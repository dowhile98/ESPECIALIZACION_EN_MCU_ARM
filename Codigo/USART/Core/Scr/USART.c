/*
 * USART.c
 *
 *  Created on: 30 ene. 2022
 *      Author: Lenovo
 */

#include "USART.h"

/**
 * @brief configura los pines PA9 y P10
 */
static void USART1_PinoutConfig(void){
	/*habilitar el reloj*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*CONFIGURAMOS PA9 - PA10*/
	GPIOA->MODER &=~ (GPIO_MODER_MODE10 | GPIO_MODER_MODE9);
	GPIOA->MODER |= GPIO_MODER_MODE10_1 | GPIO_MODER_MODE9_1;		//Funcion alternativa
	GPIOA->AFR[1] &=~ (GPIO_AFRH_AFSEL10 | GPIO_AFRH_AFSEL9);
	GPIOA->AFR[1] |= 7U<<GPIO_AFRH_AFSEL10_Pos;						//PA10 -> USART1_RX
	GPIOA->AFR[1] |= 7U<<GPIO_AFRH_AFSEL9_Pos;						//PA9  -> USART1_TX
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED10 | GPIO_OSPEEDR_OSPEED9;	//VERY HIGH SPEED
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD10 | GPIO_PUPDR_PUPD9;			//PULL UP
	return;
}
/**
 * @brief configura los pines PA9 y P10
 */
static void USART2_PinoutConfig(void){
	/*habilitar el reloj*/
	RCC->AHB1ENR |= GPIOX_CLOCK(USART2_TX);
	/*CONFIGURAMOS PA2 - PA3*/
	GPIOX_MODER(MODE_ALTER,USART2_TX);
	GPIOX_MODER(MODE_ALTER,USART2_RX);
	GPIOX_AFR(7U,USART2_TX);
	GPIOX_AFR(7U,USART2_RX);

	GPIOX_OSPEEDR(MODE_SPD_VHIGH,USART2_TX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH,USART2_RX);
	GPIOX_PUPDR(MODE_PU_UP,USART2_TX);
	GPIOX_PUPDR(MODE_PU_UP,USART2_RX);
	return;
}
/**
 * @configura el USARTx como:
 * 1-bit stop
 * sin paridad
 * 8-bit de datos
 */
void USART_Init(USART_TypeDef * USARTx,uint32_t baud){
	/*habilitar el reloj*/
	if(USARTx == USART1){
		/*habilitar el reloj*/
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		/*configurar los pines (TX y RX)*/
		USART1_PinoutConfig();

	}else if(USARTx == USART2){
		/*habilitar el reloj*/
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
		/*configurar los pines (TX y RX)*/
		USART2_PinoutConfig();
	}
	/*CONFIGURAR LOS PARETROS DE LA COMUNICACION*/
	USARTx->CR1 &=~ (USART_CR1_M);				//8-BIT DE DATOS
	USARTx->CR1 &=~ (USART_CR1_OVER8);			//OVERSAMPLING 16
	USARTx->BRR = UART_BRR_SAMPLING16(SystemCoreClock,baud);
	USARTx->CR1 |= USART_CR1_TE | USART_CR1_RE;	//habilita la recepcion y transmimsion
	USARTx->CR2 &=~ (USART_CR2_STOP);			//1bit de stop
	USARTx->CR1 &=~ (USART_CR1_PCE);			//sin paridad
	/*configuracion de interrupciones*/

	/*habilitar el USART*/
	USARTx->CR1 |= USART_CR1_UE;				//Habilitacion del USART
	return;
}


/**
 * @brief enviar N data por el USART
 */
void USART_SendData(USART_TypeDef * USARTx,uint8_t *pTxBuffer, uint32_t Size){
	uint16_t *pdata;

	for(uint32_t i = 0;i<Size;i++){
		//verificar el flag TXE
		while(!(USARTx->SR & USART_SR_TXE));

		//verificar si se ve transmitir en modo de 8bit o 9bit
		if(USARTx->CR1 & USART_CR1_M){
			//enviar el dato
			pdata = (uint16_t*) pTxBuffer;
			USARTx->DR = (*pdata & (uint16_t)0x1FF);
			//Verificar la paridad
			if(!(USARTx->CR1 & USART_CR1_PCE )){
				pTxBuffer++;
				pTxBuffer++;
			}
			else{
				pTxBuffer++;
			}
		}
		else{		//modo de 8bit
			USARTx->DR = (*pTxBuffer & (uint8_t)0xFF);
			pTxBuffer++;
		}
	}
	/*esperamos que TC se ponga a 1*/
	while(!(USARTx->SR & USART_SR_TC));

	return;
}


/**
 * @brief enviar N data por el USART
 */
void USART_ReceiveData(USART_TypeDef * USARTx,uint8_t *pRxBuffer, uint32_t Size){
	for(uint32_t i= 0; i<Size;i++){
		//verificar el flag RXNE
		while(!(USARTx->SR & USART_SR_RXNE));
		//verificar si se ve transmitir en modo de 8bit o 9bit
		if(USARTx->CR1 & USART_CR1_M){

			/*VERIFICAR LA PARIDAD*/
			if(!(USARTx->CR1 & USART_CR1_PCE )){	//sin paridad
				*((uint16_t*) pRxBuffer) = USARTx->DR & (uint16_t) 0x1FF;
				pRxBuffer++;
				pRxBuffer++;
			}
			else{	//paridad
				*pRxBuffer = USARTx->DR & (uint8_t) 0xFF;
				pRxBuffer++;
			}
		}
		else{
			/*VERIFICAR LA PARIDAD*/
			if(!(USARTx->CR1 & USART_CR1_PCE)){
				*pRxBuffer = USARTx->DR & (uint8_t) 0xFF;
			}
			else{
				*pRxBuffer = USARTx->DR & (uint8_t) 0x7F;
			}
			pRxBuffer++;
		}
	}
	return;
}
