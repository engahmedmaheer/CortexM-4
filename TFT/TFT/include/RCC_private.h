/*************************************************************************
author: youssef tolba                                                    *
date : 22 / jul/ 2022                                                    *
version: v01                                                             *                                                               
*************************************************************************/
#ifndef RCC_private_H
#define RCC_private_H

#define RCC_BASE_ADDRESS 0x40023800
// THIS IS BASE ADRESS  0x40023800

#define RCC_CR          *((uint32*)(RCC_BASE_ADDRESS+0x00))
#define RCC_PLLCFGR     *((uint32*)(RCC_BASE_ADDRESS+0x04))
#define RCC_CFGR        *((uint32*)(RCC_BASE_ADDRESS+0x08))
#define RCC_CIR         *((uint32*)(RCC_BASE_ADDRESS+0x0c))
#define RCC_AHB1RSTR    *((uint32*)(RCC_BASE_ADDRESS+0x10))
#define RCC_AHB2RSTR    *((uint32*)(RCC_BASE_ADDRESS+0x14))
#define RCC_APB1RSTR    *((uint32*)(RCC_BASE_ADDRESS+0x20))
#define RCC_APB2RSTR    *((uint32*)(RCC_BASE_ADDRESS+0x24))
#define RCC_AHB1ENR     *((uint32*)(RCC_BASE_ADDRESS+0x30))
#define RCC_AHB2ENR     *((uint32*)(RCC_BASE_ADDRESS+0x34))
#define RCC_APB1ENR     *((uint32*)(RCC_BASE_ADDRESS+0x40))
#define RCC_APB2ENR     *((uint32*)(RCC_BASE_ADDRESS+0x44))       
#define RCC_AHB1LPENR   *((uint32*)(RCC_BASE_ADDRESS+0x50))  
#define RCC_AHB2LPENR   *((uint32*)(RCC_BASE_ADDRESS+0x54))  
#define RCC_APB1LPENR   *((uint32*)(RCC_BASE_ADDRESS+0x60))  
#define RCC_APB2LPENR   *((uint32*)(RCC_BASE_ADDRESS+0x64))  
#define RCC_BDCR        *((uint32*)(RCC_BASE_ADDRESS+0x70))  
#define RCC_CSR         *((uint32*)(RCC_BASE_ADDRESS+0x74))  
#define RCC_SSCGR       *((uint32*)(RCC_BASE_ADDRESS+0x80))
#define RCC_PLLI2SCFGR  *((uint32*)(RCC_BASE_ADDRESS+0x84))
#define RCC_DCKCFGR     *((uint32*)(RCC_BASE_ADDRESS+0x8c))

//******************AHB1_PREPH
#define GPIO_PORTA_BIT  0
#define GPIO_PORTB_BIT  1
#define GPIO_PORTC_BIT  2
#define GPIO_PORTD_BIT  3
#define GPIO_PORTE_BIT  4
#define GPIO_PORTH_BIT  7
#define CRC_BIT         12
#define DMA_1_BIT       21 
#define DMA_2_BIT       22
//** ABB2_PREPH****************************************
#define TIM_2_BIT    0
#define TIM_3_BIT    1
#define TIM_4_BIT    2
#define TIM_5_BIT    3
#define WWDG_EN_BIT  11
#define SPI_2_BIT    14
#define SPI_3_BIT   15
#define USART_2_BIT   17
#define I2C_1_BIT     21
#define I2C_2_BIT	 22
#define I2C_3_BIT	 23
#define PWR_EN_BIT 		28   
//*******************************************
#define TIM_1_BIT     0
#define USART_1_BIT    4
#define USART_6_BIT    5
#define ADC_1_BIT      8
#define SDIO_BIT       11
#define SPI_1_BIT      12
#define SPI_4_BIT      13 
#define SYSCFG_EN_BIT  14
#define TIM_9_BIT      16
#define TIM_10_BIT     17
#define TIM_11_BIT     18





// struct method
/*
typedef struct{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
}RCC_TYPE;
#define RCC ((RCC_TYPE*)RCC_BASE_ADDRESS)*/
#endif
