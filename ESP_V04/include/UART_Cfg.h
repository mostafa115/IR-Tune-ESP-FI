/*
 * UART_Cfg.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Jimmy
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_



#define UART_BAUDRATE                   UART_BAUDRATE_9600
															  /*
																UART_BAUDRATE_9600
																UART_BAUDRATE_19200
															   */

#define UART_OVERSAMPLING                UART_OVERSAMPLING_16
                                                             /*
                                                              UART_OVERSAMPLING_16
                                                              UART_OVERSAMPLING_8

                                                              */

#define UART_WORDLENGTH                  UART_DATA8_NOPARITY
                                                               /*
                                                                UART_DATA8_NOPARITY
																UART_DATA8_PARITY_ODD
																UART_DATA8_PARITY_EVEN
																UART_DATA9_NOPARITY

                                                               */

#define UART_STOPBIT_LENGTH                 UART_ONE_STOP_BIT
                                                                   /*
																		ONE_STOP_BIT
																		TWO_STOP_BIT

                                                                    */

#endif /* UART_CFG_H_ */
