/**
******************************************************************************
* @file iowrstr.c
* @brief UART writes string out
* @internal
* @author   Thomas Sailer, Pradeep Kumar GR
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
#define uart_txfree		uart1_txfree
#define uart_rxcount		uart1_rxcount
#define uart_wait_txfree	uart1_wait_txfree
#define _uart_wait_txfree	_uart1_wait_txfree
#define uart_wait_rxcount	uart1_wait_rxcount
#define uart_txbufptr		uart1_txbufptr
#define _uart_txbufptr		_uart1_txbufptr
#define uart_txfreelinear	uart1_txfreelinear
#define _uart_txfreelinear 	_uart1_txfreelinear
#define uart_rxpeek		uart1_rxpeek
#define uart_txpokehex		uart1_txpokehex
#define uart_txpoke		uart1_txpoke
#define uart_rxadvance		uart1_rxadvance
#define uart_txadvance		uart1_txadvance
#define _uart_txadvance		_uart1_txadvance
#define uart_rx			uart1_rx
#define uart_tx			uart1_tx
#define uart_writestr		uart1_writestr
#define uart_writehexu16	uart1_writehexu16
#define uart_writehexu32	uart1_writehexu32
#define uart_writeu16		uart1_writeu16
#define uart_writeu32		uart1_writeu32

#if defined(SDCC)

__reentrantb void uart_writestr(const char __genericaddr *ch) __reentrant
{
	ch;
	__asm;
	mov	r0,dpl
	mov	r7,dph
	clr	a
	mov	r3,a
	mov	r2,a
00000$:	jb	_B_7,00010$		; >0x80 code
	jnb	_B_6,00011$		; <0x40 far
	jb	_B_5,00012$		; >0x60 pdata
	;; idata
	mov	a,@r0
	inc	r0
	sjmp	00013$
00010$: ;; code
	mov	dpl,r0
	mov	dph,r7
	clr	a
	movc	a,@a+dptr
	inc	dptr
	mov	r0,dpl
	mov	r7,dph
	sjmp	00013$
00011$:	;; xdata
	mov	dpl,r0
	mov	dph,r7
	movx	a,@dptr
	inc	dptr
	mov	r0,dpl
	mov	r7,dph
	sjmp	00013$
00012$:	;; pdata
	movx	a,@r0
	inc	r0
00013$:	jz	00001$
	mov	r1,a
	mov	a,r3
	jnz	00002$
	mov	a,r2
	jz	00003$
	mov	dpl,a
	lcall	_uart_txadvance
00003$:	lcall	_uart_txfreelinear
	mov	a,dpl
	jnz	00004$
	mov	r4,b
	mov	dpl,#1
	lcall	_uart_wait_txfree
	mov	b,r4
	lcall	_uart_txfreelinear
	mov	a,dpl
00004$:	mov	r3,a
	clr	a
	mov	r2,a
	mov	dpl,a
	lcall	_uart_txbufptr
	mov	r4,dpl
	mov	r5,dph
00002$:	mov	dpl,r4
	mov	dph,r5
	mov	a,r1
	movx	@dptr,a
	inc	dptr
	mov	r4,dpl
	mov	r5,dph
	inc	r2
	dec	r3
	sjmp	00000$
00001$:	mov	a,r2
	jz	00005$
	mov	dpl,a
	lcall	_uart_txadvance
00005$:
	__endasm;
}

#elif defined __ARMEL__ || defined __ARMEB__
#include "axm0_uart.h"

__reentrantb void uart_writestr(const char __genericaddr *ch) __reentrant
{
	axm0_uart_writestr(&_uart1_descriptor, ch);
}

#else	/* !defined __ARMEL__ || !defined __ARMEB__ */

__reentrantb void uart_writestr(const char __genericaddr *ch) __reentrant
{
	uint8_t __xdata *p;
	uint8_t f = 0;
	uint8_t a = 0;
	for (;;) {
		char c = *ch++;
		if (!c)
			break;
		if (!f) {
			if (a)
				uart_txadvance(a);
			f = uart_txfreelinear();
			if (!f) {
				uart_wait_txfree(1);
				f = uart_txfreelinear();
			}
			p = uart_txbufptr(0);
			a = 0;
		}
		*p++ = c;
		++a;
		--f;
	}
	if (a)
		uart_txadvance(a);
}

#endif
