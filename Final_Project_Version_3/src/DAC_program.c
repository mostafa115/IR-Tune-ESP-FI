/*
 * DAC_program.c
 *
 *  Created on: Jan 23, 2024
 *      Author: Jimmy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "DAC_interface.h"
#include "GPTIM_interface.h"
#include "STP_interface.h"


void HR2RDAC_vInit(void)
{
	MGPIO_vSetMode(PORT_B,PIN_5,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_8,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_9,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_10,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_12,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_13,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_14,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_15,MODE_OUTPUT);

	MGPIO_vSetOutputMode(PORT_B,PIN_5,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_8,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_9,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_10,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_12,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_13,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_14,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_15,OUTPUT_PUSHPULL,SPEED_LOW);

	MGPIO_vWritePin(PORT_B,PIN_5,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_8,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_9,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_10,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_12,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_13,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_14,GPIO_LOW);
	MGPIO_vWritePin(PORT_B,PIN_15,GPIO_LOW);
}
void HR2RDAC_vSetData(const u8 *arr,u32 arrsize)
{
	static u32 L_counter = 0;
	Global_u8DACINLoop = 1 ;
	for (L_counter = 0;L_counter<arrsize;L_counter++)
	{
		MGPIO_vWritePin(PORT_B,PIN_5,GET_BIT(arr[L_counter],0));
		MGPIO_vWritePin(PORT_B,PIN_8,GET_BIT(arr[L_counter],1));
		MGPIO_vWritePin(PORT_B,PIN_9,GET_BIT(arr[L_counter],2));
		MGPIO_vWritePin(PORT_B,PIN_10,GET_BIT(arr[L_counter],3));
		MGPIO_vWritePin(PORT_B,PIN_12,GET_BIT(arr[L_counter],4));
		MGPIO_vWritePin(PORT_B,PIN_13,GET_BIT(arr[L_counter],5));
		MGPIO_vWritePin(PORT_B,PIN_14,GET_BIT(arr[L_counter],6));
		MGPIO_vWritePin(PORT_B,PIN_15,GET_BIT(arr[L_counter],7));
		/* Using Timer Insted of Systic because we Are Clearing Systic on IR Sensor */
		/* Edited By Jimmy On 10/3/2024 */
		//MSYSYTICK_voidDelayUs(125);
		TIM2_voidSetBusyWait(125);
		if(Global_u8DACBreakLoop == 1)
		{
			HR2RDAC_vInit();
			Global_u8DACBreakLoop = 0 ;
			break ;
		}
	}
	Global_u8DACINLoop = 0 ;
}


