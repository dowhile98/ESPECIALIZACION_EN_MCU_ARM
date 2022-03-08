/*
 * File: STM32_MAT.h
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

#ifndef RTW_HEADER_STM32_MAT_h_
#define RTW_HEADER_STM32_MAT_h_
#include "STM32_Config.h"
#include "STM32_MAT_External_Functions.h"
#include "STM32_MAT_TIM.h"
#include "STM32_MAT_EXTI.h"
#ifndef STM32_MAT_COMMON_INCLUDES_
# define STM32_MAT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* STM32_MAT_COMMON_INCLUDES_ */

#include "STM32_MAT_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_STM32_MAT {
  const char_T *errorStatus;
};

/* Model entry point functions */
extern void STM32_MAT_initialize(void);
extern void STM32_MAT_step(void);

/* Real-time Model object */
extern RT_MODEL_STM32_MAT *const STM32_MAT_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'STM32_MAT'
 * '<S1>'   : 'STM32_MAT/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_STM32_MAT_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] STM32_MAT.h
 */
