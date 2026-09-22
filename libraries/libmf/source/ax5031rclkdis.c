/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer, Pradeep Kumar GR
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

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0f131.h"
#endif /* __AXM0 */
#ifdef __AXM0F2
#include "axm0f231.h"
#endif /* __AXM0F2 */
#else
#include "ax8052f131.h"
#endif
#include "libmftypes.h"
#include "libmfradio.h"

__reentrantb void ax5031_rclk_disable(void) __reentrant
{
	criticalsection_t crit;
	uint8_t p;
	crit = enter_critical();
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	/* Enable the pull up on PR1 */
	XBAR->PULL_UP_CFG_b.PR1 = 0x1;
#endif /* __AXM0 */
#ifdef __AXM0F2
	/* Configure P3[1] as off */
	GPIO_PRT3->PC ^= (GPIO_PRT3->PC ^ 0x00000000) & 0x00000038;
#endif /* __AXM0F2 */
#else
	PORTR |= 0x02;
#endif	
	radio_write8(AX5031_REG_PINCFG1, (radio_read8(AX5031_REG_PINCFG1) & 0xF0) | 0x01);
	p = radio_read8(AX5031_REG_PWRMODE);
	if ((p & 0x0F) == 0x05)
		radio_write8(AX5031_REG_PWRMODE, p & 0xF0);
	exit_critical(crit);
}
