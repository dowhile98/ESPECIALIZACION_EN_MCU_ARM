/*
 * PID.c
 *
 *  Created on: Dec 11, 2021
 *      Author: Lenovo
 */

#include "PID.h"

/**
 * @brief PID init parameters
 */
void PID_Init(PID_Def_t *pidx,float Kp,float Ki,float Kd,float Ts,float Umin,float Umax){
	memset(pidx,0,sizeof(&pidx));
	pidx->Kp = Kp;
	pidx->Ki = Ki;
	pidx->Kd = Kd;
	pidx->Kaw = Ki/Kp;
	pidx->Ts = Ts;
	pidx->Umin = Umin;
	pidx->Umax = Umax;
}

/**
 * @brief compute pid
 */
float PID_Compute(PID_Def_t *pidx, float Ref, float yk){
	float e_1 = pidx->e;
	float Uk;
	pidx->e = Ref - yk;
	/*parte proporcional*/
	pidx->Pk = pidx->e * pidx->Kp;
	/*parte integral*/
	pidx->Ik += pidx->Ts*pidx->Ki*pidx->e + pidx->Ts*pidx->Kaw*pidx->Wk;
	/*parte derivativa*/
	pidx->Dk = (pidx->Kd/pidx->Ts)*(pidx->e - e_1);
	/*salida pid*/
	pidx->Vk = pidx->Pk + pidx->Ik + pidx->Dk;
	/*saturador*/
	if(pidx->Vk > pidx->Umax)
		Uk = pidx->Umax;
	else if(pidx->Vk < pidx->Umin)
		Uk = pidx->Umin;
	else
		Uk = pidx->Vk;
	/*error wind up*/
	pidx->Wk = Uk - pidx->Vk;

	/*se retorna la salida el valor calculado*/
	return Uk;
}

