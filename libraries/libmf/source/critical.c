/**
******************************************************************************
* @file critical.c
* @brief Critical Section non-inline routines
* @internal
* @author   Thomas Sailer
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
* @ingroup LIBMF General
*
* @details
*/

#include "cpu.h"

#if defined __ARMEL__ || defined __ARMEB__

#include <sys/types.h>

typedef uint32_t criticalsection_t;

criticalsection_t enter_critical(void)
{
	criticalsection_t crit = __get_PRIMASK();
	__disable_irq();
	return crit;
}

void exit_critical(criticalsection_t crit)
{

		__set_PRIMASK(crit);
}

void reenter_critical(void)
{
	__disable_irq();
}


#else /* Other than ARM */

#if defined SDCC
#define __reentrantb
#endif

#if defined __CX51__ || defined __C51__
#define __reentrantb
#define __reentrant small reentrant
#endif

#if defined __ICC8051__
#if !defined(__CALLING_CONVENTION__) || __CALLING_CONVENTION__ < 2
#define __reentrantb __idata_reentrant
#else
#define __reentrantb
#endif
#define __reentrant
#endif

typedef unsigned char uint8_t;    /**< \brief C99 unsigned 8bit type */
typedef uint8_t criticalsection_t;

__reentrantb criticalsection_t enter_critical(void) __reentrant
{
	criticalsection_t crit = IE & 0x80;
	EA = 0;
	return crit;
}

__reentrantb void exit_critical(criticalsection_t crit) __reentrant
{
	IE |= crit;
}

__reentrantb void reenter_critical(void) __reentrant
{
	EA = 0;
}

__reentrantb void __disable_irq(void) __reentrant
{
	EA = 0;
}

__reentrantb void __enable_irq(void) __reentrant
{
	EA = 1;
}
#endif
