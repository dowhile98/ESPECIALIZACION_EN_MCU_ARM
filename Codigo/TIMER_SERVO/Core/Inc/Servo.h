/*
 * Servo.h
 *
 *  Created on: 6 feb. 2022
 *      Author: Lenovo
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stm32f4xx.h"


/**
 * strutura para manejar la informacion del servo
 */
typedef struct
{
	uint16_t  Period_Min;
	uint16_t  Period_Max;
}Servo_info_t;
/**
 * estructura para el manejo de servos
 */
typedef struct{
	GPIO_TypeDef *pGPIO;
	uint8_t Servo_Pin;
	TIM_TypeDef *pTIM;
	uint8_t TIM_CH;
	uint32_t TIM_PSC;
	float MinPulse;
	float MaxPulse;
	Servo_info_t xServoInfo;
}Servo_Handle_t;


/**
 * @brief configura el timer y el canal a usarse
 */
void SERVO_Init(Servo_Handle_t *xServo);

/**
 * @brief establece el angulo del servo
 */
void SERVO_Write(Servo_Handle_t *xServo, float angle);
/**
 * @brief escribe microsegundos al servo
 */
void SERVO_WriteMicroSeconds(Servo_Handle_t *xServo,uint16_t microSeconds);
/**
 * @brief obtiene el pulso minimo
 */
uint16_t SERVO_Get_MinPulse(Servo_Handle_t *xServo);

/**
 * @brief obtiene el pulso maximo
 */
uint16_t SERVO_Get_MaxPulse(Servo_Handle_t *xServo);


#endif /* INC_SERVO_H_ */
