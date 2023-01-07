/*****************************************************************/
/*****************************************************************/
/********************		Author:AhmedMaher		**************/
/********************		Layer: RTOS Stack		**************/
/********************		SWC: RTOS				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-10-2020		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart(void);

uint8 RTOS_u8CreateTask(uint8 Copy_u8Priority, uint16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), uint16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(uint8 Copy_u8Priority);

void RTOS_voidResumeTask(uint8 Copy_u8Priority);

void RTOS_voidDeleteTask(uint8 Copy_u8Priority);

#endif
