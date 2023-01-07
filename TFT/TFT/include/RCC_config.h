#ifndef RCC_CONFIG
#define RCC_CONFIG



/* select CLOCK SYSTEM
RCC_HSE_CRYSTAL
RCC_HSE_RC
RCC_HSI
RCC_PLL
*/
#define RCC_CLOCK_SYSTEM      RCC_HSI

// IF YOU didnt select pll in-> RCC_CLOCK_SYSTEM <-"RCC_CLOCK_PLL_INPUT" will not have any effect

/*select RCC_CLOCK_PLL_INPUT
 *   RCC_PLL_HSI
     RCC_PLL_HSE
note" pll will produce clock has 84 Mhz  "
 */
//#define RCC_CLOCK_PLL_INPUT   RCC_PLL_HSE

#define AHB1_EN    1
#define AHB2_EN    2
#define APB1_EN    3
#define APB2_EN    4 

 #define RCC_HSE_CRYSTAL 0
 #define RCC_HSE_RC      1
 #define RCC_HSI         2
 #define RCC_PLL         3


#define RCC_PLL_HSI  4
#define RCC_PLL_HSE  5

#endif
