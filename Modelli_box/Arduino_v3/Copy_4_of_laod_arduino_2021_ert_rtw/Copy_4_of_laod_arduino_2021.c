/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_4_of_laod_arduino_2021.c
 *
 * Code generated for Simulink model 'Copy_4_of_laod_arduino_2021'.
 *
 * Model version                  : 5.21
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 19:05:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_4_of_laod_arduino_2021.h"
#include "Copy_4_of_laod_arduino_2021_private.h"

/* Named constants for Chart: '<S42>/SELEZIONE MODALITA\'  HOLD//SELECT' */
#define Copy_4_of_laod_arduin_IN_Select ((uint8_T)2U)
#define Copy_4_of_laod_arduino__IN_Hold ((uint8_T)1U)

/* Named constants for Chart: '<S40>/ STATI' */
#define Copy_4_of_IN_DECOLLO_AUTOMATICO ((uint8_T)2U)
#define Copy_4_of__IN_Intervento_Pilota ((uint8_T)3U)
#define Copy_4_of_laod_ar_IN_AUTOMATICA ((uint8_T)1U)
#define Copy_4_of_laod_ar_IN_VETTORIALE ((uint8_T)4U)
#define Copy_4_of_laod_ardu_IN_Stand_By ((uint8_T)6U)
#define Copy_4_of_laod_ardu_IN_WAYPOINT ((uint8_T)5U)
#define Copy_4_of_laod_ardui_IN_Go_Home ((uint8_T)2U)
#define Copy_4_of_laod_ardui_IN_MANUALE ((uint8_T)4U)
#define Copy_4_of_laod_arduino__IN_Safe ((uint8_T)5U)
#define Copy_4_of_laod_arduino__IN_TEST ((uint8_T)3U)
#define Copy__IN_ATTERRAGGIO_AUTOMATICO ((uint8_T)1U)

/* Named constants for Chart: '<S41>/Chart' */
#define Copy_4_of_laod_a_IN_AutoLanding ((uint8_T)1U)
#define Copy_4_of_laod_a_IN_AutoTakeoff ((uint8_T)2U)
#define Copy_4_of_laod_ar_IN_Vettoriale ((uint8_T)5U)
#define Copy_4_of_laod_ardu_IN_Waypoint ((uint8_T)6U)
#define Copy_4_of_laod_arduin_IN_GoHome ((uint8_T)3U)
#define Copy_4_of_laod_arduino_20_IN_In ((uint8_T)4U)

/* Named constants for Chart: '<S440>/Chart1' */
#define Copy_4_of_laod_ar_IN_Fase_0_ATO ((uint8_T)1U)
#define Copy_4_of_laod_ar_IN_Fase_1_ATO ((uint8_T)2U)
#define Copy_4_of_laod_ar_IN_Fase_2_ATO ((uint8_T)3U)
#define Copy_4_of_laod_ar_IN_Fase_3_ATO ((uint8_T)4U)
#define Copy_4_of_laod_ar_IN_Fase_4_ATO ((uint8_T)5U)

/* Named constants for Chart: '<S442>/Chart1' */
#define Copy_4_of_laod_a_IN_Allignment1 ((uint8_T)3U)
#define Copy_4_of_laod_ar_IN_Allignment ((uint8_T)2U)
#define Copy_4_of_laod_ardu_IN_Approach ((uint8_T)4U)
#define Copy_4_of_laod_arduino_IN_Abort ((uint8_T)1U)
#define Copy_4_of_laod_arduino_IN_Flare ((uint8_T)5U)

const uint16_T Copy_4_of_laod_arduino_2021_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_Copy_4_of_laod_arduino_2021_T Copy_4_of_laod_arduino_2021_B;

/* Block states (default storage) */
DW_Copy_4_of_laod_arduino_202_T Copy_4_of_laod_arduino_2021_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Copy_4_of_laod_arduin_T Copy_4_of_laod_arduino__PrevZCX;

/* Real-time model */
static RT_MODEL_Copy_4_of_laod_ardui_T Copy_4_of_laod_arduino_2021_M_;
RT_MODEL_Copy_4_of_laod_ardui_T *const Copy_4_of_laod_arduino_2021_M =
  &Copy_4_of_laod_arduino_2021_M_;

/* Forward declaration for local functions */
static void Copy_4_of_laod_arduino_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T Copy_4_of_laod_ardu_ifWhileCond(const boolean_T x[100]);
static void Copy_4_of_laod_arduino_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void Copy_4_of_laod_arduino_2021_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void Copy_4_of_laod_arduino_eml_find(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static boolean_T Copy_4_of_laod_ar_ifWhileCond_o(const boolean_T x[5]);
static void Copy_4_of_laod_ardui_eml_find_o(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void Copy_4_of_laod_ar_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T Copy_4_of_laod_ardui_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T Copy_4_of_laod_ard_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void Copy_4_of_laod_arduin_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Copy_4_of_laod_ardui_str2double(const char_T s[2]);
static boolean_T Copy_4_of_laod_ard_copydigits_k(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void Copy_4_of_laod_ardu_readfloat_d(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T Copy_4_of_laod_ard_str2double_l(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T Copy_4_of_laod_ardui_isUnitImag(const char_T s[3], int32_T k);
static void Copy_4_of_laod__readNonFinite_l(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T Copy_4_of_laod_ar_copydigits_k3(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T Copy_4_of_laod_a_copyexponent_k(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void Copy_4_of_laod_ard_readfloat_dt(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Copy_4_of_laod_ar_str2double_lv(const char_T s[3]);
static void Copy_4_of_laod_readNonFinite_ln(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T Copy_4_of_laod_a_copydigits_k3z(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T Copy_4_of_laod__copyexponent_kd(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void Copy_4_of_laod_ar_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Copy_4_of_laod_a_str2double_lvk(char_T s);
static real_T Copy_4_of_laod_arduino__hex2dec(const char_T s[2]);
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
void Copy_4_of_laod_arduino_2021_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Copy_4_of_laod_arduino_2021_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Copy_4_of_laod_arduino_2021_M, 2));
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
  (Copy_4_of_laod_arduino_2021_M->Timing.TaskCounters.TID[1])++;
  if ((Copy_4_of_laod_arduino_2021_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    Copy_4_of_laod_arduino_2021_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Copy_4_of_laod_arduino_2021_M->Timing.TaskCounters.TID[2])++;
  if ((Copy_4_of_laod_arduino_2021_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.1s, 0.0s] */
    Copy_4_of_laod_arduino_2021_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S410>/Enabled Subsystem'
 *    '<S411>/Enabled Subsystem'
 */
void Copy__EnabledSubsystem_Init(real_T *rty_u0, P_EnabledSubsystem_Copy_4_of__T
  *localP)
{
  /* SystemInitialize for Outport: '<S419>/1//0' */
  *rty_u0 = localP->u0_Y0;
}

/*
 * Output and update for enable system:
 *    '<S410>/Enabled Subsystem'
 *    '<S411>/Enabled Subsystem'
 */
void Copy_4_of__EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0, P_EnabledSubsystem_Copy_4_of__T *localP)
{
  /* Outputs for Enabled SubSystem: '<S410>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S419>/Enable'
   */
  if (rtu_Enable > 0) {
    /* Switch: '<S419>/Switch' incorporates:
     *  Constant: '<S419>/Constant1'
     *  Constant: '<S419>/Constant2'
     */
    if (rtu_Time > localP->Switch_Threshold) {
      *rty_u0 = localP->Constant1_Value;
    } else {
      *rty_u0 = localP->Constant2_Value;
    }

    /* End of Switch: '<S419>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S410>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S410>/Resettable Subsystem'
 *    '<S411>/Resettable Subsystem'
 */
void Co_ResettableSubsystem_Init(DW_ResettableSubsystem_Copy_4_T *localDW,
  P_ResettableSubsystem_Copy_4__T *localP)
{
  /* InitializeConditions for Memory: '<S421>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * System reset for atomic system:
 *    '<S410>/Resettable Subsystem'
 *    '<S411>/Resettable Subsystem'
 */
void C_ResettableSubsystem_Reset(DW_ResettableSubsystem_Copy_4_T *localDW,
  P_ResettableSubsystem_Copy_4__T *localP)
{
  /* InitializeConditions for Memory: '<S421>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S410>/Resettable Subsystem'
 *    '<S411>/Resettable Subsystem'
 */
real_T Copy_4__ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_Copy_4_T *localDW, P_ResettableSubsystem_Copy_4__T
  *localP, ZCE_ResettableSubsystem_Copy__T *localZCE)
{
  real_T rty_Time_0;

  /* Outputs for Resettable SubSystem: '<S410>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S420>/Reset'
   */
  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_f != POS_ZCSIG))
  {
    C_ResettableSubsystem_Reset(localDW, localP);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_f = (ZCSigState)(rtu_Reset > 0);

  /* Sum: '<S421>/Sum' incorporates:
   *  Constant: '<S421>/Constant4'
   *  Memory: '<S421>/Memory'
   */
  rty_Time_0 = Copy_4_of_laod_arduino_2021_P.t_AP +
    localDW->Memory_PreviousInput;

  /* Update for Memory: '<S421>/Memory' */
  localDW->Memory_PreviousInput = rty_Time_0;

  /* End of Outputs for SubSystem: '<S410>/Resettable Subsystem' */
  return rty_Time_0;
}

/* System initialize for enable system: '<S569>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_Cop_T *localB,
  DW_One_time_initialization_Co_T *localDW, P_One_time_initialization_Cop_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S576>/I2C Read' */
  localDW->obj_kf.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_kf;
  localDW->obj_kf.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_kf.isInitialized = 0;
  localDW->obj_kf.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_kf.matlabCodegenIsDeleted = false;
  localDW->obj_kf.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_kf;
  localDW->obj_kf.isSetupComplete = false;
  localDW->obj_kf.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_kf.BusSpeed = 100000U;
  varargin_1 = localDW->obj_kf.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_kf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read1' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read2' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read3' */
  localDW->obj_k4.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k4;
  localDW->obj_k4.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k4.isInitialized = 0;
  localDW->obj_k4.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k4.matlabCodegenIsDeleted = false;
  localDW->obj_k4.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_k4;
  localDW->obj_k4.isSetupComplete = false;
  localDW->obj_k4.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k4.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k4.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k4.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read4' */
  localDW->obj_co.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_co;
  localDW->obj_co.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_co.isInitialized = 0;
  localDW->obj_co.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_co.matlabCodegenIsDeleted = false;
  localDW->obj_co.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_co;
  localDW->obj_co.isSetupComplete = false;
  localDW->obj_co.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_co.BusSpeed = 100000U;
  varargin_1 = localDW->obj_co.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_co.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read5' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read6' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read7' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read8' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read10' */
  localDW->obj_d0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d0;
  localDW->obj_d0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d0.isInitialized = 0;
  localDW->obj_d0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d0.matlabCodegenIsDeleted = false;
  localDW->obj_d0.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_d0;
  localDW->obj_d0.isSetupComplete = false;
  localDW->obj_d0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Read11' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S576>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S576>/I2C Write2' */
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

  /* Start for MATLABSystem: '<S576>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S576>/I2C Read12' */
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

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read' incorporates:
   *  Outport: '<S576>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read1' incorporates:
   *  Outport: '<S576>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read2' incorporates:
   *  Outport: '<S576>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read3' incorporates:
   *  Outport: '<S576>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read4' incorporates:
   *  Outport: '<S576>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read5' incorporates:
   *  Outport: '<S576>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read6' incorporates:
   *  Outport: '<S576>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read7' incorporates:
   *  Outport: '<S576>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read8' incorporates:
   *  Outport: '<S576>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read9' incorporates:
   *  Outport: '<S576>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read10' incorporates:
   *  Outport: '<S576>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S576>/I2C Read11' incorporates:
   *  Outport: '<S576>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S576>/Byte Unpack' incorporates:
     *  Outport: '<S576>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S569>/One_time_initialization' */
void Cop_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_Cop_T *localB, DW_One_time_initialization_Co_T
  *localDW, P_One_time_initialization_Cop_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S569>/One_time_initialization' incorporates:
   *  EnablePort: '<S576>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S576>/I2C Write3' incorporates:
     *  ArithShift: '<S576>/Shift Arithmetic1'
     *  Constant: '<S576>/registro memoria2 '
     *  DataTypeConversion: '<S576>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S576>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S576>/I2C Read' */
    if (localDW->obj_kf.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_kf.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S576>/I2C Read' */

    /* MATLABSystem: '<S576>/I2C Read1' */
    if (localDW->obj_o.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_o.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read1' */

    /* MATLABSystem: '<S576>/I2C Read2' */
    if (localDW->obj_d.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_d.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read2' */

    /* MATLABSystem: '<S576>/I2C Read3' */
    if (localDW->obj_k4.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_k4.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S576>/I2C Read3' */

    /* MATLABSystem: '<S576>/I2C Read4' */
    if (localDW->obj_co.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_co.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read4' */

    /* MATLABSystem: '<S576>/I2C Read5' */
    if (localDW->obj_k.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_k.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read5' */

    /* MATLABSystem: '<S576>/I2C Read6' */
    if (localDW->obj_b.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_b.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read6' */

    /* MATLABSystem: '<S576>/I2C Read7' */
    if (localDW->obj_c.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_c.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read7' */

    /* MATLABSystem: '<S576>/I2C Read8' */
    if (localDW->obj_i.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_i.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read8' */

    /* MATLABSystem: '<S576>/I2C Read9' */
    if (localDW->obj.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read9' */

    /* MATLABSystem: '<S576>/I2C Read10' */
    if (localDW->obj_d0.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_d0.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read10' */

    /* MATLABSystem: '<S576>/I2C Read11' */
    if (localDW->obj_l.SampleTime != Copy_4_of_laod_arduino_2021_P.t_AP) {
      localDW->obj_l.SampleTime = Copy_4_of_laod_arduino_2021_P.t_AP;
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
      /* MATLABSystem: '<S576>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S576>/I2C Read11' */

    /* MATLABSystem: '<S576>/I2C Write1' incorporates:
     *  Constant: '<S576>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S576>/I2C Write2' incorporates:
     *  Constant: '<S576>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_in.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S576>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_d01.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S576>/I2C Read12' */
    if (localDW->obj_ir.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_ir.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S576>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S576>/Byte Unpack' */

    /* Unpack: <S576>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S569>/One_time_initialization' */
}

/* Termination for enable system: '<S569>/One_time_initialization' */
void One_time_initializatio_Term(DW_One_time_initialization_Co_T *localDW)
{
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S576>/I2C Read' */
  obj = &localDW->obj_kf;
  if (!localDW->obj_kf.matlabCodegenIsDeleted) {
    localDW->obj_kf.matlabCodegenIsDeleted = true;
    if ((localDW->obj_kf.isInitialized == 1) && localDW->obj_kf.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read1' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read2' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read3' */
  obj = &localDW->obj_k4;
  if (!localDW->obj_k4.matlabCodegenIsDeleted) {
    localDW->obj_k4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k4.isInitialized == 1) && localDW->obj_k4.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read4' */
  obj = &localDW->obj_co;
  if (!localDW->obj_co.matlabCodegenIsDeleted) {
    localDW->obj_co.matlabCodegenIsDeleted = true;
    if ((localDW->obj_co.isInitialized == 1) && localDW->obj_co.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read5' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read6' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read7' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read8' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read10' */
  obj = &localDW->obj_d0;
  if (!localDW->obj_d0.matlabCodegenIsDeleted) {
    localDW->obj_d0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d0.isInitialized == 1) && localDW->obj_d0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read11' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S576>/I2C Write1' */
  obj_0 = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S576>/I2C Write2' */
  obj_0 = &localDW->obj_in;
  if (!localDW->obj_in.matlabCodegenIsDeleted) {
    localDW->obj_in.matlabCodegenIsDeleted = true;
    if ((localDW->obj_in.isInitialized == 1) && localDW->obj_in.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S576>/I2C Write3' */
  obj_0 = &localDW->obj_d01;
  if (!localDW->obj_d01.matlabCodegenIsDeleted) {
    localDW->obj_d01.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d01.isInitialized == 1) &&
        localDW->obj_d01.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S576>/I2C Read12' */
  obj = &localDW->obj_ir;
  if (!localDW->obj_ir.matlabCodegenIsDeleted) {
    localDW->obj_ir.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ir.isInitialized == 1) && localDW->obj_ir.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S576>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void Copy_4_of_laod_arduino_find_254(const uint8_T pack[100], real_T
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
static boolean_T Copy_4_of_laod_ardu_ifWhileCond(const boolean_T x[100])
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
static void Copy_4_of_laod_arduino_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 5.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_arduin_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_arduino_20_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 2.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_ar_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 4.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_a_IN_AutoLanding;
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
static void Copy_4_of_laod_arduino_2021_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 1.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_ardu_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 2.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_ar_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 5.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_arduin_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 4.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_a_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Copy_4_of_laod_arduino_2021_B.modo == 3.0)) {
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_a_IN_AutoTakeoff;
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_arduino_eml_find(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2])
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_ar_ifWhileCond_o(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_ardui_eml_find_o(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2])
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_ar_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_ardui_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_ard_copyexponent(char_T s1[4], int32_T *idx,
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

      Copy_4_of_laod_arduino_2021_B.kexp_f = *k;
      b_k = *k;
      b_success = Copy_4_of_laod_ardui_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > Copy_4_of_laod_arduino_2021_B.kexp_f));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_arduin_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
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
            Copy_4_of_laod_arduin_readfloat(s1, idx, s, k, false, &isneg,
              b_finite, nfv, &unusedU2, success);
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
      Copy_4_of_laod_ar_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Copy_4_of_laod_ardui_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = Copy_4_of_laod_ard_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static creal_T Copy_4_of_laod_ardui_str2double(const char_T s[2])
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
  Copy_4_of_laod_arduino_2021_B.ntoread_j = 0;
  Copy_4_of_laod_arduino_2021_B.k_e = 0;
  while ((Copy_4_of_laod_arduino_2021_B.k_e + 1 <= 2) && (c[(uint8_T)
          s[Copy_4_of_laod_arduino_2021_B.k_e] & 127] ||
          (s[Copy_4_of_laod_arduino_2021_B.k_e] == '\x00'))) {
    Copy_4_of_laod_arduino_2021_B.k_e++;
  }

  isimag1 = false;
  b_finite = true;
  Copy_4_of_laod_arduino_2021_B.scanned1_dh = 0.0;
  Copy_4_of_laod_arduino_2021_B.idx_bj = 1;
  Copy_4_of_laod_arduino_2021_B.s1_l[0] = '\x00';
  Copy_4_of_laod_arduino_2021_B.s1_l[1] = '\x00';
  Copy_4_of_laod_arduino_2021_B.s1_l[2] = '\x00';
  Copy_4_of_laod_arduino_2021_B.s1_l[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.k_e + 1 <= 2)) {
    if (s[Copy_4_of_laod_arduino_2021_B.k_e] == '-') {
      isneg = !isneg;
      Copy_4_of_laod_arduino_2021_B.k_e++;
    } else if ((s[Copy_4_of_laod_arduino_2021_B.k_e] == ',') ||
               (s[Copy_4_of_laod_arduino_2021_B.k_e] == '+') || c[(uint8_T)
               s[Copy_4_of_laod_arduino_2021_B.k_e] & 127]) {
      Copy_4_of_laod_arduino_2021_B.k_e++;
    } else {
      exitg1 = true;
    }
  }

  success = (Copy_4_of_laod_arduino_2021_B.k_e + 1 <= 2);
  if (success && isneg) {
    Copy_4_of_laod_arduino_2021_B.s1_l[0] = '-';
    Copy_4_of_laod_arduino_2021_B.idx_bj = 2;
  }

  Copy_4_of_laod_arduino_2021_B.e_k = Copy_4_of_laod_arduino_2021_B.k_e + 1;
  if (success) {
    if ((Copy_4_of_laod_arduino_2021_B.k_e + 1 <= 2) &&
        ((s[Copy_4_of_laod_arduino_2021_B.k_e] == 'j') ||
         (s[Copy_4_of_laod_arduino_2021_B.k_e] == 'i'))) {
      isimag1 = true;
      Copy_4_of_laod_arduino_2021_B.e_k = Copy_4_of_laod_arduino_2021_B.k_e + 2;
      while ((Copy_4_of_laod_arduino_2021_B.e_k <= 2) && (c[(uint8_T)s[1] & 127]
              || (s[1] == '\x00') || (s[1] == ','))) {
        Copy_4_of_laod_arduino_2021_B.e_k = 3;
      }

      if ((Copy_4_of_laod_arduino_2021_B.e_k <= 2) && (s[1] == '*')) {
        Copy_4_of_laod_arduino_2021_B.e_k = 3;
        Copy_4_of_laod_arduin_readfloat(Copy_4_of_laod_arduino_2021_B.s1_l,
          &Copy_4_of_laod_arduino_2021_B.idx_bj, s,
          &Copy_4_of_laod_arduino_2021_B.e_k, false, &isneg, &b_finite,
          &Copy_4_of_laod_arduino_2021_B.scanned1_dh, &unusedU2, &success);
      } else {
        Copy_4_of_laod_arduino_2021_B.s1_l[Copy_4_of_laod_arduino_2021_B.idx_bj
          - 1] = '1';
        Copy_4_of_laod_arduino_2021_B.idx_bj++;
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.e_k = Copy_4_of_laod_arduino_2021_B.k_e + 1;
      Copy_4_of_laod_ar_readNonFinite(s, &Copy_4_of_laod_arduino_2021_B.e_k,
        &b_finite, &Copy_4_of_laod_arduino_2021_B.scanned1_dh);
      if (b_finite) {
        success = Copy_4_of_laod_ardui_copydigits
          (Copy_4_of_laod_arduino_2021_B.s1_l,
           &Copy_4_of_laod_arduino_2021_B.idx_bj, s,
           &Copy_4_of_laod_arduino_2021_B.e_k, true);
        if (success) {
          success = Copy_4_of_laod_ard_copyexponent
            (Copy_4_of_laod_arduino_2021_B.s1_l,
             &Copy_4_of_laod_arduino_2021_B.idx_bj, s,
             &Copy_4_of_laod_arduino_2021_B.e_k);
        }
      } else {
        if ((Copy_4_of_laod_arduino_2021_B.idx_bj >= 2) &&
            (Copy_4_of_laod_arduino_2021_B.s1_l[0] == '-')) {
          Copy_4_of_laod_arduino_2021_B.idx_bj = 1;
          Copy_4_of_laod_arduino_2021_B.s1_l[0] = ' ';
          Copy_4_of_laod_arduino_2021_B.scanned1_dh =
            -Copy_4_of_laod_arduino_2021_B.scanned1_dh;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.e_k <= 2)) {
        tmp = s[Copy_4_of_laod_arduino_2021_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          Copy_4_of_laod_arduino_2021_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((Copy_4_of_laod_arduino_2021_B.e_k <= 2) &&
          (s[Copy_4_of_laod_arduino_2021_B.e_k - 1] == '*')) {
        Copy_4_of_laod_arduino_2021_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.e_k <= 2)) {
          tmp = s[Copy_4_of_laod_arduino_2021_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            Copy_4_of_laod_arduino_2021_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (Copy_4_of_laod_arduino_2021_B.e_k <= 2) {
        tmp = s[Copy_4_of_laod_arduino_2021_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          Copy_4_of_laod_arduino_2021_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.e_k <= 2)) {
      tmp = s[Copy_4_of_laod_arduino_2021_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        Copy_4_of_laod_arduino_2021_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    Copy_4_of_laod_arduino_2021_B.ntoread_j = 1;
  }

  if (success && (Copy_4_of_laod_arduino_2021_B.e_k <= 2)) {
    Copy_4_of_laod_arduino_2021_B.s1_l[Copy_4_of_laod_arduino_2021_B.idx_bj - 1]
      = ' ';
    Copy_4_of_laod_arduino_2021_B.idx_bj++;
    Copy_4_of_laod_arduin_readfloat(Copy_4_of_laod_arduino_2021_B.s1_l,
      &Copy_4_of_laod_arduino_2021_B.idx_bj, s,
      &Copy_4_of_laod_arduino_2021_B.e_k, true, &success, &isneg,
      &Copy_4_of_laod_arduino_2021_B.scanned2_d, &unusedU2, &c_success);
    if (isneg) {
      Copy_4_of_laod_arduino_2021_B.ntoread_j++;
    }

    success = (c_success && (Copy_4_of_laod_arduino_2021_B.e_k > 2) && (isimag1
                != success) && unusedU2);
  } else {
    Copy_4_of_laod_arduino_2021_B.scanned2_d = 0.0;
  }

  if (success) {
    Copy_4_of_laod_arduino_2021_B.s1_l[Copy_4_of_laod_arduino_2021_B.idx_bj - 1]
      = '\x00';
    switch (Copy_4_of_laod_arduino_2021_B.ntoread_j) {
     case 2:
      Copy_4_of_laod_arduino_2021_B.ntoread_j = sscanf
        (&Copy_4_of_laod_arduino_2021_B.s1_l[0], "%lf %lf",
         &Copy_4_of_laod_arduino_2021_B.scanned1_dh,
         &Copy_4_of_laod_arduino_2021_B.scanned2_d);
      if (Copy_4_of_laod_arduino_2021_B.ntoread_j != 2) {
        Copy_4_of_laod_arduino_2021_B.scanned1_dh = (rtNaN);
        Copy_4_of_laod_arduino_2021_B.scanned2_d = (rtNaN);
      }
      break;

     case 1:
      Copy_4_of_laod_arduino_2021_B.ntoread_j = sscanf
        (&Copy_4_of_laod_arduino_2021_B.s1_l[0], "%lf",
         &Copy_4_of_laod_arduino_2021_B.b_scanned1_lx);
      if (b_finite) {
        if (Copy_4_of_laod_arduino_2021_B.ntoread_j == 1) {
          Copy_4_of_laod_arduino_2021_B.scanned1_dh =
            Copy_4_of_laod_arduino_2021_B.b_scanned1_lx;
        } else {
          Copy_4_of_laod_arduino_2021_B.scanned1_dh = (rtNaN);
        }
      } else if (Copy_4_of_laod_arduino_2021_B.ntoread_j == 1) {
        Copy_4_of_laod_arduino_2021_B.scanned2_d =
          Copy_4_of_laod_arduino_2021_B.b_scanned1_lx;
      } else {
        Copy_4_of_laod_arduino_2021_B.scanned2_d = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = Copy_4_of_laod_arduino_2021_B.scanned2_d;
      x.im = Copy_4_of_laod_arduino_2021_B.scanned1_dh;
    } else {
      x.re = Copy_4_of_laod_arduino_2021_B.scanned1_dh;
      x.im = Copy_4_of_laod_arduino_2021_B.scanned2_d;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_ard_copydigits_k(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_ardu_readfloat_d(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success)
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
          Copy_4_of_laod_ardu_readfloat_d(s1_data, idx, s_data, k, n, false,
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
        *success = Copy_4_of_laod_ard_copydigits_k(s1_data, &b_idx, s_data, &h_k,
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
              isneg = Copy_4_of_laod_ard_copydigits_k(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static creal_T Copy_4_of_laod_ard_str2double_l(const char_T s_data[], const
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
    Copy_4_of_laod_arduino_2021_B.ntoread = 0;
    Copy_4_of_laod_arduino_2021_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.k <= s_size[1])) {
      tmp = s_data[Copy_4_of_laod_arduino_2021_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        Copy_4_of_laod_arduino_2021_B.k++;
      } else {
        exitg1 = true;
      }
    }

    Copy_4_of_laod_arduino_2021_B.s1_size[0] = 1;
    Copy_4_of_laod_arduino_2021_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    Copy_4_of_laod_arduino_2021_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= Copy_4_of_laod_arduino_2021_B.idx) {
      memset(&Copy_4_of_laod_arduino_2021_B.s1_data[0], 0,
             (Copy_4_of_laod_arduino_2021_B.idx + 1) * sizeof(char_T));
    }

    Copy_4_of_laod_arduino_2021_B.idx = 1;
    Copy_4_of_laod_ardu_readfloat_d(Copy_4_of_laod_arduino_2021_B.s1_data,
      &Copy_4_of_laod_arduino_2021_B.idx, s_data,
      &Copy_4_of_laod_arduino_2021_B.k, s_size[1], true, &isimag1, &isfinite1,
      &Copy_4_of_laod_arduino_2021_B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      Copy_4_of_laod_arduino_2021_B.ntoread = 1;
    }

    if (success) {
      if (Copy_4_of_laod_arduino_2021_B.k <= s_size[1]) {
        Copy_4_of_laod_arduino_2021_B.s1_data[Copy_4_of_laod_arduino_2021_B.idx
          - 1] = ' ';
        Copy_4_of_laod_arduino_2021_B.idx++;
        Copy_4_of_laod_ardu_readfloat_d(Copy_4_of_laod_arduino_2021_B.s1_data,
          &Copy_4_of_laod_arduino_2021_B.idx, s_data,
          &Copy_4_of_laod_arduino_2021_B.k, s_size[1], true, &unusedU0, &success,
          &Copy_4_of_laod_arduino_2021_B.scanned2, &foundsign, &c_success);
        if (success) {
          Copy_4_of_laod_arduino_2021_B.ntoread++;
        }

        success = (c_success && ((Copy_4_of_laod_arduino_2021_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        Copy_4_of_laod_arduino_2021_B.scanned2 = 0.0;
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.scanned2 = 0.0;
    }

    if (success) {
      Copy_4_of_laod_arduino_2021_B.s1_data[Copy_4_of_laod_arduino_2021_B.idx -
        1] = '\x00';
      switch (Copy_4_of_laod_arduino_2021_B.ntoread) {
       case 2:
        Copy_4_of_laod_arduino_2021_B.ntoread = sscanf
          (&Copy_4_of_laod_arduino_2021_B.s1_data[0], "%lf %lf",
           &Copy_4_of_laod_arduino_2021_B.scanned1,
           &Copy_4_of_laod_arduino_2021_B.scanned2);
        if (Copy_4_of_laod_arduino_2021_B.ntoread != 2) {
          Copy_4_of_laod_arduino_2021_B.scanned1 = (rtNaN);
          Copy_4_of_laod_arduino_2021_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        Copy_4_of_laod_arduino_2021_B.ntoread = sscanf
          (&Copy_4_of_laod_arduino_2021_B.s1_data[0], "%lf",
           &Copy_4_of_laod_arduino_2021_B.b_scanned1);
        if (isfinite1) {
          if (Copy_4_of_laod_arduino_2021_B.ntoread == 1) {
            Copy_4_of_laod_arduino_2021_B.scanned1 =
              Copy_4_of_laod_arduino_2021_B.b_scanned1;
          } else {
            Copy_4_of_laod_arduino_2021_B.scanned1 = (rtNaN);
          }
        } else if (Copy_4_of_laod_arduino_2021_B.ntoread == 1) {
          Copy_4_of_laod_arduino_2021_B.scanned2 =
            Copy_4_of_laod_arduino_2021_B.b_scanned1;
        } else {
          Copy_4_of_laod_arduino_2021_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = Copy_4_of_laod_arduino_2021_B.scanned2;
        x.im = Copy_4_of_laod_arduino_2021_B.scanned1;
      } else {
        x.re = Copy_4_of_laod_arduino_2021_B.scanned1;
        x.im = Copy_4_of_laod_arduino_2021_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_ardui_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod__readNonFinite_l(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_ar_copydigits_k3(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_a_copyexponent_k(char_T s1[5], int32_T *idx,
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

      Copy_4_of_laod_arduino_2021_B.kexp = *k;
      b_k = *k;
      b_success = Copy_4_of_laod_ar_copydigits_k3(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > Copy_4_of_laod_arduino_2021_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_ard_readfloat_dt(char_T s1[5], int32_T *idx, const
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
    if (Copy_4_of_laod_ardui_isUnitImag(s, b_k)) {
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
          Copy_4_of_laod_ard_readfloat_dt(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      Copy_4_of_laod__readNonFinite_l(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Copy_4_of_laod_ar_copydigits_k3(s1, idx, s, k, true);
        if (*success) {
          *success = Copy_4_of_laod_a_copyexponent_k(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static creal_T Copy_4_of_laod_ar_str2double_lv(const char_T s[3])
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
  Copy_4_of_laod_arduino_2021_B.ntoread_d = 0;
  Copy_4_of_laod_arduino_2021_B.k_h = 1;
  exitg1 = false;
  while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.k_h <= 3)) {
    tmp = s[Copy_4_of_laod_arduino_2021_B.k_h - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      Copy_4_of_laod_arduino_2021_B.k_h++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  Copy_4_of_laod_arduino_2021_B.scanned1_d = 0.0;
  Copy_4_of_laod_arduino_2021_B.idx_b = 1;
  for (Copy_4_of_laod_arduino_2021_B.b_k = 0; Copy_4_of_laod_arduino_2021_B.b_k <
       5; Copy_4_of_laod_arduino_2021_B.b_k++) {
    Copy_4_of_laod_arduino_2021_B.s1[Copy_4_of_laod_arduino_2021_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.k_h <= 3)) {
    tmp = s[Copy_4_of_laod_arduino_2021_B.k_h - 1];
    if (tmp == '-') {
      isneg = !isneg;
      Copy_4_of_laod_arduino_2021_B.k_h++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      Copy_4_of_laod_arduino_2021_B.k_h++;
    } else {
      exitg1 = true;
    }
  }

  success = (Copy_4_of_laod_arduino_2021_B.k_h <= 3);
  if (success && isneg) {
    Copy_4_of_laod_arduino_2021_B.s1[0] = '-';
    Copy_4_of_laod_arduino_2021_B.idx_b = 2;
  }

  Copy_4_of_laod_arduino_2021_B.b_k = Copy_4_of_laod_arduino_2021_B.k_h - 1;
  if (success) {
    if (Copy_4_of_laod_ardui_isUnitImag(s, Copy_4_of_laod_arduino_2021_B.k_h)) {
      isimag1 = true;
      Copy_4_of_laod_arduino_2021_B.b_k = Copy_4_of_laod_arduino_2021_B.k_h;
      while ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[Copy_4_of_laod_arduino_2021_B.b_k] & 127] ||
              (s[Copy_4_of_laod_arduino_2021_B.b_k] == '\x00') ||
              (s[Copy_4_of_laod_arduino_2021_B.b_k] == ','))) {
        Copy_4_of_laod_arduino_2021_B.b_k++;
      }

      if ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) &&
          (s[Copy_4_of_laod_arduino_2021_B.b_k] == '*')) {
        Copy_4_of_laod_arduino_2021_B.k_h = Copy_4_of_laod_arduino_2021_B.b_k +
          2;
        Copy_4_of_laod_ard_readfloat_dt(Copy_4_of_laod_arduino_2021_B.s1,
          &Copy_4_of_laod_arduino_2021_B.idx_b, s,
          &Copy_4_of_laod_arduino_2021_B.k_h, false, &isneg, &b_finite,
          &Copy_4_of_laod_arduino_2021_B.scanned1_d, &unusedU2, &success);
        Copy_4_of_laod_arduino_2021_B.b_k = Copy_4_of_laod_arduino_2021_B.k_h -
          1;
      } else {
        Copy_4_of_laod_arduino_2021_B.s1[Copy_4_of_laod_arduino_2021_B.idx_b - 1]
          = '1';
        Copy_4_of_laod_arduino_2021_B.idx_b++;
      }
    } else {
      Copy_4_of_laod__readNonFinite_l(s, &Copy_4_of_laod_arduino_2021_B.k_h,
        &b_finite, &Copy_4_of_laod_arduino_2021_B.scanned1_d);
      Copy_4_of_laod_arduino_2021_B.b_k = Copy_4_of_laod_arduino_2021_B.k_h - 1;
      if (b_finite) {
        success = Copy_4_of_laod_ar_copydigits_k3
          (Copy_4_of_laod_arduino_2021_B.s1,
           &Copy_4_of_laod_arduino_2021_B.idx_b, s,
           &Copy_4_of_laod_arduino_2021_B.k_h, true);
        Copy_4_of_laod_arduino_2021_B.b_k = Copy_4_of_laod_arduino_2021_B.k_h -
          1;
        if (success) {
          success = Copy_4_of_laod_a_copyexponent_k
            (Copy_4_of_laod_arduino_2021_B.s1,
             &Copy_4_of_laod_arduino_2021_B.idx_b, s,
             &Copy_4_of_laod_arduino_2021_B.k_h);
          Copy_4_of_laod_arduino_2021_B.b_k = Copy_4_of_laod_arduino_2021_B.k_h
            - 1;
        }
      } else {
        if ((Copy_4_of_laod_arduino_2021_B.idx_b >= 2) &&
            (Copy_4_of_laod_arduino_2021_B.s1[0] == '-')) {
          Copy_4_of_laod_arduino_2021_B.idx_b = 1;
          Copy_4_of_laod_arduino_2021_B.s1[0] = ' ';
          Copy_4_of_laod_arduino_2021_B.scanned1_d =
            -Copy_4_of_laod_arduino_2021_B.scanned1_d;
        }
      }

      while ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[Copy_4_of_laod_arduino_2021_B.b_k] & 127] ||
              (s[Copy_4_of_laod_arduino_2021_B.b_k] == '\x00') ||
              (s[Copy_4_of_laod_arduino_2021_B.b_k] == ','))) {
        Copy_4_of_laod_arduino_2021_B.b_k++;
      }

      if ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) &&
          (s[Copy_4_of_laod_arduino_2021_B.b_k] == '*')) {
        Copy_4_of_laod_arduino_2021_B.b_k++;
        while ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[Copy_4_of_laod_arduino_2021_B.b_k] & 127] ||
                (s[Copy_4_of_laod_arduino_2021_B.b_k] == '\x00') ||
                (s[Copy_4_of_laod_arduino_2021_B.b_k] == ','))) {
          Copy_4_of_laod_arduino_2021_B.b_k++;
        }
      }

      if ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) &&
          ((s[Copy_4_of_laod_arduino_2021_B.b_k] == 'i') ||
           (s[Copy_4_of_laod_arduino_2021_B.b_k] == 'j'))) {
        Copy_4_of_laod_arduino_2021_B.b_k++;
        isimag1 = true;
      }
    }

    while ((Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[Copy_4_of_laod_arduino_2021_B.b_k] & 127] ||
            (s[Copy_4_of_laod_arduino_2021_B.b_k] == '\x00') ||
            (s[Copy_4_of_laod_arduino_2021_B.b_k] == ','))) {
      Copy_4_of_laod_arduino_2021_B.b_k++;
    }
  }

  if (b_finite) {
    Copy_4_of_laod_arduino_2021_B.ntoread_d = 1;
  }

  if (success && (Copy_4_of_laod_arduino_2021_B.b_k + 1 <= 3)) {
    Copy_4_of_laod_arduino_2021_B.s1[Copy_4_of_laod_arduino_2021_B.idx_b - 1] =
      ' ';
    Copy_4_of_laod_arduino_2021_B.idx_b++;
    Copy_4_of_laod_arduino_2021_B.k_h = Copy_4_of_laod_arduino_2021_B.b_k + 1;
    Copy_4_of_laod_ard_readfloat_dt(Copy_4_of_laod_arduino_2021_B.s1,
      &Copy_4_of_laod_arduino_2021_B.idx_b, s,
      &Copy_4_of_laod_arduino_2021_B.k_h, true, &success, &isneg,
      &Copy_4_of_laod_arduino_2021_B.scanned2_g, &unusedU2, &c_success);
    if (isneg) {
      Copy_4_of_laod_arduino_2021_B.ntoread_d++;
    }

    success = (c_success && (Copy_4_of_laod_arduino_2021_B.k_h > 3) && (isimag1
                != success) && unusedU2);
  } else {
    Copy_4_of_laod_arduino_2021_B.scanned2_g = 0.0;
  }

  if (success) {
    Copy_4_of_laod_arduino_2021_B.s1[Copy_4_of_laod_arduino_2021_B.idx_b - 1] =
      '\x00';
    switch (Copy_4_of_laod_arduino_2021_B.ntoread_d) {
     case 2:
      Copy_4_of_laod_arduino_2021_B.ntoread_d = sscanf
        (&Copy_4_of_laod_arduino_2021_B.s1[0], "%lf %lf",
         &Copy_4_of_laod_arduino_2021_B.scanned1_d,
         &Copy_4_of_laod_arduino_2021_B.scanned2_g);
      if (Copy_4_of_laod_arduino_2021_B.ntoread_d != 2) {
        Copy_4_of_laod_arduino_2021_B.scanned1_d = (rtNaN);
        Copy_4_of_laod_arduino_2021_B.scanned2_g = (rtNaN);
      }
      break;

     case 1:
      Copy_4_of_laod_arduino_2021_B.ntoread_d = sscanf
        (&Copy_4_of_laod_arduino_2021_B.s1[0], "%lf",
         &Copy_4_of_laod_arduino_2021_B.b_scanned1_l);
      if (b_finite) {
        if (Copy_4_of_laod_arduino_2021_B.ntoread_d == 1) {
          Copy_4_of_laod_arduino_2021_B.scanned1_d =
            Copy_4_of_laod_arduino_2021_B.b_scanned1_l;
        } else {
          Copy_4_of_laod_arduino_2021_B.scanned1_d = (rtNaN);
        }
      } else if (Copy_4_of_laod_arduino_2021_B.ntoread_d == 1) {
        Copy_4_of_laod_arduino_2021_B.scanned2_g =
          Copy_4_of_laod_arduino_2021_B.b_scanned1_l;
      } else {
        Copy_4_of_laod_arduino_2021_B.scanned2_g = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = Copy_4_of_laod_arduino_2021_B.scanned2_g;
      x.im = Copy_4_of_laod_arduino_2021_B.scanned1_d;
    } else {
      x.re = Copy_4_of_laod_arduino_2021_B.scanned1_d;
      x.im = Copy_4_of_laod_arduino_2021_B.scanned2_g;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_readNonFinite_ln(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod_a_copydigits_k3z(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Copy_4_of_laod__copyexponent_kd(char_T s1[3], int32_T *idx,
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
    b_success = Copy_4_of_laod_a_copydigits_k3z(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Copy_4_of_laod_ar_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
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
          Copy_4_of_laod_ar_readfloat_dtp(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      Copy_4_of_laod_readNonFinite_ln(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = Copy_4_of_laod_a_copydigits_k3z(s1, idx, s, k, true);
        if (*success) {
          *success = Copy_4_of_laod__copyexponent_kd(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static creal_T Copy_4_of_laod_a_str2double_lvk(char_T s)
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
  Copy_4_of_laod_arduino_2021_B.ntoread_ju = 0;
  Copy_4_of_laod_arduino_2021_B.d_k = 1;
  Copy_4_of_laod_arduino_2021_B.i_j = (uint8_T)s & 127;
  if (c[Copy_4_of_laod_arduino_2021_B.i_j] || (s == '\x00')) {
    Copy_4_of_laod_arduino_2021_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  Copy_4_of_laod_arduino_2021_B.scanned1_o = 0.0;
  Copy_4_of_laod_arduino_2021_B.idx_a = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      Copy_4_of_laod_arduino_2021_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[Copy_4_of_laod_arduino_2021_B.i_j])
    {
      Copy_4_of_laod_arduino_2021_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (Copy_4_of_laod_arduino_2021_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    Copy_4_of_laod_arduino_2021_B.idx_a = 2;
  }

  if (success) {
    isneg = false;
    if (Copy_4_of_laod_arduino_2021_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      Copy_4_of_laod_arduino_2021_B.d_k++;
      s1[Copy_4_of_laod_arduino_2021_B.idx_a - 1] = '1';
      Copy_4_of_laod_arduino_2021_B.idx_a++;
    } else {
      Copy_4_of_laod_readNonFinite_ln(s, &Copy_4_of_laod_arduino_2021_B.d_k,
        &b_finite, &Copy_4_of_laod_arduino_2021_B.scanned1_o);
      if (b_finite) {
        success = Copy_4_of_laod_a_copydigits_k3z(s1,
          &Copy_4_of_laod_arduino_2021_B.idx_a, s,
          &Copy_4_of_laod_arduino_2021_B.d_k, true);
        if (success) {
          success = Copy_4_of_laod__copyexponent_kd(s1,
            &Copy_4_of_laod_arduino_2021_B.idx_a, s,
            &Copy_4_of_laod_arduino_2021_B.d_k);
        }
      } else {
        if ((Copy_4_of_laod_arduino_2021_B.idx_a >= 2) && (s1[0] == '-')) {
          Copy_4_of_laod_arduino_2021_B.idx_a = 1;
          s1[0] = ' ';
          Copy_4_of_laod_arduino_2021_B.scanned1_o =
            -Copy_4_of_laod_arduino_2021_B.scanned1_o;
        }
      }

      while ((Copy_4_of_laod_arduino_2021_B.d_k <= 1) &&
             (c[Copy_4_of_laod_arduino_2021_B.i_j] || ((s == '\x00') || (s ==
                ',')))) {
        Copy_4_of_laod_arduino_2021_B.d_k = 2;
      }

      if ((Copy_4_of_laod_arduino_2021_B.d_k <= 1) && (s == '*')) {
        Copy_4_of_laod_arduino_2021_B.d_k = 2;
      }

      if ((Copy_4_of_laod_arduino_2021_B.d_k <= 1) && ((s == 'i') || (s == 'j')))
      {
        Copy_4_of_laod_arduino_2021_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((Copy_4_of_laod_arduino_2021_B.d_k <= 1) &&
           (c[Copy_4_of_laod_arduino_2021_B.i_j] || ((s == '\x00') || (s == ','))))
    {
      Copy_4_of_laod_arduino_2021_B.d_k = 2;
    }
  }

  if (b_finite) {
    Copy_4_of_laod_arduino_2021_B.ntoread_ju = 1;
  }

  if (success && (Copy_4_of_laod_arduino_2021_B.d_k <= 1)) {
    s1[Copy_4_of_laod_arduino_2021_B.idx_a - 1] = ' ';
    Copy_4_of_laod_arduino_2021_B.idx_a++;
    Copy_4_of_laod_arduino_2021_B.d_k = 1;
    Copy_4_of_laod_ar_readfloat_dtp(s1, &Copy_4_of_laod_arduino_2021_B.idx_a, s,
      &Copy_4_of_laod_arduino_2021_B.d_k, true, &success, &isneg,
      &Copy_4_of_laod_arduino_2021_B.scanned2_b, &foundsign, &c_success);
    if (isneg) {
      Copy_4_of_laod_arduino_2021_B.ntoread_ju++;
    }

    success = (c_success && (Copy_4_of_laod_arduino_2021_B.d_k > 1) && (isimag1
                != success) && foundsign);
  } else {
    Copy_4_of_laod_arduino_2021_B.scanned2_b = 0.0;
  }

  if (success) {
    s1[Copy_4_of_laod_arduino_2021_B.idx_a - 1] = '\x00';
    switch (Copy_4_of_laod_arduino_2021_B.ntoread_ju) {
     case 2:
      Copy_4_of_laod_arduino_2021_B.ntoread_ju = sscanf(&s1[0], "%lf %lf",
        &Copy_4_of_laod_arduino_2021_B.scanned1_o,
        &Copy_4_of_laod_arduino_2021_B.scanned2_b);
      if (Copy_4_of_laod_arduino_2021_B.ntoread_ju != 2) {
        Copy_4_of_laod_arduino_2021_B.scanned1_o = (rtNaN);
        Copy_4_of_laod_arduino_2021_B.scanned2_b = (rtNaN);
      }
      break;

     case 1:
      Copy_4_of_laod_arduino_2021_B.ntoread_ju = sscanf(&s1[0], "%lf",
        &Copy_4_of_laod_arduino_2021_B.b_scanned1_n);
      if (b_finite) {
        if (Copy_4_of_laod_arduino_2021_B.ntoread_ju == 1) {
          Copy_4_of_laod_arduino_2021_B.scanned1_o =
            Copy_4_of_laod_arduino_2021_B.b_scanned1_n;
        } else {
          Copy_4_of_laod_arduino_2021_B.scanned1_o = (rtNaN);
        }
      } else if (Copy_4_of_laod_arduino_2021_B.ntoread_ju == 1) {
        Copy_4_of_laod_arduino_2021_B.scanned2_b =
          Copy_4_of_laod_arduino_2021_B.b_scanned1_n;
      } else {
        Copy_4_of_laod_arduino_2021_B.scanned2_b = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = Copy_4_of_laod_arduino_2021_B.scanned2_b;
      x.im = Copy_4_of_laod_arduino_2021_B.scanned1_o;
    } else {
      x.re = Copy_4_of_laod_arduino_2021_B.scanned1_o;
      x.im = Copy_4_of_laod_arduino_2021_B.scanned2_b;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static real_T Copy_4_of_laod_arduino__hex2dec(const char_T s[2])
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

  Copy_4_of_laod_arduino_2021_B.a_n = tmp_0;
  Copy_4_of_laod_arduino_2021_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &Copy_4_of_laod_arduino_2021_B.r3.chunks
                      [0U], 2);
      tmp = tmp_2;
      MultiWordSub(&Copy_4_of_laod_arduino_2021_B.r3.chunks[0U], &tmp_2.chunks
                   [0U], &Copy_4_of_laod_arduino_2021_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &Copy_4_of_laod_arduino_2021_B.r3.chunks
                      [0U], 2);
      tmp = tmp_3;
      MultiWordSub(&Copy_4_of_laod_arduino_2021_B.r3.chunks[0U], &tmp_3.chunks
                   [0U], &Copy_4_of_laod_arduino_2021_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx],
                        &Copy_4_of_laod_arduino_2021_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&Copy_4_of_laod_arduino_2021_B.r3.chunks[0U],
                     &tmp_4.chunks[0U],
                     &Copy_4_of_laod_arduino_2021_B.sk.chunks[0U], 2);
      } else {
        Copy_4_of_laod_arduino_2021_B.sk = tmp_0;
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.sk = tmp_0;
    }

    uMultiWordMul(&Copy_4_of_laod_arduino_2021_B.sk.chunks[0U], 2,
                  &Copy_4_of_laod_arduino_2021_B.p16.chunks[0U], 2,
                  &Copy_4_of_laod_arduino_2021_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&Copy_4_of_laod_arduino_2021_B.r.chunks[0U], 4,
                         &Copy_4_of_laod_arduino_2021_B.r3.chunks[0U], 2);
    MultiWordAdd(&Copy_4_of_laod_arduino_2021_B.a_n.chunks[0U],
                 &Copy_4_of_laod_arduino_2021_B.r3.chunks[0U], &tmp.chunks[0U],
                 2);
    Copy_4_of_laod_arduino_2021_B.a_n = tmp;
    uMultiWord2MultiWord(&Copy_4_of_laod_arduino_2021_B.p16.chunks[0U], 2,
                         &Copy_4_of_laod_arduino_2021_B.r2.chunks[0U], 3);
    uMultiWordShl(&Copy_4_of_laod_arduino_2021_B.r2.chunks[0U], 3, 4U,
                  &Copy_4_of_laod_arduino_2021_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&Copy_4_of_laod_arduino_2021_B.r1.chunks[0U], 3,
                         &Copy_4_of_laod_arduino_2021_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&Copy_4_of_laod_arduino_2021_B.a_n.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&Copy_4_of_laod_arduino_2021_B.a_n.chunks[0U], 2,
                              0) - uMultiWord2Double
          (&Copy_4_of_laod_arduino_2021_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&Copy_4_of_laod_arduino_2021_B.a_n.chunks[0U], 2,
                              0);
      }
    } else {
      x = uMultiWord2Double(&Copy_4_of_laod_arduino_2021_B.a_n.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&Copy_4_of_laod_arduino_2021_B.a_n.chunks[0U], 2, 0);
  }

  return x;
}

/* Model step function for TID0 */
void Copy_4_of_laod_arduino_2021_step0(void) /* Sample time: [0.02s, 0.0s] */
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

  /* S-Function (Mti): '<S571>/S-Function Builder' */
  Mti_Outputs_wrapper(&Copy_4_of_laod_arduino_2021_B.SFunctionBuilder[0],
                      &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S571>/Byte Unpack' */

  /* Unpack: <S571>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o1[0], (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder[0] +
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
      memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2[0], (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder[0] +
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
      memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3_b, (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder[0] +
             MW_inputPortOffset, MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S571>/Byte Reversal' */

  /* ReverseEndian: <S571>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2[0];
    real32_T *y0 = &Copy_4_of_laod_arduino_2021_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S569>/One_time_initialization' */
  /* Logic: '<S569>/Logical Operator1' incorporates:
   *  UnitDelay: '<S569>/Unit Delay'
   */
  Cop_One_time_initialization(!Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE_d,
    &Copy_4_of_laod_arduino_2021_B.One_time_initialization,
    &Copy_4_of_laod_arduino_2021_DW.One_time_initialization,
    &Copy_4_of_laod_arduino_2021_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S569>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S569>/Execution_loop' incorporates:
   *  EnablePort: '<S573>/Enable'
   */
  /* UnitDelay: '<S569>/Unit Delay' */
  if (Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE_d) {
    /* MATLABSystem: '<S573>/I2C Read12' */
    if (Copy_4_of_laod_arduino_2021_DW.obj_f.SampleTime !=
        Copy_4_of_laod_arduino_2021_P.t_AP) {
      Copy_4_of_laod_arduino_2021_DW.obj_f.SampleTime =
        Copy_4_of_laod_arduino_2021_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (Copy_4_of_laod_arduino_2021_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead
        (Copy_4_of_laod_arduino_2021_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S573>/I2C Read1' */
    if (Copy_4_of_laod_arduino_2021_DW.obj_p.SampleTime !=
        Copy_4_of_laod_arduino_2021_P.t_AP) {
      Copy_4_of_laod_arduino_2021_DW.obj_p.SampleTime =
        Copy_4_of_laod_arduino_2021_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (Copy_4_of_laod_arduino_2021_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead
        (Copy_4_of_laod_arduino_2021_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &Copy_4_of_laod_arduino_2021_B.output_raw[0], 3U, false, true);
      memcpy((void *)&Copy_4_of_laod_arduino_2021_B.output[0], (void *)
             &Copy_4_of_laod_arduino_2021_B.output_raw[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      Copy_4_of_laod_arduino_2021_B.output[0] = 0U;
      Copy_4_of_laod_arduino_2021_B.output[1] = 0U;
      Copy_4_of_laod_arduino_2021_B.output[2] = 0U;
    }

    /* ArithShift: '<S573>/Shift Arithmetic4' incorporates:
     *  Constant: '<S573>/Constant1'
     */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_o);
    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic3' incorporates:
     *  Constant: '<S573>/Constant5'
     */
    Copy_4_of_laod_arduino_2021_B.Sum3_o = floor
      (Copy_4_of_laod_arduino_2021_P.Constant5_Value_n);
    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.Sum3_o) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.Sum3_o)) {
      Copy_4_of_laod_arduino_2021_B.Sum3_o = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.Sum3_o = fmod
        (Copy_4_of_laod_arduino_2021_B.Sum3_o, 4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic1' incorporates:
     *  Constant: '<S573>/Constant6'
     */
    Copy_4_of_laod_arduino_2021_B.num_254 = floor
      (Copy_4_of_laod_arduino_2021_P.Constant6_Value);
    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.num_254) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.num_254)) {
      Copy_4_of_laod_arduino_2021_B.num_254 = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.num_254 = fmod
        (Copy_4_of_laod_arduino_2021_B.num_254, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S573>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S573>/Shift Arithmetic1'
     *  ArithShift: '<S573>/Shift Arithmetic3'
     *  ArithShift: '<S573>/Shift Arithmetic4'
     *  Constant: '<S573>/Constant10'
     *  Constant: '<S573>/Constant11'
     *  Constant: '<S573>/Constant7'
     *  MATLABSystem: '<S573>/I2C Read1'
     *  Sum: '<S573>/Sum1'
     *  Sum: '<S573>/Sum4'
     *  Sum: '<S573>/Sum5'
     *  Sum: '<S573>/Sum6'
     */
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_i = (int32_T)
      ((((((Copy_4_of_laod_arduino_2021_P.Constant7_Value +
            Copy_4_of_laod_arduino_2021_B.output[0]) <<
           (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? -(int32_T)
            (uint32_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)
            (uint32_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit)) +
          ((Copy_4_of_laod_arduino_2021_P.Constant10_Value +
            Copy_4_of_laod_arduino_2021_B.output[1]) <<
           (Copy_4_of_laod_arduino_2021_B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
            -Copy_4_of_laod_arduino_2021_B.Sum3_o : (int32_T)(uint32_T)
            Copy_4_of_laod_arduino_2021_B.Sum3_o))) +
         Copy_4_of_laod_arduino_2021_P.Constant11_Value) +
        Copy_4_of_laod_arduino_2021_B.output[2]) >>
       (Copy_4_of_laod_arduino_2021_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
        -Copy_4_of_laod_arduino_2021_B.num_254 : (int32_T)(uint32_T)
        Copy_4_of_laod_arduino_2021_B.num_254));

    /* ArithShift: '<S573>/Shift Arithmetic7' incorporates:
     *  Constant: '<S573>/Constant2'
     */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_P.Constant2_Value_a);
    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic6' incorporates:
     *  Constant: '<S573>/Constant3'
     */
    Copy_4_of_laod_arduino_2021_B.Sum3_o = floor
      (Copy_4_of_laod_arduino_2021_P.Constant3_Value_c0);
    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.Sum3_o) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.Sum3_o)) {
      Copy_4_of_laod_arduino_2021_B.Sum3_o = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.Sum3_o = fmod
        (Copy_4_of_laod_arduino_2021_B.Sum3_o, 4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic2' incorporates:
     *  Constant: '<S573>/Constant4'
     */
    Copy_4_of_laod_arduino_2021_B.num_254 = floor
      (Copy_4_of_laod_arduino_2021_P.Constant4_Value_l);
    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.num_254) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.num_254)) {
      Copy_4_of_laod_arduino_2021_B.num_254 = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.num_254 = fmod
        (Copy_4_of_laod_arduino_2021_B.num_254, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S573>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S573>/Shift Arithmetic2'
     *  ArithShift: '<S573>/Shift Arithmetic6'
     *  ArithShift: '<S573>/Shift Arithmetic7'
     *  Constant: '<S573>/Constant8'
     *  Constant: '<S573>/Constant9'
     *  MATLABSystem: '<S573>/I2C Read12'
     *  Sum: '<S573>/Sum'
     *  Sum: '<S573>/Sum2'
     *  Sum: '<S573>/Sum3'
     */
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ay = (int32_T)
      ((((Copy_4_of_laod_arduino_2021_P.Constant8_Value_e + rtb_H_mav[0]) <<
         (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? -(int32_T)
          (uint32_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)
          (uint32_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit)) +
        ((Copy_4_of_laod_arduino_2021_P.Constant9_Value + rtb_H_mav[1]) <<
         (Copy_4_of_laod_arduino_2021_B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
          -Copy_4_of_laod_arduino_2021_B.Sum3_o : (int32_T)(uint32_T)
          Copy_4_of_laod_arduino_2021_B.Sum3_o))) >>
       (Copy_4_of_laod_arduino_2021_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
        -Copy_4_of_laod_arduino_2021_B.num_254 : (int32_T)(uint32_T)
        Copy_4_of_laod_arduino_2021_B.num_254));

    /* S-Function (calc_T): '<S573>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead1,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead2,
       &Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ay,
       &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1,
       &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S573>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead3,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead4,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead5,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead6,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead7,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead8,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead9,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead10,
       &Copy_4_of_laod_arduino_2021_B.One_time_initialization.I2CRead11,
       &Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_i,
       &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2_a,
       &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S569>/Execution_loop' */

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&Copy_4_of_laod_arduino_2021_P.Constant1_Value_a,
    &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[0],
    &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2,
    &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE_l);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  Copy_4_of_laod_arduino_2021_B.AL = 0;
  Copy_4_of_laod_arduino_2021_B.caso = 0;
  memset(&Copy_4_of_laod_arduino_2021_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
  memset(&Copy_4_of_laod_arduino_2021_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  Copy_4_of_laod_arduino_find_254
    (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h,
     Copy_4_of_laod_arduino_2021_B.lat_end,
     &Copy_4_of_laod_arduino_2021_B.num_254);
  if (Copy_4_of_laod_arduino_2021_DW.Interr_parz &&
      (Copy_4_of_laod_arduino_2021_B.num_254 == 1.0)) {
    Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
      (Copy_4_of_laod_arduino_2021_DW.counter_a + 1U);
    if (Copy_4_of_laod_arduino_2021_DW.counter_a + 1U > 255U) {
      Copy_4_of_laod_arduino_2021_B.ATO = 255;
    }

    if (Copy_4_of_laod_arduino_2021_B.lat_end[0] !=
        Copy_4_of_laod_arduino_2021_B.ATO) {
      Copy_4_of_laod_arduino_2021_B.num_254 = 0.0;
    }
  }

  Ap_sel = !Copy_4_of_laod_arduino_2021_DW.Interr_parz;
  if ((Copy_4_of_laod_arduino_2021_B.num_254 == 1.0) && Ap_sel) {
    Copy_4_of_laod_arduino_2021_B.caso = 1;
  } else if ((Copy_4_of_laod_arduino_2021_B.num_254 == 0.0) &&
             Copy_4_of_laod_arduino_2021_DW.Interr_parz) {
    Copy_4_of_laod_arduino_2021_B.caso = 2;
  } else if ((Copy_4_of_laod_arduino_2021_B.num_254 == 1.0) &&
             Copy_4_of_laod_arduino_2021_DW.Interr_parz) {
    Copy_4_of_laod_arduino_2021_B.caso = 3;
  } else {
    if ((Copy_4_of_laod_arduino_2021_B.num_254 == 2.0) && Ap_sel) {
      Copy_4_of_laod_arduino_2021_B.caso = 4;
    }
  }

  switch (Copy_4_of_laod_arduino_2021_B.caso) {
   case 1:
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_B.lat_end[(int32_T)
      Copy_4_of_laod_arduino_2021_B.num_254 - 1];
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 100.0) {
      Copy_4_of_laod_arduino_2021_DW.message_i[0] =
        Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[99];
      Copy_4_of_laod_arduino_2021_DW.Interr_parz = true;
    } else if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
               (Copy_4_of_laod_arduino_2021_B.deltafalllimit + 1.0) - 1] <= 100)
    {
      Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
        (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
         (Copy_4_of_laod_arduino_2021_B.lat_end[0] + 1.0) - 1] + 8U);
      Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.ATO;
      if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
        Copy_4_of_laod_arduino_2021_B.g = 255;
      }

      if (Copy_4_of_laod_arduino_2021_B.g ==
          Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2) {
        Copy_4_of_laod_arduino_2021_B.Sum3_o = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
        if (Copy_4_of_laod_arduino_2021_B.Sum3_o < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.Sum3_o >= 0.0) {
            status = (uint8_T)Copy_4_of_laod_arduino_2021_B.Sum3_o;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
          (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
           (Copy_4_of_laod_arduino_2021_B.deltafalllimit + 1.0) - 1] + 7U);
        if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
          Copy_4_of_laod_arduino_2021_B.ATO = 255;
        }

        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.deltafalllimit + (real_T)
           Copy_4_of_laod_arduino_2021_B.ATO);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
            find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          Copy_4_of_laod_arduino_2021_B.g = 0;
          Copy_4_of_laod_arduino_2021_B.i = 0;
        } else {
          Copy_4_of_laod_arduino_2021_B.g = status - 1;
          Copy_4_of_laod_arduino_2021_B.i = find_comma;
        }

        Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.i -
          Copy_4_of_laod_arduino_2021_B.g;
        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO <
             Copy_4_of_laod_arduino_2021_B.caso;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.ATO]
            =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.g
            + Copy_4_of_laod_arduino_2021_B.ATO];
        }

        Copy_4_of_laod_arduino_2021_B.AL = 1;
        for (Copy_4_of_laod_arduino_2021_B.i = 0;
             Copy_4_of_laod_arduino_2021_B.i < 100;
             Copy_4_of_laod_arduino_2021_B.i++) {
          Copy_4_of_laod_arduino_2021_B.messaggio_i[Copy_4_of_laod_arduino_2021_B.i]
            =
            Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i];
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i]
            = 0U;
        }

        Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
        Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
          Copy_4_of_laod_arduino_2021_B.ATO = 255;
        }

        if (Copy_4_of_laod_arduino_2021_B.ATO >
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2) {
          Copy_4_of_laod_arduino_2021_DW.mess_len =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2;
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >
              Copy_4_of_laod_arduino_2021_DW.mess_len) {
            Copy_4_of_laod_arduino_2021_B.g = 0;
            Copy_4_of_laod_arduino_2021_B.i = 0;
          } else {
            Copy_4_of_laod_arduino_2021_B.g = (int32_T)
              Copy_4_of_laod_arduino_2021_B.deltafalllimit - 1;
            Copy_4_of_laod_arduino_2021_B.i = (int32_T)
              Copy_4_of_laod_arduino_2021_DW.mess_len;
          }

          Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.i -
            Copy_4_of_laod_arduino_2021_B.g;
          for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
               Copy_4_of_laod_arduino_2021_B.ATO <
               Copy_4_of_laod_arduino_2021_B.caso;
               Copy_4_of_laod_arduino_2021_B.ATO++) {
            Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.ATO]
              =
              Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.g
              + Copy_4_of_laod_arduino_2021_B.ATO];
          }

          Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
            (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
             (Copy_4_of_laod_arduino_2021_B.deltafalllimit + 1.0) - 1] + 8U);
          if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
            Copy_4_of_laod_arduino_2021_B.ATO = 255;
          }

          Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf((real_T)
            Copy_4_of_laod_arduino_2021_B.ATO -
            Copy_4_of_laod_arduino_2021_DW.mess_len);
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
            if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
              Copy_4_of_laod_arduino_2021_DW.counter_a = (uint8_T)
                Copy_4_of_laod_arduino_2021_B.deltafalllimit;
            } else {
              Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
            }
          } else {
            Copy_4_of_laod_arduino_2021_DW.counter_a = MAX_uint8_T;
          }

          Copy_4_of_laod_arduino_2021_DW.Interr_parz = true;
        }
      }
    } else {
      Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
      memset(&Copy_4_of_laod_arduino_2021_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
      Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
      Copy_4_of_laod_arduino_2021_B.AL = 1;
    }
    break;

   case 2:
    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 100;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.x[Copy_4_of_laod_arduino_2021_B.ATO] =
        (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.ATO]
         != 0);
    }

    if (Copy_4_of_laod_ardu_ifWhileCond(Copy_4_of_laod_arduino_2021_B.x)) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
        (Copy_4_of_laod_arduino_2021_DW.mess_len + 1.0);
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
          find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
        (Copy_4_of_laod_arduino_2021_DW.mess_len + (real_T)
         Copy_4_of_laod_arduino_2021_DW.counter_a);
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
          status = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      if (find_comma > status) {
        Copy_4_of_laod_arduino_2021_B.AL = 1;
      } else {
        Copy_4_of_laod_arduino_2021_B.AL = find_comma;
      }

      if (1 > Copy_4_of_laod_arduino_2021_DW.counter_a) {
        Copy_4_of_laod_arduino_2021_B.caso = -1;
      } else {
        Copy_4_of_laod_arduino_2021_B.caso =
          Copy_4_of_laod_arduino_2021_DW.counter_a - 1;
      }

      for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
           Copy_4_of_laod_arduino_2021_B.ATO <=
           Copy_4_of_laod_arduino_2021_B.caso; Copy_4_of_laod_arduino_2021_B.ATO
           ++) {
        Copy_4_of_laod_arduino_2021_DW.message_i
          [(Copy_4_of_laod_arduino_2021_B.AL + Copy_4_of_laod_arduino_2021_B.ATO)
          - 1] =
          Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.ATO];
      }

      Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
      Copy_4_of_laod_arduino_2021_B.AL = 1;
      for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i <
           100; Copy_4_of_laod_arduino_2021_B.i++) {
        Copy_4_of_laod_arduino_2021_B.messaggio_i[Copy_4_of_laod_arduino_2021_B.i]
          =
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i];
        Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i]
          = 0U;
      }

      Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
      Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
    } else {
      Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
      Copy_4_of_laod_arduino_2021_B.AL = 1;
      memset(&Copy_4_of_laod_arduino_2021_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
      Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
    }
    break;

   case 3:
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
      (Copy_4_of_laod_arduino_2021_DW.mess_len + 1.0);
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
        find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
      (Copy_4_of_laod_arduino_2021_DW.mess_len + (real_T)
       Copy_4_of_laod_arduino_2021_DW.counter_a);
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
        status = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    if (find_comma > status) {
      Copy_4_of_laod_arduino_2021_B.g = 1;
    } else {
      Copy_4_of_laod_arduino_2021_B.g = find_comma;
    }

    if (1 > Copy_4_of_laod_arduino_2021_DW.counter_a) {
      Copy_4_of_laod_arduino_2021_B.caso = -1;
    } else {
      Copy_4_of_laod_arduino_2021_B.caso =
        Copy_4_of_laod_arduino_2021_DW.counter_a - 1;
    }

    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO <= Copy_4_of_laod_arduino_2021_B.caso;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_DW.message_i[(Copy_4_of_laod_arduino_2021_B.g
        + Copy_4_of_laod_arduino_2021_B.ATO) - 1] =
        Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.ATO];
    }

    Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
    Copy_4_of_laod_arduino_2021_B.AL = 1;
    for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i <
         100; Copy_4_of_laod_arduino_2021_B.i++) {
      Copy_4_of_laod_arduino_2021_B.messaggio_i[Copy_4_of_laod_arduino_2021_B.i]
        =
        Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i];
      Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i] =
        0U;
    }

    Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
    Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
    Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
      (Copy_4_of_laod_arduino_2021_B.lat_end[(int32_T)
       Copy_4_of_laod_arduino_2021_B.num_254 - 1] + 1.0) - 1;
    if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.ATO]
        <= 100) {
      Copy_4_of_laod_arduino_2021_B.g = (int32_T)
        (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
         (Copy_4_of_laod_arduino_2021_B.lat_end[0] + 1.0) - 1] + 8U);
      if ((uint32_T)Copy_4_of_laod_arduino_2021_B.g > 255U) {
        Copy_4_of_laod_arduino_2021_B.g = 255;
      }

      Copy_4_of_laod_arduino_2021_B.caso =
        Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2;
      if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2 < 0) {
        Copy_4_of_laod_arduino_2021_B.caso = 0;
      } else {
        if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2 > 255) {
          Copy_4_of_laod_arduino_2021_B.caso = 255;
        }
      }

      if (Copy_4_of_laod_arduino_2021_B.g == Copy_4_of_laod_arduino_2021_B.caso)
      {
        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.lat_end[(int32_T)
           Copy_4_of_laod_arduino_2021_B.num_254 - 1]);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
            status = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
          (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.ATO]
           + 7U);
        if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
          Copy_4_of_laod_arduino_2021_B.ATO = 255;
        }

        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.lat_end[(int32_T)
           Copy_4_of_laod_arduino_2021_B.num_254 - 1] + (real_T)
           Copy_4_of_laod_arduino_2021_B.ATO);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
            find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          Copy_4_of_laod_arduino_2021_B.g = 0;
          Copy_4_of_laod_arduino_2021_B.ATO = 0;
        } else {
          Copy_4_of_laod_arduino_2021_B.g = status - 1;
          Copy_4_of_laod_arduino_2021_B.ATO = find_comma;
        }

        Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.ATO -
          Copy_4_of_laod_arduino_2021_B.g;
        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO <
             Copy_4_of_laod_arduino_2021_B.caso;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.ATO]
            =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.g
            + Copy_4_of_laod_arduino_2021_B.ATO];
        }

        for (Copy_4_of_laod_arduino_2021_B.i = 0;
             Copy_4_of_laod_arduino_2021_B.i < 100;
             Copy_4_of_laod_arduino_2021_B.i++) {
          Copy_4_of_laod_arduino_2021_B.messaggio_2[Copy_4_of_laod_arduino_2021_B.i]
            =
            Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i];
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i]
            = 0U;
        }

        Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
        Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.g = (int32_T)
          (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
           (Copy_4_of_laod_arduino_2021_B.lat_end[0] + 1.0) - 1] + 8U);
        if ((uint32_T)Copy_4_of_laod_arduino_2021_B.g > 255U) {
          Copy_4_of_laod_arduino_2021_B.g = 255;
        }

        Copy_4_of_laod_arduino_2021_B.caso =
          Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2;
        if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2 < 0) {
          Copy_4_of_laod_arduino_2021_B.caso = 0;
        } else {
          if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2 > 255) {
            Copy_4_of_laod_arduino_2021_B.caso = 255;
          }
        }

        if (Copy_4_of_laod_arduino_2021_B.g > Copy_4_of_laod_arduino_2021_B.caso)
        {
          Copy_4_of_laod_arduino_2021_DW.mess_len =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2;
          if (Copy_4_of_laod_arduino_2021_B.lat_end[(int32_T)
              Copy_4_of_laod_arduino_2021_B.num_254 - 1] >
              Copy_4_of_laod_arduino_2021_DW.mess_len) {
            Copy_4_of_laod_arduino_2021_B.i = 0;
            Copy_4_of_laod_arduino_2021_B.caso = 0;
          } else {
            Copy_4_of_laod_arduino_2021_B.i = (int32_T)
              Copy_4_of_laod_arduino_2021_B.lat_end[(int32_T)
              Copy_4_of_laod_arduino_2021_B.num_254 - 1] - 1;
            Copy_4_of_laod_arduino_2021_B.caso = (int32_T)
              Copy_4_of_laod_arduino_2021_DW.mess_len;
          }

          Copy_4_of_laod_arduino_2021_B.caso -= Copy_4_of_laod_arduino_2021_B.i;
          for (Copy_4_of_laod_arduino_2021_B.g = 0;
               Copy_4_of_laod_arduino_2021_B.g <
               Copy_4_of_laod_arduino_2021_B.caso;
               Copy_4_of_laod_arduino_2021_B.g++) {
            Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.g]
              =
              Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.i
              + Copy_4_of_laod_arduino_2021_B.g];
          }

          Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
            (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.ATO]
             + 8U);
          if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
            Copy_4_of_laod_arduino_2021_B.ATO = 255;
          }

          Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf((real_T)
            Copy_4_of_laod_arduino_2021_B.ATO -
            Copy_4_of_laod_arduino_2021_DW.mess_len);
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
            if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
              Copy_4_of_laod_arduino_2021_DW.counter_a = (uint8_T)
                Copy_4_of_laod_arduino_2021_B.deltafalllimit;
            } else {
              Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
            }
          } else {
            Copy_4_of_laod_arduino_2021_DW.counter_a = MAX_uint8_T;
          }

          Copy_4_of_laod_arduino_2021_DW.Interr_parz = true;
        }
      }
    } else {
      Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
      memset(&Copy_4_of_laod_arduino_2021_B.messaggio_i[0], 0, 100U * sizeof
             (uint8_T));
      memset(&Copy_4_of_laod_arduino_2021_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
      Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
        (Copy_4_of_laod_arduino_2021_B.lat_end[0] + 1.0) - 1] <= 100) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
        (Copy_4_of_laod_arduino_2021_B.lat_end[0]);
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
          status = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
        (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
         (Copy_4_of_laod_arduino_2021_B.lat_end[0] + 1.0) - 1] + 7U);
      if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
        Copy_4_of_laod_arduino_2021_B.ATO = 255;
      }

      Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
        (Copy_4_of_laod_arduino_2021_B.lat_end[0] + (real_T)
         Copy_4_of_laod_arduino_2021_B.ATO);
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
          find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (status > find_comma) {
        Copy_4_of_laod_arduino_2021_B.AL = 0;
        Copy_4_of_laod_arduino_2021_B.ATO = 0;
      } else {
        Copy_4_of_laod_arduino_2021_B.AL = status - 1;
        Copy_4_of_laod_arduino_2021_B.ATO = find_comma;
      }

      Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.ATO -
        Copy_4_of_laod_arduino_2021_B.AL;
      for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
           Copy_4_of_laod_arduino_2021_B.ATO <
           Copy_4_of_laod_arduino_2021_B.caso; Copy_4_of_laod_arduino_2021_B.ATO
           ++) {
        Copy_4_of_laod_arduino_2021_B.messaggio_i[Copy_4_of_laod_arduino_2021_B.ATO]
          =
          Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.AL
          + Copy_4_of_laod_arduino_2021_B.ATO];
      }
    } else {
      Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
      memset(&Copy_4_of_laod_arduino_2021_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
    }

    Copy_4_of_laod_arduino_2021_B.AL = 1;
    if ((Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
         (Copy_4_of_laod_arduino_2021_B.lat_end[1] + 1.0) - 1] <= 100) &&
        (Copy_4_of_laod_arduino_2021_B.lat_end[1] -
         Copy_4_of_laod_arduino_2021_B.lat_end[0] > 3.0)) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf((real_T)
        Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2 -
        Copy_4_of_laod_arduino_2021_B.lat_end[1]);
      Copy_4_of_laod_arduino_2021_B.qY =
        Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[(int32_T)
        (Copy_4_of_laod_arduino_2021_B.lat_end[1] + 1.0) - 1];
      Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
        (Copy_4_of_laod_arduino_2021_B.qY + 7U);
      if (Copy_4_of_laod_arduino_2021_B.qY + 7U > 255U) {
        Copy_4_of_laod_arduino_2021_B.ATO = 255;
      }

      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 2.147483648E+9) {
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= -2.147483648E+9) {
          Copy_4_of_laod_arduino_2021_B.g = (int32_T)
            Copy_4_of_laod_arduino_2021_B.deltafalllimit;
        } else {
          Copy_4_of_laod_arduino_2021_B.g = MIN_int32_T;
        }
      } else {
        Copy_4_of_laod_arduino_2021_B.g = MAX_int32_T;
      }

      if (Copy_4_of_laod_arduino_2021_B.g == Copy_4_of_laod_arduino_2021_B.ATO)
      {
        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.lat_end[1]);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
            status = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
          (Copy_4_of_laod_arduino_2021_B.qY + 7U);
        if (Copy_4_of_laod_arduino_2021_B.qY + 7U > 255U) {
          Copy_4_of_laod_arduino_2021_B.ATO = 255;
        }

        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.lat_end[1] + (real_T)
           Copy_4_of_laod_arduino_2021_B.ATO);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
            find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          Copy_4_of_laod_arduino_2021_B.AL = 0;
          Copy_4_of_laod_arduino_2021_B.ATO = 0;
        } else {
          Copy_4_of_laod_arduino_2021_B.AL = status - 1;
          Copy_4_of_laod_arduino_2021_B.ATO = find_comma;
        }

        Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.ATO -
          Copy_4_of_laod_arduino_2021_B.AL;
        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO <
             Copy_4_of_laod_arduino_2021_B.caso;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.ATO]
            =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.AL
            + Copy_4_of_laod_arduino_2021_B.ATO];
        }

        Copy_4_of_laod_arduino_2021_B.AL = 2;
        for (Copy_4_of_laod_arduino_2021_B.i = 0;
             Copy_4_of_laod_arduino_2021_B.i < 100;
             Copy_4_of_laod_arduino_2021_B.i++) {
          Copy_4_of_laod_arduino_2021_B.messaggio_2[Copy_4_of_laod_arduino_2021_B.i]
            =
            Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i];
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.i]
            = 0U;
        }

        Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
        Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf
          (Copy_4_of_laod_arduino_2021_B.lat_end[1]);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 2.147483648E+9) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= -2.147483648E+9) {
            Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
              Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            Copy_4_of_laod_arduino_2021_B.ATO = MIN_int32_T;
          }
        } else {
          Copy_4_of_laod_arduino_2021_B.ATO = MAX_int32_T;
        }

        if (Copy_4_of_laod_arduino_2021_B.ATO >
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2) {
          Copy_4_of_laod_arduino_2021_B.ATO = -1;
          Copy_4_of_laod_arduino_2021_B.caso = 0;
        } else {
          Copy_4_of_laod_arduino_2021_B.ATO -= 2;
          Copy_4_of_laod_arduino_2021_B.caso =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2;
        }

        Copy_4_of_laod_arduino_2021_DW.mess_len = (int8_T)
          ((Copy_4_of_laod_arduino_2021_B.caso -
            Copy_4_of_laod_arduino_2021_B.ATO) - 1);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 2.147483648E+9) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= -2.147483648E+9) {
            Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
              Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            Copy_4_of_laod_arduino_2021_B.ATO = MIN_int32_T;
          }
        } else {
          Copy_4_of_laod_arduino_2021_B.ATO = MAX_int32_T;
        }

        if (Copy_4_of_laod_arduino_2021_B.ATO >
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2) {
          Copy_4_of_laod_arduino_2021_B.g = 0;
          Copy_4_of_laod_arduino_2021_B.ATO = 0;
        } else {
          Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.ATO -
            1;
          Copy_4_of_laod_arduino_2021_B.ATO =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2;
        }

        Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.ATO -
          Copy_4_of_laod_arduino_2021_B.g;
        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO <
             Copy_4_of_laod_arduino_2021_B.caso;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_DW.message_i[Copy_4_of_laod_arduino_2021_B.ATO]
            =
            Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[Copy_4_of_laod_arduino_2021_B.g
            + Copy_4_of_laod_arduino_2021_B.ATO];
        }

        Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
          (Copy_4_of_laod_arduino_2021_B.qY + 8U);
        if (Copy_4_of_laod_arduino_2021_B.qY + 8U > 255U) {
          Copy_4_of_laod_arduino_2021_B.ATO = 255;
        }

        Copy_4_of_laod_arduino_2021_B.deltafalllimit = rt_roundd_snf((real_T)
          Copy_4_of_laod_arduino_2021_B.ATO -
          Copy_4_of_laod_arduino_2021_DW.mess_len);
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 256.0) {
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >= 0.0) {
            Copy_4_of_laod_arduino_2021_DW.counter_a = (uint8_T)
              Copy_4_of_laod_arduino_2021_B.deltafalllimit;
          } else {
            Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
          }
        } else {
          Copy_4_of_laod_arduino_2021_DW.counter_a = MAX_uint8_T;
        }

        Copy_4_of_laod_arduino_2021_DW.Interr_parz = true;
      }
    } else {
      Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
      memset(&Copy_4_of_laod_arduino_2021_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
      Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&Copy_4_of_laod_arduino_2021_B.buffer[0], 0, 300U * sizeof(uint8_T));
  status = 0U;
  for (Copy_4_of_laod_arduino_2021_B.ATO = 0; Copy_4_of_laod_arduino_2021_B.ATO <
       100; Copy_4_of_laod_arduino_2021_B.ATO++) {
    Copy_4_of_laod_arduino_2021_B.buffer[3 * Copy_4_of_laod_arduino_2021_B.ATO] =
      0U;
  }

  for (Copy_4_of_laod_arduino_2021_B.ATO = 0; Copy_4_of_laod_arduino_2021_B.ATO <
       100; Copy_4_of_laod_arduino_2021_B.ATO++) {
    for (Copy_4_of_laod_arduino_2021_B.caso = 0;
         Copy_4_of_laod_arduino_2021_B.caso < 2;
         Copy_4_of_laod_arduino_2021_B.caso++) {
      Copy_4_of_laod_arduino_2021_B.g = 3 * Copy_4_of_laod_arduino_2021_B.ATO +
        Copy_4_of_laod_arduino_2021_B.caso;
      Copy_4_of_laod_arduino_2021_B.buffer[Copy_4_of_laod_arduino_2021_B.g + 1] =
        Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput_c[Copy_4_of_laod_arduino_2021_B.g];
    }
  }

  Copy_4_of_laod_arduino_2021_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.i >= 1)) {
    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 100;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.x[Copy_4_of_laod_arduino_2021_B.ATO] =
        (Copy_4_of_laod_arduino_2021_B.buffer[(3 *
          Copy_4_of_laod_arduino_2021_B.ATO + Copy_4_of_laod_arduino_2021_B.i) -
         1] == 0);
    }

    Ap_sel = true;
    Copy_4_of_laod_arduino_2021_B.ATO = 0;
    exitg2 = false;
    while ((!exitg2) && (Copy_4_of_laod_arduino_2021_B.ATO < 100)) {
      if (!Copy_4_of_laod_arduino_2021_B.x[Copy_4_of_laod_arduino_2021_B.ATO]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        Copy_4_of_laod_arduino_2021_B.ATO++;
      }
    }

    if (Ap_sel) {
      status = (uint8_T)Copy_4_of_laod_arduino_2021_B.i;
      exitg1 = true;
    } else {
      Copy_4_of_laod_arduino_2021_B.i--;
    }
  }

  if (Copy_4_of_laod_arduino_2021_B.AL == 1) {
    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 100;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.buffer[(status + 3 *
        Copy_4_of_laod_arduino_2021_B.ATO) - 1] =
        Copy_4_of_laod_arduino_2021_B.messaggio_i[Copy_4_of_laod_arduino_2021_B.ATO];
    }
  } else if (Copy_4_of_laod_arduino_2021_B.AL == 2) {
    Copy_4_of_laod_arduino_2021_B.qY = status - /*MW:OvSatOk*/ 1U;
    if (status - 1U > status) {
      Copy_4_of_laod_arduino_2021_B.qY = 0U;
    }

    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 100;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.buffer[(status + 3 *
        Copy_4_of_laod_arduino_2021_B.ATO) - 1] =
        Copy_4_of_laod_arduino_2021_B.messaggio_i[Copy_4_of_laod_arduino_2021_B.ATO];
      Copy_4_of_laod_arduino_2021_B.buffer[((int32_T)
        Copy_4_of_laod_arduino_2021_B.qY + 3 * Copy_4_of_laod_arduino_2021_B.ATO)
        - 1] =
        Copy_4_of_laod_arduino_2021_B.messaggio_2[Copy_4_of_laod_arduino_2021_B.ATO];
    }
  } else {
    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 100;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.buffer[(status + 3 *
        Copy_4_of_laod_arduino_2021_B.ATO) - 1] = 0U;
    }
  }

  for (Copy_4_of_laod_arduino_2021_B.ATO = 0; Copy_4_of_laod_arduino_2021_B.ATO <
       100; Copy_4_of_laod_arduino_2021_B.ATO++) {
    Copy_4_of_laod_arduino_2021_B.mess_out[Copy_4_of_laod_arduino_2021_B.ATO] =
      Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput_c[3 *
      Copy_4_of_laod_arduino_2021_B.ATO + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  Copy_4_of_laod_arduino_2021_B.Add =
    Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput_c[5] +
    Copy_4_of_laod_arduino_2021_P.Constant_Value_gw;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (Copy_4_of_laod_arduino_2021_B.mess_out[2] !=
      Copy_4_of_laod_arduino_2021_DW.Memory5_PreviousInput_l[2]) {
    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 100;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.x[Copy_4_of_laod_arduino_2021_B.ATO] =
        (Copy_4_of_laod_arduino_2021_B.mess_out[Copy_4_of_laod_arduino_2021_B.ATO]
         != 0);
    }

    Ap_sel = true;
    Copy_4_of_laod_arduino_2021_B.ATO = 0;
    exitg1 = false;
    while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.ATO < 100)) {
      if (!Copy_4_of_laod_arduino_2021_B.x[Copy_4_of_laod_arduino_2021_B.ATO]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        Copy_4_of_laod_arduino_2021_B.ATO++;
      }
    }

    if (!Ap_sel) {
      if (Copy_4_of_laod_arduino_2021_DW.counter > 100) {
        Copy_4_of_laod_arduino_2021_DW.counter = 0U;
      }

      Copy_4_of_laod_arduino_2021_B.qY = Copy_4_of_laod_arduino_2021_DW.counter
        + 1U;
      if (Copy_4_of_laod_arduino_2021_DW.counter + 1U > 65535U) {
        Copy_4_of_laod_arduino_2021_B.qY = 65535U;
      }

      Copy_4_of_laod_arduino_2021_DW.counter = (uint16_T)
        Copy_4_of_laod_arduino_2021_B.qY;
    }
  }

  Copy_4_of_laod_arduino_2021_B.new_mex = Copy_4_of_laod_arduino_2021_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  Copy_4_of_laod_arduino_2021_B.Memory1[0] =
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0];
  Copy_4_of_laod_arduino_2021_B.Memory1[1] =
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1];

  /* Memory: '<Root>/Memory' */
  Copy_4_of_laod_arduino_2021_B.Memory_k[0] =
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[0];
  Copy_4_of_laod_arduino_2021_B.Memory_k[1] =
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[1];
  Copy_4_of_laod_arduino_2021_B.Memory_k[2] =
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[2];
  Copy_4_of_laod_arduino_2021_B.Memory_k[3] =
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[3];

  /* Memory: '<S1>/Memory3' */
  Copy_4_of_laod_arduino_2021_B.Memory3 =
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o;
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 8;
       Copy_4_of_laod_arduino_2021_B.i++) {
    /* Memory: '<S1>/Memory' */
    Copy_4_of_laod_arduino_2021_B.Memory[Copy_4_of_laod_arduino_2021_B.i] =
      Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_ic[Copy_4_of_laod_arduino_2021_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.mess_out[0],
     &Copy_4_of_laod_arduino_2021_B.Add, &Copy_4_of_laod_arduino_2021_B.new_mex,
     &Copy_4_of_laod_arduino_2021_P.SIUAVuint8_Value,
     &Copy_4_of_laod_arduino_2021_B.Memory[0],
     &Copy_4_of_laod_arduino_2021_B.Memory1[0],
     &Copy_4_of_laod_arduino_2021_B.Memory_k[0],
     &Copy_4_of_laod_arduino_2021_B.Memory3,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o1[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o2,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o3_j,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o4_n[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o5[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o6,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o7[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o8,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o9[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o10[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o11[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o12,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o13,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o14,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o15,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o16,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 6;
       Copy_4_of_laod_arduino_2021_B.i++) {
    Copy_4_of_laod_arduino_2021_B.WP_info_in[Copy_4_of_laod_arduino_2021_B.i] =
      Copy_4_of_laod_arduino_2021_B.SFunction_o9[Copy_4_of_laod_arduino_2021_B.i];
  }

  if ((!Copy_4_of_laod_arduino_2021_DW.WP_dbP_not_empty) ||
      ((Copy_4_of_laod_arduino_2021_B.SFunction_o7[0] == 3) &&
       (Copy_4_of_laod_arduino_2021_B.SFunction_o7[1] == 250))) {
    memset(&Copy_4_of_laod_arduino_2021_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    Copy_4_of_laod_arduino_2021_DW.WP_dbP_not_empty = true;
    memset(&Copy_4_of_laod_arduino_2021_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!Copy_4_of_laod_arduino_2021_DW.WP_dbP_AL_not_empty) ||
      ((Copy_4_of_laod_arduino_2021_B.SFunction_o7[0] == 3) &&
       (Copy_4_of_laod_arduino_2021_B.SFunction_o7[1] == 250))) {
    memset(&Copy_4_of_laod_arduino_2021_DW.WP_dbP_AL[0], 0, 42U * sizeof
           (real32_T));
    Copy_4_of_laod_arduino_2021_DW.WP_dbP_AL_not_empty = true;
  }

  Copy_4_of_laod_arduino_2021_B.GC_info[0] =
    Copy_4_of_laod_arduino_2021_B.SFunction_o7[0];
  Copy_4_of_laod_arduino_2021_B.GC_info[1] =
    Copy_4_of_laod_arduino_2021_B.SFunction_o7[1];
  Copy_4_of_laod_arduino_2021_B.GC_info[2] =
    Copy_4_of_laod_arduino_2021_B.SFunction_o11[0];
  if (Copy_4_of_laod_arduino_2021_B.GC_info[0] == 1) {
    if ((Copy_4_of_laod_arduino_2021_B.GC_info[1] > 0) &&
        (Copy_4_of_laod_arduino_2021_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(Copy_4_of_laod_arduino_2021_B.SFunction_o8) > 0.0F) {
        Copy_4_of_laod_arduino_2021_DW.riferimenti[Copy_4_of_laod_arduino_2021_B.GC_info
          [1] - 1] = 1.0F;
      } else {
        if (Copy_4_of_laod_arduino_2021_B.SFunction_o8 == 0.0F) {
          Copy_4_of_laod_arduino_2021_DW.riferimenti[Copy_4_of_laod_arduino_2021_B.GC_info
            [1] - 1] = 0.0F;
        }
      }
    } else {
      if ((Copy_4_of_laod_arduino_2021_B.GC_info[1] > 7) &&
          (Copy_4_of_laod_arduino_2021_B.GC_info[1] < 12)) {
        Copy_4_of_laod_arduino_2021_DW.riferimenti[Copy_4_of_laod_arduino_2021_B.GC_info
          [1] - 1] = Copy_4_of_laod_arduino_2021_B.SFunction_o8;
      }
    }
  }

  if (Copy_4_of_laod_arduino_2021_B.SFunction_o12 == 13) {
    Copy_4_of_laod_arduino_2021_DW.riferimenti[Copy_4_of_laod_arduino_2021_B.SFunction_o12
      - 1] = Copy_4_of_laod_arduino_2021_B.SFunction_o13;
  }

  memcpy(&Copy_4_of_laod_arduino_2021_B.Val_out_MAV[0],
         &Copy_4_of_laod_arduino_2021_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((Copy_4_of_laod_arduino_2021_B.GC_info[0] == 3) &&
      (Copy_4_of_laod_arduino_2021_B.GC_info[1] == 200)) {
    if (Copy_4_of_laod_arduino_2021_B.SFunction_o9[0] > 6) {
      Copy_4_of_laod_arduino_2021_B.WP_info_in[0] = 6U;
    }

    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 6;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_DW.WP_dbI[Copy_4_of_laod_arduino_2021_B.ATO] =
        Copy_4_of_laod_arduino_2021_B.WP_info_in[0];
    }
  }

  if ((Copy_4_of_laod_arduino_2021_B.GC_info[0] == 3) &&
      (Copy_4_of_laod_arduino_2021_B.GC_info[1] < 200)) {
    if (Copy_4_of_laod_arduino_2021_B.SFunction_o10[1] == 0.0F) {
      Copy_4_of_laod_arduino_2021_B.qY =
        Copy_4_of_laod_arduino_2021_B.SFunction_o9[1] + 1U;
      if (Copy_4_of_laod_arduino_2021_B.SFunction_o9[1] + 1U > 65535U) {
        Copy_4_of_laod_arduino_2021_B.qY = 65535U;
      }

      for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
           Copy_4_of_laod_arduino_2021_B.ATO < 7;
           Copy_4_of_laod_arduino_2021_B.ATO++) {
        Copy_4_of_laod_arduino_2021_DW.WP_dbP[((int32_T)
          Copy_4_of_laod_arduino_2021_B.qY + 6 *
          Copy_4_of_laod_arduino_2021_B.ATO) - 1] =
          Copy_4_of_laod_arduino_2021_B.SFunction_o10[Copy_4_of_laod_arduino_2021_B.ATO];
      }

      Copy_4_of_laod_arduino_2021_B.qY =
        Copy_4_of_laod_arduino_2021_B.SFunction_o9[1] + 1U;
      if (Copy_4_of_laod_arduino_2021_B.SFunction_o9[1] + 1U > 65535U) {
        Copy_4_of_laod_arduino_2021_B.qY = 65535U;
      }

      for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
           Copy_4_of_laod_arduino_2021_B.ATO < 6;
           Copy_4_of_laod_arduino_2021_B.ATO++) {
        Copy_4_of_laod_arduino_2021_DW.WP_dbI[((int32_T)
          Copy_4_of_laod_arduino_2021_B.qY + 6 *
          (Copy_4_of_laod_arduino_2021_B.ATO + 1)) - 1] =
          Copy_4_of_laod_arduino_2021_B.WP_info_in[Copy_4_of_laod_arduino_2021_B.ATO
          + 1];
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
        (Copy_4_of_laod_arduino_2021_B.SFunction_o10[0] + 1.0F);
      for (Copy_4_of_laod_arduino_2021_B.g = 0; Copy_4_of_laod_arduino_2021_B.g <
           7; Copy_4_of_laod_arduino_2021_B.g++) {
        Copy_4_of_laod_arduino_2021_DW.WP_dbP_AL
          [(Copy_4_of_laod_arduino_2021_B.ATO + 6 *
            Copy_4_of_laod_arduino_2021_B.g) - 1] =
          Copy_4_of_laod_arduino_2021_B.SFunction_o10[Copy_4_of_laod_arduino_2021_B.g];
      }

      Copy_4_of_laod_arduino_2021_B.qY =
        Copy_4_of_laod_arduino_2021_B.SFunction_o9[1] + 1U;
      if (Copy_4_of_laod_arduino_2021_B.SFunction_o9[1] + 1U > 65535U) {
        Copy_4_of_laod_arduino_2021_B.qY = 65535U;
      }

      for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
           Copy_4_of_laod_arduino_2021_B.ATO < 6;
           Copy_4_of_laod_arduino_2021_B.ATO++) {
        Copy_4_of_laod_arduino_2021_DW.WP_dbI[((int32_T)
          Copy_4_of_laod_arduino_2021_B.qY + 6 *
          (Copy_4_of_laod_arduino_2021_B.ATO + 1)) - 1] =
          Copy_4_of_laod_arduino_2021_B.WP_info_in[Copy_4_of_laod_arduino_2021_B.ATO
          + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((Copy_4_of_laod_arduino_2021_B.SFunction_o6 == 0) &&
      (Copy_4_of_laod_arduino_2021_B.SFunction_o3_j == 0)) {
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 0U;
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 0U;
  } else if ((Copy_4_of_laod_arduino_2021_B.SFunction_o6 == 0) &&
             (Copy_4_of_laod_arduino_2021_B.SFunction_o3_j == 3)) {
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 0U;
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 0U;
    Copy_4_of_laod_arduino_2021_DW.test1 = 0.0;
  } else if ((Copy_4_of_laod_arduino_2021_B.SFunction_o6 == 0) &&
             (Copy_4_of_laod_arduino_2021_B.SFunction_o3_j == 2)) {
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 0U;
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 0U;
    Copy_4_of_laod_arduino_2021_DW.test1 = 0.0;
  } else if ((Copy_4_of_laod_arduino_2021_B.SFunction_o6 == 0) &&
             (Copy_4_of_laod_arduino_2021_B.SFunction_o3_j == 1)) {
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 0U;
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 0U;
    Copy_4_of_laod_arduino_2021_DW.test1 = 1.0;
  } else {
    switch (Copy_4_of_laod_arduino_2021_B.SFunction_o6) {
     case 192:
      Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 192U;
      Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 192U;
      break;

     case 208:
      Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 208U;
      Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 208U;
      break;

     default:
      if ((Copy_4_of_laod_arduino_2021_B.SFunction_o6 == 220) &&
          (Copy_4_of_laod_arduino_2021_B.SFunction_o3_j != 5)) {
        if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 0) &&
            (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] == 0) &&
            ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[2] == 1) ||
             (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[3] == 1) ||
             (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] == 1) ||
             (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[5] == 1) ||
             (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] == 1) ||
             (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[7] == 1)))
        {
          Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 220U;
          Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 220U;
        } else if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] ==
                    0) &&
                   (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] ==
                    1) &&
                   ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[2] ==
                     1) ||
                    (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[3] ==
                     1) ||
                    (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] ==
                     1) ||
                    (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[5] ==
                     1) ||
                    (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] ==
                     1) ||
                    (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[7] ==
                     1))) {
          Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 220U;
          Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 220U;
        } else {
          Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 208U;
          Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o = 208U;
        }
      } else if (Copy_4_of_laod_arduino_2021_B.SFunction_o3_j == 5) {
        Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 220U;
        Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] = 192U;
        Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  Copy_4_of_laod_arduino_2021_B.qY = 100U *
    Copy_4_of_laod_arduino_2021_B.SFunction_o11[5];
  if (Copy_4_of_laod_arduino_2021_B.qY > 65535U) {
    Copy_4_of_laod_arduino_2021_B.qY = 65535U;
  }

  if (Copy_4_of_laod_arduino_2021_B.SFunction_o11[4] == 0) {
    if ((uint16_T)Copy_4_of_laod_arduino_2021_B.qY == 0) {
      Copy_4_of_laod_arduino_2021_B.z = 0U;
    } else {
      Copy_4_of_laod_arduino_2021_B.z = MAX_uint16_T;
    }
  } else {
    Copy_4_of_laod_arduino_2021_B.z = (uint16_T)
      (Copy_4_of_laod_arduino_2021_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
       (uint32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.qY /
       Copy_4_of_laod_arduino_2021_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.qY -
                   (uint16_T)((uint32_T)Copy_4_of_laod_arduino_2021_B.z *
      Copy_4_of_laod_arduino_2021_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)
          Copy_4_of_laod_arduino_2021_B.SFunction_o11[4] >> 1) +
                    (Copy_4_of_laod_arduino_2021_B.SFunction_o11[4] & 1))) {
      Copy_4_of_laod_arduino_2021_B.z++;
    }
  }

  Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] = (uint8_T)
    AP_mode_idx_0;
  Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] = (uint8_T)
    AP_mode_idx_1;
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 7;
       Copy_4_of_laod_arduino_2021_B.i++) {
    Copy_4_of_laod_arduino_2021_B.f = rt_roundf_snf
      (Copy_4_of_laod_arduino_2021_DW.riferimenti[Copy_4_of_laod_arduino_2021_B.i]);
    if (Copy_4_of_laod_arduino_2021_B.f < 256.0F) {
      if (Copy_4_of_laod_arduino_2021_B.f >= 0.0F) {
        Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[Copy_4_of_laod_arduino_2021_B.i
          + 2] = (uint8_T)Copy_4_of_laod_arduino_2021_B.f;
      } else {
        Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[Copy_4_of_laod_arduino_2021_B.i
          + 2] = 0U;
      }
    } else {
      Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[Copy_4_of_laod_arduino_2021_B.i
        + 2] = MAX_uint8_T;
    }
  }

  /* Outputs for Enabled SubSystem: '<S577>/Subsystem1' incorporates:
   *  EnablePort: '<S579>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.SFunction_o14 > 0) {
    /* Inport: '<S579>/T' */
    Copy_4_of_laod_arduino_2021_B.T =
      Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S577>/Subsystem1' */

  /* Switch: '<S577>/Switch1' incorporates:
   *  Constant: '<S577>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  RelationalOperator: '<S577>/NotEqual'
   *  Switch: '<S577>/Switch'
   */
  if (Copy_4_of_laod_arduino_2021_P.Constant_Value_hx !=
      Copy_4_of_laod_arduino_2021_DW.riferimenti[12]) {
    /* Switch: '<S577>/Switch1' */
    Copy_4_of_laod_arduino_2021_B.Switch1 =
      Copy_4_of_laod_arduino_2021_DW.riferimenti[12];
  } else if (Copy_4_of_laod_arduino_2021_B.T >
             Copy_4_of_laod_arduino_2021_P.Switch_Threshold_p) {
    /* Switch: '<S577>/Switch' incorporates:
     *  Switch: '<S577>/Switch1'
     */
    Copy_4_of_laod_arduino_2021_B.Switch1 = Copy_4_of_laod_arduino_2021_B.T;
  } else {
    /* Switch: '<S577>/Switch1' */
    Copy_4_of_laod_arduino_2021_B.Switch1 =
      Copy_4_of_laod_arduino_2021_DW.riferimenti[12];
  }

  /* End of Switch: '<S577>/Switch1' */

  /* RateTransition: '<S29>/Rate Transition' */
  Copy_4_of_laod_arduino_2021_B.RateTransition =
    Copy_4_of_laod_arduino_2021_DW.RateTransition_Buffer0;

  /* Sum: '<S29>/Add1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  Memory: '<S29>/Memory1'
   */
  Copy_4_of_laod_arduino_2021_B.num_254 =
    (Copy_4_of_laod_arduino_2021_P.Constant2_Value_jg +
     Copy_4_of_laod_arduino_2021_P.Constant3_Value_o) +
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput;

  /* Switch: '<S29>/Switch' */
  if (Copy_4_of_laod_arduino_2021_B.num_254 >
      Copy_4_of_laod_arduino_2021_P.Switch_Threshold_f) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant2'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Constant2_Value_jg;
  } else {
    /* Switch: '<S29>/Switch' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput =
      Copy_4_of_laod_arduino_2021_B.num_254;
  }

  /* End of Switch: '<S29>/Switch' */

  /* MATLAB Function: '<S19>/iflogic_function' */
  if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 1.0) ||
      (Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 3.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 26U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 2.0) ||
             (Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 4.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 30U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             (Copy_4_of_laod_arduino_2021_B.RateTransition == 2.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 33U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             (Copy_4_of_laod_arduino_2021_B.RateTransition == 6.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 34U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             (Copy_4_of_laod_arduino_2021_B.RateTransition == 0.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 0U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             ((Copy_4_of_laod_arduino_2021_B.RateTransition == 1.0) ||
              (Copy_4_of_laod_arduino_2021_B.RateTransition == 5.0) ||
              (Copy_4_of_laod_arduino_2021_B.RateTransition == 9.0))) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 1U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             ((Copy_4_of_laod_arduino_2021_B.RateTransition == 3.0) ||
              (Copy_4_of_laod_arduino_2021_B.RateTransition == 8.0))) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 74U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             (Copy_4_of_laod_arduino_2021_B.RateTransition == 7.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 36U;
  } else if ((Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput == 0.0) &&
             (Copy_4_of_laod_arduino_2021_B.RateTransition == 4.0)) {
    Copy_4_of_laod_arduino_2021_B.iflogic = 29U;
  } else {
    Copy_4_of_laod_arduino_2021_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S19>/iflogic_function' */

  /* Sum: '<S29>/Add' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant1'
   *  Memory: '<S29>/Memory'
   */
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput +=
    Copy_4_of_laod_arduino_2021_P.Constant_Value_m +
    Copy_4_of_laod_arduino_2021_P.Constant1_Value_n;

  /* Gain: '<S19>/Gain' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_c *
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion3 =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit : (uint32_T)
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (Copy_4_of_laod_arduino_2021_B.ATO = 0; Copy_4_of_laod_arduino_2021_B.ATO <
       6; Copy_4_of_laod_arduino_2021_B.ATO++) {
    Copy_4_of_laod_arduino_2021_B.WP_info[Copy_4_of_laod_arduino_2021_B.ATO] =
      Copy_4_of_laod_arduino_2021_DW.WP_dbI[6 *
      Copy_4_of_laod_arduino_2021_B.ATO];
  }

  for (Copy_4_of_laod_arduino_2021_B.ATO = 0; Copy_4_of_laod_arduino_2021_B.ATO <
       7; Copy_4_of_laod_arduino_2021_B.ATO++) {
    Copy_4_of_laod_arduino_2021_B.WP_param[Copy_4_of_laod_arduino_2021_B.ATO] =
      Copy_4_of_laod_arduino_2021_DW.WP_dbP[6 *
      Copy_4_of_laod_arduino_2021_B.ATO];
  }

  if ((Copy_4_of_laod_arduino_2021_B.GC_info[0] == 2) &&
      (Copy_4_of_laod_arduino_2021_B.GC_info[1] < 6)) {
    Copy_4_of_laod_arduino_2021_B.qY = Copy_4_of_laod_arduino_2021_B.GC_info[1]
      + 1U;
    if (Copy_4_of_laod_arduino_2021_B.GC_info[1] + 1U > 65535U) {
      Copy_4_of_laod_arduino_2021_B.qY = 65535U;
    }

    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 6;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.WP_info[Copy_4_of_laod_arduino_2021_B.ATO] =
        Copy_4_of_laod_arduino_2021_DW.WP_dbI[(6 *
        Copy_4_of_laod_arduino_2021_B.ATO + (int32_T)
        Copy_4_of_laod_arduino_2021_B.qY) - 1];
    }

    Copy_4_of_laod_arduino_2021_B.qY = Copy_4_of_laod_arduino_2021_B.GC_info[1]
      + 1U;
    if (Copy_4_of_laod_arduino_2021_B.GC_info[1] + 1U > 65535U) {
      Copy_4_of_laod_arduino_2021_B.qY = 65535U;
    }

    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 7;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.WP_param[Copy_4_of_laod_arduino_2021_B.ATO] =
        Copy_4_of_laod_arduino_2021_DW.WP_dbP[(6 *
        Copy_4_of_laod_arduino_2021_B.ATO + (int32_T)
        Copy_4_of_laod_arduino_2021_B.qY) - 1];
    }
  }

  if ((Copy_4_of_laod_arduino_2021_B.GC_info[0] == 3) &&
      (Copy_4_of_laod_arduino_2021_B.GC_info[1] < 200)) {
    Copy_4_of_laod_arduino_2021_B.qY = Copy_4_of_laod_arduino_2021_B.GC_info[1]
      + 1U;
    if (Copy_4_of_laod_arduino_2021_B.GC_info[1] + 1U > 65535U) {
      Copy_4_of_laod_arduino_2021_B.qY = 65535U;
    }

    for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
         Copy_4_of_laod_arduino_2021_B.ATO < 6;
         Copy_4_of_laod_arduino_2021_B.ATO++) {
      Copy_4_of_laod_arduino_2021_B.WP_info[Copy_4_of_laod_arduino_2021_B.ATO] =
        Copy_4_of_laod_arduino_2021_DW.WP_dbI[(6 *
        Copy_4_of_laod_arduino_2021_B.ATO + (int32_T)
        Copy_4_of_laod_arduino_2021_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function' */

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S7>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_by *
     Copy_4_of_laod_arduino_2021_P.Constant_Value_jp[0]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* Outputs for Resettable SubSystem: '<S411>/Resettable Subsystem' */
  Copy_4_of_laod_arduino_2021_B.IProdOut = Copy_4__ResettableSubsystem
    (Copy_4_of_laod_arduino_2021_B.SFunction_o4_n[0],
     &Copy_4_of_laod_arduino_2021_DW.ResettableSubsystem_o,
     &Copy_4_of_laod_arduino_2021_P.ResettableSubsystem_o,
     &Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem_o);

  /* End of Outputs for SubSystem: '<S411>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S411>/Enabled Subsystem' */
  Copy_4_of__EnabledSubsystem(Copy_4_of_laod_arduino_2021_B.SFunction_o4_n[0],
    Copy_4_of_laod_arduino_2021_B.IProdOut,
    &Copy_4_of_laod_arduino_2021_B.Switch_l,
    &Copy_4_of_laod_arduino_2021_P.EnabledSubsystem_j);

  /* End of Outputs for SubSystem: '<S411>/Enabled Subsystem' */

  /* MATLAB Function: '<S565>/MATLAB Function' incorporates:
   *  Constant: '<S556>/Constant'
   *  Constant: '<S565>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.num_254 =
    Copy_4_of_laod_arduino_2021_P.Constant_Value_k *
    Copy_4_of_laod_arduino_2021_P.Constant_Value_p;
  Copy_4_of_laod_arduino_2021_B.RateTransition =
    Copy_4_of_laod_arduino_2021_B.num_254 /
    (Copy_4_of_laod_arduino_2021_B.num_254 + 1.0);

  /* MATLABSystem: '<S556>/Serial Receive' */
  if (Copy_4_of_laod_arduino_2021_DW.obj_m.Protocol !=
      Copy_4_of_laod_arduino_2021_P.SerialReceive_Protocol) {
    Copy_4_of_laod_arduino_2021_DW.obj_m.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialReceive_Protocol;
  }

  MW_Serial_read(0, Copy_4_of_laod_arduino_2021_DW.obj_m.DataSizeInBytes,
                 &Copy_4_of_laod_arduino_2021_B.b_dataOut_c[0], &status);

  /* Outputs for Enabled SubSystem: '<S556>/Subsystem1' incorporates:
   *  EnablePort: '<S564>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S564>/MATLAB Function' */
    for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i <
         31; Copy_4_of_laod_arduino_2021_B.i++) {
      Copy_4_of_laod_arduino_2021_B.messaggio[Copy_4_of_laod_arduino_2021_B.i] =
        0U;
    }

    guard1 = false;
    if (!Copy_4_of_laod_arduino_2021_DW.start_found_c) {
      Copy_4_of_laod_arduino_2021_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.i - 1 < 30)) {
        if ((Copy_4_of_laod_arduino_2021_B.b_dataOut_c[(uint8_T)
             Copy_4_of_laod_arduino_2021_B.i - 1] == 255) &&
            (Copy_4_of_laod_arduino_2021_B.b_dataOut_c[(uint8_T)
             Copy_4_of_laod_arduino_2021_B.i] == 254)) {
          Copy_4_of_laod_arduino_2021_B.caso = 31 - (uint8_T)
            Copy_4_of_laod_arduino_2021_B.i;
          for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
               Copy_4_of_laod_arduino_2021_B.ATO <=
               Copy_4_of_laod_arduino_2021_B.caso;
               Copy_4_of_laod_arduino_2021_B.ATO++) {
            Copy_4_of_laod_arduino_2021_DW.message_k[Copy_4_of_laod_arduino_2021_B.ATO]
              = Copy_4_of_laod_arduino_2021_B.b_dataOut_c[((uint8_T)
              Copy_4_of_laod_arduino_2021_B.i +
              Copy_4_of_laod_arduino_2021_B.ATO) - 1];
          }

          Copy_4_of_laod_arduino_2021_DW.counter_n = (uint8_T)(32 - (uint8_T)
            Copy_4_of_laod_arduino_2021_B.i);
          Copy_4_of_laod_arduino_2021_DW.start_found_c = true;
          exitg1 = true;
        } else {
          Copy_4_of_laod_arduino_2021_B.i++;
        }
      }

      if (Copy_4_of_laod_arduino_2021_DW.counter_n == 31) {
        for (Copy_4_of_laod_arduino_2021_B.i = 0;
             Copy_4_of_laod_arduino_2021_B.i < 31;
             Copy_4_of_laod_arduino_2021_B.i++) {
          Copy_4_of_laod_arduino_2021_B.messaggio[Copy_4_of_laod_arduino_2021_B.i]
            =
            Copy_4_of_laod_arduino_2021_DW.message_k[Copy_4_of_laod_arduino_2021_B.i];
          Copy_4_of_laod_arduino_2021_DW.message_k[Copy_4_of_laod_arduino_2021_B.i]
            = 0U;
        }

        Copy_4_of_laod_arduino_2021_DW.start_found_c = false;
        Copy_4_of_laod_arduino_2021_DW.counter_n = 0U;
        guard1 = true;
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.qY = 31U - /*MW:OvSatOk*/
        Copy_4_of_laod_arduino_2021_DW.counter_n;
      if (31U - Copy_4_of_laod_arduino_2021_DW.counter_n > 31U) {
        Copy_4_of_laod_arduino_2021_B.qY = 0U;
      }

      Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
        (Copy_4_of_laod_arduino_2021_DW.counter_n + 1U);
      if (Copy_4_of_laod_arduino_2021_DW.counter_n + 1U > 255U) {
        Copy_4_of_laod_arduino_2021_B.ATO = 255;
      }

      if ((uint8_T)Copy_4_of_laod_arduino_2021_B.ATO > 31) {
        Copy_4_of_laod_arduino_2021_B.i = 1;
      } else {
        Copy_4_of_laod_arduino_2021_B.i = (uint8_T)
          Copy_4_of_laod_arduino_2021_B.ATO;
      }

      if (1 > (uint8_T)Copy_4_of_laod_arduino_2021_B.qY) {
        Copy_4_of_laod_arduino_2021_B.caso = -1;
      } else {
        Copy_4_of_laod_arduino_2021_B.caso = (uint8_T)
          Copy_4_of_laod_arduino_2021_B.qY - 1;
      }

      for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
           Copy_4_of_laod_arduino_2021_B.ATO <=
           Copy_4_of_laod_arduino_2021_B.caso; Copy_4_of_laod_arduino_2021_B.ATO
           ++) {
        Copy_4_of_laod_arduino_2021_DW.message_k
          [(Copy_4_of_laod_arduino_2021_B.i + Copy_4_of_laod_arduino_2021_B.ATO)
          - 1] =
          Copy_4_of_laod_arduino_2021_B.b_dataOut_c[Copy_4_of_laod_arduino_2021_B.ATO];
      }

      Copy_4_of_laod_arduino_2021_B.qY = 31U - /*MW:OvSatOk*/
        Copy_4_of_laod_arduino_2021_DW.counter_n;
      if (31U - Copy_4_of_laod_arduino_2021_DW.counter_n > 31U) {
        Copy_4_of_laod_arduino_2021_B.qY = 0U;
      }

      Copy_4_of_laod_arduino_2021_DW.counter_n = (uint8_T)
        Copy_4_of_laod_arduino_2021_B.qY;
      for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i <
           31; Copy_4_of_laod_arduino_2021_B.i++) {
        Copy_4_of_laod_arduino_2021_B.messaggio[Copy_4_of_laod_arduino_2021_B.i]
          =
          Copy_4_of_laod_arduino_2021_DW.message_k[Copy_4_of_laod_arduino_2021_B.i];
        Copy_4_of_laod_arduino_2021_DW.message_k[Copy_4_of_laod_arduino_2021_B.i]
          = 0U;
      }

      status = Copy_4_of_laod_arduino_2021_DW.counter_n;
      do {
        exitg3 = 0;
        if (status < 31) {
          if ((Copy_4_of_laod_arduino_2021_B.b_dataOut_c[status - 1] == 255) &&
              (Copy_4_of_laod_arduino_2021_B.b_dataOut_c[status] == 254)) {
            Copy_4_of_laod_arduino_2021_B.caso = 31 - status;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <=
                 Copy_4_of_laod_arduino_2021_B.caso;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_DW.message_k[Copy_4_of_laod_arduino_2021_B.ATO]
                = Copy_4_of_laod_arduino_2021_B.b_dataOut_c[(status +
                Copy_4_of_laod_arduino_2021_B.ATO) - 1];
            }

            Copy_4_of_laod_arduino_2021_B.qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              Copy_4_of_laod_arduino_2021_B.qY = 0U;
            }

            Copy_4_of_laod_arduino_2021_DW.counter_n = (uint8_T)(31 - (int32_T)
              Copy_4_of_laod_arduino_2021_B.qY);
            Copy_4_of_laod_arduino_2021_DW.start_found_c = true;
            guard1 = true;
            exitg3 = 1;
          } else {
            Copy_4_of_laod_arduino_2021_DW.start_found_c = false;
            Copy_4_of_laod_arduino_2021_DW.counter_n = 0U;
            status++;
          }
        } else {
          guard1 = true;
          exitg3 = 1;
        }
      } while (exitg3 == 0);
    }

    if (guard1) {
      /* Outputs for Enabled SubSystem: '<S564>/Subsystem2' incorporates:
       *  EnablePort: '<S568>/Enable'
       */
      /* S-Function (byte2any_svd): '<S568>/Byte Unpack' */

      /* Unpack: <S568>/Byte Unpack */
      {
        uint32_T MW_inputPortOffset = 0;
        uint32_T MW_outputPortWidth = 0;
        uint32_T MW_remainder2 = 0;

        /* Packed input data type - uint8_T */
        /* Unpacking the values to output 1 */
        /* Output data type - uint8_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint8_T);
          memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o1_o[0],
                 (uint8_T*)&Copy_4_of_laod_arduino_2021_B.messaggio[0] +
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
        /* Output data type - real32_T, size - 4 */
        {
          MW_outputPortWidth = 4 * sizeof(real32_T);
          memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[0],
                 (uint8_T*)&Copy_4_of_laod_arduino_2021_B.messaggio[0] +
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
        /* Output data type - int16_T, size - 4 */
        {
          MW_outputPortWidth = 4 * sizeof(int16_T);
          memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[0],
                 (uint8_T*)&Copy_4_of_laod_arduino_2021_B.messaggio[0] +
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

        /* Unpacking the values to output 4 */
        /* Output data type - uint16_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint16_T);
          memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o4[0],
                 (uint8_T*)&Copy_4_of_laod_arduino_2021_B.messaggio[0] +
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

        /* Unpacking the values to output 5 */
        /* Output data type - uint8_T, size - 1 */
        {
          MW_outputPortWidth = 1 * sizeof(uint8_T);
          memcpy((uint8_T*)&Copy_4_of_laod_arduino_2021_B.ByteUnpack_o5,
                 (uint8_T*)&Copy_4_of_laod_arduino_2021_B.messaggio[0] +
                 MW_inputPortOffset, MW_outputPortWidth);
        }
      }

      /* End of Outputs for SubSystem: '<S564>/Subsystem2' */
    }

    /* End of MATLAB Function: '<S564>/MATLAB Function' */
  }

  /* End of MATLABSystem: '<S556>/Serial Receive' */
  /* End of Outputs for SubSystem: '<S556>/Subsystem1' */

  /* Gain: '<S556>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion2'
   */
  Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0 =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_p * (real_T)
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[0];
  Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_1 =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_p * (real_T)
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[1];

  /* Sum: '<S565>/Sum' incorporates:
   *  UnitDelay: '<S565>/Unit Delay'
   */
  Copy_4_of_laod_arduino_2021_B.num_254 =
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_1 +
    Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE;

  /* Product: '<S565>/Product1' incorporates:
   *  MATLAB Function: '<S565>/MATLAB Function'
   */
  Copy_4_of_laod_arduino_2021_B.Product1 =
    Copy_4_of_laod_arduino_2021_B.RateTransition *
    Copy_4_of_laod_arduino_2021_B.num_254;

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 9;
       Copy_4_of_laod_arduino_2021_B.i++) {
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[Copy_4_of_laod_arduino_2021_B.i]
      =
      Copy_4_of_laod_arduino_2021_B.ByteReversal[Copy_4_of_laod_arduino_2021_B.i];
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* Gain: '<S552>/Gain1' */
  Copy_4_of_laod_arduino_2021_B.Gain1_j =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_m *
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[6];

  /* MATLAB Function: '<S417>/MATLAB Function1' */
  guard1 = false;
  if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] == 1) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     */
    if (Copy_4_of_laod_arduino_2021_B.Switch_l != 0.0) {
      Copy_4_of_laod_arduino_2021_B.Sum3_o =
        Copy_4_of_laod_arduino_2021_P.Constant_Value_i;
    } else {
      Copy_4_of_laod_arduino_2021_B.Sum3_o =
        Copy_4_of_laod_arduino_2021_B.Product1;
    }

    /* End of Switch: '<S40>/Switch' */
    if (Copy_4_of_laod_arduino_2021_B.Sum3_o >
        Copy_4_of_laod_arduino_2021_P.safe_V) {
      Copy_4_of_laod_arduino_2021_DW.alarm = 1.0;
    } else if (fabs(Copy_4_of_laod_arduino_2021_P.Gain_Gain_mz *
                    Copy_4_of_laod_arduino_2021_B.Gain1_j) >
               Copy_4_of_laod_arduino_2021_P.safe_phi) {
      Copy_4_of_laod_arduino_2021_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 1) {
      Copy_4_of_laod_arduino_2021_DW.alarm = 0.0;
    }
  }

  /* Outputs for Resettable SubSystem: '<S434>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S437>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem_Reset_ZCE,
               (Copy_4_of_laod_arduino_2021_DW.alarm)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S438>/Sum' incorporates:
     *  Memory: '<S438>/Memory'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition;
  }

  /* Sum: '<S438>/Sum' incorporates:
   *  Constant: '<S438>/Constant4'
   *  Memory: '<S438>/Memory'
   */
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h +=
    Copy_4_of_laod_arduino_2021_P.t_AP;

  /* End of Outputs for SubSystem: '<S434>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S434>/Enabled ' incorporates:
   *  EnablePort: '<S436>/Enable'
   */
  /* MATLAB Function: '<S417>/MATLAB Function1' */
  if (Copy_4_of_laod_arduino_2021_DW.alarm > 0.0) {
    Copy_4_of_laod_arduino_2021_DW.Enabled_MODE = true;

    /* Switch: '<S436>/Switch' */
    if (Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h >
        Copy_4_of_laod_arduino_2021_P.time_alarm_SAFE) {
      /* Switch: '<S436>/Switch' incorporates:
       *  Constant: '<S436>/Constant'
       */
      Copy_4_of_laod_arduino_2021_B.Switch_n =
        Copy_4_of_laod_arduino_2021_P.Constant_Value;
    } else {
      /* Switch: '<S436>/Switch' incorporates:
       *  Constant: '<S436>/Constant1'
       */
      Copy_4_of_laod_arduino_2021_B.Switch_n =
        Copy_4_of_laod_arduino_2021_P.Constant1_Value;
    }

    /* End of Switch: '<S436>/Switch' */
  } else {
    if (Copy_4_of_laod_arduino_2021_DW.Enabled_MODE) {
      /* Disable for Switch: '<S436>/Switch' incorporates:
       *  Outport: '<S436>/Alarm Safe'
       */
      Copy_4_of_laod_arduino_2021_B.Switch_n =
        Copy_4_of_laod_arduino_2021_P.AlarmSafe_Y0;
      Copy_4_of_laod_arduino_2021_DW.Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S434>/Enabled ' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/load uint16'
   *  Gain: '<S21>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[0] =
    Copy_4_of_laod_arduino_2021_P.loaduint16_Value;
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  Copy_4_of_laod_arduino_2021_B.qY = 10U * Copy_4_of_laod_arduino_2021_B.z;
  if (Copy_4_of_laod_arduino_2021_B.qY > 65535U) {
    Copy_4_of_laod_arduino_2021_B.qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)
    Copy_4_of_laod_arduino_2021_B.qY;
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[3] =
    Copy_4_of_laod_arduino_2021_B.SFunction_o11[6];
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[4] =
    Copy_4_of_laod_arduino_2021_B.SFunction_o11[2];
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[5] =
    Copy_4_of_laod_arduino_2021_P._Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_B.Switch_n);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S21>/Data Type Conversion4' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_P.Constant2_Value_k);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S21>/Gain2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_P.Gain2_Gain *
     Copy_4_of_laod_arduino_2021_P.Constant_Value_jp[2]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Gain: '<S21>/Gain2'
   */
  Copy_4_of_laod_arduino_2021_B.Gain1 = (int16_T)
    (((Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
       -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
       (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit)
      * Copy_4_of_laod_arduino_2021_P.Gain1_Gain_eu) >> 18);

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_P.Constant_Value_jp[1]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 256.0);
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion3' */
  Copy_4_of_laod_arduino_2021_B.B_Remaining = (int8_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int8_T)
     -(int8_T)(uint8_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)
     (int8_T)(uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_P.Constant_Value_e);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit : (uint32_T)
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* MATLAB Function: '<S17>/Alarm set' incorporates:
   *  Constant: '<S40>/Constant2'
   *  SignalConversion generated from: '<S28>/ SFunction '
   */
  rtb_H_mav[0] = Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0];
  rtb_H_mav[1] = Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1];
  if (Copy_4_of_laod_arduino_2021_B.Switch_n == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (Copy_4_of_laod_arduino_2021_P.Constant2_Value_k == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S17>/Alarm set' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S17>/Type fixed_wing Autopilot generic'
   */
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[0] =
    Copy_4_of_laod_arduino_2021_P.Typefixed_wingAutopilotgeneric_[0];
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[2] = rtb_H_mav[0];
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[1] =
    Copy_4_of_laod_arduino_2021_P.Typefixed_wingAutopilotgeneric_[1];
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[3] = rtb_H_mav[1];
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 6;
       Copy_4_of_laod_arduino_2021_B.i++) {
    /* Gain: '<S18>/Gain' */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_dn *
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[Copy_4_of_laod_arduino_2021_B.i];

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
    } else {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
    }

    if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
    } else {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ld[Copy_4_of_laod_arduino_2021_B.i]
      = (int16_T)(Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)
                  (int16_T)-(int16_T)(uint16_T)
                  -Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)
                  (int16_T)(uint16_T)
                  Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_dn *
    Copy_4_of_laod_arduino_2021_P.Constant_Value_hxg;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ld[6] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_dn *
    Copy_4_of_laod_arduino_2021_P.Constant1_Value_f;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ld[7] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_dn *
    Copy_4_of_laod_arduino_2021_P.Constant2_Value_e;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ld[8] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S553>/Gain1' */
  Copy_4_of_laod_arduino_2021_B.Gain1_c =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_l *
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[7];

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Gain: '<S554>/Gain1'
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[0] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.Gain1_j;
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[1] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.Gain1_c;
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[2] = (real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain1_Gain_i *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[8]);
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[3] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[3];
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[4] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[4];
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[5] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[5];

  /* Gain: '<S557>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Copy_4_of_laod_arduino_2021_B.Gain1_f =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_d *
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[0];

  /* Gain: '<S558>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Copy_4_of_laod_arduino_2021_B.Gain1_p =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_n *
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[1];

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S26>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_f2 *
    Copy_4_of_laod_arduino_2021_B.Gain1_f *
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_bx[0];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_a[0] =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
    -Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)(uint32_T)
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S27>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_ds *
    Copy_4_of_laod_arduino_2021_B.Gain1_p *
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_bx[1];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_a[1] =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
    -Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)(uint32_T)
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* Gain: '<S16>/Gain' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_bx[2] *
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_a[2] =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
    -Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)(uint32_T)
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/alt_r'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_bx[3] *
    Copy_4_of_laod_arduino_2021_P.alt_r_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_a[3] =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
    -Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)(uint32_T)
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* Gain: '<S556>/Gain4' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion3'
   */
  Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
    Copy_4_of_laod_arduino_2021_P.Gain4_Gain * (real_T)
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o4[0];

  /* Gain: '<S16>/Gain1' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_e *
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_p[0] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S16>/Gain1' incorporates:
   *  Constant: '<S16>/vel y'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_e *
    Copy_4_of_laod_arduino_2021_P.vely_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_p[1] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S16>/Gain1' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_e *
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_p[2] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S555>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   *  Gain: '<S559>/Gain1'
   */
  Copy_4_of_laod_arduino_2021_B.Gain1_kx =
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_b *
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[3] *
    Copy_4_of_laod_arduino_2021_P.Gain1_Gain_n1;

  /* Gain: '<S16>/Gain2' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain2_Gain_k *
    Copy_4_of_laod_arduino_2021_B.Gain1_kx;

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_h = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Constant: '<S22>/airspeed groundspeed alt climb1'
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Copy_4_of_laod_arduino_2021_B.AGAC[0] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.Product1;
  Copy_4_of_laod_arduino_2021_B.AGAC[1] = (real32_T)
    Copy_4_of_laod_arduino_2021_P.airspeedgroundspeedaltclimb1_Va;
  Copy_4_of_laod_arduino_2021_B.AGAC[2] =
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2];
  Copy_4_of_laod_arduino_2021_B.AGAC[3] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0;

  /* Gain: '<S35>/Gain' */
  Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0 =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_l *
    Copy_4_of_laod_arduino_2021_B.Gain1_kx;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Abs: '<S36>/Abs'
   *  Constant: '<S36>/Constant2'
   *  Sum: '<S36>/Sum'
   */
  if (!(Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0 >
        Copy_4_of_laod_arduino_2021_P.Switch2_Threshold_a)) {
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0 =
      Copy_4_of_laod_arduino_2021_P.Constant2_Value - fabs
      (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0);
  }

  /* End of Switch: '<S36>/Switch2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0 < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading_g = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Gain: '<S22>/USCITA PERCENTUALE' incorporates:
   *  Constant: '<S6>/Constant'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.USCITAPERCENTUALE_Gain *
    Copy_4_of_laod_arduino_2021_P.Constant_Value_c;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  Copy_4_of_laod_arduino_2021_B.Throttle = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* S-Function (PWMinterrupt_throttle_v4_4): '<S9>/S-Function Builder6' */
  PWMinterrupt_throttle_v4_4_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.PWM_throttle);

  /* Product: '<S590>/Divide2' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   *  Product: '<S593>/Multiply'
   *  Sum: '<S590>/Sum3'
   */
  Copy_4_of_laod_arduino_2021_B.Gain1_kx =
    Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[0] -
    Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[1];

  /* Sum: '<S590>/Sum5' incorporates:
   *  Constant: '<S590>/manetta_massima'
   *  Constant: '<S590>/manetta_minima'
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   *  Product: '<S590>/Divide2'
   *  Product: '<S590>/Multiply1'
   *  Sum: '<S590>/Sum2'
   *  Sum: '<S590>/Sum4'
   */
  Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0 = (real_T)
    (Copy_4_of_laod_arduino_2021_B.PWM_throttle -
     Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[1]) /
    Copy_4_of_laod_arduino_2021_B.Gain1_kx *
    (Copy_4_of_laod_arduino_2021_P.attuatore_Tmax -
     Copy_4_of_laod_arduino_2021_P.attuatore_Tmin) +
    Copy_4_of_laod_arduino_2021_P.attuatore_Tmin;

  /* Gain: '<S31>/Gain2' */
  Copy_4_of_laod_arduino_2021_B.Gain2_g =
    Copy_4_of_laod_arduino_2021_P.Gain2_Gain_j *
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0;

  /* S-Function (PWMinterrupt_goHome): '<S9>/S-Function Builder2' */
  PWMinterrupt_goHome_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.SFunctionBuilder2);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  if (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder2 >
      Copy_4_of_laod_arduino_2021_P.Switch_Threshold_m) {
    Copy_4_of_laod_arduino_2021_B.Go_Home =
      Copy_4_of_laod_arduino_2021_P.Constant_Value_b;
  } else {
    Copy_4_of_laod_arduino_2021_B.Go_Home =
      Copy_4_of_laod_arduino_2021_P.Constant1_Value_js;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<S40>/ STATI' incorporates:
   *  Constant: '<S40>/Constant2'
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  if (Copy_4_of_laod_arduino_2021_DW.is_active_c26_Copy_4_of_laod_ar == 0U) {
    Copy_4_of_laod_arduino_2021_DW.is_active_c26_Copy_4_of_laod_ar = 1U;
    Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_ardui_IN_MANUALE;
  } else {
    switch (Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2) {
     case Copy_4_of_laod_ar_IN_AUTOMATICA:
      if (Copy_4_of_laod_arduino_2021_P.Constant2_Value_k == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA = 0;
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of__IN_Intervento_Pilota;
      } else if (Copy_4_of_laod_arduino_2021_B.Switch_n == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA = 0;
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduino__IN_Safe;
      } else if (Copy_4_of_laod_arduino_2021_B.Go_Home == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA = 0;
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardui_IN_Go_Home;
      } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] == 0)
      {
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA = 0;
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardu_IN_Stand_By;
      } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 1)
      {
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA = 0;
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardui_IN_MANUALE;
      } else {
        switch (Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA) {
         case Copy__IN_ATTERRAGGIO_AUTOMATICO:
          if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[8] == 0) &&
              (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] > 20.0F) &&
              (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] == 1))
          {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ardu_IN_WAYPOINT;
          } else if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[8] ==
                      0) && (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] >
                             20.0F)) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ar_IN_VETTORIALE;
          } else if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[7] ==
                      1) &&
                     (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[8] ==
                      0) && (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] <
                             1.0F) &&
                     (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 < 1.0)) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_IN_DECOLLO_AUTOMATICO;
          } else {
            Copy_4_of_laod_arduino_2021_B.modo = 4.0;
            Copy_4_of_laod_arduino_2021_B.switch_manetta = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_alettoni = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_timone = 1.0;
          }
          break;

         case Copy_4_of_IN_DECOLLO_AUTOMATICO:
          if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[7] == 0) &&
              (Copy_4_of_laod_arduino_2021_B.Product1 >= 1.0) &&
              ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[3] == 1) ||
               (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] == 1) ||
               (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[2] == 1)))
          {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ar_IN_VETTORIALE;
          } else if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] ==
                      1) && (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] >
                             30.0F)) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ardu_IN_WAYPOINT;
          } else {
            Copy_4_of_laod_arduino_2021_B.modo = 3.0;
            Copy_4_of_laod_arduino_2021_B.switch_manetta = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_alettoni = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_timone = 1.0;
          }
          break;

         case Copy_4_of_laod_arduino__IN_TEST:
          if (Copy_4_of_laod_arduino_2021_DW.test1 == 0.0) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ar_IN_VETTORIALE;
          } else {
            Copy_4_of_laod_arduino_2021_B.switch_manetta = 0.0;
            Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 0.0;
            Copy_4_of_laod_arduino_2021_B.switch_alettoni = 0.0;
            Copy_4_of_laod_arduino_2021_B.switch_timone = 0.0;
          }
          break;

         case Copy_4_of_laod_ar_IN_VETTORIALE:
          if (Copy_4_of_laod_arduino_2021_DW.test1 == 1.0) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_arduino__IN_TEST;
          } else if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[7] ==
                      1) && (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 <
                             1.0)) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_IN_DECOLLO_AUTOMATICO;
          } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[8] ==
                     1) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy__IN_ATTERRAGGIO_AUTOMATICO;
          } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] ==
                     1) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ardu_IN_WAYPOINT;
          } else {
            Copy_4_of_laod_arduino_2021_B.modo = 2.0;
            Copy_4_of_laod_arduino_2021_B.switch_manetta = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_alettoni = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_timone = 1.0;
          }
          break;

         default:
          /* case IN_WAYPOINT: */
          if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] == 0) &&
              ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[3] == 1) ||
               (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] == 1) ||
               (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[2] == 1) ||
               (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[7] == 1)))
          {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy_4_of_laod_ar_IN_VETTORIALE;
          } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[8] ==
                     1) {
            Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
              Copy__IN_ATTERRAGGIO_AUTOMATICO;
          } else {
            Copy_4_of_laod_arduino_2021_B.modo = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_manetta = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_alettoni = 1.0;
            Copy_4_of_laod_arduino_2021_B.switch_timone = 1.0;
          }
          break;
        }
      }
      break;

     case Copy_4_of_laod_ardui_IN_Go_Home:
      if ((Copy_4_of_laod_arduino_2021_B.Go_Home == 0.0) &&
          ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[6] == 1) ||
           (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[3] == 1) ||
           (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] == 1) ||
           (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[2] == 1) ||
           (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[8] == 1))) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ar_IN_AUTOMATICA;
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
          Copy_4_of_laod_ar_IN_VETTORIALE;
      } else if (Copy_4_of_laod_arduino_2021_B.Switch_n == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduino__IN_Safe;
      } else if (Copy_4_of_laod_arduino_2021_P.Constant2_Value_k == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of__IN_Intervento_Pilota;
      } else {
        Copy_4_of_laod_arduino_2021_B.modo = 5.0;
        Copy_4_of_laod_arduino_2021_B.switch_manetta = 1.0;
        Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 1.0;
        Copy_4_of_laod_arduino_2021_B.switch_alettoni = 1.0;
        Copy_4_of_laod_arduino_2021_B.switch_timone = 1.0;
      }
      break;

     case Copy_4_of__IN_Intervento_Pilota:
      if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 1) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardui_IN_MANUALE;
      } else {
        Copy_4_of_laod_arduino_2021_B.switch_manetta = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_alettoni = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_timone = 0.0;
      }
      break;

     case Copy_4_of_laod_ardui_IN_MANUALE:
      if ((Copy_4_of_laod_arduino_2021_B.Go_Home == 1.0) &&
          (Copy_4_of_laod_arduino_2021_B.Switch_n == 0.0)) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardui_IN_Go_Home;
      } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 0)
      {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardu_IN_Stand_By;
      } else {
        Copy_4_of_laod_arduino_2021_B.switch_manetta = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_alettoni = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_timone = 0.0;
      }
      break;

     case Copy_4_of_laod_arduino__IN_Safe:
      if (Copy_4_of_laod_arduino_2021_P.Constant2_Value_k == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of__IN_Intervento_Pilota;
      } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 1)
      {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardui_IN_MANUALE;
      } else {
        Copy_4_of_laod_arduino_2021_B.switch_manetta = 1.0;
        Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 1.0;
        Copy_4_of_laod_arduino_2021_B.switch_alettoni = 1.0;
        Copy_4_of_laod_arduino_2021_B.switch_timone = 1.0;
      }
      break;

     default:
      /* case IN_Stand_By: */
      if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] == 1) {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ar_IN_AUTOMATICA;
        Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA =
          Copy_4_of_laod_ar_IN_VETTORIALE;
      } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 1)
      {
        Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardui_IN_MANUALE;
      } else {
        Copy_4_of_laod_arduino_2021_B.switch_manetta = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_alettoni = 0.0;
        Copy_4_of_laod_arduino_2021_B.switch_timone = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S40>/ STATI' */

  /* S-Function (PWMinterrupt_elevator_v4_4): '<S9>/S-Function Builder1' */
  PWMinterrupt_elevator_v4_4_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.PWM_elevator);

  /* Product: '<S587>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion13'
   *  DataTypeConversion: '<S9>/Data Type Conversion6'
   *  DataTypeConversion: '<S9>/Data Type Conversion7'
   *  Product: '<S588>/Divide'
   *  Product: '<S594>/Multiply'
   *  Sum: '<S587>/Sum'
   *  Sum: '<S587>/Sum1'
   */
  Copy_4_of_laod_arduino_2021_B.Go_Home =
    Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[2] -
    Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[3];
  Copy_4_of_laod_arduino_2021_B.Sum_nu = (real_T)
    (Copy_4_of_laod_arduino_2021_B.PWM_elevator -
     Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[3]) /
    Copy_4_of_laod_arduino_2021_B.Go_Home;

  /* Sum: '<S587>/Sum2' incorporates:
   *  Constant: '<S587>/Constant8'
   *  Constant: '<S587>/Constant9'
   *  Sum: '<S594>/Sum1'
   */
  Copy_4_of_laod_arduino_2021_B.rtb_Sum3_o_tmp =
    Copy_4_of_laod_arduino_2021_P.attuatore_Emax -
    Copy_4_of_laod_arduino_2021_P.attuatore_Emin;

  /* Sum: '<S587>/Sum3' incorporates:
   *  Constant: '<S587>/Constant9'
   *  Product: '<S587>/Divide'
   *  Product: '<S587>/Multiply'
   *  Sum: '<S587>/Sum2'
   */
  Copy_4_of_laod_arduino_2021_B.Sum3_o = Copy_4_of_laod_arduino_2021_B.Sum_nu *
    Copy_4_of_laod_arduino_2021_B.rtb_Sum3_o_tmp +
    Copy_4_of_laod_arduino_2021_P.attuatore_Emin;

  /* MATLAB Function: '<S40>/MATLAB Function' */
  if (Copy_4_of_laod_arduino_2021_B.modo == 3.0) {
    Copy_4_of_laod_arduino_2021_B.ATO = 1;
    Copy_4_of_laod_arduino_2021_B.AL = 0;
  } else if (Copy_4_of_laod_arduino_2021_B.modo == 4.0) {
    Copy_4_of_laod_arduino_2021_B.AL = 1;
    Copy_4_of_laod_arduino_2021_B.ATO = 0;
  } else {
    Copy_4_of_laod_arduino_2021_B.ATO = 0;
    Copy_4_of_laod_arduino_2021_B.AL = 0;
  }

  /* Gain: '<S588>/Gain' incorporates:
   *  Constant: '<S588>/Constant8'
   *  Constant: '<S588>/Constant9'
   *  Product: '<S588>/Multiply'
   *  Sum: '<S588>/Sum2'
   *  Sum: '<S588>/Sum3'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    (Copy_4_of_laod_arduino_2021_B.Sum_nu *
     (Copy_4_of_laod_arduino_2021_P.theta_max -
      Copy_4_of_laod_arduino_2021_P.theta_min) +
     Copy_4_of_laod_arduino_2021_P.theta_min) *
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_h;

  /* Saturate: '<S588>/Saturation' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >
      Copy_4_of_laod_arduino_2021_P.theta_max) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_P.theta_max;
  } else {
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit <
        Copy_4_of_laod_arduino_2021_P.theta_min) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_P.theta_min;
    }
  }

  /* End of Saturate: '<S588>/Saturation' */

  /* Sum: '<S39>/Sum2' */
  Copy_4_of_laod_arduino_2021_B.Gain1_c =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit -
    Copy_4_of_laod_arduino_2021_B.Gain1_c;

  /* Sum: '<S351>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore beccheggio1'
   *  DiscreteIntegrator: '<S342>/Integrator'
   *  Product: '<S347>/PProd Out'
   */
  Copy_4_of_laod_arduino_2021_B.Sum_nu = Copy_4_of_laod_arduino_2021_B.Gain1_c *
    Copy_4_of_laod_arduino_2021_P.Kp_becch +
    Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE;

  /* Saturate: '<S349>/Saturation' */
  if (Copy_4_of_laod_arduino_2021_B.Sum_nu >
      Copy_4_of_laod_arduino_2021_P.attuatore_Emax) {
    Copy_4_of_laod_arduino_2021_B.Saturation =
      Copy_4_of_laod_arduino_2021_P.attuatore_Emax;
  } else if (Copy_4_of_laod_arduino_2021_B.Sum_nu <
             Copy_4_of_laod_arduino_2021_P.attuatore_Emin) {
    Copy_4_of_laod_arduino_2021_B.Saturation =
      Copy_4_of_laod_arduino_2021_P.attuatore_Emin;
  } else {
    Copy_4_of_laod_arduino_2021_B.Saturation =
      Copy_4_of_laod_arduino_2021_B.Sum_nu;
  }

  /* End of Saturate: '<S349>/Saturation' */

  /* MultiPortSwitch: '<S304>/Switch Bumpless 2' */
  if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_equilibratore == 0) {
    Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 =
      Copy_4_of_laod_arduino_2021_B.Sum3_o;
  } else {
    Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 =
      Copy_4_of_laod_arduino_2021_B.Saturation;
  }

  /* End of MultiPortSwitch: '<S304>/Switch Bumpless 2' */

  /* MultiPortSwitch: '<S309>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (Copy_4_of_laod_arduino_2021_B.AL != 0) {
    /* Switch: '<S309>/Switch1' incorporates:
     *  Constant: '<S309>/Constant5'
     */
    if (!(Copy_4_of_laod_arduino_2021_B.Product1 >=
          Copy_4_of_laod_arduino_2021_P.Switch1_Threshold)) {
      Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 =
        Copy_4_of_laod_arduino_2021_P.Constant5_Value;
    }

    /* End of Switch: '<S309>/Switch1' */
  }

  /* End of MultiPortSwitch: '<S309>/Multiport Switch2' */

  /* Logic: '<S41>/AND' */
  Ap_sel = ((Copy_4_of_laod_arduino_2021_B.switch_manetta != 0.0) &&
            (Copy_4_of_laod_arduino_2021_B.switch_equilibratore != 0.0) &&
            (Copy_4_of_laod_arduino_2021_B.switch_alettoni != 0.0) &&
            (Copy_4_of_laod_arduino_2021_B.switch_timone != 0.0));

  /* Chart: '<S41>/Chart' incorporates:
   *  Logic: '<S41>/AND'
   */
  if (Copy_4_of_laod_arduino_2021_DW.is_active_c21_Copy_4_of_laod_ar == 0U) {
    Copy_4_of_laod_arduino_2021_DW.is_active_c21_Copy_4_of_laod_ar = 1U;
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_arduino_20_IN_In;
    Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
    Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
    Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
    Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
    Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
  } else {
    switch (Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2) {
     case Copy_4_of_laod_a_IN_AutoLanding:
      if ((!(Copy_4_of_laod_arduino_2021_B.switch_manetta != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_equilibratore != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_alettoni != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_timone != 0.0))) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduino_20_IN_In;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 2.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ar_IN_Vettoriale;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardu_IN_Waypoint;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 5.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduin_IN_GoHome;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 1.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      }
      break;

     case Copy_4_of_laod_a_IN_AutoTakeoff:
      if ((!(Copy_4_of_laod_arduino_2021_B.switch_manetta != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_equilibratore != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_alettoni != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_timone != 0.0))) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduino_20_IN_In;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardu_IN_Waypoint;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 2.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ar_IN_Vettoriale;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      }
      break;

     case Copy_4_of_laod_arduin_IN_GoHome:
      if ((!(Copy_4_of_laod_arduino_2021_B.switch_manetta != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_equilibratore != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_alettoni != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_timone != 0.0))) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduino_20_IN_In;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 1.0;
      }
      break;

     case Copy_4_of_laod_arduino_20_IN_In:
      Copy_4_of_laod_arduino_2021_In(&Ap_sel,
        &Copy_4_of_laod_arduino_2021_B.Go_home_selector,
        &Copy_4_of_laod_arduino_2021_B.Al_selector,
        &Copy_4_of_laod_arduino_2021_B.Ato_selector,
        &Copy_4_of_laod_arduino_2021_B.Vec_selector,
        &Copy_4_of_laod_arduino_2021_B.Wp_selector);
      break;

     case Copy_4_of_laod_ar_IN_Vettoriale:
      if ((!(Copy_4_of_laod_arduino_2021_B.switch_manetta != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_equilibratore != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_alettoni != 0.0)) ||
          (!(Copy_4_of_laod_arduino_2021_B.switch_timone != 0.0))) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduino_20_IN_In;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 1.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_ardu_IN_Waypoint;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 5.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_arduin_IN_GoHome;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 1.0;
      } else if (Copy_4_of_laod_arduino_2021_B.modo == 4.0) {
        Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 =
          Copy_4_of_laod_a_IN_AutoLanding;
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.Wp_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Vec_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.Ato_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
      }
      break;

     default:
      /* case IN_Waypoint: */
      Copy_4_of_laod_arduino_Waypoint(&Ap_sel,
        &Copy_4_of_laod_arduino_2021_B.Go_home_selector,
        &Copy_4_of_laod_arduino_2021_B.Al_selector,
        &Copy_4_of_laod_arduino_2021_B.Ato_selector,
        &Copy_4_of_laod_arduino_2021_B.Vec_selector,
        &Copy_4_of_laod_arduino_2021_B.Wp_selector);
      break;
    }
  }

  /* End of Chart: '<S41>/Chart' */

  /* Outputs for Enabled SubSystem: '<S41>/DECOLLO AUTOMATICO' incorporates:
   *  EnablePort: '<S440>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.Ato_selector > 0.0) {
    /* Outputs for Triggered SubSystem: '<S440>/Sample and Hold' incorporates:
     *  TriggerPort: '<S448>/Trigger'
     */
    /* Memory: '<S440>/Memory' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &Copy_4_of_laod_arduino__PrevZCX.SampleandHold_Trig_ZCE_h,
             (Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_i));

    /* End of Outputs for SubSystem: '<S440>/Sample and Hold' */

    /* Outputs for Triggered SubSystem: '<S440>/Sample and Hold1' incorporates:
     *  TriggerPort: '<S449>/Trigger'
     */
    /* Memory: '<S440>/Memory1' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &Copy_4_of_laod_arduino__PrevZCX.SampleandHold1_Trig_ZCE,
             (Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_o));

    /* End of Outputs for SubSystem: '<S440>/Sample and Hold1' */

    /* Chart: '<S440>/Chart1' incorporates:
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     */
    if (Copy_4_of_laod_arduino_2021_DW.temporalCounter_i1 < 255U) {
      Copy_4_of_laod_arduino_2021_DW.temporalCounter_i1++;
    }

    if (Copy_4_of_laod_arduino_2021_DW.is_active_c1_Copy_4_of_laod_ard == 0U) {
      Copy_4_of_laod_arduino_2021_DW.is_active_c1_Copy_4_of_laod_ard = 1U;
      Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20 =
        Copy_4_of_laod_ar_IN_Fase_0_ATO;
    } else {
      switch (Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20) {
       case Copy_4_of_laod_ar_IN_Fase_0_ATO:
        if (Copy_4_of_laod_arduino_2021_B.modo == 3.0) {
          Copy_4_of_laod_arduino_2021_B.psi_ref_selector = 1.0;
          Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20 =
            Copy_4_of_laod_ar_IN_Fase_1_ATO;
          Copy_4_of_laod_arduino_2021_DW.temporalCounter_i1 = 0U;
        } else {
          Copy_4_of_laod_arduino_2021_B.Fase_ATO = 0.0;
          Copy_4_of_laod_arduino_2021_B.psi_ref_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.theta_ground_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.eq_rot = 0.0;
          Copy_4_of_laod_arduino_2021_B.h_ref = 0.0;
        }
        break;

       case Copy_4_of_laod_ar_IN_Fase_1_ATO:
        if (Copy_4_of_laod_arduino_2021_DW.temporalCounter_i1 >= 250) {
          Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20 =
            Copy_4_of_laod_ar_IN_Fase_2_ATO;
        } else {
          Copy_4_of_laod_arduino_2021_B.Fase_ATO = 1.0;
          Copy_4_of_laod_arduino_2021_B.psi_ref_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.h_ref = 0.0;
          Copy_4_of_laod_arduino_2021_B.eq_rot = 2.0;
        }
        break;

       case Copy_4_of_laod_ar_IN_Fase_2_ATO:
        if ((Copy_4_of_laod_arduino_2021_B.Product1 >= 18.0) &&
            (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 >= 10.0)) {
          Copy_4_of_laod_arduino_2021_B.theta_ground_selector = 1.0;
          Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20 =
            Copy_4_of_laod_ar_IN_Fase_3_ATO;
        } else {
          Copy_4_of_laod_arduino_2021_B.Fase_ATO = 2.0;
          Copy_4_of_laod_arduino_2021_B.psi_ref_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.h_ref = 0.0;
          Copy_4_of_laod_arduino_2021_B.eq_rot = 2.0;
        }
        break;

       case Copy_4_of_laod_ar_IN_Fase_3_ATO:
        if (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] >= 2.0F) {
          Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20 =
            Copy_4_of_laod_ar_IN_Fase_4_ATO;
        } else {
          Copy_4_of_laod_arduino_2021_B.Fase_ATO = 3.0;
          Copy_4_of_laod_arduino_2021_B.psi_ref_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.theta_ground_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.h_ref = 0.0;
        }
        break;

       default:
        /* case IN_Fase_4_ATO: */
        Copy_4_of_laod_arduino_2021_B.Fase_ATO = 4.0;
        Copy_4_of_laod_arduino_2021_B.psi_ref_selector = 0.0;
        Copy_4_of_laod_arduino_2021_B.h_ref = 35.0;
        break;
      }
    }

    /* End of Chart: '<S440>/Chart1' */

    /* Update for Memory: '<S440>/Memory' */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_i =
      Copy_4_of_laod_arduino_2021_B.psi_ref_selector;

    /* Update for Memory: '<S440>/Memory1' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_o =
      Copy_4_of_laod_arduino_2021_B.theta_ground_selector;
  }

  /* End of Outputs for SubSystem: '<S41>/DECOLLO AUTOMATICO' */

  /* MultiPortSwitch: '<S310>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S40>/MATLAB Function'
   */
  if (Copy_4_of_laod_arduino_2021_B.ATO != 0) {
    /* MultiPortSwitch: '<S310>/Multiport Switch1' incorporates:
     *  Gain: '<S359>/Gain1'
     */
    switch ((int32_T)Copy_4_of_laod_arduino_2021_B.Fase_ATO) {
     case 0:
      Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 =
        Copy_4_of_laod_arduino_2021_P.Gain1_Gain_jm *
        Copy_4_of_laod_arduino_2021_B.eq_rot;
      break;

     case 1:
      Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 =
        Copy_4_of_laod_arduino_2021_P.Gain1_Gain_jm *
        Copy_4_of_laod_arduino_2021_B.eq_rot;
      break;

     case 2:
      Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 =
        Copy_4_of_laod_arduino_2021_P.Gain1_Gain_jm *
        Copy_4_of_laod_arduino_2021_B.eq_rot;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S310>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S310>/Multiport Switch2' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 1' incorporates:
   *  Gain: '<S39>/Gain'
   */
  if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_equilibratore != 0) {
    /* MultiPortSwitch: '<S304>/Switch 1' incorporates:
     *  Abs: '<S304>/Abs1'
     *  Constant: '<S304>/Constant1'
     *  Constant: '<S304>/Constant2'
     *  Constant: '<S304>/Constant3'
     *  Constant: '<S8>/Kp controllore velocità beccheggio1'
     *  Gain: '<S304>/Gain'
     *  MultiPortSwitch: '<S304>/Switch  2'
     *  Product: '<S304>/Product3'
     *  Product: '<S304>/Product4'
     *  Product: '<S304>/Product5'
     *  Sum: '<S304>/Sum3'
     *  Trigonometry: '<S304>/Trigonometric Function'
     */
    if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_equilibratore == 0) {
      Copy_4_of_laod_arduino_2021_B.Sum3_o =
        Copy_4_of_laod_arduino_2021_P.Constant1_Value_fj;
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_P.Constant2_Value_i4;
    } else {
      /* Abs: '<S304>/Abs1' incorporates:
       *  Abs: '<S304>/Abs'
       */
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = fabs
        (Copy_4_of_laod_arduino_2021_B.Gain1_j);
      Copy_4_of_laod_arduino_2021_B.Sum3_o =
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[4] - sin
         (Copy_4_of_laod_arduino_2021_B.deltafalllimit) *
         Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[5]) *
        Copy_4_of_laod_arduino_2021_P.Kp_q;
      Copy_4_of_laod_arduino_2021_B.deltafalllimit *=
        Copy_4_of_laod_arduino_2021_P.inv_comp_h *
        Copy_4_of_laod_arduino_2021_P.Kp_comp_h;
    }

    /* End of MultiPortSwitch: '<S304>/Switch 1' */

    /* Sum: '<S304>/Sum2' incorporates:
     *  Sum: '<S304>/Sum'
     */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      (Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 -
       Copy_4_of_laod_arduino_2021_B.Sum3_o) -
      Copy_4_of_laod_arduino_2021_B.deltafalllimit;

    /* Saturate: '<S304>/saturatore E2' */
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >
        Copy_4_of_laod_arduino_2021_P.attuatore_Emax) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_P.attuatore_Emax;
    } else {
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit <
          Copy_4_of_laod_arduino_2021_P.attuatore_Emin) {
        Copy_4_of_laod_arduino_2021_B.deltafalllimit =
          Copy_4_of_laod_arduino_2021_P.attuatore_Emin;
      }
    }

    /* End of Saturate: '<S304>/saturatore E2' */
    Copy_4_of_laod_arduino_2021_B.Sum3_o = Copy_4_of_laod_arduino_2021_P.inv_E *
      Copy_4_of_laod_arduino_2021_B.deltafalllimit;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 1' */

  /* Sum: '<S31>/Sum' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.Gain3 =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_od *
    Copy_4_of_laod_arduino_2021_B.Sum3_o +
    Copy_4_of_laod_arduino_2021_P.Constant2_Value_m;

  /* S-Function (PWMinterrupt_aileron_v4_4): '<S9>/S-Function Builder7' */
  PWMinterrupt_aileron_v4_4_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.PWM_aileron);

  /* Product: '<S585>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion14'
   *  DataTypeConversion: '<S9>/Data Type Conversion8'
   *  DataTypeConversion: '<S9>/Data Type Conversion9'
   *  Product: '<S586>/Divide'
   *  Product: '<S591>/Multiply'
   *  Sum: '<S585>/Sum'
   *  Sum: '<S585>/Sum1'
   */
  Copy_4_of_laod_arduino_2021_B.Ato_selector =
    Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[4] -
    Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[5];
  Copy_4_of_laod_arduino_2021_B.Sum_o = (real_T)
    (Copy_4_of_laod_arduino_2021_B.PWM_aileron -
     Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[5]) /
    Copy_4_of_laod_arduino_2021_B.Ato_selector;

  /* Sum: '<S585>/Sum2' incorporates:
   *  Constant: '<S585>/Constant8'
   *  Constant: '<S585>/Constant9'
   *  Sum: '<S591>/Sum1'
   */
  Copy_4_of_laod_arduino_2021_B.rtb_Sum3_b_tmp =
    Copy_4_of_laod_arduino_2021_P.attuatore_Amax -
    Copy_4_of_laod_arduino_2021_P.attuatore_Amin;

  /* Sum: '<S585>/Sum3' incorporates:
   *  Constant: '<S585>/Constant9'
   *  Product: '<S585>/Divide'
   *  Product: '<S585>/Multiply'
   *  Sum: '<S585>/Sum2'
   */
  Copy_4_of_laod_arduino_2021_B.Sum3_b = Copy_4_of_laod_arduino_2021_B.Sum_o *
    Copy_4_of_laod_arduino_2021_B.rtb_Sum3_b_tmp +
    Copy_4_of_laod_arduino_2021_P.attuatore_Amin;

  /* Gain: '<S586>/Gain' incorporates:
   *  Constant: '<S586>/Constant8'
   *  Constant: '<S586>/Constant9'
   *  Product: '<S586>/Multiply'
   *  Sum: '<S586>/Sum2'
   *  Sum: '<S586>/Sum3'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    (Copy_4_of_laod_arduino_2021_B.Sum_o *
     (Copy_4_of_laod_arduino_2021_P.phi_max -
      Copy_4_of_laod_arduino_2021_P.phi_min) +
     Copy_4_of_laod_arduino_2021_P.phi_min) *
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_a;

  /* Saturate: '<S586>/Saturation' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >
      Copy_4_of_laod_arduino_2021_P.phi_max) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_P.phi_max;
  } else {
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit <
        Copy_4_of_laod_arduino_2021_P.phi_min) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_P.phi_min;
    }
  }

  /* End of Saturate: '<S586>/Saturation' */

  /* Sum: '<S39>/Sum5' */
  Copy_4_of_laod_arduino_2021_B.Gain1_j =
    Copy_4_of_laod_arduino_2021_B.deltafalllimit -
    Copy_4_of_laod_arduino_2021_B.Gain1_j;

  /* Sum: '<S305>/Sum' incorporates:
   *  Constant: '<S305>/Constant3'
   */
  Copy_4_of_laod_arduino_2021_B.Sum_o = Copy_4_of_laod_arduino_2021_B.Fase_ATO -
    Copy_4_of_laod_arduino_2021_P.Constant3_Value_cr;

  /* DiscreteIntegrator: '<S392>/Integrator' */
  if ((Copy_4_of_laod_arduino_2021_B.Sum_o > 0.0) &&
      (Copy_4_of_laod_arduino_2021_DW.Integrator_PrevResetState <= 0)) {
    Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE_p =
      Copy_4_of_laod_arduino_2021_P.PIDController_InitialConditio_d;
  }

  /* Sum: '<S401>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore  rollio3'
   *  DiscreteIntegrator: '<S392>/Integrator'
   *  Product: '<S397>/PProd Out'
   */
  Copy_4_of_laod_arduino_2021_B.Sum_n3 = Copy_4_of_laod_arduino_2021_B.Gain1_j *
    Copy_4_of_laod_arduino_2021_P.Kp_roll +
    Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE_p;

  /* Saturate: '<S399>/Saturation' */
  if (Copy_4_of_laod_arduino_2021_B.Sum_n3 >
      Copy_4_of_laod_arduino_2021_P.attuatore_Amax) {
    Copy_4_of_laod_arduino_2021_B.Saturation_f =
      Copy_4_of_laod_arduino_2021_P.attuatore_Amax;
  } else if (Copy_4_of_laod_arduino_2021_B.Sum_n3 <
             Copy_4_of_laod_arduino_2021_P.attuatore_Amin) {
    Copy_4_of_laod_arduino_2021_B.Saturation_f =
      Copy_4_of_laod_arduino_2021_P.attuatore_Amin;
  } else {
    Copy_4_of_laod_arduino_2021_B.Saturation_f =
      Copy_4_of_laod_arduino_2021_B.Sum_n3;
  }

  /* End of Saturate: '<S399>/Saturation' */

  /* MultiPortSwitch: '<S305>/Switch Bumpless 1' incorporates:
   *  Constant: '<S305>/Constant1'
   *  Constant: '<S8>/Kp controllore  velocità rollio3'
   *  Product: '<S305>/Product3'
   */
  if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_alettoni == 0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_P.Constant1_Value_ng;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[3] *
      Copy_4_of_laod_arduino_2021_P.Kp_p;
  }

  /* End of MultiPortSwitch: '<S305>/Switch Bumpless 1' */

  /* Sum: '<S305>/Sum2' */
  Copy_4_of_laod_arduino_2021_B.Sum2_o =
    Copy_4_of_laod_arduino_2021_B.Saturation_f -
    Copy_4_of_laod_arduino_2021_B.deltafalllimit;

  /* MultiPortSwitch: '<S39>/Switch Bumpless 3' incorporates:
   *  Saturate: '<S39>/saturatore A1'
   */
  if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_alettoni == 0) {
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p =
      Copy_4_of_laod_arduino_2021_B.Sum3_b;
  } else if (Copy_4_of_laod_arduino_2021_B.Sum2_o >
             Copy_4_of_laod_arduino_2021_P.attuatore_Amax) {
    /* Saturate: '<S39>/saturatore A1' */
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p =
      Copy_4_of_laod_arduino_2021_P.attuatore_Amax;
  } else if (Copy_4_of_laod_arduino_2021_B.Sum2_o <
             Copy_4_of_laod_arduino_2021_P.attuatore_Amin) {
    /* Saturate: '<S39>/saturatore A1' */
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p =
      Copy_4_of_laod_arduino_2021_P.attuatore_Amin;
  } else {
    /* Saturate: '<S39>/saturatore A1' */
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p =
      Copy_4_of_laod_arduino_2021_B.Sum2_o;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 3' */

  /* Saturate: '<S39>/saturatore A' */
  if (Copy_4_of_laod_arduino_2021_B.PWM_rudder_p >
      Copy_4_of_laod_arduino_2021_P.attuatore_Amax) {
    Copy_4_of_laod_arduino_2021_B.Alettoni =
      Copy_4_of_laod_arduino_2021_P.attuatore_Amax;
  } else if (Copy_4_of_laod_arduino_2021_B.PWM_rudder_p <
             Copy_4_of_laod_arduino_2021_P.attuatore_Amin) {
    Copy_4_of_laod_arduino_2021_B.Alettoni =
      Copy_4_of_laod_arduino_2021_P.attuatore_Amin;
  } else {
    Copy_4_of_laod_arduino_2021_B.Alettoni =
      Copy_4_of_laod_arduino_2021_B.PWM_rudder_p;
  }

  /* End of Saturate: '<S39>/saturatore A' */

  /* MultiPortSwitch: '<S39>/Switch Bumpless 5' incorporates:
   *  Gain: '<S39>/Gain1'
   */
  if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_alettoni == 0) {
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p =
      Copy_4_of_laod_arduino_2021_B.Sum3_b;
  } else {
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p =
      Copy_4_of_laod_arduino_2021_P.inv_A *
      Copy_4_of_laod_arduino_2021_B.Alettoni;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 5' */

  /* Sum: '<S31>/Sum1' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S33>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.Switch_bk =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_i *
    Copy_4_of_laod_arduino_2021_B.PWM_rudder_p +
    Copy_4_of_laod_arduino_2021_P.Constant2_Value_m;

  /* S-Function (PWMinterrupt_rudder_v4_4): '<S9>/S-Function Builder8' */
  PWMinterrupt_rudder_v4_4_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.PWM_rudder);

  /* DiscreteTransferFcn: '<S306>/Discrete Washout Filter' */
  Copy_4_of_laod_arduino_2021_B.denAccum =
    (Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[5] -
     Copy_4_of_laod_arduino_2021_P.DiscreteWashoutFilter_DenCoef[1] *
     Copy_4_of_laod_arduino_2021_DW.DiscreteWashoutFilter_states) /
    Copy_4_of_laod_arduino_2021_P.DiscreteWashoutFilter_DenCoef[0];

  /* MultiPortSwitch: '<S39>/Switch Bumpless 6' incorporates:
   *  Constant: '<S589>/Constant8'
   *  Constant: '<S589>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion10'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  DataTypeConversion: '<S9>/Data Type Conversion15'
   *  Gain: '<S39>/Gain2'
   *  MultiPortSwitch: '<S39>/Switch Bumpless 4'
   *  Product: '<S589>/Divide'
   *  Product: '<S589>/Multiply'
   *  Sum: '<S589>/Sum1'
   *  Sum: '<S589>/Sum2'
   *  Sum: '<S589>/Sum3'
   *  Sum: '<S589>/Sum4'
   */
  if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_timone == 0) {
    Copy_4_of_laod_arduino_2021_B.Sum2_o = (real_T)
      (Copy_4_of_laod_arduino_2021_B.PWM_rudder -
       Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[7]) /
      (real_T)(Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack
               [6] -
               Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack
               [7]) * (Copy_4_of_laod_arduino_2021_P.attuatore_Rmax -
                       Copy_4_of_laod_arduino_2021_P.attuatore_Rmin) +
      Copy_4_of_laod_arduino_2021_P.attuatore_Rmin;
  } else {
    if ((int32_T)Copy_4_of_laod_arduino_2021_B.switch_timone == 0) {
      /* MultiPortSwitch: '<S39>/Switch Bumpless 4' incorporates:
       *  Constant: '<S589>/Constant8'
       *  Constant: '<S589>/Constant9'
       *  DataTypeConversion: '<S9>/Data Type Conversion10'
       *  DataTypeConversion: '<S9>/Data Type Conversion11'
       *  DataTypeConversion: '<S9>/Data Type Conversion15'
       *  Product: '<S589>/Divide'
       *  Product: '<S589>/Multiply'
       *  Sum: '<S589>/Sum1'
       *  Sum: '<S589>/Sum2'
       *  Sum: '<S589>/Sum3'
       *  Sum: '<S589>/Sum4'
       */
      Copy_4_of_laod_arduino_2021_B.Sum2_o = (real_T)
        (Copy_4_of_laod_arduino_2021_B.PWM_rudder -
         Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[7]) /
        (real_T)
        (Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[6] -
         Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[7]) *
        (Copy_4_of_laod_arduino_2021_P.attuatore_Rmax -
         Copy_4_of_laod_arduino_2021_P.attuatore_Rmin) +
        Copy_4_of_laod_arduino_2021_P.attuatore_Rmin;
    } else {
      /* MultiPortSwitch: '<S39>/Switch Bumpless 4' incorporates:
       *  Constant: '<S39>/r_rif'
       *  Constant: '<S8>/K controllo imbardata inversa'
       *  Constant: '<S8>/Kp controllore imbardata'
       *  DiscreteTransferFcn: '<S306>/Discrete Washout Filter'
       *  Gain: '<S8>/Gain3'
       *  Product: '<S39>/  CONTROLLO     IMBARDATA      INVERSA'
       *  Product: '<S39>/Product'
       *  Sum: '<S39>/Sum1'
       *  Sum: '<S39>/Sum9'
       */
      Copy_4_of_laod_arduino_2021_B.Sum2_o =
        (Copy_4_of_laod_arduino_2021_P.r_rif_Value -
         (Copy_4_of_laod_arduino_2021_P.DiscreteWashoutFilter_NumCoef[0] *
          Copy_4_of_laod_arduino_2021_B.denAccum +
          Copy_4_of_laod_arduino_2021_P.DiscreteWashoutFilter_NumCoef[1] *
          Copy_4_of_laod_arduino_2021_DW.DiscreteWashoutFilter_states)) *
        Copy_4_of_laod_arduino_2021_P.Kp_imb + (real_T)
        (Copy_4_of_laod_arduino_2021_P.Gain3_Gain_o *
         Copy_4_of_laod_arduino_2021_P.K_imb_inv) * 0.0078125 *
        Copy_4_of_laod_arduino_2021_B.Sum2_o;
    }

    /* Saturate: '<S39>/saturatore R' */
    if (Copy_4_of_laod_arduino_2021_B.Sum2_o >
        Copy_4_of_laod_arduino_2021_P.attuatore_Rmax) {
      Copy_4_of_laod_arduino_2021_B.Sum2_o =
        Copy_4_of_laod_arduino_2021_P.attuatore_Rmax;
    } else {
      if (Copy_4_of_laod_arduino_2021_B.Sum2_o <
          Copy_4_of_laod_arduino_2021_P.attuatore_Rmin) {
        Copy_4_of_laod_arduino_2021_B.Sum2_o =
          Copy_4_of_laod_arduino_2021_P.attuatore_Rmin;
      }
    }

    /* End of Saturate: '<S39>/saturatore R' */
    Copy_4_of_laod_arduino_2021_B.Sum2_o *= Copy_4_of_laod_arduino_2021_P.inv_R;
  }

  /* End of MultiPortSwitch: '<S39>/Switch Bumpless 6' */

  /* Sum: '<S31>/Sum2' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S34>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_bh *
    Copy_4_of_laod_arduino_2021_B.Sum2_o +
    Copy_4_of_laod_arduino_2021_P.Constant2_Value_m;

  /* Gain: '<S20>/Gain' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion3'
   *  Gain: '<S556>/Gain4'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_P.Gain4_Gain * (real_T)
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o4[1] *
    Copy_4_of_laod_arduino_2021_P.Gain_Gain_jr;

  /* Saturate: '<S20>/Saturation' */
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit >
      Copy_4_of_laod_arduino_2021_P.Saturation_UpperSat) {
    Copy_4_of_laod_arduino_2021_B.IProdOut =
      Copy_4_of_laod_arduino_2021_P.Saturation_UpperSat;
  } else if (Copy_4_of_laod_arduino_2021_B.deltafalllimit <
             Copy_4_of_laod_arduino_2021_P.Saturation_LowerSat) {
    Copy_4_of_laod_arduino_2021_B.IProdOut =
      Copy_4_of_laod_arduino_2021_P.Saturation_LowerSat;
  } else {
    Copy_4_of_laod_arduino_2021_B.IProdOut =
      Copy_4_of_laod_arduino_2021_B.deltafalllimit;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (Copy_4_of_laod_arduino_2021_P.Constant_Value_bh < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_P.Constant_Value_bh);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_P.Constant_Value_bh);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[0] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.Gain2_g < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.Gain2_g);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.Gain2_g);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[1] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.Gain3 < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.Gain3);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.Gain3);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[2] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.Switch_bk < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.Switch_bk);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.Switch_bk);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[3] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[4] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[0] < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[0]);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[0]);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[5] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[1] < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[1]);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[1]);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[6] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[2] < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[2]);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_P.Constant1_Value_pa[2]);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[7] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit =
    Copy_4_of_laod_arduino_2021_B.IProdOut;
  if (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = ceil
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  }

  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.Heading[8] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* Memory: '<S2>/Memory' */
  Copy_4_of_laod_arduino_2021_B.Memory_a =
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_n;

  /* MATLAB Function: '<S569>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S569>/Data Type Conversion'
   *  DataTypeConversion: '<S569>/Data Type Conversion2'
   */
  if (Copy_4_of_laod_arduino_2021_B.SFunction_o14 == 1) {
    Copy_4_of_laod_arduino_2021_DW.P_ref =
      Copy_4_of_laod_arduino_2021_B.SFunctionBuilder1;
  }

  if (Copy_4_of_laod_arduino_2021_B.SFunction_o16 == 1) {
    Copy_4_of_laod_arduino_2021_DW.P_ref =
      Copy_4_of_laod_arduino_2021_B.SFunction_o17;
    Copy_4_of_laod_arduino_2021_DW.rl_up = 20.0;
    Copy_4_of_laod_arduino_2021_DW.rl_dw = -20.0;
  }

  /* Product: '<S572>/delta rise limit' incorporates:
   *  MATLAB Function: '<S569>/MATLAB Function'
   *  SampleTimeMath: '<S572>/sample time'
   *
   * About '<S572>/sample time':
   *  y = K where K = ( w * Ts )
   */
  Copy_4_of_laod_arduino_2021_B.IProdOut = Copy_4_of_laod_arduino_2021_DW.rl_up *
    Copy_4_of_laod_arduino_2021_P.sampletime_WtEt;

  /* Sum: '<S572>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S569>/MATLAB Function'
   *  UnitDelay: '<S572>/Delay Input2'
   *
   * Block description for '<S572>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S572>/Delay Input2':
   *
   *  Store in Global RAM
   */
  Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
    Copy_4_of_laod_arduino_2021_DW.P_ref -
    Copy_4_of_laod_arduino_2021_DW.DelayInput2_DSTATE;

  /* Switch: '<S578>/Switch2' incorporates:
   *  RelationalOperator: '<S578>/LowerRelop1'
   */
  if (!(Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 >
        Copy_4_of_laod_arduino_2021_B.IProdOut)) {
    /* Product: '<S572>/delta fall limit' incorporates:
     *  MATLAB Function: '<S569>/MATLAB Function'
     *  SampleTimeMath: '<S572>/sample time'
     *
     * About '<S572>/sample time':
     *  y = K where K = ( w * Ts )
     */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_DW.rl_dw *
      Copy_4_of_laod_arduino_2021_P.sampletime_WtEt;

    /* Switch: '<S578>/Switch' incorporates:
     *  RelationalOperator: '<S578>/UpperRelop'
     */
    if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 <
        Copy_4_of_laod_arduino_2021_B.deltafalllimit) {
      Copy_4_of_laod_arduino_2021_B.IProdOut =
        Copy_4_of_laod_arduino_2021_B.deltafalllimit;
    } else {
      Copy_4_of_laod_arduino_2021_B.IProdOut =
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;
    }

    /* End of Switch: '<S578>/Switch' */
  }

  /* End of Switch: '<S578>/Switch2' */

  /* Sum: '<S572>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S572>/Delay Input2'
   *
   * Block description for '<S572>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S572>/Delay Input2':
   *
   *  Store in Global RAM
   */
  Copy_4_of_laod_arduino_2021_DW.DelayInput2_DSTATE +=
    Copy_4_of_laod_arduino_2021_B.IProdOut;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S572>/Delay Input2'
   *
   * Block description for '<S572>/Delay Input2':
   *
   *  Store in Global RAM
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion2 = (real32_T)
    Copy_4_of_laod_arduino_2021_DW.DelayInput2_DSTATE;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S569>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_l = (real32_T)
    (Copy_4_of_laod_arduino_2021_P.PatohPa_Gain * (real_T)
     Copy_4_of_laod_arduino_2021_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion2'
   *  Gain: '<S2>/Pa to hPa1'
   *  Gain: '<S556>/Gain1'
   *  Gain: '<S556>/Gain7'
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_g = (real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain1_Gain_p * (real_T)
     Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[2] *
     Copy_4_of_laod_arduino_2021_P.Gain7_Gain *
     Copy_4_of_laod_arduino_2021_P.PatohPa1_Gain);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor
    (Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1);
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_m = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem1' incorporates:
   *  EnablePort: '<S442>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S442>/Data Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i <
         42; Copy_4_of_laod_arduino_2021_B.i++) {
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[Copy_4_of_laod_arduino_2021_B.i]
        =
        Copy_4_of_laod_arduino_2021_DW.WP_dbP_AL[Copy_4_of_laod_arduino_2021_B.i];
    }

    /* End of DataTypeConversion: '<S442>/Data Type Conversion4' */

    /* MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES' incorporates:
     *  DataTypeConversion: '<S442>/Data Type Conversion4'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[30] *
      0.017453292519943295;
    Copy_4_of_laod_arduino_2021_B.h_Home =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[36];
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = cos
      (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[25] *
       0.017453292519943295);
    Copy_4_of_laod_arduino_2021_B.Switch_bk = sin
      (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[24] *
       0.017453292519943295);
    Copy_4_of_laod_arduino_2021_B.Al_selector = cos
      (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[24] *
       0.017453292519943295);
    Copy_4_of_laod_arduino_2021_B.Gain2_g =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[31] *
      0.017453292519943295 -
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[30] *
      0.017453292519943295;
    Copy_4_of_laod_arduino_2021_B.Gain2_g = rt_atan2d_snf(sin
      (Copy_4_of_laod_arduino_2021_B.Gain2_g) *
      Copy_4_of_laod_arduino_2021_B.deltafalllimit, sin
      (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[25] *
       0.017453292519943295) * Copy_4_of_laod_arduino_2021_B.Al_selector - cos
      (Copy_4_of_laod_arduino_2021_B.Gain2_g) *
      (Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.deltafalllimit));
    if (Copy_4_of_laod_arduino_2021_B.Gain2_g < 0.0) {
      Copy_4_of_laod_arduino_2021_B.Gain2_g = 6.2831853071795862 - fabs
        (Copy_4_of_laod_arduino_2021_B.Gain2_g);
    }

    /* MATLAB Function: '<S455>/MATLAB Function' incorporates:
     *  Constant: '<S455>/distance waypoints virtuale'
     *  MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES'
     *  Trigonometry: '<S526>/SinCos'
     */
    Copy_4_of_laod_arduino_2021_B.Gain3 = sin
      (Copy_4_of_laod_arduino_2021_P.distancewaypointsvirtuale_Value[0] /
       6.378137E+6);
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l = cos
      (Copy_4_of_laod_arduino_2021_P.distancewaypointsvirtuale_Value[0] /
       6.378137E+6);
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = cos
      (Copy_4_of_laod_arduino_2021_B.Gain2_g);
    Copy_4_of_laod_arduino_2021_B.Gain_n = asin
      (Copy_4_of_laod_arduino_2021_B.Al_selector *
       Copy_4_of_laod_arduino_2021_B.Gain3 *
       Copy_4_of_laod_arduino_2021_B.deltafalllimit +
       Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l);
    Copy_4_of_laod_arduino_2021_B.Gain2_g = sin
      (Copy_4_of_laod_arduino_2021_B.Gain2_g);

    /* MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S455>/alt waypoint virtuale'
     *  Gain: '<S471>/Gain'
     *  Gain: '<S472>/Gain'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Copy_4_of_laod_arduino_2021_B.WP_param_c[12] =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_es *
      Copy_4_of_laod_arduino_2021_B.Gain_n;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[15] =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_k * (rt_atan2d_snf
      (Copy_4_of_laod_arduino_2021_B.Gain2_g *
       Copy_4_of_laod_arduino_2021_B.Gain3 *
       Copy_4_of_laod_arduino_2021_B.Al_selector,
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l -
       Copy_4_of_laod_arduino_2021_B.Switch_bk * sin
       (Copy_4_of_laod_arduino_2021_B.Gain_n)) +
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0);
    Copy_4_of_laod_arduino_2021_B.WP_param_c[3] = 1.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[6] = 0.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[9] = 0.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[18] =
      Copy_4_of_laod_arduino_2021_B.h_Home +
      Copy_4_of_laod_arduino_2021_P.altwaypointvirtuale_Value[0];

    /* MATLAB Function: '<S455>/MATLAB Function' incorporates:
     *  Constant: '<S455>/distance waypoints virtuale'
     */
    Copy_4_of_laod_arduino_2021_B.Gain3 = sin
      (Copy_4_of_laod_arduino_2021_P.distancewaypointsvirtuale_Value[1] /
       6.378137E+6);
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l = cos
      (Copy_4_of_laod_arduino_2021_P.distancewaypointsvirtuale_Value[1] /
       6.378137E+6);
    Copy_4_of_laod_arduino_2021_B.Gain_n = asin
      (Copy_4_of_laod_arduino_2021_B.Al_selector *
       Copy_4_of_laod_arduino_2021_B.Gain3 *
       Copy_4_of_laod_arduino_2021_B.deltafalllimit +
       Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l);

    /* MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S455>/Constant1'
     *  Constant: '<S455>/alt waypoint virtuale'
     *  Gain: '<S471>/Gain'
     *  Gain: '<S472>/Gain'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Copy_4_of_laod_arduino_2021_B.WP_param_c[13] =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_es *
      Copy_4_of_laod_arduino_2021_B.Gain_n;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[16] =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_k * (rt_atan2d_snf
      (Copy_4_of_laod_arduino_2021_B.Gain2_g *
       Copy_4_of_laod_arduino_2021_B.Gain3 *
       Copy_4_of_laod_arduino_2021_B.Al_selector,
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l -
       Copy_4_of_laod_arduino_2021_B.Switch_bk * sin
       (Copy_4_of_laod_arduino_2021_B.Gain_n)) +
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0);
    Copy_4_of_laod_arduino_2021_B.WP_param_c[1] =
      Copy_4_of_laod_arduino_2021_P.vel_wp2_al;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[4] = 1.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[7] = 0.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[10] = 0.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[19] =
      Copy_4_of_laod_arduino_2021_B.h_Home +
      Copy_4_of_laod_arduino_2021_P.altwaypointvirtuale_Value[1];

    /* MATLAB Function: '<S455>/MATLAB Function' incorporates:
     *  Constant: '<S455>/distance waypoints virtuale'
     */
    Copy_4_of_laod_arduino_2021_B.Gain3 = sin
      (Copy_4_of_laod_arduino_2021_P.distancewaypointsvirtuale_Value[2] /
       6.378137E+6);
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l = cos
      (Copy_4_of_laod_arduino_2021_P.distancewaypointsvirtuale_Value[2] /
       6.378137E+6);
    Copy_4_of_laod_arduino_2021_B.Gain_n = asin
      (Copy_4_of_laod_arduino_2021_B.Al_selector *
       Copy_4_of_laod_arduino_2021_B.Gain3 *
       Copy_4_of_laod_arduino_2021_B.deltafalllimit +
       Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l);

    /* MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S455>/Constant'
     *  Constant: '<S455>/Constant1'
     *  Constant: '<S455>/alt waypoint virtuale'
     *  Gain: '<S471>/Gain'
     *  Gain: '<S472>/Gain'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Copy_4_of_laod_arduino_2021_B.WP_param_c[14] =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_es *
      Copy_4_of_laod_arduino_2021_B.Gain_n;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[17] =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_k * (rt_atan2d_snf
      (Copy_4_of_laod_arduino_2021_B.Gain2_g *
       Copy_4_of_laod_arduino_2021_B.Gain3 *
       Copy_4_of_laod_arduino_2021_B.Al_selector,
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l -
       Copy_4_of_laod_arduino_2021_B.Switch_bk * sin
       (Copy_4_of_laod_arduino_2021_B.Gain_n)) +
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0);
    Copy_4_of_laod_arduino_2021_B.WP_param_c[2] =
      Copy_4_of_laod_arduino_2021_P.vel_wp2_al;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[8] = 0.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[11] = 0.0;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[20] =
      Copy_4_of_laod_arduino_2021_B.h_Home +
      Copy_4_of_laod_arduino_2021_P.altwaypointvirtuale_Value[2];
    Copy_4_of_laod_arduino_2021_B.WP_param_c[0] =
      Copy_4_of_laod_arduino_2021_P.vel_wp1_al;
    Copy_4_of_laod_arduino_2021_B.WP_param_c[5] = 0.0;

    /* Gain: '<S460>/Gain' incorporates:
     *  DataTypeConversion: '<S442>/Data Type Conversion4'
     *  MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES'
     */
    Copy_4_of_laod_arduino_2021_B.Gain =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[24] *
      0.017453292519943295 * Copy_4_of_laod_arduino_2021_P.Gain_Gain_p;

    /* Switch: '<S536>/Switch' incorporates:
     *  Abs: '<S536>/Abs'
     *  Bias: '<S536>/Bias'
     *  Bias: '<S536>/Bias1'
     *  Constant: '<S536>/Constant2'
     *  Constant: '<S537>/Constant'
     *  Math: '<S536>/Math Function1'
     *  RelationalOperator: '<S537>/Compare'
     */
    if (fabs(Copy_4_of_laod_arduino_2021_B.Gain) >
        Copy_4_of_laod_arduino_2021_P.CompareToConstant_const) {
      Copy_4_of_laod_arduino_2021_B.Switch_bk = rt_modd_snf
        (Copy_4_of_laod_arduino_2021_B.Gain +
         Copy_4_of_laod_arduino_2021_P.Bias_Bias_e,
         Copy_4_of_laod_arduino_2021_P.Constant2_Value_n) +
        Copy_4_of_laod_arduino_2021_P.Bias1_Bias_j;
    } else {
      Copy_4_of_laod_arduino_2021_B.Switch_bk =
        Copy_4_of_laod_arduino_2021_B.Gain;
    }

    /* End of Switch: '<S536>/Switch' */

    /* Abs: '<S533>/Abs1' */
    Copy_4_of_laod_arduino_2021_B.Al_selector = fabs
      (Copy_4_of_laod_arduino_2021_B.Switch_bk);

    /* RelationalOperator: '<S535>/Compare' incorporates:
     *  Constant: '<S535>/Constant'
     */
    Ap_sel = (Copy_4_of_laod_arduino_2021_B.Al_selector >
              Copy_4_of_laod_arduino_2021_P.CompareToConstant_const_d);

    /* Gain: '<S461>/Gain' */
    Copy_4_of_laod_arduino_2021_B.Gain_g =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_b2 *
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;

    /* Switch: '<S533>/Switch' incorporates:
     *  Bias: '<S533>/Bias'
     *  Bias: '<S533>/Bias1'
     *  Constant: '<S525>/Constant'
     *  Constant: '<S525>/Constant1'
     *  Gain: '<S533>/Gain'
     *  Product: '<S533>/Divide1'
     *  Switch: '<S525>/Switch1'
     */
    if (Ap_sel) {
      /* Signum: '<S533>/Sign1' */
      if (Copy_4_of_laod_arduino_2021_B.Switch_bk < 0.0) {
        Copy_4_of_laod_arduino_2021_B.Switch_bk = -1.0;
      } else if (Copy_4_of_laod_arduino_2021_B.Switch_bk > 0.0) {
        Copy_4_of_laod_arduino_2021_B.Switch_bk = 1.0;
      } else if (Copy_4_of_laod_arduino_2021_B.Switch_bk == 0.0) {
        Copy_4_of_laod_arduino_2021_B.Switch_bk = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.Switch_bk = (rtNaN);
      }

      /* End of Signum: '<S533>/Sign1' */
      Copy_4_of_laod_arduino_2021_B.Switch_bk *=
        (Copy_4_of_laod_arduino_2021_B.Al_selector +
         Copy_4_of_laod_arduino_2021_P.Bias_Bias_f) *
        Copy_4_of_laod_arduino_2021_P.Gain_Gain_mn +
        Copy_4_of_laod_arduino_2021_P.Bias1_Bias_f;
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
        Copy_4_of_laod_arduino_2021_P.Constant_Value_d;
    } else {
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
        Copy_4_of_laod_arduino_2021_P.Constant1_Value_d5;
    }

    /* End of Switch: '<S533>/Switch' */

    /* Sum: '<S525>/Sum' */
    Copy_4_of_laod_arduino_2021_B.Al_selector =
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 +
      Copy_4_of_laod_arduino_2021_B.Gain_g;

    /* Sum: '<S459>/Sum1' incorporates:
     *  Gain: '<S463>/Gain'
     */
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_f *
      Copy_4_of_laod_arduino_2021_B.Gain1_f -
      Copy_4_of_laod_arduino_2021_B.Switch_bk;

    /* Switch: '<S530>/Switch' incorporates:
     *  Abs: '<S530>/Abs'
     *  Bias: '<S530>/Bias'
     *  Bias: '<S530>/Bias1'
     *  Constant: '<S530>/Constant2'
     *  Constant: '<S531>/Constant'
     *  Math: '<S530>/Math Function1'
     *  RelationalOperator: '<S531>/Compare'
     */
    if (fabs(Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0) >
        Copy_4_of_laod_arduino_2021_P.CompareToConstant_const_b) {
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 = rt_modd_snf
        (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 +
         Copy_4_of_laod_arduino_2021_P.Bias_Bias_n,
         Copy_4_of_laod_arduino_2021_P.Constant2_Value_i) +
        Copy_4_of_laod_arduino_2021_P.Bias1_Bias_n;
    }

    /* End of Switch: '<S530>/Switch' */

    /* Abs: '<S527>/Abs1' */
    Copy_4_of_laod_arduino_2021_B.Gain3 = fabs
      (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0);

    /* Switch: '<S527>/Switch' incorporates:
     *  Bias: '<S527>/Bias'
     *  Bias: '<S527>/Bias1'
     *  Constant: '<S524>/Constant'
     *  Constant: '<S524>/Constant1'
     *  Constant: '<S529>/Constant'
     *  Gain: '<S527>/Gain'
     *  Product: '<S527>/Divide1'
     *  RelationalOperator: '<S529>/Compare'
     *  Switch: '<S524>/Switch1'
     */
    if (Copy_4_of_laod_arduino_2021_B.Gain3 >
        Copy_4_of_laod_arduino_2021_P.CompareToConstant_const_dp) {
      /* Signum: '<S527>/Sign1' */
      if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 < 0.0) {
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 = -1.0;
      } else if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 > 0.0) {
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 = 1.0;
      } else if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 == 0.0) {
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 = 0.0;
      } else {
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 = (rtNaN);
      }

      /* End of Signum: '<S527>/Sign1' */
      Copy_4_of_laod_arduino_2021_B.IProdOut =
        ((Copy_4_of_laod_arduino_2021_B.Gain3 +
          Copy_4_of_laod_arduino_2021_P.Bias_Bias) *
         Copy_4_of_laod_arduino_2021_P.Gain_Gain_b +
         Copy_4_of_laod_arduino_2021_P.Bias1_Bias) *
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
        Copy_4_of_laod_arduino_2021_P.Constant_Value_n;
    } else {
      Copy_4_of_laod_arduino_2021_B.IProdOut =
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
        Copy_4_of_laod_arduino_2021_P.Constant1_Value_p;
    }

    /* End of Switch: '<S527>/Switch' */

    /* Switch: '<S534>/Switch' incorporates:
     *  Abs: '<S534>/Abs'
     *  Bias: '<S534>/Bias'
     *  Bias: '<S534>/Bias1'
     *  Constant: '<S534>/Constant2'
     *  Constant: '<S538>/Constant'
     *  Math: '<S534>/Math Function1'
     *  RelationalOperator: '<S538>/Compare'
     */
    if (fabs(Copy_4_of_laod_arduino_2021_B.Al_selector) >
        Copy_4_of_laod_arduino_2021_P.CompareToConstant_const_p) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = rt_modd_snf
        (Copy_4_of_laod_arduino_2021_B.Al_selector +
         Copy_4_of_laod_arduino_2021_P.Bias_Bias_jc,
         Copy_4_of_laod_arduino_2021_P.Constant2_Value_b) +
        Copy_4_of_laod_arduino_2021_P.Bias1_Bias_gb;
    }

    /* End of Switch: '<S534>/Switch' */

    /* Sum: '<S524>/Sum' incorporates:
     *  Gain: '<S462>/Gain'
     *  Sum: '<S459>/Sum1'
     */
    Copy_4_of_laod_arduino_2021_B.Al_selector =
      (Copy_4_of_laod_arduino_2021_P.Gain_Gain_d *
       Copy_4_of_laod_arduino_2021_B.Gain1_p -
       Copy_4_of_laod_arduino_2021_B.Al_selector) +
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;

    /* Gain: '<S523>/Gain1' */
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
      Copy_4_of_laod_arduino_2021_P.Gain1_Gain *
      Copy_4_of_laod_arduino_2021_B.IProdOut;

    /* Sum: '<S541>/Sum' incorporates:
     *  Constant: '<S541>/Constant'
     *  Constant: '<S541>/f'
     */
    Copy_4_of_laod_arduino_2021_B.IProdOut =
      Copy_4_of_laod_arduino_2021_P.f_Value -
      Copy_4_of_laod_arduino_2021_P.Constant_Value_j;

    /* Sqrt: '<S542>/Sqrt' incorporates:
     *  Constant: '<S542>/Constant4'
     *  Product: '<S542>/Product'
     *  Sum: '<S542>/Sum'
     */
    Copy_4_of_laod_arduino_2021_B.IProdOut = sqrt
      (Copy_4_of_laod_arduino_2021_P.Constant4_Value_o -
       Copy_4_of_laod_arduino_2021_B.IProdOut *
       Copy_4_of_laod_arduino_2021_B.IProdOut);

    /* Gain: '<S540>/Gain1' */
    Copy_4_of_laod_arduino_2021_B.Switch_bk *=
      Copy_4_of_laod_arduino_2021_P.Gain1_Gain_j;

    /* Trigonometry: '<S543>/Trigonometric Function1' */
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l = sin
      (Copy_4_of_laod_arduino_2021_B.Switch_bk);

    /* Sum: '<S543>/Sum1' incorporates:
     *  Constant: '<S543>/Constant'
     *  Product: '<S543>/Product1'
     */
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
      Copy_4_of_laod_arduino_2021_P.Constant_Value_nw -
      Copy_4_of_laod_arduino_2021_B.IProdOut *
      Copy_4_of_laod_arduino_2021_B.IProdOut *
      Copy_4_of_laod_arduino_2021_B.PWM_elevator_l *
      Copy_4_of_laod_arduino_2021_B.PWM_elevator_l;

    /* Product: '<S539>/Product1' incorporates:
     *  Constant: '<S539>/Constant1'
     *  Sqrt: '<S539>/sqrt'
     */
    Copy_4_of_laod_arduino_2021_B.Gain3 =
      Copy_4_of_laod_arduino_2021_P.Constant1_Value_j / sqrt
      (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l);

    /* Switch: '<S528>/Switch' incorporates:
     *  Abs: '<S528>/Abs'
     *  Bias: '<S528>/Bias'
     *  Bias: '<S528>/Bias1'
     *  Constant: '<S528>/Constant2'
     *  Constant: '<S532>/Constant'
     *  Math: '<S528>/Math Function1'
     *  RelationalOperator: '<S532>/Compare'
     */
    if (fabs(Copy_4_of_laod_arduino_2021_B.Al_selector) >
        Copy_4_of_laod_arduino_2021_P.CompareToConstant_const_g) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = rt_modd_snf
        (Copy_4_of_laod_arduino_2021_B.Al_selector +
         Copy_4_of_laod_arduino_2021_P.Bias_Bias_j,
         Copy_4_of_laod_arduino_2021_P.Constant2_Value_gk) +
        Copy_4_of_laod_arduino_2021_P.Bias1_Bias_g;
    }

    /* End of Switch: '<S528>/Switch' */

    /* Sum: '<S526>/Sum2' incorporates:
     *  Constant: '<S539>/Constant'
     *  Constant: '<S539>/Constant2'
     *  Constant: '<S539>/Constant3'
     *  Gain: '<S523>/Gain1'
     *  Product: '<S526>/dEast'
     *  Product: '<S526>/dNorth'
     *  Product: '<S526>/x*cos'
     *  Product: '<S526>/y*sin'
     *  Product: '<S539>/Product2'
     *  Product: '<S539>/Product3'
     *  Product: '<S539>/Product4'
     *  Sum: '<S539>/Sum1'
     *  Trigonometry: '<S539>/Trigonometric Function'
     *  Trigonometry: '<S539>/Trigonometric Function1'
     *  Trigonometry: '<S539>/Trigonometric Function2'
     */
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 / rt_atan2d_snf
      (Copy_4_of_laod_arduino_2021_P.Constant2_Value_j,
       (Copy_4_of_laod_arduino_2021_P.Constant_Value_h -
        Copy_4_of_laod_arduino_2021_B.IProdOut *
        Copy_4_of_laod_arduino_2021_B.IProdOut) *
       Copy_4_of_laod_arduino_2021_B.Gain3 /
       Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) *
      Copy_4_of_laod_arduino_2021_B.deltafalllimit + 1.0 / rt_atan2d_snf
      (Copy_4_of_laod_arduino_2021_P.Constant3_Value_f,
       Copy_4_of_laod_arduino_2021_B.Gain3 * cos
       (Copy_4_of_laod_arduino_2021_B.Switch_bk)) *
      (Copy_4_of_laod_arduino_2021_P.Gain1_Gain *
       Copy_4_of_laod_arduino_2021_B.Al_selector) *
      Copy_4_of_laod_arduino_2021_B.Gain2_g;

    /* Gain: '<S464>/Gain' */
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_o *
      Copy_4_of_laod_arduino_2021_B.Gain1_f;

    /* Gain: '<S465>/Gain' */
    Copy_4_of_laod_arduino_2021_B.Gain_n =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_ov *
      Copy_4_of_laod_arduino_2021_B.Gain1_p;

    /* MATLAB Function: '<S442>/ALLINEAMENTO' incorporates:
     *  Memory: '<S442>/Memory7'
     */
    Copy_4_of_laod_arduino_2021_B.b_a_tmp =
      Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
      Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 11];
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = sin
      ((Copy_4_of_laod_arduino_2021_B.b_a_tmp -
        Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) * 3.1415926535897931 /
       180.0 / 2.0);
    Copy_4_of_laod_arduino_2021_B.dist_fut =
      Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
      Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 14];
    Copy_4_of_laod_arduino_2021_B.dist = (Copy_4_of_laod_arduino_2021_B.dist_fut
      - Copy_4_of_laod_arduino_2021_B.Gain_n) * 3.1415926535897931 / 180.0;
    Copy_4_of_laod_arduino_2021_B.Switch_bk = sin
      (Copy_4_of_laod_arduino_2021_B.dist / 2.0);
    Copy_4_of_laod_arduino_2021_B.Al_selector =
      Copy_4_of_laod_arduino_2021_B.b_a_tmp * 3.1415926535897931 / 180.0;
    Copy_4_of_laod_arduino_2021_B.Gain3 = cos
      (Copy_4_of_laod_arduino_2021_B.Al_selector);
    Copy_4_of_laod_arduino_2021_B.a_tmp_tmp =
      Copy_4_of_laod_arduino_2021_B.PWM_elevator_l * 3.1415926535897931 / 180.0;
    Copy_4_of_laod_arduino_2021_B.Gain2_g = cos
      (Copy_4_of_laod_arduino_2021_B.a_tmp_tmp);
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_B.Gain2_g *
      Copy_4_of_laod_arduino_2021_B.Gain3 *
      (Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.Switch_bk) +
      Copy_4_of_laod_arduino_2021_B.deltafalllimit *
      Copy_4_of_laod_arduino_2021_B.deltafalllimit;
    Copy_4_of_laod_arduino_2021_B.Switch_bk = rt_atan2d_snf(sqrt
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit), sqrt(1.0 -
      Copy_4_of_laod_arduino_2021_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    if (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput > 1.0) {
      Copy_4_of_laod_arduino_2021_B.a_tmp_tmp =
        Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 11];
      Copy_4_of_laod_arduino_2021_B.Al_selector =
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = cos
        (Copy_4_of_laod_arduino_2021_B.Al_selector);
      Copy_4_of_laod_arduino_2021_B.dist =
        Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 14];
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        (Copy_4_of_laod_arduino_2021_B.dist_fut -
         Copy_4_of_laod_arduino_2021_B.dist) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Al_selector = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp) *
        Copy_4_of_laod_arduino_2021_B.Gain3, sin
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 11] *
         3.1415926535897931 / 180.0) *
        Copy_4_of_laod_arduino_2021_B.deltafalllimit - sin
        (Copy_4_of_laod_arduino_2021_B.Al_selector) *
        Copy_4_of_laod_arduino_2021_B.Gain3 * cos
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      Copy_4_of_laod_arduino_2021_B.a_tmp_tmp = sin
        ((Copy_4_of_laod_arduino_2021_B.PWM_elevator_l -
          Copy_4_of_laod_arduino_2021_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 /
         2.0);
      Copy_4_of_laod_arduino_2021_B.dist = sin
        ((Copy_4_of_laod_arduino_2021_B.Gain_n -
          Copy_4_of_laod_arduino_2021_B.dist) * 3.1415926535897931 / 180.0 / 2.0);
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_B.deltafalllimit *
        Copy_4_of_laod_arduino_2021_B.Gain2_g *
        (Copy_4_of_laod_arduino_2021_B.dist * Copy_4_of_laod_arduino_2021_B.dist)
        + Copy_4_of_laod_arduino_2021_B.a_tmp_tmp *
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp;
      Copy_4_of_laod_arduino_2021_B.dist = rt_atan2d_snf(sqrt
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit), sqrt(1.0 -
        Copy_4_of_laod_arduino_2021_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    } else {
      Copy_4_of_laod_arduino_2021_B.Al_selector = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.dist) *
        Copy_4_of_laod_arduino_2021_B.Gain3, sin
        (Copy_4_of_laod_arduino_2021_B.Al_selector) *
        Copy_4_of_laod_arduino_2021_B.Gain2_g - cos
        (Copy_4_of_laod_arduino_2021_B.dist) * (sin
        (Copy_4_of_laod_arduino_2021_B.a_tmp_tmp) *
        Copy_4_of_laod_arduino_2021_B.Gain3)) * 180.0 / 3.1415926535897931;
      Copy_4_of_laod_arduino_2021_B.dist = 0.0;
    }

    if (Copy_4_of_laod_arduino_2021_B.Al_selector < 0.0) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 360.0 - fabs
        (Copy_4_of_laod_arduino_2021_B.Al_selector);
    }

    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
      Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 2];
    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 1.0) {
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 1.0) + 11];
      Copy_4_of_laod_arduino_2021_B.a_tmp_tmp = sin
        ((Copy_4_of_laod_arduino_2021_B.psi_ref_tmp -
          Copy_4_of_laod_arduino_2021_B.b_a_tmp) * 3.1415926535897931 / 180.0 /
         2.0);
      Copy_4_of_laod_arduino_2021_B.b_a_tmp =
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 1.0) + 14] -
         Copy_4_of_laod_arduino_2021_B.dist_fut) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.dist_fut = sin
        (Copy_4_of_laod_arduino_2021_B.b_a_tmp / 2.0);
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        Copy_4_of_laod_arduino_2021_B.psi_ref_tmp * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.a_fut_tmp = cos
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp);
      Copy_4_of_laod_arduino_2021_B.dist_fut =
        Copy_4_of_laod_arduino_2021_B.Gain3 *
        Copy_4_of_laod_arduino_2021_B.a_fut_tmp *
        (Copy_4_of_laod_arduino_2021_B.dist_fut *
         Copy_4_of_laod_arduino_2021_B.dist_fut) +
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp *
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp;
      Copy_4_of_laod_arduino_2021_B.dist_fut = rt_atan2d_snf(sqrt
        (Copy_4_of_laod_arduino_2021_B.dist_fut), sqrt(1.0 -
        Copy_4_of_laod_arduino_2021_B.dist_fut)) * 2.0 * 6.378137E+6;
      Copy_4_of_laod_arduino_2021_B.Gain3 = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.b_a_tmp) *
        Copy_4_of_laod_arduino_2021_B.a_fut_tmp, sin
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp) *
        Copy_4_of_laod_arduino_2021_B.Gain3 - cos
        (Copy_4_of_laod_arduino_2021_B.b_a_tmp) * (sin
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 11] *
         3.1415926535897931 / 180.0) * Copy_4_of_laod_arduino_2021_B.a_fut_tmp))
        * 180.0 / 3.1415926535897931;
      if (Copy_4_of_laod_arduino_2021_B.Gain3 < 0.0) {
        Copy_4_of_laod_arduino_2021_B.Gain3 = 360.0 - fabs
          (Copy_4_of_laod_arduino_2021_B.Gain3);
      }

      if (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput > 1.0) {
        Copy_4_of_laod_arduino_2021_B.Gain3 = fabs
          (Copy_4_of_laod_arduino_2021_B.Gain3 -
           Copy_4_of_laod_arduino_2021_B.Al_selector);
      } else {
        Copy_4_of_laod_arduino_2021_B.Gain3 = fabs
          (Copy_4_of_laod_arduino_2021_B.Gain3 - rt_atan2d_snf(sin
            ((Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
              Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 14] -
              Copy_4_of_laod_arduino_2021_B.Gain_n) * 3.1415926535897931 / 180.0)
            * cos(Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
                  Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 11] *
                  3.1415926535897931 / 180.0), sin
            (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
             Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput + 11] *
             3.1415926535897931 / 180.0) * cos
            (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l * 3.1415926535897931 /
             180.0) - cos(Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
                          Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput +
                          11] * 3.1415926535897931 / 180.0) * sin
            (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l * 3.1415926535897931 /
             180.0) * cos((Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
                           Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput
                           + 14] - Copy_4_of_laod_arduino_2021_B.Gain_n) *
                          3.1415926535897931 / 180.0)) * 180.0 /
           3.1415926535897931);
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.dist_fut = 0.0;
      Copy_4_of_laod_arduino_2021_B.Gain3 = 0.0;
    }

    if (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput < 2.0) {
      Copy_4_of_laod_arduino_2021_B.Gain2_g = 0.0;
    } else if (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput == 2.0) {
      Copy_4_of_laod_arduino_2021_B.b_a_tmp = cos
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0);
      Copy_4_of_laod_arduino_2021_B.Gain_n =
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 14] -
         Copy_4_of_laod_arduino_2021_B.Gain_n) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Gain2_g = fabs
        (Copy_4_of_laod_arduino_2021_B.Al_selector - rt_atan2d_snf(sin
          (Copy_4_of_laod_arduino_2021_B.Gain_n) *
          Copy_4_of_laod_arduino_2021_B.b_a_tmp, sin
          (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
           (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 11] *
           3.1415926535897931 / 180.0) * Copy_4_of_laod_arduino_2021_B.Gain2_g -
          cos(Copy_4_of_laod_arduino_2021_B.Gain_n) * (sin
           (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l * 3.1415926535897931 /
            180.0) * Copy_4_of_laod_arduino_2021_B.b_a_tmp)) * 180.0 /
         3.1415926535897931);
    } else {
      Copy_4_of_laod_arduino_2021_B.Gain2_g = cos
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0);
      Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
        Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 2.0) + 11] *
        3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Gain_n =
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 14] -
         Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Gain2_g = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.Gain_n) *
        Copy_4_of_laod_arduino_2021_B.Gain2_g, cos
        (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) * sin
        (Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0) - sin
        (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) *
        Copy_4_of_laod_arduino_2021_B.Gain2_g * cos
        (Copy_4_of_laod_arduino_2021_B.Gain_n)) * 180.0 / 3.1415926535897931;
      if (Copy_4_of_laod_arduino_2021_B.Gain2_g < 0.0) {
        Copy_4_of_laod_arduino_2021_B.Gain2_g = 360.0 - fabs
          (Copy_4_of_laod_arduino_2021_B.Gain2_g);
      }

      Copy_4_of_laod_arduino_2021_B.Gain2_g = fabs
        (Copy_4_of_laod_arduino_2021_B.Al_selector -
         Copy_4_of_laod_arduino_2021_B.Gain2_g);
    }

    if (Copy_4_of_laod_arduino_2021_B.Gain3 <= 3.0) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 1.0;
      Copy_4_of_laod_arduino_2021_B.AL = 20;
    } else if (Copy_4_of_laod_arduino_2021_B.Gain3 <= 10.0) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 30.0;
      Copy_4_of_laod_arduino_2021_B.AL = 100;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain3 > 10.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain3 <= 50.0)) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 80.0;
      Copy_4_of_laod_arduino_2021_B.AL = 250;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain3 > 50.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain3 <= 90.0)) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 100.0;
      Copy_4_of_laod_arduino_2021_B.AL = 300;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain3 > 90.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain3 <= 120.0)) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 150.0;
      Copy_4_of_laod_arduino_2021_B.AL = 350;
    } else {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 200.0;
      Copy_4_of_laod_arduino_2021_B.AL = 400;
    }

    if (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 10.0) {
      Copy_4_of_laod_arduino_2021_B.caso = 80;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain2_g > 10.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 50.0)) {
      Copy_4_of_laod_arduino_2021_B.caso = 200;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain2_g > 50.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 90.0)) {
      Copy_4_of_laod_arduino_2021_B.caso = 300;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain2_g > 90.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 120.0)) {
      Copy_4_of_laod_arduino_2021_B.caso = 350;
    } else {
      Copy_4_of_laod_arduino_2021_B.caso = 400;
    }

    if (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 1.0) {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_B.WP_param_c[(int32_T)
        Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput - 1];
      if (Copy_4_of_laod_arduino_2021_B.deltafalllimit <= 20.0) {
        Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.1;
      } else if ((Copy_4_of_laod_arduino_2021_B.deltafalllimit <= 25.0) &&
                 (Copy_4_of_laod_arduino_2021_B.deltafalllimit > 20.0)) {
        Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.2;
      } else if (Copy_4_of_laod_arduino_2021_B.deltafalllimit <= 30.0) {
        if (Copy_4_of_laod_arduino_2021_B.deltafalllimit > 25.0) {
          Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.3;
        } else {
          Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.4;
        }
      } else {
        Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.4;
      }

      if (((!(Copy_4_of_laod_arduino_2021_B.dist <
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_B.Switch_bk >
              Copy_4_of_laod_arduino_2021_B.Al_selector))) &&
          ((!(Copy_4_of_laod_arduino_2021_B.dist >
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_B.Switch_bk >
              Copy_4_of_laod_arduino_2021_B.Al_selector))) &&
          (Copy_4_of_laod_arduino_2021_B.Switch_bk <
           Copy_4_of_laod_arduino_2021_B.Al_selector)) {
        if (Copy_4_of_laod_arduino_2021_B.dist_fut >
            Copy_4_of_laod_arduino_2021_B.AL) {
          Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput++;
        } else if (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput < 2.0) {
          Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput += 2.0;
        } else {
          Copy_4_of_laod_arduino_2021_DW.flag_c = 1.0;
        }
      }
    } else {
      if (((!(Copy_4_of_laod_arduino_2021_B.dist <
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_DW.flag_c == 0.0))) &&
          ((!(Copy_4_of_laod_arduino_2021_B.dist >
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_B.Switch_bk > 40.0)) ||
           (!(Copy_4_of_laod_arduino_2021_DW.flag_c == 0.0)))) {
        Copy_4_of_laod_arduino_2021_DW.flag_c = 1.0;
      }
    }

    if (!(Copy_4_of_laod_arduino_2021_B.modo == 4.0)) {
      Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput = 1.0;
    }

    /* End of MATLAB Function: '<S442>/ALLINEAMENTO' */

    /* Abs: '<S442>/Abs1' */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fabs
      (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0);

    /* Chart: '<S442>/Chart1' incorporates:
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  Memory: '<S442>/Memory1'
     *  Memory: '<S442>/Memory2'
     *  Memory: '<S442>/Memory5'
     */
    if (Copy_4_of_laod_arduino_2021_DW.is_active_c10_Copy_4_of_laod_ar == 0U) {
      Copy_4_of_laod_arduino_2021_DW.is_active_c10_Copy_4_of_laod_ar = 1U;
      Copy_4_of_laod_arduino_2021_B.maneuver_selector = 1.0;
      Copy_4_of_laod_arduino_2021_B.trig_approach = 0.0;
      Copy_4_of_laod_arduino_2021_B.trig_flare = 0.0;
      Copy_4_of_laod_arduino_2021_B.approach_selector = 1.0;
      Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
        Copy_4_of_laod_a_IN_Allignment1;
    } else {
      switch (Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2) {
       case Copy_4_of_laod_arduino_IN_Abort:
        Copy_4_of_laod_arduino_2021_B.maneuver_selector = 1.0;
        Copy_4_of_laod_arduino_2021_B.trig_approach = 0.0;
        Copy_4_of_laod_arduino_2021_B.trig_flare = 0.0;
        Copy_4_of_laod_arduino_2021_B.approach_selector = 0.0;
        break;

       case Copy_4_of_laod_ar_IN_Allignment:
        if ((Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] > 35.0F) &&
            (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] < 60.0F) &&
            (Copy_4_of_laod_arduino_2021_B.deltafalllimit <=
             Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] *
             19.081136687728211 + 100.0) &&
            (Copy_4_of_laod_arduino_2021_B.deltafalllimit >=
             Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] *
             14.300666256711928 + 100.0) &&
            (Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput > 1.0)) {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_ardu_IN_Approach;
        } else if (Copy_4_of_laod_arduino_2021_B.modo != 4.0) {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_a_IN_Allignment1;
        } else {
          Copy_4_of_laod_arduino_2021_B.trig_flare = 0.0;
          Copy_4_of_laod_arduino_2021_B.approach_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.maneuver_selector = 1.0;
          Copy_4_of_laod_arduino_2021_B.trig_approach = 0.0;
        }
        break;

       case Copy_4_of_laod_a_IN_Allignment1:
        if (Copy_4_of_laod_arduino_2021_B.modo == 4.0) {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_ar_IN_Allignment;
        } else {
          Copy_4_of_laod_arduino_2021_B.maneuver_selector = 1.0;
          Copy_4_of_laod_arduino_2021_B.trig_approach = 0.0;
          Copy_4_of_laod_arduino_2021_B.trig_flare = 0.0;
          Copy_4_of_laod_arduino_2021_B.approach_selector = 0.0;
        }
        break;

       case Copy_4_of_laod_ardu_IN_Approach:
        if ((Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 >=
             Copy_4_of_laod_arduino_2021_DW.Memory5_PreviousInput) &&
            ((Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] <=
              Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_l + 1.5) ||
             (Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] >
              Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_l - 1.0))) {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_arduino_IN_Flare;
        } else if (Copy_4_of_laod_arduino_2021_B.modo != 4.0) {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_a_IN_Allignment1;
        } else if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_f == 1.0)
        {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_arduino_IN_Abort;
        } else {
          Copy_4_of_laod_arduino_2021_B.trig_flare = 0.0;
          Copy_4_of_laod_arduino_2021_B.trig_approach = 1.0;
          Copy_4_of_laod_arduino_2021_B.approach_selector = 1.0;
          Copy_4_of_laod_arduino_2021_B.maneuver_selector = 2.0;
        }
        break;

       default:
        /* case IN_Flare: */
        if ((Copy_4_of_laod_arduino_2021_B.Product1 < 3.0) ||
            (!(Copy_4_of_laod_arduino_2021_B.modo != 4.0))) {
          Copy_4_of_laod_arduino_2021_B.trig_approach = 0.0;
          Copy_4_of_laod_arduino_2021_B.trig_flare = 1.0;
          Copy_4_of_laod_arduino_2021_B.approach_selector = 0.0;
          Copy_4_of_laod_arduino_2021_B.maneuver_selector = 3.0;
        } else {
          Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 =
            Copy_4_of_laod_a_IN_Allignment1;
        }
        break;
      }
    }

    /* End of Chart: '<S442>/Chart1' */

    /* Outputs for Triggered SubSystem: '<S442>/Sample and Hold' incorporates:
     *  TriggerPort: '<S467>/Trigger'
     */
    Copy_4_of_laod_arduino_2021_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &Copy_4_of_laod_arduino__PrevZCX.SampleandHold_Trig_ZCE,
      (Copy_4_of_laod_arduino_2021_B.approach_selector));
    if (Copy_4_of_laod_arduino_2021_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S467>/In' incorporates:
       *  Abs: '<S442>/Abs2'
       *  Constant: '<S442>/Constant4'
       *  DataTypeConversion: '<S556>/Data Type Conversion5'
       *  Sum: '<S459>/Sum'
       *  UnaryMinus: '<S459>/Ze2height'
       */
      Copy_4_of_laod_arduino_2021_B.In[0] = fabs
        (-(Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] +
           Copy_4_of_laod_arduino_2021_P.Constant4_Value_j));
      Copy_4_of_laod_arduino_2021_B.In[1] =
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;
    }

    /* End of Outputs for SubSystem: '<S442>/Sample and Hold' */

    /* Outputs for Enabled SubSystem: '<S442>/APPROACH' incorporates:
     *  EnablePort: '<S453>/Enable'
     */
    if (Copy_4_of_laod_arduino_2021_B.trig_approach > 0.0) {
      /* Product: '<S453>/Divide' incorporates:
       *  Constant: '<S453>/x_g0'
       *  Sum: '<S453>/Sum'
       */
      Copy_4_of_laod_arduino_2021_B.IProdOut = Copy_4_of_laod_arduino_2021_B.In
        [0] / (Copy_4_of_laod_arduino_2021_B.In[1] -
               Copy_4_of_laod_arduino_2021_P.x_g0_Value);

      /* Abs: '<S453>/Abs' incorporates:
       *  Trigonometry: '<S453>/Atan'
       */
      Copy_4_of_laod_arduino_2021_B.Product1 = fabs(atan
        (Copy_4_of_laod_arduino_2021_B.IProdOut));

      /* DiscreteIntegrator: '<S453>/Discrete-Time Integrator' */
      if ((Copy_4_of_laod_arduino_2021_B.trig_approach > 0.0) &&
          (Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_PrevRese <= 0))
      {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE =
          Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_IC;
      }

      if (Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE >=
          Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_UpperSat) {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE =
          Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE <=
            Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_LowerSat) {
          Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE =
            Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      /* Switch: '<S453>/Switch' incorporates:
       *  Constant: '<S453>/Constant3'
       *  Constant: '<S453>/Constant4'
       *  DiscreteIntegrator: '<S453>/Discrete-Time Integrator'
       */
      if (Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE >
          Copy_4_of_laod_arduino_2021_P.Switch_Threshold) {
        Copy_4_of_laod_arduino_2021_B.deltafalllimit =
          Copy_4_of_laod_arduino_2021_P.Constant3_Value;
      } else {
        Copy_4_of_laod_arduino_2021_B.deltafalllimit =
          Copy_4_of_laod_arduino_2021_P.Constant4_Value;
      }

      /* End of Switch: '<S453>/Switch' */

      /* MATLAB Function: '<S453>/MATLAB Function' */
      Copy_4_of_laod_arduino_2021_B.AL = 0;
      if ((!Copy_4_of_laod_arduino_2021_DW.x_not_empty) ||
          (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 0.0)) {
        Copy_4_of_laod_arduino_2021_DW.x[0] = 1.5;
        Copy_4_of_laod_arduino_2021_DW.x[1] = -200.0;
        Copy_4_of_laod_arduino_2021_DW.x[2] = 0.01;
        Copy_4_of_laod_arduino_2021_DW.x[3] = -2.0;
        Copy_4_of_laod_arduino_2021_DW.x_not_empty = true;
      }

      Copy_4_of_laod_arduino_2021_DW.x_new_not_empty =
        ((!Copy_4_of_laod_arduino_2021_DW.x_new_not_empty) ||
         (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 0.0) ||
         Copy_4_of_laod_arduino_2021_DW.x_new_not_empty);
      if ((!Copy_4_of_laod_arduino_2021_DW.eps_not_empty) ||
          (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 0.0)) {
        Copy_4_of_laod_arduino_2021_DW.eps[0] = 1.0;
        Copy_4_of_laod_arduino_2021_DW.eps[1] = 1.0;
        Copy_4_of_laod_arduino_2021_DW.eps[2] = 1.0;
        Copy_4_of_laod_arduino_2021_DW.eps[3] = 1.0;
        Copy_4_of_laod_arduino_2021_DW.eps_not_empty = true;
      }

      if ((!Copy_4_of_laod_arduino_2021_DW.cycle_count_not_empty) ||
          (Copy_4_of_laod_arduino_2021_B.deltafalllimit == 0.0)) {
        Copy_4_of_laod_arduino_2021_DW.cycle_count = 0.0;
        Copy_4_of_laod_arduino_2021_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(Copy_4_of_laod_arduino_2021_DW.eps[0] < 0.1)) ||
                           ((!(Copy_4_of_laod_arduino_2021_DW.eps[1] < 0.1)) ||
                            ((!(Copy_4_of_laod_arduino_2021_DW.eps[2] < 0.1)) ||
                (!(Copy_4_of_laod_arduino_2021_DW.eps[3] < 0.1)))))) {
        memset(&Copy_4_of_laod_arduino_2021_B.a[0], 0, sizeof(real_T) << 4U);
        Copy_4_of_laod_arduino_2021_B.Switch_bk = exp((5.0 -
          Copy_4_of_laod_arduino_2021_DW.x[1]) *
          -Copy_4_of_laod_arduino_2021_DW.x[2]);
        Copy_4_of_laod_arduino_2021_B.Gain3 = tan
          (Copy_4_of_laod_arduino_2021_B.Product1);
        Copy_4_of_laod_arduino_2021_B.A[0] = 1.0;
        Copy_4_of_laod_arduino_2021_B.A[4] = Copy_4_of_laod_arduino_2021_B.Gain3;
        Copy_4_of_laod_arduino_2021_B.A[8] = 0.0;
        Copy_4_of_laod_arduino_2021_B.A[12] = 0.0;
        Copy_4_of_laod_arduino_2021_B.A[1] = Copy_4_of_laod_arduino_2021_DW.x[2];
        Copy_4_of_laod_arduino_2021_B.A[5] = 0.0;
        Copy_4_of_laod_arduino_2021_B.Al_selector =
          Copy_4_of_laod_arduino_2021_DW.x[0] -
          Copy_4_of_laod_arduino_2021_DW.x[3];
        Copy_4_of_laod_arduino_2021_B.A[9] =
          Copy_4_of_laod_arduino_2021_B.Al_selector;
        Copy_4_of_laod_arduino_2021_B.A[13] = -Copy_4_of_laod_arduino_2021_DW.x
          [2];
        Copy_4_of_laod_arduino_2021_B.A[2] =
          Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
          Copy_4_of_laod_arduino_2021_B.Al_selector *
          Copy_4_of_laod_arduino_2021_DW.x[2];
        Copy_4_of_laod_arduino_2021_B.A[6] =
          Copy_4_of_laod_arduino_2021_B.PWM_elevator_l *
          Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.A[10] =
          Copy_4_of_laod_arduino_2021_B.Al_selector *
          (Copy_4_of_laod_arduino_2021_DW.x[1] - 5.0) *
          Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.A[14] = 1.0;
        Copy_4_of_laod_arduino_2021_B.A[3] = Copy_4_of_laod_arduino_2021_DW.x[2]
          * 18.0 * Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.A[7] =
          Copy_4_of_laod_arduino_2021_B.Al_selector *
          (Copy_4_of_laod_arduino_2021_DW.x[2] *
           Copy_4_of_laod_arduino_2021_DW.x[2]) * 18.0 *
          Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.Gain2_g =
          Copy_4_of_laod_arduino_2021_B.PWM_elevator_l * 18.0;
        Copy_4_of_laod_arduino_2021_B.A[11] =
          Copy_4_of_laod_arduino_2021_B.Gain2_g *
          (Copy_4_of_laod_arduino_2021_DW.x[1] - 5.0) *
          Copy_4_of_laod_arduino_2021_B.Switch_bk +
          Copy_4_of_laod_arduino_2021_B.Al_selector * 18.0 *
          Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.A[15] = -Copy_4_of_laod_arduino_2021_DW.x
          [2] * 18.0 * Copy_4_of_laod_arduino_2021_B.Switch_bk;
        Copy_4_of_laod_arduino_2021_B.ipiv[0] = 1;
        Copy_4_of_laod_arduino_2021_B.ipiv[1] = 2;
        Copy_4_of_laod_arduino_2021_B.ipiv[2] = 3;
        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO < 3;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.ATO
            * 5;
          Copy_4_of_laod_arduino_2021_B.g = 0;
          Copy_4_of_laod_arduino_2021_B.i = Copy_4_of_laod_arduino_2021_B.caso;
          Copy_4_of_laod_arduino_2021_B.deltafalllimit = fabs
            (Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.caso]);
          Copy_4_of_laod_arduino_2021_B.jy = 2;
          while (Copy_4_of_laod_arduino_2021_B.jy <= 4 -
                 Copy_4_of_laod_arduino_2021_B.ATO) {
            Copy_4_of_laod_arduino_2021_B.i++;
            Copy_4_of_laod_arduino_2021_B.Gain_n = fabs
              (Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.i]);
            if (Copy_4_of_laod_arduino_2021_B.Gain_n >
                Copy_4_of_laod_arduino_2021_B.deltafalllimit) {
              Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.jy
                - 1;
              Copy_4_of_laod_arduino_2021_B.deltafalllimit =
                Copy_4_of_laod_arduino_2021_B.Gain_n;
            }

            Copy_4_of_laod_arduino_2021_B.jy++;
          }

          if (Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.caso
              + Copy_4_of_laod_arduino_2021_B.g] != 0.0) {
            if (Copy_4_of_laod_arduino_2021_B.g != 0) {
              Copy_4_of_laod_arduino_2021_B.g +=
                Copy_4_of_laod_arduino_2021_B.ATO;
              Copy_4_of_laod_arduino_2021_B.ipiv[Copy_4_of_laod_arduino_2021_B.ATO]
                = (int8_T)(Copy_4_of_laod_arduino_2021_B.g + 1);
              Copy_4_of_laod_arduino_2021_B.deltafalllimit =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g] =
                Copy_4_of_laod_arduino_2021_B.deltafalllimit;
              Copy_4_of_laod_arduino_2021_B.deltafalllimit =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO
                + 4];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO
                + 4] =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g
                + 4];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g +
                4] = Copy_4_of_laod_arduino_2021_B.deltafalllimit;
              Copy_4_of_laod_arduino_2021_B.deltafalllimit =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO
                + 8];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO
                + 8] =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g
                + 8];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g +
                8] = Copy_4_of_laod_arduino_2021_B.deltafalllimit;
              Copy_4_of_laod_arduino_2021_B.deltafalllimit =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO
                + 12];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ATO
                + 12] =
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g
                + 12];
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g +
                12] = Copy_4_of_laod_arduino_2021_B.deltafalllimit;
            }

            Copy_4_of_laod_arduino_2021_B.i =
              (Copy_4_of_laod_arduino_2021_B.caso -
               Copy_4_of_laod_arduino_2021_B.ATO) + 4;
            Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.caso
              + 1;
            while (Copy_4_of_laod_arduino_2021_B.g + 1 <=
                   Copy_4_of_laod_arduino_2021_B.i) {
              Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g] /=
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.caso];
              Copy_4_of_laod_arduino_2021_B.g++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.i = Copy_4_of_laod_arduino_2021_B.caso;
          Copy_4_of_laod_arduino_2021_B.jy = Copy_4_of_laod_arduino_2021_B.caso
            + 4;
          Copy_4_of_laod_arduino_2021_B.c = 0;
          while (Copy_4_of_laod_arduino_2021_B.c <= 2 -
                 Copy_4_of_laod_arduino_2021_B.ATO) {
            if (Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.jy]
                != 0.0) {
              Copy_4_of_laod_arduino_2021_B.deltafalllimit =
                -Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.jy];
              Copy_4_of_laod_arduino_2021_B.c_ix =
                Copy_4_of_laod_arduino_2021_B.caso + 1;
              Copy_4_of_laod_arduino_2021_B.g = (Copy_4_of_laod_arduino_2021_B.i
                - Copy_4_of_laod_arduino_2021_B.ATO) + 8;
              Copy_4_of_laod_arduino_2021_B.ijA =
                Copy_4_of_laod_arduino_2021_B.i + 5;
              while (Copy_4_of_laod_arduino_2021_B.ijA + 1 <=
                     Copy_4_of_laod_arduino_2021_B.g) {
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.ijA]
                  +=
                  Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.c_ix]
                  * Copy_4_of_laod_arduino_2021_B.deltafalllimit;
                Copy_4_of_laod_arduino_2021_B.c_ix++;
                Copy_4_of_laod_arduino_2021_B.ijA++;
              }
            }

            Copy_4_of_laod_arduino_2021_B.jy += 4;
            Copy_4_of_laod_arduino_2021_B.i += 4;
            Copy_4_of_laod_arduino_2021_B.c++;
          }
        }

        Copy_4_of_laod_arduino_2021_B.p[0] = 1;
        Copy_4_of_laod_arduino_2021_B.p[1] = 2;
        Copy_4_of_laod_arduino_2021_B.p[2] = 3;
        Copy_4_of_laod_arduino_2021_B.p[3] = 4;
        if (Copy_4_of_laod_arduino_2021_B.ipiv[0] > 1) {
          Copy_4_of_laod_arduino_2021_B.ATO =
            Copy_4_of_laod_arduino_2021_B.p[Copy_4_of_laod_arduino_2021_B.ipiv[0]
            - 1];
          Copy_4_of_laod_arduino_2021_B.p[Copy_4_of_laod_arduino_2021_B.ipiv[0]
            - 1] = 1;
          Copy_4_of_laod_arduino_2021_B.p[0] = (int8_T)
            Copy_4_of_laod_arduino_2021_B.ATO;
        }

        if (Copy_4_of_laod_arduino_2021_B.ipiv[1] > 2) {
          Copy_4_of_laod_arduino_2021_B.ATO =
            Copy_4_of_laod_arduino_2021_B.p[Copy_4_of_laod_arduino_2021_B.ipiv[1]
            - 1];
          Copy_4_of_laod_arduino_2021_B.p[Copy_4_of_laod_arduino_2021_B.ipiv[1]
            - 1] = Copy_4_of_laod_arduino_2021_B.p[1];
          Copy_4_of_laod_arduino_2021_B.p[1] = (int8_T)
            Copy_4_of_laod_arduino_2021_B.ATO;
        }

        if (Copy_4_of_laod_arduino_2021_B.ipiv[2] > 3) {
          Copy_4_of_laod_arduino_2021_B.ATO =
            Copy_4_of_laod_arduino_2021_B.p[Copy_4_of_laod_arduino_2021_B.ipiv[2]
            - 1];
          Copy_4_of_laod_arduino_2021_B.p[Copy_4_of_laod_arduino_2021_B.ipiv[2]
            - 1] = Copy_4_of_laod_arduino_2021_B.p[2];
          Copy_4_of_laod_arduino_2021_B.p[2] = (int8_T)
            Copy_4_of_laod_arduino_2021_B.ATO;
        }

        Copy_4_of_laod_arduino_2021_B.c = Copy_4_of_laod_arduino_2021_B.p[0] - 1;
        Copy_4_of_laod_arduino_2021_B.a[(Copy_4_of_laod_arduino_2021_B.p[0] - 1)
          << 2] = 1.0;
        Copy_4_of_laod_arduino_2021_B.caso = 0;
        while (Copy_4_of_laod_arduino_2021_B.caso + 1 < 5) {
          Copy_4_of_laod_arduino_2021_B.ATO = Copy_4_of_laod_arduino_2021_B.c <<
            2;
          Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.ATO +
            Copy_4_of_laod_arduino_2021_B.caso;
          if (Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g]
              != 0.0) {
            Copy_4_of_laod_arduino_2021_B.i = Copy_4_of_laod_arduino_2021_B.caso
              + 1;
            while (Copy_4_of_laod_arduino_2021_B.i + 1 < 5) {
              Copy_4_of_laod_arduino_2021_B.jy =
                Copy_4_of_laod_arduino_2021_B.ATO +
                Copy_4_of_laod_arduino_2021_B.i;
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.jy] -=
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g]
                * Copy_4_of_laod_arduino_2021_B.A
                [(Copy_4_of_laod_arduino_2021_B.caso << 2) +
                Copy_4_of_laod_arduino_2021_B.i];
              Copy_4_of_laod_arduino_2021_B.i++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.caso++;
        }

        Copy_4_of_laod_arduino_2021_B.c = Copy_4_of_laod_arduino_2021_B.p[1] - 1;
        Copy_4_of_laod_arduino_2021_B.a[((Copy_4_of_laod_arduino_2021_B.p[1] - 1)
          << 2) + 1] = 1.0;
        Copy_4_of_laod_arduino_2021_B.caso = 1;
        while (Copy_4_of_laod_arduino_2021_B.caso + 1 < 5) {
          Copy_4_of_laod_arduino_2021_B.ATO = Copy_4_of_laod_arduino_2021_B.c <<
            2;
          Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.ATO +
            Copy_4_of_laod_arduino_2021_B.caso;
          if (Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g]
              != 0.0) {
            Copy_4_of_laod_arduino_2021_B.i = Copy_4_of_laod_arduino_2021_B.caso
              + 1;
            while (Copy_4_of_laod_arduino_2021_B.i + 1 < 5) {
              Copy_4_of_laod_arduino_2021_B.jy =
                Copy_4_of_laod_arduino_2021_B.ATO +
                Copy_4_of_laod_arduino_2021_B.i;
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.jy] -=
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g]
                * Copy_4_of_laod_arduino_2021_B.A
                [(Copy_4_of_laod_arduino_2021_B.caso << 2) +
                Copy_4_of_laod_arduino_2021_B.i];
              Copy_4_of_laod_arduino_2021_B.i++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.caso++;
        }

        Copy_4_of_laod_arduino_2021_B.c = Copy_4_of_laod_arduino_2021_B.p[2] - 1;
        Copy_4_of_laod_arduino_2021_B.a[((Copy_4_of_laod_arduino_2021_B.p[2] - 1)
          << 2) + 2] = 1.0;
        Copy_4_of_laod_arduino_2021_B.caso = 2;
        while (Copy_4_of_laod_arduino_2021_B.caso + 1 < 5) {
          Copy_4_of_laod_arduino_2021_B.ATO = Copy_4_of_laod_arduino_2021_B.c <<
            2;
          Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.ATO +
            Copy_4_of_laod_arduino_2021_B.caso;
          if (Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g]
              != 0.0) {
            Copy_4_of_laod_arduino_2021_B.i = Copy_4_of_laod_arduino_2021_B.caso
              + 1;
            while (Copy_4_of_laod_arduino_2021_B.i + 1 < 5) {
              Copy_4_of_laod_arduino_2021_B.jy =
                Copy_4_of_laod_arduino_2021_B.ATO +
                Copy_4_of_laod_arduino_2021_B.i;
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.jy] -=
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g]
                * Copy_4_of_laod_arduino_2021_B.A
                [(Copy_4_of_laod_arduino_2021_B.caso << 2) +
                Copy_4_of_laod_arduino_2021_B.i];
              Copy_4_of_laod_arduino_2021_B.i++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.caso++;
        }

        Copy_4_of_laod_arduino_2021_B.jy = (Copy_4_of_laod_arduino_2021_B.p[3] -
          1) << 2;
        Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.jy + 3] =
          1.0;
        Copy_4_of_laod_arduino_2021_B.caso = 3;
        while (Copy_4_of_laod_arduino_2021_B.caso + 1 < 5) {
          Copy_4_of_laod_arduino_2021_B.ATO = Copy_4_of_laod_arduino_2021_B.jy +
            Copy_4_of_laod_arduino_2021_B.caso;
          if (Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.ATO]
              != 0.0) {
            Copy_4_of_laod_arduino_2021_B.i = Copy_4_of_laod_arduino_2021_B.caso
              + 1;
            while (Copy_4_of_laod_arduino_2021_B.i + 1 < 5) {
              Copy_4_of_laod_arduino_2021_B.g = Copy_4_of_laod_arduino_2021_B.jy
                + Copy_4_of_laod_arduino_2021_B.i;
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.g] -=
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.ATO]
                * Copy_4_of_laod_arduino_2021_B.A
                [(Copy_4_of_laod_arduino_2021_B.caso << 2) +
                Copy_4_of_laod_arduino_2021_B.i];
              Copy_4_of_laod_arduino_2021_B.i++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.caso++;
        }

        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO < 4;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_B.caso = Copy_4_of_laod_arduino_2021_B.ATO
            << 2;
          Copy_4_of_laod_arduino_2021_B.deltafalllimit =
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso +
            3];
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit != 0.0) {
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso +
              3] = Copy_4_of_laod_arduino_2021_B.deltafalllimit /
              Copy_4_of_laod_arduino_2021_B.A[15];
            Copy_4_of_laod_arduino_2021_B.g = 0;
            while (Copy_4_of_laod_arduino_2021_B.g <= 2) {
              Copy_4_of_laod_arduino_2021_B.jy = Copy_4_of_laod_arduino_2021_B.g
                + Copy_4_of_laod_arduino_2021_B.caso;
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.jy] -=
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso
                + 3] *
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g
                + 12];
              Copy_4_of_laod_arduino_2021_B.g++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.deltafalllimit =
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso +
            2];
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit != 0.0) {
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso +
              2] = Copy_4_of_laod_arduino_2021_B.deltafalllimit /
              Copy_4_of_laod_arduino_2021_B.A[10];
            Copy_4_of_laod_arduino_2021_B.g = 0;
            while (Copy_4_of_laod_arduino_2021_B.g <= 1) {
              Copy_4_of_laod_arduino_2021_B.jy = Copy_4_of_laod_arduino_2021_B.g
                + Copy_4_of_laod_arduino_2021_B.caso;
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.jy] -=
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso
                + 2] *
                Copy_4_of_laod_arduino_2021_B.A[Copy_4_of_laod_arduino_2021_B.g
                + 8];
              Copy_4_of_laod_arduino_2021_B.g++;
            }
          }

          Copy_4_of_laod_arduino_2021_B.deltafalllimit =
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso +
            1];
          if (Copy_4_of_laod_arduino_2021_B.deltafalllimit != 0.0) {
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso +
              1] = Copy_4_of_laod_arduino_2021_B.deltafalllimit /
              Copy_4_of_laod_arduino_2021_B.A[5];
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso] -=
              Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso
              + 1] * Copy_4_of_laod_arduino_2021_B.A[4];
          }

          if (Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso]
              != 0.0) {
            Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.caso] /=
              Copy_4_of_laod_arduino_2021_B.A[0];
          }
        }

        Copy_4_of_laod_arduino_2021_B.deltafalllimit =
          (Copy_4_of_laod_arduino_2021_DW.x[1] -
           Copy_4_of_laod_arduino_2021_P.x_g0_Value) *
          Copy_4_of_laod_arduino_2021_B.Gain3 +
          Copy_4_of_laod_arduino_2021_DW.x[0];
        Copy_4_of_laod_arduino_2021_B.Gain3 =
          Copy_4_of_laod_arduino_2021_B.PWM_elevator_l -
          Copy_4_of_laod_arduino_2021_B.Gain3;
        Copy_4_of_laod_arduino_2021_B.Al_selector =
          Copy_4_of_laod_arduino_2021_B.Al_selector *
          Copy_4_of_laod_arduino_2021_B.Switch_bk +
          Copy_4_of_laod_arduino_2021_DW.x[3];
        Copy_4_of_laod_arduino_2021_B.Switch_bk =
          Copy_4_of_laod_arduino_2021_B.Gain2_g *
          Copy_4_of_laod_arduino_2021_B.Switch_bk + -0.1;
        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO < 4;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_B.x_new[Copy_4_of_laod_arduino_2021_B.ATO]
            = Copy_4_of_laod_arduino_2021_DW.x[Copy_4_of_laod_arduino_2021_B.ATO]
            - (((Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.ATO
                 + 4] * Copy_4_of_laod_arduino_2021_B.Gain3 +
                 Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.ATO]
                 * Copy_4_of_laod_arduino_2021_B.deltafalllimit) +
                Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.ATO
                + 8] * Copy_4_of_laod_arduino_2021_B.Al_selector) +
               Copy_4_of_laod_arduino_2021_B.a[Copy_4_of_laod_arduino_2021_B.ATO
               + 12] * Copy_4_of_laod_arduino_2021_B.Switch_bk);
        }

        Copy_4_of_laod_arduino_2021_DW.eps[0] = fabs
          (Copy_4_of_laod_arduino_2021_B.x_new[0] -
           Copy_4_of_laod_arduino_2021_DW.x[0]);
        Copy_4_of_laod_arduino_2021_DW.eps[1] = fabs
          (Copy_4_of_laod_arduino_2021_B.x_new[1] -
           Copy_4_of_laod_arduino_2021_DW.x[1]);
        Copy_4_of_laod_arduino_2021_DW.eps[2] = fabs
          (Copy_4_of_laod_arduino_2021_B.x_new[2] -
           Copy_4_of_laod_arduino_2021_DW.x[2]);
        Copy_4_of_laod_arduino_2021_DW.eps[3] = fabs
          (Copy_4_of_laod_arduino_2021_B.x_new[3] -
           Copy_4_of_laod_arduino_2021_DW.x[3]);
        Copy_4_of_laod_arduino_2021_DW.x[0] =
          Copy_4_of_laod_arduino_2021_B.x_new[0];
        Copy_4_of_laod_arduino_2021_DW.x[1] =
          Copy_4_of_laod_arduino_2021_B.x_new[1];
        Copy_4_of_laod_arduino_2021_DW.x[2] =
          Copy_4_of_laod_arduino_2021_B.x_new[2];
        Copy_4_of_laod_arduino_2021_DW.x[3] =
          Copy_4_of_laod_arduino_2021_B.x_new[3];
        Copy_4_of_laod_arduino_2021_DW.cycle_count++;
        if (Copy_4_of_laod_arduino_2021_DW.cycle_count > 10.0) {
          Copy_4_of_laod_arduino_2021_B.AL = 1;
          exitg1 = true;
        }
      }

      if ((Copy_4_of_laod_arduino_2021_DW.eps[0] < 0.1) &&
          (Copy_4_of_laod_arduino_2021_DW.eps[1] < 0.1) &&
          (Copy_4_of_laod_arduino_2021_DW.eps[2] < 0.1) &&
          (Copy_4_of_laod_arduino_2021_DW.eps[3] < 0.1)) {
        Copy_4_of_laod_arduino_2021_B.h_f_out =
          Copy_4_of_laod_arduino_2021_DW.x[0];
        Copy_4_of_laod_arduino_2021_B.x_f_out =
          Copy_4_of_laod_arduino_2021_DW.x[1];
        Copy_4_of_laod_arduino_2021_B.k_x_out =
          Copy_4_of_laod_arduino_2021_DW.x[2];
        Copy_4_of_laod_arduino_2021_B.h_c_out =
          Copy_4_of_laod_arduino_2021_DW.x[3];
      } else {
        Copy_4_of_laod_arduino_2021_B.h_f_out = 0.0;
        Copy_4_of_laod_arduino_2021_B.x_f_out = 0.0;
        Copy_4_of_laod_arduino_2021_B.k_x_out = 0.0;
        Copy_4_of_laod_arduino_2021_B.h_c_out = 0.0;
      }

      Copy_4_of_laod_arduino_2021_B.no_solution =
        Copy_4_of_laod_arduino_2021_B.AL;

      /* End of MATLAB Function: '<S453>/MATLAB Function' */

      /* Product: '<S453>/Multiply' incorporates:
       *  Constant: '<S453>/x_g0'
       *  Gain: '<S453>/Gain'
       *  Sum: '<S453>/Sum1'
       */
      Copy_4_of_laod_arduino_2021_B.Multiply =
        (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 -
         Copy_4_of_laod_arduino_2021_P.x_g0_Value) *
        Copy_4_of_laod_arduino_2021_P.Gain_Gain_e0 *
        Copy_4_of_laod_arduino_2021_B.IProdOut;

      /* Update for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S453>/Constant2'
       */
      Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE +=
        Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_gainval *
        Copy_4_of_laod_arduino_2021_P.Constant2_Value_g;
      if (Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE >=
          Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_UpperSat) {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE =
          Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE <=
            Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_LowerSat) {
          Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE =
            Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      if (Copy_4_of_laod_arduino_2021_B.trig_approach > 0.0) {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_PrevRese = 1;
      } else if (Copy_4_of_laod_arduino_2021_B.trig_approach < 0.0) {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_PrevRese = -1;
      } else if (Copy_4_of_laod_arduino_2021_B.trig_approach == 0.0) {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' */
    }

    /* End of Outputs for SubSystem: '<S442>/APPROACH' */

    /* Outputs for Enabled SubSystem: '<S442>/FLARE' incorporates:
     *  EnablePort: '<S457>/Enable'
     */
    if (Copy_4_of_laod_arduino_2021_B.trig_flare > 0.0) {
      /* Sum: '<S457>/Sum2' incorporates:
       *  Gain: '<S457>/Gain'
       *  Math: '<S457>/Exp'
       *  Product: '<S457>/Multiply'
       *  Product: '<S457>/Multiply1'
       *  Sum: '<S457>/Sum'
       *  Sum: '<S457>/Sum1'
       *
       * About '<S457>/Exp':
       *  Operator: exp
       */
      Copy_4_of_laod_arduino_2021_B.Sum2 = exp
        ((Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 -
          Copy_4_of_laod_arduino_2021_B.x_f_out) *
         Copy_4_of_laod_arduino_2021_B.k_x_out *
         Copy_4_of_laod_arduino_2021_P.Gain_Gain_j) *
        (Copy_4_of_laod_arduino_2021_B.h_f_out -
         Copy_4_of_laod_arduino_2021_B.h_c_out) +
        Copy_4_of_laod_arduino_2021_B.h_c_out;
    }

    /* End of Outputs for SubSystem: '<S442>/FLARE' */

    /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' */
    switch ((int32_T)Copy_4_of_laod_arduino_2021_B.maneuver_selector) {
     case 1:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Constant: '<S442>/Constant2'
       */
      Copy_4_of_laod_arduino_2021_B.QUOTA_m =
        Copy_4_of_laod_arduino_2021_P.Constant2_Value_n3;
      break;

     case 2:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S442>/Abs3'
       */
      Copy_4_of_laod_arduino_2021_B.QUOTA_m = fabs
        (Copy_4_of_laod_arduino_2021_B.Multiply);
      break;

     default:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S442>/Abs4'
       */
      Copy_4_of_laod_arduino_2021_B.QUOTA_m = fabs
        (Copy_4_of_laod_arduino_2021_B.Sum2);
      break;
    }

    /* End of MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' */

    /* Update for Memory: '<S442>/Memory5' */
    Copy_4_of_laod_arduino_2021_DW.Memory5_PreviousInput =
      Copy_4_of_laod_arduino_2021_B.x_f_out;

    /* Update for Memory: '<S442>/Memory1' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_l =
      Copy_4_of_laod_arduino_2021_B.h_f_out;

    /* Update for Memory: '<S442>/Memory2' */
    Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_f =
      Copy_4_of_laod_arduino_2021_B.no_solution;
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem1' */

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S21>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.iflogic,
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion3,
     &Copy_4_of_laod_arduino_2021_P.SIUAVuint8_Value,
     &Copy_4_of_laod_arduino_2021_B.GC_info[0],
     &Copy_4_of_laod_arduino_2021_B.Val_out_MAV[0],
     &Copy_4_of_laod_arduino_2021_B.WP_info[0],
     &Copy_4_of_laod_arduino_2021_B.WP_param[0],
     &Copy_4_of_laod_arduino_2021_P.onboard_control_sensor_presentu[0],
     &Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctionI[0],
     &Copy_4_of_laod_arduino_2021_B.Gain1,
     &Copy_4_of_laod_arduino_2021_B.B_Remaining,
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion,
     &Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[0],
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion_ld[0],
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion1[0],
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion_a[0],
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_p[0],
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_h,
     &Copy_4_of_laod_arduino_2021_B.AGAC[0],
     &Copy_4_of_laod_arduino_2021_B.Heading_g,
     &Copy_4_of_laod_arduino_2021_B.Throttle,
     &Copy_4_of_laod_arduino_2021_B.Heading[0],
     &Copy_4_of_laod_arduino_2021_B.Memory_a,
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion2,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o14,
     &Copy_4_of_laod_arduino_2021_B.Switch1,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o15,
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion_l,
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_g,
     &Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_m,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o5[0],
     &Copy_4_of_laod_arduino_2021_B.Gain, &Copy_4_of_laod_arduino_2021_B.Gain_g,
     &Copy_4_of_laod_arduino_2021_B.h_Home, ((const uint16_T*)
      &Copy_4_of_laod_arduino_2021_U16GND),
     &Copy_4_of_laod_arduino_2021_B.SFunction_o1_j,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o2_f[0],
     &Copy_4_of_laod_arduino_2021_B.SFunction_o3,
     &Copy_4_of_laod_arduino_2021_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.SFunction_o1_j > 0) {
    /* Chart: '<S15>/Chart' */
    if (Copy_4_of_laod_arduino_2021_DW.is_active_c9_Copy_4_of_laod_ard == 0U) {
      Copy_4_of_laod_arduino_2021_DW.is_active_c9_Copy_4_of_laod_ard = 1U;
      Copy_4_of_laod_arduino_2021_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (Copy_4_of_laod_arduino_2021_DW.obj_o.Protocol !=
            Copy_4_of_laod_arduino_2021_P.SerialTransmit_Protocol) {
          Copy_4_of_laod_arduino_2021_DW.obj_o.Protocol =
            Copy_4_of_laod_arduino_2021_P.SerialTransmit_Protocol;
        }

        status =
          Copy_4_of_laod_arduino_2021_B.SFunction_o2_f[Copy_4_of_laod_arduino_2021_DW.i
          - 1];
        MW_Serial_write(Copy_4_of_laod_arduino_2021_DW.obj_o.port, &status, 1.0,
                        Copy_4_of_laod_arduino_2021_DW.obj_o.dataSizeInBytes,
                        Copy_4_of_laod_arduino_2021_DW.obj_o.sendModeEnum,
                        Copy_4_of_laod_arduino_2021_DW.obj_o.dataType,
                        Copy_4_of_laod_arduino_2021_DW.obj_o.sendFormatEnum, 2.0,
                        '\x00');
        if (Copy_4_of_laod_arduino_2021_DW.i <
            Copy_4_of_laod_arduino_2021_B.SFunction_o3) {
          Copy_4_of_laod_arduino_2021_B.ATO = Copy_4_of_laod_arduino_2021_DW.i +
            1;
          if (Copy_4_of_laod_arduino_2021_DW.i + 1 > 255) {
            Copy_4_of_laod_arduino_2021_B.ATO = 255;
          }

          Copy_4_of_laod_arduino_2021_DW.i = (uint8_T)
            Copy_4_of_laod_arduino_2021_B.ATO;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      Copy_4_of_laod_arduino_2021_DW.i = 1U;
    }

    /* End of Chart: '<S15>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S1>/Data Tversion' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 42;
       Copy_4_of_laod_arduino_2021_B.i++) {
    Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[Copy_4_of_laod_arduino_2021_B.i]
      = Copy_4_of_laod_arduino_2021_DW.WP_dbP[Copy_4_of_laod_arduino_2021_B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Tversion' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem2' incorporates:
   *  EnablePort: '<S443>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.Wp_selector > 0.0) {
    /* Gain: '<S544>/Gain' */
    Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_bu *
      Copy_4_of_laod_arduino_2021_B.Gain1_f;

    /* Gain: '<S545>/Gain' */
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_jz *
      Copy_4_of_laod_arduino_2021_B.Gain1_p;

    /* MATLAB Function: '<S443>/WAYPOINTS' incorporates:
     *  DataTypeConversion: '<S1>/Data Tversion'
     *  DataTypeConversion: '<S1>/Data Tversion1'
     *  DataTypeConversion: '<S1>/Data Tversion2'
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  Memory: '<S443>/Memory4'
     */
    Copy_4_of_laod_arduino_2021_B.ATO = 1;
    if (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput == 6.0) {
      Copy_4_of_laod_arduino_2021_B.ATO = 0;
    }

    if ((uint8_T)Copy_4_of_laod_arduino_2021_B.GC_info[0] == 3) {
      Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput = 1.0;
      Copy_4_of_laod_arduino_2021_DW.lat1 =
        Copy_4_of_laod_arduino_2021_B.PWM_elevator_l;
      Copy_4_of_laod_arduino_2021_DW.long1 =
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0;
      for (Copy_4_of_laod_arduino_2021_B.AL = 0;
           Copy_4_of_laod_arduino_2021_B.AL < 6;
           Copy_4_of_laod_arduino_2021_B.AL++) {
        if (Copy_4_of_laod_arduino_2021_DW.WP_dbI[Copy_4_of_laod_arduino_2021_B.AL
            + 24] == 1) {
          Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput = (real_T)
            Copy_4_of_laod_arduino_2021_B.AL + 1.0;
        }
      }
    }

    Copy_4_of_laod_arduino_2021_B.Wp_selector =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
      Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 23];
    Copy_4_of_laod_arduino_2021_B.Product1 =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
      Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 29];
    Copy_4_of_laod_arduino_2021_B.QUOTA =
      Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
      Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 35];
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = sin
      ((Copy_4_of_laod_arduino_2021_B.Wp_selector -
        Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) * 3.1415926535897931 /
       180.0 / 2.0);
    Copy_4_of_laod_arduino_2021_B.Switch_bk = sin
      ((Copy_4_of_laod_arduino_2021_B.Product1 -
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0) * 3.1415926535897931 /
       180.0 / 2.0);
    Copy_4_of_laod_arduino_2021_B.Al_selector =
      Copy_4_of_laod_arduino_2021_B.Wp_selector * 3.1415926535897931 / 180.0;
    Copy_4_of_laod_arduino_2021_B.Gain3 = cos
      (Copy_4_of_laod_arduino_2021_B.Al_selector);
    Copy_4_of_laod_arduino_2021_B.Gain2_g = cos
      (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l * 3.1415926535897931 / 180.0);
    Copy_4_of_laod_arduino_2021_B.deltafalllimit =
      Copy_4_of_laod_arduino_2021_B.Gain2_g *
      Copy_4_of_laod_arduino_2021_B.Gain3 *
      (Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.Switch_bk) +
      Copy_4_of_laod_arduino_2021_B.deltafalllimit *
      Copy_4_of_laod_arduino_2021_B.deltafalllimit;
    Copy_4_of_laod_arduino_2021_B.Switch_bk = rt_atan2d_snf(sqrt
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit), sqrt(1.0 -
      Copy_4_of_laod_arduino_2021_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    if (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput > 1.0) {
      Copy_4_of_laod_arduino_2021_B.a_tmp_tmp =
        Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 1.0) + 23];
      Copy_4_of_laod_arduino_2021_B.Al_selector =
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.deltafalllimit = cos
        (Copy_4_of_laod_arduino_2021_B.Al_selector);
      Copy_4_of_laod_arduino_2021_B.dist =
        Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 1.0) + 29];
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        (Copy_4_of_laod_arduino_2021_B.Product1 -
         Copy_4_of_laod_arduino_2021_B.dist) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Al_selector = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp) *
        Copy_4_of_laod_arduino_2021_B.Gain3, sin
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 23] *
         3.1415926535897931 / 180.0) *
        Copy_4_of_laod_arduino_2021_B.deltafalllimit - sin
        (Copy_4_of_laod_arduino_2021_B.Al_selector) *
        Copy_4_of_laod_arduino_2021_B.Gain3 * cos
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      Copy_4_of_laod_arduino_2021_B.a_tmp_tmp = sin
        ((Copy_4_of_laod_arduino_2021_B.PWM_elevator_l -
          Copy_4_of_laod_arduino_2021_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 /
         2.0);
      Copy_4_of_laod_arduino_2021_B.dist = sin
        ((Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 -
          Copy_4_of_laod_arduino_2021_B.dist) * 3.1415926535897931 / 180.0 / 2.0);
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        Copy_4_of_laod_arduino_2021_B.deltafalllimit *
        Copy_4_of_laod_arduino_2021_B.Gain2_g *
        (Copy_4_of_laod_arduino_2021_B.dist * Copy_4_of_laod_arduino_2021_B.dist)
        + Copy_4_of_laod_arduino_2021_B.a_tmp_tmp *
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp;
      Copy_4_of_laod_arduino_2021_B.dist = rt_atan2d_snf(sqrt
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit), sqrt(1.0 -
        Copy_4_of_laod_arduino_2021_B.deltafalllimit)) * 2.0 * 6.378137E+6;
    } else {
      Copy_4_of_laod_arduino_2021_B.deltafalllimit =
        (Copy_4_of_laod_arduino_2021_B.Product1 -
         Copy_4_of_laod_arduino_2021_DW.long1) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        Copy_4_of_laod_arduino_2021_DW.lat1 * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Al_selector = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit) *
        Copy_4_of_laod_arduino_2021_B.Gain3, sin
        (Copy_4_of_laod_arduino_2021_B.Al_selector) * cos
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp) - cos
        (Copy_4_of_laod_arduino_2021_B.deltafalllimit) * (sin
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp) *
        Copy_4_of_laod_arduino_2021_B.Gain3)) * 180.0 / 3.1415926535897931;
      Copy_4_of_laod_arduino_2021_B.dist = 0.0;
    }

    if (Copy_4_of_laod_arduino_2021_B.Al_selector < 0.0) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 360.0 - fabs
        (Copy_4_of_laod_arduino_2021_B.Al_selector);
    }

    if (Copy_4_of_laod_arduino_2021_B.ATO == 1) {
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 1.0) + 23];
      Copy_4_of_laod_arduino_2021_B.a_tmp_tmp = sin
        ((Copy_4_of_laod_arduino_2021_B.psi_ref_tmp -
          Copy_4_of_laod_arduino_2021_B.Wp_selector) * 3.1415926535897931 /
         180.0 / 2.0);
      Copy_4_of_laod_arduino_2021_B.b_a_tmp =
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 1.0) + 29] -
         Copy_4_of_laod_arduino_2021_B.Product1) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.dist_fut = sin
        (Copy_4_of_laod_arduino_2021_B.b_a_tmp / 2.0);
      Copy_4_of_laod_arduino_2021_B.psi_ref_tmp =
        Copy_4_of_laod_arduino_2021_B.psi_ref_tmp * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.a_fut_tmp = cos
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp);
      Copy_4_of_laod_arduino_2021_B.dist_fut =
        Copy_4_of_laod_arduino_2021_B.Gain3 *
        Copy_4_of_laod_arduino_2021_B.a_fut_tmp *
        (Copy_4_of_laod_arduino_2021_B.dist_fut *
         Copy_4_of_laod_arduino_2021_B.dist_fut) +
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp *
        Copy_4_of_laod_arduino_2021_B.a_tmp_tmp;
      Copy_4_of_laod_arduino_2021_B.dist_fut = rt_atan2d_snf(sqrt
        (Copy_4_of_laod_arduino_2021_B.dist_fut), sqrt(1.0 -
        Copy_4_of_laod_arduino_2021_B.dist_fut)) * 2.0 * 6.378137E+6;
      Copy_4_of_laod_arduino_2021_B.Gain3 = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.b_a_tmp) *
        Copy_4_of_laod_arduino_2021_B.a_fut_tmp, sin
        (Copy_4_of_laod_arduino_2021_B.psi_ref_tmp) *
        Copy_4_of_laod_arduino_2021_B.Gain3 - cos
        (Copy_4_of_laod_arduino_2021_B.b_a_tmp) * (sin
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 23] *
         3.1415926535897931 / 180.0) * Copy_4_of_laod_arduino_2021_B.a_fut_tmp))
        * 180.0 / 3.1415926535897931;
      if (Copy_4_of_laod_arduino_2021_B.Gain3 < 0.0) {
        Copy_4_of_laod_arduino_2021_B.Gain3 = 360.0 - fabs
          (Copy_4_of_laod_arduino_2021_B.Gain3);
      }

      if (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput > 1.0) {
        Copy_4_of_laod_arduino_2021_B.Gain3 = fabs
          (Copy_4_of_laod_arduino_2021_B.Gain3 -
           Copy_4_of_laod_arduino_2021_B.Al_selector);
      } else {
        Copy_4_of_laod_arduino_2021_B.Gain3 = fabs
          (Copy_4_of_laod_arduino_2021_B.Gain3 - rt_atan2d_snf(sin
            ((Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
              Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 29] -
              Copy_4_of_laod_arduino_2021_DW.long1) * 3.1415926535897931 / 180.0)
            * cos(Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
                  Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 23] *
                  3.1415926535897931 / 180.0), sin
            (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
             Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 23] *
             3.1415926535897931 / 180.0) * cos
            (Copy_4_of_laod_arduino_2021_DW.lat1 * 3.1415926535897931 / 180.0) -
            cos(Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
                Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 23] *
                3.1415926535897931 / 180.0) * sin
            (Copy_4_of_laod_arduino_2021_DW.lat1 * 3.1415926535897931 / 180.0) *
            cos((Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
                 Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 29] -
                 Copy_4_of_laod_arduino_2021_DW.long1) * 3.1415926535897931 /
                180.0)) * 180.0 / 3.1415926535897931);
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.dist_fut = 0.0;
      Copy_4_of_laod_arduino_2021_B.Gain3 = 0.0;
    }

    if (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput < 2.0) {
      Copy_4_of_laod_arduino_2021_B.Gain2_g = 0.0;
    } else if (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput == 2.0) {
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
        Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[24] *
        3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.b_a_tmp = cos
        (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0);
      Copy_4_of_laod_arduino_2021_B.Gain_n =
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[30] -
         Copy_4_of_laod_arduino_2021_DW.long1) * 3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Gain2_g = fabs
        (Copy_4_of_laod_arduino_2021_B.Al_selector - rt_atan2d_snf(sin
          (Copy_4_of_laod_arduino_2021_B.Gain_n) *
          Copy_4_of_laod_arduino_2021_B.b_a_tmp, cos
          (Copy_4_of_laod_arduino_2021_DW.lat1 * 3.1415926535897931 / 180.0) *
          sin(Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0) - sin
          (Copy_4_of_laod_arduino_2021_DW.lat1 * 3.1415926535897931 / 180.0) *
          Copy_4_of_laod_arduino_2021_B.b_a_tmp * cos
          (Copy_4_of_laod_arduino_2021_B.Gain_n)) * 180.0 / 3.1415926535897931);
    } else {
      Copy_4_of_laod_arduino_2021_B.Gain2_g = cos
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0);
      Copy_4_of_laod_arduino_2021_B.PWM_elevator_l =
        Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
        (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Gain_n =
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 1.0) + 29] -
         Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 2.0) + 29]) *
        3.1415926535897931 / 180.0;
      Copy_4_of_laod_arduino_2021_B.Gain2_g = rt_atan2d_snf(sin
        (Copy_4_of_laod_arduino_2021_B.Gain_n) *
        Copy_4_of_laod_arduino_2021_B.Gain2_g, cos
        (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) * sin
        (Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
         (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0) - sin
        (Copy_4_of_laod_arduino_2021_B.PWM_elevator_l) *
        Copy_4_of_laod_arduino_2021_B.Gain2_g * cos
        (Copy_4_of_laod_arduino_2021_B.Gain_n)) * 180.0 / 3.1415926535897931;
      if (Copy_4_of_laod_arduino_2021_B.Gain2_g < 0.0) {
        Copy_4_of_laod_arduino_2021_B.Gain2_g = 360.0 - fabs
          (Copy_4_of_laod_arduino_2021_B.Gain2_g);
      }

      Copy_4_of_laod_arduino_2021_B.Gain2_g = fabs
        (Copy_4_of_laod_arduino_2021_B.Al_selector -
         Copy_4_of_laod_arduino_2021_B.Gain2_g);
    }

    if (Copy_4_of_laod_arduino_2021_B.Gain3 <= 10.0) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 40.0;
      Copy_4_of_laod_arduino_2021_B.AL = 100;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain3 > 10.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain3 <= 50.0)) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 60.0;
      Copy_4_of_laod_arduino_2021_B.AL = 250;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain3 > 50.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain3 <= 90.0)) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 80.0;
      Copy_4_of_laod_arduino_2021_B.AL = 300;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain3 > 90.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain3 <= 120.0)) {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 120.0;
      Copy_4_of_laod_arduino_2021_B.AL = 350;
    } else {
      Copy_4_of_laod_arduino_2021_B.Al_selector = 150.0;
      Copy_4_of_laod_arduino_2021_B.AL = 400;
    }

    if (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 10.0) {
      Copy_4_of_laod_arduino_2021_B.caso = 50;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain2_g > 10.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 50.0)) {
      Copy_4_of_laod_arduino_2021_B.caso = 200;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain2_g > 50.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 90.0)) {
      Copy_4_of_laod_arduino_2021_B.caso = 300;
    } else if ((Copy_4_of_laod_arduino_2021_B.Gain2_g > 90.0) &&
               (Copy_4_of_laod_arduino_2021_B.Gain2_g <= 120.0)) {
      Copy_4_of_laod_arduino_2021_B.caso = 350;
    } else {
      Copy_4_of_laod_arduino_2021_B.caso = 400;
    }

    if (Copy_4_of_laod_arduino_2021_B.ATO == 1) {
      Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 =
        Copy_4_of_laod_arduino_2021_B.DataTypeConversion4_m[(int32_T)
        Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput + 11];
      if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 < 15.0) {
        Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 = 25.0;
      }

      if (!(Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 <= 20.0)) {
        if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 <= 25.0) {
          Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.2;
        } else if (Copy_4_of_laod_arduino_2021_B.rtb_Gain1_i_idx_0 <= 30.0) {
          Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.3;
        } else {
          Copy_4_of_laod_arduino_2021_B.Al_selector *= 1.4;
        }
      }

      if (((!(Copy_4_of_laod_arduino_2021_B.dist <
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_B.Switch_bk >
              Copy_4_of_laod_arduino_2021_B.Al_selector))) &&
          ((!(Copy_4_of_laod_arduino_2021_B.dist >
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_B.Switch_bk >
              Copy_4_of_laod_arduino_2021_B.Al_selector))) &&
          (Copy_4_of_laod_arduino_2021_B.Switch_bk <
           Copy_4_of_laod_arduino_2021_B.Al_selector)) {
        if (Copy_4_of_laod_arduino_2021_B.dist_fut >
            Copy_4_of_laod_arduino_2021_B.AL) {
          Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput++;
        } else if (Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput < 5.0) {
          Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput += 2.0;
        } else {
          Copy_4_of_laod_arduino_2021_B.QUOTA =
            Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] + 0.4;
        }
      }

      Copy_4_of_laod_arduino_2021_DW.flag_m = 0.0;
    } else {
      if (((!(Copy_4_of_laod_arduino_2021_B.dist <
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_DW.flag_m == 0.0))) &&
          ((!(Copy_4_of_laod_arduino_2021_B.dist >
              Copy_4_of_laod_arduino_2021_B.caso)) ||
           (!(Copy_4_of_laod_arduino_2021_B.Switch_bk > 40.0)) ||
           (!(Copy_4_of_laod_arduino_2021_DW.flag_m == 0.0)))) {
        Copy_4_of_laod_arduino_2021_B.QUOTA =
          Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] + 0.4;
        Copy_4_of_laod_arduino_2021_DW.flag_m = 1.0;
      }
    }

    if ((Copy_4_of_laod_arduino_2021_B.Wp_selector == 0.0) &&
        (Copy_4_of_laod_arduino_2021_B.Product1 == 0.0) &&
        (Copy_4_of_laod_arduino_2021_B.QUOTA == 0.0)) {
      Copy_4_of_laod_arduino_2021_B.QUOTA =
        Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] + 0.3;
    }

    /* End of MATLAB Function: '<S443>/WAYPOINTS' */
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem' incorporates:
   *  EnablePort: '<S441>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.Vec_selector > 0.0) {
    /* MATLAB Function: '<S441>/VETTORIALE' incorporates:
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     *  Memory: '<S441>/Memory1'
     *  Memory: '<S441>/Memory3'
     *  Memory: '<S441>/Memory6'
     */
    if ((Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] !=
         Copy_4_of_laod_arduino_2021_DW.Memory6_PreviousInput) ||
        (Copy_4_of_laod_arduino_2021_B.modo !=
         Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput) ||
        (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] !=
         Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_h)) {
      Copy_4_of_laod_arduino_2021_DW.ALT_ref =
        Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2];
    }

    if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4] == 1) {
      Copy_4_of_laod_arduino_2021_B.h_vett =
        Copy_4_of_laod_arduino_2021_DW.riferimenti[9];
    } else {
      Copy_4_of_laod_arduino_2021_B.h_vett =
        Copy_4_of_laod_arduino_2021_DW.ALT_ref;
    }

    /* Update for Memory: '<S441>/Memory1' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_h =
      Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[4];

    /* Update for Memory: '<S441>/Memory3' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput =
      Copy_4_of_laod_arduino_2021_B.modo;

    /* Update for Memory: '<S441>/Memory6' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory6_PreviousInput =
      Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1];
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem3' incorporates:
   *  EnablePort: '<S444>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.Go_home_selector > 0.0) {
    /* Gain: '<S549>/Gain' */
    Copy_4_of_laod_arduino_2021_B.Gain1_f *=
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_ji;

    /* MATLAB Function: '<S444>/GO_HOME' incorporates:
     *  Constant: '<S41>/Constant'
     *  Gain: '<S550>/Gain'
     */
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = sin((0.0 -
      Copy_4_of_laod_arduino_2021_B.Gain1_f) * 3.1415926535897931 / 180.0 / 2.0);
    Copy_4_of_laod_arduino_2021_B.Switch_bk = sin((0.0 -
      Copy_4_of_laod_arduino_2021_P.Gain_Gain_gf *
      Copy_4_of_laod_arduino_2021_B.Gain1_p) * 3.1415926535897931 / 180.0 / 2.0);
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = cos
      (Copy_4_of_laod_arduino_2021_B.Gain1_f * 3.1415926535897931 / 180.0) *
      (Copy_4_of_laod_arduino_2021_B.Switch_bk *
       Copy_4_of_laod_arduino_2021_B.Switch_bk) +
      Copy_4_of_laod_arduino_2021_B.deltafalllimit *
      Copy_4_of_laod_arduino_2021_B.deltafalllimit;
    Copy_4_of_laod_arduino_2021_B.h_goHome =
      Copy_4_of_laod_arduino_2021_P.Constant_Value_g;
    if ((rt_atan2d_snf(sqrt(Copy_4_of_laod_arduino_2021_B.deltafalllimit), sqrt
                       (1.0 - Copy_4_of_laod_arduino_2021_B.deltafalllimit)) *
         2.0 * 6.378137E+6 < 30.0) && (Copy_4_of_laod_arduino_2021_DW.flag ==
         0.0)) {
      Copy_4_of_laod_arduino_2021_DW.flag = 1.0;
      Copy_4_of_laod_arduino_2021_B.h_goHome =
        Copy_4_of_laod_arduino_2021_P.Constant_Value_g + 0.4;
    }

    /* End of MATLAB Function: '<S444>/GO_HOME' */
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem3' */

  /* MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation2' */
  switch ((int32_T)Copy_4_of_laod_arduino_2021_B.modo) {
   case 1:
    Copy_4_of_laod_arduino_2021_B.Gain1_p = Copy_4_of_laod_arduino_2021_B.QUOTA;
    break;

   case 2:
    Copy_4_of_laod_arduino_2021_B.Gain1_p = Copy_4_of_laod_arduino_2021_B.h_vett;
    break;

   case 3:
    Copy_4_of_laod_arduino_2021_B.Gain1_p = Copy_4_of_laod_arduino_2021_B.h_ref;
    break;

   case 4:
    Copy_4_of_laod_arduino_2021_B.Gain1_p =
      Copy_4_of_laod_arduino_2021_B.QUOTA_m;
    break;

   default:
    Copy_4_of_laod_arduino_2021_B.Gain1_p =
      Copy_4_of_laod_arduino_2021_B.h_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S41>/Switch di selezione  Task - Waypoint navigation2' */

  /* Abs: '<S42>/Abs' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   *  Sum: '<S42>/Sum1'
   */
  Copy_4_of_laod_arduino_2021_B.Gain1_f = fabs
    (Copy_4_of_laod_arduino_2021_B.Gain1_p -
     Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2]);

  /* Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  if (Copy_4_of_laod_arduino_2021_DW.is_active_c23_Copy_4_of_laod_ar == 0U) {
    Copy_4_of_laod_arduino_2021_DW.is_active_c23_Copy_4_of_laod_ar = 1U;
    Copy_4_of_laod_arduino_2021_DW.is_c23_Copy_4_of_laod_arduino_2 =
      Copy_4_of_laod_arduin_IN_Select;
  } else if (Copy_4_of_laod_arduino_2021_DW.is_c23_Copy_4_of_laod_arduino_2 == 1)
  {
    if (Copy_4_of_laod_arduino_2021_B.Gain1_f > 10.0) {
      Copy_4_of_laod_arduino_2021_DW.is_c23_Copy_4_of_laod_arduino_2 =
        Copy_4_of_laod_arduin_IN_Select;
    }
  } else {
    /* case IN_Select: */
    if (Copy_4_of_laod_arduino_2021_B.Gain1_f < 10.0) {
      Copy_4_of_laod_arduino_2021_DW.is_c23_Copy_4_of_laod_arduino_2 =
        Copy_4_of_laod_arduino__IN_Hold;
    }
  }

  /* End of Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */

  /* MATLABSystem: '<S570>/Serial Receive1' */
  if (Copy_4_of_laod_arduino_2021_DW.obj_e.Protocol !=
      Copy_4_of_laod_arduino_2021_P.SerialReceive1_Protocol) {
    Copy_4_of_laod_arduino_2021_DW.obj_e.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, Copy_4_of_laod_arduino_2021_DW.obj_e.DataSizeInBytes,
                 &Copy_4_of_laod_arduino_2021_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S570>/Subsystem2' incorporates:
   *  EnablePort: '<S581>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S581>/Create_message' */
    status = 0U;
    if (!Copy_4_of_laod_arduino_2021_DW.start_found) {
      Copy_4_of_laod_arduino_2021_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.i - 1 < 32)) {
        if (Copy_4_of_laod_arduino_2021_B.b_dataOut[(uint8_T)
            Copy_4_of_laod_arduino_2021_B.i - 1] == 36) {
          Copy_4_of_laod_arduino_2021_B.caso = 32 - (uint8_T)
            Copy_4_of_laod_arduino_2021_B.i;
          for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
               Copy_4_of_laod_arduino_2021_B.ATO <=
               Copy_4_of_laod_arduino_2021_B.caso;
               Copy_4_of_laod_arduino_2021_B.ATO++) {
            Copy_4_of_laod_arduino_2021_DW.message[Copy_4_of_laod_arduino_2021_B.ATO]
              = Copy_4_of_laod_arduino_2021_B.b_dataOut[((uint8_T)
              Copy_4_of_laod_arduino_2021_B.i +
              Copy_4_of_laod_arduino_2021_B.ATO) - 1];
          }

          Copy_4_of_laod_arduino_2021_DW.counter_k = (uint8_T)(33 - (uint8_T)
            Copy_4_of_laod_arduino_2021_B.i);
          Copy_4_of_laod_arduino_2021_DW.start_found = true;
          exitg1 = true;
        } else {
          Copy_4_of_laod_arduino_2021_B.i++;
        }
      }
    } else {
      Copy_4_of_laod_arduino_2021_B.g = 1;
      exitg1 = false;
      while ((!exitg1) && (Copy_4_of_laod_arduino_2021_B.g - 1 < 32)) {
        if (Copy_4_of_laod_arduino_2021_B.b_dataOut[(uint8_T)
            Copy_4_of_laod_arduino_2021_B.g - 1] == 13) {
          Copy_4_of_laod_arduino_2021_DW.end_found = true;
          status = (uint8_T)Copy_4_of_laod_arduino_2021_B.g;
          exitg1 = true;
        } else {
          Copy_4_of_laod_arduino_2021_B.g++;
        }
      }

      if (Copy_4_of_laod_arduino_2021_DW.end_found) {
        if (1 > status) {
          Copy_4_of_laod_arduino_2021_B.caso = -1;
        } else {
          Copy_4_of_laod_arduino_2021_B.caso = status - 1;
        }

        for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
             Copy_4_of_laod_arduino_2021_B.ATO <=
             Copy_4_of_laod_arduino_2021_B.caso;
             Copy_4_of_laod_arduino_2021_B.ATO++) {
          Copy_4_of_laod_arduino_2021_B.g = (int32_T)(((uint32_T)
            Copy_4_of_laod_arduino_2021_B.ATO +
            Copy_4_of_laod_arduino_2021_DW.counter_k) + 1U);
          if ((uint32_T)Copy_4_of_laod_arduino_2021_B.g > 255U) {
            Copy_4_of_laod_arduino_2021_B.g = 255;
          }

          Copy_4_of_laod_arduino_2021_DW.message[Copy_4_of_laod_arduino_2021_B.g
            - 1] =
            Copy_4_of_laod_arduino_2021_B.b_dataOut[Copy_4_of_laod_arduino_2021_B.ATO];
        }

        memcpy(&Copy_4_of_laod_arduino_2021_B.messaggio_b[0],
               &Copy_4_of_laod_arduino_2021_DW.message[0], 80U * sizeof(uint8_T));
        Copy_4_of_laod_arduino_2021_DW.end_found = false;
        Copy_4_of_laod_arduino_2021_DW.counter_k = (uint8_T)(32 - status);
        if (status == 32) {
          Copy_4_of_laod_arduino_2021_DW.start_found = false;
          memset(&Copy_4_of_laod_arduino_2021_DW.message[0], 0, 80U * sizeof
                 (uint8_T));
        } else {
          Copy_4_of_laod_arduino_2021_DW.start_found = true;
          Copy_4_of_laod_arduino_2021_B.caso = -status;
          for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
               Copy_4_of_laod_arduino_2021_B.ATO <=
               Copy_4_of_laod_arduino_2021_B.caso + 31;
               Copy_4_of_laod_arduino_2021_B.ATO++) {
            Copy_4_of_laod_arduino_2021_DW.message[Copy_4_of_laod_arduino_2021_B.ATO]
              = Copy_4_of_laod_arduino_2021_B.b_dataOut[status +
              Copy_4_of_laod_arduino_2021_B.ATO];
          }

          Copy_4_of_laod_arduino_2021_B.ATO = status + 48;
          if (0 <= Copy_4_of_laod_arduino_2021_B.ATO - 1) {
            memset(&Copy_4_of_laod_arduino_2021_DW.message[-status + 32], 0,
                   ((Copy_4_of_laod_arduino_2021_B.ATO - status) + status) *
                   sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S581>/Subsystem' incorporates:
         *  EnablePort: '<S583>/Enable'
         */
        /* MATLAB Function: '<S583>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        Copy_4_of_laod_arduino_2021_B.indice_dimario = 0U;
        for (Copy_4_of_laod_arduino_2021_B.i = 0;
             Copy_4_of_laod_arduino_2021_B.i < 80;
             Copy_4_of_laod_arduino_2021_B.i++) {
          messaggio = (int8_T)
            Copy_4_of_laod_arduino_2021_B.messaggio_b[Copy_4_of_laod_arduino_2021_B.i];
          if (messaggio == '$') {
            Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              Copy_4_of_laod_arduino_2021_B.ATO = 255;
            }

            status = (uint8_T)Copy_4_of_laod_arduino_2021_B.ATO;
          }

          if (messaggio == ',') {
            Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              Copy_4_of_laod_arduino_2021_B.ATO = 255;
            }

            find_comma = (uint8_T)Copy_4_of_laod_arduino_2021_B.ATO;
          }

          Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.i]
            = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
               Copy_4_of_laod_arduino_2021_B.ATO < 80;
               Copy_4_of_laod_arduino_2021_B.ATO++) {
            Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
              =
              (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
               == '$');
          }

          Copy_4_of_laod_arduino_eml_find
            (Copy_4_of_laod_arduino_2021_B.messaggio_c,
             &Copy_4_of_laod_arduino_2021_B.eb_data,
             Copy_4_of_laod_arduino_2021_B.eb_size);
          Copy_4_of_laod_arduino_2021_B.AL =
            Copy_4_of_laod_arduino_2021_B.eb_data;
          for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
               Copy_4_of_laod_arduino_2021_B.ATO < 5;
               Copy_4_of_laod_arduino_2021_B.ATO++) {
            messaggio =
              Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO
              + Copy_4_of_laod_arduino_2021_B.AL];
            Copy_4_of_laod_arduino_2021_B.mess_type_b[Copy_4_of_laod_arduino_2021_B.ATO]
              = (messaggio == bb[Copy_4_of_laod_arduino_2021_B.ATO]);
            Copy_4_of_laod_arduino_2021_B.mess_type[Copy_4_of_laod_arduino_2021_B.ATO]
              = messaggio;
          }

          if (Copy_4_of_laod_ar_ifWhileCond_o
              (Copy_4_of_laod_arduino_2021_B.mess_type_b)) {
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO < 80;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
                 == ',');
            }

            Copy_4_of_laod_ardui_eml_find_o
              (Copy_4_of_laod_arduino_2021_B.messaggio_c,
               Copy_4_of_laod_arduino_2021_B.comma_gga_data,
               Copy_4_of_laod_arduino_2021_B.eb_size);
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO < 80;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
                 == '*');
            }

            Copy_4_of_laod_ardui_eml_find_o
              (Copy_4_of_laod_arduino_2021_B.messaggio_c,
               Copy_4_of_laod_arduino_2021_B.star_data,
               Copy_4_of_laod_arduino_2021_B.star_size);
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO < 80;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
                 == '$');
            }

            Copy_4_of_laod_ardui_eml_find_o
              (Copy_4_of_laod_arduino_2021_B.messaggio_c,
               Copy_4_of_laod_arduino_2021_B.fb_data,
               Copy_4_of_laod_arduino_2021_B.star_size);
            Copy_4_of_laod_arduino_2021_B.Lat_1 =
              Copy_4_of_laod_ardui_str2double
              (&Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.comma_gga_data
               [2]]);
            if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[2] + 3.0 >
                (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[3] - 1.0) {
              Copy_4_of_laod_arduino_2021_B.c = 0;
              Copy_4_of_laod_arduino_2021_B.ATO = 0;
            } else {
              Copy_4_of_laod_arduino_2021_B.c =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[2] + 2;
              Copy_4_of_laod_arduino_2021_B.ATO =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[3] - 1;
            }

            Copy_4_of_laod_arduino_2021_B.messaggio_size[0] = 1;
            Copy_4_of_laod_arduino_2021_B.AL = Copy_4_of_laod_arduino_2021_B.ATO
              - Copy_4_of_laod_arduino_2021_B.c;
            Copy_4_of_laod_arduino_2021_B.messaggio_size[1] =
              Copy_4_of_laod_arduino_2021_B.AL;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <
                 Copy_4_of_laod_arduino_2021_B.AL;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.c
                + Copy_4_of_laod_arduino_2021_B.ATO];
            }

            Copy_4_of_laod_arduino_2021_B.b_x = Copy_4_of_laod_ard_str2double_l
              (Copy_4_of_laod_arduino_2021_B.messaggio_data,
               Copy_4_of_laod_arduino_2021_B.messaggio_size);
            if (Copy_4_of_laod_arduino_2021_B.b_x.im == 0.0) {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
            } else if (Copy_4_of_laod_arduino_2021_B.b_x.re == 0.0) {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
            } else {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
            }

            Copy_4_of_laod_arduino_2021_B.Gain1_f =
              Copy_4_of_laod_arduino_2021_B.Lat_1.re +
              Copy_4_of_laod_arduino_2021_B.Go_home_selector;
            Copy_4_of_laod_arduino_2021_B.caso =
              Copy_4_of_laod_arduino_2021_B.eb_size[0] *
              Copy_4_of_laod_arduino_2021_B.eb_size[1] - 1;
            if (0 <= Copy_4_of_laod_arduino_2021_B.caso) {
              memcpy(&Copy_4_of_laod_arduino_2021_B.tmp_data[0],
                     &Copy_4_of_laod_arduino_2021_B.comma_gga_data[0],
                     (Copy_4_of_laod_arduino_2021_B.caso + 1) * sizeof(int32_T));
            }

            if (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.tmp_data
                [3]] == 'S') {
              Copy_4_of_laod_arduino_2021_B.Gain1_f =
                -Copy_4_of_laod_arduino_2021_B.Gain1_f;
            }

            Copy_4_of_laod_arduino_2021_B.Lat_1 =
              Copy_4_of_laod_ar_str2double_lv
              (&Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.comma_gga_data
               [4]]);
            if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[4] + 4.0 >
                (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[5] - 1.0) {
              Copy_4_of_laod_arduino_2021_B.g = 0;
              Copy_4_of_laod_arduino_2021_B.i = 0;
            } else {
              Copy_4_of_laod_arduino_2021_B.g =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[4] + 3;
              Copy_4_of_laod_arduino_2021_B.i =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[5] - 1;
            }

            Copy_4_of_laod_arduino_2021_B.messaggio_size_f[0] = 1;
            Copy_4_of_laod_arduino_2021_B.AL = Copy_4_of_laod_arduino_2021_B.i -
              Copy_4_of_laod_arduino_2021_B.g;
            Copy_4_of_laod_arduino_2021_B.messaggio_size_f[1] =
              Copy_4_of_laod_arduino_2021_B.AL;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <
                 Copy_4_of_laod_arduino_2021_B.AL;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.g
                + Copy_4_of_laod_arduino_2021_B.ATO];
            }

            Copy_4_of_laod_arduino_2021_B.b_x = Copy_4_of_laod_ard_str2double_l
              (Copy_4_of_laod_arduino_2021_B.messaggio_data,
               Copy_4_of_laod_arduino_2021_B.messaggio_size_f);
            if (Copy_4_of_laod_arduino_2021_B.b_x.im == 0.0) {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
            } else if (Copy_4_of_laod_arduino_2021_B.b_x.re == 0.0) {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
            } else {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
            }

            Copy_4_of_laod_arduino_2021_B.Go_home_selector +=
              Copy_4_of_laod_arduino_2021_B.Lat_1.re;
            if (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.tmp_data
                [5]] == 'W') {
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                -Copy_4_of_laod_arduino_2021_B.Go_home_selector;
            }

            if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[6] + 1.0 >
                (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[7] - 1.0) {
              Copy_4_of_laod_arduino_2021_B.g = 0;
              Copy_4_of_laod_arduino_2021_B.i = 0;
            } else {
              Copy_4_of_laod_arduino_2021_B.g =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[6];
              Copy_4_of_laod_arduino_2021_B.i =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[7] - 1;
            }

            Copy_4_of_laod_arduino_2021_B.messaggio_size_g[0] = 1;
            Copy_4_of_laod_arduino_2021_B.AL = Copy_4_of_laod_arduino_2021_B.i -
              Copy_4_of_laod_arduino_2021_B.g;
            Copy_4_of_laod_arduino_2021_B.messaggio_size_g[1] =
              Copy_4_of_laod_arduino_2021_B.AL;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <
                 Copy_4_of_laod_arduino_2021_B.AL;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.g
                + Copy_4_of_laod_arduino_2021_B.ATO];
            }

            Copy_4_of_laod_arduino_2021_B.Lat_1 =
              Copy_4_of_laod_ard_str2double_l
              (Copy_4_of_laod_arduino_2021_B.messaggio_data,
               Copy_4_of_laod_arduino_2021_B.messaggio_size_g);

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[2] =
              Copy_4_of_laod_arduino_2021_B.Lat_1.re;
            if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[7] + 1.0 >
                (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[8] - 1.0) {
              Copy_4_of_laod_arduino_2021_B.caso = 0;
              Copy_4_of_laod_arduino_2021_B.ATO = 0;
            } else {
              Copy_4_of_laod_arduino_2021_B.caso =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[7];
              Copy_4_of_laod_arduino_2021_B.ATO =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[8] - 1;
            }

            Copy_4_of_laod_arduino_2021_B.messaggio_size_g1[0] = 1;
            Copy_4_of_laod_arduino_2021_B.AL = Copy_4_of_laod_arduino_2021_B.ATO
              - Copy_4_of_laod_arduino_2021_B.caso;
            Copy_4_of_laod_arduino_2021_B.messaggio_size_g1[1] =
              Copy_4_of_laod_arduino_2021_B.AL;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <
                 Copy_4_of_laod_arduino_2021_B.AL;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.caso
                + Copy_4_of_laod_arduino_2021_B.ATO];
            }

            Copy_4_of_laod_arduino_2021_B.Lat_1 =
              Copy_4_of_laod_ard_str2double_l
              (Copy_4_of_laod_arduino_2021_B.messaggio_data,
               Copy_4_of_laod_arduino_2021_B.messaggio_size_g1);

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[4] =
              Copy_4_of_laod_arduino_2021_B.Lat_1.re;
            if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[9] + 1.0 >
                (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[10] - 1.0)
            {
              Copy_4_of_laod_arduino_2021_B.caso = 0;
              Copy_4_of_laod_arduino_2021_B.ATO = 0;
            } else {
              Copy_4_of_laod_arduino_2021_B.caso =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[9];
              Copy_4_of_laod_arduino_2021_B.ATO =
                Copy_4_of_laod_arduino_2021_B.comma_gga_data[10] - 1;
            }

            Copy_4_of_laod_arduino_2021_B.messaggio_size_m[0] = 1;
            Copy_4_of_laod_arduino_2021_B.AL = Copy_4_of_laod_arduino_2021_B.ATO
              - Copy_4_of_laod_arduino_2021_B.caso;
            Copy_4_of_laod_arduino_2021_B.messaggio_size_m[1] =
              Copy_4_of_laod_arduino_2021_B.AL;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <
                 Copy_4_of_laod_arduino_2021_B.AL;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.caso
                + Copy_4_of_laod_arduino_2021_B.ATO];
            }

            Copy_4_of_laod_arduino_2021_B.Lat_1 =
              Copy_4_of_laod_ard_str2double_l
              (Copy_4_of_laod_arduino_2021_B.messaggio_data,
               Copy_4_of_laod_arduino_2021_B.messaggio_size_m);

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[3] =
              Copy_4_of_laod_arduino_2021_B.Lat_1.re;
            if (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.tmp_data
                [10]] == 'W') {
              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[3] =
                -Copy_4_of_laod_arduino_2021_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] =
              Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[5];
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[6] =
              Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[6];
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7] =
              Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[7];
            Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[8] =
              Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[8];
            if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 1.0 < 256.0)
            {
              if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 1.0 >=
                  0.0) {
                status = (uint8_T)((real_T)
                                   Copy_4_of_laod_arduino_2021_B.star_data[0] +
                                   1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = Copy_4_of_laod_arduino_2021_B.messaggio_k[status - 1];
            if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 2.0 < 256.0)
            {
              if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 2.0 >=
                  0.0) {
                status = (uint8_T)((real_T)
                                   Copy_4_of_laod_arduino_2021_B.star_data[0] +
                                   2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = Copy_4_of_laod_arduino_2021_B.messaggio_k[status - 1];
            if ((real_T)Copy_4_of_laod_arduino_2021_B.fb_data[0] + 1.0 > (real_T)
                Copy_4_of_laod_arduino_2021_B.star_data[0] - 1.0) {
              Copy_4_of_laod_arduino_2021_B.caso = 0;
              Copy_4_of_laod_arduino_2021_B.AL = 0;
            } else {
              Copy_4_of_laod_arduino_2021_B.caso =
                Copy_4_of_laod_arduino_2021_B.fb_data[0];
              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.star_data[0] - 1;
            }

            Copy_4_of_laod_arduino_2021_B.AL -=
              Copy_4_of_laod_arduino_2021_B.caso;
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO <
                 Copy_4_of_laod_arduino_2021_B.AL;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.NMEA_gga_string_data[Copy_4_of_laod_arduino_2021_B.ATO]
                = (uint8_T)
                Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.caso
                + Copy_4_of_laod_arduino_2021_B.ATO];
            }

            status = 0U;
            Copy_4_of_laod_arduino_2021_B.g = 0;
            while (Copy_4_of_laod_arduino_2021_B.g <=
                   Copy_4_of_laod_arduino_2021_B.AL - 1) {
              status ^=
                Copy_4_of_laod_arduino_2021_B.NMEA_gga_string_data[Copy_4_of_laod_arduino_2021_B.g];
              Copy_4_of_laod_arduino_2021_B.g++;
            }

            if (status != Copy_4_of_laod_arduino__hex2dec(ck_ric)) {
              Copy_4_of_laod_arduino_2021_B.Gain1_f =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[0];
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[2] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[2];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[3] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[3];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[4] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[4];
              Copy_4_of_laod_arduino_2021_B.indice_dimario = 10U;
            }
          } else {
            for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                 Copy_4_of_laod_arduino_2021_B.ATO < 5;
                 Copy_4_of_laod_arduino_2021_B.ATO++) {
              Copy_4_of_laod_arduino_2021_B.mess_type_b[Copy_4_of_laod_arduino_2021_B.ATO]
                =
                (Copy_4_of_laod_arduino_2021_B.mess_type[Copy_4_of_laod_arduino_2021_B.ATO]
                 == cb[Copy_4_of_laod_arduino_2021_B.ATO]);
            }

            if (Copy_4_of_laod_ar_ifWhileCond_o
                (Copy_4_of_laod_arduino_2021_B.mess_type_b)) {
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO < 80;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
                   == ',');
              }

              Copy_4_of_laod_ardui_eml_find_o
                (Copy_4_of_laod_arduino_2021_B.messaggio_c,
                 Copy_4_of_laod_arduino_2021_B.comma_gga_data,
                 Copy_4_of_laod_arduino_2021_B.eb_size);
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO < 80;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
                   == '*');
              }

              Copy_4_of_laod_ardui_eml_find_o
                (Copy_4_of_laod_arduino_2021_B.messaggio_c,
                 Copy_4_of_laod_arduino_2021_B.star_data,
                 Copy_4_of_laod_arduino_2021_B.star_size);
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO < 80;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_c[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.ATO]
                   == '$');
              }

              Copy_4_of_laod_ardui_eml_find_o
                (Copy_4_of_laod_arduino_2021_B.messaggio_c,
                 Copy_4_of_laod_arduino_2021_B.fb_data,
                 Copy_4_of_laod_arduino_2021_B.star_size);
              Copy_4_of_laod_arduino_2021_B.Lat_1 =
                Copy_4_of_laod_ardui_str2double
                (&Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.comma_gga_data
                 [1]]);
              if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[1] + 3.0 >
                  (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[2] - 1.0)
              {
                Copy_4_of_laod_arduino_2021_B.caso = 0;
                Copy_4_of_laod_arduino_2021_B.ATO = 0;
              } else {
                Copy_4_of_laod_arduino_2021_B.caso =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[1] + 2;
                Copy_4_of_laod_arduino_2021_B.ATO =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[2] - 1;
              }

              Copy_4_of_laod_arduino_2021_B.messaggio_size[0] = 1;
              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.ATO -
                Copy_4_of_laod_arduino_2021_B.caso;
              Copy_4_of_laod_arduino_2021_B.messaggio_size[1] =
                Copy_4_of_laod_arduino_2021_B.AL;
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO <
                   Copy_4_of_laod_arduino_2021_B.AL;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.caso
                  + Copy_4_of_laod_arduino_2021_B.ATO];
              }

              Copy_4_of_laod_arduino_2021_B.b_x =
                Copy_4_of_laod_ard_str2double_l
                (Copy_4_of_laod_arduino_2021_B.messaggio_data,
                 Copy_4_of_laod_arduino_2021_B.messaggio_size);
              if (Copy_4_of_laod_arduino_2021_B.b_x.im == 0.0) {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                  Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
              } else if (Copy_4_of_laod_arduino_2021_B.b_x.re == 0.0) {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
              } else {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                  Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
              }

              Copy_4_of_laod_arduino_2021_B.Gain1_f =
                Copy_4_of_laod_arduino_2021_B.Lat_1.re +
                Copy_4_of_laod_arduino_2021_B.Go_home_selector;
              Copy_4_of_laod_arduino_2021_B.caso =
                Copy_4_of_laod_arduino_2021_B.eb_size[0] *
                Copy_4_of_laod_arduino_2021_B.eb_size[1] - 1;
              if (0 <= Copy_4_of_laod_arduino_2021_B.caso) {
                memcpy(&Copy_4_of_laod_arduino_2021_B.tmp_data[0],
                       &Copy_4_of_laod_arduino_2021_B.comma_gga_data[0],
                       (Copy_4_of_laod_arduino_2021_B.caso + 1) * sizeof(int32_T));
              }

              if (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.tmp_data
                  [2]] == 'S') {
                Copy_4_of_laod_arduino_2021_B.Gain1_f =
                  -Copy_4_of_laod_arduino_2021_B.Gain1_f;
              }

              Copy_4_of_laod_arduino_2021_B.Lat_1 =
                Copy_4_of_laod_ar_str2double_lv
                (&Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.comma_gga_data
                 [3]]);
              if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[3] + 4.0 >
                  (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[4] - 1.0)
              {
                Copy_4_of_laod_arduino_2021_B.g = 0;
                Copy_4_of_laod_arduino_2021_B.ATO = 0;
              } else {
                Copy_4_of_laod_arduino_2021_B.g =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[3] + 3;
                Copy_4_of_laod_arduino_2021_B.ATO =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[4] - 1;
              }

              Copy_4_of_laod_arduino_2021_B.messaggio_size_f[0] = 1;
              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.ATO -
                Copy_4_of_laod_arduino_2021_B.g;
              Copy_4_of_laod_arduino_2021_B.messaggio_size_f[1] =
                Copy_4_of_laod_arduino_2021_B.AL;
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO <
                   Copy_4_of_laod_arduino_2021_B.AL;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.g
                  + Copy_4_of_laod_arduino_2021_B.ATO];
              }

              Copy_4_of_laod_arduino_2021_B.b_x =
                Copy_4_of_laod_ard_str2double_l
                (Copy_4_of_laod_arduino_2021_B.messaggio_data,
                 Copy_4_of_laod_arduino_2021_B.messaggio_size_f);
              if (Copy_4_of_laod_arduino_2021_B.b_x.im == 0.0) {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                  Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
              } else if (Copy_4_of_laod_arduino_2021_B.b_x.re == 0.0) {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector = 0.0;
              } else {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                  Copy_4_of_laod_arduino_2021_B.b_x.re / 60.0;
              }

              Copy_4_of_laod_arduino_2021_B.Go_home_selector +=
                Copy_4_of_laod_arduino_2021_B.Lat_1.re;
              if (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.tmp_data
                  [4]] == 'W') {
                Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                  -Copy_4_of_laod_arduino_2021_B.Go_home_selector;
              }

              Copy_4_of_laod_arduino_2021_B.Lat_1 =
                Copy_4_of_laod_a_str2double_lvk
                (Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] =
                Copy_4_of_laod_arduino_2021_B.Lat_1.re;
              if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[6] + 1.0 >
                  (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[7] - 1.0)
              {
                Copy_4_of_laod_arduino_2021_B.caso = 0;
                Copy_4_of_laod_arduino_2021_B.ATO = 0;
              } else {
                Copy_4_of_laod_arduino_2021_B.caso =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[6];
                Copy_4_of_laod_arduino_2021_B.ATO =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[7] - 1;
              }

              Copy_4_of_laod_arduino_2021_B.messaggio_size_g[0] = 1;
              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.ATO -
                Copy_4_of_laod_arduino_2021_B.caso;
              Copy_4_of_laod_arduino_2021_B.messaggio_size_g[1] =
                Copy_4_of_laod_arduino_2021_B.AL;
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO <
                   Copy_4_of_laod_arduino_2021_B.AL;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.caso
                  + Copy_4_of_laod_arduino_2021_B.ATO];
              }

              Copy_4_of_laod_arduino_2021_B.Lat_1 =
                Copy_4_of_laod_ard_str2double_l
                (Copy_4_of_laod_arduino_2021_B.messaggio_data,
                 Copy_4_of_laod_arduino_2021_B.messaggio_size_g);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[6] =
                Copy_4_of_laod_arduino_2021_B.Lat_1.re;
              if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[8] + 1.0 >
                  (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[9] - 1.0)
              {
                Copy_4_of_laod_arduino_2021_B.g = 0;
                Copy_4_of_laod_arduino_2021_B.ATO = 0;
              } else {
                Copy_4_of_laod_arduino_2021_B.g =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[8];
                Copy_4_of_laod_arduino_2021_B.ATO =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[9] - 1;
              }

              Copy_4_of_laod_arduino_2021_B.messaggio_size_g1[0] = 1;
              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.ATO -
                Copy_4_of_laod_arduino_2021_B.g;
              Copy_4_of_laod_arduino_2021_B.messaggio_size_g1[1] =
                Copy_4_of_laod_arduino_2021_B.AL;
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO <
                   Copy_4_of_laod_arduino_2021_B.AL;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.g
                  + Copy_4_of_laod_arduino_2021_B.ATO];
              }

              Copy_4_of_laod_arduino_2021_B.Lat_1 =
                Copy_4_of_laod_ard_str2double_l
                (Copy_4_of_laod_arduino_2021_B.messaggio_data,
                 Copy_4_of_laod_arduino_2021_B.messaggio_size_g1);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7] =
                Copy_4_of_laod_arduino_2021_B.Lat_1.re;
              if ((real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[10] + 1.0
                  > (real_T)Copy_4_of_laod_arduino_2021_B.comma_gga_data[11] -
                  1.0) {
                Copy_4_of_laod_arduino_2021_B.i = 0;
                Copy_4_of_laod_arduino_2021_B.caso = 0;
              } else {
                Copy_4_of_laod_arduino_2021_B.i =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[10];
                Copy_4_of_laod_arduino_2021_B.caso =
                  Copy_4_of_laod_arduino_2021_B.comma_gga_data[11] - 1;
              }

              Copy_4_of_laod_arduino_2021_B.messaggio_size_m[0] = 1;
              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.caso -
                Copy_4_of_laod_arduino_2021_B.i;
              Copy_4_of_laod_arduino_2021_B.messaggio_size_m[1] =
                Copy_4_of_laod_arduino_2021_B.AL;
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO <
                   Copy_4_of_laod_arduino_2021_B.AL;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.messaggio_data[Copy_4_of_laod_arduino_2021_B.ATO]
                  =
                  Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.i
                  + Copy_4_of_laod_arduino_2021_B.ATO];
              }

              Copy_4_of_laod_arduino_2021_B.Lat_1 =
                Copy_4_of_laod_ard_str2double_l
                (Copy_4_of_laod_arduino_2021_B.messaggio_data,
                 Copy_4_of_laod_arduino_2021_B.messaggio_size_m);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[8] =
                Copy_4_of_laod_arduino_2021_B.Lat_1.re;
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[2] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[2];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[3] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[3];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[4] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[4];
              if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 1.0 <
                  256.0) {
                if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 1.0 >=
                    0.0) {
                  status = (uint8_T)((real_T)
                                     Copy_4_of_laod_arduino_2021_B.star_data[0]
                                     + 1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = Copy_4_of_laod_arduino_2021_B.messaggio_k[status - 1];
              if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 2.0 <
                  256.0) {
                if ((real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] + 2.0 >=
                    0.0) {
                  status = (uint8_T)((real_T)
                                     Copy_4_of_laod_arduino_2021_B.star_data[0]
                                     + 2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = Copy_4_of_laod_arduino_2021_B.messaggio_k[status - 1];
              if ((real_T)Copy_4_of_laod_arduino_2021_B.fb_data[0] + 1.0 >
                  (real_T)Copy_4_of_laod_arduino_2021_B.star_data[0] - 1.0) {
                Copy_4_of_laod_arduino_2021_B.caso = 0;
                Copy_4_of_laod_arduino_2021_B.ATO = 0;
              } else {
                Copy_4_of_laod_arduino_2021_B.caso =
                  Copy_4_of_laod_arduino_2021_B.fb_data[0];
                Copy_4_of_laod_arduino_2021_B.ATO =
                  Copy_4_of_laod_arduino_2021_B.star_data[0] - 1;
              }

              Copy_4_of_laod_arduino_2021_B.AL =
                Copy_4_of_laod_arduino_2021_B.ATO -
                Copy_4_of_laod_arduino_2021_B.caso;
              for (Copy_4_of_laod_arduino_2021_B.ATO = 0;
                   Copy_4_of_laod_arduino_2021_B.ATO <
                   Copy_4_of_laod_arduino_2021_B.AL;
                   Copy_4_of_laod_arduino_2021_B.ATO++) {
                Copy_4_of_laod_arduino_2021_B.NMEA_gga_string_data[Copy_4_of_laod_arduino_2021_B.ATO]
                  = (uint8_T)
                  Copy_4_of_laod_arduino_2021_B.messaggio_k[Copy_4_of_laod_arduino_2021_B.caso
                  + Copy_4_of_laod_arduino_2021_B.ATO];
              }

              status = 0U;
              Copy_4_of_laod_arduino_2021_B.ATO = 0;
              while (Copy_4_of_laod_arduino_2021_B.ATO <=
                     Copy_4_of_laod_arduino_2021_B.AL - 1) {
                status ^=
                  Copy_4_of_laod_arduino_2021_B.NMEA_gga_string_data[Copy_4_of_laod_arduino_2021_B.ATO];
                Copy_4_of_laod_arduino_2021_B.ATO++;
              }

              if (status != Copy_4_of_laod_arduino__hex2dec(ck_ric)) {
                Copy_4_of_laod_arduino_2021_B.Gain1_f =
                  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[0];
                Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[1];

                /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
                Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] =
                  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[5];
                Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[6] =
                  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[6];
                Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7] =
                  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[7];
                Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[8] =
                  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[8];
                Copy_4_of_laod_arduino_2021_B.indice_dimario = 20U;
              }
            } else {
              Copy_4_of_laod_arduino_2021_B.Gain1_f =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[0];
              Copy_4_of_laod_arduino_2021_B.Go_home_selector =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[2] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[2];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[3] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[3];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[4] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[4];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[5];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[6] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[6];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[7];
              Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[8] =
                Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[8];
            }
          }
        } else {
          Copy_4_of_laod_arduino_2021_B.Gain1_f =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[0];
          Copy_4_of_laod_arduino_2021_B.Go_home_selector =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[1];

          /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[2] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[2];
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[3] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[3];
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[4] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[4];
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[5];
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[6] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[6];
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[7];
          Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[8] =
            Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[8];
        }

        /* End of MATLAB Function: '<S583>/MATLAB Function' */

        /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
        Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[0] =
          Copy_4_of_laod_arduino_2021_B.Gain1_f;
        Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[1] =
          Copy_4_of_laod_arduino_2021_B.Go_home_selector;

        /* Update for Memory: '<S583>/Memory' */
        memcpy(&Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[0],
               &Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[0], 9U * sizeof
               (real_T));

        /* End of Outputs for SubSystem: '<S581>/Subsystem' */
      } else {
        for (Copy_4_of_laod_arduino_2021_B.i = 0;
             Copy_4_of_laod_arduino_2021_B.i < 32;
             Copy_4_of_laod_arduino_2021_B.i++) {
          Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)(((uint32_T)
            Copy_4_of_laod_arduino_2021_DW.counter_k +
            Copy_4_of_laod_arduino_2021_B.i) + 1U);
          if ((uint32_T)Copy_4_of_laod_arduino_2021_B.ATO > 255U) {
            Copy_4_of_laod_arduino_2021_B.ATO = 255;
          }

          Copy_4_of_laod_arduino_2021_DW.message[Copy_4_of_laod_arduino_2021_B.ATO
            - 1] =
            Copy_4_of_laod_arduino_2021_B.b_dataOut[Copy_4_of_laod_arduino_2021_B.i];
        }

        Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)
          (Copy_4_of_laod_arduino_2021_DW.counter_k + 32U);
        if (Copy_4_of_laod_arduino_2021_DW.counter_k + 32U > 255U) {
          Copy_4_of_laod_arduino_2021_B.ATO = 255;
        }

        Copy_4_of_laod_arduino_2021_DW.counter_k = (uint8_T)
          Copy_4_of_laod_arduino_2021_B.ATO;
      }
    }

    /* End of MATLAB Function: '<S581>/Create_message' */
  }

  /* End of MATLABSystem: '<S570>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S570>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S570>/Subsystem1' incorporates:
   *  EnablePort: '<S580>/Enable'
   */
  if (Copy_4_of_laod_arduino_2021_B.SFunction_o14 > 0) {
    /* Switch: '<S580>/Switch' incorporates:
     *  Constant: '<S580>/Constant'
     *  Constant: '<S580>/Constant1'
     *  Constant: '<S580>/Constant3'
     *  Logic: '<S580>/OR'
     *  RelationalOperator: '<S580>/Equal'
     *  RelationalOperator: '<S580>/Equal1'
     *  RelationalOperator: '<S580>/Equal2'
     */
    if ((Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] ==
         Copy_4_of_laod_arduino_2021_P.Constant_Value_l) ||
        (Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] ==
         Copy_4_of_laod_arduino_2021_P.Constant1_Value_b) ||
        (Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5] ==
         Copy_4_of_laod_arduino_2021_P.Constant3_Value_ct)) {
      /* Switch: '<S580>/Switch' */
      Copy_4_of_laod_arduino_2021_B.Switch =
        Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S580>/Switch' incorporates:
       *  Constant: '<S580>/Constant2'
       */
      Copy_4_of_laod_arduino_2021_B.Switch =
        Copy_4_of_laod_arduino_2021_P.Constant2_Value_d;
    }

    /* End of Switch: '<S580>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S570>/Subsystem1' */

  /* MATLAB Function: '<S569>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S569>/Data Type Conversion'
   *  UnitDelay: '<S572>/Delay Input2'
   *
   * Block description for '<S572>/Delay Input2':
   *
   *  Store in Global RAM
   */
  Copy_4_of_laod_arduino_2021_B.Gain1_f = log
    (Copy_4_of_laod_arduino_2021_DW.DelayInput2_DSTATE / (real_T)
     Copy_4_of_laod_arduino_2021_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S556>/Data Type Conversion4' incorporates:
   *  MATLAB Function: '<S569>/MATLAB Function1'
   *  Sum: '<S570>/Sum'
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion4[0] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[0];
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion4[1] = (real32_T)
    Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[1];
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion4[2] = (real32_T)
    (Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[7] -
     Copy_4_of_laod_arduino_2021_B.Switch);
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion4[3] = (real32_T)
    (29.260958205912335 * Copy_4_of_laod_arduino_2021_B.Gain1_f) *
    (Copy_4_of_laod_arduino_2021_B.Switch1 + 273.15F) / (real32_T)(1.0 -
    -0.095098114169215084 * Copy_4_of_laod_arduino_2021_B.Gain1_f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  Gain: '<S561>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_n *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[3] *
     Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[3] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  Gain: '<S562>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_db *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[4] *
     Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[4] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  Gain: '<S563>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_dc *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[5] *
     Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[5] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[6]));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[0] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[0]));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[6] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[7]));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[1] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[1]));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[7] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[8]));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[2] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Copy_4_of_laod_arduino_2021_B.f = (real32_T)floor((real32_T)
    (Copy_4_of_laod_arduino_2021_P.Gain_Gain_bk *
     Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_pb[2]));
  if (rtIsNaNF(Copy_4_of_laod_arduino_2021_B.f) || rtIsInfF
      (Copy_4_of_laod_arduino_2021_B.f)) {
    Copy_4_of_laod_arduino_2021_B.f = 0.0F;
  } else {
    Copy_4_of_laod_arduino_2021_B.f = (real32_T)fmod
      (Copy_4_of_laod_arduino_2021_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[8] = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Copy_4_of_laod_arduino_2021_B.f : (int32_T)(int16_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.f);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S594>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion7'
   *  Product: '<S594>/Divide'
   *  Product: '<S594>/Multiply'
   *  Sum: '<S594>/Sum'
   *  Sum: '<S594>/Sum3'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    ((Copy_4_of_laod_arduino_2021_B.Sum3_o -
      Copy_4_of_laod_arduino_2021_P.attuatore_Emin) /
     Copy_4_of_laod_arduino_2021_B.rtb_Sum3_o_tmp *
     Copy_4_of_laod_arduino_2021_B.Go_Home + (real_T)
     Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[3]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion_p = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S591>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion9'
   *  Product: '<S591>/Divide'
   *  Product: '<S591>/Multiply'
   *  Sum: '<S591>/Sum'
   *  Sum: '<S591>/Sum3'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    ((Copy_4_of_laod_arduino_2021_B.PWM_rudder_p -
      Copy_4_of_laod_arduino_2021_P.attuatore_Amin) /
     Copy_4_of_laod_arduino_2021_B.rtb_Sum3_b_tmp *
     Copy_4_of_laod_arduino_2021_B.Ato_selector + (real_T)
     Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[5]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_c = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S592>/Constant'
   *  Constant: '<S592>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion10'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   *  Product: '<S592>/Divide'
   *  Product: '<S592>/Multiply'
   *  Sum: '<S592>/Sum'
   *  Sum: '<S592>/Sum1'
   *  Sum: '<S592>/Sum2'
   *  Sum: '<S592>/Sum3'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    ((Copy_4_of_laod_arduino_2021_B.Sum2_o -
      Copy_4_of_laod_arduino_2021_P.attuatore_Rmin) /
     (Copy_4_of_laod_arduino_2021_P.attuatore_Rmax -
      Copy_4_of_laod_arduino_2021_P.attuatore_Rmin) * (real_T)
     (Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[6] -
      Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[7]) +
     (real_T)Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[7]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_j = (int16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[4]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[0] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  Gain: '<S556>/Gain2'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_P.Gain2_Gain_m *
     Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[2]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[1] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion9'
   */
  Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)fmod
    (Copy_4_of_laod_arduino_2021_B.DataTypeConversion_p, 65536.0);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[2] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.ATO < 0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-(real_T)Copy_4_of_laod_arduino_2021_B.ATO : (int32_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.ATO);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion9'
   */
  Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)fmod
    (Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_c, 65536.0);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[3] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.ATO < 0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-(real_T)Copy_4_of_laod_arduino_2021_B.ATO : (int32_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.ATO);
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[4] = (uint16_T)
    Copy_4_of_laod_arduino_2021_B.PWM_throttle;
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[5] = (uint16_T)
    Copy_4_of_laod_arduino_2021_B.PWM_elevator;
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[6] = (uint16_T)
    Copy_4_of_laod_arduino_2021_B.PWM_aileron;
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[7] = (uint16_T)
    Copy_4_of_laod_arduino_2021_B.PWM_rudder;

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion9'
   */
  Copy_4_of_laod_arduino_2021_B.ATO = (int32_T)fmod
    (Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_j, 65536.0);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[8] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.ATO < 0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-(real_T)Copy_4_of_laod_arduino_2021_B.ATO : (int32_T)(uint16_T)
     Copy_4_of_laod_arduino_2021_B.ATO);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  Gain: '<S556>/Gain3'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor((real_T)
    Copy_4_of_laod_arduino_2021_P.Gain3_Gain *
    Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[9] = (uint16_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
     (int32_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);

  /* DataTypeConversion: '<S556>/Data Type Conversion6' */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[5]);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 256.0);
  }

  /* SignalConversion generated from: '<S556>/Byte Pack' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion6'
   */
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtBytePackIn[0] = (uint8_T)
    (Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)
     -(int8_T)(uint8_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit : (int32_T)
     (uint8_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit);
  Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtBytePackIn[1] =
    Copy_4_of_laod_arduino_2021_B.indice_dimario;

  /* DataTypeConversion: '<S556>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S569>/Data Type Conversion'
   */
  Copy_4_of_laod_arduino_2021_B.DataTypeConversion8 =
    Copy_4_of_laod_arduino_2021_B.SFunctionBuilder1;

  /* S-Function (any2byte_svd): '<S556>/Byte Pack' incorporates:
   *  Constant: '<S556>/Fine MSG1'
   *  Constant: '<S556>/Inizio MSG'
   */

  /* Pack: <S556>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_P.InizioMSG_Value[0],
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

    /* Packing the values of Input 2 */
    /* Input data type - real32_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.DataTypeConversion4[0],
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

    /* Packing the values of Input 3 */
    /* Input data type - int16_T, size - 9 */
    {
      MW_inputPortWidth = 9 * sizeof(int16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.DataTypeConversion_lx[0],
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

    /* Packing the values of Input 4 */
    /* Input data type - uint16_T, size - 10 */
    {
      MW_inputPortWidth = 10 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_h[0],
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

    /* Packing the values of Input 5 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtBytePackIn[0],
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
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_B.DataTypeConversion8,
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

    /* Packing the values of Input 7 */
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_4_of_laod_arduino_2021_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_4_of_laod_arduino_2021_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S556>/Serial Transmit' */
  if (Copy_4_of_laod_arduino_2021_DW.obj.Protocol !=
      Copy_4_of_laod_arduino_2021_P.SerialTransmit_Protocol_b) {
    Copy_4_of_laod_arduino_2021_DW.obj.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialTransmit_Protocol_b;
  }

  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 63;
       Copy_4_of_laod_arduino_2021_B.i++) {
    Copy_4_of_laod_arduino_2021_B.dataIn[Copy_4_of_laod_arduino_2021_B.i] =
      Copy_4_of_laod_arduino_2021_B.BytePack[Copy_4_of_laod_arduino_2021_B.i];
  }

  MW_Serial_write(Copy_4_of_laod_arduino_2021_DW.obj.port,
                  &Copy_4_of_laod_arduino_2021_B.dataIn[0], 63.0,
                  Copy_4_of_laod_arduino_2021_DW.obj.dataSizeInBytes,
                  Copy_4_of_laod_arduino_2021_DW.obj.sendModeEnum,
                  Copy_4_of_laod_arduino_2021_DW.obj.dataType,
                  Copy_4_of_laod_arduino_2021_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S556>/Serial Transmit' */

  /* S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */
  Servo_microseconds_alettoni_beta_3_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_c,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder10_DSTATE);

  /* Sum: '<S593>/Sum' incorporates:
   *  Product: '<S593>/Multiply'
   */
  Copy_4_of_laod_arduino_2021_B.deltafalllimit = floor
    (Copy_4_of_laod_arduino_2021_B.Gain1_kx *
     Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0);
  if (rtIsNaN(Copy_4_of_laod_arduino_2021_B.deltafalllimit) || rtIsInf
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit)) {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = 0.0;
  } else {
    Copy_4_of_laod_arduino_2021_B.deltafalllimit = fmod
      (Copy_4_of_laod_arduino_2021_B.deltafalllimit, 65536.0);
  }

  /* Sum: '<S593>/Sum' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   */
  Copy_4_of_laod_arduino_2021_B.Sum = (int16_T)
    ((Copy_4_of_laod_arduino_2021_B.deltafalllimit < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-Copy_4_of_laod_arduino_2021_B.deltafalllimit :
      (int32_T)(int16_T)(uint16_T)Copy_4_of_laod_arduino_2021_B.deltafalllimit)
     + (int16_T)
     Copy_4_of_laod_arduino_2021_B.One_time_initialization.ByteUnpack[1]);

  /* S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.Sum,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder4_DSTATE);

  /* S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */
  Servo_microseconds_timone_beta_3_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_j,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder5_DSTATE);

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_B.DataTypeConversion_p,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder9_DSTATE);

  /* HitCross: '<S252>/Hit  Crossing' */
  Copy_4_of_laod_arduino_2021_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &Copy_4_of_laod_arduino__PrevZCX.HitCrossing_Input_ZCE,
    (Copy_4_of_laod_arduino_2021_B.Gain1_p -
     Copy_4_of_laod_arduino_2021_P.HitCrossing_Offset));
  if (Copy_4_of_laod_arduino_2021_DW.HitCrossing_MODE == 0) {
    if (Copy_4_of_laod_arduino_2021_B.zcEvent != NO_ZCEVENT) {
      /* HitCross: '<S252>/Hit  Crossing' */
      Copy_4_of_laod_arduino_2021_B.HitCrossing =
        !Copy_4_of_laod_arduino_2021_B.HitCrossing;
      Copy_4_of_laod_arduino_2021_DW.HitCrossing_MODE = 1;
    } else {
      if (Copy_4_of_laod_arduino_2021_B.HitCrossing) {
        /* HitCross: '<S252>/Hit  Crossing' */
        Copy_4_of_laod_arduino_2021_B.HitCrossing =
          ((!(Copy_4_of_laod_arduino_2021_B.Gain1_p !=
              Copy_4_of_laod_arduino_2021_P.HitCrossing_Offset)) &&
           Copy_4_of_laod_arduino_2021_B.HitCrossing);
      }
    }
  } else {
    /* HitCross: '<S252>/Hit  Crossing' */
    Copy_4_of_laod_arduino_2021_B.HitCrossing =
      ((!(Copy_4_of_laod_arduino_2021_B.Gain1_p !=
          Copy_4_of_laod_arduino_2021_P.HitCrossing_Offset)) &&
       Copy_4_of_laod_arduino_2021_B.HitCrossing);
    Copy_4_of_laod_arduino_2021_DW.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<S252>/Hit  Crossing' */

  /* Abs: '<S418>/Abs1' */
  Copy_4_of_laod_arduino_2021_B.IProdOut = fabs
    (Copy_4_of_laod_arduino_2021_B.Sum3_b);

  /* Outputs for Resettable SubSystem: '<S410>/Resettable Subsystem' */
  Copy_4_of_laod_arduino_2021_B.IProdOut = Copy_4__ResettableSubsystem
    (Copy_4_of_laod_arduino_2021_B.SFunction_o4_n[1],
     &Copy_4_of_laod_arduino_2021_DW.ResettableSubsystem,
     &Copy_4_of_laod_arduino_2021_P.ResettableSubsystem,
     &Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S410>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S410>/Enabled Subsystem' */
  Copy_4_of__EnabledSubsystem(Copy_4_of_laod_arduino_2021_B.SFunction_o4_n[1],
    Copy_4_of_laod_arduino_2021_B.IProdOut,
    &Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_0,
    &Copy_4_of_laod_arduino_2021_P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S410>/Enabled Subsystem' */

  /* MATLAB Function: '<S412>/MATLAB Function1' */
  Copy_4_of_laod_arduino_2021_DW.Tf_not_empty =
    ((!Copy_4_of_laod_arduino_2021_DW.Tf_not_empty) ||
     (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[0] == 1) ||
     (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[1] == 0) ||
     Copy_4_of_laod_arduino_2021_DW.Tf_not_empty);

  /* Product: '<S565>/Product4' incorporates:
   *  MATLAB Function: '<S565>/MATLAB Function'
   */
  Copy_4_of_laod_arduino_2021_B.num_254 *= 1.0 - 2.0 *
    Copy_4_of_laod_arduino_2021_B.RateTransition;

  /* S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper
    (&Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput_c[0],
         &Copy_4_of_laod_arduino_2021_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S571>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S571>/S-Function Builder */
  Mti_Update_wrapper(&Copy_4_of_laod_arduino_2021_B.SFunctionBuilder[0],
                     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S569>/Unit Delay' incorporates:
   *  Constant: '<S569>/Constant3'
   */
  Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE_d =
    Copy_4_of_laod_arduino_2021_P.Constant3_Value_ok;

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&Copy_4_of_laod_arduino_2021_P.Constant1_Value_a,
    &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1_h[0],
    &Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o2,
    &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE_l);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&Copy_4_of_laod_arduino_2021_DW.Memory5_PreviousInput_l[0],
         &Copy_4_of_laod_arduino_2021_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[0] =
    Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[0];
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[1] =
    Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[1];
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[2] =
    Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[2];
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[3] =
    Copy_4_of_laod_arduino_2021_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (Copy_4_of_laod_arduino_2021_B.i = 0; Copy_4_of_laod_arduino_2021_B.i < 8;
       Copy_4_of_laod_arduino_2021_B.i++) {
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_ic[Copy_4_of_laod_arduino_2021_B.i]
      =
      Copy_4_of_laod_arduino_2021_B.SFunction_o11[Copy_4_of_laod_arduino_2021_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for UnitDelay: '<S565>/Unit Delay' incorporates:
   *  Sum: '<S565>/Sum1'
   */
  Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE =
    Copy_4_of_laod_arduino_2021_B.rtb_Gain1_kw_idx_1 +
    Copy_4_of_laod_arduino_2021_B.num_254;

  /* Update for DiscreteIntegrator: '<S342>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  beccheggio1'
   *  Gain: '<S335>/Kb'
   *  Gain: '<S353>/Kt'
   *  Product: '<S339>/IProd Out'
   *  Sum: '<S335>/SumI2'
   *  Sum: '<S335>/SumI4'
   *  Sum: '<S353>/SumI3'
   *  Sum: '<S354>/SumI1'
   */
  Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE +=
    (((Copy_4_of_laod_arduino_2021_B.SwitchBumpless2 -
       Copy_4_of_laod_arduino_2021_B.Saturation) *
      Copy_4_of_laod_arduino_2021_P.PIDController_Kt_m +
      Copy_4_of_laod_arduino_2021_B.Gain1_c *
      Copy_4_of_laod_arduino_2021_P.Ki_becch) +
     (Copy_4_of_laod_arduino_2021_B.Saturation -
      Copy_4_of_laod_arduino_2021_B.Sum_nu) *
     Copy_4_of_laod_arduino_2021_P.PIDController_Kb_k) *
    Copy_4_of_laod_arduino_2021_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S392>/Integrator' incorporates:
   *  Constant: '<S8>/Ki controllore  rollio3'
   *  Gain: '<S385>/Kb'
   *  Gain: '<S403>/Kt'
   *  Product: '<S389>/IProd Out'
   *  Sum: '<S385>/SumI2'
   *  Sum: '<S385>/SumI4'
   *  Sum: '<S403>/SumI3'
   *  Sum: '<S404>/SumI1'
   */
  Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE_p +=
    (((Copy_4_of_laod_arduino_2021_B.Alettoni -
       Copy_4_of_laod_arduino_2021_B.Saturation_f) *
      Copy_4_of_laod_arduino_2021_P.PIDController_Kt +
      Copy_4_of_laod_arduino_2021_B.Gain1_j *
      Copy_4_of_laod_arduino_2021_P.Ki_roll) +
     (Copy_4_of_laod_arduino_2021_B.Saturation_f -
      Copy_4_of_laod_arduino_2021_B.Sum_n3) *
     Copy_4_of_laod_arduino_2021_P.PIDController_Kb) *
    Copy_4_of_laod_arduino_2021_P.Integrator_gainval_g;
  if (Copy_4_of_laod_arduino_2021_B.Sum_o > 0.0) {
    Copy_4_of_laod_arduino_2021_DW.Integrator_PrevResetState = 1;
  } else if (Copy_4_of_laod_arduino_2021_B.Sum_o < 0.0) {
    Copy_4_of_laod_arduino_2021_DW.Integrator_PrevResetState = -1;
  } else if (Copy_4_of_laod_arduino_2021_B.Sum_o == 0.0) {
    Copy_4_of_laod_arduino_2021_DW.Integrator_PrevResetState = 0;
  } else {
    Copy_4_of_laod_arduino_2021_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S392>/Integrator' */

  /* Update for DiscreteTransferFcn: '<S306>/Discrete Washout Filter' */
  Copy_4_of_laod_arduino_2021_DW.DiscreteWashoutFilter_states =
    Copy_4_of_laod_arduino_2021_B.denAccum;

  /* Update for Memory: '<S2>/Memory' */
  Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_n =
    Copy_4_of_laod_arduino_2021_B.SFunction_o4;

  /* Update for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

  /* S-Function "Servo_microseconds_alettoni_beta_3_wrapper" Block: <S10>/S-Function Builder10 */
  Servo_microseconds_alettoni_beta_3_Update_wrapper
    (&Copy_4_of_laod_arduino_2021_B.DataTypeConversion1_c,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder10_DSTATE);

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <S10>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper
    (&Copy_4_of_laod_arduino_2021_B.Sum,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder4_DSTATE);

  /* Update for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

  /* S-Function "Servo_microseconds_timone_beta_3_wrapper" Block: <S10>/S-Function Builder5 */
  Servo_microseconds_timone_beta_3_Update_wrapper
    (&Copy_4_of_laod_arduino_2021_B.DataTypeConversion2_j,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder5_DSTATE);

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <S10>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper
    (&Copy_4_of_laod_arduino_2021_B.DataTypeConversion_p,
     &Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder9_DSTATE);

  /* Update for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S4>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper
    (&Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE_n);
}

/* Model step function for TID1 */
void Copy_4_of_laod_arduino_2021_step1(void) /* Sample time: [0.04s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  rtb_PulseGenerator = (Copy_4_of_laod_arduino_2021_DW.clockTickCounter <
                        Copy_4_of_laod_arduino_2021_P.PulseGenerator_Duty) &&
    (Copy_4_of_laod_arduino_2021_DW.clockTickCounter >= 0) ?
    Copy_4_of_laod_arduino_2021_P.PulseGenerator_Amp : 0.0;
  if (Copy_4_of_laod_arduino_2021_DW.clockTickCounter >=
      Copy_4_of_laod_arduino_2021_P.PulseGenerator_Period - 1.0) {
    Copy_4_of_laod_arduino_2021_DW.clockTickCounter = 0;
  } else {
    Copy_4_of_laod_arduino_2021_DW.clockTickCounter++;
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
  rtb_PulseGenerator = (Copy_4_of_laod_arduino_2021_DW.clockTickCounter_c <
                        Copy_4_of_laod_arduino_2021_P.PulseGenerator1_Duty) &&
    (Copy_4_of_laod_arduino_2021_DW.clockTickCounter_c >= 0) ?
    Copy_4_of_laod_arduino_2021_P.PulseGenerator1_Amp : 0.0;
  if (Copy_4_of_laod_arduino_2021_DW.clockTickCounter_c >=
      Copy_4_of_laod_arduino_2021_P.PulseGenerator1_Period - 1.0) {
    Copy_4_of_laod_arduino_2021_DW.clockTickCounter_c = 0;
  } else {
    Copy_4_of_laod_arduino_2021_DW.clockTickCounter_c++;
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
void Copy_4_of_laod_arduino_2021_step2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S29>/Add2' incorporates:
   *  Constant: '<S29>/Constant4'
   *  Constant: '<S29>/Constant5'
   *  Memory: '<S29>/Memory2'
   */
  Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput +=
    Copy_4_of_laod_arduino_2021_P.Constant4_Value_a +
    Copy_4_of_laod_arduino_2021_P.Constant5_Value_a;

  /* Switch: '<S29>/Switch1' */
  if (Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput >
      Copy_4_of_laod_arduino_2021_P.Switch1_Threshold_c) {
    /* Sum: '<S29>/Add2' incorporates:
     *  Constant: '<S29>/Constant4'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Constant4_Value_a;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* RateTransition: '<S29>/Rate Transition' */
  Copy_4_of_laod_arduino_2021_DW.RateTransition_Buffer0 =
    Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void Copy_4_of_laod_arduino_2021_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Copy_4_of_laod_arduino_2021_M, 0,
                sizeof(RT_MODEL_Copy_4_of_laod_ardui_T));

  /* block I/O */
  (void) memset(((void *) &Copy_4_of_laod_arduino_2021_B), 0,
                sizeof(B_Copy_4_of_laod_arduino_2021_T));

  /* states (dwork) */
  (void) memset((void *)&Copy_4_of_laod_arduino_2021_DW, 0,
                sizeof(DW_Copy_4_of_laod_arduino_202_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    codertarget_arduinobase_inter_T *obj;
    real_T Switch_a;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S571>/S-Function Builder' */

    /* S-Function Block: <S571>/S-Function Builder */
    Mti_Start_wrapper(&Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE);
    Copy_4_of_laod_arduino__PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem_Reset_ZCE_p =
      UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem_Reset_ZCE_h =
      UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.SampleandHold_Trig_ZCE_h =
      UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.SampleandHold1_Trig_ZCE =
      UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem_o.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;
    Copy_4_of_laod_arduino__PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput_c[0],
           &Copy_4_of_laod_arduino_2021_P.Memory4_InitialCondition_g[0], 300U *
           sizeof(uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S571>/S-Function Builder' */

    /* S-Function Block: <S571>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S569>/Unit Delay' */
    Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE_d =
      Copy_4_of_laod_arduino_2021_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE_l = initVector
            [0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      Copy_4_of_laod_arduino_2021_DW.Memory5_PreviousInput_l[i] =
        Copy_4_of_laod_arduino_2021_P.Memory5_InitialCondition_d;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[0] =
      Copy_4_of_laod_arduino_2021_P.Memory1_InitialCondition_b;
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_d[1] =
      Copy_4_of_laod_arduino_2021_P.Memory1_InitialCondition_b;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[0] =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_o;
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[1] =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_o;
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[2] =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_o;
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h5[3] =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_o;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput_o =
      Copy_4_of_laod_arduino_2021_P.Memory3_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_ic[i] =
        Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_at;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_a[i] =
        Copy_4_of_laod_arduino_2021_P.Memory2_InitialCondition_g[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S29>/Rate Transition' */
    Copy_4_of_laod_arduino_2021_DW.RateTransition_Buffer0 =
      Copy_4_of_laod_arduino_2021_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S29>/Switch' incorporates:
     *  Memory: '<S29>/Memory1'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory1_InitialCondition_p;

    /* InitializeConditions for Sum: '<S29>/Add' incorporates:
     *  Memory: '<S29>/Memory'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_au;

    /* InitializeConditions for UnitDelay: '<S565>/Unit Delay' */
    Copy_4_of_laod_arduino_2021_DW.UnitDelay_DSTATE =
      Copy_4_of_laod_arduino_2021_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S342>/Integrator' */
    Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE =
      Copy_4_of_laod_arduino_2021_P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S392>/Integrator' */
    Copy_4_of_laod_arduino_2021_DW.Integrator_DSTATE_p =
      Copy_4_of_laod_arduino_2021_P.PIDController_InitialConditio_d;
    Copy_4_of_laod_arduino_2021_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S306>/Discrete Washout Filter' */
    Copy_4_of_laod_arduino_2021_DW.DiscreteWashoutFilter_states =
      Copy_4_of_laod_arduino_2021_P.DiscreteWashoutFilter_InitialSt;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_n =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S572>/Delay Input2'
     *
     * Block description for '<S572>/Delay Input2':
     *
     *  Store in Global RAM
     */
    Copy_4_of_laod_arduino_2021_DW.DelayInput2_DSTATE =
      Copy_4_of_laod_arduino_2021_P.DelayInput2_InitialCondition;

    /* InitializeConditions for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

    /* S-Function Block: <S10>/S-Function Builder10 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder10_DSTATE = initVector
            [0];
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
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder4_DSTATE = initVector[0];
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
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder5_DSTATE = initVector[0];
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
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder9_DSTATE = initVector[0];
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
          Copy_4_of_laod_arduino_2021_DW.SFunctionBuilder_DSTATE_n = initVector
            [0];
        }
      }
    }

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
    Copy_4_of_laod_arduino_2021_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    Copy_4_of_laod_arduino_2021_DW.clockTickCounter_c = 0;

    /* InitializeConditions for Sum: '<S29>/Add2' incorporates:
     *  Memory: '<S29>/Memory2'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory2_InitialCondition_o;

    /* SystemInitialize for Enabled SubSystem: '<S569>/Execution_loop' */
    /* Start for MATLABSystem: '<S573>/I2C Read12' */
    Copy_4_of_laod_arduino_2021_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &Copy_4_of_laod_arduino_2021_DW.obj_f;
    Copy_4_of_laod_arduino_2021_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    Copy_4_of_laod_arduino_2021_DW.obj_f.isInitialized = 0;
    Copy_4_of_laod_arduino_2021_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    Copy_4_of_laod_arduino_2021_DW.obj_f.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_f.SampleTime =
      Copy_4_of_laod_arduino_2021_P.t_AP;
    obj = &Copy_4_of_laod_arduino_2021_DW.obj_f;
    Copy_4_of_laod_arduino_2021_DW.obj_f.isSetupComplete = false;
    Copy_4_of_laod_arduino_2021_DW.obj_f.isInitialized = 1;
    Copy_4_of_laod_arduino_2021_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (Copy_4_of_laod_arduino_2021_B.i2cname, 0);
    Copy_4_of_laod_arduino_2021_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = Copy_4_of_laod_arduino_2021_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    Copy_4_of_laod_arduino_2021_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S573>/I2C Read1' */
    Copy_4_of_laod_arduino_2021_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &Copy_4_of_laod_arduino_2021_DW.obj_p;
    Copy_4_of_laod_arduino_2021_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    Copy_4_of_laod_arduino_2021_DW.obj_p.isInitialized = 0;
    Copy_4_of_laod_arduino_2021_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    Copy_4_of_laod_arduino_2021_DW.obj_p.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_p.SampleTime =
      Copy_4_of_laod_arduino_2021_P.t_AP;
    obj = &Copy_4_of_laod_arduino_2021_DW.obj_p;
    Copy_4_of_laod_arduino_2021_DW.obj_p.isSetupComplete = false;
    Copy_4_of_laod_arduino_2021_DW.obj_p.isInitialized = 1;
    Copy_4_of_laod_arduino_2021_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (Copy_4_of_laod_arduino_2021_B.i2cname, 0);
    Copy_4_of_laod_arduino_2021_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = Copy_4_of_laod_arduino_2021_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    Copy_4_of_laod_arduino_2021_DW.obj_p.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S573>/S-Function Builder' incorporates:
     *  Outport: '<S573>/T'
     */
    Copy_4_of_laod_arduino_2021_B.SFunctionBuilder_o1 =
      Copy_4_of_laod_arduino_2021_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S573>/S-Function Builder1' incorporates:
     *  Outport: '<S573>/p'
     */
    Copy_4_of_laod_arduino_2021_B.SFunctionBuilder1 =
      Copy_4_of_laod_arduino_2021_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S569>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S569>/MATLAB Function' */
    Copy_4_of_laod_arduino_2021_DW.P_ref = 101325.0;
    Copy_4_of_laod_arduino_2021_DW.rl_up = 300.0;
    Copy_4_of_laod_arduino_2021_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S569>/One_time_initialization' */
    One_time_initializatio_Init
      (&Copy_4_of_laod_arduino_2021_B.One_time_initialization,
       &Copy_4_of_laod_arduino_2021_DW.One_time_initialization,
       &Copy_4_of_laod_arduino_2021_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S569>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S577>/Subsystem1' */
    /* SystemInitialize for Outport: '<S579>/T_0' incorporates:
     *  Inport: '<S579>/T'
     */
    Copy_4_of_laod_arduino_2021_B.T = Copy_4_of_laod_arduino_2021_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S577>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S570>/Subsystem1' */
    /* SystemInitialize for Switch: '<S580>/Switch' incorporates:
     *  Outport: '<S580>/h_to_subtract'
     */
    Copy_4_of_laod_arduino_2021_B.Switch =
      Copy_4_of_laod_arduino_2021_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S570>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S570>/Subsystem2' */
    /* SystemInitialize for MATLAB Function: '<S581>/Create_message' */
    Copy_4_of_laod_arduino_2021_DW.end_found = false;
    Copy_4_of_laod_arduino_2021_DW.start_found = false;
    Copy_4_of_laod_arduino_2021_DW.counter_k = 0U;
    memset(&Copy_4_of_laod_arduino_2021_DW.message[0], 0, 80U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S581>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S583>/Memory' */
      Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_l[i] =
        Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_ab;

      /* SystemInitialize for ComplexToRealImag: '<S583>/Complex to Real-Imag' incorporates:
       *  Outport: '<S583>/Outport'
       */
      Copy_4_of_laod_arduino_2021_B.ComplextoRealImag[i] =
        Copy_4_of_laod_arduino_2021_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S583>/mario' */
    Copy_4_of_laod_arduino_2021_B.indice_dimario =
      Copy_4_of_laod_arduino_2021_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S581>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S570>/Subsystem2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&Copy_4_of_laod_arduino_2021_DW.riferimenti[0], &tmp[0], sizeof
           (real32_T) << 4U);
    Copy_4_of_laod_arduino_2021_DW.WP_dbP_not_empty = false;
    Copy_4_of_laod_arduino_2021_DW.WP_dbP_AL_not_empty = false;
    Copy_4_of_laod_arduino_2021_DW.test1 = 0.0;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3' */
    Copy_4_of_laod_arduino_2021_DW.counter = 0U;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    Copy_4_of_laod_arduino_2021_DW.Interr_parz = false;
    memset(&Copy_4_of_laod_arduino_2021_DW.message_i[0], 0, 100U * sizeof
           (uint8_T));
    Copy_4_of_laod_arduino_2021_DW.counter_a = 0U;
    Copy_4_of_laod_arduino_2021_DW.mess_len = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    Copy_4_of_laod_arduino_2021_DW.is_active_c9_Copy_4_of_laod_ard = 0U;
    Copy_4_of_laod_arduino_2021_DW.i = 0U;

    /* SystemInitialize for Chart: '<S15>/Chart' incorporates:
     *  SubSystem: '<S24>/sendbyte'
     */
    /* Start for MATLABSystem: '<S25>/Serial Transmit' */
    Copy_4_of_laod_arduino_2021_DW.obj_o.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_o.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialTransmit_Protocol;
    Copy_4_of_laod_arduino_2021_DW.obj_o.isInitialized = 1;
    Copy_4_of_laod_arduino_2021_DW.obj_o.port = 2.0;
    Copy_4_of_laod_arduino_2021_DW.obj_o.dataSizeInBytes = 1.0;
    Copy_4_of_laod_arduino_2021_DW.obj_o.dataType = 0.0;
    Copy_4_of_laod_arduino_2021_DW.obj_o.sendModeEnum = 0.0;
    Copy_4_of_laod_arduino_2021_DW.obj_o.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(Copy_4_of_laod_arduino_2021_DW.obj_o.port);
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
    Copy_4_of_laod_arduino_2021_DW.obj_o.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S25>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Chart: '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
    Copy_4_of_laod_arduino_2021_DW.is_active_c23_Copy_4_of_laod_ar = 0U;
    Copy_4_of_laod_arduino_2021_DW.is_c23_Copy_4_of_laod_arduino_2 = 0;

    /* SystemInitialize for Chart: '<S40>/ STATI' */
    Copy_4_of_laod_arduino_2021_DW.is_AUTOMATICA = 0;
    Copy_4_of_laod_arduino_2021_DW.is_active_c26_Copy_4_of_laod_ar = 0U;
    Copy_4_of_laod_arduino_2021_DW.is_c26_Copy_4_of_laod_arduino_2 = 0;
    Copy_4_of_laod_arduino_2021_B.switch_manetta = 0.0;
    Copy_4_of_laod_arduino_2021_B.switch_equilibratore = 0.0;
    Copy_4_of_laod_arduino_2021_B.switch_alettoni = 0.0;
    Copy_4_of_laod_arduino_2021_B.switch_timone = 0.0;
    Copy_4_of_laod_arduino_2021_B.modo = 1.0;

    /* SystemInitialize for Enabled SubSystem: '<S410>/Enabled Subsystem' */
    Copy__EnabledSubsystem_Init(&Switch_a,
      &Copy_4_of_laod_arduino_2021_P.EnabledSubsystem_h);

    /* End of SystemInitialize for SubSystem: '<S410>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S410>/Resettable Subsystem' */
    Co_ResettableSubsystem_Init
      (&Copy_4_of_laod_arduino_2021_DW.ResettableSubsystem,
       &Copy_4_of_laod_arduino_2021_P.ResettableSubsystem);

    /* End of SystemInitialize for SubSystem: '<S410>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S411>/Enabled Subsystem' */
    Copy__EnabledSubsystem_Init(&Copy_4_of_laod_arduino_2021_B.Switch_l,
      &Copy_4_of_laod_arduino_2021_P.EnabledSubsystem_j);

    /* End of SystemInitialize for SubSystem: '<S411>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S411>/Resettable Subsystem' */
    Co_ResettableSubsystem_Init
      (&Copy_4_of_laod_arduino_2021_DW.ResettableSubsystem_o,
       &Copy_4_of_laod_arduino_2021_P.ResettableSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S411>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S412>/MATLAB Function1' */
    Copy_4_of_laod_arduino_2021_DW.Tf_not_empty = false;

    /* SystemInitialize for Enabled SubSystem: '<S434>/Enabled ' */
    /* SystemInitialize for Switch: '<S436>/Switch' incorporates:
     *  Outport: '<S436>/Alarm Safe'
     */
    Copy_4_of_laod_arduino_2021_B.Switch_n =
      Copy_4_of_laod_arduino_2021_P.AlarmSafe_Y0;

    /* End of SystemInitialize for SubSystem: '<S434>/Enabled ' */

    /* SystemInitialize for Resettable SubSystem: '<S434>/Resettable Subsystem' */
    /* InitializeConditions for Sum: '<S438>/Sum' incorporates:
     *  Memory: '<S438>/Memory'
     */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_h =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S434>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S417>/MATLAB Function1' */
    Copy_4_of_laod_arduino_2021_DW.alarm = 0.0;

    /* SystemInitialize for Chart: '<S41>/Chart' */
    Copy_4_of_laod_arduino_2021_DW.is_active_c21_Copy_4_of_laod_ar = 0U;
    Copy_4_of_laod_arduino_2021_DW.is_c21_Copy_4_of_laod_arduino_2 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S41>/DECOLLO AUTOMATICO' */
    /* InitializeConditions for Memory: '<S440>/Memory' */
    Copy_4_of_laod_arduino_2021_DW.Memory_PreviousInput_i =
      Copy_4_of_laod_arduino_2021_P.Memory_InitialCondition_a;

    /* InitializeConditions for Memory: '<S440>/Memory1' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_o =
      Copy_4_of_laod_arduino_2021_P.Memory1_InitialCondition;

    /* SystemInitialize for Chart: '<S440>/Chart1' */
    Copy_4_of_laod_arduino_2021_DW.temporalCounter_i1 = 0U;
    Copy_4_of_laod_arduino_2021_DW.is_active_c1_Copy_4_of_laod_ard = 0U;
    Copy_4_of_laod_arduino_2021_DW.is_c1_Copy_4_of_laod_arduino_20 = 0;

    /* End of SystemInitialize for SubSystem: '<S41>/DECOLLO AUTOMATICO' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem' */
    /* InitializeConditions for Memory: '<S441>/Memory1' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_h =
      Copy_4_of_laod_arduino_2021_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<S441>/Memory3' */
    Copy_4_of_laod_arduino_2021_DW.Memory3_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S441>/Memory6' */
    Copy_4_of_laod_arduino_2021_DW.Memory6_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory6_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S441>/VETTORIALE' */
    Copy_4_of_laod_arduino_2021_DW.ALT_ref = 0.0;

    /* SystemInitialize for Outport: '<S441>/Out2' */
    Copy_4_of_laod_arduino_2021_B.h_vett = Copy_4_of_laod_arduino_2021_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem1' */
    /* InitializeConditions for Memory: '<S442>/Memory7' */
    Copy_4_of_laod_arduino_2021_DW.Memory7_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S442>/Memory5' */
    Copy_4_of_laod_arduino_2021_DW.Memory5_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S442>/Memory1' */
    Copy_4_of_laod_arduino_2021_DW.Memory1_PreviousInput_l =
      Copy_4_of_laod_arduino_2021_P.Memory1_InitialCondition_f;

    /* InitializeConditions for Memory: '<S442>/Memory2' */
    Copy_4_of_laod_arduino_2021_DW.Memory2_PreviousInput_f =
      Copy_4_of_laod_arduino_2021_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S442>/ALLINEAMENTO' */
    Copy_4_of_laod_arduino_2021_DW.flag_c = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S442>/APPROACH' */
    /* InitializeConditions for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' */
    Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_DSTATE =
      Copy_4_of_laod_arduino_2021_P.DiscreteTimeIntegrator_IC;
    Copy_4_of_laod_arduino_2021_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* SystemInitialize for MATLAB Function: '<S453>/MATLAB Function' */
    Copy_4_of_laod_arduino_2021_DW.x_not_empty = false;
    Copy_4_of_laod_arduino_2021_DW.x_new_not_empty = false;
    Copy_4_of_laod_arduino_2021_DW.cycle_count_not_empty = false;
    Copy_4_of_laod_arduino_2021_DW.eps_not_empty = false;

    /* SystemInitialize for Product: '<S453>/Multiply' incorporates:
     *  Outport: '<S453>/h_ref'
     */
    Copy_4_of_laod_arduino_2021_B.Multiply =
      Copy_4_of_laod_arduino_2021_P.h_ref_Y0;

    /* SystemInitialize for Outport: '<S453>/flare_data' */
    Copy_4_of_laod_arduino_2021_B.x_f_out =
      Copy_4_of_laod_arduino_2021_P.flare_data_Y0;
    Copy_4_of_laod_arduino_2021_B.h_f_out =
      Copy_4_of_laod_arduino_2021_P.flare_data_Y0;
    Copy_4_of_laod_arduino_2021_B.k_x_out =
      Copy_4_of_laod_arduino_2021_P.flare_data_Y0;
    Copy_4_of_laod_arduino_2021_B.h_c_out =
      Copy_4_of_laod_arduino_2021_P.flare_data_Y0;

    /* SystemInitialize for Outport: '<S453>/landing_abort' */
    Copy_4_of_laod_arduino_2021_B.no_solution =
      Copy_4_of_laod_arduino_2021_P.landing_abort_Y0;

    /* End of SystemInitialize for SubSystem: '<S442>/APPROACH' */

    /* SystemInitialize for Chart: '<S442>/Chart1' */
    Copy_4_of_laod_arduino_2021_DW.is_active_c10_Copy_4_of_laod_ar = 0U;
    Copy_4_of_laod_arduino_2021_DW.is_c10_Copy_4_of_laod_arduino_2 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S442>/FLARE' */
    /* SystemInitialize for Sum: '<S457>/Sum2' incorporates:
     *  Outport: '<S457>/h_ref'
     */
    Copy_4_of_laod_arduino_2021_B.Sum2 =
      Copy_4_of_laod_arduino_2021_P.h_ref_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S442>/FLARE' */

    /* SystemInitialize for Triggered SubSystem: '<S442>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S467>/ ' incorporates:
     *  Inport: '<S467>/In'
     */
    Copy_4_of_laod_arduino_2021_B.In[0] = Copy_4_of_laod_arduino_2021_P._Y0_b[0];
    Copy_4_of_laod_arduino_2021_B.In[1] = Copy_4_of_laod_arduino_2021_P._Y0_b[1];

    /* End of SystemInitialize for SubSystem: '<S442>/Sample and Hold' */

    /* SystemInitialize for MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
     *  Outport: '<S442>/QUOTA_AL'
     */
    Copy_4_of_laod_arduino_2021_B.QUOTA_m =
      Copy_4_of_laod_arduino_2021_P.QUOTA_AL_Y0;

    /* SystemInitialize for Gain: '<S460>/Gain' incorporates:
     *  Outport: '<S442>/H_LAT'
     */
    Copy_4_of_laod_arduino_2021_B.Gain = Copy_4_of_laod_arduino_2021_P.H_LAT_Y0;

    /* SystemInitialize for Gain: '<S461>/Gain' incorporates:
     *  Outport: '<S442>/H_LONG'
     */
    Copy_4_of_laod_arduino_2021_B.Gain_g =
      Copy_4_of_laod_arduino_2021_P.H_LONG_Y0;

    /* SystemInitialize for Outport: '<S442>/H_ALT' */
    Copy_4_of_laod_arduino_2021_B.h_Home =
      Copy_4_of_laod_arduino_2021_P.H_ALT_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem2' */
    /* InitializeConditions for Memory: '<S443>/Memory4' */
    Copy_4_of_laod_arduino_2021_DW.Memory4_PreviousInput =
      Copy_4_of_laod_arduino_2021_P.Memory4_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S443>/WAYPOINTS' */
    Copy_4_of_laod_arduino_2021_DW.flag_m = 0.0;
    Copy_4_of_laod_arduino_2021_DW.lat1 = 0.0;
    Copy_4_of_laod_arduino_2021_DW.long1 = 0.0;

    /* SystemInitialize for Outport: '<S443>/Out3' */
    Copy_4_of_laod_arduino_2021_B.QUOTA =
      Copy_4_of_laod_arduino_2021_P.Out3_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem3' */
    /* SystemInitialize for MATLAB Function: '<S444>/GO_HOME' */
    Copy_4_of_laod_arduino_2021_DW.flag = 0.0;

    /* SystemInitialize for Outport: '<S444>/Out2' */
    Copy_4_of_laod_arduino_2021_B.h_goHome =
      Copy_4_of_laod_arduino_2021_P.Out2_Y0_c;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem3' */

    /* SystemInitialize for Enabled SubSystem: '<S556>/Subsystem1' */
    /* SystemInitialize for MATLAB Function: '<S564>/MATLAB Function' */
    Copy_4_of_laod_arduino_2021_DW.start_found_c = false;
    Copy_4_of_laod_arduino_2021_DW.counter_n = 0U;
    for (i = 0; i < 31; i++) {
      Copy_4_of_laod_arduino_2021_DW.message_k[i] = 0U;
    }

    /* End of SystemInitialize for MATLAB Function: '<S564>/MATLAB Function' */

    /* SystemInitialize for Enabled SubSystem: '<S564>/Subsystem2' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[0] =
      Copy_4_of_laod_arduino_2021_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[0] =
      Copy_4_of_laod_arduino_2021_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[1] =
      Copy_4_of_laod_arduino_2021_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[1] =
      Copy_4_of_laod_arduino_2021_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[2] =
      Copy_4_of_laod_arduino_2021_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[2] =
      Copy_4_of_laod_arduino_2021_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o2_e[3] =
      Copy_4_of_laod_arduino_2021_P.Out2_Y0_cb;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o3[3] =
      Copy_4_of_laod_arduino_2021_P.Out3_Y0_a;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out4'
     */
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o4[0] =
      Copy_4_of_laod_arduino_2021_P.Out4_Y0_i;
    Copy_4_of_laod_arduino_2021_B.ByteUnpack_o4[1] =
      Copy_4_of_laod_arduino_2021_P.Out4_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S564>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S556>/Subsystem1' */

    /* Start for MATLABSystem: '<S556>/Serial Receive' */
    Copy_4_of_laod_arduino_2021_DW.obj_m.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_m.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialReceive_Protocol;
    Copy_4_of_laod_arduino_2021_DW.obj_m.isInitialized = 1;
    Copy_4_of_laod_arduino_2021_DW.obj_m.DataTypeWidth = 1U;
    varargin_1 = 31U * Copy_4_of_laod_arduino_2021_DW.obj_m.DataTypeWidth;
    if (varargin_1 > 65535U) {
      varargin_1 = 65535U;
    }

    Copy_4_of_laod_arduino_2021_DW.obj_m.DataSizeInBytes = (uint16_T)varargin_1;
    MW_SCI_Open(0);
    Copy_4_of_laod_arduino_2021_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S556>/Serial Receive' */

    /* Start for MATLABSystem: '<S570>/Serial Receive1' */
    Copy_4_of_laod_arduino_2021_DW.obj_e.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_e.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialReceive1_Protocol;
    Copy_4_of_laod_arduino_2021_DW.obj_e.isInitialized = 1;
    Copy_4_of_laod_arduino_2021_DW.obj_e.DataTypeWidth = 1U;
    if (Copy_4_of_laod_arduino_2021_DW.obj_e.DataTypeWidth > 2047) {
      Copy_4_of_laod_arduino_2021_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      Copy_4_of_laod_arduino_2021_DW.obj_e.DataSizeInBytes = (uint16_T)
        (Copy_4_of_laod_arduino_2021_DW.obj_e.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    Copy_4_of_laod_arduino_2021_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S570>/Serial Receive1' */

    /* Start for MATLABSystem: '<S556>/Serial Transmit' */
    Copy_4_of_laod_arduino_2021_DW.obj.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj.Protocol =
      Copy_4_of_laod_arduino_2021_P.SerialTransmit_Protocol_b;
    Copy_4_of_laod_arduino_2021_DW.obj.isInitialized = 1;
    Copy_4_of_laod_arduino_2021_DW.obj.port = 0.0;
    Copy_4_of_laod_arduino_2021_DW.obj.dataSizeInBytes = 1.0;
    Copy_4_of_laod_arduino_2021_DW.obj.dataType = 0.0;
    Copy_4_of_laod_arduino_2021_DW.obj.sendModeEnum = 0.0;
    Copy_4_of_laod_arduino_2021_DW.obj.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(Copy_4_of_laod_arduino_2021_DW.obj.port);
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
    Copy_4_of_laod_arduino_2021_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S556>/Serial Transmit' */

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    Copy_4_of_laod_arduino_2021_DW.obj_d.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_d.isInitialized = 1;
    digitalIOSetup(13, 1);
    Copy_4_of_laod_arduino_2021_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    Copy_4_of_laod_arduino_2021_DW.obj_b.matlabCodegenIsDeleted = false;
    Copy_4_of_laod_arduino_2021_DW.obj_b.isInitialized = 1;
    digitalIOSetup(44, 1);
    Copy_4_of_laod_arduino_2021_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Copy_4_of_laod_arduino_2021_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S569>/One_time_initialization' */
  One_time_initializatio_Term
    (&Copy_4_of_laod_arduino_2021_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S569>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S569>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S573>/I2C Read12' */
  obj = &Copy_4_of_laod_arduino_2021_DW.obj_f;
  if (!Copy_4_of_laod_arduino_2021_DW.obj_f.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Copy_4_of_laod_arduino_2021_DW.obj_f.isInitialized == 1) &&
        Copy_4_of_laod_arduino_2021_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S573>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S573>/I2C Read1' */
  obj = &Copy_4_of_laod_arduino_2021_DW.obj_p;
  if (!Copy_4_of_laod_arduino_2021_DW.obj_p.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Copy_4_of_laod_arduino_2021_DW.obj_p.isInitialized == 1) &&
        Copy_4_of_laod_arduino_2021_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S573>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S569>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S556>/Serial Receive' */
  if (!Copy_4_of_laod_arduino_2021_DW.obj_m.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S556>/Serial Receive' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S15>/Chart' incorporates:
   *  SubSystem: '<S24>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  if (!Copy_4_of_laod_arduino_2021_DW.obj_o.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S570>/Serial Receive1' */
  if (!Copy_4_of_laod_arduino_2021_DW.obj_e.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S570>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<S556>/Serial Transmit' */
  if (!Copy_4_of_laod_arduino_2021_DW.obj.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S556>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!Copy_4_of_laod_arduino_2021_DW.obj_d.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!Copy_4_of_laod_arduino_2021_DW.obj_b.matlabCodegenIsDeleted) {
    Copy_4_of_laod_arduino_2021_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
