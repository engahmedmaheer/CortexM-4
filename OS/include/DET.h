/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Ahmed Maher	********************************/
/*************************  Date: 20/8/2022	********************************/
/*************************  Version: 1.00		********************************/
/*************************  @ brief : DET  		********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef DET_H
#define DET_H



typedef enum {
	DET_RCCModuleID,
	DET_GPIOModuleID,
	DET_STPModuleID,
	DET_NVICModuleID


}DET_module_ID_E;

typedef enum {

	DET_RCC_voidResetPeripheral,
	DET_RCC_voidEnablePeripheralClock,
	DET_RCC_voidDisablePeripheralClock,
	DET_GPIO_voidSetPinValue,
	DET_GPIO_uint8GetPinValue,
	DET_STP_VoidSendNumber,
	DETNVIC_voidPriorityInit,
	DETNVIC_voidSetPriority,
	DETNVIC_voidEnableInterrupt,
	DETNVIC_voidDisableInterrupt,
	DETNVIC_voidSetPendingFlag,
	DETNVIC_voidClearPendingFlag,
	DETNVIC_uint8GetActiveFlag

}DET_function_ID_E;

typedef enum {

	DET_busId,
	DET_peripheralId,

	DET_PortId,
	DET_PinId,
	DET_PinStatue,
	DET_NULL_POINTER,

	DET_PositionID,
	DET_Priority,


}DET_error_ID_E;

void DET_ReportError(DET_module_ID_E   module_ID   ,
		DET_function_ID_E function_ID ,
		DET_error_ID_E    error_ID  );



#endif
