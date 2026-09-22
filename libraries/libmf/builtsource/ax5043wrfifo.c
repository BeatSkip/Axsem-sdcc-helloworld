/**
******************************************************************************
* @file radiowrfifo.c
* @brief radio FIFO write function
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

#define RADIO 5043

#include "radiodefs.h"

#if defined(SDCC)

__reentrantb void radio_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant __naked
{
	ptr;
	len;
        __asm;
	mov	a,sp
	add	a,#-2
	mov	r0,a
	mov	a,@r0
	jz	nodata$
	mov	r7,a
	jb	_B_7,codeptr$		; >0x80 code
	jnb	_B_6,xdataptr$		; <0x40 far
	mov	r0,dpl
	mov	dptr,#(AX8052_RADIOBASE | FDATA)
	jb	_B_5,pdataptr$		; >0x60 pdata
idataloop$:
	mov	a,@r0
	movx	@dptr,a
	inc	r0
	djnz	r7,idataloop$
nodata$:
	ret
pdataptr$:
pdataloop$:
	movx	a,@r0
	movx	@dptr,a
	inc	r0
	djnz	r7,pdataloop$
	ret
xdataptr$:
	mov	a,#0x80
	anl	a,_IE
	mov	r5,a
	clr	_EA
	mov	r6,_XPAGE
	mov	_XPAGE,#((AX8052_RADIOBASE | FDATA) >> 8)
	mov	r0,#(AX8052_RADIOBASE | FDATA)
xdataloop$:
	movx	a,@dptr
	movx	@r0,a
	inc	dptr
	djnz	r7,xdataloop$
	mov	_XPAGE,r6
	mov	a,r5
	orl	_IE,a
	ret
codeptr$:
	mov	a,#0x80
	anl	a,_IE
	mov	r5,a
	clr	_EA
	mov	r6,_XPAGE
	mov	_XPAGE,#((AX8052_RADIOBASE | FDATA) >> 8)
	mov	r0,#(AX8052_RADIOBASE | FDATA)
codeloop$:
	clr	a
	movc	a,@a+dptr
	movx	@r0,a
	inc	dptr
	djnz	r7,codeloop$
	mov	_XPAGE,r6
	mov	a,r5
	orl	_IE,a
	ret
        __endasm;
}

#elif defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

#include "radioutil.h"

__reentrantb void radio_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant
{
	while (len) {
		unsigned int len1 = len;
		if (len1 > 8)
			len1 = 8;
		_radio_spi_bulkio(0x80, (FDATA), ptr, 0, len1);
		ptr += len1;
		len -= len1;
	}
}

#else

__reentrantb void radio_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant
{
	if (!len)
		return;
#if ((RADIO == 5043 || RADIO == 5044  /* or 5045 */ ) && (FDATA) >= 0x70)
	volatile uint32_t *fifo = (uint32_t *)((((FDATA) | 0x7000) << 2) | 0x000000 | SPI0_BASE);
#else
	volatile uint32_t *fifo = (uint32_t *)(((FDATA) << 2) | 0x020000 | SPI0_BASE);
#endif
	do {
		*fifo = *ptr++;
	} while (--len);
}

#endif

#else

__reentrantb void radio_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant
{
	if (!len)
		return;
	do {
		*(uint8_t __xdata *)(AX8052_RADIOBASE | FDATA) = *ptr++;
	} while (--len);
}

#endif
