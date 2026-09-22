/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer, Pradeep Kumar GR
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

#include "cpu.h"
#include "libmfosc.h"
#include "axm0_config.h"
#include "libmfradio.h"

/**
 * \brief set up oscillator calibration
 *
 */

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

/* Smart IO */
#define AXM0F2_SMARTIO_CLKSRC_ASYNC    31
#define AXM0F2_SMARTIO_PIPELINE_EN     0
#define AXM0F2_SMARTIO_HLD_OVR         0
#define AXM0F2_SMARTIO_BYPASS_PINS     237
#define AXM0F2_SMARTIO_GPIO_DATA1      13
#define AXM0F2_SMARTIO_LUT3_OUTPUT     3
#define AXM0F2_SMARTIO_LUT1_OUTPUT     17
#define AXM0F2_SMARTIO_LUT_CONFIG0     0
#define AXM0F2_SMARTIO_LUT_CONFIG1     1
#define AXM0F2_SMARTIO_LUT_CONFIG2     66
#define AXM0F2_SMARTIO_LUT_CONFIG3     128
#define AXM0F2_SMARTIO_LUT_OPCODE0     0
#define AXM0F2_SMARTIO_LUT_OPCODE2     2
#define AXM0F2_SMARTIO_DU_INPUT0       0
#define AXM0F2_SMARTIO_DU_SIZE         7
#define AXM0F2_SMARTIO_DU_OPCODE       1
#define AXM0F2_SMARTIO_DU_DATA         0
#define AXM0F2_SMARTIO_ENABLE          1

/* IMO calibration */
#define AXM0F2_IMO_CALIB_KLF        12000
#define AXM0F2_IMO_CALIB_ACC_SHIFT  256
#define AXM0F2_IMO_CALIB_FREF       6000000
#define AXM0F2_IMO_CALIB_FREF_CNT   6000
#define AXM0F2_IMO_CALIB_FOSC       375000
#define AXM0F2_IMO_CALIB_FOSC_CNT   375
#define AXM0F2_IMO_CALIB_FILTER_VAL ((AXM0F2_IMO_CALIB_KLF/1000 * AXM0F2_IMO_CALIB_ACC_SHIFT * AXM0F2_IMO_CALIB_FOSC/1000))

/* ILO calibration */
#define AXM0F2_SYS_CLK_ILO_CONFIG_ENABLE          (uint32_t)(1 << 31)
#define AXM0F2_SYS_CLK_ILO_DESIRED_FREQ_HZ        (uint32_t)(40000)
#define AXM0F2_SYS_CLK_ILO_PERIOD_PPH             (uint32_t)(2500)
#define AXM0F2_SYS_CLK_ILO_CALIBR_COMPLETE_MASK   (uint32_t)(0x1 << 31)
#define AXM0F2_SYS_TST_DDFT_CTRL_REG_DEFAULT_MASK (uint32_t)(0x3F3F)
#define AXM0F2_SYS_TST_DDFT_CTRL_REG_SEL2_CLK1    (uint32_t)(0x201)
#define AXM0F2_SYS_CLK_DFT_SELECT_DEFAULT_MASK    (uint32_t)(0xF00)
#define AXM0F2_SYS_CLK_SEL_ILO_DFT_SOURCE         (uint32_t)(0x100)
#define AXM0F2_SYS_CLK_COEF_PHUNDRED              (uint32_t) (0x64)
#define AXM0F2_SYS_CLK_HALF_OF_CLOCK              (uint32_t)(AXM0F2_SYS_CLK_ILO_PERIOD_PPH >> 2)
#define AXM0F2_SYS_CLK_SYS_CLK_DEVIDER            (uint32_t)(0x0A)
#define AXM0F2_ILO_CALIB_CALC_COUNT               (uint32_t)(40000)
#define AXM0F2_ILO_CALIB_DESIRD_COUNTS            (uint32_t)(((AXM0F2_ILO_CALIB_LPOSC_DESIRED_DELAY_IN_US * AXM0F2_SYS_CLK_COEF_PHUNDRED) + \
                                                              AXM0F2_SYS_CLK_HALF_OF_CLOCK) / AXM0F2_SYS_CLK_ILO_PERIOD_PPH)
