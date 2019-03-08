![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Opto_3 Click

- **CIC Prefix**  : OPTO3
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the Opto_3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2659/opto-3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library performs the input state checking and the output state setting.
For more details check documentation.

Key functions :

- ``` T_OPTO3_STATE opto3_getIN1( void ) ``` - Function returns a state of the Input 1.
- ``` void opto3_setOUT2( T_OPTO3_SWITCH state ) ``` - Function puts the Output 2 to the desired state.
- ```  ``` - 

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface.
- Application Task - (code snippet) - Switches ON or switches OFF the both outputs depending on the
  states of the inputs, respectively.
Note : Input state is active low, and output state is active high.


```.c
void applicationTask()
{
    stateIN1 = opto3_getIN1();
    stateIN2 = opto3_getIN2();
    
    stateOUT1 = stateIN1 ^ 1;
    stateOUT2 = stateIN2 ^ 1;
    
    opto3_setOUT1( stateOUT1 );
    opto3_setOUT2( stateOUT2 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2659/opto-3-click) page.

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
