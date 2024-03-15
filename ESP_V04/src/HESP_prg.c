#include "STD_Types.h"
#include "BIT_MATH.h"
#include "HESP_int.h"
#include "UART_Interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"


//extern u8 Global_u8Array_1[4] ;
extern u8 * Global_puReadingFile ;
void ESP_voidInit(void)
{
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		//UART_SendString("AT\r\n");
		//MSYSYTICK_voidDelayUs(5000000);
		UART_SendString("ATE0\r\n");           //disable echo
		MSYSYTICK_voidDelayUs(1000);
		Local_u8Result=ESP_voidESPValidateCmd();
	}

	Local_u8Result=0;

	while(Local_u8Result==0)
	{
		UART_SendString("AT+CWMODE=1\r\n");         // station mode
		Local_u8Result=ESP_voidESPValidateCmd();
	}

}


/*
	u8 * Command_Name_Password ;
	u8 Data[12 +Copy_Name_Size+Copy_Password_Size];
	u8 i = 0 ;
	*Command_Name_Password = "AT+CWJAP=";
	*(Command_Name_Password + 8) = "\"" ;
	*(Command_Name_Password + 9) = Copy_Name ;
	*(Command_Name_Password + 9 + Copy_Name_Size ) = "\",\"" ;
	*(Command_Name_Password + 12 + Copy_Name_Size) = Copy_Password ;
	*(Command_Name_Password + 12 + Copy_Name_Size + Copy_Password_Size ) = "\"";

for(i = 0 ; i < (12 +Copy_Name_Size+Copy_Password_Size) ; i++ )
{
	Data[i] = Command_Name_Password[i] ;
}
*/
void ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password)
{
	u8 Local_u8Result=0;
		UART_SendString("AT+CWJAP=\"jamal10\",\"mM101010#\"\r\n");
	//	while(Local_u8Result==0)
	//	{
	//		UART_SendString("AT+CWJAP_CUR=\"WE_CFA4F8\",\"lc715758\"\r\n");
	//
	////		UART_SendString("AT+CWJAP_CUR=\"");
	////		UART_SendString(Copy_Name);
	////		UART_SendString(",");
	////		UART_SendString(Copy_Password);
	////		UART_SendString("\"\r\n");
	//		//MSYSYTICK_voidDelayUs(1000);      //or this -> Local_u8Result=ESP_voidESPValidateCmd();
	//	}

	while(Local_u8Result==0)
	{

		Local_u8Result=ESP_voidESPValidateCmd();
	}
}

void ESP_ServerConnect(u8 * Copy_IP , u8 * Copy_Port)
{
	u8 Local_u8Result = 0 ;
	UART_SendString("AT+CIPSTART=\"TCP\",\"185.176.43.112\",80\r\n");
	//	UART_SendString("AT+CIPSTART=\"TCP\",\"");
	//	UART_SendString(Copy_IP);
	//	UART_SendString("\",");
	//	UART_SendString(Copy_Port);
	//	UART_SendString("\r\n");
	while(Local_u8Result==0)
	{
		Local_u8Result=ESP_voidESPValidateCmd();
	}
}

void ESP_SendHttpRequest(u8 * Copy_URL , u8 * Length)
{
	u8 Local_u8Result = 0 ;
	//UART_SendString("ATE0\r\n");
	UART_SendString("AT+CIPSEND=43\r\n");
	//	UART_SendString("AT+CIPSEND=");
	//	UART_SendString(Length);
	//	UART_SendString("\r\n");
	//	MSYSYTICK_voidDelayUs(1000);
	while(Local_u8Result==0)
	{
		Local_u8Result=ESP_voidESPValidateCmd();
	}
	Local_u8Result = 0 ;
	while(Local_u8Result==0)
	{
		UART_SendString("GET http://jimy.atwebpages.com/status.txt\r\n");
		Local_u8Result=ESP_voidESPValidateCmd();
	}
	Local_u8Result = 1 ;
	//	UART_SendString(Copy_URL);
	//	UART_SendString("\r\n");
}

u8 ESP_voidESPValidateCmd(void)
{
	u8 Local_u8Response[100]={0};
	u8 i = 0 ;
	u16 Dummy = 0 ;
	u8 Result=0;
	while(Dummy < 255)
	{
		Dummy = UART_u8Receive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	asm("NOP");
	if( (Local_u8Response[2] == 'O' && Local_u8Response[3] == 'K' ) || (Local_u8Response[11] == 'O' && Local_u8Response[12] == 'K' ) )
	{
		Result=1;
	}
	if((Local_u8Response[7] == 'O' && Local_u8Response[8] == 'K'))
	{
		if(Local_u8Response[20] == '0')
		{
			*Global_puReadingFile = 0 ;
			MGPIO_vWritePin(PORT_A,PIN_0,GPIO_LOW);
		}
		else
		{
			*Global_puReadingFile = 1 ;
			MGPIO_vWritePin(PORT_A,PIN_0,GPIO_HIGH);
		}
		Result = 1 ;
	}

	return Result;

}

u8 ESP_ReadFile(void)
{
	u8 Local_u8Response[100]={0};
	u16 Dummy = 0 , i = 0;
	//u8 Result=0;

	while( i < 20)
	{
		Dummy = UART_u8Receive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	return Local_u8Response[9];
}
