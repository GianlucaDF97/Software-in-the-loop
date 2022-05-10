/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1_private.h
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Jun  9 15:57:30 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled1_private_h_
#define RTW_HEADER_untitled1_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Mti_Start_wrapper(real_T *xD);
  extern void Mti_Outputs_wrapper(const real_T *u0,
    uint8_T *message,
    const real_T *xD);
  extern void Mti_Update_wrapper(const real_T *u0,
    uint8_T *message,
    real_T *xD);
  extern void Mti_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_untitled1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
