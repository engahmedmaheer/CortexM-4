/*******************************************************************************/
/*******************************************************************************/
/***************************	Author : AhmedMaher     ************************/
/***************************	Date   : 20/9/2021	    ************************/
/***************************	Layer  : MCAL		    ************************/
/***************************	Version: 1.00		    ************************/
/***************************	brief: DMA FOR STM32F401************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


typedef struct
{
	union
	{
		uint32 R;
		struct
		{
			uint8 EN       :1;
			uint8 DMEIE    :1;
			uint8 TEIE     :1;
			uint8 HTIE	   :1;
			uint8 TCIE     :1;
			uint8 PFCTRL   :1;
			uint8 DIR      :2;
			uint8 CIRC     :1;
			uint8 PINC     :1;
			uint8 MINC     :1;
			uint8 PSIZE    :2;
			uint8 MSIZE    :2;
			uint8 PINCOS   :1;
			uint8 PL       :2;
			uint8 DBM      :1;
			uint8 CT       :1;
			uint8 Reserved0:1;
			uint8 PBURST   :2;
			uint8 MBURST   :2;
			uint8 CHSEL    :3;
			uint8 Reserved1:4;
		}B;
	}CR;
	union
	{
		   uint32 R;
		struct
		{

			uint16 NDT :16 ;
			uint16 Reserved2: 16;

		}B;
	}NDTR;

	union
	{
		    uint32 R;
		struct
		{
			uint32 PAR :32;
		}B;
	}PAR;

	union
	{
		    uint32 R;
		struct
		{
		    uint32 M0A :32 ;

		}B;
	}M0AR;

	union
	{
		    uint32 R;
		struct
		{
			uint32 M1A :32 ;

		}B;
	}M1AR;
	union
	{
		    uint32 R;
		struct
		{
			uint32	FTH       :   2;
			uint32	DMDIS     :   1;
			uint32	FS        :   3;
			uint32	Reserved3 :   1;
			uint32	FEIE      :   1;
			uint32	Reserved4 :  24;

		}B;
	}FCR;
}STREAM_t;


typedef struct

{
	uint32   DMA_LISR      ;
	uint32   DMA_HISR      ;
	uint32   DMA_LIFCR     ;
	uint32   DMA_HIFCR     ;
	STREAM_t DMA_STREAM[6] ;

}DMA_REG_t;


typedef enum
{
	CHANNEL0,
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7
}DMA_CHANNEL_E;
typedef enum
{
	STREAM0,
	STREAM1,
	STREAM2,
	STREAM3,
	STREAM4,
	STREAM5,
	STREAM6,
	STREAM7

}DMA_STR_E;

typedef enum
{
	LOW_P,
	MEDUIM_P,
	HIGH_P,
	VERY_HIGH_P
}Priorety_level_E;


typedef enum
{
	BYTE,
	HALF_WORD ,
	WORD
}BLOCK_SIZE_E;


typedef enum
{
	PERIPHERAL_TO_MEMORY,
	MEMOREY_TO_PERIPHERAL,
	MEMOREY_TO_MEMOREY,
	PERIPHERAL_TO_PERIPHERL

}MODE_E;


typedef enum
{
	FREE_RUNNING,
	 TRIGGER

}FLOWMODE_E;



/******************************/
#define P_SIZE    0
#define MAX_SEND  1
/**************************/
#define ENABLE    1
#define DISABLE   0

/******************************/
#define NULL      (void*)0

/************************************************************/
#define  DMA1   ((volatile DMA_REG_t*)  DMA1_BASE_ADDRESS )
#define  DMA2   ((volatile DMA_REG_t*)  DMA2_BASE_ADDRESS )
/***********************************************************/

#define DMA1_BASE_ADDRESS 			0x40026000
#define DMA2_BASE_ADDRESS			0x40026400

/********************************************************/

#define DMA_ONE  0
#define DMA_TWO  1

/********************************************************/







#endif
