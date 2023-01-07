#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

/* Base address */
#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800

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
}GPIO_TYPE;

#define GPIOA              ((GPIO_TYPE*)GPIOA_BASE_ADDRESS)
#define GPIOB              ((GPIO_TYPE*)GPIOB_BASE_ADDRESS)
#define GPIOC              ((GPIO_TYPE*)GPIOC_BASE_ADDRESS)



#endif
