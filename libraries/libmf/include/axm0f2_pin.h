/**
******************************************************************************
* @file axm0f2_pin.h
* @brief Pin config APIs declarations
* @internal
* @author   Pradeep Kumar G R, Prakash Rajendran
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
* @ingroup PIN
*
* @details
*/


#ifndef AXM0F2_PIN_H
#define AXM0F2_PIN_H
#include "libmftypes.h"
#include "axm0_config.h"

#if defined __ARMEL__ || defined __ARMEB__

typedef enum {      	                	 /*!< GPIO_PORT_PIN */
	  GPIO_PIN_P00 	            = 0x00,  	 /*!< PORT 0.0 	 	*/
	  GPIO_PIN_P01 	            = 0x01,  	 /*!< PORT 0.1 	 	*/
	  GPIO_PIN_P02 	            = 0x02,  	 /*!< PORT 0.2 	 	*/
	  GPIO_PIN_P03 	            = 0x03,  	 /*!< PORT 0.3 	 	*/
	  GPIO_PIN_P04 	            = 0x04,  	 /*!< PORT 0.4 	 	*/
	  GPIO_PIN_P05 	            = 0x05,  	 /*!< PORT 0.5 	 	*/
	  GPIO_PIN_P06 	            = 0x06,      /*!< PORT 0.6      */
	  GPIO_PIN_P07 	            = 0x07,      /*!< PORT 0.7      */

	  GPIO_PIN_P10 	            = 0x08,  	 /*!< PORT 1.0 	 	*/
	  GPIO_PIN_P11 	            = 0x09,  	 /*!< PORT 1.1 	 	*/
	  GPIO_PIN_P12 	            = 0x0A,  	 /*!< PORT 1.2 	 	*/
	  GPIO_PIN_P13 	            = 0x0B,  	 /*!< PORT 1.3 	 	*/
	  GPIO_PIN_P14 	            = 0x0C,  	 /*!< PORT 1.4 	 	*/
	  GPIO_PIN_P15 	            = 0x0D,  	 /*!< PORT 1.5 	 	*/
	  GPIO_PIN_P16 	            = 0x0E,      /*!< PORT 1.6      */
	  GPIO_PIN_P17          	= 0x0F,      /*!< PORT 1.7      */

	  GPIO_PIN_P20 	            = 0x10,  	 /*!< PORT 2.0 	 	*/
	  GPIO_PIN_P21 	            = 0x11,  	 /*!< PORT 2.1 	 	*/
	  GPIO_PIN_P22 	            = 0x12,  	 /*!< PORT 2.2 	 	*/
	  GPIO_PIN_P23 	            = 0x13,  	 /*!< PORT 2.3 	 	*/
	  GPIO_PIN_P24          	= 0x14,  	 /*!< PORT 2.4 	 	*/
	  GPIO_PIN_P25 	            = 0x15,  	 /*!< PORT 2.5 	 	*/
	  GPIO_PIN_P26 	            = 0x16,      /*!< PORT 2.6      */
	  GPIO_PIN_P27 	            = 0x17,      /*!< PORT 2.7      */

      GPIO_PIN_P30 	            = 0x18,  	 /*!< PORT 3.0 	 	*/
	  GPIO_PIN_P31             	= 0x19,  	 /*!< PORT 3.1 	 	*/
	  GPIO_PIN_P32          	= 0x1A,  	 /*!< PORT 3.2 	 	*/
	  GPIO_PIN_P33 	            = 0x1B,  	 /*!< PORT 3.3 	 	*/
	  GPIO_PIN_P34 	            = 0x1C,  	 /*!< PORT 3.4 	 	*/
	  GPIO_PIN_P35 	            = 0x1D,  	 /*!< PORT 3.5 	 	*/
	  GPIO_PIN_P36 	            = 0x1E,      /*!< PORT 3.6      */
	  GPIO_PIN_P37 	            = 0x1F,      /*!< PORT 3.7      */

      GPIO_PIN_P40 	            = 0x20,  	 /*!< PORT 4.0 	 	*/
	  GPIO_PIN_P41 	            = 0x21,  	 /*!< PORT 4.1 	 	*/
	  GPIO_PIN_P42 			    = 0x22,  	 /*!< PORT 4.2 	 	*/
	  GPIO_PIN_P43 			    = 0x23,  	 /*!< PORT 4.3 	 	*/

	  GPIO_PIN_DISABLE   	    = 0x7F,     /* GPIO_PIN_NO_OUTPUT */
	  GPIO_PIN_NO_INVERT 		= 0x00,  	/* GPIO_PIN_NO_INVERT */
	  GPIO_PIN_INVERT 		    = 0x80  	/* GPIO_PIN_INVERT */

} GPIO_PIN_Enum;

