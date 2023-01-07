#ifndef NVIC_INTERFACE
#define NVIC_INTERFACE


#define GROUP_4_SUB_0        0x05FA0000
#define GROUP_3_SUB_1        0x05FA0400
#define GROUP_2_SUB_2        0x05FA0500
#define GROUP_1_SUB_3        0x05FA0600
#define GROUP_0_SUB_4        0x05FA0700

#define GROUP_SUB_PRIORITY  GROUP_3_SUB_1


void NVIC_GROUP_SUB_PRIORITY(void);
void NVIC_ENABLE_INTRRUPT(uint8 position);
void NVIC_DISABLE_INTRRUPT(uint8 position);
void NVIC_SET_PENDING_FALG(uint8 position);
void NVIC_CLR_PENDING_FALG(uint8 position);
void NVIC_voidSoftwarePriority (uint8 local_uint8Position, uint8 local_uint8Priority);

#endif
