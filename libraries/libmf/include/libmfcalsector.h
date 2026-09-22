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

#ifndef LIBMFCALSECTOR_H
#define LIBMFCALSECTOR_H

#include "libmftypes.h"

/*
 * FLASH Calibration Sector Layout
 */

struct calsector {
	uint8_t id[5];             /* ID: 0x80, 0xFE, CAL */
	uint8_t len;               /* Length, excluding id, but including len */
	uint8_t devid[6];          /* arbitrary device ID */
	uint8_t calg00gain[2];     /* ADC x0.1 Gain Calibration */
	uint8_t calg01gain[2];     /* ADC x1 Gain Calibration */
	uint8_t calg10gain[2];     /* ADC x10 Gain Calibration */
	uint8_t caltempgain[2];    /* ADC Temperature Gain Calibration */
	uint8_t caltempoffs[2];    /* ADC Temperature Offset Calibration */
	uint8_t frcoscfreq[2];     /* Fast RC Oscillator Frequency Calibration */
	uint8_t lposcfreq[2];      /* Low Power Oscillator Frequency Calibration, Slow Mode */
        uint8_t lposcfreq_fast[2]; /* Low Power Oscillator Frequency Calibration, Fast Mode */
        uint8_t powctrl0;          /* VDD_CORE Calibration */
        uint8_t powctrl1;          /* VDD_SLEEP Calibration */
	uint8_t ref;               /* Ref Calibration */
};

#if defined(SDCC)
static struct calsector __xdata __at(0xfc00) flash_calsector;
#elif defined __CX51__ || defined __C51__
static struct calsector xdata flash_calsector _at_ 0xfc00;
#elif defined __ICC8051__
extern __no_init struct calsector __xdata flash_calsector @ 0xfc00;
#elif defined __ARMEL__ || defined __ARMEB__
extern struct calsector flash_calsector;
#endif

#endif /* LIBMFCALSECTOR_H */
