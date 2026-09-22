/**
******************************************************************************
* @file libmfaes.h
* @brief AES API header
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

#ifndef LIBMFAES_H
#define LIBMFAES_H

#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

extern enum aes_mode{
	AES_KEYSIZE_128 = 0x00,
	AES_KEYSIZE_192 = 0x01,
	AES_KEYSIZE_256 = 0x02,
	AES_BLOCKMODE_ECB = 0x00,
	AES_BLOCKMODE_CFB = 0x10,
	AES_BLOCKMODE_OFB = 0x20,
	AES_BLOCKMODE_CBC = 0x30,
	AES_ECB_128  = AES_KEYSIZE_128 | AES_BLOCKMODE_ECB,
	AES_ECB_192  = AES_KEYSIZE_192 | AES_BLOCKMODE_ECB,
	AES_ECB_256  = AES_KEYSIZE_256 | AES_BLOCKMODE_ECB,
	AES_CFB_128  = AES_KEYSIZE_128 | AES_BLOCKMODE_CFB,
	AES_CFB_192  = AES_KEYSIZE_192 | AES_BLOCKMODE_CFB,
	AES_CFB_256  = AES_KEYSIZE_256 | AES_BLOCKMODE_CFB,
	AES_OFB_128  = AES_KEYSIZE_128 | AES_BLOCKMODE_OFB,
	AES_OFB_192  = AES_KEYSIZE_192 | AES_BLOCKMODE_OFB,
	AES_OFB_256  = AES_KEYSIZE_256 | AES_BLOCKMODE_OFB,
	AES_CBC_128  = AES_KEYSIZE_128 | AES_BLOCKMODE_CBC,
	AES_CBC_192  = AES_KEYSIZE_192 | AES_BLOCKMODE_CBC,
	AES_CBC_256  = AES_KEYSIZE_256 | AES_BLOCKMODE_CBC
};

extern void aes_setup(const uint8_t *key, uint8_t __xdata *keyschedule, uint8_t flag);

uint32_t aes_encrypt(uint8_t __xdata *pdata, uint8_t __xdata *cdata, uint32_t block_len, uint8_t __xdata *keyschedule, uint8_t flag);

uint32_t aes_decrypt(uint8_t __xdata *cdata, uint8_t __xdata *pdata, uint32_t block_len, uint8_t __xdata *keyschedule, uint8_t flag);

#endif /* __AXM0F2 */

#else /* Other than ARM */
/*
 * AES Setup (generates key schedule, sets up AESCONFIG and AESKEYADDR registers
 */
extern void aes128_setup(const uint8_t key[16], uint8_t __xdata *keyschedule); /* keyschedule size 176 */
extern void aes192_setup(const uint8_t key[24], uint8_t __xdata *keyschedule); /* keyschedule size 208 */
extern void aes256_setup(const uint8_t key[32], uint8_t __xdata *keyschedule); /* keyschedule size 240 */

#endif /* defined __ARMEL__ || defined __ARMEB__ */

/*
 * AES Key Schedule Expansion
 */
extern void aes_keyexp(uint8_t __xdata *keysched, uint8_t Nk, uint8_t Nr);

#endif /* LIBMFAES_H */
