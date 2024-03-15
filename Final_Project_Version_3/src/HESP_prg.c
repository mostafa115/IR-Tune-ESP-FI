#include "STD_Types.h"
#include "BIT_MATH.h"
#include "HESP_int.h"
#include "UART_Interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"


//extern u8 Global_u8Array_1[4] ;

void ESP_voidInit(void)
{
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		UART_SendString("AT\r\n");
		//UART_SendString("ATE0\r\n");           //disable echo
		Local_u8Result=ESP_voidESPValidateCmd();
	}
	Local_u8Result=0;
	while(Local_u8Result==0)
	{
		UART_SendString("AT+CWMODE=1\r\n");         // station mode
		Local_u8Result=ESP_voidESPValidateCmd();
	}
}
void ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password)
{
	u8 Local_u8Result=0;

	while(Local_u8Result==0)
	{
		UART_SendString("AT+CWJAP=\"WE_A3432C\",\"n6n05253\"\r\n");
		//Local_u8Result=ESP_voidESPValidateWifiConnection();
		Local_u8Result = 1 ;
	}
}
void ESP_ServerConnect(u8 * Copy_IP , u8 * Copy_Port)
{
	u8 Local_u8Result = 0 ;

	while(Local_u8Result==0)
	{
		UART_SendString("AT+CIPSTART=\"TCP\",\"185.176.43.112\",80\r\n");
		//Local_u8Result=ESP_voidESPValidateCmd();
		Local_u8Result = 1 ;
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
		Local_u8Result =1 ;
	}
	Local_u8Result = 0 ;
	while(Local_u8Result==0)
	{
		UART_SendString("GET http://jimy.atwebpages.com/status.txt\r\n");
		Local_u8Result=ESP_voidESPValidateCmd();
		Local_u8Result = 1 ;
	}
	Local_u8Result = 1 ;
	//	UART_SendString(Copy_URL);
	//	UART_SendString("\r\n");
}
u8 ESP_voidESPValidateCmd(void)
{
	volatile u8 Local_u8Response[100];
	u8 i = 0 ;
	u16 Dummy = 0 ;
	volatile u8 Result=0;
	while(Dummy < 255)
	{
		Dummy = UART_u8Receive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	i=0  ;
	while( (Local_u8Response[i] != 'O') || (Local_u8Response[i+1] != 'K') )
	{
		i++ ;
		if(i == 100)
		{
			break ;
		}
	}
	if( (Local_u8Response[i] == 'O') && (Local_u8Response[i+1] == 'K'))
	{
		Result = 1 ;
	}

	/*
	if( ((Local_u8Response[7] == 79)&& (Local_u8Response[8] == 'K' )) || ((Local_u8Response[16] == 'O') && (Local_u8Response[17] == 'K' ))
|| ( ( Local_u8Response[78] == 'O') && ( Local_u8Response[79] == 'K' )) || ( ( Local_u8Response[78] == 'O') && ( Local_u8Response[79] == 'K' ))
|| ((Local_u8Response[16] == 'O') && (Local_u8Response[17] == 'K' )))
	{
		//asm("NOP");
		Result=1;
	}
	 */
	return Result ;
}

u8 ESP_voidESPValidateWifiConnection(void)
{
	static volatile u8 Local_u8Response[100];
	static volatile u8 Local_u8ReadData;
	u8 i = 0 ;
	u16 Dummy = 0 ;
	volatile u8 Result=0;
	while(Dummy < 255)
	{
		Dummy = UART_ReceiveSynchronous();
		Local_u8Response[i]=Dummy;
		i++;
	}
	i = 0 ;
	while( Local_u8ReadData != 'b' || Local_u8ReadData != 'S' || Local_u8ReadData != 255  || Local_u8ReadData != 'O' )
	{
		Local_u8ReadData = Local_u8Response[i];
		i++;
		if(Local_u8ReadData == 'O')
		{
			Local_u8ReadData = Local_u8Response[i];
			if(Local_u8ReadData == 'K')
			{
				Result = 1 ;
			}
		}
		else if(Local_u8ReadData == 'b')
		{
			Local_u8ReadData = Local_u8Response[i];
			i++;
			if(Local_u8ReadData == 'u')
			{
				Local_u8ReadData = Local_u8Response[i] ;
				i++ ;
				if(Local_u8ReadData == 's')
				{
					Local_u8ReadData = Local_u8Response[i] ;
					i++ ;
				}
				if(Local_u8ReadData == 'y')
				{
					Result = 1 ;
				}
			}
		}
		else if(Local_u8ReadData == 255)
		{
			Local_u8ReadData = Local_u8Response[i];
			i++;
			if(Local_u8ReadData == 'u')
			{
				Local_u8ReadData = Local_u8Response[i] ;
				i++ ;
				if(Local_u8ReadData == 's')
				{
					Local_u8ReadData = Local_u8Response[i] ;
					i++ ;
				}
				if(Local_u8ReadData == 'y')
				{
					Result = 1 ;
				}
			}
		}
		else if(Local_u8ReadData == 'S')
		{
			Local_u8ReadData = Local_u8Response[i];
			i++;
			if(Local_u8ReadData == 'E')
			{
				Local_u8ReadData = Local_u8Response[i] ;
				i++ ;
				if(Local_u8ReadData == 'N')
				{
					Local_u8ReadData = Local_u8Response[i] ;
					i++ ;
				}
				if(Local_u8ReadData == 'D')
				{
					Result = 1 ;
				}
			}
		}
		/*
		else if(Local_u8ReadData == 'C')
		{
			Local_u8ReadData = Local_u8Response[i];
			i++;
			if(Local_u8ReadData == 'W')
			{
				Local_u8ReadData = Local_u8Response[i] ;
				i++ ;
				if(Local_u8ReadData == 'J')
				{
					Local_u8ReadData = Local_u8Response[i] ;
					i++ ;
				}
				if(Local_u8ReadData == 'A')
				{
					Result = 1 ;
				}
			}
		}
		*/
		if(i == 50 )
		{
			break ;
		}
	}
	/*
	if(( Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K')|| ((Local_u8Response[i+1] == 'u') && (Local_u8Response[i+2] == 's') && (Local_u8Response[i+3] == 'y'))
			|| ((Local_u8Response[i+1] == 'E') && (Local_u8Response[i+2] == 'N') && (Local_u8Response[i+3] == 'D')) )
	{
		Result = 1 ;
	}
	/*
	if( ((Local_u8Response[7] == 79)&& (Local_u8Response[8] == 'K' )) || ((Local_u8Response[16] == 'O') && (Local_u8Response[17] == 'K' ))
	|| ( ( Local_u8Response[78] == 'O') && ( Local_u8Response[79] == 'K' )) || ( ( Local_u8Response[49] == 'O') && ( Local_u8Response[50] == 'K' ))
	)
		{
			//asm("NOP");
			Result=1;
		}
	 */
	return Result ;
}
u8 ESP_ReadFile(void)
{
	volatile u8 Data_u8Return ;
	volatile u8 Local_u8Response[100];

	u8 volatile i ,Dummy;
	while( i < 20)
	{
		Dummy = UART_u8Receive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	i = 0 ;
	while(Local_u8Response[i] != '+')
	{
		i++ ;
	}
	Data_u8Return = Local_u8Response[i+7];

	return Data_u8Return;

}

