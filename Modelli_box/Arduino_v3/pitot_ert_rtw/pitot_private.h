/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pitot_private.h
 *
 * Code generated for Simulink model 'pitot'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 25 11:45:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pitot_private_h_
#define RTW_HEADER_pitot_private_h_
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void Risoluzione_12bit_Start_wrapper(real_T *xD);
  extern void Risoluzione_12bit_Outputs_wrapper(const real_T *xD);
  extern void Risoluzione_12bit_Update_wrapper(real_T *xD);
  extern void Risoluzione_12bit_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_pitot_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
