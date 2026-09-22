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

#ifdef __AXM0

__reentrantb int16_t adc_measure_temperature(void) __reentrant
{
	/* FIXME - calibration */
	ADC->CFG = 0x00071000;
	ADC->CTL = 0x00000044; /* clear sequence */
	ADC->CTL = 0x00000005; /* start one shot */
	while (ADC->CTL & 0x00000001);
	int16_t ret = ADC->DATA & 0xFFFF;
	/* FIXME - conversion to degree */
	return ret;
}

#endif

#ifdef __AXM0F2

static __reentrantb int32_t convert_dietemp(int32_t adcCounts) __reentrant
{
	static const int32_t SAR_TEMP_OFFSET_MULT       = 0x400;
	static const int32_t DUAL_SLOPE_CORRECTION      = 0xF0000;  /* 15 in Q16.16 format */
	static const int32_t SCALE_ADJUSTMENT           = 8;        /* (effectively 0.5 << 4u) 0.5 in Q28.4 format */
	static const int32_t HIGH_TEMPERATURE           = 0x640000; /* 100 in Q16.16 format */
	static const int32_t LOW_TEMPERATURE            = 0x280000; /* 40 in Q16.16 format */
	static const int32_t SCALE_ADJUSTMENT_DIVIDER   = 16u;
	static const int32_t SAR_TEMP_DIVIDER           = 0x10000;
	static const int32_t HALF_OF_ONE                = 0x00008000;
	int32_t offsetReg = (int16_t)SFLASH->SAR_TEMP_OFFSET;
	int32_t multReg   = (int16_t)SFLASH->SAR_TEMP_MULTIPLIER;
	/* Calculate tInitial in Q16.16 */
 	int32_t tInitial = (adcCounts * multReg) + (offsetReg * SAR_TEMP_OFFSET_MULT);
	int32_t tAdjust;
	if (tInitial >= DUAL_SLOPE_CORRECTION) {
		/* Shift (100 - tInitial) by 4 bits to prevent scale-adjustment from overflowing. */
		/* Then divide by the integer bits of (100 - cutoff) to end up with a Q16.16 tAdjust */
		tAdjust = (SCALE_ADJUSTMENT * ((HIGH_TEMPERATURE - tInitial) / SCALE_ADJUSTMENT_DIVIDER)) /
			((HIGH_TEMPERATURE - DUAL_SLOPE_CORRECTION) / SAR_TEMP_DIVIDER);
	} else {
		/* Shift (40 + tInitial) by 4 bits to prevent scale-adjustment from overflowing. */
		/* Then divide by the integer bits of (40 + cutoff) to end up with a Q16.16 tAdjust */
		tAdjust = (SCALE_ADJUSTMENT * ((LOW_TEMPERATURE + tInitial) / SCALE_ADJUSTMENT_DIVIDER)) /
			((LOW_TEMPERATURE + DUAL_SLOPE_CORRECTION) / SAR_TEMP_DIVIDER);
	}

	/* Add tInitial + tAdjust + 0.5 to round to nearest int. Shift off excess frac bits, and return. */
	/* return format is Q8.8 */
	return (tInitial + tAdjust + HALF_OF_ONE) >> 8;
}

