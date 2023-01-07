
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#include "MCP2515_Interface.h"
#include "UART_Interface.h"
#include <util/delay.h>

#define SREG *((volatile u8 *) 0x5F)

extern u8 readBuffer[];

void main(void)
{
	MCP2515_VidReceiveInit();
	UART_VidInit();
	DIO_VidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);
	u8 dataR = 0;

	while(1)
	{
		if(DIO_U8GetPinValue(DIO_PORTD, DIO_PIN2) == 0)
		{
			MCP2515_VidReceiveCANmsg();

			for(u8 i=0; i<8; i++)
			{
				dataR = readBuffer[6+i];
				UART_VidSendData(dataR);
			}
			UART_VidSendData('\r');
			UART_VidSendData('\n');
		}

	}
}
