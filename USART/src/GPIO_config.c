#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/*Configration
   PORTID*****PINID*******
   PORTA      PIN0--14
   PORTB      PIN0--14
   PORTC	  SINKING
 ******MODE**********
 - OUTPUT   -INPUT
 ******OTYPE*********
    PUSH_PULL
	OPEN_DRAIN
 *****OSPEED**********
    LOW_SPEED
    MEDIUM_SPEED
    HIGH_SPEED
    VERY_HIGH_SPEED
 *****PULL_UP_DOWN*****
    FLOATING
	PULL_UP
	PULL_DOWN
 */

pinInfo arrOfPins[NUMBER_OF_USED_PINS]=
{

		{
				.PORT_ID      = PORTA,
				.PIN_ID       = PIN0,
				.MODE         = OUTPUT,
				.OTYPE        = PUSH_PULL,
				.OSPEED       = LOW_SPEED,
				.PULL_UP_DOWN = PULL_DOWN,
		},


		{
				.PORT_ID      = PORTA,
				.PIN_ID       = PIN9,
				.MODE         = AF,
				.OTYPE        = NOT_USED,
				.OSPEED       = NOT_USED,
				.PULL_UP_DOWN = NOT_USED,
		},
		{
				.PORT_ID      = PORTA,
				.PIN_ID       = PIN10,
				.MODE         = AF,
				.OTYPE        = NOT_USED,
				.OSPEED       = NOT_USED,
				.PULL_UP_DOWN = NOT_USED,
		}


};
