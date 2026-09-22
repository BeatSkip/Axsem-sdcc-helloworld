/**
******************************************************************************
* @file axm0_uart.c
* @brief UART buffer size definitions
* @internal
* @author   Thomas Sailer, Pradeep Kumar G R
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
* @ingroup UART
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__

#include "libmfuart.h"
#include "wrnum.h"
#include "axm0_uart.h"

const uint8_t __xdata *axm0_uart_rxbufptr(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint16_t sz = *(uart_desc->rxbuffersize);
	uint16_t rd = fifoptr->rxrd;
	idx += rd;
	if (idx < rd || idx >= sz)
		idx -= sz;
	return &uart_desc->rxbuffer[idx];
}

uint8_t __xdata *axm0_uart_txbufptr(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint16_t sz = *(uart_desc->txbuffersize);
	uint16_t wr = fifoptr->txwr;
	idx += wr;
	if (idx < wr || idx >= sz)
		idx -= sz;
	return &uart_desc->txbuffer[idx];
}

uint8_t axm0_uart_txfreelinear(const struct uart_descriptor *uart_desc)
{
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint16_t sz = *(uart_desc->txbuffersize);
	uint16_t rd = fifoptr->txrd;
	uint16_t wr = fifoptr->txwr;
	if (rd <= wr) {
		uint16_t r = sz - wr;
		if (!rd)
			--r;
		return r;
	}
	return rd - wr - 1;
}

uint8_t axm0_uart_txfree(const struct uart_descriptor *uart_desc)
{
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint16_t sz = *(uart_desc->txbuffersize);
	uint16_t read  = fifoptr->txrd;
	uint16_t write = fifoptr->txwr;
	uint16_t free  = read - write;
	if (read <= write)
		free += sz;
	--free;
	return free;
}

uint8_t axm0_uart_rxcountlinear(const struct uart_descriptor *uart_desc)
{
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint16_t sz = *(uart_desc->rxbuffersize);
	uint16_t rd = fifoptr->rxrd;
	uint16_t wr = fifoptr->rxwr;
	if (wr < rd)
		return sz - rd;
	return wr - rd;
}

uint8_t axm0_uart_rxcount(const struct uart_descriptor *uart_desc)
{
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint16_t sz = *(uart_desc->rxbuffersize);
	uint8_t rd = fifoptr->rxrd;
	uint8_t wr = fifoptr->rxwr;
	uint8_t r = wr - rd;
	if (wr < rd)
		r += sz;
	return r;
}

uint8_t axm0_uart_txbuffersize(const struct uart_descriptor *uart_desc)
{
	return *(uart_desc->txbuffersize) - 1;
}

uint8_t axm0_uart_rxbuffersize(const struct uart_descriptor *uart_desc)
{
	return *(uart_desc->rxbuffersize) - 1;
}

uint8_t axm0_uart_rxpeek(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	const uint8_t __xdata *bp = axm0_uart_rxbufptr(uart_desc, idx);
	return *bp;
}

void axm0_uart_txpoke(const struct uart_descriptor *uart_desc, uint8_t idx, uint8_t ch)
{
	uint8_t __xdata *bp = axm0_uart_txbufptr(uart_desc, idx);
	*bp = ch;
}

void axm0_uart_txpokehex(const struct uart_descriptor *uart_desc, uint8_t idx, uint8_t ch)
{
	ch &= 0x0F;
	if (ch >= 10)
		ch += 'A' - '9' - 1;
	ch += '0';
	axm0_uart_txpoke(uart_desc, idx, ch);
}

void axm0_uart_wait_txfree(const struct uart_descriptor *uart_desc, uint8_t v)
{
	uint32_t temp_primask = __get_PRIMASK();
	for (;;) {
		__set_PRIMASK(1);
		if (axm0_uart_txfree(uart_desc) >= v)
			break;
		if (!axm0_uart_poll(uart_desc)) {
			wtimer_standby();
		}
		__set_PRIMASK(temp_primask);
	}
	__set_PRIMASK(temp_primask);
}

void axm0_uart_wait_txdone(const struct uart_descriptor *uart_desc)
{
	uint32_t temp_primask = __get_PRIMASK();
	for (;;) {
		uint8_t b;
		__set_PRIMASK(1);
		b = axm0_uart_txbusy(uart_desc);
		if (!b)
			break;
		if (!axm0_uart_poll(uart_desc) && b & 2)
			wtimer_standby();
 		__set_PRIMASK(temp_primask);
	}
	__set_PRIMASK(temp_primask);
}

void axm0_uart_tx(const struct uart_descriptor *uart_desc, uint8_t v)
{
	axm0_uart_wait_txfree(uart_desc, 1);
	axm0_uart_txpoke(uart_desc, 0, v);
	axm0_uart_txadvance(uart_desc, 1);
}

void axm0_uart_wait_rxcount(const struct uart_descriptor *uart_desc, uint8_t v)
{
	uint32_t temp_primask = __get_PRIMASK();
	for (;;) {
		__set_PRIMASK(1);
		if (axm0_uart_rxcount(uart_desc) >= v)
			break;
		if (!axm0_uart_poll(uart_desc))
			wtimer_standby();
		__set_PRIMASK(temp_primask);
	}
	__set_PRIMASK(temp_primask);
}

uint8_t axm0_uart_rx(const struct uart_descriptor *uart_desc)
{
	uint8_t x;
	axm0_uart_wait_rxcount(uart_desc, 1);
	x = axm0_uart_rxpeek(uart_desc, 0);
	axm0_uart_rxadvance(uart_desc, 1);
	return x;
}

void axm0_uart_writestr(const struct uart_descriptor *uart_desc, const char *ch)
{
	uint8_t __xdata *p;
	uint8_t f = 0;
	uint8_t a = 0;
	for(;;) {
		char c = *ch++;
		if (!c)
			break;
     		if (!f) {
			if(a)
				axm0_uart_txadvance(uart_desc, a);
          		f = axm0_uart_txfreelinear(uart_desc);
			if (!f) {
				axm0_uart_wait_txfree(uart_desc, 1);
				f = axm0_uart_txfreelinear(uart_desc);
			}
			p = axm0_uart_txbufptr(uart_desc, 0);
			a = 0;
		}
		*p++ = c;
		++a;
		--f;
	}
	if (a)
		axm0_uart_txadvance(uart_desc, a);
}

uint8_t axm0_uart_writehex16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig1, uint8_t flags1)
{
	char ch = 0;
	uint8_t d;
	uint8_t cnt = 4;
	uint8_t flags = flags1;
	uint8_t nrdig = nrdig1;

	if ((flags & WRNUM_SIGNED) && (int32_t)val < 0) {
		val = -val;
		ch = '-';
	} else if ((flags & WRNUM_ZEROPLUS) || ((flags & WRNUM_PLUS) && val)) {
		ch = '+';
	}
	if (ch && nrdig > 0)
		--nrdig;
	if (flags & WRNUM_TSDSEP) {
		if (nrdig > 4)
			--nrdig;
	}
	flags &= WRNUM_MASK;
	if (cnt < nrdig)
		cnt = nrdig;
	do {
		d = val >> (4 * (cnt - 1));
		d &= 0x0F;
		if (d >= 10) {
			if (flags & WRNUM_LCHEX)
				d += 'a' - '9' - 1;
			else
				d += 'A' - '9' - 1;
		}
		if (!d && cnt != 1 && !(flags & WRNUM_DIGCONT)) {
			if (cnt > nrdig)
				continue;
			if (!(flags & WRNUM_PADZERO)) {
				if (!(flags & WRNUM_DIGSET)) {
					nrdig = cnt;
					flags |= WRNUM_DIGSET;
				}
				axm0_uart_tx(uart_desc, ' ');
				if ((flags & WRNUM_TSDSEP) && (cnt == 5)) {
					axm0_uart_tx(uart_desc, ' ');
					++nrdig;
				}
				continue;
			}
		}
		if (!(flags & WRNUM_DIGCONT)) {
			if (!(flags & WRNUM_DIGSET))
				nrdig = cnt;
			flags |= WRNUM_PADZERO | WRNUM_DIGCONT | WRNUM_DIGSET;
			if (ch) {
				axm0_uart_tx(uart_desc, ch);
				++nrdig;
			}
		}
		axm0_uart_tx(uart_desc, '0' + d);
		if ((flags & WRNUM_TSDSEP) && (cnt == 5)) {
			axm0_uart_tx(uart_desc, '\'');
			++nrdig;
		}
	} while (--cnt);
	return nrdig;
}

uint8_t axm0_uart_writehex32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig1, uint8_t flags1)
{
	char __autodata ch = 0;
	uint8_t __autodata d;
	uint8_t __autodata cnt = 8;
	uint8_t __autodata flags = flags1;
	uint8_t __autodata nrdig = nrdig1;

	if ((flags & WRNUM_SIGNED) && (int32_t)val < 0) {
		val = -val;
		ch = '-';
	} else if ((flags & WRNUM_ZEROPLUS) || ((flags & WRNUM_PLUS) && val)) {
		ch = '+';
	}
	if (ch && nrdig > 0)
		--nrdig;
	if (flags & WRNUM_TSDSEP) {
		if (nrdig > 4)
			--nrdig;
	}
	flags &= WRNUM_MASK;
	if (cnt < nrdig)
		cnt = nrdig;
	do {
		d = val >> (4 * (cnt - 1));
		d &= 0x0F;
		if (d >= 10) {
			if (flags & WRNUM_LCHEX)
				d += 'a' - '9' - 1;
			else
				d += 'A' - '9' - 1;
		}
		if (!d && cnt != 1 && !(flags & WRNUM_DIGCONT)) {
			if (cnt > nrdig)
				continue;
			if (!(flags & WRNUM_PADZERO)) {
				if (!(flags & WRNUM_DIGSET)) {
					nrdig = cnt;
					flags |= WRNUM_DIGSET;
				}
				axm0_uart_tx(uart_desc, ' ');
				if ((flags & WRNUM_TSDSEP) && (cnt == 5)) {
					axm0_uart_tx(uart_desc, ' ');
					++nrdig;
				}
				continue;
			}
		}
		if (!(flags & WRNUM_DIGCONT)) {
			if (!(flags & WRNUM_DIGSET))
				nrdig = cnt;
			flags |= WRNUM_PADZERO | WRNUM_DIGCONT | WRNUM_DIGSET;
			if (ch) {
				axm0_uart_tx(uart_desc, ch);
				++nrdig;
			}
		}
		axm0_uart_tx(uart_desc, '0' + d);
		if ((flags & WRNUM_TSDSEP) && (cnt == 5)) {
			axm0_uart_tx(uart_desc, '\'');
			++nrdig;
		}
	} while (--cnt);
	return nrdig;
}

void axm0_uart_writehexu16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig)
{
	uint8_t nrdig1 = nrdig;
	uint8_t digit = nrdig1;
	axm0_uart_wait_txfree(uart_desc, nrdig);
       	while (digit) {
		--digit;
		axm0_uart_txpokehex(uart_desc, digit, val);
		val >>= 4;
	}
	axm0_uart_txadvance(uart_desc, nrdig1);
}

void axm0_uart_writehexu32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig)
{
	uint8_t __autodata nrdig1 = nrdig;
	uint8_t __autodata digit = nrdig1;
	axm0_uart_wait_txfree(uart_desc, nrdig1);
	while (digit) {
		--digit;
		axm0_uart_txpokehex(uart_desc, digit, val);
		val >>= 4;
	}
	axm0_uart_txadvance(uart_desc, nrdig1);
}

uint8_t axm0_uart_writenum16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig1, uint8_t flags1)
{
	char ch = 0;
	uint8_t d;
	uint8_t cnt = 5;
	uint8_t flags = flags1;
	uint8_t nrdig = nrdig1;

	if ((flags & WRNUM_SIGNED) && (int16_t)val < 0) {
		val = -val;
		ch = '-';
	} else if ((flags & WRNUM_ZEROPLUS) || ((flags & WRNUM_PLUS) && val)) {
		ch = '+';
	}
	if (ch && nrdig > 0)
		--nrdig;
	if (flags & WRNUM_TSDSEP) {
		if (nrdig > 3)
			--nrdig;
	}
	flags &= WRNUM_MASK;
	if (cnt < nrdig)
		cnt = nrdig;
	do {
		d = cnt;
		val = libmf_num16_digit(val, (uint8_t __auto *)&d);
		if (!d && cnt != 1 && !(flags & WRNUM_DIGCONT)) {
			if (cnt > nrdig)
				continue;
			if (!(flags & WRNUM_PADZERO)) {
				if (!(flags & WRNUM_DIGSET)) {
					nrdig = cnt;
					flags |= WRNUM_DIGSET;
				}
				axm0_uart_tx(uart_desc, ' ');
				if ((flags & WRNUM_TSDSEP) && (cnt == 4)) {
					axm0_uart_tx(uart_desc, ' ');
					++nrdig;
				}
				continue;
			}
		}
		if (!(flags & WRNUM_DIGCONT)) {
			if (!(flags & WRNUM_DIGSET))
				nrdig = cnt;
			flags |= WRNUM_PADZERO | WRNUM_DIGCONT | WRNUM_DIGSET;
			if (ch) {
				axm0_uart_tx(uart_desc, ch);
				++nrdig;
			}
		}
		axm0_uart_tx(uart_desc, '0' + d);
		if ((flags & WRNUM_TSDSEP) && (cnt == 4)) {
			axm0_uart_tx(uart_desc, '\'');
			++nrdig;
		}
	} while (--cnt);
	return nrdig;
}

uint8_t axm0_uart_writenum32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig1, uint8_t flags1)
{
	char __autodata ch = 0;
	uint8_t __autodata d;
	uint8_t __autodata cnt = 10;
	uint8_t __autodata flags = flags1;
	uint8_t __autodata nrdig = nrdig1;

	if ((flags & WRNUM_SIGNED) && ((int32_t)val) < 0) {
		val = -val;
		ch = '-';
	} else if ((flags & WRNUM_ZEROPLUS) || ((flags & WRNUM_PLUS) && val)) {
		ch = '+';
	}
	if (ch && nrdig > 0)
		--nrdig;
	if (flags & WRNUM_TSDSEP) {
		if (nrdig > 9)
			--nrdig;
		if (nrdig > 6)
			--nrdig;
		if (nrdig > 3)
			--nrdig;
	}
	flags &= WRNUM_MASK;
	if (cnt < nrdig)
		cnt = nrdig;
	do {
		d = cnt;
		val = libmf_num32_digit(val, (uint8_t __auto *)&d);
		if (!d && cnt != 1 && !(flags & WRNUM_DIGCONT)) {
			if (cnt > nrdig)
				continue;
			if (!(flags & WRNUM_PADZERO)) {
				if (!(flags & WRNUM_DIGSET)) {
					nrdig = cnt;
					flags |= WRNUM_DIGSET;
				}
				axm0_uart_tx(uart_desc, ' ');
				if ((flags & WRNUM_TSDSEP) && (cnt == 4 || cnt == 7 || cnt == 10)) {
					axm0_uart_tx(uart_desc, ' ');
					++nrdig;
				}
				continue;
			}
		}
		if (!(flags & WRNUM_DIGCONT)) {
			if (!(flags & WRNUM_DIGSET))
				nrdig = cnt;
			flags |= WRNUM_PADZERO | WRNUM_DIGCONT | WRNUM_DIGSET;
			if (ch) {
				axm0_uart_tx(uart_desc, ch);
				++nrdig;
			}
		}
		axm0_uart_tx(uart_desc, '0' + d);
		if ((flags & WRNUM_TSDSEP) && (cnt == 4 || cnt == 7 || cnt == 10)) {
			axm0_uart_tx(uart_desc, '\'');
			++nrdig;
		}
	} while (--cnt);
	return nrdig;
}

#ifdef __AXM0

uint8_t axm0_uart_poll(const struct uart_descriptor *uart_desc)
{
	uint8_t flag;
	uint32_t temp_primask = __get_PRIMASK();
	__set_PRIMASK(1); /* Mask all interrupts */
	flag = axm0_uart_iocore(uart_desc);
	__set_PRIMASK(temp_primask); /* Restore interrupt priority mask */
	return flag;
}

