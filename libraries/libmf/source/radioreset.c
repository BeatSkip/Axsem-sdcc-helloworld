/**
******************************************************************************
* @file radioreset.c
* @brief radio reset
* @internal
* @author   Thomas Sailer, Pradeep Kumar GR
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
* @ingroup RADIO
*
* @details
*/

#include "libmftypes.h"
#include "libmfradio.h"

#include "cpu.h"

#if RADIO == 5031
#define RADIO 5031
#elif RADIO == 5042
#define RADIO 5042
#elif RADIO == 5043
#define RADIO 5043
#elif RADIO == 5044 /* or 5045 */
#define RADIO 5044
#elif RADIO == 5051
#define RADIO 5051
#endif

#include "radiodefs.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0
#include "axm0_xbar.h"
#endif

#ifdef __AXM0F2
#include "axm0f2.h"
#include "axm0f2_pin.h"
#include "radioutil.h"
#endif // __AXM0F2

uint8_t radio_reset(void) __reentrant
{
	uint8_t i;
	// Initialize Interface
#ifdef __AXM0
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
#endif // __AXM0

#if DEEPSLEEP
	// Ensure Device is not in Deep Sleep
	radio_wakeup_deepsleep_core();
#endif
    	// Reset Device
	radio_write8(RADIO_PWRMODE, 0x80);  // RST bit PWRMODE
	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);  //PWRMODE
	// Wait some time for regulator startup
#if defined(VREGDELAY) && VREGDELAY > 0
	delay(VREGDELAY);
#endif

	// Check Silicon Version
	i = radio_read8(RADIO_SILICONREVISION);
	i = radio_read8(RADIO_SILICONREVISION);

#ifdef SILICONREV2
	if (i != SILICONREV1 && i != SILICONREV2)
		return RADIO_ERR_REVISION;
#else
	if (i != SILICONREV1)
		return RADIO_ERR_REVISION;
#endif

	// Check Scratch (To test communication to the AX5043/44/45 & Uc)
	radio_write8(RADIO_SCRATCH, 0x55);
	if (radio_read8(RADIO_SCRATCH) != 0x55)
		return RADIO_ERR_COMM;
	radio_write8(RADIO_SCRATCH, 0xAA);
	if (radio_read8(RADIO_SCRATCH) != 0xAA)
		return RADIO_ERR_COMM;
	// Initialize Radio Interface Registers
#if RADIO == 5031
#elif RADIO == 5042
	radio_write8(AX5042_REG_IFMODE, 0x00);
	radio_write8(AX5042_REG_AGCTARGET, 0x0E);
	radio_write8(AX5042_REG_PLLRNGMISC, 0x01);
	radio_write8(AX5042_REG_RXMISC, 0x35);
#elif RADIO == 5043
#elif RADIO == 5044 /* or 5045 */
#elif RADIO == 5051
	radio_write8(AX5051_REG_IFMODE, 0x00);
	radio_write8(AX5051_REG_PLLVCOI, 0x01);
	radio_write8(AX5051_REG_RXMISC, 0x35);
#endif
	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return RADIO_OK;
}

#else

#include "axcompiler.h"

__reentrantb uint8_t radio_reset(void) __reentrant
{
	uint8_t i;
	// Initialize Interface
	DIRR = 0x15;
	PORTR = 0xEB;
#if DEEPSLEEP
	RADIOMUX = 0x07;
#else
	RADIOMUX = 0x47;
#endif
	RADIOACC = RACC;
	GPIOENABLE = 1;
#if defined SDCC
	RADIOFDATAADDR = FDATA;
	RADIOFSTATADDR = FSTAT;
#else
	RADIOFDATAADDR0 = (FDATA) & 0xFF;
	RADIOFDATAADDR1 = (FDATA) >> 8;
	RADIOFSTATADDR0 = (FSTAT) & 0xFF;
	RADIOFSTATADDR1 = (FSTAT) >> 8;
#endif
#if DEEPSLEEP
	// Ensure Device is not in Deep Sleep
	radio_wakeup_deepsleep_core();
#endif
	// Reset Device
	radio_write8(RADIO_PWRMODE, 0x80);
	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);
	// Wait some time for regulator startup
#if defined(VREGDELAY) && VREGDELAY > 0
	delay(VREGDELAY);
