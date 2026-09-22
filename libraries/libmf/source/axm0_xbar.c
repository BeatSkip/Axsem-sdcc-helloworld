/**
******************************************************************************
* @file axm0_xbar.c
* @brief Crossbar config APIs definitions
* @internal
* @author   Pradeep Kumar G R
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
* @ingroup CROSSBAR
*
* @details
*/
#include "cpu.h"
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0_xbar.h"
uint8_t axm0_xbar_uart_config(XBAR_PIN_Enum tx_pin, XBAR_PIN_Enum rx_pin, \
                              XBAR_PIN_Enum uart_clk_pin, XBAR_PIN_Enum tout_pin)
{
	uint32_t xbar_val;
	XBAR_Type *xbar_base_adrs;
	uint8_t config, uart_num = UART_NUMBER0;

	CMU->PCLK_CFG_b.XBAR_EN = 1; /* Enable XBAR clock */

	/* TOUT Pin configuration */
	if(tout_pin != AXM0_XBAR_PIN_NOT_REQUIRED)
    {
        if((tout_pin == XBAR_PIN_PA0) || (tout_pin == XBAR_PIN_PA3) || (tout_pin == XBAR_PIN_PB5) || (tout_pin == XBAR_PIN_PA1)/* TODO Not connected || (timer_pin == XBAR_PIN_PA6)*/)
        {
            config = UART_XBAR_CFG1;
        }
        else if((tout_pin == XBAR_PIN_PC0) || (tout_pin == XBAR_PIN_PB3) || (tout_pin == XBAR_PIN_PB2))
        {
            config = UART_XBAR_CFG2;
        }
        else
        {
            return AXM0_STATUS_INVALID_PARAMETER;
        }

        /* Configure timer pin */
        xbar_base_adrs = (XBAR_Type*)(XBAR_BASE + ((tout_pin / 8) * 4)); 	/* Get PIO_A_CFG register address */
        xbar_val = xbar_base_adrs->PA_CFG;									/* Read XBAR value */
        xbar_val = xbar_val & ~((7 << (tout_pin % 8) * 4));				    /* Clear old settings if any */
        xbar_val = xbar_val | (config << (tout_pin % 8) * 4);				/* Set timer pin */
        xbar_base_adrs->PA_CFG = xbar_val;									/* Write back timer pin setting to xbar */
    }

    /* UART_CLOCK pin configuration */
    if(uart_clk_pin != AXM0_XBAR_PIN_NOT_REQUIRED)
    {
        if((uart_clk_pin == XBAR_PIN_PR0) || (uart_clk_pin == XBAR_PIN_PR5))
        {
            config = UART_XBAR_FUN2;
        }
        else if((uart_clk_pin == XBAR_PIN_PA1) || (uart_clk_pin == XBAR_PIN_PB2/* TODO PB1/PB2 May be design/doc issue */))
        {
            config = UART_XBAR_FUN1;
        }
        else
        {
            return AXM0_STATUS_INVALID_PARAMETER;
        }

        if((uart_clk_pin == XBAR_PIN_PB2) || (uart_clk_pin == XBAR_PIN_PR5))
        {/* UART 0 */
             XBAR->IN_UART0_CFG_b.CLK = config;
        }
        else /* PA1 or PR0 */
        {/* UART 1 */
            XBAR->IN_UART1_CFG_b.CLK = config;
        }

        GPIO_AND->OUT_EN = ~(1 << uart_clk_pin);
    }

    /* Tx pin settings */
	if((tx_pin == XBAR_PIN_PB4)/* TODO Not connected  || (tx_pin == XBAR_PIN_PC5)*/) /* UART 0 TX with config 1 */
	{
		config = 1;
	}
	else if (tx_pin == XBAR_PIN_PC2)	/* UART 0 TX with config 2 */
	{
		config = 2;
	}
	else if((tx_pin == XBAR_PIN_PB0) || (tx_pin == XBAR_PIN_PC6))	/* UART 1 TX  with config 1 */
	{
		uart_num = UART_NUMBER1;
		config = 1;
	}
	else if(tx_pin == XBAR_PIN_PA5)	/* UART 1 TX with config 2 */
	{
		uart_num = UART_NUMBER1;
		config = 2;
	}
	else	/* tx_pin not supported for UART */
	{
		return AXM0_STATUS_INVALID_PARAMETER;
	}

	xbar_base_adrs = (XBAR_Type*)(XBAR_BASE + ((tx_pin / 8) * 4)); 		/* Get PIO_A_CFG register address */
	xbar_val = xbar_base_adrs->PA_CFG;									/* Read XBAR value */
	xbar_val = xbar_val & ~((7 << (tx_pin % 8) * 4));					/* Clear old settings if any */
	xbar_val = xbar_val | (config << (tx_pin % 8) * 4);					/* Set tx pin */
	xbar_base_adrs->PA_CFG = xbar_val;									/* Write back timer pin setting to xbar */

	/* Rx pin configuration */
	if(uart_num == UART_NUMBER0)
	{	/* UART 0 RX */
		if ((rx_pin != XBAR_PIN_PB5) && (rx_pin != XBAR_PIN_PC3) && (rx_pin != XBAR_PIN_PR4))
		{
			/* rx_pin not supported for UART */
			return AXM0_STATUS_INVALID_PARAMETER;
		}

		/* COnfigure Rx pin */
		XBAR->IN_UART0_CFG_b.RX = (rx_pin / 8);
	}
	else /* UART 1 */
	{
		/* UART 1 RX */
		if ((rx_pin != XBAR_PIN_PA2) && (rx_pin != XBAR_PIN_PB1)/* TODO Not connected  && (rx_pin != XBAR_PIN_PC7)*/) //RX1
		{
			/* rx_pin not supported for UART */
			return AXM0_STATUS_INVALID_PARAMETER;
		}

		/* Configure Rx pin */
		XBAR->IN_UART1_CFG_b.RX = (rx_pin / 8) + 1;
	}

	/* Make Rx pin as input */
    GPIO_AND->OUT_EN = ~(1 << rx_pin);

	return AXM0_STATUS_SUCCESS;
}

