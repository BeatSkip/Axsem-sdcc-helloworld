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

#include "libmftypes.h"

#if defined(SDCC)

__reentrantb int16_t signedlimit16(int16_t x, int16_t lim) __reentrant
{
	__asm
	ar2=0x02
	ar3=0x03
	ar4=0x04
	ar5=0x05
	ar6=0x06
	ar7=0x07
	ar0=0x00
	ar1=0x01

	push	ar0
	mov	a,sp
	add	a,#-4
	mov	r0,a
	mov	a,dph
	jnb	acc.7,00010$
	mov	a,dpl
	add	a,@r0
	inc	r0
	mov	a,dph
	addc	a,@r0
	jnb	acc.7,00000$
	dec	r0
	clr	c
	clr	a
	subb	a,@r0
	inc	r0
	mov	dpl,a
	clr	a
	subb	a,@r0
	sjmp	00001$
00010$:	setb	c
	mov	a,dpl
	subb	a,@r0
	inc	r0
	mov	a,dph
	subb	a,@r0
	jb	acc.7,00000$
	dec	r0
	mov	a,@r0
	inc	r0
	mov	dpl,a
	mov	a,@r0
00001$:	mov	dph,a
00000$:	pop	ar0
	ret
	__endasm;
}

#else

__reentrantb int16_t signedlimit16(int16_t x, int16_t lim) __reentrant
{
	if (x < 0) {
		int16_t xx = x + lim;
		if (xx >= 0)
			return x;
		return -lim;
	}
	{
		int16_t xx = x - lim;
		if (xx <= 0)
			return x;
		return lim;
	}
}

#endif
