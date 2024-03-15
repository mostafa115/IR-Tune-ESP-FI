/*
 * GPIO_interface.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Jimmy
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

typedef enum
{
	PORT_A=0,
	PORT_B,
	PORT_C
}PORT;
typedef enum
{
	PIN_0=0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,PIN_8,PIN_9,PIN_10,PIN_11,PIN_12,PIN_13,PIN_14,PIN_15
}PIN;

// modes
#define MODE_INPUT  0
#define MODE_OUTPUT 1
#define MODE_ALTERNATIVE  2
#define MODE_ANALOG  3

// output modes
#define OUTPUT_PUSHPULL 0
#define OUTPUT_OPENDRAIN 1

// speed
#define SPEED_LOW 0
#define SPEED_MEDUIEM 1
#define SPEED_HIGH 2

// input values
#define INPUT_NOPULL 0
#define INPUT_PULLUP 1
#define INPUT_PULLDOWN 2


// output value
#define GPIO_LOW 0
#define GPIO_HIGH 1

// UART Values
#define ALTR_UART 7


void MGPIO_vSetMode(PORT port_copy,PIN pin_copy ,u8 mode);
void MGPIO_vSetOutputMode(PORT port_copy,PIN pin_copy,u8 mode , u8 speed);
void MGPIO_vSetInputMode(PORT port_copy,PIN pin_copy,u8 mode);
void MGPIO_vWritePin(PORT port_copy,PIN pin_copy,u8 mode);
u8 MGPIO_u8ReadPin(PORT port_copy,PIN pin_copy);


void MGPIO_vSetAlternativeMode(PORT port_copy,PIN pin_copy ,u8 driver_val);


#endif /* GPIO_INTERFACE_H_ */
