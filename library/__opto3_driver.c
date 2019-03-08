/*
    __opto3_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__opto3_driver.h"
#include "__opto3_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __OPTO3_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const T_OPTO3_STATE _OPTO3_HIGH           = 0x01;
const T_OPTO3_STATE _OPTO3_LOW            = 0x00;

const T_OPTO3_SWITCH _OPTO3_ON            = 0x01;
const T_OPTO3_SWITCH _OPTO3_OFF           = 0x00;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __OPTO3_DRV_SPI__

void opto3_spiDriverInit(T_OPTO3_P gpioObj, T_OPTO3_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __OPTO3_DRV_I2C__

void opto3_i2cDriverInit(T_OPTO3_P gpioObj, T_OPTO3_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __OPTO3_DRV_UART__

void opto3_uartDriverInit(T_OPTO3_P gpioObj, T_OPTO3_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

void opto3_gpioDriverInit(T_OPTO3_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

T_OPTO3_STATE opto3_getIN1( void )
{
    if ( hal_gpio_pwmGet() )
    {
        return _OPTO3_HIGH;
    }
    else
    {
        return _OPTO3_LOW;
    }
}

T_OPTO3_STATE opto3_getIN2( void )
{
    if ( hal_gpio_intGet() )
    {
        return _OPTO3_HIGH;
    }
    else
    {
        return _OPTO3_LOW;
    }
}

void opto3_setOUT1( T_OPTO3_SWITCH state )
{
    if (state)
    {
        hal_gpio_anSet( _OPTO3_ON );
    }
    else
    {
        hal_gpio_anSet( _OPTO3_OFF );
    }
}

void opto3_setOUT2( T_OPTO3_SWITCH state )
{
    if (state)
    {
        hal_gpio_rstSet( _OPTO3_ON );
    }
    else
    {
        hal_gpio_rstSet( _OPTO3_OFF );
    }
}

/* -------------------------------------------------------------------------- */
/*
  __opto3_driver.c

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