#endif
	// Check Scratch
	i = radio_read8(RADIO_SILICONREVISION);
	i = radio_read8(RADIO_SILICONREVISION);
#ifdef SILICONREV2
	if (i != SILICONREV1 && i != SILICONREV2)
		return RADIO_ERR_REVISION;
#else
	if (i != SILICONREV1)
		return RADIO_ERR_REVISION;
#endif
	radio_write8(RADIO_SCRATCH, 0x55);
	if (radio_read8(RADIO_SCRATCH) != 0x55)
		return RADIO_ERR_COMM;
	radio_write8(RADIO_SCRATCH, 0xAA);
	if (radio_read8(RADIO_SCRATCH) != 0xAA)
		return RADIO_ERR_COMM;
	// Initialize Radio Interface Registers
#if RADIO == 5031
#elif RADIO == 5042
	radio_write8(AX5042_REG_IFMODE, 0x00);
	radio_write8(AX5042_REG_AGCTARGET, 0x0E);
	radio_write8(AX5042_REG_PLLRNGMISC, 0x01);
	radio_write8(AX5042_REG_RXMISC, 0x35);
#elif RADIO == 5043
#elif RADIO == 5044 /* or 5045 */
#elif RADIO == 5051
	radio_write8(AX5051_REG_IFMODE, 0x00);
	radio_write8(AX5051_REG_PLLVCOI, 0x01);
	radio_write8(AX5051_REG_RXMISC, 0x35);
#endif
	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return RADIO_OK;
}
#endif

#if RADIO == 5031


