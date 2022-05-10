/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_13_types.h
 *
 * Code generated for Simulink model 'load_arduino_v_13'.
 *
 * Model version                  : 1.330
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov  5 15:54:12 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_load_arduino_v_13_types_h_
#define RTW_HEADER_load_arduino_v_13_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Custom Type definition for MATLABSystem: '<S971>/I2C Read' */
#include "MW_SVD.h"
#include <stddef.h>
#ifndef typedef_cell_load_arduino_v_13_T
#define typedef_cell_load_arduino_v_13_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_load_arduino_v_13_T;

#endif                                 /*typedef_cell_load_arduino_v_13_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_load_arduino_v_13_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_b_T
#define typedef_codertarget_arduinobase_int_b_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_int_b_T;

#endif                                 /*typedef_codertarget_arduinobase_int_b_T*/

#ifndef typedef_codertarget_arduinobase_int_m_T
#define typedef_codertarget_arduinobase_int_m_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
} codertarget_arduinobase_int_m_T;

#endif                                 /*typedef_codertarget_arduinobase_int_m_T*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_codertarget_arduinobase_int_j_T
#define typedef_codertarget_arduinobase_int_j_T

typedef struct {
  int32_T isInitialized;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
} codertarget_arduinobase_int_j_T;

#endif                                 /*typedef_codertarget_arduinobase_int_j_T*/

#ifndef typedef_cell_wrap_load_arduino_v_13_T
#define typedef_cell_wrap_load_arduino_v_13_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_load_arduino_v_13_T;

#endif                                 /*typedef_cell_wrap_load_arduino_v_13_T*/

#ifndef typedef_codertarget_arduinobase_in_js_T
#define typedef_codertarget_arduinobase_in_js_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_load_arduino_v_13_T inputVarSize;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
} codertarget_arduinobase_in_js_T;

#endif                                 /*typedef_codertarget_arduinobase_in_js_T*/

/* Parameters for system: '<S750>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_load_ardui_T_ P_EnabledSubsystem_load_ardui_T;

/* Parameters for system: '<S750>/Resettable Subsystem' */
typedef struct P_ResettableSubsystem_load_ar_T_ P_ResettableSubsystem_load_ar_T;

/* Parameters for system: '<S963>/One_time_initialization' */
typedef struct P_One_time_initialization_loa_T_ P_One_time_initialization_loa_T;

/* Parameters (default storage) */
typedef struct P_load_arduino_v_13_T_ P_load_arduino_v_13_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_load_arduino_v_13_T RT_MODEL_load_arduino_v_13_T;

#endif                                 /* RTW_HEADER_load_arduino_v_13_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
