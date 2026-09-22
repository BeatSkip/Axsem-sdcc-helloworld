/**************************************************************************//**
 * @file     system_ARMCM0plus.c
 * @brief    CMSIS Device System Source File for
 *           ARMCM0plus Device Series
 * @version  V5.00
 * @date     07. September 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "axm0.h"
/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define  XTAL            ( 16000000UL)      /* Two XTAL oscillators - 32KHz and 8-16MHz */
/* ToDo: add here your necessary defines for device initialization
         following is an example for different system frequencies             */
#define  SYSTEM_CLOCK    (20000000UL) 		/* 20 MHz clock */


/*----------------------------------------------------------------------------
  Externals
 *----------------------------------------------------------------------------*/
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
extern uint32_t __Vectors;
#endif

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
/*
 * ToDo: initialize SystemCoreClock with the system core clock frequency value
 * achieved after system intitialization.
 * This means system core clock frequency after call to SystemInit()
 */
uint32_t SystemCoreClock = SYSTEM_CLOCK;

/*----------------------------------------------------------------------------
  System Core Clock update function
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)
{
	/*
	 * TODO: add code to calculate the system frequency based upon the current
	 * register settings.
         * This function can be used to retrieve the system core clock frequeny
         * after user changed register sittings.
	 */
	SystemCoreClock = SYSTEM_CLOCK;
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
unsigned int SystemInit (void) __attribute__ ((weak));
unsigned int SystemInit (void)
{
	_axm0_external_startup();

#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
	SCB->VTOR = (uint32_t) &__Vectors;
#endif

	SystemCoreClock = SYSTEM_CLOCK;
	/* Chip coming out of hibernate; Check the status and mode */
	if ((PMU->STS & 0x02) && (PMU->MOD == 0x1))
		return 1;
	return 0;
}

/*----------------------------------------------------------------------------
  Weak dummy function for _axm0_external_startup
 *----------------------------------------------------------------------------*/
__attribute__((weak)) uint8_t _axm0_external_startup(void)
{
	return 0;
}
