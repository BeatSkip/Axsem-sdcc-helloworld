/**
******************************************************************************
* @file memsetx.c
* @brief Microfoot library string functions
* @internal
* @author   Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a �ON Semiconductor�).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (�ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software�) and
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
* @ingroup LIBMF String
*
* @details
*/

#include "libmfstring.h"

#if defined __ICC8051__

void __genericaddr *memcpy_genericxdata(void __genericaddr *p, const void __xdata *ps, uint16_t l)
{
	uint8_t i = l >> 8;
	uint8_t j = l;
	if (!i && !j)
		return p;
	if (j)
		++i;
	{
		uint8_t __genericaddr *p1 = p;
		const uint8_t __xdata *p2 = ps;
		do {
			do {
				*p1++ = *p2++;
			} while (--j);
		} while (--i);
	}
	return p;
}

#endif