uint8_t axm0_uart_iocore(const struct uart_descriptor *uart_desc)
{
	UART_Type *uart = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint8_t flg = 0;
	if (uart->STS_b.RX_FULL) {
		uint16_t sz = *(uart_desc->rxbuffersize);
		uint16_t wp = fifoptr->rxwr + 1;
		if (wp >= sz)
			wp -= sz;
		if (wp != fifoptr->rxrd) {
			uart_desc->rxbuffer[fifoptr->rxwr] = uart->DATA;
			fifoptr->rxwr = wp;
			uart->CFG_b.INT_EN_RX = 1;
			flg |= 1;
		} else {
			uart->CFG_b.INT_EN_RX = 0;
		}
	}
	if (uart->STS_b.TX_EMPTY)	{
		if (fifoptr->txrd != fifoptr->txwr) {
			uint16_t sz = *(uart_desc->txbuffersize);
			uint16_t rp = fifoptr->txrd + 1;
			uart->DATA = uart_desc->txbuffer[fifoptr->txrd];
			if (rp >= sz)
				rp -= sz;
			fifoptr->txrd = rp;
			uart->CFG_b.INT_EN_TX = 1;
			flg |= 2;
		} else {
			uart->CFG_b.INT_EN_TX = 0;
		}
	}
	return flg;
}

