/**
******************************************************************************
* @file axm0.h
* @brief Nebo peripheral register addresses
* @internal
* @author   Thomas Sailer, Radhika Raghavendran, Pradeep G R
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
#ifndef AXM0_H
#define AXM0_H

#ifdef __cplusplus
extern "C" {
#endif

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum IRQn
{
/* =======================================  ARM Cortex-M0+ Specific Interrupt Numbers  ======================================= */
  Reset_IRQn                     = -15,      /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn            = -14,      /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn                 = -13,      /*!< -13  Hard Fault, all classes of Fault                                     */
  SVCall_IRQn                    =  -5,      /*!< -5 System Service Call via SVC instruction                                */
  PendSV_IRQn                    =  -2,      /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn                   =  -1,      /*!< -1 System Tick Timer                                                      */
/* ==========================================  axm0 Specific Interrupt Numbers  ============================================== */
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

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ==========================  Configuration of the ARM Cortex-M0+ Processor and Core Peripherals  =========================== */
#define __CM0PLUS_REV             0x0000U   /* Core revision r0p0 */
#define __MPU_PRESENT             0U        /* MPU present or not */
#define __VTOR_PRESENT            0U        /* VTOR present or not */
#define __NVIC_PRIO_BITS          2U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0plus.h"                       /*!< ARM Cortex-M0+ processor and core peripherals                             */
#include "system_ARMCM0plus.h"                  /*!< ARM CM0+ System                                                           */


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                            CMP                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Analog comparators interface is used to configure the inputs and read the results of analog comparisons.  An interrupt can be configured to assert when comparators output are high. (CMP)
  */

typedef struct {                                /*!< (@ 0x40600000) CMP Structure                                              */

  union {
    __IM  uint32_t OUT;                         /*!< (@ 0x00000000) Analog comparators output register                         */

    struct {
      __IM  uint32_t CMP0        : 1;           /*!< (@ 0x00000000) CMP0                                                       */
      __IM  uint32_t CMP1        : 1;           /*!< (@ 0x00000001) CMP1                                                       */
    } OUT_b;
  } ;

  union {
    __IOM uint32_t CTL;                         /*!< (@ 0x00000004) Analog comparators control register                        */

    struct {
      __IOM uint32_t CMP0_EN     : 1;           /*!< (@ 0x00000000) Comparator 0 enable                                        */
      __IOM uint32_t CMP0_MINUS  : 3;           /*!< (@ 0x00000001) Comparator 0 negative terminal input selection             */
      __IOM uint32_t CMP0_PLUS   : 3;           /*!< (@ 0x00000004) Comparator 0 positive terminal input selection             */
      __IM  uint32_t             : 1;
      __IOM uint32_t CMP1_EN     : 1;           /*!< (@ 0x00000008) Comparator 1 enable                                        */
      __IOM uint32_t CMP1_MINUS  : 3;           /*!< (@ 0x00000009) Comparator 1 negative terminal input selection             */
      __IOM uint32_t CMP1_PLUS   : 3;           /*!< (@ 0x0000000C) Comparator 1 positive terminal input selection             */
    } CTL_b;
  } ;

  union {
    __IOM uint32_t INT_EN;                      /*!< (@ 0x00000008) Analog comparators interrupt enable register               */

    struct {
      __IOM uint32_t COMP0_RISE  : 1;           /*!< (@ 0x00000000) Comparator 0 rising edge interrupt enable                  */
      __IOM uint32_t COMP0_FALL  : 1;           /*!< (@ 0x00000001) Comparator 0 falling edge interrupt enable                 */
      __IOM uint32_t COMP1_RISE  : 1;           /*!< (@ 0x00000002) Comparator 1 rising edge interrupt enable                  */
      __IOM uint32_t COMP1_FALL  : 1;           /*!< (@ 0x00000003) Comparator 1 falling edge interrupt enable                 */
    } INT_EN_b;
  } ;

  union {
    __IOM uint32_t INT_STS;                     /*!< (@ 0x0000000C) Analog comparators interrupt status register               */

    struct {
      __IOM uint32_t COMP0_RISE  : 1;           /*!< (@ 0x00000000) Comparator 0 rising edge interrupt enable                  */
      __IOM uint32_t COMP0_FALL  : 1;           /*!< (@ 0x00000001) Comparator 0 falling edge interrupt enable                 */
      __IOM uint32_t COMP1_RISE  : 1;           /*!< (@ 0x00000002) Comparator 1 rising edge interrupt enable                  */
      __IOM uint32_t COMP1_FALL  : 1;           /*!< (@ 0x00000003) Comparator 1 falling edge interrupt enable                 */
    } INT_STS_b;
  } ;
} CMP_Type;                                     /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief ADC interface contains registers used to enable and retrieve ADC conversion data.  Desired ADC conversion is configured and started using the ADC control register. (ADC)
  */

typedef struct {                                /*!< (@ 0x40700000) ADC Structure                                              */
  __IM  uint32_t   DATA;                        /*!< (@ 0x00000000) ADC data Register. It contains sampled data.               */

  union {
    __IOM uint32_t CFG;                         /*!< (@ 0x00000004) ADC configuration register                                 */

    struct {
      __IOM uint32_t CH_SINGLE_0_EN : 1;        /*!< (@ 0x00000000) Analog external channel 0 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_1_EN : 1;        /*!< (@ 0x00000001) Analog external channel 1 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_2_EN : 1;        /*!< (@ 0x00000002) Analog external channel 2 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_3_EN : 1;        /*!< (@ 0x00000003) Analog external channel 3 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_4_EN : 1;        /*!< (@ 0x00000004) Analog external channel 4 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_5_EN : 1;        /*!< (@ 0x00000005) Analog external channel 5 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_6_EN : 1;        /*!< (@ 0x00000006) Analog external channel 6 (single ended) enable            */
      __IOM uint32_t CH_SINGLE_7_EN : 1;        /*!< (@ 0x00000007) Analog external channel 7 (single ended) enable            */
      __IOM uint32_t CH_DIFF_0_1_EN : 1;        /*!< (@ 0x00000008) Analog external differential channels 0-1 enable           */
      __IOM uint32_t CH_DIFF_2_3_EN : 1;        /*!< (@ 0x00000009) Analog external differential channels 2-3 enable           */
      __IOM uint32_t CH_DIFF_4_5_EN : 1;        /*!< (@ 0x0000000A) Analog external differential channels 4-5 enable           */
      __IOM uint32_t CH_DIFF_6_7_EN : 1;        /*!< (@ 0x0000000B) Analog external differential channels 6-7 enable           */
      __IOM uint32_t CH_TEMP_EN  : 1;           /*!< (@ 0x0000000C) Temperature sensor channel enable                          */
      __IOM uint32_t CH_CMP_IN_EN : 1;          /*!< (@ 0x0000000D) Comparator input channel enable                            */
      __IOM uint32_t CH_CHIP_VOLT_EN : 1;       /*!< (@ 0x0000000E) Chip supply voltage channel enable                         */
      __IOM uint32_t CH_CORE_VOLT_EN : 1;       /*!< (@ 0x0000000F) Digital core voltage channel enable                        */
      __IOM uint32_t SAMP_PER    : 3;           /*!< (@ 0x00000010) ADC sample phase period (number of clock cycles)
                                                                    Number = ADC_SAMP_CLKS + 1.                                */
      __IOM uint32_t GAIN        : 2;           /*!< (@ 0x00000013) ADC gain configuration                                     */
      __IOM uint32_t HV_MOD      : 1;           /*!< (@ 0x00000015) 3.3V mode selection                                        */
      __IOM uint32_t REF_SEL     : 2;           /*!< (@ 0x00000016) ADC reference voltage selection. 0 = internal,
                                                                    1 = external.                                              */
      __IOM uint32_t REG_SEL     : 1;           /*!< (@ 0x00000018) ADC regulator selection                                    */
    } CFG_b;
  } ;

  union {
    __IOM uint32_t CTL;                         /*!< (@ 0x00000008) ADC control register                                       */

    struct {
      __IOM uint32_t CNT_EN      : 1;           /*!< (@ 0x00000000) ADC count conversion enable. Self clearing when
                                                                    number of requested conversion (CNT_LIMIT
                                                                    + 1) are done. Writing 1 will abort current
                                                                    sequence.                                                  */
      __IOM uint32_t CONT_EN     : 1;           /*!< (@ 0x00000001) ADC continuous conversion enable                           */
      __IOM uint32_t OVER_EN     : 1;           /*!< (@ 0x00000002) ADC over-write (of data and channel number) enable         */
      __IOM uint32_t HW_TRIG     : 1;           /*!< (@ 0x00000003) Hardware ADC trigger in continuous conversion
                                                                    mode (ignored otherwise)                                   */
      __IOM uint32_t EDGE_TRIG   : 2;           /*!< (@ 0x00000004) Edge trigger configuration. It must be set to
                                                                    0x0 if the hardware trigger is not a pin.                  */
      __IOM uint32_t SEQ_RST     : 1;           /*!< (@ 0x00000006) ADC channel sequence reset, to restart channel
                                                                    selection at lowest enabled. Self clearing
                                                                    when reset is done.                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t CNT_LIMIT   : 11;          /*!< (@ 0x00000008) Number of conversion requested when count conversion
                                                                    is enabled                                                 */
    } CTL_b;
  } ;
  __IOM uint32_t   CAL;                         /*!< (@ 0x0000000C) ADC calibrate register. It starts ADC calibration.         */

  union {
    __IOM uint32_t INT_EN;                      /*!< (@ 0x00000010) ADC interrupt enable register                              */

    struct {
      __IOM uint32_t DATA        : 1;           /*!< (@ 0x00000000) ADC data ready interrupt enable                            */
      __IOM uint32_t OVER        : 1;           /*!< (@ 0x00000001) ADC over-write interrupt enable                            */
    } INT_EN_b;
  } ;

  union {
    __IOM uint32_t INT_STS;                     /*!< (@ 0x00000014) ADC interrupt status register                              */

    struct {
      __IOM uint32_t DATA        : 1;           /*!< (@ 0x00000000) ADC data ready interrupt status                            */
      __IOM uint32_t OVER        : 1;           /*!< (@ 0x00000001) ADC over-write interrupt status                            */
    } INT_STS_b;
  } ;
  __IOM uint32_t   TEST_MOD;                    /*!< (@ 0x00000018) ADC test mode register                                     */
  __IM  uint32_t   CH_STS;                      /*!< (@ 0x0000001C) ADC channel status register. It indicates last
                                                                    channel which was sampled (0x0 to 0xF)                     */

  union {
    __IM  uint32_t STS;                         /*!< (@ 0x00000020) ADC status register                                        */

    struct {
      __IM  uint32_t CNT         : 11;          /*!< (@ 0x00000000) ADC conversion completed in count mode since
                                                                    sequence was started                                       */
      __IM  uint32_t             : 4;
      __IM  uint32_t STATE       : 1;           /*!< (@ 0x0000000F) ADC state                                                  */
    } STS_b;
  } ;
} ADC_Type;                                     /*!< Size = 36 (0x24)                                                          */



/* =========================================================================================================================== */
/* ================                                            CMU                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Clock Management Unit is used to configure clocks. (CMU)
  */

typedef struct {                                /*!< (@ 0x40300000) CMU Structure                                              */

  union {
    __IOM uint32_t CFG;                         /*!< (@ 0x00000000) Clock configuration register                               */

    struct {
      __IOM uint32_t SYS_CLK_SEL : 3;           /*!< (@ 0x00000000) System clock source selection                              */
      __IOM uint32_t SYS_CLK_DIV : 3;           /*!< (@ 0x00000003) System clock divider. HCLK = SYS_CLK / (2 ^ SYS_CLK_DIV)   */
      __IOM uint32_t SYS_CLK_MON_PER : 2;       /*!< (@ 0x00000006) System clock monitoring period                             */
      __IM  uint32_t             : 2;
      __IOM uint32_t HS_OSC_PD   : 1;           /*!< (@ 0x0000000A) High speed RC oscillator power-down. 1 = HS_OSC
                                                                    disabled, 0 = HS_OSC enabled                               */
      __IOM uint32_t LP_OSC_PD   : 1;           /*!< (@ 0x0000000B) Low power RC oscillator power-down. 1 = LP_OSC
                                                                    disabled, 0 = LP_OSC enabled                               */
      __IOM uint32_t HS_XOSC_PD  : 1;           /*!< (@ 0x0000000C) High speed crystal oscillator power-down. 1 =
                                                                    HS_XOSC disabled, 0 = HS_XOSC enabled                      */
      __IOM uint32_t LP_XOSC_PD  : 1;           /*!< (@ 0x0000000D) Low power crystal oscillator power-down. 1 =
                                                                    LP_XOSC disabled, 0 = LP_XOSC enabled                      */
      __IOM uint32_t WDOG_CLK_SEL : 2;          /*!< (@ 0x0000000E) Watchdog clock source selection                            */
      __IOM uint32_t SYSTICK_CLK_SEL : 2;       /*!< (@ 0x00000010) Systick clock source selection                             */
      __IOM uint32_t HS_OSC_CAL_INT_EN : 1;     /*!< (@ 0x00000012) High speed RC oscillator calibration interrupt
                                                                    enable                                                     */
      __IOM uint32_t LP_OSC_CAL_INT_EN : 1;     /*!< (@ 0x00000013) Low power RC oscillator calibration interrupt
                                                                    enable                                                     */
      __IOM uint32_t CLK_LOSS_INT_EN : 1;       /*!< (@ 0x00000014) Clock loss interrupt enable                                */
    } CFG_b;
  } ;

  union {
    __IM  uint32_t STS;                         /*!< (@ 0x00000004) Clock status register                                      */

    struct {
      __IM  uint32_t CLK_SEL     : 3;           /*!< (@ 0x00000000) Active system clock source selection                       */
      __IM  uint32_t CLK_LOSS    : 1;           /*!< (@ 0x00000003) Clock loss detected. Source switched to low power
                                                                    RC oscillator                                              */
    } STS_b;
  } ;

  union {
    __IOM uint32_t ADC_CLK_CFG;                 /*!< (@ 0x00000008) ADC clock configuration register.                          */

    struct {
      __IOM uint32_t DIV         : 3;           /*!< (@ 0x00000000) ADC clock divider. ADC_CLK = SYS_CLK / (2 ^ ADC_CLK_DIV)   */
      __IM  uint32_t             : 1;
      __IOM uint32_t SEL         : 3;           /*!< (@ 0x00000004) ADC clock selection                                        */
    } ADC_CLK_CFG_b;
  } ;
  __IOM uint32_t   EXT_CLK_DIV;                 /*!< (@ 0x0000000C) External clock divider register. EXT_CLK = SYS_CLK
                                                                    / (EXT_CLK_DIV + 1)                                        */

  union {
    __IOM uint32_t PCLK_CFG;                    /*!< (@ 0x00000010) Peripheral clocks configuration register                   */

    struct {
      __IOM uint32_t GPIO_EN     : 1;           /*!< (@ 0x00000000) GPIO_EN                                                    */
      __IOM uint32_t WUT_EN      : 1;           /*!< (@ 0x00000001) WUT_EN                                                     */
      __IM  uint32_t             : 1;
      __IOM uint32_t CL_SYSCFG_EN: 1;           /*!< (@ 0x00000003) CL_SYSCFG_EN                                               */
      __IOM uint32_t PMU_EN      : 1;           /*!< (@ 0x00000004) PMU_EN                                                     */
      __IOM uint32_t XBAR_EN     : 1;           /*!< (@ 0x00000005) XBAR_EN                                                    */
      __IOM uint32_t CMP_EN      : 1;           /*!< (@ 0x00000006) CMP_EN                                                     */
      __IOM uint32_t ADC_EN      : 1;           /*!< (@ 0x00000007) ADC_EN                                                     */
      __IM  uint32_t DMA_EN      : 1;           /*!< (@ 0x00000008) DMA_EN                                                     */
      __IOM uint32_t AES_EN      : 1;           /*!< (@ 0x00000009) AES_EN                                                     */
      __IOM uint32_t TRNG_EN     : 1;           /*!< (@ 0x0000000A) TRNG_EN                                                    */
      __IM  uint32_t             : 1;
      __IOM uint32_t FLASH_EN    : 1;           /*!< (@ 0x0000000C) FLASH_EN                                                   */
      __IOM uint32_t CRC_EN      : 1;           /*!< (@ 0x0000000D) CRC_EN                                                     */
      __IM  uint32_t             : 1;
      __IOM uint32_t WDOG_EN     : 1;           /*!< (@ 0x0000000F) WDOG_EN                                                    */
      __IOM uint32_t TICKER_EN   : 1;           /*!< (@ 0x00000010) TICKER_EN                                                  */
      __IOM uint32_t TIM0_EN     : 1;           /*!< (@ 0x00000011) TIM0_EN                                                    */
      __IOM uint32_t TIM1_EN     : 1;           /*!< (@ 0x00000012) TIM1_EN                                                    */
      __IOM uint32_t TIM2_EN     : 1;           /*!< (@ 0x00000013) TIM2_EN                                                    */
      __IOM uint32_t CC_PWM0_EN  : 1;           /*!< (@ 0x00000014) CC_PWM0_EN                                                 */
      __IOM uint32_t CC_PWM1_EN  : 1;           /*!< (@ 0x00000015) CC_PWM1_EN                                                 */
      __IOM uint32_t CC_PWM2_EN  : 1;           /*!< (@ 0x00000016) CC_PWM2_EN                                                 */
      __IOM uint32_t CC_PWM3_EN  : 1;           /*!< (@ 0x00000017) CC_PWM3_EN                                                 */
      __IM  uint32_t             : 1;
      __IOM uint32_t SPI0_EN     : 1;           /*!< (@ 0x00000019) SPI0_EN                                                    */
      __IOM uint32_t SPI1_EN     : 1;           /*!< (@ 0x0000001A) SPI1_EN                                                    */
      __IOM uint32_t UART0_EN    : 1;           /*!< (@ 0x0000001B) UART0_EN                                                   */
      __IOM uint32_t UART1_EN    : 1;           /*!< (@ 0x0000001C) UART1_EN                                                   */
      __IOM uint32_t I2C_EN      : 1;           /*!< (@ 0x0000001D) I2C_EN                                                     */
      __IM  uint32_t             : 1;
      __IOM uint32_t MISC_EN     : 1;           /*!< (@ 0x0000001F) MISC_EN                                                    */
    } PCLK_CFG_b;
  } ;

  union {
    __IOM uint32_t LP_OSC_CFG;                  /*!< (@ 0x00000014) Low power RC oscillator configuration register.
                                                                    It is used for configuration and calibration.              */

    struct {
      __IOM uint32_t CAL_SEL     : 3;           /*!< (@ 0x00000000) Low power RC oscillator calibration source selection       */
      __IOM uint32_t DIV         : 3;           /*!< (@ 0x00000003) Low power RC oscillator clock divider                      */
      __IOM uint32_t FREQ_SEL    : 1;           /*!< (@ 0x00000006) Low power RC oscillator frequency selection.
                                                                    0=640Hz, 1=10.24kHz                                        */
    } LP_OSC_CFG_b;
  } ;
  __IOM uint32_t   LP_OSC_FILT;                 /*!< (@ 0x00000018) Low power RC oscillator calibration filter constant
                                                                    register                                                   */
  __IOM uint32_t   LP_OSC_REF_DIV;              /*!< (@ 0x0000001C) Low power RC oscillator reference frequency divider
                                                                    register                                                   */
  __IOM uint32_t   LP_OSC_FREQ_TUNE;            /*!< (@ 0x00000020) Low power RC oscillator frequency tune register.           */
  __IM  uint32_t   HS_OSC_PER;                  /*!< (@ 0x00000024) Low power RC oscillator period register. It measures
                                                                    last LP_OSC period.                                        */

  union {
    __IOM uint32_t HS_OSC_CFG;                  /*!< (@ 0x00000028) High speed RC oscillator configuration register.
                                                                    It is used to setup its operation and its
                                                                    calibration.                                               */

    struct {
      __IOM uint32_t CAL_SEL     : 3;           /*!< (@ 0x00000000) High speed RC oscillator calibration source selection      */
      __IOM uint32_t DIV         : 4;           /*!< (@ 0x00000003) High speed RC oscillator clock divider. HS_OSC_CLK
                                                                    = HS_OSC / (2 ^ (DIV - 1))                                 */
      __IOM uint32_t FREQ_SEL    : 1;           /*!< (@ 0x00000007) High speed RC oscillator frequency selection.
                                                                    0=16MHz, 1=20MHz                                           */
      __IOM uint32_t PER_GAIN    : 1;           /*!< (@ 0x00000008) High speed RC oscillator period gain. 1=measured
                                                                    period multiplied by 16                                    */
    } HS_OSC_CFG_b;
  } ;
  __IOM uint32_t   HS_OSC_FILT;                 /*!< (@ 0x0000002C) High speed oscillator calibration filter constant
                                                                    register                                                   */
  __IOM uint32_t   HS_OSC_REF_DIV;              /*!< (@ 0x00000030) High speed oscillator reference frequency divider
                                                                    register                                                   */
  __IOM uint32_t   HS_OSC_20M_FREQ_TUNE;        /*!< (@ 0x00000034) High speed oscillator frequency tune register
                                                                    for 20MHz operation                                        */
  __IOM uint32_t   HS_OSC_16M_FREQ_TUNE;        /*!< (@ 0x00000038) High speed oscillator frequency tune register
                                                                    for 16MHz operation                                        */
  __IM  uint32_t   LP_OSC_PER;                  /*!< (@ 0x0000003C) High speed oscillator period register. It measures
                                                                    last LP_OSC period.                                        */

  union {
    __IM  uint32_t OSC_ON_STS;                  /*!< (@ 0x00000040) Oscillators on status register. It indicates
                                                                    which oscillator is turned on. 0 = disabled,
                                                                    1 = enabled.                                               */

    struct {
      __IM  uint32_t HS_OSC      : 1;           /*!< (@ 0x00000000) High speed RC oscillator turned on                         */
      __IM  uint32_t LP_OSC      : 1;           /*!< (@ 0x00000001) Low power RC oscillator turned on                          */
      __IM  uint32_t HS_XOSC     : 1;           /*!< (@ 0x00000002) High speed crystal oscillator turned on                    */
      __IM  uint32_t LP_XOSC     : 1;           /*!< (@ 0x00000003) Low power crystal oscillator turned on                     */
    } OSC_ON_STS_b;
  } ;

  union {
    __IM  uint32_t OSC_READY_STS;               /*!< (@ 0x00000044) Oscillator ready status register. It indicates
                                                                    which oscillator is turned on and ready.
                                                                    0 = not ready, 1 = ready.                                  */

    struct {
      __IM  uint32_t HS_OSC      : 1;           /*!< (@ 0x00000000) High speed RC oscillator turned on and ready               */
      __IM  uint32_t LP_OSC      : 1;           /*!< (@ 0x00000001) Low power RC oscillator turned on and ready                */
      __IM  uint32_t HS_XOSC     : 1;           /*!< (@ 0x00000002) High speed crystal oscillator turned on and ready          */
      __IM  uint32_t LP_XOSC     : 1;           /*!< (@ 0x00000003) Low power crystal oscillator turned on and ready           */
    } OSC_READY_STS_b;
  } ;

  union {
    __IOM uint32_t INT_STS;                     /*!< (@ 0x00000048) CMU interrupt status register.                             */

    struct {
      __IOM uint32_t CLK_LOSS    : 1;           /*!< (@ 0x00000000) Clock loss interrupt status (same as Clock status
                                                                    register). Cleared writing 1.                              */
      __IOM uint32_t HS_OSC_CAL_MISSED : 1;     /*!< (@ 0x00000001) High speed RC oscillator calibration missed interrupt
                                                                    status. Cleared writing 1.                                 */
      __IOM uint32_t LP_OSC_CAL_MISSED : 1;     /*!< (@ 0x00000002) Low power RC oscillator calibration missed interrupt
                                                                    status. Cleared writing 1.                                 */
      __IOM uint32_t HS_OSC_CAL  : 1;           /*!< (@ 0x00000003) High speed RC oscillator calibration interrupt
                                                                    status. Cleared writing 1.                                 */
      __IOM uint32_t LP_OSC_CAL  : 1;           /*!< (@ 0x00000004) Low power RC oscillator calibration interrupt
                                                                    status. Cleared writing 1.                                 */
    } INT_STS_b;
  } ;

  union {
    __IOM uint32_t LP_XOSC_CFG;                 /*!< (@ 0x0000004C) Low power (tuning fork) crystal oscillator configuration
                                                                    register                                                   */

    struct {
      __IOM uint32_t GM          : 5;           /*!< (@ 0x00000000) Low power crystal oscillator transconductance
                                                                    configuration                                              */
    } LP_XOSC_CFG_b;
  } ;
  __IM  uint32_t   RESERVED;
  __IOM uint32_t   HS_XOSC_GM_CFG;              /*!< (@ 0x00000054) High speed crystal oscillator transconductance
                                                                    configuration register                                     */

  union {
    __IM  uint32_t HS_XOSC_AMPL_CFG;            /*!< (@ 0x00000058) High speed crystal oscillator amplitude regulator
                                                                    configuration register. It should be left
                                                                    at the default value.                                      */

    struct {
      __IM  uint32_t AMPL        : 3;           /*!< (@ 0x00000000) High speed crystal oscillator amplitude                    */
      __IM  uint32_t             : 4;
      __IM  uint32_t REG_EN      : 1;           /*!< (@ 0x00000007) High speed crystal oscillator regulator enable             */
    } HS_XOSC_AMPL_CFG_b;
  } ;

  union {
    __IOM uint32_t HS_XOSC_READY;               /*!< (@ 0x0000005C) This register controls the generation of the
                                                                    crystal oscillator ready signal. It should
                                                                    not normally be changed from the default.                  */

    struct {
      __IOM uint32_t MOD         : 3;           /*!< (@ 0x00000000) High speed crystal oscillator ready mode                   */
      __IOM uint32_t OUT_AMP_DIS : 1;           /*!< (@ 0x00000003) High speed crystal oscillator output amplifier
                                                                    disable. 1=AO disabled                                     */
      __IM  uint32_t             : 2;
      __IM  uint32_t READY_STS   : 1;           /*!< (@ 0x00000006) High speed crystal oscillator READY signal status          */
      __IM  uint32_t SIG_DET_STS : 1;           /*!< (@ 0x00000007) High speed crystal oscillator SIG_DET signal
                                                                    status                                                     */
    } HS_XOSC_READY_b;
  } ;
  __IOM uint32_t   AO_SCRATCH;                  /*!< (@ 0x00000060) Always scratch registers. 32bit of state storage
                                                                    during low power modes.                                    */
} CMU_Type;                                     /*!< Size = 100 (0x64)                                                         */



/* =========================================================================================================================== */
/* ================                                          CC_PWM                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief CC_PWM (CC_PWM)
  */

typedef struct {                                /*!< (@ 0x41400000) CC_PWM Structure                                           */
  __IOM uint32_t   CFG;                         /*!< (@ 0x00000000) CC_PWM configuration register                              */
  __IM  uint32_t   STS;                         /*!< (@ 0x00000004) CC_PWM status register                                     */
  __IOM uint32_t   DATA;                        /*!< (@ 0x00000008) CC_PWM data register                                       */
} CC_PWM_Type;                                  /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                           XBAR                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Crossbar, 32 PIOs pins to communicate with external devices.  These pins are shared between GPIO, ADC, DAC, PWM, UART, SPI and SWD. (XBAR)
  */

