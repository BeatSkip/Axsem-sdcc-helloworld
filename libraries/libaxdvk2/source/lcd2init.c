#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0.h"
#endif
#ifdef __AXM0F2
#include "axm0f2.h"
#endif
#else
#include "ax8052.h"
#endif
#include "libaxlcd2.h"

#include <string.h>

#define WAITSHORT     0x01
#define WAITLONG      0x18
#define STATUSCMDSHORT  (0x40 | WAITSHORT)
#define STATUSCMDLONG   (0x40 | WAITLONG)
#define STATUSCMDDATA   (0xC0 | WAITSHORT)

static volatile uint8_t __data fifotxwr;
static volatile uint8_t __data fifotxrd;

extern uint8_t __xdata lcd2_txbuffer[];

#if !defined(SDCC)
extern const uint8_t __code lcd2_txbuffer_size[];
#endif

#if defined(SDCC)

static __reentrantb uint8_t lcd2_iocore(void) __reentrant __naked;

void lcd2_irq(void) __interrupt(10) __naked
{
	__asm;
	ar2=0x02
	ar3=0x03
	ar4=0x04
	ar5=0x05
	ar6=0x06
	ar7=0x07
	ar0=0x00
	ar1=0x01

	push	acc
	push	psw
	push	_DPS
	push	dpl
	push	dph
	mov	_DPS,#0
	mov	psw,#0
	mov	a,_SPSTATUS
	jnb	acc.0,00000$
	mov	a,_SPSHREG
	lcall	_lcd2_iocore
00000$:	pop	dph
	pop	dpl
	pop	_DPS
	pop	psw
	pop	acc
	reti
	__endasm;
}

__reentrantb uint8_t lcd2_poll(void) __reentrant __naked
{
	__asm;
	mov	a,#0x80
	anl	a,_IE
	mov	b,a
	clr	_EA
	mov	a,_SPSTATUS
	jnb	acc.0,00000$
	mov	a,_SPSHREG
	lcall	_lcd2_iocore
00000$:	mov	a,b
	orl	_IE,a
	ret

	.area	LCD2S0 (CODE)
	.area	LCD2S1 (CODE)

	.area	LCD2S0 (CODE)
	__endasm;
}

static __reentrantb uint8_t lcd2_iocore(void) __reentrant __naked
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

	mov	a,_fifotxrd
	cjne	a,_fifotxwr,00000$
	setb	_PORTC_0
	mov	a,#~0x08
	anl	_SPMODE,a
	mov	dpl,#0x00
	ret
00000$:	add	a,acc
	mov	dptr,#_lcd2_txbuffer
	add	a,dpl
	mov	dpl,a
	clr	a
	addc	a,dph
	mov	dph,a
	movx	a,@dptr
	jnb	acc.6,00001$
	clr	_PORTC_0
	rlc	a
	mov	_PORTB_0,c
	rrc	a
	setb	_PORTB_1
	mov	_SPCLKSRC,#0xD8
	anl	a,#0x3F
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	mov	_SPSHREG,a
00010$:	mov	dpl,#0x00
00011$:	mov	a,#0x08
	orl	_SPMODE,a
	ret
00001$:	setb	_PORTC_0
	mov	_SPCLKSRC,#0xF8
	mov	_SPSHREG,#0x00
	djnz	acc,00002$
	mov	a,#_lcd2_txbuffer_size+2-00012$
	movc	a,@a+pc
00012$:	add	a,_fifotxrd
	jc	00003$
	mov	a,_fifotxrd
	inc	a
00003$:	mov	_fifotxrd,a
	mov	dpl,#0x02
	sjmp	00011$
00002$:	movx	@dptr,a
	sjmp	00010$
	__endasm;
}

__reentrantb void lcd2_txadvance(uint8_t idx) __reentrant __naked
{
	idx;
	__asm;
	mov	a,#_lcd2_txbuffer_size+1-00003$
	movc	a,@a+pc
00003$:	xch	a,dpl
	jz	00000$
	add	a,_fifotxwr
	jnc	00002$
	add	a,dpl
	sjmp	00001$
00002$:	xch	a,dpl
	add	a,dpl
	jc	00001$
	mov	a,dpl
00001$:	mov	_fifotxwr,a
	mov	a,_SPMODE
	jb	acc.3,00000$
	ljmp	_lcd2_iocore
00000$:	ret
	__endasm;
}