void axm0_uart_rxadvance(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	uint16_t rd, sz;
	if (!idx)
		return;
	UART_Type *uart = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	rd = fifoptr->rxrd;
	idx += rd;
	sz = *(uart_desc->rxbuffersize);
	if (idx < rd || idx >= sz)
		idx -= sz;
	fifoptr->rxrd = idx;
	uart->CFG_b.INT_EN_RX = 1;
}

void axm0_uart_txadvance(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	uint16_t wr, sz;
	if (!idx)
		return;
	UART_Type *uart = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	wr = fifoptr->txwr;
	idx += wr;
	sz = *(uart_desc->txbuffersize);
	if (idx < wr || idx >= sz)
		idx -= sz;
	fifoptr->txwr = idx;
	uart->CFG_b.INT_EN_TX = 1;
}

uint8_t axm0_uart_txidle(const struct uart_descriptor *uart_desc)
{
	UART_Type *uart = uart_desc->membase;
	uint32_t cfg = uart->CFG;
	if (!(cfg & 0x00000200))
		return 1;
	if ((cfg & 0x00000800) || !(uart->STS & 0x00000040))
		return 0;
	return 1;
}

uint8_t axm0_uart_txbusy(const struct uart_descriptor *uart_desc)
{
	UART_Type *uart = uart_desc->membase;
	uint32_t cfg = uart->CFG;
	if (!(cfg & 0x00000200))
		return 0;
	if (cfg & 0x00000800)
		return 3;
	if (!(uart->STS & 0x00000040))
		return 1;
	return 0;
}

