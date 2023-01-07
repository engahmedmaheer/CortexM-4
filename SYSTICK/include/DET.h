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


}DET_module_ID_E;

typedef enum {

	DET_RCC_voidResetPeripheral,
	DET_RCC_voidEnablePeripheralClock,
	DET_RCC_voidDisablePeripheralClock,
	DET_GPIO_voidSetPinValue,
	DET_GPIO_uint8GetPinValue

}DET_function_ID_E;

typedef enum {

	DET_busId,
	DET_peripheralId,

	DET_PortId,
	DET_PinId,
	DET_PinStatue


}DET_error_ID_E;

void DET_ReportError(DET_module_ID_E   module_ID   ,
		DET_function_ID_E function_ID ,
		DET_error_ID_E    error_ID  );



#endif
