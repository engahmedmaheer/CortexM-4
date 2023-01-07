/*******************************************************************************/
/*******************************************************************************/
/***************************	Author : AhmedMaher     ************************/
/***************************	Date   : 20/9/2021	    ************************/
/***************************	Layer  : MCAL		    ************************/
/***************************	Version: 1.00		    ************************/
/***************************	brief: DMA FOR STM32F401************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void DMA_VoidInit(uint8 Copy_u8_DMA , uint8 Copy_u8_Channel  ,uint8 Copy_u8_priorety );

void DMA_VoidStart( uint8 Copy_u8_DMA ,uint8 Copy_u8_Channel, uint32* local_u32_SourceAdress , uint32* local_u32_DestinationAddress ,uint16 local_u16_BlockSize );


void DMA_VoidStop( uint8 Copy_u8_DMA ,uint8 Copy_u8_Channel );







#endif
