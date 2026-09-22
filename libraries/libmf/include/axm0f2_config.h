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


#ifndef AXM0F2_CONFIG_H
#define AXM0F2_CONFIG_H
#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__

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
#define AXM0_FREQ_XOSC_20M                  20000000UL
#define AXM0_FREQ_LPXOSC_32K                32768UL
#define AXM0_FREQ_RSYS_20M                  20000000UL

#define SCB_HANDLER_SPI     0
#define SCB_HANDLER_UART    1
#define SCB_HANDLER_I2C     2

#define SET_BIT_FIELDS(reg, mask, val) (reg = ((reg & ~mask) | val));

#endif /* __ARMEL__ || defined __ARMEB__ */

#endif /* AXM0F2_CONFIG_H */
