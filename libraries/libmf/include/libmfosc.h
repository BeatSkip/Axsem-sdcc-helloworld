/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a �ON Semiconductor�).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (�ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software�) and
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

#ifndef LIBMFOSC_H
#define LIBMFOSC_H

#include "libmftypes.h"

extern __reentrantb void turn_off_xosc(void) __reentrant;
extern __reentrantb void turn_off_lpxosc(void) __reentrant;

extern uint8_t wtimer0_clksrc, wtimer1_clksrc, wtimer1_prescaler;

extern __reentrantb uint32_t wtimer0_correctinterval(uint32_t intvl) __reentrant;
extern __reentrantb uint32_t wtimer1_correctinterval(uint32_t intvl) __reentrant;

#if defined SDCC
#pragma callee_saves setup_xosc,setup_lpxosc
#endif
extern __reentrantb void setup_xosc(void) __reentrant;
extern __reentrantb void setup_lpxosc(void) __reentrant;

extern __reentrantb uint8_t setup_osc_calibration(uint32_t reffreq, uint8_t refosc) __reentrant;

/*
 * Clock Sources
 */
#define CLKSRC_FRCOSC   0
#define CLKSRC_LPOSC    1
#define CLKSRC_XOSC     2
#define CLKSRC_LPXOSC   3
#define CLKSRC_RSYSCLK  4
#define CLKSRC_TCLK     5
#define CLKSRC_SYSCLK   6
#define CLKSRC_OFF      7

#if defined(__ICC8051__)

#define __osc_set_frcoscref(x) do { FRCOSCREF0 = (x); FRCOSCREF1 = (x) >> 8; } while(0)
#define __osc_set_lposcref(x)  do { LPOSCREF0 = (x); LPOSCREF1 = (x) >> 8; } while(0)
#define __osc_set_filt()       do { FRCOSCKFILT0 = 0x00; FRCOSCKFILT1 = 0x40; LPOSCKFILT0 = 0x00; LPOSCKFILT1 = 0x40; } while(0)

#elif (defined __ARMEL__ || defined __ARMEB__)

#ifdef AXM0_H
#define __osc_set_frcoscref(x) do { CMU->HS_OSC_REF_DIV = (0x1300); } while(0)
#define __osc_set_lposcref(x)  do { CMU->LP_OSC_REF_DIV = (0x4F80); } while(0)
#define __osc_set_filt()       do { CMU->HS_OSC_FILT = 0x4000; CMU->LP_OSC_FILT = 0x4000; } while(0)
#endif

#ifdef AXM0F2_H
#define __osc_set_frcoscref(x) do {  } while(0)
#define __osc_set_lposcref(x)  do {  } while(0)
#define __osc_set_filt()       do {  } while(0)
#endif

/* Input parameter clk_freq: 0 for 16 MHz, 1 for 20 MHz */
extern void axm0_calib_hs_osc(uint8_t clk_freq);

#ifdef __AXM0F2

#define AXM0F2_VTCXO_PIN GPIO_PIN_P00 /* Pin 0.0 used as VTCXO */

#endif /* __AXM0F2 */

#else /* All other compiler */

#define __osc_set_frcoscref(x) do { FRCOSCREF = (x); } while(0)
#define __osc_set_lposcref(x)  do { LPOSCREF = (x); } while(0)
#define __osc_set_filt()       do { FRCOSCKFILT = 0x4000; LPOSCKFILT = 0x4000; } while(0)

#endif

#if (defined __ARMEL__ || defined __ARMEB__)
#ifdef __AXM0

