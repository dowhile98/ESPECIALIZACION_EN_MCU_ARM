/*
 * PID.h
 *
 *  Created on: Dec 11, 2021
 *      Author: Lenovo
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include <string.h>

typedef struct{
	float Kp;
	float Ki;
	float Kd;
	float Kaw;			//ganancia wind up
	float Ts;			//tiempo de muestreo
	float e;			//error;
	float Pk;			//parte proporcional
	float Ik;			//parte integral
	float Dk;			//parte derivativa
	float Wk;			//wind up
	float Vk;
	float Umin;			//valor minimo de salida
	float Umax;			//valor maximo de salida
}PID_Def_t;

/**
 * @brief PID init parameters
 */
void PID_Init(PID_Def_t *pidx,float Kp,float Ki,float Kd,float Ts,float Umin,float Umax);

/**
 * @brief compute pid
 */
float PID_Compute(PID_Def_t *pidx, float Ref, float yk);

#endif /* INC_PID_H_ */
