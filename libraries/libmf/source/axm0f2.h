/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file     axm0f2.h
 * @brief    CMSIS HeaderFile
 * @version  0.1
 * @date     05. December 2017
 */



/** @addtogroup
  * @{
  */


/** @addtogroup axm0f2
  * @{
  */


#ifndef AXM0F2_H
#define AXM0F2_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Configuration_of_CMSIS
  * @{
  */



/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* =======================================  ARM Cortex-M0+ Specific Interrupt Numbers  ======================================= */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */
/* ==========================================  axm0f2 Specific Interrupt Numbers  ============================================ */
  GPIOPort0_IRQn            =   0,              /*!< 0  GPIOPort0                                                              */
  GPIOPort1_IRQn            =   1,              /*!< 1  GPIOPort1                                                              */
  GPIOPort2_IRQn            =   2,              /*!< 2  GPIOPort2                                                              */
  GPIOPort3_IRQn            =   3,              /*!< 3  GPIOPort3                                                              */
  GPIO_IRQn                 =   4,              /*!< 4  GPIO                                                                   */
  LPComp_IRQn               =   5,              /*!< 5  LPComp                                                                 */
  WDT_IRQn                  =   6,              /*!< 6  WDT                                                                    */
  SCB0_IRQn                 =   7,              /*!< 7  SCB0                                                                   */
  SCB1_IRQn                 =   8,              /*!< 8  SCB1                                                                   */
  SCB2_IRQn                 =   9,              /*!< 9  SCB2                                                                   */
  CTBm_IRQn                 =  10,              /*!< 10 CTBm                                                                   */
  WCOWDT_IRQn               =  11,              /*!< 11 WCOWDT                                                                 */
  SPCIF_IRQn                =  12,              /*!< 12 SPCIF                                                                  */
  CSD_IRQn                  =  13,              /*!< 13 CSD                                                                    */
  TCPWM0_IRQn               =  14,              /*!< 14 TCPWM0                                                                 */
  TCPWM1_IRQn               =  15,              /*!< 15 TCPWM1                                                                 */
  TCPWM2_IRQn               =  16,              /*!< 16 TCPWM2                                                                 */
  TCPWM3_IRQn               =  17,              /*!< 17 TCPWM3                                                                 */
  TCPWM4_IRQn               =  18,              /*!< 18 TCPWM4                                                                 */
  ADC_IRQn                  =  19               /*!< 19 ADC                                                                    */
} IRQn_Type;



/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ==========================  Configuration of the ARM Cortex-M0+ Processor and Core Peripherals  =========================== */
#define __CM0PLUS_REV                 0x0001U   /*!< CM0PLUS Core Revision                                                     */
#define __NVIC_PRIO_BITS               2        /*!< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0        /*!< Set to 1 if different SysTick Config is used                              */
#define __VTOR_PRESENT                 1        /*!< Set to 1 if CPU supports Vector Table Offset Register                     */


/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0plus.h"                       /*!< ARM Cortex-M0+ processor and core peripherals                             */
#include "system_ARMCM0plus.h"                  /*!< ARM CM0+ System                                                           */

#ifndef __IM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __IM   __I
#endif
#ifndef __OM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __OM   __O
#endif
#ifndef __IOM                                   /*!< Fallback for older CMSIS versions                                         */
  #define __IOM  __IO
#endif


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                          SFLASH                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Supervisory Flash Area (Manufacturer Trim & Wounding Info) (SFLASH)
  */

