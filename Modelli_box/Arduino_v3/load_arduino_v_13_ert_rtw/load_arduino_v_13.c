/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_13.c
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

#include "load_arduino_v_13.h"
#include "load_arduino_v_13_private.h"

/* Named constants for Chart: '<S42>/SELEZIONE MODALITA\'  HOLD//SELECT' */
#define load_arduino_v_13_IN_Hold      ((uint8_T)1U)
#define load_arduino_v_13_IN_Select    ((uint8_T)2U)

/* Named constants for Chart: '<S40>/ STATI' */
#define load__IN_ATTERRAGGIO_AUTOMATICO ((uint8_T)1U)
#define load_ardu_IN_DECOLLO_AUTOMATICO ((uint8_T)2U)
#define load_ardui_IN_Intervento_Pilota ((uint8_T)3U)
#define load_arduino_v_13_IN_AUTOMATICA ((uint8_T)1U)
#define load_arduino_v_13_IN_Go_Home   ((uint8_T)2U)
#define load_arduino_v_13_IN_MANUALE   ((uint8_T)4U)
#define load_arduino_v_13_IN_Safe      ((uint8_T)5U)
#define load_arduino_v_13_IN_Stand_By  ((uint8_T)6U)
#define load_arduino_v_13_IN_TEST      ((uint8_T)3U)
#define load_arduino_v_13_IN_VETTORIALE ((uint8_T)4U)
#define load_arduino_v_13_IN_WAYPOINT  ((uint8_T)5U)

/* Named constants for Chart: '<S41>/Chart' */
#define load_arduino_v_13_IN_GoHome    ((uint8_T)3U)
#define load_arduino_v_13_IN_In        ((uint8_T)4U)
#define load_arduino_v_13_IN_Vettoriale ((uint8_T)5U)
#define load_arduino_v_13_IN_Waypoint  ((uint8_T)6U)
#define load_arduino_v_1_IN_AutoLanding ((uint8_T)1U)
#define load_arduino_v_1_IN_AutoTakeoff ((uint8_T)2U)

/* Named constants for Chart: '<S780>/Chart1' */
#define load_arduino_v_13_IN_Fase_0_ATO ((uint8_T)1U)
#define load_arduino_v_13_IN_Fase_1_ATO ((uint8_T)2U)
#define load_arduino_v_13_IN_Fase_2_ATO ((uint8_T)3U)
#define load_arduino_v_13_IN_Fase_3_ATO ((uint8_T)4U)
#define load_arduino_v_13_IN_Fase_4_ATO ((uint8_T)5U)

/* Named constants for Chart: '<S782>/Chart1' */
#define load_arduino_v_13_IN_Abort     ((uint8_T)1U)
#define load_arduino_v_13_IN_Allignment ((uint8_T)2U)
#define load_arduino_v_13_IN_Approach  ((uint8_T)4U)
#define load_arduino_v_13_IN_Flare     ((uint8_T)5U)
#define load_arduino_v_1_IN_Allignment1 ((uint8_T)3U)

const uint16_T load_arduino_v_13_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_load_arduino_v_13_T load_arduino_v_13_B;

/* Block states (default storage) */
DW_load_arduino_v_13_T load_arduino_v_13_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_load_arduino_v_13_T load_arduino_v_13_PrevZCX;

/* Real-time model */
RT_MODEL_load_arduino_v_13_T load_arduino_v_13_M_;
RT_MODEL_load_arduino_v_13_T *const load_arduino_v_13_M = &load_arduino_v_13_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_int_b_T *l_arduinoI2CRead_arduinoI2CRead
  (codertarget_arduinobase_int_b_T *obj);
static codertarget_arduinobase_int_m_T *arduinoI2CWrite_arduinoI2CWrite
  (codertarget_arduinobase_int_m_T *obj);
static void load_arduino_SystemCore_release(const
  codertarget_arduinobase_int_b_T *obj);
static void load_arduino__SystemCore_delete(const
  codertarget_arduinobase_int_b_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj);
static void load_ardui_SystemCore_release_h(const
  codertarget_arduinobase_int_m_T *obj);
static void load_arduin_SystemCore_delete_j(const
  codertarget_arduinobase_int_m_T *obj);
static void matlabCodegenHandle_matlabCod_j(codertarget_arduinobase_int_m_T *obj);

/* Forward declaration for local functions */
static void load_arduino_v_13_find_254(const uint8_T pack[100], real_T position
  [3], real_T *counter);
static boolean_T load_arduino_v_13_ifWhileCond(const boolean_T x[100]);
static void load_arduino_v_13_AUTOMATICA(const real_T DataTypeConversion5[4],
  const real_T Gain4[2], const real_T *Product1, real_T *Go_Home, real_T *test);
static void load_arduino_v_13_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void load_arduino_v_13_AutoLanding(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void load_arduino_v_13_invNxN(const real_T x[16], real_T y[16]);
static boolean_T load_arduino_v_13_ifWhileCond_f(const boolean_T x[5]);
static boolean_T load_arduino_v_13_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T load_arduino_v_13_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static boolean_T load_arduino_v_13_copysign(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k);
static void load_arduino_v_13_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
  boolean_T *success);
static creal_T load_arduino_v_13_str2double(const char_T s[2]);
static boolean_T load_arduino_v_13_copysign_f(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n);
static void load_arduino_v_13_readNonFinite(const char_T s_data[], int32_T *k,
  int32_T n, boolean_T *b_finite, real_T *fv);
static boolean_T load_arduino_v_13_copydigits_c(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static boolean_T load_arduino_v_1_copyexponent_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n);
static void load_arduino_v_13_readfloat_a(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *success);
static creal_T load_arduino_v_13_str2double_g(const char_T s_data[], const
  int32_T s_size[2]);
static void load_arduino_v__readNonFinite_p(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T load_arduino_v_13_copydigits_cm(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T load_arduino_v__copyexponent_ok(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static boolean_T load_arduino_v_13_copysign_fr(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k);
static void load_arduino_v_13_readfloat_a1(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
  boolean_T *success);
static creal_T load_arduino_v_13_str2double_gv(const char_T s[3]);
static boolean_T load_arduino_v_1_copydigits_cmm(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static creal_T load_arduino_v_1_str2double_gv1(char_T s);
static real_T load_arduino_v_13_hex2dec(const char_T s[2]);
static void load_ardui_SystemCore_release_j(const
  codertarget_arduinobase_int_b_T *obj);
static void load_ard_SystemCore_delete_js1p(const
  codertarget_arduinobase_int_b_T *obj);
static void matlabCodegenHandle_matlab_js1p(codertarget_arduinobase_int_b_T *obj);
static void matlabCodegenHandle_matlabCo_js(codertarget_arduinobase_block_T *obj);
static codertarget_arduinobase_int_b_T *arduinoI2CRead_arduinoI2CRead_j
  (codertarget_arduinobase_int_b_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void load_arduino_v_13_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(load_arduino_v_13_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(load_arduino_v_13_M, 2));
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
  (load_arduino_v_13_M->Timing.TaskCounters.TID[1])++;
  if ((load_arduino_v_13_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    load_arduino_v_13_M->Timing.TaskCounters.TID[1] = 0;
  }

  (load_arduino_v_13_M->Timing.TaskCounters.TID[2])++;
  if ((load_arduino_v_13_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.1s, 0.0s] */
    load_arduino_v_13_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S750>/Enabled Subsystem'
 *    '<S751>/Enabled Subsystem'
 */
void load__EnabledSubsystem_Init(real_T *rty_u0, P_EnabledSubsystem_load_ardui_T
  *localP)
{
  /* SystemInitialize for Outport: '<S759>/1//0' */
  *rty_u0 = localP->u0_Y0;
}

/*
 * Output and update for enable system:
 *    '<S750>/Enabled Subsystem'
 *    '<S751>/Enabled Subsystem'
 */
void load_ardui_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0, P_EnabledSubsystem_load_ardui_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S750>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S759>/Enable'
   */
  if (rtu_Enable > 0) {
    /* Switch: '<S759>/Switch' incorporates:
     *  Constant: '<S759>/Constant1'
     *  Constant: '<S759>/Constant2'
     */
    if (rtu_Time > localP->Switch_Threshold) {
      *rty_u0 = localP->Constant1_Value;
    } else {
      *rty_u0 = localP->Constant2_Value;
    }

    /* End of Switch: '<S759>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S750>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S750>/Resettable Subsystem'
 *    '<S751>/Resettable Subsystem'
 */
void lo_ResettableSubsystem_Init(DW_ResettableSubsystem_load_a_T *localDW,
  P_ResettableSubsystem_load_ar_T *localP)
{
  /* InitializeConditions for Memory: '<S761>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * System reset for atomic system:
 *    '<S750>/Resettable Subsystem'
 *    '<S751>/Resettable Subsystem'
 */
void l_ResettableSubsystem_Reset(DW_ResettableSubsystem_load_a_T *localDW,
  P_ResettableSubsystem_load_ar_T *localP)
{
  /* InitializeConditions for Memory: '<S761>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S750>/Resettable Subsystem'
 *    '<S751>/Resettable Subsystem'
 */
real_T load_ar_ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_load_a_T *localDW, P_ResettableSubsystem_load_ar_T
  *localP, ZCE_ResettableSubsystem_load__T *localZCE)
{
  real_T rty_Time_0;

  /* Outputs for Resettable SubSystem: '<S750>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S760>/Reset'
   */
  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_f != POS_ZCSIG))
  {
    l_ResettableSubsystem_Reset(localDW, localP);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_f = (ZCSigState)(rtu_Reset > 0);

  /* Sum: '<S761>/Sum' incorporates:
   *  Constant: '<S761>/Constant4'
   *  Memory: '<S761>/Memory'
   */
  rty_Time_0 = load_arduino_v_13_P.t_AP + localDW->Memory_PreviousInput;

  /* Update for Memory: '<S761>/Memory' */
  localDW->Memory_PreviousInput = rty_Time_0;

  /* End of Outputs for SubSystem: '<S750>/Resettable Subsystem' */
  return rty_Time_0;
}

static codertarget_arduinobase_int_b_T *l_arduinoI2CRead_arduinoI2CRead
  (codertarget_arduinobase_int_b_T *obj)
{
  codertarget_arduinobase_int_b_T *b_obj;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static codertarget_arduinobase_int_m_T *arduinoI2CWrite_arduinoI2CWrite
  (codertarget_arduinobase_int_m_T *obj)
{
  codertarget_arduinobase_int_m_T *b_obj;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void load_arduino_SystemCore_release(const
  codertarget_arduinobase_int_b_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void load_arduino__SystemCore_delete(const
  codertarget_arduinobase_int_b_T *obj)
{
  load_arduino_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    load_arduino__SystemCore_delete(obj);
  }
}

static void load_ardui_SystemCore_release_h(const
  codertarget_arduinobase_int_m_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void load_arduin_SystemCore_delete_j(const
  codertarget_arduinobase_int_m_T *obj)
{
  load_ardui_SystemCore_release_h(obj);
}

static void matlabCodegenHandle_matlabCod_j(codertarget_arduinobase_int_m_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    load_arduin_SystemCore_delete_j(obj);
  }
}

/* System initialize for enable system: '<S963>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_loa_T *localB,
  P_One_time_initialization_loa_T *localP)
{
  int32_T i;

  /* SystemInitialize for Outport: '<S971>/dig_T1' */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_T2' */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_T3' */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p1' */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p2' */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p3' */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p4' */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p5' */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p6' */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p7' */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p8' */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for Outport: '<S971>/dig_p9' */
  localB->I2CRead11 = localP->dig_p9_Y0;

  /* SystemInitialize for Outport: '<S971>/pwm_max_min' */
  for (i = 0; i < 8; i++) {
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }

  /* End of SystemInitialize for Outport: '<S971>/pwm_max_min' */
}

/* Start for enable system: '<S963>/One_time_initialization' */
void One_time_initializati_Start(DW_One_time_initialization_lo_T *localDW,
  P_One_time_initialization_loa_T *localP)
{
  codertarget_arduinobase_int_b_T *obj;
  uint32_T i2cname;
  codertarget_arduinobase_int_m_T *obj_0;

  /* Start for MATLABSystem: '<S971>/I2C Read' */
  localDW->obj.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj);
  localDW->obj.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj.MW_I2C_HANDLE, localDW->obj.BusSpeed);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read1' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_o);
  localDW->obj_o.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_o.MW_I2C_HANDLE, localDW->obj_o.BusSpeed);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read2' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_d);
  localDW->obj_d.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_d.MW_I2C_HANDLE, localDW->obj_d.BusSpeed);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read3' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_k);
  localDW->obj_k.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_k.MW_I2C_HANDLE, localDW->obj_k.BusSpeed);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read4' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_c);
  localDW->obj_c.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_c.MW_I2C_HANDLE, localDW->obj_c.BusSpeed);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read5' */
  localDW->obj_kn.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_kn);
  localDW->obj_kn.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_kn;
  localDW->obj_kn.isSetupComplete = false;
  localDW->obj_kn.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_kn.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_kn.MW_I2C_HANDLE, localDW->obj_kn.BusSpeed);
  localDW->obj_kn.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read6' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_b);
  localDW->obj_b.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_b.MW_I2C_HANDLE, localDW->obj_b.BusSpeed);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read7' */
  localDW->obj_cn.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_cn);
  localDW->obj_cn.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_cn;
  localDW->obj_cn.isSetupComplete = false;
  localDW->obj_cn.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_cn.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_cn.MW_I2C_HANDLE, localDW->obj_cn.BusSpeed);
  localDW->obj_cn.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read8' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_i);
  localDW->obj_i.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_i.MW_I2C_HANDLE, localDW->obj_i.BusSpeed);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read9' */
  localDW->obj_h.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_h);
  localDW->obj_h.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_h;
  localDW->obj_h.isSetupComplete = false;
  localDW->obj_h.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_h.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_h.MW_I2C_HANDLE, localDW->obj_h.BusSpeed);
  localDW->obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read10' */
  localDW->obj_d0.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_d0);
  localDW->obj_d0.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_d0;
  localDW->obj_d0.isSetupComplete = false;
  localDW->obj_d0.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d0.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_d0.MW_I2C_HANDLE, localDW->obj_d0.BusSpeed);
  localDW->obj_d0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read11' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_l);
  localDW->obj_l.SampleTime = load_arduino_v_13_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_l.MW_I2C_HANDLE, localDW->obj_l.BusSpeed);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Write1' */
  localDW->obj_j.matlabCodegenIsDeleted = true;
  arduinoI2CWrite_arduinoI2CWrite(&localDW->obj_j);
  obj_0 = &localDW->obj_j;
  localDW->obj_j.isSetupComplete = false;
  localDW->obj_j.isInitialized = 1;
  i2cname = 0;
  obj_0->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_j.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_j.MW_I2C_HANDLE, localDW->obj_j.BusSpeed);
  localDW->obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Write2' */
  localDW->obj_in.matlabCodegenIsDeleted = true;
  arduinoI2CWrite_arduinoI2CWrite(&localDW->obj_in);
  obj_0 = &localDW->obj_in;
  localDW->obj_in.isSetupComplete = false;
  localDW->obj_in.isInitialized = 1;
  i2cname = 0;
  obj_0->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_in.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_in.MW_I2C_HANDLE, localDW->obj_in.BusSpeed);
  localDW->obj_in.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Write3' */
  localDW->obj_d01.matlabCodegenIsDeleted = true;
  arduinoI2CWrite_arduinoI2CWrite(&localDW->obj_d01);
  obj_0 = &localDW->obj_d01;
  localDW->obj_d01.isSetupComplete = false;
  localDW->obj_d01.isInitialized = 1;
  i2cname = 0;
  obj_0->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d01.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_d01.MW_I2C_HANDLE, localDW->obj_d01.BusSpeed);
  localDW->obj_d01.isSetupComplete = true;

  /* Start for MATLABSystem: '<S971>/I2C Read12' */
  localDW->obj_ir.matlabCodegenIsDeleted = true;
  l_arduinoI2CRead_arduinoI2CRead(&localDW->obj_ir);
  localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_ir;
  localDW->obj_ir.isSetupComplete = false;
  localDW->obj_ir.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ir.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj_ir.MW_I2C_HANDLE, localDW->obj_ir.BusSpeed);
  localDW->obj_ir.isSetupComplete = true;
}

/* Output and update for enable system: '<S963>/One_time_initialization' */
void loa_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_loa_T *localB, DW_One_time_initialization_lo_T
  *localDW, P_One_time_initialization_loa_T *localP)
{
  uint8_T SwappedDataBytes;
  uint8_T status;
  uint8_T output_raw[2];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw_0[16];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];

  /* Outputs for Enabled SubSystem: '<S963>/One_time_initialization' incorporates:
   *  EnablePort: '<S971>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion: '<S971>/TmpSignal ConversionAtI2C Write3Inport1' incorporates:
     *  ArithShift: '<S971>/Shift Arithmetic1'
     *  Constant: '<S971>/registro memoria2 '
     *  DataTypeConversion: '<S971>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S971>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S971>/I2C Read' */
    if (localDW->obj.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj.MW_I2C_HANDLE, 118U, output_raw, 2U, false,
                        true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S971>/I2C Read' */

    /* MATLABSystem: '<S971>/I2C Read1' */
    if (localDW->obj_o.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_o.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_o.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_o.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read1' */

    /* MATLABSystem: '<S971>/I2C Read2' */
    if (localDW->obj_d.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_d.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_d.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_d.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read2' */

    /* MATLABSystem: '<S971>/I2C Read3' */
    if (localDW->obj_k.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_k.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_k.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_k.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S971>/I2C Read3' */

    /* MATLABSystem: '<S971>/I2C Read4' */
    if (localDW->obj_c.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_c.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_c.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_c.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read4' */

    /* MATLABSystem: '<S971>/I2C Read5' */
    if (localDW->obj_kn.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_kn.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_kn.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_kn.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read5' */

    /* MATLABSystem: '<S971>/I2C Read6' */
    if (localDW->obj_b.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_b.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_b.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_b.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read6' */

    /* MATLABSystem: '<S971>/I2C Read7' */
    if (localDW->obj_cn.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_cn.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_cn.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_cn.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read7' */

    /* MATLABSystem: '<S971>/I2C Read8' */
    if (localDW->obj_i.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_i.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_i.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_i.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read8' */

    /* MATLABSystem: '<S971>/I2C Read9' */
    if (localDW->obj_h.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_h.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 154U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_h.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_h.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead9, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read9' */

    /* MATLABSystem: '<S971>/I2C Read10' */
    if (localDW->obj_d0.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_d0.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_d0.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_d0.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read10' */

    /* MATLABSystem: '<S971>/I2C Read11' */
    if (localDW->obj_l.SampleTime != load_arduino_v_13_P.t_AP) {
      localDW->obj_l.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.MW_I2C_HANDLE, 118U, output_raw, 2U,
                        false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S971>/I2C Read11' */

    /* MATLABSystem: '<S971>/I2C Write1' incorporates:
     *  Constant: '<S971>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_j.MW_I2C_HANDLE, 118U, SwappedDataBytes_0,
                       2U, false, false);

    /* MATLABSystem: '<S971>/I2C Write2' incorporates:
     *  Constant: '<S971>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_in.MW_I2C_HANDLE, 118U, SwappedDataBytes_0,
                       2U, false, false);

    /* MATLABSystem: '<S971>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_d01.MW_I2C_HANDLE, 80U,
                       rtb_TmpSignalConversionAtI2CWri, 2U, false, false);

    /* MATLABSystem: '<S971>/I2C Read12' */
    if (localDW->obj_ir.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_ir.MW_I2C_HANDLE, 80U, output_raw_0, 16U,
                      false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S971>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S971>/Byte Unpack' */

    /* Unpack: <S971>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S963>/One_time_initialization' */
}

/* Termination for enable system: '<S963>/One_time_initialization' */
void One_time_initializatio_Term(DW_One_time_initialization_lo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S971>/I2C Read' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj);

  /* Terminate for MATLABSystem: '<S971>/I2C Read1' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_o);

  /* Terminate for MATLABSystem: '<S971>/I2C Read2' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_d);

  /* Terminate for MATLABSystem: '<S971>/I2C Read3' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_k);

  /* Terminate for MATLABSystem: '<S971>/I2C Read4' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_c);

  /* Terminate for MATLABSystem: '<S971>/I2C Read5' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_kn);

  /* Terminate for MATLABSystem: '<S971>/I2C Read6' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_b);

  /* Terminate for MATLABSystem: '<S971>/I2C Read7' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_cn);

  /* Terminate for MATLABSystem: '<S971>/I2C Read8' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_i);

  /* Terminate for MATLABSystem: '<S971>/I2C Read9' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_h);

  /* Terminate for MATLABSystem: '<S971>/I2C Read10' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_d0);

  /* Terminate for MATLABSystem: '<S971>/I2C Read11' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_l);

  /* Terminate for MATLABSystem: '<S971>/I2C Write1' */
  matlabCodegenHandle_matlabCod_j(&localDW->obj_j);

  /* Terminate for MATLABSystem: '<S971>/I2C Write2' */
  matlabCodegenHandle_matlabCod_j(&localDW->obj_in);

  /* Terminate for MATLABSystem: '<S971>/I2C Write3' */
  matlabCodegenHandle_matlabCod_j(&localDW->obj_d01);

  /* Terminate for MATLABSystem: '<S971>/I2C Read12' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj_ir);
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void load_arduino_v_13_find_254(const uint8_T pack[100], real_T position
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
      position[(int32_T)*counter - 1] = 1.0 + (real_T)i;
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
static boolean_T load_arduino_v_13_ifWhileCond(const boolean_T x[100])
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
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

/* Function for Chart: '<S40>/ STATI' */
static void load_arduino_v_13_AUTOMATICA(const real_T DataTypeConversion5[4],
  const real_T Gain4[2], const real_T *Product1, real_T *Go_Home, real_T *test)
{
  /* Constant: '<S40>/Constant2' */
  if (load_arduino_v_13_P.Constant2_Value_k == 1.0) {
    load_arduino_v_13_DW.is_AUTOMATICA = 0;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
      load_ardui_IN_Intervento_Pilota;
  } else if (load_arduino_v_13_B.Switch_n == 1.0) {
    load_arduino_v_13_DW.is_AUTOMATICA = 0;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 = load_arduino_v_13_IN_Safe;
  } else if (*Go_Home == 1.0) {
    load_arduino_v_13_DW.is_AUTOMATICA = 0;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 = load_arduino_v_13_IN_Go_Home;
  } else if (load_arduino_v_13_B.AP_int[1] == 0) {
    load_arduino_v_13_DW.is_AUTOMATICA = 0;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
      load_arduino_v_13_IN_Stand_By;
  } else if (load_arduino_v_13_B.AP_int[0] == 1) {
    load_arduino_v_13_DW.is_AUTOMATICA = 0;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 = load_arduino_v_13_IN_MANUALE;
  } else {
    switch (load_arduino_v_13_DW.is_AUTOMATICA) {
     case load__IN_ATTERRAGGIO_AUTOMATICO:
      if ((load_arduino_v_13_B.AP_int[8] == 0) && (DataTypeConversion5[2] > 20.0)
          && (load_arduino_v_13_B.AP_int[6] == 1)) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_WAYPOINT;
      } else if ((load_arduino_v_13_B.AP_int[8] == 0) && (DataTypeConversion5[2]
                  > 20.0)) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_VETTORIALE;
      } else if ((load_arduino_v_13_B.AP_int[7] == 1) &&
                 (load_arduino_v_13_B.AP_int[8] == 0) && (DataTypeConversion5[2]
                  < 1.0) && (Gain4[0] < 1.0)) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_ardu_IN_DECOLLO_AUTOMATICO;
      } else {
        load_arduino_v_13_B.modo = 4.0;
        load_arduino_v_13_B.switch_manetta = 1.0;
        load_arduino_v_13_B.switch_equilibratore = 1.0;
        load_arduino_v_13_B.switch_alettoni = 1.0;
        load_arduino_v_13_B.switch_timone = 1.0;
      }
      break;

     case load_ardu_IN_DECOLLO_AUTOMATICO:
      if ((load_arduino_v_13_B.AP_int[7] == 0) && (*Product1 >= 1.0) &&
          ((load_arduino_v_13_B.AP_int[3] == 1) || (load_arduino_v_13_B.AP_int[4]
            == 1) || (load_arduino_v_13_B.AP_int[2] == 1))) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_VETTORIALE;
      } else if ((load_arduino_v_13_B.AP_int[6] == 1) && (DataTypeConversion5[2]
                  > 30.0)) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_WAYPOINT;
      } else {
        load_arduino_v_13_B.modo = 3.0;
        load_arduino_v_13_B.switch_manetta = 1.0;
        load_arduino_v_13_B.switch_equilibratore = 1.0;
        load_arduino_v_13_B.switch_alettoni = 1.0;
        load_arduino_v_13_B.switch_timone = 1.0;
      }
      break;

     case load_arduino_v_13_IN_TEST:
      if (*test == 0.0) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_VETTORIALE;
      } else {
        load_arduino_v_13_B.switch_manetta = 0.0;
        load_arduino_v_13_B.switch_equilibratore = 0.0;
        load_arduino_v_13_B.switch_alettoni = 0.0;
        load_arduino_v_13_B.switch_timone = 0.0;
      }
      break;

     case load_arduino_v_13_IN_VETTORIALE:
      if (*test == 1.0) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_TEST;
      } else if ((load_arduino_v_13_B.AP_int[7] == 1) && (Gain4[0] < 1.0)) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_ardu_IN_DECOLLO_AUTOMATICO;
      } else if (load_arduino_v_13_B.AP_int[8] == 1) {
        load_arduino_v_13_DW.is_AUTOMATICA = load__IN_ATTERRAGGIO_AUTOMATICO;
      } else if (load_arduino_v_13_B.AP_int[6] == 1) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_WAYPOINT;
      } else {
        load_arduino_v_13_B.modo = 2.0;
        load_arduino_v_13_B.switch_manetta = 1.0;
        load_arduino_v_13_B.switch_equilibratore = 1.0;
        load_arduino_v_13_B.switch_alettoni = 1.0;
        load_arduino_v_13_B.switch_timone = 1.0;
      }
      break;

     default:
      if ((load_arduino_v_13_B.AP_int[6] == 0) && ((load_arduino_v_13_B.AP_int[3]
            == 1) || (load_arduino_v_13_B.AP_int[4] == 1) ||
           (load_arduino_v_13_B.AP_int[2] == 1) || (load_arduino_v_13_B.AP_int[7]
            == 1))) {
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_VETTORIALE;
      } else if (load_arduino_v_13_B.AP_int[8] == 1) {
        load_arduino_v_13_DW.is_AUTOMATICA = load__IN_ATTERRAGGIO_AUTOMATICO;
      } else {
        load_arduino_v_13_B.modo = 1.0;
        load_arduino_v_13_B.switch_manetta = 1.0;
        load_arduino_v_13_B.switch_equilibratore = 1.0;
        load_arduino_v_13_B.switch_alettoni = 1.0;
        load_arduino_v_13_B.switch_timone = 1.0;
      }
      break;
    }
  }

  /* End of Constant: '<S40>/Constant2' */
}

/* Function for Chart: '<S41>/Chart' */
static void load_arduino_v_13_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (load_arduino_v_13_B.modo == 5.0)) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_13_B.modo == 2.0)) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
      load_arduino_v_13_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_13_B.modo == 4.0)) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
      load_arduino_v_1_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else {
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  }
}

/* Function for Chart: '<S41>/Chart' */
static void load_arduino_v_13_AutoLanding(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if (!*Ap_sel) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_13_B.modo == 2.0)) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
      load_arduino_v_13_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_13_B.modo == 1.0)) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
      load_arduino_v_13_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_13_B.modo == 5.0)) {
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else {
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
    if (u1 != 0.0) {
      y = (rtNaN);
    }
  } else if (u0 == 0.0) {
    y = u1 * 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = u1 * 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S793>/MATLAB Function' */
static void load_arduino_v_13_invNxN(const real_T x[16], real_T y[16])
{
  int32_T pipk;
  for (load_arduino_v_13_B.b_j = 0; load_arduino_v_13_B.b_j < 16;
       load_arduino_v_13_B.b_j++) {
    y[load_arduino_v_13_B.b_j] = 0.0;
    load_arduino_v_13_B.A[load_arduino_v_13_B.b_j] = x[load_arduino_v_13_B.b_j];
  }

  load_arduino_v_13_B.ipiv[0] = 1;
  load_arduino_v_13_B.ipiv[1] = 2;
  load_arduino_v_13_B.ipiv[2] = 3;
  for (load_arduino_v_13_B.b_j = 0; load_arduino_v_13_B.b_j < 3;
       load_arduino_v_13_B.b_j++) {
    pipk = load_arduino_v_13_B.b_j * 5;
    load_arduino_v_13_B.b_ix = 0;
    load_arduino_v_13_B.ix = pipk;
    load_arduino_v_13_B.smax = fabs(load_arduino_v_13_B.A[pipk]);
    load_arduino_v_13_B.b_k = 2;
    while (load_arduino_v_13_B.b_k <= 4 - load_arduino_v_13_B.b_j) {
      load_arduino_v_13_B.ix++;
      load_arduino_v_13_B.s = fabs(load_arduino_v_13_B.A[load_arduino_v_13_B.ix]);
      if (load_arduino_v_13_B.s > load_arduino_v_13_B.smax) {
        load_arduino_v_13_B.b_ix = load_arduino_v_13_B.b_k - 1;
        load_arduino_v_13_B.smax = load_arduino_v_13_B.s;
      }

      load_arduino_v_13_B.b_k++;
    }

    if (load_arduino_v_13_B.A[pipk + load_arduino_v_13_B.b_ix] != 0.0) {
      if (load_arduino_v_13_B.b_ix != 0) {
        load_arduino_v_13_B.ix = load_arduino_v_13_B.b_j +
          load_arduino_v_13_B.b_ix;
        load_arduino_v_13_B.ipiv[load_arduino_v_13_B.b_j] = (int8_T)
          (load_arduino_v_13_B.ix + 1);
        load_arduino_v_13_B.smax = load_arduino_v_13_B.A[load_arduino_v_13_B.b_j];
        load_arduino_v_13_B.A[load_arduino_v_13_B.b_j] =
          load_arduino_v_13_B.A[load_arduino_v_13_B.ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.ix] = load_arduino_v_13_B.smax;
        load_arduino_v_13_B.b_ix = load_arduino_v_13_B.b_j + 4;
        load_arduino_v_13_B.ix += 4;
        load_arduino_v_13_B.smax =
          load_arduino_v_13_B.A[load_arduino_v_13_B.b_ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.b_ix] =
          load_arduino_v_13_B.A[load_arduino_v_13_B.ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.ix] = load_arduino_v_13_B.smax;
        load_arduino_v_13_B.b_ix += 4;
        load_arduino_v_13_B.ix += 4;
        load_arduino_v_13_B.smax =
          load_arduino_v_13_B.A[load_arduino_v_13_B.b_ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.b_ix] =
          load_arduino_v_13_B.A[load_arduino_v_13_B.ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.ix] = load_arduino_v_13_B.smax;
        load_arduino_v_13_B.b_ix += 4;
        load_arduino_v_13_B.ix += 4;
        load_arduino_v_13_B.smax =
          load_arduino_v_13_B.A[load_arduino_v_13_B.b_ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.b_ix] =
          load_arduino_v_13_B.A[load_arduino_v_13_B.ix];
        load_arduino_v_13_B.A[load_arduino_v_13_B.ix] = load_arduino_v_13_B.smax;
      }

      load_arduino_v_13_B.b_ix = (pipk - load_arduino_v_13_B.b_j) + 4;
      load_arduino_v_13_B.ix = pipk + 1;
      while (load_arduino_v_13_B.ix + 1 <= load_arduino_v_13_B.b_ix) {
        load_arduino_v_13_B.A[load_arduino_v_13_B.ix] /=
          load_arduino_v_13_B.A[pipk];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.b_ix = pipk;
    load_arduino_v_13_B.ix = pipk + 4;
    load_arduino_v_13_B.b_k = 0;
    while (load_arduino_v_13_B.b_k <= 2 - load_arduino_v_13_B.b_j) {
      if (load_arduino_v_13_B.A[load_arduino_v_13_B.ix] != 0.0) {
        load_arduino_v_13_B.smax = -load_arduino_v_13_B.A[load_arduino_v_13_B.ix];
        load_arduino_v_13_B.c_ix = pipk + 1;
        load_arduino_v_13_B.d = (load_arduino_v_13_B.b_ix -
          load_arduino_v_13_B.b_j) + 8;
        load_arduino_v_13_B.ijA = 5 + load_arduino_v_13_B.b_ix;
        while (load_arduino_v_13_B.ijA + 1 <= load_arduino_v_13_B.d) {
          load_arduino_v_13_B.A[load_arduino_v_13_B.ijA] +=
            load_arduino_v_13_B.A[load_arduino_v_13_B.c_ix] *
            load_arduino_v_13_B.smax;
          load_arduino_v_13_B.c_ix++;
          load_arduino_v_13_B.ijA++;
        }
      }

      load_arduino_v_13_B.ix += 4;
      load_arduino_v_13_B.b_ix += 4;
      load_arduino_v_13_B.b_k++;
    }
  }

  load_arduino_v_13_B.p[0] = 1;
  load_arduino_v_13_B.p[1] = 2;
  load_arduino_v_13_B.p[2] = 3;
  load_arduino_v_13_B.p[3] = 4;
  if (load_arduino_v_13_B.ipiv[0] > 1) {
    load_arduino_v_13_B.b_j = load_arduino_v_13_B.ipiv[0] - 1;
    pipk = load_arduino_v_13_B.p[load_arduino_v_13_B.b_j];
    load_arduino_v_13_B.p[load_arduino_v_13_B.b_j] = 1;
    load_arduino_v_13_B.p[0] = (int8_T)pipk;
  }

  if (load_arduino_v_13_B.ipiv[1] > 2) {
    load_arduino_v_13_B.b_j = load_arduino_v_13_B.ipiv[1] - 1;
    pipk = load_arduino_v_13_B.p[load_arduino_v_13_B.b_j];
    load_arduino_v_13_B.p[load_arduino_v_13_B.b_j] = load_arduino_v_13_B.p[1];
    load_arduino_v_13_B.p[1] = (int8_T)pipk;
  }

  if (load_arduino_v_13_B.ipiv[2] > 3) {
    load_arduino_v_13_B.b_j = load_arduino_v_13_B.ipiv[2] - 1;
    pipk = load_arduino_v_13_B.p[load_arduino_v_13_B.b_j];
    load_arduino_v_13_B.p[load_arduino_v_13_B.b_j] = load_arduino_v_13_B.p[2];
    load_arduino_v_13_B.p[2] = (int8_T)pipk;
  }

  pipk = load_arduino_v_13_B.p[0] - 1;
  y[pipk << 2] = 1.0;
  load_arduino_v_13_B.b_ix = 0;
  while (load_arduino_v_13_B.b_ix + 1 < 5) {
    if (y[(pipk << 2) + load_arduino_v_13_B.b_ix] != 0.0) {
      load_arduino_v_13_B.ix = load_arduino_v_13_B.b_ix + 1;
      while (load_arduino_v_13_B.ix + 1 < 5) {
        y[load_arduino_v_13_B.ix + (pipk << 2)] -= y[(pipk << 2) +
          load_arduino_v_13_B.b_ix] * load_arduino_v_13_B.A
          [(load_arduino_v_13_B.b_ix << 2) + load_arduino_v_13_B.ix];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.b_ix++;
  }

  pipk = load_arduino_v_13_B.p[1] - 1;
  y[1 + (pipk << 2)] = 1.0;
  load_arduino_v_13_B.b_ix = 1;
  while (load_arduino_v_13_B.b_ix + 1 < 5) {
    if (y[(pipk << 2) + load_arduino_v_13_B.b_ix] != 0.0) {
      load_arduino_v_13_B.ix = load_arduino_v_13_B.b_ix + 1;
      while (load_arduino_v_13_B.ix + 1 < 5) {
        y[load_arduino_v_13_B.ix + (pipk << 2)] -= y[(pipk << 2) +
          load_arduino_v_13_B.b_ix] * load_arduino_v_13_B.A
          [(load_arduino_v_13_B.b_ix << 2) + load_arduino_v_13_B.ix];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.b_ix++;
  }

  pipk = load_arduino_v_13_B.p[2] - 1;
  y[2 + (pipk << 2)] = 1.0;
  load_arduino_v_13_B.b_ix = 2;
  while (load_arduino_v_13_B.b_ix + 1 < 5) {
    if (y[(pipk << 2) + load_arduino_v_13_B.b_ix] != 0.0) {
      load_arduino_v_13_B.ix = load_arduino_v_13_B.b_ix + 1;
      while (load_arduino_v_13_B.ix + 1 < 5) {
        y[load_arduino_v_13_B.ix + (pipk << 2)] -= y[(pipk << 2) +
          load_arduino_v_13_B.b_ix] * load_arduino_v_13_B.A
          [(load_arduino_v_13_B.b_ix << 2) + load_arduino_v_13_B.ix];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.b_ix++;
  }

  pipk = load_arduino_v_13_B.p[3] - 1;
  load_arduino_v_13_B.b_j = pipk << 2;
  y[3 + load_arduino_v_13_B.b_j] = 1.0;
  load_arduino_v_13_B.b_ix = 3;
  while (load_arduino_v_13_B.b_ix + 1 < 5) {
    if (y[load_arduino_v_13_B.b_j + load_arduino_v_13_B.b_ix] != 0.0) {
      load_arduino_v_13_B.ix = load_arduino_v_13_B.b_ix + 1;
      while (load_arduino_v_13_B.ix + 1 < 5) {
        y[load_arduino_v_13_B.ix + load_arduino_v_13_B.b_j] -= y[(pipk << 2) +
          load_arduino_v_13_B.b_ix] * load_arduino_v_13_B.A
          [(load_arduino_v_13_B.b_ix << 2) + load_arduino_v_13_B.ix];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.b_ix++;
  }

  for (pipk = 0; pipk < 4; pipk++) {
    load_arduino_v_13_B.b_ix = pipk << 2;
    load_arduino_v_13_B.smax = y[3 + load_arduino_v_13_B.b_ix];
    if (load_arduino_v_13_B.smax != 0.0) {
      y[3 + load_arduino_v_13_B.b_ix] = load_arduino_v_13_B.smax /
        load_arduino_v_13_B.A[15];
      load_arduino_v_13_B.ix = 0;
      while (load_arduino_v_13_B.ix <= 2) {
        load_arduino_v_13_B.b_j = load_arduino_v_13_B.ix +
          load_arduino_v_13_B.b_ix;
        y[load_arduino_v_13_B.b_j] -= y[3 + load_arduino_v_13_B.b_ix] *
          load_arduino_v_13_B.A[load_arduino_v_13_B.ix + 12];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.smax = y[2 + load_arduino_v_13_B.b_ix];
    if (load_arduino_v_13_B.smax != 0.0) {
      y[2 + load_arduino_v_13_B.b_ix] = load_arduino_v_13_B.smax /
        load_arduino_v_13_B.A[10];
      load_arduino_v_13_B.ix = 0;
      while (load_arduino_v_13_B.ix <= 1) {
        load_arduino_v_13_B.b_j = load_arduino_v_13_B.ix +
          load_arduino_v_13_B.b_ix;
        y[load_arduino_v_13_B.b_j] -= y[2 + load_arduino_v_13_B.b_ix] *
          load_arduino_v_13_B.A[load_arduino_v_13_B.ix + 8];
        load_arduino_v_13_B.ix++;
      }
    }

    load_arduino_v_13_B.smax = y[1 + load_arduino_v_13_B.b_ix];
    if (load_arduino_v_13_B.smax != 0.0) {
      y[1 + load_arduino_v_13_B.b_ix] = load_arduino_v_13_B.smax /
        load_arduino_v_13_B.A[5];
      y[load_arduino_v_13_B.b_ix] -= y[1 + load_arduino_v_13_B.b_ix] *
        load_arduino_v_13_B.A[4];
    }

    if (y[load_arduino_v_13_B.b_ix] != 0.0) {
      y[load_arduino_v_13_B.b_ix] /= load_arduino_v_13_B.A[0];
    }
  }
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_ifWhileCond_f(const boolean_T x[5])
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 5)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  char_T tmp;
  boolean_T exitg1;
  success = (*k <= 2);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= 2)) {
    tmp = s[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        (*k)++;
      }
    } else if (tmp != ',') {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k)
{
  boolean_T success;
  char_T tmp;
  success = true;
  if (*k <= 2) {
    tmp = s[*k - 1];
    if ((tmp == 'E') || (tmp == 'e')) {
      s1[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      if (*k <= 2) {
        if (s[1] == '-') {
          s1[*idx - 1] = '-';
          (*idx)++;
          *k = 3;
        } else {
          if (s[1] == '+') {
            *k = 3;
          }
        }
      }

      success = load_arduino_v_13_copydigits(s1, idx, s, k, false);
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copysign(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k)
{
  boolean_T success;
  boolean_T isneg;
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T exitg1;
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (*k <= 2)) {
    tmp = s[*k - 1];
    if ((tmp == '+') || (tmp == '-') || b[(uint8_T)tmp & 127]) {
      if (tmp == '-') {
        isneg = !isneg;
      }

      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  success = (*k <= 2);
  if (success && isneg) {
    if ((*idx >= 2) && (s1[*idx - 2] == '-')) {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      (*idx)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static void load_arduino_v_13_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
  boolean_T *success)
{
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T guard1 = false;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  load_arduino_v_13_B.b_k_f = *k;
  *success = load_arduino_v_13_copysign(s1, idx, s, &load_arduino_v_13_B.b_k_f);
  *k = load_arduino_v_13_B.b_k_f;
  if (*success) {
    guard1 = false;
    if (load_arduino_v_13_B.b_k_f <= 2) {
      tmp = s[load_arduino_v_13_B.b_k_f - 1];
      if ((tmp == 'j') || ((tmp == 'i') && ((load_arduino_v_13_B.b_k_f == 2) ||
            ((s[1] != 'n') && (s[1] != 'N'))))) {
        *success = false;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      *success = load_arduino_v_13_copydigits(s1, idx, s, k, true);
      if (*success) {
        *success = load_arduino_v_13_copyexponent(s1, idx, s, k);
      }

      while ((*k <= 2) && b[(uint8_T)s[*k - 1] & 127]) {
        (*k)++;
      }

      if ((*k <= 2) && (s[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= 2) && b[(uint8_T)s[*k - 1] & 127]) {
          (*k)++;
        }
      }

      if ((*k <= 2) && ((s[*k - 1] == 'i') || (s[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    while ((*k <= 2) && b[(uint8_T)s[*k - 1] & 127]) {
      (*k)++;
    }
  }
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static creal_T load_arduino_v_13_str2double(const char_T s[2])
{
  creal_T x;
  boolean_T success;
  boolean_T isimag1;
  boolean_T h_success;
  boolean_T isneg;
  boolean_T c_finite;
  static const boolean_T c[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T guard1 = false;
  boolean_T exitg1;
  x.re = (rtNaN);
  x.im = 0.0;
  isimag1 = false;
  load_arduino_v_13_B.c_k_j = 1;
  load_arduino_v_13_B.idx_e = 1;
  load_arduino_v_13_B.s1_n[0] = '\x00';
  load_arduino_v_13_B.s1_n[1] = '\x00';
  load_arduino_v_13_B.s1_n[2] = '\x00';
  load_arduino_v_13_B.s1_n[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_13_B.c_k_j <= 2)) {
    tmp = s[load_arduino_v_13_B.c_k_j - 1];
    if ((tmp == '+') || (tmp == '-') || c[(uint8_T)tmp & 127]) {
      if (tmp == '-') {
        isneg = !isneg;
      }

      load_arduino_v_13_B.c_k_j++;
    } else {
      exitg1 = true;
    }
  }

  success = (load_arduino_v_13_B.c_k_j <= 2);
  if (success && isneg) {
    load_arduino_v_13_B.s1_n[0] = '-';
    load_arduino_v_13_B.idx_e = 2;
  }

  if (success) {
    if ((load_arduino_v_13_B.c_k_j <= 2) && ((s[load_arduino_v_13_B.c_k_j - 1] ==
          'j') || ((s[load_arduino_v_13_B.c_k_j - 1] == 'i') &&
                   ((load_arduino_v_13_B.c_k_j == 2) || ((s[1] != 'n') && (s[1]
             != 'N')))))) {
      isimag1 = true;
      load_arduino_v_13_B.c_k_j++;
      while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)s[1] & 127]) {
        load_arduino_v_13_B.c_k_j = 3;
      }

      if ((load_arduino_v_13_B.c_k_j <= 2) && (s[1] == '*')) {
        load_arduino_v_13_B.c_k_j = 3;
        load_arduino_v_13_readfloat(load_arduino_v_13_B.s1_n,
          &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j, &isneg,
          &success, &load_arduino_v_13_B.b_scanned1_d, &h_success);
        load_arduino_v_13_B.c_k_j = 3;
        success = false;
      } else {
        load_arduino_v_13_B.s1_n[load_arduino_v_13_B.idx_e - 1] = '1';
        load_arduino_v_13_B.idx_e++;
      }
    } else {
      success = load_arduino_v_13_copydigits(load_arduino_v_13_B.s1_n,
        &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j, true);
      if (success) {
        success = load_arduino_v_13_copyexponent(load_arduino_v_13_B.s1_n,
          &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j);
      }

      while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
             s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
        load_arduino_v_13_B.c_k_j++;
      }

      if ((load_arduino_v_13_B.c_k_j <= 2) && (s[load_arduino_v_13_B.c_k_j - 1] ==
           '*')) {
        load_arduino_v_13_B.c_k_j++;
        while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
               s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
          load_arduino_v_13_B.c_k_j++;
        }
      }

      if (load_arduino_v_13_B.c_k_j <= 2) {
        tmp = s[load_arduino_v_13_B.c_k_j - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          load_arduino_v_13_B.c_k_j++;
          isimag1 = true;
        }
      }
    }

    while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
           s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
      load_arduino_v_13_B.c_k_j++;
    }
  }

  load_arduino_v_13_B.ntoread_b = 1;
  if (success && (load_arduino_v_13_B.c_k_j <= 2)) {
    load_arduino_v_13_B.s1_n[load_arduino_v_13_B.idx_e - 1] = ' ';
    isneg = false;
    load_arduino_v_13_B.idx_e++;
    success = load_arduino_v_13_copysign(load_arduino_v_13_B.s1_n,
      &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j);
    if (success) {
      guard1 = false;
      if (load_arduino_v_13_B.c_k_j <= 2) {
        tmp = s[load_arduino_v_13_B.c_k_j - 1];
        if ((tmp == 'j') || ((tmp == 'i') && ((load_arduino_v_13_B.c_k_j == 2) ||
              ((s[1] != 'n') && (s[1] != 'N'))))) {
          isneg = true;
          load_arduino_v_13_B.c_k_j++;
          while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
                 s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
            load_arduino_v_13_B.c_k_j++;
          }

          if ((load_arduino_v_13_B.c_k_j <= 2) && (s[load_arduino_v_13_B.c_k_j -
               1] == '*')) {
            load_arduino_v_13_B.c_k_j++;
            load_arduino_v_13_readfloat(load_arduino_v_13_B.s1_n,
              &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j,
              &h_success, &c_finite, &load_arduino_v_13_B.b_scanned1_d, &success);
          } else {
            load_arduino_v_13_B.s1_n[load_arduino_v_13_B.idx_e - 1] = '1';
            load_arduino_v_13_B.idx_e++;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        success = load_arduino_v_13_copydigits(load_arduino_v_13_B.s1_n,
          &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j, true);
        if (success) {
          success = load_arduino_v_13_copyexponent(load_arduino_v_13_B.s1_n,
            &load_arduino_v_13_B.idx_e, s, &load_arduino_v_13_B.c_k_j);
        }

        while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
               s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
          load_arduino_v_13_B.c_k_j++;
        }

        if ((load_arduino_v_13_B.c_k_j <= 2) && (s[load_arduino_v_13_B.c_k_j - 1]
             == '*')) {
          load_arduino_v_13_B.c_k_j++;
          while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
                 s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
            load_arduino_v_13_B.c_k_j++;
          }
        }

        if (load_arduino_v_13_B.c_k_j <= 2) {
          tmp = s[load_arduino_v_13_B.c_k_j - 1];
          if ((tmp == 'i') || (tmp == 'j')) {
            load_arduino_v_13_B.c_k_j++;
            isneg = true;
          }
        }
      }

      while ((load_arduino_v_13_B.c_k_j <= 2) && c[(uint8_T)
             s[load_arduino_v_13_B.c_k_j - 1] & 127]) {
        load_arduino_v_13_B.c_k_j++;
      }
    }

    load_arduino_v_13_B.scanned2_d = 0.0;
    load_arduino_v_13_B.ntoread_b = 2;
    success = (success && (load_arduino_v_13_B.c_k_j > 2) && ((isimag1 ^ isneg)
                != 0));
  } else {
    load_arduino_v_13_B.scanned2_d = 0.0;
  }

  if (success) {
    load_arduino_v_13_B.s1_n[load_arduino_v_13_B.idx_e - 1] = '\x00';
    if (load_arduino_v_13_B.ntoread_b == 2) {
      load_arduino_v_13_B.idx_e = sscanf(&load_arduino_v_13_B.s1_n[0], "%lf %lf",
        &load_arduino_v_13_B.b_scanned1_d, &load_arduino_v_13_B.scanned2_d);
      if (load_arduino_v_13_B.idx_e != 2) {
        load_arduino_v_13_B.b_scanned1_d = (rtNaN);
        load_arduino_v_13_B.scanned2_d = (rtNaN);
      }
    } else {
      load_arduino_v_13_B.idx_e = sscanf(&load_arduino_v_13_B.s1_n[0], "%lf",
        &load_arduino_v_13_B.b_scanned1_d);
      if (load_arduino_v_13_B.idx_e != 1) {
        load_arduino_v_13_B.b_scanned1_d = (rtNaN);
      }
    }

    if (isimag1) {
      x.re = load_arduino_v_13_B.scanned2_d;
      x.im = load_arduino_v_13_B.b_scanned1_d;
    } else {
      x.re = load_arduino_v_13_B.b_scanned1_d;
      x.im = load_arduino_v_13_B.scanned2_d;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copysign_f(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n)
{
  boolean_T success;
  boolean_T isneg;
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T exitg1;
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    tmp = s_data[*k - 1];
    if ((tmp == '+') || (tmp == '-') || b[(uint8_T)tmp & 127]) {
      if (tmp == '-') {
        isneg = !isneg;
      }

      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  success = (*k <= n);
  if (success && isneg) {
    if ((*idx >= 2) && (s1_data[*idx - 2] == '-')) {
      s1_data[*idx - 2] = ' ';
    } else {
      s1_data[*idx - 1] = '-';
      (*idx)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static void load_arduino_v_13_readNonFinite(const char_T s_data[], int32_T *k,
  int32_T n, boolean_T *b_finite, real_T *fv)
{
  char_T tmp;
  char_T tmp_0;
  boolean_T guard1 = false;
  *b_finite = true;
  *fv = 0.0;
  if (*k + 2 <= n) {
    tmp = s_data[*k - 1];
    guard1 = false;
    if (((tmp == 'I') || (tmp == 'i')) && ((s_data[*k] == 'N') || (s_data[*k] ==
          'n'))) {
      tmp_0 = s_data[*k + 1];
      if ((tmp_0 == 'F') || (tmp_0 == 'f')) {
        *b_finite = false;
        *fv = (rtInf);
        *k += 3;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (((tmp == 'N') || (tmp == 'n')) && ((s_data[*k] == 'A') || (s_data[*k] ==
            'a')) && ((s_data[*k + 1] == 'N') || (s_data[*k + 1] == 'n'))) {
        *b_finite = false;
        *fv = (rtNaN);
        *k += 3;
      }
    }
  }
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copydigits_c(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  char_T tmp;
  boolean_T exitg1;
  success = (*k <= n);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    tmp = s_data[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1_data[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1_data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        (*k)++;
      }
    } else if (tmp != ',') {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_1_copyexponent_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n)
{
  boolean_T success;
  char_T tmp;
  success = true;
  if (*k <= n) {
    tmp = s_data[*k - 1];
    if ((tmp == 'E') || (tmp == 'e')) {
      s1_data[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      if (*k <= n) {
        if (s_data[*k - 1] == '-') {
          s1_data[*idx - 1] = '-';
          (*idx)++;
          (*k)++;
        } else {
          if (s_data[*k - 1] == '+') {
            (*k)++;
          }
        }
      }

      success = load_arduino_v_13_copydigits_c(s1_data, idx, s_data, k, n, false);
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static void load_arduino_v_13_readfloat_a(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *success)
{
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  load_arduino_v_13_B.b_idx = *idx;
  load_arduino_v_13_B.b_k_b = *k;
  *success = load_arduino_v_13_copysign_f(s1_data, &load_arduino_v_13_B.b_idx,
    s_data, &load_arduino_v_13_B.b_k_b, n);
  *idx = load_arduino_v_13_B.b_idx;
  *k = load_arduino_v_13_B.b_k_b;
  if (*success) {
    guard1 = false;
    if (load_arduino_v_13_B.b_k_b <= n) {
      tmp = s_data[load_arduino_v_13_B.b_k_b - 1];
      if ((tmp == 'j') || ((tmp == 'i') && ((load_arduino_v_13_B.b_k_b == n) ||
            ((s_data[load_arduino_v_13_B.b_k_b] != 'n') &&
             (s_data[load_arduino_v_13_B.b_k_b] != 'N'))))) {
        *isimag = true;
        *k = load_arduino_v_13_B.b_k_b + 1;
        while ((*k <= n) && b[(uint8_T)s_data[*k - 1] & 127]) {
          (*k)++;
        }

        if ((*k <= n) && (s_data[*k - 1] == '*')) {
          (*k)++;
          load_arduino_v_13_B.b_k_b = *k;
          *success = load_arduino_v_13_copysign_f(s1_data,
            &load_arduino_v_13_B.b_idx, s_data, &load_arduino_v_13_B.b_k_b, n);
          *idx = load_arduino_v_13_B.b_idx;
          if (*success) {
            guard2 = false;
            if (load_arduino_v_13_B.b_k_b <= n) {
              tmp = s_data[load_arduino_v_13_B.b_k_b - 1];
              if ((tmp == 'j') || ((tmp == 'i') && ((load_arduino_v_13_B.b_k_b ==
                     n) || ((s_data[load_arduino_v_13_B.b_k_b] != 'n') &&
                            (s_data[load_arduino_v_13_B.b_k_b] != 'N'))))) {
                *success = false;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }

            if (guard2) {
              load_arduino_v_13_readNonFinite(s_data, &load_arduino_v_13_B.b_k_b,
                n, b_finite, nfv);
              if (*b_finite) {
                *success = load_arduino_v_13_copydigits_c(s1_data, idx, s_data,
                  &load_arduino_v_13_B.b_k_b, n, true);
                if (*success) {
                  *success = load_arduino_v_1_copyexponent_o(s1_data, idx,
                    s_data, &load_arduino_v_13_B.b_k_b, n);
                }
              } else {
                if ((load_arduino_v_13_B.b_idx >= 2) &&
                    (s1_data[load_arduino_v_13_B.b_idx - 2] == '-')) {
                  *idx = load_arduino_v_13_B.b_idx - 1;
                  s1_data[load_arduino_v_13_B.b_idx - 2] = ' ';
                  *nfv = -*nfv;
                }
              }

              while ((load_arduino_v_13_B.b_k_b <= n) && b[(uint8_T)
                     s_data[load_arduino_v_13_B.b_k_b - 1] & 127]) {
                load_arduino_v_13_B.b_k_b++;
              }

              if ((load_arduino_v_13_B.b_k_b <= n) &&
                  (s_data[load_arduino_v_13_B.b_k_b - 1] == '*')) {
                load_arduino_v_13_B.b_k_b++;
                while ((load_arduino_v_13_B.b_k_b <= n) && b[(uint8_T)
                       s_data[load_arduino_v_13_B.b_k_b - 1] & 127]) {
                  load_arduino_v_13_B.b_k_b++;
                }
              }

              if (load_arduino_v_13_B.b_k_b <= n) {
                tmp = s_data[load_arduino_v_13_B.b_k_b - 1];
                if ((tmp == 'i') || (tmp == 'j')) {
                  load_arduino_v_13_B.b_k_b++;
                }
              }
            }

            while ((load_arduino_v_13_B.b_k_b <= n) && b[(uint8_T)
                   s_data[load_arduino_v_13_B.b_k_b - 1] & 127]) {
              load_arduino_v_13_B.b_k_b++;
            }
          }

          *k = load_arduino_v_13_B.b_k_b;
        } else {
          s1_data[load_arduino_v_13_B.b_idx - 1] = '1';
          *idx = load_arduino_v_13_B.b_idx + 1;
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      load_arduino_v_13_readNonFinite(s_data, &load_arduino_v_13_B.b_k_b, n,
        b_finite, nfv);
      *k = load_arduino_v_13_B.b_k_b;
      if (*b_finite) {
        *success = load_arduino_v_13_copydigits_c(s1_data, idx, s_data, k, n,
          true);
        if (*success) {
          *success = load_arduino_v_1_copyexponent_o(s1_data, idx, s_data, k, n);
        }
      } else {
        if ((load_arduino_v_13_B.b_idx >= 2) &&
            (s1_data[load_arduino_v_13_B.b_idx - 2] == '-')) {
          *idx = load_arduino_v_13_B.b_idx - 1;
          s1_data[load_arduino_v_13_B.b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      while ((*k <= n) && b[(uint8_T)s_data[*k - 1] & 127]) {
        (*k)++;
      }

      if ((*k <= n) && (s_data[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= n) && b[(uint8_T)s_data[*k - 1] & 127]) {
          (*k)++;
        }
      }

      if ((*k <= n) && ((s_data[*k - 1] == 'i') || (s_data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    while ((*k <= n) && b[(uint8_T)s_data[*k - 1] & 127]) {
      (*k)++;
    }
  }
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static creal_T load_arduino_v_13_str2double_g(const char_T s_data[], const
  int32_T s_size[2])
{
  creal_T x;
  boolean_T success;
  boolean_T isimag1;
  boolean_T isfinite1;
  boolean_T isfinite2;
  boolean_T c_success;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s_size[1] >= 1) {
    load_arduino_v_13_B.ntoread = 0;
    load_arduino_v_13_B.loop_ub = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= load_arduino_v_13_B.loop_ub) {
      memset(&load_arduino_v_13_B.s1_data[0], 0, (load_arduino_v_13_B.loop_ub +
              1) * sizeof(char_T));
    }

    load_arduino_v_13_B.idx = 1;
    load_arduino_v_13_B.loop_ub = 1;
    load_arduino_v_13_readfloat_a(load_arduino_v_13_B.s1_data,
      &load_arduino_v_13_B.idx, s_data, &load_arduino_v_13_B.loop_ub, s_size[1],
      &isimag1, &isfinite1, &load_arduino_v_13_B.b_scanned1, &success);
    if (isfinite1) {
      load_arduino_v_13_B.ntoread = 1;
    }

    if (success) {
      if (load_arduino_v_13_B.loop_ub <= s_size[1]) {
        load_arduino_v_13_B.s1_data[load_arduino_v_13_B.idx - 1] = ' ';
        load_arduino_v_13_B.idx++;
        load_arduino_v_13_readfloat_a(load_arduino_v_13_B.s1_data,
          &load_arduino_v_13_B.idx, s_data, &load_arduino_v_13_B.loop_ub,
          s_size[1], &success, &isfinite2, &load_arduino_v_13_B.scanned2,
          &c_success);
        if (isfinite2) {
          load_arduino_v_13_B.ntoread++;
        }

        success = (c_success && ((load_arduino_v_13_B.loop_ub > s_size[1]) &&
                    ((isimag1 ^ success) != 0)));
      } else {
        load_arduino_v_13_B.scanned2 = 0.0;
      }
    } else {
      load_arduino_v_13_B.scanned2 = 0.0;
    }

    if (success) {
      load_arduino_v_13_B.s1_data[load_arduino_v_13_B.idx - 1] = '\x00';
      switch (load_arduino_v_13_B.ntoread) {
       case 2:
        load_arduino_v_13_B.ntoread = sscanf(&load_arduino_v_13_B.s1_data[0],
          "%lf %lf", &load_arduino_v_13_B.b_scanned1,
          &load_arduino_v_13_B.scanned2);
        if (load_arduino_v_13_B.ntoread != 2) {
          load_arduino_v_13_B.b_scanned1 = (rtNaN);
          load_arduino_v_13_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        load_arduino_v_13_B.ntoread = sscanf(&load_arduino_v_13_B.s1_data[0],
          "%lf", &load_arduino_v_13_B.scanned1);
        if (isfinite1) {
          if (load_arduino_v_13_B.ntoread == 1) {
            load_arduino_v_13_B.b_scanned1 = load_arduino_v_13_B.scanned1;
          } else {
            load_arduino_v_13_B.b_scanned1 = (rtNaN);
          }
        } else if (load_arduino_v_13_B.ntoread == 1) {
          load_arduino_v_13_B.scanned2 = load_arduino_v_13_B.scanned1;
        } else {
          load_arduino_v_13_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = load_arduino_v_13_B.scanned2;
        x.im = load_arduino_v_13_B.b_scanned1;
      } else {
        x.re = load_arduino_v_13_B.b_scanned1;
        x.im = load_arduino_v_13_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static void load_arduino_v__readNonFinite_p(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv)
{
  char_T tmp;
  *b_finite = true;
  *fv = 0.0;
  if (*k + 2 <= 3) {
    tmp = s[*k - 1];
    if (((tmp == 'I') || (tmp == 'i')) && ((s[*k] == 'N') || (s[*k] == 'n')) &&
        ((s[2] == 'F') || (s[2] == 'f'))) {
      *b_finite = false;
      *fv = (rtInf);
      *k += 3;
    } else {
      if (((tmp == 'N') || (tmp == 'n')) && ((s[*k] == 'A') || (s[*k] == 'a')) &&
          ((s[2] == 'N') || (s[2] == 'n'))) {
        *b_finite = false;
        *fv = (rtNaN);
        *k += 3;
      }
    }
  }
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copydigits_cm(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  char_T tmp;
  boolean_T exitg1;
  success = (*k <= 3);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= 3)) {
    tmp = s[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        (*k)++;
      }
    } else if (tmp != ',') {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v__copyexponent_ok(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k)
{
  boolean_T success;
  char_T tmp;
  success = true;
  if (*k <= 3) {
    tmp = s[*k - 1];
    if ((tmp == 'E') || (tmp == 'e')) {
      s1[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      if (*k <= 3) {
        if (s[*k - 1] == '-') {
          s1[*idx - 1] = '-';
          (*idx)++;
          (*k)++;
        } else {
          if (s[*k - 1] == '+') {
            (*k)++;
          }
        }
      }

      success = load_arduino_v_13_copydigits_cm(s1, idx, s, k, false);
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_13_copysign_fr(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k)
{
  boolean_T success;
  boolean_T isneg;
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T exitg1;
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (*k <= 3)) {
    tmp = s[*k - 1];
    if ((tmp == '+') || (tmp == '-') || b[(uint8_T)tmp & 127]) {
      if (tmp == '-') {
        isneg = !isneg;
      }

      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  success = (*k <= 3);
  if (success && isneg) {
    if ((*idx >= 2) && (s1[*idx - 2] == '-')) {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      (*idx)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static void load_arduino_v_13_readfloat_a1(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
  boolean_T *success)
{
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T guard1 = false;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  load_arduino_v_13_B.b_idx_b = *idx;
  load_arduino_v_13_B.b_k_d = *k;
  *success = load_arduino_v_13_copysign_fr(s1, &load_arduino_v_13_B.b_idx_b, s,
    &load_arduino_v_13_B.b_k_d);
  *idx = load_arduino_v_13_B.b_idx_b;
  *k = load_arduino_v_13_B.b_k_d;
  if (*success) {
    guard1 = false;
    if (load_arduino_v_13_B.b_k_d <= 3) {
      tmp = s[load_arduino_v_13_B.b_k_d - 1];
      if ((tmp == 'j') || ((tmp == 'i') && ((load_arduino_v_13_B.b_k_d == 3) ||
            ((s[load_arduino_v_13_B.b_k_d] != 'n') &&
             (s[load_arduino_v_13_B.b_k_d] != 'N'))))) {
        *success = false;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      load_arduino_v__readNonFinite_p(s, &load_arduino_v_13_B.b_k_d, b_finite,
        nfv);
      *k = load_arduino_v_13_B.b_k_d;
      if (*b_finite) {
        *success = load_arduino_v_13_copydigits_cm(s1, idx, s, k, true);
        if (*success) {
          *success = load_arduino_v__copyexponent_ok(s1, idx, s, k);
        }
      } else {
        if ((load_arduino_v_13_B.b_idx_b >= 2) &&
            (s1[load_arduino_v_13_B.b_idx_b - 2] == '-')) {
          *idx = load_arduino_v_13_B.b_idx_b - 1;
          s1[load_arduino_v_13_B.b_idx_b - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      while ((*k <= 3) && b[(uint8_T)s[*k - 1] & 127]) {
        (*k)++;
      }

      if ((*k <= 3) && (s[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= 3) && b[(uint8_T)s[*k - 1] & 127]) {
          (*k)++;
        }
      }

      if ((*k <= 3) && ((s[*k - 1] == 'i') || (s[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    while ((*k <= 3) && b[(uint8_T)s[*k - 1] & 127]) {
      (*k)++;
    }
  }
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static creal_T load_arduino_v_13_str2double_gv(const char_T s[3])
{
  creal_T x;
  boolean_T success;
  boolean_T isimag1;
  boolean_T b_finite;
  boolean_T c_finite;
  boolean_T isneg;
  boolean_T b_unusedU0;
  static const boolean_T c[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T tmp;
  boolean_T guard1 = false;
  boolean_T exitg1;
  x.re = (rtNaN);
  x.im = 0.0;
  load_arduino_v_13_B.ntoread_h = 0;
  isimag1 = false;
  b_finite = true;
  load_arduino_v_13_B.b_scanned1_g = 0.0;
  load_arduino_v_13_B.c_k = 1;
  load_arduino_v_13_B.idx_l = 1;
  for (load_arduino_v_13_B.h_idx = 0; load_arduino_v_13_B.h_idx < 5;
       load_arduino_v_13_B.h_idx++) {
    load_arduino_v_13_B.s1[load_arduino_v_13_B.h_idx] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_13_B.c_k <= 3)) {
    tmp = s[load_arduino_v_13_B.c_k - 1];
    if ((tmp == '+') || (tmp == '-') || c[(uint8_T)tmp & 127]) {
      if (tmp == '-') {
        isneg = !isneg;
      }

      load_arduino_v_13_B.c_k++;
    } else {
      exitg1 = true;
    }
  }

  success = (load_arduino_v_13_B.c_k <= 3);
  if (success && isneg) {
    load_arduino_v_13_B.s1[0] = '-';
    load_arduino_v_13_B.idx_l = 2;
  }

  if (success) {
    if ((load_arduino_v_13_B.c_k <= 3) && ((s[load_arduino_v_13_B.c_k - 1] ==
          'j') || ((s[load_arduino_v_13_B.c_k - 1] == 'i') &&
                   ((load_arduino_v_13_B.c_k == 3) ||
                    ((s[load_arduino_v_13_B.c_k] != 'n') &&
                     (s[load_arduino_v_13_B.c_k] != 'N')))))) {
      isimag1 = true;
      load_arduino_v_13_B.c_k++;
      while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
             s[load_arduino_v_13_B.c_k - 1] & 127]) {
        load_arduino_v_13_B.c_k++;
      }

      if ((load_arduino_v_13_B.c_k <= 3) && (s[load_arduino_v_13_B.c_k - 1] ==
           '*')) {
        load_arduino_v_13_B.c_k++;
        load_arduino_v_13_readfloat_a1(load_arduino_v_13_B.s1,
          &load_arduino_v_13_B.idx_l, s, &load_arduino_v_13_B.c_k, &isneg,
          &c_finite, &load_arduino_v_13_B.scanned2_l, &success);
      } else {
        load_arduino_v_13_B.s1[load_arduino_v_13_B.idx_l - 1] = '1';
        load_arduino_v_13_B.idx_l++;
      }
    } else {
      load_arduino_v__readNonFinite_p(s, &load_arduino_v_13_B.c_k, &b_finite,
        &load_arduino_v_13_B.b_scanned1_g);
      if (b_finite) {
        success = load_arduino_v_13_copydigits_cm(load_arduino_v_13_B.s1,
          &load_arduino_v_13_B.idx_l, s, &load_arduino_v_13_B.c_k, true);
        if (success) {
          success = load_arduino_v__copyexponent_ok(load_arduino_v_13_B.s1,
            &load_arduino_v_13_B.idx_l, s, &load_arduino_v_13_B.c_k);
        }
      } else {
        if ((load_arduino_v_13_B.idx_l >= 2) && (load_arduino_v_13_B.s1[0] ==
             '-')) {
          load_arduino_v_13_B.idx_l = 1;
          load_arduino_v_13_B.s1[0] = ' ';
          load_arduino_v_13_B.b_scanned1_g = -load_arduino_v_13_B.b_scanned1_g;
        }
      }

      while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
             s[load_arduino_v_13_B.c_k - 1] & 127]) {
        load_arduino_v_13_B.c_k++;
      }

      if ((load_arduino_v_13_B.c_k <= 3) && (s[load_arduino_v_13_B.c_k - 1] ==
           '*')) {
        load_arduino_v_13_B.c_k++;
        while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
               s[load_arduino_v_13_B.c_k - 1] & 127]) {
          load_arduino_v_13_B.c_k++;
        }
      }

      if (load_arduino_v_13_B.c_k <= 3) {
        tmp = s[load_arduino_v_13_B.c_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          load_arduino_v_13_B.c_k++;
          isimag1 = true;
        }
      }
    }

    while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
           s[load_arduino_v_13_B.c_k - 1] & 127]) {
      load_arduino_v_13_B.c_k++;
    }
  }

  if (b_finite) {
    load_arduino_v_13_B.ntoread_h = 1;
  }

  if (success && (load_arduino_v_13_B.c_k <= 3)) {
    load_arduino_v_13_B.s1[load_arduino_v_13_B.idx_l - 1] = ' ';
    success = false;
    isneg = true;
    load_arduino_v_13_B.scanned2_l = 0.0;
    load_arduino_v_13_B.h_idx = load_arduino_v_13_B.idx_l + 1;
    c_finite = load_arduino_v_13_copysign_fr(load_arduino_v_13_B.s1,
      &load_arduino_v_13_B.h_idx, s, &load_arduino_v_13_B.c_k);
    load_arduino_v_13_B.idx_l = load_arduino_v_13_B.h_idx;
    if (c_finite) {
      guard1 = false;
      if (load_arduino_v_13_B.c_k <= 3) {
        tmp = s[load_arduino_v_13_B.c_k - 1];
        if ((tmp == 'j') || ((tmp == 'i') && ((load_arduino_v_13_B.c_k == 3) ||
              ((s[load_arduino_v_13_B.c_k] != 'n') && (s[load_arduino_v_13_B.c_k]
                != 'N'))))) {
          success = true;
          load_arduino_v_13_B.c_k++;
          while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
                 s[load_arduino_v_13_B.c_k - 1] & 127]) {
            load_arduino_v_13_B.c_k++;
          }

          if ((load_arduino_v_13_B.c_k <= 3) && (s[load_arduino_v_13_B.c_k - 1] ==
               '*')) {
            load_arduino_v_13_B.c_k++;
            load_arduino_v_13_readfloat_a1(load_arduino_v_13_B.s1,
              &load_arduino_v_13_B.idx_l, s, &load_arduino_v_13_B.c_k,
              &b_unusedU0, &isneg, &load_arduino_v_13_B.scanned2_l, &c_finite);
          } else {
            load_arduino_v_13_B.s1[load_arduino_v_13_B.h_idx - 1] = '1';
            load_arduino_v_13_B.idx_l = load_arduino_v_13_B.h_idx + 1;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        load_arduino_v__readNonFinite_p(s, &load_arduino_v_13_B.c_k, &isneg,
          &load_arduino_v_13_B.scanned2_l);
        if (isneg) {
          c_finite = load_arduino_v_13_copydigits_cm(load_arduino_v_13_B.s1,
            &load_arduino_v_13_B.idx_l, s, &load_arduino_v_13_B.c_k, true);
          if (c_finite) {
            c_finite = load_arduino_v__copyexponent_ok(load_arduino_v_13_B.s1,
              &load_arduino_v_13_B.idx_l, s, &load_arduino_v_13_B.c_k);
          }
        } else {
          if ((load_arduino_v_13_B.h_idx >= 2) &&
              (load_arduino_v_13_B.s1[load_arduino_v_13_B.h_idx - 2] == '-')) {
            load_arduino_v_13_B.idx_l = load_arduino_v_13_B.h_idx - 1;
            load_arduino_v_13_B.s1[load_arduino_v_13_B.h_idx - 2] = ' ';
            load_arduino_v_13_B.scanned2_l = -load_arduino_v_13_B.scanned2_l;
          }
        }

        while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
               s[load_arduino_v_13_B.c_k - 1] & 127]) {
          load_arduino_v_13_B.c_k++;
        }

        if ((load_arduino_v_13_B.c_k <= 3) && (s[load_arduino_v_13_B.c_k - 1] ==
             '*')) {
          load_arduino_v_13_B.c_k++;
          while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
                 s[load_arduino_v_13_B.c_k - 1] & 127]) {
            load_arduino_v_13_B.c_k++;
          }
        }

        if (load_arduino_v_13_B.c_k <= 3) {
          tmp = s[load_arduino_v_13_B.c_k - 1];
          if ((tmp == 'i') || (tmp == 'j')) {
            load_arduino_v_13_B.c_k++;
            success = true;
          }
        }
      }

      while ((load_arduino_v_13_B.c_k <= 3) && c[(uint8_T)
             s[load_arduino_v_13_B.c_k - 1] & 127]) {
        load_arduino_v_13_B.c_k++;
      }
    }

    if (isneg) {
      load_arduino_v_13_B.ntoread_h++;
    }

    success = (c_finite && (load_arduino_v_13_B.c_k > 3) && ((isimag1 ^ success)
                != 0));
  } else {
    load_arduino_v_13_B.scanned2_l = 0.0;
  }

  if (success) {
    load_arduino_v_13_B.s1[load_arduino_v_13_B.idx_l - 1] = '\x00';
    switch (load_arduino_v_13_B.ntoread_h) {
     case 2:
      load_arduino_v_13_B.ntoread_h = sscanf(&load_arduino_v_13_B.s1[0],
        "%lf %lf", &load_arduino_v_13_B.b_scanned1_g,
        &load_arduino_v_13_B.scanned2_l);
      if (load_arduino_v_13_B.ntoread_h != 2) {
        load_arduino_v_13_B.b_scanned1_g = (rtNaN);
        load_arduino_v_13_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      load_arduino_v_13_B.ntoread_h = sscanf(&load_arduino_v_13_B.s1[0], "%lf",
        &load_arduino_v_13_B.scanned1_d);
      if (b_finite) {
        if (load_arduino_v_13_B.ntoread_h == 1) {
          load_arduino_v_13_B.b_scanned1_g = load_arduino_v_13_B.scanned1_d;
        } else {
          load_arduino_v_13_B.b_scanned1_g = (rtNaN);
        }
      } else if (load_arduino_v_13_B.ntoread_h == 1) {
        load_arduino_v_13_B.scanned2_l = load_arduino_v_13_B.scanned1_d;
      } else {
        load_arduino_v_13_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = load_arduino_v_13_B.scanned2_l;
      x.im = load_arduino_v_13_B.b_scanned1_g;
    } else {
      x.re = load_arduino_v_13_B.b_scanned1_g;
      x.im = load_arduino_v_13_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static boolean_T load_arduino_v_1_copydigits_cmm(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  boolean_T exitg1;
  success = (*k <= 1);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= 1)) {
    if ((s >= '0') && (s <= '9')) {
      s1[*idx - 1] = s;
      (*idx)++;
      *k = 2;
    } else if (s == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        *k = 2;
      }
    } else if (s != ',') {
      exitg1 = true;
    } else {
      *k = 2;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static creal_T load_arduino_v_1_str2double_gv1(char_T s)
{
  creal_T x;
  char_T s1[3];
  boolean_T success;
  boolean_T isimag1;
  int32_T c_k;
  boolean_T isneg;
  boolean_T j_success;
  static const boolean_T c[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  x.re = (rtNaN);
  x.im = 0.0;
  isimag1 = false;
  c_k = 1;
  load_arduino_v_13_B.idx_a = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  if ((s == '+') || (s == '-') || c[(uint8_T)s & 127]) {
    if (s == '-') {
      isneg = true;
    }

    c_k = 2;
  }

  success = (c_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    load_arduino_v_13_B.idx_a = 2;
  }

  if (success) {
    if ((c_k <= 1) && ((s == 'j') || (s == 'i'))) {
      isimag1 = true;
      c_k = 2;
      s1[load_arduino_v_13_B.idx_a - 1] = '1';
      load_arduino_v_13_B.idx_a++;
    } else {
      success = load_arduino_v_1_copydigits_cmm(s1, &load_arduino_v_13_B.idx_a,
        s, &c_k, true);
      if (success) {
        success = true;
        if ((c_k <= 1) && ((s == 'E') || (s == 'e'))) {
          s1[load_arduino_v_13_B.idx_a - 1] = 'e';
          load_arduino_v_13_B.idx_a++;
          c_k = 2;
          success = load_arduino_v_1_copydigits_cmm(s1,
            &load_arduino_v_13_B.idx_a, s, &c_k, false);
        }
      }

      while ((c_k <= 1) && c[(uint8_T)s & 127]) {
        c_k = 2;
      }

      if ((c_k <= 1) && (s == '*')) {
        c_k = 2;
      }

      if ((c_k <= 1) && ((s == 'i') || (s == 'j'))) {
        c_k = 2;
        isimag1 = true;
      }
    }

    while ((c_k <= 1) && c[(uint8_T)s & 127]) {
      c_k = 2;
    }
  }

  load_arduino_v_13_B.ntoread_j = 1;
  if (success && (c_k <= 1)) {
    s1[load_arduino_v_13_B.idx_a - 1] = ' ';
    isneg = false;
    c_k = 1;
    load_arduino_v_13_B.ntoread_j = load_arduino_v_13_B.idx_a + 1;
    success = false;
    if ((s == '+') || (s == '-') || c[(uint8_T)s & 127]) {
      if (s == '-') {
        success = true;
      }

      c_k = 2;
    }

    j_success = (c_k <= 1);
    if (j_success && success) {
      if (s1[load_arduino_v_13_B.idx_a - 1] == '-') {
        s1[load_arduino_v_13_B.idx_a - 1] = ' ';
      } else {
        s1[load_arduino_v_13_B.idx_a] = '-';
        load_arduino_v_13_B.ntoread_j = load_arduino_v_13_B.idx_a + 2;
      }
    }

    load_arduino_v_13_B.idx_a = load_arduino_v_13_B.ntoread_j;
    if (j_success) {
      if ((c_k <= 1) && ((s == 'j') || (s == 'i'))) {
        isneg = true;
        c_k = 2;
        s1[load_arduino_v_13_B.ntoread_j - 1] = '1';
        load_arduino_v_13_B.idx_a = load_arduino_v_13_B.ntoread_j + 1;
      } else {
        j_success = load_arduino_v_1_copydigits_cmm(s1,
          &load_arduino_v_13_B.ntoread_j, s, &c_k, true);
        load_arduino_v_13_B.idx_a = load_arduino_v_13_B.ntoread_j;
        if (j_success) {
          j_success = true;
          if ((c_k <= 1) && ((s == 'E') || (s == 'e'))) {
            s1[load_arduino_v_13_B.ntoread_j - 1] = 'e';
            load_arduino_v_13_B.idx_a = load_arduino_v_13_B.ntoread_j + 1;
            c_k = 2;
            j_success = load_arduino_v_1_copydigits_cmm(s1,
              &load_arduino_v_13_B.idx_a, s, &c_k, false);
          }
        }

        while ((c_k <= 1) && c[(uint8_T)s & 127]) {
          c_k = 2;
        }

        if ((c_k <= 1) && (s == '*')) {
          c_k = 2;
        }

        if ((c_k <= 1) && ((s == 'i') || (s == 'j'))) {
          c_k = 2;
          isneg = true;
        }
      }

      while ((c_k <= 1) && c[(uint8_T)s & 127]) {
        c_k = 2;
      }
    }

    load_arduino_v_13_B.scanned2_o = 0.0;
    load_arduino_v_13_B.ntoread_j = 2;
    success = (j_success && (c_k > 1) && ((isimag1 ^ isneg) != 0));
  } else {
    load_arduino_v_13_B.scanned2_o = 0.0;
  }

  if (success) {
    s1[load_arduino_v_13_B.idx_a - 1] = '\x00';
    if (load_arduino_v_13_B.ntoread_j == 2) {
      load_arduino_v_13_B.idx_a = sscanf(&s1[0], "%lf %lf",
        &load_arduino_v_13_B.b_scanned1_l, &load_arduino_v_13_B.scanned2_o);
      if (load_arduino_v_13_B.idx_a != 2) {
        load_arduino_v_13_B.b_scanned1_l = (rtNaN);
        load_arduino_v_13_B.scanned2_o = (rtNaN);
      }
    } else {
      load_arduino_v_13_B.idx_a = sscanf(&s1[0], "%lf",
        &load_arduino_v_13_B.b_scanned1_l);
      if (load_arduino_v_13_B.idx_a != 1) {
        load_arduino_v_13_B.b_scanned1_l = (rtNaN);
      }
    }

    if (isimag1) {
      x.re = load_arduino_v_13_B.scanned2_o;
      x.im = load_arduino_v_13_B.b_scanned1_l;
    } else {
      x.re = load_arduino_v_13_B.b_scanned1_l;
      x.im = load_arduino_v_13_B.scanned2_o;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S978>/MATLAB Function' */
static real_T load_arduino_v_13_hex2dec(const char_T s[2])
{
  real_T x;
  int32_T p16;
  int32_T s_0;
  x = 0.0;
  p16 = 1;
  if (s[1] != ' ') {
    s_0 = (uint8_T)s[1];
    if ((s_0 != 0) && (s_0 != 48)) {
      if (s_0 > 57) {
        if (s_0 > 70) {
          s_0 -= 39;
        } else {
          s_0 -= 7;
        }
      }

      x = (real_T)s_0 - 48.0;
    }

    p16 = 16;
  }

  if (s[0] != ' ') {
    s_0 = (uint8_T)s[0];
    if ((s_0 != 0) && (s_0 != 48)) {
      if (s_0 > 57) {
        if (s_0 > 70) {
          s_0 -= 39;
        } else {
          s_0 -= 7;
        }
      }

      x += (real_T)((s_0 - 48) * p16);
    }
  }

  return x;
}

static void load_ardui_SystemCore_release_j(const
  codertarget_arduinobase_int_b_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void load_ard_SystemCore_delete_js1p(const
  codertarget_arduinobase_int_b_T *obj)
{
  load_ardui_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlab_js1p(codertarget_arduinobase_int_b_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    load_ard_SystemCore_delete_js1p(obj);
  }
}

static void matlabCodegenHandle_matlabCo_js(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static codertarget_arduinobase_int_b_T *arduinoI2CRead_arduinoI2CRead_j
  (codertarget_arduinobase_int_b_T *obj)
{
  codertarget_arduinobase_int_b_T *b_obj;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* Model step function for TID0 */
void load_arduino_v_13_step0(void)     /* Sample time: [0.02s, 0.0s] */
{
  uint16_T z;
  uint16_T x;
  uint8_T sts;
  uint8_T status;
  uint8_T output_raw[2];
  uint8_T find_comma;
  char_T ck_ric[2];
  static const char_T ib[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T jb[5] = { 'G', 'P', 'G', 'G', 'A' };

  uint8_T rtb_H_mav[2];
  boolean_T Ap_sel;
  char_T messaggio;
  uint8_T rtb_H_mav_e_idx_1;
  int8_T ii_data_idx_0;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint16_T *rtb_WP_db_info_0;
  boolean_T guard1 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  int32_T exitg3;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Mti): '<S965>/S-Function Builder' incorporates:
   *  Constant: '<S965>/Constant1'
   */
  Mti_Outputs_wrapper(&load_arduino_v_13_P.Constant1_Value_g,
                      &load_arduino_v_13_B.SFunctionBuilder_o1_n[0],
                      &load_arduino_v_13_B.SFunctionBuilder_o2_f,
                      &load_arduino_v_13_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S965>/MATLAB Function1' incorporates:
   *  Delay: '<S965>/Delay'
   */
  load_arduino_v_13_B.checksum = load_arduino_v_13_B.SFunctionBuilder_o1_n[1];
  for (load_arduino_v_13_B.caso = 0; load_arduino_v_13_B.caso < 39;
       load_arduino_v_13_B.caso++) {
    load_arduino_v_13_B.checksum += (real_T)
      load_arduino_v_13_B.SFunctionBuilder_o1_n[load_arduino_v_13_B.caso + 2];
  }

  for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 13;
       load_arduino_v_13_B.firstcol++) {
    load_arduino_v_13_B.hex_checksum_data[load_arduino_v_13_B.firstcol] = '0';
  }

  load_arduino_v_13_B.caso = 13;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_13_B.caso > 0)) {
    load_arduino_v_13_B.r = load_arduino_v_13_B.checksum;
    load_arduino_v_13_B.checksum = floor(load_arduino_v_13_B.checksum / 16.0);
    load_arduino_v_13_B.r -= load_arduino_v_13_B.checksum * 16.0;
    if (load_arduino_v_13_B.r > 9.0) {
      load_arduino_v_13_B.r += 7.0;
    }

    load_arduino_v_13_B.hex_checksum_data[load_arduino_v_13_B.caso - 1] =
      (int8_T)((uint16_T)load_arduino_v_13_B.r + 48U);
    if (load_arduino_v_13_B.checksum > 0.0) {
      load_arduino_v_13_B.caso--;
    } else {
      exitg1 = true;
    }
  }

  load_arduino_v_13_B.firstcol = 13;
  load_arduino_v_13_B.AL = 0;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_13_B.AL < 12)) {
    Ap_sel = false;
    if (load_arduino_v_13_B.hex_checksum_data[load_arduino_v_13_B.AL] != '0') {
      Ap_sel = true;
    }

    if (Ap_sel) {
      load_arduino_v_13_B.firstcol = load_arduino_v_13_B.AL + 1;
      exitg1 = true;
    } else {
      load_arduino_v_13_B.AL++;
    }
  }

  if (load_arduino_v_13_B.firstcol > 1) {
    load_arduino_v_13_B.AL = load_arduino_v_13_B.firstcol;
    while (load_arduino_v_13_B.AL < 14) {
      load_arduino_v_13_B.hex_checksum_data[load_arduino_v_13_B.AL -
        load_arduino_v_13_B.firstcol] =
        load_arduino_v_13_B.hex_checksum_data[load_arduino_v_13_B.AL - 1];
      load_arduino_v_13_B.AL++;
    }

    load_arduino_v_13_B.caso = 14 - load_arduino_v_13_B.firstcol;
    if (0 <= load_arduino_v_13_B.caso - 1) {
      memcpy(&load_arduino_v_13_B.hex_checksum_data_c[0],
             &load_arduino_v_13_B.hex_checksum_data[0], load_arduino_v_13_B.caso
             * sizeof(char_T));
      memcpy(&load_arduino_v_13_B.hex_checksum_data[0],
             &load_arduino_v_13_B.hex_checksum_data_c[0],
             load_arduino_v_13_B.caso * sizeof(char_T));
    }
  }

  if ((load_arduino_v_13_B.hex_checksum_data[2] == '0') &&
      (load_arduino_v_13_B.hex_checksum_data[3] == '0')) {
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 41;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.Mex_out[load_arduino_v_13_B.i] =
        load_arduino_v_13_B.SFunctionBuilder_o1_n[load_arduino_v_13_B.i];
    }
  } else {
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 41;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.Mex_out[load_arduino_v_13_B.i] =
        load_arduino_v_13_DW.Delay_DSTATE[load_arduino_v_13_B.i];
    }
  }

  /* End of MATLAB Function: '<S965>/MATLAB Function1' */

  /* S-Function (byte2any_svd): '<S965>/Byte Unpack' */

  /* Unpack: <S965>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o1[0], (uint8_T*)
             &load_arduino_v_13_B.Mex_out[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o2[0], (uint8_T*)
             &load_arduino_v_13_B.Mex_out[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o3_p, (uint8_T*)
             &load_arduino_v_13_B.Mex_out[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S965>/Byte Reversal' */

  /* ReverseEndian: <S965>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &load_arduino_v_13_B.ByteUnpack_o2[0];
    real32_T *y0 = &load_arduino_v_13_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S963>/One_time_initialization' */
  /* Logic: '<S963>/Logical Operator1' incorporates:
   *  UnitDelay: '<S963>/Unit Delay'
   */
  loa_One_time_initialization(!load_arduino_v_13_DW.UnitDelay_DSTATE_d,
    &load_arduino_v_13_B.One_time_initialization,
    &load_arduino_v_13_DW.One_time_initialization,
    &load_arduino_v_13_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S963>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S963>/Execution_loop' incorporates:
   *  EnablePort: '<S968>/Enable'
   */
  /* UnitDelay: '<S963>/Unit Delay' */
  if (load_arduino_v_13_DW.UnitDelay_DSTATE_d) {
    /* MATLABSystem: '<S968>/I2C Read12' */
    if (load_arduino_v_13_DW.obj_f.SampleTime != load_arduino_v_13_P.t_AP) {
      load_arduino_v_13_DW.obj_f.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite(load_arduino_v_13_DW.obj_f.MW_I2C_HANDLE, 118U,
      &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(load_arduino_v_13_DW.obj_f.MW_I2C_HANDLE, 118U,
                        output_raw, 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S968>/I2C Read1' */
    if (load_arduino_v_13_DW.obj_p.SampleTime != load_arduino_v_13_P.t_AP) {
      load_arduino_v_13_DW.obj_p.SampleTime = load_arduino_v_13_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite(load_arduino_v_13_DW.obj_p.MW_I2C_HANDLE, 118U,
      &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(load_arduino_v_13_DW.obj_p.MW_I2C_HANDLE, 118U,
                        load_arduino_v_13_B.output_raw, 3U, false, true);
      memcpy((void *)&load_arduino_v_13_B.output[0], (void *)
             &load_arduino_v_13_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
              (uint8_T)));
    } else {
      load_arduino_v_13_B.output[0] = 0U;
      load_arduino_v_13_B.output[1] = 0U;
      load_arduino_v_13_B.output[2] = 0U;
    }

    /* ArithShift: '<S968>/Shift Arithmetic4' incorporates:
     *  Constant: '<S968>/Constant1'
     */
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant1_Value_o);
    if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf
        (load_arduino_v_13_B.Sum4_n)) {
      load_arduino_v_13_B.Sum4_n = 0.0;
    } else {
      load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n,
        4.294967296E+9);
    }

    /* ArithShift: '<S968>/Shift Arithmetic3' incorporates:
     *  Constant: '<S968>/Constant5'
     */
    load_arduino_v_13_B.Sum3_o = floor(load_arduino_v_13_P.Constant5_Value_n);
    if (rtIsNaN(load_arduino_v_13_B.Sum3_o) || rtIsInf
        (load_arduino_v_13_B.Sum3_o)) {
      load_arduino_v_13_B.Sum3_o = 0.0;
    } else {
      load_arduino_v_13_B.Sum3_o = fmod(load_arduino_v_13_B.Sum3_o,
        4.294967296E+9);
    }

    /* ArithShift: '<S968>/Shift Arithmetic1' incorporates:
     *  Constant: '<S968>/Constant6'
     */
    load_arduino_v_13_B.Abs1_b = floor(load_arduino_v_13_P.Constant6_Value);
    if (rtIsNaN(load_arduino_v_13_B.Abs1_b) || rtIsInf
        (load_arduino_v_13_B.Abs1_b)) {
      load_arduino_v_13_B.Abs1_b = 0.0;
    } else {
      load_arduino_v_13_B.Abs1_b = fmod(load_arduino_v_13_B.Abs1_b,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S968>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S968>/Shift Arithmetic1'
     *  ArithShift: '<S968>/Shift Arithmetic3'
     *  ArithShift: '<S968>/Shift Arithmetic4'
     *  Constant: '<S968>/Constant10'
     *  Constant: '<S968>/Constant11'
     *  Constant: '<S968>/Constant7'
     *  MATLABSystem: '<S968>/I2C Read1'
     *  Sum: '<S968>/Sum1'
     *  Sum: '<S968>/Sum4'
     *  Sum: '<S968>/Sum5'
     *  Sum: '<S968>/Sum6'
     */
    load_arduino_v_13_B.DataTypeConversion1_i = (int32_T)
      ((((((load_arduino_v_13_P.Constant7_Value_h + load_arduino_v_13_B.output[0])
           << (load_arduino_v_13_B.Sum4_n < 0.0 ? -(int32_T)(uint32_T)
               -load_arduino_v_13_B.Sum4_n : (int32_T)(uint32_T)
               load_arduino_v_13_B.Sum4_n)) +
          ((load_arduino_v_13_P.Constant10_Value + load_arduino_v_13_B.output[1])
           << (load_arduino_v_13_B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
               -load_arduino_v_13_B.Sum3_o : (int32_T)(uint32_T)
               load_arduino_v_13_B.Sum3_o))) +
         load_arduino_v_13_P.Constant11_Value) + load_arduino_v_13_B.output[2]) >>
       (load_arduino_v_13_B.Abs1_b < 0.0 ? -(int32_T)(uint32_T)
        -load_arduino_v_13_B.Abs1_b : (int32_T)(uint32_T)
        load_arduino_v_13_B.Abs1_b));

    /* ArithShift: '<S968>/Shift Arithmetic7' incorporates:
     *  Constant: '<S968>/Constant2'
     */
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant2_Value_a);
    if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf
        (load_arduino_v_13_B.Sum4_n)) {
      load_arduino_v_13_B.Sum4_n = 0.0;
    } else {
      load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n,
        4.294967296E+9);
    }

    /* ArithShift: '<S968>/Shift Arithmetic6' incorporates:
     *  Constant: '<S968>/Constant3'
     */
    load_arduino_v_13_B.Sum3_o = floor(load_arduino_v_13_P.Constant3_Value_c0);
    if (rtIsNaN(load_arduino_v_13_B.Sum3_o) || rtIsInf
        (load_arduino_v_13_B.Sum3_o)) {
      load_arduino_v_13_B.Sum3_o = 0.0;
    } else {
      load_arduino_v_13_B.Sum3_o = fmod(load_arduino_v_13_B.Sum3_o,
        4.294967296E+9);
    }

    /* ArithShift: '<S968>/Shift Arithmetic2' incorporates:
     *  Constant: '<S968>/Constant4'
     */
    load_arduino_v_13_B.Abs1_b = floor(load_arduino_v_13_P.Constant4_Value_l);
    if (rtIsNaN(load_arduino_v_13_B.Abs1_b) || rtIsInf
        (load_arduino_v_13_B.Abs1_b)) {
      load_arduino_v_13_B.Abs1_b = 0.0;
    } else {
      load_arduino_v_13_B.Abs1_b = fmod(load_arduino_v_13_B.Abs1_b,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S968>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S968>/Shift Arithmetic2'
     *  ArithShift: '<S968>/Shift Arithmetic6'
     *  ArithShift: '<S968>/Shift Arithmetic7'
     *  Constant: '<S968>/Constant8'
     *  Constant: '<S968>/Constant9'
     *  MATLABSystem: '<S968>/I2C Read12'
     *  Sum: '<S968>/Sum'
     *  Sum: '<S968>/Sum2'
     *  Sum: '<S968>/Sum3'
     */
    load_arduino_v_13_B.DataTypeConversion_ay = (int32_T)
      ((((load_arduino_v_13_P.Constant8_Value_et + rtb_H_mav[0]) <<
         (load_arduino_v_13_B.Sum4_n < 0.0 ? -(int32_T)(uint32_T)
          -load_arduino_v_13_B.Sum4_n : (int32_T)(uint32_T)
          load_arduino_v_13_B.Sum4_n)) + ((load_arduino_v_13_P.Constant9_Value +
          rtb_H_mav[1]) << (load_arduino_v_13_B.Sum3_o < 0.0 ? -(int32_T)
          (uint32_T)-load_arduino_v_13_B.Sum3_o : (int32_T)(uint32_T)
          load_arduino_v_13_B.Sum3_o))) >> (load_arduino_v_13_B.Abs1_b < 0.0 ?
        -(int32_T)(uint32_T)-load_arduino_v_13_B.Abs1_b : (int32_T)(uint32_T)
        load_arduino_v_13_B.Abs1_b));

    /* S-Function (calc_T): '<S968>/S-Function Builder' */
    calc_T_Outputs_wrapper(&load_arduino_v_13_B.One_time_initialization.I2CRead,
      &load_arduino_v_13_B.One_time_initialization.I2CRead1,
      &load_arduino_v_13_B.One_time_initialization.I2CRead2,
      &load_arduino_v_13_B.DataTypeConversion_ay,
      &load_arduino_v_13_B.SFunctionBuilder_o1,
      &load_arduino_v_13_B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S968>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&load_arduino_v_13_B.One_time_initialization.I2CRead3,
      &load_arduino_v_13_B.One_time_initialization.I2CRead4,
      &load_arduino_v_13_B.One_time_initialization.I2CRead5,
      &load_arduino_v_13_B.One_time_initialization.I2CRead6,
      &load_arduino_v_13_B.One_time_initialization.I2CRead7,
      &load_arduino_v_13_B.One_time_initialization.I2CRead8,
      &load_arduino_v_13_B.One_time_initialization.I2CRead9,
      &load_arduino_v_13_B.One_time_initialization.I2CRead10,
      &load_arduino_v_13_B.One_time_initialization.I2CRead11,
      &load_arduino_v_13_B.DataTypeConversion1_i,
      &load_arduino_v_13_B.SFunctionBuilder_o2_a,
      &load_arduino_v_13_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S963>/Execution_loop' */

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&load_arduino_v_13_P.Constant1_Value_a,
    &load_arduino_v_13_B.SFunctionBuilder_o1_h[0],
    &load_arduino_v_13_B.SFunctionBuilder_o2,
    &load_arduino_v_13_DW.SFunctionBuilder_DSTATE_l);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  load_arduino_v_13_B.AL = 0;
  load_arduino_v_13_B.caso = 0;
  memset(&load_arduino_v_13_B.messaggio_b[0], 0, 100U * sizeof(uint8_T));
  memset(&load_arduino_v_13_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  load_arduino_v_13_find_254(load_arduino_v_13_B.SFunctionBuilder_o1_h,
    load_arduino_v_13_B.lat_end, &load_arduino_v_13_B.checksum);
  if (load_arduino_v_13_DW.Interr_parz && (load_arduino_v_13_B.checksum == 1.0))
  {
    load_arduino_v_13_B.firstcol = (int32_T)(load_arduino_v_13_DW.counter_m + 1U);
    if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
      load_arduino_v_13_B.firstcol = 255;
    }

    if (load_arduino_v_13_B.lat_end[0] != load_arduino_v_13_B.firstcol) {
      load_arduino_v_13_B.checksum = 0.0;
    }
  }

  Ap_sel = !load_arduino_v_13_DW.Interr_parz;
  if ((load_arduino_v_13_B.checksum == 1.0) && Ap_sel) {
    load_arduino_v_13_B.caso = 1;
  } else if ((load_arduino_v_13_B.checksum == 0.0) &&
             load_arduino_v_13_DW.Interr_parz) {
    load_arduino_v_13_B.caso = 2;
  } else if ((load_arduino_v_13_B.checksum == 1.0) &&
             load_arduino_v_13_DW.Interr_parz) {
    load_arduino_v_13_B.caso = 3;
  } else {
    if ((load_arduino_v_13_B.checksum == 2.0) && Ap_sel) {
      load_arduino_v_13_B.caso = 4;
    }
  }

  switch (load_arduino_v_13_B.caso) {
   case 1:
    load_arduino_v_13_B.Sum4_n = load_arduino_v_13_B.lat_end[(int32_T)
      load_arduino_v_13_B.checksum - 1];
    if (load_arduino_v_13_B.Sum4_n == 100.0) {
      load_arduino_v_13_DW.message_m[0] =
        load_arduino_v_13_B.SFunctionBuilder_o1_h[99];
      load_arduino_v_13_DW.Interr_parz = true;
    } else if (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
               (load_arduino_v_13_B.Sum4_n + 1.0) - 1] <= 100) {
      load_arduino_v_13_B.firstcol = (int32_T)
        (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_13_B.lat_end[0] + 1.0) - 1] + 8U);
      load_arduino_v_13_B.i = load_arduino_v_13_B.firstcol;
      if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
        load_arduino_v_13_B.i = 255;
      }

      if (load_arduino_v_13_B.i == load_arduino_v_13_B.SFunctionBuilder_o2) {
        load_arduino_v_13_B.Sum3_o = rt_roundd_snf(load_arduino_v_13_B.Sum4_n);
        if (load_arduino_v_13_B.Sum3_o < 256.0) {
          if (load_arduino_v_13_B.Sum3_o >= 0.0) {
            status = (uint8_T)load_arduino_v_13_B.Sum3_o;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        load_arduino_v_13_B.firstcol = (int32_T)
          (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
           (load_arduino_v_13_B.lat_end[(int32_T)load_arduino_v_13_B.checksum -
            1] + 1.0) - 1] + 7U);
        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.Sum4_n +
          (real_T)load_arduino_v_13_B.firstcol);
        if (load_arduino_v_13_B.Sum4_n < 256.0) {
          if (load_arduino_v_13_B.Sum4_n >= 0.0) {
            rtb_H_mav_e_idx_1 = (uint8_T)load_arduino_v_13_B.Sum4_n;
          } else {
            rtb_H_mav_e_idx_1 = 0U;
          }
        } else {
          rtb_H_mav_e_idx_1 = MAX_uint8_T;
        }

        if (status > rtb_H_mav_e_idx_1) {
          load_arduino_v_13_B.AL = 1;
          load_arduino_v_13_B.caso = 0;
        } else {
          load_arduino_v_13_B.AL = status;
          load_arduino_v_13_B.caso = rtb_H_mav_e_idx_1;
        }

        load_arduino_v_13_B.caso -= load_arduino_v_13_B.AL;
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
             load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.firstcol] =
            load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.AL +
            load_arduino_v_13_B.firstcol) - 1];
        }

        load_arduino_v_13_B.AL = 1;
        for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 100;
             load_arduino_v_13_B.i++) {
          load_arduino_v_13_B.messaggio_b[load_arduino_v_13_B.i] =
            load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i];
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i] = 0U;
        }

        load_arduino_v_13_DW.counter_m = 0U;
        load_arduino_v_13_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        if (load_arduino_v_13_B.firstcol >
            load_arduino_v_13_B.SFunctionBuilder_o2) {
          load_arduino_v_13_DW.mess_len =
            load_arduino_v_13_B.SFunctionBuilder_o2;
          if (load_arduino_v_13_B.Sum4_n > load_arduino_v_13_DW.mess_len) {
            load_arduino_v_13_B.i = 1;
            load_arduino_v_13_B.tolleranza_distWP_fut = 0;
          } else {
            load_arduino_v_13_B.i = (int32_T)load_arduino_v_13_B.Sum4_n;
            load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
              load_arduino_v_13_DW.mess_len;
          }

          load_arduino_v_13_B.caso = load_arduino_v_13_B.tolleranza_distWP_fut -
            load_arduino_v_13_B.i;
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
               load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_DW.message_m[load_arduino_v_13_B.firstcol] =
              load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.i +
              load_arduino_v_13_B.firstcol) - 1];
          }

          load_arduino_v_13_B.firstcol = (int32_T)
            (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
             (load_arduino_v_13_B.lat_end[(int32_T)load_arduino_v_13_B.checksum
              - 1] + 1.0) - 1] + 8U);
          if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
            load_arduino_v_13_B.firstcol = 255;
          }

          load_arduino_v_13_B.Sum4_n = rt_roundd_snf((real_T)
            load_arduino_v_13_B.firstcol - load_arduino_v_13_DW.mess_len);
          if (load_arduino_v_13_B.Sum4_n < 256.0) {
            if (load_arduino_v_13_B.Sum4_n >= 0.0) {
              load_arduino_v_13_DW.counter_m = (uint8_T)
                load_arduino_v_13_B.Sum4_n;
            } else {
              load_arduino_v_13_DW.counter_m = 0U;
            }
          } else {
            load_arduino_v_13_DW.counter_m = MAX_uint8_T;
          }

          load_arduino_v_13_DW.Interr_parz = true;
        }
      }
    } else {
      load_arduino_v_13_DW.Interr_parz = false;
      memset(&load_arduino_v_13_DW.message_m[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_13_DW.counter_m = 0U;
      load_arduino_v_13_DW.mess_len = 0.0;
      load_arduino_v_13_B.AL = 1;
    }
    break;

   case 2:
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.x[load_arduino_v_13_B.firstcol] =
        (load_arduino_v_13_B.SFunctionBuilder_o1_h[load_arduino_v_13_B.firstcol]
         != 0);
    }

    if (load_arduino_v_13_ifWhileCond(load_arduino_v_13_B.x)) {
      load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_DW.mess_len +
        1.0);
      if (load_arduino_v_13_B.Sum4_n < 256.0) {
        if (load_arduino_v_13_B.Sum4_n >= 0.0) {
          rtb_H_mav_e_idx_1 = (uint8_T)load_arduino_v_13_B.Sum4_n;
        } else {
          rtb_H_mav_e_idx_1 = 0U;
        }
      } else {
        rtb_H_mav_e_idx_1 = MAX_uint8_T;
      }

      load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_DW.mess_len +
        (real_T)load_arduino_v_13_DW.counter_m);
      if (load_arduino_v_13_B.Sum4_n < 256.0) {
        if (load_arduino_v_13_B.Sum4_n >= 0.0) {
          status = (uint8_T)load_arduino_v_13_B.Sum4_n;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      if (rtb_H_mav_e_idx_1 > status) {
        load_arduino_v_13_B.AL = 0;
      } else {
        load_arduino_v_13_B.AL = rtb_H_mav_e_idx_1 - 1;
      }

      if (1 > load_arduino_v_13_DW.counter_m) {
        load_arduino_v_13_B.firstcol = 0;
      } else {
        load_arduino_v_13_B.firstcol = load_arduino_v_13_DW.counter_m;
      }

      load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
      for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
           load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
        load_arduino_v_13_DW.message_m[load_arduino_v_13_B.AL +
          load_arduino_v_13_B.firstcol] =
          load_arduino_v_13_B.SFunctionBuilder_o1_h[load_arduino_v_13_B.firstcol];
      }

      load_arduino_v_13_DW.Interr_parz = false;
      load_arduino_v_13_B.AL = 1;
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 100;
           load_arduino_v_13_B.i++) {
        load_arduino_v_13_B.messaggio_b[load_arduino_v_13_B.i] =
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i];
        load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i] = 0U;
      }

      load_arduino_v_13_DW.mess_len = 0.0;
      load_arduino_v_13_DW.counter_m = 0U;
    } else {
      load_arduino_v_13_DW.Interr_parz = false;
      load_arduino_v_13_B.AL = 1;
      memset(&load_arduino_v_13_DW.message_m[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_13_DW.mess_len = 0.0;
      load_arduino_v_13_DW.counter_m = 0U;
    }
    break;

   case 3:
    load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_DW.mess_len +
      1.0);
    if (load_arduino_v_13_B.Sum4_n < 256.0) {
      if (load_arduino_v_13_B.Sum4_n >= 0.0) {
        rtb_H_mav_e_idx_1 = (uint8_T)load_arduino_v_13_B.Sum4_n;
      } else {
        rtb_H_mav_e_idx_1 = 0U;
      }
    } else {
      rtb_H_mav_e_idx_1 = MAX_uint8_T;
    }

    load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_DW.mess_len +
      (real_T)load_arduino_v_13_DW.counter_m);
    if (load_arduino_v_13_B.Sum4_n < 256.0) {
      if (load_arduino_v_13_B.Sum4_n >= 0.0) {
        status = (uint8_T)load_arduino_v_13_B.Sum4_n;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    if (rtb_H_mav_e_idx_1 > status) {
      load_arduino_v_13_B.AL = 0;
    } else {
      load_arduino_v_13_B.AL = rtb_H_mav_e_idx_1 - 1;
    }

    if (1 > load_arduino_v_13_DW.counter_m) {
      load_arduino_v_13_B.firstcol = 0;
    } else {
      load_arduino_v_13_B.firstcol = load_arduino_v_13_DW.counter_m;
    }

    load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
         load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_DW.message_m[load_arduino_v_13_B.AL +
        load_arduino_v_13_B.firstcol] =
        load_arduino_v_13_B.SFunctionBuilder_o1_h[load_arduino_v_13_B.firstcol];
    }

    load_arduino_v_13_DW.Interr_parz = false;
    load_arduino_v_13_B.AL = 1;
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 100;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.messaggio_b[load_arduino_v_13_B.i] =
        load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i];
      load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i] = 0U;
    }

    load_arduino_v_13_DW.mess_len = 0.0;
    load_arduino_v_13_DW.counter_m = 0U;
    if (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
        (load_arduino_v_13_B.lat_end[(int32_T)load_arduino_v_13_B.checksum - 1]
         + 1.0) - 1] <= 100) {
      load_arduino_v_13_B.firstcol = (int32_T)
        (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_13_B.lat_end[0] + 1.0) - 1] + 8U);
      if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
        load_arduino_v_13_B.firstcol = 255;
      }

      load_arduino_v_13_B.i = load_arduino_v_13_B.SFunctionBuilder_o2;
      if (load_arduino_v_13_B.SFunctionBuilder_o2 < 0) {
        load_arduino_v_13_B.i = 0;
      } else {
        if (load_arduino_v_13_B.SFunctionBuilder_o2 > 255) {
          load_arduino_v_13_B.i = 255;
        }
      }

      if (load_arduino_v_13_B.firstcol == load_arduino_v_13_B.i) {
        load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end
          [(int32_T)load_arduino_v_13_B.checksum - 1]);
        if (load_arduino_v_13_B.Sum4_n < 256.0) {
          if (load_arduino_v_13_B.Sum4_n >= 0.0) {
            status = (uint8_T)load_arduino_v_13_B.Sum4_n;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        load_arduino_v_13_B.firstcol = (int32_T)
          (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
           (load_arduino_v_13_B.lat_end[(int32_T)load_arduino_v_13_B.checksum -
            1] + 1.0) - 1] + 7U);
        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end
          [(int32_T)load_arduino_v_13_B.checksum - 1] + (real_T)
          load_arduino_v_13_B.firstcol);
        if (load_arduino_v_13_B.Sum4_n < 256.0) {
          if (load_arduino_v_13_B.Sum4_n >= 0.0) {
            rtb_H_mav_e_idx_1 = (uint8_T)load_arduino_v_13_B.Sum4_n;
          } else {
            rtb_H_mav_e_idx_1 = 0U;
          }
        } else {
          rtb_H_mav_e_idx_1 = MAX_uint8_T;
        }

        if (status > rtb_H_mav_e_idx_1) {
          load_arduino_v_13_B.i = 1;
          load_arduino_v_13_B.caso = 0;
        } else {
          load_arduino_v_13_B.i = status;
          load_arduino_v_13_B.caso = rtb_H_mav_e_idx_1;
        }

        load_arduino_v_13_B.caso -= load_arduino_v_13_B.i;
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
             load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.firstcol] =
            load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.i +
            load_arduino_v_13_B.firstcol) - 1];
        }

        for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 100;
             load_arduino_v_13_B.i++) {
          load_arduino_v_13_B.messaggio_2[load_arduino_v_13_B.i] =
            load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i];
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i] = 0U;
        }

        load_arduino_v_13_DW.counter_m = 0U;
        load_arduino_v_13_DW.mess_len = 0.0;
      } else {
        load_arduino_v_13_B.firstcol = (int32_T)
          (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
           (load_arduino_v_13_B.lat_end[0] + 1.0) - 1] + 8U);
        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        load_arduino_v_13_B.i = load_arduino_v_13_B.SFunctionBuilder_o2;
        if (load_arduino_v_13_B.SFunctionBuilder_o2 < 0) {
          load_arduino_v_13_B.i = 0;
        } else {
          if (load_arduino_v_13_B.SFunctionBuilder_o2 > 255) {
            load_arduino_v_13_B.i = 255;
          }
        }

        if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.i) {
          load_arduino_v_13_DW.mess_len =
            load_arduino_v_13_B.SFunctionBuilder_o2;
          if (load_arduino_v_13_B.lat_end[(int32_T)load_arduino_v_13_B.checksum
              - 1] > load_arduino_v_13_DW.mess_len) {
            load_arduino_v_13_B.i = 1;
            load_arduino_v_13_B.caso = 0;
          } else {
            load_arduino_v_13_B.i = (int32_T)load_arduino_v_13_B.lat_end
              [(int32_T)load_arduino_v_13_B.checksum - 1];
            load_arduino_v_13_B.caso = (int32_T)load_arduino_v_13_DW.mess_len;
          }

          load_arduino_v_13_B.caso -= load_arduino_v_13_B.i;
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
               load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_DW.message_m[load_arduino_v_13_B.firstcol] =
              load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.i +
              load_arduino_v_13_B.firstcol) - 1];
          }

          load_arduino_v_13_B.firstcol = (int32_T)
            (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
             (load_arduino_v_13_B.lat_end[(int32_T)load_arduino_v_13_B.checksum
              - 1] + 1.0) - 1] + 8U);
          if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
            load_arduino_v_13_B.firstcol = 255;
          }

          load_arduino_v_13_B.Sum4_n = rt_roundd_snf((real_T)
            load_arduino_v_13_B.firstcol - load_arduino_v_13_DW.mess_len);
          if (load_arduino_v_13_B.Sum4_n < 256.0) {
            if (load_arduino_v_13_B.Sum4_n >= 0.0) {
              load_arduino_v_13_DW.counter_m = (uint8_T)
                load_arduino_v_13_B.Sum4_n;
            } else {
              load_arduino_v_13_DW.counter_m = 0U;
            }
          } else {
            load_arduino_v_13_DW.counter_m = MAX_uint8_T;
          }

          load_arduino_v_13_DW.Interr_parz = true;
        }
      }
    } else {
      load_arduino_v_13_DW.Interr_parz = false;
      memset(&load_arduino_v_13_B.messaggio_b[0], 0, 100U * sizeof(uint8_T));
      memset(&load_arduino_v_13_DW.message_m[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_13_DW.counter_m = 0U;
      load_arduino_v_13_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
        (load_arduino_v_13_B.lat_end[0] + 1.0) - 1] <= 100) {
      load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end[0]);
      if (load_arduino_v_13_B.Sum4_n < 256.0) {
        if (load_arduino_v_13_B.Sum4_n >= 0.0) {
          status = (uint8_T)load_arduino_v_13_B.Sum4_n;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      load_arduino_v_13_B.firstcol = (int32_T)
        (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_13_B.lat_end[0] + 1.0) - 1] + 7U);
      if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
        load_arduino_v_13_B.firstcol = 255;
      }

      load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end[0]
        + (real_T)load_arduino_v_13_B.firstcol);
      if (load_arduino_v_13_B.Sum4_n < 256.0) {
        if (load_arduino_v_13_B.Sum4_n >= 0.0) {
          rtb_H_mav_e_idx_1 = (uint8_T)load_arduino_v_13_B.Sum4_n;
        } else {
          rtb_H_mav_e_idx_1 = 0U;
        }
      } else {
        rtb_H_mav_e_idx_1 = MAX_uint8_T;
      }

      if (status > rtb_H_mav_e_idx_1) {
        load_arduino_v_13_B.AL = 1;
        load_arduino_v_13_B.firstcol = 0;
      } else {
        load_arduino_v_13_B.AL = status;
        load_arduino_v_13_B.firstcol = rtb_H_mav_e_idx_1;
      }

      load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol -
        load_arduino_v_13_B.AL;
      for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
           load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
        load_arduino_v_13_B.messaggio_b[load_arduino_v_13_B.firstcol] =
          load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.AL +
          load_arduino_v_13_B.firstcol) - 1];
      }
    } else {
      load_arduino_v_13_DW.Interr_parz = false;
      memset(&load_arduino_v_13_DW.message_m[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_13_DW.counter_m = 0U;
      load_arduino_v_13_DW.mess_len = 0.0;
    }

    load_arduino_v_13_B.AL = 1;
    if ((load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_13_B.lat_end[1] + 1.0) - 1] <= 100) &&
        (load_arduino_v_13_B.lat_end[1] - load_arduino_v_13_B.lat_end[0] > 3.0))
    {
      load_arduino_v_13_B.Sum4_n = rt_roundd_snf((real_T)
        load_arduino_v_13_B.SFunctionBuilder_o2 - load_arduino_v_13_B.lat_end[1]);
      load_arduino_v_13_B.firstcol = (int32_T)
        (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_13_B.lat_end[1] + 1.0) - 1] + 7U);
      load_arduino_v_13_B.i = load_arduino_v_13_B.firstcol;
      if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
        load_arduino_v_13_B.i = 255;
      }

      if (load_arduino_v_13_B.Sum4_n < 2.147483648E+9) {
        if (load_arduino_v_13_B.Sum4_n >= -2.147483648E+9) {
          load_arduino_v_13_B.caso = (int32_T)load_arduino_v_13_B.Sum4_n;
        } else {
          load_arduino_v_13_B.caso = MIN_int32_T;
        }
      } else {
        load_arduino_v_13_B.caso = MAX_int32_T;
      }

      if (load_arduino_v_13_B.caso == load_arduino_v_13_B.i) {
        load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end[1]);
        if (load_arduino_v_13_B.Sum4_n < 256.0) {
          if (load_arduino_v_13_B.Sum4_n >= 0.0) {
            status = (uint8_T)load_arduino_v_13_B.Sum4_n;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end[1]
          + (real_T)load_arduino_v_13_B.firstcol);
        if (load_arduino_v_13_B.Sum4_n < 256.0) {
          if (load_arduino_v_13_B.Sum4_n >= 0.0) {
            rtb_H_mav_e_idx_1 = (uint8_T)load_arduino_v_13_B.Sum4_n;
          } else {
            rtb_H_mav_e_idx_1 = 0U;
          }
        } else {
          rtb_H_mav_e_idx_1 = MAX_uint8_T;
        }

        if (status > rtb_H_mav_e_idx_1) {
          load_arduino_v_13_B.AL = 1;
          load_arduino_v_13_B.firstcol = 0;
        } else {
          load_arduino_v_13_B.AL = status;
          load_arduino_v_13_B.firstcol = rtb_H_mav_e_idx_1;
        }

        load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol -
          load_arduino_v_13_B.AL;
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
             load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.firstcol] =
            load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.AL +
            load_arduino_v_13_B.firstcol) - 1];
        }

        load_arduino_v_13_B.AL = 2;
        for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 100;
             load_arduino_v_13_B.i++) {
          load_arduino_v_13_B.messaggio_2[load_arduino_v_13_B.i] =
            load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i];
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.i] = 0U;
        }

        load_arduino_v_13_DW.counter_m = 0U;
        load_arduino_v_13_DW.mess_len = 0.0;
      } else {
        load_arduino_v_13_B.Sum4_n = rt_roundd_snf(load_arduino_v_13_B.lat_end[1]);
        if (load_arduino_v_13_B.Sum4_n < 2.147483648E+9) {
          if (load_arduino_v_13_B.Sum4_n >= -2.147483648E+9) {
            load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.Sum4_n;
          } else {
            load_arduino_v_13_B.firstcol = MIN_int32_T;
          }
        } else {
          load_arduino_v_13_B.firstcol = MAX_int32_T;
        }

        if (load_arduino_v_13_B.firstcol >
            load_arduino_v_13_B.SFunctionBuilder_o2) {
          load_arduino_v_13_B.firstcol = 1;
          load_arduino_v_13_B.caso = 1;
        } else {
          load_arduino_v_13_B.caso = load_arduino_v_13_B.SFunctionBuilder_o2 + 1;
        }

        load_arduino_v_13_DW.mess_len = load_arduino_v_13_B.caso -
          load_arduino_v_13_B.firstcol;
        if (load_arduino_v_13_B.Sum4_n < 2.147483648E+9) {
          if (load_arduino_v_13_B.Sum4_n >= -2.147483648E+9) {
            load_arduino_v_13_B.i = (int32_T)load_arduino_v_13_B.Sum4_n;
          } else {
            load_arduino_v_13_B.i = MIN_int32_T;
          }
        } else {
          load_arduino_v_13_B.i = MAX_int32_T;
        }

        if (load_arduino_v_13_B.i > load_arduino_v_13_B.SFunctionBuilder_o2) {
          load_arduino_v_13_B.i = 1;
          load_arduino_v_13_B.firstcol = 0;
        } else {
          load_arduino_v_13_B.firstcol = load_arduino_v_13_B.SFunctionBuilder_o2;
        }

        load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol -
          load_arduino_v_13_B.i;
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
             load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_DW.message_m[load_arduino_v_13_B.firstcol] =
            load_arduino_v_13_B.SFunctionBuilder_o1_h[(load_arduino_v_13_B.i +
            load_arduino_v_13_B.firstcol) - 1];
        }

        load_arduino_v_13_B.firstcol = (int32_T)
          (load_arduino_v_13_B.SFunctionBuilder_o1_h[(int32_T)
           (load_arduino_v_13_B.lat_end[1] + 1.0) - 1] + 8U);
        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        load_arduino_v_13_B.Sum4_n = rt_roundd_snf((real_T)
          load_arduino_v_13_B.firstcol - load_arduino_v_13_DW.mess_len);
        if (load_arduino_v_13_B.Sum4_n < 256.0) {
          if (load_arduino_v_13_B.Sum4_n >= 0.0) {
            load_arduino_v_13_DW.counter_m = (uint8_T)load_arduino_v_13_B.Sum4_n;
          } else {
            load_arduino_v_13_DW.counter_m = 0U;
          }
        } else {
          load_arduino_v_13_DW.counter_m = MAX_uint8_T;
        }

        load_arduino_v_13_DW.Interr_parz = true;
      }
    } else {
      load_arduino_v_13_DW.Interr_parz = false;
      memset(&load_arduino_v_13_DW.message_m[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_13_DW.counter_m = 0U;
      load_arduino_v_13_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&load_arduino_v_13_B.buffer[0], 0, 300U * sizeof(uint8_T));
  status = 0U;
  for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
       load_arduino_v_13_B.firstcol++) {
    load_arduino_v_13_B.buffer[3 * load_arduino_v_13_B.firstcol] = 0U;
  }

  for (load_arduino_v_13_B.caso = 0; load_arduino_v_13_B.caso < 2;
       load_arduino_v_13_B.caso++) {
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.buffer[(load_arduino_v_13_B.caso + 3 *
        load_arduino_v_13_B.firstcol) + 1] =
        load_arduino_v_13_DW.Memory4_PreviousInput_c[3 *
        load_arduino_v_13_B.firstcol + load_arduino_v_13_B.caso];
    }
  }

  load_arduino_v_13_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_13_B.i >= 1)) {
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.x[load_arduino_v_13_B.firstcol] =
        (load_arduino_v_13_B.buffer[(3 * load_arduino_v_13_B.firstcol +
          load_arduino_v_13_B.i) - 1] == 0);
    }

    Ap_sel = true;
    load_arduino_v_13_B.caso = 0;
    exitg2 = false;
    while ((!exitg2) && (load_arduino_v_13_B.caso < 100)) {
      if (!load_arduino_v_13_B.x[load_arduino_v_13_B.caso]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        load_arduino_v_13_B.caso++;
      }
    }

    if (Ap_sel) {
      status = (uint8_T)load_arduino_v_13_B.i;
      exitg1 = true;
    } else {
      load_arduino_v_13_B.i--;
    }
  }

  if (load_arduino_v_13_B.AL == 1) {
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.buffer[(status + 3 * load_arduino_v_13_B.firstcol) - 1]
        = load_arduino_v_13_B.messaggio_b[load_arduino_v_13_B.firstcol];
    }
  } else if (load_arduino_v_13_B.AL == 2) {
    load_arduino_v_13_B.qY = status - /*MW:OvSatOk*/ 1U;
    if (load_arduino_v_13_B.qY > status) {
      load_arduino_v_13_B.qY = 0U;
    }

    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.buffer[(status + 3 * load_arduino_v_13_B.firstcol) - 1]
        = load_arduino_v_13_B.messaggio_b[load_arduino_v_13_B.firstcol];
      load_arduino_v_13_B.buffer[((int32_T)load_arduino_v_13_B.qY + 3 *
        load_arduino_v_13_B.firstcol) - 1] =
        load_arduino_v_13_B.messaggio_2[load_arduino_v_13_B.firstcol];
    }
  } else {
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.buffer[(status + 3 * load_arduino_v_13_B.firstcol) - 1]
        = 0U;
    }
  }

  for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
       load_arduino_v_13_B.firstcol++) {
    load_arduino_v_13_B.mess_out[load_arduino_v_13_B.firstcol] =
      load_arduino_v_13_DW.Memory4_PreviousInput_c[3 *
      load_arduino_v_13_B.firstcol + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  load_arduino_v_13_B.Add = load_arduino_v_13_DW.Memory4_PreviousInput_c[5] +
    load_arduino_v_13_P.Constant_Value_gw;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (load_arduino_v_13_B.mess_out[2] !=
      load_arduino_v_13_DW.Memory5_PreviousInput_l[2]) {
    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 100;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_B.x[load_arduino_v_13_B.firstcol] =
        (load_arduino_v_13_B.mess_out[load_arduino_v_13_B.firstcol] != 0);
    }

    Ap_sel = true;
    load_arduino_v_13_B.caso = 0;
    exitg1 = false;
    while ((!exitg1) && (load_arduino_v_13_B.caso < 100)) {
      if (!load_arduino_v_13_B.x[load_arduino_v_13_B.caso]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        load_arduino_v_13_B.caso++;
      }
    }

    if (!Ap_sel) {
      if (load_arduino_v_13_DW.counter > 100) {
        load_arduino_v_13_DW.counter = 0U;
      }

      load_arduino_v_13_B.qY = load_arduino_v_13_DW.counter + 1U;
      if (load_arduino_v_13_B.qY > 65535U) {
        load_arduino_v_13_B.qY = 65535U;
      }

      load_arduino_v_13_DW.counter = (uint16_T)load_arduino_v_13_B.qY;
    }
  }

  load_arduino_v_13_B.new_mex = load_arduino_v_13_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  load_arduino_v_13_B.Memory1[0] = load_arduino_v_13_DW.Memory1_PreviousInput_d
    [0];
  load_arduino_v_13_B.Memory1[1] = load_arduino_v_13_DW.Memory1_PreviousInput_d
    [1];

  /* Memory: '<Root>/Memory' */
  load_arduino_v_13_B.Memory_k[0] =
    load_arduino_v_13_DW.Memory_PreviousInput_h5[0];
  load_arduino_v_13_B.Memory_k[1] =
    load_arduino_v_13_DW.Memory_PreviousInput_h5[1];
  load_arduino_v_13_B.Memory_k[2] =
    load_arduino_v_13_DW.Memory_PreviousInput_h5[2];
  load_arduino_v_13_B.Memory_k[3] =
    load_arduino_v_13_DW.Memory_PreviousInput_h5[3];

  /* Memory: '<S1>/Memory3' */
  load_arduino_v_13_B.Memory3 = load_arduino_v_13_DW.Memory3_PreviousInput_o;

  /* Memory: '<S1>/Memory' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 8;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_B.Memory[load_arduino_v_13_B.i] =
      load_arduino_v_13_DW.Memory_PreviousInput_ic[load_arduino_v_13_B.i];
  }

  /* End of Memory: '<S1>/Memory' */

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&load_arduino_v_13_B.mess_out[0], &load_arduino_v_13_B.Add,
     &load_arduino_v_13_B.new_mex, &load_arduino_v_13_P.SIUAVuint8_Value,
     &load_arduino_v_13_B.Memory[0], &load_arduino_v_13_B.Memory1[0],
     &load_arduino_v_13_B.Memory_k[0], &load_arduino_v_13_B.Memory3,
     &load_arduino_v_13_B.SFunction_o1[0], &load_arduino_v_13_B.SFunction_o2,
     &load_arduino_v_13_B.SFunction_o3_j, &load_arduino_v_13_B.SFunction_o4_n[0],
     &load_arduino_v_13_B.SFunction_o5[0], &load_arduino_v_13_B.SFunction_o6,
     &load_arduino_v_13_B.SFunction_o7[0], &load_arduino_v_13_B.SFunction_o8,
     &load_arduino_v_13_B.SFunction_o9[0], &load_arduino_v_13_B.SFunction_o10[0],
     &load_arduino_v_13_B.SFunction_o11[0], &load_arduino_v_13_B.SFunction_o12,
     &load_arduino_v_13_B.SFunction_o13, &load_arduino_v_13_B.SFunction_o14,
     &load_arduino_v_13_B.SFunction_o15, &load_arduino_v_13_B.SFunction_o16,
     &load_arduino_v_13_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_B.WP_info_in[load_arduino_v_13_B.i] =
      load_arduino_v_13_B.SFunction_o9[load_arduino_v_13_B.i];
  }

  if ((!load_arduino_v_13_DW.WP_dbP_not_empty) ||
      ((load_arduino_v_13_B.SFunction_o7[0] == 3) &&
       (load_arduino_v_13_B.SFunction_o7[1] == 250))) {
    memset(&load_arduino_v_13_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    load_arduino_v_13_DW.WP_dbP_not_empty = true;
    memset(&load_arduino_v_13_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!load_arduino_v_13_DW.WP_dbP_AL_not_empty) ||
      ((load_arduino_v_13_B.SFunction_o7[0] == 3) &&
       (load_arduino_v_13_B.SFunction_o7[1] == 250))) {
    memset(&load_arduino_v_13_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    load_arduino_v_13_DW.WP_dbP_AL_not_empty = true;
  }

  load_arduino_v_13_B.GC_info[0] = load_arduino_v_13_B.SFunction_o7[0];
  load_arduino_v_13_B.GC_info[1] = load_arduino_v_13_B.SFunction_o7[1];
  load_arduino_v_13_B.GC_info[2] = load_arduino_v_13_B.SFunction_o11[0];
  if (load_arduino_v_13_B.GC_info[0] == 1) {
    if ((load_arduino_v_13_B.GC_info[1] > 0) && (load_arduino_v_13_B.GC_info[1] <=
         7)) {
      if ((real32_T)fabs(load_arduino_v_13_B.SFunction_o8) > 0.0F) {
        load_arduino_v_13_DW.riferimenti[load_arduino_v_13_B.GC_info[1] - 1] =
          1.0F;
      } else {
        if (load_arduino_v_13_B.SFunction_o8 == 0.0F) {
          load_arduino_v_13_DW.riferimenti[load_arduino_v_13_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((load_arduino_v_13_B.GC_info[1] > 7) && (load_arduino_v_13_B.GC_info[1]
           < 12)) {
        load_arduino_v_13_DW.riferimenti[load_arduino_v_13_B.GC_info[1] - 1] =
          load_arduino_v_13_B.SFunction_o8;
      }
    }
  }

  if (load_arduino_v_13_B.SFunction_o12 == 13) {
    load_arduino_v_13_DW.riferimenti[load_arduino_v_13_B.SFunction_o12 - 1] =
      load_arduino_v_13_B.SFunction_o13;
  }

  memcpy(&load_arduino_v_13_B.Val_out_MAV[0], &load_arduino_v_13_DW.riferimenti
         [0], sizeof(real32_T) << 4U);
  if ((load_arduino_v_13_B.GC_info[0] == 3) && (load_arduino_v_13_B.GC_info[1] ==
       200)) {
    if (load_arduino_v_13_B.SFunction_o9[0] > 6) {
      load_arduino_v_13_B.WP_info_in[0] = 6U;
    }

    for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 6;
         load_arduino_v_13_B.firstcol++) {
      load_arduino_v_13_DW.WP_dbI[load_arduino_v_13_B.firstcol] =
        load_arduino_v_13_B.WP_info_in[0];
    }
  }

  if ((load_arduino_v_13_B.GC_info[0] == 3) && (load_arduino_v_13_B.GC_info[1] <
       200)) {
    if (load_arduino_v_13_B.SFunction_o10[1] == 0.0F) {
      load_arduino_v_13_B.qY = load_arduino_v_13_B.SFunction_o9[1] + 1U;
      if (load_arduino_v_13_B.qY > 65535U) {
        load_arduino_v_13_B.qY = 65535U;
      }

      load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.qY;
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 7;
           load_arduino_v_13_B.i++) {
        load_arduino_v_13_DW.WP_dbP[(load_arduino_v_13_B.firstcol + 6 *
          load_arduino_v_13_B.i) - 1] =
          load_arduino_v_13_B.SFunction_o10[load_arduino_v_13_B.i];
      }

      load_arduino_v_13_B.qY = load_arduino_v_13_B.SFunction_o9[1] + 1U;
      if (load_arduino_v_13_B.qY > 65535U) {
        load_arduino_v_13_B.qY = 65535U;
      }

      load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.qY;
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
           load_arduino_v_13_B.i++) {
        load_arduino_v_13_DW.WP_dbI[(load_arduino_v_13_B.firstcol + 6 * (1 +
          load_arduino_v_13_B.i)) - 1] = load_arduino_v_13_B.WP_info_in[1 +
          load_arduino_v_13_B.i];
      }
    } else {
      load_arduino_v_13_B.firstcol = (int32_T)
        (load_arduino_v_13_B.SFunction_o10[0] + 1.0F);
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 7;
           load_arduino_v_13_B.i++) {
        load_arduino_v_13_DW.WP_dbP_AL[(load_arduino_v_13_B.firstcol + 6 *
          load_arduino_v_13_B.i) - 1] =
          load_arduino_v_13_B.SFunction_o10[load_arduino_v_13_B.i];
      }

      load_arduino_v_13_B.qY = load_arduino_v_13_B.SFunction_o9[1] + 1U;
      if (load_arduino_v_13_B.qY > 65535U) {
        load_arduino_v_13_B.qY = 65535U;
      }

      load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.qY;
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
           load_arduino_v_13_B.i++) {
        load_arduino_v_13_DW.WP_dbI[(load_arduino_v_13_B.firstcol + 6 * (1 +
          load_arduino_v_13_B.i)) - 1] = load_arduino_v_13_B.WP_info_in[1 +
          load_arduino_v_13_B.i];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  load_arduino_v_13_DW.Memory3_PreviousInput_o = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((load_arduino_v_13_B.SFunction_o6 == 0) &&
      (load_arduino_v_13_B.SFunction_o3_j == 0)) {
    status = 0U;
    rtb_H_mav_e_idx_1 = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_13_DW.Memory3_PreviousInput_o = 0U;
  } else if ((load_arduino_v_13_B.SFunction_o6 == 0) &&
             (load_arduino_v_13_B.SFunction_o3_j == 3)) {
    status = 0U;
    rtb_H_mav_e_idx_1 = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_13_DW.Memory3_PreviousInput_o = 0U;
    load_arduino_v_13_DW.test1 = 0.0;
  } else if ((load_arduino_v_13_B.SFunction_o6 == 0) &&
             (load_arduino_v_13_B.SFunction_o3_j == 2)) {
    status = 0U;
    rtb_H_mav_e_idx_1 = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_13_DW.Memory3_PreviousInput_o = 0U;
    load_arduino_v_13_DW.test1 = 0.0;
  } else if ((load_arduino_v_13_B.SFunction_o6 == 0) &&
             (load_arduino_v_13_B.SFunction_o3_j == 1)) {
    status = 0U;
    rtb_H_mav_e_idx_1 = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_13_DW.Memory3_PreviousInput_o = 0U;
    load_arduino_v_13_DW.test1 = 1.0;
  } else {
    switch (load_arduino_v_13_B.SFunction_o6) {
     case 192:
      status = 192U;
      rtb_H_mav_e_idx_1 = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      load_arduino_v_13_DW.Memory3_PreviousInput_o = 192U;
      break;

     case 208:
      status = 208U;
      rtb_H_mav_e_idx_1 = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      load_arduino_v_13_DW.Memory3_PreviousInput_o = 208U;
      break;

     default:
      if ((load_arduino_v_13_B.SFunction_o6 == 220) &&
          (load_arduino_v_13_B.SFunction_o3_j != 5)) {
        if ((load_arduino_v_13_DW.Memory2_PreviousInput_a[0] == 0) &&
            (load_arduino_v_13_DW.Memory2_PreviousInput_a[1] == 0) &&
            ((load_arduino_v_13_DW.Memory2_PreviousInput_a[2] == 1) ||
             (load_arduino_v_13_DW.Memory2_PreviousInput_a[3] == 1) ||
             (load_arduino_v_13_DW.Memory2_PreviousInput_a[4] == 1) ||
             (load_arduino_v_13_DW.Memory2_PreviousInput_a[5] == 1) ||
             (load_arduino_v_13_DW.Memory2_PreviousInput_a[6] == 1) ||
             (load_arduino_v_13_DW.Memory2_PreviousInput_a[7] == 1))) {
          status = 220U;
          rtb_H_mav_e_idx_1 = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          load_arduino_v_13_DW.Memory3_PreviousInput_o = 220U;
        } else if ((load_arduino_v_13_DW.Memory2_PreviousInput_a[0] == 0) &&
                   (load_arduino_v_13_DW.Memory2_PreviousInput_a[1] == 1) &&
                   ((load_arduino_v_13_DW.Memory2_PreviousInput_a[2] == 1) ||
                    (load_arduino_v_13_DW.Memory2_PreviousInput_a[3] == 1) ||
                    (load_arduino_v_13_DW.Memory2_PreviousInput_a[4] == 1) ||
                    (load_arduino_v_13_DW.Memory2_PreviousInput_a[5] == 1) ||
                    (load_arduino_v_13_DW.Memory2_PreviousInput_a[6] == 1) ||
                    (load_arduino_v_13_DW.Memory2_PreviousInput_a[7] == 1))) {
          status = 220U;
          rtb_H_mav_e_idx_1 = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          load_arduino_v_13_DW.Memory3_PreviousInput_o = 220U;
        } else {
          status = 208U;
          rtb_H_mav_e_idx_1 = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          load_arduino_v_13_DW.Memory3_PreviousInput_o = 208U;
        }
      } else if (load_arduino_v_13_B.SFunction_o3_j == 5) {
        status = 220U;
        rtb_H_mav_e_idx_1 = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        status = 192U;
        rtb_H_mav_e_idx_1 = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  load_arduino_v_13_B.qY = 100U * load_arduino_v_13_B.SFunction_o11[5];
  if (load_arduino_v_13_B.qY > 65535U) {
    load_arduino_v_13_B.qY = 65535U;
  }

  if (load_arduino_v_13_B.SFunction_o11[4] == 0) {
    if ((uint16_T)load_arduino_v_13_B.qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(load_arduino_v_13_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
                   (uint32_T)(uint16_T)load_arduino_v_13_B.qY /
                   load_arduino_v_13_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)load_arduino_v_13_B.qY - (uint16_T)
                   ((uint32_T)z * load_arduino_v_13_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)load_arduino_v_13_B.SFunction_o11[4]
          >> 1) + (load_arduino_v_13_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  load_arduino_v_13_B.AP_int[0] = (uint8_T)AP_mode_idx_0;
  load_arduino_v_13_B.AP_int[1] = (uint8_T)AP_mode_idx_1;
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 7;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_B.f0 = rt_roundf_snf
      (load_arduino_v_13_DW.riferimenti[load_arduino_v_13_B.i]);
    if (load_arduino_v_13_B.f0 < 256.0F) {
      if (load_arduino_v_13_B.f0 >= 0.0F) {
        load_arduino_v_13_B.AP_int[load_arduino_v_13_B.i + 2] = (uint8_T)
          load_arduino_v_13_B.f0;
      } else {
        load_arduino_v_13_B.AP_int[load_arduino_v_13_B.i + 2] = 0U;
      }
    } else {
      load_arduino_v_13_B.AP_int[load_arduino_v_13_B.i + 2] = MAX_uint8_T;
    }
  }

  /* Outputs for Enabled SubSystem: '<S972>/Subsystem1' incorporates:
   *  EnablePort: '<S974>/Enable'
   */
  if (load_arduino_v_13_B.SFunction_o14 > 0) {
    /* Inport: '<S974>/T' */
    load_arduino_v_13_B.T = load_arduino_v_13_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S972>/Subsystem1' */

  /* Switch: '<S972>/Switch1' incorporates:
   *  Constant: '<S972>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  RelationalOperator: '<S972>/NotEqual'
   *  Switch: '<S972>/Switch'
   */
  if (load_arduino_v_13_P.Constant_Value_hx != load_arduino_v_13_DW.riferimenti
      [12]) {
    load_arduino_v_13_B.Switch1_g = load_arduino_v_13_DW.riferimenti[12];
  } else if (load_arduino_v_13_B.T > load_arduino_v_13_P.Switch_Threshold_p) {
    /* Switch: '<S972>/Switch' */
    load_arduino_v_13_B.Switch1_g = load_arduino_v_13_B.T;
  } else {
    load_arduino_v_13_B.Switch1_g = load_arduino_v_13_DW.riferimenti[12];
  }

  /* End of Switch: '<S972>/Switch1' */

  /* RateTransition: '<S29>/Rate Transition' */
  load_arduino_v_13_B.r = load_arduino_v_13_DW.RateTransition_Buffer0;

  /* Sum: '<S29>/Add1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  Memory: '<S29>/Memory1'
   */
  load_arduino_v_13_B.checksum = (load_arduino_v_13_P.Constant2_Value_jg +
    load_arduino_v_13_P.Constant3_Value_o) +
    load_arduino_v_13_DW.Memory1_PreviousInput;

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant2'
   */
  if (load_arduino_v_13_B.checksum > load_arduino_v_13_P.Switch_Threshold_f) {
    load_arduino_v_13_DW.Memory1_PreviousInput =
      load_arduino_v_13_P.Constant2_Value_jg;
  } else {
    load_arduino_v_13_DW.Memory1_PreviousInput = load_arduino_v_13_B.checksum;
  }

  /* End of Switch: '<S29>/Switch' */

  /* MATLAB Function: '<S19>/iflogic_function' */
  if ((load_arduino_v_13_DW.Memory1_PreviousInput == 1.0) ||
      (load_arduino_v_13_DW.Memory1_PreviousInput == 3.0)) {
    load_arduino_v_13_B.iflogic = 26U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 2.0) ||
             (load_arduino_v_13_DW.Memory1_PreviousInput == 4.0)) {
    load_arduino_v_13_B.iflogic = 30U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_13_B.r == 2.0)) {
    load_arduino_v_13_B.iflogic = 33U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_13_B.r == 6.0)) {
    load_arduino_v_13_B.iflogic = 34U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_13_B.r == 0.0)) {
    load_arduino_v_13_B.iflogic = 0U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             ((load_arduino_v_13_B.r == 1.0) || (load_arduino_v_13_B.r == 5.0) ||
              (load_arduino_v_13_B.r == 9.0))) {
    load_arduino_v_13_B.iflogic = 1U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             ((load_arduino_v_13_B.r == 3.0) || (load_arduino_v_13_B.r == 8.0)))
  {
    load_arduino_v_13_B.iflogic = 74U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_13_B.r == 7.0)) {
    load_arduino_v_13_B.iflogic = 36U;
  } else if ((load_arduino_v_13_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_13_B.r == 4.0)) {
    load_arduino_v_13_B.iflogic = 29U;
  } else {
    load_arduino_v_13_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S19>/iflogic_function' */

  /* Sum: '<S29>/Add' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant1'
   *  Memory: '<S29>/Memory'
   */
  load_arduino_v_13_DW.Memory_PreviousInput +=
    load_arduino_v_13_P.Constant_Value_m + load_arduino_v_13_P.Constant1_Value_n;

  /* Gain: '<S19>/Gain' */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_c *
    load_arduino_v_13_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 4.294967296E+9);
  }

  load_arduino_v_13_B.DataTypeConversion3 = load_arduino_v_13_B.Sum4_n < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-load_arduino_v_13_B.Sum4_n : (uint32_T)
    load_arduino_v_13_B.Sum4_n;

  /* End of DataTypeConversion: '<S19>/Data Type Conversion3' */

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 6;
       load_arduino_v_13_B.firstcol++) {
    load_arduino_v_13_B.WP_info[load_arduino_v_13_B.firstcol] =
      load_arduino_v_13_DW.WP_dbI[6 * load_arduino_v_13_B.firstcol];
  }

  for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 7;
       load_arduino_v_13_B.firstcol++) {
    load_arduino_v_13_B.WP_param[load_arduino_v_13_B.firstcol] =
      load_arduino_v_13_DW.WP_dbP[6 * load_arduino_v_13_B.firstcol];
  }

  if ((load_arduino_v_13_B.GC_info[0] == 2) && (load_arduino_v_13_B.GC_info[1] <
       6)) {
    load_arduino_v_13_B.qY = load_arduino_v_13_B.GC_info[1] + 1U;
    load_arduino_v_13_B.qY_tmp = load_arduino_v_13_B.qY;
    if (load_arduino_v_13_B.qY > 65535U) {
      load_arduino_v_13_B.qY_tmp = 65535U;
    }

    load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.qY_tmp;
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.WP_info[load_arduino_v_13_B.i] =
        load_arduino_v_13_DW.WP_dbI[(6 * load_arduino_v_13_B.i +
        load_arduino_v_13_B.firstcol) - 1];
    }

    if (load_arduino_v_13_B.qY > 65535U) {
      load_arduino_v_13_B.qY = 65535U;
    }

    load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.qY;
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 7;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.WP_param[load_arduino_v_13_B.i] =
        load_arduino_v_13_DW.WP_dbP[(6 * load_arduino_v_13_B.i +
        load_arduino_v_13_B.firstcol) - 1];
    }
  }

  if ((load_arduino_v_13_B.GC_info[0] == 3) && (load_arduino_v_13_B.GC_info[1] <
       200)) {
    load_arduino_v_13_B.qY = load_arduino_v_13_B.GC_info[1] + 1U;
    if (load_arduino_v_13_B.qY > 65535U) {
      load_arduino_v_13_B.qY = 65535U;
    }

    load_arduino_v_13_B.firstcol = (int32_T)load_arduino_v_13_B.qY;
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.WP_info[load_arduino_v_13_B.i] =
        load_arduino_v_13_DW.WP_dbI[(6 * load_arduino_v_13_B.i +
        load_arduino_v_13_B.firstcol) - 1];
    }
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function' */

  /* Outputs for Resettable SubSystem: '<S751>/Resettable Subsystem' */
  load_arduino_v_13_B.IProdOut_b = load_ar_ResettableSubsystem
    (load_arduino_v_13_B.SFunction_o4_n[0],
     &load_arduino_v_13_DW.ResettableSubsystem_o,
     &load_arduino_v_13_P.ResettableSubsystem_o,
     &load_arduino_v_13_PrevZCX.ResettableSubsystem_o);

  /* End of Outputs for SubSystem: '<S751>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S751>/Enabled Subsystem' */
  load_ardui_EnabledSubsystem(load_arduino_v_13_B.SFunction_o4_n[0],
    load_arduino_v_13_B.IProdOut_b, &load_arduino_v_13_B.Switch_l,
    &load_arduino_v_13_P.EnabledSubsystem_j);

  /* End of Outputs for SubSystem: '<S751>/Enabled Subsystem' */

  /* MATLAB Function: '<S956>/MATLAB Function' incorporates:
   *  Constant: '<S947>/Constant'
   *  Constant: '<S956>/Constant'
   */
  load_arduino_v_13_B.checksum = load_arduino_v_13_P.Constant_Value_k *
    load_arduino_v_13_P.Constant_Value_p;
  load_arduino_v_13_B.r = load_arduino_v_13_B.checksum / (1.0 +
    load_arduino_v_13_B.checksum);

  /* MATLABSystem: '<S947>/Serial Receive' incorporates:
   *  MATLAB Function: '<S955>/MATLAB Function'
   */
  MW_Serial_read(1, load_arduino_v_13_DW.obj_m.DataSizeInBytes,
                 load_arduino_v_13_B.data_p, &sts);

  /* Outputs for Enabled SubSystem: '<S947>/Subsystem1' incorporates:
   *  EnablePort: '<S955>/Enable'
   */
  if (sts > 0) {
    /* MATLAB Function: '<S955>/MATLAB Function' */
    Ap_sel = false;
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 31;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.messaggio[load_arduino_v_13_B.i] = 0U;
    }

    if (!load_arduino_v_13_DW.start_found_i) {
      load_arduino_v_13_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_13_B.i - 1 < 30)) {
        if ((load_arduino_v_13_B.data_p[(uint8_T)load_arduino_v_13_B.i - 1] ==
             255) && (load_arduino_v_13_B.data_p[(uint8_T)load_arduino_v_13_B.i]
                      == 254)) {
          load_arduino_v_13_B.caso = -(uint8_T)load_arduino_v_13_B.i;
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
               load_arduino_v_13_B.caso + 31; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_DW.message_a[load_arduino_v_13_B.firstcol] =
              load_arduino_v_13_B.data_p[((uint8_T)load_arduino_v_13_B.i +
              load_arduino_v_13_B.firstcol) - 1];
          }

          load_arduino_v_13_DW.counter_i = (uint8_T)(32 - (uint8_T)
            load_arduino_v_13_B.i);
          load_arduino_v_13_DW.start_found_i = true;
          exitg1 = true;
        } else {
          load_arduino_v_13_B.i++;
        }
      }

      if (load_arduino_v_13_DW.counter_i == 31) {
        for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 31;
             load_arduino_v_13_B.i++) {
          load_arduino_v_13_B.messaggio[load_arduino_v_13_B.i] =
            load_arduino_v_13_DW.message_a[load_arduino_v_13_B.i];
          load_arduino_v_13_DW.message_a[load_arduino_v_13_B.i] = 0U;
        }

        Ap_sel = true;
        load_arduino_v_13_DW.start_found_i = false;
        load_arduino_v_13_DW.counter_i = 0U;
      }
    } else {
      load_arduino_v_13_B.qY_tmp = 31U - /*MW:OvSatOk*/
        load_arduino_v_13_DW.counter_i;
      load_arduino_v_13_B.qY = load_arduino_v_13_B.qY_tmp;
      if (load_arduino_v_13_B.qY_tmp > 31U) {
        load_arduino_v_13_B.qY = 0U;
      }

      load_arduino_v_13_B.firstcol = (int32_T)(load_arduino_v_13_DW.counter_i +
        1U);
      if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
        load_arduino_v_13_B.firstcol = 255;
      }

      if ((uint8_T)load_arduino_v_13_B.firstcol > 31) {
        load_arduino_v_13_B.tolleranza_distWP_fut = 0;
      } else {
        load_arduino_v_13_B.tolleranza_distWP_fut = (uint8_T)
          load_arduino_v_13_B.firstcol - 1;
      }

      if (1 > (uint8_T)load_arduino_v_13_B.qY) {
        load_arduino_v_13_B.firstcol = 0;
      } else {
        load_arduino_v_13_B.firstcol = (uint8_T)load_arduino_v_13_B.qY;
      }

      load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
      for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
           load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
        load_arduino_v_13_DW.message_a[load_arduino_v_13_B.tolleranza_distWP_fut
          + load_arduino_v_13_B.firstcol] =
          load_arduino_v_13_B.data_p[load_arduino_v_13_B.firstcol];
      }

      Ap_sel = true;
      if (load_arduino_v_13_B.qY_tmp > 31U) {
        load_arduino_v_13_B.qY_tmp = 0U;
      }

      load_arduino_v_13_DW.counter_i = (uint8_T)load_arduino_v_13_B.qY_tmp;
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 31;
           load_arduino_v_13_B.i++) {
        load_arduino_v_13_B.messaggio[load_arduino_v_13_B.i] =
          load_arduino_v_13_DW.message_a[load_arduino_v_13_B.i];
        load_arduino_v_13_DW.message_a[load_arduino_v_13_B.i] = 0U;
      }

      sts = load_arduino_v_13_DW.counter_i;
      exitg1 = false;
      while ((!exitg1) && (sts < 31)) {
        if ((load_arduino_v_13_B.data_p[sts - 1] == 255) &&
            (load_arduino_v_13_B.data_p[sts] == 254)) {
          load_arduino_v_13_B.caso = -sts;
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
               load_arduino_v_13_B.caso + 31; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_DW.message_a[load_arduino_v_13_B.firstcol] =
              load_arduino_v_13_B.data_p[(sts + load_arduino_v_13_B.firstcol) -
              1];
          }

          load_arduino_v_13_B.qY = sts - /*MW:OvSatOk*/ 1U;
          if (load_arduino_v_13_B.qY > sts) {
            load_arduino_v_13_B.qY = 0U;
          }

          load_arduino_v_13_DW.counter_i = (uint8_T)(31 - (int32_T)
            load_arduino_v_13_B.qY);
          load_arduino_v_13_DW.start_found_i = true;
          exitg1 = true;
        } else {
          load_arduino_v_13_DW.start_found_i = false;
          load_arduino_v_13_DW.counter_i = 0U;
          sts++;
        }
      }
    }

    /* Outputs for Enabled SubSystem: '<S955>/Subsystem2' incorporates:
     *  EnablePort: '<S961>/Enable'
     */
    if (Ap_sel) {
      /* S-Function (byte2any_svd): '<S961>/Byte Unpack' */

      /* Unpack: <S961>/Byte Unpack */
      {
        uint32_T MW_inputPortOffset = 0;
        uint32_T MW_outputPortWidth = 0;
        uint32_T MW_remainder2 = 0;

        /* Packed input data type - uint8_T */
        /* Unpacking the values to output 1 */
        /* Output data type - uint8_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint8_T);
          memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o1_o[0], (uint8_T*)
                 &load_arduino_v_13_B.messaggio[0] + MW_inputPortOffset,
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
        /* Output data type - real32_T, size - 4 */
        {
          MW_outputPortWidth = 4 * sizeof(real32_T);
          memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o2_e[0], (uint8_T*)
                 &load_arduino_v_13_B.messaggio[0] + MW_inputPortOffset,
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
        /* Output data type - int16_T, size - 4 */
        {
          MW_outputPortWidth = 4 * sizeof(int16_T);
          memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o3[0], (uint8_T*)
                 &load_arduino_v_13_B.messaggio[0] + MW_inputPortOffset,
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

        /* Unpacking the values to output 4 */
        /* Output data type - uint16_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint16_T);
          memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o4[0], (uint8_T*)
                 &load_arduino_v_13_B.messaggio[0] + MW_inputPortOffset,
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

        /* Unpacking the values to output 5 */
        /* Output data type - uint8_T, size - 1 */
        {
          MW_outputPortWidth = 1 * sizeof(uint8_T);
          memcpy((uint8_T*)&load_arduino_v_13_B.ByteUnpack_o5, (uint8_T*)
                 &load_arduino_v_13_B.messaggio[0] + MW_inputPortOffset,
                 MW_outputPortWidth);
        }
      }
    }

    /* End of Outputs for SubSystem: '<S955>/Subsystem2' */
  }

  /* End of MATLABSystem: '<S947>/Serial Receive' */
  /* End of Outputs for SubSystem: '<S947>/Subsystem1' */

  /* Gain: '<S947>/Gain1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion2'
   */
  load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = load_arduino_v_13_P.Gain1_Gain_px *
    (real_T)load_arduino_v_13_B.ByteUnpack_o3[0];
  load_arduino_v_13_B.rtb_Gain1_kw_idx_1 = load_arduino_v_13_P.Gain1_Gain_px *
    (real_T)load_arduino_v_13_B.ByteUnpack_o3[1];

  /* Sum: '<S956>/Sum' incorporates:
   *  UnitDelay: '<S956>/Unit Delay'
   */
  load_arduino_v_13_B.checksum = load_arduino_v_13_B.rtb_Gain1_kw_idx_1 +
    load_arduino_v_13_DW.UnitDelay_DSTATE;

  /* Product: '<S956>/Product1' incorporates:
   *  MATLAB Function: '<S956>/MATLAB Function'
   */
  load_arduino_v_13_B.Product1 = load_arduino_v_13_B.r *
    load_arduino_v_13_B.checksum;

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 9;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_B.DataTypeConversion1_b[load_arduino_v_13_B.i] =
      load_arduino_v_13_B.ByteReversal[load_arduino_v_13_B.i];
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* Gain: '<S943>/Gain1' */
  load_arduino_v_13_B.Gain1_l = load_arduino_v_13_P.Gain1_Gain_k *
    load_arduino_v_13_B.DataTypeConversion1_b[6];

  /* MATLAB Function: '<S757>/MATLAB Function1' */
  guard1 = false;
  if (load_arduino_v_13_B.AP_int[1] == 1) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     */
    if (load_arduino_v_13_B.Switch_l != 0.0) {
      load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant_Value;
    } else {
      load_arduino_v_13_B.Sum4_n = load_arduino_v_13_B.Product1;
    }

    /* End of Switch: '<S40>/Switch' */
    if (load_arduino_v_13_B.Sum4_n > load_arduino_v_13_P.safe_V) {
      load_arduino_v_13_DW.alarm = 1.0;
    } else if (fabs(load_arduino_v_13_P.Gain_Gain_mz *
                    load_arduino_v_13_B.Gain1_l) > load_arduino_v_13_P.safe_phi)
    {
      load_arduino_v_13_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (load_arduino_v_13_B.AP_int[0] == 1) {
      load_arduino_v_13_DW.alarm = 0.0;
    }
  }

  /* Outputs for Resettable SubSystem: '<S774>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S777>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &load_arduino_v_13_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (load_arduino_v_13_DW.alarm)) != NO_ZCEVENT) {
    /* InitializeConditions for Memory: '<S778>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_h =
      load_arduino_v_13_P.Memory_InitialCondition;
  }

  /* Sum: '<S778>/Sum' incorporates:
   *  Constant: '<S778>/Constant4'
   *  Memory: '<S778>/Memory'
   */
  load_arduino_v_13_DW.Memory_PreviousInput_h += load_arduino_v_13_P.t_AP;

  /* End of Outputs for SubSystem: '<S774>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S774>/Enabled ' incorporates:
   *  EnablePort: '<S776>/Enable'
   */
  /* MATLAB Function: '<S757>/MATLAB Function1' */
  if (load_arduino_v_13_DW.alarm > 0.0) {
    if (!load_arduino_v_13_DW.Enabled_MODE) {
      load_arduino_v_13_DW.Enabled_MODE = true;
    }

    /* Switch: '<S776>/Switch' incorporates:
     *  Constant: '<S776>/Constant'
     *  Constant: '<S776>/Constant1'
     */
    if (load_arduino_v_13_DW.Memory_PreviousInput_h >
        load_arduino_v_13_P.time_alarm_SAFE) {
      load_arduino_v_13_B.Switch_n = load_arduino_v_13_P.Constant_Value_h;
    } else {
      load_arduino_v_13_B.Switch_n = load_arduino_v_13_P.Constant1_Value_i;
    }

    /* End of Switch: '<S776>/Switch' */
  } else {
    if (load_arduino_v_13_DW.Enabled_MODE) {
      /* Disable for Outport: '<S776>/Alarm Safe' */
      load_arduino_v_13_B.Switch_n = load_arduino_v_13_P.AlarmSafe_Y0;
      load_arduino_v_13_DW.Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S774>/Enabled ' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtS-FunctionInport9' incorporates:
   *  Constant: '<S21>/load uint16'
   */
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[0] =
    load_arduino_v_13_P.loaduint16_Value;

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S7>/Constant'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Gain_Gain_by *
    load_arduino_v_13_P.Constant_Value_jp[0]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtS-FunctionInport9' incorporates:
   *  Gain: '<S21>/Gain'
   */
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  load_arduino_v_13_B.qY = 10U * z;
  if (load_arduino_v_13_B.qY > 65535U) {
    load_arduino_v_13_B.qY = 65535U;
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtS-FunctionInport9' incorporates:
   *  Constant: '<S21>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)
    load_arduino_v_13_B.qY;
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[3] =
    load_arduino_v_13_B.SFunction_o11[6];
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[4] =
    load_arduino_v_13_B.SFunction_o11[2];
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[5] =
    load_arduino_v_13_P._Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Switch_n);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtS-FunctionInport9' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* DataTypeConversion: '<S21>/Data Type Conversion4' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant2_Value_k);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtS-FunctionInport9' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S21>/Gain2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Gain2_Gain *
    load_arduino_v_13_P.Constant_Value_jp[2]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Gain: '<S21>/Gain2'
   */
  load_arduino_v_13_B.Gain1 = (int16_T)(((load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n : (int32_T)
    (int16_T)(uint16_T)load_arduino_v_13_B.Sum4_n) *
    load_arduino_v_13_P.Gain1_Gain_eu) >> 18);

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant_Value_jp[1]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 256.0);
  }

  load_arduino_v_13_B.B_Remaining = (int8_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(int8_T)-(int8_T)(uint8_T)-load_arduino_v_13_B.Sum4_n : (int32_T)
    (int8_T)(uint8_T)load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S21>/Data Type Conversion3' */

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant_Value_e);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 4.294967296E+9);
  }

  load_arduino_v_13_B.DataTypeConversion = load_arduino_v_13_B.Sum4_n < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-load_arduino_v_13_B.Sum4_n : (uint32_T)
    load_arduino_v_13_B.Sum4_n;

  /* End of DataTypeConversion: '<S17>/Data Type Conversion' */

  /* MATLAB Function: '<S17>/Alarm set' incorporates:
   *  Constant: '<S40>/Constant2'
   *  SignalConversion: '<S28>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_H_mav[0] = status;
  rtb_H_mav[1] = rtb_H_mav_e_idx_1;
  if (load_arduino_v_13_B.Switch_n == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (load_arduino_v_13_P.Constant2_Value_k == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S17>/Alarm set' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtS-FunctionInport13' incorporates:
   *  Constant: '<S17>/Type fixed_wing Autopilot generic'
   */
  load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[0] =
    load_arduino_v_13_P.Typefixed_wingAutopilotgeneric_[0];
  load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[2] = rtb_H_mav[0];
  load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[1] =
    load_arduino_v_13_P.Typefixed_wingAutopilotgeneric_[1];
  load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[3] = rtb_H_mav[1];

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
       load_arduino_v_13_B.i++) {
    /* Gain: '<S18>/Gain' */
    load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_dn *
      load_arduino_v_13_B.DataTypeConversion1_b[load_arduino_v_13_B.i];
    if (load_arduino_v_13_B.Go_Home < 0.0) {
      load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
    } else {
      load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
    }

    if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf
        (load_arduino_v_13_B.Sum4_n)) {
      load_arduino_v_13_B.Sum4_n = 0.0;
    } else {
      load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
    }

    load_arduino_v_13_B.DataTypeConversion_ld[load_arduino_v_13_B.i] = (int16_T)
      (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
       -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
       load_arduino_v_13_B.Sum4_n);
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_dn *
    load_arduino_v_13_P.Constant_Value_hxg;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_ld[6] = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_dn *
    load_arduino_v_13_P.Constant1_Value_f;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_ld[7] = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_dn *
    load_arduino_v_13_P.Constant2_Value_e;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_ld[8] = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S944>/Gain1' */
  load_arduino_v_13_B.Gain1_a = load_arduino_v_13_P.Gain1_Gain_kf *
    load_arduino_v_13_B.DataTypeConversion1_b[7];

  /* Gain: '<S945>/Gain1' */
  load_arduino_v_13_B.Gain1_c = load_arduino_v_13_P.Gain1_Gain_c *
    load_arduino_v_13_B.DataTypeConversion1_b[8];

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  load_arduino_v_13_B.DataTypeConversion1[0] = (real32_T)
    load_arduino_v_13_B.Gain1_l;
  load_arduino_v_13_B.DataTypeConversion1[1] = (real32_T)
    load_arduino_v_13_B.Gain1_a;
  load_arduino_v_13_B.DataTypeConversion1[2] = (real32_T)
    load_arduino_v_13_B.Gain1_c;
  load_arduino_v_13_B.DataTypeConversion1[3] = (real32_T)
    load_arduino_v_13_B.DataTypeConversion1_b[3];
  load_arduino_v_13_B.DataTypeConversion1[4] = (real32_T)
    load_arduino_v_13_B.DataTypeConversion1_b[4];
  load_arduino_v_13_B.DataTypeConversion1[5] = (real32_T)
    load_arduino_v_13_B.DataTypeConversion1_b[5];

  /* DataTypeConversion: '<S947>/Data Type Conversion5' */
  load_arduino_v_13_B.DataTypeConversion5[0] =
    load_arduino_v_13_B.ByteUnpack_o2_e[0];
  load_arduino_v_13_B.DataTypeConversion5[1] =
    load_arduino_v_13_B.ByteUnpack_o2_e[1];
  load_arduino_v_13_B.DataTypeConversion5[2] =
    load_arduino_v_13_B.ByteUnpack_o2_e[2];
  load_arduino_v_13_B.DataTypeConversion5[3] =
    load_arduino_v_13_B.ByteUnpack_o2_e[3];

  /* Gain: '<S948>/Gain1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   */
  load_arduino_v_13_B.Gain1_f = load_arduino_v_13_P.Gain1_Gain_d *
    load_arduino_v_13_B.ByteUnpack_o2_e[0];

  /* Gain: '<S949>/Gain1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   */
  load_arduino_v_13_B.Gain1_p = load_arduino_v_13_P.Gain1_Gain_n *
    load_arduino_v_13_B.ByteUnpack_o2_e[1];

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S26>/Gain'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_f2 *
    load_arduino_v_13_B.Gain1_f * load_arduino_v_13_P.Gain_Gain_bx[0];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 4.294967296E+9);
  }

  load_arduino_v_13_B.DataTypeConversion_a[0] = load_arduino_v_13_B.Sum4_n < 0.0
    ? -(int32_T)(uint32_T)-load_arduino_v_13_B.Sum4_n : (int32_T)(uint32_T)
    load_arduino_v_13_B.Sum4_n;

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S27>/Gain'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_ds *
    load_arduino_v_13_B.Gain1_p * load_arduino_v_13_P.Gain_Gain_bx[1];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 4.294967296E+9);
  }

  load_arduino_v_13_B.DataTypeConversion_a[1] = load_arduino_v_13_B.Sum4_n < 0.0
    ? -(int32_T)(uint32_T)-load_arduino_v_13_B.Sum4_n : (int32_T)(uint32_T)
    load_arduino_v_13_B.Sum4_n;

  /* Gain: '<S16>/Gain' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_bx[2] *
    load_arduino_v_13_B.ByteUnpack_o2_e[2];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 4.294967296E+9);
  }

  load_arduino_v_13_B.DataTypeConversion_a[2] = load_arduino_v_13_B.Sum4_n < 0.0
    ? -(int32_T)(uint32_T)-load_arduino_v_13_B.Sum4_n : (int32_T)(uint32_T)
    load_arduino_v_13_B.Sum4_n;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/alt_r'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_bx[3] *
    load_arduino_v_13_P.alt_r_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 4.294967296E+9);
  }

  load_arduino_v_13_B.DataTypeConversion_a[3] = load_arduino_v_13_B.Sum4_n < 0.0
    ? -(int32_T)(uint32_T)-load_arduino_v_13_B.Sum4_n : (int32_T)(uint32_T)
    load_arduino_v_13_B.Sum4_n;

  /* Gain: '<S947>/Gain4' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion3'
   */
  load_arduino_v_13_B.Gain4[0] = load_arduino_v_13_P.Gain4_Gain * (real_T)
    load_arduino_v_13_B.ByteUnpack_o4[0];
  load_arduino_v_13_B.Gain4[1] = load_arduino_v_13_P.Gain4_Gain * (real_T)
    load_arduino_v_13_B.ByteUnpack_o4[1];

  /* Gain: '<S16>/Gain1' */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain1_Gain_e *
    load_arduino_v_13_B.Gain4[0];

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_p[0] = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S16>/Gain1' incorporates:
   *  Constant: '<S16>/vel y'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain1_Gain_e *
    load_arduino_v_13_P.vely_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_p[1] = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S16>/Gain1' */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain1_Gain_e *
    load_arduino_v_13_B.rtb_Gain1_kw_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_p[2] = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S946>/Gain1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   *  Gain: '<S950>/Gain1'
   */
  load_arduino_v_13_B.Gain1_k = load_arduino_v_13_P.Gain1_Gain_b *
    load_arduino_v_13_B.ByteUnpack_o2_e[3] * load_arduino_v_13_P.Gain1_Gain_n1;

  /* Gain: '<S16>/Gain2' */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain2_Gain_k *
    load_arduino_v_13_B.Gain1_k;

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion2_h = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S16>/Data Type Conversion2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Constant: '<S22>/airspeed groundspeed alt climb1'
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   */
  load_arduino_v_13_B.AGAC[0] = (real32_T)load_arduino_v_13_B.Product1;
  load_arduino_v_13_B.AGAC[1] = (real32_T)
    load_arduino_v_13_P.airspeedgroundspeedaltclimb1_Va;
  load_arduino_v_13_B.AGAC[2] = load_arduino_v_13_B.ByteUnpack_o2_e[2];
  load_arduino_v_13_B.AGAC[3] = (real32_T)load_arduino_v_13_B.rtb_Gain1_kw_idx_0;

  /* Gain: '<S35>/Gain' */
  load_arduino_v_13_B.Gain_o = load_arduino_v_13_P.Gain_Gain_l *
    load_arduino_v_13_B.Gain1_k;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Abs: '<S36>/Abs'
   *  Constant: '<S36>/Constant2'
   *  Sum: '<S36>/Sum'
   */
  if (!(load_arduino_v_13_B.Gain_o > load_arduino_v_13_P.Switch2_Threshold_a)) {
    load_arduino_v_13_B.Gain_o = load_arduino_v_13_P.Constant2_Value - fabs
      (load_arduino_v_13_B.Gain_o);
  }

  /* End of Switch: '<S36>/Switch2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Gain_o < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Gain_o);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Gain_o);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading_g = (int16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n : (int32_T)
    (int16_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S22>/Data Type Conversion1' */

  /* Gain: '<S22>/USCITA PERCENTUALE' incorporates:
   *  Constant: '<S6>/Constant'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.USCITAPERCENTUALE_Gain *
    load_arduino_v_13_P.Constant_Value_c;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Throttle = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S22>/Data Type Conversion2' */

  /* DataTypeConversion: '<S1>/Data Tversion2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  rtb_WP_db_info_0 = &load_arduino_v_13_DW.WP_dbI[0];

  /* S-Function (PWMinterrupt_goHome): '<S9>/S-Function Builder2' */
  PWMinterrupt_goHome_Outputs_wrapper(&load_arduino_v_13_B.SFunctionBuilder2);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  if (load_arduino_v_13_B.SFunctionBuilder2 >
      load_arduino_v_13_P.Switch_Threshold_mm) {
    load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Constant_Value_bh;
  } else {
    load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Constant1_Value_js;
  }

  /* Chart: '<S40>/ STATI' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  if (load_arduino_v_13_DW.is_active_c26_load_arduino_v_13 == 0U) {
    load_arduino_v_13_DW.is_active_c26_load_arduino_v_13 = 1U;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 = load_arduino_v_13_IN_MANUALE;
  } else {
    switch (load_arduino_v_13_DW.is_c26_load_arduino_v_13) {
     case load_arduino_v_13_IN_AUTOMATICA:
      load_arduino_v_13_AUTOMATICA(load_arduino_v_13_B.DataTypeConversion5,
        load_arduino_v_13_B.Gain4, &load_arduino_v_13_B.Product1,
        &load_arduino_v_13_B.Go_Home, &load_arduino_v_13_DW.test1);
      break;

     case load_arduino_v_13_IN_Go_Home:
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant'
       *  Constant: '<S9>/Constant1'
       */
      if (load_arduino_v_13_B.SFunctionBuilder2 >
          load_arduino_v_13_P.Switch_Threshold_mm) {
        load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant_Value_bh;
      } else {
        load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant1_Value_js;
      }

      if ((load_arduino_v_13_B.Sum4_n == 0.0) && ((load_arduino_v_13_B.AP_int[6]
            == 1) || (load_arduino_v_13_B.AP_int[3] == 1) ||
           (load_arduino_v_13_B.AP_int[4] == 1) || (load_arduino_v_13_B.AP_int[2]
            == 1) || (load_arduino_v_13_B.AP_int[8] == 1))) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_AUTOMATICA;
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_VETTORIALE;
      } else if (load_arduino_v_13_B.Switch_n == 1.0) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_Safe;
      } else if (load_arduino_v_13_P.Constant2_Value_k == 1.0) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_ardui_IN_Intervento_Pilota;
      } else {
        load_arduino_v_13_B.modo = 5.0;
        load_arduino_v_13_B.switch_manetta = 1.0;
        load_arduino_v_13_B.switch_equilibratore = 1.0;
        load_arduino_v_13_B.switch_alettoni = 1.0;
        load_arduino_v_13_B.switch_timone = 1.0;
      }
      break;

     case load_ardui_IN_Intervento_Pilota:
      if (load_arduino_v_13_B.AP_int[0] == 1) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_MANUALE;
      } else {
        load_arduino_v_13_B.switch_manetta = 0.0;
        load_arduino_v_13_B.switch_equilibratore = 0.0;
        load_arduino_v_13_B.switch_alettoni = 0.0;
        load_arduino_v_13_B.switch_timone = 0.0;
      }
      break;

     case load_arduino_v_13_IN_MANUALE:
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant'
       *  Constant: '<S9>/Constant1'
       */
      if (load_arduino_v_13_B.SFunctionBuilder2 >
          load_arduino_v_13_P.Switch_Threshold_mm) {
        load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant_Value_bh;
      } else {
        load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant1_Value_js;
      }

      if ((load_arduino_v_13_B.Sum4_n == 1.0) && (load_arduino_v_13_B.Switch_n ==
           0.0)) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_Go_Home;
      } else if (load_arduino_v_13_B.AP_int[0] == 0) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_Stand_By;
      } else {
        load_arduino_v_13_B.switch_manetta = 0.0;
        load_arduino_v_13_B.switch_equilibratore = 0.0;
        load_arduino_v_13_B.switch_alettoni = 0.0;
        load_arduino_v_13_B.switch_timone = 0.0;
      }
      break;

     case load_arduino_v_13_IN_Safe:
      if (load_arduino_v_13_P.Constant2_Value_k == 1.0) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_ardui_IN_Intervento_Pilota;
      } else if (load_arduino_v_13_B.AP_int[0] == 1) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_MANUALE;
      } else {
        load_arduino_v_13_B.switch_manetta = 1.0;
        load_arduino_v_13_B.switch_equilibratore = 1.0;
        load_arduino_v_13_B.switch_alettoni = 1.0;
        load_arduino_v_13_B.switch_timone = 1.0;
      }
      break;

     default:
      if (load_arduino_v_13_B.AP_int[1] == 1) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_AUTOMATICA;
        load_arduino_v_13_DW.is_AUTOMATICA = load_arduino_v_13_IN_VETTORIALE;
      } else if (load_arduino_v_13_B.AP_int[0] == 1) {
        load_arduino_v_13_DW.is_c26_load_arduino_v_13 =
          load_arduino_v_13_IN_MANUALE;
      } else {
        load_arduino_v_13_B.switch_manetta = 0.0;
        load_arduino_v_13_B.switch_equilibratore = 0.0;
        load_arduino_v_13_B.switch_alettoni = 0.0;
        load_arduino_v_13_B.switch_timone = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S40>/ STATI' */

  /* S-Function (PWMinterrupt_throttle_v4_4): '<S9>/S-Function Builder6' */
  PWMinterrupt_throttle_v4_4_Outputs_wrapper(&load_arduino_v_13_B.PWM_throttle);

  /* Logic: '<S41>/AND' */
  Ap_sel = ((load_arduino_v_13_B.switch_manetta != 0.0) &&
            (load_arduino_v_13_B.switch_equilibratore != 0.0) &&
            (load_arduino_v_13_B.switch_alettoni != 0.0) &&
            (load_arduino_v_13_B.switch_timone != 0.0));

  /* Chart: '<S41>/Chart' */
  if (load_arduino_v_13_DW.is_active_c21_load_arduino_v_13 == 0U) {
    load_arduino_v_13_DW.is_active_c21_load_arduino_v_13 = 1U;
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_In;
    load_arduino_v_13_B.Wp_selector = 0.0;
    load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
    load_arduino_v_13_B.Gain_o = 0.0;
    load_arduino_v_13_B.Al_selector = 0.0;
    load_arduino_v_13_B.Go_Home = 0.0;
  } else {
    switch (load_arduino_v_13_DW.is_c21_load_arduino_v_13) {
     case load_arduino_v_1_IN_AutoLanding:
      load_arduino_v_13_AutoLanding(&Ap_sel, &load_arduino_v_13_B.Go_Home,
        &load_arduino_v_13_B.Al_selector, &load_arduino_v_13_B.Gain_o,
        &load_arduino_v_13_B.rtb_Gain1_kw_idx_0,
        &load_arduino_v_13_B.Wp_selector);
      break;

     case load_arduino_v_1_IN_AutoTakeoff:
      if (!Ap_sel) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_In;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (load_arduino_v_13_B.modo == 1.0) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_Waypoint;
        load_arduino_v_13_B.Wp_selector = 1.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (load_arduino_v_13_B.modo == 2.0) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_Vettoriale;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 1.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else {
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 1.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      }
      break;

     case load_arduino_v_13_IN_GoHome:
      if (!Ap_sel) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_In;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else {
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 1.0;
      }
      break;

     case load_arduino_v_13_IN_In:
      if (Ap_sel && (load_arduino_v_13_B.modo == 1.0)) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_Waypoint;
        load_arduino_v_13_B.Wp_selector = 1.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (Ap_sel && (load_arduino_v_13_B.modo == 2.0)) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_Vettoriale;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 1.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (Ap_sel && (load_arduino_v_13_B.modo == 5.0)) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_GoHome;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 1.0;
      } else if (Ap_sel && (load_arduino_v_13_B.modo == 4.0)) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_1_IN_AutoLanding;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 1.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (Ap_sel && (load_arduino_v_13_B.modo == 3.0)) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_1_IN_AutoTakeoff;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 1.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else {
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      }
      break;

     case load_arduino_v_13_IN_Vettoriale:
      if (!Ap_sel) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 = load_arduino_v_13_IN_In;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (load_arduino_v_13_B.modo == 1.0) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_Waypoint;
        load_arduino_v_13_B.Wp_selector = 1.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else if (load_arduino_v_13_B.modo == 5.0) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_13_IN_GoHome;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 1.0;
      } else if (load_arduino_v_13_B.modo == 4.0) {
        load_arduino_v_13_DW.is_c21_load_arduino_v_13 =
          load_arduino_v_1_IN_AutoLanding;
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 0.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 1.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      } else {
        load_arduino_v_13_B.Wp_selector = 0.0;
        load_arduino_v_13_B.rtb_Gain1_kw_idx_0 = 1.0;
        load_arduino_v_13_B.Gain_o = 0.0;
        load_arduino_v_13_B.Al_selector = 0.0;
        load_arduino_v_13_B.Go_Home = 0.0;
      }
      break;

     default:
      load_arduino_v_13_Waypoint(&Ap_sel, &load_arduino_v_13_B.Go_Home,
        &load_arduino_v_13_B.Al_selector, &load_arduino_v_13_B.Gain_o,
        &load_arduino_v_13_B.rtb_Gain1_kw_idx_0,
        &load_arduino_v_13_B.Wp_selector);
      break;
    }
  }

  /* End of Chart: '<S41>/Chart' */

  /* Outputs for Enabled SubSystem: '<S41>/DECOLLO AUTOMATICO' incorporates:
   *  EnablePort: '<S780>/Enable'
   */
  if (load_arduino_v_13_B.Gain_o > 0.0) {
    /* Outputs for Triggered SubSystem: '<S780>/Sample and Hold' incorporates:
     *  TriggerPort: '<S788>/Trigger'
     */
    /* Memory: '<S780>/Memory' */
    load_arduino_v_13_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &load_arduino_v_13_PrevZCX.SampleandHold_Trig_ZCE_h,
      (load_arduino_v_13_DW.Memory_PreviousInput_i));
    if (load_arduino_v_13_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S788>/In' incorporates:
       *  Gain: '<S787>/Gain'
       */
      load_arduino_v_13_B.In_k = load_arduino_v_13_P.Gain_Gain_gm *
        load_arduino_v_13_B.Gain1_c;
    }

    /* End of Outputs for SubSystem: '<S780>/Sample and Hold' */

    /* Outputs for Triggered SubSystem: '<S780>/Sample and Hold1' incorporates:
     *  TriggerPort: '<S789>/Trigger'
     */
    /* Memory: '<S780>/Memory1' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &load_arduino_v_13_PrevZCX.SampleandHold1_Trig_ZCE,
             (load_arduino_v_13_DW.Memory1_PreviousInput_o));

    /* End of Outputs for SubSystem: '<S780>/Sample and Hold1' */

    /* Chart: '<S780>/Chart1' incorporates:
     *  DataTypeConversion: '<S947>/Data Type Conversion5'
     */
    if (load_arduino_v_13_DW.temporalCounter_i1 < 255U) {
      load_arduino_v_13_DW.temporalCounter_i1++;
    }

    if (load_arduino_v_13_DW.is_active_c1_load_arduino_v_13 == 0U) {
      load_arduino_v_13_DW.is_active_c1_load_arduino_v_13 = 1U;
      load_arduino_v_13_DW.is_c1_load_arduino_v_13 =
        load_arduino_v_13_IN_Fase_0_ATO;
    } else {
      switch (load_arduino_v_13_DW.is_c1_load_arduino_v_13) {
       case load_arduino_v_13_IN_Fase_0_ATO:
        if (load_arduino_v_13_B.modo == 3.0) {
          load_arduino_v_13_B.psi_ref_selector = 1.0;
          load_arduino_v_13_DW.is_c1_load_arduino_v_13 =
            load_arduino_v_13_IN_Fase_1_ATO;
          load_arduino_v_13_DW.temporalCounter_i1 = 0U;
        } else {
          load_arduino_v_13_B.Fase_ATO = 0.0;
          load_arduino_v_13_B.psi_ref_selector = 0.0;
          load_arduino_v_13_B.theta_ground_selector = 0.0;
          load_arduino_v_13_B.psi_ref = 0.0;
          load_arduino_v_13_B.eq_rot = 0.0;
          load_arduino_v_13_B.h_ref = 0.0;
        }
        break;

       case load_arduino_v_13_IN_Fase_1_ATO:
        if (load_arduino_v_13_DW.temporalCounter_i1 >= 250) {
          load_arduino_v_13_DW.is_c1_load_arduino_v_13 =
            load_arduino_v_13_IN_Fase_2_ATO;
        } else {
          load_arduino_v_13_B.Fase_ATO = 1.0;
          load_arduino_v_13_B.manetta_ref = 0.1;
          load_arduino_v_13_B.psi_ref_selector = 0.0;
          load_arduino_v_13_B.h_ref = 0.0;
          load_arduino_v_13_B.psi_ref = load_arduino_v_13_B.In_k;
          load_arduino_v_13_B.eq_rot = 2.0;
        }
        break;

       case load_arduino_v_13_IN_Fase_2_ATO:
        if ((load_arduino_v_13_B.Product1 >= 18.0) &&
            (load_arduino_v_13_B.Gain4[0] >= 10.0)) {
          load_arduino_v_13_B.theta_ground_selector = 1.0;
          load_arduino_v_13_DW.is_c1_load_arduino_v_13 =
            load_arduino_v_13_IN_Fase_3_ATO;
        } else {
          load_arduino_v_13_B.Fase_ATO = 2.0;
          load_arduino_v_13_B.psi_ref_selector = 0.0;
          load_arduino_v_13_B.psi_ref = load_arduino_v_13_B.In_k;
          load_arduino_v_13_B.h_ref = 0.0;
          load_arduino_v_13_B.eq_rot = 2.0;
        }
        break;

       case load_arduino_v_13_IN_Fase_3_ATO:
        if (load_arduino_v_13_B.ByteUnpack_o2_e[2] >= 2.0F) {
          load_arduino_v_13_DW.is_c1_load_arduino_v_13 =
            load_arduino_v_13_IN_Fase_4_ATO;
        } else {
          load_arduino_v_13_B.Fase_ATO = 3.0;
          load_arduino_v_13_B.psi_ref_selector = 0.0;
          load_arduino_v_13_B.theta_ground_selector = 0.0;
          load_arduino_v_13_B.psi_ref = load_arduino_v_13_B.In_k;
          load_arduino_v_13_B.h_ref = 0.0;
        }
        break;

       default:
        load_arduino_v_13_B.Fase_ATO = 4.0;
        load_arduino_v_13_B.psi_ref_selector = 0.0;
        load_arduino_v_13_B.psi_ref = load_arduino_v_13_B.In_k;
        load_arduino_v_13_B.h_ref = 35.0;
        break;
      }
    }

    /* End of Chart: '<S780>/Chart1' */

    /* Update for Memory: '<S780>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_i =
      load_arduino_v_13_B.psi_ref_selector;

    /* Update for Memory: '<S780>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput_o =
      load_arduino_v_13_B.theta_ground_selector;
  }

  /* End of Outputs for SubSystem: '<S41>/DECOLLO AUTOMATICO' */

  /* S-Function (PWMinterrupt_elevator_v4_4): '<S9>/S-Function Builder1' */
  PWMinterrupt_elevator_v4_4_Outputs_wrapper(&load_arduino_v_13_B.PWM_elevator);

  /* S-Function (PWMinterrupt_aileron_v4_4): '<S9>/S-Function Builder7' */
  PWMinterrupt_aileron_v4_4_Outputs_wrapper(&load_arduino_v_13_B.PWM_aileron);

  /* S-Function (PWMinterrupt_rudder_v4_4): '<S9>/S-Function Builder8' */
  PWMinterrupt_rudder_v4_4_Outputs_wrapper(&load_arduino_v_13_B.PWM_rudder);

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem1' incorporates:
   *  EnablePort: '<S782>/Enable'
   */
  if (load_arduino_v_13_B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S782>/Data Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 42;
         load_arduino_v_13_B.i++) {
      load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.i] =
        load_arduino_v_13_DW.WP_dbP_AL[load_arduino_v_13_B.i];
    }

    /* End of DataTypeConversion: '<S782>/Data Type Conversion4' */

    /* MATLAB Function: '<S782>/CALIBRATING_HOME_COORDINATES' incorporates:
     *  MATLAB Function: '<S795>/MATLAB Function'
     */
    load_arduino_v_13_B.Long_Home = load_arduino_v_13_B.DataTypeConversion4_m[30]
      * 0.017453292519943295;
    load_arduino_v_13_B.h_Home = load_arduino_v_13_B.DataTypeConversion4_m[36];
    load_arduino_v_13_B.Al_selector = cos
      (load_arduino_v_13_B.DataTypeConversion4_m[25] * 0.017453292519943295);
    load_arduino_v_13_B.Gain_o = load_arduino_v_13_B.DataTypeConversion4_m[31] *
      0.017453292519943295 - load_arduino_v_13_B.DataTypeConversion4_m[30] *
      0.017453292519943295;
    load_arduino_v_13_B.Switch_bk = cos
      (load_arduino_v_13_B.DataTypeConversion4_m[24] * 0.017453292519943295);
    load_arduino_v_13_B.Abs1 = sin(load_arduino_v_13_B.DataTypeConversion4_m[24]
      * 0.017453292519943295);
    load_arduino_v_13_B.Al_selector = rt_atan2d_snf(sin
      (load_arduino_v_13_B.Gain_o) * load_arduino_v_13_B.Al_selector,
      load_arduino_v_13_B.Switch_bk * sin
      (load_arduino_v_13_B.DataTypeConversion4_m[25] * 0.017453292519943295) -
      load_arduino_v_13_B.Abs1 * load_arduino_v_13_B.Al_selector * cos
      (load_arduino_v_13_B.Gain_o));
    if (load_arduino_v_13_B.Al_selector < 0.0) {
      load_arduino_v_13_B.Al_selector = 6.2831853071795862 - fabs
        (load_arduino_v_13_B.Al_selector);
    }

    /* MATLAB Function: '<S795>/MATLAB Function' incorporates:
     *  Constant: '<S795>/distance waypoints virtuale'
     *  MATLAB Function: '<S782>/CALIBRATING_HOME_COORDINATES'
     *  Trigonometry: '<S915>/SinCos'
     */
    load_arduino_v_13_B.Abs1_b = sin
      (load_arduino_v_13_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    load_arduino_v_13_B.Sum3_o = cos
      (load_arduino_v_13_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    load_arduino_v_13_B.Gain_o = cos(load_arduino_v_13_B.Al_selector);
    load_arduino_v_13_B.Abs_o = asin(load_arduino_v_13_B.Abs1_b *
      load_arduino_v_13_B.Switch_bk * load_arduino_v_13_B.Gain_o +
      load_arduino_v_13_B.Sum3_o * load_arduino_v_13_B.Abs1);
    load_arduino_v_13_B.rtb_long_end_tmp = sin(load_arduino_v_13_B.Al_selector);

    /* MATLAB Function: '<S795>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S795>/alt waypoint virtuale'
     *  Gain: '<S811>/Gain'
     *  Gain: '<S812>/Gain'
     *  MATLAB Function: '<S795>/MATLAB Function'
     */
    load_arduino_v_13_B.WP_param_c[12] = load_arduino_v_13_P.Gain_Gain_es *
      load_arduino_v_13_B.Abs_o;
    load_arduino_v_13_B.WP_param_c[15] = load_arduino_v_13_P.Gain_Gain_k *
      (rt_atan2d_snf(load_arduino_v_13_B.Abs1_b *
                     load_arduino_v_13_B.rtb_long_end_tmp *
                     load_arduino_v_13_B.Switch_bk, load_arduino_v_13_B.Sum3_o -
                     load_arduino_v_13_B.Abs1 * sin(load_arduino_v_13_B.Abs_o))
       + load_arduino_v_13_B.Long_Home);
    load_arduino_v_13_B.WP_param_c[3] = 1.0;
    load_arduino_v_13_B.WP_param_c[6] = 0.0;
    load_arduino_v_13_B.WP_param_c[9] = 0.0;
    load_arduino_v_13_B.WP_param_c[18] = load_arduino_v_13_B.h_Home +
      load_arduino_v_13_P.altwaypointvirtuale_Value[0];

    /* MATLAB Function: '<S795>/MATLAB Function' incorporates:
     *  Constant: '<S795>/distance waypoints virtuale'
     */
    load_arduino_v_13_B.Abs1_b = sin
      (load_arduino_v_13_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    load_arduino_v_13_B.Sum3_o = cos
      (load_arduino_v_13_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    load_arduino_v_13_B.Abs_o = asin(load_arduino_v_13_B.Abs1_b *
      load_arduino_v_13_B.Switch_bk * load_arduino_v_13_B.Gain_o +
      load_arduino_v_13_B.Sum3_o * load_arduino_v_13_B.Abs1);

    /* MATLAB Function: '<S795>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S795>/Constant1'
     *  Constant: '<S795>/alt waypoint virtuale'
     *  Gain: '<S811>/Gain'
     *  Gain: '<S812>/Gain'
     *  MATLAB Function: '<S795>/MATLAB Function'
     */
    load_arduino_v_13_B.WP_param_c[13] = load_arduino_v_13_P.Gain_Gain_es *
      load_arduino_v_13_B.Abs_o;
    load_arduino_v_13_B.WP_param_c[16] = load_arduino_v_13_P.Gain_Gain_k *
      (rt_atan2d_snf(load_arduino_v_13_B.Abs1_b *
                     load_arduino_v_13_B.rtb_long_end_tmp *
                     load_arduino_v_13_B.Switch_bk, load_arduino_v_13_B.Sum3_o -
                     load_arduino_v_13_B.Abs1 * sin(load_arduino_v_13_B.Abs_o))
       + load_arduino_v_13_B.Long_Home);
    load_arduino_v_13_B.WP_param_c[1] = load_arduino_v_13_P.vel_wp2_al;
    load_arduino_v_13_B.WP_param_c[4] = 1.0;
    load_arduino_v_13_B.WP_param_c[7] = 0.0;
    load_arduino_v_13_B.WP_param_c[10] = 0.0;
    load_arduino_v_13_B.WP_param_c[19] = load_arduino_v_13_B.h_Home +
      load_arduino_v_13_P.altwaypointvirtuale_Value[1];

    /* MATLAB Function: '<S795>/MATLAB Function' incorporates:
     *  Constant: '<S795>/distance waypoints virtuale'
     */
    load_arduino_v_13_B.Abs1_b = sin
      (load_arduino_v_13_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    load_arduino_v_13_B.Sum3_o = cos
      (load_arduino_v_13_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    load_arduino_v_13_B.Abs_o = asin(load_arduino_v_13_B.Abs1_b *
      load_arduino_v_13_B.Switch_bk * load_arduino_v_13_B.Gain_o +
      load_arduino_v_13_B.Sum3_o * load_arduino_v_13_B.Abs1);

    /* MATLAB Function: '<S795>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S795>/Constant'
     *  Constant: '<S795>/Constant1'
     *  Constant: '<S795>/alt waypoint virtuale'
     *  Gain: '<S811>/Gain'
     *  Gain: '<S812>/Gain'
     *  MATLAB Function: '<S795>/MATLAB Function'
     */
    load_arduino_v_13_B.WP_param_c[14] = load_arduino_v_13_P.Gain_Gain_es *
      load_arduino_v_13_B.Abs_o;
    load_arduino_v_13_B.WP_param_c[17] = load_arduino_v_13_P.Gain_Gain_k *
      (rt_atan2d_snf(load_arduino_v_13_B.Abs1_b *
                     load_arduino_v_13_B.rtb_long_end_tmp *
                     load_arduino_v_13_B.Switch_bk, load_arduino_v_13_B.Sum3_o -
                     load_arduino_v_13_B.Abs1 * sin(load_arduino_v_13_B.Abs_o))
       + load_arduino_v_13_B.Long_Home);
    load_arduino_v_13_B.WP_param_c[2] = load_arduino_v_13_P.vel_wp2_al;
    load_arduino_v_13_B.WP_param_c[8] = 0.0;
    load_arduino_v_13_B.WP_param_c[11] = 0.0;
    load_arduino_v_13_B.WP_param_c[20] = load_arduino_v_13_B.h_Home +
      load_arduino_v_13_P.altwaypointvirtuale_Value[2];
    load_arduino_v_13_B.WP_param_c[0] = load_arduino_v_13_P.vel_wp1_al;
    load_arduino_v_13_B.WP_param_c[5] = 0.0;

    /* Gain: '<S800>/Gain' incorporates:
     *  MATLAB Function: '<S782>/CALIBRATING_HOME_COORDINATES'
     */
    load_arduino_v_13_B.Gain = load_arduino_v_13_P.Gain_Gain_p *
      (load_arduino_v_13_B.DataTypeConversion4_m[24] * 0.017453292519943295);

    /* Switch: '<S925>/Switch' incorporates:
     *  Abs: '<S925>/Abs'
     *  Bias: '<S925>/Bias'
     *  Bias: '<S925>/Bias1'
     *  Constant: '<S925>/Constant2'
     *  Constant: '<S926>/Constant'
     *  Math: '<S925>/Math Function1'
     *  RelationalOperator: '<S926>/Compare'
     */
    if (fabs(load_arduino_v_13_B.Gain) >
        load_arduino_v_13_P.CompareToConstant_const) {
      load_arduino_v_13_B.Switch_bk = rt_modd_snf(load_arduino_v_13_B.Gain +
        load_arduino_v_13_P.Bias_Bias_e, load_arduino_v_13_P.Constant2_Value_n)
        + load_arduino_v_13_P.Bias1_Bias_j;
    } else {
      load_arduino_v_13_B.Switch_bk = load_arduino_v_13_B.Gain;
    }

    /* End of Switch: '<S925>/Switch' */

    /* Abs: '<S922>/Abs1' */
    load_arduino_v_13_B.Abs1 = fabs(load_arduino_v_13_B.Switch_bk);

    /* RelationalOperator: '<S924>/Compare' incorporates:
     *  Constant: '<S924>/Constant'
     */
    Ap_sel = (load_arduino_v_13_B.Abs1 >
              load_arduino_v_13_P.CompareToConstant_const_d);

    /* Gain: '<S801>/Gain' */
    load_arduino_v_13_B.Gain_g = load_arduino_v_13_P.Gain_Gain_b2 *
      load_arduino_v_13_B.Long_Home;

    /* Switch: '<S922>/Switch' incorporates:
     *  Bias: '<S922>/Bias'
     *  Bias: '<S922>/Bias1'
     *  Constant: '<S914>/Constant'
     *  Constant: '<S914>/Constant1'
     *  Gain: '<S922>/Gain'
     *  Product: '<S922>/Divide1'
     *  Switch: '<S914>/Switch1'
     */
    if (Ap_sel) {
      /* Signum: '<S922>/Sign1' */
      if (load_arduino_v_13_B.Switch_bk < 0.0) {
        load_arduino_v_13_B.Switch_bk = -1.0;
      } else if (load_arduino_v_13_B.Switch_bk > 0.0) {
        load_arduino_v_13_B.Switch_bk = 1.0;
      } else if (load_arduino_v_13_B.Switch_bk == 0.0) {
        load_arduino_v_13_B.Switch_bk = 0.0;
      } else {
        load_arduino_v_13_B.Switch_bk = (rtNaN);
      }

      /* End of Signum: '<S922>/Sign1' */
      load_arduino_v_13_B.Switch_bk *= (load_arduino_v_13_B.Abs1 +
        load_arduino_v_13_P.Bias_Bias_f) * load_arduino_v_13_P.Gain_Gain_mn +
        load_arduino_v_13_P.Bias1_Bias_f;
      load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Constant_Value_d;
    } else {
      load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Constant1_Value_d;
    }

    /* End of Switch: '<S922>/Switch' */

    /* Sum: '<S914>/Sum' */
    load_arduino_v_13_B.Abs1 = load_arduino_v_13_B.Long_Home +
      load_arduino_v_13_B.Gain_g;

    /* Sum: '<S799>/Sum1' incorporates:
     *  Gain: '<S803>/Gain'
     */
    load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Gain_Gain_fi *
      load_arduino_v_13_B.Gain1_f - load_arduino_v_13_B.Switch_bk;

    /* Switch: '<S919>/Switch' incorporates:
     *  Abs: '<S919>/Abs'
     *  Bias: '<S919>/Bias'
     *  Bias: '<S919>/Bias1'
     *  Constant: '<S919>/Constant2'
     *  Constant: '<S920>/Constant'
     *  Math: '<S919>/Math Function1'
     *  RelationalOperator: '<S920>/Compare'
     */
    if (fabs(load_arduino_v_13_B.Long_Home) >
        load_arduino_v_13_P.CompareToConstant_const_b) {
      load_arduino_v_13_B.Long_Home = rt_modd_snf(load_arduino_v_13_B.Long_Home
        + load_arduino_v_13_P.Bias_Bias_n, load_arduino_v_13_P.Constant2_Value_i)
        + load_arduino_v_13_P.Bias1_Bias_n;
    }

    /* End of Switch: '<S919>/Switch' */

    /* Abs: '<S916>/Abs1' */
    load_arduino_v_13_B.Abs1_b = fabs(load_arduino_v_13_B.Long_Home);

    /* Switch: '<S916>/Switch' incorporates:
     *  Bias: '<S916>/Bias'
     *  Bias: '<S916>/Bias1'
     *  Constant: '<S913>/Constant'
     *  Constant: '<S913>/Constant1'
     *  Constant: '<S918>/Constant'
     *  Gain: '<S916>/Gain'
     *  Product: '<S916>/Divide1'
     *  RelationalOperator: '<S918>/Compare'
     *  Switch: '<S913>/Switch1'
     */
    if (load_arduino_v_13_B.Abs1_b >
        load_arduino_v_13_P.CompareToConstant_const_dp) {
      /* Signum: '<S916>/Sign1' */
      if (load_arduino_v_13_B.Long_Home < 0.0) {
        load_arduino_v_13_B.Long_Home = -1.0;
      } else if (load_arduino_v_13_B.Long_Home > 0.0) {
        load_arduino_v_13_B.Long_Home = 1.0;
      } else if (load_arduino_v_13_B.Long_Home == 0.0) {
        load_arduino_v_13_B.Long_Home = 0.0;
      } else {
        load_arduino_v_13_B.Long_Home = (rtNaN);
      }

      /* End of Signum: '<S916>/Sign1' */
      load_arduino_v_13_B.IProdOut_b = ((load_arduino_v_13_B.Abs1_b +
        load_arduino_v_13_P.Bias_Bias) * load_arduino_v_13_P.Gain_Gain_b +
        load_arduino_v_13_P.Bias1_Bias) * load_arduino_v_13_B.Long_Home;
      load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Constant_Value_n;
    } else {
      load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_B.Long_Home;
      load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Constant1_Value_p;
    }

    /* End of Switch: '<S916>/Switch' */

    /* Switch: '<S923>/Switch' incorporates:
     *  Abs: '<S923>/Abs'
     *  Bias: '<S923>/Bias'
     *  Bias: '<S923>/Bias1'
     *  Constant: '<S923>/Constant2'
     *  Constant: '<S927>/Constant'
     *  Math: '<S923>/Math Function1'
     *  RelationalOperator: '<S927>/Compare'
     */
    if (fabs(load_arduino_v_13_B.Abs1) >
        load_arduino_v_13_P.CompareToConstant_const_p) {
      load_arduino_v_13_B.Abs1 = rt_modd_snf(load_arduino_v_13_B.Abs1 +
        load_arduino_v_13_P.Bias_Bias_jc, load_arduino_v_13_P.Constant2_Value_b)
        + load_arduino_v_13_P.Bias1_Bias_gb;
    }

    /* End of Switch: '<S923>/Switch' */

    /* Sum: '<S913>/Sum' incorporates:
     *  Gain: '<S802>/Gain'
     *  Sum: '<S799>/Sum1'
     */
    load_arduino_v_13_B.Abs1_b = (load_arduino_v_13_P.Gain_Gain_d *
      load_arduino_v_13_B.Gain1_p - load_arduino_v_13_B.Abs1) +
      load_arduino_v_13_B.Long_Home;

    /* Gain: '<S912>/Gain1' */
    load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Gain1_Gain_p *
      load_arduino_v_13_B.IProdOut_b;

    /* Sum: '<S930>/Sum' incorporates:
     *  Constant: '<S930>/Constant'
     *  Constant: '<S930>/f'
     */
    load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_P.f_Value -
      load_arduino_v_13_P.Constant_Value_j;

    /* Sqrt: '<S932>/sqrt' incorporates:
     *  Constant: '<S932>/Constant'
     *  Product: '<S932>/Product1'
     *  Sum: '<S932>/Sum1'
     */
    load_arduino_v_13_B.IProdOut_b = sqrt(load_arduino_v_13_P.Constant_Value_b -
      load_arduino_v_13_B.IProdOut_b * load_arduino_v_13_B.IProdOut_b);

    /* Gain: '<S929>/Gain1' */
    load_arduino_v_13_B.Switch_bk *= load_arduino_v_13_P.Gain1_Gain_j;

    /* Trigonometry: '<S931>/Trigonometric Function1' */
    load_arduino_v_13_B.err = sin(load_arduino_v_13_B.Switch_bk);

    /* Sum: '<S931>/Sum1' incorporates:
     *  Constant: '<S931>/Constant'
     *  Product: '<S931>/Product1'
     */
    load_arduino_v_13_B.err = load_arduino_v_13_P.Constant_Value_nw -
      load_arduino_v_13_B.IProdOut_b * load_arduino_v_13_B.IProdOut_b *
      load_arduino_v_13_B.err * load_arduino_v_13_B.err;

    /* Product: '<S928>/Product1' incorporates:
     *  Constant: '<S928>/Constant1'
     *  Sqrt: '<S928>/sqrt'
     */
    load_arduino_v_13_B.Abs1 = load_arduino_v_13_P.Constant1_Value_j / sqrt
      (load_arduino_v_13_B.err);

    /* Product: '<S915>/dNorth' incorporates:
     *  Constant: '<S928>/Constant'
     *  Constant: '<S928>/Constant2'
     *  Product: '<S928>/Product2'
     *  Product: '<S928>/Product3'
     *  Sum: '<S928>/Sum1'
     *  Trigonometry: '<S928>/Trigonometric Function1'
     */
    load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_B.Long_Home /
      rt_atan2d_snf(load_arduino_v_13_P.Constant2_Value_jx,
                    (load_arduino_v_13_P.Constant_Value_hg -
                     load_arduino_v_13_B.IProdOut_b *
                     load_arduino_v_13_B.IProdOut_b) * load_arduino_v_13_B.Abs1 /
                    load_arduino_v_13_B.err);

    /* Switch: '<S917>/Switch' incorporates:
     *  Abs: '<S917>/Abs'
     *  Bias: '<S917>/Bias'
     *  Bias: '<S917>/Bias1'
     *  Constant: '<S917>/Constant2'
     *  Constant: '<S921>/Constant'
     *  Math: '<S917>/Math Function1'
     *  RelationalOperator: '<S921>/Compare'
     */
    if (fabs(load_arduino_v_13_B.Abs1_b) >
        load_arduino_v_13_P.CompareToConstant_const_g) {
      load_arduino_v_13_B.Abs1_b = rt_modd_snf(load_arduino_v_13_B.Abs1_b +
        load_arduino_v_13_P.Bias_Bias_j, load_arduino_v_13_P.Constant2_Value_gk)
        + load_arduino_v_13_P.Bias1_Bias_g;
    }

    /* End of Switch: '<S917>/Switch' */

    /* Product: '<S915>/dEast' incorporates:
     *  Constant: '<S928>/Constant3'
     *  Gain: '<S912>/Gain1'
     *  Product: '<S928>/Product4'
     *  Trigonometry: '<S928>/Trigonometric Function'
     *  Trigonometry: '<S928>/Trigonometric Function2'
     */
    load_arduino_v_13_B.Switch_bk = 1.0 / rt_atan2d_snf
      (load_arduino_v_13_P.Constant3_Value_f, load_arduino_v_13_B.Abs1 * cos
       (load_arduino_v_13_B.Switch_bk)) * (load_arduino_v_13_P.Gain1_Gain_p *
      load_arduino_v_13_B.Abs1_b);

    /* Sum: '<S915>/Sum2' incorporates:
     *  Product: '<S915>/x*cos'
     *  Product: '<S915>/y*sin'
     */
    load_arduino_v_13_B.Long_Home = load_arduino_v_13_B.IProdOut_b *
      load_arduino_v_13_B.Gain_o + load_arduino_v_13_B.Switch_bk *
      load_arduino_v_13_B.rtb_long_end_tmp;

    /* Gain: '<S804>/Gain' */
    load_arduino_v_13_B.Gain_k3 = load_arduino_v_13_P.Gain_Gain_o *
      load_arduino_v_13_B.Gain1_f;

    /* Gain: '<S805>/Gain' */
    load_arduino_v_13_B.Gain_n = load_arduino_v_13_P.Gain_Gain_ov *
      load_arduino_v_13_B.Gain1_p;

    /* Gain: '<S806>/Gain' */
    load_arduino_v_13_B.Abs1 = load_arduino_v_13_P.Gain_Gain_jp *
      load_arduino_v_13_B.Gain1_c;

    /* MATLAB Function: '<S782>/ALLINEAMENTO' incorporates:
     *  DataTypeConversion: '<S947>/Data Type Conversion5'
     *  Memory: '<S782>/Memory7'
     */
    load_arduino_v_13_B.firstcol = (int32_T)
      load_arduino_v_13_DW.Memory7_PreviousInput;
    load_arduino_v_13_B.Abs1_b =
      load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.firstcol + 17];
    load_arduino_v_13_B.Sum3_o =
      load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.firstcol + 11];
    load_arduino_v_13_B.a = sin((load_arduino_v_13_B.Sum3_o -
      load_arduino_v_13_B.Gain_k3) * 3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_13_B.Abs_o =
      load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.firstcol + 14];
    load_arduino_v_13_B.b_x_tmp = (load_arduino_v_13_B.Abs_o -
      load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0;
    load_arduino_v_13_B.dist = sin(load_arduino_v_13_B.b_x_tmp / 2.0);
    load_arduino_v_13_B.psi_ref_n = load_arduino_v_13_B.Sum3_o *
      3.1415926535897931 / 180.0;
    load_arduino_v_13_B.angoloWP = cos(load_arduino_v_13_B.psi_ref_n);
    load_arduino_v_13_B.Sum_n3 = load_arduino_v_13_B.Gain_k3 *
      3.1415926535897931 / 180.0;
    load_arduino_v_13_B.err = cos(load_arduino_v_13_B.Sum_n3);
    load_arduino_v_13_B.a = load_arduino_v_13_B.angoloWP *
      load_arduino_v_13_B.err * (load_arduino_v_13_B.dist *
      load_arduino_v_13_B.dist) + load_arduino_v_13_B.a * load_arduino_v_13_B.a;
    load_arduino_v_13_B.a = rt_atan2d_snf(sqrt(load_arduino_v_13_B.a), sqrt(1.0
      - load_arduino_v_13_B.a)) * 2.0 * 6.378137E+6;
    if (load_arduino_v_13_DW.Memory7_PreviousInput > 1.0) {
      load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
        (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0);
      load_arduino_v_13_B.psi_ref_pre =
        load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.tolleranza_distWP_fut
        + 11];
      load_arduino_v_13_B.psi_ref_n = load_arduino_v_13_B.psi_ref_pre *
        3.1415926535897931 / 180.0;
      load_arduino_v_13_B.dist_fut =
        load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.tolleranza_distWP_fut
        + 14];
      load_arduino_v_13_B.psi_ref_tmp = (load_arduino_v_13_B.Abs_o -
        load_arduino_v_13_B.dist_fut) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.dist = cos(load_arduino_v_13_B.psi_ref_n);
      load_arduino_v_13_B.psi_ref_n = rt_atan2d_snf(sin
        (load_arduino_v_13_B.psi_ref_tmp) * load_arduino_v_13_B.angoloWP,
        load_arduino_v_13_B.dist * sin(load_arduino_v_13_B.WP_param_c[(int32_T)
        load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
        180.0) - sin(load_arduino_v_13_B.psi_ref_n) *
        load_arduino_v_13_B.angoloWP * cos(load_arduino_v_13_B.psi_ref_tmp)) *
        180.0 / 3.1415926535897931;
      load_arduino_v_13_B.psi_ref_pre = sin((load_arduino_v_13_B.Gain_k3 -
        load_arduino_v_13_B.psi_ref_pre) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_13_B.dist_fut = sin((load_arduino_v_13_B.Gain_n -
        load_arduino_v_13_B.dist_fut) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_13_B.dist = load_arduino_v_13_B.dist *
        load_arduino_v_13_B.err * (load_arduino_v_13_B.dist_fut *
        load_arduino_v_13_B.dist_fut) + load_arduino_v_13_B.psi_ref_pre *
        load_arduino_v_13_B.psi_ref_pre;
      load_arduino_v_13_B.dist = rt_atan2d_snf(sqrt(load_arduino_v_13_B.dist),
        sqrt(1.0 - load_arduino_v_13_B.dist)) * 2.0 * 6.378137E+6;
    } else {
      load_arduino_v_13_B.psi_ref_n = rt_atan2d_snf(sin
        (load_arduino_v_13_B.b_x_tmp) * load_arduino_v_13_B.angoloWP, sin
        (load_arduino_v_13_B.psi_ref_n) * load_arduino_v_13_B.err -
        load_arduino_v_13_B.angoloWP * sin(load_arduino_v_13_B.Sum_n3) * cos
        (load_arduino_v_13_B.b_x_tmp)) * 180.0 / 3.1415926535897931;
      load_arduino_v_13_B.dist = 0.0;
    }

    if (load_arduino_v_13_B.psi_ref_n < 0.0) {
      load_arduino_v_13_B.psi_ref_n = 360.0 - fabs(load_arduino_v_13_B.psi_ref_n);
    }

    load_arduino_v_13_B.Sum4_n =
      load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.firstcol + 2];
    if (load_arduino_v_13_B.Sum4_n == 1.0) {
      load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
        (load_arduino_v_13_DW.Memory7_PreviousInput + 1.0);
      load_arduino_v_13_B.psi_ref_tmp =
        load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.tolleranza_distWP_fut
        + 11];
      load_arduino_v_13_B.dist_fut = sin((load_arduino_v_13_B.psi_ref_tmp -
        load_arduino_v_13_B.Sum3_o) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_13_B.psi_ref_pre =
        (load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.tolleranza_distWP_fut
         + 14] - load_arduino_v_13_B.Abs_o) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.f_x = sin(load_arduino_v_13_B.psi_ref_pre / 2.0);
      load_arduino_v_13_B.psi_ref_tmp = load_arduino_v_13_B.psi_ref_tmp *
        3.1415926535897931 / 180.0;
      load_arduino_v_13_B.a_fut_tmp = cos(load_arduino_v_13_B.psi_ref_tmp);
      load_arduino_v_13_B.dist_fut = load_arduino_v_13_B.a_fut_tmp *
        load_arduino_v_13_B.angoloWP * (load_arduino_v_13_B.f_x *
        load_arduino_v_13_B.f_x) + load_arduino_v_13_B.dist_fut *
        load_arduino_v_13_B.dist_fut;
      load_arduino_v_13_B.dist_fut = rt_atan2d_snf(sqrt
        (load_arduino_v_13_B.dist_fut), sqrt(1.0 - load_arduino_v_13_B.dist_fut))
        * 2.0 * 6.378137E+6;
      load_arduino_v_13_B.angoloWP = rt_atan2d_snf(sin
        (load_arduino_v_13_B.psi_ref_pre) * load_arduino_v_13_B.a_fut_tmp, sin
        (load_arduino_v_13_B.psi_ref_tmp) * load_arduino_v_13_B.angoloWP -
        load_arduino_v_13_B.a_fut_tmp * sin(load_arduino_v_13_B.WP_param_c
        [(int32_T)load_arduino_v_13_DW.Memory7_PreviousInput + 11] *
        3.1415926535897931 / 180.0) * cos(load_arduino_v_13_B.psi_ref_pre)) *
        180.0 / 3.1415926535897931;
      if (load_arduino_v_13_B.angoloWP < 0.0) {
        load_arduino_v_13_B.angoloWP = 360.0 - fabs(load_arduino_v_13_B.angoloWP);
      }

      if (load_arduino_v_13_DW.Memory7_PreviousInput > 1.0) {
        load_arduino_v_13_B.angoloWP = fabs(load_arduino_v_13_B.angoloWP -
          load_arduino_v_13_B.psi_ref_n);
      } else {
        load_arduino_v_13_B.angoloWP = fabs(load_arduino_v_13_B.angoloWP -
          rt_atan2d_snf(sin((load_arduino_v_13_B.WP_param_c[(int32_T)
                             load_arduino_v_13_DW.Memory7_PreviousInput + 14] -
                             load_arduino_v_13_B.Gain_n) * 3.1415926535897931 /
                            180.0) * cos(load_arduino_v_13_B.WP_param_c[(int32_T)
          load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
          180.0), sin(load_arduino_v_13_B.WP_param_c[(int32_T)
                      load_arduino_v_13_DW.Memory7_PreviousInput + 11] *
                      3.1415926535897931 / 180.0) * cos
                        (load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 /
                         180.0) - cos(load_arduino_v_13_B.WP_param_c[(int32_T)
          load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
          180.0) * sin(load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 / 180.0)
                        * cos((load_arduino_v_13_B.WP_param_c[(int32_T)
          load_arduino_v_13_DW.Memory7_PreviousInput + 14] -
          load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      load_arduino_v_13_B.dist_fut = 0.0;
      load_arduino_v_13_B.angoloWP = 0.0;
    }

    if (load_arduino_v_13_DW.Memory7_PreviousInput < 2.0) {
      load_arduino_v_13_B.psi_ref_pre = 0.0;
    } else if (load_arduino_v_13_DW.Memory7_PreviousInput == 2.0) {
      load_arduino_v_13_B.psi_ref_pre = (load_arduino_v_13_B.WP_param_c[(int32_T)
        (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 14] -
        load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.psi_ref_pre = fabs(load_arduino_v_13_B.psi_ref_n -
        rt_atan2d_snf(sin(load_arduino_v_13_B.psi_ref_pre) * cos
                      (load_arduino_v_13_B.WP_param_c[(int32_T)
                       (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 11] *
                       3.1415926535897931 / 180.0), sin
                      (load_arduino_v_13_B.WP_param_c[(int32_T)
                       (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 11] *
                       3.1415926535897931 / 180.0) * load_arduino_v_13_B.err -
                      cos(load_arduino_v_13_B.WP_param_c[(int32_T)
                          (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) +
                          11] * 3.1415926535897931 / 180.0) * sin
                      (load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 / 180.0)
                      * cos(load_arduino_v_13_B.psi_ref_pre)) * 180.0 /
        3.1415926535897931);
    } else {
      load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
        (load_arduino_v_13_DW.Memory7_PreviousInput - 2.0);
      load_arduino_v_13_B.psi_ref_pre =
        load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.tolleranza_distWP_fut
        + 11] * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.psi_ref_tmp = (load_arduino_v_13_B.WP_param_c[(int32_T)
        (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 14] -
        load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.tolleranza_distWP_fut
        + 14]) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.psi_ref_pre = rt_atan2d_snf(sin
        (load_arduino_v_13_B.psi_ref_tmp) * cos(load_arduino_v_13_B.WP_param_c
        [(int32_T)(load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0), cos(load_arduino_v_13_B.psi_ref_pre) * sin
        (load_arduino_v_13_B.WP_param_c[(int32_T)
         (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0) - sin(load_arduino_v_13_B.psi_ref_pre) *
        cos(load_arduino_v_13_B.WP_param_c[(int32_T)
            (load_arduino_v_13_DW.Memory7_PreviousInput - 1.0) + 11] *
            3.1415926535897931 / 180.0) * cos(load_arduino_v_13_B.psi_ref_tmp)) *
        180.0 / 3.1415926535897931;
      if (load_arduino_v_13_B.psi_ref_pre < 0.0) {
        load_arduino_v_13_B.psi_ref_pre = 360.0 - fabs
          (load_arduino_v_13_B.psi_ref_pre);
      }

      load_arduino_v_13_B.psi_ref_pre = fabs(load_arduino_v_13_B.psi_ref_n -
        load_arduino_v_13_B.psi_ref_pre);
    }

    if (load_arduino_v_13_B.angoloWP <= 3.0) {
      load_arduino_v_13_B.angoloWP = 1.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 20;
    } else if (load_arduino_v_13_B.angoloWP <= 10.0) {
      load_arduino_v_13_B.angoloWP = 30.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 100;
    } else if ((load_arduino_v_13_B.angoloWP > 10.0) &&
               (load_arduino_v_13_B.angoloWP <= 50.0)) {
      load_arduino_v_13_B.angoloWP = 80.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 250;
    } else if ((load_arduino_v_13_B.angoloWP > 50.0) &&
               (load_arduino_v_13_B.angoloWP <= 90.0)) {
      load_arduino_v_13_B.angoloWP = 100.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 300;
    } else if ((load_arduino_v_13_B.angoloWP > 90.0) &&
               (load_arduino_v_13_B.angoloWP <= 120.0)) {
      load_arduino_v_13_B.angoloWP = 150.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 350;
    } else {
      load_arduino_v_13_B.angoloWP = 200.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 400;
    }

    if (load_arduino_v_13_B.psi_ref_pre <= 10.0) {
      load_arduino_v_13_B.soglia_dist = 80;
    } else if ((load_arduino_v_13_B.psi_ref_pre > 10.0) &&
               (load_arduino_v_13_B.psi_ref_pre <= 50.0)) {
      load_arduino_v_13_B.soglia_dist = 200;
    } else if ((load_arduino_v_13_B.psi_ref_pre > 50.0) &&
               (load_arduino_v_13_B.psi_ref_pre <= 90.0)) {
      load_arduino_v_13_B.soglia_dist = 300;
    } else if ((load_arduino_v_13_B.psi_ref_pre > 90.0) &&
               (load_arduino_v_13_B.psi_ref_pre <= 120.0)) {
      load_arduino_v_13_B.soglia_dist = 350;
    } else {
      load_arduino_v_13_B.soglia_dist = 400;
    }

    if (load_arduino_v_13_B.Sum4_n == 1.0) {
      load_arduino_v_13_B.Switch1 = rt_atan2d_snf(sin
        ((load_arduino_v_13_B.WP_param_c[(int32_T)
          load_arduino_v_13_DW.Memory7_PreviousInput + 14] -
          load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.WP_param_c[(int32_T)
         load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_13_B.WP_param_c[(int32_T)
                     load_arduino_v_13_DW.Memory7_PreviousInput + 11] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_13_B.WP_param_c[(int32_T)
         load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_13_B.WP_param_c[(int32_T)
             load_arduino_v_13_DW.Memory7_PreviousInput + 14] -
             load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0)) * 180.0 /
        3.1415926535897931;
      load_arduino_v_13_B.Sum4_n =
        load_arduino_v_13_B.WP_param_c[load_arduino_v_13_B.firstcol - 1];
      if (load_arduino_v_13_B.Sum4_n <= 20.0) {
        load_arduino_v_13_B.angoloWP *= 1.1;
      } else if ((load_arduino_v_13_B.Sum4_n <= 25.0) &&
                 (load_arduino_v_13_B.Sum4_n > 20.0)) {
        load_arduino_v_13_B.angoloWP *= 1.2;
      } else if (load_arduino_v_13_B.Sum4_n <= 30.0) {
        if (load_arduino_v_13_B.Sum4_n > 25.0) {
          load_arduino_v_13_B.angoloWP *= 1.3;
        } else {
          load_arduino_v_13_B.angoloWP *= 1.4;
        }
      } else {
        load_arduino_v_13_B.angoloWP *= 1.4;
      }

      if ((!(load_arduino_v_13_B.dist < load_arduino_v_13_B.soglia_dist)) ||
          (!(load_arduino_v_13_B.a > load_arduino_v_13_B.angoloWP))) {
        if ((load_arduino_v_13_B.dist > load_arduino_v_13_B.soglia_dist) &&
            (load_arduino_v_13_B.a > load_arduino_v_13_B.angoloWP)) {
          load_arduino_v_13_B.err = fabs(load_arduino_v_13_B.Switch1 -
            load_arduino_v_13_B.psi_ref_n);
          if ((load_arduino_v_13_B.psi_ref_n <= 90.0) &&
              (load_arduino_v_13_B.psi_ref_n >= 0.0)) {
            if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
              load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
            } else {
              if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n <= 180.0) &&
                     (load_arduino_v_13_B.psi_ref_n > 90.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.Switch1 >
                0.0) {
              if ((load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.Switch1 < -90.0) &&
                   (load_arduino_v_13_B.Switch1 > -180.0))) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 - fabs
                (load_arduino_v_13_B.Switch1)) - load_arduino_v_13_B.psi_ref_n);
              if ((load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.Switch1 < -90.0) &&
                   (load_arduino_v_13_B.Switch1 > -180.0))) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n < -90.0) &&
                     (load_arduino_v_13_B.psi_ref_n >= -180.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.Switch1 >
                0.0) {
              if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 -
                load_arduino_v_13_B.Switch1) - fabs
                (load_arduino_v_13_B.psi_ref_n));
              if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else {
            if ((load_arduino_v_13_B.psi_ref_n < 0.0) &&
                (load_arduino_v_13_B.psi_ref_n >= -90.0)) {
              if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          }
        } else {
          if (load_arduino_v_13_B.a < load_arduino_v_13_B.angoloWP) {
            if (load_arduino_v_13_B.dist_fut >
                load_arduino_v_13_B.tolleranza_distWP_fut) {
              load_arduino_v_13_B.a = (load_arduino_v_13_B.WP_param_c[(int32_T)
                (load_arduino_v_13_DW.Memory7_PreviousInput + 1.0) + 14] -
                load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0;
              load_arduino_v_13_B.Switch1 = rt_atan2d_snf(sin
                (load_arduino_v_13_B.a) * cos(load_arduino_v_13_B.WP_param_c
                [(int32_T)(load_arduino_v_13_DW.Memory7_PreviousInput + 1.0) +
                11] * 3.1415926535897931 / 180.0), sin
                (load_arduino_v_13_B.WP_param_c[(int32_T)
                 (load_arduino_v_13_DW.Memory7_PreviousInput + 1.0) + 11] *
                 3.1415926535897931 / 180.0) * load_arduino_v_13_B.err - cos
                (load_arduino_v_13_B.WP_param_c[(int32_T)
                 (load_arduino_v_13_DW.Memory7_PreviousInput + 1.0) + 11] *
                 3.1415926535897931 / 180.0) * sin(load_arduino_v_13_B.Gain_k3 *
                3.1415926535897931 / 180.0) * cos(load_arduino_v_13_B.a)) *
                180.0 / 3.1415926535897931;
              load_arduino_v_13_DW.Memory7_PreviousInput++;
            } else if (load_arduino_v_13_DW.Memory7_PreviousInput < 2.0) {
              load_arduino_v_13_DW.Memory7_PreviousInput += 2.0;
            } else {
              load_arduino_v_13_B.Abs1_b = load_arduino_v_13_B.ByteUnpack_o2_e[2]
                + 0.4;
              load_arduino_v_13_B.Switch1 = load_arduino_v_13_B.Abs1 + 36.6;
              load_arduino_v_13_DW.flag_m = 1.0;
            }
          }
        }
      }
    } else {
      load_arduino_v_13_B.Switch1 = rt_atan2d_snf(sin
        ((load_arduino_v_13_B.WP_param_c[(int32_T)
          load_arduino_v_13_DW.Memory7_PreviousInput + 14] -
          load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.WP_param_c[(int32_T)
         load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_13_B.WP_param_c[(int32_T)
                     load_arduino_v_13_DW.Memory7_PreviousInput + 11] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_13_B.WP_param_c[(int32_T)
         load_arduino_v_13_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_13_B.Gain_k3 * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_13_B.WP_param_c[(int32_T)
             load_arduino_v_13_DW.Memory7_PreviousInput + 14] -
             load_arduino_v_13_B.Gain_n) * 3.1415926535897931 / 180.0)) * 180.0 /
        3.1415926535897931;
      if ((!(load_arduino_v_13_B.dist < load_arduino_v_13_B.soglia_dist)) ||
          (!(load_arduino_v_13_DW.flag_m == 0.0))) {
        if ((load_arduino_v_13_B.dist > load_arduino_v_13_B.soglia_dist) &&
            (load_arduino_v_13_B.a > 40.0) && (load_arduino_v_13_DW.flag_m ==
             0.0)) {
          load_arduino_v_13_B.err = fabs(load_arduino_v_13_B.Switch1 -
            load_arduino_v_13_B.psi_ref_n);
          if ((load_arduino_v_13_B.psi_ref_n <= 90.0) &&
              (load_arduino_v_13_B.psi_ref_n >= 0.0)) {
            if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
              load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
            } else {
              if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n <= 180.0) &&
                     (load_arduino_v_13_B.psi_ref_n > 90.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.Switch1 >
                0.0) {
              if ((load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.Switch1 < -90.0) &&
                   (load_arduino_v_13_B.Switch1 > -180.0))) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 - fabs
                (load_arduino_v_13_B.Switch1)) - load_arduino_v_13_B.psi_ref_n);
              if ((load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.Switch1 < -90.0) &&
                   (load_arduino_v_13_B.Switch1 > -180.0))) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n < -90.0) &&
                     (load_arduino_v_13_B.psi_ref_n >= -180.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.Switch1 >
                0.0) {
              if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 -
                load_arduino_v_13_B.Switch1) - fabs
                (load_arduino_v_13_B.psi_ref_n));
              if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else {
            if ((load_arduino_v_13_B.psi_ref_n < 0.0) &&
                (load_arduino_v_13_B.psi_ref_n >= -90.0)) {
              if (load_arduino_v_13_B.Switch1 > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.Switch1 += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.Switch1 < load_arduino_v_13_B.psi_ref_n)
                {
                  load_arduino_v_13_B.Switch1 -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          }
        } else {
          load_arduino_v_13_B.Abs1_b = load_arduino_v_13_B.ByteUnpack_o2_e[2] +
            0.4;
          load_arduino_v_13_B.Switch1 = load_arduino_v_13_B.Abs1 + 36.6;
          load_arduino_v_13_DW.flag_m = 1.0;
        }
      }
    }

    if ((load_arduino_v_13_B.Sum3_o == 0.0) && (load_arduino_v_13_B.Abs_o == 0.0)
        && (load_arduino_v_13_B.Abs1_b == 0.0)) {
      load_arduino_v_13_B.Switch1 = load_arduino_v_13_B.Abs1 + 36.6;
    }

    if (!(load_arduino_v_13_B.modo == 4.0)) {
      load_arduino_v_13_DW.Memory7_PreviousInput = 1.0;
    }

    /* End of MATLAB Function: '<S782>/ALLINEAMENTO' */

    /* Abs: '<S782>/Abs1' */
    load_arduino_v_13_B.Abs1 = fabs(load_arduino_v_13_B.Long_Home);

    /* Chart: '<S782>/Chart1' incorporates:
     *  DataTypeConversion: '<S947>/Data Type Conversion5'
     *  Memory: '<S782>/Memory1'
     *  Memory: '<S782>/Memory2'
     *  Memory: '<S782>/Memory5'
     */
    if (load_arduino_v_13_DW.is_active_c10_load_arduino_v_13 == 0U) {
      load_arduino_v_13_DW.is_active_c10_load_arduino_v_13 = 1U;
      load_arduino_v_13_B.maneuver_selector = 1.0;
      load_arduino_v_13_B.trig_approach = 0.0;
      load_arduino_v_13_B.trig_flare = 0.0;
      load_arduino_v_13_B.approach_selector = 1.0;
      load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
        load_arduino_v_1_IN_Allignment1;
    } else {
      switch (load_arduino_v_13_DW.is_c10_load_arduino_v_13) {
       case load_arduino_v_13_IN_Abort:
        load_arduino_v_13_B.maneuver_selector = 1.0;
        load_arduino_v_13_B.trig_approach = 0.0;
        load_arduino_v_13_B.trig_flare = 0.0;
        load_arduino_v_13_B.approach_selector = 0.0;
        break;

       case load_arduino_v_13_IN_Allignment:
        if ((load_arduino_v_13_B.ByteUnpack_o2_e[2] > 35.0F) &&
            (load_arduino_v_13_B.ByteUnpack_o2_e[2] < 60.0F) &&
            (load_arduino_v_13_B.Abs1 <= load_arduino_v_13_B.ByteUnpack_o2_e[2] *
             19.081136687728211 + 100.0) && (load_arduino_v_13_B.Abs1 >=
             load_arduino_v_13_B.ByteUnpack_o2_e[2] * 14.300666256711928 + 100.0)
            && (load_arduino_v_13_DW.Memory7_PreviousInput > 1.0)) {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_13_IN_Approach;
        } else if (load_arduino_v_13_B.modo != 4.0) {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_1_IN_Allignment1;
        } else {
          load_arduino_v_13_B.trig_flare = 0.0;
          load_arduino_v_13_B.approach_selector = 0.0;
          load_arduino_v_13_B.maneuver_selector = 1.0;
          load_arduino_v_13_B.trig_approach = 0.0;
        }
        break;

       case load_arduino_v_1_IN_Allignment1:
        if (load_arduino_v_13_B.modo == 4.0) {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_13_IN_Allignment;
        } else {
          load_arduino_v_13_B.maneuver_selector = 1.0;
          load_arduino_v_13_B.trig_approach = 0.0;
          load_arduino_v_13_B.trig_flare = 0.0;
          load_arduino_v_13_B.approach_selector = 0.0;
        }
        break;

       case load_arduino_v_13_IN_Approach:
        if ((load_arduino_v_13_B.Long_Home >=
             load_arduino_v_13_DW.Memory5_PreviousInput) &&
            ((load_arduino_v_13_B.ByteUnpack_o2_e[2] <=
              load_arduino_v_13_DW.Memory1_PreviousInput_l + 1.5) ||
             (load_arduino_v_13_B.ByteUnpack_o2_e[2] >
              load_arduino_v_13_DW.Memory1_PreviousInput_l - 1.0))) {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_13_IN_Flare;
        } else if (load_arduino_v_13_B.modo != 4.0) {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_1_IN_Allignment1;
        } else if (load_arduino_v_13_DW.Memory2_PreviousInput_f == 1.0) {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_13_IN_Abort;
        } else {
          load_arduino_v_13_B.trig_flare = 0.0;
          load_arduino_v_13_B.trig_approach = 1.0;
          load_arduino_v_13_B.approach_selector = 1.0;
          load_arduino_v_13_B.maneuver_selector = 2.0;
        }
        break;

       default:
        if ((load_arduino_v_13_B.Product1 < 3.0) || (!(load_arduino_v_13_B.modo
              != 4.0))) {
          load_arduino_v_13_B.trig_approach = 0.0;
          load_arduino_v_13_B.trig_flare = 1.0;
          load_arduino_v_13_B.approach_selector = 0.0;
          load_arduino_v_13_B.maneuver_selector = 3.0;
        } else {
          load_arduino_v_13_DW.is_c10_load_arduino_v_13 =
            load_arduino_v_1_IN_Allignment1;
        }
        break;
      }
    }

    /* End of Chart: '<S782>/Chart1' */

    /* Outputs for Triggered SubSystem: '<S782>/Sample and Hold' incorporates:
     *  TriggerPort: '<S807>/Trigger'
     */
    load_arduino_v_13_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &load_arduino_v_13_PrevZCX.SampleandHold_Trig_ZCE,
      (load_arduino_v_13_B.approach_selector));
    if (load_arduino_v_13_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S807>/In' incorporates:
       *  Abs: '<S782>/Abs2'
       *  Constant: '<S782>/Constant4'
       *  DataTypeConversion: '<S947>/Data Type Conversion5'
       *  Sum: '<S799>/Sum'
       *  UnaryMinus: '<S799>/Ze2height'
       */
      load_arduino_v_13_B.In[0] = fabs(-(load_arduino_v_13_B.ByteUnpack_o2_e[2]
        + load_arduino_v_13_P.Constant4_Value_j));
      load_arduino_v_13_B.In[1] = load_arduino_v_13_B.Long_Home;
    }

    /* End of Outputs for SubSystem: '<S782>/Sample and Hold' */

    /* Outputs for Enabled SubSystem: '<S782>/APPROACH' incorporates:
     *  EnablePort: '<S793>/Enable'
     */
    if (load_arduino_v_13_B.trig_approach > 0.0) {
      /* Product: '<S793>/Divide' incorporates:
       *  Constant: '<S793>/x_g0'
       *  Sum: '<S793>/Sum'
       */
      load_arduino_v_13_B.Abs1 = load_arduino_v_13_B.In[0] /
        (load_arduino_v_13_B.In[1] - load_arduino_v_13_P.x_g0_Value);

      /* Abs: '<S793>/Abs' incorporates:
       *  Trigonometry: '<S793>/Atan'
       */
      load_arduino_v_13_B.Abs_o = fabs(atan(load_arduino_v_13_B.Abs1));

      /* DiscreteIntegrator: '<S793>/Discrete-Time Integrator' */
      if ((load_arduino_v_13_B.trig_approach > 0.0) &&
          (load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRe_f <= 0)) {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f =
          load_arduino_v_13_P.DiscreteTimeIntegrator_IC;
      }

      if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f >=
          load_arduino_v_13_P.DiscreteTimeIntegrator_UpperSat) {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f =
          load_arduino_v_13_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f <=
            load_arduino_v_13_P.DiscreteTimeIntegrator_LowerSat) {
          load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f =
            load_arduino_v_13_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      /* Switch: '<S793>/Switch' incorporates:
       *  Constant: '<S793>/Constant3'
       *  Constant: '<S793>/Constant4'
       *  DiscreteIntegrator: '<S793>/Discrete-Time Integrator'
       */
      if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f >
          load_arduino_v_13_P.Switch_Threshold) {
        load_arduino_v_13_B.Abs1_b = load_arduino_v_13_P.Constant3_Value_n;
      } else {
        load_arduino_v_13_B.Abs1_b = load_arduino_v_13_P.Constant4_Value_g;
      }

      /* End of Switch: '<S793>/Switch' */

      /* MATLAB Function: '<S793>/MATLAB Function' */
      load_arduino_v_13_B.AL = 0;
      if ((!load_arduino_v_13_DW.x_not_empty) || (load_arduino_v_13_B.Abs1_b ==
           0.0)) {
        load_arduino_v_13_DW.x[0] = 1.5;
        load_arduino_v_13_DW.x[1] = -200.0;
        load_arduino_v_13_DW.x[2] = 0.01;
        load_arduino_v_13_DW.x[3] = -2.0;
        load_arduino_v_13_DW.x_not_empty = true;
      }

      if ((!load_arduino_v_13_DW.x_new_not_empty) || (load_arduino_v_13_B.Abs1_b
           == 0.0)) {
        load_arduino_v_13_DW.x_new_not_empty = true;
      }

      if ((!load_arduino_v_13_DW.eps_not_empty) || (load_arduino_v_13_B.Abs1_b ==
           0.0)) {
        load_arduino_v_13_DW.eps[0] = 1.0;
        load_arduino_v_13_DW.eps[1] = 1.0;
        load_arduino_v_13_DW.eps[2] = 1.0;
        load_arduino_v_13_DW.eps[3] = 1.0;
        load_arduino_v_13_DW.eps_not_empty = true;
      }

      if ((!load_arduino_v_13_DW.cycle_count_not_empty) ||
          (load_arduino_v_13_B.Abs1_b == 0.0)) {
        load_arduino_v_13_DW.cycle_count = 0.0;
        load_arduino_v_13_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(load_arduino_v_13_DW.eps[0] < 0.1)) ||
                           ((!(load_arduino_v_13_DW.eps[1] < 0.1)) ||
                            ((!(load_arduino_v_13_DW.eps[2] < 0.1)) ||
                             (!(load_arduino_v_13_DW.eps[3] < 0.1)))))) {
        load_arduino_v_13_B.dv0[0] = 1.0;
        load_arduino_v_13_B.Sum4_n = tan(load_arduino_v_13_B.Abs_o);
        load_arduino_v_13_B.dv0[4] = load_arduino_v_13_B.Sum4_n;
        load_arduino_v_13_B.dv0[8] = 0.0;
        load_arduino_v_13_B.dv0[12] = 0.0;
        load_arduino_v_13_B.dv0[1] = load_arduino_v_13_DW.x[2];
        load_arduino_v_13_B.dv0[5] = 0.0;
        load_arduino_v_13_B.Sum3_o = load_arduino_v_13_DW.x[0] -
          load_arduino_v_13_DW.x[3];
        load_arduino_v_13_B.dv0[9] = load_arduino_v_13_B.Sum3_o;
        load_arduino_v_13_B.dv0[13] = -load_arduino_v_13_DW.x[2];
        load_arduino_v_13_B.Abs1_b = exp((5.0 - load_arduino_v_13_DW.x[1]) *
          -load_arduino_v_13_DW.x[2]);
        load_arduino_v_13_B.dv0[2] = load_arduino_v_13_B.Abs1_b;
        load_arduino_v_13_B.Sum_n3 = load_arduino_v_13_B.Sum3_o *
          load_arduino_v_13_DW.x[2];
        load_arduino_v_13_B.dv0[6] = load_arduino_v_13_B.Sum_n3 *
          load_arduino_v_13_B.Abs1_b;
        load_arduino_v_13_B.dv0[10] = load_arduino_v_13_B.Sum3_o *
          (load_arduino_v_13_DW.x[1] - 5.0) * load_arduino_v_13_B.Abs1_b;
        load_arduino_v_13_B.dv0[14] = 1.0;
        load_arduino_v_13_B.dv0[3] = load_arduino_v_13_B.Abs1_b *
          (load_arduino_v_13_DW.x[2] * 18.0);
        load_arduino_v_13_B.dv0[7] = load_arduino_v_13_B.Sum3_o *
          (load_arduino_v_13_DW.x[2] * load_arduino_v_13_DW.x[2]) * 18.0 *
          load_arduino_v_13_B.Abs1_b;
        load_arduino_v_13_B.Gain_n = load_arduino_v_13_B.Sum_n3 * 18.0;
        load_arduino_v_13_B.dv0[11] = load_arduino_v_13_B.Gain_n *
          (load_arduino_v_13_DW.x[1] - 5.0) * load_arduino_v_13_B.Abs1_b +
          load_arduino_v_13_B.Sum3_o * 18.0 * load_arduino_v_13_B.Abs1_b;
        load_arduino_v_13_B.dv0[15] = load_arduino_v_13_B.Abs1_b *
          (-load_arduino_v_13_DW.x[2] * 18.0);
        load_arduino_v_13_invNxN(load_arduino_v_13_B.dv0,
          load_arduino_v_13_B.dv1);
        load_arduino_v_13_B.Gain_k3 = (load_arduino_v_13_DW.x[1] -
          load_arduino_v_13_P.x_g0_Value) * load_arduino_v_13_B.Sum4_n +
          load_arduino_v_13_DW.x[0];
        load_arduino_v_13_B.Sum_n3 -= load_arduino_v_13_B.Sum4_n;
        load_arduino_v_13_B.Sum3_o = load_arduino_v_13_B.Abs1_b *
          load_arduino_v_13_B.Sum3_o + load_arduino_v_13_DW.x[3];
        load_arduino_v_13_B.Abs1_b = load_arduino_v_13_B.Gain_n *
          load_arduino_v_13_B.Abs1_b + -0.1;
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 4;
             load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_B.DataTypeConversion5[load_arduino_v_13_B.firstcol] =
            load_arduino_v_13_DW.x[load_arduino_v_13_B.firstcol] -
            (((load_arduino_v_13_B.dv1[load_arduino_v_13_B.firstcol + 4] *
               load_arduino_v_13_B.Sum_n3 +
               load_arduino_v_13_B.dv1[load_arduino_v_13_B.firstcol] *
               load_arduino_v_13_B.Gain_k3) +
              load_arduino_v_13_B.dv1[load_arduino_v_13_B.firstcol + 8] *
              load_arduino_v_13_B.Sum3_o) +
             load_arduino_v_13_B.dv1[load_arduino_v_13_B.firstcol + 12] *
             load_arduino_v_13_B.Abs1_b);
        }

        load_arduino_v_13_DW.eps[0] = fabs
          (load_arduino_v_13_B.DataTypeConversion5[0] - load_arduino_v_13_DW.x[0]);
        load_arduino_v_13_DW.eps[1] = fabs
          (load_arduino_v_13_B.DataTypeConversion5[1] - load_arduino_v_13_DW.x[1]);
        load_arduino_v_13_DW.eps[2] = fabs
          (load_arduino_v_13_B.DataTypeConversion5[2] - load_arduino_v_13_DW.x[2]);
        load_arduino_v_13_DW.eps[3] = fabs
          (load_arduino_v_13_B.DataTypeConversion5[3] - load_arduino_v_13_DW.x[3]);
        load_arduino_v_13_DW.x[0] = load_arduino_v_13_B.DataTypeConversion5[0];
        load_arduino_v_13_DW.x[1] = load_arduino_v_13_B.DataTypeConversion5[1];
        load_arduino_v_13_DW.x[2] = load_arduino_v_13_B.DataTypeConversion5[2];
        load_arduino_v_13_DW.x[3] = load_arduino_v_13_B.DataTypeConversion5[3];
        load_arduino_v_13_DW.cycle_count++;
        if (load_arduino_v_13_DW.cycle_count > 10.0) {
          load_arduino_v_13_B.AL = 1;
          exitg1 = true;
        }
      }

      if ((load_arduino_v_13_DW.eps[0] < 0.1) && (load_arduino_v_13_DW.eps[1] <
           0.1) && (load_arduino_v_13_DW.eps[2] < 0.1) &&
          (load_arduino_v_13_DW.eps[3] < 0.1)) {
        load_arduino_v_13_B.h_f_out = load_arduino_v_13_DW.x[0];
        load_arduino_v_13_B.x_f_out = load_arduino_v_13_DW.x[1];
        load_arduino_v_13_B.k_x_out = load_arduino_v_13_DW.x[2];
        load_arduino_v_13_B.h_c_out = load_arduino_v_13_DW.x[3];
      } else {
        load_arduino_v_13_B.h_f_out = 0.0;
        load_arduino_v_13_B.x_f_out = 0.0;
        load_arduino_v_13_B.k_x_out = 0.0;
        load_arduino_v_13_B.h_c_out = 0.0;
      }

      load_arduino_v_13_B.no_solution = load_arduino_v_13_B.AL;

      /* End of MATLAB Function: '<S793>/MATLAB Function' */

      /* Product: '<S793>/Multiply' incorporates:
       *  Constant: '<S793>/x_g0'
       *  Gain: '<S793>/Gain'
       *  Sum: '<S793>/Sum1'
       */
      load_arduino_v_13_B.Multiply = (load_arduino_v_13_B.Long_Home -
        load_arduino_v_13_P.x_g0_Value) * load_arduino_v_13_P.Gain_Gain_e0 *
        load_arduino_v_13_B.Abs1;

      /* Update for DiscreteIntegrator: '<S793>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S793>/Constant2'
       */
      load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f +=
        load_arduino_v_13_P.DiscreteTimeIntegrator_gainval *
        load_arduino_v_13_P.Constant2_Value_g;
      if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f >=
          load_arduino_v_13_P.DiscreteTimeIntegrator_UpperSat) {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f =
          load_arduino_v_13_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f <=
            load_arduino_v_13_P.DiscreteTimeIntegrator_LowerSat) {
          load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f =
            load_arduino_v_13_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      if (load_arduino_v_13_B.trig_approach > 0.0) {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRe_f = 1;
      } else if (load_arduino_v_13_B.trig_approach < 0.0) {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRe_f = -1;
      } else if (load_arduino_v_13_B.trig_approach == 0.0) {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRe_f = 0;
      } else {
        load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRe_f = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S793>/Discrete-Time Integrator' */
    }

    /* End of Outputs for SubSystem: '<S782>/APPROACH' */

    /* Outputs for Enabled SubSystem: '<S782>/FLARE' incorporates:
     *  EnablePort: '<S797>/Enable'
     */
    if (load_arduino_v_13_B.trig_flare > 0.0) {
      /* Sum: '<S797>/Sum2' incorporates:
       *  Gain: '<S797>/Gain'
       *  Math: '<S797>/Exp'
       *  Product: '<S797>/Multiply'
       *  Product: '<S797>/Multiply1'
       *  Sum: '<S797>/Sum'
       *  Sum: '<S797>/Sum1'
       *
       * About '<S797>/Exp':
       *  Operator: exp
       */
      load_arduino_v_13_B.Sum2 = exp((load_arduino_v_13_B.Long_Home -
        load_arduino_v_13_B.x_f_out) * load_arduino_v_13_B.k_x_out *
        load_arduino_v_13_P.Gain_Gain_j) * (load_arduino_v_13_B.h_f_out -
        load_arduino_v_13_B.h_c_out) + load_arduino_v_13_B.h_c_out;
    }

    /* End of Outputs for SubSystem: '<S782>/FLARE' */

    /* MultiPortSwitch: '<S782>/Switch di selezione  Task - Waypoint navigation4' incorporates:
     *  Abs: '<S782>/Abs3'
     *  Abs: '<S782>/Abs4'
     *  Constant: '<S782>/Constant2'
     */
    switch ((int32_T)load_arduino_v_13_B.maneuver_selector) {
     case 1:
      load_arduino_v_13_B.QUOTA_m = load_arduino_v_13_P.Constant2_Value_n3;
      break;

     case 2:
      load_arduino_v_13_B.QUOTA_m = fabs(load_arduino_v_13_B.Multiply);
      break;

     default:
      load_arduino_v_13_B.QUOTA_m = fabs(load_arduino_v_13_B.Sum2);
      break;
    }

    /* End of MultiPortSwitch: '<S782>/Switch di selezione  Task - Waypoint navigation4' */

    /* Switch: '<S782>/Switch2' incorporates:
     *  Constant: '<S782>/Constant3'
     *  Constant: '<S782>/Constant8'
     */
    if (load_arduino_v_13_DW.Memory7_PreviousInput >
        load_arduino_v_13_P.Switch2_Threshold_f) {
      load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Constant3_Value_c;
    } else {
      load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Constant8_Value;
    }

    /* End of Switch: '<S782>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S782>/INSEGUIMENTO CENTRO PISTA' incorporates:
     *  EnablePort: '<S798>/Enable'
     */
    if (load_arduino_v_13_B.Long_Home > 0.0) {
      /* Gain: '<S798>/Gain1' incorporates:
       *  Product: '<S915>/x*sin'
       *  Product: '<S915>/y*cos'
       *  Sum: '<S915>/Sum3'
       */
      load_arduino_v_13_B.IProdOut_b = (load_arduino_v_13_B.Switch_bk *
        load_arduino_v_13_B.Gain_o - load_arduino_v_13_B.IProdOut_b *
        load_arduino_v_13_B.rtb_long_end_tmp) * load_arduino_v_13_P.Gain1_Gain;

      /* Gain: '<S815>/Gain' incorporates:
       *  Constant: '<S798>/psi ref gain'
       *  DiscreteIntegrator: '<S870>/Integrator'
       *  MATLAB Function: '<S782>/CALIBRATING_HOME_COORDINATES'
       *  Product: '<S886>/PProd Out'
       *  Sum: '<S798>/Sum3'
       *  Sum: '<S899>/Sum'
       */
      load_arduino_v_13_B.Gain_p = (load_arduino_v_13_B.Al_selector -
        (load_arduino_v_13_B.IProdOut_b * load_arduino_v_13_P.psirefgain_Value +
         load_arduino_v_13_DW.Integrator_DSTATE_h)) *
        load_arduino_v_13_P.Gain_Gain_nw;

      /* Update for DiscreteIntegrator: '<S870>/Integrator' incorporates:
       *  Constant: '<S798>/psi ref gain1'
       *  Product: '<S859>/IProd Out'
       */
      load_arduino_v_13_DW.Integrator_DSTATE_h += load_arduino_v_13_B.IProdOut_b
        * load_arduino_v_13_P.psirefgain1_Value *
        load_arduino_v_13_P.Integrator_gainval;
    }

    /* End of Outputs for SubSystem: '<S782>/INSEGUIMENTO CENTRO PISTA' */

    /* Switch: '<S782>/Switch1' */
    if (load_arduino_v_13_DW.Memory7_PreviousInput >
        load_arduino_v_13_P.Switch1_Threshold_l) {
      load_arduino_v_13_B.Switch1 = load_arduino_v_13_B.Gain_p;
    }

    /* End of Switch: '<S782>/Switch1' */

    /* Update for Memory: '<S782>/Memory5' */
    load_arduino_v_13_DW.Memory5_PreviousInput = load_arduino_v_13_B.x_f_out;

    /* Update for Memory: '<S782>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput_l = load_arduino_v_13_B.h_f_out;

    /* Update for Memory: '<S782>/Memory2' */
    load_arduino_v_13_DW.Memory2_PreviousInput_f =
      load_arduino_v_13_B.no_solution;
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem1' */

  /* MATLAB Function: '<S40>/MATLAB Function' */
  if (load_arduino_v_13_B.modo == 3.0) {
    load_arduino_v_13_B.firstcol = 1;
    load_arduino_v_13_B.AL = 0;
  } else if (load_arduino_v_13_B.modo == 4.0) {
    load_arduino_v_13_B.AL = 1;
    load_arduino_v_13_B.firstcol = 0;
  } else {
    load_arduino_v_13_B.firstcol = 0;
    load_arduino_v_13_B.AL = 0;
  }

  /* Sum: '<S544>/Sum' incorporates:
   *  Constant: '<S544>/Constant8'
   */
  load_arduino_v_13_B.Al_selector = load_arduino_v_13_B.Fase_ATO -
    load_arduino_v_13_P.Constant8_Value_e;

  /* DiscreteIntegrator: '<S544>/Discrete-Time Integrator' */
  if ((load_arduino_v_13_B.Al_selector > 0.0) &&
      (load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_13_P.DiscreteTimeIntegrator_IC_d;
  }

  if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE >=
      load_arduino_v_13_P.DiscreteTimeIntegrator_UpperS_l) {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_13_P.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE <=
        load_arduino_v_13_P.DiscreteTimeIntegrator_LowerS_c) {
      load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE =
        load_arduino_v_13_P.DiscreteTimeIntegrator_LowerS_c;
    }
  }

  /* MultiPortSwitch: '<S39>/Switch Bumpless 7' incorporates:
   *  Constant: '<S986>/manetta_massima'
   *  Constant: '<S986>/manetta_minima'
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   *  Gain: '<S39>/Gain3'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  MultiPortSwitch: '<S544>/Multiport Switch1'
   *  Product: '<S986>/Divide2'
   *  Product: '<S986>/Multiply1'
   *  Sum: '<S986>/Sum2'
   *  Sum: '<S986>/Sum3'
   *  Sum: '<S986>/Sum4'
   *  Sum: '<S986>/Sum5'
   */
  if ((int32_T)load_arduino_v_13_B.switch_manetta == 0) {
    load_arduino_v_13_B.Gain_o = (real_T)(load_arduino_v_13_B.PWM_throttle -
      load_arduino_v_13_B.One_time_initialization.ByteUnpack[1]) / (real_T)
      (load_arduino_v_13_B.One_time_initialization.ByteUnpack[0] -
       load_arduino_v_13_B.One_time_initialization.ByteUnpack[1]) *
      (load_arduino_v_13_P.attuatore_Tmax - load_arduino_v_13_P.attuatore_Tmin)
      + load_arduino_v_13_P.attuatore_Tmin;
  } else {
    if (load_arduino_v_13_B.firstcol == 0) {
      /* MultiPortSwitch: '<S544>/Multiport Switch1' incorporates:
       *  Constant: '<S39>/Constant2'
       */
      load_arduino_v_13_B.Gain_o = load_arduino_v_13_P.Constant2_Value_jd;
    } else {
      /* MultiPortSwitch: '<S544>/Switch Bumpless 1' incorporates:
       *  Constant: '<S39>/Constant2'
       *  Constant: '<S544>/Constant4'
       *  DiscreteIntegrator: '<S544>/Discrete-Time Integrator'
       *  MultiPortSwitch: '<S544>/Multiport Switch1'
       */
      switch ((int32_T)load_arduino_v_13_B.Fase_ATO) {
       case 0:
        load_arduino_v_13_B.Gain_o = load_arduino_v_13_P.Constant4_Value;
        break;

       case 1:
        load_arduino_v_13_B.Gain_o = load_arduino_v_13_B.manetta_ref;
        break;

       case 2:
        load_arduino_v_13_B.Gain_o =
          load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE;
        break;

       case 3:
        load_arduino_v_13_B.Gain_o = load_arduino_v_13_P.Constant2_Value_jd;
        break;

       default:
        load_arduino_v_13_B.Gain_o = load_arduino_v_13_P.Constant2_Value_jd;
        break;
      }

      /* End of MultiPortSwitch: '<S544>/Switch Bumpless 1' */
    }

    load_arduino_v_13_B.Gain_o *= load_arduino_v_13_P.inv_T;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 7' */

  /* Product: '<S983>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion13'
   *  DataTypeConversion: '<S9>/Data Type Conversion6'
   *  DataTypeConversion: '<S9>/Data Type Conversion7'
   *  Product: '<S984>/Divide'
   *  Product: '<S990>/Multiply'
   *  Sum: '<S983>/Sum'
   *  Sum: '<S983>/Sum1'
   */
  load_arduino_v_13_B.rtb_long_end_tmp =
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[2] -
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[3];
  load_arduino_v_13_B.Long_Home = (real_T)(load_arduino_v_13_B.PWM_elevator -
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[3]) /
    load_arduino_v_13_B.rtb_long_end_tmp;

  /* Sum: '<S983>/Sum2' incorporates:
   *  Constant: '<S983>/Constant8'
   *  Constant: '<S983>/Constant9'
   *  Sum: '<S990>/Sum1'
   */
  load_arduino_v_13_B.Switch_bk = load_arduino_v_13_P.attuatore_Emax -
    load_arduino_v_13_P.attuatore_Emin;

  /* Sum: '<S983>/Sum3' incorporates:
   *  Constant: '<S983>/Constant9'
   *  Product: '<S983>/Divide'
   *  Product: '<S983>/Multiply'
   *  Sum: '<S983>/Sum2'
   */
  load_arduino_v_13_B.Sum3_o = load_arduino_v_13_B.Long_Home *
    load_arduino_v_13_B.Switch_bk + load_arduino_v_13_P.attuatore_Emin;

  /* Sum: '<S39>/Sum2' incorporates:
   *  Constant: '<S984>/Constant8'
   *  Constant: '<S984>/Constant9'
   *  Gain: '<S984>/Gain'
   *  Product: '<S984>/Multiply'
   *  Sum: '<S984>/Sum2'
   *  Sum: '<S984>/Sum3'
   */
  load_arduino_v_13_B.Gain1_a = (load_arduino_v_13_B.Long_Home *
    (load_arduino_v_13_P.theta_max - load_arduino_v_13_P.theta_min) +
    load_arduino_v_13_P.theta_min) * load_arduino_v_13_P.Gain_Gain_h1 -
    load_arduino_v_13_B.Gain1_a;

  /* Sum: '<S638>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore beccheggio1'
   *  DiscreteIntegrator: '<S609>/Integrator'
   *  Gain: '<S8>/Gain'
   *  Product: '<S625>/PProd Out'
   */
  load_arduino_v_13_B.Long_Home = load_arduino_v_13_P.Gain_Gain_j5 *
    load_arduino_v_13_P.Kp_becch * load_arduino_v_13_B.Gain1_a +
    load_arduino_v_13_DW.Integrator_DSTATE;

  /* Saturate: '<S630>/Saturation' */
  if (load_arduino_v_13_B.Long_Home > load_arduino_v_13_P.attuatore_Emax) {
    load_arduino_v_13_B.Abs1 = load_arduino_v_13_P.attuatore_Emax;
  } else if (load_arduino_v_13_B.Long_Home < load_arduino_v_13_P.attuatore_Emin)
  {
    load_arduino_v_13_B.Abs1 = load_arduino_v_13_P.attuatore_Emin;
  } else {
    load_arduino_v_13_B.Abs1 = load_arduino_v_13_B.Long_Home;
  }

  /* End of Saturate: '<S630>/Saturation' */

  /* MultiPortSwitch: '<S541>/Switch Bumpless 2' */
  if ((int32_T)load_arduino_v_13_B.switch_equilibratore == 0) {
    load_arduino_v_13_B.Abs1_b = load_arduino_v_13_B.Sum3_o;
  } else {
    load_arduino_v_13_B.Abs1_b = load_arduino_v_13_B.Abs1;
  }

  /* End of MultiPortSwitch: '<S541>/Switch Bumpless 2' */

  /* Switch: '<S553>/Switch1' incorporates:
   *  Constant: '<S553>/Constant5'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  MultiPortSwitch: '<S553>/Multiport Switch2'
   */
  if ((load_arduino_v_13_B.AL != 0) && (!(load_arduino_v_13_B.Product1 >=
        load_arduino_v_13_P.Switch1_Threshold))) {
    load_arduino_v_13_B.Abs1_b = load_arduino_v_13_P.Constant5_Value;
  }

  /* End of Switch: '<S553>/Switch1' */

  /* MultiPortSwitch: '<S554>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_13_B.firstcol != 0) {
    /* MultiPortSwitch: '<S554>/Multiport Switch1' incorporates:
     *  Gain: '<S651>/Gain1'
     */
    switch ((int32_T)load_arduino_v_13_B.Fase_ATO) {
     case 0:
      load_arduino_v_13_B.Abs1_b = load_arduino_v_13_P.Gain1_Gain_jm *
        load_arduino_v_13_B.eq_rot;
      break;

     case 1:
      load_arduino_v_13_B.Abs1_b = load_arduino_v_13_P.Gain1_Gain_jm *
        load_arduino_v_13_B.eq_rot;
      break;

     case 2:
      load_arduino_v_13_B.Abs1_b = load_arduino_v_13_P.Gain1_Gain_jm *
        load_arduino_v_13_B.eq_rot;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S554>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S554>/Multiport Switch2' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 1' incorporates:
   *  Gain: '<S39>/Gain'
   */
  if ((int32_T)load_arduino_v_13_B.switch_equilibratore != 0) {
    /* MultiPortSwitch: '<S541>/Switch 1' incorporates:
     *  Abs: '<S541>/Abs1'
     *  Constant: '<S541>/Constant1'
     *  Constant: '<S541>/Constant2'
     *  Constant: '<S541>/Constant3'
     *  Constant: '<S8>/Kp controllore velocità beccheggio1'
     *  Gain: '<S541>/Gain'
     *  Gain: '<S8>/Gain2'
     *  MultiPortSwitch: '<S541>/Switch  2'
     *  Product: '<S541>/Product3'
     *  Product: '<S541>/Product4'
     *  Product: '<S541>/Product5'
     *  Sum: '<S541>/Sum3'
     *  Trigonometry: '<S541>/Trigonometric Function'
     */
    if ((int32_T)load_arduino_v_13_B.switch_equilibratore == 0) {
      load_arduino_v_13_B.Sum3_o = load_arduino_v_13_P.Constant1_Value_fj;
      load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant2_Value_i4;
    } else {
      /* Abs: '<S541>/Abs1' incorporates:
       *  Abs: '<S541>/Abs'
       */
      load_arduino_v_13_B.Sum4_n = fabs(load_arduino_v_13_B.Gain1_l);
      load_arduino_v_13_B.Sum3_o = (load_arduino_v_13_B.DataTypeConversion1_b[4]
        - sin(load_arduino_v_13_B.Sum4_n) *
        load_arduino_v_13_B.DataTypeConversion1_b[5]) *
        (load_arduino_v_13_P.Gain2_Gain_k4 * load_arduino_v_13_P.Kp_q);
      load_arduino_v_13_B.Sum4_n *= load_arduino_v_13_P.Gain_Gain_f *
        load_arduino_v_13_P.Constant3_Value;
    }

    /* End of MultiPortSwitch: '<S541>/Switch 1' */

    /* Sum: '<S541>/Sum2' incorporates:
     *  Sum: '<S541>/Sum'
     */
    load_arduino_v_13_B.err = (load_arduino_v_13_B.Abs1_b -
      load_arduino_v_13_B.Sum3_o) - load_arduino_v_13_B.Sum4_n;

    /* Saturate: '<S541>/saturatore E2' */
    if (load_arduino_v_13_B.err > load_arduino_v_13_P.attuatore_Emax) {
      load_arduino_v_13_B.err = load_arduino_v_13_P.attuatore_Emax;
    } else {
      if (load_arduino_v_13_B.err < load_arduino_v_13_P.attuatore_Emin) {
        load_arduino_v_13_B.err = load_arduino_v_13_P.attuatore_Emin;
      }
    }

    /* End of Saturate: '<S541>/saturatore E2' */
    load_arduino_v_13_B.Sum3_o = load_arduino_v_13_P.inv_E *
      load_arduino_v_13_B.err;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 1' */

  /* Product: '<S981>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion14'
   *  DataTypeConversion: '<S9>/Data Type Conversion8'
   *  DataTypeConversion: '<S9>/Data Type Conversion9'
   *  Product: '<S982>/Divide'
   *  Product: '<S987>/Multiply'
   *  Sum: '<S981>/Sum'
   *  Sum: '<S981>/Sum1'
   */
  load_arduino_v_13_B.Product1 =
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[4] -
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[5];
  load_arduino_v_13_B.Gain_n = (real_T)(load_arduino_v_13_B.PWM_aileron -
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[5]) /
    load_arduino_v_13_B.Product1;

  /* Sum: '<S981>/Sum2' incorporates:
   *  Constant: '<S981>/Constant8'
   *  Constant: '<S981>/Constant9'
   *  Sum: '<S987>/Sum1'
   */
  load_arduino_v_13_B.Abs_o = load_arduino_v_13_P.attuatore_Amax -
    load_arduino_v_13_P.attuatore_Amin;

  /* Sum: '<S981>/Sum3' incorporates:
   *  Constant: '<S981>/Constant9'
   *  Product: '<S981>/Divide'
   *  Product: '<S981>/Multiply'
   *  Sum: '<S981>/Sum2'
   */
  load_arduino_v_13_B.Gain_k3 = load_arduino_v_13_B.Gain_n *
    load_arduino_v_13_B.Abs_o + load_arduino_v_13_P.attuatore_Amin;

  /* Sum: '<S39>/Sum5' incorporates:
   *  Constant: '<S982>/Constant8'
   *  Constant: '<S982>/Constant9'
   *  Gain: '<S982>/Gain'
   *  Product: '<S982>/Multiply'
   *  Sum: '<S982>/Sum2'
   *  Sum: '<S982>/Sum3'
   */
  load_arduino_v_13_B.Gain1_l = (load_arduino_v_13_B.Gain_n *
    (load_arduino_v_13_P.phi_max - load_arduino_v_13_P.phi_min) +
    load_arduino_v_13_P.phi_min) * load_arduino_v_13_P.Gain_Gain_a -
    load_arduino_v_13_B.Gain1_l;

  /* Sum: '<S542>/Sum' incorporates:
   *  Constant: '<S542>/Constant3'
   */
  load_arduino_v_13_B.Gain_n = load_arduino_v_13_B.Fase_ATO -
    load_arduino_v_13_P.Constant3_Value_cr;

  /* DiscreteIntegrator: '<S707>/Integrator' */
  if ((load_arduino_v_13_B.Gain_n > 0.0) &&
      (load_arduino_v_13_DW.Integrator_PrevResetState <= 0)) {
    load_arduino_v_13_DW.Integrator_DSTATE_p =
      load_arduino_v_13_P.PIDController_InitialConditio_d;
  }

  /* Switch: '<S542>/Switch' incorporates:
   *  Constant: '<S542>/Constant2'
   *  Constant: '<S8>/Kp controllore  rollio3'
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  MultiPortSwitch: '<S542>/Multiport Switch'
   */
  if (load_arduino_v_13_B.ByteUnpack_o2_e[2] >
      load_arduino_v_13_P.Switch_Threshold_m) {
    load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Kp_roll;
  } else if (load_arduino_v_13_B.AL == 0) {
    /* MultiPortSwitch: '<S542>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Kp controllore  rollio3'
     */
    load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Kp_roll;
  } else {
    load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant2_Value_hr;
  }

  /* End of Switch: '<S542>/Switch' */

  /* Sum: '<S736>/Sum' incorporates:
   *  DiscreteIntegrator: '<S707>/Integrator'
   *  Product: '<S723>/PProd Out'
   */
  load_arduino_v_13_B.Sum_n3 = load_arduino_v_13_B.Gain1_l *
    load_arduino_v_13_B.Sum4_n + load_arduino_v_13_DW.Integrator_DSTATE_p;

  /* Saturate: '<S728>/Saturation' */
  if (load_arduino_v_13_B.Sum_n3 > load_arduino_v_13_P.attuatore_Amax) {
    load_arduino_v_13_B.Saturation_f = load_arduino_v_13_P.attuatore_Amax;
  } else if (load_arduino_v_13_B.Sum_n3 < load_arduino_v_13_P.attuatore_Amin) {
    load_arduino_v_13_B.Saturation_f = load_arduino_v_13_P.attuatore_Amin;
  } else {
    load_arduino_v_13_B.Saturation_f = load_arduino_v_13_B.Sum_n3;
  }

  /* End of Saturate: '<S728>/Saturation' */

  /* MultiPortSwitch: '<S542>/Switch Bumpless 1' incorporates:
   *  Constant: '<S542>/Constant1'
   *  Constant: '<S8>/Kp controllore  velocità rollio3'
   *  Product: '<S542>/Product3'
   */
  if ((int32_T)load_arduino_v_13_B.switch_alettoni == 0) {
    load_arduino_v_13_B.Sum4_n = load_arduino_v_13_P.Constant1_Value_ng;
  } else {
    load_arduino_v_13_B.Sum4_n = load_arduino_v_13_B.DataTypeConversion1_b[3] *
      load_arduino_v_13_P.Kp_p;
  }

  /* End of MultiPortSwitch: '<S542>/Switch Bumpless 1' */

  /* Sum: '<S542>/Sum2' */
  load_arduino_v_13_B.err = load_arduino_v_13_B.Saturation_f -
    load_arduino_v_13_B.Sum4_n;

  /* MultiPortSwitch: '<S39>/Switch Bumpless 3' incorporates:
   *  Saturate: '<S39>/saturatore A1'
   */
  if ((int32_T)load_arduino_v_13_B.switch_alettoni == 0) {
    load_arduino_v_13_B.PWM_rudder_p = load_arduino_v_13_B.Gain_k3;
  } else if (load_arduino_v_13_B.err > load_arduino_v_13_P.attuatore_Amax) {
    /* Saturate: '<S39>/saturatore A1' */
    load_arduino_v_13_B.PWM_rudder_p = load_arduino_v_13_P.attuatore_Amax;
  } else if (load_arduino_v_13_B.err < load_arduino_v_13_P.attuatore_Amin) {
    /* Saturate: '<S39>/saturatore A1' */
    load_arduino_v_13_B.PWM_rudder_p = load_arduino_v_13_P.attuatore_Amin;
  } else {
    /* Saturate: '<S39>/saturatore A1' */
    load_arduino_v_13_B.PWM_rudder_p = load_arduino_v_13_B.err;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 3' */

  /* Saturate: '<S39>/saturatore A' */
  if (load_arduino_v_13_B.PWM_rudder_p > load_arduino_v_13_P.attuatore_Amax) {
    load_arduino_v_13_B.Alettoni = load_arduino_v_13_P.attuatore_Amax;
  } else if (load_arduino_v_13_B.PWM_rudder_p <
             load_arduino_v_13_P.attuatore_Amin) {
    load_arduino_v_13_B.Alettoni = load_arduino_v_13_P.attuatore_Amin;
  } else {
    load_arduino_v_13_B.Alettoni = load_arduino_v_13_B.PWM_rudder_p;
  }

  /* End of Saturate: '<S39>/saturatore A' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 5' incorporates:
   *  Gain: '<S39>/Gain1'
   */
  if ((int32_T)load_arduino_v_13_B.switch_alettoni == 0) {
    load_arduino_v_13_B.PWM_rudder_p = load_arduino_v_13_B.Gain_k3;
  } else {
    load_arduino_v_13_B.PWM_rudder_p = load_arduino_v_13_P.inv_A *
      load_arduino_v_13_B.Alettoni;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 5' */

  /* Sum: '<S985>/Sum3' incorporates:
   *  Constant: '<S985>/Constant8'
   *  Constant: '<S985>/Constant9'
   *  Sum: '<S988>/Sum1'
   */
  load_arduino_v_13_B.rtb_Sum4_n_tmp = load_arduino_v_13_P.attuatore_Rmax -
    load_arduino_v_13_P.attuatore_Rmin;

  /* Product: '<S985>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion10'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  Product: '<S988>/Multiply'
   *  Sum: '<S985>/Sum2'
   */
  load_arduino_v_13_B.rtb_Sum4_n_tmp_j =
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[6] -
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[7];

  /* Sum: '<S985>/Sum4' incorporates:
   *  Constant: '<S985>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  DataTypeConversion: '<S9>/Data Type Conversion15'
   *  Product: '<S985>/Divide'
   *  Product: '<S985>/Multiply'
   *  Sum: '<S985>/Sum1'
   *  Sum: '<S985>/Sum3'
   */
  load_arduino_v_13_B.Sum4_n = (real_T)(load_arduino_v_13_B.PWM_rudder -
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[7]) /
    load_arduino_v_13_B.rtb_Sum4_n_tmp_j * load_arduino_v_13_B.rtb_Sum4_n_tmp +
    load_arduino_v_13_P.attuatore_Rmin;

  /* DiscreteTransferFcn: '<S543>/Discrete Washout Filter' */
  load_arduino_v_13_B.denAccum = (load_arduino_v_13_B.DataTypeConversion1_b[5] -
    load_arduino_v_13_P.DiscreteWashoutFilter_DenCoef[1] *
    load_arduino_v_13_DW.DiscreteWashoutFilter_states) /
    load_arduino_v_13_P.DiscreteWashoutFilter_DenCoef[0];

  /* Sum: '<S39>/Sum1' incorporates:
   *  Constant: '<S39>/r_rif'
   *  Constant: '<S8>/K controllo imbardata inversa'
   *  Constant: '<S8>/Kp controllore imbardata'
   *  DiscreteTransferFcn: '<S543>/Discrete Washout Filter'
   *  Gain: '<S8>/Gain3'
   *  Product: '<S39>/  CONTROLLO     IMBARDATA      INVERSA'
   *  Product: '<S39>/Product'
   *  Sum: '<S39>/Sum9'
   */
  load_arduino_v_13_B.Sum1_lg = (load_arduino_v_13_P.r_rif_Value -
    (load_arduino_v_13_P.DiscreteWashoutFilter_NumCoef[0] *
     load_arduino_v_13_B.denAccum +
     load_arduino_v_13_P.DiscreteWashoutFilter_NumCoef[1] *
     load_arduino_v_13_DW.DiscreteWashoutFilter_states)) *
    load_arduino_v_13_P.Kp_imb + (real_T)(load_arduino_v_13_P.Gain3_Gain_o *
    load_arduino_v_13_P.K_imb_inv) * 0.0078125 * load_arduino_v_13_B.err;

  /* Switch: '<S540>/Switch2' incorporates:
   *  Gain: '<S545>/Gain'
   *  Gain: '<S546>/Gain'
   */
  if (load_arduino_v_13_B.Gain4[0] >= load_arduino_v_13_P.Switch2_Threshold_c) {
    load_arduino_v_13_B.err = load_arduino_v_13_P.Gain_Gain_n *
      load_arduino_v_13_B.Gain1_k;
  } else {
    load_arduino_v_13_B.err = load_arduino_v_13_P.Gain_Gain_g *
      load_arduino_v_13_B.Gain1_c;
  }

  /* End of Switch: '<S540>/Switch2' */

  /* Switch: '<S550>/Switch2' incorporates:
   *  Abs: '<S550>/Abs'
   *  Constant: '<S550>/Constant2'
   *  Sum: '<S550>/Sum'
   */
  if (load_arduino_v_13_B.err > load_arduino_v_13_P.Switch2_Threshold_n) {
    load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_B.err;
  } else {
    load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_P.Constant2_Value_h -
      fabs(load_arduino_v_13_B.err);
  }

  /* End of Switch: '<S550>/Switch2' */

  /* DataTypeConversion: '<S1>/Data Tversion' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 42;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.i] =
      load_arduino_v_13_DW.WP_dbP[load_arduino_v_13_B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Tversion' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem2' incorporates:
   *  EnablePort: '<S783>/Enable'
   */
  if (load_arduino_v_13_B.Wp_selector > 0.0) {
    /* Gain: '<S933>/Gain' */
    load_arduino_v_13_B.Gain_a = load_arduino_v_13_P.Gain_Gain_bu *
      load_arduino_v_13_B.Gain1_f;

    /* Gain: '<S934>/Gain' */
    load_arduino_v_13_B.Gain_pq = load_arduino_v_13_P.Gain_Gain_jz *
      load_arduino_v_13_B.Gain1_p;

    /* Gain: '<S935>/Gain' */
    load_arduino_v_13_B.Wp_selector = load_arduino_v_13_P.Gain_Gain_gj *
      load_arduino_v_13_B.Gain1_c;

    /* MATLAB Function: '<S783>/WAYPOINTS' incorporates:
     *  DataTypeConversion: '<S1>/Data Tversion1'
     *  DataTypeConversion: '<S947>/Data Type Conversion5'
     *  Memory: '<S783>/Memory4'
     */
    load_arduino_v_13_B.caso = 1;
    if (load_arduino_v_13_DW.Memory4_PreviousInput == 6.0) {
      load_arduino_v_13_B.caso = 0;
    }

    if ((uint8_T)load_arduino_v_13_B.GC_info[0] == 3) {
      load_arduino_v_13_DW.Memory4_PreviousInput = 1.0;
      load_arduino_v_13_DW.lat1 = load_arduino_v_13_B.Gain_a;
      load_arduino_v_13_DW.long1 = load_arduino_v_13_B.Gain_pq;
      for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 6;
           load_arduino_v_13_B.i++) {
        if (rtb_WP_db_info_0[24 + load_arduino_v_13_B.i] == 1) {
          load_arduino_v_13_DW.Memory4_PreviousInput = 1.0 + (real_T)
            load_arduino_v_13_B.i;
        }
      }
    }

    load_arduino_v_13_B.i = (int32_T)load_arduino_v_13_DW.Memory4_PreviousInput;
    load_arduino_v_13_B.b_x_tmp =
      load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.i + 23];
    load_arduino_v_13_B.long_comandato_tmp =
      load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.i + 29];
    load_arduino_v_13_B.QUOTA =
      load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.i + 35];
    load_arduino_v_13_B.a = sin((load_arduino_v_13_B.b_x_tmp -
      load_arduino_v_13_B.Gain_a) * 3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_13_B.dist = sin((load_arduino_v_13_B.long_comandato_tmp -
      load_arduino_v_13_B.Gain_pq) * 3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_13_B.psi_ref_n = load_arduino_v_13_B.b_x_tmp *
      3.1415926535897931 / 180.0;
    load_arduino_v_13_B.angoloWP = cos(load_arduino_v_13_B.psi_ref_n);
    load_arduino_v_13_B.err = cos(load_arduino_v_13_B.Gain_a *
      3.1415926535897931 / 180.0);
    load_arduino_v_13_B.a = load_arduino_v_13_B.angoloWP *
      load_arduino_v_13_B.err * (load_arduino_v_13_B.dist *
      load_arduino_v_13_B.dist) + load_arduino_v_13_B.a * load_arduino_v_13_B.a;
    load_arduino_v_13_B.a = rt_atan2d_snf(sqrt(load_arduino_v_13_B.a), sqrt(1.0
      - load_arduino_v_13_B.a)) * 2.0 * 6.378137E+6;
    if (load_arduino_v_13_DW.Memory4_PreviousInput > 1.0) {
      load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
        (load_arduino_v_13_DW.Memory4_PreviousInput - 1.0);
      load_arduino_v_13_B.psi_ref_pre =
        load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.tolleranza_distWP_fut
        + 23];
      load_arduino_v_13_B.psi_ref_n = load_arduino_v_13_B.psi_ref_pre *
        3.1415926535897931 / 180.0;
      load_arduino_v_13_B.dist_fut =
        load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.tolleranza_distWP_fut
        + 29];
      load_arduino_v_13_B.psi_ref_tmp = (load_arduino_v_13_B.long_comandato_tmp
        - load_arduino_v_13_B.dist_fut) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.dist = cos(load_arduino_v_13_B.psi_ref_n);
      load_arduino_v_13_B.psi_ref_n = rt_atan2d_snf(sin
        (load_arduino_v_13_B.psi_ref_tmp) * load_arduino_v_13_B.angoloWP,
        load_arduino_v_13_B.dist * sin
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         load_arduino_v_13_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) - sin(load_arduino_v_13_B.psi_ref_n) *
        load_arduino_v_13_B.angoloWP * cos(load_arduino_v_13_B.psi_ref_tmp)) *
        180.0 / 3.1415926535897931;
      load_arduino_v_13_B.psi_ref_pre = sin((load_arduino_v_13_B.Gain_a -
        load_arduino_v_13_B.psi_ref_pre) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_13_B.dist_fut = sin((load_arduino_v_13_B.Gain_pq -
        load_arduino_v_13_B.dist_fut) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_13_B.dist = load_arduino_v_13_B.dist *
        load_arduino_v_13_B.err * (load_arduino_v_13_B.dist_fut *
        load_arduino_v_13_B.dist_fut) + load_arduino_v_13_B.psi_ref_pre *
        load_arduino_v_13_B.psi_ref_pre;
      load_arduino_v_13_B.dist = rt_atan2d_snf(sqrt(load_arduino_v_13_B.dist),
        sqrt(1.0 - load_arduino_v_13_B.dist)) * 2.0 * 6.378137E+6;
    } else {
      load_arduino_v_13_B.psi_ref_n = rt_atan2d_snf(sin
        ((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
          load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_13_DW.long1) * 3.1415926535897931 / 180.0) *
        load_arduino_v_13_B.angoloWP, sin(load_arduino_v_13_B.psi_ref_n) * cos
        (load_arduino_v_13_DW.lat1 * 3.1415926535897931 / 180.0) -
        load_arduino_v_13_B.angoloWP * sin(load_arduino_v_13_DW.lat1 *
        3.1415926535897931 / 180.0) * cos
        ((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
          load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_13_DW.long1) * 3.1415926535897931 / 180.0)) * 180.0 /
        3.1415926535897931;
      load_arduino_v_13_B.dist = 0.0;
    }

    if (load_arduino_v_13_B.psi_ref_n < 0.0) {
      load_arduino_v_13_B.psi_ref_n = 360.0 - fabs(load_arduino_v_13_B.psi_ref_n);
    }

    if (load_arduino_v_13_B.caso == 1) {
      load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
        (load_arduino_v_13_DW.Memory4_PreviousInput + 1.0);
      load_arduino_v_13_B.psi_ref_tmp =
        load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.tolleranza_distWP_fut
        + 23];
      load_arduino_v_13_B.dist_fut = sin((load_arduino_v_13_B.psi_ref_tmp -
        load_arduino_v_13_B.b_x_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_13_B.psi_ref_pre =
        (load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.tolleranza_distWP_fut
         + 29] - load_arduino_v_13_B.long_comandato_tmp) * 3.1415926535897931 /
        180.0;
      load_arduino_v_13_B.f_x = sin(load_arduino_v_13_B.psi_ref_pre / 2.0);
      load_arduino_v_13_B.psi_ref_tmp = load_arduino_v_13_B.psi_ref_tmp *
        3.1415926535897931 / 180.0;
      load_arduino_v_13_B.a_fut_tmp = cos(load_arduino_v_13_B.psi_ref_tmp);
      load_arduino_v_13_B.dist_fut = load_arduino_v_13_B.a_fut_tmp *
        load_arduino_v_13_B.angoloWP * (load_arduino_v_13_B.f_x *
        load_arduino_v_13_B.f_x) + load_arduino_v_13_B.dist_fut *
        load_arduino_v_13_B.dist_fut;
      load_arduino_v_13_B.dist_fut = rt_atan2d_snf(sqrt
        (load_arduino_v_13_B.dist_fut), sqrt(1.0 - load_arduino_v_13_B.dist_fut))
        * 2.0 * 6.378137E+6;
      load_arduino_v_13_B.angoloWP = rt_atan2d_snf(sin
        (load_arduino_v_13_B.psi_ref_pre) * load_arduino_v_13_B.a_fut_tmp, sin
        (load_arduino_v_13_B.psi_ref_tmp) * load_arduino_v_13_B.angoloWP -
        load_arduino_v_13_B.a_fut_tmp * sin
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         load_arduino_v_13_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * cos(load_arduino_v_13_B.psi_ref_pre)) * 180.0 /
        3.1415926535897931;
      if (load_arduino_v_13_B.angoloWP < 0.0) {
        load_arduino_v_13_B.angoloWP = 360.0 - fabs(load_arduino_v_13_B.angoloWP);
      }

      if (load_arduino_v_13_DW.Memory4_PreviousInput > 1.0) {
        load_arduino_v_13_B.angoloWP = fabs(load_arduino_v_13_B.angoloWP -
          load_arduino_v_13_B.psi_ref_n);
      } else {
        load_arduino_v_13_B.angoloWP = fabs(load_arduino_v_13_B.angoloWP -
          rt_atan2d_snf(sin((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                             load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
                             load_arduino_v_13_DW.long1) * 3.1415926535897931 /
                            180.0) * cos
                        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                         load_arduino_v_13_DW.Memory4_PreviousInput + 23] *
                         3.1415926535897931 / 180.0), sin
                        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                         load_arduino_v_13_DW.Memory4_PreviousInput + 23] *
                         3.1415926535897931 / 180.0) * cos
                        (load_arduino_v_13_DW.lat1 * 3.1415926535897931 / 180.0)
                        - cos(load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                              load_arduino_v_13_DW.Memory4_PreviousInput + 23] *
                              3.1415926535897931 / 180.0) * sin
                        (load_arduino_v_13_DW.lat1 * 3.1415926535897931 / 180.0)
                        * cos((load_arduino_v_13_B.DataTypeConversion4_m
          [(int32_T)load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_13_DW.long1) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      load_arduino_v_13_B.dist_fut = 0.0;
      load_arduino_v_13_B.angoloWP = 0.0;
    }

    if (load_arduino_v_13_DW.Memory4_PreviousInput < 2.0) {
      load_arduino_v_13_B.psi_ref_pre = 0.0;
    } else if (load_arduino_v_13_DW.Memory4_PreviousInput == 2.0) {
      load_arduino_v_13_B.psi_ref_pre =
        load_arduino_v_13_B.DataTypeConversion4_m[24] * 3.1415926535897931 /
        180.0;
      load_arduino_v_13_B.psi_ref_tmp = cos(load_arduino_v_13_B.psi_ref_pre);
      load_arduino_v_13_B.a_fut_tmp =
        (load_arduino_v_13_B.DataTypeConversion4_m[30] -
         load_arduino_v_13_DW.long1) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.psi_ref_pre = fabs(load_arduino_v_13_B.psi_ref_n -
        rt_atan2d_snf(sin(load_arduino_v_13_B.a_fut_tmp) *
                      load_arduino_v_13_B.psi_ref_tmp, cos
                      (load_arduino_v_13_DW.lat1 * 3.1415926535897931 / 180.0) *
                      sin(load_arduino_v_13_B.psi_ref_pre) - sin
                      (load_arduino_v_13_DW.lat1 * 3.1415926535897931 / 180.0) *
                      load_arduino_v_13_B.psi_ref_tmp * cos
                      (load_arduino_v_13_B.a_fut_tmp)) * 180.0 /
        3.1415926535897931);
    } else {
      load_arduino_v_13_B.tolleranza_distWP_fut = (int32_T)
        (load_arduino_v_13_DW.Memory4_PreviousInput - 2.0);
      load_arduino_v_13_B.psi_ref_pre =
        load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.tolleranza_distWP_fut
        + 23] * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.psi_ref_tmp =
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         (load_arduino_v_13_DW.Memory4_PreviousInput - 1.0) + 29] -
         load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.tolleranza_distWP_fut
         + 29]) * 3.1415926535897931 / 180.0;
      load_arduino_v_13_B.psi_ref_pre = rt_atan2d_snf(sin
        (load_arduino_v_13_B.psi_ref_tmp) * cos
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         (load_arduino_v_13_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0), cos(load_arduino_v_13_B.psi_ref_pre) * sin
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         (load_arduino_v_13_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0) - sin(load_arduino_v_13_B.psi_ref_pre) *
        cos(load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
            (load_arduino_v_13_DW.Memory4_PreviousInput - 1.0) + 23] *
            3.1415926535897931 / 180.0) * cos(load_arduino_v_13_B.psi_ref_tmp)) *
        180.0 / 3.1415926535897931;
      if (load_arduino_v_13_B.psi_ref_pre < 0.0) {
        load_arduino_v_13_B.psi_ref_pre = 360.0 - fabs
          (load_arduino_v_13_B.psi_ref_pre);
      }

      load_arduino_v_13_B.psi_ref_pre = fabs(load_arduino_v_13_B.psi_ref_n -
        load_arduino_v_13_B.psi_ref_pre);
    }

    if (load_arduino_v_13_B.angoloWP <= 10.0) {
      load_arduino_v_13_B.angoloWP = 40.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 100;
    } else if ((load_arduino_v_13_B.angoloWP > 10.0) &&
               (load_arduino_v_13_B.angoloWP <= 50.0)) {
      load_arduino_v_13_B.angoloWP = 60.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 250;
    } else if ((load_arduino_v_13_B.angoloWP > 50.0) &&
               (load_arduino_v_13_B.angoloWP <= 90.0)) {
      load_arduino_v_13_B.angoloWP = 80.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 300;
    } else if ((load_arduino_v_13_B.angoloWP > 90.0) &&
               (load_arduino_v_13_B.angoloWP <= 120.0)) {
      load_arduino_v_13_B.angoloWP = 120.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 350;
    } else {
      load_arduino_v_13_B.angoloWP = 150.0;
      load_arduino_v_13_B.tolleranza_distWP_fut = 400;
    }

    if (load_arduino_v_13_B.psi_ref_pre <= 10.0) {
      load_arduino_v_13_B.soglia_dist = 50;
    } else if ((load_arduino_v_13_B.psi_ref_pre > 10.0) &&
               (load_arduino_v_13_B.psi_ref_pre <= 50.0)) {
      load_arduino_v_13_B.soglia_dist = 200;
    } else if ((load_arduino_v_13_B.psi_ref_pre > 50.0) &&
               (load_arduino_v_13_B.psi_ref_pre <= 90.0)) {
      load_arduino_v_13_B.soglia_dist = 300;
    } else if ((load_arduino_v_13_B.psi_ref_pre > 90.0) &&
               (load_arduino_v_13_B.psi_ref_pre <= 120.0)) {
      load_arduino_v_13_B.soglia_dist = 350;
    } else {
      load_arduino_v_13_B.soglia_dist = 400;
    }

    if (load_arduino_v_13_B.caso == 1) {
      load_arduino_v_13_B.psi_ref_pre =
        load_arduino_v_13_B.DataTypeConversion4_m[load_arduino_v_13_B.i + 11];
      if (load_arduino_v_13_B.psi_ref_pre < 15.0) {
        load_arduino_v_13_B.psi_ref_pre = 25.0;
      }

      if (!(load_arduino_v_13_B.psi_ref_pre <= 20.0)) {
        if (load_arduino_v_13_B.psi_ref_pre <= 25.0) {
          load_arduino_v_13_B.angoloWP *= 1.2;
        } else if (load_arduino_v_13_B.psi_ref_pre <= 30.0) {
          load_arduino_v_13_B.angoloWP *= 1.3;
        } else {
          load_arduino_v_13_B.angoloWP *= 1.4;
        }
      }

      load_arduino_v_13_B.ROTTA = rt_atan2d_snf(sin
        ((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
          load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_13_B.Gain_pq) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         load_arduino_v_13_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                     load_arduino_v_13_DW.Memory4_PreviousInput + 23] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.Gain_a * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         load_arduino_v_13_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_13_B.Gain_a * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
             load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
             load_arduino_v_13_B.Gain_pq) * 3.1415926535897931 / 180.0)) * 180.0
        / 3.1415926535897931;
      if ((!(load_arduino_v_13_B.dist < load_arduino_v_13_B.soglia_dist)) ||
          (!(load_arduino_v_13_B.a > load_arduino_v_13_B.angoloWP))) {
        if ((load_arduino_v_13_B.dist > load_arduino_v_13_B.soglia_dist) &&
            (load_arduino_v_13_B.a > load_arduino_v_13_B.angoloWP)) {
          load_arduino_v_13_B.err = fabs(load_arduino_v_13_B.ROTTA -
            load_arduino_v_13_B.psi_ref_n);
          if ((load_arduino_v_13_B.psi_ref_n <= 90.0) &&
              (load_arduino_v_13_B.psi_ref_n >= 0.0)) {
            if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
              load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
            } else {
              if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n <= 180.0) &&
                     (load_arduino_v_13_B.psi_ref_n > 90.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.ROTTA > 0.0)
            {
              if ((load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.ROTTA < -90.0) &&
                   (load_arduino_v_13_B.ROTTA > -180.0))) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 - fabs
                (load_arduino_v_13_B.ROTTA)) - load_arduino_v_13_B.psi_ref_n);
              if ((load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.ROTTA < -90.0) &&
                   (load_arduino_v_13_B.ROTTA > -180.0))) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n < -90.0) &&
                     (load_arduino_v_13_B.psi_ref_n >= -180.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.ROTTA > 0.0)
            {
              if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 - load_arduino_v_13_B.ROTTA)
                - fabs(load_arduino_v_13_B.psi_ref_n));
              if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else {
            if ((load_arduino_v_13_B.psi_ref_n < 0.0) &&
                (load_arduino_v_13_B.psi_ref_n >= -90.0)) {
              if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          }
        } else {
          if (load_arduino_v_13_B.a < load_arduino_v_13_B.angoloWP) {
            if (load_arduino_v_13_B.dist_fut >
                load_arduino_v_13_B.tolleranza_distWP_fut) {
              load_arduino_v_13_B.a =
                (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                 (load_arduino_v_13_DW.Memory4_PreviousInput + 1.0) + 29] -
                 load_arduino_v_13_B.Gain_pq) * 3.1415926535897931 / 180.0;
              load_arduino_v_13_B.ROTTA = rt_atan2d_snf(sin
                (load_arduino_v_13_B.a) * cos
                (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                 (load_arduino_v_13_DW.Memory4_PreviousInput + 1.0) + 23] *
                 3.1415926535897931 / 180.0), sin
                (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                 (load_arduino_v_13_DW.Memory4_PreviousInput + 1.0) + 23] *
                 3.1415926535897931 / 180.0) * load_arduino_v_13_B.err - cos
                (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                 (load_arduino_v_13_DW.Memory4_PreviousInput + 1.0) + 23] *
                 3.1415926535897931 / 180.0) * sin(load_arduino_v_13_B.Gain_a *
                3.1415926535897931 / 180.0) * cos(load_arduino_v_13_B.a)) *
                180.0 / 3.1415926535897931;
              load_arduino_v_13_DW.Memory4_PreviousInput++;
            } else if (load_arduino_v_13_DW.Memory4_PreviousInput < 5.0) {
              load_arduino_v_13_DW.Memory4_PreviousInput += 2.0;
            } else {
              load_arduino_v_13_B.QUOTA = load_arduino_v_13_B.ByteUnpack_o2_e[2]
                + 0.4;
              load_arduino_v_13_B.ROTTA = load_arduino_v_13_B.Wp_selector + 36.6;
              load_arduino_v_13_DW.flag_n = 1.0;
            }
          }
        }
      }

      load_arduino_v_13_DW.flag_n = 0.0;
    } else {
      load_arduino_v_13_B.ROTTA = rt_atan2d_snf(sin
        ((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
          load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_13_B.Gain_pq) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         load_arduino_v_13_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
                     load_arduino_v_13_DW.Memory4_PreviousInput + 23] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_13_B.Gain_a * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
         load_arduino_v_13_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_13_B.Gain_a * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_13_B.DataTypeConversion4_m[(int32_T)
             load_arduino_v_13_DW.Memory4_PreviousInput + 29] -
             load_arduino_v_13_B.Gain_pq) * 3.1415926535897931 / 180.0)) * 180.0
        / 3.1415926535897931;
      if ((!(load_arduino_v_13_B.dist < load_arduino_v_13_B.soglia_dist)) ||
          (!(load_arduino_v_13_DW.flag_n == 0.0))) {
        if ((load_arduino_v_13_B.dist > load_arduino_v_13_B.soglia_dist) &&
            (load_arduino_v_13_B.a > 40.0) && (load_arduino_v_13_DW.flag_n ==
             0.0)) {
          load_arduino_v_13_B.err = fabs(load_arduino_v_13_B.ROTTA -
            load_arduino_v_13_B.psi_ref_n);
          if ((load_arduino_v_13_B.psi_ref_n <= 90.0) &&
              (load_arduino_v_13_B.psi_ref_n >= 0.0)) {
            if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
              load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
            } else {
              if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n <= 180.0) &&
                     (load_arduino_v_13_B.psi_ref_n > 90.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.ROTTA > 0.0)
            {
              if ((load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.ROTTA < -90.0) &&
                   (load_arduino_v_13_B.ROTTA > -180.0))) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 - fabs
                (load_arduino_v_13_B.ROTTA)) - load_arduino_v_13_B.psi_ref_n);
              if ((load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) ||
                  ((load_arduino_v_13_B.ROTTA < -90.0) &&
                   (load_arduino_v_13_B.ROTTA > -180.0))) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else if ((load_arduino_v_13_B.psi_ref_n < -90.0) &&
                     (load_arduino_v_13_B.psi_ref_n >= -180.0)) {
            if (load_arduino_v_13_B.psi_ref_n * load_arduino_v_13_B.ROTTA > 0.0)
            {
              if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            } else {
              load_arduino_v_13_B.err = fabs((360.0 - load_arduino_v_13_B.ROTTA)
                - fabs(load_arduino_v_13_B.psi_ref_n));
              if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          } else {
            if ((load_arduino_v_13_B.psi_ref_n < 0.0) &&
                (load_arduino_v_13_B.psi_ref_n >= -90.0)) {
              if (load_arduino_v_13_B.ROTTA > load_arduino_v_13_B.psi_ref_n) {
                load_arduino_v_13_B.ROTTA += 1.3 * load_arduino_v_13_B.err;
              } else {
                if (load_arduino_v_13_B.ROTTA < load_arduino_v_13_B.psi_ref_n) {
                  load_arduino_v_13_B.ROTTA -= 1.3 * load_arduino_v_13_B.err;
                }
              }
            }
          }
        } else {
          load_arduino_v_13_B.QUOTA = load_arduino_v_13_B.ByteUnpack_o2_e[2] +
            0.4;
          load_arduino_v_13_B.ROTTA = load_arduino_v_13_B.Wp_selector + 36.6;
          load_arduino_v_13_DW.flag_n = 1.0;
        }
      }
    }

    if ((load_arduino_v_13_B.b_x_tmp == 0.0) &&
        (load_arduino_v_13_B.long_comandato_tmp == 0.0) &&
        (load_arduino_v_13_B.QUOTA == 0.0)) {
      load_arduino_v_13_B.QUOTA = load_arduino_v_13_B.ByteUnpack_o2_e[2] + 0.3;
      load_arduino_v_13_B.ROTTA = load_arduino_v_13_B.Wp_selector + 36.6;
    }

    /* End of MATLAB Function: '<S783>/WAYPOINTS' */
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem' incorporates:
   *  EnablePort: '<S781>/Enable'
   */
  if (load_arduino_v_13_B.rtb_Gain1_kw_idx_0 > 0.0) {
    /* MATLAB Function: '<S781>/VETTORIALE' incorporates:
     *  DataTypeConversion: '<S947>/Data Type Conversion5'
     *  Gain: '<S790>/Gain'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     *  Memory: '<S781>/Memory'
     *  Memory: '<S781>/Memory1'
     *  Memory: '<S781>/Memory3'
     *  Memory: '<S781>/Memory6'
     */
    if ((load_arduino_v_13_B.AP_int[1] !=
         load_arduino_v_13_DW.Memory6_PreviousInput) ||
        (load_arduino_v_13_B.modo != load_arduino_v_13_DW.Memory3_PreviousInput)
        || (load_arduino_v_13_B.AP_int[4] !=
            load_arduino_v_13_DW.Memory1_PreviousInput_h)) {
      load_arduino_v_13_DW.ALT_ref = load_arduino_v_13_B.ByteUnpack_o2_e[2];
    }

    if ((load_arduino_v_13_B.AP_int[1] !=
         load_arduino_v_13_DW.Memory6_PreviousInput) ||
        (load_arduino_v_13_B.modo != load_arduino_v_13_DW.Memory3_PreviousInput)
        || (load_arduino_v_13_B.AP_int[2] !=
            load_arduino_v_13_DW.Memory_PreviousInput_b)) {
      load_arduino_v_13_DW.HDG_ref = load_arduino_v_13_P.Gain_Gain_e *
        load_arduino_v_13_B.Gain1_k;
    }

    if (load_arduino_v_13_B.AP_int[2] == 1) {
      load_arduino_v_13_B.rotta_vett = load_arduino_v_13_DW.riferimenti[7];
    } else {
      load_arduino_v_13_B.rotta_vett = load_arduino_v_13_DW.HDG_ref;
    }

    if (load_arduino_v_13_B.AP_int[4] == 1) {
      load_arduino_v_13_B.h_vett = load_arduino_v_13_DW.riferimenti[9];
    } else {
      load_arduino_v_13_B.h_vett = load_arduino_v_13_DW.ALT_ref;
    }

    /* Update for Memory: '<S781>/Memory' incorporates:
     *  MATLAB Function: '<S781>/VETTORIALE'
     */
    load_arduino_v_13_DW.Memory_PreviousInput_b = load_arduino_v_13_B.AP_int[2];

    /* Update for Memory: '<S781>/Memory1' incorporates:
     *  MATLAB Function: '<S781>/VETTORIALE'
     */
    load_arduino_v_13_DW.Memory1_PreviousInput_h = load_arduino_v_13_B.AP_int[4];

    /* Update for Memory: '<S781>/Memory3' incorporates:
     *  MATLAB Function: '<S781>/VETTORIALE'
     */
    load_arduino_v_13_DW.Memory3_PreviousInput = load_arduino_v_13_B.modo;

    /* Update for Memory: '<S781>/Memory6' incorporates:
     *  MATLAB Function: '<S781>/VETTORIALE'
     */
    load_arduino_v_13_DW.Memory6_PreviousInput = load_arduino_v_13_B.AP_int[1];
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem3' incorporates:
   *  EnablePort: '<S784>/Enable'
   */
  if (load_arduino_v_13_B.Go_Home > 0.0) {
    /* Gain: '<S938>/Gain' */
    load_arduino_v_13_B.Gain1_f *= load_arduino_v_13_P.Gain_Gain_ji;

    /* MATLAB Function: '<S784>/GO_HOME' incorporates:
     *  Constant: '<S41>/Constant'
     *  Gain: '<S939>/Gain'
     *  Gain: '<S940>/Gain'
     */
    load_arduino_v_13_B.a = sin((0.0 - load_arduino_v_13_B.Gain1_f) *
      3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_13_B.b_x_tmp = (0.0 - load_arduino_v_13_P.Gain_Gain_gf *
      load_arduino_v_13_B.Gain1_p) * 3.1415926535897931 / 180.0;
    load_arduino_v_13_B.dist = sin(load_arduino_v_13_B.b_x_tmp / 2.0);
    load_arduino_v_13_B.psi_ref_n = load_arduino_v_13_B.Gain1_f *
      3.1415926535897931 / 180.0;
    load_arduino_v_13_B.angoloWP = cos(load_arduino_v_13_B.psi_ref_n);
    load_arduino_v_13_B.a = load_arduino_v_13_B.angoloWP *
      (load_arduino_v_13_B.dist * load_arduino_v_13_B.dist) +
      load_arduino_v_13_B.a * load_arduino_v_13_B.a;
    load_arduino_v_13_B.rotta_goHome = rt_atan2d_snf(sin
      (load_arduino_v_13_B.b_x_tmp), load_arduino_v_13_B.angoloWP * 0.0 - cos
      (load_arduino_v_13_B.b_x_tmp) * sin(load_arduino_v_13_B.psi_ref_n)) *
      180.0 / 3.1415926535897931;
    load_arduino_v_13_B.h_goHome = load_arduino_v_13_P.Constant_Value_g;
    if ((rt_atan2d_snf(sqrt(load_arduino_v_13_B.a), sqrt(1.0 -
           load_arduino_v_13_B.a)) * 2.0 * 6.378137E+6 < 30.0) &&
        (load_arduino_v_13_DW.flag == 0.0)) {
      load_arduino_v_13_DW.flag = 1.0;
      load_arduino_v_13_B.h_goHome = load_arduino_v_13_P.Constant_Value_g + 0.4;
      load_arduino_v_13_B.rotta_goHome = load_arduino_v_13_P.Gain_Gain_ov4 *
        load_arduino_v_13_B.Gain1_c + 100.0;
    }

    /* End of MATLAB Function: '<S784>/GO_HOME' */
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem3' */

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation3' */
  switch ((int32_T)load_arduino_v_13_B.modo) {
   case 1:
    load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.ROTTA;
    break;

   case 2:
    load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.rotta_vett;
    break;

   case 3:
    load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.psi_ref;
    break;

   case 4:
    load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.Switch1;
    break;

   default:
    load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.rotta_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation3' */

  /* MultiPortSwitch: '<S540>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_13_B.firstcol != 0) {
    /* MultiPortSwitch: '<S540>/Multiport Switch1' incorporates:
     *  Constant: '<S540>/Constant4'
     *  Product: '<S540>/Product5'
     *  Sum: '<S540>/Sum5'
     */
    switch ((int32_T)load_arduino_v_13_B.Fase_ATO) {
     case 0:
      /* Switch: '<S551>/Switch2' incorporates:
       *  Abs: '<S551>/Abs'
       *  Constant: '<S551>/Constant2'
       *  Sum: '<S551>/Sum'
       */
      if (load_arduino_v_13_B.Gain1_c > load_arduino_v_13_P.Switch2_Threshold_ah)
      {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_B.Gain1_c;
      } else {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_P.Constant2_Value_dm -
          fabs(load_arduino_v_13_B.Gain1_c);
      }

      load_arduino_v_13_B.Sum1_lg = (load_arduino_v_13_B.Gain1_p -
        load_arduino_v_13_B.IProdOut_b) * load_arduino_v_13_P.Kp_Rotta_psi;
      break;

     case 1:
      /* Switch: '<S551>/Switch2' incorporates:
       *  Abs: '<S551>/Abs'
       *  Constant: '<S551>/Constant2'
       *  Sum: '<S551>/Sum'
       */
      if (load_arduino_v_13_B.Gain1_c > load_arduino_v_13_P.Switch2_Threshold_ah)
      {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_B.Gain1_c;
      } else {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_P.Constant2_Value_dm -
          fabs(load_arduino_v_13_B.Gain1_c);
      }

      load_arduino_v_13_B.Sum1_lg = (load_arduino_v_13_B.Gain1_p -
        load_arduino_v_13_B.IProdOut_b) * load_arduino_v_13_P.Kp_Rotta_psi;
      break;

     case 2:
      /* Switch: '<S551>/Switch2' incorporates:
       *  Abs: '<S551>/Abs'
       *  Constant: '<S551>/Constant2'
       *  Sum: '<S551>/Sum'
       */
      if (load_arduino_v_13_B.Gain1_c > load_arduino_v_13_P.Switch2_Threshold_ah)
      {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_B.Gain1_c;
      } else {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_P.Constant2_Value_dm -
          fabs(load_arduino_v_13_B.Gain1_c);
      }

      load_arduino_v_13_B.Sum1_lg = (load_arduino_v_13_B.Gain1_p -
        load_arduino_v_13_B.IProdOut_b) * load_arduino_v_13_P.Kp_Rotta_psi;
      break;

     case 3:
      /* Switch: '<S551>/Switch2' incorporates:
       *  Abs: '<S551>/Abs'
       *  Constant: '<S551>/Constant2'
       *  Sum: '<S551>/Sum'
       */
      if (load_arduino_v_13_B.Gain1_c > load_arduino_v_13_P.Switch2_Threshold_ah)
      {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_B.Gain1_c;
      } else {
        load_arduino_v_13_B.Gain1_p = load_arduino_v_13_P.Constant2_Value_dm -
          fabs(load_arduino_v_13_B.Gain1_c);
      }

      load_arduino_v_13_B.Sum1_lg = (load_arduino_v_13_B.Gain1_p -
        load_arduino_v_13_B.IProdOut_b) * load_arduino_v_13_P.Kp_Rotta_psi;
      break;
    }

    /* End of MultiPortSwitch: '<S540>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S540>/Multiport Switch2' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 6' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   *  Gain: '<S39>/Gain2'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  MultiPortSwitch: '<S39>/Switch Bumpless 4'
   *  MultiPortSwitch: '<S540>/Multiport Switch3'
   *  Switch: '<S540>/Switch3'
   */
  if ((int32_T)load_arduino_v_13_B.switch_timone == 0) {
    load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_B.Sum4_n;
  } else {
    if ((int32_T)load_arduino_v_13_B.switch_timone == 0) {
      /* MultiPortSwitch: '<S39>/Switch Bumpless 4' */
      load_arduino_v_13_B.Sum1_lg = load_arduino_v_13_B.Sum4_n;
    } else {
      if ((load_arduino_v_13_B.AL != 0) &&
          (!(load_arduino_v_13_B.ByteUnpack_o2_e[2] >
             load_arduino_v_13_P.Switch3_Threshold))) {
        /* Gain: '<S547>/Gain' incorporates:
         *  MultiPortSwitch: '<S39>/Switch Bumpless 4'
         *  MultiPortSwitch: '<S540>/Multiport Switch3'
         *  Switch: '<S540>/Switch3'
         */
        load_arduino_v_13_B.Gain1_k *= load_arduino_v_13_P.Gain_Gain;

        /* Switch: '<S549>/Switch2' incorporates:
         *  Abs: '<S549>/Abs'
         *  Constant: '<S549>/Constant2'
         *  MultiPortSwitch: '<S39>/Switch Bumpless 4'
         *  MultiPortSwitch: '<S540>/Multiport Switch3'
         *  Sum: '<S549>/Sum'
         *  Switch: '<S540>/Switch3'
         */
        if (!(load_arduino_v_13_B.Gain1_c >
              load_arduino_v_13_P.Switch2_Threshold)) {
          load_arduino_v_13_B.Gain1_c = load_arduino_v_13_P.Constant2_Value_j -
            fabs(load_arduino_v_13_B.Gain1_c);
        }

        /* End of Switch: '<S549>/Switch2' */

        /* Switch: '<S548>/Switch2' incorporates:
         *  Abs: '<S548>/Abs'
         *  Constant: '<S548>/Constant2'
         *  MultiPortSwitch: '<S39>/Switch Bumpless 4'
         *  MultiPortSwitch: '<S540>/Multiport Switch3'
         *  Sum: '<S548>/Sum'
         *  Switch: '<S540>/Switch3'
         */
        if (!(load_arduino_v_13_B.Gain1_k >
              load_arduino_v_13_P.Switch2_Threshold_i)) {
          load_arduino_v_13_B.Gain1_k = load_arduino_v_13_P.Constant2_Value_d -
            fabs(load_arduino_v_13_B.Gain1_k);
        }

        /* End of Switch: '<S548>/Switch2' */

        /* MultiPortSwitch: '<S39>/Switch Bumpless 4' incorporates:
         *  Constant: '<S540>/Constant3'
         *  MultiPortSwitch: '<S540>/Multiport Switch3'
         *  Product: '<S540>/Product4'
         *  Sum: '<S540>/Sum2'
         *  Switch: '<S540>/Switch3'
         */
        load_arduino_v_13_B.Sum1_lg = (load_arduino_v_13_B.Gain1_c -
          load_arduino_v_13_B.Gain1_k) * load_arduino_v_13_P.Kp_Rotta_psi;
      }
    }

    /* Saturate: '<S39>/saturatore R' incorporates:
     *  DataTypeConversion: '<S947>/Data Type Conversion5'
     *  MATLAB Function: '<S40>/MATLAB Function'
     *  MultiPortSwitch: '<S39>/Switch Bumpless 4'
     *  MultiPortSwitch: '<S540>/Multiport Switch3'
     *  Switch: '<S540>/Switch3'
     */
    if (load_arduino_v_13_B.Sum1_lg > load_arduino_v_13_P.attuatore_Rmax) {
      load_arduino_v_13_B.Sum1_lg = load_arduino_v_13_P.attuatore_Rmax;
    } else {
      if (load_arduino_v_13_B.Sum1_lg < load_arduino_v_13_P.attuatore_Rmin) {
        load_arduino_v_13_B.Sum1_lg = load_arduino_v_13_P.attuatore_Rmin;
      }
    }

    /* End of Saturate: '<S39>/saturatore R' */
    load_arduino_v_13_B.IProdOut_b = load_arduino_v_13_P.inv_R *
      load_arduino_v_13_B.Sum1_lg;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 6' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (load_arduino_v_13_P.Constant_Value_bh2 < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_P.Constant_Value_bh2);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant_Value_bh2);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[0] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S31>/Gain2' */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain2_Gain_j *
    load_arduino_v_13_B.Gain_o;

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[1] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Sum: '<S31>/Sum' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_od *
    load_arduino_v_13_B.Sum3_o + load_arduino_v_13_P.Constant2_Value_m;

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[2] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Sum: '<S31>/Sum1' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S33>/Gain'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_i *
    load_arduino_v_13_B.PWM_rudder_p + load_arduino_v_13_P.Constant2_Value_m;

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[3] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Sum: '<S31>/Sum2' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S34>/Gain'
   */
  load_arduino_v_13_B.Go_Home = load_arduino_v_13_P.Gain_Gain_bh *
    load_arduino_v_13_B.IProdOut_b + load_arduino_v_13_P.Constant2_Value_m;

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (load_arduino_v_13_B.Go_Home < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.Go_Home);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Go_Home);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[4] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);
  if (load_arduino_v_13_P.Constant1_Value_pa[0] < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_P.Constant1_Value_pa[0]);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant1_Value_pa[0]);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[5] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);
  if (load_arduino_v_13_P.Constant1_Value_pa[1] < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_P.Constant1_Value_pa[1]);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant1_Value_pa[1]);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[6] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);
  if (load_arduino_v_13_P.Constant1_Value_pa[2] < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_P.Constant1_Value_pa[2]);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Constant1_Value_pa[2]);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[7] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Gain: '<S20>/Gain' */
  load_arduino_v_13_B.err = load_arduino_v_13_P.Gain_Gain_jr *
    load_arduino_v_13_B.Gain4[1];

  /* Saturate: '<S20>/Saturation' */
  if (load_arduino_v_13_B.err > load_arduino_v_13_P.Saturation_UpperSat) {
    load_arduino_v_13_B.err = load_arduino_v_13_P.Saturation_UpperSat;
  } else {
    if (load_arduino_v_13_B.err < load_arduino_v_13_P.Saturation_LowerSat) {
      load_arduino_v_13_B.err = load_arduino_v_13_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_13_B.err < 0.0) {
    load_arduino_v_13_B.Sum4_n = ceil(load_arduino_v_13_B.err);
  } else {
    load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.err);
  }

  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Heading[8] = (uint16_T)(load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n :
    (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* Memory: '<S2>/Memory' */
  load_arduino_v_13_B.Memory_a = load_arduino_v_13_DW.Memory_PreviousInput_n;

  /* MATLAB Function: '<S963>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S963>/Data Type Conversion'
   *  DataTypeConversion: '<S963>/Data Type Conversion2'
   */
  if (load_arduino_v_13_B.SFunction_o14 == 1) {
    load_arduino_v_13_DW.P_ref = load_arduino_v_13_B.SFunctionBuilder1;
  }

  if (load_arduino_v_13_B.SFunction_o16 == 1) {
    load_arduino_v_13_DW.P_ref = load_arduino_v_13_B.SFunction_o17;
    load_arduino_v_13_DW.rl_up = 20.0;
    load_arduino_v_13_DW.rl_dw = -20.0;
  }

  /* Product: '<S967>/delta rise limit' incorporates:
   *  MATLAB Function: '<S963>/MATLAB Function'
   *  SampleTimeMath: '<S967>/sample time'
   *
   * About '<S967>/sample time':
   *  y = K where K = ( w * Ts )
   */
  load_arduino_v_13_B.err = load_arduino_v_13_DW.rl_up *
    load_arduino_v_13_P.sampletime_WtEt;

  /* Sum: '<S967>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S963>/MATLAB Function'
   *  UnitDelay: '<S967>/Delay Input2'
   *
   * Block description for '<S967>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S967>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_13_B.Gain1_k = load_arduino_v_13_DW.P_ref -
    load_arduino_v_13_DW.DelayInput2_DSTATE;

  /* Switch: '<S973>/Switch2' incorporates:
   *  RelationalOperator: '<S973>/LowerRelop1'
   */
  if (!(load_arduino_v_13_B.Gain1_k > load_arduino_v_13_B.err)) {
    /* Product: '<S967>/delta fall limit' incorporates:
     *  MATLAB Function: '<S963>/MATLAB Function'
     *  SampleTimeMath: '<S967>/sample time'
     *
     * About '<S967>/sample time':
     *  y = K where K = ( w * Ts )
     */
    load_arduino_v_13_B.err = load_arduino_v_13_DW.rl_dw *
      load_arduino_v_13_P.sampletime_WtEt;

    /* Switch: '<S973>/Switch' incorporates:
     *  RelationalOperator: '<S973>/UpperRelop'
     */
    if (!(load_arduino_v_13_B.Gain1_k < load_arduino_v_13_B.err)) {
      load_arduino_v_13_B.err = load_arduino_v_13_B.Gain1_k;
    }

    /* End of Switch: '<S973>/Switch' */
  }

  /* End of Switch: '<S973>/Switch2' */

  /* Sum: '<S967>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S967>/Delay Input2'
   *
   * Block description for '<S967>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S967>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_13_DW.DelayInput2_DSTATE += load_arduino_v_13_B.err;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S967>/Delay Input2'
   *
   * Block description for '<S967>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_13_B.DataTypeConversion2 = (real32_T)
    load_arduino_v_13_DW.DelayInput2_DSTATE;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S963>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  load_arduino_v_13_B.DataTypeConversion_l = (real32_T)
    (load_arduino_v_13_P.PatohPa_Gain * (real_T)
     load_arduino_v_13_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion2'
   *  Gain: '<S2>/Pa to hPa1'
   *  Gain: '<S947>/Gain1'
   *  Gain: '<S947>/Gain7'
   */
  load_arduino_v_13_B.DataTypeConversion1_g = (real32_T)
    (load_arduino_v_13_P.Gain1_Gain_px * (real_T)
     load_arduino_v_13_B.ByteUnpack_o3[2] * load_arduino_v_13_P.Gain7_Gain *
     load_arduino_v_13_P.PatohPa1_Gain);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  load_arduino_v_13_B.f0 = (real32_T)floor
    (load_arduino_v_13_B.SFunctionBuilder_o1);
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion2_m = (int16_T)(load_arduino_v_13_B.f0 <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.f0 :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_13_B.f0);

  /* End of DataTypeConversion: '<S2>/Data Type Conversion2' */

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S21>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&load_arduino_v_13_B.iflogic,
    &load_arduino_v_13_B.DataTypeConversion3,
    &load_arduino_v_13_P.SIUAVuint8_Value, &load_arduino_v_13_B.GC_info[0],
    &load_arduino_v_13_B.Val_out_MAV[0], &load_arduino_v_13_B.WP_info[0],
    &load_arduino_v_13_B.WP_param[0],
    &load_arduino_v_13_P.onboard_control_sensor_presentu[0],
    &load_arduino_v_13_B.TmpSignalConversionAtSFunctionI[0],
    &load_arduino_v_13_B.Gain1, &load_arduino_v_13_B.B_Remaining,
    &load_arduino_v_13_B.DataTypeConversion,
    &load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[0],
    &load_arduino_v_13_B.DataTypeConversion_ld[0],
    &load_arduino_v_13_B.DataTypeConversion1[0],
    &load_arduino_v_13_B.DataTypeConversion_a[0],
    &load_arduino_v_13_B.DataTypeConversion1_p[0],
    &load_arduino_v_13_B.DataTypeConversion2_h, &load_arduino_v_13_B.AGAC[0],
    &load_arduino_v_13_B.Heading_g, &load_arduino_v_13_B.Throttle,
    &load_arduino_v_13_B.Heading[0], &load_arduino_v_13_B.Memory_a,
    &load_arduino_v_13_B.DataTypeConversion2, &load_arduino_v_13_B.SFunction_o14,
    &load_arduino_v_13_B.Switch1_g, &load_arduino_v_13_B.SFunction_o15,
    &load_arduino_v_13_B.DataTypeConversion_l,
    &load_arduino_v_13_B.DataTypeConversion1_g,
    &load_arduino_v_13_B.DataTypeConversion2_m,
    &load_arduino_v_13_B.SFunction_o5[0], &load_arduino_v_13_B.Gain,
    &load_arduino_v_13_B.Gain_g, &load_arduino_v_13_B.h_Home, (uint16_T*)
    &load_arduino_v_13_U16GND, &load_arduino_v_13_B.SFunction_o1_j,
    &load_arduino_v_13_B.SFunction_o2_f[0], &load_arduino_v_13_B.SFunction_o3,
    &load_arduino_v_13_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (load_arduino_v_13_B.SFunction_o1_j > 0) {
    /* Chart: '<S15>/Chart' */
    if (load_arduino_v_13_DW.is_active_c9_load_arduino_v_13 == 0U) {
      load_arduino_v_13_DW.is_active_c9_load_arduino_v_13 = 1U;
      load_arduino_v_13_DW.i = 1U;
    } else {
      memcpy(&load_arduino_v_13_B.bt[0], &load_arduino_v_13_B.SFunction_o2_f[0],
             264U * sizeof(uint8_T));
      do {
        exitg3 = 0;
        load_arduino_v_13_B.n = load_arduino_v_13_DW.i;
        sts = load_arduino_v_13_B.bt[(int32_T)load_arduino_v_13_B.n - 1];
        MW_Serial_write(load_arduino_v_13_DW.obj_o.port, &sts, 1.0,
                        load_arduino_v_13_DW.obj_o.dataSizeInBytes,
                        load_arduino_v_13_DW.obj_o.sendModeEnum,
                        load_arduino_v_13_DW.obj_o.dataType,
                        load_arduino_v_13_DW.obj_o.sendFormatEnum, 2.0, '\x00');
        if (load_arduino_v_13_DW.i < load_arduino_v_13_B.SFunction_o3) {
          load_arduino_v_13_B.firstcol = load_arduino_v_13_DW.i + 1;
          if (load_arduino_v_13_B.firstcol > 255) {
            load_arduino_v_13_B.firstcol = 255;
          }

          load_arduino_v_13_DW.i = (uint8_T)load_arduino_v_13_B.firstcol;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      load_arduino_v_13_DW.i = 1U;
    }

    /* End of Chart: '<S15>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation2' */
  switch ((int32_T)load_arduino_v_13_B.modo) {
   case 1:
    load_arduino_v_13_B.err = load_arduino_v_13_B.QUOTA;
    break;

   case 2:
    load_arduino_v_13_B.err = load_arduino_v_13_B.h_vett;
    break;

   case 3:
    load_arduino_v_13_B.err = load_arduino_v_13_B.h_ref;
    break;

   case 4:
    load_arduino_v_13_B.err = load_arduino_v_13_B.QUOTA_m;
    break;

   default:
    load_arduino_v_13_B.err = load_arduino_v_13_B.h_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation2' */

  /* Sum: '<S42>/Sum1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion5'
   */
  load_arduino_v_13_B.err -= load_arduino_v_13_B.ByteUnpack_o2_e[2];

  /* Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' incorporates:
   *  Abs: '<S42>/Abs'
   */
  if (load_arduino_v_13_DW.is_active_c23_load_arduino_v_13 == 0U) {
    load_arduino_v_13_DW.is_active_c23_load_arduino_v_13 = 1U;
    load_arduino_v_13_DW.is_c23_load_arduino_v_13 = load_arduino_v_13_IN_Select;
  } else if (load_arduino_v_13_DW.is_c23_load_arduino_v_13 ==
             load_arduino_v_13_IN_Hold) {
    if (fabs(load_arduino_v_13_B.err) > 10.0) {
      load_arduino_v_13_DW.is_c23_load_arduino_v_13 =
        load_arduino_v_13_IN_Select;
    }
  } else {
    if (fabs(load_arduino_v_13_B.err) < 10.0) {
      load_arduino_v_13_DW.is_c23_load_arduino_v_13 = load_arduino_v_13_IN_Hold;
    }
  }

  /* End of Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */

  /* MATLABSystem: '<S964>/Serial Receive1' */
  MW_Serial_read(0, load_arduino_v_13_DW.obj_e.DataSizeInBytes,
                 load_arduino_v_13_B.data, &sts);

  /* Outputs for Enabled SubSystem: '<S964>/Subsystem2' incorporates:
   *  EnablePort: '<S976>/Enable'
   */
  if (sts > 0) {
    /* MATLAB Function: '<S976>/Create_message' */
    sts = 0U;
    if (!load_arduino_v_13_DW.start_found) {
      load_arduino_v_13_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_13_B.i - 1 < 32)) {
        if (load_arduino_v_13_B.data[(uint8_T)load_arduino_v_13_B.i - 1] == 36)
        {
          load_arduino_v_13_B.caso = -(uint8_T)load_arduino_v_13_B.i;
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
               load_arduino_v_13_B.caso + 32; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_DW.message[load_arduino_v_13_B.firstcol] =
              load_arduino_v_13_B.data[((uint8_T)load_arduino_v_13_B.i +
              load_arduino_v_13_B.firstcol) - 1];
          }

          load_arduino_v_13_DW.counter_a = (uint8_T)(33 - (uint8_T)
            load_arduino_v_13_B.i);
          load_arduino_v_13_DW.start_found = true;
          exitg1 = true;
        } else {
          load_arduino_v_13_B.i++;
        }
      }
    } else {
      load_arduino_v_13_B.firstcol = 1;
      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_13_B.firstcol - 1 < 32)) {
        if (load_arduino_v_13_B.data[(uint8_T)load_arduino_v_13_B.firstcol - 1] ==
            13) {
          load_arduino_v_13_DW.end_found = true;
          sts = (uint8_T)load_arduino_v_13_B.firstcol;
          exitg1 = true;
        } else {
          load_arduino_v_13_B.firstcol++;
        }
      }

      if (load_arduino_v_13_DW.end_found) {
        if (1 > sts) {
          load_arduino_v_13_B.firstcol = 0;
        } else {
          load_arduino_v_13_B.firstcol = sts;
        }

        load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
             load_arduino_v_13_B.caso; load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_B.i = (int32_T)((uint32_T)(1 +
            load_arduino_v_13_B.firstcol) + load_arduino_v_13_DW.counter_a);
          if ((uint32_T)load_arduino_v_13_B.i > 255U) {
            load_arduino_v_13_B.i = 255;
          }

          load_arduino_v_13_DW.message[load_arduino_v_13_B.i - 1] =
            load_arduino_v_13_B.data[load_arduino_v_13_B.firstcol];
        }

        memcpy(&load_arduino_v_13_B.messaggio_c[0],
               &load_arduino_v_13_DW.message[0], 80U * sizeof(uint8_T));
        load_arduino_v_13_DW.end_found = false;
        load_arduino_v_13_B.AL = 32 - sts;
        load_arduino_v_13_DW.counter_a = (uint8_T)load_arduino_v_13_B.AL;
        if (sts == 32) {
          load_arduino_v_13_DW.start_found = false;
          memset(&load_arduino_v_13_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          load_arduino_v_13_DW.start_found = true;
          load_arduino_v_13_B.caso = -sts;
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <=
               load_arduino_v_13_B.caso + 31; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_DW.message[load_arduino_v_13_B.firstcol] =
              load_arduino_v_13_B.data[sts + load_arduino_v_13_B.firstcol];
          }

          load_arduino_v_13_B.firstcol = sts + 48;
          if (0 <= load_arduino_v_13_B.firstcol - 1) {
            memset(&load_arduino_v_13_DW.message[load_arduino_v_13_B.AL], 0,
                   ((load_arduino_v_13_B.firstcol + load_arduino_v_13_B.AL) -
                    load_arduino_v_13_B.AL) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S976>/Subsystem' incorporates:
         *  EnablePort: '<S978>/Enable'
         */
        /* MATLAB Function: '<S978>/MATLAB Function' */
        sts = 0U;
        find_comma = 0U;
        load_arduino_v_13_B.indice_dimario = 0U;
        for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 80;
             load_arduino_v_13_B.i++) {
          messaggio = (int8_T)
            load_arduino_v_13_B.messaggio_c[load_arduino_v_13_B.i];
          if (messaggio == '$') {
            load_arduino_v_13_B.firstcol = (int32_T)(sts + 1U);
            if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
              load_arduino_v_13_B.firstcol = 255;
            }

            sts = (uint8_T)load_arduino_v_13_B.firstcol;
          }

          if (messaggio == ',') {
            load_arduino_v_13_B.firstcol = (int32_T)(find_comma + 1U);
            if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
              load_arduino_v_13_B.firstcol = 255;
            }

            find_comma = (uint8_T)load_arduino_v_13_B.firstcol;
          }

          load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.i] = messaggio;
        }

        if ((sts == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <
               80; load_arduino_v_13_B.firstcol++) {
            load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
              (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol] ==
               '$');
          }

          load_arduino_v_13_B.firstcol = 0;
          exitg1 = false;
          while ((!exitg1) && (load_arduino_v_13_B.firstcol < 80)) {
            if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol]) {
              ii_data_idx_0 = (int8_T)(load_arduino_v_13_B.firstcol + 1);
              exitg1 = true;
            } else {
              load_arduino_v_13_B.firstcol++;
            }
          }

          for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <
               5; load_arduino_v_13_B.firstcol++) {
            messaggio =
              load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
              ii_data_idx_0];
            load_arduino_v_13_B.mess_type_b[load_arduino_v_13_B.firstcol] =
              (messaggio == ib[load_arduino_v_13_B.firstcol]);
            load_arduino_v_13_B.mess_type[load_arduino_v_13_B.firstcol] =
              messaggio;
          }

          if (load_arduino_v_13_ifWhileCond_f(load_arduino_v_13_B.mess_type_b))
          {
            for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <
                 80; load_arduino_v_13_B.firstcol++) {
              load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
                (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol] ==
                 ',');
            }

            load_arduino_v_13_B.firstcol = 0;
            load_arduino_v_13_B.AL = 0;
            exitg1 = false;
            while ((!exitg1) && (load_arduino_v_13_B.AL < 80)) {
              if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.AL]) {
                load_arduino_v_13_B.firstcol++;
                load_arduino_v_13_B.c_ii_data[load_arduino_v_13_B.firstcol - 1] =
                  (int8_T)(load_arduino_v_13_B.AL + 1);
                if (load_arduino_v_13_B.firstcol >= 80) {
                  exitg1 = true;
                } else {
                  load_arduino_v_13_B.AL++;
                }
              } else {
                load_arduino_v_13_B.AL++;
              }
            }

            if (1 > load_arduino_v_13_B.firstcol) {
              load_arduino_v_13_B.firstcol = 0;
            }

            load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
            if (0 <= load_arduino_v_13_B.caso) {
              memcpy(&load_arduino_v_13_B.comma_gga_data[0],
                     &load_arduino_v_13_B.c_ii_data[0],
                     (load_arduino_v_13_B.caso + 1) * sizeof(int8_T));
            }

            for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <
                 80; load_arduino_v_13_B.firstcol++) {
              load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
                (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol] ==
                 '*');
            }

            load_arduino_v_13_B.firstcol = 0;
            load_arduino_v_13_B.AL = 0;
            exitg1 = false;
            while ((!exitg1) && (load_arduino_v_13_B.AL < 80)) {
              if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.AL]) {
                load_arduino_v_13_B.firstcol++;
                load_arduino_v_13_B.c_ii_data[load_arduino_v_13_B.firstcol - 1] =
                  (int8_T)(load_arduino_v_13_B.AL + 1);
                if (load_arduino_v_13_B.firstcol >= 80) {
                  exitg1 = true;
                } else {
                  load_arduino_v_13_B.AL++;
                }
              } else {
                load_arduino_v_13_B.AL++;
              }
            }

            if (1 > load_arduino_v_13_B.firstcol) {
              load_arduino_v_13_B.firstcol = 0;
            }

            load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
            if (0 <= load_arduino_v_13_B.caso) {
              memcpy(&load_arduino_v_13_B.star_data[0],
                     &load_arduino_v_13_B.c_ii_data[0],
                     (load_arduino_v_13_B.caso + 1) * sizeof(int8_T));
            }

            for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <
                 80; load_arduino_v_13_B.firstcol++) {
              load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
                (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol] ==
                 '$');
            }

            load_arduino_v_13_B.firstcol = -1;
            load_arduino_v_13_B.AL = 0;
            exitg1 = false;
            while ((!exitg1) && (load_arduino_v_13_B.AL < 80)) {
              if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.AL]) {
                load_arduino_v_13_B.firstcol++;
                load_arduino_v_13_B.c_ii_data[load_arduino_v_13_B.firstcol] =
                  (int8_T)(load_arduino_v_13_B.AL + 1);
                if (load_arduino_v_13_B.firstcol + 1 >= 80) {
                  exitg1 = true;
                } else {
                  load_arduino_v_13_B.AL++;
                }
              } else {
                load_arduino_v_13_B.AL++;
              }
            }

            load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double
              (&load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
               [2]]);
            load_arduino_v_13_B.firstcol = load_arduino_v_13_B.comma_gga_data[2]
              + 3;
            load_arduino_v_13_B.AL = load_arduino_v_13_B.comma_gga_data[3] - 1;
            if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.AL) {
              load_arduino_v_13_B.firstcol = 1;
              load_arduino_v_13_B.AL = 0;
            }

            load_arduino_v_13_B.firstcol--;
            load_arduino_v_13_B.messaggio_size_m[0] = 1;
            load_arduino_v_13_B.AL -= load_arduino_v_13_B.firstcol;
            load_arduino_v_13_B.messaggio_size_m[1] = load_arduino_v_13_B.AL;
            for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                 load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
              load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                load_arduino_v_13_B.i];
            }

            load_arduino_v_13_B.c_x = load_arduino_v_13_str2double_g
              (load_arduino_v_13_B.messaggio_data,
               load_arduino_v_13_B.messaggio_size_m);
            if (load_arduino_v_13_B.c_x.im == 0.0) {
              load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                60.0;
            } else if (load_arduino_v_13_B.c_x.re == 0.0) {
              load_arduino_v_13_B.psi_ref_pre = 0.0;
            } else {
              load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                60.0;
            }

            load_arduino_v_13_B.Gain1_k = load_arduino_v_13_B.Lat_1.re +
              load_arduino_v_13_B.psi_ref_pre;
            if (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                [3]] == 'S') {
              load_arduino_v_13_B.Gain1_k = -load_arduino_v_13_B.Gain1_k;
            }

            load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_gv
              (&load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
               [4]]);
            load_arduino_v_13_B.AL = load_arduino_v_13_B.comma_gga_data[4] + 4;
            load_arduino_v_13_B.caso = load_arduino_v_13_B.comma_gga_data[5] - 1;
            if (load_arduino_v_13_B.AL > load_arduino_v_13_B.caso) {
              load_arduino_v_13_B.AL = 1;
              load_arduino_v_13_B.caso = 0;
            }

            load_arduino_v_13_B.firstcol = load_arduino_v_13_B.AL - 1;
            load_arduino_v_13_B.messaggio_size_g1[0] = 1;
            load_arduino_v_13_B.AL = load_arduino_v_13_B.caso -
              load_arduino_v_13_B.firstcol;
            load_arduino_v_13_B.messaggio_size_g1[1] = load_arduino_v_13_B.AL;
            for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                 load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
              load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                load_arduino_v_13_B.i];
            }

            load_arduino_v_13_B.c_x = load_arduino_v_13_str2double_g
              (load_arduino_v_13_B.messaggio_data,
               load_arduino_v_13_B.messaggio_size_g1);
            if (load_arduino_v_13_B.c_x.im == 0.0) {
              load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                60.0;
            } else if (load_arduino_v_13_B.c_x.re == 0.0) {
              load_arduino_v_13_B.psi_ref_pre = 0.0;
            } else {
              load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                60.0;
            }

            load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.Lat_1.re +
              load_arduino_v_13_B.psi_ref_pre;
            if (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                [5]] == 'W') {
              load_arduino_v_13_B.Gain1_c = -load_arduino_v_13_B.Gain1_c;
            }

            load_arduino_v_13_B.i = load_arduino_v_13_B.comma_gga_data[6] + 1;
            load_arduino_v_13_B.tolleranza_distWP_fut =
              load_arduino_v_13_B.comma_gga_data[7] - 1;
            if (load_arduino_v_13_B.i >
                load_arduino_v_13_B.tolleranza_distWP_fut) {
              load_arduino_v_13_B.i = 1;
              load_arduino_v_13_B.tolleranza_distWP_fut = 0;
            }

            load_arduino_v_13_B.firstcol = load_arduino_v_13_B.i - 1;
            load_arduino_v_13_B.messaggio_size_g[0] = 1;
            load_arduino_v_13_B.AL = load_arduino_v_13_B.tolleranza_distWP_fut -
              load_arduino_v_13_B.firstcol;
            load_arduino_v_13_B.messaggio_size_g[1] = load_arduino_v_13_B.AL;
            for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                 load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
              load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                load_arduino_v_13_B.i];
            }

            load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_g
              (load_arduino_v_13_B.messaggio_data,
               load_arduino_v_13_B.messaggio_size_g);

            /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
            load_arduino_v_13_B.ComplextoRealImag[2] =
              load_arduino_v_13_B.Lat_1.re;
            load_arduino_v_13_B.caso = load_arduino_v_13_B.comma_gga_data[7] + 1;
            load_arduino_v_13_B.AL = load_arduino_v_13_B.comma_gga_data[8] - 1;
            if (load_arduino_v_13_B.caso > load_arduino_v_13_B.AL) {
              load_arduino_v_13_B.caso = 1;
              load_arduino_v_13_B.AL = 0;
            }

            load_arduino_v_13_B.firstcol = load_arduino_v_13_B.caso - 1;
            load_arduino_v_13_B.messaggio_size_f[0] = 1;
            load_arduino_v_13_B.AL -= load_arduino_v_13_B.firstcol;
            load_arduino_v_13_B.messaggio_size_f[1] = load_arduino_v_13_B.AL;
            for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                 load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
              load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                load_arduino_v_13_B.i];
            }

            load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_g
              (load_arduino_v_13_B.messaggio_data,
               load_arduino_v_13_B.messaggio_size_f);

            /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
            load_arduino_v_13_B.ComplextoRealImag[4] =
              load_arduino_v_13_B.Lat_1.re;
            load_arduino_v_13_B.firstcol = load_arduino_v_13_B.comma_gga_data[9]
              + 1;
            load_arduino_v_13_B.caso = load_arduino_v_13_B.comma_gga_data[10] -
              1;
            if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.caso) {
              load_arduino_v_13_B.firstcol = 1;
              load_arduino_v_13_B.caso = 0;
            }

            load_arduino_v_13_B.firstcol--;
            load_arduino_v_13_B.messaggio_size[0] = 1;
            load_arduino_v_13_B.AL = load_arduino_v_13_B.caso -
              load_arduino_v_13_B.firstcol;
            load_arduino_v_13_B.messaggio_size[1] = load_arduino_v_13_B.AL;
            for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                 load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
              load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                load_arduino_v_13_B.i];
            }

            load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_g
              (load_arduino_v_13_B.messaggio_data,
               load_arduino_v_13_B.messaggio_size);

            /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
            load_arduino_v_13_B.ComplextoRealImag[3] =
              load_arduino_v_13_B.Lat_1.re;
            if (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                [10]] == 'W') {
              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[3] =
                -load_arduino_v_13_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
            load_arduino_v_13_B.ComplextoRealImag[5] =
              load_arduino_v_13_DW.Memory_PreviousInput_l[5];
            load_arduino_v_13_B.ComplextoRealImag[6] =
              load_arduino_v_13_DW.Memory_PreviousInput_l[6];
            load_arduino_v_13_B.ComplextoRealImag[7] =
              load_arduino_v_13_DW.Memory_PreviousInput_l[7];
            load_arduino_v_13_B.ComplextoRealImag[8] =
              load_arduino_v_13_DW.Memory_PreviousInput_l[8];
            ck_ric[0] =
              load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.star_data[0]];
            ck_ric[1] =
              load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.star_data[0] +
              1];
            load_arduino_v_13_B.firstcol = load_arduino_v_13_B.c_ii_data[0] + 1;
            load_arduino_v_13_B.AL = load_arduino_v_13_B.star_data[0] - 1;
            if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.AL) {
              load_arduino_v_13_B.firstcol = 1;
              load_arduino_v_13_B.AL = 0;
            }

            load_arduino_v_13_B.firstcol--;
            load_arduino_v_13_B.AL -= load_arduino_v_13_B.firstcol;
            for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                 load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
              load_arduino_v_13_B.NMEA_gga_string_data[load_arduino_v_13_B.i] =
                (uint8_T)
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                load_arduino_v_13_B.i];
            }

            sts = 0U;
            load_arduino_v_13_B.firstcol = 0;
            while (load_arduino_v_13_B.firstcol <= load_arduino_v_13_B.AL - 1) {
              sts ^=
                load_arduino_v_13_B.NMEA_gga_string_data[load_arduino_v_13_B.firstcol];
              load_arduino_v_13_B.firstcol++;
            }

            if (sts != load_arduino_v_13_hex2dec(ck_ric)) {
              load_arduino_v_13_B.Gain1_k =
                load_arduino_v_13_DW.Memory_PreviousInput_l[0];
              load_arduino_v_13_B.Gain1_c =
                load_arduino_v_13_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[2] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[2];
              load_arduino_v_13_B.ComplextoRealImag[3] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[3];
              load_arduino_v_13_B.ComplextoRealImag[4] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[4];
              load_arduino_v_13_B.indice_dimario = 10U;
            }
          } else {
            for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol <
                 5; load_arduino_v_13_B.firstcol++) {
              load_arduino_v_13_B.mess_type_b[load_arduino_v_13_B.firstcol] =
                (load_arduino_v_13_B.mess_type[load_arduino_v_13_B.firstcol] ==
                 jb[load_arduino_v_13_B.firstcol]);
            }

            if (load_arduino_v_13_ifWhileCond_f(load_arduino_v_13_B.mess_type_b))
            {
              for (load_arduino_v_13_B.firstcol = 0;
                   load_arduino_v_13_B.firstcol < 80;
                   load_arduino_v_13_B.firstcol++) {
                load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
                  (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol]
                   == ',');
              }

              load_arduino_v_13_B.firstcol = 0;
              load_arduino_v_13_B.AL = 0;
              exitg1 = false;
              while ((!exitg1) && (load_arduino_v_13_B.AL < 80)) {
                if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.AL]) {
                  load_arduino_v_13_B.firstcol++;
                  load_arduino_v_13_B.c_ii_data[load_arduino_v_13_B.firstcol - 1]
                    = (int8_T)(load_arduino_v_13_B.AL + 1);
                  if (load_arduino_v_13_B.firstcol >= 80) {
                    exitg1 = true;
                  } else {
                    load_arduino_v_13_B.AL++;
                  }
                } else {
                  load_arduino_v_13_B.AL++;
                }
              }

              if (1 > load_arduino_v_13_B.firstcol) {
                load_arduino_v_13_B.firstcol = 0;
              }

              load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
              if (0 <= load_arduino_v_13_B.caso) {
                memcpy(&load_arduino_v_13_B.comma_gga_data[0],
                       &load_arduino_v_13_B.c_ii_data[0],
                       (load_arduino_v_13_B.caso + 1) * sizeof(int8_T));
              }

              for (load_arduino_v_13_B.firstcol = 0;
                   load_arduino_v_13_B.firstcol < 80;
                   load_arduino_v_13_B.firstcol++) {
                load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
                  (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol]
                   == '*');
              }

              load_arduino_v_13_B.firstcol = 0;
              load_arduino_v_13_B.AL = 0;
              exitg1 = false;
              while ((!exitg1) && (load_arduino_v_13_B.AL < 80)) {
                if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.AL]) {
                  load_arduino_v_13_B.firstcol++;
                  load_arduino_v_13_B.c_ii_data[load_arduino_v_13_B.firstcol - 1]
                    = (int8_T)(load_arduino_v_13_B.AL + 1);
                  if (load_arduino_v_13_B.firstcol >= 80) {
                    exitg1 = true;
                  } else {
                    load_arduino_v_13_B.AL++;
                  }
                } else {
                  load_arduino_v_13_B.AL++;
                }
              }

              if (1 > load_arduino_v_13_B.firstcol) {
                load_arduino_v_13_B.firstcol = 0;
              }

              load_arduino_v_13_B.caso = load_arduino_v_13_B.firstcol - 1;
              if (0 <= load_arduino_v_13_B.caso) {
                memcpy(&load_arduino_v_13_B.star_data[0],
                       &load_arduino_v_13_B.c_ii_data[0],
                       (load_arduino_v_13_B.caso + 1) * sizeof(int8_T));
              }

              for (load_arduino_v_13_B.firstcol = 0;
                   load_arduino_v_13_B.firstcol < 80;
                   load_arduino_v_13_B.firstcol++) {
                load_arduino_v_13_B.b_x[load_arduino_v_13_B.firstcol] =
                  (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol]
                   == '$');
              }

              load_arduino_v_13_B.firstcol = -1;
              load_arduino_v_13_B.AL = 0;
              exitg1 = false;
              while ((!exitg1) && (load_arduino_v_13_B.AL < 80)) {
                if (load_arduino_v_13_B.b_x[load_arduino_v_13_B.AL]) {
                  load_arduino_v_13_B.firstcol++;
                  load_arduino_v_13_B.c_ii_data[load_arduino_v_13_B.firstcol] =
                    (int8_T)(load_arduino_v_13_B.AL + 1);
                  if (load_arduino_v_13_B.firstcol + 1 >= 80) {
                    exitg1 = true;
                  } else {
                    load_arduino_v_13_B.AL++;
                  }
                } else {
                  load_arduino_v_13_B.AL++;
                }
              }

              load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double
                (&load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                 [1]]);
              load_arduino_v_13_B.firstcol = load_arduino_v_13_B.comma_gga_data
                [1] + 3;
              load_arduino_v_13_B.AL = load_arduino_v_13_B.comma_gga_data[2] - 1;
              if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.AL) {
                load_arduino_v_13_B.firstcol = 1;
                load_arduino_v_13_B.AL = 0;
              }

              load_arduino_v_13_B.firstcol--;
              load_arduino_v_13_B.messaggio_size_m[0] = 1;
              load_arduino_v_13_B.AL -= load_arduino_v_13_B.firstcol;
              load_arduino_v_13_B.messaggio_size_m[1] = load_arduino_v_13_B.AL;
              for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                   load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
                load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                  load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                  load_arduino_v_13_B.i];
              }

              load_arduino_v_13_B.c_x = load_arduino_v_13_str2double_g
                (load_arduino_v_13_B.messaggio_data,
                 load_arduino_v_13_B.messaggio_size_m);
              if (load_arduino_v_13_B.c_x.im == 0.0) {
                load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                  60.0;
              } else if (load_arduino_v_13_B.c_x.re == 0.0) {
                load_arduino_v_13_B.psi_ref_pre = 0.0;
              } else {
                load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                  60.0;
              }

              load_arduino_v_13_B.Gain1_k = load_arduino_v_13_B.Lat_1.re +
                load_arduino_v_13_B.psi_ref_pre;
              if (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                  [2]] == 'S') {
                load_arduino_v_13_B.Gain1_k = -load_arduino_v_13_B.Gain1_k;
              }

              load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_gv
                (&load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                 [3]]);
              load_arduino_v_13_B.AL = load_arduino_v_13_B.comma_gga_data[3] + 4;
              load_arduino_v_13_B.caso = load_arduino_v_13_B.comma_gga_data[4] -
                1;
              if (load_arduino_v_13_B.AL > load_arduino_v_13_B.caso) {
                load_arduino_v_13_B.AL = 1;
                load_arduino_v_13_B.caso = 0;
              }

              load_arduino_v_13_B.firstcol = load_arduino_v_13_B.AL - 1;
              load_arduino_v_13_B.messaggio_size_g1[0] = 1;
              load_arduino_v_13_B.AL = load_arduino_v_13_B.caso -
                load_arduino_v_13_B.firstcol;
              load_arduino_v_13_B.messaggio_size_g1[1] = load_arduino_v_13_B.AL;
              for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                   load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
                load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                  load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                  load_arduino_v_13_B.i];
              }

              load_arduino_v_13_B.c_x = load_arduino_v_13_str2double_g
                (load_arduino_v_13_B.messaggio_data,
                 load_arduino_v_13_B.messaggio_size_g1);
              if (load_arduino_v_13_B.c_x.im == 0.0) {
                load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                  60.0;
              } else if (load_arduino_v_13_B.c_x.re == 0.0) {
                load_arduino_v_13_B.psi_ref_pre = 0.0;
              } else {
                load_arduino_v_13_B.psi_ref_pre = load_arduino_v_13_B.c_x.re /
                  60.0;
              }

              load_arduino_v_13_B.Gain1_c = load_arduino_v_13_B.Lat_1.re +
                load_arduino_v_13_B.psi_ref_pre;
              if (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                  [4]] == 'W') {
                load_arduino_v_13_B.Gain1_c = -load_arduino_v_13_B.Gain1_c;
              }

              load_arduino_v_13_B.Lat_1 = load_arduino_v_1_str2double_gv1
                (load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[5] =
                load_arduino_v_13_B.Lat_1.re;
              load_arduino_v_13_B.firstcol = load_arduino_v_13_B.comma_gga_data
                [6] + 1;
              load_arduino_v_13_B.AL = load_arduino_v_13_B.comma_gga_data[7] - 1;
              if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.AL) {
                load_arduino_v_13_B.firstcol = 1;
                load_arduino_v_13_B.AL = 0;
              }

              load_arduino_v_13_B.firstcol--;
              load_arduino_v_13_B.messaggio_size_g[0] = 1;
              load_arduino_v_13_B.AL -= load_arduino_v_13_B.firstcol;
              load_arduino_v_13_B.messaggio_size_g[1] = load_arduino_v_13_B.AL;
              for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                   load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
                load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                  load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                  load_arduino_v_13_B.i];
              }

              load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_g
                (load_arduino_v_13_B.messaggio_data,
                 load_arduino_v_13_B.messaggio_size_g);

              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[6] =
                load_arduino_v_13_B.Lat_1.re;
              load_arduino_v_13_B.i = load_arduino_v_13_B.comma_gga_data[8] + 1;
              load_arduino_v_13_B.caso = load_arduino_v_13_B.comma_gga_data[9] -
                1;
              if (load_arduino_v_13_B.i > load_arduino_v_13_B.caso) {
                load_arduino_v_13_B.i = 1;
                load_arduino_v_13_B.caso = 0;
              }

              load_arduino_v_13_B.firstcol = load_arduino_v_13_B.i - 1;
              load_arduino_v_13_B.messaggio_size_f[0] = 1;
              load_arduino_v_13_B.AL = load_arduino_v_13_B.caso -
                load_arduino_v_13_B.firstcol;
              load_arduino_v_13_B.messaggio_size_f[1] = load_arduino_v_13_B.AL;
              for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                   load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
                load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                  load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                  load_arduino_v_13_B.i];
              }

              load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_g
                (load_arduino_v_13_B.messaggio_data,
                 load_arduino_v_13_B.messaggio_size_f);

              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[7] =
                load_arduino_v_13_B.Lat_1.re;
              load_arduino_v_13_B.i = load_arduino_v_13_B.comma_gga_data[10] + 1;
              load_arduino_v_13_B.caso = load_arduino_v_13_B.comma_gga_data[11]
                - 1;
              if (load_arduino_v_13_B.i > load_arduino_v_13_B.caso) {
                load_arduino_v_13_B.i = 1;
                load_arduino_v_13_B.caso = 0;
              }

              load_arduino_v_13_B.firstcol = load_arduino_v_13_B.i - 1;
              load_arduino_v_13_B.messaggio_size[0] = 1;
              load_arduino_v_13_B.AL = load_arduino_v_13_B.caso -
                load_arduino_v_13_B.firstcol;
              load_arduino_v_13_B.messaggio_size[1] = load_arduino_v_13_B.AL;
              for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                   load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
                load_arduino_v_13_B.messaggio_data[load_arduino_v_13_B.i] =
                  load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                  load_arduino_v_13_B.i];
              }

              load_arduino_v_13_B.Lat_1 = load_arduino_v_13_str2double_g
                (load_arduino_v_13_B.messaggio_data,
                 load_arduino_v_13_B.messaggio_size);

              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[8] =
                load_arduino_v_13_B.Lat_1.re;
              load_arduino_v_13_B.ComplextoRealImag[2] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[2];
              load_arduino_v_13_B.ComplextoRealImag[3] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[3];
              load_arduino_v_13_B.ComplextoRealImag[4] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[4];
              ck_ric[0] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.star_data[0]];
              ck_ric[1] =
                load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.star_data[0]
                + 1];
              load_arduino_v_13_B.firstcol = load_arduino_v_13_B.c_ii_data[0] +
                1;
              load_arduino_v_13_B.AL = load_arduino_v_13_B.star_data[0] - 1;
              if (load_arduino_v_13_B.firstcol > load_arduino_v_13_B.AL) {
                load_arduino_v_13_B.firstcol = 1;
                load_arduino_v_13_B.AL = 0;
              }

              load_arduino_v_13_B.firstcol--;
              load_arduino_v_13_B.AL -= load_arduino_v_13_B.firstcol;
              for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i <
                   load_arduino_v_13_B.AL; load_arduino_v_13_B.i++) {
                load_arduino_v_13_B.NMEA_gga_string_data[load_arduino_v_13_B.i] =
                  (uint8_T)
                  load_arduino_v_13_B.messaggio_k[load_arduino_v_13_B.firstcol +
                  load_arduino_v_13_B.i];
              }

              sts = 0U;
              load_arduino_v_13_B.firstcol = 0;
              while (load_arduino_v_13_B.firstcol <= load_arduino_v_13_B.AL - 1)
              {
                sts ^=
                  load_arduino_v_13_B.NMEA_gga_string_data[load_arduino_v_13_B.firstcol];
                load_arduino_v_13_B.firstcol++;
              }

              if (sts != load_arduino_v_13_hex2dec(ck_ric)) {
                load_arduino_v_13_B.Gain1_k =
                  load_arduino_v_13_DW.Memory_PreviousInput_l[0];
                load_arduino_v_13_B.Gain1_c =
                  load_arduino_v_13_DW.Memory_PreviousInput_l[1];

                /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
                load_arduino_v_13_B.ComplextoRealImag[5] =
                  load_arduino_v_13_DW.Memory_PreviousInput_l[5];
                load_arduino_v_13_B.ComplextoRealImag[6] =
                  load_arduino_v_13_DW.Memory_PreviousInput_l[6];
                load_arduino_v_13_B.ComplextoRealImag[7] =
                  load_arduino_v_13_DW.Memory_PreviousInput_l[7];
                load_arduino_v_13_B.ComplextoRealImag[8] =
                  load_arduino_v_13_DW.Memory_PreviousInput_l[8];
                load_arduino_v_13_B.indice_dimario = 20U;
              }
            } else {
              load_arduino_v_13_B.Gain1_k =
                load_arduino_v_13_DW.Memory_PreviousInput_l[0];
              load_arduino_v_13_B.Gain1_c =
                load_arduino_v_13_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
              load_arduino_v_13_B.ComplextoRealImag[2] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[2];
              load_arduino_v_13_B.ComplextoRealImag[3] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[3];
              load_arduino_v_13_B.ComplextoRealImag[4] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[4];
              load_arduino_v_13_B.ComplextoRealImag[5] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[5];
              load_arduino_v_13_B.ComplextoRealImag[6] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[6];
              load_arduino_v_13_B.ComplextoRealImag[7] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[7];
              load_arduino_v_13_B.ComplextoRealImag[8] =
                load_arduino_v_13_DW.Memory_PreviousInput_l[8];
            }
          }
        } else {
          load_arduino_v_13_B.Gain1_k =
            load_arduino_v_13_DW.Memory_PreviousInput_l[0];
          load_arduino_v_13_B.Gain1_c =
            load_arduino_v_13_DW.Memory_PreviousInput_l[1];

          /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
          load_arduino_v_13_B.ComplextoRealImag[2] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[2];
          load_arduino_v_13_B.ComplextoRealImag[3] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[3];
          load_arduino_v_13_B.ComplextoRealImag[4] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[4];
          load_arduino_v_13_B.ComplextoRealImag[5] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[5];
          load_arduino_v_13_B.ComplextoRealImag[6] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[6];
          load_arduino_v_13_B.ComplextoRealImag[7] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[7];
          load_arduino_v_13_B.ComplextoRealImag[8] =
            load_arduino_v_13_DW.Memory_PreviousInput_l[8];
        }

        /* End of MATLAB Function: '<S978>/MATLAB Function' */

        /* ComplexToRealImag: '<S978>/Complex to Real-Imag' */
        load_arduino_v_13_B.ComplextoRealImag[0] = load_arduino_v_13_B.Gain1_k;
        load_arduino_v_13_B.ComplextoRealImag[1] = load_arduino_v_13_B.Gain1_c;

        /* Update for Memory: '<S978>/Memory' */
        memcpy(&load_arduino_v_13_DW.Memory_PreviousInput_l[0],
               &load_arduino_v_13_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S976>/Subsystem' */
      } else {
        for (load_arduino_v_13_B.firstcol = 0; load_arduino_v_13_B.firstcol < 32;
             load_arduino_v_13_B.firstcol++) {
          load_arduino_v_13_B.i = (int32_T)((uint32_T)(1 +
            load_arduino_v_13_B.firstcol) + load_arduino_v_13_DW.counter_a);
          if ((uint32_T)load_arduino_v_13_B.i > 255U) {
            load_arduino_v_13_B.i = 255;
          }

          load_arduino_v_13_DW.message[load_arduino_v_13_B.i - 1] =
            load_arduino_v_13_B.data[load_arduino_v_13_B.firstcol];
        }

        load_arduino_v_13_B.firstcol = (int32_T)(32U +
          load_arduino_v_13_DW.counter_a);
        if ((uint32_T)load_arduino_v_13_B.firstcol > 255U) {
          load_arduino_v_13_B.firstcol = 255;
        }

        load_arduino_v_13_DW.counter_a = (uint8_T)load_arduino_v_13_B.firstcol;
      }
    }

    /* End of MATLAB Function: '<S976>/Create_message' */
  }

  /* End of MATLABSystem: '<S964>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S964>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S964>/Subsystem1' incorporates:
   *  EnablePort: '<S975>/Enable'
   */
  if (load_arduino_v_13_B.SFunction_o14 > 0) {
    /* Switch: '<S975>/Switch' incorporates:
     *  Constant: '<S975>/Constant'
     *  Constant: '<S975>/Constant1'
     *  Constant: '<S975>/Constant2'
     *  Constant: '<S975>/Constant3'
     *  Logic: '<S975>/OR'
     *  RelationalOperator: '<S975>/Equal'
     *  RelationalOperator: '<S975>/Equal1'
     *  RelationalOperator: '<S975>/Equal2'
     */
    if ((load_arduino_v_13_B.ComplextoRealImag[5] ==
         load_arduino_v_13_P.Constant_Value_l) ||
        (load_arduino_v_13_B.ComplextoRealImag[5] ==
         load_arduino_v_13_P.Constant1_Value_b) ||
        (load_arduino_v_13_B.ComplextoRealImag[5] ==
         load_arduino_v_13_P.Constant3_Value_ct)) {
      load_arduino_v_13_B.Switch = load_arduino_v_13_B.ComplextoRealImag[7];
    } else {
      load_arduino_v_13_B.Switch = load_arduino_v_13_P.Constant2_Value_dy;
    }

    /* End of Switch: '<S975>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S964>/Subsystem1' */

  /* DataTypeConversion: '<S947>/Data Type Conversion4' incorporates:
   *  Sum: '<S964>/Sum'
   */
  load_arduino_v_13_B.DataTypeConversion4[0] = (real32_T)
    load_arduino_v_13_B.ComplextoRealImag[0];
  load_arduino_v_13_B.DataTypeConversion4[1] = (real32_T)
    load_arduino_v_13_B.ComplextoRealImag[1];
  load_arduino_v_13_B.DataTypeConversion4[2] = (real32_T)
    (load_arduino_v_13_B.ComplextoRealImag[7] - load_arduino_v_13_B.Switch);

  /* MATLAB Function: '<S963>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S963>/Data Type Conversion'
   *  UnitDelay: '<S967>/Delay Input2'
   *
   * Block description for '<S967>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_13_B.Gain1_k = log(load_arduino_v_13_DW.DelayInput2_DSTATE /
    (real_T)load_arduino_v_13_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S947>/Data Type Conversion4' incorporates:
   *  MATLAB Function: '<S963>/MATLAB Function1'
   */
  load_arduino_v_13_B.DataTypeConversion4[3] = (real32_T)
    (load_arduino_v_13_B.Gain1_k * 29.260958205912335) *
    (load_arduino_v_13_B.Switch1_g + 273.15F) / (real32_T)(1.0 -
    load_arduino_v_13_B.Gain1_k * -0.095098114169215084);

  /* DataTypeConversion: '<S947>/Data Type Conversion' incorporates:
   *  Gain: '<S947>/Gain'
   *  Gain: '<S952>/Gain'
   *  Gain: '<S953>/Gain'
   *  Gain: '<S954>/Gain'
   *  SignalConversion: '<S947>/TmpSignal ConversionAtGainInport1'
   */
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_nk *
     load_arduino_v_13_B.DataTypeConversion1_b[3] *
     load_arduino_v_13_P.Gain_Gain_bk));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[3] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_db *
     load_arduino_v_13_B.DataTypeConversion1_b[4] *
     load_arduino_v_13_P.Gain_Gain_bk));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[4] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_dc *
     load_arduino_v_13_B.DataTypeConversion1_b[5] *
     load_arduino_v_13_P.Gain_Gain_bk));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[5] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_bk *
     load_arduino_v_13_B.DataTypeConversion1_b[6]));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[0] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_bk *
     load_arduino_v_13_B.DataTypeConversion1_b[0]));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[6] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_bk *
     load_arduino_v_13_B.DataTypeConversion1_b[7]));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[1] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_bk *
     load_arduino_v_13_B.DataTypeConversion1_b[1]));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[7] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_bk *
     load_arduino_v_13_B.DataTypeConversion1_b[8]));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[2] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);
  load_arduino_v_13_B.f0 = (real32_T)floor((real32_T)
    (load_arduino_v_13_P.Gain_Gain_bk *
     load_arduino_v_13_B.DataTypeConversion1_b[2]));
  if (rtIsNaNF(load_arduino_v_13_B.f0) || rtIsInfF(load_arduino_v_13_B.f0)) {
    load_arduino_v_13_B.f0 = 0.0F;
  } else {
    load_arduino_v_13_B.f0 = (real32_T)fmod(load_arduino_v_13_B.f0, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_lx[8] = (int16_T)
    (load_arduino_v_13_B.f0 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.f0 : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.f0);

  /* End of DataTypeConversion: '<S947>/Data Type Conversion' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S990>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion7'
   *  Product: '<S990>/Divide'
   *  Product: '<S990>/Multiply'
   *  Sum: '<S990>/Sum'
   *  Sum: '<S990>/Sum3'
   */
  load_arduino_v_13_B.Sum4_n = floor((load_arduino_v_13_B.Sum3_o -
    load_arduino_v_13_P.attuatore_Emin) / load_arduino_v_13_B.Switch_bk *
    load_arduino_v_13_B.rtb_long_end_tmp + (real_T)
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[3]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion_p = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S987>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion9'
   *  Product: '<S987>/Divide'
   *  Product: '<S987>/Multiply'
   *  Sum: '<S987>/Sum'
   *  Sum: '<S987>/Sum3'
   */
  load_arduino_v_13_B.Sum4_n = floor((load_arduino_v_13_B.PWM_rudder_p -
    load_arduino_v_13_P.attuatore_Amin) / load_arduino_v_13_B.Abs_o *
    load_arduino_v_13_B.Product1 + (real_T)
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[5]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_c = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S10>/Data Type Conversion1' */

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S988>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   *  Product: '<S988>/Divide'
   *  Product: '<S988>/Multiply'
   *  Sum: '<S988>/Sum'
   *  Sum: '<S988>/Sum3'
   */
  load_arduino_v_13_B.Sum4_n = floor((load_arduino_v_13_B.IProdOut_b -
    load_arduino_v_13_P.attuatore_Rmin) / load_arduino_v_13_B.rtb_Sum4_n_tmp *
    load_arduino_v_13_B.rtb_Sum4_n_tmp_j + (real_T)
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[7]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion2_j = (int16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S10>/Data Type Conversion2' */

  /* DataTypeConversion: '<S947>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion9'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   *  Gain: '<S947>/Gain2'
   *  Gain: '<S947>/Gain3'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.ComplextoRealImag[4]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_h[0] = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_P.Gain2_Gain_m *
    load_arduino_v_13_B.ComplextoRealImag[2]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_h[1] = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);
  load_arduino_v_13_B.firstcol = (int32_T)fmod
    (load_arduino_v_13_B.DataTypeConversion_p, 65536.0);
  load_arduino_v_13_B.DataTypeConversion1_h[2] = (uint16_T)
    (load_arduino_v_13_B.firstcol < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)load_arduino_v_13_B.firstcol : (int32_T)(uint16_T)
     load_arduino_v_13_B.firstcol);
  load_arduino_v_13_B.firstcol = (int32_T)fmod
    (load_arduino_v_13_B.DataTypeConversion1_c, 65536.0);
  load_arduino_v_13_B.DataTypeConversion1_h[3] = (uint16_T)
    (load_arduino_v_13_B.firstcol < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)load_arduino_v_13_B.firstcol : (int32_T)(uint16_T)
     load_arduino_v_13_B.firstcol);
  load_arduino_v_13_B.DataTypeConversion1_h[4] = (uint16_T)
    load_arduino_v_13_B.PWM_throttle;
  load_arduino_v_13_B.DataTypeConversion1_h[5] = (uint16_T)
    load_arduino_v_13_B.PWM_elevator;
  load_arduino_v_13_B.DataTypeConversion1_h[6] = (uint16_T)
    load_arduino_v_13_B.PWM_aileron;
  load_arduino_v_13_B.DataTypeConversion1_h[7] = (uint16_T)
    load_arduino_v_13_B.PWM_rudder;
  load_arduino_v_13_B.firstcol = (int32_T)fmod
    (load_arduino_v_13_B.DataTypeConversion2_j, 65536.0);
  load_arduino_v_13_B.DataTypeConversion1_h[8] = (uint16_T)
    (load_arduino_v_13_B.firstcol < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)load_arduino_v_13_B.firstcol : (int32_T)(uint16_T)
     load_arduino_v_13_B.firstcol);
  load_arduino_v_13_B.Sum4_n = floor((real_T)load_arduino_v_13_P.Gain3_Gain *
    load_arduino_v_13_B.SFunctionBuilder_o1);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.DataTypeConversion1_h[9] = (uint16_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint16_T)load_arduino_v_13_B.Sum4_n);

  /* End of DataTypeConversion: '<S947>/Data Type Conversion1' */

  /* DataTypeConversion: '<S947>/Data Type Conversion6' */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.ComplextoRealImag[5]);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 256.0);
  }

  /* SignalConversion: '<S947>/TmpSignal ConversionAtByte PackInport5' incorporates:
   *  DataTypeConversion: '<S947>/Data Type Conversion6'
   */
  load_arduino_v_13_B.TmpSignalConversionAtBytePackIn[0] = (uint8_T)
    (load_arduino_v_13_B.Sum4_n < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
     -load_arduino_v_13_B.Sum4_n : (int32_T)(uint8_T)load_arduino_v_13_B.Sum4_n);
  load_arduino_v_13_B.TmpSignalConversionAtBytePackIn[1] =
    load_arduino_v_13_B.indice_dimario;

  /* DataTypeConversion: '<S947>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S963>/Data Type Conversion'
   */
  load_arduino_v_13_B.DataTypeConversion8 =
    load_arduino_v_13_B.SFunctionBuilder1;

  /* S-Function (any2byte_svd): '<S947>/Byte Pack' incorporates:
   *  Constant: '<S947>/Fine MSG1'
   *  Constant: '<S947>/Inizio MSG'
   */

  /* Pack: <S947>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_B.DataTypeConversion4[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_B.DataTypeConversion_lx[0], MW_inputPortWidth);
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
    /* Input data type - uint16_T, size - 10 */
    {
      MW_inputPortWidth = 10 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_B.DataTypeConversion1_h[0], MW_inputPortWidth);
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
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_B.TmpSignalConversionAtBytePackIn[0],
             MW_inputPortWidth);
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
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_B.DataTypeConversion8, MW_inputPortWidth);
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
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_13_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_13_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S947>/Serial Transmit' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 63;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_B.dataIn[load_arduino_v_13_B.i] =
      load_arduino_v_13_B.BytePack[load_arduino_v_13_B.i];
  }

  MW_Serial_write(load_arduino_v_13_DW.obj.port, load_arduino_v_13_B.dataIn,
                  63.0, load_arduino_v_13_DW.obj.dataSizeInBytes,
                  load_arduino_v_13_DW.obj.sendModeEnum,
                  load_arduino_v_13_DW.obj.dataType,
                  load_arduino_v_13_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S947>/Serial Transmit' */

  /* S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */
  Servo_microseconds_alettoni_beta_3_Outputs_wrapper
    (&load_arduino_v_13_B.DataTypeConversion1_c,
     &load_arduino_v_13_DW.SFunctionBuilder10_DSTATE);

  /* Product: '<S989>/Multiply' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion4'
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   *  Sum: '<S989>/Sum1'
   */
  load_arduino_v_13_B.Gain_o *= (real_T)
    (load_arduino_v_13_B.One_time_initialization.ByteUnpack[0] -
     load_arduino_v_13_B.One_time_initialization.ByteUnpack[1]);

  /* Sum: '<S989>/Sum' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   */
  load_arduino_v_13_B.Sum4_n = floor(load_arduino_v_13_B.Gain_o);
  if (rtIsNaN(load_arduino_v_13_B.Sum4_n) || rtIsInf(load_arduino_v_13_B.Sum4_n))
  {
    load_arduino_v_13_B.Sum4_n = 0.0;
  } else {
    load_arduino_v_13_B.Sum4_n = fmod(load_arduino_v_13_B.Sum4_n, 65536.0);
  }

  load_arduino_v_13_B.Sum = (int16_T)((load_arduino_v_13_B.Sum4_n < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_13_B.Sum4_n : (int32_T)
    (int16_T)(uint16_T)load_arduino_v_13_B.Sum4_n) + (int16_T)
    load_arduino_v_13_B.One_time_initialization.ByteUnpack[1]);

  /* End of Sum: '<S989>/Sum' */

  /* S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper(&load_arduino_v_13_B.Sum,
    &load_arduino_v_13_DW.SFunctionBuilder4_DSTATE);

  /* S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */
  Servo_microseconds_timone_beta_3_Outputs_wrapper
    (&load_arduino_v_13_B.DataTypeConversion2_j,
     &load_arduino_v_13_DW.SFunctionBuilder5_DSTATE);

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper
    (&load_arduino_v_13_B.DataTypeConversion_p,
     &load_arduino_v_13_DW.SFunctionBuilder9_DSTATE);

  /* Abs: '<S758>/Abs1' */
  load_arduino_v_13_B.IProdOut_b = fabs(load_arduino_v_13_B.Gain_k3);

  /* Outputs for Resettable SubSystem: '<S750>/Resettable Subsystem' */
  load_arduino_v_13_B.IProdOut_b = load_ar_ResettableSubsystem
    (load_arduino_v_13_B.SFunction_o4_n[1],
     &load_arduino_v_13_DW.ResettableSubsystem,
     &load_arduino_v_13_P.ResettableSubsystem,
     &load_arduino_v_13_PrevZCX.ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S750>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S750>/Enabled Subsystem' */
  load_ardui_EnabledSubsystem(load_arduino_v_13_B.SFunction_o4_n[1],
    load_arduino_v_13_B.IProdOut_b, &load_arduino_v_13_B.Gain1_k,
    &load_arduino_v_13_P.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S750>/Enabled Subsystem' */

  /* MATLAB Function: '<S752>/MATLAB Function1' */
  if ((!load_arduino_v_13_DW.Tf_not_empty) || (load_arduino_v_13_B.AP_int[0] ==
       1) || (load_arduino_v_13_B.AP_int[1] == 0)) {
    load_arduino_v_13_DW.Tf_not_empty = true;
  }

  /* End of MATLAB Function: '<S752>/MATLAB Function1' */

  /* Product: '<S956>/Product4' incorporates:
   *  MATLAB Function: '<S956>/MATLAB Function'
   */
  load_arduino_v_13_B.checksum *= 1.0 - 2.0 * load_arduino_v_13_B.r;

  /* Sum: '<S956>/Sum1' incorporates:
   *  UnitDelay: '<S956>/Unit Delay'
   */
  load_arduino_v_13_DW.UnitDelay_DSTATE = load_arduino_v_13_B.rtb_Gain1_kw_idx_1
    + load_arduino_v_13_B.checksum;

  /* S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper
    (&load_arduino_v_13_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&load_arduino_v_13_DW.Memory4_PreviousInput_c[0],
         &load_arduino_v_13_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S965>/S-Function Builder' incorporates:
   *  Constant: '<S965>/Constant1'
   */

  /* S-Function "Mti_wrapper" Block: <S965>/S-Function Builder */
  Mti_Update_wrapper(&load_arduino_v_13_P.Constant1_Value_g,
                     &load_arduino_v_13_B.SFunctionBuilder_o1_n[0],
                     &load_arduino_v_13_B.SFunctionBuilder_o2_f,
                     &load_arduino_v_13_DW.SFunctionBuilder_DSTATE);

  /* Update for Delay: '<S965>/Delay' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 41;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_DW.Delay_DSTATE[load_arduino_v_13_B.i] =
      load_arduino_v_13_B.SFunctionBuilder_o1_n[load_arduino_v_13_B.i];
  }

  /* End of Update for Delay: '<S965>/Delay' */

  /* Update for UnitDelay: '<S963>/Unit Delay' incorporates:
   *  Constant: '<S963>/Constant3'
   */
  load_arduino_v_13_DW.UnitDelay_DSTATE_d =
    load_arduino_v_13_P.Constant3_Value_ok;

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&load_arduino_v_13_P.Constant1_Value_a,
    &load_arduino_v_13_B.SFunctionBuilder_o1_h[0],
    &load_arduino_v_13_B.SFunctionBuilder_o2,
    &load_arduino_v_13_DW.SFunctionBuilder_DSTATE_l);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&load_arduino_v_13_DW.Memory5_PreviousInput_l[0],
         &load_arduino_v_13_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<S1>/Memory1' */
  load_arduino_v_13_DW.Memory1_PreviousInput_d[0] = status;
  load_arduino_v_13_DW.Memory1_PreviousInput_d[1] = rtb_H_mav_e_idx_1;

  /* Update for Memory: '<Root>/Memory' */
  load_arduino_v_13_DW.Memory_PreviousInput_h5[0] =
    load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[0];
  load_arduino_v_13_DW.Memory_PreviousInput_h5[1] =
    load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[1];
  load_arduino_v_13_DW.Memory_PreviousInput_h5[2] =
    load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[2];
  load_arduino_v_13_DW.Memory_PreviousInput_h5[3] =
    load_arduino_v_13_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 8;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_DW.Memory_PreviousInput_ic[load_arduino_v_13_B.i] =
      load_arduino_v_13_B.SFunction_o11[load_arduino_v_13_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' */
  for (load_arduino_v_13_B.i = 0; load_arduino_v_13_B.i < 9;
       load_arduino_v_13_B.i++) {
    load_arduino_v_13_DW.Memory2_PreviousInput_a[load_arduino_v_13_B.i] =
      load_arduino_v_13_B.AP_int[load_arduino_v_13_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for DiscreteIntegrator: '<S544>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S544>/Constant7'
   */
  load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE +=
    load_arduino_v_13_P.DiscreteTimeIntegrator_gainva_k *
    load_arduino_v_13_P.Constant7_Value;
  if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE >=
      load_arduino_v_13_P.DiscreteTimeIntegrator_UpperS_l) {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_13_P.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE <=
        load_arduino_v_13_P.DiscreteTimeIntegrator_LowerS_c) {
      load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE =
        load_arduino_v_13_P.DiscreteTimeIntegrator_LowerS_c;
    }
  }

  if (load_arduino_v_13_B.Al_selector > 0.0) {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (load_arduino_v_13_B.Al_selector < 0.0) {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (load_arduino_v_13_B.Al_selector == 0.0) {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S544>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S609>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  beccheggio1'
   *  Gain: '<S577>/Kb'
   *  Gain: '<S644>/Kt'
   *  Gain: '<S8>/Gain1'
   *  Product: '<S598>/IProd Out'
   *  Sum: '<S577>/SumI2'
   *  Sum: '<S577>/SumI4'
   *  Sum: '<S644>/SumI3'
   *  Sum: '<S646>/SumI1'
   */
  load_arduino_v_13_DW.Integrator_DSTATE += ((load_arduino_v_13_P.Gain1_Gain_k2 *
    load_arduino_v_13_P.Ki_becch * load_arduino_v_13_B.Gain1_a +
    (load_arduino_v_13_B.Abs1_b - load_arduino_v_13_B.Abs1) *
    load_arduino_v_13_P.PIDController_Kt_m) + (load_arduino_v_13_B.Abs1 -
    load_arduino_v_13_B.Long_Home) * load_arduino_v_13_P.PIDController_Kb_k) *
    load_arduino_v_13_P.Integrator_gainval_b;

  /* Update for DiscreteIntegrator: '<S707>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  rollio3'
   *  Gain: '<S675>/Kb'
   *  Gain: '<S742>/Kt'
   *  Product: '<S696>/IProd Out'
   *  Sum: '<S675>/SumI2'
   *  Sum: '<S675>/SumI4'
   *  Sum: '<S742>/SumI3'
   *  Sum: '<S744>/SumI1'
   */
  load_arduino_v_13_DW.Integrator_DSTATE_p += (((load_arduino_v_13_B.Alettoni -
    load_arduino_v_13_B.Saturation_f) * load_arduino_v_13_P.PIDController_Kt +
    load_arduino_v_13_B.Gain1_l * load_arduino_v_13_P.Ki_roll) +
    (load_arduino_v_13_B.Saturation_f - load_arduino_v_13_B.Sum_n3) *
    load_arduino_v_13_P.PIDController_Kb) *
    load_arduino_v_13_P.Integrator_gainval_g;
  if (load_arduino_v_13_B.Gain_n > 0.0) {
    load_arduino_v_13_DW.Integrator_PrevResetState = 1;
  } else if (load_arduino_v_13_B.Gain_n < 0.0) {
    load_arduino_v_13_DW.Integrator_PrevResetState = -1;
  } else if (load_arduino_v_13_B.Gain_n == 0.0) {
    load_arduino_v_13_DW.Integrator_PrevResetState = 0;
  } else {
    load_arduino_v_13_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S707>/Integrator' */

  /* Update for DiscreteTransferFcn: '<S543>/Discrete Washout Filter' */
  load_arduino_v_13_DW.DiscreteWashoutFilter_states =
    load_arduino_v_13_B.denAccum;

  /* Update for Memory: '<S2>/Memory' */
  load_arduino_v_13_DW.Memory_PreviousInput_n = load_arduino_v_13_B.SFunction_o4;

  /* Update for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

  /* S-Function "Servo_microseconds_alettoni_beta_3_wrapper" Block: <S10>/S-Function Builder10 */
  Servo_microseconds_alettoni_beta_3_Update_wrapper
    (&load_arduino_v_13_B.DataTypeConversion1_c,
     &load_arduino_v_13_DW.SFunctionBuilder10_DSTATE);

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <S10>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper(&load_arduino_v_13_B.Sum,
    &load_arduino_v_13_DW.SFunctionBuilder4_DSTATE);

  /* Update for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

  /* S-Function "Servo_microseconds_timone_beta_3_wrapper" Block: <S10>/S-Function Builder5 */
  Servo_microseconds_timone_beta_3_Update_wrapper
    (&load_arduino_v_13_B.DataTypeConversion2_j,
     &load_arduino_v_13_DW.SFunctionBuilder5_DSTATE);

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <S10>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper
    (&load_arduino_v_13_B.DataTypeConversion_p,
     &load_arduino_v_13_DW.SFunctionBuilder9_DSTATE);

  /* Update for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S4>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper
    (&load_arduino_v_13_DW.SFunctionBuilder_DSTATE_n);
}

/* Model step function for TID1 */
void load_arduino_v_13_step1(void)     /* Sample time: [0.04s, 0.0s] */
{
  real_T rtb_PulseGenerator1;
  uint8_T rtb_PulseGenerator1_0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  rtb_PulseGenerator1 = (load_arduino_v_13_DW.clockTickCounter <
    load_arduino_v_13_P.PulseGenerator_Duty) &&
    (load_arduino_v_13_DW.clockTickCounter >= 0) ?
    load_arduino_v_13_P.PulseGenerator_Amp : 0.0;
  if (load_arduino_v_13_DW.clockTickCounter >=
      load_arduino_v_13_P.PulseGenerator_Period - 1.0) {
    load_arduino_v_13_DW.clockTickCounter = 0;
  } else {
    load_arduino_v_13_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Pulse Generator' */

  /* DataTypeConversion: '<S941>/Data Type Conversion' */
  if (rtb_PulseGenerator1 < 256.0) {
    if (rtb_PulseGenerator1 >= 0.0) {
      rtb_PulseGenerator1_0 = (uint8_T)rtb_PulseGenerator1;
    } else {
      rtb_PulseGenerator1_0 = 0U;
    }
  } else {
    rtb_PulseGenerator1_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S941>/Data Type Conversion' */

  /* MATLABSystem: '<S941>/Digital Output' */
  writeDigitalPin(13, rtb_PulseGenerator1_0);

  /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
  rtb_PulseGenerator1 = (load_arduino_v_13_DW.clockTickCounter_c <
    load_arduino_v_13_P.PulseGenerator1_Duty) &&
    (load_arduino_v_13_DW.clockTickCounter_c >= 0) ?
    load_arduino_v_13_P.PulseGenerator1_Amp : 0.0;
  if (load_arduino_v_13_DW.clockTickCounter_c >=
      load_arduino_v_13_P.PulseGenerator1_Period - 1.0) {
    load_arduino_v_13_DW.clockTickCounter_c = 0;
  } else {
    load_arduino_v_13_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Pulse Generator1' */

  /* DataTypeConversion: '<S942>/Data Type Conversion' */
  if (rtb_PulseGenerator1 < 256.0) {
    if (rtb_PulseGenerator1 >= 0.0) {
      rtb_PulseGenerator1_0 = (uint8_T)rtb_PulseGenerator1;
    } else {
      rtb_PulseGenerator1_0 = 0U;
    }
  } else {
    rtb_PulseGenerator1_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S942>/Data Type Conversion' */

  /* MATLABSystem: '<S942>/Digital Output' */
  writeDigitalPin(44, rtb_PulseGenerator1_0);
}

/* Model step function for TID2 */
void load_arduino_v_13_step2(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S29>/Add2' incorporates:
   *  Constant: '<S29>/Constant4'
   *  Constant: '<S29>/Constant5'
   *  Memory: '<S29>/Memory2'
   */
  load_arduino_v_13_DW.Memory2_PreviousInput +=
    load_arduino_v_13_P.Constant4_Value_a +
    load_arduino_v_13_P.Constant5_Value_a;

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S29>/Constant4'
   */
  if (load_arduino_v_13_DW.Memory2_PreviousInput >
      load_arduino_v_13_P.Switch1_Threshold_c) {
    load_arduino_v_13_DW.Memory2_PreviousInput =
      load_arduino_v_13_P.Constant4_Value_a;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* Update for RateTransition: '<S29>/Rate Transition' */
  load_arduino_v_13_DW.RateTransition_Buffer0 =
    load_arduino_v_13_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void load_arduino_v_13_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)load_arduino_v_13_M, 0,
                sizeof(RT_MODEL_load_arduino_v_13_T));

  /* block I/O */
  (void) memset(((void *) &load_arduino_v_13_B), 0,
                sizeof(B_load_arduino_v_13_T));

  /* states (dwork) */
  (void) memset((void *)&load_arduino_v_13_DW, 0,
                sizeof(DW_load_arduino_v_13_T));

  {
    codertarget_arduinobase_int_b_T *obj;
    uint32_T i2cname;
    real_T Switch_a;
    int32_T i;
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    uint32_T tmp_0;

    /* Start for Enabled SubSystem: '<S963>/One_time_initialization' */
    One_time_initializati_Start(&load_arduino_v_13_DW.One_time_initialization,
      &load_arduino_v_13_P.One_time_initialization);

    /* End of Start for SubSystem: '<S963>/One_time_initialization' */

    /* Start for Enabled SubSystem: '<S963>/Execution_loop' */
    /* Start for MATLABSystem: '<S968>/I2C Read12' */
    load_arduino_v_13_DW.obj_f.matlabCodegenIsDeleted = true;
    arduinoI2CRead_arduinoI2CRead_j(&load_arduino_v_13_DW.obj_f);
    load_arduino_v_13_DW.obj_f.SampleTime = load_arduino_v_13_P.t_AP;
    obj = &load_arduino_v_13_DW.obj_f;
    load_arduino_v_13_DW.obj_f.isSetupComplete = false;
    load_arduino_v_13_DW.obj_f.isInitialized = 1;
    i2cname = 0;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    load_arduino_v_13_DW.obj_f.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(load_arduino_v_13_DW.obj_f.MW_I2C_HANDLE,
                       load_arduino_v_13_DW.obj_f.BusSpeed);
    load_arduino_v_13_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S968>/I2C Read1' */
    load_arduino_v_13_DW.obj_p.matlabCodegenIsDeleted = true;
    arduinoI2CRead_arduinoI2CRead_j(&load_arduino_v_13_DW.obj_p);
    load_arduino_v_13_DW.obj_p.SampleTime = load_arduino_v_13_P.t_AP;
    obj = &load_arduino_v_13_DW.obj_p;
    load_arduino_v_13_DW.obj_p.isSetupComplete = false;
    load_arduino_v_13_DW.obj_p.isInitialized = 1;
    i2cname = 0;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    load_arduino_v_13_DW.obj_p.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(load_arduino_v_13_DW.obj_p.MW_I2C_HANDLE,
                       load_arduino_v_13_DW.obj_p.BusSpeed);
    load_arduino_v_13_DW.obj_p.isSetupComplete = true;

    /* End of Start for SubSystem: '<S963>/Execution_loop' */

    /* Start for MATLABSystem: '<S947>/Serial Receive' */
    load_arduino_v_13_DW.obj_m.isInitialized = 0;
    load_arduino_v_13_DW.obj_m.isInitialized = 1;
    load_arduino_v_13_DW.obj_m.DataTypeWidth = 1U;
    tmp_0 = 31U * load_arduino_v_13_DW.obj_m.DataTypeWidth;
    if (tmp_0 > 65535U) {
      tmp_0 = 65535U;
    }

    load_arduino_v_13_DW.obj_m.DataSizeInBytes = (uint16_T)tmp_0;

    /* End of Start for MATLABSystem: '<S947>/Serial Receive' */

    /* Start for Enabled SubSystem: '<S2>/Enable ' */
    /* Start for Chart: '<S15>/Chart' incorporates:
     *  SubSystem: '<S24>/sendbyte'
     */
    /* Start for MATLABSystem: '<S25>/Serial Transmit' */
    load_arduino_v_13_DW.obj_o.isInitialized = 0;
    load_arduino_v_13_DW.obj_o.isInitialized = 1;
    load_arduino_v_13_DW.obj_o.port = 2.0;
    load_arduino_v_13_DW.obj_o.dataSizeInBytes = 1.0;
    load_arduino_v_13_DW.obj_o.dataType = 0.0;
    load_arduino_v_13_DW.obj_o.sendModeEnum = 0.0;
    load_arduino_v_13_DW.obj_o.sendFormatEnum = 0.0;

    /* End of Start for SubSystem: '<S2>/Enable ' */

    /* Start for MATLABSystem: '<S964>/Serial Receive1' */
    load_arduino_v_13_DW.obj_e.isInitialized = 0;
    load_arduino_v_13_DW.obj_e.isInitialized = 1;
    load_arduino_v_13_DW.obj_e.DataTypeWidth = 1U;
    if (load_arduino_v_13_DW.obj_e.DataTypeWidth > 2047) {
      load_arduino_v_13_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      load_arduino_v_13_DW.obj_e.DataSizeInBytes = (uint16_T)
        (load_arduino_v_13_DW.obj_e.DataTypeWidth << 5);
    }

    /* End of Start for MATLABSystem: '<S964>/Serial Receive1' */

    /* Start for MATLABSystem: '<S947>/Serial Transmit' */
    load_arduino_v_13_DW.obj.isInitialized = 0;
    load_arduino_v_13_DW.obj.isInitialized = 1;
    load_arduino_v_13_DW.obj.port = 1.0;
    load_arduino_v_13_DW.obj.dataSizeInBytes = 1.0;
    load_arduino_v_13_DW.obj.dataType = 0.0;
    load_arduino_v_13_DW.obj.sendModeEnum = 0.0;
    load_arduino_v_13_DW.obj.sendFormatEnum = 0.0;

    /* Start for MATLABSystem: '<S941>/Digital Output' */
    load_arduino_v_13_DW.obj_c.matlabCodegenIsDeleted = true;
    load_arduino_v_13_DW.obj_c.isInitialized = 0;
    load_arduino_v_13_DW.obj_c.matlabCodegenIsDeleted = false;
    load_arduino_v_13_DW.obj_c.isSetupComplete = false;
    load_arduino_v_13_DW.obj_c.isInitialized = 1;
    digitalIOSetup(13, true);
    load_arduino_v_13_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S942>/Digital Output' */
    load_arduino_v_13_DW.obj_l.matlabCodegenIsDeleted = true;
    load_arduino_v_13_DW.obj_l.isInitialized = 0;
    load_arduino_v_13_DW.obj_l.matlabCodegenIsDeleted = false;
    load_arduino_v_13_DW.obj_l.isSetupComplete = false;
    load_arduino_v_13_DW.obj_l.isInitialized = 1;
    digitalIOSetup(44, true);
    load_arduino_v_13_DW.obj_l.isSetupComplete = true;
    load_arduino_v_13_PrevZCX.ResettableSubsystem_Reset_ZCE_p =
      UNINITIALIZED_ZCSIG;
    load_arduino_v_13_PrevZCX.ResettableSubsystem_Reset_ZCE_h =
      UNINITIALIZED_ZCSIG;
    load_arduino_v_13_PrevZCX.ResettableSubsystem_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    load_arduino_v_13_PrevZCX.SampleandHold_Trig_ZCE_h = UNINITIALIZED_ZCSIG;
    load_arduino_v_13_PrevZCX.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
    load_arduino_v_13_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    load_arduino_v_13_PrevZCX.ResettableSubsystem_o.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;
    load_arduino_v_13_PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&load_arduino_v_13_DW.Memory4_PreviousInput_c[0],
           &load_arduino_v_13_P.Memory4_InitialCondition_g[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S965>/S-Function Builder' incorporates:
     *  Constant: '<S965>/Constant1'
     */

    /* S-Function Block: <S965>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Delay: '<S965>/Delay' */
    for (i = 0; i < 41; i++) {
      load_arduino_v_13_DW.Delay_DSTATE[i] =
        load_arduino_v_13_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S965>/Delay' */

    /* InitializeConditions for UnitDelay: '<S963>/Unit Delay' */
    load_arduino_v_13_DW.UnitDelay_DSTATE_d =
      load_arduino_v_13_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder_DSTATE_l = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      load_arduino_v_13_DW.Memory5_PreviousInput_l[i] =
        load_arduino_v_13_P.Memory5_InitialCondition_d;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput_d[0] =
      load_arduino_v_13_P.Memory1_InitialCondition_b;
    load_arduino_v_13_DW.Memory1_PreviousInput_d[1] =
      load_arduino_v_13_P.Memory1_InitialCondition_b;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_h5[0] =
      load_arduino_v_13_P.Memory_InitialCondition_o;
    load_arduino_v_13_DW.Memory_PreviousInput_h5[1] =
      load_arduino_v_13_P.Memory_InitialCondition_o;
    load_arduino_v_13_DW.Memory_PreviousInput_h5[2] =
      load_arduino_v_13_P.Memory_InitialCondition_o;
    load_arduino_v_13_DW.Memory_PreviousInput_h5[3] =
      load_arduino_v_13_P.Memory_InitialCondition_o;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    load_arduino_v_13_DW.Memory3_PreviousInput_o =
      load_arduino_v_13_P.Memory3_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      load_arduino_v_13_DW.Memory_PreviousInput_ic[i] =
        load_arduino_v_13_P.Memory_InitialCondition_at;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      load_arduino_v_13_DW.Memory2_PreviousInput_a[i] =
        load_arduino_v_13_P.Memory2_InitialCondition_g[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S29>/Rate Transition' */
    load_arduino_v_13_DW.RateTransition_Buffer0 =
      load_arduino_v_13_P.RateTransition_InitialCondition;

    /* InitializeConditions for Memory: '<S29>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput =
      load_arduino_v_13_P.Memory1_InitialCondition_p;

    /* InitializeConditions for Memory: '<S29>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput =
      load_arduino_v_13_P.Memory_InitialCondition_au;

    /* InitializeConditions for UnitDelay: '<S956>/Unit Delay' */
    load_arduino_v_13_DW.UnitDelay_DSTATE =
      load_arduino_v_13_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S544>/Discrete-Time Integrator' */
    load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_13_P.DiscreteTimeIntegrator_IC_d;
    load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator' */
    load_arduino_v_13_DW.Integrator_DSTATE =
      load_arduino_v_13_P.PIDController_InitialConditio_g;

    /* InitializeConditions for DiscreteIntegrator: '<S707>/Integrator' */
    load_arduino_v_13_DW.Integrator_DSTATE_p =
      load_arduino_v_13_P.PIDController_InitialConditio_d;
    load_arduino_v_13_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S543>/Discrete Washout Filter' */
    load_arduino_v_13_DW.DiscreteWashoutFilter_states =
      load_arduino_v_13_P.DiscreteWashoutFilter_InitialSt;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_n =
      load_arduino_v_13_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S967>/Delay Input2'
     *
     * Block description for '<S967>/Delay Input2':
     *
     *  Store in Global RAM
     */
    load_arduino_v_13_DW.DelayInput2_DSTATE =
      load_arduino_v_13_P.DelayInput2_InitialCondition;

    /* InitializeConditions for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

    /* S-Function Block: <S10>/S-Function Builder10 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder10_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

    /* S-Function Block: <S10>/S-Function Builder4 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder4_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

    /* S-Function Block: <S10>/S-Function Builder5 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder5_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

    /* S-Function Block: <S10>/S-Function Builder9 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder9_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

    /* S-Function Block: <S4>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_13_DW.SFunctionBuilder_DSTATE_n = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S29>/Memory2' */
    load_arduino_v_13_DW.Memory2_PreviousInput =
      load_arduino_v_13_P.Memory2_InitialCondition_o;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
    load_arduino_v_13_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    load_arduino_v_13_DW.clockTickCounter_c = 0;

    /* SystemInitialize for Enabled SubSystem: '<S963>/One_time_initialization' */
    One_time_initializatio_Init(&load_arduino_v_13_B.One_time_initialization,
      &load_arduino_v_13_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S963>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S963>/Execution_loop' */
    /* SystemInitialize for Outport: '<S968>/T' */
    load_arduino_v_13_B.SFunctionBuilder_o1 = load_arduino_v_13_P.T_Y0;

    /* SystemInitialize for Outport: '<S968>/p' */
    load_arduino_v_13_B.SFunctionBuilder1 = load_arduino_v_13_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S963>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    load_arduino_v_13_DW.Interr_parz = false;
    memset(&load_arduino_v_13_DW.message_m[0], 0, 100U * sizeof(uint8_T));
    load_arduino_v_13_DW.counter_m = 0U;
    load_arduino_v_13_DW.mess_len = 0.0;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3' */
    load_arduino_v_13_DW.counter = 0U;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&load_arduino_v_13_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);
    load_arduino_v_13_DW.WP_dbP_not_empty = false;
    load_arduino_v_13_DW.WP_dbP_AL_not_empty = false;
    load_arduino_v_13_DW.test1 = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S972>/Subsystem1' */
    /* SystemInitialize for Outport: '<S974>/T_0' */
    load_arduino_v_13_B.T = load_arduino_v_13_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S972>/Subsystem1' */

    /* SystemInitialize for Resettable SubSystem: '<S751>/Resettable Subsystem' */
    lo_ResettableSubsystem_Init(&load_arduino_v_13_DW.ResettableSubsystem_o,
      &load_arduino_v_13_P.ResettableSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S751>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S751>/Enabled Subsystem' */
    load__EnabledSubsystem_Init(&load_arduino_v_13_B.Switch_l,
      &load_arduino_v_13_P.EnabledSubsystem_j);

    /* End of SystemInitialize for SubSystem: '<S751>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S947>/Subsystem1' */
    /* SystemInitialize for MATLAB Function: '<S955>/MATLAB Function' */
    load_arduino_v_13_DW.start_found_i = false;
    load_arduino_v_13_DW.counter_i = 0U;
    for (i = 0; i < 31; i++) {
      load_arduino_v_13_DW.message_a[i] = 0U;
    }

    /* End of SystemInitialize for MATLAB Function: '<S955>/MATLAB Function' */

    /* SystemInitialize for Enabled SubSystem: '<S955>/Subsystem2' */
    /* SystemInitialize for Outport: '<S961>/Out2' */
    load_arduino_v_13_B.ByteUnpack_o2_e[0] = load_arduino_v_13_P.Out2_Y0_cb;

    /* SystemInitialize for Outport: '<S961>/Out3' */
    load_arduino_v_13_B.ByteUnpack_o3[0] = load_arduino_v_13_P.Out3_Y0_a;

    /* SystemInitialize for Outport: '<S961>/Out2' */
    load_arduino_v_13_B.ByteUnpack_o2_e[1] = load_arduino_v_13_P.Out2_Y0_cb;

    /* SystemInitialize for Outport: '<S961>/Out3' */
    load_arduino_v_13_B.ByteUnpack_o3[1] = load_arduino_v_13_P.Out3_Y0_a;

    /* SystemInitialize for Outport: '<S961>/Out2' */
    load_arduino_v_13_B.ByteUnpack_o2_e[2] = load_arduino_v_13_P.Out2_Y0_cb;

    /* SystemInitialize for Outport: '<S961>/Out3' */
    load_arduino_v_13_B.ByteUnpack_o3[2] = load_arduino_v_13_P.Out3_Y0_a;

    /* SystemInitialize for Outport: '<S961>/Out2' */
    load_arduino_v_13_B.ByteUnpack_o2_e[3] = load_arduino_v_13_P.Out2_Y0_cb;

    /* SystemInitialize for Outport: '<S961>/Out3' */
    load_arduino_v_13_B.ByteUnpack_o3[3] = load_arduino_v_13_P.Out3_Y0_a;

    /* End of SystemInitialize for SubSystem: '<S955>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S947>/Subsystem1' */

    /* SystemInitialize for MATLAB Function: '<S757>/MATLAB Function1' */
    load_arduino_v_13_DW.alarm = 0.0;

    /* SystemInitialize for Resettable SubSystem: '<S774>/Resettable Subsystem' */
    /* InitializeConditions for Memory: '<S778>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_h =
      load_arduino_v_13_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S774>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S774>/Enabled ' */
    /* SystemInitialize for Outport: '<S776>/Alarm Safe' */
    load_arduino_v_13_B.Switch_n = load_arduino_v_13_P.AlarmSafe_Y0;

    /* End of SystemInitialize for SubSystem: '<S774>/Enabled ' */

    /* SystemInitialize for Chart: '<S40>/ STATI' */
    load_arduino_v_13_DW.is_AUTOMATICA = 0;
    load_arduino_v_13_DW.is_active_c26_load_arduino_v_13 = 0U;
    load_arduino_v_13_DW.is_c26_load_arduino_v_13 = 0;
    load_arduino_v_13_B.switch_manetta = 0.0;
    load_arduino_v_13_B.switch_equilibratore = 0.0;
    load_arduino_v_13_B.switch_alettoni = 0.0;
    load_arduino_v_13_B.switch_timone = 0.0;
    load_arduino_v_13_B.modo = 1.0;

    /* SystemInitialize for Chart: '<S41>/Chart' */
    load_arduino_v_13_DW.is_active_c21_load_arduino_v_13 = 0U;
    load_arduino_v_13_DW.is_c21_load_arduino_v_13 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S41>/DECOLLO AUTOMATICO' */
    /* InitializeConditions for Memory: '<S780>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_i =
      load_arduino_v_13_P.Memory_InitialCondition_a;

    /* InitializeConditions for Memory: '<S780>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput_o =
      load_arduino_v_13_P.Memory1_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S780>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S788>/ ' */
    load_arduino_v_13_B.In_k = load_arduino_v_13_P._Y0;

    /* End of SystemInitialize for SubSystem: '<S780>/Sample and Hold' */

    /* SystemInitialize for Chart: '<S780>/Chart1' */
    load_arduino_v_13_DW.temporalCounter_i1 = 0U;
    load_arduino_v_13_DW.is_active_c1_load_arduino_v_13 = 0U;
    load_arduino_v_13_DW.is_c1_load_arduino_v_13 = 0;

    /* End of SystemInitialize for SubSystem: '<S41>/DECOLLO AUTOMATICO' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem1' */
    /* InitializeConditions for Memory: '<S782>/Memory7' */
    load_arduino_v_13_DW.Memory7_PreviousInput =
      load_arduino_v_13_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S782>/Memory5' */
    load_arduino_v_13_DW.Memory5_PreviousInput =
      load_arduino_v_13_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S782>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput_l =
      load_arduino_v_13_P.Memory1_InitialCondition_f;

    /* InitializeConditions for Memory: '<S782>/Memory2' */
    load_arduino_v_13_DW.Memory2_PreviousInput_f =
      load_arduino_v_13_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S782>/ALLINEAMENTO' */
    load_arduino_v_13_DW.flag_m = 0.0;

    /* SystemInitialize for Chart: '<S782>/Chart1' */
    load_arduino_v_13_DW.is_active_c10_load_arduino_v_13 = 0U;
    load_arduino_v_13_DW.is_c10_load_arduino_v_13 = 0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S947>/Subsystem1' */
    /* SystemInitialize for Enabled SubSystem: '<S955>/Subsystem2' */
    /* SystemInitialize for Outport: '<S961>/Out4' */
    load_arduino_v_13_B.ByteUnpack_o4[0] = load_arduino_v_13_P.Out4_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S955>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S947>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem1' */
    /* SystemInitialize for Triggered SubSystem: '<S782>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S807>/ ' */
    load_arduino_v_13_B.In[0] = load_arduino_v_13_P._Y0_b[0];

    /* End of SystemInitialize for SubSystem: '<S782>/Sample and Hold' */
    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S947>/Subsystem1' */
    /* SystemInitialize for Enabled SubSystem: '<S955>/Subsystem2' */
    /* SystemInitialize for Outport: '<S961>/Out4' */
    load_arduino_v_13_B.ByteUnpack_o4[1] = load_arduino_v_13_P.Out4_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S955>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S947>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem1' */
    /* SystemInitialize for Triggered SubSystem: '<S782>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S807>/ ' */
    load_arduino_v_13_B.In[1] = load_arduino_v_13_P._Y0_b[1];

    /* End of SystemInitialize for SubSystem: '<S782>/Sample and Hold' */

    /* SystemInitialize for Enabled SubSystem: '<S782>/APPROACH' */
    /* InitializeConditions for DiscreteIntegrator: '<S793>/Discrete-Time Integrator' */
    load_arduino_v_13_DW.DiscreteTimeIntegrator_DSTATE_f =
      load_arduino_v_13_P.DiscreteTimeIntegrator_IC;
    load_arduino_v_13_DW.DiscreteTimeIntegrator_PrevRe_f = 2;

    /* SystemInitialize for MATLAB Function: '<S793>/MATLAB Function' */
    load_arduino_v_13_DW.x_not_empty = false;
    load_arduino_v_13_DW.x_new_not_empty = false;
    load_arduino_v_13_DW.cycle_count_not_empty = false;
    load_arduino_v_13_DW.eps_not_empty = false;

    /* SystemInitialize for Outport: '<S793>/h_ref' */
    load_arduino_v_13_B.Multiply = load_arduino_v_13_P.h_ref_Y0;

    /* SystemInitialize for Outport: '<S793>/flare_data' */
    load_arduino_v_13_B.x_f_out = load_arduino_v_13_P.flare_data_Y0;
    load_arduino_v_13_B.h_f_out = load_arduino_v_13_P.flare_data_Y0;
    load_arduino_v_13_B.k_x_out = load_arduino_v_13_P.flare_data_Y0;
    load_arduino_v_13_B.h_c_out = load_arduino_v_13_P.flare_data_Y0;

    /* SystemInitialize for Outport: '<S793>/landing_abort' */
    load_arduino_v_13_B.no_solution = load_arduino_v_13_P.landing_abort_Y0;

    /* End of SystemInitialize for SubSystem: '<S782>/APPROACH' */

    /* SystemInitialize for Enabled SubSystem: '<S782>/FLARE' */
    /* SystemInitialize for Outport: '<S797>/h_ref' */
    load_arduino_v_13_B.Sum2 = load_arduino_v_13_P.h_ref_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S782>/FLARE' */

    /* SystemInitialize for Enabled SubSystem: '<S782>/INSEGUIMENTO CENTRO PISTA' */
    /* InitializeConditions for DiscreteIntegrator: '<S870>/Integrator' */
    load_arduino_v_13_DW.Integrator_DSTATE_h =
      load_arduino_v_13_P.PIDController_InitialConditionF;

    /* SystemInitialize for Outport: '<S798>/psi_ref_landing' */
    load_arduino_v_13_B.Gain_p = load_arduino_v_13_P.psi_ref_landing_Y0;

    /* End of SystemInitialize for SubSystem: '<S782>/INSEGUIMENTO CENTRO PISTA' */

    /* SystemInitialize for Outport: '<S782>/QUOTA_AL' */
    load_arduino_v_13_B.QUOTA_m = load_arduino_v_13_P.QUOTA_AL_Y0;

    /* SystemInitialize for Outport: '<S782>/ROTTA_AL' */
    load_arduino_v_13_B.Switch1 = load_arduino_v_13_P.ROTTA_AL_Y0;

    /* SystemInitialize for Outport: '<S782>/H_LAT' */
    load_arduino_v_13_B.Gain = load_arduino_v_13_P.H_LAT_Y0;

    /* SystemInitialize for Outport: '<S782>/H_LONG' */
    load_arduino_v_13_B.Gain_g = load_arduino_v_13_P.H_LONG_Y0;

    /* SystemInitialize for Outport: '<S782>/H_ALT' */
    load_arduino_v_13_B.h_Home = load_arduino_v_13_P.H_ALT_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem2' */
    /* InitializeConditions for Memory: '<S783>/Memory4' */
    load_arduino_v_13_DW.Memory4_PreviousInput =
      load_arduino_v_13_P.Memory4_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S783>/WAYPOINTS' */
    load_arduino_v_13_DW.flag_n = 0.0;
    load_arduino_v_13_DW.lat1 = 0.0;
    load_arduino_v_13_DW.long1 = 0.0;

    /* SystemInitialize for Outport: '<S783>/Out3' */
    load_arduino_v_13_B.QUOTA = load_arduino_v_13_P.Out3_Y0_j;

    /* SystemInitialize for Outport: '<S783>/Out4' */
    load_arduino_v_13_B.ROTTA = load_arduino_v_13_P.Out4_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem' */
    /* InitializeConditions for Memory: '<S781>/Memory' */
    load_arduino_v_13_DW.Memory_PreviousInput_b =
      load_arduino_v_13_P.Memory_InitialCondition_j;

    /* InitializeConditions for Memory: '<S781>/Memory1' */
    load_arduino_v_13_DW.Memory1_PreviousInput_h =
      load_arduino_v_13_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<S781>/Memory3' */
    load_arduino_v_13_DW.Memory3_PreviousInput =
      load_arduino_v_13_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S781>/Memory6' */
    load_arduino_v_13_DW.Memory6_PreviousInput =
      load_arduino_v_13_P.Memory6_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S781>/VETTORIALE' */
    load_arduino_v_13_DW.ALT_ref = 0.0;
    load_arduino_v_13_DW.HDG_ref = 0.0;

    /* SystemInitialize for Outport: '<S781>/Out2' */
    load_arduino_v_13_B.h_vett = load_arduino_v_13_P.Out2_Y0;

    /* SystemInitialize for Outport: '<S781>/Out3' */
    load_arduino_v_13_B.rotta_vett = load_arduino_v_13_P.Out3_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem3' */
    /* SystemInitialize for MATLAB Function: '<S784>/GO_HOME' */
    load_arduino_v_13_DW.flag = 0.0;

    /* SystemInitialize for Outport: '<S784>/Out2' */
    load_arduino_v_13_B.h_goHome = load_arduino_v_13_P.Out2_Y0_c;

    /* SystemInitialize for Outport: '<S784>/Out4' */
    load_arduino_v_13_B.rotta_goHome = load_arduino_v_13_P.Out4_Y0_c;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem3' */

    /* SystemInitialize for MATLAB Function: '<S963>/MATLAB Function' */
    load_arduino_v_13_DW.P_ref = 101325.0;
    load_arduino_v_13_DW.rl_up = 300.0;
    load_arduino_v_13_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S15>/Chart' */
    load_arduino_v_13_DW.is_active_c9_load_arduino_v_13 = 0U;
    load_arduino_v_13_DW.i = 0U;

    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
    load_arduino_v_13_DW.is_active_c23_load_arduino_v_13 = 0U;
    load_arduino_v_13_DW.is_c23_load_arduino_v_13 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S964>/Subsystem2' */
    /* SystemInitialize for MATLAB Function: '<S976>/Create_message' */
    load_arduino_v_13_DW.end_found = false;
    load_arduino_v_13_DW.start_found = false;
    load_arduino_v_13_DW.counter_a = 0U;
    memset(&load_arduino_v_13_DW.message[0], 0, 80U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S976>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S978>/Memory' */
      load_arduino_v_13_DW.Memory_PreviousInput_l[i] =
        load_arduino_v_13_P.Memory_InitialCondition_ab;

      /* SystemInitialize for Outport: '<S978>/Outport' */
      load_arduino_v_13_B.ComplextoRealImag[i] = load_arduino_v_13_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S978>/mario' */
    load_arduino_v_13_B.indice_dimario = load_arduino_v_13_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S976>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S964>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S964>/Subsystem1' */
    /* SystemInitialize for Outport: '<S975>/h_to_subtract' */
    load_arduino_v_13_B.Switch = load_arduino_v_13_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S964>/Subsystem1' */

    /* SystemInitialize for Resettable SubSystem: '<S750>/Resettable Subsystem' */
    lo_ResettableSubsystem_Init(&load_arduino_v_13_DW.ResettableSubsystem,
      &load_arduino_v_13_P.ResettableSubsystem);

    /* End of SystemInitialize for SubSystem: '<S750>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S750>/Enabled Subsystem' */
    load__EnabledSubsystem_Init(&Switch_a, &load_arduino_v_13_P.EnabledSubsystem);

    /* End of SystemInitialize for SubSystem: '<S750>/Enabled Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S752>/MATLAB Function1' */
    load_arduino_v_13_DW.Tf_not_empty = false;
  }
}

/* Model terminate function */
void load_arduino_v_13_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S963>/One_time_initialization' */
  One_time_initializatio_Term(&load_arduino_v_13_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S963>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S963>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S968>/I2C Read12' */
  matlabCodegenHandle_matlab_js1p(&load_arduino_v_13_DW.obj_f);

  /* Terminate for MATLABSystem: '<S968>/I2C Read1' */
  matlabCodegenHandle_matlab_js1p(&load_arduino_v_13_DW.obj_p);

  /* End of Terminate for SubSystem: '<S963>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S941>/Digital Output' */
  matlabCodegenHandle_matlabCo_js(&load_arduino_v_13_DW.obj_c);

  /* Terminate for MATLABSystem: '<S942>/Digital Output' */
  matlabCodegenHandle_matlabCo_js(&load_arduino_v_13_DW.obj_l);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
