/*
 * DAC_interface.h
 *
 *  Created on: Jan 23, 2024
 *      Author: Jimmy
 */

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_


void HR2RDAC_vInit(void);
void HR2RDAC_vSetData(const u8 *arr,u32 arrsize);

u8 Global_u8DACINLoop ;
u8 Global_u8DACBreakLoop ;
u16 GLobal_u16FlagCounter ;

#endif /* DAC_INTERFACE_H_ */
