/*
 * GPIO_private.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Jimmy
 */
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_A_BASE_ADDRESS 0x40020000
#define GPIO_B_BASE_ADDRESS	0x40020400
#define GPIO_C_BASE_ADDRESS 0x40020800

typedef struct
{
	u32 GPIO_MODER;
	u32 GPIO_OTYPER;
	u32 GPIO_OSPEEDR;
	u32 GPIO_PUPDR;
	u32 GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_LCKR;
	u32 GPIO_AFRL;
	u32 GPIO_AFRH;

}GPIO;

#define PORT_MASK 3
#define INPUT_MASK 3
#define OUTPUT_MASK 1
#define SPEED_MASK 3



#define GPIO_A ((volatile GPIO *) (GPIO_A_BASE_ADDRESS))
#define GPIO_B ((volatile GPIO *) (GPIO_B_BASE_ADDRESS))
#define GPIO_C ((volatile GPIO *) (GPIO_C_BASE_ADDRESS))

#endif



