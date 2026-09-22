/**
******************************************************************************
* @file axm0vectors.c
* @brief IRQ handler/Vector definitions
* @internal
* @author   Thomas Sailer, Pradeep Kumar G R, Radhika R
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

#include "axm0vectors.h"

void fExceptionPriorities (void)
{
	/* setting all exceptions to default low priority */
	/* Priorities can be changed at dynamically */
	NVIC_SetPriority(GPIO_IRQn, 3);
	NVIC_SetPriority(WakeupTimer_IRQn, 3);
	NVIC_SetPriority(ClockSysConfig_IRQn, 3);
	NVIC_SetPriority(AnalogComp_IRQn, 3);
	NVIC_SetPriority(ADC_IRQn, 3);
	NVIC_SetPriority(AES_IRQn, 3);
	NVIC_SetPriority(TRNG_IRQn, 3);
	NVIC_SetPriority(FLASH_IRQn, 3);
	NVIC_SetPriority(Watchdog_IRQn, 3);
	NVIC_SetPriority(TickerTimer_IRQn, 3);
	NVIC_SetPriority(Timer0_IRQn, 3);
	NVIC_SetPriority(Timer1_IRQn, 3);
	NVIC_SetPriority(Timer2_IRQn, 3);
	NVIC_SetPriority(PMW0_IRQn, 3);
	NVIC_SetPriority(PMW1_IRQn, 3);
	NVIC_SetPriority(PMW2_IRQn, 3);
	NVIC_SetPriority(PMW3_IRQn, 3);
	NVIC_SetPriority(SPI0_IRQn, 3);
	NVIC_SetPriority(SPI1_IRQn, 3);
	NVIC_SetPriority(UART0_IRQn, 3);
	NVIC_SetPriority(UART1_IRQn, 3);
	NVIC_SetPriority(I2C_IRQn, 3);
	NVIC_SetPriority(DMAError_IRQn, 3);
	NVIC_SetPriority(DMADone_IRQn, 3);
}
