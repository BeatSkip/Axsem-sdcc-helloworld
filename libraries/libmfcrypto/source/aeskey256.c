/**
******************************************************************************
* @file aeskey256.c
* @brief AES256 algorithm
* @internal
* @author   Thomas Sailer, Prakash Rajendran
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

#include "ax8052crypto.h"
#include "aes.h"
#include <string.h>

void aes256_setup(const uint8_t key[32], uint8_t __xdata *keyschedule)
{
	memcpy((void *)keyschedule, key, 32);
	aes_keyexp(keyschedule, 8, 14);
	AESCONFIG = (AESCONFIG & 0xC0) | 14;
	AESKEYADDR0 = (uint16_t)keyschedule;
	AESKEYADDR1 = ((uint16_t)keyschedule) >> 8;
}
