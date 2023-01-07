#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

void GPIO_voidSetPinsMode(void)
{
	uint8 local_uint8PinsCounter;
	for(local_uint8PinsCounter=0; local_uint8PinsCounter<NUMBER_OF_USED_PINS; local_uint8PinsCounter++)
	{
		switch(arrOfPins[local_uint8PinsCounter].PORT_ID)
		{
		case PORTA:

			GPIOA -> MODER  &= ~((0b11) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			GPIOA -> MODER  |= ((arrOfPins[local_uint8PinsCounter].MODE) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			if(arrOfPins[local_uint8PinsCounter].MODE == OUTPUT)
			{
				GPIOA -> OTYPER  &= ~(1 << (arrOfPins[local_uint8PinsCounter].PIN_ID));
				GPIOA -> OTYPER  |=  ((arrOfPins[local_uint8PinsCounter].OTYPE) << (arrOfPins[local_uint8PinsCounter].PIN_ID));

				GPIOA -> OSPEEDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOA -> OSPEEDR  |=  ((arrOfPins[local_uint8PinsCounter].OSPEED) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}				
			else
			{
				GPIOA -> PUPDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOA -> PUPDR  |=  ((arrOfPins[local_uint8PinsCounter].PULL_UP_DOWN) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}

			break;

		case PORTB:

			GPIOB -> MODER  &= ~((0b11) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			GPIOB -> MODER  |= ((arrOfPins[local_uint8PinsCounter].MODE) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			if(arrOfPins[local_uint8PinsCounter].MODE == OUTPUT)
			{
				GPIOB -> OTYPER  &= ~(1 << (arrOfPins[local_uint8PinsCounter].PIN_ID));
				GPIOB -> OTYPER  |=  ((arrOfPins[local_uint8PinsCounter].OTYPE) << (arrOfPins[local_uint8PinsCounter].PIN_ID));

				GPIOB -> OSPEEDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOB -> OSPEEDR  |=  ((arrOfPins[local_uint8PinsCounter].OSPEED) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}				
			else
			{
				GPIOB -> PUPDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOB -> PUPDR  |=  ((arrOfPins[local_uint8PinsCounter].PULL_UP_DOWN) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}

			break;

		case PORTC:

			GPIOC -> MODER  &= ~((0b11) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			GPIOC -> MODER  |= ((arrOfPins[local_uint8PinsCounter].MODE) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			if(arrOfPins[local_uint8PinsCounter].MODE == OUTPUT)
			{
				GPIOC -> OTYPER  &= ~(1 << (arrOfPins[local_uint8PinsCounter].PIN_ID));
				GPIOC -> OTYPER  |=  ((arrOfPins[local_uint8PinsCounter].OTYPE) << (arrOfPins[local_uint8PinsCounter].PIN_ID));

				GPIOC -> OSPEEDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOC -> OSPEEDR  |=  ((arrOfPins[local_uint8PinsCounter].OSPEED) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}				
			else
			{
				GPIOC -> PUPDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOC -> PUPDR  |=  ((arrOfPins[local_uint8PinsCounter].PULL_UP_DOWN) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}

			break;
		}
	}
}


void GPIO_voidSetPinValue(PORT_IDs_E  portId,
		PIN_IDs_E   pinId,
		PIN_STATE_E pinState)
{
	if(pinId > 31)
	{
		//DET_ReportError(moduleID, errorId, FunctionId);
	}
	else
	{
		switch(portId)
		{
		case PORTA:  if(pinState == LOW)
		{
			CLR_BIT(GPIOA -> ODR, pinId);
		}
		else if(pinState == HIGH)
		{
			SET_BIT(GPIOA -> ODR, pinId);
		}
		else
		{
			//DET_ReportError();
		}
		break;
		case PORTB: if(pinState == LOW)
		{
			CLR_BIT(GPIOB -> ODR, pinId);
		}
		else if(pinState == HIGH)
		{
			SET_BIT(GPIOB -> ODR, pinId);
		}
		else
		{
			//DET_ReportError();
		}
		break;
		case PORTC: if(pinState == LOW)
		{
			CLR_BIT(GPIOC -> ODR, pinId);
		}
		else if(pinState == HIGH)
		{
			SET_BIT(GPIOC -> ODR, pinId);
		}
		else
		{
			//DET_ReportError();
		}
		break;
		default:
			//DET_ReportError(moduleID, errorId, FunctionId);
			break;
		}
	}
}

void GPIO_VoidSetPortValue(PORT_IDs_E  portId , uint8 pinState )
{


	switch (portId)
	{
	case PORTA: GPIOA -> ODR = pinState; break;
	case PORTB: GPIOB -> ODR= pinState; break;
	case PORTC: GPIOC -> ODR= pinState; break;
	default: //DETReportError();
		;
		break;
	}


}
uint8 GPIO_uint8GetPinValue(PORT_IDs_E  portId,
		PIN_IDs_E   pinId)
{
	uint8 local_uint8PinValue=2;
	if(pinId > 31)
	{
		//DET_ReportError();
	}
	else
	{
		switch(portId)
		{
		case PORTA: local_uint8PinValue = GET_BIT(GPIOA -> IDR, pinId);break;
		case PORTB: local_uint8PinValue = GET_BIT(GPIOB -> IDR, pinId);break;
		case PORTC: local_uint8PinValue = GET_BIT(GPIOC -> IDR, pinId);break;
		default:
			//DET_ReportError();
			break;

		}
	}
	return local_uint8PinValue;
}












