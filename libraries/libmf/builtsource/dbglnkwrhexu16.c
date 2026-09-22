/**
******************************************************************************
* @file iowrhexu16.c
* @brief Writes 16 bit unsigned hexadecimal number on UART
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

#include "libmfdbglink.h"
#define uart_txfree	   dbglink_txfree
#define uart_rxcount	   dbglink_rxcount
#define uart_wait_txfree   dbglink_wait_txfree
#define uart_wait_rxcount  dbglink_wait_rxcount
#define uart_rxpeek	   dbglink_rxpeek
#define uart_txpokehex	   dbglink_txpokehex
#define uart_txpoke	   dbglink_txpoke
#define uart_rxadvance	   dbglink_rxadvance
#define uart_txadvance	   dbglink_txadvance
#define uart_rx		   dbglink_rx
#define uart_tx            dbglink_tx
#define uart_writestr      dbglink_writestr
#define uart_writehexu16   dbglink_writehexu16
#define uart_writehexu32   dbglink_writehexu32
#define uart_writeu16      dbglink_writeu16
#define uart_writeu32      dbglink_writeu32

#if defined __ARMEL__ || defined __ARMEB__

#else	/* !defined __ARMEL__ || !defined __ARMEB__ */

__reentrantb void uart_writehexu16(uint16_t val, uint8_t nrdig) __reentrant
{
	uint8_t nrdig1 = nrdig;
	uint8_t digit = nrdig1;
	uart_wait_txfree(nrdig);
       	while (digit) {
		--digit;
		uart_txpokehex(digit, val);
		val >>= 4;
	}
	uart_txadvance(nrdig1);
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */
