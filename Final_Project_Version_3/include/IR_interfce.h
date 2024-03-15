/*
 * IR_interfce.h
 *
 *  Created on: 10/3/2024
 *      Author: Jimmy
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_


volatile u8   Global_u8Data ;
void voidPlay(void);
void voidTakeAction(void);
void voidGetFrame(void);
void PlayFunction_voidcallback(void (*Play_Function)(void));



#endif /* IR_INTERFCE_H_ */
