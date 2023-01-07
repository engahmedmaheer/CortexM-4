/*****************************************************************/
/*****************************************************************/
/********************		Author: AhmedMaher		**************/
/********************		Layer: RTOS Stack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-10-2020		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	uint16 Periodicity;
	void(*TaskFunc)(void);
	uint8 State;
	uint16 FirstDelay;
}Task_t;

static void voidScheduler(void);

#define TASK_RESUMED		0
#define TASK_SUSPENDED		1

#endif
