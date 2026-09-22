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
#include "libmftypes.h"

#if defined SDCC

/**
 * \brief fast memset
 *
 */
__reentrantb void fmemset(void __genericaddr *p, char c, uint16_t n) __reentrant __naked
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

	mov	r0,sp
	dec	r0
	dec	r0
	mov	ar5,@r0
	dec	r0
	mov	ar7,@r0
	dec	r0
	mov	a,@r0
	mov	r6,a
	jnz	00001$
	orl	a,r7
	jnz	00000$
00002$:	ret
00001$:	inc	r7
00000$:	;; decide memory space
	mov	a,r5
	jb	_B_7,00002$		; >0x80 code
	jnb	_B_6,xdataloop$		; <0x40 far
	mov	r0,dpl
	jb	_B_5,pdataloop$		; >0x60 pdata
idataloop$:
	mov	@r0,a
	inc	r0
	djnz	r6,idataloop$
	djnz	r7,idataloop$
	ret
pdataloop$:
	movx	@r0,a
	inc	r0
	djnz	r6,pdataloop$
	djnz	r7,pdataloop$
	ret
xdataloop$:
	movx	@dptr,a
	inc	dptr
	djnz	r6,xdataloop$
	djnz	r7,xdataloop$
	ret
	__endasm;
}

#elif defined __ICC8051__

__reentrantb void fmemset(void __genericaddr *p, char c, uint16_t n) __reentrant
{
	union ptr {
		void __genericaddr *p;
		uint8_t __data *pd;
		uint8_t __xdata *px;
		uint8_t b[3];
	};
	union ptr pp;
	uint8_t pa;
	uint8_t n0 = n, n1 = n >> 8;
	if (n0)
		++n1;
	else if (!n1)
		return;
	pp.p = p;
	pa = pp.b[2];
	if (pa & 0x80)
		return;
	if (pa & 0x01) {
		uint8_t __data *p1 = pp.pd;
		do {
			do {
				*p1++ = c;
			} while (--n0);
		} while (--n1);
	} else {
		uint8_t __xdata *p1 = pp.px;
		do {
			do {
				*p1++ = c;
			} while (--n0);
		} while (--n1);
	}
}

#else

__reentrantb void fmemset(void __genericaddr *p, char c, uint16_t n) __reentrant
{
	char __genericaddr *pp = (char __genericaddr *)p;
	for (; n; --n)
		*pp++ = c;
}

#endif
