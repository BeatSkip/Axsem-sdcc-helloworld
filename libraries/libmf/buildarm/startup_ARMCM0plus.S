/**************************************************************************//**
 * @file     startup_ARMCM0plus.s
 * @brief    CMSIS Core Device Startup File for
 *           ARMCM0plus Device Series
 * @version  V5.00
 * @date     02. March 2016
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

	.syntax	unified
	.arch	armv6-m

	.extern __StackTop

	.section .vectors
	.align 2
	.globl	__Vectors
__Vectors:
	.long	__StackTop            /* Top of Stack */
	.long	Reset_Handler         /* Reset Handler */
	.long	NMI_Handler           /* NMI Handler */
	.long	HardFault_Handler     /* Hard Fault Handler */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	SVC_Handler           /* SVCall Handler */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	PendSV_Handler        /* PendSV Handler */
	.long	SysTick_Handler       /* SysTick Handler */

	/* External interrupts */
#ifdef __AXM0
	.long GPIO_Handler              /* GPIO Handler - 16 */
	.long WakeupTimer_Handler       /* Wake up timer Handler - 17 */
	.long ClockSysConfig_Handler    /* Clock and System Config Handler - 18 */
	.long AnalogComp_Handler        /* Analog Comparator Handler- 19 */
	.long ADC_Handler               /* ADC Handler - 20 */
	.long AES_Handler               /* AES Handler - 21 */
	.long TRNG_Handler              /* TRNG Handler - 22 */
	.long FLASH_Handler             /* Flash Handler - 23 */
	.long Watchdog_Handler   		/* Watchdog Handler - 24 */
	.long TickerTimer_Handler       /* TickerTimer Handler - 25 */
	.long Timer0_Handler            /* Timer 0 Handler - 26 */
	.long Timer1_Handler            /* Timer 1 Handler - 27 */
	.long Timer2_Handler            /* Timer 2 Handler - 28 */
	.long CC_PMW0_Handler           /* PWM 0 Handler - 29 */
	.long CC_PMW1_Handler           /* PWM 1 Handler - 30 */
	.long CC_PMW2_Handler           /* PWM 2 Handler - 31 */
	.long CC_PMW3_Handler  			/* PWM 3 Handler - 32 */
	.long SPI0_Handler     			/* SPI0 Handler - 33 */
	.long SPI1_Handler              /* SPI1 Handler - 34 */
	.long UART0_Handler             /* UART 0 Handler - 35 */
	.long UART1_Handler             /* UART 1 Handler - 36 */
	.long I2C_Handler               /* I2C Handler - 37 */
	.long DMAError_Handler         	/* DMA Error Handler - 38 */
	.long DMADone_Handler         	/* DMA Done Handler - 39 */
#endif	
#ifdef __AXM0F2
	.long GPIOPort0_Handler         /* GPIOPort0 Handler - 16 */
	.long GPIOPort1_Handler         /* GPIOPort1 Handler - 17 */
	.long GPIOPort2_Handler         /* GPIOPort2 Handler - 18 */
	.long GPIOPort3_Handler         /* GPIOPort3 Handler - 19 */
	.long GPIO_Handler              /* GPIO Handler - 20 */
	.long LPComp_Handler            /* LPComp Handler - 21 */
	.long WDT_Handler               /* WDT Handler - 22 */
	.long SCB0_Handler              /* SCB0 Handler - 23 */
	.long SCB1_Handler              /* SCB1 Handler - 24 */
	.long SCB2_Handler              /* SCB2 Handler - 25 */
	.long CTBm_Handler              /* CTBm Handler - 26 */
	.long WCOWDT_Handler            /* WCOWDT Handler - 27 */
	.long SPCIF_Handler             /* SPCIF Handler - 28 */
	.long CSD_Handler               /* CSD Handler - 29 */
	.long TCPWM0_Handler            /* TCPWM0 Handler - 30 */
	.long TCPWM1_Handler            /* TCPWM1 Handler - 31 */
	.long TCPWM2_Handler            /* TCPWM2 Handler - 32 */
	.long TCPWM3_Handler            /* TCPWM3 Handler - 33 */
	.long TCPWM4_Handler            /* TCPWM4 Handler - 34 */
	.long ADC_Handler               /* ADC Handler - 35 */
