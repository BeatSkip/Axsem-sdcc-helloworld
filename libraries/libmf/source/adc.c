/**
******************************************************************************
* @file adc.c
* @brief ADC implementation
* @internal
* @author   Sai Pramod Kumar D
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a ?ON Semiconductor?).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (?ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software?) and
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
* @ingroup ADC
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#include "cpu.h"
#include "axm0f2.h"
#include "adc.h"
#include "libmfadc.h"
#include "axm0f2_pin.h"

static int32_t gAdcSarSeqCountsPer10Volt = AXM0_ADC_SAR_SEQ_COUNTS_PER_10V;
static volatile uint8_t gAdcStatus = 0;
static volatile int16_t gAdcResult;
static volatile uint8_t gOneshotContinuous = 0;
static uint8_t gAdcInitStatus = AXM0_PERI_NOT_INITIALIZED;
static volatile uint8_t gVddioVref = 0;
static volatile uint16_t gVrefResult = 0;
static volatile uint8_t gVrefStatus = 0;
static uint8_t gPositiveInput = PKG_PIN_NOT_GPIO;
static uint8_t gNegativeInput = PKG_PIN_NOT_GPIO;
static uint8_t gExternalRef = 0;

/** Function description can be found in header file */
int32_t adc_convert_dietemp(int32_t adcCounts)
{
	int32_t offsetReg = (int16_t)SFLASH->SAR_TEMP_OFFSET;
	int32_t multReg   = (int16_t)SFLASH->SAR_TEMP_MULTIPLIER;

	/* Calculate tInitial in Q16.16 */
 	int32_t tInitial = (adcCounts * multReg) + (offsetReg * AXM0_ADC_SAR_TEMP_OFFSET_MULT);
	int32_t tAdjust;
	if (tInitial >= AXM0_ADC_DUAL_SLOPE_CORRECTION) {
		/* Shift (100 - tInitial) by 4 bits to prevent scale-adjustment from overflowing. */
		/* Then divide by the integer bits of (100 - cutoff) to end up with a Q16.16 tAdjust */
		tAdjust = (AXM0_ADC_SCALE_ADJUSTMENT * ((AXM0_ADC_HIGH_TEMPERATURE - tInitial) / AXM0_ADC_SCALE_ADJUSTMENT_DIVIDER)) /
			((AXM0_ADC_HIGH_TEMPERATURE - AXM0_ADC_DUAL_SLOPE_CORRECTION) / AXM0_ADC_SAR_TEMP_DIVIDER);
	} else {
		/* Shift (40 + tInitial) by 4 bits to prevent scale-adjustment from overflowing. */
		/* Then divide by the integer bits of (40 + cutoff) to end up with a Q16.16 tAdjust */
		tAdjust = (AXM0_ADC_SCALE_ADJUSTMENT * ((AXM0_ADC_LOW_TEMPERATURE + tInitial) / AXM0_ADC_SCALE_ADJUSTMENT_DIVIDER)) /
			((AXM0_ADC_LOW_TEMPERATURE + AXM0_ADC_DUAL_SLOPE_CORRECTION) / AXM0_ADC_SAR_TEMP_DIVIDER);
	}

	/* Add tInitial + tAdjust + 0.5 to round to nearest int. Shift off excess frac bits, and return. */
	/* return format is Q8.8 */
	return (tInitial + tAdjust + AXM0_ADC_HALF_OF_ONE) >> 8;
}

/** ADC Temperature Initialization is done */
static void adc_temperature_init(void)
{

    if (!(SAR->CTRL & 0x80000000)) {
		while (SAR->STATUS & 0x80000000);
		SAR->CTRL = 0x80000000;
		delay(10);
	}

	SAR->MUX_SWITCH_CLEAR0 = 0xFFFFFFFF;

    SAR->MUX_SWITCH0 = 0x000700B0;
    SAR->MUX_SWITCH_HW_CTRL = 0x000700B0;

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

    gOneshotContinuous = 1;
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
	SAR->INTR_MASK = 0x00000010; /* EOS and INJ EOC */
	SAR->INTR = 0x000000FF;      /* Clear all SAR Interrupts */

	/* Read and modify default configuration based on characterization */
	SAR->DFT_CTRL = (SAR->DFT_CTRL & ~0x20000000) | 0x00000001;

	SAR->INJ_CHAN_CONFIG = (0x00000070 | /* SARMUX_VIRT port */
				0x40000000 | /* Tailgating */
				0x80000000); /* Enable */

    gAdcInitStatus = AXM0_PERI_INITIALIZED; /* Set ADC init status to YES */

}

