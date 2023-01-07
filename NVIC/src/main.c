#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"

void main (void)
{

	RCC_voidInitializeSystemClock();
	RCC_voidEnablePeripheralClock(0, 0);

	GPIO_voidSetPinsMode();

	NVIC_voidPriorityInit(); //2 groups 8 sub

	NVIC_voidSetPriority(32, 0b1000);
	NVIC_voidSetPriority(31, 0b1111);

	NVIC_voidEnableInterrupt(31);
	NVIC_voidEnableInterrupt(32);

	NVIC_voidSetPendingFlag(31);

}

void I2C1_EV_IRQHandler ()
{
	GPIO_voidSetPinValue(PORTA, PIN0, HIGH);
	NVIC_voidSetPendingFlag(32);
	GPIO_voidSetPinValue(PORTA, PIN1, HIGH);
}

void I2C1_ER_IRQHandler ()
{
	GPIO_voidSetPinValue(PORTA, PIN2, HIGH);
}
