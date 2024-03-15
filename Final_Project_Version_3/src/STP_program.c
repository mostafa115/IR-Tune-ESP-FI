#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "STP_private.h"
#include "STP_config.h"
#include "STP_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "GPTIM_interface.h"

void S2P_vInit(void)
{
MGPIO_vSetMode(HSTP_SERIAL_DATA,MODE_OUTPUT);
MGPIO_vSetOutputMode(HSTP_SERIAL_DATA,OUTPUT_PUSHPULL,SPEED_LOW);

MGPIO_vSetMode(HSTP_SHIFT_CLOCK,MODE_OUTPUT);
MGPIO_vSetOutputMode(HSTP_SERIAL_DATA,OUTPUT_PUSHPULL,SPEED_LOW);

MGPIO_vSetMode(HSTP_STORAGE_CLOCK,MODE_OUTPUT);
MGPIO_vSetOutputMode(HSTP_SERIAL_DATA,OUTPUT_PUSHPULL,SPEED_LOW);
}

void S2P_vSendPulse(void)
{
MGPIO_vWritePin(HSTP_SHIFT_CLOCK,GPIO_HIGH);
//MSYSYTICK_voidDelayUs(1);
TIM2_voidSetBusyWait(1);
MGPIO_vWritePin(HSTP_SHIFT_CLOCK,GPIO_LOW);
//MSYSYTICK_voidDelayUs(1);
TIM2_voidSetBusyWait(10);
}

void S2P_vSendData(u16 Copy_u16Data)
{
	s8 Local_u8Iterator = 0 ;

	for(Local_u8Iterator = 15 ; Local_u8Iterator >= 0 ; Local_u8Iterator --  )
	{
		MGPIO_vWritePin(HSTP_SERIAL_DATA, GET_BIT(Copy_u16Data,Local_u8Iterator));
		S2P_vSendPulse();
	}
	/* Send Pulse To Storage Pin */
	MGPIO_vWritePin(HSTP_STORAGE_CLOCK,GPIO_HIGH);
	//MSYSYTICK_voidDelayUs(1);
	TIM2_voidSetBusyWait(1);
	MGPIO_vWritePin(HSTP_STORAGE_CLOCK,GPIO_LOW);
	//MSYSYTICK_voidDelayUs(1);
	TIM2_voidSetBusyWait(1);
}
