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

__reentrantb uint16_t pn9_buffer(uint8_t __genericaddr *buf, uint16_t buflen, uint16_t pn9, uint8_t xor) __reentrant __naked
{
	buf;
	buflen;
	pn9;
	xor;
	__asm;
	mov	a,sp
	add	a,#-6
	mov	r0,a
	mov	a,@r0
	mov	r7,a		; xor
	inc	r0
	mov	a,@r0
	mov	r4,a		; pn9 lo
	inc	r0
	mov	a,@r0
	mov	r5,a		; pn9 hi
	inc	r0
	mov	a,@r0
	mov	r2,a		; buflen lo
	inc	r0
	mov	a,@r0
	mov	r3,a		; buflen hi
	orl	a,r2
	jz	00001$
	mov	a,r2
	jz	00000$
	inc	r3
00000$:	jb	_B_7,00019$		; >0x80 code
	jnb	_B_6,00029$		; <0x40 far
	mov	r0,dpl
	jb	_B_5,00030$		; >0x60 pdata
	;; idata
00040$:	mov	a,@r0
	xrl	a,r4
	xrl	a,r7
	mov	@r0,a
	inc	r0
	mov	a,r5
	rrc	a
	mov	a,r4
	rrc	a
	jnb	acc.4,00041$
	cpl	c
00041$:	rrc	a
	jnb	acc.4,00042$
	cpl	c
00042$:	rrc	a
	jnb	acc.4,00043$
	cpl	c
00043$:	rrc	a
	jnb	acc.4,00044$
	cpl	c
00044$:	rrc	a
	jnb	acc.4,00045$
	cpl	c
00045$:	rrc	a
	jnb	acc.4,00046$
	cpl	c
00046$:	rrc	a
	jnb	acc.4,00047$
	cpl	c
00047$:	rrc	a
	jnb	acc.4,00048$
	cpl	c
00048$:	mov	r4,a
	clr	a
	rlc	a
	mov	r5,a
	djnz	r2,00040$
	djnz	r3,00040$

00001$:
	mov	dpl,r4
	mov	dph,r5
	ret

00019$:
	ljmp	00010$

00029$:
	ljmp	00020$

00030$:	movx	a,@r0
	xrl	a,r4
	xrl	a,r7
	movx	@r0,a
	inc	r0
	mov	a,r5
	rrc	a
	mov	a,r4
	rrc	a
	jnb	acc.4,00031$
	cpl	c
00031$:	rrc	a
	jnb	acc.4,00032$
	cpl	c
00032$:	rrc	a
	jnb	acc.4,00033$
	cpl	c
00033$:	rrc	a
	jnb	acc.4,00034$
	cpl	c
00034$:	rrc	a
	jnb	acc.4,00035$
	cpl	c
00035$:	rrc	a
	jnb	acc.4,00036$
	cpl	c
00036$:	rrc	a
	jnb	acc.4,00037$
	cpl	c
00037$:	rrc	a
	jnb	acc.4,00038$
	cpl	c
00038$:	mov	r4,a
	clr	a
	rlc	a
	mov	r5,a
	djnz	r2,00030$
	djnz	r3,00030$
	sjmp	00001$

00020$:	movx	a,@dptr
	xrl	a,r4
	xrl	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	rrc	a
	mov	a,r4
	rrc	a
	jnb	acc.4,00021$
	cpl	c
00021$:	rrc	a
	jnb	acc.4,00022$
	cpl	c
00022$:	rrc	a
	jnb	acc.4,00023$
	cpl	c
00023$:	rrc	a
	jnb	acc.4,00024$
	cpl	c
00024$:	rrc	a
	jnb	acc.4,00025$
	cpl	c
00025$:	rrc	a
	jnb	acc.4,00026$
	cpl	c
00026$:	rrc	a
	jnb	acc.4,00027$
	cpl	c
00027$:	rrc	a
	jnb	acc.4,00028$
	cpl	c
00028$:	mov	r4,a
	clr	a
	rlc	a
	mov	r5,a
	djnz	r2,00020$
	djnz	r3,00020$
	sjmp	00001$

00010$:	mov	a,r5
	rrc	a
	mov	a,r4
	rrc	a
	jnb	acc.4,00011$
	cpl	c
00011$:	rrc	a
	jnb	acc.4,00012$
	cpl	c
00012$:	rrc	a
	jnb	acc.4,00013$
	cpl	c
00013$:	rrc	a
	jnb	acc.4,00014$
	cpl	c
00014$:	rrc	a
	jnb	acc.4,00015$
	cpl	c
00015$:	rrc	a
	jnb	acc.4,00016$
	cpl	c
00016$:	rrc	a
	jnb	acc.4,00017$
	cpl	c
00017$:	rrc	a
	jnb	acc.4,00018$
	cpl	c
00018$:	mov	r4,a
	clr	a
	rlc	a
	mov	r5,a
	djnz	r2,00010$
	djnz	r3,00010$
	ljmp	00001$
	__endasm;
}

#else

__reentrantb uint16_t pn9_buffer(uint8_t __genericaddr *buf, uint16_t buflen, uint16_t pn9, uint8_t xor) __reentrant
{
	if (!buflen)
		return pn9;
	do {
		*buf++ ^= pn9 ^ xor;
		pn9 = pn9_advance_byte(pn9);
	} while (--buflen);
	return pn9;
}

#endif
