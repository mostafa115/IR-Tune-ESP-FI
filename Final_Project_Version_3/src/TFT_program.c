/***********************************************************/
/* Author    : Jimmy                                 */
/* Date      : 21 Jan 2024                                 */
/* Version   : V01                                         */
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI.h"
#include "SYSTICK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

#include "GPTIM_interface.h"

void HTFT_voidInitialize(void)
{
	MGPIO_vSetMode(TFT_RST_PIN,MODE_OUTPUT);
	MGPIO_vSetMode(TFT_A0_PIN,MODE_OUTPUT);

	MGPIO_vSetOutputMode(TFT_RST_PIN,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(TFT_A0_PIN,OUTPUT_PUSHPULL,SPEED_LOW);

	/* Reset Pulse */
	MGPIO_vWritePin(TFT_RST_PIN,GPIO_HIGH);
	TIM2_voidSetBusyWait(100);
	MGPIO_vWritePin(TFT_RST_PIN,GPIO_LOW);
	TIM2_voidSetBusyWait(100);
	MGPIO_vWritePin(TFT_RST_PIN,GPIO_HIGH);
	TIM2_voidSetBusyWait(100);
	MGPIO_vWritePin(TFT_RST_PIN,GPIO_HIGH);
	TIM2_voidSetBusyWait(100);
	MGPIO_vWritePin(TFT_RST_PIN,GPIO_LOW);
	TIM2_voidSetBusyWait(100);
	MGPIO_vWritePin(TFT_RST_PIN,GPIO_HIGH);
	TIM2_voidSetBusyWait(120);


	/* Sleep Out Command */
	HTFT_voidWriteCommand(0x11);

	/* Wait 150 ms */
	TIM2_voidSetBusyWait(100);

	/* Color Mode Command */
	HTFT_voidWriteCommand(0x3A);
	HTFT_voidWriteData(0x05);

	/* Display On Command */
	HTFT_voidWriteCommand(0x29);
}


void HTFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 Local_u16Counter;
	u8 Local_u8Data;

	/* Set X Address */
	HTFT_voidWriteCommand(0x2A);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);

	/* Set Y Address */
	HTFT_voidWriteCommand(0x2B);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);

	/* RAM Write */
	HTFT_voidWriteCommand(0x2C);

	Global_u8TFTINLoop = 1 ;

	for(Local_u16Counter = 0; Local_u16Counter< 20480;Local_u16Counter++)
	{


		Local_u8Data = Copy_Image[Local_u16Counter] >> 8;

		/* Write the high byte */
		HTFT_voidWriteData(Local_u8Data);
		/* Write the low byte */
		Local_u8Data = Copy_Image[Local_u16Counter] & 0x00ff;
		HTFT_voidWriteData(Local_u8Data);
		if(Global_u8TFTBreakLoop == 1)
		{
			HTFT_voidInitialize();
			Global_u8TFTBreakLoop = 0 ;
			break ;
		}
	}

	Global_u8TFTINLoop = 0 ;
	//MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
}

static void HTFT_voidWriteCommand(u8 Copy_u8Command)
{
	/* Set A0 Pin to Low */
	MGPIO_vWritePin(TFT_A0_PIN,GPIO_LOW);
	/* Send Command over SPI */
	MSPI_u16Transceive(Copy_u8Command);
}

static void HTFT_voidWriteData(u8 Copy_u8Data)
{
	/* Set A0 Pin to High */
	MGPIO_vWritePin(TFT_A0_PIN,GPIO_HIGH);
	/* Send data over SPI */
	MSPI_u16Transceive(Copy_u8Data);
}