__reentrantb uint8_t __xdata *lcd2_txbufptr(uint8_t idx) __reentrant __naked
{
	__asm;
	mov	a,#_lcd2_txbuffer_size+1-00003$
	movc	a,@a+pc
00003$:	xch	a,dpl
	add	a,_fifotxwr
	jnc	00002$
	add	a,dpl
	sjmp	00001$
00002$:	xch	a,dpl
	add	a,dpl
	jc	00001$
	mov	a,dpl
00001$:	add	a,acc
	mov	dptr,#_lcd2_txbuffer
	add	a,dpl
	mov	dpl,a
	clr	a
	addc	a,dph
	mov	dph,a
	ret
	__endasm;
}

__reentrantb uint8_t lcd2_txfreelinear(void) __reentrant __naked
{
	__asm;
	mov	a,_fifotxrd
	setb	c
	subb	a,_fifotxwr
	jnc	00000$
	mov	a,_fifotxrd
	add	a,#0xff
	cpl	c
	mov	a,#_lcd2_txbuffer_size-00001$
	movc	a,@a+pc
00001$:	subb	a,_fifotxwr
00000$:	mov	dpl,a
	ret
	__endasm;
}

__reentrantb uint8_t lcd2_txfree(void) __reentrant __naked
{
	__asm;
	mov	a,_fifotxrd
	setb	c
	subb	a,_fifotxwr
	mov	dpl,a
	jnc	00000$
	mov	a,#_lcd2_txbuffer_size-00001$
	movc	a,@a+pc
00001$:	add	a,dpl
	mov	dpl,a
00000$:	ret
	__endasm;
}

__reentrantb uint8_t lcd2_txbuffersize(void) __reentrant __naked
{
	__asm;
	mov	a,#_lcd2_txbuffer_size-00000$
	movc	a,@a+pc
00000$:	dec	a
	mov	dpl,a
	ret

_lcd2_txbuffer_size:
	.area CSEG    (CODE)
	__endasm;
}

__reentrantb void lcd2_txpokecmd(uint8_t idx, uint16_t cmd) __reentrant __naked
{
	idx;
	cmd;
	__asm;
	push	ar0
	mov	a,sp
	add	a,#-3
	mov	r0,a
	lcall	_lcd2_txbufptr
	mov	a,@r0
	movx	@dptr,a
	dec	r0
	inc	dptr
	mov	a,@r0
	movx	@dptr,a
	pop	ar0
	ret
	__endasm;
}

__reentrantb void lcd2_txpoke(uint8_t idx, uint8_t ch) __reentrant __naked
{
	idx;
	ch;
	__asm;
	push	ar0
	mov	a,sp
	add	a,#-3
	mov	r0,a
_lcd2_txpoke_hexentry:
	lcall	_lcd2_txbufptr
	mov	a,#STATUSCMDDATA
	movx	@dptr,a
	inc	dptr
	mov	a,@r0
	movx	@dptr,a
	pop	ar0
	ret
	__endasm;
}

__reentrantb void lcd2_txpokehex(uint8_t idx, uint8_t ch) __reentrant __naked
{
	idx;
	ch;
	__asm;
	push	ar0
	mov	a,sp
	add	a,#-3
	mov	r0,a
	mov	a,@r0
	anl	a,#0x0F
	add	a,#256-10
	jnc	00000$
	add	a,#'A-'9-1
00000$:	add	a,#10+'0	; '
	mov	@r0,a
	ljmp    _lcd2_txpoke_hexentry
	__endasm;
}

__reentrantb uint8_t lcd2_txidle(void) __reentrant __naked
{
	__asm;
	mov	a,_SPMODE
	swap	a
	rl	a
	cpl	a
	anl	a,#0x01
	mov	dpl,a
	ret
	__endasm;
}

static void wtimer_cansleep_dummy(void) __naked
{
	__asm
	.area WTCANSLP0 (CODE)
	.area WTCANSLP1 (CODE)
	.area WTCANSLP2 (CODE)

	.area WTCANSLP1 (CODE)
	lcall	_lcd2_txidle
	mov	a,dpl
	jnz	00000$
	ret
00000$:
	.area CSEG      (CODE)
	__endasm;
}

#elif defined __CX51__ || defined __C51__

static __reentrantb uint8_t lcd2_iocore(void) __reentrant;

__reentrantb void lcd2_irq(void) interrupt 10
{
#pragma asm
	push	acc
	push	psw
	push	DPS
	push	dpl
	push	dph
	push	ar7
	mov	DPS,#0
	mov	psw,#0
	mov	a,SPSTATUS
	jnb	acc.0,irqnotx
	mov	a,SPSHREG
	lcall	_lcd2_iocore
irqnotx:
	pop	ar7
	pop	dph
	pop	dpl
	pop	DPS
	pop	psw
	pop	acc
#pragma endasm
}

