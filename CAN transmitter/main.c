
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#include "MCP2515_Interface.h"
#include <util/delay.h>

void main(void)
{

	MCP2515_VidInit();

	u8 msgData[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	while(1)
	{
		MCP2515_VidSendCANmsg(0, 0x7E1, msgData, 8);
		for(u8 i=0; i<8; i++)
		{
			msgData[i]++;
		}
		_delay_ms(1000);
	}
}
