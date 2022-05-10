/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaseriale_noxbee_private.h
 *
 * Code generated for Simulink model 'provaseriale_noxbee'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:56:51 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provaseriale_noxbee_private_h_
#define RTW_HEADER_provaseriale_noxbee_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "provaseriale_noxbee.h"

/* Used to reverse endianness */
#define SWAP16(x)                      (((x) >> 8) | (((x) & 0xff) << 8))
#define SWAP32(x)                      (SWAP16((x) >> 16) | (SWAP16((x) & 0xffff) << 16))
#ifdef __cplusplus

extern "C" {

#endif

  extern void calc_T_Start_wrapper(void);
  extern void calc_T_Outputs_wrapper(const uint16_T *dig_T1,
    const int16_T *dig_T2,
    const int16_T *dig_T3,
    const int32_T *adc_T,
    real32_T *T,
    int32_T *t_fine);
  extern void calc_T_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void calc_p_Start_wrapper(void);
  extern void calc_p_Outputs_wrapper(const uint16_T *dig_p1,
    const int16_T *dig_p2,
    const int16_T *dig_p3,
    const int16_T *dig_p4,
    const int16_T *dig_p5,
    const int16_T *dig_p6,
    const int16_T *dig_p7,
    const int16_T *dig_p8,
    const int16_T *dig_p9,
    const int32_T *adc_P,
    const int32_T *t_fine,
    uint32_T *p);
  extern void calc_p_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

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

extern real_T rt_roundd_snf(real_T u);
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
extern void pr_One_time_initialization_Init(B_One_time_initialization_pro_T
  *localB, DW_One_time_initialization_pr_T *localDW,
  P_One_time_initialization_pro_T *localP);
extern void provase_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_pro_T *localB, DW_One_time_initialization_pr_T
  *localDW, P_One_time_initialization_pro_T *localP);
extern void pr_One_time_initialization_Term(DW_One_time_initialization_pr_T
  *localDW);

#endif                           /* RTW_HEADER_provaseriale_noxbee_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
