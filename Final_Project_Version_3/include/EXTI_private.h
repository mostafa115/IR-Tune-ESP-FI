/*
 * EXTI_private.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Jimmy
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADRESS   0x40013C00
#define SYSCFG_BASE_ADRESS 0x40013800

#define DIV_FAC 4
#define MUSK 15


typedef struct
{
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;

}EXTI_t;

typedef struct
{
	u32 SYSCFG_MEMRMP;
	u32 SYSCFG_PMC;
	u32 SYSCFG_EXTICR[4];
	u32 RES[2];
	u32 SYSCFG_CMPCR;


}SYSCFG_t;

#define EXTI   ((volatile EXTI_t *)   (EXTI_BASE_ADRESS))
#define SYSCFG ((volatile SYSCFG_t *) (SYSCFG_BASE_ADRESS))

#endif /* EXTI_PRIVATE_H_ */
