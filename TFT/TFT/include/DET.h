#ifndef DET_H
#define DET_H

#define DET_INTIA 1

typedef enum{
	RCC_MODULE_ID,
	GPIO_MODULE_ID,
	SYS_TICK_MODULE_ID,
	}DET_Module_Id;
	
	void DET_Report_Error(uint8 Module_Id,uint8 Error_Id,uint8 Function_Id);
#endif
