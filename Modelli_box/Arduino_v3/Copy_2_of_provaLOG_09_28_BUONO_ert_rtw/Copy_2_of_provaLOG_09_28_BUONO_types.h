/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_2_of_provaLOG_09_28_BUONO_types.h
 *
 * Code generated for Simulink model 'Copy_2_of_provaLOG_09_28_BUONO'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Nov 26 16:21:05 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_2_of_provaLOG_09_28_BUONO_types_h_
#define RTW_HEADER_Copy_2_of_provaLOG_09_28_BUONO_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S38>/I2C Write3' */
#include "MW_SVD.h"
#ifndef struct_tag_hNRvEDxDSc9X6cDQ3gk5iB
#define struct_tag_hNRvEDxDSc9X6cDQ3gk5iB

struct tag_hNRvEDxDSc9X6cDQ3gk5iB
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_hNRvEDxDSc9X6cDQ3gk5iB*/

#ifndef typedef_c_arduinodriver_ArduinoI2C_Co_T
#define typedef_c_arduinodriver_ArduinoI2C_Co_T

typedef struct tag_hNRvEDxDSc9X6cDQ3gk5iB c_arduinodriver_ArduinoI2C_Co_T;

#endif                               /*typedef_c_arduinodriver_ArduinoI2C_Co_T*/

#ifndef struct_tag_E2Q7mT7TALi8AyIFGt7NpB
#define struct_tag_E2Q7mT7TALi8AyIFGt7NpB

struct tag_E2Q7mT7TALi8AyIFGt7NpB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_Co_T I2CDriverObj;
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
  c_arduinodriver_ArduinoI2C_Co_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /*struct_tag_xW8Ib17ITU95ekBipdoHgD*/

#ifndef typedef_codertarget_arduinobase_int_j_T
#define typedef_codertarget_arduinobase_int_j_T

typedef struct tag_xW8Ib17ITU95ekBipdoHgD codertarget_arduinobase_int_j_T;

#endif                               /*typedef_codertarget_arduinobase_int_j_T*/

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

#ifndef typedef_codertarget_arduinobase_int_g_T
#define typedef_codertarget_arduinobase_int_g_T

typedef struct tag_vJChquI25cIRVK3PayyatE codertarget_arduinobase_int_g_T;

#endif                               /*typedef_codertarget_arduinobase_int_g_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_Copy_2_of_provaLOG__T
#define typedef_cell_wrap_Copy_2_of_provaLOG__T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_Copy_2_of_provaLOG__T;

#endif                               /*typedef_cell_wrap_Copy_2_of_provaLOG__T*/

#ifndef struct_tag_VxMdwqNJNRwRcuNs0czZ4C
#define struct_tag_VxMdwqNJNRwRcuNs0czZ4C

struct tag_VxMdwqNJNRwRcuNs0czZ4C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Copy_2_of_provaLOG__T inputVarSize;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_VxMdwqNJNRwRcuNs0czZ4C*/

#ifndef typedef_codertarget_arduinobase_in_gw_T
#define typedef_codertarget_arduinobase_in_gw_T

typedef struct tag_VxMdwqNJNRwRcuNs0czZ4C codertarget_arduinobase_in_gw_T;

#endif                               /*typedef_codertarget_arduinobase_in_gw_T*/

/* Parameters for system: '<S3>/One_time_initialization' */
typedef struct P_One_time_initialization_Cop_T_ P_One_time_initialization_Cop_T;

/* Parameters (default storage) */
typedef struct P_Copy_2_of_provaLOG_09_28_BU_T_ P_Copy_2_of_provaLOG_09_28_BU_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Copy_2_of_provaLOG_09_T RT_MODEL_Copy_2_of_provaLOG_0_T;

#endif                  /* RTW_HEADER_Copy_2_of_provaLOG_09_28_BUONO_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
