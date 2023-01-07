
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_INTERFACE.h"
#include "NVIC_PRIV.h"


void NVIC_GROUP_SUB_PRIORITY(void)
{
	NVIC_SCB=GROUP_SUB_PRIORITY ;
}


void NVIC_voidSoftwarePriority (uint8 local_uint8Position, uint8 local_uint8Priority)
{
	NVIC -> IPR[local_uint8Position] = (local_uint8Priority << 4);
}

void NVIC_ENABLE_INTRRUPT(uint8 position)
{
	NVIC->ISER[position/32] = (1<<(position%32));
}

void NVIC_DISABLE_INTRRUPT(uint8 position)
{
		NVIC->ICER[position/32] = (1<<(position%32));

}
void NVIC_SET_PENDING_FALG(uint8 position)
{
	NVIC->ISPR[position/32] = (1<<(position%32));
}

void NVIC_CLR_PENDING_FALG(uint8 position)
{
	NVIC->ICPR[position/32] = (1<<(position%32));
}
uint8 NVIC_uint8GetActiveFlag(uint8 local_uint8Position)
{
	uint8 local_unit8ActiveFlag = GET_BIT(NVIC -> IAPR[local_uint8Position / 32],
	                                              local_uint8Position % 32);
												  							  
	return local_unit8ActiveFlag;
}

