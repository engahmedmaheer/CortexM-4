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
	union
	{
		uint32 R ;
		struct
		{
		uint32 AFRL0:4;
		uint32 AFRL1:4;
		uint32 AFRL2:4;
		uint32 AFRL3:4;
		uint32 AFRL4:4;
		uint32 AFRL5:4;
		uint32 AFRL6:4;
		uint32 AFRL7:4;
		}B;

}AFRL;
union
{
	uint32 R ;
	struct
	{
	uint32 AFRH0:4;
	uint32 AFRH1:4;
	uint32 AFRH2:4;
	uint32 AFRH3:4;
	uint32 AFRH4:4;
	uint32 AFRH5:4;
	uint32 AFRH6:4;
	uint32 AFRH7:4;

	}B;

} AFRH;
}GPIO_type;

#define GPIOA ((volatile GPIO_type*)GPIOA_BASE_ADDRESS)
#define GPIOB ((volatile GPIO_type*)GPIOB_BASE_ADDRESS)
#define GPIOC ((volatile GPIO_type*)GPIOC_BASE_ADDRESS)


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

typedef enum
{
  Alt_FUNC0 ,
  Alt_FUNC1 ,
  Alt_FUNC2 ,
  Alt_FUNC3 ,
  Alt_FUNC4 ,
  Alt_FUNC5 ,
  Alt_FUNC6 ,
  Alt_FUNC7 ,
  Alt_FUNC9 ,
  Alt_FUNC10,
  Alt_FUNC11,
  Alt_FUNC12,
  Alt_FUNC13,
  Alt_FUNC14,
  Alt_FUNC15
}ALT_FUNC_E;

#define HIGHPORT 0xff
#define LOWPORT  0


#endif




