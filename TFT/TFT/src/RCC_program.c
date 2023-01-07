#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DET.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit(void)
{

#if RCC_CLOCK_SYSTEM == RCC_HSE_CRYSTA

	RCC_CR=0x00010000;
  RCC_CFGR=0x00000001;


#elif RCC_CLOCK_SYSTEM == RCC_HSE_RC

  RCC_CR=0x00050000;
  RCC_CFGR=0x00000001;

#elif RCC_CLOCK_SYSTEM== RCC_HSI
 // RCC_CR=0x00000081;
  SET_BIT(RCC_CR,0);
  while(GET_BIT(RCC_CR,1)==0){};
SET_BIT(RCC_CFGR,7);
#elif RCC_CLOCK_SYSTEM == RCC_PLL    //it will produce 84 Mhz

         RCC_CR=0x01000000;
		#if RCC_CLOCK_PLL_INPUT  == RCC_PLL_HSI
		    RCC_PLLCFGR=0x02003494; //0 on bit 22
		#elif RCC_CLOCK_PLL_INPUT  == RCC_PLL_HSE
		    RCC_PLLCFGR=0x0241541A; //1 on bit 22
		#else
		    DET_Report_Error(RCC_MODULE_ID,RCC_IntiaFunction_Id,InvalidClock_Pll);

		#endif

	#else
		    DET_Report_Error(RCC_MODULE_ID,RCC_IntiaFunction_Id,InvalidClock);

	#endif


}



