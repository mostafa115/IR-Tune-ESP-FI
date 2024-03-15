/*
 * UART_Interface.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Mostafa
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_Init(void);
void UART_SendSynchronous(u16 data);
u16 UART_ReceiveSynchronous(void);
void UART_SendASynchronous(u16 data);
u16 UART_ReceiveASynchronous(void);
void UART_TX_InterruptEnable(void);
void UART_RX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_CallBackFunction(void(*local_fptr)(void));
void UART_RX_CallBackFunction(void(*local_fptr)(void));
UART_SendString(u8*str);

#endif /* UART_INTERFACE_H_ */