__reentrantb uint8_t lcd2_poll(void) __reentrant
{
#pragma asm
	mov	a,#0x80
	anl	a,IE
	mov	b,a
	clr	EA
	mov	a,SPSTATUS
	jnb	acc.0,pollnotx
	mov	a,SPSHREG
	lcall	_lcd2_iocore
pollnotx:
	mov	a,b
	orl	IE,a
#pragma endasm
}

static __reentrantb uint8_t lcd2_iocore(void) __reentrant
{
#pragma asm
;ar2	equ	0x02
;ar3	equ	0x03
;ar4	equ	0x04
;ar5	equ	0x05
;ar6	equ	0x06
;ar7	equ	0x07
;ar0	equ	0x00
;ar1	equ	0x01

_lcd2_iocore:
	mov	r7,#0x00
	mov	a,fifotxrd
	cjne	a,fifotxwr,iocor0
	setb	PORTC_0
	mov	a,#~0x08
	anl	SPMODE,a
	ret
iocor0:	add	a,acc
	mov	dptr,#lcd2_txbuffer
	add	a,dpl
	mov	dpl,a
	clr	a
	addc	a,dph
	mov	dph,a
	movx	a,@dptr
	jnb	acc.6,iocor1
	clr	PORTC_0
	rlc	a
	mov	PORTB_0,c
	rrc	a
	setb	PORTB_1
	mov	SPCLKSRC,#0xD8
	anl	a,#0x3F
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	mov	SPSHREG,a
	sjmp	iorete
iocor2:	movx	@dptr,a
	sjmp	iorete
iocor1:	setb	PORTC_0
	mov	SPCLKSRC,#0xF8
	mov	SPSHREG,#0x00
	djnz	acc,iocor2
	clr	a
	mov	dptr,#lcd2_txbuffer_size+2
	movc	a,@a+dptr
	add	a,fifotxrd
	jc	iocor3
	mov	a,fifotxrd
	inc	a
iocor3:	mov	fifotxrd,a
	mov	r7,#0x02
iorete:	mov	a,#0x08
	orl	SPMODE,a
	ret
#pragma endasm
}

__reentrantb void lcd2_txadvance(uint8_t idx) __reentrant
{
#pragma asm
	clr	a
	mov	dptr,#lcd2_txbuffer_size+1
	movc	a,@a+dptr
	xch	a,r7
	jz	txad0
	add	a,fifotxwr
	jnc	txad2
	add	a,r7
	sjmp	txad1
txad2:	xch	a,r7
	add	a,r7
	jc	txad1
	mov	a,r7
txad1:	mov	fifotxwr,a
	lcall	_lcd2_iocore
txad0:
#pragma endasm
}

__reentrantb uint8_t __xdata *lcd2_txbufptr(uint8_t idx) __reentrant
{
#pragma asm
_lcd2_txbufptr:
	clr	a
	mov	dptr,#lcd2_txbuffer_size+1
	movc	a,@a+dptr
	xch	a,r7
	add	a,fifotxwr
	jnc	txpc2
	add	a,r7
	sjmp	txpc1
txpc2:	xch	a,r7
	add	a,r7
	jc	txpc1
	mov	a,r7
txpc1:	add	a,acc
	mov	dptr,#lcd2_txbuffer
	add	a,dpl
	mov	r7,a
	clr	a
	addc	a,dph
	mov	r6,a
#pragma endasm
}
	
__reentrantb uint8_t lcd2_txfreelinear(void) __reentrant
{
#pragma asm
	mov	a,fifotxrd
	setb	c
	subb	a,fifotxwr
	jnc	txfrl0
	mov	a,fifotxrd
	add	a,#0xff
	cpl	c
	clr	a
	mov	dptr,#lcd2_txbuffer_size
	movc	a,@a+dptr
	subb	a,fifotxwr
txfrl0:	mov	r7,a
#pragma endasm
}
	
__reentrantb uint8_t lcd2_txfree(void) __reentrant
{
#pragma asm
	mov	a,fifotxrd
	setb	c
	subb	a,fifotxwr
	mov	r7,a
	jnc	txfr0
	clr	a
	mov	dptr,#lcd2_txbuffer_size
	movc	a,@a+dptr
	add	a,r7
	mov	r7,a
txfr0:
#pragma endasm
}

__reentrantb uint8_t lcd2_txbuffersize(void) __reentrant
{
	return lcd2_txbuffer_size[0]-1;
}

