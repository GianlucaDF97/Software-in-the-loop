/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prva_09_30_types.h
 *
 * Code generated for Simulink model 'prva_09_30'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 30 17:41:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prva_09_30_types_h_
#define RTW_HEADER_prva_09_30_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_HyyPQh7keCcvrZQqq814NE
#define struct_tag_HyyPQh7keCcvrZQqq814NE

struct tag_HyyPQh7keCcvrZQqq814NE
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_HyyPQh7keCcvrZQqq814NE*/

#ifndef typedef_c_arduinodriver_ArduinoSerial_T
#define typedef_c_arduinodriver_ArduinoSerial_T

typedef struct tag_HyyPQh7keCcvrZQqq814NE c_arduinodriver_ArduinoSerial_T;

#endif                               /*typedef_c_arduinodriver_ArduinoSerial_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_prva_09_30_T
#define typedef_cell_wrap_prva_09_30_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_prva_09_30_T;

#endif                                 /*typedef_cell_wrap_prva_09_30_T*/

#ifndef struct_tag_VxMdwqNJNRwRcuNs0czZ4C
#define struct_tag_VxMdwqNJNRwRcuNs0czZ4C

struct tag_VxMdwqNJNRwRcuNs0czZ4C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_prva_09_30_T inputVarSize;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_VxMdwqNJNRwRcuNs0czZ4C*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_VxMdwqNJNRwRcuNs0czZ4C codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (default storage) */
typedef struct P_prva_09_30_T_ P_prva_09_30_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_prva_09_30_T RT_MODEL_prva_09_30_T;

#endif                                 /* RTW_HEADER_prva_09_30_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
