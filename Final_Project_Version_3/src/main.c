/*
 * 	main.c
 *
 *  Created on: 10/3/2024
 *      Author: Jimmy
 */

/**********************************/
/* Includes H files */
/**********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "GPIO_interface.h"
#include "HESP_int.h"
#include "SYSTICK_interface.h"
#include "DAC_interface.h"
#include "GPTIM_interface.h"
#include "STP_interface.h"
#include "SPI.h"
#include "TFT_interface.h"
#include "IR_interfce.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "UART_Interface.h"
#include "_5aleny_f_7odnk.h"
#include "Tamer_Ashour.h"
#include "Amr_Diab.h"
#include "Wayah.h"
#include "Amr_Diab_Frames.h"
#include "Tamer_Ashour_Frames.h"

/**************************************************
Using this function to Organize The Application
****************************************************/
void OS_voidOrganizeTasks(void);


/**************************************************
IR Application FUnction
****************************************************/
void Play_voidIR(void);



/**************************************************
Display the Name of singer On Led Matrix
****************************************************/
void Play_LedMatrix(void);



/* Update Number of task in this Variable */
static u8 Global_u8TaskFlagNumber = 0 ;
/* Update Number of Remote in IR APPLiCation Fumnction in this variable */
static u8 Global_u8RemoteNumber = 0 ;
/* If You Clicked On remote Just raise this variable */
static u8 Global_u8RemoteFlag = 0 ;
/* Update Number of threadd in THis functionPlay_LedMatrix() because i divided the whole frame into threads */
static u16 Global_u8LedMatrixThreads = 0 ;


void main()
{
	/* Initialize RCC */
	MRCC_vInt();
	/* Enable Clock of RCC For Port A */
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOA);
	/* Enable Clock of RCC For Port B */
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOB);
	/* Initialize Systick Pripheral */
	MSYSYTICK_voidInit();

	/* Set Port B From Pin 0 -> To Pin 7 Output PushPull For DAC */
	HR2RDAC_vInit();

	/* Set Port A , Pin 8 Output PushPull For Data Serial In STP   */
	MGPIO_vSetMode(PORT_A,PIN_8,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_8,OUTPUT_PUSHPULL,SPEED_LOW);

	/* Enable Tim2 */
	MRCC_vEnable(RCC_APB1,APB1_TIM2);

	/* Init Timer 2 */

	TIM2_voidInit();

	/* Led Matrix Section */

	MRCC_vEnable(RCC_AHB1,AHB1_GPIOA);

	/* Initialize STP */
	S2P_vInit();

	/* TFT Section */

/* Enable SPI FOR TFT */
	MRCC_vEnable(RCC_APB2, APB2_SPI1);
/* Initialize SPI */
	MSPI_VoidInit();
