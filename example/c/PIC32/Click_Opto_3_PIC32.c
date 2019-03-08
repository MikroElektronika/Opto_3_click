/*
Example for Opto_3 Click

    Date          : Nov 2018.
    Author        : Nemanja Medakovic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface.
- Application Task - (code snippet) - Switches ON or switches OFF the both outputs depending on the
  states of the inputs, respectively.
Note : Input state is active low, and output state is active high.

*/

#include "Click_Opto_3_types.h"
#include "Click_Opto_3_config.h"

T_OPTO3_STATE stateIN1;
T_OPTO3_STATE stateIN2;
T_OPTO3_SWITCH stateOUT1;
T_OPTO3_SWITCH stateOUT2;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite( "*** Initializing... ***", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    opto3_gpioDriverInit( (T_OPTO3_P)&_MIKROBUS1_GPIO );
    Delay_ms( 100 );
    
    mikrobus_logWrite( "** Opto 3 is initialized **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
}

void applicationTask()
{
    stateIN1 = opto3_getIN1();
    stateIN2 = opto3_getIN2();
    
    stateOUT1 = stateIN1 ^ 1;
    stateOUT2 = stateIN2 ^ 1;
    
    opto3_setOUT1( stateOUT1 );
    opto3_setOUT2( stateOUT2 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
