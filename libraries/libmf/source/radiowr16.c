/**
******************************************************************************
* @file radiowr16.c
* @brief 16 bit write to radio register
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
* @ingroup RADIO
*
* @details
*/

#include "cpu.h"
#include "libmftypes.h"
#include "libmfradio.h"

#if defined(SDCC)

__reentrantb void radio_write16(uint16_t addr, uint16_t d) __reentrant __naked
{
	addr;
	d;
        __asm;
	ar2=0x02
	ar3=0x03
	ar4=0x04
	ar5=0x05
	ar6=0x06
	ar7=0x07
	ar0=0x00
	ar1=0x01

	mov	a,dph
	anl	a,#0x0F
	orl	a,#(AX8052_RADIOBASE >> 8)
	mov	dph,a
	mov	a,sp
	add	a,#-3
	push	ar0
	mov	r0,a
	mov	a,_IE
	rlc	a
	clr	_EA
	mov	a,_RADIOACC
	mov	b,a
	anl	a,#0xFC
	orl	a,#0x01
	mov	_RADIOACC,a
	mov	_RADIODATA2,@r0
	inc	r0
	mov	a,@r0
	movx	@dptr,a
	mov	_RADIOACC,b
	mov	_EA,c
	pop	ar0
	ret
        __endasm;
}

#elif defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

#include "radioutil.h"

__reentrantb void _radio_write16(uint32_t addr, uint16_t d) __reentrant
{
	_radio_spi_io(0x80, addr, d, 2);
}

#else

__reentrantb void _radio_write16(uint32_t addr, uint16_t d) __reentrant
{
	*_radio_addr(addr, 0x080000) = d;
}

#endif

#else

__reentrantb void radio_write16(uint16_t addr, uint16_t d) __reentrant
{
	uint8_t racc;
	criticalsection_t crit;
	addr &= 0xFFF;
	addr |= AX8052_RADIOBASE;
	crit = enter_critical();
	racc = RADIOACC;
	RADIOACC = (racc & 0xFC) | 0x01;
	RADIODATA2 = d;
	d >>= 8;
	*(uint8_t __xdata *)addr = d;
	RADIOACC = racc;
	exit_critical(crit);
}

#endif