#define AXM0F2_ILO_CALIB_LPOSC_DESIRED_DELAY_IN_US   (uint32_t)(1000000)     /* 1000000 us = 1 second */
#define AXM0F2_ILO_CALIB_FRCOSC_FREQ_IN_HZ           (uint32_t)(48000000)    /* 48MHz */
#define AXM0F2_ILO_CALIB_MIN_FREQ                    (uint32_t)(4000000)

static uint32_t lposcCompensatedCycles = AXM0F2_ILO_CALIB_CALC_COUNT; /* default LPOSC count for 1 second @ 40 KHz*/

__attribute__ ((section (".noinit"))) uint8_t wtimer0_clksrc, wtimer1_clksrc, wtimer1_prescaler;/* Wtimer 0/1 clock source to use in ILO interval correction. noinit to avoid RAM init */

#endif // __AXM0F2
#endif // defined __ARMEL__ || defined __ARMEB__

__reentrantb uint32_t wtimer0_correctinterval(uint32_t intvl) __reentrant
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

	if (wtimer0_clksrc == CLKSRC_LPOSC) /* If clock source is LPOSC */
	{
		intvl = (((intvl / AXM0F2_ILO_CALIB_CALC_COUNT) * lposcCompensatedCycles) + /* Extract number of seconds count if any and compensate */
				(((intvl % AXM0F2_ILO_CALIB_CALC_COUNT) * lposcCompensatedCycles) / AXM0F2_ILO_CALIB_CALC_COUNT)); /* Extract less than second count if any and compensate */
	}

#endif // __AXM0F2
#endif // defined __ARMEL__ || defined __ARMEB__
    return intvl;
}

__reentrantb uint32_t wtimer1_correctinterval(uint32_t intvl) __reentrant
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

	if (wtimer1_clksrc == CLKSRC_LPOSC) /* If clock source is LPOSC */
	{
			intvl = (((intvl / AXM0F2_ILO_CALIB_CALC_COUNT) * lposcCompensatedCycles) + /* Extract number of seconds count if any and compensate */
					(((intvl % AXM0F2_ILO_CALIB_CALC_COUNT) * lposcCompensatedCycles) / AXM0F2_ILO_CALIB_CALC_COUNT)); /* Extract less than second count if any and compensate */
	}

#endif // __AXM0F2
#endif // defined __ARMEL__ || defined __ARMEB__
    return intvl;
}

#if defined __ARMEL__ || defined __ARMEB__
/* Input parameter clk_freq: 0 for 16 MHz, 1 for 20 MHz */
#ifdef __AXM0

#include "axm0f143.h"
#include "axm0_xbar.h"
#include "libmfradio.h"

#define AXM0_XBAR_EXT_CLK_SEL_PR1       3
#define AXM0_HS_OSC_FIL_VAL             0x4000
#define AXM0_HS_OSC_CFG_16M_VAL         0x174
#define AXM0_HS_OSC_CFG_16M_REF_VAL     0x1600
#define AXM0_HS_OSC_CFG_20M_VAL         0x1F4
#define AXM0_HS_OSC_CFG_20M_REF_VAL     0x1300
#define AXM0_HS_OSC_CFG_REF_VAL_DIV     500
#define AXM0_HS_OSC_CAL_COUNT           4
#define AXM0_RADIO_CONN_TEST_VAL        (uint8_t)0xA5

void axm0_calib_hs_osc(uint8_t clk_freq)
{
	uint8_t  scratch_val, frccalcnt = 0;
	uint16_t frcmaxerr, frcperiod = 0;
	uint32_t cmu_cfg, cmu_pclk, hs_osc_cfg;
	int32_t temp_err;

	/* Backup register content */
	cmu_cfg      = CMU->CFG;
	cmu_pclk     = CMU->PCLK_CFG;
	hs_osc_cfg   = CMU->HS_OSC_CFG;

	/* Enable peripherals */
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_SPI0_EN_Msk | CMU_PCLK_CFG_CL_SYSCFG_EN_Msk | CMU_PCLK_CFG_XBAR_EN_Msk;

	/* Configure xbar for SPI (radio) interface */
	XBAR->PR_CFG_b.PR0 = 1;
	XBAR->PR_CFG_b.PR2 = 1;
	XBAR->PR_CFG_b.PR4 = 1;
	XBAR->IN_SPI0_CFG_b.IN = XBAR_IN_SPI0_CFG_IN_MISO_PR3;

	XBAR->IN_EXT_CLK_CFG = AXM0_XBAR_EXT_CLK_SEL_PR1;   /* RSYSCLK is set as input on PR1 */

	/* Write test value to radio scratch register, read back and compare with written value */
	radio_write8(AX5043_REG_SCRATCH, AXM0_RADIO_CONN_TEST_VAL);
	scratch_val = radio_read8(AX5043_REG_SCRATCH);
	if (scratch_val != AXM0_RADIO_CONN_TEST_VAL) {
		/* Radio not connected: Scratch register value not matching with written value */
		/* Restore registers content */
		CMU->PCLK_CFG   = cmu_pclk;
		return;
	}

	ax5043_rclk_enable(2);        /* Enable and Divide RSYSCLK by 4 to have 12 MHz */

	/* Set filter value */
	CMU->HS_OSC_FILT = AXM0_HS_OSC_FIL_VAL;

	if(clk_freq == 0) {
		/* 16 MHz REF and CFG values */
		CMU->HS_OSC_CFG     = AXM0_HS_OSC_CFG_16M_VAL;      /* Start auto calibration */
		CMU->HS_OSC_REF_DIV = AXM0_HS_OSC_CFG_16M_REF_VAL;
	} else {
		/* 20 MHz REF and CFG values */
		CMU->HS_OSC_CFG     = AXM0_HS_OSC_CFG_20M_VAL;      /* Start auto calibration */
		CMU->HS_OSC_REF_DIV = AXM0_HS_OSC_CFG_20M_REF_VAL;
	}

	/* Get maximum error value */
	frcmaxerr = (CMU->HS_OSC_REF_DIV) / AXM0_HS_OSC_CFG_REF_VAL_DIV;

	/* Check output clock is less than maximum error for 4 consecutive times */
	for (;;) {
		if (CMU->INT_STS_b.HS_OSC_CAL) {
			CMU->INT_STS_b.HS_OSC_CAL = 1;
			frcperiod = CMU->HS_OSC_PER;

			temp_err = frcperiod - (CMU->HS_OSC_REF_DIV);

			/* Find out absolute value of error */
			if(temp_err < 0)
				temp_err = -temp_err;

			if (temp_err > frcmaxerr)
				frccalcnt = 0;
			else if (frccalcnt != 0xff)
				++frccalcnt;
		}

		if (frccalcnt > AXM0_HS_OSC_CAL_COUNT) {
			/* Satisfied error test */
			CMU->HS_OSC_CFG_b.CAL_SEL = 0; /* Stop auto calibration */
			break;
		}
	}

	ax5043_rclk_disable();        /* Disable RSYSCLK */

	/* Restore registers content */
	CMU->CFG        = cmu_cfg;
	CMU->PCLK_CFG   = cmu_pclk;
	CMU->HS_OSC_CFG = hs_osc_cfg;
}

#endif

#ifdef __AXM0F2

#include "axm0f2.h"
#include "axm0f243.h"
#include "libmfwtimer.h"
#include "libmfradio.h"

static void axm0f2_calib_ilo_update_count(void);
static void axm0f2_calib_init(void);
static void axm0f2_calib_imo_osc(void);
static void axm0f2_refclk_pin_SmartIO_init(void);
static void axm0f2_refclk_counter_init(void);

static struct calstate {
    uint16_t osccount ;
    int32_t osctrim ;
}calstate ;

extern uint8_t __startcause;
static uint8_t flag = 0;
static uint32_t prescaled_ref_freq;

