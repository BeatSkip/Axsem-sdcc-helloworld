/**
******************************************************************************
* @file axm0_xbar.h
* @brief Crossbar config APIs declarations
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

#ifndef AXM0_XBAR_H
#define AXM0_XBAR_H

#if defined __ARMEL__ || defined __ARMEB__
#include "libmftypes.h"
#include "axm0_config.h"
#define AXM0_XBAR_PIN_NOT_CONNECTED			0xFF
#define AXM0_XBAR_PIN_NOT_REQUIRED			0xFF

#define UART_SLAVE      0
#define UART_MASTER     1

#define UART_XBAR_CFG1  1
#define UART_XBAR_CFG2  2

#define UART_XBAR_FUN1  1
#define UART_XBAR_FUN2  2

#define UART_NUMBER0    0
#define UART_NUMBER1    1

typedef enum {      	     /*!< XBAR_PIN 	*/
	  XBAR_PIN_PA0 	= 0,  	 /*!< PA0 	 	*/
	  XBAR_PIN_PA1 	= 1,  	 /*!< PA1 	 	*/
	  XBAR_PIN_PA2 	= 2,  	 /*!< PA2 	 	*/
	  XBAR_PIN_PA3 	= 3,  	 /*!< PA3 	 	*/
	  XBAR_PIN_PA4 	= 4,  	 /*!< PA4 	 	*/
	  XBAR_PIN_PA5 	= 5,  	 /*!< PA5 	 	*/
	  XBAR_PIN_PA6 	= 0xFF,  /*!< PA6 Not available in 28 pin package */
	  XBAR_PIN_PA7 	= 0xFF,  /*!< PA7 Not available in 28 pin package */

	  XBAR_PIN_PB0 	= 8,  	 /*!< PB0 	 	*/
	  XBAR_PIN_PB1 	= 9,  	 /*!< PB1 	 	*/
	  XBAR_PIN_PB2 	= 10, 	 /*!< PB2 	 	*/
	  XBAR_PIN_PB3 	= 11, 	 /*!< PB3 	 	*/
	  XBAR_PIN_PB4 	= 12, 	 /*!< PB4 	 	*/
	  XBAR_PIN_PB5 	= 13, 	 /*!< PB5 	 	*/
	  XBAR_PIN_PB6 	= 14, 	 /*!< PB6 	 	*/
	  XBAR_PIN_PB7 	= 15, 	 /*!< PB7 	 	*/

	  XBAR_PIN_PC0 	= 16, 	 /*!< PC0 	 	*/
	  XBAR_PIN_PC1 	= 17, 	 /*!< PC1 	 	*/
	  XBAR_PIN_PC2 	= 18, 	 /*!< PC2 	 	*/
	  XBAR_PIN_PC3 	= 19, 	 /*!< PC3 	 	*/
	  XBAR_PIN_PC4 	= 0xFF,  /*!< PC4 Not available in 28 pin package */
	  XBAR_PIN_PC5 	= 0xFF,  /*!< PC5 Not available in 28 pin package */
	  XBAR_PIN_PC6 	= 0xFF,	 /*!< PC6 Not available in 28 pin package */
	  XBAR_PIN_PC7 	= 0xFF,  /*!< PC7 Not available in 28 pin package */

	  XBAR_PIN_PR0 	= 24, 	 /*!< PR0 	 	*/
	  XBAR_PIN_PR1 	= 25,    /*!< PR1       */
	  XBAR_PIN_PR2 	= 26, 	 /*!< PR2 	 	*/
	  XBAR_PIN_PR3 	= 27, 	 /*!< PR3 	 	*/
	  XBAR_PIN_PR4	= 28, 	 /*!< PR4 	 	*/
	  XBAR_PIN_PR5 	= 29, 	 /*!< PR5 	 	*/
	  XBAR_PIN_PR6 	= 0xFF,  /*!< PR6 Not available in 28 pin package */
	  XBAR_PIN_PR7 	= 0xFF,  /*!< PR7 Not available in 28 pin package */

	  /* TIMER 0 */
	  T0OUT 		= XBAR_PIN_PA0, 	/* Default */
	  T0OUT_2 		= XBAR_PIN_PC0,

	  /* TIMER 1 */
	  T1OUT_1		= XBAR_PIN_PA3,
	  T1OUT_2		= XBAR_PIN_PB3,
	  T1OUT_3		= XBAR_PIN_PB5,

	  /* TIMER 2 */
	  T2OUT_1		= XBAR_PIN_PA1,
	  T2OUT_2		= XBAR_PIN_PA6,
	  T2OUT_3 		= XBAR_PIN_PB2,

	  /* UART 0 TX */
	  UART0_TX 		= XBAR_PIN_PB4,		/* UART 0 Default */
	  UART0_TX_2 	= XBAR_PIN_PC2,
	  UART0_TX_3 	= XBAR_PIN_PC5,

	  /* UART 0 RX */
	  UART0_RX 		= XBAR_PIN_PR4,		/* UART 0 Default */
	  UART0_RX_2	= XBAR_PIN_PB5,
	  UART0_RX_3	= XBAR_PIN_PC3,

	  /* UART 1 TX */
	  UART1_TX	 	= XBAR_PIN_PB0,		/* UART 1 Default */
	  UART1_TX_2 	= XBAR_PIN_PA5,
	  UART1_TX_3 	= XBAR_PIN_PC6,

	  /* UART 1 RX */
	  UART1_RX	 	= XBAR_PIN_PB1,		/* UART 1 Default */
	  UART1_RX_2 	= XBAR_PIN_PA2,
	  UART1_RX_3 	= XBAR_PIN_PC7,

	  /* UART 0 CLK */
	  UART0_CLK     = XBAR_PIN_PB2,
	  UART0_CLK_1   = XBAR_PIN_PR5,

	  /* UART 1 CLK */
	  UART1_CLK     = XBAR_PIN_PA1,
	  UART1_CLK_1   = XBAR_PIN_PR0,

	  /* SPI 0 - Master SPI */
	  SPI0_MOSI     = XBAR_PIN_PR4,
	  SPI0_MISO     = XBAR_PIN_PR3,
	  SPI0_SELECT   = XBAR_PIN_PR0,
	  SPI0_CLOCK    = XBAR_PIN_PR2,
	  SPI0_SYSCLK   = XBAR_PIN_PR1,
	  SPI0_IRQ      = XBAR_PIN_PR5,

} XBAR_PIN_Enum;

uint8_t axm0_xbar_uart_config(XBAR_PIN_Enum tx_pin, XBAR_PIN_Enum rx_pin, \
                              XBAR_PIN_Enum uart_clk_pin, XBAR_PIN_Enum tout_pin);

uint8_t axm0_xbar_spi0_config(XBAR_PIN_Enum spi0_mosi, XBAR_PIN_Enum spi0_miso, \
                              XBAR_PIN_Enum spi0_sel, XBAR_PIN_Enum spi0_clk, \
                              XBAR_PIN_Enum spi0_sysclk);

#endif /* defined __ARMEL__ || defined __ARMEB__ */
#endif /* AXM0_XBAR_H */
