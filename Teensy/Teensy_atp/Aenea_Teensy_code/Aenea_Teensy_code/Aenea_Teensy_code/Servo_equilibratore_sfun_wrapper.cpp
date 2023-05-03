 
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif
 
 
 
/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
 
#ifndef MATLAB_MEX_FILE
#include<Arduino.h>
#include<Servo.h>
 
	Servo myservo1;
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */
 
/*
 * Start function
 *
 */
extern "C" void Servo_equilibratore_sfun_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    myservo1.attach(5); //c'era 10
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void Servo_equilibratore_sfun_Outputs_wrapper(const int16_T *tau,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    myservo1.writeMicroseconds(tau[0]);
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
/*
 * Updates function
 *
 */
extern "C" void Servo_equilibratore_sfun_Update_wrapper(const int16_T *tau,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
 