uint8_t setup_osc_calibration(uint32_t reffreq, uint8_t refosc)
{
    uint8_t prescaler = 0;
    uint32_t temp_reffreq;

    if(__startcause == STARTCAUSE_COLDSTART)
    {/* Change radio mode only for the cold start */
        /* Check reference clock is RSYSCLK */
        if(refosc == CLKSRC_RSYSCLK)
        {
            /* Check reference frequency < 4 MHz */
            if(reffreq < AXM0F2_ILO_CALIB_MIN_FREQ)
            {
                return AXM0_STATUS_INVALID_PARAMETER;
            }

            /* Choose pre-scaler so the reffreq after pre-scaling falls into the range from 4 to 8 MHz */
            temp_reffreq = reffreq/AXM0F2_ILO_CALIB_MIN_FREQ;

            while(temp_reffreq > 0)
            {
               temp_reffreq >>= 1;
               prescaler++;
            }

            prescaled_ref_freq = reffreq >> (prescaler - 1);

            /* Enable and Divide RSYSCLK by pre-scaler */
            ax5043_rclk_enable(prescaler - 1);
        }
        else
        {
            /* Space to extend to support other clock sources */
        }
    }
    /* IMO Calibration Setup */
    axm0f2_calib_imo_osc();

    /* ILO calibration setup */
    SRSSLT->CLK_ILO_CONFIG |= AXM0F2_SYS_CLK_ILO_CONFIG_ENABLE;

    /* Configure measurement counters to source by SysClk (Counter 1) and ILO (Counter 2)*/
    SRSSLT->CLK_DFT_SELECT = (SRSSLT->CLK_DFT_SELECT & (uint32_t) ~AXM0F2_SYS_CLK_DFT_SELECT_DEFAULT_MASK) |
                             AXM0F2_SYS_CLK_SEL_ILO_DFT_SOURCE;

    SRSSLT->TST_DDFT_CTRL = (SRSSLT->TST_DDFT_CTRL & (uint32_t) ~AXM0F2_SYS_TST_DDFT_CTRL_REG_DEFAULT_MASK) |
                            AXM0F2_SYS_TST_DDFT_CTRL_REG_SEL2_CLK1;

    /* Reload CNTR 1 count value for next measurement cycle*/
    SRSSLT->TST_TRIM_CNTR1 = (AXM0F2_ILO_CALIB_FRCOSC_FREQ_IN_HZ >> AXM0F2_SYS_CLK_SYS_CLK_DEVIDER);

    return AXM0_STATUS_SUCCESS;
}

static void axm0f2_calib_init(void)
{
    calstate.osccount = 0;

    uint32_t t = SRSSLT->CLK_IMO_TRIM1 & 0xff;
    t <<= 3;
    t |= SRSSLT->CLK_IMO_TRIM2 & 0x7;
    t <<= 8;
    calstate.osctrim = t;
}



