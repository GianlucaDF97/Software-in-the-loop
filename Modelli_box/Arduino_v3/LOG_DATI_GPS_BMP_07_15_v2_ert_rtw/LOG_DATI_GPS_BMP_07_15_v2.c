/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LOG_DATI_GPS_BMP_07_15_v2.c
 *
 * Code generated for Simulink model 'LOG_DATI_GPS_BMP_07_15_v2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 18:15:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LOG_DATI_GPS_BMP_07_15_v2.h"
#include "LOG_DATI_GPS_BMP_07_15_v2_private.h"

const uint16_T LOG_DATI_GPS_BMP_07_15_v2_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_LOG_DATI_GPS_BMP_07_15_v2_T LOG_DATI_GPS_BMP_07_15_v2_B;

/* Block states (default storage) */
DW_LOG_DATI_GPS_BMP_07_15_v2_T LOG_DATI_GPS_BMP_07_15_v2_DW;

/* Real-time model */
static RT_MODEL_LOG_DATI_GPS_BMP_07__T LOG_DATI_GPS_BMP_07_15_v2_M_;
RT_MODEL_LOG_DATI_GPS_BMP_07__T *const LOG_DATI_GPS_BMP_07_15_v2_M =
  &LOG_DATI_GPS_BMP_07_15_v2_M_;

