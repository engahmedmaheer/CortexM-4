#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

void main (void)
{

	RCC_voidInitializeSystemClock();
	RCC_voidEnablePeripheralClock(0,0);
	GPIO_voidSetPinsMode();
	while(1)
	{
		GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
		SYSTICK_voidSynchSecondsDelay(1);
	}


}