typedef struct {                                /*!< (@ 0x40500000) XBAR Structure                                             */

  union {
    __IOM uint32_t ANA_CFG;                     /*!< (@ 0x00000000) XABR analog configuration register. It enables
                                                                    analog function on PAx.                                    */

    struct {
      __IOM uint32_t PA0         : 1;           /*!< (@ 0x00000000) PA0                                                        */
      __IOM uint32_t PA1         : 1;           /*!< (@ 0x00000001) PA1                                                        */
      __IOM uint32_t PA2         : 1;           /*!< (@ 0x00000002) PA2                                                        */
      __IOM uint32_t PA3         : 1;           /*!< (@ 0x00000003) PA3                                                        */
      __IOM uint32_t PA4         : 1;           /*!< (@ 0x00000004) PA4                                                        */
      __IOM uint32_t PA5         : 1;           /*!< (@ 0x00000005) PA5                                                        */
      __IOM uint32_t PA6         : 1;           /*!< (@ 0x00000006) PA6                                                        */
      __IOM uint32_t PA7         : 1;           /*!< (@ 0x00000007) PA7                                                        */
    } ANA_CFG_b;
  } ;

  union {
    __IOM uint32_t OUT_CFG;                     /*!< (@ 0x00000004) Pin output type configuration register. 0 = push/pull,
                                                                    1 = open drain. It requieres output enable
                                                                    in GPIO block. Configuring the pin as an
                                                                    ouput to a peripheral overrides this setting.              */

    struct {
      __IOM uint32_t PA0         : 1;           /*!< (@ 0x00000000) PA0                                                        */
      __IOM uint32_t PA1         : 1;           /*!< (@ 0x00000001) PA1                                                        */
      __IOM uint32_t PA2         : 1;           /*!< (@ 0x00000002) PA2                                                        */
      __IOM uint32_t PA3         : 1;           /*!< (@ 0x00000003) PA3                                                        */
      __IOM uint32_t PA4         : 1;           /*!< (@ 0x00000004) PA4                                                        */
      __IOM uint32_t PA5         : 1;           /*!< (@ 0x00000005) PA5                                                        */
      __IOM uint32_t PA6         : 1;           /*!< (@ 0x00000006) PA6                                                        */
      __IOM uint32_t PA7         : 1;           /*!< (@ 0x00000007) PA7                                                        */
      __IOM uint32_t PB0         : 1;           /*!< (@ 0x00000008) PB0                                                        */
      __IOM uint32_t PB1         : 1;           /*!< (@ 0x00000009) PB1                                                        */
      __IOM uint32_t PB2         : 1;           /*!< (@ 0x0000000A) PB2                                                        */
      __IOM uint32_t PB3         : 1;           /*!< (@ 0x0000000B) PB3                                                        */
      __IOM uint32_t PB4         : 1;           /*!< (@ 0x0000000C) PB4                                                        */
      __IOM uint32_t PB5         : 1;           /*!< (@ 0x0000000D) PB5                                                        */
      __IOM uint32_t PB6         : 1;           /*!< (@ 0x0000000E) PB6                                                        */
      __IOM uint32_t PB7         : 1;           /*!< (@ 0x0000000F) PB7                                                        */
      __IOM uint32_t PC0         : 1;           /*!< (@ 0x00000010) PC0                                                        */
      __IOM uint32_t PC1         : 1;           /*!< (@ 0x00000011) PC1                                                        */
      __IOM uint32_t PC2         : 1;           /*!< (@ 0x00000012) PC2                                                        */
      __IOM uint32_t PC3         : 1;           /*!< (@ 0x00000013) PC3                                                        */
      __IOM uint32_t PC4         : 1;           /*!< (@ 0x00000014) PC4                                                        */
      __IOM uint32_t PC5         : 1;           /*!< (@ 0x00000015) PC5                                                        */
      __IOM uint32_t PC6         : 1;           /*!< (@ 0x00000016) PC6                                                        */
      __IOM uint32_t PC7         : 1;           /*!< (@ 0x00000017) PC7                                                        */
      __IOM uint32_t PR0         : 1;           /*!< (@ 0x00000018) PR0                                                        */
      __IOM uint32_t PR1         : 1;           /*!< (@ 0x00000019) PR1                                                        */
      __IOM uint32_t PR2         : 1;           /*!< (@ 0x0000001A) PR2                                                        */
      __IOM uint32_t PR3         : 1;           /*!< (@ 0x0000001B) PR3                                                        */
      __IOM uint32_t PR4         : 1;           /*!< (@ 0x0000001C) PR4                                                        */
      __IOM uint32_t PR5         : 1;           /*!< (@ 0x0000001D) PR5                                                        */
      __IOM uint32_t PR6         : 1;           /*!< (@ 0x0000001E) PR6                                                        */
      __IOM uint32_t PR7         : 1;           /*!< (@ 0x0000001F) PR7                                                        */
    } OUT_CFG_b;
  } ;

  union {
    __IOM uint32_t PULL_UP_CFG;                 /*!< (@ 0x00000008) XBAR pull-up configuration register. It allows
                                                                    a weak pull-up to be attached to the pin
                                                                    internally. If pull-up and pull-down bits
                                                                    are set bus keeper function is enabled.                    */

    struct {
      __IOM uint32_t PA0         : 1;           /*!< (@ 0x00000000) PA0                                                        */
      __IOM uint32_t PA1         : 1;           /*!< (@ 0x00000001) PA1                                                        */
      __IOM uint32_t PA2         : 1;           /*!< (@ 0x00000002) PA2                                                        */
      __IOM uint32_t PA3         : 1;           /*!< (@ 0x00000003) PA3                                                        */
      __IOM uint32_t PA4         : 1;           /*!< (@ 0x00000004) PA4                                                        */
      __IOM uint32_t PA5         : 1;           /*!< (@ 0x00000005) PA5                                                        */
      __IOM uint32_t PA6         : 1;           /*!< (@ 0x00000006) PA6                                                        */
      __IOM uint32_t PA7         : 1;           /*!< (@ 0x00000007) PA7                                                        */
      __IOM uint32_t PB0         : 1;           /*!< (@ 0x00000008) PB0                                                        */
      __IOM uint32_t PB1         : 1;           /*!< (@ 0x00000009) PB1                                                        */
      __IOM uint32_t PB2         : 1;           /*!< (@ 0x0000000A) PB2                                                        */
      __IOM uint32_t PB3         : 1;           /*!< (@ 0x0000000B) PB3                                                        */
      __IOM uint32_t PB4         : 1;           /*!< (@ 0x0000000C) PB4                                                        */
      __IOM uint32_t PB5         : 1;           /*!< (@ 0x0000000D) PB5                                                        */
      __IOM uint32_t PB6         : 1;           /*!< (@ 0x0000000E) PB6                                                        */
      __IOM uint32_t PB7         : 1;           /*!< (@ 0x0000000F) PB7                                                        */
      __IOM uint32_t PC0         : 1;           /*!< (@ 0x00000010) PC0                                                        */
      __IOM uint32_t PC1         : 1;           /*!< (@ 0x00000011) PC1                                                        */
      __IOM uint32_t PC2         : 1;           /*!< (@ 0x00000012) PC2                                                        */
      __IOM uint32_t PC3         : 1;           /*!< (@ 0x00000013) PC3                                                        */
      __IOM uint32_t PC4         : 1;           /*!< (@ 0x00000014) PC4                                                        */
      __IOM uint32_t PC5         : 1;           /*!< (@ 0x00000015) PC5                                                        */
      __IOM uint32_t PC6         : 1;           /*!< (@ 0x00000016) PC6                                                        */
      __IOM uint32_t PC7         : 1;           /*!< (@ 0x00000017) PC7                                                        */
      __IOM uint32_t PR0         : 1;           /*!< (@ 0x00000018) PR0                                                        */
      __IOM uint32_t PR1         : 1;           /*!< (@ 0x00000019) PR1                                                        */
      __IOM uint32_t PR2         : 1;           /*!< (@ 0x0000001A) PR2                                                        */
      __IOM uint32_t PR3         : 1;           /*!< (@ 0x0000001B) PR3                                                        */
      __IOM uint32_t PR4         : 1;           /*!< (@ 0x0000001C) PR4                                                        */
      __IOM uint32_t PR5         : 1;           /*!< (@ 0x0000001D) PR5                                                        */
      __IOM uint32_t PR6         : 1;           /*!< (@ 0x0000001E) PR6                                                        */
      __IOM uint32_t PR7         : 1;           /*!< (@ 0x0000001F) PR7                                                        */
    } PULL_UP_CFG_b;
  } ;

  union {
    __IOM uint32_t PULL_DOWN_CFG;               /*!< (@ 0x0000000C) XBAR pull-down configuration register. It allows
                                                                    a weak pull-down to be attached to the
                                                                    pin internally. If both pull-up and pull-down
                                                                    bits are set bus keeper function is enabled.               */

    struct {
      __IOM uint32_t PA0         : 1;           /*!< (@ 0x00000000) PA0                                                        */
      __IOM uint32_t PA1         : 1;           /*!< (@ 0x00000001) PA1                                                        */
      __IOM uint32_t PA2         : 1;           /*!< (@ 0x00000002) PA2                                                        */
      __IOM uint32_t PA3         : 1;           /*!< (@ 0x00000003) PA3                                                        */
      __IOM uint32_t PA4         : 1;           /*!< (@ 0x00000004) PA4                                                        */
      __IOM uint32_t PA5         : 1;           /*!< (@ 0x00000005) PA5                                                        */
      __IOM uint32_t PA6         : 1;           /*!< (@ 0x00000006) PA6                                                        */
      __IOM uint32_t PA7         : 1;           /*!< (@ 0x00000007) PA7                                                        */
      __IOM uint32_t PB0         : 1;           /*!< (@ 0x00000008) PB0                                                        */
      __IOM uint32_t PB1         : 1;           /*!< (@ 0x00000009) PB1                                                        */
      __IOM uint32_t PB2         : 1;           /*!< (@ 0x0000000A) PB2                                                        */
      __IOM uint32_t PB3         : 1;           /*!< (@ 0x0000000B) PB3                                                        */
      __IOM uint32_t PB4         : 1;           /*!< (@ 0x0000000C) PB4                                                        */
      __IOM uint32_t PB5         : 1;           /*!< (@ 0x0000000D) PB5                                                        */
      __IOM uint32_t PB6         : 1;           /*!< (@ 0x0000000E) PB6                                                        */
      __IOM uint32_t PB7         : 1;           /*!< (@ 0x0000000F) PB7                                                        */
      __IOM uint32_t PC0         : 1;           /*!< (@ 0x00000010) PC0                                                        */
      __IOM uint32_t PC1         : 1;           /*!< (@ 0x00000011) PC1                                                        */
      __IOM uint32_t PC2         : 1;           /*!< (@ 0x00000012) PC2                                                        */
      __IOM uint32_t PC3         : 1;           /*!< (@ 0x00000013) PC3                                                        */
      __IOM uint32_t PC4         : 1;           /*!< (@ 0x00000014) PC4                                                        */
      __IOM uint32_t PC5         : 1;           /*!< (@ 0x00000015) PC5                                                        */
      __IOM uint32_t PC6         : 1;           /*!< (@ 0x00000016) PC6                                                        */
      __IOM uint32_t PC7         : 1;           /*!< (@ 0x00000017) PC7                                                        */
      __IOM uint32_t PR0         : 1;           /*!< (@ 0x00000018) PR0                                                        */
      __IOM uint32_t PR1         : 1;           /*!< (@ 0x00000019) PR1                                                        */
      __IOM uint32_t PR2         : 1;           /*!< (@ 0x0000001A) PR2                                                        */
      __IOM uint32_t PR3         : 1;           /*!< (@ 0x0000001B) PR3                                                        */
      __IOM uint32_t PR4         : 1;           /*!< (@ 0x0000001C) PR4                                                        */
      __IOM uint32_t PR5         : 1;           /*!< (@ 0x0000001D) PR5                                                        */
      __IOM uint32_t PR6         : 1;           /*!< (@ 0x0000001E) PR6                                                        */
      __IOM uint32_t PR7         : 1;           /*!< (@ 0x0000001F) PR7                                                        */
    } PULL_DOWN_CFG_b;
  } ;

  union {
    __IOM uint32_t PA_CFG;                      /*!< (@ 0x00000010) XBAR PA bank configuration register. It configures
                                                                    PCx as GPIO or output.                                     */

    struct {
      __IOM uint32_t PA0         : 3;           /*!< (@ 0x00000000) PA0                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA1         : 3;           /*!< (@ 0x00000004) PA1                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA2         : 3;           /*!< (@ 0x00000008) PA2                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA3         : 3;           /*!< (@ 0x0000000C) PA3                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA4         : 3;           /*!< (@ 0x00000010) PA4                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA5         : 3;           /*!< (@ 0x00000014) PA5                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA6         : 3;           /*!< (@ 0x00000018) PA6                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PA7         : 3;           /*!< (@ 0x0000001C) PA7                                                        */
    } PA_CFG_b;
  } ;

  union {
    __IOM uint32_t PB_CFG;                      /*!< (@ 0x00000014) XBAR PB bank configuration register. It configures
                                                                    PCx as GPIO or output.                                     */

    struct {
      __IOM uint32_t PB0         : 3;           /*!< (@ 0x00000000) PB0                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB1         : 3;           /*!< (@ 0x00000004) PB1                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB2         : 3;           /*!< (@ 0x00000008) PB2                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB3         : 3;           /*!< (@ 0x0000000C) PB3                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB4         : 3;           /*!< (@ 0x00000010) PB4                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB5         : 3;           /*!< (@ 0x00000014) PB5                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB6         : 3;           /*!< (@ 0x00000018) PB6                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PB7         : 3;           /*!< (@ 0x0000001C) PB7                                                        */
    } PB_CFG_b;
  } ;

  union {
    __IOM uint32_t PC_CFG;                      /*!< (@ 0x00000018) XBAR PC bank configuration register. It configures
                                                                    PCx as GPIO or output.                                     */

    struct {
      __IOM uint32_t PC0         : 3;           /*!< (@ 0x00000000) PC0                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC1         : 3;           /*!< (@ 0x00000004) PC1                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC2         : 3;           /*!< (@ 0x00000008) PC2                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC3         : 3;           /*!< (@ 0x0000000C) PC3                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC4         : 3;           /*!< (@ 0x00000010) PC4                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC5         : 3;           /*!< (@ 0x00000014) PC5                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC6         : 3;           /*!< (@ 0x00000018) PC6                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PC7         : 3;           /*!< (@ 0x0000001C) PC7                                                        */
    } PC_CFG_b;
  } ;

  union {
    __IOM uint32_t PR_CFG;                      /*!< (@ 0x0000001C) XBAR PR bank output configuration register. It
                                                                    configures PRx as GPIO or output.                          */

    struct {
      __IOM uint32_t PR0         : 3;           /*!< (@ 0x00000000) PR0                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR1         : 3;           /*!< (@ 0x00000004) PR1                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR2         : 3;           /*!< (@ 0x00000008) PR2                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR3         : 3;           /*!< (@ 0x0000000C) PR3                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR4         : 3;           /*!< (@ 0x00000010) PR4                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR5         : 3;           /*!< (@ 0x00000014) PR5                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR6         : 3;           /*!< (@ 0x00000018) PR6                                                        */
      __IM  uint32_t             : 1;
      __IOM uint32_t PR7         : 3;           /*!< (@ 0x0000001C) PR7                                                        */
    } PR_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_UART0_CFG;                /*!< (@ 0x00000020) XBAR UART0 input configuration register. It connects
                                                                    the UART0 inputs to selected input pins.
                                                                    GPI or alternate function is still able
                                                                    to drive this pin as well. The pin should
                                                                    be undriven in the GPIO, and the weak pull-up
                                                                    disabled.                                                  */

    struct {
      __IOM uint32_t RX          : 2;           /*!< (@ 0x00000000) UART0 RX input configuration                               */
      __IOM uint32_t CLK         : 2;           /*!< (@ 0x00000002) UART0 CLK input configuration                              */
    } IN_UART0_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_UART1_CFG;                /*!< (@ 0x00000024) XBAR UART1 input configuration register. It connects
                                                                    the UART1 inputs to selected input pins.
                                                                    GPI or alternate function is still able
                                                                    to drive this pin as well. The pin should
                                                                    be undriven in the GPIO, and the weak pull-up
                                                                    disabled.                                                  */

    struct {
      __IOM uint32_t RX          : 2;           /*!< (@ 0x00000000) UART1 RX input configuration                               */
      __IOM uint32_t CLK         : 2;           /*!< (@ 0x00000002) UART1 CLK input configuration                              */
    } IN_UART1_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_SPI1_CFG;                 /*!< (@ 0x00000028) XBAR SPI1 input configuration register. It connects
                                                                    the SPI inputs to selected input pins.
                                                                    GPI or alternate function is still able
                                                                    to drive this pin as well. The pin should
                                                                    be undriven in the GPIO, and the weak pull-up
                                                                    disabled.                                                  */

    struct {
      __IOM uint32_t IN          : 3;           /*!< (@ 0x00000000) SPI1 inputs configuration                                  */
    } IN_SPI1_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_SPI0_CFG;                 /*!< (@ 0x00000028) XBAR SPI0 input configuration register. It connects
                                                                    the SPI inputs to selected input pins.
                                                                    GPI or alternate function is still able
                                                                    to drive this pin as well. The pin should
                                                                    be undriven in the GPIO, and the weak pull-up
                                                                    disabled.                                                  */

    struct {
      __IOM uint32_t IN          : 2;           /*!< (@ 0x00000000) SPI0 inputs configuration                                  */
    } IN_SPI0_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_DMA_CFG;                  /*!< (@ 0x00000030) XBAR DMA trigger configuration register                    */

    struct {
      __IOM uint32_t CH0_TRIG_SEL : 5;          /*!< (@ 0x00000000) DMA channel 0 trigger selection                            */
      __IOM uint32_t CH0_TRIG_TYP : 1;          /*!< (@ 0x00000005) DMA channel 0 trigger type                                 */
      __IM  uint32_t             : 2;
      __IOM uint32_t CH1_TRIG_SEL : 5;          /*!< (@ 0x00000008) DMA channel 1 trigger selection                            */
      __IOM uint32_t CH1_TRIG_TYP : 1;          /*!< (@ 0x0000000D) DMA channel 1 trigger type                                 */
      __IM  uint32_t             : 2;
      __IOM uint32_t CH2_TRIG_SEL : 5;          /*!< (@ 0x00000010) DMA channel 2 trigger selection                            */
      __IOM uint32_t CH2_TRIG_TYP : 1;          /*!< (@ 0x00000015) DMA channel 2 trigger type                                 */
    } IN_DMA_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_ADC_CFG;                  /*!< (@ 0x00000034) XBAR ADC trigger configuration register                    */

    struct {
      __IOM uint32_t TIM_SEL     : 3;           /*!< (@ 0x00000000) ADC timer trigger selection                                */
      __IM  uint32_t             : 5;
      __IOM uint32_t PIN_SEL     : 3;           /*!< (@ 0x00000008) ADC pin trigger selection                                  */
      __IM  uint32_t             : 5;
      __IOM uint32_t TRIG_TYP    : 1;           /*!< (@ 0x00000010) ADC trigger type                                           */
    } IN_ADC_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_TIM0_CFG;                 /*!< (@ 0x00000038) XBAR Timer 0 input configuration register. It
                                                                    connects TIMER 0 external count input to
                                                                    selected input pins. GPI or alternate function
                                                                    is still able to drive this pin as well.
                                                                    The pin should normally be undriven in
                                                                    the GPIO, and the weak pull-up disabled
                                                                    in this block.                                             */

    struct {
      __IOM uint32_t SEL         : 3;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_TIM0_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_TIM1_CFG;                 /*!< (@ 0x0000003C) XBAR Timer 1 input configuration register. It
                                                                    connects TIMER 1 external count input to
                                                                    selected input pins. GPI or alternate function
                                                                    is still able to drive this pin as well.
                                                                    The pin should normally be undriven in
                                                                    the GPIO, and the weak pull-up disabled
                                                                    in this block.                                             */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_TIM1_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_TIM2_CFG;                 /*!< (@ 0x00000040) XBAR Timer 2 input configuration register. It
                                                                    connects TIMER 2 external count input to
                                                                    selected input pins. GPI or alternate function
                                                                    is still able to drive this pin as well.
                                                                    The pin should normally be undriven in
                                                                    the GPIO, and the weak pull-up disabled
                                                                    in this block.                                             */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_TIM2_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_CAPT0_CFG;                /*!< (@ 0x00000044) XBAR Capture 0 input configuration register.
                                                                    It connects Capture 0 input to selected
                                                                    input pins. GPI or alternate function is
                                                                    still able to drive this pin as well. The
                                                                    pin should normally be undriven in the
                                                                    GPIO, and the weak pull-up disabled in
                                                                    this block.                                                */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_CAPT0_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_CAPT1_CFG;                /*!< (@ 0x00000048) XBAR Capture 1 input configuration register.
                                                                    It connects Capture 1 input to selected
                                                                    input pins. GPI or alternate function is
                                                                    still able to drive this pin as well. The
                                                                    pin should normally be undriven in the
                                                                    GPIO, and the weak pull-up disabled in
                                                                    this block.                                                */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_CAPT1_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_CAPT2_CFG;                /*!< (@ 0x0000004C) XBAR Capture 2 input configuration register.
                                                                    It connects Capture 2 input to selected
                                                                    input pins. GPI or alternate function is
                                                                    still able to drive this pin as well. The
                                                                    pin should normally be undriven in the
                                                                    GPIO, and the weak pull-up disabled in
                                                                    this block.                                                */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_CAPT2_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_CAPT3_CFG;                /*!< (@ 0x00000050) XBAR Capture 3 input configuration register.
                                                                    It connects Capture 3 input to selected
                                                                    input pins. GPI or alternate function is
                                                                    still able to drive this pin as well. The
                                                                    pin should normally be undriven in the
                                                                    GPIO, and the weak pull-up disabled in
                                                                    this block.                                                */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_CAPT3_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_EXT_CLK_CFG;              /*!< (@ 0x00000054) XBAR external clock configuration register. It
                                                                    selects PIO to be source of the system
                                                                    clock.                                                     */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) SEL                                                        */
    } IN_EXT_CLK_CFG_b;
  } ;

  union {
    __IOM uint32_t TEST_CFG;                    /*!< (@ 0x00000058) XBAR test configuration register. It enables
                                                                    the individual I/Os for parametric testing
                                                                    in the I/O Parametric test modes                           */

    struct {
      __IOM uint32_t PA0         : 1;           /*!< (@ 0x00000000) PA0                                                        */
      __IOM uint32_t PA1         : 1;           /*!< (@ 0x00000001) PA1                                                        */
      __IOM uint32_t PA2         : 1;           /*!< (@ 0x00000002) PA2                                                        */
      __IOM uint32_t PA3         : 1;           /*!< (@ 0x00000003) PA3                                                        */
      __IOM uint32_t PA4         : 1;           /*!< (@ 0x00000004) PA4                                                        */
      __IOM uint32_t PA5         : 1;           /*!< (@ 0x00000005) PA5                                                        */
      __IOM uint32_t PA6         : 1;           /*!< (@ 0x00000006) PA6                                                        */
      __IOM uint32_t PA7         : 1;           /*!< (@ 0x00000007) PA7                                                        */
      __IOM uint32_t PB0         : 1;           /*!< (@ 0x00000008) PB0                                                        */
      __IOM uint32_t PB1         : 1;           /*!< (@ 0x00000009) PB1                                                        */
      __IOM uint32_t PB2         : 1;           /*!< (@ 0x0000000A) PB2                                                        */
      __IOM uint32_t PB3         : 1;           /*!< (@ 0x0000000B) PB3                                                        */
      __IOM uint32_t PB4         : 1;           /*!< (@ 0x0000000C) PB4                                                        */
      __IOM uint32_t PB5         : 1;           /*!< (@ 0x0000000D) PB5                                                        */
      __IOM uint32_t PB6         : 1;           /*!< (@ 0x0000000E) PB6                                                        */
      __IOM uint32_t PB7         : 1;           /*!< (@ 0x0000000F) PB7                                                        */
      __IOM uint32_t PC0         : 1;           /*!< (@ 0x00000010) PC0                                                        */
      __IOM uint32_t PC1         : 1;           /*!< (@ 0x00000011) PC1                                                        */
      __IOM uint32_t PC2         : 1;           /*!< (@ 0x00000012) PC2                                                        */
      __IOM uint32_t PC3         : 1;           /*!< (@ 0x00000013) PC3                                                        */
      __IOM uint32_t PC4         : 1;           /*!< (@ 0x00000014) PC4                                                        */
      __IOM uint32_t PC5         : 1;           /*!< (@ 0x00000015) PC5                                                        */
      __IOM uint32_t PC6         : 1;           /*!< (@ 0x00000016) PC6                                                        */
      __IOM uint32_t PC7         : 1;           /*!< (@ 0x00000017) PC7                                                        */
      __IOM uint32_t PR0         : 1;           /*!< (@ 0x00000018) PR0                                                        */
      __IOM uint32_t PR1         : 1;           /*!< (@ 0x00000019) PR1                                                        */
      __IOM uint32_t PR2         : 1;           /*!< (@ 0x0000001A) PR2                                                        */
      __IOM uint32_t PR3         : 1;           /*!< (@ 0x0000001B) PR3                                                        */
      __IOM uint32_t PR4         : 1;           /*!< (@ 0x0000001C) PR4                                                        */
      __IOM uint32_t PR5         : 1;           /*!< (@ 0x0000001D) PR5                                                        */
      __IOM uint32_t PR6         : 1;           /*!< (@ 0x0000001E) PR6                                                        */
      __IOM uint32_t PR7         : 1;           /*!< (@ 0x0000001F) PR7                                                        */
    } TEST_CFG_b;
  } ;

  union {
    __IOM uint32_t IN_MTB_CFG;                  /*!< (@ 0x0000005C) XBAR MTB configuration register. It connects
                                                                    PIOs to the trace start (TSTART) and trace
                                                                    stop (TSTOP) signals, as well as setting
                                                                    the debugenable (NIDEN) signal. MTB configuration
                                                                    allows a single pin to control the start/stop
                                                                    control (see 3rd configuration)                            */

    struct {
      __IOM uint32_t SEL         : 2;           /*!< (@ 0x00000000) TSTART and TSTOP input selection                           */
      __IOM uint32_t NIDEN       : 1;           /*!< (@ 0x00000002) ?                                                          */
    } IN_MTB_CFG_b;
  } ;
} XBAR_Type;                                    /*!< Size = 96 (0x60)                                                          */



/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief The Cyclic Redundancy Check Module is a peripheral that calculates a 32 bit CRC  using the standard Ethernet polynomial 0x04C11DB7. (CRC)
  */

typedef struct {                                /*!< (@ 0x40D00000) CRC Structure                                              */
  __IOM uint32_t   RESULT;                      /*!< (@ 0x00000000) CRC result register                                        */
  __OM  uint32_t   INPUT;                       /*!< (@ 0x00000004) CRC input register.                                        */
} CRC_Type;                                     /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                            DMA                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief DMA acts as another bus master on the AHB Bus to facilitate data transfers. (DMA)
  */

typedef struct {                                /*!< (@ 0x40800000) DMA Structure                                              */

  union {
    __IM  uint32_t STS;                         /*!< (@ 0x00000000) DMA status register                                        */

    struct {
      __IM  uint32_t EN          : 1;           /*!< (@ 0x00000000) DMA enable status                                          */
      __IM  uint32_t             : 3;
      __IM  uint32_t STATE       : 4;           /*!< (@ 0x00000004) DMA control current state                                  */
      __IM  uint32_t             : 8;
      __IM  uint32_t CH_NUM      : 5;           /*!< (@ 0x00000010) Number of available DMA channels minus one                 */
      __IM  uint32_t             : 7;
      __IM  uint32_t TEST        : 4;           /*!< (@ 0x0000001C) Test logic integration status                              */
    } STS_b;
  } ;

  union {
    __OM  uint32_t CFG;                         /*!< (@ 0x00000004) DMA configuration register                                 */

    struct {
      __OM  uint32_t EN          : 1;           /*!< (@ 0x00000000) DMA enable                                                 */
      __IM  uint32_t             : 4;
      __OM  uint32_t CH_PROT_CTL : 3;           /*!< (@ 0x00000005) Channel protection control                                 */
    } CFG_b;
  } ;
  __IOM uint32_t   CTL_BASE_PTR;                /*!< (@ 0x00000008) Channel control data base pointer                          */
  __IM  uint32_t   ALT_CTL_BASE_PTR;            /*!< (@ 0x0000000C) Channel alternate control data base pointer                */

  union {
    __IM  uint32_t WAIT_ON_REQ_STS;             /*!< (@ 0x00000010) Channel wait on request status register                    */

    struct {
      __IM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } WAIT_ON_REQ_STS_b;
  } ;

  union {
    __OM  uint32_t SW_REQ;                      /*!< (@ 0x00000014) Channel software request register                          */

    struct {
      __OM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __OM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __OM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } SW_REQ_b;
  } ;

  union {
    __IOM uint32_t USE_BURST_SET;               /*!< (@ 0x00000018) Channel use burst set register                             */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } USE_BURST_SET_b;
  } ;

  union {
    __OM  uint32_t USE_BURST_CLR;               /*!< (@ 0x0000001C) Channel use burst clear register                           */

    struct {
      __OM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __OM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __OM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } USE_BURST_CLR_b;
  } ;

  union {
    __IOM uint32_t REQ_MASK_SET;                 /*!< (@ 0x00000020) Channel request mask set register                          */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } REQ_MASK_SET_b;
  } ;

  union {
    __OM  uint32_t REQ_MASK_CLR;                /*!< (@ 0x00000024) Channel request mask clear register                        */

    struct {
      __OM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __OM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __OM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } REQ_MASK_CLR_b;
  } ;

  union {
    __IOM uint32_t EN_SET;                      /*!< (@ 0x00000028) Channel enable set register                                */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } EN_SET_b;
  } ;

  union {
    __OM  uint32_t EN_CLR;                      /*!< (@ 0x0000002C) Channel enable clear register                              */

    struct {
      __OM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __OM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __OM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } EN_CLR_b;
  } ;

  union {
    __IOM uint32_t PRI_ALT_SEL_SET;             /*!< (@ 0x00000030) Primary/alternate descriptor selection set register
                                                                    0 = primary, 1 = alternate                                 */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } PRI_ALT_SEL_SET_b;
  } ;

  union {
    __OM  uint32_t PRI_ALT_SEL_CLR;             /*!< (@ 0x00000034) Primary/alternate descriptor selection clear
                                                                    register 0 = primary, 1 = alternate                        */

    struct {
      __OM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __OM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __OM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } PRI_ALT_SEL_CLR_b;
  } ;

  union {
    __IOM uint32_t PRIO_SET;                    /*!< (@ 0x00000038) Channel priority set register                              */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } PRIO_SET_b;
  } ;

  union {
    __OM  uint32_t PRIO_CLR;                    /*!< (@ 0x0000003C) Channel priority clear register                            */

    struct {
      __OM  uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __OM  uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __OM  uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
    } PRIO_CLR_b;
  } ;
  __IM  uint32_t   RESERVED[3];
  __IOM uint32_t   ERR_CLR;                     /*!< (@ 0x0000004C) Bus error clear register                                   */

  union {
    __IOM uint32_t INT_EN;                      /*!< (@ 0x00000050) DMA interrupt enable register                              */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
      __IOM uint32_t ERR         : 1;           /*!< (@ 0x00000003) ERR                                                        */
    } INT_EN_b;
  } ;

  union {
    __IOM uint32_t INT_STS;                     /*!< (@ 0x00000054) DMA interrupt status register                              */

    struct {
      __IOM uint32_t CH0         : 1;           /*!< (@ 0x00000000) CH0                                                        */
      __IOM uint32_t CH1         : 1;           /*!< (@ 0x00000001) CH1                                                        */
      __IOM uint32_t CH2         : 1;           /*!< (@ 0x00000002) CH2                                                        */
      __IOM uint32_t ERR         : 1;           /*!< (@ 0x00000003) ERR                                                        */
    } INT_STS_b;
  } ;
} DMA_Type;                                     /*!< Size = 88 (0x58)                                                          */



/* =========================================================================================================================== */
/* ================                                           FLASH                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Flash controller is used to erase or program the flash memory. (FLASH)
  */

typedef struct {                                /*!< (@ 0x40C00000) FLASH Structure                                            */

  union {
    __IOM uint32_t CTL;                         /*!< (@ 0x00000000) Flash controler control register. It contain
                                                                    also state of the flash controler.                         */

    struct {
      __IOM uint32_t START_PROG  : 1;           /*!< (@ 0x00000000) START_PROG                                                 */
      __IOM uint32_t START_PAGE_ERASE : 1;      /*!< (@ 0x00000001) START_PAGE_ERASE                                           */
      __IOM uint32_t START_MASS_ERASE : 1;      /*!< (@ 0x00000002) START_MASS_ERASE                                           */
      __IOM uint32_t HALF_WORD   : 1;           /*!< (@ 0x00000003) HALF_WORD                                                  */
      __IOM uint32_t UP_HALF     : 1;           /*!< (@ 0x00000004) UP_HALF                                                    */
      __IM  uint32_t STATE       : 1;           /*!< (@ 0x00000005) Controler state                                            */
      __IM  uint32_t             : 10;
      __OM  uint32_t KEY         : 16;          /*!< (@ 0x00000010) Keyword to prevent inadvertent changes to the
                                                                    flash. It must be written to 0xA45B to
                                                                    enable starting erase or program operation.
                                                                    (setting any of the bits 0-2)                              */
    } CTL_b;
  } ;
  __IOM uint32_t   ADDR;                        /*!< (@ 0x00000004) Flash controler address register. Address is
                                                                    used for erase and program operations.                     */
  __IOM uint32_t   FLASHDATA;                   /*!< (@ 0x00000008) Flash controler data register                              */

  union {
    __IOM uint32_t INT_EN;                      /*!< (@ 0x0000000C) Flash controler interrupt enable register                  */

    struct {
      __IOM uint32_t PROG        : 1;           /*!< (@ 0x00000000) Enable program interrupt. 1= enabled, 0= disabled          */
      __IOM uint32_t ERASE       : 1;           /*!< (@ 0x00000001) Enable erase interrupt. 1= enabled, 0= disabled            */
      __IOM uint32_t PROTECT     : 1;           /*!< (@ 0x00000002) Enable protected page violation interrupt. 1=
                                                                    enabled, 0 = disabled                                      */
    } INT_EN_b;
  } ;
  __IM  uint32_t   RESERVED;

  union {
    __IOM uint32_t INT_STS;                     /*!< (@ 0x00000014) Flash controler interrupt status register                  */

    struct {
      __IOM uint32_t PROG        : 1;           /*!< (@ 0x00000000) Program interrupt status. Write 1 to clear.                */
      __IOM uint32_t ERASE       : 1;           /*!< (@ 0x00000001) Erase interrupt status. Write 1 to clear.                  */
      __IOM uint32_t PROTECT     : 1;           /*!< (@ 0x00000002) Protected page violation interrupt status. Write
                                                                    1 to clear.                                                */
    } INT_STS_b;
  } ;
  __IOM uint32_t   PROTECT0;                    /*!< (@ 0x00000018) Flash page protection register 0                           */
  __IOM uint32_t   PROTECT1;                    /*!< (@ 0x0000001C) Flash page protection register 1                           */
  __IOM uint32_t   PROTECT2;                    /*!< (@ 0x00000020) Flash page protection register 2                           */
  __IOM uint32_t   PROTECT3;                    /*!< (@ 0x00000024) Flash page protection register 3                           */

  union {
    __IOM uint32_t DMA_EN;                      /*!< (@ 0x00000028) DMA_EN                                                     */

    struct {
      __IOM uint32_t PROG        : 1;           /*!< (@ 0x00000000) Enable DMA signal on program complete                      */
      __IOM uint32_t ERASE       : 1;           /*!< (@ 0x00000001) Enable DMA signal on erase complete                        */
    } DMA_EN_b;
  } ;
} FLASH_Type;                                   /*!< Size = 44 (0x2c)                                                          */



/* =========================================================================================================================== */
/* ================                                           GPIO                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO block, is a general-purpose I/O interface unit that provides a 32-bit I/O. (GPIO)
  */

typedef struct {                                /*!< (@ 0x40000000) GPIO Structure                                             */
  __IM  uint32_t   DATA;                        /*!< (@ 0x00000000) GPIO data register. It returns synchronized value
                                                                    currently on the pins.                                     */
  __IOM uint32_t   DATA_OUT;                    /*!< (@ 0x00000004) GPIO data out register. It indicates value applied
                                                                    on pin when GPIO is configured as output.                  */
  __IOM uint32_t   OUT_EN;                      /*!< (@ 0x00000008) GPIO output enable register. 0=Input, 1 = Output           */
  __IOM uint32_t   INT_EN;                      /*!< (@ 0x0000000C) GPIO interrupt enable register.                            */
  __IOM uint32_t   INT_POL;                     /*!< (@ 0x00000010) GPIO interrupt polarity register. 0 = Low or
                                                                    Falling Edge, 1 = High or Rising Edge                      */
  __IOM uint32_t   INT_TYP;                     /*!< (@ 0x00000014) GPIO interrupt type register. 0 = Level triggered,
                                                                    1 = Edge triggered                                         */
  __IOM uint32_t   DMA_TRIG_EN;                 /*!< (@ 0x00000018) PIO DMA trigger enable register. DMA polarity
                                                                    and type configuration are the same as
                                                                    the interrupt polarity and type.                           */
  __IOM uint32_t   INT_STS;                     /*!< (@ 0x0000001C) GPIO interrupt enable register                             */
} GPIO_Type;                                    /*!< Size = 32 (0x20)                                                          */



/* =========================================================================================================================== */
/* ================                                            I2C                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief I2C (I2C)
  */

typedef struct {                                /*!< (@ 0x41D00000) I2C Structure                                              */
  __IOM uint32_t   CFG;                         /*!< (@ 0x00000000) I2C configuration register                                 */

  union {
    __OM  uint32_t CTL;                         /*!< (@ 0x00000004) I2C control register                                       */

    struct {
      __OM  uint32_t ACK         : 1;           /*!< (@ 0x00000000) 1: Issue an acknowledge on the I2C interface
                                                                    bus                                                        */
      __OM  uint32_t NACK        : 1;           /*!< (@ 0x00000001) 1: Issue a not acknowledge on the I2C interface
                                                                    bus                                                        */
      __IM  uint32_t             : 1;
      __OM  uint32_t STOP        : 1;           /*!< (@ 0x00000003) 1: Issue a stop condition the I2C interface bus            */
      __OM  uint32_t LAST_DATA   : 1;           /*!< (@ 0x00000004) 1: Indicate that the current data is the last
                                                                    byte of a data transfer                                    */
      __OM  uint32_t RST         : 1;           /*!< (@ 0x00000005) 1: Reset the I2C interface                                 */
    } CTL_b;
  } ;
  __IOM uint32_t   DATA;                        /*!< (@ 0x00000008) I2C data register                                          */
  __IOM uint32_t   DATA_MIRROR;                 /*!< (@ 0x0000000C) I2C data mirror register                                   */
  __OM  uint32_t   ADDR_START;                  /*!< (@ 0x00000010) I2C status register                                        */
  __IM  uint32_t   STS;                         /*!< (@ 0x00000014) I2C status register                                        */
  __IOM uint32_t   INT_STS;                     /*!< (@ 0x00000018) I2C interrup status register                               */
} I2C_Type;                                     /*!< Size = 28 (0x1c)                                                          */



/* =========================================================================================================================== */
/* ================                                            PMU                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief NEBO has an advanced power management unit (PMU) three operating modes: Run, Sleep, Deep Sleep. (PMU)
  */

typedef struct {                                /*!< (@ 0x40400000) PMU Structure                                              */
  __IOM uint32_t   MOD;                         /*!< (@ 0x00000000) PMU mode register. It is used to configure low-power
                                                                    modes. Entry into these modes may be a
                                                                    combination of setting this register along
                                                                    with specific processor instruction.                       */

  union {
    __IOM uint32_t PD;                          /*!< (@ 0x00000004) PMU power down register. It is used to power
                                                                    down parts of the design.                                  */

    struct {
      __IOM uint32_t SRAM2K      : 1;           /*!< (@ 0x00000000) Power down 2K SRAM bank                                    */
      __IOM uint32_t SRAM6K      : 1;           /*!< (@ 0x00000001) Power down 6K SRAM bank                                    */
    } PD_b;
  } ;

  union {
    __IM  uint32_t STS;                         /*!< (@ 0x00000008) PMU status register                                        */

    struct {
      __IM  uint32_t WDOG        : 1;           /*!< (@ 0x00000000) Watchdog Reset. Reading 1 indicates that the
                                                                    last reset was caused by a watchdog reset                  */
      __IM  uint32_t WU          : 1;           /*!< (@ 0x00000001) Wakeup Reset. Reading 1 indicates that the last
                                                                    reset was caused by a wakeup from sleep
                                                                    or deep sleep                                              */
    } STS_b;
  } ;
} PMU_Type;                                     /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                            SPI0                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief SPI0 (SPI0)
  */

struct SPI0_Reg {
  __IOM uint32_t   A15[32768];                  /*!< (@ 0x00000000) SPI 15 bit Address Transactions                            */
  __IOM uint32_t   A7[128];                     /*!< (@ 0x00000200) SPI 7 bit Address Transactions                             */
  __IOM uint32_t   NOA[8];                      /*!< (@ 0x00000400) SPI no Address Transactions                                */
  __IOM uint32_t   RESERVED[32632];
};

typedef struct {                                /*!< (@ 0x41900000) SPI0 Structure                                             */
  union {
    struct {
      struct SPI0_Reg REGD8;
      struct SPI0_Reg REGD8NB;
      struct SPI0_Reg REGD16;
      struct SPI0_Reg REGD16NB;
      uint32_t RESERVED1[0x007C0000];
      struct SPI0_Reg REGD24;
      struct SPI0_Reg REGD24NB;
      struct SPI0_Reg REGD32;
      struct SPI0_Reg REGD32NB;
    };
    struct {
      __IOM uint32_t   RESERVED[524284 + 0x007C0000];
      __IOM uint32_t   DATA;                    /*!< (@ 0x020FFFF0) SPI most recently received data                            */
      __IOM uint32_t   ADDR;                    /*!< (@ 0x020FFFF4) SPI most recently transmitted address                      */
      union {
        __IOM uint32_t   CONFIG;                /*!< (@ 0x020FFFF8) SPI configuration register                                 */
        struct {
          __IOM uint32_t PRESCALER   : 2;       /*!< (@ 0x00000000) SPI master clock prescaler                                 */
          __IOM uint32_t RESERVED    : 27;
          __IOM uint32_t SEL         : 1;       /*!< (@ 0x0000001D) SEL line status                                            */
          __IOM uint32_t WRITE       : 1;       /*!< (@ 0x0000001E) Current or last access is/was write                        */
          __IOM uint32_t BUSY        : 1;       /*!< (@ 0x0000001F) Access ongoing                                             */
        } CONFIG_b;
      };
      __IOM uint32_t   STAT;                    /*!< (@ 0x020FFFFC) SPI most recently received status (MISO bits during addr)  */
    };
  };
} SPI0_Type;                                    /*!< Size = 35651584 (0x02200000)                                              */



/* =========================================================================================================================== */
/* ================                                            SPI1                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief SPI1 (SPI1)
  */

typedef struct {                                /*!< (@ 0x41A00000) SPI1 Structure                                             */
  __IOM uint32_t   DATA;                        /*!< (@ 0x00000000) SPI Shift Register: Contains the receive and
                                                                    transmit data.                                             */
  __IOM uint32_t   CFG;                         /*!< (@ 0x00000004) SPI configuration register                                 */
  __IM  uint32_t   STS;                         /*!< (@ 0x00000008) SPI status register                                        */
} SPI1_Type;                                    /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                          TICKER                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief The ticker timer enables software to schedule events on given tick or timeslot. (TICKER)
  */

typedef struct {                                /*!< (@ 0x04000000) TICKER Structure                                           */
    union
    {
        __IOM uint32_t   TTCFG;                 /*!< (@ 0x00000000) TICKER configuration register                              */
        struct
        {
            __IOM uint32_t TTSRC      : 3;
            __IOM uint32_t TTDIV      : 3;
            __IOM uint32_t RESERVED   : 2;
            __IOM uint32_t TTIRQE     : 1;
        } TTCFG_b;
    };

  __IOM  uint32_t  TTSTS;                       /*!< (@ 0x00000004) TICKER status register                                     */
  __IM  uint32_t   TTCNT;                       /*!< (@ 0x00000008) TICKER counter register                                    */
  __IOM uint32_t   TTEVT;                       /*!< (@ 0x0000000C) TICKER period register                                     */
} TICKER_Type;                                  /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                            TIM                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief TIM: 16-bit count up/down timer with prescaler (TIM)
  */

typedef struct {                                /*!< (@ 0x41100000) TIM Structure                                              */
  __IOM uint32_t   CNT;                         /*!< (@ 0x00000000) Timer counter register (unsigned)                          */
  __IOM uint32_t   PER;                         /*!< (@ 0x00000004) Timer period register (unsigned)                           */

  union {
    __IOM uint32_t CFG;                         /*!< (@ 0x00000008) Timer configuration register                               */

    struct {
      __IOM uint32_t MOD         : 4;           /*!< (@ 0x00000000) Operating mode                                             */
      __IOM uint32_t PER_BUF     : 2;           /*!< (@ 0x00000004) Period buffering                                           */
      __IM  uint32_t             : 2;
      __IOM uint32_t CLK_SEL     : 3;           /*!< (@ 0x00000008) Timer clock source selection                               */
      __IOM uint32_t CLK_DIV     : 3;           /*!< (@ 0x0000000B) Timer clock divider                                        */
      __IOM uint32_t CLK_INV     : 1;           /*!< (@ 0x0000000E) Timer clock inversion. If set, the selected clock
                                                                    is inverted before being fed into the timer
                                                                    core.                                                      */
      __IOM uint32_t CLK_SYNC    : 1;           /*!< (@ 0x0000000F) Timer external input synchronization. if set,
                                                                    the timer input signal EXT_CNT is synchronized
                                                                    to PCLK. If cleared, EXT_CNT clocks the
                                                                    timer asynchronously. Applicable if EXT_CNT
                                                                    is selected as clock source.                               */
      __IOM uint32_t INT_EN_OVER : 1;           /*!< (@ 0x00000010) TxOVER interrupt enable                                    */
      __IOM uint32_t INT_EN_UNDER : 1;          /*!< (@ 0x00000011) TxUNDER interrupt enable                                   */
      __IOM uint32_t INT_EN_PER_EMPTY : 1;      /*!< (@ 0x00000012) TxPERIOD empty interrupt enable                            */
      __IOM uint32_t INT_EN_PER_UNDER : 1;      /*!< (@ 0x00000013) TxPERIOD underrun interrupt enable                         */
    } CFG_b;
  } ;

  union {
    __IOM uint32_t INT_STS;                     /*!< (@ 0x0000000C) Timer interrupt status register                            */

    struct {
      __IOM uint32_t OVER        : 1;           /*!< (@ 0x00000000) TxOVER interrupt (clears on write 1)                       */
      __IOM uint32_t UNDER       : 1;           /*!< (@ 0x00000001) TxUNDER interrupt (cleared on write 1)                     */
      __IOM uint32_t OVER_MISSED : 1;           /*!< (@ 0x00000002) TxOVER interrupt missed (clears on read)                   */
      __IOM uint32_t UNDER_MISSED : 1;          /*!< (@ 0x00000003) TxUNDER interrupt missed (cleared on write 1)              */
      __IOM uint32_t PER_EMPTY   : 1;           /*!< (@ 0x00000004) TxPERIOD empty interrupt. (cleared writing a
                                                                    new value to the TPERIOD register)                         */
      __IOM uint32_t PER_UNDER   : 1;           /*!< (@ 0x00000005) TxPERIOD underrun interrupt (cleared on write
                                                                    1)                                                         */
    } INT_STS_b;
  } ;
} TIM_Type;                                     /*!< Size = 16 (0x10)                                                          */

