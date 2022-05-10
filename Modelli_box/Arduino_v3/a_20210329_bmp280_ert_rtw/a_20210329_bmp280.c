/*
 * a_20210329_bmp280.c
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

#include "a_20210329_bmp280.h"
#include "a_20210329_bmp280_private.h"

/* Block signals (default storage) */
B_a_20210329_bmp280_T a_20210329_bmp280_B;

/* Block states (default storage) */
DW_a_20210329_bmp280_T a_20210329_bmp280_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_a_20210329_bmp280_T a_20210329_bmp280_Y;

/* Real-time model */
static RT_MODEL_a_20210329_bmp280_T a_20210329_bmp280_M_;
RT_MODEL_a_20210329_bmp280_T *const a_20210329_bmp280_M = &a_20210329_bmp280_M_;

/* System initialize for enable system: '<Root>/One_time_initialization' */
void a__One_time_initialization_Init(B_One_time_initialization_a_2_T *localB,
  P_One_time_initialization_a_2_T *localP)
{
  int32_T i;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read' incorporates:
   *  Outport: '<S2>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read1' incorporates:
   *  Outport: '<S2>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read2' incorporates:
   *  Outport: '<S2>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read3' incorporates:
   *  Outport: '<S2>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read4' incorporates:
   *  Outport: '<S2>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read5' incorporates:
   *  Outport: '<S2>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read6' incorporates:
   *  Outport: '<S2>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read7' incorporates:
   *  Outport: '<S2>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read8' incorporates:
   *  Outport: '<S2>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read9' incorporates:
   *  Outport: '<S2>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read10' incorporates:
   *  Outport: '<S2>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/I2C Read11' incorporates:
   *  Outport: '<S2>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S2>/Byte Unpack' incorporates:
     *  Outport: '<S2>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Start for enable system: '<Root>/One_time_initialization' */
void a_One_time_initialization_Start(DW_One_time_initialization_a__T *localDW,
  P_One_time_initialization_a_2_T *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_i_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S2>/I2C Read' */
  localDW->obj_f1.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f1;
  localDW->obj_f1.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f1.isInitialized = 0;
  localDW->obj_f1.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f1.matlabCodegenIsDeleted = false;
  localDW->objisempty_p = true;
  localDW->obj_f1.SampleTime = localP->I2CRead_SampleTime;
  obj = &localDW->obj_f1;
  localDW->obj_f1.isSetupComplete = false;
  localDW->obj_f1.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f1.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f1.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f1.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read1' */
  localDW->obj_lm.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_lm;
  localDW->obj_lm.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_lm.isInitialized = 0;
  localDW->obj_lm.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_lm.matlabCodegenIsDeleted = false;
  localDW->objisempty_kg = true;
  localDW->obj_lm.SampleTime = localP->I2CRead1_SampleTime;
  obj = &localDW->obj_lm;
  localDW->obj_lm.isSetupComplete = false;
  localDW->obj_lm.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_lm.BusSpeed = 100000U;
  varargin_1 = localDW->obj_lm.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_lm.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read2' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->objisempty_bn = true;
  localDW->obj_l.SampleTime = localP->I2CRead2_SampleTime;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read3' */
  localDW->obj_ng.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ng;
  localDW->obj_ng.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ng.isInitialized = 0;
  localDW->obj_ng.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ng.matlabCodegenIsDeleted = false;
  localDW->objisempty_b = true;
  localDW->obj_ng.SampleTime = localP->I2CRead3_SampleTime;
  obj = &localDW->obj_ng;
  localDW->obj_ng.isSetupComplete = false;
  localDW->obj_ng.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ng.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ng.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ng.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read4' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->objisempty_n = true;
  localDW->obj_f.SampleTime = localP->I2CRead4_SampleTime;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read5' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  localDW->obj_e.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  localDW->objisempty_h = true;
  localDW->obj_e.SampleTime = localP->I2CRead5_SampleTime;
  obj = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read6' */
  localDW->obj_ny.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ny;
  localDW->obj_ny.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ny.isInitialized = 0;
  localDW->obj_ny.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ny.matlabCodegenIsDeleted = false;
  localDW->objisempty_a = true;
  localDW->obj_ny.SampleTime = localP->I2CRead6_SampleTime;
  obj = &localDW->obj_ny;
  localDW->obj_ny.isSetupComplete = false;
  localDW->obj_ny.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ny.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ny.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ny.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read7' */
  localDW->obj_g.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_g;
  localDW->obj_g.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_g.isInitialized = 0;
  localDW->obj_g.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_g.matlabCodegenIsDeleted = false;
  localDW->objisempty_g = true;
  localDW->obj_g.SampleTime = localP->I2CRead7_SampleTime;
  obj = &localDW->obj_g;
  localDW->obj_g.isSetupComplete = false;
  localDW->obj_g.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_g.BusSpeed = 100000U;
  varargin_1 = localDW->obj_g.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read8' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->objisempty_l = true;
  localDW->obj_n.SampleTime = localP->I2CRead8_SampleTime;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty_m = true;
  localDW->obj.SampleTime = localP->I2CRead9_SampleTime;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read10' */
  localDW->obj_ej.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ej;
  localDW->obj_ej.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ej.isInitialized = 0;
  localDW->obj_ej.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ej.matlabCodegenIsDeleted = false;
  localDW->objisempty_c = true;
  localDW->obj_ej.SampleTime = localP->I2CRead10_SampleTime;
  obj = &localDW->obj_ej;
  localDW->obj_ej.isSetupComplete = false;
  localDW->obj_ej.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ej.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ej.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ej.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read11' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->objisempty_hr = true;
  localDW->obj_o.SampleTime = localP->I2CRead11_SampleTime;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Write1' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->objisempty_oh = true;
  obj_0 = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Write2' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->objisempty_o = true;
  obj_0 = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Write3' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj_0 = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/I2C Read12' */
  localDW->obj_a.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_a;
  localDW->obj_a.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_a.isInitialized = 0;
  localDW->obj_a.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_a.matlabCodegenIsDeleted = false;
  localDW->objisempty_k = true;
  localDW->obj_a.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_a;
  localDW->obj_a.isSetupComplete = false;
  localDW->obj_a.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_a.BusSpeed = 100000U;
  varargin_1 = localDW->obj_a.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_a.isSetupComplete = true;
}

/* Output and update for enable system: '<Root>/One_time_initialization' */
void a_20210_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_a_2_T *localB, DW_One_time_initialization_a__T
  *localDW, P_One_time_initialization_a_2_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<Root>/One_time_initialization' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S2>/I2C Write3' incorporates:
     *  ArithShift: '<S2>/Shift Arithmetic1'
     *  Constant: '<S2>/registro memoria2 '
     *  DataTypeConversion: '<S2>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S2>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S2>/I2C Read' */
    if (localDW->obj_f1.SampleTime != localP->I2CRead_SampleTime) {
      localDW->obj_f1.SampleTime = localP->I2CRead_SampleTime;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f1.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f1.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S2>/I2C Read' */

    /* MATLABSystem: '<S2>/I2C Read1' */
    if (localDW->obj_lm.SampleTime != localP->I2CRead1_SampleTime) {
      localDW->obj_lm.SampleTime = localP->I2CRead1_SampleTime;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_lm.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_lm.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read1' */

    /* MATLABSystem: '<S2>/I2C Read2' */
    if (localDW->obj_l.SampleTime != localP->I2CRead2_SampleTime) {
      localDW->obj_l.SampleTime = localP->I2CRead2_SampleTime;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read2' */

    /* MATLABSystem: '<S2>/I2C Read3' */
    if (localDW->obj_ng.SampleTime != localP->I2CRead3_SampleTime) {
      localDW->obj_ng.SampleTime = localP->I2CRead3_SampleTime;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ng.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ng.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S2>/I2C Read3' */

    /* MATLABSystem: '<S2>/I2C Read4' */
    if (localDW->obj_f.SampleTime != localP->I2CRead4_SampleTime) {
      localDW->obj_f.SampleTime = localP->I2CRead4_SampleTime;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read4' */

    /* MATLABSystem: '<S2>/I2C Read5' */
    if (localDW->obj_e.SampleTime != localP->I2CRead5_SampleTime) {
      localDW->obj_e.SampleTime = localP->I2CRead5_SampleTime;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read5' */

    /* MATLABSystem: '<S2>/I2C Read6' */
    if (localDW->obj_ny.SampleTime != localP->I2CRead6_SampleTime) {
      localDW->obj_ny.SampleTime = localP->I2CRead6_SampleTime;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ny.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ny.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read6' */

    /* MATLABSystem: '<S2>/I2C Read7' */
    if (localDW->obj_g.SampleTime != localP->I2CRead7_SampleTime) {
      localDW->obj_g.SampleTime = localP->I2CRead7_SampleTime;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_g.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_g.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read7' */

    /* MATLABSystem: '<S2>/I2C Read8' */
    if (localDW->obj_n.SampleTime != localP->I2CRead8_SampleTime) {
      localDW->obj_n.SampleTime = localP->I2CRead8_SampleTime;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read8' */

    /* MATLABSystem: '<S2>/I2C Read9' */
    if (localDW->obj.SampleTime != localP->I2CRead9_SampleTime) {
      localDW->obj.SampleTime = localP->I2CRead9_SampleTime;
    }

    status = 154U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead9, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read9' */

    /* MATLABSystem: '<S2>/I2C Read10' */
    if (localDW->obj_ej.SampleTime != localP->I2CRead10_SampleTime) {
      localDW->obj_ej.SampleTime = localP->I2CRead10_SampleTime;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ej.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ej.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read10' */

    /* MATLABSystem: '<S2>/I2C Read11' */
    if (localDW->obj_o.SampleTime != localP->I2CRead11_SampleTime) {
      localDW->obj_o.SampleTime = localP->I2CRead11_SampleTime;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S2>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S2>/I2C Read11' */

    /* MATLABSystem: '<S2>/I2C Write1' incorporates:
     *  Constant: '<S2>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S2>/I2C Write2' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S2>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S2>/I2C Read12' */
    if (localDW->obj_a.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_a.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S2>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S2>/Byte Unpack' */

    /* Unpack: <S2>/Byte Unpack */
    {
      uint32_T MW_inputPortOffset = 0;
      uint32_T MW_outputPortWidth = 0;
      uint32_T MW_remainder2 = 0;

      /* Packed input data type - uint8_T */
      /* Unpacking the values to output 1 */
      /* Output data type - uint16_T, size - 8 */
      {
        MW_outputPortWidth = 8 * sizeof(uint16_T);
        memcpy((uint8_T*)&localB->ByteUnpack[0], (uint8_T*)&localB->I2CRead12[0]
               + MW_inputPortOffset, MW_outputPortWidth);
      }
    }

    srUpdateBC(localDW->One_time_initialization_SubsysR);
  }

  /* End of Outputs for SubSystem: '<Root>/One_time_initialization' */
}

/* Termination for enable system: '<Root>/One_time_initialization' */
void a__One_time_initialization_Term(DW_One_time_initialization_a__T *localDW)
{
  codertarget_arduinobase_int_i_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S2>/I2C Read' */
  obj = &localDW->obj_f1;
  if (!localDW->obj_f1.matlabCodegenIsDeleted) {
    localDW->obj_f1.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f1.isInitialized == 1) && localDW->obj_f1.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read1' */
  obj = &localDW->obj_lm;
  if (!localDW->obj_lm.matlabCodegenIsDeleted) {
    localDW->obj_lm.matlabCodegenIsDeleted = true;
    if ((localDW->obj_lm.isInitialized == 1) && localDW->obj_lm.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read2' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read3' */
  obj = &localDW->obj_ng;
  if (!localDW->obj_ng.matlabCodegenIsDeleted) {
    localDW->obj_ng.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ng.isInitialized == 1) && localDW->obj_ng.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read4' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read5' */
  obj = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read6' */
  obj = &localDW->obj_ny;
  if (!localDW->obj_ny.matlabCodegenIsDeleted) {
    localDW->obj_ny.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ny.isInitialized == 1) && localDW->obj_ny.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read7' */
  obj = &localDW->obj_g;
  if (!localDW->obj_g.matlabCodegenIsDeleted) {
    localDW->obj_g.matlabCodegenIsDeleted = true;
    if ((localDW->obj_g.isInitialized == 1) && localDW->obj_g.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read8' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read10' */
  obj = &localDW->obj_ej;
  if (!localDW->obj_ej.matlabCodegenIsDeleted) {
    localDW->obj_ej.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ej.isInitialized == 1) && localDW->obj_ej.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read11' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S2>/I2C Write1' */
  obj_0 = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S2>/I2C Write2' */
  obj_0 = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S2>/I2C Write3' */
  obj_0 = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S2>/I2C Read12' */
  obj = &localDW->obj_a;
  if (!localDW->obj_a.matlabCodegenIsDeleted) {
    localDW->obj_a.matlabCodegenIsDeleted = true;
    if ((localDW->obj_a.isInitialized == 1) && localDW->obj_a.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Read12' */
}

/* Model step function */
void a_20210329_bmp280_step(void)
{
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  int32_T i;
  uint8_T output_0[3];
  uint8_T output_raw_0[3];
  uint8_T output[2];
  uint8_T output_raw[2];
  uint8_T status;

  /* Reset subsysRan breadcrumbs */
  srClearBC(a_20210329_bmp280_DW.Execution_loop_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR);

  /* Outputs for Enabled SubSystem: '<Root>/One_time_initialization' */
  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  a_20210_One_time_initialization(!(a_20210329_bmp280_DW.UnitDelay_DSTATE != 0.0),
    &a_20210329_bmp280_B.One_time_initialization,
    &a_20210329_bmp280_DW.One_time_initialization,
    &a_20210329_bmp280_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<Root>/One_time_initialization' */

  /* Outport: '<Root>/pwm_max_min ' */
  for (i = 0; i < 8; i++) {
    a_20210329_bmp280_Y.pwm_max_min[i] =
      a_20210329_bmp280_B.One_time_initialization.ByteUnpack[i];
  }

  /* End of Outport: '<Root>/pwm_max_min ' */
  /* Outputs for Enabled SubSystem: '<Root>/Execution_loop' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* UnitDelay: '<Root>/Unit Delay' */
  if (a_20210329_bmp280_DW.UnitDelay_DSTATE > 0.0) {
    /* MATLABSystem: '<S1>/I2C Read12' */
    if (a_20210329_bmp280_DW.obj.SampleTime !=
        a_20210329_bmp280_P.I2CRead12_SampleTime) {
      a_20210329_bmp280_DW.obj.SampleTime =
        a_20210329_bmp280_P.I2CRead12_SampleTime;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (a_20210329_bmp280_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 118U, &status, 1U,
       true, false);
    if (0 == status) {
      MW_I2C_MasterRead(a_20210329_bmp280_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw[0], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
    }

    /* MATLABSystem: '<S1>/I2C Read1' */
    if (a_20210329_bmp280_DW.obj_p.SampleTime !=
        a_20210329_bmp280_P.I2CRead1_SampleTime) {
      a_20210329_bmp280_DW.obj_p.SampleTime =
        a_20210329_bmp280_P.I2CRead1_SampleTime;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (a_20210329_bmp280_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U, &status, 1U,
       true, false);
    if (0 == status) {
      MW_I2C_MasterRead(a_20210329_bmp280_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw_0[0], 3U, false, true);
      memcpy((void *)&output_0[0], (void *)&output_raw_0[0], (uint32_T)((size_t)
              3 * sizeof(uint8_T)));
    } else {
      output_0[0] = 0U;
      output_0[1] = 0U;
      output_0[2] = 0U;
    }

    /* ArithShift: '<S1>/Shift Arithmetic4' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    tmp = floor(a_20210329_bmp280_P.Constant1_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* ArithShift: '<S1>/Shift Arithmetic3' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    tmp_0 = floor(a_20210329_bmp280_P.Constant5_Value);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    /* ArithShift: '<S1>/Shift Arithmetic1' incorporates:
     *  Constant: '<S1>/Constant6'
     */
    tmp_1 = floor(a_20210329_bmp280_P.Constant6_Value);
    if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
      tmp_1 = 0.0;
    } else {
      tmp_1 = fmod(tmp_1, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S1>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S1>/Shift Arithmetic1'
     *  ArithShift: '<S1>/Shift Arithmetic3'
     *  ArithShift: '<S1>/Shift Arithmetic4'
     *  Constant: '<S1>/Constant10'
     *  Constant: '<S1>/Constant11'
     *  Constant: '<S1>/Constant7'
     *  MATLABSystem: '<S1>/I2C Read1'
     *  Sum: '<S1>/Sum1'
     *  Sum: '<S1>/Sum4'
     *  Sum: '<S1>/Sum5'
     *  Sum: '<S1>/Sum6'
     */
    a_20210329_bmp280_B.DataTypeConversion1 = (int32_T)
      ((((((a_20210329_bmp280_P.Constant7_Value + output_0[0]) << (tmp < 0.0 ?
            -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp)) +
          ((a_20210329_bmp280_P.Constant10_Value + output_0[1]) << (tmp_0 < 0.0 ?
            -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0))) +
         a_20210329_bmp280_P.Constant11_Value) + output_0[2]) >> (tmp_1 < 0.0 ?
        -(int32_T)(uint32_T)-tmp_1 : (int32_T)(uint32_T)tmp_1));

    /* ArithShift: '<S1>/Shift Arithmetic7' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    tmp = floor(a_20210329_bmp280_P.Constant2_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* ArithShift: '<S1>/Shift Arithmetic6' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    tmp_0 = floor(a_20210329_bmp280_P.Constant3_Value);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    /* ArithShift: '<S1>/Shift Arithmetic2' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    tmp_1 = floor(a_20210329_bmp280_P.Constant4_Value);
    if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
      tmp_1 = 0.0;
    } else {
      tmp_1 = fmod(tmp_1, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S1>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S1>/Shift Arithmetic2'
     *  ArithShift: '<S1>/Shift Arithmetic6'
     *  ArithShift: '<S1>/Shift Arithmetic7'
     *  Constant: '<S1>/Constant8'
     *  Constant: '<S1>/Constant9'
     *  MATLABSystem: '<S1>/I2C Read12'
     *  Sum: '<S1>/Sum'
     *  Sum: '<S1>/Sum2'
     *  Sum: '<S1>/Sum3'
     */
    a_20210329_bmp280_B.DataTypeConversion = (int32_T)
      ((((a_20210329_bmp280_P.Constant8_Value + output[0]) << (tmp < 0.0 ?
          -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp)) +
        ((a_20210329_bmp280_P.Constant9_Value + output[1]) << (tmp_0 < 0.0 ?
          -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0))) >> (tmp_1 <
        0.0 ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)(uint32_T)tmp_1));

    /* S-Function (calc_T): '<S1>/S-Function Builder' */
    calc_T_Outputs_wrapper(&a_20210329_bmp280_B.One_time_initialization.I2CRead,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead1,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead2,
      &a_20210329_bmp280_B.DataTypeConversion,
      &a_20210329_bmp280_B.SFunctionBuilder_o1,
      &a_20210329_bmp280_B.SFunctionBuilder_o2);

    /* S-Function (calc_p): '<S1>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&a_20210329_bmp280_B.One_time_initialization.I2CRead3,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead4,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead5,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead6,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead7,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead8,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead9,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead10,
      &a_20210329_bmp280_B.One_time_initialization.I2CRead11,
      &a_20210329_bmp280_B.DataTypeConversion1,
      &a_20210329_bmp280_B.SFunctionBuilder_o2,
      &a_20210329_bmp280_B.SFunctionBuilder1);
    srUpdateBC(a_20210329_bmp280_DW.Execution_loop_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/Execution_loop' */
  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Constant: '<Root>/Constant'
   */
  a_20210329_bmp280_DW.UnitDelay_DSTATE = a_20210329_bmp280_P.Constant_Value;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, (real_T)a_20210329_bmp280_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(a_20210329_bmp280_M)!=-1) &&
        !((rtmGetTFinal(a_20210329_bmp280_M)-
           a_20210329_bmp280_M->Timing.taskTime0) >
          a_20210329_bmp280_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(a_20210329_bmp280_M, "Simulation finished");
    }

    if (rtmGetStopRequested(a_20210329_bmp280_M)) {
      rtmSetErrorStatus(a_20210329_bmp280_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++a_20210329_bmp280_M->Timing.clockTick0)) {
    ++a_20210329_bmp280_M->Timing.clockTickH0;
  }

  a_20210329_bmp280_M->Timing.taskTime0 = a_20210329_bmp280_M->Timing.clockTick0
    * a_20210329_bmp280_M->Timing.stepSize0 +
    a_20210329_bmp280_M->Timing.clockTickH0 *
    a_20210329_bmp280_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void a_20210329_bmp280_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)a_20210329_bmp280_M, 0,
                sizeof(RT_MODEL_a_20210329_bmp280_T));
  rtmSetTFinal(a_20210329_bmp280_M, -1);
  a_20210329_bmp280_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  a_20210329_bmp280_M->Sizes.checksums[0] = (1138578962U);
  a_20210329_bmp280_M->Sizes.checksums[1] = (147112733U);
  a_20210329_bmp280_M->Sizes.checksums[2] = (3202962298U);
  a_20210329_bmp280_M->Sizes.checksums[3] = (2202224443U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[21];
    a_20210329_bmp280_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &a_20210329_bmp280_DW.Execution_loop_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &a_20210329_bmp280_DW.Execution_loop_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &a_20210329_bmp280_DW.Execution_loop_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[5] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[6] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[7] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[8] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[9] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[10] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[11] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[12] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[13] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[14] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[15] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[16] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[17] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[18] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[19] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    systemRan[20] = (sysRanDType *)
      &a_20210329_bmp280_DW.One_time_initialization.One_time_initialization_SubsysR;
    rteiSetModelMappingInfoPtr(a_20210329_bmp280_M->extModeInfo,
      &a_20210329_bmp280_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(a_20210329_bmp280_M->extModeInfo,
                        a_20210329_bmp280_M->Sizes.checksums);
    rteiSetTPtr(a_20210329_bmp280_M->extModeInfo, rtmGetTPtr(a_20210329_bmp280_M));
  }

  /* block I/O */
  (void) memset(((void *) &a_20210329_bmp280_B), 0,
                sizeof(B_a_20210329_bmp280_T));

  /* states (dwork) */
  (void) memset((void *)&a_20210329_bmp280_DW, 0,
                sizeof(DW_a_20210329_bmp280_T));

  /* external outputs */
  (void) memset(&a_20210329_bmp280_Y.pwm_max_min[0], 0,
                8U*sizeof(uint16_T));

  {
    uint32_T i2cname;
    codertarget_arduinobase_inter_T *obj;
    uint32_T varargin_1;

    /* Start for Enabled SubSystem: '<Root>/One_time_initialization' */
    a_One_time_initialization_Start
      (&a_20210329_bmp280_DW.One_time_initialization,
       &a_20210329_bmp280_P.One_time_initialization);

    /* End of Start for SubSystem: '<Root>/One_time_initialization' */

    /* Start for Enabled SubSystem: '<Root>/Execution_loop' */
    /* Start for MATLABSystem: '<S1>/I2C Read12' */
    a_20210329_bmp280_DW.obj.matlabCodegenIsDeleted = true;
    obj = &a_20210329_bmp280_DW.obj;
    a_20210329_bmp280_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    a_20210329_bmp280_DW.obj.isInitialized = 0;
    a_20210329_bmp280_DW.obj.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    a_20210329_bmp280_DW.obj.matlabCodegenIsDeleted = false;
    a_20210329_bmp280_DW.objisempty = true;
    a_20210329_bmp280_DW.obj.SampleTime =
      a_20210329_bmp280_P.I2CRead12_SampleTime;
    obj = &a_20210329_bmp280_DW.obj;
    a_20210329_bmp280_DW.obj.isSetupComplete = false;
    a_20210329_bmp280_DW.obj.isInitialized = 1;
    i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    a_20210329_bmp280_DW.obj.BusSpeed = 100000U;
    varargin_1 = a_20210329_bmp280_DW.obj.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    a_20210329_bmp280_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/I2C Read1' */
    a_20210329_bmp280_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &a_20210329_bmp280_DW.obj_p;
    a_20210329_bmp280_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    a_20210329_bmp280_DW.obj_p.isInitialized = 0;
    a_20210329_bmp280_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    a_20210329_bmp280_DW.obj_p.matlabCodegenIsDeleted = false;
    a_20210329_bmp280_DW.objisempty_b = true;
    a_20210329_bmp280_DW.obj_p.SampleTime =
      a_20210329_bmp280_P.I2CRead1_SampleTime;
    obj = &a_20210329_bmp280_DW.obj_p;
    a_20210329_bmp280_DW.obj_p.isSetupComplete = false;
    a_20210329_bmp280_DW.obj_p.isInitialized = 1;
    i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    a_20210329_bmp280_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = a_20210329_bmp280_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    a_20210329_bmp280_DW.obj_p.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/Execution_loop' */
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  a_20210329_bmp280_DW.UnitDelay_DSTATE =
    a_20210329_bmp280_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<Root>/One_time_initialization' */
  a__One_time_initialization_Init(&a_20210329_bmp280_B.One_time_initialization,
    &a_20210329_bmp280_P.One_time_initialization);

  /* End of SystemInitialize for SubSystem: '<Root>/One_time_initialization' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Execution_loop' */
  /* SystemInitialize for S-Function (calc_T): '<S1>/S-Function Builder' incorporates:
   *  Outport: '<S1>/T'
   */
  a_20210329_bmp280_B.SFunctionBuilder_o1 = a_20210329_bmp280_P.T_Y0;

  /* SystemInitialize for S-Function (calc_p): '<S1>/S-Function Builder1' incorporates:
   *  Outport: '<S1>/p'
   */
  a_20210329_bmp280_B.SFunctionBuilder1 = a_20210329_bmp280_P.p_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Execution_loop' */
}

/* Model terminate function */
void a_20210329_bmp280_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<Root>/One_time_initialization' */
  a__One_time_initialization_Term(&a_20210329_bmp280_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<Root>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<Root>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S1>/I2C Read12' */
  obj = &a_20210329_bmp280_DW.obj;
  if (!a_20210329_bmp280_DW.obj.matlabCodegenIsDeleted) {
    a_20210329_bmp280_DW.obj.matlabCodegenIsDeleted = true;
    if ((a_20210329_bmp280_DW.obj.isInitialized == 1) &&
        a_20210329_bmp280_DW.obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S1>/I2C Read1' */
  obj = &a_20210329_bmp280_DW.obj_p;
  if (!a_20210329_bmp280_DW.obj_p.matlabCodegenIsDeleted) {
    a_20210329_bmp280_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((a_20210329_bmp280_DW.obj_p.isInitialized == 1) &&
        a_20210329_bmp280_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/I2C Read1' */
  /* End of Terminate for SubSystem: '<Root>/Execution_loop' */
}
