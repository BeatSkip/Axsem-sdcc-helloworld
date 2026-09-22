/*
This is the startup file for CM0. The C definition of the vector tables are defined in vector.c
*/

	.syntax	unified
	.arch	armv6-m

	.section .stack
	.align	3
	.equ	Stack_Size, 0x400 /* 1K stack size */

	.globl	__StackTop
	.globl	__StackLimit

__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

.section .isr_vectors
.align 2
.globl	__isr_vector /* The symbol __isr_vector can  be used in ld file */

__isr_vector:

	.long __StackTop				/* Top of Stack */
	.long Reset_Handler             /* Reset Handler */
	.long NMI_Handler               /* NMI Handler */
	.long HardFault_Handler         /* Hard Fault Handler */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long SVC_Handler               /* SVCall Handler */
	.long 0                         /* Reserved */
	.long 0                         /* Reserved */
	.long PendSV_Handler            /* PendSV Handler */
	.long SysTick_Handler           /* SysTick Handler */

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

	.size	__isr_vector, . - __isr_vector

	.text
	.thumb
	.thumb_func
	.align 1
	.global Reset_Handler
	.func Reset_Handler, Reset_Handler
	.type Reset_Handler, %function


Reset_Handler:

	/* load stack pointer */
	ldr	r3, =__StackTop
	mov	sp, r3

	/* Call System init */
	/* This function includes code for handling low power modes */
	bl	SystemInit
	cmp r0, #0
	bne .L_callmain

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

/*  Zero out bss section.
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

.L_callmain:

	/* call main */
	bl	main

	/* Call default handler if main returns */
	b Default_Handler

	.align
.Lstack:
	.word	__StackTop
.Lbssstart:
	.word	__bss_start__
.Lbssend:
	.word	__bss_end__


	.size Reset_Handler, . - Reset_Handler
	.pool

	.endfunc /* End of function Reset Handler */

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

	def_irq_handler		NMI_Handler
	def_irq_handler		HardFault_Handler
	def_irq_handler		SVC_Handler
	def_irq_handler		PendSV_Handler
	def_irq_handler		SysTick_Handler

	.macro	def_prog_irq_handler	handler_name
	.weak	\handler_name
	.set	\handler_name, Default_Handler
	.endm

	def_prog_irq_handler	GPIO_Handler
	def_prog_irq_handler    WakeupTimer_Handler
	def_prog_irq_handler    ClockSysConfig_Handler
	def_prog_irq_handler    AnalogComp_Handler
	def_prog_irq_handler    ADC_Handler
	def_prog_irq_handler    AES_Handler
	def_prog_irq_handler    TRNG_Handler
	def_prog_irq_handler    FLASH_Handler
	def_prog_irq_handler    Watchdog_Handler
	def_prog_irq_handler    TickerTimer_Handler
	def_prog_irq_handler    Timer0_Handler
	def_prog_irq_handler    Timer1_Handler
	def_prog_irq_handler    Timer2_Handler
	def_prog_irq_handler    CC_PMW0_Handler
	def_prog_irq_handler    CC_PMW1_Handler
	def_prog_irq_handler    CC_PMW2_Handler
	def_prog_irq_handler    CC_PMW3_Handler
	def_prog_irq_handler    SPI0_Handler
	def_prog_irq_handler    SPI1_Handler
	def_prog_irq_handler    UART0_Handler
	def_prog_irq_handler    UART1_Handler
	def_prog_irq_handler    I2C_Handler
	def_prog_irq_handler    DMAError_Handler
	def_prog_irq_handler    DMADone_Handler

	.end