typedef struct {                                /*!< (@ 0x0FFFF000) SFLASH Structure                                           */
  __IM  uint32_t  RESERVED[53];
  __IOM uint8_t   CSDV2_CSD1_ADC_TRIM1;         /*!< (@ 0x000000D4) CSDV2 CSD1 ADC TRIM 1                                      */
  __IOM uint8_t   CSDV2_CSD1_ADC_TRIM2;         /*!< (@ 0x000000D5) CSDV2 CSD1 ADC TRIM2                                       */
  __IM  uint16_t  RESERVED1;
  __IM  uint32_t  RESERVED2[30];
  __IOM uint16_t  HIB_KEY_DELAY;                /*!< (@ 0x00000150) Hibernate wakeup value for PWR_KEY_DELAY                   */
  __IOM uint16_t  DPSLP_KEY_DELAY;              /*!< (@ 0x00000152) DeepSleep wakeup value for PWR_KEY_DELAY                   */
  __IOM uint8_t   SWD_CONFIG;                   /*!< (@ 0x00000154) SWD pinout selector (not present in TSG4/TSG5-M)           */
  __IM  uint8_t   RESERVED3;
  __IM  uint16_t  RESERVED4;
  __IOM uint32_t  SWD_LISTEN;                   /*!< (@ 0x00000158) Listen Window Length                                       */
  __IOM uint32_t  FLASH_START;                  /*!< (@ 0x0000015C) Flash Image Start Address                                  */
  __IOM uint8_t   CSDV2_CSD0_ADC_TRIM1;         /*!< (@ 0x00000160) CSDV2 CSD0 ADC TRIM 1                                      */
  __IOM uint8_t   CSDV2_CSD0_ADC_TRIM2;         /*!< (@ 0x00000161) CSDV2 CSD0 ADC TRIM2                                       */
  __IM  uint16_t  RESERVED5;
  __IOM uint16_t  SAR_TEMP_MULTIPLIER;          /*!< (@ 0x00000164) SAR Temperature Sensor Multiplication Factor               */
  __IOM uint16_t  SAR_TEMP_OFFSET;              /*!< (@ 0x00000166) SAR Temperature Sensor Offset                              */
  __IM  uint32_t  RESERVED6[4];
  __IOM uint8_t   DIE_LOT0;                     /*!< (@ 0x00000178) Lot Number (3 bytes)                                       */
  __IOM uint8_t   DIE_LOT1;                     /*!< (@ 0x00000179) Lot Number (3 bytes)                                       */
  __IOM uint8_t   DIE_LOT2;                     /*!< (@ 0x0000017A) Lot Number (3 bytes)                                       */
  __IOM uint8_t   DIE_WAFER;                    /*!< (@ 0x0000017B) Wafer Number                                               */
  __IOM uint8_t   DIE_X;                        /*!< (@ 0x0000017C) X Position on Wafer, CRI Pass/Fail Bin                     */
  __IOM uint8_t   DIE_Y;                        /*!< (@ 0x0000017D) Y Position on Wafer, CHI Pass/Fail Bin                     */
  __IOM uint8_t   DIE_SORT;                     /*!< (@ 0x0000017E) Sort1/2/3 Pass/Fail Bin                                    */
  __IOM uint8_t   DIE_MINOR;                    /*!< (@ 0x0000017F) Minor Revision Number                                      */
  __IM  uint32_t  RESERVED7[15];
  __IM  uint16_t  RESERVED8;
  __IOM uint8_t   IMO_TRIM_USBMODE_24;          /*!< (@ 0x000001BE) USB IMO TRIM 24MHz                                         */
  __IOM uint8_t   IMO_TRIM_USBMODE_48;          /*!< (@ 0x000001BF) USB IMO TRIM 48MHz                                         */
  __IM  uint32_t  RESERVED9[3];
  __IOM uint8_t   IMO_TCTRIM_LT0;               /*!< (@ 0x000001CC) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT1;               /*!< (@ 0x000001CD) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT2;               /*!< (@ 0x000001CE) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT3;               /*!< (@ 0x000001CF) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT4;               /*!< (@ 0x000001D0) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT5;               /*!< (@ 0x000001D1) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT6;               /*!< (@ 0x000001D2) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT7;               /*!< (@ 0x000001D3) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT8;               /*!< (@ 0x000001D4) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT9;               /*!< (@ 0x000001D5) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT10;              /*!< (@ 0x000001D6) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT11;              /*!< (@ 0x000001D7) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT12;              /*!< (@ 0x000001D8) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT13;              /*!< (@ 0x000001D9) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT14;              /*!< (@ 0x000001DA) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT15;              /*!< (@ 0x000001DB) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT16;              /*!< (@ 0x000001DC) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT17;              /*!< (@ 0x000001DD) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT18;              /*!< (@ 0x000001DE) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT19;              /*!< (@ 0x000001DF) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT20;              /*!< (@ 0x000001E0) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT21;              /*!< (@ 0x000001E1) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT22;              /*!< (@ 0x000001E2) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT23;              /*!< (@ 0x000001E3) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TCTRIM_LT24;              /*!< (@ 0x000001E4) IMO TempCo Trim Register (SRSS-Lite)                       */
  __IOM uint8_t   IMO_TRIM_LT0;                 /*!< (@ 0x000001E5) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT1;                 /*!< (@ 0x000001E6) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT2;                 /*!< (@ 0x000001E7) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT3;                 /*!< (@ 0x000001E8) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT4;                 /*!< (@ 0x000001E9) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT5;                 /*!< (@ 0x000001EA) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT6;                 /*!< (@ 0x000001EB) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT7;                 /*!< (@ 0x000001EC) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT8;                 /*!< (@ 0x000001ED) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT9;                 /*!< (@ 0x000001EE) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT10;                /*!< (@ 0x000001EF) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT11;                /*!< (@ 0x000001F0) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT12;                /*!< (@ 0x000001F1) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT13;                /*!< (@ 0x000001F2) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT14;                /*!< (@ 0x000001F3) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT15;                /*!< (@ 0x000001F4) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT16;                /*!< (@ 0x000001F5) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT17;                /*!< (@ 0x000001F6) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT18;                /*!< (@ 0x000001F7) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT19;                /*!< (@ 0x000001F8) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT20;                /*!< (@ 0x000001F9) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT21;                /*!< (@ 0x000001FA) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT22;                /*!< (@ 0x000001FB) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT23;                /*!< (@ 0x000001FC) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IOM uint8_t   IMO_TRIM_LT24;                /*!< (@ 0x000001FD) IMO Frequency Trim Register (SRSS-Lite)                    */
  __IM  uint16_t  RESERVED10;
  __IOM uint8_t   MACRO_0_FREE_SFLASH0;         /*!< (@ 0x00000200) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH1;         /*!< (@ 0x00000201) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH2;         /*!< (@ 0x00000202) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH3;         /*!< (@ 0x00000203) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH4;         /*!< (@ 0x00000204) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH5;         /*!< (@ 0x00000205) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH6;         /*!< (@ 0x00000206) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH7;         /*!< (@ 0x00000207) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH8;         /*!< (@ 0x00000208) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH9;         /*!< (@ 0x00000209) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH10;        /*!< (@ 0x0000020A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH11;        /*!< (@ 0x0000020B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH12;        /*!< (@ 0x0000020C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH13;        /*!< (@ 0x0000020D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH14;        /*!< (@ 0x0000020E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH15;        /*!< (@ 0x0000020F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH16;        /*!< (@ 0x00000210) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH17;        /*!< (@ 0x00000211) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH18;        /*!< (@ 0x00000212) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH19;        /*!< (@ 0x00000213) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH20;        /*!< (@ 0x00000214) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH21;        /*!< (@ 0x00000215) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH22;        /*!< (@ 0x00000216) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH23;        /*!< (@ 0x00000217) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH24;        /*!< (@ 0x00000218) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH25;        /*!< (@ 0x00000219) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH26;        /*!< (@ 0x0000021A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH27;        /*!< (@ 0x0000021B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH28;        /*!< (@ 0x0000021C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH29;        /*!< (@ 0x0000021D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH30;        /*!< (@ 0x0000021E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH31;        /*!< (@ 0x0000021F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH32;        /*!< (@ 0x00000220) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH33;        /*!< (@ 0x00000221) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH34;        /*!< (@ 0x00000222) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH35;        /*!< (@ 0x00000223) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH36;        /*!< (@ 0x00000224) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH37;        /*!< (@ 0x00000225) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH38;        /*!< (@ 0x00000226) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH39;        /*!< (@ 0x00000227) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH40;        /*!< (@ 0x00000228) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH41;        /*!< (@ 0x00000229) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH42;        /*!< (@ 0x0000022A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH43;        /*!< (@ 0x0000022B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH44;        /*!< (@ 0x0000022C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH45;        /*!< (@ 0x0000022D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH46;        /*!< (@ 0x0000022E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH47;        /*!< (@ 0x0000022F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH48;        /*!< (@ 0x00000230) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH49;        /*!< (@ 0x00000231) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH50;        /*!< (@ 0x00000232) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH51;        /*!< (@ 0x00000233) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH52;        /*!< (@ 0x00000234) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH53;        /*!< (@ 0x00000235) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH54;        /*!< (@ 0x00000236) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH55;        /*!< (@ 0x00000237) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH56;        /*!< (@ 0x00000238) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH57;        /*!< (@ 0x00000239) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH58;        /*!< (@ 0x0000023A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH59;        /*!< (@ 0x0000023B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH60;        /*!< (@ 0x0000023C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH61;        /*!< (@ 0x0000023D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH62;        /*!< (@ 0x0000023E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH63;        /*!< (@ 0x0000023F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH64;        /*!< (@ 0x00000240) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH65;        /*!< (@ 0x00000241) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH66;        /*!< (@ 0x00000242) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH67;        /*!< (@ 0x00000243) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH68;        /*!< (@ 0x00000244) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH69;        /*!< (@ 0x00000245) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH70;        /*!< (@ 0x00000246) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH71;        /*!< (@ 0x00000247) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH72;        /*!< (@ 0x00000248) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH73;        /*!< (@ 0x00000249) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH74;        /*!< (@ 0x0000024A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH75;        /*!< (@ 0x0000024B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH76;        /*!< (@ 0x0000024C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH77;        /*!< (@ 0x0000024D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH78;        /*!< (@ 0x0000024E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH79;        /*!< (@ 0x0000024F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH80;        /*!< (@ 0x00000250) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH81;        /*!< (@ 0x00000251) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH82;        /*!< (@ 0x00000252) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH83;        /*!< (@ 0x00000253) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH84;        /*!< (@ 0x00000254) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH85;        /*!< (@ 0x00000255) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH86;        /*!< (@ 0x00000256) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH87;        /*!< (@ 0x00000257) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH88;        /*!< (@ 0x00000258) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH89;        /*!< (@ 0x00000259) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH90;        /*!< (@ 0x0000025A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH91;        /*!< (@ 0x0000025B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH92;        /*!< (@ 0x0000025C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH93;        /*!< (@ 0x0000025D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH94;        /*!< (@ 0x0000025E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH95;        /*!< (@ 0x0000025F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH96;        /*!< (@ 0x00000260) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH97;        /*!< (@ 0x00000261) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH98;        /*!< (@ 0x00000262) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH99;        /*!< (@ 0x00000263) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH100;       /*!< (@ 0x00000264) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH101;       /*!< (@ 0x00000265) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH102;       /*!< (@ 0x00000266) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH103;       /*!< (@ 0x00000267) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH104;       /*!< (@ 0x00000268) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH105;       /*!< (@ 0x00000269) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH106;       /*!< (@ 0x0000026A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH107;       /*!< (@ 0x0000026B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH108;       /*!< (@ 0x0000026C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH109;       /*!< (@ 0x0000026D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH110;       /*!< (@ 0x0000026E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH111;       /*!< (@ 0x0000026F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH112;       /*!< (@ 0x00000270) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH113;       /*!< (@ 0x00000271) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH114;       /*!< (@ 0x00000272) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH115;       /*!< (@ 0x00000273) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH116;       /*!< (@ 0x00000274) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH117;       /*!< (@ 0x00000275) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH118;       /*!< (@ 0x00000276) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH119;       /*!< (@ 0x00000277) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH120;       /*!< (@ 0x00000278) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH121;       /*!< (@ 0x00000279) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH122;       /*!< (@ 0x0000027A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH123;       /*!< (@ 0x0000027B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH124;       /*!< (@ 0x0000027C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH125;       /*!< (@ 0x0000027D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH126;       /*!< (@ 0x0000027E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH127;       /*!< (@ 0x0000027F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH128;       /*!< (@ 0x00000280) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH129;       /*!< (@ 0x00000281) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH130;       /*!< (@ 0x00000282) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH131;       /*!< (@ 0x00000283) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH132;       /*!< (@ 0x00000284) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH133;       /*!< (@ 0x00000285) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH134;       /*!< (@ 0x00000286) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH135;       /*!< (@ 0x00000287) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH136;       /*!< (@ 0x00000288) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH137;       /*!< (@ 0x00000289) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH138;       /*!< (@ 0x0000028A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH139;       /*!< (@ 0x0000028B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH140;       /*!< (@ 0x0000028C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH141;       /*!< (@ 0x0000028D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH142;       /*!< (@ 0x0000028E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH143;       /*!< (@ 0x0000028F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH144;       /*!< (@ 0x00000290) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH145;       /*!< (@ 0x00000291) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH146;       /*!< (@ 0x00000292) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH147;       /*!< (@ 0x00000293) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH148;       /*!< (@ 0x00000294) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH149;       /*!< (@ 0x00000295) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH150;       /*!< (@ 0x00000296) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH151;       /*!< (@ 0x00000297) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH152;       /*!< (@ 0x00000298) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH153;       /*!< (@ 0x00000299) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH154;       /*!< (@ 0x0000029A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH155;       /*!< (@ 0x0000029B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH156;       /*!< (@ 0x0000029C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH157;       /*!< (@ 0x0000029D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH158;       /*!< (@ 0x0000029E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH159;       /*!< (@ 0x0000029F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH160;       /*!< (@ 0x000002A0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH161;       /*!< (@ 0x000002A1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH162;       /*!< (@ 0x000002A2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH163;       /*!< (@ 0x000002A3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH164;       /*!< (@ 0x000002A4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH165;       /*!< (@ 0x000002A5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH166;       /*!< (@ 0x000002A6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH167;       /*!< (@ 0x000002A7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH168;       /*!< (@ 0x000002A8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH169;       /*!< (@ 0x000002A9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH170;       /*!< (@ 0x000002AA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH171;       /*!< (@ 0x000002AB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH172;       /*!< (@ 0x000002AC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH173;       /*!< (@ 0x000002AD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH174;       /*!< (@ 0x000002AE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH175;       /*!< (@ 0x000002AF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH176;       /*!< (@ 0x000002B0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH177;       /*!< (@ 0x000002B1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH178;       /*!< (@ 0x000002B2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH179;       /*!< (@ 0x000002B3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH180;       /*!< (@ 0x000002B4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH181;       /*!< (@ 0x000002B5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH182;       /*!< (@ 0x000002B6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH183;       /*!< (@ 0x000002B7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH184;       /*!< (@ 0x000002B8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH185;       /*!< (@ 0x000002B9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH186;       /*!< (@ 0x000002BA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH187;       /*!< (@ 0x000002BB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH188;       /*!< (@ 0x000002BC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH189;       /*!< (@ 0x000002BD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH190;       /*!< (@ 0x000002BE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH191;       /*!< (@ 0x000002BF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH192;       /*!< (@ 0x000002C0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH193;       /*!< (@ 0x000002C1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH194;       /*!< (@ 0x000002C2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH195;       /*!< (@ 0x000002C3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH196;       /*!< (@ 0x000002C4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH197;       /*!< (@ 0x000002C5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH198;       /*!< (@ 0x000002C6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH199;       /*!< (@ 0x000002C7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH200;       /*!< (@ 0x000002C8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH201;       /*!< (@ 0x000002C9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH202;       /*!< (@ 0x000002CA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH203;       /*!< (@ 0x000002CB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH204;       /*!< (@ 0x000002CC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH205;       /*!< (@ 0x000002CD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH206;       /*!< (@ 0x000002CE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH207;       /*!< (@ 0x000002CF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH208;       /*!< (@ 0x000002D0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH209;       /*!< (@ 0x000002D1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH210;       /*!< (@ 0x000002D2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH211;       /*!< (@ 0x000002D3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH212;       /*!< (@ 0x000002D4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH213;       /*!< (@ 0x000002D5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH214;       /*!< (@ 0x000002D6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH215;       /*!< (@ 0x000002D7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH216;       /*!< (@ 0x000002D8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH217;       /*!< (@ 0x000002D9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH218;       /*!< (@ 0x000002DA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH219;       /*!< (@ 0x000002DB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH220;       /*!< (@ 0x000002DC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH221;       /*!< (@ 0x000002DD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH222;       /*!< (@ 0x000002DE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH223;       /*!< (@ 0x000002DF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH224;       /*!< (@ 0x000002E0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH225;       /*!< (@ 0x000002E1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH226;       /*!< (@ 0x000002E2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH227;       /*!< (@ 0x000002E3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH228;       /*!< (@ 0x000002E4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH229;       /*!< (@ 0x000002E5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH230;       /*!< (@ 0x000002E6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH231;       /*!< (@ 0x000002E7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH232;       /*!< (@ 0x000002E8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH233;       /*!< (@ 0x000002E9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH234;       /*!< (@ 0x000002EA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH235;       /*!< (@ 0x000002EB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH236;       /*!< (@ 0x000002EC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH237;       /*!< (@ 0x000002ED) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH238;       /*!< (@ 0x000002EE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH239;       /*!< (@ 0x000002EF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH240;       /*!< (@ 0x000002F0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH241;       /*!< (@ 0x000002F1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH242;       /*!< (@ 0x000002F2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH243;       /*!< (@ 0x000002F3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH244;       /*!< (@ 0x000002F4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH245;       /*!< (@ 0x000002F5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH246;       /*!< (@ 0x000002F6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH247;       /*!< (@ 0x000002F7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH248;       /*!< (@ 0x000002F8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH249;       /*!< (@ 0x000002F9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH250;       /*!< (@ 0x000002FA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH251;       /*!< (@ 0x000002FB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH252;       /*!< (@ 0x000002FC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH253;       /*!< (@ 0x000002FD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH254;       /*!< (@ 0x000002FE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH255;       /*!< (@ 0x000002FF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH256;       /*!< (@ 0x00000300) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH257;       /*!< (@ 0x00000301) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH258;       /*!< (@ 0x00000302) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH259;       /*!< (@ 0x00000303) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH260;       /*!< (@ 0x00000304) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH261;       /*!< (@ 0x00000305) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH262;       /*!< (@ 0x00000306) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH263;       /*!< (@ 0x00000307) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH264;       /*!< (@ 0x00000308) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH265;       /*!< (@ 0x00000309) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH266;       /*!< (@ 0x0000030A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH267;       /*!< (@ 0x0000030B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH268;       /*!< (@ 0x0000030C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH269;       /*!< (@ 0x0000030D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH270;       /*!< (@ 0x0000030E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH271;       /*!< (@ 0x0000030F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH272;       /*!< (@ 0x00000310) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH273;       /*!< (@ 0x00000311) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH274;       /*!< (@ 0x00000312) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH275;       /*!< (@ 0x00000313) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH276;       /*!< (@ 0x00000314) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH277;       /*!< (@ 0x00000315) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH278;       /*!< (@ 0x00000316) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH279;       /*!< (@ 0x00000317) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH280;       /*!< (@ 0x00000318) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH281;       /*!< (@ 0x00000319) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH282;       /*!< (@ 0x0000031A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH283;       /*!< (@ 0x0000031B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH284;       /*!< (@ 0x0000031C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH285;       /*!< (@ 0x0000031D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH286;       /*!< (@ 0x0000031E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH287;       /*!< (@ 0x0000031F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH288;       /*!< (@ 0x00000320) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH289;       /*!< (@ 0x00000321) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH290;       /*!< (@ 0x00000322) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH291;       /*!< (@ 0x00000323) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH292;       /*!< (@ 0x00000324) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH293;       /*!< (@ 0x00000325) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH294;       /*!< (@ 0x00000326) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH295;       /*!< (@ 0x00000327) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH296;       /*!< (@ 0x00000328) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH297;       /*!< (@ 0x00000329) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH298;       /*!< (@ 0x0000032A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH299;       /*!< (@ 0x0000032B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH300;       /*!< (@ 0x0000032C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH301;       /*!< (@ 0x0000032D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH302;       /*!< (@ 0x0000032E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH303;       /*!< (@ 0x0000032F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH304;       /*!< (@ 0x00000330) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH305;       /*!< (@ 0x00000331) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH306;       /*!< (@ 0x00000332) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH307;       /*!< (@ 0x00000333) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH308;       /*!< (@ 0x00000334) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH309;       /*!< (@ 0x00000335) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH310;       /*!< (@ 0x00000336) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH311;       /*!< (@ 0x00000337) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH312;       /*!< (@ 0x00000338) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH313;       /*!< (@ 0x00000339) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH314;       /*!< (@ 0x0000033A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH315;       /*!< (@ 0x0000033B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH316;       /*!< (@ 0x0000033C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH317;       /*!< (@ 0x0000033D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH318;       /*!< (@ 0x0000033E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH319;       /*!< (@ 0x0000033F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH320;       /*!< (@ 0x00000340) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH321;       /*!< (@ 0x00000341) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH322;       /*!< (@ 0x00000342) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH323;       /*!< (@ 0x00000343) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH324;       /*!< (@ 0x00000344) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH325;       /*!< (@ 0x00000345) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH326;       /*!< (@ 0x00000346) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH327;       /*!< (@ 0x00000347) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH328;       /*!< (@ 0x00000348) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH329;       /*!< (@ 0x00000349) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH330;       /*!< (@ 0x0000034A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH331;       /*!< (@ 0x0000034B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH332;       /*!< (@ 0x0000034C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH333;       /*!< (@ 0x0000034D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH334;       /*!< (@ 0x0000034E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH335;       /*!< (@ 0x0000034F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH336;       /*!< (@ 0x00000350) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH337;       /*!< (@ 0x00000351) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH338;       /*!< (@ 0x00000352) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH339;       /*!< (@ 0x00000353) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH340;       /*!< (@ 0x00000354) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH341;       /*!< (@ 0x00000355) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH342;       /*!< (@ 0x00000356) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH343;       /*!< (@ 0x00000357) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH344;       /*!< (@ 0x00000358) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH345;       /*!< (@ 0x00000359) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH346;       /*!< (@ 0x0000035A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH347;       /*!< (@ 0x0000035B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH348;       /*!< (@ 0x0000035C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH349;       /*!< (@ 0x0000035D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH350;       /*!< (@ 0x0000035E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH351;       /*!< (@ 0x0000035F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH352;       /*!< (@ 0x00000360) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH353;       /*!< (@ 0x00000361) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH354;       /*!< (@ 0x00000362) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH355;       /*!< (@ 0x00000363) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH356;       /*!< (@ 0x00000364) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH357;       /*!< (@ 0x00000365) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH358;       /*!< (@ 0x00000366) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH359;       /*!< (@ 0x00000367) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH360;       /*!< (@ 0x00000368) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH361;       /*!< (@ 0x00000369) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH362;       /*!< (@ 0x0000036A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH363;       /*!< (@ 0x0000036B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH364;       /*!< (@ 0x0000036C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH365;       /*!< (@ 0x0000036D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH366;       /*!< (@ 0x0000036E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH367;       /*!< (@ 0x0000036F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH368;       /*!< (@ 0x00000370) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH369;       /*!< (@ 0x00000371) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH370;       /*!< (@ 0x00000372) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH371;       /*!< (@ 0x00000373) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH372;       /*!< (@ 0x00000374) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH373;       /*!< (@ 0x00000375) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH374;       /*!< (@ 0x00000376) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH375;       /*!< (@ 0x00000377) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH376;       /*!< (@ 0x00000378) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH377;       /*!< (@ 0x00000379) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH378;       /*!< (@ 0x0000037A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH379;       /*!< (@ 0x0000037B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH380;       /*!< (@ 0x0000037C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH381;       /*!< (@ 0x0000037D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH382;       /*!< (@ 0x0000037E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH383;       /*!< (@ 0x0000037F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH384;       /*!< (@ 0x00000380) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH385;       /*!< (@ 0x00000381) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH386;       /*!< (@ 0x00000382) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH387;       /*!< (@ 0x00000383) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH388;       /*!< (@ 0x00000384) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH389;       /*!< (@ 0x00000385) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH390;       /*!< (@ 0x00000386) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH391;       /*!< (@ 0x00000387) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH392;       /*!< (@ 0x00000388) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH393;       /*!< (@ 0x00000389) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH394;       /*!< (@ 0x0000038A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH395;       /*!< (@ 0x0000038B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH396;       /*!< (@ 0x0000038C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH397;       /*!< (@ 0x0000038D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH398;       /*!< (@ 0x0000038E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH399;       /*!< (@ 0x0000038F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH400;       /*!< (@ 0x00000390) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH401;       /*!< (@ 0x00000391) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH402;       /*!< (@ 0x00000392) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH403;       /*!< (@ 0x00000393) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH404;       /*!< (@ 0x00000394) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH405;       /*!< (@ 0x00000395) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH406;       /*!< (@ 0x00000396) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH407;       /*!< (@ 0x00000397) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH408;       /*!< (@ 0x00000398) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH409;       /*!< (@ 0x00000399) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH410;       /*!< (@ 0x0000039A) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH411;       /*!< (@ 0x0000039B) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH412;       /*!< (@ 0x0000039C) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH413;       /*!< (@ 0x0000039D) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH414;       /*!< (@ 0x0000039E) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH415;       /*!< (@ 0x0000039F) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH416;       /*!< (@ 0x000003A0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH417;       /*!< (@ 0x000003A1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH418;       /*!< (@ 0x000003A2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH419;       /*!< (@ 0x000003A3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH420;       /*!< (@ 0x000003A4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH421;       /*!< (@ 0x000003A5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH422;       /*!< (@ 0x000003A6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH423;       /*!< (@ 0x000003A7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH424;       /*!< (@ 0x000003A8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH425;       /*!< (@ 0x000003A9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH426;       /*!< (@ 0x000003AA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH427;       /*!< (@ 0x000003AB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH428;       /*!< (@ 0x000003AC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH429;       /*!< (@ 0x000003AD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH430;       /*!< (@ 0x000003AE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH431;       /*!< (@ 0x000003AF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH432;       /*!< (@ 0x000003B0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH433;       /*!< (@ 0x000003B1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH434;       /*!< (@ 0x000003B2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH435;       /*!< (@ 0x000003B3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH436;       /*!< (@ 0x000003B4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH437;       /*!< (@ 0x000003B5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH438;       /*!< (@ 0x000003B6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH439;       /*!< (@ 0x000003B7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH440;       /*!< (@ 0x000003B8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH441;       /*!< (@ 0x000003B9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH442;       /*!< (@ 0x000003BA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH443;       /*!< (@ 0x000003BB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH444;       /*!< (@ 0x000003BC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH445;       /*!< (@ 0x000003BD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH446;       /*!< (@ 0x000003BE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH447;       /*!< (@ 0x000003BF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH448;       /*!< (@ 0x000003C0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH449;       /*!< (@ 0x000003C1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH450;       /*!< (@ 0x000003C2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH451;       /*!< (@ 0x000003C3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH452;       /*!< (@ 0x000003C4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH453;       /*!< (@ 0x000003C5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH454;       /*!< (@ 0x000003C6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH455;       /*!< (@ 0x000003C7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH456;       /*!< (@ 0x000003C8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH457;       /*!< (@ 0x000003C9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH458;       /*!< (@ 0x000003CA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH459;       /*!< (@ 0x000003CB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH460;       /*!< (@ 0x000003CC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH461;       /*!< (@ 0x000003CD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH462;       /*!< (@ 0x000003CE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH463;       /*!< (@ 0x000003CF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH464;       /*!< (@ 0x000003D0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH465;       /*!< (@ 0x000003D1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH466;       /*!< (@ 0x000003D2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH467;       /*!< (@ 0x000003D3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH468;       /*!< (@ 0x000003D4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH469;       /*!< (@ 0x000003D5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH470;       /*!< (@ 0x000003D6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH471;       /*!< (@ 0x000003D7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH472;       /*!< (@ 0x000003D8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH473;       /*!< (@ 0x000003D9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH474;       /*!< (@ 0x000003DA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH475;       /*!< (@ 0x000003DB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH476;       /*!< (@ 0x000003DC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH477;       /*!< (@ 0x000003DD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH478;       /*!< (@ 0x000003DE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH479;       /*!< (@ 0x000003DF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH480;       /*!< (@ 0x000003E0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH481;       /*!< (@ 0x000003E1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH482;       /*!< (@ 0x000003E2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH483;       /*!< (@ 0x000003E3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH484;       /*!< (@ 0x000003E4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH485;       /*!< (@ 0x000003E5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH486;       /*!< (@ 0x000003E6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH487;       /*!< (@ 0x000003E7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH488;       /*!< (@ 0x000003E8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH489;       /*!< (@ 0x000003E9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH490;       /*!< (@ 0x000003EA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH491;       /*!< (@ 0x000003EB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH492;       /*!< (@ 0x000003EC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH493;       /*!< (@ 0x000003ED) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH494;       /*!< (@ 0x000003EE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH495;       /*!< (@ 0x000003EF) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH496;       /*!< (@ 0x000003F0) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH497;       /*!< (@ 0x000003F1) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH498;       /*!< (@ 0x000003F2) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH499;       /*!< (@ 0x000003F3) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH500;       /*!< (@ 0x000003F4) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH501;       /*!< (@ 0x000003F5) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH502;       /*!< (@ 0x000003F6) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH503;       /*!< (@ 0x000003F7) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH504;       /*!< (@ 0x000003F8) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH505;       /*!< (@ 0x000003F9) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH506;       /*!< (@ 0x000003FA) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH507;       /*!< (@ 0x000003FB) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH508;       /*!< (@ 0x000003FC) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH509;       /*!< (@ 0x000003FD) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH510;       /*!< (@ 0x000003FE) Uncommitted Supervisorly Flash in Macro 0                  */
  __IOM uint8_t   MACRO_0_FREE_SFLASH511;       /*!< (@ 0x000003FF) Uncommitted Supervisorly Flash in Macro 0                  */
} SFLASH_Type;                                  /*!< Size = 1024 (0x400)                                                       */



