/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuPidInt.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : PID_Int
**     Version     : Component 01.008, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-20, 21:25, # CodeGen: 114
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuPidInt
**          Variable for controller set point              : no
**          P - Proportional                               : Enabled
**            constant                                     : yes
**            Kp Factor                                    : 1
**            Kp Divisor                                   : 8
**          I - Integral                                   : Enabled
**            constant                                     : yes
**            Ki Factor                                    : 1
**            Ki Divisor                                   : 512
**            Anti Wind-Up                                 : Enabled
**              constant                                   : yes
**              Value                                      : 1024
**          D - Differential                               : Enabled
**            constant                                     : yes
**            Kd Factor                                    : 4
**            Kd Divisor                                   : 1
**          Hardware                                       : Disabled
**          System                                         : 
**            SDK                                          : McuLib
**     Contents    :
**         PID      - int32_t McuPidInt_PID(int32_t setPoint, int32_t currValue);
**         Control  - void McuPidInt_Control(void);
**         SetPoint - void McuPidInt_SetPoint(int32_t value);
**         GetPoint - int32_t McuPidInt_GetPoint(void);
**
**     * Copyright (c) 2012-2016, Erich Styger
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
** @file McuPidInt.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuPidInt_module McuPidInt module documentation
**  @{
*/         

#ifndef __McuPidInt_H
#define __McuPidInt_H

/* MODULE McuPidInt. */
#include "McuLib.h" /* SDK and API used */
#include "McuPidIntconfig.h" /* configuration */

/* Include inherited components */
#include "McuLib.h"




void McuPidInt_Control(void);
/*
** ===================================================================
**     Method      :  McuPidInt_Control (component PID_Int)
**     Description :
**         Performs the PID control calculation.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuPidInt_SetPoint(int32_t value);
/*
** ===================================================================
**     Method      :  McuPidInt_SetPoint (component PID_Int)
**     Description :
**         Specifies the value to be reached by the PID controller.
**     Parameters  :
**         NAME            - DESCRIPTION
**         value           - The setpoint value.
**     Returns     : Nothing
** ===================================================================
*/

int32_t McuPidInt_GetPoint(void);
/*
** ===================================================================
**     Method      :  McuPidInt_GetPoint (component PID_Int)
**     Description :
**         Returns the current set point value
**     Parameters  : None
**     Returns     :
**         ---             - The current set point
** ===================================================================
*/

int32_t McuPidInt_PID(int32_t setPoint, int32_t currValue);
/*
** ===================================================================
**     Method      :  McuPidInt_PID (component PID_Int)
**     Description :
**         Performs PID calculation
**     Parameters  :
**         NAME            - DESCRIPTION
**         setPoint        - current setpoint (desired value)
**         currValue       - current sensor value
**     Returns     :
**         ---             - output of PID calculation
** ===================================================================
*/

/* END McuPidInt. */

#endif
/* ifndef __McuPidInt_H */
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