typedef enum {                            /*!< PACKAGE_PIN_NUM */

    PKG_PIN_NOT_GPIO = 0xFF,              /*!< Cannot be used as GPIO */
    PKG_PIN_GROUND   = 0xF0,              /*!< package pin ground */

    PKG_PIN_NUM_01  = PKG_PIN_NOT_GPIO,   /*!< Package pin 1  */
    PKG_PIN_NUM_02  = PKG_PIN_NOT_GPIO,   /*!< Package pin 2  */
    PKG_PIN_NUM_03  = PKG_PIN_NOT_GPIO,   /*!< Package pin 3  */
    PKG_PIN_NUM_04  = PKG_PIN_NOT_GPIO,   /*!< Package pin 4  */
    PKG_PIN_NUM_05  = PKG_PIN_NOT_GPIO,   /*!< Package pin 5  */
    PKG_PIN_NUM_06  = PKG_PIN_NOT_GPIO,   /*!< Package pin 6  */
    PKG_PIN_NUM_07  = PKG_PIN_NOT_GPIO,   /*!< Package pin 7  */
    PKG_PIN_NUM_08  = PKG_PIN_NOT_GPIO,   /*!< Package pin 8  */

    PKG_PIN_NUM_9   = PKG_PIN_NOT_GPIO,   /*!< Package pin 9  */
    PKG_PIN_NUM_10  = PKG_PIN_NOT_GPIO,   /*!< Package pin 10 */
    PKG_PIN_NUM_11  = PKG_PIN_NOT_GPIO,   /*!< Package pin 11 */
    PKG_PIN_NUM_12  = PKG_PIN_NOT_GPIO,   /*!< Package pin 12 */
    PKG_PIN_NUM_13  = GPIO_PIN_P31,       /*!< Package pin 13 */
    PKG_PIN_NUM_14  = GPIO_PIN_P32,       /*!< Package pin 14 */
    PKG_PIN_NUM_15  = GPIO_PIN_P33,       /*!< Package pin 15 */
    PKG_PIN_NUM_16  = GPIO_PIN_P36,       /*!< Package pin 16 */
    PKG_PIN_NUM_17  = GPIO_PIN_P37,       /*!< Package pin 17 */
    PKG_PIN_NUM_18  = GPIO_PIN_P40,       /*!< Package pin 18 */
    PKG_PIN_NUM_19  = GPIO_PIN_P41,       /*!< Package pin 19 */
    PKG_PIN_NUM_20  = GPIO_PIN_P42,       /*!< Package pin 20 */

    PKG_PIN_NUM_21  = GPIO_PIN_P43,       /*!< Package pin 21 */
    PKG_PIN_NUM_22  = GPIO_PIN_P00,       /*!< Package pin 22 */
    PKG_PIN_NUM_23  = GPIO_PIN_P01,       /*!< Package pin 23 */
    PKG_PIN_NUM_24  = GPIO_PIN_P02,       /*!< Package pin 24 */
    PKG_PIN_NUM_25  = GPIO_PIN_P04,       /*!< Package pin 25 */
    PKG_PIN_NUM_26  = GPIO_PIN_P05,       /*!< Package pin 26 */
    PKG_PIN_NUM_27  = GPIO_PIN_P06,       /*!< Package pin 27 */
    PKG_PIN_NUM_28  = PKG_PIN_NOT_GPIO,   /*!< Package pin 28 */

    PKG_PIN_NUM_29  = PKG_PIN_NOT_GPIO,   /*!< Package pin 29 */
    PKG_PIN_NUM_30  = GPIO_PIN_P10,       /*!< Package pin 30 */
    PKG_PIN_NUM_31  = GPIO_PIN_P11,       /*!< Package pin 31 */
    PKG_PIN_NUM_32  = GPIO_PIN_P12,       /*!< Package pin 32 */
    PKG_PIN_NUM_33  = GPIO_PIN_P13,       /*!< Package pin 33 */
    PKG_PIN_NUM_34  = GPIO_PIN_P15,       /*!< Package pin 34 */
    PKG_PIN_NUM_35  = GPIO_PIN_P17,       /*!< Package pin 35 */
    PKG_PIN_NUM_36  = PKG_PIN_NOT_GPIO,   /*!< Package pin 36 */
    PKG_PIN_NUM_37  = PKG_PIN_NOT_GPIO,   /*!< Package pin 37 */
    PKG_PIN_NUM_38  = PKG_PIN_NOT_GPIO,   /*!< Package pin 38 */
    PKG_PIN_NUM_39  = PKG_PIN_NOT_GPIO,   /*!< Package pin 39 */
    PKG_PIN_NUM_40  = PKG_PIN_NOT_GPIO,   /*!< Package pin 40 */

} PACKAGE_PIN_Enum;

#endif

#endif /* AXM0F2_PIN_H */