/* Forward declaration for local functions */
static void LOG_DATI_GPS_BMP_07_15_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T LOG_DATI_GPS_BMP_07_ifWhileCond(const boolean_T x[100]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void LOG_DATI_GPS_BMP_07_15_v2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(LOG_DATI_GPS_BMP_07_15_v2_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(LOG_DATI_GPS_BMP_07_15_v2_M, 2));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 2 */
  LOG_DATI_GPS_BMP_07_15_v2_M->Timing.RateInteraction.TID0_2 =
    (LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[1])++;
  if ((LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[1] = 0;
  }

  (LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[2])++;
  if ((LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [1.0s, 0.0s] */
    LOG_DATI_GPS_BMP_07_15_v2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_LOG_T *localB,
  DW_One_time_initialization_LO_T *localDW, P_One_time_initialization_LOG_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_p_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S33>/I2C Read' */
  localDW->obj_oc.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_oc;
  localDW->obj_oc.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_oc.isInitialized = 0;
  localDW->obj_oc.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_oc.matlabCodegenIsDeleted = false;
  localDW->obj_oc.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_oc;
  localDW->obj_oc.isSetupComplete = false;
  localDW->obj_oc.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_oc.BusSpeed = 100000U;
  varargin_1 = localDW->obj_oc.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_oc.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read1' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read2' */
  localDW->obj_h.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_h;
  localDW->obj_h.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_h.isInitialized = 0;
  localDW->obj_h.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_h.matlabCodegenIsDeleted = false;
  localDW->obj_h.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_h;
  localDW->obj_h.isSetupComplete = false;
  localDW->obj_h.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_h.BusSpeed = 100000U;
  varargin_1 = localDW->obj_h.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read3' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read4' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read5' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read6' */
  localDW->obj_g.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_g;
  localDW->obj_g.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_g.isInitialized = 0;
  localDW->obj_g.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_g.matlabCodegenIsDeleted = false;
  localDW->obj_g.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_g;
  localDW->obj_g.isSetupComplete = false;
  localDW->obj_g.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_g.BusSpeed = 100000U;
  varargin_1 = localDW->obj_g.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read7' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read8' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read10' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read11' */
  localDW->obj_a.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_a;
  localDW->obj_a.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_a.isInitialized = 0;
  localDW->obj_a.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_a.matlabCodegenIsDeleted = false;
  localDW->obj_a.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
  obj = &localDW->obj_a;
  localDW->obj_a.isSetupComplete = false;
  localDW->obj_a.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_a.BusSpeed = 100000U;
  varargin_1 = localDW->obj_a.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Write1' */
  localDW->obj_es.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_es;
  localDW->obj_es.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_es.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_es.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_es;
  localDW->obj_es.isSetupComplete = false;
  localDW->obj_es.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_es.BusSpeed = 100000U;
  varargin_1 = localDW->obj_es.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_es.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Write2' */
  localDW->obj_i2.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_i2;
  localDW->obj_i2.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i2.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i2.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_i2;
  localDW->obj_i2.isSetupComplete = false;
  localDW->obj_i2.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i2.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i2.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i2.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Write3' */
  localDW->obj_hv.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_hv;
  localDW->obj_hv.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_hv.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_hv.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_hv;
  localDW->obj_hv.isSetupComplete = false;
  localDW->obj_hv.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_hv.BusSpeed = 100000U;
  varargin_1 = localDW->obj_hv.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_hv.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read12' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  localDW->obj_e.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  localDW->obj_e.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read' incorporates:
   *  Outport: '<S33>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read1' incorporates:
   *  Outport: '<S33>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read2' incorporates:
   *  Outport: '<S33>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read3' incorporates:
   *  Outport: '<S33>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read4' incorporates:
   *  Outport: '<S33>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read5' incorporates:
   *  Outport: '<S33>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read6' incorporates:
   *  Outport: '<S33>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read7' incorporates:
   *  Outport: '<S33>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read8' incorporates:
   *  Outport: '<S33>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read9' incorporates:
   *  Outport: '<S33>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read10' incorporates:
   *  Outport: '<S33>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S33>/I2C Read11' incorporates:
   *  Outport: '<S33>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S33>/Byte Unpack' incorporates:
     *  Outport: '<S33>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S3>/One_time_initialization' */
void LOG_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_LOG_T *localB, DW_One_time_initialization_LO_T
  *localDW, P_One_time_initialization_LOG_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S33>/I2C Write3' incorporates:
     *  ArithShift: '<S33>/Shift Arithmetic1'
     *  Constant: '<S33>/registro memoria2 '
     *  DataTypeConversion: '<S33>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S33>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S33>/I2C Read' */
    if (localDW->obj_oc.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_oc.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_oc.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_oc.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S33>/I2C Read' */

    /* MATLABSystem: '<S33>/I2C Read1' */
    if (localDW->obj_b.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_b.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read1' */

    /* MATLABSystem: '<S33>/I2C Read2' */
    if (localDW->obj_h.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_h.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read2' */

    /* MATLABSystem: '<S33>/I2C Read3' */
    if (localDW->obj_o.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_o.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S33>/I2C Read3' */

    /* MATLABSystem: '<S33>/I2C Read4' */
    if (localDW->obj_f.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_f.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read4' */

    /* MATLABSystem: '<S33>/I2C Read5' */
    if (localDW->obj_i.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_i.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read5' */

    /* MATLABSystem: '<S33>/I2C Read6' */
    if (localDW->obj_g.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_g.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_g.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_g.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read6' */

    /* MATLABSystem: '<S33>/I2C Read7' */
    if (localDW->obj_c.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_c.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read7' */

    /* MATLABSystem: '<S33>/I2C Read8' */
    if (localDW->obj_p.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_p.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read8' */

    /* MATLABSystem: '<S33>/I2C Read9' */
    if (localDW->obj.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read9' */

    /* MATLABSystem: '<S33>/I2C Read10' */
    if (localDW->obj_m.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_m.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read10' */

    /* MATLABSystem: '<S33>/I2C Read11' */
    if (localDW->obj_a.SampleTime != LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      localDW->obj_a.SampleTime = LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S33>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read11' */

    /* MATLABSystem: '<S33>/I2C Write1' incorporates:
     *  Constant: '<S33>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_es.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S33>/I2C Write2' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_i2.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S33>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_hv.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S33>/I2C Read12' */
    if (localDW->obj_e.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_e.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S33>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S33>/Byte Unpack' */

    /* Unpack: <S33>/Byte Unpack */
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
void One_time_initializatio_Term(DW_One_time_initialization_LO_T *localDW)
{
  codertarget_arduinobase_int_p_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S33>/I2C Read' */
  obj = &localDW->obj_oc;
  if (!localDW->obj_oc.matlabCodegenIsDeleted) {
    localDW->obj_oc.matlabCodegenIsDeleted = true;
    if ((localDW->obj_oc.isInitialized == 1) && localDW->obj_oc.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read1' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read2' */
  obj = &localDW->obj_h;
  if (!localDW->obj_h.matlabCodegenIsDeleted) {
    localDW->obj_h.matlabCodegenIsDeleted = true;
    if ((localDW->obj_h.isInitialized == 1) && localDW->obj_h.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read3' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read4' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read5' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read6' */
  obj = &localDW->obj_g;
  if (!localDW->obj_g.matlabCodegenIsDeleted) {
    localDW->obj_g.matlabCodegenIsDeleted = true;
    if ((localDW->obj_g.isInitialized == 1) && localDW->obj_g.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read7' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read8' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read10' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read11' */
  obj = &localDW->obj_a;
  if (!localDW->obj_a.matlabCodegenIsDeleted) {
    localDW->obj_a.matlabCodegenIsDeleted = true;
    if ((localDW->obj_a.isInitialized == 1) && localDW->obj_a.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S33>/I2C Write1' */
  obj_0 = &localDW->obj_es;
  if (!localDW->obj_es.matlabCodegenIsDeleted) {
    localDW->obj_es.matlabCodegenIsDeleted = true;
    if ((localDW->obj_es.isInitialized == 1) && localDW->obj_es.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S33>/I2C Write2' */
  obj_0 = &localDW->obj_i2;
  if (!localDW->obj_i2.matlabCodegenIsDeleted) {
    localDW->obj_i2.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i2.isInitialized == 1) && localDW->obj_i2.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S33>/I2C Write3' */
  obj_0 = &localDW->obj_hv;
  if (!localDW->obj_hv.matlabCodegenIsDeleted) {
    localDW->obj_hv.matlabCodegenIsDeleted = true;
    if ((localDW->obj_hv.isInitialized == 1) && localDW->obj_hv.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read12' */
  obj = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void LOG_DATI_GPS_BMP_07_15_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter)
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
static boolean_T LOG_DATI_GPS_BMP_07_ifWhileCond(const boolean_T x[100])
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
void LOG_DATI_GPS_BMP_07_15_v2_step0(void) /* Sample time: [0.02s, 0.0s] */
{
  int32_T exitg3;
  int32_T x;
  real32_T tmp;
  uint32_T qY;
  uint16_T x_0;
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
  boolean_T y;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_f,
    &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[0],
    &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2,
    &LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  LOG_DATI_GPS_BMP_07_15_v2_B.status = 0;
  LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
  memset(&LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  memset(&LOG_DATI_GPS_BMP_07_15_v2_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  LOG_DATI_GPS_BMP_07_15_find_254
    (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e,
     LOG_DATI_GPS_BMP_07_15_v2_B.poss_254, &LOG_DATI_GPS_BMP_07_15_v2_B.num_254);
  if (LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz &&
      (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 == 1.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
      (LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e + 1U);
    if (LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e + 1U > 255U) {
      LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
    }

    if (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] != LOG_DATI_GPS_BMP_07_15_v2_B.f)
    {
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = 0.0;
    }
  }

  y = !LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz;
  if ((LOG_DATI_GPS_BMP_07_15_v2_B.num_254 == 1.0) && y) {
    LOG_DATI_GPS_BMP_07_15_v2_B.caso = 1;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_B.num_254 == 0.0) &&
             LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz) {
    LOG_DATI_GPS_BMP_07_15_v2_B.caso = 2;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_B.num_254 == 1.0) &&
             LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz) {
    LOG_DATI_GPS_BMP_07_15_v2_B.caso = 3;
  } else {
    if ((LOG_DATI_GPS_BMP_07_15_v2_B.num_254 == 2.0) && y) {
      LOG_DATI_GPS_BMP_07_15_v2_B.caso = 4;
    }
  }

  switch (LOG_DATI_GPS_BMP_07_15_v2_B.caso) {
   case 1:
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
      LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[(int32_T)
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254 - 1];
    if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 100.0) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.message[0] =
        LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[99];
      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = true;
    } else if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
               (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition + 1.0) - 1] <= 100) {
      LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
        (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] + 1.0) - 1] + 8U);
      LOG_DATI_GPS_BMP_07_15_v2_B.g = LOG_DATI_GPS_BMP_07_15_v2_B.f;
      if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
        LOG_DATI_GPS_BMP_07_15_v2_B.g = 255;
      }

      if (LOG_DATI_GPS_BMP_07_15_v2_B.g ==
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2) {
        LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 >= 0.0) {
            counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
          (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
           (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition + (real_T)
           LOG_DATI_GPS_BMP_07_15_v2_B.f);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
            c = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          LOG_DATI_GPS_BMP_07_15_v2_B.status = 0;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.status = counter - 1;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = c;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_B.f -
          LOG_DATI_GPS_BMP_07_15_v2_B.status;
        for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <
             LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++)
        {
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.status
            + LOG_DATI_GPS_BMP_07_15_v2_B.f];
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
        for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
             LOG_DATI_GPS_BMP_07_15_v2_B.caso < 100;
             LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
          LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
            =
            LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
            = 0U;
        }

        LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
        LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
        }

        if (LOG_DATI_GPS_BMP_07_15_v2_B.f >
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2;
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >
              LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len) {
            LOG_DATI_GPS_BMP_07_15_v2_B.g = 0;
            LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
          } else {
            LOG_DATI_GPS_BMP_07_15_v2_B.g = (int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition - 1;
            LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len;
          }

          LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_B.f -
            LOG_DATI_GPS_BMP_07_15_v2_B.g;
          for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <
               LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++)
          {
            LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
              LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.g
              + LOG_DATI_GPS_BMP_07_15_v2_B.f];
          }

          LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
            (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
             (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
          }

          LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf((real_T)
            LOG_DATI_GPS_BMP_07_15_v2_B.f -
            LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len);
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
            if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
              LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = (uint8_T)
                LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
            } else {
              LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
            }
          } else {
            LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = MAX_uint8_T;
          }

          LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = true;
        }
      }
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.message[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
      LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
      LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
    }
    break;

   case 2:
    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.x[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.f]
         != 0);
    }

    if (LOG_DATI_GPS_BMP_07_ifWhileCond(LOG_DATI_GPS_BMP_07_15_v2_B.x)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len + 1.0);
      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
          c = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len + (real_T)
         LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e);
      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
          counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (c > counter) {
        LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.status = c;
      }

      if (1 > LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e) {
        LOG_DATI_GPS_BMP_07_15_v2_B.caso = -1;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.caso =
          LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e - 1;
      }

      for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <=
           LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.message[(LOG_DATI_GPS_BMP_07_15_v2_B.status
          + LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] =
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.f];
      }

      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
      LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
      for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
           LOG_DATI_GPS_BMP_07_15_v2_B.caso < 100;
           LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
        LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[LOG_DATI_GPS_BMP_07_15_v2_B.caso] =
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
        LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso] =
          0U;
      }

      LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
      LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
      LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
      memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.message[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
      LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
    }
    break;

   case 3:
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
      (LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len + 1.0);
    if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
        c = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
      (LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len + (real_T)
       LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e);
    if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
        counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (c > counter) {
      LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.status = c;
    }

    if (1 > LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e) {
      LOG_DATI_GPS_BMP_07_15_v2_B.caso = -1;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e
        - 1;
    }

    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <=
         LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.message[(LOG_DATI_GPS_BMP_07_15_v2_B.status +
        LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] =
        LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.f];
    }

    LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
    LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
    for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
         100; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[LOG_DATI_GPS_BMP_07_15_v2_B.caso] =
        LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
      LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso] =
        0U;
    }

    LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
    LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
      (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[(int32_T)
       LOG_DATI_GPS_BMP_07_15_v2_B.num_254 - 1] + 1.0) - 1;
    if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.f]
        <= 100) {
      LOG_DATI_GPS_BMP_07_15_v2_B.g = (int32_T)
        (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.g > 255U) {
        LOG_DATI_GPS_BMP_07_15_v2_B.g = 255;
      }

      LOG_DATI_GPS_BMP_07_15_v2_B.caso =
        LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2;
      if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2 < 0) {
        LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
      } else {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2 > 255) {
          LOG_DATI_GPS_BMP_07_15_v2_B.caso = 255;
        }
      }

      if (LOG_DATI_GPS_BMP_07_15_v2_B.g == LOG_DATI_GPS_BMP_07_15_v2_B.caso) {
        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[(int32_T)
           LOG_DATI_GPS_BMP_07_15_v2_B.num_254 - 1]);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
            counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
          (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.f]
           + 7U);
        if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[(int32_T)
           LOG_DATI_GPS_BMP_07_15_v2_B.num_254 - 1] + (real_T)
           LOG_DATI_GPS_BMP_07_15_v2_B.f);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
            c = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = 0;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = counter - 1;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = c;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_B.f -
          LOG_DATI_GPS_BMP_07_15_v2_B.g;
        for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <
             LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++)
        {
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.g
            + LOG_DATI_GPS_BMP_07_15_v2_B.f];
        }

        for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
             LOG_DATI_GPS_BMP_07_15_v2_B.caso < 100;
             LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
          LOG_DATI_GPS_BMP_07_15_v2_B.messaggio_2[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
            =
            LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
            = 0U;
        }

        LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
        LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.g = (int32_T)
          (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
           (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.g > 255U) {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = 255;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.caso =
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2;
        if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2 < 0) {
          LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
        } else {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2 > 255) {
            LOG_DATI_GPS_BMP_07_15_v2_B.caso = 255;
          }
        }

        if (LOG_DATI_GPS_BMP_07_15_v2_B.g > LOG_DATI_GPS_BMP_07_15_v2_B.caso) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2;
          if (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[(int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_B.num_254 - 1] >
              LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len) {
            x = 0;
            LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
          } else {
            x = (int32_T)LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[(int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_B.num_254 - 1] - 1;
            LOG_DATI_GPS_BMP_07_15_v2_B.caso = (int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len;
          }

          LOG_DATI_GPS_BMP_07_15_v2_B.caso -= x;
          for (LOG_DATI_GPS_BMP_07_15_v2_B.g = 0; LOG_DATI_GPS_BMP_07_15_v2_B.g <
               LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.g++)
          {
            LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.g] =
              LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[x +
              LOG_DATI_GPS_BMP_07_15_v2_B.g];
          }

          LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
            (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.f]
             + 8U);
          if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
          }

          LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf((real_T)
            LOG_DATI_GPS_BMP_07_15_v2_B.f -
            LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len);
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
            if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
              LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = (uint8_T)
                LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
            } else {
              LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
            }
          } else {
            LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = MAX_uint8_T;
          }

          LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = true;
        }
      }
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.message[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
      LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
        (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] + 1.0) - 1] <= 100) {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0]);
      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
          counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
        (LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.f > 255U) {
        LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
      }

      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] + (real_T)
         LOG_DATI_GPS_BMP_07_15_v2_B.f);
      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
          c = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      if (counter > c) {
        LOG_DATI_GPS_BMP_07_15_v2_B.status = 0;
        LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.status = counter - 1;
        LOG_DATI_GPS_BMP_07_15_v2_B.f = c;
      }

      LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_B.f -
        LOG_DATI_GPS_BMP_07_15_v2_B.status;
      for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <
           LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
        LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.status
          + LOG_DATI_GPS_BMP_07_15_v2_B.f];
      }
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    LOG_DATI_GPS_BMP_07_15_v2_B.status = 1;
    if ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1] -
         LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[0] > 3.0)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf((real_T)
        LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2 -
        LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1]);
      qY = LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[(int32_T)
        (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1] + 1.0) - 1];
      LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)(qY + 7U);
      if (qY + 7U > 255U) {
        LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
      }

      if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 2.147483648E+9) {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= -2.147483648E+9) {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = (int32_T)
            LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = MIN_int32_T;
        }
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.g = MAX_int32_T;
      }

      if (LOG_DATI_GPS_BMP_07_15_v2_B.g == LOG_DATI_GPS_BMP_07_15_v2_B.f) {
        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1]);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
            counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)(qY + 7U);
        if (qY + 7U > 255U) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1] + (real_T)
           LOG_DATI_GPS_BMP_07_15_v2_B.f);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
            c = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          LOG_DATI_GPS_BMP_07_15_v2_B.status = 0;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.status = counter - 1;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = c;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_B.f -
          LOG_DATI_GPS_BMP_07_15_v2_B.status;
        for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <
             LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++)
        {
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.status
            + LOG_DATI_GPS_BMP_07_15_v2_B.f];
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.status = 2;
        for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
             LOG_DATI_GPS_BMP_07_15_v2_B.caso < 100;
             LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
          LOG_DATI_GPS_BMP_07_15_v2_B.messaggio_2[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
            =
            LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
            = 0U;
        }

        LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
        LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_15_v2_B.poss_254[1]);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 2.147483648E+9) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= -2.147483648E+9) {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = MIN_int32_T;
          }
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = MAX_int32_T;
        }

        if (LOG_DATI_GPS_BMP_07_15_v2_B.f >
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = -1;
          LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.f -= 2;
          LOG_DATI_GPS_BMP_07_15_v2_B.caso =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2;
        }

        LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = (int8_T)
          ((LOG_DATI_GPS_BMP_07_15_v2_B.caso - LOG_DATI_GPS_BMP_07_15_v2_B.f) -
           1);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 2.147483648E+9) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= -2.147483648E+9) {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)
              LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = MIN_int32_T;
          }
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = MAX_int32_T;
        }

        if (LOG_DATI_GPS_BMP_07_15_v2_B.f >
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2) {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = 0;
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_B.g = LOG_DATI_GPS_BMP_07_15_v2_B.f - 1;
          LOG_DATI_GPS_BMP_07_15_v2_B.f =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.caso = LOG_DATI_GPS_BMP_07_15_v2_B.f -
          LOG_DATI_GPS_BMP_07_15_v2_B.g;
        for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f <
             LOG_DATI_GPS_BMP_07_15_v2_B.caso; LOG_DATI_GPS_BMP_07_15_v2_B.f++)
        {
          LOG_DATI_GPS_BMP_07_15_v2_DW.message[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_15_v2_B.g
            + LOG_DATI_GPS_BMP_07_15_v2_B.f];
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.f = (int32_T)(qY + 8U);
        if (qY + 8U > 255U) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
        }

        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = rt_roundd_snf((real_T)
          LOG_DATI_GPS_BMP_07_15_v2_B.f - LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len);
        if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >= 0.0) {
            LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = (uint8_T)
              LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
          } else {
            LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
          }
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = true;
      }
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.message[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_15_v2_DW.counter_e = 0U;
      LOG_DATI_GPS_BMP_07_15_v2_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&LOG_DATI_GPS_BMP_07_15_v2_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
       LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
    LOG_DATI_GPS_BMP_07_15_v2_B.buffer[3 * LOG_DATI_GPS_BMP_07_15_v2_B.f] = 0U;
  }

  for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
       LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
    for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
         2; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.g = 3 * LOG_DATI_GPS_BMP_07_15_v2_B.f +
        LOG_DATI_GPS_BMP_07_15_v2_B.caso;
      LOG_DATI_GPS_BMP_07_15_v2_B.buffer[LOG_DATI_GPS_BMP_07_15_v2_B.g + 1] =
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory4_PreviousInput[LOG_DATI_GPS_BMP_07_15_v2_B.g];
    }
  }

  LOG_DATI_GPS_BMP_07_15_v2_B.caso = 3;
  exitg1 = false;
  while ((!exitg1) && (LOG_DATI_GPS_BMP_07_15_v2_B.caso >= 1)) {
    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.x[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        (LOG_DATI_GPS_BMP_07_15_v2_B.buffer[(3 * LOG_DATI_GPS_BMP_07_15_v2_B.f +
          LOG_DATI_GPS_BMP_07_15_v2_B.caso) - 1] == 0);
    }

    y = true;
    LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
    exitg2 = false;
    while ((!exitg2) && (LOG_DATI_GPS_BMP_07_15_v2_B.f < 100)) {
      if (!LOG_DATI_GPS_BMP_07_15_v2_B.x[LOG_DATI_GPS_BMP_07_15_v2_B.f]) {
        y = false;
        exitg2 = true;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.f++;
      }
    }

    if (y) {
      counter = (uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.caso;
      exitg1 = true;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.caso--;
    }
  }

  if (LOG_DATI_GPS_BMP_07_15_v2_B.status == 1) {
    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.buffer[(counter + 3 *
        LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] =
        LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[LOG_DATI_GPS_BMP_07_15_v2_B.f];
    }
  } else if (LOG_DATI_GPS_BMP_07_15_v2_B.status == 2) {
    qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      qY = 0U;
    }

    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.buffer[(counter + 3 *
        LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] =
        LOG_DATI_GPS_BMP_07_15_v2_B.messaggio[LOG_DATI_GPS_BMP_07_15_v2_B.f];
      LOG_DATI_GPS_BMP_07_15_v2_B.buffer[((int32_T)qY + 3 *
        LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] =
        LOG_DATI_GPS_BMP_07_15_v2_B.messaggio_2[LOG_DATI_GPS_BMP_07_15_v2_B.f];
    }
  } else {
    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.buffer[(counter + 3 *
        LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] = 0U;
    }
  }

  for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
       LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
    LOG_DATI_GPS_BMP_07_15_v2_B.mess_out[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory4_PreviousInput[3 *
      LOG_DATI_GPS_BMP_07_15_v2_B.f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.Add =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory4_PreviousInput[5] +
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.mess_out[2] !=
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory5_PreviousInput[2]) {
    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 100;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.x[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        (LOG_DATI_GPS_BMP_07_15_v2_B.mess_out[LOG_DATI_GPS_BMP_07_15_v2_B.f] !=
         0);
    }

    y = true;
    LOG_DATI_GPS_BMP_07_15_v2_B.f = 0;
    exitg1 = false;
    while ((!exitg1) && (LOG_DATI_GPS_BMP_07_15_v2_B.f < 100)) {
      if (!LOG_DATI_GPS_BMP_07_15_v2_B.x[LOG_DATI_GPS_BMP_07_15_v2_B.f]) {
        y = false;
        exitg1 = true;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_B.f++;
      }
    }

    if (!y) {
      if (LOG_DATI_GPS_BMP_07_15_v2_DW.counter > 100) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.counter = 0U;
      }

      qY = LOG_DATI_GPS_BMP_07_15_v2_DW.counter + 1U;
      if (LOG_DATI_GPS_BMP_07_15_v2_DW.counter + 1U > 65535U) {
        qY = 65535U;
      }

      LOG_DATI_GPS_BMP_07_15_v2_DW.counter = (uint16_T)qY;
    }
  }

  LOG_DATI_GPS_BMP_07_15_v2_B.new_mex = LOG_DATI_GPS_BMP_07_15_v2_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory1[0] =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0];
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory1[1] =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1];

  /* Memory: '<Root>/Memory' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory_o[0] =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[0];
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory_o[1] =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[1];
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory_o[2] =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[2];
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory_o[3] =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[3];

  /* Memory: '<S1>/Memory3' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory3 =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput;
  for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
       8; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
    /* Memory: '<S1>/Memory' */
    LOG_DATI_GPS_BMP_07_15_v2_B.Memory[LOG_DATI_GPS_BMP_07_15_v2_B.caso] =
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_o[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&LOG_DATI_GPS_BMP_07_15_v2_B.mess_out[0], &LOG_DATI_GPS_BMP_07_15_v2_B.Add,
     &LOG_DATI_GPS_BMP_07_15_v2_B.new_mex,
     &LOG_DATI_GPS_BMP_07_15_v2_P.SIUAVuint8_Value,
     &LOG_DATI_GPS_BMP_07_15_v2_B.Memory[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.Memory1[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.Memory_o[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.Memory3,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o1[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o2,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o4_e[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o5[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o8,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o10[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o12,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o13,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o14,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o15,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o16,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
       6; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
    LOG_DATI_GPS_BMP_07_15_v2_B.WP_info_in[LOG_DATI_GPS_BMP_07_15_v2_B.caso] =
      LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
  }

  if ((!LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP_not_empty) ||
      ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[0] == 3) &&
       (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[1] == 250))) {
    memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP_not_empty = true;
    memset(&LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP_AL_not_empty) ||
      ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[0] == 3) &&
       (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[1] == 250))) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP_AL_not_empty = true;
  }

  LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0] =
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[0];
  LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] =
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o7[1];
  LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[2] =
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[0];
  if (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0] == 1) {
    if ((LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] > 0) &&
        (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o8) > 0.0F) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[LOG_DATI_GPS_BMP_07_15_v2_B.GC_info
          [1] - 1] = 1.0F;
      } else {
        if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o8 == 0.0F) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[LOG_DATI_GPS_BMP_07_15_v2_B.GC_info
            [1] - 1] = 0.0F;
        }
      }
    } else {
      if ((LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] > 7) &&
          (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] < 12)) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[LOG_DATI_GPS_BMP_07_15_v2_B.GC_info
          [1] - 1] = LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o8;
      }
    }
  }

  if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o12 == 13) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o12
      - 1] = LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o13;
  }

  memcpy(&LOG_DATI_GPS_BMP_07_15_v2_B.Val_out_MAV[0],
         &LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0] == 3) &&
      (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] == 200)) {
    if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[0] > 6) {
      LOG_DATI_GPS_BMP_07_15_v2_B.WP_info_in[0] = 6U;
    }

    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 6;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        LOG_DATI_GPS_BMP_07_15_v2_B.WP_info_in[0];
    }
  }

  if ((LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0] == 3) &&
      (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] < 200)) {
    if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o10[1] == 0.0F) {
      qY = LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[1] + 1U;
      if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 7;
           LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP[((int32_T)qY + 6 *
          LOG_DATI_GPS_BMP_07_15_v2_B.f) - 1] =
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o10[LOG_DATI_GPS_BMP_07_15_v2_B.f];
      }

      qY = LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[1] + 1U;
      if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 6;
           LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[((int32_T)qY + 6 *
          (LOG_DATI_GPS_BMP_07_15_v2_B.f + 1)) - 1] =
          LOG_DATI_GPS_BMP_07_15_v2_B.WP_info_in[LOG_DATI_GPS_BMP_07_15_v2_B.f +
          1];
      }
    } else {
      qY = LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[1] + 1U;
      if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 6;
           LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[((int32_T)qY + 6 *
          (LOG_DATI_GPS_BMP_07_15_v2_B.f + 1)) - 1] =
          LOG_DATI_GPS_BMP_07_15_v2_B.WP_info_in[LOG_DATI_GPS_BMP_07_15_v2_B.f +
          1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6 == 0) &&
      (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d == 0)) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 0U;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 0U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6 == 0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d == 3)) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 0U;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 0U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6 == 0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d == 2)) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 0U;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 0U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6 == 0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d == 1)) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 0U;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 0U;
  } else {
    switch (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6) {
     case 192:
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 192U;
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 208U;
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o6 == 220) &&
          (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d != 5)) {
        if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[0] == 0) &&
            (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[1] == 0) &&
            ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[2] == 1) ||
             (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[3] == 1) ||
             (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[4] == 1) ||
             (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[5] == 1) ||
             (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[6] == 1) ||
             (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[7] == 1))) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 220U;
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 220U;
        } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[0] == 0)
                   && (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[1] ==
                       1) &&
                   ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[2] ==
                     1) ||
                    (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[3] ==
                     1) ||
                    (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[4] ==
                     1) ||
                    (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[5] ==
                     1) ||
                    (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[6] ==
                     1) ||
                    (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[7] ==
                     1))) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 220U;
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 220U;
        } else {
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 208U;
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput = 208U;
        }
      } else if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3_d == 5) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 220U;
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] = 192U;
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  qY = 100U * LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[5];
  if (qY > 65535U) {
    qY = 65535U;
  }

  if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[4] == 0) {
    if ((uint16_T)qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[4] == 0U ?
                   MAX_uint32_T : (uint32_T)(uint16_T)qY /
                   LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[4]);
    x_0 = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)z *
      LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[4]));
    if ((x_0 > 0) && (x_0 >= (int32_T)((uint32_T)
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[4] >> 1) +
                      (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  LOG_DATI_GPS_BMP_07_15_v2_B.T_0 = LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[12];

  /* RateTransition: '<S22>/Rate Transition' */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_DW.RateTransition_Buffer0;

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant3'
   *  Memory: '<S22>/Memory1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.num_254 =
    (LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_n +
     LOG_DATI_GPS_BMP_07_15_v2_P.Constant3_Value_e) +
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput;

  /* Switch: '<S22>/Switch' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 >
      LOG_DATI_GPS_BMP_07_15_v2_P.Switch_Threshold) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant2'
     */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_n;
  } else {
    /* Switch: '<S22>/Switch' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254;
  }

  /* End of Switch: '<S22>/Switch' */

  /* MATLAB Function: '<S12>/iflogic_function' */
  if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 1.0) ||
      (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 3.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 26U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 2.0) ||
             (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 4.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 30U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 2.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 33U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 6.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 34U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 0.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 0U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             ((LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 1.0) ||
              (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 5.0) ||
              (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 9.0))) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 1U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             ((LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 3.0) ||
              (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 8.0))) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 74U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 7.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 36U;
  } else if ((LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition == 4.0)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = 29U;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S12>/iflogic_function' */

  /* Sum: '<S22>/Add' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Memory: '<S22>/Memory'
   */
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput +=
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value +
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_i;

  /* Gain: '<S12>/Gain' */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain *
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3 =
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (uint32_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 6;
       LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
    LOG_DATI_GPS_BMP_07_15_v2_B.WP_info[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
      LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[6 * LOG_DATI_GPS_BMP_07_15_v2_B.f];
  }

  for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 7;
       LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
    LOG_DATI_GPS_BMP_07_15_v2_B.WP_param[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
      LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP[6 * LOG_DATI_GPS_BMP_07_15_v2_B.f];
  }

  if ((LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0] == 2) &&
      (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] < 6)) {
    qY = LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] + 1U;
    if (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 6;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.WP_info[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[(6 * LOG_DATI_GPS_BMP_07_15_v2_B.f +
        (int32_T)qY) - 1];
    }

    qY = LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] + 1U;
    if (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 7;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.WP_param[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbP[(6 * LOG_DATI_GPS_BMP_07_15_v2_B.f +
        (int32_T)qY) - 1];
    }
  }

  if ((LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0] == 3) &&
      (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] < 200)) {
    qY = LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] + 1U;
    if (LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (LOG_DATI_GPS_BMP_07_15_v2_B.f = 0; LOG_DATI_GPS_BMP_07_15_v2_B.f < 6;
         LOG_DATI_GPS_BMP_07_15_v2_B.f++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.WP_info[LOG_DATI_GPS_BMP_07_15_v2_B.f] =
        LOG_DATI_GPS_BMP_07_15_v2_DW.WP_dbI[(6 * LOG_DATI_GPS_BMP_07_15_v2_B.f +
        (int32_T)qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S16>/MATLAB Function' */

  /* Gain: '<S14>/Gain' incorporates:
   *  Constant: '<S14>/Constant'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_o *
     LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_o);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S14>/load uint16'
   *  Gain: '<S14>/Gain'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[0] =
    LOG_DATI_GPS_BMP_07_15_v2_P.loaduint16_Value;
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  qY = 10U * z;
  if (qY > 65535U) {
    qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S14>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)qY;
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[3] =
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[6];
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[4] =
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[2];
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[5] =
    LOG_DATI_GPS_BMP_07_15_v2_P._Value;

  /* Gain: '<S14>/Gain2' incorporates:
   *  Constant: '<S14>/Constant3'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Gain2_Gain *
     LOG_DATI_GPS_BMP_07_15_v2_P.Constant3_Value_b);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* Gain: '<S14>/Gain1' incorporates:
   *  Gain: '<S14>/Gain2'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.Gain1 = (int16_T)
    (((LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int16_T)
       -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition :
       (int32_T)(int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) *
      LOG_DATI_GPS_BMP_07_15_v2_P.Gain1_Gain_p) >> 18);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<S14>/Constant4'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Constant4_Value_d);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_15_v2_B.B_Remaining = (int8_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int8_T)
     -(int8_T)(uint8_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (int8_T)(uint8_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_oq);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion =
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (uint32_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_m[0]);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* MATLAB Function: '<S10>/Alarm set' */
  rtb_H_mav[0] = LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0];

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_m[1]);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* MATLAB Function: '<S10>/Alarm set' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_H_mav[1] = LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1];
  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_id[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_id[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S10>/Type fixed_wing Autopilot generic'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[0] =
    LOG_DATI_GPS_BMP_07_15_v2_P.Typefixed_wingAutopilotgeneric_[0];
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[2] = rtb_H_mav[0];
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[1] =
    LOG_DATI_GPS_BMP_07_15_v2_P.Typefixed_wingAutopilotgeneric_[1];
  LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[3] = rtb_H_mav[1];

  /* RateTransition generated from: '<S2>/S-Function' */
  if (LOG_DATI_GPS_BMP_07_15_v2_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition generated from: '<S2>/S-Function' */
    for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
         9; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
      LOG_DATI_GPS_BMP_07_15_v2_B.TmpRTBAtSFunctionInport14[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
        =
        LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport14_Buffe[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
    }

    /* End of RateTransition generated from: '<S2>/S-Function' */
    for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
         6; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
      /* RateTransition generated from: '<S2>/S-Function' */
      LOG_DATI_GPS_BMP_07_15_v2_B.TmpRTBAtSFunctionInport15[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
        =
        LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
    }
  }

  /* End of RateTransition generated from: '<S2>/S-Function' */

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Lat Simulated'
   *  Gain: '<S19>/Gain'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_f *
    LOG_DATI_GPS_BMP_07_15_v2_P.LatSimulated_Value *
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_od[0];

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_d[0] =
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Long Simulated'
   *  Gain: '<S20>/Gain'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_j *
    LOG_DATI_GPS_BMP_07_15_v2_P.LongSimulated_Value *
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_od[1];

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_d[1] =
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Alt Simulated'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_od[2] *
    LOG_DATI_GPS_BMP_07_15_v2_P.AltSimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_d[2] =
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/alt_r'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_od[3] *
    LOG_DATI_GPS_BMP_07_15_v2_P.alt_r_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_d[3] =
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/v Simulated1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain1_Gain *
    LOG_DATI_GPS_BMP_07_15_v2_P.vSimulated1_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1_d[0] = (int16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/vel y'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain1_Gain *
    LOG_DATI_GPS_BMP_07_15_v2_P.vely_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1_d[1] = (int16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/RC Simulated'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain1_Gain *
    LOG_DATI_GPS_BMP_07_15_v2_P.RCSimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1_d[2] = (int16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* Gain: '<S9>/Gain2' incorporates:
   *  Constant: '<S9>/Heading simulated'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain2_Gain_p *
    LOG_DATI_GPS_BMP_07_15_v2_P.Headingsimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion2 = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  LOG_One_time_initialization(!LOG_DATI_GPS_BMP_07_15_v2_DW.UnitDelay_DSTATE,
    &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization,
    &LOG_DATI_GPS_BMP_07_15_v2_DW.One_time_initialization,
    &LOG_DATI_GPS_BMP_07_15_v2_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (LOG_DATI_GPS_BMP_07_15_v2_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S30>/I2C Read12' */
    if (LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.SampleTime !=
        LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.SampleTime =
        LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &counter, 1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead
        (LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S30>/I2C Read1' */
    if (LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.SampleTime !=
        LOG_DATI_GPS_BMP_07_15_v2_P.t_AP) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.SampleTime =
        LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &counter, 1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead
        (LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw_0[0], 3U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw_0[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
      output[2] = 0U;
    }

    /* ArithShift: '<S30>/Shift Arithmetic4' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
        (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
        (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic3' incorporates:
     *  Constant: '<S30>/Constant5'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant5_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.num_254) || rtIsInf
        (LOG_DATI_GPS_BMP_07_15_v2_B.num_254)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = fmod
        (LOG_DATI_GPS_BMP_07_15_v2_B.num_254, 4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic1' incorporates:
     *  Constant: '<S30>/Constant6'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant6_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit) || rtIsInf
        (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit = fmod
        (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S30>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S30>/Shift Arithmetic1'
     *  ArithShift: '<S30>/Shift Arithmetic3'
     *  ArithShift: '<S30>/Shift Arithmetic4'
     *  Constant: '<S30>/Constant10'
     *  Constant: '<S30>/Constant11'
     *  Constant: '<S30>/Constant7'
     *  MATLABSystem: '<S30>/I2C Read1'
     *  Sum: '<S30>/Sum1'
     *  Sum: '<S30>/Sum4'
     *  Sum: '<S30>/Sum5'
     *  Sum: '<S30>/Sum6'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1_k = (int32_T)
      ((((((LOG_DATI_GPS_BMP_07_15_v2_P.Constant7_Value + output[0]) <<
           (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? -(int32_T)
            (uint32_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
            (uint32_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) +
          ((LOG_DATI_GPS_BMP_07_15_v2_P.Constant10_Value_b + output[1]) <<
           (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
            -LOG_DATI_GPS_BMP_07_15_v2_B.num_254 : (int32_T)(uint32_T)
            LOG_DATI_GPS_BMP_07_15_v2_B.num_254))) +
         LOG_DATI_GPS_BMP_07_15_v2_P.Constant11_Value) + output[2]) >>
       (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit : (int32_T)(uint32_T)
        LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit));

    /* ArithShift: '<S30>/Shift Arithmetic7' incorporates:
     *  Constant: '<S30>/Constant2'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
        (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
        (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic6' incorporates:
     *  Constant: '<S30>/Constant3'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant3_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.num_254) || rtIsInf
        (LOG_DATI_GPS_BMP_07_15_v2_B.num_254)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = fmod
        (LOG_DATI_GPS_BMP_07_15_v2_B.num_254, 4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic2' incorporates:
     *  Constant: '<S30>/Constant4'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant4_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit) || rtIsInf
        (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit = fmod
        (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S30>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S30>/Shift Arithmetic2'
     *  ArithShift: '<S30>/Shift Arithmetic6'
     *  ArithShift: '<S30>/Shift Arithmetic7'
     *  Constant: '<S30>/Constant8'
     *  Constant: '<S30>/Constant9'
     *  MATLABSystem: '<S30>/I2C Read12'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum2'
     *  Sum: '<S30>/Sum3'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_e = (int32_T)
      ((((LOG_DATI_GPS_BMP_07_15_v2_P.Constant8_Value + rtb_H_mav[0]) <<
         (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)(uint32_T)
          LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) +
        ((LOG_DATI_GPS_BMP_07_15_v2_P.Constant9_Value + rtb_H_mav[1]) <<
         (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
          -LOG_DATI_GPS_BMP_07_15_v2_B.num_254 : (int32_T)(uint32_T)
          LOG_DATI_GPS_BMP_07_15_v2_B.num_254))) >>
       (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit : (int32_T)(uint32_T)
        LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit));

    /* S-Function (calc_T): '<S30>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead1,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead2,
       &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_e,
       &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1,
       &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2_i);

    /* S-Function (calc_p): '<S30>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead3,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead4,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead5,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead6,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead7,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead8,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead9,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead10,
       &LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization.I2CRead11,
       &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1_k,
       &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2_i,
       &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_j == 1.0) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.P_ref =
      LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder1;
  }

  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_l == 1.0) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.P_ref =
      LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_ma;
    LOG_DATI_GPS_BMP_07_15_v2_DW.rl_up = 20.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.rl_dw = -20.0;
  }

  /* Product: '<S29>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S29>/sample time'
   *
   * About '<S29>/sample time':
   *  y = K where K = ( w * Ts )
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit =
    LOG_DATI_GPS_BMP_07_15_v2_DW.rl_up *
    LOG_DATI_GPS_BMP_07_15_v2_P.sampletime_WtEt;

  /* Sum: '<S29>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S29>/Delay Input2'
   *
   * Block description for '<S29>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S29>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition =
    LOG_DATI_GPS_BMP_07_15_v2_DW.P_ref -
    LOG_DATI_GPS_BMP_07_15_v2_DW.DelayInput2_DSTATE;

  /* Switch: '<S35>/Switch2' incorporates:
   *  RelationalOperator: '<S35>/LowerRelop1'
   */
  if (!(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition >
        LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit)) {
    /* Product: '<S29>/delta fall limit' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function'
     *  SampleTimeMath: '<S29>/sample time'
     *
     * About '<S29>/sample time':
     *  y = K where K = ( w * Ts )
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit =
      LOG_DATI_GPS_BMP_07_15_v2_DW.rl_dw *
      LOG_DATI_GPS_BMP_07_15_v2_P.sampletime_WtEt;

    /* Switch: '<S35>/Switch' incorporates:
     *  RelationalOperator: '<S35>/UpperRelop'
     */
    if (!(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition <
          LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit)) {
      LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit =
        LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition;
    }

    /* End of Switch: '<S35>/Switch' */
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Sum: '<S29>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S29>/Delay Input2'
   *
   * Block description for '<S29>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S29>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LOG_DATI_GPS_BMP_07_15_v2_DW.DelayInput2_DSTATE +=
    LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit;

  /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
   *  Constant: '<S15>/RC simulated'
   *  Constant: '<S15>/TAS simulated'
   *  Constant: '<S15>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  MATLAB Function: '<S3>/MATLAB Function1'
   *  UnitDelay: '<S29>/Delay Input2'
   *
   * Block description for '<S29>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_l[0] = (real32_T)
    LOG_DATI_GPS_BMP_07_15_v2_P.TASsimulated_Value;
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_l[1] = (real32_T)
    LOG_DATI_GPS_BMP_07_15_v2_P.vsimulated_Value;
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_l[2] = (real32_T)(log((real_T)
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder1 /
    LOG_DATI_GPS_BMP_07_15_v2_DW.DelayInput2_DSTATE) * -8333.3333333333339);
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_l[3] = (real32_T)
    LOG_DATI_GPS_BMP_07_15_v2_P.RCsimulated_Value;

  /* DataTypeConversion: '<S15>/Data Type Conversion4' incorporates:
   *  Constant: '<S15>/ Heading simulated'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Headingsimulated_Value_f);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion4' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion4 = (int16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion5' incorporates:
   *  Constant: '<S15>/Rpm simulated'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Rpmsimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion5' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion5 = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* Gain: '<S24>/Gain2' incorporates:
   *  Constant: '<S13>/Manetta Simulated'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit =
    LOG_DATI_GPS_BMP_07_15_v2_P.Gain2_Gain_l *
    LOG_DATI_GPS_BMP_07_15_v2_P.ManettaSimulated_Value;

  /* Sum: '<S24>/Sum' incorporates:
   *  Constant: '<S13>/Equilibratore Simulated'
   *  Constant: '<S24>/Constant2'
   *  Gain: '<S25>/Gain'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.num_254 = LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_n *
    LOG_DATI_GPS_BMP_07_15_v2_P.EquilibratoreSimulated_Value +
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_g;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Constant: '<S13>/Alettoni Simulated'
   *  Constant: '<S24>/Constant2'
   *  Gain: '<S26>/Gain'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.Sum1 = LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_j2 *
    LOG_DATI_GPS_BMP_07_15_v2_P.AlettoniSimulated_Value +
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_g;

  /* Sum: '<S24>/Sum2' incorporates:
   *  Constant: '<S13>/Timone Simulated'
   *  Constant: '<S24>/Constant2'
   *  Gain: '<S27>/Gain'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.Sum2 = LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_oo *
    LOG_DATI_GPS_BMP_07_15_v2_P.TimoneSimulated_Value +
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_g;

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1 = LOG_DATI_GPS_BMP_07_15_v2_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_p;

  /* Saturate: '<S13>/Saturation' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1 >
      LOG_DATI_GPS_BMP_07_15_v2_P.Saturation_UpperSat) {
    LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1 =
      LOG_DATI_GPS_BMP_07_15_v2_P.Saturation_UpperSat;
  } else {
    if (LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1 <
        LOG_DATI_GPS_BMP_07_15_v2_P.Saturation_LowerSat) {
      LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1 =
        LOG_DATI_GPS_BMP_07_15_v2_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_a < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_a);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_a);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[0] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.deltafalllimit);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[1] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.num_254 < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.num_254);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.num_254);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[2] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.Sum1 < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.Sum1);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.Sum1);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[3] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.Sum2 < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.Sum2);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.Sum2);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[4] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[0] < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[0]);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[0]);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[5] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[1] < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[1]);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[1]);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[6] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[2] < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[2]);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_k[2]);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[7] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1 < 0.0) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1);
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_15_v2_B.PatohPa1);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Heading[8] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  LOG_DATI_GPS_BMP_07_15_v2_B.Memory_p =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_m;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_n = (real32_T)
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_mk;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Gain: '<S2>/Pa to hPa'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_p = (real32_T)
    (LOG_DATI_GPS_BMP_07_15_v2_P.PatohPa_Gain *
     LOG_DATI_GPS_BMP_07_15_v2_P.Constant6_Value_i);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1 = (real32_T)
    (LOG_DATI_GPS_BMP_07_15_v2_P.PatohPa1_Gain *
     LOG_DATI_GPS_BMP_07_15_v2_P.Constant2_Value_c);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_15_v2_P.Constant3_Value_k);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion2_h = (int16_T)
    (LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_15_v2_B.RateTransition);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S14>/onboard_control_sensor_present uint32'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&LOG_DATI_GPS_BMP_07_15_v2_B.iflogic,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3,
     &LOG_DATI_GPS_BMP_07_15_v2_P.SIUAVuint8_Value,
     &LOG_DATI_GPS_BMP_07_15_v2_B.GC_info[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.Val_out_MAV[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.WP_info[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.WP_param[0],
     &LOG_DATI_GPS_BMP_07_15_v2_P.onboard_control_sensor_presentu[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctionI[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.Gain1,
     &LOG_DATI_GPS_BMP_07_15_v2_B.B_Remaining,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion,
     &LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.TmpRTBAtSFunctionInport14[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.TmpRTBAtSFunctionInport15[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_d[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1_d[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion2,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_l[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion4,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion5,
     &LOG_DATI_GPS_BMP_07_15_v2_B.Heading[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.Memory_p,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion3_n,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o14,
     &LOG_DATI_GPS_BMP_07_15_v2_B.T_0,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o15,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion_p,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion1,
     &LOG_DATI_GPS_BMP_07_15_v2_B.DataTypeConversion2_h,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o5[0],
     &LOG_DATI_GPS_BMP_07_15_v2_P.Constant4_Value_e,
     &LOG_DATI_GPS_BMP_07_15_v2_P.Constant5_Value_e,
     &LOG_DATI_GPS_BMP_07_15_v2_P.Constant10_Value, ((const uint16_T*)
      &LOG_DATI_GPS_BMP_07_15_v2_U16GND),
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o1_e,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o2_g[0],
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3,
     &LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o1_e > 0) {
    /* Chart: '<S8>/Chart' */
    if (LOG_DATI_GPS_BMP_07_15_v2_DW.is_active_c9_LOG_DATI_GPS_BMP_0 == 0U) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.is_active_c9_LOG_DATI_GPS_BMP_0 = 1U;
      LOG_DATI_GPS_BMP_07_15_v2_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (LOG_DATI_GPS_BMP_07_15_v2_DW.obj.Protocol !=
            LOG_DATI_GPS_BMP_07_15_v2_P.SerialTransmit_Protocol) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.obj.Protocol =
            LOG_DATI_GPS_BMP_07_15_v2_P.SerialTransmit_Protocol;
        }

        counter =
          LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o2_g[LOG_DATI_GPS_BMP_07_15_v2_DW.i
          - 1];
        MW_Serial_write(LOG_DATI_GPS_BMP_07_15_v2_DW.obj.port, &counter, 1.0,
                        LOG_DATI_GPS_BMP_07_15_v2_DW.obj.dataSizeInBytes,
                        LOG_DATI_GPS_BMP_07_15_v2_DW.obj.sendModeEnum,
                        LOG_DATI_GPS_BMP_07_15_v2_DW.obj.dataType,
                        LOG_DATI_GPS_BMP_07_15_v2_DW.obj.sendFormatEnum, 2.0,
                        '\x00');
        if (LOG_DATI_GPS_BMP_07_15_v2_DW.i <
            LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o3) {
          LOG_DATI_GPS_BMP_07_15_v2_B.f = LOG_DATI_GPS_BMP_07_15_v2_DW.i + 1;
          if (LOG_DATI_GPS_BMP_07_15_v2_DW.i + 1 > 255) {
            LOG_DATI_GPS_BMP_07_15_v2_B.f = 255;
          }

          LOG_DATI_GPS_BMP_07_15_v2_DW.i = (uint8_T)
            LOG_DATI_GPS_BMP_07_15_v2_B.f;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      LOG_DATI_GPS_BMP_07_15_v2_DW.i = 1U;
    }

    /* End of Chart: '<S8>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&LOG_DATI_GPS_BMP_07_15_v2_DW.Memory4_PreviousInput[0],
         &LOG_DATI_GPS_BMP_07_15_v2_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&LOG_DATI_GPS_BMP_07_15_v2_P.Constant1_Value_f,
    &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1_e[0],
    &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o2,
    &LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&LOG_DATI_GPS_BMP_07_15_v2_DW.Memory5_PreviousInput[0],
         &LOG_DATI_GPS_BMP_07_15_v2_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[0] =
    LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[0];
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[1] =
    LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[1];
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[2] =
    LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[2];
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[3] =
    LOG_DATI_GPS_BMP_07_15_v2_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
       8; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_o[LOG_DATI_GPS_BMP_07_15_v2_B.caso]
      =
      LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o11[LOG_DATI_GPS_BMP_07_15_v2_B.caso];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[0] = (uint8_T)
    AP_mode_idx_0;
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[1] = (uint8_T)
    AP_mode_idx_1;
  for (LOG_DATI_GPS_BMP_07_15_v2_B.caso = 0; LOG_DATI_GPS_BMP_07_15_v2_B.caso <
       7; LOG_DATI_GPS_BMP_07_15_v2_B.caso++) {
    tmp = rt_roundf_snf
      (LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[LOG_DATI_GPS_BMP_07_15_v2_B.caso]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[LOG_DATI_GPS_BMP_07_15_v2_B.caso
          + 2] = (uint8_T)tmp;
      } else {
        LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[LOG_DATI_GPS_BMP_07_15_v2_B.caso
          + 2] = 0U;
      }
    } else {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[LOG_DATI_GPS_BMP_07_15_v2_B.caso
        + 2] = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  LOG_DATI_GPS_BMP_07_15_v2_DW.UnitDelay_DSTATE =
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant3_Value_o;

  /* Update for Memory: '<S2>/Memory' */
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_m =
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunction_o4;
}

/* Model step function for TID1 */
void LOG_DATI_GPS_BMP_07_15_v2_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S22>/Add2' incorporates:
   *  Constant: '<S22>/Constant4'
   *  Constant: '<S22>/Constant5'
   *  Memory: '<S22>/Memory2'
   */
  LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput +=
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant4_Value_f +
    LOG_DATI_GPS_BMP_07_15_v2_P.Constant5_Value_f;

  /* Switch: '<S22>/Switch1' */
  if (LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput >
      LOG_DATI_GPS_BMP_07_15_v2_P.Switch1_Threshold) {
    /* Sum: '<S22>/Add2' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_P.Constant4_Value_f;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* RateTransition: '<S22>/Rate Transition' */
  LOG_DATI_GPS_BMP_07_15_v2_DW.RateTransition_Buffer0 =
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput;
}

/* Model step function for TID2 */
void LOG_DATI_GPS_BMP_07_15_v2_step2(void) /* Sample time: [1.0s, 0.0s] */
{
  int32_T i;
  real32_T tmp;
  int16_T rtb_DataTypeConversion_j[9];

  /* S-Function (Mti): '<Root>/S-Function Builder' */
  Mti_Outputs_wrapper(&LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder[0],
                      &LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE_o);

  /* S-Function (byte2any_svd): '<Root>/Byte Unpack' */

  /* Unpack: <Root>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&LOG_DATI_GPS_BMP_07_15_v2_B.ByteUnpack_o1[0], (uint8_T*)
             &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder[0] +
             MW_inputPortOffset, MW_outputPortWidth);
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
      memcpy((uint8_T*)&LOG_DATI_GPS_BMP_07_15_v2_B.ByteUnpack_o2[0], (uint8_T*)
             &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder[0] +
             MW_inputPortOffset, MW_outputPortWidth);
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
      memcpy((uint8_T*)&LOG_DATI_GPS_BMP_07_15_v2_B.ByteUnpack_o3, (uint8_T*)
             &LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder[0] +
             MW_inputPortOffset, MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<Root>/Byte Reversal' */

  /* ReverseEndian: <Root>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &LOG_DATI_GPS_BMP_07_15_v2_B.ByteUnpack_o2[0];
    real32_T *y0 = &LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  for (i = 0; i < 6; i++) {
    tmp = (real32_T)floor(LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[i]);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0);
    }

    rtb_DataTypeConversion_j[i] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  tmp = (real32_T)floor((real32_T)LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_oo
                        [0]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion_j[6] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  tmp = (real32_T)floor((real32_T)LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_oo
                        [1]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion_j[7] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  tmp = (real32_T)floor((real32_T)LOG_DATI_GPS_BMP_07_15_v2_P.Constant_Value_oo
                        [2]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion_j[8] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* RateTransition generated from: '<S2>/S-Function' */
  for (i = 0; i < 9; i++) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport14_Buffe[i] =
      rtb_DataTypeConversion_j[i];
  }

  /* End of RateTransition generated from: '<S2>/S-Function' */

  /* RateTransition generated from: '<S2>/S-Function' */
  LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[0] =
    LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[6];
  LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[3] =
    LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[3];
  LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[1] =
    LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[7];
  LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[4] =
    LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[4];
  LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[2] =
    LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[8];
  LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[5] =
    LOG_DATI_GPS_BMP_07_15_v2_B.ByteReversal[5];

  /* Update for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <Root>/S-Function Builder */
  Mti_Update_wrapper(&LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder[0],
                     &LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE_o);
}

/* Model initialize function */
void LOG_DATI_GPS_BMP_07_15_v2_initialize(void)
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
    for (i = 0; i < 9; i++) {
      /* Start for RateTransition generated from: '<S2>/S-Function' */
      LOG_DATI_GPS_BMP_07_15_v2_B.TmpRTBAtSFunctionInport14[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.TmpRTBAtSFunctionInport14_Initi;
    }

    for (i = 0; i < 6; i++) {
      /* Start for RateTransition generated from: '<S2>/S-Function' */
      LOG_DATI_GPS_BMP_07_15_v2_B.TmpRTBAtSFunctionInport15[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.TmpRTBAtSFunctionInport15_Initi;
    }

    /* Start for S-Function (Mti): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    Mti_Start_wrapper(&LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE_o);

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&LOG_DATI_GPS_BMP_07_15_v2_DW.Memory4_PreviousInput[0],
           &LOG_DATI_GPS_BMP_07_15_v2_P.Memory4_InitialCondition[0], 300U *
           sizeof(uint8_T));

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory5_PreviousInput[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[0] =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory1_InitialCondition_g;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput_e[1] =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[0] =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition_bh;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[1] =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition_bh;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[2] =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition_bh;
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_i[3] =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition_bh;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory3_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_o[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition_b;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput_k[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.Memory2_InitialCondition_c[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S22>/Rate Transition' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.RateTransition_Buffer0 =
      LOG_DATI_GPS_BMP_07_15_v2_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S22>/Switch' incorporates:
     *  Memory: '<S22>/Memory1'
     */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory1_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S22>/Add' incorporates:
     *  Memory: '<S22>/Memory'
     */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S2>/S-Function' */
    for (i = 0; i < 9; i++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport14_Buffe[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.TmpRTBAtSFunctionInport14_Initi;
    }

    /* End of InitializeConditions for RateTransition generated from: '<S2>/S-Function' */

    /* InitializeConditions for RateTransition generated from: '<S2>/S-Function' */
    for (i = 0; i < 6; i++) {
      LOG_DATI_GPS_BMP_07_15_v2_DW.TmpRTBAtSFunctionInport15_Buffe[i] =
        LOG_DATI_GPS_BMP_07_15_v2_P.TmpRTBAtSFunctionInport15_Initi;
    }

    /* End of InitializeConditions for RateTransition generated from: '<S2>/S-Function' */

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.UnitDelay_DSTATE =
      LOG_DATI_GPS_BMP_07_15_v2_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S29>/Delay Input2'
     *
     * Block description for '<S29>/Delay Input2':
     *
     *  Store in Global RAM
     */
    LOG_DATI_GPS_BMP_07_15_v2_DW.DelayInput2_DSTATE =
      LOG_DATI_GPS_BMP_07_15_v2_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory_PreviousInput_m =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory_InitialCondition_k;

    /* InitializeConditions for Sum: '<S22>/Add2' incorporates:
     *  Memory: '<S22>/Memory2'
     */
    LOG_DATI_GPS_BMP_07_15_v2_DW.Memory2_PreviousInput =
      LOG_DATI_GPS_BMP_07_15_v2_P.Memory2_InitialCondition;

    /* InitializeConditions for S-Function (Mti): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          LOG_DATI_GPS_BMP_07_15_v2_DW.SFunctionBuilder_DSTATE_o = initVector[0];
        }
      }
    }

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&LOG_DATI_GPS_BMP_07_15_v2_DW.riferimenti[0], &tmp[0], sizeof
           (real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
     *  SubSystem: '<S17>/sendbyte'
     */
    /* Start for MATLABSystem: '<S18>/Serial Transmit' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.Protocol =
      LOG_DATI_GPS_BMP_07_15_v2_P.SerialTransmit_Protocol;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.port = 2.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.dataSizeInBytes = 1.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.dataType = 0.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.sendModeEnum = 0.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(LOG_DATI_GPS_BMP_07_15_v2_DW.obj.port);
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
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S18>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S30>/I2C Read12' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.isInitialized = 0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.SampleTime =
      LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    obj = &LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.isSetupComplete = false;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_15_v2_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (LOG_DATI_GPS_BMP_07_15_v2_B.i2cname, 0);
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S30>/I2C Read1' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.matlabCodegenIsDeleted = true;
    obj = &LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.isInitialized = 0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.SampleTime =
      LOG_DATI_GPS_BMP_07_15_v2_P.t_AP;
    obj = &LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.isSetupComplete = false;
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_15_v2_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (LOG_DATI_GPS_BMP_07_15_v2_B.i2cname, 0);
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.BusSpeed = 100000U;
    varargin_1 = LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S30>/S-Function Builder' incorporates:
     *  Outport: '<S30>/T'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder_o1 =
      LOG_DATI_GPS_BMP_07_15_v2_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S30>/S-Function Builder1' incorporates:
     *  Outport: '<S30>/p'
     */
    LOG_DATI_GPS_BMP_07_15_v2_B.SFunctionBuilder1 =
      LOG_DATI_GPS_BMP_07_15_v2_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    LOG_DATI_GPS_BMP_07_15_v2_DW.P_ref = 101325.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.rl_up = 300.0;
    LOG_DATI_GPS_BMP_07_15_v2_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init
      (&LOG_DATI_GPS_BMP_07_15_v2_B.One_time_initialization,
       &LOG_DATI_GPS_BMP_07_15_v2_DW.One_time_initialization,
       &LOG_DATI_GPS_BMP_07_15_v2_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */
  }
}

/* Model terminate function */
void LOG_DATI_GPS_BMP_07_15_v2_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term
    (&LOG_DATI_GPS_BMP_07_15_v2_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S30>/I2C Read12' */
  obj = &LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f;
  if (!LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.isInitialized == 1) &&
        LOG_DATI_GPS_BMP_07_15_v2_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S30>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S30>/I2C Read1' */
  obj = &LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k;
  if (!LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.isInitialized == 1) &&
        LOG_DATI_GPS_BMP_07_15_v2_DW.obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S30>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S17>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S18>/Serial Transmit' */
  if (!LOG_DATI_GPS_BMP_07_15_v2_DW.obj.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_15_v2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S18>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
