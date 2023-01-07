/*****************************************************************/
/*****************************************************************/
/********************		Author: AhmedMaher		**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 1.00			**************/
/********************		Date: 26-10-2020		**************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATUE.h"

#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"


void USART_VoidInit(void)
{

	USART->CR1.B.UE=1;
	USART->BRR.B.DIV_Mantissa=0x34;
	USART->BRR.B.DIV_Fraction=1;
	USART->CR1.B.OVER8=0;
	USART->CR1.B.M=0;
	USART->CR1.B.WAKE=0;
	USART->CR1.B.PCE=1;
	USART->CR1.B.PS=0;
	USART->CR1.B.TXEIE=1;
	USART->CR1.B.RXNEIE=1;
	USART->CR2.B.STOP=0;

/*
	//USART ENABLE
	USART->CR1.B.UE=1;
	//BOUD RATE 9600
	USART->BRR.B.DIV_Mantissa= ( F_CPU ) / ( 16 *BAUD_RATE ) ;
	USART->BRR.B.DIV_Fraction=(( ( (F_CPU * 100)/(16 *BAUD_RATE ))% 100) * 16) ;
	//over 16 sample
	USART->CR1.B.OVER8=0;
#if WORD_LENGTH== DATA_9BIT_WORD_LENGTH
	//1 Start bit, 9 Data bits, n Stop bit
	USART->CR1.B.M=1;
#elif WORD_LENGTH== DATA_8BIT_WORD_LENGTH
	USART->CR1.B.M=0;
#endif
	//WAKE UP MODE
	USART->CR1.B.WAKE=0;
#if PARITY_EN==ENABLE
	//Parity control enable
	USART->CR1.B.PCE=1;
#elif PARITY_EN==DISABLE
	USART->CR1.B.PCE=0;
#endif
	//EVEN PARITY
#if PARITY == EVEN
	USART->CR1.B.PS=0;
#elif PARITY == ODD
	USART->CR1.B.PS=1;
#endif
	//TXE ENABLE
	USART->CR1.B.TXEIE=1;

	//RXNE interrupt enable
	USART->CR1.B.RXNEIE=1;
		//STOP BITS
	USART->CR2.B.STOP=STOPBITS;

*/
}

uint16 USART_u16ReceiveData(void)
{

	//WAIT UNTILL THERE IS DATA RECEVED
	while((USART->SR.B.RXNE==0));

	USART->SR.B.RXNE=0;
	return USART->DR.B.DR;

}

void USART_u16SendData( uint16 Copy_u16Data)
{
		USART->DR.B.DR=Copy_u16Data;
		while((USART->SR.B.TXE==0));
}
