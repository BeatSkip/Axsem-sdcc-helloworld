/**
******************************************************************************
* @file
* @brief
* @internal
* @author    Thomas Sailer
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
* @ingroup
*
* @details
*/

#ifndef WRNUM_H
#define WRNUM_H

#include "libmftypes.h"

#define WRNUM_MASK    (WRNUM_SIGNED | WRNUM_PLUS | WRNUM_ZEROPLUS | WRNUM_PADZERO | WRNUM_TSDSEP | WRNUM_LCHEX)
#define WRNUM_DIGCONT 0x80
#define WRNUM_DIGSET  0x40

#if defined SDCC
#pragma callee_saves libmf_num16_digit,libmf_num32_digit

extern __reentrantb uint32_t libmf_num32_digit(uint32_t v, uint8_t __auto *dp) __reentrant;
#else
extern uint32_t libmf_num32_digit(uint32_t v, uint8_t __auto *dp);
#endif

extern __reentrantb uint16_t libmf_num16_digit(uint16_t v, uint8_t __auto *dp) __reentrant;

#endif /* WRNUM_H */
