#ifndef RCC_INTERFACE
#define RCC_INTERFACE
void RCC_voidInit(); //reg cr, cfgr
void RCC_voidEnablePeripheralClock(uint8 busid, uint8 prephirelid); // reg->ahb1enr prephiralid -- in interface
void RCC_voidDisablePeripheralClock(uint8 busid, uint8 prephirelid);
#define AHB1_EN    1
#define AHB2_EN    2
#define APB1_EN    3
#define APB2_EN    4 

//AHB1_EN
#define GPIO_PORTA  0
#define GPIO_PORTB  1
#define GPIO_PORTC   2
#define GPIO_PORTD  3
#define GPIO_PORTE  4
#define GPIO_PORTH  5
#define CRC         6
#define DMA_1      7 
#define DMA_2      8
//** ApB1_PREPH
#define TIM_2      9
#define TIM_3      10
#define TIM_4      11
#define TIM_5      12
#define WWDG_EN    13
#define SPI_2      14
#define SPI_3      32
#define USART_2    16
#define I2C_1      17
#define I2C_2      18
#define I2C_3      19
#define PWR_EN     20
//APB2ENR
#define TIM_1      21
#define USART_1    22
#define USART_6    23
#define ADC_1      24
#define SDIO       25
#define SPI_1      26
#define SPI_4      27 
#define SYSCFG_EN  28
#define TIM_9      29
#define TIM_10     30
#define TIM_11     31
#endif
