#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include "ERROR_STATUS.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/*
   PORT

     PIN
      MODE
      TYPE; //OPEN
      SPEED
      PULL_UP_DOWN*/  


void GPIO_mainFunction(void)
{uint8 itr;
for(itr=0;itr<pin_number;itr++)
{
	switch(configPin[itr].PORT)
	{
	case PORTA:
		if(configPin[itr].MODE==AF)
			{
			GPIOA -> MODER &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR THE LOCATION OF PIN
					GPIOA -> MODER |=  ((configPin[itr].MODE)<<((configPin[itr].PIN) * 2));//


				if((configPin[itr].PIN)/8==0)
				{
					GPIOA -> AFRL |=((configPin[itr].AF_mode)<<(4*configPin[itr].PIN)); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);

				}
			else if((configPin[itr].PIN)/8==1)
			{

				GPIOA -> AFRH |=((configPin[itr].AF_mode)<<(4*((configPin[itr].PIN)%8))); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);
			}

			else
			{};

			}

		else{
		GPIOA -> MODER &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR THE LOCATION OF PIN
		GPIOA -> MODER |=  ((configPin[itr].MODE)<<((configPin[itr].PIN) * 2));// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
		if(configPin[itr].TYPE!=NOT_USED)
		{
			CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);
			GPIOA -> OTYPER |=  ((configPin[itr].TYPE)<<((configPin[itr].PIN))); // this determine open_drain or push pull
			GPIOA -> OSPEEDR &= ~((0b11) <<((configPin[itr].PIN))); //CLEAR THE LOCATION
			GPIOA -> OSPEEDR |=  ((configPin[itr].SPEED)<<((configPin[itr].PIN) * 2)); // DETERMINE THE SPEED HIGH OR LOW OR MIDUM OR VERY HIGH
			//GPIOA -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
			//  GPIOA -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN

			//***************************************************
		}
		else if(configPin[itr].PULL_UP_DOWN!=NOT_USED)
		{
			GPIOA -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
			GPIOA -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
		}
		else{};
		}
		break;
		//********************************************** PORTB
	case PORTB:
		if(configPin[itr].MODE==AF)
				{
				GPIOB -> MODER &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR THE LOCATION OF PIN
						GPIOB -> MODER |=  ((configPin[itr].MODE)<<((configPin[itr].PIN) * 2));//


					if((configPin[itr].PIN)/7==0)
					{
				GPIOB -> AFRL|= ((configPin[itr].AF_mode)<<(4*configPin[itr].PIN)); // CONFIG AF0 OR AF1

					}
				else if((configPin[itr].PIN)/7==1)
				{

					GPIOB -> AFRH |=((configPin[itr].AF_mode)<<(4*configPin[itr].PIN)); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);
				}

				else
				{};

				}

		else
		{
		GPIOB -> MODER &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR THE LOCATION OF PIN
		GPIOB -> MODER |=  ((configPin[itr].MODE)<<((configPin[itr].PIN) * 2));// SHIFT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
		if(configPin[itr].TYPE!=NOT_USED)
		{
			CLR_BIT(GPIOB -> OTYPER,configPin[itr].PIN);
			GPIOB -> OTYPER |=  ((configPin[itr].TYPE)<<((configPin[itr].PIN)));    // this determine opendrain or push pull
			GPIOB -> OSPEEDR &= ~((0b11) <<((configPin[itr].PIN) * 2));         //CLEAR THE LOCATION
			GPIOB -> OSPEEDR |=  ((configPin[itr].SPEED)<<((configPin[itr].PIN) * 2)); // DETERMINE THE SPEED HIGH OR LOW OR MIDUM OR VERY HIGH
			//GPIOB -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
			//    GPIOB -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
		}
		else if(configPin[itr].PULL_UP_DOWN!=NOT_USED)
		{
			GPIOB -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
			GPIOB -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
		}
		else{};
		}
		break;
		//**************************************************************************PORTC
	case PORTC:
		GPIOC -> MODER &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR THE LOCATION OF PIN
		GPIOC -> MODER |=  ((configPin[itr].MODE)<<((configPin[itr].PIN) * 2));// SHIFT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
		if(configPin[itr].TYPE!=NOT_USED)
		{
			CLR_BIT(GPIOC -> OTYPER,configPin[itr].PIN);
			GPIOC -> OTYPER |=  ((configPin[itr].TYPE)<<((configPin[itr].PIN))); // this determine opendrain or push pull
			GPIOC -> OSPEEDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); //CLEAR THE LOCATION
			GPIOC -> OSPEEDR |=  ((configPin[itr].SPEED)<<((configPin[itr].PIN) * 2)); // DETERMINE THE SPEED HIGH OR LOW OR MIDUM OR VERY HIGH
			//GPIOC -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
			// GPIOC -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
		}
		else if(configPin[itr].PULL_UP_DOWN!=NOT_USED)
		{
			GPIOC -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
			GPIOC -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN or floating
		}
		else{};
		break;
	}
}
}

void GPIO_SET_PIN_VALUE_BSRR(uint8 port, uint8 pin ,uint8 value)
{
	if(pin<=15)
	{
		switch(port)
		{
		//*******************************************************************************
		case PORTA:
			if(value==LOW)
			{
				SET_BIT(GPIOA ->BSRR,(pin+16));
			}
			else if(value==HIGH)
			{
				SET_BIT(GPIOA ->BSRR,pin);
			}
			else{/*use det*/};
			break;
			//********************************************************************************
		case PORTB:
			if(value==LOW)
			{
				SET_BIT(GPIOB ->BSRR,(pin+16));
			}
			else if(value==HIGH)
			{
				SET_BIT(GPIOB ->BSRR,pin);
			}
			else{/*use det*/};
			break;
			//********************************************************************************
		case PORTC:
			if(value==LOW)
			{
				SET_BIT(GPIOC ->BSRR,(pin+16));
			}
			else if(value==HIGH)
			{
				SET_BIT(GPIOC ->BSRR,pin);
			}
			break;
		}
	}
	else{/*use det*/};

	//********************************************************************************
}


uint8 GPIO_GET_PIN_VALUE(uint8 port, uint8 pin)
{ uint8 pin_value=6;
if(pin<=15)
{
	switch(port)
	{
	case PORTA :
		pin_value=GET_BIT(GPIOA->IDR,pin);
		break;
	case PORTB :
		pin_value=GET_BIT(GPIOB->IDR,pin);
		break;
	case PORTC :
		pin_value=GET_BIT(GPIOC->IDR,pin);
		break;
	}
}
else{/*use det*/};
return pin_value;
}
void GPIO_SET_PIN_VALUE_ODR(uint8 port, uint8 pin ,uint8 value)
{
	if(pin<=15)
	{

		switch (port)
		{
		case PORTA:
			CLR_BIT(GPIOA->ODR,pin);
			GPIOA->ODR |=  ((value)<<(pin));
			break;
		case PORTB:
			CLR_BIT(GPIOB->ODR,pin);
			GPIOB->ODR |=  ((value)<<(pin));
			break;
		case PORTC:
			CLR_BIT(GPIOC->ODR,pin);
			GPIOC->ODR |=  ((value)<<(pin));
			break;
		}
	}
	else {/*use det*/};
}
void GPIO_SET_PORT_VALUE_ODR(uint8 port, uint8 data)
{
	switch(port)
	{
	case PORTA: GPIOA->ODR=data;break;
	case PORTB: GPIOB->ODR=data;break;




	}
}
