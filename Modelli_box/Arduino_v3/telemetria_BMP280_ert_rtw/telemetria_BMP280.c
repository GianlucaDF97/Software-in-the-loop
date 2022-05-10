/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: telemetria_BMP280.c
 *
 * Code generated for Simulink model 'telemetria_BMP280'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 22 17:20:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "telemetria_BMP280.h"
#include "telemetria_BMP280_private.h"

const uint16_T telemetria_BMP280_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_telemetria_BMP280_T telemetria_BMP280_B;

/* Block states (default storage) */
DW_telemetria_BMP280_T telemetria_BMP280_DW;

/* Real-time model */
static RT_MODEL_telemetria_BMP280_T telemetria_BMP280_M_;
RT_MODEL_telemetria_BMP280_T *const telemetria_BMP280_M = &telemetria_BMP280_M_;

/* Forward declaration for local functions */
static void telemetria_BMP280_find_254(const uint8_T pack[100], real_T position
  [3], real_T *counter);
static boolean_T telemetria_BMP280_ifWhileCond(const boolean_T x[100]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void telemetria_BMP280_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(telemetria_BMP280_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (telemetria_BMP280_M->Timing.TaskCounters.TID[1])++;
  if ((telemetria_BMP280_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    telemetria_BMP280_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_tel_T *localB,
  DW_One_time_initialization_te_T *localDW, P_One_time_initialization_tel_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S31>/I2C Read' */
  localDW->obj_n0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n0;
  localDW->obj_n0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n0.isInitialized = 0;
  localDW->obj_n0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n0.matlabCodegenIsDeleted = false;
  localDW->obj_n0.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_n0;
  localDW->obj_n0.isSetupComplete = false;
  localDW->obj_n0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read1' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read2' */
  localDW->obj_ba.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ba;
  localDW->obj_ba.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ba.isInitialized = 0;
  localDW->obj_ba.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ba.matlabCodegenIsDeleted = false;
  localDW->obj_ba.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_ba;
  localDW->obj_ba.isSetupComplete = false;
  localDW->obj_ba.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ba.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ba.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ba.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read3' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read4' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read5' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read6' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read7' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read8' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read10' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read11' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = telemetria_BMP280_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Write1' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Write2' */
  localDW->obj_n4.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_n4;
  localDW->obj_n4.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n4.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n4.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_n4;
  localDW->obj_n4.isSetupComplete = false;
  localDW->obj_n4.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n4.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n4.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n4.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Write3' */
  localDW->obj_ff.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_ff;
  localDW->obj_ff.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ff.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ff.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_ff;
  localDW->obj_ff.isSetupComplete = false;
  localDW->obj_ff.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ff.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ff.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ff.isSetupComplete = true;

  /* Start for MATLABSystem: '<S31>/I2C Read12' */
  localDW->obj_h.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_h;
  localDW->obj_h.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_h.isInitialized = 0;
  localDW->obj_h.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_h.matlabCodegenIsDeleted = false;
  localDW->obj_h.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_h;
  localDW->obj_h.isSetupComplete = false;
  localDW->obj_h.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_h.BusSpeed = 100000U;
  varargin_1 = localDW->obj_h.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_h.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read' incorporates:
   *  Outport: '<S31>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read1' incorporates:
   *  Outport: '<S31>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read2' incorporates:
   *  Outport: '<S31>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read3' incorporates:
   *  Outport: '<S31>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read4' incorporates:
   *  Outport: '<S31>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read5' incorporates:
   *  Outport: '<S31>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read6' incorporates:
   *  Outport: '<S31>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read7' incorporates:
   *  Outport: '<S31>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read8' incorporates:
   *  Outport: '<S31>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read9' incorporates:
   *  Outport: '<S31>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read10' incorporates:
   *  Outport: '<S31>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S31>/I2C Read11' incorporates:
   *  Outport: '<S31>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S31>/Byte Unpack' incorporates:
     *  Outport: '<S31>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S3>/One_time_initialization' */
void tel_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_tel_T *localB, DW_One_time_initialization_te_T
  *localDW, P_One_time_initialization_tel_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S31>/I2C Write3' incorporates:
     *  ArithShift: '<S31>/Shift Arithmetic1'
     *  Constant: '<S31>/registro memoria2 '
     *  DataTypeConversion: '<S31>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S31>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S31>/I2C Read' */
    if (localDW->obj_n0.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_n0.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_n0.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_n0.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S31>/I2C Read' */

    /* MATLABSystem: '<S31>/I2C Read1' */
    if (localDW->obj_d.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_d.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read1' */

    /* MATLABSystem: '<S31>/I2C Read2' */
    if (localDW->obj_ba.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_ba.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ba.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ba.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read2' */

    /* MATLABSystem: '<S31>/I2C Read3' */
    if (localDW->obj_o.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_o.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S31>/I2C Read3' */

    /* MATLABSystem: '<S31>/I2C Read4' */
    if (localDW->obj_i.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_i.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read4' */

    /* MATLABSystem: '<S31>/I2C Read5' */
    if (localDW->obj_n.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_n.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read5' */

    /* MATLABSystem: '<S31>/I2C Read6' */
    if (localDW->obj_m.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_m.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read6' */

    /* MATLABSystem: '<S31>/I2C Read7' */
    if (localDW->obj_b.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_b.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read7' */

    /* MATLABSystem: '<S31>/I2C Read8' */
    if (localDW->obj_l.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_l.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read8' */

    /* MATLABSystem: '<S31>/I2C Read9' */
    if (localDW->obj.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj.SampleTime = telemetria_BMP280_P.t_AP;
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
      /* MATLABSystem: '<S31>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read9' */

    /* MATLABSystem: '<S31>/I2C Read10' */
    if (localDW->obj_f.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_f.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read10' */

    /* MATLABSystem: '<S31>/I2C Read11' */
    if (localDW->obj_p.SampleTime != telemetria_BMP280_P.t_AP) {
      localDW->obj_p.SampleTime = telemetria_BMP280_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S31>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S31>/I2C Read11' */

    /* MATLABSystem: '<S31>/I2C Write1' incorporates:
     *  Constant: '<S31>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S31>/I2C Write2' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_n4.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S31>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_ff.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S31>/I2C Read12' */
    if (localDW->obj_h.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_h.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S31>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S31>/Byte Unpack' */

    /* Unpack: <S31>/Byte Unpack */
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
  }

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */
}

/* Termination for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Term(DW_One_time_initialization_te_T *localDW)
{
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S31>/I2C Read' */
  obj = &localDW->obj_n0;
  if (!localDW->obj_n0.matlabCodegenIsDeleted) {
    localDW->obj_n0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n0.isInitialized == 1) && localDW->obj_n0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read1' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read2' */
  obj = &localDW->obj_ba;
  if (!localDW->obj_ba.matlabCodegenIsDeleted) {
    localDW->obj_ba.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ba.isInitialized == 1) && localDW->obj_ba.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read3' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read4' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read5' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read6' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read7' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read8' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read10' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read11' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S31>/I2C Write1' */
  obj_0 = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S31>/I2C Write2' */
  obj_0 = &localDW->obj_n4;
  if (!localDW->obj_n4.matlabCodegenIsDeleted) {
    localDW->obj_n4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n4.isInitialized == 1) && localDW->obj_n4.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S31>/I2C Write3' */
  obj_0 = &localDW->obj_ff;
  if (!localDW->obj_ff.matlabCodegenIsDeleted) {
    localDW->obj_ff.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ff.isInitialized == 1) && localDW->obj_ff.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S31>/I2C Read12' */
  obj = &localDW->obj_h;
  if (!localDW->obj_h.matlabCodegenIsDeleted) {
    localDW->obj_h.matlabCodegenIsDeleted = true;
    if ((localDW->obj_h.isInitialized == 1) && localDW->obj_h.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void telemetria_BMP280_find_254(const uint8_T pack[100], real_T position
  [3], real_T *counter)
{
  int32_T i;
  int32_T tmp;
  uint8_T tmp_0;
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
  *counter = 0.0;
  for (i = 0; i < 100; i++) {
    if (pack[i] == 254) {
      (*counter)++;
      position[(int32_T)*counter - 1] = (real_T)i + 1.0;
    }
  }

  if (*counter > 1.0) {
    i = (int32_T)position[0];
    tmp = (int32_T)(pack[i] + 8U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    i += tmp;
    if (i < 256) {
      tmp_0 = (uint8_T)i;
    } else {
      tmp_0 = MAX_uint8_T;
    }

    if ((pack[tmp_0 - 1] != 254) && (position[0] != 0.0)) {
      *counter = 1.0;
      position[1] = 0.0;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static boolean_T telemetria_BMP280_ifWhileCond(const boolean_T x[100])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 100)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void telemetria_BMP280_step0(void)     /* Sample time: [0.02s, 0.0s] */
{
  int32_T exitg3;
  real32_T tmp;
  uint32_T qY;
  uint16_T x;
  uint16_T z;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T output[3];
  uint8_T output_raw_0[3];
  uint8_T output_raw[2];
  uint8_T rtb_H_mav[2];
  uint8_T c;
  uint8_T counter;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T rtb_HiddenBuf_InsertedFor_One_t;
  boolean_T y;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&telemetria_BMP280_P.Constant1_Value_h,
    &telemetria_BMP280_B.SFunctionBuilder_o1_e[0],
    &telemetria_BMP280_B.SFunctionBuilder_o2,
    &telemetria_BMP280_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  telemetria_BMP280_B.status = 0;
  telemetria_BMP280_B.caso = 0;
  memset(&telemetria_BMP280_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  memset(&telemetria_BMP280_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  telemetria_BMP280_find_254(telemetria_BMP280_B.SFunctionBuilder_o1_e,
    telemetria_BMP280_B.poss_254, &telemetria_BMP280_B.num_254);
  if (telemetria_BMP280_DW.Interr_parz && (telemetria_BMP280_B.num_254 == 1.0))
  {
    telemetria_BMP280_B.f = (int32_T)(telemetria_BMP280_DW.counter_b + 1U);
    if (telemetria_BMP280_DW.counter_b + 1U > 255U) {
      telemetria_BMP280_B.f = 255;
    }

    if (telemetria_BMP280_B.poss_254[0] != telemetria_BMP280_B.f) {
      telemetria_BMP280_B.num_254 = 0.0;
    }
  }

  y = !telemetria_BMP280_DW.Interr_parz;
  if ((telemetria_BMP280_B.num_254 == 1.0) && y) {
    telemetria_BMP280_B.caso = 1;
  } else if ((telemetria_BMP280_B.num_254 == 0.0) &&
             telemetria_BMP280_DW.Interr_parz) {
    telemetria_BMP280_B.caso = 2;
  } else if ((telemetria_BMP280_B.num_254 == 1.0) &&
             telemetria_BMP280_DW.Interr_parz) {
    telemetria_BMP280_B.caso = 3;
  } else {
    if ((telemetria_BMP280_B.num_254 == 2.0) && y) {
      telemetria_BMP280_B.caso = 4;
    }
  }

  switch (telemetria_BMP280_B.caso) {
   case 1:
    telemetria_BMP280_B.RateTransition = telemetria_BMP280_B.poss_254[(int32_T)
      telemetria_BMP280_B.num_254 - 1];
    if (telemetria_BMP280_B.RateTransition == 100.0) {
      telemetria_BMP280_DW.message[0] =
        telemetria_BMP280_B.SFunctionBuilder_o1_e[99];
      telemetria_BMP280_DW.Interr_parz = true;
    } else if (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
               (telemetria_BMP280_B.RateTransition + 1.0) - 1] <= 100) {
      telemetria_BMP280_B.f = (int32_T)
        (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
         (telemetria_BMP280_B.poss_254[0] + 1.0) - 1] + 8U);
      telemetria_BMP280_B.g = telemetria_BMP280_B.f;
      if ((uint32_T)telemetria_BMP280_B.f > 255U) {
        telemetria_BMP280_B.g = 255;
      }

      if (telemetria_BMP280_B.g == telemetria_BMP280_B.SFunctionBuilder_o2) {
        telemetria_BMP280_B.num_254 = rt_roundd_snf
          (telemetria_BMP280_B.RateTransition);
        if (telemetria_BMP280_B.num_254 < 256.0) {
          if (telemetria_BMP280_B.num_254 >= 0.0) {
            counter = (uint8_T)telemetria_BMP280_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        telemetria_BMP280_B.f = (int32_T)
          (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
           (telemetria_BMP280_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)telemetria_BMP280_B.f > 255U) {
          telemetria_BMP280_B.f = 255;
        }

        telemetria_BMP280_B.RateTransition = rt_roundd_snf
          (telemetria_BMP280_B.RateTransition + (real_T)telemetria_BMP280_B.f);
        if (telemetria_BMP280_B.RateTransition < 256.0) {
          if (telemetria_BMP280_B.RateTransition >= 0.0) {
            c = (uint8_T)telemetria_BMP280_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          telemetria_BMP280_B.status = 0;
          telemetria_BMP280_B.f = 0;
        } else {
          telemetria_BMP280_B.status = counter - 1;
          telemetria_BMP280_B.f = c;
        }

        telemetria_BMP280_B.caso = telemetria_BMP280_B.f -
          telemetria_BMP280_B.status;
        for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <
             telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
          telemetria_BMP280_DW.message[telemetria_BMP280_B.f] =
            telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.status
            + telemetria_BMP280_B.f];
        }

        telemetria_BMP280_B.status = 1;
        for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 100;
             telemetria_BMP280_B.caso++) {
          telemetria_BMP280_B.messaggio[telemetria_BMP280_B.caso] =
            telemetria_BMP280_DW.message[telemetria_BMP280_B.caso];
          telemetria_BMP280_DW.message[telemetria_BMP280_B.caso] = 0U;
        }

        telemetria_BMP280_DW.counter_b = 0U;
        telemetria_BMP280_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)telemetria_BMP280_B.f > 255U) {
          telemetria_BMP280_B.f = 255;
        }

        if (telemetria_BMP280_B.f > telemetria_BMP280_B.SFunctionBuilder_o2) {
          telemetria_BMP280_DW.mess_len =
            telemetria_BMP280_B.SFunctionBuilder_o2;
          if (telemetria_BMP280_B.RateTransition > telemetria_BMP280_DW.mess_len)
          {
            telemetria_BMP280_B.g = 0;
            telemetria_BMP280_B.f = 0;
          } else {
            telemetria_BMP280_B.g = (int32_T)telemetria_BMP280_B.RateTransition
              - 1;
            telemetria_BMP280_B.f = (int32_T)telemetria_BMP280_DW.mess_len;
          }

          telemetria_BMP280_B.caso = telemetria_BMP280_B.f -
            telemetria_BMP280_B.g;
          for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <
               telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
            telemetria_BMP280_DW.message[telemetria_BMP280_B.f] =
              telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.g +
              telemetria_BMP280_B.f];
          }

          telemetria_BMP280_B.f = (int32_T)
            (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
             (telemetria_BMP280_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)telemetria_BMP280_B.f > 255U) {
            telemetria_BMP280_B.f = 255;
          }

          telemetria_BMP280_B.RateTransition = rt_roundd_snf((real_T)
            telemetria_BMP280_B.f - telemetria_BMP280_DW.mess_len);
          if (telemetria_BMP280_B.RateTransition < 256.0) {
            if (telemetria_BMP280_B.RateTransition >= 0.0) {
              telemetria_BMP280_DW.counter_b = (uint8_T)
                telemetria_BMP280_B.RateTransition;
            } else {
              telemetria_BMP280_DW.counter_b = 0U;
            }
          } else {
            telemetria_BMP280_DW.counter_b = MAX_uint8_T;
          }

          telemetria_BMP280_DW.Interr_parz = true;
        }
      }
    } else {
      telemetria_BMP280_DW.Interr_parz = false;
      memset(&telemetria_BMP280_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_BMP280_DW.counter_b = 0U;
      telemetria_BMP280_DW.mess_len = 0.0;
      telemetria_BMP280_B.status = 1;
    }
    break;

   case 2:
    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.x[telemetria_BMP280_B.f] =
        (telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.f] != 0);
    }

    if (telemetria_BMP280_ifWhileCond(telemetria_BMP280_B.x)) {
      telemetria_BMP280_B.RateTransition = rt_roundd_snf
        (telemetria_BMP280_DW.mess_len + 1.0);
      if (telemetria_BMP280_B.RateTransition < 256.0) {
        if (telemetria_BMP280_B.RateTransition >= 0.0) {
          c = (uint8_T)telemetria_BMP280_B.RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      telemetria_BMP280_B.RateTransition = rt_roundd_snf
        (telemetria_BMP280_DW.mess_len + (real_T)telemetria_BMP280_DW.counter_b);
      if (telemetria_BMP280_B.RateTransition < 256.0) {
        if (telemetria_BMP280_B.RateTransition >= 0.0) {
          counter = (uint8_T)telemetria_BMP280_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (c > counter) {
        telemetria_BMP280_B.status = 1;
      } else {
        telemetria_BMP280_B.status = c;
      }

      if (1 > telemetria_BMP280_DW.counter_b) {
        telemetria_BMP280_B.caso = -1;
      } else {
        telemetria_BMP280_B.caso = telemetria_BMP280_DW.counter_b - 1;
      }

      for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <=
           telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
        telemetria_BMP280_DW.message[(telemetria_BMP280_B.status +
          telemetria_BMP280_B.f) - 1] =
          telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.f];
      }

      telemetria_BMP280_DW.Interr_parz = false;
      telemetria_BMP280_B.status = 1;
      for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 100;
           telemetria_BMP280_B.caso++) {
        telemetria_BMP280_B.messaggio[telemetria_BMP280_B.caso] =
          telemetria_BMP280_DW.message[telemetria_BMP280_B.caso];
        telemetria_BMP280_DW.message[telemetria_BMP280_B.caso] = 0U;
      }

      telemetria_BMP280_DW.mess_len = 0.0;
      telemetria_BMP280_DW.counter_b = 0U;
    } else {
      telemetria_BMP280_DW.Interr_parz = false;
      telemetria_BMP280_B.status = 1;
      memset(&telemetria_BMP280_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_BMP280_DW.mess_len = 0.0;
      telemetria_BMP280_DW.counter_b = 0U;
    }
    break;

   case 3:
    telemetria_BMP280_B.RateTransition = rt_roundd_snf
      (telemetria_BMP280_DW.mess_len + 1.0);
    if (telemetria_BMP280_B.RateTransition < 256.0) {
      if (telemetria_BMP280_B.RateTransition >= 0.0) {
        c = (uint8_T)telemetria_BMP280_B.RateTransition;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    telemetria_BMP280_B.RateTransition = rt_roundd_snf
      (telemetria_BMP280_DW.mess_len + (real_T)telemetria_BMP280_DW.counter_b);
    if (telemetria_BMP280_B.RateTransition < 256.0) {
      if (telemetria_BMP280_B.RateTransition >= 0.0) {
        counter = (uint8_T)telemetria_BMP280_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (c > counter) {
      telemetria_BMP280_B.status = 1;
    } else {
      telemetria_BMP280_B.status = c;
    }

    if (1 > telemetria_BMP280_DW.counter_b) {
      telemetria_BMP280_B.caso = -1;
    } else {
      telemetria_BMP280_B.caso = telemetria_BMP280_DW.counter_b - 1;
    }

    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <=
         telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
      telemetria_BMP280_DW.message[(telemetria_BMP280_B.status +
        telemetria_BMP280_B.f) - 1] =
        telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.f];
    }

    telemetria_BMP280_DW.Interr_parz = false;
    telemetria_BMP280_B.status = 1;
    for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 100;
         telemetria_BMP280_B.caso++) {
      telemetria_BMP280_B.messaggio[telemetria_BMP280_B.caso] =
        telemetria_BMP280_DW.message[telemetria_BMP280_B.caso];
      telemetria_BMP280_DW.message[telemetria_BMP280_B.caso] = 0U;
    }

    telemetria_BMP280_DW.mess_len = 0.0;
    telemetria_BMP280_DW.counter_b = 0U;
    telemetria_BMP280_B.f = (int32_T)(telemetria_BMP280_B.poss_254[(int32_T)
      telemetria_BMP280_B.num_254 - 1] + 1.0) - 1;
    if (telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.f] <= 100)
    {
      telemetria_BMP280_B.g = (int32_T)
        (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
         (telemetria_BMP280_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)telemetria_BMP280_B.g > 255U) {
        telemetria_BMP280_B.g = 255;
      }

      telemetria_BMP280_B.caso = telemetria_BMP280_B.SFunctionBuilder_o2;
      if (telemetria_BMP280_B.SFunctionBuilder_o2 < 0) {
        telemetria_BMP280_B.caso = 0;
      } else {
        if (telemetria_BMP280_B.SFunctionBuilder_o2 > 255) {
          telemetria_BMP280_B.caso = 255;
        }
      }

      if (telemetria_BMP280_B.g == telemetria_BMP280_B.caso) {
        telemetria_BMP280_B.RateTransition = rt_roundd_snf
          (telemetria_BMP280_B.poss_254[(int32_T)telemetria_BMP280_B.num_254 - 1]);
        if (telemetria_BMP280_B.RateTransition < 256.0) {
          if (telemetria_BMP280_B.RateTransition >= 0.0) {
            counter = (uint8_T)telemetria_BMP280_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        telemetria_BMP280_B.f = (int32_T)
          (telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.f] + 7U);
        if ((uint32_T)telemetria_BMP280_B.f > 255U) {
          telemetria_BMP280_B.f = 255;
        }

        telemetria_BMP280_B.RateTransition = rt_roundd_snf
          (telemetria_BMP280_B.poss_254[(int32_T)telemetria_BMP280_B.num_254 - 1]
           + (real_T)telemetria_BMP280_B.f);
        if (telemetria_BMP280_B.RateTransition < 256.0) {
          if (telemetria_BMP280_B.RateTransition >= 0.0) {
            c = (uint8_T)telemetria_BMP280_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          telemetria_BMP280_B.g = 0;
          telemetria_BMP280_B.f = 0;
        } else {
          telemetria_BMP280_B.g = counter - 1;
          telemetria_BMP280_B.f = c;
        }

        telemetria_BMP280_B.caso = telemetria_BMP280_B.f - telemetria_BMP280_B.g;
        for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <
             telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
          telemetria_BMP280_DW.message[telemetria_BMP280_B.f] =
            telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.g +
            telemetria_BMP280_B.f];
        }

        for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 100;
             telemetria_BMP280_B.caso++) {
          telemetria_BMP280_B.messaggio_2[telemetria_BMP280_B.caso] =
            telemetria_BMP280_DW.message[telemetria_BMP280_B.caso];
          telemetria_BMP280_DW.message[telemetria_BMP280_B.caso] = 0U;
        }

        telemetria_BMP280_DW.counter_b = 0U;
        telemetria_BMP280_DW.mess_len = 0.0;
      } else {
        telemetria_BMP280_B.g = (int32_T)
          (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
           (telemetria_BMP280_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)telemetria_BMP280_B.g > 255U) {
          telemetria_BMP280_B.g = 255;
        }

        telemetria_BMP280_B.caso = telemetria_BMP280_B.SFunctionBuilder_o2;
        if (telemetria_BMP280_B.SFunctionBuilder_o2 < 0) {
          telemetria_BMP280_B.caso = 0;
        } else {
          if (telemetria_BMP280_B.SFunctionBuilder_o2 > 255) {
            telemetria_BMP280_B.caso = 255;
          }
        }

        if (telemetria_BMP280_B.g > telemetria_BMP280_B.caso) {
          telemetria_BMP280_DW.mess_len =
            telemetria_BMP280_B.SFunctionBuilder_o2;
          if (telemetria_BMP280_B.poss_254[(int32_T)telemetria_BMP280_B.num_254
              - 1] > telemetria_BMP280_DW.mess_len) {
            telemetria_BMP280_B.x_m = 0;
            telemetria_BMP280_B.caso = 0;
          } else {
            telemetria_BMP280_B.x_m = (int32_T)telemetria_BMP280_B.poss_254
              [(int32_T)telemetria_BMP280_B.num_254 - 1] - 1;
            telemetria_BMP280_B.caso = (int32_T)telemetria_BMP280_DW.mess_len;
          }

          telemetria_BMP280_B.caso -= telemetria_BMP280_B.x_m;
          for (telemetria_BMP280_B.g = 0; telemetria_BMP280_B.g <
               telemetria_BMP280_B.caso; telemetria_BMP280_B.g++) {
            telemetria_BMP280_DW.message[telemetria_BMP280_B.g] =
              telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.x_m
              + telemetria_BMP280_B.g];
          }

          telemetria_BMP280_B.f = (int32_T)
            (telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.f] +
             8U);
          if ((uint32_T)telemetria_BMP280_B.f > 255U) {
            telemetria_BMP280_B.f = 255;
          }

          telemetria_BMP280_B.RateTransition = rt_roundd_snf((real_T)
            telemetria_BMP280_B.f - telemetria_BMP280_DW.mess_len);
          if (telemetria_BMP280_B.RateTransition < 256.0) {
            if (telemetria_BMP280_B.RateTransition >= 0.0) {
              telemetria_BMP280_DW.counter_b = (uint8_T)
                telemetria_BMP280_B.RateTransition;
            } else {
              telemetria_BMP280_DW.counter_b = 0U;
            }
          } else {
            telemetria_BMP280_DW.counter_b = MAX_uint8_T;
          }

          telemetria_BMP280_DW.Interr_parz = true;
        }
      }
    } else {
      telemetria_BMP280_DW.Interr_parz = false;
      memset(&telemetria_BMP280_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      memset(&telemetria_BMP280_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_BMP280_DW.counter_b = 0U;
      telemetria_BMP280_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
        (telemetria_BMP280_B.poss_254[0] + 1.0) - 1] <= 100) {
      telemetria_BMP280_B.RateTransition = rt_roundd_snf
        (telemetria_BMP280_B.poss_254[0]);
      if (telemetria_BMP280_B.RateTransition < 256.0) {
        if (telemetria_BMP280_B.RateTransition >= 0.0) {
          counter = (uint8_T)telemetria_BMP280_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      telemetria_BMP280_B.f = (int32_T)
        (telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
         (telemetria_BMP280_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)telemetria_BMP280_B.f > 255U) {
        telemetria_BMP280_B.f = 255;
      }

      telemetria_BMP280_B.RateTransition = rt_roundd_snf
        (telemetria_BMP280_B.poss_254[0] + (real_T)telemetria_BMP280_B.f);
      if (telemetria_BMP280_B.RateTransition < 256.0) {
        if (telemetria_BMP280_B.RateTransition >= 0.0) {
          c = (uint8_T)telemetria_BMP280_B.RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      if (counter > c) {
        telemetria_BMP280_B.status = 0;
        telemetria_BMP280_B.f = 0;
      } else {
        telemetria_BMP280_B.status = counter - 1;
        telemetria_BMP280_B.f = c;
      }

      telemetria_BMP280_B.caso = telemetria_BMP280_B.f -
        telemetria_BMP280_B.status;
      for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <
           telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
        telemetria_BMP280_B.messaggio[telemetria_BMP280_B.f] =
          telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.status +
          telemetria_BMP280_B.f];
      }
    } else {
      telemetria_BMP280_DW.Interr_parz = false;
      memset(&telemetria_BMP280_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    telemetria_BMP280_B.status = 1;
    if ((telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
         (telemetria_BMP280_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (telemetria_BMP280_B.poss_254[1] - telemetria_BMP280_B.poss_254[0] > 3.0))
    {
      telemetria_BMP280_B.RateTransition = rt_roundd_snf((real_T)
        telemetria_BMP280_B.SFunctionBuilder_o2 - telemetria_BMP280_B.poss_254[1]);
      qY = telemetria_BMP280_B.SFunctionBuilder_o1_e[(int32_T)
        (telemetria_BMP280_B.poss_254[1] + 1.0) - 1];
      telemetria_BMP280_B.f = (int32_T)(qY + 7U);
      if (qY + 7U > 255U) {
        telemetria_BMP280_B.f = 255;
      }

      if (telemetria_BMP280_B.RateTransition < 2.147483648E+9) {
        if (telemetria_BMP280_B.RateTransition >= -2.147483648E+9) {
          telemetria_BMP280_B.g = (int32_T)telemetria_BMP280_B.RateTransition;
        } else {
          telemetria_BMP280_B.g = MIN_int32_T;
        }
      } else {
        telemetria_BMP280_B.g = MAX_int32_T;
      }

      if (telemetria_BMP280_B.g == telemetria_BMP280_B.f) {
        telemetria_BMP280_B.RateTransition = rt_roundd_snf
          (telemetria_BMP280_B.poss_254[1]);
        if (telemetria_BMP280_B.RateTransition < 256.0) {
          if (telemetria_BMP280_B.RateTransition >= 0.0) {
            counter = (uint8_T)telemetria_BMP280_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        telemetria_BMP280_B.f = (int32_T)(qY + 7U);
        if (qY + 7U > 255U) {
          telemetria_BMP280_B.f = 255;
        }

        telemetria_BMP280_B.RateTransition = rt_roundd_snf
          (telemetria_BMP280_B.poss_254[1] + (real_T)telemetria_BMP280_B.f);
        if (telemetria_BMP280_B.RateTransition < 256.0) {
          if (telemetria_BMP280_B.RateTransition >= 0.0) {
            c = (uint8_T)telemetria_BMP280_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          telemetria_BMP280_B.status = 0;
          telemetria_BMP280_B.f = 0;
        } else {
          telemetria_BMP280_B.status = counter - 1;
          telemetria_BMP280_B.f = c;
        }

        telemetria_BMP280_B.caso = telemetria_BMP280_B.f -
          telemetria_BMP280_B.status;
        for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <
             telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
          telemetria_BMP280_DW.message[telemetria_BMP280_B.f] =
            telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.status
            + telemetria_BMP280_B.f];
        }

        telemetria_BMP280_B.status = 2;
        for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 100;
             telemetria_BMP280_B.caso++) {
          telemetria_BMP280_B.messaggio_2[telemetria_BMP280_B.caso] =
            telemetria_BMP280_DW.message[telemetria_BMP280_B.caso];
          telemetria_BMP280_DW.message[telemetria_BMP280_B.caso] = 0U;
        }

        telemetria_BMP280_DW.counter_b = 0U;
        telemetria_BMP280_DW.mess_len = 0.0;
      } else {
        telemetria_BMP280_B.RateTransition = rt_roundd_snf
          (telemetria_BMP280_B.poss_254[1]);
        if (telemetria_BMP280_B.RateTransition < 2.147483648E+9) {
          if (telemetria_BMP280_B.RateTransition >= -2.147483648E+9) {
            telemetria_BMP280_B.f = (int32_T)telemetria_BMP280_B.RateTransition;
          } else {
            telemetria_BMP280_B.f = MIN_int32_T;
          }
        } else {
          telemetria_BMP280_B.f = MAX_int32_T;
        }

        if (telemetria_BMP280_B.f > telemetria_BMP280_B.SFunctionBuilder_o2) {
          telemetria_BMP280_B.f = -1;
          telemetria_BMP280_B.caso = 0;
        } else {
          telemetria_BMP280_B.f -= 2;
          telemetria_BMP280_B.caso = telemetria_BMP280_B.SFunctionBuilder_o2;
        }

        telemetria_BMP280_DW.mess_len = (int8_T)((telemetria_BMP280_B.caso -
          telemetria_BMP280_B.f) - 1);
        if (telemetria_BMP280_B.RateTransition < 2.147483648E+9) {
          if (telemetria_BMP280_B.RateTransition >= -2.147483648E+9) {
            telemetria_BMP280_B.f = (int32_T)telemetria_BMP280_B.RateTransition;
          } else {
            telemetria_BMP280_B.f = MIN_int32_T;
          }
        } else {
          telemetria_BMP280_B.f = MAX_int32_T;
        }

        if (telemetria_BMP280_B.f > telemetria_BMP280_B.SFunctionBuilder_o2) {
          telemetria_BMP280_B.g = 0;
          telemetria_BMP280_B.f = 0;
        } else {
          telemetria_BMP280_B.g = telemetria_BMP280_B.f - 1;
          telemetria_BMP280_B.f = telemetria_BMP280_B.SFunctionBuilder_o2;
        }

        telemetria_BMP280_B.caso = telemetria_BMP280_B.f - telemetria_BMP280_B.g;
        for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f <
             telemetria_BMP280_B.caso; telemetria_BMP280_B.f++) {
          telemetria_BMP280_DW.message[telemetria_BMP280_B.f] =
            telemetria_BMP280_B.SFunctionBuilder_o1_e[telemetria_BMP280_B.g +
            telemetria_BMP280_B.f];
        }

        telemetria_BMP280_B.f = (int32_T)(qY + 8U);
        if (qY + 8U > 255U) {
          telemetria_BMP280_B.f = 255;
        }

        telemetria_BMP280_B.RateTransition = rt_roundd_snf((real_T)
          telemetria_BMP280_B.f - telemetria_BMP280_DW.mess_len);
        if (telemetria_BMP280_B.RateTransition < 256.0) {
          if (telemetria_BMP280_B.RateTransition >= 0.0) {
            telemetria_BMP280_DW.counter_b = (uint8_T)
              telemetria_BMP280_B.RateTransition;
          } else {
            telemetria_BMP280_DW.counter_b = 0U;
          }
        } else {
          telemetria_BMP280_DW.counter_b = MAX_uint8_T;
        }

        telemetria_BMP280_DW.Interr_parz = true;
      }
    } else {
      telemetria_BMP280_DW.Interr_parz = false;
      memset(&telemetria_BMP280_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_BMP280_DW.counter_b = 0U;
      telemetria_BMP280_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&telemetria_BMP280_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
       telemetria_BMP280_B.f++) {
    telemetria_BMP280_B.buffer[3 * telemetria_BMP280_B.f] = 0U;
  }

  for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
       telemetria_BMP280_B.f++) {
    for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 2;
         telemetria_BMP280_B.caso++) {
      telemetria_BMP280_B.g = 3 * telemetria_BMP280_B.f +
        telemetria_BMP280_B.caso;
      telemetria_BMP280_B.buffer[telemetria_BMP280_B.g + 1] =
        telemetria_BMP280_DW.Memory4_PreviousInput[telemetria_BMP280_B.g];
    }
  }

  telemetria_BMP280_B.caso = 3;
  exitg1 = false;
  while ((!exitg1) && (telemetria_BMP280_B.caso >= 1)) {
    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.x[telemetria_BMP280_B.f] =
        (telemetria_BMP280_B.buffer[(3 * telemetria_BMP280_B.f +
          telemetria_BMP280_B.caso) - 1] == 0);
    }

    y = true;
    telemetria_BMP280_B.f = 0;
    exitg2 = false;
    while ((!exitg2) && (telemetria_BMP280_B.f < 100)) {
      if (!telemetria_BMP280_B.x[telemetria_BMP280_B.f]) {
        y = false;
        exitg2 = true;
      } else {
        telemetria_BMP280_B.f++;
      }
    }

    if (y) {
      counter = (uint8_T)telemetria_BMP280_B.caso;
      exitg1 = true;
    } else {
      telemetria_BMP280_B.caso--;
    }
  }

  if (telemetria_BMP280_B.status == 1) {
    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.buffer[(counter + 3 * telemetria_BMP280_B.f) - 1] =
        telemetria_BMP280_B.messaggio[telemetria_BMP280_B.f];
    }
  } else if (telemetria_BMP280_B.status == 2) {
    qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      qY = 0U;
    }

    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.buffer[(counter + 3 * telemetria_BMP280_B.f) - 1] =
        telemetria_BMP280_B.messaggio[telemetria_BMP280_B.f];
      telemetria_BMP280_B.buffer[((int32_T)qY + 3 * telemetria_BMP280_B.f) - 1] =
        telemetria_BMP280_B.messaggio_2[telemetria_BMP280_B.f];
    }
  } else {
    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.buffer[(counter + 3 * telemetria_BMP280_B.f) - 1] = 0U;
    }
  }

  for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
       telemetria_BMP280_B.f++) {
    telemetria_BMP280_B.mess_out[telemetria_BMP280_B.f] =
      telemetria_BMP280_DW.Memory4_PreviousInput[3 * telemetria_BMP280_B.f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  telemetria_BMP280_B.Add = telemetria_BMP280_DW.Memory4_PreviousInput[5] +
    telemetria_BMP280_P.Constant_Value_j;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (telemetria_BMP280_B.mess_out[2] !=
      telemetria_BMP280_DW.Memory5_PreviousInput[2]) {
    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 100;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.x[telemetria_BMP280_B.f] =
        (telemetria_BMP280_B.mess_out[telemetria_BMP280_B.f] != 0);
    }

    y = true;
    telemetria_BMP280_B.f = 0;
    exitg1 = false;
    while ((!exitg1) && (telemetria_BMP280_B.f < 100)) {
      if (!telemetria_BMP280_B.x[telemetria_BMP280_B.f]) {
        y = false;
        exitg1 = true;
      } else {
        telemetria_BMP280_B.f++;
      }
    }

    if (!y) {
      if (telemetria_BMP280_DW.counter > 100) {
        telemetria_BMP280_DW.counter = 0U;
      }

      qY = telemetria_BMP280_DW.counter + 1U;
      if (telemetria_BMP280_DW.counter + 1U > 65535U) {
        qY = 65535U;
      }

      telemetria_BMP280_DW.counter = (uint16_T)qY;
    }
  }

  telemetria_BMP280_B.new_mex = telemetria_BMP280_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  telemetria_BMP280_B.Memory1[0] = telemetria_BMP280_DW.Memory1_PreviousInput_m
    [0];
  telemetria_BMP280_B.Memory1[1] = telemetria_BMP280_DW.Memory1_PreviousInput_m
    [1];

  /* Memory: '<Root>/Memory' */
  telemetria_BMP280_B.Memory_k[0] = telemetria_BMP280_DW.Memory_PreviousInput_m
    [0];
  telemetria_BMP280_B.Memory_k[1] = telemetria_BMP280_DW.Memory_PreviousInput_m
    [1];
  telemetria_BMP280_B.Memory_k[2] = telemetria_BMP280_DW.Memory_PreviousInput_m
    [2];
  telemetria_BMP280_B.Memory_k[3] = telemetria_BMP280_DW.Memory_PreviousInput_m
    [3];

  /* Memory: '<S1>/Memory3' */
  telemetria_BMP280_B.Memory3 = telemetria_BMP280_DW.Memory3_PreviousInput;
  for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 8;
       telemetria_BMP280_B.caso++) {
    /* Memory: '<S1>/Memory' */
    telemetria_BMP280_B.Memory[telemetria_BMP280_B.caso] =
      telemetria_BMP280_DW.Memory_PreviousInput_e[telemetria_BMP280_B.caso];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&telemetria_BMP280_B.mess_out[0], &telemetria_BMP280_B.Add,
     &telemetria_BMP280_B.new_mex, &telemetria_BMP280_P.SIUAVuint8_Value,
     &telemetria_BMP280_B.Memory[0], &telemetria_BMP280_B.Memory1[0],
     &telemetria_BMP280_B.Memory_k[0], &telemetria_BMP280_B.Memory3,
     &telemetria_BMP280_B.SFunction_o1[0], &telemetria_BMP280_B.SFunction_o2,
     &telemetria_BMP280_B.SFunction_o3_f, &telemetria_BMP280_B.SFunction_o4_j[0],
     &telemetria_BMP280_B.SFunction_o5[0], &telemetria_BMP280_B.SFunction_o6,
     &telemetria_BMP280_B.SFunction_o7[0], &telemetria_BMP280_B.SFunction_o8,
     &telemetria_BMP280_B.SFunction_o9[0], &telemetria_BMP280_B.SFunction_o10[0],
     &telemetria_BMP280_B.SFunction_o11[0], &telemetria_BMP280_B.SFunction_o12,
     &telemetria_BMP280_B.SFunction_o13, &telemetria_BMP280_B.SFunction_o14,
     &telemetria_BMP280_B.SFunction_o15, &telemetria_BMP280_B.SFunction_o16,
     &telemetria_BMP280_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 9;
       telemetria_BMP280_B.caso++) {
    telemetria_BMP280_B.Memory2[telemetria_BMP280_B.caso] =
      telemetria_BMP280_DW.Memory2_PreviousInput_a[telemetria_BMP280_B.caso];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 6;
       telemetria_BMP280_B.caso++) {
    telemetria_BMP280_B.WP_info_in[telemetria_BMP280_B.caso] =
      telemetria_BMP280_B.SFunction_o9[telemetria_BMP280_B.caso];
  }

  if ((!telemetria_BMP280_DW.WP_dbP_not_empty) ||
      ((telemetria_BMP280_B.SFunction_o7[0] == 3) &&
       (telemetria_BMP280_B.SFunction_o7[1] == 250))) {
    memset(&telemetria_BMP280_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    telemetria_BMP280_DW.WP_dbP_not_empty = true;
    memset(&telemetria_BMP280_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!telemetria_BMP280_DW.WP_dbP_AL_not_empty) ||
      ((telemetria_BMP280_B.SFunction_o7[0] == 3) &&
       (telemetria_BMP280_B.SFunction_o7[1] == 250))) {
    memset(&telemetria_BMP280_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    telemetria_BMP280_DW.WP_dbP_AL_not_empty = true;
  }

  telemetria_BMP280_B.GC_info[0] = telemetria_BMP280_B.SFunction_o7[0];
  telemetria_BMP280_B.GC_info[1] = telemetria_BMP280_B.SFunction_o7[1];
  telemetria_BMP280_B.GC_info[2] = telemetria_BMP280_B.SFunction_o11[0];
  if (telemetria_BMP280_B.GC_info[0] == 1) {
    if ((telemetria_BMP280_B.GC_info[1] > 0) && (telemetria_BMP280_B.GC_info[1] <=
         7)) {
      if ((real32_T)fabs(telemetria_BMP280_B.SFunction_o8) > 0.0F) {
        telemetria_BMP280_DW.riferimenti[telemetria_BMP280_B.GC_info[1] - 1] =
          1.0F;
      } else {
        if (telemetria_BMP280_B.SFunction_o8 == 0.0F) {
          telemetria_BMP280_DW.riferimenti[telemetria_BMP280_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((telemetria_BMP280_B.GC_info[1] > 7) && (telemetria_BMP280_B.GC_info[1]
           < 12)) {
        telemetria_BMP280_DW.riferimenti[telemetria_BMP280_B.GC_info[1] - 1] =
          telemetria_BMP280_B.SFunction_o8;
      }
    }
  }

  if (telemetria_BMP280_B.SFunction_o12 == 13) {
    telemetria_BMP280_DW.riferimenti[telemetria_BMP280_B.SFunction_o12 - 1] =
      telemetria_BMP280_B.SFunction_o13;
  }

  memcpy(&telemetria_BMP280_B.Val_out_MAV[0], &telemetria_BMP280_DW.riferimenti
         [0], sizeof(real32_T) << 4U);
  if ((telemetria_BMP280_B.GC_info[0] == 3) && (telemetria_BMP280_B.GC_info[1] ==
       200)) {
    if (telemetria_BMP280_B.SFunction_o9[0] > 6) {
      telemetria_BMP280_B.WP_info_in[0] = 6U;
    }

    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 6;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_DW.WP_dbI[telemetria_BMP280_B.f] =
        telemetria_BMP280_B.WP_info_in[0];
    }
  }

  if ((telemetria_BMP280_B.GC_info[0] == 3) && (telemetria_BMP280_B.GC_info[1] <
       200)) {
    if (telemetria_BMP280_B.SFunction_o10[1] == 0.0F) {
      qY = telemetria_BMP280_B.SFunction_o9[1] + 1U;
      if (telemetria_BMP280_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 7;
           telemetria_BMP280_B.f++) {
        telemetria_BMP280_DW.WP_dbP[((int32_T)qY + 6 * telemetria_BMP280_B.f) -
          1] = telemetria_BMP280_B.SFunction_o10[telemetria_BMP280_B.f];
      }

      qY = telemetria_BMP280_B.SFunction_o9[1] + 1U;
      if (telemetria_BMP280_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 6;
           telemetria_BMP280_B.f++) {
        telemetria_BMP280_DW.WP_dbI[((int32_T)qY + 6 * (telemetria_BMP280_B.f +
          1)) - 1] = telemetria_BMP280_B.WP_info_in[telemetria_BMP280_B.f + 1];
      }
    } else {
      telemetria_BMP280_B.f = (int32_T)(telemetria_BMP280_B.SFunction_o10[0] +
        1.0F);
      for (telemetria_BMP280_B.g = 0; telemetria_BMP280_B.g < 7;
           telemetria_BMP280_B.g++) {
        telemetria_BMP280_DW.WP_dbP_AL[(telemetria_BMP280_B.f + 6 *
          telemetria_BMP280_B.g) - 1] =
          telemetria_BMP280_B.SFunction_o10[telemetria_BMP280_B.g];
      }

      qY = telemetria_BMP280_B.SFunction_o9[1] + 1U;
      if (telemetria_BMP280_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 6;
           telemetria_BMP280_B.f++) {
        telemetria_BMP280_DW.WP_dbI[((int32_T)qY + 6 * (telemetria_BMP280_B.f +
          1)) - 1] = telemetria_BMP280_B.WP_info_in[telemetria_BMP280_B.f + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  telemetria_BMP280_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((telemetria_BMP280_B.SFunction_o6 == 0) &&
      (telemetria_BMP280_B.SFunction_o3_f == 0)) {
    telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 0U;
    telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_BMP280_DW.Memory3_PreviousInput = 0U;
  } else if ((telemetria_BMP280_B.SFunction_o6 == 0) &&
             (telemetria_BMP280_B.SFunction_o3_f == 3)) {
    telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 0U;
    telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_BMP280_DW.Memory3_PreviousInput = 0U;
    telemetria_BMP280_DW.test1 = 0.0;
  } else if ((telemetria_BMP280_B.SFunction_o6 == 0) &&
             (telemetria_BMP280_B.SFunction_o3_f == 2)) {
    telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 0U;
    telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_BMP280_DW.Memory3_PreviousInput = 0U;
    telemetria_BMP280_DW.test1 = 0.0;
  } else if ((telemetria_BMP280_B.SFunction_o6 == 0) &&
             (telemetria_BMP280_B.SFunction_o3_f == 1)) {
    telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 0U;
    telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_BMP280_DW.Memory3_PreviousInput = 0U;
    telemetria_BMP280_DW.test1 = 1.0;
  } else {
    switch (telemetria_BMP280_B.SFunction_o6) {
     case 192:
      telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 192U;
      telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      telemetria_BMP280_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 208U;
      telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      telemetria_BMP280_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((telemetria_BMP280_B.SFunction_o6 == 220) &&
          (telemetria_BMP280_B.SFunction_o3_f != 5)) {
        if ((telemetria_BMP280_B.Memory2[0] == 0) &&
            (telemetria_BMP280_B.Memory2[1] == 0) &&
            ((telemetria_BMP280_B.Memory2[2] == 1) ||
             (telemetria_BMP280_B.Memory2[3] == 1) ||
             (telemetria_BMP280_B.Memory2[4] == 1) ||
             (telemetria_BMP280_B.Memory2[5] == 1) ||
             (telemetria_BMP280_B.Memory2[6] == 1) ||
             (telemetria_BMP280_B.Memory2[7] == 1))) {
          telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 220U;
          telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          telemetria_BMP280_DW.Memory3_PreviousInput = 220U;
        } else if ((telemetria_BMP280_B.Memory2[0] == 0) &&
                   (telemetria_BMP280_B.Memory2[1] == 1) &&
                   ((telemetria_BMP280_B.Memory2[2] == 1) ||
                    (telemetria_BMP280_B.Memory2[3] == 1) ||
                    (telemetria_BMP280_B.Memory2[4] == 1) ||
                    (telemetria_BMP280_B.Memory2[5] == 1) ||
                    (telemetria_BMP280_B.Memory2[6] == 1) ||
                    (telemetria_BMP280_B.Memory2[7] == 1))) {
          telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 220U;
          telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          telemetria_BMP280_DW.Memory3_PreviousInput = 220U;
        } else {
          telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 208U;
          telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          telemetria_BMP280_DW.Memory3_PreviousInput = 208U;
        }
      } else if (telemetria_BMP280_B.SFunction_o3_f == 5) {
        telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 220U;
        telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        telemetria_BMP280_DW.Memory1_PreviousInput_m[0] = 192U;
        telemetria_BMP280_DW.Memory1_PreviousInput_m[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  qY = 100U * telemetria_BMP280_B.SFunction_o11[5];
  if (qY > 65535U) {
    qY = 65535U;
  }

  if (telemetria_BMP280_B.SFunction_o11[4] == 0) {
    if ((uint16_T)qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(telemetria_BMP280_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
                   (uint32_T)(uint16_T)qY / telemetria_BMP280_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)z *
      telemetria_BMP280_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)telemetria_BMP280_B.SFunction_o11[4]
          >> 1) + (telemetria_BMP280_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  /* RateTransition: '<S20>/Rate Transition' */
  telemetria_BMP280_B.RateTransition =
    telemetria_BMP280_DW.RateTransition_Buffer0;

  /* Sum: '<S20>/Add1' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Constant3'
   *  Memory: '<S20>/Memory1'
   */
  telemetria_BMP280_B.num_254 = (telemetria_BMP280_P.Constant2_Value_c +
    telemetria_BMP280_P.Constant3_Value_b) +
    telemetria_BMP280_DW.Memory1_PreviousInput;

  /* Switch: '<S20>/Switch' */
  if (telemetria_BMP280_B.num_254 > telemetria_BMP280_P.Switch_Threshold) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant2'
     */
    telemetria_BMP280_DW.Memory1_PreviousInput =
      telemetria_BMP280_P.Constant2_Value_c;
  } else {
    /* Switch: '<S20>/Switch' */
    telemetria_BMP280_DW.Memory1_PreviousInput = telemetria_BMP280_B.num_254;
  }

  /* End of Switch: '<S20>/Switch' */

  /* MATLAB Function: '<S12>/iflogic_function' */
  if ((telemetria_BMP280_DW.Memory1_PreviousInput == 1.0) ||
      (telemetria_BMP280_DW.Memory1_PreviousInput == 3.0)) {
    telemetria_BMP280_B.iflogic = 26U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 2.0) ||
             (telemetria_BMP280_DW.Memory1_PreviousInput == 4.0)) {
    telemetria_BMP280_B.iflogic = 30U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             (telemetria_BMP280_B.RateTransition == 2.0)) {
    telemetria_BMP280_B.iflogic = 33U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             (telemetria_BMP280_B.RateTransition == 6.0)) {
    telemetria_BMP280_B.iflogic = 34U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             (telemetria_BMP280_B.RateTransition == 0.0)) {
    telemetria_BMP280_B.iflogic = 0U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             ((telemetria_BMP280_B.RateTransition == 1.0) ||
              (telemetria_BMP280_B.RateTransition == 5.0) ||
              (telemetria_BMP280_B.RateTransition == 9.0))) {
    telemetria_BMP280_B.iflogic = 1U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             ((telemetria_BMP280_B.RateTransition == 3.0) ||
              (telemetria_BMP280_B.RateTransition == 8.0))) {
    telemetria_BMP280_B.iflogic = 74U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             (telemetria_BMP280_B.RateTransition == 7.0)) {
    telemetria_BMP280_B.iflogic = 36U;
  } else if ((telemetria_BMP280_DW.Memory1_PreviousInput == 0.0) &&
             (telemetria_BMP280_B.RateTransition == 4.0)) {
    telemetria_BMP280_B.iflogic = 29U;
  } else {
    telemetria_BMP280_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S12>/iflogic_function' */

  /* Sum: '<S20>/Add' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Memory: '<S20>/Memory'
   */
  telemetria_BMP280_DW.Memory_PreviousInput +=
    telemetria_BMP280_P.Constant_Value + telemetria_BMP280_P.Constant1_Value_n;

  /* Gain: '<S12>/Gain' */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain *
    telemetria_BMP280_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  telemetria_BMP280_B.DataTypeConversion3 = telemetria_BMP280_B.RateTransition <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-telemetria_BMP280_B.RateTransition :
    (uint32_T)telemetria_BMP280_B.RateTransition;

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 6;
       telemetria_BMP280_B.f++) {
    telemetria_BMP280_B.WP_info[telemetria_BMP280_B.f] =
      telemetria_BMP280_DW.WP_dbI[6 * telemetria_BMP280_B.f];
  }

  for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 7;
       telemetria_BMP280_B.f++) {
    telemetria_BMP280_B.WP_param[telemetria_BMP280_B.f] =
      telemetria_BMP280_DW.WP_dbP[6 * telemetria_BMP280_B.f];
  }

  if ((telemetria_BMP280_B.GC_info[0] == 2) && (telemetria_BMP280_B.GC_info[1] <
       6)) {
    qY = telemetria_BMP280_B.GC_info[1] + 1U;
    if (telemetria_BMP280_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 6;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.WP_info[telemetria_BMP280_B.f] =
        telemetria_BMP280_DW.WP_dbI[(6 * telemetria_BMP280_B.f + (int32_T)qY) -
        1];
    }

    qY = telemetria_BMP280_B.GC_info[1] + 1U;
    if (telemetria_BMP280_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 7;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.WP_param[telemetria_BMP280_B.f] =
        telemetria_BMP280_DW.WP_dbP[(6 * telemetria_BMP280_B.f + (int32_T)qY) -
        1];
    }
  }

  if ((telemetria_BMP280_B.GC_info[0] == 3) && (telemetria_BMP280_B.GC_info[1] <
       200)) {
    qY = telemetria_BMP280_B.GC_info[1] + 1U;
    if (telemetria_BMP280_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (telemetria_BMP280_B.f = 0; telemetria_BMP280_B.f < 6;
         telemetria_BMP280_B.f++) {
      telemetria_BMP280_B.WP_info[telemetria_BMP280_B.f] =
        telemetria_BMP280_DW.WP_dbI[(6 * telemetria_BMP280_B.f + (int32_T)qY) -
        1];
    }
  }

  /* End of MATLAB Function: '<S16>/MATLAB Function' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  Constant: '<S14>/onboard_control_sensor_present uint32'
   */
  telemetria_BMP280_B.onboard[0] =
    telemetria_BMP280_P.onboard_control_sensor_presentu[0];
  telemetria_BMP280_B.onboard[1] =
    telemetria_BMP280_P.onboard_control_sensor_presentu[1];
  telemetria_BMP280_B.onboard[2] =
    telemetria_BMP280_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S14>/Gain' incorporates:
   *  Constant: '<S14>/Constant'
   */
  telemetria_BMP280_B.RateTransition = floor(telemetria_BMP280_P.Gain_Gain_i *
    telemetria_BMP280_P.Constant_Value_h);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Constant: '<S14>/load uint16'
   *  Gain: '<S14>/Gain'
   */
  telemetria_BMP280_B.LVDE[0] = telemetria_BMP280_P.loaduint16_Value;
  telemetria_BMP280_B.LVDE[1] = (uint16_T)(telemetria_BMP280_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  qY = 10U * z;
  if (qY > 65535U) {
    qY = 65535U;
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Constant: '<S14>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  telemetria_BMP280_B.LVDE[2] = (uint16_T)qY;
  telemetria_BMP280_B.LVDE[3] = telemetria_BMP280_B.SFunction_o11[6];
  telemetria_BMP280_B.LVDE[4] = telemetria_BMP280_B.SFunction_o11[2];
  telemetria_BMP280_B.LVDE[5] = telemetria_BMP280_P._Value;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  telemetria_BMP280_B.RateTransition = floor
    (telemetria_BMP280_P.Constant1_Value_p[0]);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  telemetria_BMP280_B.LVDE[6] = (uint16_T)(telemetria_BMP280_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  telemetria_BMP280_B.RateTransition = floor
    (telemetria_BMP280_P.Constant1_Value_p[1]);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  telemetria_BMP280_B.LVDE[7] = (uint16_T)(telemetria_BMP280_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* Gain: '<S14>/Gain2' incorporates:
   *  Constant: '<S14>/Constant3'
   */
  telemetria_BMP280_B.RateTransition = floor(telemetria_BMP280_P.Gain2_Gain *
    telemetria_BMP280_P.Constant3_Value_c);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Gain: '<S14>/Gain1'
   *  Gain: '<S14>/Gain2'
   */
  telemetria_BMP280_B.B_Current = (int16_T)(((telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
    telemetria_BMP280_B.RateTransition) * telemetria_BMP280_P.Gain1_Gain_f) >>
    18);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<S14>/Constant2'
   */
  telemetria_BMP280_B.RateTransition = floor
    (telemetria_BMP280_P.Constant2_Value_g);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  telemetria_BMP280_B.B_Remaining = (int8_T)(telemetria_BMP280_B.RateTransition <
    0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-telemetria_BMP280_B.RateTransition
    : (int32_T)(int8_T)(uint8_T)telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant'
   */
  telemetria_BMP280_B.RateTransition = floor
    (telemetria_BMP280_P.Constant_Value_c);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion = telemetria_BMP280_B.RateTransition <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-telemetria_BMP280_B.RateTransition :
    (uint32_T)telemetria_BMP280_B.RateTransition;

  /* MATLAB Function: '<S10>/Alarm set' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_H_mav[0] = telemetria_BMP280_DW.Memory1_PreviousInput_m[0];
  rtb_H_mav[1] = telemetria_BMP280_DW.Memory1_PreviousInput_m[1];
  if (telemetria_BMP280_P.Constant1_Value_k[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (telemetria_BMP280_P.Constant1_Value_k[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S10>/Alarm set' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S10>/Type fixed_wing Autopilot generic'
   */
  telemetria_BMP280_B.DataTypeConversion1_hk[0] =
    telemetria_BMP280_P.Typefixed_wingAutopilotgeneric_[0];
  telemetria_BMP280_B.DataTypeConversion1_hk[1] =
    telemetria_BMP280_P.Typefixed_wingAutopilotgeneric_[1];
  telemetria_BMP280_B.DataTypeConversion1_hk[2] = rtb_H_mav[0];
  telemetria_BMP280_B.DataTypeConversion1_hk[3] = rtb_H_mav[1];

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/ACC simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.ACCsimulated_Value[0];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[0] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/ACC simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.ACCsimulated_Value[1];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[1] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/ACC simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.ACCsimulated_Value[2];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[2] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/p simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.psimulated_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[3] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/q simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.qsimulated_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[4] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/r simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.rsimulated_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[5] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/Constant'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.Constant_Value_n;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[6] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.Constant1_Value_nf;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[7] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_e *
    telemetria_BMP280_P.Constant2_Value_j;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_c[8] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
   *  Constant: '<S11>/p simulated'
   *  Constant: '<S11>/phi simulated'
   *  Constant: '<S11>/psi simulated'
   *  Constant: '<S11>/q simulated'
   *  Constant: '<S11>/r simulated'
   *  Constant: '<S11>/theta simulated'
   */
  telemetria_BMP280_B.DataTypeConversion1[0] = (real32_T)
    telemetria_BMP280_P.phisimulated_Value;
  telemetria_BMP280_B.DataTypeConversion1[1] = (real32_T)
    telemetria_BMP280_P.thetasimulated_Value;
  telemetria_BMP280_B.DataTypeConversion1[2] = (real32_T)
    telemetria_BMP280_P.psisimulated_Value;
  telemetria_BMP280_B.DataTypeConversion1[3] = (real32_T)
    telemetria_BMP280_P.psimulated_Value;
  telemetria_BMP280_B.DataTypeConversion1[4] = (real32_T)
    telemetria_BMP280_P.qsimulated_Value;
  telemetria_BMP280_B.DataTypeConversion1[5] = (real32_T)
    telemetria_BMP280_P.rsimulated_Value;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_h[0] *
    telemetria_BMP280_P.Constant3_Value_j;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_n[0] =
    telemetria_BMP280_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint32_T)
    telemetria_BMP280_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_h[1] *
    telemetria_BMP280_P.Constant5_Value_j;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_n[1] =
    telemetria_BMP280_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint32_T)
    telemetria_BMP280_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_h[2] *
    telemetria_BMP280_P.Constant4_Value_b;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_n[2] =
    telemetria_BMP280_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint32_T)
    telemetria_BMP280_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/alt_r'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain_Gain_h[3] *
    telemetria_BMP280_P.alt_r_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  telemetria_BMP280_B.DataTypeConversion_n[3] =
    telemetria_BMP280_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint32_T)
    telemetria_BMP280_B.RateTransition;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain1_Gain *
    telemetria_BMP280_P.Constant6_Value_l;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  telemetria_BMP280_B.DataTypeConversion1_h[0] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/vel y'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain1_Gain *
    telemetria_BMP280_P.vely_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  telemetria_BMP280_B.DataTypeConversion1_h[1] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/RC Simulated'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain1_Gain *
    telemetria_BMP280_P.RCSimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  telemetria_BMP280_B.DataTypeConversion1_h[2] = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S9>/Gain2' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_P.Gain2_Gain_k *
    telemetria_BMP280_P.Constant7_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  if (telemetria_BMP280_B.RateTransition < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.RateTransition);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.RateTransition);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  telemetria_BMP280_B.DataTypeConversion2 = (uint16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* SignalConversion generated from: '<S31>/Enable' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !telemetria_BMP280_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  tel_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &telemetria_BMP280_B.One_time_initialization,
    &telemetria_BMP280_DW.One_time_initialization,
    &telemetria_BMP280_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (telemetria_BMP280_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S28>/I2C Read12' */
    if (telemetria_BMP280_DW.obj_d.SampleTime != telemetria_BMP280_P.t_AP) {
      telemetria_BMP280_DW.obj_d.SampleTime = telemetria_BMP280_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (telemetria_BMP280_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter, 1U,
       true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(telemetria_BMP280_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S28>/I2C Read1' */
    if (telemetria_BMP280_DW.obj_i.SampleTime != telemetria_BMP280_P.t_AP) {
      telemetria_BMP280_DW.obj_i.SampleTime = telemetria_BMP280_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (telemetria_BMP280_DW.obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter, 1U,
       true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(telemetria_BMP280_DW.obj_i.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw_0[0], 3U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw_0[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
      output[2] = 0U;
    }

    /* ArithShift: '<S28>/Shift Arithmetic4' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_P.Constant1_Value);
    if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
        (telemetria_BMP280_B.RateTransition)) {
      telemetria_BMP280_B.RateTransition = 0.0;
    } else {
      telemetria_BMP280_B.RateTransition = fmod
        (telemetria_BMP280_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S28>/Shift Arithmetic3' incorporates:
     *  Constant: '<S28>/Constant5'
     */
    telemetria_BMP280_B.num_254 = floor(telemetria_BMP280_P.Constant5_Value);
    if (rtIsNaN(telemetria_BMP280_B.num_254) || rtIsInf
        (telemetria_BMP280_B.num_254)) {
      telemetria_BMP280_B.num_254 = 0.0;
    } else {
      telemetria_BMP280_B.num_254 = fmod(telemetria_BMP280_B.num_254,
        4.294967296E+9);
    }

    /* ArithShift: '<S28>/Shift Arithmetic1' incorporates:
     *  Constant: '<S28>/Constant6'
     */
    telemetria_BMP280_B.deltafalllimit = floor
      (telemetria_BMP280_P.Constant6_Value);
    if (rtIsNaN(telemetria_BMP280_B.deltafalllimit) || rtIsInf
        (telemetria_BMP280_B.deltafalllimit)) {
      telemetria_BMP280_B.deltafalllimit = 0.0;
    } else {
      telemetria_BMP280_B.deltafalllimit = fmod
        (telemetria_BMP280_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S28>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S28>/Shift Arithmetic1'
     *  ArithShift: '<S28>/Shift Arithmetic3'
     *  ArithShift: '<S28>/Shift Arithmetic4'
     *  Constant: '<S28>/Constant10'
     *  Constant: '<S28>/Constant11'
     *  Constant: '<S28>/Constant7'
     *  MATLABSystem: '<S28>/I2C Read1'
     *  Sum: '<S28>/Sum1'
     *  Sum: '<S28>/Sum4'
     *  Sum: '<S28>/Sum5'
     *  Sum: '<S28>/Sum6'
     */
    telemetria_BMP280_B.DataTypeConversion1_l = (int32_T)
      ((((((telemetria_BMP280_P.Constant7_Value_h + output[0]) <<
           (telemetria_BMP280_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
            -telemetria_BMP280_B.RateTransition : (int32_T)(uint32_T)
            telemetria_BMP280_B.RateTransition)) +
          ((telemetria_BMP280_P.Constant10_Value_i + output[1]) <<
           (telemetria_BMP280_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
            -telemetria_BMP280_B.num_254 : (int32_T)(uint32_T)
            telemetria_BMP280_B.num_254))) +
         telemetria_BMP280_P.Constant11_Value) + output[2]) >>
       (telemetria_BMP280_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -telemetria_BMP280_B.deltafalllimit : (int32_T)(uint32_T)
        telemetria_BMP280_B.deltafalllimit));

    /* ArithShift: '<S28>/Shift Arithmetic7' incorporates:
     *  Constant: '<S28>/Constant2'
     */
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_P.Constant2_Value);
    if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
        (telemetria_BMP280_B.RateTransition)) {
      telemetria_BMP280_B.RateTransition = 0.0;
    } else {
      telemetria_BMP280_B.RateTransition = fmod
        (telemetria_BMP280_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S28>/Shift Arithmetic6' incorporates:
     *  Constant: '<S28>/Constant3'
     */
    telemetria_BMP280_B.num_254 = floor(telemetria_BMP280_P.Constant3_Value);
    if (rtIsNaN(telemetria_BMP280_B.num_254) || rtIsInf
        (telemetria_BMP280_B.num_254)) {
      telemetria_BMP280_B.num_254 = 0.0;
    } else {
      telemetria_BMP280_B.num_254 = fmod(telemetria_BMP280_B.num_254,
        4.294967296E+9);
    }

    /* ArithShift: '<S28>/Shift Arithmetic2' incorporates:
     *  Constant: '<S28>/Constant4'
     */
    telemetria_BMP280_B.deltafalllimit = floor
      (telemetria_BMP280_P.Constant4_Value);
    if (rtIsNaN(telemetria_BMP280_B.deltafalllimit) || rtIsInf
        (telemetria_BMP280_B.deltafalllimit)) {
      telemetria_BMP280_B.deltafalllimit = 0.0;
    } else {
      telemetria_BMP280_B.deltafalllimit = fmod
        (telemetria_BMP280_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S28>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S28>/Shift Arithmetic2'
     *  ArithShift: '<S28>/Shift Arithmetic6'
     *  ArithShift: '<S28>/Shift Arithmetic7'
     *  Constant: '<S28>/Constant8'
     *  Constant: '<S28>/Constant9'
     *  MATLABSystem: '<S28>/I2C Read12'
     *  Sum: '<S28>/Sum'
     *  Sum: '<S28>/Sum2'
     *  Sum: '<S28>/Sum3'
     */
    telemetria_BMP280_B.DataTypeConversion_p = (int32_T)
      ((((telemetria_BMP280_P.Constant8_Value + rtb_H_mav[0]) <<
         (telemetria_BMP280_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -telemetria_BMP280_B.RateTransition : (int32_T)(uint32_T)
          telemetria_BMP280_B.RateTransition)) +
        ((telemetria_BMP280_P.Constant9_Value + rtb_H_mav[1]) <<
         (telemetria_BMP280_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
          -telemetria_BMP280_B.num_254 : (int32_T)(uint32_T)
          telemetria_BMP280_B.num_254))) >> (telemetria_BMP280_B.deltafalllimit <
        0.0 ? -(int32_T)(uint32_T)-telemetria_BMP280_B.deltafalllimit : (int32_T)
        (uint32_T)telemetria_BMP280_B.deltafalllimit));

    /* S-Function (calc_T): '<S28>/S-Function Builder' */
    calc_T_Outputs_wrapper(&telemetria_BMP280_B.One_time_initialization.I2CRead,
      &telemetria_BMP280_B.One_time_initialization.I2CRead1,
      &telemetria_BMP280_B.One_time_initialization.I2CRead2,
      &telemetria_BMP280_B.DataTypeConversion_p,
      &telemetria_BMP280_B.SFunctionBuilder_o1,
      &telemetria_BMP280_B.SFunctionBuilder_o2_i);

    /* S-Function (calc_p): '<S28>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&telemetria_BMP280_B.One_time_initialization.I2CRead3,
      &telemetria_BMP280_B.One_time_initialization.I2CRead4,
      &telemetria_BMP280_B.One_time_initialization.I2CRead5,
      &telemetria_BMP280_B.One_time_initialization.I2CRead6,
      &telemetria_BMP280_B.One_time_initialization.I2CRead7,
      &telemetria_BMP280_B.One_time_initialization.I2CRead8,
      &telemetria_BMP280_B.One_time_initialization.I2CRead9,
      &telemetria_BMP280_B.One_time_initialization.I2CRead10,
      &telemetria_BMP280_B.One_time_initialization.I2CRead11,
      &telemetria_BMP280_B.DataTypeConversion1_l,
      &telemetria_BMP280_B.SFunctionBuilder_o2_i,
      &telemetria_BMP280_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (telemetria_BMP280_P.Constant2_Value_e == 1.0) {
    telemetria_BMP280_DW.P_ref = telemetria_BMP280_B.SFunctionBuilder1;
  }

  if (telemetria_BMP280_P.Constant_Value_a == 1.0) {
    telemetria_BMP280_DW.P_ref = telemetria_BMP280_P.Constant1_Value_kc;
    telemetria_BMP280_DW.rl_up = 20.0;
    telemetria_BMP280_DW.rl_dw = -20.0;
  }

  /* Product: '<S27>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S27>/sample time'
   *
   * About '<S27>/sample time':
   *  y = K where K = ( w * Ts )
   */
  telemetria_BMP280_B.RateTransition = telemetria_BMP280_DW.rl_up *
    telemetria_BMP280_P.sampletime_WtEt;

  /* Sum: '<S27>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S27>/Delay Input2'
   *
   * Block description for '<S27>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S27>/Delay Input2':
   *
   *  Store in Global RAM
   */
  telemetria_BMP280_B.num_254 = telemetria_BMP280_DW.P_ref -
    telemetria_BMP280_DW.DelayInput2_DSTATE;

  /* Product: '<S27>/delta fall limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S27>/sample time'
   *
   * About '<S27>/sample time':
   *  y = K where K = ( w * Ts )
   */
  telemetria_BMP280_B.deltafalllimit = telemetria_BMP280_DW.rl_dw *
    telemetria_BMP280_P.sampletime_WtEt;

  /* Switch: '<S33>/Switch2' incorporates:
   *  RelationalOperator: '<S33>/LowerRelop1'
   *  RelationalOperator: '<S33>/UpperRelop'
   *  Switch: '<S33>/Switch'
   */
  if (telemetria_BMP280_B.num_254 > telemetria_BMP280_B.RateTransition) {
    telemetria_BMP280_B.num_254 = telemetria_BMP280_B.RateTransition;
  } else {
    if (telemetria_BMP280_B.num_254 < telemetria_BMP280_B.deltafalllimit) {
      /* Switch: '<S33>/Switch' */
      telemetria_BMP280_B.num_254 = telemetria_BMP280_B.deltafalllimit;
    }
  }

  /* End of Switch: '<S33>/Switch2' */

  /* Sum: '<S27>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S27>/Delay Input2'
   *
   * Block description for '<S27>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S27>/Delay Input2':
   *
   *  Store in Global RAM
   */
  telemetria_BMP280_DW.DelayInput2_DSTATE += telemetria_BMP280_B.num_254;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S27>/Delay Input2'
   *
   * Block description for '<S27>/Delay Input2':
   *
   *  Store in Global RAM
   */
  telemetria_BMP280_B.DataTypeConversion3_m = (real32_T)
    telemetria_BMP280_DW.DelayInput2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S32>/Subsystem1' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (telemetria_BMP280_P.Constant2_Value_e > 0.0) {
    /* Inport: '<S34>/T' */
    telemetria_BMP280_B.T = telemetria_BMP280_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S32>/Subsystem1' */

  /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
   *  Constant: '<S15>/RC simulated'
   *  Constant: '<S15>/TAS simulated'
   *  Constant: '<S15>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  MATLAB Function: '<S3>/MATLAB Function1'
   */
  telemetria_BMP280_B.DataTypeConversion3_p[0] = (real32_T)
    telemetria_BMP280_P.TASsimulated_Value;
  telemetria_BMP280_B.DataTypeConversion3_p[1] = (real32_T)
    telemetria_BMP280_P.vsimulated_Value;
  telemetria_BMP280_B.DataTypeConversion3_p[2] = (real32_T)log((real32_T)
    telemetria_BMP280_B.SFunctionBuilder1 /
    telemetria_BMP280_B.DataTypeConversion3_m) * -8333.33301F;
  telemetria_BMP280_B.DataTypeConversion3_p[3] = (real32_T)
    telemetria_BMP280_P.RCsimulated_Value;

  /* DataTypeConversion: '<S15>/Data Type Conversion4' incorporates:
   *  Constant: '<S15>/ Heading simulated'
   */
  telemetria_BMP280_B.RateTransition = floor
    (telemetria_BMP280_P.Headingsimulated_Value);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion4' */
  telemetria_BMP280_B.DataTypeConversion4_h = (int16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion5' incorporates:
   *  Constant: '<S15>/Rpm simulated'
   */
  telemetria_BMP280_B.RateTransition = floor
    (telemetria_BMP280_P.Rpmsimulated_Value);
  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion5' */
  telemetria_BMP280_B.DataTypeConversion5 = (uint16_T)
    (telemetria_BMP280_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
     telemetria_BMP280_B.RateTransition);

  /* Gain: '<S22>/Gain2' incorporates:
   *  Constant: '<S13>/Manetta Simulated'
   */
  telemetria_BMP280_B.num_254 = telemetria_BMP280_P.Gain2_Gain_f *
    telemetria_BMP280_P.ManettaSimulated_Value;

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S13>/Equilibratore Simulated'
   *  Constant: '<S22>/Constant2'
   *  Gain: '<S23>/Gain'
   */
  telemetria_BMP280_B.deltafalllimit = telemetria_BMP280_P.Gain_Gain_c *
    telemetria_BMP280_P.EquilibratoreSimulated_Value +
    telemetria_BMP280_P.Constant2_Value_gt;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S13>/Alettoni Simulated'
   *  Constant: '<S22>/Constant2'
   *  Gain: '<S24>/Gain'
   */
  telemetria_BMP280_B.Sum1 = telemetria_BMP280_P.Gain_Gain_h4 *
    telemetria_BMP280_P.AlettoniSimulated_Value +
    telemetria_BMP280_P.Constant2_Value_gt;

  /* Sum: '<S22>/Sum2' incorporates:
   *  Constant: '<S13>/Timone Simulated'
   *  Constant: '<S22>/Constant2'
   *  Gain: '<S25>/Gain'
   */
  telemetria_BMP280_B.Sum2 = telemetria_BMP280_P.Gain_Gain_m *
    telemetria_BMP280_P.TimoneSimulated_Value +
    telemetria_BMP280_P.Constant2_Value_gt;

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  telemetria_BMP280_B.PatohPa1 = telemetria_BMP280_P.Gain_Gain_l *
    telemetria_BMP280_P.Constant2_Value_h;

  /* Saturate: '<S13>/Saturation' */
  if (telemetria_BMP280_B.PatohPa1 > telemetria_BMP280_P.Saturation_UpperSat) {
    telemetria_BMP280_B.PatohPa1 = telemetria_BMP280_P.Saturation_UpperSat;
  } else {
    if (telemetria_BMP280_B.PatohPa1 < telemetria_BMP280_P.Saturation_LowerSat)
    {
      telemetria_BMP280_B.PatohPa1 = telemetria_BMP280_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (telemetria_BMP280_P.Constant_Value_p < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil
      (telemetria_BMP280_P.Constant_Value_p);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_P.Constant_Value_p);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[0] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (telemetria_BMP280_B.num_254 < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.num_254);
  } else {
    telemetria_BMP280_B.RateTransition = floor(telemetria_BMP280_B.num_254);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[1] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (telemetria_BMP280_B.deltafalllimit < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.deltafalllimit);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_B.deltafalllimit);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[2] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (telemetria_BMP280_B.Sum1 < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.Sum1);
  } else {
    telemetria_BMP280_B.RateTransition = floor(telemetria_BMP280_B.Sum1);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[3] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (telemetria_BMP280_B.Sum2 < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.Sum2);
  } else {
    telemetria_BMP280_B.RateTransition = floor(telemetria_BMP280_B.Sum2);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[4] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (telemetria_BMP280_P.Constant1_Value_c[0] < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil
      (telemetria_BMP280_P.Constant1_Value_c[0]);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_P.Constant1_Value_c[0]);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[5] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (telemetria_BMP280_P.Constant1_Value_c[1] < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil
      (telemetria_BMP280_P.Constant1_Value_c[1]);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_P.Constant1_Value_c[1]);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[6] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (telemetria_BMP280_P.Constant1_Value_c[2] < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil
      (telemetria_BMP280_P.Constant1_Value_c[2]);
  } else {
    telemetria_BMP280_B.RateTransition = floor
      (telemetria_BMP280_P.Constant1_Value_c[2]);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[7] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (telemetria_BMP280_B.PatohPa1 < 0.0) {
    telemetria_BMP280_B.RateTransition = ceil(telemetria_BMP280_B.PatohPa1);
  } else {
    telemetria_BMP280_B.RateTransition = floor(telemetria_BMP280_B.PatohPa1);
  }

  if (rtIsNaN(telemetria_BMP280_B.RateTransition) || rtIsInf
      (telemetria_BMP280_B.RateTransition)) {
    telemetria_BMP280_B.RateTransition = 0.0;
  } else {
    telemetria_BMP280_B.RateTransition = fmod(telemetria_BMP280_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  telemetria_BMP280_B.Heading[8] = (uint16_T)(telemetria_BMP280_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -telemetria_BMP280_B.RateTransition : (int32_T)(uint16_T)
    telemetria_BMP280_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  telemetria_BMP280_B.Memory_n = telemetria_BMP280_DW.Memory_PreviousInput_f;

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S32>/NotEqual'
   *  Switch: '<S32>/Switch'
   */
  if (telemetria_BMP280_P.Constant_Value_o != telemetria_BMP280_P.T_0_Value) {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    telemetria_BMP280_B.DataTypeConversion4 = (real32_T)
      telemetria_BMP280_P.T_0_Value;
  } else if (telemetria_BMP280_B.T > telemetria_BMP280_P.Switch_Threshold_c) {
    /* Switch: '<S32>/Switch' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion4'
     */
    telemetria_BMP280_B.DataTypeConversion4 = telemetria_BMP280_B.T;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    telemetria_BMP280_B.DataTypeConversion4 = (real32_T)
      telemetria_BMP280_P.T_0_Value;
  }

  /* End of Switch: '<S32>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  telemetria_BMP280_B.DataTypeConversion_g = (real32_T)
    (telemetria_BMP280_P.PatohPa_Gain * (real_T)
     telemetria_BMP280_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  telemetria_BMP280_B.DataTypeConversion1_n = (real32_T)
    (telemetria_BMP280_P.PatohPa1_Gain * telemetria_BMP280_P.Constant2_Value_eg);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  tmp = (real32_T)floor(telemetria_BMP280_B.SFunctionBuilder_o1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  telemetria_BMP280_B.DataTypeConversion2_d = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&telemetria_BMP280_B.iflogic,
    &telemetria_BMP280_B.DataTypeConversion3,
    &telemetria_BMP280_P.SIUAVuint8_Value, &telemetria_BMP280_B.GC_info[0],
    &telemetria_BMP280_B.Val_out_MAV[0], &telemetria_BMP280_B.WP_info[0],
    &telemetria_BMP280_B.WP_param[0], &telemetria_BMP280_B.onboard[0],
    &telemetria_BMP280_B.LVDE[0], &telemetria_BMP280_B.B_Current,
    &telemetria_BMP280_B.B_Remaining, &telemetria_BMP280_B.DataTypeConversion,
    &telemetria_BMP280_B.DataTypeConversion1_hk[0],
    &telemetria_BMP280_B.DataTypeConversion_c[0],
    &telemetria_BMP280_B.DataTypeConversion1[0],
    &telemetria_BMP280_B.DataTypeConversion_n[0],
    &telemetria_BMP280_B.DataTypeConversion1_h[0],
    &telemetria_BMP280_B.DataTypeConversion2,
    &telemetria_BMP280_B.DataTypeConversion3_p[0],
    &telemetria_BMP280_B.DataTypeConversion4_h,
    &telemetria_BMP280_B.DataTypeConversion5, &telemetria_BMP280_B.Heading[0],
    &telemetria_BMP280_B.Memory_n, &telemetria_BMP280_B.DataTypeConversion3_m,
    &telemetria_BMP280_B.SFunction_o14, &telemetria_BMP280_B.DataTypeConversion4,
    &telemetria_BMP280_B.SFunction_o15,
    &telemetria_BMP280_B.DataTypeConversion_g,
    &telemetria_BMP280_B.DataTypeConversion1_n,
    &telemetria_BMP280_B.DataTypeConversion2_d,
    &telemetria_BMP280_B.SFunction_o5[0],
    &telemetria_BMP280_P.Constant4_Value_b5,
    &telemetria_BMP280_P.Constant5_Value_a,
    &telemetria_BMP280_P.Constant10_Value, ((const uint16_T*)
    &telemetria_BMP280_U16GND), &telemetria_BMP280_B.SFunction_o1_g,
    &telemetria_BMP280_B.SFunction_o2_b[0], &telemetria_BMP280_B.SFunction_o3,
    &telemetria_BMP280_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (telemetria_BMP280_B.SFunction_o1_g > 0) {
    /* Chart: '<S8>/Chart' */
    if (telemetria_BMP280_DW.is_active_c9_telemetria_BMP280 == 0U) {
      telemetria_BMP280_DW.is_active_c9_telemetria_BMP280 = 1U;
      telemetria_BMP280_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (telemetria_BMP280_DW.obj.Protocol !=
            telemetria_BMP280_P.SerialTransmit_Protocol) {
          telemetria_BMP280_DW.obj.Protocol =
            telemetria_BMP280_P.SerialTransmit_Protocol;
        }

        counter = telemetria_BMP280_B.SFunction_o2_b[telemetria_BMP280_DW.i - 1];
        MW_Serial_write(telemetria_BMP280_DW.obj.port, &counter, 1.0,
                        telemetria_BMP280_DW.obj.dataSizeInBytes,
                        telemetria_BMP280_DW.obj.sendModeEnum,
                        telemetria_BMP280_DW.obj.dataType,
                        telemetria_BMP280_DW.obj.sendFormatEnum, 2.0, '\x00');
        if (telemetria_BMP280_DW.i < telemetria_BMP280_B.SFunction_o3) {
          telemetria_BMP280_B.f = telemetria_BMP280_DW.i + 1;
          if (telemetria_BMP280_DW.i + 1 > 255) {
            telemetria_BMP280_B.f = 255;
          }

          telemetria_BMP280_DW.i = (uint8_T)telemetria_BMP280_B.f;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      telemetria_BMP280_DW.i = 1U;
    }

    /* End of Chart: '<S8>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&telemetria_BMP280_DW.Memory4_PreviousInput[0],
         &telemetria_BMP280_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&telemetria_BMP280_P.Constant1_Value_h,
    &telemetria_BMP280_B.SFunctionBuilder_o1_e[0],
    &telemetria_BMP280_B.SFunctionBuilder_o2,
    &telemetria_BMP280_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&telemetria_BMP280_DW.Memory5_PreviousInput[0],
         &telemetria_BMP280_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  telemetria_BMP280_DW.Memory_PreviousInput_m[0] =
    telemetria_BMP280_B.DataTypeConversion1_hk[0];
  telemetria_BMP280_DW.Memory_PreviousInput_m[1] =
    telemetria_BMP280_B.DataTypeConversion1_hk[1];
  telemetria_BMP280_DW.Memory_PreviousInput_m[2] =
    telemetria_BMP280_B.DataTypeConversion1_hk[2];
  telemetria_BMP280_DW.Memory_PreviousInput_m[3] =
    telemetria_BMP280_B.DataTypeConversion1_hk[3];

  /* Update for Memory: '<S1>/Memory' */
  for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 8;
       telemetria_BMP280_B.caso++) {
    telemetria_BMP280_DW.Memory_PreviousInput_e[telemetria_BMP280_B.caso] =
      telemetria_BMP280_B.SFunction_o11[telemetria_BMP280_B.caso];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  telemetria_BMP280_DW.Memory2_PreviousInput_a[0] = (uint8_T)AP_mode_idx_0;
  telemetria_BMP280_DW.Memory2_PreviousInput_a[1] = (uint8_T)AP_mode_idx_1;
  for (telemetria_BMP280_B.caso = 0; telemetria_BMP280_B.caso < 7;
       telemetria_BMP280_B.caso++) {
    tmp = rt_roundf_snf
      (telemetria_BMP280_DW.riferimenti[telemetria_BMP280_B.caso]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        telemetria_BMP280_DW.Memory2_PreviousInput_a[telemetria_BMP280_B.caso +
          2] = (uint8_T)tmp;
      } else {
        telemetria_BMP280_DW.Memory2_PreviousInput_a[telemetria_BMP280_B.caso +
          2] = 0U;
      }
    } else {
      telemetria_BMP280_DW.Memory2_PreviousInput_a[telemetria_BMP280_B.caso + 2]
        = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  telemetria_BMP280_DW.UnitDelay_DSTATE = telemetria_BMP280_P.Constant3_Value_g;

  /* Update for Memory: '<S2>/Memory' */
  telemetria_BMP280_DW.Memory_PreviousInput_f = telemetria_BMP280_B.SFunction_o4;
}

/* Model step function for TID1 */
void telemetria_BMP280_step1(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S20>/Add2' incorporates:
   *  Constant: '<S20>/Constant4'
   *  Constant: '<S20>/Constant5'
   *  Memory: '<S20>/Memory2'
   */
  telemetria_BMP280_DW.Memory2_PreviousInput +=
    telemetria_BMP280_P.Constant4_Value_n +
    telemetria_BMP280_P.Constant5_Value_d;

  /* Switch: '<S20>/Switch1' */
  if (telemetria_BMP280_DW.Memory2_PreviousInput >
      telemetria_BMP280_P.Switch1_Threshold) {
    /* Sum: '<S20>/Add2' incorporates:
     *  Constant: '<S20>/Constant4'
     */
    telemetria_BMP280_DW.Memory2_PreviousInput =
      telemetria_BMP280_P.Constant4_Value_n;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* RateTransition: '<S20>/Rate Transition' */
  telemetria_BMP280_DW.RateTransition_Buffer0 =
    telemetria_BMP280_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void telemetria_BMP280_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    codertarget_arduinobase_inter_T *obj;
    real_T tmp_0;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_1;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&telemetria_BMP280_DW.Memory4_PreviousInput[0],
           &telemetria_BMP280_P.Memory4_InitialCondition[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          telemetria_BMP280_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      telemetria_BMP280_DW.Memory5_PreviousInput[i] =
        telemetria_BMP280_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    telemetria_BMP280_DW.Memory1_PreviousInput_m[0] =
      telemetria_BMP280_P.Memory1_InitialCondition_g;
    telemetria_BMP280_DW.Memory1_PreviousInput_m[1] =
      telemetria_BMP280_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    telemetria_BMP280_DW.Memory_PreviousInput_m[0] =
      telemetria_BMP280_P.Memory_InitialCondition_g;
    telemetria_BMP280_DW.Memory_PreviousInput_m[1] =
      telemetria_BMP280_P.Memory_InitialCondition_g;
    telemetria_BMP280_DW.Memory_PreviousInput_m[2] =
      telemetria_BMP280_P.Memory_InitialCondition_g;
    telemetria_BMP280_DW.Memory_PreviousInput_m[3] =
      telemetria_BMP280_P.Memory_InitialCondition_g;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    telemetria_BMP280_DW.Memory3_PreviousInput =
      telemetria_BMP280_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      telemetria_BMP280_DW.Memory_PreviousInput_e[i] =
        telemetria_BMP280_P.Memory_InitialCondition_o;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      telemetria_BMP280_DW.Memory2_PreviousInput_a[i] =
        telemetria_BMP280_P.Memory2_InitialCondition_p[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S20>/Rate Transition' */
    telemetria_BMP280_DW.RateTransition_Buffer0 =
      telemetria_BMP280_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S20>/Switch' incorporates:
     *  Memory: '<S20>/Memory1'
     */
    telemetria_BMP280_DW.Memory1_PreviousInput =
      telemetria_BMP280_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S20>/Add' incorporates:
     *  Memory: '<S20>/Memory'
     */
    telemetria_BMP280_DW.Memory_PreviousInput =
      telemetria_BMP280_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    telemetria_BMP280_DW.UnitDelay_DSTATE =
      telemetria_BMP280_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S27>/Delay Input2'
     *
     * Block description for '<S27>/Delay Input2':
     *
     *  Store in Global RAM
     */
    telemetria_BMP280_DW.DelayInput2_DSTATE =
      telemetria_BMP280_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    telemetria_BMP280_DW.Memory_PreviousInput_f =
      telemetria_BMP280_P.Memory_InitialCondition_h;

    /* InitializeConditions for Sum: '<S20>/Add2' incorporates:
     *  Memory: '<S20>/Memory2'
     */
    telemetria_BMP280_DW.Memory2_PreviousInput =
      telemetria_BMP280_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&telemetria_BMP280_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
     *  SubSystem: '<S17>/sendbyte'
     */
    /* Start for MATLABSystem: '<S18>/Serial Transmit' */
    telemetria_BMP280_DW.obj.matlabCodegenIsDeleted = false;
    telemetria_BMP280_DW.obj.Protocol =
      telemetria_BMP280_P.SerialTransmit_Protocol;
    telemetria_BMP280_DW.obj.isInitialized = 1;
    telemetria_BMP280_DW.obj.port = 2.0;
    telemetria_BMP280_DW.obj.dataSizeInBytes = 1.0;
    telemetria_BMP280_DW.obj.dataType = 0.0;
    telemetria_BMP280_DW.obj.sendModeEnum = 0.0;
    telemetria_BMP280_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(telemetria_BMP280_DW.obj.port);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp_1 = (uint8_T)tmp_0;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_1);
    telemetria_BMP280_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S18>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S28>/I2C Read12' */
    telemetria_BMP280_DW.obj_d.matlabCodegenIsDeleted = true;
    obj = &telemetria_BMP280_DW.obj_d;
    telemetria_BMP280_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    telemetria_BMP280_DW.obj_d.isInitialized = 0;
    telemetria_BMP280_DW.obj_d.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    telemetria_BMP280_DW.obj_d.matlabCodegenIsDeleted = false;
    telemetria_BMP280_DW.obj_d.SampleTime = telemetria_BMP280_P.t_AP;
    obj = &telemetria_BMP280_DW.obj_d;
    telemetria_BMP280_DW.obj_d.isSetupComplete = false;
    telemetria_BMP280_DW.obj_d.isInitialized = 1;
    telemetria_BMP280_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(telemetria_BMP280_B.i2cname, 0);
    telemetria_BMP280_DW.obj_d.BusSpeed = 100000U;
    varargin_1 = telemetria_BMP280_DW.obj_d.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    telemetria_BMP280_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S28>/I2C Read1' */
    telemetria_BMP280_DW.obj_i.matlabCodegenIsDeleted = true;
    obj = &telemetria_BMP280_DW.obj_i;
    telemetria_BMP280_DW.obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
    telemetria_BMP280_DW.obj_i.isInitialized = 0;
    telemetria_BMP280_DW.obj_i.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    telemetria_BMP280_DW.obj_i.matlabCodegenIsDeleted = false;
    telemetria_BMP280_DW.obj_i.SampleTime = telemetria_BMP280_P.t_AP;
    obj = &telemetria_BMP280_DW.obj_i;
    telemetria_BMP280_DW.obj_i.isSetupComplete = false;
    telemetria_BMP280_DW.obj_i.isInitialized = 1;
    telemetria_BMP280_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(telemetria_BMP280_B.i2cname, 0);
    telemetria_BMP280_DW.obj_i.BusSpeed = 100000U;
    varargin_1 = telemetria_BMP280_DW.obj_i.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    telemetria_BMP280_DW.obj_i.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S28>/S-Function Builder' incorporates:
     *  Outport: '<S28>/T'
     */
    telemetria_BMP280_B.SFunctionBuilder_o1 = telemetria_BMP280_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S28>/S-Function Builder1' incorporates:
     *  Outport: '<S28>/p'
     */
    telemetria_BMP280_B.SFunctionBuilder1 = telemetria_BMP280_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    telemetria_BMP280_DW.P_ref = 101325.0;
    telemetria_BMP280_DW.rl_up = 300.0;
    telemetria_BMP280_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init(&telemetria_BMP280_B.One_time_initialization,
      &telemetria_BMP280_DW.One_time_initialization,
      &telemetria_BMP280_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem1' */
    /* SystemInitialize for Outport: '<S34>/T_0' incorporates:
     *  Inport: '<S34>/T'
     */
    telemetria_BMP280_B.T = telemetria_BMP280_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S32>/Subsystem1' */
  }
}

/* Model terminate function */
void telemetria_BMP280_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term(&telemetria_BMP280_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S28>/I2C Read12' */
  obj = &telemetria_BMP280_DW.obj_d;
  if (!telemetria_BMP280_DW.obj_d.matlabCodegenIsDeleted) {
    telemetria_BMP280_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((telemetria_BMP280_DW.obj_d.isInitialized == 1) &&
        telemetria_BMP280_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S28>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S28>/I2C Read1' */
  obj = &telemetria_BMP280_DW.obj_i;
  if (!telemetria_BMP280_DW.obj_i.matlabCodegenIsDeleted) {
    telemetria_BMP280_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((telemetria_BMP280_DW.obj_i.isInitialized == 1) &&
        telemetria_BMP280_DW.obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S28>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S17>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S18>/Serial Transmit' */
  if (!telemetria_BMP280_DW.obj.matlabCodegenIsDeleted) {
    telemetria_BMP280_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S18>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
