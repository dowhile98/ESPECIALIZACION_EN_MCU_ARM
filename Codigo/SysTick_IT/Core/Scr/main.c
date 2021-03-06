/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f4xx.h"
/* Private includes ----------------------------------------------------------*/
#include "RCC.h"
#include "Config.h"
#include "Delay.h"
/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
#define USE_SWV			0
#define BIT2 			*((volatile uint32_t*)(0x22006008))

#define BITBAND_PERI(a,b) 		((PERIPH_BB_BASE + (a - PERIPH_BASE)*32 + 4*b))

#define PA5				*((volatile uint32_t*)(BITBAND_PERI(GPIOA_BASE + 0x14,5)))
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/


int main(void)
{
	/*delay init*/
	PLL_Config();						//84MHZ
#if USE_DELAY_US == 1
	Delay_Init(SystemCoreClock/1000000);
#else
	Delay_Init(SystemCoreClock/1000);
#endif

	/*LED INIT*/
	GPIO_CLOCK_ENABLE(A)
	GPIOX_MODER(MODE_OUT,LED);
	GPIOX_PUPDR(MODE_PU_NONE,LED);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH,LED);
	/*BUTTON INIT*/
	RCC->AHB1ENR |= GPIOX_CLOCK(BUTTON);
	GPIOX_MODER(MODE_DIGITAL_INPUT,BUTTON);
	GPIOX_PUPDR(MODE_PU_NONE,BUTTON);
    /* Loop forever */
	for(;;){

		PA5 = 1;
		delay_ms(100);
		GPIOX_ODR(LED) = 0;
		delay_ms(100);
	}
}
/******************************************************************************/
int __io_putchar(int ch){
#if (USE_SWV== 1)
	ITM_SendChar((uint32_t)ch);
#endif
	return ch;
}
