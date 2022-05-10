/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testloaddata_09_27_types.h
 *
 * Code generated for Simulink model 'testloaddata_09_27'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Sep 27 14:18:56 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testloaddata_09_27_types_h_
#define RTW_HEADER_testloaddata_09_27_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_rMOgeynmi8eZKnAJKOv0nC
#define struct_tag_rMOgeynmi8eZKnAJKOv0nC

struct tag_rMOgeynmi8eZKnAJKOv0nC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /*struct_tag_rMOgeynmi8eZKnAJKOv0nC*/

#ifndef typedef_codertarget_linux_blocks_Digi_T
#define typedef_codertarget_linux_blocks_Digi_T

typedef struct tag_rMOgeynmi8eZKnAJKOv0nC codertarget_linux_blocks_Digi_T;

#endif                               /*typedef_codertarget_linux_blocks_Digi_T*/

/* Custom Type definition for MATLABSystem: '<S4>/Serial Read' */
#include "MW_SVD.h"
#ifndef struct_tag_R1xdlxXgEuZ2YKjrgC1tPF
#define struct_tag_R1xdlxXgEuZ2YKjrgC1tPF

struct tag_R1xdlxXgEuZ2YKjrgC1tPF
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_R1xdlxXgEuZ2YKjrgC1tPF*/

#ifndef typedef_e_codertarget_raspi_internal__T
#define typedef_e_codertarget_raspi_internal__T

typedef struct tag_R1xdlxXgEuZ2YKjrgC1tPF e_codertarget_raspi_internal__T;

#endif                               /*typedef_e_codertarget_raspi_internal__T*/

#ifndef struct_tag_PSnzQVOYwaaoehMkVWqS3C
#define struct_tag_PSnzQVOYwaaoehMkVWqS3C

struct tag_PSnzQVOYwaaoehMkVWqS3C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_codertarget_raspi_internal__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_PSnzQVOYwaaoehMkVWqS3C*/

#ifndef typedef_codertarget_raspi_internal_SC_T
#define typedef_codertarget_raspi_internal_SC_T

typedef struct tag_PSnzQVOYwaaoehMkVWqS3C codertarget_raspi_internal_SC_T;

#endif                               /*typedef_codertarget_raspi_internal_SC_T*/

/* Parameters (default storage) */
typedef struct P_testloaddata_09_27_T_ P_testloaddata_09_27_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_testloaddata_09_27_T RT_MODEL_testloaddata_09_27_T;

#endif                              /* RTW_HEADER_testloaddata_09_27_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
