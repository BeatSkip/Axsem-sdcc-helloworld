/**
******************************************************************************
* @file axm0_uart1.c
* @brief UART buffer size definitions
* @internal
* @author   Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2018 Semiconductor Components Industries LLC (d/b/a ON Semiconductor).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software) and
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

#if defined __ARMEL__ || defined __ARMEB__

#include "libmfuart.h"
#include "axm0_uart.h"

static struct uart_fifo_pointers uart1_fifo_pointers;

extern uint8_t __data uart1_rxbuffer[];
extern uint8_t __data uart1_txbuffer[];
extern const uint16_t __code uart1_rxbuffer_size;
extern const uint16_t __code uart1_txbuffer_size;

#ifdef __AXM0

const struct uart_descriptor _uart1_descriptor = {
	&uart1_fifo_pointers,
	uart1_txbuffer,
	uart1_rxbuffer,
	&uart1_txbuffer_size,
	&uart1_rxbuffer_size,
	UART1,
	UART1_IRQn,
	1
};

#endif

#ifdef __AXM0F2

const struct uart_descriptor _uart1_descriptor = {
	&uart1_fifo_pointers,
	uart1_txbuffer,
	uart1_rxbuffer,
	&uart1_txbuffer_size,
	&uart1_rxbuffer_size,
	SCB2,
	SCB2_IRQn,
	1
};

#endif

#endif
