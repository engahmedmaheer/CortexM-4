#include "STD_TYPES.h"
#include "ERR_STATUE.h"
#include "DET.h"

#include"GPIO_interface.h"
#include"RCC_interface.h"
#include"USART_interface.h"


void main (void)
{
	RCC_voidInitializeSystemClock();
	/*GPIOA CLCK ENABLE*/
	RCC_voidEnablePeripheralClock(0,0);
	/*USART CLCK ENABLE*/
	RCC_voidEnablePeripheralClock(2,4);


	GPIO_voidSetPinsMode();
	GPIO_VoidSetAlternateFunction(PORTA,PIN9,7);
	GPIO_VoidSetAlternateFunction(PORTA,PIN10,7);

	USART_VoidInit();
	uint8 Local_ReceiveData;
	while (1)
	{
		Local_ReceiveData=USART_u16ReceiveData();
		if (Local_ReceiveData=='1')
		{
			GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
			USART_u16SendData('OK');
		}
		else if  (Local_ReceiveData=='0')
		{
			GPIO_voidSetPinValue(PORTA,PIN0,LOW);
		}




	}
}
