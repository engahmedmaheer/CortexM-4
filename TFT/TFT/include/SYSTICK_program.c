#inlcludes

void (*SYSTICK_GlobalcallbackPtr) (void);
volatile uint8 GlobalDelaySeconds;
uint8 GlobalSingleCallFlag=0;

void SYSTICK_voidInit (void)
{
	SYSTICK -> CTRL.B.ClockSrc = SYSTICK_CLOCK_SOURCE;
}

void SYSTICK_voidSyncSecDelay(uint8 local_uint8Seconds)
{
	uint8 local_uint8SecondsCounter;
	// disable systick 
	SYSTICK -> CTRL.B.Enable = 0;
	 
	// optional: clear value register
	SYSTICK -> VALUE.R = 0;
	
	for(local_uint8SecondsCounter = 0; local_uint8SecondsCounter < local_uint8Seconds; local_uint8SecondsCounter++)
	{
		SYSTICK -> LOAD.R = 3125000;   // not valid if clock selection was AHB and not 25MHz
		SYSTICK -> CTRL.B.Enable = 1;
		while(SYSTICK -> CTRL.B.CountFlag == 0);
		SYSTICK -> CTRL.B.CountFlag = 0;
	}
}

void SYSTICK_voidAsyncPeriodicSecDelay(uint8 local_uint8Seconds, void (*callbackPtr) (void))
{
	GlobalDelaySeconds = local_uint8Seconds;
	// disable systick 
	SYSTICK -> CTRL.B.Enable = 0;
	 
	// optional: clear value register
	SYSTICK -> VALUE.R = 0;
	
	SYSTICK -> LOAD.R = 3125000;   // not valid if clock selection was AHB and not 25MHz
	SYSTICK -> CTRL.B.TickInt = 1;
	SYSTICK -> CTRL.B.Enable = 1;
	
	SYSTICK_GlobalcallbackPtr = callbackPtr;
}

void SYSTICK_voidAsyncSingleCallSecDelay(uint8 local_uint8Seconds, int (*callbackPtr) (void))
{
	GlobalSingleCallFlag = 1;
	GlobalDelaySeconds = local_uint8Seconds;
	// disable systick 
	SYSTICK -> CTRL.B.Enable = 0;
	 
	// optional: clear value register
	SYSTICK -> VALUE.R = 0;
	
	SYSTICK -> LOAD.R = 3125000;   // not valid if clock selection was AHB and not 25MHz
	SYSTICK -> CTRL.B.TickInt = 1;
	SYSTICK -> CTRL.B.Enable = 1;
	
	SYSTICK_GlobalcallbackPtr = callbackPtr;
}

void SYSTICK_voidAsyncSingleCallUsecDelay(uint8 local_uint8Seconds, int (*callbackPtr) (void))
{
	GlobalSingleCallFlag = 1;
	GlobalDelaySeconds = local_uint8Seconds;
	// disable systick 
	SYSTICK -> CTRL.B.Enable = 0;
	 
	// optional: clear value register
	SYSTICK -> VALUE.R = 0;
	
	SYSTICK -> LOAD.R = 3;   // not valid if clock selection was AHB and not 25MHz
	SYSTICK -> CTRL.B.TickInt = 1;
	SYSTICK -> CTRL.B.Enable = 1;
	
	SYSTICK_GlobalcallbackPtr = callbackPtr;
}

uint32 SYSTICK_voidGetElapsedTime (void)
{
	return ( (SYSTICK -> LOAD.R) - (SYSTICK -> VALUE.R) );
}

uint32 SYSTICK_voidGetRemainingTime (void)
{
	return (SYSTICK -> VALUE.R);
}

void SYSTICK_voidStop (void)
{
	SYSTICK -> CTRL.B.Enable = 0;
	
	// optional: clear value register
	SYSTICK -> VALUE.R = 0;
	SYSTICK -> LOAD .R = 0;
}

void SysTick_Handler (void)
{
	static uint8 DelayCounter=1;
	if(DelayCounter == GlobalDelaySeconds)
	{
		SYSTICK_GlobalcallbackPtr();
		if(GlobalSingleCallFlag == 1)
		{
			GlobalSingleCallFlag = 0;
			SYSTICK -> CTRL.B.Enable = 0;
			SYSTICK -> LOAD .R = 0;
		}
		DelayCounter=1;
	}
	else
	{
		DelayCounter++;
	}
}