static void CapSenseADC_Init(uint8_t input_pin)
{
    uint8_t port_plus = 0;
    uint8_t pin_plus = 0;
    volatile uint32_t *Port_select;

	NVIC_DisableIRQ(CSD_IRQn);

    port_plus = input_pin/8;
    pin_plus = input_pin%8;

    HSIOM->AMUX_SPLIT_CTL0 |= 0x30;

    /* Get base address of HSIOM register */
    Port_select = (volatile uint32_t*)(HSIOM);
    SET_BIT_FIELDS((*(Port_select + (port_plus * 0x40))), (0xF << (4 * pin_plus)), (0x7 << (4 * pin_plus))); //HSIOM : AMUX BUSB

    /* Get base address of GPIO register */
    Port_select = (volatile uint32_t*)(GPIO_PRT0);
    *((Port_select + (port_plus * 0x40) + 6)) |= (0x1 << pin_plus);                 //PC2
    *((Port_select + (port_plus * 0x40) + 2)) &= (~(0x7 << (pin_plus * 0x3)));      //PC
    *((Port_select + (port_plus * 0x40))) &= (~(0x1 << pin_plus));                  //DR

	/************************************
	 * Clear all registers
	 ************************************/
	CSD->SW_REFGEN_SEL = 0;
	CSD->SW_FW_TANK_SEL = 0;
	CSD->SW_DSI_SEL = 0;
	CSD->ADC_CTL = 0;
	CSD->AMBUF = 0;
	CSD->SW_SHIELD_SEL = 0;
	CSD->SW_HS_P_SEL = 0;
	CSD->SW_HS_N_SEL = 0;
	CSD->HSCMP = 0;

	/************************************
	 * Set ModClk Clock Divider
	 ************************************/
	PERI->PCLK_CTL3 = 0x45; // DIV_16_CTL5 is zero by default

	/* Sense Division, length = 6 */
	CSD->SENSE_PERIOD = (6 - 1);

	/************************************
	 * Enable CapSense Block
	 * High Power, Filter Delay = 2, Sense Enable, DSI Count Sel = ADC
	 ************************************/
	CSD->CONFIG = ((1 << AXM0_CSD_ENABLE_OFFSET)  |
		       (0 << AXM0_CSD_LP_MODE_OFFSET) |
		       (0 << AXM0_CSD_DSI_SENSE_EN_OFFSET) |
		       (1 << AXM0_CSD_SAMPLE_SYNC_OFFSET) |
		       (0 << AXM0_CSD_DSI_SAMPLE_EN_OFFSET) |
		       (1 << AXM0_CSD_DSI_COUNT_SEL_OFFSET) |
		       (0 << AXM0_CSD_CSX_DUAL_CNT_OFFSET) |
		       (0 << AXM0_CSD_MUTUAL_CAP_OFFSET) |
		       (0 << AXM0_CSD_CHARGE_MODE_OFFSET) |
		       (1 << AXM0_CSD_SENSE_EN_OFFSET)|
		       (0 << AXM0_CSD_SHIELD_DELAY_OFFSET) |
		       (2 << AXM0_CSD_FILTER_DELAY_OFFSET));

	/************************************
	 * Init IDACB
	 * Set: 37.5nA (IDAC_Lo-Range)
	 * Set: Default Value = 26 (~1200 counts for 1.2V Vref)
	 ************************************/
	CSD->IDACB = ((1 << AXM0_CSD_LEG3_EN_OFFSET) |
		      (0 << AXM0_CSD_LEG2_EN_OFFSET) |
		      (0 << AXM0_CSD_LEG1_EN_OFFSET) |
		      (0 << AXM0_CSD_RANGE_OFFSET) |
		      (0 << AXM0_CSD_DSI_CTRL_EN_OFFSET) |
		      (0 << AXM0_CSD_LEG1_MODE_OFFSET) |
		      (0 << AXM0_CSD_LEG2_MODE_OFFSET) |
		      (0 << AXM0_CSD_BAL_MODE_OFFSET) |
		      (0 << AXM0_CSD_POLARITY_OFFSET) |
		      (0 << AXM0_CSD_POL_DYN_OFFSET) |
		      (15 << AXM0_CSD_VAL_OFFSET));

	/************************************
	 * Configure Auto Zero Time
	 ************************************/
	CSD->SEQ_TIME = ((((AXM0XX_HFCLK_CLOCK_FREQ * AZ_time) / 4) / 1000000uL) - 1uL);

	CSD->CSDCMP       = 0uL; /*  */
	CSD->SW_DSI_SEL   = 0uL; /* has to be 0 */
	CSD->SENSE_DUTY   = 0uL; /* 50% duty cycle -> probably test different duty cycles? */
	CSD->SEQ_INIT_CNT = 1uL; /* Number of conversions per sample */
	CSD->SEQ_NORM_CNT = 2uL; /*  */

	/************************************
	 * CSDBUS Init
	 * Connect VDDA to csdbusb (HCBV)
	 * Connect both intern Cref to csdbusc (CnCC) and csdbusd (CnCD)
	 * connect csdbusb with csdbusc (CBCC)
	 ************************************/
	CSD->SW_SHIELD_SEL = ((0 << AXM0_CSD_SW_HCCG_OFFSET) |
			      (0 << AXM0_CSD_SW_HCCV_OFFSET) |
			      (0 << AXM0_CSD_SW_HCBG_OFFSET) |
			      (0 << AXM0_CSD_SW_HCBV_OFFSET) |
			      (0 << AXM0_CSD_SW_HCAG_OFFSET) |
			      (0 << AXM0_CSD_SW_HCAV_OFFSET));

	CSD->SW_CMP_P_SEL = ((0 << AXM0_CSD_SW_SFCB_OFFSET) |
			     (0 << AXM0_CSD_SW_SFCA_OFFSET) |
			     (0 << AXM0_CSD_SW_SFMB_OFFSET) |
			     (0 << AXM0_CSD_SW_SFMA_OFFSET) |
			     (0 << AXM0_CSD_SW_SFPS_OFFSET) |
			     (0 << AXM0_CSD_SW_SFPT_OFFSET) |
			     (0 << AXM0_CSD_SW_SFPM_OFFSET));

	CSD->SW_CMP_N_SEL = ((0 << AXM0_CSD_SW_SCRL_OFFSET) |
			     (0 << AXM0_CSD_SW_SCRH_OFFSET));

	CSD->SW_FW_MOD_SEL = ((0 << AXM0_CSD_SW_C1F1_OFFSET) |
			      (1 << AXM0_CSD_SW_C1CD_OFFSET) |
			      (1 << AXM0_CSD_SW_C1CC_OFFSET) |
			      (0 << AXM0_CSD_SW_F1CA_OFFSET) |
			      (0 << AXM0_CSD_SW_F1MA_OFFSET) |
			      (0 << AXM0_CSD_SW_F1PM_OFFSET));

	CSD->SW_FW_TANK_SEL = ((0 << AXM0_CSD_SW_C2F2_OFFSET) |
			       (1 << AXM0_CSD_SW_C2CD_OFFSET) |
			       (1 << AXM0_CSD_SW_C2CC_OFFSET) |
			       (0 << AXM0_CSD_SW_F2CB_OFFSET) |
			       (0 << AXM0_CSD_SW_F2CA_OFFSET) |
			       (0 << AXM0_CSD_SW_F2MA_OFFSET) |
			       (0 << AXM0_CSD_SW_F2PT_OFFSET));

	CSD->SW_BYP_SEL = ((1 << AXM0_CSD_SW_CBCC_OFFSET) |
			   (1 << AXM0_CSD_SW_BYB_OFFSET) |
			   (0 << AXM0_CSD_SW_BYA_OFFSET));

	/************************************
	 * Init Vref
	 * Set: Input to Vref (1.2V)
	 * Set: Vrefhi = Vref (1.2V) * 31/31 = 1.2V
	 * Set: Vreflo = Vref * 15/31 = 0.6V
	 ************************************/
	CSD->SW_REFGEN_SEL = ((1 << AXM0_CSD_SW_SGR_OFFSET) |
			      (0 << AXM0_CSD_SW_SGRE_OFFSET) |
			      (0 << AXM0_CSD_SW_SGMB_OFFSET) |
			      (1 << AXM0_CSD_SW_IBCB_OFFSET) |
			      (0 << AXM0_CSD_SW_IAIB_OFFSET));

	CSD->REFGEN = ((0 << AXM0_CSD_VREFLO_INT_OFFSET) |
		       (15 << AXM0_CSD_VREFLO_SEL_OFFSET)|
		       (31 << AXM0_CSD_GAIN_OFFSET)      |
		       (1 << AXM0_CSD_RES_EN_OFFSET)     |
		       (0 << AXM0_CSD_VDDA_EN_OFFSET)    |
		       (0 << AXM0_CSD_BYPASS_OFFSET)     |
		       (1 << AXM0_CSD_REFGEN_EN_OFFSET) );

	CSD->SW_AMUXBUF_SEL = ((0 << AXM0_CSD_SW_IRL_OFFSET) |
			       (0 << AXM0_CSD_SW_IRH_OFFSET) |
			       (0 << AXM0_CSD_SW_IRLI_OFFSET) |
			       (0 << AXM0_CSD_SW_ICB_OFFSET) |
			       (0 << AXM0_CSD_SW_ICA_OFFSET) |
			       (0 << AXM0_CSD_SW_IRLB_OFFSET) |
			       (0 << AXM0_CSD_SW_IRBY_OFFSET));

	/************************************
	 * Init HSCOMP
	 * Enable: HSCOMP
	 * Set: cmp Vrefhi (P = HMRH) and csdbusd (N = HCCD)
	 * Enable: Auto Zero mode
	 ************************************/
	CSD->SW_HS_P_SEL = ((1 << AXM0_CSD_SW_HMRH_OFFSET) |
			    (0 << AXM0_CSD_SW_HMCB_OFFSET) |
			    (0 << AXM0_CSD_SW_HMCA_OFFSET) |
			    (0 << AXM0_CSD_SW_HMMB_OFFSET) |
			    (0 << AXM0_CSD_SW_HMMA_OFFSET) |
			    (0 << AXM0_CSD_SW_HMPS_OFFSET) |
			    (0 << AXM0_CSD_SW_HMPT_OFFSET) |
			    (0 << AXM0_CSD_SW_HMPM_OFFSET));

	CSD->SW_HS_N_SEL = ((0 << AXM0_CSD_SW_HCRL_OFFSET) |
			    (0 << AXM0_CSD_SW_HCRH_OFFSET) |
			    (1 << AXM0_CSD_SW_HCCD_OFFSET) |
			    (0 << AXM0_CSD_SW_HCCC_OFFSET));

	CSD->HSCMP =  ((1 << AXM0_CSD_HSCMP_EN_OFFSET)|
		       (0 << AXM0_CSD_HSCMP_INVERT_OFFSET) |
		       (1 << AXM0_CSD_AZ_EN_OFFSET));

	/************************************
	 * Clear all pending interrupts
	 * disable all interrupts
	 ************************************/
	CSD->INTR = ((1 << AXM0_CSD_ADC_RES_OFFSET)|
		     (1 << AXM0_CSD_INIT_OFFSET) |
		     (1 << AXM0_CSD_SAMPLE_OFFSET));

	CSD->INTR_MASK = ((1 << AXM0_CSD_ADC_RES_OFFSET)|
			  (1 << AXM0_CSD_INIT_OFFSET) |
			  (1 << AXM0_CSD_SAMPLE_OFFSET));

    gOneshotContinuous = 4;

    gAdcInitStatus = AXM0_PERI_INITIALIZED; /* Set ADC init status to YES */
}

