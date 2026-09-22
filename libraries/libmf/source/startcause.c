/**
******************************************************************************
* @file sleep.c
* @brief PMU hibernate mode APIs
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
* @ingroup pmu
*
* @details
*/

#include "cpu.h"
#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/**
 * \brief return the reason for the startup
 *
 */
__reentrantb uint8_t get_startcause(void) __reentrant
{
	uint32_t st = PMU->STS;
	if (st & 0x00000004)
		return STARTCAUSE_WAKEUPSLEEP;
	if (st & 0x00000002)
		return STARTCAUSE_WAKEUPDEEPSLEEP;
	if (st & 0x00000001)
		return STARTCAUSE_WATCHDOGRESET;
	return STARTCAUSE_COLDSTART;
}

#endif

#ifdef __AXM0F2

extern uint8_t __startcause;

/**
 * \brief return the reason for the startup
 *
 */
__reentrantb uint8_t get_startcause(void) __reentrant
{
	uint32_t st = SRSSLT->RES_CAUSE;
	if (st & 0x00000010)
		return STARTCAUSE_SWRESET;
	if (st & 0x00000001)
		return STARTCAUSE_WATCHDOGRESET;
	return __startcause;
}

#endif

#else /* AX8052 */

uint8_t __data __startcause = STARTCAUSE_COLDSTART;

/**
 * \brief return the reason for the startup
 *
 */
__reentrantb uint8_t get_startcause(void) __reentrant
{
	uint8_t p = PCON;
	if (p & 0x40)
		__startcause = STARTCAUSE_WAKEUPSLEEP;
	else if (p & 0x20)
		__startcause = STARTCAUSE_WATCHDOGRESET;
	else if (p & 0x10)
		__startcause = STARTCAUSE_SWRESET;
	return __startcause;
	//FIXME: STARTCAUSE_WAKEUPDEEPSLEEP
}

#endif