__reentrantb void lcd2_txpokecmd(uint8_t idx, uint16_t cmd) __reentrant
{
#pragma asm
	lcall	_lcd2_txbufptr
	mov	dpl,r7
	mov	dph,r6
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
#pragma endasm
}

__reentrantb void lcd2_txpoke(uint8_t idx, uint8_t ch) __reentrant
{
#pragma asm
_lcd2_txpokehex_entry:
	lcall	_lcd2_txbufptr
	mov	dpl,r7
	mov	dph,r6
	mov	a,#STATUSCMDDATA
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
#pragma endasm
}

__reentrantb void lcd2_txpokehex(uint8_t idx, uint8_t ch) __reentrant
{
#pragma asm
	mov	a,r5
	anl	a,#0x0F
	add	a,#256-10
	jnc	txph0
	add	a,#'A'-'9'-1
txph0:	add	a,#10+'0'
	mov	r5,a
	ljmp	_lcd2_txpokehex_entry
#pragma endasm
}

__reentrantb uint8_t lcd2_txidle(void) __reentrant
{
#pragma asm
	mov	a,SPMODE
	swap	a
	rl	a
	cpl	a
	anl	a,#0x01
	mov	r7,a
txnotidle:
#pragma endasm
}

#elif defined __ICC8051__

static __reentrantb uint8_t lcd2_iocore(void) __reentrant __naked;

#pragma vector=0x53
__interrupt void lcd2_irq(void)
{
	if (SPSTATUS & 0x01) {
		SPSHREG;
		lcd2_iocore();
	}
}

__reentrantb uint8_t lcd2_poll(void) __reentrant __naked
{
	uint8_t flg = 0;
	criticalsection_t crit = enter_critical();
	if (SPSTATUS & 0x01) {
		SPSHREG;
		flg = lcd2_iocore();
	}
	exit_critical(crit);
	return flg;
}

static __reentrantb uint8_t lcd2_iocore(void) __reentrant __naked
{
	uint8_t flg = 0;
	if (fifotxrd != fifotxwr) {
		uint8_t rp = fifotxrd + 1;
		uint8_t st = lcd2_txbuffer[fifotxrd << 1];
		if (st & 0x40) {
			PORTC_0 = 0;
			PORTB_0 = (st >> 7) & 1;
			PORTB_1 = 1;
			SPCLKSRC = 0xD8;
			st &= 0x3F;
			lcd2_txbuffer[fifotxrd << 1] = st;
			SPSHREG = lcd2_txbuffer[(fifotxrd << 1) + 1];
		} else {
			PORTC_0 = 1;
			SPCLKSRC = 0xF8;
			SPSHREG = 0x00;
			--st;
			if (!st) {
				uint8_t sz = lcd2_txbuffer_size[0];
				if (rp >= sz)
					rp -= sz;
				fifotxrd = rp;
				flg |= 2;
			} else {
				lcd2_txbuffer[fifotxrd << 1] = st;
			}
		}
		SPMODE |= 0x08;
	} else {
		PORTC_0 = 1;
		SPMODE &= (uint8_t)~0x08;
	}
	return flg;
}

__reentrantb void lcd2_txadvance(uint8_t idx) __reentrant __naked
{
	uint8_t wr;
	uint8_t sz;
	if (!idx)
		return;
	wr = fifotxwr;
	idx += wr;
	sz = lcd2_txbuffer_size[0];
	if (idx < wr || idx >= sz)
		idx -= sz;
	fifotxwr = idx;
	if (!(SPMODE & 0x08))
		lcd2_iocore();
}

__reentrantb uint8_t __xdata *lcd2_txbufptr(uint8_t idx) __reentrant __naked
{
	uint8_t wr = fifotxwr;
	uint8_t sz = lcd2_txbuffer_size[0];
	idx += wr;
	if (idx < wr || idx >= sz)
		idx -= sz;
	idx <<= 1;
	return &lcd2_txbuffer[idx];
}

__reentrantb uint8_t lcd2_txfreelinear(void) __reentrant __naked
{
	uint8_t rd = fifotxrd;
	uint8_t wr = fifotxwr;
	if (rd <= wr) {
		uint8_t r = lcd2_txbuffer_size[0] - wr;
		if (!rd)
			--r;
		return r;
	}
	return rd - wr - 1;
}

__reentrantb uint8_t lcd2_txfree(void) __reentrant __naked
{
	uint8_t rd = fifotxrd;
	uint8_t wr = fifotxwr;
	uint8_t r = rd - wr;
	if (rd <= wr)
		r += lcd2_txbuffer_size[0];
	--r;
	return r;
}

