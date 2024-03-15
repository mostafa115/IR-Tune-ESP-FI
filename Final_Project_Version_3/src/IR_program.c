/*
 * IR_program.c
 *
 *  Created on: 1/3/2024
 *      Author: Jimmy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPTIM_interface.h"
#include "IR_private.h"
#include "IR_interfce.h"
#include "SYSTICK_interface.h"


void PlayFunction_voidcallback(void (*Play_Function)(void))
{
	if(Play_Function != NULL)
	{
		Play_CallBack = Play_Function ;
	}
}

void voidTakeAction(void)
{
//	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	u8 i;
	Global_u8Data = 0;
	if ( (Global_u32FrameData[0] >= 10000) && (Global_u32FrameData[0] <= 15000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (Global_u32FrameData[17+i] >= 2000) && (Global_u32FrameData[17+i] <=2300) )
			{
				SET_BIT(Global_u8Data,i);
			}

			else
			{
				CLR_BIT(Global_u8Data,i);
			}
		}

		Play_CallBack();
	//	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
	}
	else
	{
		/*	 Invalid Frame */
	}

	Global_u8StartFlag     = 0;
	Global_u32FrameData[0] = 0;
	Global_u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	//MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	if (Global_u8StartFlag == 0)
	{
		/* Start Timer */
		//TIM3_voidSetIntervalSingle(200000,voidTakeAction);
		MSTK_voidSetInterval_single(200000,voidTakeAction);
		Global_u8StartFlag = 1;
	}

	else
	{
		Global_u32FrameData[Global_u8EdgeCounter] =  (MSTK_u32GetElapsedTime()/2);
		MSTK_voidSetInterval_single(200000,voidTakeAction);
		//TIM3_voidSetIntervalSingle(200000,voidTakeAction);
		Global_u8EdgeCounter++;
	}
	if(Global_u8EdgeCounter == 10)
	{
		asm("NOP");
	}
//	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);

}