/* =========================================================================================================================== */
/* ================                                           PERI                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Peripheral Interconnect (PERI)
  */

typedef struct {                                /*!< (@ 0x40010000) PERI Structure                                             */
  __IOM uint32_t  DIV_CMD;                      /*!< (@ 0x00000000) Divider command register                                   */
  __IM  uint32_t  RESERVED[63];
  __IOM uint32_t  PCLK_CTL0;                    /*!< (@ 0x00000100) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL1;                    /*!< (@ 0x00000104) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL2;                    /*!< (@ 0x00000108) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL3;                    /*!< (@ 0x0000010C) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL4;                    /*!< (@ 0x00000110) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL5;                    /*!< (@ 0x00000114) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL6;                    /*!< (@ 0x00000118) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL7;                    /*!< (@ 0x0000011C) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL8;                    /*!< (@ 0x00000120) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL9;                    /*!< (@ 0x00000124) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL10;                   /*!< (@ 0x00000128) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL11;                   /*!< (@ 0x0000012C) Programmable clock control register                        */
  __IOM uint32_t  PCLK_CTL12;                   /*!< (@ 0x00000130) Programmable clock control register                        */
  __IM  uint32_t  RESERVED1[115];
  __IOM uint32_t  DIV_16_CTL0;                  /*!< (@ 0x00000300) Divider control register (for 16.0 divider)                */
  __IOM uint32_t  DIV_16_CTL1;                  /*!< (@ 0x00000304) Divider control register (for 16.0 divider)                */
  __IOM uint32_t  DIV_16_CTL2;                  /*!< (@ 0x00000308) Divider control register (for 16.0 divider)                */
  __IOM uint32_t  DIV_16_CTL3;                  /*!< (@ 0x0000030C) Divider control register (for 16.0 divider)                */
  __IOM uint32_t  DIV_16_CTL4;                  /*!< (@ 0x00000310) Divider control register (for 16.0 divider)                */
  __IOM uint32_t  DIV_16_CTL5;                  /*!< (@ 0x00000314) Divider control register (for 16.0 divider)                */
  __IM  uint32_t  RESERVED2[58];
  __IOM uint32_t  DIV_16_5_CTL0;                /*!< (@ 0x00000400) Divider control register (for 16.5 divider)                */
  __IOM uint32_t  DIV_16_5_CTL1;                /*!< (@ 0x00000404) Divider control register (for 16.5 divider)                */
  __IOM uint32_t  DIV_16_5_CTL2;                /*!< (@ 0x00000408) Divider control register (for 16.5 divider)                */
  __IM  uint32_t  RESERVED3[125];
  __IOM uint32_t  TR_CTL;                       /*!< (@ 0x00000600) Trigger control register                                   */
} PERI_Type;                                    /*!< Size = 1540 (0x604)                                                       */



/* =========================================================================================================================== */
/* ================                                      PERI_TR_GROUP0                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief Peripheral Interconnect trigger group control registers (PERI_TR_GROUP0)
  */

typedef struct {                                /*!< (@ 0x40012000) PERI_TR_GROUP0 Structure                                   */
  __IOM uint32_t  TR_OUT_CTL0;                  /*!< (@ 0x00000000) Trigger control register                                   */
  __IOM uint32_t  TR_OUT_CTL1;                  /*!< (@ 0x00000004) Trigger control register                                   */
  __IOM uint32_t  TR_OUT_CTL2;                  /*!< (@ 0x00000008) Trigger control register                                   */
  __IOM uint32_t  TR_OUT_CTL3;                  /*!< (@ 0x0000000C) Trigger control register                                   */
  __IOM uint32_t  TR_OUT_CTL4;                  /*!< (@ 0x00000010) Trigger control register                                   */
  __IOM uint32_t  TR_OUT_CTL5;                  /*!< (@ 0x00000014) Trigger control register                                   */
  __IOM uint32_t  TR_OUT_CTL6;                  /*!< (@ 0x00000018) Trigger control register                                   */
} PERI_TR_GROUP0_Type;                          /*!< Size = 28 (0x1c)                                                          */



/* =========================================================================================================================== */
/* ================                                      PERI_TR_GROUP1                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief Peripheral Interconnect trigger group control registers (PERI_TR_GROUP1)
  */

typedef struct {                                /*!< (@ 0x40012200) PERI_TR_GROUP1 Structure                                   */
  __IOM uint32_t  TR_OUT_CTL;                   /*!< (@ 0x00000000) Trigger control register                                   */
} PERI_TR_GROUP1_Type;                          /*!< Size = 4 (0x4)                                                            */



/* =========================================================================================================================== */
/* ================                                           HSIOM                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief High Speed IO Matrix (HSIOM) (HSIOM)
  */

typedef struct {                                /*!< (@ 0x40020000) HSIOM Structure                                            */
  __IOM uint32_t  PORT_SEL0;                    /*!< (@ 0x00000000) Port selection register                                    */
  __IM  uint32_t  RESERVED[63];
  __IOM uint32_t  PORT_SEL1;                    /*!< (@ 0x00000100) Port selection register                                    */
  __IM  uint32_t  RESERVED1[63];
  __IOM uint32_t  PORT_SEL2;                    /*!< (@ 0x00000200) Port selection register                                    */
  __IM  uint32_t  RESERVED2[63];
  __IOM uint32_t  PORT_SEL3;                    /*!< (@ 0x00000300) Port selection register                                    */
  __IM  uint32_t  RESERVED3[63];
  __IOM uint32_t  PORT_SEL4;                    /*!< (@ 0x00000400) Port selection register                                    */
  __IM  uint32_t  RESERVED4[1855];
  __IOM uint32_t  AMUX_SPLIT_CTL0;              /*!< (@ 0x00002100) AMUX splitter cell control                                 */
  __IOM uint32_t  AMUX_SPLIT_CTL1;              /*!< (@ 0x00002104) AMUX splitter cell control                                 */
} HSIOM_Type;                                   /*!< Size = 8456 (0x2108)                                                      */



/* =========================================================================================================================== */
/* ================                                          SRSSLT                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief System Resources Lite Subsystem (SRSSLT)
  */

typedef struct {                                /*!< (@ 0x40030000) SRSSLT Structure                                           */
  __IOM uint32_t  PWR_CONTROL;                  /*!< (@ 0x00000000) Power Mode Control                                         */
  __IOM uint32_t  PWR_KEY_DELAY;                /*!< (@ 0x00000004) Power System Key&Delay Register                            */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  PWR_DDFT_SELECT;              /*!< (@ 0x0000000C) Power DDFT Mode Selection Register                         */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  TST_MODE;                     /*!< (@ 0x00000014) Test Mode Control Register                                 */
  __IOM uint32_t  TST_DDFT_CTRL;                /*!< (@ 0x00000018) Digital DFT Control Register                               */
  __IOM uint32_t  TST_TRIM_CNTR1;               /*!< (@ 0x0000001C) IMO trim down-counter and status (clk_sys)                 */
  __IOM uint32_t  TST_TRIM_CNTR2;               /*!< (@ 0x00000020) IMO trim up-counter (ddft)                                 */
  __IOM uint32_t  TST_ADFT_CTRL;                /*!< (@ 0x00000024) ADFT buffer/comparator control register                    */
  __IOM uint32_t  CLK_SELECT;                   /*!< (@ 0x00000028) Clock Select Register                                      */
  __IOM uint32_t  CLK_ILO_CONFIG;               /*!< (@ 0x0000002C) ILO Configuration                                          */
  __IOM uint32_t  CLK_IMO_CONFIG;               /*!< (@ 0x00000030) IMO Configuration                                          */
  __IOM uint32_t  CLK_DFT_SELECT;               /*!< (@ 0x00000034) Clock DFT Mode Selection Register                          */
  __IOM uint32_t  WDT_DISABLE_KEY;              /*!< (@ 0x00000038) Watchdog Disable Key Register                              */
  __IOM uint32_t  WDT_COUNTER;                  /*!< (@ 0x0000003C) Watchdog Counter Register                                  */
  __IOM uint32_t  WDT_MATCH;                    /*!< (@ 0x00000040) Watchdog Match Register                                    */
  __IOM uint32_t  SRSS_INTR;                    /*!< (@ 0x00000044) SRSS Interrupt Register                                    */
  __IOM uint32_t  SRSS_INTR_SET;                /*!< (@ 0x00000048) SRSS Interrupt Set Register                                */
  __IOM uint32_t  SRSS_INTR_MASK;               /*!< (@ 0x0000004C) SRSS Interrupt Mask Register                               */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  RES_CAUSE;                    /*!< (@ 0x00000054) Reset Cause Observation Register                           */
  __IM  uint32_t  RESERVED3[938];
  __IOM uint32_t  PWR_BG_TRIM1;                 /*!< (@ 0x00000F00) Bandgap Trim Register                                      */
  __IOM uint32_t  PWR_BG_TRIM2;                 /*!< (@ 0x00000F04) Bandgap Trim Register                                      */
  __IOM uint32_t  CLK_IMO_SELECT;               /*!< (@ 0x00000F08) IMO Frequency Select Register                              */
  __IOM uint32_t  CLK_IMO_TRIM1;                /*!< (@ 0x00000F0C) IMO Trim Register                                          */
  __IOM uint32_t  CLK_IMO_TRIM2;                /*!< (@ 0x00000F10) IMO Trim Register                                          */
  __IOM uint32_t  PWR_PWRSYS_TRIM1;             /*!< (@ 0x00000F14) Power System Trim Register                                 */
  __IOM uint32_t  CLK_IMO_TRIM3;                /*!< (@ 0x00000F18) IMO Trim Register                                          */
} SRSSLT_Type;                                  /*!< Size = 3868 (0xf1c)                                                       */



/* =========================================================================================================================== */
/* ================                                           GPIO                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO port control/configuration (GPIO)
  */

typedef struct {                                /*!< (@ 0x40041000) GPIO Structure                                             */
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x00000000) Interrupt port cause register                              */
} GPIO_Type;                                    /*!< Size = 4 (0x4)                                                            */



/* =========================================================================================================================== */
/* ================                                         GPIO_PRT0                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO port registers (GPIO_PRT0)
  */

typedef struct {                                /*!< (@ 0x40040000) GPIO_PRT0 Structure                                        */
  __IOM uint32_t  DR;                           /*!< (@ 0x00000000) Port output data register                                  */
  __IOM uint32_t  PS;                           /*!< (@ 0x00000004) Port IO pad state register                                 */
  __IOM uint32_t  PC;                           /*!< (@ 0x00000008) Port configuration register                                */
  __IOM uint32_t  INTR_CFG;                     /*!< (@ 0x0000000C) Port interrupt configuration register                      */
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000010) Port interrupt status register                             */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  PC2;                          /*!< (@ 0x00000018) Port configuration register 2                              */
  __IM  uint32_t  RESERVED1[9];
  __IOM uint32_t  DR_SET;                       /*!< (@ 0x00000040) Port output data set register                              */
  __IOM uint32_t  DR_CLR;                       /*!< (@ 0x00000044) Port output data clear register                            */
  __IOM uint32_t  DR_INV;                       /*!< (@ 0x00000048) Port output data invert register                           */
  __IM  uint32_t  RSVD[45];                     /*!< (@ Reserved till 0xFF                                                     */
} GPIO_PRT0_Type;                               /*!< Size = 256 (0x100)                                                          */



/* =========================================================================================================================== */
/* ================                                         GPIO_PRT1                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO port registers (GPIO_PRT1)
  */

typedef struct {                                /*!< (@ 0x40040100) GPIO_PRT1 Structure                                        */
  __IOM uint32_t  DR;                           /*!< (@ 0x00000000) Port output data register                                  */
  __IOM uint32_t  PS;                           /*!< (@ 0x00000004) Port IO pad state register                                 */
  __IOM uint32_t  PC;                           /*!< (@ 0x00000008) Port configuration register                                */
  __IOM uint32_t  INTR_CFG;                     /*!< (@ 0x0000000C) Port interrupt configuration register                      */
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000010) Port interrupt status register                             */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  PC2;                          /*!< (@ 0x00000018) Port configuration register 2                              */
  __IM  uint32_t  RESERVED1[9];
  __IOM uint32_t  DR_SET;                       /*!< (@ 0x00000040) Port output data set register                              */
  __IOM uint32_t  DR_CLR;                       /*!< (@ 0x00000044) Port output data clear register                            */
  __IOM uint32_t  DR_INV;                       /*!< (@ 0x00000048) Port output data invert register                           */
} GPIO_PRT1_Type;                               /*!< Size = 76 (0x4c)                                                          */



/* =========================================================================================================================== */
/* ================                                         GPIO_PRT2                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO port registers (GPIO_PRT2)
  */

typedef struct {                                /*!< (@ 0x40040200) GPIO_PRT2 Structure                                        */
  __IOM uint32_t  DR;                           /*!< (@ 0x00000000) Port output data register                                  */
  __IOM uint32_t  PS;                           /*!< (@ 0x00000004) Port IO pad state register                                 */
  __IOM uint32_t  PC;                           /*!< (@ 0x00000008) Port configuration register                                */
  __IOM uint32_t  INTR_CFG;                     /*!< (@ 0x0000000C) Port interrupt configuration register                      */
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000010) Port interrupt status register                             */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  PC2;                          /*!< (@ 0x00000018) Port configuration register 2                              */
  __IM  uint32_t  RESERVED1[9];
  __IOM uint32_t  DR_SET;                       /*!< (@ 0x00000040) Port output data set register                              */
  __IOM uint32_t  DR_CLR;                       /*!< (@ 0x00000044) Port output data clear register                            */
  __IOM uint32_t  DR_INV;                       /*!< (@ 0x00000048) Port output data invert register                           */
} GPIO_PRT2_Type;                               /*!< Size = 76 (0x4c)                                                          */



/* =========================================================================================================================== */
/* ================                                         GPIO_PRT3                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO port registers (GPIO_PRT3)
  */

typedef struct {                                /*!< (@ 0x40040300) GPIO_PRT3 Structure                                        */
  __IOM uint32_t  DR;                           /*!< (@ 0x00000000) Port output data register                                  */
  __IOM uint32_t  PS;                           /*!< (@ 0x00000004) Port IO pad state register                                 */
  __IOM uint32_t  PC;                           /*!< (@ 0x00000008) Port configuration register                                */
  __IOM uint32_t  INTR_CFG;                     /*!< (@ 0x0000000C) Port interrupt configuration register                      */
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000010) Port interrupt status register                             */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  PC2;                          /*!< (@ 0x00000018) Port configuration register 2                              */
  __IM  uint32_t  RESERVED1[9];
  __IOM uint32_t  DR_SET;                       /*!< (@ 0x00000040) Port output data set register                              */
  __IOM uint32_t  DR_CLR;                       /*!< (@ 0x00000044) Port output data clear register                            */
  __IOM uint32_t  DR_INV;                       /*!< (@ 0x00000048) Port output data invert register                           */
} GPIO_PRT3_Type;                               /*!< Size = 76 (0x4c)                                                          */



