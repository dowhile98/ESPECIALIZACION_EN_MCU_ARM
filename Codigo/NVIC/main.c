#include "stm32l4xx.h"                  // Device header

int main(void){
  
	NVIC->IP[EXTI4_IRQn] = 7<<4;							//se cambia la prioridad
	NVIC->ISER[EXTI4_IRQn>>5U] |= 1U<<(EXTI4_IRQn & 0x1FUL);//se activa la interrupcion
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC->STIR |= EXTI4_IRQn;							//se genera una interrupcion por software
	while(1){
		
	}
	
}

/*RUTINA DE SERVICIO DE LA INTERRUPCION*/
void EXTI4_IRQHandler(void){
	
	//NVIC->ICPR[EXTI4_IRQn>>5U] |= 1U<<(EXTI4_IRQn & 0x1FUL);
	NVIC->STIR = EXTI3_IRQn;
}


void EXTI3_IRQHandler(void){
	
}
