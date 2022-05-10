/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaarduino_private.h
 *
 * Code generated for Simulink model 'provaarduino'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 16:03:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provaarduino_private_h_
#define RTW_HEADER_provaarduino_private_h_
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_microseconds_equilibratore_beta_3_Start_wrapper(real_T *xD);
  extern void Servo_microseconds_equilibratore_beta_3_Outputs_wrapper(const
    int16_T *tau,
    const real_T *xD);
  extern void Servo_microseconds_equilibratore_beta_3_Update_wrapper(const
    int16_T *tau,
    real_T *xD);
  extern void Servo_microseconds_equilibratore_beta_3_Terminate_wrapper(real_T
    *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_microseconds_manetta_beta_3_Start_wrapper(real_T *xD);
  extern void Servo_microseconds_manetta_beta_3_Outputs_wrapper(const int16_T
    *tau,
    const real_T *xD);
  extern void Servo_microseconds_manetta_beta_3_Update_wrapper(const int16_T
    *tau,
    real_T *xD);
  extern void Servo_microseconds_manetta_beta_3_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);

#endif                                 /* RTW_HEADER_provaarduino_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
