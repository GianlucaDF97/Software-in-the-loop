/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaHITL_12_10_gps_ahrs_types.h
 *
 * Code generated for Simulink model 'provaHITL_12_10_gps_ahrs'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 12 17:41:33 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provaHITL_12_10_gps_ahrs_types_h_
#define RTW_HEADER_provaHITL_12_10_gps_ahrs_types_h_
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

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_provaHITL_12_10_gps_T
#define typedef_cell_wrap_provaHITL_12_10_gps_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_provaHITL_12_10_gps_T;

#endif                               /*typedef_cell_wrap_provaHITL_12_10_gps_T*/

#ifndef struct_tag_VxMdwqNJNRwRcuNs0czZ4C
#define struct_tag_VxMdwqNJNRwRcuNs0czZ4C

struct tag_VxMdwqNJNRwRcuNs0czZ4C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_provaHITL_12_10_gps_T inputVarSize;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_VxMdwqNJNRwRcuNs0czZ4C*/

#ifndef typedef_codertarget_arduinobase_int_m_T
#define typedef_codertarget_arduinobase_int_m_T

typedef struct tag_VxMdwqNJNRwRcuNs0czZ4C codertarget_arduinobase_int_m_T;

#endif                               /*typedef_codertarget_arduinobase_int_m_T*/

/* Parameters (default storage) */
typedef struct P_provaHITL_12_10_gps_ahrs_T_ P_provaHITL_12_10_gps_ahrs_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_provaHITL_12_10_gps_a_T RT_MODEL_provaHITL_12_10_gps__T;

#endif                        /* RTW_HEADER_provaHITL_12_10_gps_ahrs_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
