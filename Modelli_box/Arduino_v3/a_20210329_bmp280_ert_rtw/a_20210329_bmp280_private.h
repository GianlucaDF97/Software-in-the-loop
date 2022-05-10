/*
 * a_20210329_bmp280_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210329_bmp280".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Mar 29 17:19:05 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210329_bmp280_private_h_
#define RTW_HEADER_a_20210329_bmp280_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "a_20210329_bmp280.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

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

extern void a__One_time_initialization_Init(B_One_time_initialization_a_2_T
  *localB, P_One_time_initialization_a_2_T *localP);
extern void a_One_time_initialization_Start(DW_One_time_initialization_a__T
  *localDW, P_One_time_initialization_a_2_T *localP);
extern void a_20210_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_a_2_T *localB, DW_One_time_initialization_a__T
  *localDW, P_One_time_initialization_a_2_T *localP);
extern void a__One_time_initialization_Term(DW_One_time_initialization_a__T
  *localDW);

#endif                             /* RTW_HEADER_a_20210329_bmp280_private_h_ */
