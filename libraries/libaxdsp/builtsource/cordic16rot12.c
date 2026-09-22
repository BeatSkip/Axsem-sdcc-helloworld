#include "libaxdsp.h"

#define cordic16_rot cordic16_rot12
#define _cordic16_core_rot _cordic16_core_rot12

#if defined(SDCC)

__reentrantb void cordic16_rot(struct cordic16 *c) __reentrant
{
	__asm
	jb	_B_7,codeptr$		; >0x80 code
	jnb	_B_6,xdataptr$		; <0x40 far
	mov	r0,dpl
	jb	_B_5,pdataptr$		; >0x60 pdata
	push	ar0
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	lcall	_cordic16_core_rot
	pop	ar0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,dpl
	inc	r0
	mov	@r0,dph
codeptr$:
	ret
pdataptr$:
	push	ar0
	movx	a,@r0
	mov	r2,a
	inc	r0
	movx	a,@r0
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r4,a
	inc	r0
	movx	a,@r0
	mov	r5,a
	inc	r0
	movx	a,@r0
	mov	dpl,a
	inc	r0
	movx	a,@r0
	mov	dph,a
	lcall	_cordic16_core_rot
	pop	ar0
	mov	a,r2
	movx	@r0,a
	inc	r0
	mov	a,r3
	movx	@r0,a
	inc	r0
	mov	a,r4
	movx	@r0,a
	inc	r0
	mov	a,r5
	movx	@r0,a
	inc	r0
	mov	a,dpl
	movx	@r0,a
	inc	r0
	mov	a,dph
	movx	@r0,a
	ret
xdataptr$:
	push	dpl
	push	dph
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	dph,a
	mov	dpl,r0
	lcall	_cordic16_core_rot
	mov	r0,dpl
	mov	r1,dph
	pop	dph
	pop	dpl
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	ret	
	__endasm;
}

#else

// dec2hex(round(arg(1+i*2.^-(0:15))/2/pi*2^16))
// 0x2000, 0x12E4, 0x09FB, 0x0511, 0x028B, 0x0146, 0x00A3, 0x0051
// 0x0029, 0x0014, 0x000A, 0x0005, 0x0003, 0x0001, 0x0001, 0x0000

#define STAGE(s,pinc)				\
	do {					\
		int16_t xx = x >> (s);		\
		int16_t yy = y >> (s);		\
		if (!(p & 0x8000)) {		\
			x -= yy;		\
			y += xx;		\
			p -= (pinc);		\
		} else {			\
			x += yy;		\
			y -= xx;		\
			p += (pinc);		\
		}				\
	} while (0)

__reentrantb void cordic16_rot(struct cordic16 *c) __reentrant
{
	int16_t x = c->x;
	int16_t y = c->y;
	uint16_t p = c->p;
	if ((p ^ (p << 1)) & 0x8000) {
		x = -x;
		y = -y;
		p ^= 0x8000;
	}
	STAGE(0,0x2000);
	STAGE(1,0x12E4);
	STAGE(2,0x09FB);
	STAGE(3,0x0511);
	STAGE(4,0x028B);
	STAGE(5,0x0146);
	STAGE(6,0x00A3);
	STAGE(7,0x0051);
	STAGE(8,0x0029);
	STAGE(9,0x0014);
	STAGE(10,0x000A);
	STAGE(11,0x0005);
	STAGE(12,0x0003);
	c->x = x;
	c->y = y;
	c->p = p;
}

#endif
