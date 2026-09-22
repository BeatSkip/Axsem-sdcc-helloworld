/**
******************************************************************************
* @file desencdec.c
* @brief DES encryption and decryption
* @internal
* @author   Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a "ON Semiconductor").
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software") and
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

#include "des.h"

#if defined(DES_ASM) && defined(SDCC)

#pragma preproc_asm +
#pragma sdcc_hash +

#define PERM8_4(regl,regr,mask)	\
	mov	a,regl		\
	swap	a		\
	xrl	a,regr		\
	anl	a,#(mask)	\
	xrl	a##regr,a	\
	swap	a		\
	xrl	a##regl,a

#define PERM8_2(regl,regr,mask)	\
	mov	a,regl		\
	rr	a		\
	rr	a		\
	xrl	a,regr		\
	anl	a,#(mask)	\
	xrl	a##regr,a	\
	rl	a		\
	rl	a		\
	xrl	a##regl,a

#define PERM8_0(regl,regr,mask)	\
	mov	a,regl		\
	xrl	a,regr		\
	anl	a,#(mask)	\
	xrl	a##regr,a	\
	xrl	a##regl,a

#define SWAP8(regl,regr)	\
	mov	a,regl		\
	xch	a,regr		\
	mov	regl,a

#define ROTATE_LEFT(reg0,reg1,reg2,reg3) \
	mov	a,reg3		\
	rlc	a		\
	mov	a,reg0		\
	rlc	a		\
	mov	reg0,a		\
	mov	a,reg1		\
	rlc	a		\
	mov	reg1,a		\
	mov	a,reg2		\
	rlc	a		\
	mov	reg2,a		\
	mov	a,reg3		\
	rlc	a		\
	mov	reg3,a

#define ROTATE_RIGHT(reg0,reg1,reg2,reg3) \
	mov	a,reg0		\
	rrc	a		\
	mov	a,reg3		\
	rrc	a		\
	mov	reg3,a		\
	mov	a,reg2		\
	rrc	a		\
	mov	reg2,a		\
	mov	a,reg1		\
	rrc	a		\
	mov	reg1,a		\
	mov	a,reg0		\
	rrc	a		\
	mov	reg0,a

#define DESROUND(from0,from1,from2,from3,to0,to1,to2,to3)	\
	;; SBox 0				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+0*64)		\
	xrl	a,from0				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x40				\
	xrl	a##to0,a			\
	mov	a,b				\
	anl	a,#0x10				\
	xrl	a##to1,a			\
	mov	a,b				\
	anl	a,#0x04				\
	xrl	a##to2,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x10				\
	xrl	a##to3,a			\
	;; SBox 2				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+2*64)		\
	xrl	a,from1				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x10				\
	xrl	a##to0,a			\
	mov	a,b				\
	anl	a,#0x40				\
	xrl	a##to1,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x40				\
	xrl	a##to2,a			\
	mov	a,b				\
	rl	a				\
	rl	a				\
	anl	a,#0x20				\
	xrl	a##to3,a			\
	;; SBox 4				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+4*64)		\
	xrl	a,from2				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x81				\
	xrl	a##to0,a			\
	mov	a,b				\
	anl	a,#0x20				\
	xrl	a##to1,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x80				\
	xrl	a##to2,a			\
	;; SBox 6				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+6*64)		\
	xrl	a,from3				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x20				\
	xrl	a##to0,a			\
	mov	a,b				\
	anl	a,#0x80				\
	xrl	a##to1,a			\
	mov	a,b				\
	anl	a,#0x10				\
	xrl	a##to2,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x80				\
	xrl	a##to3,a			\
	;; SBox 1				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+1*64)		\
	mov	b,a				\
	mov	a,from0				\
	swap	a				\
	anl	a,#0x0f				\
	xrl	b,a				\
	mov	a,from1				\
	swap	a				\
	anl	a,#0xf0				\
	xrl	a,b				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x02				\
	xrl	a##to0,a			\
	mov	a,b				\
	anl	a,#0x08				\
	xrl	a##to1,a			\
	mov	a,b				\
	anl	a,#0x20				\
	xrl	a##to2,a			\
	mov	a,b				\
	anl	a,#0x04				\
	xrl	a##to3,a			\
	;; SBox 3				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+3*64)		\
	mov	b,a				\
	mov	a,from1				\
	swap	a				\
	anl	a,#0x0f				\
	xrl	b,a				\
	mov	a,from2				\
	swap	a				\
	anl	a,#0xf0				\
	xrl	a,b				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x01				\
	xrl	a##to1,a			\
	mov	a,b				\
	anl	a,#0x08				\
	xrl	a##to2,a			\
	mov	a,b				\
	anl	a,#0x42				\
	xrl	a##to3,a			\
	;; SBox 5				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+5*64)		\
	mov	b,a				\
	mov	a,from2				\
	swap	a				\
	anl	a,#0x0f				\
	xrl	b,a				\
	mov	a,from3				\
	swap	a				\
	anl	a,#0xf0				\
	xrl	a,b				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x08				\
	xrl	a##to0,a			\
	mov	a,b				\
	anl	a,#0x02				\
	xrl	a##to1,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x02				\
	xrl	a##to2,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x08				\
	xrl	a##to3,a			\
	;; SBox 7				\
	movx	a,@dptr				\
	inc	dptr				\
	push	dpl				\
	push	dph				\
	mov	dptr,#(_des_sbox+7*64)		\
	mov	b,a				\
	mov	a,from3				\
	swap	a				\
	anl	a,#0x0f				\
	xrl	b,a				\
	mov	a,from0				\
	swap	a				\
	anl	a,#0xf0				\
	xrl	a,b				\
	anl	a,#0x3f				\
	movc	a,@a+dptr			\
	pop	dph				\
	pop	dpl				\
	mov	b,a				\
	anl	a,#0x04				\
	xrl	a##to0,a			\
	mov	a,b				\
	rl	a				\
	mov	b,a				\
	anl	a,#0x04				\
	xrl	a##to1,a			\
	mov	a,b				\
	anl	a,#0x01				\
	xrl	a##to2,a			\
	mov	a,b				\
	rl	a				\
	anl	a,#0x01				\
	xrl	a##to3,a


void des_encdec(uint16_t flags, const uint8_t __xdata *inptr, uint8_t __xdata *outptr, const uint8_t __xdata *keysched)
{
	flags;
	inptr;
	outptr;
	keysched;
	__asm
	;; FIXME: loop blurb
	mov	a,dpl
	jnz	desencdecnz
	ret
desencdecnz:
	mov	b,dph		; flags word; bit 0 = 1: decrypt, 0: encrypt
desencdecloop:
	push	dpl
	;; Copy Input Buffer into Regfile
	mov	dpl,_des_encdec_PARM_2
	mov	dph,(_des_encdec_PARM_2+1)
	movx	a,@dptr
	inc	dptr
	mov	r7,a
	movx	a,@dptr
	inc	dptr
	mov	r6,a
	movx	a,@dptr
	inc	dptr
	mov	r5,a
	movx	a,@dptr
	inc	dptr
	mov	r4,a
	movx	a,@dptr
	inc	dptr
	mov	r3,a
	movx	a,@dptr
	inc	dptr
	mov	r2,a
	movx	a,@dptr
	inc	dptr
	mov	r1,a
	movx	a,@dptr
	inc	dptr
	mov	r0,a
	mov	_des_encdec_PARM_2,dpl
	mov	(_des_encdec_PARM_2+1),dph
	;; Initial Permutation
	PERM8_4(r4,r0,0x0f)
	PERM8_4(r5,r1,0x0f)
	PERM8_4(r6,r2,0x0f)
	PERM8_4(r7,r3,0x0f)

	SWAP8(r6,r0)
	SWAP8(r7,r1)

	PERM8_2(r0,r4,0x33)
	PERM8_2(r1,r5,0x33)
	PERM8_2(r2,r6,0x33)
	PERM8_2(r3,r7,0x33)

	SWAP8(r1,r4)
	SWAP8(r3,r6)

	ROTATE_LEFT(r0,r1,r2,r3)

	PERM8_0(r4,r0,0xaa)
	PERM8_0(r5,r1,0xaa)
	PERM8_0(r6,r2,0xaa)
	PERM8_0(r7,r3,0xaa)

	ROTATE_LEFT(r4,r5,r6,r7)

	;; DES Round Processing
	mov	dpl,_des_encdec_PARM_4
	mov	dph,(_des_encdec_PARM_4+1)
	jnb	b.0,desencdecnoks0
	mov	a,#(17*8)
	add	a,dpl
	mov	dpl,a
	clr	a
	addc	a,dph
	mov	dph,a
desencdecnoks0:
	mov	a,#8
desencdecroundloop:
	push	acc
	push	b
	jnb	b.0,desencdecnoks1
	mov	a,#-16
	add	a,dpl
	mov	dpl,a
	mov	a,#(-16>>8)
	addc	a,dph
	mov	dph,a
desencdecnoks1:
	DESROUND(r0,r1,r2,r3,r4,r5,r6,r7)
	pop	b
	push	b
	jnb	b.0,desencdecnoks2
	mov	a,#-16
	add	a,dpl
	mov	dpl,a
	mov	a,#(-16>>8)
	addc	a,dph
	mov	dph,a
desencdecnoks2:
	DESROUND(r4,r5,r6,r7,r0,r1,r2,r3)
	pop	b
	pop	acc
	djnz	acc,desencdecroundloop1
	sjmp	desencdecfperm
desencdecroundloop1:
	ljmp	desencdecroundloop
desencdecfperm:

	;; Final Permutation
	ROTATE_RIGHT(r0,r1,r2,r3)

	PERM8_0(r0,r4,0xaa)
	PERM8_0(r1,r5,0xaa)
	PERM8_0(r2,r6,0xaa)
	PERM8_0(r3,r7,0xaa)

	ROTATE_RIGHT(r4,r5,r6,r7)

	SWAP8(r5,r0)
	SWAP8(r7,r2)

	PERM8_2(r4,r0,0x33)
	PERM8_2(r5,r1,0x33)
	PERM8_2(r6,r2,0x33)
	PERM8_2(r7,r3,0x33)

	SWAP8(r2,r4)
	SWAP8(r3,r5)

	PERM8_4(r0,r4,0x0f)
	PERM8_4(r1,r5,0x0f)
	PERM8_4(r2,r6,0x0f)
	PERM8_4(r3,r7,0x0f)

	;; Copy Regfile into Output Buffer
	mov	dpl,_des_encdec_PARM_3
	mov	dph,(_des_encdec_PARM_3+1)
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	_des_encdec_PARM_3,dpl
	mov	(_des_encdec_PARM_3+1),dph

	;; main loop
	pop	dpl
	djnz	dpl,desencdecloop1
	ret

desencdecloop1:
	ljmp	desencdecloop
	__endasm;
}

#endif
