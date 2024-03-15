/*
 * MRCC_private.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Jimmy
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define RCC_BASE_ADDRESS     0x40023800

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved0;
	u32 reserved1;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved2;
	u32 reserved3;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved4;
	u32 reserved5;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 reserved6;
	u32 reserved7;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 reserved8;
	u32 reserved9;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 reserved10;
	u32 reserved11;
	u32 BDCR;
	u32 CSR;
	u32 reserved12;
	u32 reserved13;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 reserved14;
	u32 DCKCFGR;
}RCC_t;

#define RCC_BYP 18
#define RCC_HSEON 16
#define RCC_HSERDY 17

#define RCC_HSION 0
#define RCC_HSIRDY 1


#define SWITCH_MASk  0xFFFFFFFC

#define RCC_HSI 0
#define RCC_HSE 1



#define RCC ((volatile RCC_t*) (RCC_BASE_ADDRESS))



#endif /* MRCC_PRIVATE_H_ */