/* =========================================================================================================================== */
/* ================                                           AES                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Hardware Accellerated AES Encryption and Decryption enabled peripheral (AES)
  */

typedef struct {                                /*!< (@ 0x40900000) AES Structure                                             */
  __IOM uint32_t AESCTL;                        /*!< (@ 0x00000000) AES control register                                      */
  __OM  uint32_t AESDIN;                        /*!< (@ 0x00000004) AES data in register                                      */
  __IM  uint32_t AESDOUT;                       /*!< (@ 0x00000008) AES data out register                                     */
} AES_Type;                                     /*!< Size = 12 (0xC)                                                          */



/* =========================================================================================================================== */
/* ================                                           TRNG                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief The True Random Number Generator is a peripheral generating random numbers. (TRNG)
  */

typedef struct {                                /*!< (@ 0x40A00000) TRNG Structure                                             */
  __IOM uint32_t   CFG;                         /*!< (@ 0x00000000) TRNG configuration register                                */
  __IM  uint32_t   DATA;                        /*!< (@ 0x00000004) TRNG data (byte) register                                  */
} TRNG_Type;                                    /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                           UART                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief UART0 (UART)
  */

typedef struct {                                /*!< (@ 0x41B00000) UART Structure                                             */
  __IOM uint32_t   DATA;                        /*!< (@ 0x00000000) Shift Register: Contains the receive and transmit
                                                                    data.                                                      */

  union {
    __IOM uint32_t CFG;                         /*!< (@ 0x00000004) UARTx configuration register                               */

    struct {
      __IOM uint32_t BRG         : 2;           /*!< (@ 0x00000000) Baud rate generator source. (TxOUT = 16x Baudrate)
                                                                    In SYNC mode interpretation is different:
                                                                    X0: receiver samples on falling edge X1:
                                                                    receiver samples on rising edge 0X: transmitter
                                                                    changes on rising edge 1X: transmitter
                                                                    changes on falling edge                                    */
      __IOM uint32_t WORD_LEN    : 3;           /*!< (@ 0x00000002) Word length                                                */
      __IOM uint32_t STOP_BITS   : 1;           /*!< (@ 0x00000005) Stop bits configuration. 0 = 1 Stop bit, 1 =
                                                                    2 Stop bits                                                */
      __IOM uint32_t RX_DGL_EN   : 1;           /*!< (@ 0x00000006) Receiver deglitch enable                                   */
      __IOM uint32_t TX_BRK_EN   : 1;           /*!< (@ 0x00000007) Transmit break enable                                      */
      __IOM uint32_t RX_EN       : 1;           /*!< (@ 0x00000008) Receiver enable                                            */
      __IOM uint32_t TX_EN       : 1;           /*!< (@ 0x00000009) Transmitter enable                                         */
      __IOM uint32_t INT_EN_RX   : 1;           /*!< (@ 0x0000000A) Receiver interrupt enable                                  */
      __IOM uint32_t INT_EN_TX   : 1;           /*!< (@ 0x0000000B) Transmitter interrupt enable                               */
      __IOM uint32_t INT_EN_RX_FE : 1;          /*!< (@ 0x0000000C) Receiver framing error interrupt enable                    */
      __IOM uint32_t INT_EN_RX_BRK : 1;         /*!< (@ 0x0000000D) Receiver break detect change interrupt enable.
                                                                    Interrupt is activated if UBRKDET changes,
                                                                    and cleared when UBRKDET is written to
                                                                    1.                                                         */
      __IOM uint32_t MCE         : 1;           /*!< (@ 0x0000000E) Multiprocessor communication enable, If set,
                                                                    the received byte is only stored in the
                                                                    receive register if the topmost bit is
                                                                    set.                                                       */
      __IOM uint32_t SYNC        : 1;           /*!< (@ 0x0000000F) Synchronous (USART) mode if set (in this case,
                                                                    BRG sets the clock inversion)                              */
      __IOM uint32_t INT_EN_TX_IDLE : 1;        /*!< (@ 0x00000010) Transmitter idle interrupt enable                          */
    } CFG_b;
  } ;

  union {
    __IOM uint32_t STS;                         /*!< (@ 0x00000008) UART status register.                                      */

    struct {
      __IOM uint32_t RX_FULL     : 1;           /*!< (@ 0x00000000) Rx full interrupt status                                   */
      __IOM uint32_t RX_OVER     : 1;           /*!< (@ 0x00000001) Rx overrun interrupt status (cleared on write
                                                                    1) (cleared on write 1)                                    */
      __IOM uint32_t TX_EMPTY    : 1;           /*!< (@ 0x00000002) Tx empty interrupt status                                  */
      __IOM uint32_t TX_UNDER    : 1;           /*!< (@ 0x00000003) Tx underrun interrupt status (cleared on write
                                                                    1)                                                         */
      __IOM uint32_t RX_FE       : 1;           /*!< (@ 0x00000004) Rx framing error interrupt status (cleared on
                                                                    write 1)                                                   */
      __IOM uint32_t RX_BRK      : 1;           /*!< (@ 0x00000005) Rx break interrupt status (cleared on write 1)             */
      __IOM uint32_t TX_IDLE     : 1;           /*!< (@ 0x00000006) Tx idle status                                             */
    } STS_b;
  } ;
} UART_Type;                                    /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                            WUT                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief The Wakeup timer enables wakeup from low power modes. (WUT)
  */

typedef struct {                                /*!< (@ 0x40100000) WUT Structure                                              */
  union
  {
      __IOM uint32_t   WTCFG;                   /*!< (@ 0x00000000) WUT configuration register                             */
      struct
      {
          __IOM uint32_t WTSRC      : 3;
          __IOM uint32_t WTDIV      : 3;
          __IOM uint32_t RESERVED   : 2;
          __IOM uint32_t WTIRQE     : 1;
      } WTCFG_b;
  };
  __IOM uint32_t   WTSTS;                       /*!< (@ 0x00000004) WUT status register                                        */
  __IM  uint32_t   WTCNT;                       /*!< (@ 0x00000008) WUT counter register                                       */
  __IOM uint32_t   WTEVT;                       /*!< (@ 0x0000000C) WUT period register                                        */
} WUT_Type;                                     /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                           WDOG                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief The watchdog module applies a reset to a system in the event of a software failure,  providing a way to recover from software crashes.  The watchdog can be enabled or disabled as required. (WDOG)
  */

typedef struct {                                /*!< (@ 0x40F00000) WDOG Structure                                             */
  __IOM uint32_t   LOAD;                        /*!< (@ 0x00000000) Watchdog load register.                                    */
  __IM  uint32_t   VAL;                         /*!< (@ 0x00000004) Watchdog value register.                                   */

  union {
    __IOM uint32_t CFG;                         /*!< (@ 0x00000008) Watchdog configuration register                            */

    struct {
      __IOM uint32_t EN          : 1;           /*!< (@ 0x00000000) Enable the count down and the interrupt. Set
                                                                    High to enable the counter and the interrupt,
                                                                    and set LOW to disable the counter and
                                                                    interrupt. Writing it from 0 to 1 reloads
                                                                    the counter from the value in WDOGLOAD.                    */
      __IOM uint32_t RST_EN      : 1;           /*!< (@ 0x00000001) Enable Watchdog reset output, WDOGRES. Acts as
                                                                    a mask for the reset output. Set HIGH to
                                                                    enable the reset, and LOW to disable the
                                                                    reset.                                                     */
    } CFG_b;
  } ;
  __IM  uint32_t   RESERVED;
  __IM  uint32_t   INT_STS_RAW;                 /*!< (@ 0x00000010) Watchdog raw interrupt status register. It indicates
                                                                    the raw interrupt status from the counter.
                                                                    This value is ANDed with the interrupt
                                                                    enable bit from the configuration register
                                                                    to create the masked interrupt, that is
                                                                    passed to the interrupt output pin.                        */
  __IOM uint32_t   INT_STS;                     /*!< (@ 0x00000014) Watchdog interrupt status register. It indicates
                                                                    the masked interrupt status from the counter.
                                                                    This value is the logical AND of the raw
                                                                    interrupt status with the INT_EN bit from
                                                                    the configuration register, and is the
                                                                    same value that is passed to the interrupt
                                                                    output pin.                                                */
  __IM  uint32_t   RESERVED1[762];
  __IOM uint32_t   LOCK;                        /*!< (@ 0x00000C00) Watchdog lock register. Use of this register
                                                                    causes write-access to all other registers
                                                                    to be disabled. This is to prevent rogue
                                                                    software from disabling the watchdog functionality.
                                                                    Enable write access to all other registers
                                                                    by writing 0x1ACCE551. Disable write access
                                                                    by writing any other value. Read: 0 = write
                                                                    access to all other registers is enabled
                                                                    1 = write access to all other registers
                                                                    is disabled                                                */
  __IM  uint32_t   RESERVED2[191];
  __IOM uint32_t   TEST_CFG;                    /*!< (@ 0x00000F00) Watchdog integration test configuration register.
                                                                    It is a single-bit register that enables
                                                                    the integration test mode. When set HIGH,
                                                                    the masked interrupt output, WDOGINT, and
                                                                    reset output, WDOGRES, are directly controlled
                                                                    by the test output set register.                           */

  union {
    __OM  uint32_t TEST_OUT;                    /*!< (@ 0x00000F04) Watchdog tst output register. When in integration
                                                                    test mode, the enabled interrupt output
                                                                    and reset output are driven directly from
                                                                    the values in this register.                               */

    struct {
      __OM  uint32_t RST         : 1;           /*!< (@ 0x00000000) Value output on WDOGRES when in integration test
                                                                    mode                                                       */
      __OM  uint32_t INT         : 1;           /*!< (@ 0x00000001) Value output on WDOGINT when in integration test
                                                                    mode                                                       */
    } TEST_OUT_b;
  } ;
} WDOG_Type;                                    /*!< Size = 3848 (0xf08)                                                       */



/* =========================================================================================================================== */
/* ================                                           MISC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Miscellaneous control interface allows re-configuring various circuits and modules for functional operation and security. (MISC)
  */

typedef struct {                                /*!< (@ 0x41F00000) TEST Structure                                             */
  __IM  uint32_t   RESERVED[11];

  __IOM uint32_t   SCRATCH;                     /*!< (@ 0x0000002C) The scratch register is a generic register that
                                                                    may be used by the program code.                           */
  __IM  uint32_t   RESERVED2[4];
  __IOM uint32_t   TRIM;                        /*!< (@ 0x00000040) Trim register is used to hold factory trim settings
                                                                    for analog blocks along with other ASIC
                                                                    specific configurations. This register
                                                                    is initially loaded from FLASH at power-up.
                                                                    The register will be modified during factory
                                                                    testing to determine the final trim settings
                                                                    to store in the FLASH.                                     */
  __IM  uint32_t   RESERVED3[3];
  __IM  uint32_t   REV_ID;                      /*!< (@ 0x00000050) Revision ID register is used to read the Nebo
                                                                    revision number. Bits 31:4 are the same
                                                                    as the ECO revision code of the ARM Cortex
                                                                    M0+.                                                       */
  __IM  uint32_t   RESERVED4[3];

  union {
    __IOM uint32_t LOCK;                        /*!< (@ 0x00000060) Lock Debug Port register is used to disable the
                                                                    Serial Wire Debug Port to prevent access
                                                                    to the internal buses and memory for security
                                                                    sensitive applications.                                    */

    struct {
      __IOM uint32_t STS         : 1;           /*!< (@ 0x00000000) Status of Debug Port lock. 1 = locked. 0 = unlocked.       */
      __IM  uint32_t OVER        : 1;           /*!< (@ 0x00000001) Debug Port Lock Override detected at power-up.             */
    } LOCK_b;
  } ;
} MISC_Type;                                    /*!< Size = 100 (0x64)                                                         */



/* =========================================================================================================================== */
/* ================                                            MTB                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Micro Trace Buffer is available.  See CoreSight MTB-M0+ Technical Reference Manual for full details.  When enabled, the MTB records changes in program flow, reported by the Cortex-M0+ processor over the execution trace interface.  This information is stored as trace packets in the SRAM.  An off-chip debugger can extract the trace information using the DAP to read the trace information from the SRAM.  The debugger can then reconstruct the program flow from this information. (MTB)
  */

typedef struct {                                /*!< (@ 0x30000000) MTB Structure                                              */

  union {
    __IOM uint32_t POSITION;                    /*!< (@ 0x00000000) The MTB Position Register contains the trace
                                                                    write pointer and the wrap bit.                            */

    struct {
      __IM  uint32_t             : 2;
      __IOM uint32_t WRAP        : 1;           /*!< (@ 0x00000002) This bit is set to 1 automatically when the POINTER
                                                                    value wraps as determined by the MASTER.MASK
                                                                    field in the MASTER Trace Control Register                 */
      __IOM uint32_t POINTER     : 29;          /*!< (@ 0x00000003) Trace packet location pointer.                             */
    } POSITION_b;
  } ;

  union {
    __IOM uint32_t MASTER;                      /*!< (@ 0x00000004) The MTB Master Register contains the main trace
                                                                    enable bit along with other trace control
                                                                    fields.                                                    */

    struct {
      __IOM uint32_t MASK        : 5;           /*!< (@ 0x00000000) This value determines the maximum size of the
                                                                    trace buffer in SRAM                                       */
      __IOM uint32_t TSTARTEN    : 1;           /*!< (@ 0x00000005) Trace start input enable                                   */
      __IOM uint32_t TSTOPEN     : 1;           /*!< (@ 0x00000006) Trace stop input enable                                    */
      __IM  uint32_t             : 2;
      __IOM uint32_t HALTREQ     : 1;           /*!< (@ 0x00000009) Halt request bit                                           */
      __IM  uint32_t             : 21;
      __IOM uint32_t EN          : 1;           /*!< (@ 0x0000001F) Main trace enable bit                                      */
    } MASTER_b;
  } ;

  union {
    __IOM uint32_t FLOW;                        /*!< (@ 0x00000008) The MTB FLOW register.                                     */

    struct {
      __IOM uint32_t AUTOSTOP    : 1;           /*!< (@ 0x00000000) If this bit is 1 and WATERMARK is equal to POSITION.POINTER,
                                                                    then the MASTER.EN bit is automatically
                                                                    set to 0. This stops tracing.                              */
      __IOM uint32_t AUTOHALT    : 1;           /*!< (@ 0x00000001) If this bit is 1 and WATERMARK is equal to POSITION.POINTER,
                                                                    then the MASTER.HALTREQ bit is automatically
                                                                    set to 1.                                                  */
      __IM  uint32_t             : 1;
      __IOM uint32_t WATERMARK   : 29;          /*!< (@ 0x00000003) When the POSITION.POINTER matches the WATERMARK
                                                                    field value, actions defined by the AUTOHALT
                                                                    and AUTOSTOP bits are performed.                           */
    } FLOW_b;
  } ;
  __IM  uint32_t   BASE;                        /*!< (@ 0x0000000C) The MTB Base Register indicates where the SRAM
                                                                    is located in the processor memory map.
                                                                    This register is provided to enable auto
                                                                    discovery of the MTB SRAM location, by
                                                                    a debug agent.                                             */
} MTB_Type;                                     /*!< Size = 16 (0x10)                                                          */


/** @} */ /* End of group Device_Peripheral_peripherals */


/* =========================================  End of section using anonymous unions  ========================================= */
#if defined (__CC_ARM)
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


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define CMP_BASE                    0x40600000UL
#define ADC_BASE                    0x40700000UL
#define CMU_BASE                    0x40300000UL
#define CC_PWM_BASE                 0x41400000UL
#define CC_PWM1_BASE                0x41500000UL
#define CC_PWM2_BASE                0x41600000UL
#define CC_PWM3_BASE                0x41700000UL
#define XBAR_BASE                   0x40500000UL
#define CRC_BASE                    0x40D00000UL
#define DMA_BASE                    0x40800000UL
#define FLASH_BASE                  0x40C00000UL
#define GPIO_BASE                   0x40000000UL
#define I2C_BASE                    0x41D00000UL
#define PMU_BASE                    0x40400000UL
#define SPI0_BASE                   0x41900000UL
#define SPI1_BASE                   0x41A00000UL
#define TICKER_BASE                 0x41000000UL
#define TIM_BASE                    0x41100000UL
#define TIM1_BASE                   0x41200000UL
#define TIM2_BASE                   0x41300000UL
#define TRNG_BASE                   0x40A00000UL
#define AES_BASE                    0x40900000UL
#define UART_BASE                   0x41B00000UL
#define UART1_BASE                  0x41C00000UL
#define WUT_BASE                    0x40100000UL
#define WDOG_BASE                   0x40F00000UL
#define MISC_BASE                   0x41F00000UL
#define MTB_BASE                    0x30000000UL

#define AND_OFFSET                  0x04000000UL
#define OR_OFFSET                   0x08000000UL
#define XOR_OFFSET                  0x0C000000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define CMP                         ((CMP_Type*)               CMP_BASE)
#define ADC                         ((ADC_Type*)               ADC_BASE)
#define CMU                         ((CMU_Type*)               CMU_BASE)
#define CC_PWM                      ((CC_PWM_Type*)            CC_PWM_BASE)
#define CC_PWM1                     ((CC_PWM_Type*)            CC_PWM1_BASE)
#define CC_PWM2                     ((CC_PWM_Type*)            CC_PWM2_BASE)
#define CC_PWM3                     ((CC_PWM_Type*)            CC_PWM3_BASE)
#define XBAR                        ((XBAR_Type*)              XBAR_BASE)
#define CRC                         ((CRC_Type*)               CRC_BASE)
#define DMA                         ((DMA_Type*)               DMA_BASE)
#define FLASH                       ((FLASH_Type*)             FLASH_BASE)
#define GPIO                        ((GPIO_Type*)              GPIO_BASE)
#define I2C                         ((I2C_Type*)               I2C_BASE)
#define PMU                         ((PMU_Type*)               PMU_BASE)
#define SPI0                        ((SPI0_Type*)              SPI0_BASE)
#define SPI1                        ((SPI1_Type*)              SPI1_BASE)
#define TICKER                      ((TICKER_Type*)            TICKER_BASE)
#define TIM                         ((TIM_Type*)               TIM_BASE)
#define TIM1                        ((TIM_Type*)               TIM1_BASE)
#define TIM2                        ((TIM_Type*)               TIM2_BASE)
#define TRNG                        ((TRNG_Type*)              TRNG_BASE)
#define AES                         ((AES_Type*)               AES_BASE)
#define UART0                       ((UART_Type*)              UART_BASE)
#define UART1                       ((UART_Type*)              UART1_BASE)
#define WUT                         ((WUT_Type*)               WUT_BASE)
#define WDOG                        ((WDOG_Type*)              WDOG_BASE)
#define MISC                        ((MISC_Type*)              MISC_BASE)
#define MTB                         ((MTB_Type*)               MTB_BASE)

#define CMP_AND                     ((CMP_Type*)               (CMP_BASE + AND_OFFSET))
#define ADC_AND                     ((ADC_Type*)               (ADC_BASE + AND_OFFSET))
#define CMU_AND                     ((CMU_Type*)               (CMU_BASE + AND_OFFSET))
#define CC_PWM_AND                  ((CC_PWM_Type*)            (CC_PWM_BASE + AND_OFFSET))
#define CC_PWM1_AND                 ((CC_PWM_Type*)            (CC_PWM1_BASE + AND_OFFSET))
#define CC_PWM2_AND                 ((CC_PWM_Type*)            (CC_PWM2_BASE + AND_OFFSET))
#define CC_PWM3_AND                 ((CC_PWM_Type*)            (CC_PWM3_BASE + AND_OFFSET))
#define XBAR_AND                    ((XBAR_Type*)              (XBAR_BASE + AND_OFFSET))
#define CRC_AND                     ((CRC_Type*)               (CRC_BASE + AND_OFFSET))
#define DMA_AND                     ((DMA_Type*)               (DMA_BASE + AND_OFFSET))
#define FLASH_AND                   ((FLASH_Type*)             (FLASH_BASE + AND_OFFSET))
#define GPIO_AND                    ((GPIO_Type*)              (GPIO_BASE + AND_OFFSET))
#define I2C_AND                     ((I2C_Type*)               (I2C_BASE + AND_OFFSET))
#define PMU_AND                     ((PMU_Type*)               (PMU_BASE + AND_OFFSET))
#define SPI0_AND                    ((SPI0_Type*)              (SPI0_BASE + AND_OFFSET))
#define SPI1_AND                    ((SPI1_Type*)              (SPI1_BASE + AND_OFFSET))
#define TICKER_AND                  ((TICKER_Type*)            (TICKER_BASE + AND_OFFSET))
#define TIM_AND                     ((TIM_Type*)               (TIM_BASE + AND_OFFSET))
#define TIM1_AND                    ((TIM_Type*)               (TIM1_BASE + AND_OFFSET))
#define TIM2_AND                    ((TIM_Type*)               (TIM2_BASE + AND_OFFSET))
#define TRNG_AND                    ((TRNG_Type*)              (TRNG_BASE + AND_OFFSET))
#define AES_AND                     ((AES_Type*)               (AES_BASE + AND_OFFSET))
#define UART_AND                    ((UART_Type*)              (UART_BASE + AND_OFFSET))
#define UART1_AND                   ((UART_Type*)              (UART1_BASE + AND_OFFSET))
#define WUT_AND                     ((WUT_Type*)               (WUT_BASE + AND_OFFSET))
#define WDOG_AND                    ((WDOG_Type*)              (WDOG_BASE + AND_OFFSET))
#define MISC_AND                    ((MISC_Type*)              (MISC_BASE + AND_OFFSET))

#define CMP_OR                      ((CMP_Type*)               (CMP_BASE + OR_OFFSET))
#define ADC_OR                      ((ADC_Type*)               (ADC_BASE + OR_OFFSET))
#define CMU_OR                      ((CMU_Type*)               (CMU_BASE + OR_OFFSET))
#define CC_PWM_OR                   ((CC_PWM_Type*)            (CC_PWM_BASE + OR_OFFSET))
#define CC_PWM1_OR                  ((CC_PWM_Type*)            (CC_PWM1_BASE + OR_OFFSET))
#define CC_PWM2_OR                  ((CC_PWM_Type*)            (CC_PWM2_BASE + OR_OFFSET))
#define CC_PWM3_OR                  ((CC_PWM_Type*)            (CC_PWM3_BASE + OR_OFFSET))
#define XBAR_OR                     ((XBAR_Type*)              (XBAR_BASE + OR_OFFSET))
#define CRC_OR                      ((CRC_Type*)               (CRC_BASE + OR_OFFSET))
#define DMA_OR                      ((DMA_Type*)               (DMA_BASE + OR_OFFSET))
#define FLASH_OR                    ((FLASH_Type*)             (FLASH_BASE + OR_OFFSET))
#define GPIO_OR                     ((GPIO_Type*)              (GPIO_BASE + OR_OFFSET))
#define I2C_OR                      ((I2C_Type*)               (I2C_BASE + OR_OFFSET))
#define PMU_OR                      ((PMU_Type*)               (PMU_BASE + OR_OFFSET))
#define SPI0_OR                     ((SPI0_Type*)              (SPI0_BASE + OR_OFFSET))
#define SPI1_OR                     ((SPI1_Type*)              (SPI1_BASE + OR_OFFSET))
#define TICKER_OR                   ((TICKER_Type*)            (TICKER_BASE + OR_OFFSET))
#define TIM_OR                      ((TIM_Type*)               (TIM_BASE + OR_OFFSET))
#define TIM1_OR                     ((TIM_Type*)               (TIM1_BASE + OR_OFFSET))
#define TIM2_OR                     ((TIM_Type*)               (TIM2_BASE + OR_OFFSET))
#define TRNG_OR                     ((TRNG_Type*)              (TRNG_BASE + OR_OFFSET))
#define AES_OR                      ((AES_Type*)               (AES_BASE + OR_OFFSET))
#define UART_OR                     ((UART_Type*)              (UART_BASE + OR_OFFSET))
#define UART1_OR                    ((UART_Type*)              (UART1_BASE + OR_OFFSET))
#define WUT_OR                      ((WUT_Type*)               (WUT_BASE + OR_OFFSET))
#define WDOG_OR                     ((WDOG_Type*)              (WDOG_BASE + OR_OFFSET))
#define MISC_OR                     ((MISC_Type*)              (MISC_BASE + OR_OFFSET))

#define CMP_XOR                     ((CMP_Type*)               (CMP_BASE + XOR_OFFSET))
#define ADC_XOR                     ((ADC_Type*)               (ADC_BASE + XOR_OFFSET))
#define CMU_XOR                     ((CMU_Type*)               (CMU_BASE + XOR_OFFSET))
#define CC_PWM_XOR                  ((CC_PWM_Type*)            (CC_PWM_BASE + XOR_OFFSET))
#define CC_PWM1_XOR                 ((CC_PWM_Type*)            (CC_PWM1_BASE + XOR_OFFSET))
#define CC_PWM2_XOR                 ((CC_PWM_Type*)            (CC_PWM2_BASE + XOR_OFFSET))
#define CC_PWM3_XOR                 ((CC_PWM_Type*)            (CC_PWM3_BASE + XOR_OFFSET))
#define XBAR_XOR                    ((XBAR_Type*)              (XBAR_BASE + XOR_OFFSET))
#define CRC_XOR                     ((CRC_Type*)               (CRC_BASE + XOR_OFFSET))
#define DMA_XOR                     ((DMA_Type*)               (DMA_BASE + XOR_OFFSET))
#define FLASH_XOR                   ((FLASH_Type*)             (FLASH_BASE + XOR_OFFSET))
#define GPIO_XOR                    ((GPIO_Type*)              (GPIO_BASE + XOR_OFFSET))
#define I2C_XOR                     ((I2C_Type*)               (I2C_BASE + XOR_OFFSET))
#define PMU_XOR                     ((PMU_Type*)               (PMU_BASE + XOR_OFFSET))
#define SPI0_XOR                    ((SPI0_Type*)              (SPI0_BASE + XOR_OFFSET))
#define SPI1_XOR                    ((SPI1_Type*)              (SPI1_BASE + XOR_OFFSET))
#define TICKER_XOR                  ((TICKER_Type*)            (TICKER_BASE + XOR_OFFSET))
#define TIM_XOR                     ((TIM_Type*)               (TIM_BASE + XOR_OFFSET))
#define TIM1_XOR                    ((TIM_Type*)               (TIM1_BASE + XOR_OFFSET))
#define TIM2_XOR                    ((TIM_Type*)               (TIM2_BASE + XOR_OFFSET))
#define TRNG_XOR                    ((TRNG_Type*)              (TRNG_BASE + XOR_OFFSET))
#define AES_XOR                     ((AES_Type*)               (AES_BASE + XOR_OFFSET))
#define UART_XOR                    ((UART_Type*)              (UART_BASE + XOR_OFFSET))
#define UART1_XOR                   ((UART_Type*)              (UART1_BASE + XOR_OFFSET))
#define WUT_XOR                     ((WUT_Type*)               (WUT_BASE + XOR_OFFSET))
#define WDOG_XOR                    ((WDOG_Type*)              (WDOG_BASE + XOR_OFFSET))
#define MISC_XOR                    ((MISC_Type*)              (MISC_BASE + XOR_OFFSET))

/** @} */ /* End of group Device_Peripheral_declaration */


/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */


/** @addtogroup PosMask_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                            CMP                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  OUT  ========================================================== */
#define CMP_OUT_CMP1_Pos                  (1UL)                     /*!< CMP OUT: CMP1 (Bit 1)                                 */
#define CMP_OUT_CMP1_Msk                  (0x2UL)                   /*!< CMP OUT: CMP1 (Bitfield-Mask: 0x01)                   */
#define CMP_OUT_CMP0_Pos                  (0UL)                     /*!< CMP OUT: CMP0 (Bit 0)                                 */
#define CMP_OUT_CMP0_Msk                  (0x1UL)                   /*!< CMP OUT: CMP0 (Bitfield-Mask: 0x01)                   */
/* ==========================================================  CTL  ========================================================== */
#define CMP_CTL_CMP1_PLUS_Pos             (12UL)                    /*!< CMP CTL: CMP1_PLUS (Bit 12)                           */
#define CMP_CTL_CMP1_PLUS_Msk             (0x7000UL)                /*!< CMP CTL: CMP1_PLUS (Bitfield-Mask: 0x07)              */
#define CMP_CTL_CMP1_MINUS_Pos            (9UL)                     /*!< CMP CTL: CMP1_MINUS (Bit 9)                           */
#define CMP_CTL_CMP1_MINUS_Msk            (0xe00UL)                 /*!< CMP CTL: CMP1_MINUS (Bitfield-Mask: 0x07)             */
#define CMP_CTL_CMP1_EN_Pos               (8UL)                     /*!< CMP CTL: CMP1_EN (Bit 8)                              */
#define CMP_CTL_CMP1_EN_Msk               (0x100UL)                 /*!< CMP CTL: CMP1_EN (Bitfield-Mask: 0x01)                */
#define CMP_CTL_CMP0_PLUS_Pos             (4UL)                     /*!< CMP CTL: CMP0_PLUS (Bit 4)                            */
#define CMP_CTL_CMP0_PLUS_Msk             (0x70UL)                  /*!< CMP CTL: CMP0_PLUS (Bitfield-Mask: 0x07)              */
#define CMP_CTL_CMP0_MINUS_Pos            (1UL)                     /*!< CMP CTL: CMP0_MINUS (Bit 1)                           */
#define CMP_CTL_CMP0_MINUS_Msk            (0xeUL)                   /*!< CMP CTL: CMP0_MINUS (Bitfield-Mask: 0x07)             */
#define CMP_CTL_CMP0_EN_Pos               (0UL)                     /*!< CMP CTL: CMP0_EN (Bit 0)                              */
#define CMP_CTL_CMP0_EN_Msk               (0x1UL)                   /*!< CMP CTL: CMP0_EN (Bitfield-Mask: 0x01)                */
/* ========================================================  INT_EN  ========================================================= */
#define CMP_INT_EN_COMP1_FALL_Pos         (3UL)                     /*!< CMP INT_EN: COMP1_FALL (Bit 3)                        */
#define CMP_INT_EN_COMP1_FALL_Msk         (0x8UL)                   /*!< CMP INT_EN: COMP1_FALL (Bitfield-Mask: 0x01)          */
#define CMP_INT_EN_COMP1_RISE_Pos         (2UL)                     /*!< CMP INT_EN: COMP1_RISE (Bit 2)                        */
#define CMP_INT_EN_COMP1_RISE_Msk         (0x4UL)                   /*!< CMP INT_EN: COMP1_RISE (Bitfield-Mask: 0x01)          */
#define CMP_INT_EN_COMP0_FALL_Pos         (1UL)                     /*!< CMP INT_EN: COMP0_FALL (Bit 1)                        */
#define CMP_INT_EN_COMP0_FALL_Msk         (0x2UL)                   /*!< CMP INT_EN: COMP0_FALL (Bitfield-Mask: 0x01)          */
#define CMP_INT_EN_COMP0_RISE_Pos         (0UL)                     /*!< CMP INT_EN: COMP0_RISE (Bit 0)                        */
#define CMP_INT_EN_COMP0_RISE_Msk         (0x1UL)                   /*!< CMP INT_EN: COMP0_RISE (Bitfield-Mask: 0x01)          */
/* ========================================================  INT_STS  ======================================================== */
#define CMP_INT_STS_COMP1_FALL_Pos        (3UL)                     /*!< CMP INT_STS: COMP1_FALL (Bit 3)                       */
#define CMP_INT_STS_COMP1_FALL_Msk        (0x8UL)                   /*!< CMP INT_STS: COMP1_FALL (Bitfield-Mask: 0x01)         */
#define CMP_INT_STS_COMP1_RISE_Pos        (2UL)                     /*!< CMP INT_STS: COMP1_RISE (Bit 2)                       */
#define CMP_INT_STS_COMP1_RISE_Msk        (0x4UL)                   /*!< CMP INT_STS: COMP1_RISE (Bitfield-Mask: 0x01)         */
#define CMP_INT_STS_COMP0_FALL_Pos        (1UL)                     /*!< CMP INT_STS: COMP0_FALL (Bit 1)                       */
#define CMP_INT_STS_COMP0_FALL_Msk        (0x2UL)                   /*!< CMP INT_STS: COMP0_FALL (Bitfield-Mask: 0x01)         */
#define CMP_INT_STS_COMP0_RISE_Pos        (0UL)                     /*!< CMP INT_STS: COMP0_RISE (Bit 0)                       */
#define CMP_INT_STS_COMP0_RISE_Msk        (0x1UL)                   /*!< CMP INT_STS: COMP0_RISE (Bitfield-Mask: 0x01)         */


