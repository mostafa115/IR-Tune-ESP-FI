#ifndef HESP_INT_H
#define HESP_INT_H

void ESP_voidInit(void);

//void ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password, u8 Copy_Name_Size , u8 Copy_Password_Size) ;
void ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password);

void ESP_ServerConnect(u8 * Copy_IP , u8 * Copy_Port);

void ESP_SendHttpRequest(u8 * Copy_URL , u8 * Length);

u8 ESP_voidESPValidateCmd(void);



typedef enum {
	WIFI_OK=0,
	WIFI_NOK
}WIFI_Status;


#endif
