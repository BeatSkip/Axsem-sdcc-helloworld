/*
This is the startup file for AXM0F2. The C definition of the vector tables are defined in vector.c
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

	.section .isr_vectors ,"a",%progbits
	.align 2
	.globl	__isr_vector /* The symbol __isr_vector can  be used in ld file */

__isr_vector:

	.long __StackTop		/* Top of Stack */
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

	.size	__isr_vector, . - __isr_vector

	.text
	.thumb
	.thumb_func
	.align 1
	.global Reset_Handler
	.func Reset_Handler, Reset_Handler
	.type Reset_Handler, %function


Reset_Handler:
	/* Done : Handling stack pointer and stack data when coming out of low power modes */
	/* load stack pointer */
	ldr	r3, =__StackTop
	mov	sp, r3

	/* Call System init */
	/* This function includes code for handling low power modes */
	bl	SystemInit
	cmp	r0, #0
	bne	.L_callmain

/*  Single section scheme.
 *
 *  The ranges of copy from/to are specified by following symbols
 *    __etext: LMA of start of the section to copy from. Usually end of text
 *    __data_start__: VMA of start of the section to copy to
 *    __data_end__: VMA of end of the section to copy to
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
	ldr	r1, =__data_init__
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
	/* infinite loop if main returns */
.Lstop:
	b	.Lstop

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

	def_prog_irq_handler	GPIOPort0_Handler
	def_prog_irq_handler	GPIOPort1_Handler
	def_prog_irq_handler	GPIOPort2_Handler
	def_prog_irq_handler	GPIOPort3_Handler
	def_prog_irq_handler	GPIO_Handler
	def_prog_irq_handler	LPComp_Handler
	def_prog_irq_handler	WDT_Handler
	def_prog_irq_handler	SCB0_Handler
	def_prog_irq_handler	SCB1_Handler
	def_prog_irq_handler	SCB2_Handler
	def_prog_irq_handler	CTBm_Handler
	def_prog_irq_handler	WCOWDT_Handler
	def_prog_irq_handler	SPCIF_Handler
	def_prog_irq_handler	CSD_Handler
	def_prog_irq_handler	TCPWM0_Handler
	def_prog_irq_handler	TCPWM1_Handler
	def_prog_irq_handler	TCPWM2_Handler
	def_prog_irq_handler	TCPWM3_Handler
	def_prog_irq_handler	TCPWM4_Handler
	def_prog_irq_handler	ADC_Handler

	.end
