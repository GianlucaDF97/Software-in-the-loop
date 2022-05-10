/*
 * a_20210329_bmp280_types.h
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

#ifndef RTW_HEADER_a_20210329_bmp280_types_h_
#define RTW_HEADER_a_20210329_bmp280_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S2>/I2C Write3' */
#include "MW_SVD.h"
#ifndef struct_tag_hNRvEDxDSc9X6cDQ3gk5iB
#define struct_tag_hNRvEDxDSc9X6cDQ3gk5iB

struct tag_hNRvEDxDSc9X6cDQ3gk5iB
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_hNRvEDxDSc9X6cDQ3gk5iB*/

#ifndef typedef_c_arduinodriver_ArduinoI2C_a__T
#define typedef_c_arduinodriver_ArduinoI2C_a__T

typedef struct tag_hNRvEDxDSc9X6cDQ3gk5iB c_arduinodriver_ArduinoI2C_a__T;

#endif                               /*typedef_c_arduinodriver_ArduinoI2C_a__T*/

#ifndef struct_tag_E2Q7mT7TALi8AyIFGt7NpB
#define struct_tag_E2Q7mT7TALi8AyIFGt7NpB

struct tag_E2Q7mT7TALi8AyIFGt7NpB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_a__T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  real_T SampleTime;
};

#endif                                 /*struct_tag_E2Q7mT7TALi8AyIFGt7NpB*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_E2Q7mT7TALi8AyIFGt7NpB codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

#ifndef struct_tag_xW8Ib17ITU95ekBipdoHgD
#define struct_tag_xW8Ib17ITU95ekBipdoHgD

struct tag_xW8Ib17ITU95ekBipdoHgD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_a__T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /*struct_tag_xW8Ib17ITU95ekBipdoHgD*/

#ifndef typedef_codertarget_arduinobase_int_i_T
#define typedef_codertarget_arduinobase_int_i_T

typedef struct tag_xW8Ib17ITU95ekBipdoHgD codertarget_arduinobase_int_i_T;

#endif                               /*typedef_codertarget_arduinobase_int_i_T*/

/* Parameters for system: '<Root>/One_time_initialization' */
typedef struct P_One_time_initialization_a_2_T_ P_One_time_initialization_a_2_T;

/* Parameters (default storage) */
typedef struct P_a_20210329_bmp280_T_ P_a_20210329_bmp280_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_a_20210329_bmp280_T RT_MODEL_a_20210329_bmp280_T;

#endif                               /* RTW_HEADER_a_20210329_bmp280_types_h_ */
