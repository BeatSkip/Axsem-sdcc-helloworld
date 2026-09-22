#ifndef LIBAXLCD2_H
#define LIBAXLCD2_H

#include "libmftypes.h"

/*
 * LCD
 */
#if defined SDCC

#define LCD2_DEFINE_TXBUFFER(sz)                                \
static void lcd2_define_txbuffer(void) __naked                  \
{                                                               \
	__asm                                                   \
	.area XSEG    (XDATA)                                   \
	.globl  _lcd2_txbuffer                                  \
_lcd2_txbuffer:                                                 \
	.ds	2*(sz)                                          \
                                                                \
	.area LCD2S0 (CODE)                                     \
	.area LCD2S1 (CODE)                                     \
                                                                \
	.area LCD2S1 (CODE)                                     \
	.db	sz                                              \
	.db	256-sz                                          \
	.db	257-sz                                          \
                                                                \
	.area CSEG    (CODE)                                    \
	__endasm;                                               \
}

#elif defined __CX51__ || defined __C51__

#define LCD2_DEFINE_TXBUFFER(sz)                                \
uint8_t __xdata lcd2_txbuffer[2*(sz)];                          \
const uint8_t __code lcd2_txbuffer_size[] = { sz, 256-(sz), 257-(sz) };

#else

#define LCD2_DEFINE_TXBUFFER(sz)                                \
uint8_t __xdata lcd2_txbuffer[2*(sz)];                          \
const uint8_t __code lcd2_txbuffer_size[] = { sz };

#endif

#if defined SDCC
#pragma callee_saves lcd2_txbufptr,lcd2_txfreelinear
#pragma callee_saves lcd2_txfree,lcd2_txbuffersize,lcd2_wait_txfree,lcd2_txpokecmd,lcd2_txpoke,lcd2_txpokehex
#pragma callee_saves lcd2_init,lcd2_poll,lcd2_wait_txfree,lcd2_tx,lcd2_txcmdshort,lcd2_txcmdlong
extern __reentrantb void lcd2_irq(void) __interrupt(10) __naked;
#elif defined __CX51__ || defined __C51__
#elif defined __ICC8051__
#elif defined __ARMEL__ || defined __ARMEB__
#else
#error "Compiler unsupported"
#endif

extern __reentrantb uint8_t lcd2_poll(void) __reentrant __naked;
extern __reentrantb uint8_t __xdata *lcd2_txbufptr(uint8_t idx) __reentrant __naked;
extern __reentrantb uint8_t lcd2_txfreelinear(void) __reentrant __naked;
extern __reentrantb uint8_t lcd2_txidle(void) __reentrant __naked;
extern __reentrantb uint8_t lcd2_txfree(void) __reentrant __naked;
extern __reentrantb uint8_t lcd2_txbuffersize(void) __reentrant __naked;
extern __reentrantb void lcd2_txpokecmd(uint8_t idx, uint16_t cmd) __reentrant __naked;
extern __reentrantb void lcd2_txpoke(uint8_t idx, uint8_t ch) __reentrant __naked;
extern __reentrantb void lcd2_txpokehex(uint8_t idx, uint8_t ch) __reentrant __naked;
extern __reentrantb void lcd2_txadvance(uint8_t idx) __reentrant __naked;

extern __reentrantb void lcd2_init(void) __reentrant;
extern __reentrantb void lcd2_portinit(void) __reentrant;
extern __reentrantb void lcd2_wait_txdone(void) __reentrant;
extern __reentrantb void lcd2_wait_txfree(uint8_t v) __reentrant;
extern __reentrantb void lcd2_tx(uint8_t v) __reentrant;
extern __reentrantb void lcd2_txcmdshort(uint8_t v) __reentrant;
extern __reentrantb void lcd2_txcmdlong(uint8_t v) __reentrant;
extern __reentrantb void lcd2_setpos(uint8_t v) __reentrant;
extern __reentrantb void lcd2_cleardisplay(void) __reentrant;
extern __reentrantb void lcd2_clear(uint8_t pos, uint8_t len) __reentrant;
extern __reentrantb void lcd2_writestr(const char __genericaddr *ch) __reentrant;
extern __reentrantb uint8_t lcd2_writenum16(uint16_t val, uint8_t nrdig, uint8_t flags) __reentrant;
extern __reentrantb uint8_t lcd2_writehex16(uint16_t val, uint8_t nrdig, uint8_t flags) __reentrant;
#if defined(SDCC)
extern __reentrantb uint8_t lcd2_writenum32(uint32_t val, uint8_t nrdig, uint8_t flags) __reentrant;
extern __reentrantb uint8_t lcd2_writehex32(uint32_t val, uint8_t nrdig, uint8_t flags) __reentrant;
#else
extern uint8_t lcd2_writenum32(uint32_t val, uint8_t nrdig, uint8_t flags);
extern uint8_t lcd2_writehex32(uint32_t val, uint8_t nrdig, uint8_t flags);
#endif

#endif /* LIBAXLCD2_H */
