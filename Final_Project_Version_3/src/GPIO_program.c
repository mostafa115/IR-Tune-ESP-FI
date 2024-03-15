/*
 * GPIO_program.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Jimmy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"


void MGPIO_vSetMode(PORT port_copy,PIN pin_copy ,u8 mode)
{
	switch (port_copy) {
	case PORT_A:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_13) || (pin_copy == PIN_14) || (pin_copy == PIN_15) )
		{
			//do nothing
		}
		else
		{
			//setting the mode
			GPIO_A->GPIO_MODER &= ~(PORT_MASK<<(pin_copy*2));
			GPIO_A->GPIO_MODER |= (mode<<(pin_copy*2));
		}
		break;
	case PORT_B:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_2) || (pin_copy == PIN_3) || (pin_copy == PIN_4) )
		{
			//do nothing
		}
		else
		{
		//setting the mode
		GPIO_B->GPIO_MODER &= ~(PORT_MASK<<(pin_copy*2));
		GPIO_B->GPIO_MODER |= (mode<<(pin_copy*2));
		}
		break;
	case PORT_C:
		//setting the mode
		GPIO_C->GPIO_MODER &= ~(PORT_MASK<<(pin_copy*2));
		GPIO_C->GPIO_MODER |= (mode<<(pin_copy*2));
		break;
	default:
		break;
	}
}
void MGPIO_vSetOutputMode(PORT port_copy,PIN pin_copy,u8 mode , u8 speed)
{
	switch (port_copy) {
	case PORT_A:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_13) || (pin_copy == PIN_14) || (pin_copy == PIN_15) )
		{
			//do nothing
		}
		else
		{
			//setting the mode
			GPIO_A->GPIO_OTYPER &= ~(OUTPUT_MASK<<(pin_copy));
			GPIO_A->GPIO_OTYPER |= (mode<<(pin_copy));
			//setting speed
			GPIO_A->GPIO_OSPEEDR &= ~(SPEED_MASK<<(pin_copy*2));
			GPIO_A->GPIO_OSPEEDR |= (speed<<(pin_copy*2));
		}
		break;
	case PORT_B:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_2) || (pin_copy == PIN_3) || (pin_copy == PIN_4) )
		{
			//do nothing
		}
		else
		{
		//setting the mode
		GPIO_B->GPIO_OTYPER &= ~(OUTPUT_MASK<<(pin_copy));
		GPIO_B->GPIO_OTYPER |= (mode<<(pin_copy));
		//setting speed
		GPIO_B->GPIO_OSPEEDR &= ~(SPEED_MASK<<(pin_copy*2));
		GPIO_B->GPIO_OSPEEDR |= (speed<<(pin_copy*2));
		}
		break;
	case PORT_C:
		//setting the mode
		GPIO_C->GPIO_OTYPER &= ~(OUTPUT_MASK<<(pin_copy));
		GPIO_C->GPIO_OTYPER |= (mode<<(pin_copy));
		//setting speed
		GPIO_C->GPIO_OSPEEDR &= ~(SPEED_MASK<<(pin_copy*2));
		GPIO_C->GPIO_OSPEEDR |= (speed<<(pin_copy*2));
		break;
	default:
		break;
	}
}
void MGPIO_vSetInputMode(PORT port_copy,PIN pin_copy,u8 mode)
{
	switch (port_copy) {
	case PORT_A:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_13) || (pin_copy == PIN_14) || (pin_copy == PIN_15) )
		{
			//do nothing
		}
		else
		{
		//setting the mode
		GPIO_A->GPIO_PUPDR &= ~(INPUT_MASK<<(pin_copy*2));
		GPIO_A->GPIO_PUPDR |= (mode<<(pin_copy*2));
		}
		break;
	case PORT_B:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_2) || (pin_copy == PIN_3) || (pin_copy == PIN_4) )
		{
			//do nothing
		}
		else
		{
		//setting the mode
		GPIO_B->GPIO_PUPDR &= ~(INPUT_MASK<<(pin_copy*2));
		GPIO_B->GPIO_PUPDR |= (mode<<(pin_copy*2));
		}
		break;
	case PORT_C:
		//setting the mode
		GPIO_C->GPIO_PUPDR &= ~(INPUT_MASK<<(pin_copy*2));
		GPIO_C->GPIO_PUPDR |= (mode<<(pin_copy*2));
		break;
	default:
		break;
	}
}
void MGPIO_vWritePin(PORT port_copy,PIN pin_copy,u8 mode)
{
	switch (port_copy) {
	case PORT_A:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_13) || (pin_copy == PIN_14) || (pin_copy == PIN_15) )
		{
			//do nothing
		}
		else
		{
			//setting the mode
			GPIO_A->GPIO_ODR &= ~(OUTPUT_MASK<<(pin_copy));
			GPIO_A->GPIO_ODR |= (mode<<(pin_copy));
		}

		break;
	case PORT_B:
		//check for the pins that must not be changed
		if ((pin_copy == PIN_2) || (pin_copy == PIN_3) || (pin_copy == PIN_4) )
		{
			//do nothing
		}
		else
		{
		//setting the mode
		GPIO_B->GPIO_ODR &= ~(OUTPUT_MASK<<(pin_copy));
		GPIO_B->GPIO_ODR |= (mode<<(pin_copy));
		}
		break;
	case PORT_C:
		//setting the mode
		GPIO_C->GPIO_ODR &= ~(OUTPUT_MASK<<(pin_copy));
		GPIO_C->GPIO_ODR |= (mode<<(pin_copy));
		break;
	default:
		break;
	}
}
u8 MGPIO_u8ReadPin(PORT port_copy,PIN pin_copy)
{
	u8 L_returnVal=0;
	switch (port_copy) {
	case PORT_A:
		L_returnVal = GET_BIT(GPIO_A->GPIO_IDR,pin_copy);
		break;
	case PORT_B:
		L_returnVal = GET_BIT(GPIO_B->GPIO_IDR,pin_copy);
		break;
	case PORT_C:
		L_returnVal = GET_BIT(GPIO_C->GPIO_IDR,pin_copy);
		break;
	default:
		break;
	}
	return L_returnVal;
}
void MGPIO_vSetAlternativeMode(PORT port_copy,PIN pin_copy ,u8 driver_val)
{
	if (pin_copy < PIN_8 )
	{
		switch (port_copy) {
		case PORT_A:
			//check for the pins that must not be changed
			if ((pin_copy == PIN_13) || (pin_copy == PIN_14) || (pin_copy == PIN_15) )
			{
				//do nothing
			}
			else
			{
				//setting the mode
				GPIO_A->GPIO_AFRL |= (driver_val<<(pin_copy*4));
			}
			break;
		case PORT_B:
			//check for the pins that must not be changed
			if ((pin_copy == PIN_2) || (pin_copy == PIN_3) || (pin_copy == PIN_4) )
			{
				//do nothing
			}
			else
			{
				//setting the mode
				GPIO_B->GPIO_AFRL |= (driver_val<<(pin_copy*4));
			}
			break;
		case PORT_C:
			//setting the mode
			GPIO_C->GPIO_AFRL |= (driver_val<<(pin_copy*4));
			break;
		default:
			break;
		}
	}
	else if ( (pin_copy >= PIN_8) && (pin_copy <= PIN_15) )
	{
		switch (port_copy) {
		case PORT_A:
			//check for the pins that must not be changed
			if ((pin_copy == PIN_13) || (pin_copy == PIN_14) || (pin_copy == PIN_15) )
			{
				//do nothing
			}
			else
			{
				//setting the mode
				GPIO_A->GPIO_AFRH |= (driver_val<<((pin_copy-8)*4));
			}
			break;
		case PORT_B:
			//check for the pins that must not be changed
			if ((pin_copy == PIN_2) || (pin_copy == PIN_3) || (pin_copy == PIN_4) )
			{
				//do nothing
			}
			else
			{
				//setting the mode
				GPIO_B->GPIO_AFRH |= (driver_val<<((pin_copy-8)*4));
			}
			break;
		case PORT_C:
			//setting the mode
			GPIO_A->GPIO_AFRH |= (driver_val<<((pin_copy-8)*4));
			break;
		default:
			break;
		}

	}
	else
	{

	}
}