void axm0_uart_init(const struct uart_descriptor *uart_desc, uint8_t timernr, uint8_t wl, uint8_t stop)
{
	UART_Type *uart = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint8_t data_flush;

	/* Disable UART interrupt */
	NVIC_DisableIRQ(uart_desc->irqnum);

	/* Initialize FIFO pointers */
	fifoptr->txwr = fifoptr->txrd = fifoptr->rxwr = fifoptr->rxrd = 0;

	uart->CFG             = 0x0;          /* Reset config register */

	uart->CFG_b.BRG 	    = timernr + 1;  /* Set baud rate generator */
	uart->CFG_b.WORD_LEN  = wl;           /* Set word length */
	uart->CFG_b.STOP_BITS = stop >> 1;    /* Set number of stop bit(s) */

	uart->CFG_b.RX_EN     = 1;            /* Enable receiver */
	uart->CFG_b.TX_EN     = 1;            /* Enable transmitter */
	uart->CFG_b.INT_EN_RX = 1;            /* Enable Rx interrupt */
	uart->CFG_b.INT_EN_TX = 1;            /* Enable tx interrupt */

	uart->STS             = 0xFFFFFFFF;   /* Clear status */

	/* Clear UART interrupt if any */
	NVIC_ClearPendingIRQ(uart_desc->irqnum);

	data_flush = uart->DATA; /* Flush data if any */

	/* Enable UART interrupt */
	NVIC_EnableIRQ(uart_desc->irqnum);
}

