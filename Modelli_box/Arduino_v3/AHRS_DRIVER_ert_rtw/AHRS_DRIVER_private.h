/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AHRS_DRIVER_private.h
 *
 * Code generated for Simulink model 'AHRS_DRIVER'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 08:57:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AHRS_DRIVER_private_h_
#define RTW_HEADER_AHRS_DRIVER_private_h_
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void Mti_Start_wrapper(real_T *xD);
  extern void Mti_Outputs_wrapper(uint8_T *messaggio,
    const real_T *xD);
  extern void Mti_Update_wrapper(uint8_T *messaggio,
    real_T *xD);
  extern void Mti_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_AHRS_DRIVER_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
