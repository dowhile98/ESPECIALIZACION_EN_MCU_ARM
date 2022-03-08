/*
 * File: STM32_MAT.c
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

#include "STM32_MAT.h"
#include "STM32_MAT_private.h"

/* Real-time model */
RT_MODEL_STM32_MAT STM32_MAT_M_;
RT_MODEL_STM32_MAT *const STM32_MAT_M = &STM32_MAT_M_;

/* Model step function */
void STM32_MAT_step(void)
{
  {
    if (((uint16_T)80U) != TIM2_Conf.CH1_duty) {
      TIM2_Conf.CH1_duty = ((uint16_T)80U);
      if (((uint16_T)80U) >= 0) {
        /* Channel1 duty cycle is an input port. */
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(uint32_t)(((uint16_T)500U) *
          (&htim2)->Instance->ARR / 100));
      }
    }
  }
}

/* Model initialize function */
void STM32_MAT_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* TIM2 initialization. */
      /* Store TIM2 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM2_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim2;

      /* Store TIM information. */
      TIM2_Conf.TIM_Prescaler = 0;
      TIM2_Conf.TIM_APBClock = 84000000;
      TIM2_Conf.TIM_ARR = 84000 - 1;
      TIM2_Conf.TIM_Clock = 8.4E+7;
      TIM2_Conf.TIM_Freq = 1000.0;
      TIM2_Conf.CH1_duty = 50;
      TIM2_Conf.CH2_duty = 0.0;
      TIM2_Conf.CH3_duty = 0.0;
      TIM2_Conf.CH4_duty = 0.0;
      TIM2_Conf.CH1_type = OUTPUT_PWM;
      TIM2_Conf.CH2_type = UNKNOWN;
      TIM2_Conf.CH3_type = UNKNOWN;
      TIM2_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM2_Conf.ItUpFcn = NULL;
      TIM2_Conf.ItTrgFcn = NULL;
      TIM2_Conf.ItComFcn = NULL;
      TIM2_Conf.ItBrkFcn = NULL;
      TIM2_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim2)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim2,TIM2_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim2,84000 - 1);

      /* Set CH1 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(uint32_t)(1000));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim2,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */
    {
      /* TIM2 Start. */

      /* Wait for htim2 State READY. */
      while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    }

    {
      /* External interrupt function registering. */
      EXTI_Callback[13] = EXTI13_Callback;
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] STM32_MAT.c
 */
