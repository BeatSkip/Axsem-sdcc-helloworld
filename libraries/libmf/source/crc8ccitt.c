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

#include "cpu.h"
#include "libmfcrc.h"


#if defined(SDCC)

uint8_t crc8_ccitt_byte(uint8_t crc, uint8_t c) __reentrant __naked
{
	crc;
	c;
	__asm;
	mov	r0,sp
	dec	r0
	dec	r0
	mov	a,@r0
	xrl	a,dpl
	mov	r0,#8
00000$:	clr	c
	rlc	a
	jnc	00001$
	xrl	a,#0x07
00001$:	djnz	r0,00000$
	mov	dpl,a
	ret
	__endasm;
}

uint8_t crc8_ccitt(const __genericaddr uint8_t *buf, uint8_t len, uint8_t init) __reentrant __naked
{
	buf;
	len;
	init;
	__asm;
	mov	r0,sp
	dec	r0
	dec	r0
	mov	a,@r0
	mov	r2,a
	dec	r0
	mov	a,@r0
	mov	r3,a
	jb	_B_7,00010$		; >0x80 code
	jnb	_B_6,00020$		; <0x40 far
	mov	r0,dpl
	jb	_B_5,00030$		; >0x60 pdata
	;; data
00000$:	mov	a,@r0
	inc	r0
	xrl	a,r3
	mov	r4,#8
00001$:	clr	c
	rlc	a
	jnc	00002$
	xrl	a,#0x07
00002$:	djnz	r4,00001$
	mov	r3,a
	djnz	r2,00000$
	sjmp	00040$

	;; code
00010$:	clr	a
	movc	a,@a+dptr
	inc	dptr
	xrl	a,r3
	mov	r4,#8
00011$:	clr	c
	rlc	a
	jnc	00012$
	xrl	a,#0x07
00012$:	djnz	r4,00011$
	mov	r3,a
	djnz	r2,00010$
	sjmp	00040$

	;; xdata
00020$:	movx	a,@dptr
	inc	dptr
	xrl	a,r3
	mov	r4,#8
00021$:	clr	c
	rlc	a
	jnc	00022$
	xrl	a,#0x07
00022$:	djnz	r4,00021$
	mov	r3,a
	djnz	r2,00020$
	sjmp	00040$

	;; pdata
00030$:	movx	a,@r0
	inc	r0
	xrl	a,r3
	mov	r4,#8
00031$:	clr	c
	rlc	a
	jnc	00032$
	xrl	a,#0x07
00032$:	djnz	r4,00031$
	mov	r3,a
	djnz	r2,00030$
	;sjmp	00040$

00040$:	mov	dpl,r3
	ret
	__endasm;
}

#else

#if defined __CX51__ || defined __C51__

static uint8_t crc8_reduce(uint8_t idx)
{
#pragma asm
	mov	a,r7
	mov	r0,#8
c8red0:	clr	c
	rlc	a
	jnc	c8red1
	xrl	a,#0x07
c8red1:	djnz	r0,c8red0
	mov	r7,a
#pragma endasm
}

#else

static __reentrantb uint8_t crc8_reduce(uint8_t idx) __reentrant
{
	uint8_t cnt = 8;
	do {
		uint8_t m = idx & 0x80;
		idx <<= 1;
		if (m)
			idx ^= 0x07;
	} while (--cnt);
	return idx;
}

#endif

__reentrantb uint8_t crc8_ccitt_byte(uint8_t crc, uint8_t c) __reentrant
{
	return crc8_reduce(crc ^ c);
}

__reentrantb uint8_t crc8_ccitt(const uint8_t __genericaddr *buf, uint8_t len, uint8_t init) __reentrant
{
	do {
		init = crc8_reduce(init ^ *buf++);
	} while (len--);
	return init;
}

#endif