/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
#define ADC_CFG_REG_SEL_Pos               (24UL)                    /*!< ADC CFG: REG_SEL (Bit 24)                             */
#define ADC_CFG_REG_SEL_Msk               (0x1000000UL)             /*!< ADC CFG: REG_SEL (Bitfield-Mask: 0x01)                */
#define ADC_CFG_REF_SEL_Pos               (22UL)                    /*!< ADC CFG: REF_SEL (Bit 22)                             */
#define ADC_CFG_REF_SEL_Msk               (0xc00000UL)              /*!< ADC CFG: REF_SEL (Bitfield-Mask: 0x03)                */
#define ADC_CFG_HV_MOD_Pos                (21UL)                    /*!< ADC CFG: HV_MOD (Bit 21)                              */
#define ADC_CFG_HV_MOD_Msk                (0x200000UL)              /*!< ADC CFG: HV_MOD (Bitfield-Mask: 0x01)                 */
#define ADC_CFG_GAIN_Pos                  (19UL)                    /*!< ADC CFG: GAIN (Bit 19)                                */
#define ADC_CFG_GAIN_Msk                  (0x180000UL)              /*!< ADC CFG: GAIN (Bitfield-Mask: 0x03)                   */
#define ADC_CFG_SAMP_PER_Pos              (16UL)                    /*!< ADC CFG: SAMP_PER (Bit 16)                            */
#define ADC_CFG_SAMP_PER_Msk              (0x70000UL)               /*!< ADC CFG: SAMP_PER (Bitfield-Mask: 0x07)               */
#define ADC_CFG_CH_CORE_VOLT_EN_Pos       (15UL)                    /*!< ADC CFG: CH_CORE_VOLT_EN (Bit 15)                     */
#define ADC_CFG_CH_CORE_VOLT_EN_Msk       (0x8000UL)                /*!< ADC CFG: CH_CORE_VOLT_EN (Bitfield-Mask: 0x01)        */
#define ADC_CFG_CH_CHIP_VOLT_EN_Pos       (14UL)                    /*!< ADC CFG: CH_CHIP_VOLT_EN (Bit 14)                     */
#define ADC_CFG_CH_CHIP_VOLT_EN_Msk       (0x4000UL)                /*!< ADC CFG: CH_CHIP_VOLT_EN (Bitfield-Mask: 0x01)        */
#define ADC_CFG_CH_CMP_IN_EN_Pos          (13UL)                    /*!< ADC CFG: CH_CMP_IN_EN (Bit 13)                        */
#define ADC_CFG_CH_CMP_IN_EN_Msk          (0x2000UL)                /*!< ADC CFG: CH_CMP_IN_EN (Bitfield-Mask: 0x01)           */
#define ADC_CFG_CH_TEMP_EN_Pos            (12UL)                    /*!< ADC CFG: CH_TEMP_EN (Bit 12)                          */
#define ADC_CFG_CH_TEMP_EN_Msk            (0x1000UL)                /*!< ADC CFG: CH_TEMP_EN (Bitfield-Mask: 0x01)             */
#define ADC_CFG_CH_DIFF_6_7_EN_Pos        (11UL)                    /*!< ADC CFG: CH_DIFF_6_7_EN (Bit 11)                      */
#define ADC_CFG_CH_DIFF_6_7_EN_Msk        (0x800UL)                 /*!< ADC CFG: CH_DIFF_6_7_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_DIFF_4_5_EN_Pos        (10UL)                    /*!< ADC CFG: CH_DIFF_4_5_EN (Bit 10)                      */
#define ADC_CFG_CH_DIFF_4_5_EN_Msk        (0x400UL)                 /*!< ADC CFG: CH_DIFF_4_5_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_DIFF_2_3_EN_Pos        (9UL)                     /*!< ADC CFG: CH_DIFF_2_3_EN (Bit 9)                       */
#define ADC_CFG_CH_DIFF_2_3_EN_Msk        (0x200UL)                 /*!< ADC CFG: CH_DIFF_2_3_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_DIFF_0_1_EN_Pos        (8UL)                     /*!< ADC CFG: CH_DIFF_0_1_EN (Bit 8)                       */
#define ADC_CFG_CH_DIFF_0_1_EN_Msk        (0x100UL)                 /*!< ADC CFG: CH_DIFF_0_1_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_7_EN_Pos        (7UL)                     /*!< ADC CFG: CH_SINGLE_7_EN (Bit 7)                       */
#define ADC_CFG_CH_SINGLE_7_EN_Msk        (0x80UL)                  /*!< ADC CFG: CH_SINGLE_7_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_6_EN_Pos        (6UL)                     /*!< ADC CFG: CH_SINGLE_6_EN (Bit 6)                       */
#define ADC_CFG_CH_SINGLE_6_EN_Msk        (0x40UL)                  /*!< ADC CFG: CH_SINGLE_6_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_5_EN_Pos        (5UL)                     /*!< ADC CFG: CH_SINGLE_5_EN (Bit 5)                       */
#define ADC_CFG_CH_SINGLE_5_EN_Msk        (0x20UL)                  /*!< ADC CFG: CH_SINGLE_5_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_4_EN_Pos        (4UL)                     /*!< ADC CFG: CH_SINGLE_4_EN (Bit 4)                       */
#define ADC_CFG_CH_SINGLE_4_EN_Msk        (0x10UL)                  /*!< ADC CFG: CH_SINGLE_4_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_3_EN_Pos        (3UL)                     /*!< ADC CFG: CH_SINGLE_3_EN (Bit 3)                       */
#define ADC_CFG_CH_SINGLE_3_EN_Msk        (0x8UL)                   /*!< ADC CFG: CH_SINGLE_3_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_2_EN_Pos        (2UL)                     /*!< ADC CFG: CH_SINGLE_2_EN (Bit 2)                       */
#define ADC_CFG_CH_SINGLE_2_EN_Msk        (0x4UL)                   /*!< ADC CFG: CH_SINGLE_2_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_1_EN_Pos        (1UL)                     /*!< ADC CFG: CH_SINGLE_1_EN (Bit 1)                       */
#define ADC_CFG_CH_SINGLE_1_EN_Msk        (0x2UL)                   /*!< ADC CFG: CH_SINGLE_1_EN (Bitfield-Mask: 0x01)         */
#define ADC_CFG_CH_SINGLE_0_EN_Pos        (0UL)                     /*!< ADC CFG: CH_SINGLE_0_EN (Bit 0)                       */
#define ADC_CFG_CH_SINGLE_0_EN_Msk        (0x1UL)                   /*!< ADC CFG: CH_SINGLE_0_EN (Bitfield-Mask: 0x01)         */
/* ==========================================================  CTL  ========================================================== */
#define ADC_CTL_CNT_LIMIT_Pos             (8UL)                     /*!< ADC CTL: CNT_LIMIT (Bit 8)                            */
#define ADC_CTL_CNT_LIMIT_Msk             (0x7ff00UL)               /*!< ADC CTL: CNT_LIMIT (Bitfield-Mask: 0x7ff)             */
#define ADC_CTL_SEQ_RST_Pos               (6UL)                     /*!< ADC CTL: SEQ_RST (Bit 6)                              */
#define ADC_CTL_SEQ_RST_Msk               (0x40UL)                  /*!< ADC CTL: SEQ_RST (Bitfield-Mask: 0x01)                */
#define ADC_CTL_EDGE_TRIG_Pos             (4UL)                     /*!< ADC CTL: EDGE_TRIG (Bit 4)                            */
#define ADC_CTL_EDGE_TRIG_Msk             (0x30UL)                  /*!< ADC CTL: EDGE_TRIG (Bitfield-Mask: 0x03)              */
#define ADC_CTL_HW_TRIG_Pos               (3UL)                     /*!< ADC CTL: HW_TRIG (Bit 3)                              */
#define ADC_CTL_HW_TRIG_Msk               (0x8UL)                   /*!< ADC CTL: HW_TRIG (Bitfield-Mask: 0x01)                */
#define ADC_CTL_OVER_EN_Pos               (2UL)                     /*!< ADC CTL: OVER_EN (Bit 2)                              */
#define ADC_CTL_OVER_EN_Msk               (0x4UL)                   /*!< ADC CTL: OVER_EN (Bitfield-Mask: 0x01)                */
#define ADC_CTL_CONT_EN_Pos               (1UL)                     /*!< ADC CTL: CONT_EN (Bit 1)                              */
#define ADC_CTL_CONT_EN_Msk               (0x2UL)                   /*!< ADC CTL: CONT_EN (Bitfield-Mask: 0x01)                */
#define ADC_CTL_CNT_EN_Pos                (0UL)                     /*!< ADC CTL: CNT_EN (Bit 0)                               */
#define ADC_CTL_CNT_EN_Msk                (0x1UL)                   /*!< ADC CTL: CNT_EN (Bitfield-Mask: 0x01)                 */
/* ==========================================================  CAL  ========================================================== */
/* ========================================================  INT_EN  ========================================================= */
#define ADC_INT_EN_OVER_Pos               (1UL)                     /*!< ADC INT_EN: OVER (Bit 1)                              */
#define ADC_INT_EN_OVER_Msk               (0x2UL)                   /*!< ADC INT_EN: OVER (Bitfield-Mask: 0x01)                */
#define ADC_INT_EN_DATA_Pos               (0UL)                     /*!< ADC INT_EN: DATA (Bit 0)                              */
#define ADC_INT_EN_DATA_Msk               (0x1UL)                   /*!< ADC INT_EN: DATA (Bitfield-Mask: 0x01)                */
/* ========================================================  INT_STS  ======================================================== */
#define ADC_INT_STS_OVER_Pos              (1UL)                     /*!< ADC INT_STS: OVER (Bit 1)                             */
#define ADC_INT_STS_OVER_Msk              (0x2UL)                   /*!< ADC INT_STS: OVER (Bitfield-Mask: 0x01)               */
#define ADC_INT_STS_DATA_Pos              (0UL)                     /*!< ADC INT_STS: DATA (Bit 0)                             */
#define ADC_INT_STS_DATA_Msk              (0x1UL)                   /*!< ADC INT_STS: DATA (Bitfield-Mask: 0x01)               */
/* =======================================================  TEST_MOD  ======================================================== */
/* ========================================================  CH_STS  ========================================================= */
/* ==========================================================  STS  ========================================================== */
#define ADC_STS_STATE_Pos                 (15UL)                    /*!< ADC STS: STATE (Bit 15)                               */
#define ADC_STS_STATE_Msk                 (0x8000UL)                /*!< ADC STS: STATE (Bitfield-Mask: 0x01)                  */
#define ADC_STS_CNT_Pos                   (0UL)                     /*!< ADC STS: CNT (Bit 0)                                  */
#define ADC_STS_CNT_Msk                   (0x7ffUL)                 /*!< ADC STS: CNT (Bitfield-Mask: 0x7ff)                   */


/* =========================================================================================================================== */
/* ================                                            CMU                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
#define CMU_CFG_CLK_LOSS_INT_EN_Pos       (20UL)                    /*!< CMU CFG: CLK_LOSS_INT_EN (Bit 20)                     */
#define CMU_CFG_CLK_LOSS_INT_EN_Msk       (0x100000UL)              /*!< CMU CFG: CLK_LOSS_INT_EN (Bitfield-Mask: 0x01)        */
#define CMU_CFG_LP_OSC_CAL_INT_EN_Pos     (19UL)                    /*!< CMU CFG: LP_OSC_CAL_INT_EN (Bit 19)                   */
#define CMU_CFG_LP_OSC_CAL_INT_EN_Msk     (0x80000UL)               /*!< CMU CFG: LP_OSC_CAL_INT_EN (Bitfield-Mask: 0x01)      */
#define CMU_CFG_HS_OSC_CAL_INT_EN_Pos     (18UL)                    /*!< CMU CFG: HS_OSC_CAL_INT_EN (Bit 18)                   */
#define CMU_CFG_HS_OSC_CAL_INT_EN_Msk     (0x40000UL)               /*!< CMU CFG: HS_OSC_CAL_INT_EN (Bitfield-Mask: 0x01)      */
#define CMU_CFG_SYSTICK_CLK_SEL_Pos       (16UL)                    /*!< CMU CFG: SYSTICK_CLK_SEL (Bit 16)                     */
#define CMU_CFG_SYSTICK_CLK_SEL_Msk       (0x30000UL)               /*!< CMU CFG: SYSTICK_CLK_SEL (Bitfield-Mask: 0x03)        */
#define CMU_CFG_WDOG_CLK_SEL_Pos          (14UL)                    /*!< CMU CFG: WDOG_CLK_SEL (Bit 14)                        */
#define CMU_CFG_WDOG_CLK_SEL_Msk          (0xc000UL)                /*!< CMU CFG: WDOG_CLK_SEL (Bitfield-Mask: 0x03)           */
#define CMU_CFG_LP_XOSC_PD_Pos            (13UL)                    /*!< CMU CFG: LP_XOSC_PD (Bit 13)                          */
#define CMU_CFG_LP_XOSC_PD_Msk            (0x2000UL)                /*!< CMU CFG: LP_XOSC_PD (Bitfield-Mask: 0x01)             */
#define CMU_CFG_HS_XOSC_PD_Pos            (12UL)                    /*!< CMU CFG: HS_XOSC_PD (Bit 12)                          */
#define CMU_CFG_HS_XOSC_PD_Msk            (0x1000UL)                /*!< CMU CFG: HS_XOSC_PD (Bitfield-Mask: 0x01)             */
#define CMU_CFG_LP_OSC_PD_Pos             (11UL)                    /*!< CMU CFG: LP_OSC_PD (Bit 11)                           */
#define CMU_CFG_LP_OSC_PD_Msk             (0x800UL)                 /*!< CMU CFG: LP_OSC_PD (Bitfield-Mask: 0x01)              */
#define CMU_CFG_HS_OSC_PD_Pos             (10UL)                    /*!< CMU CFG: HS_OSC_PD (Bit 10)                           */
#define CMU_CFG_HS_OSC_PD_Msk             (0x400UL)                 /*!< CMU CFG: HS_OSC_PD (Bitfield-Mask: 0x01)              */
#define CMU_CFG_SYS_CLK_MON_PER_Pos       (6UL)                     /*!< CMU CFG: SYS_CLK_MON_PER (Bit 6)                      */
#define CMU_CFG_SYS_CLK_MON_PER_Msk       (0xc0UL)                  /*!< CMU CFG: SYS_CLK_MON_PER (Bitfield-Mask: 0x03)        */
#define CMU_CFG_SYS_CLK_DIV_Pos           (3UL)                     /*!< CMU CFG: SYS_CLK_DIV (Bit 3)                          */
#define CMU_CFG_SYS_CLK_DIV_Msk           (0x38UL)                  /*!< CMU CFG: SYS_CLK_DIV (Bitfield-Mask: 0x07)            */
#define CMU_CFG_SYS_CLK_SEL_Pos           (0UL)                     /*!< CMU CFG: SYS_CLK_SEL (Bit 0)                          */
#define CMU_CFG_SYS_CLK_SEL_Msk           (0x7UL)                   /*!< CMU CFG: SYS_CLK_SEL (Bitfield-Mask: 0x07)            */
/* ==========================================================  STS  ========================================================== */
#define CMU_STS_CLK_LOSS_Pos              (3UL)                     /*!< CMU STS: CLK_LOSS (Bit 3)                             */
#define CMU_STS_CLK_LOSS_Msk              (0x8UL)                   /*!< CMU STS: CLK_LOSS (Bitfield-Mask: 0x01)               */
#define CMU_STS_CLK_SEL_Pos               (0UL)                     /*!< CMU STS: CLK_SEL (Bit 0)                              */
#define CMU_STS_CLK_SEL_Msk               (0x7UL)                   /*!< CMU STS: CLK_SEL (Bitfield-Mask: 0x07)                */
/* ======================================================  ADC_CLK_CFG  ====================================================== */
#define CMU_ADC_CLK_CFG_SEL_Pos           (4UL)                     /*!< CMU ADC_CLK_CFG: SEL (Bit 4)                          */
#define CMU_ADC_CLK_CFG_SEL_Msk           (0x70UL)                  /*!< CMU ADC_CLK_CFG: SEL (Bitfield-Mask: 0x07)            */
#define CMU_ADC_CLK_CFG_DIV_Pos           (0UL)                     /*!< CMU ADC_CLK_CFG: DIV (Bit 0)                          */
#define CMU_ADC_CLK_CFG_DIV_Msk           (0x7UL)                   /*!< CMU ADC_CLK_CFG: DIV (Bitfield-Mask: 0x07)            */
/* ======================================================  EXT_CLK_DIV  ====================================================== */
/* =======================================================  PCLK_CFG  ======================================================== */
#define CMU_PCLK_CFG_TEST_EN_Pos          (31UL)                    /*!< CMU PCLK_CFG: TEST_EN (Bit 31)                        */
#define CMU_PCLK_CFG_TEST_EN_Msk          (0x80000000UL)            /*!< CMU PCLK_CFG: TEST_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_I2C_EN_Pos           (29UL)                    /*!< CMU PCLK_CFG: I2C_EN (Bit 29)                         */
#define CMU_PCLK_CFG_I2C_EN_Msk           (0x20000000UL)            /*!< CMU PCLK_CFG: I2C_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_UART1_EN_Pos         (28UL)                    /*!< CMU PCLK_CFG: UART1_EN (Bit 28)                       */
#define CMU_PCLK_CFG_UART1_EN_Msk         (0x10000000UL)            /*!< CMU PCLK_CFG: UART1_EN (Bitfield-Mask: 0x01)          */
#define CMU_PCLK_CFG_UART0_EN_Pos         (27UL)                    /*!< CMU PCLK_CFG: UART0_EN (Bit 27)                       */
#define CMU_PCLK_CFG_UART0_EN_Msk         (0x8000000UL)             /*!< CMU PCLK_CFG: UART0_EN (Bitfield-Mask: 0x01)          */
#define CMU_PCLK_CFG_SPI1_EN_Pos          (26UL)                    /*!< CMU PCLK_CFG: SPI1_EN (Bit 26)                        */
#define CMU_PCLK_CFG_SPI1_EN_Msk          (0x4000000UL)             /*!< CMU PCLK_CFG: SPI1_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_SPI0_EN_Pos          (25UL)                    /*!< CMU PCLK_CFG: SPI0_EN (Bit 25)                        */
#define CMU_PCLK_CFG_SPI0_EN_Msk          (0x2000000UL)             /*!< CMU PCLK_CFG: SPI0_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_CC_PWM3_EN_Pos       (23UL)                    /*!< CMU PCLK_CFG: CC_PWM3_EN (Bit 23)                     */
#define CMU_PCLK_CFG_CC_PWM3_EN_Msk       (0x800000UL)              /*!< CMU PCLK_CFG: CC_PWM3_EN (Bitfield-Mask: 0x01)        */
#define CMU_PCLK_CFG_CC_PWM2_EN_Pos       (22UL)                    /*!< CMU PCLK_CFG: CC_PWM2_EN (Bit 22)                     */
#define CMU_PCLK_CFG_CC_PWM2_EN_Msk       (0x400000UL)              /*!< CMU PCLK_CFG: CC_PWM2_EN (Bitfield-Mask: 0x01)        */
#define CMU_PCLK_CFG_CC_PWM1_EN_Pos       (21UL)                    /*!< CMU PCLK_CFG: CC_PWM1_EN (Bit 21)                     */
#define CMU_PCLK_CFG_CC_PWM1_EN_Msk       (0x200000UL)              /*!< CMU PCLK_CFG: CC_PWM1_EN (Bitfield-Mask: 0x01)        */
#define CMU_PCLK_CFG_CC_PWM0_EN_Pos       (20UL)                    /*!< CMU PCLK_CFG: CC_PWM0_EN (Bit 20)                     */
#define CMU_PCLK_CFG_CC_PWM0_EN_Msk       (0x100000UL)              /*!< CMU PCLK_CFG: CC_PWM0_EN (Bitfield-Mask: 0x01)        */
#define CMU_PCLK_CFG_TIM2_EN_Pos          (19UL)                    /*!< CMU PCLK_CFG: TIM2_EN (Bit 19)                        */
#define CMU_PCLK_CFG_TIM2_EN_Msk          (0x80000UL)               /*!< CMU PCLK_CFG: TIM2_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_TIM1_EN_Pos          (18UL)                    /*!< CMU PCLK_CFG: TIM1_EN (Bit 18)                        */
#define CMU_PCLK_CFG_TIM1_EN_Msk          (0x40000UL)               /*!< CMU PCLK_CFG: TIM1_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_TIM0_EN_Pos          (17UL)                    /*!< CMU PCLK_CFG: TIM0_EN (Bit 17)                        */
#define CMU_PCLK_CFG_TIM0_EN_Msk          (0x20000UL)               /*!< CMU PCLK_CFG: TIM0_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_TICKER_EN_Pos        (16UL)                    /*!< CMU PCLK_CFG: TICKER_EN (Bit 16)                      */
#define CMU_PCLK_CFG_TICKER_EN_Msk        (0x10000UL)               /*!< CMU PCLK_CFG: TICKER_EN (Bitfield-Mask: 0x01)         */
#define CMU_PCLK_CFG_WDOG_EN_Pos          (15UL)                    /*!< CMU PCLK_CFG: WDOG_EN (Bit 15)                        */
#define CMU_PCLK_CFG_WDOG_EN_Msk          (0x8000UL)                /*!< CMU PCLK_CFG: WDOG_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_CRC_EN_Pos           (13UL)                    /*!< CMU PCLK_CFG: CRC_EN (Bit 13)                         */
#define CMU_PCLK_CFG_CRC_EN_Msk           (0x2000UL)                /*!< CMU PCLK_CFG: CRC_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_FLASH_EN_Pos         (12UL)                    /*!< CMU PCLK_CFG: FLASH_EN (Bit 12)                       */
#define CMU_PCLK_CFG_FLASH_EN_Msk         (0x1000UL)                /*!< CMU PCLK_CFG: FLASH_EN (Bitfield-Mask: 0x01)          */
#define CMU_PCLK_CFG_TRNG_EN_Pos          (10UL)                    /*!< CMU PCLK_CFG: TRNG_EN (Bit 10)                        */
#define CMU_PCLK_CFG_TRNG_EN_Msk          (0x400UL)                 /*!< CMU PCLK_CFG: TRNG_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_AES_EN_Pos           (9UL)                     /*!< CMU PCLK_CFG: AES_EN (Bit 9)                          */
#define CMU_PCLK_CFG_AES_EN_Msk           (0x200UL)                 /*!< CMU PCLK_CFG: AES_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_DMA_EN_Pos           (8UL)                     /*!< CMU PCLK_CFG: DMA_EN (Bit 8)                          */
#define CMU_PCLK_CFG_DMA_EN_Msk           (0x100UL)                 /*!< CMU PCLK_CFG: DMA_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_ADC_EN_Pos           (7UL)                     /*!< CMU PCLK_CFG: ADC_EN (Bit 7)                          */
#define CMU_PCLK_CFG_ADC_EN_Msk           (0x80UL)                  /*!< CMU PCLK_CFG: ADC_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_CMP_EN_Pos           (6UL)                     /*!< CMU PCLK_CFG: CMP_EN (Bit 6)                          */
#define CMU_PCLK_CFG_CMP_EN_Msk           (0x40UL)                  /*!< CMU PCLK_CFG: CMP_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_XBAR_EN_Pos          (5UL)                     /*!< CMU PCLK_CFG: XBAR_EN (Bit 5)                         */
#define CMU_PCLK_CFG_XBAR_EN_Msk          (0x20UL)                  /*!< CMU PCLK_CFG: XBAR_EN (Bitfield-Mask: 0x01)           */
#define CMU_PCLK_CFG_PMU_EN_Pos           (4UL)                     /*!< CMU PCLK_CFG: PMU_EN (Bit 4)                          */
#define CMU_PCLK_CFG_PMU_EN_Msk           (0x10UL)                  /*!< CMU PCLK_CFG: PMU_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_CL_SYSCFG_EN_Pos     (3UL)                     /*!< CMU PCLK_CFG: CL_SYSCFG_EN (Bit 3)                    */
#define CMU_PCLK_CFG_CL_SYSCFG_EN_Msk     (0x8UL)                   /*!< CMU PCLK_CFG: CL_SYSCFG_EN (Bitfield-Mask: 0x01)      */
#define CMU_PCLK_CFG_WUT_EN_Pos           (1UL)                     /*!< CMU PCLK_CFG: WUT_EN (Bit 1)                          */
#define CMU_PCLK_CFG_WUT_EN_Msk           (0x2UL)                   /*!< CMU PCLK_CFG: WUT_EN (Bitfield-Mask: 0x01)            */
#define CMU_PCLK_CFG_GPIO_EN_Pos          (0UL)                     /*!< CMU PCLK_CFG: GPIO_EN (Bit 1)                         */
#define CMU_PCLK_CFG_GPIO_EN_Msk          (0x1UL)                   /*!< CMU PCLK_CFG: GPIO_EN (Bitfield-Mask: 0x01)           */
/* ======================================================  LP_OSC_CFG  ======================================================= */
#define CMU_LP_OSC_CFG_FREQ_SEL_Pos       (6UL)                     /*!< CMU LP_OSC_CFG: FREQ_SEL (Bit 6)                      */
#define CMU_LP_OSC_CFG_FREQ_SEL_Msk       (0x40UL)                  /*!< CMU LP_OSC_CFG: FREQ_SEL (Bitfield-Mask: 0x01)        */
#define CMU_LP_OSC_CFG_DIV_Pos            (3UL)                     /*!< CMU LP_OSC_CFG: DIV (Bit 3)                           */
#define CMU_LP_OSC_CFG_DIV_Msk            (0x38UL)                  /*!< CMU LP_OSC_CFG: DIV (Bitfield-Mask: 0x07)             */
#define CMU_LP_OSC_CFG_CAL_SEL_Pos        (0UL)                     /*!< CMU LP_OSC_CFG: CAL_SEL (Bit 0)                       */
#define CMU_LP_OSC_CFG_CAL_SEL_Msk        (0x7UL)                   /*!< CMU LP_OSC_CFG: CAL_SEL (Bitfield-Mask: 0x07)         */
/* ======================================================  LP_OSC_FILT  ====================================================== */
/* ====================================================  LP_OSC_REF_DIV  ===================================================== */
/* ===================================================  LP_OSC_FREQ_TUNE  ==================================================== */
/* ======================================================  LP_OSC_PER  ======================================================= */
/* ======================================================  HS_OSC_CFG  ======================================================= */
#define CMU_HS_OSC_CFG_PER_GAIN_Pos       (8UL)                     /*!< CMU HS_OSC_CFG: PER_GAIN (Bit 8)                      */
#define CMU_HS_OSC_CFG_PER_GAIN_Msk       (0x100UL)                 /*!< CMU HS_OSC_CFG: PER_GAIN (Bitfield-Mask: 0x01)        */
#define CMU_HS_OSC_CFG_FREQ_SEL_Pos       (7UL)                     /*!< CMU HS_OSC_CFG: FREQ_SEL (Bit 7)                      */
#define CMU_HS_OSC_CFG_FREQ_SEL_Msk       (0x80UL)                  /*!< CMU HS_OSC_CFG: FREQ_SEL (Bitfield-Mask: 0x01)        */
#define CMU_HS_OSC_CFG_DIV_Pos            (3UL)                     /*!< CMU HS_OSC_CFG: DIV (Bit 3)                           */
#define CMU_HS_OSC_CFG_DIV_Msk            (0x78UL)                  /*!< CMU HS_OSC_CFG: DIV (Bitfield-Mask: 0x0f)             */
#define CMU_HS_OSC_CFG_CAL_SEL_Pos        (0UL)                     /*!< CMU HS_OSC_CFG: CAL_SEL (Bit 0)                       */
#define CMU_HS_OSC_CFG_CAL_SEL_Msk        (0x7UL)                   /*!< CMU HS_OSC_CFG: CAL_SEL (Bitfield-Mask: 0x07)         */
/* ======================================================  HS_OSC_FILT  ====================================================== */
/* ====================================================  HS_OSC_REF_DIV  ===================================================== */
/* =================================================  HS_OSC_20M_FREQ_TUNE  ================================================== */
/* =================================================  HS_OSC_16M_FREQ_TUNE  ================================================== */
/* ======================================================  HS_OSC_PER  ======================================================= */
/* ======================================================  OSC_ON_STS  ======================================================= */
#define CMU_OSC_ON_STS_LP_XOSC_Pos        (3UL)                     /*!< CMU OSC_ON_STS: LP_XOSC (Bit 3)                       */
#define CMU_OSC_ON_STS_LP_XOSC_Msk        (0x8UL)                   /*!< CMU OSC_ON_STS: LP_XOSC (Bitfield-Mask: 0x01)         */
#define CMU_OSC_ON_STS_HS_XOSC_Pos        (2UL)                     /*!< CMU OSC_ON_STS: HS_XOSC (Bit 2)                       */
#define CMU_OSC_ON_STS_HS_XOSC_Msk        (0x4UL)                   /*!< CMU OSC_ON_STS: HS_XOSC (Bitfield-Mask: 0x01)         */
#define CMU_OSC_ON_STS_LP_OSC_Pos         (1UL)                     /*!< CMU OSC_ON_STS: LP_OSC (Bit 1)                        */
#define CMU_OSC_ON_STS_LP_OSC_Msk         (0x2UL)                   /*!< CMU OSC_ON_STS: LP_OSC (Bitfield-Mask: 0x01)          */
#define CMU_OSC_ON_STS_HS_OSC_Pos         (0UL)                     /*!< CMU OSC_ON_STS: HS_OSC (Bit 0)                        */
#define CMU_OSC_ON_STS_HS_OSC_Msk         (0x1UL)                   /*!< CMU OSC_ON_STS: HS_OSC (Bitfield-Mask: 0x01)          */
/* =====================================================  OSC_READY_STS  ===================================================== */
#define CMU_OSC_READY_STS_LP_XOSC_Pos     (3UL)                     /*!< CMU OSC_READY_STS: LP_XOSC (Bit 3)                    */
#define CMU_OSC_READY_STS_LP_XOSC_Msk     (0x8UL)                   /*!< CMU OSC_READY_STS: LP_XOSC (Bitfield-Mask: 0x01)      */
#define CMU_OSC_READY_STS_HS_XOSC_Pos     (2UL)                     /*!< CMU OSC_READY_STS: HS_XOSC (Bit 2)                    */
#define CMU_OSC_READY_STS_HS_XOSC_Msk     (0x4UL)                   /*!< CMU OSC_READY_STS: HS_XOSC (Bitfield-Mask: 0x01)      */
#define CMU_OSC_READY_STS_LP_OSC_Pos      (1UL)                     /*!< CMU OSC_READY_STS: LP_OSC (Bit 1)                     */
#define CMU_OSC_READY_STS_LP_OSC_Msk      (0x2UL)                   /*!< CMU OSC_READY_STS: LP_OSC (Bitfield-Mask: 0x01)       */
#define CMU_OSC_READY_STS_HS_OSC_Pos      (0UL)                     /*!< CMU OSC_READY_STS: HS_OSC (Bit 0)                     */
#define CMU_OSC_READY_STS_HS_OSC_Msk      (0x1UL)                   /*!< CMU OSC_READY_STS: HS_OSC (Bitfield-Mask: 0x01)       */
/* ========================================================  INT_STS  ======================================================== */
#define CMU_INT_STS_LP_OSC_CAL_Pos        (4UL)                     /*!< CMU INT_STS: LP_OSC_CAL (Bit 4)                       */
#define CMU_INT_STS_LP_OSC_CAL_Msk        (0x10UL)                  /*!< CMU INT_STS: LP_OSC_CAL (Bitfield-Mask: 0x01)         */
#define CMU_INT_STS_HS_OSC_CAL_Pos        (3UL)                     /*!< CMU INT_STS: HS_OSC_CAL (Bit 3)                       */
#define CMU_INT_STS_HS_OSC_CAL_Msk        (0x8UL)                   /*!< CMU INT_STS: HS_OSC_CAL (Bitfield-Mask: 0x01)         */
#define CMU_INT_STS_LP_OSC_CAL_MISSED_Pos (2UL)                     /*!< CMU INT_STS: LP_OSC_CAL_MISSED (Bit 2)                */
#define CMU_INT_STS_LP_OSC_CAL_MISSED_Msk (0x4UL)                   /*!< CMU INT_STS: LP_OSC_CAL_MISSED (Bitfield-Mask: 0x01)  */
#define CMU_INT_STS_HS_OSC_CAL_MISSED_Pos (1UL)                     /*!< CMU INT_STS: HS_OSC_CAL_MISSED (Bit 1)                */
#define CMU_INT_STS_HS_OSC_CAL_MISSED_Msk (0x2UL)                   /*!< CMU INT_STS: HS_OSC_CAL_MISSED (Bitfield-Mask: 0x01)  */
#define CMU_INT_STS_CLK_LOSS_Pos          (0UL)                     /*!< CMU INT_STS: CLK_LOSS (Bit 0)                         */
#define CMU_INT_STS_CLK_LOSS_Msk          (0x1UL)                   /*!< CMU INT_STS: CLK_LOSS (Bitfield-Mask: 0x01)           */
/* ======================================================  LP_XOSC_CFG  ====================================================== */
#define CMU_LP_XOSC_CFG_GM_Pos            (0UL)                     /*!< CMU LP_XOSC_CFG: GM (Bit 0)                           */
#define CMU_LP_XOSC_CFG_GM_Msk            (0x1fUL)                  /*!< CMU LP_XOSC_CFG: GM (Bitfield-Mask: 0x1f)             */
/* ====================================================  HS_XOSC_GM_CFG  ===================================================== */
/* ===================================================  HS_XOSC_AMPL_CFG  ==================================================== */
#define CMU_HS_XOSC_AMPL_CFG_REG_EN_Pos   (7UL)                     /*!< CMU HS_XOSC_AMPL_CFG: REG_EN (Bit 7)                  */
#define CMU_HS_XOSC_AMPL_CFG_REG_EN_Msk   (0x80UL)                  /*!< CMU HS_XOSC_AMPL_CFG: REG_EN (Bitfield-Mask: 0x01)    */
#define CMU_HS_XOSC_AMPL_CFG_AMPL_Pos     (0UL)                     /*!< CMU HS_XOSC_AMPL_CFG: AMPL (Bit 0)                    */
#define CMU_HS_XOSC_AMPL_CFG_AMPL_Msk     (0x7UL)                   /*!< CMU HS_XOSC_AMPL_CFG: AMPL (Bitfield-Mask: 0x07)      */
/* =====================================================  HS_XOSC_READY  ===================================================== */
#define CMU_HS_XOSC_READY_SIG_DET_STS_Pos (7UL)                     /*!< CMU HS_XOSC_READY: SIG_DET_STS (Bit 7)                */
#define CMU_HS_XOSC_READY_SIG_DET_STS_Msk (0x80UL)                  /*!< CMU HS_XOSC_READY: SIG_DET_STS (Bitfield-Mask: 0x01)  */
#define CMU_HS_XOSC_READY_READY_STS_Pos   (6UL)                     /*!< CMU HS_XOSC_READY: READY_STS (Bit 6)                  */
#define CMU_HS_XOSC_READY_READY_STS_Msk   (0x40UL)                  /*!< CMU HS_XOSC_READY: READY_STS (Bitfield-Mask: 0x01)    */
#define CMU_HS_XOSC_READY_OUT_AMP_DIS_Pos (3UL)                     /*!< CMU HS_XOSC_READY: OUT_AMP_DIS (Bit 3)                */
#define CMU_HS_XOSC_READY_OUT_AMP_DIS_Msk (0x8UL)                   /*!< CMU HS_XOSC_READY: OUT_AMP_DIS (Bitfield-Mask: 0x01)  */
#define CMU_HS_XOSC_READY_MOD_Pos         (0UL)                     /*!< CMU HS_XOSC_READY: MOD (Bit 0)                        */
#define CMU_HS_XOSC_READY_MOD_Msk         (0x7UL)                   /*!< CMU HS_XOSC_READY: MOD (Bitfield-Mask: 0x07)          */
/* ======================================================  AO_SCRATCH  ======================================================= */


