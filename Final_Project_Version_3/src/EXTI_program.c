/*
 * EXTI_program.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Jimmy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

static void (*GLOBAL_PTR[16]) (void); // ->Array of pointers to functions


void MEXTI_voidInerruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port)
{
	SYSCFG->SYSCFG_EXTICR[Copy_u8Line/DIV_FAC] &= ~(MUSK<<(DIV_FAC*(Copy_u8Line%DIV_FAC)));
	SYSCFG->SYSCFG_EXTICR[Copy_u8Line/DIV_FAC] |= Copy_u8Port<<(DIV_FAC*(Copy_u8Line%DIV_FAC));
}
void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis)
{
	switch (Copy_u8ENDis) {
		case EXTI_Enable:
			EXTI->EXTI_IMR|=1<<(Copy_u8IntLine);
		break;

		case EXTI_Disable:
			EXTI->EXTI_IMR&= ~(1<<(Copy_u8IntLine));
		break;

		default:
		break;
	}

}
void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig)
{
	switch (Copy_u8Trig) {
	case EXTI_Rising:
		EXTI->EXTI_RTSR|=1<<(Copy_u8IntLine);
		EXTI->EXTI_FTSR &= ~(1<<(Copy_u8IntLine));
		break;

	case EXTI_Falling:
		EXTI->EXTI_FTSR|=1<<(Copy_u8IntLine);
		EXTI->EXTI_RTSR &= ~(1<<(Copy_u8IntLine));
		break;

	case EXTI_OnChange:
		EXTI->EXTI_FTSR|=1<<(Copy_u8IntLine);
		EXTI->EXTI_RTSR|=1<<(Copy_u8IntLine);
		break;

	default:
		break;
	}

}
void MEXTI0_voidCallBack(void (*ptr)(void))
{
	GLOBAL_PTR[0]=ptr;
}
void MEXTI1_voidCallBack(void (*ptr)(void))
{
	GLOBAL_PTR[1]=ptr;
}


void EXTI0_IRQHandler (void)
{
	GLOBAL_PTR[0]();
	SET_BIT(EXTI->EXTI_PR,0);
}

void EXTI1_IRQHandler (void)
{
	GLOBAL_PTR[1]();
	EXTI->EXTI_PR |= 1<<1;
}
