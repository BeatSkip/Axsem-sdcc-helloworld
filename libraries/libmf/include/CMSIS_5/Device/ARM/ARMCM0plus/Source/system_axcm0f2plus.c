/**************************************************************************//**
 * @file     system_ARMCM0f2plus.c
 * @brief    CMSIS Device System Source File for
 *           ARMCM0plus Device Series
 * @version  V5.00
 * @date     07. September 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "axm0f2.h"
#include "libmftypes.h"

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define  SYSTEM_CLOCK    (48000000UL) 		/* 48 MHz clock */


/*----------------------------------------------------------------------------
  Externals
 *----------------------------------------------------------------------------*/
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
extern uint32_t __Vectors;
#endif

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
/*
 * ToDo: initialize SystemCoreClock with the system core clock frequency value
 * achieved after system intitialization.
 * This means system core clock frequency after call to SystemInit()
 */
uint32_t SystemCoreClock = SYSTEM_CLOCK;

/*----------------------------------------------------------------------------
  System Core Clock update function
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)
{
	/*
	 * TODO: add code to calculate the system frequency based upon the current
	 * register settings.
	 * This function can be used to retrieve the system core clock frequeny
	 * after user changed register sittings.
	 */
	SystemCoreClock = SYSTEM_CLOCK;
}

static inline void delay_cycles(unsigned int cyc)
{
 	cyc += 2;
	cyc >>= 2;
	if (!cyc)
                return;
	__asm volatile(".syntax unified\n\t"
		       ".align 2\n"
		       "0:\n\t"
		       "subs\t%0, %0, #1\n\t"
		       "cmp\t%0, #0\n\t"
		       "bne\t0b" : "=r" (cyc) : "0" (cyc));
}

static inline void set_imo_frequency(uint32_t freq)
{
        criticalsection_t crit;
	uint32_t wcoLock;

	if ((freq != 24u) && (freq != 28u) && (freq != 32u) &&
	    (freq != 36u) && (freq != 40u) && (freq != 44u) &&
	    (freq != 48u)) {
#ifdef NDEBUG
		__asm volatile("bkpt\t1");
#endif
		return;
	}
	crit = enter_critical();

	wcoLock = WCO->CONFIG & 0x40000000;
	WCO->CONFIG &= ~0x40000000;

	/* Set IMO to 24 MHz - CLK_IMO_SELECT.FREQ = 0 */
	SRSSLT->CLK_IMO_SELECT &= ~0x07;

	/* Apply coarse trim */
	SRSSLT->CLK_IMO_TRIM1 = (&(SFLASH->IMO_TRIM_LT0))[freq - 24];

	/* Zero out fine trim */
	SRSSLT->CLK_IMO_TRIM2 &= ~0x07;

	/* Apply TC trim */
	SRSSLT->CLK_IMO_TRIM3 = (SRSSLT->CLK_IMO_TRIM3 & ~0x7F) | ((&(SFLASH->IMO_TCTRIM_LT0))[freq - 24] & 0x7F);

	delay_cycles(50);

	if (freq > 24) {
		/* Select nearby intermediate frequency */
		SRSSLT->CLK_IMO_SELECT = (SRSSLT->CLK_IMO_SELECT & ~0x07) | (((freq - 28) >> 2) & 0x07);
		delay_cycles(50);
		/* Make small step to final frequency */
		/* Select nearby intermediate frequency */
		SRSSLT->CLK_IMO_SELECT = (SRSSLT->CLK_IMO_SELECT & ~0x07) | (((freq - 24) >> 2) & 0x07);
	}
	WCO->CONFIG |= wcoLock;
	exit_critical(crit);
}

static inline void set_timer_source(uint32_t source)
{
	source &= 0xC0000000;
        if ((WCO->WDT_CONFIG & 0xC0000000) != source) {
		criticalsection_t crit;

		/* Reset both _EN bits in WCO->WDT_CLKEN register */
		WCO->WDT_CLKEN &= ~0x03;

		/* Wait 4 new clock source-cycles for change to come into effect */
		delay((WCO->WDT_CONFIG & 0xC0000000) ? /* ILO */ 268 : /* WCO */ 124);

		crit = enter_critical();
		WCO->WDT_CONFIG = (WCO->WDT_CONFIG & ~0xC0000000) | source;
		exit_critical(crit);
        }

        WCO->WDT_CLKEN = (WCO->WDT_CLKEN & ~0x03) |
		((WCO->WDT_CONFIG & 0xC0000000) ? /* WCO */ 0x01 : /* ILO */ 0x02);
}

