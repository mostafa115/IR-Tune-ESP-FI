/*
 * SPI_private.h
 *
 *  Created on: 10/3/2024
 *      Author: Jimmy
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS		0x40013000

#define  SPE  6
#define  BSY  7
#define  DFF  11
#define  CPOL 1
#define  CPHA 0
#define  MSTR 2
#define  LSBFIRST  7
#define  SSM  9
#define  SSI  8
#define  BR   3
#define SR_TXE  1
#define SR_RXNE 0

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR ;

}SPI_t;


#define SPI1	((volatile SPI_t*)SPI1_BASE_ADDRESS)

#endif /* SPI_PRIVATE_H_ */
