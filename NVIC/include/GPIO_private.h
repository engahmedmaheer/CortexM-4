#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

#define GPIOA_BASE_ADDRESS   0x40020000
#define GPIOB_BASE_ADDRESS   0x40020400
#define GPIOC_BASE_ADDRESS   0x40020800

typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_type;

#define GPIOA ((GPIO_type*)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_type*)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_type*)GPIOC_BASE_ADDRESS)


#define NOT_USED  255




typedef enum
{
	INPUT,
	OUTPUT,
	AF,
	ANALOG
}MODE_IDs_E;

typedef enum
{
	PUSH_PULL,
	OPEN_DRAIN
}TYPE_IDs_E;

typedef enum
{
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED,
    VERY_HIGH_SPEED	
}SPEED_IDs_E;

typedef enum
{
	FLOATING,
	PULL_UP,
	PULL_DOWN
}INPUT_TYPE_IDs_E;



#endif




