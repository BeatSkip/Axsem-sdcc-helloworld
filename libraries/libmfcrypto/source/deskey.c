/**
******************************************************************************
* @file deskey.c
* @brief DES Key
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

/* reverse index! */
static const uint8_t __code rotate_tab[16] = {
	0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0
};

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

#define PERM8_0(regl,regr,mask)	\
	mov	a,regl		\
	xrl	a,regr		\
	anl	a,#(mask)	\
	xrl	a##regr,a	\
	xrl	a##regl,a

#define ROTATE28_LEFT(reg0,reg1,reg2,reg3) \
	mov	a,reg3		\
	swap	a		\
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
	anl	a,#0x3f		\
	mov	reg3,a

#define LKEY0(setb)		\
	clr	a		\
	mov	c,b.0		\
	mov	setb,c		\
	orl	ar4,a		\
	mov	c,b.1		\
	mov	setb,c		\
	orl	ar5,a		\
	mov	c,b.2		\
	mov	setb,c		\
	orl	ar6,a		\
	mov	c,b.3		\
	mov	setb,c		\
	orl	ar7,a

#define LKEY5(setb)		\
	clr	a		\
	mov	c,b.5		\
	mov	setb,c		\
	orl	ar4,a		\
	mov	c,b.6		\
	mov	setb,c		\
	orl	ar5,a		\
	mov	c,b.7		\
	mov	setb,c		\
	orl	ar6,a

#define LKEY3(setb)		\
	clr	a		\
	mov	c,b.0		\
	mov	setb,c		\
	orl	ar7,a

#define RKEY1(setb)		\
	clr	a		\
	mov	c,b.1		\
	mov	setb,c		\
	orl	ar3,a		\
	mov	c,b.2		\
	mov	setb,c		\
	orl	ar2,a		\
	mov	c,b.3		\
	mov	setb,c		\
	orl	ar1,a		\
	mov	c,b.4		\
	mov	setb,c		\
	orl	ar0,a

#define RKEY4(setb)		\
	clr	a		\
	mov	c,b.4		\
	mov	setb,c		\
	orl	ar3,a		\
	mov	c,b.5		\
	mov	setb,c		\
	orl	ar2,a		\
	mov	c,b.6		\
	mov	setb,c		\
	orl	ar1,a		\
	mov	c,b.7		\
	mov	setb,c		\
	orl	ar0,a

#define KEYBYTE(reg5,bit5,reg4,bit4,reg3,bit3,reg2,bit2,reg1,bit1,reg0,bit0) \
	clr	a		\
	mov	b,reg5		\
	mov	c,bit5		\
	rlc	a		\
	mov	b,reg4		\
	mov	c,bit4		\
	rlc	a		\
	mov	b,reg3		\
	mov	c,bit3		\
	rlc	a		\
	mov	b,reg2		\
	mov	c,bit2		\
	rlc	a		\
	mov	b,reg1		\
	mov	c,bit1		\
	rlc	a		\
	mov	b,reg0		\
	mov	c,bit0		\
	rlc	a		\
	movx	@dptr,a		\
	inc	dptr

