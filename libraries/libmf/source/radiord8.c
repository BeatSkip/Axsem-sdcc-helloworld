/**
******************************************************************************
* @file radiord8.c
* @brief 8 bit read of radio register
* @internal
* @author   Thomas Sailer
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

#include "cpu.h"
#include "libmftypes.h"

#if defined(SDCC)

__reentrantb uint8_t radio_read8(uint16_t addr) __reentrant __naked
{
	addr;
        __asm;
	mov	a,dph
	anl	a,#0x0F
	orl	a,#(AX8052_RADIOBASE >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dpl,a
	ret
        __endasm;
}

#elif defined __ARMEL__ || defined __ARMEB__

#include "libmfradio.h"

#ifdef __AXM0F2

#include "radioutil.h"

__reentrantb uint8_t _radio_read8(uint32_t addr) __reentrant
{
	return _radio_spi_io(0x00, addr, 0, 1);
}

#else

__reentrantb uint8_t _radio_read8(uint32_t addr) __reentrant
{
	return *_radio_addr(addr, 0);
}

#endif

#else

__reentrantb uint8_t radio_read8(uint16_t addr) __reentrant
{
	addr &= 0xFFF;
	addr |= AX8052_RADIOBASE;
	return *(volatile uint8_t __xdata *)addr;
}

#endif