static uint8_t wait_until_vref_done(void)
{
    /* Wait in  standby mode till ADC is done with measurement */
    while(AXM0_STATUS_IN_PROGRESS == gVrefStatus)
    {
        wtimer_idle(WTFLAG_CANSTANDBY);
    }
    return(gVrefStatus);
}

static void CapSenseADC_Measure(en_CapSenseADC_source source)
{

	/***************************************
	 * switch ADC Mode depending on input
	 * Performs charge/discharge of internal Cref
	 * AXM0_ADC_VREF_CNT = Vssa -> Vref
	 * AXM0_ADC_VIN_CNT = Vin -> Vref
	 ****************************************/
	switch(source) {
        case AXM0_ADC_VREF_CNT:
            CSD->ADC_CTL = ((1 << AXM0_CSD_ADC_MODE_OFFSET) |
                    (250 << AXM0_CSD_ADC_TIME_OFFSET));

            CSD->SEQ_START = ((0 << AXM0_CSD_AZ1_SKIP_OFFSET) |
                      (1 << AXM0_CSD_AZ0_SKIP_OFFSET) |
                      (0 << AXM0_CSD_DSI_START_EN_OFFSET) |
                      (0 << AXM0_CSD_ABORT_OFFSET) |
                      (0 << AXM0_CSD_SEQ_MODE_OFFSET) |
                      (1 << AXM0_CSD_START_OFFSET));
            gVddioVref = 1;
            gVrefStatus = AXM0_STATUS_IN_PROGRESS;
        break;

        case AXM0_ADC_VIN_CNT:
        default:
            /* Close switch HCBV to precharge */
            CSD->SW_SHIELD_SEL = ((0 << AXM0_CSD_SW_HCCG_OFFSET) |
                          (0 << AXM0_CSD_SW_HCCV_OFFSET) |
                          (0 << AXM0_CSD_SW_HCBG_OFFSET) |
                          (1 << AXM0_CSD_SW_HCBV_OFFSET) |
                          (0 << AXM0_CSD_SW_HCAG_OFFSET) |
                          (0 << AXM0_CSD_SW_HCAV_OFFSET));

            CSD->ADC_CTL = ((3 << AXM0_CSD_ADC_MODE_OFFSET) |
                    (250 << AXM0_CSD_ADC_TIME_OFFSET));

            CSD->SEQ_START = ((0 << AXM0_CSD_AZ1_SKIP_OFFSET) |
                      (1 << AXM0_CSD_AZ0_SKIP_OFFSET) |
                      (0 << AXM0_CSD_DSI_START_EN_OFFSET) |
                      (0 << AXM0_CSD_ABORT_OFFSET) |
                      (0 << AXM0_CSD_SEQ_MODE_OFFSET) |
                      (1 << AXM0_CSD_START_OFFSET));
            gVddioVref = 0;
            gAdcStatus = AXM0_STATUS_IN_PROGRESS;
        break;
	}
}