void des_keyexp(const uint8_t key[8], uint8_t __xdata *keysched)
{
	key;
	keysched;
	__asm
	;; copy input
	lcall   __gptrget
	inc	dptr
	mov	r7,a
	lcall   __gptrget
	inc	dptr
	mov	r6,a
	lcall   __gptrget
	inc	dptr
	mov	r5,a
	lcall   __gptrget
	inc	dptr
	mov	r4,a
	lcall   __gptrget
	inc	dptr
	mov	r3,a
	lcall   __gptrget
	inc	dptr
	mov	r2,a
	lcall   __gptrget
	inc	dptr
	mov	r1,a
	lcall   __gptrget
	inc	dptr
	mov	r0,a

	;; PC1
	PERM8_4(r0,r4,0x0f)
	PERM8_4(r1,r5,0x0f)
	PERM8_4(r2,r6,0x0f)
	PERM8_4(r3,r7,0x0f)

	PERM8_0(r0,r4,0x10)
	PERM8_0(r1,r5,0x10)
	PERM8_0(r2,r6,0x10)
	PERM8_0(r3,r7,0x10)

	push	ar4
	push	ar5
	push	ar6
	mov	b,r7
	clr	a
	mov	r4,a
	mov	r5,a
	mov	r6,a
	mov	r7,a
	LKEY5(acc.4)
	LKEY0(acc.0)
	LKEY3(acc.5)
	pop	b
	LKEY5(acc.5)
	LKEY0(acc.1)
	LKEY3(acc.6)
	pop	b
	LKEY5(acc.6)
	LKEY0(acc.2)
	LKEY3(acc.7)
	pop	b
	LKEY5(acc.7)
	LKEY0(acc.3)

	push	ar0
	push	ar1
	push	ar2
	mov	b,r3
	clr	a
	mov	r0,a
	mov	r1,a
	mov	r2,a
	mov	r3,a
	RKEY4(acc.4)
	RKEY1(acc.0)
	pop	b
	RKEY4(acc.5)
	RKEY1(acc.1)
	pop	b
	RKEY4(acc.6)
	RKEY1(acc.2)
	pop	b
	RKEY4(acc.7)
	RKEY1(acc.3)

	mov	a,#0x0f
	anl	ar3,a
	anl	ar7,a

	;; PC2 Loop
	mov	dpl,_des_keyexp_PARM_2
	mov	dph,(_des_keyexp_PARM_2+1)
	mov	a,#16
deskeyloop:
	push	acc
	push	dpl
	push	dph
	mov	dptr,#(_rotate_tab-1)
	movc	a,@a+dptr
	pop	dph
	pop	dpl
	jz	deskeysinglerot
	ROTATE28_LEFT(r0,r1,r2,r3)
	ROTATE28_LEFT(r4,r5,r6,r7)
deskeysinglerot:
	ROTATE28_LEFT(r0,r1,r2,r3)
	ROTATE28_LEFT(r4,r5,r6,r7)

        KEYBYTE(r1,b.2,r1,b.6,r0,b.6,r2,b.4,r3,b.3,r3,b.0)
        KEYBYTE(r3,b.2,r2,b.0,r0,b.5,r1,b.3,r2,b.7,r1,b.0)
        KEYBYTE(r5,b.4,r6,b.5,r4,b.1,r5,b.0,r5,b.7,r7,b.2)
        KEYBYTE(r7,b.1,r4,b.0,r5,b.5,r6,b.6,r4,b.7,r6,b.2)
        KEYBYTE(r1,b.4,r0,b.7,r2,b.1,r0,b.0,r2,b.6,r0,b.3)
        KEYBYTE(r1,b.7,r0,b.4,r3,b.1,r2,b.3,r1,b.1,r0,b.1)
        KEYBYTE(r4,b.5,r5,b.1,r6,b.0,r7,b.0,r4,b.2,r6,b.4)
        KEYBYTE(r5,b.6,r5,b.3,r6,b.1,r4,b.4,r7,b.3,r6,b.7)

	pop	acc
	djnz	acc,deskeyloop1
	ret
deskeyloop1:
	ljmp	deskeyloop
	__endasm;
}

#else

#define PERM8(l,r,offs,mask)                                                                \
do {                                                                                        \
	uint8_t t = ((desstate_lr[(l)] >> (offs)) ^ desstate_lr[(r)]) & (mask);             \
	desstate_lr[(r)] ^= t;                                                              \
	desstate_lr[(l)] ^= t << (offs);                                                    \
} while (0)

#define LKEY(x,sh)                                                                          \
do {                                                                                        \
	uint8_t t = (x);                                                                    \
	desstate_lr[4] |= (t & 1) << sh;                                                    \
	t >>= 1;                                                                            \
	desstate_lr[5] |= (t & 1) << sh;                                                    \
	t >>= 1;                                                                            \
	desstate_lr[6] |= (t & 1) << sh;                                                    \
	t >>= 1;                                                                            \
	desstate_lr[7] |= (t & 1) << sh;                                                    \
} while (0)

#define RKEY(x,sh)                                                                          \
do {                                                                                        \
	uint8_t t = (x);                                                                    \
	desstate_lr[3] |= (t & 1) << sh;                                                    \
	t >>= 1;                                                                            \
	desstate_lr[2] |= (t & 1) << sh;                                                    \
	t >>= 1;                                                                            \
	desstate_lr[1] |= (t & 1) << sh;                                                    \
	t >>= 1;                                                                            \
	desstate_lr[0] |= (t & 1) << sh;                                                    \
} while (0)

