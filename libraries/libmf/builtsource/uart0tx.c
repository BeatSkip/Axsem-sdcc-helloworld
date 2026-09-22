/**
******************************************************************************
* @file iotx.c
* @brief UART transmission
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

#include "cpu.h"

#include "libmfuart0.h"
#define uart_poll	   uart0_poll
#define uart_txidle	   uart0_txidle
#define uart_txbusy	   uart0_txbusy
#define uart_txfree	   uart0_txfree
#define uart_rxcount	   uart0_rxcount
#define uart_wait_txdone   uart0_wait_txdone
#define uart_wait_txfree   uart0_wait_txfree
#define uart_wait_rxcount  uart0_wait_rxcount
#define uart_rxpeek	   uart0_rxpeek
#define uart_txpokehex	   uart0_txpokehex
#define uart_txpoke	   uart0_txpoke
#define uart_rxadvance	   uart0_rxadvance
#define uart_txadvance	   uart0_txadvance
#define uart_rx		   uart0_rx
#define uart_tx            uart0_tx
#define uart_writestr      uart0_writestr
#define uart_writehexu16   uart0_writehexu16
#define uart_writehexu32   uart0_writehexu32
#define uart_writeu16      uart0_writeu16
#define uart_writeu32      uart0_writeu32

#if defined __ARMEL__ || defined __ARMEB__
#include "axm0_uart.h"

__reentrantb void uart_wait_txfree(uint8_t v) __reentrant
{
	axm0_uart_wait_txfree(&_uart0_descriptor, v);
}

__reentrantb void uart_wait_txdone(void) __reentrant
{
	axm0_uart_wait_txdone(&_uart0_descriptor);
}

__reentrantb void uart_tx(uint8_t v) __reentrant
{
	axm0_uart_tx(&_uart0_descriptor, v);
}

#else

__reentrantb void uart_wait_txfree(uint8_t v) __reentrant
{
	criticalsection_t crit;
	crit = enter_critical();
	for (;;) {
		__disable_irq();
		if (uart_txfree() >= v)
			break;
		if (!uart_poll())
			wtimer_standby();
		exit_critical(crit);
	}
	exit_critical(crit);
}

#ifdef uart_txbusy

__reentrantb void uart_wait_txdone(void) __reentrant
{
	criticalsection_t crit;
	crit = enter_critical();
	for (;;) {
		uint8_t b;
		__disable_irq();
		b = uart_txbusy();
		if (!b)
			break;
		if (!uart_poll() && b & 2)
			wtimer_standby();
		exit_critical(crit);
	}
	exit_critical(crit);
}

#else

__reentrantb void uart_wait_txdone(void) __reentrant
{
	criticalsection_t crit;
	crit = enter_critical();
	for (;;) {
		__disable_irq();
		if (uart_txidle())
			break;
		if (!uart_poll())
			wtimer_standby();
		exit_critical(crit);
	}
	exit_critical(crit);
}

#endif

__reentrantb void uart_tx(uint8_t v) __reentrant
{
	uart_wait_txfree(1);
	uart_txpoke(0, v);
	uart_txadvance(1);
}

#endif

