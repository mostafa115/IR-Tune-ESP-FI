/*
 * NVIC_private.h
 *
 *  Created on: Jan 17, 2024
 *      Author: Jimmy
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct
{
	u32 NVIC_ISER[8];
	u32 RES_1[24];
	u32 NVIC_ICER[8];
	u32 RES_2[24];
	u32 NVIC_ISPR[8];
	u32 RES_3[24];
	u32 NVIC_ICPR[8];
	u32 RES_4[24];
	u32 NVIC_IABR[8];
	u32 RES_5[56];
	u8 IPR[240];
	u32 RES_6[580];
	u32 STIR;
}NVIC_t;



#define NVIC   ((volatile NVIC_t *) (NVIC_BASE_ADDRESS))
#define AIRCR   *((volatile u32 *)    (0xE000ED0C))
#define NVIC_VECTKEY 0x05FA0000


#endif /* NVIC_PRIVATE_H_ */
