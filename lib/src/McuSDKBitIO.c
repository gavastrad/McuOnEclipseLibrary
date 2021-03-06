/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuSDKBitIO.c
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
** @file McuSDKBitIO.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuSDKBitIO_module McuSDKBitIO module documentation
**  @{
*/         

/* MODULE McuSDKBitIO. */

#include "McuSDKBitIO.h"
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#else
  #error "This component only works with the Kinetis SDK!"
#endif

#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  #define McuSDKBitIO_PORTName   PORTA /* name of PORT, is pointer to PORT_Type */
  #define McuSDKBitIO_GPIOName   GPIOA /* name of GPIO, is pointer to GPIO_Type */
  #define McuSDKBitIO_PinNumber  0u   /* number of pin, type unsigned integer */

  static const gpio_pin_config_t McuSDKBitIO_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    1,  /* initial value */
  };

  static const gpio_pin_config_t McuSDKBitIO_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    0,  /* initial value */
  };
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  const gpio_output_pin_user_config_t McuSDKBitIO_OutputConfig[] = {
    {
      .pinName = LED_RED,
      .config.outputLogic = 0,
    #if FSL_FEATURE_PORT_HAS_SLEW_RATE
      .config.slewRate = kPortSlowSlewRate,
    #endif
    #if FSL_FEATURE_PORT_HAS_OPEN_DRAIN
      .config.isOpenDrainEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH
      .config.driveStrength = kPortLowDriveStrength,
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

  const gpio_input_pin_user_config_t McuSDKBitIO_InputConfig[] = {
    {
      .pinName = LED_RED,
    #if FSL_FEATURE_PORT_HAS_PULL_ENABLE
      .config.isPullEnable = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_PULL_SELECTION
      .config.pullSelect = kPortPullDown,
    #endif
    #if FSL_FEATURE_PORT_HAS_PASSIVE_FILTER
      .config.isPassiveFilterEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DIGITAL_FILTER
      .config.isDigitalFilterEnabled = true,
    #endif
    #if FSL_FEATURE_GPIO_HAS_INTERRUPT_VECTOR
      .config.interrupt = kPortIntDisabled
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

#endif

static bool McuSDKBitIO_isOutput = false;
/*
** ===================================================================
**     Method      :  McuSDKBitIO_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_ClrVal(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  GPIO_ClearPinsOutput(McuSDKBitIO_GPIOName, 1<<McuSDKBitIO_PinNumber);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_ClearPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_SetVal(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  GPIO_SetPinsOutput(McuSDKBitIO_GPIOName, 1<<McuSDKBitIO_PinNumber);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  McuSDKBitIO_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_NegVal(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  GPIO_TogglePinsOutput(McuSDKBitIO_GPIOName, 1<<McuSDKBitIO_PinNumber);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_TogglePinOutput(LED_RED);
#endif
}

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
bool McuSDKBitIO_GetVal(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  return GPIO_ReadPinInput(McuSDKBitIO_GPIOName, McuSDKBitIO_PinNumber)!=0;
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  return GPIO_DRV_ReadPinInput(LED_RED)!=0;
#else
  return FALSE;
#endif
}

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
bool McuSDKBitIO_GetDir(void)
{
  return McuSDKBitIO_isOutput;
}

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
void McuSDKBitIO_SetDir(bool Dir)
{
  if (Dir) {
    McuSDKBitIO_SetOutput();
  } else {
    McuSDKBitIO_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_SetInput(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  GPIO_PinInit(McuSDKBitIO_GPIOName, McuSDKBitIO_PinNumber, &McuSDKBitIO_configInput);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalInput);
#endif
  McuSDKBitIO_isOutput = false;
}

/*
** ===================================================================
**     Method      :  McuSDKBitIO_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_SetOutput(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  GPIO_PinInit(McuSDKBitIO_GPIOName, McuSDKBitIO_PinNumber, &McuSDKBitIO_configOutput);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalOutput);
#endif
  McuSDKBitIO_isOutput = true;
}

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
void McuSDKBitIO_PutVal(bool Val)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  if (Val) {
    GPIO_SetPinsOutput(McuSDKBitIO_GPIOName, 1<<McuSDKBitIO_PinNumber);
  } else {
    GPIO_ClearPinsOutput(McuSDKBitIO_GPIOName, 1<<McuSDKBitIO_PinNumber);
  }
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_WritePinOutput(LED_RED, Val);
#endif
}

/*
** ===================================================================
**     Method      :  McuSDKBitIO_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_Init(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_2_0
  #if McuSDKBitIO_CONFIG_DO_PIN_MUXING
  PORT_SetPinMux(McuSDKBitIO_PORTName, McuSDKBitIO_PinNumber, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
  McuSDKBitIO_SetOutput();
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(McuSDKBitIO_InputConfig, McuSDKBitIO_OutputConfig);
#endif
}

/*
** ===================================================================
**     Method      :  McuSDKBitIO_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuSDKBitIO_Deinit(void)
{
  /* nothing needed */
}

/* END McuSDKBitIO. */

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
