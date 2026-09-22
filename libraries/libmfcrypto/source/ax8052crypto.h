/**
******************************************************************************
* @file ax8052crypto.h
* @brief ax 8052 crypto header
* @internal
* @author   Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a "ON Semiconductor").
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software") and
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

#ifndef AX8052CRYPTO_H
#define AX8052CRYPTO_H

#include <axcompiler.h>

/* X Address Space */

SFRX(AESCONFIG,       0x7091)   /* AES Configuration */
SFRX(AESCURBLOCK,     0x7098)   /* AES Current Block Number */
SFRX(AESINADDR0,      0x7094)   /* AES Input Address Low Byte */
SFRX(AESINADDR1,      0x7095)   /* AES Input Address High Byte */
SFR16LEX(AESINADDR,     0x7094)   /* AES Input Address */
SFRX(AESKEYADDR0,     0x7092)   /* AES Keystream Address Low Byte */
SFRX(AESKEYADDR1,     0x7093)   /* AES Keystream Address High Byte */
SFR16LEX(AESKEYADDR,    0x7092)   /* AES Keystream Address */
SFRX(AESMODE,         0x7090)   /* AES Mode */
SFRX(AESOUTADDR0,     0x7096)   /* AES Output Address Low Byte */
SFRX(AESOUTADDR1,     0x7097)   /* AES Output Address High Byte */
SFR16LEX(AESOUTADDR,    0x7096)   /* AES Output Address */
SFRX(RNGBYTE,         0x7081)   /* True Random Byte */
SFRX(RNGCLKSRC0,      0x7082)   /* True Random Number Generator Clock Source 0 */
SFRX(RNGCLKSRC1,      0x7083)   /* True Random Number Generator Clock Source 1 */
SFRX(RNGMODE,         0x7080)   /* True Random Number Generator Mode */


/* Interrupt Numbers */

#define INT_RNG          19
#define INT_AES          20


#endif /* AX8052CRYPTO_H */
