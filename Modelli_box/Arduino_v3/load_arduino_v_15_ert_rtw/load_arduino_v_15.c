/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_15.c
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

#include "load_arduino_v_15.h"
#include "load_arduino_v_15_private.h"

/* Named constants for Chart: '<S42>/SELEZIONE MODALITA\'  HOLD//SELECT' */
#define load_arduino_v_15_IN_Hold      ((uint8_T)1U)
#define load_arduino_v_15_IN_Select    ((uint8_T)2U)

/* Named constants for Chart: '<S40>/ STATI' */
#define load__IN_ATTERRAGGIO_AUTOMATICO ((uint8_T)1U)
#define load_ardu_IN_DECOLLO_AUTOMATICO ((uint8_T)2U)
#define load_ardui_IN_Intervento_Pilota ((uint8_T)3U)
#define load_arduino_v_15_IN_AUTOMATICA ((uint8_T)1U)
#define load_arduino_v_15_IN_Go_Home   ((uint8_T)2U)
#define load_arduino_v_15_IN_MANUALE   ((uint8_T)4U)
#define load_arduino_v_15_IN_Safe      ((uint8_T)5U)
#define load_arduino_v_15_IN_Stand_By  ((uint8_T)6U)
#define load_arduino_v_15_IN_TEST      ((uint8_T)3U)
#define load_arduino_v_15_IN_VETTORIALE ((uint8_T)4U)
#define load_arduino_v_15_IN_WAYPOINT  ((uint8_T)5U)

/* Named constants for Chart: '<S41>/Chart' */
#define load_arduino_v_15_IN_GoHome    ((uint8_T)3U)
#define load_arduino_v_15_IN_In        ((uint8_T)4U)
#define load_arduino_v_15_IN_Vettoriale ((uint8_T)5U)
#define load_arduino_v_15_IN_Waypoint  ((uint8_T)6U)
#define load_arduino_v_1_IN_AutoLanding ((uint8_T)1U)
#define load_arduino_v_1_IN_AutoTakeoff ((uint8_T)2U)

/* Named constants for Chart: '<S452>/Chart1' */
#define load_arduino_v_15_IN_Fase_0_ATO ((uint8_T)1U)
#define load_arduino_v_15_IN_Fase_1_ATO ((uint8_T)2U)
#define load_arduino_v_15_IN_Fase_2_ATO ((uint8_T)3U)
#define load_arduino_v_15_IN_Fase_3_ATO ((uint8_T)4U)
#define load_arduino_v_15_IN_Fase_4_ATO ((uint8_T)5U)

/* Named constants for Chart: '<S455>/Chart1' */
#define load_arduino_v_15_IN_Abort     ((uint8_T)1U)
#define load_arduino_v_15_IN_Allignment ((uint8_T)2U)
#define load_arduino_v_15_IN_Approach  ((uint8_T)4U)
#define load_arduino_v_15_IN_Flare     ((uint8_T)5U)
#define load_arduino_v_1_IN_Allignment1 ((uint8_T)3U)

const uint16_T load_arduino_v_15_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_load_arduino_v_15_T load_arduino_v_15_B;

/* Block states (default storage) */
DW_load_arduino_v_15_T load_arduino_v_15_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_load_arduino_v_15_T load_arduino_v_15_PrevZCX;

/* Real-time model */
static RT_MODEL_load_arduino_v_15_T load_arduino_v_15_M_;
RT_MODEL_load_arduino_v_15_T *const load_arduino_v_15_M = &load_arduino_v_15_M_;

/* Forward declaration for local functions */
static void load_arduino_v_15_find_254(const uint8_T pack[100], real_T position
  [3], real_T *counter);
static boolean_T load_arduino_v_15_ifWhileCond(const boolean_T x[100]);
static void load_arduino_v_15_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void load_arduino_v_15_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void load_arduino_v_15_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T load_arduino_v_15_ifWhileCond_o(const boolean_T x[5]);
static void load_arduino_v_15_eml_find_o(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void load_arduino_v_15_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T load_arduino_v_15_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T load_arduino_v_15_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void load_arduino_v_15_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T load_arduino_v_15_str2double(const char_T s[2]);
static boolean_T load_arduino_v_15_copydigits_k(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void load_arduino_v_15_readfloat_d(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T load_arduino_v_15_str2double_l(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T load_arduino_v_15_isUnitImag(const char_T s[3], int32_T k);
static void load_arduino_v__readNonFinite_l(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T load_arduino_v_15_copydigits_k3(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T load_arduino_v_1_copyexponent_k(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void load_arduino_v_15_readfloat_dt(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T load_arduino_v_15_str2double_lv(const char_T s[3]);
static void load_arduino_v_readNonFinite_ln(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T load_arduino_v_1_copydigits_k3z(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T load_arduino_v__copyexponent_kd(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void load_arduino_v_15_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T load_arduino_v_1_str2double_lvk(char_T s);
static real_T load_arduino_v_15_hex2dec(const char_T s[2]);
static void rate_monotonic_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

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
void load_arduino_v_15_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(load_arduino_v_15_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(load_arduino_v_15_M, 2));
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
  (load_arduino_v_15_M->Timing.TaskCounters.TID[1])++;
  if ((load_arduino_v_15_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    load_arduino_v_15_M->Timing.TaskCounters.TID[1] = 0;
  }

  (load_arduino_v_15_M->Timing.TaskCounters.TID[2])++;
  if ((load_arduino_v_15_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.1s, 0.0s] */
    load_arduino_v_15_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S422>/Enabled Subsystem'
 *    '<S423>/Enabled Subsystem'
 */
void load__EnabledSubsystem_Init(real_T *rty_u0, P_EnabledSubsystem_load_ardui_T
  *localP)
{
  /* SystemInitialize for Outport: '<S431>/1//0' */
  *rty_u0 = localP->u0_Y0;
}

/*
 * Output and update for enable system:
 *    '<S422>/Enabled Subsystem'
 *    '<S423>/Enabled Subsystem'
 */
void load_ardui_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0, P_EnabledSubsystem_load_ardui_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S422>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S431>/Enable'
   */
  if (rtu_Enable > 0) {
    /* Switch: '<S431>/Switch' incorporates:
     *  Constant: '<S431>/Constant1'
     *  Constant: '<S431>/Constant2'
     */
    if (rtu_Time > localP->Switch_Threshold) {
      *rty_u0 = localP->Constant1_Value;
    } else {
      *rty_u0 = localP->Constant2_Value;
    }

    /* End of Switch: '<S431>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S422>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S422>/Resettable Subsystem'
 *    '<S423>/Resettable Subsystem'
 */
void lo_ResettableSubsystem_Init(DW_ResettableSubsystem_load_a_T *localDW,
  P_ResettableSubsystem_load_ar_T *localP)
{
  /* InitializeConditions for Memory: '<S433>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * System reset for atomic system:
 *    '<S422>/Resettable Subsystem'
 *    '<S423>/Resettable Subsystem'
 */
void l_ResettableSubsystem_Reset(DW_ResettableSubsystem_load_a_T *localDW,
  P_ResettableSubsystem_load_ar_T *localP)
{
  /* InitializeConditions for Memory: '<S433>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S422>/Resettable Subsystem'
 *    '<S423>/Resettable Subsystem'
 */
real_T load_ar_ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_load_a_T *localDW, P_ResettableSubsystem_load_ar_T
  *localP, ZCE_ResettableSubsystem_load__T *localZCE)
{
  real_T rty_Time_0;

  /* Outputs for Resettable SubSystem: '<S422>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S432>/Reset'
   */
  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_f != POS_ZCSIG))
  {
    l_ResettableSubsystem_Reset(localDW, localP);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_f = (ZCSigState)(rtu_Reset > 0);

  /* Sum: '<S433>/Sum' incorporates:
   *  Constant: '<S433>/Constant4'
   *  Memory: '<S433>/Memory'
   */
  rty_Time_0 = load_arduino_v_15_P.t_AP + localDW->Memory_PreviousInput;

  /* Update for Memory: '<S433>/Memory' */
  localDW->Memory_PreviousInput = rty_Time_0;

  /* End of Outputs for SubSystem: '<S422>/Resettable Subsystem' */
  return rty_Time_0;
}

/* System initialize for enable system: '<S578>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_loa_T *localB,
  DW_One_time_initialization_lo_T *localDW, P_One_time_initialization_loa_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S585>/I2C Read' */
  localDW->obj_kf.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_kf;
  localDW->obj_kf.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_kf.isInitialized = 0;
  localDW->obj_kf.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_kf.matlabCodegenIsDeleted = false;
  localDW->obj_kf.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_kf;
  localDW->obj_kf.isSetupComplete = false;
  localDW->obj_kf.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_kf.BusSpeed = 100000U;
  varargin_1 = localDW->obj_kf.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_kf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read1' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read2' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read3' */
  localDW->obj_k4.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k4;
  localDW->obj_k4.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k4.isInitialized = 0;
  localDW->obj_k4.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k4.matlabCodegenIsDeleted = false;
  localDW->obj_k4.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_k4;
  localDW->obj_k4.isSetupComplete = false;
  localDW->obj_k4.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k4.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k4.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k4.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read4' */
  localDW->obj_co.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_co;
  localDW->obj_co.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_co.isInitialized = 0;
  localDW->obj_co.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_co.matlabCodegenIsDeleted = false;
  localDW->obj_co.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_co;
  localDW->obj_co.isSetupComplete = false;
  localDW->obj_co.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_co.BusSpeed = 100000U;
  varargin_1 = localDW->obj_co.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_co.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read5' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read6' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read7' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read8' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read10' */
  localDW->obj_d0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d0;
  localDW->obj_d0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d0.isInitialized = 0;
  localDW->obj_d0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d0.matlabCodegenIsDeleted = false;
  localDW->obj_d0.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_d0;
  localDW->obj_d0.isSetupComplete = false;
  localDW->obj_d0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Read11' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = load_arduino_v_15_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S585>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S585>/I2C Write2' */
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

  /* Start for MATLABSystem: '<S585>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S585>/I2C Read12' */
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

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read' incorporates:
   *  Outport: '<S585>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read1' incorporates:
   *  Outport: '<S585>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read2' incorporates:
   *  Outport: '<S585>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read3' incorporates:
   *  Outport: '<S585>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read4' incorporates:
   *  Outport: '<S585>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read5' incorporates:
   *  Outport: '<S585>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read6' incorporates:
   *  Outport: '<S585>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read7' incorporates:
   *  Outport: '<S585>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read8' incorporates:
   *  Outport: '<S585>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read9' incorporates:
   *  Outport: '<S585>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read10' incorporates:
   *  Outport: '<S585>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S585>/I2C Read11' incorporates:
   *  Outport: '<S585>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S585>/Byte Unpack' incorporates:
     *  Outport: '<S585>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S578>/One_time_initialization' */
void loa_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_loa_T *localB, DW_One_time_initialization_lo_T
  *localDW, P_One_time_initialization_loa_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S578>/One_time_initialization' incorporates:
   *  EnablePort: '<S585>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S585>/I2C Write3' incorporates:
     *  ArithShift: '<S585>/Shift Arithmetic1'
     *  Constant: '<S585>/registro memoria2 '
     *  DataTypeConversion: '<S585>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S585>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S585>/I2C Read' */
    if (localDW->obj_kf.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_kf.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S585>/I2C Read' */

    /* MATLABSystem: '<S585>/I2C Read1' */
    if (localDW->obj_o.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_o.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read1' */

    /* MATLABSystem: '<S585>/I2C Read2' */
    if (localDW->obj_d.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_d.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read2' */

    /* MATLABSystem: '<S585>/I2C Read3' */
    if (localDW->obj_k4.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_k4.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S585>/I2C Read3' */

    /* MATLABSystem: '<S585>/I2C Read4' */
    if (localDW->obj_co.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_co.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read4' */

    /* MATLABSystem: '<S585>/I2C Read5' */
    if (localDW->obj_k.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_k.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read5' */

    /* MATLABSystem: '<S585>/I2C Read6' */
    if (localDW->obj_b.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_b.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read6' */

    /* MATLABSystem: '<S585>/I2C Read7' */
    if (localDW->obj_c.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_c.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read7' */

    /* MATLABSystem: '<S585>/I2C Read8' */
    if (localDW->obj_i.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_i.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read8' */

    /* MATLABSystem: '<S585>/I2C Read9' */
    if (localDW->obj.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read9' */

    /* MATLABSystem: '<S585>/I2C Read10' */
    if (localDW->obj_d0.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_d0.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read10' */

    /* MATLABSystem: '<S585>/I2C Read11' */
    if (localDW->obj_l.SampleTime != load_arduino_v_15_P.t_AP) {
      localDW->obj_l.SampleTime = load_arduino_v_15_P.t_AP;
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
      /* MATLABSystem: '<S585>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S585>/I2C Read11' */

    /* MATLABSystem: '<S585>/I2C Write1' incorporates:
     *  Constant: '<S585>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S585>/I2C Write2' incorporates:
     *  Constant: '<S585>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_in.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S585>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_d01.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S585>/I2C Read12' */
    if (localDW->obj_ir.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_ir.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S585>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S585>/Byte Unpack' */

    /* Unpack: <S585>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S578>/One_time_initialization' */
}

/* Termination for enable system: '<S578>/One_time_initialization' */
void One_time_initializatio_Term(DW_One_time_initialization_lo_T *localDW)
{
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S585>/I2C Read' */
  obj = &localDW->obj_kf;
  if (!localDW->obj_kf.matlabCodegenIsDeleted) {
    localDW->obj_kf.matlabCodegenIsDeleted = true;
    if ((localDW->obj_kf.isInitialized == 1) && localDW->obj_kf.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read1' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read2' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read3' */
  obj = &localDW->obj_k4;
  if (!localDW->obj_k4.matlabCodegenIsDeleted) {
    localDW->obj_k4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k4.isInitialized == 1) && localDW->obj_k4.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read4' */
  obj = &localDW->obj_co;
  if (!localDW->obj_co.matlabCodegenIsDeleted) {
    localDW->obj_co.matlabCodegenIsDeleted = true;
    if ((localDW->obj_co.isInitialized == 1) && localDW->obj_co.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read5' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read6' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read7' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read8' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read10' */
  obj = &localDW->obj_d0;
  if (!localDW->obj_d0.matlabCodegenIsDeleted) {
    localDW->obj_d0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d0.isInitialized == 1) && localDW->obj_d0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read11' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S585>/I2C Write1' */
  obj_0 = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S585>/I2C Write2' */
  obj_0 = &localDW->obj_in;
  if (!localDW->obj_in.matlabCodegenIsDeleted) {
    localDW->obj_in.matlabCodegenIsDeleted = true;
    if ((localDW->obj_in.isInitialized == 1) && localDW->obj_in.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S585>/I2C Write3' */
  obj_0 = &localDW->obj_d01;
  if (!localDW->obj_d01.matlabCodegenIsDeleted) {
    localDW->obj_d01.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d01.isInitialized == 1) &&
        localDW->obj_d01.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S585>/I2C Read12' */
  obj = &localDW->obj_ir;
  if (!localDW->obj_ir.matlabCodegenIsDeleted) {
    localDW->obj_ir.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ir.isInitialized == 1) && localDW->obj_ir.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S585>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void load_arduino_v_15_find_254(const uint8_T pack[100], real_T position
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
static boolean_T load_arduino_v_15_ifWhileCond(const boolean_T x[100])
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

/* Function for Chart: '<S41>/Chart' */
static void load_arduino_v_15_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (load_arduino_v_15_B.modo == 5.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_15_B.modo == 2.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
      load_arduino_v_15_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_15_B.modo == 4.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
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
static void load_arduino_v_15_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (load_arduino_v_15_B.modo == 1.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_15_B.modo == 2.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
      load_arduino_v_15_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_15_B.modo == 5.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if ((*Ap_sel) && (load_arduino_v_15_B.modo == 4.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
      load_arduino_v_1_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (load_arduino_v_15_B.modo == 3.0)) {
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
      load_arduino_v_1_IN_AutoTakeoff;
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_15_ifWhileCond_o(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_eml_find_o(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_15_copydigits(char_T s1[4], int32_T *idx, const
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_15_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k)
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

      load_arduino_v_15_B.kexp_f = *k;
      b_k = *k;
      b_success = load_arduino_v_15_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > load_arduino_v_15_B.kexp_f));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_readfloat(char_T s1[4], int32_T *idx, const char_T
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
            load_arduino_v_15_readfloat(s1, idx, s, k, false, &isneg, b_finite,
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
      load_arduino_v_15_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = load_arduino_v_15_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = load_arduino_v_15_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static creal_T load_arduino_v_15_str2double(const char_T s[2])
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
  load_arduino_v_15_B.ntoread_j = 0;
  load_arduino_v_15_B.k_e = 0;
  while ((load_arduino_v_15_B.k_e + 1 <= 2) && (c[(uint8_T)
          s[load_arduino_v_15_B.k_e] & 127] || (s[load_arduino_v_15_B.k_e] ==
           '\x00'))) {
    load_arduino_v_15_B.k_e++;
  }

  isimag1 = false;
  b_finite = true;
  load_arduino_v_15_B.scanned1_dh = 0.0;
  load_arduino_v_15_B.idx_bj = 1;
  load_arduino_v_15_B.s1_l[0] = '\x00';
  load_arduino_v_15_B.s1_l[1] = '\x00';
  load_arduino_v_15_B.s1_l[2] = '\x00';
  load_arduino_v_15_B.s1_l[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_15_B.k_e + 1 <= 2)) {
    if (s[load_arduino_v_15_B.k_e] == '-') {
      isneg = !isneg;
      load_arduino_v_15_B.k_e++;
    } else if ((s[load_arduino_v_15_B.k_e] == ',') || (s[load_arduino_v_15_B.k_e]
                == '+') || c[(uint8_T)s[load_arduino_v_15_B.k_e] & 127]) {
      load_arduino_v_15_B.k_e++;
    } else {
      exitg1 = true;
    }
  }

  success = (load_arduino_v_15_B.k_e + 1 <= 2);
  if (success && isneg) {
    load_arduino_v_15_B.s1_l[0] = '-';
    load_arduino_v_15_B.idx_bj = 2;
  }

  load_arduino_v_15_B.e_k = load_arduino_v_15_B.k_e + 1;
  if (success) {
    if ((load_arduino_v_15_B.k_e + 1 <= 2) && ((s[load_arduino_v_15_B.k_e] ==
          'j') || (s[load_arduino_v_15_B.k_e] == 'i'))) {
      isimag1 = true;
      load_arduino_v_15_B.e_k = load_arduino_v_15_B.k_e + 2;
      while ((load_arduino_v_15_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1] ==
               '\x00') || (s[1] == ','))) {
        load_arduino_v_15_B.e_k = 3;
      }

      if ((load_arduino_v_15_B.e_k <= 2) && (s[1] == '*')) {
        load_arduino_v_15_B.e_k = 3;
        load_arduino_v_15_readfloat(load_arduino_v_15_B.s1_l,
          &load_arduino_v_15_B.idx_bj, s, &load_arduino_v_15_B.e_k, false,
          &isneg, &b_finite, &load_arduino_v_15_B.scanned1_dh, &unusedU2,
          &success);
      } else {
        load_arduino_v_15_B.s1_l[load_arduino_v_15_B.idx_bj - 1] = '1';
        load_arduino_v_15_B.idx_bj++;
      }
    } else {
      load_arduino_v_15_B.e_k = load_arduino_v_15_B.k_e + 1;
      load_arduino_v_15_readNonFinite(s, &load_arduino_v_15_B.e_k, &b_finite,
        &load_arduino_v_15_B.scanned1_dh);
      if (b_finite) {
        success = load_arduino_v_15_copydigits(load_arduino_v_15_B.s1_l,
          &load_arduino_v_15_B.idx_bj, s, &load_arduino_v_15_B.e_k, true);
        if (success) {
          success = load_arduino_v_15_copyexponent(load_arduino_v_15_B.s1_l,
            &load_arduino_v_15_B.idx_bj, s, &load_arduino_v_15_B.e_k);
        }
      } else {
        if ((load_arduino_v_15_B.idx_bj >= 2) && (load_arduino_v_15_B.s1_l[0] ==
             '-')) {
          load_arduino_v_15_B.idx_bj = 1;
          load_arduino_v_15_B.s1_l[0] = ' ';
          load_arduino_v_15_B.scanned1_dh = -load_arduino_v_15_B.scanned1_dh;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_15_B.e_k <= 2)) {
        tmp = s[load_arduino_v_15_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          load_arduino_v_15_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((load_arduino_v_15_B.e_k <= 2) && (s[load_arduino_v_15_B.e_k - 1] ==
           '*')) {
        load_arduino_v_15_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (load_arduino_v_15_B.e_k <= 2)) {
          tmp = s[load_arduino_v_15_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            load_arduino_v_15_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (load_arduino_v_15_B.e_k <= 2) {
        tmp = s[load_arduino_v_15_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          load_arduino_v_15_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (load_arduino_v_15_B.e_k <= 2)) {
      tmp = s[load_arduino_v_15_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        load_arduino_v_15_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    load_arduino_v_15_B.ntoread_j = 1;
  }

  if (success && (load_arduino_v_15_B.e_k <= 2)) {
    load_arduino_v_15_B.s1_l[load_arduino_v_15_B.idx_bj - 1] = ' ';
    load_arduino_v_15_B.idx_bj++;
    load_arduino_v_15_readfloat(load_arduino_v_15_B.s1_l,
      &load_arduino_v_15_B.idx_bj, s, &load_arduino_v_15_B.e_k, true, &success,
      &isneg, &load_arduino_v_15_B.scanned2_d, &unusedU2, &c_success);
    if (isneg) {
      load_arduino_v_15_B.ntoread_j++;
    }

    success = (c_success && (load_arduino_v_15_B.e_k > 2) && (isimag1 != success)
               && unusedU2);
  } else {
    load_arduino_v_15_B.scanned2_d = 0.0;
  }

  if (success) {
    load_arduino_v_15_B.s1_l[load_arduino_v_15_B.idx_bj - 1] = '\x00';
    switch (load_arduino_v_15_B.ntoread_j) {
     case 2:
      load_arduino_v_15_B.ntoread_j = sscanf(&load_arduino_v_15_B.s1_l[0],
        "%lf %lf", &load_arduino_v_15_B.scanned1_dh,
        &load_arduino_v_15_B.scanned2_d);
      if (load_arduino_v_15_B.ntoread_j != 2) {
        load_arduino_v_15_B.scanned1_dh = (rtNaN);
        load_arduino_v_15_B.scanned2_d = (rtNaN);
      }
      break;

     case 1:
      load_arduino_v_15_B.ntoread_j = sscanf(&load_arduino_v_15_B.s1_l[0], "%lf",
        &load_arduino_v_15_B.b_scanned1_lx);
      if (b_finite) {
        if (load_arduino_v_15_B.ntoread_j == 1) {
          load_arduino_v_15_B.scanned1_dh = load_arduino_v_15_B.b_scanned1_lx;
        } else {
          load_arduino_v_15_B.scanned1_dh = (rtNaN);
        }
      } else if (load_arduino_v_15_B.ntoread_j == 1) {
        load_arduino_v_15_B.scanned2_d = load_arduino_v_15_B.b_scanned1_lx;
      } else {
        load_arduino_v_15_B.scanned2_d = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = load_arduino_v_15_B.scanned2_d;
      x.im = load_arduino_v_15_B.scanned1_dh;
    } else {
      x.re = load_arduino_v_15_B.scanned1_dh;
      x.im = load_arduino_v_15_B.scanned2_d;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_15_copydigits_k(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_readfloat_d(char_T s1_data[], int32_T *idx, const
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
          load_arduino_v_15_readfloat_d(s1_data, idx, s_data, k, n, false,
            &isneg, b_finite, nfv, &unusedU2, success);
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
        *success = load_arduino_v_15_copydigits_k(s1_data, &b_idx, s_data, &h_k,
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
              isneg = load_arduino_v_15_copydigits_k(s1_data, idx, s_data,
                &b_idx, n, false);
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static creal_T load_arduino_v_15_str2double_l(const char_T s_data[], const
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
    load_arduino_v_15_B.ntoread = 0;
    load_arduino_v_15_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (load_arduino_v_15_B.k <= s_size[1])) {
      tmp = s_data[load_arduino_v_15_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        load_arduino_v_15_B.k++;
      } else {
        exitg1 = true;
      }
    }

    load_arduino_v_15_B.s1_size[0] = 1;
    load_arduino_v_15_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    load_arduino_v_15_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= load_arduino_v_15_B.idx) {
      memset(&load_arduino_v_15_B.s1_data[0], 0, (load_arduino_v_15_B.idx + 1) *
             sizeof(char_T));
    }

    load_arduino_v_15_B.idx = 1;
    load_arduino_v_15_readfloat_d(load_arduino_v_15_B.s1_data,
      &load_arduino_v_15_B.idx, s_data, &load_arduino_v_15_B.k, s_size[1], true,
      &isimag1, &isfinite1, &load_arduino_v_15_B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      load_arduino_v_15_B.ntoread = 1;
    }

    if (success) {
      if (load_arduino_v_15_B.k <= s_size[1]) {
        load_arduino_v_15_B.s1_data[load_arduino_v_15_B.idx - 1] = ' ';
        load_arduino_v_15_B.idx++;
        load_arduino_v_15_readfloat_d(load_arduino_v_15_B.s1_data,
          &load_arduino_v_15_B.idx, s_data, &load_arduino_v_15_B.k, s_size[1],
          true, &unusedU0, &success, &load_arduino_v_15_B.scanned2, &foundsign,
          &c_success);
        if (success) {
          load_arduino_v_15_B.ntoread++;
        }

        success = (c_success && ((load_arduino_v_15_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        load_arduino_v_15_B.scanned2 = 0.0;
      }
    } else {
      load_arduino_v_15_B.scanned2 = 0.0;
    }

    if (success) {
      load_arduino_v_15_B.s1_data[load_arduino_v_15_B.idx - 1] = '\x00';
      switch (load_arduino_v_15_B.ntoread) {
       case 2:
        load_arduino_v_15_B.ntoread = sscanf(&load_arduino_v_15_B.s1_data[0],
          "%lf %lf", &load_arduino_v_15_B.scanned1,
          &load_arduino_v_15_B.scanned2);
        if (load_arduino_v_15_B.ntoread != 2) {
          load_arduino_v_15_B.scanned1 = (rtNaN);
          load_arduino_v_15_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        load_arduino_v_15_B.ntoread = sscanf(&load_arduino_v_15_B.s1_data[0],
          "%lf", &load_arduino_v_15_B.b_scanned1);
        if (isfinite1) {
          if (load_arduino_v_15_B.ntoread == 1) {
            load_arduino_v_15_B.scanned1 = load_arduino_v_15_B.b_scanned1;
          } else {
            load_arduino_v_15_B.scanned1 = (rtNaN);
          }
        } else if (load_arduino_v_15_B.ntoread == 1) {
          load_arduino_v_15_B.scanned2 = load_arduino_v_15_B.b_scanned1;
        } else {
          load_arduino_v_15_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = load_arduino_v_15_B.scanned2;
        x.im = load_arduino_v_15_B.scanned1;
      } else {
        x.re = load_arduino_v_15_B.scanned1;
        x.im = load_arduino_v_15_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_15_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v__readNonFinite_l(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_15_copydigits_k3(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_1_copyexponent_k(char_T s1[5], int32_T *idx,
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

      load_arduino_v_15_B.kexp = *k;
      b_k = *k;
      b_success = load_arduino_v_15_copydigits_k3(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > load_arduino_v_15_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_readfloat_dt(char_T s1[5], int32_T *idx, const
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
    if (load_arduino_v_15_isUnitImag(s, b_k)) {
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
          load_arduino_v_15_readfloat_dt(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      load_arduino_v__readNonFinite_l(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = load_arduino_v_15_copydigits_k3(s1, idx, s, k, true);
        if (*success) {
          *success = load_arduino_v_1_copyexponent_k(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static creal_T load_arduino_v_15_str2double_lv(const char_T s[3])
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
  load_arduino_v_15_B.ntoread_d = 0;
  load_arduino_v_15_B.k_h = 1;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_15_B.k_h <= 3)) {
    tmp = s[load_arduino_v_15_B.k_h - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      load_arduino_v_15_B.k_h++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  load_arduino_v_15_B.scanned1_d = 0.0;
  load_arduino_v_15_B.idx_b = 1;
  for (load_arduino_v_15_B.b_k = 0; load_arduino_v_15_B.b_k < 5;
       load_arduino_v_15_B.b_k++) {
    load_arduino_v_15_B.s1[load_arduino_v_15_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_15_B.k_h <= 3)) {
    tmp = s[load_arduino_v_15_B.k_h - 1];
    if (tmp == '-') {
      isneg = !isneg;
      load_arduino_v_15_B.k_h++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      load_arduino_v_15_B.k_h++;
    } else {
      exitg1 = true;
    }
  }

  success = (load_arduino_v_15_B.k_h <= 3);
  if (success && isneg) {
    load_arduino_v_15_B.s1[0] = '-';
    load_arduino_v_15_B.idx_b = 2;
  }

  load_arduino_v_15_B.b_k = load_arduino_v_15_B.k_h - 1;
  if (success) {
    if (load_arduino_v_15_isUnitImag(s, load_arduino_v_15_B.k_h)) {
      isimag1 = true;
      load_arduino_v_15_B.b_k = load_arduino_v_15_B.k_h;
      while ((load_arduino_v_15_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[load_arduino_v_15_B.b_k] & 127] || (s[load_arduino_v_15_B.b_k] ==
               '\x00') || (s[load_arduino_v_15_B.b_k] == ','))) {
        load_arduino_v_15_B.b_k++;
      }

      if ((load_arduino_v_15_B.b_k + 1 <= 3) && (s[load_arduino_v_15_B.b_k] ==
           '*')) {
        load_arduino_v_15_B.k_h = load_arduino_v_15_B.b_k + 2;
        load_arduino_v_15_readfloat_dt(load_arduino_v_15_B.s1,
          &load_arduino_v_15_B.idx_b, s, &load_arduino_v_15_B.k_h, false, &isneg,
          &b_finite, &load_arduino_v_15_B.scanned1_d, &unusedU2, &success);
        load_arduino_v_15_B.b_k = load_arduino_v_15_B.k_h - 1;
      } else {
        load_arduino_v_15_B.s1[load_arduino_v_15_B.idx_b - 1] = '1';
        load_arduino_v_15_B.idx_b++;
      }
    } else {
      load_arduino_v__readNonFinite_l(s, &load_arduino_v_15_B.k_h, &b_finite,
        &load_arduino_v_15_B.scanned1_d);
      load_arduino_v_15_B.b_k = load_arduino_v_15_B.k_h - 1;
      if (b_finite) {
        success = load_arduino_v_15_copydigits_k3(load_arduino_v_15_B.s1,
          &load_arduino_v_15_B.idx_b, s, &load_arduino_v_15_B.k_h, true);
        load_arduino_v_15_B.b_k = load_arduino_v_15_B.k_h - 1;
        if (success) {
          success = load_arduino_v_1_copyexponent_k(load_arduino_v_15_B.s1,
            &load_arduino_v_15_B.idx_b, s, &load_arduino_v_15_B.k_h);
          load_arduino_v_15_B.b_k = load_arduino_v_15_B.k_h - 1;
        }
      } else {
        if ((load_arduino_v_15_B.idx_b >= 2) && (load_arduino_v_15_B.s1[0] ==
             '-')) {
          load_arduino_v_15_B.idx_b = 1;
          load_arduino_v_15_B.s1[0] = ' ';
          load_arduino_v_15_B.scanned1_d = -load_arduino_v_15_B.scanned1_d;
        }
      }

      while ((load_arduino_v_15_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[load_arduino_v_15_B.b_k] & 127] || (s[load_arduino_v_15_B.b_k] ==
               '\x00') || (s[load_arduino_v_15_B.b_k] == ','))) {
        load_arduino_v_15_B.b_k++;
      }

      if ((load_arduino_v_15_B.b_k + 1 <= 3) && (s[load_arduino_v_15_B.b_k] ==
           '*')) {
        load_arduino_v_15_B.b_k++;
        while ((load_arduino_v_15_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[load_arduino_v_15_B.b_k] & 127] || (s[load_arduino_v_15_B.b_k]
                 == '\x00') || (s[load_arduino_v_15_B.b_k] == ','))) {
          load_arduino_v_15_B.b_k++;
        }
      }

      if ((load_arduino_v_15_B.b_k + 1 <= 3) && ((s[load_arduino_v_15_B.b_k] ==
            'i') || (s[load_arduino_v_15_B.b_k] == 'j'))) {
        load_arduino_v_15_B.b_k++;
        isimag1 = true;
      }
    }

    while ((load_arduino_v_15_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[load_arduino_v_15_B.b_k] & 127] || (s[load_arduino_v_15_B.b_k] ==
             '\x00') || (s[load_arduino_v_15_B.b_k] == ','))) {
      load_arduino_v_15_B.b_k++;
    }
  }

  if (b_finite) {
    load_arduino_v_15_B.ntoread_d = 1;
  }

  if (success && (load_arduino_v_15_B.b_k + 1 <= 3)) {
    load_arduino_v_15_B.s1[load_arduino_v_15_B.idx_b - 1] = ' ';
    load_arduino_v_15_B.idx_b++;
    load_arduino_v_15_B.k_h = load_arduino_v_15_B.b_k + 1;
    load_arduino_v_15_readfloat_dt(load_arduino_v_15_B.s1,
      &load_arduino_v_15_B.idx_b, s, &load_arduino_v_15_B.k_h, true, &success,
      &isneg, &load_arduino_v_15_B.scanned2_g, &unusedU2, &c_success);
    if (isneg) {
      load_arduino_v_15_B.ntoread_d++;
    }

    success = (c_success && (load_arduino_v_15_B.k_h > 3) && (isimag1 != success)
               && unusedU2);
  } else {
    load_arduino_v_15_B.scanned2_g = 0.0;
  }

  if (success) {
    load_arduino_v_15_B.s1[load_arduino_v_15_B.idx_b - 1] = '\x00';
    switch (load_arduino_v_15_B.ntoread_d) {
     case 2:
      load_arduino_v_15_B.ntoread_d = sscanf(&load_arduino_v_15_B.s1[0],
        "%lf %lf", &load_arduino_v_15_B.scanned1_d,
        &load_arduino_v_15_B.scanned2_g);
      if (load_arduino_v_15_B.ntoread_d != 2) {
        load_arduino_v_15_B.scanned1_d = (rtNaN);
        load_arduino_v_15_B.scanned2_g = (rtNaN);
      }
      break;

     case 1:
      load_arduino_v_15_B.ntoread_d = sscanf(&load_arduino_v_15_B.s1[0], "%lf",
        &load_arduino_v_15_B.b_scanned1_l);
      if (b_finite) {
        if (load_arduino_v_15_B.ntoread_d == 1) {
          load_arduino_v_15_B.scanned1_d = load_arduino_v_15_B.b_scanned1_l;
        } else {
          load_arduino_v_15_B.scanned1_d = (rtNaN);
        }
      } else if (load_arduino_v_15_B.ntoread_d == 1) {
        load_arduino_v_15_B.scanned2_g = load_arduino_v_15_B.b_scanned1_l;
      } else {
        load_arduino_v_15_B.scanned2_g = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = load_arduino_v_15_B.scanned2_g;
      x.im = load_arduino_v_15_B.scanned1_d;
    } else {
      x.re = load_arduino_v_15_B.scanned1_d;
      x.im = load_arduino_v_15_B.scanned2_g;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_readNonFinite_ln(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v_1_copydigits_k3z(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static boolean_T load_arduino_v__copyexponent_kd(char_T s1[3], int32_T *idx,
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
    b_success = load_arduino_v_1_copydigits_k3z(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static void load_arduino_v_15_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
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
          load_arduino_v_15_readfloat_dtp(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      load_arduino_v_readNonFinite_ln(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = load_arduino_v_1_copydigits_k3z(s1, idx, s, k, true);
        if (*success) {
          *success = load_arduino_v__copyexponent_kd(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static creal_T load_arduino_v_1_str2double_lvk(char_T s)
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
  load_arduino_v_15_B.ntoread_ju = 0;
  load_arduino_v_15_B.d_k = 1;
  load_arduino_v_15_B.i_j = (uint8_T)s & 127;
  if (c[load_arduino_v_15_B.i_j] || (s == '\x00')) {
    load_arduino_v_15_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  load_arduino_v_15_B.scanned1_o = 0.0;
  load_arduino_v_15_B.idx_a = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_15_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      load_arduino_v_15_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[load_arduino_v_15_B.i_j]) {
      load_arduino_v_15_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (load_arduino_v_15_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    load_arduino_v_15_B.idx_a = 2;
  }

  if (success) {
    isneg = false;
    if (load_arduino_v_15_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      load_arduino_v_15_B.d_k++;
      s1[load_arduino_v_15_B.idx_a - 1] = '1';
      load_arduino_v_15_B.idx_a++;
    } else {
      load_arduino_v_readNonFinite_ln(s, &load_arduino_v_15_B.d_k, &b_finite,
        &load_arduino_v_15_B.scanned1_o);
      if (b_finite) {
        success = load_arduino_v_1_copydigits_k3z(s1, &load_arduino_v_15_B.idx_a,
          s, &load_arduino_v_15_B.d_k, true);
        if (success) {
          success = load_arduino_v__copyexponent_kd(s1,
            &load_arduino_v_15_B.idx_a, s, &load_arduino_v_15_B.d_k);
        }
      } else {
        if ((load_arduino_v_15_B.idx_a >= 2) && (s1[0] == '-')) {
          load_arduino_v_15_B.idx_a = 1;
          s1[0] = ' ';
          load_arduino_v_15_B.scanned1_o = -load_arduino_v_15_B.scanned1_o;
        }
      }

      while ((load_arduino_v_15_B.d_k <= 1) && (c[load_arduino_v_15_B.i_j] ||
              ((s == '\x00') || (s == ',')))) {
        load_arduino_v_15_B.d_k = 2;
      }

      if ((load_arduino_v_15_B.d_k <= 1) && (s == '*')) {
        load_arduino_v_15_B.d_k = 2;
      }

      if ((load_arduino_v_15_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        load_arduino_v_15_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((load_arduino_v_15_B.d_k <= 1) && (c[load_arduino_v_15_B.i_j] || ((s ==
              '\x00') || (s == ',')))) {
      load_arduino_v_15_B.d_k = 2;
    }
  }

  if (b_finite) {
    load_arduino_v_15_B.ntoread_ju = 1;
  }

  if (success && (load_arduino_v_15_B.d_k <= 1)) {
    s1[load_arduino_v_15_B.idx_a - 1] = ' ';
    load_arduino_v_15_B.idx_a++;
    load_arduino_v_15_B.d_k = 1;
    load_arduino_v_15_readfloat_dtp(s1, &load_arduino_v_15_B.idx_a, s,
      &load_arduino_v_15_B.d_k, true, &success, &isneg,
      &load_arduino_v_15_B.scanned2_b, &foundsign, &c_success);
    if (isneg) {
      load_arduino_v_15_B.ntoread_ju++;
    }

    success = (c_success && (load_arduino_v_15_B.d_k > 1) && (isimag1 != success)
               && foundsign);
  } else {
    load_arduino_v_15_B.scanned2_b = 0.0;
  }

  if (success) {
    s1[load_arduino_v_15_B.idx_a - 1] = '\x00';
    switch (load_arduino_v_15_B.ntoread_ju) {
     case 2:
      load_arduino_v_15_B.ntoread_ju = sscanf(&s1[0], "%lf %lf",
        &load_arduino_v_15_B.scanned1_o, &load_arduino_v_15_B.scanned2_b);
      if (load_arduino_v_15_B.ntoread_ju != 2) {
        load_arduino_v_15_B.scanned1_o = (rtNaN);
        load_arduino_v_15_B.scanned2_b = (rtNaN);
      }
      break;

     case 1:
      load_arduino_v_15_B.ntoread_ju = sscanf(&s1[0], "%lf",
        &load_arduino_v_15_B.b_scanned1_n);
      if (b_finite) {
        if (load_arduino_v_15_B.ntoread_ju == 1) {
          load_arduino_v_15_B.scanned1_o = load_arduino_v_15_B.b_scanned1_n;
        } else {
          load_arduino_v_15_B.scanned1_o = (rtNaN);
        }
      } else if (load_arduino_v_15_B.ntoread_ju == 1) {
        load_arduino_v_15_B.scanned2_b = load_arduino_v_15_B.b_scanned1_n;
      } else {
        load_arduino_v_15_B.scanned2_b = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = load_arduino_v_15_B.scanned2_b;
      x.im = load_arduino_v_15_B.scanned1_o;
    } else {
      x.re = load_arduino_v_15_B.scanned1_o;
      x.im = load_arduino_v_15_B.scanned2_b;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S592>/MATLAB Function' */
static real_T load_arduino_v_15_hex2dec(const char_T s[2])
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

  load_arduino_v_15_B.a_m = tmp_0;
  load_arduino_v_15_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &load_arduino_v_15_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&load_arduino_v_15_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &load_arduino_v_15_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &load_arduino_v_15_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&load_arduino_v_15_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &load_arduino_v_15_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &load_arduino_v_15_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&load_arduino_v_15_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &load_arduino_v_15_B.sk.chunks[0U], 2);
      } else {
        load_arduino_v_15_B.sk = tmp_0;
      }
    } else {
      load_arduino_v_15_B.sk = tmp_0;
    }

    uMultiWordMul(&load_arduino_v_15_B.sk.chunks[0U], 2,
                  &load_arduino_v_15_B.p16.chunks[0U], 2,
                  &load_arduino_v_15_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&load_arduino_v_15_B.r.chunks[0U], 4,
                         &load_arduino_v_15_B.r3.chunks[0U], 2);
    MultiWordAdd(&load_arduino_v_15_B.a_m.chunks[0U],
                 &load_arduino_v_15_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    load_arduino_v_15_B.a_m = tmp;
    uMultiWord2MultiWord(&load_arduino_v_15_B.p16.chunks[0U], 2,
                         &load_arduino_v_15_B.r2.chunks[0U], 3);
    uMultiWordShl(&load_arduino_v_15_B.r2.chunks[0U], 3, 4U,
                  &load_arduino_v_15_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&load_arduino_v_15_B.r1.chunks[0U], 3,
                         &load_arduino_v_15_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&load_arduino_v_15_B.a_m.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&load_arduino_v_15_B.a_m.chunks[0U], 2, 0) -
          uMultiWord2Double(&load_arduino_v_15_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&load_arduino_v_15_B.a_m.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&load_arduino_v_15_B.a_m.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&load_arduino_v_15_B.a_m.chunks[0U], 2, 0);
  }

  return x;
}

/* Model step function for TID0 */
void load_arduino_v_15_step0(void)     /* Sample time: [0.02s, 0.0s] */
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

  /* S-Function (Mti): '<S580>/S-Function Builder1' */
  Mti_Outputs_wrapper(&load_arduino_v_15_B.SFunctionBuilder1_b[0],
                      &load_arduino_v_15_DW.SFunctionBuilder1_DSTATE);

  /* S-Function (byte2any_svd): '<S580>/Byte Unpack1' */

  /* Unpack: <S580>/Byte Unpack1 */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack1_o1[0], (uint8_T*)
             &load_arduino_v_15_B.SFunctionBuilder1_b[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack1_o2[0], (uint8_T*)
             &load_arduino_v_15_B.SFunctionBuilder1_b[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack1_o3, (uint8_T*)
             &load_arduino_v_15_B.SFunctionBuilder1_b[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S580>/Byte Reversal1' */

  /* ReverseEndian: <S580>/Byte Reversal1 */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &load_arduino_v_15_B.ByteUnpack1_o2[0];
    real32_T *y0 = &load_arduino_v_15_B.ByteReversal1[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S578>/One_time_initialization' */
  /* Logic: '<S578>/Logical Operator1' incorporates:
   *  UnitDelay: '<S578>/Unit Delay'
   */
  loa_One_time_initialization(!load_arduino_v_15_DW.UnitDelay_DSTATE,
    &load_arduino_v_15_B.One_time_initialization,
    &load_arduino_v_15_DW.One_time_initialization,
    &load_arduino_v_15_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S578>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S578>/Execution_loop' incorporates:
   *  EnablePort: '<S582>/Enable'
   */
  /* UnitDelay: '<S578>/Unit Delay' */
  if (load_arduino_v_15_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S582>/I2C Read12' */
    if (load_arduino_v_15_DW.obj_f.SampleTime != load_arduino_v_15_P.t_AP) {
      load_arduino_v_15_DW.obj_f.SampleTime = load_arduino_v_15_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (load_arduino_v_15_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U, &status, 1U,
       true, false);
    if (0 == status) {
      MW_I2C_MasterRead(load_arduino_v_15_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S582>/I2C Read1' */
    if (load_arduino_v_15_DW.obj_p.SampleTime != load_arduino_v_15_P.t_AP) {
      load_arduino_v_15_DW.obj_p.SampleTime = load_arduino_v_15_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (load_arduino_v_15_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U, &status, 1U,
       true, false);
    if (0 == status) {
      MW_I2C_MasterRead(load_arduino_v_15_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &load_arduino_v_15_B.output_raw[0], 3U, false,
                        true);
      memcpy((void *)&load_arduino_v_15_B.output[0], (void *)
             &load_arduino_v_15_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
              (uint8_T)));
    } else {
      load_arduino_v_15_B.output[0] = 0U;
      load_arduino_v_15_B.output[1] = 0U;
      load_arduino_v_15_B.output[2] = 0U;
    }

    /* ArithShift: '<S582>/Shift Arithmetic4' incorporates:
     *  Constant: '<S582>/Constant1'
     */
    load_arduino_v_15_B.Ato_selector = floor
      (load_arduino_v_15_P.Constant1_Value_ol);
    if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
        (load_arduino_v_15_B.Ato_selector)) {
      load_arduino_v_15_B.Ato_selector = 0.0;
    } else {
      load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
        4.294967296E+9);
    }

    /* ArithShift: '<S582>/Shift Arithmetic3' incorporates:
     *  Constant: '<S582>/Constant5'
     */
    load_arduino_v_15_B.Al_selector = floor
      (load_arduino_v_15_P.Constant5_Value_n);
    if (rtIsNaN(load_arduino_v_15_B.Al_selector) || rtIsInf
        (load_arduino_v_15_B.Al_selector)) {
      load_arduino_v_15_B.Al_selector = 0.0;
    } else {
      load_arduino_v_15_B.Al_selector = fmod(load_arduino_v_15_B.Al_selector,
        4.294967296E+9);
    }

    /* ArithShift: '<S582>/Shift Arithmetic1' incorporates:
     *  Constant: '<S582>/Constant6'
     */
    load_arduino_v_15_B.num_254 = floor(load_arduino_v_15_P.Constant6_Value);
    if (rtIsNaN(load_arduino_v_15_B.num_254) || rtIsInf
        (load_arduino_v_15_B.num_254)) {
      load_arduino_v_15_B.num_254 = 0.0;
    } else {
      load_arduino_v_15_B.num_254 = fmod(load_arduino_v_15_B.num_254,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S582>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S582>/Shift Arithmetic1'
     *  ArithShift: '<S582>/Shift Arithmetic3'
     *  ArithShift: '<S582>/Shift Arithmetic4'
     *  Constant: '<S582>/Constant10'
     *  Constant: '<S582>/Constant11'
     *  Constant: '<S582>/Constant7'
     *  MATLABSystem: '<S582>/I2C Read1'
     *  Sum: '<S582>/Sum1'
     *  Sum: '<S582>/Sum4'
     *  Sum: '<S582>/Sum5'
     *  Sum: '<S582>/Sum6'
     */
    load_arduino_v_15_B.DataTypeConversion1_i = (int32_T)
      ((((((load_arduino_v_15_P.Constant7_Value_h + load_arduino_v_15_B.output[0])
           << (load_arduino_v_15_B.Ato_selector < 0.0 ? -(int32_T)(uint32_T)
               -load_arduino_v_15_B.Ato_selector : (int32_T)(uint32_T)
               load_arduino_v_15_B.Ato_selector)) +
          ((load_arduino_v_15_P.Constant10_Value + load_arduino_v_15_B.output[1])
           << (load_arduino_v_15_B.Al_selector < 0.0 ? -(int32_T)(uint32_T)
               -load_arduino_v_15_B.Al_selector : (int32_T)(uint32_T)
               load_arduino_v_15_B.Al_selector))) +
         load_arduino_v_15_P.Constant11_Value) + load_arduino_v_15_B.output[2]) >>
       (load_arduino_v_15_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
        -load_arduino_v_15_B.num_254 : (int32_T)(uint32_T)
        load_arduino_v_15_B.num_254));

    /* ArithShift: '<S582>/Shift Arithmetic7' incorporates:
     *  Constant: '<S582>/Constant2'
     */
    load_arduino_v_15_B.Ato_selector = floor
      (load_arduino_v_15_P.Constant2_Value_av);
    if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
        (load_arduino_v_15_B.Ato_selector)) {
      load_arduino_v_15_B.Ato_selector = 0.0;
    } else {
      load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
        4.294967296E+9);
    }

    /* ArithShift: '<S582>/Shift Arithmetic6' incorporates:
     *  Constant: '<S582>/Constant3'
     */
    load_arduino_v_15_B.Al_selector = floor
      (load_arduino_v_15_P.Constant3_Value_c);
    if (rtIsNaN(load_arduino_v_15_B.Al_selector) || rtIsInf
        (load_arduino_v_15_B.Al_selector)) {
      load_arduino_v_15_B.Al_selector = 0.0;
    } else {
      load_arduino_v_15_B.Al_selector = fmod(load_arduino_v_15_B.Al_selector,
        4.294967296E+9);
    }

    /* ArithShift: '<S582>/Shift Arithmetic2' incorporates:
     *  Constant: '<S582>/Constant4'
     */
    load_arduino_v_15_B.num_254 = floor(load_arduino_v_15_P.Constant4_Value_l);
    if (rtIsNaN(load_arduino_v_15_B.num_254) || rtIsInf
        (load_arduino_v_15_B.num_254)) {
      load_arduino_v_15_B.num_254 = 0.0;
    } else {
      load_arduino_v_15_B.num_254 = fmod(load_arduino_v_15_B.num_254,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S582>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S582>/Shift Arithmetic2'
     *  ArithShift: '<S582>/Shift Arithmetic6'
     *  ArithShift: '<S582>/Shift Arithmetic7'
     *  Constant: '<S582>/Constant8'
     *  Constant: '<S582>/Constant9'
     *  MATLABSystem: '<S582>/I2C Read12'
     *  Sum: '<S582>/Sum'
     *  Sum: '<S582>/Sum2'
     *  Sum: '<S582>/Sum3'
     */
    load_arduino_v_15_B.DataTypeConversion_ay = (int32_T)
      ((((load_arduino_v_15_P.Constant8_Value_e + rtb_H_mav[0]) <<
         (load_arduino_v_15_B.Ato_selector < 0.0 ? -(int32_T)(uint32_T)
          -load_arduino_v_15_B.Ato_selector : (int32_T)(uint32_T)
          load_arduino_v_15_B.Ato_selector)) +
        ((load_arduino_v_15_P.Constant9_Value + rtb_H_mav[1]) <<
         (load_arduino_v_15_B.Al_selector < 0.0 ? -(int32_T)(uint32_T)
          -load_arduino_v_15_B.Al_selector : (int32_T)(uint32_T)
          load_arduino_v_15_B.Al_selector))) >> (load_arduino_v_15_B.num_254 <
        0.0 ? -(int32_T)(uint32_T)-load_arduino_v_15_B.num_254 : (int32_T)
        (uint32_T)load_arduino_v_15_B.num_254));

    /* S-Function (calc_T): '<S582>/S-Function Builder' */
    calc_T_Outputs_wrapper(&load_arduino_v_15_B.One_time_initialization.I2CRead,
      &load_arduino_v_15_B.One_time_initialization.I2CRead1,
      &load_arduino_v_15_B.One_time_initialization.I2CRead2,
      &load_arduino_v_15_B.DataTypeConversion_ay,
      &load_arduino_v_15_B.SFunctionBuilder_o1,
      &load_arduino_v_15_B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S582>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&load_arduino_v_15_B.One_time_initialization.I2CRead3,
      &load_arduino_v_15_B.One_time_initialization.I2CRead4,
      &load_arduino_v_15_B.One_time_initialization.I2CRead5,
      &load_arduino_v_15_B.One_time_initialization.I2CRead6,
      &load_arduino_v_15_B.One_time_initialization.I2CRead7,
      &load_arduino_v_15_B.One_time_initialization.I2CRead8,
      &load_arduino_v_15_B.One_time_initialization.I2CRead9,
      &load_arduino_v_15_B.One_time_initialization.I2CRead10,
      &load_arduino_v_15_B.One_time_initialization.I2CRead11,
      &load_arduino_v_15_B.DataTypeConversion1_i,
      &load_arduino_v_15_B.SFunctionBuilder_o2_a,
      &load_arduino_v_15_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S578>/Execution_loop' */

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&load_arduino_v_15_P.Constant1_Value_a,
    &load_arduino_v_15_B.SFunctionBuilder_o1_h[0],
    &load_arduino_v_15_B.SFunctionBuilder_o2,
    &load_arduino_v_15_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  load_arduino_v_15_B.ATO = 0;
  load_arduino_v_15_B.caso = 0;
  memset(&load_arduino_v_15_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
  memset(&load_arduino_v_15_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  load_arduino_v_15_find_254(load_arduino_v_15_B.SFunctionBuilder_o1_h,
    load_arduino_v_15_B.lat_end, &load_arduino_v_15_B.num_254);
  if (load_arduino_v_15_DW.Interr_parz && (load_arduino_v_15_B.num_254 == 1.0))
  {
    load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_DW.counter_a + 1U);
    if (load_arduino_v_15_DW.counter_a + 1U > 255U) {
      load_arduino_v_15_B.pipk = 255;
    }

    if (load_arduino_v_15_B.lat_end[0] != load_arduino_v_15_B.pipk) {
      load_arduino_v_15_B.num_254 = 0.0;
    }
  }

  Ap_sel = !load_arduino_v_15_DW.Interr_parz;
  if ((load_arduino_v_15_B.num_254 == 1.0) && Ap_sel) {
    load_arduino_v_15_B.caso = 1;
  } else if ((load_arduino_v_15_B.num_254 == 0.0) &&
             load_arduino_v_15_DW.Interr_parz) {
    load_arduino_v_15_B.caso = 2;
  } else if ((load_arduino_v_15_B.num_254 == 1.0) &&
             load_arduino_v_15_DW.Interr_parz) {
    load_arduino_v_15_B.caso = 3;
  } else {
    if ((load_arduino_v_15_B.num_254 == 2.0) && Ap_sel) {
      load_arduino_v_15_B.caso = 4;
    }
  }

  switch (load_arduino_v_15_B.caso) {
   case 1:
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.lat_end[(int32_T)
      load_arduino_v_15_B.num_254 - 1];
    if (load_arduino_v_15_B.Ato_selector == 100.0) {
      load_arduino_v_15_DW.message_i[0] =
        load_arduino_v_15_B.SFunctionBuilder_o1_h[99];
      load_arduino_v_15_DW.Interr_parz = true;
    } else if (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
               (load_arduino_v_15_B.Ato_selector + 1.0) - 1] <= 100) {
      load_arduino_v_15_B.pipk = (int32_T)
        (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_15_B.lat_end[0] + 1.0) - 1] + 8U);
      load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk;
      if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
        load_arduino_v_15_B.soglia_dist = 255;
      }

      if (load_arduino_v_15_B.soglia_dist ==
          load_arduino_v_15_B.SFunctionBuilder_o2) {
        load_arduino_v_15_B.Al_selector = rt_roundd_snf
          (load_arduino_v_15_B.Ato_selector);
        if (load_arduino_v_15_B.Al_selector < 256.0) {
          if (load_arduino_v_15_B.Al_selector >= 0.0) {
            status = (uint8_T)load_arduino_v_15_B.Al_selector;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        load_arduino_v_15_B.pipk = (int32_T)
          (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
           (load_arduino_v_15_B.Ato_selector + 1.0) - 1] + 7U);
        if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
          load_arduino_v_15_B.pipk = 255;
        }

        load_arduino_v_15_B.Ato_selector = rt_roundd_snf
          (load_arduino_v_15_B.Ato_selector + (real_T)load_arduino_v_15_B.pipk);
        if (load_arduino_v_15_B.Ato_selector < 256.0) {
          if (load_arduino_v_15_B.Ato_selector >= 0.0) {
            find_comma = (uint8_T)load_arduino_v_15_B.Ato_selector;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          load_arduino_v_15_B.i = 0;
          load_arduino_v_15_B.soglia_dist = 0;
        } else {
          load_arduino_v_15_B.i = status - 1;
          load_arduino_v_15_B.soglia_dist = find_comma;
        }

        load_arduino_v_15_B.caso = load_arduino_v_15_B.soglia_dist -
          load_arduino_v_15_B.i;
        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
             load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.pipk] =
            load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.i +
            load_arduino_v_15_B.pipk];
        }

        load_arduino_v_15_B.ATO = 1;
        for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 100;
             load_arduino_v_15_B.i++) {
          load_arduino_v_15_B.messaggio_i[load_arduino_v_15_B.i] =
            load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i];
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i] = 0U;
        }

        load_arduino_v_15_DW.counter_a = 0U;
        load_arduino_v_15_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
          load_arduino_v_15_B.pipk = 255;
        }

        if (load_arduino_v_15_B.pipk > load_arduino_v_15_B.SFunctionBuilder_o2)
        {
          load_arduino_v_15_DW.mess_len =
            load_arduino_v_15_B.SFunctionBuilder_o2;
          if (load_arduino_v_15_B.Ato_selector > load_arduino_v_15_DW.mess_len)
          {
            load_arduino_v_15_B.i = 0;
            load_arduino_v_15_B.soglia_dist = 0;
          } else {
            load_arduino_v_15_B.i = (int32_T)load_arduino_v_15_B.Ato_selector -
              1;
            load_arduino_v_15_B.soglia_dist = (int32_T)
              load_arduino_v_15_DW.mess_len;
          }

          load_arduino_v_15_B.caso = load_arduino_v_15_B.soglia_dist -
            load_arduino_v_15_B.i;
          for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
               load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
            load_arduino_v_15_DW.message_i[load_arduino_v_15_B.pipk] =
              load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.i +
              load_arduino_v_15_B.pipk];
          }

          load_arduino_v_15_B.pipk = (int32_T)
            (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
             (load_arduino_v_15_B.Ato_selector + 1.0) - 1] + 8U);
          if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
            load_arduino_v_15_B.pipk = 255;
          }

          load_arduino_v_15_B.Ato_selector = rt_roundd_snf((real_T)
            load_arduino_v_15_B.pipk - load_arduino_v_15_DW.mess_len);
          if (load_arduino_v_15_B.Ato_selector < 256.0) {
            if (load_arduino_v_15_B.Ato_selector >= 0.0) {
              load_arduino_v_15_DW.counter_a = (uint8_T)
                load_arduino_v_15_B.Ato_selector;
            } else {
              load_arduino_v_15_DW.counter_a = 0U;
            }
          } else {
            load_arduino_v_15_DW.counter_a = MAX_uint8_T;
          }

          load_arduino_v_15_DW.Interr_parz = true;
        }
      }
    } else {
      load_arduino_v_15_DW.Interr_parz = false;
      memset(&load_arduino_v_15_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_15_DW.counter_a = 0U;
      load_arduino_v_15_DW.mess_len = 0.0;
      load_arduino_v_15_B.ATO = 1;
    }
    break;

   case 2:
    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.x[load_arduino_v_15_B.pipk] =
        (load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.pipk] !=
         0);
    }

    if (load_arduino_v_15_ifWhileCond(load_arduino_v_15_B.x)) {
      load_arduino_v_15_B.Ato_selector = rt_roundd_snf
        (load_arduino_v_15_DW.mess_len + 1.0);
      if (load_arduino_v_15_B.Ato_selector < 256.0) {
        if (load_arduino_v_15_B.Ato_selector >= 0.0) {
          find_comma = (uint8_T)load_arduino_v_15_B.Ato_selector;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      load_arduino_v_15_B.Ato_selector = rt_roundd_snf
        (load_arduino_v_15_DW.mess_len + (real_T)load_arduino_v_15_DW.counter_a);
      if (load_arduino_v_15_B.Ato_selector < 256.0) {
        if (load_arduino_v_15_B.Ato_selector >= 0.0) {
          status = (uint8_T)load_arduino_v_15_B.Ato_selector;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      if (find_comma > status) {
        load_arduino_v_15_B.i = 1;
      } else {
        load_arduino_v_15_B.i = find_comma;
      }

      if (1 > load_arduino_v_15_DW.counter_a) {
        load_arduino_v_15_B.caso = -1;
      } else {
        load_arduino_v_15_B.caso = load_arduino_v_15_DW.counter_a - 1;
      }

      for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
           load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
        load_arduino_v_15_DW.message_i[(load_arduino_v_15_B.i +
          load_arduino_v_15_B.pipk) - 1] =
          load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.pipk];
      }

      load_arduino_v_15_DW.Interr_parz = false;
      load_arduino_v_15_B.ATO = 1;
      for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 100;
           load_arduino_v_15_B.i++) {
        load_arduino_v_15_B.messaggio_i[load_arduino_v_15_B.i] =
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i];
        load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i] = 0U;
      }

      load_arduino_v_15_DW.mess_len = 0.0;
      load_arduino_v_15_DW.counter_a = 0U;
    } else {
      load_arduino_v_15_DW.Interr_parz = false;
      load_arduino_v_15_B.ATO = 1;
      memset(&load_arduino_v_15_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_15_DW.mess_len = 0.0;
      load_arduino_v_15_DW.counter_a = 0U;
    }
    break;

   case 3:
    load_arduino_v_15_B.Ato_selector = rt_roundd_snf
      (load_arduino_v_15_DW.mess_len + 1.0);
    if (load_arduino_v_15_B.Ato_selector < 256.0) {
      if (load_arduino_v_15_B.Ato_selector >= 0.0) {
        find_comma = (uint8_T)load_arduino_v_15_B.Ato_selector;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    load_arduino_v_15_B.Ato_selector = rt_roundd_snf
      (load_arduino_v_15_DW.mess_len + (real_T)load_arduino_v_15_DW.counter_a);
    if (load_arduino_v_15_B.Ato_selector < 256.0) {
      if (load_arduino_v_15_B.Ato_selector >= 0.0) {
        status = (uint8_T)load_arduino_v_15_B.Ato_selector;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    if (find_comma > status) {
      load_arduino_v_15_B.i = 1;
    } else {
      load_arduino_v_15_B.i = find_comma;
    }

    if (1 > load_arduino_v_15_DW.counter_a) {
      load_arduino_v_15_B.caso = -1;
    } else {
      load_arduino_v_15_B.caso = load_arduino_v_15_DW.counter_a - 1;
    }

    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
         load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_DW.message_i[(load_arduino_v_15_B.i +
        load_arduino_v_15_B.pipk) - 1] =
        load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.pipk];
    }

    load_arduino_v_15_DW.Interr_parz = false;
    load_arduino_v_15_B.ATO = 1;
    for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 100;
         load_arduino_v_15_B.i++) {
      load_arduino_v_15_B.messaggio_i[load_arduino_v_15_B.i] =
        load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i];
      load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i] = 0U;
    }

    load_arduino_v_15_DW.mess_len = 0.0;
    load_arduino_v_15_DW.counter_a = 0U;
    load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_B.lat_end[(int32_T)
      load_arduino_v_15_B.num_254 - 1] + 1.0) - 1;
    if (load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.pipk] <=
        100) {
      load_arduino_v_15_B.soglia_dist = (int32_T)
        (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_15_B.lat_end[0] + 1.0) - 1] + 8U);
      if ((uint32_T)load_arduino_v_15_B.soglia_dist > 255U) {
        load_arduino_v_15_B.soglia_dist = 255;
      }

      load_arduino_v_15_B.caso = load_arduino_v_15_B.SFunctionBuilder_o2;
      if (load_arduino_v_15_B.SFunctionBuilder_o2 < 0) {
        load_arduino_v_15_B.caso = 0;
      } else {
        if (load_arduino_v_15_B.SFunctionBuilder_o2 > 255) {
          load_arduino_v_15_B.caso = 255;
        }
      }

      if (load_arduino_v_15_B.soglia_dist == load_arduino_v_15_B.caso) {
        load_arduino_v_15_B.Ato_selector = rt_roundd_snf
          (load_arduino_v_15_B.lat_end[(int32_T)load_arduino_v_15_B.num_254 - 1]);
        if (load_arduino_v_15_B.Ato_selector < 256.0) {
          if (load_arduino_v_15_B.Ato_selector >= 0.0) {
            status = (uint8_T)load_arduino_v_15_B.Ato_selector;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        load_arduino_v_15_B.pipk = (int32_T)
          (load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.pipk] +
           7U);
        if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
          load_arduino_v_15_B.pipk = 255;
        }

        load_arduino_v_15_B.Ato_selector = rt_roundd_snf
          (load_arduino_v_15_B.lat_end[(int32_T)load_arduino_v_15_B.num_254 - 1]
           + (real_T)load_arduino_v_15_B.pipk);
        if (load_arduino_v_15_B.Ato_selector < 256.0) {
          if (load_arduino_v_15_B.Ato_selector >= 0.0) {
            find_comma = (uint8_T)load_arduino_v_15_B.Ato_selector;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          load_arduino_v_15_B.i = 0;
          load_arduino_v_15_B.pipk = 0;
        } else {
          load_arduino_v_15_B.i = status - 1;
          load_arduino_v_15_B.pipk = find_comma;
        }

        load_arduino_v_15_B.caso = load_arduino_v_15_B.pipk -
          load_arduino_v_15_B.i;
        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
             load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.pipk] =
            load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.i +
            load_arduino_v_15_B.pipk];
        }

        for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 100;
             load_arduino_v_15_B.i++) {
          load_arduino_v_15_B.messaggio_2[load_arduino_v_15_B.i] =
            load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i];
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i] = 0U;
        }

        load_arduino_v_15_DW.counter_a = 0U;
        load_arduino_v_15_DW.mess_len = 0.0;
      } else {
        load_arduino_v_15_B.soglia_dist = (int32_T)
          (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
           (load_arduino_v_15_B.lat_end[0] + 1.0) - 1] + 8U);
        if ((uint32_T)load_arduino_v_15_B.soglia_dist > 255U) {
          load_arduino_v_15_B.soglia_dist = 255;
        }

        load_arduino_v_15_B.caso = load_arduino_v_15_B.SFunctionBuilder_o2;
        if (load_arduino_v_15_B.SFunctionBuilder_o2 < 0) {
          load_arduino_v_15_B.caso = 0;
        } else {
          if (load_arduino_v_15_B.SFunctionBuilder_o2 > 255) {
            load_arduino_v_15_B.caso = 255;
          }
        }

        if (load_arduino_v_15_B.soglia_dist > load_arduino_v_15_B.caso) {
          load_arduino_v_15_DW.mess_len =
            load_arduino_v_15_B.SFunctionBuilder_o2;
          if (load_arduino_v_15_B.lat_end[(int32_T)load_arduino_v_15_B.num_254 -
              1] > load_arduino_v_15_DW.mess_len) {
            load_arduino_v_15_B.i = 0;
            load_arduino_v_15_B.caso = 0;
          } else {
            load_arduino_v_15_B.i = (int32_T)load_arduino_v_15_B.lat_end
              [(int32_T)load_arduino_v_15_B.num_254 - 1] - 1;
            load_arduino_v_15_B.caso = (int32_T)load_arduino_v_15_DW.mess_len;
          }

          load_arduino_v_15_B.caso -= load_arduino_v_15_B.i;
          for (load_arduino_v_15_B.soglia_dist = 0;
               load_arduino_v_15_B.soglia_dist < load_arduino_v_15_B.caso;
               load_arduino_v_15_B.soglia_dist++) {
            load_arduino_v_15_DW.message_i[load_arduino_v_15_B.soglia_dist] =
              load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.i +
              load_arduino_v_15_B.soglia_dist];
          }

          load_arduino_v_15_B.pipk = (int32_T)
            (load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.pipk]
             + 8U);
          if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
            load_arduino_v_15_B.pipk = 255;
          }

          load_arduino_v_15_B.Ato_selector = rt_roundd_snf((real_T)
            load_arduino_v_15_B.pipk - load_arduino_v_15_DW.mess_len);
          if (load_arduino_v_15_B.Ato_selector < 256.0) {
            if (load_arduino_v_15_B.Ato_selector >= 0.0) {
              load_arduino_v_15_DW.counter_a = (uint8_T)
                load_arduino_v_15_B.Ato_selector;
            } else {
              load_arduino_v_15_DW.counter_a = 0U;
            }
          } else {
            load_arduino_v_15_DW.counter_a = MAX_uint8_T;
          }

          load_arduino_v_15_DW.Interr_parz = true;
        }
      }
    } else {
      load_arduino_v_15_DW.Interr_parz = false;
      memset(&load_arduino_v_15_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
      memset(&load_arduino_v_15_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_15_DW.counter_a = 0U;
      load_arduino_v_15_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
        (load_arduino_v_15_B.lat_end[0] + 1.0) - 1] <= 100) {
      load_arduino_v_15_B.Ato_selector = rt_roundd_snf
        (load_arduino_v_15_B.lat_end[0]);
      if (load_arduino_v_15_B.Ato_selector < 256.0) {
        if (load_arduino_v_15_B.Ato_selector >= 0.0) {
          status = (uint8_T)load_arduino_v_15_B.Ato_selector;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      load_arduino_v_15_B.pipk = (int32_T)
        (load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_15_B.lat_end[0] + 1.0) - 1] + 7U);
      if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
        load_arduino_v_15_B.pipk = 255;
      }

      load_arduino_v_15_B.Ato_selector = rt_roundd_snf
        (load_arduino_v_15_B.lat_end[0] + (real_T)load_arduino_v_15_B.pipk);
      if (load_arduino_v_15_B.Ato_selector < 256.0) {
        if (load_arduino_v_15_B.Ato_selector >= 0.0) {
          find_comma = (uint8_T)load_arduino_v_15_B.Ato_selector;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (status > find_comma) {
        load_arduino_v_15_B.ATO = 0;
        load_arduino_v_15_B.pipk = 0;
      } else {
        load_arduino_v_15_B.ATO = status - 1;
        load_arduino_v_15_B.pipk = find_comma;
      }

      load_arduino_v_15_B.caso = load_arduino_v_15_B.pipk -
        load_arduino_v_15_B.ATO;
      for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
           load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
        load_arduino_v_15_B.messaggio_i[load_arduino_v_15_B.pipk] =
          load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.ATO +
          load_arduino_v_15_B.pipk];
      }
    } else {
      load_arduino_v_15_DW.Interr_parz = false;
      memset(&load_arduino_v_15_DW.message_i[0], 0, 100U * sizeof(uint8_T));
    }

    load_arduino_v_15_B.ATO = 1;
    if ((load_arduino_v_15_B.SFunctionBuilder_o1_h[(int32_T)
         (load_arduino_v_15_B.lat_end[1] + 1.0) - 1] <= 100) &&
        (load_arduino_v_15_B.lat_end[1] - load_arduino_v_15_B.lat_end[0] > 3.0))
    {
      load_arduino_v_15_B.Ato_selector = rt_roundd_snf((real_T)
        load_arduino_v_15_B.SFunctionBuilder_o2 - load_arduino_v_15_B.lat_end[1]);
      load_arduino_v_15_B.qY = load_arduino_v_15_B.SFunctionBuilder_o1_h
        [(int32_T)(load_arduino_v_15_B.lat_end[1] + 1.0) - 1];
      load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_B.qY + 7U);
      if (load_arduino_v_15_B.qY + 7U > 255U) {
        load_arduino_v_15_B.pipk = 255;
      }

      if (load_arduino_v_15_B.Ato_selector < 2.147483648E+9) {
        if (load_arduino_v_15_B.Ato_selector >= -2.147483648E+9) {
          load_arduino_v_15_B.soglia_dist = (int32_T)
            load_arduino_v_15_B.Ato_selector;
        } else {
          load_arduino_v_15_B.soglia_dist = MIN_int32_T;
        }
      } else {
        load_arduino_v_15_B.soglia_dist = MAX_int32_T;
      }

      if (load_arduino_v_15_B.soglia_dist == load_arduino_v_15_B.pipk) {
        load_arduino_v_15_B.Ato_selector = rt_roundd_snf
          (load_arduino_v_15_B.lat_end[1]);
        if (load_arduino_v_15_B.Ato_selector < 256.0) {
          if (load_arduino_v_15_B.Ato_selector >= 0.0) {
            status = (uint8_T)load_arduino_v_15_B.Ato_selector;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_B.qY + 7U);
        if (load_arduino_v_15_B.qY + 7U > 255U) {
          load_arduino_v_15_B.pipk = 255;
        }

        load_arduino_v_15_B.Ato_selector = rt_roundd_snf
          (load_arduino_v_15_B.lat_end[1] + (real_T)load_arduino_v_15_B.pipk);
        if (load_arduino_v_15_B.Ato_selector < 256.0) {
          if (load_arduino_v_15_B.Ato_selector >= 0.0) {
            find_comma = (uint8_T)load_arduino_v_15_B.Ato_selector;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          load_arduino_v_15_B.ATO = 0;
          load_arduino_v_15_B.pipk = 0;
        } else {
          load_arduino_v_15_B.ATO = status - 1;
          load_arduino_v_15_B.pipk = find_comma;
        }

        load_arduino_v_15_B.caso = load_arduino_v_15_B.pipk -
          load_arduino_v_15_B.ATO;
        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
             load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.pipk] =
            load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.ATO +
            load_arduino_v_15_B.pipk];
        }

        load_arduino_v_15_B.ATO = 2;
        for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 100;
             load_arduino_v_15_B.i++) {
          load_arduino_v_15_B.messaggio_2[load_arduino_v_15_B.i] =
            load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i];
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.i] = 0U;
        }

        load_arduino_v_15_DW.counter_a = 0U;
        load_arduino_v_15_DW.mess_len = 0.0;
      } else {
        load_arduino_v_15_B.Ato_selector = rt_roundd_snf
          (load_arduino_v_15_B.lat_end[1]);
        if (load_arduino_v_15_B.Ato_selector < 2.147483648E+9) {
          if (load_arduino_v_15_B.Ato_selector >= -2.147483648E+9) {
            load_arduino_v_15_B.pipk = (int32_T)load_arduino_v_15_B.Ato_selector;
          } else {
            load_arduino_v_15_B.pipk = MIN_int32_T;
          }
        } else {
          load_arduino_v_15_B.pipk = MAX_int32_T;
        }

        if (load_arduino_v_15_B.pipk > load_arduino_v_15_B.SFunctionBuilder_o2)
        {
          load_arduino_v_15_B.pipk = -1;
          load_arduino_v_15_B.caso = 0;
        } else {
          load_arduino_v_15_B.pipk -= 2;
          load_arduino_v_15_B.caso = load_arduino_v_15_B.SFunctionBuilder_o2;
        }

        load_arduino_v_15_DW.mess_len = (int8_T)((load_arduino_v_15_B.caso -
          load_arduino_v_15_B.pipk) - 1);
        if (load_arduino_v_15_B.Ato_selector < 2.147483648E+9) {
          if (load_arduino_v_15_B.Ato_selector >= -2.147483648E+9) {
            load_arduino_v_15_B.pipk = (int32_T)load_arduino_v_15_B.Ato_selector;
          } else {
            load_arduino_v_15_B.pipk = MIN_int32_T;
          }
        } else {
          load_arduino_v_15_B.pipk = MAX_int32_T;
        }

        if (load_arduino_v_15_B.pipk > load_arduino_v_15_B.SFunctionBuilder_o2)
        {
          load_arduino_v_15_B.i = 0;
          load_arduino_v_15_B.pipk = 0;
        } else {
          load_arduino_v_15_B.i = load_arduino_v_15_B.pipk - 1;
          load_arduino_v_15_B.pipk = load_arduino_v_15_B.SFunctionBuilder_o2;
        }

        load_arduino_v_15_B.caso = load_arduino_v_15_B.pipk -
          load_arduino_v_15_B.i;
        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
             load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_DW.message_i[load_arduino_v_15_B.pipk] =
            load_arduino_v_15_B.SFunctionBuilder_o1_h[load_arduino_v_15_B.i +
            load_arduino_v_15_B.pipk];
        }

        load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_B.qY + 8U);
        if (load_arduino_v_15_B.qY + 8U > 255U) {
          load_arduino_v_15_B.pipk = 255;
        }

        load_arduino_v_15_B.Ato_selector = rt_roundd_snf((real_T)
          load_arduino_v_15_B.pipk - load_arduino_v_15_DW.mess_len);
        if (load_arduino_v_15_B.Ato_selector < 256.0) {
          if (load_arduino_v_15_B.Ato_selector >= 0.0) {
            load_arduino_v_15_DW.counter_a = (uint8_T)
              load_arduino_v_15_B.Ato_selector;
          } else {
            load_arduino_v_15_DW.counter_a = 0U;
          }
        } else {
          load_arduino_v_15_DW.counter_a = MAX_uint8_T;
        }

        load_arduino_v_15_DW.Interr_parz = true;
      }
    } else {
      load_arduino_v_15_DW.Interr_parz = false;
      memset(&load_arduino_v_15_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      load_arduino_v_15_DW.counter_a = 0U;
      load_arduino_v_15_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&load_arduino_v_15_B.buffer[0], 0, 300U * sizeof(uint8_T));
  status = 0U;
  for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
       load_arduino_v_15_B.pipk++) {
    load_arduino_v_15_B.buffer[3 * load_arduino_v_15_B.pipk] = 0U;
  }

  for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
       load_arduino_v_15_B.pipk++) {
    for (load_arduino_v_15_B.caso = 0; load_arduino_v_15_B.caso < 2;
         load_arduino_v_15_B.caso++) {
      load_arduino_v_15_B.i = 3 * load_arduino_v_15_B.pipk +
        load_arduino_v_15_B.caso;
      load_arduino_v_15_B.buffer[load_arduino_v_15_B.i + 1] =
        load_arduino_v_15_DW.Memory4_PreviousInput_c[load_arduino_v_15_B.i];
    }
  }

  load_arduino_v_15_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (load_arduino_v_15_B.i >= 1)) {
    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.x[load_arduino_v_15_B.pipk] =
        (load_arduino_v_15_B.buffer[(3 * load_arduino_v_15_B.pipk +
          load_arduino_v_15_B.i) - 1] == 0);
    }

    Ap_sel = true;
    load_arduino_v_15_B.pipk = 0;
    exitg2 = false;
    while ((!exitg2) && (load_arduino_v_15_B.pipk < 100)) {
      if (!load_arduino_v_15_B.x[load_arduino_v_15_B.pipk]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        load_arduino_v_15_B.pipk++;
      }
    }

    if (Ap_sel) {
      status = (uint8_T)load_arduino_v_15_B.i;
      exitg1 = true;
    } else {
      load_arduino_v_15_B.i--;
    }
  }

  if (load_arduino_v_15_B.ATO == 1) {
    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.buffer[(status + 3 * load_arduino_v_15_B.pipk) - 1] =
        load_arduino_v_15_B.messaggio_i[load_arduino_v_15_B.pipk];
    }
  } else if (load_arduino_v_15_B.ATO == 2) {
    load_arduino_v_15_B.qY = status - /*MW:OvSatOk*/ 1U;
    if (status - 1U > status) {
      load_arduino_v_15_B.qY = 0U;
    }

    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.buffer[(status + 3 * load_arduino_v_15_B.pipk) - 1] =
        load_arduino_v_15_B.messaggio_i[load_arduino_v_15_B.pipk];
      load_arduino_v_15_B.buffer[((int32_T)load_arduino_v_15_B.qY + 3 *
        load_arduino_v_15_B.pipk) - 1] =
        load_arduino_v_15_B.messaggio_2[load_arduino_v_15_B.pipk];
    }
  } else {
    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.buffer[(status + 3 * load_arduino_v_15_B.pipk) - 1] =
        0U;
    }
  }

  for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
       load_arduino_v_15_B.pipk++) {
    load_arduino_v_15_B.mess_out[load_arduino_v_15_B.pipk] =
      load_arduino_v_15_DW.Memory4_PreviousInput_c[3 * load_arduino_v_15_B.pipk
      + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  load_arduino_v_15_B.Add = load_arduino_v_15_DW.Memory4_PreviousInput_c[5] +
    load_arduino_v_15_P.Constant_Value_gw;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (load_arduino_v_15_B.mess_out[2] !=
      load_arduino_v_15_DW.Memory5_PreviousInput_l[2]) {
    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 100;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.x[load_arduino_v_15_B.pipk] =
        (load_arduino_v_15_B.mess_out[load_arduino_v_15_B.pipk] != 0);
    }

    Ap_sel = true;
    load_arduino_v_15_B.pipk = 0;
    exitg1 = false;
    while ((!exitg1) && (load_arduino_v_15_B.pipk < 100)) {
      if (!load_arduino_v_15_B.x[load_arduino_v_15_B.pipk]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        load_arduino_v_15_B.pipk++;
      }
    }

    if (!Ap_sel) {
      if (load_arduino_v_15_DW.counter > 100) {
        load_arduino_v_15_DW.counter = 0U;
      }

      load_arduino_v_15_B.qY = load_arduino_v_15_DW.counter + 1U;
      if (load_arduino_v_15_DW.counter + 1U > 65535U) {
        load_arduino_v_15_B.qY = 65535U;
      }

      load_arduino_v_15_DW.counter = (uint16_T)load_arduino_v_15_B.qY;
    }
  }

  load_arduino_v_15_B.new_mex = load_arduino_v_15_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  load_arduino_v_15_B.Memory1[0] = load_arduino_v_15_DW.Memory1_PreviousInput_d
    [0];
  load_arduino_v_15_B.Memory1[1] = load_arduino_v_15_DW.Memory1_PreviousInput_d
    [1];

  /* Memory: '<Root>/Memory' */
  load_arduino_v_15_B.Memory_k[0] =
    load_arduino_v_15_DW.Memory_PreviousInput_h5[0];
  load_arduino_v_15_B.Memory_k[1] =
    load_arduino_v_15_DW.Memory_PreviousInput_h5[1];
  load_arduino_v_15_B.Memory_k[2] =
    load_arduino_v_15_DW.Memory_PreviousInput_h5[2];
  load_arduino_v_15_B.Memory_k[3] =
    load_arduino_v_15_DW.Memory_PreviousInput_h5[3];

  /* Memory: '<S1>/Memory3' */
  load_arduino_v_15_B.Memory3 = load_arduino_v_15_DW.Memory3_PreviousInput_o;
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 8;
       load_arduino_v_15_B.i++) {
    /* Memory: '<S1>/Memory' */
    load_arduino_v_15_B.Memory[load_arduino_v_15_B.i] =
      load_arduino_v_15_DW.Memory_PreviousInput_i[load_arduino_v_15_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&load_arduino_v_15_B.mess_out[0], &load_arduino_v_15_B.Add,
     &load_arduino_v_15_B.new_mex, &load_arduino_v_15_P.SIUAVuint8_Value,
     &load_arduino_v_15_B.Memory[0], &load_arduino_v_15_B.Memory1[0],
     &load_arduino_v_15_B.Memory_k[0], &load_arduino_v_15_B.Memory3,
     &load_arduino_v_15_B.SFunction_o1[0], &load_arduino_v_15_B.SFunction_o2,
     &load_arduino_v_15_B.SFunction_o3_j, &load_arduino_v_15_B.SFunction_o4_n[0],
     &load_arduino_v_15_B.SFunction_o5[0], &load_arduino_v_15_B.SFunction_o6,
     &load_arduino_v_15_B.SFunction_o7[0], &load_arduino_v_15_B.SFunction_o8,
     &load_arduino_v_15_B.SFunction_o9[0], &load_arduino_v_15_B.SFunction_o10[0],
     &load_arduino_v_15_B.SFunction_o11[0], &load_arduino_v_15_B.SFunction_o12,
     &load_arduino_v_15_B.SFunction_o13, &load_arduino_v_15_B.SFunction_o14,
     &load_arduino_v_15_B.SFunction_o15, &load_arduino_v_15_B.SFunction_o16,
     &load_arduino_v_15_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 6;
       load_arduino_v_15_B.i++) {
    load_arduino_v_15_B.WP_info_in[load_arduino_v_15_B.i] =
      load_arduino_v_15_B.SFunction_o9[load_arduino_v_15_B.i];
  }

  if ((!load_arduino_v_15_DW.WP_dbP_not_empty) ||
      ((load_arduino_v_15_B.SFunction_o7[0] == 3) &&
       (load_arduino_v_15_B.SFunction_o7[1] == 250))) {
    memset(&load_arduino_v_15_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    load_arduino_v_15_DW.WP_dbP_not_empty = true;
    memset(&load_arduino_v_15_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!load_arduino_v_15_DW.WP_dbP_AL_not_empty) ||
      ((load_arduino_v_15_B.SFunction_o7[0] == 3) &&
       (load_arduino_v_15_B.SFunction_o7[1] == 250))) {
    memset(&load_arduino_v_15_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    load_arduino_v_15_DW.WP_dbP_AL_not_empty = true;
  }

  load_arduino_v_15_B.GC_info[0] = load_arduino_v_15_B.SFunction_o7[0];
  load_arduino_v_15_B.GC_info[1] = load_arduino_v_15_B.SFunction_o7[1];
  load_arduino_v_15_B.GC_info[2] = load_arduino_v_15_B.SFunction_o11[0];
  if (load_arduino_v_15_B.GC_info[0] == 1) {
    if ((load_arduino_v_15_B.GC_info[1] > 0) && (load_arduino_v_15_B.GC_info[1] <=
         7)) {
      if ((real32_T)fabs(load_arduino_v_15_B.SFunction_o8) > 0.0F) {
        load_arduino_v_15_DW.riferimenti[load_arduino_v_15_B.GC_info[1] - 1] =
          1.0F;
      } else {
        if (load_arduino_v_15_B.SFunction_o8 == 0.0F) {
          load_arduino_v_15_DW.riferimenti[load_arduino_v_15_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((load_arduino_v_15_B.GC_info[1] > 7) && (load_arduino_v_15_B.GC_info[1]
           < 12)) {
        load_arduino_v_15_DW.riferimenti[load_arduino_v_15_B.GC_info[1] - 1] =
          load_arduino_v_15_B.SFunction_o8;
      }
    }
  }

  if (load_arduino_v_15_B.SFunction_o12 == 13) {
    load_arduino_v_15_DW.riferimenti[load_arduino_v_15_B.SFunction_o12 - 1] =
      load_arduino_v_15_B.SFunction_o13;
  }

  memcpy(&load_arduino_v_15_B.Val_out_MAV[0], &load_arduino_v_15_DW.riferimenti
         [0], sizeof(real32_T) << 4U);
  if ((load_arduino_v_15_B.GC_info[0] == 3) && (load_arduino_v_15_B.GC_info[1] ==
       200)) {
    if (load_arduino_v_15_B.SFunction_o9[0] > 6) {
      load_arduino_v_15_B.WP_info_in[0] = 6U;
    }

    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 6;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_DW.WP_dbI[load_arduino_v_15_B.pipk] =
        load_arduino_v_15_B.WP_info_in[0];
    }
  }

  if ((load_arduino_v_15_B.GC_info[0] == 3) && (load_arduino_v_15_B.GC_info[1] <
       200)) {
    if (load_arduino_v_15_B.SFunction_o10[1] == 0.0F) {
      load_arduino_v_15_B.qY = load_arduino_v_15_B.SFunction_o9[1] + 1U;
      if (load_arduino_v_15_B.SFunction_o9[1] + 1U > 65535U) {
        load_arduino_v_15_B.qY = 65535U;
      }

      for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 7;
           load_arduino_v_15_B.pipk++) {
        load_arduino_v_15_DW.WP_dbP[((int32_T)load_arduino_v_15_B.qY + 6 *
          load_arduino_v_15_B.pipk) - 1] =
          load_arduino_v_15_B.SFunction_o10[load_arduino_v_15_B.pipk];
      }

      load_arduino_v_15_B.qY = load_arduino_v_15_B.SFunction_o9[1] + 1U;
      if (load_arduino_v_15_B.SFunction_o9[1] + 1U > 65535U) {
        load_arduino_v_15_B.qY = 65535U;
      }

      for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 6;
           load_arduino_v_15_B.pipk++) {
        load_arduino_v_15_DW.WP_dbI[((int32_T)load_arduino_v_15_B.qY + 6 *
          (load_arduino_v_15_B.pipk + 1)) - 1] =
          load_arduino_v_15_B.WP_info_in[load_arduino_v_15_B.pipk + 1];
      }
    } else {
      load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_B.SFunction_o10[0]
        + 1.0F);
      for (load_arduino_v_15_B.soglia_dist = 0; load_arduino_v_15_B.soglia_dist <
           7; load_arduino_v_15_B.soglia_dist++) {
        load_arduino_v_15_DW.WP_dbP_AL[(load_arduino_v_15_B.pipk + 6 *
          load_arduino_v_15_B.soglia_dist) - 1] =
          load_arduino_v_15_B.SFunction_o10[load_arduino_v_15_B.soglia_dist];
      }

      load_arduino_v_15_B.qY = load_arduino_v_15_B.SFunction_o9[1] + 1U;
      if (load_arduino_v_15_B.SFunction_o9[1] + 1U > 65535U) {
        load_arduino_v_15_B.qY = 65535U;
      }

      for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 6;
           load_arduino_v_15_B.pipk++) {
        load_arduino_v_15_DW.WP_dbI[((int32_T)load_arduino_v_15_B.qY + 6 *
          (load_arduino_v_15_B.pipk + 1)) - 1] =
          load_arduino_v_15_B.WP_info_in[load_arduino_v_15_B.pipk + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  load_arduino_v_15_DW.Memory3_PreviousInput_o = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((load_arduino_v_15_B.SFunction_o6 == 0) &&
      (load_arduino_v_15_B.SFunction_o3_j == 0)) {
    load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 0U;
    load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_15_DW.Memory3_PreviousInput_o = 0U;
  } else if ((load_arduino_v_15_B.SFunction_o6 == 0) &&
             (load_arduino_v_15_B.SFunction_o3_j == 3)) {
    load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 0U;
    load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_15_DW.Memory3_PreviousInput_o = 0U;
    load_arduino_v_15_DW.test1 = 0.0;
  } else if ((load_arduino_v_15_B.SFunction_o6 == 0) &&
             (load_arduino_v_15_B.SFunction_o3_j == 2)) {
    load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 0U;
    load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_15_DW.Memory3_PreviousInput_o = 0U;
    load_arduino_v_15_DW.test1 = 0.0;
  } else if ((load_arduino_v_15_B.SFunction_o6 == 0) &&
             (load_arduino_v_15_B.SFunction_o3_j == 1)) {
    load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 0U;
    load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    load_arduino_v_15_DW.Memory3_PreviousInput_o = 0U;
    load_arduino_v_15_DW.test1 = 1.0;
  } else {
    switch (load_arduino_v_15_B.SFunction_o6) {
     case 192:
      load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 192U;
      load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      load_arduino_v_15_DW.Memory3_PreviousInput_o = 192U;
      break;

     case 208:
      load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 208U;
      load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      load_arduino_v_15_DW.Memory3_PreviousInput_o = 208U;
      break;

     default:
      if ((load_arduino_v_15_B.SFunction_o6 == 220) &&
          (load_arduino_v_15_B.SFunction_o3_j != 5)) {
        if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 0) &&
            (load_arduino_v_15_DW.Memory2_PreviousInput_a[1] == 0) &&
            ((load_arduino_v_15_DW.Memory2_PreviousInput_a[2] == 1) ||
             (load_arduino_v_15_DW.Memory2_PreviousInput_a[3] == 1) ||
             (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] == 1) ||
             (load_arduino_v_15_DW.Memory2_PreviousInput_a[5] == 1) ||
             (load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 1) ||
             (load_arduino_v_15_DW.Memory2_PreviousInput_a[7] == 1))) {
          load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 220U;
          load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          load_arduino_v_15_DW.Memory3_PreviousInput_o = 220U;
        } else if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 0) &&
                   (load_arduino_v_15_DW.Memory2_PreviousInput_a[1] == 1) &&
                   ((load_arduino_v_15_DW.Memory2_PreviousInput_a[2] == 1) ||
                    (load_arduino_v_15_DW.Memory2_PreviousInput_a[3] == 1) ||
                    (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] == 1) ||
                    (load_arduino_v_15_DW.Memory2_PreviousInput_a[5] == 1) ||
                    (load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 1) ||
                    (load_arduino_v_15_DW.Memory2_PreviousInput_a[7] == 1))) {
          load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 220U;
          load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          load_arduino_v_15_DW.Memory3_PreviousInput_o = 220U;
        } else {
          load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 208U;
          load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          load_arduino_v_15_DW.Memory3_PreviousInput_o = 208U;
        }
      } else if (load_arduino_v_15_B.SFunction_o3_j == 5) {
        load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 220U;
        load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        load_arduino_v_15_DW.Memory1_PreviousInput_d[0] = 192U;
        load_arduino_v_15_DW.Memory1_PreviousInput_d[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  load_arduino_v_15_B.qY = 100U * load_arduino_v_15_B.SFunction_o11[5];
  if (load_arduino_v_15_B.qY > 65535U) {
    load_arduino_v_15_B.qY = 65535U;
  }

  if (load_arduino_v_15_B.SFunction_o11[4] == 0) {
    if ((uint16_T)load_arduino_v_15_B.qY == 0) {
      load_arduino_v_15_B.z = 0U;
    } else {
      load_arduino_v_15_B.z = MAX_uint16_T;
    }
  } else {
    load_arduino_v_15_B.z = (uint16_T)(load_arduino_v_15_B.SFunction_o11[4] ==
      0U ? MAX_uint32_T : (uint32_T)(uint16_T)load_arduino_v_15_B.qY /
      load_arduino_v_15_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)load_arduino_v_15_B.qY - (uint16_T)
                   ((uint32_T)load_arduino_v_15_B.z *
                    load_arduino_v_15_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)load_arduino_v_15_B.SFunction_o11[4]
          >> 1) + (load_arduino_v_15_B.SFunction_o11[4] & 1))) {
      load_arduino_v_15_B.z++;
    }
  }

  load_arduino_v_15_DW.Memory2_PreviousInput_a[0] = (uint8_T)AP_mode_idx_0;
  load_arduino_v_15_DW.Memory2_PreviousInput_a[1] = (uint8_T)AP_mode_idx_1;
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 7;
       load_arduino_v_15_B.i++) {
    load_arduino_v_15_B.f = rt_roundf_snf
      (load_arduino_v_15_DW.riferimenti[load_arduino_v_15_B.i]);
    if (load_arduino_v_15_B.f < 256.0F) {
      if (load_arduino_v_15_B.f >= 0.0F) {
        load_arduino_v_15_DW.Memory2_PreviousInput_a[load_arduino_v_15_B.i + 2] =
          (uint8_T)load_arduino_v_15_B.f;
      } else {
        load_arduino_v_15_DW.Memory2_PreviousInput_a[load_arduino_v_15_B.i + 2] =
          0U;
      }
    } else {
      load_arduino_v_15_DW.Memory2_PreviousInput_a[load_arduino_v_15_B.i + 2] =
        MAX_uint8_T;
    }
  }

  /* Outputs for Enabled SubSystem: '<S586>/Subsystem1' incorporates:
   *  EnablePort: '<S588>/Enable'
   */
  if (load_arduino_v_15_B.SFunction_o14 > 0) {
    /* Inport: '<S588>/T' */
    load_arduino_v_15_B.T = load_arduino_v_15_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S586>/Subsystem1' */

  /* Switch: '<S586>/Switch1' incorporates:
   *  Constant: '<S586>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  RelationalOperator: '<S586>/NotEqual'
   *  Switch: '<S586>/Switch'
   */
  if (load_arduino_v_15_P.Constant_Value_hx != load_arduino_v_15_DW.riferimenti
      [12]) {
    /* Switch: '<S586>/Switch1' */
    load_arduino_v_15_B.Switch1_g = load_arduino_v_15_DW.riferimenti[12];
  } else if (load_arduino_v_15_B.T > load_arduino_v_15_P.Switch_Threshold_p) {
    /* Switch: '<S586>/Switch' incorporates:
     *  Switch: '<S586>/Switch1'
     */
    load_arduino_v_15_B.Switch1_g = load_arduino_v_15_B.T;
  } else {
    /* Switch: '<S586>/Switch1' */
    load_arduino_v_15_B.Switch1_g = load_arduino_v_15_DW.riferimenti[12];
  }

  /* End of Switch: '<S586>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem1' incorporates:
   *  EnablePort: '<S455>/Enable'
   */
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 42;
       load_arduino_v_15_B.i++) {
    /* DataTypeConversion: '<S41>/Data Type Conversion5' incorporates:
     *  DataTypeConversion: '<S455>/Data Type Conversion4'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    load_arduino_v_15_B.WP_db_param[load_arduino_v_15_B.i] =
      load_arduino_v_15_DW.WP_dbP_AL[load_arduino_v_15_B.i];
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem1' */

  /* MATLAB Function: '<S41>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S41>/Data Type Conversion5'
   */
  load_arduino_v_15_B.Lat_Home = load_arduino_v_15_B.WP_db_param[24];
  load_arduino_v_15_B.Long_Home = load_arduino_v_15_B.WP_db_param[30];
  load_arduino_v_15_B.h_Home = load_arduino_v_15_B.WP_db_param[36];

  /* MATLABSystem: '<S571>/Serial Receive' */
  if (load_arduino_v_15_DW.obj_m.Protocol !=
      load_arduino_v_15_P.SerialReceive_Protocol) {
    load_arduino_v_15_DW.obj_m.Protocol =
      load_arduino_v_15_P.SerialReceive_Protocol;
  }

  MW_Serial_read(1, load_arduino_v_15_DW.obj_m.DataSizeInBytes,
                 &load_arduino_v_15_B.b_dataOut_p[0], &status);

  /* Outputs for Enabled SubSystem: '<S571>/Subsystem1' incorporates:
   *  EnablePort: '<S575>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S575>/MATLAB Function' */
    for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 31;
         load_arduino_v_15_B.i++) {
      load_arduino_v_15_B.messaggio[load_arduino_v_15_B.i] = 0U;
    }

    guard1 = false;
    if (!load_arduino_v_15_DW.start_found_c) {
      load_arduino_v_15_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_15_B.i - 1 < 30)) {
        if ((load_arduino_v_15_B.b_dataOut_p[(uint8_T)load_arduino_v_15_B.i - 1]
             == 255) && (load_arduino_v_15_B.b_dataOut_p[(uint8_T)
                         load_arduino_v_15_B.i] == 254)) {
          load_arduino_v_15_B.caso = 31 - (uint8_T)load_arduino_v_15_B.i;
          for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
               load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
            load_arduino_v_15_DW.message_k[load_arduino_v_15_B.pipk] =
              load_arduino_v_15_B.b_dataOut_p[((uint8_T)load_arduino_v_15_B.i +
              load_arduino_v_15_B.pipk) - 1];
          }

          load_arduino_v_15_DW.counter_n = (uint8_T)(32 - (uint8_T)
            load_arduino_v_15_B.i);
          load_arduino_v_15_DW.start_found_c = true;
          exitg1 = true;
        } else {
          load_arduino_v_15_B.i++;
        }
      }

      if (load_arduino_v_15_DW.counter_n == 31) {
        for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 31;
             load_arduino_v_15_B.i++) {
          load_arduino_v_15_B.messaggio[load_arduino_v_15_B.i] =
            load_arduino_v_15_DW.message_k[load_arduino_v_15_B.i];
          load_arduino_v_15_DW.message_k[load_arduino_v_15_B.i] = 0U;
        }

        load_arduino_v_15_DW.start_found_c = false;
        load_arduino_v_15_DW.counter_n = 0U;
        guard1 = true;
      }
    } else {
      load_arduino_v_15_B.qY = 31U - /*MW:OvSatOk*/
        load_arduino_v_15_DW.counter_n;
      if (31U - load_arduino_v_15_DW.counter_n > 31U) {
        load_arduino_v_15_B.qY = 0U;
      }

      load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_DW.counter_n + 1U);
      if (load_arduino_v_15_DW.counter_n + 1U > 255U) {
        load_arduino_v_15_B.pipk = 255;
      }

      if ((uint8_T)load_arduino_v_15_B.pipk > 31) {
        load_arduino_v_15_B.soglia_dist = 1;
      } else {
        load_arduino_v_15_B.soglia_dist = (uint8_T)load_arduino_v_15_B.pipk;
      }

      if (1 > (uint8_T)load_arduino_v_15_B.qY) {
        load_arduino_v_15_B.caso = -1;
      } else {
        load_arduino_v_15_B.caso = (uint8_T)load_arduino_v_15_B.qY - 1;
      }

      for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
           load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
        load_arduino_v_15_DW.message_k[(load_arduino_v_15_B.soglia_dist +
          load_arduino_v_15_B.pipk) - 1] =
          load_arduino_v_15_B.b_dataOut_p[load_arduino_v_15_B.pipk];
      }

      load_arduino_v_15_B.qY = 31U - /*MW:OvSatOk*/
        load_arduino_v_15_DW.counter_n;
      if (31U - load_arduino_v_15_DW.counter_n > 31U) {
        load_arduino_v_15_B.qY = 0U;
      }

      load_arduino_v_15_DW.counter_n = (uint8_T)load_arduino_v_15_B.qY;
      for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 31;
           load_arduino_v_15_B.i++) {
        load_arduino_v_15_B.messaggio[load_arduino_v_15_B.i] =
          load_arduino_v_15_DW.message_k[load_arduino_v_15_B.i];
        load_arduino_v_15_DW.message_k[load_arduino_v_15_B.i] = 0U;
      }

      status = load_arduino_v_15_DW.counter_n;
      do {
        exitg3 = 0;
        if (status < 31) {
          if ((load_arduino_v_15_B.b_dataOut_p[status - 1] == 255) &&
              (load_arduino_v_15_B.b_dataOut_p[status] == 254)) {
            load_arduino_v_15_B.caso = 31 - status;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
                 load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_DW.message_k[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.b_dataOut_p[(status +
                load_arduino_v_15_B.pipk) - 1];
            }

            load_arduino_v_15_B.qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              load_arduino_v_15_B.qY = 0U;
            }

            load_arduino_v_15_DW.counter_n = (uint8_T)(31 - (int32_T)
              load_arduino_v_15_B.qY);
            load_arduino_v_15_DW.start_found_c = true;
            guard1 = true;
            exitg3 = 1;
          } else {
            load_arduino_v_15_DW.start_found_c = false;
            load_arduino_v_15_DW.counter_n = 0U;
            status++;
          }
        } else {
          guard1 = true;
          exitg3 = 1;
        }
      } while (exitg3 == 0);
    }

    if (guard1) {
      /* Outputs for Enabled SubSystem: '<S575>/Subsystem2' incorporates:
       *  EnablePort: '<S577>/Enable'
       */
      /* S-Function (byte2any_svd): '<S577>/Byte Unpack' */

      /* Unpack: <S577>/Byte Unpack */
      {
        uint32_T MW_inputPortOffset = 0;
        uint32_T MW_outputPortWidth = 0;
        uint32_T MW_remainder2 = 0;

        /* Packed input data type - uint8_T */
        /* Unpacking the values to output 1 */
        /* Output data type - uint8_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint8_T);
          memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack_o1[0], (uint8_T*)
                 &load_arduino_v_15_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack_o2[0], (uint8_T*)
                 &load_arduino_v_15_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack_o3[0], (uint8_T*)
                 &load_arduino_v_15_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack_o4[0], (uint8_T*)
                 &load_arduino_v_15_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&load_arduino_v_15_B.ByteUnpack_o5, (uint8_T*)
                 &load_arduino_v_15_B.messaggio[0] + MW_inputPortOffset,
                 MW_outputPortWidth);
        }
      }

      /* End of Outputs for SubSystem: '<S575>/Subsystem2' */
    }

    /* End of MATLAB Function: '<S575>/MATLAB Function' */
  }

  /* End of MATLABSystem: '<S571>/Serial Receive' */
  /* End of Outputs for SubSystem: '<S571>/Subsystem1' */

  /* Gain: '<S571>/Gain1' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion2'
   */
  load_arduino_v_15_B.num_254 = load_arduino_v_15_P.Gain1_Gain_p * (real_T)
    load_arduino_v_15_B.ByteUnpack_o3[0];
  load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_P.Gain1_Gain_p *
    (real_T)load_arduino_v_15_B.ByteUnpack_o3[1];

  /* Gain: '<S571>/Gain4' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion3'
   */
  load_arduino_v_15_B.rtb_Gain4_idx_0 = load_arduino_v_15_P.Gain4_Gain * (real_T)
    load_arduino_v_15_B.ByteUnpack_o4[0];
  load_arduino_v_15_B.rtb_Gain4_idx_1 = load_arduino_v_15_P.Gain4_Gain * (real_T)
    load_arduino_v_15_B.ByteUnpack_o4[1];

  /* Outputs for Resettable SubSystem: '<S423>/Resettable Subsystem' */
  load_arduino_v_15_B.SumI1_ak = load_ar_ResettableSubsystem
    (load_arduino_v_15_B.SFunction_o4_n[0],
     &load_arduino_v_15_DW.ResettableSubsystem_o,
     &load_arduino_v_15_P.ResettableSubsystem_o,
     &load_arduino_v_15_PrevZCX.ResettableSubsystem_o);

  /* End of Outputs for SubSystem: '<S423>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S423>/Enabled Subsystem' */
  load_ardui_EnabledSubsystem(load_arduino_v_15_B.SFunction_o4_n[0],
    load_arduino_v_15_B.SumI1_ak, &load_arduino_v_15_B.Switch_l,
    &load_arduino_v_15_P.EnabledSubsystem_j);

  /* End of Outputs for SubSystem: '<S423>/Enabled Subsystem' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 9;
       load_arduino_v_15_B.i++) {
    load_arduino_v_15_B.DataTypeConversion1_b[load_arduino_v_15_B.i] =
      load_arduino_v_15_B.ByteReversal1[load_arduino_v_15_B.i];
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* Gain: '<S565>/Gain1' */
  load_arduino_v_15_B.Gain1_b = load_arduino_v_15_P.Gain1_Gain_kg *
    load_arduino_v_15_B.DataTypeConversion1_b[6];

  /* MATLAB Function: '<S429>/MATLAB Function1' */
  guard1 = false;
  if (load_arduino_v_15_DW.Memory2_PreviousInput_a[1] == 1) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     */
    if (load_arduino_v_15_B.Switch_l != 0.0) {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.V_max * 1.4;
    } else {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.rtb_Gain1_idx_1;
    }

    /* End of Switch: '<S40>/Switch' */
    if (load_arduino_v_15_B.Ato_selector > load_arduino_v_15_P.safe_V) {
      load_arduino_v_15_DW.alarm = 1.0;
    } else if (fabs(load_arduino_v_15_P.Gain_Gain_mz *
                    load_arduino_v_15_B.Gain1_b) > load_arduino_v_15_P.safe_phi)
    {
      load_arduino_v_15_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 1) {
      load_arduino_v_15_DW.alarm = 0.0;
    }
  }

  /* Outputs for Resettable SubSystem: '<S446>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S449>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &load_arduino_v_15_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (load_arduino_v_15_DW.alarm)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S450>/Sum' incorporates:
     *  Memory: '<S450>/Memory'
     */
    load_arduino_v_15_DW.Memory_PreviousInput_h =
      load_arduino_v_15_P.Memory_InitialCondition;
  }

  /* Sum: '<S450>/Sum' incorporates:
   *  Constant: '<S450>/Constant4'
   *  Memory: '<S450>/Memory'
   */
  load_arduino_v_15_DW.Memory_PreviousInput_h += load_arduino_v_15_P.t_AP;

  /* End of Outputs for SubSystem: '<S446>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S446>/Enabled ' incorporates:
   *  EnablePort: '<S448>/Enable'
   */
  /* MATLAB Function: '<S429>/MATLAB Function1' */
  if (load_arduino_v_15_DW.alarm > 0.0) {
    load_arduino_v_15_DW.Enabled_MODE = true;

    /* Switch: '<S448>/Switch' */
    if (load_arduino_v_15_DW.Memory_PreviousInput_h >
        load_arduino_v_15_P.time_alarm_SAFE) {
      /* Switch: '<S448>/Switch' incorporates:
       *  Constant: '<S448>/Constant'
       */
      load_arduino_v_15_B.Switch_n = load_arduino_v_15_P.Constant_Value_h;
    } else {
      /* Switch: '<S448>/Switch' incorporates:
       *  Constant: '<S448>/Constant1'
       */
      load_arduino_v_15_B.Switch_n = load_arduino_v_15_P.Constant1_Value;
    }

    /* End of Switch: '<S448>/Switch' */
  } else {
    if (load_arduino_v_15_DW.Enabled_MODE) {
      /* Disable for Switch: '<S448>/Switch' incorporates:
       *  Outport: '<S448>/Alarm Safe'
       */
      load_arduino_v_15_B.Switch_n = load_arduino_v_15_P.AlarmSafe_Y0;
      load_arduino_v_15_DW.Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S446>/Enabled ' */

  /* S-Function (PWMinterrupt_goHome): '<S9>/S-Function Builder2' */
  PWMinterrupt_goHome_Outputs_wrapper(&load_arduino_v_15_B.SFunctionBuilder2);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  if (load_arduino_v_15_B.SFunctionBuilder2 >
      load_arduino_v_15_P.Switch_Threshold_m) {
    load_arduino_v_15_B.Go_Home = load_arduino_v_15_P.Constant_Value_bh;
  } else {
    load_arduino_v_15_B.Go_Home = load_arduino_v_15_P.Constant1_Value_j;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<S40>/ STATI' incorporates:
   *  Constant: '<S40>/Constant2'
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  if (load_arduino_v_15_DW.is_active_c26_load_arduino_v_15 == 0U) {
    load_arduino_v_15_DW.is_active_c26_load_arduino_v_15 = 1U;
    load_arduino_v_15_DW.is_c26_load_arduino_v_15 = load_arduino_v_15_IN_MANUALE;
  } else {
    switch (load_arduino_v_15_DW.is_c26_load_arduino_v_15) {
     case load_arduino_v_15_IN_AUTOMATICA:
      if (load_arduino_v_15_P.Constant2_Value_k == 1.0) {
        load_arduino_v_15_DW.is_AUTOMATICA = 0;
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_ardui_IN_Intervento_Pilota;
      } else if (load_arduino_v_15_B.Switch_n == 1.0) {
        load_arduino_v_15_DW.is_AUTOMATICA = 0;
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_Safe;
      } else if (load_arduino_v_15_B.Go_Home == 1.0) {
        load_arduino_v_15_DW.is_AUTOMATICA = 0;
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_Go_Home;
      } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[1] == 0) {
        load_arduino_v_15_DW.is_AUTOMATICA = 0;
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_Stand_By;
      } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 1) {
        load_arduino_v_15_DW.is_AUTOMATICA = 0;
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_MANUALE;
      } else {
        switch (load_arduino_v_15_DW.is_AUTOMATICA) {
         case load__IN_ATTERRAGGIO_AUTOMATICO:
          if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[8] == 0) &&
              (load_arduino_v_15_B.ByteUnpack_o2[2] > 20.0F) &&
              (load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 1)) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_WAYPOINT;
          } else if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[8] == 0) &&
                     (load_arduino_v_15_B.ByteUnpack_o2[2] > 20.0F)) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_VETTORIALE;
          } else if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[7] == 1) &&
                     (load_arduino_v_15_DW.Memory2_PreviousInput_a[8] == 0) &&
                     (load_arduino_v_15_B.ByteUnpack_o2[2] < 1.0F) &&
                     (load_arduino_v_15_B.rtb_Gain4_idx_0 < 1.0)) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_ardu_IN_DECOLLO_AUTOMATICO;
          } else {
            load_arduino_v_15_B.modo = 4.0;
            load_arduino_v_15_B.switch_manetta = 1.0;
            load_arduino_v_15_B.switch_equilibratore = 1.0;
            load_arduino_v_15_B.switch_alettoni = 1.0;
            load_arduino_v_15_B.switch_timone = 1.0;
          }
          break;

         case load_ardu_IN_DECOLLO_AUTOMATICO:
          if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[7] == 0) &&
              (load_arduino_v_15_B.rtb_Gain1_idx_1 >= 1.0) &&
              ((load_arduino_v_15_DW.Memory2_PreviousInput_a[3] == 1) ||
               (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] == 1) ||
               (load_arduino_v_15_DW.Memory2_PreviousInput_a[2] == 1))) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_VETTORIALE;
          } else if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 1) &&
                     (load_arduino_v_15_B.ByteUnpack_o2[2] > 30.0F)) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_WAYPOINT;
          } else {
            load_arduino_v_15_B.modo = 3.0;
            load_arduino_v_15_B.switch_manetta = 1.0;
            load_arduino_v_15_B.switch_equilibratore = 1.0;
            load_arduino_v_15_B.switch_alettoni = 1.0;
            load_arduino_v_15_B.switch_timone = 1.0;
          }
          break;

         case load_arduino_v_15_IN_TEST:
          if (load_arduino_v_15_DW.test1 == 0.0) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_VETTORIALE;
          } else {
            load_arduino_v_15_B.switch_manetta = 0.0;
            load_arduino_v_15_B.switch_equilibratore = 0.0;
            load_arduino_v_15_B.switch_alettoni = 0.0;
            load_arduino_v_15_B.switch_timone = 0.0;
          }
          break;

         case load_arduino_v_15_IN_VETTORIALE:
          if (load_arduino_v_15_DW.test1 == 1.0) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_TEST;
          } else if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[7] == 1) &&
                     (load_arduino_v_15_B.rtb_Gain4_idx_0 < 3.0)) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_ardu_IN_DECOLLO_AUTOMATICO;
          } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[8] == 1) {
            load_arduino_v_15_DW.is_AUTOMATICA = load__IN_ATTERRAGGIO_AUTOMATICO;
          } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 1) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_WAYPOINT;
          } else {
            load_arduino_v_15_B.modo = 2.0;
            load_arduino_v_15_B.switch_manetta = 1.0;
            load_arduino_v_15_B.switch_equilibratore = 1.0;
            load_arduino_v_15_B.switch_alettoni = 1.0;
            load_arduino_v_15_B.switch_timone = 1.0;
          }
          break;

         default:
          /* case IN_WAYPOINT: */
          if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 0) &&
              ((load_arduino_v_15_DW.Memory2_PreviousInput_a[3] == 1) ||
               (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] == 1) ||
               (load_arduino_v_15_DW.Memory2_PreviousInput_a[2] == 1) ||
               (load_arduino_v_15_DW.Memory2_PreviousInput_a[7] == 1))) {
            load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_VETTORIALE;
          } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[8] == 1) {
            load_arduino_v_15_DW.is_AUTOMATICA = load__IN_ATTERRAGGIO_AUTOMATICO;
          } else {
            load_arduino_v_15_B.modo = 1.0;
            load_arduino_v_15_B.switch_manetta = 1.0;
            load_arduino_v_15_B.switch_equilibratore = 1.0;
            load_arduino_v_15_B.switch_alettoni = 1.0;
            load_arduino_v_15_B.switch_timone = 1.0;
          }
          break;
        }
      }
      break;

     case load_arduino_v_15_IN_Go_Home:
      if ((load_arduino_v_15_B.Go_Home == 0.0) &&
          ((load_arduino_v_15_DW.Memory2_PreviousInput_a[6] == 1) ||
           (load_arduino_v_15_DW.Memory2_PreviousInput_a[3] == 1) ||
           (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] == 1) ||
           (load_arduino_v_15_DW.Memory2_PreviousInput_a[2] == 1) ||
           (load_arduino_v_15_DW.Memory2_PreviousInput_a[8] == 1))) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_AUTOMATICA;
        load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_VETTORIALE;
      } else if (load_arduino_v_15_B.Switch_n == 1.0) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_Safe;
      } else if (load_arduino_v_15_P.Constant2_Value_k == 1.0) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_ardui_IN_Intervento_Pilota;
      } else {
        load_arduino_v_15_B.modo = 5.0;
        load_arduino_v_15_B.switch_manetta = 1.0;
        load_arduino_v_15_B.switch_equilibratore = 1.0;
        load_arduino_v_15_B.switch_alettoni = 1.0;
        load_arduino_v_15_B.switch_timone = 1.0;
      }
      break;

     case load_ardui_IN_Intervento_Pilota:
      if (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 1) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_MANUALE;
      } else {
        load_arduino_v_15_B.switch_manetta = 0.0;
        load_arduino_v_15_B.switch_equilibratore = 0.0;
        load_arduino_v_15_B.switch_alettoni = 0.0;
        load_arduino_v_15_B.switch_timone = 0.0;
      }
      break;

     case load_arduino_v_15_IN_MANUALE:
      if ((load_arduino_v_15_B.Go_Home == 1.0) && (load_arduino_v_15_B.Switch_n ==
           0.0)) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_Go_Home;
      } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 0) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_Stand_By;
      } else {
        load_arduino_v_15_B.switch_manetta = 0.0;
        load_arduino_v_15_B.switch_equilibratore = 0.0;
        load_arduino_v_15_B.switch_alettoni = 0.0;
        load_arduino_v_15_B.switch_timone = 0.0;
      }
      break;

     case load_arduino_v_15_IN_Safe:
      if (load_arduino_v_15_P.Constant2_Value_k == 1.0) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_ardui_IN_Intervento_Pilota;
      } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 1) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_MANUALE;
      } else {
        load_arduino_v_15_B.switch_manetta = 1.0;
        load_arduino_v_15_B.switch_equilibratore = 1.0;
        load_arduino_v_15_B.switch_alettoni = 1.0;
        load_arduino_v_15_B.switch_timone = 1.0;
        load_arduino_v_15_B.phi_safe = 0.1745;
        load_arduino_v_15_B.theta_safe = 0.05;
        load_arduino_v_15_B.throttle_safe = 0.1;
      }
      break;

     default:
      /* case IN_Stand_By: */
      if (load_arduino_v_15_DW.Memory2_PreviousInput_a[1] == 1) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_AUTOMATICA;
        load_arduino_v_15_DW.is_AUTOMATICA = load_arduino_v_15_IN_VETTORIALE;
      } else if (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 1) {
        load_arduino_v_15_DW.is_c26_load_arduino_v_15 =
          load_arduino_v_15_IN_MANUALE;
      } else {
        load_arduino_v_15_B.switch_manetta = 0.0;
        load_arduino_v_15_B.switch_equilibratore = 0.0;
        load_arduino_v_15_B.switch_alettoni = 0.0;
        load_arduino_v_15_B.switch_timone = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S40>/ STATI' */

  /* Gain: '<S569>/Gain1' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   */
  load_arduino_v_15_B.Go_Home = load_arduino_v_15_P.Gain1_Gain_j *
    load_arduino_v_15_B.ByteUnpack_o2[0];

  /* Gain: '<S570>/Gain1' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   */
  load_arduino_v_15_B.Gain1_cv = load_arduino_v_15_P.Gain1_Gain_kd *
    load_arduino_v_15_B.ByteUnpack_o2[1];

  /* Gain: '<S567>/Gain1' */
  load_arduino_v_15_B.Gain1_cvb = load_arduino_v_15_P.Gain1_Gain_c *
    load_arduino_v_15_B.DataTypeConversion1_b[8];

  /* S-Function (PWMinterrupt_aileron_v4_4): '<S9>/S-Function Builder7' */
  PWMinterrupt_aileron_v4_4_Outputs_wrapper(&load_arduino_v_15_B.PWM_aileron);

  /* Logic: '<S41>/AND' */
  Ap_sel = ((load_arduino_v_15_B.switch_manetta != 0.0) &&
            (load_arduino_v_15_B.switch_equilibratore != 0.0) &&
            (load_arduino_v_15_B.switch_alettoni != 0.0) &&
            (load_arduino_v_15_B.switch_timone != 0.0));

  /* Chart: '<S41>/Chart' incorporates:
   *  Logic: '<S41>/AND'
   */
  if (load_arduino_v_15_DW.is_active_c1_load_arduino_v_15 == 0U) {
    load_arduino_v_15_DW.is_active_c1_load_arduino_v_15 = 1U;
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_In;
    load_arduino_v_15_B.Wp_selector = 0.0;
    load_arduino_v_15_B.Vec_selector = 0.0;
    load_arduino_v_15_B.Ato_selector = 0.0;
    load_arduino_v_15_B.Al_selector = 0.0;
    load_arduino_v_15_B.Go_home_selector = 0.0;
  } else {
    switch (load_arduino_v_15_DW.is_c1_load_arduino_v_15) {
     case load_arduino_v_1_IN_AutoLanding:
      if ((!(load_arduino_v_15_B.switch_manetta != 0.0)) ||
          (!(load_arduino_v_15_B.switch_equilibratore != 0.0)) ||
          (!(load_arduino_v_15_B.switch_alettoni != 0.0)) ||
          (!(load_arduino_v_15_B.switch_timone != 0.0))) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_In;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 2.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_Vettoriale;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 1.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 1.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_Waypoint;
        load_arduino_v_15_B.Wp_selector = 1.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 5.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_GoHome;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 1.0;
      } else {
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 1.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      }
      break;

     case load_arduino_v_1_IN_AutoTakeoff:
      if ((!(load_arduino_v_15_B.switch_manetta != 0.0)) ||
          (!(load_arduino_v_15_B.switch_equilibratore != 0.0)) ||
          (!(load_arduino_v_15_B.switch_alettoni != 0.0)) ||
          (!(load_arduino_v_15_B.switch_timone != 0.0))) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_In;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 1.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_Waypoint;
        load_arduino_v_15_B.Wp_selector = 1.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 2.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_Vettoriale;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 1.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else {
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 1.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      }
      break;

     case load_arduino_v_15_IN_GoHome:
      if ((!(load_arduino_v_15_B.switch_manetta != 0.0)) ||
          (!(load_arduino_v_15_B.switch_equilibratore != 0.0)) ||
          (!(load_arduino_v_15_B.switch_alettoni != 0.0)) ||
          (!(load_arduino_v_15_B.switch_timone != 0.0))) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_In;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else {
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 1.0;
      }
      break;

     case load_arduino_v_15_IN_In:
      load_arduino_v_15_In(&Ap_sel, &load_arduino_v_15_B.Go_home_selector,
                           &load_arduino_v_15_B.Al_selector,
                           &load_arduino_v_15_B.Ato_selector,
                           &load_arduino_v_15_B.Vec_selector,
                           &load_arduino_v_15_B.Wp_selector);
      break;

     case load_arduino_v_15_IN_Vettoriale:
      if ((!(load_arduino_v_15_B.switch_manetta != 0.0)) ||
          (!(load_arduino_v_15_B.switch_equilibratore != 0.0)) ||
          (!(load_arduino_v_15_B.switch_alettoni != 0.0)) ||
          (!(load_arduino_v_15_B.switch_timone != 0.0))) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 = load_arduino_v_15_IN_In;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 1.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_Waypoint;
        load_arduino_v_15_B.Wp_selector = 1.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else if (load_arduino_v_15_B.modo == 5.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_15_IN_GoHome;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 1.0;
      } else if (load_arduino_v_15_B.modo == 4.0) {
        load_arduino_v_15_DW.is_c1_load_arduino_v_15 =
          load_arduino_v_1_IN_AutoLanding;
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 0.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 1.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      } else {
        load_arduino_v_15_B.Wp_selector = 0.0;
        load_arduino_v_15_B.Vec_selector = 1.0;
        load_arduino_v_15_B.Ato_selector = 0.0;
        load_arduino_v_15_B.Al_selector = 0.0;
        load_arduino_v_15_B.Go_home_selector = 0.0;
      }
      break;

     default:
      /* case IN_Waypoint: */
      load_arduino_v_15_Waypoint(&Ap_sel, &load_arduino_v_15_B.Go_home_selector,
        &load_arduino_v_15_B.Al_selector, &load_arduino_v_15_B.Ato_selector,
        &load_arduino_v_15_B.Vec_selector, &load_arduino_v_15_B.Wp_selector);
      break;
    }
  }

  /* End of Chart: '<S41>/Chart' */

  /* Gain: '<S566>/Gain1' */
  load_arduino_v_15_B.Gain1_a = load_arduino_v_15_P.Gain1_Gain_kf *
    load_arduino_v_15_B.DataTypeConversion1_b[7];

  /* Outputs for Enabled SubSystem: '<S41>/DECOLLO AUTOMATICO' incorporates:
   *  EnablePort: '<S452>/Enable'
   */
  if (load_arduino_v_15_B.Ato_selector > 0.0) {
    /* Outputs for Triggered SubSystem: '<S452>/Sample and Hold' incorporates:
     *  TriggerPort: '<S461>/Trigger'
     */
    /* Memory: '<S452>/Memory' */
    load_arduino_v_15_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &load_arduino_v_15_PrevZCX.SampleandHold_Trig_ZCE_e,
      (load_arduino_v_15_DW.Memory_PreviousInput_a));
    if (load_arduino_v_15_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S461>/In' */
      load_arduino_v_15_B.In_o = load_arduino_v_15_B.Gain1_cvb;
    }

    /* End of Outputs for SubSystem: '<S452>/Sample and Hold' */

    /* Outputs for Triggered SubSystem: '<S452>/Sample and Hold1' incorporates:
     *  TriggerPort: '<S462>/Trigger'
     */
    /* Memory: '<S452>/Memory1' */
    load_arduino_v_15_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &load_arduino_v_15_PrevZCX.SampleandHold1_Trig_ZCE,
      (load_arduino_v_15_DW.Memory1_PreviousInput_m));
    if (load_arduino_v_15_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S462>/In' incorporates:
       *  Gain: '<S459>/Gain'
       */
      load_arduino_v_15_B.In_j = load_arduino_v_15_P.Gain_Gain_n *
        load_arduino_v_15_B.Gain1_a;
    }

    /* End of Outputs for SubSystem: '<S452>/Sample and Hold1' */

    /* Chart: '<S452>/Chart1' incorporates:
     *  Constant: '<S452>/Constant'
     *  Constant: '<S452>/Constant1'
     *  Constant: '<S452>/Constant2'
     *  DataTypeConversion: '<S571>/Data Type Conversion5'
     */
    if (load_arduino_v_15_DW.temporalCounter_i1 < 255U) {
      load_arduino_v_15_DW.temporalCounter_i1++;
    }

    if (load_arduino_v_15_DW.is_active_c2_load_arduino_v_15 == 0U) {
      load_arduino_v_15_DW.is_active_c2_load_arduino_v_15 = 1U;
      load_arduino_v_15_DW.is_c2_load_arduino_v_15 =
        load_arduino_v_15_IN_Fase_0_ATO;
    } else {
      switch (load_arduino_v_15_DW.is_c2_load_arduino_v_15) {
       case load_arduino_v_15_IN_Fase_0_ATO:
        if (load_arduino_v_15_B.modo == 3.0) {
          load_arduino_v_15_B.psi_ref_selector = 1.0;
          load_arduino_v_15_DW.is_c2_load_arduino_v_15 =
            load_arduino_v_15_IN_Fase_1_ATO;
          load_arduino_v_15_DW.temporalCounter_i1 = 0U;
        } else {
          load_arduino_v_15_B.Fase_ATO = 0.0;
          load_arduino_v_15_B.psi_ref_selector = 0.0;
          load_arduino_v_15_B.theta_ground_selector = 0.0;
          load_arduino_v_15_B.psi_ref = 0.0;
          load_arduino_v_15_B.eq_rot = 0.0;
          load_arduino_v_15_B.Tas_ref = 0.0;
          load_arduino_v_15_B.pitch_ref = 0.0;
          load_arduino_v_15_B.h_ref = 0.0;
          load_arduino_v_15_B.RC_ref = 0.0;
        }
        break;

       case load_arduino_v_15_IN_Fase_1_ATO:
        if (load_arduino_v_15_DW.temporalCounter_i1 >= 250) {
          load_arduino_v_15_DW.is_c2_load_arduino_v_15 =
            load_arduino_v_15_IN_Fase_2_ATO;
        } else {
          load_arduino_v_15_B.Fase_ATO = 1.0;
          load_arduino_v_15_B.manetta_ref = 0.0;
          load_arduino_v_15_B.psi_ref_selector = 0.0;
          load_arduino_v_15_B.h_ref = load_arduino_v_15_B.ByteUnpack_o2[2];
          load_arduino_v_15_B.psi_ref = load_arduino_v_15_B.In_o;
          load_arduino_v_15_B.eq_rot = 2.0;
          load_arduino_v_15_B.RC_ref = load_arduino_v_15_B.num_254;
        }
        break;

       case load_arduino_v_15_IN_Fase_2_ATO:
        if (load_arduino_v_15_B.rtb_Gain1_idx_1 >= load_arduino_v_15_P.V_stall *
            1.2) {
          load_arduino_v_15_B.theta_ground_selector = 1.0;
          load_arduino_v_15_DW.is_c2_load_arduino_v_15 =
            load_arduino_v_15_IN_Fase_3_ATO;
        } else {
          load_arduino_v_15_B.Fase_ATO = 2.0;
          load_arduino_v_15_B.psi_ref_selector = 0.0;
          load_arduino_v_15_B.psi_ref = load_arduino_v_15_B.In_o;
          load_arduino_v_15_B.h_ref = load_arduino_v_15_P.final_h;
          load_arduino_v_15_B.eq_rot = 0.0;
          load_arduino_v_15_B.Tas_ref = load_arduino_v_15_P.V_stall * 1.4;
          load_arduino_v_15_B.RC_ref = load_arduino_v_15_B.num_254;
        }
        break;

       case load_arduino_v_15_IN_Fase_3_ATO:
        if (load_arduino_v_15_B.ByteUnpack_o2[2] >= 1.5F) {
          load_arduino_v_15_DW.is_c2_load_arduino_v_15 =
            load_arduino_v_15_IN_Fase_4_ATO;
        } else {
          load_arduino_v_15_B.Fase_ATO = 3.0;
          load_arduino_v_15_B.psi_ref_selector = 0.0;
          load_arduino_v_15_B.theta_ground_selector = 0.0;
          load_arduino_v_15_B.psi_ref = load_arduino_v_15_B.In_o;
          load_arduino_v_15_B.h_ref = load_arduino_v_15_P.final_h;
          load_arduino_v_15_B.RC_ref = load_arduino_v_15_B.num_254;
          load_arduino_v_15_B.pitch_ref = load_arduino_v_15_P.theta_rot +
            load_arduino_v_15_B.In_j;
          load_arduino_v_15_B.Tas_ref = load_arduino_v_15_P.V_stall * 1.4;
        }
        break;

       default:
        /* case IN_Fase_4_ATO: */
        load_arduino_v_15_B.Fase_ATO = 4.0;
        load_arduino_v_15_B.psi_ref_selector = 0.0;
        load_arduino_v_15_B.psi_ref = load_arduino_v_15_B.In_o;
        load_arduino_v_15_B.h_ref = load_arduino_v_15_P.final_h;
        load_arduino_v_15_B.RC_ref = 1.5;
        load_arduino_v_15_B.Tas_ref = load_arduino_v_15_P.V_stall * 1.4;
        break;
      }
    }

    /* End of Chart: '<S452>/Chart1' */

    /* Gain: '<S460>/Gain' */
    load_arduino_v_15_B.Gain_f = load_arduino_v_15_P.Gain_Gain_o *
      load_arduino_v_15_B.psi_ref;

    /* Update for Memory: '<S452>/Memory' */
    load_arduino_v_15_DW.Memory_PreviousInput_a =
      load_arduino_v_15_B.psi_ref_selector;

    /* Update for Memory: '<S452>/Memory1' */
    load_arduino_v_15_DW.Memory1_PreviousInput_m =
      load_arduino_v_15_B.theta_ground_selector;
  }

  /* End of Outputs for SubSystem: '<S41>/DECOLLO AUTOMATICO' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Abs: '<S6>/Abs2'
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   *  Sum: '<S6>/Sum2'
   *  Switch: '<S6>/Switch2'
   */
  if (load_arduino_v_15_B.ByteUnpack_o2[2] >
      load_arduino_v_15_P.Switch1_Threshold_c) {
    load_arduino_v_15_B.rtb_Gain4_idx_1 = load_arduino_v_15_B.ByteUnpack_o2[2];
  } else {
    if (fabs(load_arduino_v_15_B.rtb_Gain4_idx_1 -
             load_arduino_v_15_B.ByteUnpack_o2[2]) >
        load_arduino_v_15_P.Switch2_Threshold_k) {
      /* Switch: '<S6>/Switch2' */
      load_arduino_v_15_B.rtb_Gain4_idx_1 = load_arduino_v_15_B.ByteUnpack_o2[2];
    }
  }

  /* End of Switch: '<S6>/Switch1' */

  /* RateLimiter: '<S6>/Rate Limiter1' */
  load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.rtb_Gain4_idx_1 -
    load_arduino_v_15_DW.PrevY;
  if (load_arduino_v_15_B.Ato_selector >
      load_arduino_v_15_P.RateLimiter1_RisingLim) {
    /* RateLimiter: '<S6>/Rate Limiter1' */
    load_arduino_v_15_DW.PrevY += load_arduino_v_15_P.RateLimiter1_RisingLim;
  } else if (load_arduino_v_15_B.Ato_selector <
             load_arduino_v_15_P.RateLimiter1_FallingLim) {
    /* RateLimiter: '<S6>/Rate Limiter1' */
    load_arduino_v_15_DW.PrevY += load_arduino_v_15_P.RateLimiter1_FallingLim;
  } else {
    /* RateLimiter: '<S6>/Rate Limiter1' */
    load_arduino_v_15_DW.PrevY = load_arduino_v_15_B.rtb_Gain4_idx_1;
  }

  /* End of RateLimiter: '<S6>/Rate Limiter1' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem1' incorporates:
   *  EnablePort: '<S455>/Enable'
   */
  if (load_arduino_v_15_B.Al_selector > 0.0) {
    /* MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES' incorporates:
     *  MATLAB Function: '<S468>/MATLAB Function'
     */
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.WP_db_param[30] *
      0.017453292519943295;
    load_arduino_v_15_B.rtb_Gain4_idx_1 = cos(load_arduino_v_15_B.WP_db_param[25]
      * 0.017453292519943295);
    load_arduino_v_15_B.Al_selector = sin(load_arduino_v_15_B.WP_db_param[24] *
      0.017453292519943295);
    load_arduino_v_15_B.Abs1 = cos(load_arduino_v_15_B.WP_db_param[24] *
      0.017453292519943295);
    load_arduino_v_15_B.Sum3 = load_arduino_v_15_B.WP_db_param[31] *
      0.017453292519943295 - load_arduino_v_15_B.WP_db_param[30] *
      0.017453292519943295;
    load_arduino_v_15_B.rtb_Gain4_idx_1 = rt_atan2d_snf(sin
      (load_arduino_v_15_B.Sum3) * load_arduino_v_15_B.rtb_Gain4_idx_1, sin
      (load_arduino_v_15_B.WP_db_param[25] * 0.017453292519943295) *
      load_arduino_v_15_B.Abs1 - cos(load_arduino_v_15_B.Sum3) *
      (load_arduino_v_15_B.Al_selector * load_arduino_v_15_B.rtb_Gain4_idx_1));
    if (load_arduino_v_15_B.rtb_Gain4_idx_1 < 0.0) {
      load_arduino_v_15_B.rtb_Gain4_idx_1 = 6.2831853071795862 - fabs
        (load_arduino_v_15_B.rtb_Gain4_idx_1);
    }

    /* MATLAB Function: '<S468>/MATLAB Function' incorporates:
     *  Constant: '<S468>/distance waypoints virtuale'
     *  MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES'
     *  Trigonometry: '<S539>/SinCos'
     */
    load_arduino_v_15_B.Abs1_a = sin
      (load_arduino_v_15_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    load_arduino_v_15_B.Abs_i = cos
      (load_arduino_v_15_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    load_arduino_v_15_B.Sum3 = cos(load_arduino_v_15_B.rtb_Gain4_idx_1);
    load_arduino_v_15_B.e = asin(load_arduino_v_15_B.Abs1 *
      load_arduino_v_15_B.Abs1_a * load_arduino_v_15_B.Sum3 +
      load_arduino_v_15_B.Al_selector * load_arduino_v_15_B.Abs_i);
    load_arduino_v_15_B.Sum_gs = sin(load_arduino_v_15_B.rtb_Gain4_idx_1);

    /* MATLAB Function: '<S468>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S468>/alt waypoint virtuale'
     *  Gain: '<S484>/Gain'
     *  Gain: '<S485>/Gain'
     *  MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES'
     *  MATLAB Function: '<S468>/MATLAB Function'
     */
    load_arduino_v_15_B.WP_param_m[12] = load_arduino_v_15_P.Gain_Gain_m *
      load_arduino_v_15_B.e;
    load_arduino_v_15_B.WP_param_m[15] = load_arduino_v_15_P.Gain_Gain_pc *
      (rt_atan2d_snf(load_arduino_v_15_B.Sum_gs * load_arduino_v_15_B.Abs1_a *
                     load_arduino_v_15_B.Abs1, load_arduino_v_15_B.Abs_i -
                     load_arduino_v_15_B.Al_selector * sin(load_arduino_v_15_B.e))
       + load_arduino_v_15_B.Ato_selector);
    load_arduino_v_15_B.WP_param_m[3] = 1.0;
    load_arduino_v_15_B.WP_param_m[6] = 0.0;
    load_arduino_v_15_B.WP_param_m[9] = 0.0;
    load_arduino_v_15_B.WP_param_m[18] = load_arduino_v_15_B.WP_db_param[36] +
      load_arduino_v_15_P.altwaypointvirtuale_Value[0];

    /* MATLAB Function: '<S468>/MATLAB Function' incorporates:
     *  Constant: '<S468>/distance waypoints virtuale'
     */
    load_arduino_v_15_B.Abs1_a = sin
      (load_arduino_v_15_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    load_arduino_v_15_B.Abs_i = cos
      (load_arduino_v_15_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    load_arduino_v_15_B.e = asin(load_arduino_v_15_B.Abs1 *
      load_arduino_v_15_B.Abs1_a * load_arduino_v_15_B.Sum3 +
      load_arduino_v_15_B.Al_selector * load_arduino_v_15_B.Abs_i);

    /* MATLAB Function: '<S468>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S468>/Constant1'
     *  Constant: '<S468>/alt waypoint virtuale'
     *  Gain: '<S484>/Gain'
     *  Gain: '<S485>/Gain'
     *  MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES'
     *  MATLAB Function: '<S468>/MATLAB Function'
     */
    load_arduino_v_15_B.WP_param_m[13] = load_arduino_v_15_P.Gain_Gain_m *
      load_arduino_v_15_B.e;
    load_arduino_v_15_B.WP_param_m[16] = load_arduino_v_15_P.Gain_Gain_pc *
      (rt_atan2d_snf(load_arduino_v_15_B.Sum_gs * load_arduino_v_15_B.Abs1_a *
                     load_arduino_v_15_B.Abs1, load_arduino_v_15_B.Abs_i -
                     load_arduino_v_15_B.Al_selector * sin(load_arduino_v_15_B.e))
       + load_arduino_v_15_B.Ato_selector);
    load_arduino_v_15_B.WP_param_m[1] = load_arduino_v_15_P.vel_wp2_al;
    load_arduino_v_15_B.WP_param_m[4] = 1.0;
    load_arduino_v_15_B.WP_param_m[7] = 0.0;
    load_arduino_v_15_B.WP_param_m[10] = 0.0;
    load_arduino_v_15_B.WP_param_m[19] = load_arduino_v_15_B.WP_db_param[36] +
      load_arduino_v_15_P.altwaypointvirtuale_Value[1];

    /* MATLAB Function: '<S468>/MATLAB Function' incorporates:
     *  Constant: '<S468>/distance waypoints virtuale'
     */
    load_arduino_v_15_B.Abs1_a = sin
      (load_arduino_v_15_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    load_arduino_v_15_B.Abs_i = cos
      (load_arduino_v_15_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    load_arduino_v_15_B.e = asin(load_arduino_v_15_B.Abs1 *
      load_arduino_v_15_B.Abs1_a * load_arduino_v_15_B.Sum3 +
      load_arduino_v_15_B.Al_selector * load_arduino_v_15_B.Abs_i);

    /* MATLAB Function: '<S468>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S468>/Constant'
     *  Constant: '<S468>/Constant1'
     *  Constant: '<S468>/alt waypoint virtuale'
     *  Gain: '<S484>/Gain'
     *  Gain: '<S485>/Gain'
     *  MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES'
     *  MATLAB Function: '<S468>/MATLAB Function'
     */
    load_arduino_v_15_B.WP_param_m[14] = load_arduino_v_15_P.Gain_Gain_m *
      load_arduino_v_15_B.e;
    load_arduino_v_15_B.WP_param_m[17] = load_arduino_v_15_P.Gain_Gain_pc *
      (rt_atan2d_snf(load_arduino_v_15_B.Sum_gs * load_arduino_v_15_B.Abs1_a *
                     load_arduino_v_15_B.Abs1, load_arduino_v_15_B.Abs_i -
                     load_arduino_v_15_B.Al_selector * sin(load_arduino_v_15_B.e))
       + load_arduino_v_15_B.Ato_selector);
    load_arduino_v_15_B.WP_param_m[2] = load_arduino_v_15_P.vel_wp2_al;
    load_arduino_v_15_B.WP_param_m[8] = 0.0;
    load_arduino_v_15_B.WP_param_m[11] = 0.0;
    load_arduino_v_15_B.WP_param_m[20] = load_arduino_v_15_B.WP_db_param[36] +
      load_arduino_v_15_P.altwaypointvirtuale_Value[2];
    load_arduino_v_15_B.WP_param_m[0] = load_arduino_v_15_P.vel_wp1_al;
    load_arduino_v_15_B.WP_param_m[5] = 0.0;

    /* Gain: '<S473>/Gain' incorporates:
     *  MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES'
     */
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.WP_db_param[24] *
      0.017453292519943295 * load_arduino_v_15_P.Gain_Gain_n2;

    /* Switch: '<S549>/Switch' incorporates:
     *  Abs: '<S549>/Abs'
     *  Bias: '<S549>/Bias'
     *  Bias: '<S549>/Bias1'
     *  Constant: '<S549>/Constant2'
     *  Constant: '<S550>/Constant'
     *  Math: '<S549>/Math Function1'
     *  RelationalOperator: '<S550>/Compare'
     */
    if (fabs(load_arduino_v_15_B.Al_selector) >
        load_arduino_v_15_P.CompareToConstant_const) {
      load_arduino_v_15_B.Al_selector = rt_modd_snf
        (load_arduino_v_15_B.Al_selector + load_arduino_v_15_P.Bias_Bias_b,
         load_arduino_v_15_P.Constant2_Value_e) +
        load_arduino_v_15_P.Bias1_Bias_jg;
    }

    /* End of Switch: '<S549>/Switch' */

    /* Abs: '<S546>/Abs1' */
    load_arduino_v_15_B.Abs1 = fabs(load_arduino_v_15_B.Al_selector);

    /* Switch: '<S546>/Switch' incorporates:
     *  Bias: '<S546>/Bias'
     *  Bias: '<S546>/Bias1'
     *  Constant: '<S538>/Constant'
     *  Constant: '<S538>/Constant1'
     *  Constant: '<S548>/Constant'
     *  Gain: '<S546>/Gain'
     *  Product: '<S546>/Divide1'
     *  RelationalOperator: '<S548>/Compare'
     *  Switch: '<S538>/Switch1'
     */
    if (load_arduino_v_15_B.Abs1 > load_arduino_v_15_P.CompareToConstant_const_h)
    {
      /* Signum: '<S546>/Sign1' */
      if (load_arduino_v_15_B.Al_selector < 0.0) {
        load_arduino_v_15_B.Al_selector = -1.0;
      } else if (load_arduino_v_15_B.Al_selector > 0.0) {
        load_arduino_v_15_B.Al_selector = 1.0;
      } else if (load_arduino_v_15_B.Al_selector == 0.0) {
        load_arduino_v_15_B.Al_selector = 0.0;
      } else {
        load_arduino_v_15_B.Al_selector = (rtNaN);
      }

      /* End of Signum: '<S546>/Sign1' */
      load_arduino_v_15_B.Al_selector *= (load_arduino_v_15_B.Abs1 +
        load_arduino_v_15_P.Bias_Bias_m) * load_arduino_v_15_P.Gain_Gain_g +
        load_arduino_v_15_P.Bias1_Bias_f;
      load_arduino_v_15_B.Abs1_a = load_arduino_v_15_P.Constant_Value_a;
    } else {
      load_arduino_v_15_B.Abs1_a = load_arduino_v_15_P.Constant1_Value_o;
    }

    /* End of Switch: '<S546>/Switch' */

    /* Sum: '<S538>/Sum' incorporates:
     *  Gain: '<S474>/Gain'
     */
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_P.Gain_Gain_k *
      load_arduino_v_15_B.Ato_selector + load_arduino_v_15_B.Abs1_a;

    /* Sum: '<S472>/Sum1' incorporates:
     *  Gain: '<S476>/Gain'
     */
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Gain_Gain_j *
      load_arduino_v_15_B.Go_Home - load_arduino_v_15_B.Al_selector;

    /* Switch: '<S543>/Switch' incorporates:
     *  Abs: '<S543>/Abs'
     *  Bias: '<S543>/Bias'
     *  Bias: '<S543>/Bias1'
     *  Constant: '<S543>/Constant2'
     *  Constant: '<S544>/Constant'
     *  Math: '<S543>/Math Function1'
     *  RelationalOperator: '<S544>/Compare'
     */
    if (fabs(load_arduino_v_15_B.Ato_selector) >
        load_arduino_v_15_P.CompareToConstant_const_k) {
      load_arduino_v_15_B.Ato_selector = rt_modd_snf
        (load_arduino_v_15_B.Ato_selector + load_arduino_v_15_P.Bias_Bias_d,
         load_arduino_v_15_P.Constant2_Value_o2) +
        load_arduino_v_15_P.Bias1_Bias_j;
    }

    /* End of Switch: '<S543>/Switch' */

    /* Abs: '<S540>/Abs1' */
    load_arduino_v_15_B.Abs1_a = fabs(load_arduino_v_15_B.Ato_selector);

    /* Switch: '<S540>/Switch' incorporates:
     *  Bias: '<S540>/Bias'
     *  Bias: '<S540>/Bias1'
     *  Constant: '<S537>/Constant'
     *  Constant: '<S537>/Constant1'
     *  Constant: '<S542>/Constant'
     *  Gain: '<S540>/Gain'
     *  Product: '<S540>/Divide1'
     *  RelationalOperator: '<S542>/Compare'
     *  Switch: '<S537>/Switch1'
     */
    if (load_arduino_v_15_B.Abs1_a >
        load_arduino_v_15_P.CompareToConstant_const_m) {
      /* Signum: '<S540>/Sign1' */
      if (load_arduino_v_15_B.Ato_selector < 0.0) {
        load_arduino_v_15_B.Ato_selector = -1.0;
      } else if (load_arduino_v_15_B.Ato_selector > 0.0) {
        load_arduino_v_15_B.Ato_selector = 1.0;
      } else if (load_arduino_v_15_B.Ato_selector == 0.0) {
        load_arduino_v_15_B.Ato_selector = 0.0;
      } else {
        load_arduino_v_15_B.Ato_selector = (rtNaN);
      }

      /* End of Signum: '<S540>/Sign1' */
      load_arduino_v_15_B.SumI1_ak = ((load_arduino_v_15_B.Abs1_a +
        load_arduino_v_15_P.Bias_Bias) * load_arduino_v_15_P.Gain_Gain_p +
        load_arduino_v_15_P.Bias1_Bias) * load_arduino_v_15_B.Ato_selector;
      load_arduino_v_15_B.Abs1_a = load_arduino_v_15_P.Constant_Value_e;
    } else {
      load_arduino_v_15_B.SumI1_ak = load_arduino_v_15_B.Ato_selector;
      load_arduino_v_15_B.Abs1_a = load_arduino_v_15_P.Constant1_Value_g;
    }

    /* End of Switch: '<S540>/Switch' */

    /* Switch: '<S547>/Switch' incorporates:
     *  Abs: '<S547>/Abs'
     *  Bias: '<S547>/Bias'
     *  Bias: '<S547>/Bias1'
     *  Constant: '<S547>/Constant2'
     *  Constant: '<S551>/Constant'
     *  Math: '<S547>/Math Function1'
     *  RelationalOperator: '<S551>/Compare'
     */
    if (fabs(load_arduino_v_15_B.Abs1) >
        load_arduino_v_15_P.CompareToConstant_const_f) {
      load_arduino_v_15_B.Abs1 = rt_modd_snf(load_arduino_v_15_B.Abs1 +
        load_arduino_v_15_P.Bias_Bias_c, load_arduino_v_15_P.Constant2_Value_j)
        + load_arduino_v_15_P.Bias1_Bias_g;
    }

    /* End of Switch: '<S547>/Switch' */

    /* Sum: '<S537>/Sum' incorporates:
     *  Gain: '<S475>/Gain'
     *  Sum: '<S472>/Sum1'
     */
    load_arduino_v_15_B.Abs1_a += load_arduino_v_15_P.Gain_Gain_d *
      load_arduino_v_15_B.Gain1_cv - load_arduino_v_15_B.Abs1;

    /* Gain: '<S536>/Gain1' */
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Gain1_Gain_m *
      load_arduino_v_15_B.SumI1_ak;

    /* Sum: '<S554>/Sum' incorporates:
     *  Constant: '<S554>/Constant'
     *  Constant: '<S554>/f'
     */
    load_arduino_v_15_B.SumI1_ak = load_arduino_v_15_P.f_Value -
      load_arduino_v_15_P.Constant_Value_i;

    /* Sqrt: '<S555>/Sqrt' incorporates:
     *  Constant: '<S555>/Constant4'
     *  Product: '<S555>/Product'
     *  Sum: '<S555>/Sum'
     */
    load_arduino_v_15_B.SumI1_ak = sqrt(load_arduino_v_15_P.Constant4_Value_ee -
      load_arduino_v_15_B.SumI1_ak * load_arduino_v_15_B.SumI1_ak);

    /* Gain: '<S553>/Gain1' */
    load_arduino_v_15_B.Al_selector *= load_arduino_v_15_P.Gain1_Gain_m4;

    /* Trigonometry: '<S556>/Trigonometric Function1' */
    load_arduino_v_15_B.DeadZone = sin(load_arduino_v_15_B.Al_selector);

    /* Sum: '<S556>/Sum1' incorporates:
     *  Constant: '<S556>/Constant'
     *  Product: '<S556>/Product1'
     */
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_P.Constant_Value_l -
      load_arduino_v_15_B.SumI1_ak * load_arduino_v_15_B.SumI1_ak *
      load_arduino_v_15_B.DeadZone * load_arduino_v_15_B.DeadZone;

    /* Product: '<S552>/Product1' incorporates:
     *  Constant: '<S552>/Constant1'
     *  Sqrt: '<S552>/sqrt'
     */
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_P.Constant1_Value_n / sqrt
      (load_arduino_v_15_B.DeadZone);

    /* Product: '<S539>/dNorth' incorporates:
     *  Constant: '<S552>/Constant'
     *  Constant: '<S552>/Constant2'
     *  Product: '<S552>/Product2'
     *  Product: '<S552>/Product3'
     *  Sum: '<S552>/Sum1'
     *  Trigonometry: '<S552>/Trigonometric Function1'
     */
    load_arduino_v_15_B.SumI1_ak = load_arduino_v_15_B.Ato_selector /
      rt_atan2d_snf(load_arduino_v_15_P.Constant2_Value_oc,
                    (load_arduino_v_15_P.Constant_Value_b -
                     load_arduino_v_15_B.SumI1_ak * load_arduino_v_15_B.SumI1_ak)
                    * load_arduino_v_15_B.Abs1 / load_arduino_v_15_B.DeadZone);

    /* Switch: '<S541>/Switch' incorporates:
     *  Abs: '<S541>/Abs'
     *  Bias: '<S541>/Bias'
     *  Bias: '<S541>/Bias1'
     *  Constant: '<S541>/Constant2'
     *  Constant: '<S545>/Constant'
     *  Math: '<S541>/Math Function1'
     *  RelationalOperator: '<S545>/Compare'
     */
    if (fabs(load_arduino_v_15_B.Abs1_a) >
        load_arduino_v_15_P.CompareToConstant_const_o) {
      load_arduino_v_15_B.Abs1_a = rt_modd_snf(load_arduino_v_15_B.Abs1_a +
        load_arduino_v_15_P.Bias_Bias_g, load_arduino_v_15_P.Constant2_Value_on)
        + load_arduino_v_15_P.Bias1_Bias_c;
    }

    /* End of Switch: '<S541>/Switch' */

    /* Product: '<S539>/dEast' incorporates:
     *  Constant: '<S552>/Constant3'
     *  Gain: '<S536>/Gain1'
     *  Product: '<S552>/Product4'
     *  Trigonometry: '<S552>/Trigonometric Function'
     *  Trigonometry: '<S552>/Trigonometric Function2'
     */
    load_arduino_v_15_B.Al_selector = 1.0 / rt_atan2d_snf
      (load_arduino_v_15_P.Constant3_Value_h, load_arduino_v_15_B.Abs1 * cos
       (load_arduino_v_15_B.Al_selector)) * (load_arduino_v_15_P.Gain1_Gain_m *
      load_arduino_v_15_B.Abs1_a);

    /* Sum: '<S539>/Sum2' incorporates:
     *  Product: '<S539>/x*cos'
     *  Product: '<S539>/y*sin'
     */
    load_arduino_v_15_B.Abs1_a = load_arduino_v_15_B.SumI1_ak *
      load_arduino_v_15_B.Sum3 + load_arduino_v_15_B.Al_selector *
      load_arduino_v_15_B.Sum_gs;

    /* Gain: '<S477>/Gain' */
    load_arduino_v_15_B.Gain_g = load_arduino_v_15_P.Gain_Gain_lp *
      load_arduino_v_15_B.Go_Home;

    /* Gain: '<S478>/Gain' */
    load_arduino_v_15_B.Gain_dw = load_arduino_v_15_P.Gain_Gain_iz *
      load_arduino_v_15_B.Gain1_cv;

    /* Gain: '<S479>/Gain' */
    load_arduino_v_15_B.Gain_nr = load_arduino_v_15_P.Gain_Gain_dl *
      load_arduino_v_15_B.Gain1_cvb;

    /* MATLAB Function: '<S455>/ALLINEAMENTO' incorporates:
     *  Memory: '<S455>/Memory7'
     */
    load_arduino_v_15_B.h_comandato = load_arduino_v_15_B.WP_param_m[(int32_T)
      load_arduino_v_15_DW.Memory7_PreviousInput + 17];
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.WP_param_m[(int32_T)
      load_arduino_v_15_DW.Memory7_PreviousInput + 11];
    load_arduino_v_15_B.a_n = sin((load_arduino_v_15_B.DeadZone -
      load_arduino_v_15_B.Gain_g) * 3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_15_B.Saturation_h = load_arduino_v_15_B.WP_param_m[(int32_T)
      load_arduino_v_15_DW.Memory7_PreviousInput + 14];
    load_arduino_v_15_B.Ato_selector = (load_arduino_v_15_B.Saturation_h -
      load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0;
    load_arduino_v_15_B.dist = sin(load_arduino_v_15_B.Ato_selector / 2.0);
    load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.DeadZone *
      3.1415926535897931 / 180.0;
    load_arduino_v_15_B.Abs_i = cos(load_arduino_v_15_B.psi_ref_p);
    load_arduino_v_15_B.e = load_arduino_v_15_B.Gain_g * 3.1415926535897931 /
      180.0;
    load_arduino_v_15_B.Abs1 = cos(load_arduino_v_15_B.e);
    load_arduino_v_15_B.a_n = load_arduino_v_15_B.Abs1 *
      load_arduino_v_15_B.Abs_i * (load_arduino_v_15_B.dist *
      load_arduino_v_15_B.dist) + load_arduino_v_15_B.a_n *
      load_arduino_v_15_B.a_n;
    load_arduino_v_15_B.a_n = rt_atan2d_snf(sqrt(load_arduino_v_15_B.a_n), sqrt
      (1.0 - load_arduino_v_15_B.a_n)) * 2.0 * 6.378137E+6;
    if (load_arduino_v_15_DW.Memory7_PreviousInput > 1.0) {
      load_arduino_v_15_B.angoloWP = load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 11];
      load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.angoloWP *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.dist = cos(load_arduino_v_15_B.psi_ref_p);
      load_arduino_v_15_B.dist_fut = load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 14];
      load_arduino_v_15_B.psi_ref_pre = (load_arduino_v_15_B.Saturation_h -
        load_arduino_v_15_B.dist_fut) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_p = rt_atan2d_snf(sin
        (load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_B.Abs_i, sin
        (load_arduino_v_15_B.WP_param_m[(int32_T)
         load_arduino_v_15_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * load_arduino_v_15_B.dist - sin(load_arduino_v_15_B.psi_ref_p) *
        load_arduino_v_15_B.Abs_i * cos(load_arduino_v_15_B.psi_ref_pre)) *
        180.0 / 3.1415926535897931;
      load_arduino_v_15_B.angoloWP = sin((load_arduino_v_15_B.Gain_g -
        load_arduino_v_15_B.angoloWP) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_15_B.dist_fut = sin((load_arduino_v_15_B.Gain_dw -
        load_arduino_v_15_B.dist_fut) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_15_B.dist = load_arduino_v_15_B.dist *
        load_arduino_v_15_B.Abs1 * (load_arduino_v_15_B.dist_fut *
        load_arduino_v_15_B.dist_fut) + load_arduino_v_15_B.angoloWP *
        load_arduino_v_15_B.angoloWP;
      load_arduino_v_15_B.dist = rt_atan2d_snf(sqrt(load_arduino_v_15_B.dist),
        sqrt(1.0 - load_arduino_v_15_B.dist)) * 2.0 * 6.378137E+6;
    } else {
      load_arduino_v_15_B.psi_ref_p = rt_atan2d_snf(sin
        (load_arduino_v_15_B.Ato_selector) * load_arduino_v_15_B.Abs_i, sin
        (load_arduino_v_15_B.psi_ref_p) * load_arduino_v_15_B.Abs1 - cos
        (load_arduino_v_15_B.Ato_selector) * (sin(load_arduino_v_15_B.e) *
        load_arduino_v_15_B.Abs_i)) * 180.0 / 3.1415926535897931;
      load_arduino_v_15_B.dist = 0.0;
    }

    if (load_arduino_v_15_B.psi_ref_p < 0.0) {
      load_arduino_v_15_B.psi_ref_p = 360.0 - fabs(load_arduino_v_15_B.psi_ref_p);
    }

    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.WP_param_m[(int32_T)
      load_arduino_v_15_DW.Memory7_PreviousInput + 2];
    if (load_arduino_v_15_B.Ato_selector == 1.0) {
      load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput + 1.0) + 11];
      load_arduino_v_15_B.dist_fut = sin((load_arduino_v_15_B.psi_ref_pre -
        load_arduino_v_15_B.DeadZone) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_15_B.angoloWP = (load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput + 1.0) + 14] -
        load_arduino_v_15_B.Saturation_h) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.Sum1_m = sin(load_arduino_v_15_B.angoloWP / 2.0);
      load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.psi_ref_pre *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.Sum_h = cos(load_arduino_v_15_B.psi_ref_pre);
      load_arduino_v_15_B.dist_fut = load_arduino_v_15_B.Abs_i *
        load_arduino_v_15_B.Sum_h * (load_arduino_v_15_B.Sum1_m *
        load_arduino_v_15_B.Sum1_m) + load_arduino_v_15_B.dist_fut *
        load_arduino_v_15_B.dist_fut;
      load_arduino_v_15_B.dist_fut = rt_atan2d_snf(sqrt
        (load_arduino_v_15_B.dist_fut), sqrt(1.0 - load_arduino_v_15_B.dist_fut))
        * 2.0 * 6.378137E+6;
      load_arduino_v_15_B.angoloWP = rt_atan2d_snf(sin
        (load_arduino_v_15_B.angoloWP) * load_arduino_v_15_B.Sum_h, sin
        (load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_B.Abs_i - cos
        (load_arduino_v_15_B.angoloWP) * (sin(load_arduino_v_15_B.WP_param_m
        [(int32_T)load_arduino_v_15_DW.Memory7_PreviousInput + 11] *
        3.1415926535897931 / 180.0) * load_arduino_v_15_B.Sum_h)) * 180.0 /
        3.1415926535897931;
      if (load_arduino_v_15_B.angoloWP < 0.0) {
        load_arduino_v_15_B.angoloWP = 360.0 - fabs(load_arduino_v_15_B.angoloWP);
      }

      if (load_arduino_v_15_DW.Memory7_PreviousInput > 1.0) {
        load_arduino_v_15_B.angoloWP = fabs(load_arduino_v_15_B.angoloWP -
          load_arduino_v_15_B.psi_ref_p);
      } else {
        load_arduino_v_15_B.angoloWP = fabs(load_arduino_v_15_B.angoloWP -
          rt_atan2d_snf(sin((load_arduino_v_15_B.WP_param_m[(int32_T)
                             load_arduino_v_15_DW.Memory7_PreviousInput + 14] -
                             load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 /
                            180.0) * cos(load_arduino_v_15_B.WP_param_m[(int32_T)
          load_arduino_v_15_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
          180.0), sin(load_arduino_v_15_B.WP_param_m[(int32_T)
                      load_arduino_v_15_DW.Memory7_PreviousInput + 11] *
                      3.1415926535897931 / 180.0) * cos
                        (load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0)
                        - cos(load_arduino_v_15_B.WP_param_m[(int32_T)
                              load_arduino_v_15_DW.Memory7_PreviousInput + 11] *
                              3.1415926535897931 / 180.0) * sin
                        (load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0)
                        * cos((load_arduino_v_15_B.WP_param_m[(int32_T)
          load_arduino_v_15_DW.Memory7_PreviousInput + 14] -
          load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      load_arduino_v_15_B.dist_fut = 0.0;
      load_arduino_v_15_B.angoloWP = 0.0;
    }

    if (load_arduino_v_15_DW.Memory7_PreviousInput < 2.0) {
      load_arduino_v_15_B.psi_ref_pre = 0.0;
    } else if (load_arduino_v_15_DW.Memory7_PreviousInput == 2.0) {
      load_arduino_v_15_B.psi_ref_pre = cos(load_arduino_v_15_B.WP_param_m
        [(int32_T)(load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      load_arduino_v_15_B.Sum_h = (load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 14] -
        load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_pre = fabs(load_arduino_v_15_B.psi_ref_p -
        rt_atan2d_snf(sin(load_arduino_v_15_B.Sum_h) *
                      load_arduino_v_15_B.psi_ref_pre, sin
                      (load_arduino_v_15_B.WP_param_m[(int32_T)
                       (load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 11] *
                       3.1415926535897931 / 180.0) * load_arduino_v_15_B.Abs1 -
                      cos(load_arduino_v_15_B.Sum_h) * (sin
        (load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0) *
        load_arduino_v_15_B.psi_ref_pre)) * 180.0 / 3.1415926535897931);
    } else {
      load_arduino_v_15_B.psi_ref_pre = cos(load_arduino_v_15_B.WP_param_m
        [(int32_T)(load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      load_arduino_v_15_B.Sum_h = load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput - 2.0) + 11] *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 14] -
        load_arduino_v_15_B.WP_param_m[(int32_T)
        (load_arduino_v_15_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_pre = rt_atan2d_snf(sin
        (load_arduino_v_15_B.Sum1_m) * load_arduino_v_15_B.psi_ref_pre, cos
        (load_arduino_v_15_B.Sum_h) * sin(load_arduino_v_15_B.WP_param_m
        [(int32_T)(load_arduino_v_15_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0) - sin(load_arduino_v_15_B.Sum_h) *
        load_arduino_v_15_B.psi_ref_pre * cos(load_arduino_v_15_B.Sum1_m)) *
        180.0 / 3.1415926535897931;
      if (load_arduino_v_15_B.psi_ref_pre < 0.0) {
        load_arduino_v_15_B.psi_ref_pre = 360.0 - fabs
          (load_arduino_v_15_B.psi_ref_pre);
      }

      load_arduino_v_15_B.psi_ref_pre = fabs(load_arduino_v_15_B.psi_ref_p -
        load_arduino_v_15_B.psi_ref_pre);
    }

    if (load_arduino_v_15_B.angoloWP <= 3.0) {
      load_arduino_v_15_B.angoloWP = 1.0;
      load_arduino_v_15_B.i = 20;
    } else if (load_arduino_v_15_B.angoloWP <= 10.0) {
      load_arduino_v_15_B.angoloWP = 30.0;
      load_arduino_v_15_B.i = 100;
    } else if ((load_arduino_v_15_B.angoloWP > 10.0) &&
               (load_arduino_v_15_B.angoloWP <= 50.0)) {
      load_arduino_v_15_B.angoloWP = 80.0;
      load_arduino_v_15_B.i = 250;
    } else if ((load_arduino_v_15_B.angoloWP > 50.0) &&
               (load_arduino_v_15_B.angoloWP <= 90.0)) {
      load_arduino_v_15_B.angoloWP = 100.0;
      load_arduino_v_15_B.i = 300;
    } else if ((load_arduino_v_15_B.angoloWP > 90.0) &&
               (load_arduino_v_15_B.angoloWP <= 120.0)) {
      load_arduino_v_15_B.angoloWP = 150.0;
      load_arduino_v_15_B.i = 350;
    } else {
      load_arduino_v_15_B.angoloWP = 200.0;
      load_arduino_v_15_B.i = 400;
    }

    if (load_arduino_v_15_B.psi_ref_pre <= 10.0) {
      load_arduino_v_15_B.soglia_dist = 80;
    } else if ((load_arduino_v_15_B.psi_ref_pre > 10.0) &&
               (load_arduino_v_15_B.psi_ref_pre <= 50.0)) {
      load_arduino_v_15_B.soglia_dist = 200;
    } else if ((load_arduino_v_15_B.psi_ref_pre > 50.0) &&
               (load_arduino_v_15_B.psi_ref_pre <= 90.0)) {
      load_arduino_v_15_B.soglia_dist = 300;
    } else if ((load_arduino_v_15_B.psi_ref_pre > 90.0) &&
               (load_arduino_v_15_B.psi_ref_pre <= 120.0)) {
      load_arduino_v_15_B.soglia_dist = 350;
    } else {
      load_arduino_v_15_B.soglia_dist = 400;
    }

    if (load_arduino_v_15_B.Ato_selector == 1.0) {
      load_arduino_v_15_B.Switch1 = rt_atan2d_snf(sin
        ((load_arduino_v_15_B.WP_param_m[(int32_T)
          load_arduino_v_15_DW.Memory7_PreviousInput + 14] -
          load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_15_B.WP_param_m[(int32_T)
         load_arduino_v_15_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_15_B.WP_param_m[(int32_T)
                     load_arduino_v_15_DW.Memory7_PreviousInput + 11] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_15_B.WP_param_m[(int32_T)
         load_arduino_v_15_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_15_B.WP_param_m[(int32_T)
             load_arduino_v_15_DW.Memory7_PreviousInput + 14] -
             load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0)) * 180.0
        / 3.1415926535897931;
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.WP_param_m[(int32_T)
        load_arduino_v_15_DW.Memory7_PreviousInput - 1];
      if (load_arduino_v_15_B.Ato_selector <= 20.0) {
        load_arduino_v_15_B.angoloWP *= 1.1;
      } else if ((load_arduino_v_15_B.Ato_selector <= 25.0) &&
                 (load_arduino_v_15_B.Ato_selector > 20.0)) {
        load_arduino_v_15_B.angoloWP *= 1.2;
      } else if (load_arduino_v_15_B.Ato_selector <= 30.0) {
        if (load_arduino_v_15_B.Ato_selector > 25.0) {
          load_arduino_v_15_B.angoloWP *= 1.3;
        } else {
          load_arduino_v_15_B.angoloWP *= 1.4;
        }
      } else {
        load_arduino_v_15_B.angoloWP *= 1.4;
      }

      if ((!(load_arduino_v_15_B.dist < load_arduino_v_15_B.soglia_dist)) ||
          (!(load_arduino_v_15_B.a_n > load_arduino_v_15_B.angoloWP))) {
        if ((load_arduino_v_15_B.dist > load_arduino_v_15_B.soglia_dist) &&
            (load_arduino_v_15_B.a_n > load_arduino_v_15_B.angoloWP)) {
          load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.Switch1 -
            load_arduino_v_15_B.psi_ref_p);
          if ((load_arduino_v_15_B.psi_ref_p <= 90.0) &&
              (load_arduino_v_15_B.psi_ref_p >= 0.0)) {
            if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
              load_arduino_v_15_B.Switch1 += 1.3 *
                load_arduino_v_15_B.Ato_selector;
            } else {
              if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 -= 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p <= 180.0) &&
                     (load_arduino_v_15_B.psi_ref_p > 90.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.Switch1 >
                0.0) {
              if ((load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.Switch1 < -90.0) &&
                   (load_arduino_v_15_B.Switch1 > -180.0))) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 - fabs
                (load_arduino_v_15_B.Switch1)) - load_arduino_v_15_B.psi_ref_p);
              if ((load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.Switch1 < -90.0) &&
                   (load_arduino_v_15_B.Switch1 > -180.0))) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p < -90.0) &&
                     (load_arduino_v_15_B.psi_ref_p >= -180.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.Switch1 >
                0.0) {
              if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 -
                load_arduino_v_15_B.Switch1) - fabs
                (load_arduino_v_15_B.psi_ref_p));
              if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else {
            if ((load_arduino_v_15_B.psi_ref_p < 0.0) &&
                (load_arduino_v_15_B.psi_ref_p >= -90.0)) {
              if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          }
        } else {
          if (load_arduino_v_15_B.a_n < load_arduino_v_15_B.angoloWP) {
            if (load_arduino_v_15_B.dist_fut > load_arduino_v_15_B.i) {
              load_arduino_v_15_B.Ato_selector = cos
                (load_arduino_v_15_B.WP_param_m[(int32_T)
                 (load_arduino_v_15_DW.Memory7_PreviousInput + 1.0) + 11] *
                 3.1415926535897931 / 180.0);
              load_arduino_v_15_B.Abs_i = (load_arduino_v_15_B.WP_param_m
                [(int32_T)(load_arduino_v_15_DW.Memory7_PreviousInput + 1.0) +
                14] - load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0;
              load_arduino_v_15_B.Switch1 = rt_atan2d_snf(sin
                (load_arduino_v_15_B.Abs_i) * load_arduino_v_15_B.Ato_selector,
                sin(load_arduino_v_15_B.WP_param_m[(int32_T)
                    (load_arduino_v_15_DW.Memory7_PreviousInput + 1.0) + 11] *
                    3.1415926535897931 / 180.0) * load_arduino_v_15_B.Abs1 - cos
                (load_arduino_v_15_B.Abs_i) * (sin(load_arduino_v_15_B.Gain_g *
                3.1415926535897931 / 180.0) * load_arduino_v_15_B.Ato_selector))
                * 180.0 / 3.1415926535897931;
              load_arduino_v_15_DW.Memory7_PreviousInput++;
            } else if (load_arduino_v_15_DW.Memory7_PreviousInput < 2.0) {
              load_arduino_v_15_DW.Memory7_PreviousInput += 2.0;
            } else {
              load_arduino_v_15_B.h_comandato = load_arduino_v_15_DW.PrevY + 0.4;
              load_arduino_v_15_B.Switch1 = load_arduino_v_15_B.Gain_nr + 36.6;
              load_arduino_v_15_DW.flag_m = 1.0;
            }
          }
        }
      }
    } else {
      load_arduino_v_15_B.Switch1 = rt_atan2d_snf(sin
        ((load_arduino_v_15_B.WP_param_m[(int32_T)
          load_arduino_v_15_DW.Memory7_PreviousInput + 14] -
          load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_15_B.WP_param_m[(int32_T)
         load_arduino_v_15_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_15_B.WP_param_m[(int32_T)
                     load_arduino_v_15_DW.Memory7_PreviousInput + 11] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_15_B.WP_param_m[(int32_T)
         load_arduino_v_15_DW.Memory7_PreviousInput + 11] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_15_B.Gain_g * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_15_B.WP_param_m[(int32_T)
             load_arduino_v_15_DW.Memory7_PreviousInput + 14] -
             load_arduino_v_15_B.Gain_dw) * 3.1415926535897931 / 180.0)) * 180.0
        / 3.1415926535897931;
      if ((!(load_arduino_v_15_B.dist < load_arduino_v_15_B.soglia_dist)) ||
          (!(load_arduino_v_15_DW.flag_m == 0.0))) {
        if ((load_arduino_v_15_B.dist > load_arduino_v_15_B.soglia_dist) &&
            (load_arduino_v_15_B.a_n > 40.0) && (load_arduino_v_15_DW.flag_m ==
             0.0)) {
          load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.Switch1 -
            load_arduino_v_15_B.psi_ref_p);
          if ((load_arduino_v_15_B.psi_ref_p <= 90.0) &&
              (load_arduino_v_15_B.psi_ref_p >= 0.0)) {
            if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
              load_arduino_v_15_B.Switch1 += 1.3 *
                load_arduino_v_15_B.Ato_selector;
            } else {
              if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 -= 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p <= 180.0) &&
                     (load_arduino_v_15_B.psi_ref_p > 90.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.Switch1 >
                0.0) {
              if ((load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.Switch1 < -90.0) &&
                   (load_arduino_v_15_B.Switch1 > -180.0))) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 - fabs
                (load_arduino_v_15_B.Switch1)) - load_arduino_v_15_B.psi_ref_p);
              if ((load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.Switch1 < -90.0) &&
                   (load_arduino_v_15_B.Switch1 > -180.0))) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p < -90.0) &&
                     (load_arduino_v_15_B.psi_ref_p >= -180.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.Switch1 >
                0.0) {
              if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 -
                load_arduino_v_15_B.Switch1) - fabs
                (load_arduino_v_15_B.psi_ref_p));
              if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else {
            if ((load_arduino_v_15_B.psi_ref_p < 0.0) &&
                (load_arduino_v_15_B.psi_ref_p >= -90.0)) {
              if (load_arduino_v_15_B.Switch1 > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.Switch1 += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.Switch1 < load_arduino_v_15_B.psi_ref_p)
                {
                  load_arduino_v_15_B.Switch1 -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          }
        } else {
          load_arduino_v_15_B.h_comandato = load_arduino_v_15_DW.PrevY + 0.4;
          load_arduino_v_15_B.Switch1 = load_arduino_v_15_B.Gain_nr + 36.6;
          load_arduino_v_15_DW.flag_m = 1.0;
        }
      }
    }

    if ((load_arduino_v_15_B.DeadZone == 0.0) &&
        (load_arduino_v_15_B.Saturation_h == 0.0) &&
        (load_arduino_v_15_B.h_comandato == 0.0)) {
      load_arduino_v_15_B.Switch1 = load_arduino_v_15_B.Gain_nr + 36.6;
    }

    if (!(load_arduino_v_15_B.modo == 4.0)) {
      load_arduino_v_15_DW.Memory7_PreviousInput = 1.0;
    }

    /* End of MATLAB Function: '<S455>/ALLINEAMENTO' */

    /* Abs: '<S455>/Abs1' */
    load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.Abs1_a);

    /* Chart: '<S455>/Chart1' incorporates:
     *  Memory: '<S455>/Memory1'
     *  Memory: '<S455>/Memory2'
     *  Memory: '<S455>/Memory5'
     */
    if (load_arduino_v_15_DW.is_active_c17_load_arduino_v_15 == 0U) {
      load_arduino_v_15_DW.is_active_c17_load_arduino_v_15 = 1U;
      load_arduino_v_15_B.maneuver_selector = 1.0;
      load_arduino_v_15_B.landing_selector = 0.0;
      load_arduino_v_15_B.trig_approach = 0.0;
      load_arduino_v_15_B.trig_flare = 0.0;
      load_arduino_v_15_B.approach_selector = 1.0;
      load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
        load_arduino_v_1_IN_Allignment1;
    } else {
      switch (load_arduino_v_15_DW.is_c17_load_arduino_v_15) {
       case load_arduino_v_15_IN_Abort:
        load_arduino_v_15_B.maneuver_selector = 1.0;
        load_arduino_v_15_B.landing_selector = 0.0;
        load_arduino_v_15_B.trig_approach = 0.0;
        load_arduino_v_15_B.trig_flare = 0.0;
        load_arduino_v_15_B.approach_selector = 0.0;
        break;

       case load_arduino_v_15_IN_Allignment:
        if ((load_arduino_v_15_DW.PrevY > 35.0) && (load_arduino_v_15_DW.PrevY <
             60.0) && (load_arduino_v_15_B.Ato_selector <=
                       load_arduino_v_15_DW.PrevY * 19.081136687728211 + 100.0) &&
            (load_arduino_v_15_B.Ato_selector >= load_arduino_v_15_DW.PrevY *
             14.300666256711928 + 100.0) &&
            (load_arduino_v_15_DW.Memory7_PreviousInput > 1.0)) {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_15_IN_Approach;
        } else if (load_arduino_v_15_B.modo != 4.0) {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_1_IN_Allignment1;
        } else {
          load_arduino_v_15_B.trig_flare = 0.0;
          load_arduino_v_15_B.approach_selector = 0.0;
          load_arduino_v_15_B.maneuver_selector = 1.0;
          load_arduino_v_15_B.landing_selector = 0.0;
          load_arduino_v_15_B.trig_approach = 0.0;
        }
        break;

       case load_arduino_v_1_IN_Allignment1:
        if (load_arduino_v_15_B.modo == 4.0) {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_15_IN_Allignment;
        } else {
          load_arduino_v_15_B.maneuver_selector = 1.0;
          load_arduino_v_15_B.landing_selector = 0.0;
          load_arduino_v_15_B.trig_approach = 0.0;
          load_arduino_v_15_B.trig_flare = 0.0;
          load_arduino_v_15_B.approach_selector = 0.0;
        }
        break;

       case load_arduino_v_15_IN_Approach:
        if ((load_arduino_v_15_B.Abs1_a >=
             load_arduino_v_15_DW.Memory5_PreviousInput) &&
            ((load_arduino_v_15_DW.PrevY <=
              load_arduino_v_15_DW.Memory1_PreviousInput_i + 1.5) ||
             (load_arduino_v_15_DW.PrevY >
              load_arduino_v_15_DW.Memory1_PreviousInput_i - 1.0))) {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_15_IN_Flare;
        } else if (load_arduino_v_15_B.modo != 4.0) {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_1_IN_Allignment1;
        } else if (load_arduino_v_15_DW.Memory2_PreviousInput_o == 1.0) {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_15_IN_Abort;
        } else {
          load_arduino_v_15_B.trig_flare = 0.0;
          load_arduino_v_15_B.trig_approach = 1.0;
          load_arduino_v_15_B.approach_selector = 1.0;
          load_arduino_v_15_B.landing_selector = 1.0;
          load_arduino_v_15_B.maneuver_selector = 2.0;
        }
        break;

       default:
        /* case IN_Flare: */
        if ((load_arduino_v_15_B.rtb_Gain1_idx_1 < 3.0) ||
            (!(load_arduino_v_15_B.modo != 4.0))) {
          load_arduino_v_15_B.trig_approach = 0.0;
          load_arduino_v_15_B.trig_flare = 1.0;
          load_arduino_v_15_B.approach_selector = 0.0;
          load_arduino_v_15_B.landing_selector = 2.0;
          load_arduino_v_15_B.maneuver_selector = 3.0;
        } else {
          load_arduino_v_15_DW.is_c17_load_arduino_v_15 =
            load_arduino_v_1_IN_Allignment1;
        }
        break;
      }
    }

    /* End of Chart: '<S455>/Chart1' */

    /* Outputs for Triggered SubSystem: '<S455>/Sample and Hold' incorporates:
     *  TriggerPort: '<S480>/Trigger'
     */
    load_arduino_v_15_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &load_arduino_v_15_PrevZCX.SampleandHold_Trig_ZCE,
      (load_arduino_v_15_B.approach_selector));
    if (load_arduino_v_15_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S480>/In' incorporates:
       *  Abs: '<S455>/Abs2'
       *  Constant: '<S455>/Constant4'
       *  Sum: '<S472>/Sum'
       *  UnaryMinus: '<S472>/Ze2height'
       */
      load_arduino_v_15_B.In[0] = fabs(-(load_arduino_v_15_DW.PrevY +
        load_arduino_v_15_P.Constant4_Value_n));
      load_arduino_v_15_B.In[1] = load_arduino_v_15_B.Abs1_a;
    }

    /* End of Outputs for SubSystem: '<S455>/Sample and Hold' */

    /* Outputs for Enabled SubSystem: '<S455>/APPROACH' incorporates:
     *  EnablePort: '<S466>/Enable'
     */
    if (load_arduino_v_15_B.trig_approach > 0.0) {
      /* Product: '<S466>/Divide' incorporates:
       *  Constant: '<S466>/x_g0'
       *  Sum: '<S466>/Sum'
       */
      load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.In[0] /
        (load_arduino_v_15_B.In[1] - load_arduino_v_15_P.x_g0_Value);

      /* Abs: '<S466>/Abs' incorporates:
       *  Trigonometry: '<S466>/Atan'
       */
      load_arduino_v_15_B.Abs_i = fabs(atan(load_arduino_v_15_B.Abs1));

      /* DiscreteIntegrator: '<S466>/Discrete-Time Integrator' */
      if ((load_arduino_v_15_B.trig_approach > 0.0) &&
          (load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h <= 0)) {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m =
          load_arduino_v_15_P.DiscreteTimeIntegrator_IC;
      }

      if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m >=
          load_arduino_v_15_P.DiscreteTimeIntegrator_UpperSat) {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m =
          load_arduino_v_15_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m <=
            load_arduino_v_15_P.DiscreteTimeIntegrator_LowerSat) {
          load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m =
            load_arduino_v_15_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      /* Switch: '<S466>/Switch' incorporates:
       *  Constant: '<S466>/Constant3'
       *  Constant: '<S466>/Constant4'
       *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator'
       */
      if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m >
          load_arduino_v_15_P.Switch_Threshold_a) {
        load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant3_Value_k;
      } else {
        load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant4_Value_e;
      }

      /* End of Switch: '<S466>/Switch' */

      /* MATLAB Function: '<S466>/MATLAB Function' */
      load_arduino_v_15_B.ATO = 0;
      if ((!load_arduino_v_15_DW.x_not_empty) ||
          (load_arduino_v_15_B.Ato_selector == 0.0)) {
        load_arduino_v_15_DW.x[0] = 3.0;
        load_arduino_v_15_DW.x[1] = -200.0;
        load_arduino_v_15_DW.x[2] = 0.01;
        load_arduino_v_15_DW.x[3] = -2.0;
        load_arduino_v_15_DW.x_not_empty = true;
      }

      load_arduino_v_15_DW.x_new_not_empty =
        ((!load_arduino_v_15_DW.x_new_not_empty) ||
         (load_arduino_v_15_B.Ato_selector == 0.0) ||
         load_arduino_v_15_DW.x_new_not_empty);
      if ((!load_arduino_v_15_DW.eps_not_empty) ||
          (load_arduino_v_15_B.Ato_selector == 0.0)) {
        load_arduino_v_15_DW.eps[0] = 1.0;
        load_arduino_v_15_DW.eps[1] = 1.0;
        load_arduino_v_15_DW.eps[2] = 1.0;
        load_arduino_v_15_DW.eps[3] = 1.0;
        load_arduino_v_15_DW.eps_not_empty = true;
      }

      if ((!load_arduino_v_15_DW.cycle_count_not_empty) ||
          (load_arduino_v_15_B.Ato_selector == 0.0)) {
        load_arduino_v_15_DW.cycle_count = 0.0;
        load_arduino_v_15_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(load_arduino_v_15_DW.eps[0] < 0.1)) ||
                           ((!(load_arduino_v_15_DW.eps[1] < 0.1)) ||
                            ((!(load_arduino_v_15_DW.eps[2] < 0.1)) ||
                             (!(load_arduino_v_15_DW.eps[3] < 0.1)))))) {
        memset(&load_arduino_v_15_B.a[0], 0, sizeof(real_T) << 4U);
        load_arduino_v_15_B.e = exp((30.0 - load_arduino_v_15_DW.x[1]) *
          -load_arduino_v_15_DW.x[2]);
        load_arduino_v_15_B.Gain_nr = tan(load_arduino_v_15_B.Abs_i);
        load_arduino_v_15_B.A[0] = 1.0;
        load_arduino_v_15_B.A[4] = load_arduino_v_15_B.Gain_nr;
        load_arduino_v_15_B.A[8] = 0.0;
        load_arduino_v_15_B.A[12] = 0.0;
        load_arduino_v_15_B.A[1] = load_arduino_v_15_DW.x[2];
        load_arduino_v_15_B.A[5] = 0.0;
        load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_DW.x[0] -
          load_arduino_v_15_DW.x[3];
        load_arduino_v_15_B.A[9] = load_arduino_v_15_B.psi_ref_p;
        load_arduino_v_15_B.A[13] = -load_arduino_v_15_DW.x[2];
        load_arduino_v_15_B.A[2] = load_arduino_v_15_B.e;
        load_arduino_v_15_B.h_comandato = load_arduino_v_15_B.psi_ref_p *
          load_arduino_v_15_DW.x[2];
        load_arduino_v_15_B.A[6] = load_arduino_v_15_B.h_comandato *
          load_arduino_v_15_B.e;
        load_arduino_v_15_B.A[10] = load_arduino_v_15_B.psi_ref_p *
          (load_arduino_v_15_DW.x[1] - 30.0) * load_arduino_v_15_B.e;
        load_arduino_v_15_B.A[14] = 1.0;
        load_arduino_v_15_B.A[3] = load_arduino_v_15_DW.x[2] * 18.0 *
          load_arduino_v_15_B.e;
        load_arduino_v_15_B.A[7] = load_arduino_v_15_B.psi_ref_p *
          (load_arduino_v_15_DW.x[2] * load_arduino_v_15_DW.x[2]) * 18.0 *
          load_arduino_v_15_B.e;
        load_arduino_v_15_B.a_n = load_arduino_v_15_B.h_comandato * 18.0;
        load_arduino_v_15_B.A[11] = load_arduino_v_15_B.a_n *
          (load_arduino_v_15_DW.x[1] - 30.0) * load_arduino_v_15_B.e +
          load_arduino_v_15_B.psi_ref_p * 18.0 * load_arduino_v_15_B.e;
        load_arduino_v_15_B.A[15] = -load_arduino_v_15_DW.x[2] * 18.0 *
          load_arduino_v_15_B.e;
        load_arduino_v_15_B.ipiv[0] = 1;
        load_arduino_v_15_B.ipiv[1] = 2;
        load_arduino_v_15_B.ipiv[2] = 3;
        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 3;
             load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_B.caso = load_arduino_v_15_B.pipk * 5;
          load_arduino_v_15_B.i = 0;
          load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.caso;
          load_arduino_v_15_B.Ato_selector = fabs
            (load_arduino_v_15_B.A[load_arduino_v_15_B.caso]);
          load_arduino_v_15_B.jy = 2;
          while (load_arduino_v_15_B.jy <= 4 - load_arduino_v_15_B.pipk) {
            load_arduino_v_15_B.soglia_dist++;
            load_arduino_v_15_B.DeadZone = fabs
              (load_arduino_v_15_B.A[load_arduino_v_15_B.soglia_dist]);
            if (load_arduino_v_15_B.DeadZone > load_arduino_v_15_B.Ato_selector)
            {
              load_arduino_v_15_B.i = load_arduino_v_15_B.jy - 1;
              load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.DeadZone;
            }

            load_arduino_v_15_B.jy++;
          }

          if (load_arduino_v_15_B.A[load_arduino_v_15_B.caso +
              load_arduino_v_15_B.i] != 0.0) {
            if (load_arduino_v_15_B.i != 0) {
              load_arduino_v_15_B.i += load_arduino_v_15_B.pipk;
              load_arduino_v_15_B.ipiv[load_arduino_v_15_B.pipk] = (int8_T)
                (load_arduino_v_15_B.i + 1);
              load_arduino_v_15_B.Ato_selector =
                load_arduino_v_15_B.A[load_arduino_v_15_B.pipk];
              load_arduino_v_15_B.A[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.A[load_arduino_v_15_B.i];
              load_arduino_v_15_B.A[load_arduino_v_15_B.i] =
                load_arduino_v_15_B.Ato_selector;
              load_arduino_v_15_B.Ato_selector =
                load_arduino_v_15_B.A[load_arduino_v_15_B.pipk + 4];
              load_arduino_v_15_B.A[load_arduino_v_15_B.pipk + 4] =
                load_arduino_v_15_B.A[load_arduino_v_15_B.i + 4];
              load_arduino_v_15_B.A[load_arduino_v_15_B.i + 4] =
                load_arduino_v_15_B.Ato_selector;
              load_arduino_v_15_B.Ato_selector =
                load_arduino_v_15_B.A[load_arduino_v_15_B.pipk + 8];
              load_arduino_v_15_B.A[load_arduino_v_15_B.pipk + 8] =
                load_arduino_v_15_B.A[load_arduino_v_15_B.i + 8];
              load_arduino_v_15_B.A[load_arduino_v_15_B.i + 8] =
                load_arduino_v_15_B.Ato_selector;
              load_arduino_v_15_B.Ato_selector =
                load_arduino_v_15_B.A[load_arduino_v_15_B.pipk + 12];
              load_arduino_v_15_B.A[load_arduino_v_15_B.pipk + 12] =
                load_arduino_v_15_B.A[load_arduino_v_15_B.i + 12];
              load_arduino_v_15_B.A[load_arduino_v_15_B.i + 12] =
                load_arduino_v_15_B.Ato_selector;
            }

            load_arduino_v_15_B.soglia_dist = (load_arduino_v_15_B.caso -
              load_arduino_v_15_B.pipk) + 4;
            load_arduino_v_15_B.i = load_arduino_v_15_B.caso + 1;
            while (load_arduino_v_15_B.i + 1 <= load_arduino_v_15_B.soglia_dist)
            {
              load_arduino_v_15_B.A[load_arduino_v_15_B.i] /=
                load_arduino_v_15_B.A[load_arduino_v_15_B.caso];
              load_arduino_v_15_B.i++;
            }
          }

          load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.caso;
          load_arduino_v_15_B.jy = load_arduino_v_15_B.caso + 4;
          load_arduino_v_15_B.c = 0;
          while (load_arduino_v_15_B.c <= 2 - load_arduino_v_15_B.pipk) {
            if (load_arduino_v_15_B.A[load_arduino_v_15_B.jy] != 0.0) {
              load_arduino_v_15_B.Ato_selector =
                -load_arduino_v_15_B.A[load_arduino_v_15_B.jy];
              load_arduino_v_15_B.c_ix = load_arduino_v_15_B.caso + 1;
              load_arduino_v_15_B.i = (load_arduino_v_15_B.soglia_dist -
                load_arduino_v_15_B.pipk) + 8;
              load_arduino_v_15_B.ijA = load_arduino_v_15_B.soglia_dist + 5;
              while (load_arduino_v_15_B.ijA + 1 <= load_arduino_v_15_B.i) {
                load_arduino_v_15_B.A[load_arduino_v_15_B.ijA] +=
                  load_arduino_v_15_B.A[load_arduino_v_15_B.c_ix] *
                  load_arduino_v_15_B.Ato_selector;
                load_arduino_v_15_B.c_ix++;
                load_arduino_v_15_B.ijA++;
              }
            }

            load_arduino_v_15_B.jy += 4;
            load_arduino_v_15_B.soglia_dist += 4;
            load_arduino_v_15_B.c++;
          }
        }

        load_arduino_v_15_B.p[0] = 1;
        load_arduino_v_15_B.p[1] = 2;
        load_arduino_v_15_B.p[2] = 3;
        load_arduino_v_15_B.p[3] = 4;
        if (load_arduino_v_15_B.ipiv[0] > 1) {
          load_arduino_v_15_B.pipk =
            load_arduino_v_15_B.p[load_arduino_v_15_B.ipiv[0] - 1];
          load_arduino_v_15_B.p[load_arduino_v_15_B.ipiv[0] - 1] = 1;
          load_arduino_v_15_B.p[0] = (int8_T)load_arduino_v_15_B.pipk;
        }

        if (load_arduino_v_15_B.ipiv[1] > 2) {
          load_arduino_v_15_B.pipk =
            load_arduino_v_15_B.p[load_arduino_v_15_B.ipiv[1] - 1];
          load_arduino_v_15_B.p[load_arduino_v_15_B.ipiv[1] - 1] =
            load_arduino_v_15_B.p[1];
          load_arduino_v_15_B.p[1] = (int8_T)load_arduino_v_15_B.pipk;
        }

        if (load_arduino_v_15_B.ipiv[2] > 3) {
          load_arduino_v_15_B.pipk =
            load_arduino_v_15_B.p[load_arduino_v_15_B.ipiv[2] - 1];
          load_arduino_v_15_B.p[load_arduino_v_15_B.ipiv[2] - 1] =
            load_arduino_v_15_B.p[2];
          load_arduino_v_15_B.p[2] = (int8_T)load_arduino_v_15_B.pipk;
        }

        load_arduino_v_15_B.c = load_arduino_v_15_B.p[0] - 1;
        load_arduino_v_15_B.a[(load_arduino_v_15_B.p[0] - 1) << 2] = 1.0;
        load_arduino_v_15_B.caso = 0;
        while (load_arduino_v_15_B.caso + 1 < 5) {
          load_arduino_v_15_B.pipk = load_arduino_v_15_B.c << 2;
          load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk +
            load_arduino_v_15_B.caso;
          if (load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] != 0.0) {
            load_arduino_v_15_B.i = load_arduino_v_15_B.caso + 1;
            while (load_arduino_v_15_B.i + 1 < 5) {
              load_arduino_v_15_B.jy = load_arduino_v_15_B.pipk +
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.a[load_arduino_v_15_B.jy] -=
                load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] *
                load_arduino_v_15_B.A[(load_arduino_v_15_B.caso << 2) +
                load_arduino_v_15_B.i];
              load_arduino_v_15_B.i++;
            }
          }

          load_arduino_v_15_B.caso++;
        }

        load_arduino_v_15_B.c = load_arduino_v_15_B.p[1] - 1;
        load_arduino_v_15_B.a[((load_arduino_v_15_B.p[1] - 1) << 2) + 1] = 1.0;
        load_arduino_v_15_B.caso = 1;
        while (load_arduino_v_15_B.caso + 1 < 5) {
          load_arduino_v_15_B.pipk = load_arduino_v_15_B.c << 2;
          load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk +
            load_arduino_v_15_B.caso;
          if (load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] != 0.0) {
            load_arduino_v_15_B.i = load_arduino_v_15_B.caso + 1;
            while (load_arduino_v_15_B.i + 1 < 5) {
              load_arduino_v_15_B.jy = load_arduino_v_15_B.pipk +
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.a[load_arduino_v_15_B.jy] -=
                load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] *
                load_arduino_v_15_B.A[(load_arduino_v_15_B.caso << 2) +
                load_arduino_v_15_B.i];
              load_arduino_v_15_B.i++;
            }
          }

          load_arduino_v_15_B.caso++;
        }

        load_arduino_v_15_B.c = load_arduino_v_15_B.p[2] - 1;
        load_arduino_v_15_B.a[((load_arduino_v_15_B.p[2] - 1) << 2) + 2] = 1.0;
        load_arduino_v_15_B.caso = 2;
        while (load_arduino_v_15_B.caso + 1 < 5) {
          load_arduino_v_15_B.pipk = load_arduino_v_15_B.c << 2;
          load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk +
            load_arduino_v_15_B.caso;
          if (load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] != 0.0) {
            load_arduino_v_15_B.i = load_arduino_v_15_B.caso + 1;
            while (load_arduino_v_15_B.i + 1 < 5) {
              load_arduino_v_15_B.jy = load_arduino_v_15_B.pipk +
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.a[load_arduino_v_15_B.jy] -=
                load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] *
                load_arduino_v_15_B.A[(load_arduino_v_15_B.caso << 2) +
                load_arduino_v_15_B.i];
              load_arduino_v_15_B.i++;
            }
          }

          load_arduino_v_15_B.caso++;
        }

        load_arduino_v_15_B.jy = (load_arduino_v_15_B.p[3] - 1) << 2;
        load_arduino_v_15_B.a[load_arduino_v_15_B.jy + 3] = 1.0;
        load_arduino_v_15_B.caso = 3;
        while (load_arduino_v_15_B.caso + 1 < 5) {
          load_arduino_v_15_B.pipk = load_arduino_v_15_B.jy +
            load_arduino_v_15_B.caso;
          if (load_arduino_v_15_B.a[load_arduino_v_15_B.pipk] != 0.0) {
            load_arduino_v_15_B.i = load_arduino_v_15_B.caso + 1;
            while (load_arduino_v_15_B.i + 1 < 5) {
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.jy +
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.a[load_arduino_v_15_B.soglia_dist] -=
                load_arduino_v_15_B.a[load_arduino_v_15_B.pipk] *
                load_arduino_v_15_B.A[(load_arduino_v_15_B.caso << 2) +
                load_arduino_v_15_B.i];
              load_arduino_v_15_B.i++;
            }
          }

          load_arduino_v_15_B.caso++;
        }

        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 4;
             load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_B.i = load_arduino_v_15_B.pipk << 2;
          load_arduino_v_15_B.Ato_selector =
            load_arduino_v_15_B.a[load_arduino_v_15_B.i + 3];
          if (load_arduino_v_15_B.Ato_selector != 0.0) {
            load_arduino_v_15_B.a[load_arduino_v_15_B.i + 3] =
              load_arduino_v_15_B.Ato_selector / load_arduino_v_15_B.A[15];
            load_arduino_v_15_B.caso = 0;
            while (load_arduino_v_15_B.caso <= 2) {
              load_arduino_v_15_B.jy = load_arduino_v_15_B.caso +
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.a[load_arduino_v_15_B.jy] -=
                load_arduino_v_15_B.a[load_arduino_v_15_B.i + 3] *
                load_arduino_v_15_B.A[load_arduino_v_15_B.caso + 12];
              load_arduino_v_15_B.caso++;
            }
          }

          load_arduino_v_15_B.Ato_selector =
            load_arduino_v_15_B.a[load_arduino_v_15_B.i + 2];
          if (load_arduino_v_15_B.Ato_selector != 0.0) {
            load_arduino_v_15_B.a[load_arduino_v_15_B.i + 2] =
              load_arduino_v_15_B.Ato_selector / load_arduino_v_15_B.A[10];
            load_arduino_v_15_B.caso = 0;
            while (load_arduino_v_15_B.caso <= 1) {
              load_arduino_v_15_B.jy = load_arduino_v_15_B.caso +
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.a[load_arduino_v_15_B.jy] -=
                load_arduino_v_15_B.a[load_arduino_v_15_B.i + 2] *
                load_arduino_v_15_B.A[load_arduino_v_15_B.caso + 8];
              load_arduino_v_15_B.caso++;
            }
          }

          load_arduino_v_15_B.Ato_selector =
            load_arduino_v_15_B.a[load_arduino_v_15_B.i + 1];
          if (load_arduino_v_15_B.Ato_selector != 0.0) {
            load_arduino_v_15_B.a[load_arduino_v_15_B.i + 1] =
              load_arduino_v_15_B.Ato_selector / load_arduino_v_15_B.A[5];
            load_arduino_v_15_B.a[load_arduino_v_15_B.i] -=
              load_arduino_v_15_B.a[load_arduino_v_15_B.i + 1] *
              load_arduino_v_15_B.A[4];
          }

          if (load_arduino_v_15_B.a[load_arduino_v_15_B.i] != 0.0) {
            load_arduino_v_15_B.a[load_arduino_v_15_B.i] /=
              load_arduino_v_15_B.A[0];
          }
        }

        load_arduino_v_15_B.Ato_selector = (load_arduino_v_15_DW.x[1] -
          load_arduino_v_15_P.x_g0_Value) * load_arduino_v_15_B.Gain_nr +
          load_arduino_v_15_DW.x[0];
        load_arduino_v_15_B.Gain_nr = load_arduino_v_15_B.h_comandato -
          load_arduino_v_15_B.Gain_nr;
        load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.psi_ref_p *
          load_arduino_v_15_B.e + load_arduino_v_15_DW.x[3];
        load_arduino_v_15_B.e = load_arduino_v_15_B.a_n * load_arduino_v_15_B.e
          + -0.05;
        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 4;
             load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_B.x_new[load_arduino_v_15_B.pipk] =
            load_arduino_v_15_DW.x[load_arduino_v_15_B.pipk] -
            (((load_arduino_v_15_B.a[load_arduino_v_15_B.pipk + 4] *
               load_arduino_v_15_B.Gain_nr +
               load_arduino_v_15_B.a[load_arduino_v_15_B.pipk] *
               load_arduino_v_15_B.Ato_selector) +
              load_arduino_v_15_B.a[load_arduino_v_15_B.pipk + 8] *
              load_arduino_v_15_B.psi_ref_p) +
             load_arduino_v_15_B.a[load_arduino_v_15_B.pipk + 12] *
             load_arduino_v_15_B.e);
        }

        load_arduino_v_15_DW.eps[0] = fabs(load_arduino_v_15_B.x_new[0] -
          load_arduino_v_15_DW.x[0]);
        load_arduino_v_15_DW.eps[1] = fabs(load_arduino_v_15_B.x_new[1] -
          load_arduino_v_15_DW.x[1]);
        load_arduino_v_15_DW.eps[2] = fabs(load_arduino_v_15_B.x_new[2] -
          load_arduino_v_15_DW.x[2]);
        load_arduino_v_15_DW.eps[3] = fabs(load_arduino_v_15_B.x_new[3] -
          load_arduino_v_15_DW.x[3]);
        load_arduino_v_15_DW.x[0] = load_arduino_v_15_B.x_new[0];
        load_arduino_v_15_DW.x[1] = load_arduino_v_15_B.x_new[1];
        load_arduino_v_15_DW.x[2] = load_arduino_v_15_B.x_new[2];
        load_arduino_v_15_DW.x[3] = load_arduino_v_15_B.x_new[3];
        load_arduino_v_15_DW.cycle_count++;
        if (load_arduino_v_15_DW.cycle_count > 10.0) {
          load_arduino_v_15_B.ATO = 1;
          exitg1 = true;
        }
      }

      if ((load_arduino_v_15_DW.eps[0] < 0.1) && (load_arduino_v_15_DW.eps[1] <
           0.1) && (load_arduino_v_15_DW.eps[2] < 0.1) &&
          (load_arduino_v_15_DW.eps[3] < 0.1)) {
        load_arduino_v_15_B.h_f_out = load_arduino_v_15_DW.x[0];
        load_arduino_v_15_B.x_f_out = load_arduino_v_15_DW.x[1];
        load_arduino_v_15_B.k_x_out = load_arduino_v_15_DW.x[2];
        load_arduino_v_15_B.h_c_out = load_arduino_v_15_DW.x[3];
      } else {
        load_arduino_v_15_B.h_f_out = 0.0;
        load_arduino_v_15_B.x_f_out = 0.0;
        load_arduino_v_15_B.k_x_out = 0.0;
        load_arduino_v_15_B.h_c_out = 0.0;
      }

      load_arduino_v_15_B.no_solution = load_arduino_v_15_B.ATO;

      /* End of MATLAB Function: '<S466>/MATLAB Function' */

      /* Product: '<S466>/Multiply' incorporates:
       *  Constant: '<S466>/x_g0'
       *  Gain: '<S466>/Gain'
       *  Sum: '<S466>/Sum1'
       */
      load_arduino_v_15_B.Multiply = (load_arduino_v_15_B.Abs1_a -
        load_arduino_v_15_P.x_g0_Value) * load_arduino_v_15_P.Gain_Gain_oz *
        load_arduino_v_15_B.Abs1;

      /* Product: '<S466>/Multiply1' */
      load_arduino_v_15_B.Multiply1 = load_arduino_v_15_B.rtb_Gain4_idx_0 *
        load_arduino_v_15_B.Abs1;

      /* Constant: '<S466>/Constant1' */
      load_arduino_v_15_B.Constant1_l = load_arduino_v_15_P.V_stall * 1.2;

      /* Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S466>/Constant2'
       */
      load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m +=
        load_arduino_v_15_P.DiscreteTimeIntegrator_gainval *
        load_arduino_v_15_P.Constant2_Value_a;
      if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m >=
          load_arduino_v_15_P.DiscreteTimeIntegrator_UpperSat) {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m =
          load_arduino_v_15_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m <=
            load_arduino_v_15_P.DiscreteTimeIntegrator_LowerSat) {
          load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m =
            load_arduino_v_15_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      if (load_arduino_v_15_B.trig_approach > 0.0) {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h = 1;
      } else if (load_arduino_v_15_B.trig_approach < 0.0) {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h = -1;
      } else if (load_arduino_v_15_B.trig_approach == 0.0) {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h = 0;
      } else {
        load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator' */
    }

    /* End of Outputs for SubSystem: '<S455>/APPROACH' */

    /* Outputs for Enabled SubSystem: '<S455>/FLARE' incorporates:
     *  EnablePort: '<S470>/Enable'
     */
    if (load_arduino_v_15_B.trig_flare > 0.0) {
      /* Constant: '<S470>/Constant1' */
      load_arduino_v_15_B.Constant1 = load_arduino_v_15_P.V_stall * 1.2;

      /* Product: '<S470>/Multiply' incorporates:
       *  Product: '<S470>/Multiply2'
       *  Sum: '<S470>/Sum'
       */
      load_arduino_v_15_B.Ato_selector = (load_arduino_v_15_B.Abs1_a -
        load_arduino_v_15_B.x_f_out) * load_arduino_v_15_B.k_x_out;

      /* Sum: '<S470>/Sum1' incorporates:
       *  Sum: '<S470>/Sum4'
       */
      load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.h_f_out -
        load_arduino_v_15_B.h_c_out;

      /* Sum: '<S470>/Sum2' incorporates:
       *  Gain: '<S470>/Gain'
       *  Math: '<S470>/Exp'
       *  Product: '<S470>/Multiply'
       *  Product: '<S470>/Multiply1'
       *  Sum: '<S470>/Sum1'
       *
       * About '<S470>/Exp':
       *  Operator: exp
       */
      load_arduino_v_15_B.Sum2 = exp(load_arduino_v_15_B.Ato_selector *
        load_arduino_v_15_P.Gain_Gain_hs) * load_arduino_v_15_B.Abs1 +
        load_arduino_v_15_B.h_c_out;

      /* Gain: '<S470>/Gain2' incorporates:
       *  Gain: '<S470>/Gain1'
       *  Math: '<S470>/Exp1'
       *  Product: '<S470>/Multiply3'
       *  Product: '<S470>/Multiply4'
       *
       * About '<S470>/Exp1':
       *  Operator: exp
       */
      load_arduino_v_15_B.Gain2 = exp(load_arduino_v_15_B.Ato_selector *
        load_arduino_v_15_P.Gain1_Gain_k) * (load_arduino_v_15_B.Abs1 *
        load_arduino_v_15_B.rtb_Gain4_idx_0 * load_arduino_v_15_B.k_x_out) *
        load_arduino_v_15_P.Gain2_Gain;
    }

    /* End of Outputs for SubSystem: '<S455>/FLARE' */

    /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation5' */
    switch ((int32_T)load_arduino_v_15_B.maneuver_selector) {
     case 1:
      /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation5' incorporates:
       *  Constant: '<S455>/Constant6'
       */
      load_arduino_v_15_B.velocita = load_arduino_v_15_P.V_stall * 1.4;
      break;

     case 2:
      /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation5' */
      load_arduino_v_15_B.velocita = load_arduino_v_15_B.Constant1_l;
      break;

     default:
      /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation5' */
      load_arduino_v_15_B.velocita = load_arduino_v_15_B.Constant1;
      break;
    }

    /* End of MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation5' */

    /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' */
    switch ((int32_T)load_arduino_v_15_B.maneuver_selector) {
     case 1:
      /* Switch: '<S455>/Switch' incorporates:
       *  Constant: '<S455>/Constant2'
       *  RelationalOperator: '<S455>/Relational Operator'
       */
      if (load_arduino_v_15_P.Constant2_Value_jb >= load_arduino_v_15_DW.PrevY)
      {
        /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' incorporates:
         *  Constant: '<S455>/Constant1'
         */
        load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna =
          load_arduino_v_15_P.Constant1_Value_c;
      } else {
        /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' incorporates:
         *  Constant: '<S455>/Constant7'
         */
        load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna =
          load_arduino_v_15_P.Constant7_Value;
      }

      /* End of Switch: '<S455>/Switch' */
      break;

     case 2:
      /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' */
      load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna =
        load_arduino_v_15_B.Multiply1;
      break;

     default:
      /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' */
      load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna =
        load_arduino_v_15_B.Gain2;
      break;
    }

    /* End of MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' */

    /* MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation4' incorporates:
     *  Abs: '<S455>/Abs3'
     *  Abs: '<S455>/Abs4'
     *  Constant: '<S455>/Constant2'
     */
    switch ((int32_T)load_arduino_v_15_B.maneuver_selector) {
     case 1:
      load_arduino_v_15_B.Abs1 = load_arduino_v_15_P.Constant2_Value_jb;
      break;

     case 2:
      load_arduino_v_15_B.Abs1 = fabs(load_arduino_v_15_B.Multiply);
      break;

     default:
      load_arduino_v_15_B.Abs1 = fabs(load_arduino_v_15_B.Sum2);
      break;
    }

    /* End of MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation4' */

    /* Sum: '<S455>/Sum' incorporates:
     *  Constant: '<S455>/latezza carrello'
     */
    load_arduino_v_15_B.QUOTA_n = load_arduino_v_15_B.Abs1 +
      load_arduino_v_15_P.latezzacarrello_Value;

    /* Switch: '<S455>/Switch2' incorporates:
     *  Constant: '<S455>/Constant3'
     *  Constant: '<S455>/Constant8'
     */
    if (load_arduino_v_15_DW.Memory7_PreviousInput >
        load_arduino_v_15_P.Switch2_Threshold_p) {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant3_Value_m;
    } else {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant8_Value;
    }

    /* End of Switch: '<S455>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S455>/INSEGUIMENTO CENTRO PISTA' incorporates:
     *  EnablePort: '<S471>/Enable'
     */
    if (load_arduino_v_15_B.Ato_selector > 0.0) {
      /* Gain: '<S471>/Gain1' incorporates:
       *  Product: '<S539>/x*sin'
       *  Product: '<S539>/y*cos'
       *  Sum: '<S539>/Sum3'
       */
      load_arduino_v_15_B.SumI1_ak = (load_arduino_v_15_B.Al_selector *
        load_arduino_v_15_B.Sum3 - load_arduino_v_15_B.SumI1_ak *
        load_arduino_v_15_B.Sum_gs) * load_arduino_v_15_P.Gain1_Gain_e;

      /* Product: '<S522>/NProd Out' incorporates:
       *  Constant: '<S471>/psi ref gain2'
       *  Constant: '<S471>/psi ref gain3'
       *  DiscreteIntegrator: '<S514>/Filter'
       *  Product: '<S513>/DProd Out'
       *  Sum: '<S514>/SumD'
       */
      load_arduino_v_15_B.Al_selector = (load_arduino_v_15_B.SumI1_ak *
        load_arduino_v_15_P.psirefgain2_Value -
        load_arduino_v_15_DW.Filter_DSTATE_g) *
        load_arduino_v_15_P.psirefgain3_Value;

      /* Gain: '<S487>/Gain' incorporates:
       *  Constant: '<S471>/psi ref gain'
       *  DiscreteIntegrator: '<S519>/Integrator'
       *  MATLAB Function: '<S455>/CALIBRATING_HOME_COORDINATES'
       *  Product: '<S524>/PProd Out'
       *  Sum: '<S471>/Sum3'
       *  Sum: '<S528>/Sum'
       */
      load_arduino_v_15_B.Gain = (load_arduino_v_15_B.rtb_Gain4_idx_1 -
        ((load_arduino_v_15_B.SumI1_ak * load_arduino_v_15_P.psirefgain_Value +
          load_arduino_v_15_DW.Integrator_DSTATE_o) +
         load_arduino_v_15_B.Al_selector)) * load_arduino_v_15_P.Gain_Gain_l;

      /* Update for DiscreteIntegrator: '<S514>/Filter' */
      load_arduino_v_15_DW.Filter_DSTATE_g += load_arduino_v_15_P.Filter_gainval
        * load_arduino_v_15_B.Al_selector;

      /* Update for DiscreteIntegrator: '<S519>/Integrator' incorporates:
       *  Constant: '<S471>/psi ref gain1'
       *  Product: '<S516>/IProd Out'
       */
      load_arduino_v_15_DW.Integrator_DSTATE_o += load_arduino_v_15_B.SumI1_ak *
        load_arduino_v_15_P.psirefgain1_Value *
        load_arduino_v_15_P.Integrator_gainval;
    }

    /* End of Outputs for SubSystem: '<S455>/INSEGUIMENTO CENTRO PISTA' */

    /* Switch: '<S455>/Switch1' */
    if (load_arduino_v_15_DW.Memory7_PreviousInput >
        load_arduino_v_15_P.Switch1_Threshold) {
      /* Switch: '<S455>/Switch1' */
      load_arduino_v_15_B.Switch1 = load_arduino_v_15_B.Gain;
    }

    /* End of Switch: '<S455>/Switch1' */

    /* Update for Memory: '<S455>/Memory5' */
    load_arduino_v_15_DW.Memory5_PreviousInput = load_arduino_v_15_B.x_f_out;

    /* Update for Memory: '<S455>/Memory1' */
    load_arduino_v_15_DW.Memory1_PreviousInput_i = load_arduino_v_15_B.h_f_out;

    /* Update for Memory: '<S455>/Memory2' */
    load_arduino_v_15_DW.Memory2_PreviousInput_o =
      load_arduino_v_15_B.no_solution;
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem1' */

  /* Sum: '<S594>/Sum2' incorporates:
   *  Constant: '<S594>/Constant8'
   *  Constant: '<S594>/Constant9'
   *  Sum: '<S598>/Sum1'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.attuatore_Amax -
    load_arduino_v_15_P.attuatore_Amin;

  /* Product: '<S594>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion8'
   *  DataTypeConversion: '<S9>/Data Type Conversion9'
   *  Product: '<S598>/Multiply'
   *  Sum: '<S594>/Sum1'
   */
  load_arduino_v_15_B.rtb_Gain4_idx_1 =
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[4] -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[5];

  /* Sum: '<S594>/Sum3' incorporates:
   *  Constant: '<S594>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion14'
   *  DataTypeConversion: '<S9>/Data Type Conversion9'
   *  Product: '<S594>/Divide'
   *  Product: '<S594>/Multiply'
   *  Sum: '<S594>/Sum'
   *  Sum: '<S594>/Sum2'
   */
  load_arduino_v_15_B.Sum3 = (real_T)(load_arduino_v_15_B.PWM_aileron -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[5]) /
    load_arduino_v_15_B.rtb_Gain4_idx_1 * load_arduino_v_15_B.Al_selector +
    load_arduino_v_15_P.attuatore_Amin;

  /* MATLAB Function: '<S40>/MATLAB Function' */
  if (load_arduino_v_15_B.modo == 3.0) {
    load_arduino_v_15_B.ATO = 1;
    load_arduino_v_15_B.pipk = 0;
  } else if (load_arduino_v_15_B.modo == 4.0) {
    load_arduino_v_15_B.pipk = 1;
    load_arduino_v_15_B.ATO = 0;
  } else {
    load_arduino_v_15_B.ATO = 0;
    load_arduino_v_15_B.pipk = 0;
  }

  /* DataTypeConversion: '<S1>/Data Tversion' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 42;
       load_arduino_v_15_B.i++) {
    load_arduino_v_15_B.WP_db_param[load_arduino_v_15_B.i] =
      load_arduino_v_15_DW.WP_dbP[load_arduino_v_15_B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Tversion' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem2' incorporates:
   *  EnablePort: '<S456>/Enable'
   */
  if (load_arduino_v_15_B.Wp_selector > 0.0) {
    /* Gain: '<S557>/Gain' */
    load_arduino_v_15_B.Gain_nr = load_arduino_v_15_P.Gain_Gain_hq *
      load_arduino_v_15_B.Go_Home;

    /* Gain: '<S558>/Gain' */
    load_arduino_v_15_B.h_comandato = load_arduino_v_15_P.Gain_Gain_jr *
      load_arduino_v_15_B.Gain1_cv;

    /* Gain: '<S559>/Gain' */
    load_arduino_v_15_B.Wp_selector = load_arduino_v_15_P.Gain_Gain_l2 *
      load_arduino_v_15_B.Gain1_cvb;

    /* MATLAB Function: '<S456>/WAYPOINTS' incorporates:
     *  DataTypeConversion: '<S1>/Data Tversion'
     *  DataTypeConversion: '<S1>/Data Tversion1'
     *  DataTypeConversion: '<S1>/Data Tversion2'
     *  DataTypeConversion: '<S571>/Data Type Conversion5'
     *  Memory: '<S456>/Memory4'
     */
    load_arduino_v_15_B.caso = 1;
    if (load_arduino_v_15_DW.Memory4_PreviousInput == 6.0) {
      load_arduino_v_15_B.caso = 0;
    }

    if ((uint8_T)load_arduino_v_15_B.GC_info[0] == 3) {
      load_arduino_v_15_DW.Memory4_PreviousInput = 1.0;
      load_arduino_v_15_DW.lat1 = load_arduino_v_15_B.Gain_nr;
      load_arduino_v_15_DW.long1 = load_arduino_v_15_B.h_comandato;
      for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 6;
           load_arduino_v_15_B.i++) {
        if (load_arduino_v_15_DW.WP_dbI[load_arduino_v_15_B.i + 24] == 1) {
          load_arduino_v_15_DW.Memory4_PreviousInput = (real_T)
            load_arduino_v_15_B.i + 1.0;
        }
      }
    }

    load_arduino_v_15_B.Sum_gs = load_arduino_v_15_B.WP_db_param[(int32_T)
      load_arduino_v_15_DW.Memory4_PreviousInput + 23];
    load_arduino_v_15_B.Abs1_a = load_arduino_v_15_B.WP_db_param[(int32_T)
      load_arduino_v_15_DW.Memory4_PreviousInput + 29];
    load_arduino_v_15_B.QUOTA = load_arduino_v_15_B.WP_db_param[(int32_T)
      load_arduino_v_15_DW.Memory4_PreviousInput + 35];
    load_arduino_v_15_B.RC = load_arduino_v_15_B.QUOTA -
      load_arduino_v_15_B.ByteUnpack_o2[2];
    load_arduino_v_15_B.a_n = sin((load_arduino_v_15_B.Sum_gs -
      load_arduino_v_15_B.Gain_nr) * 3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_15_B.Ato_selector = (load_arduino_v_15_B.Abs1_a -
      load_arduino_v_15_B.h_comandato) * 3.1415926535897931 / 180.0;
    load_arduino_v_15_B.dist = sin(load_arduino_v_15_B.Ato_selector / 2.0);
    load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.Sum_gs *
      3.1415926535897931 / 180.0;
    load_arduino_v_15_B.Abs_i = cos(load_arduino_v_15_B.psi_ref_p);
    load_arduino_v_15_B.e = load_arduino_v_15_B.Gain_nr * 3.1415926535897931 /
      180.0;
    load_arduino_v_15_B.Abs1 = cos(load_arduino_v_15_B.e);
    load_arduino_v_15_B.a_n = load_arduino_v_15_B.Abs1 *
      load_arduino_v_15_B.Abs_i * (load_arduino_v_15_B.dist *
      load_arduino_v_15_B.dist) + load_arduino_v_15_B.a_n *
      load_arduino_v_15_B.a_n;
    load_arduino_v_15_B.a_n = rt_atan2d_snf(sqrt(load_arduino_v_15_B.a_n), sqrt
      (1.0 - load_arduino_v_15_B.a_n)) * 2.0 * 6.378137E+6;
    if (load_arduino_v_15_DW.Memory4_PreviousInput > 1.0) {
      load_arduino_v_15_B.angoloWP = load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput - 1.0) + 23];
      load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.angoloWP *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.dist = cos(load_arduino_v_15_B.psi_ref_p);
      load_arduino_v_15_B.dist_fut = load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput - 1.0) + 29];
      load_arduino_v_15_B.psi_ref_pre = (load_arduino_v_15_B.Abs1_a -
        load_arduino_v_15_B.dist_fut) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_p = rt_atan2d_snf(sin
        (load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_B.Abs_i, sin
        (load_arduino_v_15_B.WP_db_param[(int32_T)
         load_arduino_v_15_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * load_arduino_v_15_B.dist - sin(load_arduino_v_15_B.psi_ref_p) *
        load_arduino_v_15_B.Abs_i * cos(load_arduino_v_15_B.psi_ref_pre)) *
        180.0 / 3.1415926535897931;
      load_arduino_v_15_B.angoloWP = sin((load_arduino_v_15_B.Gain_nr -
        load_arduino_v_15_B.angoloWP) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_15_B.dist_fut = sin((load_arduino_v_15_B.h_comandato -
        load_arduino_v_15_B.dist_fut) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_15_B.dist = load_arduino_v_15_B.dist *
        load_arduino_v_15_B.Abs1 * (load_arduino_v_15_B.dist_fut *
        load_arduino_v_15_B.dist_fut) + load_arduino_v_15_B.angoloWP *
        load_arduino_v_15_B.angoloWP;
      load_arduino_v_15_B.dist = rt_atan2d_snf(sqrt(load_arduino_v_15_B.dist),
        sqrt(1.0 - load_arduino_v_15_B.dist)) * 2.0 * 6.378137E+6;
    } else {
      load_arduino_v_15_B.dist = (load_arduino_v_15_B.Abs1_a -
        load_arduino_v_15_DW.long1) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_DW.lat1 *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_p = rt_atan2d_snf(sin(load_arduino_v_15_B.dist)
        * load_arduino_v_15_B.Abs_i, sin(load_arduino_v_15_B.psi_ref_p) * cos
        (load_arduino_v_15_B.psi_ref_pre) - cos(load_arduino_v_15_B.dist) * (sin
        (load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_B.Abs_i)) * 180.0 /
        3.1415926535897931;
      load_arduino_v_15_B.dist = 0.0;
    }

    if (load_arduino_v_15_B.psi_ref_p < 0.0) {
      load_arduino_v_15_B.psi_ref_p = 360.0 - fabs(load_arduino_v_15_B.psi_ref_p);
    }

    if (load_arduino_v_15_B.caso == 1) {
      load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput + 1.0) + 23];
      load_arduino_v_15_B.dist_fut = sin((load_arduino_v_15_B.psi_ref_pre -
        load_arduino_v_15_B.Sum_gs) * 3.1415926535897931 / 180.0 / 2.0);
      load_arduino_v_15_B.angoloWP = (load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput + 1.0) + 29] -
        load_arduino_v_15_B.Abs1_a) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.Sum1_m = sin(load_arduino_v_15_B.angoloWP / 2.0);
      load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.psi_ref_pre *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.Sum_h = cos(load_arduino_v_15_B.psi_ref_pre);
      load_arduino_v_15_B.dist_fut = load_arduino_v_15_B.Abs_i *
        load_arduino_v_15_B.Sum_h * (load_arduino_v_15_B.Sum1_m *
        load_arduino_v_15_B.Sum1_m) + load_arduino_v_15_B.dist_fut *
        load_arduino_v_15_B.dist_fut;
      load_arduino_v_15_B.dist_fut = rt_atan2d_snf(sqrt
        (load_arduino_v_15_B.dist_fut), sqrt(1.0 - load_arduino_v_15_B.dist_fut))
        * 2.0 * 6.378137E+6;
      load_arduino_v_15_B.angoloWP = rt_atan2d_snf(sin
        (load_arduino_v_15_B.angoloWP) * load_arduino_v_15_B.Sum_h, sin
        (load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_B.Abs_i - cos
        (load_arduino_v_15_B.angoloWP) * (sin(load_arduino_v_15_B.WP_db_param
        [(int32_T)load_arduino_v_15_DW.Memory4_PreviousInput + 23] *
        3.1415926535897931 / 180.0) * load_arduino_v_15_B.Sum_h)) * 180.0 /
        3.1415926535897931;
      if (load_arduino_v_15_B.angoloWP < 0.0) {
        load_arduino_v_15_B.angoloWP = 360.0 - fabs(load_arduino_v_15_B.angoloWP);
      }

      if (load_arduino_v_15_DW.Memory4_PreviousInput > 1.0) {
        load_arduino_v_15_B.angoloWP = fabs(load_arduino_v_15_B.angoloWP -
          load_arduino_v_15_B.psi_ref_p);
      } else {
        load_arduino_v_15_B.angoloWP = fabs(load_arduino_v_15_B.angoloWP -
          rt_atan2d_snf(sin((load_arduino_v_15_B.WP_db_param[(int32_T)
                             load_arduino_v_15_DW.Memory4_PreviousInput + 29] -
                             load_arduino_v_15_DW.long1) * 3.1415926535897931 /
                            180.0) * cos(load_arduino_v_15_B.WP_db_param
          [(int32_T)load_arduino_v_15_DW.Memory4_PreviousInput + 23] *
          3.1415926535897931 / 180.0), sin(load_arduino_v_15_B.WP_db_param
          [(int32_T)load_arduino_v_15_DW.Memory4_PreviousInput + 23] *
          3.1415926535897931 / 180.0) * cos(load_arduino_v_15_DW.lat1 *
          3.1415926535897931 / 180.0) - cos(load_arduino_v_15_B.WP_db_param
          [(int32_T)load_arduino_v_15_DW.Memory4_PreviousInput + 23] *
          3.1415926535897931 / 180.0) * sin(load_arduino_v_15_DW.lat1 *
          3.1415926535897931 / 180.0) * cos((load_arduino_v_15_B.WP_db_param
          [(int32_T)load_arduino_v_15_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_15_DW.long1) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      load_arduino_v_15_B.dist_fut = 0.0;
      load_arduino_v_15_B.angoloWP = 0.0;
    }

    if (load_arduino_v_15_DW.Memory4_PreviousInput < 2.0) {
      load_arduino_v_15_B.psi_ref_pre = 0.0;
    } else if (load_arduino_v_15_DW.Memory4_PreviousInput == 2.0) {
      load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.WP_db_param[24] *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_pre = cos(load_arduino_v_15_B.DeadZone);
      load_arduino_v_15_B.Sum_h = (load_arduino_v_15_B.WP_db_param[30] -
        load_arduino_v_15_DW.long1) * 3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_pre = fabs(load_arduino_v_15_B.psi_ref_p -
        rt_atan2d_snf(sin(load_arduino_v_15_B.Sum_h) *
                      load_arduino_v_15_B.psi_ref_pre, cos
                      (load_arduino_v_15_DW.lat1 * 3.1415926535897931 / 180.0) *
                      sin(load_arduino_v_15_B.DeadZone) - sin
                      (load_arduino_v_15_DW.lat1 * 3.1415926535897931 / 180.0) *
                      load_arduino_v_15_B.psi_ref_pre * cos
                      (load_arduino_v_15_B.Sum_h)) * 180.0 / 3.1415926535897931);
    } else {
      load_arduino_v_15_B.psi_ref_pre = cos(load_arduino_v_15_B.WP_db_param
        [(int32_T)(load_arduino_v_15_DW.Memory4_PreviousInput - 1.0) + 23] *
        3.1415926535897931 / 180.0);
      load_arduino_v_15_B.Sum_h = load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput - 1.0) + 29] -
        load_arduino_v_15_B.WP_db_param[(int32_T)
        (load_arduino_v_15_DW.Memory4_PreviousInput - 2.0) + 29]) *
        3.1415926535897931 / 180.0;
      load_arduino_v_15_B.psi_ref_pre = rt_atan2d_snf(sin
        (load_arduino_v_15_B.Sum1_m) * load_arduino_v_15_B.psi_ref_pre, cos
        (load_arduino_v_15_B.Sum_h) * sin(load_arduino_v_15_B.WP_db_param
        [(int32_T)(load_arduino_v_15_DW.Memory4_PreviousInput - 1.0) + 23] *
        3.1415926535897931 / 180.0) - sin(load_arduino_v_15_B.Sum_h) *
        load_arduino_v_15_B.psi_ref_pre * cos(load_arduino_v_15_B.Sum1_m)) *
        180.0 / 3.1415926535897931;
      if (load_arduino_v_15_B.psi_ref_pre < 0.0) {
        load_arduino_v_15_B.psi_ref_pre = 360.0 - fabs
          (load_arduino_v_15_B.psi_ref_pre);
      }

      load_arduino_v_15_B.psi_ref_pre = fabs(load_arduino_v_15_B.psi_ref_p -
        load_arduino_v_15_B.psi_ref_pre);
    }

    if (load_arduino_v_15_B.angoloWP <= 10.0) {
      load_arduino_v_15_B.angoloWP = 40.0;
      load_arduino_v_15_B.i = 100;
    } else if ((load_arduino_v_15_B.angoloWP > 10.0) &&
               (load_arduino_v_15_B.angoloWP <= 50.0)) {
      load_arduino_v_15_B.angoloWP = 60.0;
      load_arduino_v_15_B.i = 250;
    } else if ((load_arduino_v_15_B.angoloWP > 50.0) &&
               (load_arduino_v_15_B.angoloWP <= 90.0)) {
      load_arduino_v_15_B.angoloWP = 80.0;
      load_arduino_v_15_B.i = 300;
    } else if ((load_arduino_v_15_B.angoloWP > 90.0) &&
               (load_arduino_v_15_B.angoloWP <= 120.0)) {
      load_arduino_v_15_B.angoloWP = 120.0;
      load_arduino_v_15_B.i = 350;
    } else {
      load_arduino_v_15_B.angoloWP = 150.0;
      load_arduino_v_15_B.i = 400;
    }

    if (load_arduino_v_15_B.psi_ref_pre <= 10.0) {
      load_arduino_v_15_B.soglia_dist = 50;
    } else if ((load_arduino_v_15_B.psi_ref_pre > 10.0) &&
               (load_arduino_v_15_B.psi_ref_pre <= 50.0)) {
      load_arduino_v_15_B.soglia_dist = 200;
    } else if ((load_arduino_v_15_B.psi_ref_pre > 50.0) &&
               (load_arduino_v_15_B.psi_ref_pre <= 90.0)) {
      load_arduino_v_15_B.soglia_dist = 300;
    } else if ((load_arduino_v_15_B.psi_ref_pre > 90.0) &&
               (load_arduino_v_15_B.psi_ref_pre <= 120.0)) {
      load_arduino_v_15_B.soglia_dist = 350;
    } else {
      load_arduino_v_15_B.soglia_dist = 400;
    }

    if (load_arduino_v_15_B.caso == 1) {
      load_arduino_v_15_B.VELOCITA = load_arduino_v_15_B.WP_db_param[(int32_T)
        load_arduino_v_15_DW.Memory4_PreviousInput + 11];
      if (load_arduino_v_15_B.VELOCITA < 15.0) {
        load_arduino_v_15_B.VELOCITA = 25.0;
      }

      if (!(load_arduino_v_15_B.VELOCITA <= 20.0)) {
        if (load_arduino_v_15_B.VELOCITA <= 25.0) {
          load_arduino_v_15_B.angoloWP *= 1.2;
        } else if (load_arduino_v_15_B.VELOCITA <= 30.0) {
          load_arduino_v_15_B.angoloWP *= 1.3;
        } else {
          load_arduino_v_15_B.angoloWP *= 1.4;
        }
      }

      load_arduino_v_15_B.ROTTA = rt_atan2d_snf(sin
        ((load_arduino_v_15_B.WP_db_param[(int32_T)
          load_arduino_v_15_DW.Memory4_PreviousInput + 29] -
          load_arduino_v_15_B.h_comandato) * 3.1415926535897931 / 180.0) * cos
        (load_arduino_v_15_B.WP_db_param[(int32_T)
         load_arduino_v_15_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0), sin(load_arduino_v_15_B.WP_db_param[(int32_T)
                     load_arduino_v_15_DW.Memory4_PreviousInput + 23] *
                     3.1415926535897931 / 180.0) * cos
        (load_arduino_v_15_B.Gain_nr * 3.1415926535897931 / 180.0) - cos
        (load_arduino_v_15_B.WP_db_param[(int32_T)
         load_arduino_v_15_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * sin(load_arduino_v_15_B.Gain_nr * 3.1415926535897931 / 180.0) *
        cos((load_arduino_v_15_B.WP_db_param[(int32_T)
             load_arduino_v_15_DW.Memory4_PreviousInput + 29] -
             load_arduino_v_15_B.h_comandato) * 3.1415926535897931 / 180.0)) *
        180.0 / 3.1415926535897931;
      if ((!(load_arduino_v_15_B.dist < load_arduino_v_15_B.soglia_dist)) ||
          (!(load_arduino_v_15_B.a_n > load_arduino_v_15_B.angoloWP))) {
        if ((load_arduino_v_15_B.dist > load_arduino_v_15_B.soglia_dist) &&
            (load_arduino_v_15_B.a_n > load_arduino_v_15_B.angoloWP)) {
          load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.ROTTA -
            load_arduino_v_15_B.psi_ref_p);
          if ((load_arduino_v_15_B.psi_ref_p <= 90.0) &&
              (load_arduino_v_15_B.psi_ref_p >= 0.0)) {
            if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
              load_arduino_v_15_B.ROTTA += 1.3 *
                load_arduino_v_15_B.Ato_selector;
            } else {
              if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA -= 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p <= 180.0) &&
                     (load_arduino_v_15_B.psi_ref_p > 90.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.ROTTA > 0.0)
            {
              if ((load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.ROTTA < -90.0) &&
                   (load_arduino_v_15_B.ROTTA > -180.0))) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 - fabs
                (load_arduino_v_15_B.ROTTA)) - load_arduino_v_15_B.psi_ref_p);
              if ((load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.ROTTA < -90.0) &&
                   (load_arduino_v_15_B.ROTTA > -180.0))) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p < -90.0) &&
                     (load_arduino_v_15_B.psi_ref_p >= -180.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.ROTTA > 0.0)
            {
              if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 -
                load_arduino_v_15_B.ROTTA) - fabs(load_arduino_v_15_B.psi_ref_p));
              if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else {
            if ((load_arduino_v_15_B.psi_ref_p < 0.0) &&
                (load_arduino_v_15_B.psi_ref_p >= -90.0)) {
              if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          }
        } else {
          if (load_arduino_v_15_B.a_n < load_arduino_v_15_B.angoloWP) {
            if (load_arduino_v_15_B.dist_fut > load_arduino_v_15_B.i) {
              load_arduino_v_15_B.Ato_selector = cos
                (load_arduino_v_15_B.WP_db_param[(int32_T)
                 (load_arduino_v_15_DW.Memory4_PreviousInput + 1.0) + 23] *
                 3.1415926535897931 / 180.0);
              load_arduino_v_15_B.Abs_i = (load_arduino_v_15_B.WP_db_param
                [(int32_T)(load_arduino_v_15_DW.Memory4_PreviousInput + 1.0) +
                29] - load_arduino_v_15_B.h_comandato) * 3.1415926535897931 /
                180.0;
              load_arduino_v_15_B.ROTTA = rt_atan2d_snf(sin
                (load_arduino_v_15_B.Abs_i) * load_arduino_v_15_B.Ato_selector,
                sin(load_arduino_v_15_B.WP_db_param[(int32_T)
                    (load_arduino_v_15_DW.Memory4_PreviousInput + 1.0) + 23] *
                    3.1415926535897931 / 180.0) * load_arduino_v_15_B.Abs1 - cos
                (load_arduino_v_15_B.Abs_i) * (sin(load_arduino_v_15_B.Gain_nr *
                3.1415926535897931 / 180.0) * load_arduino_v_15_B.Ato_selector))
                * 180.0 / 3.1415926535897931;
              load_arduino_v_15_DW.Memory4_PreviousInput++;
            } else if (load_arduino_v_15_DW.Memory4_PreviousInput < 5.0) {
              load_arduino_v_15_DW.Memory4_PreviousInput += 2.0;
            } else {
              load_arduino_v_15_B.VELOCITA = 22.0;
              load_arduino_v_15_B.QUOTA = load_arduino_v_15_B.ByteUnpack_o2[2] +
                0.4;
              load_arduino_v_15_B.ROTTA = load_arduino_v_15_B.Wp_selector + 36.6;
              load_arduino_v_15_B.RC = 0.0;
            }
          }
        }
      }

      load_arduino_v_15_DW.flag_l = 0.0;
    } else {
      load_arduino_v_15_B.ROTTA = rt_atan2d_snf(sin
        (load_arduino_v_15_B.Ato_selector) * load_arduino_v_15_B.Abs_i, sin
        (load_arduino_v_15_B.WP_db_param[(int32_T)
         load_arduino_v_15_DW.Memory4_PreviousInput + 23] * 3.1415926535897931 /
         180.0) * load_arduino_v_15_B.Abs1 - cos
        (load_arduino_v_15_B.Ato_selector) * (sin(load_arduino_v_15_B.e) *
        load_arduino_v_15_B.Abs_i)) * 180.0 / 3.1415926535897931;
      load_arduino_v_15_B.VELOCITA = load_arduino_v_15_B.WP_db_param[(int32_T)
        load_arduino_v_15_DW.Memory4_PreviousInput + 11];
      if (load_arduino_v_15_B.VELOCITA < 15.0) {
        load_arduino_v_15_B.VELOCITA = 25.0;
      }

      if ((!(load_arduino_v_15_B.dist < load_arduino_v_15_B.soglia_dist)) ||
          (!(load_arduino_v_15_DW.flag_l == 0.0))) {
        if ((load_arduino_v_15_B.dist > load_arduino_v_15_B.soglia_dist) &&
            (load_arduino_v_15_B.a_n > 40.0) && (load_arduino_v_15_DW.flag_l ==
             0.0)) {
          load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.ROTTA -
            load_arduino_v_15_B.psi_ref_p);
          if ((load_arduino_v_15_B.psi_ref_p <= 90.0) &&
              (load_arduino_v_15_B.psi_ref_p >= 0.0)) {
            if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
              load_arduino_v_15_B.ROTTA += 1.3 *
                load_arduino_v_15_B.Ato_selector;
            } else {
              if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA -= 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p <= 180.0) &&
                     (load_arduino_v_15_B.psi_ref_p > 90.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.ROTTA > 0.0)
            {
              if ((load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.ROTTA < -90.0) &&
                   (load_arduino_v_15_B.ROTTA > -180.0))) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 - fabs
                (load_arduino_v_15_B.ROTTA)) - load_arduino_v_15_B.psi_ref_p);
              if ((load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) ||
                  ((load_arduino_v_15_B.ROTTA < -90.0) &&
                   (load_arduino_v_15_B.ROTTA > -180.0))) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else if ((load_arduino_v_15_B.psi_ref_p < -90.0) &&
                     (load_arduino_v_15_B.psi_ref_p >= -180.0)) {
            if (load_arduino_v_15_B.psi_ref_p * load_arduino_v_15_B.ROTTA > 0.0)
            {
              if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            } else {
              load_arduino_v_15_B.Ato_selector = fabs((360.0 -
                load_arduino_v_15_B.ROTTA) - fabs(load_arduino_v_15_B.psi_ref_p));
              if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          } else {
            if ((load_arduino_v_15_B.psi_ref_p < 0.0) &&
                (load_arduino_v_15_B.psi_ref_p >= -90.0)) {
              if (load_arduino_v_15_B.ROTTA > load_arduino_v_15_B.psi_ref_p) {
                load_arduino_v_15_B.ROTTA += 1.3 *
                  load_arduino_v_15_B.Ato_selector;
              } else {
                if (load_arduino_v_15_B.ROTTA < load_arduino_v_15_B.psi_ref_p) {
                  load_arduino_v_15_B.ROTTA -= 1.3 *
                    load_arduino_v_15_B.Ato_selector;
                }
              }
            }
          }
        } else {
          load_arduino_v_15_B.VELOCITA = 22.0;
          load_arduino_v_15_B.QUOTA = load_arduino_v_15_B.ByteUnpack_o2[2] + 0.4;
          load_arduino_v_15_B.ROTTA = load_arduino_v_15_B.Wp_selector + 36.6;
          load_arduino_v_15_B.RC = 0.0;
          load_arduino_v_15_DW.flag_l = 1.0;
        }
      }
    }

    if ((load_arduino_v_15_B.Sum_gs == 0.0) && (load_arduino_v_15_B.Abs1_a ==
         0.0) && (load_arduino_v_15_B.QUOTA == 0.0)) {
      load_arduino_v_15_B.QUOTA = load_arduino_v_15_B.ByteUnpack_o2[2] + 0.3;
      load_arduino_v_15_B.ROTTA = load_arduino_v_15_B.Wp_selector + 36.6;
      load_arduino_v_15_B.VELOCITA = 22.0;
      load_arduino_v_15_B.RC = 0.0;
    }

    /* Saturate: '<S456>/saturatore V' incorporates:
     *  MATLAB Function: '<S456>/WAYPOINTS'
     */
    if (load_arduino_v_15_B.VELOCITA > load_arduino_v_15_P.saturatoreV_UpperSat)
    {
      /* Saturate: '<S456>/saturatore V' */
      load_arduino_v_15_B.VELOCITA = load_arduino_v_15_P.saturatoreV_UpperSat;
    } else {
      if (load_arduino_v_15_B.VELOCITA <
          load_arduino_v_15_P.saturatoreV_LowerSat) {
        /* Saturate: '<S456>/saturatore V' */
        load_arduino_v_15_B.VELOCITA = load_arduino_v_15_P.saturatoreV_LowerSat;
      }
    }

    /* End of Saturate: '<S456>/saturatore V' */

    /* Saturate: '<S456>/saturatore V1' */
    if (load_arduino_v_15_B.RC > load_arduino_v_15_P.saturatoreV1_UpperSat) {
      /* Saturate: '<S456>/saturatore V1' */
      load_arduino_v_15_B.RC = load_arduino_v_15_P.saturatoreV1_UpperSat;
    } else {
      if (load_arduino_v_15_B.RC < load_arduino_v_15_P.saturatoreV1_LowerSat) {
        /* Saturate: '<S456>/saturatore V1' */
        load_arduino_v_15_B.RC = load_arduino_v_15_P.saturatoreV1_LowerSat;
      }
    }

    /* End of Saturate: '<S456>/saturatore V1' */
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem2' */

  /* Gain: '<S568>/Gain1' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   */
  load_arduino_v_15_B.Wp_selector = load_arduino_v_15_P.Gain1_Gain_o *
    load_arduino_v_15_B.ByteUnpack_o2[3];

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem' incorporates:
   *  EnablePort: '<S454>/Enable'
   */
  if (load_arduino_v_15_B.Vec_selector > 0.0) {
    /* Abs: '<S454>/Abs' incorporates:
     *  DataTypeConversion: '<S454>/Data Type Conversion3'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    load_arduino_v_15_B.Vec_selector = fabs(load_arduino_v_15_DW.riferimenti[10]);

    /* MATLAB Function: '<S454>/VETTORIALE' incorporates:
     *  Constant: '<S41>/RC_default'
     *  DataTypeConversion: '<S571>/Data Type Conversion5'
     *  Gain: '<S463>/Gain'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     *  Memory: '<S454>/Memory'
     *  Memory: '<S454>/Memory1'
     *  Memory: '<S454>/Memory2'
     *  Memory: '<S454>/Memory3'
     *  Memory: '<S454>/Memory6'
     */
    if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[1] !=
         load_arduino_v_15_DW.Memory6_PreviousInput) ||
        (load_arduino_v_15_B.modo != load_arduino_v_15_DW.Memory3_PreviousInput)
        || (load_arduino_v_15_DW.Memory2_PreviousInput_a[3] !=
            load_arduino_v_15_DW.Memory2_PreviousInput_d)) {
      load_arduino_v_15_DW.V_ref = load_arduino_v_15_B.rtb_Gain1_idx_1;
    }

    if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[1] !=
         load_arduino_v_15_DW.Memory6_PreviousInput) ||
        (load_arduino_v_15_B.modo != load_arduino_v_15_DW.Memory3_PreviousInput)
        || (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] !=
            load_arduino_v_15_DW.Memory1_PreviousInput_a)) {
      load_arduino_v_15_DW.ALT_ref = load_arduino_v_15_B.ByteUnpack_o2[2];
    }

    if ((load_arduino_v_15_DW.Memory2_PreviousInput_a[1] !=
         load_arduino_v_15_DW.Memory6_PreviousInput) ||
        (load_arduino_v_15_B.modo != load_arduino_v_15_DW.Memory3_PreviousInput)
        || (load_arduino_v_15_DW.Memory2_PreviousInput_a[2] !=
            load_arduino_v_15_DW.Memory_PreviousInput_b)) {
      load_arduino_v_15_DW.HDG_ref = load_arduino_v_15_P.Gain_Gain_c *
        load_arduino_v_15_B.Wp_selector;
    }

    if (load_arduino_v_15_DW.Memory2_PreviousInput_a[3] == 1) {
      load_arduino_v_15_B.V_vett = load_arduino_v_15_DW.riferimenti[8];
    } else {
      load_arduino_v_15_B.V_vett = load_arduino_v_15_DW.V_ref;
    }

    if (load_arduino_v_15_DW.Memory2_PreviousInput_a[4] == 1) {
      load_arduino_v_15_B.h_vett = load_arduino_v_15_DW.riferimenti[9];
    } else {
      load_arduino_v_15_B.h_vett = load_arduino_v_15_DW.ALT_ref;
    }

    if (load_arduino_v_15_DW.Memory2_PreviousInput_a[2] == 1) {
      load_arduino_v_15_B.rotta_vett = load_arduino_v_15_DW.riferimenti[7];
    } else {
      load_arduino_v_15_B.rotta_vett = load_arduino_v_15_DW.HDG_ref;
    }

    load_arduino_v_15_B.RC_vett = 0.0;
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.h_vett -
      load_arduino_v_15_B.ByteUnpack_o2[2];
    if (load_arduino_v_15_B.Ato_selector >= 0.0) {
      if (load_arduino_v_15_DW.Memory2_PreviousInput_a[5] == 1) {
        load_arduino_v_15_B.RC_vett = load_arduino_v_15_B.Vec_selector;
      } else {
        load_arduino_v_15_B.RC_vett = load_arduino_v_15_P.RC_default_Value;
      }
    } else {
      if (load_arduino_v_15_B.Ato_selector < 0.0) {
        if (load_arduino_v_15_DW.Memory2_PreviousInput_a[5] == 1) {
          load_arduino_v_15_B.RC_vett = -load_arduino_v_15_B.Vec_selector;
        } else {
          load_arduino_v_15_B.RC_vett = -load_arduino_v_15_P.RC_default_Value;
        }
      }
    }

    /* Update for Memory: '<S454>/Memory' incorporates:
     *  MATLAB Function: '<S454>/VETTORIALE'
     */
    load_arduino_v_15_DW.Memory_PreviousInput_b =
      load_arduino_v_15_DW.Memory2_PreviousInput_a[2];

    /* Update for Memory: '<S454>/Memory1' incorporates:
     *  MATLAB Function: '<S454>/VETTORIALE'
     */
    load_arduino_v_15_DW.Memory1_PreviousInput_a =
      load_arduino_v_15_DW.Memory2_PreviousInput_a[4];

    /* Update for Memory: '<S454>/Memory2' incorporates:
     *  MATLAB Function: '<S454>/VETTORIALE'
     */
    load_arduino_v_15_DW.Memory2_PreviousInput_d =
      load_arduino_v_15_DW.Memory2_PreviousInput_a[3];

    /* Update for Memory: '<S454>/Memory3' incorporates:
     *  MATLAB Function: '<S454>/VETTORIALE'
     */
    load_arduino_v_15_DW.Memory3_PreviousInput = load_arduino_v_15_B.modo;

    /* Update for Memory: '<S454>/Memory6' incorporates:
     *  MATLAB Function: '<S454>/VETTORIALE'
     */
    load_arduino_v_15_DW.Memory6_PreviousInput =
      load_arduino_v_15_DW.Memory2_PreviousInput_a[1];
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem3' incorporates:
   *  EnablePort: '<S457>/Enable'
   */
  if (load_arduino_v_15_B.Go_home_selector > 0.0) {
    /* Gain: '<S562>/Gain' */
    load_arduino_v_15_B.Go_home_selector = load_arduino_v_15_P.Gain_Gain_jv *
      load_arduino_v_15_B.Go_Home;

    /* MATLAB Function: '<S457>/GO_HOME' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant1'
     *  DataTypeConversion: '<S571>/Data Type Conversion5'
     *  Gain: '<S563>/Gain'
     *  Gain: '<S564>/Gain'
     */
    load_arduino_v_15_B.a_n = sin((load_arduino_v_15_B.Lat_Home -
      load_arduino_v_15_B.Go_home_selector) * 3.1415926535897931 / 180.0 / 2.0);
    load_arduino_v_15_B.Ato_selector = (load_arduino_v_15_B.Long_Home -
      load_arduino_v_15_P.Gain_Gain_hc * load_arduino_v_15_B.Gain1_cv) *
      3.1415926535897931 / 180.0;
    load_arduino_v_15_B.dist = sin(load_arduino_v_15_B.Ato_selector / 2.0);
    load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.Lat_Home *
      3.1415926535897931 / 180.0;
    load_arduino_v_15_B.Abs_i = cos(load_arduino_v_15_B.psi_ref_p);
    load_arduino_v_15_B.e = load_arduino_v_15_B.Go_home_selector *
      3.1415926535897931 / 180.0;
    load_arduino_v_15_B.Abs1 = cos(load_arduino_v_15_B.e);
    load_arduino_v_15_B.a_n = load_arduino_v_15_B.Abs1 *
      load_arduino_v_15_B.Abs_i * (load_arduino_v_15_B.dist *
      load_arduino_v_15_B.dist) + load_arduino_v_15_B.a_n *
      load_arduino_v_15_B.a_n;
    load_arduino_v_15_B.rotta_goHome = rt_atan2d_snf(sin
      (load_arduino_v_15_B.Ato_selector) * load_arduino_v_15_B.Abs_i, sin
      (load_arduino_v_15_B.psi_ref_p) * load_arduino_v_15_B.Abs1 - sin
      (load_arduino_v_15_B.e) * load_arduino_v_15_B.Abs_i * cos
      (load_arduino_v_15_B.Ato_selector)) * 180.0 / 3.1415926535897931;
    load_arduino_v_15_B.h_goHome = load_arduino_v_15_P.Constant_Value_g;
    load_arduino_v_15_B.V_goHome = load_arduino_v_15_P.Constant1_Value_cc;
    load_arduino_v_15_B.RC_goHome = load_arduino_v_15_P.Constant_Value_g -
      load_arduino_v_15_B.ByteUnpack_o2[2];
    if ((rt_atan2d_snf(sqrt(load_arduino_v_15_B.a_n), sqrt(1.0 -
           load_arduino_v_15_B.a_n)) * 2.0 * 6.378137E+6 < 30.0) &&
        (load_arduino_v_15_DW.flag == 0.0)) {
      load_arduino_v_15_DW.flag = 1.0;
      load_arduino_v_15_B.h_goHome = load_arduino_v_15_P.Constant_Value_g + 0.4;
      load_arduino_v_15_B.rotta_goHome = load_arduino_v_15_P.Gain_Gain_pr *
        load_arduino_v_15_B.Gain1_cvb + 100.0;
      load_arduino_v_15_B.RC_goHome = 0.0;
    }

    /* End of MATLAB Function: '<S457>/GO_HOME' */
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem3' */

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation3' */
  switch ((int32_T)load_arduino_v_15_B.modo) {
   case 1:
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.ROTTA;
    break;

   case 2:
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.rotta_vett;
    break;

   case 3:
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.Gain_f;
    break;

   case 4:
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.Switch1;
    break;

   default:
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_B.rotta_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation3' */

  /* Switch: '<S43>/Switch' */
  if (load_arduino_v_15_B.rtb_Gain4_idx_0 >
      load_arduino_v_15_P.Switch_Threshold_l) {
    load_arduino_v_15_B.Go_home_selector = load_arduino_v_15_B.Wp_selector;
  } else {
    load_arduino_v_15_B.Go_home_selector = load_arduino_v_15_B.Gain1_cvb;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Sum: '<S198>/Sum' incorporates:
   *  Constant: '<S198>/Constant'
   *  Gain: '<S250>/Gain'
   *  Math: '<S198>/Math Function'
   */
  load_arduino_v_15_B.Go_home_selector = load_arduino_v_15_B.Abs1 - rt_modd_snf
    (load_arduino_v_15_P.Gain_Gain_pa * load_arduino_v_15_B.Go_home_selector,
     load_arduino_v_15_P.Constant_Value_ig);

  /* Switch: '<S198>/Switch1' incorporates:
   *  Constant: '<S198>/Constant2'
   *  Sum: '<S198>/Sum2'
   */
  if (load_arduino_v_15_B.Go_home_selector >=
      load_arduino_v_15_P.Switch1_Threshold_b) {
    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S198>/Constant1'
     *  Sum: '<S198>/Sum1'
     */
    if (load_arduino_v_15_B.Go_home_selector >=
        load_arduino_v_15_P.Switch_Threshold) {
      load_arduino_v_15_B.Go_home_selector -=
        load_arduino_v_15_P.Constant1_Value_e;
    }

    /* End of Switch: '<S198>/Switch' */
  } else {
    load_arduino_v_15_B.Go_home_selector +=
      load_arduino_v_15_P.Constant2_Value_g;
  }

  /* End of Switch: '<S198>/Switch1' */

  /* Gain: '<S249>/Gain1' */
  load_arduino_v_15_B.Go_home_selector *= load_arduino_v_15_P.Gain1_Gain_ef;

  /* Switch: '<S196>/Switch4' incorporates:
   *  Constant: '<S196>/Constant4'
   *  Constant: '<S8>/Ki AP rotta1'
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  MultiPortSwitch: '<S196>/Multiport Switch3'
   */
  if (load_arduino_v_15_B.ByteUnpack_o2[2] >
      load_arduino_v_15_P.Switch4_Threshold_d) {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.KiAProtta1_Value;
  } else if (load_arduino_v_15_B.ATO == 0) {
    /* MultiPortSwitch: '<S196>/Multiport Switch3' incorporates:
     *  Constant: '<S8>/Ki AP rotta1'
     */
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.KiAProtta1_Value;
  } else {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant4_Value;
  }

  /* End of Switch: '<S196>/Switch4' */

  /* Product: '<S235>/NProd Out' incorporates:
   *  Constant: '<S43>/Constant'
   *  DiscreteIntegrator: '<S227>/Filter'
   *  Product: '<S226>/DProd Out'
   *  Sum: '<S227>/SumD'
   */
  load_arduino_v_15_B.Vec_selector = (load_arduino_v_15_B.Go_home_selector *
    load_arduino_v_15_B.Ato_selector - load_arduino_v_15_DW.Filter_DSTATE) *
    load_arduino_v_15_P.Constant_Value_j;

  /* Switch: '<S196>/Switch3' incorporates:
   *  Constant: '<S196>/Constant3'
   *  Constant: '<S8>/Kp AP rotta'
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  MultiPortSwitch: '<S196>/Multiport Switch2'
   */
  if (load_arduino_v_15_B.ByteUnpack_o2[2] >
      load_arduino_v_15_P.Switch3_Threshold_d) {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Kp_AP_rotta;
  } else if (load_arduino_v_15_B.ATO == 0) {
    /* MultiPortSwitch: '<S196>/Multiport Switch2' incorporates:
     *  Constant: '<S8>/Kp AP rotta'
     */
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Kp_AP_rotta;
  } else {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Kp_Rotta_ATO;
  }

  /* End of Switch: '<S196>/Switch3' */

  /* Sum: '<S241>/Sum' incorporates:
   *  DiscreteIntegrator: '<S232>/Integrator'
   *  Product: '<S237>/PProd Out'
   */
  load_arduino_v_15_B.Sum_gs = (load_arduino_v_15_B.Go_home_selector *
    load_arduino_v_15_B.Ato_selector + load_arduino_v_15_DW.Integrator_DSTATE) +
    load_arduino_v_15_B.Vec_selector;

  /* Saturate: '<S239>/Saturation' */
  if (load_arduino_v_15_B.Sum_gs >
      load_arduino_v_15_P.PIDController1_UpperSaturationL) {
    load_arduino_v_15_B.Abs1_a =
      load_arduino_v_15_P.PIDController1_UpperSaturationL;
  } else if (load_arduino_v_15_B.Sum_gs <
             load_arduino_v_15_P.PIDController1_LowerSaturationL) {
    load_arduino_v_15_B.Abs1_a =
      load_arduino_v_15_P.PIDController1_LowerSaturationL;
  } else {
    load_arduino_v_15_B.Abs1_a = load_arduino_v_15_B.Sum_gs;
  }

  /* End of Saturate: '<S239>/Saturation' */

  /* MultiPortSwitch: '<S38>/Switch di selezioneriferimeti  per i loop interni 3' */
  if ((int32_T)load_arduino_v_15_B.Switch_n == 0) {
    /* MultiPortSwitch: '<S43>/Switch auto-manual' */
    if ((int32_T)load_arduino_v_15_B.switch_alettoni == 0) {
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_B.Gain1_b;
    } else {
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_B.Abs1_a;
    }

    /* End of MultiPortSwitch: '<S43>/Switch auto-manual' */
  } else {
    load_arduino_v_15_B.Abs_i = load_arduino_v_15_B.phi_safe;
  }

  /* End of MultiPortSwitch: '<S38>/Switch di selezioneriferimeti  per i loop interni 3' */

  /* MultiPortSwitch: '<S309>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.ATO != 0) {
    /* MultiPortSwitch: '<S309>/Multiport Switch1' incorporates:
     *  Constant: '<S309>/Constant'
     */
    switch ((int32_T)load_arduino_v_15_B.Fase_ATO) {
     case 0:
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_P.Constant_Value_a3;
      break;

     case 1:
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_P.Constant_Value_a3;
      break;

     case 2:
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_P.Constant_Value_a3;
      break;

     case 3:
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_P.Constant_Value_a3;
      break;
    }

    /* End of MultiPortSwitch: '<S309>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S309>/Multiport Switch2' */

  /* MultiPortSwitch: '<S308>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.pipk != 0) {
    /* Switch: '<S308>/Switch4' incorporates:
     *  Constant: '<S308>/Constant5'
     *  DataTypeConversion: '<S571>/Data Type Conversion5'
     */
    if (!(load_arduino_v_15_B.ByteUnpack_o2[2] >=
          load_arduino_v_15_P.Switch4_Threshold)) {
      load_arduino_v_15_B.Abs_i = load_arduino_v_15_P.Constant5_Value_g;
    }

    /* End of Switch: '<S308>/Switch4' */
  }

  /* End of MultiPortSwitch: '<S308>/Multiport Switch2' */

  /* Sum: '<S39>/Sum5' */
  load_arduino_v_15_B.e = load_arduino_v_15_B.Abs_i -
    load_arduino_v_15_B.Gain1_b;

  /* Sum: '<S306>/Sum' incorporates:
   *  Constant: '<S306>/Constant3'
   */
  load_arduino_v_15_B.a_n = load_arduino_v_15_B.Fase_ATO -
    load_arduino_v_15_P.Constant3_Value_j;

  /* DiscreteIntegrator: '<S403>/Integrator' */
  if ((load_arduino_v_15_B.a_n > 0.0) &&
      (load_arduino_v_15_DW.Integrator_PrevResetState <= 0)) {
    load_arduino_v_15_DW.Integrator_DSTATE_d =
      load_arduino_v_15_P.PIDController_InitialConditi_ld;
  }

  /* Sum: '<S412>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore  rollio3'
   *  DiscreteIntegrator: '<S403>/Integrator'
   *  Product: '<S408>/PProd Out'
   */
  load_arduino_v_15_B.psi_ref_p = load_arduino_v_15_B.e *
    load_arduino_v_15_P.Kp_roll + load_arduino_v_15_DW.Integrator_DSTATE_d;

  /* Saturate: '<S410>/Saturation' */
  if (load_arduino_v_15_B.psi_ref_p > load_arduino_v_15_P.attuatore_Amax) {
    load_arduino_v_15_B.Gain_nr = load_arduino_v_15_P.attuatore_Amax;
  } else if (load_arduino_v_15_B.psi_ref_p < load_arduino_v_15_P.attuatore_Amin)
  {
    load_arduino_v_15_B.Gain_nr = load_arduino_v_15_P.attuatore_Amin;
  } else {
    load_arduino_v_15_B.Gain_nr = load_arduino_v_15_B.psi_ref_p;
  }

  /* End of Saturate: '<S410>/Saturation' */

  /* MultiPortSwitch: '<S306>/Switch Bumpless 1' incorporates:
   *  Constant: '<S306>/Constant1'
   *  Constant: '<S8>/Kp controllore  velocità rollio3'
   *  Product: '<S306>/Product3'
   */
  if ((int32_T)load_arduino_v_15_B.switch_alettoni == 0) {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant1_Value_fs;
  } else {
    load_arduino_v_15_B.Ato_selector =
      load_arduino_v_15_B.DataTypeConversion1_b[3] * load_arduino_v_15_P.Kp_p;
  }

  /* End of MultiPortSwitch: '<S306>/Switch Bumpless 1' */

  /* Sum: '<S306>/Sum2' */
  load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.Gain_nr -
    load_arduino_v_15_B.Ato_selector;

  /* MultiPortSwitch: '<S39>/Switch Bumpless 3' incorporates:
   *  Saturate: '<S39>/saturatore A1'
   */
  if ((int32_T)load_arduino_v_15_B.switch_alettoni == 0) {
    load_arduino_v_15_B.dist = load_arduino_v_15_B.Sum3;
  } else if (load_arduino_v_15_B.psi_ref_pre >
             load_arduino_v_15_P.attuatore_Amax) {
    /* Saturate: '<S39>/saturatore A1' */
    load_arduino_v_15_B.dist = load_arduino_v_15_P.attuatore_Amax;
  } else if (load_arduino_v_15_B.psi_ref_pre <
             load_arduino_v_15_P.attuatore_Amin) {
    /* Saturate: '<S39>/saturatore A1' */
    load_arduino_v_15_B.dist = load_arduino_v_15_P.attuatore_Amin;
  } else {
    /* Saturate: '<S39>/saturatore A1' */
    load_arduino_v_15_B.dist = load_arduino_v_15_B.psi_ref_pre;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 3' */

  /* Saturate: '<S39>/saturatore A' */
  if (load_arduino_v_15_B.dist > load_arduino_v_15_P.attuatore_Amax) {
    load_arduino_v_15_B.h_comandato = load_arduino_v_15_P.attuatore_Amax;
  } else if (load_arduino_v_15_B.dist < load_arduino_v_15_P.attuatore_Amin) {
    load_arduino_v_15_B.h_comandato = load_arduino_v_15_P.attuatore_Amin;
  } else {
    load_arduino_v_15_B.h_comandato = load_arduino_v_15_B.dist;
  }

  /* End of Saturate: '<S39>/saturatore A' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 5' incorporates:
   *  Gain: '<S39>/Gain1'
   */
  if ((int32_T)load_arduino_v_15_B.switch_alettoni == 0) {
    load_arduino_v_15_B.dist = load_arduino_v_15_B.Sum3;
  } else {
    load_arduino_v_15_B.dist = load_arduino_v_15_P.inv_A *
      load_arduino_v_15_B.h_comandato;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 5' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S598>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion9'
   *  Product: '<S598>/Divide'
   *  Product: '<S598>/Multiply'
   *  Sum: '<S598>/Sum'
   *  Sum: '<S598>/Sum3'
   */
  load_arduino_v_15_B.Ato_selector = floor((load_arduino_v_15_B.dist -
    load_arduino_v_15_P.attuatore_Amin) / load_arduino_v_15_B.Al_selector *
    load_arduino_v_15_B.rtb_Gain4_idx_1 + (real_T)
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[5]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_c = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */
  Servo_microseconds_alettoni_beta_3_Outputs_wrapper
    (&load_arduino_v_15_B.DataTypeConversion1_c,
     &load_arduino_v_15_DW.SFunctionBuilder10_DSTATE);

  /* S-Function (PWMinterrupt_throttle_v4_4): '<S9>/S-Function Builder6' */
  PWMinterrupt_throttle_v4_4_Outputs_wrapper(&load_arduino_v_15_B.PWM_throttle);

  /* Product: '<S597>/Divide2' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   *  Product: '<S600>/Multiply'
   *  Sum: '<S597>/Sum3'
   */
  load_arduino_v_15_B.Gain_dw =
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[0] -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[1];

  /* Sum: '<S597>/Sum5' incorporates:
   *  Constant: '<S597>/manetta_massima'
   *  Constant: '<S597>/manetta_minima'
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   *  Product: '<S597>/Divide2'
   *  Product: '<S597>/Multiply1'
   *  Sum: '<S597>/Sum2'
   *  Sum: '<S597>/Sum4'
   */
  load_arduino_v_15_B.dist_fut = (real_T)(load_arduino_v_15_B.PWM_throttle -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[1]) /
    load_arduino_v_15_B.Gain_dw * (load_arduino_v_15_P.attuatore_Tmax -
    load_arduino_v_15_P.attuatore_Tmin) + load_arduino_v_15_P.attuatore_Tmin;

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation1' */
  switch ((int32_T)load_arduino_v_15_B.modo) {
   case 1:
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.VELOCITA;
    break;

   case 2:
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.V_vett;
    break;

   case 3:
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.Tas_ref;
    break;

   case 4:
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.velocita;
    break;

   default:
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.V_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation1' */

  /* Sum: '<S44>/Sum3' */
  load_arduino_v_15_B.DeadZone -= load_arduino_v_15_B.rtb_Gain1_idx_1;

  /* Sum: '<S295>/Sum' incorporates:
   *  Constant: '<S8>/Kp AP velocità'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  Product: '<S291>/PProd Out'
   */
  load_arduino_v_15_B.rtb_Gain4_idx_1 = load_arduino_v_15_B.DeadZone *
    load_arduino_v_15_P.Kp_AP_vel + load_arduino_v_15_DW.Integrator_DSTATE_n;

  /* Saturate: '<S293>/Saturation' */
  if (load_arduino_v_15_B.rtb_Gain4_idx_1 > load_arduino_v_15_P.attuatore_Tmax)
  {
    load_arduino_v_15_B.Saturation_h = load_arduino_v_15_P.attuatore_Tmax;
  } else if (load_arduino_v_15_B.rtb_Gain4_idx_1 <
             load_arduino_v_15_P.attuatore_Tmin) {
    load_arduino_v_15_B.Saturation_h = load_arduino_v_15_P.attuatore_Tmin;
  } else {
    load_arduino_v_15_B.Saturation_h = load_arduino_v_15_B.rtb_Gain4_idx_1;
  }

  /* End of Saturate: '<S293>/Saturation' */

  /* MultiPortSwitch: '<S44>/Switch Bumpless 1' */
  if ((int32_T)load_arduino_v_15_B.switch_manetta == 0) {
    load_arduino_v_15_B.Gain_g = load_arduino_v_15_B.dist_fut;
  } else {
    load_arduino_v_15_B.Gain_g = load_arduino_v_15_B.Saturation_h;
  }

  /* End of MultiPortSwitch: '<S44>/Switch Bumpless 1' */

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation2' */
  switch ((int32_T)load_arduino_v_15_B.modo) {
   case 1:
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.QUOTA;
    break;

   case 2:
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.h_vett;
    break;

   case 3:
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.h_ref;
    break;

   case 4:
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.QUOTA_n;
    break;

   default:
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.h_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation2' */

  /* HitCross: '<S252>/Hit  Crossing' */
  load_arduino_v_15_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &load_arduino_v_15_PrevZCX.HitCrossing_Input_ZCE,
    (load_arduino_v_15_B.Al_selector - load_arduino_v_15_P.HitCrossing_Offset));
  if (load_arduino_v_15_DW.HitCrossing_MODE == 0) {
    if (load_arduino_v_15_B.zcEvent != NO_ZCEVENT) {
      /* HitCross: '<S252>/Hit  Crossing' */
      load_arduino_v_15_B.HitCrossing = !load_arduino_v_15_B.HitCrossing;
      load_arduino_v_15_DW.HitCrossing_MODE = 1;
    } else {
      if (load_arduino_v_15_B.HitCrossing) {
        /* HitCross: '<S252>/Hit  Crossing' */
        load_arduino_v_15_B.HitCrossing = ((!(load_arduino_v_15_B.Al_selector !=
          load_arduino_v_15_P.HitCrossing_Offset)) &&
          load_arduino_v_15_B.HitCrossing);
      }
    }
  } else {
    /* HitCross: '<S252>/Hit  Crossing' */
    load_arduino_v_15_B.HitCrossing = ((!(load_arduino_v_15_B.Al_selector !=
      load_arduino_v_15_P.HitCrossing_Offset)) &&
      load_arduino_v_15_B.HitCrossing);
    load_arduino_v_15_DW.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<S252>/Hit  Crossing' */

  /* Outputs for Triggered SubSystem: '<S252>/Enabled Subsystem' incorporates:
   *  TriggerPort: '<S303>/Trigger'
   */
  if (load_arduino_v_15_B.HitCrossing &&
      (load_arduino_v_15_PrevZCX.EnabledSubsystem_Trig_ZCE != 1)) {
    /* SignalConversion generated from: '<S303>/Out1' incorporates:
     *  Constant: '<S303>/Constant'
     */
    load_arduino_v_15_B.OutportBufferForOut1 =
      load_arduino_v_15_P.Constant_Value;
  }

  load_arduino_v_15_PrevZCX.EnabledSubsystem_Trig_ZCE =
    load_arduino_v_15_B.HitCrossing;

  /* End of Outputs for SubSystem: '<S252>/Enabled Subsystem' */

  /* MultiPortSwitch: '<S38>/Switch di selezione riferimeti  per i loop interni 1' */
  if ((int32_T)load_arduino_v_15_B.Switch_n == 0) {
    /* MultiPortSwitch: '<S252>/throttle - landing' incorporates:
     *  MATLAB Function: '<S40>/MATLAB Function'
     */
    if (load_arduino_v_15_B.pipk != 0) {
      /* Switch: '<S252>/Switch' incorporates:
       *  Constant: '<S252>/Constant3'
       */
      if (!(load_arduino_v_15_B.OutportBufferForOut1 >
            load_arduino_v_15_P.Switch_Threshold_k)) {
        load_arduino_v_15_B.Gain_g = load_arduino_v_15_P.Constant3_Value;
      }

      /* End of Switch: '<S252>/Switch' */
    }

    /* End of MultiPortSwitch: '<S252>/throttle - landing' */
  } else {
    load_arduino_v_15_B.Gain_g = load_arduino_v_15_B.throttle_safe;
  }

  /* End of MultiPortSwitch: '<S38>/Switch di selezione riferimeti  per i loop interni 1' */

  /* Sum: '<S310>/Sum' incorporates:
   *  Constant: '<S310>/Constant8'
   */
  load_arduino_v_15_B.Sum3 = load_arduino_v_15_B.Fase_ATO -
    load_arduino_v_15_P.Constant8_Value_p;

  /* DiscreteIntegrator: '<S310>/Discrete-Time Integrator' */
  if ((load_arduino_v_15_B.Sum3 > 0.0) &&
      (load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_15_P.DiscreteTimeIntegrator_IC_e;
  }

  if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE >=
      load_arduino_v_15_P.attuatore_Tmax) {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_15_P.attuatore_Tmax;
  } else {
    if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE <=
        load_arduino_v_15_P.DiscreteTimeIntegrator_LowerS_o) {
      load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE =
        load_arduino_v_15_P.DiscreteTimeIntegrator_LowerS_o;
    }
  }

  /* MultiPortSwitch: '<S310>/Multiport Switch1' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.ATO != 0) {
    /* MultiPortSwitch: '<S310>/Switch Bumpless 1' incorporates:
     *  Constant: '<S310>/Constant4'
     *  DiscreteIntegrator: '<S310>/Discrete-Time Integrator'
     */
    switch ((int32_T)load_arduino_v_15_B.Fase_ATO) {
     case 0:
      load_arduino_v_15_B.Gain_g = load_arduino_v_15_P.Constant4_Value_d;
      break;

     case 1:
      load_arduino_v_15_B.Gain_g = load_arduino_v_15_B.manetta_ref;
      break;

     case 2:
      load_arduino_v_15_B.Gain_g =
        load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S310>/Switch Bumpless 1' */
  }

  /* End of MultiPortSwitch: '<S310>/Multiport Switch1' */

  /* RateLimiter: '<S39>/Rate Limiter' */
  load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.Gain_g -
    load_arduino_v_15_DW.PrevY_o;
  if (load_arduino_v_15_B.Ato_selector >
      load_arduino_v_15_P.RateLimiter_RisingLim) {
    /* RateLimiter: '<S39>/Rate Limiter' */
    load_arduino_v_15_DW.PrevY_o += load_arduino_v_15_P.RateLimiter_RisingLim;
  } else if (load_arduino_v_15_B.Ato_selector <
             load_arduino_v_15_P.RateLimiter_FallingLim) {
    /* RateLimiter: '<S39>/Rate Limiter' */
    load_arduino_v_15_DW.PrevY_o += load_arduino_v_15_P.RateLimiter_FallingLim;
  } else {
    /* RateLimiter: '<S39>/Rate Limiter' */
    load_arduino_v_15_DW.PrevY_o = load_arduino_v_15_B.Gain_g;
  }

  /* End of RateLimiter: '<S39>/Rate Limiter' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 7' */
  if ((int32_T)load_arduino_v_15_B.switch_manetta != 0) {
    /* Gain: '<S39>/Gain3' */
    load_arduino_v_15_B.dist_fut = load_arduino_v_15_P.inv_T
      * load_arduino_v_15_DW.PrevY_o;

    /* Saturate: '<S39>/Saturation' */
    if (load_arduino_v_15_B.dist_fut > load_arduino_v_15_P.attuatore_Tmax) {
      load_arduino_v_15_B.dist_fut = load_arduino_v_15_P.attuatore_Tmax;
    } else {
      if (load_arduino_v_15_B.dist_fut < load_arduino_v_15_P.attuatore_Tmin) {
        load_arduino_v_15_B.dist_fut = load_arduino_v_15_P.attuatore_Tmin;
      }
    }

    /* End of Saturate: '<S39>/Saturation' */
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 7' */

  /* Sum: '<S600>/Sum' incorporates:
   *  Product: '<S600>/Multiply'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Gain_dw *
    load_arduino_v_15_B.dist_fut);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* Sum: '<S600>/Sum' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   */
  load_arduino_v_15_B.Sum = (int16_T)((load_arduino_v_15_B.Ato_selector < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.Ato_selector :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.Ato_selector) + (int16_T)
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[1]);

  /* S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper(&load_arduino_v_15_B.Sum,
    &load_arduino_v_15_DW.SFunctionBuilder4_DSTATE);

  /* S-Function (PWMinterrupt_rudder_v4_4): '<S9>/S-Function Builder8' */
  PWMinterrupt_rudder_v4_4_Outputs_wrapper(&load_arduino_v_15_B.PWM_rudder);

  /* Sum: '<S596>/Sum3' incorporates:
   *  Constant: '<S596>/Constant8'
   *  Constant: '<S596>/Constant9'
   *  Sum: '<S599>/Sum1'
   */
  load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.attuatore_Rmax -
    load_arduino_v_15_P.attuatore_Rmin;

  /* Product: '<S596>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion10'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  Product: '<S599>/Multiply'
   *  Sum: '<S596>/Sum2'
   */
  load_arduino_v_15_B.Sum_h =
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[6] -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[7];

  /* Sum: '<S596>/Sum4' incorporates:
   *  Constant: '<S596>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  DataTypeConversion: '<S9>/Data Type Conversion15'
   *  Product: '<S596>/Divide'
   *  Product: '<S596>/Multiply'
   *  Sum: '<S596>/Sum1'
   *  Sum: '<S596>/Sum3'
   */
  load_arduino_v_15_B.angoloWP = (real_T)(load_arduino_v_15_B.PWM_rudder -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[7]) /
    load_arduino_v_15_B.Sum_h * load_arduino_v_15_B.Ato_selector +
    load_arduino_v_15_P.attuatore_Rmin;

  /* DiscreteTransferFcn: '<S307>/Discrete Washout Filter' */
  load_arduino_v_15_B.Gain_dw = (load_arduino_v_15_B.DataTypeConversion1_b[5] -
    load_arduino_v_15_P.DiscreteWashoutFilter_DenCoef[1] *
    load_arduino_v_15_DW.DiscreteWashoutFilter_states) /
    load_arduino_v_15_P.DiscreteWashoutFilter_DenCoef[0];

  /* Sum: '<S39>/Sum1' incorporates:
   *  Constant: '<S39>/r_rif'
   *  Constant: '<S8>/K controllo imbardata inversa'
   *  Constant: '<S8>/Kp controllore imbardata'
   *  DiscreteTransferFcn: '<S307>/Discrete Washout Filter'
   *  Product: '<S39>/  CONTROLLO     IMBARDATA      INVERSA'
   *  Product: '<S39>/Product'
   *  Sum: '<S39>/Sum9'
   */
  load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_P.r_rif_Value -
    (load_arduino_v_15_P.DiscreteWashoutFilter_NumCoef[0] *
     load_arduino_v_15_B.Gain_dw +
     load_arduino_v_15_P.DiscreteWashoutFilter_NumCoef[1] *
     load_arduino_v_15_DW.DiscreteWashoutFilter_states)) *
    load_arduino_v_15_P.Kp_imb + load_arduino_v_15_B.psi_ref_pre * (real_T)
    load_arduino_v_15_P.K_imb_inv;

  /* Switch: '<S304>/Switch2' incorporates:
   *  Gain: '<S312>/Gain'
   *  Gain: '<S313>/Gain'
   */
  if (load_arduino_v_15_B.rtb_Gain4_idx_0 >=
      load_arduino_v_15_P.Switch2_Threshold_n) {
    load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Gain_Gain *
      load_arduino_v_15_B.Wp_selector;
  } else {
    load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Gain_Gain_i *
      load_arduino_v_15_B.Gain1_cvb;
  }

  /* End of Switch: '<S304>/Switch2' */

  /* MultiPortSwitch: '<S304>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.ATO != 0) {
    /* MultiPortSwitch: '<S304>/Multiport Switch1' incorporates:
     *  Constant: '<S304>/Constant4'
     *  Product: '<S304>/Product5'
     *  Sum: '<S304>/Sum5'
     */
    switch ((int32_T)load_arduino_v_15_B.Fase_ATO) {
     case 0:
      /* Switch: '<S318>/Switch2' incorporates:
       *  Abs: '<S318>/Abs'
       *  Constant: '<S318>/Constant2'
       *  Sum: '<S318>/Sum'
       */
      if (load_arduino_v_15_B.Abs1 > load_arduino_v_15_P.Switch2_Threshold_h) {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_B.Abs1;
      } else {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.Constant2_Value_c -
          fabs(load_arduino_v_15_B.Abs1);
      }

      /* Switch: '<S317>/Switch2' incorporates:
       *  Abs: '<S317>/Abs'
       *  Constant: '<S317>/Constant2'
       *  Sum: '<S317>/Sum'
       */
      if (!(load_arduino_v_15_B.psi_ref_pre >
            load_arduino_v_15_P.Switch2_Threshold_m)) {
        load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Constant2_Value_f
          - fabs(load_arduino_v_15_B.psi_ref_pre);
      }

      load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.Sum1_m -
        load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_P.Kp_Rotta_psi;
      break;

     case 1:
      /* Switch: '<S318>/Switch2' incorporates:
       *  Abs: '<S318>/Abs'
       *  Constant: '<S318>/Constant2'
       *  Sum: '<S318>/Sum'
       */
      if (load_arduino_v_15_B.Abs1 > load_arduino_v_15_P.Switch2_Threshold_h) {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_B.Abs1;
      } else {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.Constant2_Value_c -
          fabs(load_arduino_v_15_B.Abs1);
      }

      /* Switch: '<S317>/Switch2' incorporates:
       *  Abs: '<S317>/Abs'
       *  Constant: '<S317>/Constant2'
       *  Sum: '<S317>/Sum'
       */
      if (!(load_arduino_v_15_B.psi_ref_pre >
            load_arduino_v_15_P.Switch2_Threshold_m)) {
        load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Constant2_Value_f
          - fabs(load_arduino_v_15_B.psi_ref_pre);
      }

      load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.Sum1_m -
        load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_P.Kp_Rotta_psi;
      break;

     case 2:
      /* Switch: '<S318>/Switch2' incorporates:
       *  Abs: '<S318>/Abs'
       *  Constant: '<S318>/Constant2'
       *  Sum: '<S318>/Sum'
       */
      if (load_arduino_v_15_B.Abs1 > load_arduino_v_15_P.Switch2_Threshold_h) {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_B.Abs1;
      } else {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.Constant2_Value_c -
          fabs(load_arduino_v_15_B.Abs1);
      }

      /* Switch: '<S317>/Switch2' incorporates:
       *  Abs: '<S317>/Abs'
       *  Constant: '<S317>/Constant2'
       *  Sum: '<S317>/Sum'
       */
      if (!(load_arduino_v_15_B.psi_ref_pre >
            load_arduino_v_15_P.Switch2_Threshold_m)) {
        load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Constant2_Value_f
          - fabs(load_arduino_v_15_B.psi_ref_pre);
      }

      load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.Sum1_m -
        load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_P.Kp_Rotta_psi;
      break;

     case 3:
      /* Switch: '<S318>/Switch2' incorporates:
       *  Abs: '<S318>/Abs'
       *  Constant: '<S318>/Constant2'
       *  Sum: '<S318>/Sum'
       */
      if (load_arduino_v_15_B.Abs1 > load_arduino_v_15_P.Switch2_Threshold_h) {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_B.Abs1;
      } else {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.Constant2_Value_c -
          fabs(load_arduino_v_15_B.Abs1);
      }

      /* Switch: '<S317>/Switch2' incorporates:
       *  Abs: '<S317>/Abs'
       *  Constant: '<S317>/Constant2'
       *  Sum: '<S317>/Sum'
       */
      if (!(load_arduino_v_15_B.psi_ref_pre >
            load_arduino_v_15_P.Switch2_Threshold_m)) {
        load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Constant2_Value_f
          - fabs(load_arduino_v_15_B.psi_ref_pre);
      }

      load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.Sum1_m -
        load_arduino_v_15_B.psi_ref_pre) * load_arduino_v_15_P.Kp_Rotta_psi;
      break;
    }

    /* End of MultiPortSwitch: '<S304>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S304>/Multiport Switch2' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 6' incorporates:
   *  Gain: '<S39>/Gain2'
   */
  if ((int32_T)load_arduino_v_15_B.switch_timone != 0) {
    /* MultiPortSwitch: '<S39>/Switch Bumpless 4' incorporates:
     *  MATLAB Function: '<S40>/MATLAB Function'
     *  MultiPortSwitch: '<S304>/Multiport Switch3'
     */
    if ((int32_T)load_arduino_v_15_B.switch_timone == 0) {
      load_arduino_v_15_B.Sum1_m = load_arduino_v_15_B.angoloWP;
    } else {
      if (load_arduino_v_15_B.pipk != 0) {
        /* Switch: '<S304>/Switch3' incorporates:
         *  Constant: '<S304>/Constant3'
         *  DataTypeConversion: '<S571>/Data Type Conversion5'
         *  MultiPortSwitch: '<S304>/Multiport Switch3'
         *  Product: '<S304>/Product4'
         *  Sum: '<S304>/Sum2'
         */
        if (!(load_arduino_v_15_B.ByteUnpack_o2[2] >
              load_arduino_v_15_P.Switch3_Threshold)) {
          /* Gain: '<S314>/Gain' */
          load_arduino_v_15_B.angoloWP = load_arduino_v_15_P.Gain_Gain_b *
            load_arduino_v_15_B.Wp_selector;

          /* Switch: '<S316>/Switch2' incorporates:
           *  Abs: '<S316>/Abs'
           *  Constant: '<S316>/Constant2'
           *  Sum: '<S316>/Sum'
           */
          if (!(load_arduino_v_15_B.Abs1 > load_arduino_v_15_P.Switch2_Threshold))
          {
            load_arduino_v_15_B.Abs1 = load_arduino_v_15_P.Constant2_Value_b -
              fabs(load_arduino_v_15_B.Abs1);
          }

          /* End of Switch: '<S316>/Switch2' */

          /* Switch: '<S315>/Switch2' incorporates:
           *  Abs: '<S315>/Abs'
           *  Constant: '<S315>/Constant2'
           *  Sum: '<S315>/Sum'
           */
          if (!(load_arduino_v_15_B.angoloWP >
                load_arduino_v_15_P.Switch2_Threshold_i)) {
            load_arduino_v_15_B.angoloWP = load_arduino_v_15_P.Constant2_Value_o
              - fabs(load_arduino_v_15_B.angoloWP);
          }

          /* End of Switch: '<S315>/Switch2' */
          load_arduino_v_15_B.Sum1_m = (load_arduino_v_15_B.Abs1 -
            load_arduino_v_15_B.angoloWP) * load_arduino_v_15_P.Kp_Rotta_psi;
        }

        /* End of Switch: '<S304>/Switch3' */
      }
    }

    /* End of MultiPortSwitch: '<S39>/Switch Bumpless 4' */

    /* Saturate: '<S39>/saturatore R' */
    if (load_arduino_v_15_B.Sum1_m > load_arduino_v_15_P.attuatore_Rmax) {
      load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.attuatore_Rmax;
    } else {
      if (load_arduino_v_15_B.Sum1_m < load_arduino_v_15_P.attuatore_Rmin) {
        load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.attuatore_Rmin;
      }
    }

    /* End of Saturate: '<S39>/saturatore R' */
    load_arduino_v_15_B.angoloWP = load_arduino_v_15_P.inv_R *
      load_arduino_v_15_B.Sum1_m;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 6' */

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S599>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   *  Product: '<S599>/Divide'
   *  Product: '<S599>/Multiply'
   *  Sum: '<S599>/Sum'
   *  Sum: '<S599>/Sum3'
   */
  load_arduino_v_15_B.Ato_selector = floor((load_arduino_v_15_B.angoloWP -
    load_arduino_v_15_P.attuatore_Rmin) / load_arduino_v_15_B.Ato_selector *
    load_arduino_v_15_B.Sum_h + (real_T)
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[7]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  load_arduino_v_15_B.DataTypeConversion2_j = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */
  Servo_microseconds_timone_beta_3_Outputs_wrapper
    (&load_arduino_v_15_B.DataTypeConversion2_j,
     &load_arduino_v_15_DW.SFunctionBuilder5_DSTATE);

  /* S-Function (PWMinterrupt_elevator_v4_4): '<S9>/S-Function Builder1' */
  PWMinterrupt_elevator_v4_4_Outputs_wrapper(&load_arduino_v_15_B.PWM_elevator);

  /* Sum: '<S42>/Sum1' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   */
  load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.Al_selector -
    load_arduino_v_15_B.ByteUnpack_o2[2];

  /* Abs: '<S42>/Abs' */
  load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.psi_ref_pre);

  /* Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  if (load_arduino_v_15_DW.is_active_c23_load_arduino_v_15 == 0U) {
    load_arduino_v_15_DW.is_active_c23_load_arduino_v_15 = 1U;
    load_arduino_v_15_DW.is_c23_load_arduino_v_15 = load_arduino_v_15_IN_Select;
  } else if (load_arduino_v_15_DW.is_c23_load_arduino_v_15 == 1) {
    if (load_arduino_v_15_B.Ato_selector > 10.0) {
      load_arduino_v_15_DW.is_c23_load_arduino_v_15 =
        load_arduino_v_15_IN_Select;
    } else {
      load_arduino_v_15_B.mod = 0.0;
    }
  } else {
    /* case IN_Select: */
    if (load_arduino_v_15_B.Ato_selector < 10.0) {
      load_arduino_v_15_DW.is_c23_load_arduino_v_15 = load_arduino_v_15_IN_Hold;
    } else {
      load_arduino_v_15_B.mod = 1.0;
    }
  }

  /* End of Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */

  /* Sum: '<S595>/Sum2' incorporates:
   *  Constant: '<S595>/Constant8'
   *  Constant: '<S595>/Constant9'
   *  Sum: '<S601>/Sum1'
   */
  load_arduino_v_15_B.rtb_Sum3_o_tmp = load_arduino_v_15_P.attuatore_Emax -
    load_arduino_v_15_P.attuatore_Emin;

  /* Product: '<S595>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion6'
   *  DataTypeConversion: '<S9>/Data Type Conversion7'
   *  Product: '<S601>/Multiply'
   *  Sum: '<S595>/Sum1'
   */
  load_arduino_v_15_B.rtb_Sum3_o_tmp_j =
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[2] -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[3];

  /* Sum: '<S595>/Sum3' incorporates:
   *  Constant: '<S595>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion13'
   *  DataTypeConversion: '<S9>/Data Type Conversion7'
   *  Product: '<S595>/Divide'
   *  Product: '<S595>/Multiply'
   *  Sum: '<S595>/Sum'
   *  Sum: '<S595>/Sum2'
   */
  load_arduino_v_15_B.Abs1 = (real_T)(load_arduino_v_15_B.PWM_elevator -
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[3]) /
    load_arduino_v_15_B.rtb_Sum3_o_tmp_j * load_arduino_v_15_B.rtb_Sum3_o_tmp +
    load_arduino_v_15_P.attuatore_Emin;

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation' */
  switch ((int32_T)load_arduino_v_15_B.modo) {
   case 1:
    load_arduino_v_15_B.RC_l = load_arduino_v_15_B.RC;
    break;

   case 2:
    load_arduino_v_15_B.RC_l = load_arduino_v_15_B.RC_vett;
    break;

   case 3:
    load_arduino_v_15_B.RC_l = load_arduino_v_15_B.RC_ref;
    break;

   case 4:
    load_arduino_v_15_B.RC_l =
      load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna;
    break;

   default:
    load_arduino_v_15_B.RC_l = load_arduino_v_15_B.RC_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation' */

  /* MultiPortSwitch: '<S45>/Multiport Switch1' incorporates:
   *  Constant: '<S45>/Constant2'
   *  MultiPortSwitch: '<S42>/Switch HOLD//SELECT'
   *  Sum: '<S45>/Sum1'
   */
  if ((int32_T)load_arduino_v_15_B.switch_equilibratore == 0) {
    load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_P.Constant2_Value_by;
  } else {
    if ((int32_T)load_arduino_v_15_B.mod == 0) {
      /* Lookup_n-D: '<S8>/n-D Lookup Table' incorporates:
       *  MultiPortSwitch: '<S42>/Switch HOLD//SELECT'
       */
      load_arduino_v_15_B.Ato_selector = look1_binlxpw
        (load_arduino_v_15_B.rtb_Gain1_idx_1,
         load_arduino_v_15_P.nDLookupTable_bp01Data,
         load_arduino_v_15_P.nDLookupTable_tableData, 1U);

      /* Saturate: '<S8>/Saturation' incorporates:
       *  MultiPortSwitch: '<S42>/Switch HOLD//SELECT'
       */
      if (load_arduino_v_15_B.Ato_selector >
          load_arduino_v_15_P.Kp_AP_quota_hold_l) {
        load_arduino_v_15_B.Ato_selector =
          load_arduino_v_15_P.Kp_AP_quota_hold_l;
      } else {
        if (load_arduino_v_15_B.Ato_selector <
            load_arduino_v_15_P.Kp_AP_quota_hold_h) {
          load_arduino_v_15_B.Ato_selector =
            load_arduino_v_15_P.Kp_AP_quota_hold_h;
        }
      }

      /* End of Saturate: '<S8>/Saturation' */

      /* MultiPortSwitch: '<S42>/Switch HOLD//SELECT' incorporates:
       *  Product: '<S42>/Kp'
       */
      load_arduino_v_15_B.Ato_selector *= load_arduino_v_15_B.psi_ref_pre;
    } else {
      /* MultiPortSwitch: '<S42>/Switch HOLD//SELECT' */
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.RC_l;
    }

    /* Lookup: '<S47>/Lookup Table2' */
    load_arduino_v_15_B.psi_ref_pre = rt_Lookup
      (&load_arduino_v_15_P.LookupTable2_XData[0], 6,
       load_arduino_v_15_B.rtb_Gain1_idx_1,
       &load_arduino_v_15_P.LookupTable2_YData[0]);

    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S47>/Constant'
     *  RelationalOperator: '<S195>/LowerRelop1'
     *  RelationalOperator: '<S195>/UpperRelop'
     *  Switch: '<S195>/Switch'
     */
    if (load_arduino_v_15_B.Ato_selector > load_arduino_v_15_B.psi_ref_pre) {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.psi_ref_pre;
    } else {
      if (load_arduino_v_15_B.Ato_selector <
          load_arduino_v_15_P.Constant_Value_d) {
        /* Switch: '<S195>/Switch' incorporates:
         *  Constant: '<S47>/Constant'
         */
        load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant_Value_d;
      }
    }

    /* End of Switch: '<S195>/Switch2' */
    load_arduino_v_15_B.psi_ref_pre = load_arduino_v_15_B.Ato_selector -
      load_arduino_v_15_B.num_254;
  }

  /* End of MultiPortSwitch: '<S45>/Multiport Switch1' */

  /* DiscreteIntegrator: '<S178>/Integrator' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if ((load_arduino_v_15_B.ATO > 0) &&
      (load_arduino_v_15_DW.Integrator_PrevResetState_c <= 0)) {
    load_arduino_v_15_DW.Integrator_DSTATE_h =
      load_arduino_v_15_P.PIRCsaturato_InitialConditionFo;
  }

  /* Sum: '<S187>/Sum' incorporates:
   *  Constant: '<S45>/Constant5'
   *  DiscreteIntegrator: '<S178>/Integrator'
   *  Product: '<S183>/PProd Out'
   */
  load_arduino_v_15_B.Sum_h = load_arduino_v_15_B.psi_ref_pre *
    load_arduino_v_15_P.Kp_h_cruise + load_arduino_v_15_DW.Integrator_DSTATE_h;

  /* MultiPortSwitch: '<S45>/Multiport Switch' incorporates:
   *  Constant: '<S45>/Constant1'
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   *  Sum: '<S45>/Sum2'
   */
  if ((int32_T)load_arduino_v_15_B.switch_equilibratore == 0) {
    load_arduino_v_15_B.Sum1_m = load_arduino_v_15_P.Constant1_Value_l;
  } else {
    load_arduino_v_15_B.Sum1_m = load_arduino_v_15_B.Al_selector -
      load_arduino_v_15_B.ByteUnpack_o2[2];
  }

  /* End of MultiPortSwitch: '<S45>/Multiport Switch' */

  /* DiscreteIntegrator: '<S82>/Integrator' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if ((load_arduino_v_15_B.ATO > 0) &&
      (load_arduino_v_15_DW.Integrator_PrevResetState_a <= 0)) {
    load_arduino_v_15_DW.Integrator_DSTATE_g =
      load_arduino_v_15_P.PIApproach_InitialConditionForI;
  }

  /* DiscreteIntegrator: '<S77>/Filter' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if ((load_arduino_v_15_B.ATO > 0) &&
      (load_arduino_v_15_DW.Filter_PrevResetState <= 0)) {
    load_arduino_v_15_DW.Filter_DSTATE_l =
      load_arduino_v_15_P.PIApproach_InitialConditionForF;
  }

  /* Product: '<S85>/NProd Out' incorporates:
   *  Constant: '<S45>/Constant14'
   *  Constant: '<S45>/Constant15'
   *  DiscreteIntegrator: '<S77>/Filter'
   *  Product: '<S76>/DProd Out'
   *  Sum: '<S77>/SumD'
   */
  load_arduino_v_15_B.NProdOut_m = (load_arduino_v_15_B.Sum1_m *
    load_arduino_v_15_P.Kd_h_app - load_arduino_v_15_DW.Filter_DSTATE_l) *
    load_arduino_v_15_P.Constant15_Value;

  /* Lookup_n-D: '<S45>/n-D Lookup Table' */
  load_arduino_v_15_B.Ato_selector = look1_binlxpw
    (load_arduino_v_15_B.rtb_Gain1_idx_1,
     load_arduino_v_15_P.nDLookupTable_bp01Data_l,
     load_arduino_v_15_P.nDLookupTable_tableData_c, 1U);

  /* Saturate: '<S45>/Saturation' */
  if (load_arduino_v_15_B.Ato_selector > load_arduino_v_15_P.Saturation_UpperSat)
  {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Saturation_UpperSat;
  } else {
    if (load_arduino_v_15_B.Ato_selector <
        load_arduino_v_15_P.Saturation_LowerSat) {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* Sum: '<S91>/Sum' incorporates:
   *  DiscreteIntegrator: '<S82>/Integrator'
   *  Product: '<S87>/PProd Out'
   */
  load_arduino_v_15_B.Sum_d = (load_arduino_v_15_B.Sum1_m *
    load_arduino_v_15_B.Ato_selector + load_arduino_v_15_DW.Integrator_DSTATE_g)
    + load_arduino_v_15_B.NProdOut_m;

  /* MultiPortSwitch: '<S45>/Multiport Switch2' incorporates:
   *  Constant: '<S45>/Constant3'
   *  Sum: '<S45>/Sum4'
   */
  if ((int32_T)load_arduino_v_15_B.switch_equilibratore == 0) {
    load_arduino_v_15_B.RC_l = load_arduino_v_15_P.Constant3_Value_f;
  } else {
    load_arduino_v_15_B.RC_l -= load_arduino_v_15_B.num_254;
  }

  /* End of MultiPortSwitch: '<S45>/Multiport Switch2' */

  /* DiscreteIntegrator: '<S130>/Integrator' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if ((load_arduino_v_15_B.ATO > 0) &&
      (load_arduino_v_15_DW.Integrator_PrevResetState_f <= 0)) {
    load_arduino_v_15_DW.Integrator_DSTATE_d5 =
      load_arduino_v_15_P.PIApproach1_InitialConditionF_n;
  }

  /* DiscreteIntegrator: '<S125>/Filter' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if ((load_arduino_v_15_B.ATO > 0) &&
      (load_arduino_v_15_DW.Filter_PrevResetState_f <= 0)) {
    load_arduino_v_15_DW.Filter_DSTATE_k =
      load_arduino_v_15_P.PIApproach1_InitialConditionFor;
  }

  /* Product: '<S133>/NProd Out' incorporates:
   *  Constant: '<S45>/Constant13'
   *  Constant: '<S45>/Constant9'
   *  DiscreteIntegrator: '<S125>/Filter'
   *  Product: '<S124>/DProd Out'
   *  Sum: '<S125>/SumD'
   */
  load_arduino_v_15_B.NProdOut_j = (load_arduino_v_15_B.RC_l *
    load_arduino_v_15_P.Kd_h_flare - load_arduino_v_15_DW.Filter_DSTATE_k) *
    load_arduino_v_15_P.Constant13_Value;

  /* Sum: '<S139>/Sum' incorporates:
   *  Constant: '<S45>/Constant11'
   *  DiscreteIntegrator: '<S130>/Integrator'
   *  Product: '<S135>/PProd Out'
   */
  load_arduino_v_15_B.Sum_l = (load_arduino_v_15_B.RC_l *
    load_arduino_v_15_P.Kp_h_flare + load_arduino_v_15_DW.Integrator_DSTATE_d5)
    + load_arduino_v_15_B.NProdOut_j;

  /* MultiPortSwitch: '<S38>/Switch di selezioneriferimeti  per i loop interni 2' */
  if ((int32_T)load_arduino_v_15_B.Switch_n == 0) {
    /* MultiPortSwitch: '<S45>/Switch auto-manual' incorporates:
     *  MultiPortSwitch: '<S45>/Switch rc saturata'
     */
    if ((int32_T)load_arduino_v_15_B.switch_equilibratore == 0) {
      load_arduino_v_15_B.theta_rif = load_arduino_v_15_B.Gain1_a;
    } else if ((int32_T)load_arduino_v_15_B.mod == 0) {
      /* MultiPortSwitch: '<S45>/Switch maneuver' incorporates:
       *  MultiPortSwitch: '<S45>/Switch rc saturata'
       */
      switch ((int32_T)load_arduino_v_15_B.landing_selector) {
       case 0:
        load_arduino_v_15_B.theta_rif = load_arduino_v_15_B.Sum_h;
        break;

       case 1:
        load_arduino_v_15_B.theta_rif = load_arduino_v_15_B.Sum_d;
        break;

       default:
        load_arduino_v_15_B.theta_rif = load_arduino_v_15_B.Sum_l;
        break;
      }

      /* End of MultiPortSwitch: '<S45>/Switch maneuver' */
    } else {
      /* MultiPortSwitch: '<S45>/Switch rc saturata' */
      load_arduino_v_15_B.theta_rif = load_arduino_v_15_B.Sum_h;
    }

    /* End of MultiPortSwitch: '<S45>/Switch auto-manual' */
  } else {
    load_arduino_v_15_B.theta_rif = load_arduino_v_15_B.theta_safe;
  }

  /* End of MultiPortSwitch: '<S38>/Switch di selezioneriferimeti  per i loop interni 2' */

  /* MultiPortSwitch: '<S311>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.ATO != 0) {
    /* MultiPortSwitch: '<S311>/Multiport Switch1' incorporates:
     *  Constant: '<S311>/Constant'
     *  Gain: '<S420>/Gain1'
     */
    switch ((int32_T)load_arduino_v_15_B.Fase_ATO) {
     case 0:
      load_arduino_v_15_B.theta_rif = load_arduino_v_15_P.Constant_Value_at;
      break;

     case 1:
      load_arduino_v_15_B.theta_rif = load_arduino_v_15_P.Constant_Value_at;
      break;

     case 2:
      load_arduino_v_15_B.theta_rif = load_arduino_v_15_P.Constant_Value_at;
      break;

     case 3:
      load_arduino_v_15_B.theta_rif = load_arduino_v_15_P.Gain1_Gain *
        load_arduino_v_15_B.pitch_ref;
      break;
    }

    /* End of MultiPortSwitch: '<S311>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S311>/Multiport Switch2' */

  /* Sum: '<S39>/Sum2' */
  load_arduino_v_15_B.e_b = load_arduino_v_15_B.theta_rif -
    load_arduino_v_15_B.Gain1_a;

  /* Sum: '<S362>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore beccheggio1'
   *  DiscreteIntegrator: '<S353>/Integrator'
   *  Product: '<S358>/PProd Out'
   */
  load_arduino_v_15_B.Sum_a1 = load_arduino_v_15_B.e_b *
    load_arduino_v_15_P.Kp_becch + load_arduino_v_15_DW.Integrator_DSTATE_l;

  /* Saturate: '<S360>/Saturation' */
  if (load_arduino_v_15_B.Sum_a1 > load_arduino_v_15_P.attuatore_Emax) {
    load_arduino_v_15_B.Saturation_i = load_arduino_v_15_P.attuatore_Emax;
  } else if (load_arduino_v_15_B.Sum_a1 < load_arduino_v_15_P.attuatore_Emin) {
    load_arduino_v_15_B.Saturation_i = load_arduino_v_15_P.attuatore_Emin;
  } else {
    load_arduino_v_15_B.Saturation_i = load_arduino_v_15_B.Sum_a1;
  }

  /* End of Saturate: '<S360>/Saturation' */

  /* MultiPortSwitch: '<S305>/Switch Bumpless 2' */
  if ((int32_T)load_arduino_v_15_B.switch_equilibratore == 0) {
    load_arduino_v_15_B.SwitchBumpless2 = load_arduino_v_15_B.Abs1;
  } else {
    load_arduino_v_15_B.SwitchBumpless2 = load_arduino_v_15_B.Saturation_i;
  }

  /* End of MultiPortSwitch: '<S305>/Switch Bumpless 2' */

  /* MultiPortSwitch: '<S320>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.pipk != 0) {
    /* Switch: '<S320>/Switch1' incorporates:
     *  Constant: '<S320>/Constant5'
     */
    if (!(load_arduino_v_15_B.rtb_Gain4_idx_0 >= load_arduino_v_15_P.V_stall *
          1.1)) {
      load_arduino_v_15_B.SwitchBumpless2 = load_arduino_v_15_P.Constant5_Value;
    }

    /* End of Switch: '<S320>/Switch1' */
  }

  /* End of MultiPortSwitch: '<S320>/Multiport Switch2' */

  /* MultiPortSwitch: '<S321>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (load_arduino_v_15_B.ATO != 0) {
    /* MultiPortSwitch: '<S321>/Multiport Switch1' incorporates:
     *  Gain: '<S370>/Gain1'
     */
    switch ((int32_T)load_arduino_v_15_B.Fase_ATO) {
     case 0:
      load_arduino_v_15_B.SwitchBumpless2 = load_arduino_v_15_P.Gain1_Gain_l *
        load_arduino_v_15_B.eq_rot;
      break;

     case 1:
      load_arduino_v_15_B.SwitchBumpless2 = load_arduino_v_15_P.Gain1_Gain_l *
        load_arduino_v_15_B.eq_rot;
      break;

     case 2:
      load_arduino_v_15_B.SwitchBumpless2 = load_arduino_v_15_P.Gain1_Gain_l *
        load_arduino_v_15_B.eq_rot;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S321>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S321>/Multiport Switch2' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 1' incorporates:
   *  Gain: '<S39>/Gain'
   */
  if ((int32_T)load_arduino_v_15_B.switch_equilibratore != 0) {
    /* MultiPortSwitch: '<S305>/Switch 1' incorporates:
     *  Abs: '<S305>/Abs1'
     *  Constant: '<S305>/Constant1'
     *  Constant: '<S305>/Constant2'
     *  Constant: '<S305>/Constant3'
     *  Constant: '<S8>/Kp controllore velocità beccheggio1'
     *  Gain: '<S305>/Gain'
     *  MultiPortSwitch: '<S305>/Switch  2'
     *  Product: '<S305>/Product3'
     *  Product: '<S305>/Product4'
     *  Product: '<S305>/Product5'
     *  Sum: '<S305>/Sum3'
     *  Trigonometry: '<S305>/Trigonometric Function'
     */
    if ((int32_T)load_arduino_v_15_B.switch_equilibratore == 0) {
      load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Constant1_Value_i;
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant2_Value_em;
    } else {
      /* Abs: '<S305>/Abs1' incorporates:
       *  Abs: '<S305>/Abs'
       */
      load_arduino_v_15_B.Ato_selector = fabs(load_arduino_v_15_B.Gain1_b);
      load_arduino_v_15_B.Al_selector =
        (load_arduino_v_15_B.DataTypeConversion1_b[4] - sin
         (load_arduino_v_15_B.Ato_selector) *
         load_arduino_v_15_B.DataTypeConversion1_b[5]) *
        load_arduino_v_15_P.Kp_q;
      load_arduino_v_15_B.Ato_selector *= load_arduino_v_15_P.inv_comp_h *
        load_arduino_v_15_P.Kp_comp_h;
    }

    /* End of MultiPortSwitch: '<S305>/Switch 1' */

    /* Sum: '<S305>/Sum2' incorporates:
     *  Sum: '<S305>/Sum'
     */
    load_arduino_v_15_B.Ato_selector = (load_arduino_v_15_B.SwitchBumpless2 -
      load_arduino_v_15_B.Al_selector) - load_arduino_v_15_B.Ato_selector;

    /* Saturate: '<S305>/saturatore E2' */
    if (load_arduino_v_15_B.Ato_selector > load_arduino_v_15_P.attuatore_Emax) {
      load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.attuatore_Emax;
    } else {
      if (load_arduino_v_15_B.Ato_selector < load_arduino_v_15_P.attuatore_Emin)
      {
        load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.attuatore_Emin;
      }
    }

    /* End of Saturate: '<S305>/saturatore E2' */
    load_arduino_v_15_B.Abs1 = load_arduino_v_15_P.inv_E *
      load_arduino_v_15_B.Ato_selector;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 1' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S601>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion7'
   *  Product: '<S601>/Divide'
   *  Product: '<S601>/Multiply'
   *  Sum: '<S601>/Sum'
   *  Sum: '<S601>/Sum3'
   */
  load_arduino_v_15_B.Ato_selector = floor((load_arduino_v_15_B.Abs1 -
    load_arduino_v_15_P.attuatore_Emin) / load_arduino_v_15_B.rtb_Sum3_o_tmp *
    load_arduino_v_15_B.rtb_Sum3_o_tmp_j + (real_T)
    load_arduino_v_15_B.One_time_initialization.ByteUnpack[3]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_p = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper
    (&load_arduino_v_15_B.DataTypeConversion_p,
     &load_arduino_v_15_DW.SFunctionBuilder9_DSTATE);

  /* RateTransition: '<S29>/Rate Transition' */
  load_arduino_v_15_B.Ato_selector = load_arduino_v_15_DW.RateTransition_Buffer0;

  /* Sum: '<S29>/Add1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  Memory: '<S29>/Memory1'
   */
  load_arduino_v_15_B.Al_selector = (load_arduino_v_15_P.Constant2_Value_jg +
    load_arduino_v_15_P.Constant3_Value_o) +
    load_arduino_v_15_DW.Memory1_PreviousInput;

  /* Switch: '<S29>/Switch' */
  if (load_arduino_v_15_B.Al_selector > load_arduino_v_15_P.Switch_Threshold_f)
  {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant2'
     */
    load_arduino_v_15_DW.Memory1_PreviousInput =
      load_arduino_v_15_P.Constant2_Value_jg;
  } else {
    /* Switch: '<S29>/Switch' */
    load_arduino_v_15_DW.Memory1_PreviousInput = load_arduino_v_15_B.Al_selector;
  }

  /* End of Switch: '<S29>/Switch' */

  /* MATLAB Function: '<S19>/iflogic_function' */
  if ((load_arduino_v_15_DW.Memory1_PreviousInput == 1.0) ||
      (load_arduino_v_15_DW.Memory1_PreviousInput == 3.0)) {
    load_arduino_v_15_B.iflogic = 26U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 2.0) ||
             (load_arduino_v_15_DW.Memory1_PreviousInput == 4.0)) {
    load_arduino_v_15_B.iflogic = 30U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_15_B.Ato_selector == 2.0)) {
    load_arduino_v_15_B.iflogic = 33U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_15_B.Ato_selector == 6.0)) {
    load_arduino_v_15_B.iflogic = 34U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_15_B.Ato_selector == 0.0)) {
    load_arduino_v_15_B.iflogic = 0U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             ((load_arduino_v_15_B.Ato_selector == 1.0) ||
              (load_arduino_v_15_B.Ato_selector == 5.0) ||
              (load_arduino_v_15_B.Ato_selector == 9.0))) {
    load_arduino_v_15_B.iflogic = 1U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             ((load_arduino_v_15_B.Ato_selector == 3.0) ||
              (load_arduino_v_15_B.Ato_selector == 8.0))) {
    load_arduino_v_15_B.iflogic = 74U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_15_B.Ato_selector == 7.0)) {
    load_arduino_v_15_B.iflogic = 36U;
  } else if ((load_arduino_v_15_DW.Memory1_PreviousInput == 0.0) &&
             (load_arduino_v_15_B.Ato_selector == 4.0)) {
    load_arduino_v_15_B.iflogic = 29U;
  } else {
    load_arduino_v_15_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S19>/iflogic_function' */

  /* Sum: '<S29>/Add' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant1'
   *  Memory: '<S29>/Memory'
   */
  load_arduino_v_15_DW.Memory_PreviousInput +=
    load_arduino_v_15_P.Constant_Value_m +
    load_arduino_v_15_P.Constant1_Value_n0;

  /* Gain: '<S19>/Gain' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_cw *
    load_arduino_v_15_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  load_arduino_v_15_B.DataTypeConversion3 = load_arduino_v_15_B.Ato_selector <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-load_arduino_v_15_B.Ato_selector :
    (uint32_T)load_arduino_v_15_B.Ato_selector;

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 6;
       load_arduino_v_15_B.pipk++) {
    load_arduino_v_15_B.WP_info[load_arduino_v_15_B.pipk] =
      load_arduino_v_15_DW.WP_dbI[6 * load_arduino_v_15_B.pipk];
  }

  for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 7;
       load_arduino_v_15_B.pipk++) {
    load_arduino_v_15_B.WP_param[load_arduino_v_15_B.pipk] =
      load_arduino_v_15_DW.WP_dbP[6 * load_arduino_v_15_B.pipk];
  }

  if ((load_arduino_v_15_B.GC_info[0] == 2) && (load_arduino_v_15_B.GC_info[1] <
       6)) {
    load_arduino_v_15_B.qY = load_arduino_v_15_B.GC_info[1] + 1U;
    if (load_arduino_v_15_B.GC_info[1] + 1U > 65535U) {
      load_arduino_v_15_B.qY = 65535U;
    }

    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 6;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.WP_info[load_arduino_v_15_B.pipk] =
        load_arduino_v_15_DW.WP_dbI[(6 * load_arduino_v_15_B.pipk + (int32_T)
        load_arduino_v_15_B.qY) - 1];
    }

    load_arduino_v_15_B.qY = load_arduino_v_15_B.GC_info[1] + 1U;
    if (load_arduino_v_15_B.GC_info[1] + 1U > 65535U) {
      load_arduino_v_15_B.qY = 65535U;
    }

    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 7;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.WP_param[load_arduino_v_15_B.pipk] =
        load_arduino_v_15_DW.WP_dbP[(6 * load_arduino_v_15_B.pipk + (int32_T)
        load_arduino_v_15_B.qY) - 1];
    }
  }

  if ((load_arduino_v_15_B.GC_info[0] == 3) && (load_arduino_v_15_B.GC_info[1] <
       200)) {
    load_arduino_v_15_B.qY = load_arduino_v_15_B.GC_info[1] + 1U;
    if (load_arduino_v_15_B.GC_info[1] + 1U > 65535U) {
      load_arduino_v_15_B.qY = 65535U;
    }

    for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 6;
         load_arduino_v_15_B.pipk++) {
      load_arduino_v_15_B.WP_info[load_arduino_v_15_B.pipk] =
        load_arduino_v_15_DW.WP_dbI[(6 * load_arduino_v_15_B.pipk + (int32_T)
        load_arduino_v_15_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function' */

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S7>/Constant'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Gain_Gain_by *
    load_arduino_v_15_P.Constant_Value_jp[0]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/load uint16'
   *  Gain: '<S21>/Gain'
   */
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[0] =
    load_arduino_v_15_P.loaduint16_Value;
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  load_arduino_v_15_B.qY = 10U * load_arduino_v_15_B.z;
  if (load_arduino_v_15_B.qY > 65535U) {
    load_arduino_v_15_B.qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)
    load_arduino_v_15_B.qY;
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[3] =
    load_arduino_v_15_B.SFunction_o11[6];
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[4] =
    load_arduino_v_15_B.SFunction_o11[2];
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[5] =
    load_arduino_v_15_P._Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Switch_n);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S21>/Data Type Conversion4' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Constant2_Value_k);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S21>/Gain2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Gain2_Gain_o *
    load_arduino_v_15_P.Constant_Value_jp[2]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Gain: '<S21>/Gain2'
   */
  load_arduino_v_15_B.Gain1 = (int16_T)(((load_arduino_v_15_B.Ato_selector < 0.0
    ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.Ato_selector :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.Ato_selector) *
    load_arduino_v_15_P.Gain1_Gain_eu) >> 18);

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  load_arduino_v_15_B.Ato_selector = floor
    (load_arduino_v_15_P.Constant_Value_jp[1]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      256.0);
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion3' */
  load_arduino_v_15_B.B_Remaining = (int8_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-load_arduino_v_15_B.Ato_selector :
    (int32_T)(int8_T)(uint8_T)load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Constant_Value_ex);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion = load_arduino_v_15_B.Ato_selector <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-load_arduino_v_15_B.Ato_selector :
    (uint32_T)load_arduino_v_15_B.Ato_selector;

  /* MATLAB Function: '<S17>/Alarm set' incorporates:
   *  Constant: '<S40>/Constant2'
   *  SignalConversion generated from: '<S28>/ SFunction '
   */
  rtb_H_mav[0] = load_arduino_v_15_DW.Memory1_PreviousInput_d[0];
  rtb_H_mav[1] = load_arduino_v_15_DW.Memory1_PreviousInput_d[1];
  if (load_arduino_v_15_B.Switch_n == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (load_arduino_v_15_P.Constant2_Value_k == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S17>/Alarm set' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S17>/Type fixed_wing Autopilot generic'
   */
  load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[0] =
    load_arduino_v_15_P.Typefixed_wingAutopilotgeneric_[0];
  load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[2] = rtb_H_mav[0];
  load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[1] =
    load_arduino_v_15_P.Typefixed_wingAutopilotgeneric_[1];
  load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[3] = rtb_H_mav[1];
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 6;
       load_arduino_v_15_B.i++) {
    /* Gain: '<S18>/Gain' */
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_dn *
      load_arduino_v_15_B.DataTypeConversion1_b[load_arduino_v_15_B.i];

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    if (load_arduino_v_15_B.Al_selector < 0.0) {
      load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
    } else {
      load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
    }

    if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
        (load_arduino_v_15_B.Ato_selector)) {
      load_arduino_v_15_B.Ato_selector = 0.0;
    } else {
      load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
        65536.0);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    load_arduino_v_15_B.DataTypeConversion_ld[load_arduino_v_15_B.i] = (int16_T)
      (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
       (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
       load_arduino_v_15_B.Ato_selector);
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_dn *
    load_arduino_v_15_P.Constant_Value_hxg;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_ld[6] = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_dn *
    load_arduino_v_15_P.Constant1_Value_fi;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_ld[7] = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_dn *
    load_arduino_v_15_P.Constant2_Value_eu;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_ld[8] = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1[0] = (real32_T)
    load_arduino_v_15_B.Gain1_b;
  load_arduino_v_15_B.DataTypeConversion1[1] = (real32_T)
    load_arduino_v_15_B.Gain1_a;
  load_arduino_v_15_B.DataTypeConversion1[2] = (real32_T)
    load_arduino_v_15_B.Gain1_cvb;
  load_arduino_v_15_B.DataTypeConversion1[3] = (real32_T)
    load_arduino_v_15_B.DataTypeConversion1_b[3];
  load_arduino_v_15_B.DataTypeConversion1[4] = (real32_T)
    load_arduino_v_15_B.DataTypeConversion1_b[4];
  load_arduino_v_15_B.DataTypeConversion1[5] = (real32_T)
    load_arduino_v_15_B.DataTypeConversion1_b[5];

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S26>/Gain'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_f *
    load_arduino_v_15_B.Go_Home * load_arduino_v_15_P.Gain_Gain_bx[0];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_a[0] = load_arduino_v_15_B.Ato_selector
    < 0.0 ? -(int32_T)(uint32_T)-load_arduino_v_15_B.Ato_selector : (int32_T)
    (uint32_T)load_arduino_v_15_B.Ato_selector;

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S27>/Gain'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_ds *
    load_arduino_v_15_B.Gain1_cv * load_arduino_v_15_P.Gain_Gain_bx[1];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_a[1] = load_arduino_v_15_B.Ato_selector
    < 0.0 ? -(int32_T)(uint32_T)-load_arduino_v_15_B.Ato_selector : (int32_T)
    (uint32_T)load_arduino_v_15_B.Ato_selector;

  /* Gain: '<S16>/Gain' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_bx[2] *
    load_arduino_v_15_B.ByteUnpack_o2[2];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_a[2] = load_arduino_v_15_B.Ato_selector
    < 0.0 ? -(int32_T)(uint32_T)-load_arduino_v_15_B.Ato_selector : (int32_T)
    (uint32_T)load_arduino_v_15_B.Ato_selector;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/alt_r'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_bx[3] *
    load_arduino_v_15_P.alt_r_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_a[3] = load_arduino_v_15_B.Ato_selector
    < 0.0 ? -(int32_T)(uint32_T)-load_arduino_v_15_B.Ato_selector : (int32_T)
    (uint32_T)load_arduino_v_15_B.Ato_selector;

  /* Gain: '<S16>/Gain1' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain1_Gain_ej *
    load_arduino_v_15_B.rtb_Gain4_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_p[0] = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S16>/Gain1' incorporates:
   *  Constant: '<S16>/vel y'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain1_Gain_ej *
    load_arduino_v_15_P.vely_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_p[1] = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S16>/Gain1' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain1_Gain_ej *
    load_arduino_v_15_B.num_254;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_p[2] = (int16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S16>/Gain2' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain2_Gain_k *
    load_arduino_v_15_B.Wp_selector;

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  load_arduino_v_15_B.DataTypeConversion2_h = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion5'
   */
  load_arduino_v_15_B.AGAC[0] = (real32_T)load_arduino_v_15_B.rtb_Gain1_idx_1;
  load_arduino_v_15_B.AGAC[1] = (real32_T)load_arduino_v_15_B.rtb_Gain4_idx_0;
  load_arduino_v_15_B.AGAC[2] = load_arduino_v_15_B.ByteUnpack_o2[2];
  load_arduino_v_15_B.AGAC[3] = (real32_T)load_arduino_v_15_B.num_254;

  /* Gain: '<S35>/Gain' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_lb *
    load_arduino_v_15_B.Wp_selector;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Abs: '<S36>/Abs'
   *  Constant: '<S36>/Constant2'
   *  Sum: '<S36>/Sum'
   */
  if (!(load_arduino_v_15_B.Al_selector >
        load_arduino_v_15_P.Switch2_Threshold_a)) {
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Constant2_Value - fabs
      (load_arduino_v_15_B.Al_selector);
  }

  /* End of Switch: '<S36>/Switch2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading_g = (int16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(int16_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S22>/USCITA PERCENTUALE' incorporates:
   *  Constant: '<S6>/Constant'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.USCITAPERCENTUALE_Gain *
    load_arduino_v_15_P.Constant_Value_c;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  load_arduino_v_15_B.Throttle = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* Gain: '<S31>/Gain2' */
  load_arduino_v_15_B.dist_fut *= load_arduino_v_15_P.Gain2_Gain_j;

  /* Sum: '<S31>/Sum' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_P.Gain_Gain_od *
    load_arduino_v_15_B.Abs1 + load_arduino_v_15_P.Constant2_Value_m;

  /* Sum: '<S31>/Sum1' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S33>/Gain'
   */
  load_arduino_v_15_B.Abs1 = load_arduino_v_15_P.Gain_Gain_if *
    load_arduino_v_15_B.dist + load_arduino_v_15_P.Constant2_Value_m;

  /* Sum: '<S31>/Sum2' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S34>/Gain'
   */
  load_arduino_v_15_B.angoloWP = load_arduino_v_15_P.Gain_Gain_bh *
    load_arduino_v_15_B.angoloWP + load_arduino_v_15_P.Constant2_Value_m;

  /* Gain: '<S20>/Gain' */
  load_arduino_v_15_B.num_254 = load_arduino_v_15_P.Gain_Gain_jrt *
    load_arduino_v_15_DW.PrevY;

  /* Saturate: '<S20>/Saturation' */
  if (load_arduino_v_15_B.num_254 > load_arduino_v_15_P.Saturation_UpperSat_a) {
    load_arduino_v_15_B.num_254 = load_arduino_v_15_P.Saturation_UpperSat_a;
  } else {
    if (load_arduino_v_15_B.num_254 < load_arduino_v_15_P.Saturation_LowerSat_p)
    {
      load_arduino_v_15_B.num_254 = load_arduino_v_15_P.Saturation_LowerSat_p;
    }
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (load_arduino_v_15_P.Constant_Value_bh2 < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil
      (load_arduino_v_15_P.Constant_Value_bh2);
  } else {
    load_arduino_v_15_B.Ato_selector = floor
      (load_arduino_v_15_P.Constant_Value_bh2);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[0] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_15_B.dist_fut < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.dist_fut);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.dist_fut);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[1] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Al_selector);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Al_selector);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[2] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_15_B.Abs1 < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.Abs1);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.Abs1);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[3] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_15_B.angoloWP < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.angoloWP);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.angoloWP);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[4] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (load_arduino_v_15_P.Constant1_Value_p[0] < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil
      (load_arduino_v_15_P.Constant1_Value_p[0]);
  } else {
    load_arduino_v_15_B.Ato_selector = floor
      (load_arduino_v_15_P.Constant1_Value_p[0]);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[5] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (load_arduino_v_15_P.Constant1_Value_p[1] < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil
      (load_arduino_v_15_P.Constant1_Value_p[1]);
  } else {
    load_arduino_v_15_B.Ato_selector = floor
      (load_arduino_v_15_P.Constant1_Value_p[1]);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[6] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (load_arduino_v_15_P.Constant1_Value_p[2] < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil
      (load_arduino_v_15_P.Constant1_Value_p[2]);
  } else {
    load_arduino_v_15_B.Ato_selector = floor
      (load_arduino_v_15_P.Constant1_Value_p[2]);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[7] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (load_arduino_v_15_B.num_254 < 0.0) {
    load_arduino_v_15_B.Ato_selector = ceil(load_arduino_v_15_B.num_254);
  } else {
    load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_B.num_254);
  }

  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  load_arduino_v_15_B.Heading[8] = (uint16_T)(load_arduino_v_15_B.Ato_selector <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
    load_arduino_v_15_B.Ato_selector);

  /* Memory: '<S2>/Memory' */
  load_arduino_v_15_B.Memory_a = load_arduino_v_15_DW.Memory_PreviousInput_n;

  /* MATLAB Function: '<S578>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S578>/Data Type Conversion'
   *  DataTypeConversion: '<S578>/Data Type Conversion2'
   */
  if (load_arduino_v_15_B.SFunction_o14 == 1) {
    load_arduino_v_15_DW.P_ref = load_arduino_v_15_B.SFunctionBuilder1;
  }

  if (load_arduino_v_15_B.SFunction_o16 == 1) {
    load_arduino_v_15_DW.P_ref = load_arduino_v_15_B.SFunction_o17;
    load_arduino_v_15_DW.rl_up = 20.0;
    load_arduino_v_15_DW.rl_dw = -20.0;
  }

  /* Product: '<S581>/delta rise limit' incorporates:
   *  MATLAB Function: '<S578>/MATLAB Function'
   *  SampleTimeMath: '<S581>/sample time'
   *
   * About '<S581>/sample time':
   *  y = K where K = ( w * Ts )
   */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_DW.rl_up *
    load_arduino_v_15_P.sampletime_WtEt;

  /* Sum: '<S581>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S578>/MATLAB Function'
   *  UnitDelay: '<S581>/Delay Input2'
   *
   * Block description for '<S581>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S581>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_15_B.num_254 = load_arduino_v_15_DW.P_ref -
    load_arduino_v_15_DW.DelayInput2_DSTATE;

  /* Switch: '<S587>/Switch2' incorporates:
   *  RelationalOperator: '<S587>/LowerRelop1'
   */
  if (!(load_arduino_v_15_B.num_254 > load_arduino_v_15_B.Al_selector)) {
    /* Product: '<S581>/delta fall limit' incorporates:
     *  MATLAB Function: '<S578>/MATLAB Function'
     *  SampleTimeMath: '<S581>/sample time'
     *
     * About '<S581>/sample time':
     *  y = K where K = ( w * Ts )
     */
    load_arduino_v_15_B.Al_selector = load_arduino_v_15_DW.rl_dw *
      load_arduino_v_15_P.sampletime_WtEt;

    /* Switch: '<S587>/Switch' incorporates:
     *  RelationalOperator: '<S587>/UpperRelop'
     */
    if (!(load_arduino_v_15_B.num_254 < load_arduino_v_15_B.Al_selector)) {
      load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.num_254;
    }

    /* End of Switch: '<S587>/Switch' */
  }

  /* End of Switch: '<S587>/Switch2' */

  /* Sum: '<S581>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S581>/Delay Input2'
   *
   * Block description for '<S581>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S581>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_15_DW.DelayInput2_DSTATE += load_arduino_v_15_B.Al_selector;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S581>/Delay Input2'
   *
   * Block description for '<S581>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_15_B.DataTypeConversion2 = (real32_T)
    load_arduino_v_15_DW.DelayInput2_DSTATE;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S578>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  load_arduino_v_15_B.DataTypeConversion_l = (real32_T)
    (load_arduino_v_15_P.PatohPa_Gain * (real_T)
     load_arduino_v_15_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion2'
   *  Gain: '<S2>/Pa to hPa1'
   *  Gain: '<S571>/Gain1'
   *  Gain: '<S571>/Gain7'
   */
  load_arduino_v_15_B.DataTypeConversion1_g = (real32_T)
    (load_arduino_v_15_P.Gain1_Gain_p * (real_T)
     load_arduino_v_15_B.ByteUnpack_o3[2] * load_arduino_v_15_P.Gain7_Gain *
     load_arduino_v_15_P.PatohPa1_Gain);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  load_arduino_v_15_B.f = (real32_T)floor
    (load_arduino_v_15_B.SFunctionBuilder_o1);
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  load_arduino_v_15_B.DataTypeConversion2_m = (int16_T)(load_arduino_v_15_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S21>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&load_arduino_v_15_B.iflogic,
    &load_arduino_v_15_B.DataTypeConversion3,
    &load_arduino_v_15_P.SIUAVuint8_Value, &load_arduino_v_15_B.GC_info[0],
    &load_arduino_v_15_B.Val_out_MAV[0], &load_arduino_v_15_B.WP_info[0],
    &load_arduino_v_15_B.WP_param[0],
    &load_arduino_v_15_P.onboard_control_sensor_presentu[0],
    &load_arduino_v_15_B.TmpSignalConversionAtSFunctionI[0],
    &load_arduino_v_15_B.Gain1, &load_arduino_v_15_B.B_Remaining,
    &load_arduino_v_15_B.DataTypeConversion,
    &load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[0],
    &load_arduino_v_15_B.DataTypeConversion_ld[0],
    &load_arduino_v_15_B.DataTypeConversion1[0],
    &load_arduino_v_15_B.DataTypeConversion_a[0],
    &load_arduino_v_15_B.DataTypeConversion1_p[0],
    &load_arduino_v_15_B.DataTypeConversion2_h, &load_arduino_v_15_B.AGAC[0],
    &load_arduino_v_15_B.Heading_g, &load_arduino_v_15_B.Throttle,
    &load_arduino_v_15_B.Heading[0], &load_arduino_v_15_B.Memory_a,
    &load_arduino_v_15_B.DataTypeConversion2, &load_arduino_v_15_B.SFunction_o14,
    &load_arduino_v_15_B.Switch1_g, &load_arduino_v_15_B.SFunction_o15,
    &load_arduino_v_15_B.DataTypeConversion_l,
    &load_arduino_v_15_B.DataTypeConversion1_g,
    &load_arduino_v_15_B.DataTypeConversion2_m,
    &load_arduino_v_15_B.SFunction_o5[0], &load_arduino_v_15_B.Lat_Home,
    &load_arduino_v_15_B.Long_Home, &load_arduino_v_15_B.h_Home, ((const
    uint16_T*) &load_arduino_v_15_U16GND), &load_arduino_v_15_B.SFunction_o1_j,
    &load_arduino_v_15_B.SFunction_o2_f[0], &load_arduino_v_15_B.SFunction_o3,
    &load_arduino_v_15_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (load_arduino_v_15_B.SFunction_o1_j > 0) {
    /* Chart: '<S15>/Chart' */
    if (load_arduino_v_15_DW.is_active_c9_load_arduino_v_15 == 0U) {
      load_arduino_v_15_DW.is_active_c9_load_arduino_v_15 = 1U;
      load_arduino_v_15_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (load_arduino_v_15_DW.obj_o.Protocol !=
            load_arduino_v_15_P.SerialTransmit_Protocol) {
          load_arduino_v_15_DW.obj_o.Protocol =
            load_arduino_v_15_P.SerialTransmit_Protocol;
        }

        status = load_arduino_v_15_B.SFunction_o2_f[load_arduino_v_15_DW.i - 1];
        MW_Serial_write(load_arduino_v_15_DW.obj_o.port, &status, 1.0,
                        load_arduino_v_15_DW.obj_o.dataSizeInBytes,
                        load_arduino_v_15_DW.obj_o.sendModeEnum,
                        load_arduino_v_15_DW.obj_o.dataType,
                        load_arduino_v_15_DW.obj_o.sendFormatEnum, 2.0, '\x00');
        if (load_arduino_v_15_DW.i < load_arduino_v_15_B.SFunction_o3) {
          load_arduino_v_15_B.pipk = load_arduino_v_15_DW.i + 1;
          if (load_arduino_v_15_DW.i + 1 > 255) {
            load_arduino_v_15_B.pipk = 255;
          }

          load_arduino_v_15_DW.i = (uint8_T)load_arduino_v_15_B.pipk;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      load_arduino_v_15_DW.i = 1U;
    }

    /* End of Chart: '<S15>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* MATLABSystem: '<S579>/Serial Receive1' */
  if (load_arduino_v_15_DW.obj_e.Protocol !=
      load_arduino_v_15_P.SerialReceive1_Protocol) {
    load_arduino_v_15_DW.obj_e.Protocol =
      load_arduino_v_15_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(0, load_arduino_v_15_DW.obj_e.DataSizeInBytes,
                 &load_arduino_v_15_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S579>/Subsystem2' incorporates:
   *  EnablePort: '<S590>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S590>/Create_message' */
    status = 0U;
    if (!load_arduino_v_15_DW.start_found) {
      load_arduino_v_15_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_15_B.i - 1 < 32)) {
        if (load_arduino_v_15_B.b_dataOut[(uint8_T)load_arduino_v_15_B.i - 1] ==
            36) {
          load_arduino_v_15_B.caso = 32 - (uint8_T)load_arduino_v_15_B.i;
          for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
               load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
            load_arduino_v_15_DW.message[load_arduino_v_15_B.pipk] =
              load_arduino_v_15_B.b_dataOut[((uint8_T)load_arduino_v_15_B.i +
              load_arduino_v_15_B.pipk) - 1];
          }

          load_arduino_v_15_DW.counter_k = (uint8_T)(33 - (uint8_T)
            load_arduino_v_15_B.i);
          load_arduino_v_15_DW.start_found = true;
          exitg1 = true;
        } else {
          load_arduino_v_15_B.i++;
        }
      }
    } else {
      load_arduino_v_15_B.caso = 1;
      exitg1 = false;
      while ((!exitg1) && (load_arduino_v_15_B.caso - 1 < 32)) {
        if (load_arduino_v_15_B.b_dataOut[(uint8_T)load_arduino_v_15_B.caso - 1]
            == 13) {
          load_arduino_v_15_DW.end_found = true;
          status = (uint8_T)load_arduino_v_15_B.caso;
          exitg1 = true;
        } else {
          load_arduino_v_15_B.caso++;
        }
      }

      if (load_arduino_v_15_DW.end_found) {
        if (1 > status) {
          load_arduino_v_15_B.caso = -1;
        } else {
          load_arduino_v_15_B.caso = status - 1;
        }

        for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
             load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
          load_arduino_v_15_B.soglia_dist = (int32_T)(((uint32_T)
            load_arduino_v_15_B.pipk + load_arduino_v_15_DW.counter_k) + 1U);
          if ((uint32_T)load_arduino_v_15_B.soglia_dist > 255U) {
            load_arduino_v_15_B.soglia_dist = 255;
          }

          load_arduino_v_15_DW.message[load_arduino_v_15_B.soglia_dist - 1] =
            load_arduino_v_15_B.b_dataOut[load_arduino_v_15_B.pipk];
        }

        memcpy(&load_arduino_v_15_B.messaggio_cx[0],
               &load_arduino_v_15_DW.message[0], 80U * sizeof(uint8_T));
        load_arduino_v_15_DW.end_found = false;
        load_arduino_v_15_DW.counter_k = (uint8_T)(32 - status);
        if (status == 32) {
          load_arduino_v_15_DW.start_found = false;
          memset(&load_arduino_v_15_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          load_arduino_v_15_DW.start_found = true;
          load_arduino_v_15_B.caso = -status;
          for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <=
               load_arduino_v_15_B.caso + 31; load_arduino_v_15_B.pipk++) {
            load_arduino_v_15_DW.message[load_arduino_v_15_B.pipk] =
              load_arduino_v_15_B.b_dataOut[status + load_arduino_v_15_B.pipk];
          }

          load_arduino_v_15_B.pipk = status + 48;
          if (0 <= load_arduino_v_15_B.pipk - 1) {
            memset(&load_arduino_v_15_DW.message[-status + 32], 0,
                   ((load_arduino_v_15_B.pipk - status) + status) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S590>/Subsystem' incorporates:
         *  EnablePort: '<S592>/Enable'
         */
        /* MATLAB Function: '<S592>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        load_arduino_v_15_B.indice_dimario = 0U;
        for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 80;
             load_arduino_v_15_B.i++) {
          messaggio = (int8_T)
            load_arduino_v_15_B.messaggio_cx[load_arduino_v_15_B.i];
          if (messaggio == '$') {
            load_arduino_v_15_B.pipk = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              load_arduino_v_15_B.pipk = 255;
            }

            status = (uint8_T)load_arduino_v_15_B.pipk;
          }

          if (messaggio == ',') {
            load_arduino_v_15_B.pipk = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              load_arduino_v_15_B.pipk = 255;
            }

            find_comma = (uint8_T)load_arduino_v_15_B.pipk;
          }

          load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i] = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
               load_arduino_v_15_B.pipk++) {
            load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
              (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] == '$');
          }

          load_arduino_v_15_eml_find(load_arduino_v_15_B.messaggio_k,
            &load_arduino_v_15_B.eb_data, load_arduino_v_15_B.eb_size);
          load_arduino_v_15_B.caso = load_arduino_v_15_B.eb_data;
          for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 5;
               load_arduino_v_15_B.pipk++) {
            messaggio = load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk
              + load_arduino_v_15_B.caso];
            load_arduino_v_15_B.mess_type_b[load_arduino_v_15_B.pipk] =
              (messaggio == bb[load_arduino_v_15_B.pipk]);
            load_arduino_v_15_B.mess_type[load_arduino_v_15_B.pipk] = messaggio;
          }

          if (load_arduino_v_15_ifWhileCond_o(load_arduino_v_15_B.mess_type_b))
          {
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
                 load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
                (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] ==
                 ',');
            }

            load_arduino_v_15_eml_find_o(load_arduino_v_15_B.messaggio_k,
              load_arduino_v_15_B.comma_gga_data, load_arduino_v_15_B.eb_size);
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
                 load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
                (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] ==
                 '*');
            }

            load_arduino_v_15_eml_find_o(load_arduino_v_15_B.messaggio_k,
              load_arduino_v_15_B.star_data, load_arduino_v_15_B.star_size);
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
                 load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
                (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] ==
                 '$');
            }

            load_arduino_v_15_eml_find_o(load_arduino_v_15_B.messaggio_k,
              load_arduino_v_15_B.fb_data, load_arduino_v_15_B.star_size);
            load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double
              (&load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.comma_gga_data
               [2]]);
            if ((real_T)load_arduino_v_15_B.comma_gga_data[2] + 3.0 > (real_T)
                load_arduino_v_15_B.comma_gga_data[3] - 1.0) {
              load_arduino_v_15_B.c = 0;
              load_arduino_v_15_B.pipk = 0;
            } else {
              load_arduino_v_15_B.c = load_arduino_v_15_B.comma_gga_data[2] + 2;
              load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[3] -
                1;
            }

            load_arduino_v_15_B.messaggio_size[0] = 1;
            load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
              load_arduino_v_15_B.c;
            load_arduino_v_15_B.messaggio_size[1] =
              load_arduino_v_15_B.soglia_dist;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                 load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.c +
                load_arduino_v_15_B.pipk];
            }

            load_arduino_v_15_B.b_x = load_arduino_v_15_str2double_l
              (load_arduino_v_15_B.messaggio_data,
               load_arduino_v_15_B.messaggio_size);
            if (load_arduino_v_15_B.b_x.im == 0.0) {
              load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re /
                60.0;
            } else if (load_arduino_v_15_B.b_x.re == 0.0) {
              load_arduino_v_15_B.rtb_Gain1_idx_1 = 0.0;
            } else {
              load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re /
                60.0;
            }

            load_arduino_v_15_B.num_254 = load_arduino_v_15_B.Lat_1.re +
              load_arduino_v_15_B.rtb_Gain1_idx_1;
            load_arduino_v_15_B.caso = load_arduino_v_15_B.eb_size[0] *
              load_arduino_v_15_B.eb_size[1] - 1;
            if (0 <= load_arduino_v_15_B.caso) {
              memcpy(&load_arduino_v_15_B.tmp_data[0],
                     &load_arduino_v_15_B.comma_gga_data[0],
                     (load_arduino_v_15_B.caso + 1) * sizeof(int32_T));
            }

            if (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.tmp_data[3]]
                == 'S') {
              load_arduino_v_15_B.num_254 = -load_arduino_v_15_B.num_254;
            }

            load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_lv
              (&load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.comma_gga_data
               [4]]);
            if ((real_T)load_arduino_v_15_B.comma_gga_data[4] + 4.0 > (real_T)
                load_arduino_v_15_B.comma_gga_data[5] - 1.0) {
              load_arduino_v_15_B.i = 0;
              load_arduino_v_15_B.soglia_dist = 0;
            } else {
              load_arduino_v_15_B.i = load_arduino_v_15_B.comma_gga_data[4] + 3;
              load_arduino_v_15_B.soglia_dist =
                load_arduino_v_15_B.comma_gga_data[5] - 1;
            }

            load_arduino_v_15_B.messaggio_size_c[0] = 1;
            load_arduino_v_15_B.soglia_dist -= load_arduino_v_15_B.i;
            load_arduino_v_15_B.messaggio_size_c[1] =
              load_arduino_v_15_B.soglia_dist;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                 load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i +
                load_arduino_v_15_B.pipk];
            }

            load_arduino_v_15_B.b_x = load_arduino_v_15_str2double_l
              (load_arduino_v_15_B.messaggio_data,
               load_arduino_v_15_B.messaggio_size_c);
            if (load_arduino_v_15_B.b_x.im == 0.0) {
              load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re /
                60.0;
            } else if (load_arduino_v_15_B.b_x.re == 0.0) {
              load_arduino_v_15_B.rtb_Gain1_idx_1 = 0.0;
            } else {
              load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re /
                60.0;
            }

            load_arduino_v_15_B.rtb_Gain1_idx_1 += load_arduino_v_15_B.Lat_1.re;
            if (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.tmp_data[5]]
                == 'W') {
              load_arduino_v_15_B.rtb_Gain1_idx_1 =
                -load_arduino_v_15_B.rtb_Gain1_idx_1;
            }

            if ((real_T)load_arduino_v_15_B.comma_gga_data[6] + 1.0 > (real_T)
                load_arduino_v_15_B.comma_gga_data[7] - 1.0) {
              load_arduino_v_15_B.i = 0;
              load_arduino_v_15_B.soglia_dist = 0;
            } else {
              load_arduino_v_15_B.i = load_arduino_v_15_B.comma_gga_data[6];
              load_arduino_v_15_B.soglia_dist =
                load_arduino_v_15_B.comma_gga_data[7] - 1;
            }

            load_arduino_v_15_B.messaggio_size_f[0] = 1;
            load_arduino_v_15_B.soglia_dist -= load_arduino_v_15_B.i;
            load_arduino_v_15_B.messaggio_size_f[1] =
              load_arduino_v_15_B.soglia_dist;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                 load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i +
                load_arduino_v_15_B.pipk];
            }

            load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_l
              (load_arduino_v_15_B.messaggio_data,
               load_arduino_v_15_B.messaggio_size_f);

            /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
            load_arduino_v_15_B.ComplextoRealImag[2] =
              load_arduino_v_15_B.Lat_1.re;
            if ((real_T)load_arduino_v_15_B.comma_gga_data[7] + 1.0 > (real_T)
                load_arduino_v_15_B.comma_gga_data[8] - 1.0) {
              load_arduino_v_15_B.caso = 0;
              load_arduino_v_15_B.pipk = 0;
            } else {
              load_arduino_v_15_B.caso = load_arduino_v_15_B.comma_gga_data[7];
              load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[8] -
                1;
            }

            load_arduino_v_15_B.messaggio_size_g[0] = 1;
            load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
              load_arduino_v_15_B.caso;
            load_arduino_v_15_B.messaggio_size_g[1] =
              load_arduino_v_15_B.soglia_dist;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                 load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.caso +
                load_arduino_v_15_B.pipk];
            }

            load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_l
              (load_arduino_v_15_B.messaggio_data,
               load_arduino_v_15_B.messaggio_size_g);

            /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
            load_arduino_v_15_B.ComplextoRealImag[4] =
              load_arduino_v_15_B.Lat_1.re;
            if ((real_T)load_arduino_v_15_B.comma_gga_data[9] + 1.0 > (real_T)
                load_arduino_v_15_B.comma_gga_data[10] - 1.0) {
              load_arduino_v_15_B.caso = 0;
              load_arduino_v_15_B.pipk = 0;
            } else {
              load_arduino_v_15_B.caso = load_arduino_v_15_B.comma_gga_data[9];
              load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[10]
                - 1;
            }

            load_arduino_v_15_B.messaggio_size_g1[0] = 1;
            load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
              load_arduino_v_15_B.caso;
            load_arduino_v_15_B.messaggio_size_g1[1] =
              load_arduino_v_15_B.soglia_dist;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                 load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.caso +
                load_arduino_v_15_B.pipk];
            }

            load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_l
              (load_arduino_v_15_B.messaggio_data,
               load_arduino_v_15_B.messaggio_size_g1);

            /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
            load_arduino_v_15_B.ComplextoRealImag[3] =
              load_arduino_v_15_B.Lat_1.re;
            if (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.tmp_data[10]]
                == 'W') {
              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[3] =
                -load_arduino_v_15_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
            load_arduino_v_15_B.ComplextoRealImag[5] =
              load_arduino_v_15_DW.Memory_PreviousInput_l[5];
            load_arduino_v_15_B.ComplextoRealImag[6] =
              load_arduino_v_15_DW.Memory_PreviousInput_l[6];
            load_arduino_v_15_B.ComplextoRealImag[7] =
              load_arduino_v_15_DW.Memory_PreviousInput_l[7];
            load_arduino_v_15_B.ComplextoRealImag[8] =
              load_arduino_v_15_DW.Memory_PreviousInput_l[8];
            if ((real_T)load_arduino_v_15_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)load_arduino_v_15_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)load_arduino_v_15_B.star_data[0] +
                                   1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = load_arduino_v_15_B.messaggio_c[status - 1];
            if ((real_T)load_arduino_v_15_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)load_arduino_v_15_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)load_arduino_v_15_B.star_data[0] +
                                   2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = load_arduino_v_15_B.messaggio_c[status - 1];
            if ((real_T)load_arduino_v_15_B.fb_data[0] + 1.0 > (real_T)
                load_arduino_v_15_B.star_data[0] - 1.0) {
              load_arduino_v_15_B.soglia_dist = 0;
              load_arduino_v_15_B.i = 0;
            } else {
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.fb_data[0];
              load_arduino_v_15_B.i = load_arduino_v_15_B.star_data[0] - 1;
            }

            load_arduino_v_15_B.caso = load_arduino_v_15_B.i -
              load_arduino_v_15_B.soglia_dist;
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                 load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.NMEA_gga_string_data[load_arduino_v_15_B.pipk]
                = (uint8_T)
                load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.soglia_dist
                + load_arduino_v_15_B.pipk];
            }

            status = 0U;
            load_arduino_v_15_B.i = 0;
            while (load_arduino_v_15_B.i <= load_arduino_v_15_B.caso - 1) {
              status ^=
                load_arduino_v_15_B.NMEA_gga_string_data[load_arduino_v_15_B.i];
              load_arduino_v_15_B.i++;
            }

            if (status != load_arduino_v_15_hex2dec(ck_ric)) {
              load_arduino_v_15_B.num_254 =
                load_arduino_v_15_DW.Memory_PreviousInput_l[0];
              load_arduino_v_15_B.rtb_Gain1_idx_1 =
                load_arduino_v_15_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[2] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[2];
              load_arduino_v_15_B.ComplextoRealImag[3] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[3];
              load_arduino_v_15_B.ComplextoRealImag[4] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[4];
              load_arduino_v_15_B.indice_dimario = 10U;
            }
          } else {
            for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 5;
                 load_arduino_v_15_B.pipk++) {
              load_arduino_v_15_B.mess_type_b[load_arduino_v_15_B.pipk] =
                (load_arduino_v_15_B.mess_type[load_arduino_v_15_B.pipk] ==
                 cb[load_arduino_v_15_B.pipk]);
            }

            if (load_arduino_v_15_ifWhileCond_o(load_arduino_v_15_B.mess_type_b))
            {
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
                   load_arduino_v_15_B.pipk++) {
                load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
                  (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] ==
                   ',');
              }

              load_arduino_v_15_eml_find_o(load_arduino_v_15_B.messaggio_k,
                load_arduino_v_15_B.comma_gga_data, load_arduino_v_15_B.eb_size);
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
                   load_arduino_v_15_B.pipk++) {
                load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
                  (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] ==
                   '*');
              }

              load_arduino_v_15_eml_find_o(load_arduino_v_15_B.messaggio_k,
                load_arduino_v_15_B.star_data, load_arduino_v_15_B.star_size);
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk < 80;
                   load_arduino_v_15_B.pipk++) {
                load_arduino_v_15_B.messaggio_k[load_arduino_v_15_B.pipk] =
                  (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.pipk] ==
                   '$');
              }

              load_arduino_v_15_eml_find_o(load_arduino_v_15_B.messaggio_k,
                load_arduino_v_15_B.fb_data, load_arduino_v_15_B.star_size);
              load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double
                (&load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.comma_gga_data
                 [1]]);
              if ((real_T)load_arduino_v_15_B.comma_gga_data[1] + 3.0 > (real_T)
                  load_arduino_v_15_B.comma_gga_data[2] - 1.0) {
                load_arduino_v_15_B.caso = 0;
                load_arduino_v_15_B.pipk = 0;
              } else {
                load_arduino_v_15_B.caso = load_arduino_v_15_B.comma_gga_data[1]
                  + 2;
                load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[2]
                  - 1;
              }

              load_arduino_v_15_B.messaggio_size[0] = 1;
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
                load_arduino_v_15_B.caso;
              load_arduino_v_15_B.messaggio_size[1] =
                load_arduino_v_15_B.soglia_dist;
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                   load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++)
              {
                load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                  load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.caso +
                  load_arduino_v_15_B.pipk];
              }

              load_arduino_v_15_B.b_x = load_arduino_v_15_str2double_l
                (load_arduino_v_15_B.messaggio_data,
                 load_arduino_v_15_B.messaggio_size);
              if (load_arduino_v_15_B.b_x.im == 0.0) {
                load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re
                  / 60.0;
              } else if (load_arduino_v_15_B.b_x.re == 0.0) {
                load_arduino_v_15_B.rtb_Gain1_idx_1 = 0.0;
              } else {
                load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re
                  / 60.0;
              }

              load_arduino_v_15_B.num_254 = load_arduino_v_15_B.Lat_1.re +
                load_arduino_v_15_B.rtb_Gain1_idx_1;
              load_arduino_v_15_B.caso = load_arduino_v_15_B.eb_size[0] *
                load_arduino_v_15_B.eb_size[1] - 1;
              if (0 <= load_arduino_v_15_B.caso) {
                memcpy(&load_arduino_v_15_B.tmp_data[0],
                       &load_arduino_v_15_B.comma_gga_data[0],
                       (load_arduino_v_15_B.caso + 1) * sizeof(int32_T));
              }

              if (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.tmp_data[2]]
                  == 'S') {
                load_arduino_v_15_B.num_254 = -load_arduino_v_15_B.num_254;
              }

              load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_lv
                (&load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.comma_gga_data
                 [3]]);
              if ((real_T)load_arduino_v_15_B.comma_gga_data[3] + 4.0 > (real_T)
                  load_arduino_v_15_B.comma_gga_data[4] - 1.0) {
                load_arduino_v_15_B.i = 0;
                load_arduino_v_15_B.pipk = 0;
              } else {
                load_arduino_v_15_B.i = load_arduino_v_15_B.comma_gga_data[3] +
                  3;
                load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[4]
                  - 1;
              }

              load_arduino_v_15_B.messaggio_size_c[0] = 1;
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.messaggio_size_c[1] =
                load_arduino_v_15_B.soglia_dist;
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                   load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++)
              {
                load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                  load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i +
                  load_arduino_v_15_B.pipk];
              }

              load_arduino_v_15_B.b_x = load_arduino_v_15_str2double_l
                (load_arduino_v_15_B.messaggio_data,
                 load_arduino_v_15_B.messaggio_size_c);
              if (load_arduino_v_15_B.b_x.im == 0.0) {
                load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re
                  / 60.0;
              } else if (load_arduino_v_15_B.b_x.re == 0.0) {
                load_arduino_v_15_B.rtb_Gain1_idx_1 = 0.0;
              } else {
                load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.b_x.re
                  / 60.0;
              }

              load_arduino_v_15_B.rtb_Gain1_idx_1 +=
                load_arduino_v_15_B.Lat_1.re;
              if (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.tmp_data[4]]
                  == 'W') {
                load_arduino_v_15_B.rtb_Gain1_idx_1 =
                  -load_arduino_v_15_B.rtb_Gain1_idx_1;
              }

              load_arduino_v_15_B.Lat_1 = load_arduino_v_1_str2double_lvk
                (load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[5] =
                load_arduino_v_15_B.Lat_1.re;
              if ((real_T)load_arduino_v_15_B.comma_gga_data[6] + 1.0 > (real_T)
                  load_arduino_v_15_B.comma_gga_data[7] - 1.0) {
                load_arduino_v_15_B.caso = 0;
                load_arduino_v_15_B.pipk = 0;
              } else {
                load_arduino_v_15_B.caso = load_arduino_v_15_B.comma_gga_data[6];
                load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[7]
                  - 1;
              }

              load_arduino_v_15_B.messaggio_size_f[0] = 1;
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
                load_arduino_v_15_B.caso;
              load_arduino_v_15_B.messaggio_size_f[1] =
                load_arduino_v_15_B.soglia_dist;
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                   load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++)
              {
                load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                  load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.caso +
                  load_arduino_v_15_B.pipk];
              }

              load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_l
                (load_arduino_v_15_B.messaggio_data,
                 load_arduino_v_15_B.messaggio_size_f);

              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[6] =
                load_arduino_v_15_B.Lat_1.re;
              if ((real_T)load_arduino_v_15_B.comma_gga_data[8] + 1.0 > (real_T)
                  load_arduino_v_15_B.comma_gga_data[9] - 1.0) {
                load_arduino_v_15_B.i = 0;
                load_arduino_v_15_B.pipk = 0;
              } else {
                load_arduino_v_15_B.i = load_arduino_v_15_B.comma_gga_data[8];
                load_arduino_v_15_B.pipk = load_arduino_v_15_B.comma_gga_data[9]
                  - 1;
              }

              load_arduino_v_15_B.messaggio_size_g[0] = 1;
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.pipk -
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.messaggio_size_g[1] =
                load_arduino_v_15_B.soglia_dist;
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                   load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++)
              {
                load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                  load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i +
                  load_arduino_v_15_B.pipk];
              }

              load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_l
                (load_arduino_v_15_B.messaggio_data,
                 load_arduino_v_15_B.messaggio_size_g);

              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[7] =
                load_arduino_v_15_B.Lat_1.re;
              if ((real_T)load_arduino_v_15_B.comma_gga_data[10] + 1.0 > (real_T)
                  load_arduino_v_15_B.comma_gga_data[11] - 1.0) {
                load_arduino_v_15_B.i = 0;
                load_arduino_v_15_B.caso = 0;
              } else {
                load_arduino_v_15_B.i = load_arduino_v_15_B.comma_gga_data[10];
                load_arduino_v_15_B.caso = load_arduino_v_15_B.comma_gga_data[11]
                  - 1;
              }

              load_arduino_v_15_B.messaggio_size_g1[0] = 1;
              load_arduino_v_15_B.soglia_dist = load_arduino_v_15_B.caso -
                load_arduino_v_15_B.i;
              load_arduino_v_15_B.messaggio_size_g1[1] =
                load_arduino_v_15_B.soglia_dist;
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                   load_arduino_v_15_B.soglia_dist; load_arduino_v_15_B.pipk++)
              {
                load_arduino_v_15_B.messaggio_data[load_arduino_v_15_B.pipk] =
                  load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i +
                  load_arduino_v_15_B.pipk];
              }

              load_arduino_v_15_B.Lat_1 = load_arduino_v_15_str2double_l
                (load_arduino_v_15_B.messaggio_data,
                 load_arduino_v_15_B.messaggio_size_g1);

              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[8] =
                load_arduino_v_15_B.Lat_1.re;
              load_arduino_v_15_B.ComplextoRealImag[2] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[2];
              load_arduino_v_15_B.ComplextoRealImag[3] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[3];
              load_arduino_v_15_B.ComplextoRealImag[4] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[4];
              if ((real_T)load_arduino_v_15_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)load_arduino_v_15_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)load_arduino_v_15_B.star_data[0] +
                                     1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = load_arduino_v_15_B.messaggio_c[status - 1];
              if ((real_T)load_arduino_v_15_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)load_arduino_v_15_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)load_arduino_v_15_B.star_data[0] +
                                     2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = load_arduino_v_15_B.messaggio_c[status - 1];
              if ((real_T)load_arduino_v_15_B.fb_data[0] + 1.0 > (real_T)
                  load_arduino_v_15_B.star_data[0] - 1.0) {
                load_arduino_v_15_B.i = 0;
                load_arduino_v_15_B.pipk = 0;
              } else {
                load_arduino_v_15_B.i = load_arduino_v_15_B.fb_data[0];
                load_arduino_v_15_B.pipk = load_arduino_v_15_B.star_data[0] - 1;
              }

              load_arduino_v_15_B.caso = load_arduino_v_15_B.pipk -
                load_arduino_v_15_B.i;
              for (load_arduino_v_15_B.pipk = 0; load_arduino_v_15_B.pipk <
                   load_arduino_v_15_B.caso; load_arduino_v_15_B.pipk++) {
                load_arduino_v_15_B.NMEA_gga_string_data[load_arduino_v_15_B.pipk]
                  = (uint8_T)
                  load_arduino_v_15_B.messaggio_c[load_arduino_v_15_B.i +
                  load_arduino_v_15_B.pipk];
              }

              status = 0U;
              load_arduino_v_15_B.pipk = 0;
              while (load_arduino_v_15_B.pipk <= load_arduino_v_15_B.caso - 1) {
                status ^=
                  load_arduino_v_15_B.NMEA_gga_string_data[load_arduino_v_15_B.pipk];
                load_arduino_v_15_B.pipk++;
              }

              if (status != load_arduino_v_15_hex2dec(ck_ric)) {
                load_arduino_v_15_B.num_254 =
                  load_arduino_v_15_DW.Memory_PreviousInput_l[0];
                load_arduino_v_15_B.rtb_Gain1_idx_1 =
                  load_arduino_v_15_DW.Memory_PreviousInput_l[1];

                /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
                load_arduino_v_15_B.ComplextoRealImag[5] =
                  load_arduino_v_15_DW.Memory_PreviousInput_l[5];
                load_arduino_v_15_B.ComplextoRealImag[6] =
                  load_arduino_v_15_DW.Memory_PreviousInput_l[6];
                load_arduino_v_15_B.ComplextoRealImag[7] =
                  load_arduino_v_15_DW.Memory_PreviousInput_l[7];
                load_arduino_v_15_B.ComplextoRealImag[8] =
                  load_arduino_v_15_DW.Memory_PreviousInput_l[8];
                load_arduino_v_15_B.indice_dimario = 20U;
              }
            } else {
              load_arduino_v_15_B.num_254 =
                load_arduino_v_15_DW.Memory_PreviousInput_l[0];
              load_arduino_v_15_B.rtb_Gain1_idx_1 =
                load_arduino_v_15_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
              load_arduino_v_15_B.ComplextoRealImag[2] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[2];
              load_arduino_v_15_B.ComplextoRealImag[3] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[3];
              load_arduino_v_15_B.ComplextoRealImag[4] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[4];
              load_arduino_v_15_B.ComplextoRealImag[5] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[5];
              load_arduino_v_15_B.ComplextoRealImag[6] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[6];
              load_arduino_v_15_B.ComplextoRealImag[7] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[7];
              load_arduino_v_15_B.ComplextoRealImag[8] =
                load_arduino_v_15_DW.Memory_PreviousInput_l[8];
            }
          }
        } else {
          load_arduino_v_15_B.num_254 =
            load_arduino_v_15_DW.Memory_PreviousInput_l[0];
          load_arduino_v_15_B.rtb_Gain1_idx_1 =
            load_arduino_v_15_DW.Memory_PreviousInput_l[1];

          /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
          load_arduino_v_15_B.ComplextoRealImag[2] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[2];
          load_arduino_v_15_B.ComplextoRealImag[3] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[3];
          load_arduino_v_15_B.ComplextoRealImag[4] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[4];
          load_arduino_v_15_B.ComplextoRealImag[5] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[5];
          load_arduino_v_15_B.ComplextoRealImag[6] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[6];
          load_arduino_v_15_B.ComplextoRealImag[7] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[7];
          load_arduino_v_15_B.ComplextoRealImag[8] =
            load_arduino_v_15_DW.Memory_PreviousInput_l[8];
        }

        /* End of MATLAB Function: '<S592>/MATLAB Function' */

        /* ComplexToRealImag: '<S592>/Complex to Real-Imag' */
        load_arduino_v_15_B.ComplextoRealImag[0] = load_arduino_v_15_B.num_254;
        load_arduino_v_15_B.ComplextoRealImag[1] =
          load_arduino_v_15_B.rtb_Gain1_idx_1;

        /* Update for Memory: '<S592>/Memory' */
        memcpy(&load_arduino_v_15_DW.Memory_PreviousInput_l[0],
               &load_arduino_v_15_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S590>/Subsystem' */
      } else {
        for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 32;
             load_arduino_v_15_B.i++) {
          load_arduino_v_15_B.pipk = (int32_T)(((uint32_T)
            load_arduino_v_15_DW.counter_k + load_arduino_v_15_B.i) + 1U);
          if ((uint32_T)load_arduino_v_15_B.pipk > 255U) {
            load_arduino_v_15_B.pipk = 255;
          }

          load_arduino_v_15_DW.message[load_arduino_v_15_B.pipk - 1] =
            load_arduino_v_15_B.b_dataOut[load_arduino_v_15_B.i];
        }

        load_arduino_v_15_B.pipk = (int32_T)(load_arduino_v_15_DW.counter_k +
          32U);
        if (load_arduino_v_15_DW.counter_k + 32U > 255U) {
          load_arduino_v_15_B.pipk = 255;
        }

        load_arduino_v_15_DW.counter_k = (uint8_T)load_arduino_v_15_B.pipk;
      }
    }

    /* End of MATLAB Function: '<S590>/Create_message' */
  }

  /* End of MATLABSystem: '<S579>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S579>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S579>/Subsystem1' incorporates:
   *  EnablePort: '<S589>/Enable'
   */
  if (load_arduino_v_15_B.SFunction_o14 > 0) {
    /* Switch: '<S589>/Switch' incorporates:
     *  Constant: '<S589>/Constant'
     *  Constant: '<S589>/Constant1'
     *  Constant: '<S589>/Constant3'
     *  Logic: '<S589>/OR'
     *  RelationalOperator: '<S589>/Equal'
     *  RelationalOperator: '<S589>/Equal1'
     *  RelationalOperator: '<S589>/Equal2'
     */
    if ((load_arduino_v_15_B.ComplextoRealImag[5] ==
         load_arduino_v_15_P.Constant_Value_lv) ||
        (load_arduino_v_15_B.ComplextoRealImag[5] ==
         load_arduino_v_15_P.Constant1_Value_b) ||
        (load_arduino_v_15_B.ComplextoRealImag[5] ==
         load_arduino_v_15_P.Constant3_Value_ct)) {
      /* Switch: '<S589>/Switch' */
      load_arduino_v_15_B.Switch = load_arduino_v_15_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S589>/Switch' incorporates:
       *  Constant: '<S589>/Constant2'
       */
      load_arduino_v_15_B.Switch = load_arduino_v_15_P.Constant2_Value_d;
    }

    /* End of Switch: '<S589>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S579>/Subsystem1' */

  /* MATLAB Function: '<S578>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S578>/Data Type Conversion'
   *  UnitDelay: '<S581>/Delay Input2'
   *
   * Block description for '<S581>/Delay Input2':
   *
   *  Store in Global RAM
   */
  load_arduino_v_15_B.num_254 = log(load_arduino_v_15_DW.DelayInput2_DSTATE /
    (real_T)load_arduino_v_15_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S571>/Data Type Conversion4' incorporates:
   *  MATLAB Function: '<S578>/MATLAB Function1'
   *  Sum: '<S579>/Sum'
   */
  load_arduino_v_15_B.DataTypeConversion4[0] = (real32_T)
    load_arduino_v_15_B.ComplextoRealImag[0];
  load_arduino_v_15_B.DataTypeConversion4[1] = (real32_T)
    load_arduino_v_15_B.ComplextoRealImag[1];
  load_arduino_v_15_B.DataTypeConversion4[2] = (real32_T)
    (load_arduino_v_15_B.ComplextoRealImag[7] - load_arduino_v_15_B.Switch);
  load_arduino_v_15_B.DataTypeConversion4[3] = (real32_T)(29.260958205912335 *
    load_arduino_v_15_B.num_254) * (load_arduino_v_15_B.Switch1_g + 273.15F) /
    (real32_T)(1.0 - -0.095098114169215084 * load_arduino_v_15_B.num_254);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  Gain: '<S572>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_nk *
     load_arduino_v_15_B.DataTypeConversion1_b[3] *
     load_arduino_v_15_P.Gain_Gain_bk));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[3] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  Gain: '<S573>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_db *
     load_arduino_v_15_B.DataTypeConversion1_b[4] *
     load_arduino_v_15_P.Gain_Gain_bk));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[4] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  Gain: '<S574>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_dc *
     load_arduino_v_15_B.DataTypeConversion1_b[5] *
     load_arduino_v_15_P.Gain_Gain_bk));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[5] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  SignalConversion generated from: '<S571>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_bk *
     load_arduino_v_15_B.DataTypeConversion1_b[6]));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[0] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  SignalConversion generated from: '<S571>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_bk *
     load_arduino_v_15_B.DataTypeConversion1_b[0]));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[6] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  SignalConversion generated from: '<S571>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_bk *
     load_arduino_v_15_B.DataTypeConversion1_b[7]));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[1] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  SignalConversion generated from: '<S571>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_bk *
     load_arduino_v_15_B.DataTypeConversion1_b[1]));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[7] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  SignalConversion generated from: '<S571>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_bk *
     load_arduino_v_15_B.DataTypeConversion1_b[8]));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[2] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion' incorporates:
   *  Gain: '<S571>/Gain'
   *  SignalConversion generated from: '<S571>/Gain'
   */
  load_arduino_v_15_B.f = (real32_T)floor((real32_T)
    (load_arduino_v_15_P.Gain_Gain_bk *
     load_arduino_v_15_B.DataTypeConversion1_b[2]));
  if (rtIsNaNF(load_arduino_v_15_B.f) || rtIsInfF(load_arduino_v_15_B.f)) {
    load_arduino_v_15_B.f = 0.0F;
  } else {
    load_arduino_v_15_B.f = (real32_T)fmod(load_arduino_v_15_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion' */
  load_arduino_v_15_B.DataTypeConversion_lx[8] = (int16_T)(load_arduino_v_15_B.f
    < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-load_arduino_v_15_B.f :
    (int32_T)(int16_T)(uint16_T)load_arduino_v_15_B.f);

  /* DataTypeConversion: '<S571>/Data Type Conversion1' */
  load_arduino_v_15_B.Ato_selector = floor
    (load_arduino_v_15_B.ComplextoRealImag[4]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_h[0] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
   *  Gain: '<S571>/Gain2'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Gain2_Gain_m *
    load_arduino_v_15_B.ComplextoRealImag[2]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_h[1] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);
  load_arduino_v_15_B.DataTypeConversion1_h[2] = 0U;

  /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Constant_Value_c);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   */
  load_arduino_v_15_B.DataTypeConversion1_h[3] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);
  load_arduino_v_15_B.DataTypeConversion1_h[4] = (uint16_T)
    load_arduino_v_15_B.PWM_throttle;
  load_arduino_v_15_B.DataTypeConversion1_h[5] = (uint16_T)
    load_arduino_v_15_B.PWM_elevator;
  load_arduino_v_15_B.DataTypeConversion1_h[6] = (uint16_T)
    load_arduino_v_15_B.PWM_aileron;
  load_arduino_v_15_B.DataTypeConversion1_h[7] = (uint16_T)
    load_arduino_v_15_B.PWM_rudder;

  /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S571>/Gain6'
   */
  load_arduino_v_15_B.Ato_selector = floor(load_arduino_v_15_P.Gain6_Gain *
    load_arduino_v_15_P.Constant1_Value_fu);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_h[8] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
   *  Gain: '<S571>/Gain5'
   */
  load_arduino_v_15_B.Ato_selector = floor((real_T)
    load_arduino_v_15_P.Gain5_Gain * load_arduino_v_15_B.SFunctionBuilder_o1);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      65536.0);
  }

  /* DataTypeConversion: '<S571>/Data Type Conversion1' */
  load_arduino_v_15_B.DataTypeConversion1_h[9] = (uint16_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint16_T)
     load_arduino_v_15_B.Ato_selector);

  /* DataTypeConversion: '<S571>/Data Type Conversion6' */
  load_arduino_v_15_B.Ato_selector = floor
    (load_arduino_v_15_B.ComplextoRealImag[5]);
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector) || rtIsInf
      (load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      256.0);
  }

  /* SignalConversion generated from: '<S571>/Byte Pack' incorporates:
   *  DataTypeConversion: '<S571>/Data Type Conversion6'
   */
  load_arduino_v_15_B.TmpSignalConversionAtBytePackIn[0] = (uint8_T)
    (load_arduino_v_15_B.Ato_selector < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-load_arduino_v_15_B.Ato_selector : (int32_T)(uint8_T)
     load_arduino_v_15_B.Ato_selector);
  load_arduino_v_15_B.TmpSignalConversionAtBytePackIn[1] =
    load_arduino_v_15_B.indice_dimario;

  /* DataTypeConversion: '<S571>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S578>/Data Type Conversion'
   */
  load_arduino_v_15_B.DataTypeConversion8 =
    load_arduino_v_15_B.SFunctionBuilder1;

  /* S-Function (any2byte_svd): '<S571>/Byte Pack' incorporates:
   *  Constant: '<S571>/Fine MSG1'
   *  Constant: '<S571>/Inizio MSG'
   */

  /* Pack: <S571>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_B.DataTypeConversion4[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_B.DataTypeConversion_lx[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_B.DataTypeConversion1_h[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_B.TmpSignalConversionAtBytePackIn[0],
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_B.DataTypeConversion8, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&load_arduino_v_15_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &load_arduino_v_15_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S571>/Serial Transmit' */
  if (load_arduino_v_15_DW.obj.Protocol !=
      load_arduino_v_15_P.SerialTransmit_Protocol_b) {
    load_arduino_v_15_DW.obj.Protocol =
      load_arduino_v_15_P.SerialTransmit_Protocol_b;
  }

  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 63;
       load_arduino_v_15_B.i++) {
    load_arduino_v_15_B.dataIn[load_arduino_v_15_B.i] =
      load_arduino_v_15_B.BytePack[load_arduino_v_15_B.i];
  }

  MW_Serial_write(load_arduino_v_15_DW.obj.port, &load_arduino_v_15_B.dataIn[0],
                  63.0, load_arduino_v_15_DW.obj.dataSizeInBytes,
                  load_arduino_v_15_DW.obj.sendModeEnum,
                  load_arduino_v_15_DW.obj.dataType,
                  load_arduino_v_15_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S571>/Serial Transmit' */

  /* Product: '<S350>/IProd Out' incorporates:
   *  Constant: '<S8>/Ki controllore  beccheggio1'
   */
  load_arduino_v_15_B.SumI1_ak = load_arduino_v_15_B.e_b *
    load_arduino_v_15_P.Ki_becch;

  /* Sum: '<S365>/SumI1' incorporates:
   *  Gain: '<S364>/Kt'
   *  Sum: '<S364>/SumI3'
   */
  load_arduino_v_15_B.num_254 = (load_arduino_v_15_B.SwitchBumpless2 -
    load_arduino_v_15_B.Saturation_i) * load_arduino_v_15_P.PIDController_Kt +
    load_arduino_v_15_B.SumI1_ak;

  /* Outputs for Resettable SubSystem: '<S422>/Resettable Subsystem' */
  load_arduino_v_15_B.SumI1_ak = load_ar_ResettableSubsystem
    (load_arduino_v_15_B.SFunction_o4_n[1],
     &load_arduino_v_15_DW.ResettableSubsystem,
     &load_arduino_v_15_P.ResettableSubsystem,
     &load_arduino_v_15_PrevZCX.ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S422>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S422>/Enabled Subsystem' */
  load_ardui_EnabledSubsystem(load_arduino_v_15_B.SFunction_o4_n[1],
    load_arduino_v_15_B.SumI1_ak, &load_arduino_v_15_B.rtb_Gain1_idx_1,
    &load_arduino_v_15_P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S422>/Enabled Subsystem' */

  /* MATLAB Function: '<S424>/MATLAB Function1' */
  load_arduino_v_15_DW.Tf_not_empty = ((!load_arduino_v_15_DW.Tf_not_empty) ||
    (load_arduino_v_15_DW.Memory2_PreviousInput_a[0] == 1) ||
    (load_arduino_v_15_DW.Memory2_PreviousInput_a[1] == 0) ||
    load_arduino_v_15_DW.Tf_not_empty);

  /* Sum: '<S298>/SumI1' incorporates:
   *  Constant: '<S8>/Ki AP velocità'
   *  Gain: '<S297>/Kt'
   *  Product: '<S283>/IProd Out'
   *  Sum: '<S297>/SumI3'
   */
  load_arduino_v_15_B.SumI1_ak = (load_arduino_v_15_B.Gain_g -
    load_arduino_v_15_B.Saturation_h) * load_arduino_v_15_P.PIDController_Kt_p +
    load_arduino_v_15_B.DeadZone * load_arduino_v_15_P.Ki_AP_vel;

  /* DeadZone: '<S279>/DeadZone' */
  if (load_arduino_v_15_B.rtb_Gain4_idx_1 > load_arduino_v_15_P.attuatore_Tmax)
  {
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.rtb_Gain4_idx_1 -
      load_arduino_v_15_P.attuatore_Tmax;
  } else if (load_arduino_v_15_B.rtb_Gain4_idx_1 >=
             load_arduino_v_15_P.attuatore_Tmin) {
    load_arduino_v_15_B.DeadZone = 0.0;
  } else {
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.rtb_Gain4_idx_1 -
      load_arduino_v_15_P.attuatore_Tmin;
  }

  /* End of DeadZone: '<S279>/DeadZone' */

  /* Signum: '<S277>/SignPreSat' */
  if (load_arduino_v_15_B.DeadZone < 0.0) {
    /* DataTypeConversion: '<S277>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = -1.0;
  } else if (load_arduino_v_15_B.DeadZone > 0.0) {
    /* DataTypeConversion: '<S277>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = 1.0;
  } else if (load_arduino_v_15_B.DeadZone == 0.0) {
    /* DataTypeConversion: '<S277>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    /* DataTypeConversion: '<S277>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = (rtNaN);
  }

  /* End of Signum: '<S277>/SignPreSat' */

  /* DataTypeConversion: '<S277>/DataTypeConv1' */
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      256.0);
  }

  /* Signum: '<S277>/SignPreIntegrator' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.SumI1_ak;
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    /* DataTypeConversion: '<S277>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = -1.0;
  } else if (load_arduino_v_15_B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S277>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = 1.0;
  } else if (load_arduino_v_15_B.Al_selector == 0.0) {
    /* DataTypeConversion: '<S277>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = 0.0;
  } else {
    /* DataTypeConversion: '<S277>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = (rtNaN);
  }

  /* End of Signum: '<S277>/SignPreIntegrator' */

  /* DataTypeConversion: '<S277>/DataTypeConv2' */
  if (rtIsNaN(load_arduino_v_15_B.Al_selector)) {
    load_arduino_v_15_B.Al_selector = 0.0;
  } else {
    load_arduino_v_15_B.Al_selector = fmod(load_arduino_v_15_B.Al_selector,
      256.0);
  }

  /* Switch: '<S277>/Switch' incorporates:
   *  Constant: '<S277>/Constant1'
   *  DataTypeConversion: '<S277>/DataTypeConv1'
   *  DataTypeConversion: '<S277>/DataTypeConv2'
   *  Gain: '<S277>/ZeroGain'
   *  Logic: '<S277>/AND3'
   *  RelationalOperator: '<S277>/Equal1'
   *  RelationalOperator: '<S277>/NotEqual'
   */
  if ((load_arduino_v_15_P.ZeroGain_Gain * load_arduino_v_15_B.rtb_Gain4_idx_1
       != load_arduino_v_15_B.DeadZone) && ((load_arduino_v_15_B.Ato_selector <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
        -load_arduino_v_15_B.Ato_selector : (int32_T)(int8_T)(uint8_T)
        load_arduino_v_15_B.Ato_selector) == (load_arduino_v_15_B.Al_selector <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
        -load_arduino_v_15_B.Al_selector : (int32_T)(int8_T)(uint8_T)
        load_arduino_v_15_B.Al_selector))) {
    load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_P.Constant1_Value_f;
  } else {
    load_arduino_v_15_B.rtb_Gain1_idx_1 = load_arduino_v_15_B.SumI1_ak;
  }

  /* End of Switch: '<S277>/Switch' */

  /* Sum: '<S244>/SumI1' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Gain: '<S243>/Kt'
   *  Product: '<S229>/IProd Out'
   *  Sum: '<S243>/SumI3'
   */
  load_arduino_v_15_B.SumI1_ak = (load_arduino_v_15_B.Abs_i -
    load_arduino_v_15_B.Abs1_a) * load_arduino_v_15_P.PIDController1_Kt +
    load_arduino_v_15_B.Go_home_selector *
    load_arduino_v_15_P.Constant2_Value_kv;

  /* DeadZone: '<S225>/DeadZone' */
  if (load_arduino_v_15_B.Sum_gs >
      load_arduino_v_15_P.PIDController1_UpperSaturationL) {
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.Sum_gs -
      load_arduino_v_15_P.PIDController1_UpperSaturationL;
  } else if (load_arduino_v_15_B.Sum_gs >=
             load_arduino_v_15_P.PIDController1_LowerSaturationL) {
    load_arduino_v_15_B.DeadZone = 0.0;
  } else {
    load_arduino_v_15_B.DeadZone = load_arduino_v_15_B.Sum_gs -
      load_arduino_v_15_P.PIDController1_LowerSaturationL;
  }

  /* End of DeadZone: '<S225>/DeadZone' */

  /* S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper
    (&load_arduino_v_15_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&load_arduino_v_15_DW.Memory4_PreviousInput_c[0],
         &load_arduino_v_15_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S580>/S-Function Builder1' */

  /* S-Function "Mti_wrapper" Block: <S580>/S-Function Builder1 */
  Mti_Update_wrapper(&load_arduino_v_15_B.SFunctionBuilder1_b[0],
                     &load_arduino_v_15_DW.SFunctionBuilder1_DSTATE);

  /* Update for UnitDelay: '<S578>/Unit Delay' incorporates:
   *  Constant: '<S578>/Constant3'
   */
  load_arduino_v_15_DW.UnitDelay_DSTATE = load_arduino_v_15_P.Constant3_Value_ok;

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&load_arduino_v_15_P.Constant1_Value_a,
    &load_arduino_v_15_B.SFunctionBuilder_o1_h[0],
    &load_arduino_v_15_B.SFunctionBuilder_o2,
    &load_arduino_v_15_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&load_arduino_v_15_DW.Memory5_PreviousInput_l[0],
         &load_arduino_v_15_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  load_arduino_v_15_DW.Memory_PreviousInput_h5[0] =
    load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[0];
  load_arduino_v_15_DW.Memory_PreviousInput_h5[1] =
    load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[1];
  load_arduino_v_15_DW.Memory_PreviousInput_h5[2] =
    load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[2];
  load_arduino_v_15_DW.Memory_PreviousInput_h5[3] =
    load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (load_arduino_v_15_B.i = 0; load_arduino_v_15_B.i < 8;
       load_arduino_v_15_B.i++) {
    load_arduino_v_15_DW.Memory_PreviousInput_i[load_arduino_v_15_B.i] =
      load_arduino_v_15_B.SFunction_o11[load_arduino_v_15_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Signum: '<S223>/SignPreSat' */
  if (load_arduino_v_15_B.DeadZone < 0.0) {
    /* DataTypeConversion: '<S223>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = -1.0;
  } else if (load_arduino_v_15_B.DeadZone > 0.0) {
    /* DataTypeConversion: '<S223>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = 1.0;
  } else if (load_arduino_v_15_B.DeadZone == 0.0) {
    /* DataTypeConversion: '<S223>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    /* DataTypeConversion: '<S223>/DataTypeConv1' */
    load_arduino_v_15_B.Ato_selector = (rtNaN);
  }

  /* End of Signum: '<S223>/SignPreSat' */

  /* DataTypeConversion: '<S223>/DataTypeConv1' */
  if (rtIsNaN(load_arduino_v_15_B.Ato_selector)) {
    load_arduino_v_15_B.Ato_selector = 0.0;
  } else {
    load_arduino_v_15_B.Ato_selector = fmod(load_arduino_v_15_B.Ato_selector,
      256.0);
  }

  /* Signum: '<S223>/SignPreIntegrator' */
  load_arduino_v_15_B.Al_selector = load_arduino_v_15_B.SumI1_ak;
  if (load_arduino_v_15_B.Al_selector < 0.0) {
    /* DataTypeConversion: '<S223>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = -1.0;
  } else if (load_arduino_v_15_B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S223>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = 1.0;
  } else if (load_arduino_v_15_B.Al_selector == 0.0) {
    /* DataTypeConversion: '<S223>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = 0.0;
  } else {
    /* DataTypeConversion: '<S223>/DataTypeConv2' */
    load_arduino_v_15_B.Al_selector = (rtNaN);
  }

  /* End of Signum: '<S223>/SignPreIntegrator' */

  /* DataTypeConversion: '<S223>/DataTypeConv2' */
  if (rtIsNaN(load_arduino_v_15_B.Al_selector)) {
    load_arduino_v_15_B.Al_selector = 0.0;
  } else {
    load_arduino_v_15_B.Al_selector = fmod(load_arduino_v_15_B.Al_selector,
      256.0);
  }

  /* Switch: '<S223>/Switch' incorporates:
   *  Constant: '<S223>/Constant1'
   *  DataTypeConversion: '<S223>/DataTypeConv1'
   *  DataTypeConversion: '<S223>/DataTypeConv2'
   *  Gain: '<S223>/ZeroGain'
   *  Logic: '<S223>/AND3'
   *  RelationalOperator: '<S223>/Equal1'
   *  RelationalOperator: '<S223>/NotEqual'
   */
  if ((load_arduino_v_15_P.ZeroGain_Gain_f * load_arduino_v_15_B.Sum_gs !=
       load_arduino_v_15_B.DeadZone) && ((load_arduino_v_15_B.Ato_selector < 0.0
        ? (int32_T)(int8_T)-(int8_T)(uint8_T)-load_arduino_v_15_B.Ato_selector :
        (int32_T)(int8_T)(uint8_T)load_arduino_v_15_B.Ato_selector) ==
       (load_arduino_v_15_B.Al_selector < 0.0 ? (int32_T)(int8_T)-(int8_T)
        (uint8_T)-load_arduino_v_15_B.Al_selector : (int32_T)(int8_T)(uint8_T)
        load_arduino_v_15_B.Al_selector))) {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_P.Constant1_Value_op;
  } else {
    load_arduino_v_15_B.Ato_selector = load_arduino_v_15_B.SumI1_ak;
  }

  /* End of Switch: '<S223>/Switch' */

  /* Update for DiscreteIntegrator: '<S232>/Integrator' */
  load_arduino_v_15_DW.Integrator_DSTATE +=
    load_arduino_v_15_P.Integrator_gainval_h * load_arduino_v_15_B.Ato_selector;

  /* Update for DiscreteIntegrator: '<S227>/Filter' */
  load_arduino_v_15_DW.Filter_DSTATE += load_arduino_v_15_P.Filter_gainval_d *
    load_arduino_v_15_B.Vec_selector;

  /* Update for DiscreteIntegrator: '<S403>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  rollio3'
   *  Gain: '<S396>/Kb'
   *  Gain: '<S414>/Kt'
   *  Product: '<S400>/IProd Out'
   *  Sum: '<S396>/SumI2'
   *  Sum: '<S396>/SumI4'
   *  Sum: '<S414>/SumI3'
   *  Sum: '<S415>/SumI1'
   */
  load_arduino_v_15_DW.Integrator_DSTATE_d += (((load_arduino_v_15_B.h_comandato
    - load_arduino_v_15_B.Gain_nr) * load_arduino_v_15_P.PIDController_Kt_g +
    load_arduino_v_15_B.e * load_arduino_v_15_P.Ki_roll) +
    (load_arduino_v_15_B.Gain_nr - load_arduino_v_15_B.psi_ref_p) *
    load_arduino_v_15_P.PIDController_Kb_g) *
    load_arduino_v_15_P.Integrator_gainval_i;
  if (load_arduino_v_15_B.a_n > 0.0) {
    load_arduino_v_15_DW.Integrator_PrevResetState = 1;
  } else if (load_arduino_v_15_B.a_n < 0.0) {
    load_arduino_v_15_DW.Integrator_PrevResetState = -1;
  } else if (load_arduino_v_15_B.a_n == 0.0) {
    load_arduino_v_15_DW.Integrator_PrevResetState = 0;
  } else {
    load_arduino_v_15_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S403>/Integrator' */

  /* Update for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

  /* S-Function "Servo_microseconds_alettoni_beta_3_wrapper" Block: <S10>/S-Function Builder10 */
  Servo_microseconds_alettoni_beta_3_Update_wrapper
    (&load_arduino_v_15_B.DataTypeConversion1_c,
     &load_arduino_v_15_DW.SFunctionBuilder10_DSTATE);

  /* Update for DiscreteIntegrator: '<S286>/Integrator' */
  load_arduino_v_15_DW.Integrator_DSTATE_n +=
    load_arduino_v_15_P.Integrator_gainval_l *
    load_arduino_v_15_B.rtb_Gain1_idx_1;

  /* Update for DiscreteIntegrator: '<S310>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S310>/Constant7'
   */
  load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE +=
    load_arduino_v_15_P.DiscreteTimeIntegrator_gainva_p *
    load_arduino_v_15_P.Constant7_Value_i;
  if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE >=
      load_arduino_v_15_P.attuatore_Tmax) {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_15_P.attuatore_Tmax;
  } else {
    if (load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE <=
        load_arduino_v_15_P.DiscreteTimeIntegrator_LowerS_o) {
      load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE =
        load_arduino_v_15_P.DiscreteTimeIntegrator_LowerS_o;
    }
  }

  if (load_arduino_v_15_B.Sum3 > 0.0) {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (load_arduino_v_15_B.Sum3 < 0.0) {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (load_arduino_v_15_B.Sum3 == 0.0) {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S310>/Discrete-Time Integrator' */

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <S10>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper(&load_arduino_v_15_B.Sum,
    &load_arduino_v_15_DW.SFunctionBuilder4_DSTATE);

  /* Update for DiscreteTransferFcn: '<S307>/Discrete Washout Filter' */
  load_arduino_v_15_DW.DiscreteWashoutFilter_states =
    load_arduino_v_15_B.Gain_dw;

  /* Update for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

  /* S-Function "Servo_microseconds_timone_beta_3_wrapper" Block: <S10>/S-Function Builder5 */
  Servo_microseconds_timone_beta_3_Update_wrapper
    (&load_arduino_v_15_B.DataTypeConversion2_j,
     &load_arduino_v_15_DW.SFunctionBuilder5_DSTATE);

  /* Update for DiscreteIntegrator: '<S178>/Integrator' incorporates:
   *  Constant: '<S45>/Constant10'
   *  DiscreteIntegrator: '<S82>/Integrator'
   *  Gain: '<S189>/Kt'
   *  MATLAB Function: '<S40>/MATLAB Function'
   *  Product: '<S175>/IProd Out'
   *  Sum: '<S189>/SumI3'
   *  Sum: '<S190>/SumI1'
   */
  load_arduino_v_15_DW.Integrator_DSTATE_h += ((load_arduino_v_15_B.theta_rif -
    load_arduino_v_15_B.Sum_h) * load_arduino_v_15_P.PIRCsaturato_Kt +
    load_arduino_v_15_B.psi_ref_pre * load_arduino_v_15_P.Ki_h_cruise) *
    load_arduino_v_15_P.Integrator_gainval_hq;
  if (load_arduino_v_15_B.ATO > 0) {
    load_arduino_v_15_DW.Integrator_PrevResetState_c = 1;
    load_arduino_v_15_DW.Integrator_PrevResetState_a = 1;
  } else {
    load_arduino_v_15_DW.Integrator_PrevResetState_c = 0;
    load_arduino_v_15_DW.Integrator_PrevResetState_a = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S178>/Integrator' */

  /* Update for DiscreteIntegrator: '<S82>/Integrator' incorporates:
   *  Constant: '<S45>/Constant7'
   *  Gain: '<S93>/Kt'
   *  Product: '<S79>/IProd Out'
   *  Sum: '<S93>/SumI3'
   *  Sum: '<S94>/SumI1'
   */
  load_arduino_v_15_DW.Integrator_DSTATE_g += ((load_arduino_v_15_B.theta_rif -
    load_arduino_v_15_B.Sum_d) * load_arduino_v_15_P.PIApproach_Kt +
    load_arduino_v_15_B.Sum1_m * load_arduino_v_15_P.Ki_h_app) *
    load_arduino_v_15_P.Integrator_gainval_f;

  /* Update for DiscreteIntegrator: '<S77>/Filter' incorporates:
   *  DiscreteIntegrator: '<S130>/Integrator'
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  load_arduino_v_15_DW.Filter_DSTATE_l += load_arduino_v_15_P.Filter_gainval_a *
    load_arduino_v_15_B.NProdOut_m;
  if (load_arduino_v_15_B.ATO > 0) {
    load_arduino_v_15_DW.Filter_PrevResetState = 1;
    load_arduino_v_15_DW.Integrator_PrevResetState_f = 1;
  } else {
    load_arduino_v_15_DW.Filter_PrevResetState = 0;
    load_arduino_v_15_DW.Integrator_PrevResetState_f = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S77>/Filter' */

  /* Update for DiscreteIntegrator: '<S130>/Integrator' incorporates:
   *  Constant: '<S45>/Constant12'
   *  Gain: '<S141>/Kt'
   *  Product: '<S127>/IProd Out'
   *  Sum: '<S141>/SumI3'
   *  Sum: '<S142>/SumI1'
   */
  load_arduino_v_15_DW.Integrator_DSTATE_d5 += ((load_arduino_v_15_B.theta_rif -
    load_arduino_v_15_B.Sum_l) * load_arduino_v_15_P.PIApproach1_Kt +
    load_arduino_v_15_B.RC_l * load_arduino_v_15_P.Ki_h_flare) *
    load_arduino_v_15_P.Integrator_gainval_p;

  /* Update for DiscreteIntegrator: '<S125>/Filter' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  load_arduino_v_15_DW.Filter_DSTATE_k += load_arduino_v_15_P.Filter_gainval_d1 *
    load_arduino_v_15_B.NProdOut_j;
  if (load_arduino_v_15_B.ATO > 0) {
    load_arduino_v_15_DW.Filter_PrevResetState_f = 1;
  } else {
    load_arduino_v_15_DW.Filter_PrevResetState_f = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S125>/Filter' */

  /* Update for DiscreteIntegrator: '<S353>/Integrator' incorporates:
   *  Gain: '<S346>/Kb'
   *  Sum: '<S346>/SumI2'
   *  Sum: '<S346>/SumI4'
   */
  load_arduino_v_15_DW.Integrator_DSTATE_l += ((load_arduino_v_15_B.Saturation_i
    - load_arduino_v_15_B.Sum_a1) * load_arduino_v_15_P.PIDController_Kb +
    load_arduino_v_15_B.num_254) * load_arduino_v_15_P.Integrator_gainval_e;

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <S10>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper
    (&load_arduino_v_15_B.DataTypeConversion_p,
     &load_arduino_v_15_DW.SFunctionBuilder9_DSTATE);

  /* Update for Memory: '<S2>/Memory' */
  load_arduino_v_15_DW.Memory_PreviousInput_n = load_arduino_v_15_B.SFunction_o4;

  /* Update for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S4>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper
    (&load_arduino_v_15_DW.SFunctionBuilder_DSTATE_n);
}

/* Model step function for TID1 */
void load_arduino_v_15_step1(void)     /* Sample time: [0.04s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  rtb_PulseGenerator = (load_arduino_v_15_DW.clockTickCounter <
                        load_arduino_v_15_P.PulseGenerator_Duty) &&
    (load_arduino_v_15_DW.clockTickCounter >= 0) ?
    load_arduino_v_15_P.PulseGenerator_Amp : 0.0;
  if (load_arduino_v_15_DW.clockTickCounter >=
      load_arduino_v_15_P.PulseGenerator_Period - 1.0) {
    load_arduino_v_15_DW.clockTickCounter = 0;
  } else {
    load_arduino_v_15_DW.clockTickCounter++;
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
  rtb_PulseGenerator = (load_arduino_v_15_DW.clockTickCounter_c <
                        load_arduino_v_15_P.PulseGenerator1_Duty) &&
    (load_arduino_v_15_DW.clockTickCounter_c >= 0) ?
    load_arduino_v_15_P.PulseGenerator1_Amp : 0.0;
  if (load_arduino_v_15_DW.clockTickCounter_c >=
      load_arduino_v_15_P.PulseGenerator1_Period - 1.0) {
    load_arduino_v_15_DW.clockTickCounter_c = 0;
  } else {
    load_arduino_v_15_DW.clockTickCounter_c++;
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
void load_arduino_v_15_step2(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S29>/Add2' incorporates:
   *  Constant: '<S29>/Constant4'
   *  Constant: '<S29>/Constant5'
   *  Memory: '<S29>/Memory2'
   */
  load_arduino_v_15_DW.Memory2_PreviousInput +=
    load_arduino_v_15_P.Constant4_Value_a +
    load_arduino_v_15_P.Constant5_Value_a;

  /* Switch: '<S29>/Switch1' */
  if (load_arduino_v_15_DW.Memory2_PreviousInput >
      load_arduino_v_15_P.Switch1_Threshold_ca) {
    /* Sum: '<S29>/Add2' incorporates:
     *  Constant: '<S29>/Constant4'
     */
    load_arduino_v_15_DW.Memory2_PreviousInput =
      load_arduino_v_15_P.Constant4_Value_a;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* RateTransition: '<S29>/Rate Transition' */
  load_arduino_v_15_DW.RateTransition_Buffer0 =
    load_arduino_v_15_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void load_arduino_v_15_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)load_arduino_v_15_M, 0,
                sizeof(RT_MODEL_load_arduino_v_15_T));

  /* block I/O */
  (void) memset(((void *) &load_arduino_v_15_B), 0,
                sizeof(B_load_arduino_v_15_T));

  /* states (dwork) */
  (void) memset((void *)&load_arduino_v_15_DW, 0,
                sizeof(DW_load_arduino_v_15_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    codertarget_arduinobase_inter_T *obj;
    real_T Switch_a;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S580>/S-Function Builder1' */

    /* S-Function Block: <S580>/S-Function Builder1 */
    Mti_Start_wrapper(&load_arduino_v_15_DW.SFunctionBuilder1_DSTATE);
    load_arduino_v_15_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
    load_arduino_v_15_PrevZCX.ResettableSubsystem_Reset_ZCE_p =
      UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.ResettableSubsystem_Reset_ZCE_h =
      UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.ResettableSubsystem_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.SampleandHold_Trig_ZCE_e = UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    load_arduino_v_15_PrevZCX.ResettableSubsystem_o.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;
    load_arduino_v_15_PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&load_arduino_v_15_DW.Memory4_PreviousInput_c[0],
           &load_arduino_v_15_P.Memory4_InitialCondition_g[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S580>/S-Function Builder1' */

    /* S-Function Block: <S580>/S-Function Builder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder1_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S578>/Unit Delay' */
    load_arduino_v_15_DW.UnitDelay_DSTATE =
      load_arduino_v_15_P.UnitDelay_InitialCondition;

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      load_arduino_v_15_DW.Memory5_PreviousInput_l[i] =
        load_arduino_v_15_P.Memory5_InitialCondition_d;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    load_arduino_v_15_DW.Memory1_PreviousInput_d[0] =
      load_arduino_v_15_P.Memory1_InitialCondition_b;
    load_arduino_v_15_DW.Memory1_PreviousInput_d[1] =
      load_arduino_v_15_P.Memory1_InitialCondition_b;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    load_arduino_v_15_DW.Memory_PreviousInput_h5[0] =
      load_arduino_v_15_P.Memory_InitialCondition_o;
    load_arduino_v_15_DW.Memory_PreviousInput_h5[1] =
      load_arduino_v_15_P.Memory_InitialCondition_o;
    load_arduino_v_15_DW.Memory_PreviousInput_h5[2] =
      load_arduino_v_15_P.Memory_InitialCondition_o;
    load_arduino_v_15_DW.Memory_PreviousInput_h5[3] =
      load_arduino_v_15_P.Memory_InitialCondition_o;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    load_arduino_v_15_DW.Memory3_PreviousInput_o =
      load_arduino_v_15_P.Memory3_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      load_arduino_v_15_DW.Memory_PreviousInput_i[i] =
        load_arduino_v_15_P.Memory_InitialCondition_at;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      load_arduino_v_15_DW.Memory2_PreviousInput_a[i] =
        load_arduino_v_15_P.Memory2_InitialCondition_go[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateLimiter: '<S6>/Rate Limiter1' */
    load_arduino_v_15_DW.PrevY = load_arduino_v_15_P.RateLimiter1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S232>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE =
      load_arduino_v_15_P.PIDController1_InitialConditi_n;

    /* InitializeConditions for DiscreteIntegrator: '<S227>/Filter' */
    load_arduino_v_15_DW.Filter_DSTATE =
      load_arduino_v_15_P.PIDController1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S403>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_d =
      load_arduino_v_15_P.PIDController_InitialConditi_ld;
    load_arduino_v_15_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

    /* S-Function Block: <S10>/S-Function Builder10 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder10_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S286>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_n =
      load_arduino_v_15_P.PIDController_InitialConditio_g;

    /* InitializeConditions for DiscreteIntegrator: '<S310>/Discrete-Time Integrator' */
    load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE =
      load_arduino_v_15_P.DiscreteTimeIntegrator_IC_e;
    load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for RateLimiter: '<S39>/Rate Limiter' */
    load_arduino_v_15_DW.PrevY_o = load_arduino_v_15_P.RateLimiter_IC;

    /* InitializeConditions for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

    /* S-Function Block: <S10>/S-Function Builder4 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder4_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteTransferFcn: '<S307>/Discrete Washout Filter' */
    load_arduino_v_15_DW.DiscreteWashoutFilter_states =
      load_arduino_v_15_P.DiscreteWashoutFilter_InitialSt;

    /* InitializeConditions for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

    /* S-Function Block: <S10>/S-Function Builder5 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder5_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S178>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_h =
      load_arduino_v_15_P.PIRCsaturato_InitialConditionFo;
    load_arduino_v_15_DW.Integrator_PrevResetState_c = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S82>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_g =
      load_arduino_v_15_P.PIApproach_InitialConditionForI;
    load_arduino_v_15_DW.Integrator_PrevResetState_a = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S77>/Filter' */
    load_arduino_v_15_DW.Filter_DSTATE_l =
      load_arduino_v_15_P.PIApproach_InitialConditionForF;
    load_arduino_v_15_DW.Filter_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S130>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_d5 =
      load_arduino_v_15_P.PIApproach1_InitialConditionF_n;
    load_arduino_v_15_DW.Integrator_PrevResetState_f = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S125>/Filter' */
    load_arduino_v_15_DW.Filter_DSTATE_k =
      load_arduino_v_15_P.PIApproach1_InitialConditionFor;
    load_arduino_v_15_DW.Filter_PrevResetState_f = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S353>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_l =
      load_arduino_v_15_P.PIDController_InitialConditio_a;

    /* InitializeConditions for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

    /* S-Function Block: <S10>/S-Function Builder9 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder9_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for RateTransition: '<S29>/Rate Transition' */
    load_arduino_v_15_DW.RateTransition_Buffer0 =
      load_arduino_v_15_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S29>/Switch' incorporates:
     *  Memory: '<S29>/Memory1'
     */
    load_arduino_v_15_DW.Memory1_PreviousInput =
      load_arduino_v_15_P.Memory1_InitialCondition_p;

    /* InitializeConditions for Sum: '<S29>/Add' incorporates:
     *  Memory: '<S29>/Memory'
     */
    load_arduino_v_15_DW.Memory_PreviousInput =
      load_arduino_v_15_P.Memory_InitialCondition_au;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    load_arduino_v_15_DW.Memory_PreviousInput_n =
      load_arduino_v_15_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S581>/Delay Input2'
     *
     * Block description for '<S581>/Delay Input2':
     *
     *  Store in Global RAM
     */
    load_arduino_v_15_DW.DelayInput2_DSTATE =
      load_arduino_v_15_P.DelayInput2_InitialCondition;

    /* InitializeConditions for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

    /* S-Function Block: <S4>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          load_arduino_v_15_DW.SFunctionBuilder_DSTATE_n = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
    load_arduino_v_15_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    load_arduino_v_15_DW.clockTickCounter_c = 0;

    /* InitializeConditions for Sum: '<S29>/Add2' incorporates:
     *  Memory: '<S29>/Memory2'
     */
    load_arduino_v_15_DW.Memory2_PreviousInput =
      load_arduino_v_15_P.Memory2_InitialCondition_o;

    /* SystemInitialize for Enabled SubSystem: '<S578>/Execution_loop' */
    /* Start for MATLABSystem: '<S582>/I2C Read12' */
    load_arduino_v_15_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &load_arduino_v_15_DW.obj_f;
    load_arduino_v_15_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    load_arduino_v_15_DW.obj_f.isInitialized = 0;
    load_arduino_v_15_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    load_arduino_v_15_DW.obj_f.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_f.SampleTime = load_arduino_v_15_P.t_AP;
    obj = &load_arduino_v_15_DW.obj_f;
    load_arduino_v_15_DW.obj_f.isSetupComplete = false;
    load_arduino_v_15_DW.obj_f.isInitialized = 1;
    load_arduino_v_15_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(load_arduino_v_15_B.i2cname, 0);
    load_arduino_v_15_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = load_arduino_v_15_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    load_arduino_v_15_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S582>/I2C Read1' */
    load_arduino_v_15_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &load_arduino_v_15_DW.obj_p;
    load_arduino_v_15_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    load_arduino_v_15_DW.obj_p.isInitialized = 0;
    load_arduino_v_15_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    load_arduino_v_15_DW.obj_p.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_p.SampleTime = load_arduino_v_15_P.t_AP;
    obj = &load_arduino_v_15_DW.obj_p;
    load_arduino_v_15_DW.obj_p.isSetupComplete = false;
    load_arduino_v_15_DW.obj_p.isInitialized = 1;
    load_arduino_v_15_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(load_arduino_v_15_B.i2cname, 0);
    load_arduino_v_15_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = load_arduino_v_15_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    load_arduino_v_15_DW.obj_p.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S582>/S-Function Builder' incorporates:
     *  Outport: '<S582>/T'
     */
    load_arduino_v_15_B.SFunctionBuilder_o1 = load_arduino_v_15_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S582>/S-Function Builder1' incorporates:
     *  Outport: '<S582>/p'
     */
    load_arduino_v_15_B.SFunctionBuilder1 = load_arduino_v_15_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S578>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S578>/MATLAB Function' */
    load_arduino_v_15_DW.P_ref = 101325.0;
    load_arduino_v_15_DW.rl_up = 300.0;
    load_arduino_v_15_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S578>/One_time_initialization' */
    One_time_initializatio_Init(&load_arduino_v_15_B.One_time_initialization,
      &load_arduino_v_15_DW.One_time_initialization,
      &load_arduino_v_15_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S578>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S586>/Subsystem1' */
    /* SystemInitialize for Outport: '<S588>/T_0' incorporates:
     *  Inport: '<S588>/T'
     */
    load_arduino_v_15_B.T = load_arduino_v_15_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S586>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S579>/Subsystem1' */
    /* SystemInitialize for Switch: '<S589>/Switch' incorporates:
     *  Outport: '<S589>/h_to_subtract'
     */
    load_arduino_v_15_B.Switch = load_arduino_v_15_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S579>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S579>/Subsystem2' */
    /* SystemInitialize for MATLAB Function: '<S590>/Create_message' */
    load_arduino_v_15_DW.end_found = false;
    load_arduino_v_15_DW.start_found = false;
    load_arduino_v_15_DW.counter_k = 0U;
    memset(&load_arduino_v_15_DW.message[0], 0, 80U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S590>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S592>/Memory' */
      load_arduino_v_15_DW.Memory_PreviousInput_l[i] =
        load_arduino_v_15_P.Memory_InitialCondition_a;

      /* SystemInitialize for ComplexToRealImag: '<S592>/Complex to Real-Imag' incorporates:
       *  Outport: '<S592>/Outport'
       */
      load_arduino_v_15_B.ComplextoRealImag[i] = load_arduino_v_15_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S592>/mario' */
    load_arduino_v_15_B.indice_dimario = load_arduino_v_15_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S590>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S579>/Subsystem2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&load_arduino_v_15_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);
    load_arduino_v_15_DW.WP_dbP_not_empty = false;
    load_arduino_v_15_DW.WP_dbP_AL_not_empty = false;
    load_arduino_v_15_DW.test1 = 0.0;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3' */
    load_arduino_v_15_DW.counter = 0U;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    load_arduino_v_15_DW.Interr_parz = false;
    memset(&load_arduino_v_15_DW.message_i[0], 0, 100U * sizeof(uint8_T));
    load_arduino_v_15_DW.counter_a = 0U;
    load_arduino_v_15_DW.mess_len = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    load_arduino_v_15_DW.is_active_c9_load_arduino_v_15 = 0U;
    load_arduino_v_15_DW.i = 0U;

    /* SystemInitialize for Chart: '<S15>/Chart' incorporates:
     *  SubSystem: '<S24>/sendbyte'
     */
    /* Start for MATLABSystem: '<S25>/Serial Transmit' */
    load_arduino_v_15_DW.obj_o.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_o.Protocol =
      load_arduino_v_15_P.SerialTransmit_Protocol;
    load_arduino_v_15_DW.obj_o.isInitialized = 1;
    load_arduino_v_15_DW.obj_o.port = 2.0;
    load_arduino_v_15_DW.obj_o.dataSizeInBytes = 1.0;
    load_arduino_v_15_DW.obj_o.dataType = 0.0;
    load_arduino_v_15_DW.obj_o.sendModeEnum = 0.0;
    load_arduino_v_15_DW.obj_o.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(load_arduino_v_15_DW.obj_o.port);
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
    load_arduino_v_15_DW.obj_o.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S25>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
    load_arduino_v_15_DW.is_active_c23_load_arduino_v_15 = 0U;
    load_arduino_v_15_DW.is_c23_load_arduino_v_15 = 0;
    load_arduino_v_15_B.mod = 0.0;

    /* SystemInitialize for Triggered SubSystem: '<S252>/Enabled Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S303>/Out1' incorporates:
     *  Outport: '<S303>/Out1'
     */
    load_arduino_v_15_B.OutportBufferForOut1 = load_arduino_v_15_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S252>/Enabled Subsystem' */

    /* SystemInitialize for Chart: '<S40>/ STATI' */
    load_arduino_v_15_DW.is_AUTOMATICA = 0;
    load_arduino_v_15_DW.is_active_c26_load_arduino_v_15 = 0U;
    load_arduino_v_15_DW.is_c26_load_arduino_v_15 = 0;
    load_arduino_v_15_B.switch_manetta = 0.0;
    load_arduino_v_15_B.switch_equilibratore = 0.0;
    load_arduino_v_15_B.switch_alettoni = 0.0;
    load_arduino_v_15_B.switch_timone = 0.0;
    load_arduino_v_15_B.phi_safe = 0.0;
    load_arduino_v_15_B.theta_safe = 0.0;
    load_arduino_v_15_B.throttle_safe = 0.0;
    load_arduino_v_15_B.modo = 1.0;

    /* SystemInitialize for Enabled SubSystem: '<S422>/Enabled Subsystem' */
    load__EnabledSubsystem_Init(&Switch_a,
      &load_arduino_v_15_P.EnabledSubsystem_h);

    /* End of SystemInitialize for SubSystem: '<S422>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S422>/Resettable Subsystem' */
    lo_ResettableSubsystem_Init(&load_arduino_v_15_DW.ResettableSubsystem,
      &load_arduino_v_15_P.ResettableSubsystem);

    /* End of SystemInitialize for SubSystem: '<S422>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S423>/Enabled Subsystem' */
    load__EnabledSubsystem_Init(&load_arduino_v_15_B.Switch_l,
      &load_arduino_v_15_P.EnabledSubsystem_j);

    /* End of SystemInitialize for SubSystem: '<S423>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S423>/Resettable Subsystem' */
    lo_ResettableSubsystem_Init(&load_arduino_v_15_DW.ResettableSubsystem_o,
      &load_arduino_v_15_P.ResettableSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S423>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S424>/MATLAB Function1' */
    load_arduino_v_15_DW.Tf_not_empty = false;

    /* SystemInitialize for Enabled SubSystem: '<S446>/Enabled ' */
    /* SystemInitialize for Switch: '<S448>/Switch' incorporates:
     *  Outport: '<S448>/Alarm Safe'
     */
    load_arduino_v_15_B.Switch_n = load_arduino_v_15_P.AlarmSafe_Y0;

    /* End of SystemInitialize for SubSystem: '<S446>/Enabled ' */

    /* SystemInitialize for Resettable SubSystem: '<S446>/Resettable Subsystem' */
    /* InitializeConditions for Sum: '<S450>/Sum' incorporates:
     *  Memory: '<S450>/Memory'
     */
    load_arduino_v_15_DW.Memory_PreviousInput_h =
      load_arduino_v_15_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S446>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S429>/MATLAB Function1' */
    load_arduino_v_15_DW.alarm = 0.0;

    /* SystemInitialize for Chart: '<S41>/Chart' */
    load_arduino_v_15_DW.is_active_c1_load_arduino_v_15 = 0U;
    load_arduino_v_15_DW.is_c1_load_arduino_v_15 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S41>/DECOLLO AUTOMATICO' */
    /* InitializeConditions for Memory: '<S452>/Memory' */
    load_arduino_v_15_DW.Memory_PreviousInput_a =
      load_arduino_v_15_P.Memory_InitialCondition_k;

    /* InitializeConditions for Memory: '<S452>/Memory1' */
    load_arduino_v_15_DW.Memory1_PreviousInput_m =
      load_arduino_v_15_P.Memory1_InitialCondition;

    /* SystemInitialize for Chart: '<S452>/Chart1' */
    load_arduino_v_15_DW.temporalCounter_i1 = 0U;
    load_arduino_v_15_DW.is_active_c2_load_arduino_v_15 = 0U;
    load_arduino_v_15_DW.is_c2_load_arduino_v_15 = 0;

    /* SystemInitialize for Triggered SubSystem: '<S452>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S461>/ ' incorporates:
     *  Inport: '<S461>/In'
     */
    load_arduino_v_15_B.In_o = load_arduino_v_15_P._Y0;

    /* End of SystemInitialize for SubSystem: '<S452>/Sample and Hold' */

    /* SystemInitialize for Triggered SubSystem: '<S452>/Sample and Hold1' */
    /* SystemInitialize for Outport: '<S462>/ ' incorporates:
     *  Inport: '<S462>/In'
     */
    load_arduino_v_15_B.In_j = load_arduino_v_15_P._Y0_a;

    /* End of SystemInitialize for SubSystem: '<S452>/Sample and Hold1' */

    /* SystemInitialize for Gain: '<S460>/Gain' incorporates:
     *  Outport: '<S452>/rotta_ATO'
     */
    load_arduino_v_15_B.Gain_f = load_arduino_v_15_P.rotta_ATO_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/DECOLLO AUTOMATICO' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem' */
    /* InitializeConditions for Memory: '<S454>/Memory' */
    load_arduino_v_15_DW.Memory_PreviousInput_b =
      load_arduino_v_15_P.Memory_InitialCondition_af;

    /* InitializeConditions for Memory: '<S454>/Memory1' */
    load_arduino_v_15_DW.Memory1_PreviousInput_a =
      load_arduino_v_15_P.Memory1_InitialCondition_k;

    /* InitializeConditions for Memory: '<S454>/Memory2' */
    load_arduino_v_15_DW.Memory2_PreviousInput_d =
      load_arduino_v_15_P.Memory2_InitialCondition_g;

    /* InitializeConditions for Memory: '<S454>/Memory3' */
    load_arduino_v_15_DW.Memory3_PreviousInput =
      load_arduino_v_15_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S454>/Memory6' */
    load_arduino_v_15_DW.Memory6_PreviousInput =
      load_arduino_v_15_P.Memory6_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S454>/VETTORIALE' */
    load_arduino_v_15_DW.V_ref = 0.0;
    load_arduino_v_15_DW.ALT_ref = 0.0;
    load_arduino_v_15_DW.HDG_ref = 0.0;

    /* SystemInitialize for Outport: '<S454>/Out1' */
    load_arduino_v_15_B.V_vett = load_arduino_v_15_P.Out1_Y0_f;

    /* SystemInitialize for Outport: '<S454>/Out2' */
    load_arduino_v_15_B.h_vett = load_arduino_v_15_P.Out2_Y0;

    /* SystemInitialize for Outport: '<S454>/Out3' */
    load_arduino_v_15_B.rotta_vett = load_arduino_v_15_P.Out3_Y0;

    /* SystemInitialize for Outport: '<S454>/Out4' */
    load_arduino_v_15_B.RC_vett = load_arduino_v_15_P.Out4_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem1' */
    /* InitializeConditions for Memory: '<S455>/Memory7' */
    load_arduino_v_15_DW.Memory7_PreviousInput =
      load_arduino_v_15_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S455>/Memory5' */
    load_arduino_v_15_DW.Memory5_PreviousInput =
      load_arduino_v_15_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S455>/Memory1' */
    load_arduino_v_15_DW.Memory1_PreviousInput_i =
      load_arduino_v_15_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<S455>/Memory2' */
    load_arduino_v_15_DW.Memory2_PreviousInput_o =
      load_arduino_v_15_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S455>/ALLINEAMENTO' */
    load_arduino_v_15_DW.flag_m = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S455>/FLARE' */
    /* SystemInitialize for Enabled SubSystem: '<S455>/APPROACH' */
    /* Start for Constant: '<S466>/Constant1' incorporates:
     *  Constant: '<S470>/Constant1'
     */
    load_arduino_v_15_B.Constant1_l = load_arduino_v_15_P.V_stall * 1.2;

    /* End of SystemInitialize for SubSystem: '<S455>/FLARE' */

    /* InitializeConditions for DiscreteIntegrator: '<S466>/Discrete-Time Integrator' */
    load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m =
      load_arduino_v_15_P.DiscreteTimeIntegrator_IC;
    load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h = 2;

    /* SystemInitialize for MATLAB Function: '<S466>/MATLAB Function' */
    load_arduino_v_15_DW.x_not_empty = false;
    load_arduino_v_15_DW.x_new_not_empty = false;
    load_arduino_v_15_DW.cycle_count_not_empty = false;
    load_arduino_v_15_DW.eps_not_empty = false;

    /* SystemInitialize for Product: '<S466>/Multiply' incorporates:
     *  Outport: '<S466>/h_ref'
     */
    load_arduino_v_15_B.Multiply = load_arduino_v_15_P.h_ref_Y0;

    /* SystemInitialize for Outport: '<S466>/flare_data' */
    load_arduino_v_15_B.x_f_out = load_arduino_v_15_P.flare_data_Y0;
    load_arduino_v_15_B.h_f_out = load_arduino_v_15_P.flare_data_Y0;
    load_arduino_v_15_B.k_x_out = load_arduino_v_15_P.flare_data_Y0;
    load_arduino_v_15_B.h_c_out = load_arduino_v_15_P.flare_data_Y0;

    /* SystemInitialize for Outport: '<S466>/landing_abort' */
    load_arduino_v_15_B.no_solution = load_arduino_v_15_P.landing_abort_Y0;

    /* SystemInitialize for Product: '<S466>/Multiply1' incorporates:
     *  Outport: '<S466>/rc_ref_app'
     */
    load_arduino_v_15_B.Multiply1 = load_arduino_v_15_P.rc_ref_app_Y0;

    /* End of SystemInitialize for SubSystem: '<S455>/APPROACH' */

    /* SystemInitialize for Chart: '<S455>/Chart1' */
    load_arduino_v_15_DW.is_active_c17_load_arduino_v_15 = 0U;
    load_arduino_v_15_DW.is_c17_load_arduino_v_15 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S455>/FLARE' */
    /* Start for Constant: '<S470>/Constant1' */
    load_arduino_v_15_B.Constant1 = load_arduino_v_15_B.Constant1_l;

    /* SystemInitialize for Sum: '<S470>/Sum2' incorporates:
     *  Outport: '<S470>/h_ref'
     */
    load_arduino_v_15_B.Sum2 = load_arduino_v_15_P.h_ref_Y0_b;

    /* SystemInitialize for Gain: '<S470>/Gain2' incorporates:
     *  Outport: '<S470>/RC_ref'
     */
    load_arduino_v_15_B.Gain2 = load_arduino_v_15_P.RC_ref_Y0;

    /* End of SystemInitialize for SubSystem: '<S455>/FLARE' */

    /* SystemInitialize for Enabled SubSystem: '<S455>/INSEGUIMENTO CENTRO PISTA' */
    /* InitializeConditions for DiscreteIntegrator: '<S514>/Filter' */
    load_arduino_v_15_DW.Filter_DSTATE_g =
      load_arduino_v_15_P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S519>/Integrator' */
    load_arduino_v_15_DW.Integrator_DSTATE_o =
      load_arduino_v_15_P.PIDController_InitialConditio_l;

    /* SystemInitialize for Gain: '<S487>/Gain' incorporates:
     *  Outport: '<S471>/psi_ref_landing'
     */
    load_arduino_v_15_B.Gain = load_arduino_v_15_P.psi_ref_landing_Y0;

    /* End of SystemInitialize for SubSystem: '<S455>/INSEGUIMENTO CENTRO PISTA' */

    /* SystemInitialize for Triggered SubSystem: '<S455>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S480>/ ' incorporates:
     *  Inport: '<S480>/In'
     */
    load_arduino_v_15_B.In[0] = load_arduino_v_15_P._Y0_f[0];
    load_arduino_v_15_B.In[1] = load_arduino_v_15_P._Y0_f[1];

    /* End of SystemInitialize for SubSystem: '<S455>/Sample and Hold' */

    /* SystemInitialize for MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation5' incorporates:
     *  Outport: '<S455>/TAS_AL'
     */
    load_arduino_v_15_B.velocita = load_arduino_v_15_P.TAS_AL_Y0;

    /* SystemInitialize for Sum: '<S455>/Sum' incorporates:
     *  Outport: '<S455>/QUOTA_AL'
     */
    load_arduino_v_15_B.QUOTA_n = load_arduino_v_15_P.QUOTA_AL_Y0;

    /* SystemInitialize for MultiPortSwitch: '<S455>/Switch di selezione  Task - Waypoint navigation6' incorporates:
     *  Outport: '<S455>/RC_AL'
     */
    load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna =
      load_arduino_v_15_P.RC_AL_Y0;

    /* SystemInitialize for Switch: '<S455>/Switch1' incorporates:
     *  Outport: '<S455>/ROTTA_AL'
     */
    load_arduino_v_15_B.Switch1 = load_arduino_v_15_P.ROTTA_AL_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem2' */
    /* InitializeConditions for Memory: '<S456>/Memory4' */
    load_arduino_v_15_DW.Memory4_PreviousInput =
      load_arduino_v_15_P.Memory4_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S456>/WAYPOINTS' */
    load_arduino_v_15_DW.flag_l = 0.0;
    load_arduino_v_15_DW.lat1 = 0.0;
    load_arduino_v_15_DW.long1 = 0.0;

    /* SystemInitialize for Saturate: '<S456>/saturatore V1' incorporates:
     *  Outport: '<S456>/RC'
     */
    load_arduino_v_15_B.RC = load_arduino_v_15_P.RC_Y0;

    /* SystemInitialize for Saturate: '<S456>/saturatore V' incorporates:
     *  Outport: '<S456>/VELOCITA'
     */
    load_arduino_v_15_B.VELOCITA = load_arduino_v_15_P.VELOCITA_Y0;

    /* SystemInitialize for Outport: '<S456>/Out3' */
    load_arduino_v_15_B.QUOTA = load_arduino_v_15_P.Out3_Y0_j;

    /* SystemInitialize for Outport: '<S456>/Out4' */
    load_arduino_v_15_B.ROTTA = load_arduino_v_15_P.Out4_Y0_e;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem3' */
    /* SystemInitialize for MATLAB Function: '<S457>/GO_HOME' */
    load_arduino_v_15_DW.flag = 0.0;

    /* SystemInitialize for Outport: '<S457>/Out1' */
    load_arduino_v_15_B.V_goHome = load_arduino_v_15_P.Out1_Y0_j;

    /* SystemInitialize for Outport: '<S457>/Out2' */
    load_arduino_v_15_B.h_goHome = load_arduino_v_15_P.Out2_Y0_n;

    /* SystemInitialize for Outport: '<S457>/Out3' */
    load_arduino_v_15_B.RC_goHome = load_arduino_v_15_P.Out3_Y0_e;

    /* SystemInitialize for Outport: '<S457>/Out4' */
    load_arduino_v_15_B.rotta_goHome = load_arduino_v_15_P.Out4_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem3' */

    /* SystemInitialize for Enabled SubSystem: '<S571>/Subsystem1' */
    /* SystemInitialize for MATLAB Function: '<S575>/MATLAB Function' */
    load_arduino_v_15_DW.start_found_c = false;
    load_arduino_v_15_DW.counter_n = 0U;
    for (i = 0; i < 31; i++) {
      load_arduino_v_15_DW.message_k[i] = 0U;
    }

    /* End of SystemInitialize for MATLAB Function: '<S575>/MATLAB Function' */

    /* SystemInitialize for Enabled SubSystem: '<S575>/Subsystem2' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out2'
     */
    load_arduino_v_15_B.ByteUnpack_o2[0] = load_arduino_v_15_P.Out2_Y0_c;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out3'
     */
    load_arduino_v_15_B.ByteUnpack_o3[0] = load_arduino_v_15_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out2'
     */
    load_arduino_v_15_B.ByteUnpack_o2[1] = load_arduino_v_15_P.Out2_Y0_c;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out3'
     */
    load_arduino_v_15_B.ByteUnpack_o3[1] = load_arduino_v_15_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out2'
     */
    load_arduino_v_15_B.ByteUnpack_o2[2] = load_arduino_v_15_P.Out2_Y0_c;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out3'
     */
    load_arduino_v_15_B.ByteUnpack_o3[2] = load_arduino_v_15_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out2'
     */
    load_arduino_v_15_B.ByteUnpack_o2[3] = load_arduino_v_15_P.Out2_Y0_c;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out3'
     */
    load_arduino_v_15_B.ByteUnpack_o3[3] = load_arduino_v_15_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S577>/Byte Unpack' incorporates:
     *  Outport: '<S577>/Out4'
     */
    load_arduino_v_15_B.ByteUnpack_o4[0] = load_arduino_v_15_P.Out4_Y0_i;
    load_arduino_v_15_B.ByteUnpack_o4[1] = load_arduino_v_15_P.Out4_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S575>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S571>/Subsystem1' */

    /* Start for MATLABSystem: '<S571>/Serial Receive' */
    load_arduino_v_15_DW.obj_m.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_m.Protocol =
      load_arduino_v_15_P.SerialReceive_Protocol;
    load_arduino_v_15_DW.obj_m.isInitialized = 1;
    load_arduino_v_15_DW.obj_m.DataTypeWidth = 1U;
    varargin_1 = 31U * load_arduino_v_15_DW.obj_m.DataTypeWidth;
    if (varargin_1 > 65535U) {
      varargin_1 = 65535U;
    }

    load_arduino_v_15_DW.obj_m.DataSizeInBytes = (uint16_T)varargin_1;
    MW_SCI_Open(1);
    load_arduino_v_15_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S571>/Serial Receive' */

    /* Start for MATLABSystem: '<S579>/Serial Receive1' */
    load_arduino_v_15_DW.obj_e.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_e.Protocol =
      load_arduino_v_15_P.SerialReceive1_Protocol;
    load_arduino_v_15_DW.obj_e.isInitialized = 1;
    load_arduino_v_15_DW.obj_e.DataTypeWidth = 1U;
    if (load_arduino_v_15_DW.obj_e.DataTypeWidth > 2047) {
      load_arduino_v_15_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      load_arduino_v_15_DW.obj_e.DataSizeInBytes = (uint16_T)
        (load_arduino_v_15_DW.obj_e.DataTypeWidth << 5);
    }

    MW_SCI_Open(0);
    load_arduino_v_15_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S579>/Serial Receive1' */

    /* Start for MATLABSystem: '<S571>/Serial Transmit' */
    load_arduino_v_15_DW.obj.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj.Protocol =
      load_arduino_v_15_P.SerialTransmit_Protocol_b;
    load_arduino_v_15_DW.obj.isInitialized = 1;
    load_arduino_v_15_DW.obj.port = 1.0;
    load_arduino_v_15_DW.obj.dataSizeInBytes = 1.0;
    load_arduino_v_15_DW.obj.dataType = 0.0;
    load_arduino_v_15_DW.obj.sendModeEnum = 0.0;
    load_arduino_v_15_DW.obj.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(load_arduino_v_15_DW.obj.port);
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
    load_arduino_v_15_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S571>/Serial Transmit' */

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    load_arduino_v_15_DW.obj_d.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_d.isInitialized = 1;
    digitalIOSetup(13, 1);
    load_arduino_v_15_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    load_arduino_v_15_DW.obj_b.matlabCodegenIsDeleted = false;
    load_arduino_v_15_DW.obj_b.isInitialized = 1;
    digitalIOSetup(44, 1);
    load_arduino_v_15_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void load_arduino_v_15_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S578>/One_time_initialization' */
  One_time_initializatio_Term(&load_arduino_v_15_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S578>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S578>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S582>/I2C Read12' */
  obj = &load_arduino_v_15_DW.obj_f;
  if (!load_arduino_v_15_DW.obj_f.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((load_arduino_v_15_DW.obj_f.isInitialized == 1) &&
        load_arduino_v_15_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S582>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S582>/I2C Read1' */
  obj = &load_arduino_v_15_DW.obj_p;
  if (!load_arduino_v_15_DW.obj_p.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((load_arduino_v_15_DW.obj_p.isInitialized == 1) &&
        load_arduino_v_15_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S582>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S578>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S571>/Serial Receive' */
  if (!load_arduino_v_15_DW.obj_m.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S571>/Serial Receive' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S15>/Chart' incorporates:
   *  SubSystem: '<S24>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  if (!load_arduino_v_15_DW.obj_o.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S579>/Serial Receive1' */
  if (!load_arduino_v_15_DW.obj_e.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S579>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<S571>/Serial Transmit' */
  if (!load_arduino_v_15_DW.obj.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S571>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!load_arduino_v_15_DW.obj_d.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!load_arduino_v_15_DW.obj_b.matlabCodegenIsDeleted) {
    load_arduino_v_15_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