/* SET these Pins Alternative Function For SPI */
	MGPIO_vSetMode(PORT_A,PIN_4,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_5,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_6,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_7,MODE_ALTERNATIVE);

	/* Set Pins 5,6,7 as an Alternative Function For SPI */

	/* PIN4 -> Slave Select */
	MGPIO_vSetAlternativeMode(PORT_A,PIN_4,5);
	/* PIN5 -> SCK */
	MGPIO_vSetAlternativeMode(PORT_A,PIN_5,5);
	/* PIN6 -> MISO */
	MGPIO_vSetAlternativeMode(PORT_A,PIN_6,5);
	/* PIN6 -> MOSI */
	MGPIO_vSetAlternativeMode(PORT_A,PIN_7,5);
	/* SET Pin2 , Pin 3 Output for ESP */
	MGPIO_vSetMode(PORT_A,PIN_2,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_2,OUTPUT_PUSHPULL,SPEED_LOW);

	MGPIO_vSetMode(PORT_A,PIN_3,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_3,OUTPUT_PUSHPULL,SPEED_LOW);

	/* Initialize TFT */
	HTFT_voidInitialize();

	/* IR Section */

	PlayFunction_voidcallback(Play_voidIR);

	/* Set BIT 0 Input FOR Interrupt */

	MGPIO_vSetMode(PORT_A,0,MODE_INPUT);
	MGPIO_vSetInputMode(PORT_A,0,INPUT_PULLUP);

	/* EXTI Initializtion */

	MEXTI_voidInerruptSetPort(EXTI_LineZero ,EXTI_PortA);
	MEXTI0_voidCallBack(voidGetFrame);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero,EXTI_Enable) ;
	MEXTI_voidInterruptTrigger(EXTI_LineZero,EXTI_Falling) ;

	/* Enable RCC FOR TIM_3 */
	MRCC_vEnable(RCC_APB1,APB1_TIM3);

	/* Enable EXTI0 from NVIC */
	NVIC_vEnable(6);

	/* TIM_3 Init */
	TIM3_voidInit();
	MRCC_vEnable(RCC_APB1,APB1_TIM4);
	MRCC_vEnable(RCC_APB1,APB1_TIM5);
	/* Enable TIM_3 from NVIC */
	NVIC_vEnable(29);
	//NVIC_vEnable(30);
	NVIC_vEnable(50);

	/* SysTick Init */
	MSYSYTICK_voidInit();

	/* Enable Systick Interrupt */

	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);

	/* Enable Tim5 For Led Matrix */

	MRCC_vEnable(RCC_APB1,APB1_TIM5);

	/* Init Timer 5 */
	TIM5_voidInit();
	/* Enable Interrupt For Timer 5 */
	NVIC_vEnable(50);
	/* Pass this function as a call back to timer 5 */
	TIM5_voidSetIntervalPeriodic(100000,Play_LedMatrix);
	/* Pass OS function as a call back to timer 3 */
	TIM3_voidSetIntervalPeriodic(20000,OS_voidOrganizeTasks);
	/* Divide My pripherals into 16 Group Priority */
	NVIC_VoidSetInterruptGroupMode(Group16Sub0);
	/* Set EXTI0 Group periprity 0 */
	NVIC_VoidSetInterruptPriority(6,0,0);
	/* Set TIM3 Group periprity 1 */
	NVIC_VoidSetInterruptPriority(29,1,0);
	/* Set TIM5 Group periprity 2 */
	NVIC_VoidSetInterruptPriority(50,2,0);

	/* Clear TFT */
	HTFT_voidDisplayImage(0xff);

	/* I will Integrate ESP in second Edition but it works as IR individual */
	/* ESP Section */

	//MRCC_vEnable(RCC_AHB1,AHB1_GPIOB);

	//MRCC_vEnable(RCC_APB1,APB1_USART2);

	//MGPIO_vSetMode(PORT_A,PIN_2,MODE_ALTERNATIVE);
	//MGPIO_vSetMode(PORT_A,PIN_3,MODE_ALTERNATIVE);

	//MGPIO_vSetAlternativeMode(PORT_A,PIN_2,ALTR_UART);
	//MGPIO_vSetAlternativeMode(PORT_A,PIN_3,ALTR_UART);

	//	UART_Init();



	while(1)
	{
		/* Task NUmber 1 */
		if(Global_u8TaskFlagNumber == 1)
		{
			HTFT_voidDisplayImage(Tamer_Ashour_Photo);
			HR2RDAC_vSetData(Tamer_5aleny_f_7odnk,81790);
		}
		/* Task Number 2 */
		else if(Global_u8TaskFlagNumber == 2)
		{
			HTFT_voidDisplayImage(Amr_Diab_Photo);
			HR2RDAC_vSetData(Wayah_Amr_Diab,58644);
		}
		/* Task Number 3 */
		else if(Global_u8TaskFlagNumber == 3)
		{
			HTFT_voidDisplayImage(0xff);
		}


		/* I am gonna Integrate this section OF ESP */
	/*
		switch(Global_u8TaskFlagNumber)
		{
		case 1 :
			HTFT_voidDisplayImage(Tamer_Ashour_Photo);
			HR2RDAC_vSetData(Tamer_5aleny_f_7odnk,81790);
			break ;
		case 2 :
			HTFT_voidDisplayImage(Amr_Diab_Photo);
			HR2RDAC_vSetData(Wayah_Amr_Diab,58644);
			break ;

		case 3 :
			ESP_voidInit();
			break ;
		case 4 :
			ESP_WifiConnect("jamal10","mM101010#");
			break ;
		case 5 :
			ESP_ServerConnect("185.176.43.112","80");
			break ;
		case 6 :
			ESP_SendHttpRequest("http://jimy.atwebpages.com/status.txt","43") ;
			break ;
		case 7 :
			Global_u8ReadValue = ESP_ReadFile() ;
			break ;
	}
		 */
	}
}
/* IR Application Function */
void Play_voidIR(void)
{
	Global_u8RemoteFlag = 1 ;
	switch (Global_u8Data)
	{
	/* These are Numbers of signal and the number of function on remote */
	/* 22 = "0" , 12 = "1" , 24 = "2" , 94 = "3" , 4 = "8" , 5 = "28" , 90 = "6" , 66 = "7" , 82 = "8" , 74 = "9" */
	/* 69 = "Turn off" , 70 = "Mode" , 71 = "Mute" , 7 = "EQ" , 21 = "VOL-" , 9 = "VOL+" , 25 = "RPT" , 13 = "U/SD" */

	case 69:
		Global_u8RemoteNumber = 0xff ;
		break;

	case 12:
		Global_u8RemoteNumber = 1 ;
		break ;
	case 24:
		Global_u8RemoteNumber = 2 ;
		break ;
	default : break ;
	}
}