void axm0_uart_stop(const struct uart_descriptor *uart_desc)
{
	UART_Type *uart = uart_desc->membase;

	/* Disable UART interrupt */
	NVIC_DisableIRQ(uart_desc->irqnum);

	uart->CFG_b.BRG         = 0;
	uart->CFG_b.INT_EN_RX   = 0;
	uart->CFG_b.INT_EN_TX   = 0;

	uart->CFG_b.RX_EN       = 0;
	uart->CFG_b.TX_EN       = 0;
}

__reentrantb void axm0_uart_writeu16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig) __reentrant
{
	uint8_t nrdig1 = nrdig;
	uint8_t digit = nrdig1;
	axm0_uart_wait_txfree(uart_desc, nrdig1);
	while (digit) {
		uint8_t v1 = val;
		val /= 10;
		v1 -= 10 * (uint8_t)val;
		--digit;
		axm0_uart_txpoke(uart_desc, digit, '0' + v1);
	}
	axm0_uart_txadvance(uart_desc, nrdig1);
}

void axm0_uart_writeu32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig)
{
	uint8_t __autodata nrdig1 = nrdig;
	uint8_t __autodata digit = nrdig1;
	axm0_uart_wait_txfree(uart_desc, nrdig1);
	while (digit) {
		uint8_t __autodata v1 = val;
		val /= 10;
		v1 -= 10 * (uint8_t)val;
		--digit;
		axm0_uart_txpoke(uart_desc, digit, '0' + v1);
	}
	axm0_uart_txadvance(uart_desc, nrdig1);
}

#endif

#ifdef __AXM0F2

uint8_t axm0_uart_poll(const struct uart_descriptor *uart_desc)
{
	uint8_t flag;
	uint32_t temp_primask = __get_PRIMASK();
	__set_PRIMASK(1); /* Mask all interrupts */
	flag = axm0_uart_iocore(uart_desc);
	__set_PRIMASK(temp_primask); /* Restore interrupt priority mask */
	return flag;
}