#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5031_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5031_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	// Initialize Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
	radio_write8(AX5031_REG_PINCFG1, pc1);
	radio_write8(AX5031_REG_PINCFG2, 0x22); /* IRQ Line 1 */
	p &= GPIO->DATA >> 24;
	radio_write8(AX5031_REG_PINCFG2, 0x20); /* IRQ Line 0 */
	p &= (uint8_t)~(GPIO->DATA >> 24);
	radio_write8(AX5031_REG_PINCFG2, 0x00);
	switch(p) {
	case 0x20: /* IRQ on PR5 */
		// PR5 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR5 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x20000000;     // Configure PR5 to input
		GPIO_AND->INT_TYP = ~0x20000000;    // Configure PR5 to level triggered
		GPIO_OR->INT_POL = 0x20000000;      // Configure PR5 to rising edge
		GPIO_AND->INT_EN = ~0x20000000;     // Disable PR5 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<29));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<29));       // Disable pull down
		break;

	case 0x40: /* IRQ on PR6 */
		// PR6 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR6 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x40000000;     // Configure PR6 to input
		GPIO_AND->INT_TYP = ~0x40000000;    // Configure PR6 to level triggered
		GPIO_OR->INT_POL = 0x40000000;      // Configure PR6 to rising edge
		GPIO_AND->INT_EN = ~0x40000000;     // Disable PR6 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<30));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<30));       // Disable pull down
		break;

	default:
		/* Error */
		radio_write8(AX5031_REG_PINCFG1, 0x20 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#elif defined __AXM0F2

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5031_probeirq(void) __reentrant
{
	uint8_t p = 0x10;
	uint8_t pc1 = radio_read8(AX5031_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	radio_write8(AX5031_REG_PINCFG1, pc1);
	radio_write8(AX5031_REG_PINCFG2, 0x22); /* IRQ Line 1 */
	p &= GPIO_PRT2->PS;
	radio_write8(AX5031_REG_PINCFG2, 0x20); /* IRQ Line 0 */
	p &= (uint8_t)~GPIO_PRT2->PS;
	radio_write8(AX5031_REG_PINCFG2, 0x00);
	switch(p) {
	case 0x10: /* IRQ on P2[4] */
		break;

	default:
		/* Error */
		GPIO_PRT2->PC |= 7 << 12; /* enable PD/PU */
		radio_write8(AX5031_REG_PINCFG1, 0x20 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#endif

#else

__reentrantb uint8_t ax5031_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5031_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	PORTR = 0xEB;
	radio_write8(AX5031_REG_PINCFG1, pc1);
	radio_write8(AX5031_REG_PINCFG2, 0x22); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5031_REG_PINCFG2, 0x20); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5031_REG_PINCFG2, 0x00);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5031_REG_PINCFG1, 0x20 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	exit_critical(crit);
	return 0;
}

#endif

#elif RADIO == 5042


#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5042_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5042_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	// Initialize Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
	radio_write8(AX5042_REG_PINCFG1, 0xD0 | pc1);
	radio_write8(AX5042_REG_PINCFG2, 0xE2); /* IRQ Line 1 */
	p &= GPIO->DATA >> 24;
	radio_write8(AX5042_REG_PINCFG2, 0xE0); /* IRQ Line 0 */
	p &= (uint8_t)~(GPIO->DATA >> 24);
	radio_write8(AX5042_REG_PINCFG2, 0xC0);
	switch(p) {
	case 0x20: /* IRQ on PR5 */
		// PR5 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR5 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x20000000;     // Configure PR5 to input
		GPIO_AND->INT_TYP = ~0x20000000;    // Configure PR5 to level triggered
		GPIO_OR->INT_POL = 0x20000000;      // Configure PR5 to rising edge
		GPIO_AND->INT_EN = ~0x20000000;     // Disable PR5 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<29));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<29));       // Disable pull down
		break;

	case 0x40: /* IRQ on PR6 */
		// PR6 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR6 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x40000000;     // Configure PR6 to input
		GPIO_AND->INT_TYP = ~0x40000000;    // Configure PR6 to level triggered
		GPIO_OR->INT_POL = 0x40000000;      // Configure PR6 to rising edge
		GPIO_AND->INT_EN = ~0x40000000;     // Disable PR6 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<30));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<30));       // Disable pull down
		break;

	default:
		/* Error */
		radio_write8(AX5042_REG_PINCFG1, 0xF0 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#elif defined __AXM0F2

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5042_probeirq(void) __reentrant
{
	uint8_t p = 0x10;
	uint8_t pc1 = radio_read8(AX5042_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	radio_write8(AX5042_REG_PINCFG1, 0xD0 | pc1);
	radio_write8(AX5042_REG_PINCFG2, 0xE2); /* IRQ Line 1 */
	p &= GPIO_PRT2->PS;
	radio_write8(AX5042_REG_PINCFG2, 0xE0); /* IRQ Line 0 */
	p &= (uint8_t)~GPIO_PRT2->PS;
	radio_write8(AX5042_REG_PINCFG2, 0xC0);
	switch(p) {
	case 0x10: /* IRQ on P2[4] */
		break;

	default:
		/* Error */
		GPIO_PRT2->PC |= 7 << 12; /* enable PD/PU */
		radio_write8(AX5042_REG_PINCFG1, 0xF0 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#endif

#else

__reentrantb uint8_t ax5042_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5042_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	PORTR = 0xEB;
	radio_write8(AX5042_REG_PINCFG1, 0xD0 | pc1);
	radio_write8(AX5042_REG_PINCFG2, 0xE2); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5042_REG_PINCFG2, 0xE0); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5042_REG_PINCFG2, 0xC0);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5042_REG_PINCFG1, 0xF0 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	exit_critical(crit);
	return 0;
}

#endif

#elif RADIO == 5043

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5043_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	criticalsection_t crit = enter_critical();
	// Initialize Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);

	// AXM0_REVA Specific
	// PB3 - RIRQ Pin configure as GPIO
	XBAR->PB_CFG_b.PB3 = 0;             // Digital - 0
	GPIO_AND->OUT_EN = ~0x00000800;     // Configure PB3 to input
	GPIO_AND->INT_TYP = ~0x00000800;    // Configure PB3 to level triggered
	GPIO_OR->INT_POL = 0x00000800;      // Configure PB3 to rising edge
	GPIO_AND->INT_EN = ~0x00000800;     // Disable PB3

	radio_write8(AX5043_REG_PINFUNCIRQ, 0x01); /* IRQ Line 1 */
	p &= GPIO->DATA >> 24;
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x00); /* IRQ Line 0 */
	p &= (uint8_t)~(GPIO->DATA >> 24);

	/* Set AX5043 IRQ Output Interrupt Request  */
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x03);
	switch(p) {
	case 0x20: /* IRQ on PR5 */
		// PR5 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR5 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x20000000;     // Configure PR5 to input
		GPIO_AND->INT_TYP = ~0x20000000;    // Configure PR5 to level triggered
		GPIO_OR->INT_POL = 0x20000000;      // Configure PR5 to rising edge
		GPIO_AND->INT_EN = ~0x20000000;     // Disable PR5 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<29));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<29));       // Disable pull down
		break;

	case 0x40: /* IRQ on PR6 */
		// PR6 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR6 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x40000000;     // Configure PR6 to input
		GPIO_AND->INT_TYP = ~0x40000000;    // Configure PR6 to level triggered
		GPIO_OR->INT_POL = 0x40000000;      // Configure PR6 to rising edge
		GPIO_AND->INT_EN = ~0x40000000;     // Disable PR6 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<30));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<30));       // Disable pull down
		break;

	default:
		/* Error */
		radio_write8(AX5043_REG_PINFUNCIRQ, 0x02); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#elif defined __AXM0F2

void RADIO_IRQ(void) __attribute__((weak));

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5043_probeirq(void) __reentrant
{
	uint8_t p = 0x10;
	criticalsection_t crit = enter_critical();

	radio_write8(AX5043_REG_PINFUNCIRQ, 0x01); /* IRQ Line 1 */
	p &= GPIO_PRT2->PS;
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x00); /* IRQ Line 0 */
	p &= (uint8_t)~GPIO_PRT2->PS;

	/* Set AX5043 IRQ Output Interrupt Request  */
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x03);
	switch(p) {
	case 0x10: /* IRQ on P2[4] */
		break;

	default:
		/* Error */
		GPIO_PRT2->PC |= 7 << 12; /* enable PD/PU */
		radio_write8(AX5043_REG_PINFUNCIRQ, 0x02); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

static uint8_t pwramp_config_pin = GPIO_PIN_DISABLE, antsel_config_pin = GPIO_PIN_DISABLE ;

/*
 * Description : Configures edge trigger interrupt on PWRAMP pin (P2.3) and
 *               configures strong drive mode for the given GPIO port pin
 * input : @param config_pin Any GPIO port pin value from the GPIO_PIN_Enum defined in axm0f2_pin.h
 * output : None
 */
__reentrantb void ax5043_set_pwramp_pin(uint8_t config_pin) __reentrant
{
    /* GPIO Port 0 Base address */
    GPIO_PRT0_Type* gpio_pwramp_port_base_reg = (GPIO_PRT0_Type*)GPIO_PRT0_BASE;

    if (config_pin == GPIO_PIN_DISABLE)
    {
        /* Disable PWRAMP(P2.3) Interrupt */
        GPIO_PRT2->INTR_CFG &= ~(AXM0F2_GPIO_INTR_DISABLE << AXM0F2_GPIO_PIN3_INTR_CNFG_BIT_POS);
    }
    else
    {
        /* Enable PWRAMP(P2.3) Interrupt on both rising and falling edge */
        GPIO_PRT2->INTR_CFG |= AXM0F2_GPIO_INTR_CNFG_BOTH_EDGES << AXM0F2_GPIO_PIN3_INTR_CNFG_BIT_POS ;

        /* Store input */
        pwramp_config_pin = config_pin ;

        /* Calculate port base address for the config pin */
        gpio_pwramp_port_base_reg += ((config_pin & AXM0F2_GPIO_PORT_PIN_MASK) >> 3);

        /* Clear existing pin configuration of the pin and Configure strong drive mode for the pin */
        SET_BIT_FIELDS(gpio_pwramp_port_base_reg->PC,
                       (AXM0F2_GPIO_PIN_DRIVE_MODE_MASK << ((config_pin & AXM0F2_GPIO_PIN_MASK) * 3)),
                       (AXM0F2_GPIO_PIN_STRONG_DRIVE_MODE << ((config_pin & AXM0F2_GPIO_PIN_MASK) * 3)));

        /* copy status of P2.3 to the config pin */
        /* check for pin P2.3 status */
        if(GPIO_PRT2->PS & AXM0F2_GPIO_PWRAMP_PIN_STATE_MASK){
            /* Set Pin */
            gpio_pwramp_port_base_reg->DR_SET |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
        }
        else{
            /* Clear Pin */
            gpio_pwramp_port_base_reg->DR_CLR |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
        }
    }
}

/*
 * Description : Returns enum value on which the PWRAMP pin functionality is available
 * input : None
 * output : @return returns GPIO port pin enum value
 */
__reentrantb uint8_t ax5043_get_pwramp_pin() __reentrant
{
    return pwramp_config_pin;
}

/*
 * Description : Configures edge trigger interrupt on ANTSEL pin(P2.6) and
 *               configures strong drive mode for the given GPIO port pin
 * input : @param config_pin Any GPIO port pin value from the GPIO_PIN_Enum defined in axm0f2_pin.h
 * output : None
 */
__reentrantb void ax5043_set_antsel_pin(uint8_t config_pin) __reentrant
{
    /* GPIO Port 0 Base address */
    GPIO_PRT0_Type* gpio_antsel_port_base_reg = (GPIO_PRT0_Type*)GPIO_PRT0_BASE;

    if (config_pin == GPIO_PIN_DISABLE)
    {
        /* Disable ANTSEL(P2.6) Interrupt */
        GPIO_PRT2->INTR_CFG &= ~(AXM0F2_GPIO_INTR_DISABLE << AXM0F2_GPIO_PIN6_INTR_CNFG_BIT_POS);
    }
    else
    {
        /* Enable ANTSEL(P2.6) Interrupt on both rising and falling edge */
        GPIO_PRT2->INTR_CFG |= AXM0F2_GPIO_INTR_CNFG_BOTH_EDGES << AXM0F2_GPIO_PIN6_INTR_CNFG_BIT_POS ;

        /* Store input */
        antsel_config_pin = config_pin ;

        /* Calculate port base address for the config pin */
        gpio_antsel_port_base_reg += ((config_pin & AXM0F2_GPIO_PORT_PIN_MASK) >> 3);

        /* Clear existing pin configuration of the pin and Configure strong drive mode for the pin */
        SET_BIT_FIELDS(gpio_antsel_port_base_reg->PC,
                      (AXM0F2_GPIO_PIN_DRIVE_MODE_MASK << ((config_pin & AXM0F2_GPIO_PIN_MASK) * 3)),
                      (AXM0F2_GPIO_PIN_STRONG_DRIVE_MODE << ((config_pin & AXM0F2_GPIO_PIN_MASK) * 3)));

        /* copy status of P2.6 to the config pin */
        /* check for pin P2.6 status */
        if(GPIO_PRT2->PS & AXM0F2_GPIO_ANTSEL_PIN_STATE_MASK){
            /* Set Pin */
            gpio_antsel_port_base_reg->DR_SET |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
        }
        else{
            /* Clear Pin */
            gpio_antsel_port_base_reg->DR_CLR |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
        }
    }
}

/*
 * Description : Returns enum value on which the ANTSEL pin functionality is available
 * input : None
 * output : @return returns GPIO port pin enum value
 */
__reentrantb uint8_t ax5043_get_antsel_pin() __reentrant
{
    return antsel_config_pin;
}

void GPIOPort2_Handler(void)
{
    uint8_t config_pin;

	NVIC_ClearPendingIRQ(GPIOPort2_IRQn);

    /* Check interrupt is due to PWRAMP(P2.3) */
    if(GPIO_PRT2->INTR & AXM0F2_GPIO_PWRAMP_PIN_INTR_MASK){

        /* clear P2.3 interrupt */
        GPIO_PRT2->INTR |= AXM0F2_GPIO_PWRAMP_PIN_INTR_MASK;

        config_pin = ax5043_get_pwramp_pin();

        /* GPIO Port 0 Base address */
        GPIO_PRT0_Type* gpio_pwramp_port_base_reg = (GPIO_PRT0_Type*)GPIO_PRT0_BASE;

        /* Calculate port base address for the config pin */
        gpio_pwramp_port_base_reg += ((config_pin & AXM0F2_GPIO_PORT_PIN_MASK) >> 3);

        /* Check Invert */
        if((config_pin & GPIO_PIN_INVERT) == GPIO_PIN_NO_INVERT)
        {
            /* Check for pin P2.3 status */
            if(GPIO_PRT2->PS & AXM0F2_GPIO_PWRAMP_PIN_STATE_MASK){
                /* Set Pin */
                gpio_pwramp_port_base_reg->DR_SET |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
            else{
                /* Clear Pin */
                gpio_pwramp_port_base_reg->DR_CLR |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
        }
        else
        {
            /* Check for pin P2.3 status */
            if(GPIO_PRT2->PS & AXM0F2_GPIO_PWRAMP_PIN_STATE_MASK){
                /* Clear Pin */
                gpio_pwramp_port_base_reg->DR_CLR |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
            else{
                /* Set Pin */
                gpio_pwramp_port_base_reg->DR_SET |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
        }
    }

    /* Check interrupt is due to ANTSEL(P2.6) */
    if(GPIO_PRT2->INTR & AXM0F2_GPIO_ANTSEL_PIN_INTR_MASK){

        /* clear P2.6 interrupt */
        GPIO_PRT2->INTR |= AXM0F2_GPIO_ANTSEL_PIN_INTR_MASK;

        config_pin = ax5043_get_antsel_pin();

        /* GPIO Port 0 Base address */
        GPIO_PRT0_Type* gpio_antsel_port_base_reg = (GPIO_PRT0_Type*)GPIO_PRT0_BASE;

        /* Calculate port base address for the config pin */
        gpio_antsel_port_base_reg += ((config_pin & AXM0F2_GPIO_PORT_PIN_MASK) >> 3);

        /* Check Invert */
        if((config_pin & GPIO_PIN_INVERT) == GPIO_PIN_NO_INVERT)
        {
            /* Check for pin P2.6 status */
            if(GPIO_PRT2->PS & AXM0F2_GPIO_ANTSEL_PIN_STATE_MASK){
                /* Set Pin */
                gpio_antsel_port_base_reg->DR_SET |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
            else{
                /* Clear Pin */
                gpio_antsel_port_base_reg->DR_CLR |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
        }
        else
        {
            /* Check for pin P2.6 status */
            if(GPIO_PRT2->PS & AXM0F2_GPIO_ANTSEL_PIN_STATE_MASK){
                /* Clear Pin */
                gpio_antsel_port_base_reg->DR_CLR |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
            else{
                /* Set Pin */
                gpio_antsel_port_base_reg->DR_SET |= (1 << (config_pin & AXM0F2_GPIO_PIN_MASK));
            }
        }

    }

    /* Check interrupt is due to RIRQ */
	if (GPIO_PRT2->INTR & AXM0F2_GPIO_RADIO_IRQ_PIN_INTR_MASK){
        /* clear RIRQ 2.4 interrupt */
        GPIO_PRT2->INTR |= AXM0F2_GPIO_RADIO_IRQ_PIN_INTR_MASK;

        /* Serve INTR at 2.4 (RIRQ) */
        while (GPIO_PRT2->PS & AXM0F2_GPIO_RADIO_IRQ_PIN_STATE_MASK) {
            /* Level is high serve interrupt */
            RADIO_IRQ();
        }

    }
}

#endif

#else

#define RADIODRV        SFRX(0x7045)

__reentrantb uint8_t ax5043_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	criticalsection_t crit = enter_critical();
	PORTR &= 0xEB;
	PORTR |= 0x2B;
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x01); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x00); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5043_REG_PINFUNCIRQ, 0x03);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5043_REG_PINFUNCIRQ, 0x02); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	exit_critical(crit);
	return 0;
}

#endif

#elif RADIO == 5044 /* or 5045 */

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0
/* Place holder */
#elif defined __AXM0F2
/* Place holder */
#endif

#else /* Non - ARM: 8052 */

#define RADIODRV        SFRX(0x7045)

__reentrantb uint8_t ax5044_45_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	criticalsection_t crit = enter_critical();
	PORTR &= 0xEB;
	PORTR |= 0x2B;
	radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x01); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x00); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x03);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x02); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	exit_critical(crit);
	return 0;
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */

#elif RADIO == 5051

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5051_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5051_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	// Initialize Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
	radio_write8(AX5051_REG_PINCFG1, 0xD0 | pc1);
	radio_write8(AX5051_REG_PINCFG2, 0xF2); /* IRQ Line 1 */
	p &= GPIO->DATA >> 24;
	radio_write8(AX5051_REG_PINCFG2, 0xF0); /* IRQ Line 0 */
	p &= (uint8_t)~(GPIO->DATA >> 24);
	radio_write8(AX5051_REG_PINCFG2, 0xD0);
	switch(p) {
	case 0x20: /* IRQ on PR5 */
		// PR5 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR5 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x20000000;     // Configure PR5 to input
		GPIO_AND->INT_TYP = ~0x20000000;    // Configure PR5 to level triggered
		GPIO_OR->INT_POL = 0x20000000;      // Configure PR5 to rising edge
		GPIO_AND->INT_EN = ~0x20000000;     // Disable PR5 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<29));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<29));       // Disable pull down
		break;

	case 0x40: /* IRQ on PR6 */
		// PR6 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR6 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x40000000;     // Configure PR6 to input
		GPIO_AND->INT_TYP = ~0x40000000;    // Configure PR6 to level triggered
		GPIO_OR->INT_POL = 0x40000000;      // Configure PR6 to rising edge
		GPIO_AND->INT_EN = ~0x40000000;     // Disable PR6 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<30));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<30));       // Disable pull down
		break;

	default:
		/* Error */
		radio_write8(AX5051_REG_PINCFG1, 0xA0 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	/*
	 * Check voltage on test mode pins and drive them
	 * to the correct level. This is somewhat dangerous - we
	 * may momentarily short circuit the output driver (4mA)
	 * no short circuit will happen if the board complies
	 * to AX5051/AX5151/AX8052F151 programming manual
	 */
	/* check T2 */
	radio_write8(AX5051_REG_PINCFG1, 0xC0 | pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x01));
	/* check T1 */
	radio_write8(AX5051_REG_PINCFG1, 0x80 | pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x04));
	/* check TST3 */
	radio_write8(AX5051_REG_PINCFG1, pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x08));
	exit_critical(crit);
	return 0;
}

#elif defined __AXM0F2

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5051_probeirq(void) __reentrant
{
	uint8_t p = 0x10;
	uint8_t pc1 = radio_read8(AX5051_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	radio_write8(AX5051_REG_PINCFG1, 0xD0 | pc1);
	radio_write8(AX5051_REG_PINCFG2, 0xF2); /* IRQ Line 1 */
	p &= GPIO_PRT2->PS;
	radio_write8(AX5051_REG_PINCFG2, 0xF0); /* IRQ Line 0 */
	p &= (uint8_t)~GPIO_PRT2->PS;
	radio_write8(AX5051_REG_PINCFG2, 0xD0);
	switch(p) {
	case 0x10: /* IRQ on P2[4] */
		break;

	default:
		/* Error */
		GPIO_PRT2->PC |= 7 << 12; /* enable PD/PU */
		radio_write8(AX5051_REG_PINCFG1, 0xA0 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	/*
	 * Check voltage on test mode pins and drive them
	 * to the correct level. This is somewhat dangerous - we
	 * may momentarily short circuit the output driver (4mA)
	 * no short circuit will happen if the board complies
	 * to AX5051/AX5151/AX8052F151 programming manual
	 */
	/* check T2 */
	radio_write8(AX5051_REG_PINCFG1, 0xC0 | pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x01));
	/* check T1 */
	radio_write8(AX5051_REG_PINCFG1, 0x80 | pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x04));
	/* check TST3 */
	radio_write8(AX5051_REG_PINCFG1, pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x08));
	exit_critical(crit);
	return 0;
}

#endif

#else

__reentrantb uint8_t ax5051_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5051_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	PORTR = 0xEB;
	radio_write8(AX5051_REG_PINCFG1, 0xD0 | pc1);
	radio_write8(AX5051_REG_PINCFG2, 0xF2); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5051_REG_PINCFG2, 0xF0); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5051_REG_PINCFG2, 0xD0);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5051_REG_PINCFG1, 0xA0 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	/*
	 * Check voltage on test mode pins and drive them
	 * to the correct level. This is somewhat dangerous - we
	 * may momentarily short circuit the output driver (4mA)
	 * no short circuit will happen if the board complies
	 * to AX5051/AX5151/AX8052F151 programming manual
	 */
	/* check T2 */
	radio_write8(AX5051_REG_PINCFG1, 0xC0 | pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x01));
	/* check T1 */
	radio_write8(AX5051_REG_PINCFG1, 0x80 | pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x04));
	/* check TST3 */
	radio_write8(AX5051_REG_PINCFG1, pc1);
	radio_write8(AX5051_REG_PINCFG2, radio_read8(AX5051_REG_PINCFG2) | (radio_read8(AX5051_REG_PINCFG3) & 0x08));
	IE |= p;
	/* check whether TST3 is connected to PR5 - if so disable pullup */
	PORTR &= PINR | (uint8_t)~0x20;
	exit_critical(crit);
	return 0;
}

#endif

#endif
