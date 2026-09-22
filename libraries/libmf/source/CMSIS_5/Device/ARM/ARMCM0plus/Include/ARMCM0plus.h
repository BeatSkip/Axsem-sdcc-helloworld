/**************************************************************************//**
 * @file     ARMCM0plus.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
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

#ifndef ARMCM0plus_H
#define ARMCM0plus_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Cortex-M0+ Processor Exceptions Numbers  ------------------ */
  NonMaskableInt_IRQn           = -14,      /*  2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,      /*  3 HardFault Interrupt */



  SVCall_IRQn                   =  -5,      /* 11 SV Call Interrupt */

  PendSV_IRQn                   =  -2,      /* 14 Pend SV Interrupt */
  SysTick_IRQn                  =  -1,      /* 15 System Tick Interrupt */

/* ----------------------  ARMCM0 Specific Interrupt Numbers  --------------------- */
  GPIO_IRQn                      =   0,      /* GPIO Interrupt */
  WakeupTimer_IRQn               =   1,      /* Wakeup Timer Interrupt */
  ClockSysConfig_IRQn            =   2,      /* ClockSysConfig Interrupt */
  AnalogComp_IRQn                =   3,      /* AnalogComp Interrupt */
  ADC_IRQn                       =   4,      /* ADC Interrupt */
  AES_IRQn                       =   5,      /* AES Interrupt */
  TRNG_IRQn                      =   6,      /* TRNG Interrupt */
  FLASH_IRQn                     =   7,      /* FLASH Interrupt */
  Watchdog_IRQn                  =   8,      /* Watchdog Interrupt */
  TickerTimer_IRQn               =   9,      /* TickerTimer Interrupt */
  Timer0_IRQn                    =  10,      /* Timer0 Interrupt */
  Timer1_IRQn                    =  11,      /* Timer1 Interrupt */
  Timer2_IRQn                    =  12,      /* Timer2 Interrupt */
  PMW0_IRQn                      =  13,      /* PMW0 Interrupt */
  PMW1_IRQn                      =  14,      /* PMW1 Interrupt */
  PMW2_IRQn                      =  15,      /* PMW2 Interrupt */
  PMW3_IRQn                      =  16,      /* PMW3 Interrupt */
  SPI0_IRQn                      =  17,      /* SPI0 Interrupt */
  SPI1_IRQn                      =  18,      /* SPI1 Interrupt */
  UART0_IRQn                     =  19,      /* UART0 Interrupt */
  UART1_IRQn                     =  20,      /* UART1 Interrupt */
  I2C_IRQn                       =  21,      /* I2C Interrupt */
  DMAError_IRQn                  =  22,      /* DMAError Interrupt */
  DMADone_IRQn                   =  23       /* DMADone Interrupt */
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of the Cortex-M0+ Processor and Core Peripherals  ------ */
#define __CM0PLUS_REV             0x0000U   /* Core revision r0p0 */
#define __MPU_PRESENT             0U        /* MPU present or not */
#define __VTOR_PRESENT            0U        /* VTOR present or not */
#define __NVIC_PRIO_BITS          2U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */

#include "core_cm0plus.h"                   /* Processor and core peripherals */
#include "system_axcm0plus.h"               /* System Header */


/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

#ifdef __cplusplus
}
#endif

#endif  /* ARMCM0plus_H */
