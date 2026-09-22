/**
******************************************************************************
* @file axm0_config.h
* @brief AXM0 configuration macro definitions
* @internal
* @author   Pradeep Kumar G R, Radhika R
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
* @ingroup CONFIG
*
* @details
*/


#ifndef AXM0_CONFIG_H
#define AXM0_CONFIG_H
#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0
#define AXM0_STATUS_SUCCESS 				0
#define AXM0_STATUS_FAIL 					1
#define AXM0_STATUS_INVALID_PARAMETER 		2
#define AXM0_CONFIG_SYSCLK_HSOSC            0x103800
#define AXM0_CONFIG_SYSCLK_LPOSC            0x103401
#define AXM0_CONFIG_SYSCLK_HSXTAL           0x102C02
#define AXM0_CONFIG_SYSCLK_LPXTAL           0x101C03
#define AXM0_CONFIG_SYSCLK_RSYSCLK          0x103804
#define AXM0_CONFIG_HSCLK_20M               0x80
#define AXM0_CONFIG_HSCLK_16M               0x0
#define AXM0_CONFIG_LPCLK_10K               0x41
#define AXM0_CONFIG_LPCLK_640               0x1
#define AXM0_CONFIG_XBAR_LPXTAL             0xFFFCCFFF
#define AXM0_CONFIG_XBAR_LPXTAL_PD          0xFFFFFFE7
#define AXM0_FREQ_HSOSC_16M                 16000000UL
#define AXM0_FREQ_HSOSC_20M                 20000000UL
#define AXM0_FREQ_LPOSC_640                 640
#define AXM0_FREQ_LPOSC_10K                 10240UL
#define AXM0XX_HFCLK_CLOCK_FREQ             20000000UL
#define AXM0_FREQ_LPXOSC_32K                32768UL
#define AXM0_FREQ_RSYS_20M                  20000000UL
#endif /* __AXM0 */

#ifdef __AXM0F2
#define AXM0_STATUS_SUCCESS					0x0
#define AXM0_STATUS_FAIL					0x1
#define AXM0_STATUS_INVALID_PARAMETER		0x2
#define LIBMF_I2C_BUS_ERROR					0x3	    /* Bus Error */
#define LIBMF_I2C_ARB_LOST					0x4	    /* Arbitration Lost */
#define AXM0_STATUS_IN_PROGRESS				0x5
#define AXM0_STATUS_NO_INIT 				0x6     /* Module not initialized */

/* Peripheral initialization status */
#define AXM0_PERI_NOT_INITIALIZED           0x0
#define AXM0_PERI_INITIALIZED               0x1

#define AXM0XX_HFCLK_CLOCK_FREQ				48000000UL
#define AXM0_FREQ_LPOSC_40K					40000UL
#define AXM0_FREQ_LPXOSC_32K                32768UL

#define SCB_HANDLER_SPI						0
#define SCB_HANDLER_UART					1
#define SCB_HANDLER_I2C						2

#define SET_BIT_FIELDS(reg, mask, val) (reg = ((reg & ~mask) | val));
#endif /* __AXM0F2 */

#endif /* __ARMEL__ || defined __ARMEB__ */

#endif /* AXM0_CONFIG_H */