/* =========================================================================================================================== */
/* ================                                         GPIO_PRT4                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO port registers (GPIO_PRT4)
  */

typedef struct {                                /*!< (@ 0x40040400) GPIO_PRT4 Structure                                        */
  __IOM uint32_t  DR;                           /*!< (@ 0x00000000) Port output data register                                  */
  __IOM uint32_t  PS;                           /*!< (@ 0x00000004) Port IO pad state register                                 */
  __IOM uint32_t  PC;                           /*!< (@ 0x00000008) Port configuration register                                */
  __IOM uint32_t  INTR_CFG;                     /*!< (@ 0x0000000C) Port interrupt configuration register                      */
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000010) Port interrupt status register                             */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  PC2;                          /*!< (@ 0x00000018) Port configuration register 2                              */
  __IM  uint32_t  RESERVED1[9];
  __IOM uint32_t  DR_SET;                       /*!< (@ 0x00000040) Port output data set register                              */
  __IOM uint32_t  DR_CLR;                       /*!< (@ 0x00000044) Port output data clear register                            */
  __IOM uint32_t  DR_INV;                       /*!< (@ 0x00000048) Port output data invert register                           */
} GPIO_PRT4_Type;                               /*!< Size = 76 (0x4c)                                                          */



/* =========================================================================================================================== */
/* ================                                        PRGIO_PRT0                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Programmable IO port registers (PRGIO_PRT0)
  */

typedef struct {                                /*!< (@ 0x40050000) PRGIO_PRT0 Structure                                       */
  __IOM uint32_t  CTL;                          /*!< (@ 0x00000000) Control register                                           */
  __IM  uint32_t  RESERVED[3];
  __IOM uint32_t  SYNC_CTL;                     /*!< (@ 0x00000010) Synchronization control register                           */
  __IM  uint32_t  RESERVED1[3];
  __IOM uint32_t  LUT_SEL0;                     /*!< (@ 0x00000020) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL1;                     /*!< (@ 0x00000024) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL2;                     /*!< (@ 0x00000028) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL3;                     /*!< (@ 0x0000002C) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL4;                     /*!< (@ 0x00000030) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL5;                     /*!< (@ 0x00000034) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL6;                     /*!< (@ 0x00000038) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL7;                     /*!< (@ 0x0000003C) LUT component input selection                              */
  __IOM uint32_t  LUT_CTL0;                     /*!< (@ 0x00000040) LUT component control register                             */
  __IOM uint32_t  LUT_CTL1;                     /*!< (@ 0x00000044) LUT component control register                             */
  __IOM uint32_t  LUT_CTL2;                     /*!< (@ 0x00000048) LUT component control register                             */
  __IOM uint32_t  LUT_CTL3;                     /*!< (@ 0x0000004C) LUT component control register                             */
  __IOM uint32_t  LUT_CTL4;                     /*!< (@ 0x00000050) LUT component control register                             */
  __IOM uint32_t  LUT_CTL5;                     /*!< (@ 0x00000054) LUT component control register                             */
  __IOM uint32_t  LUT_CTL6;                     /*!< (@ 0x00000058) LUT component control register                             */
  __IOM uint32_t  LUT_CTL7;                     /*!< (@ 0x0000005C) LUT component control register                             */
  __IM  uint32_t  RESERVED2[24];
  __IOM uint32_t  DU_SEL;                       /*!< (@ 0x000000C0) Data unit component input selection                        */
  __IOM uint32_t  DU_CTL;                       /*!< (@ 0x000000C4) Data unit component control register                       */
  __IM  uint32_t  RESERVED3[10];
  __IOM uint32_t  DATA;                         /*!< (@ 0x000000F0) Data register                                              */
} PRGIO_PRT0_Type;                              /*!< Size = 244 (0xf4)                                                         */



/* =========================================================================================================================== */
/* ================                                        PRGIO_PRT1                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Programmable IO port registers (PRGIO_PRT1)
  */

typedef struct {                                /*!< (@ 0x40050100) PRGIO_PRT1 Structure                                       */
  __IOM uint32_t  CTL;                          /*!< (@ 0x00000000) Control register                                           */
  __IM  uint32_t  RESERVED[3];
  __IOM uint32_t  SYNC_CTL;                     /*!< (@ 0x00000010) Synchronization control register                           */
  __IM  uint32_t  RESERVED1[3];
  __IOM uint32_t  LUT_SEL0;                     /*!< (@ 0x00000020) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL1;                     /*!< (@ 0x00000024) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL2;                     /*!< (@ 0x00000028) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL3;                     /*!< (@ 0x0000002C) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL4;                     /*!< (@ 0x00000030) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL5;                     /*!< (@ 0x00000034) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL6;                     /*!< (@ 0x00000038) LUT component input selection                              */
  __IOM uint32_t  LUT_SEL7;                     /*!< (@ 0x0000003C) LUT component input selection                              */
  __IOM uint32_t  LUT_CTL0;                     /*!< (@ 0x00000040) LUT component control register                             */
  __IOM uint32_t  LUT_CTL1;                     /*!< (@ 0x00000044) LUT component control register                             */
  __IOM uint32_t  LUT_CTL2;                     /*!< (@ 0x00000048) LUT component control register                             */
  __IOM uint32_t  LUT_CTL3;                     /*!< (@ 0x0000004C) LUT component control register                             */
  __IOM uint32_t  LUT_CTL4;                     /*!< (@ 0x00000050) LUT component control register                             */
  __IOM uint32_t  LUT_CTL5;                     /*!< (@ 0x00000054) LUT component control register                             */
  __IOM uint32_t  LUT_CTL6;                     /*!< (@ 0x00000058) LUT component control register                             */
  __IOM uint32_t  LUT_CTL7;                     /*!< (@ 0x0000005C) LUT component control register                             */
  __IM  uint32_t  RESERVED2[24];
  __IOM uint32_t  DU_SEL;                       /*!< (@ 0x000000C0) Data unit component input selection                        */
  __IOM uint32_t  DU_CTL;                       /*!< (@ 0x000000C4) Data unit component control register                       */
  __IM  uint32_t  RESERVED3[10];
  __IOM uint32_t  DATA;                         /*!< (@ 0x000000F0) Data register                                              */
} PRGIO_PRT1_Type;                              /*!< Size = 244 (0xf4)                                                         */



/* =========================================================================================================================== */
/* ================                                           TCPWM                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer/Counter/PWM (TCPWM)
  */

typedef struct {                                /*!< (@ 0x40060000) TCPWM Structure                                            */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) TCPWM control register 0.                                  */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  CMD;                          /*!< (@ 0x00000008) TCPWM command register.                                    */
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x0000000C) TCPWM Counter interrupt cause register.                    */
} TCPWM_Type;                                   /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                        TCPWM_CNT0                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer/Counter/PWM Counter Module (TCPWM_CNT0)
  */

typedef struct {                                /*!< (@ 0x40060100) TCPWM_CNT0 Structure                                       */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Counter control register                                   */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Counter status register                                    */
  __IOM uint32_t  COUNTER;                      /*!< (@ 0x00000008) Counter count register                                     */
  __IOM uint32_t  CC;                           /*!< (@ 0x0000000C) Counter compare/capture register                           */
  __IOM uint32_t  CC_BUFF;                      /*!< (@ 0x00000010) Counter buffered compare/capture register                  */
  __IOM uint32_t  PERIOD;                       /*!< (@ 0x00000014) Counter period register                                    */
  __IOM uint32_t  PERIOD_BUFF;                  /*!< (@ 0x00000018) Counter buffered period register                           */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  TR_CTRL0;                     /*!< (@ 0x00000020) Counter trigger control register 0                         */
  __IOM uint32_t  TR_CTRL1;                     /*!< (@ 0x00000024) Counter trigger control register 1                         */
  __IOM uint32_t  TR_CTRL2;                     /*!< (@ 0x00000028) Counter trigger control register 2                         */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000030) Interrupt request register.                                */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000034) Interrupt set request register.                            */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000038) Interrupt mask register.                                   */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000003C) Interrupt masked request register                          */
} TCPWM_CNT0_Type;                              /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                        TCPWM_CNT1                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer/Counter/PWM Counter Module (TCPWM_CNT1)
  */

typedef struct {                                /*!< (@ 0x40060140) TCPWM_CNT1 Structure                                       */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Counter control register                                   */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Counter status register                                    */
  __IOM uint32_t  COUNTER;                      /*!< (@ 0x00000008) Counter count register                                     */
  __IOM uint32_t  CC;                           /*!< (@ 0x0000000C) Counter compare/capture register                           */
  __IOM uint32_t  CC_BUFF;                      /*!< (@ 0x00000010) Counter buffered compare/capture register                  */
  __IOM uint32_t  PERIOD;                       /*!< (@ 0x00000014) Counter period register                                    */
  __IOM uint32_t  PERIOD_BUFF;                  /*!< (@ 0x00000018) Counter buffered period register                           */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  TR_CTRL0;                     /*!< (@ 0x00000020) Counter trigger control register 0                         */
  __IOM uint32_t  TR_CTRL1;                     /*!< (@ 0x00000024) Counter trigger control register 1                         */
  __IOM uint32_t  TR_CTRL2;                     /*!< (@ 0x00000028) Counter trigger control register 2                         */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000030) Interrupt request register.                                */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000034) Interrupt set request register.                            */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000038) Interrupt mask register.                                   */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000003C) Interrupt masked request register                          */
} TCPWM_CNT1_Type;                              /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                        TCPWM_CNT2                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer/Counter/PWM Counter Module (TCPWM_CNT2)
  */

typedef struct {                                /*!< (@ 0x40060180) TCPWM_CNT2 Structure                                       */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Counter control register                                   */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Counter status register                                    */
  __IOM uint32_t  COUNTER;                      /*!< (@ 0x00000008) Counter count register                                     */
  __IOM uint32_t  CC;                           /*!< (@ 0x0000000C) Counter compare/capture register                           */
  __IOM uint32_t  CC_BUFF;                      /*!< (@ 0x00000010) Counter buffered compare/capture register                  */
  __IOM uint32_t  PERIOD;                       /*!< (@ 0x00000014) Counter period register                                    */
  __IOM uint32_t  PERIOD_BUFF;                  /*!< (@ 0x00000018) Counter buffered period register                           */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  TR_CTRL0;                     /*!< (@ 0x00000020) Counter trigger control register 0                         */
  __IOM uint32_t  TR_CTRL1;                     /*!< (@ 0x00000024) Counter trigger control register 1                         */
  __IOM uint32_t  TR_CTRL2;                     /*!< (@ 0x00000028) Counter trigger control register 2                         */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000030) Interrupt request register.                                */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000034) Interrupt set request register.                            */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000038) Interrupt mask register.                                   */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000003C) Interrupt masked request register                          */
} TCPWM_CNT2_Type;                              /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                        TCPWM_CNT3                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer/Counter/PWM Counter Module (TCPWM_CNT3)
  */

typedef struct {                                /*!< (@ 0x400601C0) TCPWM_CNT3 Structure                                       */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Counter control register                                   */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Counter status register                                    */
  __IOM uint32_t  COUNTER;                      /*!< (@ 0x00000008) Counter count register                                     */
  __IOM uint32_t  CC;                           /*!< (@ 0x0000000C) Counter compare/capture register                           */
  __IOM uint32_t  CC_BUFF;                      /*!< (@ 0x00000010) Counter buffered compare/capture register                  */
  __IOM uint32_t  PERIOD;                       /*!< (@ 0x00000014) Counter period register                                    */
  __IOM uint32_t  PERIOD_BUFF;                  /*!< (@ 0x00000018) Counter buffered period register                           */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  TR_CTRL0;                     /*!< (@ 0x00000020) Counter trigger control register 0                         */
  __IOM uint32_t  TR_CTRL1;                     /*!< (@ 0x00000024) Counter trigger control register 1                         */
  __IOM uint32_t  TR_CTRL2;                     /*!< (@ 0x00000028) Counter trigger control register 2                         */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000030) Interrupt request register.                                */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000034) Interrupt set request register.                            */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000038) Interrupt mask register.                                   */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000003C) Interrupt masked request register                          */
} TCPWM_CNT3_Type;                              /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                        TCPWM_CNT4                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer/Counter/PWM Counter Module (TCPWM_CNT4)
  */

typedef struct {                                /*!< (@ 0x40060200) TCPWM_CNT4 Structure                                       */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Counter control register                                   */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Counter status register                                    */
  __IOM uint32_t  COUNTER;                      /*!< (@ 0x00000008) Counter count register                                     */
  __IOM uint32_t  CC;                           /*!< (@ 0x0000000C) Counter compare/capture register                           */
  __IOM uint32_t  CC_BUFF;                      /*!< (@ 0x00000010) Counter buffered compare/capture register                  */
  __IOM uint32_t  PERIOD;                       /*!< (@ 0x00000014) Counter period register                                    */
  __IOM uint32_t  PERIOD_BUFF;                  /*!< (@ 0x00000018) Counter buffered period register                           */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  TR_CTRL0;                     /*!< (@ 0x00000020) Counter trigger control register 0                         */
  __IOM uint32_t  TR_CTRL1;                     /*!< (@ 0x00000024) Counter trigger control register 1                         */
  __IOM uint32_t  TR_CTRL2;                     /*!< (@ 0x00000028) Counter trigger control register 2                         */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000030) Interrupt request register.                                */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000034) Interrupt set request register.                            */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000038) Interrupt mask register.                                   */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000003C) Interrupt masked request register                          */
} TCPWM_CNT4_Type;                              /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                            WCO                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief 32KHz Oscillator (WCO)
  */

typedef struct {                                /*!< (@ 0x40070000) WCO Structure                                              */
  __IOM uint32_t  CONFIG;                       /*!< (@ 0x00000000) WCO Configuration Register                                 */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) WCO Status Register                                        */
  __IOM uint32_t  DPLL;                         /*!< (@ 0x00000008) WCO DPLL Register                                          */
  __IM  uint32_t  RESERVED[125];
  __IOM uint32_t  WDT_CTRLOW;                   /*!< (@ 0x00000200) Watchdog Counters 0/1                                      */
  __IOM uint32_t  WDT_CTRHIGH;                  /*!< (@ 0x00000204) Watchdog Counter 2                                         */
  __IOM uint32_t  WDT_MATCH;                    /*!< (@ 0x00000208) Watchdog counter match values                              */
  __IOM uint32_t  WDT_CONFIG;                   /*!< (@ 0x0000020C) Watchdog Counters Configuration                            */
  __IOM uint32_t  WDT_CONTROL;                  /*!< (@ 0x00000210) Watchdog Counters Control                                  */
  __IOM uint32_t  WDT_CLKEN;                    /*!< (@ 0x00000214) Watchdog Counters Clock Enable                             */
  __IM  uint32_t  RESERVED1[826];
  __IOM uint32_t  TRIM;                         /*!< (@ 0x00000F00) WCO Trim Register                                          */
} WCO_Type;                                     /*!< Size = 3844 (0xf04)                                                       */



/* =========================================================================================================================== */
/* ================                                           SCB0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Serial Communications Block (SPI/UART/I2C) (SCB0)
  */

