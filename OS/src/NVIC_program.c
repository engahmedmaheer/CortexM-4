#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DET.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"

void NVIC_voidPriorityInit(void)
{
	SCB_AIRCR = PRIORITY_DISTRIBUTION;
}

void NVIC_voidSetPriority(uint8 copy_uint8Position, uint8 copy_uint8Priority)
{
	NVIC -> IPR[copy_uint8Position] = (copy_uint8Priority << 4);
}
void NVIC_voidEnableInterrupt(uint8 copy_uint8Position)
{
	if ((copy_uint8Position >= MIN_IRQ) && (copy_uint8Position <= MAX_IRQ))
	{
		NVIC -> ISER[copy_uint8Position / 32] = (1 << (copy_uint8Position % 32));
	}
	else
	{
		DET_ReportError(DET_NVICModuleID,DETNVIC_voidEnableInterrupt,DET_PositionID);
	}
}
void NVIC_voidDisableInterrupt(uint8 copy_uint8Position)
{
	if ((copy_uint8Position >= MIN_IRQ) && (copy_uint8Position <= MAX_IRQ))
	{
		NVIC -> ICER[copy_uint8Position / 32] = (1 << (copy_uint8Position % 32));
	}
	else
	{
		DET_ReportError(DET_NVICModuleID,DETNVIC_voidDisableInterrupt,DET_PositionID);
	}

}

void NVIC_voidSetPendingFlag(uint8 copy_uint8Position)
{
	if ((copy_uint8Position >= MIN_IRQ) && (copy_uint8Position <= MAX_IRQ))
	{
		NVIC -> ISPR[copy_uint8Position / 32] = (1 << (copy_uint8Position % 32));
	}
	else
	{
		DET_ReportError(DET_NVICModuleID,DETNVIC_voidSetPendingFlag,DET_PositionID);

	}

}
void NVIC_voidClearPendingFlag(uint8 copy_uint8Position)
{
	if ((copy_uint8Position >= MIN_IRQ) && (copy_uint8Position <= MAX_IRQ))
		{
	NVIC -> ICPR[copy_uint8Position / 32] = (1 << (copy_uint8Position % 32));
		}
	else
		{
			DET_ReportError(DET_NVICModuleID,DETNVIC_voidClearPendingFlag,DET_PositionID);

		}
}

uint8 NVIC_uint8GetActiveFlag (uint8 copy_uint8Position)
{
	return GET_BIT(NVIC->IABR[copy_uint8Position / 32], (copy_uint8Position % 32));
}