#define setup_osc_calibration_const(reffreq,refosc)				\
do {										\
	uint8_t ret = 0;							\
	uint8_t lposccfg;							\
	uint8_t frcosccfg;							\
	if ((reffreq) >= 32768000UL) {						\
		frcosccfg = 0;							\
		ret |= 1;							\
	} else if ((reffreq) >= 16384000UL) {					\
		frcosccfg = 0x78 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 7));	\
	} else if ((reffreq) >= 8192000UL) {					\
		frcosccfg = 0x70 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 6));	\
	} else if ((reffreq) >= 4096000UL) {					\
		frcosccfg = 0x68 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 5));	\
	} else if ((reffreq) >= 2048000UL) {					\
		frcosccfg = 0x60 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 4));	\
	} else if ((reffreq) >= 1024000UL) {					\
		frcosccfg = 0x58 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 3));	\
	} else if ((reffreq) >= 512000UL) {					\
		frcosccfg = 0x50 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 2));	\
	} else if ((reffreq) >= 256000UL) {					\
		frcosccfg = 0x48 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 1));	\
	} else if ((reffreq) >= 128000UL) {					\
		frcosccfg = 0x40 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / (reffreq));		\
	} else if ((reffreq) >= 64000UL) {					\
		frcosccfg = 0x38 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 7) / (reffreq));		\
	} else if ((reffreq) >= 32000UL) {					\
		frcosccfg = 0x30 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 6) / (reffreq));		\
	} else if ((reffreq) >= 16000UL) {					\
		frcosccfg = 0x28 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 5) / (reffreq));		\
	} else if ((reffreq) >= 8000UL) {					\
		frcosccfg = 0x20 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 4) / (reffreq));		\
	} else if ((reffreq) >= 4000UL) {					\
		frcosccfg = 0x18 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 3) / (reffreq));		\
	} else if ((reffreq) >= 2000UL) {					\
		frcosccfg = 0x10 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 2) / (reffreq));		\
	} else if ((reffreq) >= 1000UL) {					\
		frcosccfg = 0x08 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 1) / (reffreq));		\
	} else if ((reffreq) >= 500UL) {					\
		frcosccfg = 0x00 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 0) / (reffreq));		\
	} else {								\
		frcosccfg = 0;							\
		ret |= 1;							\
	}									\
	if ((reffreq) >= 2013265920UL || (reffreq) < 7864320UL) {		\
		lposccfg = 0x08 | CLKSRC_FRCOSC;				\
		__osc_set_lposcref(31250);					\
	} else if ((reffreq) >= 1006632960UL) {					\
		lposccfg = 0x38 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 40960UL);			\
	} else if ((reffreq) >= 503316480UL) {					\
		lposccfg = 0x30 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 20480UL);			\
	} else if ((reffreq) >= 251658240UL) {					\
		lposccfg = 0x28 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 10240UL);			\
	} else if ((reffreq) >= 125829120UL) {					\
		lposccfg = 0x20 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 5120UL);				\
	} else if ((reffreq) >= 62914560UL) {					\
		lposccfg = 0x18 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 2560UL);				\
	} else if ((reffreq) >= 31457280UL) {					\
		lposccfg = 0x10 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 1280UL);				\
	} else if ((reffreq) >= 15728640UL) {					\
		lposccfg = 0x08 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 640UL);				\
	} else {								\
		lposccfg = 0x00 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 320UL);				\
	}									\
	if (!ret) {								\
		switch (refosc) {						\
		case CLKSRC_XOSC:						\
			break;							\
										\
		case CLKSRC_LPXOSC:						\
			setup_lpxosc();						\
			break;							\
										\
		case CLKSRC_RSYSCLK:						\
			break;							\
										\
		default:							\
			ret = 2;						\
			break;							\
		}								\
		if (!ret) {							\
			__osc_set_filt();					\
			CMU->HS_OSC_CFG = 0x180 | frcosccfg;				\
			CMU->LP_OSC_CFG = 0x38 | lposccfg;					\
		}								\
	}									\
} while (0)

#endif /* __AXM0 */
#else /* AX8052 */