/* OS Function */
void OS_voidOrganizeTasks()
{
	static u16 Local_u16Counter = 0 ;

	if(Local_u16Counter == 1 )
	{
		if(Global_u8RemoteFlag == 1 )
		{
			if(Global_u8TFTINLoop == 1)
			{
				Global_u8TFTBreakLoop = 1 ;
				Global_u8TFTINLoop = 0 ;
			}
			else if (Global_u8DACINLoop == 1)
			{
				Global_u8DACBreakLoop = 1 ;
				Global_u8DACINLoop = 0 ;
			}
			Global_u8RemoteFlag = 0 ;
		}
		if(Global_u8RemoteNumber == 1)
		{
			Global_u8TaskFlagNumber = 1 ;
		}
		else if(Global_u8RemoteNumber == 2)
		{
			Global_u8TaskFlagNumber = 2 ;
		}
		else
		{
			Global_u8TaskFlagNumber = 3 ;
		}
	}
	else if(Local_u16Counter == 5 )
	{
		Local_u16Counter = 0 ;
	}

	Local_u16Counter ++ ;
}


void Play_LedMatrix()
{
	/* I divided the frame into many Frames to make the System working in parallel and as a multi tasking */
	if(Global_u8LedMatrixThreads < 5 )
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame1(); break ;
		case 2 : Amr_Diab_Frame1(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads ++ ;
	}
	else if(Global_u8LedMatrixThreads <10)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame2(); break ;
		case 2 : Amr_Diab_Frame2(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++ ;
	}
	else if(Global_u8LedMatrixThreads < 15)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame3(); break ;
		case 2 : Amr_Diab_Frame3(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++ ;
	}
	else if(Global_u8LedMatrixThreads < 20)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame4(); break ;
		case 2 : Amr_Diab_Frame4(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 25)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame5(); break ;
		case 2 : Amr_Diab_Frame5(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 30)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame6(); break ;
		case 2 : Amr_Diab_Frame6(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++ ;
	}
	else if(Global_u8LedMatrixThreads < 35)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame7(); break ;
		case 2 : Amr_Diab_Frame7(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++ ;
	}
	else if(Global_u8LedMatrixThreads < 40)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame8(); break ;
		case 2 : Amr_Diab_Frame8(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++ ;
	}
	else if(Global_u8LedMatrixThreads < 45)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame9(); break ;
		case 2 : Amr_Diab_Frame9(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 50)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame10(); break ;
		case 2 : Amr_Diab_Frame10(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 55)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame11(); break ;
		case 2 : Amr_Diab_Frame11(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 60)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame12(); break ;
		case 2 : Amr_Diab_Frame12(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 65)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame13(); break ;
		case 2 : Amr_Diab_Frame13(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 70)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame14(); break ;
		case 2 : Amr_Diab_Frame14(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 75)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame15(); break ;
		case 2 : Amr_Diab_Frame15(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 80)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame16(); break ;
		case 2 : Amr_Diab_Frame16(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 85)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame17(); break ;
		case 2 : Amr_Diab_Frame17(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 90)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame18(); break ;
		case 2 : Amr_Diab_Frame18(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 95)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame19(); break ;
		case 2 : Amr_Diab_Frame19(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 100)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame20(); break ;
		case 2 : Amr_Diab_Frame20(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 105)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame21(); break ;
		case 2 : Amr_Diab_Frame21(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 110)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame22(); break ;
		case 2 : Amr_Diab_Frame22(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 115)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame23(); break ;
		case 2 : Amr_Diab_Frame23(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 120)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame24(); break ;
		case 2 : Amr_Diab_Frame24(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 125)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame25(); break ;
		case 2 : Amr_Diab_Frame25(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 130)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame26(); break ;
		case 2 : Amr_Diab_Frame26(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 135)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame27(); break ;
		case 2 : Amr_Diab_Frame27(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 140)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame28(); break ;
		case 2 : Amr_Diab_Frame28(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 145)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 1 : Tamer_Ashour_Frame29(); break ;
		case 2 : Amr_Diab_Frame29(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else if(Global_u8LedMatrixThreads < 150)
	{
		switch(Global_u8TaskFlagNumber)
		{
		case 2 : Amr_Diab_Frame30(); break ;
		default : break ;
		}
		Global_u8LedMatrixThreads++;
	}
	else
	{
		Global_u8LedMatrixThreads = 0 ;
	}
}

