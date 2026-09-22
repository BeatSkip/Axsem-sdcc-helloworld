#include "libaxlcd2.h"

#define WAITSHORT     0x01
#define WAITLONG      0x18
#define STATUSCMDSHORT  (0x40 | WAITSHORT)
#define STATUSCMDLONG   (0x40 | WAITLONG)
#define STATUSCMDDATA   (0xC0 | WAITSHORT)

#if defined(SDCC)

__reentrantb void lcd2_writestr(const char __genericaddr *ch) __reentrant
{
	ch;
	__asm;
	mov	r0,dpl
	mov	r7,dph
	clr	a
	mov	r3,a
	mov	r2,a
00000$:	jb	_B_7,00010$		; >0x80 code
	jnb	_B_6,00011$		; <0x40 far
	jb	_B_5,00012$		; >0x60 pdata
	;; idata
	mov	a,@r0
	inc	r0
	sjmp	00013$
00010$: ;; code
	mov	dpl,r0
	mov	dph,r7
	clr	a
	movc	a,@a+dptr
	inc	dptr
	mov	r0,dpl
	mov	r7,dph
	sjmp	00013$
00011$:	;; xdata
	mov	dpl,r0
	mov	dph,r7
	movx	a,@dptr
	inc	dptr
	mov	r0,dpl
	mov	r7,dph
	sjmp	00013$
00012$:	;; pdata
	movx	a,@r0
	inc	r0
00013$:	jz	00001$
	mov	r1,a
	mov	a,r3
	jnz	00002$
	mov	a,r2
	jz	00003$
	mov	dpl,a
	lcall	_lcd2_txadvance
00003$:	lcall	_lcd2_txfreelinear
	mov	a,dpl
	jnz	00004$
	mov	r4,b
	mov	dpl,#1
	lcall	_lcd2_wait_txfree
	mov	b,r4
	lcall	_lcd2_txfreelinear
	mov	a,dpl
00004$:	mov	r3,a
	clr	a
	mov	r2,a
	mov	dpl,a
	lcall	_lcd2_txbufptr
	mov	r4,dpl
	mov	r5,dph
00002$:	mov	dpl,r4
	mov	dph,r5
	cjne	r1,#10,00020$
	mov	a,#STATUSCMDSHORT
	movx	@dptr,a
	inc	dptr
	mov	a,#0xc0
	sjmp	00021$
00020$:	mov	a,#STATUSCMDDATA
	movx	@dptr,a
	inc	dptr
	mov	a,r1
00021$:	movx	@dptr,a
	inc	dptr
	mov	r4,dpl
	mov	r5,dph
	inc	r2
	dec	r3
	sjmp	00000$
00001$:	mov	a,r2
	jz	00005$
	mov	dpl,a
	lcall	_lcd2_txadvance
00005$:
	__endasm;
}

#else

__reentrantb void lcd2_writestr(const char __genericaddr *ch) __reentrant
{
	uint8_t __xdata *p;
	uint8_t f = 0;
	uint8_t a = 0;
	for (;;) {
		char c = *ch++;
		if (!c)
			break;
		if (!f) {
			if (a)
				lcd2_txadvance(a);
			f = lcd2_txfreelinear();
			if (!f) {
				lcd2_wait_txfree(1);
				f = lcd2_txfreelinear();
			}
			p = lcd2_txbufptr(0);
			a = 0;
		}
		if (c == '\n') {
			*p++ = STATUSCMDSHORT;
			*p++ = 0xc0;
		} else {
			*p++ = STATUSCMDDATA;
			*p++ = c;
		}
		++a;
		--f;
	}
	if (a)
		lcd2_txadvance(a);
}

#endif