#define setup_osc_calibration_const(reffreq,refosc)				\
do {										\
	uint8_t ret = 0;							\
	uint8_t lposccfg;							\
	uint8_t frcosccfg;							\
	if ((reffreq) >= 32768000UL) {						\
		frcosccfg = 0;							\
		ret |= 1;							\
	} else if ((reffreq) >= 16384000UL) {					\
		frcosccfg = 0x78 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 7));	\
	} else if ((reffreq) >= 8192000UL) {					\
		frcosccfg = 0x70 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 6));	\
	} else if ((reffreq) >= 4096000UL) {					\
		frcosccfg = 0x68 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 5));	\
	} else if ((reffreq) >= 2048000UL) {					\
		frcosccfg = 0x60 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 4));	\
	} else if ((reffreq) >= 1024000UL) {					\
		frcosccfg = 0x58 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 3));	\
	} else if ((reffreq) >= 512000UL) {					\
		frcosccfg = 0x50 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 2));	\
	} else if ((reffreq) >= 256000UL) {					\
		frcosccfg = 0x48 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / ((reffreq) >> 1));	\
	} else if ((reffreq) >= 128000UL) {					\
		frcosccfg = 0x40 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 8) / (reffreq));		\
	} else if ((reffreq) >= 64000UL) {					\
		frcosccfg = 0x38 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 7) / (reffreq));		\
	} else if ((reffreq) >= 32000UL) {					\
		frcosccfg = 0x30 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 6) / (reffreq));		\
	} else if ((reffreq) >= 16000UL) {					\
		frcosccfg = 0x28 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 5) / (reffreq));		\
	} else if ((reffreq) >= 8000UL) {					\
		frcosccfg = 0x20 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 4) / (reffreq));		\
	} else if ((reffreq) >= 4000UL) {					\
		frcosccfg = 0x18 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 3) / (reffreq));		\
	} else if ((reffreq) >= 2000UL) {					\
		frcosccfg = 0x10 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 2) / (reffreq));		\
	} else if ((reffreq) >= 1000UL) {					\
		frcosccfg = 0x08 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 1) / (reffreq));		\
	} else if ((reffreq) >= 500UL) {					\
		frcosccfg = 0x00 | ((refosc) & 0x07);				\
		__osc_set_frcoscref((10000000UL << 0) / (reffreq));		\
	} else {								\
		frcosccfg = 0;							\
		ret |= 1;							\
	}									\
	if ((reffreq) >= 2013265920UL || (reffreq) < 7864320UL) {		\
		lposccfg = 0x08 | CLKSRC_FRCOSC;				\
		__osc_set_lposcref(31250);					\
	} else if ((reffreq) >= 1006632960UL) {					\
		lposccfg = 0x38 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 40960UL);			\
	} else if ((reffreq) >= 503316480UL) {					\
		lposccfg = 0x30 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 20480UL);			\
	} else if ((reffreq) >= 251658240UL) {					\
		lposccfg = 0x28 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 10240UL);			\
	} else if ((reffreq) >= 125829120UL) {					\
		lposccfg = 0x20 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 5120UL);				\
	} else if ((reffreq) >= 62914560UL) {					\
		lposccfg = 0x18 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 2560UL);				\
	} else if ((reffreq) >= 31457280UL) {					\
		lposccfg = 0x10 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 1280UL);				\
	} else if ((reffreq) >= 15728640UL) {					\
		lposccfg = 0x08 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 640UL);				\
	} else {								\
		lposccfg = 0x00 | ((refosc) & 0x07);				\
		__osc_set_lposcref((reffreq) / 320UL);				\
	}									\
	if (!ret) {								\
		switch (refosc) {						\
		case CLKSRC_XOSC:						\
			setup_xosc();						\
			OSCFORCERUN |= 0x04;					\
			break;							\
										\
		case CLKSRC_LPXOSC:						\
			setup_lpxosc();						\
			OSCFORCERUN |= 0x08;					\
			break;							\
										\
		case CLKSRC_RSYSCLK:						\
			break;							\
										\
		default:							\
			ret = 2;						\
			break;							\
		}								\
		if (!ret) {							\
			__osc_set_filt();					\
			FRCOSCCONFIG = frcosccfg;				\
			LPOSCCONFIG = lposccfg;					\
		}								\
	}									\
} while (0)

#endif

#endif /* LIBMFOSC_H */