/* =========================================================================================================================== */
/* ================                                          CC_PWM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */
/* =========================================================  DATA  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           XBAR                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  ANA_CFG  ======================================================== */
#define XBAR_ANA_CFG_PA7_Pos              (7UL)                     /*!< XBAR ANA_CFG: PA7 (Bit 7)                             */
#define XBAR_ANA_CFG_PA7_Msk              (0x80UL)                  /*!< XBAR ANA_CFG: PA7 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA6_Pos              (6UL)                     /*!< XBAR ANA_CFG: PA6 (Bit 6)                             */
#define XBAR_ANA_CFG_PA6_Msk              (0x40UL)                  /*!< XBAR ANA_CFG: PA6 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA5_Pos              (5UL)                     /*!< XBAR ANA_CFG: PA5 (Bit 5)                             */
#define XBAR_ANA_CFG_PA5_Msk              (0x20UL)                  /*!< XBAR ANA_CFG: PA5 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA4_Pos              (4UL)                     /*!< XBAR ANA_CFG: PA4 (Bit 4)                             */
#define XBAR_ANA_CFG_PA4_Msk              (0x10UL)                  /*!< XBAR ANA_CFG: PA4 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA3_Pos              (3UL)                     /*!< XBAR ANA_CFG: PA3 (Bit 3)                             */
#define XBAR_ANA_CFG_PA3_Msk              (0x8UL)                   /*!< XBAR ANA_CFG: PA3 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA2_Pos              (2UL)                     /*!< XBAR ANA_CFG: PA2 (Bit 2)                             */
#define XBAR_ANA_CFG_PA2_Msk              (0x4UL)                   /*!< XBAR ANA_CFG: PA2 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA1_Pos              (1UL)                     /*!< XBAR ANA_CFG: PA1 (Bit 1)                             */
#define XBAR_ANA_CFG_PA1_Msk              (0x2UL)                   /*!< XBAR ANA_CFG: PA1 (Bitfield-Mask: 0x01)               */
#define XBAR_ANA_CFG_PA0_Pos              (0UL)                     /*!< XBAR ANA_CFG: PA0 (Bit 0)                             */
#define XBAR_ANA_CFG_PA0_Msk              (0x1UL)                   /*!< XBAR ANA_CFG: PA0 (Bitfield-Mask: 0x01)               */
/* ========================================================  OUT_CFG  ======================================================== */
#define XBAR_OUT_CFG_PR7_Pos              (31UL)                    /*!< XBAR OUT_CFG: PR7 (Bit 31)                            */
#define XBAR_OUT_CFG_PR7_Msk              (0x80000000UL)            /*!< XBAR OUT_CFG: PR7 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR6_Pos              (30UL)                    /*!< XBAR OUT_CFG: PR6 (Bit 30)                            */
#define XBAR_OUT_CFG_PR6_Msk              (0x40000000UL)            /*!< XBAR OUT_CFG: PR6 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR5_Pos              (29UL)                    /*!< XBAR OUT_CFG: PR5 (Bit 29)                            */
#define XBAR_OUT_CFG_PR5_Msk              (0x20000000UL)            /*!< XBAR OUT_CFG: PR5 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR4_Pos              (28UL)                    /*!< XBAR OUT_CFG: PR4 (Bit 28)                            */
#define XBAR_OUT_CFG_PR4_Msk              (0x10000000UL)            /*!< XBAR OUT_CFG: PR4 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR3_Pos              (27UL)                    /*!< XBAR OUT_CFG: PR3 (Bit 27)                            */
#define XBAR_OUT_CFG_PR3_Msk              (0x8000000UL)             /*!< XBAR OUT_CFG: PR3 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR2_Pos              (26UL)                    /*!< XBAR OUT_CFG: PR2 (Bit 26)                            */
#define XBAR_OUT_CFG_PR2_Msk              (0x4000000UL)             /*!< XBAR OUT_CFG: PR2 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR1_Pos              (25UL)                    /*!< XBAR OUT_CFG: PR1 (Bit 25)                            */
#define XBAR_OUT_CFG_PR1_Msk              (0x2000000UL)             /*!< XBAR OUT_CFG: PR1 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PR0_Pos              (24UL)                    /*!< XBAR OUT_CFG: PR0 (Bit 24)                            */
#define XBAR_OUT_CFG_PR0_Msk              (0x1000000UL)             /*!< XBAR OUT_CFG: PR0 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC7_Pos              (23UL)                    /*!< XBAR OUT_CFG: PC7 (Bit 23)                            */
#define XBAR_OUT_CFG_PC7_Msk              (0x800000UL)              /*!< XBAR OUT_CFG: PC7 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC6_Pos              (22UL)                    /*!< XBAR OUT_CFG: PC6 (Bit 22)                            */
#define XBAR_OUT_CFG_PC6_Msk              (0x400000UL)              /*!< XBAR OUT_CFG: PC6 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC5_Pos              (21UL)                    /*!< XBAR OUT_CFG: PC5 (Bit 21)                            */
#define XBAR_OUT_CFG_PC5_Msk              (0x200000UL)              /*!< XBAR OUT_CFG: PC5 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC4_Pos              (20UL)                    /*!< XBAR OUT_CFG: PC4 (Bit 20)                            */
#define XBAR_OUT_CFG_PC4_Msk              (0x100000UL)              /*!< XBAR OUT_CFG: PC4 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC3_Pos              (19UL)                    /*!< XBAR OUT_CFG: PC3 (Bit 19)                            */
#define XBAR_OUT_CFG_PC3_Msk              (0x80000UL)               /*!< XBAR OUT_CFG: PC3 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC2_Pos              (18UL)                    /*!< XBAR OUT_CFG: PC2 (Bit 18)                            */
#define XBAR_OUT_CFG_PC2_Msk              (0x40000UL)               /*!< XBAR OUT_CFG: PC2 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC1_Pos              (17UL)                    /*!< XBAR OUT_CFG: PC1 (Bit 17)                            */
#define XBAR_OUT_CFG_PC1_Msk              (0x20000UL)               /*!< XBAR OUT_CFG: PC1 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PC0_Pos              (16UL)                    /*!< XBAR OUT_CFG: PC0 (Bit 16)                            */
#define XBAR_OUT_CFG_PC0_Msk              (0x10000UL)               /*!< XBAR OUT_CFG: PC0 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB7_Pos              (15UL)                    /*!< XBAR OUT_CFG: PB7 (Bit 15)                            */
#define XBAR_OUT_CFG_PB7_Msk              (0x8000UL)                /*!< XBAR OUT_CFG: PB7 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB6_Pos              (14UL)                    /*!< XBAR OUT_CFG: PB6 (Bit 14)                            */
#define XBAR_OUT_CFG_PB6_Msk              (0x4000UL)                /*!< XBAR OUT_CFG: PB6 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB5_Pos              (13UL)                    /*!< XBAR OUT_CFG: PB5 (Bit 13)                            */
#define XBAR_OUT_CFG_PB5_Msk              (0x2000UL)                /*!< XBAR OUT_CFG: PB5 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB4_Pos              (12UL)                    /*!< XBAR OUT_CFG: PB4 (Bit 12)                            */
#define XBAR_OUT_CFG_PB4_Msk              (0x1000UL)                /*!< XBAR OUT_CFG: PB4 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB3_Pos              (11UL)                    /*!< XBAR OUT_CFG: PB3 (Bit 11)                            */
#define XBAR_OUT_CFG_PB3_Msk              (0x800UL)                 /*!< XBAR OUT_CFG: PB3 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB2_Pos              (10UL)                    /*!< XBAR OUT_CFG: PB2 (Bit 10)                            */
#define XBAR_OUT_CFG_PB2_Msk              (0x400UL)                 /*!< XBAR OUT_CFG: PB2 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB1_Pos              (9UL)                     /*!< XBAR OUT_CFG: PB1 (Bit 9)                             */
#define XBAR_OUT_CFG_PB1_Msk              (0x200UL)                 /*!< XBAR OUT_CFG: PB1 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PB0_Pos              (8UL)                     /*!< XBAR OUT_CFG: PB0 (Bit 8)                             */
#define XBAR_OUT_CFG_PB0_Msk              (0x100UL)                 /*!< XBAR OUT_CFG: PB0 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA7_Pos              (7UL)                     /*!< XBAR OUT_CFG: PA7 (Bit 7)                             */
#define XBAR_OUT_CFG_PA7_Msk              (0x80UL)                  /*!< XBAR OUT_CFG: PA7 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA6_Pos              (6UL)                     /*!< XBAR OUT_CFG: PA6 (Bit 6)                             */
#define XBAR_OUT_CFG_PA6_Msk              (0x40UL)                  /*!< XBAR OUT_CFG: PA6 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA5_Pos              (5UL)                     /*!< XBAR OUT_CFG: PA5 (Bit 5)                             */
#define XBAR_OUT_CFG_PA5_Msk              (0x20UL)                  /*!< XBAR OUT_CFG: PA5 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA4_Pos              (4UL)                     /*!< XBAR OUT_CFG: PA4 (Bit 4)                             */
#define XBAR_OUT_CFG_PA4_Msk              (0x10UL)                  /*!< XBAR OUT_CFG: PA4 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA3_Pos              (3UL)                     /*!< XBAR OUT_CFG: PA3 (Bit 3)                             */
#define XBAR_OUT_CFG_PA3_Msk              (0x8UL)                   /*!< XBAR OUT_CFG: PA3 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA2_Pos              (2UL)                     /*!< XBAR OUT_CFG: PA2 (Bit 2)                             */
#define XBAR_OUT_CFG_PA2_Msk              (0x4UL)                   /*!< XBAR OUT_CFG: PA2 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA1_Pos              (1UL)                     /*!< XBAR OUT_CFG: PA1 (Bit 1)                             */
#define XBAR_OUT_CFG_PA1_Msk              (0x2UL)                   /*!< XBAR OUT_CFG: PA1 (Bitfield-Mask: 0x01)               */
#define XBAR_OUT_CFG_PA0_Pos              (0UL)                     /*!< XBAR OUT_CFG: PA0 (Bit 0)                             */
#define XBAR_OUT_CFG_PA0_Msk              (0x1UL)                   /*!< XBAR OUT_CFG: PA0 (Bitfield-Mask: 0x01)               */
/* ======================================================  PULL_UP_CFG  ====================================================== */
#define XBAR_PULL_UP_CFG_PR7_Pos          (31UL)                    /*!< XBAR PULL_UP_CFG: PR7 (Bit 31)                        */
#define XBAR_PULL_UP_CFG_PR7_Msk          (0x80000000UL)            /*!< XBAR PULL_UP_CFG: PR7 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR6_Pos          (30UL)                    /*!< XBAR PULL_UP_CFG: PR6 (Bit 30)                        */
#define XBAR_PULL_UP_CFG_PR6_Msk          (0x40000000UL)            /*!< XBAR PULL_UP_CFG: PR6 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR5_Pos          (29UL)                    /*!< XBAR PULL_UP_CFG: PR5 (Bit 29)                        */
#define XBAR_PULL_UP_CFG_PR5_Msk          (0x20000000UL)            /*!< XBAR PULL_UP_CFG: PR5 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR4_Pos          (28UL)                    /*!< XBAR PULL_UP_CFG: PR4 (Bit 28)                        */
#define XBAR_PULL_UP_CFG_PR4_Msk          (0x10000000UL)            /*!< XBAR PULL_UP_CFG: PR4 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR3_Pos          (27UL)                    /*!< XBAR PULL_UP_CFG: PR3 (Bit 27)                        */
#define XBAR_PULL_UP_CFG_PR3_Msk          (0x8000000UL)             /*!< XBAR PULL_UP_CFG: PR3 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR2_Pos          (26UL)                    /*!< XBAR PULL_UP_CFG: PR2 (Bit 26)                        */
#define XBAR_PULL_UP_CFG_PR2_Msk          (0x4000000UL)             /*!< XBAR PULL_UP_CFG: PR2 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR1_Pos          (25UL)                    /*!< XBAR PULL_UP_CFG: PR1 (Bit 25)                        */
#define XBAR_PULL_UP_CFG_PR1_Msk          (0x2000000UL)             /*!< XBAR PULL_UP_CFG: PR1 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PR0_Pos          (24UL)                    /*!< XBAR PULL_UP_CFG: PR0 (Bit 24)                        */
#define XBAR_PULL_UP_CFG_PR0_Msk          (0x1000000UL)             /*!< XBAR PULL_UP_CFG: PR0 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC7_Pos          (23UL)                    /*!< XBAR PULL_UP_CFG: PC7 (Bit 23)                        */
#define XBAR_PULL_UP_CFG_PC7_Msk          (0x800000UL)              /*!< XBAR PULL_UP_CFG: PC7 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC6_Pos          (22UL)                    /*!< XBAR PULL_UP_CFG: PC6 (Bit 22)                        */
#define XBAR_PULL_UP_CFG_PC6_Msk          (0x400000UL)              /*!< XBAR PULL_UP_CFG: PC6 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC5_Pos          (21UL)                    /*!< XBAR PULL_UP_CFG: PC5 (Bit 21)                        */
#define XBAR_PULL_UP_CFG_PC5_Msk          (0x200000UL)              /*!< XBAR PULL_UP_CFG: PC5 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC4_Pos          (20UL)                    /*!< XBAR PULL_UP_CFG: PC4 (Bit 20)                        */
#define XBAR_PULL_UP_CFG_PC4_Msk          (0x100000UL)              /*!< XBAR PULL_UP_CFG: PC4 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC3_Pos          (19UL)                    /*!< XBAR PULL_UP_CFG: PC3 (Bit 19)                        */
#define XBAR_PULL_UP_CFG_PC3_Msk          (0x80000UL)               /*!< XBAR PULL_UP_CFG: PC3 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC2_Pos          (18UL)                    /*!< XBAR PULL_UP_CFG: PC2 (Bit 18)                        */
#define XBAR_PULL_UP_CFG_PC2_Msk          (0x40000UL)               /*!< XBAR PULL_UP_CFG: PC2 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC1_Pos          (17UL)                    /*!< XBAR PULL_UP_CFG: PC1 (Bit 17)                        */
#define XBAR_PULL_UP_CFG_PC1_Msk          (0x20000UL)               /*!< XBAR PULL_UP_CFG: PC1 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PC0_Pos          (16UL)                    /*!< XBAR PULL_UP_CFG: PC0 (Bit 16)                        */
#define XBAR_PULL_UP_CFG_PC0_Msk          (0x10000UL)               /*!< XBAR PULL_UP_CFG: PC0 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB7_Pos          (15UL)                    /*!< XBAR PULL_UP_CFG: PB7 (Bit 15)                        */
#define XBAR_PULL_UP_CFG_PB7_Msk          (0x8000UL)                /*!< XBAR PULL_UP_CFG: PB7 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB6_Pos          (14UL)                    /*!< XBAR PULL_UP_CFG: PB6 (Bit 14)                        */
#define XBAR_PULL_UP_CFG_PB6_Msk          (0x4000UL)                /*!< XBAR PULL_UP_CFG: PB6 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB5_Pos          (13UL)                    /*!< XBAR PULL_UP_CFG: PB5 (Bit 13)                        */
#define XBAR_PULL_UP_CFG_PB5_Msk          (0x2000UL)                /*!< XBAR PULL_UP_CFG: PB5 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB4_Pos          (12UL)                    /*!< XBAR PULL_UP_CFG: PB4 (Bit 12)                        */
#define XBAR_PULL_UP_CFG_PB4_Msk          (0x1000UL)                /*!< XBAR PULL_UP_CFG: PB4 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB3_Pos          (11UL)                    /*!< XBAR PULL_UP_CFG: PB3 (Bit 11)                        */
#define XBAR_PULL_UP_CFG_PB3_Msk          (0x800UL)                 /*!< XBAR PULL_UP_CFG: PB3 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB2_Pos          (10UL)                    /*!< XBAR PULL_UP_CFG: PB2 (Bit 10)                        */
#define XBAR_PULL_UP_CFG_PB2_Msk          (0x400UL)                 /*!< XBAR PULL_UP_CFG: PB2 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB1_Pos          (9UL)                     /*!< XBAR PULL_UP_CFG: PB1 (Bit 9)                         */
#define XBAR_PULL_UP_CFG_PB1_Msk          (0x200UL)                 /*!< XBAR PULL_UP_CFG: PB1 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PB0_Pos          (8UL)                     /*!< XBAR PULL_UP_CFG: PB0 (Bit 8)                         */
#define XBAR_PULL_UP_CFG_PB0_Msk          (0x100UL)                 /*!< XBAR PULL_UP_CFG: PB0 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA7_Pos          (7UL)                     /*!< XBAR PULL_UP_CFG: PA7 (Bit 7)                         */
#define XBAR_PULL_UP_CFG_PA7_Msk          (0x80UL)                  /*!< XBAR PULL_UP_CFG: PA7 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA6_Pos          (6UL)                     /*!< XBAR PULL_UP_CFG: PA6 (Bit 6)                         */
#define XBAR_PULL_UP_CFG_PA6_Msk          (0x40UL)                  /*!< XBAR PULL_UP_CFG: PA6 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA5_Pos          (5UL)                     /*!< XBAR PULL_UP_CFG: PA5 (Bit 5)                         */
#define XBAR_PULL_UP_CFG_PA5_Msk          (0x20UL)                  /*!< XBAR PULL_UP_CFG: PA5 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA4_Pos          (4UL)                     /*!< XBAR PULL_UP_CFG: PA4 (Bit 4)                         */
#define XBAR_PULL_UP_CFG_PA4_Msk          (0x10UL)                  /*!< XBAR PULL_UP_CFG: PA4 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA3_Pos          (3UL)                     /*!< XBAR PULL_UP_CFG: PA3 (Bit 3)                         */
#define XBAR_PULL_UP_CFG_PA3_Msk          (0x8UL)                   /*!< XBAR PULL_UP_CFG: PA3 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA2_Pos          (2UL)                     /*!< XBAR PULL_UP_CFG: PA2 (Bit 2)                         */
#define XBAR_PULL_UP_CFG_PA2_Msk          (0x4UL)                   /*!< XBAR PULL_UP_CFG: PA2 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA1_Pos          (1UL)                     /*!< XBAR PULL_UP_CFG: PA1 (Bit 1)                         */
#define XBAR_PULL_UP_CFG_PA1_Msk          (0x2UL)                   /*!< XBAR PULL_UP_CFG: PA1 (Bitfield-Mask: 0x01)           */
#define XBAR_PULL_UP_CFG_PA0_Pos          (0UL)                     /*!< XBAR PULL_UP_CFG: PA0 (Bit 0)                         */
#define XBAR_PULL_UP_CFG_PA0_Msk          (0x1UL)                   /*!< XBAR PULL_UP_CFG: PA0 (Bitfield-Mask: 0x01)           */
/* =====================================================  PULL_DOWN_CFG  ===================================================== */
#define XBAR_PULL_DOWN_CFG_PR7_Pos        (31UL)                    /*!< XBAR PULL_DOWN_CFG: PR7 (Bit 31)                      */
#define XBAR_PULL_DOWN_CFG_PR7_Msk        (0x80000000UL)            /*!< XBAR PULL_DOWN_CFG: PR7 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR6_Pos        (30UL)                    /*!< XBAR PULL_DOWN_CFG: PR6 (Bit 30)                      */
#define XBAR_PULL_DOWN_CFG_PR6_Msk        (0x40000000UL)            /*!< XBAR PULL_DOWN_CFG: PR6 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR5_Pos        (29UL)                    /*!< XBAR PULL_DOWN_CFG: PR5 (Bit 29)                      */
#define XBAR_PULL_DOWN_CFG_PR5_Msk        (0x20000000UL)            /*!< XBAR PULL_DOWN_CFG: PR5 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR4_Pos        (28UL)                    /*!< XBAR PULL_DOWN_CFG: PR4 (Bit 28)                      */
#define XBAR_PULL_DOWN_CFG_PR4_Msk        (0x10000000UL)            /*!< XBAR PULL_DOWN_CFG: PR4 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR3_Pos        (27UL)                    /*!< XBAR PULL_DOWN_CFG: PR3 (Bit 27)                      */
#define XBAR_PULL_DOWN_CFG_PR3_Msk        (0x8000000UL)             /*!< XBAR PULL_DOWN_CFG: PR3 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR2_Pos        (26UL)                    /*!< XBAR PULL_DOWN_CFG: PR2 (Bit 26)                      */
#define XBAR_PULL_DOWN_CFG_PR2_Msk        (0x4000000UL)             /*!< XBAR PULL_DOWN_CFG: PR2 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR1_Pos        (25UL)                    /*!< XBAR PULL_DOWN_CFG: PR1 (Bit 25)                      */
#define XBAR_PULL_DOWN_CFG_PR1_Msk        (0x2000000UL)             /*!< XBAR PULL_DOWN_CFG: PR1 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PR0_Pos        (24UL)                    /*!< XBAR PULL_DOWN_CFG: PR0 (Bit 24)                      */
#define XBAR_PULL_DOWN_CFG_PR0_Msk        (0x1000000UL)             /*!< XBAR PULL_DOWN_CFG: PR0 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC7_Pos        (23UL)                    /*!< XBAR PULL_DOWN_CFG: PC7 (Bit 23)                      */
#define XBAR_PULL_DOWN_CFG_PC7_Msk        (0x800000UL)              /*!< XBAR PULL_DOWN_CFG: PC7 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC6_Pos        (22UL)                    /*!< XBAR PULL_DOWN_CFG: PC6 (Bit 22)                      */
#define XBAR_PULL_DOWN_CFG_PC6_Msk        (0x400000UL)              /*!< XBAR PULL_DOWN_CFG: PC6 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC5_Pos        (21UL)                    /*!< XBAR PULL_DOWN_CFG: PC5 (Bit 21)                      */
#define XBAR_PULL_DOWN_CFG_PC5_Msk        (0x200000UL)              /*!< XBAR PULL_DOWN_CFG: PC5 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC4_Pos        (20UL)                    /*!< XBAR PULL_DOWN_CFG: PC4 (Bit 20)                      */
#define XBAR_PULL_DOWN_CFG_PC4_Msk        (0x100000UL)              /*!< XBAR PULL_DOWN_CFG: PC4 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC3_Pos        (19UL)                    /*!< XBAR PULL_DOWN_CFG: PC3 (Bit 19)                      */
#define XBAR_PULL_DOWN_CFG_PC3_Msk        (0x80000UL)               /*!< XBAR PULL_DOWN_CFG: PC3 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC2_Pos        (18UL)                    /*!< XBAR PULL_DOWN_CFG: PC2 (Bit 18)                      */
#define XBAR_PULL_DOWN_CFG_PC2_Msk        (0x40000UL)               /*!< XBAR PULL_DOWN_CFG: PC2 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC1_Pos        (17UL)                    /*!< XBAR PULL_DOWN_CFG: PC1 (Bit 17)                      */
#define XBAR_PULL_DOWN_CFG_PC1_Msk        (0x20000UL)               /*!< XBAR PULL_DOWN_CFG: PC1 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PC0_Pos        (16UL)                    /*!< XBAR PULL_DOWN_CFG: PC0 (Bit 16)                      */
#define XBAR_PULL_DOWN_CFG_PC0_Msk        (0x10000UL)               /*!< XBAR PULL_DOWN_CFG: PC0 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB7_Pos        (15UL)                    /*!< XBAR PULL_DOWN_CFG: PB7 (Bit 15)                      */
#define XBAR_PULL_DOWN_CFG_PB7_Msk        (0x8000UL)                /*!< XBAR PULL_DOWN_CFG: PB7 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB6_Pos        (14UL)                    /*!< XBAR PULL_DOWN_CFG: PB6 (Bit 14)                      */
#define XBAR_PULL_DOWN_CFG_PB6_Msk        (0x4000UL)                /*!< XBAR PULL_DOWN_CFG: PB6 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB5_Pos        (13UL)                    /*!< XBAR PULL_DOWN_CFG: PB5 (Bit 13)                      */
#define XBAR_PULL_DOWN_CFG_PB5_Msk        (0x2000UL)                /*!< XBAR PULL_DOWN_CFG: PB5 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB4_Pos        (12UL)                    /*!< XBAR PULL_DOWN_CFG: PB4 (Bit 12)                      */
#define XBAR_PULL_DOWN_CFG_PB4_Msk        (0x1000UL)                /*!< XBAR PULL_DOWN_CFG: PB4 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB3_Pos        (11UL)                    /*!< XBAR PULL_DOWN_CFG: PB3 (Bit 11)                      */
#define XBAR_PULL_DOWN_CFG_PB3_Msk        (0x800UL)                 /*!< XBAR PULL_DOWN_CFG: PB3 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB2_Pos        (10UL)                    /*!< XBAR PULL_DOWN_CFG: PB2 (Bit 10)                      */
#define XBAR_PULL_DOWN_CFG_PB2_Msk        (0x400UL)                 /*!< XBAR PULL_DOWN_CFG: PB2 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB1_Pos        (9UL)                     /*!< XBAR PULL_DOWN_CFG: PB1 (Bit 9)                       */
#define XBAR_PULL_DOWN_CFG_PB1_Msk        (0x200UL)                 /*!< XBAR PULL_DOWN_CFG: PB1 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PB0_Pos        (8UL)                     /*!< XBAR PULL_DOWN_CFG: PB0 (Bit 8)                       */
#define XBAR_PULL_DOWN_CFG_PB0_Msk        (0x100UL)                 /*!< XBAR PULL_DOWN_CFG: PB0 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA7_Pos        (7UL)                     /*!< XBAR PULL_DOWN_CFG: PA7 (Bit 7)                       */
#define XBAR_PULL_DOWN_CFG_PA7_Msk        (0x80UL)                  /*!< XBAR PULL_DOWN_CFG: PA7 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA6_Pos        (6UL)                     /*!< XBAR PULL_DOWN_CFG: PA6 (Bit 6)                       */
#define XBAR_PULL_DOWN_CFG_PA6_Msk        (0x40UL)                  /*!< XBAR PULL_DOWN_CFG: PA6 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA5_Pos        (5UL)                     /*!< XBAR PULL_DOWN_CFG: PA5 (Bit 5)                       */
#define XBAR_PULL_DOWN_CFG_PA5_Msk        (0x20UL)                  /*!< XBAR PULL_DOWN_CFG: PA5 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA4_Pos        (4UL)                     /*!< XBAR PULL_DOWN_CFG: PA4 (Bit 4)                       */
#define XBAR_PULL_DOWN_CFG_PA4_Msk        (0x10UL)                  /*!< XBAR PULL_DOWN_CFG: PA4 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA3_Pos        (3UL)                     /*!< XBAR PULL_DOWN_CFG: PA3 (Bit 3)                       */
#define XBAR_PULL_DOWN_CFG_PA3_Msk        (0x8UL)                   /*!< XBAR PULL_DOWN_CFG: PA3 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA2_Pos        (2UL)                     /*!< XBAR PULL_DOWN_CFG: PA2 (Bit 2)                       */
#define XBAR_PULL_DOWN_CFG_PA2_Msk        (0x4UL)                   /*!< XBAR PULL_DOWN_CFG: PA2 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA1_Pos        (1UL)                     /*!< XBAR PULL_DOWN_CFG: PA1 (Bit 1)                       */
#define XBAR_PULL_DOWN_CFG_PA1_Msk        (0x2UL)                   /*!< XBAR PULL_DOWN_CFG: PA1 (Bitfield-Mask: 0x01)         */
#define XBAR_PULL_DOWN_CFG_PA0_Pos        (0UL)                     /*!< XBAR PULL_DOWN_CFG: PA0 (Bit 0)                       */
#define XBAR_PULL_DOWN_CFG_PA0_Msk        (0x1UL)                   /*!< XBAR PULL_DOWN_CFG: PA0 (Bitfield-Mask: 0x01)         */
/* ========================================================  PA_CFG  ========================================================= */
#define XBAR_PA_CFG_PA7_Pos               (28UL)                    /*!< XBAR PA_CFG: PA7 (Bit 28)                             */
#define XBAR_PA_CFG_PA7_Msk               (0x70000000UL)            /*!< XBAR PA_CFG: PA7 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA6_Pos               (24UL)                    /*!< XBAR PA_CFG: PA6 (Bit 24)                             */
#define XBAR_PA_CFG_PA6_Msk               (0x7000000UL)             /*!< XBAR PA_CFG: PA6 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA5_Pos               (20UL)                    /*!< XBAR PA_CFG: PA5 (Bit 20)                             */
#define XBAR_PA_CFG_PA5_Msk               (0x700000UL)              /*!< XBAR PA_CFG: PA5 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA4_Pos               (16UL)                    /*!< XBAR PA_CFG: PA4 (Bit 16)                             */
#define XBAR_PA_CFG_PA4_Msk               (0x70000UL)               /*!< XBAR PA_CFG: PA4 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA3_Pos               (12UL)                    /*!< XBAR PA_CFG: PA3 (Bit 12)                             */
#define XBAR_PA_CFG_PA3_Msk               (0x7000UL)                /*!< XBAR PA_CFG: PA3 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA2_Pos               (8UL)                     /*!< XBAR PA_CFG: PA2 (Bit 8)                              */
#define XBAR_PA_CFG_PA2_Msk               (0x700UL)                 /*!< XBAR PA_CFG: PA2 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA1_Pos               (4UL)                     /*!< XBAR PA_CFG: PA1 (Bit 4)                              */
#define XBAR_PA_CFG_PA1_Msk               (0x70UL)                  /*!< XBAR PA_CFG: PA1 (Bitfield-Mask: 0x07)                */
#define XBAR_PA_CFG_PA0_Pos               (0UL)                     /*!< XBAR PA_CFG: PA0 (Bit 0)                              */
#define XBAR_PA_CFG_PA0_Msk               (0x7UL)                   /*!< XBAR PA_CFG: PA0 (Bitfield-Mask: 0x07)                */
/* ========================================================  PB_CFG  ========================================================= */
#define XBAR_PB_CFG_PB7_Pos               (28UL)                    /*!< XBAR PB_CFG: PB7 (Bit 28)                             */
#define XBAR_PB_CFG_PB7_Msk               (0x70000000UL)            /*!< XBAR PB_CFG: PB7 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB6_Pos               (24UL)                    /*!< XBAR PB_CFG: PB6 (Bit 24)                             */
#define XBAR_PB_CFG_PB6_Msk               (0x7000000UL)             /*!< XBAR PB_CFG: PB6 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB5_Pos               (20UL)                    /*!< XBAR PB_CFG: PB5 (Bit 20)                             */
#define XBAR_PB_CFG_PB5_Msk               (0x700000UL)              /*!< XBAR PB_CFG: PB5 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB4_Pos               (16UL)                    /*!< XBAR PB_CFG: PB4 (Bit 16)                             */
#define XBAR_PB_CFG_PB4_Msk               (0x70000UL)               /*!< XBAR PB_CFG: PB4 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB3_Pos               (12UL)                    /*!< XBAR PB_CFG: PB3 (Bit 12)                             */
#define XBAR_PB_CFG_PB3_Msk               (0x7000UL)                /*!< XBAR PB_CFG: PB3 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB2_Pos               (8UL)                     /*!< XBAR PB_CFG: PB2 (Bit 8)                              */
#define XBAR_PB_CFG_PB2_Msk               (0x700UL)                 /*!< XBAR PB_CFG: PB2 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB1_Pos               (4UL)                     /*!< XBAR PB_CFG: PB1 (Bit 4)                              */
#define XBAR_PB_CFG_PB1_Msk               (0x70UL)                  /*!< XBAR PB_CFG: PB1 (Bitfield-Mask: 0x07)                */
#define XBAR_PB_CFG_PB0_Pos               (0UL)                     /*!< XBAR PB_CFG: PB0 (Bit 0)                              */
#define XBAR_PB_CFG_PB0_Msk               (0x7UL)                   /*!< XBAR PB_CFG: PB0 (Bitfield-Mask: 0x07)                */
/* ========================================================  PC_CFG  ========================================================= */
#define XBAR_PC_CFG_PC7_Pos               (28UL)                    /*!< XBAR PC_CFG: PC7 (Bit 28)                             */
#define XBAR_PC_CFG_PC7_Msk               (0x70000000UL)            /*!< XBAR PC_CFG: PC7 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC6_Pos               (24UL)                    /*!< XBAR PC_CFG: PC6 (Bit 24)                             */
#define XBAR_PC_CFG_PC6_Msk               (0x7000000UL)             /*!< XBAR PC_CFG: PC6 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC5_Pos               (20UL)                    /*!< XBAR PC_CFG: PC5 (Bit 20)                             */
#define XBAR_PC_CFG_PC5_Msk               (0x700000UL)              /*!< XBAR PC_CFG: PC5 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC4_Pos               (16UL)                    /*!< XBAR PC_CFG: PC4 (Bit 16)                             */
#define XBAR_PC_CFG_PC4_Msk               (0x70000UL)               /*!< XBAR PC_CFG: PC4 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC3_Pos               (12UL)                    /*!< XBAR PC_CFG: PC3 (Bit 12)                             */
#define XBAR_PC_CFG_PC3_Msk               (0x7000UL)                /*!< XBAR PC_CFG: PC3 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC2_Pos               (8UL)                     /*!< XBAR PC_CFG: PC2 (Bit 8)                              */
#define XBAR_PC_CFG_PC2_Msk               (0x700UL)                 /*!< XBAR PC_CFG: PC2 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC1_Pos               (4UL)                     /*!< XBAR PC_CFG: PC1 (Bit 4)                              */
#define XBAR_PC_CFG_PC1_Msk               (0x70UL)                  /*!< XBAR PC_CFG: PC1 (Bitfield-Mask: 0x07)                */
#define XBAR_PC_CFG_PC0_Pos               (0UL)                     /*!< XBAR PC_CFG: PC0 (Bit 0)                              */
#define XBAR_PC_CFG_PC0_Msk               (0x7UL)                   /*!< XBAR PC_CFG: PC0 (Bitfield-Mask: 0x07)                */
/* ========================================================  PR_CFG  ========================================================= */
#define XBAR_PR_CFG_PR7_Pos               (28UL)                    /*!< XBAR PR_CFG: PR7 (Bit 28)                             */
#define XBAR_PR_CFG_PR7_Msk               (0x70000000UL)            /*!< XBAR PR_CFG: PR7 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR6_Pos               (24UL)                    /*!< XBAR PR_CFG: PR6 (Bit 24)                             */
#define XBAR_PR_CFG_PR6_Msk               (0x7000000UL)             /*!< XBAR PR_CFG: PR6 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR5_Pos               (20UL)                    /*!< XBAR PR_CFG: PR5 (Bit 20)                             */
#define XBAR_PR_CFG_PR5_Msk               (0x700000UL)              /*!< XBAR PR_CFG: PR5 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR4_Pos               (16UL)                    /*!< XBAR PR_CFG: PR4 (Bit 16)                             */
#define XBAR_PR_CFG_PR4_Msk               (0x70000UL)               /*!< XBAR PR_CFG: PR4 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR3_Pos               (12UL)                    /*!< XBAR PR_CFG: PR3 (Bit 12)                             */
#define XBAR_PR_CFG_PR3_Msk               (0x7000UL)                /*!< XBAR PR_CFG: PR3 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR2_Pos               (8UL)                     /*!< XBAR PR_CFG: PR2 (Bit 8)                              */
#define XBAR_PR_CFG_PR2_Msk               (0x700UL)                 /*!< XBAR PR_CFG: PR2 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR1_Pos               (4UL)                     /*!< XBAR PR_CFG: PR1 (Bit 4)                              */
#define XBAR_PR_CFG_PR1_Msk               (0x70UL)                  /*!< XBAR PR_CFG: PR1 (Bitfield-Mask: 0x07)                */
#define XBAR_PR_CFG_PR0_Pos               (0UL)                     /*!< XBAR PR_CFG: PR0 (Bit 0)                              */
#define XBAR_PR_CFG_PR0_Msk               (0x7UL)                   /*!< XBAR PR_CFG: PR0 (Bitfield-Mask: 0x07)                */
/* =====================================================  IN_UART0_CFG  ====================================================== */
#define XBAR_IN_UART0_CFG_CLK_Pos         (2UL)                     /*!< XBAR IN_UART0_CFG: CLK (Bit 2)                        */
#define XBAR_IN_UART0_CFG_CLK_Msk         (0xcUL)                   /*!< XBAR IN_UART0_CFG: CLK (Bitfield-Mask: 0x03)          */
#define XBAR_IN_UART0_CFG_RX_Pos          (0UL)                     /*!< XBAR IN_UART0_CFG: RX (Bit 0)                         */
#define XBAR_IN_UART0_CFG_RX_Msk          (0x3UL)                   /*!< XBAR IN_UART0_CFG: RX (Bitfield-Mask: 0x03)           */
/* =====================================================  IN_UART1_CFG  ====================================================== */
#define XBAR_IN_UART1_CFG_CLK_Pos         (2UL)                     /*!< XBAR IN_UART1_CFG: CLK (Bit 2)                        */
#define XBAR_IN_UART1_CFG_CLK_Msk         (0xcUL)                   /*!< XBAR IN_UART1_CFG: CLK (Bitfield-Mask: 0x03)          */
#define XBAR_IN_UART1_CFG_RX_Pos          (0UL)                     /*!< XBAR IN_UART1_CFG: RX (Bit 0)                         */
#define XBAR_IN_UART1_CFG_RX_Msk          (0x3UL)                   /*!< XBAR IN_UART1_CFG: RX (Bitfield-Mask: 0x03)           */
/* ======================================================  IN_SPI1_CFG  ====================================================== */
#define XBAR_IN_SPI1_CFG_IN_Pos            (0UL)                    /*!< XBAR IN_SPI1_CFG: IN (Bit 0)                          */
#define XBAR_IN_SPI1_CFG_IN_Msk            (0x7UL)                  /*!< XBAR IN_SPI1_CFG: IN (Bitfield-Mask: 0x07)            */
/* ======================================================  IN_SPI0_CFG  ====================================================== */
#define XBAR_IN_SPI0_CFG_IN_Pos            (0UL)                    /*!< XBAR IN_SPI0_CFG: IN (Bit 0)                          */
#define XBAR_IN_SPI0_CFG_IN_Msk            (0x3UL)                  /*!< XBAR IN_SPI0_CFG: IN (Bitfield-Mask: 0x07)            */
/* ======================================================  IN_DMA_CFG  ======================================================= */
#define XBAR_IN_DMA_CFG_CH2_TRIG_TYP_Pos  (21UL)                    /*!< XBAR IN_DMA_CFG: CH2_TRIG_TYP (Bit 21)                */
#define XBAR_IN_DMA_CFG_CH2_TRIG_TYP_Msk  (0x200000UL)              /*!< XBAR IN_DMA_CFG: CH2_TRIG_TYP (Bitfield-Mask: 0x01)   */
#define XBAR_IN_DMA_CFG_CH2_TRIG_SEL_Pos  (16UL)                    /*!< XBAR IN_DMA_CFG: CH2_TRIG_SEL (Bit 16)                */
#define XBAR_IN_DMA_CFG_CH2_TRIG_SEL_Msk  (0x1f0000UL)              /*!< XBAR IN_DMA_CFG: CH2_TRIG_SEL (Bitfield-Mask: 0x1f)   */
#define XBAR_IN_DMA_CFG_CH1_TRIG_TYP_Pos  (13UL)                    /*!< XBAR IN_DMA_CFG: CH1_TRIG_TYP (Bit 13)                */
#define XBAR_IN_DMA_CFG_CH1_TRIG_TYP_Msk  (0x2000UL)                /*!< XBAR IN_DMA_CFG: CH1_TRIG_TYP (Bitfield-Mask: 0x01)   */
#define XBAR_IN_DMA_CFG_CH1_TRIG_SEL_Pos  (8UL)                     /*!< XBAR IN_DMA_CFG: CH1_TRIG_SEL (Bit 8)                 */
#define XBAR_IN_DMA_CFG_CH1_TRIG_SEL_Msk  (0x1f00UL)                /*!< XBAR IN_DMA_CFG: CH1_TRIG_SEL (Bitfield-Mask: 0x1f)   */
#define XBAR_IN_DMA_CFG_CH0_TRIG_TYP_Pos  (5UL)                     /*!< XBAR IN_DMA_CFG: CH0_TRIG_TYP (Bit 5)                 */
#define XBAR_IN_DMA_CFG_CH0_TRIG_TYP_Msk  (0x20UL)                  /*!< XBAR IN_DMA_CFG: CH0_TRIG_TYP (Bitfield-Mask: 0x01)   */
#define XBAR_IN_DMA_CFG_CH0_TRIG_SEL_Pos  (0UL)                     /*!< XBAR IN_DMA_CFG: CH0_TRIG_SEL (Bit 0)                 */
#define XBAR_IN_DMA_CFG_CH0_TRIG_SEL_Msk  (0x1fUL)                  /*!< XBAR IN_DMA_CFG: CH0_TRIG_SEL (Bitfield-Mask: 0x1f)   */
/* ======================================================  IN_ADC_CFG  ======================================================= */
#define XBAR_IN_ADC_CFG_TRIG_TYP_Pos      (16UL)                    /*!< XBAR IN_ADC_CFG: TRIG_TYP (Bit 16)                    */
#define XBAR_IN_ADC_CFG_TRIG_TYP_Msk      (0x10000UL)               /*!< XBAR IN_ADC_CFG: TRIG_TYP (Bitfield-Mask: 0x01)       */
#define XBAR_IN_ADC_CFG_PIN_SEL_Pos       (8UL)                     /*!< XBAR IN_ADC_CFG: PIN_SEL (Bit 8)                      */
#define XBAR_IN_ADC_CFG_PIN_SEL_Msk       (0x700UL)                 /*!< XBAR IN_ADC_CFG: PIN_SEL (Bitfield-Mask: 0x07)        */
#define XBAR_IN_ADC_CFG_TIM_SEL_Pos       (0UL)                     /*!< XBAR IN_ADC_CFG: TIM_SEL (Bit 0)                      */
#define XBAR_IN_ADC_CFG_TIM_SEL_Msk       (0x7UL)                   /*!< XBAR IN_ADC_CFG: TIM_SEL (Bitfield-Mask: 0x07)        */
/* ======================================================  IN_TIM0_CFG  ====================================================== */
#define XBAR_IN_TIM0_CFG_SEL_Pos          (0UL)                     /*!< XBAR IN_TIM0_CFG: SEL (Bit 0)                         */
#define XBAR_IN_TIM0_CFG_SEL_Msk          (0x7UL)                   /*!< XBAR IN_TIM0_CFG: SEL (Bitfield-Mask: 0x07)           */
/* ======================================================  IN_TIM1_CFG  ====================================================== */
#define XBAR_IN_TIM1_CFG_SEL_Pos          (0UL)                     /*!< XBAR IN_TIM1_CFG: SEL (Bit 0)                         */
#define XBAR_IN_TIM1_CFG_SEL_Msk          (0x3UL)                   /*!< XBAR IN_TIM1_CFG: SEL (Bitfield-Mask: 0x03)           */
/* ======================================================  IN_TIM2_CFG  ====================================================== */
#define XBAR_IN_TIM2_CFG_SEL_Pos          (0UL)                     /*!< XBAR IN_TIM2_CFG: SEL (Bit 0)                         */
#define XBAR_IN_TIM2_CFG_SEL_Msk          (0x3UL)                   /*!< XBAR IN_TIM2_CFG: SEL (Bitfield-Mask: 0x03)           */
/* =====================================================  IN_CAPT0_CFG  ====================================================== */
#define XBAR_IN_CAPT0_CFG_SEL_Pos         (0UL)                     /*!< XBAR IN_CAPT0_CFG: SEL (Bit 0)                        */
#define XBAR_IN_CAPT0_CFG_SEL_Msk         (0x3UL)                   /*!< XBAR IN_CAPT0_CFG: SEL (Bitfield-Mask: 0x03)          */
/* =====================================================  IN_CAPT1_CFG  ====================================================== */
#define XBAR_IN_CAPT1_CFG_SEL_Pos         (0UL)                     /*!< XBAR IN_CAPT1_CFG: SEL (Bit 0)                        */
#define XBAR_IN_CAPT1_CFG_SEL_Msk         (0x3UL)                   /*!< XBAR IN_CAPT1_CFG: SEL (Bitfield-Mask: 0x03)          */
/* =====================================================  IN_CAPT2_CFG  ====================================================== */
#define XBAR_IN_CAPT2_CFG_SEL_Pos         (0UL)                     /*!< XBAR IN_CAPT2_CFG: SEL (Bit 0)                        */
#define XBAR_IN_CAPT2_CFG_SEL_Msk         (0x3UL)                   /*!< XBAR IN_CAPT2_CFG: SEL (Bitfield-Mask: 0x03)          */
/* =====================================================  IN_CAPT3_CFG  ====================================================== */
#define XBAR_IN_CAPT3_CFG_SEL_Pos         (0UL)                     /*!< XBAR IN_CAPT3_CFG: SEL (Bit 0)                        */
#define XBAR_IN_CAPT3_CFG_SEL_Msk         (0x3UL)                   /*!< XBAR IN_CAPT3_CFG: SEL (Bitfield-Mask: 0x03)          */
/* ====================================================  IN_EXT_CLK_CFG  ===================================================== */
#define XBAR_IN_EXT_CLK_CFG_SEL_Pos       (0UL)                     /*!< XBAR IN_EXT_CLK_CFG: SEL (Bit 0)                      */
#define XBAR_IN_EXT_CLK_CFG_SEL_Msk       (0x3UL)                   /*!< XBAR IN_EXT_CLK_CFG: SEL (Bitfield-Mask: 0x03)        */
/* =======================================================  TEST_CFG  ======================================================== */
#define XBAR_TEST_CFG_PR7_Pos             (31UL)                    /*!< XBAR TEST_CFG: PR7 (Bit 31)                           */
#define XBAR_TEST_CFG_PR7_Msk             (0x80000000UL)            /*!< XBAR TEST_CFG: PR7 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR6_Pos             (30UL)                    /*!< XBAR TEST_CFG: PR6 (Bit 30)                           */
#define XBAR_TEST_CFG_PR6_Msk             (0x40000000UL)            /*!< XBAR TEST_CFG: PR6 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR5_Pos             (29UL)                    /*!< XBAR TEST_CFG: PR5 (Bit 29)                           */
#define XBAR_TEST_CFG_PR5_Msk             (0x20000000UL)            /*!< XBAR TEST_CFG: PR5 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR4_Pos             (28UL)                    /*!< XBAR TEST_CFG: PR4 (Bit 28)                           */
#define XBAR_TEST_CFG_PR4_Msk             (0x10000000UL)            /*!< XBAR TEST_CFG: PR4 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR3_Pos             (27UL)                    /*!< XBAR TEST_CFG: PR3 (Bit 27)                           */
#define XBAR_TEST_CFG_PR3_Msk             (0x8000000UL)             /*!< XBAR TEST_CFG: PR3 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR2_Pos             (26UL)                    /*!< XBAR TEST_CFG: PR2 (Bit 26)                           */
#define XBAR_TEST_CFG_PR2_Msk             (0x4000000UL)             /*!< XBAR TEST_CFG: PR2 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR1_Pos             (25UL)                    /*!< XBAR TEST_CFG: PR1 (Bit 25)                           */
#define XBAR_TEST_CFG_PR1_Msk             (0x2000000UL)             /*!< XBAR TEST_CFG: PR1 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PR0_Pos             (24UL)                    /*!< XBAR TEST_CFG: PR0 (Bit 24)                           */
#define XBAR_TEST_CFG_PR0_Msk             (0x1000000UL)             /*!< XBAR TEST_CFG: PR0 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC7_Pos             (23UL)                    /*!< XBAR TEST_CFG: PC7 (Bit 23)                           */
#define XBAR_TEST_CFG_PC7_Msk             (0x800000UL)              /*!< XBAR TEST_CFG: PC7 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC6_Pos             (22UL)                    /*!< XBAR TEST_CFG: PC6 (Bit 22)                           */
#define XBAR_TEST_CFG_PC6_Msk             (0x400000UL)              /*!< XBAR TEST_CFG: PC6 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC5_Pos             (21UL)                    /*!< XBAR TEST_CFG: PC5 (Bit 21)                           */
#define XBAR_TEST_CFG_PC5_Msk             (0x200000UL)              /*!< XBAR TEST_CFG: PC5 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC4_Pos             (20UL)                    /*!< XBAR TEST_CFG: PC4 (Bit 20)                           */
#define XBAR_TEST_CFG_PC4_Msk             (0x100000UL)              /*!< XBAR TEST_CFG: PC4 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC3_Pos             (19UL)                    /*!< XBAR TEST_CFG: PC3 (Bit 19)                           */
#define XBAR_TEST_CFG_PC3_Msk             (0x80000UL)               /*!< XBAR TEST_CFG: PC3 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC2_Pos             (18UL)                    /*!< XBAR TEST_CFG: PC2 (Bit 18)                           */
#define XBAR_TEST_CFG_PC2_Msk             (0x40000UL)               /*!< XBAR TEST_CFG: PC2 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC1_Pos             (17UL)                    /*!< XBAR TEST_CFG: PC1 (Bit 17)                           */
#define XBAR_TEST_CFG_PC1_Msk             (0x20000UL)               /*!< XBAR TEST_CFG: PC1 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PC0_Pos             (16UL)                    /*!< XBAR TEST_CFG: PC0 (Bit 16)                           */
#define XBAR_TEST_CFG_PC0_Msk             (0x10000UL)               /*!< XBAR TEST_CFG: PC0 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB7_Pos             (15UL)                    /*!< XBAR TEST_CFG: PB7 (Bit 15)                           */
#define XBAR_TEST_CFG_PB7_Msk             (0x8000UL)                /*!< XBAR TEST_CFG: PB7 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB6_Pos             (14UL)                    /*!< XBAR TEST_CFG: PB6 (Bit 14)                           */
#define XBAR_TEST_CFG_PB6_Msk             (0x4000UL)                /*!< XBAR TEST_CFG: PB6 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB5_Pos             (13UL)                    /*!< XBAR TEST_CFG: PB5 (Bit 13)                           */
#define XBAR_TEST_CFG_PB5_Msk             (0x2000UL)                /*!< XBAR TEST_CFG: PB5 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB4_Pos             (12UL)                    /*!< XBAR TEST_CFG: PB4 (Bit 12)                           */
#define XBAR_TEST_CFG_PB4_Msk             (0x1000UL)                /*!< XBAR TEST_CFG: PB4 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB3_Pos             (11UL)                    /*!< XBAR TEST_CFG: PB3 (Bit 11)                           */
#define XBAR_TEST_CFG_PB3_Msk             (0x800UL)                 /*!< XBAR TEST_CFG: PB3 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB2_Pos             (10UL)                    /*!< XBAR TEST_CFG: PB2 (Bit 10)                           */
#define XBAR_TEST_CFG_PB2_Msk             (0x400UL)                 /*!< XBAR TEST_CFG: PB2 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB1_Pos             (9UL)                     /*!< XBAR TEST_CFG: PB1 (Bit 9)                            */
#define XBAR_TEST_CFG_PB1_Msk             (0x200UL)                 /*!< XBAR TEST_CFG: PB1 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PB0_Pos             (8UL)                     /*!< XBAR TEST_CFG: PB0 (Bit 8)                            */
#define XBAR_TEST_CFG_PB0_Msk             (0x100UL)                 /*!< XBAR TEST_CFG: PB0 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA7_Pos             (7UL)                     /*!< XBAR TEST_CFG: PA7 (Bit 7)                            */
#define XBAR_TEST_CFG_PA7_Msk             (0x80UL)                  /*!< XBAR TEST_CFG: PA7 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA6_Pos             (6UL)                     /*!< XBAR TEST_CFG: PA6 (Bit 6)                            */
#define XBAR_TEST_CFG_PA6_Msk             (0x40UL)                  /*!< XBAR TEST_CFG: PA6 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA5_Pos             (5UL)                     /*!< XBAR TEST_CFG: PA5 (Bit 5)                            */
#define XBAR_TEST_CFG_PA5_Msk             (0x20UL)                  /*!< XBAR TEST_CFG: PA5 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA4_Pos             (4UL)                     /*!< XBAR TEST_CFG: PA4 (Bit 4)                            */
#define XBAR_TEST_CFG_PA4_Msk             (0x10UL)                  /*!< XBAR TEST_CFG: PA4 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA3_Pos             (3UL)                     /*!< XBAR TEST_CFG: PA3 (Bit 3)                            */
#define XBAR_TEST_CFG_PA3_Msk             (0x8UL)                   /*!< XBAR TEST_CFG: PA3 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA2_Pos             (2UL)                     /*!< XBAR TEST_CFG: PA2 (Bit 2)                            */
#define XBAR_TEST_CFG_PA2_Msk             (0x4UL)                   /*!< XBAR TEST_CFG: PA2 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA1_Pos             (1UL)                     /*!< XBAR TEST_CFG: PA1 (Bit 1)                            */
#define XBAR_TEST_CFG_PA1_Msk             (0x2UL)                   /*!< XBAR TEST_CFG: PA1 (Bitfield-Mask: 0x01)              */
#define XBAR_TEST_CFG_PA0_Pos             (0UL)                     /*!< XBAR TEST_CFG: PA0 (Bit 0)                            */
#define XBAR_TEST_CFG_PA0_Msk             (0x1UL)                   /*!< XBAR TEST_CFG: PA0 (Bitfield-Mask: 0x01)              */
/* ======================================================  IN_MTB_CFG  ======================================================= */
#define XBAR_IN_MTB_CFG_NIDEN_Pos         (2UL)                     /*!< XBAR IN_MTB_CFG: NIDEN (Bit 2)                        */
#define XBAR_IN_MTB_CFG_NIDEN_Msk         (0x4UL)                   /*!< XBAR IN_MTB_CFG: NIDEN (Bitfield-Mask: 0x01)          */
#define XBAR_IN_MTB_CFG_SEL_Pos           (0UL)                     /*!< XBAR IN_MTB_CFG: SEL (Bit 0)                          */
#define XBAR_IN_MTB_CFG_SEL_Msk           (0x3UL)                   /*!< XBAR IN_MTB_CFG: SEL (Bitfield-Mask: 0x03)            */


