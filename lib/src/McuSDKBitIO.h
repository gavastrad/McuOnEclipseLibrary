/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuSDKBitIO.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : SDK_BitIO
**     Version     : Component 01.018, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-12, 14:16, # CodeGen: 98
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuSDKBitIO
**          SDK                                            : McuLib
**          GPIO Name                                      : GPIOA
**          PORT Name                                      : PORTA
**          Pin Number                                     : 0
**          Pin Symbol                                     : LED_RED
**          Do Pin Muxing                                  : no
**     Contents    :
**         GetDir    - bool McuSDKBitIO_GetDir(void);
**         SetDir    - void McuSDKBitIO_SetDir(bool Dir);
**         SetInput  - void McuSDKBitIO_SetInput(void);
**         SetOutput - void McuSDKBitIO_SetOutput(void);
**         GetVal    - bool McuSDKBitIO_GetVal(void);
**         PutVal    - void McuSDKBitIO_PutVal(bool Val);
**         ClrVal    - void McuSDKBitIO_ClrVal(void);
**         SetVal    - void McuSDKBitIO_SetVal(void);
**         NegVal    - void McuSDKBitIO_NegVal(void);
**         Init      - void McuSDKBitIO_Init(void);
**         Deinit    - void McuSDKBitIO_Deinit(void);
**
**     * Copyright (c) 2015-2016, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuSDKBitIO.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuSDKBitIO_module McuSDKBitIO module documentation
**  @{
*/         

#ifndef __McuSDKBitIO_H
#define __McuSDKBitIO_H

/* MODULE McuSDKBitIO. */
#include "McuLib.h" /* SDK and API used */
#include "McuSDKBitIOconfig.h" /* configuration */

#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h"

  /* only GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF and GPIOG are currently supported */
  #define McuSDKBitIO_GPIO_IDX GPIOA_IDX   /* GPIOA */
  #define McuSDKBitIO_PinNumber  0u   /* number of pin, type unsigned integer */

  enum McuSDKBitIO_pinNames{
    LED_RED = GPIO_MAKE_PIN(McuSDKBitIO_GPIO_IDX, McuSDKBitIO_PinNumber),
  };

  extern const gpio_output_pin_user_config_t McuSDKBitIO_OutputConfig[];
  extern const gpio_input_pin_user_config_t McuSDKBitIO_InputConfig[];
#endif

void McuSDKBitIO_Init(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_ClrVal(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_SetVal(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_NegVal(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_Deinit(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

bool McuSDKBitIO_GetVal(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_GetVal (component SDK_BitIO)
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/

bool McuSDKBitIO_GetDir(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_GetDir (component SDK_BitIO)
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/

void McuSDKBitIO_SetDir(bool Dir);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetDir (component SDK_BitIO)
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_SetInput(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_SetOutput(void);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuSDKBitIO_PutVal(bool Val);
/*
** ===================================================================
**     Method      :  McuSDKBitIO_PutVal (component SDK_BitIO)
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/

/* END McuSDKBitIO. */

#endif
/* ifndef __McuSDKBitIO_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
