/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer and Sai Pramod Kumar D
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

#ifndef LIBMFADC_H
#define LIBMFADC_H

#include "libmftypes.h"

/*
 * AD Converter
 */
extern __reentrantb int16_t adc_measure_temperature(void) __reentrant;


extern void adc_calibrate_gain(void);
extern void adc_calibrate_temp(void);
extern void adc_calibrate(void);
extern void adc_uncalibrate(void);
extern uint16_t adc_singleended_offset_x01(void);
extern uint16_t adc_singleended_offset_x1(void);
extern uint16_t adc_singleended_offset_x10(void);

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

/**
 *
 * Description: ADC initialization
 *
 * Input:
 *      positive_input - ADC_TEMPERATURE_MEASUREMENT        : Negative input will be ignored
 *                       PKG_PIN_NUM_01 to PKG_PIN_NUM_40   : Definitions @ axm0f2_pin.h
 *      negative_input - PKG_PIN_GROUND                     : Single Ended
 *                       PKG_PIN_NUM_01 to PKG_PIN_NUM_40   : Differential
 *      conv_mode - LIBMF_ADC_ONESHOT and LIBMF_ADC_CONTINUOUS
 *      ref_input - LIBMF_ADC_VREF_INTERNAL  : 1.2V Internal
 *                  LIBMF_ADC_VREF_VDD_BY_2  : 1.5V Internal
 *                  LIBMF_ADC_VREF_VDD       : 3V Internal
 *                  LIBMF_ADC_VREF_EXTERNAL  : Voltage supplied to pin 1.7(PKG_PIN_NUM_35)
 *      ext_vref -  External reference input  voltage in millivolts from 0 to 3300
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t adc_init(uint8_t positive_input, uint8_t negative_input, uint8_t conv_mode, uint8_t ref_input, uint16_t ext_vref);

/**
 *
 * Description: Start ADC Measurement
 *
 * Input - adc_reading : Holds pointer to read ADC value
 *
 * Output: Returns nothing
 *
 */
extern void adc_start_measurement(void);

/**
 *
 * Description: Disable ADC Module
 *
 * Input: No Passing Parameter
 *
 * Output: Returns nothing
 *
 */
extern void adc_close(void);

/**
 *
 * Description: Start ADC Measurement
 *
 * Input - adcCounts : 11 Bit Signed ADC digital value
 *
 * Output: Returns voltage in millivolts(mV)
 *
 */
extern int16_t adc_result_in_mVolts(int16_t adcCounts);

/**
 *
 * Description: Start ADC Measurement
 *
 * Input - adcCounts : 11 Bit Signed ADC digital value
 *
 * Output: Returns Temperature in celsius
 *
 */
extern int32_t adc_convert_dietemp(int32_t adcCounts);

/**
 *
 * Description: ADC get Result
 *
 * Input: nothing
 *
 * Output: Returns ADC Count
 *
 */
extern int16_t adc_get_result(void);

/**
 *
 * Description: ADC get status
 *
 * Input: nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t adc_getstatus();

/**
 *
 * Description: ADC wait until done - Wait in  standby mode till ADC is done with measurement
 *
 * Input: Nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t adc_wait_until_done();

#define LIBMF_ADC_VREF_INTERNAL      0
#define LIBMF_ADC_VREF_VDD_BY_2      1
#define LIBMF_ADC_VREF_VDD           2
#define LIBMF_ADC_VREF_EXTERNAL      3

#define LIBMF_ADC_CONTINUOUS        0
#define LIBMF_ADC_ONESHOT           1

#define ADC_TEMPERATURE_MEASUREMENT		    0xF1
#define ADC_VDDIO_MEASUREMENT			    0xF2

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */

#endif /* LIBMFADC_H */