void RCC_voidEnablePeripheralClock(uint8 busid, uint8 prephirelid)
{
	if(busid==AHB1_EN)
	{
		switch(prephirelid)
		{
			case GPIO_PORTA:SET_BIT(RCC_AHB1ENR,GPIO_PORTA_BIT);break;
			case GPIO_PORTB:SET_BIT(RCC_AHB1ENR,GPIO_PORTB_BIT);break;
			case GPIO_PORTC:SET_BIT(RCC_AHB1ENR,GPIO_PORTC_BIT);break;
			case GPIO_PORTD:SET_BIT(RCC_AHB1ENR,GPIO_PORTD_BIT);break;
			case GPIO_PORTE:SET_BIT(RCC_AHB1ENR,GPIO_PORTE_BIT);break;
			case GPIO_PORTH:SET_BIT(RCC_AHB1ENR,GPIO_PORTH_BIT);break;
			case CRC:SET_BIT(RCC_AHB1ENR,CRC_BIT);break;
			case DMA_1:SET_BIT(RCC_AHB1ENR,DMA_1_BIT);break;
			case DMA_2:SET_BIT(RCC_AHB1ENR,DMA_2_BIT);break;
			default: DET_Report_Error(RCC_MODULE_ID,RCC_EnablePeripheral_Function_ID,InvalidPeripheralId);
						break;
			
		}
	}
	else if(busid==APB1_EN)
	{
		switch(prephirelid)
		{
 case TIM_2 : SET_BIT(RCC_APB1ENR,TIM_2_BIT);break;
 case TIM_3 :SET_BIT(RCC_APB1ENR,TIM_3_BIT);break;
 case TIM_4 :SET_BIT(RCC_APB1ENR,TIM_4_BIT);break;
 case TIM_5:SET_BIT(RCC_APB1ENR,TIM_5_BIT);break;
 case WWDG_EN:SET_BIT(RCC_APB1ENR,WWDG_EN_BIT);break;
 case SPI_2 :SET_BIT(RCC_APB1ENR,SPI_2_BIT);break;
 case SPI_3 :SET_BIT(RCC_APB1ENR,SPI_3_BIT);break ;

 case USART_2:      SET_BIT(RCC_APB1ENR,USART_2_BIT);break;  
 case I2C_1 :       SET_BIT(RCC_APB1ENR,I2C_1_BIT);break;  
 case I2C_2 :      SET_BIT(RCC_APB1ENR,I2C_2_BIT);break;  
 case I2C_3 :       SET_BIT(RCC_APB1ENR,I2C_3_BIT);break;  
 case PWR_EN:      SET_BIT(RCC_APB1ENR,PWR_EN_BIT);break;  
	default: DET_Report_Error(RCC_MODULE_ID,RCC_EnablePeripheral_Function_ID,InvalidPeripheralId);
				break;
	}
	}
	
		else if(busid==APB2_EN)
	{
		switch(prephirelid)
		{
 case TIM_1 : SET_BIT(RCC_APB2ENR,TIM_1_BIT);break;   
 case USART_1  :  SET_BIT(RCC_APB2ENR,USART_1_BIT);break;     
 case USART_6 :   SET_BIT(RCC_APB2ENR,USART_6_BIT);break;     
 case ADC_1:    SET_BIT(RCC_APB2ENR,ADC_1_BIT);break;     
 case  SDIO:    SET_BIT(RCC_APB2ENR,SDIO_BIT);break;   
 case  SPI_1 :       SET_BIT(RCC_APB2ENR,SPI_1_BIT);break;  
 case SPI_4 :       SET_BIT(RCC_APB2ENR,SPI_4_BIT);break;  
 case SYSCFG_EN:      SET_BIT(RCC_APB2ENR,SYSCFG_EN_BIT);break;  
 case TIM_9  :       SET_BIT(RCC_APB2ENR,TIM_9_BIT);break;  
 case TIM_10 :      SET_BIT(RCC_APB2ENR,TIM_10_BIT);break;  
 case TIM_11:       SET_BIT(RCC_APB2ENR,TIM_11_BIT);break;  
	default:DET_Report_Error(RCC_MODULE_ID,RCC_EnablePeripheral_Function_ID,InvalidPeripheralId);
				break; // add det
	}
}
else
{
	DET_Report_Error(RCC_MODULE_ID,RCC_EnablePeripheral_Function_ID,InvalidBusId);
}
}
// DISABLE********************************************************************************************************
void RCC_voidDisablePeripheralClock(uint8 busid, uint8 prephirelid)
{
		if(busid==AHB1_EN)
	{
		switch(prephirelid)
		{
			case GPIO_PORTA:CLR_BIT(RCC_AHB1ENR,GPIO_PORTA_BIT);break;
			case GPIO_PORTB:CLR_BIT(RCC_AHB1ENR,GPIO_PORTB_BIT);break;
			case GPIO_PORTC:CLR_BIT(RCC_AHB1ENR,GPIO_PORTC_BIT);break;
			case GPIO_PORTD:CLR_BIT(RCC_AHB1ENR,GPIO_PORTD_BIT);break;
			case GPIO_PORTE:CLR_BIT(RCC_AHB1ENR,GPIO_PORTE_BIT);break;
			case GPIO_PORTH:CLR_BIT(RCC_AHB1ENR,GPIO_PORTH_BIT);break;
			case CRC:CLR_BIT(RCC_AHB1ENR,CRC_BIT);break;
			case DMA_1:CLR_BIT(RCC_AHB1ENR,DMA_1_BIT);break;
			case DMA_2:CLR_BIT(RCC_AHB1ENR,DMA_2_BIT);break;
			default:DET_Report_Error(RCC_MODULE_ID,RCC_DisablePeripheral_Function_ID,InvalidPeripheralId);
						break;
		}
	}
	else if(busid==APB1_EN)
	{
		switch(prephirelid)
		{
 case TIM_2 : CLR_BIT(RCC_APB1ENR,TIM_2_BIT);break;   
 case TIM_3 :  CLR_BIT(RCC_APB1ENR,TIM_3_BIT);break;     
 case TIM_4 :   CLR_BIT(RCC_APB1ENR,TIM_4_BIT);break;     
 case  TIM_5:    CLR_BIT(RCC_APB1ENR,TIM_5_BIT);break;     
 case  WWDG_EN:    CLR_BIT(RCC_APB1ENR,WWDG_EN_BIT);break;   
 case  SPI_2 :       CLR_BIT(RCC_APB1ENR,SPI_2_BIT);break;  
 case SPI_3  :  CLR_BIT(RCC_APB1ENR,SPI_3_BIT);break;
 case USART_2:      CLR_BIT(RCC_APB1ENR,USART_2_BIT);break;  
 case I2C_1 :       CLR_BIT(RCC_APB1ENR,I2C_1_BIT);break;  
 case I2C_2 :      CLR_BIT(RCC_APB1ENR,I2C_2_BIT);break;  
 case I2C_3 :       CLR_BIT(RCC_APB1ENR,I2C_3_BIT);break;  
 case PWR_EN:      CLR_BIT(RCC_APB1ENR,PWR_EN_BIT);break;  
	default:DET_Report_Error(RCC_MODULE_ID,RCC_DisablePeripheral_Function_ID,InvalidPeripheralId);

				break; // add det
	}
	}
		else if(busid==APB2_EN)
	{
		switch(prephirelid)
		{
 case TIM_1 : CLR_BIT(RCC_APB2ENR,TIM_1_BIT);break;   
 case USART_1:CLR_BIT(RCC_APB2ENR,USART_1_BIT);break;
 case USART_6: CLR_BIT(RCC_APB2ENR,USART_6_BIT);break;
 case ADC_1:  CLR_BIT(RCC_APB2ENR,ADC_1_BIT);break;
 case SDIO: CLR_BIT(RCC_APB2ENR,SDIO_BIT);break;
 case SPI_1: CLR_BIT(RCC_APB2ENR,SPI_1_BIT);break;
 case SPI_4:       CLR_BIT(RCC_APB2ENR,SPI_4_BIT);break;
 case SYSCFG_EN:      CLR_BIT(RCC_APB2ENR,SYSCFG_EN_BIT);break;  
 case TIM_9  :       CLR_BIT(RCC_APB2ENR,TIM_9_BIT);break;  
 case TIM_10 :      CLR_BIT(RCC_APB2ENR,TIM_10_BIT);break;  
 case TIM_11:       CLR_BIT(RCC_APB2ENR,TIM_11_BIT);break;  
	default:DET_Report_Error(RCC_MODULE_ID,RCC_DisablePeripheral_Function_ID,InvalidPeripheralId);

				break; // add det
		}
	}
		else
		{
			DET_Report_Error(RCC_MODULE_ID,RCC_DisablePeripheral_Function_ID,InvalidBusId);
		}
}
