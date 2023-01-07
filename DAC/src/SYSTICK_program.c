#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

void SYSTICK_voidInit(void)
{
	SYSTICK -> CTRL.B.CLKSOURCE = SYSTICK_CLOCK_SOURCE;
}

void SYSTICK_voidSynchSecondsDelay(uint32 local_uint32Seconds)
{
	uint8 local_uint8Counter=0;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;
	
	for(local_uint8Counter=0; local_uint8Counter<local_uint32Seconds; local_uint8Counter++)
	{
		SYSTICK -> LOAD.R = 3125000;
		SYSTICK -> CTRL.B.ENABLE = 1;
		while(SYSTICK -> CTRL.B.COUNTFLAG == 0);
		SYSTICK -> CTRL.B.COUNTFLAG = 0;
	}
	
}

void SYSTICK_voidSynchMsecondsDelay(uint32 local_uint32MilliSeconds)
{
	uint8 local_uint8Counter=0;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;

	for(local_uint8Counter=0; local_uint8Counter<local_uint32MilliSeconds; local_uint8Counter++)
	{
		SYSTICK -> LOAD.R = 3125;
		SYSTICK -> CTRL.B.ENABLE = 1;
		while(SYSTICK -> CTRL.B.COUNTFLAG == 0);
		SYSTICK -> CTRL.B.COUNTFLAG = 0;
	}

}

void SYSTICK_voidSynchUsecondsDelay(uint32 local_uint32MicroSeconds)
{
	uint32 local_uint32Counter=0;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;
	

		SYSTICK -> LOAD.R = local_uint32MicroSeconds;
		SYSTICK -> CTRL.B.ENABLE = 1;
		while(SYSTICK -> CTRL.B.COUNTFLAG == 0);
		SYSTICK -> CTRL.B.COUNTFLAG = 0;
	

}

void SYSTICK_voidAsynchSecondsDelay(uint32 local_uint32Seconds, void (*localCallBackPtr) (void))
{
	GlobalSystickCallBack = localCallBackPtr;
	globalSeconds = local_uint32Seconds;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;
	
	SYSTICK -> LOAD.R = 3125000;
	SYSTICK -> CTRL.B.TICKINT = 1;
	SYSTICK -> CTRL.B.ENABLE = 1;
	
}

void SYSTICK_voidAsynchMsecondsDelay(uint32 local_uint32MilliSeconds, void (*localCallBackPtr) (void))
{
	GlobalSystickCallBack = localCallBackPtr;
	globalSeconds = local_uint32MilliSeconds;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;

	SYSTICK -> LOAD.R = 3125;
	SYSTICK -> CTRL.B.TICKINT = 1;
	SYSTICK -> CTRL.B.ENABLE = 1;
}

void SYSTICK_voidAsynchUsecondsDelay(uint32 local_uint32MicroSeconds, void (*localCallBackPtr) (void))
{
	GlobalSystickCallBack = localCallBackPtr;
	globalSeconds = local_uint32MicroSeconds;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;

	SYSTICK -> LOAD.R = 3;
	SYSTICK -> CTRL.B.TICKINT = 1;
	SYSTICK -> CTRL.B.ENABLE = 1;

}

void SYSTICK_voidAsynchSingleSecondsDelay(uint32 local_uint32Seconds, void (*localCallBackPtr) (void))
{
	globalSingleCallIndicator = 1;
	GlobalSystickCallBack = localCallBackPtr;
	globalSeconds = local_uint32Seconds;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;
	
	SYSTICK -> LOAD.R = 1000000;
	SYSTICK -> CTRL.B.TICKINT = 1;
	SYSTICK -> CTRL.B.ENABLE = 1;
	
}

void SYSTICK_voidAsynchSingleMsecondsDelay(uint32 local_uint32MilliSeconds, void (*localCallBackPtr) (void))
{
	globalSingleCallIndicator = 1;
	GlobalSystickCallBack = localCallBackPtr;
	globalSeconds = local_uint32MilliSeconds;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;

	SYSTICK -> LOAD.R = 3125;
	SYSTICK -> CTRL.B.TICKINT = 1;
	SYSTICK -> CTRL.B.ENABLE = 1;

}

void SYSTICK_voidAsynchSingleUsecondsDelay(uint32 local_uint32MicroSeconds, void (*localCallBackPtr) (void))
{
	globalSingleCallIndicator = 1;
	GlobalSystickCallBack = localCallBackPtr;
	globalSeconds = local_uint32MicroSeconds;
	/* OPTIONAL for safety */
	SYSTICK -> CTRL.R = 0;
	SYSTICK -> VALUE.R =0;

	SYSTICK -> LOAD.R = 3;
	SYSTICK -> CTRL.B.TICKINT = 1;
	SYSTICK -> CTRL.B.ENABLE = 1;

}

uint32 SYSTICK_uint32GetElapsedTime (void)
{
	return ((SYSTICK -> LOAD.R) - (SYSTICK -> VALUE.R));
}
uint32 SYSTICK_uint32GetRemainingTime (void)
{
	return (SYSTICK -> VALUE.R);
}

void SYSTICK_voidStop(void)
{
	SYSTICK -> CTRL.R = 0;
}

void SysTick_Handler ()
{
	static uint32 counter=1;
	
	if(counter == globalSeconds)
	{
		GlobalSystickCallBack();
		counter=1;
		if(globalSingleCallIndicator == 1)
		{
			SYSTICK -> CTRL.R  = 0;
			SYSTICK -> LOAD.R  = 0;
			SYSTICK -> VALUE.R = 0;
		}
	}
	else
	{
		counter++;
	}
	
}
