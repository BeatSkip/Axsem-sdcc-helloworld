/**
******************************************************************************
* @file axm0_xbar.h
* @brief Crossbar config APIs declarations
* @internal
* @author   Pradeep Kumar G R
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
* @ingroup CROSSBAR
*
* @details
*/


#ifndef AXM0F2_XBAR_H
#define AXM0F2_XBAR_H
#include "libmftypes.h"
#include "axm0f2_config.h"

#if defined __ARMEL__ || defined __ARMEB__

typedef enum {      	     /*!< XBAR_PIN 	*/
	  XBAR_PIN_P00 	= 0,  	 /*!< P00 	 	*/
	  XBAR_PIN_P01 	= 1,  	 /*!< P01 	 	*/
	  XBAR_PIN_P02 	= 2,  	 /*!< P02 	 	*/
	  XBAR_PIN_P03 	= 3,  	 /*!< P03 	 	*/
	  XBAR_PIN_P04 	= 4,  	 /*!< P04 	 	*/
	  XBAR_PIN_P05 	= 5,  	 /*!< P05 	 	*/
	  XBAR_PIN_P06 	= 6,     /*!< P06       */
	  XBAR_PIN_P07 	= 7,     /*!< P07       */

	  XBAR_PIN_P10 	= 0,  	 /*!< P10 	 	*/
	  XBAR_PIN_P11 	= 1,  	 /*!< P11 	 	*/
	  XBAR_PIN_P12 	= 2,  	 /*!< P12 	 	*/
	  XBAR_PIN_P13 	= 3,  	 /*!< P13 	 	*/
	  XBAR_PIN_P14 	= 4,  	 /*!< P14 	 	*/
	  XBAR_PIN_P15 	= 5,  	 /*!< P15 	 	*/
	  XBAR_PIN_P16 	= 6,     /*!< P16       */
	  XBAR_PIN_P17 	= 7,     /*!< P17       */

	  XBAR_PIN_P20 	= 0,  	 /*!< P20 	 	*/
	  XBAR_PIN_P21 	= 1,  	 /*!< P21 	 	*/
	  XBAR_PIN_P22 	= 2,  	 /*!< P22 	 	*/
	  XBAR_PIN_P23 	= 3,  	 /*!< P23 	 	*/
	  XBAR_PIN_P24 	= 4,  	 /*!< P24 	 	*/
	  XBAR_PIN_P25 	= 5,  	 /*!< P25 	 	*/
	  XBAR_PIN_P26 	= 6,     /*!< P26       */
	  XBAR_PIN_P27 	= 7,     /*!< P27       */

      XBAR_PIN_P30 	= 0,  	 /*!< P30 	 	*/
	  XBAR_PIN_P31 	= 1,  	 /*!< P31 	 	*/
	  XBAR_PIN_P32 	= 2,  	 /*!< P32 	 	*/
	  XBAR_PIN_P33 	= 3,  	 /*!< P33 	 	*/
	  XBAR_PIN_P34 	= 4,  	 /*!< P34 	 	*/
	  XBAR_PIN_P35 	= 5,  	 /*!< P35 	 	*/
	  XBAR_PIN_P36 	= 6,     /*!< P36       */
	  XBAR_PIN_P37 	= 7,     /*!< P37       */

      XBAR_PIN_P40 	= 0,  	 /*!< P40 	 	*/
	  XBAR_PIN_P41 	= 1,  	 /*!< P41 	 	*/
	  XBAR_PIN_P42 	= 2,  	 /*!< P42 	 	*/
	  XBAR_PIN_P43 	= 3,  	 /*!< P43 	 	*/

} XBAR_PIN_Enum;

#endif

#endif /* AXM0_XBAR_H */
