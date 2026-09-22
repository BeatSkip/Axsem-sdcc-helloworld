/**
******************************************************************************
* @file axm0f2vectors.h
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


#include "axm0f2.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* System defined exceptions */
extern void HardFault_Handler (void);
extern void NotImplemented_Handler (void);

/* Programmable exception vectors */

extern void NMI_Handler (void);

extern void SVC_Handler (void);

extern void PendSV_Handler (void);

extern void SysTick_Handler (void);

extern void GPIOPort0_Handler (void);

extern void GPIOPort1_Handler (void);

extern void GPIOPort2_Handler (void);

extern void GPIOPort3_Handler (void);

extern void GPIO_Handler (void);

extern void LPComp_Handler (void);

extern void WDT_Handler (void);

extern void SCB0_Handler (void);

extern void SCB1_Handler (void);

extern void SCB2_Handler (void);

extern void CTBm_Handler (void);

extern void WCOWDT_Handler (void);

extern void SPCIF_Handler (void);

extern void CSD_Handler (void);

extern void TCPWM0_Handler (void);

extern void TCPWM1_Handler (void);

extern void TCPWM2_Handler (void);

extern void TCPWM3_Handler (void);

extern void TCPWM4_Handler (void);

extern void ADC_Handler (void);

extern void fExceptionPriorities (void);

#ifdef __cplusplus
}
#endif

#endif /* __CM0PLUSEXCEPTIONVECTORS_H */
