/*
 * IR_private.h
 *
 *  Created on: 11/3/2024
 *      Author: Jimmy
 */

#ifndef IR_PRIVATE_H_
#define IR_PRIVATE_H_

static void (*Play_CallBack) (void) = NULL ;
volatile u8   Global_u8StartFlag       = 0;
volatile u32  Global_u32FrameData[50]  = {0};
volatile u8   Global_u8EdgeCounter     = 0;


#endif /* IR_PRIVATE_H_ */