/* TODO need to generalize */
uint8_t axm0_xbar_spi0_config(XBAR_PIN_Enum spi0_mosi, XBAR_PIN_Enum spi0_miso, \
                              XBAR_PIN_Enum spi0_sel, XBAR_PIN_Enum spi0_clk, \
                              XBAR_PIN_Enum spi0_sysclk)
{
    uint32_t xbar_val;
	XBAR_Type *xbar_base_adrs;
    uint8_t config = 1;

    CMU->PCLK_CFG_b.XBAR_EN = 1; /* Enable XBAR clock */

    GPIO_OR->OUT_EN  =  ((1 << spi0_mosi) | (1 << spi0_sel) | \
                         (1 << spi0_clk));//0x15000000;
	GPIO_AND->OUT_EN = ~((1 << spi0_miso) | (1 << spi0_sysclk));//~0x08000000;

    xbar_base_adrs = (XBAR_Type*)(XBAR_BASE + ((spi0_sel / 8) * 4)); 	/* Get PIO_R_CFG register address */
	xbar_val = xbar_base_adrs->PA_CFG;									/* Read XBAR value */
	xbar_val = xbar_val & ~((7 << (spi0_mosi % 8) * 4) | \
                            (7 << (spi0_sel  % 8) * 4) | \
                            (7 << (spi0_clk  % 8) * 4));		 	    /* Clear old settings if any */
	xbar_val = xbar_val | (config << (spi0_mosi % 8) * 4) | \
	                      (config << (spi0_sel  % 8) * 4) | \
	                      (config << (spi0_clk % 8) * 4);				/* Set tx pin */
	xbar_base_adrs->PA_CFG = xbar_val;									/* Write back timer pin setting to xbar */


//    XBAR->PR_CFG_b.PR4      = 1;    /* MOSI     */
//    XBAR->PR_CFG_b.PR0      = 1;    /* SELECT   */
//    XBAR->PR_CFG_b.PR2      = 1;    /* CLK      */


    XBAR->IN_SPI0_CFG_b.IN  = 2;    /* MISO     */
    //   XBAR->PR_CFG_b.PR1      = 3;    /* SYSCLK   */
    //  GPIO->DATA_OUT &= ~(1 << XBAR_PIN_PR1);

    //   XBAR->PR_CFG_b.PR5      = 0;    /* IRQ      */
    //  GPIO->DATA_OUT &= ~(1 << XBAR_PIN_PR5);

    return AXM0_STATUS_SUCCESS;
}

#endif /* __AXM0 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */
