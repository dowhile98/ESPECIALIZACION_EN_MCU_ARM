/*
 * File: STM32_MAT_TIM.h
 *
 * Code generated for Simulink model :STM32_MAT.
 *
 * Model version      : 1.1
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Sun Mar  6 21:15:16 2022
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STM32CortexM
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#ifndef RTW_HEADER_STM32_MAT_TIM_h_
#define RTW_HEADER_STM32_MAT_TIM_h_
#include "STM32_Config.h"

/**
 * @brief TIM informations
 */
typedef struct {
  uint32_t TIM_Prescaler;
  uint32_t TIM_APBClock;
  uint32_t TIM_ARR;
  uint32_t TIM_Clock;
  uint32_t TIM_Freq;
  uint8_t CH1_type;
  uint8_t CH2_type;
  uint8_t CH3_type;
  uint8_t CH4_type;
  int32_t CH1_duty;
  int32_t CH2_duty;
  int32_t CH3_duty;
  int32_t CH4_duty;

  /* Input Capture data. */
  uint32_t* ICCData;
  uint32_t ICC1Capture;
  uint32_t ICC1Freq;
  uint32_t ICC1Duty;
  uint32_t ICC2Capture;
  uint32_t ICC2Freq;
  uint32_t ICC2Duty;
  uint32_t ICC3Capture;
  uint32_t ICC3Freq;
  uint32_t ICC3Duty;
  uint32_t ICC4Capture;
  uint32_t ICC4Freq;
  uint32_t ICC4Duty;
  uint16_t ICC1ReadValue1;
  uint16_t ICC1ReadValue2;
  uint16_t ICC1ReadValue3;
  uint16_t ICC1ReadValue4;
  uint16_t ICC2ReadValue1;
  uint16_t ICC2ReadValue2;
  uint16_t ICC2ReadValue3;
  uint16_t ICC2ReadValue4;
  uint16_t ICC3ReadValue1;
  uint16_t ICC3ReadValue2;
  uint16_t ICC3ReadValue3;
  uint16_t ICC3ReadValue4;
  uint16_t ICC4ReadValue1;
  uint16_t ICC4ReadValue2;
  uint16_t ICC4ReadValue3;
  uint16_t ICC4ReadValue4;
  uint8_t ICC1CaptureNumber;
  uint8_t ICC2CaptureNumber;
  uint8_t ICC3CaptureNumber;
  uint8_t ICC4CaptureNumber;
  void (* ItUpFcn)(void);
  void (* ItTrgFcn)(void);
  void (* ItComFcn)(void);
  void (* ItBrkFcn)(void);
  void (* ItCcFcn)(TIM_HandleTypeDef *htim);
} TIM_ConfTypeDef;

typedef enum {
  OUTPUT_COMP = 0,
  OUTPUT_PWM,
  OUTPUT_TRGO,
  OUTPUT_FORCED,
  INPUT_PWM,
  INPUT_CAPTURE,
  INPUT_ETR,
  INPUT_ENCODER,
  INPUT_HALL_SENSOR,
  UNKNOWN
} TIM_ChTypeDef;

/* Number of configured TIMER. */
extern uint16_t G_TIM_Count;

/* Array of TIMER information. */
extern TIM_ConfTypeDef* G_TIM_Conf[1];
extern TIM_HandleTypeDef* G_TIM_Handler[1];

/* TIM2 handler. */
extern TIM_HandleTypeDef htim2;

/* TIM2 informations. */
extern TIM_ConfTypeDef TIM2_Conf;

/* TIM2 polling timeout value. Number of Solver loop. (can be changed). */
extern uint32_t G_TIM2_PollTimeOut;

#endif                                 /* RTW_HEADER_STM32_MAT_TIM_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] STM32_MAT_TIM.h
 */
