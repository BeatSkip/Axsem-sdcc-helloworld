/**
******************************************************************************
* @file
* @brief
* @internal
* @author Sai Pramod Kumar D
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

#ifndef LIBMFPWM_H
#define LIBMFPWM_H

#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

/**
 *	Description: PWM initialization
 *
 *	Input:
 * 	sel_pwm -   LIBMF_PWM_1
 * 				LIBMF_PWM_2
 * 				LIBMF_PWM_3
 *
 * 	pwm_pin -   PKG_PIN_NUM_14 (P3.2) for LIBMF_PWM_1
 * 				PKG_PIN_NUM_30 (P1.0) for LIBMF_PWM_2
 *				PKG_PIN_NUM_32 (P1.2) for LIBMF_PWM_3
 * 				PKG_PIN_NUM_16 (P3.6) for LIBMF_PWM_3
 *
 * 	pwm_type - 	LIBMF_PWM_LEFT_ALIGNED
 *				LIBMF_PWM_RIGHT_ALIGNED
 * 				LIBMF_PWM_CENTER_ALIGNED
 *				LIBMF_PWM_ASSYMETRIC_ALIGNED
 *
 *	pwm_period -     Period in Micro Seconds
 *
 *	pwm_dutycycle -  Percentage of pwm_period (0 to 100)%
 *
 *  sel_div - Integer divider number to be selected (0 to 5)
 *
 * 	Return:
 * 	status -	AXM0_STATUS_SUCCESS
 * 				AXM0_STATUS_INVALID_PARAMETER
 *
 */
extern uint8_t pwm_init(uint8_t sel_pwm ,uint8_t pwm_pin, uint8_t pwm_type, uint32_t pwm_period, uint8_t pwm_dutycycle, uint8_t sel_div);

/**
 *	Description: PWM Set Dutycycle
 *
 *	Input:
 * 	sel_pwm -   LIBMF_PWM_1
 * 				LIBMF_PWM_2
 * 				LIBMF_PWM_3
 *
 *	pwm_dutycycle -  Percentage of pwm_period (0 to 100)%
 *
 * 	Return:
 * 	status -	AXM0_STATUS_SUCCESS
 * 			    AXM0_STATUS_NO_INIT
 * 				AXM0_STATUS_INVALID_PARAMETER
 *
 */
extern uint8_t pwm_dutycycle(uint8_t sel_pwm, uint8_t pwm_dutycycle);

/**
 *	Description: PWM Start the counter
 *
 *	Input:
 * 	sel_pwm -   LIBMF_PWM_1
 * 				LIBMF_PWM_2
 * 				LIBMF_PWM_3
 *
 * 	Return:
 * 	status -	AXM0_STATUS_SUCCESS
 * 			    AXM0_STATUS_NO_INIT
 * 				AXM0_STATUS_INVALID_PARAMETER
 *
 */
extern uint8_t pwm_start(uint8_t sel_pwm);

/**
 *	Description: PWM Stop the counter
 *
 *	Input:
 * 	sel_pwm -   LIBMF_PWM_1
 * 				LIBMF_PWM_2
 * 				LIBMF_PWM_3
 *
 * 	Return:
 * 	status -	AXM0_STATUS_SUCCESS
 * 			    AXM0_STATUS_NO_INIT
 * 				AXM0_STATUS_INVALID_PARAMETER
 *
 */
extern uint8_t pwm_stop(uint8_t sel_pwm);

/**
 *	Description: PWM Stop and Disables the counter
 *
 *	Input:
 * 	sel_pwm -   LIBMF_PWM_1
 * 				LIBMF_PWM_2
 * 				LIBMF_PWM_3
 *
 * 	Return:
 * 	status -	AXM0_STATUS_SUCCESS
 * 			    AXM0_STATUS_NO_INIT
 * 				AXM0_STATUS_INVALID_PARAMETER
 *
 */
extern uint8_t pwm_close(uint8_t sel_pwm);

#define LIBMF_PWM_0              0
#define LIBMF_PWM_1              1
#define LIBMF_PWM_2              2
#define LIBMF_PWM_3              3
#define LIBMF_PWM_4              4

#define LIBMF_PWM_LEFT_ALIGNED           0
#define LIBMF_PWM_RIGHT_ALIGNED          1
#define LIBMF_PWM_CENTER_ALIGNED         2
#define LIBMF_PWM_ASSYMETRIC_ALIGNED     3

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */

#endif /* LIBMFPWM_H */
