/*
 * SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Jimmy
 */
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI.h"



void MSPI_VoidInit(void)
{
	SPI1->CR1 &= ~ 1<<SPE;  //Disable SPI

#if DATA_FORMAT==Data_Formate_8
	SPI1->CR1 &= ~1<<DFF;

#elif DATA_FORMAT==Data_Formate_16
	SPI1->CR1 |= 1<<DFF;
#endif

#if FRAME_FORMATE==MSP
	SPI1->CR1 &= ~1<<LSBFIRST;

#elif FRAME_FORMATE==LSB
	SPI1->CR1 |= 1<<LSBFIRST;
#endif

#if Control==Slave
	SPI1->CR1 &= ~1<<MSTR;

#elif Control==Master
	SPI1->CR1 |= 1<<MSTR;
#endif

#if Clock_Polarity==CPOL_0
	SPI1->CR1 &= ~1<<CPOL;

#elif Clock_Polarity==CPOL_1
	SPI1->CR1 |= 1<<CPOL;
#endif

#if Clock_Phase==CPHA_0
	SPI1->CR1 &= ~1<<CPHA;

#elif Clock_Phase==CPHA_1
	SPI1->CR1 |= 1<<CPHA;
#endif

/*BOUDRATE*/
	SPI1->CR1 &= ~(7<<BR);
	SPI1->CR1 |=(BOUDRATE<<BR);

	/* Software slave management */
	SPI1->CR1 |= 1<<SSM;
	SPI1->CR1 |= 1<<SSI;

	SPI1->CR1 |= 1<<SPE;   //Enable SPI
}

u16 MSPI_u16Transceive(u16 Data)
{
	while(GET_BIT(SPI1->SR, SR_TXE)==0);
	SPI1->DR = Data;
	while(GET_BIT(SPI1->SR, SR_RXNE)==0);
	return SPI1->DR;
}