__reentrantb void lcd2_txpokecmd(uint8_t idx, uint16_t cmd) __reentrant __naked
{
	uint8_t __xdata *bp = lcd2_txbufptr(idx);
	*bp++ = cmd >> 8;
	*bp = cmd;
}

__reentrantb void lcd2_txpoke(uint8_t idx, uint8_t ch) __reentrant __naked
{
	uint8_t __xdata *bp = lcd2_txbufptr(idx);
	*bp++ = STATUSCMDDATA;
	*bp = ch;
}

__reentrantb void lcd2_txpokehex(uint8_t idx, uint8_t ch) __reentrant __naked
{
	ch &= 0x0F;
	if (ch >= 10)
		ch += 'A' - '9' - 1;
	ch += '0';
	lcd2_txpoke(idx, ch);
}

__reentrantb uint8_t lcd2_txidle(void) __reentrant __naked
{
	if (!(SPMODE & 0x08))
		return 1;
	return 0;
}

#elif defined __ARMEL__ || defined __ARMEB__

static __reentrantb uint8_t lcd2_iocore(void) __reentrant;

#ifdef __AXM0

void SPI1_Handler(void)
{
	if (SPI1->STS & 0x01) {
		SPI1->DATA;
		lcd2_iocore();
	}
}

__reentrantb uint8_t lcd2_poll(void) __reentrant __naked
{
	uint8_t flg = 0;
	criticalsection_t crit = enter_critical();
	if (SPI1->STS & 0x01) {
		SPI1->DATA;
		flg = lcd2_iocore();
	}
	exit_critical(crit);
	return flg;
}

static __reentrantb uint8_t lcd2_iocore(void) __reentrant __naked
{
	uint8_t flg = 0;
	if (fifotxrd != fifotxwr) {
		uint8_t rp = fifotxrd + 1;
		uint8_t st = lcd2_txbuffer[fifotxrd << 1];
		if (st & 0x40) {
			GPIO_AND->DATA_OUT = ~0x00010000;
			GPIO_XOR->DATA_OUT = (GPIO_XOR->DATA_OUT ^ (((uint32_t)st) << 1)) & 0x00000100;
			GPIO_OR->DATA_OUT = 0x00000200;
			SPI1->CFG = 0x0001D802;
			st &= 0x3F;
			lcd2_txbuffer[fifotxrd << 1] = st;
			SPI1->DATA = lcd2_txbuffer[(fifotxrd << 1) + 1];
		} else {
			GPIO_OR->DATA_OUT = 0x00010000;
			SPI1->CFG = 0x0001F802;
			SPI1->DATA = 0x00;
			--st;
			if (!st) {
				uint8_t sz = lcd2_txbuffer_size[0];
				if (rp >= sz)
					rp -= sz;
				fifotxrd = rp;
				flg |= 2;
			} else {
				lcd2_txbuffer[fifotxrd << 1] = st;
			}
		}
	} else {
		GPIO_OR->DATA_OUT = 0x00010000;
		SPI1_AND->CFG = ~0x00010000;
	}
	return flg;
}

__reentrantb uint8_t lcd2_txidle(void) __reentrant __naked
{
	if (!(SPI1->CFG & 0x00010000))
		return 1;
	return 0;
}

#endif

#ifdef __AXM0F2

void SCB0_Handler(void)
{
	if (SCB0->INTR_RX & 0x00000004) {
		SCB0->RX_FIFO_RD;
		SCB0->INTR_RX = 0x00000004;
		lcd2_iocore();
	}
}

__reentrantb uint8_t lcd2_poll(void) __reentrant __naked
{
	uint8_t flg = 0;
	criticalsection_t crit = enter_critical();
	if (SCB0->INTR_RX & 0x00000004) {
		SCB0->RX_FIFO_RD;
		SCB0->INTR_RX = 0x00000004;
		flg = lcd2_iocore();
	}
	exit_critical(crit);
	return flg;
}

