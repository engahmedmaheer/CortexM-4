#ifndef SPI_private
#define SPI_private
typedef struct 
{
	uint32 CR_1;
	uint32 CR_2;
	uint32 SR;
	uint32 DR;
	uint32 CRCPR;
	uint32 RXCRCR ;
	uint32 TXCRCR  ;
	uint32 I2SCFGR  ;
	uint32 I2SPR  ;
}SPI_t;

#define SPI_1    ((SPI_t*)0x40013000) 


#endif