uint8_t axm0_uart_iocore(const struct uart_descriptor *uart_desc)
{
	SCB0_Type *scb = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	uint8_t flg = 0;
	uint32_t fifocount = scb->RX_FIFO_STATUS & AXM0F2_SCB_FIFO_STAT_USED_MASK;
	if (fifocount) {
		uint16_t sz = *(uart_desc->rxbuffersize);
		for (; fifocount > 0; --fifocount) {
			uint16_t wp = fifoptr->rxwr + 1;
			if (wp >= sz)
				wp -= sz;
			if (wp == fifoptr->rxrd)
				break;
			uart_desc->rxbuffer[fifoptr->rxwr] = scb->RX_FIFO_RD;
			fifoptr->rxwr = wp;
			flg |= 1;
		}
		if (!fifocount) {
			scb->INTR_RX = AXM0F2_SCB_INTR_RX_NOT_EMPTY_MASK;
			scb->INTR_RX_MASK |= AXM0F2_SCB_INTR_RX_NOT_EMPTY_MASK;
		} else {
			scb->INTR_RX_MASK &= ~AXM0F2_SCB_INTR_RX_NOT_EMPTY_MASK;
		}
	}
	fifocount = scb->TX_FIFO_STATUS & AXM0F2_SCB_FIFO_STAT_USED_MASK;
	if (fifocount < 8) {
		fifocount = 8 - fifocount;
		uint16_t sz = *(uart_desc->txbuffersize);
		for (; fifocount > 0; --fifocount) {
			if (fifoptr->txrd == fifoptr->txwr)
				break;
			uint16_t rp = fifoptr->txrd;
			scb->TX_FIFO_WR = uart_desc->txbuffer[rp];
			++rp;
			if (rp >= sz)
				rp -= sz;
			fifoptr->txrd = rp;
			flg |= 2;
		}
		if (!fifocount) {
			scb->INTR_TX = AXM0F2_SCB_INTR_TX_NOT_FULL_MASK;
			scb->INTR_TX_MASK |= AXM0F2_SCB_INTR_TX_NOT_FULL_MASK;
		} else {
			scb->INTR_TX_MASK &= ~AXM0F2_SCB_INTR_TX_NOT_FULL_MASK;
		}
	}
	return flg;
}

void axm0_uart_rxadvance(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	uint16_t rd, sz;
	if (!idx)
		return;
	SCB0_Type *scb = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	rd = fifoptr->rxrd;
	idx += rd;
	sz = *(uart_desc->rxbuffersize);
	if (idx < rd || idx >= sz)
		idx -= sz;
	fifoptr->rxrd = idx;
	scb->INTR_RX_MASK |= AXM0F2_SCB_INTR_RX_NOT_EMPTY_MASK;
}

void axm0_uart_txadvance(const struct uart_descriptor *uart_desc, uint8_t idx)
{
	uint16_t wr, sz;
	if (!idx)
		return;
	SCB0_Type *scb = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;
	wr = fifoptr->txwr;
	idx += wr;
	sz = *(uart_desc->txbuffersize);
	if (idx < wr || idx >= sz)
		idx -= sz;
	fifoptr->txwr = idx;
	scb->INTR_TX_MASK |= AXM0F2_SCB_INTR_TX_NOT_FULL_MASK;
}

uint8_t axm0_uart_txidle(const struct uart_descriptor *uart_desc)
{
	SCB0_Type *scb = uart_desc->membase;
	if (!(scb->CTRL & (AXM0F2_UART_CTRL_SCB_EN << AXM0F2_UART_CTRL_SCB_EN_BIT_POS)))
		return 1;
	if (scb->TX_FIFO_STATUS & (AXM0F2_SCB_FIFO_STAT_USED_MASK | AXM0F2_SCB_FIFO_STAT_SR_VALID_MASK))
		return 0;
	if (scb->INTR_TX_MASK & AXM0F2_SCB_INTR_TX_NOT_FULL_MASK)
		return 0;
	return 1;
}

uint8_t axm0_uart_txbusy(const struct uart_descriptor *uart_desc)
{
	SCB0_Type *scb = uart_desc->membase;
	if (!(scb->CTRL & (AXM0F2_UART_CTRL_SCB_EN << AXM0F2_UART_CTRL_SCB_EN_BIT_POS)))
		return 0;
	if (scb->INTR_TX_MASK & AXM0F2_SCB_INTR_TX_NOT_FULL_MASK)
		return 3;
	uint32_t txfifostat = scb->TX_FIFO_STATUS;
	if (txfifostat & AXM0F2_SCB_FIFO_STAT_USED_MASK)
		return 3;
	if (txfifostat & AXM0F2_SCB_FIFO_STAT_SR_VALID_MASK)
		return 1;
        return 0;
}

