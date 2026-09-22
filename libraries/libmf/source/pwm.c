/**
******************************************************************************
* @file pwm.c
* @brief PWM implementation
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
* @ingroup PWM
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#include "cpu.h"
#include "axm0f2.h"
#include "pwm.h"
#include "libmfpwm.h"
#include "axm0f2_pin.h"

static uint8_t gPwmInitStatus[3] = {AXM0_PERI_NOT_INITIALIZED,AXM0_PERI_NOT_INITIALIZED,AXM0_PERI_NOT_INITIALIZED};

/** Function description can be found in header file */
uint8_t pwm_init(uint8_t sel_pwm ,uint8_t pwm_pin, uint8_t pwm_type, uint32_t pwm_period, uint8_t pwm_dutycycle, uint8_t sel_div)
{

    uint8_t port_plus = 0;
    uint8_t pin_plus = 0;
    volatile uint32_t *Port_select;
    volatile TCPWM_CNT0_Type *tcpwm = (TCPWM_CNT0_Type *)(TCPWM_CNT0 + sel_pwm);
    uint32_t period_count = 0;
    uint32_t dutycycle_count = 0;
    uint16_t prescalar = 0;
    uint8_t prescalar_count = 0;
    volatile uint8_t value = 0;
    volatile uint32_t *peri_div;

    if(!(((sel_pwm == LIBMF_PWM_1) && (pwm_pin == PKG_PIN_NUM_14)) || ((sel_pwm == LIBMF_PWM_2) && (pwm_pin == PKG_PIN_NUM_30)) || ((sel_pwm == LIBMF_PWM_3) && ((pwm_pin == PKG_PIN_NUM_16) || (pwm_pin == PKG_PIN_NUM_32)))))
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    if(sel_div > 5)
    {
        /* Only Integer dividers are used, Valid range 0 to 5, return with error for invalid range */
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    /* Duty cycle 0 to 100 is Supported */
    if((pwm_dutycycle < PWM_MIN_DUTYCYCLE) || (pwm_dutycycle > PWM_MAX_DUTYCYCLE))    /* Dutycycle range supported is 0 to 100 */
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    if((pwm_type == LIBMF_PWM_LEFT_ALIGNED) || (pwm_type == LIBMF_PWM_RIGHT_ALIGNED))
    {
        value = 1;
    }
    else if((pwm_type == LIBMF_PWM_CENTER_ALIGNED) || (pwm_type == LIBMF_PWM_ASSYMETRIC_ALIGNED))
    {
        value = 2;
    }
    else
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    /* Period Range Supported 3 MicroSec to 1,74,500 MicroSec For LEFT and RIGHT Aligned */
    /* Period Range Supported 6 MicroSec to 3,49,000 MicroSec For CENTER and ASSYMETRIC Aligned */
    if((pwm_period < (PWM_MIN_PERIOD_TIME * value)) || (pwm_period > (PWM_MAX_PERIOD_TIME * value)))
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    /* Get base address of divider selection register */
    peri_div = (uint32_t*)(PERI);
    *((peri_div + sel_div + AXM0F2_DIV_CTL_ADRS_OFFSET)) = 0x00000000;
    /* Command is performed on Divider-0, Integer 16 Clock Divider */
    PERI->DIV_CMD = 0x8000FF40 | sel_div;
    /* IMO Clock is directly fed, No division :: TCPWM Clock = HCLK */
    SRSSLT->CLK_SELECT = 0;

    NVIC_DisableIRQ(TCPWM0_IRQn+sel_pwm);

    (*(peri_div + AXM0F2_PCLK_CTL_ADRS_OFFSET + sel_pwm)) = 0x00000040 | sel_div;

    port_plus = pwm_pin/8;
    pin_plus = pwm_pin%8;

    /* Get base address of HSIOM register */
    Port_select = (volatile uint32_t*)(HSIOM);
    SET_BIT_FIELDS((*(Port_select + (port_plus * 0x40))), (PWM_4BIT_MASK << (4 * pin_plus)), (0x8 << (4 * pin_plus))); /* HSIOM : Chip specific active source 0 connection */

    /* Get base address of GPIO register */
    Port_select = (volatile uint32_t*)(GPIO_PRT0);
    *((Port_select + (port_plus * 0x40))) |= ((0x1 << pin_plus));                   //DR
    SET_BIT_FIELDS((*(Port_select + (port_plus * 0x40) + 2)), (0x7 << (pin_plus * 0x3)), (0x6 << (pin_plus * 0x3))); /* PC : Strong Pull-down and Strong Pull-up */

    /* Calculate Period value, Prescalar Count */
    prescalar = 1;
    prescalar_count = 0;
    while(1)
    {
        period_count = ((pwm_period * 48)/prescalar)/value;
        if((period_count >= PWM_MIN_PERIOD_COUNT) && (period_count <= PWM_MAX_PERIOD_COUNT))
        {
            break;
        }
        prescalar = prescalar * 2;
        if(prescalar > 128)
        {
           return AXM0_STATUS_INVALID_PARAMETER;
        }
        prescalar_count++;
    }

    /* Calculate Dutycycle Count */
    if(value == 1)
    {
       dutycycle_count = (period_count * pwm_dutycycle)/PWM_MAX_DUTYCYCLE;
    }
    else if(value == 2)
    {
       dutycycle_count = (period_count * (PWM_MAX_DUTYCYCLE-pwm_dutycycle))/PWM_MAX_DUTYCYCLE;
    }

    /* PWM MODE is Selected and PWM STOP ON Kill is enabled */
    tcpwm->CTRL = 0x04000008;

    /* Prescalar Count is Configured in TCPWM */
    SET_BIT_FIELDS(tcpwm->CTRL,(PWM_8BIT_MASK << 8),(prescalar_count << 8));

    tcpwm->CTRL &= ~(0x3 << 16);
    if(pwm_type == LIBMF_PWM_LEFT_ALIGNED)
    {
        /* Count-UP is configured */
        /* Counter is Initialised to 0 */
        tcpwm->COUNTER = 0;
        /* UNDERFLOW Mode : Line Out No Change, OVERFLOW Mode : Line Out Set to 1, CC MATCH Mode : Line Out Set to 0 */
        tcpwm->TR_CTRL2 = 0x31;
    }
    else if(pwm_type == LIBMF_PWM_RIGHT_ALIGNED)
    {
        /* Count-DOWN is Configured */
        tcpwm->CTRL |= (0x1 << 16);
        /* Counter is Initialised to PERIOD */
        tcpwm->COUNTER = period_count & PWM_16BIT_MASK;
        /* UNDERFLOW Mode : Line Out Set to 0, OVERFLOW Mode : Line Out No Change, CC MATCH Mode : Line Out Set to 1 */
        tcpwm->TR_CTRL2 = 0x1C;
    }
    else if(pwm_type == LIBMF_PWM_CENTER_ALIGNED)
    {
        /* Count-UPDOWN1 is Configured */
        tcpwm->CTRL |= (0x2 << 16);
        /* Counter is Initialised to 1 */
        tcpwm->COUNTER = 1;
        /* UNDERFLOW Mode : Line Out Set to 0, OVERFLOW Mode : Line Out Set to 1, CC MATCH Mode : Line Out Invert */
        tcpwm->TR_CTRL2 = 0x12;
    }
    else if(pwm_type == LIBMF_PWM_ASSYMETRIC_ALIGNED)
    {
        /* Count-UPDOWN2 is Configured */
        tcpwm->CTRL |= (0x3 << 16);
        /* Counter is Initialised to 1 */
        tcpwm->COUNTER = 1;
        /* UNDERFLOW Mode : Line Out Set to 0, OVERFLOW Mode : Line Out Set to 1, CC MATCH Mode : Line Out Invert */
        tcpwm->TR_CTRL2 = 0x12;
    }

    /* Count Trigger is Selected */
    tcpwm->TR_CTRL0 = 0x10;

    /* START Edge, STOP Edge, RELOAD Edge, CAPTURE Edge is RAISING Edge, COUNT Edge is Use Trigger As is */
    tcpwm->TR_CTRL1 = 0xC;

    /* Set Interrupt Mask for TC */
    tcpwm->INTR_MASK = 0x1;

    /* Configure PERIOD COUNT */
    tcpwm->PERIOD = period_count & PWM_16BIT_MASK;

    /* Configure DUTY-CYCLE COUNT */
    tcpwm->CC = dutycycle_count & PWM_16BIT_MASK;

    /* Set PWM init status to AXM0_PERI_INITIALIZED for Selected PWM */
    gPwmInitStatus[sel_pwm-1] = AXM0_PERI_INITIALIZED;

    return(AXM0_STATUS_SUCCESS);
}

/** Function description can be found in header file */
uint8_t pwm_start(uint8_t sel_pwm)
{
    if((sel_pwm < 1) || (sel_pwm > 3))
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    /* If Selected TCPWM is not Initialised, Return */
    if(gPwmInitStatus[sel_pwm-1] == AXM0_PERI_NOT_INITIALIZED)
    {
        return AXM0_STATUS_NO_INIT;
    }

    /* Counter Enabled For TCPWM */
    TCPWM->CTRL |= (0x1<<sel_pwm);
    /* Counter Start For TCPWM */
    TCPWM->CMD |= ((0x1<<sel_pwm) << 24);

    return(AXM0_STATUS_SUCCESS);
}

/** Function description can be found in header file */
uint8_t pwm_dutycycle(uint8_t sel_pwm, uint8_t pwm_dutycycle)
{
    uint32_t period_count = 0;
    uint32_t dutycycle_count = 0;

	volatile TCPWM_CNT0_Type *tcpwm = (TCPWM_CNT0_Type *)(TCPWM_CNT0 + sel_pwm);

    if((sel_pwm < 1) || (sel_pwm > 3))
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }

    /* If Selected TCPWM is not Initialised, Return */
    if(gPwmInitStatus[sel_pwm-1] == AXM0_PERI_NOT_INITIALIZED)
    {
        return AXM0_STATUS_NO_INIT;
    }

    /* Get PERIOD Count for TCPWM */
    period_count = (tcpwm->PERIOD) & PWM_16BIT_MASK;
    /* Calculate Dutycycle Count for TCPWM */
    if(tcpwm->TR_CTRL2 == 0x12)
    {
       dutycycle_count = (period_count * (PWM_MAX_DUTYCYCLE-pwm_dutycycle))/PWM_MAX_DUTYCYCLE;
    }
    else
    {
       dutycycle_count = (period_count * pwm_dutycycle)/PWM_MAX_DUTYCYCLE;
    }
    /* Configure DUTY-CYCLE COUNT for TCPWM */
    tcpwm->CC = dutycycle_count & PWM_16BIT_MASK;

    return(AXM0_STATUS_SUCCESS);
}