static void adc_measure_vddio(void)
{
    CapSenseADC_Measure(AXM0_ADC_VREF_CNT);
    wait_until_vref_done();
    gVrefResult = (gVrefResult * 853) >> 10;    // ~ div by 1.2 = counts per mV
    CapSenseADC_Measure(AXM0_ADC_VIN_CNT);
	return ;
}

/** CSD Handler */
void CSD_Handler(void)
{
    /* End of Scanning Interrupt */
    if(0 != (CSD->INTR_MASKED & 0x100))
    {
        if(gVddioVref == 1)
        {
            gVrefResult = (int16_t)(CSD->ADC_RES & 0xFFFF);
            gVrefStatus = AXM0_STATUS_SUCCESS;
        }
        else
        {
            gAdcResult = (int16_t)(CSD->ADC_RES & 0xFFFF);
            gAdcStatus = AXM0_STATUS_SUCCESS;
        }
    }
	/* Clear all interrupts */
	CSD->INTR = ((1 << AXM0_CSD_ADC_RES_OFFSET)|
		     (1 << AXM0_CSD_INIT_OFFSET) |
		     (1 << AXM0_CSD_SAMPLE_OFFSET));
}

static void Reset_port_pin(void)
{
    volatile uint32_t *Port_select;
    uint8_t port_plus = 0;
    uint8_t pin_plus = 0;
    uint8_t port_minus = 0;
    uint8_t pin_minus = 0;

    if(gPositiveInput != PKG_PIN_NOT_GPIO)
    {
        port_plus = gPositiveInput/8;
        pin_plus = gPositiveInput%8;
        /* Get base address of HSIOM register */
        Port_select = (volatile uint32_t*)(HSIOM);
        *((Port_select + (port_plus * 0x40))) &= (~(0xF << (4 * pin_plus)));

        Port_select = (volatile uint32_t*)(GPIO_PRT0);
        *((Port_select + (port_plus * 0x40))) &= ~(0x1 << pin_plus);
        *((Port_select + (port_plus * 0x40) + 6)) &= ~(0x1 << pin_plus);
    }

    if(gNegativeInput != PKG_PIN_NOT_GPIO)
    {
        port_minus = gNegativeInput/8;
        pin_minus = gNegativeInput%8;

        /* Get base address of HSIOM register */
        Port_select = (volatile uint32_t*)(HSIOM);
        *((Port_select + (port_minus * 0x40))) &= (~(0xF << (4 * pin_minus)));

        /* Get base address of GPIO register */
        Port_select = (volatile uint32_t*)(GPIO_PRT0);
        *((Port_select + (port_minus * 0x40) + 6)) &= ~(0x1 << pin_minus);                //PC2
        *((Port_select + (port_minus * 0x40) + 2)) &= (~(0x7 << (pin_minus * 0x3)));      //PC
        *((Port_select + (port_minus * 0x40))) &= (~(0x1 << pin_minus));                  //DR
    }

    if(gExternalRef == 1)
    {
        GPIO_PRT1->DR &= ~(0x00000080);    /* p1.7 external referance input */
        GPIO_PRT1->PC2 &= ~(0x00000080);
        gExternalRef = 0;
    }

    gPositiveInput = PKG_PIN_NOT_GPIO;
    gNegativeInput = PKG_PIN_NOT_GPIO;

    return;

}