void TCPWM0_Handler(void)
{
    /* Clear pending interrupt */
    NVIC_ClearPendingIRQ(TCPWM0_IRQn);

    /* Clear the interrupt flag */
    TCPWM_CNT0->INTR = (TCPWM_CNT0->INTR & ~0x00000003) | 0x00000001;

    /* ILO calibration */
    axm0f2_calib_ilo_update_count();

    uint16_t ref,osc;
    {
        uint16_t t;
        uint32_t irqm = enter_critical();

        /* read ref oscillator ticks */
        ref = TCPWM_CNT0->COUNTER;

        /* read IMO oscillator ticks */
        osc = TCPWM_CNT4->COUNTER;

        exit_critical(irqm);

        /* Add 6000 to count as TC interrupt is configured on TCPWM3 */
        ref += AXM0F2_IMO_CALIB_FREF_CNT;

        if (flag == 0){
            /* Store the IMO clock count when the handler is hit first time */
            calstate.osccount = osc ;

            /* Update the flag value */
            flag = 1;

            return;
        }

        t = osc - calstate.osccount ;
        calstate.osccount = osc;
        osc = t;
    }

    /* sanity check with fref = 6MHz */
    if ((ref < ((AXM0F2_IMO_CALIB_FREF_CNT * 7) / 10)) || (ref > ((AXM0F2_IMO_CALIB_FREF_CNT * 13) / 10)))
        return ;

    int32_t expected_osc_cnt = (prescaled_ref_freq * AXM0F2_IMO_CALIB_FOSC_CNT) / AXM0F2_IMO_CALIB_FREF;

    /* sanity check with fosc = 375 KHz */
    if (osc < ((expected_osc_cnt * 7) / 10) || osc > ((expected_osc_cnt * 13) / 10))
        return ;

    int32_t t;

    t = osc;

    /* Loop filter equation with fref - 6MHz, fosc - 375KHz, Klf - 12000, Accsh - 8 */
    t *= (AXM0F2_IMO_CALIB_KLF * AXM0F2_IMO_CALIB_ACC_SHIFT);
    t += (AXM0F2_IMO_CALIB_KLF / 2);
    t /= ref;
    t -= (AXM0F2_IMO_CALIB_FILTER_VAL / (prescaled_ref_freq / 1000000));

    /* integrator */
    calstate.osctrim -= t;

    if (calstate.osctrim > (0x7ff * 256))
        calstate.osctrim = (0x7ff * 256);
    else if (calstate.osctrim < 0)
        calstate.osctrim = 0;

    /* store relevant bits of trim integrator into trim registers */
    t = (calstate.osctrim >> 8);

    SRSSLT->CLK_IMO_TRIM2 = t & 0x7;

    t >>= 3;

    SRSSLT->CLK_IMO_TRIM1 = t & 0xff;
}

void axm0f2_calib_imo_osc()
{
    /* Configure TCPWM trigger input for pin P3.4 */
    SET_BIT_FIELDS(HSIOM->PORT_SEL3, 0x000F0000, 0x000B0000);

    /* Configure P3.4 as input */
    SET_BIT_FIELDS(GPIO_PRT3->PC, (7 << 12), (1 << 12));

    /* Map P3.1(RSYSCLK) to P3.4 using SMART IO */
    axm0f2_refclk_pin_SmartIO_init();

    /* Initializes TCPWM3 to count reference clock ticks */
    axm0f2_refclk_counter_init();

    /* Calibration initialization */
    axm0f2_calib_init();

    /* Update flag value */
    flag = 0;
}

void axm0f2_calib_ilo_update_count(void)
{
    /* Check counter 1 stopped counting and after it calculate compensated cycles */
    if(0u != (SRSSLT->TST_TRIM_CNTR1 & AXM0F2_SYS_CLK_ILO_CALIBR_COMPLETE_MASK))
    {
        if (0u != SRSSLT->TST_TRIM_CNTR2)
        {
            /* Calculate required number of ILO cycles for given delay */
            lposcCompensatedCycles = (((SRSSLT->TST_TRIM_CNTR2 * AXM0F2_ILO_CALIB_FRCOSC_FREQ_IN_HZ) /
                                     (AXM0F2_ILO_CALIB_FRCOSC_FREQ_IN_HZ >> AXM0F2_SYS_CLK_SYS_CLK_DEVIDER)) *
                                     AXM0F2_ILO_CALIB_DESIRD_COUNTS) / AXM0F2_SYS_CLK_ILO_DESIRED_FREQ_HZ;

            /* Reload CNTR 1 count value for next measurement cycle*/
            SRSSLT->TST_TRIM_CNTR1 = (AXM0F2_ILO_CALIB_FRCOSC_FREQ_IN_HZ >> AXM0F2_SYS_CLK_SYS_CLK_DEVIDER);
        }
    }
}

