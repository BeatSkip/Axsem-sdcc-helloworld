/**
******************************************************************************
* @file desdec.c
* @brief DES decryption
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

#include "des.h"

#define ROTATE_LEFT(x)                                                                      \
do {                                                                                        \
	uint8_t t = desstate_lr[(x) + 3];                                                   \
	desstate_lr[(x) + 3] = (desstate_lr[(x) + 3] << 1) | (desstate_lr[(x) + 2] >> 7);   \
	desstate_lr[(x) + 2] = (desstate_lr[(x) + 2] << 1) | (desstate_lr[(x) + 1] >> 7);   \
	desstate_lr[(x) + 1] = (desstate_lr[(x) + 1] << 1) | (desstate_lr[(x) + 0] >> 7);   \
	desstate_lr[(x) + 0] = (desstate_lr[(x) + 0] << 1) | (t >> 7);                      \
} while(0)

#define ROTATE_RIGHT(x)                                                                     \
do {                                                                                        \
	uint8_t t = desstate_lr[(x) + 0];                                                   \
	desstate_lr[(x) + 0] = (desstate_lr[(x) + 0] >> 1) | (desstate_lr[(x) + 1] << 7);   \
	desstate_lr[(x) + 1] = (desstate_lr[(x) + 1] >> 1) | (desstate_lr[(x) + 2] << 7);   \
	desstate_lr[(x) + 2] = (desstate_lr[(x) + 2] >> 1) | (desstate_lr[(x) + 3] << 7);   \
	desstate_lr[(x) + 3] = (desstate_lr[(x) + 3] >> 1) | (t << 7);                      \
} while(0)

#define PERM8(l,r,offs,mask)                                                                \
do {                                                                                        \
	uint8_t t = ((desstate_lr[(l)] >> (offs)) ^ desstate_lr[(r)]) & (mask);             \
	desstate_lr[(r)] ^= t;                                                              \
	desstate_lr[(l)] ^= t << (offs);                                                    \
} while (0)

#define SWAP8(l,r)                                                                          \
do {                                                                                        \
	uint8_t t = desstate_lr[(r)];                                                       \
	desstate_lr[(r)] = desstate_lr[(l)];                                                \
	desstate_lr[(l)] = t;                                                               \
} while (0)

#define DESROUND(from,to,subkey)                                                            \
do {                                                                                        \
	uint8_t s, f;                                                                       \
	uint32_t sk = (subkey)[0];                                                          \
	s = des_sbox[0][(desstate_lr[(from) + 0] ^ *subkey++) & 0x3f];                      \
	desstate_lr[(to) + 0] ^= (s & 0x40);                                                \
	desstate_lr[(to) + 1] ^= (s & 0x10);                                                \
	desstate_lr[(to) + 2] ^= (s & 0x04);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 3] ^= (s & 0x10);                                                \
	s = des_sbox[2][(desstate_lr[(from) + 1] ^ *subkey++) & 0x3f];                      \
	desstate_lr[(to) + 0] ^= (s & 0x10);                                                \
	desstate_lr[(to) + 1] ^= (s & 0x40);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 2] ^= (s & 0x40);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 3] ^= (s & 0x20);                                                \
	s = des_sbox[4][(desstate_lr[(from) + 2] ^ *subkey++) & 0x3f];                      \
	desstate_lr[(to) + 0] ^= (s & 0x81);                                                \
	desstate_lr[(to) + 1] ^= (s & 0x20);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 2] ^= (s & 0x80);                                                \
	s = des_sbox[6][(desstate_lr[(from) + 3] ^ *subkey++) & 0x3f];                      \
	desstate_lr[(to) + 0] ^= (s & 0x20);                                                \
	desstate_lr[(to) + 1] ^= (s & 0x80);                                                \
	desstate_lr[(to) + 2] ^= (s & 0x10);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 3] ^= (s & 0x80);                                                \
	sk = (subkey)[1];                                                                   \
	f = (desstate_lr[(from) + 0] >> 4) | (desstate_lr[(from) + 1] << 4);                \
	s = des_sbox[1][(f ^ *subkey++) & 0x3f];                                            \
	desstate_lr[(to) + 0] ^= (s & 0x02);                                                \
	desstate_lr[(to) + 1] ^= (s & 0x08);                                                \
	desstate_lr[(to) + 2] ^= (s & 0x20);                                                \
	desstate_lr[(to) + 3] ^= (s & 0x04);                                                \
	f = (desstate_lr[(from) + 1] >> 4) | (desstate_lr[(from) + 2] << 4);                \
	s = des_sbox[3][(f ^ *subkey++) & 0x3f];                                            \
	desstate_lr[(to) + 1] ^= (s & 0x01);                                                \
	desstate_lr[(to) + 2] ^= (s & 0x08);                                                \
	desstate_lr[(to) + 3] ^= (s & 0x42);                                                \
	f = (desstate_lr[(from) + 2] >> 4) | (desstate_lr[(from) + 3] << 4);                \
	s = des_sbox[5][(f ^ *subkey++) & 0x3f];                                            \
	desstate_lr[(to) + 0] ^= (s & 0x08);                                                \
	desstate_lr[(to) + 1] ^= (s & 0x02);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 2] ^= (s & 0x02);                                                \
	desstate_lr[(to) + 3] ^= (s & 0x08);                                                \
	f = (desstate_lr[(from) + 3] >> 4) | (desstate_lr[(from) + 0] << 4);                \
	s = des_sbox[7][(f ^ *subkey++) & 0x3f];                                            \
	desstate_lr[(to) + 0] ^= (s & 0x04);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 1] ^= (s & 0x04);                                                \
	desstate_lr[(to) + 2] ^= (s & 0x01);                                                \
	s = (s << 1) | (s >> 7);                                                            \
	desstate_lr[(to) + 3] ^= (s & 0x01);                                                \
} while(0)

void des_decrypt(const uint8_t __xdata *inptr, uint8_t __xdata *outptr, const uint8_t __xdata *keysched, uint8_t nr)
{
#if defined(DES_ASM) && defined(SDCC)
	des_encdec(nr | 0x100, inptr, outptr, keysched);
#else
	uint8_t __autodata desstate_lr[8];
	uint8_t __autodata rnd;
	if (!nr)
		return;
	do {
		desstate_lr[7] = *inptr++;
		desstate_lr[6] = *inptr++;
		desstate_lr[5] = *inptr++;
		desstate_lr[4] = *inptr++;
		desstate_lr[3] = *inptr++;
		desstate_lr[2] = *inptr++;
		desstate_lr[1] = *inptr++;
		desstate_lr[0] = *inptr++;

		// IP
		PERM8(4, 0, 4, 0x0f);
		PERM8(5, 1, 4, 0x0f);
		PERM8(6, 2, 4, 0x0f);
		PERM8(7, 3, 4, 0x0f);

		SWAP8(6, 0);
		SWAP8(7, 1);

		PERM8(0, 4, 2, 0x33);
		PERM8(1, 5, 2, 0x33);
		PERM8(2, 6, 2, 0x33);
		PERM8(3, 7, 2, 0x33);

		SWAP8(1, 4);
		SWAP8(3, 6);

		ROTATE_LEFT(0);

		PERM8(4, 0, 0, 0xaa);
		PERM8(5, 1, 0, 0xaa);
		PERM8(6, 2, 0, 0xaa);
		PERM8(7, 3, 0, 0xaa);

		ROTATE_LEFT(4);

		// Kernel
		keysched += 15 * 8;
		rnd = 8;
		do {
			DESROUND(0, 4, keysched); keysched -= 16; DESROUND(4, 0, keysched); keysched -= 16;
		} while (--rnd);
		keysched += 8;

		// FP
		ROTATE_RIGHT(0);

		PERM8(0, 4, 0, 0xaa);
		PERM8(1, 5, 0, 0xaa);
		PERM8(2, 6, 0, 0xaa);
		PERM8(3, 7, 0, 0xaa);

		ROTATE_RIGHT(4);

		SWAP8(5, 0);
		SWAP8(7, 2);

		PERM8(4, 0, 2, 0x33);
		PERM8(5, 1, 2, 0x33);
		PERM8(6, 2, 2, 0x33);
		PERM8(7, 3, 2, 0x33);

		SWAP8(2, 4);
		SWAP8(3, 5);

		PERM8(0, 4, 4, 0x0f);
		PERM8(1, 5, 4, 0x0f);
		PERM8(2, 6, 4, 0x0f);
		PERM8(3, 7, 4, 0x0f);

		*outptr++ = desstate_lr[3];
		*outptr++ = desstate_lr[2];
		*outptr++ = desstate_lr[1];
		*outptr++ = desstate_lr[0];
		*outptr++ = desstate_lr[7];
		*outptr++ = desstate_lr[6];
		*outptr++ = desstate_lr[5];
		*outptr++ = desstate_lr[4];
	} while (--nr);
#endif
}