/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  RESULT  ========================================================= */
/* =========================================================  INPUT  ========================================================= */


/* =========================================================================================================================== */
/* ================                                            DMA                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  STS  ========================================================== */
#define DMA_STS_TEST_Pos                  (28UL)                    /*!< DMA STS: TEST (Bit 28)                                */
#define DMA_STS_TEST_Msk                  (0xf0000000UL)            /*!< DMA STS: TEST (Bitfield-Mask: 0x0f)                   */
#define DMA_STS_CH_NUM_Pos                (16UL)                    /*!< DMA STS: CH_NUM (Bit 16)                              */
#define DMA_STS_CH_NUM_Msk                (0x1f0000UL)              /*!< DMA STS: CH_NUM (Bitfield-Mask: 0x1f)                 */
#define DMA_STS_STATE_Pos                 (4UL)                     /*!< DMA STS: STATE (Bit 4)                                */
#define DMA_STS_STATE_Msk                 (0xf0UL)                  /*!< DMA STS: STATE (Bitfield-Mask: 0x0f)                  */
#define DMA_STS_EN_Pos                    (0UL)                     /*!< DMA STS: EN (Bit 0)                                   */
#define DMA_STS_EN_Msk                    (0x1UL)                   /*!< DMA STS: EN (Bitfield-Mask: 0x01)                     */
/* ==========================================================  CFG  ========================================================== */
#define DMA_CFG_CH_PROT_CTL_Pos           (5UL)                     /*!< DMA CFG: CH_PROT_CTL (Bit 5)                          */
#define DMA_CFG_CH_PROT_CTL_Msk           (0xe0UL)                  /*!< DMA CFG: CH_PROT_CTL (Bitfield-Mask: 0x07)            */
#define DMA_CFG_EN_Pos                    (0UL)                     /*!< DMA CFG: EN (Bit 0)                                   */
#define DMA_CFG_EN_Msk                    (0x1UL)                   /*!< DMA CFG: EN (Bitfield-Mask: 0x01)                     */
/* =====================================================  CTL_BASE_PTR  ====================================================== */
/* ===================================================  ALT_CTL_BASE_PTR  ==================================================== */
/* ====================================================  WAIT_ON_REQ_STS  ==================================================== */
#define DMA_WAIT_ON_REQ_STS_CH2_Pos       (2UL)                     /*!< DMA WAIT_ON_REQ_STS: CH2 (Bit 2)                      */
#define DMA_WAIT_ON_REQ_STS_CH2_Msk       (0x4UL)                   /*!< DMA WAIT_ON_REQ_STS: CH2 (Bitfield-Mask: 0x01)        */
#define DMA_WAIT_ON_REQ_STS_CH1_Pos       (1UL)                     /*!< DMA WAIT_ON_REQ_STS: CH1 (Bit 1)                      */
#define DMA_WAIT_ON_REQ_STS_CH1_Msk       (0x2UL)                   /*!< DMA WAIT_ON_REQ_STS: CH1 (Bitfield-Mask: 0x01)        */
#define DMA_WAIT_ON_REQ_STS_CH0_Pos       (0UL)                     /*!< DMA WAIT_ON_REQ_STS: CH0 (Bit 0)                      */
#define DMA_WAIT_ON_REQ_STS_CH0_Msk       (0x1UL)                   /*!< DMA WAIT_ON_REQ_STS: CH0 (Bitfield-Mask: 0x01)        */
/* ========================================================  SW_REQ  ========================================================= */
#define DMA_SW_REQ_CH2_Pos                (2UL)                     /*!< DMA SW_REQ: CH2 (Bit 2)                               */
#define DMA_SW_REQ_CH2_Msk                (0x4UL)                   /*!< DMA SW_REQ: CH2 (Bitfield-Mask: 0x01)                 */
#define DMA_SW_REQ_CH1_Pos                (1UL)                     /*!< DMA SW_REQ: CH1 (Bit 1)                               */
#define DMA_SW_REQ_CH1_Msk                (0x2UL)                   /*!< DMA SW_REQ: CH1 (Bitfield-Mask: 0x01)                 */
#define DMA_SW_REQ_CH0_Pos                (0UL)                     /*!< DMA SW_REQ: CH0 (Bit 0)                               */
#define DMA_SW_REQ_CH0_Msk                (0x1UL)                   /*!< DMA SW_REQ: CH0 (Bitfield-Mask: 0x01)                 */
/* =====================================================  USE_BURST_SET  ===================================================== */
#define DMA_USE_BURST_SET_CH2_Pos         (2UL)                     /*!< DMA USE_BURST_SET: CH2 (Bit 2)                        */
#define DMA_USE_BURST_SET_CH2_Msk         (0x4UL)                   /*!< DMA USE_BURST_SET: CH2 (Bitfield-Mask: 0x01)          */
#define DMA_USE_BURST_SET_CH1_Pos         (1UL)                     /*!< DMA USE_BURST_SET: CH1 (Bit 1)                        */
#define DMA_USE_BURST_SET_CH1_Msk         (0x2UL)                   /*!< DMA USE_BURST_SET: CH1 (Bitfield-Mask: 0x01)          */
#define DMA_USE_BURST_SET_CH0_Pos         (0UL)                     /*!< DMA USE_BURST_SET: CH0 (Bit 0)                        */
#define DMA_USE_BURST_SET_CH0_Msk         (0x1UL)                   /*!< DMA USE_BURST_SET: CH0 (Bitfield-Mask: 0x01)          */
/* =====================================================  USE_BURST_CLR  ===================================================== */
#define DMA_USE_BURST_CLR_CH2_Pos         (2UL)                     /*!< DMA USE_BURST_CLR: CH2 (Bit 2)                        */
#define DMA_USE_BURST_CLR_CH2_Msk         (0x4UL)                   /*!< DMA USE_BURST_CLR: CH2 (Bitfield-Mask: 0x01)          */
#define DMA_USE_BURST_CLR_CH1_Pos         (1UL)                     /*!< DMA USE_BURST_CLR: CH1 (Bit 1)                        */
#define DMA_USE_BURST_CLR_CH1_Msk         (0x2UL)                   /*!< DMA USE_BURST_CLR: CH1 (Bitfield-Mask: 0x01)          */
#define DMA_USE_BURST_CLR_CH0_Pos         (0UL)                     /*!< DMA USE_BURST_CLR: CH0 (Bit 0)                        */
#define DMA_USE_BURST_CLR_CH0_Msk         (0x1UL)                   /*!< DMA USE_BURST_CLR: CH0 (Bitfield-Mask: 0x01)          */
/* =====================================================  REQ_MASK_SET  ====================================================== */
#define DMA_REQ_MASK_SET_CH2_Pos          (2UL)                     /*!< DMA REQ_MASK_SET: CH2 (Bit 2)                         */
#define DMA_REQ_MASK_SET_CH2_Msk          (0x4UL)                   /*!< DMA REQ_MASK_SET: CH2 (Bitfield-Mask: 0x01)           */
#define DMA_REQ_MASK_SET_CH1_Pos          (1UL)                     /*!< DMA REQ_MASK_SET: CH1 (Bit 1)                         */
#define DMA_REQ_MASK_SET_CH1_Msk          (0x2UL)                   /*!< DMA REQ_MASK_SET: CH1 (Bitfield-Mask: 0x01)           */
#define DMA_REQ_MASK_SET_CH0_Pos          (0UL)                     /*!< DMA REQ_MASK_SET: CH0 (Bit 0)                         */
#define DMA_REQ_MASK_SET_CH0_Msk          (0x1UL)                   /*!< DMA REQ_MASK_SET: CH0 (Bitfield-Mask: 0x01)           */
/* =====================================================  REQ_MASK_CLR  ====================================================== */
#define DMA_REQ_MASK_CLR_CH2_Pos          (2UL)                     /*!< DMA REQ_MASK_CLR: CH2 (Bit 2)                         */
#define DMA_REQ_MASK_CLR_CH2_Msk          (0x4UL)                   /*!< DMA REQ_MASK_CLR: CH2 (Bitfield-Mask: 0x01)           */
#define DMA_REQ_MASK_CLR_CH1_Pos          (1UL)                     /*!< DMA REQ_MASK_CLR: CH1 (Bit 1)                         */
#define DMA_REQ_MASK_CLR_CH1_Msk          (0x2UL)                   /*!< DMA REQ_MASK_CLR: CH1 (Bitfield-Mask: 0x01)           */
#define DMA_REQ_MASK_CLR_CH0_Pos          (0UL)                     /*!< DMA REQ_MASK_CLR: CH0 (Bit 0)                         */
#define DMA_REQ_MASK_CLR_CH0_Msk          (0x1UL)                   /*!< DMA REQ_MASK_CLR: CH0 (Bitfield-Mask: 0x01)           */
/* ========================================================  EN_SET  ========================================================= */
#define DMA_EN_SET_CH2_Pos                (2UL)                     /*!< DMA EN_SET: CH2 (Bit 2)                               */
#define DMA_EN_SET_CH2_Msk                (0x4UL)                   /*!< DMA EN_SET: CH2 (Bitfield-Mask: 0x01)                 */
#define DMA_EN_SET_CH1_Pos                (1UL)                     /*!< DMA EN_SET: CH1 (Bit 1)                               */
#define DMA_EN_SET_CH1_Msk                (0x2UL)                   /*!< DMA EN_SET: CH1 (Bitfield-Mask: 0x01)                 */
#define DMA_EN_SET_CH0_Pos                (0UL)                     /*!< DMA EN_SET: CH0 (Bit 0)                               */
#define DMA_EN_SET_CH0_Msk                (0x1UL)                   /*!< DMA EN_SET: CH0 (Bitfield-Mask: 0x01)                 */
/* ========================================================  EN_CLR  ========================================================= */
#define DMA_EN_CLR_CH2_Pos                (2UL)                     /*!< DMA EN_CLR: CH2 (Bit 2)                               */
#define DMA_EN_CLR_CH2_Msk                (0x4UL)                   /*!< DMA EN_CLR: CH2 (Bitfield-Mask: 0x01)                 */
#define DMA_EN_CLR_CH1_Pos                (1UL)                     /*!< DMA EN_CLR: CH1 (Bit 1)                               */
#define DMA_EN_CLR_CH1_Msk                (0x2UL)                   /*!< DMA EN_CLR: CH1 (Bitfield-Mask: 0x01)                 */
#define DMA_EN_CLR_CH0_Pos                (0UL)                     /*!< DMA EN_CLR: CH0 (Bit 0)                               */
#define DMA_EN_CLR_CH0_Msk                (0x1UL)                   /*!< DMA EN_CLR: CH0 (Bitfield-Mask: 0x01)                 */
/* ====================================================  PRI_ALT_SEL_SET  ==================================================== */
#define DMA_PRI_ALT_SEL_SET_CH2_Pos       (2UL)                     /*!< DMA PRI_ALT_SEL_SET: CH2 (Bit 2)                      */
#define DMA_PRI_ALT_SEL_SET_CH2_Msk       (0x4UL)                   /*!< DMA PRI_ALT_SEL_SET: CH2 (Bitfield-Mask: 0x01)        */
#define DMA_PRI_ALT_SEL_SET_CH1_Pos       (1UL)                     /*!< DMA PRI_ALT_SEL_SET: CH1 (Bit 1)                      */
#define DMA_PRI_ALT_SEL_SET_CH1_Msk       (0x2UL)                   /*!< DMA PRI_ALT_SEL_SET: CH1 (Bitfield-Mask: 0x01)        */
#define DMA_PRI_ALT_SEL_SET_CH0_Pos       (0UL)                     /*!< DMA PRI_ALT_SEL_SET: CH0 (Bit 0)                      */
#define DMA_PRI_ALT_SEL_SET_CH0_Msk       (0x1UL)                   /*!< DMA PRI_ALT_SEL_SET: CH0 (Bitfield-Mask: 0x01)        */
/* ====================================================  PRI_ALT_SEL_CLR  ==================================================== */
#define DMA_PRI_ALT_SEL_CLR_CH2_Pos       (2UL)                     /*!< DMA PRI_ALT_SEL_CLR: CH2 (Bit 2)                      */
#define DMA_PRI_ALT_SEL_CLR_CH2_Msk       (0x4UL)                   /*!< DMA PRI_ALT_SEL_CLR: CH2 (Bitfield-Mask: 0x01)        */
#define DMA_PRI_ALT_SEL_CLR_CH1_Pos       (1UL)                     /*!< DMA PRI_ALT_SEL_CLR: CH1 (Bit 1)                      */
#define DMA_PRI_ALT_SEL_CLR_CH1_Msk       (0x2UL)                   /*!< DMA PRI_ALT_SEL_CLR: CH1 (Bitfield-Mask: 0x01)        */
#define DMA_PRI_ALT_SEL_CLR_CH0_Pos       (0UL)                     /*!< DMA PRI_ALT_SEL_CLR: CH0 (Bit 0)                      */
#define DMA_PRI_ALT_SEL_CLR_CH0_Msk       (0x1UL)                   /*!< DMA PRI_ALT_SEL_CLR: CH0 (Bitfield-Mask: 0x01)        */
/* =======================================================  PRIO_SET  ======================================================== */
#define DMA_PRIO_SET_CH2_Pos              (2UL)                     /*!< DMA PRIO_SET: CH2 (Bit 2)                             */
#define DMA_PRIO_SET_CH2_Msk              (0x4UL)                   /*!< DMA PRIO_SET: CH2 (Bitfield-Mask: 0x01)               */
#define DMA_PRIO_SET_CH1_Pos              (1UL)                     /*!< DMA PRIO_SET: CH1 (Bit 1)                             */
#define DMA_PRIO_SET_CH1_Msk              (0x2UL)                   /*!< DMA PRIO_SET: CH1 (Bitfield-Mask: 0x01)               */
#define DMA_PRIO_SET_CH0_Pos              (0UL)                     /*!< DMA PRIO_SET: CH0 (Bit 0)                             */
#define DMA_PRIO_SET_CH0_Msk              (0x1UL)                   /*!< DMA PRIO_SET: CH0 (Bitfield-Mask: 0x01)               */
/* =======================================================  PRIO_CLR  ======================================================== */
#define DMA_PRIO_CLR_CH2_Pos              (2UL)                     /*!< DMA PRIO_CLR: CH2 (Bit 2)                             */
#define DMA_PRIO_CLR_CH2_Msk              (0x4UL)                   /*!< DMA PRIO_CLR: CH2 (Bitfield-Mask: 0x01)               */
#define DMA_PRIO_CLR_CH1_Pos              (1UL)                     /*!< DMA PRIO_CLR: CH1 (Bit 1)                             */
#define DMA_PRIO_CLR_CH1_Msk              (0x2UL)                   /*!< DMA PRIO_CLR: CH1 (Bitfield-Mask: 0x01)               */
#define DMA_PRIO_CLR_CH0_Pos              (0UL)                     /*!< DMA PRIO_CLR: CH0 (Bit 0)                             */
#define DMA_PRIO_CLR_CH0_Msk              (0x1UL)                   /*!< DMA PRIO_CLR: CH0 (Bitfield-Mask: 0x01)               */
/* ========================================================  ERR_CLR  ======================================================== */
/* ========================================================  INT_EN  ========================================================= */
#define DMA_INT_EN_ERR_Pos                (3UL)                     /*!< DMA INT_EN: ERR (Bit 3)                               */
#define DMA_INT_EN_ERR_Msk                (0x8UL)                   /*!< DMA INT_EN: ERR (Bitfield-Mask: 0x01)                 */
#define DMA_INT_EN_CH2_Pos                (2UL)                     /*!< DMA INT_EN: CH2 (Bit 2)                               */
#define DMA_INT_EN_CH2_Msk                (0x4UL)                   /*!< DMA INT_EN: CH2 (Bitfield-Mask: 0x01)                 */
#define DMA_INT_EN_CH1_Pos                (1UL)                     /*!< DMA INT_EN: CH1 (Bit 1)                               */
#define DMA_INT_EN_CH1_Msk                (0x2UL)                   /*!< DMA INT_EN: CH1 (Bitfield-Mask: 0x01)                 */
#define DMA_INT_EN_CH0_Pos                (0UL)                     /*!< DMA INT_EN: CH0 (Bit 0)                               */
#define DMA_INT_EN_CH0_Msk                (0x1UL)                   /*!< DMA INT_EN: CH0 (Bitfield-Mask: 0x01)                 */
/* ========================================================  INT_STS  ======================================================== */
#define DMA_INT_STS_ERR_Pos               (3UL)                     /*!< DMA INT_STS: ERR (Bit 3)                              */
#define DMA_INT_STS_ERR_Msk               (0x8UL)                   /*!< DMA INT_STS: ERR (Bitfield-Mask: 0x01)                */
#define DMA_INT_STS_CH2_Pos               (2UL)                     /*!< DMA INT_STS: CH2 (Bit 2)                              */
#define DMA_INT_STS_CH2_Msk               (0x4UL)                   /*!< DMA INT_STS: CH2 (Bitfield-Mask: 0x01)                */
#define DMA_INT_STS_CH1_Pos               (1UL)                     /*!< DMA INT_STS: CH1 (Bit 1)                              */
#define DMA_INT_STS_CH1_Msk               (0x2UL)                   /*!< DMA INT_STS: CH1 (Bitfield-Mask: 0x01)                */
#define DMA_INT_STS_CH0_Pos               (0UL)                     /*!< DMA INT_STS: CH0 (Bit 0)                              */
#define DMA_INT_STS_CH0_Msk               (0x1UL)                   /*!< DMA INT_STS: CH0 (Bitfield-Mask: 0x01)                */


/* =========================================================================================================================== */
/* ================                                           FLASH                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CTL  ========================================================== */
#define FLASH_CTL_KEY_Pos                 (16UL)                    /*!< FLASH CTL: KEY (Bit 16)                               */
#define FLASH_CTL_KEY_Msk                 (0xffff0000UL)            /*!< FLASH CTL: KEY (Bitfield-Mask: 0xffff)                */
#define FLASH_CTL_STATE_Pos               (3UL)                     /*!< FLASH CTL: STATE (Bit 3)                              */
#define FLASH_CTL_STATE_Msk               (0x8UL)                   /*!< FLASH CTL: STATE (Bitfield-Mask: 0x01)                */
#define FLASH_CTL_START_MASS_ERASE_Pos    (2UL)                     /*!< FLASH CTL: START_MASS_ERASE (Bit 2)                   */
#define FLASH_CTL_START_MASS_ERASE_Msk    (0x4UL)                   /*!< FLASH CTL: START_MASS_ERASE (Bitfield-Mask: 0x01)     */
#define FLASH_CTL_START_PAGE_ERASE_Pos    (1UL)                     /*!< FLASH CTL: START_PAGE_ERASE (Bit 1)                   */
#define FLASH_CTL_START_PAGE_ERASE_Msk    (0x2UL)                   /*!< FLASH CTL: START_PAGE_ERASE (Bitfield-Mask: 0x01)     */
#define FLASH_CTL_START_PROG_Pos          (0UL)                     /*!< FLASH CTL: START_PROG (Bit 0)                         */
#define FLASH_CTL_START_PROG_Msk          (0x1UL)                   /*!< FLASH CTL: START_PROG (Bitfield-Mask: 0x01)           */
/* =========================================================  ADDR  ========================================================== */
/* =======================================================  FLASHDATA  ======================================================= */
/* ========================================================  INT_EN  ========================================================= */
#define FLASH_INT_EN_PROTECT_Pos          (2UL)                     /*!< FLASH INT_EN: PROTECT (Bit 2)                         */
#define FLASH_INT_EN_PROTECT_Msk          (0x4UL)                   /*!< FLASH INT_EN: PROTECT (Bitfield-Mask: 0x01)           */
#define FLASH_INT_EN_ERASE_Pos            (1UL)                     /*!< FLASH INT_EN: ERASE (Bit 1)                           */
#define FLASH_INT_EN_ERASE_Msk            (0x2UL)                   /*!< FLASH INT_EN: ERASE (Bitfield-Mask: 0x01)             */
#define FLASH_INT_EN_PROG_Pos             (0UL)                     /*!< FLASH INT_EN: PROG (Bit 0)                            */
#define FLASH_INT_EN_PROG_Msk             (0x1UL)                   /*!< FLASH INT_EN: PROG (Bitfield-Mask: 0x01)              */
/* ========================================================  INT_STS  ======================================================== */
#define FLASH_INT_STS_PROTECT_Pos         (2UL)                     /*!< FLASH INT_STS: PROTECT (Bit 2)                        */
#define FLASH_INT_STS_PROTECT_Msk         (0x4UL)                   /*!< FLASH INT_STS: PROTECT (Bitfield-Mask: 0x01)          */
#define FLASH_INT_STS_ERASE_Pos           (1UL)                     /*!< FLASH INT_STS: ERASE (Bit 1)                          */
#define FLASH_INT_STS_ERASE_Msk           (0x2UL)                   /*!< FLASH INT_STS: ERASE (Bitfield-Mask: 0x01)            */
#define FLASH_INT_STS_PROG_Pos            (0UL)                     /*!< FLASH INT_STS: PROG (Bit 0)                           */
#define FLASH_INT_STS_PROG_Msk            (0x1UL)                   /*!< FLASH INT_STS: PROG (Bitfield-Mask: 0x01)             */
/* =======================================================  PROTECT0  ======================================================== */
/* =======================================================  PROTECT1  ======================================================== */
/* =======================================================  PROTECT2  ======================================================== */
/* =======================================================  PROTECT3  ======================================================== */
/* ========================================================  DMA_EN  ========================================================= */
#define FLASH_DMA_EN_ERASE_Pos            (1UL)                     /*!< FLASH DMA_EN: ERASE (Bit 1)                           */
#define FLASH_DMA_EN_ERASE_Msk            (0x2UL)                   /*!< FLASH DMA_EN: ERASE (Bitfield-Mask: 0x01)             */
#define FLASH_DMA_EN_PROG_Pos             (0UL)                     /*!< FLASH DMA_EN: PROG (Bit 0)                            */
#define FLASH_DMA_EN_PROG_Msk             (0x1UL)                   /*!< FLASH DMA_EN: PROG (Bitfield-Mask: 0x01)              */


/* =========================================================================================================================== */
/* ================                                           GPIO                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* =======================================================  DATA_OUT  ======================================================== */
/* ========================================================  OUT_EN  ========================================================= */
/* ========================================================  INT_EN  ========================================================= */
/* ========================================================  INT_POL  ======================================================== */
/* ========================================================  INT_TYP  ======================================================== */
/* ======================================================  DMA_TRIG_EN  ====================================================== */
/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                            I2C                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  CTL  ========================================================== */
#define I2C_CTL_RST_Pos                   (5UL)                     /*!< I2C CTL: RST (Bit 5)                                  */
#define I2C_CTL_RST_Msk                   (0x20UL)                  /*!< I2C CTL: RST (Bitfield-Mask: 0x01)                    */
#define I2C_CTL_LAST_DATA_Pos             (4UL)                     /*!< I2C CTL: LAST_DATA (Bit 4)                            */
#define I2C_CTL_LAST_DATA_Msk             (0x10UL)                  /*!< I2C CTL: LAST_DATA (Bitfield-Mask: 0x01)              */
#define I2C_CTL_STOP_Pos                  (3UL)                     /*!< I2C CTL: STOP (Bit 3)                                 */
#define I2C_CTL_STOP_Msk                  (0x8UL)                   /*!< I2C CTL: STOP (Bitfield-Mask: 0x01)                   */
#define I2C_CTL_NACK_Pos                  (1UL)                     /*!< I2C CTL: NACK (Bit 1)                                 */
#define I2C_CTL_NACK_Msk                  (0x2UL)                   /*!< I2C CTL: NACK (Bitfield-Mask: 0x01)                   */
#define I2C_CTL_ACK_Pos                   (0UL)                     /*!< I2C CTL: ACK (Bit 0)                                  */
#define I2C_CTL_ACK_Msk                   (0x1UL)                   /*!< I2C CTL: ACK (Bitfield-Mask: 0x01)                    */
/* =========================================================  DATA  ========================================================== */
/* ======================================================  DATA_MIRROR  ====================================================== */
/* ======================================================  ADDR_START  ======================================================= */
/* ==========================================================  STS  ========================================================== */
/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                            PMU                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  MOD  ========================================================== */
#define PMU_MOD_HIBERNATE_Pos             (0UL)                     /* PMU Hibernate mode */
#define PMU_MOD_HIBERNATE_Msk             (0x1UL)                   /* PMU mode bit 0 */
#define PMU_MOD_SHUTDOWN_Pos              (0x1UL)                   /* PMU shutdown mode */
#define PMU_MOD_SHUTDOWN_Msk              (0x2UL)                   /* PMU mode bit 1 */
#define PMU_MOD_PADLATCH_Pos              (0x2UL)                   /* PMU pad latch */
#define PMU_MOD_PADLATCH_Msk              (0x4UL)                   /* PMU mode bit 2 */
#define PMU_MOD_CM0LP_Msk                 (0UL)                     /* PMU mode determined by CM0+ LP registers */
/* ==========================================================  PD  =========================================================== */
#define PMU_PD_SRAM6K_Pos                 (1UL)                     /*!< PMU PD: SRAM6K (Bit 1)                                */
#define PMU_PD_SRAM6K_Msk                 (0x2UL)                   /*!< PMU PD: SRAM6K (Bitfield-Mask: 0x01)                  */
#define PMU_PD_SRAM2K_Pos                 (0UL)                     /*!< PMU PD: SRAM2K (Bit 0)                                */
#define PMU_PD_SRAM2K_Msk                 (0x1UL)                   /*!< PMU PD: SRAM2K (Bitfield-Mask: 0x01)                  */
/* ==========================================================  STS  ========================================================== */
#define PMU_STS_WU_Pos                    (1UL)                     /*!< PMU STS: WU (Bit 1)                                   */
#define PMU_STS_WU_Msk                    (0x2UL)                   /*!< PMU STS: WU (Bitfield-Mask: 0x01)                     */
#define PMU_STS_WDOG_Pos                  (0UL)                     /*!< PMU STS: WDOG (Bit 0)                                 */
#define PMU_STS_WDOG_Msk                  (0x1UL)                   /*!< PMU STS: WDOG (Bitfield-Mask: 0x01)                   */


