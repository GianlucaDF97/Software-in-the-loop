/*
 * a_20210406_testgpssolo_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210406_testgpssolo".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Apr  6 17:29:38 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210406_testgpssolo_types_h_
#define RTW_HEADER_a_20210406_testgpssolo_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

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

#ifndef struct_tag_vJChquI25cIRVK3PayyatE
#define struct_tag_vJChquI25cIRVK3PayyatE

struct tag_vJChquI25cIRVK3PayyatE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Protocol;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_vJChquI25cIRVK3PayyatE*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_vJChquI25cIRVK3PayyatE codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (default storage) */
typedef struct P_a_20210406_testgpssolo_T_ P_a_20210406_testgpssolo_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_a_20210406_testgpssol_T RT_MODEL_a_20210406_testgpsso_T;

#endif                          /* RTW_HEADER_a_20210406_testgpssolo_types_h_ */
