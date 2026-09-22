/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer
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
* @ingroup
*
* @details
*/

#include "libmfcrc.h"

#if defined(SDCC)

__reentrantb uint16_t pn9_advance_bits(uint16_t pn9, uint16_t bits) __reentrant __naked
{
	pn9;
	bits;
	__asm
	mov	a,sp
	add	a,#-3
	mov	r0,a
	mov	a,@r0
	mov	r2,a
	inc	r0
	mov	a,@r0
	mov	r3,a
	orl	a,r2
	jz	00000$
	mov	a,r2
	jz	00003$
	inc	r3
00003$:	mov	a,dph
	rrc	a
	mov	a,dpl
00001$:	rrc	a
	jnb	acc.4,00002$
	cpl	c
00002$:	djnz	r2,00001$
	djnz	r3,00001$
	mov	dpl,a
	clr	a
	rlc	a
	mov	dph,a
00000$:	ret
	__endasm;
}

#else

__reentrantb uint16_t pn9_advance_bits(uint16_t pn9, uint16_t bits) __reentrant
{
	if (!bits)
		return pn9;
	do {
		pn9 = (uint8_t)(pn9 >> 1) | (((pn9 << 3) ^ (pn9 << 8)) & 0x100);
	} while (--bits);
	return pn9;
}

#endif