/* =========================================================================================================================== */
/* ================                                            SPI                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */


/* =========================================================================================================================== */
/* ================                                          TICKER                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */
/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PER  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            TIM                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PER  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
#define TIM_CFG_INT_EN_PER_UNDER_Pos      (19UL)                    /*!< TIM CFG: INT_EN_PER_UNDER (Bit 19)                    */
#define TIM_CFG_INT_EN_PER_UNDER_Msk      (0x80000UL)               /*!< TIM CFG: INT_EN_PER_UNDER (Bitfield-Mask: 0x01)       */
#define TIM_CFG_INT_EN_PER_EMPTY_Pos      (18UL)                    /*!< TIM CFG: INT_EN_PER_EMPTY (Bit 18)                    */
#define TIM_CFG_INT_EN_PER_EMPTY_Msk      (0x40000UL)               /*!< TIM CFG: INT_EN_PER_EMPTY (Bitfield-Mask: 0x01)       */
#define TIM_CFG_INT_EN_UNDER_Pos          (17UL)                    /*!< TIM CFG: INT_EN_UNDER (Bit 17)                        */
#define TIM_CFG_INT_EN_UNDER_Msk          (0x20000UL)               /*!< TIM CFG: INT_EN_UNDER (Bitfield-Mask: 0x01)           */
#define TIM_CFG_INT_EN_OVER_Pos           (16UL)                    /*!< TIM CFG: INT_EN_OVER (Bit 16)                         */
#define TIM_CFG_INT_EN_OVER_Msk           (0x10000UL)               /*!< TIM CFG: INT_EN_OVER (Bitfield-Mask: 0x01)            */
#define TIM_CFG_CLK_SYNC_Pos              (15UL)                    /*!< TIM CFG: CLK_SYNC (Bit 15)                            */
#define TIM_CFG_CLK_SYNC_Msk              (0x8000UL)                /*!< TIM CFG: CLK_SYNC (Bitfield-Mask: 0x01)               */
#define TIM_CFG_CLK_INV_Pos               (14UL)                    /*!< TIM CFG: CLK_INV (Bit 14)                             */
#define TIM_CFG_CLK_INV_Msk               (0x4000UL)                /*!< TIM CFG: CLK_INV (Bitfield-Mask: 0x01)                */
#define TIM_CFG_CLK_DIV_Pos               (11UL)                    /*!< TIM CFG: CLK_DIV (Bit 11)                             */
#define TIM_CFG_CLK_DIV_Msk               (0x3800UL)                /*!< TIM CFG: CLK_DIV (Bitfield-Mask: 0x07)                */
#define TIM_CFG_CLK_SEL_Pos               (8UL)                     /*!< TIM CFG: CLK_SEL (Bit 8)                              */
#define TIM_CFG_CLK_SEL_Msk               (0x700UL)                 /*!< TIM CFG: CLK_SEL (Bitfield-Mask: 0x07)                */
#define TIM_CFG_PER_BUF_Pos               (4UL)                     /*!< TIM CFG: PER_BUF (Bit 4)                              */
#define TIM_CFG_PER_BUF_Msk               (0x30UL)                  /*!< TIM CFG: PER_BUF (Bitfield-Mask: 0x03)                */
#define TIM_CFG_MOD_Pos                   (0UL)                     /*!< TIM CFG: MOD (Bit 0)                                  */
#define TIM_CFG_MOD_Msk                   (0xfUL)                   /*!< TIM CFG: MOD (Bitfield-Mask: 0x0f)                    */
/* ========================================================  INT_STS  ======================================================== */
#define TIM_INT_STS_PER_UNDER_Pos         (5UL)                     /*!< TIM INT_STS: PER_UNDER (Bit 5)                        */
#define TIM_INT_STS_PER_UNDER_Msk         (0x20UL)                  /*!< TIM INT_STS: PER_UNDER (Bitfield-Mask: 0x01)          */
#define TIM_INT_STS_PER_EMPTY_Pos         (4UL)                     /*!< TIM INT_STS: PER_EMPTY (Bit 4)                        */
#define TIM_INT_STS_PER_EMPTY_Msk         (0x10UL)                  /*!< TIM INT_STS: PER_EMPTY (Bitfield-Mask: 0x01)          */
#define TIM_INT_STS_UNDER_MISSED_Pos      (3UL)                     /*!< TIM INT_STS: UNDER_MISSED (Bit 3)                     */
#define TIM_INT_STS_UNDER_MISSED_Msk      (0x8UL)                   /*!< TIM INT_STS: UNDER_MISSED (Bitfield-Mask: 0x01)       */
#define TIM_INT_STS_OVER_MISSED_Pos       (2UL)                     /*!< TIM INT_STS: OVER_MISSED (Bit 2)                      */
#define TIM_INT_STS_OVER_MISSED_Msk       (0x4UL)                   /*!< TIM INT_STS: OVER_MISSED (Bitfield-Mask: 0x01)        */
#define TIM_INT_STS_UNDER_Pos             (1UL)                     /*!< TIM INT_STS: UNDER (Bit 1)                            */
#define TIM_INT_STS_UNDER_Msk             (0x2UL)                   /*!< TIM INT_STS: UNDER (Bitfield-Mask: 0x01)              */
#define TIM_INT_STS_OVER_Pos              (0UL)                     /*!< TIM INT_STS: OVER (Bit 0)                             */
#define TIM_INT_STS_OVER_Msk              (0x1UL)                   /*!< TIM INT_STS: OVER (Bitfield-Mask: 0x01)               */


/* =========================================================================================================================== */
/* ================                                           TRNG                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* =========================================================  DATA  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           UART                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
#define UART_CFG_INT_EN_TX_IDLE_Pos       (16UL)                    /*!< UART CFG: INT_EN_TX_IDLE (Bit 16)                     */
#define UART_CFG_INT_EN_TX_IDLE_Msk       (0x10000UL)               /*!< UART CFG: INT_EN_TX_IDLE (Bitfield-Mask: 0x01)        */
#define UART_CFG_SYNC_Pos                 (15UL)                    /*!< UART CFG: SYNC (Bit 15)                               */
#define UART_CFG_SYNC_Msk                 (0x8000UL)                /*!< UART CFG: SYNC (Bitfield-Mask: 0x01)                  */
#define UART_CFG_MCE_Pos                  (14UL)                    /*!< UART CFG: MCE (Bit 14)                                */
#define UART_CFG_MCE_Msk                  (0x4000UL)                /*!< UART CFG: MCE (Bitfield-Mask: 0x01)                   */
#define UART_CFG_INT_EN_RX_BRK_Pos        (13UL)                    /*!< UART CFG: INT_EN_RX_BRK (Bit 13)                      */
#define UART_CFG_INT_EN_RX_BRK_Msk        (0x2000UL)                /*!< UART CFG: INT_EN_RX_BRK (Bitfield-Mask: 0x01)         */
#define UART_CFG_INT_EN_RX_FE_Pos         (12UL)                    /*!< UART CFG: INT_EN_RX_FE (Bit 12)                       */
#define UART_CFG_INT_EN_RX_FE_Msk         (0x1000UL)                /*!< UART CFG: INT_EN_RX_FE (Bitfield-Mask: 0x01)          */
#define UART_CFG_INT_EN_TX_Pos            (11UL)                    /*!< UART CFG: INT_EN_TX (Bit 11)                          */
#define UART_CFG_INT_EN_TX_Msk            (0x800UL)                 /*!< UART CFG: INT_EN_TX (Bitfield-Mask: 0x01)             */
#define UART_CFG_INT_EN_RX_Pos            (10UL)                    /*!< UART CFG: INT_EN_RX (Bit 10)                          */
#define UART_CFG_INT_EN_RX_Msk            (0x400UL)                 /*!< UART CFG: INT_EN_RX (Bitfield-Mask: 0x01)             */
#define UART_CFG_TX_EN_Pos                (9UL)                     /*!< UART CFG: TX_EN (Bit 9)                               */
#define UART_CFG_TX_EN_Msk                (0x200UL)                 /*!< UART CFG: TX_EN (Bitfield-Mask: 0x01)                 */
#define UART_CFG_RX_EN_Pos                (8UL)                     /*!< UART CFG: RX_EN (Bit 8)                               */
#define UART_CFG_RX_EN_Msk                (0x100UL)                 /*!< UART CFG: RX_EN (Bitfield-Mask: 0x01)                 */
#define UART_CFG_TX_BRK_EN_Pos            (7UL)                     /*!< UART CFG: TX_BRK_EN (Bit 7)                           */
#define UART_CFG_TX_BRK_EN_Msk            (0x80UL)                  /*!< UART CFG: TX_BRK_EN (Bitfield-Mask: 0x01)             */
#define UART_CFG_RX_DGL_EN_Pos            (6UL)                     /*!< UART CFG: RX_DGL_EN (Bit 6)                           */
#define UART_CFG_RX_DGL_EN_Msk            (0x40UL)                  /*!< UART CFG: RX_DGL_EN (Bitfield-Mask: 0x01)             */
#define UART_CFG_STOP_BITS_Pos            (5UL)                     /*!< UART CFG: STOP_BITS (Bit 5)                           */
#define UART_CFG_STOP_BITS_Msk            (0x20UL)                  /*!< UART CFG: STOP_BITS (Bitfield-Mask: 0x01)             */
#define UART_CFG_WORD_LEN_Pos             (2UL)                     /*!< UART CFG: WORD_LEN (Bit 2)                            */
#define UART_CFG_WORD_LEN_Msk             (0x1cUL)                  /*!< UART CFG: WORD_LEN (Bitfield-Mask: 0x07)              */
#define UART_CFG_BRG_Pos                  (0UL)                     /*!< UART CFG: BRG (Bit 0)                                 */
#define UART_CFG_BRG_Msk                  (0x3UL)                   /*!< UART CFG: BRG (Bitfield-Mask: 0x03)                   */
/* ==========================================================  STS  ========================================================== */
#define UART_STS_TX_IDLE_Pos              (6UL)                     /*!< UART STS: TX_IDLE (Bit 6)                             */
#define UART_STS_TX_IDLE_Msk              (0x40UL)                  /*!< UART STS: TX_IDLE (Bitfield-Mask: 0x01)               */
#define UART_STS_RX_BRK_Pos               (5UL)                     /*!< UART STS: RX_BRK (Bit 5)                              */
#define UART_STS_RX_BRK_Msk               (0x20UL)                  /*!< UART STS: RX_BRK (Bitfield-Mask: 0x01)                */
#define UART_STS_RX_FE_Pos                (4UL)                     /*!< UART STS: RX_FE (Bit 4)                               */
#define UART_STS_RX_FE_Msk                (0x10UL)                  /*!< UART STS: RX_FE (Bitfield-Mask: 0x01)                 */
#define UART_STS_TX_UNDER_Pos             (3UL)                     /*!< UART STS: TX_UNDER (Bit 3)                            */
#define UART_STS_TX_UNDER_Msk             (0x8UL)                   /*!< UART STS: TX_UNDER (Bitfield-Mask: 0x01)              */
#define UART_STS_TX_EMPTY_Pos             (2UL)                     /*!< UART STS: TX_EMPTY (Bit 2)                            */
#define UART_STS_TX_EMPTY_Msk             (0x4UL)                   /*!< UART STS: TX_EMPTY (Bitfield-Mask: 0x01)              */
#define UART_STS_RX_OVER_Pos              (1UL)                     /*!< UART STS: RX_OVER (Bit 1)                             */
#define UART_STS_RX_OVER_Msk              (0x2UL)                   /*!< UART STS: RX_OVER (Bitfield-Mask: 0x01)               */
#define UART_STS_RX_FULL_Pos              (0UL)                     /*!< UART STS: RX_FULL (Bit 0)                             */
#define UART_STS_RX_FULL_Msk              (0x1UL)                   /*!< UART STS: RX_FULL (Bitfield-Mask: 0x01)               */


/* =========================================================================================================================== */
/* ================                                            WUT                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */
/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PER  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           WDOG                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  LOAD  ========================================================== */
/* ==========================================================  VAL  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
#define WDOG_CFG_RST_EN_Pos               (1UL)                     /*!< WDOG CFG: RST_EN (Bit 1)                              */
#define WDOG_CFG_RST_EN_Msk               (0x2UL)                   /*!< WDOG CFG: RST_EN (Bitfield-Mask: 0x01)                */
#define WDOG_CFG_EN_Pos                   (0UL)                     /*!< WDOG CFG: EN (Bit 0)                                  */
#define WDOG_CFG_EN_Msk                   (0x1UL)                   /*!< WDOG CFG: EN (Bitfield-Mask: 0x01)                    */
/* ======================================================  INT_STS_RAW  ====================================================== */
/* ========================================================  INT_STS  ======================================================== */
/* =========================================================  LOCK  ========================================================== */
/* =======================================================  TEST_CFG  ======================================================== */
/* =======================================================  TEST_OUT  ======================================================== */
#define WDOG_TEST_OUT_INT_Pos             (1UL)                     /*!< WDOG TEST_OUT: INT (Bit 1)                            */
#define WDOG_TEST_OUT_INT_Msk             (0x2UL)                   /*!< WDOG TEST_OUT: INT (Bitfield-Mask: 0x01)              */
#define WDOG_TEST_OUT_RST_Pos             (0UL)                     /*!< WDOG TEST_OUT: RST (Bit 0)                            */
#define WDOG_TEST_OUT_RST_Msk             (0x1UL)                   /*!< WDOG TEST_OUT: RST (Bitfield-Mask: 0x01)              */


/* =========================================================================================================================== */
/* ================                                           MISC                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  SCRATCH  ======================================================== */
/* =========================================================  TRIM  ========================================================== */
/* ========================================================  REV_ID  ========================================================= */
/* =========================================================  LOCK  ========================================================== */
#define TEST_LOCK_OVER_Pos                (1UL)                     /*!< TEST LOCK: OVER (Bit 1)                               */
#define TEST_LOCK_OVER_Msk                (0x2UL)                   /*!< TEST LOCK: OVER (Bitfield-Mask: 0x01)                 */
#define TEST_LOCK_STS_Pos                 (0UL)                     /*!< TEST LOCK: STS (Bit 0)                                */
#define TEST_LOCK_STS_Msk                 (0x1UL)                   /*!< TEST LOCK: STS (Bitfield-Mask: 0x01)                  */


/* =========================================================================================================================== */
/* ================                                            MTB                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  POSITION  ======================================================== */
#define MTB_POSITION_POINTER_Pos          (3UL)                     /*!< MTB POSITION: POINTER (Bit 3)                         */
#define MTB_POSITION_POINTER_Msk          (0xfffffff8UL)            /*!< MTB POSITION: POINTER (Bitfield-Mask: 0x1fffffff)     */
#define MTB_POSITION_WRAP_Pos             (2UL)                     /*!< MTB POSITION: WRAP (Bit 2)                            */
#define MTB_POSITION_WRAP_Msk             (0x4UL)                   /*!< MTB POSITION: WRAP (Bitfield-Mask: 0x01)              */
/* ========================================================  MASTER  ========================================================= */
#define MTB_MASTER_EN_Pos                 (31UL)                    /*!< MTB MASTER: EN (Bit 31)                               */
#define MTB_MASTER_EN_Msk                 (0x80000000UL)            /*!< MTB MASTER: EN (Bitfield-Mask: 0x01)                  */
#define MTB_MASTER_HALTREQ_Pos            (9UL)                     /*!< MTB MASTER: HALTREQ (Bit 9)                           */
#define MTB_MASTER_HALTREQ_Msk            (0x200UL)                 /*!< MTB MASTER: HALTREQ (Bitfield-Mask: 0x01)             */
#define MTB_MASTER_TSTOPEN_Pos            (6UL)                     /*!< MTB MASTER: TSTOPEN (Bit 6)                           */
#define MTB_MASTER_TSTOPEN_Msk            (0x40UL)                  /*!< MTB MASTER: TSTOPEN (Bitfield-Mask: 0x01)             */
#define MTB_MASTER_TSTARTEN_Pos           (5UL)                     /*!< MTB MASTER: TSTARTEN (Bit 5)                          */
#define MTB_MASTER_TSTARTEN_Msk           (0x20UL)                  /*!< MTB MASTER: TSTARTEN (Bitfield-Mask: 0x01)            */
#define MTB_MASTER_MASK_Pos               (0UL)                     /*!< MTB MASTER: MASK (Bit 0)                              */
#define MTB_MASTER_MASK_Msk               (0x1fUL)                  /*!< MTB MASTER: MASK (Bitfield-Mask: 0x1f)                */
/* =========================================================  FLOW  ========================================================== */
#define MTB_FLOW_WATERMARK_Pos            (3UL)                     /*!< MTB FLOW: WATERMARK (Bit 3)                           */
#define MTB_FLOW_WATERMARK_Msk            (0xfffffff8UL)            /*!< MTB FLOW: WATERMARK (Bitfield-Mask: 0x1fffffff)       */
#define MTB_FLOW_AUTOHALT_Pos             (1UL)                     /*!< MTB FLOW: AUTOHALT (Bit 1)                            */
#define MTB_FLOW_AUTOHALT_Msk             (0x2UL)                   /*!< MTB FLOW: AUTOHALT (Bitfield-Mask: 0x01)              */
#define MTB_FLOW_AUTOSTOP_Pos             (0UL)                     /*!< MTB FLOW: AUTOSTOP (Bit 0)                            */
#define MTB_FLOW_AUTOSTOP_Msk             (0x1UL)                   /*!< MTB FLOW: AUTOSTOP (Bitfield-Mask: 0x01)              */
/* =========================================================  BASE  ========================================================== */

/** @} */ /* End of group PosMask_peripherals */


/* =========================================================================================================================== */
/* ================                           Enumerated Values Peripheral Section                            ================ */
/* =========================================================================================================================== */


/** @addtogroup EnumValue_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                            CMP                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  OUT  ========================================================== */
/* ==========================================================  CTL  ========================================================== */
/* ==============================================  CMP CTL CMP1_PLUS [12..14]  =============================================== */
typedef enum {                                  /*!< CMP_CTL_CMP1_PLUS                                                         */
  CMP_CTL_CMP1_PLUS_NONE               = 0,     /*!< NONE : NONE                                                               */
  CMP_CTL_CMP1_PLUS_PA_1               = 1,     /*!< PA_1 : PA_1                                                               */
  CMP_CTL_CMP1_PLUS_PA_3               = 2,     /*!< PA_3 : PA_3                                                               */
  CMP_CTL_CMP1_PLUS_PA_5               = 3,     /*!< PA_5 : PA_5                                                               */
  CMP_CTL_CMP1_PLUS_PA_7               = 4,     /*!< PA_7 : PA_7                                                               */
} CMP_CTL_CMP1_PLUS_Enum;

/* ==============================================  CMP CTL CMP1_MINUS [9..11]  =============================================== */
typedef enum {                                  /*!< CMP_CTL_CMP1_MINUS                                                        */
  CMP_CTL_CMP1_MINUS_NONE              = 0,     /*!< NONE : NONE                                                               */
  CMP_CTL_CMP1_MINUS_PA_0              = 1,     /*!< PA_0 : PA_0                                                               */
  CMP_CTL_CMP1_MINUS_PA_2              = 2,     /*!< PA_2 : PA_2                                                               */
  CMP_CTL_CMP1_MINUS_PA_4              = 3,     /*!< PA_4 : PA_4                                                               */
  CMP_CTL_CMP1_MINUS_PA_6              = 4,     /*!< PA_6 : PA_6                                                               */
} CMP_CTL_CMP1_MINUS_Enum;

/* ===============================================  CMP CTL CMP0_PLUS [4..6]  ================================================ */
typedef enum {                                  /*!< CMP_CTL_CMP0_PLUS                                                         */
  CMP_CTL_CMP0_PLUS_NONE               = 0,     /*!< NONE : NONE                                                               */
  CMP_CTL_CMP0_PLUS_PA_1               = 1,     /*!< PA_1 : PA_1                                                               */
  CMP_CTL_CMP0_PLUS_PA_3               = 2,     /*!< PA_3 : PA_3                                                               */
  CMP_CTL_CMP0_PLUS_PA_5               = 3,     /*!< PA_5 : PA_5                                                               */
  CMP_CTL_CMP0_PLUS_PA_7               = 4,     /*!< PA_7 : PA_7                                                               */
} CMP_CTL_CMP0_PLUS_Enum;

/* ===============================================  CMP CTL CMP0_MINUS [1..3]  =============================================== */
typedef enum {                                  /*!< CMP_CTL_CMP0_MINUS                                                        */
  CMP_CTL_CMP0_MINUS_NONE              = 0,     /*!< NONE : NONE                                                               */
  CMP_CTL_CMP0_MINUS_PA_0              = 1,     /*!< PA_0 : PA_0                                                               */
  CMP_CTL_CMP0_MINUS_PA_2              = 2,     /*!< PA_2 : PA_2                                                               */
  CMP_CTL_CMP0_MINUS_PA_4              = 3,     /*!< PA_4 : PA_4                                                               */
  CMP_CTL_CMP0_MINUS_PA_6              = 4,     /*!< PA_6 : PA_6                                                               */
} CMP_CTL_CMP0_MINUS_Enum;

/* ========================================================  INT_EN  ========================================================= */
/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
/* ===============================================  ADC CFG REG_SEL [24..24]  ================================================ */
typedef enum {                                  /*!< ADC_CFG_REG_SEL                                                           */
  ADC_CFG_REG_SEL_INT                  = 0,     /*!< INT : INT                                                                 */
  ADC_CFG_REG_SEL_EXT                  = 1,     /*!< EXT : EXT                                                                 */
} ADC_CFG_REG_SEL_Enum;

/* ===============================================  ADC CFG REF_SEL [22..23]  ================================================ */
typedef enum {                                  /*!< ADC_CFG_REF_SEL                                                           */
  ADC_CFG_REF_SEL_INT                  = 0,     /*!< INT : INT                                                                 */
  ADC_CFG_REF_SEL_EXT                  = 1,     /*!< EXT : EXT                                                                 */
  ADC_CFG_REF_SEL_INT_REG              = 2,     /*!< INT_REG : INT_REG                                                         */
} ADC_CFG_REF_SEL_Enum;

/* =================================================  ADC CFG GAIN [19..20]  ================================================= */
typedef enum {                                  /*!< ADC_CFG_GAIN                                                              */
  ADC_CFG_GAIN_BYPASS                  = 0,     /*!< BYPASS : BYPASS                                                           */
  ADC_CFG_GAIN_DIV4                    = 1,     /*!< DIV4 : DIV4                                                               */
  ADC_CFG_GAIN_MUL1                    = 2,     /*!< MUL1 : MUL1                                                               */
  ADC_CFG_GAIN_MUL10                   = 3,     /*!< MUL10 : MUL10                                                             */
} ADC_CFG_GAIN_Enum;

/* ==========================================================  CTL  ========================================================== */
/* ===============================================  ADC CTL EDGE_TRIG [4..5]  ================================================ */
typedef enum {                                  /*!< ADC_CTL_EDGE_TRIG                                                         */
  ADC_CTL_EDGE_TRIG_RISING             = 0,     /*!< RISING : RISING                                                           */
  ADC_CTL_EDGE_TRIG_FALLING            = 1,     /*!< FALLING : FALLING                                                         */
  ADC_CTL_EDGE_TRIG_BOTH               = 2,     /*!< BOTH : BOTH                                                               */
} ADC_CTL_EDGE_TRIG_Enum;

/* ==========================================================  CAL  ========================================================== */
/* ========================================================  INT_EN  ========================================================= */
/* ========================================================  INT_STS  ======================================================== */
/* =======================================================  TEST_MOD  ======================================================== */
/* ========================================================  CH_STS  ========================================================= */
/* ==========================================================  STS  ========================================================== */
/* ================================================  ADC STS STATE [15..15]  ================================================= */
typedef enum {                                  /*!< ADC_STS_STATE                                                             */
  ADC_STS_STATE_RUNNING                = 0,     /*!< RUNNING : RUNNING                                                         */
  ADC_STS_STATE_IDLE                   = 1,     /*!< IDLE : IDLE                                                               */
} ADC_STS_STATE_Enum;



/* =========================================================================================================================== */
/* ================                                            CMU                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ===========================================  CMU CFG SYSTICK_CLK_SEL [16..17]  ============================================ */
typedef enum {                                  /*!< CMU_CFG_SYSTICK_CLK_SEL                                                   */
  CMU_CFG_SYSTICK_CLK_SEL_NONE         = 0,     /*!< NONE : NONE                                                               */
  CMU_CFG_SYSTICK_CLK_SEL_SYS_CLK      = 1,     /*!< SYS_CLK : SYS_CLK                                                         */
  CMU_CFG_SYSTICK_CLK_SEL_LP_OSC       = 2,     /*!< LP_OSC : LP_OSC                                                           */
  CMU_CFG_SYSTICK_CLK_SEL_LP_XOSC      = 3,     /*!< LP_XOSC : LP_XOSC                                                         */
} CMU_CFG_SYSTICK_CLK_SEL_Enum;

/* =============================================  CMU CFG WDOG_CLK_SEL [14..15]  ============================================= */
typedef enum {                                  /*!< CMU_CFG_WDOG_CLK_SEL                                                      */
  CMU_CFG_WDOG_CLK_SEL_NONE            = 0,     /*!< NONE : NONE                                                               */
  CMU_CFG_WDOG_CLK_SEL_SYS_CLK         = 1,     /*!< SYS_CLK : SYS_CLK                                                         */
  CMU_CFG_WDOG_CLK_SEL_LP_OSC          = 2,     /*!< LP_OSC : LP_OSC                                                           */
  CMU_CFG_WDOG_CLK_SEL_LP_XOSC         = 3,     /*!< LP_XOSC : LP_XOSC                                                         */
} CMU_CFG_WDOG_CLK_SEL_Enum;

/* ============================================  CMU CFG SYS_CLK_MON_PER [6..7]  ============================================= */
typedef enum {                                  /*!< CMU_CFG_SYS_CLK_MON_PER                                                   */
  CMU_CFG_SYS_CLK_MON_PER_NONE         = 0,     /*!< NONE : NONE                                                               */
  CMU_CFG_SYS_CLK_MON_PER_4_LP_OSC_PER = 1,     /*!< 4_LP_OSC_PER : 4_LP_OSC_PER                                               */
  CMU_CFG_SYS_CLK_MON_PER_16_LP_OSC_PER = 2,    /*!< 16_LP_OSC_PER : 16_LP_OSC_PER                                             */
  CMU_CFG_SYS_CLK_MON_PER_64_LP_OSC_PER = 3,    /*!< 64_LP_OSC_PER : 64_LP_OSC_PER                                             */
} CMU_CFG_SYS_CLK_MON_PER_Enum;

/* ==============================================  CMU CFG SYS_CLK_DIV [3..5]  =============================================== */
typedef enum {                                  /*!< CMU_CFG_SYS_CLK_DIV                                                       */
  CMU_CFG_SYS_CLK_DIV_BY_1             = 0,     /*!< BY_1 : BY_1                                                               */
  CMU_CFG_SYS_CLK_DIV_BY_2             = 1,     /*!< BY_2 : BY_2                                                               */
  CMU_CFG_SYS_CLK_DIV_BY_4             = 2,     /*!< BY_4 : BY_4                                                               */
  CMU_CFG_SYS_CLK_DIV_BY_8             = 3,     /*!< BY_8 : BY_8                                                               */
  CMU_CFG_SYS_CLK_DIV_BY_16            = 4,     /*!< BY_16 : BY_16                                                             */
  CMU_CFG_SYS_CLK_DIV_BY_32            = 5,     /*!< BY_32 : BY_32                                                             */
  CMU_CFG_SYS_CLK_DIV_BY_64            = 6,     /*!< BY_64 : BY_64                                                             */
  CMU_CFG_SYS_CLK_DIV_BY_128           = 7,     /*!< BY_128 : BY_128                                                           */
} CMU_CFG_SYS_CLK_DIV_Enum;

/* ==============================================  CMU CFG SYS_CLK_SEL [0..2]  =============================================== */
typedef enum {                                  /*!< CMU_CFG_SYS_CLK_SEL                                                       */
  CMU_CFG_SYS_CLK_SEL_HS_OSC           = 0,     /*!< HS_OSC : HS_OSC                                                           */
  CMU_CFG_SYS_CLK_SEL_LP_OSC           = 1,     /*!< LP_OSC : LP_OSC                                                           */
  CMU_CFG_SYS_CLK_SEL_HS_XOSC          = 2,     /*!< HS_XOSC : HS_XOSC                                                         */
  CMU_CFG_SYS_CLK_SEL_LP_XOSC          = 3,     /*!< LP_XOSC : LP_XOSC                                                         */
  CMU_CFG_SYS_CLK_SEL_EXT_CLK          = 4,     /*!< EXT_CLK : EXT_CLK                                                         */
} CMU_CFG_SYS_CLK_SEL_Enum;

/* ==========================================================  STS  ========================================================== */
/* ================================================  CMU STS CLK_SEL [0..2]  ================================================= */
typedef enum {                                  /*!< CMU_STS_CLK_SEL                                                           */
  CMU_STS_CLK_SEL_HS_OSC               = 0,     /*!< HS_OSC : HS_OSC                                                           */
  CMU_STS_CLK_SEL_LP_OSC               = 1,     /*!< LP_OSC : LP_OSC                                                           */
  CMU_STS_CLK_SEL_HS_XOSC              = 2,     /*!< HS_XOSC : HS_XOSC                                                         */
  CMU_STS_CLK_SEL_LP_XOSC              = 3,     /*!< LP_XOSC : LP_XOSC                                                         */
  CMU_STS_CLK_SEL_EXT_CLK              = 4,     /*!< EXT_CLK : EXT_CLK                                                         */
} CMU_STS_CLK_SEL_Enum;

/* ======================================================  ADC_CLK_CFG  ====================================================== */
/* ==============================================  CMU ADC_CLK_CFG SEL [4..6]  =============================================== */
typedef enum {                                  /*!< CMU_ADC_CLK_CFG_SEL                                                       */
  CMU_ADC_CLK_CFG_SEL_SYS_CLK          = 0,     /*!< SYS_CLK : SYS_CLK                                                         */
  CMU_ADC_CLK_CFG_SEL_HS_OSC           = 1,     /*!< HS_OSC : HS_OSC                                                           */
  CMU_ADC_CLK_CFG_SEL_LP_OSC           = 2,     /*!< LP_OSC : LP_OSC                                                           */
  CMU_ADC_CLK_CFG_SEL_HS_XOSC          = 3,     /*!< HS_XOSC : HS_XOSC                                                         */
  CMU_ADC_CLK_CFG_SEL_LP_XOSC          = 4,     /*!< LP_XOSC : LP_XOSC                                                         */
  CMU_ADC_CLK_CFG_SEL_EXT_CLK          = 5,     /*!< EXT_CLK : EXT_CLK                                                         */
} CMU_ADC_CLK_CFG_SEL_Enum;

/* ==============================================  CMU ADC_CLK_CFG DIV [0..2]  =============================================== */
typedef enum {                                  /*!< CMU_ADC_CLK_CFG_DIV                                                       */
  CMU_ADC_CLK_CFG_DIV_BY_1             = 0,     /*!< BY_1 : BY_1                                                               */
  CMU_ADC_CLK_CFG_DIV_BY_2             = 1,     /*!< BY_2 : BY_2                                                               */
  CMU_ADC_CLK_CFG_DIV_BY_4             = 2,     /*!< BY_4 : BY_4                                                               */
  CMU_ADC_CLK_CFG_DIV_BY_8             = 3,     /*!< BY_8 : BY_8                                                               */
  CMU_ADC_CLK_CFG_DIV_BY_16            = 4,     /*!< BY_16 : BY_16                                                             */
  CMU_ADC_CLK_CFG_DIV_BY_32            = 5,     /*!< BY_32 : BY_32                                                             */
  CMU_ADC_CLK_CFG_DIV_BY_64            = 6,     /*!< BY_64 : BY_64                                                             */
  CMU_ADC_CLK_CFG_DIV_BY_128           = 7,     /*!< BY_128 : BY_128                                                           */
} CMU_ADC_CLK_CFG_DIV_Enum;

/* ======================================================  EXT_CLK_DIV  ====================================================== */
/* =======================================================  PCLK_CFG  ======================================================== */
/* ======================================================  LP_OSC_CFG  ======================================================= */
/* ============================================  CMU LP_OSC_CFG FREQ_SEL [6..6]  ============================================= */
typedef enum {                                  /*!< CMU_LP_OSC_CFG_FREQ_SEL                                                   */
  CMU_LP_OSC_CFG_FREQ_SEL_640Hz        = 0,     /*!< 640Hz : 640Hz                                                             */
  CMU_LP_OSC_CFG_FREQ_SEL_1024Hz       = 1,     /*!< 1024Hz : 1024Hz                                                           */
} CMU_LP_OSC_CFG_FREQ_SEL_Enum;

/* ===============================================  CMU LP_OSC_CFG DIV [3..5]  =============================================== */
typedef enum {                                  /*!< CMU_LP_OSC_CFG_DIV                                                        */
  CMU_LP_OSC_CFG_DIV_BY_2              = 2,     /*!< BY_2 : BY_2                                                               */
  CMU_LP_OSC_CFG_DIV_BY_4              = 3,     /*!< BY_4 : BY_4                                                               */
  CMU_LP_OSC_CFG_DIV_BY_8              = 4,     /*!< BY_8 : BY_8                                                               */
  CMU_LP_OSC_CFG_DIV_BY_16             = 5,     /*!< BY_16 : BY_16                                                             */
  CMU_LP_OSC_CFG_DIV_BY_32             = 6,     /*!< BY_32 : BY_32                                                             */
  CMU_LP_OSC_CFG_DIV_BY_64             = 7,     /*!< BY_64 : BY_64                                                             */
} CMU_LP_OSC_CFG_DIV_Enum;

/* =============================================  CMU LP_OSC_CFG CAL_SEL [0..2]  ============================================= */
typedef enum {                                  /*!< CMU_LP_OSC_CFG_CAL_SEL                                                    */
  CMU_LP_OSC_CFG_CAL_SEL_HS_OSC        = 0,     /*!< HS_OSC : HS_OSC                                                           */
  CMU_LP_OSC_CFG_CAL_SEL_NONE          = 1,     /*!< NONE : NONE                                                               */
  CMU_LP_OSC_CFG_CAL_SEL_HS_XOSC       = 2,     /*!< HS_XOSC : HS_XOSC                                                         */
  CMU_LP_OSC_CFG_CAL_SEL_EXT_CLK       = 4,     /*!< EXT_CLK : EXT_CLK                                                         */
} CMU_LP_OSC_CFG_CAL_SEL_Enum;

/* ======================================================  LP_OSC_FILT  ====================================================== */
/* ====================================================  LP_OSC_REF_DIV  ===================================================== */
/* ===================================================  LP_OSC_FREQ_TUNE  ==================================================== */
/* ======================================================  LP_OSC_PER  ======================================================= */
/* ======================================================  HS_OSC_CFG  ======================================================= */
/* ============================================  CMU HS_OSC_CFG FREQ_SEL [7..7]  ============================================= */
typedef enum {                                  /*!< CMU_HS_OSC_CFG_FREQ_SEL                                                   */
  CMU_HS_OSC_CFG_FREQ_SEL_16MHz        = 0,     /*!< 16MHz : 16MHz                                                             */
  CMU_HS_OSC_CFG_FREQ_SEL_20MHz        = 1,     /*!< 20MHz : 20MHz                                                             */
} CMU_HS_OSC_CFG_FREQ_SEL_Enum;

