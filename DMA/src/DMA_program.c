
/*****************INCLUDE LIBRARY******************************************************/
#include "STD_TYPES.h"


/***************INCLUDE FILE*************************************************************/
#include "DMA_config.h"
#include "DMA_interface.h"
#include "DMA_private.h"



void DMA_VoidInit( uint8 Copy_u8_DMA,  uint8 Copy_u8_Channel , uint8  Copy_u8_priorety)

{
	if ( Copy_u8_Channel <  MAX_CHANNEL )
	{
		switch (Copy_u8_DMA )
		{
		case  DMA_ONE :
						/*Enable DMA*/
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.EN    =DISABLE ;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.CHSEL =Copy_u8_Channel;
						/*SET PRIORETY FOR EACH */
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.PL    = Copy_u8_priorety ;
						/*INIT*/
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.PINCOS= Peripheralincrement ;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.MSIZE = BLOCK_SIZE;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.PSIZE = BLOCK_SIZE;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.MINC  = MEMEORY_INCREMENT;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.PINC  = PERIPHERAL_INCREMENT;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.CIRC  = CIRCULAR_MODE ;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.DIR   = DMA1_MODE     ;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.PFCTRL= PERIPHERAL_FLOW_MODE ;
						/*ENABLE INTERRUPT*/
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.TCIE=1;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.HTIE=1;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.TEIE=1;
						DMA1 -> DMA_STREAM[Copy_u8_Channel].CR.B.DMEIE=1;





			   break ;
		case  DMA_TWO :
								/*Enable DMA*/
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.EN    = DISABLE ;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.CHSEL = Copy_u8_Channel;
			            /*SET PRIORETY FOR EACH */
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.PL    = Copy_u8_priorety ;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.PINCOS= Peripheralincrement ;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.MSIZE = BLOCK_SIZE;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.PSIZE = BLOCK_SIZE;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.MINC  = MEMEORY_INCREMENT;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.PINC  = PERIPHERAL_INCREMENT;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.CIRC  = CIRCULAR_MODE ;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.DIR   = DMA2_MODE     ;
			            DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.PFCTRL= PERIPHERAL_FLOW_MODE ;
						/*ENABLE INTERRUPT*/
						DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.TCIE=1;
						DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.HTIE=1;
						DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.TEIE=1;
						DMA2 -> DMA_STREAM[Copy_u8_Channel].CR.B.DMEIE=1;


			            break ;
		default:   //DET_RepoerError
			break;
		}

	}


	else
	{
		//DET_ReportError()
	}


}
void DMA_VoidStart( uint8 Copy_u8_DMA ,uint8 Copy_u8_Channel,  uint32* local_u32_SourceAdress ,  uint32* local_u32_DestinationAddress ,uint16 local_u16_BlockSize )
{

	switch (Copy_u8_DMA)
		{

		case DMA_ONE:
				DMA1-> DMA_STREAM[Copy_u8_Channel].PAR.R            	  =  (*local_u32_SourceAdress)       ;
				DMA1-> DMA_STREAM[Copy_u8_Channel].M0AR.R				  =  (*local_u32_DestinationAddress) ;
				DMA1-> DMA_STREAM[Copy_u8_Channel].NDTR.R 				  =  local_u16_BlockSize             ;
				DMA1-> DMA_STREAM[Copy_u8_Channel].CR.B.EN				  =	 ENABLE                          ;
				break;
		case DMA_TWO:
			    DMA2-> DMA_STREAM[Copy_u8_Channel].PAR.R            	  =  (*local_u32_SourceAdress)       ;
				DMA2-> DMA_STREAM[Copy_u8_Channel].M0AR.R				  =  (*local_u32_DestinationAddress) ;
				DMA2-> DMA_STREAM[Copy_u8_Channel].NDTR.R 				  =  local_u16_BlockSize             ;
				DMA2-> DMA_STREAM[Copy_u8_Channel].CR.B.EN				  =	 ENABLE                          ;

				break;

		default:  			//DET_ReportError
		break;
		}


}


void DMA_VoidStop( uint8 Copy_u8_DMA ,uint8 Copy_u8_Channel )
{
	switch (Copy_u8_DMA)
	{
	case DMA_ONE: DMA1-> DMA_STREAM[Copy_u8_Channel].CR.B.EN	= DISABLE;	break;
	case DMA_TWO: DMA2-> DMA_STREAM[Copy_u8_Channel].CR.B.EN	= DISABLE;	break;
	default: //DET_ReportError
		break;

	}
}








