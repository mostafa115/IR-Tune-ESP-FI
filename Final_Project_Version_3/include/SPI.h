/*
 * SPI.h
 *
 *  Created on: 8/3/2024
 *      Author: Jimmy
 */

#ifndef SPI_H_
#define SPI_H_

//Data Formate
#define Data_Formate_8   0
#define Data_Formate_16  1

//Frame Formate
#define MSP      0
#define LSB      1

//BoudRate
#define    FrequancyDIVBy2     0
#define    FrequancyDIVBy4     1
#define    FrequancyDIVBy8     2
#define    FrequancyDIVBy16    3
#define    FrequancyDIVB32     4
#define    FrequancyDIVBy64    5
#define    FrequancyDIVBy128   6
#define    FrequancyDIVBy256   7

#define  Slave      0
#define  Master     1

#define  CPOL_0     0
#define  CPOL_1     1

#define  CPHA_0     0
#define  CPHA_1     1

void MSPI_VoidInit(void);
u16 MSPI_u16Transceive(u16 Data);


#endif /* SPI_H_ */
