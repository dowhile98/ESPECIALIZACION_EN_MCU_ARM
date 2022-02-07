/*
 * Servo.c
 *
 *  Created on: 6 feb. 2022
 *      Author: Lenovo
 */


#include "Servo.h"

/*************************************************private funtions****************************************/
static void SERVO_PinConfig(Servo_Handle_t *xServo);
static void SERVO_ClockEnable(Servo_Handle_t *xServo);
/**
 * @brief establece el valor del registro CCRx
 */
void SERVO_SetCCRx(Servo_Handle_t *xServo,uint32_t value);

/***************************************PUBLIC FUNCTION***************************************************/
/**
 * @brief configura el timer y el canal a usarse
 */
void SERVO_Init(Servo_Handle_t *xServo){
	uint16_t psc;
	uint32_t arr;
	uint32_t tim_ch = xServo->TIM_CH - 1;
	/*habilitar el reloj*/
	SERVO_ClockEnable(xServo);
	/*configurar el pin */
	SERVO_PinConfig(xServo);
	xServo->pTIM->CR1 &=~(TIM_CR1_CEN);
	/*configurar el timer*/
	/*calculando el PSC y ARR que maximize la resolucion*/
	psc = (uint16_t)(xServo->TIM_PSC/3276800.0);
	arr = (uint32_t)(xServo->TIM_PSC/(50.0*(psc + 1)) - 1U);

	xServo->pTIM->PSC = psc;
	xServo->pTIM->ARR = arr;
	xServo->pTIM->CR1 = 0;
	/*configurando el canal en modo de comparacion de salida*/
	if(tim_ch>=2){
		xServo->pTIM->CCMR2 &=~ (0x3U<<(tim_ch - 2)*8);			//canal configurado como salida
		xServo->pTIM->CCMR2 &=~ (0x7U<<((tim_ch - 2)*8 + 4));
		xServo->pTIM->CCMR2 |= (0x6U<<((tim_ch - 2)*8 + 4));	//PWM MODO 1
	}else{
		xServo->pTIM->CCMR1 &=~ (0x3U<<(tim_ch)*8);			//canal configurado como salida
		xServo->pTIM->CCMR1 &=~ (0x7U<<((tim_ch)*8 + 4));
		xServo->pTIM->CCMR1 |= (0x6U<<((tim_ch)*8 + 4));	//PWM MODO 1
	}
	/*configuracino de la polaridad y se habilita la salida pwm*/
	//xServo->pTIM->CCER = 0;
	xServo->pTIM->CCER |= 1U<<tim_ch*4;
	SERVO_SetCCRx(xServo, 0);
	/*calculando del valor minimo y maximo del periodo*/
	xServo->xServoInfo.Period_Min = (uint16_t)(arr * xServo->MinPulse/20.0);
	xServo->xServoInfo.Period_Max = (uint16_t)(arr * xServo->MaxPulse/20.0);
	/*se inicia contar el timer*/
	xServo->pTIM->CR1 |= TIM_CR1_CEN;
	return;
}

/**
 * @brief establece el angulo del servo
 */
void SERVO_Write(Servo_Handle_t *xServo, float angle){
	uint16_t pulse;

	pulse = (angle*(xServo->xServoInfo.Period_Max - xServo->xServoInfo.Period_Min)/180.0) \
			+ xServo->xServoInfo.Period_Min;
	SERVO_SetCCRx(xServo, pulse);
	return;
}
/**
 * @brief escribe microsegundos al servo
 */
void SERVO_WriteMicroSeconds(Servo_Handle_t *xServo,uint16_t microSeconds){
	uint16_t pulse;
	pulse = (uint16_t)(xServo->pTIM->ARR * microSeconds/20000.0);
	/*comprobar si esta dentro del rango valido para el servo*/
	if(microSeconds>=500 && microSeconds<=2500)
		SERVO_SetCCRx(xServo, pulse);
	return;
}
/**
 * @brief obtiene el pulso minimo
 */
uint16_t SERVO_Get_MinPulse(Servo_Handle_t *xServo){
	return(xServo->xServoInfo.Period_Min);
}

/**
 * @brief obtiene el pulso maximo
 */
uint16_t SERVO_Get_MaxPulse(Servo_Handle_t *xServo){
	return(xServo->xServoInfo.Period_Max);
}
/*************************************************private funtions****************************************/
static void SERVO_PinConfig(Servo_Handle_t *xServo){
	uint8_t pin = xServo->Servo_Pin;
	xServo->pGPIO->MODER &=~(0x3U<<(2*pin));				//reset
	xServo->pGPIO->MODER |= 0x2U<<(2*pin);					//funcion alternativa
	xServo->pGPIO->OSPEEDR |= (0x3U<<(2*pin));				//very high speed
	xServo->pGPIO->PUPDR &=~ (0x3U<<(2*pin));				//no pull up/down
	/*se establece la funcion alternativa*/
	if(pin>7){
		xServo->pGPIO->AFR[1] &=~ (0xFU<<(4*(pin-8)));
		//Se verifica el timer usado
		if(xServo->pTIM == TIM1 || xServo->pTIM == TIM2){
			xServo->pGPIO->AFR[1] |= 1U<<(4*(pin - 8));
		}else if(xServo->pTIM == TIM3 || xServo->pTIM == TIM4 || xServo->pTIM == TIM5){
			xServo->pGPIO->AFR[1] |= 2U<<(4*(pin - 8));
		}else{ //TIM9, TIM10, 11
			xServo->pGPIO->AFR[1] |= 3U<<(4*(pin - 8));
		}
	}else{
		xServo->pGPIO->AFR[0] &=~ (0xFU<<(4*(pin)));
		//Se verifica el timer usado
		if(xServo->pTIM == TIM1 || xServo->pTIM == TIM2){
			xServo->pGPIO->AFR[0] |= 1U<<(4*(pin));
		}else if(xServo->pTIM == TIM3 || xServo->pTIM == TIM4 || xServo->pTIM == TIM5){
			xServo->pGPIO->AFR[0] |= 2U<<(4*(pin ));
		}else{ //TIM9, TIM10, 11
			xServo->pGPIO->AFR[0] |= 3U<<(4*(pin));
		}
	}
	return;
}
static void SERVO_ClockEnable(Servo_Handle_t *xServo){
	/*GPIO CLOCK ENABLE*/
	if(xServo->pGPIO == GPIOA)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	if(xServo->pGPIO == GPIOB)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	if(xServo->pGPIO == GPIOC)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	if(xServo->pGPIO == GPIOD)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	if(xServo->pGPIO == GPIOE)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	if(xServo->pGPIO == GPIOH)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	/*timer clock enable*/
	if(xServo->pTIM == TIM1)
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if(xServo->pTIM == TIM9)
		RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
	if(xServo->pTIM == TIM10)
		RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
	if(xServo->pTIM == TIM11)
		RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
	if(xServo->pTIM == TIM2)
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if(xServo->pTIM == TIM3)
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if(xServo->pTIM == TIM4)
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	if(xServo->pTIM == TIM5)
			RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	return;
}

/**
 * @brief establece el valor del registro CCRx
 */
void SERVO_SetCCRx(Servo_Handle_t *xServo,uint32_t value){
	if(xServo->TIM_CH == 1)
		xServo->pTIM->CCR1 = value;
	if(xServo->TIM_CH == 2)
		xServo->pTIM->CCR2 = value;
	if(xServo->TIM_CH == 3)
		xServo->pTIM->CCR3 = value;
	else
		xServo->pTIM->CCR4 = value;
	return;
}
