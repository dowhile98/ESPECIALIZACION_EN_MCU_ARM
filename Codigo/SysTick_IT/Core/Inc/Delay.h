/*
 * Delay.h
 *
 *  Created on: 29 ene. 2022
 *      Author: Lenovo
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include <stdint.h>
#include "stm32f4xx.h"
/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
#define USE_DELAY_US  0
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/

/**
 * @brief Configuración de la SysTick
 */
void Delay_Init(uint32_t ticks);

#if USE_DELAY_US == 1
/**
 * @brief retardos en us
 */
void delay_us(uint32_t delay);
#endif
/**
 * @brief retardos en ms
 */
void delay_ms(uint32_t delay);


#endif /* INC_DELAY_H_ */
