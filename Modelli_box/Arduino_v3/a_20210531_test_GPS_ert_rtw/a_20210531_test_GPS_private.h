/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210531_test_GPS_private.h
 *
 * Code generated for Simulink model 'a_20210531_test_GPS'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jun  1 16:31:17 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210531_test_GPS_private_h_
#define RTW_HEADER_a_20210531_test_GPS_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

extern real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
extern void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n);
extern void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);

#endif                           /* RTW_HEADER_a_20210531_test_GPS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
