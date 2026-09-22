/**
******************************************************************************
* @file pwm.h
* @brief PWM APIs declararion
* @internal
* @author   Sai Pramod Kumar D
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
* @ingroup PWM
*
* @details
*/

#ifndef PWM_H
#define PWM_H

#include "cpu.h"
#include "libmftypes.h"
#include "axm0_config.h"
#include "libmfwtimer.h"
#include "libmfpwm.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#define PWM_4BIT_MASK          0xF
#define PWM_8BIT_MASK          0xFF
#define PWM_16BIT_MASK         0xFFFF
#define PWM_MIN_PERIOD_TIME    3
#define PWM_MAX_PERIOD_TIME    174500
#define PWM_MIN_PERIOD_COUNT   1
#define PWM_MAX_PERIOD_COUNT   65535
#define PWM_MIN_DUTYCYCLE      0
#define PWM_MAX_DUTYCYCLE      100
#define PWM_TCPWM_1_SELECT     0x2
#define PWM_TCPWM_2_SELECT     0x4
#define PWM_TCPWM_3_SELECT     0x8
#define AXM0F2_DIV_CTL_ADRS_OFFSET (uint32_t)(0x300/4)
#define AXM0F2_PCLK_CTL_ADRS_OFFSET (uint32_t)(0x110/4)

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */

#endif /* PWM_H */