void axm0_uart_init(const struct uart_descriptor *uart_desc, uint8_t timernr, uint8_t wl, uint8_t stop)
{
	SCB0_Type *scb = uart_desc->membase;
	struct uart_fifo_pointers *fifoptr = uart_desc->fifoptr;

	if (timernr < 6) {
		timernr |= 0x40;
	} else if (timernr < 9) {
		timernr -= 6;
		timernr |= 0x80;
	} else {
		timernr = 0xff;
	}

	/* Disable UART interrupt */
	NVIC_DisableIRQ(uart_desc->irqnum);

	/* Initialize FIFO pointers */
	fifoptr->txwr = fifoptr->txrd = fifoptr->rxwr = fifoptr->rxrd = 0;

	if (scb == (SCB0_Type*)SCB2) {
		/* SCB2 - UART1 - TX ->P0.5, Rx->0.4 */

		/* TX P0.5 to high, Rx P0.4 to low */
		SET_BIT_FIELDS(GPIO_PRT0->DR,
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART1_TX_PIN) |
				(AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART1_RX_PIN)),
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART1_TX_PIN) |
				(AXM0F2_GPIO_PIN_DIS << AXM0F2_GPIO_SCB2_UART1_RX_PIN)));

		/* P0.5 DM 6 - Strong PU/PD, P0.4 DM 1 - input */
		SET_BIT_FIELDS(GPIO_PRT0->PC,
			       ((AXM0F2_GPIO_PORT_PC_DM_MASK << AXM0F2_GPIO_PORT_PC_DM_UART1_TX_POS) |
				(AXM0F2_GPIO_PORT_PC_DM_MASK << AXM0F2_GPIO_PORT_PC_DM_UART1_RX_POS)),
			       ((AXM0F2_GPIO_PORT_PC_DM_UART_TX << AXM0F2_GPIO_PORT_PC_DM_UART1_TX_POS) |
				(AXM0F2_GPIO_PORT_PC_DM_UART_RX << AXM0F2_GPIO_PORT_PC_DM_UART1_RX_POS)));

		/* Input buffer disable P0.5:1, P0.4:0 */
		SET_BIT_FIELDS(GPIO_PRT0->PC2,
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART1_TX_PIN) |
				(AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART1_RX_PIN)),
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART1_TX_PIN) |
				(AXM0F2_GPIO_PIN_DIS << AXM0F2_GPIO_SCB2_UART1_RX_PIN)));

		/* HSIOM P0.4 and P0.5 mapped to SCB2 */
		SET_BIT_FIELDS(HSIOM->PORT_SEL0,
			       ((AXM0F2_HSIOM_PORT_SEL_MASK << AXM0F2_HSIOM_PORT_SEL_UART1_TX) |
				(AXM0F2_HSIOM_PORT_SEL_MASK << AXM0F2_HSIOM_PORT_SEL_UART1_RX)),
			       ((AXM0F2_HSIOM_PORT_SEL_UART1 << AXM0F2_HSIOM_PORT_SEL_UART1_TX) |
				(AXM0F2_HSIOM_PORT_SEL_UART1 << AXM0F2_HSIOM_PORT_SEL_UART1_RX)));

		/* Initialize Timer number (aka which DIV_16_CTLx) */
		PERI->PCLK_CTL2 = timernr;
	} else {
		/* SCB0 UART - TX ->P4.1, Rx->4.0 */

		/* TX P4.1 to high, Rx P4.0 to low */
		SET_BIT_FIELDS(GPIO_PRT4->DR,
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART0_TX_PIN) |
				(AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART0_RX_PIN)),
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART0_TX_PIN) |
				(AXM0F2_GPIO_PIN_DIS << AXM0F2_GPIO_SCB2_UART0_RX_PIN)));

		/* P4.1 DM 6 - Strong PU/PD, P4.0 DM 1 - input */
		SET_BIT_FIELDS(GPIO_PRT4->PC,
			       ((AXM0F2_GPIO_PORT_PC_DM_MASK << AXM0F2_GPIO_PORT_PC_DM_UART0_TX_POS) |
				(AXM0F2_GPIO_PORT_PC_DM_MASK << AXM0F2_GPIO_PORT_PC_DM_UART0_RX_POS)),
			       ((AXM0F2_GPIO_PORT_PC_DM_UART_TX << AXM0F2_GPIO_PORT_PC_DM_UART0_TX_POS) |
				(AXM0F2_GPIO_PORT_PC_DM_UART_RX << AXM0F2_GPIO_PORT_PC_DM_UART0_RX_POS)));

		/* Input buffer disable P4.1:1, P4.0:0 */
		SET_BIT_FIELDS(GPIO_PRT4->PC2,
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART0_TX_PIN) |
				(AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART0_RX_PIN)),
			       ((AXM0F2_GPIO_PIN_EN << AXM0F2_GPIO_SCB2_UART0_TX_PIN) |
				(AXM0F2_GPIO_PIN_DIS << AXM0F2_GPIO_SCB2_UART0_RX_PIN)));

		/* HSIOM P4.1 and P4.0 mapped to SCB0 */
		SET_BIT_FIELDS(HSIOM->PORT_SEL4,
			       ((AXM0F2_HSIOM_PORT_SEL_MASK << AXM0F2_HSIOM_PORT_SEL_UART0_TX) |
				(AXM0F2_HSIOM_PORT_SEL_MASK << AXM0F2_HSIOM_PORT_SEL_UART0_RX)),
			       ((AXM0F2_HSIOM_PORT_SEL_UART0 << AXM0F2_HSIOM_PORT_SEL_UART0_TX) |
				(AXM0F2_HSIOM_PORT_SEL_UART0 << AXM0F2_HSIOM_PORT_SEL_UART0_RX)));

		/* Initialize Timer number (aka which DIV_16_CTLx) */
		PERI->PCLK_CTL0 = timernr;
	}

	stop = ((stop << 1) - 1); /* Convert user requested stop bit(s) to chip specified bit value */

	/* SCB Mode: UART, Set OVS   */
	scb->CTRL              = ((AXM0F2_UART_CTRL_SCB_MODE_UART << AXM0F2_UART_CTRL_SCB_MODE_BIT_POS) |
				  (AXM0F2_UART_CTRL_OVS << AXM0F2_UART_CTRL_OVS_BIT_POS));
	scb->UART_CTRL         = (AXM0F2_UART_CTRL_STD_MODE_EN << AXM0F2_UART_CTRL_STD_MODE_BIT_POS);    /* UART std mode */
	scb->UART_RX_CTRL      = ((AXM0F2_UART_CTRL_PARITY_OFF << AXM0F2_UART_CTRL_PARITY_BIT_POS) |
				  (stop << AXM0F2_UART_CTRL_STOP_BIT_POS));                              /* No parity, user stop bits */
	scb->RX_CTRL           = ((wl - 1) << AXM0F2_UART_CTRL_DATA_LEN_BIT_POS);                        /* MSB first, user data width */
	scb->RX_FIFO_CTRL      = ((AXM0F2_UART_CTRL_RCV_TRGLEV << AXM0F2_UART_CTRL_RCV_TRGLEV_BIT_POS) | /* Receiver trigger level 7 */
				  (1 << AXM0F2_UART_CTRL_FIFOCLEAR_BIT_POS));                            /* Clear FIFO */
	scb->UART_TX_CTRL      = (stop << AXM0F2_UART_CTRL_STOP_BIT_POS);                                /* User stop bit */
	scb->TX_CTRL           = ((wl - 1) << AXM0F2_UART_CTRL_DATA_LEN_BIT_POS);                        /* MSB first, 8 bit data */
	scb->TX_FIFO_CTRL      = (1 << AXM0F2_UART_CTRL_FIFOCLEAR_BIT_POS);                              /* Transmitter trigger level 0, clear FIFO */

	/* Disable which are not required for UART */
	scb->UART_FLOW_CTRL    = 0;
	scb->INTR_I2C_EC_MASK  = 0;
	scb->INTR_SPI_EC_MASK  = 0;
	scb->INTR_S_MASK       = 0;
	scb->INTR_M_MASK       = 0;
	scb->INTR_RX_MASK      = AXM0F2_SCB_INTR_RX_NOT_EMPTY_MASK;
	scb->INTR_TX_MASK      = 0;

	/* End Flushing FIFOs */
	scb->RX_FIFO_CTRL      &= ~(1 << AXM0F2_UART_CTRL_FIFOCLEAR_BIT_POS);
	scb->TX_FIFO_CTRL      &= ~(1 << AXM0F2_UART_CTRL_FIFOCLEAR_BIT_POS);

	/* Enable SCB */
	scb->CTRL              |= (AXM0F2_UART_CTRL_SCB_EN << AXM0F2_UART_CTRL_SCB_EN_BIT_POS);

	/* Clear UART interrupt if any */
	NVIC_ClearPendingIRQ(uart_desc->irqnum);

	/* Enable UART interrupt */
	NVIC_EnableIRQ(uart_desc->irqnum);

}

