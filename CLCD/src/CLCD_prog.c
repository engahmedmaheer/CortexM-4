#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "DET.h"

static void  SetHalfDataPort(uint8 Copy_u8Data)
{

	GPIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN4,GET_BIT(Copy_u8Data,0));
	GPIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN5,GET_BIT(Copy_u8Data,1));
	GPIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN6,GET_BIT(Copy_u8Data,2));
	GPIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN7,GET_BIT(Copy_u8Data,3));

}

static void SendEnablePulse(void)
{
	//send enable pulse/
	GPIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,HIGH);
	SYSTICK_voidSynchMsecondsDelay(2);
	GPIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,LOW);
}

void CLCD_voidSendCommand(uint8 Copy_u8Command)
{
	/*Set RS pin to low*/
	GPIO_voidSetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, LOW);

	/*Set RW pin to low*/
	GPIO_voidSetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, LOW);
#if CLCD_u8_MODE==EIGHT_BIT
	/*Send command*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);

	/*Send Enable pulse*/
	SendEnablePulse();

#elif CLCD_u8_MODE==FOUR_BIT
	SetHalfDataPort(Copy_u8Command>>4);
	SendEnablePulse();
	SetHalfDataPort(Copy_u8Command);
	SendEnablePulse();
#endif

}
void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*Set RS pin to low*/
	GPIO_voidSetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, HIGH);

	/*Set RW pin to low*/
	GPIO_voidSetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, LOW);

	/*Send command*/
#if CLCD_u8_MODE==EIGHT_BIT
	/*Send command*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);

	/*Send Enable pulse*/
	SendEnablePulse();

#elif CLCD_u8_MODE==FOUR_BIT
	SetHalfDataPort(Copy_u8Data>>4);
	SendEnablePulse();
	SetHalfDataPort(Copy_u8Data);
	SendEnablePulse();
#endif

}

void CLCD_voidInit(void)
{
	/*delay for more than 30ms*/
	SYSTICK_voidSynchMsecondsDelay(2);
#if CLCD_u8_MODE==EIGHT_BIT
	/*Set command:N = 0 2 line,F = 0 font size: 5*7 */
	CLCD_voidSendCommand(0b00111000);
#elif CLCD_u8_MODE==FOUR_BIT
	SetHalfDataPort(0b0010);
	SendEnablePulse();
	SetHalfDataPort(0b0010);
	SendEnablePulse();
	SetHalfDataPort(0b1000);
	SendEnablePulse();
#endif
	/*Set command:D = 1 display enabled, C = 0 cursor off, B = 0 blink cursor off*/
	CLCD_voidSendCommand(0b00001100);
	/*Clear LCD*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(const char* str)
{
	for(uint8 i = 0; str[i] != '\0'; i++)
	{
		CLCD_voidSendData(str[i]);
	}
}

void CLCD_voidSendNumber(sint16 number)
{
	sint16 holder = 0;
	if(number < 0)
	{
		number *=-1;
		CLCD_voidSendData('-');
	}
	while(number != 0)
	{
		holder += number%10;
		number /= 10;
		if(number != 0)
			holder *= 10;
	}
	while(holder != 0)
	{
		CLCD_voidSendData(holder%10 + '0');
		holder /= 10;
	}
}

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8Add;
	if(Copy_u8XPos <= 15 && Copy_u8XPos >= 0 && Copy_u8YPos <= 1 && Copy_u8YPos >= 0)
		Local_u8Add = Copy_u8YPos * 0x40 + Copy_u8XPos;
	else
		return;

	/*Set bit number 7*/
	SET_BIT(Local_u8Add, 7);

	/*Set DDRAM address command*/
	CLCD_voidSendCommand(Local_u8Add);
}





