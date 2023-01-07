#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

void main (void)
{
	while(1)
	{
		RCC_voidInitializeSystemClock();
		RCC_voidEnablePeripheralClock(0,0);
	    GPIO_voidSetPinsMode();
		GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
	}

}
