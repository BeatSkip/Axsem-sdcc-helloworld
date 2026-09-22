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
#include "libmftypes.h"

#ifdef SDCC

/**
 * \brief reset the CPU
 *
 */
__reentrantb void reset_cpu(void) __reentrant
{
	__disable_irq();
	GPIOENABLE = 0;
	CODECONFIG = 0xD3;
	__asm
	ljmp 0xE047
	__endasm;
}

#elif defined __CX51__ || defined __C51__

__reentrantb void reset_cpu(void) __reentrant
{
	__disable_irq();
	GPIOENABLE = 0;
	CODECONFIG = 0xD3;
#pragma asm
	ljmp 0xE047
#pragma endasm
}

#elif defined __ICC8051__

__noreturn __reentrantb void reset_cpu(void) __reentrant
{
	__disable_irq();
	GPIOENABLE = 0;
	CODECONFIG = 0xD3;
	asm("ljmp 0xE047");
}

#elif defined __ARMEL__ || defined __ARMEB__

__reentrantb void reset_cpu(void) __reentrant
{
	__disable_irq();
	//GPIOENABLE = 0; // FIXME
	NVIC_SystemReset();
}

#else

#error "Compiler unsupported"

#endif
