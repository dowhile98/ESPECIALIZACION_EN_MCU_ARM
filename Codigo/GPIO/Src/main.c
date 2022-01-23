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

uint8_t stateButton;
/**
 * @brief funcion que va generar retardos en milisegundos
 */
void delay_ms(uint32_t delay);

void delay(uint32_t delay){
	int i;
	for(;delay>0;delay--){
		for(i = 0;i<3195/2;i++);
	}
}

int main(void)
{
	/*PC13 -> ENTRADA y PA5 -> SALIDA DIGITAL*/
	/*HABILITAMOS EL RELOJ*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;
	//PC13
	GPIOC->MODER &=~ (GPIO_MODER_MODE13);		//input floating
	GPIOC->PUPDR &=~ (GPIO_PUPDR_PUPD13);		//no pull up/down
	//PA5
	GPIOA->MODER &=~ GPIO_MODER_MODE5;
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	GPIOA->OTYPER &=~ GPIO_OTYPER_OT5;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5;		//VERY HIGH ESPEED
	GPIOA->PUPDR &=~ GPIO_PUPDR_PUPD5;			//NO PULL UP/DOWN

//	GPIOA->ODR |= 1U<<5;
//
//	GPIOA->ODR &=~ (1U<<5);
//
//	GPIOA->BSRR |= 1U<<5;
//
//	GPIOA->BSRR |= 1U<<(16 + 5);
	stateButton  = GPIOC->IDR;
    /* Loop forever */
	for(;;){

//		stateButton = (GPIOC->IDR>>13 & 0x1);
//		if(stateButton)
//			GPIOA->BSRR |= 1U<<5;
//		else
//			GPIOA->BSRR |= (1U<<(16+5));
		GPIOA->ODR ^= 1U<<5;
		delay_ms(100);

	}
}

/**
 * @brief funcion que va generar retardos en milisegundos
 */
void delay_ms(uint32_t delay){
	uint32_t i;
	/*deshabilitar la systick*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
	/*cargar el valor de reload al registro LOAD*/
	SysTick->LOAD = SystemCoreClock /1000 - 1;   //2^24 - SystemCoreClock * delay/1000

	/*poner el regitro VAL*/
	SysTick->VAL = 0;

	/*elegir la fuente de reloj*/
	SysTick->CTRL |= 1u<<2;				//SYSCLK
	/*Habilitar el conteo*/
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

	for(i = 0;i<delay;i++){
		while(!(SysTick->CTRL & 1U<<16));			//retardo de un milisegundo
	}

	/*deshabilitar la systick*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;

	return;
}
