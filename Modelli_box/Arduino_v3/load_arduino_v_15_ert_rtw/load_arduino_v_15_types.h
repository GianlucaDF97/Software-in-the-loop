/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_15_types.h
 *
 * Code generated for Simulink model 'load_arduino_v_15'.
 *
 * Model version                  : 5.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Oct 20 16:54:03 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_load_arduino_v_15_types_h_
#define RTW_HEADER_load_arduino_v_15_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S585>/I2C Write3' */
#include "MW_SVD.h"
#ifndef struct_tag_hNRvEDxDSc9X6cDQ3gk5iB
#define struct_tag_hNRvEDxDSc9X6cDQ3gk5iB

struct tag_hNRvEDxDSc9X6cDQ3gk5iB
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_hNRvEDxDSc9X6cDQ3gk5iB*/

#ifndef typedef_c_arduinodriver_ArduinoI2C_lo_T
#define typedef_c_arduinodriver_ArduinoI2C_lo_T

typedef struct tag_hNRvEDxDSc9X6cDQ3gk5iB c_arduinodriver_ArduinoI2C_lo_T;

#endif                               /*typedef_c_arduinodriver_ArduinoI2C_lo_T*/

#ifndef struct_tag_E2Q7mT7TALi8AyIFGt7NpB
#define struct_tag_E2Q7mT7TALi8AyIFGt7NpB

struct tag_E2Q7mT7TALi8AyIFGt7NpB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_lo_T I2CDriverObj;
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
  c_arduinodriver_ArduinoI2C_lo_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /*struct_tag_xW8Ib17ITU95ekBipdoHgD*/

#ifndef typedef_codertarget_arduinobase_int_m_T
#define typedef_codertarget_arduinobase_int_m_T

typedef struct tag_xW8Ib17ITU95ekBipdoHgD codertarget_arduinobase_int_m_T;

#endif                               /*typedef_codertarget_arduinobase_int_m_T*/

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

#ifndef struct_tag_CI5KDzeK8eRdVMkrjyn9aB
#define struct_tag_CI5KDzeK8eRdVMkrjyn9aB

struct tag_CI5KDzeK8eRdVMkrjyn9aB
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_CI5KDzeK8eRdVMkrjyn9aB*/

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_CI5KDzeK8eRdVMkrjyn9aB b_arduinodriver_ArduinoDigita_T;

#endif                               /*typedef_b_arduinodriver_ArduinoDigita_T*/

#ifndef struct_tag_JWD6fNxPJmGmyMV4L0MUi
#define struct_tag_JWD6fNxPJmGmyMV4L0MUi

struct tag_JWD6fNxPJmGmyMV4L0MUi
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /*struct_tag_JWD6fNxPJmGmyMV4L0MUi*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_JWD6fNxPJmGmyMV4L0MUi codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

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

#ifndef typedef_codertarget_arduinobase_int_h_T
#define typedef_codertarget_arduinobase_int_h_T

typedef struct tag_vJChquI25cIRVK3PayyatE codertarget_arduinobase_int_h_T;

#endif                               /*typedef_codertarget_arduinobase_int_h_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_load_arduino_v_15_T
#define typedef_cell_wrap_load_arduino_v_15_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_load_arduino_v_15_T;

#endif                                 /*typedef_cell_wrap_load_arduino_v_15_T*/

#ifndef struct_tag_VxMdwqNJNRwRcuNs0czZ4C
#define struct_tag_VxMdwqNJNRwRcuNs0czZ4C

struct tag_VxMdwqNJNRwRcuNs0czZ4C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_load_arduino_v_15_T inputVarSize;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_VxMdwqNJNRwRcuNs0czZ4C*/

#ifndef typedef_codertarget_arduinobase_in_hb_T
#define typedef_codertarget_arduinobase_in_hb_T

typedef struct tag_VxMdwqNJNRwRcuNs0czZ4C codertarget_arduinobase_in_hb_T;

#endif                               /*typedef_codertarget_arduinobase_in_hb_T*/

/* Parameters for system: '<S422>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_load_ardui_T_ P_EnabledSubsystem_load_ardui_T;

/* Parameters for system: '<S422>/Resettable Subsystem' */
typedef struct P_ResettableSubsystem_load_ar_T_ P_ResettableSubsystem_load_ar_T;

/* Parameters for system: '<S578>/One_time_initialization' */
typedef struct P_One_time_initialization_loa_T_ P_One_time_initialization_loa_T;

/* Parameters (default storage) */
typedef struct P_load_arduino_v_15_T_ P_load_arduino_v_15_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_load_arduino_v_15_T RT_MODEL_load_arduino_v_15_T;

#endif                               /* RTW_HEADER_load_arduino_v_15_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