#endif	

	.size	__Vectors, . - __Vectors

	.text
	.thumb
	.thumb_func
	.align	1
	.globl	Reset_Handler
	.type	Reset_Handler, %function
Reset_Handler:
#ifdef __AXM0F2
	.extern	__startcause
	ldr	r1, =__startcause
	movs	r0, 0
	str	r0, [r1]
Reset_Handler_NoStartCause:
	.globl	Reset_Handler_NoStartCause
#endif	

#ifndef __NO_SYSTEM_INIT
	/* Call System init */
	/* This function includes code for handling low power modes */
	bl	SystemInit
	cmp	r0, #0
	bne	.L_callstart
#endif

/*  Firstly it copies data from read only memory to RAM. There are two schemes
 *  to copy. One can copy more than one sections. Another can only copy
 *  one section.  The former scheme needs more instructions and read-only
 *  data to implement than the latter.
 *  Macro __STARTUP_COPY_MULTIPLE is used to choose between two schemes.  */

#ifdef __STARTUP_COPY_MULTIPLE
/*  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of triplets, each of which specify:
 *    offset 0: LMA of start of a section to copy from
 *    offset 4: VMA of start of a section to copy to
 *    offset 8: size of the section to copy. Must be multiply of 4
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
	ldr	r4, =__copy_table_start__
	ldr	r5, =__copy_table_end__

.L_loop0:
	cmp	r4, r5
	bge	.L_loop0_done
	ldr	r1, [r4]
	ldr	r2, [r4, #4]
	ldr	r3, [r4, #8]

.L_loop0_0:
	subs	r3, #4
	blt	.L_loop0_0_done
	ldr	r0, [r1, r3]
	str	r0, [r2, r3]
	b	.L_loop0_0

.L_loop0_0_done:
	adds	r4, #12
	b	.L_loop0

.L_loop0_done:
#else
/*  Single section scheme.
 *
 *  The ranges of copy from/to are specified by following symbols
 *    __etext: LMA of start of the section to copy from. Usually end of text
 *    __data_start__: VMA of start of the section to copy to
 *    __data_end__: VMA of end of the section to copy to
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
	ldr	r1, =__etext
	ldr	r2, =__data_start__
	ldr	r3, =__data_end__

	subs	r3, r2
	ble	.L_loop1_done

.L_loop1:
	subs	r3, #4
	ldr	r0, [r1,r3]
	str	r0, [r2,r3]
	bgt	.L_loop1

.L_loop1_done:
#endif /*__STARTUP_COPY_MULTIPLE */

/*  This part of work usually is done in C library startup code. Otherwise,
 *  define this macro to enable it in this startup.
 *
 *  There are two schemes too. One can clear multiple BSS sections. Another
 *  can only clear one section. The former is more size expensive than the
 *  latter.
 *
 *  Define macro __STARTUP_CLEAR_BSS_MULTIPLE to choose the former.
 *  Otherwise efine macro __STARTUP_CLEAR_BSS to choose the later.
 */
#ifdef __STARTUP_CLEAR_BSS_MULTIPLE
/*  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of tuples specifying:
 *    offset 0: Start of a BSS section
 *    offset 4: Size of this BSS section. Must be multiply of 4
 */
	ldr	r3, =__zero_table_start__
	ldr	r4, =__zero_table_end__