__reentrantb int16_t adc_measure_temperature(void) __reentrant
{
	SAR->CHAN_EN = 0;
	SAR->CTRL |= (0x00000040 |   /* internal VREF */
		          0x00000000 |  /* VSSA_KELVIN negative connection */
		          0x00002000 |  /* HW control neg VREF */
		          0x00000000 |  /* normal power */
		          0x10000000 |  /* DSI sync */
                  0x00000000) | /* normal switch mode */
                ((SAR->PUMP_CTRL >> 11) & 0x00100000); /* Enable the SAR internal pump when global pump is enabled */
	SAR->SAMPLE_CTRL = (0x00000008 | /* Differential Signed result */
                        0x00000004 | /* Single Ended Signed result */
                        0x00000000 | /* Right Alignment */
                        0x00000000 | /* alt resolution 8bits */
                        0x00000000 | /* average count */
                        0x00000080 | /* shift after averaging */
                        0x00000000 | /* no DSI trigger, free running */
                        0x80000000); /* DSI out enable */
	SAR->RANGE_THRES = 0x07FF0000;
	SAR->RANGE_COND  = 0x00000000;
	SAR->SAMPLE_TIME01 = 0x00020006; /* Sample time ~3.44 us or 5.5 cycle */
	SAR->SAMPLE_TIME23 = 0x00020006;

	/* Connect Vm to VSSA when even one channel is single-ended or multiple channels configured */
    SAR->MUX_SWITCH0 |= 0x00010000;

    /* Set MUX_HW_CTRL_VSSA in MUX_SWITCH_HW_CTRL when multiple channels enabled */
	SAR->MUX_SWITCH_HW_CTRL |= 0x00010000;

	SAR->SATURATE_INTR_MASK = 0;
	SAR->RANGE_INTR_MASK = 0;
	SAR->INTR_MASK = 0x00000011; /* EOS and INJ EOC */

	/* Read and modify default configuration based on characterization */
	SAR->DFT_CTRL = (SAR->DFT_CTRL & ~0x20000000) | 0x00000001;

	SAR->INJ_CHAN_CONFIG = (0x00000070 | /* SARMUX_VIRT port */
				0x40000000 | /* Tailgating */
				0x80000000); /* Enable */

	if (!(SAR->CTRL & 0x80000000)) {
		while (SAR->STATUS & 0x80000000);
		SAR->CTRL |= 0x80000000;
		delay(10);
	}

	SAR->INTR = 0x000000FF;

	/* start conversion */
	SAR->START_CTRL = 1;
	while (!(SAR->INTR & 0x00000010));

    /* Clear interrupt */
	SAR->INTR = 0x00000011;

	int16_t ret = SAR->INJ_RESULT & 0xFFFF;
	return convert_dietemp(ret);
}

#endif

#else

#if defined(SDCC)

__reentrantb int16_t adc_measure_temperature(void) __reentrant
{
	__asm
	clr	a
	mov	b,_IE
	mov	_IE,a
	mov	r0,_EIE
	mov	_EIE,a
	mov	r1,_E2IE
	mov	_E2IE,a

	mov	dptr,#_ADCTUNE0
	mov	a,#0x01
	movx	@dptr,a
	inc	dptr
	mov	a,#0x06
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	mov	r2,a
	clr	a
	movx	@dptr,a

	mov	r3,_ADCCLKSRC
	mov	_ADCCLKSRC,#0x30

	mov	r4,_ADCCH0CONFIG
	mov	_ADCCH0CONFIG,#0xd8
	mov	r5,_ADCCH1CONFIG
	mov	_ADCCH1CONFIG,#0xd8
	mov	r6,_ADCCH2CONFIG
	mov	_ADCCH2CONFIG,#0xd8
	mov	r7,_ADCCH3CONFIG
	mov	_ADCCH3CONFIG,#0xd8

	mov	_ADCCONV,#0x01
	setb	_EIE_6
00000$:	mov	a,_ADCCONV
	jb	acc.7,00001$
	mov	a,_PCON
	anl	a,#0x0c
	orl	a,#0x01
	mov	_PCON,a
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	sjmp	00000$
00001$:	;; restore registers
	mov	_ADCCH0CONFIG,r4
	mov	_ADCCH1CONFIG,r5
	mov	_ADCCH2CONFIG,r6
	mov	_ADCCH3CONFIG,r7

	mov	_ADCCLKSRC,r3

	mov	dptr,#_ADCTUNE2
	mov	a,r2
	movx	@dptr,a

	mov	_EIE,r0
	mov	_E2IE,r1

	mov	dptr,#_ADCCH1VAL0
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a

	mov	_IE,b

	;; compute median

	;; A=R5:R4 - R3:R2
	mov	a,r4
	clr	c
	subb	a,r2
	mov	a,r5
	subb	a,r3
	jnb	acc.7,00010$
	;; if R3:R2 > R5:R4, swap
	mov	a,r2
	xch	a,r4
	mov	r2,a
	mov	a,r3
	xch	a,r5
	mov	r3,a
00010$:
	;; A=R7:R6 - R5:R4
	mov	a,r6
	clr	c
	subb	a,r4
	mov	a,r7
	subb	a,r5
	jnb	acc.7,00011$
	;; if R5:R4 > R7:R6, swap
	mov	a,r4
	xch	a,r6
	mov	r4,a
	mov	a,r5
	xch	a,r7
	mov	r5,a
00011$:
	;; A=R5:R4 - R3:R2
	mov	a,r4
	clr	c
	subb	a,r2
	mov	a,r5
	subb	a,r3
	jnb	acc.7,00012$
	;; if R3:R2 > R5:R4, swap
	mov	a,r2
	xch	a,r4
	mov	r2,a
	mov	a,r3
	xch	a,r5
	mov	r3,a
00012$:

	;; return is in R5:R4
	mov	dpl,r4
	mov	dph,r5
	__endasm;
}

