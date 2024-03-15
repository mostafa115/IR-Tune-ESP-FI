/*
 * SYSTICK_private.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Jimmy
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS 0xE000E010

#define COUNT_FLAG 16
#define CLKSOURCE 2
#define TICK_INT 1
#define ENABLE 0

#define AHB 0
#define AHB_DIVIDEBY8 1

typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;


}SYSTICK_t;


#define SYSTICK ((volatile SYSTICK_t *) (SYSTICK_BASE_ADDRESS))

#endif /* SYSTICK_PRIVATE_H_ */
