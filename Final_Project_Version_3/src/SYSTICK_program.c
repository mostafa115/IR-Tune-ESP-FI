/*
 * SYSTICK_program.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Jimmy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"
#include "BIT_MATH.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"

static void (*SetCallBack) (void) = NULL_PTR ;
static u8 Mode_GLOBALE = 0 ;

void MSYSYTICK_voidInit(void)
{
#if (SYSTICK_Source == AHB)

	SYSTICK->STK_CTRL |= (1<<CLKSOURCE);

#elif (SYSTICK_Source == AHB_DIVIDEBY8)

	SYSTICK->STK_CTRL &= ~(1<<CLKSOURCE);

#endif

}

void MSYSYTICK_voidStart(u32 Copy_u32Loadvalue)
{
	SYSTICK->STK_LOAD = Copy_u32Loadvalue;
	SYSTICK->STK_VAL = 0;
	SYSTICK->STK_CTRL |= (1<<ENABLE);

}

u8   MSYSYTICK_voidReadFlag(void)
{
	return GET_BIT(SYSTICK->STK_CTRL,COUNT_FLAG);
}

void MSYSYTICK_voidCtrlIntState(SYSTICKState Copy_State )
{
	switch (Copy_State) {
	case SYSTICKEnable:
		SYSTICK->STK_CTRL |= (1<<TICK_INT);
		break;
	case SYSTICKDisable:
		SYSTICK->STK_CTRL &= ~(1<<TICK_INT);
		break;
	default:
		break;
	}

}

// 16MHZ --> /8 ---> 2MHZ
void MSYSYTICK_voidDelayUs(u32 Copy_u32Delayvalue)
{
	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSYTICK_voidStart(Copy_u32Delayvalue*2);
	while (MSYSYTICK_voidReadFlag() == 0);
	CLR_BIT(SYSTICK->STK_CTRL,0);
	SYSTICK->STK_LOAD = 0 ;
	SYSTICK->STK_VAL  = 0 ;
}

void MSYSYTICK_voidDelayms(u32 Copy_u32Delayvalue)
{
	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSYTICK_voidStart(Copy_u32Delayvalue*2000);
	while (MSYSYTICK_voidReadFlag() == 0);
	CLR_BIT(SYSTICK->STK_CTRL,0);
	SYSTICK->STK_LOAD = 0 ;
	SYSTICK->STK_VAL  = 0 ;
}

u32  MSTK_u32GetElapsedTime(void)
{
	return ((SYSTICK->STK_LOAD)-(SYSTICK->STK_VAL));
}

u32  MSTK_u32GetRemainingTime(void)
{
	return SYSTICK->STK_VAL ;
}

void MSTK_voidSetInterval_single(u32 Copy_u32Loadvalue, void (*CallbackFunction)(void))
{
	SetCallBack=CallbackFunction;
	MSYSYTICK_voidStart(Copy_u32Loadvalue);
	Mode_GLOBALE = SINGLE_MODE ;



}
void MSTK_voidSetInterval_periodic(u32 Copy_u32Loadvalue, void (*CallbackFunction)(void))
{
	SetCallBack=CallbackFunction;
	MSYSYTICK_voidStart(Copy_u32Loadvalue);
	Mode_GLOBALE = PERIODIC ;

}


void SysTick_Handler(void)
{
	if(SetCallBack!=NULL_PTR)
	{
		SetCallBack();
		if(Mode_GLOBALE==SINGLE_MODE)
		{
			SetCallBack = NULL_PTR;
		}
	}
	else
	{

	}
}