static inline void SmartIO_init(void)
{
	//*********************** SMARTIO_0**********************************
	/* Must disable the block before configuring */
	PRGIO_PRT0->CTL &= ~(1<<31);                                             // disable smartIO
	/* General control */
	PRGIO_PRT0->CTL = (0x18<<0)|(31<<8)|(0<<24)|(0<<25);                     // configure smartIO (bypass pins, clock-async, overhold func, disable pipeline,
	/* Synchronization control */
	PRGIO_PRT0->SYNC_CTL = 0x00;                                             // sync off for LUTs

	/* LUT input selection */
	PRGIO_PRT0->LUT_SEL0 = (uint32_t)((8<<0)|(8<<8)|(8<<16));               // data0
	PRGIO_PRT0->LUT_SEL1 = (uint32_t)((4<<0)|(4<<8)|(4<<16));               // LUT4
	PRGIO_PRT0->LUT_SEL2 = (uint32_t)((10<<0)|(10<<8)|(10<<16));            // data2
	PRGIO_PRT0->LUT_SEL3 = (uint32_t)((14<<0)|(14<<8)|(14<<16));             // gpio2 (14)
	PRGIO_PRT0->LUT_SEL4 = (uint32_t)((14<<0)|(14<<8)|(14<<16));            // gpio6
	PRGIO_PRT0->LUT_SEL5 = (uint32_t)((5<<0)|(0<<8)|(0<<16));               // lut5, lut0,lut0      ///////////////////////
	PRGIO_PRT0->LUT_SEL6 = (uint32_t)((3<<0)|(3<<8)|(3<<16));               // lut3 (3)
	PRGIO_PRT0->LUT_SEL7 = (uint32_t)((2<<0)|(2<<8)|(2<<16));               // lut2
	/* LUT input control */
	PRGIO_PRT0->LUT_CTL0 = (uint32_t)(128<<0);
	PRGIO_PRT0->LUT_CTL1 = (uint32_t)(128<<0);
	PRGIO_PRT0->LUT_CTL2 = (uint32_t)(128<<0);
	PRGIO_PRT0->LUT_CTL3 = (uint32_t)(128<<0);
	PRGIO_PRT0->LUT_CTL4 = (uint32_t)(128<<0);
	PRGIO_PRT0->LUT_CTL5 = (uint32_t)(192<<0);                                                  /////////////////////////
	PRGIO_PRT0->LUT_CTL6 = (uint32_t)(128<<0);
	PRGIO_PRT0->LUT_CTL7 = (uint32_t)(128<<0);
	/* LUT input data unit */
	PRGIO_PRT0->DU_SEL = (uint32_t)((0<<0)|(0<<8)|(0<<16)|(0<<24)|(0<<28));
	PRGIO_PRT0->DU_CTL = (uint32_t)((7<<0)|(1<<8));
	PRGIO_PRT0->DATA = (uint32_t)(0x00);
	PRGIO_PRT0->CTL |= 1<<31;                                                // enable smartIO*/
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
unsigned int SystemInit (void) __attribute__ ((weak));
unsigned int SystemInit (void)
{
	/* Disable WDT */
	SRSSLT->WDT_DISABLE_KEY = 0xACED8865;

	/* Pre-fetch enable, Slow flash: 2 wait states */
	CPUSS->FLASH_CTL = 0x0012u;

	/* Update IMO to new clock speed. */
	set_imo_frequency(48u);

	/* Map pin 0.4 and 0.5 to UART1 */
	HSIOM->PORT_SEL0 = 0x00BB0000u;

	/* Map pin 1.2 to AMUXA */
	HSIOM->PORT_SEL1 = 0x00000600u;

	/* Map pin 2.0 to MOSI, 2.1 to MISO, 2.2 to SCLK */
	HSIOM->PORT_SEL2 = 0x00000FFFu;

	/* Map pin 3.2 to SWD_DATA and 3.3 to SWD_CLK */
	HSIOM->PORT_SEL3 = 0x0000EE00u; /* TODO system default, not required? */

	/* Set RSEL pin 3.0 to Active Low */
	HSIOM->PORT_SEL3 &= ~0xF;       /* 3.0 as GPIO */

	/* Basic GPIO Configuration */

	/*
	 * Port 2:
	 * P2[0]: SmartIO  off
	 * P2[1]: SmartIO  off
	 * P2[2]: ANTSEL   input
	 * P2[3]: PWRAMP   input
	 * P2[4]: IRQ      input
	 * P2[5]: MOSI     0_1
	 * P2[6]: MISO     input
	 * P2[7]: CLK      0_1
	 */
	GPIO_PRT2->PC = 0x00C71240;

	/*
	 * Port 3:
	 * P3[0]: SEL      0_1
	 * P3[1]: SYSCLK   input
	 * P3[2]: SWD DATA 0_1
	 * P3[3]: SWD CLK  0_1
	 */
	GPIO_PRT3->DR = 0x00000001;
	GPIO_PRT3->PC = 0x00000D8E;

	/* Setup phase aligned clocks */
	/*
	 * Use of dividers by libmf:
	 * 16[0]: 
	 * 16[1]: 
	 * 16[2]: 
	 * 16[3]:
	 * 16[4]: ADC - FIXME
	 * 16[5]: Radio SPI
	 * 16_5[0]: 
	 * 16_5[1]: 
	 * 16_5[2]: 
	 */

	PERI->DIV_16_CTL4   = 0x00001D00u;
	PERI->DIV_CMD       = 0x8000FF44u;

	/* SCB1 - RADIO SPI divider */
	PERI->DIV_16_CTL5   = 0x00000000u;
	PERI->DIV_CMD       = 0x8000FF45u;

	SRSSLT->CLK_SELECT  = 0x00000020u;

	// PERI->PCLK_CTL0  SCB0
	// PERI->PCLK_CTL1  SCB1
	// PERI->PCLK_CTL2  SCB2
	// PERI->PCLK_CTL3  CSD
	// PERI->PCLK_CTL4  TCPWM0
	// PERI->PCLK_CTL5  TCPWM1
	// PERI->PCLK_CTL6  TCPWM2
	// PERI->PCLK_CTL7  TCPWM3
	// PERI->PCLK_CTL8  TCPWM4
	// PERI->PCLK_CTL9  SmartIO
	// PERI->PCLK_CTL10 SmartIO
	// PERI->PCLK_CTL11 LCD
	// PERI->PCLK_CTL12 SAR ADC
	PERI->PCLK_CTL12    = 0x00000044u;
	PERI->PCLK_CTL1     = 0x00000045u;

	WCO->WDT_CONFIG = 0x00000000u;

	/* 0 -- ILO; 0x40000000 -- WCO */
	set_timer_source(0);	
	SRSSLT->CLK_ILO_CONFIG |= 0x80000000;

	CTBM0->DFT_CTRL = 0x00000003u;
	SAR->CTRL = 0x80000000u;
	SAR->MUX_SWITCH0 = 0x000700B0u;
	SAR->MUX_SWITCH_HW_CTRL = 0x000700B0u;
	PASS_DSAB->DSAB_CTRL = 0x00000000u;

	SAR->PUMP_CTRL |= 0x80000000u;

	/* initialize the Radio SPI */
	/* Configure RADIO - SPI interface */
	SCB1->CTRL = (6 - 1) /* oversampling - 8 MHz clock speed */ | 0x01000800;
	SCB1->SPI_CTRL = 0x80000001;

	/* Configure RX direction */
	SCB1->RX_CTRL = 0x80000107;
	SCB1->RX_FIFO_CTRL = 7;

	/* Configure TX direction */
	SCB1->TX_CTRL = 0x80000107;
	SCB1->TX_FIFO_CTRL = 0;

	/* Configure interrupt sources */
	SCB1->INTR_I2C_EC_MASK = 0;
	SCB1->INTR_SPI_EC_MASK = 0;
	SCB1->INTR_S_MASK = 0;
	SCB1->INTR_M_MASK = 0;
	SCB1->INTR_RX_MASK = 0;
	SCB1->INTR_TX_MASK = 0;

	/* Enable */
	SCB1->CTRL |= 0x80000000;

	SmartIO_init();
	_axm0f2_external_startup();


#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
	SCB->VTOR = (uint32_t) &__Vectors;
#endif

	SystemCoreClock = SYSTEM_CLOCK;
	return 0;
}

/*----------------------------------------------------------------------------
  Weak dummy function for _axm0f2_external_startup
*----------------------------------------------------------------------------*/
__attribute__((weak)) uint8_t _axm0f2_external_startup(void)
{
	return 0;
}
