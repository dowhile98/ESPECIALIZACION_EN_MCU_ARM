/*
 * File: SimpleGPIO.c
 *
 * Code generated for Simulink model :SimpleGPIO.
 *
 * Model version      : 1.38
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Sun Mar  6 20:26:03 2022
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. MISRA C:2012 guidelines
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

#include "SimpleGPIO.h"
#include "SimpleGPIO_private.h"

/* Real-time model */
RT_MODEL_SimpleGPIO SimpleGPIO_M_;
RT_MODEL_SimpleGPIO *const SimpleGPIO_M = &SimpleGPIO_M_;

/* Model step function */
void SimpleGPIO_step(void)
{
  /* S-Function (GPIO_Write): '<Root>/GPIO_Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    if (((uint8_T)1U) == 0)
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    else
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
  }
}

/* Model initialize function */
void SimpleGPIO_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SimpleGPIO_M, (NULL));
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] SimpleGPIO.c
 */
