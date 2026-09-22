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

#include "libmfcrc.h"

#define crc_byte      crc_crc8onewire_byte
#define crc_table     crc_crc8onewire_table
#define crc_table_asm _crc_crc8onewire_table

#if defined(SDCC)

__reentrantb uint8_t crc_byte(uint8_t crc, uint8_t c) __reentrant __naked
{
	crc;
	c;
        __asm;
	mov	a,sp
	add	a,#-2
	mov	r0,a
	mov	a,@r0
	xrl	a,dpl
	mov	dptr,#crc_table_asm
	movc	a,@a+dptr
	mov	dpl,a
	ret
        __endasm;
}

#else

__reentrantb uint8_t crc_byte(uint8_t crc, uint8_t c) __reentrant
{
        return crc_table[crc ^ c];
}

#endif
