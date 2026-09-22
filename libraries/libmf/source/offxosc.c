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

#include "cpu.h"
#include "libmfosc.h"

/**
 * \brief turn off XOSC if accidentally enabled
 *
 */
__reentrantb void turn_off_xosc(void) __reentrant
{
	uint8_t portasave, dirasave, xtalreadysave, i;
	criticalsection_t crit;

	if (SILICONREV != SILICONREVISION_V1 && (MISCCTRL & 0x02))
		return;
	MISCCTRL |= 0x02;
	crit = enter_critical();
	portasave = PORTA;
	dirasave = DIRA;
	xtalreadysave = XTALREADY;
	XTALREADY = 0x00;
	PORTA_0 = 1;
	PORTA_1 = 0;
	DIRA |= 0x03;
	OSCFORCERUN &= (uint8_t)~0x04;
	i = 6;
	do {
		PORTA ^= 0x03;
	} while (--i);
	DIRA = dirasave;
	PORTA = portasave;
	XTALREADY = xtalreadysave;
	exit_critical(crit);
}
