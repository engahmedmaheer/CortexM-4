
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DET.h"



void RCC_voidInitializeSystemClock(void)
{
	#if CLOCK_SELECTION == HSE
	RCC -> CR   = 0x00010000;
    //SET_BIT(RCC -> CR, HSE_ON);	
	RCC -> CFGR = 0x00000001; 
	
	#elif CLOCK_SELECTION == HSI
	RCC -> CR   = 0x00000081;	
	RCC -> CFGR = 0x00000000;
	
	#elif CLOCK_SELECTION == HSI
	RCC -> CR   = 0x00000081;	
	RCC -> CFGR = 0x00000000;
	
	#elif CLOCK_SELECTION == PLL
	
	#else
		
	#endif
}
void RCC_voidResetPeripheral(uint8 local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case AHB  : SET_BIT(RCC -> AHB1RSTR, local_peripheralId);break;  
			case APB1 : SET_BIT(RCC -> APB1RSTR, local_peripheralId);break;
			case APB2 : SET_BIT(RCC -> APB2RSTR, local_peripheralId);break;
			default: DET_ReportError(DET_RCCModuleID,DET_RCC_voidResetPeripheral,DET_busId);
			break;
		}
	}
	else
	{
		DET_ReportError(DET_RCCModuleID,DET_RCC_voidResetPeripheral,DET_peripheralId);
	}
}
void RCC_voidEnablePeripheralClock(uint8 local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case AHB  : SET_BIT(RCC -> AHB1ENR, local_peripheralId);break;  
			case APB1 : SET_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case APB2 : SET_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default:DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralClock,DET_busId);
			break;
		}
	}
	else
	{
		DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralClock,DET_peripheralId);
	}
}
void RCC_voidDisablePeripheralClock(uint8 local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case AHB  : CLR_BIT(RCC -> AHB1ENR, local_peripheralId);break;  
			case APB1 : CLR_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case APB2 : CLR_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default: DET_ReportError(DET_RCCModuleID,DET_RCC_voidDisablePeripheralClock,DET_busId);
			break;
		}
	}
	else
	{
		DET_ReportError(DET_RCCModuleID,DET_RCC_voidDisablePeripheralClock,DET_peripheralId);
	}
}