typedef struct {                                /*!< (@ 0x40080000) SCB0 Structure                                             */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Generic control register.                                  */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Generic status register.                                   */
  __IM  uint32_t  RESERVED[6];
  __IOM uint32_t  SPI_CTRL;                     /*!< (@ 0x00000020) SPI control register.                                      */
  __IOM uint32_t  SPI_STATUS;                   /*!< (@ 0x00000024) SPI status register.                                       */
  __IM  uint32_t  RESERVED1[6];
  __IOM uint32_t  UART_CTRL;                    /*!< (@ 0x00000040) UART control register.                                     */
  __IOM uint32_t  UART_TX_CTRL;                 /*!< (@ 0x00000044) UART transmitter control register.                         */
  __IOM uint32_t  UART_RX_CTRL;                 /*!< (@ 0x00000048) UART receiver control register.                            */
  __IOM uint32_t  UART_RX_STATUS;               /*!< (@ 0x0000004C) UART receiver status register.                             */
  __IOM uint32_t  UART_FLOW_CTRL;               /*!< (@ 0x00000050) UART flow control register                                 */
  __IM  uint32_t  RESERVED2[3];
  __IOM uint32_t  I2C_CTRL;                     /*!< (@ 0x00000060) I2C control register.                                      */
  __IOM uint32_t  I2C_STATUS;                   /*!< (@ 0x00000064) I2C status register.                                       */
  __IOM uint32_t  I2C_M_CMD;                    /*!< (@ 0x00000068) I2C master command register.                               */
  __IOM uint32_t  I2C_S_CMD;                    /*!< (@ 0x0000006C) I2C slave command register.                                */
  __IOM uint32_t  I2C_CFG;                      /*!< (@ 0x00000070) I2C configuration register.                                */
  __IM  uint32_t  RESERVED3[99];
  __IOM uint32_t  TX_CTRL;                      /*!< (@ 0x00000200) Transmitter control register.                              */
  __IOM uint32_t  TX_FIFO_CTRL;                 /*!< (@ 0x00000204) Transmitter FIFO control register.                         */
  __IOM uint32_t  TX_FIFO_STATUS;               /*!< (@ 0x00000208) Transmitter FIFO status register.                          */
  __IM  uint32_t  RESERVED4[13];
  __IOM uint32_t  TX_FIFO_WR;                   /*!< (@ 0x00000240) Transmitter FIFO write register.                           */
  __IM  uint32_t  RESERVED5[47];
  __IOM uint32_t  RX_CTRL;                      /*!< (@ 0x00000300) Receiver control register.                                 */
  __IOM uint32_t  RX_FIFO_CTRL;                 /*!< (@ 0x00000304) Receiver FIFO control register.                            */
  __IOM uint32_t  RX_FIFO_STATUS;               /*!< (@ 0x00000308) Receiver FIFO status register.                             */
  __IM  uint32_t  RESERVED6;
  __IOM uint32_t  RX_MATCH;                     /*!< (@ 0x00000310) Slave address and mask register.                           */
  __IM  uint32_t  RESERVED7[11];
  __IOM uint32_t  RX_FIFO_RD;                   /*!< (@ 0x00000340) Receiver FIFO read register.                               */
  __IOM uint32_t  RX_FIFO_RD_SILENT;            /*!< (@ 0x00000344) Receiver FIFO read register.                               */
  __IM  uint32_t  RESERVED8[46];
  __IOM uint32_t  EZ_DATA0;                     /*!< (@ 0x00000400) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA1;                     /*!< (@ 0x00000404) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA2;                     /*!< (@ 0x00000408) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA3;                     /*!< (@ 0x0000040C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA4;                     /*!< (@ 0x00000410) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA5;                     /*!< (@ 0x00000414) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA6;                     /*!< (@ 0x00000418) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA7;                     /*!< (@ 0x0000041C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA8;                     /*!< (@ 0x00000420) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA9;                     /*!< (@ 0x00000424) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA10;                    /*!< (@ 0x00000428) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA11;                    /*!< (@ 0x0000042C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA12;                    /*!< (@ 0x00000430) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA13;                    /*!< (@ 0x00000434) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA14;                    /*!< (@ 0x00000438) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA15;                    /*!< (@ 0x0000043C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA16;                    /*!< (@ 0x00000440) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA17;                    /*!< (@ 0x00000444) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA18;                    /*!< (@ 0x00000448) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA19;                    /*!< (@ 0x0000044C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA20;                    /*!< (@ 0x00000450) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA21;                    /*!< (@ 0x00000454) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA22;                    /*!< (@ 0x00000458) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA23;                    /*!< (@ 0x0000045C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA24;                    /*!< (@ 0x00000460) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA25;                    /*!< (@ 0x00000464) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA26;                    /*!< (@ 0x00000468) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA27;                    /*!< (@ 0x0000046C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA28;                    /*!< (@ 0x00000470) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA29;                    /*!< (@ 0x00000474) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA30;                    /*!< (@ 0x00000478) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA31;                    /*!< (@ 0x0000047C) Memory buffer registers.                                   */
  __IM  uint32_t  RESERVED9[608];
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x00000E00) Active clocked interrupt signal register                   */
  __IM  uint32_t  RESERVED10[31];
  __IOM uint32_t  INTR_I2C_EC;                  /*!< (@ 0x00000E80) Externally clocked I2C interrupt request register          */
  __IM  uint32_t  RESERVED11;
  __IOM uint32_t  INTR_I2C_EC_MASK;             /*!< (@ 0x00000E88) Externally clocked I2C interrupt mask register             */
  __IOM uint32_t  INTR_I2C_EC_MASKED;           /*!< (@ 0x00000E8C) Externally clocked I2C interrupt masked register           */
  __IM  uint32_t  RESERVED12[12];
  __IOM uint32_t  INTR_SPI_EC;                  /*!< (@ 0x00000EC0) Externally clocked SPI interrupt request register          */
  __IM  uint32_t  RESERVED13;
  __IOM uint32_t  INTR_SPI_EC_MASK;             /*!< (@ 0x00000EC8) Externally clocked SPI interrupt mask register             */
  __IOM uint32_t  INTR_SPI_EC_MASKED;           /*!< (@ 0x00000ECC) Externally clocked SPI interrupt masked register           */
  __IM  uint32_t  RESERVED14[12];
  __IOM uint32_t  INTR_M;                       /*!< (@ 0x00000F00) Master interrupt request register.                         */
  __IOM uint32_t  INTR_M_SET;                   /*!< (@ 0x00000F04) Master interrupt set request register                      */
  __IOM uint32_t  INTR_M_MASK;                  /*!< (@ 0x00000F08) Master interrupt mask register.                            */
  __IOM uint32_t  INTR_M_MASKED;                /*!< (@ 0x00000F0C) Master interrupt masked request register                   */
  __IM  uint32_t  RESERVED15[12];
  __IOM uint32_t  INTR_S;                       /*!< (@ 0x00000F40) Slave interrupt request register.                          */
  __IOM uint32_t  INTR_S_SET;                   /*!< (@ 0x00000F44) Slave interrupt set request register.                      */
  __IOM uint32_t  INTR_S_MASK;                  /*!< (@ 0x00000F48) Slave interrupt mask register.                             */
  __IOM uint32_t  INTR_S_MASKED;                /*!< (@ 0x00000F4C) Slave interrupt masked request register                    */
  __IM  uint32_t  RESERVED16[12];
  __IOM uint32_t  INTR_TX;                      /*!< (@ 0x00000F80) Transmitter interrupt request register.                    */
  __IOM uint32_t  INTR_TX_SET;                  /*!< (@ 0x00000F84) Transmitter interrupt set request register                 */
  __IOM uint32_t  INTR_TX_MASK;                 /*!< (@ 0x00000F88) Transmitter interrupt mask register.                       */
  __IOM uint32_t  INTR_TX_MASKED;               /*!< (@ 0x00000F8C) Transmitter interrupt masked request register              */
  __IM  uint32_t  RESERVED17[12];
  __IOM uint32_t  INTR_RX;                      /*!< (@ 0x00000FC0) Receiver interrupt request register.                       */
  __IOM uint32_t  INTR_RX_SET;                  /*!< (@ 0x00000FC4) Receiver interrupt set request register.                   */
  __IOM uint32_t  INTR_RX_MASK;                 /*!< (@ 0x00000FC8) Receiver interrupt mask register.                          */
  __IOM uint32_t  INTR_RX_MASKED;               /*!< (@ 0x00000FCC) Receiver interrupt masked request register                 */
} SCB0_Type;                                    /*!< Size = 4048 (0xfd0)                                                       */



/* =========================================================================================================================== */
/* ================                                           SCB1                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Serial Communications Block (SPI/UART/I2C) (SCB1)
  */

typedef struct {                                /*!< (@ 0x40090000) SCB1 Structure                                             */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Generic control register.                                  */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Generic status register.                                   */
  __IM  uint32_t  RESERVED[6];
  __IOM uint32_t  SPI_CTRL;                     /*!< (@ 0x00000020) SPI control register.                                      */
  __IOM uint32_t  SPI_STATUS;                   /*!< (@ 0x00000024) SPI status register.                                       */
  __IM  uint32_t  RESERVED1[6];
  __IOM uint32_t  UART_CTRL;                    /*!< (@ 0x00000040) UART control register.                                     */
  __IOM uint32_t  UART_TX_CTRL;                 /*!< (@ 0x00000044) UART transmitter control register.                         */
  __IOM uint32_t  UART_RX_CTRL;                 /*!< (@ 0x00000048) UART receiver control register.                            */
  __IOM uint32_t  UART_RX_STATUS;               /*!< (@ 0x0000004C) UART receiver status register.                             */
  __IOM uint32_t  UART_FLOW_CTRL;               /*!< (@ 0x00000050) UART flow control register                                 */
  __IM  uint32_t  RESERVED2[3];
  __IOM uint32_t  I2C_CTRL;                     /*!< (@ 0x00000060) I2C control register.                                      */
  __IOM uint32_t  I2C_STATUS;                   /*!< (@ 0x00000064) I2C status register.                                       */
  __IOM uint32_t  I2C_M_CMD;                    /*!< (@ 0x00000068) I2C master command register.                               */
  __IOM uint32_t  I2C_S_CMD;                    /*!< (@ 0x0000006C) I2C slave command register.                                */
  __IOM uint32_t  I2C_CFG;                      /*!< (@ 0x00000070) I2C configuration register.                                */
  __IM  uint32_t  RESERVED3[99];
  __IOM uint32_t  TX_CTRL;                      /*!< (@ 0x00000200) Transmitter control register.                              */
  __IOM uint32_t  TX_FIFO_CTRL;                 /*!< (@ 0x00000204) Transmitter FIFO control register.                         */
  __IOM uint32_t  TX_FIFO_STATUS;               /*!< (@ 0x00000208) Transmitter FIFO status register.                          */
  __IM  uint32_t  RESERVED4[13];
  __IOM uint32_t  TX_FIFO_WR;                   /*!< (@ 0x00000240) Transmitter FIFO write register.                           */
  __IM  uint32_t  RESERVED5[47];
  __IOM uint32_t  RX_CTRL;                      /*!< (@ 0x00000300) Receiver control register.                                 */
  __IOM uint32_t  RX_FIFO_CTRL;                 /*!< (@ 0x00000304) Receiver FIFO control register.                            */
  __IOM uint32_t  RX_FIFO_STATUS;               /*!< (@ 0x00000308) Receiver FIFO status register.                             */
  __IM  uint32_t  RESERVED6;
  __IOM uint32_t  RX_MATCH;                     /*!< (@ 0x00000310) Slave address and mask register.                           */
  __IM  uint32_t  RESERVED7[11];
  __IOM uint32_t  RX_FIFO_RD;                   /*!< (@ 0x00000340) Receiver FIFO read register.                               */
  __IOM uint32_t  RX_FIFO_RD_SILENT;            /*!< (@ 0x00000344) Receiver FIFO read register.                               */
  __IM  uint32_t  RESERVED8[46];
  __IOM uint32_t  EZ_DATA0;                     /*!< (@ 0x00000400) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA1;                     /*!< (@ 0x00000404) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA2;                     /*!< (@ 0x00000408) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA3;                     /*!< (@ 0x0000040C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA4;                     /*!< (@ 0x00000410) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA5;                     /*!< (@ 0x00000414) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA6;                     /*!< (@ 0x00000418) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA7;                     /*!< (@ 0x0000041C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA8;                     /*!< (@ 0x00000420) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA9;                     /*!< (@ 0x00000424) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA10;                    /*!< (@ 0x00000428) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA11;                    /*!< (@ 0x0000042C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA12;                    /*!< (@ 0x00000430) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA13;                    /*!< (@ 0x00000434) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA14;                    /*!< (@ 0x00000438) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA15;                    /*!< (@ 0x0000043C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA16;                    /*!< (@ 0x00000440) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA17;                    /*!< (@ 0x00000444) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA18;                    /*!< (@ 0x00000448) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA19;                    /*!< (@ 0x0000044C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA20;                    /*!< (@ 0x00000450) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA21;                    /*!< (@ 0x00000454) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA22;                    /*!< (@ 0x00000458) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA23;                    /*!< (@ 0x0000045C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA24;                    /*!< (@ 0x00000460) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA25;                    /*!< (@ 0x00000464) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA26;                    /*!< (@ 0x00000468) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA27;                    /*!< (@ 0x0000046C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA28;                    /*!< (@ 0x00000470) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA29;                    /*!< (@ 0x00000474) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA30;                    /*!< (@ 0x00000478) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA31;                    /*!< (@ 0x0000047C) Memory buffer registers.                                   */
  __IM  uint32_t  RESERVED9[608];
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x00000E00) Active clocked interrupt signal register                   */
  __IM  uint32_t  RESERVED10[31];
  __IOM uint32_t  INTR_I2C_EC;                  /*!< (@ 0x00000E80) Externally clocked I2C interrupt request register          */
  __IM  uint32_t  RESERVED11;
  __IOM uint32_t  INTR_I2C_EC_MASK;             /*!< (@ 0x00000E88) Externally clocked I2C interrupt mask register             */
  __IOM uint32_t  INTR_I2C_EC_MASKED;           /*!< (@ 0x00000E8C) Externally clocked I2C interrupt masked register           */
  __IM  uint32_t  RESERVED12[12];
  __IOM uint32_t  INTR_SPI_EC;                  /*!< (@ 0x00000EC0) Externally clocked SPI interrupt request register          */
  __IM  uint32_t  RESERVED13;
  __IOM uint32_t  INTR_SPI_EC_MASK;             /*!< (@ 0x00000EC8) Externally clocked SPI interrupt mask register             */
  __IOM uint32_t  INTR_SPI_EC_MASKED;           /*!< (@ 0x00000ECC) Externally clocked SPI interrupt masked register           */
  __IM  uint32_t  RESERVED14[12];
  __IOM uint32_t  INTR_M;                       /*!< (@ 0x00000F00) Master interrupt request register.                         */
  __IOM uint32_t  INTR_M_SET;                   /*!< (@ 0x00000F04) Master interrupt set request register                      */
  __IOM uint32_t  INTR_M_MASK;                  /*!< (@ 0x00000F08) Master interrupt mask register.                            */
  __IOM uint32_t  INTR_M_MASKED;                /*!< (@ 0x00000F0C) Master interrupt masked request register                   */
  __IM  uint32_t  RESERVED15[12];
  __IOM uint32_t  INTR_S;                       /*!< (@ 0x00000F40) Slave interrupt request register.                          */
  __IOM uint32_t  INTR_S_SET;                   /*!< (@ 0x00000F44) Slave interrupt set request register.                      */
  __IOM uint32_t  INTR_S_MASK;                  /*!< (@ 0x00000F48) Slave interrupt mask register.                             */
  __IOM uint32_t  INTR_S_MASKED;                /*!< (@ 0x00000F4C) Slave interrupt masked request register                    */
  __IM  uint32_t  RESERVED16[12];
  __IOM uint32_t  INTR_TX;                      /*!< (@ 0x00000F80) Transmitter interrupt request register.                    */
  __IOM uint32_t  INTR_TX_SET;                  /*!< (@ 0x00000F84) Transmitter interrupt set request register                 */
  __IOM uint32_t  INTR_TX_MASK;                 /*!< (@ 0x00000F88) Transmitter interrupt mask register.                       */
  __IOM uint32_t  INTR_TX_MASKED;               /*!< (@ 0x00000F8C) Transmitter interrupt masked request register              */
  __IM  uint32_t  RESERVED17[12];
  __IOM uint32_t  INTR_RX;                      /*!< (@ 0x00000FC0) Receiver interrupt request register.                       */
  __IOM uint32_t  INTR_RX_SET;                  /*!< (@ 0x00000FC4) Receiver interrupt set request register.                   */
  __IOM uint32_t  INTR_RX_MASK;                 /*!< (@ 0x00000FC8) Receiver interrupt mask register.                          */
  __IOM uint32_t  INTR_RX_MASKED;               /*!< (@ 0x00000FCC) Receiver interrupt masked request register                 */
} SCB1_Type;                                    /*!< Size = 4048 (0xfd0)                                                       */



/* =========================================================================================================================== */
/* ================                                           SCB2                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Serial Communications Block (SPI/UART/I2C) (SCB2)
  */

