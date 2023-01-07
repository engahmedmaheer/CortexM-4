#ifndef SPI_interface
#define SPI_interface

void SPI_Master_Init(void);
void SPI_Slave_Init(void);

void SPI_Send(uint8 data);
void SPI_SEND_RECIVE(uint8 TransmittedData, uint8* ReceivedData);



#endif
