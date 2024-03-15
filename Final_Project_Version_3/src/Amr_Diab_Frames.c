/*
 * Amr_Diab_Frames.c
 *
 *  Created on: 1/3/2024
 *      Author: Jimmy
 */
#include "STD_TYPES.h"
#include "STP_interface.h"
#include "Amr_Diab_Frames.h"

void Amr_Diab_Frame1()
{
	S2P_vSendData(0xFEF8);
	S2P_vSendData(0xFD24);
	S2P_vSendData(0xFB22);
	S2P_vSendData(0xF722);
	S2P_vSendData(0xEF24);
	S2P_vSendData(0xDFF8);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0x7F00);
}
void Amr_Diab_Frame2()
{
	S2P_vSendData(0xFE24);
	S2P_vSendData(0xFD22);
	S2P_vSendData(0xFB22);
	S2P_vSendData(0xF724);
	S2P_vSendData(0xEFF8);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0xBFFC);
}
void Amr_Diab_Frame3()
{
	S2P_vSendData(0xFE22);
	S2P_vSendData(0xFD22);
	S2P_vSendData(0xFB24);
	S2P_vSendData(0xF7F8);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBFFC);
	S2P_vSendData(0xBF04);
}
void Amr_Diab_Frame4()
{
	S2P_vSendData(0xFE22);
	S2P_vSendData(0xFD24);
	S2P_vSendData(0xFBF8);
	S2P_vSendData(0xF700);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDFFC);
	S2P_vSendData(0xBF04);
	S2P_vSendData(0xBF08);
}
void Amr_Diab_Frame5()
{
	S2P_vSendData(0xFE00);
	S2P_vSendData(0xFDFC);
	S2P_vSendData(0xFB04);
	S2P_vSendData(0xF708);
	S2P_vSendData(0xEFF0);
	S2P_vSendData(0xDF08);
	S2P_vSendData(0xBF04);
	S2P_vSendData(0xBFFC);
}
void Amr_Diab_Frame6()
{
	S2P_vSendData(0xFEFC);
	S2P_vSendData(0xFD04);
	S2P_vSendData(0xFB08);
	S2P_vSendData(0xF7F0);
	S2P_vSendData(0xEF08);
	S2P_vSendData(0xDF04);
	S2P_vSendData(0xBFFC);
	S2P_vSendData(0xBF00);

}
void Amr_Diab_Frame7()
{
	S2P_vSendData(0xFE04);
	S2P_vSendData(0xFD08);
	S2P_vSendData(0xFBF0);
	S2P_vSendData(0xF708);
	S2P_vSendData(0xEF04);
	S2P_vSendData(0xDFFC);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0xBFFC);
}
void Amr_Diab_Frame8()
{
	//*******************************************
	S2P_vSendData(0xFE08);
	S2P_vSendData(0xFDF0);
	S2P_vSendData(0xFB08);
	S2P_vSendData(0xF704);
	S2P_vSendData(0xEFFC);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBFFC);
	S2P_vSendData(0xBF24);

}
void Amr_Diab_Frame9()
{
	//**************************************
	S2P_vSendData(0xFEF0);
	S2P_vSendData(0xFD08);
	S2P_vSendData(0xFB04);
	S2P_vSendData(0xF7FC);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDFFC);
	S2P_vSendData(0xBF24);
	S2P_vSendData(0xBF24);
}
void Amr_Diab_Frame10()
{
	//**********************************
	S2P_vSendData(0xFE08);
	S2P_vSendData(0xFD04);
	S2P_vSendData(0xFBFC);
	S2P_vSendData(0xF700);
	S2P_vSendData(0xEFFC);
	S2P_vSendData(0xDF24);
	S2P_vSendData(0xBF24);
	S2P_vSendData(0xBF58);
}
void Amr_Diab_Frame11(void){
	//******************************
	S2P_vSendData(0xFE04);
	S2P_vSendData(0xFDFC);
	S2P_vSendData(0xFB00);
	S2P_vSendData(0xF7FC);
	S2P_vSendData(0xEF24);
	S2P_vSendData(0xDF24);
	S2P_vSendData(0xBF58);
	S2P_vSendData(0xBF80);
}
void Amr_Diab_Frame12(void)
{
	//*****************************
	S2P_vSendData(0xFEFC);
	S2P_vSendData(0xFD00);
	S2P_vSendData(0xFBFC);
	S2P_vSendData(0xF724);
	S2P_vSendData(0xEF24);
	S2P_vSendData(0xDF58);
	S2P_vSendData(0xBF80);
	S2P_vSendData(0xBF00);
}
void Amr_Diab_Frame13(void)
{
	//******************************
	S2P_vSendData(0xFE00);
	S2P_vSendData(0xFDFC);
	S2P_vSendData(0xFB24);
	S2P_vSendData(0xF724);
	S2P_vSendData(0xEF58);
	S2P_vSendData(0xDF80);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0xBFFC);
}
void Amr_Diab_Frame14(void)
{
	//*****************************
	S2P_vSendData(0xFEFC);
	S2P_vSendData(0xFD24);
	S2P_vSendData(0xFB24);
	S2P_vSendData(0xF758);
	S2P_vSendData(0xEF80);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBFFC);
	S2P_vSendData(0xBF54);
}
void Amr_Diab_Frame15(void)
{
	//*****************************
	S2P_vSendData(0xFE24);
	S2P_vSendData(0xFD24);
	S2P_vSendData(0xFB58);
	S2P_vSendData(0xF780);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDFFC);
	S2P_vSendData(0xBF84);
	S2P_vSendData(0xBF48);
}
void Amr_Diab_Frame16(void)
{
	//******************************
	S2P_vSendData(0xFE24);
	S2P_vSendData(0xFD58);
	S2P_vSendData(0xFB80);
	S2P_vSendData(0xF700);
	S2P_vSendData(0xEFFC);
	S2P_vSendData(0xDF84);
	S2P_vSendData(0xBF48);
	S2P_vSendData(0xBF30);
}
void Amr_Diab_Frame17(void)
{
	//*****************************
	S2P_vSendData(0xFE58);
	S2P_vSendData(0xFD80);
	S2P_vSendData(0xFB00);
	S2P_vSendData(0xF7FC);
	S2P_vSendData(0xEF84);
	S2P_vSendData(0xDF48);
	S2P_vSendData(0xBF30);
	S2P_vSendData(0xBF00);
}
void Amr_Diab_Frame18(void)
{
	//********************************
	S2P_vSendData(0xFE80);
	S2P_vSendData(0xFD00);
	S2P_vSendData(0xFBFC);
	S2P_vSendData(0xF784);
	S2P_vSendData(0xEF48);
	S2P_vSendData(0xDF30);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0xBFF4);
}
void Amr_Diab_Frame19(void)
{
	//******************************
	S2P_vSendData(0xFE00);
	S2P_vSendData(0xFDFC);
	S2P_vSendData(0xFB84);
	S2P_vSendData(0xF748);
	S2P_vSendData(0xEF30);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBFF4);
	S2P_vSendData(0xBF00);
}
void Amr_Diab_Frame20(void)
{
	//******************************
	S2P_vSendData(0xFEFC);
	S2P_vSendData(0xFD84);
	S2P_vSendData(0xFB48);
	S2P_vSendData(0xF730);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDFF4);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0xBFF0);
}
void Amr_Diab_Frame21(void)
{
	//****************************
	S2P_vSendData(0xFE84);
	S2P_vSendData(0xFD48);
	S2P_vSendData(0xFB30);
	S2P_vSendData(0xF700);
	S2P_vSendData(0xEFF4);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBFF0);
	S2P_vSendData(0xBF28);
}
void Amr_Diab_Frame22(void)
{
	//*****************************
	S2P_vSendData(0xFE48);
	S2P_vSendData(0xFD30);
	S2P_vSendData(0xFB00);
	S2P_vSendData(0xF7F4);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDFF0);
	S2P_vSendData(0xBF28);
	S2P_vSendData(0xBF24);
}
void Amr_Diab_Frame23(void)
{
	//******************************
	S2P_vSendData(0xFE30);
	S2P_vSendData(0xFD00);
	S2P_vSendData(0xFBF4);
	S2P_vSendData(0xF700);
	S2P_vSendData(0xEFF0);
	S2P_vSendData(0xDF28);
	S2P_vSendData(0xBF24);
	S2P_vSendData(0xBF28);
}
void Amr_Diab_Frame24(void)
{
	//*******************************
	S2P_vSendData(0xFE00);
	S2P_vSendData(0xFDF4);
	S2P_vSendData(0xFB00);
	S2P_vSendData(0xF7F0);
	S2P_vSendData(0xEF28);
	S2P_vSendData(0xDF24);
	S2P_vSendData(0xBF28);
	S2P_vSendData(0xBFF0);
}
void Amr_Diab_Frame25(void)
{
	//*******************************
	S2P_vSendData(0xFEF4);
	S2P_vSendData(0xFD00);
	S2P_vSendData(0xFBF0);
	S2P_vSendData(0xF728);
	S2P_vSendData(0xEF24);
	S2P_vSendData(0xDF28);
	S2P_vSendData(0xBFF0);
	S2P_vSendData(0xBF00);
}
void Amr_Diab_Frame26(void)
{
	//*******************************
	S2P_vSendData(0xFE00);
	S2P_vSendData(0xFDF0);
	S2P_vSendData(0xFB28);
	S2P_vSendData(0xF724);
	S2P_vSendData(0xEF28);
	S2P_vSendData(0xDFF0);
	S2P_vSendData(0xBF00);
	S2P_vSendData(0xBFFC);
}
void Amr_Diab_Frame27(void)
{
	//******************************
	S2P_vSendData(0xFEF0);
	S2P_vSendData(0xFD28);
	S2P_vSendData(0xFB24);
	S2P_vSendData(0xF728);
	S2P_vSendData(0xEFF0);
	S2P_vSendData(0xDF00);
	S2P_vSendData(0xBFFC);
	S2P_vSendData(0xBF90);

}
void Amr_Diab_Frame28(void)
{
	//******************************
	S2P_vSendData(0xFE28);
	S2P_vSendData(0xFD24);
	S2P_vSendData(0xFB28);
	S2P_vSendData(0xF7F0);
	S2P_vSendData(0xEF00);
	S2P_vSendData(0xDFFC);
	S2P_vSendData(0xBF90);
	S2P_vSendData(0xBFF0);
}
void Amr_Diab_Frame29(void)
{
	//******************************
	S2P_vSendData(0xFE14);
	S2P_vSendData(0xFDF8);
	S2P_vSendData(0xFB00);
	S2P_vSendData(0xF700);
	S2P_vSendData(0xEFFE);
	S2P_vSendData(0xDF92);
	S2P_vSendData(0xBF5E);
	S2P_vSendData(0xBF7C);
}
void Amr_Diab_Frame30(void)
{
	//******************************
	S2P_vSendData(0xFEF8);
	S2P_vSendData(0xFD00);
	S2P_vSendData(0xFB00);
	S2P_vSendData(0xF7FE);
	S2P_vSendData(0xEF92);
	S2P_vSendData(0xDF5E);
	S2P_vSendData(0xBF7C);
	S2P_vSendData(0xBF00);
}