static __reentrantb uint8_t lcd2_iocore(void) __reentrant __naked
{
	uint8_t flg = 0;
	if (fifotxrd != fifotxwr) {
		uint8_t rp = fifotxrd + 1;
		uint8_t st = lcd2_txbuffer[fifotxrd << 1];
		if (st & 0x40) {
			GPIO_PRT0->DR_CLR = 0x00000001; /* SEL = 0 */
			GPIO_PRT4->DR_INV = (GPIO_PRT4->DR ^ (st >> 5)) & 0x00000004; /* RS = st.7 */
			GPIO_PRT4->DR_SET = 0x00000008; /* RST = 1 */
			st &= 0x3F;
			lcd2_txbuffer[fifotxrd << 1] = st;
		        SCB0->TX_FIFO_WR = lcd2_txbuffer[(fifotxrd << 1) + 1];
			lcd2_txbuffer[(fifotxrd << 1) + 1] = 0;
		} else {
			uint8_t div = lcd2_txbuffer[(fifotxrd << 1) + 1];
			GPIO_PRT0->DR_SET = 0x00000001; /* SEL = 1 */
			SCB0->TX_FIFO_WR = 0x00;
			div = (div + 1) & 0x0F;
			lcd2_txbuffer[(fifotxrd << 1) + 1] = div;
			if (!div) {
				--st;
				if (!st) {
					uint8_t sz = lcd2_txbuffer_size[0];
					if (rp >= sz)
						rp -= sz;
					fifotxrd = rp;
					flg |= 2;
				} else {
					lcd2_txbuffer[fifotxrd << 1] = st;
				}
			}
		}
		SCB0->INTR_RX_MASK = 0x00000004;
	} else {
		GPIO_PRT0->DR_SET = 0x00000001; /* SEL = 1 */
		SCB0->INTR_RX_MASK = 0x00000000;
	}
	return flg;
}

__reentrantb uint8_t lcd2_txidle(void) __reentrant __naked
{
	if (!(SCB0->INTR_RX_MASK & 0x00000004))
		return 1;
	return 0;
}

#endif

__reentrantb void lcd2_txadvance(uint8_t idx) __reentrant __naked
{
	uint8_t wr;
	uint8_t sz;
	if (!idx)
		return;
	wr = fifotxwr;
	idx += wr;
	sz = lcd2_txbuffer_size[0];
	if (idx < wr || idx >= sz)
		idx -= sz;
	fifotxwr = idx;
	if (lcd2_txidle())
		lcd2_iocore();
}

__reentrantb uint8_t __xdata *lcd2_txbufptr(uint8_t idx) __reentrant __naked
{
	uint8_t wr = fifotxwr;
	uint8_t sz = lcd2_txbuffer_size[0];
	idx += wr;
	if (idx < wr || idx >= sz)
		idx -= sz;
	idx <<= 1;
	return &lcd2_txbuffer[idx];
}

__reentrantb uint8_t lcd2_txfreelinear(void) __reentrant __naked
{
	uint8_t rd = fifotxrd;
	uint8_t wr = fifotxwr;
	if (rd <= wr) {
		uint8_t r = lcd2_txbuffer_size[0] - wr;
		if (!rd)
			--r;
		return r;
	}
	return rd - wr - 1;
}

__reentrantb uint8_t lcd2_txfree(void) __reentrant __naked
{
	uint8_t rd = fifotxrd;
	uint8_t wr = fifotxwr;
	uint8_t r = rd - wr;
	if (rd <= wr)
		r += lcd2_txbuffer_size[0];
	--r;
	return r;
}

__reentrantb void lcd2_txpokecmd(uint8_t idx, uint16_t cmd) __reentrant __naked
{
	uint8_t __xdata *bp = lcd2_txbufptr(idx);
	*bp++ = cmd >> 8;
	*bp = cmd;
}

__reentrantb void lcd2_txpoke(uint8_t idx, uint8_t ch) __reentrant __naked
{
	uint8_t __xdata *bp = lcd2_txbufptr(idx);
	*bp++ = STATUSCMDDATA;
	*bp = ch;
}

__reentrantb void lcd2_txpokehex(uint8_t idx, uint8_t ch) __reentrant __naked
{
	ch &= 0x0F;
	if (ch >= 10)
		ch += 'A' - '9' - 1;
	ch += '0';
	lcd2_txpoke(idx, ch);
}

#else

#error "Compiler unsupported"

#endif

static const uint8_t __code lcdinitcmd[] = {
	WAITLONG, 0x00,       // Init Display
	STATUSCMDLONG, 0x30,  // wake-up
	STATUSCMDLONG, 0x30,  // wake-up
	STATUSCMDLONG, 0x30,  // wake-up
	STATUSCMDSHORT, 0x39, // function set
	STATUSCMDSHORT, 0x14, // internal osc frequency
	STATUSCMDSHORT, 0x56, // power control
	STATUSCMDSHORT, 0x6d, // follower control
	STATUSCMDSHORT, 0x78, // contrast
	STATUSCMDSHORT, 0x0c, // display on
	STATUSCMDSHORT, 0x06, // entry mode
	STATUSCMDLONG, 0x01, // clear display
	//STATUSCMDSHORT, 0x0f, // display on; cursor on
};