typedef struct {                                /*!< (@ 0x400A0000) SCB2 Structure                                             */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Generic control register.                                  */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000004) Generic status register.                                   */
  __IM  uint32_t  RESERVED[6];
  __IOM uint32_t  SPI_CTRL;                     /*!< (@ 0x00000020) SPI control register.                                      */
  __IOM uint32_t  SPI_STATUS;                   /*!< (@ 0x00000024) SPI status register.                                       */
  __IM  uint32_t  RESERVED1[6];
  __IOM uint32_t  UART_CTRL;                    /*!< (@ 0x00000040) UART control register.                                     */
  __IOM uint32_t  UART_TX_CTRL;                 /*!< (@ 0x00000044) UART transmitter control register.                         */
  __IOM uint32_t  UART_RX_CTRL;                 /*!< (@ 0x00000048) UART receiver control register.                            */
  __IOM uint32_t  UART_RX_STATUS;               /*!< (@ 0x0000004C) UART receiver status register.                             */
  __IOM uint32_t  UART_FLOW_CTRL;               /*!< (@ 0x00000050) UART flow control register                                 */
  __IM  uint32_t  RESERVED2[3];
  __IOM uint32_t  I2C_CTRL;                     /*!< (@ 0x00000060) I2C control register.                                      */
  __IOM uint32_t  I2C_STATUS;                   /*!< (@ 0x00000064) I2C status register.                                       */
  __IOM uint32_t  I2C_M_CMD;                    /*!< (@ 0x00000068) I2C master command register.                               */
  __IOM uint32_t  I2C_S_CMD;                    /*!< (@ 0x0000006C) I2C slave command register.                                */
  __IOM uint32_t  I2C_CFG;                      /*!< (@ 0x00000070) I2C configuration register.                                */
  __IM  uint32_t  RESERVED3[99];
  __IOM uint32_t  TX_CTRL;                      /*!< (@ 0x00000200) Transmitter control register.                              */
  __IOM uint32_t  TX_FIFO_CTRL;                 /*!< (@ 0x00000204) Transmitter FIFO control register.                         */
  __IOM uint32_t  TX_FIFO_STATUS;               /*!< (@ 0x00000208) Transmitter FIFO status register.                          */
  __IM  uint32_t  RESERVED4[13];
  __IOM uint32_t  TX_FIFO_WR;                   /*!< (@ 0x00000240) Transmitter FIFO write register.                           */
  __IM  uint32_t  RESERVED5[47];
  __IOM uint32_t  RX_CTRL;                      /*!< (@ 0x00000300) Receiver control register.                                 */
  __IOM uint32_t  RX_FIFO_CTRL;                 /*!< (@ 0x00000304) Receiver FIFO control register.                            */
  __IOM uint32_t  RX_FIFO_STATUS;               /*!< (@ 0x00000308) Receiver FIFO status register.                             */
  __IM  uint32_t  RESERVED6;
  __IOM uint32_t  RX_MATCH;                     /*!< (@ 0x00000310) Slave address and mask register.                           */
  __IM  uint32_t  RESERVED7[11];
  __IOM uint32_t  RX_FIFO_RD;                   /*!< (@ 0x00000340) Receiver FIFO read register.                               */
  __IOM uint32_t  RX_FIFO_RD_SILENT;            /*!< (@ 0x00000344) Receiver FIFO read register.                               */
  __IM  uint32_t  RESERVED8[46];
  __IOM uint32_t  EZ_DATA0;                     /*!< (@ 0x00000400) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA1;                     /*!< (@ 0x00000404) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA2;                     /*!< (@ 0x00000408) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA3;                     /*!< (@ 0x0000040C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA4;                     /*!< (@ 0x00000410) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA5;                     /*!< (@ 0x00000414) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA6;                     /*!< (@ 0x00000418) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA7;                     /*!< (@ 0x0000041C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA8;                     /*!< (@ 0x00000420) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA9;                     /*!< (@ 0x00000424) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA10;                    /*!< (@ 0x00000428) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA11;                    /*!< (@ 0x0000042C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA12;                    /*!< (@ 0x00000430) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA13;                    /*!< (@ 0x00000434) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA14;                    /*!< (@ 0x00000438) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA15;                    /*!< (@ 0x0000043C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA16;                    /*!< (@ 0x00000440) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA17;                    /*!< (@ 0x00000444) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA18;                    /*!< (@ 0x00000448) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA19;                    /*!< (@ 0x0000044C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA20;                    /*!< (@ 0x00000450) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA21;                    /*!< (@ 0x00000454) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA22;                    /*!< (@ 0x00000458) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA23;                    /*!< (@ 0x0000045C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA24;                    /*!< (@ 0x00000460) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA25;                    /*!< (@ 0x00000464) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA26;                    /*!< (@ 0x00000468) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA27;                    /*!< (@ 0x0000046C) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA28;                    /*!< (@ 0x00000470) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA29;                    /*!< (@ 0x00000474) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA30;                    /*!< (@ 0x00000478) Memory buffer registers.                                   */
  __IOM uint32_t  EZ_DATA31;                    /*!< (@ 0x0000047C) Memory buffer registers.                                   */
  __IM  uint32_t  RESERVED9[608];
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x00000E00) Active clocked interrupt signal register                   */
  __IM  uint32_t  RESERVED10[31];
  __IOM uint32_t  INTR_I2C_EC;                  /*!< (@ 0x00000E80) Externally clocked I2C interrupt request register          */
  __IM  uint32_t  RESERVED11;
  __IOM uint32_t  INTR_I2C_EC_MASK;             /*!< (@ 0x00000E88) Externally clocked I2C interrupt mask register             */
  __IOM uint32_t  INTR_I2C_EC_MASKED;           /*!< (@ 0x00000E8C) Externally clocked I2C interrupt masked register           */
  __IM  uint32_t  RESERVED12[12];
  __IOM uint32_t  INTR_SPI_EC;                  /*!< (@ 0x00000EC0) Externally clocked SPI interrupt request register          */
  __IM  uint32_t  RESERVED13;
  __IOM uint32_t  INTR_SPI_EC_MASK;             /*!< (@ 0x00000EC8) Externally clocked SPI interrupt mask register             */
  __IOM uint32_t  INTR_SPI_EC_MASKED;           /*!< (@ 0x00000ECC) Externally clocked SPI interrupt masked register           */
  __IM  uint32_t  RESERVED14[12];
  __IOM uint32_t  INTR_M;                       /*!< (@ 0x00000F00) Master interrupt request register.                         */
  __IOM uint32_t  INTR_M_SET;                   /*!< (@ 0x00000F04) Master interrupt set request register                      */
  __IOM uint32_t  INTR_M_MASK;                  /*!< (@ 0x00000F08) Master interrupt mask register.                            */
  __IOM uint32_t  INTR_M_MASKED;                /*!< (@ 0x00000F0C) Master interrupt masked request register                   */
  __IM  uint32_t  RESERVED15[12];
  __IOM uint32_t  INTR_S;                       /*!< (@ 0x00000F40) Slave interrupt request register.                          */
  __IOM uint32_t  INTR_S_SET;                   /*!< (@ 0x00000F44) Slave interrupt set request register.                      */
  __IOM uint32_t  INTR_S_MASK;                  /*!< (@ 0x00000F48) Slave interrupt mask register.                             */
  __IOM uint32_t  INTR_S_MASKED;                /*!< (@ 0x00000F4C) Slave interrupt masked request register                    */
  __IM  uint32_t  RESERVED16[12];
  __IOM uint32_t  INTR_TX;                      /*!< (@ 0x00000F80) Transmitter interrupt request register.                    */
  __IOM uint32_t  INTR_TX_SET;                  /*!< (@ 0x00000F84) Transmitter interrupt set request register                 */
  __IOM uint32_t  INTR_TX_MASK;                 /*!< (@ 0x00000F88) Transmitter interrupt mask register.                       */
  __IOM uint32_t  INTR_TX_MASKED;               /*!< (@ 0x00000F8C) Transmitter interrupt masked request register              */
  __IM  uint32_t  RESERVED17[12];
  __IOM uint32_t  INTR_RX;                      /*!< (@ 0x00000FC0) Receiver interrupt request register.                       */
  __IOM uint32_t  INTR_RX_SET;                  /*!< (@ 0x00000FC4) Receiver interrupt set request register.                   */
  __IOM uint32_t  INTR_RX_MASK;                 /*!< (@ 0x00000FC8) Receiver interrupt mask register.                          */
  __IOM uint32_t  INTR_RX_MASKED;               /*!< (@ 0x00000FCC) Receiver interrupt masked request register                 */
} SCB2_Type;                                    /*!< Size = 4048 (0xfd0)                                                       */



/* =========================================================================================================================== */
/* ================                                            LCD                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief LCD Controller Block (LCD)
  */

typedef struct {                                /*!< (@ 0x400B0000) LCD Structure                                              */
  __IOM uint32_t  ID;                           /*!< (@ 0x00000000) ID & Revision                                              */
  __IOM uint32_t  DIVIDER;                      /*!< (@ 0x00000004) LCD Divider Register                                       */
  __IOM uint32_t  CONTROL;                      /*!< (@ 0x00000008) LCD Configuration Register                                 */
  __IM  uint32_t  RESERVED[61];
  __IOM uint32_t  DATA00;                       /*!< (@ 0x00000100) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA01;                       /*!< (@ 0x00000104) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA02;                       /*!< (@ 0x00000108) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA03;                       /*!< (@ 0x0000010C) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA04;                       /*!< (@ 0x00000110) LCD Pin Data Registers                                     */
  __IM  uint32_t  RESERVED1[59];
  __IOM uint32_t  DATA10;                       /*!< (@ 0x00000200) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA11;                       /*!< (@ 0x00000204) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA12;                       /*!< (@ 0x00000208) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA13;                       /*!< (@ 0x0000020C) LCD Pin Data Registers                                     */
  __IOM uint32_t  DATA14;                       /*!< (@ 0x00000210) LCD Pin Data Registers                                     */
} LCD_Type;                                     /*!< Size = 532 (0x214)                                                        */



/* =========================================================================================================================== */
/* ================                                            CSD                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Capsense Controller (CSD)
  */

typedef struct {                                /*!< (@ 0x400C0000) CSD Structure                                              */
  __IOM uint32_t  CONFIG;                       /*!< (@ 0x00000000) Configuration and Control                                  */
  __IOM uint32_t  SPARE;                        /*!< (@ 0x00000004) Spare MMIO                                                 */
  __IM  uint32_t  RESERVED[30];
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000080) Status Register                                            */
  __IOM uint32_t  STAT_SEQ;                     /*!< (@ 0x00000084) Current Sequencer status                                   */
  __IOM uint32_t  STAT_CNTS;                    /*!< (@ 0x00000088) Current status counts                                      */
  __IM  uint32_t  RESERVED1[17];
  __IOM uint32_t  RESULT_VAL1;                  /*!< (@ 0x000000D0) Result CSD/CSX accumulation counter value 1                */
  __IOM uint32_t  RESULT_VAL2;                  /*!< (@ 0x000000D4) Result CSX accumulation counter value 2                    */
  __IM  uint32_t  RESERVED2[2];
  __IOM uint32_t  ADC_RES;                      /*!< (@ 0x000000E0) ADC measurement                                            */
  __IM  uint32_t  RESERVED3[3];
  __IOM uint32_t  INTR;                         /*!< (@ 0x000000F0) CSD Interrupt Request Register                             */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x000000F4) CSD Interrupt set register                                 */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x000000F8) CSD Interrupt mask register                                */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x000000FC) CSD Interrupt masked register                              */
  __IM  uint32_t  RESERVED4[32];
  __IOM uint32_t  HSCMP;                        /*!< (@ 0x00000180) High Speed Comparator configuration                        */
  __IOM uint32_t  AMBUF;                        /*!< (@ 0x00000184) Reference Generator configuration                          */
  __IOM uint32_t  REFGEN;                       /*!< (@ 0x00000188) Reference Generator configuration                          */
  __IOM uint32_t  CSDCMP;                       /*!< (@ 0x0000018C) CSD Comparator configuration                               */
  __IM  uint32_t  RESERVED5[12];
  __IOM uint32_t  IDACA;                        /*!< (@ 0x000001C0) IDACA Configuration                                        */
  __IOM uint32_t  IDACB;                        /*!< (@ 0x000001C4) IDACB Configuration                                        */
  __IM  uint32_t  RESERVED6[10];
  __IOM uint32_t  SW_RES;                       /*!< (@ 0x000001F0) Switch Resistance configuration                            */
  __IM  uint32_t  RESERVED7[3];
  __IOM uint32_t  SENSE_PERIOD;                 /*!< (@ 0x00000200) Sense clock period                                         */
  __IOM uint32_t  SENSE_DUTY;                   /*!< (@ 0x00000204) Sense clock duty cycle                                     */
  __IM  uint32_t  RESERVED8[30];
  __IOM uint32_t  SW_HS_P_SEL;                  /*!< (@ 0x00000280) HSCMP Pos input switch Waveform selection                  */
  __IOM uint32_t  SW_HS_N_SEL;                  /*!< (@ 0x00000284) HSCMP Neg input switch Waveform selection                  */
  __IOM uint32_t  SW_SHIELD_SEL;                /*!< (@ 0x00000288) Shielding switches Waveform selection                      */
  __IM  uint32_t  RESERVED9;
  __IOM uint32_t  SW_AMUXBUF_SEL;               /*!< (@ 0x00000290) Amuxbuffer switches Waveform selection                     */
  __IOM uint32_t  SW_BYP_SEL;                   /*!< (@ 0x00000294) AMUXBUS bypass switches Waveform selection                 */
  __IM  uint32_t  RESERVED10[2];
  __IOM uint32_t  SW_CMP_P_SEL;                 /*!< (@ 0x000002A0) CSDCMP Pos Switch Waveform selection                       */
  __IOM uint32_t  SW_CMP_N_SEL;                 /*!< (@ 0x000002A4) CSDCMP Neg Switch Waveform selection                       */
  __IOM uint32_t  SW_REFGEN_SEL;                /*!< (@ 0x000002A8) Reference Generator Switch Waveform selection              */
  __IM  uint32_t  RESERVED11;
  __IOM uint32_t  SW_FW_MOD_SEL;                /*!< (@ 0x000002B0) Full Wave Cmod Switch Waveform selection                   */
  __IOM uint32_t  SW_FW_TANK_SEL;               /*!< (@ 0x000002B4) Full Wave Csh_tank Switch Waveform selection               */
  __IM  uint32_t  RESERVED12[2];
  __IOM uint32_t  SW_DSI_SEL;                   /*!< (@ 0x000002C0) DSI output switch control Waveform selection               */
  __IM  uint32_t  RESERVED13[15];
  __IOM uint32_t  SEQ_TIME;                     /*!< (@ 0x00000300) Sequencer Timing                                           */
  __IM  uint32_t  RESERVED14[3];
  __IOM uint32_t  SEQ_INIT_CNT;                 /*!< (@ 0x00000310) Sequencer Initial conversion and sample counts             */
  __IOM uint32_t  SEQ_NORM_CNT;                 /*!< (@ 0x00000314) Sequencer Normal conversion and sample counts              */
  __IM  uint32_t  RESERVED15[2];
  __IOM uint32_t  ADC_CTL;                      /*!< (@ 0x00000320) ADC Control                                                */
  __IM  uint32_t  RESERVED16[7];
  __IOM uint32_t  SEQ_START;                    /*!< (@ 0x00000340) Sequencer start                                            */
  __IM  uint32_t  RESERVED17[751];
  __IOM uint32_t  TRIM_CTRL;                    /*!< (@ 0x00000F00) Trim control                                               */
} CSD_Type;                                     /*!< Size = 3844 (0xf04)                                                       */



/* =========================================================================================================================== */
/* ================                                          LPCOMP                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Low Power Comparators (LPCOMP)
  */

typedef struct {                                /*!< (@ 0x400D0000) LPCOMP Structure                                           */
  __IOM uint32_t  ID;                           /*!< (@ 0x00000000) ID & Revision                                              */
  __IOM uint32_t  CONFIG;                       /*!< (@ 0x00000004) LPCOMP Configuration Register                              */
  __IOM uint32_t  DFT;                          /*!< (@ 0x00000008) LPCOMP DFT register                                        */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000010) LPCOMP Interrupt request register                          */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000014) LPCOMP Interrupt set register                              */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000018) LPCOMP Interrupt request mask                              */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000001C) LPCOMP Interrupt request masked                            */
  __IM  uint32_t  RESERVED1[16312];
  __IOM uint32_t  TRIM1;                        /*!< (@ 0x0000FF00) LPCOMP Trim Register                                       */
  __IOM uint32_t  TRIM2;                        /*!< (@ 0x0000FF04) LPCOMP Trim Register                                       */
  __IOM uint32_t  TRIM3;                        /*!< (@ 0x0000FF08) LPCOMP Trim Register                                       */
  __IOM uint32_t  TRIM4;                        /*!< (@ 0x0000FF0C) LPCOMP Trim Register                                       */
} LPCOMP_Type;                                  /*!< Size = 65296 (0xff10)                                                     */



