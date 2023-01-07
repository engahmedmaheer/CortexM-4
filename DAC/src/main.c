#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"


#include "DAC.h"


void main (void)
{
	RCC_voidInitializeSystemClock();
	RCC_voidEnablePeripheralClock(RCC_AHB,0);

	SYSTICK_voidInit();


	GPIO_voidSetPinsMode();

	uint32 songcounter=0;


	while(1)
	{

		GPIO_VoidSetPortValue(PORTA ,song[ songcounter] );
		songcounter++;

		SYSTICK_voidSynchUsecondsDelay(122);

		if(songcounter==79970)
		{
			songcounter=0;
		}

	}
}
