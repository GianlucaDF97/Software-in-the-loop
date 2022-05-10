/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provalogBMP_09_22.c
 *
 * Code generated for Simulink model 'provalogBMP_09_22'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 17:33:28 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provalogBMP_09_22.h"
#include "provalogBMP_09_22_private.h"

const uint16_T provalogBMP_09_22_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_provalogBMP_09_22_T provalogBMP_09_22_B;

/* Block states (default storage) */
DW_provalogBMP_09_22_T provalogBMP_09_22_DW;

/* Real-time model */
static RT_MODEL_provalogBMP_09_22_T provalogBMP_09_22_M_;
RT_MODEL_provalogBMP_09_22_T *const provalogBMP_09_22_M = &provalogBMP_09_22_M_;

/* Forward declaration for local functions */
static void provalogBMP_09_22_find_254(const uint8_T pack[100], real_T position
  [3], real_T *counter);
static boolean_T provalogBMP_09_22_ifWhileCond(const boolean_T x[100]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void provalogBMP_09_22_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(provalogBMP_09_22_M, 1));
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
  (provalogBMP_09_22_M->Timing.TaskCounters.TID[1])++;
  if ((provalogBMP_09_22_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    provalogBMP_09_22_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_pro_T *localB,
  DW_One_time_initialization_pr_T *localDW, P_One_time_initialization_pro_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S35>/I2C Read' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read1' */
  localDW->obj_f2.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f2;
  localDW->obj_f2.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f2.isInitialized = 0;
  localDW->obj_f2.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f2.matlabCodegenIsDeleted = false;
  localDW->obj_f2.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_f2;
  localDW->obj_f2.isSetupComplete = false;
  localDW->obj_f2.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f2.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f2.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f2.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read2' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read3' */
  localDW->obj_ef.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ef;
  localDW->obj_ef.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ef.isInitialized = 0;
  localDW->obj_ef.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ef.matlabCodegenIsDeleted = false;
  localDW->obj_ef.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_ef;
  localDW->obj_ef.isSetupComplete = false;
  localDW->obj_ef.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ef.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ef.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ef.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read4' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  localDW->obj_e.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  localDW->obj_e.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read5' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read6' */
  localDW->obj_j.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_j;
  localDW->obj_j.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_j.isInitialized = 0;
  localDW->obj_j.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_j.matlabCodegenIsDeleted = false;
  localDW->obj_j.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_j;
  localDW->obj_j.isSetupComplete = false;
  localDW->obj_j.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_j.BusSpeed = 100000U;
  varargin_1 = localDW->obj_j.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read7' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read8' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read10' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read11' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = provalogBMP_09_22_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Write1' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Write2' */
  localDW->obj_fo.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_fo;
  localDW->obj_fo.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_fo.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_fo.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_fo;
  localDW->obj_fo.isSetupComplete = false;
  localDW->obj_fo.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_fo.BusSpeed = 100000U;
  varargin_1 = localDW->obj_fo.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_fo.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Write3' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S35>/I2C Read12' */
  localDW->obj_a.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_a;
  localDW->obj_a.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_a.isInitialized = 0;
  localDW->obj_a.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_a.matlabCodegenIsDeleted = false;
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

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read' incorporates:
   *  Outport: '<S35>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read1' incorporates:
   *  Outport: '<S35>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read2' incorporates:
   *  Outport: '<S35>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read3' incorporates:
   *  Outport: '<S35>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read4' incorporates:
   *  Outport: '<S35>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read5' incorporates:
   *  Outport: '<S35>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read6' incorporates:
   *  Outport: '<S35>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read7' incorporates:
   *  Outport: '<S35>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read8' incorporates:
   *  Outport: '<S35>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read9' incorporates:
   *  Outport: '<S35>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read10' incorporates:
   *  Outport: '<S35>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S35>/I2C Read11' incorporates:
   *  Outport: '<S35>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S35>/Byte Unpack' incorporates:
     *  Outport: '<S35>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S3>/One_time_initialization' */
void pro_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_pro_T *localB, DW_One_time_initialization_pr_T
  *localDW, P_One_time_initialization_pro_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' incorporates:
   *  EnablePort: '<S35>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S35>/I2C Write3' incorporates:
     *  ArithShift: '<S35>/Shift Arithmetic1'
     *  Constant: '<S35>/registro memoria2 '
     *  DataTypeConversion: '<S35>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S35>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S35>/I2C Read' */
    if (localDW->obj_m.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_m.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S35>/I2C Read' */

    /* MATLABSystem: '<S35>/I2C Read1' */
    if (localDW->obj_f2.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_f2.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f2.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f2.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read1' */

    /* MATLABSystem: '<S35>/I2C Read2' */
    if (localDW->obj_k.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_k.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read2' */

    /* MATLABSystem: '<S35>/I2C Read3' */
    if (localDW->obj_ef.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_ef.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ef.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ef.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S35>/I2C Read3' */

    /* MATLABSystem: '<S35>/I2C Read4' */
    if (localDW->obj_e.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_e.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read4' */

    /* MATLABSystem: '<S35>/I2C Read5' */
    if (localDW->obj_n.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_n.SampleTime = provalogBMP_09_22_P.t_AP;
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
      /* MATLABSystem: '<S35>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read5' */

    /* MATLABSystem: '<S35>/I2C Read6' */
    if (localDW->obj_j.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_j.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read6' */

    /* MATLABSystem: '<S35>/I2C Read7' */
    if (localDW->obj_l.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_l.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read7' */

    /* MATLABSystem: '<S35>/I2C Read8' */
    if (localDW->obj_i.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_i.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S35>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read8' */

    /* MATLABSystem: '<S35>/I2C Read9' */
    if (localDW->obj.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj.SampleTime = provalogBMP_09_22_P.t_AP;
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
      /* MATLABSystem: '<S35>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read9' */

    /* MATLABSystem: '<S35>/I2C Read10' */
    if (localDW->obj_f.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_f.SampleTime = provalogBMP_09_22_P.t_AP;
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
      /* MATLABSystem: '<S35>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read10' */

    /* MATLABSystem: '<S35>/I2C Read11' */
    if (localDW->obj_p.SampleTime != provalogBMP_09_22_P.t_AP) {
      localDW->obj_p.SampleTime = provalogBMP_09_22_P.t_AP;
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
      /* MATLABSystem: '<S35>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S35>/I2C Read11' */

    /* MATLABSystem: '<S35>/I2C Write1' incorporates:
     *  Constant: '<S35>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S35>/I2C Write2' incorporates:
     *  Constant: '<S35>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_fo.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S35>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S35>/I2C Read12' */
    if (localDW->obj_a.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_a.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S35>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S35>/Byte Unpack' */

    /* Unpack: <S35>/Byte Unpack */
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
void One_time_initializatio_Term(DW_One_time_initialization_pr_T *localDW)
{
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S35>/I2C Read' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read1' */
  obj = &localDW->obj_f2;
  if (!localDW->obj_f2.matlabCodegenIsDeleted) {
    localDW->obj_f2.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f2.isInitialized == 1) && localDW->obj_f2.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read2' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read3' */
  obj = &localDW->obj_ef;
  if (!localDW->obj_ef.matlabCodegenIsDeleted) {
    localDW->obj_ef.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ef.isInitialized == 1) && localDW->obj_ef.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read4' */
  obj = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read5' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read6' */
  obj = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read7' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read8' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read10' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read11' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S35>/I2C Write1' */
  obj_0 = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S35>/I2C Write2' */
  obj_0 = &localDW->obj_fo;
  if (!localDW->obj_fo.matlabCodegenIsDeleted) {
    localDW->obj_fo.matlabCodegenIsDeleted = true;
    if ((localDW->obj_fo.isInitialized == 1) && localDW->obj_fo.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S35>/I2C Write3' */
  obj_0 = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read12' */
  obj = &localDW->obj_a;
  if (!localDW->obj_a.matlabCodegenIsDeleted) {
    localDW->obj_a.matlabCodegenIsDeleted = true;
    if ((localDW->obj_a.isInitialized == 1) && localDW->obj_a.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void provalogBMP_09_22_find_254(const uint8_T pack[100], real_T position
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
static boolean_T provalogBMP_09_22_ifWhileCond(const boolean_T x[100])
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
void provalogBMP_09_22_step0(void)     /* Sample time: [0.02s, 0.0s] */
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

  /* S-Function (Mti): '<S4>/S-Function Builder' */
  Mti_Outputs_wrapper(&provalogBMP_09_22_B.SFunctionBuilder[0],
                      &provalogBMP_09_22_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S4>/Byte Unpack' */

  /* Unpack: <S4>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&provalogBMP_09_22_B.ByteUnpack_o1[0], (uint8_T*)
             &provalogBMP_09_22_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder2 = MW_outputPortWidth % 1;
    if (MW_remainder2 == 0) {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
    } else {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
        MW_remainder2);
    }

    /* Unpacking the values to output 2 */
    /* Output data type - real32_T, size - 9 */
    {
      MW_outputPortWidth = 9 * sizeof(real32_T);
      memcpy((uint8_T*)&provalogBMP_09_22_B.ByteUnpack_o2[0], (uint8_T*)
             &provalogBMP_09_22_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder2 = MW_outputPortWidth % 1;
    if (MW_remainder2 == 0) {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
    } else {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
        MW_remainder2);
    }

    /* Unpacking the values to output 3 */
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)&provalogBMP_09_22_B.ByteUnpack_o3, (uint8_T*)
             &provalogBMP_09_22_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S4>/Byte Reversal' */

  /* ReverseEndian: <S4>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &provalogBMP_09_22_B.ByteUnpack_o2[0];
    real32_T *y0 = &provalogBMP_09_22_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&provalogBMP_09_22_P.Constant1_Value_i,
    &provalogBMP_09_22_B.SFunctionBuilder_o1_g[0],
    &provalogBMP_09_22_B.SFunctionBuilder_o2,
    &provalogBMP_09_22_DW.SFunctionBuilder_DSTATE_n);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  provalogBMP_09_22_B.status = 0;
  provalogBMP_09_22_B.caso = 0;
  memset(&provalogBMP_09_22_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  memset(&provalogBMP_09_22_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  provalogBMP_09_22_find_254(provalogBMP_09_22_B.SFunctionBuilder_o1_g,
    provalogBMP_09_22_B.poss_254, &provalogBMP_09_22_B.num_254);
  if (provalogBMP_09_22_DW.Interr_parz && (provalogBMP_09_22_B.num_254 == 1.0))
  {
    provalogBMP_09_22_B.f = (int32_T)(provalogBMP_09_22_DW.counter_o + 1U);
    if (provalogBMP_09_22_DW.counter_o + 1U > 255U) {
      provalogBMP_09_22_B.f = 255;
    }

    if (provalogBMP_09_22_B.poss_254[0] != provalogBMP_09_22_B.f) {
      provalogBMP_09_22_B.num_254 = 0.0;
    }
  }

  y = !provalogBMP_09_22_DW.Interr_parz;
  if ((provalogBMP_09_22_B.num_254 == 1.0) && y) {
    provalogBMP_09_22_B.caso = 1;
  } else if ((provalogBMP_09_22_B.num_254 == 0.0) &&
             provalogBMP_09_22_DW.Interr_parz) {
    provalogBMP_09_22_B.caso = 2;
  } else if ((provalogBMP_09_22_B.num_254 == 1.0) &&
             provalogBMP_09_22_DW.Interr_parz) {
    provalogBMP_09_22_B.caso = 3;
  } else {
    if ((provalogBMP_09_22_B.num_254 == 2.0) && y) {
      provalogBMP_09_22_B.caso = 4;
    }
  }

  switch (provalogBMP_09_22_B.caso) {
   case 1:
    provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_B.poss_254[(int32_T)
      provalogBMP_09_22_B.num_254 - 1];
    if (provalogBMP_09_22_B.RateTransition == 100.0) {
      provalogBMP_09_22_DW.message[0] =
        provalogBMP_09_22_B.SFunctionBuilder_o1_g[99];
      provalogBMP_09_22_DW.Interr_parz = true;
    } else if (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
               (provalogBMP_09_22_B.RateTransition + 1.0) - 1] <= 100) {
      provalogBMP_09_22_B.f = (int32_T)
        (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
         (provalogBMP_09_22_B.poss_254[0] + 1.0) - 1] + 8U);
      provalogBMP_09_22_B.g = provalogBMP_09_22_B.f;
      if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
        provalogBMP_09_22_B.g = 255;
      }

      if (provalogBMP_09_22_B.g == provalogBMP_09_22_B.SFunctionBuilder_o2) {
        provalogBMP_09_22_B.num_254 = rt_roundd_snf
          (provalogBMP_09_22_B.RateTransition);
        if (provalogBMP_09_22_B.num_254 < 256.0) {
          if (provalogBMP_09_22_B.num_254 >= 0.0) {
            counter = (uint8_T)provalogBMP_09_22_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provalogBMP_09_22_B.f = (int32_T)
          (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
           (provalogBMP_09_22_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
          provalogBMP_09_22_B.f = 255;
        }

        provalogBMP_09_22_B.RateTransition = rt_roundd_snf
          (provalogBMP_09_22_B.RateTransition + (real_T)provalogBMP_09_22_B.f);
        if (provalogBMP_09_22_B.RateTransition < 256.0) {
          if (provalogBMP_09_22_B.RateTransition >= 0.0) {
            c = (uint8_T)provalogBMP_09_22_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          provalogBMP_09_22_B.status = 0;
          provalogBMP_09_22_B.f = 0;
        } else {
          provalogBMP_09_22_B.status = counter - 1;
          provalogBMP_09_22_B.f = c;
        }

        provalogBMP_09_22_B.caso = provalogBMP_09_22_B.f -
          provalogBMP_09_22_B.status;
        for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <
             provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.f] =
            provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.status
            + provalogBMP_09_22_B.f];
        }

        provalogBMP_09_22_B.status = 1;
        for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 100;
             provalogBMP_09_22_B.caso++) {
          provalogBMP_09_22_B.messaggio[provalogBMP_09_22_B.caso] =
            provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso];
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso] = 0U;
        }

        provalogBMP_09_22_DW.counter_o = 0U;
        provalogBMP_09_22_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
          provalogBMP_09_22_B.f = 255;
        }

        if (provalogBMP_09_22_B.f > provalogBMP_09_22_B.SFunctionBuilder_o2) {
          provalogBMP_09_22_DW.mess_len =
            provalogBMP_09_22_B.SFunctionBuilder_o2;
          if (provalogBMP_09_22_B.RateTransition > provalogBMP_09_22_DW.mess_len)
          {
            provalogBMP_09_22_B.g = 0;
            provalogBMP_09_22_B.f = 0;
          } else {
            provalogBMP_09_22_B.g = (int32_T)provalogBMP_09_22_B.RateTransition
              - 1;
            provalogBMP_09_22_B.f = (int32_T)provalogBMP_09_22_DW.mess_len;
          }

          provalogBMP_09_22_B.caso = provalogBMP_09_22_B.f -
            provalogBMP_09_22_B.g;
          for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <
               provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
            provalogBMP_09_22_DW.message[provalogBMP_09_22_B.f] =
              provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.g +
              provalogBMP_09_22_B.f];
          }

          provalogBMP_09_22_B.f = (int32_T)
            (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
             (provalogBMP_09_22_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
            provalogBMP_09_22_B.f = 255;
          }

          provalogBMP_09_22_B.RateTransition = rt_roundd_snf((real_T)
            provalogBMP_09_22_B.f - provalogBMP_09_22_DW.mess_len);
          if (provalogBMP_09_22_B.RateTransition < 256.0) {
            if (provalogBMP_09_22_B.RateTransition >= 0.0) {
              provalogBMP_09_22_DW.counter_o = (uint8_T)
                provalogBMP_09_22_B.RateTransition;
            } else {
              provalogBMP_09_22_DW.counter_o = 0U;
            }
          } else {
            provalogBMP_09_22_DW.counter_o = MAX_uint8_T;
          }

          provalogBMP_09_22_DW.Interr_parz = true;
        }
      }
    } else {
      provalogBMP_09_22_DW.Interr_parz = false;
      memset(&provalogBMP_09_22_DW.message[0], 0, 100U * sizeof(uint8_T));
      provalogBMP_09_22_DW.counter_o = 0U;
      provalogBMP_09_22_DW.mess_len = 0.0;
      provalogBMP_09_22_B.status = 1;
    }
    break;

   case 2:
    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.x[provalogBMP_09_22_B.f] =
        (provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.f] != 0);
    }

    if (provalogBMP_09_22_ifWhileCond(provalogBMP_09_22_B.x)) {
      provalogBMP_09_22_B.RateTransition = rt_roundd_snf
        (provalogBMP_09_22_DW.mess_len + 1.0);
      if (provalogBMP_09_22_B.RateTransition < 256.0) {
        if (provalogBMP_09_22_B.RateTransition >= 0.0) {
          c = (uint8_T)provalogBMP_09_22_B.RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      provalogBMP_09_22_B.RateTransition = rt_roundd_snf
        (provalogBMP_09_22_DW.mess_len + (real_T)provalogBMP_09_22_DW.counter_o);
      if (provalogBMP_09_22_B.RateTransition < 256.0) {
        if (provalogBMP_09_22_B.RateTransition >= 0.0) {
          counter = (uint8_T)provalogBMP_09_22_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (c > counter) {
        provalogBMP_09_22_B.status = 1;
      } else {
        provalogBMP_09_22_B.status = c;
      }

      if (1 > provalogBMP_09_22_DW.counter_o) {
        provalogBMP_09_22_B.caso = -1;
      } else {
        provalogBMP_09_22_B.caso = provalogBMP_09_22_DW.counter_o - 1;
      }

      for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <=
           provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
        provalogBMP_09_22_DW.message[(provalogBMP_09_22_B.status +
          provalogBMP_09_22_B.f) - 1] =
          provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.f];
      }

      provalogBMP_09_22_DW.Interr_parz = false;
      provalogBMP_09_22_B.status = 1;
      for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 100;
           provalogBMP_09_22_B.caso++) {
        provalogBMP_09_22_B.messaggio[provalogBMP_09_22_B.caso] =
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso];
        provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso] = 0U;
      }

      provalogBMP_09_22_DW.mess_len = 0.0;
      provalogBMP_09_22_DW.counter_o = 0U;
    } else {
      provalogBMP_09_22_DW.Interr_parz = false;
      provalogBMP_09_22_B.status = 1;
      memset(&provalogBMP_09_22_DW.message[0], 0, 100U * sizeof(uint8_T));
      provalogBMP_09_22_DW.mess_len = 0.0;
      provalogBMP_09_22_DW.counter_o = 0U;
    }
    break;

   case 3:
    provalogBMP_09_22_B.RateTransition = rt_roundd_snf
      (provalogBMP_09_22_DW.mess_len + 1.0);
    if (provalogBMP_09_22_B.RateTransition < 256.0) {
      if (provalogBMP_09_22_B.RateTransition >= 0.0) {
        c = (uint8_T)provalogBMP_09_22_B.RateTransition;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    provalogBMP_09_22_B.RateTransition = rt_roundd_snf
      (provalogBMP_09_22_DW.mess_len + (real_T)provalogBMP_09_22_DW.counter_o);
    if (provalogBMP_09_22_B.RateTransition < 256.0) {
      if (provalogBMP_09_22_B.RateTransition >= 0.0) {
        counter = (uint8_T)provalogBMP_09_22_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (c > counter) {
      provalogBMP_09_22_B.status = 1;
    } else {
      provalogBMP_09_22_B.status = c;
    }

    if (1 > provalogBMP_09_22_DW.counter_o) {
      provalogBMP_09_22_B.caso = -1;
    } else {
      provalogBMP_09_22_B.caso = provalogBMP_09_22_DW.counter_o - 1;
    }

    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <=
         provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_DW.message[(provalogBMP_09_22_B.status +
        provalogBMP_09_22_B.f) - 1] =
        provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.f];
    }

    provalogBMP_09_22_DW.Interr_parz = false;
    provalogBMP_09_22_B.status = 1;
    for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 100;
         provalogBMP_09_22_B.caso++) {
      provalogBMP_09_22_B.messaggio[provalogBMP_09_22_B.caso] =
        provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso];
      provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso] = 0U;
    }

    provalogBMP_09_22_DW.mess_len = 0.0;
    provalogBMP_09_22_DW.counter_o = 0U;
    provalogBMP_09_22_B.f = (int32_T)(provalogBMP_09_22_B.poss_254[(int32_T)
      provalogBMP_09_22_B.num_254 - 1] + 1.0) - 1;
    if (provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.f] <= 100)
    {
      provalogBMP_09_22_B.g = (int32_T)
        (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
         (provalogBMP_09_22_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)provalogBMP_09_22_B.g > 255U) {
        provalogBMP_09_22_B.g = 255;
      }

      provalogBMP_09_22_B.caso = provalogBMP_09_22_B.SFunctionBuilder_o2;
      if (provalogBMP_09_22_B.SFunctionBuilder_o2 < 0) {
        provalogBMP_09_22_B.caso = 0;
      } else {
        if (provalogBMP_09_22_B.SFunctionBuilder_o2 > 255) {
          provalogBMP_09_22_B.caso = 255;
        }
      }

      if (provalogBMP_09_22_B.g == provalogBMP_09_22_B.caso) {
        provalogBMP_09_22_B.RateTransition = rt_roundd_snf
          (provalogBMP_09_22_B.poss_254[(int32_T)provalogBMP_09_22_B.num_254 - 1]);
        if (provalogBMP_09_22_B.RateTransition < 256.0) {
          if (provalogBMP_09_22_B.RateTransition >= 0.0) {
            counter = (uint8_T)provalogBMP_09_22_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provalogBMP_09_22_B.f = (int32_T)
          (provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.f] + 7U);
        if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
          provalogBMP_09_22_B.f = 255;
        }

        provalogBMP_09_22_B.RateTransition = rt_roundd_snf
          (provalogBMP_09_22_B.poss_254[(int32_T)provalogBMP_09_22_B.num_254 - 1]
           + (real_T)provalogBMP_09_22_B.f);
        if (provalogBMP_09_22_B.RateTransition < 256.0) {
          if (provalogBMP_09_22_B.RateTransition >= 0.0) {
            c = (uint8_T)provalogBMP_09_22_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          provalogBMP_09_22_B.g = 0;
          provalogBMP_09_22_B.f = 0;
        } else {
          provalogBMP_09_22_B.g = counter - 1;
          provalogBMP_09_22_B.f = c;
        }

        provalogBMP_09_22_B.caso = provalogBMP_09_22_B.f - provalogBMP_09_22_B.g;
        for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <
             provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.f] =
            provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.g +
            provalogBMP_09_22_B.f];
        }

        for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 100;
             provalogBMP_09_22_B.caso++) {
          provalogBMP_09_22_B.messaggio_2[provalogBMP_09_22_B.caso] =
            provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso];
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso] = 0U;
        }

        provalogBMP_09_22_DW.counter_o = 0U;
        provalogBMP_09_22_DW.mess_len = 0.0;
      } else {
        provalogBMP_09_22_B.g = (int32_T)
          (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
           (provalogBMP_09_22_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)provalogBMP_09_22_B.g > 255U) {
          provalogBMP_09_22_B.g = 255;
        }

        provalogBMP_09_22_B.caso = provalogBMP_09_22_B.SFunctionBuilder_o2;
        if (provalogBMP_09_22_B.SFunctionBuilder_o2 < 0) {
          provalogBMP_09_22_B.caso = 0;
        } else {
          if (provalogBMP_09_22_B.SFunctionBuilder_o2 > 255) {
            provalogBMP_09_22_B.caso = 255;
          }
        }

        if (provalogBMP_09_22_B.g > provalogBMP_09_22_B.caso) {
          provalogBMP_09_22_DW.mess_len =
            provalogBMP_09_22_B.SFunctionBuilder_o2;
          if (provalogBMP_09_22_B.poss_254[(int32_T)provalogBMP_09_22_B.num_254
              - 1] > provalogBMP_09_22_DW.mess_len) {
            provalogBMP_09_22_B.x_m = 0;
            provalogBMP_09_22_B.caso = 0;
          } else {
            provalogBMP_09_22_B.x_m = (int32_T)provalogBMP_09_22_B.poss_254
              [(int32_T)provalogBMP_09_22_B.num_254 - 1] - 1;
            provalogBMP_09_22_B.caso = (int32_T)provalogBMP_09_22_DW.mess_len;
          }

          provalogBMP_09_22_B.caso -= provalogBMP_09_22_B.x_m;
          for (provalogBMP_09_22_B.g = 0; provalogBMP_09_22_B.g <
               provalogBMP_09_22_B.caso; provalogBMP_09_22_B.g++) {
            provalogBMP_09_22_DW.message[provalogBMP_09_22_B.g] =
              provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.x_m
              + provalogBMP_09_22_B.g];
          }

          provalogBMP_09_22_B.f = (int32_T)
            (provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.f] +
             8U);
          if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
            provalogBMP_09_22_B.f = 255;
          }

          provalogBMP_09_22_B.RateTransition = rt_roundd_snf((real_T)
            provalogBMP_09_22_B.f - provalogBMP_09_22_DW.mess_len);
          if (provalogBMP_09_22_B.RateTransition < 256.0) {
            if (provalogBMP_09_22_B.RateTransition >= 0.0) {
              provalogBMP_09_22_DW.counter_o = (uint8_T)
                provalogBMP_09_22_B.RateTransition;
            } else {
              provalogBMP_09_22_DW.counter_o = 0U;
            }
          } else {
            provalogBMP_09_22_DW.counter_o = MAX_uint8_T;
          }

          provalogBMP_09_22_DW.Interr_parz = true;
        }
      }
    } else {
      provalogBMP_09_22_DW.Interr_parz = false;
      memset(&provalogBMP_09_22_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      memset(&provalogBMP_09_22_DW.message[0], 0, 100U * sizeof(uint8_T));
      provalogBMP_09_22_DW.counter_o = 0U;
      provalogBMP_09_22_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
        (provalogBMP_09_22_B.poss_254[0] + 1.0) - 1] <= 100) {
      provalogBMP_09_22_B.RateTransition = rt_roundd_snf
        (provalogBMP_09_22_B.poss_254[0]);
      if (provalogBMP_09_22_B.RateTransition < 256.0) {
        if (provalogBMP_09_22_B.RateTransition >= 0.0) {
          counter = (uint8_T)provalogBMP_09_22_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      provalogBMP_09_22_B.f = (int32_T)
        (provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
         (provalogBMP_09_22_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)provalogBMP_09_22_B.f > 255U) {
        provalogBMP_09_22_B.f = 255;
      }

      provalogBMP_09_22_B.RateTransition = rt_roundd_snf
        (provalogBMP_09_22_B.poss_254[0] + (real_T)provalogBMP_09_22_B.f);
      if (provalogBMP_09_22_B.RateTransition < 256.0) {
        if (provalogBMP_09_22_B.RateTransition >= 0.0) {
          c = (uint8_T)provalogBMP_09_22_B.RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      if (counter > c) {
        provalogBMP_09_22_B.status = 0;
        provalogBMP_09_22_B.f = 0;
      } else {
        provalogBMP_09_22_B.status = counter - 1;
        provalogBMP_09_22_B.f = c;
      }

      provalogBMP_09_22_B.caso = provalogBMP_09_22_B.f -
        provalogBMP_09_22_B.status;
      for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <
           provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
        provalogBMP_09_22_B.messaggio[provalogBMP_09_22_B.f] =
          provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.status +
          provalogBMP_09_22_B.f];
      }
    } else {
      provalogBMP_09_22_DW.Interr_parz = false;
      memset(&provalogBMP_09_22_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    provalogBMP_09_22_B.status = 1;
    if ((provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
         (provalogBMP_09_22_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (provalogBMP_09_22_B.poss_254[1] - provalogBMP_09_22_B.poss_254[0] > 3.0))
    {
      provalogBMP_09_22_B.RateTransition = rt_roundd_snf((real_T)
        provalogBMP_09_22_B.SFunctionBuilder_o2 - provalogBMP_09_22_B.poss_254[1]);
      qY = provalogBMP_09_22_B.SFunctionBuilder_o1_g[(int32_T)
        (provalogBMP_09_22_B.poss_254[1] + 1.0) - 1];
      provalogBMP_09_22_B.f = (int32_T)(qY + 7U);
      if (qY + 7U > 255U) {
        provalogBMP_09_22_B.f = 255;
      }

      if (provalogBMP_09_22_B.RateTransition < 2.147483648E+9) {
        if (provalogBMP_09_22_B.RateTransition >= -2.147483648E+9) {
          provalogBMP_09_22_B.g = (int32_T)provalogBMP_09_22_B.RateTransition;
        } else {
          provalogBMP_09_22_B.g = MIN_int32_T;
        }
      } else {
        provalogBMP_09_22_B.g = MAX_int32_T;
      }

      if (provalogBMP_09_22_B.g == provalogBMP_09_22_B.f) {
        provalogBMP_09_22_B.RateTransition = rt_roundd_snf
          (provalogBMP_09_22_B.poss_254[1]);
        if (provalogBMP_09_22_B.RateTransition < 256.0) {
          if (provalogBMP_09_22_B.RateTransition >= 0.0) {
            counter = (uint8_T)provalogBMP_09_22_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provalogBMP_09_22_B.f = (int32_T)(qY + 7U);
        if (qY + 7U > 255U) {
          provalogBMP_09_22_B.f = 255;
        }

        provalogBMP_09_22_B.RateTransition = rt_roundd_snf
          (provalogBMP_09_22_B.poss_254[1] + (real_T)provalogBMP_09_22_B.f);
        if (provalogBMP_09_22_B.RateTransition < 256.0) {
          if (provalogBMP_09_22_B.RateTransition >= 0.0) {
            c = (uint8_T)provalogBMP_09_22_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          provalogBMP_09_22_B.status = 0;
          provalogBMP_09_22_B.f = 0;
        } else {
          provalogBMP_09_22_B.status = counter - 1;
          provalogBMP_09_22_B.f = c;
        }

        provalogBMP_09_22_B.caso = provalogBMP_09_22_B.f -
          provalogBMP_09_22_B.status;
        for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <
             provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.f] =
            provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.status
            + provalogBMP_09_22_B.f];
        }

        provalogBMP_09_22_B.status = 2;
        for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 100;
             provalogBMP_09_22_B.caso++) {
          provalogBMP_09_22_B.messaggio_2[provalogBMP_09_22_B.caso] =
            provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso];
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.caso] = 0U;
        }

        provalogBMP_09_22_DW.counter_o = 0U;
        provalogBMP_09_22_DW.mess_len = 0.0;
      } else {
        provalogBMP_09_22_B.RateTransition = rt_roundd_snf
          (provalogBMP_09_22_B.poss_254[1]);
        if (provalogBMP_09_22_B.RateTransition < 2.147483648E+9) {
          if (provalogBMP_09_22_B.RateTransition >= -2.147483648E+9) {
            provalogBMP_09_22_B.f = (int32_T)provalogBMP_09_22_B.RateTransition;
          } else {
            provalogBMP_09_22_B.f = MIN_int32_T;
          }
        } else {
          provalogBMP_09_22_B.f = MAX_int32_T;
        }

        if (provalogBMP_09_22_B.f > provalogBMP_09_22_B.SFunctionBuilder_o2) {
          provalogBMP_09_22_B.f = -1;
          provalogBMP_09_22_B.caso = 0;
        } else {
          provalogBMP_09_22_B.f -= 2;
          provalogBMP_09_22_B.caso = provalogBMP_09_22_B.SFunctionBuilder_o2;
        }

        provalogBMP_09_22_DW.mess_len = (int8_T)((provalogBMP_09_22_B.caso -
          provalogBMP_09_22_B.f) - 1);
        if (provalogBMP_09_22_B.RateTransition < 2.147483648E+9) {
          if (provalogBMP_09_22_B.RateTransition >= -2.147483648E+9) {
            provalogBMP_09_22_B.f = (int32_T)provalogBMP_09_22_B.RateTransition;
          } else {
            provalogBMP_09_22_B.f = MIN_int32_T;
          }
        } else {
          provalogBMP_09_22_B.f = MAX_int32_T;
        }

        if (provalogBMP_09_22_B.f > provalogBMP_09_22_B.SFunctionBuilder_o2) {
          provalogBMP_09_22_B.g = 0;
          provalogBMP_09_22_B.f = 0;
        } else {
          provalogBMP_09_22_B.g = provalogBMP_09_22_B.f - 1;
          provalogBMP_09_22_B.f = provalogBMP_09_22_B.SFunctionBuilder_o2;
        }

        provalogBMP_09_22_B.caso = provalogBMP_09_22_B.f - provalogBMP_09_22_B.g;
        for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f <
             provalogBMP_09_22_B.caso; provalogBMP_09_22_B.f++) {
          provalogBMP_09_22_DW.message[provalogBMP_09_22_B.f] =
            provalogBMP_09_22_B.SFunctionBuilder_o1_g[provalogBMP_09_22_B.g +
            provalogBMP_09_22_B.f];
        }

        provalogBMP_09_22_B.f = (int32_T)(qY + 8U);
        if (qY + 8U > 255U) {
          provalogBMP_09_22_B.f = 255;
        }

        provalogBMP_09_22_B.RateTransition = rt_roundd_snf((real_T)
          provalogBMP_09_22_B.f - provalogBMP_09_22_DW.mess_len);
        if (provalogBMP_09_22_B.RateTransition < 256.0) {
          if (provalogBMP_09_22_B.RateTransition >= 0.0) {
            provalogBMP_09_22_DW.counter_o = (uint8_T)
              provalogBMP_09_22_B.RateTransition;
          } else {
            provalogBMP_09_22_DW.counter_o = 0U;
          }
        } else {
          provalogBMP_09_22_DW.counter_o = MAX_uint8_T;
        }

        provalogBMP_09_22_DW.Interr_parz = true;
      }
    } else {
      provalogBMP_09_22_DW.Interr_parz = false;
      memset(&provalogBMP_09_22_DW.message[0], 0, 100U * sizeof(uint8_T));
      provalogBMP_09_22_DW.counter_o = 0U;
      provalogBMP_09_22_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&provalogBMP_09_22_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
       provalogBMP_09_22_B.f++) {
    provalogBMP_09_22_B.buffer[3 * provalogBMP_09_22_B.f] = 0U;
  }

  for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
       provalogBMP_09_22_B.f++) {
    for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 2;
         provalogBMP_09_22_B.caso++) {
      provalogBMP_09_22_B.g = 3 * provalogBMP_09_22_B.f +
        provalogBMP_09_22_B.caso;
      provalogBMP_09_22_B.buffer[provalogBMP_09_22_B.g + 1] =
        provalogBMP_09_22_DW.Memory4_PreviousInput[provalogBMP_09_22_B.g];
    }
  }

  provalogBMP_09_22_B.caso = 3;
  exitg1 = false;
  while ((!exitg1) && (provalogBMP_09_22_B.caso >= 1)) {
    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.x[provalogBMP_09_22_B.f] =
        (provalogBMP_09_22_B.buffer[(3 * provalogBMP_09_22_B.f +
          provalogBMP_09_22_B.caso) - 1] == 0);
    }

    y = true;
    provalogBMP_09_22_B.f = 0;
    exitg2 = false;
    while ((!exitg2) && (provalogBMP_09_22_B.f < 100)) {
      if (!provalogBMP_09_22_B.x[provalogBMP_09_22_B.f]) {
        y = false;
        exitg2 = true;
      } else {
        provalogBMP_09_22_B.f++;
      }
    }

    if (y) {
      counter = (uint8_T)provalogBMP_09_22_B.caso;
      exitg1 = true;
    } else {
      provalogBMP_09_22_B.caso--;
    }
  }

  if (provalogBMP_09_22_B.status == 1) {
    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.buffer[(counter + 3 * provalogBMP_09_22_B.f) - 1] =
        provalogBMP_09_22_B.messaggio[provalogBMP_09_22_B.f];
    }
  } else if (provalogBMP_09_22_B.status == 2) {
    qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      qY = 0U;
    }

    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.buffer[(counter + 3 * provalogBMP_09_22_B.f) - 1] =
        provalogBMP_09_22_B.messaggio[provalogBMP_09_22_B.f];
      provalogBMP_09_22_B.buffer[((int32_T)qY + 3 * provalogBMP_09_22_B.f) - 1] =
        provalogBMP_09_22_B.messaggio_2[provalogBMP_09_22_B.f];
    }
  } else {
    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.buffer[(counter + 3 * provalogBMP_09_22_B.f) - 1] = 0U;
    }
  }

  for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
       provalogBMP_09_22_B.f++) {
    provalogBMP_09_22_B.mess_out[provalogBMP_09_22_B.f] =
      provalogBMP_09_22_DW.Memory4_PreviousInput[3 * provalogBMP_09_22_B.f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  provalogBMP_09_22_B.Add = provalogBMP_09_22_DW.Memory4_PreviousInput[5] +
    provalogBMP_09_22_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (provalogBMP_09_22_B.mess_out[2] !=
      provalogBMP_09_22_DW.Memory5_PreviousInput[2]) {
    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 100;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.x[provalogBMP_09_22_B.f] =
        (provalogBMP_09_22_B.mess_out[provalogBMP_09_22_B.f] != 0);
    }

    y = true;
    provalogBMP_09_22_B.f = 0;
    exitg1 = false;
    while ((!exitg1) && (provalogBMP_09_22_B.f < 100)) {
      if (!provalogBMP_09_22_B.x[provalogBMP_09_22_B.f]) {
        y = false;
        exitg1 = true;
      } else {
        provalogBMP_09_22_B.f++;
      }
    }

    if (!y) {
      if (provalogBMP_09_22_DW.counter > 100) {
        provalogBMP_09_22_DW.counter = 0U;
      }

      qY = provalogBMP_09_22_DW.counter + 1U;
      if (provalogBMP_09_22_DW.counter + 1U > 65535U) {
        qY = 65535U;
      }

      provalogBMP_09_22_DW.counter = (uint16_T)qY;
    }
  }

  provalogBMP_09_22_B.new_mex = provalogBMP_09_22_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  provalogBMP_09_22_B.Memory1[0] = provalogBMP_09_22_DW.Memory1_PreviousInput_c
    [0];
  provalogBMP_09_22_B.Memory1[1] = provalogBMP_09_22_DW.Memory1_PreviousInput_c
    [1];

  /* Memory: '<Root>/Memory' */
  provalogBMP_09_22_B.Memory_c[0] = provalogBMP_09_22_DW.Memory_PreviousInput_i
    [0];
  provalogBMP_09_22_B.Memory_c[1] = provalogBMP_09_22_DW.Memory_PreviousInput_i
    [1];
  provalogBMP_09_22_B.Memory_c[2] = provalogBMP_09_22_DW.Memory_PreviousInput_i
    [2];
  provalogBMP_09_22_B.Memory_c[3] = provalogBMP_09_22_DW.Memory_PreviousInput_i
    [3];

  /* Memory: '<S1>/Memory3' */
  provalogBMP_09_22_B.Memory3 = provalogBMP_09_22_DW.Memory3_PreviousInput;
  for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 8;
       provalogBMP_09_22_B.caso++) {
    /* Memory: '<S1>/Memory' */
    provalogBMP_09_22_B.Memory[provalogBMP_09_22_B.caso] =
      provalogBMP_09_22_DW.Memory_PreviousInput_c[provalogBMP_09_22_B.caso];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&provalogBMP_09_22_B.mess_out[0], &provalogBMP_09_22_B.Add,
     &provalogBMP_09_22_B.new_mex, &provalogBMP_09_22_P.SIUAVuint8_Value,
     &provalogBMP_09_22_B.Memory[0], &provalogBMP_09_22_B.Memory1[0],
     &provalogBMP_09_22_B.Memory_c[0], &provalogBMP_09_22_B.Memory3,
     &provalogBMP_09_22_B.SFunction_o1[0], &provalogBMP_09_22_B.SFunction_o2,
     &provalogBMP_09_22_B.SFunction_o3_j, &provalogBMP_09_22_B.SFunction_o4_b[0],
     &provalogBMP_09_22_B.SFunction_o5[0], &provalogBMP_09_22_B.SFunction_o6,
     &provalogBMP_09_22_B.SFunction_o7[0], &provalogBMP_09_22_B.SFunction_o8,
     &provalogBMP_09_22_B.SFunction_o9[0], &provalogBMP_09_22_B.SFunction_o10[0],
     &provalogBMP_09_22_B.SFunction_o11[0], &provalogBMP_09_22_B.SFunction_o12,
     &provalogBMP_09_22_B.SFunction_o13, &provalogBMP_09_22_B.SFunction_o14,
     &provalogBMP_09_22_B.SFunction_o15, &provalogBMP_09_22_B.SFunction_o16,
     &provalogBMP_09_22_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 9;
       provalogBMP_09_22_B.caso++) {
    provalogBMP_09_22_B.Memory2[provalogBMP_09_22_B.caso] =
      provalogBMP_09_22_DW.Memory2_PreviousInput_i[provalogBMP_09_22_B.caso];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 6;
       provalogBMP_09_22_B.caso++) {
    provalogBMP_09_22_B.WP_info_in[provalogBMP_09_22_B.caso] =
      provalogBMP_09_22_B.SFunction_o9[provalogBMP_09_22_B.caso];
  }

  if ((!provalogBMP_09_22_DW.WP_dbP_not_empty) ||
      ((provalogBMP_09_22_B.SFunction_o7[0] == 3) &&
       (provalogBMP_09_22_B.SFunction_o7[1] == 250))) {
    memset(&provalogBMP_09_22_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    provalogBMP_09_22_DW.WP_dbP_not_empty = true;
    memset(&provalogBMP_09_22_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!provalogBMP_09_22_DW.WP_dbP_AL_not_empty) ||
      ((provalogBMP_09_22_B.SFunction_o7[0] == 3) &&
       (provalogBMP_09_22_B.SFunction_o7[1] == 250))) {
    memset(&provalogBMP_09_22_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    provalogBMP_09_22_DW.WP_dbP_AL_not_empty = true;
  }

  provalogBMP_09_22_B.GC_info[0] = provalogBMP_09_22_B.SFunction_o7[0];
  provalogBMP_09_22_B.GC_info[1] = provalogBMP_09_22_B.SFunction_o7[1];
  provalogBMP_09_22_B.GC_info[2] = provalogBMP_09_22_B.SFunction_o11[0];
  if (provalogBMP_09_22_B.GC_info[0] == 1) {
    if ((provalogBMP_09_22_B.GC_info[1] > 0) && (provalogBMP_09_22_B.GC_info[1] <=
         7)) {
      if ((real32_T)fabs(provalogBMP_09_22_B.SFunction_o8) > 0.0F) {
        provalogBMP_09_22_DW.riferimenti[provalogBMP_09_22_B.GC_info[1] - 1] =
          1.0F;
      } else {
        if (provalogBMP_09_22_B.SFunction_o8 == 0.0F) {
          provalogBMP_09_22_DW.riferimenti[provalogBMP_09_22_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((provalogBMP_09_22_B.GC_info[1] > 7) && (provalogBMP_09_22_B.GC_info[1]
           < 12)) {
        provalogBMP_09_22_DW.riferimenti[provalogBMP_09_22_B.GC_info[1] - 1] =
          provalogBMP_09_22_B.SFunction_o8;
      }
    }
  }

  if (provalogBMP_09_22_B.SFunction_o12 == 13) {
    provalogBMP_09_22_DW.riferimenti[provalogBMP_09_22_B.SFunction_o12 - 1] =
      provalogBMP_09_22_B.SFunction_o13;
  }

  memcpy(&provalogBMP_09_22_B.Val_out_MAV[0], &provalogBMP_09_22_DW.riferimenti
         [0], sizeof(real32_T) << 4U);
  if ((provalogBMP_09_22_B.GC_info[0] == 3) && (provalogBMP_09_22_B.GC_info[1] ==
       200)) {
    if (provalogBMP_09_22_B.SFunction_o9[0] > 6) {
      provalogBMP_09_22_B.WP_info_in[0] = 6U;
    }

    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 6;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_DW.WP_dbI[provalogBMP_09_22_B.f] =
        provalogBMP_09_22_B.WP_info_in[0];
    }
  }

  if ((provalogBMP_09_22_B.GC_info[0] == 3) && (provalogBMP_09_22_B.GC_info[1] <
       200)) {
    if (provalogBMP_09_22_B.SFunction_o10[1] == 0.0F) {
      qY = provalogBMP_09_22_B.SFunction_o9[1] + 1U;
      if (provalogBMP_09_22_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 7;
           provalogBMP_09_22_B.f++) {
        provalogBMP_09_22_DW.WP_dbP[((int32_T)qY + 6 * provalogBMP_09_22_B.f) -
          1] = provalogBMP_09_22_B.SFunction_o10[provalogBMP_09_22_B.f];
      }

      qY = provalogBMP_09_22_B.SFunction_o9[1] + 1U;
      if (provalogBMP_09_22_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 6;
           provalogBMP_09_22_B.f++) {
        provalogBMP_09_22_DW.WP_dbI[((int32_T)qY + 6 * (provalogBMP_09_22_B.f +
          1)) - 1] = provalogBMP_09_22_B.WP_info_in[provalogBMP_09_22_B.f + 1];
      }
    } else {
      provalogBMP_09_22_B.f = (int32_T)(provalogBMP_09_22_B.SFunction_o10[0] +
        1.0F);
      for (provalogBMP_09_22_B.g = 0; provalogBMP_09_22_B.g < 7;
           provalogBMP_09_22_B.g++) {
        provalogBMP_09_22_DW.WP_dbP_AL[(provalogBMP_09_22_B.f + 6 *
          provalogBMP_09_22_B.g) - 1] =
          provalogBMP_09_22_B.SFunction_o10[provalogBMP_09_22_B.g];
      }

      qY = provalogBMP_09_22_B.SFunction_o9[1] + 1U;
      if (provalogBMP_09_22_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 6;
           provalogBMP_09_22_B.f++) {
        provalogBMP_09_22_DW.WP_dbI[((int32_T)qY + 6 * (provalogBMP_09_22_B.f +
          1)) - 1] = provalogBMP_09_22_B.WP_info_in[provalogBMP_09_22_B.f + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provalogBMP_09_22_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((provalogBMP_09_22_B.SFunction_o6 == 0) &&
      (provalogBMP_09_22_B.SFunction_o3_j == 0)) {
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 0U;
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provalogBMP_09_22_DW.Memory3_PreviousInput = 0U;
  } else if ((provalogBMP_09_22_B.SFunction_o6 == 0) &&
             (provalogBMP_09_22_B.SFunction_o3_j == 3)) {
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 0U;
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provalogBMP_09_22_DW.Memory3_PreviousInput = 0U;
    provalogBMP_09_22_DW.test1 = 0.0;
  } else if ((provalogBMP_09_22_B.SFunction_o6 == 0) &&
             (provalogBMP_09_22_B.SFunction_o3_j == 2)) {
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 0U;
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provalogBMP_09_22_DW.Memory3_PreviousInput = 0U;
    provalogBMP_09_22_DW.test1 = 0.0;
  } else if ((provalogBMP_09_22_B.SFunction_o6 == 0) &&
             (provalogBMP_09_22_B.SFunction_o3_j == 1)) {
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 0U;
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    provalogBMP_09_22_DW.Memory3_PreviousInput = 0U;
    provalogBMP_09_22_DW.test1 = 1.0;
  } else {
    switch (provalogBMP_09_22_B.SFunction_o6) {
     case 192:
      provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 192U;
      provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      provalogBMP_09_22_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 208U;
      provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      provalogBMP_09_22_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((provalogBMP_09_22_B.SFunction_o6 == 220) &&
          (provalogBMP_09_22_B.SFunction_o3_j != 5)) {
        if ((provalogBMP_09_22_B.Memory2[0] == 0) &&
            (provalogBMP_09_22_B.Memory2[1] == 0) &&
            ((provalogBMP_09_22_B.Memory2[2] == 1) ||
             (provalogBMP_09_22_B.Memory2[3] == 1) ||
             (provalogBMP_09_22_B.Memory2[4] == 1) ||
             (provalogBMP_09_22_B.Memory2[5] == 1) ||
             (provalogBMP_09_22_B.Memory2[6] == 1) ||
             (provalogBMP_09_22_B.Memory2[7] == 1))) {
          provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 220U;
          provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          provalogBMP_09_22_DW.Memory3_PreviousInput = 220U;
        } else if ((provalogBMP_09_22_B.Memory2[0] == 0) &&
                   (provalogBMP_09_22_B.Memory2[1] == 1) &&
                   ((provalogBMP_09_22_B.Memory2[2] == 1) ||
                    (provalogBMP_09_22_B.Memory2[3] == 1) ||
                    (provalogBMP_09_22_B.Memory2[4] == 1) ||
                    (provalogBMP_09_22_B.Memory2[5] == 1) ||
                    (provalogBMP_09_22_B.Memory2[6] == 1) ||
                    (provalogBMP_09_22_B.Memory2[7] == 1))) {
          provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 220U;
          provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          provalogBMP_09_22_DW.Memory3_PreviousInput = 220U;
        } else {
          provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 208U;
          provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          provalogBMP_09_22_DW.Memory3_PreviousInput = 208U;
        }
      } else if (provalogBMP_09_22_B.SFunction_o3_j == 5) {
        provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 220U;
        provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] = 192U;
        provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  qY = 100U * provalogBMP_09_22_B.SFunction_o11[5];
  if (qY > 65535U) {
    qY = 65535U;
  }

  if (provalogBMP_09_22_B.SFunction_o11[4] == 0) {
    if ((uint16_T)qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(provalogBMP_09_22_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
                   (uint32_T)(uint16_T)qY / provalogBMP_09_22_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)z *
      provalogBMP_09_22_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)provalogBMP_09_22_B.SFunction_o11[4]
          >> 1) + (provalogBMP_09_22_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  /* RateTransition: '<S24>/Rate Transition' */
  provalogBMP_09_22_B.RateTransition =
    provalogBMP_09_22_DW.RateTransition_Buffer0;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Constant: '<S24>/Constant3'
   *  Memory: '<S24>/Memory1'
   *  Sum: '<S24>/Add1'
   */
  provalogBMP_09_22_DW.Memory1_PreviousInput +=
    provalogBMP_09_22_P.Constant2_Value_e +
    provalogBMP_09_22_P.Constant3_Value_n;

  /* Switch: '<S24>/Switch' */
  if (provalogBMP_09_22_DW.Memory1_PreviousInput >
      provalogBMP_09_22_P.Switch_Threshold) {
    /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
     *  Constant: '<S24>/Constant2'
     */
    provalogBMP_09_22_DW.Memory1_PreviousInput =
      provalogBMP_09_22_P.Constant2_Value_e;
  }

  /* End of Switch: '<S24>/Switch' */

  /* MATLAB Function: '<S13>/iflogic_function' */
  if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 1.0) ||
      (provalogBMP_09_22_DW.Memory1_PreviousInput == 3.0)) {
    provalogBMP_09_22_B.iflogic = 26U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 2.0) ||
             (provalogBMP_09_22_DW.Memory1_PreviousInput == 4.0)) {
    provalogBMP_09_22_B.iflogic = 30U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             (provalogBMP_09_22_B.RateTransition == 2.0)) {
    provalogBMP_09_22_B.iflogic = 33U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             (provalogBMP_09_22_B.RateTransition == 6.0)) {
    provalogBMP_09_22_B.iflogic = 34U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             (provalogBMP_09_22_B.RateTransition == 0.0)) {
    provalogBMP_09_22_B.iflogic = 0U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             ((provalogBMP_09_22_B.RateTransition == 1.0) ||
              (provalogBMP_09_22_B.RateTransition == 5.0) ||
              (provalogBMP_09_22_B.RateTransition == 9.0))) {
    provalogBMP_09_22_B.iflogic = 1U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             ((provalogBMP_09_22_B.RateTransition == 3.0) ||
              (provalogBMP_09_22_B.RateTransition == 8.0))) {
    provalogBMP_09_22_B.iflogic = 74U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             (provalogBMP_09_22_B.RateTransition == 7.0)) {
    provalogBMP_09_22_B.iflogic = 36U;
  } else if ((provalogBMP_09_22_DW.Memory1_PreviousInput == 0.0) &&
             (provalogBMP_09_22_B.RateTransition == 4.0)) {
    provalogBMP_09_22_B.iflogic = 29U;
  } else {
    provalogBMP_09_22_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S13>/iflogic_function' */

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S24>/Constant1'
   *  Memory: '<S24>/Memory'
   */
  provalogBMP_09_22_DW.Memory_PreviousInput +=
    provalogBMP_09_22_P.Constant_Value + provalogBMP_09_22_P.Constant1_Value_e;

  /* Gain: '<S13>/Gain' */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain_Gain *
    provalogBMP_09_22_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3 = provalogBMP_09_22_B.RateTransition <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-provalogBMP_09_22_B.RateTransition :
    (uint32_T)provalogBMP_09_22_B.RateTransition;

  /* MATLAB Function: '<S20>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 6;
       provalogBMP_09_22_B.f++) {
    provalogBMP_09_22_B.WP_info[provalogBMP_09_22_B.f] =
      provalogBMP_09_22_DW.WP_dbI[6 * provalogBMP_09_22_B.f];
  }

  for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 7;
       provalogBMP_09_22_B.f++) {
    provalogBMP_09_22_B.WP_param[provalogBMP_09_22_B.f] =
      provalogBMP_09_22_DW.WP_dbP[6 * provalogBMP_09_22_B.f];
  }

  if ((provalogBMP_09_22_B.GC_info[0] == 2) && (provalogBMP_09_22_B.GC_info[1] <
       6)) {
    qY = provalogBMP_09_22_B.GC_info[1] + 1U;
    if (provalogBMP_09_22_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 6;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.WP_info[provalogBMP_09_22_B.f] =
        provalogBMP_09_22_DW.WP_dbI[(6 * provalogBMP_09_22_B.f + (int32_T)qY) -
        1];
    }

    qY = provalogBMP_09_22_B.GC_info[1] + 1U;
    if (provalogBMP_09_22_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 7;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.WP_param[provalogBMP_09_22_B.f] =
        provalogBMP_09_22_DW.WP_dbP[(6 * provalogBMP_09_22_B.f + (int32_T)qY) -
        1];
    }
  }

  if ((provalogBMP_09_22_B.GC_info[0] == 3) && (provalogBMP_09_22_B.GC_info[1] <
       200)) {
    qY = provalogBMP_09_22_B.GC_info[1] + 1U;
    if (provalogBMP_09_22_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (provalogBMP_09_22_B.f = 0; provalogBMP_09_22_B.f < 6;
         provalogBMP_09_22_B.f++) {
      provalogBMP_09_22_B.WP_info[provalogBMP_09_22_B.f] =
        provalogBMP_09_22_DW.WP_dbI[(6 * provalogBMP_09_22_B.f + (int32_T)qY) -
        1];
    }
  }

  /* End of MATLAB Function: '<S20>/MATLAB Function' */

  /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
   *  Constant: '<S18>/onboard_control_sensor_present uint32'
   */
  provalogBMP_09_22_B.onboard[0] =
    provalogBMP_09_22_P.onboard_control_sensor_presentu[0];
  provalogBMP_09_22_B.onboard[1] =
    provalogBMP_09_22_P.onboard_control_sensor_presentu[1];
  provalogBMP_09_22_B.onboard[2] =
    provalogBMP_09_22_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_P.Gain_Gain_n *
    provalogBMP_09_22_P.Constant_Value_g);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
   *  Constant: '<S18>/load uint16'
   *  Gain: '<S18>/Gain'
   */
  provalogBMP_09_22_B.LVDE[0] = provalogBMP_09_22_P.loaduint16_Value;
  provalogBMP_09_22_B.LVDE[1] = (uint16_T)(provalogBMP_09_22_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  qY = 10U * z;
  if (qY > 65535U) {
    qY = 65535U;
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
   *  Constant: '<S18>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provalogBMP_09_22_B.LVDE[2] = (uint16_T)qY;
  provalogBMP_09_22_B.LVDE[3] = provalogBMP_09_22_B.SFunction_o11[6];
  provalogBMP_09_22_B.LVDE[4] = provalogBMP_09_22_B.SFunction_o11[2];
  provalogBMP_09_22_B.LVDE[5] = provalogBMP_09_22_P._Value;

  /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant1_Value_o[0]);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion4'
   */
  provalogBMP_09_22_B.LVDE[6] = (uint16_T)(provalogBMP_09_22_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant1_Value_o[1]);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion4'
   */
  provalogBMP_09_22_B.LVDE[7] = (uint16_T)(provalogBMP_09_22_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* Gain: '<S18>/Gain2' incorporates:
   *  Constant: '<S18>/Constant3'
   */
  provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_P.Gain2_Gain *
    provalogBMP_09_22_P.Constant3_Value_d);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Gain: '<S18>/Gain2'
   */
  provalogBMP_09_22_B.B_Current = (int16_T)(((provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(int16_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition) * provalogBMP_09_22_P.Gain1_Gain_l) >>
    18);

  /* DataTypeConversion: '<S18>/Data Type Conversion3' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant2_Value_l);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion3' */
  provalogBMP_09_22_B.B_Remaining = (int8_T)(provalogBMP_09_22_B.RateTransition <
    0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-provalogBMP_09_22_B.RateTransition
    : (int32_T)(int8_T)(uint8_T)provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant_Value_a);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion = provalogBMP_09_22_B.RateTransition <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-provalogBMP_09_22_B.RateTransition :
    (uint32_T)provalogBMP_09_22_B.RateTransition;

  /* MATLAB Function: '<S11>/Alarm set' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  rtb_H_mav[0] = provalogBMP_09_22_DW.Memory1_PreviousInput_c[0];
  rtb_H_mav[1] = provalogBMP_09_22_DW.Memory1_PreviousInput_c[1];
  if (provalogBMP_09_22_P.Constant1_Value_k[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (provalogBMP_09_22_P.Constant1_Value_k[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S11>/Alarm set' */

  /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
   *  Constant: '<S11>/Type fixed_wing Autopilot generic'
   */
  provalogBMP_09_22_B.DataTypeConversion1_c[0] =
    provalogBMP_09_22_P.Typefixed_wingAutopilotgeneric_[0];
  provalogBMP_09_22_B.DataTypeConversion1_c[1] =
    provalogBMP_09_22_P.Typefixed_wingAutopilotgeneric_[1];
  provalogBMP_09_22_B.DataTypeConversion1_c[2] = rtb_H_mav[0];
  provalogBMP_09_22_B.DataTypeConversion1_c[3] = rtb_H_mav[1];

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (provalogBMP_09_22_B.ByteReversal[6] < 0.0F) {
    tmp = (real32_T)ceil(provalogBMP_09_22_B.ByteReversal[6]);
  } else {
    tmp = (real32_T)floor(provalogBMP_09_22_B.ByteReversal[6]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[0] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (provalogBMP_09_22_B.ByteReversal[7] < 0.0F) {
    tmp = (real32_T)ceil(provalogBMP_09_22_B.ByteReversal[7]);
  } else {
    tmp = (real32_T)floor(provalogBMP_09_22_B.ByteReversal[7]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[1] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (provalogBMP_09_22_B.ByteReversal[8] < 0.0F) {
    tmp = (real32_T)ceil(provalogBMP_09_22_B.ByteReversal[8]);
  } else {
    tmp = (real32_T)floor(provalogBMP_09_22_B.ByteReversal[8]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[2] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (provalogBMP_09_22_B.ByteReversal[3] < 0.0F) {
    tmp = (real32_T)ceil(provalogBMP_09_22_B.ByteReversal[3]);
  } else {
    tmp = (real32_T)floor(provalogBMP_09_22_B.ByteReversal[3]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[3] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (provalogBMP_09_22_B.ByteReversal[4] < 0.0F) {
    tmp = (real32_T)ceil(provalogBMP_09_22_B.ByteReversal[4]);
  } else {
    tmp = (real32_T)floor(provalogBMP_09_22_B.ByteReversal[4]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[4] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (provalogBMP_09_22_B.ByteReversal[5] < 0.0F) {
    tmp = (real32_T)ceil(provalogBMP_09_22_B.ByteReversal[5]);
  } else {
    tmp = (real32_T)floor(provalogBMP_09_22_B.ByteReversal[5]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[5] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant3'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   */
  if ((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[0] < 0.0F) {
    tmp = (real32_T)ceil((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[0]);
  } else {
    tmp = (real32_T)floor((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[0]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[6] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant3'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   */
  if ((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[1] < 0.0F) {
    tmp = (real32_T)ceil((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[1]);
  } else {
    tmp = (real32_T)floor((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[1]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[7] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant3'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   */
  if ((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[2] < 0.0F) {
    tmp = (real32_T)ceil((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[2]);
  } else {
    tmp = (real32_T)floor((real32_T)provalogBMP_09_22_P.Constant3_Value_d1[2]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_n2[8] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  provalogBMP_09_22_B.DataTypeConversion1[0] = provalogBMP_09_22_B.ByteReversal
    [1];
  provalogBMP_09_22_B.DataTypeConversion1[1] = provalogBMP_09_22_B.ByteReversal
    [0];
  provalogBMP_09_22_B.DataTypeConversion1[2] = provalogBMP_09_22_B.ByteReversal
    [2];
  provalogBMP_09_22_B.DataTypeConversion1[3] = provalogBMP_09_22_B.ByteReversal
    [3];
  provalogBMP_09_22_B.DataTypeConversion1[4] = provalogBMP_09_22_B.ByteReversal
    [4];
  provalogBMP_09_22_B.DataTypeConversion1[5] = provalogBMP_09_22_B.ByteReversal
    [5];

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/Constant'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain_Gain_j[0] *
    provalogBMP_09_22_P.Constant_Value_d;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_f[0] =
    provalogBMP_09_22_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint32_T)
    provalogBMP_09_22_B.RateTransition;

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain_Gain_j[1] *
    provalogBMP_09_22_P.Constant2_Value_i;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_f[1] =
    provalogBMP_09_22_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint32_T)
    provalogBMP_09_22_B.RateTransition;

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain_Gain_j[2] *
    provalogBMP_09_22_P.Constant1_Value_kl;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_f[2] =
    provalogBMP_09_22_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint32_T)
    provalogBMP_09_22_B.RateTransition;

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/alt_r'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain_Gain_j[3] *
    provalogBMP_09_22_P.alt_r_Value;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  provalogBMP_09_22_B.DataTypeConversion_f[3] =
    provalogBMP_09_22_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint32_T)
    provalogBMP_09_22_B.RateTransition;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain1_Gain *
    provalogBMP_09_22_P.Constant3_Value_k;

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  provalogBMP_09_22_B.DataTypeConversion1_k[0] = (int16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* Gain: '<S10>/Gain1' incorporates:
   *  Constant: '<S10>/vel y'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain1_Gain *
    provalogBMP_09_22_P.vely_Value;

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  provalogBMP_09_22_B.DataTypeConversion1_k[1] = (int16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* Gain: '<S10>/Gain1' incorporates:
   *  Constant: '<S10>/RC Simulated'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain1_Gain *
    provalogBMP_09_22_P.RCSimulated_Value;

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  provalogBMP_09_22_B.DataTypeConversion1_k[2] = (int16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* Gain: '<S10>/Gain2' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_P.Gain2_Gain_n *
    provalogBMP_09_22_P.Constant4_Value_b;

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  if (provalogBMP_09_22_B.RateTransition < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.RateTransition);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.RateTransition);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  provalogBMP_09_22_B.DataTypeConversion2 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* SignalConversion generated from: '<S35>/Enable' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !provalogBMP_09_22_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  pro_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &provalogBMP_09_22_B.One_time_initialization,
    &provalogBMP_09_22_DW.One_time_initialization,
    &provalogBMP_09_22_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S32>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (provalogBMP_09_22_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S32>/I2C Read12' */
    if (provalogBMP_09_22_DW.obj_m.SampleTime != provalogBMP_09_22_P.t_AP) {
      provalogBMP_09_22_DW.obj_m.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (provalogBMP_09_22_DW.obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter, 1U,
       true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(provalogBMP_09_22_DW.obj_m.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S32>/I2C Read1' */
    if (provalogBMP_09_22_DW.obj_k.SampleTime != provalogBMP_09_22_P.t_AP) {
      provalogBMP_09_22_DW.obj_k.SampleTime = provalogBMP_09_22_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (provalogBMP_09_22_DW.obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter, 1U,
       true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(provalogBMP_09_22_DW.obj_k.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw_0[0], 3U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw_0[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
      output[2] = 0U;
    }

    /* ArithShift: '<S32>/Shift Arithmetic4' incorporates:
     *  Constant: '<S32>/Constant1'
     */
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_P.Constant1_Value);
    if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
        (provalogBMP_09_22_B.RateTransition)) {
      provalogBMP_09_22_B.RateTransition = 0.0;
    } else {
      provalogBMP_09_22_B.RateTransition = fmod
        (provalogBMP_09_22_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S32>/Shift Arithmetic3' incorporates:
     *  Constant: '<S32>/Constant5'
     */
    provalogBMP_09_22_B.num_254 = floor(provalogBMP_09_22_P.Constant5_Value);
    if (rtIsNaN(provalogBMP_09_22_B.num_254) || rtIsInf
        (provalogBMP_09_22_B.num_254)) {
      provalogBMP_09_22_B.num_254 = 0.0;
    } else {
      provalogBMP_09_22_B.num_254 = fmod(provalogBMP_09_22_B.num_254,
        4.294967296E+9);
    }

    /* ArithShift: '<S32>/Shift Arithmetic1' incorporates:
     *  Constant: '<S32>/Constant6'
     */
    provalogBMP_09_22_B.deltafalllimit = floor
      (provalogBMP_09_22_P.Constant6_Value);
    if (rtIsNaN(provalogBMP_09_22_B.deltafalllimit) || rtIsInf
        (provalogBMP_09_22_B.deltafalllimit)) {
      provalogBMP_09_22_B.deltafalllimit = 0.0;
    } else {
      provalogBMP_09_22_B.deltafalllimit = fmod
        (provalogBMP_09_22_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S32>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S32>/Shift Arithmetic1'
     *  ArithShift: '<S32>/Shift Arithmetic3'
     *  ArithShift: '<S32>/Shift Arithmetic4'
     *  Constant: '<S32>/Constant10'
     *  Constant: '<S32>/Constant11'
     *  Constant: '<S32>/Constant7'
     *  MATLABSystem: '<S32>/I2C Read1'
     *  Sum: '<S32>/Sum1'
     *  Sum: '<S32>/Sum4'
     *  Sum: '<S32>/Sum5'
     *  Sum: '<S32>/Sum6'
     */
    provalogBMP_09_22_B.DataTypeConversion1_f = (int32_T)
      ((((((provalogBMP_09_22_P.Constant7_Value_f + output[0]) <<
           (provalogBMP_09_22_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
            -provalogBMP_09_22_B.RateTransition : (int32_T)(uint32_T)
            provalogBMP_09_22_B.RateTransition)) +
          ((provalogBMP_09_22_P.Constant10_Value_f + output[1]) <<
           (provalogBMP_09_22_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
            -provalogBMP_09_22_B.num_254 : (int32_T)(uint32_T)
            provalogBMP_09_22_B.num_254))) +
         provalogBMP_09_22_P.Constant11_Value) + output[2]) >>
       (provalogBMP_09_22_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -provalogBMP_09_22_B.deltafalllimit : (int32_T)(uint32_T)
        provalogBMP_09_22_B.deltafalllimit));

    /* ArithShift: '<S32>/Shift Arithmetic7' incorporates:
     *  Constant: '<S32>/Constant2'
     */
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_P.Constant2_Value);
    if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
        (provalogBMP_09_22_B.RateTransition)) {
      provalogBMP_09_22_B.RateTransition = 0.0;
    } else {
      provalogBMP_09_22_B.RateTransition = fmod
        (provalogBMP_09_22_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S32>/Shift Arithmetic6' incorporates:
     *  Constant: '<S32>/Constant3'
     */
    provalogBMP_09_22_B.num_254 = floor(provalogBMP_09_22_P.Constant3_Value);
    if (rtIsNaN(provalogBMP_09_22_B.num_254) || rtIsInf
        (provalogBMP_09_22_B.num_254)) {
      provalogBMP_09_22_B.num_254 = 0.0;
    } else {
      provalogBMP_09_22_B.num_254 = fmod(provalogBMP_09_22_B.num_254,
        4.294967296E+9);
    }

    /* ArithShift: '<S32>/Shift Arithmetic2' incorporates:
     *  Constant: '<S32>/Constant4'
     */
    provalogBMP_09_22_B.deltafalllimit = floor
      (provalogBMP_09_22_P.Constant4_Value);
    if (rtIsNaN(provalogBMP_09_22_B.deltafalllimit) || rtIsInf
        (provalogBMP_09_22_B.deltafalllimit)) {
      provalogBMP_09_22_B.deltafalllimit = 0.0;
    } else {
      provalogBMP_09_22_B.deltafalllimit = fmod
        (provalogBMP_09_22_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S32>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S32>/Shift Arithmetic2'
     *  ArithShift: '<S32>/Shift Arithmetic6'
     *  ArithShift: '<S32>/Shift Arithmetic7'
     *  Constant: '<S32>/Constant8'
     *  Constant: '<S32>/Constant9'
     *  MATLABSystem: '<S32>/I2C Read12'
     *  Sum: '<S32>/Sum'
     *  Sum: '<S32>/Sum2'
     *  Sum: '<S32>/Sum3'
     */
    provalogBMP_09_22_B.DataTypeConversion_d = (int32_T)
      ((((provalogBMP_09_22_P.Constant8_Value_e + rtb_H_mav[0]) <<
         (provalogBMP_09_22_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -provalogBMP_09_22_B.RateTransition : (int32_T)(uint32_T)
          provalogBMP_09_22_B.RateTransition)) +
        ((provalogBMP_09_22_P.Constant9_Value_l + rtb_H_mav[1]) <<
         (provalogBMP_09_22_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
          -provalogBMP_09_22_B.num_254 : (int32_T)(uint32_T)
          provalogBMP_09_22_B.num_254))) >> (provalogBMP_09_22_B.deltafalllimit <
        0.0 ? -(int32_T)(uint32_T)-provalogBMP_09_22_B.deltafalllimit : (int32_T)
        (uint32_T)provalogBMP_09_22_B.deltafalllimit));

    /* S-Function (calc_T): '<S32>/S-Function Builder' */
    calc_T_Outputs_wrapper(&provalogBMP_09_22_B.One_time_initialization.I2CRead,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead1,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead2,
      &provalogBMP_09_22_B.DataTypeConversion_d,
      &provalogBMP_09_22_B.SFunctionBuilder_o1,
      &provalogBMP_09_22_B.SFunctionBuilder_o2_f);

    /* S-Function (calc_p): '<S32>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&provalogBMP_09_22_B.One_time_initialization.I2CRead3,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead4,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead5,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead6,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead7,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead8,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead9,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead10,
      &provalogBMP_09_22_B.One_time_initialization.I2CRead11,
      &provalogBMP_09_22_B.DataTypeConversion1_f,
      &provalogBMP_09_22_B.SFunctionBuilder_o2_f,
      &provalogBMP_09_22_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (provalogBMP_09_22_P.Constant2_Value_c == 1.0) {
    provalogBMP_09_22_DW.P_ref = provalogBMP_09_22_B.SFunctionBuilder1;
  }

  if (provalogBMP_09_22_P.Constant_Value_o == 1.0) {
    provalogBMP_09_22_DW.P_ref = provalogBMP_09_22_P.Constant1_Value_kk;
    provalogBMP_09_22_DW.rl_up = 20.0;
    provalogBMP_09_22_DW.rl_dw = -20.0;
  }

  /* Product: '<S31>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S31>/sample time'
   *
   * About '<S31>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provalogBMP_09_22_B.RateTransition = provalogBMP_09_22_DW.rl_up *
    provalogBMP_09_22_P.sampletime_WtEt;

  /* Sum: '<S31>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S31>/Delay Input2'
   *
   * Block description for '<S31>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S31>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provalogBMP_09_22_B.num_254 = provalogBMP_09_22_DW.P_ref -
    provalogBMP_09_22_DW.DelayInput2_DSTATE;

  /* Product: '<S31>/delta fall limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S31>/sample time'
   *
   * About '<S31>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provalogBMP_09_22_B.deltafalllimit = provalogBMP_09_22_DW.rl_dw *
    provalogBMP_09_22_P.sampletime_WtEt;

  /* Switch: '<S37>/Switch2' incorporates:
   *  RelationalOperator: '<S37>/LowerRelop1'
   *  RelationalOperator: '<S37>/UpperRelop'
   *  Switch: '<S37>/Switch'
   */
  if (provalogBMP_09_22_B.num_254 > provalogBMP_09_22_B.RateTransition) {
    provalogBMP_09_22_B.num_254 = provalogBMP_09_22_B.RateTransition;
  } else {
    if (provalogBMP_09_22_B.num_254 < provalogBMP_09_22_B.deltafalllimit) {
      /* Switch: '<S37>/Switch' */
      provalogBMP_09_22_B.num_254 = provalogBMP_09_22_B.deltafalllimit;
    }
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Sum: '<S31>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S31>/Delay Input2'
   *
   * Block description for '<S31>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S31>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provalogBMP_09_22_DW.DelayInput2_DSTATE += provalogBMP_09_22_B.num_254;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S31>/Delay Input2'
   *
   * Block description for '<S31>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provalogBMP_09_22_B.DataTypeConversion3_e = (real32_T)
    provalogBMP_09_22_DW.DelayInput2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S36>/Subsystem1' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (provalogBMP_09_22_P.Constant2_Value_c > 0.0) {
    /* Inport: '<S38>/T' */
    provalogBMP_09_22_B.T = provalogBMP_09_22_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S36>/Subsystem1' */

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  provalogBMP_09_22_B.h_ = (real32_T)log((real32_T)
    provalogBMP_09_22_B.SFunctionBuilder1 /
    provalogBMP_09_22_B.DataTypeConversion3_e) * -8333.33301F;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' incorporates:
   *  Constant: '<S19>/RC simulated'
   *  Constant: '<S19>/TAS simulated'
   *  Constant: '<S19>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  provalogBMP_09_22_B.DataTypeConversion3_ei[0] = (real32_T)
    provalogBMP_09_22_P.TASsimulated_Value;
  provalogBMP_09_22_B.DataTypeConversion3_ei[1] = (real32_T)
    provalogBMP_09_22_P.vsimulated_Value;
  provalogBMP_09_22_B.DataTypeConversion3_ei[2] = provalogBMP_09_22_B.h_;
  provalogBMP_09_22_B.DataTypeConversion3_ei[3] = (real32_T)
    provalogBMP_09_22_P.RCsimulated_Value;

  /* DataTypeConversion: '<S19>/Data Type Conversion4' incorporates:
   *  Constant: '<S19>/ Heading simulated'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Headingsimulated_Value);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion4' */
  provalogBMP_09_22_B.DataTypeConversion4_g = (int16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S19>/Data Type Conversion5' incorporates:
   *  Constant: '<S19>/Rpm simulated'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Rpmsimulated_Value);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion5' */
  provalogBMP_09_22_B.DataTypeConversion5 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* Gain: '<S26>/Gain2' incorporates:
   *  Constant: '<S17>/Manetta Simulated'
   */
  provalogBMP_09_22_B.num_254 = provalogBMP_09_22_P.Gain2_Gain_p *
    provalogBMP_09_22_P.ManettaSimulated_Value;

  /* Sum: '<S26>/Sum' incorporates:
   *  Constant: '<S17>/Equilibratore Simulated'
   *  Constant: '<S26>/Constant2'
   *  Gain: '<S27>/Gain'
   */
  provalogBMP_09_22_B.deltafalllimit = provalogBMP_09_22_P.Gain_Gain_c *
    provalogBMP_09_22_P.EquilibratoreSimulated_Value +
    provalogBMP_09_22_P.Constant2_Value_lk;

  /* Sum: '<S26>/Sum1' incorporates:
   *  Constant: '<S17>/Alettoni Simulated'
   *  Constant: '<S26>/Constant2'
   *  Gain: '<S28>/Gain'
   */
  provalogBMP_09_22_B.Sum1 = provalogBMP_09_22_P.Gain_Gain_b *
    provalogBMP_09_22_P.AlettoniSimulated_Value +
    provalogBMP_09_22_P.Constant2_Value_lk;

  /* Sum: '<S26>/Sum2' incorporates:
   *  Constant: '<S17>/Timone Simulated'
   *  Constant: '<S26>/Constant2'
   *  Gain: '<S29>/Gain'
   */
  provalogBMP_09_22_B.Sum2 = provalogBMP_09_22_P.Gain_Gain_bt *
    provalogBMP_09_22_P.TimoneSimulated_Value +
    provalogBMP_09_22_P.Constant2_Value_lk;

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  provalogBMP_09_22_B.Gain3 = provalogBMP_09_22_P.Gain_Gain_a *
    provalogBMP_09_22_P.Constant2_Value_n;

  /* Saturate: '<S17>/Saturation' */
  if (provalogBMP_09_22_B.Gain3 > provalogBMP_09_22_P.Saturation_UpperSat) {
    provalogBMP_09_22_B.Gain3 = provalogBMP_09_22_P.Saturation_UpperSat;
  } else {
    if (provalogBMP_09_22_B.Gain3 < provalogBMP_09_22_P.Saturation_LowerSat) {
      provalogBMP_09_22_B.Gain3 = provalogBMP_09_22_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Constant: '<S17>/Constant'
   */
  if (provalogBMP_09_22_P.Constant_Value_n < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil
      (provalogBMP_09_22_P.Constant_Value_n);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_P.Constant_Value_n);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[0] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.num_254 < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.num_254);
  } else {
    provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_B.num_254);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[1] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.deltafalllimit < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.deltafalllimit);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_B.deltafalllimit);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[2] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.Sum1 < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.Sum1);
  } else {
    provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_B.Sum1);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[3] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.Sum2 < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.Sum2);
  } else {
    provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_B.Sum2);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[4] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  if (provalogBMP_09_22_P.Constant1_Value_o3[0] < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil
      (provalogBMP_09_22_P.Constant1_Value_o3[0]);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_P.Constant1_Value_o3[0]);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[5] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  if (provalogBMP_09_22_P.Constant1_Value_o3[1] < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil
      (provalogBMP_09_22_P.Constant1_Value_o3[1]);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_P.Constant1_Value_o3[1]);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[6] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  if (provalogBMP_09_22_P.Constant1_Value_o3[2] < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil
      (provalogBMP_09_22_P.Constant1_Value_o3[2]);
  } else {
    provalogBMP_09_22_B.RateTransition = floor
      (provalogBMP_09_22_P.Constant1_Value_o3[2]);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[7] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  if (provalogBMP_09_22_B.Gain3 < 0.0) {
    provalogBMP_09_22_B.RateTransition = ceil(provalogBMP_09_22_B.Gain3);
  } else {
    provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_B.Gain3);
  }

  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  provalogBMP_09_22_B.Heading[8] = (uint16_T)(provalogBMP_09_22_B.RateTransition
    < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
    provalogBMP_09_22_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  provalogBMP_09_22_B.Memory_i = provalogBMP_09_22_DW.Memory_PreviousInput_n;

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S36>/NotEqual'
   *  Switch: '<S36>/Switch'
   */
  if (provalogBMP_09_22_P.Constant_Value_ot != provalogBMP_09_22_P.T_0_Value) {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    provalogBMP_09_22_B.DataTypeConversion4 = (real32_T)
      provalogBMP_09_22_P.T_0_Value;
  } else if (provalogBMP_09_22_B.T > provalogBMP_09_22_P.Switch_Threshold_l) {
    /* Switch: '<S36>/Switch' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion4'
     */
    provalogBMP_09_22_B.DataTypeConversion4 = provalogBMP_09_22_B.T;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    provalogBMP_09_22_B.DataTypeConversion4 = (real32_T)
      provalogBMP_09_22_P.T_0_Value;
  }

  /* End of Switch: '<S36>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  provalogBMP_09_22_B.DataTypeConversion_n = (real32_T)
    (provalogBMP_09_22_P.PatohPa_Gain * (real_T)
     provalogBMP_09_22_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  provalogBMP_09_22_B.DataTypeConversion1_o = (real32_T)
    (provalogBMP_09_22_P.PatohPa1_Gain * provalogBMP_09_22_P.Constant2_Value_lc);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  tmp = (real32_T)floor(provalogBMP_09_22_B.SFunctionBuilder_o1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  provalogBMP_09_22_B.DataTypeConversion2_e = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&provalogBMP_09_22_B.iflogic,
    &provalogBMP_09_22_B.DataTypeConversion3,
    &provalogBMP_09_22_P.SIUAVuint8_Value, &provalogBMP_09_22_B.GC_info[0],
    &provalogBMP_09_22_B.Val_out_MAV[0], &provalogBMP_09_22_B.WP_info[0],
    &provalogBMP_09_22_B.WP_param[0], &provalogBMP_09_22_B.onboard[0],
    &provalogBMP_09_22_B.LVDE[0], &provalogBMP_09_22_B.B_Current,
    &provalogBMP_09_22_B.B_Remaining, &provalogBMP_09_22_B.DataTypeConversion,
    &provalogBMP_09_22_B.DataTypeConversion1_c[0],
    &provalogBMP_09_22_B.DataTypeConversion_n2[0],
    &provalogBMP_09_22_B.DataTypeConversion1[0],
    &provalogBMP_09_22_B.DataTypeConversion_f[0],
    &provalogBMP_09_22_B.DataTypeConversion1_k[0],
    &provalogBMP_09_22_B.DataTypeConversion2,
    &provalogBMP_09_22_B.DataTypeConversion3_ei[0],
    &provalogBMP_09_22_B.DataTypeConversion4_g,
    &provalogBMP_09_22_B.DataTypeConversion5, &provalogBMP_09_22_B.Heading[0],
    &provalogBMP_09_22_B.Memory_i, &provalogBMP_09_22_B.DataTypeConversion3_e,
    &provalogBMP_09_22_B.SFunction_o14, &provalogBMP_09_22_B.DataTypeConversion4,
    &provalogBMP_09_22_B.SFunction_o15,
    &provalogBMP_09_22_B.DataTypeConversion_n,
    &provalogBMP_09_22_B.DataTypeConversion1_o,
    &provalogBMP_09_22_B.DataTypeConversion2_e,
    &provalogBMP_09_22_B.SFunction_o5[0],
    &provalogBMP_09_22_P.Constant4_Value_bw,
    &provalogBMP_09_22_P.Constant5_Value_h,
    &provalogBMP_09_22_P.Constant10_Value, ((const uint16_T*)
    &provalogBMP_09_22_U16GND), &provalogBMP_09_22_B.SFunction_o1_h,
    &provalogBMP_09_22_B.SFunction_o2_n[0], &provalogBMP_09_22_B.SFunction_o3,
    &provalogBMP_09_22_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (provalogBMP_09_22_B.SFunction_o1_h > 0) {
    /* Chart: '<S9>/Chart' */
    if (provalogBMP_09_22_DW.is_active_c9_provalogBMP_09_22 == 0U) {
      provalogBMP_09_22_DW.is_active_c9_provalogBMP_09_22 = 1U;
      provalogBMP_09_22_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (provalogBMP_09_22_DW.obj_n.Protocol !=
            provalogBMP_09_22_P.SerialTransmit_Protocol) {
          provalogBMP_09_22_DW.obj_n.Protocol =
            provalogBMP_09_22_P.SerialTransmit_Protocol;
        }

        counter = provalogBMP_09_22_B.SFunction_o2_n[provalogBMP_09_22_DW.i - 1];
        MW_Serial_write(provalogBMP_09_22_DW.obj_n.port, &counter, 1.0,
                        provalogBMP_09_22_DW.obj_n.dataSizeInBytes,
                        provalogBMP_09_22_DW.obj_n.sendModeEnum,
                        provalogBMP_09_22_DW.obj_n.dataType,
                        provalogBMP_09_22_DW.obj_n.sendFormatEnum, 2.0, '\x00');
        if (provalogBMP_09_22_DW.i < provalogBMP_09_22_B.SFunction_o3) {
          provalogBMP_09_22_B.f = provalogBMP_09_22_DW.i + 1;
          if (provalogBMP_09_22_DW.i + 1 > 255) {
            provalogBMP_09_22_B.f = 255;
          }

          provalogBMP_09_22_DW.i = (uint8_T)provalogBMP_09_22_B.f;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      provalogBMP_09_22_DW.i = 1U;
    }

    /* End of Chart: '<S9>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  provalogBMP_09_22_B.DataTypeConversion6[0] = (real32_T)
    provalogBMP_09_22_P.Constant_Value_d;
  provalogBMP_09_22_B.DataTypeConversion6[1] = (real32_T)
    provalogBMP_09_22_P.Constant2_Value_i;
  provalogBMP_09_22_B.DataTypeConversion6[2] = (real32_T)
    provalogBMP_09_22_P.Constant1_Value_kl;
  provalogBMP_09_22_B.DataTypeConversion6[3] = provalogBMP_09_22_B.h_;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_nw *
                        provalogBMP_09_22_B.ByteReversal[0]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[0] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_nw *
                        provalogBMP_09_22_B.ByteReversal[1]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[1] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_nw *
                        provalogBMP_09_22_B.ByteReversal[2]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[2] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S14>/Gain'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_g *
                        provalogBMP_09_22_B.ByteReversal[3] *
                        provalogBMP_09_22_P.Gain_Gain_nw);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[3] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_o *
                        provalogBMP_09_22_B.ByteReversal[4] *
                        provalogBMP_09_22_P.Gain_Gain_nw);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[4] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S16>/Gain'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_h *
                        provalogBMP_09_22_B.ByteReversal[5] *
                        provalogBMP_09_22_P.Gain_Gain_nw);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[5] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_nw *
                        provalogBMP_09_22_B.ByteReversal[6]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[6] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_nw *
                        provalogBMP_09_22_B.ByteReversal[7]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[7] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(provalogBMP_09_22_P.Gain_Gain_nw *
                        provalogBMP_09_22_B.ByteReversal[8]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provalogBMP_09_22_B.DataTypeConversion3_h[8] = (int16_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion10' */
  provalogBMP_09_22_B.DataTypeConversion10 =
    provalogBMP_09_22_B.DataTypeConversion2;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  provalogBMP_09_22_B.DataTypeConversion11[0] = (uint16_T)
    ((provalogBMP_09_22_P.Gain2_Gain_e *
      provalogBMP_09_22_B.DataTypeConversion1_k[0]) >> 8);
  provalogBMP_09_22_B.DataTypeConversion11[1] = (uint16_T)
    ((provalogBMP_09_22_P.Gain2_Gain_e *
      provalogBMP_09_22_B.DataTypeConversion1_k[1]) >> 8);
  provalogBMP_09_22_B.DataTypeConversion11[2] = (uint16_T)
    ((provalogBMP_09_22_P.Gain2_Gain_e *
      provalogBMP_09_22_B.DataTypeConversion1_k[2]) >> 8);

  /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
   *  Constant: '<S2>/Constant'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant_Value_gd);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  provalogBMP_09_22_B.DataTypeConversion12 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion13' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant3_Value_m);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  provalogBMP_09_22_B.DataTypeConversion13 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_P.Constant7_Value);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  provalogBMP_09_22_B.DataTypeConversion14 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_P.Constant8_Value);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  provalogBMP_09_22_B.DataTypeConversion15 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion21' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  provalogBMP_09_22_B.RateTransition = floor(provalogBMP_09_22_P.Constant9_Value);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion21' */
  provalogBMP_09_22_B.DataTypeConversion21 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion20' incorporates:
   *  Constant: '<S2>/Constant6'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant6_Value_d);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  provalogBMP_09_22_B.DataTypeConversion20 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion19' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant1_Value_j);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  provalogBMP_09_22_B.DataTypeConversion19 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion18' incorporates:
   *  Gain: '<S2>/Gain3'
   */
  provalogBMP_09_22_B.RateTransition = floor((real_T)
    provalogBMP_09_22_P.Gain3_Gain * provalogBMP_09_22_B.SFunctionBuilder_o1);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  provalogBMP_09_22_B.DataTypeConversion18 = (uint16_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint16_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant4_Value_j);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  provalogBMP_09_22_B.DataTypeConversion8[0] = (uint8_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint8_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  provalogBMP_09_22_B.RateTransition = floor
    (provalogBMP_09_22_P.Constant3_Value_g);
  if (rtIsNaN(provalogBMP_09_22_B.RateTransition) || rtIsInf
      (provalogBMP_09_22_B.RateTransition)) {
    provalogBMP_09_22_B.RateTransition = 0.0;
  } else {
    provalogBMP_09_22_B.RateTransition = fmod(provalogBMP_09_22_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  provalogBMP_09_22_B.DataTypeConversion8[1] = (uint8_T)
    (provalogBMP_09_22_B.RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provalogBMP_09_22_B.RateTransition : (int32_T)(uint8_T)
     provalogBMP_09_22_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  tmp = (real32_T)floor(provalogBMP_09_22_B.DataTypeConversion_n);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  provalogBMP_09_22_B.DataTypeConversion9 = tmp < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-tmp : (uint32_T)tmp;

  /* S-Function (any2byte_svd): '<S2>/Byte Pack' incorporates:
   *  Constant: '<S2>/Fine MSG1'
   *  Constant: '<S2>/Inizio MSG'
   */

  /* Pack: <S2>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_P.InizioMSG_Value[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 2 */
    /* Input data type - real32_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion6[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 3 */
    /* Input data type - int16_T, size - 9 */
    {
      MW_inputPortWidth = 9 * sizeof(int16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion3_h[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 4 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion10, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 5 */
    /* Input data type - uint16_T, size - 3 */
    {
      MW_inputPortWidth = 3 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion11[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 6 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion12, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 7 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion13, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 8 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion14, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 9 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion15, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 10 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion21, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 11 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion20, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 12 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion19, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 13 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion18, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 14 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion8[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 15 */
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_B.DataTypeConversion9, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 16 */
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&provalogBMP_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provalogBMP_09_22_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S2>/Serial Transmit1' */
  if (provalogBMP_09_22_DW.obj.Protocol !=
      provalogBMP_09_22_P.SerialTransmit1_Protocol) {
    provalogBMP_09_22_DW.obj.Protocol =
      provalogBMP_09_22_P.SerialTransmit1_Protocol;
  }

  memcpy(&provalogBMP_09_22_B.dataIn[0], &provalogBMP_09_22_B.BytePack[0], 67U *
         sizeof(uint8_T));
  MW_Serial_write(provalogBMP_09_22_DW.obj.port, &provalogBMP_09_22_B.dataIn[0],
                  67.0, provalogBMP_09_22_DW.obj.dataSizeInBytes,
                  provalogBMP_09_22_DW.obj.sendModeEnum,
                  provalogBMP_09_22_DW.obj.dataType,
                  provalogBMP_09_22_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S2>/Serial Transmit1' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&provalogBMP_09_22_DW.Memory4_PreviousInput[0],
         &provalogBMP_09_22_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S4>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S4>/S-Function Builder */
  Mti_Update_wrapper(&provalogBMP_09_22_B.SFunctionBuilder[0],
                     &provalogBMP_09_22_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&provalogBMP_09_22_P.Constant1_Value_i,
    &provalogBMP_09_22_B.SFunctionBuilder_o1_g[0],
    &provalogBMP_09_22_B.SFunctionBuilder_o2,
    &provalogBMP_09_22_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&provalogBMP_09_22_DW.Memory5_PreviousInput[0],
         &provalogBMP_09_22_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  provalogBMP_09_22_DW.Memory_PreviousInput_i[0] =
    provalogBMP_09_22_B.DataTypeConversion1_c[0];
  provalogBMP_09_22_DW.Memory_PreviousInput_i[1] =
    provalogBMP_09_22_B.DataTypeConversion1_c[1];
  provalogBMP_09_22_DW.Memory_PreviousInput_i[2] =
    provalogBMP_09_22_B.DataTypeConversion1_c[2];
  provalogBMP_09_22_DW.Memory_PreviousInput_i[3] =
    provalogBMP_09_22_B.DataTypeConversion1_c[3];

  /* Update for Memory: '<S1>/Memory' */
  for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 8;
       provalogBMP_09_22_B.caso++) {
    provalogBMP_09_22_DW.Memory_PreviousInput_c[provalogBMP_09_22_B.caso] =
      provalogBMP_09_22_B.SFunction_o11[provalogBMP_09_22_B.caso];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provalogBMP_09_22_DW.Memory2_PreviousInput_i[0] = (uint8_T)AP_mode_idx_0;
  provalogBMP_09_22_DW.Memory2_PreviousInput_i[1] = (uint8_T)AP_mode_idx_1;
  for (provalogBMP_09_22_B.caso = 0; provalogBMP_09_22_B.caso < 7;
       provalogBMP_09_22_B.caso++) {
    tmp = rt_roundf_snf
      (provalogBMP_09_22_DW.riferimenti[provalogBMP_09_22_B.caso]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        provalogBMP_09_22_DW.Memory2_PreviousInput_i[provalogBMP_09_22_B.caso +
          2] = (uint8_T)tmp;
      } else {
        provalogBMP_09_22_DW.Memory2_PreviousInput_i[provalogBMP_09_22_B.caso +
          2] = 0U;
      }
    } else {
      provalogBMP_09_22_DW.Memory2_PreviousInput_i[provalogBMP_09_22_B.caso + 2]
        = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  provalogBMP_09_22_DW.UnitDelay_DSTATE = provalogBMP_09_22_P.Constant3_Value_l;

  /* Update for Memory: '<S2>/Memory' */
  provalogBMP_09_22_DW.Memory_PreviousInput_n = provalogBMP_09_22_B.SFunction_o4;
}

/* Model step function for TID1 */
void provalogBMP_09_22_step1(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S24>/Add2' incorporates:
   *  Constant: '<S24>/Constant4'
   *  Constant: '<S24>/Constant5'
   *  Memory: '<S24>/Memory2'
   */
  provalogBMP_09_22_DW.Memory2_PreviousInput +=
    provalogBMP_09_22_P.Constant4_Value_m +
    provalogBMP_09_22_P.Constant5_Value_d;

  /* Switch: '<S24>/Switch1' */
  if (provalogBMP_09_22_DW.Memory2_PreviousInput >
      provalogBMP_09_22_P.Switch1_Threshold) {
    /* Sum: '<S24>/Add2' incorporates:
     *  Constant: '<S24>/Constant4'
     */
    provalogBMP_09_22_DW.Memory2_PreviousInput =
      provalogBMP_09_22_P.Constant4_Value_m;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* RateTransition: '<S24>/Rate Transition' */
  provalogBMP_09_22_DW.RateTransition_Buffer0 =
    provalogBMP_09_22_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void provalogBMP_09_22_initialize(void)
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

    /* Start for S-Function (Mti): '<S4>/S-Function Builder' */

    /* S-Function Block: <S4>/S-Function Builder */
    Mti_Start_wrapper(&provalogBMP_09_22_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&provalogBMP_09_22_DW.Memory4_PreviousInput[0],
           &provalogBMP_09_22_P.Memory4_InitialCondition[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S4>/S-Function Builder' */

    /* S-Function Block: <S4>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provalogBMP_09_22_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provalogBMP_09_22_DW.SFunctionBuilder_DSTATE_n = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      provalogBMP_09_22_DW.Memory5_PreviousInput[i] =
        provalogBMP_09_22_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[0] =
      provalogBMP_09_22_P.Memory1_InitialCondition_j;
    provalogBMP_09_22_DW.Memory1_PreviousInput_c[1] =
      provalogBMP_09_22_P.Memory1_InitialCondition_j;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    provalogBMP_09_22_DW.Memory_PreviousInput_i[0] =
      provalogBMP_09_22_P.Memory_InitialCondition_n;
    provalogBMP_09_22_DW.Memory_PreviousInput_i[1] =
      provalogBMP_09_22_P.Memory_InitialCondition_n;
    provalogBMP_09_22_DW.Memory_PreviousInput_i[2] =
      provalogBMP_09_22_P.Memory_InitialCondition_n;
    provalogBMP_09_22_DW.Memory_PreviousInput_i[3] =
      provalogBMP_09_22_P.Memory_InitialCondition_n;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    provalogBMP_09_22_DW.Memory3_PreviousInput =
      provalogBMP_09_22_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      provalogBMP_09_22_DW.Memory_PreviousInput_c[i] =
        provalogBMP_09_22_P.Memory_InitialCondition_l;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      provalogBMP_09_22_DW.Memory2_PreviousInput_i[i] =
        provalogBMP_09_22_P.Memory2_InitialCondition_j[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S24>/Rate Transition' */
    provalogBMP_09_22_DW.RateTransition_Buffer0 =
      provalogBMP_09_22_P.RateTransition_InitialCondition;

    /* InitializeConditions for DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
     *  Memory: '<S24>/Memory1'
     */
    provalogBMP_09_22_DW.Memory1_PreviousInput =
      provalogBMP_09_22_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S24>/Add' incorporates:
     *  Memory: '<S24>/Memory'
     */
    provalogBMP_09_22_DW.Memory_PreviousInput =
      provalogBMP_09_22_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    provalogBMP_09_22_DW.UnitDelay_DSTATE =
      provalogBMP_09_22_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S31>/Delay Input2'
     *
     * Block description for '<S31>/Delay Input2':
     *
     *  Store in Global RAM
     */
    provalogBMP_09_22_DW.DelayInput2_DSTATE =
      provalogBMP_09_22_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    provalogBMP_09_22_DW.Memory_PreviousInput_n =
      provalogBMP_09_22_P.Memory_InitialCondition_c;

    /* InitializeConditions for Sum: '<S24>/Add2' incorporates:
     *  Memory: '<S24>/Memory2'
     */
    provalogBMP_09_22_DW.Memory2_PreviousInput =
      provalogBMP_09_22_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&provalogBMP_09_22_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S9>/Chart' incorporates:
     *  SubSystem: '<S21>/sendbyte'
     */
    /* Start for MATLABSystem: '<S22>/Serial Transmit' */
    provalogBMP_09_22_DW.obj_n.matlabCodegenIsDeleted = false;
    provalogBMP_09_22_DW.obj_n.Protocol =
      provalogBMP_09_22_P.SerialTransmit_Protocol;
    provalogBMP_09_22_DW.obj_n.isInitialized = 1;
    provalogBMP_09_22_DW.obj_n.port = 2.0;
    provalogBMP_09_22_DW.obj_n.dataSizeInBytes = 1.0;
    provalogBMP_09_22_DW.obj_n.dataType = 0.0;
    provalogBMP_09_22_DW.obj_n.sendModeEnum = 0.0;
    provalogBMP_09_22_DW.obj_n.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(provalogBMP_09_22_DW.obj_n.port);
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
    provalogBMP_09_22_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S22>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S32>/I2C Read12' */
    provalogBMP_09_22_DW.obj_m.matlabCodegenIsDeleted = true;
    obj = &provalogBMP_09_22_DW.obj_m;
    provalogBMP_09_22_DW.obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
    provalogBMP_09_22_DW.obj_m.isInitialized = 0;
    provalogBMP_09_22_DW.obj_m.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provalogBMP_09_22_DW.obj_m.matlabCodegenIsDeleted = false;
    provalogBMP_09_22_DW.obj_m.SampleTime = provalogBMP_09_22_P.t_AP;
    obj = &provalogBMP_09_22_DW.obj_m;
    provalogBMP_09_22_DW.obj_m.isSetupComplete = false;
    provalogBMP_09_22_DW.obj_m.isInitialized = 1;
    provalogBMP_09_22_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provalogBMP_09_22_B.i2cname, 0);
    provalogBMP_09_22_DW.obj_m.BusSpeed = 100000U;
    varargin_1 = provalogBMP_09_22_DW.obj_m.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provalogBMP_09_22_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S32>/I2C Read1' */
    provalogBMP_09_22_DW.obj_k.matlabCodegenIsDeleted = true;
    obj = &provalogBMP_09_22_DW.obj_k;
    provalogBMP_09_22_DW.obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
    provalogBMP_09_22_DW.obj_k.isInitialized = 0;
    provalogBMP_09_22_DW.obj_k.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provalogBMP_09_22_DW.obj_k.matlabCodegenIsDeleted = false;
    provalogBMP_09_22_DW.obj_k.SampleTime = provalogBMP_09_22_P.t_AP;
    obj = &provalogBMP_09_22_DW.obj_k;
    provalogBMP_09_22_DW.obj_k.isSetupComplete = false;
    provalogBMP_09_22_DW.obj_k.isInitialized = 1;
    provalogBMP_09_22_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provalogBMP_09_22_B.i2cname, 0);
    provalogBMP_09_22_DW.obj_k.BusSpeed = 100000U;
    varargin_1 = provalogBMP_09_22_DW.obj_k.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provalogBMP_09_22_DW.obj_k.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S32>/S-Function Builder' incorporates:
     *  Outport: '<S32>/T'
     */
    provalogBMP_09_22_B.SFunctionBuilder_o1 = provalogBMP_09_22_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S32>/S-Function Builder1' incorporates:
     *  Outport: '<S32>/p'
     */
    provalogBMP_09_22_B.SFunctionBuilder1 = provalogBMP_09_22_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    provalogBMP_09_22_DW.P_ref = 101325.0;
    provalogBMP_09_22_DW.rl_up = 300.0;
    provalogBMP_09_22_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init(&provalogBMP_09_22_B.One_time_initialization,
      &provalogBMP_09_22_DW.One_time_initialization,
      &provalogBMP_09_22_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S36>/Subsystem1' */
    /* SystemInitialize for Outport: '<S38>/T_0' incorporates:
     *  Inport: '<S38>/T'
     */
    provalogBMP_09_22_B.T = provalogBMP_09_22_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S36>/Subsystem1' */

    /* Start for MATLABSystem: '<S2>/Serial Transmit1' */
    provalogBMP_09_22_DW.obj.matlabCodegenIsDeleted = false;
    provalogBMP_09_22_DW.obj.Protocol =
      provalogBMP_09_22_P.SerialTransmit1_Protocol;
    provalogBMP_09_22_DW.obj.isInitialized = 1;
    provalogBMP_09_22_DW.obj.port = 0.0;
    provalogBMP_09_22_DW.obj.dataSizeInBytes = 1.0;
    provalogBMP_09_22_DW.obj.dataType = 0.0;
    provalogBMP_09_22_DW.obj.sendModeEnum = 0.0;
    provalogBMP_09_22_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(provalogBMP_09_22_DW.obj.port);
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
    provalogBMP_09_22_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit1' */
  }
}

/* Model terminate function */
void provalogBMP_09_22_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term(&provalogBMP_09_22_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S32>/I2C Read12' */
  obj = &provalogBMP_09_22_DW.obj_m;
  if (!provalogBMP_09_22_DW.obj_m.matlabCodegenIsDeleted) {
    provalogBMP_09_22_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((provalogBMP_09_22_DW.obj_m.isInitialized == 1) &&
        provalogBMP_09_22_DW.obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S32>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S32>/I2C Read1' */
  obj = &provalogBMP_09_22_DW.obj_k;
  if (!provalogBMP_09_22_DW.obj_k.matlabCodegenIsDeleted) {
    provalogBMP_09_22_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((provalogBMP_09_22_DW.obj_k.isInitialized == 1) &&
        provalogBMP_09_22_DW.obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S32>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S9>/Chart' incorporates:
   *  SubSystem: '<S21>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S22>/Serial Transmit' */
  if (!provalogBMP_09_22_DW.obj_n.matlabCodegenIsDeleted) {
    provalogBMP_09_22_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S22>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
  if (!provalogBMP_09_22_DW.obj.matlabCodegenIsDeleted) {
    provalogBMP_09_22_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
