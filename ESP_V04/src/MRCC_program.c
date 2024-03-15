/*
 * MRCC_program.c
 *
 *  Created on: Jan 15, 2024
 *      Author: Jimmy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MRCC_config.h"
#include "MRCC_private.h"


void MRCC_vInt(void)
{
#if (SYS_CLK==RCC_HSE)
	// bypass --> crystal oscillator (2 pins)/ RC (1 pin)
	RCC->CR &= ~(1<<RCC_BYP);
	RCC->CR |= (1<<RCC_HSEON);
	while(!GET_BIT(RCC->CR,RCC_HSERDY));
	RCC->CFGR &= SWITCH_MASk;
	RCC->CFGR |= RCC_HSE;

#elif (SYS_CLK==RCC_HSI)

	RCC->CR |= (1<<RCC_HSION);
	while(!GET_BIT(RCC->CR,RCC_HSIRDY));
	RCC->CFGR &= SWITCH_MASk;
	RCC->CFGR |= RCC_HSI;


#endif



}
void MRCC_vEnable(BUS copy_bus ,u16 copy_u16peripheral )
{
	switch (copy_bus)
	{
	case RCC_AHB1:
		RCC->AHB1ENR |= 1<<copy_u16peripheral;
		break;
	case RCC_AHB2:
		RCC->AHB2ENR |= 1<<copy_u16peripheral;
		break;
	case RCC_APB1:
		RCC->APB1ENR |= 1<<copy_u16peripheral;
		break;
	case RCC_APB2:
		RCC->APB2ENR |= 1<<copy_u16peripheral;
		break;
	case RCC_AHB1LP:
		RCC->AHB1LPENR |= 1<<copy_u16peripheral;
		break;
	default:
		break;
	}
}
void MRCC_vDisable(BUS copy_bus ,u16 copy_u16peripheral )
{
	switch (copy_bus)
	{
	case RCC_AHB1:
		RCC->AHB1ENR &= ~(1<<copy_u16peripheral);
		break;
	case RCC_AHB2:
		RCC->AHB2ENR &= ~(1<<copy_u16peripheral);
		break;
	case RCC_APB1:
		RCC->APB1ENR &= ~(1<<copy_u16peripheral);
		break;
	case RCC_AHB1LP:
		RCC->AHB1LPENR &= ~(1<<copy_u16peripheral);
		break;
	default:
		break;
	}

}