void des_keyexp(const uint8_t key[8], uint8_t __xdata *keysched)
{
	uint8_t __autodata desstate_lr[8];
	uint8_t __autodata round;

	// copy input
	desstate_lr[7] = key[0];
	desstate_lr[6] = key[1];
	desstate_lr[5] = key[2];
	desstate_lr[4] = key[3];
	desstate_lr[3] = key[4];
	desstate_lr[2] = key[5];
	desstate_lr[1] = key[6];
	desstate_lr[0] = key[7];

	// PC1
	PERM8(0, 4, 4, 0x0f);
	PERM8(1, 5, 4, 0x0f);
	PERM8(2, 6, 4, 0x0f);
	PERM8(3, 7, 4, 0x0f);

	PERM8(0, 4, 0, 0x10);
	PERM8(1, 5, 0, 0x10);
	PERM8(2, 6, 0, 0x10);
	PERM8(3, 7, 0, 0x10);

	{
		uint8_t __autodata t0 = desstate_lr[4];
		uint8_t __autodata t1 = desstate_lr[5];
		uint8_t __autodata t2 = desstate_lr[6];
		uint8_t __autodata t3 = desstate_lr[7];
		desstate_lr[4] = desstate_lr[5] = desstate_lr[6] = desstate_lr[7] = 0;
		LKEY(t0, 3);
		LKEY(t1, 2);
		LKEY(t2, 1);
		LKEY(t3, 0);
		LKEY((t0 >> 5) | (t1 << 3), 7);
		LKEY((t1 >> 5) | (t2 << 3), 6);
		LKEY((t2 >> 5) | (t3 << 3), 5);
		LKEY((t3 >> 5), 4);
		desstate_lr[7] &= 0x0f;
	}
	{
		uint8_t __autodata t0 = desstate_lr[0];
		uint8_t __autodata t1 = desstate_lr[1];
		uint8_t __autodata t2 = desstate_lr[2];
		uint8_t __autodata t3 = desstate_lr[3];
		desstate_lr[0] = desstate_lr[1] = desstate_lr[2] = desstate_lr[3] = 0;
		RKEY(t0 >> 1, 3);
		RKEY(t1 >> 1, 2);
		RKEY(t2 >> 1, 1);
		RKEY(t3 >> 1, 0);
		RKEY(t0 >> 4, 7);
		RKEY(t1 >> 4, 6);
		RKEY(t2 >> 4, 5);
		RKEY(t3 >> 4, 4);
		desstate_lr[3] &= 0x0f;
	}

	// PC2 Loop
	round = 16;
	do {
		{
			uint8_t __autodata rot = rotate_tab[round-1] + 1;
			uint8_t __autodata t;
			t = desstate_lr[3];
			desstate_lr[3] = (desstate_lr[3] << rot) | (desstate_lr[2] >> (8-rot));
			desstate_lr[2] = (desstate_lr[2] << rot) | (desstate_lr[1] >> (8-rot));
			desstate_lr[1] = (desstate_lr[1] << rot) | (desstate_lr[0] >> (8-rot));
			desstate_lr[0] = (desstate_lr[0] << rot) | (t >> (4-rot));
			desstate_lr[3] &= 0x0f;
			t = desstate_lr[7];
			desstate_lr[7] = (desstate_lr[7] << rot) | (desstate_lr[6] >> (8-rot));
			desstate_lr[6] = (desstate_lr[6] << rot) | (desstate_lr[5] >> (8-rot));
			desstate_lr[5] = (desstate_lr[5] << rot) | (desstate_lr[4] >> (8-rot));
			desstate_lr[4] = (desstate_lr[4] << rot) | (t >> (4-rot));
			desstate_lr[7] &= 0x0f;
		}

                *keysched++ = ((desstate_lr[3] & 0x01)
                             | ((desstate_lr[3] >> 2) & 0x02)
                             | ((desstate_lr[2] >> 2) & 0x04)
                             | ((desstate_lr[1] << 3) & 0x20)
                             | ((desstate_lr[1] >> 2) & 0x10)
                             | ((desstate_lr[0] >> 3) & 0x08));

                *keysched++ = (((desstate_lr[3] << 3) & 0x20)
                             | ((desstate_lr[2] << 4) & 0x10)
                             | ((desstate_lr[2] >> 6) & 0x02)
                             | (desstate_lr[1] & 0x01)
                             | ((desstate_lr[1] >> 1) & 0x04)
                             | ((desstate_lr[0] >> 2) & 0x08));

                *keysched++ = (((desstate_lr[7] >> 2) & 0x01)
                             | ((desstate_lr[6] >> 1) & 0x10)
                             | ((desstate_lr[5] << 2) & 0x04)
                             | ((desstate_lr[5] << 1) & 0x20)
                             | ((desstate_lr[5] >> 6) & 0x02)
                             | ((desstate_lr[4] << 2) & 0x08));

                *keysched++ = (((desstate_lr[7] << 4) & 0x20)
                             | ((desstate_lr[6] >> 2) & 0x01)
                             | ((desstate_lr[6] >> 4) & 0x04)
                             | ((desstate_lr[5] >> 2) & 0x08)
                             | ((desstate_lr[4] << 4) & 0x10)
                             | ((desstate_lr[4] >> 6) & 0x02));

                *keysched++ = (((desstate_lr[2] << 2) & 0x08)
                             | ((desstate_lr[2] >> 5) & 0x02)
                             | ((desstate_lr[1] << 1) & 0x20)
                             | ((desstate_lr[0] << 2) & 0x04)
                             | ((desstate_lr[0] >> 3) & 0x11));

                *keysched++ = (((desstate_lr[3] << 2) & 0x08)
                             | ((desstate_lr[2] >> 1) & 0x04)
                             | (desstate_lr[1] & 0x02)
                             | ((desstate_lr[1] >> 2) & 0x20)
                             | (desstate_lr[0] & 0x10)
                             | ((desstate_lr[0] >> 1) & 0x01));

                *keysched++ = (((desstate_lr[7] << 2) & 0x04)
                             | ((desstate_lr[6] << 3) & 0x08)
                             | ((desstate_lr[6] >> 4) & 0x01)
                             | ((desstate_lr[5] << 3) & 0x10)
                             | (desstate_lr[4] & 0x20)
                             | ((desstate_lr[4] >> 1) & 0x02));

                *keysched++ = (((desstate_lr[7] >> 2) & 0x02)
                             | ((desstate_lr[6] << 2) & 0x08)
                             | ((desstate_lr[6] >> 7) & 0x01)
                             | ((desstate_lr[5] << 1) & 0x10)
                             | ((desstate_lr[5] >> 1) & 0x20)
                             | ((desstate_lr[4] >> 2) & 0x04));
	} while (--round);
}

#endif