/** Function description can be found in header file */
uint8_t pwm_stop(uint8_t sel_pwm)
{
    if((sel_pwm < 1) || (sel_pwm > 3))
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }
    /* If Selected TCPWM is not Initialised, Return */
    if(gPwmInitStatus[sel_pwm-1] == AXM0_PERI_NOT_INITIALIZED)
    {
        return AXM0_STATUS_NO_INIT;
    }

    /* Counter Stop For TCPWM */
    TCPWM->CMD |= ((0x1<<sel_pwm) << 16);

    return(AXM0_STATUS_SUCCESS);
}

/** Function description can be found in header file */
uint8_t pwm_close(uint8_t sel_pwm)
{
    if((sel_pwm < 1) || (sel_pwm > 3))
    {
        return AXM0_STATUS_INVALID_PARAMETER;
    }
    /* If Selected TCPWM is not Initialised, Return */
    if(gPwmInitStatus[sel_pwm-1] == AXM0_PERI_NOT_INITIALIZED)
    {
        return AXM0_STATUS_NO_INIT;
    }

    /* Counter Stop For TCPWM */
    TCPWM->CMD |= ((0x1<<sel_pwm) << 16);
    /* Counter Disabled For TCPWM */
    TCPWM->CTRL &= ~((0x1<<sel_pwm));

    return(AXM0_STATUS_SUCCESS);
}

#endif // __AXM0F2

#endif // defined
