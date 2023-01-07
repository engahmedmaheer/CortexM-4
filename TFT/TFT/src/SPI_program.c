#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
void SPI_Master_Init(void)
{
	SPI_1->CR_1=0x0347;
}
void SPI_Slave_Init(void)
{
	SPI_1->CR_1=0x0343;

}

void SPI_Send(uint8 data)
{
	
	SPI_1->DR=data;
	while(GET_BIT(SPI_1->SR,7)==1);
}

uint8 SPI_RECIVE(void)
{
	uint8 data;
	data=SPI_1->DR;
	return data;
}

void SPI_SEND_RECIVE(uint8 TransmittedData, uint8* ReceivedData)
{
//	uint8 status;
	SPI_1->DR=TransmittedData;
	while(GET_BIT(SPI_1->SR,7)==1);
	*ReceivedData=SPI_1->DR;
// make error status 
}

// touch pannel 