void axm0f2_refclk_pin_SmartIO_init()
{
    /* Must disable the block before configuring */
	PRGIO_PRT1->CTL &= ~(1 << 31);
    /* Configure bypass pins, Clock source - asynchronous, disabled Pipeline and hold override functionality */
    PRGIO_PRT1->CTL = (AXM0F2_SMARTIO_CLKSRC_ASYNC << 8) | (AXM0F2_SMARTIO_PIPELINE_EN << 25) | (AXM0F2_SMARTIO_HLD_OVR << 24) | (AXM0F2_SMARTIO_BYPASS_PINS << 0);
    /* Disable synchronization control */
    PRGIO_PRT1->SYNC_CTL = 0x00;

    /* LUT input selection */
    PRGIO_PRT1->LUT_SEL0 = (AXM0F2_SMARTIO_LUT1_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 16);
    PRGIO_PRT1->LUT_SEL1 = (AXM0F2_SMARTIO_LUT1_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 16);
    PRGIO_PRT1->LUT_SEL2 = (AXM0F2_SMARTIO_LUT1_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 16);
    PRGIO_PRT1->LUT_SEL3 = (AXM0F2_SMARTIO_GPIO_DATA1 << 0)  | (AXM0F2_SMARTIO_GPIO_DATA1 << 8)  | (AXM0F2_SMARTIO_GPIO_DATA1 << 16);
    PRGIO_PRT1->LUT_SEL4 = (AXM0F2_SMARTIO_LUT3_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT3_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT3_OUTPUT << 16);
    PRGIO_PRT1->LUT_SEL5 = (AXM0F2_SMARTIO_LUT1_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 16);
    PRGIO_PRT1->LUT_SEL6 = (AXM0F2_SMARTIO_LUT1_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 16);
    PRGIO_PRT1->LUT_SEL7 = (AXM0F2_SMARTIO_LUT1_OUTPUT << 0) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 8) | (AXM0F2_SMARTIO_LUT1_OUTPUT << 16);

    /* LUT Control */
    PRGIO_PRT1->LUT_CTL0 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL1 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL2 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL3 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL4 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL5 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL6 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;
    PRGIO_PRT1->LUT_CTL7 = (AXM0F2_SMARTIO_LUT_CONFIG3 << 0) ;

    /* Turn of the Data Unit */
    PRGIO_PRT1->DU_SEL = (AXM0F2_SMARTIO_DU_INPUT0 << 0)|(AXM0F2_SMARTIO_DU_INPUT0 << 8)|(AXM0F2_SMARTIO_DU_INPUT0 << 16)|
                         (AXM0F2_SMARTIO_DU_INPUT0 << 24)|(AXM0F2_SMARTIO_DU_INPUT0 << 28);
    PRGIO_PRT1->DU_CTL = (AXM0F2_SMARTIO_DU_SIZE << 0) | (AXM0F2_SMARTIO_DU_OPCODE << 8);
    PRGIO_PRT1->DATA = 0x00;

    /* Enable Smart IO */
    PRGIO_PRT1->CTL |= (AXM0F2_SMARTIO_ENABLE << 31);
}


void axm0f2_refclk_counter_init()
{
    /* Stop TCPWM0 counter */
    TCPWM->CMD |= 0x00010000;

    /* Disable TCPWM0 interrupt */
    NVIC_DisableIRQ(TCPWM0_IRQn);

    /* Disable TCPWM0 Counter */
    TCPWM->CTRL &= ~(1 << 0);

    /* Clock:IMO, 48MHz, divider 5,divided by 1 */
    PERI->PCLK_CTL4 = 0x00000045;

    /* Maximum value for the counter to count 6000 cycles gives Interrupt frequency ~ 1ms */
    TCPWM_CNT0->PERIOD = 0x0000176F;

    /* Trigger input tcpwm.tr_in[6] on P3.4 for count */
    TCPWM_CNT0->TR_CTRL0 = 0x00000080;

    /* Count on rising edge */
    TCPWM_CNT0->TR_CTRL1 = 0x00000000;

    /* Enable TCPWM0 counter */
    TCPWM->CTRL |= (1 << 0);

    /* Configure TC interrupt */
    TCPWM_CNT0->INTR_MASK = (1 << 0);

    /* Reset interrupt */
    TCPWM_CNT0->INTR = (TCPWM_CNT0->INTR & ~0x00000003) | 0x00000001;

    /* Reset TCPWM0 counter value to 0 */
    TCPWM_CNT0->COUNTER = 0x0000;

    /* Enable TCPWM0 interrupt */
    NVIC_EnableIRQ(TCPWM0_IRQn);

    /* Start trigger to start TCPWM0 counter */
    TCPWM->CMD |= 0x01000000;
}