void axm0_uart_stop(const struct uart_descriptor *uart_desc)
{
	SCB0_Type *scb = uart_desc->membase;

	/* Disable UART interrupt */
	NVIC_DisableIRQ(uart_desc->irqnum);

	/* Disable SCB */
	scb->CTRL              &= ~(AXM0F2_UART_CTRL_SCB_EN << AXM0F2_UART_CTRL_SCB_EN_BIT_POS);
}

__reentrantb void axm0_uart_writeu16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig) __reentrant
{
	uint8_t nrdig1 = nrdig;
	uint8_t digit = nrdig1;
	axm0_uart_wait_txfree(uart_desc, nrdig1);
	while (digit) {
		uint8_t v1 = val;
		val /= 10;
		v1 -= 10 * (uint8_t)val;
		--digit;
		axm0_uart_txpoke(uart_desc, digit, '0' + v1);
	}
	axm0_uart_txadvance(uart_desc, nrdig1);
}

void axm0_uart_writeu32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig)
{
	uint8_t __autodata nrdig1 = nrdig;
	uint8_t __autodata digit = nrdig1;
	axm0_uart_wait_txfree(uart_desc, nrdig1);
	while (digit) {
		uint8_t __autodata v1 = val;
		val /= 10;
		v1 -= 10 * (uint8_t)val;
		--digit;
		axm0_uart_txpoke(uart_desc, digit, '0' + v1);
	}
	axm0_uart_txadvance(uart_desc, nrdig1);
}
#endif

#endif /* defined __ARMEL__ || defined __ARMEB__ */