.L_loop2:
	cmp	r3, r4
	bge	.L_loop2_done
	ldr	r1, [r3]
	ldr	r2, [r3, #4]
	movs	r0, 0

.L_loop2_0:
	subs	r2, #4
	blt	.L_loop2_0_done
	str	r0, [r1, r2]
	b	.L_loop2_0
.L_loop2_0_done:

	adds	r3, #8
	b	.L_loop2
.L_loop2_done:
#elif defined (__STARTUP_CLEAR_BSS)
/*  Single BSS section scheme.
 *
 *  The BSS section is specified by following symbols
 *    __bss_start__: start of the BSS section.
 *    __bss_end__: end of the BSS section.
 *
 *  Both addresses must be aligned to 4 bytes boundary.
 */
	ldr	r1, =__bss_start__
	ldr	r2, =__bss_end__

	movs	r0, 0

	subs	r2, r1
	ble	.L_loop3_done

.L_loop3:
	subs	r2, #4
	str	r0, [r1, r2]
	bgt	.L_loop3
.L_loop3_done:
#endif /* __STARTUP_CLEAR_BSS_MULTIPLE || __STARTUP_CLEAR_BSS */

.L_callstart:
#ifndef __START
#define __START _start
#endif
	bl	__START
	/* infinite loop if __START returns */
.Lstop:
	b	.Lstop

	.pool
	.size	Reset_Handler, . - Reset_Handler

	.align	1
	.thumb_func
	.weak	Default_Handler
	.type	Default_Handler, %function
Default_Handler:
	b	.
	.size	Default_Handler, . - Default_Handler

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
	.macro	def_irq_handler	handler_name
	.weak	\handler_name
	.set	\handler_name, Default_Handler
	.endm

	def_irq_handler	NMI_Handler
	def_irq_handler	HardFault_Handler
	def_irq_handler	SVC_Handler
	def_irq_handler	PendSV_Handler
	def_irq_handler	SysTick_Handler

#ifdef __AXM0
	def_irq_handler	GPIO_Handler
	def_irq_handler	WakeupTimer_Handler
	def_irq_handler	ClockSysConfig_Handler
	def_irq_handler	AnalogComp_Handler
	def_irq_handler	ADC_Handler
	def_irq_handler	AES_Handler
	def_irq_handler	TRNG_Handler
	def_irq_handler	FLASH_Handler
	def_irq_handler	Watchdog_Handler
	def_irq_handler	TickerTimer_Handler
	def_irq_handler	Timer0_Handler
	def_irq_handler	Timer1_Handler
	def_irq_handler	Timer2_Handler
	def_irq_handler	CC_PMW0_Handler
	def_irq_handler	CC_PMW1_Handler
	def_irq_handler	CC_PMW2_Handler
	def_irq_handler	CC_PMW3_Handler
	def_irq_handler	SPI0_Handler
	def_irq_handler	SPI1_Handler
	def_irq_handler	UART0_Handler
	def_irq_handler	UART1_Handler
	def_irq_handler	I2C_Handler
	def_irq_handler	DMAError_Handler
	def_irq_handler	DMADone_Handler
#endif	
#ifdef __AXM0F2
	def_irq_handler	GPIOPort0_Handler
	def_irq_handler	GPIOPort1_Handler
	def_irq_handler	GPIOPort2_Handler
	def_irq_handler	GPIOPort3_Handler
	def_irq_handler	GPIO_Handler
	def_irq_handler	LPComp_Handler
	def_irq_handler	WDT_Handler
	def_irq_handler	SCB0_Handler
	def_irq_handler	SCB1_Handler
	def_irq_handler	SCB2_Handler
	def_irq_handler	CTBm_Handler
	def_irq_handler	WCOWDT_Handler
	def_irq_handler	SPCIF_Handler
	def_irq_handler	CSD_Handler
	def_irq_handler	TCPWM0_Handler
	def_irq_handler	TCPWM1_Handler
	def_irq_handler	TCPWM2_Handler
	def_irq_handler	TCPWM3_Handler
	def_irq_handler	TCPWM4_Handler
	def_irq_handler	ADC_Handler
	def_irq_handler	RADIO_IRQ
#endif	

	.end
