#ifndef HESP_INT_H
#define HESP_INT_H

void ESP_voidInit(void);

void ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password);

void ESP_ServerConnect(u8 * Copy_IP , u8 * Copy_Port);

void ESP_SendHttpRequest(u8 * Copy_URL , u8 * Length );

u8 ESP_voidESPValidateCmd(void);

u8 ESP_ReadFile(void);

u8 ESP_voidESPValidateWifiConnection(void);

#endif