/** Function description can be found in header file */
uint8_t adc_init(uint8_t positive_input, uint8_t negative_input, uint8_t conv_mode, uint8_t ref_input, uint16_t ext_vref)
{
    uint32_t tmpRegVal;
    volatile uint32_t *Port_select;
    uint16_t Vref_value = 0;
    uint8_t differential_indicator = 1;
    uint8_t port_plus = 0;
    uint8_t pin_plus = 0;
    uint8_t port_minus = 0;
    uint8_t pin_minus = 0;

    if((positive_input == PKG_PIN_NOT_GPIO) || (negative_input == PKG_PIN_NOT_GPIO))
    {
        gAdcStatus = AXM0_STATUS_INVALID_PARAMETER;
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    gAdcStatus = AXM0_STATUS_IN_PROGRESS;

    if(positive_input == ADC_TEMPERATURE_MEASUREMENT)
    {
        if(conv_mode == LIBMF_ADC_CONTINUOUS)
        {
           gAdcStatus = AXM0_STATUS_INVALID_PARAMETER;
           return AXM0_STATUS_INVALID_PARAMETER;
        }
        if(ref_input != LIBMF_ADC_VREF_INTERNAL)
        {
           gAdcStatus = AXM0_STATUS_INVALID_PARAMETER;
           return AXM0_STATUS_INVALID_PARAMETER;
        }
        adc_temperature_init();
        return(AXM0_STATUS_SUCCESS);
    }
    else if(positive_input == ADC_VDDIO_MEASUREMENT)
    {
        if(negative_input == PKG_PIN_GROUND)
        {
           gAdcStatus = AXM0_STATUS_INVALID_PARAMETER;
           return AXM0_STATUS_INVALID_PARAMETER;
        }
        gPositiveInput = PKG_PIN_NOT_GPIO;
        gNegativeInput = negative_input;
        CapSenseADC_Init(negative_input);
        return(AXM0_STATUS_SUCCESS);
    }

    gPositiveInput = positive_input;
    gNegativeInput = negative_input;

    if(negative_input == PKG_PIN_GROUND)
    {
       differential_indicator = 0;
    }

    port_plus = positive_input/8;
    pin_plus = positive_input%8;

    /* Get base address of HSIOM register */
    Port_select = (volatile uint32_t*)(HSIOM);
    SET_BIT_FIELDS((*(Port_select + (port_plus * 0x40))), (0xF << (4 * pin_plus)), (0x6 << (4 * pin_plus))); //HSIOM : AMUX BUSA

    if(differential_indicator == 1)
    {
        port_minus = negative_input/8;
        pin_minus = negative_input%8;

        /* Get base address of HSIOM register */
        Port_select = (volatile uint32_t*)(HSIOM);
        SET_BIT_FIELDS((*(Port_select + (port_minus * 0x40))), (0xF << (4 * pin_minus)), (0x7 << (4 * pin_minus))); //HSIOM : AMUX BUSB
    }

    if(ref_input == LIBMF_ADC_VREF_EXTERNAL)
    {
        gExternalRef = 1;
        GPIO_PRT1->DR |= 0x00000080u;    /* p1.7 external referance input */
        GPIO_PRT1->PC2 |= 0x00000080u;
    }

    Port_select = (volatile uint32_t*)(GPIO_PRT0);

    *((Port_select + (port_plus * 0x40))) |= (0x1 << pin_plus);
    *((Port_select + (port_plus * 0x40) + 6)) |= (0x1 << pin_plus);

    if(differential_indicator == 1)
    {
        *((Port_select + (port_minus * 0x40))) |= (0x1 << pin_minus);
        *((Port_select + (port_minus * 0x40) + 6)) |= (0x1 << pin_minus);
    }

    /* AnalogSetDefault */
    /* Set AMUX BUSA and BUSB Switch */
    if(differential_indicator == 0)
    {
       HSIOM->AMUX_SPLIT_CTL0 = 0x00000003u;
    }
    else
    {
       HSIOM->AMUX_SPLIT_CTL0 = 0x00000033u;
    }

    /* DFT mode is configured to 3*/
    CTBM0->DFT_CTRL = 0x00000003u;

    SAR->MUX_SWITCH_CLEAR0 = 0xFFFFFFFF;
    SAR->MUX_SWITCH_HW_CTRL = 0x0;  /* Clear Hardware Switch Control */
    SAR->INJ_CHAN_CONFIG = 0x0;
    SAR->INTR = 0x000000FF;         /* SAR Interrupts are Cleared */


    if (!(SAR->CTRL & 0x80000000)) {
		while (SAR->STATUS & 0x80000000);
		SAR->CTRL = 0x80000000;
		delay(10);  /* 10 MicroSec delay is expected */
	}

    if(differential_indicator == 0)
    {
        /* Close switch between AMUXBUSA and VPLUS signal */
        SAR->MUX_SWITCH0 = 0x00040000u; //Single Ended port 4.0
    }
    else if(differential_indicator == 1)
    {
        /* Close switch between AMUXBUSA and VPLUS signal */
        /* Close switch between AMUXBUSB and VMINUS signal */
        SAR->MUX_SWITCH0 = 0x00240000u; //Differential port 4.0 and 1.1
    }
    /* value of 0x20 is used during factory trim and is required to maintain low offsets across temperature variation*/
    PASS_DSAB->DSAB_CTRL = 0x00000020u;

    /* Init SAR and MUX registers */
    /* there are 16 channels, Channel 0 is enabled */
    SAR->CHAN_EN = 0x1;

    /* Referance voltage selection, NEG input of SARADC is connected to VSSA in AROUTE close to the SARADC,
    synchronize the DSI config signals to peripheral clock domain, Switches are controlled by firmware */
    SAR->CTRL |= 0x53000200;
    SAR->CTRL &= ~(0x70);
    if(ref_input == LIBMF_ADC_VREF_INTERNAL)
    {
       SAR->CTRL |= 0x40;
       Vref_value = 1200;
    }
    else if(ref_input == LIBMF_ADC_VREF_VDD_BY_2)
    {
       SAR->CTRL |= 0x60;
       Vref_value = 1650;
    }
    else if(ref_input == LIBMF_ADC_VREF_VDD)
    {
       SAR->CTRL |= 0x70;
       Vref_value = 3300;
    }
    else if(ref_input == LIBMF_ADC_VREF_EXTERNAL)
    {
       SAR->CTRL |= 0x50;
       Vref_value = ext_vref;
    }

    /* Sub resolution 10bit, right aligned in data[11:0], with sign extension to 16 bits if the channel is differential,
    Output is signed/Unsigned, Continuous scanning/Trigger Scanning, Enable to output EOS_INTR to DSI */
    SAR->SAMPLE_CTRL = 0x800000FD;

    /* High threshold for range detect is programmed to 0x7FF */
    /* Low threshold for range detect is programmed to 0x0 */
    SAR->RANGE_THRES = 0x07FF0000;

    /* Global range detect mode register, result < RANGE_LOW */
    SAR->RANGE_COND  = 0x0;

    /* SAMPLE_TIME0 is programmed to 6, SAMPLE_TIME1 is programmed to 2 */
    SAR->SAMPLE_TIME01 = 0x00020006;
    /* SAMPLE_TIME2 is programmed to 2, SAMPLE_TIME3 is programmed to 2 */
    SAR->SAMPLE_TIME23 = 0x00020002;

    if(differential_indicator != 1)
    {
        /* close switch between vssa_kelvin and vminus signal */
        SAR->MUX_SWITCH0 |= 0x00010000; //Only for Temperature sensor and Single Ended
    }

    SAR->SATURATE_INTR_MASK = 0u;
    SAR->RANGE_INTR_MASK = 0u;
    SAR->INTR_MASK = 0x1;

    /* Read and modify default configuration based on characterization */
    tmpRegVal = SAR->DFT_CTRL;
    tmpRegVal &= (uint32_t)~AXM0_ADC_SAR_SEQ_DCEN;

    tmpRegVal |= AXM0_ADC_SAR_SEQ_DLY_INC;
    SAR->DFT_CTRL = tmpRegVal;

    if(differential_indicator == 0)
    {
        SAR->CHAN_CONFIG0 = 0x00000400u;    //Single ended
    }
    else
    {
        SAR->CHAN_CONFIG0 = 0x00000500u;    //Differential
    }

    SAR->SAMPLE_CTRL &= ~(0xB0000);
    if(conv_mode == LIBMF_ADC_CONTINUOUS)
    {
        NVIC_DisableIRQ(ADC_IRQn);
        gOneshotContinuous = 2;
        SAR->SAMPLE_CTRL |= AXM0_ADC_SAR_SEQ_CONTINUOUS_EN;
    }
    else if(conv_mode == LIBMF_ADC_ONESHOT)
    {
        gOneshotContinuous = 3;
        SAR->SAMPLE_CTRL |= 0xA0000;
    }

    /* Calculate gain in counts per 10 volts with rounding */
    gAdcSarSeqCountsPer10Volt = (int16_t)(((AXM0_ADC_SAR_SEQ_SAR_WRK_MAX_12BIT * AXM0_ADC_SAR_SEQ_10MV_COUNTS) +
                        Vref_value) / (Vref_value * 2));

    gAdcInitStatus = AXM0_PERI_INITIALIZED; /* Set ADC init status to YES */

    return(AXM0_STATUS_SUCCESS);
}

/** Function description can be found in header file */
void adc_start_measurement(void)
{
    if(gAdcInitStatus == AXM0_PERI_NOT_INITIALIZED)
    {
        gAdcStatus = AXM0_STATUS_NO_INIT;
        return;
    }
    gAdcStatus = AXM0_STATUS_IN_PROGRESS;

    if(gOneshotContinuous == 4)
    {
        NVIC_ClearPendingIRQ(CSD_IRQn);
        NVIC_EnableIRQ(CSD_IRQn);
        adc_measure_vddio();
    }
    else
    {
        NVIC_ClearPendingIRQ(ADC_IRQn);
        NVIC_EnableIRQ(ADC_IRQn);

        /* Start channel measurement */
        SAR->START_CTRL = 0x1;

        if(gOneshotContinuous == 1)
        {
            /* Start Injection channel measurement */
            SAR->INJ_CHAN_CONFIG |= 0x1 << 31;
        }
    }

}

/** Function description can be found in header file */
void adc_close(void)
{
    if(gOneshotContinuous == 4)
    {
        NVIC_DisableIRQ(CSD_IRQn);

        /************************************
         * Clear all registers
         ************************************/
        CSD->SW_REFGEN_SEL = 0;
        CSD->SW_FW_TANK_SEL = 0;
        CSD->SW_DSI_SEL = 0;
        CSD->ADC_CTL = 0;
        CSD->AMBUF = 0;
        CSD->SW_SHIELD_SEL = 0;
        CSD->SW_HS_P_SEL = 0;
        CSD->SW_HS_N_SEL = 0;
        CSD->HSCMP = 0;
    }
    else
    {
        NVIC_DisableIRQ(ADC_IRQn);
        HSIOM->AMUX_SPLIT_CTL0 = 0x00000000;
        SAR->MUX_SWITCH_CLEAR0 = 0xFFFFFFFF;
        SAR->MUX_SWITCH_HW_CTRL = 0x0;  /* Clear Hardware Switch Control */
        /* SAR IP is disabled */
        SAR->CTRL &= ~(0x80000000);
    }

    Reset_port_pin();

    gAdcStatus = AXM0_STATUS_NO_INIT;

    gAdcInitStatus = AXM0_PERI_NOT_INITIALIZED;
}

/** Function description can be found in header file */
int16_t adc_result_in_mVolts(int16_t adcCounts)
{
    int16_t mVolts;

    if(gOneshotContinuous == 4)
    {
        mVolts = adcCounts;
    }
    else
    {
        mVolts = (int16_t)((((int32_t)adcCounts * AXM0_ADC_SAR_SEQ_10MV_COUNTS) + ( (adcCounts > 0) ?
             (gAdcSarSeqCountsPer10Volt / 2) : (-(gAdcSarSeqCountsPer10Volt / 2)) ))
             / gAdcSarSeqCountsPer10Volt);
    }

    return( mVolts );
}

/** Function description can be found in header file */
int16_t adc_get_result(void)
{
    int16_t adc_result = 0;
    if(gAdcInitStatus == AXM0_PERI_NOT_INITIALIZED)
    {
        gAdcStatus = AXM0_STATUS_NO_INIT;
        return 0;
    }
    switch(gOneshotContinuous)
    {
    case 1: /* One Shot Temp */
        adc_result = gAdcResult;
        break;
    case 2: /* Continuous Voltage */
        while (!(SAR->INTR & 0x00000001));
        adc_result = (int16_t)(SAR->CHAN_RESULT0 & AXM0_ADC_SAR_SEQ_RESULT_MASK);
        SAR->INTR = 0x00000001;
        break;
    case 3: /* One Shot Voltage */
        adc_result = gAdcResult;
        break;
    case 4: /* VDDIO Result */
        adc_result = ((gAdcResult * 1000) / gVrefResult) + 1200;
        break;
    default:
        adc_result = 0;
        break;
    }

    return(adc_result);
}

/** Function description can be found in header file */
uint8_t adc_getstatus(void)
{
    /* Return ADC status */
	return (gAdcStatus);
}

/** Function description can be found in header file */
uint8_t adc_wait_until_done(void)
{
    /* Wait in  standby mode till ADC is done with measurement */
    while(AXM0_STATUS_IN_PROGRESS == gAdcStatus)
    {
        wtimer_idle(WTFLAG_CANSTANDBY);
    }
    return(gAdcStatus);
}

/** ADC Handler */
void ADC_Handler(void)
{
    /* End of Scanning Interrupt */
    if(0 != (SAR->INTR_MASKED & AXM0_ADC_SAR_SEQ_EOS_MASK))
    {
        gAdcResult = (int16_t)(SAR->CHAN_RESULT0 & AXM0_ADC_SAR_SEQ_RESULT_MASK);
        SAR->INTR = AXM0_ADC_SAR_SEQ_EOS_MASK;
        gAdcStatus = AXM0_STATUS_SUCCESS;
    }

    /* End of Scanning Interrupt for Injection channel */
    if(0 != (SAR->INTR_MASKED & AXM0_ADC_SAR_SEQ_INJECTION_EOS_MASK))
    {
        gAdcResult = (int16_t)(SAR->INJ_RESULT & AXM0_ADC_SAR_SEQ_RESULT_MASK);
        SAR->INTR = AXM0_ADC_SAR_SEQ_EOS_EOI_MASK;
        gAdcStatus = AXM0_STATUS_SUCCESS;
    }

}


#endif // __AXM0F2

#endif // defined
