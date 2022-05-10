/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210426_ahrs_private.h
 *
 * Code generated for Simulink model 'a_20210426_ahrs'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Apr 27 15:03:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210426_ahrs_private_h_
#define RTW_HEADER_a_20210426_ahrs_private_h_
#include "rtwtypes.h"

/* Used to reverse endianness */
#define SWAP16(x)                      (((x) >> 8) | (((x) & 0xff) << 8))
#define SWAP32(x)                      (SWAP16((x) >> 16) | (SWAP16((x) & 0xffff) << 16))
#ifdef __cplusplus

extern "C" {

#endif

  extern void Mti_Start_wrapper(real_T *xD);
  extern void Mti_Outputs_wrapper(uint8_T *Messaggio,
    uint8_T *Control,
    const real_T *xD);
  extern void Mti_Update_wrapper(uint8_T *Messaggio,
    uint8_T *Control,
    real_T *xD);
  extern void Mti_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                               /* RTW_HEADER_a_20210426_ahrs_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
