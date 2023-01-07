#ifndef SYSTICK_INTERFACE
#define SYSTICK_INTERFACE

/* systick global variables */
void (*GlobalSystickCallBack) (void);
volatile uint32 globalSeconds;
volatile uint8 globalSingleCallIndicator;

/* systick public functions */
void SYSTICK_voidInit(void);

void SYSTICK_voidSynchSecondsDelay(uint32 local_uint32Seconds);
void SYSTICK_voidSynchMsecondsDelay(uint32 local_uint32MilliSeconds);
void SYSTICK_voidSynchUsecondsDelay(uint32 local_uint32MicroSeconds);

void SYSTICK_voidAsynchSecondsDelay(uint32 local_uint32Seconds, void (*localCallBackPtr) (void));
void SYSTICK_voidAsynchMsecondsDelay(uint32 local_uint32MilliSeconds, void (*localCallBackPtr) (void));
void SYSTICK_voidAsynchUsecondsDelay(uint32 local_uint32MicroSeconds, void (*localCallBackPtr) (void));

void SYSTICK_voidAsynchSingleSecondsDelay(uint32 local_uint32Seconds, void (*localCallBackPtr) (void));
void SYSTICK_voidAsynchSingleMsecondsDelay(uint32 local_uint32MilliSeconds, void (*localCallBackPtr) (void));
void SYSTICK_voidAsynchSingleUsecondsDelay(uint32 local_uint32MicroSeconds, void (*localCallBackPtr) (void));

uint32 SYSTICK_uint32GetElapsedTime (void);
uint32 SYSTICK_uint32GetRemainingTime (void);

void SYSTICK_voidStop(void);


#endif
