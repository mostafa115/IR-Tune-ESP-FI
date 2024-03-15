#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_Cfg.h"
#include "UART_Private.h"
#include "GPIO_Interface.h"

u8 Global_Data[8] = {0};

void(*UART_TX_Fptr)(void)=NULL_POINTER;
void(*UART_RX_Fptr)(void)=NULL_POINTER;

void UART_Init(void)
{   //Choose over Sampling
#if UART_OVERSAMPLING==UART_OVERSAMPLING_16
	UART2->CR1&=~(1<<OVER8);
#elif   UART_OVERSAMPLING==UART_OVERSAMPLING_8
	UART1->CR1|=(1<<OVER8);
#endif

	//Choose Clk  (16 MHZ Sampling ->16)
#if UART_BAUDRATE==UART_BAUDRATE_9600

	//UART2->BRR=11;    //DIV/Factor
	//UART2->BRR|=(8<<4);  //DIV_Mantissa
	UART2->BRR=0x8B;
	//UART1->BRR=0xD03;

#elif  UART_BAUDRATE==UART_BAUDRATE_19200


#endif

#if UART_WORDLENGTH == UART_DATA8_NOPARITY
	UART2->CR1&=~(1<<M);//Data length(8)
	UART2->CR1&=~(1<<PCE);//NO PArity
#elif 	UART_WORDLENGTH==UART_DATA8_PARITY_EVEN
	UART1->CR1&=~(1<<M);//Data length(8)
	UART1->CR1|=(1<<PCE);  //Parity Enable
	UART1->CR1&=~(1<<PS);   //Parity Even

#elif 	UART_WORDLENGTH==UART_DATA8_PARITY_ODD
	UART1->CR1&=~(1<<M);//Data length(8)
	UART1->CR1|=(1<<PCE);  //Parity Enable
	UART1->CR1|=(1<<PS);   //Parity Odd
#elif UART_WORDLENGTH == UART_DATA8_NOPARITY
	UART1->CR1|=(1<<M);//Data length(9)
	UART1->CR1&=~(1<<PCE);//NO PArity
#endif

	//Choose Stop_Bit Length
	UART2->CR2&=~(TWO_BIT_MASK<<12);
	UART2->CR2|=(UART_STOPBIT_LENGTH<<12);


	//TX Enable
	UART2->CR1|=(1<<TE);
	//RX Enable
	UART2->CR1|=(1<<RE);
	//UART ENABLE
	UART2->CR1|=(1<<UE);


}

void UART_SendSynchronous(u16 data)
{
	static u8 i = 0 ;
	while(!GET_BIT(UART2->SR,TXE));
	UART2->DR=data;
	Global_Data[i] = UART2->DR ;
	i++ ;
	if(i == 3)
	{
		asm("NOP");
	}
}
/*
u16 UART_ReceiveSynchronous(void)
{
	while(GET_BIT(UART1->SR,RXNE)==0);

	return (UART1->DR);
}

 */

u8 UART_u8Receive(void)
{
	UART2->BRR=11;    //DIV/Factor
	UART2->BRR|=(8<<4);  //DIV_Mantissa
	u8 Local_u8ReceiveData = 0 ;
	u32 local_u32TimeOut = 0;

	while(!GET_BIT(UART2->SR, 5))
	{
		local_u32TimeOut ++ ;

		if(local_u32TimeOut > 1000000)
		{
			Local_u8ReceiveData = 255 ;
			break ;
		}
	}

	if(Local_u8ReceiveData == 0)
	{
		Local_u8ReceiveData = UART2->DR ;
	}
	return Local_u8ReceiveData;
}
void UART_SendASynchronous(u16 data)
{

	UART2->DR=data;
}

u16 UART_ReceiveASynchronous(void)
{

	return (UART2->DR);
}


void UART_TX_InterruptEnable(void)
{
	UART2->CR1|=(1<<TCIE);
}
void UART_RX_InterruptEnable(void)
{
	UART2->CR1|=(1<<RXNEIE);
}
void UART_TX_InterruptDisable(void)
{
	UART2->CR1&=~(1<<TCIE);
}
void UART_RX_InterruptDisable(void)
{
	UART2->CR1&=~(1<<RXNEIE);
}

void UART_TX_CallBackFunction(void(*local_fptr)(void))
{
	UART_TX_Fptr=local_fptr;
}

void UART_RX_CallBackFunction(void(*local_fptr)(void))
{
	UART_RX_Fptr=local_fptr;
}

/* UART Service  */
UART_SendString(u8*str)
{
	for(u8 i=0;str[i];i++)
	{
		UART_SendSynchronous(str[i]);

//		if((str[i+1] == 13) || (str[i+1]==10))
//		{
//			UART2->BRR=0;    //DIV/Factor
//			UART2->BRR|=(8<<4);  //DIV_Mantissa
//
//		}
		/*
		else
		{
			UART2->BRR=11;    //DIV/Factor
			UART2->BRR|=(8<<4);  //DIV_Mantissa

		}
		 */
	}
}


void USART1_IRQHandler(void)
{
	if(GET_BIT(UART2->SR,TC)==1)
	{
		if(UART_TX_Fptr!=NULL_POINTER)
		{
			UART_TX_Fptr();
		}

		//Clear TC(TX_interrupt_flag)
		UART2->SR&=~(1<<TC);
	}

	if(GET_BIT(UART2->SR,RXNE)==1)
	{
		if(UART_RX_Fptr!=NULL_POINTER)
		{
			UART_RX_Fptr();
		}

		//Clear TC(TX_interrupt_flag)
		UART2->SR&=~(1<<RXNE);
	}
}



void USART6_IRQHandler(void)
{


}
