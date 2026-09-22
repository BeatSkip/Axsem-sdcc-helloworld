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
#define ADCCALG01GAIN0  SFRX(0x7032)   /* ADC Calibration Range 01 Gain Low Byte */
#define ADCCALG01GAIN1  SFRX(0x7033)   /* ADC Calibration Range 01 Gain High Byte */
#else
SFRX(ADCCALG01GAIN0,  0x7032)   /* ADC Calibration Range 01 Gain Low Byte */
SFRX(ADCCALG01GAIN1,  0x7033)   /* ADC Calibration Range 01 Gain High Byte */
SFR16LEX(ADCCALG01GAIN, 0x7032) /* ADC Calibration Range 01 Gain */
#endif

uint16_t adc_singleended_offset_x1(void)
{
#if defined(SDCC)
	uint16_t __autodata cal = ADCCALG01GAIN;
#else
	uint16_t __autodata cal = (((uint16_t)ADCCALG01GAIN1) << 8) | ADCCALG01GAIN0;
#endif
	uint16_t __autodata sum = 0x8000;
	cal <<= 1;
	sum += cal;
	cal >>= 5;
	sum += cal;
	cal >>= 4;
	sum += cal;
	cal >>= 4;
	sum -= cal;
	return sum;
}