/* ===============================================  CMU HS_OSC_CFG DIV [3..6]  =============================================== */
typedef enum {                                  /*!< CMU_HS_OSC_CFG_DIV                                                        */
  CMU_HS_OSC_CFG_DIV_BY_1              = 0,     /*!< BY_1 : BY_1                                                               */
  CMU_HS_OSC_CFG_DIV_BY_2              = 2,     /*!< BY_2 : BY_2                                                               */
  CMU_HS_OSC_CFG_DIV_BY_4              = 3,     /*!< BY_4 : BY_4                                                               */
  CMU_HS_OSC_CFG_DIV_BY_8              = 4,     /*!< BY_8 : BY_8                                                               */
  CMU_HS_OSC_CFG_DIV_BY_16             = 5,     /*!< BY_16 : BY_16                                                             */
  CMU_HS_OSC_CFG_DIV_BY_32             = 6,     /*!< BY_32 : BY_32                                                             */
  CMU_HS_OSC_CFG_DIV_BY_64             = 7,     /*!< BY_64 : BY_64                                                             */
  CMU_HS_OSC_CFG_DIV_BY_128            = 8,     /*!< BY_128 : BY_128                                                           */
  CMU_HS_OSC_CFG_DIV_BY_256            = 9,     /*!< BY_256 : BY_256                                                           */
  CMU_HS_OSC_CFG_DIV_BY_512            = 10,    /*!< BY_512 : BY_512                                                           */
  CMU_HS_OSC_CFG_DIV_BY_1024           = 11,    /*!< BY_1024 : BY_1024                                                         */
  CMU_HS_OSC_CFG_DIV_BY_2048           = 12,    /*!< BY_2048 : BY_2048                                                         */
  CMU_HS_OSC_CFG_DIV_BY_4096           = 13,    /*!< BY_4096 : BY_4096                                                         */
  CMU_HS_OSC_CFG_DIV_BY_8192           = 14,    /*!< BY_8192 : BY_8192                                                         */
  CMU_HS_OSC_CFG_DIV_BY_16384          = 15,    /*!< BY_16384 : BY_16384                                                       */
} CMU_HS_OSC_CFG_DIV_Enum;

/* =============================================  CMU HS_OSC_CFG CAL_SEL [0..2]  ============================================= */
typedef enum {                                  /*!< CMU_HS_OSC_CFG_CAL_SEL                                                    */
  CMU_HS_OSC_CFG_CAL_SEL_NONE          = 0,     /*!< NONE : NONE                                                               */
  CMU_HS_OSC_CFG_CAL_SEL_LP_OSC        = 1,     /*!< LP_OSC : LP_OSC                                                           */
  CMU_HS_OSC_CFG_CAL_SEL_HS_XOSC       = 2,     /*!< HS_XOSC : HS_XOSC                                                         */
  CMU_HS_OSC_CFG_CAL_SEL_LP_XOSC       = 3,     /*!< LP_XOSC : LP_XOSC                                                         */
  CMU_HS_OSC_CFG_CAL_SEL_EXT_CLK       = 4,     /*!< EXT_CLK : EXT_CLK                                                         */
} CMU_HS_OSC_CFG_CAL_SEL_Enum;

/* ======================================================  HS_OSC_FILT  ====================================================== */
/* ====================================================  HS_OSC_REF_DIV  ===================================================== */
/* =================================================  HS_OSC_20M_FREQ_TUNE  ================================================== */
/* =================================================  HS_OSC_16M_FREQ_TUNE  ================================================== */
/* ======================================================  HS_OSC_PER  ======================================================= */
/* ======================================================  OSC_ON_STS  ======================================================= */
/* =====================================================  OSC_READY_STS  ===================================================== */
/* ========================================================  INT_STS  ======================================================== */
/* ======================================================  LP_XOSC_CFG  ====================================================== */
/* ====================================================  HS_XOSC_GM_CFG  ===================================================== */
/* ===================================================  HS_XOSC_AMPL_CFG  ==================================================== */
/* =====================================================  HS_XOSC_READY  ===================================================== */
/* ======================================================  AO_SCRATCH  ======================================================= */


/* =========================================================================================================================== */
/* ================                                          CC_PWM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */
/* =========================================================  DATA  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           XBAR                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  ANA_CFG  ======================================================== */
/* ========================================================  OUT_CFG  ======================================================== */
/* ======================================================  PULL_UP_CFG  ====================================================== */
/* =====================================================  PULL_DOWN_CFG  ===================================================== */
/* ========================================================  PA_CFG  ========================================================= */
/* ========================================================  PB_CFG  ========================================================= */
/* ========================================================  PC_CFG  ========================================================= */
/* ========================================================  PR_CFG  ========================================================= */
/* =====================================================  IN_UART0_CFG  ====================================================== */
/* =============================================  XBAR IN_UART0_CFG CLK [2..3]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_UART0_CFG_CLK                                                     */
  XBAR_IN_UART0_CFG_CLK_NONE           = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_UART0_CFG_CLK_PB2            = 1,     /*!< PB2 : PB2                                                                 */
  XBAR_IN_UART0_CFG_CLK_PR5            = 2,     /*!< PR5 : PR5                                                                 */
} XBAR_IN_UART0_CFG_CLK_Enum;

/* ==============================================  XBAR IN_UART0_CFG RX [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_UART0_CFG_RX                                                      */
  XBAR_IN_UART0_CFG_RX_NONE            = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_UART0_CFG_RX_PB5             = 1,     /*!< PB5 : PB5                                                                 */
  XBAR_IN_UART0_CFG_RX_PC3             = 2,     /*!< PC3 : PC3                                                                 */
  XBAR_IN_UART0_CFG_RX_PR4             = 3,     /*!< PR4 : PR4                                                                 */
} XBAR_IN_UART0_CFG_RX_Enum;

/* =====================================================  IN_UART1_CFG  ====================================================== */
/* =============================================  XBAR IN_UART1_CFG CLK [2..3]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_UART1_CFG_CLK                                                     */
  XBAR_IN_UART1_CFG_CLK_NONE           = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_UART1_CFG_CLK_PA1            = 1,     /*!< PA1 : PA1                                                                 */
  XBAR_IN_UART1_CFG_CLK_PR0            = 2,     /*!< PR0 : PR0                                                                 */
} XBAR_IN_UART1_CFG_CLK_Enum;

/* ==============================================  XBAR IN_UART1_CFG RX [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_UART1_CFG_RX                                                      */
  XBAR_IN_UART1_CFG_RX_NONE            = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_UART1_CFG_RX_PA2             = 1,     /*!< PA2 : PA2                                                                 */
  XBAR_IN_UART1_CFG_RX_PB1             = 2,     /*!< PB1 : PB1                                                                 */
  XBAR_IN_UART1_CFG_RX_PC7             = 3,     /*!< PC7 : PC7                                                                 */
} XBAR_IN_UART1_CFG_RX_Enum;

/* ======================================================  IN_SPI1_CFG  ====================================================== */
/* ===============================================  XBAR IN_SPI1_CFG IN [0..2]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_SPI1_CFG_IN                                                       */
  XBAR_IN_SPI1_CFG_IN_SEL_1            = 0,     /*!< SEL_1 : SS = 1, SCK = 0, DATAI = 0                                        */
  XBAR_IN_SPI1_CFG_IN_SEL_PA2          = 1,     /*!< SEL_PA2 : SS = PA2, SCK = PA3, DATAI = PA6                                */
  XBAR_IN_SPI1_CFG_IN_SEL_PB2          = 2,     /*!< SEL_PB2 : SS = PB2, SCK = PB3, DATAI = PB0                                */
  XBAR_IN_SPI1_CFG_IN_SEL_PB5          = 3,     /*!< SEL_PB5 : SS = PB5, SCK = PB6,DATAI = PB4                                 */
  XBAR_IN_SPI1_CFG_IN_SEL_PC1          = 4,     /*!< SEL_PC1 : SS = PC1, SCK = PC0, DATAI = PC3                                */
} XBAR_IN_SPI1_CFG_IN_Enum;

/* ======================================================  IN_SPI0_CFG  ====================================================== */
/* ===============================================  XBAR IN_SPI0_CFG IN [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_SPI0_CFG_IN                                                       */
  XBAR_IN_SPI0_CFG_IN_MISO_0           = 0,     /*!< MISO_0 : DATAI = 0                                                        */
  XBAR_IN_SPI0_CFG_IN_MISO_PC3         = 1,     /*!< MISO_PC3 : DATAI = PC3                                                    */
  XBAR_IN_SPI0_CFG_IN_MISO_PR3         = 2,     /*!< MISO_PR3 : DATAI = PR3                                                    */
} XBAR_IN_SPI0_CFG_IN_Enum;

/* ======================================================  IN_DMA_CFG  ======================================================= */
/* =========================================  XBAR IN_DMA_CFG CH2_TRIG_TYP [21..21]  ========================================= */
typedef enum {                                  /*!< XBAR_IN_DMA_CFG_CH2_TRIG_TYP                                              */
  XBAR_IN_DMA_CFG_CH2_TRIG_TYP_SREQ    = 0,     /*!< SREQ : SREQ                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_TYP_REQ     = 1,     /*!< REQ : REQ                                                                 */
} XBAR_IN_DMA_CFG_CH2_TRIG_TYP_Enum;

/* =========================================  XBAR IN_DMA_CFG CH2_TRIG_SEL [16..20]  ========================================= */
typedef enum {                                  /*!< XBAR_IN_DMA_CFG_CH2_TRIG_SEL                                              */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_NONE    = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_ADC_SAMP = 1,    /*!< ADC_SAMP : ADC_SAMP                                                       */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_ADC_SCAN = 2,    /*!< ADC_SCAN : ADC_SCAN                                                       */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_UART0_RX = 3,    /*!< UART0_RX : UART0_RX                                                       */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_UART0_TX = 4,    /*!< UART0_TX : UART0_TX                                                       */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_UART1_RX = 5,    /*!< UART1_RX : UART1_RX                                                       */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_UART1_TX = 6,    /*!< UART1_TX : UART1_TX                                                       */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_SPI1_RX = 7,     /*!< SPI1_RX : SPI1_RX                                                         */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_SPI1_TX = 8,     /*!< SPI1_TX : SPI1_TX                                                         */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_I2C_RX  = 9,     /*!< I2C_RX : I2C_RX                                                           */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_I2C_TX  = 10,    /*!< I2C_TX : I2C_TX                                                           */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_TIM0    = 11,    /*!< TIM0 : TIM0                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_TIM1    = 12,    /*!< TIM1 : TIM1                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_TIM2    = 13,    /*!< TIM2 : TIM2                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_CAPT0   = 14,    /*!< CAPT0 : CAPT0                                                             */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_PWM0    = 15,    /*!< PWM0 : PWM0                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_CAPT1   = 16,    /*!< CAPT1 : CAPT1                                                             */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_PWM1    = 17,    /*!< PWM1 : PWM1                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_CAPT2   = 18,    /*!< CAPT2 : CAPT2                                                             */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_PWM2    = 19,    /*!< PWM2 : PWM2                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_CAPT3   = 20,    /*!< CAPT3 : CAPT3                                                             */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_PWM3    = 21,    /*!< PWM3 : PWM3                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_TRNG    = 22,    /*!< TRNG : TRNG                                                               */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_FLASH   = 23,    /*!< FLASH : FLASH                                                             */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_GPIO_A  = 24,    /*!< GPIO_A : GPIO_A                                                           */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_GPIO_B  = 25,    /*!< GPIO_B : GPIO_B                                                           */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_GPIO_C  = 26,    /*!< GPIO_C : GPIO_C                                                           */
  XBAR_IN_DMA_CFG_CH2_TRIG_SEL_GPIO_R  = 27,    /*!< GPIO_R : GPIO_R                                                           */
} XBAR_IN_DMA_CFG_CH2_TRIG_SEL_Enum;

/* =========================================  XBAR IN_DMA_CFG CH1_TRIG_TYP [13..13]  ========================================= */
typedef enum {                                  /*!< XBAR_IN_DMA_CFG_CH1_TRIG_TYP                                              */
  XBAR_IN_DMA_CFG_CH1_TRIG_TYP_SREQ    = 0,     /*!< SREQ : SREQ                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_TYP_REQ     = 1,     /*!< REQ : REQ                                                                 */
} XBAR_IN_DMA_CFG_CH1_TRIG_TYP_Enum;

/* =========================================  XBAR IN_DMA_CFG CH1_TRIG_SEL [8..12]  ========================================== */
typedef enum {                                  /*!< XBAR_IN_DMA_CFG_CH1_TRIG_SEL                                              */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_NONE    = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_ADC_SAMP = 1,    /*!< ADC_SAMP : ADC_SAMP                                                       */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_ADC_SCAN = 2,    /*!< ADC_SCAN : ADC_SCAN                                                       */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_UART0_RX = 3,    /*!< UART0_RX : UART0_RX                                                       */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_UART0_TX = 4,    /*!< UART0_TX : UART0_TX                                                       */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_UART1_RX = 5,    /*!< UART1_RX : UART1_RX                                                       */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_UART1_TX = 6,    /*!< UART1_TX : UART1_TX                                                       */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_SPI1_RX = 7,     /*!< SPI1_RX : SPI1_RX                                                         */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_SPI1_TX = 8,     /*!< SPI1_TX : SPI1_TX                                                         */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_I2C_RX  = 9,     /*!< I2C_RX : I2C_RX                                                           */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_I2C_TX  = 10,    /*!< I2C_TX : I2C_TX                                                           */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_TIM0    = 11,    /*!< TIM0 : TIM0                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_TIM1    = 12,    /*!< TIM1 : TIM1                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_TIM2    = 13,    /*!< TIM2 : TIM2                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_CAPT0   = 14,    /*!< CAPT0 : CAPT0                                                             */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_PWM0    = 15,    /*!< PWM0 : PWM0                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_CAPT1   = 16,    /*!< CAPT1 : CAPT1                                                             */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_PWM1    = 17,    /*!< PWM1 : PWM1                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_CAPT2   = 18,    /*!< CAPT2 : CAPT2                                                             */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_PWM2    = 19,    /*!< PWM2 : PWM2                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_CAPT3   = 20,    /*!< CAPT3 : CAPT3                                                             */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_PWM3    = 21,    /*!< PWM3 : PWM3                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_TRNG    = 22,    /*!< TRNG : TRNG                                                               */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_FLASH   = 23,    /*!< FLASH : FLASH                                                             */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_GPIO_A  = 24,    /*!< GPIO_A : GPIO_A                                                           */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_GPIO_B  = 25,    /*!< GPIO_B : GPIO_B                                                           */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_GPIO_C  = 26,    /*!< GPIO_C : GPIO_C                                                           */
  XBAR_IN_DMA_CFG_CH1_TRIG_SEL_GPIO_R  = 27,    /*!< GPIO_R : GPIO_R                                                           */
} XBAR_IN_DMA_CFG_CH1_TRIG_SEL_Enum;

/* ==========================================  XBAR IN_DMA_CFG CH0_TRIG_TYP [5..5]  ========================================== */
typedef enum {                                  /*!< XBAR_IN_DMA_CFG_CH0_TRIG_TYP                                              */
  XBAR_IN_DMA_CFG_CH0_TRIG_TYP_SREQ    = 0,     /*!< SREQ : SREQ                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_TYP_REQ     = 1,     /*!< REQ : REQ                                                                 */
} XBAR_IN_DMA_CFG_CH0_TRIG_TYP_Enum;

/* ==========================================  XBAR IN_DMA_CFG CH0_TRIG_SEL [0..4]  ========================================== */
typedef enum {                                  /*!< XBAR_IN_DMA_CFG_CH0_TRIG_SEL                                              */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_NONE    = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_ADC_SAMP = 1,    /*!< ADC_SAMP : ADC_SAMP                                                       */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_ADC_SCAN = 2,    /*!< ADC_SCAN : ADC_SCAN                                                       */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_UART0_RX = 3,    /*!< UART0_RX : UART0_RX                                                       */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_UART0_TX = 4,    /*!< UART0_TX : UART0_TX                                                       */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_UART1_RX = 5,    /*!< UART1_RX : UART1_RX                                                       */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_UART1_TX = 6,    /*!< UART1_TX : UART1_TX                                                       */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_SPI1_RX = 7,     /*!< SPI1_RX : SPI1_RX                                                         */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_SPI1_TX = 8,     /*!< SPI1_TX : SPI1_TX                                                         */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_I2C_RX  = 9,     /*!< I2C_RX : I2C_RX                                                           */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_I2C_TX  = 10,    /*!< I2C_TX : I2C_TX                                                           */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_TIM0    = 11,    /*!< TIM0 : TIM0                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_TIM1    = 12,    /*!< TIM1 : TIM1                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_TIM2    = 13,    /*!< TIM2 : TIM2                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_CAPT0   = 14,    /*!< CAPT0 : CAPT0                                                             */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_PWM0    = 15,    /*!< PWM0 : PWM0                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_CAPT1   = 16,    /*!< CAPT1 : CAPT1                                                             */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_PWM1    = 17,    /*!< PWM1 : PWM1                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_CAPT2   = 18,    /*!< CAPT2 : CAPT2                                                             */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_PWM2    = 19,    /*!< PWM2 : PWM2                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_CAPT3   = 20,    /*!< CAPT3 : CAPT3                                                             */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_PWM3    = 21,    /*!< PWM3 : PWM3                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_TRNG    = 22,    /*!< TRNG : TRNG                                                               */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_FLASH   = 23,    /*!< FLASH : FLASH                                                             */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_GPIO_A  = 24,    /*!< GPIO_A : GPIO_A                                                           */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_GPIO_B  = 25,    /*!< GPIO_B : GPIO_B                                                           */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_GPIO_C  = 26,    /*!< GPIO_C : GPIO_C                                                           */
  XBAR_IN_DMA_CFG_CH0_TRIG_SEL_GPIO_R  = 27,    /*!< GPIO_R : GPIO_R                                                           */
} XBAR_IN_DMA_CFG_CH0_TRIG_SEL_Enum;

/* ======================================================  IN_ADC_CFG  ======================================================= */
/* ===========================================  XBAR IN_ADC_CFG TRIG_TYP [16..16]  =========================================== */
typedef enum {                                  /*!< XBAR_IN_ADC_CFG_TRIG_TYP                                                  */
  XBAR_IN_ADC_CFG_TRIG_TYP_PIN         = 0,     /*!< PIN : PIN                                                                 */
  XBAR_IN_ADC_CFG_TRIG_TYP_TIM         = 1,     /*!< TIM : TIM                                                                 */
} XBAR_IN_ADC_CFG_TRIG_TYP_Enum;

/* ============================================  XBAR IN_ADC_CFG PIN_SEL [8..10]  ============================================ */
typedef enum {                                  /*!< XBAR_IN_ADC_CFG_PIN_SEL                                                   */
  XBAR_IN_ADC_CFG_PIN_SEL_PA6          = 0,     /*!< PA6 : PA6                                                                 */
  XBAR_IN_ADC_CFG_PIN_SEL_PB0          = 1,     /*!< PB0 : PB0                                                                 */
  XBAR_IN_ADC_CFG_PIN_SEL_PC0          = 2,     /*!< PC0 : PC0                                                                 */
  XBAR_IN_ADC_CFG_PIN_SEL_PC4          = 3,     /*!< PC4 : PC4                                                                 */
} XBAR_IN_ADC_CFG_PIN_SEL_Enum;

/* ============================================  XBAR IN_ADC_CFG TIM_SEL [0..2]  ============================================= */
typedef enum {                                  /*!< XBAR_IN_ADC_CFG_TIM_SEL                                                   */
  XBAR_IN_ADC_CFG_TIM_SEL_TIM0         = 0,     /*!< TIM0 : TIM0                                                               */
  XBAR_IN_ADC_CFG_TIM_SEL_TIM1         = 1,     /*!< TIM1 : TIM1                                                               */
  XBAR_IN_ADC_CFG_TIM_SEL_TIM2         = 2,     /*!< TIM2 : TIM2                                                               */
  XBAR_IN_ADC_CFG_TIM_SEL_PWM0         = 4,     /*!< PWM0 : PWM0                                                               */
  XBAR_IN_ADC_CFG_TIM_SEL_PWM1         = 5,     /*!< PWM1 : PWM1                                                               */
  XBAR_IN_ADC_CFG_TIM_SEL_PWM2         = 6,     /*!< PWM2 : PWM2                                                               */
  XBAR_IN_ADC_CFG_TIM_SEL_PWM3         = 7,     /*!< PWM3 : PWM3                                                               */
} XBAR_IN_ADC_CFG_TIM_SEL_Enum;

/* ======================================================  IN_TIM0_CFG  ====================================================== */
/* ==============================================  XBAR IN_TIM0_CFG SEL [0..2]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_TIM0_CFG_SEL                                                      */
  XBAR_IN_TIM0_CFG_SEL_NONE            = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_TIM0_CFG_SEL_PA1             = 1,     /*!< PA1 : PA1                                                                 */
  XBAR_IN_TIM0_CFG_SEL_PB1             = 2,     /*!< PB1 : PB1                                                                 */
  XBAR_IN_TIM0_CFG_SEL_PC1             = 3,     /*!< PC1 : PC1                                                                 */
} XBAR_IN_TIM0_CFG_SEL_Enum;

/* ======================================================  IN_TIM1_CFG  ====================================================== */
/* ==============================================  XBAR IN_TIM1_CFG SEL [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_TIM1_CFG_SEL                                                      */
  XBAR_IN_TIM1_CFG_SEL_NONE            = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_TIM1_CFG_SEL_PA4             = 1,     /*!< PA4 : PA4                                                                 */
  XBAR_IN_TIM1_CFG_SEL_PB4             = 2,     /*!< PB4 : PB4                                                                 */
  XBAR_IN_TIM1_CFG_SEL_PC4             = 3,     /*!< PC4 : PC4                                                                 */
} XBAR_IN_TIM1_CFG_SEL_Enum;

/* ======================================================  IN_TIM2_CFG  ====================================================== */
/* ==============================================  XBAR IN_TIM2_CFG SEL [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_TIM2_CFG_SEL                                                      */
  XBAR_IN_TIM2_CFG_SEL_NONE            = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_TIM2_CFG_SEL_PA7             = 1,     /*!< PA7 : PA7                                                                 */
  XBAR_IN_TIM2_CFG_SEL_PB3             = 2,     /*!< PB3 : PB3                                                                 */
  XBAR_IN_TIM2_CFG_SEL_PR6             = 3,     /*!< PR6 : PR6                                                                 */
} XBAR_IN_TIM2_CFG_SEL_Enum;

/* =====================================================  IN_CAPT0_CFG  ====================================================== */
/* =============================================  XBAR IN_CAPT0_CFG SEL [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_CAPT0_CFG_SEL                                                     */
  XBAR_IN_CAPT0_CFG_SEL_NONE           = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_CAPT0_CFG_SEL_PA5            = 1,     /*!< PA5 : PA5                                                                 */
  XBAR_IN_CAPT0_CFG_SEL_PB2            = 2,     /*!< PB2 : PB2                                                                 */
  XBAR_IN_CAPT0_CFG_SEL_PC6            = 3,     /*!< PC6 : PC6                                                                 */
} XBAR_IN_CAPT0_CFG_SEL_Enum;

/* =====================================================  IN_CAPT1_CFG  ====================================================== */
/* =============================================  XBAR IN_CAPT1_CFG SEL [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_CAPT1_CFG_SEL                                                     */
  XBAR_IN_CAPT1_CFG_SEL_NONE           = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_CAPT1_CFG_SEL_PA0            = 1,     /*!< PA0 : PA0                                                                 */
  XBAR_IN_CAPT1_CFG_SEL_PB0            = 2,     /*!< PB0 : PB0                                                                 */
  XBAR_IN_CAPT1_CFG_SEL_PC5            = 3,     /*!< PC5 : PC5                                                                 */
} XBAR_IN_CAPT1_CFG_SEL_Enum;

/* =====================================================  IN_CAPT2_CFG  ====================================================== */
/* =============================================  XBAR IN_CAPT2_CFG SEL [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_CAPT2_CFG_SEL                                                     */
  XBAR_IN_CAPT2_CFG_SEL_NONE           = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_CAPT2_CFG_SEL_PA0            = 1,     /*!< PA0 : PA0                                                                 */
  XBAR_IN_CAPT2_CFG_SEL_PB0            = 2,     /*!< PB0 : PB0                                                                 */
  XBAR_IN_CAPT2_CFG_SEL_PC5            = 3,     /*!< PC5 : PC5                                                                 */
} XBAR_IN_CAPT2_CFG_SEL_Enum;

/* =====================================================  IN_CAPT3_CFG  ====================================================== */
/* =============================================  XBAR IN_CAPT3_CFG SEL [0..1]  ============================================== */
typedef enum {                                  /*!< XBAR_IN_CAPT3_CFG_SEL                                                     */
  XBAR_IN_CAPT3_CFG_SEL_NONE           = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_CAPT3_CFG_SEL_PA0            = 1,     /*!< PA0 : PA0                                                                 */
  XBAR_IN_CAPT3_CFG_SEL_PB0            = 2,     /*!< PB0 : PB0                                                                 */
  XBAR_IN_CAPT3_CFG_SEL_PC5            = 3,     /*!< PC5 : PC5                                                                 */
} XBAR_IN_CAPT3_CFG_SEL_Enum;

/* ====================================================  IN_EXT_CLK_CFG  ===================================================== */
/* ============================================  XBAR IN_EXT_CLK_CFG SEL [0..1]  ============================================= */
typedef enum {                                  /*!< XBAR_IN_EXT_CLK_CFG_SEL                                                   */
  XBAR_IN_EXT_CLK_CFG_SEL_NONE         = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_EXT_CLK_CFG_SEL_PA3          = 1,     /*!< PA3 : PA3                                                                 */
  XBAR_IN_EXT_CLK_CFG_SEL_PC1          = 2,     /*!< PC1 : PC1                                                                 */
  XBAR_IN_EXT_CLK_CFG_SEL_PR1          = 3,     /*!< PR1 : PR1                                                                 */
} XBAR_IN_EXT_CLK_CFG_SEL_Enum;

/* =======================================================  TEST_CFG  ======================================================== */
/* ======================================================  IN_MTB_CFG  ======================================================= */
/* ==============================================  XBAR IN_MTB_CFG SEL [0..1]  =============================================== */
typedef enum {                                  /*!< XBAR_IN_MTB_CFG_SEL                                                       */
  XBAR_IN_MTB_CFG_SEL_NONE             = 0,     /*!< NONE : NONE                                                               */
  XBAR_IN_MTB_CFG_SEL_PA1_PA2          = 1,     /*!< PA1_PA2 : PA1_PA2                                                         */
  XBAR_IN_MTB_CFG_SEL_PB4_PB5          = 2,     /*!< PB4_PB5 : PB4_PB5                                                         */
  XBAR_IN_MTB_CFG_SEL_PC0              = 3,     /*!< PC0 : PC0                                                                 */
} XBAR_IN_MTB_CFG_SEL_Enum;



/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  RESULT  ========================================================= */
/* =========================================================  INPUT  ========================================================= */


/* =========================================================================================================================== */
/* ================                                            DMA                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  STS  ========================================================== */
/* =================================================  DMA STS STATE [4..7]  ================================================== */
typedef enum {                                  /*!< DMA_STS_STATE                                                             */
  DMA_STS_STATE_IDLE                   = 0,     /*!< IDLE : IDLE                                                               */
  DMA_STS_STATE_READ_CTL               = 1,     /*!< READ_CTL : READ_CTL                                                       */
  DMA_STS_STATE_READ_SRC_PTR           = 2,     /*!< READ_SRC_PTR : READ_SRC_PTR                                               */
  DMA_STS_STATE_READ_DEST_PTR          = 3,     /*!< READ_DEST_PTR : READ_DEST_PTR                                             */
  DMA_STS_STATE_READ_SRC_DATA          = 4,     /*!< READ_SRC_DATA : READ_SRC_DATA                                             */
  DMA_STS_STATE_WRITE_DEST_DATA        = 5,     /*!< WRITE_DEST_DATA : WRITE_DEST_DATA                                         */
  DMA_STS_STATE_WAIT_REQ_FALLING       = 6,     /*!< WAIT_REQ_FALLING : WAIT_REQ_FALLING                                       */
  DMA_STS_STATE_STALL                  = 7,     /*!< STALL : STALL                                                             */
  DMA_STS_STATE_WRITE_CTL              = 8,     /*!< WRITE_CTL : WRITE_CTL                                                     */
  DMA_STS_STATE_DONE                   = 9,     /*!< DONE : DONE                                                               */
  DMA_STS_STATE_SG_TRANS               = 10,    /*!< SG_TRANS : SG_TRANS                                                       */
} DMA_STS_STATE_Enum;

/* ==========================================================  CFG  ========================================================== */
/* =====================================================  CTL_BASE_PTR  ====================================================== */
/* ===================================================  ALT_CTL_BASE_PTR  ==================================================== */
/* ====================================================  WAIT_ON_REQ_STS  ==================================================== */
/* ========================================================  SW_REQ  ========================================================= */
/* =====================================================  USE_BURST_SET  ===================================================== */
/* =====================================================  USE_BURST_CLR  ===================================================== */
/* =====================================================  REQ_MASK_SET  ====================================================== */
/* =====================================================  REQ_MASK_CLR  ====================================================== */
/* ========================================================  EN_SET  ========================================================= */
/* ========================================================  EN_CLR  ========================================================= */
/* ====================================================  PRI_ALT_SEL_SET  ==================================================== */
/* ====================================================  PRI_ALT_SEL_CLR  ==================================================== */
/* =======================================================  PRIO_SET  ======================================================== */
/* =======================================================  PRIO_CLR  ======================================================== */
/* ========================================================  ERR_CLR  ======================================================== */
/* ========================================================  INT_EN  ========================================================= */
/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                           FLASH                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CTL  ========================================================== */
/* ================================================  FLASH CTL STATE [3..3]  ================================================= */
typedef enum {                                  /*!< FLASH_CTL_STATE                                                           */
  FLASH_CTL_STATE_BUSY                 = 0,     /*!< BUSY : BUSY                                                               */
  FLASH_CTL_STATE_IDLE                 = 1,     /*!< IDLE : IDLE                                                               */
} FLASH_CTL_STATE_Enum;

/* =========================================================  ADDR  ========================================================== */
/* =======================================================  FLASHDATA  ======================================================= */
/* ========================================================  INT_EN  ========================================================= */
/* ========================================================  INT_STS  ======================================================== */
/* =======================================================  PROTECT0  ======================================================== */
/* =======================================================  PROTECT1  ======================================================== */
/* =======================================================  PROTECT2  ======================================================== */
/* =======================================================  PROTECT3  ======================================================== */
/* ========================================================  DMA_EN  ========================================================= */


/* =========================================================================================================================== */
/* ================                                           GPIO                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* =======================================================  DATA_OUT  ======================================================== */
/* ========================================================  OUT_EN  ========================================================= */
/* ========================================================  INT_EN  ========================================================= */
/* ========================================================  INT_POL  ======================================================== */
/* ========================================================  INT_TYP  ======================================================== */
/* ======================================================  DMA_TRIG_EN  ====================================================== */
/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                            I2C                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  CTL  ========================================================== */
/* =========================================================  DATA  ========================================================== */
/* ======================================================  DATA_MIRROR  ====================================================== */
/* ======================================================  ADDR_START  ======================================================= */
/* ==========================================================  STS  ========================================================== */
/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                            PMU                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  MOD  ========================================================== */
/* ==========================================================  PD  =========================================================== */
/* ==========================================================  STS  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            SPI                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */


/* =========================================================================================================================== */
/* ================                                          TICKER                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */
/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PER  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            TIM                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PER  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
/* ===============================================  TIM CFG CLK_DIV [11..13]  ================================================ */
typedef enum {                                  /*!< TIM_CFG_CLK_DIV                                                           */
  TIM_CFG_CLK_DIV_MUL2                 = 0,     /*!< MUL2 : MUL2                                                               */
  TIM_CFG_CLK_DIV_MUL1                 = 1,     /*!< MUL1 : MUL1                                                               */
  TIM_CFG_CLK_DIV_DIV2                 = 2,     /*!< DIV2 : DIV2                                                               */
  TIM_CFG_CLK_DIV_DIV4                 = 3,     /*!< DIV4 : DIV4                                                               */
  TIM_CFG_CLK_DIV_DIV8                 = 4,     /*!< DIV8 : DIV8                                                               */
  TIM_CFG_CLK_DIV_DIV16                = 5,     /*!< DIV16 : DIV16                                                             */
  TIM_CFG_CLK_DIV_DIV32                = 6,     /*!< DIV32 : DIV32                                                             */
  TIM_CFG_CLK_DIV_DIV64                = 7,     /*!< DIV64 : DIV64                                                             */
} TIM_CFG_CLK_DIV_Enum;

/* ================================================  TIM CFG CLK_SEL [8..10]  ================================================ */
typedef enum {                                  /*!< TIM_CFG_CLK_SEL                                                           */
  TIM_CFG_CLK_SEL_HS_OSC               = 0,     /*!< HS_OSC : HS_OSC                                                           */
  TIM_CFG_CLK_SEL_LP_OSC               = 1,     /*!< LP_OSC : LP_OSC                                                           */
  TIM_CFG_CLK_SEL_HS_XOSC              = 2,     /*!< HS_XOSC : HS_XOSC                                                         */
  TIM_CFG_CLK_SEL_LP_XOSC              = 3,     /*!< LP_XOSC : LP_XOSC                                                         */
  TIM_CFG_CLK_SEL_EXT_CLK              = 4,     /*!< EXT_CLK : EXT_CLK                                                         */
  TIM_CFG_CLK_SEL_EXT_CNT              = 5,     /*!< EXT_CNT : EXT_CNT                                                         */
  TIM_CFG_CLK_SEL_SYS_CLK              = 6,     /*!< SYS_CLK : SYS_CLK                                                         */
  TIM_CFG_CLK_SEL_NONE                 = 7,     /*!< NONE : NONE                                                               */
} TIM_CFG_CLK_SEL_Enum;

/* ==================================================  TIM CFG MOD [0..3]  =================================================== */
typedef enum {                                  /*!< TIM_CFG_MOD                                                               */
  TIM_CFG_MOD_NONE                     = 0,     /*!< NONE : NONE                                                               */
  TIM_CFG_MOD_SD                       = 1,     /*!< SD : SD                                                                   */
  TIM_CFG_MOD_DIV_SAW_UP               = 2,     /*!< DIV_SAW_UP : DIV_SAW_UP                                                   */
  TIM_CFG_MOD_MUL_SAW_UP               = 3,     /*!< MUL_SAW_UP : MUL_SAW_UP                                                   */
  TIM_CFG_MOD_DIV_SAW_DOWN             = 4,     /*!< DIV_SAW_DOWN : DIV_SAW_DOWN                                               */
  TIM_CFG_MOD_MUL_SAW_DOWN             = 5,     /*!< MUL_SAW_DOWN : MUL_SAW_DOWN                                               */
  TIM_CFG_MOD_DIV_TRI                  = 6,     /*!< DIV_TRI : DIV_TRI                                                         */
  TIM_CFG_MOD_MUL_TRI                  = 7,     /*!< MUL_TRI : MUL_TRI                                                         */
} TIM_CFG_MOD_Enum;

/* ========================================================  INT_STS  ======================================================== */


/* =========================================================================================================================== */
/* ================                                           TRNG                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* =========================================================  DATA  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           UART                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  DATA  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
/* ===============================================  UART CFG STOP_BITS [5..5]  =============================================== */
typedef enum {                                  /*!< UART_CFG_STOP_BITS                                                        */
  UART_CFG_STOP_BITS_ONE               = 0,     /*!< ONE : ONE                                                                 */
  UART_CFG_STOP_BITS_TWO               = 1,     /*!< TWO : TWO                                                                 */
} UART_CFG_STOP_BITS_Enum;

/* ===============================================  UART CFG WORD_LEN [2..4]  ================================================ */
typedef enum {                                  /*!< UART_CFG_WORD_LEN                                                         */
  UART_CFG_WORD_LEN_8                  = 0,     /*!< 8 : 8                                                                     */
  UART_CFG_WORD_LEN_9                  = 1,     /*!< 9 : 9                                                                     */
  UART_CFG_WORD_LEN_5                  = 5,     /*!< 5 : 5                                                                     */
  UART_CFG_WORD_LEN_6                  = 6,     /*!< 6 : 6                                                                     */
  UART_CFG_WORD_LEN_7                  = 7,     /*!< 7 : 7                                                                     */
} UART_CFG_WORD_LEN_Enum;

/* ==================================================  UART CFG BRG [0..1]  ================================================== */
typedef enum {                                  /*!< UART_CFG_BRG                                                              */
  UART_CFG_BRG_NONE                    = 0,     /*!< NONE : NONE                                                               */
  UART_CFG_BRG_TIM0                    = 1,     /*!< TIM0 : TIM0                                                               */
  UART_CFG_BRG_TIM1                    = 2,     /*!< TIM1 : TIM1                                                               */
  UART_CFG_BRG_TIM2                    = 3,     /*!< TIM2 : TIM2                                                               */
} UART_CFG_BRG_Enum;

/* ==========================================================  STS  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            WUT                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CFG  ========================================================== */
/* ==========================================================  STS  ========================================================== */
/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PER  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           WDOG                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  LOAD  ========================================================== */
/* ==========================================================  VAL  ========================================================== */
/* ==========================================================  CFG  ========================================================== */
/* ======================================================  INT_STS_RAW  ====================================================== */
/* ========================================================  INT_STS  ======================================================== */
/* =========================================================  LOCK  ========================================================== */
/* =======================================================  TEST_CFG  ======================================================== */
/* =======================================================  TEST_OUT  ======================================================== */


/* =========================================================================================================================== */
/* ================                                           MISC                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  SCRATCH  ======================================================== */
/* =========================================================  TRIM  ========================================================== */
/* ========================================================  REV_ID  ========================================================= */
/* =========================================================  LOCK  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            MTB                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  POSITION  ======================================================== */
/* ========================================================  MASTER  ========================================================= */
/* =========================================================  FLOW  ========================================================== */
/* =========================================================  BASE  ========================================================== */

/** @} */ /* End of group EnumValue_peripherals */


#ifdef __cplusplus
}
#endif

#endif /* AXM0_H */

/** @} */ /* End of group ON Semiconductor */
