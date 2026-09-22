/**
******************************************************************************
* @file iowrhex16.c
* @brief Writes 16 bit hexadecimal number on UART
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

#include "wrnum.h"

#include "libmflcd.h"
#define uart_tx(x)           do { lcd_writedata(x); lcd_waitshort(); } while (0)
#define uart_writehex16      lcd_writehex16

#if   defined __ARMEL__ || defined __ARMEB__
#else

__reentrantb uint8_t uart_writehex16(uint16_t val, uint8_t nrdig1, uint8_t flags1) __reentrant
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
				uart_tx(' ');
				if ((flags & WRNUM_TSDSEP) && (cnt == 5)) {
					uart_tx(' ');
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
				uart_tx(ch);
				++nrdig;
			}
		}
		uart_tx('0' + d);
		if ((flags & WRNUM_TSDSEP) && (cnt == 5)) {
			uart_tx('\'');
			++nrdig;
		}
	} while (--cnt);
	return nrdig;
}

#endif
