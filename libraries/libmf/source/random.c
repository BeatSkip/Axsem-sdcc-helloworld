/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer
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

#include "libmftypes.h"

__data uint16_t random_seed;

#ifdef SDCC

/**
 * \brief Pseudo Random Number Generator for Channel Access
 *
 */
uint16_t random(void)
{
	__asm
	mov	a,_random_seed
	mov	b,#<28629
	mul	ab
	add	a,#<157
	mov	dpl,a
	mov	a,b
	addc	a,#>157
	mov	dph,a
	mov	a,_random_seed
	mov	b,#>28629
	mul	ab
	add	a,dph
	mov	dph,a
	mov	a,_random_seed+1
	mov	b,#<28629
	mul	ab
	add	a,dph
	mov	dph,a
	mov	_random_seed,dpl
	mov	_random_seed+1,a
	ret
	__endasm;
}

#else

uint16_t random(void)
{
	random_seed = 28629U * random_seed + 157U;
	return random_seed;
}

#endif
