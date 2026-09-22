/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer
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

#include "cpu.h"
#include "libmfadc.h"

#if defined __ARMEL__ || defined __ARMEB__
#define ADCCALG00GAIN0  SFRX(0x7030)   /* ADC Calibration Range 00 Gain Low Byte */
#define ADCCALG00GAIN1  SFRX(0x7031)   /* ADC Calibration Range 00 Gain High Byte */
#define ADCCALG01GAIN0  SFRX(0x7032)   /* ADC Calibration Range 01 Gain Low Byte */
#define ADCCALG01GAIN1  SFRX(0x7033)   /* ADC Calibration Range 01 Gain High Byte */
#define ADCCALG10GAIN0  SFRX(0x7034)   /* ADC Calibration Range 10 Gain Low Byte */
#define ADCCALG10GAIN1  SFRX(0x7035)   /* ADC Calibration Range 10 Gain High Byte */
#define ADCCALTEMPGAIN0 SFRX(0x7038)   /* ADC Calibration Temperature Gain Low Byte */
#define ADCCALTEMPGAIN1 SFRX(0x7039)   /* ADC Calibration Temperature Gain High Byte */
#define ADCCALTEMPOFFS0 SFRX(0x703A)   /* ADC Calibration Temperature Offset Low Byte */
#define ADCCALTEMPOFFS1 SFRX(0x703B)   /* ADC Calibration Temperature Offset High Byte */
#else
SFRX(ADCCALG00GAIN0,  0x7030)   /* ADC Calibration Range 00 Gain Low Byte */
SFRX(ADCCALG00GAIN1,  0x7031)   /* ADC Calibration Range 00 Gain High Byte */
SFRX(ADCCALG01GAIN0,  0x7032)   /* ADC Calibration Range 01 Gain Low Byte */
SFRX(ADCCALG01GAIN1,  0x7033)   /* ADC Calibration Range 01 Gain High Byte */
SFRX(ADCCALG10GAIN0,  0x7034)   /* ADC Calibration Range 10 Gain Low Byte */
SFRX(ADCCALG10GAIN1,  0x7035)   /* ADC Calibration Range 10 Gain High Byte */
SFRX(ADCCALTEMPGAIN0, 0x7038)   /* ADC Calibration Temperature Gain Low Byte */
SFRX(ADCCALTEMPGAIN1, 0x7039)   /* ADC Calibration Temperature Gain High Byte */
SFRX(ADCCALTEMPOFFS0, 0x703A)   /* ADC Calibration Temperature Offset Low Byte */
SFRX(ADCCALTEMPOFFS1, 0x703B)   /* ADC Calibration Temperature Offset High Byte */
#endif

void adc_uncalibrate(void)
{
	ADCCALG00GAIN0 = 0x00;
	ADCCALG00GAIN1 = 0x40;
	ADCCALG01GAIN0 = 0x00;
	ADCCALG01GAIN1 = 0x40;
	ADCCALG10GAIN0 = 0x00;
	ADCCALG10GAIN1 = 0x40;
	ADCCALTEMPGAIN0 = 0x00;
	ADCCALTEMPGAIN1 = 0x40;
	ADCCALTEMPOFFS0 = 0x00;
	ADCCALTEMPOFFS1 = 0x00;
}
