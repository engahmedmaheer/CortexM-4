#ifndef STD_TYPES
#define STD_TYPES

typedef unsigned char      uint8;  
typedef signed char        sint8;

typedef unsigned short int uint16;
typedef unsigned long int  uint32;

typedef enum
{
	InvalidClock,
	InvalidClock_Pll,
	InvalidBusId,
	InvalidPeripheralId,
}RCC_Error_Id;

typedef enum
{
	RCC_IntiaFunction_Id,
	RCC_EnablePeripheral_Function_ID,
	RCC_DisablePeripheral_Function_ID
}RCC_Function_Id;


#endif