/* =========================================================================================================================== */
/* ================                                           CPUSS                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief CPU Subsystem (CPUSS)
  */

typedef struct {                                /*!< (@ 0x40100004) CPUSS Structure                                            */
  __IOM uint32_t  SYSREQ;                       /*!< (@ 0x00000000) SYSCALL control register                                   */
  __IOM uint32_t  SYSARG;                       /*!< (@ 0x00000004) SYSARG control register                                    */
  __IOM uint32_t  PROTECTION;                   /*!< (@ 0x00000008) Protection control register                                */
  __IOM uint32_t  PRIV_ROM;                     /*!< (@ 0x0000000C) ROM privilege register                                     */
  __IOM uint32_t  PRIV_RAM;                     /*!< (@ 0x00000010) RAM privilege register                                     */
  __IOM uint32_t  PRIV_FLASH;                   /*!< (@ 0x00000014) Flash privilege register                                   */
  __IOM uint32_t  WOUNDING;                     /*!< (@ 0x00000018) Wounding register                                          */
  __IM  uint32_t  RESERVED[4];
  __IOM uint32_t  FLASH_CTL;                    /*!< (@ 0x0000002C) FLASH control register                                     */
  __IOM uint32_t  ROM_CTL;                      /*!< (@ 0x00000030) ROM control register                                       */
} CPUSS_Type;                                   /*!< Size = 52 (0x34)                                                          */



/* =========================================================================================================================== */
/* ================                                           SPCIF                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Flash Control Interface (SPCIF)
  */

typedef struct {                                /*!< (@ 0x40110000) SPCIF Structure                                            */
  __IOM uint32_t  GEOMETRY;                     /*!< (@ 0x00000000) Flash/NVL geometry information                             */
  __IM  uint32_t  RESERVED[507];
  __IOM uint32_t  INTR;                         /*!< (@ 0x000007F0) SPCIF interrupt request register                           */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x000007F4) SPCIF interrupt set request register                       */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x000007F8) SPCIF interrupt mask register                              */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x000007FC) SPCIF interrupt masked request register                    */
} SPCIF_Type;                                   /*!< Size = 2048 (0x800)                                                       */



/* =========================================================================================================================== */
/* ================                                           CTBM0                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Continuous Time Block Mini (CTBM0)
  */

typedef struct {                                /*!< (@ 0x40300000) CTBM0 Structure                                            */
  __IOM uint32_t  CTB_CTRL;                     /*!< (@ 0x00000000) global CTB and power control                               */
  __IOM uint32_t  OA_RES0_CTRL;                 /*!< (@ 0x00000004) Opamp0 and resistor0 control                               */
  __IOM uint32_t  OA_RES1_CTRL;                 /*!< (@ 0x00000008) Opamp1 and resistor1 control                               */
  __IOM uint32_t  COMP_STAT;                    /*!< (@ 0x0000000C) Comparator status                                          */
  __IM  uint32_t  RESERVED[4];
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000020) Interrupt request register                                 */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000024) Interrupt request set register                             */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000028) Interrupt request mask                                     */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000002C) Interrupt request masked                                   */
  __IOM uint32_t  DFT_CTRL;                     /*!< (@ 0x00000030) Was 'Analog DfT controls', now used as Risk Mitigation
                                                                    bits (RMP)                                                 */
  __IM  uint32_t  RESERVED1[19];
  __IOM uint32_t  OA0_SW;                       /*!< (@ 0x00000080) Opamp0 switch control                                      */
  __IOM uint32_t  OA0_SW_CLEAR;                 /*!< (@ 0x00000084) Opamp0 switch control clear                                */
  __IOM uint32_t  OA1_SW;                       /*!< (@ 0x00000088) Opamp1 switch control                                      */
  __IOM uint32_t  OA1_SW_CLEAR;                 /*!< (@ 0x0000008C) Opamp1 switch control clear                                */
  __IM  uint32_t  RESERVED2[12];
  __IOM uint32_t  CTB_SW_HW_CTRL;               /*!< (@ 0x000000C0) CTB bus switch control                                     */
  __IOM uint32_t  CTB_SW_STATUS;                /*!< (@ 0x000000C4) CTB bus switch control status                              */
  __IM  uint32_t  RESERVED3[910];
  __IOM uint32_t  OA0_OFFSET_TRIM;              /*!< (@ 0x00000F00) Opamp0 trim control                                        */
  __IOM uint32_t  OA0_SLOPE_OFFSET_TRIM;        /*!< (@ 0x00000F04) Opamp0 trim control                                        */
  __IOM uint32_t  OA0_COMP_TRIM;                /*!< (@ 0x00000F08) Opamp0 trim control                                        */
  __IOM uint32_t  OA1_OFFSET_TRIM;              /*!< (@ 0x00000F0C) Opamp1 trim control                                        */
  __IOM uint32_t  OA1_SLOPE_OFFSET_TRIM;        /*!< (@ 0x00000F10) Opamp1 trim control                                        */
  __IOM uint32_t  OA1_COMP_TRIM;                /*!< (@ 0x00000F14) Opamp1 trim control                                        */
} CTBM0_Type;                                   /*!< Size = 3864 (0xf18)                                                       */



/* =========================================================================================================================== */
/* ================                                            SAR                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief SAR ADC with Sequencer (SAR)
  */

typedef struct {                                /*!< (@ 0x403A0000) SAR Structure                                              */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) Analog control register.                                   */
  __IOM uint32_t  SAMPLE_CTRL;                  /*!< (@ 0x00000004) Sample control register.                                   */
  __IM  uint32_t  RESERVED[2];
  __IOM uint32_t  SAMPLE_TIME01;                /*!< (@ 0x00000010) Sample time specification ST0 and ST1                      */
  __IOM uint32_t  SAMPLE_TIME23;                /*!< (@ 0x00000014) Sample time specification ST2 and ST3                      */
  __IOM uint32_t  RANGE_THRES;                  /*!< (@ 0x00000018) Global range detect threshold register.                    */
  __IOM uint32_t  RANGE_COND;                   /*!< (@ 0x0000001C) Global range detect mode register.                         */
  __IOM uint32_t  CHAN_EN;                      /*!< (@ 0x00000020) Enable bits for the channels                               */
  __IOM uint32_t  START_CTRL;                   /*!< (@ 0x00000024) Start control register (firmware trigger).                 */
  __IM  uint32_t  RESERVED1[2];
  __IOM uint32_t  DFT_CTRL;                     /*!< (@ 0x00000030) DFT control register.                                      */
  __IM  uint32_t  RESERVED2[19];
  __IOM uint32_t  CHAN_CONFIG0;                 /*!< (@ 0x00000080) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG1;                 /*!< (@ 0x00000084) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG2;                 /*!< (@ 0x00000088) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG3;                 /*!< (@ 0x0000008C) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG4;                 /*!< (@ 0x00000090) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG5;                 /*!< (@ 0x00000094) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG6;                 /*!< (@ 0x00000098) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG7;                 /*!< (@ 0x0000009C) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG8;                 /*!< (@ 0x000000A0) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG9;                 /*!< (@ 0x000000A4) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG10;                /*!< (@ 0x000000A8) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG11;                /*!< (@ 0x000000AC) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG12;                /*!< (@ 0x000000B0) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG13;                /*!< (@ 0x000000B4) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG14;                /*!< (@ 0x000000B8) Channel configuration register.                            */
  __IOM uint32_t  CHAN_CONFIG15;                /*!< (@ 0x000000BC) Channel configuration register.                            */
  __IM  uint32_t  RESERVED3[16];
  __IOM uint32_t  CHAN_WORK0;                   /*!< (@ 0x00000100) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK1;                   /*!< (@ 0x00000104) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK2;                   /*!< (@ 0x00000108) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK3;                   /*!< (@ 0x0000010C) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK4;                   /*!< (@ 0x00000110) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK5;                   /*!< (@ 0x00000114) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK6;                   /*!< (@ 0x00000118) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK7;                   /*!< (@ 0x0000011C) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK8;                   /*!< (@ 0x00000120) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK9;                   /*!< (@ 0x00000124) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK10;                  /*!< (@ 0x00000128) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK11;                  /*!< (@ 0x0000012C) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK12;                  /*!< (@ 0x00000130) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK13;                  /*!< (@ 0x00000134) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK14;                  /*!< (@ 0x00000138) Channel working data register                              */
  __IOM uint32_t  CHAN_WORK15;                  /*!< (@ 0x0000013C) Channel working data register                              */
  __IM  uint32_t  RESERVED4[16];
  __IOM uint32_t  CHAN_RESULT0;                 /*!< (@ 0x00000180) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT1;                 /*!< (@ 0x00000184) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT2;                 /*!< (@ 0x00000188) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT3;                 /*!< (@ 0x0000018C) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT4;                 /*!< (@ 0x00000190) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT5;                 /*!< (@ 0x00000194) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT6;                 /*!< (@ 0x00000198) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT7;                 /*!< (@ 0x0000019C) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT8;                 /*!< (@ 0x000001A0) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT9;                 /*!< (@ 0x000001A4) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT10;                /*!< (@ 0x000001A8) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT11;                /*!< (@ 0x000001AC) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT12;                /*!< (@ 0x000001B0) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT13;                /*!< (@ 0x000001B4) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT14;                /*!< (@ 0x000001B8) Channel result data register                               */
  __IOM uint32_t  CHAN_RESULT15;                /*!< (@ 0x000001BC) Channel result data register                               */
  __IM  uint32_t  RESERVED5[16];
  __IOM uint32_t  CHAN_WORK_VALID;              /*!< (@ 0x00000200) Channel working data register valid bits                   */
  __IOM uint32_t  CHAN_RESULT_VALID;            /*!< (@ 0x00000204) Channel result data register valid bits                    */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000208) Current status of internal SAR registers (mostly
                                                                    for debug)                                                 */
  __IOM uint32_t  AVG_STAT;                     /*!< (@ 0x0000020C) Current averaging status (for debug)                       */
  __IOM uint32_t  INTR;                         /*!< (@ 0x00000210) Interrupt request register.                                */
  __IOM uint32_t  INTR_SET;                     /*!< (@ 0x00000214) Interrupt set request register                             */
  __IOM uint32_t  INTR_MASK;                    /*!< (@ 0x00000218) Interrupt mask register.                                   */
  __IOM uint32_t  INTR_MASKED;                  /*!< (@ 0x0000021C) Interrupt masked request register                          */
  __IOM uint32_t  SATURATE_INTR;                /*!< (@ 0x00000220) Saturate interrupt request register.                       */
  __IOM uint32_t  SATURATE_INTR_SET;            /*!< (@ 0x00000224) Saturate interrupt set request register                    */
  __IOM uint32_t  SATURATE_INTR_MASK;           /*!< (@ 0x00000228) Saturate interrupt mask register.                          */
  __IOM uint32_t  SATURATE_INTR_MASKED;         /*!< (@ 0x0000022C) Saturate interrupt masked request register                 */
  __IOM uint32_t  RANGE_INTR;                   /*!< (@ 0x00000230) Range detect interrupt request register.                   */
  __IOM uint32_t  RANGE_INTR_SET;               /*!< (@ 0x00000234) Range detect interrupt set request register                */
  __IOM uint32_t  RANGE_INTR_MASK;              /*!< (@ 0x00000238) Range detect interrupt mask register.                      */
  __IOM uint32_t  RANGE_INTR_MASKED;            /*!< (@ 0x0000023C) Range interrupt masked request register                    */
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x00000240) Interrupt cause register                                   */
  __IM  uint32_t  RESERVED6[15];
  __IOM uint32_t  INJ_CHAN_CONFIG;              /*!< (@ 0x00000280) Injection channel configuration register.                  */
  __IM  uint32_t  RESERVED7[3];
  __IOM uint32_t  INJ_RESULT;                   /*!< (@ 0x00000290) Injection channel result register                          */
  __IM  uint32_t  RESERVED8[27];
  __IOM uint32_t  MUX_SWITCH0;                  /*!< (@ 0x00000300) SARMUX Firmware switch controls                            */
  __IOM uint32_t  MUX_SWITCH_CLEAR0;            /*!< (@ 0x00000304) SARMUX Firmware switch control clear                       */
  __IOM uint32_t  MUX_SWITCH1;                  /*!< (@ 0x00000308) SARMUX Firmware switch controls                            */
  __IOM uint32_t  MUX_SWITCH_CLEAR1;            /*!< (@ 0x0000030C) SARMUX Firmware switch control clear                       */
  __IM  uint32_t  RESERVED9[12];
  __IOM uint32_t  MUX_SWITCH_HW_CTRL;           /*!< (@ 0x00000340) SARMUX switch hardware control                             */
  __IM  uint32_t  RESERVED10;
  __IOM uint32_t  MUX_SWITCH_STATUS;            /*!< (@ 0x00000348) SARMUX switch status                                       */
  __IM  uint32_t  RESERVED11[13];
  __IOM uint32_t  PUMP_CTRL;                    /*!< (@ 0x00000380) Switch pump control                                        */
  __IM  uint32_t  RESERVED12[735];
  __IOM uint32_t  ANA_TRIM;                     /*!< (@ 0x00000F00) Analog trim register.                                      */
  __IOM uint32_t  WOUNDING;                     /*!< (@ 0x00000F04) SAR wounding register                                      */
} SAR_Type;                                     /*!< Size = 3848 (0xf08)                                                       */



/* =========================================================================================================================== */
/* ================                                           PASS                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief PASS top-level MMIO (DSABv2, INTR) (PASS)
  */

typedef struct {                                /*!< (@ 0x403F0000) PASS Structure                                             */
  __IOM uint32_t  INTR_CAUSE;                   /*!< (@ 0x00000000) Interrupt cause register                                   */
  __IM  uint32_t  RESERVED[11];
  __IOM uint32_t  DFT_CTRL;                     /*!< (@ 0x00000030) DFT control register                                       */
  __IM  uint32_t  RESERVED1[53];
  __IOM uint32_t  PASS_CTRL;                    /*!< (@ 0x00000108) PASS Control                                               */
  __IM  uint32_t  RESERVED2[893];
  __IOM uint32_t  DSAB_TRIM;                    /*!< (@ 0x00000F00) DSAB Trim bits                                             */
} PASS_Type;                                    /*!< Size = 3844 (0xf04)                                                       */



/* =========================================================================================================================== */
/* ================                                         PASS_DSAB                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief DSAB configuration (PASS_DSAB)
  */

typedef struct {                                /*!< (@ 0x403F0E00) PASS_DSAB Structure                                        */
  __IOM uint32_t  DSAB_CTRL;                    /*!< (@ 0x00000000) global DSAB control                                        */
  __IOM uint32_t  DSAB_DFT;                     /*!< (@ 0x00000004) DFT bits                                                   */
} PASS_DSAB_Type;                               /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                           CM0P                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Cortex-M0+ System Bus (ARM PPB Peripherals) (CM0P)
  */

