/*
 * NVIC_program.c
 *
 *  Created on: Jan 17, 2024
 *      Author: Jimmy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"


static u8 Global_u8IPR =0 ;


void NVIC_vEnable(u8 position)
{
	NVIC->NVIC_ISER[position/32] |= 1<<(position%32);
}
void NVIC_vDisable(u8 position)
{
	NVIC->NVIC_ICER[position/32] |= 1<<(position%32);
}
void NVIC_PendingSet(u8 position)
{
	NVIC->NVIC_ISPR[position/32] |= 1<<(position%32);
}
void NVIC_PendingClear(u8 position)
{
	NVIC->NVIC_ICPR[position/32] |= 1<<(position%32);
}



void NVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode) //AIRCR --> how many groups and sub groubs in our micro?
{
	Global_u8IPR=Copy_uddtGroupMode;//4 g4sub
	AIRCR=NVIC_VECTKEY;
	u32 Copy_u32Local= NVIC_VECTKEY|(Copy_uddtGroupMode <<8);
	AIRCR=Copy_u32Local;
}
void NVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum)
{
	switch (Global_u8IPR)
	{
	case Group16Sub0:NVIC ->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<4 ;
	break;

	case Group8Sub2:NVIC ->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<5 |Copy_u8SubGroupNum<<4 ;
	break;

	case Group4Sub4:NVIC ->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<6 |Copy_u8SubGroupNum<<4 ;
	break;

	case Group2Sub8:NVIC ->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<7 |Copy_u8SubGroupNum<<4 ;
	break;

	case Group0Sub16:NVIC ->IPR[Copy_u8IntPos]= Copy_u8SubGroupNum<<4 ;
	break;

	default:
	break;

	}


}










