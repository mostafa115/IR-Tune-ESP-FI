/*
 * NVIC_interface.h
 *
 *  Created on: Jan 17, 2024
 *      Author: philo
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


typedef enum{
 Group16Sub0=3,
 Group8Sub2,
 Group4Sub4,
 Group2Sub8,
 Group0Sub16

}MNVIC_Group_t;





void NVIC_vEnable(u8 position);
void NVIC_vDisable(u8 position);
void NVIC_PendingSet(u8 position);
void NVIC_PendingClear(u8 position);
void NVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode); //AIRCR --> how many groups and sub groubs in our micro?
void NVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum) ;

#endif /* NVIC_INTERFACE_H_ */
