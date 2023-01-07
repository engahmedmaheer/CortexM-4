#ifndef SYSTICK_PRIVATE
#define SYSTICK_PRIVATE

typedef struct
{
	union
	{
		uint32 R;
		struct
		{
			uint32 ENABLE:1;
			uint32 TICKINT:1;
			uint32 CLKSOURCE:1;
			uint32 unused_0:13;
			uint32 COUNTFLAG:1;
			uint32 unused_1:15;			
		}B;
	}CTRL;

	union
	{
		uint32 R;
		struct
		{
			uint32 RELOAD:24;
			uint32 unused_2:8;
		}B;
	}LOAD;
	
	union
	{
		uint32 R;
		struct
		{
			uint32 CURRENT:24;
			uint32 unused_3:8;
		}B;
	}VALUE;
}systick_t;

#define SYSTICK ((volatile systick_t*)0xE000E010)

typedef enum
{
	AHB_DIV_8,
	AHB,

}SYSTICK_clockSrc_E;

#endif
