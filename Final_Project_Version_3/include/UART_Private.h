/*
 * UART_Private.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Jimmy
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define UART1_BASEADD       (0x40011000)
#define UART2_BASEADD       (0x40004400)
#define UART6_BASEADD       (0x40011400)


typedef struct {

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}UART_t;

#define UART1             ((volatile UART_t* )(UART1_BASEADD))
#define UART2             ((volatile UART_t* )(UART2_BASEADD))
#define UART6             ((volatile UART_t* )(UART6_BASEADD))

#define UART_BAUDRATE_9600        0
#define UART_BAUDRATE_19200       1

#define UART_OVERSAMPLING_16      0
#define UART_OVERSAMPLING_8       1

#define UART_DATA8_NOPARITY                  0
#define UART_DATA8_PARITY_ODD                1
#define UART_DATA8_PARITY_EVEN               2
#define UART_DATA9_NOPARITY                  3


#define UART_ONE_STOP_BIT                       0
#define UART_TWO_STOP_BIT                       2

#define TWO_BIT_MASK  (3)
//CR1
#define  OVER8               15
#define  M                   12
#define  PCE                 10
#define  PS                  9
#define  UE                  13
#define  TE                  3
#define  RE                  2
#define PEIE                 8
#define TXEIE                7
#define TCIE                 6
#define RXNEIE               5

//SR
#define   RXNE               5
#define   TXE                7
#define   TC                 6





#endif /* UART_PRIVATE_H_ */
