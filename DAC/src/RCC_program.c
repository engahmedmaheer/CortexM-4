#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitializeSystemClock(void)
{
	#if CLOCK_SELECTION == HSE
	RCC -> CR   = 0x00010000;
    //SET_BIT(RCC -> CR, HSE_ON);	
	RCC -> CFGR = 0x00000001; 
	
	#elif CLOCK_SELECTION == HSI
	SET_BIT(RCC -> CR, 0);
	while(GET_BIT(RCC -> CR, 1) == 0);
	SET_BIT(RCC -> CFGR, 7);  // PRES/2
	
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
			case RCC_AHB  : SET_BIT(RCC -> AHB1RSTR, local_peripheralId);break;
			case RCC_APB1 : SET_BIT(RCC -> APB1RSTR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC -> APB2RSTR, local_peripheralId);break;
			default: //DET
			break;
		}
	}
	else
	{
		//DET_reportError(moduleID, errorId, functionId);
	}
}
void RCC_voidEnablePeripheralClock(uint8 local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : SET_BIT(RCC -> AHB1ENR, local_peripheralId);break;
			case RCC_APB1 : SET_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default: //DET
			break;
		}
	}
	else
	{
		//DET_reportError(moduleID, errorId, functionId);
	}
}
void RCC_voidDisablePeripheralClock(uint8 local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : CLR_BIT(RCC -> AHB1ENR, local_peripheralId);break;
			case RCC_APB1 : CLR_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case RCC_APB2 : CLR_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default: //DET
			break;
		}
	}
	else
	{
		//DET_reportError(moduleID, errorId, functionId);
	}
}
