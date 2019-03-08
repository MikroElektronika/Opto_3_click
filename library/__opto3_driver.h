/*
    __opto3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __opto3_driver.h
@brief    Opto_3 Driver
@mainpage Opto_3 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   OPTO3
@brief      Opto_3 Click Driver
@{

| Global Library Prefix | **OPTO3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _OPTO3_H_
#define _OPTO3_H_

/** 
 * @macro T_OPTO3_P
 * @brief Driver Abstract type 
 */
#define T_OPTO3_P    const uint8_t*
#define T_OPTO3_STATE      uint8_t
#define T_OPTO3_SWITCH     uint8_t

/** @defgroup OPTO3_COMPILE Compilation Config */              /** @{ */

//  #define   __OPTO3_DRV_SPI__                            /**<     @macro __OPTO3_DRV_SPI__  @brief SPI driver selector */
//  #define   __OPTO3_DRV_I2C__                            /**<     @macro __OPTO3_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __OPTO3_DRV_UART__                           /**<     @macro __OPTO3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup OPTO3_VAR Variables */                           /** @{ */

/** Opto 3 click input states */
extern const T_OPTO3_STATE _OPTO3_HIGH    ;
extern const T_OPTO3_STATE _OPTO3_LOW     ;

/** Opto 3 click output switch settings */
extern const T_OPTO3_SWITCH _OPTO3_ON     ;
extern const T_OPTO3_SWITCH _OPTO3_OFF    ;

                                                                       /** @} */
/** @defgroup OPTO3_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup OPTO3_INIT Driver Initialization */              /** @{ */

#ifdef   __OPTO3_DRV_SPI__
void opto3_spiDriverInit(T_OPTO3_P gpioObj, T_OPTO3_P spiObj);
#endif
#ifdef   __OPTO3_DRV_I2C__
void opto3_i2cDriverInit(T_OPTO3_P gpioObj, T_OPTO3_P i2cObj, uint8_t slave);
#endif
#ifdef   __OPTO3_DRV_UART__
void opto3_uartDriverInit(T_OPTO3_P gpioObj, T_OPTO3_P uartObj);
#endif

void opto3_gpioDriverInit(T_OPTO3_P gpioObj);
                                                                       /** @} */
/** @defgroup OPTO3_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Input 1 Check function
 *
 * Function returns a state of the Input 1.
 */
T_OPTO3_STATE opto3_getIN1( void );

/**
 * @brief Input 2 Check function
 *
 * Function returns a state of the Input 2.
 */
T_OPTO3_STATE opto3_getIN2( void );

/**
 * @brief Output 1 Set State function
 *
 * @param[in] state  0 - Turn OFF, 1 - Turn ON
 *
 * Function puts the Output 1 to the desired state.
 */
void opto3_setOUT1( T_OPTO3_SWITCH state );

/**
 * @brief Output 2 Set State function
 *
 * @param[in] state  0 - Turn OFF, 1 - Turn ON
 *
 * Function puts the Output 2 to the desired state.
 */
void opto3_setOUT2( T_OPTO3_SWITCH state );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Opto_3_STM.c
    @example Click_Opto_3_TIVA.c
    @example Click_Opto_3_CEC.c
    @example Click_Opto_3_KINETIS.c
    @example Click_Opto_3_MSP.c
    @example Click_Opto_3_PIC.c
    @example Click_Opto_3_PIC32.c
    @example Click_Opto_3_DSPIC.c
    @example Click_Opto_3_AVR.c
    @example Click_Opto_3_FT90x.c
    @example Click_Opto_3_STM.mbas
    @example Click_Opto_3_TIVA.mbas
    @example Click_Opto_3_CEC.mbas
    @example Click_Opto_3_KINETIS.mbas
    @example Click_Opto_3_MSP.mbas
    @example Click_Opto_3_PIC.mbas
    @example Click_Opto_3_PIC32.mbas
    @example Click_Opto_3_DSPIC.mbas
    @example Click_Opto_3_AVR.mbas
    @example Click_Opto_3_FT90x.mbas
    @example Click_Opto_3_STM.mpas
    @example Click_Opto_3_TIVA.mpas
    @example Click_Opto_3_CEC.mpas
    @example Click_Opto_3_KINETIS.mpas
    @example Click_Opto_3_MSP.mpas
    @example Click_Opto_3_PIC.mpas
    @example Click_Opto_3_PIC32.mpas
    @example Click_Opto_3_DSPIC.mpas
    @example Click_Opto_3_AVR.mpas
    @example Click_Opto_3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __opto3_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */