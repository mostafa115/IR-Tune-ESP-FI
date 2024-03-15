/*
 * SYSTICK_interface.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Jimmy
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#define NULL_PTR ((void*)0)
#define SINGLE_MODE 1
#define PERIODIC 0

typedef enum
{
	SYSTICKEnable,
	SYSTICKDisable
}SYSTICKState;


// clock -> AHB  ****  AHB/8
void MSYSYTICK_voidInit(void);

void MSYSYTICK_voidStart(u32 Copy_u32Loadvalue);

u8   MSYSYTICK_voidReadFlag(void);

void MSYSYTICK_voidCtrlIntState(SYSTICKState Copy_State );

// 16MHZ --> /8 ---> 2MHZ
void MSYSYTICK_voidDelayUs(u32 Copy_u32Delayvalue);

void MSYSYTICK_voidDelayms(u32 Copy_u32Delayvalue);

u32  MSTK_u32GetElapsedTime(void);

u32  MSTK_u32GetRemainingTime(void);

void MSTK_voidSetInterval_single(u32 Copy_u32Loadvalue, void (*CallbackFunction)(void));
void MSTK_voidSetInterval_periodic(u32 Copy_u32Loadvalue, void (*CallbackFunction)(void));

#endif /* SYSTICK_INTERFACE_H_ */
