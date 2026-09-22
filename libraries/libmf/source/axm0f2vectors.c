/**
******************************************************************************
* @file axm0f2vectors.c
* @brief IRQ handler/Vector definitions
* @internal
* @author   Thomas Sailer, Pradeep Kumar G R
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
* @ingroup VECTOR
*
* @details
*/

#include "axm0f2vectors.h"

void fExceptionPriorities (void)
{
	/* setting all exceptions to default low priority */
	/* Priorities can be changed at dynamically */
	NVIC_SetPriority(GPIOPort0_IRQn, 3);
	NVIC_SetPriority(GPIOPort1_IRQn, 3);
	NVIC_SetPriority(GPIOPort2_IRQn, 3);
	NVIC_SetPriority(GPIOPort3_IRQn, 3);
	NVIC_SetPriority(GPIO_IRQn, 3);
	NVIC_SetPriority(LPComp_IRQn, 3);
	NVIC_SetPriority(WDT_IRQn, 3);
	NVIC_SetPriority(SCB0_IRQn, 3);
	NVIC_SetPriority(SCB1_IRQn, 3);
	NVIC_SetPriority(SCB2_IRQn, 3);
	NVIC_SetPriority(CTBm_IRQn, 3);
	NVIC_SetPriority(WCOWDT_IRQn, 3);
	NVIC_SetPriority(SPCIF_IRQn, 3);
	NVIC_SetPriority(CSD_IRQn, 3);
	NVIC_SetPriority(TCPWM0_IRQn, 3);
	NVIC_SetPriority(TCPWM1_IRQn, 3);
	NVIC_SetPriority(TCPWM2_IRQn, 3);
	NVIC_SetPriority(TCPWM3_IRQn, 3);
	NVIC_SetPriority(TCPWM4_IRQn, 3);
	NVIC_SetPriority(ADC_IRQn, 3);
}
