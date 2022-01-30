/*
 * Delay.c
 *
 *  Created on: 29 ene. 2022
 *      Author: Lenovo
 */
#include "Delay.h"

/*VARIABLES PRIVADAS*/
uint32_t uwTick;				//incrementar 1us/ms


/**
 * @brief Retorna el valor de la variabla ticks
 * @param none
 * @return ticks
 */
static uint32_t GetTick(void){

	return uwTick;
}

/**
 * @brief Configuración de la SysTick
 */
void Delay_Init(uint32_t ticks){
	/*deshabilitar la systick*/
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
	/*cargar el valor de reload al registro LOAD*/
	SysTick->LOAD = ticks - 1;   //2^24 - SystemCoreClock * delay/1000
	/*selecciona la fuente de reloj*/
	SysTick->CTRL |= 1u<<2;
	/*elegir la fuente de reloj Habilitar el conteo*/
	/*cambiar la prioridad*/
	NVIC_SetPriority(SysTick_IRQn,7);		//prioridad de 7
	/*habilitar la IT*/
	SysTick->CTRL |= 1U<<1;					//se habilita el bit de interrupcion
	SysTick->CTRL |=  1;					//SYSCLK

	return;
}



/**
 * @brief retardos en us
 */
#if USE_DELAY_US == 1
void delay_us(uint32_t delay){
	int32_t tickstart = GetTick();
	uint32_t wait = delay;
	while ((GetTick() - tickstart) < wait);//retardo en us

	return;
}
#endif
/**
 * @brief retardos en ms
 */
void delay_ms(uint32_t delay){
#if USE_DELAY_US == 1
	for(uint32_t i = 0; i<delay; i++){
		delay_us(1000);				//1ms de retardo
	}
#else
	int32_t tickstart = GetTick();
	uint32_t wait = delay;
	while ((GetTick() - tickstart) < wait);//retardo en ms
#endif

}
