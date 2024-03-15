/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: mosta
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MRCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "UART_Interface.h"
#include "HESP_int.h"

u8 Global_u8Array_1[4] = {'A','T','\n','\r'} ;
u8 * Global_puReadingFile = NULL_POINTER ;
void main()
{
	MRCC_vInt();

	MRCC_vEnable(RCC_AHB1,AHB1_GPIOA);
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOB);

	//MRCC_vEnable(RCC_APB2,APB2_USART1);
	MRCC_vEnable(RCC_APB1,APB1_USART2);

	MGPIO_vSetMode(PORT_A,PIN_0,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_0,OUTPUT_PUSHPULL,SPEED_LOW);
	//MGPIO_vSetMode(PORT_A,PIN_9,MODE_ALTERNATIVE);
	//MGPIO_vSetMode(PORT_A,PIN_10,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_2,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_3,MODE_ALTERNATIVE);

	//MGPIO_vSetAlternativeMode(PORT_A,PIN_9,ALTR_UART);
	//MGPIO_vSetAlternativeMode(PORT_A,PIN_10,ALTR_UART);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_2,ALTR_UART);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_3,ALTR_UART);

	MGPIO_vSetMode(PORT_A,PIN_0,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_0,OUTPUT_PUSHPULL,SPEED_LOW);

	UART_Init();

	MSYSYTICK_voidInit();


	ESP_voidInit();

	while(1)
	{
		ESP_WifiConnect("jamal10","mM101010#");
		ESP_ServerConnect("185.176.43.112","80");
		ESP_SendHttpRequest("http://jimy.atwebpages.com/status.txt","43") ;
	/*
		if(*Global_puReadingFile == 1)
		{
			MGPIO_vWritePin(PORT_A,PIN_0,GPIO_HIGH);
		}
		else
		{
			MGPIO_vWritePin(PORT_A,PIN_0,GPIO_LOW);
		}
*/
	}
}


