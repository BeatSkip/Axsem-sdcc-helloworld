/**
******************************************************************************
* @file axm0vectors.h
* @brief IRQ handler/Vector declarations
* @internal
* @author   Thomas Sailer, Pradeep Kumar G R
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
* @ingroup VECTOR
*
* @details
*/

#ifndef __CM0PLUSEXCEPTIONVECTORS_H
#define __CM0PLUSEXCEPTIONVECTORS_H


#include "axm0.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* System defined exceptions */
extern void HardFault_Handler (void);
extern void NotImplemented_Handler (void);

/* Programmable exception vectors */

extern void NMI_Handler (void);

extern void SVC_Handler (void);

extern void PendSV_Handler ();

extern void SysTick_Handler (void);

extern void GPIO_Handler (void);

extern void WakeupTimer_Handler (void);

extern void ClockSysConfig_Handler (void);

extern void AnalogComp_Handler (void);

extern void ADC_Handler (void);

extern void AES_Handler (void);

extern void TRNG_Handler (void);

extern void FLASH_Handler (void);

extern void Watchdog_Handler (void);

extern void TickerTimer_Handler (void);

extern void Timer0_Handler (void);

extern void Timer1_Handler (void);

extern void Timer2_Handler (void);

extern void CC_PMW0_Handler (void);

extern void CC_PMW1_Handler (void);

extern void CC_PMW2_Handler (void);

extern void CC_PMW3_Handler (void);

extern void SPI0_Handler (void);

extern void SPI1_Handler (void);

extern void UART0_Handler (void);

extern void UART1_Handler (void);

extern void I2C_Handler (void);

extern void DMAError_Handler (void);

extern void DMADone_Handler (void);

extern void fExceptionPriorities (void);

extern unsigned char Out_Of_Low_Power(void);

#ifdef __cplusplus
}
#endif

#endif /* __CM0PLUSEXCEPTIONVECTORS_H */