typedef struct {                                /*!< (@ 0xE0001000) CM0P Structure                                             */
  __IM  uint32_t  RESERVED[1012];
  __IOM uint32_t  DWT_PID4;                     /*!< (@ 0x00000FD0) Watchpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #4                                                      */
  __IM  uint32_t  RESERVED1[3];
  __IOM uint32_t  DWT_PID0;                     /*!< (@ 0x00000FE0) Watchpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #0                                                      */
  __IOM uint32_t  DWT_PID1;                     /*!< (@ 0x00000FE4) Watchpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #1                                                      */
  __IOM uint32_t  DWT_PID2;                     /*!< (@ 0x00000FE8) Watchpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #2                                                      */
  __IOM uint32_t  DWT_PID3;                     /*!< (@ 0x00000FEC) Watchpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #3                                                      */
  __IOM uint32_t  DWT_CID0;                     /*!< (@ 0x00000FF0) Watchpoint Unit CoreSight ROM Table Component
                                                                    ID #0                                                      */
  __IOM uint32_t  DWT_CID1;                     /*!< (@ 0x00000FF4) Watchpoint Unit CoreSight ROM Table Component
                                                                    ID #1                                                      */
  __IOM uint32_t  DWT_CID2;                     /*!< (@ 0x00000FF8) Watchpoint Unit CoreSight ROM Table Component
                                                                    ID #2                                                      */
  __IOM uint32_t  DWT_CID3;                     /*!< (@ 0x00000FFC) Watchpoint Unit CoreSight ROM Table Component
                                                                    ID #3                                                      */
  __IM  uint32_t  RESERVED2[1012];
  __IOM uint32_t  BP_PID4;                      /*!< (@ 0x00001FD0) Breakpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #4                                                      */
  __IM  uint32_t  RESERVED3[3];
  __IOM uint32_t  BP_PID0;                      /*!< (@ 0x00001FE0) Breakpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #0                                                      */
  __IOM uint32_t  BP_PID1;                      /*!< (@ 0x00001FE4) Breakpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #1                                                      */
  __IOM uint32_t  BP_PID2;                      /*!< (@ 0x00001FE8) Breakpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #2                                                      */
  __IOM uint32_t  BP_PID3;                      /*!< (@ 0x00001FEC) Breakpoint Unit CoreSight ROM Table Peripheral
                                                                    ID #3                                                      */
  __IOM uint32_t  BP_CID0;                      /*!< (@ 0x00001FF0) Breakpoint Unit CoreSight ROM Table Component
                                                                    ID #0                                                      */
  __IOM uint32_t  BP_CID1;                      /*!< (@ 0x00001FF4) Breakpoint Unit CoreSight ROM Table Component
                                                                    ID #1                                                      */
  __IOM uint32_t  BP_CID2;                      /*!< (@ 0x00001FF8) Breakpoint Unit CoreSight ROM Table Component
                                                                    ID #2                                                      */
  __IOM uint32_t  BP_CID3;                      /*!< (@ 0x00001FFC) Breakpoint Unit CoreSight ROM Table Component
                                                                    ID #3                                                      */
  __IM  uint32_t  RESERVED4[11268];
  __IOM uint32_t  SYST_CSR;                     /*!< (@ 0x0000D010) SysTick Control & Status                                   */
  __IOM uint32_t  SYST_RVR;                     /*!< (@ 0x0000D014) SysTick Reload Value                                       */
  __IOM uint32_t  SYST_CVR;                     /*!< (@ 0x0000D018) SysTick Current Value                                      */
  __IOM uint32_t  SYST_CALIB;                   /*!< (@ 0x0000D01C) SysTick Calibration Value                                  */
  __IM  uint32_t  RESERVED5[56];
  __IOM uint32_t  ISER;                         /*!< (@ 0x0000D100) Interrupt Set-Enable Register                              */
  __IM  uint32_t  RESERVED6[31];
  __IOM uint32_t  ICER;                         /*!< (@ 0x0000D180) Interrupt Clear Enable Register                            */
  __IM  uint32_t  RESERVED7[31];
  __IOM uint32_t  ISPR;                         /*!< (@ 0x0000D200) Interrupt Set-Pending Register                             */
  __IM  uint32_t  RESERVED8[31];
  __IOM uint32_t  ICPR;                         /*!< (@ 0x0000D280) Interrupt Clear-Pending Register                           */
  __IM  uint32_t  RESERVED9[95];
  __IOM uint32_t  IPR0;                         /*!< (@ 0x0000D400) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR1;                         /*!< (@ 0x0000D404) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR2;                         /*!< (@ 0x0000D408) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR3;                         /*!< (@ 0x0000D40C) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR4;                         /*!< (@ 0x0000D410) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR5;                         /*!< (@ 0x0000D414) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR6;                         /*!< (@ 0x0000D418) Interrupt Priority Registers                               */
  __IOM uint32_t  IPR7;                         /*!< (@ 0x0000D41C) Interrupt Priority Registers                               */
  __IM  uint32_t  RESERVED10[568];
  __IOM uint32_t  CPUID;                        /*!< (@ 0x0000DD00) CPUID Register                                             */
  __IOM uint32_t  ICSR;                         /*!< (@ 0x0000DD04) Interrupt Control State Register                           */
  __IOM uint32_t  VTOR;                         /*!< (@ 0x0000DD08) Vector Table Offset Register                               */
  __IOM uint32_t  AIRCR;                        /*!< (@ 0x0000DD0C) Application Interrupt and Reset Control Register           */
  __IOM uint32_t  SCR;                          /*!< (@ 0x0000DD10) System Control Register                                    */
  __IOM uint32_t  CCR;                          /*!< (@ 0x0000DD14) Configuration and Control Register                         */
  __IM  uint32_t  RESERVED11;
  __IOM uint32_t  SHPR2;                        /*!< (@ 0x0000DD1C) System Handler Priority Register 2                         */
  __IOM uint32_t  SHPR3;                        /*!< (@ 0x0000DD20) System Handler Priority Register 3                         */
  __IOM uint32_t  SHCSR;                        /*!< (@ 0x0000DD24) System Handler Control and State Register                  */
  __IM  uint32_t  RESERVED12[170];
  __IOM uint32_t  SCS_PID4;                     /*!< (@ 0x0000DFD0) System Control Space ROM Table Peripheral ID
                                                                    #4                                                         */
  __IM  uint32_t  RESERVED13[3];
  __IOM uint32_t  SCS_PID0;                     /*!< (@ 0x0000DFE0) System Control Space ROM Table Peripheral ID
                                                                    #0                                                         */
  __IOM uint32_t  SCS_PID1;                     /*!< (@ 0x0000DFE4) System Control Space ROM Table Peripheral ID
                                                                    #1                                                         */
  __IOM uint32_t  SCS_PID2;                     /*!< (@ 0x0000DFE8) System Control Space ROM Table Peripheral ID
                                                                    #2                                                         */
  __IOM uint32_t  SCS_PID3;                     /*!< (@ 0x0000DFEC) System Control Space ROM Table Peripheral ID
                                                                    #3                                                         */
  __IOM uint32_t  SCS_CID0;                     /*!< (@ 0x0000DFF0) System Control Space ROM Table Component ID #0             */
  __IOM uint32_t  SCS_CID1;                     /*!< (@ 0x0000DFF4) System Control Space ROM Table Component ID #1             */
  __IOM uint32_t  SCS_CID2;                     /*!< (@ 0x0000DFF8) System Control Space ROM Table Component ID #2             */
  __IOM uint32_t  SCS_CID3;                     /*!< (@ 0x0000DFFC) System Control Space ROM Table Component ID #3             */
  __IM  uint32_t  RESERVED14[245760];
  __IOM uint32_t  ROM_SCS;                      /*!< (@ 0x000FE000) CM0+ CoreSight ROM Table Peripheral #0                     */
  __IOM uint32_t  ROM_DWT;                      /*!< (@ 0x000FE004) CM0+ CoreSight ROM Table Peripheral #1                     */
  __IOM uint32_t  ROM_BPU;                      /*!< (@ 0x000FE008) CM0+ CoreSight ROM Table Peripheral #2                     */
  __IOM uint32_t  ROM_END;                      /*!< (@ 0x000FE00C) CM0+ CoreSight ROM Table End Marker                        */
  __IM  uint32_t  RESERVED15[1007];
  __IOM uint32_t  ROM_CSMT;                     /*!< (@ 0x000FEFCC) CM0+ CoreSight ROM Table Memory Type                       */
  __IOM uint32_t  ROM_PID4;                     /*!< (@ 0x000FEFD0) CM0+ CoreSight ROM Table Peripheral ID #4                  */
  __IM  uint32_t  RESERVED16[3];
  __IOM uint32_t  ROM_PID0;                     /*!< (@ 0x000FEFE0) CM0+ CoreSight ROM Table Peripheral ID #0                  */
  __IOM uint32_t  ROM_PID1;                     /*!< (@ 0x000FEFE4) CM0+ CoreSight ROM Table Peripheral ID #1                  */
  __IOM uint32_t  ROM_PID2;                     /*!< (@ 0x000FEFE8) CM0+ CoreSight ROM Table Peripheral ID #2                  */
  __IOM uint32_t  ROM_PID3;                     /*!< (@ 0x000FEFEC) CM0+ CoreSight ROM Table Peripheral ID #3                  */
  __IOM uint32_t  ROM_CID0;                     /*!< (@ 0x000FEFF0) CM0+ CoreSight ROM Table Component ID #0                   */
  __IOM uint32_t  ROM_CID1;                     /*!< (@ 0x000FEFF4) CM0+ CoreSight ROM Table Component ID #1                   */
  __IOM uint32_t  ROM_CID2;                     /*!< (@ 0x000FEFF8) CM0+ CoreSight ROM Table Component ID #2                   */
  __IOM uint32_t  ROM_CID3;                     /*!< (@ 0x000FEFFC) CM0+ CoreSight ROM Table Component ID #3                   */
} CM0P_Type;                                    /*!< Size = 1044480 (0xff000)                                                  */



/* =========================================================================================================================== */
/* ================                                         ROMTABLE                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief CoreSight ROM-Table with Manufacturer Vendor/Silicon ID (ROMTABLE)
  */

typedef struct {                                /*!< (@ 0xF0000000) ROMTABLE Structure                                         */
  __IOM uint32_t  ADDR;                         /*!< (@ 0x00000000) Link to Cortex M0 ROM Table.                               */
  __IM  uint32_t  RESERVED[1010];
  __IOM uint32_t  DID;                          /*!< (@ 0x00000FCC) Device Type Identifier register.                           */
  __IOM uint32_t  PID4;                         /*!< (@ 0x00000FD0) Peripheral Identification Register 4.                      */
  __IOM uint32_t  PID5;                         /*!< (@ 0x00000FD4) Peripheral Identification Register 5.                      */
  __IOM uint32_t  PID6;                         /*!< (@ 0x00000FD8) Peripheral Identification Register 6.                      */
  __IOM uint32_t  PID7;                         /*!< (@ 0x00000FDC) Peripheral Identification Register 7.                      */
  __IOM uint32_t  PID0;                         /*!< (@ 0x00000FE0) Peripheral Identification Register 0.                      */
  __IOM uint32_t  PID1;                         /*!< (@ 0x00000FE4) Peripheral Identification Register 1.                      */
  __IOM uint32_t  PID2;                         /*!< (@ 0x00000FE8) Peripheral Identification Register 2.                      */
  __IOM uint32_t  PID3;                         /*!< (@ 0x00000FEC) Peripheral Identification Register 3.                      */
  __IOM uint32_t  CID0;                         /*!< (@ 0x00000FF0) Component Identification Register 0.                       */
  __IOM uint32_t  CID1;                         /*!< (@ 0x00000FF4) Component Identification Register 1.                       */
  __IOM uint32_t  CID2;                         /*!< (@ 0x00000FF8) Component Identification Register 2.                       */
  __IOM uint32_t  CID3;                         /*!< (@ 0x00000FFC) Component Identification Register 3.                       */
} ROMTABLE_Type;                                /*!< Size = 4096 (0x1000)                                                      */


/** @} */ /* End of group Device_Peripheral_peripherals */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define SFLASH_BASE                 0x0FFFF000UL
#define PERI_BASE                   0x40010000UL
#define PERI_TR_GROUP0_BASE         0x40012000UL
#define PERI_TR_GROUP1_BASE         0x40012200UL
#define HSIOM_BASE                  0x40020000UL
#define SRSSLT_BASE                 0x40030000UL
#define GPIO_BASE                   0x40041000UL
#define GPIO_PRT0_BASE              0x40040000UL
#define GPIO_PRT1_BASE              0x40040100UL
#define GPIO_PRT2_BASE              0x40040200UL
#define GPIO_PRT3_BASE              0x40040300UL
#define GPIO_PRT4_BASE              0x40040400UL
#define PRGIO_PRT0_BASE             0x40050000UL
#define PRGIO_PRT1_BASE             0x40050100UL
#define TCPWM_BASE                  0x40060000UL
#define TCPWM_CNT0_BASE             0x40060100UL
#define TCPWM_CNT1_BASE             0x40060140UL
#define TCPWM_CNT2_BASE             0x40060180UL
#define TCPWM_CNT3_BASE             0x400601C0UL
#define TCPWM_CNT4_BASE             0x40060200UL
#define WCO_BASE                    0x40070000UL
#define SCB0_BASE                   0x40080000UL
#define SCB1_BASE                   0x40090000UL
#define SCB2_BASE                   0x400A0000UL
#define LCD_BASE                    0x400B0000UL
#define CSD_BASE                    0x400C0000UL
#define LPCOMP_BASE                 0x400D0000UL
#define CPUSS_BASE                  0x40100004UL
#define SPCIF_BASE                  0x40110000UL
#define CTBM0_BASE                  0x40300000UL
#define SAR_BASE                    0x403A0000UL
#define PASS_BASE                   0x403F0000UL
#define PASS_DSAB_BASE              0x403F0E00UL
#define CM0P_BASE                   0xE0001000UL
#define ROMTABLE_BASE               0xF0000000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define SFLASH                      ((SFLASH_Type*)            SFLASH_BASE)
#define PERI                        ((PERI_Type*)              PERI_BASE)
#define PERI_TR_GROUP0              ((PERI_TR_GROUP0_Type*)    PERI_TR_GROUP0_BASE)
#define PERI_TR_GROUP1              ((PERI_TR_GROUP1_Type*)    PERI_TR_GROUP1_BASE)
#define HSIOM                       ((HSIOM_Type*)             HSIOM_BASE)
#define SRSSLT                      ((SRSSLT_Type*)            SRSSLT_BASE)
#define GPIO                        ((GPIO_Type*)              GPIO_BASE)
#define GPIO_PRT0                   ((GPIO_PRT0_Type*)         GPIO_PRT0_BASE)
#define GPIO_PRT1                   ((GPIO_PRT1_Type*)         GPIO_PRT1_BASE)
#define GPIO_PRT2                   ((GPIO_PRT2_Type*)         GPIO_PRT2_BASE)
#define GPIO_PRT3                   ((GPIO_PRT3_Type*)         GPIO_PRT3_BASE)
#define GPIO_PRT4                   ((GPIO_PRT4_Type*)         GPIO_PRT4_BASE)
#define PRGIO_PRT0                  ((PRGIO_PRT0_Type*)        PRGIO_PRT0_BASE)
#define PRGIO_PRT1                  ((PRGIO_PRT1_Type*)        PRGIO_PRT1_BASE)
#define TCPWM                       ((TCPWM_Type*)             TCPWM_BASE)
#define TCPWM_CNT0                  ((TCPWM_CNT0_Type*)        TCPWM_CNT0_BASE)
#define TCPWM_CNT1                  ((TCPWM_CNT1_Type*)        TCPWM_CNT1_BASE)
#define TCPWM_CNT2                  ((TCPWM_CNT2_Type*)        TCPWM_CNT2_BASE)
#define TCPWM_CNT3                  ((TCPWM_CNT3_Type*)        TCPWM_CNT3_BASE)
#define TCPWM_CNT4                  ((TCPWM_CNT4_Type*)        TCPWM_CNT4_BASE)
#define WCO                         ((WCO_Type*)               WCO_BASE)
#define SCB0                        ((SCB0_Type*)              SCB0_BASE)
#define SCB1                        ((SCB1_Type*)              SCB1_BASE)
#define SCB2                        ((SCB2_Type*)              SCB2_BASE)
#define LCD                         ((LCD_Type*)               LCD_BASE)
#define CSD                         ((CSD_Type*)               CSD_BASE)
#define LPCOMP                      ((LPCOMP_Type*)            LPCOMP_BASE)
#define CPUSS                       ((CPUSS_Type*)             CPUSS_BASE)
#define SPCIF                       ((SPCIF_Type*)             SPCIF_BASE)
#define CTBM0                       ((CTBM0_Type*)             CTBM0_BASE)
#define SAR                         ((SAR_Type*)               SAR_BASE)
#define PASS                        ((PASS_Type*)              PASS_BASE)
#define PASS_DSAB                   ((PASS_DSAB_Type*)         PASS_DSAB_BASE)
#define CM0P                        ((CM0P_Type*)              CM0P_BASE)
#define ROMTABLE                    ((ROMTABLE_Type*)          ROMTABLE_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */


#ifdef __cplusplus
}
#endif

#endif /* AXM0F2_H */


/** @} */ /* End of group axm0f2 */

/** @} */ /* End of group  */
