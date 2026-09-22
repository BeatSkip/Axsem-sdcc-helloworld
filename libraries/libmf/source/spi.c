/**
******************************************************************************
* @file spi.c
* @brief SPI common driver APIs
* @internal
* @author   Pradeep Kumar GR
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a “ON Semiconductor”).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (“ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software”) and
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
* @ingroup SPI
*
* @details
*/

#include "spi.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

static uint8_t spi_cvs = 0 /* Over sampling */ , spi_init_sts = AXM0_PERI_NOT_INITIALIZED /* Initialization status */ ;

/* Calculates divider value to achieve user specified speed */
 static inline __reentrantb uint32_t spi_speed_to_div(uint8_t speed, uint32_t clkfreq) __reentrant
{
	volatile uint32_t quotient;

	uint32_t temp_speed = (uint32_t)(speed * ((spi_cvs + 1) * 1000000)); /* Convert speed to MHz */
	
	if (temp_speed) {
		quotient = clkfreq;
		quotient += temp_speed >> 1;
		quotient /= temp_speed;
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

uint8_t spi_init(struct spi_descriptor *spi_desc, uint8_t speed, uint8_t sel_div, uint8_t mode, uint8_t bitorder)
{
    SCB0_Type *scb = spi_desc->membase;
    uint32_t *peri_div;

    /* Disable SPI interrupt */
	NVIC_DisableIRQ(spi_desc->irqnum);

	/* Map Pin 4.0/4.1/4.3 to SPI */
    HSIOM->PORT_SEL4 |= 0x00000FFF;

    /* Reset Pin 4.1/4.2/4.3 */
    GPIO_PRT4->DR &= ~0x7;
    GPIO_PRT4->DR |= 0x5;

    /* Reset Pin 4.1/4.2/4.3 */
    GPIO_PRT4->PC2 &= ~0x7;
    GPIO_PRT4->PC2 &= ~0x5;

    /* Clear 4.0/4.1/4.3 */
    GPIO_PRT4->PC &= ~0x1FF;

    /* Configure 4.0:MOSI, 4.1:MISO, 4.2:SPI_CLK */
    SET_BIT_FIELDS(GPIO_PRT4->PC, 0x1FF, 0x18E);

    /* Peripheral clock setup: Integer clock divider and user specified divider number is used */
    PERI->PCLK_CTL0 = 0x00000040 | sel_div;

    /* Calculate oversampling value */
    if((speed == 3) || (speed == 6) || (speed == 7) )
    {
        spi_cvs = 7;/* 6M/2 */
    }
    else if(speed == 5)
    {
        spi_cvs = 9;/* 6M/2 */
    }
    else /* if((speed == 1) || (speed == 2) || (speed == 4) || (speed == 8)) */
    {
        spi_cvs = 5; /* 8M/x */
    }

    /* Get base address of divider selection register */
    peri_div = (uint32_t*)(PERI);

    /* Configure divider number and divider value to user specified number 'sel_div' */
    *((peri_div + sel_div + AXM0F2_DIV_CTL_ADRS_OFFSET)) = spi_speed_to_div(speed, AXM0XX_HFCLK_CLOCK_FREQ);

    PERI->DIV_CMD = 0x8000FF40u | sel_div; /* Execute divide */

    /* initialize the Radio SPI */
    /* Configure RADIO - SPI interface */
    scb->CTRL = spi_cvs | 0x01000800;
    scb->SPI_CTRL = (0x80000001 |                   /* MASTER mode, continuous */
                    (((mode >> 1) & 0x1) << 3) |    /* CPOL */
                    (((mode >> 0) & 0x1) << 2));    /* CPHA */

    /* Configure RX direction */
    scb->RX_CTRL = (0x80000007 | ((bitorder & 0x1) << 8)); /* Bit width 8 and bit order */
    scb->RX_FIFO_CTRL = 0x00010004; /* Trigger level to 4 */
    scb->RX_FIFO_CTRL = 0x00000004;

    /* Configure TX direction */
    scb->TX_CTRL = (0x80000007 | ((bitorder & 0x1) << 8)); /* Bit width 8 and bit order */
    scb->TX_FIFO_CTRL = 0x00010004;
    scb->TX_FIFO_CTRL = 0x00000004;

    /* Configure interrupt sources */
    scb->INTR_I2C_EC_MASK = 0;
    scb->INTR_SPI_EC_MASK = 0;
    scb->INTR_S_MASK = 0;
    scb->INTR_M_MASK = 0;
    scb->INTR_RX_MASK = 0;
    scb->INTR_TX_MASK = 0;

    /* Enable SCB */
    scb->CTRL |= 0x80000000;

    spi_init_sts = AXM0_PERI_INITIALIZED; /* Set SPI init status to YES */

    return AXM0_STATUS_SUCCESS;
}

void spi_write(struct spi_descriptor *spi_desc, uint8_t *wrBuf, uint8_t wrLength)
{
    volatile uint8_t dummy_var = 0xFF; /* Variable for dummy write */

    /* If peripheral not initialized */
    if(spi_init_sts == AXM0_PERI_NOT_INITIALIZED)
    {
        spi_desc->status = AXM0_STATUS_NO_INIT;
        return;
    }

    /* Get SCB base address */
    SCB0_Type *scb = spi_desc->membase;

    /* Disable SPI interrupt */
    NVIC_DisableIRQ(spi_desc->irqnum);
    /* Clear SPI interrupt */
	NVIC_ClearPendingIRQ(spi_desc->irqnum);

	/* Descriptor initialization */
    spi_desc->bufferptr     = (uint8_t*)wrBuf;
    spi_desc->buffersize    = wrLength;
    spi_desc->bufferindex   = 0;
    spi_desc->status        = AXM0_STATUS_IN_PROGRESS;

    /* Enable Tx trigger and TX empty interrupts */
    scb->INTR_TX_MASK = SPI_INTR_TX_TRIGGER | SPI_INTR_TX_EMPTY;

    /* Get length to be written, ceiling to 8 */
    uint8_t temp_len = (wrLength <= 8) ? (wrLength - 1) : 8;

    /* Write bytes for the length that extracted in previous block */
    for(uint8_t count = 0; count < temp_len; count++)
    {
        scb->TX_FIFO_WR = spi_desc->bufferptr[spi_desc->bufferindex++];
        while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
        dummy_var = scb->RX_FIFO_RD;
    }

    scb->INTR_TX_SET = SPI_INTR_TX_TRIGGER; /* Trigger TX interrupt required for wrLength = 1 */

    /* Clear and Enable SPI interrupt */
	NVIC_EnableIRQ(spi_desc->irqnum);
}

void spi_read(struct spi_descriptor *spi_desc, uint8_t *rdBuf, uint8_t rdLength)
{
    volatile uint8_t dummy_var = 0xFF; /* Variable for dummy read */

    /* If peripheral not initialized */
    if(spi_init_sts == AXM0_PERI_NOT_INITIALIZED)
    {
        spi_desc->status = AXM0_STATUS_NO_INIT;
        return;
    }

    /* Get SCB base address */
    SCB0_Type *scb = spi_desc->membase;

    /* Disable SPI interrupt */
    NVIC_DisableIRQ(spi_desc->irqnum);
    /* Clear aSPI interrupt */
	NVIC_ClearPendingIRQ(spi_desc->irqnum);

	/* Descriptor initialization */
    spi_desc->bufferptr     = (uint8_t*)rdBuf;
    spi_desc->buffersize    = rdLength;
    spi_desc->bufferindex   = 0;
    spi_desc->status        = AXM0_STATUS_IN_PROGRESS;

    /* Enable RX not empty interrupt */
    scb->INTR_RX_MASK = SPI_INTR_RX_NOT_EMPTY;

    /* Get length to be written, ceiling to 8 */
    uint8_t temp_len = (rdLength <= 8) ? (rdLength - 1) : 8;

    /* Read bytes for the length that extracted in previous block */
    for(uint8_t count = 0; count < temp_len; count++)
    {
        scb->TX_FIFO_WR = dummy_var;
        while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
        spi_desc->bufferptr[spi_desc->bufferindex++] = scb->RX_FIFO_RD;
    }

    scb->INTR_RX_SET = SPI_INTR_RX_NOT_EMPTY; /* Trigger RX interrupt required for rdLength = 1 */

    /* Enable SPI interrupt */
	NVIC_EnableIRQ(spi_desc->irqnum);
}

uint8_t spi_close(struct spi_descriptor *spi_desc)
{
    /* Get SCB base address */
    SCB0_Type *scb = spi_desc->membase;

    /* Disable SPI interrupt */
    NVIC_DisableIRQ(spi_desc->irqnum);

    /* Disable SCB in turn disables SPI */
    scb->CTRL &= ~0x80000000;

    spi_init_sts = AXM0_PERI_NOT_INITIALIZED; /* Set SPI init status to NO */

    return AXM0_STATUS_SUCCESS;
}

uint8_t spi_wait_until_done(struct spi_descriptor *spi_desc)
{
    /* Wait in standby mode till SPI status become other than IN_PROGRESS */
    while(spi_get_status(spi_desc) == AXM0_STATUS_IN_PROGRESS)
    {
        wtimer_idle(WTFLAG_CANSTANDBY);
    }
    return spi_desc->status;
}

uint8_t spi_get_status(struct spi_descriptor *spi_desc)
{
    return spi_desc->status;
}

void spi_handler(struct spi_descriptor *spi_desc)
{
    volatile uint8_t dummy_var = 0x80;
    uint32_t temp_var;

    SCB0_Type *scb = spi_desc->membase;

    /* Master interrupts */
    if(scb->INTR_M_MASKED & SPI_INTR_M_DONE)
    {
        /* Disable SPI interrupt */
        NVIC_DisableIRQ(spi_desc->irqnum);

        /* SPI transfer done. Disable master interrupts and update status to success */
        scb->INTR_M_MASK = 0;
        spi_desc->status = AXM0_STATUS_SUCCESS;
        return;
    }
    else if((temp_var = scb->INTR_TX_MASKED) != 0) /* TX interrupts */
	{
	    /* Trigger interrupt or TX empty interrupt */
        if((temp_var & SPI_INTR_TX_TRIGGER) || (temp_var & SPI_INTR_TX_EMPTY))
        {
            /* Write all bytes but one */
            if(spi_desc->bufferindex < (spi_desc->buffersize - 1))
            {
                /* If pending bytes are > 4 */
                if((spi_desc->buffersize - spi_desc->bufferindex) > 4)
                {
                    /* Write 4 bytes to FIFO */
                    scb->INTR_TX_MASK = SPI_INTR_TX_EMPTY; /* Required TX_EMPTY in case of mass write */

                    for(uint8_t count = 0; count < 4; count++)
                    {
                        scb->TX_FIFO_WR = spi_desc->bufferptr[spi_desc->bufferindex++];
                        while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
                        dummy_var = scb->RX_FIFO_RD;
                    }
                }
                else
                {
                    /* Pending bytes < 4, write byte by byte */
                    scb->INTR_TX_MASK = SPI_INTR_TX_TRIGGER;

                    scb->TX_FIFO_WR = spi_desc->bufferptr[spi_desc->bufferindex++];
                    while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
                    dummy_var = scb->RX_FIFO_RD;
                }
            }
            else /* Writes last byte */
            {
                /* One byte is pending, write one byte */
                scb->INTR_TX_MASK = 0; /* Disable all TX interrupt */
                scb->INTR_M_MASK = SPI_INTR_M_DONE; /* Enable M_DONE interrupt */

                scb->TX_FIFO_WR = spi_desc->bufferptr[spi_desc->bufferindex++];
                while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
                dummy_var = scb->RX_FIFO_RD;
            }
        }
	}
    else if((temp_var = scb->INTR_RX_MASKED) != 0) /* RX interrupts */
    {
        /* If RX not empty */
        if((temp_var & SPI_INTR_RX_NOT_EMPTY) || (temp_var & SPI_INTR_RX_FULL))
        {
            if(spi_desc->bufferindex < spi_desc->buffersize)
            {
                /* If pending read is > 4 */
                if((spi_desc->buffersize - spi_desc->bufferindex) > 4)
                {
                    /* Read 4 bytes from FIFO */
                    for(uint8_t count = 0; count < 4; count++)
                    {
                        scb->TX_FIFO_WR = dummy_var;
                        while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
                        spi_desc->bufferptr[spi_desc->bufferindex++] = scb->RX_FIFO_RD;
                    }
                }
                else
                {
                    /* Pending bytes < 4, read byte by byte */
                    scb->TX_FIFO_WR = dummy_var;
                    while((scb->RX_FIFO_STATUS & 0x1F) == 0); /* Wait if FIFO is empty */
                    spi_desc->bufferptr[spi_desc->bufferindex++] = scb->RX_FIFO_RD;
                }
                scb->INTR_RX_SET = SPI_INTR_RX_NOT_EMPTY; /* Trigger RX interrupt */
            }
            else /* Read complete */
            {
                /* Disable SPI interrupt */
                NVIC_DisableIRQ(spi_desc->irqnum);

                /* SPI transfer done. Disable all SPI interrupts and update status to success */
                scb->INTR_RX_MASK = 0;
                spi_desc->status = AXM0_STATUS_SUCCESS;
                return;
            }
        }
    }
}

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */
