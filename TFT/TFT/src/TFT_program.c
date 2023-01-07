#include "STD_TYPES.h"
#include "TFT_Config.h"
#include "TFT_Private.h"
#include "TFT_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"

void TFT_Intia(void)
{
	// reset pulse
	GPIO_SET_PIN_VALUE_ODR(TFT_PORT,REST_PIN,HIGH);
	SYSTICK_voidSynchUsecondsDelay(100);
	GPIO_SET_PIN_VALUE_ODR(TFT_PORT,REST_PIN,LOW);
	SYSTICK_voidSynchUsecondsDelay(2);
	GPIO_SET_PIN_VALUE_ODR(TFT_PORT,REST_PIN,HIGH);
	SYSTICK_voidSynchUsecondsDelay(100);
	GPIO_SET_PIN_VALUE_ODR(TFT_PORT,REST_PIN,LOW);
	SYSTICK_voidSynchUsecondsDelay(100);
	GPIO_SET_PIN_VALUE_ODR(TFT_PORT,REST_PIN,HIGH);
	SYSTICK_voidSynchUsecondsDelay(120000);
	// sleep out
   SEND_COMMAND(0x11);
	SYSTICK_voidSynchUsecondsDelay(150000);
   //color mode
   SEND_COMMAND(0x3A);
    SEND_DATA(0x05);
    // diplay on
    SEND_COMMAND(0x29);
}

void SEND_COMMAND(uint8 command)
{
	
GPIO_SET_PIN_VALUE_ODR(TFT_PORT,A0_PIN,LOW);
SPI_Send(command);

}
void SEND_DATA(uint8 data)
{
	GPIO_SET_PIN_VALUE_ODR(TFT_PORT,A0_PIN,HIGH);
	SPI_Send(data);
}

void TFT_DISPLAY_IMG(const uint16*img)
{
	uint16 local_counter;
	uint8 data;
 // set x adress
	SEND_COMMAND(0x2A);
	// this because echa on has 2 byte
	SEND_DATA(0); // START
	SEND_DATA(0); // START
	SEND_DATA(0); // end
	SEND_DATA(127); //END // this is big indian so we send msb at first
	// set Y
	SEND_COMMAND(0x2B);
	SEND_DATA(0); // START
	SEND_DATA(0); // START
	SEND_DATA(0); // end
	SEND_DATA(159); //END
// SEND DATA OF IMG TO SHOW IT
	SEND_COMMAND(0x2C);            // RAM WRITE
for(local_counter=0;local_counter<20480;local_counter++)
{
	data=img[local_counter]>>8;
SEND_DATA(data);
data=img[local_counter];
SEND_DATA(data);
}

}