#endif /* __AXM0F2 */

#else /* Other than "__ARMEL__ || defined __ARMEB__" */

static __reentrantb uint8_t compute_frcosccfg(uint32_t reffreq) __reentrant
{
	uint8_t x = 0;
	while (reffreq >= 500) {
		if (x & 0x80)
			return x;
		x += 0x08;
		reffreq >>= 1;
	}
	if (reffreq < 250)
		return 0x80;
	return x;
}

static __reentrantb void compute_frcoscref(uint32_t reffreq, uint8_t calcfg) __reentrant
{
	static const uint32_t __code refs[9] = {
		10000000, 10000000 << 1, 10000000 << 2, 10000000 << 3, 10000000 << 4, 10000000 << 5, 10000000 << 6, 10000000 << 7, 10000000 << 8
	};
	calcfg >>= 3;
	if (calcfg > 8) {
		calcfg -= 8;
		reffreq >>= calcfg;
		calcfg = 8;
	}
#ifdef SDCC
	FRCOSCREF = refs[calcfg] / reffreq;
#else
	{
		uint16_t x = refs[calcfg] / reffreq;
		FRCOSCREF0 = x;
		FRCOSCREF1 = x >> 8;
	}
#endif
}

static __reentrantb uint8_t compute_lposccfg(uint32_t reffreq) __reentrant
{
	uint8_t x = 0;
	reffreq /= 320;
	while (reffreq >= 0xC000) {
		if (x & 0x40)
			return x;
		x += 0x08;
		reffreq >>= 1;
	}
	if (reffreq < 0x6000)
		return 0x40;
#ifdef SDCC
	LPOSCREF = reffreq;
#else
	LPOSCREF0 = reffreq;
	LPOSCREF1 = reffreq >> 8;
#endif
	return x;
}

__reentrantb uint8_t setup_osc_calibration(uint32_t reffreq, uint8_t refosc) __reentrant
{
	uint8_t refosc1 = refosc;
	uint8_t lposccfg;
	uint8_t frcosccfg;

	frcosccfg = compute_frcosccfg(reffreq);
	if (frcosccfg & 0x80)
		return 1;
	compute_frcoscref(reffreq, frcosccfg);
	lposccfg = compute_lposccfg(reffreq);
	if (lposccfg & 0x40) {
#ifdef SDCC
		LPOSCREF = 0x7A12;
#else
		LPOSCREF0 = 0x12;
		LPOSCREF1 = 0x7A;
#endif
		lposccfg = 0x80;
	} else {
		lposccfg |= 0x07;
	}
	lposccfg |= LPOSCCONFIG & 0x40;
	switch (refosc1) {
	case CLKSRC_XOSC:
		setup_xosc();
		OSCFORCERUN |= 0x04;
		frcosccfg |= 0x02;
		lposccfg &= 0xF8 | 0x02;
		break;

	case CLKSRC_LPXOSC:
		setup_lpxosc();
		OSCFORCERUN |= 0x08;
		frcosccfg |= 0x03;
		lposccfg &= 0xF8 | 0x03;
		break;

	case CLKSRC_RSYSCLK:
		frcosccfg |= 0x04;
		lposccfg &= 0xF8 | 0x04;
		break;

	default:
		return 2;
	}
#ifdef SDCC
	FRCOSCKFILT = 0x4000;
	LPOSCKFILT = 0x4000;
#else
	FRCOSCKFILT0 = 0x00;
	FRCOSCKFILT1 = 0x40;
	LPOSCKFILT0 = 0x00;
	LPOSCKFILT1 = 0x40;
#endif
	FRCOSCCONFIG = frcosccfg;
	LPOSCCONFIG = lposccfg;
	return 0;
}

#endif /* __ARMEL__ || defined __ARMEB__ */
