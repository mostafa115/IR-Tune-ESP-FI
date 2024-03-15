#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInitialize   (void);
void HTFT_voidDisplayImage (const u16* Copy_Image);

u8 Global_u8TFTBreakLoop  ;
u8 Global_u8TFTINLoop  ;

#endif
