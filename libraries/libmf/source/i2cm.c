/**
******************************************************************************
* @file i2cm.c
* @brief i2c master implementation
* @internal
* @author   Sai Pramod Kumar
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a ?ON Semiconductor?).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (?ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software?) and
* if applicable the software license agreement.  Do not use this software and/or
* documentation unless you have carefully read and you agree to the limited terms and
* conditions.  By using this software and/or documentation, you agree to the limited
* terms and conditions.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* ON SEMICONDUCTOR SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,
* INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
* @endinternal
*
* @ingroup I2C
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#include "cpu.h"
#include "axm0f2.h"
#include "i2c.h"

static uint8_t i2c_init_sts = AXM0_PERI_NOT_INITIALIZED;

/* Calculates divider value to achieve user specified speed */
inline __reentrantb uint32_t i2c_timer_baud_int(uint8_t speed, uint32_t clkfreq) __reentrant
{
	volatile uint32_t quotient;
	volatile uint32_t baud;
	volatile uint8_t i2c_ovs = 19;

    switch(speed)
    {
        case LIBMF_I2C_SLOW_MODE:
            baud = 50000;
            break;

        case LIBMF_I2C_STANDARD_MODE:
            baud = 100000;
            break;

        case LIBMF_I2C_FAST_MODE:
            baud = 400000;
            break;

        case LIBMF_I2C_FAST_PLUS_MODE:
            i2c_ovs = 15;
            baud = 1000000;
            break;

        default:
            break;
    }

	baud *= (i2c_ovs + 1);
	if (baud) {
		quotient = clkfreq;
		quotient += baud >> 1;
		quotient /= baud;
		if (quotient)
			--quotient;
		if (quotient > 0xFFFF)
			quotient = 0xFFFF;
	} else {
		quotient = 0xFFFF;
	}
	quotient <<= 8;
	return quotient;
}

