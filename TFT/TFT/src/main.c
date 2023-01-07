/*
 * main.c

 *
 *  Created on: Sep 28, 2022
 *      Author: youssef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "IMG.h"

int main(void)
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(AHB1_EN,PORTA);
	RCC_voidEnablePeripheralClock(APB2_EN,SPI_1);

	GPIO_mainFunction();
	SYSTICK_voidInit();

	SPI_Master_Init();
	TFT_Intia();
	TFT_DISPLAY_IMG(img);

	while(1)
	{


	}
	return 0;
}