#else

// returns 256*temperature [deg]
// median of ADC channels 1,2 and 3 is used.
// Note: MCU is put in standby mode with all interrupts disabled during conversion!

__reentrantb int16_t adc_measure_temperature(void) __reentrant
{
	int16_t t1, t2, t3;
	{
		uint8_t ie_save = IE;
		uint8_t eie_save = EIE;
		uint8_t e2ie_save = E2IE;
		uint8_t tune2save, clksrcsave, ch0cfgsave, ch1cfgsave, ch2cfgsave, ch3cfgsave;
		IE = 0;
		EIE = 0;
		E2IE = 0;

		ADCTUNE0 = 0x01;
		ADCTUNE1 = 0x06;
		tune2save = ADCTUNE2;
		ADCTUNE2 = 0x00;

		clksrcsave = ADCCLKSRC;
		ADCCLKSRC = 0x30;

		// configure all channels for TEMP
		ch0cfgsave = ADCCH0CONFIG;
		ADCCH0CONFIG = 0xD8;
		ch1cfgsave = ADCCH1CONFIG;
		ADCCH1CONFIG = 0xD8;
		ch2cfgsave = ADCCH2CONFIG;
		ADCCH2CONFIG = 0xD8;
		ch3cfgsave = ADCCH3CONFIG;
		ADCCH3CONFIG = 0xD8;

		ADCCONV = 0x01;
		EIE_6 = 1;
		for (;;) {
			if (ADCCONV & 0x80)
				break;
			enter_standby();
		}

		t1 = ADCCH1VAL1;
		t1 <<= 8;
		t1 |= ADCCH1VAL0;

		t2 = ADCCH2VAL1;
		t2 <<= 8;
		t2 |= ADCCH2VAL0;

		t3 = ADCCH3VAL1;
		t3 <<= 8;
		t3 |= ADCCH3VAL0;

		ADCCH0CONFIG = ch0cfgsave;
		ADCCH1CONFIG = ch1cfgsave;
		ADCCH2CONFIG = ch2cfgsave;
		ADCCH3CONFIG = ch3cfgsave;
		ADCCLKSRC = clksrcsave;
		ADCTUNE2 = tune2save;

		E2IE = e2ie_save;
		EIE = eie_save;
		IE = ie_save;

	}
	// compute median
	if (t1 > t2) {
		int16_t x = t1;
		t1 = t2;
		t2 = x;
	}
	if (t2 > t3) {
		int16_t x = t2;
		t2 = t3;
		t3 = x;
	}
	if (t1 > t2) {
		int16_t x = t1;
		t1 = t2;
		t2 = x;
	}
	return t2;
}

#endif

#endif
