#include "libaxdsp.h"

#if STAGES==2
#define cordic16_vec cordic16_vec2
#define _cordic16_core_vec _cordic16_core_vec2
#elif STAGES==3
#define cordic16_vec cordic16_vec3
#define _cordic16_core_vec _cordic16_core_vec3
#elif STAGES==4
#define cordic16_vec cordic16_vec4
#define _cordic16_core_vec _cordic16_core_vec4
#elif STAGES==5
#define cordic16_vec cordic16_vec5
#define _cordic16_core_vec _cordic16_core_vec5
#elif STAGES==6
#define cordic16_vec cordic16_vec6
#define _cordic16_core_vec _cordic16_core_vec6
#elif STAGES==7
#define cordic16_vec cordic16_vec7
#define _cordic16_core_vec _cordic16_core_vec7
#elif STAGES==8
#define cordic16_vec cordic16_vec8
#define _cordic16_core_vec _cordic16_core_vec8
#elif STAGES==9
#define cordic16_vec cordic16_vec9
#define _cordic16_core_vec _cordic16_core_vec9
#elif STAGES==10
#define cordic16_vec cordic16_vec10
#define _cordic16_core_vec _cordic16_core_vec10
#elif STAGES==11
#define cordic16_vec cordic16_vec11
#define _cordic16_core_vec _cordic16_core_vec11
#elif STAGES==12
#define cordic16_vec cordic16_vec12
#define _cordic16_core_vec _cordic16_core_vec12
#elif STAGES==13
#define cordic16_vec cordic16_vec13
#define _cordic16_core_vec _cordic16_core_vec13
#elif STAGES==14
#define cordic16_vec cordic16_vec14
#define _cordic16_core_vec _cordic16_core_vec14
#elif STAGES==15
#define cordic16_vec cordic16_vec15
#define _cordic16_core_vec _cordic16_core_vec15
#else
#error "invalid STAGES value"
#endif

#if defined(SDCC)

__reentrantb void cordic16_vec(struct cordic16 *c) __reentrant
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
	lcall	_cordic16_core_vec
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
	lcall	_cordic16_core_vec
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
	lcall	_cordic16_core_vec
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
		if (y < 0) {			\
			x -= yy;		\
			y += xx;		\
			p -= (pinc);		\
		} else {			\
			x += yy;		\
			y -= xx;		\
			p += (pinc);		\
		}				\
	} while (0)

__reentrantb void cordic16_vec(struct cordic16 *c) __reentrant
{
	int16_t x = c->x;
	int16_t y = c->y;
	uint16_t p = c->p;
	if (x < 0) {
		x = -x;
		y = -y;
		p ^= 0x8000;
	}
#if STAGES>=0
	STAGE(0,0x2000);
#endif
#if STAGES>=1
	STAGE(1,0x12E4);
#endif
#if STAGES>=2
	STAGE(2,0x09FB);
#endif
#if STAGES>=3
	STAGE(3,0x0511);
#endif
#if STAGES>=4
	STAGE(4,0x028B);
#endif
#if STAGES>=5
	STAGE(5,0x0146);
#endif
#if STAGES>=6
	STAGE(6,0x00A3);
#endif
#if STAGES>=7
	STAGE(7,0x0051);
#endif
#if STAGES>=8
	STAGE(8,0x0029);
#endif
#if STAGES>=9
	STAGE(9,0x0014);
#endif
#if STAGES>=10
	STAGE(10,0x000A);
#endif
#if STAGES>=11
	STAGE(11,0x0005);
#endif
#if STAGES>=12
	STAGE(12,0x0003);
#endif
#if STAGES>=13
	STAGE(13,0x0001);
#endif
#if STAGES>=14
	STAGE(14,0x0001);
#endif
#if STAGES>=15
	STAGE(15,0x0000);
#endif
	c->x = x;
	c->y = y;
	c->p = p;
}

#endif
