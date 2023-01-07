#ifndef RCC_INTERFACE
#define RCC_INTERFACE

void RCC_voidInitializeSystemClock(void);
void RCC_voidResetPeripheral(uint8 local_busId, uint8 local_peripheralId);
void RCC_voidEnablePeripheralClock(uint8 local_busId, uint8 local_peripheralId);
void RCC_voidDisablePeripheralClock(uint8 local_busId, uint8 local_peripheralId);


typedef enum
{
	RCC_AHB ,
	RCC_APB1,
	RCC_APB2
}busId_E;

#endif
