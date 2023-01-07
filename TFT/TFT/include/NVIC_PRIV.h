#ifndef NVIC_PRIV
#define NVIC_PRIV
 
 typedef struct
 {
	 uint32 ISER[32];
	 uint32 ICER[32];
	 uint32 ISPR[32];
	 uint32 ICPR[32];
	 uint32 IAPR[32];
	 uint32 RESERVED[32];
	 uint8  IPR[84];
	 }NVIC_T;

#define NVIC     ((NVIC_T*)0xE000E100)

#define NVIC_STIR  *((unit32*)0xE000EF00)
#define NVIC_SCB   *((uint32*)0xE000ED0C)
#endif