__reentrantb void lcd2_init(void) __reentrant
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	NVIC_DisableIRQ(SPI1_IRQn);
	NVIC_ClearPendingIRQ(SPI1_IRQn);
#endif
#ifdef __AXM0F2
	NVIC_DisableIRQ(SCB0_IRQn);
	NVIC_ClearPendingIRQ(SCB0_IRQn);
#endif
#else
	EIE &= (uint8_t)~0x08;
#endif
	fifotxrd = 0;
	fifotxwr = sizeof(lcdinitcmd)/2;
#if defined(SDCC) || defined(__ICC8051__)
	{
		uint8_t i = sizeof(lcdinitcmd);
		const uint8_t __code *p0 = lcdinitcmd;
		uint8_t __xdata *p1 = lcd2_txbuffer;
		do {
			*p1++ = *p0++;
		} while (--i);
	}
#else
	// memcpy is not reentrant on SDCC
	memcpy(lcd2_txbuffer, lcdinitcmd, sizeof(lcdinitcmd));
#endif
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	GPIO_OR->OUT_EN = 0x00070300;
	GPIO_AND->DATA_OUT = ~0x00040300;
	GPIO_OR->DATA_OUT = 0x00030000;
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_SPI1_EN_Msk | CMU_PCLK_CFG_XBAR_EN_Msk;
	XBAR->IN_SPI1_CFG_b.IN = XBAR_IN_SPI1_CFG_IN_SEL_PB2;
	XBAR->PC_CFG_b.PC0 = 0;
	XBAR->PC_CFG_b.PC1 = 1;
	XBAR->PC_CFG_b.PC2 = 1;
	CMU_AND->PCLK_CFG = ~CMU_PCLK_CFG_XBAR_EN_Msk;
	SPI1->CFG = 0x0000D802;
	{
		uint8_t x = SPI1->DATA;
	}
	NVIC_EnableIRQ(SPI1_IRQn);
#endif
#ifdef __AXM0F2
	GPIO_PRT0->PC = (GPIO_PRT0->PC & ~0x00000007) | 0x00000006;
	GPIO_PRT1->PC = (GPIO_PRT1->PC & ~0x000001C7) | 0x00000186;
	GPIO_PRT4->PC = (GPIO_PRT4->PC & ~0x00000FC0) | 0x00000D80;
	GPIO_PRT4->DR_CLR = 0x0000000C;
	GPIO_PRT0->DR_SET = 0x00000001;
	GPIO_PRT1->DR_SET = 0x00000004;
	GPIO_PRT1->DR_CLR = 0x00000001;
	HSIOM->PORT_SEL0 &= ~0x0000000F;
	HSIOM->PORT_SEL1 |= 0x00000F0F;
	HSIOM->PORT_SEL4 &= ~0x0000FF00;

	PERI->PCLK_CTL0     = 0x00000045;

	/* Configure LCD - SPI interface */
	SCB0->CTRL = (16 - 1) /* oversampling - 3 MHz clock speed */ | 0x01000800;
	SCB0->SPI_CTRL = 0x8000000D;

	/* Configure RX direction */
	SCB0->RX_CTRL = 0x80000107;
	SCB0->RX_FIFO_CTRL = 0x00010007;
	SCB0->RX_FIFO_CTRL = 0x00000007;

	/* Configure TX direction */
	SCB0->TX_CTRL = 0x80000107;
	SCB0->TX_FIFO_CTRL = 0x00010000;
	SCB0->TX_FIFO_CTRL = 0x00000000;

	/* Configure interrupt sources */
	SCB0->INTR_I2C_EC_MASK = 0;
	SCB0->INTR_SPI_EC_MASK = 0;
	SCB0->INTR_S_MASK = 0;
	SCB0->INTR_M_MASK = 0;
	SCB0->INTR_RX_MASK = 0;
	SCB0->INTR_TX_MASK = 0;

	/* Enable */
	SCB0->CTRL |= 0x80000000;
	NVIC_EnableIRQ(SCB0_IRQn);
#endif
#else
	DIRB |= 0x03;
	PORTB &= (uint8_t)~0x03; // PB1=0: assert reset
	DIRC |= 0x07;
	PORTC |= 0x03;
	PORTC &= (uint8_t)~0x04;
	SPCLKSRC = 0xD8;
	SPMODE = 0x01;
	{
		uint8_t x = SPSHREG;
	}
	EIE |= 0x08;
