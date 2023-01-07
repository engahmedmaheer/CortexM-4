#ifndef NVIC_INTERFACE
#define NVIC_INTERFACE




void NVIC_voidPriorityInit(void);
void NVIC_voidSetPriority(uint8 copy_uint8Position, uint8 copy_uint8Priority);


void NVIC_voidEnableInterrupt(uint8 copy_uint8Position);
void NVIC_voidDisableInterrupt(uint8 copy_uint8Position);


void NVIC_voidSetPendingFlag(uint8 copy_uint8Position);
void NVIC_voidClearPendingFlag(uint8 copy_uint8Position);


uint8 NVIC_uint8GetActiveFlag (uint8 copy_uint8Position);





#define GROUP_4_SUB_0   0x05FA0300
#define GROUP_3_SUB_1   0x05FA0400  
#define GROUP_2_SUB_2   0x05FA0500  
#define GROUP_1_SUB_3   0x05FA0600  
#define GROUP_0_SUB_4   0x05FA0700  


#define PRIORITY_DISTRIBUTION  GROUP_1_SUB_3




#endif
