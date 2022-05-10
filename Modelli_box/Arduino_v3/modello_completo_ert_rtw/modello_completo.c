/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: modello_completo.c
 *
 * Code generated for Simulink model 'modello_completo'.
 *
 * Model version                  : 5.45
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May  4 15:32:50 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modello_completo.h"
#include "modello_completo_private.h"

/* Named constants for Chart: '<S40>/SELEZIONE MODALITA\'  HOLD//SELECT' */
#define modello_completo_IN_Hold       ((uint8_T)1U)
#define modello_completo_IN_Select     ((uint8_T)2U)

/* Named constants for Chart: '<S38>/ STATI' */
#define model_IN_ATTERRAGGIO_AUTOMATICO ((uint8_T)1U)
#define modello_c_IN_DECOLLO_AUTOMATICO ((uint8_T)2U)
#define modello_co_IN_Intervento_Pilota ((uint8_T)3U)
#define modello_completo_IN_AUTOMATICA ((uint8_T)1U)
#define modello_completo_IN_Go_Home    ((uint8_T)2U)
#define modello_completo_IN_MANUALE    ((uint8_T)4U)
#define modello_completo_IN_Safe       ((uint8_T)5U)
#define modello_completo_IN_Stand_By   ((uint8_T)6U)
#define modello_completo_IN_TEST       ((uint8_T)3U)
#define modello_completo_IN_VETTORIALE ((uint8_T)4U)
#define modello_completo_IN_WAYPOINT   ((uint8_T)5U)

/* Named constants for Chart: '<S39>/Chart' */
#define modello_completo_IN_AutoLanding ((uint8_T)1U)
#define modello_completo_IN_AutoTakeoff ((uint8_T)2U)
#define modello_completo_IN_GoHome     ((uint8_T)3U)
#define modello_completo_IN_In         ((uint8_T)4U)
#define modello_completo_IN_Vettoriale ((uint8_T)5U)
#define modello_completo_IN_Waypoint   ((uint8_T)6U)

/* Named constants for Chart: '<S438>/Chart1' */
#define modello_completo_IN_Fase_0_ATO ((uint8_T)1U)
#define modello_completo_IN_Fase_1_ATO ((uint8_T)2U)
#define modello_completo_IN_Fase_2_ATO ((uint8_T)3U)
#define modello_completo_IN_Fase_3_ATO ((uint8_T)4U)
#define modello_completo_IN_Fase_4_ATO ((uint8_T)5U)

/* Named constants for Chart: '<S440>/Chart1' */
#define modello_completo_IN_Abort      ((uint8_T)1U)
#define modello_completo_IN_Allignment ((uint8_T)2U)
#define modello_completo_IN_Allignment1 ((uint8_T)3U)
#define modello_completo_IN_Approach   ((uint8_T)4U)
#define modello_completo_IN_Flare      ((uint8_T)5U)

const uint16_T modello_completo_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_modello_completo_T modello_completo_B;

/* Block states (default storage) */
DW_modello_completo_T modello_completo_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_modello_completo_T modello_completo_PrevZCX;

/* Real-time model */
static RT_MODEL_modello_completo_T modello_completo_M_;
RT_MODEL_modello_completo_T *const modello_completo_M = &modello_completo_M_;

/* Forward declaration for local functions */
static void modello_completo_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter);
static boolean_T modello_completo_ifWhileCond(const boolean_T x[100]);
static void modello_completo_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void modello_completo_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void modello_completo_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T modello_completo_ifWhileCond_o(const boolean_T x[5]);
static void modello_completo_eml_find_o(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void modello_completo_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T modello_completo_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T modello_completo_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k);
static void modello_completo_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T modello_completo_str2double(const char_T s[2]);
static boolean_T modello_completo_copydigits_k(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void modello_completo_readfloat_d(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T modello_completo_str2double_l(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T modello_completo_isUnitImag(const char_T s[3], int32_T k);
static void modello_complet_readNonFinite_l(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T modello_completo_copydigits_k3(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T modello_completo_copyexponent_k(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void modello_completo_readfloat_dt(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T modello_completo_str2double_lv(const char_T s[3]);
static void modello_comple_readNonFinite_ln(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T modello_completo_copydigits_k3z(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T modello_complet_copyexponent_kd(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void modello_completo_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T modello_completo_str2double_lvk(char_T s);
static real_T modello_completo_hex2dec(const char_T s[2]);
static void rate_monotonic_scheduler(void);
real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T borrow = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0U ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
  }
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0U;
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T carry = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T i;
  int32_T nm;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0U;
    }
  }
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T nb;
  int32_T nc;
  uint32_T nl;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void modello_completo_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(modello_completo_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(modello_completo_M, 2));
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
  (modello_completo_M->Timing.TaskCounters.TID[1])++;
  if ((modello_completo_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    modello_completo_M->Timing.TaskCounters.TID[1] = 0;
  }

  (modello_completo_M->Timing.TaskCounters.TID[2])++;
  if ((modello_completo_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.1s, 0.0s] */
    modello_completo_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S408>/Enabled Subsystem'
 *    '<S409>/Enabled Subsystem'
 */
void model_EnabledSubsystem_Init(real_T *rty_u0, P_EnabledSubsystem_modello_co_T
  *localP)
{
  /* SystemInitialize for Outport: '<S417>/1//0' */
  *rty_u0 = localP->u0_Y0;
}

/*
 * Output and update for enable system:
 *    '<S408>/Enabled Subsystem'
 *    '<S409>/Enabled Subsystem'
 */
void modello_co_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0, P_EnabledSubsystem_modello_co_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S408>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S417>/Enable'
   */
  if (rtu_Enable > 0) {
    /* Switch: '<S417>/Switch' incorporates:
     *  Constant: '<S417>/Constant1'
     *  Constant: '<S417>/Constant2'
     */
    if (rtu_Time > localP->Switch_Threshold) {
      *rty_u0 = localP->Constant1_Value;
    } else {
      *rty_u0 = localP->Constant2_Value;
    }

    /* End of Switch: '<S417>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S408>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S408>/Resettable Subsystem'
 *    '<S409>/Resettable Subsystem'
 */
void mo_ResettableSubsystem_Init(DW_ResettableSubsystem_modell_T *localDW,
  P_ResettableSubsystem_modello_T *localP)
{
  /* InitializeConditions for Memory: '<S419>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * System reset for atomic system:
 *    '<S408>/Resettable Subsystem'
 *    '<S409>/Resettable Subsystem'
 */
void m_ResettableSubsystem_Reset(DW_ResettableSubsystem_modell_T *localDW,
  P_ResettableSubsystem_modello_T *localP)
{
  /* InitializeConditions for Memory: '<S419>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S408>/Resettable Subsystem'
 *    '<S409>/Resettable Subsystem'
 */
real_T modello_ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_modell_T *localDW, P_ResettableSubsystem_modello_T
  *localP, ZCE_ResettableSubsystem_model_T *localZCE)
{
  real_T rty_Time_0;

  /* Outputs for Resettable SubSystem: '<S408>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S418>/Reset'
   */
  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_f != POS_ZCSIG))
  {
    m_ResettableSubsystem_Reset(localDW, localP);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_f = (ZCSigState)(rtu_Reset > 0);

  /* Sum: '<S419>/Sum' incorporates:
   *  Constant: '<S419>/Constant4'
   *  Memory: '<S419>/Memory'
   */
  rty_Time_0 = modello_completo_P.t_AP + localDW->Memory_PreviousInput;

  /* Update for Memory: '<S419>/Memory' */
  localDW->Memory_PreviousInput = rty_Time_0;

  /* End of Outputs for SubSystem: '<S408>/Resettable Subsystem' */
  return rty_Time_0;
}

/* System initialize for enable system: '<S567>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_mod_T *localB,
  DW_One_time_initialization_mo_T *localDW, P_One_time_initialization_mod_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S574>/I2C Read' */
  localDW->obj_kf.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_kf;
  localDW->obj_kf.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_kf.isInitialized = 0;
  localDW->obj_kf.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_kf.matlabCodegenIsDeleted = false;
  localDW->obj_kf.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_kf;
  localDW->obj_kf.isSetupComplete = false;
  localDW->obj_kf.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_kf.BusSpeed = 100000U;
  varargin_1 = localDW->obj_kf.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_kf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read1' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read2' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read3' */
  localDW->obj_k4.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k4;
  localDW->obj_k4.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k4.isInitialized = 0;
  localDW->obj_k4.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k4.matlabCodegenIsDeleted = false;
  localDW->obj_k4.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_k4;
  localDW->obj_k4.isSetupComplete = false;
  localDW->obj_k4.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k4.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k4.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k4.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read4' */
  localDW->obj_co.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_co;
  localDW->obj_co.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_co.isInitialized = 0;
  localDW->obj_co.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_co.matlabCodegenIsDeleted = false;
  localDW->obj_co.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_co;
  localDW->obj_co.isSetupComplete = false;
  localDW->obj_co.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_co.BusSpeed = 100000U;
  varargin_1 = localDW->obj_co.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_co.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read5' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read6' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read7' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read8' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read10' */
  localDW->obj_d0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d0;
  localDW->obj_d0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d0.isInitialized = 0;
  localDW->obj_d0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d0.matlabCodegenIsDeleted = false;
  localDW->obj_d0.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_d0;
  localDW->obj_d0.isSetupComplete = false;
  localDW->obj_d0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read11' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = modello_completo_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Write1' */
  localDW->obj_j.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_j;
  localDW->obj_j.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_j.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_j.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_j;
  localDW->obj_j.isSetupComplete = false;
  localDW->obj_j.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_j.BusSpeed = 100000U;
  varargin_1 = localDW->obj_j.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Write2' */
  localDW->obj_in.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_in;
  localDW->obj_in.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_in.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_in.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_in;
  localDW->obj_in.isSetupComplete = false;
  localDW->obj_in.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_in.BusSpeed = 100000U;
  varargin_1 = localDW->obj_in.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_in.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Write3' */
  localDW->obj_d01.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_d01;
  localDW->obj_d01.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d01.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d01.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_d01;
  localDW->obj_d01.isSetupComplete = false;
  localDW->obj_d01.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d01.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d01.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d01.isSetupComplete = true;

  /* Start for MATLABSystem: '<S574>/I2C Read12' */
  localDW->obj_ir.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ir;
  localDW->obj_ir.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ir.isInitialized = 0;
  localDW->obj_ir.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ir.matlabCodegenIsDeleted = false;
  localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_ir;
  localDW->obj_ir.isSetupComplete = false;
  localDW->obj_ir.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ir.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ir.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ir.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read' incorporates:
   *  Outport: '<S574>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read1' incorporates:
   *  Outport: '<S574>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read2' incorporates:
   *  Outport: '<S574>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read3' incorporates:
   *  Outport: '<S574>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read4' incorporates:
   *  Outport: '<S574>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read5' incorporates:
   *  Outport: '<S574>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read6' incorporates:
   *  Outport: '<S574>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read7' incorporates:
   *  Outport: '<S574>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read8' incorporates:
   *  Outport: '<S574>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read9' incorporates:
   *  Outport: '<S574>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read10' incorporates:
   *  Outport: '<S574>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S574>/I2C Read11' incorporates:
   *  Outport: '<S574>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S574>/Byte Unpack' incorporates:
     *  Outport: '<S574>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S567>/One_time_initialization' */
void mod_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_mod_T *localB, DW_One_time_initialization_mo_T
  *localDW, P_One_time_initialization_mod_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S567>/One_time_initialization' incorporates:
   *  EnablePort: '<S574>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S574>/I2C Write3' incorporates:
     *  ArithShift: '<S574>/Shift Arithmetic1'
     *  Constant: '<S574>/registro memoria2 '
     *  DataTypeConversion: '<S574>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S574>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S574>/I2C Read' */
    if (localDW->obj_kf.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_kf.SampleTime = modello_completo_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_kf.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_kf.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S574>/I2C Read' */

    /* MATLABSystem: '<S574>/I2C Read1' */
    if (localDW->obj_o.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_o.SampleTime = modello_completo_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read1' */

    /* MATLABSystem: '<S574>/I2C Read2' */
    if (localDW->obj_d.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_d.SampleTime = modello_completo_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read2' */

    /* MATLABSystem: '<S574>/I2C Read3' */
    if (localDW->obj_k4.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_k4.SampleTime = modello_completo_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_k4.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_k4.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S574>/I2C Read3' */

    /* MATLABSystem: '<S574>/I2C Read4' */
    if (localDW->obj_co.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_co.SampleTime = modello_completo_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_co.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_co.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read4' */

    /* MATLABSystem: '<S574>/I2C Read5' */
    if (localDW->obj_k.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_k.SampleTime = modello_completo_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read5' */

    /* MATLABSystem: '<S574>/I2C Read6' */
    if (localDW->obj_b.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_b.SampleTime = modello_completo_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read6' */

    /* MATLABSystem: '<S574>/I2C Read7' */
    if (localDW->obj_c.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_c.SampleTime = modello_completo_P.t_AP;
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
      /* MATLABSystem: '<S574>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read7' */

    /* MATLABSystem: '<S574>/I2C Read8' */
    if (localDW->obj_i.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_i.SampleTime = modello_completo_P.t_AP;
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
      /* MATLABSystem: '<S574>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read8' */

    /* MATLABSystem: '<S574>/I2C Read9' */
    if (localDW->obj.SampleTime != modello_completo_P.t_AP) {
      localDW->obj.SampleTime = modello_completo_P.t_AP;
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
      /* MATLABSystem: '<S574>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read9' */

    /* MATLABSystem: '<S574>/I2C Read10' */
    if (localDW->obj_d0.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_d0.SampleTime = modello_completo_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_d0.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_d0.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read10' */

    /* MATLABSystem: '<S574>/I2C Read11' */
    if (localDW->obj_l.SampleTime != modello_completo_P.t_AP) {
      localDW->obj_l.SampleTime = modello_completo_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S574>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S574>/I2C Read11' */

    /* MATLABSystem: '<S574>/I2C Write1' incorporates:
     *  Constant: '<S574>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S574>/I2C Write2' incorporates:
     *  Constant: '<S574>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_in.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S574>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_d01.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S574>/I2C Read12' */
    if (localDW->obj_ir.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_ir.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S574>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S574>/Byte Unpack' */

    /* Unpack: <S574>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S567>/One_time_initialization' */
}

/* Termination for enable system: '<S567>/One_time_initialization' */
void One_time_initializatio_Term(DW_One_time_initialization_mo_T *localDW)
{
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S574>/I2C Read' */
  obj = &localDW->obj_kf;
  if (!localDW->obj_kf.matlabCodegenIsDeleted) {
    localDW->obj_kf.matlabCodegenIsDeleted = true;
    if ((localDW->obj_kf.isInitialized == 1) && localDW->obj_kf.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read1' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read2' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read3' */
  obj = &localDW->obj_k4;
  if (!localDW->obj_k4.matlabCodegenIsDeleted) {
    localDW->obj_k4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k4.isInitialized == 1) && localDW->obj_k4.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read4' */
  obj = &localDW->obj_co;
  if (!localDW->obj_co.matlabCodegenIsDeleted) {
    localDW->obj_co.matlabCodegenIsDeleted = true;
    if ((localDW->obj_co.isInitialized == 1) && localDW->obj_co.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read5' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read6' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read7' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read8' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read10' */
  obj = &localDW->obj_d0;
  if (!localDW->obj_d0.matlabCodegenIsDeleted) {
    localDW->obj_d0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d0.isInitialized == 1) && localDW->obj_d0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read11' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S574>/I2C Write1' */
  obj_0 = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S574>/I2C Write2' */
  obj_0 = &localDW->obj_in;
  if (!localDW->obj_in.matlabCodegenIsDeleted) {
    localDW->obj_in.matlabCodegenIsDeleted = true;
    if ((localDW->obj_in.isInitialized == 1) && localDW->obj_in.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S574>/I2C Write3' */
  obj_0 = &localDW->obj_d01;
  if (!localDW->obj_d01.matlabCodegenIsDeleted) {
    localDW->obj_d01.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d01.isInitialized == 1) &&
        localDW->obj_d01.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S574>/I2C Read12' */
  obj = &localDW->obj_ir;
  if (!localDW->obj_ir.matlabCodegenIsDeleted) {
    localDW->obj_ir.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ir.isInitialized == 1) && localDW->obj_ir.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S574>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void modello_completo_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter)
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
static boolean_T modello_completo_ifWhileCond(const boolean_T x[100])
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

/* Function for Chart: '<S39>/Chart' */
static void modello_completo_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (modello_completo_B.modo == 5.0)) {
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (modello_completo_B.modo == 2.0)) {
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (modello_completo_B.modo == 4.0)) {
    modello_completo_DW.is_c21_modello_completo =
      modello_completo_IN_AutoLanding;
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

/* Function for Chart: '<S39>/Chart' */
static void modello_completo_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (modello_completo_B.modo == 1.0)) {
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (modello_completo_B.modo == 2.0)) {
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (modello_completo_B.modo == 5.0)) {
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if ((*Ap_sel) && (modello_completo_B.modo == 4.0)) {
    modello_completo_DW.is_c21_modello_completo =
      modello_completo_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (modello_completo_B.modo == 3.0)) {
    modello_completo_DW.is_c21_modello_completo =
      modello_completo_IN_AutoTakeoff;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 1.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else {
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
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
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 80)) {
    if (x[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }

  if (idx == 0) {
    i_size[0] = 1;
    i_size[1] = 0;
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_ifWhileCond_o(const boolean_T x[5])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
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

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_eml_find_o(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 80)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 80) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv)
{
  int32_T ksaved;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= 2) && (s[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= 2) {
    c_idx_0 = s[*k - 1];
  }

  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= 2) && (s[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= 2) {
    c_idx_1 = s[*k - 1];
  }

  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= 2) && (s[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= 2) {
    c_idx_2 = s[*k - 1];
  }

  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
        'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    *b_finite = false;
    *fv = (rtInf);
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
              (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    *b_finite = false;
    *fv = (rtNaN);
  } else {
    *b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint)
{
  char_T tmp;
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= 2);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= 2))) {
    tmp = s[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      success = (allowpoint && (!haspoint));
      if (success) {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }

      (*k)++;
    } else if (tmp == ',') {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k)
{
  int32_T b_k;
  char_T tmp;
  boolean_T b_success;
  boolean_T success;
  success = true;
  if (*k <= 2) {
    tmp = s[*k - 1];
    if ((tmp == 'E') || (tmp == 'e')) {
      s1[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      while ((*k <= 2) && (s[1] == ',')) {
        *k = 3;
      }

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

      modello_completo_B.kexp_f = *k;
      b_k = *k;
      b_success = modello_completo_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > modello_completo_B.kexp_f));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success)
{
  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  int32_T b_idx;
  int32_T b_k;
  int32_T entryg2;
  int32_T exitg3;
  char_T tmp;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T isneg;
  boolean_T unusedU2;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_k = *k;
  b_idx = *idx;
  isneg = false;
  *foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (b_k <= 2)) {
    tmp = s[b_k - 1];
    if (tmp == '-') {
      isneg = !isneg;
      *foundsign = true;
      b_k++;
    } else if (tmp == ',') {
      b_k++;
    } else if (tmp == '+') {
      *foundsign = true;
      b_k++;
    } else if (!b[(uint8_T)tmp & 127]) {
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  *success = (b_k <= 2);
  if ((*success) && isneg) {
    if ((*idx >= 2) && (s1[*idx - 2] == '-')) {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      b_idx = *idx + 1;
    }
  }

  *idx = b_idx;
  *k = b_k;
  if (*success) {
    guard1 = false;
    if (b_k <= 2) {
      tmp = s[b_k - 1];
      if ((tmp == 'j') || (tmp == 'i')) {
        if (allowimag) {
          *isimag = true;
          *k = b_k + 1;
          exitg1 = false;
          while ((!exitg1) && (*k <= 2)) {
            if (b[(uint8_T)s[*k - 1] & 127]) {
              (*k)++;
            } else {
              tmp = s[*k - 1];
              if ((tmp == '\x00') || (tmp == ',')) {
                (*k)++;
              } else {
                exitg1 = true;
              }
            }
          }

          if ((*k <= 2) && (s[*k - 1] == '*')) {
            (*k)++;
            modello_completo_readfloat(s1, idx, s, k, false, &isneg, b_finite,
              nfv, &unusedU2, success);
          } else {
            s1[b_idx - 1] = '1';
            *idx = b_idx + 1;
          }
        } else {
          *success = false;
        }

        entryg2 = 1;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      modello_completo_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = modello_completo_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = modello_completo_copyexponent(s1, idx, s, k);
        }
      } else {
        if ((b_idx >= 2) && (s1[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (*k <= 2)) {
        if (b[(uint8_T)s[*k - 1] & 127]) {
          (*k)++;
        } else {
          tmp = s[*k - 1];
          if ((tmp == '\x00') || (tmp == ',')) {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
      }

      if ((*k <= 2) && (s[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= 2) && (b[(uint8_T)s[*k - 1] & 127] || (s[*k - 1] == '\x00')
                             || (s[*k - 1] == ','))) {
          (*k)++;
        }
      }

      if (*k <= 2) {
        tmp = s[*k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          (*k)++;
          *isimag = true;
        }
      }

      entryg2 = 0;
    }

    do {
      exitg3 = 0;
      if (entryg2 == 0) {
      } else {
        entryg2 = 0;
      }

      if (*k <= 2) {
        tmp = s[*k - 1];
        if (b[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          (*k)++;
        } else {
          exitg3 = 1;
        }
      } else {
        exitg3 = 1;
      }
    } while (exitg3 == 0);
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static creal_T modello_completo_str2double(const char_T s[2])
{
  static const boolean_T c[128] = { false, false, false, false, false, false,
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

  creal_T x;
  char_T tmp;
  boolean_T b_finite;
  boolean_T c_success;
  boolean_T exitg1;
  boolean_T isimag1;
  boolean_T isneg;
  boolean_T success;
  boolean_T unusedU2;
  x.re = (rtNaN);
  x.im = 0.0;
  modello_completo_B.ntoread_j = 0;
  modello_completo_B.k_e = 0;
  while ((modello_completo_B.k_e + 1 <= 2) && (c[(uint8_T)
          s[modello_completo_B.k_e] & 127] || (s[modello_completo_B.k_e] ==
           '\x00'))) {
    modello_completo_B.k_e++;
  }

  isimag1 = false;
  b_finite = true;
  modello_completo_B.scanned1_dh = 0.0;
  modello_completo_B.idx_bj = 1;
  modello_completo_B.s1_l[0] = '\x00';
  modello_completo_B.s1_l[1] = '\x00';
  modello_completo_B.s1_l[2] = '\x00';
  modello_completo_B.s1_l[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (modello_completo_B.k_e + 1 <= 2)) {
    if (s[modello_completo_B.k_e] == '-') {
      isneg = !isneg;
      modello_completo_B.k_e++;
    } else if ((s[modello_completo_B.k_e] == ',') || (s[modello_completo_B.k_e] ==
                '+') || c[(uint8_T)s[modello_completo_B.k_e] & 127]) {
      modello_completo_B.k_e++;
    } else {
      exitg1 = true;
    }
  }

  success = (modello_completo_B.k_e + 1 <= 2);
  if (success && isneg) {
    modello_completo_B.s1_l[0] = '-';
    modello_completo_B.idx_bj = 2;
  }

  modello_completo_B.e_k = modello_completo_B.k_e + 1;
  if (success) {
    if ((modello_completo_B.k_e + 1 <= 2) && ((s[modello_completo_B.k_e] == 'j')
         || (s[modello_completo_B.k_e] == 'i'))) {
      isimag1 = true;
      modello_completo_B.e_k = modello_completo_B.k_e + 2;
      while ((modello_completo_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1] ==
               '\x00') || (s[1] == ','))) {
        modello_completo_B.e_k = 3;
      }

      if ((modello_completo_B.e_k <= 2) && (s[1] == '*')) {
        modello_completo_B.e_k = 3;
        modello_completo_readfloat(modello_completo_B.s1_l,
          &modello_completo_B.idx_bj, s, &modello_completo_B.e_k, false, &isneg,
          &b_finite, &modello_completo_B.scanned1_dh, &unusedU2, &success);
      } else {
        modello_completo_B.s1_l[modello_completo_B.idx_bj - 1] = '1';
        modello_completo_B.idx_bj++;
      }
    } else {
      modello_completo_B.e_k = modello_completo_B.k_e + 1;
      modello_completo_readNonFinite(s, &modello_completo_B.e_k, &b_finite,
        &modello_completo_B.scanned1_dh);
      if (b_finite) {
        success = modello_completo_copydigits(modello_completo_B.s1_l,
          &modello_completo_B.idx_bj, s, &modello_completo_B.e_k, true);
        if (success) {
          success = modello_completo_copyexponent(modello_completo_B.s1_l,
            &modello_completo_B.idx_bj, s, &modello_completo_B.e_k);
        }
      } else {
        if ((modello_completo_B.idx_bj >= 2) && (modello_completo_B.s1_l[0] ==
             '-')) {
          modello_completo_B.idx_bj = 1;
          modello_completo_B.s1_l[0] = ' ';
          modello_completo_B.scanned1_dh = -modello_completo_B.scanned1_dh;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (modello_completo_B.e_k <= 2)) {
        tmp = s[modello_completo_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          modello_completo_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((modello_completo_B.e_k <= 2) && (s[modello_completo_B.e_k - 1] == '*'))
      {
        modello_completo_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (modello_completo_B.e_k <= 2)) {
          tmp = s[modello_completo_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            modello_completo_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (modello_completo_B.e_k <= 2) {
        tmp = s[modello_completo_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          modello_completo_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (modello_completo_B.e_k <= 2)) {
      tmp = s[modello_completo_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        modello_completo_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    modello_completo_B.ntoread_j = 1;
  }

  if (success && (modello_completo_B.e_k <= 2)) {
    modello_completo_B.s1_l[modello_completo_B.idx_bj - 1] = ' ';
    modello_completo_B.idx_bj++;
    modello_completo_readfloat(modello_completo_B.s1_l,
      &modello_completo_B.idx_bj, s, &modello_completo_B.e_k, true, &success,
      &isneg, &modello_completo_B.scanned2_d, &unusedU2, &c_success);
    if (isneg) {
      modello_completo_B.ntoread_j++;
    }

    success = (c_success && (modello_completo_B.e_k > 2) && (isimag1 != success)
               && unusedU2);
  } else {
    modello_completo_B.scanned2_d = 0.0;
  }

  if (success) {
    modello_completo_B.s1_l[modello_completo_B.idx_bj - 1] = '\x00';
    switch (modello_completo_B.ntoread_j) {
     case 2:
      modello_completo_B.ntoread_j = sscanf(&modello_completo_B.s1_l[0],
        "%lf %lf", &modello_completo_B.scanned1_dh,
        &modello_completo_B.scanned2_d);
      if (modello_completo_B.ntoread_j != 2) {
        modello_completo_B.scanned1_dh = (rtNaN);
        modello_completo_B.scanned2_d = (rtNaN);
      }
      break;

     case 1:
      modello_completo_B.ntoread_j = sscanf(&modello_completo_B.s1_l[0], "%lf",
        &modello_completo_B.b_scanned1_lx);
      if (b_finite) {
        if (modello_completo_B.ntoread_j == 1) {
          modello_completo_B.scanned1_dh = modello_completo_B.b_scanned1_lx;
        } else {
          modello_completo_B.scanned1_dh = (rtNaN);
        }
      } else if (modello_completo_B.ntoread_j == 1) {
        modello_completo_B.scanned2_d = modello_completo_B.b_scanned1_lx;
      } else {
        modello_completo_B.scanned2_d = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = modello_completo_B.scanned2_d;
      x.im = modello_completo_B.scanned1_dh;
    } else {
      x.re = modello_completo_B.scanned1_dh;
      x.im = modello_completo_B.scanned2_d;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_copydigits_k(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint)
{
  char_T tmp;
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= n);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= n))) {
    tmp = s_data[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1_data[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      success = (allowpoint && (!haspoint));
      if (success) {
        s1_data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }

      (*k)++;
    } else if (tmp == ',') {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_readfloat_d(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success)
{
  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  int32_T b_idx;
  int32_T b_k;
  int32_T h_k;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  boolean_T exitg1;
  boolean_T isneg;
  boolean_T unusedU2;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_k = *k;
  b_idx = *idx;
  isneg = false;
  *foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (b_k <= n)) {
    c_idx_0 = s_data[b_k - 1];
    if (c_idx_0 == '-') {
      isneg = !isneg;
      *foundsign = true;
      b_k++;
    } else if (c_idx_0 == ',') {
      b_k++;
    } else if (c_idx_0 == '+') {
      *foundsign = true;
      b_k++;
    } else if (!b[(uint8_T)c_idx_0 & 127]) {
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  *success = (b_k <= n);
  if ((*success) && isneg) {
    if ((*idx >= 2) && (s1_data[*idx - 2] == '-')) {
      s1_data[*idx - 2] = ' ';
    } else {
      s1_data[*idx - 1] = '-';
      b_idx = *idx + 1;
    }
  }

  *idx = b_idx;
  *k = b_k;
  if (*success) {
    isneg = false;
    if (b_k <= n) {
      c_idx_0 = s_data[b_k - 1];
      if (c_idx_0 == 'j') {
        isneg = true;
      } else {
        if (c_idx_0 == 'i') {
          if (b_k >= n - 1) {
            isneg = true;
          } else {
            h_k = b_k;
            c_idx_0 = '\x00';
            while ((h_k <= n) && (s_data[h_k - 1] == ',')) {
              h_k++;
            }

            if (h_k <= n) {
              c_idx_0 = s_data[h_k - 1];
            }

            h_k++;
            c_idx_1 = '\x00';
            while ((h_k <= n) && (s_data[h_k - 1] == ',')) {
              h_k++;
            }

            if (h_k <= n) {
              c_idx_1 = s_data[h_k - 1];
            }

            h_k++;
            c_idx_2 = '\x00';
            while ((h_k <= n) && (s_data[h_k - 1] == ',')) {
              h_k++;
            }

            if (h_k <= n) {
              c_idx_2 = s_data[h_k - 1];
            }

            if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                 (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
            } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
              if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
                if ((!(c_idx_2 == 'N')) && (!(c_idx_2 == 'n'))) {
                  isneg = true;
                }
              } else {
                isneg = true;
              }
            } else {
              isneg = true;
            }
          }
        }
      }
    }

    if (isneg) {
      if (allowimag) {
        *isimag = true;
        *k = b_k + 1;
        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
          if (b[(uint8_T)s_data[*k - 1] & 127]) {
            (*k)++;
          } else {
            c_idx_0 = s_data[*k - 1];
            if ((c_idx_0 == '\x00') || (c_idx_0 == ',')) {
              (*k)++;
            } else {
              exitg1 = true;
            }
          }
        }

        if ((*k <= n) && (s_data[*k - 1] == '*')) {
          (*k)++;
          modello_completo_readfloat_d(s1_data, idx, s_data, k, n, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1_data[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      h_k = b_k;
      c_idx_0 = '\x00';
      while ((h_k <= n) && (s_data[h_k - 1] == ',')) {
        h_k++;
      }

      if (h_k <= n) {
        c_idx_0 = s_data[h_k - 1];
      }

      h_k++;
      c_idx_1 = '\x00';
      while ((h_k <= n) && (s_data[h_k - 1] == ',')) {
        h_k++;
      }

      if (h_k <= n) {
        c_idx_1 = s_data[h_k - 1];
      }

      h_k++;
      c_idx_2 = '\x00';
      while ((h_k <= n) && (s_data[h_k - 1] == ',')) {
        h_k++;
      }

      if (h_k <= n) {
        c_idx_2 = s_data[h_k - 1];
      }

      h_k++;
      if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
           (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
        *b_finite = false;
        *nfv = (rtInf);
      } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                  (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
        *b_finite = false;
        *nfv = (rtNaN);
      } else {
        *b_finite = true;
        *nfv = 0.0;
        h_k = b_k;
      }

      *k = h_k;
      if (*b_finite) {
        *success = modello_completo_copydigits_k(s1_data, &b_idx, s_data, &h_k,
          n, true);
        *idx = b_idx;
        *k = h_k;
        if (*success) {
          *success = true;
          if (h_k <= n) {
            c_idx_0 = s_data[h_k - 1];
            if ((c_idx_0 == 'E') || (c_idx_0 == 'e')) {
              s1_data[b_idx - 1] = 'e';
              b_k = h_k + 1;
              while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
                b_k++;
              }

              if (b_k <= n) {
                c_idx_0 = s_data[b_k - 1];
                if (c_idx_0 == '-') {
                  s1_data[b_idx] = '-';
                  b_idx++;
                  b_k++;
                } else {
                  if (c_idx_0 == '+') {
                    b_k++;
                  }
                }
              }

              *idx = b_idx + 1;
              b_idx = b_k;
              isneg = modello_completo_copydigits_k(s1_data, idx, s_data, &b_idx,
                n, false);
              *k = b_idx;
              *success = (isneg && (b_idx > b_k));
            }
          }
        }
      } else {
        if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1_data[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (*k <= n)) {
        if (b[(uint8_T)s_data[*k - 1] & 127]) {
          (*k)++;
        } else {
          c_idx_0 = s_data[*k - 1];
          if ((c_idx_0 == '\x00') || (c_idx_0 == ',')) {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
      }

      if ((*k <= n) && (s_data[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= n) && (b[(uint8_T)s_data[*k - 1] & 127] || (s_data[*k - 1]
                 == '\x00') || (s_data[*k - 1] == ','))) {
          (*k)++;
        }
      }

      if (*k <= n) {
        c_idx_0 = s_data[*k - 1];
        if ((c_idx_0 == 'i') || (c_idx_0 == 'j')) {
          (*k)++;
          *isimag = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (*k <= n)) {
      c_idx_0 = s_data[*k - 1];
      if (b[(uint8_T)c_idx_0 & 127] || (c_idx_0 == '\x00') || (c_idx_0 == ','))
      {
        (*k)++;
      } else {
        exitg1 = true;
      }
    }
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static creal_T modello_completo_str2double_l(const char_T s_data[], const
  int32_T s_size[2])
{
  static const boolean_T c[128] = { false, false, false, false, false, false,
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

  creal_T x;
  char_T tmp;
  boolean_T c_success;
  boolean_T exitg1;
  boolean_T foundsign;
  boolean_T isfinite1;
  boolean_T isimag1;
  boolean_T success;
  boolean_T unusedU0;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s_size[1] >= 1) {
    modello_completo_B.ntoread = 0;
    modello_completo_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (modello_completo_B.k <= s_size[1])) {
      tmp = s_data[modello_completo_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        modello_completo_B.k++;
      } else {
        exitg1 = true;
      }
    }

    modello_completo_B.s1_size[0] = 1;
    modello_completo_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    modello_completo_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= modello_completo_B.idx) {
      memset(&modello_completo_B.s1_data[0], 0, (modello_completo_B.idx + 1) *
             sizeof(char_T));
    }

    modello_completo_B.idx = 1;
    modello_completo_readfloat_d(modello_completo_B.s1_data,
      &modello_completo_B.idx, s_data, &modello_completo_B.k, s_size[1], true,
      &isimag1, &isfinite1, &modello_completo_B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      modello_completo_B.ntoread = 1;
    }

    if (success) {
      if (modello_completo_B.k <= s_size[1]) {
        modello_completo_B.s1_data[modello_completo_B.idx - 1] = ' ';
        modello_completo_B.idx++;
        modello_completo_readfloat_d(modello_completo_B.s1_data,
          &modello_completo_B.idx, s_data, &modello_completo_B.k, s_size[1],
          true, &unusedU0, &success, &modello_completo_B.scanned2, &foundsign,
          &c_success);
        if (success) {
          modello_completo_B.ntoread++;
        }

        success = (c_success && ((modello_completo_B.k > s_size[1]) && ((isimag1
          != unusedU0) && foundsign)));
      } else {
        modello_completo_B.scanned2 = 0.0;
      }
    } else {
      modello_completo_B.scanned2 = 0.0;
    }

    if (success) {
      modello_completo_B.s1_data[modello_completo_B.idx - 1] = '\x00';
      switch (modello_completo_B.ntoread) {
       case 2:
        modello_completo_B.ntoread = sscanf(&modello_completo_B.s1_data[0],
          "%lf %lf", &modello_completo_B.scanned1, &modello_completo_B.scanned2);
        if (modello_completo_B.ntoread != 2) {
          modello_completo_B.scanned1 = (rtNaN);
          modello_completo_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        modello_completo_B.ntoread = sscanf(&modello_completo_B.s1_data[0],
          "%lf", &modello_completo_B.b_scanned1);
        if (isfinite1) {
          if (modello_completo_B.ntoread == 1) {
            modello_completo_B.scanned1 = modello_completo_B.b_scanned1;
          } else {
            modello_completo_B.scanned1 = (rtNaN);
          }
        } else if (modello_completo_B.ntoread == 1) {
          modello_completo_B.scanned2 = modello_completo_B.b_scanned1;
        } else {
          modello_completo_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = modello_completo_B.scanned2;
        x.im = modello_completo_B.scanned1;
      } else {
        x.re = modello_completo_B.scanned1;
        x.im = modello_completo_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_isUnitImag(const char_T s[3], int32_T k)
{
  int32_T b_k;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  boolean_T p;
  p = false;
  if (k <= 3) {
    c_idx_0 = s[k - 1];
    if (c_idx_0 == 'j') {
      p = true;
    } else {
      if (c_idx_0 == 'i') {
        if (k >= 2) {
          p = true;
        } else {
          b_k = 1;
          c_idx_0 = '\x00';
          while ((b_k <= 3) && (s[b_k - 1] == ',')) {
            b_k++;
          }

          if (b_k <= 3) {
            c_idx_0 = s[b_k - 1];
          }

          b_k++;
          c_idx_1 = '\x00';
          while ((b_k <= 3) && (s[b_k - 1] == ',')) {
            b_k++;
          }

          if (b_k <= 3) {
            c_idx_1 = s[b_k - 1];
          }

          b_k++;
          c_idx_2 = '\x00';
          while ((b_k <= 3) && (s[2] == ',')) {
            b_k = 4;
          }

          if (b_k <= 3) {
            c_idx_2 = s[2];
          }

          if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
               (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
          } else if ((c_idx_0 == 'N') || (c_idx_0 == 'n')) {
            if ((c_idx_1 == 'A') || (c_idx_1 == 'a')) {
              if ((!(c_idx_2 == 'N')) && (!(c_idx_2 == 'n'))) {
                p = true;
              }
            } else {
              p = true;
            }
          } else {
            p = true;
          }
        }
      }
    }
  }

  return p;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_complet_readNonFinite_l(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv)
{
  int32_T ksaved;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= 3) && (s[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= 3) {
    c_idx_0 = s[*k - 1];
  }

  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= 3) && (s[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= 3) {
    c_idx_1 = s[*k - 1];
  }

  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= 3) && (s[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= 3) {
    c_idx_2 = s[*k - 1];
  }

  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
        'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    *b_finite = false;
    *fv = (rtInf);
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
              (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    *b_finite = false;
    *fv = (rtNaN);
  } else {
    *b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_copydigits_k3(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint)
{
  char_T tmp;
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= 3);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= 3))) {
    tmp = s[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      success = (allowpoint && (!haspoint));
      if (success) {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }

      (*k)++;
    } else if (tmp == ',') {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_copyexponent_k(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k)
{
  int32_T b_k;
  char_T tmp;
  boolean_T b_success;
  boolean_T success;
  success = true;
  if (*k <= 3) {
    tmp = s[*k - 1];
    if ((tmp == 'E') || (tmp == 'e')) {
      s1[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      while ((*k <= 3) && (s[*k - 1] == ',')) {
        (*k)++;
      }

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

      modello_completo_B.kexp = *k;
      b_k = *k;
      b_success = modello_completo_copydigits_k3(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > modello_completo_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_readfloat_dt(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success)
{
  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  int32_T b_idx;
  int32_T b_k;
  char_T tmp;
  boolean_T exitg1;
  boolean_T isneg;
  boolean_T unusedU2;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_k = *k;
  b_idx = *idx;
  isneg = false;
  *foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (b_k <= 3)) {
    tmp = s[b_k - 1];
    if (tmp == '-') {
      isneg = !isneg;
      *foundsign = true;
      b_k++;
    } else if (tmp == ',') {
      b_k++;
    } else if (tmp == '+') {
      *foundsign = true;
      b_k++;
    } else if (!b[(uint8_T)tmp & 127]) {
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  *success = (b_k <= 3);
  if ((*success) && isneg) {
    if ((*idx >= 2) && (s1[*idx - 2] == '-')) {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      b_idx = *idx + 1;
    }
  }

  *idx = b_idx;
  *k = b_k;
  if (*success) {
    if (modello_completo_isUnitImag(s, b_k)) {
      if (allowimag) {
        *isimag = true;
        *k = b_k + 1;
        exitg1 = false;
        while ((!exitg1) && (*k <= 3)) {
          if (b[(uint8_T)s[*k - 1] & 127]) {
            (*k)++;
          } else {
            tmp = s[*k - 1];
            if ((tmp == '\x00') || (tmp == ',')) {
              (*k)++;
            } else {
              exitg1 = true;
            }
          }
        }

        if ((*k <= 3) && (s[*k - 1] == '*')) {
          (*k)++;
          modello_completo_readfloat_dt(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      modello_complet_readNonFinite_l(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = modello_completo_copydigits_k3(s1, idx, s, k, true);
        if (*success) {
          *success = modello_completo_copyexponent_k(s1, idx, s, k);
        }
      } else {
        if ((b_idx >= 2) && (s1[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (*k <= 3)) {
        if (b[(uint8_T)s[*k - 1] & 127]) {
          (*k)++;
        } else {
          tmp = s[*k - 1];
          if ((tmp == '\x00') || (tmp == ',')) {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
      }

      if ((*k <= 3) && (s[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= 3) && (b[(uint8_T)s[*k - 1] & 127] || (s[*k - 1] == '\x00')
                             || (s[*k - 1] == ','))) {
          (*k)++;
        }
      }

      if (*k <= 3) {
        tmp = s[*k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          (*k)++;
          *isimag = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (*k <= 3)) {
      tmp = s[*k - 1];
      if (b[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        (*k)++;
      } else {
        exitg1 = true;
      }
    }
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static creal_T modello_completo_str2double_lv(const char_T s[3])
{
  static const boolean_T c[128] = { false, false, false, false, false, false,
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

  creal_T x;
  char_T tmp;
  boolean_T b_finite;
  boolean_T c_success;
  boolean_T exitg1;
  boolean_T isimag1;
  boolean_T isneg;
  boolean_T success;
  boolean_T unusedU2;
  x.re = (rtNaN);
  x.im = 0.0;
  modello_completo_B.ntoread_d = 0;
  modello_completo_B.k_h = 1;
  exitg1 = false;
  while ((!exitg1) && (modello_completo_B.k_h <= 3)) {
    tmp = s[modello_completo_B.k_h - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      modello_completo_B.k_h++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  modello_completo_B.scanned1_d = 0.0;
  modello_completo_B.idx_b = 1;
  for (modello_completo_B.b_k = 0; modello_completo_B.b_k < 5;
       modello_completo_B.b_k++) {
    modello_completo_B.s1[modello_completo_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (modello_completo_B.k_h <= 3)) {
    tmp = s[modello_completo_B.k_h - 1];
    if (tmp == '-') {
      isneg = !isneg;
      modello_completo_B.k_h++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      modello_completo_B.k_h++;
    } else {
      exitg1 = true;
    }
  }

  success = (modello_completo_B.k_h <= 3);
  if (success && isneg) {
    modello_completo_B.s1[0] = '-';
    modello_completo_B.idx_b = 2;
  }

  modello_completo_B.b_k = modello_completo_B.k_h - 1;
  if (success) {
    if (modello_completo_isUnitImag(s, modello_completo_B.k_h)) {
      isimag1 = true;
      modello_completo_B.b_k = modello_completo_B.k_h;
      while ((modello_completo_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[modello_completo_B.b_k] & 127] || (s[modello_completo_B.b_k] ==
               '\x00') || (s[modello_completo_B.b_k] == ','))) {
        modello_completo_B.b_k++;
      }

      if ((modello_completo_B.b_k + 1 <= 3) && (s[modello_completo_B.b_k] == '*'))
      {
        modello_completo_B.k_h = modello_completo_B.b_k + 2;
        modello_completo_readfloat_dt(modello_completo_B.s1,
          &modello_completo_B.idx_b, s, &modello_completo_B.k_h, false, &isneg,
          &b_finite, &modello_completo_B.scanned1_d, &unusedU2, &success);
        modello_completo_B.b_k = modello_completo_B.k_h - 1;
      } else {
        modello_completo_B.s1[modello_completo_B.idx_b - 1] = '1';
        modello_completo_B.idx_b++;
      }
    } else {
      modello_complet_readNonFinite_l(s, &modello_completo_B.k_h, &b_finite,
        &modello_completo_B.scanned1_d);
      modello_completo_B.b_k = modello_completo_B.k_h - 1;
      if (b_finite) {
        success = modello_completo_copydigits_k3(modello_completo_B.s1,
          &modello_completo_B.idx_b, s, &modello_completo_B.k_h, true);
        modello_completo_B.b_k = modello_completo_B.k_h - 1;
        if (success) {
          success = modello_completo_copyexponent_k(modello_completo_B.s1,
            &modello_completo_B.idx_b, s, &modello_completo_B.k_h);
          modello_completo_B.b_k = modello_completo_B.k_h - 1;
        }
      } else {
        if ((modello_completo_B.idx_b >= 2) && (modello_completo_B.s1[0] == '-'))
        {
          modello_completo_B.idx_b = 1;
          modello_completo_B.s1[0] = ' ';
          modello_completo_B.scanned1_d = -modello_completo_B.scanned1_d;
        }
      }

      while ((modello_completo_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[modello_completo_B.b_k] & 127] || (s[modello_completo_B.b_k] ==
               '\x00') || (s[modello_completo_B.b_k] == ','))) {
        modello_completo_B.b_k++;
      }

      if ((modello_completo_B.b_k + 1 <= 3) && (s[modello_completo_B.b_k] == '*'))
      {
        modello_completo_B.b_k++;
        while ((modello_completo_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[modello_completo_B.b_k] & 127] || (s[modello_completo_B.b_k] ==
                 '\x00') || (s[modello_completo_B.b_k] == ','))) {
          modello_completo_B.b_k++;
        }
      }

      if ((modello_completo_B.b_k + 1 <= 3) && ((s[modello_completo_B.b_k] ==
            'i') || (s[modello_completo_B.b_k] == 'j'))) {
        modello_completo_B.b_k++;
        isimag1 = true;
      }
    }

    while ((modello_completo_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[modello_completo_B.b_k] & 127] || (s[modello_completo_B.b_k] ==
             '\x00') || (s[modello_completo_B.b_k] == ','))) {
      modello_completo_B.b_k++;
    }
  }

  if (b_finite) {
    modello_completo_B.ntoread_d = 1;
  }

  if (success && (modello_completo_B.b_k + 1 <= 3)) {
    modello_completo_B.s1[modello_completo_B.idx_b - 1] = ' ';
    modello_completo_B.idx_b++;
    modello_completo_B.k_h = modello_completo_B.b_k + 1;
    modello_completo_readfloat_dt(modello_completo_B.s1,
      &modello_completo_B.idx_b, s, &modello_completo_B.k_h, true, &success,
      &isneg, &modello_completo_B.scanned2_g, &unusedU2, &c_success);
    if (isneg) {
      modello_completo_B.ntoread_d++;
    }

    success = (c_success && (modello_completo_B.k_h > 3) && (isimag1 != success)
               && unusedU2);
  } else {
    modello_completo_B.scanned2_g = 0.0;
  }

  if (success) {
    modello_completo_B.s1[modello_completo_B.idx_b - 1] = '\x00';
    switch (modello_completo_B.ntoread_d) {
     case 2:
      modello_completo_B.ntoread_d = sscanf(&modello_completo_B.s1[0], "%lf %lf",
        &modello_completo_B.scanned1_d, &modello_completo_B.scanned2_g);
      if (modello_completo_B.ntoread_d != 2) {
        modello_completo_B.scanned1_d = (rtNaN);
        modello_completo_B.scanned2_g = (rtNaN);
      }
      break;

     case 1:
      modello_completo_B.ntoread_d = sscanf(&modello_completo_B.s1[0], "%lf",
        &modello_completo_B.b_scanned1_l);
      if (b_finite) {
        if (modello_completo_B.ntoread_d == 1) {
          modello_completo_B.scanned1_d = modello_completo_B.b_scanned1_l;
        } else {
          modello_completo_B.scanned1_d = (rtNaN);
        }
      } else if (modello_completo_B.ntoread_d == 1) {
        modello_completo_B.scanned2_g = modello_completo_B.b_scanned1_l;
      } else {
        modello_completo_B.scanned2_g = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = modello_completo_B.scanned2_g;
      x.im = modello_completo_B.scanned1_d;
    } else {
      x.re = modello_completo_B.scanned1_d;
      x.im = modello_completo_B.scanned2_g;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_comple_readNonFinite_ln(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv)
{
  int32_T ksaved;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= 1) && (s == ',')) {
    *k = 2;
  }

  if (*k <= 1) {
    c_idx_0 = s;
  }

  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= 1) && (s == ',')) {
    *k = 2;
  }

  if (*k <= 1) {
    c_idx_1 = s;
  }

  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= 1) && (s == ',')) {
    *k = 2;
  }

  if (*k <= 1) {
    c_idx_2 = s;
  }

  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
        'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    *b_finite = false;
    *fv = (rtInf);
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
              (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    *b_finite = false;
    *fv = (rtNaN);
  } else {
    *b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_completo_copydigits_k3z(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint)
{
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= 1);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= 1))) {
    if ((s >= '0') && (s <= '9')) {
      s1[*idx - 1] = s;
      (*idx)++;
      *k = 2;
    } else if (s == '.') {
      success = (allowpoint && (!haspoint));
      if (success) {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }

      *k = 2;
    } else if (s == ',') {
      *k = 2;
    } else {
      exitg1 = true;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static boolean_T modello_complet_copyexponent_kd(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k)
{
  int32_T b_k;
  boolean_T b_success;
  boolean_T success;
  success = true;
  if ((*k <= 1) && ((s == 'E') || (s == 'e'))) {
    s1[*idx - 1] = 'e';
    (*idx)++;
    b_k = 2;
    b_success = modello_completo_copydigits_k3z(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static void modello_completo_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success)
{
  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  int32_T b_idx;
  int32_T b_k;
  boolean_T exitg1;
  boolean_T isneg;
  boolean_T unusedU2;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_k = *k;
  b_idx = *idx - 1;
  isneg = false;
  *foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (b_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      *foundsign = true;
      b_k = 2;
    } else if (s == ',') {
      b_k = 2;
    } else if (s == '+') {
      *foundsign = true;
      b_k = 2;
    } else if (!b[(uint8_T)s & 127]) {
      exitg1 = true;
    } else {
      b_k = 2;
    }
  }

  *success = (b_k <= 1);
  if ((*success) && isneg) {
    if (s1[*idx - 2] == '-') {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      b_idx = *idx;
    }
  }

  *idx = b_idx + 1;
  *k = b_k;
  if (*success) {
    isneg = false;
    if (b_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      if (allowimag) {
        *isimag = true;
        *k = b_k + 1;
        while ((*k <= 1) && (b[(uint8_T)s & 127] || ((s == '\x00') || (s == ','))))
        {
          *k = 2;
        }

        if ((*k <= 1) && (s == '*')) {
          *k = 2;
          modello_completo_readfloat_dtp(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      modello_comple_readNonFinite_ln(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = modello_completo_copydigits_k3z(s1, idx, s, k, true);
        if (*success) {
          *success = modello_complet_copyexponent_kd(s1, idx, s, k);
        }
      } else {
        if (s1[b_idx - 1] == '-') {
          *idx = b_idx;
          s1[b_idx - 1] = ' ';
          *nfv = -*nfv;
        }
      }

      while ((*k <= 1) && (b[(uint8_T)s & 127] || ((s == '\x00') || (s == ','))))
      {
        *k = 2;
      }

      if ((*k <= 1) && (s == '*')) {
        *k = 2;
      }

      if ((*k <= 1) && ((s == 'i') || (s == 'j'))) {
        *k = 2;
        *isimag = true;
      }
    }

    while ((*k <= 1) && (b[(uint8_T)s & 127] || ((s == '\x00') || (s == ','))))
    {
      *k = 2;
    }
  }
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static creal_T modello_completo_str2double_lvk(char_T s)
{
  static const boolean_T c[128] = { false, false, false, false, false, false,
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

  creal_T x;
  char_T s1[3];
  boolean_T b_finite;
  boolean_T c_success;
  boolean_T exitg1;
  boolean_T foundsign;
  boolean_T isimag1;
  boolean_T isneg;
  boolean_T success;
  x.re = (rtNaN);
  x.im = 0.0;
  modello_completo_B.ntoread_ju = 0;
  modello_completo_B.d_k = 1;
  modello_completo_B.i_j = (uint8_T)s & 127;
  if (c[modello_completo_B.i_j] || (s == '\x00')) {
    modello_completo_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  modello_completo_B.scanned1_o = 0.0;
  modello_completo_B.idx_a = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (modello_completo_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      modello_completo_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[modello_completo_B.i_j]) {
      modello_completo_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (modello_completo_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    modello_completo_B.idx_a = 2;
  }

  if (success) {
    isneg = false;
    if (modello_completo_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      modello_completo_B.d_k++;
      s1[modello_completo_B.idx_a - 1] = '1';
      modello_completo_B.idx_a++;
    } else {
      modello_comple_readNonFinite_ln(s, &modello_completo_B.d_k, &b_finite,
        &modello_completo_B.scanned1_o);
      if (b_finite) {
        success = modello_completo_copydigits_k3z(s1, &modello_completo_B.idx_a,
          s, &modello_completo_B.d_k, true);
        if (success) {
          success = modello_complet_copyexponent_kd(s1,
            &modello_completo_B.idx_a, s, &modello_completo_B.d_k);
        }
      } else {
        if ((modello_completo_B.idx_a >= 2) && (s1[0] == '-')) {
          modello_completo_B.idx_a = 1;
          s1[0] = ' ';
          modello_completo_B.scanned1_o = -modello_completo_B.scanned1_o;
        }
      }

      while ((modello_completo_B.d_k <= 1) && (c[modello_completo_B.i_j] || ((s ==
                '\x00') || (s == ',')))) {
        modello_completo_B.d_k = 2;
      }

      if ((modello_completo_B.d_k <= 1) && (s == '*')) {
        modello_completo_B.d_k = 2;
      }

      if ((modello_completo_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        modello_completo_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((modello_completo_B.d_k <= 1) && (c[modello_completo_B.i_j] || ((s ==
              '\x00') || (s == ',')))) {
      modello_completo_B.d_k = 2;
    }
  }

  if (b_finite) {
    modello_completo_B.ntoread_ju = 1;
  }

  if (success && (modello_completo_B.d_k <= 1)) {
    s1[modello_completo_B.idx_a - 1] = ' ';
    modello_completo_B.idx_a++;
    modello_completo_B.d_k = 1;
    modello_completo_readfloat_dtp(s1, &modello_completo_B.idx_a, s,
      &modello_completo_B.d_k, true, &success, &isneg,
      &modello_completo_B.scanned2_b, &foundsign, &c_success);
    if (isneg) {
      modello_completo_B.ntoread_ju++;
    }

    success = (c_success && (modello_completo_B.d_k > 1) && (isimag1 != success)
               && foundsign);
  } else {
    modello_completo_B.scanned2_b = 0.0;
  }

  if (success) {
    s1[modello_completo_B.idx_a - 1] = '\x00';
    switch (modello_completo_B.ntoread_ju) {
     case 2:
      modello_completo_B.ntoread_ju = sscanf(&s1[0], "%lf %lf",
        &modello_completo_B.scanned1_o, &modello_completo_B.scanned2_b);
      if (modello_completo_B.ntoread_ju != 2) {
        modello_completo_B.scanned1_o = (rtNaN);
        modello_completo_B.scanned2_b = (rtNaN);
      }
      break;

     case 1:
      modello_completo_B.ntoread_ju = sscanf(&s1[0], "%lf",
        &modello_completo_B.b_scanned1_n);
      if (b_finite) {
        if (modello_completo_B.ntoread_ju == 1) {
          modello_completo_B.scanned1_o = modello_completo_B.b_scanned1_n;
        } else {
          modello_completo_B.scanned1_o = (rtNaN);
        }
      } else if (modello_completo_B.ntoread_ju == 1) {
        modello_completo_B.scanned2_b = modello_completo_B.b_scanned1_n;
      } else {
        modello_completo_B.scanned2_b = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = modello_completo_B.scanned2_b;
      x.im = modello_completo_B.scanned1_o;
    } else {
      x.re = modello_completo_B.scanned1_o;
      x.im = modello_completo_B.scanned2_b;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S581>/MATLAB Function' */
static real_T modello_completo_hex2dec(const char_T s[2])
{
  static const uint64m_T tmp_0 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_1 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_2 = { { 48U, 0U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 55U, 0U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { 87U, 0U }/* chunks */
  };

  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  uint64m_T tmp;
  real_T x;
  int32_T first;
  int32_T idx;
  int32_T last;
  int32_T nbits;
  boolean_T b_signed;
  boolean_T hasPrefix;
  b_signed = false;
  nbits = 64;
  hasPrefix = false;
  first = 1;
  if (((uint8_T)s[0] == 0) || b[(uint8_T)s[0] & 127]) {
    first = 2;
  }

  if ((s[first - 1] == '0') && (first < 2) && ((s[1] == 'x') || (s[1] == 'X')))
  {
    first = 3;
    hasPrefix = true;
  }

  last = 2;
  while ((last > first) && (((uint8_T)s[1] == 0) || b[(uint8_T)s[1] & 127])) {
    last = 1;
  }

  if (hasPrefix && (first > last)) {
    first -= 2;
  }

  idx = last - 1;
  while ((idx + 1 > first) && (s[idx] >= '0') && (s[idx] <= '9')) {
    idx--;
  }

  if ((s[idx] == 's') || (s[idx] == 'S')) {
    b_signed = true;
    if (idx + 2 == last) {
      last = (uint8_T)s[1];
    } else {
      last = 48;
    }

    nbits = last - 48;
    last = idx;
  } else {
    if ((s[idx] == 'u') || (s[idx] == 'U')) {
      if (idx + 2 == last) {
        last = (uint8_T)s[1];
      } else {
        last = 48;
      }

      nbits = last - 48;
      last = idx;
    }
  }

  modello_completo_B.a_n = tmp_0;
  modello_completo_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &modello_completo_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&modello_completo_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &modello_completo_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &modello_completo_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&modello_completo_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &modello_completo_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &modello_completo_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&modello_completo_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &modello_completo_B.sk.chunks[0U], 2);
      } else {
        modello_completo_B.sk = tmp_0;
      }
    } else {
      modello_completo_B.sk = tmp_0;
    }

    uMultiWordMul(&modello_completo_B.sk.chunks[0U], 2,
                  &modello_completo_B.p16.chunks[0U], 2,
                  &modello_completo_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&modello_completo_B.r.chunks[0U], 4,
                         &modello_completo_B.r3.chunks[0U], 2);
    MultiWordAdd(&modello_completo_B.a_n.chunks[0U],
                 &modello_completo_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    modello_completo_B.a_n = tmp;
    uMultiWord2MultiWord(&modello_completo_B.p16.chunks[0U], 2,
                         &modello_completo_B.r2.chunks[0U], 3);
    uMultiWordShl(&modello_completo_B.r2.chunks[0U], 3, 4U,
                  &modello_completo_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&modello_completo_B.r1.chunks[0U], 3,
                         &modello_completo_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&modello_completo_B.a_n.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&modello_completo_B.a_n.chunks[0U], 2, 0) -
          uMultiWord2Double(&modello_completo_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&modello_completo_B.a_n.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&modello_completo_B.a_n.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&modello_completo_B.a_n.chunks[0U], 2, 0);
  }

  return x;
}

/* Model step function for TID0 */
void modello_completo_step0(void)      /* Sample time: [0.02s, 0.0s] */
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  int32_T exitg3;
  uint16_T x;
  char_T ck_ric[2];
  char_T messaggio;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T output_raw[2];
  uint8_T rtb_H_mav[2];
  uint8_T find_comma;
  uint8_T status;
  boolean_T Ap_sel;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Mti): '<S569>/S-Function Builder' */
  Mti_Outputs_wrapper(&modello_completo_B.SFunctionBuilder[0],
                      &modello_completo_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S569>/Byte Unpack' */

  /* Unpack: <S569>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o1[0], (uint8_T*)
             &modello_completo_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o2[0], (uint8_T*)
             &modello_completo_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o3_b, (uint8_T*)
             &modello_completo_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S569>/Byte Reversal' */

  /* ReverseEndian: <S569>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &modello_completo_B.ByteUnpack_o2[0];
    real32_T *y0 = &modello_completo_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S567>/One_time_initialization' */
  /* Logic: '<S567>/Logical Operator1' incorporates:
   *  UnitDelay: '<S567>/Unit Delay'
   */
  mod_One_time_initialization(!modello_completo_DW.UnitDelay_DSTATE_d,
    &modello_completo_B.One_time_initialization,
    &modello_completo_DW.One_time_initialization,
    &modello_completo_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S567>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S567>/Execution_loop' incorporates:
   *  EnablePort: '<S571>/Enable'
   */
  /* UnitDelay: '<S567>/Unit Delay' */
  if (modello_completo_DW.UnitDelay_DSTATE_d) {
    /* MATLABSystem: '<S571>/I2C Read12' */
    if (modello_completo_DW.obj_f.SampleTime != modello_completo_P.t_AP) {
      modello_completo_DW.obj_f.SampleTime = modello_completo_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (modello_completo_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U, &status, 1U,
       true, false);
    if (0 == status) {
      MW_I2C_MasterRead(modello_completo_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S571>/I2C Read1' */
    if (modello_completo_DW.obj_p.SampleTime != modello_completo_P.t_AP) {
      modello_completo_DW.obj_p.SampleTime = modello_completo_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (modello_completo_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U, &status, 1U,
       true, false);
    if (0 == status) {
      MW_I2C_MasterRead(modello_completo_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &modello_completo_B.output_raw[0], 3U, false, true);
      memcpy((void *)&modello_completo_B.output[0], (void *)
             &modello_completo_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
              (uint8_T)));
    } else {
      modello_completo_B.output[0] = 0U;
      modello_completo_B.output[1] = 0U;
      modello_completo_B.output[2] = 0U;
    }

    /* ArithShift: '<S571>/Shift Arithmetic4' incorporates:
     *  Constant: '<S571>/Constant1'
     */
    modello_completo_B.deltafalllimit = floor
      (modello_completo_P.Constant1_Value_o);
    if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
        (modello_completo_B.deltafalllimit)) {
      modello_completo_B.deltafalllimit = 0.0;
    } else {
      modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
        4.294967296E+9);
    }

    /* ArithShift: '<S571>/Shift Arithmetic3' incorporates:
     *  Constant: '<S571>/Constant5'
     */
    modello_completo_B.Sum3_o = floor(modello_completo_P.Constant5_Value_n);
    if (rtIsNaN(modello_completo_B.Sum3_o) || rtIsInf(modello_completo_B.Sum3_o))
    {
      modello_completo_B.Sum3_o = 0.0;
    } else {
      modello_completo_B.Sum3_o = fmod(modello_completo_B.Sum3_o, 4.294967296E+9);
    }

    /* ArithShift: '<S571>/Shift Arithmetic1' incorporates:
     *  Constant: '<S571>/Constant6'
     */
    modello_completo_B.num_254 = floor(modello_completo_P.Constant6_Value);
    if (rtIsNaN(modello_completo_B.num_254) || rtIsInf
        (modello_completo_B.num_254)) {
      modello_completo_B.num_254 = 0.0;
    } else {
      modello_completo_B.num_254 = fmod(modello_completo_B.num_254,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S571>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S571>/Shift Arithmetic1'
     *  ArithShift: '<S571>/Shift Arithmetic3'
     *  ArithShift: '<S571>/Shift Arithmetic4'
     *  Constant: '<S571>/Constant10'
     *  Constant: '<S571>/Constant11'
     *  Constant: '<S571>/Constant7'
     *  MATLABSystem: '<S571>/I2C Read1'
     *  Sum: '<S571>/Sum1'
     *  Sum: '<S571>/Sum4'
     *  Sum: '<S571>/Sum5'
     *  Sum: '<S571>/Sum6'
     */
    modello_completo_B.DataTypeConversion1_i = (int32_T)
      ((((((modello_completo_P.Constant7_Value + modello_completo_B.output[0]) <<
           (modello_completo_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
            -modello_completo_B.deltafalllimit : (int32_T)(uint32_T)
            modello_completo_B.deltafalllimit)) +
          ((modello_completo_P.Constant10_Value + modello_completo_B.output[1]) <<
           (modello_completo_B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
            -modello_completo_B.Sum3_o : (int32_T)(uint32_T)
            modello_completo_B.Sum3_o))) + modello_completo_P.Constant11_Value)
        + modello_completo_B.output[2]) >> (modello_completo_B.num_254 < 0.0 ?
        -(int32_T)(uint32_T)-modello_completo_B.num_254 : (int32_T)(uint32_T)
        modello_completo_B.num_254));

    /* ArithShift: '<S571>/Shift Arithmetic7' incorporates:
     *  Constant: '<S571>/Constant2'
     */
    modello_completo_B.deltafalllimit = floor
      (modello_completo_P.Constant2_Value_a);
    if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
        (modello_completo_B.deltafalllimit)) {
      modello_completo_B.deltafalllimit = 0.0;
    } else {
      modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
        4.294967296E+9);
    }

    /* ArithShift: '<S571>/Shift Arithmetic6' incorporates:
     *  Constant: '<S571>/Constant3'
     */
    modello_completo_B.Sum3_o = floor(modello_completo_P.Constant3_Value_c0);
    if (rtIsNaN(modello_completo_B.Sum3_o) || rtIsInf(modello_completo_B.Sum3_o))
    {
      modello_completo_B.Sum3_o = 0.0;
    } else {
      modello_completo_B.Sum3_o = fmod(modello_completo_B.Sum3_o, 4.294967296E+9);
    }

    /* ArithShift: '<S571>/Shift Arithmetic2' incorporates:
     *  Constant: '<S571>/Constant4'
     */
    modello_completo_B.num_254 = floor(modello_completo_P.Constant4_Value_l);
    if (rtIsNaN(modello_completo_B.num_254) || rtIsInf
        (modello_completo_B.num_254)) {
      modello_completo_B.num_254 = 0.0;
    } else {
      modello_completo_B.num_254 = fmod(modello_completo_B.num_254,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S571>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S571>/Shift Arithmetic2'
     *  ArithShift: '<S571>/Shift Arithmetic6'
     *  ArithShift: '<S571>/Shift Arithmetic7'
     *  Constant: '<S571>/Constant8'
     *  Constant: '<S571>/Constant9'
     *  MATLABSystem: '<S571>/I2C Read12'
     *  Sum: '<S571>/Sum'
     *  Sum: '<S571>/Sum2'
     *  Sum: '<S571>/Sum3'
     */
    modello_completo_B.DataTypeConversion_ay = (int32_T)
      ((((modello_completo_P.Constant8_Value_e + rtb_H_mav[0]) <<
         (modello_completo_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
          -modello_completo_B.deltafalllimit : (int32_T)(uint32_T)
          modello_completo_B.deltafalllimit)) +
        ((modello_completo_P.Constant9_Value + rtb_H_mav[1]) <<
         (modello_completo_B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
          -modello_completo_B.Sum3_o : (int32_T)(uint32_T)
          modello_completo_B.Sum3_o))) >> (modello_completo_B.num_254 < 0.0 ?
        -(int32_T)(uint32_T)-modello_completo_B.num_254 : (int32_T)(uint32_T)
        modello_completo_B.num_254));

    /* S-Function (calc_T): '<S571>/S-Function Builder' */
    calc_T_Outputs_wrapper(&modello_completo_B.One_time_initialization.I2CRead,
      &modello_completo_B.One_time_initialization.I2CRead1,
      &modello_completo_B.One_time_initialization.I2CRead2,
      &modello_completo_B.DataTypeConversion_ay,
      &modello_completo_B.SFunctionBuilder_o1,
      &modello_completo_B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S571>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&modello_completo_B.One_time_initialization.I2CRead3,
      &modello_completo_B.One_time_initialization.I2CRead4,
      &modello_completo_B.One_time_initialization.I2CRead5,
      &modello_completo_B.One_time_initialization.I2CRead6,
      &modello_completo_B.One_time_initialization.I2CRead7,
      &modello_completo_B.One_time_initialization.I2CRead8,
      &modello_completo_B.One_time_initialization.I2CRead9,
      &modello_completo_B.One_time_initialization.I2CRead10,
      &modello_completo_B.One_time_initialization.I2CRead11,
      &modello_completo_B.DataTypeConversion1_i,
      &modello_completo_B.SFunctionBuilder_o2_a,
      &modello_completo_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S567>/Execution_loop' */

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&modello_completo_P.Constant1_Value_a,
    &modello_completo_B.SFunctionBuilder_o1_h[0],
    &modello_completo_B.SFunctionBuilder_o2,
    &modello_completo_DW.SFunctionBuilder_DSTATE_l);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  modello_completo_B.AL = 0;
  modello_completo_B.caso = 0;
  memset(&modello_completo_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
  memset(&modello_completo_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  modello_completo_find_254(modello_completo_B.SFunctionBuilder_o1_h,
    modello_completo_B.lat_end, &modello_completo_B.num_254);
  if (modello_completo_DW.Interr_parz && (modello_completo_B.num_254 == 1.0)) {
    modello_completo_B.ATO = (int32_T)(modello_completo_DW.counter_a + 1U);
    if (modello_completo_DW.counter_a + 1U > 255U) {
      modello_completo_B.ATO = 255;
    }

    if (modello_completo_B.lat_end[0] != modello_completo_B.ATO) {
      modello_completo_B.num_254 = 0.0;
    }
  }

  Ap_sel = !modello_completo_DW.Interr_parz;
  if ((modello_completo_B.num_254 == 1.0) && Ap_sel) {
    modello_completo_B.caso = 1;
  } else if ((modello_completo_B.num_254 == 0.0) &&
             modello_completo_DW.Interr_parz) {
    modello_completo_B.caso = 2;
  } else if ((modello_completo_B.num_254 == 1.0) &&
             modello_completo_DW.Interr_parz) {
    modello_completo_B.caso = 3;
  } else {
    if ((modello_completo_B.num_254 == 2.0) && Ap_sel) {
      modello_completo_B.caso = 4;
    }
  }

  switch (modello_completo_B.caso) {
   case 1:
    modello_completo_B.deltafalllimit = modello_completo_B.lat_end[(int32_T)
      modello_completo_B.num_254 - 1];
    if (modello_completo_B.deltafalllimit == 100.0) {
      modello_completo_DW.message_i[0] =
        modello_completo_B.SFunctionBuilder_o1_h[99];
      modello_completo_DW.Interr_parz = true;
    } else if (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
               (modello_completo_B.deltafalllimit + 1.0) - 1] <= 100) {
      modello_completo_B.ATO = (int32_T)
        (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
         (modello_completo_B.lat_end[0] + 1.0) - 1] + 8U);
      modello_completo_B.g = modello_completo_B.ATO;
      if ((uint32_T)modello_completo_B.ATO > 255U) {
        modello_completo_B.g = 255;
      }

      if (modello_completo_B.g == modello_completo_B.SFunctionBuilder_o2) {
        modello_completo_B.Sum3_o = rt_roundd_snf
          (modello_completo_B.deltafalllimit);
        if (modello_completo_B.Sum3_o < 256.0) {
          if (modello_completo_B.Sum3_o >= 0.0) {
            status = (uint8_T)modello_completo_B.Sum3_o;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        modello_completo_B.ATO = (int32_T)
          (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
           (modello_completo_B.deltafalllimit + 1.0) - 1] + 7U);
        if ((uint32_T)modello_completo_B.ATO > 255U) {
          modello_completo_B.ATO = 255;
        }

        modello_completo_B.deltafalllimit = rt_roundd_snf
          (modello_completo_B.deltafalllimit + (real_T)modello_completo_B.ATO);
        if (modello_completo_B.deltafalllimit < 256.0) {
          if (modello_completo_B.deltafalllimit >= 0.0) {
            find_comma = (uint8_T)modello_completo_B.deltafalllimit;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          modello_completo_B.g = 0;
          modello_completo_B.i = 0;
        } else {
          modello_completo_B.g = status - 1;
          modello_completo_B.i = find_comma;
        }

        modello_completo_B.caso = modello_completo_B.i - modello_completo_B.g;
        for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
             modello_completo_B.caso; modello_completo_B.ATO++) {
          modello_completo_DW.message_i[modello_completo_B.ATO] =
            modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.g +
            modello_completo_B.ATO];
        }

        modello_completo_B.AL = 1;
        for (modello_completo_B.i = 0; modello_completo_B.i < 100;
             modello_completo_B.i++) {
          modello_completo_B.messaggio_i[modello_completo_B.i] =
            modello_completo_DW.message_i[modello_completo_B.i];
          modello_completo_DW.message_i[modello_completo_B.i] = 0U;
        }

        modello_completo_DW.counter_a = 0U;
        modello_completo_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)modello_completo_B.ATO > 255U) {
          modello_completo_B.ATO = 255;
        }

        if (modello_completo_B.ATO > modello_completo_B.SFunctionBuilder_o2) {
          modello_completo_DW.mess_len = modello_completo_B.SFunctionBuilder_o2;
          if (modello_completo_B.deltafalllimit > modello_completo_DW.mess_len)
          {
            modello_completo_B.g = 0;
            modello_completo_B.i = 0;
          } else {
            modello_completo_B.g = (int32_T)modello_completo_B.deltafalllimit -
              1;
            modello_completo_B.i = (int32_T)modello_completo_DW.mess_len;
          }

          modello_completo_B.caso = modello_completo_B.i - modello_completo_B.g;
          for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
               modello_completo_B.caso; modello_completo_B.ATO++) {
            modello_completo_DW.message_i[modello_completo_B.ATO] =
              modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.g +
              modello_completo_B.ATO];
          }

          modello_completo_B.ATO = (int32_T)
            (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
             (modello_completo_B.deltafalllimit + 1.0) - 1] + 8U);
          if ((uint32_T)modello_completo_B.ATO > 255U) {
            modello_completo_B.ATO = 255;
          }

          modello_completo_B.deltafalllimit = rt_roundd_snf((real_T)
            modello_completo_B.ATO - modello_completo_DW.mess_len);
          if (modello_completo_B.deltafalllimit < 256.0) {
            if (modello_completo_B.deltafalllimit >= 0.0) {
              modello_completo_DW.counter_a = (uint8_T)
                modello_completo_B.deltafalllimit;
            } else {
              modello_completo_DW.counter_a = 0U;
            }
          } else {
            modello_completo_DW.counter_a = MAX_uint8_T;
          }

          modello_completo_DW.Interr_parz = true;
        }
      }
    } else {
      modello_completo_DW.Interr_parz = false;
      memset(&modello_completo_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      modello_completo_DW.counter_a = 0U;
      modello_completo_DW.mess_len = 0.0;
      modello_completo_B.AL = 1;
    }
    break;

   case 2:
    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
         modello_completo_B.ATO++) {
      modello_completo_B.x[modello_completo_B.ATO] =
        (modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.ATO] != 0);
    }

    if (modello_completo_ifWhileCond(modello_completo_B.x)) {
      modello_completo_B.deltafalllimit = rt_roundd_snf
        (modello_completo_DW.mess_len + 1.0);
      if (modello_completo_B.deltafalllimit < 256.0) {
        if (modello_completo_B.deltafalllimit >= 0.0) {
          find_comma = (uint8_T)modello_completo_B.deltafalllimit;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      modello_completo_B.deltafalllimit = rt_roundd_snf
        (modello_completo_DW.mess_len + (real_T)modello_completo_DW.counter_a);
      if (modello_completo_B.deltafalllimit < 256.0) {
        if (modello_completo_B.deltafalllimit >= 0.0) {
          status = (uint8_T)modello_completo_B.deltafalllimit;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      if (find_comma > status) {
        modello_completo_B.AL = 1;
      } else {
        modello_completo_B.AL = find_comma;
      }

      if (1 > modello_completo_DW.counter_a) {
        modello_completo_B.caso = -1;
      } else {
        modello_completo_B.caso = modello_completo_DW.counter_a - 1;
      }

      for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
           modello_completo_B.caso; modello_completo_B.ATO++) {
        modello_completo_DW.message_i[(modello_completo_B.AL +
          modello_completo_B.ATO) - 1] =
          modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.ATO];
      }

      modello_completo_DW.Interr_parz = false;
      modello_completo_B.AL = 1;
      for (modello_completo_B.i = 0; modello_completo_B.i < 100;
           modello_completo_B.i++) {
        modello_completo_B.messaggio_i[modello_completo_B.i] =
          modello_completo_DW.message_i[modello_completo_B.i];
        modello_completo_DW.message_i[modello_completo_B.i] = 0U;
      }

      modello_completo_DW.mess_len = 0.0;
      modello_completo_DW.counter_a = 0U;
    } else {
      modello_completo_DW.Interr_parz = false;
      modello_completo_B.AL = 1;
      memset(&modello_completo_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      modello_completo_DW.mess_len = 0.0;
      modello_completo_DW.counter_a = 0U;
    }
    break;

   case 3:
    modello_completo_B.deltafalllimit = rt_roundd_snf
      (modello_completo_DW.mess_len + 1.0);
    if (modello_completo_B.deltafalllimit < 256.0) {
      if (modello_completo_B.deltafalllimit >= 0.0) {
        find_comma = (uint8_T)modello_completo_B.deltafalllimit;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    modello_completo_B.deltafalllimit = rt_roundd_snf
      (modello_completo_DW.mess_len + (real_T)modello_completo_DW.counter_a);
    if (modello_completo_B.deltafalllimit < 256.0) {
      if (modello_completo_B.deltafalllimit >= 0.0) {
        status = (uint8_T)modello_completo_B.deltafalllimit;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    if (find_comma > status) {
      modello_completo_B.g = 1;
    } else {
      modello_completo_B.g = find_comma;
    }

    if (1 > modello_completo_DW.counter_a) {
      modello_completo_B.caso = -1;
    } else {
      modello_completo_B.caso = modello_completo_DW.counter_a - 1;
    }

    for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
         modello_completo_B.caso; modello_completo_B.ATO++) {
      modello_completo_DW.message_i[(modello_completo_B.g +
        modello_completo_B.ATO) - 1] =
        modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.ATO];
    }

    modello_completo_DW.Interr_parz = false;
    modello_completo_B.AL = 1;
    for (modello_completo_B.i = 0; modello_completo_B.i < 100;
         modello_completo_B.i++) {
      modello_completo_B.messaggio_i[modello_completo_B.i] =
        modello_completo_DW.message_i[modello_completo_B.i];
      modello_completo_DW.message_i[modello_completo_B.i] = 0U;
    }

    modello_completo_DW.mess_len = 0.0;
    modello_completo_DW.counter_a = 0U;
    modello_completo_B.ATO = (int32_T)(modello_completo_B.lat_end[(int32_T)
      modello_completo_B.num_254 - 1] + 1.0) - 1;
    if (modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.ATO] <= 100)
    {
      modello_completo_B.g = (int32_T)(modello_completo_B.SFunctionBuilder_o1_h
        [(int32_T)(modello_completo_B.lat_end[0] + 1.0) - 1] + 8U);
      if ((uint32_T)modello_completo_B.g > 255U) {
        modello_completo_B.g = 255;
      }

      modello_completo_B.caso = modello_completo_B.SFunctionBuilder_o2;
      if (modello_completo_B.SFunctionBuilder_o2 < 0) {
        modello_completo_B.caso = 0;
      } else {
        if (modello_completo_B.SFunctionBuilder_o2 > 255) {
          modello_completo_B.caso = 255;
        }
      }

      if (modello_completo_B.g == modello_completo_B.caso) {
        modello_completo_B.deltafalllimit = rt_roundd_snf
          (modello_completo_B.lat_end[(int32_T)modello_completo_B.num_254 - 1]);
        if (modello_completo_B.deltafalllimit < 256.0) {
          if (modello_completo_B.deltafalllimit >= 0.0) {
            status = (uint8_T)modello_completo_B.deltafalllimit;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        modello_completo_B.ATO = (int32_T)
          (modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.ATO] + 7U);
        if ((uint32_T)modello_completo_B.ATO > 255U) {
          modello_completo_B.ATO = 255;
        }

        modello_completo_B.deltafalllimit = rt_roundd_snf
          (modello_completo_B.lat_end[(int32_T)modello_completo_B.num_254 - 1] +
           (real_T)modello_completo_B.ATO);
        if (modello_completo_B.deltafalllimit < 256.0) {
          if (modello_completo_B.deltafalllimit >= 0.0) {
            find_comma = (uint8_T)modello_completo_B.deltafalllimit;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          modello_completo_B.g = 0;
          modello_completo_B.ATO = 0;
        } else {
          modello_completo_B.g = status - 1;
          modello_completo_B.ATO = find_comma;
        }

        modello_completo_B.caso = modello_completo_B.ATO - modello_completo_B.g;
        for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
             modello_completo_B.caso; modello_completo_B.ATO++) {
          modello_completo_DW.message_i[modello_completo_B.ATO] =
            modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.g +
            modello_completo_B.ATO];
        }

        for (modello_completo_B.i = 0; modello_completo_B.i < 100;
             modello_completo_B.i++) {
          modello_completo_B.messaggio_2[modello_completo_B.i] =
            modello_completo_DW.message_i[modello_completo_B.i];
          modello_completo_DW.message_i[modello_completo_B.i] = 0U;
        }

        modello_completo_DW.counter_a = 0U;
        modello_completo_DW.mess_len = 0.0;
      } else {
        modello_completo_B.g = (int32_T)
          (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
           (modello_completo_B.lat_end[0] + 1.0) - 1] + 8U);
        if ((uint32_T)modello_completo_B.g > 255U) {
          modello_completo_B.g = 255;
        }

        modello_completo_B.caso = modello_completo_B.SFunctionBuilder_o2;
        if (modello_completo_B.SFunctionBuilder_o2 < 0) {
          modello_completo_B.caso = 0;
        } else {
          if (modello_completo_B.SFunctionBuilder_o2 > 255) {
            modello_completo_B.caso = 255;
          }
        }

        if (modello_completo_B.g > modello_completo_B.caso) {
          modello_completo_DW.mess_len = modello_completo_B.SFunctionBuilder_o2;
          if (modello_completo_B.lat_end[(int32_T)modello_completo_B.num_254 - 1]
              > modello_completo_DW.mess_len) {
            modello_completo_B.i = 0;
            modello_completo_B.caso = 0;
          } else {
            modello_completo_B.i = (int32_T)modello_completo_B.lat_end[(int32_T)
              modello_completo_B.num_254 - 1] - 1;
            modello_completo_B.caso = (int32_T)modello_completo_DW.mess_len;
          }

          modello_completo_B.caso -= modello_completo_B.i;
          for (modello_completo_B.g = 0; modello_completo_B.g <
               modello_completo_B.caso; modello_completo_B.g++) {
            modello_completo_DW.message_i[modello_completo_B.g] =
              modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.i +
              modello_completo_B.g];
          }

          modello_completo_B.ATO = (int32_T)
            (modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.ATO] +
             8U);
          if ((uint32_T)modello_completo_B.ATO > 255U) {
            modello_completo_B.ATO = 255;
          }

          modello_completo_B.deltafalllimit = rt_roundd_snf((real_T)
            modello_completo_B.ATO - modello_completo_DW.mess_len);
          if (modello_completo_B.deltafalllimit < 256.0) {
            if (modello_completo_B.deltafalllimit >= 0.0) {
              modello_completo_DW.counter_a = (uint8_T)
                modello_completo_B.deltafalllimit;
            } else {
              modello_completo_DW.counter_a = 0U;
            }
          } else {
            modello_completo_DW.counter_a = MAX_uint8_T;
          }

          modello_completo_DW.Interr_parz = true;
        }
      }
    } else {
      modello_completo_DW.Interr_parz = false;
      memset(&modello_completo_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
      memset(&modello_completo_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      modello_completo_DW.counter_a = 0U;
      modello_completo_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
        (modello_completo_B.lat_end[0] + 1.0) - 1] <= 100) {
      modello_completo_B.deltafalllimit = rt_roundd_snf
        (modello_completo_B.lat_end[0]);
      if (modello_completo_B.deltafalllimit < 256.0) {
        if (modello_completo_B.deltafalllimit >= 0.0) {
          status = (uint8_T)modello_completo_B.deltafalllimit;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      modello_completo_B.ATO = (int32_T)
        (modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
         (modello_completo_B.lat_end[0] + 1.0) - 1] + 7U);
      if ((uint32_T)modello_completo_B.ATO > 255U) {
        modello_completo_B.ATO = 255;
      }

      modello_completo_B.deltafalllimit = rt_roundd_snf
        (modello_completo_B.lat_end[0] + (real_T)modello_completo_B.ATO);
      if (modello_completo_B.deltafalllimit < 256.0) {
        if (modello_completo_B.deltafalllimit >= 0.0) {
          find_comma = (uint8_T)modello_completo_B.deltafalllimit;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (status > find_comma) {
        modello_completo_B.AL = 0;
        modello_completo_B.ATO = 0;
      } else {
        modello_completo_B.AL = status - 1;
        modello_completo_B.ATO = find_comma;
      }

      modello_completo_B.caso = modello_completo_B.ATO - modello_completo_B.AL;
      for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
           modello_completo_B.caso; modello_completo_B.ATO++) {
        modello_completo_B.messaggio_i[modello_completo_B.ATO] =
          modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.AL +
          modello_completo_B.ATO];
      }
    } else {
      modello_completo_DW.Interr_parz = false;
      memset(&modello_completo_DW.message_i[0], 0, 100U * sizeof(uint8_T));
    }

    modello_completo_B.AL = 1;
    if ((modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
         (modello_completo_B.lat_end[1] + 1.0) - 1] <= 100) &&
        (modello_completo_B.lat_end[1] - modello_completo_B.lat_end[0] > 3.0)) {
      modello_completo_B.deltafalllimit = rt_roundd_snf((real_T)
        modello_completo_B.SFunctionBuilder_o2 - modello_completo_B.lat_end[1]);
      modello_completo_B.qY = modello_completo_B.SFunctionBuilder_o1_h[(int32_T)
        (modello_completo_B.lat_end[1] + 1.0) - 1];
      modello_completo_B.ATO = (int32_T)(modello_completo_B.qY + 7U);
      if (modello_completo_B.qY + 7U > 255U) {
        modello_completo_B.ATO = 255;
      }

      if (modello_completo_B.deltafalllimit < 2.147483648E+9) {
        if (modello_completo_B.deltafalllimit >= -2.147483648E+9) {
          modello_completo_B.g = (int32_T)modello_completo_B.deltafalllimit;
        } else {
          modello_completo_B.g = MIN_int32_T;
        }
      } else {
        modello_completo_B.g = MAX_int32_T;
      }

      if (modello_completo_B.g == modello_completo_B.ATO) {
        modello_completo_B.deltafalllimit = rt_roundd_snf
          (modello_completo_B.lat_end[1]);
        if (modello_completo_B.deltafalllimit < 256.0) {
          if (modello_completo_B.deltafalllimit >= 0.0) {
            status = (uint8_T)modello_completo_B.deltafalllimit;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        modello_completo_B.ATO = (int32_T)(modello_completo_B.qY + 7U);
        if (modello_completo_B.qY + 7U > 255U) {
          modello_completo_B.ATO = 255;
        }

        modello_completo_B.deltafalllimit = rt_roundd_snf
          (modello_completo_B.lat_end[1] + (real_T)modello_completo_B.ATO);
        if (modello_completo_B.deltafalllimit < 256.0) {
          if (modello_completo_B.deltafalllimit >= 0.0) {
            find_comma = (uint8_T)modello_completo_B.deltafalllimit;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          modello_completo_B.AL = 0;
          modello_completo_B.ATO = 0;
        } else {
          modello_completo_B.AL = status - 1;
          modello_completo_B.ATO = find_comma;
        }

        modello_completo_B.caso = modello_completo_B.ATO - modello_completo_B.AL;
        for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
             modello_completo_B.caso; modello_completo_B.ATO++) {
          modello_completo_DW.message_i[modello_completo_B.ATO] =
            modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.AL +
            modello_completo_B.ATO];
        }

        modello_completo_B.AL = 2;
        for (modello_completo_B.i = 0; modello_completo_B.i < 100;
             modello_completo_B.i++) {
          modello_completo_B.messaggio_2[modello_completo_B.i] =
            modello_completo_DW.message_i[modello_completo_B.i];
          modello_completo_DW.message_i[modello_completo_B.i] = 0U;
        }

        modello_completo_DW.counter_a = 0U;
        modello_completo_DW.mess_len = 0.0;
      } else {
        modello_completo_B.deltafalllimit = rt_roundd_snf
          (modello_completo_B.lat_end[1]);
        if (modello_completo_B.deltafalllimit < 2.147483648E+9) {
          if (modello_completo_B.deltafalllimit >= -2.147483648E+9) {
            modello_completo_B.ATO = (int32_T)modello_completo_B.deltafalllimit;
          } else {
            modello_completo_B.ATO = MIN_int32_T;
          }
        } else {
          modello_completo_B.ATO = MAX_int32_T;
        }

        if (modello_completo_B.ATO > modello_completo_B.SFunctionBuilder_o2) {
          modello_completo_B.ATO = -1;
          modello_completo_B.caso = 0;
        } else {
          modello_completo_B.ATO -= 2;
          modello_completo_B.caso = modello_completo_B.SFunctionBuilder_o2;
        }

        modello_completo_DW.mess_len = (int8_T)((modello_completo_B.caso -
          modello_completo_B.ATO) - 1);
        if (modello_completo_B.deltafalllimit < 2.147483648E+9) {
          if (modello_completo_B.deltafalllimit >= -2.147483648E+9) {
            modello_completo_B.ATO = (int32_T)modello_completo_B.deltafalllimit;
          } else {
            modello_completo_B.ATO = MIN_int32_T;
          }
        } else {
          modello_completo_B.ATO = MAX_int32_T;
        }

        if (modello_completo_B.ATO > modello_completo_B.SFunctionBuilder_o2) {
          modello_completo_B.g = 0;
          modello_completo_B.ATO = 0;
        } else {
          modello_completo_B.g = modello_completo_B.ATO - 1;
          modello_completo_B.ATO = modello_completo_B.SFunctionBuilder_o2;
        }

        modello_completo_B.caso = modello_completo_B.ATO - modello_completo_B.g;
        for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
             modello_completo_B.caso; modello_completo_B.ATO++) {
          modello_completo_DW.message_i[modello_completo_B.ATO] =
            modello_completo_B.SFunctionBuilder_o1_h[modello_completo_B.g +
            modello_completo_B.ATO];
        }

        modello_completo_B.ATO = (int32_T)(modello_completo_B.qY + 8U);
        if (modello_completo_B.qY + 8U > 255U) {
          modello_completo_B.ATO = 255;
        }

        modello_completo_B.deltafalllimit = rt_roundd_snf((real_T)
          modello_completo_B.ATO - modello_completo_DW.mess_len);
        if (modello_completo_B.deltafalllimit < 256.0) {
          if (modello_completo_B.deltafalllimit >= 0.0) {
            modello_completo_DW.counter_a = (uint8_T)
              modello_completo_B.deltafalllimit;
          } else {
            modello_completo_DW.counter_a = 0U;
          }
        } else {
          modello_completo_DW.counter_a = MAX_uint8_T;
        }

        modello_completo_DW.Interr_parz = true;
      }
    } else {
      modello_completo_DW.Interr_parz = false;
      memset(&modello_completo_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      modello_completo_DW.counter_a = 0U;
      modello_completo_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&modello_completo_B.buffer[0], 0, 300U * sizeof(uint8_T));
  status = 0U;
  for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
       modello_completo_B.ATO++) {
    modello_completo_B.buffer[3 * modello_completo_B.ATO] = 0U;
  }

  for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
       modello_completo_B.ATO++) {
    for (modello_completo_B.caso = 0; modello_completo_B.caso < 2;
         modello_completo_B.caso++) {
      modello_completo_B.g = 3 * modello_completo_B.ATO +
        modello_completo_B.caso;
      modello_completo_B.buffer[modello_completo_B.g + 1] =
        modello_completo_DW.Memory4_PreviousInput_c[modello_completo_B.g];
    }
  }

  modello_completo_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (modello_completo_B.i >= 1)) {
    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
         modello_completo_B.ATO++) {
      modello_completo_B.x[modello_completo_B.ATO] = (modello_completo_B.buffer
        [(3 * modello_completo_B.ATO + modello_completo_B.i) - 1] == 0);
    }

    Ap_sel = true;
    modello_completo_B.ATO = 0;
    exitg2 = false;
    while ((!exitg2) && (modello_completo_B.ATO < 100)) {
      if (!modello_completo_B.x[modello_completo_B.ATO]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        modello_completo_B.ATO++;
      }
    }

    if (Ap_sel) {
      status = (uint8_T)modello_completo_B.i;
      exitg1 = true;
    } else {
      modello_completo_B.i--;
    }
  }

  if (modello_completo_B.AL == 1) {
    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
         modello_completo_B.ATO++) {
      modello_completo_B.buffer[(status + 3 * modello_completo_B.ATO) - 1] =
        modello_completo_B.messaggio_i[modello_completo_B.ATO];
    }
  } else if (modello_completo_B.AL == 2) {
    modello_completo_B.qY = status - /*MW:OvSatOk*/ 1U;
    if (status - 1U > status) {
      modello_completo_B.qY = 0U;
    }

    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
         modello_completo_B.ATO++) {
      modello_completo_B.buffer[(status + 3 * modello_completo_B.ATO) - 1] =
        modello_completo_B.messaggio_i[modello_completo_B.ATO];
      modello_completo_B.buffer[((int32_T)modello_completo_B.qY + 3 *
        modello_completo_B.ATO) - 1] =
        modello_completo_B.messaggio_2[modello_completo_B.ATO];
    }
  } else {
    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
         modello_completo_B.ATO++) {
      modello_completo_B.buffer[(status + 3 * modello_completo_B.ATO) - 1] = 0U;
    }
  }

  for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
       modello_completo_B.ATO++) {
    modello_completo_B.mess_out[modello_completo_B.ATO] =
      modello_completo_DW.Memory4_PreviousInput_c[3 * modello_completo_B.ATO + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  modello_completo_B.Add = modello_completo_DW.Memory4_PreviousInput_c[5] +
    modello_completo_P.Constant_Value_gw;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (modello_completo_B.mess_out[2] !=
      modello_completo_DW.Memory5_PreviousInput_l[2]) {
    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 100;
         modello_completo_B.ATO++) {
      modello_completo_B.x[modello_completo_B.ATO] =
        (modello_completo_B.mess_out[modello_completo_B.ATO] != 0);
    }

    Ap_sel = true;
    modello_completo_B.ATO = 0;
    exitg1 = false;
    while ((!exitg1) && (modello_completo_B.ATO < 100)) {
      if (!modello_completo_B.x[modello_completo_B.ATO]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        modello_completo_B.ATO++;
      }
    }

    if (!Ap_sel) {
      if (modello_completo_DW.counter > 100) {
        modello_completo_DW.counter = 0U;
      }

      modello_completo_B.qY = modello_completo_DW.counter + 1U;
      if (modello_completo_DW.counter + 1U > 65535U) {
        modello_completo_B.qY = 65535U;
      }

      modello_completo_DW.counter = (uint16_T)modello_completo_B.qY;
    }
  }

  modello_completo_B.new_mex = modello_completo_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  modello_completo_B.Memory1[0] = modello_completo_DW.Memory1_PreviousInput_d[0];
  modello_completo_B.Memory1[1] = modello_completo_DW.Memory1_PreviousInput_d[1];

  /* Memory: '<Root>/Memory' */
  modello_completo_B.Memory_k[0] = modello_completo_DW.Memory_PreviousInput_h5[0];
  modello_completo_B.Memory_k[1] = modello_completo_DW.Memory_PreviousInput_h5[1];
  modello_completo_B.Memory_k[2] = modello_completo_DW.Memory_PreviousInput_h5[2];
  modello_completo_B.Memory_k[3] = modello_completo_DW.Memory_PreviousInput_h5[3];

  /* Memory: '<S1>/Memory3' */
  modello_completo_B.Memory3 = modello_completo_DW.Memory3_PreviousInput_o;
  for (modello_completo_B.i = 0; modello_completo_B.i < 8; modello_completo_B.i
       ++) {
    /* Memory: '<S1>/Memory' */
    modello_completo_B.Memory[modello_completo_B.i] =
      modello_completo_DW.Memory_PreviousInput_ic[modello_completo_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&modello_completo_B.mess_out[0], &modello_completo_B.Add,
     &modello_completo_B.new_mex, &modello_completo_P.SIUAVuint8_Value,
     &modello_completo_B.Memory[0], &modello_completo_B.Memory1[0],
     &modello_completo_B.Memory_k[0], &modello_completo_B.Memory3,
     &modello_completo_B.SFunction_o1[0], &modello_completo_B.SFunction_o2,
     &modello_completo_B.SFunction_o3_j, &modello_completo_B.SFunction_o4_n[0],
     &modello_completo_B.SFunction_o5[0], &modello_completo_B.SFunction_o6,
     &modello_completo_B.SFunction_o7[0], &modello_completo_B.SFunction_o8,
     &modello_completo_B.SFunction_o9[0], &modello_completo_B.SFunction_o10[0],
     &modello_completo_B.SFunction_o11[0], &modello_completo_B.SFunction_o12,
     &modello_completo_B.SFunction_o13, &modello_completo_B.SFunction_o14,
     &modello_completo_B.SFunction_o15, &modello_completo_B.SFunction_o16,
     &modello_completo_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (modello_completo_B.i = 0; modello_completo_B.i < 6; modello_completo_B.i
       ++) {
    modello_completo_B.WP_info_in[modello_completo_B.i] =
      modello_completo_B.SFunction_o9[modello_completo_B.i];
  }

  if ((!modello_completo_DW.WP_dbP_not_empty) ||
      ((modello_completo_B.SFunction_o7[0] == 3) &&
       (modello_completo_B.SFunction_o7[1] == 250))) {
    memset(&modello_completo_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    modello_completo_DW.WP_dbP_not_empty = true;
    memset(&modello_completo_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!modello_completo_DW.WP_dbP_AL_not_empty) ||
      ((modello_completo_B.SFunction_o7[0] == 3) &&
       (modello_completo_B.SFunction_o7[1] == 250))) {
    memset(&modello_completo_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    modello_completo_DW.WP_dbP_AL_not_empty = true;
  }

  modello_completo_B.GC_info[0] = modello_completo_B.SFunction_o7[0];
  modello_completo_B.GC_info[1] = modello_completo_B.SFunction_o7[1];
  modello_completo_B.GC_info[2] = modello_completo_B.SFunction_o11[0];
  if (modello_completo_B.GC_info[0] == 1) {
    if ((modello_completo_B.GC_info[1] > 0) && (modello_completo_B.GC_info[1] <=
         7)) {
      if ((real32_T)fabs(modello_completo_B.SFunction_o8) > 0.0F) {
        modello_completo_DW.riferimenti[modello_completo_B.GC_info[1] - 1] =
          1.0F;
      } else {
        if (modello_completo_B.SFunction_o8 == 0.0F) {
          modello_completo_DW.riferimenti[modello_completo_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((modello_completo_B.GC_info[1] > 7) && (modello_completo_B.GC_info[1] <
           12)) {
        modello_completo_DW.riferimenti[modello_completo_B.GC_info[1] - 1] =
          modello_completo_B.SFunction_o8;
      }
    }
  }

  if (modello_completo_B.SFunction_o12 == 13) {
    modello_completo_DW.riferimenti[modello_completo_B.SFunction_o12 - 1] =
      modello_completo_B.SFunction_o13;
  }

  memcpy(&modello_completo_B.Val_out_MAV[0], &modello_completo_DW.riferimenti[0],
         sizeof(real32_T) << 4U);
  if ((modello_completo_B.GC_info[0] == 3) && (modello_completo_B.GC_info[1] ==
       200)) {
    if (modello_completo_B.SFunction_o9[0] > 6) {
      modello_completo_B.WP_info_in[0] = 6U;
    }

    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 6;
         modello_completo_B.ATO++) {
      modello_completo_DW.WP_dbI[modello_completo_B.ATO] =
        modello_completo_B.WP_info_in[0];
    }
  }

  if ((modello_completo_B.GC_info[0] == 3) && (modello_completo_B.GC_info[1] <
       200)) {
    if (modello_completo_B.SFunction_o10[1] == 0.0F) {
      modello_completo_B.qY = modello_completo_B.SFunction_o9[1] + 1U;
      if (modello_completo_B.SFunction_o9[1] + 1U > 65535U) {
        modello_completo_B.qY = 65535U;
      }

      for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 7;
           modello_completo_B.ATO++) {
        modello_completo_DW.WP_dbP[((int32_T)modello_completo_B.qY + 6 *
          modello_completo_B.ATO) - 1] =
          modello_completo_B.SFunction_o10[modello_completo_B.ATO];
      }

      modello_completo_B.qY = modello_completo_B.SFunction_o9[1] + 1U;
      if (modello_completo_B.SFunction_o9[1] + 1U > 65535U) {
        modello_completo_B.qY = 65535U;
      }

      for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 6;
           modello_completo_B.ATO++) {
        modello_completo_DW.WP_dbI[((int32_T)modello_completo_B.qY + 6 *
          (modello_completo_B.ATO + 1)) - 1] =
          modello_completo_B.WP_info_in[modello_completo_B.ATO + 1];
      }
    } else {
      modello_completo_B.ATO = (int32_T)(modello_completo_B.SFunction_o10[0] +
        1.0F);
      for (modello_completo_B.g = 0; modello_completo_B.g < 7;
           modello_completo_B.g++) {
        modello_completo_DW.WP_dbP_AL[(modello_completo_B.ATO + 6 *
          modello_completo_B.g) - 1] =
          modello_completo_B.SFunction_o10[modello_completo_B.g];
      }

      modello_completo_B.qY = modello_completo_B.SFunction_o9[1] + 1U;
      if (modello_completo_B.SFunction_o9[1] + 1U > 65535U) {
        modello_completo_B.qY = 65535U;
      }

      for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 6;
           modello_completo_B.ATO++) {
        modello_completo_DW.WP_dbI[((int32_T)modello_completo_B.qY + 6 *
          (modello_completo_B.ATO + 1)) - 1] =
          modello_completo_B.WP_info_in[modello_completo_B.ATO + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  modello_completo_DW.Memory3_PreviousInput_o = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((modello_completo_B.SFunction_o6 == 0) &&
      (modello_completo_B.SFunction_o3_j == 0)) {
    modello_completo_DW.Memory1_PreviousInput_d[0] = 0U;
    modello_completo_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    modello_completo_DW.Memory3_PreviousInput_o = 0U;
  } else if ((modello_completo_B.SFunction_o6 == 0) &&
             (modello_completo_B.SFunction_o3_j == 3)) {
    modello_completo_DW.Memory1_PreviousInput_d[0] = 0U;
    modello_completo_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    modello_completo_DW.Memory3_PreviousInput_o = 0U;
    modello_completo_DW.test1 = 0.0;
  } else if ((modello_completo_B.SFunction_o6 == 0) &&
             (modello_completo_B.SFunction_o3_j == 2)) {
    modello_completo_DW.Memory1_PreviousInput_d[0] = 0U;
    modello_completo_DW.Memory1_PreviousInput_d[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    modello_completo_DW.Memory3_PreviousInput_o = 0U;
    modello_completo_DW.test1 = 0.0;
  } else if ((modello_completo_B.SFunction_o6 == 0) &&
             (modello_completo_B.SFunction_o3_j == 1)) {
    modello_completo_DW.Memory1_PreviousInput_d[0] = 0U;
    modello_completo_DW.Memory1_PreviousInput_d[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    modello_completo_DW.Memory3_PreviousInput_o = 0U;
    modello_completo_DW.test1 = 1.0;
  } else {
    switch (modello_completo_B.SFunction_o6) {
     case 192:
      modello_completo_DW.Memory1_PreviousInput_d[0] = 192U;
      modello_completo_DW.Memory1_PreviousInput_d[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      modello_completo_DW.Memory3_PreviousInput_o = 192U;
      break;

     case 208:
      modello_completo_DW.Memory1_PreviousInput_d[0] = 208U;
      modello_completo_DW.Memory1_PreviousInput_d[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      modello_completo_DW.Memory3_PreviousInput_o = 208U;
      break;

     default:
      if ((modello_completo_B.SFunction_o6 == 220) &&
          (modello_completo_B.SFunction_o3_j != 5)) {
        if ((modello_completo_DW.Memory2_PreviousInput_a[0] == 0) &&
            (modello_completo_DW.Memory2_PreviousInput_a[1] == 0) &&
            ((modello_completo_DW.Memory2_PreviousInput_a[2] == 1) ||
             (modello_completo_DW.Memory2_PreviousInput_a[3] == 1) ||
             (modello_completo_DW.Memory2_PreviousInput_a[4] == 1) ||
             (modello_completo_DW.Memory2_PreviousInput_a[5] == 1) ||
             (modello_completo_DW.Memory2_PreviousInput_a[6] == 1) ||
             (modello_completo_DW.Memory2_PreviousInput_a[7] == 1))) {
          modello_completo_DW.Memory1_PreviousInput_d[0] = 220U;
          modello_completo_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          modello_completo_DW.Memory3_PreviousInput_o = 220U;
        } else if ((modello_completo_DW.Memory2_PreviousInput_a[0] == 0) &&
                   (modello_completo_DW.Memory2_PreviousInput_a[1] == 1) &&
                   ((modello_completo_DW.Memory2_PreviousInput_a[2] == 1) ||
                    (modello_completo_DW.Memory2_PreviousInput_a[3] == 1) ||
                    (modello_completo_DW.Memory2_PreviousInput_a[4] == 1) ||
                    (modello_completo_DW.Memory2_PreviousInput_a[5] == 1) ||
                    (modello_completo_DW.Memory2_PreviousInput_a[6] == 1) ||
                    (modello_completo_DW.Memory2_PreviousInput_a[7] == 1))) {
          modello_completo_DW.Memory1_PreviousInput_d[0] = 220U;
          modello_completo_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          modello_completo_DW.Memory3_PreviousInput_o = 220U;
        } else {
          modello_completo_DW.Memory1_PreviousInput_d[0] = 208U;
          modello_completo_DW.Memory1_PreviousInput_d[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          modello_completo_DW.Memory3_PreviousInput_o = 208U;
        }
      } else if (modello_completo_B.SFunction_o3_j == 5) {
        modello_completo_DW.Memory1_PreviousInput_d[0] = 220U;
        modello_completo_DW.Memory1_PreviousInput_d[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        modello_completo_DW.Memory1_PreviousInput_d[0] = 192U;
        modello_completo_DW.Memory1_PreviousInput_d[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  modello_completo_B.qY = 100U * modello_completo_B.SFunction_o11[5];
  if (modello_completo_B.qY > 65535U) {
    modello_completo_B.qY = 65535U;
  }

  if (modello_completo_B.SFunction_o11[4] == 0) {
    if ((uint16_T)modello_completo_B.qY == 0) {
      modello_completo_B.z = 0U;
    } else {
      modello_completo_B.z = MAX_uint16_T;
    }
  } else {
    modello_completo_B.z = (uint16_T)(modello_completo_B.SFunction_o11[4] == 0U ?
      MAX_uint32_T : (uint32_T)(uint16_T)modello_completo_B.qY /
      modello_completo_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)modello_completo_B.qY - (uint16_T)
                   ((uint32_T)modello_completo_B.z *
                    modello_completo_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)modello_completo_B.SFunction_o11[4]
          >> 1) + (modello_completo_B.SFunction_o11[4] & 1))) {
      modello_completo_B.z++;
    }
  }

  modello_completo_DW.Memory2_PreviousInput_a[0] = (uint8_T)AP_mode_idx_0;
  modello_completo_DW.Memory2_PreviousInput_a[1] = (uint8_T)AP_mode_idx_1;
  for (modello_completo_B.i = 0; modello_completo_B.i < 7; modello_completo_B.i
       ++) {
    modello_completo_B.f = rt_roundf_snf
      (modello_completo_DW.riferimenti[modello_completo_B.i]);
    if (modello_completo_B.f < 256.0F) {
      if (modello_completo_B.f >= 0.0F) {
        modello_completo_DW.Memory2_PreviousInput_a[modello_completo_B.i + 2] =
          (uint8_T)modello_completo_B.f;
      } else {
        modello_completo_DW.Memory2_PreviousInput_a[modello_completo_B.i + 2] =
          0U;
      }
    } else {
      modello_completo_DW.Memory2_PreviousInput_a[modello_completo_B.i + 2] =
        MAX_uint8_T;
    }
  }

  /* Outputs for Enabled SubSystem: '<S575>/Subsystem1' incorporates:
   *  EnablePort: '<S577>/Enable'
   */
  if (modello_completo_B.SFunction_o14 > 0) {
    /* Inport: '<S577>/T' */
    modello_completo_B.T = modello_completo_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S575>/Subsystem1' */

  /* Switch: '<S575>/Switch1' incorporates:
   *  Constant: '<S575>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  RelationalOperator: '<S575>/NotEqual'
   *  Switch: '<S575>/Switch'
   */
  if (modello_completo_P.Constant_Value_hx != modello_completo_DW.riferimenti[12])
  {
    /* Switch: '<S575>/Switch1' */
    modello_completo_B.Switch1 = modello_completo_DW.riferimenti[12];
  } else if (modello_completo_B.T > modello_completo_P.Switch_Threshold_p) {
    /* Switch: '<S575>/Switch' incorporates:
     *  Switch: '<S575>/Switch1'
     */
    modello_completo_B.Switch1 = modello_completo_B.T;
  } else {
    /* Switch: '<S575>/Switch1' */
    modello_completo_B.Switch1 = modello_completo_DW.riferimenti[12];
  }

  /* End of Switch: '<S575>/Switch1' */

  /* RateTransition: '<S27>/Rate Transition' */
  modello_completo_B.RateTransition = modello_completo_DW.RateTransition_Buffer0;

  /* Sum: '<S27>/Add1' incorporates:
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Memory: '<S27>/Memory1'
   */
  modello_completo_B.num_254 = (modello_completo_P.Constant2_Value_jg +
    modello_completo_P.Constant3_Value_o) +
    modello_completo_DW.Memory1_PreviousInput;

  /* Switch: '<S27>/Switch' */
  if (modello_completo_B.num_254 > modello_completo_P.Switch_Threshold_f) {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    modello_completo_DW.Memory1_PreviousInput =
      modello_completo_P.Constant2_Value_jg;
  } else {
    /* Switch: '<S27>/Switch' */
    modello_completo_DW.Memory1_PreviousInput = modello_completo_B.num_254;
  }

  /* End of Switch: '<S27>/Switch' */

  /* MATLAB Function: '<S19>/iflogic_function' */
  if ((modello_completo_DW.Memory1_PreviousInput == 1.0) ||
      (modello_completo_DW.Memory1_PreviousInput == 3.0)) {
    modello_completo_B.iflogic = 26U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 2.0) ||
             (modello_completo_DW.Memory1_PreviousInput == 4.0)) {
    modello_completo_B.iflogic = 30U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             (modello_completo_B.RateTransition == 2.0)) {
    modello_completo_B.iflogic = 33U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             (modello_completo_B.RateTransition == 6.0)) {
    modello_completo_B.iflogic = 34U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             (modello_completo_B.RateTransition == 0.0)) {
    modello_completo_B.iflogic = 0U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             ((modello_completo_B.RateTransition == 1.0) ||
              (modello_completo_B.RateTransition == 5.0) ||
              (modello_completo_B.RateTransition == 9.0))) {
    modello_completo_B.iflogic = 1U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             ((modello_completo_B.RateTransition == 3.0) ||
              (modello_completo_B.RateTransition == 8.0))) {
    modello_completo_B.iflogic = 74U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             (modello_completo_B.RateTransition == 7.0)) {
    modello_completo_B.iflogic = 36U;
  } else if ((modello_completo_DW.Memory1_PreviousInput == 0.0) &&
             (modello_completo_B.RateTransition == 4.0)) {
    modello_completo_B.iflogic = 29U;
  } else {
    modello_completo_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S19>/iflogic_function' */

  /* Sum: '<S27>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Memory: '<S27>/Memory'
   */
  modello_completo_DW.Memory_PreviousInput +=
    modello_completo_P.Constant_Value_m + modello_completo_P.Constant1_Value_n;

  /* Gain: '<S19>/Gain' */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_c *
    modello_completo_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  modello_completo_B.DataTypeConversion3 = modello_completo_B.deltafalllimit <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-modello_completo_B.deltafalllimit :
    (uint32_T)modello_completo_B.deltafalllimit;

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 6;
       modello_completo_B.ATO++) {
    modello_completo_B.WP_info[modello_completo_B.ATO] =
      modello_completo_DW.WP_dbI[6 * modello_completo_B.ATO];
  }

  for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 7;
       modello_completo_B.ATO++) {
    modello_completo_B.WP_param[modello_completo_B.ATO] =
      modello_completo_DW.WP_dbP[6 * modello_completo_B.ATO];
  }

  if ((modello_completo_B.GC_info[0] == 2) && (modello_completo_B.GC_info[1] < 6))
  {
    modello_completo_B.qY = modello_completo_B.GC_info[1] + 1U;
    if (modello_completo_B.GC_info[1] + 1U > 65535U) {
      modello_completo_B.qY = 65535U;
    }

    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 6;
         modello_completo_B.ATO++) {
      modello_completo_B.WP_info[modello_completo_B.ATO] =
        modello_completo_DW.WP_dbI[(6 * modello_completo_B.ATO + (int32_T)
        modello_completo_B.qY) - 1];
    }

    modello_completo_B.qY = modello_completo_B.GC_info[1] + 1U;
    if (modello_completo_B.GC_info[1] + 1U > 65535U) {
      modello_completo_B.qY = 65535U;
    }

    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 7;
         modello_completo_B.ATO++) {
      modello_completo_B.WP_param[modello_completo_B.ATO] =
        modello_completo_DW.WP_dbP[(6 * modello_completo_B.ATO + (int32_T)
        modello_completo_B.qY) - 1];
    }
  }

  if ((modello_completo_B.GC_info[0] == 3) && (modello_completo_B.GC_info[1] <
       200)) {
    modello_completo_B.qY = modello_completo_B.GC_info[1] + 1U;
    if (modello_completo_B.GC_info[1] + 1U > 65535U) {
      modello_completo_B.qY = 65535U;
    }

    for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 6;
         modello_completo_B.ATO++) {
      modello_completo_B.WP_info[modello_completo_B.ATO] =
        modello_completo_DW.WP_dbI[(6 * modello_completo_B.ATO + (int32_T)
        modello_completo_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function' */

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S7>/Constant'
   */
  modello_completo_B.deltafalllimit = floor(modello_completo_P.Gain_Gain_by *
    modello_completo_P.Constant_Value_jp[0]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* Outputs for Resettable SubSystem: '<S409>/Resettable Subsystem' */
  modello_completo_B.IProdOut = modello_ResettableSubsystem
    (modello_completo_B.SFunction_o4_n[0],
     &modello_completo_DW.ResettableSubsystem_o,
     &modello_completo_P.ResettableSubsystem_o,
     &modello_completo_PrevZCX.ResettableSubsystem_o);

  /* End of Outputs for SubSystem: '<S409>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S409>/Enabled Subsystem' */
  modello_co_EnabledSubsystem(modello_completo_B.SFunction_o4_n[0],
    modello_completo_B.IProdOut, &modello_completo_B.Switch_l,
    &modello_completo_P.EnabledSubsystem_j);

  /* End of Outputs for SubSystem: '<S409>/Enabled Subsystem' */

  /* MATLAB Function: '<S563>/MATLAB Function' incorporates:
   *  Constant: '<S554>/Constant'
   *  Constant: '<S563>/Constant'
   */
  modello_completo_B.num_254 = modello_completo_P.Constant_Value_k *
    modello_completo_P.Constant_Value_p;
  modello_completo_B.RateTransition = modello_completo_B.num_254 /
    (modello_completo_B.num_254 + 1.0);

  /* MATLABSystem: '<S554>/Serial Receive' */
  if (modello_completo_DW.obj_m.Protocol !=
      modello_completo_P.SerialReceive_Protocol) {
    modello_completo_DW.obj_m.Protocol =
      modello_completo_P.SerialReceive_Protocol;
  }

  MW_Serial_read(1, modello_completo_DW.obj_m.DataSizeInBytes,
                 &modello_completo_B.b_dataOut_c[0], &status);

  /* Outputs for Enabled SubSystem: '<S554>/Subsystem1' incorporates:
   *  EnablePort: '<S562>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S562>/MATLAB Function' */
    for (modello_completo_B.i = 0; modello_completo_B.i < 31;
         modello_completo_B.i++) {
      modello_completo_B.messaggio[modello_completo_B.i] = 0U;
    }

    guard1 = false;
    if (!modello_completo_DW.start_found_c) {
      modello_completo_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (modello_completo_B.i - 1 < 30)) {
        if ((modello_completo_B.b_dataOut_c[(uint8_T)modello_completo_B.i - 1] ==
             255) && (modello_completo_B.b_dataOut_c[(uint8_T)
                      modello_completo_B.i] == 254)) {
          modello_completo_B.caso = 31 - (uint8_T)modello_completo_B.i;
          for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
               modello_completo_B.caso; modello_completo_B.ATO++) {
            modello_completo_DW.message_k[modello_completo_B.ATO] =
              modello_completo_B.b_dataOut_c[((uint8_T)modello_completo_B.i +
              modello_completo_B.ATO) - 1];
          }

          modello_completo_DW.counter_n = (uint8_T)(32 - (uint8_T)
            modello_completo_B.i);
          modello_completo_DW.start_found_c = true;
          exitg1 = true;
        } else {
          modello_completo_B.i++;
        }
      }

      if (modello_completo_DW.counter_n == 31) {
        for (modello_completo_B.i = 0; modello_completo_B.i < 31;
             modello_completo_B.i++) {
          modello_completo_B.messaggio[modello_completo_B.i] =
            modello_completo_DW.message_k[modello_completo_B.i];
          modello_completo_DW.message_k[modello_completo_B.i] = 0U;
        }

        modello_completo_DW.start_found_c = false;
        modello_completo_DW.counter_n = 0U;
        guard1 = true;
      }
    } else {
      modello_completo_B.qY = 31U - /*MW:OvSatOk*/ modello_completo_DW.counter_n;
      if (31U - modello_completo_DW.counter_n > 31U) {
        modello_completo_B.qY = 0U;
      }

      modello_completo_B.ATO = (int32_T)(modello_completo_DW.counter_n + 1U);
      if (modello_completo_DW.counter_n + 1U > 255U) {
        modello_completo_B.ATO = 255;
      }

      if ((uint8_T)modello_completo_B.ATO > 31) {
        modello_completo_B.i = 1;
      } else {
        modello_completo_B.i = (uint8_T)modello_completo_B.ATO;
      }

      if (1 > (uint8_T)modello_completo_B.qY) {
        modello_completo_B.caso = -1;
      } else {
        modello_completo_B.caso = (uint8_T)modello_completo_B.qY - 1;
      }

      for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
           modello_completo_B.caso; modello_completo_B.ATO++) {
        modello_completo_DW.message_k[(modello_completo_B.i +
          modello_completo_B.ATO) - 1] =
          modello_completo_B.b_dataOut_c[modello_completo_B.ATO];
      }

      modello_completo_B.qY = 31U - /*MW:OvSatOk*/ modello_completo_DW.counter_n;
      if (31U - modello_completo_DW.counter_n > 31U) {
        modello_completo_B.qY = 0U;
      }

      modello_completo_DW.counter_n = (uint8_T)modello_completo_B.qY;
      for (modello_completo_B.i = 0; modello_completo_B.i < 31;
           modello_completo_B.i++) {
        modello_completo_B.messaggio[modello_completo_B.i] =
          modello_completo_DW.message_k[modello_completo_B.i];
        modello_completo_DW.message_k[modello_completo_B.i] = 0U;
      }

      status = modello_completo_DW.counter_n;
      do {
        exitg3 = 0;
        if (status < 31) {
          if ((modello_completo_B.b_dataOut_c[status - 1] == 255) &&
              (modello_completo_B.b_dataOut_c[status] == 254)) {
            modello_completo_B.caso = 31 - status;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
                 modello_completo_B.caso; modello_completo_B.ATO++) {
              modello_completo_DW.message_k[modello_completo_B.ATO] =
                modello_completo_B.b_dataOut_c[(status + modello_completo_B.ATO)
                - 1];
            }

            modello_completo_B.qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              modello_completo_B.qY = 0U;
            }

            modello_completo_DW.counter_n = (uint8_T)(31 - (int32_T)
              modello_completo_B.qY);
            modello_completo_DW.start_found_c = true;
            guard1 = true;
            exitg3 = 1;
          } else {
            modello_completo_DW.start_found_c = false;
            modello_completo_DW.counter_n = 0U;
            status++;
          }
        } else {
          guard1 = true;
          exitg3 = 1;
        }
      } while (exitg3 == 0);
    }

    if (guard1) {
      /* Outputs for Enabled SubSystem: '<S562>/Subsystem2' incorporates:
       *  EnablePort: '<S566>/Enable'
       */
      /* S-Function (byte2any_svd): '<S566>/Byte Unpack' */

      /* Unpack: <S566>/Byte Unpack */
      {
        uint32_T MW_inputPortOffset = 0;
        uint32_T MW_outputPortWidth = 0;
        uint32_T MW_remainder2 = 0;

        /* Packed input data type - uint8_T */
        /* Unpacking the values to output 1 */
        /* Output data type - uint8_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint8_T);
          memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o1_o[0], (uint8_T*)
                 &modello_completo_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o2_e[0], (uint8_T*)
                 &modello_completo_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o3[0], (uint8_T*)
                 &modello_completo_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o4[0], (uint8_T*)
                 &modello_completo_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&modello_completo_B.ByteUnpack_o5, (uint8_T*)
                 &modello_completo_B.messaggio[0] + MW_inputPortOffset,
                 MW_outputPortWidth);
        }
      }

      /* End of Outputs for SubSystem: '<S562>/Subsystem2' */
    }

    /* End of MATLAB Function: '<S562>/MATLAB Function' */
  }

  /* End of MATLABSystem: '<S554>/Serial Receive' */
  /* End of Outputs for SubSystem: '<S554>/Subsystem1' */

  /* Gain: '<S554>/Gain1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion2'
   */
  modello_completo_B.rtb_Gain1_kw_idx_0 = modello_completo_P.Gain1_Gain_p *
    (real_T)modello_completo_B.ByteUnpack_o3[0];
  modello_completo_B.rtb_Gain1_kw_idx_1 = modello_completo_P.Gain1_Gain_p *
    (real_T)modello_completo_B.ByteUnpack_o3[1];

  /* Sum: '<S563>/Sum' incorporates:
   *  UnitDelay: '<S563>/Unit Delay'
   */
  modello_completo_B.num_254 = modello_completo_B.rtb_Gain1_kw_idx_1 +
    modello_completo_DW.UnitDelay_DSTATE;

  /* Product: '<S563>/Product1' incorporates:
   *  MATLAB Function: '<S563>/MATLAB Function'
   */
  modello_completo_B.Product1 = modello_completo_B.RateTransition *
    modello_completo_B.num_254;

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  for (modello_completo_B.i = 0; modello_completo_B.i < 9; modello_completo_B.i
       ++) {
    modello_completo_B.DataTypeConversion1_pb[modello_completo_B.i] =
      modello_completo_B.ByteReversal[modello_completo_B.i];
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* Gain: '<S550>/Gain1' */
  modello_completo_B.Gain1_j = modello_completo_P.Gain1_Gain_m *
    modello_completo_B.DataTypeConversion1_pb[6];

  /* MATLAB Function: '<S415>/MATLAB Function1' */
  guard1 = false;
  if (modello_completo_DW.Memory2_PreviousInput_a[1] == 1) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     */
    if (modello_completo_B.Switch_l != 0.0) {
      modello_completo_B.Sum3_o = modello_completo_P.Constant_Value_i;
    } else {
      modello_completo_B.Sum3_o = modello_completo_B.Product1;
    }

    /* End of Switch: '<S38>/Switch' */
    if (modello_completo_B.Sum3_o > modello_completo_P.safe_V) {
      modello_completo_DW.alarm = 1.0;
    } else if (fabs(modello_completo_P.Gain_Gain_mz * modello_completo_B.Gain1_j)
               > modello_completo_P.safe_phi) {
      modello_completo_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (modello_completo_DW.Memory2_PreviousInput_a[0] == 1) {
      modello_completo_DW.alarm = 0.0;
    }
  }

  /* Outputs for Resettable SubSystem: '<S432>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S435>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &modello_completo_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (modello_completo_DW.alarm)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S436>/Sum' incorporates:
     *  Memory: '<S436>/Memory'
     */
    modello_completo_DW.Memory_PreviousInput_h =
      modello_completo_P.Memory_InitialCondition;
  }

  /* Sum: '<S436>/Sum' incorporates:
   *  Constant: '<S436>/Constant4'
   *  Memory: '<S436>/Memory'
   */
  modello_completo_DW.Memory_PreviousInput_h += modello_completo_P.t_AP;

  /* End of Outputs for SubSystem: '<S432>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S432>/Enabled ' incorporates:
   *  EnablePort: '<S434>/Enable'
   */
  /* MATLAB Function: '<S415>/MATLAB Function1' */
  if (modello_completo_DW.alarm > 0.0) {
    modello_completo_DW.Enabled_MODE = true;

    /* Switch: '<S434>/Switch' */
    if (modello_completo_DW.Memory_PreviousInput_h >
        modello_completo_P.time_alarm_SAFE) {
      /* Switch: '<S434>/Switch' incorporates:
       *  Constant: '<S434>/Constant'
       */
      modello_completo_B.Switch_n = modello_completo_P.Constant_Value;
    } else {
      /* Switch: '<S434>/Switch' incorporates:
       *  Constant: '<S434>/Constant1'
       */
      modello_completo_B.Switch_n = modello_completo_P.Constant1_Value;
    }

    /* End of Switch: '<S434>/Switch' */
  } else {
    if (modello_completo_DW.Enabled_MODE) {
      /* Disable for Switch: '<S434>/Switch' incorporates:
       *  Outport: '<S434>/Alarm Safe'
       */
      modello_completo_B.Switch_n = modello_completo_P.AlarmSafe_Y0;
      modello_completo_DW.Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S432>/Enabled ' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/load uint16'
   *  Gain: '<S21>/Gain'
   */
  modello_completo_B.TmpSignalConversionAtSFunctionI[0] =
    modello_completo_P.loaduint16_Value;
  modello_completo_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  modello_completo_B.qY = 10U * modello_completo_B.z;
  if (modello_completo_B.qY > 65535U) {
    modello_completo_B.qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  modello_completo_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)
    modello_completo_B.qY;
  modello_completo_B.TmpSignalConversionAtSFunctionI[3] =
    modello_completo_B.SFunction_o11[6];
  modello_completo_B.TmpSignalConversionAtSFunctionI[4] =
    modello_completo_B.SFunction_o11[2];
  modello_completo_B.TmpSignalConversionAtSFunctionI[5] =
    modello_completo_P._Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  modello_completo_B.deltafalllimit = floor(modello_completo_B.Switch_n);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  modello_completo_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S21>/Data Type Conversion4' incorporates:
   *  Constant: '<S38>/Constant2'
   */
  modello_completo_B.deltafalllimit = floor(modello_completo_P.Constant2_Value_k);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  modello_completo_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S21>/Gain2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  modello_completo_B.deltafalllimit = floor(modello_completo_P.Gain2_Gain *
    modello_completo_P.Constant_Value_jp[2]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Gain: '<S21>/Gain2'
   */
  modello_completo_B.Gain1 = (int16_T)(((modello_completo_B.deltafalllimit < 0.0
    ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.deltafalllimit :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.deltafalllimit) *
    modello_completo_P.Gain1_Gain_eu) >> 18);

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  modello_completo_B.deltafalllimit = floor
    (modello_completo_P.Constant_Value_jp[1]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      256.0);
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion3' */
  modello_completo_B.B_Remaining = (int8_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-modello_completo_B.deltafalllimit :
    (int32_T)(int8_T)(uint8_T)modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   */
  modello_completo_B.deltafalllimit = floor(modello_completo_P.Constant_Value_e);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion = modello_completo_B.deltafalllimit <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-modello_completo_B.deltafalllimit :
    (uint32_T)modello_completo_B.deltafalllimit;

  /* MATLAB Function: '<S17>/Alarm set' incorporates:
   *  Constant: '<S38>/Constant2'
   *  SignalConversion generated from: '<S26>/ SFunction '
   */
  rtb_H_mav[0] = modello_completo_DW.Memory1_PreviousInput_d[0];
  rtb_H_mav[1] = modello_completo_DW.Memory1_PreviousInput_d[1];
  if (modello_completo_B.Switch_n == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (modello_completo_P.Constant2_Value_k == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S17>/Alarm set' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S17>/Type fixed_wing Autopilot generic'
   */
  modello_completo_B.TmpSignalConversionAtSFunctio_m[0] =
    modello_completo_P.Typefixed_wingAutopilotgeneric_[0];
  modello_completo_B.TmpSignalConversionAtSFunctio_m[2] = rtb_H_mav[0];
  modello_completo_B.TmpSignalConversionAtSFunctio_m[1] =
    modello_completo_P.Typefixed_wingAutopilotgeneric_[1];
  modello_completo_B.TmpSignalConversionAtSFunctio_m[3] = rtb_H_mav[1];
  for (modello_completo_B.i = 0; modello_completo_B.i < 6; modello_completo_B.i
       ++) {
    /* Gain: '<S18>/Gain' */
    modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_dn *
      modello_completo_B.DataTypeConversion1_pb[modello_completo_B.i];

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    if (modello_completo_B.deltafalllimit < 0.0) {
      modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
    } else {
      modello_completo_B.deltafalllimit = floor
        (modello_completo_B.deltafalllimit);
    }

    if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
        (modello_completo_B.deltafalllimit)) {
      modello_completo_B.deltafalllimit = 0.0;
    } else {
      modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
        65536.0);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    modello_completo_B.DataTypeConversion_ld[modello_completo_B.i] = (int16_T)
      (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
       (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)
       (uint16_T)modello_completo_B.deltafalllimit);
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_dn *
    modello_completo_P.Constant_Value_hxg;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_ld[6] = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_dn *
    modello_completo_P.Constant1_Value_f;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_ld[7] = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_dn *
    modello_completo_P.Constant2_Value_e;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_ld[8] = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S551>/Gain1' */
  modello_completo_B.Gain1_c = modello_completo_P.Gain1_Gain_l *
    modello_completo_B.DataTypeConversion1_pb[7];

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Gain: '<S552>/Gain1'
   */
  modello_completo_B.DataTypeConversion1[0] = (real32_T)
    modello_completo_B.Gain1_j;
  modello_completo_B.DataTypeConversion1[1] = (real32_T)
    modello_completo_B.Gain1_c;
  modello_completo_B.DataTypeConversion1[2] = (real32_T)
    (modello_completo_P.Gain1_Gain_i *
     modello_completo_B.DataTypeConversion1_pb[8]);
  modello_completo_B.DataTypeConversion1[3] = (real32_T)
    modello_completo_B.DataTypeConversion1_pb[3];
  modello_completo_B.DataTypeConversion1[4] = (real32_T)
    modello_completo_B.DataTypeConversion1_pb[4];
  modello_completo_B.DataTypeConversion1[5] = (real32_T)
    modello_completo_B.DataTypeConversion1_pb[5];

  /* Gain: '<S555>/Gain1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   */
  modello_completo_B.Gain1_f = modello_completo_P.Gain1_Gain_d *
    modello_completo_B.ByteUnpack_o2_e[0];

  /* Gain: '<S556>/Gain1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   */
  modello_completo_B.Gain1_p = modello_completo_P.Gain1_Gain_n *
    modello_completo_B.ByteUnpack_o2_e[1];

  /* Gain: '<S16>/Gain' */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_bx[0] *
    modello_completo_B.Gain1_f;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_a[0] = modello_completo_B.deltafalllimit
    < 0.0 ? -(int32_T)(uint32_T)-modello_completo_B.deltafalllimit : (int32_T)
    (uint32_T)modello_completo_B.deltafalllimit;

  /* Gain: '<S16>/Gain' */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_bx[1] *
    modello_completo_B.Gain1_p;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_a[1] = modello_completo_B.deltafalllimit
    < 0.0 ? -(int32_T)(uint32_T)-modello_completo_B.deltafalllimit : (int32_T)
    (uint32_T)modello_completo_B.deltafalllimit;

  /* Gain: '<S16>/Gain' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_bx[2] *
    modello_completo_B.ByteUnpack_o2_e[2];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_a[2] = modello_completo_B.deltafalllimit
    < 0.0 ? -(int32_T)(uint32_T)-modello_completo_B.deltafalllimit : (int32_T)
    (uint32_T)modello_completo_B.deltafalllimit;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/alt_r'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain_Gain_bx[3] *
    modello_completo_P.alt_r_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_a[3] = modello_completo_B.deltafalllimit
    < 0.0 ? -(int32_T)(uint32_T)-modello_completo_B.deltafalllimit : (int32_T)
    (uint32_T)modello_completo_B.deltafalllimit;

  /* Gain: '<S554>/Gain4' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion3'
   */
  modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_P.Gain4_Gain * (real_T)
    modello_completo_B.ByteUnpack_o4[0];

  /* Gain: '<S16>/Gain1' */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain1_Gain_e *
    modello_completo_B.rtb_Gain1_i_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_p[0] = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S16>/Gain1' incorporates:
   *  Constant: '<S16>/vel y'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain1_Gain_e *
    modello_completo_P.vely_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_p[1] = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S16>/Gain1' */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain1_Gain_e *
    modello_completo_B.rtb_Gain1_kw_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_p[2] = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* Gain: '<S553>/Gain1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   *  Gain: '<S557>/Gain1'
   */
  modello_completo_B.Gain1_kx = modello_completo_P.Gain1_Gain_b *
    modello_completo_B.ByteUnpack_o2_e[3] * modello_completo_P.Gain1_Gain_n1;

  /* Gain: '<S16>/Gain2' */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain2_Gain_k *
    modello_completo_B.Gain1_kx;

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  modello_completo_B.DataTypeConversion2_h = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Constant: '<S22>/airspeed groundspeed alt climb1'
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   */
  modello_completo_B.AGAC[0] = (real32_T)modello_completo_B.Product1;
  modello_completo_B.AGAC[1] = (real32_T)
    modello_completo_P.airspeedgroundspeedaltclimb1_Va;
  modello_completo_B.AGAC[2] = modello_completo_B.ByteUnpack_o2_e[2];
  modello_completo_B.AGAC[3] = (real32_T)modello_completo_B.rtb_Gain1_kw_idx_0;

  /* Gain: '<S33>/Gain' */
  modello_completo_B.Gain_o = modello_completo_P.Gain_Gain_l *
    modello_completo_B.Gain1_kx;

  /* Switch: '<S34>/Switch2' incorporates:
   *  Abs: '<S34>/Abs'
   *  Constant: '<S34>/Constant2'
   *  Sum: '<S34>/Sum'
   */
  if (!(modello_completo_B.Gain_o > modello_completo_P.Switch2_Threshold_a)) {
    modello_completo_B.Gain_o = modello_completo_P.Constant2_Value - fabs
      (modello_completo_B.Gain_o);
  }

  /* End of Switch: '<S34>/Switch2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  if (modello_completo_B.Gain_o < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.Gain_o);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.Gain_o);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  modello_completo_B.Heading_g = (int16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* Gain: '<S22>/USCITA PERCENTUALE' incorporates:
   *  Constant: '<S6>/Constant'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.USCITAPERCENTUALE_Gain *
    modello_completo_P.Constant_Value_c;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  modello_completo_B.Throttle = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* S-Function (PWMinterrupt_throttle_v4_4): '<S9>/S-Function Builder6' */
  PWMinterrupt_throttle_v4_4_Outputs_wrapper(&modello_completo_B.PWM_throttle);

  /* Product: '<S588>/Divide2' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   *  Product: '<S591>/Multiply'
   *  Sum: '<S588>/Sum3'
   */
  modello_completo_B.rtb_Gain1_kw_idx_0 =
    modello_completo_B.One_time_initialization.ByteUnpack[0] -
    modello_completo_B.One_time_initialization.ByteUnpack[1];

  /* Sum: '<S588>/Sum5' incorporates:
   *  Constant: '<S588>/manetta_massima'
   *  Constant: '<S588>/manetta_minima'
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   *  Product: '<S588>/Divide2'
   *  Product: '<S588>/Multiply1'
   *  Sum: '<S588>/Sum2'
   *  Sum: '<S588>/Sum4'
   */
  modello_completo_B.Gain1_kx = (real_T)(modello_completo_B.PWM_throttle -
    modello_completo_B.One_time_initialization.ByteUnpack[1]) /
    modello_completo_B.rtb_Gain1_kw_idx_0 * (modello_completo_P.attuatore_Tmax -
    modello_completo_P.attuatore_Tmin) + modello_completo_P.attuatore_Tmin;

  /* Gain: '<S29>/Gain2' */
  modello_completo_B.Gain_o = modello_completo_P.Gain2_Gain_j *
    modello_completo_B.Gain1_kx;

  /* S-Function (PWMinterrupt_goHome): '<S9>/S-Function Builder2' */
  PWMinterrupt_goHome_Outputs_wrapper(&modello_completo_B.SFunctionBuilder2);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  if (modello_completo_B.SFunctionBuilder2 >
      modello_completo_P.Switch_Threshold_m) {
    modello_completo_B.Go_Home = modello_completo_P.Constant_Value_b;
  } else {
    modello_completo_B.Go_Home = modello_completo_P.Constant1_Value_js;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<S38>/ STATI' incorporates:
   *  Constant: '<S38>/Constant2'
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  if (modello_completo_DW.is_active_c26_modello_completo == 0U) {
    modello_completo_DW.is_active_c26_modello_completo = 1U;
    modello_completo_DW.is_c26_modello_completo = modello_completo_IN_MANUALE;
  } else {
    switch (modello_completo_DW.is_c26_modello_completo) {
     case modello_completo_IN_AUTOMATICA:
      if (modello_completo_P.Constant2_Value_k == 1.0) {
        modello_completo_DW.is_AUTOMATICA = 0;
        modello_completo_DW.is_c26_modello_completo =
          modello_co_IN_Intervento_Pilota;
      } else if (modello_completo_B.Switch_n == 1.0) {
        modello_completo_DW.is_AUTOMATICA = 0;
        modello_completo_DW.is_c26_modello_completo = modello_completo_IN_Safe;
      } else if (modello_completo_B.Go_Home == 1.0) {
        modello_completo_DW.is_AUTOMATICA = 0;
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_Go_Home;
      } else if (modello_completo_DW.Memory2_PreviousInput_a[1] == 0) {
        modello_completo_DW.is_AUTOMATICA = 0;
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_Stand_By;
      } else if (modello_completo_DW.Memory2_PreviousInput_a[0] == 1) {
        modello_completo_DW.is_AUTOMATICA = 0;
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_MANUALE;
      } else {
        switch (modello_completo_DW.is_AUTOMATICA) {
         case model_IN_ATTERRAGGIO_AUTOMATICO:
          if ((modello_completo_DW.Memory2_PreviousInput_a[8] == 0) &&
              (modello_completo_B.ByteUnpack_o2_e[2] > 20.0F) &&
              (modello_completo_DW.Memory2_PreviousInput_a[6] == 1)) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_WAYPOINT;
          } else if ((modello_completo_DW.Memory2_PreviousInput_a[8] == 0) &&
                     (modello_completo_B.ByteUnpack_o2_e[2] > 20.0F)) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_VETTORIALE;
          } else if ((modello_completo_DW.Memory2_PreviousInput_a[7] == 1) &&
                     (modello_completo_DW.Memory2_PreviousInput_a[8] == 0) &&
                     (modello_completo_B.ByteUnpack_o2_e[2] < 1.0F) &&
                     (modello_completo_B.rtb_Gain1_i_idx_0 < 1.0)) {
            modello_completo_DW.is_AUTOMATICA = modello_c_IN_DECOLLO_AUTOMATICO;
          } else {
            modello_completo_B.modo = 4.0;
            modello_completo_B.switch_manetta = 1.0;
            modello_completo_B.switch_equilibratore = 1.0;
            modello_completo_B.switch_alettoni = 1.0;
            modello_completo_B.switch_timone = 1.0;
          }
          break;

         case modello_c_IN_DECOLLO_AUTOMATICO:
          if ((modello_completo_DW.Memory2_PreviousInput_a[7] == 0) &&
              (modello_completo_B.Product1 >= 1.0) &&
              ((modello_completo_DW.Memory2_PreviousInput_a[3] == 1) ||
               (modello_completo_DW.Memory2_PreviousInput_a[4] == 1) ||
               (modello_completo_DW.Memory2_PreviousInput_a[2] == 1))) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_VETTORIALE;
          } else if ((modello_completo_DW.Memory2_PreviousInput_a[6] == 1) &&
                     (modello_completo_B.ByteUnpack_o2_e[2] > 30.0F)) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_WAYPOINT;
          } else {
            modello_completo_B.modo = 3.0;
            modello_completo_B.switch_manetta = 1.0;
            modello_completo_B.switch_equilibratore = 1.0;
            modello_completo_B.switch_alettoni = 1.0;
            modello_completo_B.switch_timone = 1.0;
          }
          break;

         case modello_completo_IN_TEST:
          if (modello_completo_DW.test1 == 0.0) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_VETTORIALE;
          } else {
            modello_completo_B.switch_manetta = 0.0;
            modello_completo_B.switch_equilibratore = 0.0;
            modello_completo_B.switch_alettoni = 0.0;
            modello_completo_B.switch_timone = 0.0;
          }
          break;

         case modello_completo_IN_VETTORIALE:
          if (modello_completo_DW.test1 == 1.0) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_TEST;
          } else if ((modello_completo_DW.Memory2_PreviousInput_a[7] == 1) &&
                     (modello_completo_B.rtb_Gain1_i_idx_0 < 1.0)) {
            modello_completo_DW.is_AUTOMATICA = modello_c_IN_DECOLLO_AUTOMATICO;
          } else if (modello_completo_DW.Memory2_PreviousInput_a[8] == 1) {
            modello_completo_DW.is_AUTOMATICA = model_IN_ATTERRAGGIO_AUTOMATICO;
          } else if (modello_completo_DW.Memory2_PreviousInput_a[6] == 1) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_WAYPOINT;
          } else {
            modello_completo_B.modo = 2.0;
            modello_completo_B.switch_manetta = 1.0;
            modello_completo_B.switch_equilibratore = 1.0;
            modello_completo_B.switch_alettoni = 1.0;
            modello_completo_B.switch_timone = 1.0;
          }
          break;

         default:
          /* case IN_WAYPOINT: */
          if ((modello_completo_DW.Memory2_PreviousInput_a[6] == 0) &&
              ((modello_completo_DW.Memory2_PreviousInput_a[3] == 1) ||
               (modello_completo_DW.Memory2_PreviousInput_a[4] == 1) ||
               (modello_completo_DW.Memory2_PreviousInput_a[2] == 1) ||
               (modello_completo_DW.Memory2_PreviousInput_a[7] == 1))) {
            modello_completo_DW.is_AUTOMATICA = modello_completo_IN_VETTORIALE;
          } else if (modello_completo_DW.Memory2_PreviousInput_a[8] == 1) {
            modello_completo_DW.is_AUTOMATICA = model_IN_ATTERRAGGIO_AUTOMATICO;
          } else {
            modello_completo_B.modo = 1.0;
            modello_completo_B.switch_manetta = 1.0;
            modello_completo_B.switch_equilibratore = 1.0;
            modello_completo_B.switch_alettoni = 1.0;
            modello_completo_B.switch_timone = 1.0;
          }
          break;
        }
      }
      break;

     case modello_completo_IN_Go_Home:
      if ((modello_completo_B.Go_Home == 0.0) &&
          ((modello_completo_DW.Memory2_PreviousInput_a[6] == 1) ||
           (modello_completo_DW.Memory2_PreviousInput_a[3] == 1) ||
           (modello_completo_DW.Memory2_PreviousInput_a[4] == 1) ||
           (modello_completo_DW.Memory2_PreviousInput_a[2] == 1) ||
           (modello_completo_DW.Memory2_PreviousInput_a[8] == 1))) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_AUTOMATICA;
        modello_completo_DW.is_AUTOMATICA = modello_completo_IN_VETTORIALE;
      } else if (modello_completo_B.Switch_n == 1.0) {
        modello_completo_DW.is_c26_modello_completo = modello_completo_IN_Safe;
      } else if (modello_completo_P.Constant2_Value_k == 1.0) {
        modello_completo_DW.is_c26_modello_completo =
          modello_co_IN_Intervento_Pilota;
      } else {
        modello_completo_B.modo = 5.0;
        modello_completo_B.switch_manetta = 1.0;
        modello_completo_B.switch_equilibratore = 1.0;
        modello_completo_B.switch_alettoni = 1.0;
        modello_completo_B.switch_timone = 1.0;
      }
      break;

     case modello_co_IN_Intervento_Pilota:
      if (modello_completo_DW.Memory2_PreviousInput_a[0] == 1) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_MANUALE;
      } else {
        modello_completo_B.switch_manetta = 0.0;
        modello_completo_B.switch_equilibratore = 0.0;
        modello_completo_B.switch_alettoni = 0.0;
        modello_completo_B.switch_timone = 0.0;
      }
      break;

     case modello_completo_IN_MANUALE:
      if ((modello_completo_B.Go_Home == 1.0) && (modello_completo_B.Switch_n ==
           0.0)) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_Go_Home;
      } else if (modello_completo_DW.Memory2_PreviousInput_a[0] == 0) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_Stand_By;
      } else {
        modello_completo_B.switch_manetta = 0.0;
        modello_completo_B.switch_equilibratore = 0.0;
        modello_completo_B.switch_alettoni = 0.0;
        modello_completo_B.switch_timone = 0.0;
      }
      break;

     case modello_completo_IN_Safe:
      if (modello_completo_P.Constant2_Value_k == 1.0) {
        modello_completo_DW.is_c26_modello_completo =
          modello_co_IN_Intervento_Pilota;
      } else if (modello_completo_DW.Memory2_PreviousInput_a[0] == 1) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_MANUALE;
      } else {
        modello_completo_B.switch_manetta = 1.0;
        modello_completo_B.switch_equilibratore = 1.0;
        modello_completo_B.switch_alettoni = 1.0;
        modello_completo_B.switch_timone = 1.0;
      }
      break;

     default:
      /* case IN_Stand_By: */
      if (modello_completo_DW.Memory2_PreviousInput_a[1] == 1) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_AUTOMATICA;
        modello_completo_DW.is_AUTOMATICA = modello_completo_IN_VETTORIALE;
      } else if (modello_completo_DW.Memory2_PreviousInput_a[0] == 1) {
        modello_completo_DW.is_c26_modello_completo =
          modello_completo_IN_MANUALE;
      } else {
        modello_completo_B.switch_manetta = 0.0;
        modello_completo_B.switch_equilibratore = 0.0;
        modello_completo_B.switch_alettoni = 0.0;
        modello_completo_B.switch_timone = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S38>/ STATI' */

  /* S-Function (PWMinterrupt_elevator_v4_4): '<S9>/S-Function Builder1' */
  PWMinterrupt_elevator_v4_4_Outputs_wrapper(&modello_completo_B.PWM_elevator);

  /* Product: '<S585>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion13'
   *  DataTypeConversion: '<S9>/Data Type Conversion6'
   *  DataTypeConversion: '<S9>/Data Type Conversion7'
   *  Product: '<S586>/Divide'
   *  Product: '<S592>/Multiply'
   *  Sum: '<S585>/Sum'
   *  Sum: '<S585>/Sum1'
   */
  modello_completo_B.Go_Home =
    modello_completo_B.One_time_initialization.ByteUnpack[2] -
    modello_completo_B.One_time_initialization.ByteUnpack[3];
  modello_completo_B.Sum_nu = (real_T)(modello_completo_B.PWM_elevator -
    modello_completo_B.One_time_initialization.ByteUnpack[3]) /
    modello_completo_B.Go_Home;

  /* Sum: '<S585>/Sum2' incorporates:
   *  Constant: '<S585>/Constant8'
   *  Constant: '<S585>/Constant9'
   *  Sum: '<S592>/Sum1'
   */
  modello_completo_B.rtb_Sum3_o_tmp = modello_completo_P.attuatore_Emax -
    modello_completo_P.attuatore_Emin;

  /* Sum: '<S585>/Sum3' incorporates:
   *  Constant: '<S585>/Constant9'
   *  Product: '<S585>/Divide'
   *  Product: '<S585>/Multiply'
   *  Sum: '<S585>/Sum2'
   */
  modello_completo_B.Sum3_o = modello_completo_B.Sum_nu *
    modello_completo_B.rtb_Sum3_o_tmp + modello_completo_P.attuatore_Emin;

  /* MATLAB Function: '<S38>/MATLAB Function' */
  if (modello_completo_B.modo == 3.0) {
    modello_completo_B.ATO = 1;
    modello_completo_B.AL = 0;
  } else if (modello_completo_B.modo == 4.0) {
    modello_completo_B.AL = 1;
    modello_completo_B.ATO = 0;
  } else {
    modello_completo_B.ATO = 0;
    modello_completo_B.AL = 0;
  }

  /* Gain: '<S586>/Gain' incorporates:
   *  Constant: '<S586>/Constant8'
   *  Constant: '<S586>/Constant9'
   *  Product: '<S586>/Multiply'
   *  Sum: '<S586>/Sum2'
   *  Sum: '<S586>/Sum3'
   */
  modello_completo_B.deltafalllimit = (modello_completo_B.Sum_nu *
    (modello_completo_P.theta_max - modello_completo_P.theta_min) +
    modello_completo_P.theta_min) * modello_completo_P.Gain_Gain_h;

  /* Saturate: '<S586>/Saturation' */
  if (modello_completo_B.deltafalllimit > modello_completo_P.theta_max) {
    modello_completo_B.deltafalllimit = modello_completo_P.theta_max;
  } else {
    if (modello_completo_B.deltafalllimit < modello_completo_P.theta_min) {
      modello_completo_B.deltafalllimit = modello_completo_P.theta_min;
    }
  }

  /* End of Saturate: '<S586>/Saturation' */

  /* Sum: '<S37>/Sum2' */
  modello_completo_B.Gain1_c = modello_completo_B.deltafalllimit -
    modello_completo_B.Gain1_c;

  /* Sum: '<S349>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore beccheggio1'
   *  DiscreteIntegrator: '<S340>/Integrator'
   *  Product: '<S345>/PProd Out'
   */
  modello_completo_B.Sum_nu = modello_completo_B.Gain1_c *
    modello_completo_P.Kp_becch + modello_completo_DW.Integrator_DSTATE;

  /* Saturate: '<S347>/Saturation' */
  if (modello_completo_B.Sum_nu > modello_completo_P.attuatore_Emax) {
    modello_completo_B.Saturation = modello_completo_P.attuatore_Emax;
  } else if (modello_completo_B.Sum_nu < modello_completo_P.attuatore_Emin) {
    modello_completo_B.Saturation = modello_completo_P.attuatore_Emin;
  } else {
    modello_completo_B.Saturation = modello_completo_B.Sum_nu;
  }

  /* End of Saturate: '<S347>/Saturation' */

  /* MultiPortSwitch: '<S302>/Switch Bumpless 2' */
  if ((int32_T)modello_completo_B.switch_equilibratore == 0) {
    modello_completo_B.SwitchBumpless2 = modello_completo_B.Sum3_o;
  } else {
    modello_completo_B.SwitchBumpless2 = modello_completo_B.Saturation;
  }

  /* End of MultiPortSwitch: '<S302>/Switch Bumpless 2' */

  /* MultiPortSwitch: '<S307>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (modello_completo_B.AL != 0) {
    /* Switch: '<S307>/Switch1' incorporates:
     *  Constant: '<S307>/Constant5'
     */
    if (!(modello_completo_B.Product1 >= modello_completo_P.Switch1_Threshold))
    {
      modello_completo_B.SwitchBumpless2 = modello_completo_P.Constant5_Value;
    }

    /* End of Switch: '<S307>/Switch1' */
  }

  /* End of MultiPortSwitch: '<S307>/Multiport Switch2' */

  /* Logic: '<S39>/AND' */
  Ap_sel = ((modello_completo_B.switch_manetta != 0.0) &&
            (modello_completo_B.switch_equilibratore != 0.0) &&
            (modello_completo_B.switch_alettoni != 0.0) &&
            (modello_completo_B.switch_timone != 0.0));

  /* Chart: '<S39>/Chart' incorporates:
   *  Logic: '<S39>/AND'
   */
  if (modello_completo_DW.is_active_c21_modello_completo == 0U) {
    modello_completo_DW.is_active_c21_modello_completo = 1U;
    modello_completo_DW.is_c21_modello_completo = modello_completo_IN_In;
    modello_completo_B.Wp_selector = 0.0;
    modello_completo_B.Vec_selector = 0.0;
    modello_completo_B.Ato_selector = 0.0;
    modello_completo_B.Al_selector = 0.0;
    modello_completo_B.Go_home_selector = 0.0;
  } else {
    switch (modello_completo_DW.is_c21_modello_completo) {
     case modello_completo_IN_AutoLanding:
      if ((!(modello_completo_B.switch_manetta != 0.0)) ||
          (!(modello_completo_B.switch_equilibratore != 0.0)) ||
          (!(modello_completo_B.switch_alettoni != 0.0)) ||
          (!(modello_completo_B.switch_timone != 0.0))) {
        modello_completo_DW.is_c21_modello_completo = modello_completo_IN_In;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 2.0) {
        modello_completo_DW.is_c21_modello_completo =
          modello_completo_IN_Vettoriale;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 1.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 1.0) {
        modello_completo_DW.is_c21_modello_completo =
          modello_completo_IN_Waypoint;
        modello_completo_B.Wp_selector = 1.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 5.0) {
        modello_completo_DW.is_c21_modello_completo = modello_completo_IN_GoHome;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 1.0;
      } else {
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 1.0;
        modello_completo_B.Go_home_selector = 0.0;
      }
      break;

     case modello_completo_IN_AutoTakeoff:
      if ((!(modello_completo_B.switch_manetta != 0.0)) ||
          (!(modello_completo_B.switch_equilibratore != 0.0)) ||
          (!(modello_completo_B.switch_alettoni != 0.0)) ||
          (!(modello_completo_B.switch_timone != 0.0))) {
        modello_completo_DW.is_c21_modello_completo = modello_completo_IN_In;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 1.0) {
        modello_completo_DW.is_c21_modello_completo =
          modello_completo_IN_Waypoint;
        modello_completo_B.Wp_selector = 1.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 2.0) {
        modello_completo_DW.is_c21_modello_completo =
          modello_completo_IN_Vettoriale;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 1.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else {
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 1.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      }
      break;

     case modello_completo_IN_GoHome:
      if ((!(modello_completo_B.switch_manetta != 0.0)) ||
          (!(modello_completo_B.switch_equilibratore != 0.0)) ||
          (!(modello_completo_B.switch_alettoni != 0.0)) ||
          (!(modello_completo_B.switch_timone != 0.0))) {
        modello_completo_DW.is_c21_modello_completo = modello_completo_IN_In;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else {
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 1.0;
      }
      break;

     case modello_completo_IN_In:
      modello_completo_In(&Ap_sel, &modello_completo_B.Go_home_selector,
                          &modello_completo_B.Al_selector,
                          &modello_completo_B.Ato_selector,
                          &modello_completo_B.Vec_selector,
                          &modello_completo_B.Wp_selector);
      break;

     case modello_completo_IN_Vettoriale:
      if ((!(modello_completo_B.switch_manetta != 0.0)) ||
          (!(modello_completo_B.switch_equilibratore != 0.0)) ||
          (!(modello_completo_B.switch_alettoni != 0.0)) ||
          (!(modello_completo_B.switch_timone != 0.0))) {
        modello_completo_DW.is_c21_modello_completo = modello_completo_IN_In;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 1.0) {
        modello_completo_DW.is_c21_modello_completo =
          modello_completo_IN_Waypoint;
        modello_completo_B.Wp_selector = 1.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else if (modello_completo_B.modo == 5.0) {
        modello_completo_DW.is_c21_modello_completo = modello_completo_IN_GoHome;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 1.0;
      } else if (modello_completo_B.modo == 4.0) {
        modello_completo_DW.is_c21_modello_completo =
          modello_completo_IN_AutoLanding;
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 0.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 1.0;
        modello_completo_B.Go_home_selector = 0.0;
      } else {
        modello_completo_B.Wp_selector = 0.0;
        modello_completo_B.Vec_selector = 1.0;
        modello_completo_B.Ato_selector = 0.0;
        modello_completo_B.Al_selector = 0.0;
        modello_completo_B.Go_home_selector = 0.0;
      }
      break;

     default:
      /* case IN_Waypoint: */
      modello_completo_Waypoint(&Ap_sel, &modello_completo_B.Go_home_selector,
        &modello_completo_B.Al_selector, &modello_completo_B.Ato_selector,
        &modello_completo_B.Vec_selector, &modello_completo_B.Wp_selector);
      break;
    }
  }

  /* End of Chart: '<S39>/Chart' */

  /* Outputs for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' incorporates:
   *  EnablePort: '<S438>/Enable'
   */
  if (modello_completo_B.Ato_selector > 0.0) {
    /* Outputs for Triggered SubSystem: '<S438>/Sample and Hold' incorporates:
     *  TriggerPort: '<S446>/Trigger'
     */
    /* Memory: '<S438>/Memory' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &modello_completo_PrevZCX.SampleandHold_Trig_ZCE_h,
             (modello_completo_DW.Memory_PreviousInput_i));

    /* End of Outputs for SubSystem: '<S438>/Sample and Hold' */

    /* Outputs for Triggered SubSystem: '<S438>/Sample and Hold1' incorporates:
     *  TriggerPort: '<S447>/Trigger'
     */
    /* Memory: '<S438>/Memory1' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &modello_completo_PrevZCX.SampleandHold1_Trig_ZCE,
             (modello_completo_DW.Memory1_PreviousInput_o));

    /* End of Outputs for SubSystem: '<S438>/Sample and Hold1' */

    /* Chart: '<S438>/Chart1' incorporates:
     *  DataTypeConversion: '<S554>/Data Type Conversion5'
     */
    if (modello_completo_DW.temporalCounter_i1 < 255U) {
      modello_completo_DW.temporalCounter_i1++;
    }

    if (modello_completo_DW.is_active_c1_modello_completo == 0U) {
      modello_completo_DW.is_active_c1_modello_completo = 1U;
      modello_completo_DW.is_c1_modello_completo =
        modello_completo_IN_Fase_0_ATO;
    } else {
      switch (modello_completo_DW.is_c1_modello_completo) {
       case modello_completo_IN_Fase_0_ATO:
        if (modello_completo_B.modo == 3.0) {
          modello_completo_B.psi_ref_selector = 1.0;
          modello_completo_DW.is_c1_modello_completo =
            modello_completo_IN_Fase_1_ATO;
          modello_completo_DW.temporalCounter_i1 = 0U;
        } else {
          modello_completo_B.Fase_ATO = 0.0;
          modello_completo_B.psi_ref_selector = 0.0;
          modello_completo_B.theta_ground_selector = 0.0;
          modello_completo_B.eq_rot = 0.0;
          modello_completo_B.h_ref = 0.0;
        }
        break;

       case modello_completo_IN_Fase_1_ATO:
        if (modello_completo_DW.temporalCounter_i1 >= 250) {
          modello_completo_DW.is_c1_modello_completo =
            modello_completo_IN_Fase_2_ATO;
        } else {
          modello_completo_B.Fase_ATO = 1.0;
          modello_completo_B.psi_ref_selector = 0.0;
          modello_completo_B.h_ref = 0.0;
          modello_completo_B.eq_rot = 2.0;
        }
        break;

       case modello_completo_IN_Fase_2_ATO:
        if ((modello_completo_B.Product1 >= 18.0) &&
            (modello_completo_B.rtb_Gain1_i_idx_0 >= 10.0)) {
          modello_completo_B.theta_ground_selector = 1.0;
          modello_completo_DW.is_c1_modello_completo =
            modello_completo_IN_Fase_3_ATO;
        } else {
          modello_completo_B.Fase_ATO = 2.0;
          modello_completo_B.psi_ref_selector = 0.0;
          modello_completo_B.h_ref = 0.0;
          modello_completo_B.eq_rot = 2.0;
        }
        break;

       case modello_completo_IN_Fase_3_ATO:
        if (modello_completo_B.ByteUnpack_o2_e[2] >= 2.0F) {
          modello_completo_DW.is_c1_modello_completo =
            modello_completo_IN_Fase_4_ATO;
        } else {
          modello_completo_B.Fase_ATO = 3.0;
          modello_completo_B.psi_ref_selector = 0.0;
          modello_completo_B.theta_ground_selector = 0.0;
          modello_completo_B.h_ref = 0.0;
        }
        break;

       default:
        /* case IN_Fase_4_ATO: */
        modello_completo_B.Fase_ATO = 4.0;
        modello_completo_B.psi_ref_selector = 0.0;
        modello_completo_B.h_ref = 35.0;
        break;
      }
    }

    /* End of Chart: '<S438>/Chart1' */

    /* Update for Memory: '<S438>/Memory' */
    modello_completo_DW.Memory_PreviousInput_i =
      modello_completo_B.psi_ref_selector;

    /* Update for Memory: '<S438>/Memory1' */
    modello_completo_DW.Memory1_PreviousInput_o =
      modello_completo_B.theta_ground_selector;
  }

  /* End of Outputs for SubSystem: '<S39>/DECOLLO AUTOMATICO' */

  /* MultiPortSwitch: '<S308>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (modello_completo_B.ATO != 0) {
    /* MultiPortSwitch: '<S308>/Multiport Switch1' incorporates:
     *  Gain: '<S357>/Gain1'
     */
    switch ((int32_T)modello_completo_B.Fase_ATO) {
     case 0:
      modello_completo_B.SwitchBumpless2 = modello_completo_P.Gain1_Gain_jm *
        modello_completo_B.eq_rot;
      break;

     case 1:
      modello_completo_B.SwitchBumpless2 = modello_completo_P.Gain1_Gain_jm *
        modello_completo_B.eq_rot;
      break;

     case 2:
      modello_completo_B.SwitchBumpless2 = modello_completo_P.Gain1_Gain_jm *
        modello_completo_B.eq_rot;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S308>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S308>/Multiport Switch2' */

  /* MultiPortSwitch: '<S37>/Switch Bumpless 1' incorporates:
   *  Gain: '<S37>/Gain'
   */
  if ((int32_T)modello_completo_B.switch_equilibratore != 0) {
    /* MultiPortSwitch: '<S302>/Switch 1' incorporates:
     *  Abs: '<S302>/Abs1'
     *  Constant: '<S302>/Constant1'
     *  Constant: '<S302>/Constant2'
     *  Constant: '<S302>/Constant3'
     *  Constant: '<S8>/Kp controllore velocità beccheggio1'
     *  Gain: '<S302>/Gain'
     *  MultiPortSwitch: '<S302>/Switch  2'
     *  Product: '<S302>/Product3'
     *  Product: '<S302>/Product4'
     *  Product: '<S302>/Product5'
     *  Sum: '<S302>/Sum3'
     *  Trigonometry: '<S302>/Trigonometric Function'
     */
    if ((int32_T)modello_completo_B.switch_equilibratore == 0) {
      modello_completo_B.Sum3_o = modello_completo_P.Constant1_Value_fj;
      modello_completo_B.deltafalllimit = modello_completo_P.Constant2_Value_i4;
    } else {
      /* Abs: '<S302>/Abs1' incorporates:
       *  Abs: '<S302>/Abs'
       */
      modello_completo_B.deltafalllimit = fabs(modello_completo_B.Gain1_j);
      modello_completo_B.Sum3_o = (modello_completo_B.DataTypeConversion1_pb[4]
        - sin(modello_completo_B.deltafalllimit) *
        modello_completo_B.DataTypeConversion1_pb[5]) * modello_completo_P.Kp_q;
      modello_completo_B.deltafalllimit *= modello_completo_P.inv_comp_h *
        modello_completo_P.Kp_comp_h;
    }

    /* End of MultiPortSwitch: '<S302>/Switch 1' */

    /* Sum: '<S302>/Sum2' incorporates:
     *  Sum: '<S302>/Sum'
     */
    modello_completo_B.deltafalllimit = (modello_completo_B.SwitchBumpless2 -
      modello_completo_B.Sum3_o) - modello_completo_B.deltafalllimit;

    /* Saturate: '<S302>/saturatore E2' */
    if (modello_completo_B.deltafalllimit > modello_completo_P.attuatore_Emax) {
      modello_completo_B.deltafalllimit = modello_completo_P.attuatore_Emax;
    } else {
      if (modello_completo_B.deltafalllimit < modello_completo_P.attuatore_Emin)
      {
        modello_completo_B.deltafalllimit = modello_completo_P.attuatore_Emin;
      }
    }

    /* End of Saturate: '<S302>/saturatore E2' */
    modello_completo_B.Sum3_o = modello_completo_P.inv_E *
      modello_completo_B.deltafalllimit;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 1' */

  /* Sum: '<S29>/Sum' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S30>/Gain'
   */
  modello_completo_B.Gain3 = modello_completo_P.Gain_Gain_od *
    modello_completo_B.Sum3_o + modello_completo_P.Constant2_Value_m;

  /* S-Function (PWMinterrupt_aileron_v4_4): '<S9>/S-Function Builder7' */
  PWMinterrupt_aileron_v4_4_Outputs_wrapper(&modello_completo_B.PWM_aileron);

  /* Product: '<S583>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion14'
   *  DataTypeConversion: '<S9>/Data Type Conversion8'
   *  DataTypeConversion: '<S9>/Data Type Conversion9'
   *  Product: '<S584>/Divide'
   *  Product: '<S589>/Multiply'
   *  Sum: '<S583>/Sum'
   *  Sum: '<S583>/Sum1'
   */
  modello_completo_B.Ato_selector =
    modello_completo_B.One_time_initialization.ByteUnpack[4] -
    modello_completo_B.One_time_initialization.ByteUnpack[5];
  modello_completo_B.Sum_o = (real_T)(modello_completo_B.PWM_aileron -
    modello_completo_B.One_time_initialization.ByteUnpack[5]) /
    modello_completo_B.Ato_selector;

  /* Sum: '<S583>/Sum2' incorporates:
   *  Constant: '<S583>/Constant8'
   *  Constant: '<S583>/Constant9'
   *  Sum: '<S589>/Sum1'
   */
  modello_completo_B.rtb_Sum3_b_tmp = modello_completo_P.attuatore_Amax -
    modello_completo_P.attuatore_Amin;

  /* Sum: '<S583>/Sum3' incorporates:
   *  Constant: '<S583>/Constant9'
   *  Product: '<S583>/Divide'
   *  Product: '<S583>/Multiply'
   *  Sum: '<S583>/Sum2'
   */
  modello_completo_B.Sum3_b = modello_completo_B.Sum_o *
    modello_completo_B.rtb_Sum3_b_tmp + modello_completo_P.attuatore_Amin;

  /* Gain: '<S584>/Gain' incorporates:
   *  Constant: '<S584>/Constant8'
   *  Constant: '<S584>/Constant9'
   *  Product: '<S584>/Multiply'
   *  Sum: '<S584>/Sum2'
   *  Sum: '<S584>/Sum3'
   */
  modello_completo_B.deltafalllimit = (modello_completo_B.Sum_o *
    (modello_completo_P.phi_max - modello_completo_P.phi_min) +
    modello_completo_P.phi_min) * modello_completo_P.Gain_Gain_a;

  /* Saturate: '<S584>/Saturation' */
  if (modello_completo_B.deltafalllimit > modello_completo_P.phi_max) {
    modello_completo_B.deltafalllimit = modello_completo_P.phi_max;
  } else {
    if (modello_completo_B.deltafalllimit < modello_completo_P.phi_min) {
      modello_completo_B.deltafalllimit = modello_completo_P.phi_min;
    }
  }

  /* End of Saturate: '<S584>/Saturation' */

  /* Sum: '<S37>/Sum5' */
  modello_completo_B.Gain1_j = modello_completo_B.deltafalllimit -
    modello_completo_B.Gain1_j;

  /* Sum: '<S303>/Sum' incorporates:
   *  Constant: '<S303>/Constant3'
   */
  modello_completo_B.Sum_o = modello_completo_B.Fase_ATO -
    modello_completo_P.Constant3_Value_cr;

  /* DiscreteIntegrator: '<S390>/Integrator' */
  if ((modello_completo_B.Sum_o > 0.0) &&
      (modello_completo_DW.Integrator_PrevResetState <= 0)) {
    modello_completo_DW.Integrator_DSTATE_p =
      modello_completo_P.PIDController_InitialConditio_d;
  }

  /* Sum: '<S399>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore  rollio3'
   *  DiscreteIntegrator: '<S390>/Integrator'
   *  Product: '<S395>/PProd Out'
   */
  modello_completo_B.Sum_n3 = modello_completo_B.Gain1_j *
    modello_completo_P.Kp_roll + modello_completo_DW.Integrator_DSTATE_p;

  /* Saturate: '<S397>/Saturation' */
  if (modello_completo_B.Sum_n3 > modello_completo_P.attuatore_Amax) {
    modello_completo_B.Saturation_f = modello_completo_P.attuatore_Amax;
  } else if (modello_completo_B.Sum_n3 < modello_completo_P.attuatore_Amin) {
    modello_completo_B.Saturation_f = modello_completo_P.attuatore_Amin;
  } else {
    modello_completo_B.Saturation_f = modello_completo_B.Sum_n3;
  }

  /* End of Saturate: '<S397>/Saturation' */

  /* MultiPortSwitch: '<S303>/Switch Bumpless 1' incorporates:
   *  Constant: '<S303>/Constant1'
   *  Constant: '<S8>/Kp controllore  velocità rollio3'
   *  Product: '<S303>/Product3'
   */
  if ((int32_T)modello_completo_B.switch_alettoni == 0) {
    modello_completo_B.deltafalllimit = modello_completo_P.Constant1_Value_ng;
  } else {
    modello_completo_B.deltafalllimit =
      modello_completo_B.DataTypeConversion1_pb[3] * modello_completo_P.Kp_p;
  }

  /* End of MultiPortSwitch: '<S303>/Switch Bumpless 1' */

  /* Sum: '<S303>/Sum2' */
  modello_completo_B.Sum2_o = modello_completo_B.Saturation_f -
    modello_completo_B.deltafalllimit;

  /* MultiPortSwitch: '<S37>/Switch Bumpless 3' incorporates:
   *  Saturate: '<S37>/saturatore A1'
   */
  if ((int32_T)modello_completo_B.switch_alettoni == 0) {
    modello_completo_B.PWM_rudder_p = modello_completo_B.Sum3_b;
  } else if (modello_completo_B.Sum2_o > modello_completo_P.attuatore_Amax) {
    /* Saturate: '<S37>/saturatore A1' */
    modello_completo_B.PWM_rudder_p = modello_completo_P.attuatore_Amax;
  } else if (modello_completo_B.Sum2_o < modello_completo_P.attuatore_Amin) {
    /* Saturate: '<S37>/saturatore A1' */
    modello_completo_B.PWM_rudder_p = modello_completo_P.attuatore_Amin;
  } else {
    /* Saturate: '<S37>/saturatore A1' */
    modello_completo_B.PWM_rudder_p = modello_completo_B.Sum2_o;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 3' */

  /* Saturate: '<S37>/saturatore A' */
  if (modello_completo_B.PWM_rudder_p > modello_completo_P.attuatore_Amax) {
    modello_completo_B.Alettoni = modello_completo_P.attuatore_Amax;
  } else if (modello_completo_B.PWM_rudder_p < modello_completo_P.attuatore_Amin)
  {
    modello_completo_B.Alettoni = modello_completo_P.attuatore_Amin;
  } else {
    modello_completo_B.Alettoni = modello_completo_B.PWM_rudder_p;
  }

  /* End of Saturate: '<S37>/saturatore A' */

  /* MultiPortSwitch: '<S37>/Switch Bumpless 5' incorporates:
   *  Gain: '<S37>/Gain1'
   */
  if ((int32_T)modello_completo_B.switch_alettoni == 0) {
    modello_completo_B.PWM_rudder_p = modello_completo_B.Sum3_b;
  } else {
    modello_completo_B.PWM_rudder_p = modello_completo_P.inv_A *
      modello_completo_B.Alettoni;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 5' */

  /* Sum: '<S29>/Sum1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S31>/Gain'
   */
  modello_completo_B.Switch_bk = modello_completo_P.Gain_Gain_i *
    modello_completo_B.PWM_rudder_p + modello_completo_P.Constant2_Value_m;

  /* S-Function (PWMinterrupt_rudder_v4_4): '<S9>/S-Function Builder8' */
  PWMinterrupt_rudder_v4_4_Outputs_wrapper(&modello_completo_B.PWM_rudder);

  /* DiscreteTransferFcn: '<S304>/Discrete Washout Filter' */
  modello_completo_B.denAccum = (modello_completo_B.DataTypeConversion1_pb[5] -
    modello_completo_P.DiscreteWashoutFilter_DenCoef[1] *
    modello_completo_DW.DiscreteWashoutFilter_states) /
    modello_completo_P.DiscreteWashoutFilter_DenCoef[0];

  /* MultiPortSwitch: '<S37>/Switch Bumpless 6' incorporates:
   *  Constant: '<S587>/Constant8'
   *  Constant: '<S587>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion10'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  DataTypeConversion: '<S9>/Data Type Conversion15'
   *  Gain: '<S37>/Gain2'
   *  MultiPortSwitch: '<S37>/Switch Bumpless 4'
   *  Product: '<S587>/Divide'
   *  Product: '<S587>/Multiply'
   *  Sum: '<S587>/Sum1'
   *  Sum: '<S587>/Sum2'
   *  Sum: '<S587>/Sum3'
   *  Sum: '<S587>/Sum4'
   */
  if ((int32_T)modello_completo_B.switch_timone == 0) {
    modello_completo_B.Sum2_o = (real_T)(modello_completo_B.PWM_rudder -
      modello_completo_B.One_time_initialization.ByteUnpack[7]) / (real_T)
      (modello_completo_B.One_time_initialization.ByteUnpack[6] -
       modello_completo_B.One_time_initialization.ByteUnpack[7]) *
      (modello_completo_P.attuatore_Rmax - modello_completo_P.attuatore_Rmin) +
      modello_completo_P.attuatore_Rmin;
  } else {
    if ((int32_T)modello_completo_B.switch_timone == 0) {
      /* MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
       *  Constant: '<S587>/Constant8'
       *  Constant: '<S587>/Constant9'
       *  DataTypeConversion: '<S9>/Data Type Conversion10'
       *  DataTypeConversion: '<S9>/Data Type Conversion11'
       *  DataTypeConversion: '<S9>/Data Type Conversion15'
       *  Product: '<S587>/Divide'
       *  Product: '<S587>/Multiply'
       *  Sum: '<S587>/Sum1'
       *  Sum: '<S587>/Sum2'
       *  Sum: '<S587>/Sum3'
       *  Sum: '<S587>/Sum4'
       */
      modello_completo_B.Sum2_o = (real_T)(modello_completo_B.PWM_rudder -
        modello_completo_B.One_time_initialization.ByteUnpack[7]) / (real_T)
        (modello_completo_B.One_time_initialization.ByteUnpack[6] -
         modello_completo_B.One_time_initialization.ByteUnpack[7]) *
        (modello_completo_P.attuatore_Rmax - modello_completo_P.attuatore_Rmin)
        + modello_completo_P.attuatore_Rmin;
    } else {
      /* MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
       *  Constant: '<S37>/r_rif'
       *  Constant: '<S8>/K controllo imbardata inversa'
       *  Constant: '<S8>/Kp controllore imbardata'
       *  DiscreteTransferFcn: '<S304>/Discrete Washout Filter'
       *  Gain: '<S8>/Gain3'
       *  Product: '<S37>/  CONTROLLO     IMBARDATA      INVERSA'
       *  Product: '<S37>/Product'
       *  Sum: '<S37>/Sum1'
       *  Sum: '<S37>/Sum9'
       */
      modello_completo_B.Sum2_o = (modello_completo_P.r_rif_Value -
        (modello_completo_P.DiscreteWashoutFilter_NumCoef[0] *
         modello_completo_B.denAccum +
         modello_completo_P.DiscreteWashoutFilter_NumCoef[1] *
         modello_completo_DW.DiscreteWashoutFilter_states)) *
        modello_completo_P.Kp_imb + (real_T)(modello_completo_P.Gain3_Gain_o *
        modello_completo_P.K_imb_inv) * 0.0078125 * modello_completo_B.Sum2_o;
    }

    /* Saturate: '<S37>/saturatore R' */
    if (modello_completo_B.Sum2_o > modello_completo_P.attuatore_Rmax) {
      modello_completo_B.Sum2_o = modello_completo_P.attuatore_Rmax;
    } else {
      if (modello_completo_B.Sum2_o < modello_completo_P.attuatore_Rmin) {
        modello_completo_B.Sum2_o = modello_completo_P.attuatore_Rmin;
      }
    }

    /* End of Saturate: '<S37>/saturatore R' */
    modello_completo_B.Sum2_o *= modello_completo_P.inv_R;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 6' */

  /* Sum: '<S29>/Sum2' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  modello_completo_B.PWM_elevator_l = modello_completo_P.Gain_Gain_bh *
    modello_completo_B.Sum2_o + modello_completo_P.Constant2_Value_m;

  /* Gain: '<S20>/Gain' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion3'
   *  Gain: '<S554>/Gain4'
   */
  modello_completo_B.deltafalllimit = modello_completo_P.Gain4_Gain * (real_T)
    modello_completo_B.ByteUnpack_o4[1] * modello_completo_P.Gain_Gain_jr;

  /* Saturate: '<S20>/Saturation' */
  if (modello_completo_B.deltafalllimit > modello_completo_P.Saturation_UpperSat)
  {
    modello_completo_B.IProdOut = modello_completo_P.Saturation_UpperSat;
  } else if (modello_completo_B.deltafalllimit <
             modello_completo_P.Saturation_LowerSat) {
    modello_completo_B.IProdOut = modello_completo_P.Saturation_LowerSat;
  } else {
    modello_completo_B.IProdOut = modello_completo_B.deltafalllimit;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (modello_completo_P.Constant_Value_bh < 0.0) {
    modello_completo_B.deltafalllimit = ceil
      (modello_completo_P.Constant_Value_bh);
  } else {
    modello_completo_B.deltafalllimit = floor
      (modello_completo_P.Constant_Value_bh);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[0] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (modello_completo_B.Gain_o < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.Gain_o);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.Gain_o);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[1] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (modello_completo_B.Gain3 < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.Gain3);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.Gain3);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[2] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (modello_completo_B.Switch_bk < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.Switch_bk);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.Switch_bk);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[3] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (modello_completo_B.PWM_elevator_l < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.PWM_elevator_l);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.PWM_elevator_l);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[4] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (modello_completo_P.Constant1_Value_pa[0] < 0.0) {
    modello_completo_B.deltafalllimit = ceil
      (modello_completo_P.Constant1_Value_pa[0]);
  } else {
    modello_completo_B.deltafalllimit = floor
      (modello_completo_P.Constant1_Value_pa[0]);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[5] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (modello_completo_P.Constant1_Value_pa[1] < 0.0) {
    modello_completo_B.deltafalllimit = ceil
      (modello_completo_P.Constant1_Value_pa[1]);
  } else {
    modello_completo_B.deltafalllimit = floor
      (modello_completo_P.Constant1_Value_pa[1]);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[6] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (modello_completo_P.Constant1_Value_pa[2] < 0.0) {
    modello_completo_B.deltafalllimit = ceil
      (modello_completo_P.Constant1_Value_pa[2]);
  } else {
    modello_completo_B.deltafalllimit = floor
      (modello_completo_P.Constant1_Value_pa[2]);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[7] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.deltafalllimit = modello_completo_B.IProdOut;
  if (modello_completo_B.deltafalllimit < 0.0) {
    modello_completo_B.deltafalllimit = ceil(modello_completo_B.deltafalllimit);
  } else {
    modello_completo_B.deltafalllimit = floor(modello_completo_B.deltafalllimit);
  }

  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  modello_completo_B.Heading[8] = (uint16_T)(modello_completo_B.deltafalllimit <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
    modello_completo_B.deltafalllimit);

  /* Memory: '<S2>/Memory' */
  modello_completo_B.Memory_a = modello_completo_DW.Memory_PreviousInput_n;

  /* MATLAB Function: '<S567>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S567>/Data Type Conversion'
   *  DataTypeConversion: '<S567>/Data Type Conversion2'
   */
  if (modello_completo_B.SFunction_o14 == 1) {
    modello_completo_DW.P_ref = modello_completo_B.SFunctionBuilder1;
  }

  if (modello_completo_B.SFunction_o16 == 1) {
    modello_completo_DW.P_ref = modello_completo_B.SFunction_o17;
    modello_completo_DW.rl_up = 20.0;
    modello_completo_DW.rl_dw = -20.0;
  }

  /* Product: '<S570>/delta rise limit' incorporates:
   *  MATLAB Function: '<S567>/MATLAB Function'
   *  SampleTimeMath: '<S570>/sample time'
   *
   * About '<S570>/sample time':
   *  y = K where K = ( w * Ts )
   */
  modello_completo_B.IProdOut = modello_completo_DW.rl_up *
    modello_completo_P.sampletime_WtEt;

  /* Sum: '<S570>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S567>/MATLAB Function'
   *  UnitDelay: '<S570>/Delay Input2'
   *
   * Block description for '<S570>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S570>/Delay Input2':
   *
   *  Store in Global RAM
   */
  modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_DW.P_ref -
    modello_completo_DW.DelayInput2_DSTATE;

  /* Switch: '<S576>/Switch2' incorporates:
   *  RelationalOperator: '<S576>/LowerRelop1'
   */
  if (!(modello_completo_B.rtb_Gain1_i_idx_0 > modello_completo_B.IProdOut)) {
    /* Product: '<S570>/delta fall limit' incorporates:
     *  MATLAB Function: '<S567>/MATLAB Function'
     *  SampleTimeMath: '<S570>/sample time'
     *
     * About '<S570>/sample time':
     *  y = K where K = ( w * Ts )
     */
    modello_completo_B.deltafalllimit = modello_completo_DW.rl_dw *
      modello_completo_P.sampletime_WtEt;

    /* Switch: '<S576>/Switch' incorporates:
     *  RelationalOperator: '<S576>/UpperRelop'
     */
    if (modello_completo_B.rtb_Gain1_i_idx_0 < modello_completo_B.deltafalllimit)
    {
      modello_completo_B.IProdOut = modello_completo_B.deltafalllimit;
    } else {
      modello_completo_B.IProdOut = modello_completo_B.rtb_Gain1_i_idx_0;
    }

    /* End of Switch: '<S576>/Switch' */
  }

  /* End of Switch: '<S576>/Switch2' */

  /* Sum: '<S570>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S570>/Delay Input2'
   *
   * Block description for '<S570>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S570>/Delay Input2':
   *
   *  Store in Global RAM
   */
  modello_completo_DW.DelayInput2_DSTATE += modello_completo_B.IProdOut;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S570>/Delay Input2'
   *
   * Block description for '<S570>/Delay Input2':
   *
   *  Store in Global RAM
   */
  modello_completo_B.DataTypeConversion2 = (real32_T)
    modello_completo_DW.DelayInput2_DSTATE;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S567>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  modello_completo_B.DataTypeConversion_l = (real32_T)
    (modello_completo_P.PatohPa_Gain * (real_T)
     modello_completo_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion2'
   *  Gain: '<S2>/Pa to hPa1'
   *  Gain: '<S554>/Gain1'
   *  Gain: '<S554>/Gain7'
   */
  modello_completo_B.DataTypeConversion1_g = (real32_T)
    (modello_completo_P.Gain1_Gain_p * (real_T)modello_completo_B.ByteUnpack_o3
     [2] * modello_completo_P.Gain7_Gain * modello_completo_P.PatohPa1_Gain);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  modello_completo_B.f = (real32_T)floor(modello_completo_B.SFunctionBuilder_o1);
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  modello_completo_B.DataTypeConversion2_m = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem1' incorporates:
   *  EnablePort: '<S440>/Enable'
   */
  if (modello_completo_B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S440>/Data Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    for (modello_completo_B.i = 0; modello_completo_B.i < 42;
         modello_completo_B.i++) {
      modello_completo_B.DataTypeConversion4_m[modello_completo_B.i] =
        modello_completo_DW.WP_dbP_AL[modello_completo_B.i];
    }

    /* End of DataTypeConversion: '<S440>/Data Type Conversion4' */

    /* MATLAB Function: '<S440>/CALIBRATING_HOME_COORDINATES' incorporates:
     *  DataTypeConversion: '<S440>/Data Type Conversion4'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    modello_completo_B.rtb_Gain1_i_idx_0 =
      modello_completo_B.DataTypeConversion4_m[30] * 0.017453292519943295;
    modello_completo_B.h_Home = modello_completo_B.DataTypeConversion4_m[36];
    modello_completo_B.deltafalllimit = cos
      (modello_completo_B.DataTypeConversion4_m[25] * 0.017453292519943295);
    modello_completo_B.Switch_bk = sin(modello_completo_B.DataTypeConversion4_m
      [24] * 0.017453292519943295);
    modello_completo_B.Al_selector = cos
      (modello_completo_B.DataTypeConversion4_m[24] * 0.017453292519943295);
    modello_completo_B.Gain_o = modello_completo_B.DataTypeConversion4_m[31] *
      0.017453292519943295 - modello_completo_B.DataTypeConversion4_m[30] *
      0.017453292519943295;
    modello_completo_B.Gain_o = rt_atan2d_snf(sin(modello_completo_B.Gain_o) *
      modello_completo_B.deltafalllimit, sin
      (modello_completo_B.DataTypeConversion4_m[25] * 0.017453292519943295) *
      modello_completo_B.Al_selector - cos(modello_completo_B.Gain_o) *
      (modello_completo_B.Switch_bk * modello_completo_B.deltafalllimit));
    if (modello_completo_B.Gain_o < 0.0) {
      modello_completo_B.Gain_o = 6.2831853071795862 - fabs
        (modello_completo_B.Gain_o);
    }

    /* MATLAB Function: '<S453>/MATLAB Function' incorporates:
     *  Constant: '<S453>/distance waypoints virtuale'
     *  MATLAB Function: '<S440>/CALIBRATING_HOME_COORDINATES'
     *  Trigonometry: '<S524>/SinCos'
     */
    modello_completo_B.Gain3 = sin
      (modello_completo_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    modello_completo_B.PWM_elevator_l = cos
      (modello_completo_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    modello_completo_B.deltafalllimit = cos(modello_completo_B.Gain_o);
    modello_completo_B.Gain_n = asin(modello_completo_B.Al_selector *
      modello_completo_B.Gain3 * modello_completo_B.deltafalllimit +
      modello_completo_B.Switch_bk * modello_completo_B.PWM_elevator_l);
    modello_completo_B.Gain_o = sin(modello_completo_B.Gain_o);

    /* MATLAB Function: '<S453>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S453>/alt waypoint virtuale'
     *  Gain: '<S469>/Gain'
     *  Gain: '<S470>/Gain'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    modello_completo_B.WP_param_c[12] = modello_completo_P.Gain_Gain_es *
      modello_completo_B.Gain_n;
    modello_completo_B.WP_param_c[15] = modello_completo_P.Gain_Gain_k *
      (rt_atan2d_snf(modello_completo_B.Gain_o * modello_completo_B.Gain3 *
                     modello_completo_B.Al_selector,
                     modello_completo_B.PWM_elevator_l -
                     modello_completo_B.Switch_bk * sin
                     (modello_completo_B.Gain_n)) +
       modello_completo_B.rtb_Gain1_i_idx_0);
    modello_completo_B.WP_param_c[3] = 1.0;
    modello_completo_B.WP_param_c[6] = 0.0;
    modello_completo_B.WP_param_c[9] = 0.0;
    modello_completo_B.WP_param_c[18] = modello_completo_B.h_Home +
      modello_completo_P.altwaypointvirtuale_Value[0];

    /* MATLAB Function: '<S453>/MATLAB Function' incorporates:
     *  Constant: '<S453>/distance waypoints virtuale'
     */
    modello_completo_B.Gain3 = sin
      (modello_completo_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    modello_completo_B.PWM_elevator_l = cos
      (modello_completo_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    modello_completo_B.Gain_n = asin(modello_completo_B.Al_selector *
      modello_completo_B.Gain3 * modello_completo_B.deltafalllimit +
      modello_completo_B.Switch_bk * modello_completo_B.PWM_elevator_l);

    /* MATLAB Function: '<S453>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S453>/Constant1'
     *  Constant: '<S453>/alt waypoint virtuale'
     *  Gain: '<S469>/Gain'
     *  Gain: '<S470>/Gain'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    modello_completo_B.WP_param_c[13] = modello_completo_P.Gain_Gain_es *
      modello_completo_B.Gain_n;
    modello_completo_B.WP_param_c[16] = modello_completo_P.Gain_Gain_k *
      (rt_atan2d_snf(modello_completo_B.Gain_o * modello_completo_B.Gain3 *
                     modello_completo_B.Al_selector,
                     modello_completo_B.PWM_elevator_l -
                     modello_completo_B.Switch_bk * sin
                     (modello_completo_B.Gain_n)) +
       modello_completo_B.rtb_Gain1_i_idx_0);
    modello_completo_B.WP_param_c[1] = modello_completo_P.vel_wp2_al;
    modello_completo_B.WP_param_c[4] = 1.0;
    modello_completo_B.WP_param_c[7] = 0.0;
    modello_completo_B.WP_param_c[10] = 0.0;
    modello_completo_B.WP_param_c[19] = modello_completo_B.h_Home +
      modello_completo_P.altwaypointvirtuale_Value[1];

    /* MATLAB Function: '<S453>/MATLAB Function' incorporates:
     *  Constant: '<S453>/distance waypoints virtuale'
     */
    modello_completo_B.Gain3 = sin
      (modello_completo_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    modello_completo_B.PWM_elevator_l = cos
      (modello_completo_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    modello_completo_B.Gain_n = asin(modello_completo_B.Al_selector *
      modello_completo_B.Gain3 * modello_completo_B.deltafalllimit +
      modello_completo_B.Switch_bk * modello_completo_B.PWM_elevator_l);

    /* MATLAB Function: '<S453>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S453>/Constant'
     *  Constant: '<S453>/Constant1'
     *  Constant: '<S453>/alt waypoint virtuale'
     *  Gain: '<S469>/Gain'
     *  Gain: '<S470>/Gain'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    modello_completo_B.WP_param_c[14] = modello_completo_P.Gain_Gain_es *
      modello_completo_B.Gain_n;
    modello_completo_B.WP_param_c[17] = modello_completo_P.Gain_Gain_k *
      (rt_atan2d_snf(modello_completo_B.Gain_o * modello_completo_B.Gain3 *
                     modello_completo_B.Al_selector,
                     modello_completo_B.PWM_elevator_l -
                     modello_completo_B.Switch_bk * sin
                     (modello_completo_B.Gain_n)) +
       modello_completo_B.rtb_Gain1_i_idx_0);
    modello_completo_B.WP_param_c[2] = modello_completo_P.vel_wp2_al;
    modello_completo_B.WP_param_c[8] = 0.0;
    modello_completo_B.WP_param_c[11] = 0.0;
    modello_completo_B.WP_param_c[20] = modello_completo_B.h_Home +
      modello_completo_P.altwaypointvirtuale_Value[2];
    modello_completo_B.WP_param_c[0] = modello_completo_P.vel_wp1_al;
    modello_completo_B.WP_param_c[5] = 0.0;

    /* Gain: '<S458>/Gain' incorporates:
     *  DataTypeConversion: '<S440>/Data Type Conversion4'
     *  MATLAB Function: '<S440>/CALIBRATING_HOME_COORDINATES'
     */
    modello_completo_B.Gain = modello_completo_B.DataTypeConversion4_m[24] *
      0.017453292519943295 * modello_completo_P.Gain_Gain_p;

    /* Switch: '<S534>/Switch' incorporates:
     *  Abs: '<S534>/Abs'
     *  Bias: '<S534>/Bias'
     *  Bias: '<S534>/Bias1'
     *  Constant: '<S534>/Constant2'
     *  Constant: '<S535>/Constant'
     *  Math: '<S534>/Math Function1'
     *  RelationalOperator: '<S535>/Compare'
     */
    if (fabs(modello_completo_B.Gain) >
        modello_completo_P.CompareToConstant_const) {
      modello_completo_B.Switch_bk = rt_modd_snf(modello_completo_B.Gain +
        modello_completo_P.Bias_Bias_e, modello_completo_P.Constant2_Value_n) +
        modello_completo_P.Bias1_Bias_j;
    } else {
      modello_completo_B.Switch_bk = modello_completo_B.Gain;
    }

    /* End of Switch: '<S534>/Switch' */

    /* Abs: '<S531>/Abs1' */
    modello_completo_B.Al_selector = fabs(modello_completo_B.Switch_bk);

    /* RelationalOperator: '<S533>/Compare' incorporates:
     *  Constant: '<S533>/Constant'
     */
    Ap_sel = (modello_completo_B.Al_selector >
              modello_completo_P.CompareToConstant_const_d);

    /* Gain: '<S459>/Gain' */
    modello_completo_B.Gain_g = modello_completo_P.Gain_Gain_b2 *
      modello_completo_B.rtb_Gain1_i_idx_0;

    /* Switch: '<S531>/Switch' incorporates:
     *  Bias: '<S531>/Bias'
     *  Bias: '<S531>/Bias1'
     *  Constant: '<S523>/Constant'
     *  Constant: '<S523>/Constant1'
     *  Gain: '<S531>/Gain'
     *  Product: '<S531>/Divide1'
     *  Switch: '<S523>/Switch1'
     */
    if (Ap_sel) {
      /* Signum: '<S531>/Sign1' */
      if (modello_completo_B.Switch_bk < 0.0) {
        modello_completo_B.Switch_bk = -1.0;
      } else if (modello_completo_B.Switch_bk > 0.0) {
        modello_completo_B.Switch_bk = 1.0;
      } else if (modello_completo_B.Switch_bk == 0.0) {
        modello_completo_B.Switch_bk = 0.0;
      } else {
        modello_completo_B.Switch_bk = (rtNaN);
      }

      /* End of Signum: '<S531>/Sign1' */
      modello_completo_B.Switch_bk *= (modello_completo_B.Al_selector +
        modello_completo_P.Bias_Bias_f) * modello_completo_P.Gain_Gain_mn +
        modello_completo_P.Bias1_Bias_f;
      modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_P.Constant_Value_d;
    } else {
      modello_completo_B.rtb_Gain1_i_idx_0 =
        modello_completo_P.Constant1_Value_d5;
    }

    /* End of Switch: '<S531>/Switch' */

    /* Sum: '<S523>/Sum' */
    modello_completo_B.Al_selector = modello_completo_B.rtb_Gain1_i_idx_0 +
      modello_completo_B.Gain_g;

    /* Sum: '<S457>/Sum1' incorporates:
     *  Gain: '<S461>/Gain'
     */
    modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_P.Gain_Gain_f *
      modello_completo_B.Gain1_f - modello_completo_B.Switch_bk;

    /* Switch: '<S528>/Switch' incorporates:
     *  Abs: '<S528>/Abs'
     *  Bias: '<S528>/Bias'
     *  Bias: '<S528>/Bias1'
     *  Constant: '<S528>/Constant2'
     *  Constant: '<S529>/Constant'
     *  Math: '<S528>/Math Function1'
     *  RelationalOperator: '<S529>/Compare'
     */
    if (fabs(modello_completo_B.rtb_Gain1_i_idx_0) >
        modello_completo_P.CompareToConstant_const_b) {
      modello_completo_B.rtb_Gain1_i_idx_0 = rt_modd_snf
        (modello_completo_B.rtb_Gain1_i_idx_0 + modello_completo_P.Bias_Bias_n,
         modello_completo_P.Constant2_Value_i) + modello_completo_P.Bias1_Bias_n;
    }

    /* End of Switch: '<S528>/Switch' */

    /* Abs: '<S525>/Abs1' */
    modello_completo_B.Gain3 = fabs(modello_completo_B.rtb_Gain1_i_idx_0);

    /* Switch: '<S525>/Switch' incorporates:
     *  Bias: '<S525>/Bias'
     *  Bias: '<S525>/Bias1'
     *  Constant: '<S522>/Constant'
     *  Constant: '<S522>/Constant1'
     *  Constant: '<S527>/Constant'
     *  Gain: '<S525>/Gain'
     *  Product: '<S525>/Divide1'
     *  RelationalOperator: '<S527>/Compare'
     *  Switch: '<S522>/Switch1'
     */
    if (modello_completo_B.Gain3 > modello_completo_P.CompareToConstant_const_dp)
    {
      /* Signum: '<S525>/Sign1' */
      if (modello_completo_B.rtb_Gain1_i_idx_0 < 0.0) {
        modello_completo_B.rtb_Gain1_i_idx_0 = -1.0;
      } else if (modello_completo_B.rtb_Gain1_i_idx_0 > 0.0) {
        modello_completo_B.rtb_Gain1_i_idx_0 = 1.0;
      } else if (modello_completo_B.rtb_Gain1_i_idx_0 == 0.0) {
        modello_completo_B.rtb_Gain1_i_idx_0 = 0.0;
      } else {
        modello_completo_B.rtb_Gain1_i_idx_0 = (rtNaN);
      }

      /* End of Signum: '<S525>/Sign1' */
      modello_completo_B.IProdOut = ((modello_completo_B.Gain3 +
        modello_completo_P.Bias_Bias) * modello_completo_P.Gain_Gain_b +
        modello_completo_P.Bias1_Bias) * modello_completo_B.rtb_Gain1_i_idx_0;
      modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_P.Constant_Value_n;
    } else {
      modello_completo_B.IProdOut = modello_completo_B.rtb_Gain1_i_idx_0;
      modello_completo_B.rtb_Gain1_i_idx_0 =
        modello_completo_P.Constant1_Value_p;
    }

    /* End of Switch: '<S525>/Switch' */

    /* Switch: '<S532>/Switch' incorporates:
     *  Abs: '<S532>/Abs'
     *  Bias: '<S532>/Bias'
     *  Bias: '<S532>/Bias1'
     *  Constant: '<S532>/Constant2'
     *  Constant: '<S536>/Constant'
     *  Math: '<S532>/Math Function1'
     *  RelationalOperator: '<S536>/Compare'
     */
    if (fabs(modello_completo_B.Al_selector) >
        modello_completo_P.CompareToConstant_const_p) {
      modello_completo_B.Al_selector = rt_modd_snf
        (modello_completo_B.Al_selector + modello_completo_P.Bias_Bias_jc,
         modello_completo_P.Constant2_Value_b) +
        modello_completo_P.Bias1_Bias_gb;
    }

    /* End of Switch: '<S532>/Switch' */

    /* Sum: '<S522>/Sum' incorporates:
     *  Gain: '<S460>/Gain'
     *  Sum: '<S457>/Sum1'
     */
    modello_completo_B.Al_selector = (modello_completo_P.Gain_Gain_d *
      modello_completo_B.Gain1_p - modello_completo_B.Al_selector) +
      modello_completo_B.rtb_Gain1_i_idx_0;

    /* Gain: '<S521>/Gain1' */
    modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_P.Gain1_Gain *
      modello_completo_B.IProdOut;

    /* Sum: '<S539>/Sum' incorporates:
     *  Constant: '<S539>/Constant'
     *  Constant: '<S539>/f'
     */
    modello_completo_B.IProdOut = modello_completo_P.f_Value -
      modello_completo_P.Constant_Value_j;

    /* Sqrt: '<S540>/Sqrt' incorporates:
     *  Constant: '<S540>/Constant4'
     *  Product: '<S540>/Product'
     *  Sum: '<S540>/Sum'
     */
    modello_completo_B.IProdOut = sqrt(modello_completo_P.Constant4_Value_o -
      modello_completo_B.IProdOut * modello_completo_B.IProdOut);

    /* Gain: '<S538>/Gain1' */
    modello_completo_B.Switch_bk *= modello_completo_P.Gain1_Gain_j;

    /* Trigonometry: '<S541>/Trigonometric Function1' */
    modello_completo_B.PWM_elevator_l = sin(modello_completo_B.Switch_bk);

    /* Sum: '<S541>/Sum1' incorporates:
     *  Constant: '<S541>/Constant'
     *  Product: '<S541>/Product1'
     */
    modello_completo_B.PWM_elevator_l = modello_completo_P.Constant_Value_nw -
      modello_completo_B.IProdOut * modello_completo_B.IProdOut *
      modello_completo_B.PWM_elevator_l * modello_completo_B.PWM_elevator_l;

    /* Product: '<S537>/Product1' incorporates:
     *  Constant: '<S537>/Constant1'
     *  Sqrt: '<S537>/sqrt'
     */
    modello_completo_B.Gain3 = modello_completo_P.Constant1_Value_j / sqrt
      (modello_completo_B.PWM_elevator_l);

    /* Switch: '<S526>/Switch' incorporates:
     *  Abs: '<S526>/Abs'
     *  Bias: '<S526>/Bias'
     *  Bias: '<S526>/Bias1'
     *  Constant: '<S526>/Constant2'
     *  Constant: '<S530>/Constant'
     *  Math: '<S526>/Math Function1'
     *  RelationalOperator: '<S530>/Compare'
     */
    if (fabs(modello_completo_B.Al_selector) >
        modello_completo_P.CompareToConstant_const_g) {
      modello_completo_B.Al_selector = rt_modd_snf
        (modello_completo_B.Al_selector + modello_completo_P.Bias_Bias_j,
         modello_completo_P.Constant2_Value_gk) +
        modello_completo_P.Bias1_Bias_g;
    }

    /* End of Switch: '<S526>/Switch' */

    /* Sum: '<S524>/Sum2' incorporates:
     *  Constant: '<S537>/Constant'
     *  Constant: '<S537>/Constant2'
     *  Constant: '<S537>/Constant3'
     *  Gain: '<S521>/Gain1'
     *  Product: '<S524>/dEast'
     *  Product: '<S524>/dNorth'
     *  Product: '<S524>/x*cos'
     *  Product: '<S524>/y*sin'
     *  Product: '<S537>/Product2'
     *  Product: '<S537>/Product3'
     *  Product: '<S537>/Product4'
     *  Sum: '<S537>/Sum1'
     *  Trigonometry: '<S537>/Trigonometric Function'
     *  Trigonometry: '<S537>/Trigonometric Function1'
     *  Trigonometry: '<S537>/Trigonometric Function2'
     */
    modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_B.rtb_Gain1_i_idx_0 /
      rt_atan2d_snf(modello_completo_P.Constant2_Value_j,
                    (modello_completo_P.Constant_Value_h -
                     modello_completo_B.IProdOut * modello_completo_B.IProdOut) *
                    modello_completo_B.Gain3 / modello_completo_B.PWM_elevator_l)
      * modello_completo_B.deltafalllimit + 1.0 / rt_atan2d_snf
      (modello_completo_P.Constant3_Value_f, modello_completo_B.Gain3 * cos
       (modello_completo_B.Switch_bk)) * (modello_completo_P.Gain1_Gain *
      modello_completo_B.Al_selector) * modello_completo_B.Gain_o;

    /* Gain: '<S462>/Gain' */
    modello_completo_B.PWM_elevator_l = modello_completo_P.Gain_Gain_o *
      modello_completo_B.Gain1_f;

    /* Gain: '<S463>/Gain' */
    modello_completo_B.Gain_n = modello_completo_P.Gain_Gain_ov *
      modello_completo_B.Gain1_p;

    /* MATLAB Function: '<S440>/ALLINEAMENTO' incorporates:
     *  Memory: '<S440>/Memory7'
     */
    modello_completo_B.b_a_tmp = modello_completo_B.WP_param_c[(int32_T)
      modello_completo_DW.Memory7_PreviousInput + 11];
    modello_completo_B.deltafalllimit = sin((modello_completo_B.b_a_tmp -
      modello_completo_B.PWM_elevator_l) * 3.1415926535897931 / 180.0 / 2.0);
    modello_completo_B.dist_fut = modello_completo_B.WP_param_c[(int32_T)
      modello_completo_DW.Memory7_PreviousInput + 14];
    modello_completo_B.dist = (modello_completo_B.dist_fut -
      modello_completo_B.Gain_n) * 3.1415926535897931 / 180.0;
    modello_completo_B.Switch_bk = sin(modello_completo_B.dist / 2.0);
    modello_completo_B.Al_selector = modello_completo_B.b_a_tmp *
      3.1415926535897931 / 180.0;
    modello_completo_B.Gain3 = cos(modello_completo_B.Al_selector);
    modello_completo_B.a_tmp_tmp = modello_completo_B.PWM_elevator_l *
      3.1415926535897931 / 180.0;
    modello_completo_B.Gain_o = cos(modello_completo_B.a_tmp_tmp);
    modello_completo_B.deltafalllimit = modello_completo_B.Gain_o *
      modello_completo_B.Gain3 * (modello_completo_B.Switch_bk *
      modello_completo_B.Switch_bk) + modello_completo_B.deltafalllimit *
      modello_completo_B.deltafalllimit;
    modello_completo_B.Switch_bk = rt_atan2d_snf(sqrt
      (modello_completo_B.deltafalllimit), sqrt(1.0 -
      modello_completo_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    if (modello_completo_DW.Memory7_PreviousInput > 1.0) {
      modello_completo_B.a_tmp_tmp = modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 1.0) + 11];
      modello_completo_B.Al_selector = modello_completo_B.a_tmp_tmp *
        3.1415926535897931 / 180.0;
      modello_completo_B.deltafalllimit = cos(modello_completo_B.Al_selector);
      modello_completo_B.dist = modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 1.0) + 14];
      modello_completo_B.psi_ref_tmp = (modello_completo_B.dist_fut -
        modello_completo_B.dist) * 3.1415926535897931 / 180.0;
      modello_completo_B.Al_selector = rt_atan2d_snf(sin
        (modello_completo_B.psi_ref_tmp) * modello_completo_B.Gain3, sin
        (modello_completo_B.WP_param_c[(int32_T)
         modello_completo_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * modello_completo_B.deltafalllimit - sin
        (modello_completo_B.Al_selector) * modello_completo_B.Gain3 * cos
        (modello_completo_B.psi_ref_tmp)) * 180.0 / 3.1415926535897931;
      modello_completo_B.a_tmp_tmp = sin((modello_completo_B.PWM_elevator_l -
        modello_completo_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      modello_completo_B.dist = sin((modello_completo_B.Gain_n -
        modello_completo_B.dist) * 3.1415926535897931 / 180.0 / 2.0);
      modello_completo_B.deltafalllimit = modello_completo_B.deltafalllimit *
        modello_completo_B.Gain_o * (modello_completo_B.dist *
        modello_completo_B.dist) + modello_completo_B.a_tmp_tmp *
        modello_completo_B.a_tmp_tmp;
      modello_completo_B.dist = rt_atan2d_snf(sqrt
        (modello_completo_B.deltafalllimit), sqrt(1.0 -
        modello_completo_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    } else {
      modello_completo_B.Al_selector = rt_atan2d_snf(sin(modello_completo_B.dist)
        * modello_completo_B.Gain3, sin(modello_completo_B.Al_selector) *
        modello_completo_B.Gain_o - cos(modello_completo_B.dist) * (sin
        (modello_completo_B.a_tmp_tmp) * modello_completo_B.Gain3)) * 180.0 /
        3.1415926535897931;
      modello_completo_B.dist = 0.0;
    }

    if (modello_completo_B.Al_selector < 0.0) {
      modello_completo_B.Al_selector = 360.0 - fabs
        (modello_completo_B.Al_selector);
    }

    modello_completo_B.deltafalllimit = modello_completo_B.WP_param_c[(int32_T)
      modello_completo_DW.Memory7_PreviousInput + 2];
    if (modello_completo_B.deltafalllimit == 1.0) {
      modello_completo_B.psi_ref_tmp = modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput + 1.0) + 11];
      modello_completo_B.a_tmp_tmp = sin((modello_completo_B.psi_ref_tmp -
        modello_completo_B.b_a_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      modello_completo_B.b_a_tmp = (modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput + 1.0) + 14] -
        modello_completo_B.dist_fut) * 3.1415926535897931 / 180.0;
      modello_completo_B.dist_fut = sin(modello_completo_B.b_a_tmp / 2.0);
      modello_completo_B.psi_ref_tmp = modello_completo_B.psi_ref_tmp *
        3.1415926535897931 / 180.0;
      modello_completo_B.a_fut_tmp = cos(modello_completo_B.psi_ref_tmp);
      modello_completo_B.dist_fut = modello_completo_B.Gain3 *
        modello_completo_B.a_fut_tmp * (modello_completo_B.dist_fut *
        modello_completo_B.dist_fut) + modello_completo_B.a_tmp_tmp *
        modello_completo_B.a_tmp_tmp;
      modello_completo_B.dist_fut = rt_atan2d_snf(sqrt
        (modello_completo_B.dist_fut), sqrt(1.0 - modello_completo_B.dist_fut)) *
        2.0 * 6.378137E+6;
      modello_completo_B.Gain3 = rt_atan2d_snf(sin(modello_completo_B.b_a_tmp) *
        modello_completo_B.a_fut_tmp, sin(modello_completo_B.psi_ref_tmp) *
        modello_completo_B.Gain3 - cos(modello_completo_B.b_a_tmp) * (sin
        (modello_completo_B.WP_param_c[(int32_T)
         modello_completo_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * modello_completo_B.a_fut_tmp)) * 180.0 / 3.1415926535897931;
      if (modello_completo_B.Gain3 < 0.0) {
        modello_completo_B.Gain3 = 360.0 - fabs(modello_completo_B.Gain3);
      }

      if (modello_completo_DW.Memory7_PreviousInput > 1.0) {
        modello_completo_B.Gain3 = fabs(modello_completo_B.Gain3 -
          modello_completo_B.Al_selector);
      } else {
        modello_completo_B.Gain3 = fabs(modello_completo_B.Gain3 - rt_atan2d_snf
          (sin((modello_completo_B.WP_param_c[(int32_T)
                modello_completo_DW.Memory7_PreviousInput + 14] -
                modello_completo_B.Gain_n) * 3.1415926535897931 / 180.0) * cos
           (modello_completo_B.WP_param_c[(int32_T)
            modello_completo_DW.Memory7_PreviousInput + 11] * 3.1415926535897931
            / 180.0), sin(modello_completo_B.WP_param_c[(int32_T)
                          modello_completo_DW.Memory7_PreviousInput + 11] *
                          3.1415926535897931 / 180.0) * cos
           (modello_completo_B.PWM_elevator_l * 3.1415926535897931 / 180.0) -
           cos(modello_completo_B.WP_param_c[(int32_T)
               modello_completo_DW.Memory7_PreviousInput + 11] *
               3.1415926535897931 / 180.0) * sin
           (modello_completo_B.PWM_elevator_l * 3.1415926535897931 / 180.0) *
           cos((modello_completo_B.WP_param_c[(int32_T)
                modello_completo_DW.Memory7_PreviousInput + 14] -
                modello_completo_B.Gain_n) * 3.1415926535897931 / 180.0)) *
          180.0 / 3.1415926535897931);
      }
    } else {
      modello_completo_B.dist_fut = 0.0;
      modello_completo_B.Gain3 = 0.0;
    }

    if (modello_completo_DW.Memory7_PreviousInput < 2.0) {
      modello_completo_B.Gain_o = 0.0;
    } else if (modello_completo_DW.Memory7_PreviousInput == 2.0) {
      modello_completo_B.b_a_tmp = cos(modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      modello_completo_B.Gain_n = (modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 1.0) + 14] -
        modello_completo_B.Gain_n) * 3.1415926535897931 / 180.0;
      modello_completo_B.Gain_o = fabs(modello_completo_B.Al_selector -
        rt_atan2d_snf(sin(modello_completo_B.Gain_n) *
                      modello_completo_B.b_a_tmp, sin
                      (modello_completo_B.WP_param_c[(int32_T)
                       (modello_completo_DW.Memory7_PreviousInput - 1.0) + 11] *
                       3.1415926535897931 / 180.0) * modello_completo_B.Gain_o -
                      cos(modello_completo_B.Gain_n) * (sin
        (modello_completo_B.PWM_elevator_l * 3.1415926535897931 / 180.0) *
        modello_completo_B.b_a_tmp)) * 180.0 / 3.1415926535897931);
    } else {
      modello_completo_B.Gain_o = cos(modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      modello_completo_B.PWM_elevator_l = modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 2.0) + 11] *
        3.1415926535897931 / 180.0;
      modello_completo_B.Gain_n = (modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 1.0) + 14] -
        modello_completo_B.WP_param_c[(int32_T)
        (modello_completo_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      modello_completo_B.Gain_o = rt_atan2d_snf(sin(modello_completo_B.Gain_n) *
        modello_completo_B.Gain_o, cos(modello_completo_B.PWM_elevator_l) * sin
        (modello_completo_B.WP_param_c[(int32_T)
         (modello_completo_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0) - sin(modello_completo_B.PWM_elevator_l) *
        modello_completo_B.Gain_o * cos(modello_completo_B.Gain_n)) * 180.0 /
        3.1415926535897931;
      if (modello_completo_B.Gain_o < 0.0) {
        modello_completo_B.Gain_o = 360.0 - fabs(modello_completo_B.Gain_o);
      }

      modello_completo_B.Gain_o = fabs(modello_completo_B.Al_selector -
        modello_completo_B.Gain_o);
    }

    if (modello_completo_B.Gain3 <= 3.0) {
      modello_completo_B.Al_selector = 1.0;
      modello_completo_B.AL = 20;
    } else if (modello_completo_B.Gain3 <= 10.0) {
      modello_completo_B.Al_selector = 30.0;
      modello_completo_B.AL = 100;
    } else if ((modello_completo_B.Gain3 > 10.0) && (modello_completo_B.Gain3 <=
                50.0)) {
      modello_completo_B.Al_selector = 80.0;
      modello_completo_B.AL = 250;
    } else if ((modello_completo_B.Gain3 > 50.0) && (modello_completo_B.Gain3 <=
                90.0)) {
      modello_completo_B.Al_selector = 100.0;
      modello_completo_B.AL = 300;
    } else if ((modello_completo_B.Gain3 > 90.0) && (modello_completo_B.Gain3 <=
                120.0)) {
      modello_completo_B.Al_selector = 150.0;
      modello_completo_B.AL = 350;
    } else {
      modello_completo_B.Al_selector = 200.0;
      modello_completo_B.AL = 400;
    }

    if (modello_completo_B.Gain_o <= 10.0) {
      modello_completo_B.caso = 80;
    } else if ((modello_completo_B.Gain_o > 10.0) && (modello_completo_B.Gain_o <=
                50.0)) {
      modello_completo_B.caso = 200;
    } else if ((modello_completo_B.Gain_o > 50.0) && (modello_completo_B.Gain_o <=
                90.0)) {
      modello_completo_B.caso = 300;
    } else if ((modello_completo_B.Gain_o > 90.0) && (modello_completo_B.Gain_o <=
                120.0)) {
      modello_completo_B.caso = 350;
    } else {
      modello_completo_B.caso = 400;
    }

    if (modello_completo_B.deltafalllimit == 1.0) {
      modello_completo_B.deltafalllimit = modello_completo_B.WP_param_c[(int32_T)
        modello_completo_DW.Memory7_PreviousInput - 1];
      if (modello_completo_B.deltafalllimit <= 20.0) {
        modello_completo_B.Al_selector *= 1.1;
      } else if ((modello_completo_B.deltafalllimit <= 25.0) &&
                 (modello_completo_B.deltafalllimit > 20.0)) {
        modello_completo_B.Al_selector *= 1.2;
      } else if (modello_completo_B.deltafalllimit <= 30.0) {
        if (modello_completo_B.deltafalllimit > 25.0) {
          modello_completo_B.Al_selector *= 1.3;
        } else {
          modello_completo_B.Al_selector *= 1.4;
        }
      } else {
        modello_completo_B.Al_selector *= 1.4;
      }

      if (((!(modello_completo_B.dist < modello_completo_B.caso)) ||
           (!(modello_completo_B.Switch_bk > modello_completo_B.Al_selector))) &&
          ((!(modello_completo_B.dist > modello_completo_B.caso)) ||
           (!(modello_completo_B.Switch_bk > modello_completo_B.Al_selector))) &&
          (modello_completo_B.Switch_bk < modello_completo_B.Al_selector)) {
        if (modello_completo_B.dist_fut > modello_completo_B.AL) {
          modello_completo_DW.Memory7_PreviousInput++;
        } else if (modello_completo_DW.Memory7_PreviousInput < 2.0) {
          modello_completo_DW.Memory7_PreviousInput += 2.0;
        } else {
          modello_completo_DW.flag_c = 1.0;
        }
      }
    } else {
      if (((!(modello_completo_B.dist < modello_completo_B.caso)) ||
           (!(modello_completo_DW.flag_c == 0.0))) &&
          ((!(modello_completo_B.dist > modello_completo_B.caso)) ||
           (!(modello_completo_B.Switch_bk > 40.0)) ||
           (!(modello_completo_DW.flag_c == 0.0)))) {
        modello_completo_DW.flag_c = 1.0;
      }
    }

    if (!(modello_completo_B.modo == 4.0)) {
      modello_completo_DW.Memory7_PreviousInput = 1.0;
    }

    /* End of MATLAB Function: '<S440>/ALLINEAMENTO' */

    /* Abs: '<S440>/Abs1' */
    modello_completo_B.deltafalllimit = fabs
      (modello_completo_B.rtb_Gain1_i_idx_0);

    /* Chart: '<S440>/Chart1' incorporates:
     *  DataTypeConversion: '<S554>/Data Type Conversion5'
     *  Memory: '<S440>/Memory1'
     *  Memory: '<S440>/Memory2'
     *  Memory: '<S440>/Memory5'
     */
    if (modello_completo_DW.is_active_c10_modello_completo == 0U) {
      modello_completo_DW.is_active_c10_modello_completo = 1U;
      modello_completo_B.maneuver_selector = 1.0;
      modello_completo_B.trig_approach = 0.0;
      modello_completo_B.trig_flare = 0.0;
      modello_completo_B.approach_selector = 1.0;
      modello_completo_DW.is_c10_modello_completo =
        modello_completo_IN_Allignment1;
    } else {
      switch (modello_completo_DW.is_c10_modello_completo) {
       case modello_completo_IN_Abort:
        modello_completo_B.maneuver_selector = 1.0;
        modello_completo_B.trig_approach = 0.0;
        modello_completo_B.trig_flare = 0.0;
        modello_completo_B.approach_selector = 0.0;
        break;

       case modello_completo_IN_Allignment:
        if ((modello_completo_B.ByteUnpack_o2_e[2] > 35.0F) &&
            (modello_completo_B.ByteUnpack_o2_e[2] < 60.0F) &&
            (modello_completo_B.deltafalllimit <=
             modello_completo_B.ByteUnpack_o2_e[2] * 19.081136687728211 + 100.0)
            && (modello_completo_B.deltafalllimit >=
                modello_completo_B.ByteUnpack_o2_e[2] * 14.300666256711928 +
                100.0) && (modello_completo_DW.Memory7_PreviousInput > 1.0)) {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Approach;
        } else if (modello_completo_B.modo != 4.0) {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Allignment1;
        } else {
          modello_completo_B.trig_flare = 0.0;
          modello_completo_B.approach_selector = 0.0;
          modello_completo_B.maneuver_selector = 1.0;
          modello_completo_B.trig_approach = 0.0;
        }
        break;

       case modello_completo_IN_Allignment1:
        if (modello_completo_B.modo == 4.0) {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Allignment;
        } else {
          modello_completo_B.maneuver_selector = 1.0;
          modello_completo_B.trig_approach = 0.0;
          modello_completo_B.trig_flare = 0.0;
          modello_completo_B.approach_selector = 0.0;
        }
        break;

       case modello_completo_IN_Approach:
        if ((modello_completo_B.rtb_Gain1_i_idx_0 >=
             modello_completo_DW.Memory5_PreviousInput) &&
            ((modello_completo_B.ByteUnpack_o2_e[2] <=
              modello_completo_DW.Memory1_PreviousInput_l + 1.5) ||
             (modello_completo_B.ByteUnpack_o2_e[2] >
              modello_completo_DW.Memory1_PreviousInput_l - 1.0))) {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Flare;
        } else if (modello_completo_B.modo != 4.0) {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Allignment1;
        } else if (modello_completo_DW.Memory2_PreviousInput_f == 1.0) {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Abort;
        } else {
          modello_completo_B.trig_flare = 0.0;
          modello_completo_B.trig_approach = 1.0;
          modello_completo_B.approach_selector = 1.0;
          modello_completo_B.maneuver_selector = 2.0;
        }
        break;

       default:
        /* case IN_Flare: */
        if ((modello_completo_B.Product1 < 3.0) || (!(modello_completo_B.modo !=
              4.0))) {
          modello_completo_B.trig_approach = 0.0;
          modello_completo_B.trig_flare = 1.0;
          modello_completo_B.approach_selector = 0.0;
          modello_completo_B.maneuver_selector = 3.0;
        } else {
          modello_completo_DW.is_c10_modello_completo =
            modello_completo_IN_Allignment1;
        }
        break;
      }
    }

    /* End of Chart: '<S440>/Chart1' */

    /* Outputs for Triggered SubSystem: '<S440>/Sample and Hold' incorporates:
     *  TriggerPort: '<S465>/Trigger'
     */
    modello_completo_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &modello_completo_PrevZCX.SampleandHold_Trig_ZCE,
      (modello_completo_B.approach_selector));
    if (modello_completo_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S465>/In' incorporates:
       *  Abs: '<S440>/Abs2'
       *  Constant: '<S440>/Constant4'
       *  DataTypeConversion: '<S554>/Data Type Conversion5'
       *  Sum: '<S457>/Sum'
       *  UnaryMinus: '<S457>/Ze2height'
       */
      modello_completo_B.In[0] = fabs(-(modello_completo_B.ByteUnpack_o2_e[2] +
        modello_completo_P.Constant4_Value_j));
      modello_completo_B.In[1] = modello_completo_B.rtb_Gain1_i_idx_0;
    }

    /* End of Outputs for SubSystem: '<S440>/Sample and Hold' */

    /* Outputs for Enabled SubSystem: '<S440>/APPROACH' incorporates:
     *  EnablePort: '<S451>/Enable'
     */
    if (modello_completo_B.trig_approach > 0.0) {
      /* Product: '<S451>/Divide' incorporates:
       *  Constant: '<S451>/x_g0'
       *  Sum: '<S451>/Sum'
       */
      modello_completo_B.IProdOut = modello_completo_B.In[0] /
        (modello_completo_B.In[1] - modello_completo_P.x_g0_Value);

      /* Abs: '<S451>/Abs' incorporates:
       *  Trigonometry: '<S451>/Atan'
       */
      modello_completo_B.Product1 = fabs(atan(modello_completo_B.IProdOut));

      /* DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
      if ((modello_completo_B.trig_approach > 0.0) &&
          (modello_completo_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
        modello_completo_DW.DiscreteTimeIntegrator_DSTATE =
          modello_completo_P.DiscreteTimeIntegrator_IC;
      }

      if (modello_completo_DW.DiscreteTimeIntegrator_DSTATE >=
          modello_completo_P.DiscreteTimeIntegrator_UpperSat) {
        modello_completo_DW.DiscreteTimeIntegrator_DSTATE =
          modello_completo_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (modello_completo_DW.DiscreteTimeIntegrator_DSTATE <=
            modello_completo_P.DiscreteTimeIntegrator_LowerSat) {
          modello_completo_DW.DiscreteTimeIntegrator_DSTATE =
            modello_completo_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      /* Switch: '<S451>/Switch' incorporates:
       *  Constant: '<S451>/Constant3'
       *  Constant: '<S451>/Constant4'
       *  DiscreteIntegrator: '<S451>/Discrete-Time Integrator'
       */
      if (modello_completo_DW.DiscreteTimeIntegrator_DSTATE >
          modello_completo_P.Switch_Threshold) {
        modello_completo_B.deltafalllimit = modello_completo_P.Constant3_Value;
      } else {
        modello_completo_B.deltafalllimit = modello_completo_P.Constant4_Value;
      }

      /* End of Switch: '<S451>/Switch' */

      /* MATLAB Function: '<S451>/MATLAB Function' */
      modello_completo_B.AL = 0;
      if ((!modello_completo_DW.x_not_empty) ||
          (modello_completo_B.deltafalllimit == 0.0)) {
        modello_completo_DW.x[0] = 1.5;
        modello_completo_DW.x[1] = -200.0;
        modello_completo_DW.x[2] = 0.01;
        modello_completo_DW.x[3] = -2.0;
        modello_completo_DW.x_not_empty = true;
      }

      modello_completo_DW.x_new_not_empty =
        ((!modello_completo_DW.x_new_not_empty) ||
         (modello_completo_B.deltafalllimit == 0.0) ||
         modello_completo_DW.x_new_not_empty);
      if ((!modello_completo_DW.eps_not_empty) ||
          (modello_completo_B.deltafalllimit == 0.0)) {
        modello_completo_DW.eps[0] = 1.0;
        modello_completo_DW.eps[1] = 1.0;
        modello_completo_DW.eps[2] = 1.0;
        modello_completo_DW.eps[3] = 1.0;
        modello_completo_DW.eps_not_empty = true;
      }

      if ((!modello_completo_DW.cycle_count_not_empty) ||
          (modello_completo_B.deltafalllimit == 0.0)) {
        modello_completo_DW.cycle_count = 0.0;
        modello_completo_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(modello_completo_DW.eps[0] < 0.1)) ||
                           ((!(modello_completo_DW.eps[1] < 0.1)) ||
                            ((!(modello_completo_DW.eps[2] < 0.1)) ||
                             (!(modello_completo_DW.eps[3] < 0.1)))))) {
        memset(&modello_completo_B.a[0], 0, sizeof(real_T) << 4U);
        modello_completo_B.Switch_bk = exp((5.0 - modello_completo_DW.x[1]) *
          -modello_completo_DW.x[2]);
        modello_completo_B.Gain3 = tan(modello_completo_B.Product1);
        modello_completo_B.A[0] = 1.0;
        modello_completo_B.A[4] = modello_completo_B.Gain3;
        modello_completo_B.A[8] = 0.0;
        modello_completo_B.A[12] = 0.0;
        modello_completo_B.A[1] = modello_completo_DW.x[2];
        modello_completo_B.A[5] = 0.0;
        modello_completo_B.Al_selector = modello_completo_DW.x[0] -
          modello_completo_DW.x[3];
        modello_completo_B.A[9] = modello_completo_B.Al_selector;
        modello_completo_B.A[13] = -modello_completo_DW.x[2];
        modello_completo_B.A[2] = modello_completo_B.Switch_bk;
        modello_completo_B.PWM_elevator_l = modello_completo_B.Al_selector *
          modello_completo_DW.x[2];
        modello_completo_B.A[6] = modello_completo_B.PWM_elevator_l *
          modello_completo_B.Switch_bk;
        modello_completo_B.A[10] = modello_completo_B.Al_selector *
          (modello_completo_DW.x[1] - 5.0) * modello_completo_B.Switch_bk;
        modello_completo_B.A[14] = 1.0;
        modello_completo_B.A[3] = modello_completo_DW.x[2] * 18.0 *
          modello_completo_B.Switch_bk;
        modello_completo_B.A[7] = modello_completo_B.Al_selector *
          (modello_completo_DW.x[2] * modello_completo_DW.x[2]) * 18.0 *
          modello_completo_B.Switch_bk;
        modello_completo_B.Gain_o = modello_completo_B.PWM_elevator_l * 18.0;
        modello_completo_B.A[11] = modello_completo_B.Gain_o *
          (modello_completo_DW.x[1] - 5.0) * modello_completo_B.Switch_bk +
          modello_completo_B.Al_selector * 18.0 * modello_completo_B.Switch_bk;
        modello_completo_B.A[15] = -modello_completo_DW.x[2] * 18.0 *
          modello_completo_B.Switch_bk;
        modello_completo_B.ipiv[0] = 1;
        modello_completo_B.ipiv[1] = 2;
        modello_completo_B.ipiv[2] = 3;
        for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 3;
             modello_completo_B.ATO++) {
          modello_completo_B.caso = modello_completo_B.ATO * 5;
          modello_completo_B.g = 0;
          modello_completo_B.i = modello_completo_B.caso;
          modello_completo_B.deltafalllimit = fabs
            (modello_completo_B.A[modello_completo_B.caso]);
          modello_completo_B.jy = 2;
          while (modello_completo_B.jy <= 4 - modello_completo_B.ATO) {
            modello_completo_B.i++;
            modello_completo_B.Gain_n = fabs
              (modello_completo_B.A[modello_completo_B.i]);
            if (modello_completo_B.Gain_n > modello_completo_B.deltafalllimit) {
              modello_completo_B.g = modello_completo_B.jy - 1;
              modello_completo_B.deltafalllimit = modello_completo_B.Gain_n;
            }

            modello_completo_B.jy++;
          }

          if (modello_completo_B.A[modello_completo_B.caso +
              modello_completo_B.g] != 0.0) {
            if (modello_completo_B.g != 0) {
              modello_completo_B.g += modello_completo_B.ATO;
              modello_completo_B.ipiv[modello_completo_B.ATO] = (int8_T)
                (modello_completo_B.g + 1);
              modello_completo_B.deltafalllimit =
                modello_completo_B.A[modello_completo_B.ATO];
              modello_completo_B.A[modello_completo_B.ATO] =
                modello_completo_B.A[modello_completo_B.g];
              modello_completo_B.A[modello_completo_B.g] =
                modello_completo_B.deltafalllimit;
              modello_completo_B.deltafalllimit =
                modello_completo_B.A[modello_completo_B.ATO + 4];
              modello_completo_B.A[modello_completo_B.ATO + 4] =
                modello_completo_B.A[modello_completo_B.g + 4];
              modello_completo_B.A[modello_completo_B.g + 4] =
                modello_completo_B.deltafalllimit;
              modello_completo_B.deltafalllimit =
                modello_completo_B.A[modello_completo_B.ATO + 8];
              modello_completo_B.A[modello_completo_B.ATO + 8] =
                modello_completo_B.A[modello_completo_B.g + 8];
              modello_completo_B.A[modello_completo_B.g + 8] =
                modello_completo_B.deltafalllimit;
              modello_completo_B.deltafalllimit =
                modello_completo_B.A[modello_completo_B.ATO + 12];
              modello_completo_B.A[modello_completo_B.ATO + 12] =
                modello_completo_B.A[modello_completo_B.g + 12];
              modello_completo_B.A[modello_completo_B.g + 12] =
                modello_completo_B.deltafalllimit;
            }

            modello_completo_B.i = (modello_completo_B.caso -
              modello_completo_B.ATO) + 4;
            modello_completo_B.g = modello_completo_B.caso + 1;
            while (modello_completo_B.g + 1 <= modello_completo_B.i) {
              modello_completo_B.A[modello_completo_B.g] /=
                modello_completo_B.A[modello_completo_B.caso];
              modello_completo_B.g++;
            }
          }

          modello_completo_B.i = modello_completo_B.caso;
          modello_completo_B.jy = modello_completo_B.caso + 4;
          modello_completo_B.c = 0;
          while (modello_completo_B.c <= 2 - modello_completo_B.ATO) {
            if (modello_completo_B.A[modello_completo_B.jy] != 0.0) {
              modello_completo_B.deltafalllimit =
                -modello_completo_B.A[modello_completo_B.jy];
              modello_completo_B.c_ix = modello_completo_B.caso + 1;
              modello_completo_B.g = (modello_completo_B.i -
                modello_completo_B.ATO) + 8;
              modello_completo_B.ijA = modello_completo_B.i + 5;
              while (modello_completo_B.ijA + 1 <= modello_completo_B.g) {
                modello_completo_B.A[modello_completo_B.ijA] +=
                  modello_completo_B.A[modello_completo_B.c_ix] *
                  modello_completo_B.deltafalllimit;
                modello_completo_B.c_ix++;
                modello_completo_B.ijA++;
              }
            }

            modello_completo_B.jy += 4;
            modello_completo_B.i += 4;
            modello_completo_B.c++;
          }
        }

        modello_completo_B.p[0] = 1;
        modello_completo_B.p[1] = 2;
        modello_completo_B.p[2] = 3;
        modello_completo_B.p[3] = 4;
        if (modello_completo_B.ipiv[0] > 1) {
          modello_completo_B.ATO = modello_completo_B.p[modello_completo_B.ipiv
            [0] - 1];
          modello_completo_B.p[modello_completo_B.ipiv[0] - 1] = 1;
          modello_completo_B.p[0] = (int8_T)modello_completo_B.ATO;
        }

        if (modello_completo_B.ipiv[1] > 2) {
          modello_completo_B.ATO = modello_completo_B.p[modello_completo_B.ipiv
            [1] - 1];
          modello_completo_B.p[modello_completo_B.ipiv[1] - 1] =
            modello_completo_B.p[1];
          modello_completo_B.p[1] = (int8_T)modello_completo_B.ATO;
        }

        if (modello_completo_B.ipiv[2] > 3) {
          modello_completo_B.ATO = modello_completo_B.p[modello_completo_B.ipiv
            [2] - 1];
          modello_completo_B.p[modello_completo_B.ipiv[2] - 1] =
            modello_completo_B.p[2];
          modello_completo_B.p[2] = (int8_T)modello_completo_B.ATO;
        }

        modello_completo_B.c = modello_completo_B.p[0] - 1;
        modello_completo_B.a[(modello_completo_B.p[0] - 1) << 2] = 1.0;
        modello_completo_B.caso = 0;
        while (modello_completo_B.caso + 1 < 5) {
          modello_completo_B.ATO = modello_completo_B.c << 2;
          modello_completo_B.g = modello_completo_B.ATO +
            modello_completo_B.caso;
          if (modello_completo_B.a[modello_completo_B.g] != 0.0) {
            modello_completo_B.i = modello_completo_B.caso + 1;
            while (modello_completo_B.i + 1 < 5) {
              modello_completo_B.jy = modello_completo_B.ATO +
                modello_completo_B.i;
              modello_completo_B.a[modello_completo_B.jy] -=
                modello_completo_B.a[modello_completo_B.g] *
                modello_completo_B.A[(modello_completo_B.caso << 2) +
                modello_completo_B.i];
              modello_completo_B.i++;
            }
          }

          modello_completo_B.caso++;
        }

        modello_completo_B.c = modello_completo_B.p[1] - 1;
        modello_completo_B.a[((modello_completo_B.p[1] - 1) << 2) + 1] = 1.0;
        modello_completo_B.caso = 1;
        while (modello_completo_B.caso + 1 < 5) {
          modello_completo_B.ATO = modello_completo_B.c << 2;
          modello_completo_B.g = modello_completo_B.ATO +
            modello_completo_B.caso;
          if (modello_completo_B.a[modello_completo_B.g] != 0.0) {
            modello_completo_B.i = modello_completo_B.caso + 1;
            while (modello_completo_B.i + 1 < 5) {
              modello_completo_B.jy = modello_completo_B.ATO +
                modello_completo_B.i;
              modello_completo_B.a[modello_completo_B.jy] -=
                modello_completo_B.a[modello_completo_B.g] *
                modello_completo_B.A[(modello_completo_B.caso << 2) +
                modello_completo_B.i];
              modello_completo_B.i++;
            }
          }

          modello_completo_B.caso++;
        }

        modello_completo_B.c = modello_completo_B.p[2] - 1;
        modello_completo_B.a[((modello_completo_B.p[2] - 1) << 2) + 2] = 1.0;
        modello_completo_B.caso = 2;
        while (modello_completo_B.caso + 1 < 5) {
          modello_completo_B.ATO = modello_completo_B.c << 2;
          modello_completo_B.g = modello_completo_B.ATO +
            modello_completo_B.caso;
          if (modello_completo_B.a[modello_completo_B.g] != 0.0) {
            modello_completo_B.i = modello_completo_B.caso + 1;
            while (modello_completo_B.i + 1 < 5) {
              modello_completo_B.jy = modello_completo_B.ATO +
                modello_completo_B.i;
              modello_completo_B.a[modello_completo_B.jy] -=
                modello_completo_B.a[modello_completo_B.g] *
                modello_completo_B.A[(modello_completo_B.caso << 2) +
                modello_completo_B.i];
              modello_completo_B.i++;
            }
          }

          modello_completo_B.caso++;
        }

        modello_completo_B.jy = (modello_completo_B.p[3] - 1) << 2;
        modello_completo_B.a[modello_completo_B.jy + 3] = 1.0;
        modello_completo_B.caso = 3;
        while (modello_completo_B.caso + 1 < 5) {
          modello_completo_B.ATO = modello_completo_B.jy +
            modello_completo_B.caso;
          if (modello_completo_B.a[modello_completo_B.ATO] != 0.0) {
            modello_completo_B.i = modello_completo_B.caso + 1;
            while (modello_completo_B.i + 1 < 5) {
              modello_completo_B.g = modello_completo_B.jy +
                modello_completo_B.i;
              modello_completo_B.a[modello_completo_B.g] -=
                modello_completo_B.a[modello_completo_B.ATO] *
                modello_completo_B.A[(modello_completo_B.caso << 2) +
                modello_completo_B.i];
              modello_completo_B.i++;
            }
          }

          modello_completo_B.caso++;
        }

        for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 4;
             modello_completo_B.ATO++) {
          modello_completo_B.caso = modello_completo_B.ATO << 2;
          modello_completo_B.deltafalllimit =
            modello_completo_B.a[modello_completo_B.caso + 3];
          if (modello_completo_B.deltafalllimit != 0.0) {
            modello_completo_B.a[modello_completo_B.caso + 3] =
              modello_completo_B.deltafalllimit / modello_completo_B.A[15];
            modello_completo_B.g = 0;
            while (modello_completo_B.g <= 2) {
              modello_completo_B.jy = modello_completo_B.g +
                modello_completo_B.caso;
              modello_completo_B.a[modello_completo_B.jy] -=
                modello_completo_B.a[modello_completo_B.caso + 3] *
                modello_completo_B.A[modello_completo_B.g + 12];
              modello_completo_B.g++;
            }
          }

          modello_completo_B.deltafalllimit =
            modello_completo_B.a[modello_completo_B.caso + 2];
          if (modello_completo_B.deltafalllimit != 0.0) {
            modello_completo_B.a[modello_completo_B.caso + 2] =
              modello_completo_B.deltafalllimit / modello_completo_B.A[10];
            modello_completo_B.g = 0;
            while (modello_completo_B.g <= 1) {
              modello_completo_B.jy = modello_completo_B.g +
                modello_completo_B.caso;
              modello_completo_B.a[modello_completo_B.jy] -=
                modello_completo_B.a[modello_completo_B.caso + 2] *
                modello_completo_B.A[modello_completo_B.g + 8];
              modello_completo_B.g++;
            }
          }

          modello_completo_B.deltafalllimit =
            modello_completo_B.a[modello_completo_B.caso + 1];
          if (modello_completo_B.deltafalllimit != 0.0) {
            modello_completo_B.a[modello_completo_B.caso + 1] =
              modello_completo_B.deltafalllimit / modello_completo_B.A[5];
            modello_completo_B.a[modello_completo_B.caso] -=
              modello_completo_B.a[modello_completo_B.caso + 1] *
              modello_completo_B.A[4];
          }

          if (modello_completo_B.a[modello_completo_B.caso] != 0.0) {
            modello_completo_B.a[modello_completo_B.caso] /=
              modello_completo_B.A[0];
          }
        }

        modello_completo_B.deltafalllimit = (modello_completo_DW.x[1] -
          modello_completo_P.x_g0_Value) * modello_completo_B.Gain3 +
          modello_completo_DW.x[0];
        modello_completo_B.Gain3 = modello_completo_B.PWM_elevator_l -
          modello_completo_B.Gain3;
        modello_completo_B.Al_selector = modello_completo_B.Al_selector *
          modello_completo_B.Switch_bk + modello_completo_DW.x[3];
        modello_completo_B.Switch_bk = modello_completo_B.Gain_o *
          modello_completo_B.Switch_bk + -0.1;
        for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 4;
             modello_completo_B.ATO++) {
          modello_completo_B.x_new[modello_completo_B.ATO] =
            modello_completo_DW.x[modello_completo_B.ATO] -
            (((modello_completo_B.a[modello_completo_B.ATO + 4] *
               modello_completo_B.Gain3 +
               modello_completo_B.a[modello_completo_B.ATO] *
               modello_completo_B.deltafalllimit) +
              modello_completo_B.a[modello_completo_B.ATO + 8] *
              modello_completo_B.Al_selector) +
             modello_completo_B.a[modello_completo_B.ATO + 12] *
             modello_completo_B.Switch_bk);
        }

        modello_completo_DW.eps[0] = fabs(modello_completo_B.x_new[0] -
          modello_completo_DW.x[0]);
        modello_completo_DW.eps[1] = fabs(modello_completo_B.x_new[1] -
          modello_completo_DW.x[1]);
        modello_completo_DW.eps[2] = fabs(modello_completo_B.x_new[2] -
          modello_completo_DW.x[2]);
        modello_completo_DW.eps[3] = fabs(modello_completo_B.x_new[3] -
          modello_completo_DW.x[3]);
        modello_completo_DW.x[0] = modello_completo_B.x_new[0];
        modello_completo_DW.x[1] = modello_completo_B.x_new[1];
        modello_completo_DW.x[2] = modello_completo_B.x_new[2];
        modello_completo_DW.x[3] = modello_completo_B.x_new[3];
        modello_completo_DW.cycle_count++;
        if (modello_completo_DW.cycle_count > 10.0) {
          modello_completo_B.AL = 1;
          exitg1 = true;
        }
      }

      if ((modello_completo_DW.eps[0] < 0.1) && (modello_completo_DW.eps[1] <
           0.1) && (modello_completo_DW.eps[2] < 0.1) &&
          (modello_completo_DW.eps[3] < 0.1)) {
        modello_completo_B.h_f_out = modello_completo_DW.x[0];
        modello_completo_B.x_f_out = modello_completo_DW.x[1];
        modello_completo_B.k_x_out = modello_completo_DW.x[2];
        modello_completo_B.h_c_out = modello_completo_DW.x[3];
      } else {
        modello_completo_B.h_f_out = 0.0;
        modello_completo_B.x_f_out = 0.0;
        modello_completo_B.k_x_out = 0.0;
        modello_completo_B.h_c_out = 0.0;
      }

      modello_completo_B.no_solution = modello_completo_B.AL;

      /* End of MATLAB Function: '<S451>/MATLAB Function' */

      /* Product: '<S451>/Multiply' incorporates:
       *  Constant: '<S451>/x_g0'
       *  Gain: '<S451>/Gain'
       *  Sum: '<S451>/Sum1'
       */
      modello_completo_B.Multiply = (modello_completo_B.rtb_Gain1_i_idx_0 -
        modello_completo_P.x_g0_Value) * modello_completo_P.Gain_Gain_e0 *
        modello_completo_B.IProdOut;

      /* Update for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S451>/Constant2'
       */
      modello_completo_DW.DiscreteTimeIntegrator_DSTATE +=
        modello_completo_P.DiscreteTimeIntegrator_gainval *
        modello_completo_P.Constant2_Value_g;
      if (modello_completo_DW.DiscreteTimeIntegrator_DSTATE >=
          modello_completo_P.DiscreteTimeIntegrator_UpperSat) {
        modello_completo_DW.DiscreteTimeIntegrator_DSTATE =
          modello_completo_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (modello_completo_DW.DiscreteTimeIntegrator_DSTATE <=
            modello_completo_P.DiscreteTimeIntegrator_LowerSat) {
          modello_completo_DW.DiscreteTimeIntegrator_DSTATE =
            modello_completo_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      if (modello_completo_B.trig_approach > 0.0) {
        modello_completo_DW.DiscreteTimeIntegrator_PrevRese = 1;
      } else if (modello_completo_B.trig_approach < 0.0) {
        modello_completo_DW.DiscreteTimeIntegrator_PrevRese = -1;
      } else if (modello_completo_B.trig_approach == 0.0) {
        modello_completo_DW.DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        modello_completo_DW.DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
    }

    /* End of Outputs for SubSystem: '<S440>/APPROACH' */

    /* Outputs for Enabled SubSystem: '<S440>/FLARE' incorporates:
     *  EnablePort: '<S455>/Enable'
     */
    if (modello_completo_B.trig_flare > 0.0) {
      /* Sum: '<S455>/Sum2' incorporates:
       *  Gain: '<S455>/Gain'
       *  Math: '<S455>/Exp'
       *  Product: '<S455>/Multiply'
       *  Product: '<S455>/Multiply1'
       *  Sum: '<S455>/Sum'
       *  Sum: '<S455>/Sum1'
       *
       * About '<S455>/Exp':
       *  Operator: exp
       */
      modello_completo_B.Sum2 = exp((modello_completo_B.rtb_Gain1_i_idx_0 -
        modello_completo_B.x_f_out) * modello_completo_B.k_x_out *
        modello_completo_P.Gain_Gain_j) * (modello_completo_B.h_f_out -
        modello_completo_B.h_c_out) + modello_completo_B.h_c_out;
    }

    /* End of Outputs for SubSystem: '<S440>/FLARE' */

    /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' */
    switch ((int32_T)modello_completo_B.maneuver_selector) {
     case 1:
      /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Constant: '<S440>/Constant2'
       */
      modello_completo_B.QUOTA_m = modello_completo_P.Constant2_Value_n3;
      break;

     case 2:
      /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S440>/Abs3'
       */
      modello_completo_B.QUOTA_m = fabs(modello_completo_B.Multiply);
      break;

     default:
      /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S440>/Abs4'
       */
      modello_completo_B.QUOTA_m = fabs(modello_completo_B.Sum2);
      break;
    }

    /* End of MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' */

    /* Update for Memory: '<S440>/Memory5' */
    modello_completo_DW.Memory5_PreviousInput = modello_completo_B.x_f_out;

    /* Update for Memory: '<S440>/Memory1' */
    modello_completo_DW.Memory1_PreviousInput_l = modello_completo_B.h_f_out;

    /* Update for Memory: '<S440>/Memory2' */
    modello_completo_DW.Memory2_PreviousInput_f = modello_completo_B.no_solution;
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem1' */

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S21>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&modello_completo_B.iflogic,
    &modello_completo_B.DataTypeConversion3,
    &modello_completo_P.SIUAVuint8_Value, &modello_completo_B.GC_info[0],
    &modello_completo_B.Val_out_MAV[0], &modello_completo_B.WP_info[0],
    &modello_completo_B.WP_param[0],
    &modello_completo_P.onboard_control_sensor_presentu[0],
    &modello_completo_B.TmpSignalConversionAtSFunctionI[0],
    &modello_completo_B.Gain1, &modello_completo_B.B_Remaining,
    &modello_completo_B.DataTypeConversion,
    &modello_completo_B.TmpSignalConversionAtSFunctio_m[0],
    &modello_completo_B.DataTypeConversion_ld[0],
    &modello_completo_B.DataTypeConversion1[0],
    &modello_completo_B.DataTypeConversion_a[0],
    &modello_completo_B.DataTypeConversion1_p[0],
    &modello_completo_B.DataTypeConversion2_h, &modello_completo_B.AGAC[0],
    &modello_completo_B.Heading_g, &modello_completo_B.Throttle,
    &modello_completo_B.Heading[0], &modello_completo_B.Memory_a,
    &modello_completo_B.DataTypeConversion2, &modello_completo_B.SFunction_o14,
    &modello_completo_B.Switch1, &modello_completo_B.SFunction_o15,
    &modello_completo_B.DataTypeConversion_l,
    &modello_completo_B.DataTypeConversion1_g,
    &modello_completo_B.DataTypeConversion2_m, &modello_completo_B.SFunction_o5
    [0], &modello_completo_B.Gain, &modello_completo_B.Gain_g,
    &modello_completo_B.h_Home, ((const uint16_T*) &modello_completo_U16GND),
    &modello_completo_B.SFunction_o1_j, &modello_completo_B.SFunction_o2_f[0],
    &modello_completo_B.SFunction_o3, &modello_completo_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (modello_completo_B.SFunction_o1_j > 0) {
    /* Chart: '<S15>/Chart' */
    if (modello_completo_DW.is_active_c9_modello_completo == 0U) {
      modello_completo_DW.is_active_c9_modello_completo = 1U;
      modello_completo_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (modello_completo_DW.obj_o.Protocol !=
            modello_completo_P.SerialTransmit_Protocol) {
          modello_completo_DW.obj_o.Protocol =
            modello_completo_P.SerialTransmit_Protocol;
        }

        status = modello_completo_B.SFunction_o2_f[modello_completo_DW.i - 1];
        MW_Serial_write(modello_completo_DW.obj_o.port, &status, 1.0,
                        modello_completo_DW.obj_o.dataSizeInBytes,
                        modello_completo_DW.obj_o.sendModeEnum,
                        modello_completo_DW.obj_o.dataType,
                        modello_completo_DW.obj_o.sendFormatEnum, 2.0, '\x00');
        if (modello_completo_DW.i < modello_completo_B.SFunction_o3) {
          modello_completo_B.ATO = modello_completo_DW.i + 1;
          if (modello_completo_DW.i + 1 > 255) {
            modello_completo_B.ATO = 255;
          }

          modello_completo_DW.i = (uint8_T)modello_completo_B.ATO;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      modello_completo_DW.i = 1U;
    }

    /* End of Chart: '<S15>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S1>/Data Tversion' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (modello_completo_B.i = 0; modello_completo_B.i < 42; modello_completo_B.i
       ++) {
    modello_completo_B.DataTypeConversion4_m[modello_completo_B.i] =
      modello_completo_DW.WP_dbP[modello_completo_B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Tversion' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem2' incorporates:
   *  EnablePort: '<S441>/Enable'
   */
  if (modello_completo_B.Wp_selector > 0.0) {
    /* Gain: '<S542>/Gain' */
    modello_completo_B.PWM_elevator_l = modello_completo_P.Gain_Gain_bu *
      modello_completo_B.Gain1_f;

    /* Gain: '<S543>/Gain' */
    modello_completo_B.rtb_Gain1_i_idx_0 = modello_completo_P.Gain_Gain_jz *
      modello_completo_B.Gain1_p;

    /* MATLAB Function: '<S441>/WAYPOINTS' incorporates:
     *  DataTypeConversion: '<S1>/Data Tversion'
     *  DataTypeConversion: '<S1>/Data Tversion1'
     *  DataTypeConversion: '<S1>/Data Tversion2'
     *  DataTypeConversion: '<S554>/Data Type Conversion5'
     *  Memory: '<S441>/Memory4'
     */
    modello_completo_B.ATO = 1;
    if (modello_completo_DW.Memory4_PreviousInput == 6.0) {
      modello_completo_B.ATO = 0;
    }

    if ((uint8_T)modello_completo_B.GC_info[0] == 3) {
      modello_completo_DW.Memory4_PreviousInput = 1.0;
      modello_completo_DW.lat1 = modello_completo_B.PWM_elevator_l;
      modello_completo_DW.long1 = modello_completo_B.rtb_Gain1_i_idx_0;
      for (modello_completo_B.AL = 0; modello_completo_B.AL < 6;
           modello_completo_B.AL++) {
        if (modello_completo_DW.WP_dbI[modello_completo_B.AL + 24] == 1) {
          modello_completo_DW.Memory4_PreviousInput = (real_T)
            modello_completo_B.AL + 1.0;
        }
      }
    }

    modello_completo_B.Wp_selector = modello_completo_B.DataTypeConversion4_m
      [(int32_T)modello_completo_DW.Memory4_PreviousInput + 23];
    modello_completo_B.Product1 = modello_completo_B.DataTypeConversion4_m
      [(int32_T)modello_completo_DW.Memory4_PreviousInput + 29];
    modello_completo_B.QUOTA = modello_completo_B.DataTypeConversion4_m[(int32_T)
      modello_completo_DW.Memory4_PreviousInput + 35];
    modello_completo_B.deltafalllimit = sin((modello_completo_B.Wp_selector -
      modello_completo_B.PWM_elevator_l) * 3.1415926535897931 / 180.0 / 2.0);
    modello_completo_B.Switch_bk = sin((modello_completo_B.Product1 -
      modello_completo_B.rtb_Gain1_i_idx_0) * 3.1415926535897931 / 180.0 / 2.0);
    modello_completo_B.Al_selector = modello_completo_B.Wp_selector *
      3.1415926535897931 / 180.0;
    modello_completo_B.Gain3 = cos(modello_completo_B.Al_selector);
    modello_completo_B.Gain_o = cos(modello_completo_B.PWM_elevator_l *
      3.1415926535897931 / 180.0);
    modello_completo_B.deltafalllimit = modello_completo_B.Gain_o *
      modello_completo_B.Gain3 * (modello_completo_B.Switch_bk *
      modello_completo_B.Switch_bk) + modello_completo_B.deltafalllimit *
      modello_completo_B.deltafalllimit;
    modello_completo_B.Switch_bk = rt_atan2d_snf(sqrt
      (modello_completo_B.deltafalllimit), sqrt(1.0 -
      modello_completo_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    if (modello_completo_DW.Memory4_PreviousInput > 1.0) {
      modello_completo_B.a_tmp_tmp = modello_completo_B.DataTypeConversion4_m
        [(int32_T)(modello_completo_DW.Memory4_PreviousInput - 1.0) + 23];
      modello_completo_B.Al_selector = modello_completo_B.a_tmp_tmp *
        3.1415926535897931 / 180.0;
      modello_completo_B.deltafalllimit = cos(modello_completo_B.Al_selector);
      modello_completo_B.dist = modello_completo_B.DataTypeConversion4_m
        [(int32_T)(modello_completo_DW.Memory4_PreviousInput - 1.0) + 29];
      modello_completo_B.psi_ref_tmp = (modello_completo_B.Product1 -
        modello_completo_B.dist) * 3.1415926535897931 / 180.0;
      modello_completo_B.Al_selector = rt_atan2d_snf(sin
        (modello_completo_B.psi_ref_tmp) * modello_completo_B.Gain3, sin
        (modello_completo_B.DataTypeConversion4_m[(int32_T)
         modello_completo_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * modello_completo_B.deltafalllimit - sin
        (modello_completo_B.Al_selector) * modello_completo_B.Gain3 * cos
        (modello_completo_B.psi_ref_tmp)) * 180.0 / 3.1415926535897931;
      modello_completo_B.a_tmp_tmp = sin((modello_completo_B.PWM_elevator_l -
        modello_completo_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      modello_completo_B.dist = sin((modello_completo_B.rtb_Gain1_i_idx_0 -
        modello_completo_B.dist) * 3.1415926535897931 / 180.0 / 2.0);
      modello_completo_B.deltafalllimit = modello_completo_B.deltafalllimit *
        modello_completo_B.Gain_o * (modello_completo_B.dist *
        modello_completo_B.dist) + modello_completo_B.a_tmp_tmp *
        modello_completo_B.a_tmp_tmp;
      modello_completo_B.dist = rt_atan2d_snf(sqrt
        (modello_completo_B.deltafalllimit), sqrt(1.0 -
        modello_completo_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    } else {
      modello_completo_B.deltafalllimit = (modello_completo_B.Product1 -
        modello_completo_DW.long1) * 3.1415926535897931 / 180.0;
      modello_completo_B.psi_ref_tmp = modello_completo_DW.lat1 *
        3.1415926535897931 / 180.0;
      modello_completo_B.Al_selector = rt_atan2d_snf(sin
        (modello_completo_B.deltafalllimit) * modello_completo_B.Gain3, sin
        (modello_completo_B.Al_selector) * cos(modello_completo_B.psi_ref_tmp) -
        cos(modello_completo_B.deltafalllimit) * (sin
        (modello_completo_B.psi_ref_tmp) * modello_completo_B.Gain3)) * 180.0 /
        3.1415926535897931;
      modello_completo_B.dist = 0.0;
    }

    if (modello_completo_B.Al_selector < 0.0) {
      modello_completo_B.Al_selector = 360.0 - fabs
        (modello_completo_B.Al_selector);
    }

    if (modello_completo_B.ATO == 1) {
      modello_completo_B.psi_ref_tmp = modello_completo_B.DataTypeConversion4_m
        [(int32_T)(modello_completo_DW.Memory4_PreviousInput + 1.0) + 23];
      modello_completo_B.a_tmp_tmp = sin((modello_completo_B.psi_ref_tmp -
        modello_completo_B.Wp_selector) * 3.1415926535897931 / 180.0 / 2.0);
      modello_completo_B.b_a_tmp = (modello_completo_B.DataTypeConversion4_m
        [(int32_T)(modello_completo_DW.Memory4_PreviousInput + 1.0) + 29] -
        modello_completo_B.Product1) * 3.1415926535897931 / 180.0;
      modello_completo_B.dist_fut = sin(modello_completo_B.b_a_tmp / 2.0);
      modello_completo_B.psi_ref_tmp = modello_completo_B.psi_ref_tmp *
        3.1415926535897931 / 180.0;
      modello_completo_B.a_fut_tmp = cos(modello_completo_B.psi_ref_tmp);
      modello_completo_B.dist_fut = modello_completo_B.Gain3 *
        modello_completo_B.a_fut_tmp * (modello_completo_B.dist_fut *
        modello_completo_B.dist_fut) + modello_completo_B.a_tmp_tmp *
        modello_completo_B.a_tmp_tmp;
      modello_completo_B.dist_fut = rt_atan2d_snf(sqrt
        (modello_completo_B.dist_fut), sqrt(1.0 - modello_completo_B.dist_fut)) *
        2.0 * 6.378137E+6;
      modello_completo_B.Gain3 = rt_atan2d_snf(sin(modello_completo_B.b_a_tmp) *
        modello_completo_B.a_fut_tmp, sin(modello_completo_B.psi_ref_tmp) *
        modello_completo_B.Gain3 - cos(modello_completo_B.b_a_tmp) * (sin
        (modello_completo_B.DataTypeConversion4_m[(int32_T)
         modello_completo_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * modello_completo_B.a_fut_tmp)) * 180.0 / 3.1415926535897931;
      if (modello_completo_B.Gain3 < 0.0) {
        modello_completo_B.Gain3 = 360.0 - fabs(modello_completo_B.Gain3);
      }

      if (modello_completo_DW.Memory4_PreviousInput > 1.0) {
        modello_completo_B.Gain3 = fabs(modello_completo_B.Gain3 -
          modello_completo_B.Al_selector);
      } else {
        modello_completo_B.Gain3 = fabs(modello_completo_B.Gain3 - rt_atan2d_snf
          (sin((modello_completo_B.DataTypeConversion4_m[(int32_T)
                modello_completo_DW.Memory4_PreviousInput + 29] -
                modello_completo_DW.long1) * 3.1415926535897931 / 180.0) * cos
           (modello_completo_B.DataTypeConversion4_m[(int32_T)
            modello_completo_DW.Memory4_PreviousInput + 23] * 3.1415926535897931
            / 180.0), sin(modello_completo_B.DataTypeConversion4_m[(int32_T)
                          modello_completo_DW.Memory4_PreviousInput + 23] *
                          3.1415926535897931 / 180.0) * cos
           (modello_completo_DW.lat1 * 3.1415926535897931 / 180.0) - cos
           (modello_completo_B.DataTypeConversion4_m[(int32_T)
            modello_completo_DW.Memory4_PreviousInput + 23] * 3.1415926535897931
            / 180.0) * sin(modello_completo_DW.lat1 * 3.1415926535897931 / 180.0)
           * cos((modello_completo_B.DataTypeConversion4_m[(int32_T)
                  modello_completo_DW.Memory4_PreviousInput + 29] -
                  modello_completo_DW.long1) * 3.1415926535897931 / 180.0)) *
          180.0 / 3.1415926535897931);
      }
    } else {
      modello_completo_B.dist_fut = 0.0;
      modello_completo_B.Gain3 = 0.0;
    }

    if (modello_completo_DW.Memory4_PreviousInput < 2.0) {
      modello_completo_B.Gain_o = 0.0;
    } else if (modello_completo_DW.Memory4_PreviousInput == 2.0) {
      modello_completo_B.rtb_Gain1_i_idx_0 =
        modello_completo_B.DataTypeConversion4_m[24] * 3.1415926535897931 /
        180.0;
      modello_completo_B.b_a_tmp = cos(modello_completo_B.rtb_Gain1_i_idx_0);
      modello_completo_B.Gain_n = (modello_completo_B.DataTypeConversion4_m[30]
        - modello_completo_DW.long1) * 3.1415926535897931 / 180.0;
      modello_completo_B.Gain_o = fabs(modello_completo_B.Al_selector -
        rt_atan2d_snf(sin(modello_completo_B.Gain_n) *
                      modello_completo_B.b_a_tmp, cos(modello_completo_DW.lat1 *
        3.1415926535897931 / 180.0) * sin(modello_completo_B.rtb_Gain1_i_idx_0)
                      - sin(modello_completo_DW.lat1 * 3.1415926535897931 /
                            180.0) * modello_completo_B.b_a_tmp * cos
                      (modello_completo_B.Gain_n)) * 180.0 / 3.1415926535897931);
    } else {
      modello_completo_B.Gain_o = cos(modello_completo_B.DataTypeConversion4_m
        [(int32_T)(modello_completo_DW.Memory4_PreviousInput - 1.0) + 23] *
        3.1415926535897931 / 180.0);
      modello_completo_B.PWM_elevator_l =
        modello_completo_B.DataTypeConversion4_m[(int32_T)
        (modello_completo_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      modello_completo_B.Gain_n = (modello_completo_B.DataTypeConversion4_m
        [(int32_T)(modello_completo_DW.Memory4_PreviousInput - 1.0) + 29] -
        modello_completo_B.DataTypeConversion4_m[(int32_T)
        (modello_completo_DW.Memory4_PreviousInput - 2.0) + 29]) *
        3.1415926535897931 / 180.0;
      modello_completo_B.Gain_o = rt_atan2d_snf(sin(modello_completo_B.Gain_n) *
        modello_completo_B.Gain_o, cos(modello_completo_B.PWM_elevator_l) * sin
        (modello_completo_B.DataTypeConversion4_m[(int32_T)
         (modello_completo_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0) - sin(modello_completo_B.PWM_elevator_l) *
        modello_completo_B.Gain_o * cos(modello_completo_B.Gain_n)) * 180.0 /
        3.1415926535897931;
      if (modello_completo_B.Gain_o < 0.0) {
        modello_completo_B.Gain_o = 360.0 - fabs(modello_completo_B.Gain_o);
      }

      modello_completo_B.Gain_o = fabs(modello_completo_B.Al_selector -
        modello_completo_B.Gain_o);
    }

    if (modello_completo_B.Gain3 <= 10.0) {
      modello_completo_B.Al_selector = 40.0;
      modello_completo_B.AL = 100;
    } else if ((modello_completo_B.Gain3 > 10.0) && (modello_completo_B.Gain3 <=
                50.0)) {
      modello_completo_B.Al_selector = 60.0;
      modello_completo_B.AL = 250;
    } else if ((modello_completo_B.Gain3 > 50.0) && (modello_completo_B.Gain3 <=
                90.0)) {
      modello_completo_B.Al_selector = 80.0;
      modello_completo_B.AL = 300;
    } else if ((modello_completo_B.Gain3 > 90.0) && (modello_completo_B.Gain3 <=
                120.0)) {
      modello_completo_B.Al_selector = 120.0;
      modello_completo_B.AL = 350;
    } else {
      modello_completo_B.Al_selector = 150.0;
      modello_completo_B.AL = 400;
    }

    if (modello_completo_B.Gain_o <= 10.0) {
      modello_completo_B.caso = 50;
    } else if ((modello_completo_B.Gain_o > 10.0) && (modello_completo_B.Gain_o <=
                50.0)) {
      modello_completo_B.caso = 200;
    } else if ((modello_completo_B.Gain_o > 50.0) && (modello_completo_B.Gain_o <=
                90.0)) {
      modello_completo_B.caso = 300;
    } else if ((modello_completo_B.Gain_o > 90.0) && (modello_completo_B.Gain_o <=
                120.0)) {
      modello_completo_B.caso = 350;
    } else {
      modello_completo_B.caso = 400;
    }

    if (modello_completo_B.ATO == 1) {
      modello_completo_B.rtb_Gain1_i_idx_0 =
        modello_completo_B.DataTypeConversion4_m[(int32_T)
        modello_completo_DW.Memory4_PreviousInput + 11];
      if (modello_completo_B.rtb_Gain1_i_idx_0 < 15.0) {
        modello_completo_B.rtb_Gain1_i_idx_0 = 25.0;
      }

      if (!(modello_completo_B.rtb_Gain1_i_idx_0 <= 20.0)) {
        if (modello_completo_B.rtb_Gain1_i_idx_0 <= 25.0) {
          modello_completo_B.Al_selector *= 1.2;
        } else if (modello_completo_B.rtb_Gain1_i_idx_0 <= 30.0) {
          modello_completo_B.Al_selector *= 1.3;
        } else {
          modello_completo_B.Al_selector *= 1.4;
        }
      }

      if (((!(modello_completo_B.dist < modello_completo_B.caso)) ||
           (!(modello_completo_B.Switch_bk > modello_completo_B.Al_selector))) &&
          ((!(modello_completo_B.dist > modello_completo_B.caso)) ||
           (!(modello_completo_B.Switch_bk > modello_completo_B.Al_selector))) &&
          (modello_completo_B.Switch_bk < modello_completo_B.Al_selector)) {
        if (modello_completo_B.dist_fut > modello_completo_B.AL) {
          modello_completo_DW.Memory4_PreviousInput++;
        } else if (modello_completo_DW.Memory4_PreviousInput < 5.0) {
          modello_completo_DW.Memory4_PreviousInput += 2.0;
        } else {
          modello_completo_B.QUOTA = modello_completo_B.ByteUnpack_o2_e[2] + 0.4;
        }
      }

      modello_completo_DW.flag_m = 0.0;
    } else {
      if (((!(modello_completo_B.dist < modello_completo_B.caso)) ||
           (!(modello_completo_DW.flag_m == 0.0))) &&
          ((!(modello_completo_B.dist > modello_completo_B.caso)) ||
           (!(modello_completo_B.Switch_bk > 40.0)) ||
           (!(modello_completo_DW.flag_m == 0.0)))) {
        modello_completo_B.QUOTA = modello_completo_B.ByteUnpack_o2_e[2] + 0.4;
        modello_completo_DW.flag_m = 1.0;
      }
    }

    if ((modello_completo_B.Wp_selector == 0.0) && (modello_completo_B.Product1 ==
         0.0) && (modello_completo_B.QUOTA == 0.0)) {
      modello_completo_B.QUOTA = modello_completo_B.ByteUnpack_o2_e[2] + 0.3;
    }

    /* End of MATLAB Function: '<S441>/WAYPOINTS' */
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem' incorporates:
   *  EnablePort: '<S439>/Enable'
   */
  if (modello_completo_B.Vec_selector > 0.0) {
    /* MATLAB Function: '<S439>/VETTORIALE' incorporates:
     *  DataTypeConversion: '<S554>/Data Type Conversion5'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     *  Memory: '<S439>/Memory1'
     *  Memory: '<S439>/Memory3'
     *  Memory: '<S439>/Memory6'
     */
    if ((modello_completo_DW.Memory2_PreviousInput_a[1] !=
         modello_completo_DW.Memory6_PreviousInput) || (modello_completo_B.modo
         != modello_completo_DW.Memory3_PreviousInput) ||
        (modello_completo_DW.Memory2_PreviousInput_a[4] !=
         modello_completo_DW.Memory1_PreviousInput_h)) {
      modello_completo_DW.ALT_ref = modello_completo_B.ByteUnpack_o2_e[2];
    }

    if (modello_completo_DW.Memory2_PreviousInput_a[4] == 1) {
      modello_completo_B.h_vett = modello_completo_DW.riferimenti[9];
    } else {
      modello_completo_B.h_vett = modello_completo_DW.ALT_ref;
    }

    /* Update for Memory: '<S439>/Memory1' incorporates:
     *  MATLAB Function: '<S439>/VETTORIALE'
     */
    modello_completo_DW.Memory1_PreviousInput_h =
      modello_completo_DW.Memory2_PreviousInput_a[4];

    /* Update for Memory: '<S439>/Memory3' incorporates:
     *  MATLAB Function: '<S439>/VETTORIALE'
     */
    modello_completo_DW.Memory3_PreviousInput = modello_completo_B.modo;

    /* Update for Memory: '<S439>/Memory6' incorporates:
     *  MATLAB Function: '<S439>/VETTORIALE'
     */
    modello_completo_DW.Memory6_PreviousInput =
      modello_completo_DW.Memory2_PreviousInput_a[1];
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem3' incorporates:
   *  EnablePort: '<S442>/Enable'
   */
  if (modello_completo_B.Go_home_selector > 0.0) {
    /* Gain: '<S547>/Gain' */
    modello_completo_B.Gain1_f *= modello_completo_P.Gain_Gain_ji;

    /* MATLAB Function: '<S442>/GO_HOME' incorporates:
     *  Constant: '<S39>/Constant'
     *  Gain: '<S548>/Gain'
     */
    modello_completo_B.deltafalllimit = sin((0.0 - modello_completo_B.Gain1_f) *
      3.1415926535897931 / 180.0 / 2.0);
    modello_completo_B.Switch_bk = sin((0.0 - modello_completo_P.Gain_Gain_gf *
      modello_completo_B.Gain1_p) * 3.1415926535897931 / 180.0 / 2.0);
    modello_completo_B.deltafalllimit = cos(modello_completo_B.Gain1_f *
      3.1415926535897931 / 180.0) * (modello_completo_B.Switch_bk *
      modello_completo_B.Switch_bk) + modello_completo_B.deltafalllimit *
      modello_completo_B.deltafalllimit;
    modello_completo_B.h_goHome = modello_completo_P.Constant_Value_g;
    if ((rt_atan2d_snf(sqrt(modello_completo_B.deltafalllimit), sqrt(1.0 -
           modello_completo_B.deltafalllimit)) * 2.0 * 6.378137E+6 < 30.0) &&
        (modello_completo_DW.flag == 0.0)) {
      modello_completo_DW.flag = 1.0;
      modello_completo_B.h_goHome = modello_completo_P.Constant_Value_g + 0.4;
    }

    /* End of MATLAB Function: '<S442>/GO_HOME' */
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem3' */

  /* MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' */
  switch ((int32_T)modello_completo_B.modo) {
   case 1:
    modello_completo_B.Gain1_p = modello_completo_B.QUOTA;
    break;

   case 2:
    modello_completo_B.Gain1_p = modello_completo_B.h_vett;
    break;

   case 3:
    modello_completo_B.Gain1_p = modello_completo_B.h_ref;
    break;

   case 4:
    modello_completo_B.Gain1_p = modello_completo_B.QUOTA_m;
    break;

   default:
    modello_completo_B.Gain1_p = modello_completo_B.h_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' */

  /* Abs: '<S40>/Abs' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion5'
   *  Sum: '<S40>/Sum1'
   */
  modello_completo_B.Gain1_f = fabs(modello_completo_B.Gain1_p -
    modello_completo_B.ByteUnpack_o2_e[2]);

  /* Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  if (modello_completo_DW.is_active_c23_modello_completo == 0U) {
    modello_completo_DW.is_active_c23_modello_completo = 1U;
    modello_completo_DW.is_c23_modello_completo = modello_completo_IN_Select;
  } else if (modello_completo_DW.is_c23_modello_completo == 1) {
    if (modello_completo_B.Gain1_f > 10.0) {
      modello_completo_DW.is_c23_modello_completo = modello_completo_IN_Select;
    }
  } else {
    /* case IN_Select: */
    if (modello_completo_B.Gain1_f < 10.0) {
      modello_completo_DW.is_c23_modello_completo = modello_completo_IN_Hold;
    }
  }

  /* End of Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */

  /* MATLABSystem: '<S568>/Serial Receive1' */
  if (modello_completo_DW.obj_e.Protocol !=
      modello_completo_P.SerialReceive1_Protocol) {
    modello_completo_DW.obj_e.Protocol =
      modello_completo_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(0, modello_completo_DW.obj_e.DataSizeInBytes,
                 &modello_completo_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S568>/Subsystem2' incorporates:
   *  EnablePort: '<S579>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S579>/Create_message' */
    status = 0U;
    if (!modello_completo_DW.start_found) {
      modello_completo_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (modello_completo_B.i - 1 < 32)) {
        if (modello_completo_B.b_dataOut[(uint8_T)modello_completo_B.i - 1] ==
            36) {
          modello_completo_B.caso = 32 - (uint8_T)modello_completo_B.i;
          for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
               modello_completo_B.caso; modello_completo_B.ATO++) {
            modello_completo_DW.message[modello_completo_B.ATO] =
              modello_completo_B.b_dataOut[((uint8_T)modello_completo_B.i +
              modello_completo_B.ATO) - 1];
          }

          modello_completo_DW.counter_k = (uint8_T)(33 - (uint8_T)
            modello_completo_B.i);
          modello_completo_DW.start_found = true;
          exitg1 = true;
        } else {
          modello_completo_B.i++;
        }
      }
    } else {
      modello_completo_B.g = 1;
      exitg1 = false;
      while ((!exitg1) && (modello_completo_B.g - 1 < 32)) {
        if (modello_completo_B.b_dataOut[(uint8_T)modello_completo_B.g - 1] ==
            13) {
          modello_completo_DW.end_found = true;
          status = (uint8_T)modello_completo_B.g;
          exitg1 = true;
        } else {
          modello_completo_B.g++;
        }
      }

      if (modello_completo_DW.end_found) {
        if (1 > status) {
          modello_completo_B.caso = -1;
        } else {
          modello_completo_B.caso = status - 1;
        }

        for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
             modello_completo_B.caso; modello_completo_B.ATO++) {
          modello_completo_B.g = (int32_T)(((uint32_T)modello_completo_B.ATO +
            modello_completo_DW.counter_k) + 1U);
          if ((uint32_T)modello_completo_B.g > 255U) {
            modello_completo_B.g = 255;
          }

          modello_completo_DW.message[modello_completo_B.g - 1] =
            modello_completo_B.b_dataOut[modello_completo_B.ATO];
        }

        memcpy(&modello_completo_B.messaggio_b[0], &modello_completo_DW.message
               [0], 80U * sizeof(uint8_T));
        modello_completo_DW.end_found = false;
        modello_completo_DW.counter_k = (uint8_T)(32 - status);
        if (status == 32) {
          modello_completo_DW.start_found = false;
          memset(&modello_completo_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          modello_completo_DW.start_found = true;
          modello_completo_B.caso = -status;
          for (modello_completo_B.ATO = 0; modello_completo_B.ATO <=
               modello_completo_B.caso + 31; modello_completo_B.ATO++) {
            modello_completo_DW.message[modello_completo_B.ATO] =
              modello_completo_B.b_dataOut[status + modello_completo_B.ATO];
          }

          modello_completo_B.ATO = status + 48;
          if (0 <= modello_completo_B.ATO - 1) {
            memset(&modello_completo_DW.message[-status + 32], 0,
                   ((modello_completo_B.ATO - status) + status) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S579>/Subsystem' incorporates:
         *  EnablePort: '<S581>/Enable'
         */
        /* MATLAB Function: '<S581>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        modello_completo_B.indice_dimario = 0U;
        for (modello_completo_B.i = 0; modello_completo_B.i < 80;
             modello_completo_B.i++) {
          messaggio = (int8_T)
            modello_completo_B.messaggio_b[modello_completo_B.i];
          if (messaggio == '$') {
            modello_completo_B.ATO = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              modello_completo_B.ATO = 255;
            }

            status = (uint8_T)modello_completo_B.ATO;
          }

          if (messaggio == ',') {
            modello_completo_B.ATO = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              modello_completo_B.ATO = 255;
            }

            find_comma = (uint8_T)modello_completo_B.ATO;
          }

          modello_completo_B.messaggio_k[modello_completo_B.i] = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
               modello_completo_B.ATO++) {
            modello_completo_B.messaggio_c[modello_completo_B.ATO] =
              (modello_completo_B.messaggio_k[modello_completo_B.ATO] == '$');
          }

          modello_completo_eml_find(modello_completo_B.messaggio_c,
            &modello_completo_B.eb_data, modello_completo_B.eb_size);
          modello_completo_B.AL = modello_completo_B.eb_data;
          for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 5;
               modello_completo_B.ATO++) {
            messaggio = modello_completo_B.messaggio_k[modello_completo_B.ATO +
              modello_completo_B.AL];
            modello_completo_B.mess_type_b[modello_completo_B.ATO] = (messaggio ==
              bb[modello_completo_B.ATO]);
            modello_completo_B.mess_type[modello_completo_B.ATO] = messaggio;
          }

          if (modello_completo_ifWhileCond_o(modello_completo_B.mess_type_b)) {
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
                 modello_completo_B.ATO++) {
              modello_completo_B.messaggio_c[modello_completo_B.ATO] =
                (modello_completo_B.messaggio_k[modello_completo_B.ATO] == ',');
            }

            modello_completo_eml_find_o(modello_completo_B.messaggio_c,
              modello_completo_B.comma_gga_data, modello_completo_B.eb_size);
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
                 modello_completo_B.ATO++) {
              modello_completo_B.messaggio_c[modello_completo_B.ATO] =
                (modello_completo_B.messaggio_k[modello_completo_B.ATO] == '*');
            }

            modello_completo_eml_find_o(modello_completo_B.messaggio_c,
              modello_completo_B.star_data, modello_completo_B.star_size);
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
                 modello_completo_B.ATO++) {
              modello_completo_B.messaggio_c[modello_completo_B.ATO] =
                (modello_completo_B.messaggio_k[modello_completo_B.ATO] == '$');
            }

            modello_completo_eml_find_o(modello_completo_B.messaggio_c,
              modello_completo_B.fb_data, modello_completo_B.star_size);
            modello_completo_B.Lat_1 = modello_completo_str2double
              (&modello_completo_B.messaggio_k[modello_completo_B.comma_gga_data[
               2]]);
            if ((real_T)modello_completo_B.comma_gga_data[2] + 3.0 > (real_T)
                modello_completo_B.comma_gga_data[3] - 1.0) {
              modello_completo_B.c = 0;
              modello_completo_B.ATO = 0;
            } else {
              modello_completo_B.c = modello_completo_B.comma_gga_data[2] + 2;
              modello_completo_B.ATO = modello_completo_B.comma_gga_data[3] - 1;
            }

            modello_completo_B.messaggio_size[0] = 1;
            modello_completo_B.AL = modello_completo_B.ATO -
              modello_completo_B.c;
            modello_completo_B.messaggio_size[1] = modello_completo_B.AL;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                 modello_completo_B.AL; modello_completo_B.ATO++) {
              modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                modello_completo_B.messaggio_k[modello_completo_B.c +
                modello_completo_B.ATO];
            }

            modello_completo_B.b_x = modello_completo_str2double_l
              (modello_completo_B.messaggio_data,
               modello_completo_B.messaggio_size);
            if (modello_completo_B.b_x.im == 0.0) {
              modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                60.0;
            } else if (modello_completo_B.b_x.re == 0.0) {
              modello_completo_B.Go_home_selector = 0.0;
            } else {
              modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                60.0;
            }

            modello_completo_B.Gain1_f = modello_completo_B.Lat_1.re +
              modello_completo_B.Go_home_selector;
            modello_completo_B.caso = modello_completo_B.eb_size[0] *
              modello_completo_B.eb_size[1] - 1;
            if (0 <= modello_completo_B.caso) {
              memcpy(&modello_completo_B.tmp_data[0],
                     &modello_completo_B.comma_gga_data[0],
                     (modello_completo_B.caso + 1) * sizeof(int32_T));
            }

            if (modello_completo_B.messaggio_k[modello_completo_B.tmp_data[3]] ==
                'S') {
              modello_completo_B.Gain1_f = -modello_completo_B.Gain1_f;
            }

            modello_completo_B.Lat_1 = modello_completo_str2double_lv
              (&modello_completo_B.messaggio_k[modello_completo_B.comma_gga_data[
               4]]);
            if ((real_T)modello_completo_B.comma_gga_data[4] + 4.0 > (real_T)
                modello_completo_B.comma_gga_data[5] - 1.0) {
              modello_completo_B.g = 0;
              modello_completo_B.i = 0;
            } else {
              modello_completo_B.g = modello_completo_B.comma_gga_data[4] + 3;
              modello_completo_B.i = modello_completo_B.comma_gga_data[5] - 1;
            }

            modello_completo_B.messaggio_size_f[0] = 1;
            modello_completo_B.AL = modello_completo_B.i - modello_completo_B.g;
            modello_completo_B.messaggio_size_f[1] = modello_completo_B.AL;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                 modello_completo_B.AL; modello_completo_B.ATO++) {
              modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                modello_completo_B.messaggio_k[modello_completo_B.g +
                modello_completo_B.ATO];
            }

            modello_completo_B.b_x = modello_completo_str2double_l
              (modello_completo_B.messaggio_data,
               modello_completo_B.messaggio_size_f);
            if (modello_completo_B.b_x.im == 0.0) {
              modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                60.0;
            } else if (modello_completo_B.b_x.re == 0.0) {
              modello_completo_B.Go_home_selector = 0.0;
            } else {
              modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                60.0;
            }

            modello_completo_B.Go_home_selector += modello_completo_B.Lat_1.re;
            if (modello_completo_B.messaggio_k[modello_completo_B.tmp_data[5]] ==
                'W') {
              modello_completo_B.Go_home_selector =
                -modello_completo_B.Go_home_selector;
            }

            if ((real_T)modello_completo_B.comma_gga_data[6] + 1.0 > (real_T)
                modello_completo_B.comma_gga_data[7] - 1.0) {
              modello_completo_B.g = 0;
              modello_completo_B.i = 0;
            } else {
              modello_completo_B.g = modello_completo_B.comma_gga_data[6];
              modello_completo_B.i = modello_completo_B.comma_gga_data[7] - 1;
            }

            modello_completo_B.messaggio_size_g[0] = 1;
            modello_completo_B.AL = modello_completo_B.i - modello_completo_B.g;
            modello_completo_B.messaggio_size_g[1] = modello_completo_B.AL;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                 modello_completo_B.AL; modello_completo_B.ATO++) {
              modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                modello_completo_B.messaggio_k[modello_completo_B.g +
                modello_completo_B.ATO];
            }

            modello_completo_B.Lat_1 = modello_completo_str2double_l
              (modello_completo_B.messaggio_data,
               modello_completo_B.messaggio_size_g);

            /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
            modello_completo_B.ComplextoRealImag[2] =
              modello_completo_B.Lat_1.re;
            if ((real_T)modello_completo_B.comma_gga_data[7] + 1.0 > (real_T)
                modello_completo_B.comma_gga_data[8] - 1.0) {
              modello_completo_B.caso = 0;
              modello_completo_B.ATO = 0;
            } else {
              modello_completo_B.caso = modello_completo_B.comma_gga_data[7];
              modello_completo_B.ATO = modello_completo_B.comma_gga_data[8] - 1;
            }

            modello_completo_B.messaggio_size_g1[0] = 1;
            modello_completo_B.AL = modello_completo_B.ATO -
              modello_completo_B.caso;
            modello_completo_B.messaggio_size_g1[1] = modello_completo_B.AL;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                 modello_completo_B.AL; modello_completo_B.ATO++) {
              modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                modello_completo_B.messaggio_k[modello_completo_B.caso +
                modello_completo_B.ATO];
            }

            modello_completo_B.Lat_1 = modello_completo_str2double_l
              (modello_completo_B.messaggio_data,
               modello_completo_B.messaggio_size_g1);

            /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
            modello_completo_B.ComplextoRealImag[4] =
              modello_completo_B.Lat_1.re;
            if ((real_T)modello_completo_B.comma_gga_data[9] + 1.0 > (real_T)
                modello_completo_B.comma_gga_data[10] - 1.0) {
              modello_completo_B.caso = 0;
              modello_completo_B.ATO = 0;
            } else {
              modello_completo_B.caso = modello_completo_B.comma_gga_data[9];
              modello_completo_B.ATO = modello_completo_B.comma_gga_data[10] - 1;
            }

            modello_completo_B.messaggio_size_m[0] = 1;
            modello_completo_B.AL = modello_completo_B.ATO -
              modello_completo_B.caso;
            modello_completo_B.messaggio_size_m[1] = modello_completo_B.AL;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                 modello_completo_B.AL; modello_completo_B.ATO++) {
              modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                modello_completo_B.messaggio_k[modello_completo_B.caso +
                modello_completo_B.ATO];
            }

            modello_completo_B.Lat_1 = modello_completo_str2double_l
              (modello_completo_B.messaggio_data,
               modello_completo_B.messaggio_size_m);

            /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
            modello_completo_B.ComplextoRealImag[3] =
              modello_completo_B.Lat_1.re;
            if (modello_completo_B.messaggio_k[modello_completo_B.tmp_data[10]] ==
                'W') {
              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[3] =
                -modello_completo_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
            modello_completo_B.ComplextoRealImag[5] =
              modello_completo_DW.Memory_PreviousInput_l[5];
            modello_completo_B.ComplextoRealImag[6] =
              modello_completo_DW.Memory_PreviousInput_l[6];
            modello_completo_B.ComplextoRealImag[7] =
              modello_completo_DW.Memory_PreviousInput_l[7];
            modello_completo_B.ComplextoRealImag[8] =
              modello_completo_DW.Memory_PreviousInput_l[8];
            if ((real_T)modello_completo_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)modello_completo_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)modello_completo_B.star_data[0] + 1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = modello_completo_B.messaggio_k[status - 1];
            if ((real_T)modello_completo_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)modello_completo_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)modello_completo_B.star_data[0] + 2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = modello_completo_B.messaggio_k[status - 1];
            if ((real_T)modello_completo_B.fb_data[0] + 1.0 > (real_T)
                modello_completo_B.star_data[0] - 1.0) {
              modello_completo_B.caso = 0;
              modello_completo_B.AL = 0;
            } else {
              modello_completo_B.caso = modello_completo_B.fb_data[0];
              modello_completo_B.AL = modello_completo_B.star_data[0] - 1;
            }

            modello_completo_B.AL -= modello_completo_B.caso;
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                 modello_completo_B.AL; modello_completo_B.ATO++) {
              modello_completo_B.NMEA_gga_string_data[modello_completo_B.ATO] =
                (uint8_T)modello_completo_B.messaggio_k[modello_completo_B.caso
                + modello_completo_B.ATO];
            }

            status = 0U;
            modello_completo_B.g = 0;
            while (modello_completo_B.g <= modello_completo_B.AL - 1) {
              status ^=
                modello_completo_B.NMEA_gga_string_data[modello_completo_B.g];
              modello_completo_B.g++;
            }

            if (status != modello_completo_hex2dec(ck_ric)) {
              modello_completo_B.Gain1_f =
                modello_completo_DW.Memory_PreviousInput_l[0];
              modello_completo_B.Go_home_selector =
                modello_completo_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[2] =
                modello_completo_DW.Memory_PreviousInput_l[2];
              modello_completo_B.ComplextoRealImag[3] =
                modello_completo_DW.Memory_PreviousInput_l[3];
              modello_completo_B.ComplextoRealImag[4] =
                modello_completo_DW.Memory_PreviousInput_l[4];
              modello_completo_B.indice_dimario = 10U;
            }
          } else {
            for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 5;
                 modello_completo_B.ATO++) {
              modello_completo_B.mess_type_b[modello_completo_B.ATO] =
                (modello_completo_B.mess_type[modello_completo_B.ATO] ==
                 cb[modello_completo_B.ATO]);
            }

            if (modello_completo_ifWhileCond_o(modello_completo_B.mess_type_b))
            {
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
                   modello_completo_B.ATO++) {
                modello_completo_B.messaggio_c[modello_completo_B.ATO] =
                  (modello_completo_B.messaggio_k[modello_completo_B.ATO] == ',');
              }

              modello_completo_eml_find_o(modello_completo_B.messaggio_c,
                modello_completo_B.comma_gga_data, modello_completo_B.eb_size);
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
                   modello_completo_B.ATO++) {
                modello_completo_B.messaggio_c[modello_completo_B.ATO] =
                  (modello_completo_B.messaggio_k[modello_completo_B.ATO] == '*');
              }

              modello_completo_eml_find_o(modello_completo_B.messaggio_c,
                modello_completo_B.star_data, modello_completo_B.star_size);
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO < 80;
                   modello_completo_B.ATO++) {
                modello_completo_B.messaggio_c[modello_completo_B.ATO] =
                  (modello_completo_B.messaggio_k[modello_completo_B.ATO] == '$');
              }

              modello_completo_eml_find_o(modello_completo_B.messaggio_c,
                modello_completo_B.fb_data, modello_completo_B.star_size);
              modello_completo_B.Lat_1 = modello_completo_str2double
                (&modello_completo_B.messaggio_k[modello_completo_B.comma_gga_data
                 [1]]);
              if ((real_T)modello_completo_B.comma_gga_data[1] + 3.0 > (real_T)
                  modello_completo_B.comma_gga_data[2] - 1.0) {
                modello_completo_B.caso = 0;
                modello_completo_B.ATO = 0;
              } else {
                modello_completo_B.caso = modello_completo_B.comma_gga_data[1] +
                  2;
                modello_completo_B.ATO = modello_completo_B.comma_gga_data[2] -
                  1;
              }

              modello_completo_B.messaggio_size[0] = 1;
              modello_completo_B.AL = modello_completo_B.ATO -
                modello_completo_B.caso;
              modello_completo_B.messaggio_size[1] = modello_completo_B.AL;
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                   modello_completo_B.AL; modello_completo_B.ATO++) {
                modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                  modello_completo_B.messaggio_k[modello_completo_B.caso +
                  modello_completo_B.ATO];
              }

              modello_completo_B.b_x = modello_completo_str2double_l
                (modello_completo_B.messaggio_data,
                 modello_completo_B.messaggio_size);
              if (modello_completo_B.b_x.im == 0.0) {
                modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                  60.0;
              } else if (modello_completo_B.b_x.re == 0.0) {
                modello_completo_B.Go_home_selector = 0.0;
              } else {
                modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                  60.0;
              }

              modello_completo_B.Gain1_f = modello_completo_B.Lat_1.re +
                modello_completo_B.Go_home_selector;
              modello_completo_B.caso = modello_completo_B.eb_size[0] *
                modello_completo_B.eb_size[1] - 1;
              if (0 <= modello_completo_B.caso) {
                memcpy(&modello_completo_B.tmp_data[0],
                       &modello_completo_B.comma_gga_data[0],
                       (modello_completo_B.caso + 1) * sizeof(int32_T));
              }

              if (modello_completo_B.messaggio_k[modello_completo_B.tmp_data[2]]
                  == 'S') {
                modello_completo_B.Gain1_f = -modello_completo_B.Gain1_f;
              }

              modello_completo_B.Lat_1 = modello_completo_str2double_lv
                (&modello_completo_B.messaggio_k[modello_completo_B.comma_gga_data
                 [3]]);
              if ((real_T)modello_completo_B.comma_gga_data[3] + 4.0 > (real_T)
                  modello_completo_B.comma_gga_data[4] - 1.0) {
                modello_completo_B.g = 0;
                modello_completo_B.ATO = 0;
              } else {
                modello_completo_B.g = modello_completo_B.comma_gga_data[3] + 3;
                modello_completo_B.ATO = modello_completo_B.comma_gga_data[4] -
                  1;
              }

              modello_completo_B.messaggio_size_f[0] = 1;
              modello_completo_B.AL = modello_completo_B.ATO -
                modello_completo_B.g;
              modello_completo_B.messaggio_size_f[1] = modello_completo_B.AL;
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                   modello_completo_B.AL; modello_completo_B.ATO++) {
                modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                  modello_completo_B.messaggio_k[modello_completo_B.g +
                  modello_completo_B.ATO];
              }

              modello_completo_B.b_x = modello_completo_str2double_l
                (modello_completo_B.messaggio_data,
                 modello_completo_B.messaggio_size_f);
              if (modello_completo_B.b_x.im == 0.0) {
                modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                  60.0;
              } else if (modello_completo_B.b_x.re == 0.0) {
                modello_completo_B.Go_home_selector = 0.0;
              } else {
                modello_completo_B.Go_home_selector = modello_completo_B.b_x.re /
                  60.0;
              }

              modello_completo_B.Go_home_selector += modello_completo_B.Lat_1.re;
              if (modello_completo_B.messaggio_k[modello_completo_B.tmp_data[4]]
                  == 'W') {
                modello_completo_B.Go_home_selector =
                  -modello_completo_B.Go_home_selector;
              }

              modello_completo_B.Lat_1 = modello_completo_str2double_lvk
                (modello_completo_B.messaggio_k[modello_completo_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[5] =
                modello_completo_B.Lat_1.re;
              if ((real_T)modello_completo_B.comma_gga_data[6] + 1.0 > (real_T)
                  modello_completo_B.comma_gga_data[7] - 1.0) {
                modello_completo_B.caso = 0;
                modello_completo_B.ATO = 0;
              } else {
                modello_completo_B.caso = modello_completo_B.comma_gga_data[6];
                modello_completo_B.ATO = modello_completo_B.comma_gga_data[7] -
                  1;
              }

              modello_completo_B.messaggio_size_g[0] = 1;
              modello_completo_B.AL = modello_completo_B.ATO -
                modello_completo_B.caso;
              modello_completo_B.messaggio_size_g[1] = modello_completo_B.AL;
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                   modello_completo_B.AL; modello_completo_B.ATO++) {
                modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                  modello_completo_B.messaggio_k[modello_completo_B.caso +
                  modello_completo_B.ATO];
              }

              modello_completo_B.Lat_1 = modello_completo_str2double_l
                (modello_completo_B.messaggio_data,
                 modello_completo_B.messaggio_size_g);

              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[6] =
                modello_completo_B.Lat_1.re;
              if ((real_T)modello_completo_B.comma_gga_data[8] + 1.0 > (real_T)
                  modello_completo_B.comma_gga_data[9] - 1.0) {
                modello_completo_B.g = 0;
                modello_completo_B.ATO = 0;
              } else {
                modello_completo_B.g = modello_completo_B.comma_gga_data[8];
                modello_completo_B.ATO = modello_completo_B.comma_gga_data[9] -
                  1;
              }

              modello_completo_B.messaggio_size_g1[0] = 1;
              modello_completo_B.AL = modello_completo_B.ATO -
                modello_completo_B.g;
              modello_completo_B.messaggio_size_g1[1] = modello_completo_B.AL;
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                   modello_completo_B.AL; modello_completo_B.ATO++) {
                modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                  modello_completo_B.messaggio_k[modello_completo_B.g +
                  modello_completo_B.ATO];
              }

              modello_completo_B.Lat_1 = modello_completo_str2double_l
                (modello_completo_B.messaggio_data,
                 modello_completo_B.messaggio_size_g1);

              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[7] =
                modello_completo_B.Lat_1.re;
              if ((real_T)modello_completo_B.comma_gga_data[10] + 1.0 > (real_T)
                  modello_completo_B.comma_gga_data[11] - 1.0) {
                modello_completo_B.i = 0;
                modello_completo_B.caso = 0;
              } else {
                modello_completo_B.i = modello_completo_B.comma_gga_data[10];
                modello_completo_B.caso = modello_completo_B.comma_gga_data[11]
                  - 1;
              }

              modello_completo_B.messaggio_size_m[0] = 1;
              modello_completo_B.AL = modello_completo_B.caso -
                modello_completo_B.i;
              modello_completo_B.messaggio_size_m[1] = modello_completo_B.AL;
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                   modello_completo_B.AL; modello_completo_B.ATO++) {
                modello_completo_B.messaggio_data[modello_completo_B.ATO] =
                  modello_completo_B.messaggio_k[modello_completo_B.i +
                  modello_completo_B.ATO];
              }

              modello_completo_B.Lat_1 = modello_completo_str2double_l
                (modello_completo_B.messaggio_data,
                 modello_completo_B.messaggio_size_m);

              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[8] =
                modello_completo_B.Lat_1.re;
              modello_completo_B.ComplextoRealImag[2] =
                modello_completo_DW.Memory_PreviousInput_l[2];
              modello_completo_B.ComplextoRealImag[3] =
                modello_completo_DW.Memory_PreviousInput_l[3];
              modello_completo_B.ComplextoRealImag[4] =
                modello_completo_DW.Memory_PreviousInput_l[4];
              if ((real_T)modello_completo_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)modello_completo_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)modello_completo_B.star_data[0] +
                                     1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = modello_completo_B.messaggio_k[status - 1];
              if ((real_T)modello_completo_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)modello_completo_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)modello_completo_B.star_data[0] +
                                     2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = modello_completo_B.messaggio_k[status - 1];
              if ((real_T)modello_completo_B.fb_data[0] + 1.0 > (real_T)
                  modello_completo_B.star_data[0] - 1.0) {
                modello_completo_B.caso = 0;
                modello_completo_B.ATO = 0;
              } else {
                modello_completo_B.caso = modello_completo_B.fb_data[0];
                modello_completo_B.ATO = modello_completo_B.star_data[0] - 1;
              }

              modello_completo_B.AL = modello_completo_B.ATO -
                modello_completo_B.caso;
              for (modello_completo_B.ATO = 0; modello_completo_B.ATO <
                   modello_completo_B.AL; modello_completo_B.ATO++) {
                modello_completo_B.NMEA_gga_string_data[modello_completo_B.ATO] =
                  (uint8_T)
                  modello_completo_B.messaggio_k[modello_completo_B.caso +
                  modello_completo_B.ATO];
              }

              status = 0U;
              modello_completo_B.ATO = 0;
              while (modello_completo_B.ATO <= modello_completo_B.AL - 1) {
                status ^=
                  modello_completo_B.NMEA_gga_string_data[modello_completo_B.ATO];
                modello_completo_B.ATO++;
              }

              if (status != modello_completo_hex2dec(ck_ric)) {
                modello_completo_B.Gain1_f =
                  modello_completo_DW.Memory_PreviousInput_l[0];
                modello_completo_B.Go_home_selector =
                  modello_completo_DW.Memory_PreviousInput_l[1];

                /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
                modello_completo_B.ComplextoRealImag[5] =
                  modello_completo_DW.Memory_PreviousInput_l[5];
                modello_completo_B.ComplextoRealImag[6] =
                  modello_completo_DW.Memory_PreviousInput_l[6];
                modello_completo_B.ComplextoRealImag[7] =
                  modello_completo_DW.Memory_PreviousInput_l[7];
                modello_completo_B.ComplextoRealImag[8] =
                  modello_completo_DW.Memory_PreviousInput_l[8];
                modello_completo_B.indice_dimario = 20U;
              }
            } else {
              modello_completo_B.Gain1_f =
                modello_completo_DW.Memory_PreviousInput_l[0];
              modello_completo_B.Go_home_selector =
                modello_completo_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
              modello_completo_B.ComplextoRealImag[2] =
                modello_completo_DW.Memory_PreviousInput_l[2];
              modello_completo_B.ComplextoRealImag[3] =
                modello_completo_DW.Memory_PreviousInput_l[3];
              modello_completo_B.ComplextoRealImag[4] =
                modello_completo_DW.Memory_PreviousInput_l[4];
              modello_completo_B.ComplextoRealImag[5] =
                modello_completo_DW.Memory_PreviousInput_l[5];
              modello_completo_B.ComplextoRealImag[6] =
                modello_completo_DW.Memory_PreviousInput_l[6];
              modello_completo_B.ComplextoRealImag[7] =
                modello_completo_DW.Memory_PreviousInput_l[7];
              modello_completo_B.ComplextoRealImag[8] =
                modello_completo_DW.Memory_PreviousInput_l[8];
            }
          }
        } else {
          modello_completo_B.Gain1_f =
            modello_completo_DW.Memory_PreviousInput_l[0];
          modello_completo_B.Go_home_selector =
            modello_completo_DW.Memory_PreviousInput_l[1];

          /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
          modello_completo_B.ComplextoRealImag[2] =
            modello_completo_DW.Memory_PreviousInput_l[2];
          modello_completo_B.ComplextoRealImag[3] =
            modello_completo_DW.Memory_PreviousInput_l[3];
          modello_completo_B.ComplextoRealImag[4] =
            modello_completo_DW.Memory_PreviousInput_l[4];
          modello_completo_B.ComplextoRealImag[5] =
            modello_completo_DW.Memory_PreviousInput_l[5];
          modello_completo_B.ComplextoRealImag[6] =
            modello_completo_DW.Memory_PreviousInput_l[6];
          modello_completo_B.ComplextoRealImag[7] =
            modello_completo_DW.Memory_PreviousInput_l[7];
          modello_completo_B.ComplextoRealImag[8] =
            modello_completo_DW.Memory_PreviousInput_l[8];
        }

        /* End of MATLAB Function: '<S581>/MATLAB Function' */

        /* ComplexToRealImag: '<S581>/Complex to Real-Imag' */
        modello_completo_B.ComplextoRealImag[0] = modello_completo_B.Gain1_f;
        modello_completo_B.ComplextoRealImag[1] =
          modello_completo_B.Go_home_selector;

        /* Update for Memory: '<S581>/Memory' */
        memcpy(&modello_completo_DW.Memory_PreviousInput_l[0],
               &modello_completo_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S579>/Subsystem' */
      } else {
        for (modello_completo_B.i = 0; modello_completo_B.i < 32;
             modello_completo_B.i++) {
          modello_completo_B.ATO = (int32_T)(((uint32_T)
            modello_completo_DW.counter_k + modello_completo_B.i) + 1U);
          if ((uint32_T)modello_completo_B.ATO > 255U) {
            modello_completo_B.ATO = 255;
          }

          modello_completo_DW.message[modello_completo_B.ATO - 1] =
            modello_completo_B.b_dataOut[modello_completo_B.i];
        }

        modello_completo_B.ATO = (int32_T)(modello_completo_DW.counter_k + 32U);
        if (modello_completo_DW.counter_k + 32U > 255U) {
          modello_completo_B.ATO = 255;
        }

        modello_completo_DW.counter_k = (uint8_T)modello_completo_B.ATO;
      }
    }

    /* End of MATLAB Function: '<S579>/Create_message' */
  }

  /* End of MATLABSystem: '<S568>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S568>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S568>/Subsystem1' incorporates:
   *  EnablePort: '<S578>/Enable'
   */
  if (modello_completo_B.SFunction_o14 > 0) {
    /* Switch: '<S578>/Switch' incorporates:
     *  Constant: '<S578>/Constant'
     *  Constant: '<S578>/Constant1'
     *  Constant: '<S578>/Constant3'
     *  Logic: '<S578>/OR'
     *  RelationalOperator: '<S578>/Equal'
     *  RelationalOperator: '<S578>/Equal1'
     *  RelationalOperator: '<S578>/Equal2'
     */
    if ((modello_completo_B.ComplextoRealImag[5] ==
         modello_completo_P.Constant_Value_l) ||
        (modello_completo_B.ComplextoRealImag[5] ==
         modello_completo_P.Constant1_Value_b) ||
        (modello_completo_B.ComplextoRealImag[5] ==
         modello_completo_P.Constant3_Value_ct)) {
      /* Switch: '<S578>/Switch' */
      modello_completo_B.Switch = modello_completo_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S578>/Switch' incorporates:
       *  Constant: '<S578>/Constant2'
       */
      modello_completo_B.Switch = modello_completo_P.Constant2_Value_d;
    }

    /* End of Switch: '<S578>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S568>/Subsystem1' */

  /* MATLAB Function: '<S567>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S567>/Data Type Conversion'
   *  UnitDelay: '<S570>/Delay Input2'
   *
   * Block description for '<S570>/Delay Input2':
   *
   *  Store in Global RAM
   */
  modello_completo_B.Gain1_f = log(modello_completo_DW.DelayInput2_DSTATE /
    (real_T)modello_completo_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S554>/Data Type Conversion4' incorporates:
   *  MATLAB Function: '<S567>/MATLAB Function1'
   *  Sum: '<S568>/Sum'
   */
  modello_completo_B.DataTypeConversion4[0] = (real32_T)
    modello_completo_B.ComplextoRealImag[0];
  modello_completo_B.DataTypeConversion4[1] = (real32_T)
    modello_completo_B.ComplextoRealImag[1];
  modello_completo_B.DataTypeConversion4[2] = (real32_T)
    (modello_completo_B.ComplextoRealImag[7] - modello_completo_B.Switch);
  modello_completo_B.DataTypeConversion4[3] = (real32_T)(29.260958205912335 *
    modello_completo_B.Gain1_f) * (modello_completo_B.Switch1 + 273.15F) /
    (real32_T)(1.0 - -0.095098114169215084 * modello_completo_B.Gain1_f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  Gain: '<S559>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_n * modello_completo_B.DataTypeConversion1_pb
     [3] * modello_completo_P.Gain_Gain_bk));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[3] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  Gain: '<S560>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_db *
     modello_completo_B.DataTypeConversion1_pb[4] *
     modello_completo_P.Gain_Gain_bk));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[4] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  Gain: '<S561>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_dc *
     modello_completo_B.DataTypeConversion1_pb[5] *
     modello_completo_P.Gain_Gain_bk));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[5] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  SignalConversion generated from: '<S554>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_bk *
     modello_completo_B.DataTypeConversion1_pb[6]));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[0] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  SignalConversion generated from: '<S554>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_bk *
     modello_completo_B.DataTypeConversion1_pb[0]));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[6] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  SignalConversion generated from: '<S554>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_bk *
     modello_completo_B.DataTypeConversion1_pb[7]));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[1] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  SignalConversion generated from: '<S554>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_bk *
     modello_completo_B.DataTypeConversion1_pb[1]));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[7] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  SignalConversion generated from: '<S554>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_bk *
     modello_completo_B.DataTypeConversion1_pb[8]));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[2] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S554>/Data Type Conversion' incorporates:
   *  Gain: '<S554>/Gain'
   *  SignalConversion generated from: '<S554>/Gain'
   */
  modello_completo_B.f = (real32_T)floor((real32_T)
    (modello_completo_P.Gain_Gain_bk *
     modello_completo_B.DataTypeConversion1_pb[2]));
  if (rtIsNaNF(modello_completo_B.f) || rtIsInfF(modello_completo_B.f)) {
    modello_completo_B.f = 0.0F;
  } else {
    modello_completo_B.f = (real32_T)fmod(modello_completo_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_lx[8] = (int16_T)(modello_completo_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.f :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.f);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S592>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion7'
   *  Product: '<S592>/Divide'
   *  Product: '<S592>/Multiply'
   *  Sum: '<S592>/Sum'
   *  Sum: '<S592>/Sum3'
   */
  modello_completo_B.deltafalllimit = floor((modello_completo_B.Sum3_o -
    modello_completo_P.attuatore_Emin) / modello_completo_B.rtb_Sum3_o_tmp *
    modello_completo_B.Go_Home + (real_T)
    modello_completo_B.One_time_initialization.ByteUnpack[3]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  modello_completo_B.DataTypeConversion_p = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S589>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion9'
   *  Product: '<S589>/Divide'
   *  Product: '<S589>/Multiply'
   *  Sum: '<S589>/Sum'
   *  Sum: '<S589>/Sum3'
   */
  modello_completo_B.deltafalllimit = floor((modello_completo_B.PWM_rudder_p -
    modello_completo_P.attuatore_Amin) / modello_completo_B.rtb_Sum3_b_tmp *
    modello_completo_B.Ato_selector + (real_T)
    modello_completo_B.One_time_initialization.ByteUnpack[5]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_c = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S590>/Constant'
   *  Constant: '<S590>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion10'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   *  Product: '<S590>/Divide'
   *  Product: '<S590>/Multiply'
   *  Sum: '<S590>/Sum'
   *  Sum: '<S590>/Sum1'
   *  Sum: '<S590>/Sum2'
   *  Sum: '<S590>/Sum3'
   */
  modello_completo_B.deltafalllimit = floor((modello_completo_B.Sum2_o -
    modello_completo_P.attuatore_Rmin) / (modello_completo_P.attuatore_Rmax -
    modello_completo_P.attuatore_Rmin) * (real_T)
    (modello_completo_B.One_time_initialization.ByteUnpack[6] -
     modello_completo_B.One_time_initialization.ByteUnpack[7]) + (real_T)
    modello_completo_B.One_time_initialization.ByteUnpack[7]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  modello_completo_B.DataTypeConversion2_j = (int16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(int16_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' */
  modello_completo_B.deltafalllimit = floor
    (modello_completo_B.ComplextoRealImag[4]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_h[0] = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  Gain: '<S554>/Gain2'
   */
  modello_completo_B.deltafalllimit = floor(modello_completo_P.Gain2_Gain_m *
    modello_completo_B.ComplextoRealImag[2]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_h[1] = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion9'
   */
  modello_completo_B.ATO = (int32_T)fmod(modello_completo_B.DataTypeConversion_p,
    65536.0);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_h[2] = (uint16_T)
    (modello_completo_B.ATO < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)modello_completo_B.ATO : (int32_T)(uint16_T)modello_completo_B.ATO);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion9'
   */
  modello_completo_B.ATO = (int32_T)fmod
    (modello_completo_B.DataTypeConversion1_c, 65536.0);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   */
  modello_completo_B.DataTypeConversion1_h[3] = (uint16_T)
    (modello_completo_B.ATO < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)modello_completo_B.ATO : (int32_T)(uint16_T)modello_completo_B.ATO);
  modello_completo_B.DataTypeConversion1_h[4] = (uint16_T)
    modello_completo_B.PWM_throttle;
  modello_completo_B.DataTypeConversion1_h[5] = (uint16_T)
    modello_completo_B.PWM_elevator;
  modello_completo_B.DataTypeConversion1_h[6] = (uint16_T)
    modello_completo_B.PWM_aileron;
  modello_completo_B.DataTypeConversion1_h[7] = (uint16_T)
    modello_completo_B.PWM_rudder;

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion9'
   */
  modello_completo_B.ATO = (int32_T)fmod
    (modello_completo_B.DataTypeConversion2_j, 65536.0);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_h[8] = (uint16_T)
    (modello_completo_B.ATO < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)modello_completo_B.ATO : (int32_T)(uint16_T)modello_completo_B.ATO);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  Gain: '<S554>/Gain3'
   */
  modello_completo_B.deltafalllimit = floor((real_T)
    modello_completo_P.Gain3_Gain * modello_completo_B.SFunctionBuilder_o1);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* DataTypeConversion: '<S554>/Data Type Conversion1' */
  modello_completo_B.DataTypeConversion1_h[9] = (uint16_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-modello_completo_B.deltafalllimit : (int32_T)(uint16_T)
     modello_completo_B.deltafalllimit);

  /* DataTypeConversion: '<S554>/Data Type Conversion6' */
  modello_completo_B.deltafalllimit = floor
    (modello_completo_B.ComplextoRealImag[5]);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      256.0);
  }

  /* SignalConversion generated from: '<S554>/Byte Pack' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion6'
   */
  modello_completo_B.TmpSignalConversionAtBytePackIn[0] = (uint8_T)
    (modello_completo_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-modello_completo_B.deltafalllimit : (int32_T)(uint8_T)
     modello_completo_B.deltafalllimit);
  modello_completo_B.TmpSignalConversionAtBytePackIn[1] =
    modello_completo_B.indice_dimario;

  /* DataTypeConversion: '<S554>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S567>/Data Type Conversion'
   */
  modello_completo_B.DataTypeConversion8 = modello_completo_B.SFunctionBuilder1;

  /* S-Function (any2byte_svd): '<S554>/Byte Pack' incorporates:
   *  Constant: '<S554>/Fine MSG1'
   *  Constant: '<S554>/Inizio MSG'
   */

  /* Pack: <S554>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_B.DataTypeConversion4[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_B.DataTypeConversion_lx[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_B.DataTypeConversion1_h[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_B.TmpSignalConversionAtBytePackIn[0],
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
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_B.DataTypeConversion8, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&modello_completo_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &modello_completo_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S554>/Serial Transmit' */
  if (modello_completo_DW.obj.Protocol !=
      modello_completo_P.SerialTransmit_Protocol_b) {
    modello_completo_DW.obj.Protocol =
      modello_completo_P.SerialTransmit_Protocol_b;
  }

  for (modello_completo_B.i = 0; modello_completo_B.i < 63; modello_completo_B.i
       ++) {
    modello_completo_B.dataIn[modello_completo_B.i] =
      modello_completo_B.BytePack[modello_completo_B.i];
  }

  MW_Serial_write(modello_completo_DW.obj.port, &modello_completo_B.dataIn[0],
                  63.0, modello_completo_DW.obj.dataSizeInBytes,
                  modello_completo_DW.obj.sendModeEnum,
                  modello_completo_DW.obj.dataType,
                  modello_completo_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S554>/Serial Transmit' */

  /* S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */
  Servo_microseconds_alettoni_beta_3_Outputs_wrapper
    (&modello_completo_B.DataTypeConversion1_c,
     &modello_completo_DW.SFunctionBuilder10_DSTATE);

  /* Sum: '<S591>/Sum' incorporates:
   *  Product: '<S591>/Multiply'
   */
  modello_completo_B.deltafalllimit = floor
    (modello_completo_B.rtb_Gain1_kw_idx_0 * modello_completo_B.Gain1_kx);
  if (rtIsNaN(modello_completo_B.deltafalllimit) || rtIsInf
      (modello_completo_B.deltafalllimit)) {
    modello_completo_B.deltafalllimit = 0.0;
  } else {
    modello_completo_B.deltafalllimit = fmod(modello_completo_B.deltafalllimit,
      65536.0);
  }

  /* Sum: '<S591>/Sum' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   */
  modello_completo_B.Sum = (int16_T)((modello_completo_B.deltafalllimit < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-modello_completo_B.deltafalllimit :
    (int32_T)(int16_T)(uint16_T)modello_completo_B.deltafalllimit) + (int16_T)
    modello_completo_B.One_time_initialization.ByteUnpack[1]);

  /* S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper(&modello_completo_B.Sum,
    &modello_completo_DW.SFunctionBuilder4_DSTATE);

  /* S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */
  Servo_microseconds_timone_beta_3_Outputs_wrapper
    (&modello_completo_B.DataTypeConversion2_j,
     &modello_completo_DW.SFunctionBuilder5_DSTATE);

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper
    (&modello_completo_B.DataTypeConversion_p,
     &modello_completo_DW.SFunctionBuilder9_DSTATE);

  /* HitCross: '<S250>/Hit  Crossing' */
  modello_completo_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &modello_completo_PrevZCX.HitCrossing_Input_ZCE,
    (modello_completo_B.Gain1_p - modello_completo_P.HitCrossing_Offset));
  if (modello_completo_DW.HitCrossing_MODE == 0) {
    if (modello_completo_B.zcEvent != NO_ZCEVENT) {
      /* HitCross: '<S250>/Hit  Crossing' */
      modello_completo_B.HitCrossing = !modello_completo_B.HitCrossing;
      modello_completo_DW.HitCrossing_MODE = 1;
    } else {
      if (modello_completo_B.HitCrossing) {
        /* HitCross: '<S250>/Hit  Crossing' */
        modello_completo_B.HitCrossing = ((!(modello_completo_B.Gain1_p !=
          modello_completo_P.HitCrossing_Offset)) &&
          modello_completo_B.HitCrossing);
      }
    }
  } else {
    /* HitCross: '<S250>/Hit  Crossing' */
    modello_completo_B.HitCrossing = ((!(modello_completo_B.Gain1_p !=
      modello_completo_P.HitCrossing_Offset)) && modello_completo_B.HitCrossing);
    modello_completo_DW.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<S250>/Hit  Crossing' */

  /* Abs: '<S416>/Abs1' */
  modello_completo_B.IProdOut = fabs(modello_completo_B.Sum3_b);

  /* Outputs for Resettable SubSystem: '<S408>/Resettable Subsystem' */
  modello_completo_B.IProdOut = modello_ResettableSubsystem
    (modello_completo_B.SFunction_o4_n[1],
     &modello_completo_DW.ResettableSubsystem,
     &modello_completo_P.ResettableSubsystem,
     &modello_completo_PrevZCX.ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S408>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  modello_co_EnabledSubsystem(modello_completo_B.SFunction_o4_n[1],
    modello_completo_B.IProdOut, &modello_completo_B.rtb_Gain1_kw_idx_0,
    &modello_completo_P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S408>/Enabled Subsystem' */

  /* MATLAB Function: '<S410>/MATLAB Function1' */
  modello_completo_DW.Tf_not_empty = ((!modello_completo_DW.Tf_not_empty) ||
    (modello_completo_DW.Memory2_PreviousInput_a[0] == 1) ||
    (modello_completo_DW.Memory2_PreviousInput_a[1] == 0) ||
    modello_completo_DW.Tf_not_empty);

  /* Product: '<S563>/Product4' incorporates:
   *  MATLAB Function: '<S563>/MATLAB Function'
   */
  modello_completo_B.num_254 *= 1.0 - 2.0 * modello_completo_B.RateTransition;

  /* S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper
    (&modello_completo_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&modello_completo_DW.Memory4_PreviousInput_c[0],
         &modello_completo_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S569>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S569>/S-Function Builder */
  Mti_Update_wrapper(&modello_completo_B.SFunctionBuilder[0],
                     &modello_completo_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S567>/Unit Delay' incorporates:
   *  Constant: '<S567>/Constant3'
   */
  modello_completo_DW.UnitDelay_DSTATE_d = modello_completo_P.Constant3_Value_ok;

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&modello_completo_P.Constant1_Value_a,
    &modello_completo_B.SFunctionBuilder_o1_h[0],
    &modello_completo_B.SFunctionBuilder_o2,
    &modello_completo_DW.SFunctionBuilder_DSTATE_l);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&modello_completo_DW.Memory5_PreviousInput_l[0],
         &modello_completo_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  modello_completo_DW.Memory_PreviousInput_h5[0] =
    modello_completo_B.TmpSignalConversionAtSFunctio_m[0];
  modello_completo_DW.Memory_PreviousInput_h5[1] =
    modello_completo_B.TmpSignalConversionAtSFunctio_m[1];
  modello_completo_DW.Memory_PreviousInput_h5[2] =
    modello_completo_B.TmpSignalConversionAtSFunctio_m[2];
  modello_completo_DW.Memory_PreviousInput_h5[3] =
    modello_completo_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (modello_completo_B.i = 0; modello_completo_B.i < 8; modello_completo_B.i
       ++) {
    modello_completo_DW.Memory_PreviousInput_ic[modello_completo_B.i] =
      modello_completo_B.SFunction_o11[modello_completo_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for UnitDelay: '<S563>/Unit Delay' incorporates:
   *  Sum: '<S563>/Sum1'
   */
  modello_completo_DW.UnitDelay_DSTATE = modello_completo_B.rtb_Gain1_kw_idx_1 +
    modello_completo_B.num_254;

  /* Update for DiscreteIntegrator: '<S340>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  beccheggio1'
   *  Gain: '<S333>/Kb'
   *  Gain: '<S351>/Kt'
   *  Product: '<S337>/IProd Out'
   *  Sum: '<S333>/SumI2'
   *  Sum: '<S333>/SumI4'
   *  Sum: '<S351>/SumI3'
   *  Sum: '<S352>/SumI1'
   */
  modello_completo_DW.Integrator_DSTATE += (((modello_completo_B.SwitchBumpless2
    - modello_completo_B.Saturation) * modello_completo_P.PIDController_Kt_m +
    modello_completo_B.Gain1_c * modello_completo_P.Ki_becch) +
    (modello_completo_B.Saturation - modello_completo_B.Sum_nu) *
    modello_completo_P.PIDController_Kb_k) *
    modello_completo_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S390>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  rollio3'
   *  Gain: '<S383>/Kb'
   *  Gain: '<S401>/Kt'
   *  Product: '<S387>/IProd Out'
   *  Sum: '<S383>/SumI2'
   *  Sum: '<S383>/SumI4'
   *  Sum: '<S401>/SumI3'
   *  Sum: '<S402>/SumI1'
   */
  modello_completo_DW.Integrator_DSTATE_p += (((modello_completo_B.Alettoni -
    modello_completo_B.Saturation_f) * modello_completo_P.PIDController_Kt +
    modello_completo_B.Gain1_j * modello_completo_P.Ki_roll) +
    (modello_completo_B.Saturation_f - modello_completo_B.Sum_n3) *
    modello_completo_P.PIDController_Kb) *
    modello_completo_P.Integrator_gainval_g;
  if (modello_completo_B.Sum_o > 0.0) {
    modello_completo_DW.Integrator_PrevResetState = 1;
  } else if (modello_completo_B.Sum_o < 0.0) {
    modello_completo_DW.Integrator_PrevResetState = -1;
  } else if (modello_completo_B.Sum_o == 0.0) {
    modello_completo_DW.Integrator_PrevResetState = 0;
  } else {
    modello_completo_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S390>/Integrator' */

  /* Update for DiscreteTransferFcn: '<S304>/Discrete Washout Filter' */
  modello_completo_DW.DiscreteWashoutFilter_states = modello_completo_B.denAccum;

  /* Update for Memory: '<S2>/Memory' */
  modello_completo_DW.Memory_PreviousInput_n = modello_completo_B.SFunction_o4;

  /* Update for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

  /* S-Function "Servo_microseconds_alettoni_beta_3_wrapper" Block: <S10>/S-Function Builder10 */
  Servo_microseconds_alettoni_beta_3_Update_wrapper
    (&modello_completo_B.DataTypeConversion1_c,
     &modello_completo_DW.SFunctionBuilder10_DSTATE);

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <S10>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper(&modello_completo_B.Sum,
    &modello_completo_DW.SFunctionBuilder4_DSTATE);

  /* Update for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

  /* S-Function "Servo_microseconds_timone_beta_3_wrapper" Block: <S10>/S-Function Builder5 */
  Servo_microseconds_timone_beta_3_Update_wrapper
    (&modello_completo_B.DataTypeConversion2_j,
     &modello_completo_DW.SFunctionBuilder5_DSTATE);

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <S10>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper
    (&modello_completo_B.DataTypeConversion_p,
     &modello_completo_DW.SFunctionBuilder9_DSTATE);

  /* Update for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S4>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper
    (&modello_completo_DW.SFunctionBuilder_DSTATE_n);
}

/* Model step function for TID1 */
void modello_completo_step1(void)      /* Sample time: [0.04s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  rtb_PulseGenerator = (modello_completo_DW.clockTickCounter <
                        modello_completo_P.PulseGenerator_Duty) &&
    (modello_completo_DW.clockTickCounter >= 0) ?
    modello_completo_P.PulseGenerator_Amp : 0.0;
  if (modello_completo_DW.clockTickCounter >=
      modello_completo_P.PulseGenerator_Period - 1.0) {
    modello_completo_DW.clockTickCounter = 0;
  } else {
    modello_completo_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Pulse Generator' */

  /* MATLABSystem: '<S5>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<S5>/Digital Output' */

  /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
  rtb_PulseGenerator = (modello_completo_DW.clockTickCounter_c <
                        modello_completo_P.PulseGenerator1_Duty) &&
    (modello_completo_DW.clockTickCounter_c >= 0) ?
    modello_completo_P.PulseGenerator1_Amp : 0.0;
  if (modello_completo_DW.clockTickCounter_c >=
      modello_completo_P.PulseGenerator1_Period - 1.0) {
    modello_completo_DW.clockTickCounter_c = 0;
  } else {
    modello_completo_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Pulse Generator1' */

  /* MATLABSystem: '<S5>/Digital Output1' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(44, tmp);

  /* End of MATLABSystem: '<S5>/Digital Output1' */
}

/* Model step function for TID2 */
void modello_completo_step2(void)      /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S27>/Add2' incorporates:
   *  Constant: '<S27>/Constant4'
   *  Constant: '<S27>/Constant5'
   *  Memory: '<S27>/Memory2'
   */
  modello_completo_DW.Memory2_PreviousInput +=
    modello_completo_P.Constant4_Value_a + modello_completo_P.Constant5_Value_a;

  /* Switch: '<S27>/Switch1' */
  if (modello_completo_DW.Memory2_PreviousInput >
      modello_completo_P.Switch1_Threshold_c) {
    /* Sum: '<S27>/Add2' incorporates:
     *  Constant: '<S27>/Constant4'
     */
    modello_completo_DW.Memory2_PreviousInput =
      modello_completo_P.Constant4_Value_a;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* RateTransition: '<S27>/Rate Transition' */
  modello_completo_DW.RateTransition_Buffer0 =
    modello_completo_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void modello_completo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)modello_completo_M, 0,
                sizeof(RT_MODEL_modello_completo_T));

  /* block I/O */
  (void) memset(((void *) &modello_completo_B), 0,
                sizeof(B_modello_completo_T));

  /* states (dwork) */
  (void) memset((void *)&modello_completo_DW, 0,
                sizeof(DW_modello_completo_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    codertarget_arduinobase_inter_T *obj;
    real_T Switch_a;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S569>/S-Function Builder' */

    /* S-Function Block: <S569>/S-Function Builder */
    Mti_Start_wrapper(&modello_completo_DW.SFunctionBuilder_DSTATE);
    modello_completo_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
    modello_completo_PrevZCX.ResettableSubsystem_Reset_ZCE_p =
      UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.ResettableSubsystem_Reset_ZCE_h =
      UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.ResettableSubsystem_Reset_ZCE = UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.SampleandHold_Trig_ZCE_h = UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    modello_completo_PrevZCX.ResettableSubsystem_o.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;
    modello_completo_PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&modello_completo_DW.Memory4_PreviousInput_c[0],
           &modello_completo_P.Memory4_InitialCondition_g[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S569>/S-Function Builder' */

    /* S-Function Block: <S569>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          modello_completo_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S567>/Unit Delay' */
    modello_completo_DW.UnitDelay_DSTATE_d =
      modello_completo_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          modello_completo_DW.SFunctionBuilder_DSTATE_l = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      modello_completo_DW.Memory5_PreviousInput_l[i] =
        modello_completo_P.Memory5_InitialCondition_d;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    modello_completo_DW.Memory1_PreviousInput_d[0] =
      modello_completo_P.Memory1_InitialCondition_b;
    modello_completo_DW.Memory1_PreviousInput_d[1] =
      modello_completo_P.Memory1_InitialCondition_b;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    modello_completo_DW.Memory_PreviousInput_h5[0] =
      modello_completo_P.Memory_InitialCondition_o;
    modello_completo_DW.Memory_PreviousInput_h5[1] =
      modello_completo_P.Memory_InitialCondition_o;
    modello_completo_DW.Memory_PreviousInput_h5[2] =
      modello_completo_P.Memory_InitialCondition_o;
    modello_completo_DW.Memory_PreviousInput_h5[3] =
      modello_completo_P.Memory_InitialCondition_o;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    modello_completo_DW.Memory3_PreviousInput_o =
      modello_completo_P.Memory3_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      modello_completo_DW.Memory_PreviousInput_ic[i] =
        modello_completo_P.Memory_InitialCondition_at;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      modello_completo_DW.Memory2_PreviousInput_a[i] =
        modello_completo_P.Memory2_InitialCondition_g[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition' */
    modello_completo_DW.RateTransition_Buffer0 =
      modello_completo_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S27>/Switch' incorporates:
     *  Memory: '<S27>/Memory1'
     */
    modello_completo_DW.Memory1_PreviousInput =
      modello_completo_P.Memory1_InitialCondition_p;

    /* InitializeConditions for Sum: '<S27>/Add' incorporates:
     *  Memory: '<S27>/Memory'
     */
    modello_completo_DW.Memory_PreviousInput =
      modello_completo_P.Memory_InitialCondition_au;

    /* InitializeConditions for UnitDelay: '<S563>/Unit Delay' */
    modello_completo_DW.UnitDelay_DSTATE =
      modello_completo_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S340>/Integrator' */
    modello_completo_DW.Integrator_DSTATE =
      modello_completo_P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S390>/Integrator' */
    modello_completo_DW.Integrator_DSTATE_p =
      modello_completo_P.PIDController_InitialConditio_d;
    modello_completo_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S304>/Discrete Washout Filter' */
    modello_completo_DW.DiscreteWashoutFilter_states =
      modello_completo_P.DiscreteWashoutFilter_InitialSt;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    modello_completo_DW.Memory_PreviousInput_n =
      modello_completo_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S570>/Delay Input2'
     *
     * Block description for '<S570>/Delay Input2':
     *
     *  Store in Global RAM
     */
    modello_completo_DW.DelayInput2_DSTATE =
      modello_completo_P.DelayInput2_InitialCondition;

    /* InitializeConditions for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

    /* S-Function Block: <S10>/S-Function Builder10 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          modello_completo_DW.SFunctionBuilder10_DSTATE = initVector[0];
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
          modello_completo_DW.SFunctionBuilder4_DSTATE = initVector[0];
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
          modello_completo_DW.SFunctionBuilder5_DSTATE = initVector[0];
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
          modello_completo_DW.SFunctionBuilder9_DSTATE = initVector[0];
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
          modello_completo_DW.SFunctionBuilder_DSTATE_n = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
    modello_completo_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    modello_completo_DW.clockTickCounter_c = 0;

    /* InitializeConditions for Sum: '<S27>/Add2' incorporates:
     *  Memory: '<S27>/Memory2'
     */
    modello_completo_DW.Memory2_PreviousInput =
      modello_completo_P.Memory2_InitialCondition_o;

    /* SystemInitialize for Enabled SubSystem: '<S567>/Execution_loop' */
    /* Start for MATLABSystem: '<S571>/I2C Read12' */
    modello_completo_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &modello_completo_DW.obj_f;
    modello_completo_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    modello_completo_DW.obj_f.isInitialized = 0;
    modello_completo_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    modello_completo_DW.obj_f.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_f.SampleTime = modello_completo_P.t_AP;
    obj = &modello_completo_DW.obj_f;
    modello_completo_DW.obj_f.isSetupComplete = false;
    modello_completo_DW.obj_f.isInitialized = 1;
    modello_completo_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(modello_completo_B.i2cname, 0);
    modello_completo_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = modello_completo_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    modello_completo_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S571>/I2C Read1' */
    modello_completo_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &modello_completo_DW.obj_p;
    modello_completo_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    modello_completo_DW.obj_p.isInitialized = 0;
    modello_completo_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    modello_completo_DW.obj_p.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_p.SampleTime = modello_completo_P.t_AP;
    obj = &modello_completo_DW.obj_p;
    modello_completo_DW.obj_p.isSetupComplete = false;
    modello_completo_DW.obj_p.isInitialized = 1;
    modello_completo_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(modello_completo_B.i2cname, 0);
    modello_completo_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = modello_completo_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    modello_completo_DW.obj_p.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S571>/S-Function Builder' incorporates:
     *  Outport: '<S571>/T'
     */
    modello_completo_B.SFunctionBuilder_o1 = modello_completo_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S571>/S-Function Builder1' incorporates:
     *  Outport: '<S571>/p'
     */
    modello_completo_B.SFunctionBuilder1 = modello_completo_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S567>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S567>/MATLAB Function' */
    modello_completo_DW.P_ref = 101325.0;
    modello_completo_DW.rl_up = 300.0;
    modello_completo_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S567>/One_time_initialization' */
    One_time_initializatio_Init(&modello_completo_B.One_time_initialization,
      &modello_completo_DW.One_time_initialization,
      &modello_completo_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S567>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S575>/Subsystem1' */
    /* SystemInitialize for Outport: '<S577>/T_0' incorporates:
     *  Inport: '<S577>/T'
     */
    modello_completo_B.T = modello_completo_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S575>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S568>/Subsystem1' */
    /* SystemInitialize for Switch: '<S578>/Switch' incorporates:
     *  Outport: '<S578>/h_to_subtract'
     */
    modello_completo_B.Switch = modello_completo_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S568>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S568>/Subsystem2' */
    /* SystemInitialize for MATLAB Function: '<S579>/Create_message' */
    modello_completo_DW.end_found = false;
    modello_completo_DW.start_found = false;
    modello_completo_DW.counter_k = 0U;
    memset(&modello_completo_DW.message[0], 0, 80U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S579>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S581>/Memory' */
      modello_completo_DW.Memory_PreviousInput_l[i] =
        modello_completo_P.Memory_InitialCondition_ab;

      /* SystemInitialize for ComplexToRealImag: '<S581>/Complex to Real-Imag' incorporates:
       *  Outport: '<S581>/Outport'
       */
      modello_completo_B.ComplextoRealImag[i] = modello_completo_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S581>/mario' */
    modello_completo_B.indice_dimario = modello_completo_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S579>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S568>/Subsystem2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&modello_completo_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);
    modello_completo_DW.WP_dbP_not_empty = false;
    modello_completo_DW.WP_dbP_AL_not_empty = false;
    modello_completo_DW.test1 = 0.0;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3' */
    modello_completo_DW.counter = 0U;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    modello_completo_DW.Interr_parz = false;
    memset(&modello_completo_DW.message_i[0], 0, 100U * sizeof(uint8_T));
    modello_completo_DW.counter_a = 0U;
    modello_completo_DW.mess_len = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    modello_completo_DW.is_active_c9_modello_completo = 0U;
    modello_completo_DW.i = 0U;

    /* SystemInitialize for Chart: '<S15>/Chart' incorporates:
     *  SubSystem: '<S24>/sendbyte'
     */
    /* Start for MATLABSystem: '<S25>/Serial Transmit' */
    modello_completo_DW.obj_o.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_o.Protocol =
      modello_completo_P.SerialTransmit_Protocol;
    modello_completo_DW.obj_o.isInitialized = 1;
    modello_completo_DW.obj_o.port = 2.0;
    modello_completo_DW.obj_o.dataSizeInBytes = 1.0;
    modello_completo_DW.obj_o.dataType = 0.0;
    modello_completo_DW.obj_o.sendModeEnum = 0.0;
    modello_completo_DW.obj_o.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(modello_completo_DW.obj_o.port);
    if (Switch_a < 256.0) {
      if (Switch_a >= 0.0) {
        tmp_0 = (uint8_T)Switch_a;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    modello_completo_DW.obj_o.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S25>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
    modello_completo_DW.is_active_c23_modello_completo = 0U;
    modello_completo_DW.is_c23_modello_completo = 0;

    /* SystemInitialize for Chart: '<S38>/ STATI' */
    modello_completo_DW.is_AUTOMATICA = 0;
    modello_completo_DW.is_active_c26_modello_completo = 0U;
    modello_completo_DW.is_c26_modello_completo = 0;
    modello_completo_B.switch_manetta = 0.0;
    modello_completo_B.switch_equilibratore = 0.0;
    modello_completo_B.switch_alettoni = 0.0;
    modello_completo_B.switch_timone = 0.0;
    modello_completo_B.modo = 1.0;

    /* SystemInitialize for Enabled SubSystem: '<S408>/Enabled Subsystem' */
    model_EnabledSubsystem_Init(&Switch_a,
      &modello_completo_P.EnabledSubsystem_h);

    /* End of SystemInitialize for SubSystem: '<S408>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S408>/Resettable Subsystem' */
    mo_ResettableSubsystem_Init(&modello_completo_DW.ResettableSubsystem,
      &modello_completo_P.ResettableSubsystem);

    /* End of SystemInitialize for SubSystem: '<S408>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S409>/Enabled Subsystem' */
    model_EnabledSubsystem_Init(&modello_completo_B.Switch_l,
      &modello_completo_P.EnabledSubsystem_j);

    /* End of SystemInitialize for SubSystem: '<S409>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S409>/Resettable Subsystem' */
    mo_ResettableSubsystem_Init(&modello_completo_DW.ResettableSubsystem_o,
      &modello_completo_P.ResettableSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S409>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S410>/MATLAB Function1' */
    modello_completo_DW.Tf_not_empty = false;

    /* SystemInitialize for Enabled SubSystem: '<S432>/Enabled ' */
    /* SystemInitialize for Switch: '<S434>/Switch' incorporates:
     *  Outport: '<S434>/Alarm Safe'
     */
    modello_completo_B.Switch_n = modello_completo_P.AlarmSafe_Y0;

    /* End of SystemInitialize for SubSystem: '<S432>/Enabled ' */

    /* SystemInitialize for Resettable SubSystem: '<S432>/Resettable Subsystem' */
    /* InitializeConditions for Sum: '<S436>/Sum' incorporates:
     *  Memory: '<S436>/Memory'
     */
    modello_completo_DW.Memory_PreviousInput_h =
      modello_completo_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S432>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S415>/MATLAB Function1' */
    modello_completo_DW.alarm = 0.0;

    /* SystemInitialize for Chart: '<S39>/Chart' */
    modello_completo_DW.is_active_c21_modello_completo = 0U;
    modello_completo_DW.is_c21_modello_completo = 0;

    /* SystemInitialize for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' */
    /* InitializeConditions for Memory: '<S438>/Memory' */
    modello_completo_DW.Memory_PreviousInput_i =
      modello_completo_P.Memory_InitialCondition_a;

    /* InitializeConditions for Memory: '<S438>/Memory1' */
    modello_completo_DW.Memory1_PreviousInput_o =
      modello_completo_P.Memory1_InitialCondition;

    /* SystemInitialize for Chart: '<S438>/Chart1' */
    modello_completo_DW.temporalCounter_i1 = 0U;
    modello_completo_DW.is_active_c1_modello_completo = 0U;
    modello_completo_DW.is_c1_modello_completo = 0;

    /* End of SystemInitialize for SubSystem: '<S39>/DECOLLO AUTOMATICO' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem' */
    /* InitializeConditions for Memory: '<S439>/Memory1' */
    modello_completo_DW.Memory1_PreviousInput_h =
      modello_completo_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<S439>/Memory3' */
    modello_completo_DW.Memory3_PreviousInput =
      modello_completo_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S439>/Memory6' */
    modello_completo_DW.Memory6_PreviousInput =
      modello_completo_P.Memory6_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S439>/VETTORIALE' */
    modello_completo_DW.ALT_ref = 0.0;

    /* SystemInitialize for Outport: '<S439>/Out2' */
    modello_completo_B.h_vett = modello_completo_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem1' */
    /* InitializeConditions for Memory: '<S440>/Memory7' */
    modello_completo_DW.Memory7_PreviousInput =
      modello_completo_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S440>/Memory5' */
    modello_completo_DW.Memory5_PreviousInput =
      modello_completo_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S440>/Memory1' */
    modello_completo_DW.Memory1_PreviousInput_l =
      modello_completo_P.Memory1_InitialCondition_f;

    /* InitializeConditions for Memory: '<S440>/Memory2' */
    modello_completo_DW.Memory2_PreviousInput_f =
      modello_completo_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S440>/ALLINEAMENTO' */
    modello_completo_DW.flag_c = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S440>/APPROACH' */
    /* InitializeConditions for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
    modello_completo_DW.DiscreteTimeIntegrator_DSTATE =
      modello_completo_P.DiscreteTimeIntegrator_IC;
    modello_completo_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* SystemInitialize for MATLAB Function: '<S451>/MATLAB Function' */
    modello_completo_DW.x_not_empty = false;
    modello_completo_DW.x_new_not_empty = false;
    modello_completo_DW.cycle_count_not_empty = false;
    modello_completo_DW.eps_not_empty = false;

    /* SystemInitialize for Product: '<S451>/Multiply' incorporates:
     *  Outport: '<S451>/h_ref'
     */
    modello_completo_B.Multiply = modello_completo_P.h_ref_Y0;

    /* SystemInitialize for Outport: '<S451>/flare_data' */
    modello_completo_B.x_f_out = modello_completo_P.flare_data_Y0;
    modello_completo_B.h_f_out = modello_completo_P.flare_data_Y0;
    modello_completo_B.k_x_out = modello_completo_P.flare_data_Y0;
    modello_completo_B.h_c_out = modello_completo_P.flare_data_Y0;

    /* SystemInitialize for Outport: '<S451>/landing_abort' */
    modello_completo_B.no_solution = modello_completo_P.landing_abort_Y0;

    /* End of SystemInitialize for SubSystem: '<S440>/APPROACH' */

    /* SystemInitialize for Chart: '<S440>/Chart1' */
    modello_completo_DW.is_active_c10_modello_completo = 0U;
    modello_completo_DW.is_c10_modello_completo = 0;

    /* SystemInitialize for Enabled SubSystem: '<S440>/FLARE' */
    /* SystemInitialize for Sum: '<S455>/Sum2' incorporates:
     *  Outport: '<S455>/h_ref'
     */
    modello_completo_B.Sum2 = modello_completo_P.h_ref_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S440>/FLARE' */

    /* SystemInitialize for Triggered SubSystem: '<S440>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S465>/ ' incorporates:
     *  Inport: '<S465>/In'
     */
    modello_completo_B.In[0] = modello_completo_P._Y0_b[0];
    modello_completo_B.In[1] = modello_completo_P._Y0_b[1];

    /* End of SystemInitialize for SubSystem: '<S440>/Sample and Hold' */

    /* SystemInitialize for MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
     *  Outport: '<S440>/QUOTA_AL'
     */
    modello_completo_B.QUOTA_m = modello_completo_P.QUOTA_AL_Y0;

    /* SystemInitialize for Gain: '<S458>/Gain' incorporates:
     *  Outport: '<S440>/H_LAT'
     */
    modello_completo_B.Gain = modello_completo_P.H_LAT_Y0;

    /* SystemInitialize for Gain: '<S459>/Gain' incorporates:
     *  Outport: '<S440>/H_LONG'
     */
    modello_completo_B.Gain_g = modello_completo_P.H_LONG_Y0;

    /* SystemInitialize for Outport: '<S440>/H_ALT' */
    modello_completo_B.h_Home = modello_completo_P.H_ALT_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem2' */
    /* InitializeConditions for Memory: '<S441>/Memory4' */
    modello_completo_DW.Memory4_PreviousInput =
      modello_completo_P.Memory4_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S441>/WAYPOINTS' */
    modello_completo_DW.flag_m = 0.0;
    modello_completo_DW.lat1 = 0.0;
    modello_completo_DW.long1 = 0.0;

    /* SystemInitialize for Outport: '<S441>/Out3' */
    modello_completo_B.QUOTA = modello_completo_P.Out3_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem3' */
    /* SystemInitialize for MATLAB Function: '<S442>/GO_HOME' */
    modello_completo_DW.flag = 0.0;

    /* SystemInitialize for Outport: '<S442>/Out2' */
    modello_completo_B.h_goHome = modello_completo_P.Out2_Y0_c;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem3' */

    /* SystemInitialize for Enabled SubSystem: '<S554>/Subsystem1' */
    /* SystemInitialize for MATLAB Function: '<S562>/MATLAB Function' */
    modello_completo_DW.start_found_c = false;
    modello_completo_DW.counter_n = 0U;
    for (i = 0; i < 31; i++) {
      modello_completo_DW.message_k[i] = 0U;
    }

    /* End of SystemInitialize for MATLAB Function: '<S562>/MATLAB Function' */

    /* SystemInitialize for Enabled SubSystem: '<S562>/Subsystem2' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out2'
     */
    modello_completo_B.ByteUnpack_o2_e[0] = modello_completo_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out3'
     */
    modello_completo_B.ByteUnpack_o3[0] = modello_completo_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out2'
     */
    modello_completo_B.ByteUnpack_o2_e[1] = modello_completo_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out3'
     */
    modello_completo_B.ByteUnpack_o3[1] = modello_completo_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out2'
     */
    modello_completo_B.ByteUnpack_o2_e[2] = modello_completo_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out3'
     */
    modello_completo_B.ByteUnpack_o3[2] = modello_completo_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out2'
     */
    modello_completo_B.ByteUnpack_o2_e[3] = modello_completo_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out3'
     */
    modello_completo_B.ByteUnpack_o3[3] = modello_completo_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S566>/Byte Unpack' incorporates:
     *  Outport: '<S566>/Out4'
     */
    modello_completo_B.ByteUnpack_o4[0] = modello_completo_P.Out4_Y0_i;
    modello_completo_B.ByteUnpack_o4[1] = modello_completo_P.Out4_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S562>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S554>/Subsystem1' */

    /* Start for MATLABSystem: '<S554>/Serial Receive' */
    modello_completo_DW.obj_m.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_m.Protocol =
      modello_completo_P.SerialReceive_Protocol;
    modello_completo_DW.obj_m.isInitialized = 1;
    modello_completo_DW.obj_m.DataTypeWidth = 1U;
    varargin_1 = 31U * modello_completo_DW.obj_m.DataTypeWidth;
    if (varargin_1 > 65535U) {
      varargin_1 = 65535U;
    }

    modello_completo_DW.obj_m.DataSizeInBytes = (uint16_T)varargin_1;
    MW_SCI_Open(1);
    modello_completo_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S554>/Serial Receive' */

    /* Start for MATLABSystem: '<S568>/Serial Receive1' */
    modello_completo_DW.obj_e.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_e.Protocol =
      modello_completo_P.SerialReceive1_Protocol;
    modello_completo_DW.obj_e.isInitialized = 1;
    modello_completo_DW.obj_e.DataTypeWidth = 1U;
    if (modello_completo_DW.obj_e.DataTypeWidth > 2047) {
      modello_completo_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      modello_completo_DW.obj_e.DataSizeInBytes = (uint16_T)
        (modello_completo_DW.obj_e.DataTypeWidth << 5);
    }

    MW_SCI_Open(0);
    modello_completo_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S568>/Serial Receive1' */

    /* Start for MATLABSystem: '<S554>/Serial Transmit' */
    modello_completo_DW.obj.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj.Protocol =
      modello_completo_P.SerialTransmit_Protocol_b;
    modello_completo_DW.obj.isInitialized = 1;
    modello_completo_DW.obj.port = 1.0;
    modello_completo_DW.obj.dataSizeInBytes = 1.0;
    modello_completo_DW.obj.dataType = 0.0;
    modello_completo_DW.obj.sendModeEnum = 0.0;
    modello_completo_DW.obj.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(modello_completo_DW.obj.port);
    if (Switch_a < 256.0) {
      if (Switch_a >= 0.0) {
        tmp_0 = (uint8_T)Switch_a;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    modello_completo_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S554>/Serial Transmit' */

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    modello_completo_DW.obj_d.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_d.isInitialized = 1;
    digitalIOSetup(13, 1);
    modello_completo_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    modello_completo_DW.obj_b.matlabCodegenIsDeleted = false;
    modello_completo_DW.obj_b.isInitialized = 1;
    digitalIOSetup(44, 1);
    modello_completo_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void modello_completo_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S567>/One_time_initialization' */
  One_time_initializatio_Term(&modello_completo_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S567>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S567>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S571>/I2C Read12' */
  obj = &modello_completo_DW.obj_f;
  if (!modello_completo_DW.obj_f.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((modello_completo_DW.obj_f.isInitialized == 1) &&
        modello_completo_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S571>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S571>/I2C Read1' */
  obj = &modello_completo_DW.obj_p;
  if (!modello_completo_DW.obj_p.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((modello_completo_DW.obj_p.isInitialized == 1) &&
        modello_completo_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S571>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S567>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S554>/Serial Receive' */
  if (!modello_completo_DW.obj_m.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S554>/Serial Receive' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S15>/Chart' incorporates:
   *  SubSystem: '<S24>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  if (!modello_completo_DW.obj_o.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S568>/Serial Receive1' */
  if (!modello_completo_DW.obj_e.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S568>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<S554>/Serial Transmit' */
  if (!modello_completo_DW.obj.matlabCodegenIsDeleted) {
    modello_completo_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S554>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!modello_completo_DW.obj_d.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!modello_completo_DW.obj_b.matlabCodegenIsDeleted) {
    modello_completo_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
