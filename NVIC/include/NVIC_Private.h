#ifndef NVIC_PRIVATE
#define NVIC_PRIVATE
typedef struct
{
	uint32 ISER[32];
	uint32 ICER[32];
	uint32 ISPR[32];
	uint32 ICPR[32];
	uint32 IABR[64];
	uint8  IPR[84];
	/*union
	{
		res:4;
		rest:4;
	}*IPR;   IPR[2] --> *(IPR+2)*/
}NVIC_t;
#define NVIC       ((NVIC_t*)0xE000E100)

#define NVIC_STIR *((uint32*)0xE000EE00)

/* SCB */
#define SCB_AIRCR *((uint32*)0xE000ED0C)

#define MAX_IRQ     84
#define MIN_IRQ     0



typedef enum  {
	EXTI_WWDG,
	EXTI16,
	EXTI21,
	EXTI22,
	FLASH,
	EXTI_RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	EXTI_ADC,
	EXTI9_5


}IRQ_E;







#endif
