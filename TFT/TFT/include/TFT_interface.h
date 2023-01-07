#ifndef TFT_interface 
#define TFT_interface

void TFT_Intia(void);
void SEND_COMMAND(uint8 command);
void SEND_DATA(uint8 data);
void TFT_DISPLAY_IMG(const uint16*img);



#endif
