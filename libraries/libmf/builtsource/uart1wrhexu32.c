/**
******************************************************************************
* @file iowrhexu32.c
* @brief Writes 32 bit unsigned hexadecimal number on UART
* @internal
* @author   Thomas Sailer, Pradeep Kumar G R
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
* @ingroup UART
*
* @details
*/

#include "libmfuart1.h"
#define uart_txfree	   uart1_txfree
#define uart_rxcount	   uart1_rxcount
#define uart_wait_txfree   uart1_wait_txfree
#define uart_wait_rxcount  uart1_wait_rxcount
#define uart_rxpeek	   uart1_rxpeek
#define uart_txpokehex	   uart1_txpokehex
#define uart_txpoke	   uart1_txpoke
#define uart_rxadvance	   uart1_rxadvance
#define uart_txadvance	   uart1_txadvance
#define uart_rx		   uart1_rx
#define uart_tx            uart1_tx
#define uart_writestr      uart1_writestr
#define uart_writehexu16   uart1_writehexu16
#define uart_writehexu32   uart1_writehexu32
#define uart_writeu16      uart1_writeu16
#define uart_writeu32      uart1_writeu32

#if defined __ARMEL__ || defined __ARMEB__
#include "axm0_uart.h"

__reentrantb void uart_writehexu32(uint32_t val, uint8_t nrdig) __reentrant
{
	axm0_uart_writehexu32(&_uart1_descriptor, val, nrdig);
}

#else	/* !defined __ARMEL__ || !defined __ARMEB__ */

void uart_writehexu32(uint32_t val, uint8_t nrdig)
{
	uint8_t __autodata nrdig1 = nrdig;
	uint8_t __autodata digit = nrdig1;
	uart_wait_txfree(nrdig1);
	while (digit) {
		--digit;
		uart_txpokehex(digit, val);
		val >>= 4;
	}
	uart_txadvance(nrdig1);
}

#endif /* __ARMEL__ || defined __ARMEB__ */
