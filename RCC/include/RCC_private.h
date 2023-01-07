#ifndef RCC_PRIVATE
#define RCC_PRIVATE


#define RCC_BASE_ADDRESS 0x40023800 
typedef struct
{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 RESERVED2;
	uint32 RESERVED3;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 RESERVED0;
	uint32 RESERVED1;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 RESERVED4;
	uint32 RESERVED5;
	uint32 APB1ENR;
	uint32 APB2ENR;
}RCC_type;

#define RCC  ((volatile RCC_type *)RCC_BASE_ADDRESS)

typedef enum
{
	AHB ,
	APB1,
	APB2
}busId_E;

typedef enum
{
	HSI,
	HSE,
	PLL
}clockType_E;

#endif
