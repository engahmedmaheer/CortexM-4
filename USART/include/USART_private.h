/*****************************************************************/
/*****************************************************************/
/********************		Author: AhmedMaher		**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 1.00			**************/
/********************		Date: 26-10-2020		**************/
/*****************************************************************/
/*****************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H



typedef struct
{
	union
	{
		uint32 R;
		struct
		{
			uint32 RESERVER0:22;
			uint8  CTS      :1 ;
			uint32 LBD      :1 ;
			uint32 TXE      :1 ;
			uint32 TC       :1 ;
			uint32 RXNE     :1 ;
			uint32 IDLE     :1 ;
			uint32 ORE      :1 ;
			uint32 NF       :1 ;
			uint32 FE       :1 ;
			uint32 PE       :1 ;
		}B;
	}SR;
	union
	{
		uint32 R;
		struct
		{
			uint32 RESERVED1 : 23;
			uint32  DR :9;

		}B;

	}DR ;
	union
	{
		uint32 R;
		struct
		{
			uint32 RESERVED2 :16 ;
			uint32 DIV_Mantissa :12;
			uint32 DIV_Fraction: 4 ;

		}B;

	}BRR ;
	union
	{

		uint32 R;
		struct
		{
			uint32 RESERVED3     :16   ;
			uint8   OVER8        : 1   ;
			uint8   Reserved4    : 1   ;
			uint8   UE      	 : 1   ;
			uint8   M  			 : 1   ;
			uint8   WAKE    	 : 1   ;
			uint8   PCE     	 : 1   ;
			uint8   PS    		 : 1   ;
			uint8   PEIE         : 1   ;
			uint8   TXEIE        : 1   ;
			uint8   TCIE         : 1   ;
			uint8   RXNEIE       : 1   ;
			uint8   IDLEIE     	 : 1   ;
			uint8   TE    		 : 1   ;
			uint8   RE     		 : 1   ;
			uint8   RWU     	 : 1   ;
			uint8   SPK      	 : 1   ;
		}B;
	}CR1 ;
	union{

		uint32 R;
		struct
		{
			uint32 	  RESERVED5 :17;
			uint32    LINEN     : 1 ;
			uint32    STOP      : 2 ;
			uint32    CLKEN     : 1 ;
			uint32    CPOL      : 1 ;
			uint32    CPHA      : 1 ;
			uint32    LBCL      : 1;
			uint32    RESERVED6 : 1 ;
			uint32    LBDIE     : 1 ;
			uint32    LBDL      : 1 ;
			uint32    RESERVED7 : 1 ;
			uint32    ADD       : 4 ;
		}B;
	} CR2 ;
	union
	{

		uint32 R;
		struct
		{
			uint32 RESERVED8 :20;
			uint8  ONEBIT    :1;
			uint8  CTSIE     :1;
			uint8  CTSE      :1;
			uint8  RTSE      :1;
			uint8  DMAT      :1;
			uint8  DMAR      :1;
			uint8  SCEN      :1;
			uint8  NACK      :1;
			uint8  HDSEL     :1;
			uint8  IRLP      :1;
			uint8  IREN      :1;
            uint8  EIE       :1;
		}B;
	} CR3 ;

	union

	{

		uint32 RESERVED9 :16 ;
		uint8  GT        : 8 ;
		uint8  PSC       : 8 ;

	}GTPR ;


}REG_t;



#define USART		((volatile REG_t*)			0x40011000)


typedef enum
{
	EVEN,
	ODD
}Parity_E;
typedef enum
{
	DISABLE,
	ENALBE
}EN;

typedef enum
{
	DATA_8BIT_WORD_LENGTH,
	DATA_9BIT_WORD_LENGTH
}W_L_E;
typedef enum
{
	ONE_STOP,
	HALF_STOP_BIT,
	TWO_STOP
}STOPBITS_E;




#endif
