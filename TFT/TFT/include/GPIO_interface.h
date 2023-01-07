#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE
#define pin_number  6


void GPIO_mainFunction(void);
void GPIO_SET_PIN_VALUE_ODR(uint8 port, uint8 pin ,uint8 value);
void GPIO_SET_PIN_VALUE_BSRR(uint8 port, uint8 pin ,uint8 value);
uint8 GPIO_GET_PIN_VALUE(uint8 port, uint8 pin);
void GPIO_SET_PORT_VALUE_ODR(uint8 port, uint8 data);

typedef struct
{
	uint8 PORT;
	uint8 PIN;
	uint8 MODE;
	uint8 TYPE;  //OPEN DRAIN OR PUSH PULL
	uint8 SPEED;
	uint8 PULL_UP_DOWN;
	uint8 AF_mode;

}pin_info;
pin_info configPin[pin_number];
#define PORTA    		   0
#define PORTB    		   1
#define PORTC     		   2
#define HIGH               1
#define LOW                0

#define PIN0               0
#define PIN1               1
#define PIN2               2
#define PIN3               3
#define PIN4               4
#define PIN5               5
#define PIN6               6
#define PIN7               7
#define PIN8               8
#define PIN9               9
#define PIN10              10
#define PIN11                11
#define PIN12                12
#define PIN13                13
#define PIN14                14
#define PIN15               15
#define NOT_USED            120


#define INPUT      		   0b00
#define OUTPUT     		   0b01
#define AF          	   0b10
#define ANALOG      	   0b11
#define PUSH_PULL          0
#define OPEN_DRAIN   	   1
#define Low_speed     	   0b00
#define Medium_speed 	   0b01
#define High_speed   	   0b10
#define Very_high speed    0b11
#define PULL_UP            0b01
#define PULL_DOWN          0b10
#define FLOATING           0b00

#define  AF0  0b0000
#define  AF1  0b0001
#define  AF2  0b0010
#define  AF3  0b0011
#define  AF4  0b0100
#define  AF5  0b0101
#define  AF6  0b0110
#define  AF7  0b0111
#define  AF8  0b1000
#define  AF9  0b1001
#define  AF10 0b1010
#define  AF11 0b1011
#define  AF12 0b1100
#define  AF13 0b1101
#define  AF14 0b1110
#define  AF15 0b1111


#endif
