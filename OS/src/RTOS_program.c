/*****************************************************************/
/*****************************************************************/
/********************		Author:AhmedMaher		**************/
/********************		Layer: RTOS Stack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 1.00			**************/
/********************		Date: 22/9/2022		    **************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include  "ERR_TYPE.h"

#include "SYSTICK_interface.h"
#include "NVIC_interface.h"

#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"

Task_t SystemTasks[TASK_NUM] ={{NULL}};

void RTOS_voidStart(void)
{
	SYSTICK_voidAsynchMsecondsDelay(1,(&voidScheduler));
	NVIC_voidPriorityInit();


}

uint8 RTOS_u8CreateTask(uint8 Copy_u8Priority, uint16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), uint16 Copy_u16FirstDelay)
{
	uint8 Local_u8ErrorState = OK;

	/*Check if the required priority is empty or used before for another task*/
	if(SystemTasks[Copy_u8Priority].TaskFunc == NULL)
	{
		SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
		SystemTasks[Copy_u8Priority].State = TASK_RESUMED;		//Initialize the task state
		SystemTasks[Copy_u8Priority].FirstDelay= Copy_u16FirstDelay;
	}
	else
	{
		/*Priority is reserved before, don't create the task*/
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

void RTOS_voidDeleteTask(uint8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}

void RTOS_voidSuspendTask(uint8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(uint8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_RESUMED;
}

static void voidScheduler(void)
{
	uint8 Local_u8TaskCounter;

	/*loop on all tasks to check their periodicity*/
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		/*Check if the task is suspended or not*/
		if(SystemTasks[Local_u8TaskCounter].State== TASK_RESUMED)
		{
			if(SystemTasks[Local_u8TaskCounter].FirstDelay ==0)
			{
				/*Invoke the task function*/
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();

					/*Assign the first delay parameter to the periodicity minus 1*/
					SystemTasks[Local_u8TaskCounter].FirstDelay =( SystemTasks[Local_u8TaskCounter].Periodicity-1);
				}
				else
				{
					/*Decrement the first delay*/
					SystemTasks[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}
		else
		{
			/*Task is suspended, do nothing*/
		}
	}
}