uint8_t i2c_init(struct i2c_descriptor *i2c_desc,uint8_t mode, uint8_t speed, uint8_t sel_div, uint8_t clk_src)
{
    volatile SCB0_Type *scb = i2c_desc->membase;
    volatile uint32_t *peri_div;

    if(mode != LIBMF_I2C_MASTER)
    {
        /* If mode is not Master return with error, We support only Master Mode */
        return AXM0_STATUS_INVALID_PARAMETER;
    }
    else if(speed > 3)
    {
        /* If Speed is other than LIBMF_I2C_SLOW_MODE, LIBMF_I2C_STANDARD_MODE, LIBMF_I2C_FAST_MODE, LIBMF_I2C_FAST_PLUS_MODE, return with error */
        return AXM0_STATUS_INVALID_PARAMETER;
    }
    else if(sel_div > 5)
    {
        /* Only Integer dividers are used, Valid range 0 to 5, return with error for invalid range */
        return AXM0_STATUS_INVALID_PARAMETER;
    }
    else if(clk_src != LIBMF_I2C_INTERNAL_CLK)
    {
        /* If clock source is not Internal return with error, we support only internal clock source */
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    if(scb == (SCB0_Type*)SCB0)
    {
        PERI->PCLK_CTL0 = 0x00000040 | sel_div;
    }
    else if(scb == (SCB0_Type*)SCB2)
    {
        PERI->PCLK_CTL2 = 0x00000040 | sel_div;
    }
    else
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    /* Get base address of divider selection register */
    peri_div = (uint32_t*)(PERI);

    /* Divider value for perticular speed and HCLK is obtained and programmed */
    *((peri_div + sel_div + AXM0F2_DIV_CTL_ADRS_OFFSET)) = i2c_timer_baud_int(speed, AXM0XX_HFCLK_CLOCK_FREQ);

    PERI->DIV_CMD = 0x8000FF40u | sel_div; /* Execute divide */

    /* Configure I2C interface */
    scb->CTRL     = I2C_DEFAULT_CTRL;
    scb->I2C_CTRL = I2C_DEFAULT_I2C_CTRL;

    /* Configure Master Mode */
    scb->I2C_CTRL = scb->I2C_CTRL | (1 << MASTER_MODE_POS);

    /* Configure OVS for obtaining required Speed */
    if(speed != LIBMF_I2C_FAST_PLUS_MODE)
    {
        scb->I2C_CTRL = scb->I2C_CTRL & (~(I2C_OVS_MASK));
        scb->I2C_CTRL = scb->I2C_CTRL | I2C_STANDARD_OVS;
    }
    else
    {
        scb->I2C_CTRL = scb->I2C_CTRL & (~(I2C_OVS_MASK));
        scb->I2C_CTRL = scb->I2C_CTRL | I2C_FAST_OVS;
    }

    /* Configure RX direction */
    scb->RX_CTRL      = I2C_DEFAULT_RX_CTRL;
    scb->RX_FIFO_CTRL = 0;
    scb->RX_MATCH     = 0;

    /* Configure TX direction */
    scb->TX_CTRL      = I2C_DEFAULT_TX_CTRL;
    scb->TX_FIFO_CTRL = TX_TRIGGER_LEVEL;

    /* Disable I2C interrupt */
    NVIC_DisableIRQ(i2c_desc->irqnum);

    /* Clear interrupt sources */
    scb->INTR_I2C_EC_MASK   = 0;
    scb->INTR_M_MASK        = 0;
    scb->INTR_RX_MASK       = 0;
    scb->INTR_TX_MASK       = 0;

    /* Enable I2C module */
    scb->CTRL |= I2C_CTRL_ENABLED;

    i2c_init_sts = AXM0_PERI_INITIALIZED; /* Set I2C init status to YES */

    /* Clear and Enable I2C interrupt */
    NVIC_ClearPendingIRQ(i2c_desc->irqnum);
    NVIC_EnableIRQ(i2c_desc->irqnum);

    return AXM0_STATUS_SUCCESS;
}

void i2c_write(struct i2c_descriptor *i2c_desc,uint16_t slaveAddress, uint8_t *wrData, uint8_t length, uint8_t repeated)
{
    uint8_t i = 0;
    uint8_t len = 0;
    volatile uint8_t ls_slaveAddress = 0;
    volatile uint8_t ms_slaveAddress = 0;
    volatile SCB0_Type *scb = i2c_desc->membase;

    /* If peripheral not initialized */
    if(i2c_init_sts == AXM0_PERI_NOT_INITIALIZED)
    {
        i2c_desc->status = AXM0_STATUS_NO_INIT;
        return;
    }

    if(NULL == wrData)
    {
        /* If Write data pointer is NULL, Return with Error */
        i2c_desc->status = AXM0_STATUS_INVALID_PARAMETER;
        return;
    }
    else if(length == 0)
    {
        /* If Write data length is 0, Return with Error */
        i2c_desc->status = AXM0_STATUS_INVALID_PARAMETER;
        return;
    }
    else if(repeated >= 2)
    {
        /* If repeated state is Invalid, Return with Error */
        i2c_desc->status = AXM0_STATUS_INVALID_PARAMETER;
        return;
    }

    /* Disable I2C interrupt */
    NVIC_DisableIRQ(i2c_desc->irqnum);

    /* i2c_desc->repeated will be 1 only when STOP is not generated in previous I2C transfer
       i2c_desc->repeated will be 0 in IDLE state or STOP is generated in previous I2C transfer */
    if(i2c_desc->repeated == 0)
    {
        /* Check I2C Bus Busy */
        if(0 != (scb->I2C_STATUS & I2C_STATUS_BUS_BUSY))
        {
            /* Return with Error if I2C Bus is Busy */
            i2c_desc->status = LIBMF_I2C_BUS_ERROR;
            return;
        }
    }

    /* Descriptor initialization */
    i2c_desc->repeated = repeated;
    i2c_desc->status = AXM0_STATUS_IN_PROGRESS;
    i2c_desc->txindex    = 0u;
    i2c_desc->txdatalength     = length;
    i2c_desc->txpointer     = (uint8_t *) wrData;

    if((slaveAddress & 0xF000) == 0xF000)   /* Check for 10 bit Slave Address */
    {
        ms_slaveAddress = (slaveAddress & 0xFF00)>>8;
        /* Least Significant 8 bits of Slave Address */
        ls_slaveAddress = (slaveAddress & 0x00FF);
        /* Most Significant Slave Address with Write Flag */
        ms_slaveAddress = GET_I2C_10BIT_ADDRESS(ms_slaveAddress);
    }
    else    /* 7 bit slave address condition */
    {
        ms_slaveAddress = 0;
        ls_slaveAddress = (slaveAddress & 0x00FF);
        /* 7 bit slave address With Write Flag */
        ls_slaveAddress = GET_I2C_8BIT_ADDRESS(ls_slaveAddress);
    }

    /* Clear Tx FIFO */
    scb->TX_FIFO_CTRL |= ((uint32_t)  I2C_TX_FIFO_CTRL_CLEAR);
    scb->TX_FIFO_CTRL &= ((uint32_t) ~I2C_TX_FIFO_CTRL_CLEAR);

    /* Clear Tx Trigger Interrupt */
    scb->INTR_TX     = (uint32_t) (I2C_INTR_TX_TRIGGER);

    /* Clear all I2C Master specific Interrupts */
    scb->INTR_M = (uint32_t) (I2C_INTR_MASTER_ALL);
    /* Set all I2C Master specific Interrupts, Other than Ack */
    scb->INTR_M_MASK = (uint32_t) (I2C_INTR_MASTER_MASK);

    /* Set Tx Trigger Interrupt */
    scb->INTR_TX_MASK = (uint32_t) (I2C_INTR_TX_TRIGGER);

    /* Slave Address and Data Bytes, Total 8 bytes is written into Tx FIFO */
    if(ms_slaveAddress == 0)    /* 7 Bit Slave address case */
    {
        scb->TX_FIFO_WR = ls_slaveAddress;
        len = (i2c_desc->txdatalength < 8) ? (i2c_desc->txdatalength - 1) : 7;
    }
    else    /* 10 Bit Slave address case */
    {
        scb->TX_FIFO_WR = ms_slaveAddress;
        scb->TX_FIFO_WR = ls_slaveAddress;
        len = (i2c_desc->txdatalength < 7) ? (i2c_desc->txdatalength - 1) : 6;
    }
    for(i = 0; i < len; i++)
    {
       scb->TX_FIFO_WR =  i2c_desc->txpointer[i];
       (i2c_desc->txindex)++;
    }

    /* Generate Start */
    scb->I2C_M_CMD = I2C_MASTER_CMD_M_START;

    /* Clear and Enable I2C interrupt */
    NVIC_ClearPendingIRQ(i2c_desc->irqnum);
    NVIC_EnableIRQ(i2c_desc->irqnum);
}

void  i2c_read(struct i2c_descriptor *i2c_desc,uint16_t slaveAddress, uint8_t *rdData, uint8_t length, uint8_t repeated)
{
    volatile uint8_t ls_slaveAddress = 0;
    volatile uint8_t ms_slaveAddress = 0;
    volatile SCB0_Type *scb = i2c_desc->membase;

    /* If peripheral not initialized */
    if(i2c_init_sts == AXM0_PERI_NOT_INITIALIZED)
    {
        i2c_desc->status = AXM0_STATUS_NO_INIT;
        return;
    }

    if(NULL == rdData)
    {
        /* If Read data pointer is NULL, Return with Error */
        i2c_desc->status = AXM0_STATUS_INVALID_PARAMETER;
        return;
    }
    else if(length == 0)
    {
        /* If Read data length is 0, Return with Error */
        i2c_desc->status = AXM0_STATUS_INVALID_PARAMETER;
        return;
    }
    else if(repeated >= 2)
    {
        /* If repeated state is Invalid, Return with Error */
        i2c_desc->status = AXM0_STATUS_INVALID_PARAMETER;
        return;
    }

    /* Disable I2C interrupt */
    NVIC_DisableIRQ(i2c_desc->irqnum);

    /* i2c_desc->repeated will be 1 only when STOP is not generated in previous I2C transfer
       i2c_desc->repeated will be 0 in IDLE state or STOP is generated in previous I2C transfer */
    if(i2c_desc->repeated == 0)
    {
        /* Check I2C Bus Busy */
        if(0 != (scb->I2C_STATUS & I2C_STATUS_BUS_BUSY))
        {
            /* Return with Error if I2C Bus is Busy */
            i2c_desc->status = LIBMF_I2C_BUS_ERROR;
            return;
        }
    }

    /* Descriptor initialization */
    i2c_desc->repeated = repeated;
    i2c_desc->status = AXM0_STATUS_IN_PROGRESS;
    i2c_desc->rxindex = 0u;
    i2c_desc->rxdatalength  = length;
    i2c_desc->rxpointer   = (uint8_t *) rdData;

    if((slaveAddress & 0xF000) == 0xF000)   /* Check for 10 bit Slave Address */
    {
        ms_slaveAddress = (slaveAddress & 0xFF00)>>8;
        /* Least Significant 8 bits of Slave Address */
        ls_slaveAddress = (slaveAddress & 0x00FF);
        /* Most Significant Slave Address with Read Flag */
        ms_slaveAddress = (GET_I2C_10BIT_ADDRESS(ms_slaveAddress) | I2C_READ_FLAG);
    }
    else
    {
        ms_slaveAddress = 0;
        ls_slaveAddress = (slaveAddress & 0x00FF);
        /* 7 bit slave address With Write Flag */
        ls_slaveAddress = (GET_I2C_8BIT_ADDRESS(ls_slaveAddress) | I2C_READ_FLAG);
    }

    /* Clear Rx FIFO */
    scb->RX_FIFO_CTRL |= ((uint32_t)  I2C_RX_FIFO_CTRL_CLEAR);
    scb->RX_FIFO_CTRL &= ((uint32_t) ~I2C_RX_FIFO_CTRL_CLEAR);

    /* Clear all I2C Master specific Interrupts */
    scb->INTR_M = (uint32_t) (I2C_INTR_MASTER_ALL);
    /* Set all I2C Master specific Interrupts, Other than Ack */
    scb->INTR_M_MASK = (uint32_t) (I2C_INTR_MASTER_MASK);

    /* Prepare reading */
    if(i2c_desc->rxdatalength <= I2C_FIFO_SIZE)
    {
        /* Set Rx FIFO Not Empty Interrupt */
        scb->INTR_RX_MASK = (uint32_t) (I2C_INTR_RX_NOT_EMPTY);
    }
    else
    {
        /* Auto Data Ack is enabled */
        scb->I2C_CTRL |= I2C_CTRL_M_READY_DATA_ACK;
        /* Set Rx FIFO FULL Interrupt */
        scb->INTR_RX_MASK = (uint32_t) (I2C_INTR_RX_FULL);
    }

    if(ms_slaveAddress == 0)
    {
        /* 7 bit Slave address with Read flag is written into Tx FIFO */
        scb->TX_FIFO_WR = ls_slaveAddress;
    }
    else
    {
        /* 10 bit Slave address with Read flag is written into Tx FIFO */
        scb->TX_FIFO_WR = ms_slaveAddress;
        scb->TX_FIFO_WR = ls_slaveAddress;
    }

    /* Generate Start */
    scb->I2C_M_CMD = I2C_MASTER_CMD_M_START;

    /* Clear and Enable I2C interrupt */
    NVIC_ClearPendingIRQ(i2c_desc->irqnum);
    NVIC_EnableIRQ(i2c_desc->irqnum);
}

uint8_t i2c_getstatus(struct i2c_descriptor *i2c_desc)
{
    /* Return I2C transfer status */
	return (i2c_desc->status);
}

uint8_t i2c_wait_until_done(struct i2c_descriptor *i2c_desc)
{
    /* Wait in  standby mode till I2C is done with transfer */
    while(AXM0_STATUS_IN_PROGRESS == i2c_desc->status)
    {
        wtimer_idle(WTFLAG_CANSTANDBY);
    }
    return(i2c_desc->status);
}

uint8_t i2c_close(struct i2c_descriptor *i2c_desc)
{
    /* Get SCB base address */
    SCB0_Type *scb = i2c_desc->membase;

    /* Disable I2C interrupt */
    NVIC_DisableIRQ(i2c_desc->irqnum);

    /* Disable SCB in turn disables I2C */
    scb->CTRL &= ~0x80000000;

    i2c_init_sts = AXM0_PERI_NOT_INITIALIZED; /* Set I2C init status to NO */

    return AXM0_STATUS_SUCCESS;
}

void i2c_handler(struct i2c_descriptor *i2c_desc)
{
    volatile uint32_t diffCount = 0;
    volatile uint32_t endTransfer = 0;
    volatile uint8_t i = 0;
    volatile SCB0_Type *scb = i2c_desc->membase;

    /* Master interrupts */
    if(0u != (scb->INTR_M_MASKED & (I2C_MASTER_INTERRUPT_MASK)))
    {
        if(0u != (scb->INTR_M_MASKED & (I2C_INTR_MASTER_I2C_BUS_ERROR)))    /* I2C Bus Error is Triggered */
        {
            i2c_desc->status = LIBMF_I2C_BUS_ERROR;
            /* Clear Bus Error Interrupt */
            scb->INTR_M = (uint32_t)I2C_INTR_MASTER_I2C_BUS_ERROR;
            endTransfer = 2;
            /* Disable I2C interrupt */
            NVIC_DisableIRQ(i2c_desc->irqnum);
        }
        else if(0u != (scb->INTR_M_MASKED & (I2C_INTR_MASTER_I2C_ARB_LOST)))    /* I2C Arbitration Lost is Triggered */
        {
            i2c_desc->status = LIBMF_I2C_ARB_LOST;
            /* Clear Arbitration Lost Interrupt */
            scb->INTR_M = (uint32_t)I2C_INTR_MASTER_I2C_ARB_LOST;
            endTransfer = 2;
            /* Disable I2C interrupt */
            NVIC_DisableIRQ(i2c_desc->irqnum);
        }
        /* INTR_MASTER_I2C_STOP: */
        else if(0u != (scb->INTR_M_MASKED & (I2C_INTR_MASTER_I2C_STOP)))    /* I2C STOP Interrupt is Triggered */
        {
            /* Clear STOP Interrupt */
            scb->INTR_M = (uint32_t)I2C_INTR_MASTER_I2C_STOP;

            if(1 == i2c_desc->flag)
            {
                /* I2C Transfer Status is Success */
                i2c_desc->status = AXM0_STATUS_SUCCESS;
            }
            else if(2 == i2c_desc->flag)
            {
                /* I2C Transfer Status is Failed */
                i2c_desc->status = AXM0_STATUS_FAIL;
            }

            i2c_desc->flag = 0;
            endTransfer = 0;
            /* Disable I2C interrupt */
            NVIC_DisableIRQ(i2c_desc->irqnum);
        }
        else if(0u != (scb->INTR_M_MASKED & (I2C_INTR_MASTER_I2C_NACK)))    /* I2C NACK Interrupt is Triggered */
        {
            /* Clear NACK Interrupt */
            scb->INTR_M = (uint32_t)I2C_INTR_MASTER_I2C_NACK;

            /* Clear Tx and Rx Index */
            i2c_desc->txindex = 0;
            i2c_desc->rxindex = 0;

            i2c_desc->flag = 2;

            /* Clear Tx FIFO */
            scb->TX_FIFO_CTRL |= ((uint32_t)  I2C_TX_FIFO_CTRL_CLEAR);
            scb->TX_FIFO_CTRL &= ((uint32_t) ~I2C_TX_FIFO_CTRL_CLEAR);

            endTransfer = I2C_CMPLT_ANY_TRANSFER;
        }
    }
    /* RX interrupts */
    else if(0u != (scb->INTR_RX_MASKED  & (I2C_DATA_INTERRUPT_MASK)))
    {
        if(0u != (scb->INTR_RX_MASKED  & (I2C_INTR_RX_FULL)))   /* RX FIFO FULL interrupt is triggered */
        {
            /* Disable Auto-ACK */
            scb->I2C_CTRL &= ~((uint32_t) (0x01u << I2C_CTRL_M_READY_DATA_ACK_POS));

            /* Read data bytes from slave into Read buffer */
            diffCount = (scb->RX_FIFO_STATUS & 0x0F);
            for(i=0; i<(diffCount-1); i++)
            {
                i2c_desc->rxpointer[i2c_desc->rxindex] = (uint8_t)(scb->RX_FIFO_RD);
                (i2c_desc->rxindex)++;
            }

            if(i2c_desc->rxindex >= (i2c_desc->rxdatalength-8)) /* Data bytes to read is less than 8 */
            {
                /* Set Rx Not Empty Interrupt */
                scb->INTR_RX_MASK = (uint32_t) (I2C_INTR_RX_NOT_EMPTY);
            }
            else
            {
               /* Disable Auto-ACK */
               scb->I2C_CTRL |= ((uint32_t) (0x01u << I2C_CTRL_M_READY_DATA_ACK_POS));
            }

            /* Clear Rx FULL Interrupt */
            scb->INTR_RX     = (uint32_t) (I2C_INTR_RX_FULL);
        }
        else if(0u != (scb->INTR_RX_MASKED  & (I2C_INTR_RX_NOT_EMPTY))) /* RX FIFO Not Empty interrupt is triggered */
        {
            diffCount = (scb->RX_FIFO_STATUS & 0x0F);
            for(; (0u != diffCount); diffCount--)
            {
                /* Read data byte from slave into Read buffer */
                i2c_desc->rxpointer[i2c_desc->rxindex] = (uint8_t)(scb->RX_FIFO_RD);
                (i2c_desc->rxindex)++;

                if(i2c_desc->rxindex < i2c_desc->rxdatalength)
                {
                    /* Generate Ack */
                    scb->I2C_M_CMD = I2C_MASTER_CMD_M_ACK;
                }
                else
                {
                    if(i2c_desc->repeated == 1)
                    {
                        /* Generate Ack */
                        scb->I2C_M_CMD = I2C_MASTER_CMD_M_ACK;
                    }
                    i2c_desc->flag = 1;
                    endTransfer = I2C_CMPLT_ANY_TRANSFER;
                    break;
                }
            }
            scb->INTR_RX     = (uint32_t) (I2C_INTR_RX_ALL);
        }
    }
    /* TX interrupts */
    else if(0u != (scb->INTR_TX_MASKED  & (I2C_DATA_INTERRUPT_MASK)))
    {
        if(0u != (scb->INTR_TX_MASKED  & (I2C_INTR_TX_TRIGGER)))    /* TX Trigger interrupt is triggered */
        {
            i2c_desc->flag = 0;

            /* Clear Tx Trigger Interrupt */
            scb->INTR_TX = scb->INTR_TX | I2C_INTR_TX_TRIGGER;

            /* Write data into Tx FIFO */
            diffCount = I2C_FIFO_SIZE - (scb->TX_FIFO_STATUS & 0x07);
            for(; (0u != diffCount); diffCount--)
            {
                if(i2c_desc->txindex < i2c_desc->txdatalength)
                {
                    if(i2c_desc->txindex == (i2c_desc->txdatalength - 1u)) /* Last byte to write */
                    {
                        /* Clear and Set Underflow Interrupt */
                        scb->INTR_TX     = (uint32_t) (I2C_INTR_TX_UNDERFLOW);
                        scb->INTR_TX_MASK = (uint32_t) (I2C_INTR_TX_UNDERFLOW);

                        /* Write last byte into Tx FIFO */
                        scb->TX_FIFO_WR = (uint32_t) i2c_desc->txpointer[i2c_desc->txindex];
                        (i2c_desc->txindex)++;
                    }
                    else
                    {
                        scb->TX_FIFO_WR = (uint32_t) i2c_desc->txpointer[i2c_desc->txindex];
                        (i2c_desc->txindex)++;
                    }
                }
                else
                {
                    break; /* No more data to put */
                }

            }

            /* Clear Tx Trigger Interrupt */
            scb->INTR_TX     = (uint32_t) (I2C_INTR_TX_TRIGGER);
        }
        else if(0u != (scb->INTR_TX_MASKED  & (I2C_INTR_TX_UNDERFLOW))) /* Underflow Interrupt is Triggered */
        {
            /* Clear Underflow Interrupt */
            scb->INTR_TX     = (uint32_t) (I2C_INTR_TX_UNDERFLOW);
            i2c_desc->flag = 1;

            endTransfer = I2C_CMPLT_ANY_TRANSFER;
        }
    }

    if(1 == endTransfer) /* Complete transfer */
    {
        endTransfer = 0;
        /* Disable Auto Ack */
        scb->I2C_CTRL &= ~((uint32_t) (0x01u << I2C_CTRL_M_READY_DATA_ACK_POS));

        /* Disable data processing interrupts */
        scb->INTR_RX_MASK = 0;
        scb->INTR_TX_MASK = 0;

        if(i2c_desc->repeated == 1)
        {
            if(i2c_desc->flag == 1)
            {
                /* I2C Transfer Status is Success */
                i2c_desc->status = AXM0_STATUS_SUCCESS;
            }
            else
            {
                /* I2C Transfer Status is Failed */
                i2c_desc->status = AXM0_STATUS_FAIL;
            }
            /* Disable I2C interrupt */
            NVIC_DisableIRQ(i2c_desc->irqnum);
        }
        else
        {
            if(0 != (scb->I2C_STATUS & I2C_STATUS_M_READ))  /* Read Case */
            {
            /* Generate NACK and STOP */
               scb->I2C_M_CMD =  I2C_INTR_MASTER_I2C_STOP | I2C_MASTER_CMD_M_NACK;
            }
            else    /* Write Case */
            {
            /* Generate STOP */
               scb->I2C_M_CMD =  I2C_INTR_MASTER_I2C_STOP;
            }
        }
    }
    else if(endTransfer == 2)   /* BUS Error/Arbitration Lost Case */
    {
    /* Clear Master Interrupts, Tx Interrupts and Rx Interrupts */
       scb->INTR_RX_MASK = 0;
       scb->INTR_TX_MASK = 0;
       scb->INTR_M_MASK = 0;
    }
}

#endif // __AXM0F2

#endif // defined
