/*****************************************************************/
/*****************************************************************/
/********************		Author: AhmedMaher		**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 1.00			**************/
/********************		Date: 26-10-2020		**************/
/*****************************************************************/
/*****************************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H




#define F_CPU                    8000000UL
#define BAUD_RATE                (uint32)9600
/*
 * ENABLE
 * DISABLE
 */
#define PARITY_EN					 ENABLE
/*
 * EVEN
 * ODD
 */
#define PARITY						 EVEN
/*
	DATA_8BIT_WORD_LENGTH
	DATA_9BIT_WORD_LENGTH
 */
#define WORD_LENGTH					DATA_8BIT_WORD_LENGTH
/*  ONE_STOP
	HALF_STOP_BIT
	TWO_STOP
 */
#define STOPBITS					ONE_STOP





#endif
