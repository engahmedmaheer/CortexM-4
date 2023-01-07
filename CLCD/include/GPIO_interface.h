#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#include "GPIO_config.h"

typedef struct
{
	uint8 PORT_ID     ;
	uint8 PIN_ID      ;
	uint8 MODE        ;
	uint8 OTYPE       ;
	uint8 OSPEED      ;
	uint8 PULL_UP_DOWN;
}pinInfo;

pinInfo arrOfPins[NUMBER_OF_USED_PINS];

typedef enum
{
	PORTA,
	PORTB,
	PORTC
}PORT_IDs_E;

typedef enum
{
	PIN0  ,
	PIN1  ,
	PIN2  ,
	PIN3  ,
	PIN4  ,
	PIN5  ,
	PIN6  ,
	PIN7  ,
	PIN8  ,
	PIN9  ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15
}PIN_IDs_E;

typedef enum
{
	LOW,
	HIGH
}PIN_STATE_E;




void GPIO_voidSetPinsMode(void);
void GPIO_voidSetPinValue(PORT_IDs_E  portId,
                          PIN_IDs_E   pinId,
						  PIN_STATE_E pinState);
uint8 GPIO_uint8GetPinValue(PORT_IDs_E  portId,
                            PIN_IDs_E   pinId);
void GPIO_VoidSetPortValue(PORT_IDs_E  portId , uint8 pinState );

//int arr[5]= {[0]=5, [3]=6, [2]=1};

#endif