#endif
	lcd2_iocore();
}

__reentrantb void lcd2_portinit(void) __reentrant
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	NVIC_DisableIRQ(SPI1_IRQn);
	NVIC_ClearPendingIRQ(SPI1_IRQn);
	fifotxrd = fifotxwr = 0;
	GPIO_OR->OUT_EN = 0x00070300;
	GPIO_AND->DATA_OUT = ~0x00040100;
	GPIO_OR->DATA_OUT = 0x00030200;
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_SPI1_EN_Msk | CMU_PCLK_CFG_XBAR_EN_Msk;
	XBAR->IN_SPI1_CFG_b.IN = XBAR_IN_SPI1_CFG_IN_SEL_PC1;
	XBAR->PC_CFG_b.PC0 = 1;
	XBAR->PC_CFG_b.PC1 = 1;
	XBAR->PC_CFG_b.PC2 = 1;
	CMU_AND->PCLK_CFG = ~CMU_PCLK_CFG_XBAR_EN_Msk;
	SPI1->CFG = 0x0000D802;
	{
		uint8_t x = SPI1->DATA;
	}
	NVIC_EnableIRQ(SPI1_IRQn);
#endif
#ifdef __AXM0F2
	NVIC_DisableIRQ(SCB0_IRQn);
	NVIC_ClearPendingIRQ(SCB0_IRQn);
	fifotxrd = fifotxwr = 0;
	/*
	 * P0[0] SEL   scb[0].select1
	 * P1[0] MOSI  scb[0].mosi
	 * P1[2] SCK   scb[0].sck
	 * P4[2] RS
	 * P4[3] RST
	 */
	GPIO_PRT0->PC = (GPIO_PRT0->PC & ~0x00000007) | 0x00000006;
	GPIO_PRT1->PC = (GPIO_PRT1->PC & ~0x000001C7) | 0x00000186;
	GPIO_PRT4->PC = (GPIO_PRT4->PC & ~0x00000FC0) | 0x00000D80;
	GPIO_PRT4->DR_CLR = 0x00000004;
	GPIO_PRT4->DR_SET = 0x00000008;
	GPIO_PRT0->DR_SET = 0x00000001;
	GPIO_PRT1->DR_SET = 0x00000004;
	GPIO_PRT1->DR_CLR = 0x00000001;
	HSIOM->PORT_SEL0 &= ~0x0000000F;
	HSIOM->PORT_SEL1 |= 0x00000F0F;
	HSIOM->PORT_SEL4 &= ~0x0000FF00;

	PERI->PCLK_CTL0     = 0x00000045;

	/* Configure LCD - SPI interface */
	SCB0->CTRL = (16 - 1) /* oversampling - 3 MHz clock speed */ | 0x01000800;
	SCB0->SPI_CTRL = 0x8000000D;

	/* Configure RX direction */
	SCB0->RX_CTRL = 0x80000107;
	SCB0->RX_FIFO_CTRL = 0x00010007;
	SCB0->RX_FIFO_CTRL = 0x00000007;

	/* Configure TX direction */
	SCB0->TX_CTRL = 0x80000107;
	SCB0->TX_FIFO_CTRL = 0x00010000;
	SCB0->TX_FIFO_CTRL = 0x00000000;

	/* Configure interrupt sources */
	SCB0->INTR_I2C_EC_MASK = 0;
	SCB0->INTR_SPI_EC_MASK = 0;
	SCB0->INTR_S_MASK = 0;
	SCB0->INTR_M_MASK = 0;
	SCB0->INTR_RX_MASK = 0;
	SCB0->INTR_TX_MASK = 0;

	/* Enable */
	SCB0->CTRL |= 0x80000000;
	NVIC_EnableIRQ(SCB0_IRQn);
#endif
#else
	EIE &= (uint8_t)~0x08;
	fifotxrd = fifotxwr = 0;
	/*
	 * PB0: RS
	 * PB1: RST
	 * PC0: SEL
	 * PC1: SCK
	 * PC2: MOSI
	 */
	DIRB |= 0x03;
	PORTB &= (uint8_t)~0x01;
	PORTB_1 = 1;
	DIRC |= 0x07;
	PORTC |= 0x03;
	PORTC &= (uint8_t)~0x04;
	SPCLKSRC = 0xD8;
	SPMODE = 0x01;
	{
		uint8_t x = SPSHREG;
	}
	EIE |= 0x08;
#endif
}
