#include "libaxdsp.h"

#if defined(SDCC)

__reentrantb int32_t fir_xi16_ci16(const int16_t __xdata *p0, const int16_t __code *p1, uint16_t len) __reentrant __naked
{
	__asm
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	a,sp
	add	a,#-5
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	mov	a,r2
	orl	a,r3
	jnz	00000$
	mov	b,a
	mov	dph,a
	mov	dpl,a
	ret
00000$:	push	_DPL1
	push	_DPH1
	inc	r0
	mov	_DPL1,@r0
	inc	r0
	mov	_DPH1,@r0
	clr	a
	mov	r4,a
	mov	r5,a
	mov	r6,a
	mov	r7,a
	inc	r3
00001$:	push	ar3
00002$:	push	ar2
	;; read samples
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	b,_IE
	clr	_EA
	mov	r1,a
	inc	dptr
	inc	_DPS
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	inc	dptr
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	inc	dptr
	dec	_DPS
	mov	_IE,b
	;; multiply
	;; (a - 2^16*as) * (b - 2^16*bs) = a * b - 2^16 * (as * b + bs * a) + 2^32 * as * bs
	;; a0 * b0
	mov	a,r0
	mov	b,r2
	mul	ab
	add	a,r4
	mov	r4,a
	mov	a,b
	addc	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	;; a0 * b1
	mov	a,r0
	mov	b,r3
	mul	ab
	add	a,r5
	mov	r5,a
	mov	a,b
	addc	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	;; a1 * b0
	mov	a,r1
	mov	b,r2
	mul	ab
	add	a,r5
	mov	r5,a
	mov	a,b
	addc	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	;; a1 * b1
	mov	a,r1
	mov	b,r3
	mul	ab
	add	a,r6
	mov	r6,a
	mov	a,b
	addc	a,r7
	mov	r7,a
	;; - 2^16 * (as * b + bs * a)
	mov	a,r1
	jnb	acc.7,00003$
	clr	c
	mov	a,r6
	subb	a,r2
	mov	r6,a
	mov	a,r7
	subb	a,r3
	mov	r7,a
00003$:
	;; - 2^16 * (as * b + bs * a)
	mov	a,r3
	jnb	acc.7,00004$
	clr	c
	mov	a,r6
	subb	a,r0
	mov	r6,a
	mov	a,r7
	subb	a,r1
	mov	r7,a
00004$:
	;; end of loop
	pop	ar2
	djnz	r2,00002$
	pop	ar3
	djnz	r3,00001$
	pop	_DPH1
	pop	_DPL1
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,r7
	ret
	__endasm;
}

#else

__reentrantb int32_t fir_xi16_ci16(const int16_t __xdata *p0, const int16_t __code *p1, uint16_t len) __reentrant
{
	int32_t x = 0;
	for (; len; --len)
		x += (*p0++) * (int32_t)(*p1++);
	return x;
}

#endif
