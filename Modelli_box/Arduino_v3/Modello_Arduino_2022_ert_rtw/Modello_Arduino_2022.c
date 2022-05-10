/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Modello_Arduino_2022.c
 *
 * Code generated for Simulink model 'Modello_Arduino_2022'.
 *
 * Model version                  : 5.39
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 10 14:41:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Modello_Arduino_2022.h"
#include "Modello_Arduino_2022_private.h"

/* Named constants for Chart: '<S40>/SELEZIONE MODALITA\'  HOLD//SELECT' */
#define Modello_Arduino_2022_IN_Hold   ((uint8_T)1U)
#define Modello_Arduino_2022_IN_Select ((uint8_T)2U)

/* Named constants for Chart: '<S38>/ STATI' */
#define Model_IN_ATTERRAGGIO_AUTOMATICO ((uint8_T)1U)
#define Modello_A_IN_DECOLLO_AUTOMATICO ((uint8_T)2U)
#define Modello_Ar_IN_Intervento_Pilota ((uint8_T)3U)
#define Modello_Arduino_2022_IN_Go_Home ((uint8_T)2U)
#define Modello_Arduino_2022_IN_MANUALE ((uint8_T)4U)
#define Modello_Arduino_2022_IN_Safe   ((uint8_T)5U)
#define Modello_Arduino_2022_IN_TEST   ((uint8_T)3U)
#define Modello_Arduino_202_IN_Stand_By ((uint8_T)6U)
#define Modello_Arduino_202_IN_WAYPOINT ((uint8_T)5U)
#define Modello_Arduino_2_IN_AUTOMATICA ((uint8_T)1U)
#define Modello_Arduino_2_IN_VETTORIALE ((uint8_T)4U)

/* Named constants for Chart: '<S39>/Chart' */
#define Modello_Arduino_2022_IN_GoHome ((uint8_T)3U)
#define Modello_Arduino_2022_IN_In     ((uint8_T)4U)
#define Modello_Arduino_202_IN_Waypoint ((uint8_T)6U)
#define Modello_Arduino_2_IN_Vettoriale ((uint8_T)5U)
#define Modello_Arduino__IN_AutoLanding ((uint8_T)1U)
#define Modello_Arduino__IN_AutoTakeoff ((uint8_T)2U)

/* Named constants for Chart: '<S440>/Chart1' */
#define Modello_Arduino_2_IN_Fase_0_ATO ((uint8_T)1U)
#define Modello_Arduino_2_IN_Fase_1_ATO ((uint8_T)2U)
#define Modello_Arduino_2_IN_Fase_2_ATO ((uint8_T)3U)
#define Modello_Arduino_2_IN_Fase_3_ATO ((uint8_T)4U)
#define Modello_Arduino_2_IN_Fase_4_ATO ((uint8_T)5U)

/* Named constants for Chart: '<S442>/Chart1' */
#define Modello_Arduino_2022_IN_Abort  ((uint8_T)1U)
#define Modello_Arduino_2022_IN_Flare  ((uint8_T)5U)
#define Modello_Arduino_202_IN_Approach ((uint8_T)4U)
#define Modello_Arduino_2_IN_Allignment ((uint8_T)2U)
#define Modello_Arduino__IN_Allignment1 ((uint8_T)3U)

const uint16_T Modello_Arduino_2022_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_Modello_Arduino_2022_T Modello_Arduino_2022_B;

/* Block states (default storage) */
DW_Modello_Arduino_2022_T Modello_Arduino_2022_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Modello_Arduino_2022_T Modello_Arduino_2022_PrevZCX;

/* Real-time model */
static RT_MODEL_Modello_Arduino_2022_T Modello_Arduino_2022_M_;
RT_MODEL_Modello_Arduino_2022_T *const Modello_Arduino_2022_M =
  &Modello_Arduino_2022_M_;

/* Forward declaration for local functions */
static void Modello_Arduino_2022_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T Modello_Arduino_202_ifWhileCond(const boolean_T x[100]);
static void Modello_Arduino_2022_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void Modello_Arduino_2022_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void Modello_Arduino_2022_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T Modello_Arduino_2_ifWhileCond_o(const boolean_T x[5]);
static void Modello_Arduino_2022_eml_find_o(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void Modello_Arduino_2_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T Modello_Arduino_2022_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T Modello_Arduino_20_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void Modello_Arduino_2022_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Modello_Arduino_2022_str2double(const char_T s[2]);
static boolean_T Modello_Arduino_20_copydigits_k(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void Modello_Arduino_202_readfloat_d(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T Modello_Arduino_20_str2double_l(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T Modello_Arduino_2022_isUnitImag(const char_T s[3], int32_T k);
static void Modello_Arduino_readNonFinite_l(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T Modello_Arduino_2_copydigits_k3(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T Modello_Arduino__copyexponent_k(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void Modello_Arduino_20_readfloat_dt(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Modello_Arduino_2_str2double_lv(const char_T s[3]);
static void Modello_Arduin_readNonFinite_ln(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T Modello_Arduino__copydigits_k3z(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T Modello_Arduino_copyexponent_kd(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void Modello_Arduino_2_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T Modello_Arduino__str2double_lvk(char_T s);
static real_T Modello_Arduino_2022_hex2dec(const char_T s[2]);
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
void Modello_Arduino_2022_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Modello_Arduino_2022_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Modello_Arduino_2022_M, 2));
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
  (Modello_Arduino_2022_M->Timing.TaskCounters.TID[1])++;
  if ((Modello_Arduino_2022_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    Modello_Arduino_2022_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Modello_Arduino_2022_M->Timing.TaskCounters.TID[2])++;
  if ((Modello_Arduino_2022_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.1s, 0.0s] */
    Modello_Arduino_2022_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S410>/Enabled Subsystem'
 *    '<S411>/Enabled Subsystem'
 */
void Model_EnabledSubsystem_Init(real_T *rty_u0, P_EnabledSubsystem_Modello_Ar_T
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
void Modello_Ar_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0, P_EnabledSubsystem_Modello_Ar_T *localP)
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
void Mo_ResettableSubsystem_Init(DW_ResettableSubsystem_Modell_T *localDW,
  P_ResettableSubsystem_Modello_T *localP)
{
  /* InitializeConditions for Memory: '<S421>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * System reset for atomic system:
 *    '<S410>/Resettable Subsystem'
 *    '<S411>/Resettable Subsystem'
 */
void M_ResettableSubsystem_Reset(DW_ResettableSubsystem_Modell_T *localDW,
  P_ResettableSubsystem_Modello_T *localP)
{
  /* InitializeConditions for Memory: '<S421>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S410>/Resettable Subsystem'
 *    '<S411>/Resettable Subsystem'
 */
real_T Modello_ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_Modell_T *localDW, P_ResettableSubsystem_Modello_T
  *localP, ZCE_ResettableSubsystem_Model_T *localZCE)
{
  real_T rty_Time_0;

  /* Outputs for Resettable SubSystem: '<S410>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S420>/Reset'
   */
  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_l != POS_ZCSIG))
  {
    M_ResettableSubsystem_Reset(localDW, localP);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_l = (ZCSigState)(rtu_Reset > 0);

  /* Sum: '<S421>/Sum' incorporates:
   *  Constant: '<S421>/Constant4'
   *  Memory: '<S421>/Memory'
   */
  rty_Time_0 = Modello_Arduino_2022_P.t_AP + localDW->Memory_PreviousInput;

  /* Update for Memory: '<S421>/Memory' */
  localDW->Memory_PreviousInput = rty_Time_0;

  /* End of Outputs for SubSystem: '<S410>/Resettable Subsystem' */
  return rty_Time_0;
}

/* System initialize for enable system: '<S569>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_Mod_T *localB,
  DW_One_time_initialization_Mo_T *localDW, P_One_time_initialization_Mod_T
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
  localDW->obj_kf.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_o.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_d.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_k4.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_co.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_k.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_b.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_c.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_i.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_d0.SampleTime = Modello_Arduino_2022_P.t_AP;
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
  localDW->obj_l.SampleTime = Modello_Arduino_2022_P.t_AP;
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
void Mod_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_Mod_T *localB, DW_One_time_initialization_Mo_T
  *localDW, P_One_time_initialization_Mod_T *localP)
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
    if (localDW->obj_kf.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_kf.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_o.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_o.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_d.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_d.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_k4.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_k4.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_co.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_co.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_k.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_k.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_b.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_b.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_c.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_c.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_i.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_i.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_d0.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_d0.SampleTime = Modello_Arduino_2022_P.t_AP;
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
    if (localDW->obj_l.SampleTime != Modello_Arduino_2022_P.t_AP) {
      localDW->obj_l.SampleTime = Modello_Arduino_2022_P.t_AP;
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
void One_time_initializatio_Term(DW_One_time_initialization_Mo_T *localDW)
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
static void Modello_Arduino_2022_find_254(const uint8_T pack[100], real_T
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
static boolean_T Modello_Arduino_202_ifWhileCond(const boolean_T x[100])
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
static void Modello_Arduino_2022_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 5.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_2022_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_2022_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 2.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_2_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 4.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino__IN_AutoLanding;
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
static void Modello_Arduino_2022_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 1.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_202_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 2.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_2_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 5.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_2022_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 4.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino__IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Modello_Arduino_2022_B.modo == 3.0)) {
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino__IN_AutoTakeoff;
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
static void Modello_Arduino_2022_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Modello_Arduino_2_ifWhileCond_o(const boolean_T x[5])
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
static void Modello_Arduino_2022_eml_find_o(const boolean_T x[80], int32_T
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
static void Modello_Arduino_2_readNonFinite(const char_T s[2], int32_T *k,
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
static boolean_T Modello_Arduino_2022_copydigits(char_T s1[4], int32_T *idx,
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
static boolean_T Modello_Arduino_20_copyexponent(char_T s1[4], int32_T *idx,
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

      Modello_Arduino_2022_B.kexp_j = *k;
      b_k = *k;
      b_success = Modello_Arduino_2022_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > Modello_Arduino_2022_B.kexp_j));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Modello_Arduino_2022_readfloat(char_T s1[4], int32_T *idx, const
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
            Modello_Arduino_2022_readfloat(s1, idx, s, k, false, &isneg,
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
      Modello_Arduino_2_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Modello_Arduino_2022_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = Modello_Arduino_20_copyexponent(s1, idx, s, k);
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
static creal_T Modello_Arduino_2022_str2double(const char_T s[2])
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
  Modello_Arduino_2022_B.ntoread_bj = 0;
  Modello_Arduino_2022_B.k_d = 0;
  while ((Modello_Arduino_2022_B.k_d + 1 <= 2) && (c[(uint8_T)
          s[Modello_Arduino_2022_B.k_d] & 127] || (s[Modello_Arduino_2022_B.k_d]
           == '\x00'))) {
    Modello_Arduino_2022_B.k_d++;
  }

  isimag1 = false;
  b_finite = true;
  Modello_Arduino_2022_B.scanned1_l = 0.0;
  Modello_Arduino_2022_B.idx_e = 1;
  Modello_Arduino_2022_B.s1_b[0] = '\x00';
  Modello_Arduino_2022_B.s1_b[1] = '\x00';
  Modello_Arduino_2022_B.s1_b[2] = '\x00';
  Modello_Arduino_2022_B.s1_b[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (Modello_Arduino_2022_B.k_d + 1 <= 2)) {
    if (s[Modello_Arduino_2022_B.k_d] == '-') {
      isneg = !isneg;
      Modello_Arduino_2022_B.k_d++;
    } else if ((s[Modello_Arduino_2022_B.k_d] == ',') ||
               (s[Modello_Arduino_2022_B.k_d] == '+') || c[(uint8_T)
               s[Modello_Arduino_2022_B.k_d] & 127]) {
      Modello_Arduino_2022_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  success = (Modello_Arduino_2022_B.k_d + 1 <= 2);
  if (success && isneg) {
    Modello_Arduino_2022_B.s1_b[0] = '-';
    Modello_Arduino_2022_B.idx_e = 2;
  }

  Modello_Arduino_2022_B.e_k = Modello_Arduino_2022_B.k_d + 1;
  if (success) {
    if ((Modello_Arduino_2022_B.k_d + 1 <= 2) && ((s[Modello_Arduino_2022_B.k_d]
          == 'j') || (s[Modello_Arduino_2022_B.k_d] == 'i'))) {
      isimag1 = true;
      Modello_Arduino_2022_B.e_k = Modello_Arduino_2022_B.k_d + 2;
      while ((Modello_Arduino_2022_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s
               [1] == '\x00') || (s[1] == ','))) {
        Modello_Arduino_2022_B.e_k = 3;
      }

      if ((Modello_Arduino_2022_B.e_k <= 2) && (s[1] == '*')) {
        Modello_Arduino_2022_B.e_k = 3;
        Modello_Arduino_2022_readfloat(Modello_Arduino_2022_B.s1_b,
          &Modello_Arduino_2022_B.idx_e, s, &Modello_Arduino_2022_B.e_k, false,
          &isneg, &b_finite, &Modello_Arduino_2022_B.scanned1_l, &unusedU2,
          &success);
      } else {
        Modello_Arduino_2022_B.s1_b[Modello_Arduino_2022_B.idx_e - 1] = '1';
        Modello_Arduino_2022_B.idx_e++;
      }
    } else {
      Modello_Arduino_2022_B.e_k = Modello_Arduino_2022_B.k_d + 1;
      Modello_Arduino_2_readNonFinite(s, &Modello_Arduino_2022_B.e_k, &b_finite,
        &Modello_Arduino_2022_B.scanned1_l);
      if (b_finite) {
        success = Modello_Arduino_2022_copydigits(Modello_Arduino_2022_B.s1_b,
          &Modello_Arduino_2022_B.idx_e, s, &Modello_Arduino_2022_B.e_k, true);
        if (success) {
          success = Modello_Arduino_20_copyexponent(Modello_Arduino_2022_B.s1_b,
            &Modello_Arduino_2022_B.idx_e, s, &Modello_Arduino_2022_B.e_k);
        }
      } else {
        if ((Modello_Arduino_2022_B.idx_e >= 2) && (Modello_Arduino_2022_B.s1_b
             [0] == '-')) {
          Modello_Arduino_2022_B.idx_e = 1;
          Modello_Arduino_2022_B.s1_b[0] = ' ';
          Modello_Arduino_2022_B.scanned1_l = -Modello_Arduino_2022_B.scanned1_l;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (Modello_Arduino_2022_B.e_k <= 2)) {
        tmp = s[Modello_Arduino_2022_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          Modello_Arduino_2022_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((Modello_Arduino_2022_B.e_k <= 2) && (s[Modello_Arduino_2022_B.e_k - 1]
           == '*')) {
        Modello_Arduino_2022_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (Modello_Arduino_2022_B.e_k <= 2)) {
          tmp = s[Modello_Arduino_2022_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            Modello_Arduino_2022_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (Modello_Arduino_2022_B.e_k <= 2) {
        tmp = s[Modello_Arduino_2022_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          Modello_Arduino_2022_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (Modello_Arduino_2022_B.e_k <= 2)) {
      tmp = s[Modello_Arduino_2022_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        Modello_Arduino_2022_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    Modello_Arduino_2022_B.ntoread_bj = 1;
  }

  if (success && (Modello_Arduino_2022_B.e_k <= 2)) {
    Modello_Arduino_2022_B.s1_b[Modello_Arduino_2022_B.idx_e - 1] = ' ';
    Modello_Arduino_2022_B.idx_e++;
    Modello_Arduino_2022_readfloat(Modello_Arduino_2022_B.s1_b,
      &Modello_Arduino_2022_B.idx_e, s, &Modello_Arduino_2022_B.e_k, true,
      &success, &isneg, &Modello_Arduino_2022_B.scanned2_dh, &unusedU2,
      &c_success);
    if (isneg) {
      Modello_Arduino_2022_B.ntoread_bj++;
    }

    success = (c_success && (Modello_Arduino_2022_B.e_k > 2) && (isimag1 !=
                success) && unusedU2);
  } else {
    Modello_Arduino_2022_B.scanned2_dh = 0.0;
  }

  if (success) {
    Modello_Arduino_2022_B.s1_b[Modello_Arduino_2022_B.idx_e - 1] = '\x00';
    switch (Modello_Arduino_2022_B.ntoread_bj) {
     case 2:
      Modello_Arduino_2022_B.ntoread_bj = sscanf(&Modello_Arduino_2022_B.s1_b[0],
        "%lf %lf", &Modello_Arduino_2022_B.scanned1_l,
        &Modello_Arduino_2022_B.scanned2_dh);
      if (Modello_Arduino_2022_B.ntoread_bj != 2) {
        Modello_Arduino_2022_B.scanned1_l = (rtNaN);
        Modello_Arduino_2022_B.scanned2_dh = (rtNaN);
      }
      break;

     case 1:
      Modello_Arduino_2022_B.ntoread_bj = sscanf(&Modello_Arduino_2022_B.s1_b[0],
        "%lf", &Modello_Arduino_2022_B.b_scanned1_d);
      if (b_finite) {
        if (Modello_Arduino_2022_B.ntoread_bj == 1) {
          Modello_Arduino_2022_B.scanned1_l =
            Modello_Arduino_2022_B.b_scanned1_d;
        } else {
          Modello_Arduino_2022_B.scanned1_l = (rtNaN);
        }
      } else if (Modello_Arduino_2022_B.ntoread_bj == 1) {
        Modello_Arduino_2022_B.scanned2_dh = Modello_Arduino_2022_B.b_scanned1_d;
      } else {
        Modello_Arduino_2022_B.scanned2_dh = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = Modello_Arduino_2022_B.scanned2_dh;
      x.im = Modello_Arduino_2022_B.scanned1_l;
    } else {
      x.re = Modello_Arduino_2022_B.scanned1_l;
      x.im = Modello_Arduino_2022_B.scanned2_dh;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Modello_Arduino_20_copydigits_k(char_T s1_data[], int32_T *idx,
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
static void Modello_Arduino_202_readfloat_d(char_T s1_data[], int32_T *idx,
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
          Modello_Arduino_202_readfloat_d(s1_data, idx, s_data, k, n, false,
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
        *success = Modello_Arduino_20_copydigits_k(s1_data, &b_idx, s_data, &h_k,
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
              isneg = Modello_Arduino_20_copydigits_k(s1_data, idx, s_data,
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
static creal_T Modello_Arduino_20_str2double_l(const char_T s_data[], const
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
    Modello_Arduino_2022_B.ntoread = 0;
    Modello_Arduino_2022_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (Modello_Arduino_2022_B.k <= s_size[1])) {
      tmp = s_data[Modello_Arduino_2022_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        Modello_Arduino_2022_B.k++;
      } else {
        exitg1 = true;
      }
    }

    Modello_Arduino_2022_B.s1_size[0] = 1;
    Modello_Arduino_2022_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    Modello_Arduino_2022_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= Modello_Arduino_2022_B.idx) {
      memset(&Modello_Arduino_2022_B.s1_data[0], 0, (Modello_Arduino_2022_B.idx
              + 1) * sizeof(char_T));
    }

    Modello_Arduino_2022_B.idx = 1;
    Modello_Arduino_202_readfloat_d(Modello_Arduino_2022_B.s1_data,
      &Modello_Arduino_2022_B.idx, s_data, &Modello_Arduino_2022_B.k, s_size[1],
      true, &isimag1, &isfinite1, &Modello_Arduino_2022_B.scanned1, &unusedU0,
      &success);
    if (isfinite1) {
      Modello_Arduino_2022_B.ntoread = 1;
    }

    if (success) {
      if (Modello_Arduino_2022_B.k <= s_size[1]) {
        Modello_Arduino_2022_B.s1_data[Modello_Arduino_2022_B.idx - 1] = ' ';
        Modello_Arduino_2022_B.idx++;
        Modello_Arduino_202_readfloat_d(Modello_Arduino_2022_B.s1_data,
          &Modello_Arduino_2022_B.idx, s_data, &Modello_Arduino_2022_B.k,
          s_size[1], true, &unusedU0, &success, &Modello_Arduino_2022_B.scanned2,
          &foundsign, &c_success);
        if (success) {
          Modello_Arduino_2022_B.ntoread++;
        }

        success = (c_success && ((Modello_Arduino_2022_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        Modello_Arduino_2022_B.scanned2 = 0.0;
      }
    } else {
      Modello_Arduino_2022_B.scanned2 = 0.0;
    }

    if (success) {
      Modello_Arduino_2022_B.s1_data[Modello_Arduino_2022_B.idx - 1] = '\x00';
      switch (Modello_Arduino_2022_B.ntoread) {
       case 2:
        Modello_Arduino_2022_B.ntoread = sscanf(&Modello_Arduino_2022_B.s1_data
          [0], "%lf %lf", &Modello_Arduino_2022_B.scanned1,
          &Modello_Arduino_2022_B.scanned2);
        if (Modello_Arduino_2022_B.ntoread != 2) {
          Modello_Arduino_2022_B.scanned1 = (rtNaN);
          Modello_Arduino_2022_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        Modello_Arduino_2022_B.ntoread = sscanf(&Modello_Arduino_2022_B.s1_data
          [0], "%lf", &Modello_Arduino_2022_B.b_scanned1);
        if (isfinite1) {
          if (Modello_Arduino_2022_B.ntoread == 1) {
            Modello_Arduino_2022_B.scanned1 = Modello_Arduino_2022_B.b_scanned1;
          } else {
            Modello_Arduino_2022_B.scanned1 = (rtNaN);
          }
        } else if (Modello_Arduino_2022_B.ntoread == 1) {
          Modello_Arduino_2022_B.scanned2 = Modello_Arduino_2022_B.b_scanned1;
        } else {
          Modello_Arduino_2022_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = Modello_Arduino_2022_B.scanned2;
        x.im = Modello_Arduino_2022_B.scanned1;
      } else {
        x.re = Modello_Arduino_2022_B.scanned1;
        x.im = Modello_Arduino_2022_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static boolean_T Modello_Arduino_2022_isUnitImag(const char_T s[3], int32_T k)
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
static void Modello_Arduino_readNonFinite_l(const char_T s[3], int32_T *k,
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
static boolean_T Modello_Arduino_2_copydigits_k3(char_T s1[5], int32_T *idx,
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
static boolean_T Modello_Arduino__copyexponent_k(char_T s1[5], int32_T *idx,
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

      Modello_Arduino_2022_B.kexp = *k;
      b_k = *k;
      b_success = Modello_Arduino_2_copydigits_k3(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > Modello_Arduino_2022_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Modello_Arduino_20_readfloat_dt(char_T s1[5], int32_T *idx, const
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
    if (Modello_Arduino_2022_isUnitImag(s, b_k)) {
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
          Modello_Arduino_20_readfloat_dt(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      Modello_Arduino_readNonFinite_l(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Modello_Arduino_2_copydigits_k3(s1, idx, s, k, true);
        if (*success) {
          *success = Modello_Arduino__copyexponent_k(s1, idx, s, k);
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
static creal_T Modello_Arduino_2_str2double_lv(const char_T s[3])
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
  Modello_Arduino_2022_B.ntoread_b = 0;
  Modello_Arduino_2022_B.k_l = 1;
  exitg1 = false;
  while ((!exitg1) && (Modello_Arduino_2022_B.k_l <= 3)) {
    tmp = s[Modello_Arduino_2022_B.k_l - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      Modello_Arduino_2022_B.k_l++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  Modello_Arduino_2022_B.scanned1_j = 0.0;
  Modello_Arduino_2022_B.idx_h = 1;
  for (Modello_Arduino_2022_B.b_k = 0; Modello_Arduino_2022_B.b_k < 5;
       Modello_Arduino_2022_B.b_k++) {
    Modello_Arduino_2022_B.s1[Modello_Arduino_2022_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (Modello_Arduino_2022_B.k_l <= 3)) {
    tmp = s[Modello_Arduino_2022_B.k_l - 1];
    if (tmp == '-') {
      isneg = !isneg;
      Modello_Arduino_2022_B.k_l++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      Modello_Arduino_2022_B.k_l++;
    } else {
      exitg1 = true;
    }
  }

  success = (Modello_Arduino_2022_B.k_l <= 3);
  if (success && isneg) {
    Modello_Arduino_2022_B.s1[0] = '-';
    Modello_Arduino_2022_B.idx_h = 2;
  }

  Modello_Arduino_2022_B.b_k = Modello_Arduino_2022_B.k_l - 1;
  if (success) {
    if (Modello_Arduino_2022_isUnitImag(s, Modello_Arduino_2022_B.k_l)) {
      isimag1 = true;
      Modello_Arduino_2022_B.b_k = Modello_Arduino_2022_B.k_l;
      while ((Modello_Arduino_2022_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[Modello_Arduino_2022_B.b_k] & 127] ||
              (s[Modello_Arduino_2022_B.b_k] == '\x00') ||
              (s[Modello_Arduino_2022_B.b_k] == ','))) {
        Modello_Arduino_2022_B.b_k++;
      }

      if ((Modello_Arduino_2022_B.b_k + 1 <= 3) && (s[Modello_Arduino_2022_B.b_k]
           == '*')) {
        Modello_Arduino_2022_B.k_l = Modello_Arduino_2022_B.b_k + 2;
        Modello_Arduino_20_readfloat_dt(Modello_Arduino_2022_B.s1,
          &Modello_Arduino_2022_B.idx_h, s, &Modello_Arduino_2022_B.k_l, false,
          &isneg, &b_finite, &Modello_Arduino_2022_B.scanned1_j, &unusedU2,
          &success);
        Modello_Arduino_2022_B.b_k = Modello_Arduino_2022_B.k_l - 1;
      } else {
        Modello_Arduino_2022_B.s1[Modello_Arduino_2022_B.idx_h - 1] = '1';
        Modello_Arduino_2022_B.idx_h++;
      }
    } else {
      Modello_Arduino_readNonFinite_l(s, &Modello_Arduino_2022_B.k_l, &b_finite,
        &Modello_Arduino_2022_B.scanned1_j);
      Modello_Arduino_2022_B.b_k = Modello_Arduino_2022_B.k_l - 1;
      if (b_finite) {
        success = Modello_Arduino_2_copydigits_k3(Modello_Arduino_2022_B.s1,
          &Modello_Arduino_2022_B.idx_h, s, &Modello_Arduino_2022_B.k_l, true);
        Modello_Arduino_2022_B.b_k = Modello_Arduino_2022_B.k_l - 1;
        if (success) {
          success = Modello_Arduino__copyexponent_k(Modello_Arduino_2022_B.s1,
            &Modello_Arduino_2022_B.idx_h, s, &Modello_Arduino_2022_B.k_l);
          Modello_Arduino_2022_B.b_k = Modello_Arduino_2022_B.k_l - 1;
        }
      } else {
        if ((Modello_Arduino_2022_B.idx_h >= 2) && (Modello_Arduino_2022_B.s1[0]
             == '-')) {
          Modello_Arduino_2022_B.idx_h = 1;
          Modello_Arduino_2022_B.s1[0] = ' ';
          Modello_Arduino_2022_B.scanned1_j = -Modello_Arduino_2022_B.scanned1_j;
        }
      }

      while ((Modello_Arduino_2022_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[Modello_Arduino_2022_B.b_k] & 127] ||
              (s[Modello_Arduino_2022_B.b_k] == '\x00') ||
              (s[Modello_Arduino_2022_B.b_k] == ','))) {
        Modello_Arduino_2022_B.b_k++;
      }

      if ((Modello_Arduino_2022_B.b_k + 1 <= 3) && (s[Modello_Arduino_2022_B.b_k]
           == '*')) {
        Modello_Arduino_2022_B.b_k++;
        while ((Modello_Arduino_2022_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[Modello_Arduino_2022_B.b_k] & 127] ||
                (s[Modello_Arduino_2022_B.b_k] == '\x00') ||
                (s[Modello_Arduino_2022_B.b_k] == ','))) {
          Modello_Arduino_2022_B.b_k++;
        }
      }

      if ((Modello_Arduino_2022_B.b_k + 1 <= 3) &&
          ((s[Modello_Arduino_2022_B.b_k] == 'i') ||
           (s[Modello_Arduino_2022_B.b_k] == 'j'))) {
        Modello_Arduino_2022_B.b_k++;
        isimag1 = true;
      }
    }

    while ((Modello_Arduino_2022_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[Modello_Arduino_2022_B.b_k] & 127] ||
            (s[Modello_Arduino_2022_B.b_k] == '\x00') ||
            (s[Modello_Arduino_2022_B.b_k] == ','))) {
      Modello_Arduino_2022_B.b_k++;
    }
  }

  if (b_finite) {
    Modello_Arduino_2022_B.ntoread_b = 1;
  }

  if (success && (Modello_Arduino_2022_B.b_k + 1 <= 3)) {
    Modello_Arduino_2022_B.s1[Modello_Arduino_2022_B.idx_h - 1] = ' ';
    Modello_Arduino_2022_B.idx_h++;
    Modello_Arduino_2022_B.k_l = Modello_Arduino_2022_B.b_k + 1;
    Modello_Arduino_20_readfloat_dt(Modello_Arduino_2022_B.s1,
      &Modello_Arduino_2022_B.idx_h, s, &Modello_Arduino_2022_B.k_l, true,
      &success, &isneg, &Modello_Arduino_2022_B.scanned2_d, &unusedU2,
      &c_success);
    if (isneg) {
      Modello_Arduino_2022_B.ntoread_b++;
    }

    success = (c_success && (Modello_Arduino_2022_B.k_l > 3) && (isimag1 !=
                success) && unusedU2);
  } else {
    Modello_Arduino_2022_B.scanned2_d = 0.0;
  }

  if (success) {
    Modello_Arduino_2022_B.s1[Modello_Arduino_2022_B.idx_h - 1] = '\x00';
    switch (Modello_Arduino_2022_B.ntoread_b) {
     case 2:
      Modello_Arduino_2022_B.ntoread_b = sscanf(&Modello_Arduino_2022_B.s1[0],
        "%lf %lf", &Modello_Arduino_2022_B.scanned1_j,
        &Modello_Arduino_2022_B.scanned2_d);
      if (Modello_Arduino_2022_B.ntoread_b != 2) {
        Modello_Arduino_2022_B.scanned1_j = (rtNaN);
        Modello_Arduino_2022_B.scanned2_d = (rtNaN);
      }
      break;

     case 1:
      Modello_Arduino_2022_B.ntoread_b = sscanf(&Modello_Arduino_2022_B.s1[0],
        "%lf", &Modello_Arduino_2022_B.b_scanned1_g);
      if (b_finite) {
        if (Modello_Arduino_2022_B.ntoread_b == 1) {
          Modello_Arduino_2022_B.scanned1_j =
            Modello_Arduino_2022_B.b_scanned1_g;
        } else {
          Modello_Arduino_2022_B.scanned1_j = (rtNaN);
        }
      } else if (Modello_Arduino_2022_B.ntoread_b == 1) {
        Modello_Arduino_2022_B.scanned2_d = Modello_Arduino_2022_B.b_scanned1_g;
      } else {
        Modello_Arduino_2022_B.scanned2_d = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = Modello_Arduino_2022_B.scanned2_d;
      x.im = Modello_Arduino_2022_B.scanned1_j;
    } else {
      x.re = Modello_Arduino_2022_B.scanned1_j;
      x.im = Modello_Arduino_2022_B.scanned2_d;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Modello_Arduin_readNonFinite_ln(char_T s, int32_T *k, boolean_T
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
static boolean_T Modello_Arduino__copydigits_k3z(char_T s1[3], int32_T *idx,
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
static boolean_T Modello_Arduino_copyexponent_kd(char_T s1[3], int32_T *idx,
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
    b_success = Modello_Arduino__copydigits_k3z(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static void Modello_Arduino_2_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
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
          Modello_Arduino_2_readfloat_dtp(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      Modello_Arduin_readNonFinite_ln(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = Modello_Arduino__copydigits_k3z(s1, idx, s, k, true);
        if (*success) {
          *success = Modello_Arduino_copyexponent_kd(s1, idx, s, k);
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
static creal_T Modello_Arduino__str2double_lvk(char_T s)
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
  Modello_Arduino_2022_B.ntoread_a = 0;
  Modello_Arduino_2022_B.d_k = 1;
  Modello_Arduino_2022_B.i_j = (uint8_T)s & 127;
  if (c[Modello_Arduino_2022_B.i_j] || (s == '\x00')) {
    Modello_Arduino_2022_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  Modello_Arduino_2022_B.scanned1_lx = 0.0;
  Modello_Arduino_2022_B.idx_f = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (Modello_Arduino_2022_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      Modello_Arduino_2022_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[Modello_Arduino_2022_B.i_j]) {
      Modello_Arduino_2022_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (Modello_Arduino_2022_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    Modello_Arduino_2022_B.idx_f = 2;
  }

  if (success) {
    isneg = false;
    if (Modello_Arduino_2022_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      Modello_Arduino_2022_B.d_k++;
      s1[Modello_Arduino_2022_B.idx_f - 1] = '1';
      Modello_Arduino_2022_B.idx_f++;
    } else {
      Modello_Arduin_readNonFinite_ln(s, &Modello_Arduino_2022_B.d_k, &b_finite,
        &Modello_Arduino_2022_B.scanned1_lx);
      if (b_finite) {
        success = Modello_Arduino__copydigits_k3z(s1,
          &Modello_Arduino_2022_B.idx_f, s, &Modello_Arduino_2022_B.d_k, true);
        if (success) {
          success = Modello_Arduino_copyexponent_kd(s1,
            &Modello_Arduino_2022_B.idx_f, s, &Modello_Arduino_2022_B.d_k);
        }
      } else {
        if ((Modello_Arduino_2022_B.idx_f >= 2) && (s1[0] == '-')) {
          Modello_Arduino_2022_B.idx_f = 1;
          s1[0] = ' ';
          Modello_Arduino_2022_B.scanned1_lx =
            -Modello_Arduino_2022_B.scanned1_lx;
        }
      }

      while ((Modello_Arduino_2022_B.d_k <= 1) && (c[Modello_Arduino_2022_B.i_j]
              || ((s == '\x00') || (s == ',')))) {
        Modello_Arduino_2022_B.d_k = 2;
      }

      if ((Modello_Arduino_2022_B.d_k <= 1) && (s == '*')) {
        Modello_Arduino_2022_B.d_k = 2;
      }

      if ((Modello_Arduino_2022_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        Modello_Arduino_2022_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((Modello_Arduino_2022_B.d_k <= 1) && (c[Modello_Arduino_2022_B.i_j] ||
            ((s == '\x00') || (s == ',')))) {
      Modello_Arduino_2022_B.d_k = 2;
    }
  }

  if (b_finite) {
    Modello_Arduino_2022_B.ntoread_a = 1;
  }

  if (success && (Modello_Arduino_2022_B.d_k <= 1)) {
    s1[Modello_Arduino_2022_B.idx_f - 1] = ' ';
    Modello_Arduino_2022_B.idx_f++;
    Modello_Arduino_2022_B.d_k = 1;
    Modello_Arduino_2_readfloat_dtp(s1, &Modello_Arduino_2022_B.idx_f, s,
      &Modello_Arduino_2022_B.d_k, true, &success, &isneg,
      &Modello_Arduino_2022_B.scanned2_o, &foundsign, &c_success);
    if (isneg) {
      Modello_Arduino_2022_B.ntoread_a++;
    }

    success = (c_success && (Modello_Arduino_2022_B.d_k > 1) && (isimag1 !=
                success) && foundsign);
  } else {
    Modello_Arduino_2022_B.scanned2_o = 0.0;
  }

  if (success) {
    s1[Modello_Arduino_2022_B.idx_f - 1] = '\x00';
    switch (Modello_Arduino_2022_B.ntoread_a) {
     case 2:
      Modello_Arduino_2022_B.ntoread_a = sscanf(&s1[0], "%lf %lf",
        &Modello_Arduino_2022_B.scanned1_lx, &Modello_Arduino_2022_B.scanned2_o);
      if (Modello_Arduino_2022_B.ntoread_a != 2) {
        Modello_Arduino_2022_B.scanned1_lx = (rtNaN);
        Modello_Arduino_2022_B.scanned2_o = (rtNaN);
      }
      break;

     case 1:
      Modello_Arduino_2022_B.ntoread_a = sscanf(&s1[0], "%lf",
        &Modello_Arduino_2022_B.b_scanned1_b);
      if (b_finite) {
        if (Modello_Arduino_2022_B.ntoread_a == 1) {
          Modello_Arduino_2022_B.scanned1_lx =
            Modello_Arduino_2022_B.b_scanned1_b;
        } else {
          Modello_Arduino_2022_B.scanned1_lx = (rtNaN);
        }
      } else if (Modello_Arduino_2022_B.ntoread_a == 1) {
        Modello_Arduino_2022_B.scanned2_o = Modello_Arduino_2022_B.b_scanned1_b;
      } else {
        Modello_Arduino_2022_B.scanned2_o = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = Modello_Arduino_2022_B.scanned2_o;
      x.im = Modello_Arduino_2022_B.scanned1_lx;
    } else {
      x.re = Modello_Arduino_2022_B.scanned1_lx;
      x.im = Modello_Arduino_2022_B.scanned2_o;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S583>/MATLAB Function' */
static real_T Modello_Arduino_2022_hex2dec(const char_T s[2])
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

  Modello_Arduino_2022_B.a_m = tmp_0;
  Modello_Arduino_2022_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &Modello_Arduino_2022_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&Modello_Arduino_2022_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &Modello_Arduino_2022_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &Modello_Arduino_2022_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&Modello_Arduino_2022_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &Modello_Arduino_2022_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &Modello_Arduino_2022_B.r3.chunks[0U],
                        2);
        tmp = tmp_4;
        MultiWordSub(&Modello_Arduino_2022_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &Modello_Arduino_2022_B.sk.chunks[0U], 2);
      } else {
        Modello_Arduino_2022_B.sk = tmp_0;
      }
    } else {
      Modello_Arduino_2022_B.sk = tmp_0;
    }

    uMultiWordMul(&Modello_Arduino_2022_B.sk.chunks[0U], 2,
                  &Modello_Arduino_2022_B.p16.chunks[0U], 2,
                  &Modello_Arduino_2022_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&Modello_Arduino_2022_B.r.chunks[0U], 4,
                         &Modello_Arduino_2022_B.r3.chunks[0U], 2);
    MultiWordAdd(&Modello_Arduino_2022_B.a_m.chunks[0U],
                 &Modello_Arduino_2022_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    Modello_Arduino_2022_B.a_m = tmp;
    uMultiWord2MultiWord(&Modello_Arduino_2022_B.p16.chunks[0U], 2,
                         &Modello_Arduino_2022_B.r2.chunks[0U], 3);
    uMultiWordShl(&Modello_Arduino_2022_B.r2.chunks[0U], 3, 4U,
                  &Modello_Arduino_2022_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&Modello_Arduino_2022_B.r1.chunks[0U], 3,
                         &Modello_Arduino_2022_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&Modello_Arduino_2022_B.a_m.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&Modello_Arduino_2022_B.a_m.chunks[0U], 2, 0) -
          uMultiWord2Double(&Modello_Arduino_2022_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&Modello_Arduino_2022_B.a_m.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&Modello_Arduino_2022_B.a_m.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&Modello_Arduino_2022_B.a_m.chunks[0U], 2, 0);
  }

  return x;
}

/* Model step function for TID0 */
void Modello_Arduino_2022_step0(void)  /* Sample time: [0.02s, 0.0s] */
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
  Mti_Outputs_wrapper(&Modello_Arduino_2022_B.SFunctionBuilder[0],
                      &Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE);

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
      memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o1[0], (uint8_T*)
             &Modello_Arduino_2022_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o2[0], (uint8_T*)
             &Modello_Arduino_2022_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o3_b, (uint8_T*)
             &Modello_Arduino_2022_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S571>/Byte Reversal' */

  /* ReverseEndian: <S571>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &Modello_Arduino_2022_B.ByteUnpack_o2[0];
    real32_T *y0 = &Modello_Arduino_2022_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S569>/One_time_initialization' */
  /* Logic: '<S569>/Logical Operator1' incorporates:
   *  UnitDelay: '<S569>/Unit Delay'
   */
  Mod_One_time_initialization(!Modello_Arduino_2022_DW.UnitDelay_DSTATE_d,
    &Modello_Arduino_2022_B.One_time_initialization,
    &Modello_Arduino_2022_DW.One_time_initialization,
    &Modello_Arduino_2022_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S569>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S569>/Execution_loop' incorporates:
   *  EnablePort: '<S573>/Enable'
   */
  /* UnitDelay: '<S569>/Unit Delay' */
  if (Modello_Arduino_2022_DW.UnitDelay_DSTATE_d) {
    /* MATLABSystem: '<S573>/I2C Read12' */
    if (Modello_Arduino_2022_DW.obj_f.SampleTime != Modello_Arduino_2022_P.t_AP)
    {
      Modello_Arduino_2022_DW.obj_f.SampleTime = Modello_Arduino_2022_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (Modello_Arduino_2022_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U, &status,
       1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(Modello_Arduino_2022_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S573>/I2C Read1' */
    if (Modello_Arduino_2022_DW.obj_p.SampleTime != Modello_Arduino_2022_P.t_AP)
    {
      Modello_Arduino_2022_DW.obj_p.SampleTime = Modello_Arduino_2022_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (Modello_Arduino_2022_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U, &status,
       1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(Modello_Arduino_2022_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &Modello_Arduino_2022_B.output_raw[0], 3U, false,
                        true);
      memcpy((void *)&Modello_Arduino_2022_B.output[0], (void *)
             &Modello_Arduino_2022_B.output_raw[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      Modello_Arduino_2022_B.output[0] = 0U;
      Modello_Arduino_2022_B.output[1] = 0U;
      Modello_Arduino_2022_B.output[2] = 0U;
    }

    /* ArithShift: '<S573>/Shift Arithmetic4' incorporates:
     *  Constant: '<S573>/Constant1'
     */
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant1_Value_o);
    if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf
        (Modello_Arduino_2022_B.a_n)) {
      Modello_Arduino_2022_B.a_n = 0.0;
    } else {
      Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n,
        4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic3' incorporates:
     *  Constant: '<S573>/Constant5'
     */
    Modello_Arduino_2022_B.Sum3 = floor(Modello_Arduino_2022_P.Constant5_Value_n);
    if (rtIsNaN(Modello_Arduino_2022_B.Sum3) || rtIsInf
        (Modello_Arduino_2022_B.Sum3)) {
      Modello_Arduino_2022_B.Sum3 = 0.0;
    } else {
      Modello_Arduino_2022_B.Sum3 = fmod(Modello_Arduino_2022_B.Sum3,
        4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic1' incorporates:
     *  Constant: '<S573>/Constant6'
     */
    Modello_Arduino_2022_B.num_254 = floor
      (Modello_Arduino_2022_P.Constant6_Value_k);
    if (rtIsNaN(Modello_Arduino_2022_B.num_254) || rtIsInf
        (Modello_Arduino_2022_B.num_254)) {
      Modello_Arduino_2022_B.num_254 = 0.0;
    } else {
      Modello_Arduino_2022_B.num_254 = fmod(Modello_Arduino_2022_B.num_254,
        4.294967296E+9);
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
    Modello_Arduino_2022_B.DataTypeConversion1_i = (int32_T)
      ((((((Modello_Arduino_2022_P.Constant7_Value_hu +
            Modello_Arduino_2022_B.output[0]) << (Modello_Arduino_2022_B.a_n <
            0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (int32_T)
            (uint32_T)Modello_Arduino_2022_B.a_n)) +
          ((Modello_Arduino_2022_P.Constant10_Value +
            Modello_Arduino_2022_B.output[1]) << (Modello_Arduino_2022_B.Sum3 <
            0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.Sum3 : (int32_T)
            (uint32_T)Modello_Arduino_2022_B.Sum3))) +
         Modello_Arduino_2022_P.Constant11_Value) +
        Modello_Arduino_2022_B.output[2]) >> (Modello_Arduino_2022_B.num_254 <
        0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.num_254 : (int32_T)
        (uint32_T)Modello_Arduino_2022_B.num_254));

    /* ArithShift: '<S573>/Shift Arithmetic7' incorporates:
     *  Constant: '<S573>/Constant2'
     */
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant2_Value_av);
    if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf
        (Modello_Arduino_2022_B.a_n)) {
      Modello_Arduino_2022_B.a_n = 0.0;
    } else {
      Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n,
        4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic6' incorporates:
     *  Constant: '<S573>/Constant3'
     */
    Modello_Arduino_2022_B.Sum3 = floor(Modello_Arduino_2022_P.Constant3_Value_c);
    if (rtIsNaN(Modello_Arduino_2022_B.Sum3) || rtIsInf
        (Modello_Arduino_2022_B.Sum3)) {
      Modello_Arduino_2022_B.Sum3 = 0.0;
    } else {
      Modello_Arduino_2022_B.Sum3 = fmod(Modello_Arduino_2022_B.Sum3,
        4.294967296E+9);
    }

    /* ArithShift: '<S573>/Shift Arithmetic2' incorporates:
     *  Constant: '<S573>/Constant4'
     */
    Modello_Arduino_2022_B.num_254 = floor
      (Modello_Arduino_2022_P.Constant4_Value_l);
    if (rtIsNaN(Modello_Arduino_2022_B.num_254) || rtIsInf
        (Modello_Arduino_2022_B.num_254)) {
      Modello_Arduino_2022_B.num_254 = 0.0;
    } else {
      Modello_Arduino_2022_B.num_254 = fmod(Modello_Arduino_2022_B.num_254,
        4.294967296E+9);
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
    Modello_Arduino_2022_B.DataTypeConversion_ay = (int32_T)
      ((((Modello_Arduino_2022_P.Constant8_Value_e + rtb_H_mav[0]) <<
         (Modello_Arduino_2022_B.a_n < 0.0 ? -(int32_T)(uint32_T)
          -Modello_Arduino_2022_B.a_n : (int32_T)(uint32_T)
          Modello_Arduino_2022_B.a_n)) +
        ((Modello_Arduino_2022_P.Constant9_Value_o + rtb_H_mav[1]) <<
         (Modello_Arduino_2022_B.Sum3 < 0.0 ? -(int32_T)(uint32_T)
          -Modello_Arduino_2022_B.Sum3 : (int32_T)(uint32_T)
          Modello_Arduino_2022_B.Sum3))) >> (Modello_Arduino_2022_B.num_254 <
        0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.num_254 : (int32_T)
        (uint32_T)Modello_Arduino_2022_B.num_254));

    /* S-Function (calc_T): '<S573>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&Modello_Arduino_2022_B.One_time_initialization.I2CRead,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead1,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead2,
       &Modello_Arduino_2022_B.DataTypeConversion_ay,
       &Modello_Arduino_2022_B.SFunctionBuilder_o1,
       &Modello_Arduino_2022_B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S573>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&Modello_Arduino_2022_B.One_time_initialization.I2CRead3,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead4,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead5,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead6,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead7,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead8,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead9,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead10,
       &Modello_Arduino_2022_B.One_time_initialization.I2CRead11,
       &Modello_Arduino_2022_B.DataTypeConversion1_i,
       &Modello_Arduino_2022_B.SFunctionBuilder_o2_a,
       &Modello_Arduino_2022_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S569>/Execution_loop' */

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&Modello_Arduino_2022_P.Constant1_Value_a,
    &Modello_Arduino_2022_B.SFunctionBuilder_o1_h[0],
    &Modello_Arduino_2022_B.SFunctionBuilder_o2,
    &Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE_l);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  Modello_Arduino_2022_B.ATO = 0;
  Modello_Arduino_2022_B.caso = 0;
  memset(&Modello_Arduino_2022_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
  memset(&Modello_Arduino_2022_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  Modello_Arduino_2022_find_254(Modello_Arduino_2022_B.SFunctionBuilder_o1_h,
    Modello_Arduino_2022_B.lat_end, &Modello_Arduino_2022_B.num_254);
  if (Modello_Arduino_2022_DW.Interr_parz && (Modello_Arduino_2022_B.num_254 ==
       1.0)) {
    Modello_Arduino_2022_B.pipk = (int32_T)(Modello_Arduino_2022_DW.counter_af +
      1U);
    if (Modello_Arduino_2022_DW.counter_af + 1U > 255U) {
      Modello_Arduino_2022_B.pipk = 255;
    }

    if (Modello_Arduino_2022_B.lat_end[0] != Modello_Arduino_2022_B.pipk) {
      Modello_Arduino_2022_B.num_254 = 0.0;
    }
  }

  Ap_sel = !Modello_Arduino_2022_DW.Interr_parz;
  if ((Modello_Arduino_2022_B.num_254 == 1.0) && Ap_sel) {
    Modello_Arduino_2022_B.caso = 1;
  } else if ((Modello_Arduino_2022_B.num_254 == 0.0) &&
             Modello_Arduino_2022_DW.Interr_parz) {
    Modello_Arduino_2022_B.caso = 2;
  } else if ((Modello_Arduino_2022_B.num_254 == 1.0) &&
             Modello_Arduino_2022_DW.Interr_parz) {
    Modello_Arduino_2022_B.caso = 3;
  } else {
    if ((Modello_Arduino_2022_B.num_254 == 2.0) && Ap_sel) {
      Modello_Arduino_2022_B.caso = 4;
    }
  }

  switch (Modello_Arduino_2022_B.caso) {
   case 1:
    Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.lat_end[(int32_T)
      Modello_Arduino_2022_B.num_254 - 1];
    if (Modello_Arduino_2022_B.a_n == 100.0) {
      Modello_Arduino_2022_DW.message_i[0] =
        Modello_Arduino_2022_B.SFunctionBuilder_o1_h[99];
      Modello_Arduino_2022_DW.Interr_parz = true;
    } else if (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
               (Modello_Arduino_2022_B.a_n + 1.0) - 1] <= 100) {
      Modello_Arduino_2022_B.pipk = (int32_T)
        (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
         (Modello_Arduino_2022_B.lat_end[0] + 1.0) - 1] + 8U);
      Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.pipk;
      if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
        Modello_Arduino_2022_B.f = 255;
      }

      if (Modello_Arduino_2022_B.f == Modello_Arduino_2022_B.SFunctionBuilder_o2)
      {
        Modello_Arduino_2022_B.Sum3 = rt_roundd_snf(Modello_Arduino_2022_B.a_n);
        if (Modello_Arduino_2022_B.Sum3 < 256.0) {
          if (Modello_Arduino_2022_B.Sum3 >= 0.0) {
            status = (uint8_T)Modello_Arduino_2022_B.Sum3;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        Modello_Arduino_2022_B.pipk = (int32_T)
          (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
           (Modello_Arduino_2022_B.a_n + 1.0) - 1] + 7U);
        if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
          Modello_Arduino_2022_B.pipk = 255;
        }

        Modello_Arduino_2022_B.a_n = rt_roundd_snf(Modello_Arduino_2022_B.a_n +
          (real_T)Modello_Arduino_2022_B.pipk);
        if (Modello_Arduino_2022_B.a_n < 256.0) {
          if (Modello_Arduino_2022_B.a_n >= 0.0) {
            find_comma = (uint8_T)Modello_Arduino_2022_B.a_n;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          Modello_Arduino_2022_B.f = 0;
          Modello_Arduino_2022_B.i = 0;
        } else {
          Modello_Arduino_2022_B.f = status - 1;
          Modello_Arduino_2022_B.i = find_comma;
        }

        Modello_Arduino_2022_B.tolleranza_distWP_fut = Modello_Arduino_2022_B.i
          - Modello_Arduino_2022_B.f;
        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
             Modello_Arduino_2022_B.tolleranza_distWP_fut;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.pipk] =
            Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.f
            + Modello_Arduino_2022_B.pipk];
        }

        Modello_Arduino_2022_B.ATO = 1;
        for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 100;
             Modello_Arduino_2022_B.i++) {
          Modello_Arduino_2022_B.messaggio_i[Modello_Arduino_2022_B.i] =
            Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i];
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i] = 0U;
        }

        Modello_Arduino_2022_DW.counter_af = 0U;
        Modello_Arduino_2022_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
          Modello_Arduino_2022_B.pipk = 255;
        }

        if (Modello_Arduino_2022_B.pipk >
            Modello_Arduino_2022_B.SFunctionBuilder_o2) {
          Modello_Arduino_2022_DW.mess_len =
            Modello_Arduino_2022_B.SFunctionBuilder_o2;
          if (Modello_Arduino_2022_B.a_n > Modello_Arduino_2022_DW.mess_len) {
            Modello_Arduino_2022_B.soglia_dist = 0;
            Modello_Arduino_2022_B.f = 0;
          } else {
            Modello_Arduino_2022_B.soglia_dist = (int32_T)
              Modello_Arduino_2022_B.a_n - 1;
            Modello_Arduino_2022_B.f = (int32_T)Modello_Arduino_2022_DW.mess_len;
          }

          Modello_Arduino_2022_B.tolleranza_distWP_fut =
            Modello_Arduino_2022_B.f - Modello_Arduino_2022_B.soglia_dist;
          for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
               Modello_Arduino_2022_B.tolleranza_distWP_fut;
               Modello_Arduino_2022_B.pipk++) {
            Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.pipk] =
              Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.soglia_dist
              + Modello_Arduino_2022_B.pipk];
          }

          Modello_Arduino_2022_B.pipk = (int32_T)
            (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
             (Modello_Arduino_2022_B.a_n + 1.0) - 1] + 8U);
          if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
            Modello_Arduino_2022_B.pipk = 255;
          }

          Modello_Arduino_2022_B.a_n = rt_roundd_snf((real_T)
            Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_DW.mess_len);
          if (Modello_Arduino_2022_B.a_n < 256.0) {
            if (Modello_Arduino_2022_B.a_n >= 0.0) {
              Modello_Arduino_2022_DW.counter_af = (uint8_T)
                Modello_Arduino_2022_B.a_n;
            } else {
              Modello_Arduino_2022_DW.counter_af = 0U;
            }
          } else {
            Modello_Arduino_2022_DW.counter_af = MAX_uint8_T;
          }

          Modello_Arduino_2022_DW.Interr_parz = true;
        }
      }
    } else {
      Modello_Arduino_2022_DW.Interr_parz = false;
      memset(&Modello_Arduino_2022_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      Modello_Arduino_2022_DW.counter_af = 0U;
      Modello_Arduino_2022_DW.mess_len = 0.0;
      Modello_Arduino_2022_B.ATO = 1;
    }
    break;

   case 2:
    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.x[Modello_Arduino_2022_B.pipk] =
        (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.pipk]
         != 0);
    }

    if (Modello_Arduino_202_ifWhileCond(Modello_Arduino_2022_B.x)) {
      Modello_Arduino_2022_B.a_n = rt_roundd_snf
        (Modello_Arduino_2022_DW.mess_len + 1.0);
      if (Modello_Arduino_2022_B.a_n < 256.0) {
        if (Modello_Arduino_2022_B.a_n >= 0.0) {
          find_comma = (uint8_T)Modello_Arduino_2022_B.a_n;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      Modello_Arduino_2022_B.a_n = rt_roundd_snf
        (Modello_Arduino_2022_DW.mess_len + (real_T)
         Modello_Arduino_2022_DW.counter_af);
      if (Modello_Arduino_2022_B.a_n < 256.0) {
        if (Modello_Arduino_2022_B.a_n >= 0.0) {
          status = (uint8_T)Modello_Arduino_2022_B.a_n;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      if (find_comma > status) {
        Modello_Arduino_2022_B.soglia_dist = 1;
      } else {
        Modello_Arduino_2022_B.soglia_dist = find_comma;
      }

      if (1 > Modello_Arduino_2022_DW.counter_af) {
        Modello_Arduino_2022_B.tolleranza_distWP_fut = -1;
      } else {
        Modello_Arduino_2022_B.tolleranza_distWP_fut =
          Modello_Arduino_2022_DW.counter_af - 1;
      }

      for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
           Modello_Arduino_2022_B.tolleranza_distWP_fut;
           Modello_Arduino_2022_B.pipk++) {
        Modello_Arduino_2022_DW.message_i[(Modello_Arduino_2022_B.soglia_dist +
          Modello_Arduino_2022_B.pipk) - 1] =
          Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.pipk];
      }

      Modello_Arduino_2022_DW.Interr_parz = false;
      Modello_Arduino_2022_B.ATO = 1;
      for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 100;
           Modello_Arduino_2022_B.i++) {
        Modello_Arduino_2022_B.messaggio_i[Modello_Arduino_2022_B.i] =
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i];
        Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i] = 0U;
      }

      Modello_Arduino_2022_DW.mess_len = 0.0;
      Modello_Arduino_2022_DW.counter_af = 0U;
    } else {
      Modello_Arduino_2022_DW.Interr_parz = false;
      Modello_Arduino_2022_B.ATO = 1;
      memset(&Modello_Arduino_2022_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      Modello_Arduino_2022_DW.mess_len = 0.0;
      Modello_Arduino_2022_DW.counter_af = 0U;
    }
    break;

   case 3:
    Modello_Arduino_2022_B.a_n = rt_roundd_snf(Modello_Arduino_2022_DW.mess_len
      + 1.0);
    if (Modello_Arduino_2022_B.a_n < 256.0) {
      if (Modello_Arduino_2022_B.a_n >= 0.0) {
        find_comma = (uint8_T)Modello_Arduino_2022_B.a_n;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    Modello_Arduino_2022_B.a_n = rt_roundd_snf(Modello_Arduino_2022_DW.mess_len
      + (real_T)Modello_Arduino_2022_DW.counter_af);
    if (Modello_Arduino_2022_B.a_n < 256.0) {
      if (Modello_Arduino_2022_B.a_n >= 0.0) {
        status = (uint8_T)Modello_Arduino_2022_B.a_n;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    if (find_comma > status) {
      Modello_Arduino_2022_B.soglia_dist = 1;
    } else {
      Modello_Arduino_2022_B.soglia_dist = find_comma;
    }

    if (1 > Modello_Arduino_2022_DW.counter_af) {
      Modello_Arduino_2022_B.tolleranza_distWP_fut = -1;
    } else {
      Modello_Arduino_2022_B.tolleranza_distWP_fut =
        Modello_Arduino_2022_DW.counter_af - 1;
    }

    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
         Modello_Arduino_2022_B.tolleranza_distWP_fut;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_DW.message_i[(Modello_Arduino_2022_B.soglia_dist +
        Modello_Arduino_2022_B.pipk) - 1] =
        Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.pipk];
    }

    Modello_Arduino_2022_DW.Interr_parz = false;
    Modello_Arduino_2022_B.ATO = 1;
    for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 100;
         Modello_Arduino_2022_B.i++) {
      Modello_Arduino_2022_B.messaggio_i[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i];
      Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i] = 0U;
    }

    Modello_Arduino_2022_DW.mess_len = 0.0;
    Modello_Arduino_2022_DW.counter_af = 0U;
    Modello_Arduino_2022_B.pipk = (int32_T)(Modello_Arduino_2022_B.lat_end
      [(int32_T)Modello_Arduino_2022_B.num_254 - 1] + 1.0) - 1;
    if (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.pipk]
        <= 100) {
      Modello_Arduino_2022_B.f = (int32_T)
        (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
         (Modello_Arduino_2022_B.lat_end[0] + 1.0) - 1] + 8U);
      if ((uint32_T)Modello_Arduino_2022_B.f > 255U) {
        Modello_Arduino_2022_B.f = 255;
      }

      Modello_Arduino_2022_B.caso = Modello_Arduino_2022_B.SFunctionBuilder_o2;
      if (Modello_Arduino_2022_B.SFunctionBuilder_o2 < 0) {
        Modello_Arduino_2022_B.caso = 0;
      } else {
        if (Modello_Arduino_2022_B.SFunctionBuilder_o2 > 255) {
          Modello_Arduino_2022_B.caso = 255;
        }
      }

      if (Modello_Arduino_2022_B.f == Modello_Arduino_2022_B.caso) {
        Modello_Arduino_2022_B.a_n = rt_roundd_snf
          (Modello_Arduino_2022_B.lat_end[(int32_T)
           Modello_Arduino_2022_B.num_254 - 1]);
        if (Modello_Arduino_2022_B.a_n < 256.0) {
          if (Modello_Arduino_2022_B.a_n >= 0.0) {
            status = (uint8_T)Modello_Arduino_2022_B.a_n;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        Modello_Arduino_2022_B.pipk = (int32_T)
          (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.pipk]
           + 7U);
        if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
          Modello_Arduino_2022_B.pipk = 255;
        }

        Modello_Arduino_2022_B.a_n = rt_roundd_snf
          (Modello_Arduino_2022_B.lat_end[(int32_T)
           Modello_Arduino_2022_B.num_254 - 1] + (real_T)
           Modello_Arduino_2022_B.pipk);
        if (Modello_Arduino_2022_B.a_n < 256.0) {
          if (Modello_Arduino_2022_B.a_n >= 0.0) {
            find_comma = (uint8_T)Modello_Arduino_2022_B.a_n;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          Modello_Arduino_2022_B.soglia_dist = 0;
          Modello_Arduino_2022_B.pipk = 0;
        } else {
          Modello_Arduino_2022_B.soglia_dist = status - 1;
          Modello_Arduino_2022_B.pipk = find_comma;
        }

        Modello_Arduino_2022_B.tolleranza_distWP_fut =
          Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
             Modello_Arduino_2022_B.tolleranza_distWP_fut;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.pipk] =
            Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.soglia_dist
            + Modello_Arduino_2022_B.pipk];
        }

        for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 100;
             Modello_Arduino_2022_B.i++) {
          Modello_Arduino_2022_B.messaggio_2[Modello_Arduino_2022_B.i] =
            Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i];
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i] = 0U;
        }

        Modello_Arduino_2022_DW.counter_af = 0U;
        Modello_Arduino_2022_DW.mess_len = 0.0;
      } else {
        Modello_Arduino_2022_B.f = (int32_T)
          (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
           (Modello_Arduino_2022_B.lat_end[0] + 1.0) - 1] + 8U);
        if ((uint32_T)Modello_Arduino_2022_B.f > 255U) {
          Modello_Arduino_2022_B.f = 255;
        }

        Modello_Arduino_2022_B.caso = Modello_Arduino_2022_B.SFunctionBuilder_o2;
        if (Modello_Arduino_2022_B.SFunctionBuilder_o2 < 0) {
          Modello_Arduino_2022_B.caso = 0;
        } else {
          if (Modello_Arduino_2022_B.SFunctionBuilder_o2 > 255) {
            Modello_Arduino_2022_B.caso = 255;
          }
        }

        if (Modello_Arduino_2022_B.f > Modello_Arduino_2022_B.caso) {
          Modello_Arduino_2022_DW.mess_len =
            Modello_Arduino_2022_B.SFunctionBuilder_o2;
          if (Modello_Arduino_2022_B.lat_end[(int32_T)
              Modello_Arduino_2022_B.num_254 - 1] >
              Modello_Arduino_2022_DW.mess_len) {
            Modello_Arduino_2022_B.soglia_dist = 0;
            Modello_Arduino_2022_B.tolleranza_distWP_fut = 0;
          } else {
            Modello_Arduino_2022_B.soglia_dist = (int32_T)
              Modello_Arduino_2022_B.lat_end[(int32_T)
              Modello_Arduino_2022_B.num_254 - 1] - 1;
            Modello_Arduino_2022_B.tolleranza_distWP_fut = (int32_T)
              Modello_Arduino_2022_DW.mess_len;
          }

          Modello_Arduino_2022_B.tolleranza_distWP_fut -=
            Modello_Arduino_2022_B.soglia_dist;
          for (Modello_Arduino_2022_B.f = 0; Modello_Arduino_2022_B.f <
               Modello_Arduino_2022_B.tolleranza_distWP_fut;
               Modello_Arduino_2022_B.f++) {
            Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.f] =
              Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.soglia_dist
              + Modello_Arduino_2022_B.f];
          }

          Modello_Arduino_2022_B.pipk = (int32_T)
            (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.pipk]
             + 8U);
          if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
            Modello_Arduino_2022_B.pipk = 255;
          }

          Modello_Arduino_2022_B.a_n = rt_roundd_snf((real_T)
            Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_DW.mess_len);
          if (Modello_Arduino_2022_B.a_n < 256.0) {
            if (Modello_Arduino_2022_B.a_n >= 0.0) {
              Modello_Arduino_2022_DW.counter_af = (uint8_T)
                Modello_Arduino_2022_B.a_n;
            } else {
              Modello_Arduino_2022_DW.counter_af = 0U;
            }
          } else {
            Modello_Arduino_2022_DW.counter_af = MAX_uint8_T;
          }

          Modello_Arduino_2022_DW.Interr_parz = true;
        }
      }
    } else {
      Modello_Arduino_2022_DW.Interr_parz = false;
      memset(&Modello_Arduino_2022_B.messaggio_i[0], 0, 100U * sizeof(uint8_T));
      memset(&Modello_Arduino_2022_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      Modello_Arduino_2022_DW.counter_af = 0U;
      Modello_Arduino_2022_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
        (Modello_Arduino_2022_B.lat_end[0] + 1.0) - 1] <= 100) {
      Modello_Arduino_2022_B.a_n = rt_roundd_snf(Modello_Arduino_2022_B.lat_end
        [0]);
      if (Modello_Arduino_2022_B.a_n < 256.0) {
        if (Modello_Arduino_2022_B.a_n >= 0.0) {
          status = (uint8_T)Modello_Arduino_2022_B.a_n;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      Modello_Arduino_2022_B.pipk = (int32_T)
        (Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
         (Modello_Arduino_2022_B.lat_end[0] + 1.0) - 1] + 7U);
      if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
        Modello_Arduino_2022_B.pipk = 255;
      }

      Modello_Arduino_2022_B.a_n = rt_roundd_snf(Modello_Arduino_2022_B.lat_end
        [0] + (real_T)Modello_Arduino_2022_B.pipk);
      if (Modello_Arduino_2022_B.a_n < 256.0) {
        if (Modello_Arduino_2022_B.a_n >= 0.0) {
          find_comma = (uint8_T)Modello_Arduino_2022_B.a_n;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (status > find_comma) {
        Modello_Arduino_2022_B.ATO = 0;
        Modello_Arduino_2022_B.caso = 0;
      } else {
        Modello_Arduino_2022_B.ATO = status - 1;
        Modello_Arduino_2022_B.caso = find_comma;
      }

      Modello_Arduino_2022_B.tolleranza_distWP_fut = Modello_Arduino_2022_B.caso
        - Modello_Arduino_2022_B.ATO;
      for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
           Modello_Arduino_2022_B.tolleranza_distWP_fut;
           Modello_Arduino_2022_B.pipk++) {
        Modello_Arduino_2022_B.messaggio_i[Modello_Arduino_2022_B.pipk] =
          Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.ATO
          + Modello_Arduino_2022_B.pipk];
      }
    } else {
      Modello_Arduino_2022_DW.Interr_parz = false;
      memset(&Modello_Arduino_2022_DW.message_i[0], 0, 100U * sizeof(uint8_T));
    }

    Modello_Arduino_2022_B.ATO = 1;
    if ((Modello_Arduino_2022_B.SFunctionBuilder_o1_h[(int32_T)
         (Modello_Arduino_2022_B.lat_end[1] + 1.0) - 1] <= 100) &&
        (Modello_Arduino_2022_B.lat_end[1] - Modello_Arduino_2022_B.lat_end[0] >
         3.0)) {
      Modello_Arduino_2022_B.a_n = rt_roundd_snf((real_T)
        Modello_Arduino_2022_B.SFunctionBuilder_o2 -
        Modello_Arduino_2022_B.lat_end[1]);
      Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.SFunctionBuilder_o1_h
        [(int32_T)(Modello_Arduino_2022_B.lat_end[1] + 1.0) - 1];
      Modello_Arduino_2022_B.pipk = (int32_T)(Modello_Arduino_2022_B.qY + 7U);
      if (Modello_Arduino_2022_B.qY + 7U > 255U) {
        Modello_Arduino_2022_B.pipk = 255;
      }

      if (Modello_Arduino_2022_B.a_n < 2.147483648E+9) {
        if (Modello_Arduino_2022_B.a_n >= -2.147483648E+9) {
          Modello_Arduino_2022_B.f = (int32_T)Modello_Arduino_2022_B.a_n;
        } else {
          Modello_Arduino_2022_B.f = MIN_int32_T;
        }
      } else {
        Modello_Arduino_2022_B.f = MAX_int32_T;
      }

      if (Modello_Arduino_2022_B.f == Modello_Arduino_2022_B.pipk) {
        Modello_Arduino_2022_B.a_n = rt_roundd_snf
          (Modello_Arduino_2022_B.lat_end[1]);
        if (Modello_Arduino_2022_B.a_n < 256.0) {
          if (Modello_Arduino_2022_B.a_n >= 0.0) {
            status = (uint8_T)Modello_Arduino_2022_B.a_n;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        Modello_Arduino_2022_B.pipk = (int32_T)(Modello_Arduino_2022_B.qY + 7U);
        if (Modello_Arduino_2022_B.qY + 7U > 255U) {
          Modello_Arduino_2022_B.pipk = 255;
        }

        Modello_Arduino_2022_B.a_n = rt_roundd_snf
          (Modello_Arduino_2022_B.lat_end[1] + (real_T)
           Modello_Arduino_2022_B.pipk);
        if (Modello_Arduino_2022_B.a_n < 256.0) {
          if (Modello_Arduino_2022_B.a_n >= 0.0) {
            find_comma = (uint8_T)Modello_Arduino_2022_B.a_n;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          Modello_Arduino_2022_B.ATO = 0;
          Modello_Arduino_2022_B.caso = 0;
        } else {
          Modello_Arduino_2022_B.ATO = status - 1;
          Modello_Arduino_2022_B.caso = find_comma;
        }

        Modello_Arduino_2022_B.tolleranza_distWP_fut =
          Modello_Arduino_2022_B.caso - Modello_Arduino_2022_B.ATO;
        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
             Modello_Arduino_2022_B.tolleranza_distWP_fut;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.pipk] =
            Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.ATO
            + Modello_Arduino_2022_B.pipk];
        }

        Modello_Arduino_2022_B.ATO = 2;
        for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 100;
             Modello_Arduino_2022_B.i++) {
          Modello_Arduino_2022_B.messaggio_2[Modello_Arduino_2022_B.i] =
            Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i];
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.i] = 0U;
        }

        Modello_Arduino_2022_DW.counter_af = 0U;
        Modello_Arduino_2022_DW.mess_len = 0.0;
      } else {
        Modello_Arduino_2022_B.a_n = rt_roundd_snf
          (Modello_Arduino_2022_B.lat_end[1]);
        if (Modello_Arduino_2022_B.a_n < 2.147483648E+9) {
          if (Modello_Arduino_2022_B.a_n >= -2.147483648E+9) {
            Modello_Arduino_2022_B.caso = (int32_T)Modello_Arduino_2022_B.a_n;
          } else {
            Modello_Arduino_2022_B.caso = MIN_int32_T;
          }
        } else {
          Modello_Arduino_2022_B.caso = MAX_int32_T;
        }

        if (Modello_Arduino_2022_B.caso >
            Modello_Arduino_2022_B.SFunctionBuilder_o2) {
          Modello_Arduino_2022_B.caso = -1;
          Modello_Arduino_2022_B.pipk = 0;
        } else {
          Modello_Arduino_2022_B.caso -= 2;
          Modello_Arduino_2022_B.pipk =
            Modello_Arduino_2022_B.SFunctionBuilder_o2;
        }

        Modello_Arduino_2022_DW.mess_len = (int8_T)((Modello_Arduino_2022_B.pipk
          - Modello_Arduino_2022_B.caso) - 1);
        if (Modello_Arduino_2022_B.a_n < 2.147483648E+9) {
          if (Modello_Arduino_2022_B.a_n >= -2.147483648E+9) {
            Modello_Arduino_2022_B.caso = (int32_T)Modello_Arduino_2022_B.a_n;
          } else {
            Modello_Arduino_2022_B.caso = MIN_int32_T;
          }
        } else {
          Modello_Arduino_2022_B.caso = MAX_int32_T;
        }

        if (Modello_Arduino_2022_B.caso >
            Modello_Arduino_2022_B.SFunctionBuilder_o2) {
          Modello_Arduino_2022_B.caso = 0;
          Modello_Arduino_2022_B.pipk = 0;
        } else {
          Modello_Arduino_2022_B.caso--;
          Modello_Arduino_2022_B.pipk =
            Modello_Arduino_2022_B.SFunctionBuilder_o2;
        }

        Modello_Arduino_2022_B.tolleranza_distWP_fut =
          Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.caso;
        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
             Modello_Arduino_2022_B.tolleranza_distWP_fut;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_DW.message_i[Modello_Arduino_2022_B.pipk] =
            Modello_Arduino_2022_B.SFunctionBuilder_o1_h[Modello_Arduino_2022_B.caso
            + Modello_Arduino_2022_B.pipk];
        }

        Modello_Arduino_2022_B.pipk = (int32_T)(Modello_Arduino_2022_B.qY + 8U);
        if (Modello_Arduino_2022_B.qY + 8U > 255U) {
          Modello_Arduino_2022_B.pipk = 255;
        }

        Modello_Arduino_2022_B.a_n = rt_roundd_snf((real_T)
          Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_DW.mess_len);
        if (Modello_Arduino_2022_B.a_n < 256.0) {
          if (Modello_Arduino_2022_B.a_n >= 0.0) {
            Modello_Arduino_2022_DW.counter_af = (uint8_T)
              Modello_Arduino_2022_B.a_n;
          } else {
            Modello_Arduino_2022_DW.counter_af = 0U;
          }
        } else {
          Modello_Arduino_2022_DW.counter_af = MAX_uint8_T;
        }

        Modello_Arduino_2022_DW.Interr_parz = true;
      }
    } else {
      Modello_Arduino_2022_DW.Interr_parz = false;
      memset(&Modello_Arduino_2022_DW.message_i[0], 0, 100U * sizeof(uint8_T));
      Modello_Arduino_2022_DW.counter_af = 0U;
      Modello_Arduino_2022_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&Modello_Arduino_2022_B.buffer[0], 0, 300U * sizeof(uint8_T));
  status = 0U;
  for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
       Modello_Arduino_2022_B.pipk++) {
    Modello_Arduino_2022_B.buffer[3 * Modello_Arduino_2022_B.pipk] = 0U;
  }

  for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
       Modello_Arduino_2022_B.pipk++) {
    for (Modello_Arduino_2022_B.soglia_dist = 0;
         Modello_Arduino_2022_B.soglia_dist < 2;
         Modello_Arduino_2022_B.soglia_dist++) {
      Modello_Arduino_2022_B.caso = 3 * Modello_Arduino_2022_B.pipk +
        Modello_Arduino_2022_B.soglia_dist;
      Modello_Arduino_2022_B.buffer[Modello_Arduino_2022_B.caso + 1] =
        Modello_Arduino_2022_DW.Memory4_PreviousInput_c[Modello_Arduino_2022_B.caso];
    }
  }

  Modello_Arduino_2022_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (Modello_Arduino_2022_B.i >= 1)) {
    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.x[Modello_Arduino_2022_B.pipk] =
        (Modello_Arduino_2022_B.buffer[(3 * Modello_Arduino_2022_B.pipk +
          Modello_Arduino_2022_B.i) - 1] == 0);
    }

    Ap_sel = true;
    Modello_Arduino_2022_B.pipk = 0;
    exitg2 = false;
    while ((!exitg2) && (Modello_Arduino_2022_B.pipk < 100)) {
      if (!Modello_Arduino_2022_B.x[Modello_Arduino_2022_B.pipk]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        Modello_Arduino_2022_B.pipk++;
      }
    }

    if (Ap_sel) {
      status = (uint8_T)Modello_Arduino_2022_B.i;
      exitg1 = true;
    } else {
      Modello_Arduino_2022_B.i--;
    }
  }

  if (Modello_Arduino_2022_B.ATO == 1) {
    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.buffer[(status + 3 * Modello_Arduino_2022_B.pipk) -
        1] = Modello_Arduino_2022_B.messaggio_i[Modello_Arduino_2022_B.pipk];
    }
  } else if (Modello_Arduino_2022_B.ATO == 2) {
    Modello_Arduino_2022_B.qY = status - /*MW:OvSatOk*/ 1U;
    if (status - 1U > status) {
      Modello_Arduino_2022_B.qY = 0U;
    }

    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.buffer[(status + 3 * Modello_Arduino_2022_B.pipk) -
        1] = Modello_Arduino_2022_B.messaggio_i[Modello_Arduino_2022_B.pipk];
      Modello_Arduino_2022_B.buffer[((int32_T)Modello_Arduino_2022_B.qY + 3 *
        Modello_Arduino_2022_B.pipk) - 1] =
        Modello_Arduino_2022_B.messaggio_2[Modello_Arduino_2022_B.pipk];
    }
  } else {
    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.buffer[(status + 3 * Modello_Arduino_2022_B.pipk) -
        1] = 0U;
    }
  }

  for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
       Modello_Arduino_2022_B.pipk++) {
    Modello_Arduino_2022_B.mess_out[Modello_Arduino_2022_B.pipk] =
      Modello_Arduino_2022_DW.Memory4_PreviousInput_c[3 *
      Modello_Arduino_2022_B.pipk + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  Modello_Arduino_2022_B.Add = Modello_Arduino_2022_DW.Memory4_PreviousInput_c[5]
    + Modello_Arduino_2022_P.Constant_Value_g;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (Modello_Arduino_2022_B.mess_out[2] !=
      Modello_Arduino_2022_DW.Memory5_PreviousInput_l[2]) {
    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 100;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.x[Modello_Arduino_2022_B.pipk] =
        (Modello_Arduino_2022_B.mess_out[Modello_Arduino_2022_B.pipk] != 0);
    }

    Ap_sel = true;
    Modello_Arduino_2022_B.pipk = 0;
    exitg1 = false;
    while ((!exitg1) && (Modello_Arduino_2022_B.pipk < 100)) {
      if (!Modello_Arduino_2022_B.x[Modello_Arduino_2022_B.pipk]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        Modello_Arduino_2022_B.pipk++;
      }
    }

    if (!Ap_sel) {
      if (Modello_Arduino_2022_DW.counter > 100) {
        Modello_Arduino_2022_DW.counter = 0U;
      }

      Modello_Arduino_2022_B.qY = Modello_Arduino_2022_DW.counter + 1U;
      if (Modello_Arduino_2022_DW.counter + 1U > 65535U) {
        Modello_Arduino_2022_B.qY = 65535U;
      }

      Modello_Arduino_2022_DW.counter = (uint16_T)Modello_Arduino_2022_B.qY;
    }
  }

  Modello_Arduino_2022_B.new_mex = Modello_Arduino_2022_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  Modello_Arduino_2022_B.Memory1[0] =
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0];
  Modello_Arduino_2022_B.Memory1[1] =
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1];

  /* Memory: '<Root>/Memory' */
  Modello_Arduino_2022_B.Memory_k[0] =
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[0];
  Modello_Arduino_2022_B.Memory_k[1] =
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[1];
  Modello_Arduino_2022_B.Memory_k[2] =
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[2];
  Modello_Arduino_2022_B.Memory_k[3] =
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[3];

  /* Memory: '<S1>/Memory3' */
  Modello_Arduino_2022_B.Memory3 =
    Modello_Arduino_2022_DW.Memory3_PreviousInput_o;
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 8;
       Modello_Arduino_2022_B.i++) {
    /* Memory: '<S1>/Memory' */
    Modello_Arduino_2022_B.Memory[Modello_Arduino_2022_B.i] =
      Modello_Arduino_2022_DW.Memory_PreviousInput_i[Modello_Arduino_2022_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&Modello_Arduino_2022_B.mess_out[0], &Modello_Arduino_2022_B.Add,
     &Modello_Arduino_2022_B.new_mex, &Modello_Arduino_2022_P.SIUAVuint8_Value,
     &Modello_Arduino_2022_B.Memory[0], &Modello_Arduino_2022_B.Memory1[0],
     &Modello_Arduino_2022_B.Memory_k[0], &Modello_Arduino_2022_B.Memory3,
     &Modello_Arduino_2022_B.SFunction_o1[0],
     &Modello_Arduino_2022_B.SFunction_o2,
     &Modello_Arduino_2022_B.SFunction_o3_m,
     &Modello_Arduino_2022_B.SFunction_o4_e[0],
     &Modello_Arduino_2022_B.SFunction_o5[0],
     &Modello_Arduino_2022_B.SFunction_o6, &Modello_Arduino_2022_B.SFunction_o7
     [0], &Modello_Arduino_2022_B.SFunction_o8,
     &Modello_Arduino_2022_B.SFunction_o9[0],
     &Modello_Arduino_2022_B.SFunction_o10[0],
     &Modello_Arduino_2022_B.SFunction_o11[0],
     &Modello_Arduino_2022_B.SFunction_o12,
     &Modello_Arduino_2022_B.SFunction_o13,
     &Modello_Arduino_2022_B.SFunction_o14,
     &Modello_Arduino_2022_B.SFunction_o15,
     &Modello_Arduino_2022_B.SFunction_o16,
     &Modello_Arduino_2022_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 6;
       Modello_Arduino_2022_B.i++) {
    Modello_Arduino_2022_B.WP_info_in[Modello_Arduino_2022_B.i] =
      Modello_Arduino_2022_B.SFunction_o9[Modello_Arduino_2022_B.i];
  }

  if ((!Modello_Arduino_2022_DW.WP_dbP_not_empty) ||
      ((Modello_Arduino_2022_B.SFunction_o7[0] == 3) &&
       (Modello_Arduino_2022_B.SFunction_o7[1] == 250))) {
    memset(&Modello_Arduino_2022_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    Modello_Arduino_2022_DW.WP_dbP_not_empty = true;
    memset(&Modello_Arduino_2022_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!Modello_Arduino_2022_DW.WP_dbP_AL_not_empty) ||
      ((Modello_Arduino_2022_B.SFunction_o7[0] == 3) &&
       (Modello_Arduino_2022_B.SFunction_o7[1] == 250))) {
    memset(&Modello_Arduino_2022_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    Modello_Arduino_2022_DW.WP_dbP_AL_not_empty = true;
  }

  Modello_Arduino_2022_B.GC_info[0] = Modello_Arduino_2022_B.SFunction_o7[0];
  Modello_Arduino_2022_B.GC_info[1] = Modello_Arduino_2022_B.SFunction_o7[1];
  Modello_Arduino_2022_B.GC_info[2] = Modello_Arduino_2022_B.SFunction_o11[0];
  if (Modello_Arduino_2022_B.GC_info[0] == 1) {
    if ((Modello_Arduino_2022_B.GC_info[1] > 0) &&
        (Modello_Arduino_2022_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(Modello_Arduino_2022_B.SFunction_o8) > 0.0F) {
        Modello_Arduino_2022_DW.riferimenti[Modello_Arduino_2022_B.GC_info[1] -
          1] = 1.0F;
      } else {
        if (Modello_Arduino_2022_B.SFunction_o8 == 0.0F) {
          Modello_Arduino_2022_DW.riferimenti[Modello_Arduino_2022_B.GC_info[1]
            - 1] = 0.0F;
        }
      }
    } else {
      if ((Modello_Arduino_2022_B.GC_info[1] > 7) &&
          (Modello_Arduino_2022_B.GC_info[1] < 12)) {
        Modello_Arduino_2022_DW.riferimenti[Modello_Arduino_2022_B.GC_info[1] -
          1] = Modello_Arduino_2022_B.SFunction_o8;
      }
    }
  }

  if (Modello_Arduino_2022_B.SFunction_o12 == 13) {
    Modello_Arduino_2022_DW.riferimenti[Modello_Arduino_2022_B.SFunction_o12 - 1]
      = Modello_Arduino_2022_B.SFunction_o13;
  }

  memcpy(&Modello_Arduino_2022_B.Val_out_MAV[0],
         &Modello_Arduino_2022_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((Modello_Arduino_2022_B.GC_info[0] == 3) &&
      (Modello_Arduino_2022_B.GC_info[1] == 200)) {
    if (Modello_Arduino_2022_B.SFunction_o9[0] > 6) {
      Modello_Arduino_2022_B.WP_info_in[0] = 6U;
    }

    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 6;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_DW.WP_dbI[Modello_Arduino_2022_B.pipk] =
        Modello_Arduino_2022_B.WP_info_in[0];
    }
  }

  if ((Modello_Arduino_2022_B.GC_info[0] == 3) &&
      (Modello_Arduino_2022_B.GC_info[1] < 200)) {
    if (Modello_Arduino_2022_B.SFunction_o10[1] == 0.0F) {
      Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.SFunction_o9[1] + 1U;
      if (Modello_Arduino_2022_B.SFunction_o9[1] + 1U > 65535U) {
        Modello_Arduino_2022_B.qY = 65535U;
      }

      for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 7;
           Modello_Arduino_2022_B.pipk++) {
        Modello_Arduino_2022_DW.WP_dbP[((int32_T)Modello_Arduino_2022_B.qY + 6 *
          Modello_Arduino_2022_B.pipk) - 1] =
          Modello_Arduino_2022_B.SFunction_o10[Modello_Arduino_2022_B.pipk];
      }

      Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.SFunction_o9[1] + 1U;
      if (Modello_Arduino_2022_B.SFunction_o9[1] + 1U > 65535U) {
        Modello_Arduino_2022_B.qY = 65535U;
      }

      for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 6;
           Modello_Arduino_2022_B.pipk++) {
        Modello_Arduino_2022_DW.WP_dbI[((int32_T)Modello_Arduino_2022_B.qY + 6 *
          (Modello_Arduino_2022_B.pipk + 1)) - 1] =
          Modello_Arduino_2022_B.WP_info_in[Modello_Arduino_2022_B.pipk + 1];
      }
    } else {
      Modello_Arduino_2022_B.pipk = (int32_T)
        (Modello_Arduino_2022_B.SFunction_o10[0] + 1.0F);
      for (Modello_Arduino_2022_B.f = 0; Modello_Arduino_2022_B.f < 7;
           Modello_Arduino_2022_B.f++) {
        Modello_Arduino_2022_DW.WP_dbP_AL[(Modello_Arduino_2022_B.pipk + 6 *
          Modello_Arduino_2022_B.f) - 1] =
          Modello_Arduino_2022_B.SFunction_o10[Modello_Arduino_2022_B.f];
      }

      Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.SFunction_o9[1] + 1U;
      if (Modello_Arduino_2022_B.SFunction_o9[1] + 1U > 65535U) {
        Modello_Arduino_2022_B.qY = 65535U;
      }

      for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 6;
           Modello_Arduino_2022_B.pipk++) {
        Modello_Arduino_2022_DW.WP_dbI[((int32_T)Modello_Arduino_2022_B.qY + 6 *
          (Modello_Arduino_2022_B.pipk + 1)) - 1] =
          Modello_Arduino_2022_B.WP_info_in[Modello_Arduino_2022_B.pipk + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((Modello_Arduino_2022_B.SFunction_o6 == 0) &&
      (Modello_Arduino_2022_B.SFunction_o3_m == 0)) {
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 0U;
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 0U;
  } else if ((Modello_Arduino_2022_B.SFunction_o6 == 0) &&
             (Modello_Arduino_2022_B.SFunction_o3_m == 3)) {
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 0U;
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 0U;
    Modello_Arduino_2022_DW.test1 = 0.0;
  } else if ((Modello_Arduino_2022_B.SFunction_o6 == 0) &&
             (Modello_Arduino_2022_B.SFunction_o3_m == 2)) {
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 0U;
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 0U;
    Modello_Arduino_2022_DW.test1 = 0.0;
  } else if ((Modello_Arduino_2022_B.SFunction_o6 == 0) &&
             (Modello_Arduino_2022_B.SFunction_o3_m == 1)) {
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 0U;
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 0U;
    Modello_Arduino_2022_DW.test1 = 1.0;
  } else {
    switch (Modello_Arduino_2022_B.SFunction_o6) {
     case 192:
      Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 192U;
      Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 192U;
      break;

     case 208:
      Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 208U;
      Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 208U;
      break;

     default:
      if ((Modello_Arduino_2022_B.SFunction_o6 == 220) &&
          (Modello_Arduino_2022_B.SFunction_o3_m != 5)) {
        if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 0) &&
            (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] == 0) &&
            ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[2] == 1) ||
             (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] == 1) ||
             (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] == 1) ||
             (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[5] == 1) ||
             (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 1) ||
             (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[7] == 1))) {
          Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 220U;
          Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 220U;
        } else if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 0) &&
                   (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] == 1) &&
                   ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[2] == 1) ||
                    (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] == 1) ||
                    (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] == 1) ||
                    (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[5] == 1) ||
                    (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 1) ||
                    (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[7] == 1)))
        {
          Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 220U;
          Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 220U;
        } else {
          Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 208U;
          Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          Modello_Arduino_2022_DW.Memory3_PreviousInput_o = 208U;
        }
      } else if (Modello_Arduino_2022_B.SFunction_o3_m == 5) {
        Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 220U;
        Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] = 192U;
        Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  Modello_Arduino_2022_B.qY = 100U * Modello_Arduino_2022_B.SFunction_o11[5];
  if (Modello_Arduino_2022_B.qY > 65535U) {
    Modello_Arduino_2022_B.qY = 65535U;
  }

  if (Modello_Arduino_2022_B.SFunction_o11[4] == 0) {
    if ((uint16_T)Modello_Arduino_2022_B.qY == 0) {
      Modello_Arduino_2022_B.z = 0U;
    } else {
      Modello_Arduino_2022_B.z = MAX_uint16_T;
    }
  } else {
    Modello_Arduino_2022_B.z = (uint16_T)(Modello_Arduino_2022_B.SFunction_o11[4]
      == 0U ? MAX_uint32_T : (uint32_T)(uint16_T)Modello_Arduino_2022_B.qY /
      Modello_Arduino_2022_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)Modello_Arduino_2022_B.qY - (uint16_T)
                   ((uint32_T)Modello_Arduino_2022_B.z *
                    Modello_Arduino_2022_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)
          Modello_Arduino_2022_B.SFunction_o11[4] >> 1) +
                    (Modello_Arduino_2022_B.SFunction_o11[4] & 1))) {
      Modello_Arduino_2022_B.z++;
    }
  }

  Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] = (uint8_T)AP_mode_idx_0;
  Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] = (uint8_T)AP_mode_idx_1;
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 7;
       Modello_Arduino_2022_B.i++) {
    Modello_Arduino_2022_B.Switch1_gg = rt_roundf_snf
      (Modello_Arduino_2022_DW.riferimenti[Modello_Arduino_2022_B.i]);
    if (Modello_Arduino_2022_B.Switch1_gg < 256.0F) {
      if (Modello_Arduino_2022_B.Switch1_gg >= 0.0F) {
        Modello_Arduino_2022_DW.Memory2_PreviousInput_a[Modello_Arduino_2022_B.i
          + 2] = (uint8_T)Modello_Arduino_2022_B.Switch1_gg;
      } else {
        Modello_Arduino_2022_DW.Memory2_PreviousInput_a[Modello_Arduino_2022_B.i
          + 2] = 0U;
      }
    } else {
      Modello_Arduino_2022_DW.Memory2_PreviousInput_a[Modello_Arduino_2022_B.i +
        2] = MAX_uint8_T;
    }
  }

  /* RateTransition: '<S27>/Rate Transition' */
  Modello_Arduino_2022_B.RateTransition =
    Modello_Arduino_2022_DW.RateTransition_Buffer0;

  /* Sum: '<S27>/Add1' incorporates:
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Memory: '<S27>/Memory1'
   */
  Modello_Arduino_2022_B.num_254 = (Modello_Arduino_2022_P.Constant2_Value_jg +
    Modello_Arduino_2022_P.Constant3_Value_o) +
    Modello_Arduino_2022_DW.Memory1_PreviousInput;

  /* Switch: '<S27>/Switch' */
  if (Modello_Arduino_2022_B.num_254 > Modello_Arduino_2022_P.Switch_Threshold_f)
  {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    Modello_Arduino_2022_DW.Memory1_PreviousInput =
      Modello_Arduino_2022_P.Constant2_Value_jg;
  } else {
    /* Switch: '<S27>/Switch' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput =
      Modello_Arduino_2022_B.num_254;
  }

  /* End of Switch: '<S27>/Switch' */

  /* MATLAB Function: '<S19>/iflogic_function' */
  if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 1.0) ||
      (Modello_Arduino_2022_DW.Memory1_PreviousInput == 3.0)) {
    Modello_Arduino_2022_B.iflogic = 26U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 2.0) ||
             (Modello_Arduino_2022_DW.Memory1_PreviousInput == 4.0)) {
    Modello_Arduino_2022_B.iflogic = 30U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             (Modello_Arduino_2022_B.RateTransition == 2.0)) {
    Modello_Arduino_2022_B.iflogic = 33U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             (Modello_Arduino_2022_B.RateTransition == 6.0)) {
    Modello_Arduino_2022_B.iflogic = 34U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             (Modello_Arduino_2022_B.RateTransition == 0.0)) {
    Modello_Arduino_2022_B.iflogic = 0U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             ((Modello_Arduino_2022_B.RateTransition == 1.0) ||
              (Modello_Arduino_2022_B.RateTransition == 5.0) ||
              (Modello_Arduino_2022_B.RateTransition == 9.0))) {
    Modello_Arduino_2022_B.iflogic = 1U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             ((Modello_Arduino_2022_B.RateTransition == 3.0) ||
              (Modello_Arduino_2022_B.RateTransition == 8.0))) {
    Modello_Arduino_2022_B.iflogic = 74U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             (Modello_Arduino_2022_B.RateTransition == 7.0)) {
    Modello_Arduino_2022_B.iflogic = 36U;
  } else if ((Modello_Arduino_2022_DW.Memory1_PreviousInput == 0.0) &&
             (Modello_Arduino_2022_B.RateTransition == 4.0)) {
    Modello_Arduino_2022_B.iflogic = 29U;
  } else {
    Modello_Arduino_2022_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S19>/iflogic_function' */

  /* Sum: '<S27>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Memory: '<S27>/Memory'
   */
  Modello_Arduino_2022_DW.Memory_PreviousInput +=
    Modello_Arduino_2022_P.Constant_Value_ml +
    Modello_Arduino_2022_P.Constant1_Value_n0;

  /* Gain: '<S19>/Gain' */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_cw *
    Modello_Arduino_2022_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  Modello_Arduino_2022_B.DataTypeConversion3 = Modello_Arduino_2022_B.a_n < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (uint32_T)
    Modello_Arduino_2022_B.a_n;

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 6;
       Modello_Arduino_2022_B.pipk++) {
    Modello_Arduino_2022_B.WP_info[Modello_Arduino_2022_B.pipk] =
      Modello_Arduino_2022_DW.WP_dbI[6 * Modello_Arduino_2022_B.pipk];
  }

  for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 7;
       Modello_Arduino_2022_B.pipk++) {
    Modello_Arduino_2022_B.WP_param[Modello_Arduino_2022_B.pipk] =
      Modello_Arduino_2022_DW.WP_dbP[6 * Modello_Arduino_2022_B.pipk];
  }

  if ((Modello_Arduino_2022_B.GC_info[0] == 2) &&
      (Modello_Arduino_2022_B.GC_info[1] < 6)) {
    Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.GC_info[1] + 1U;
    if (Modello_Arduino_2022_B.GC_info[1] + 1U > 65535U) {
      Modello_Arduino_2022_B.qY = 65535U;
    }

    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 6;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.WP_info[Modello_Arduino_2022_B.pipk] =
        Modello_Arduino_2022_DW.WP_dbI[(6 * Modello_Arduino_2022_B.pipk +
        (int32_T)Modello_Arduino_2022_B.qY) - 1];
    }

    Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.GC_info[1] + 1U;
    if (Modello_Arduino_2022_B.GC_info[1] + 1U > 65535U) {
      Modello_Arduino_2022_B.qY = 65535U;
    }

    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 7;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.WP_param[Modello_Arduino_2022_B.pipk] =
        Modello_Arduino_2022_DW.WP_dbP[(6 * Modello_Arduino_2022_B.pipk +
        (int32_T)Modello_Arduino_2022_B.qY) - 1];
    }
  }

  if ((Modello_Arduino_2022_B.GC_info[0] == 3) &&
      (Modello_Arduino_2022_B.GC_info[1] < 200)) {
    Modello_Arduino_2022_B.qY = Modello_Arduino_2022_B.GC_info[1] + 1U;
    if (Modello_Arduino_2022_B.GC_info[1] + 1U > 65535U) {
      Modello_Arduino_2022_B.qY = 65535U;
    }

    for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 6;
         Modello_Arduino_2022_B.pipk++) {
      Modello_Arduino_2022_B.WP_info[Modello_Arduino_2022_B.pipk] =
        Modello_Arduino_2022_DW.WP_dbI[(6 * Modello_Arduino_2022_B.pipk +
        (int32_T)Modello_Arduino_2022_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function' */

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S7>/Constant'
   */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Gain_Gain_b *
    Modello_Arduino_2022_P.Constant_Value_j[0]);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* Outputs for Resettable SubSystem: '<S411>/Resettable Subsystem' */
  Modello_Arduino_2022_B.Sum_ax = Modello_ResettableSubsystem
    (Modello_Arduino_2022_B.SFunction_o4_e[0],
     &Modello_Arduino_2022_DW.ResettableSubsystem_p,
     &Modello_Arduino_2022_P.ResettableSubsystem_p,
     &Modello_Arduino_2022_PrevZCX.ResettableSubsystem_p);

  /* End of Outputs for SubSystem: '<S411>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S411>/Enabled Subsystem' */
  Modello_Ar_EnabledSubsystem(Modello_Arduino_2022_B.SFunction_o4_e[0],
    Modello_Arduino_2022_B.Sum_ax, &Modello_Arduino_2022_B.Switch_m,
    &Modello_Arduino_2022_P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S411>/Enabled Subsystem' */

  /* MATLAB Function: '<S565>/MATLAB Function' incorporates:
   *  Constant: '<S556>/Constant'
   *  Constant: '<S565>/Constant'
   */
  Modello_Arduino_2022_B.num_254 = Modello_Arduino_2022_P.Constant_Value_oq *
    Modello_Arduino_2022_P.Constant_Value_d;
  Modello_Arduino_2022_B.RateTransition = Modello_Arduino_2022_B.num_254 /
    (Modello_Arduino_2022_B.num_254 + 1.0);

  /* MATLABSystem: '<S556>/Serial Receive' */
  if (Modello_Arduino_2022_DW.obj_c.Protocol !=
      Modello_Arduino_2022_P.SerialReceive_Protocol) {
    Modello_Arduino_2022_DW.obj_c.Protocol =
      Modello_Arduino_2022_P.SerialReceive_Protocol;
  }

  MW_Serial_read(1, Modello_Arduino_2022_DW.obj_c.DataSizeInBytes,
                 &Modello_Arduino_2022_B.b_dataOut_p[0], &status);

  /* Outputs for Enabled SubSystem: '<S556>/Subsystem1' incorporates:
   *  EnablePort: '<S564>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S564>/MATLAB Function' */
    for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 31;
         Modello_Arduino_2022_B.i++) {
      Modello_Arduino_2022_B.messaggio[Modello_Arduino_2022_B.i] = 0U;
    }

    guard1 = false;
    if (!Modello_Arduino_2022_DW.start_found_d) {
      Modello_Arduino_2022_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (Modello_Arduino_2022_B.i - 1 < 30)) {
        if ((Modello_Arduino_2022_B.b_dataOut_p[(uint8_T)
             Modello_Arduino_2022_B.i - 1] == 255) &&
            (Modello_Arduino_2022_B.b_dataOut_p[(uint8_T)
             Modello_Arduino_2022_B.i] == 254)) {
          Modello_Arduino_2022_B.tolleranza_distWP_fut = 31 - (uint8_T)
            Modello_Arduino_2022_B.i;
          for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
               Modello_Arduino_2022_B.tolleranza_distWP_fut;
               Modello_Arduino_2022_B.pipk++) {
            Modello_Arduino_2022_DW.message_e[Modello_Arduino_2022_B.pipk] =
              Modello_Arduino_2022_B.b_dataOut_p[((uint8_T)
              Modello_Arduino_2022_B.i + Modello_Arduino_2022_B.pipk) - 1];
          }

          Modello_Arduino_2022_DW.counter_a = (uint8_T)(32 - (uint8_T)
            Modello_Arduino_2022_B.i);
          Modello_Arduino_2022_DW.start_found_d = true;
          exitg1 = true;
        } else {
          Modello_Arduino_2022_B.i++;
        }
      }

      if (Modello_Arduino_2022_DW.counter_a == 31) {
        for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 31;
             Modello_Arduino_2022_B.i++) {
          Modello_Arduino_2022_B.messaggio[Modello_Arduino_2022_B.i] =
            Modello_Arduino_2022_DW.message_e[Modello_Arduino_2022_B.i];
          Modello_Arduino_2022_DW.message_e[Modello_Arduino_2022_B.i] = 0U;
        }

        Modello_Arduino_2022_DW.start_found_d = false;
        Modello_Arduino_2022_DW.counter_a = 0U;
        guard1 = true;
      }
    } else {
      Modello_Arduino_2022_B.qY = 31U - /*MW:OvSatOk*/
        Modello_Arduino_2022_DW.counter_a;
      if (31U - Modello_Arduino_2022_DW.counter_a > 31U) {
        Modello_Arduino_2022_B.qY = 0U;
      }

      Modello_Arduino_2022_B.pipk = (int32_T)(Modello_Arduino_2022_DW.counter_a
        + 1U);
      if (Modello_Arduino_2022_DW.counter_a + 1U > 255U) {
        Modello_Arduino_2022_B.pipk = 255;
      }

      if ((uint8_T)Modello_Arduino_2022_B.pipk > 31) {
        Modello_Arduino_2022_B.f = 1;
      } else {
        Modello_Arduino_2022_B.f = (uint8_T)Modello_Arduino_2022_B.pipk;
      }

      if (1 > (uint8_T)Modello_Arduino_2022_B.qY) {
        Modello_Arduino_2022_B.tolleranza_distWP_fut = -1;
      } else {
        Modello_Arduino_2022_B.tolleranza_distWP_fut = (uint8_T)
          Modello_Arduino_2022_B.qY - 1;
      }

      for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
           Modello_Arduino_2022_B.tolleranza_distWP_fut;
           Modello_Arduino_2022_B.pipk++) {
        Modello_Arduino_2022_DW.message_e[(Modello_Arduino_2022_B.f +
          Modello_Arduino_2022_B.pipk) - 1] =
          Modello_Arduino_2022_B.b_dataOut_p[Modello_Arduino_2022_B.pipk];
      }

      Modello_Arduino_2022_B.qY = 31U - /*MW:OvSatOk*/
        Modello_Arduino_2022_DW.counter_a;
      if (31U - Modello_Arduino_2022_DW.counter_a > 31U) {
        Modello_Arduino_2022_B.qY = 0U;
      }

      Modello_Arduino_2022_DW.counter_a = (uint8_T)Modello_Arduino_2022_B.qY;
      for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 31;
           Modello_Arduino_2022_B.i++) {
        Modello_Arduino_2022_B.messaggio[Modello_Arduino_2022_B.i] =
          Modello_Arduino_2022_DW.message_e[Modello_Arduino_2022_B.i];
        Modello_Arduino_2022_DW.message_e[Modello_Arduino_2022_B.i] = 0U;
      }

      status = Modello_Arduino_2022_DW.counter_a;
      do {
        exitg3 = 0;
        if (status < 31) {
          if ((Modello_Arduino_2022_B.b_dataOut_p[status - 1] == 255) &&
              (Modello_Arduino_2022_B.b_dataOut_p[status] == 254)) {
            Modello_Arduino_2022_B.tolleranza_distWP_fut = 31 - status;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_DW.message_e[Modello_Arduino_2022_B.pipk] =
                Modello_Arduino_2022_B.b_dataOut_p[(status +
                Modello_Arduino_2022_B.pipk) - 1];
            }

            Modello_Arduino_2022_B.qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              Modello_Arduino_2022_B.qY = 0U;
            }

            Modello_Arduino_2022_DW.counter_a = (uint8_T)(31 - (int32_T)
              Modello_Arduino_2022_B.qY);
            Modello_Arduino_2022_DW.start_found_d = true;
            guard1 = true;
            exitg3 = 1;
          } else {
            Modello_Arduino_2022_DW.start_found_d = false;
            Modello_Arduino_2022_DW.counter_a = 0U;
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
          memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o1_c[0], (uint8_T*)
                 &Modello_Arduino_2022_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o2_h[0], (uint8_T*)
                 &Modello_Arduino_2022_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o3[0], (uint8_T*)
                 &Modello_Arduino_2022_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o4[0], (uint8_T*)
                 &Modello_Arduino_2022_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&Modello_Arduino_2022_B.ByteUnpack_o5, (uint8_T*)
                 &Modello_Arduino_2022_B.messaggio[0] + MW_inputPortOffset,
                 MW_outputPortWidth);
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
  Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 =
    Modello_Arduino_2022_P.Gain1_Gain_p * (real_T)
    Modello_Arduino_2022_B.ByteUnpack_o3[0];
  Modello_Arduino_2022_B.rtb_Gain1_hx_idx_1 =
    Modello_Arduino_2022_P.Gain1_Gain_p * (real_T)
    Modello_Arduino_2022_B.ByteUnpack_o3[1];

  /* Sum: '<S565>/Sum' incorporates:
   *  UnitDelay: '<S565>/Unit Delay'
   */
  Modello_Arduino_2022_B.num_254 = Modello_Arduino_2022_B.rtb_Gain1_hx_idx_1 +
    Modello_Arduino_2022_DW.UnitDelay_DSTATE;

  /* Product: '<S565>/Product1' incorporates:
   *  MATLAB Function: '<S565>/MATLAB Function'
   */
  Modello_Arduino_2022_B.Product1 = Modello_Arduino_2022_B.RateTransition *
    Modello_Arduino_2022_B.num_254;

  /* ManualSwitch: '<S7>/Manual Switch' incorporates:
   *  Constant: '<S7>/Constant1'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 9;
       Modello_Arduino_2022_B.i++) {
    if (Modello_Arduino_2022_P.ManualSwitch_CurrentSetting == 1) {
      Modello_Arduino_2022_B.ManualSwitch[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_P.Constant1_Value_ng[Modello_Arduino_2022_B.i];
    } else {
      Modello_Arduino_2022_B.ManualSwitch[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_B.ByteReversal[Modello_Arduino_2022_B.i];
    }
  }

  /* End of ManualSwitch: '<S7>/Manual Switch' */

  /* Gain: '<S552>/Gain1' */
  Modello_Arduino_2022_B.Gain1_l = Modello_Arduino_2022_P.Gain1_Gain_j *
    Modello_Arduino_2022_B.ManualSwitch[6];

  /* MATLAB Function: '<S417>/MATLAB Function1' */
  guard1 = false;
  if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] == 1) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     */
    if (Modello_Arduino_2022_B.Switch_m != 0.0) {
      Modello_Arduino_2022_B.Sum3 = Modello_Arduino_2022_P.Constant_Value_l;
    } else {
      Modello_Arduino_2022_B.Sum3 = Modello_Arduino_2022_B.Product1;
    }

    /* End of Switch: '<S38>/Switch' */
    if (Modello_Arduino_2022_B.Sum3 > Modello_Arduino_2022_P.safe_V) {
      Modello_Arduino_2022_DW.alarm = 1.0;
    } else if (fabs(Modello_Arduino_2022_P.Gain_Gain_i2 *
                    Modello_Arduino_2022_B.Gain1_l) >
               Modello_Arduino_2022_P.safe_phi) {
      Modello_Arduino_2022_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 1) {
      Modello_Arduino_2022_DW.alarm = 0.0;
    }
  }

  /* Outputs for Resettable SubSystem: '<S434>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S437>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &Modello_Arduino_2022_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (Modello_Arduino_2022_DW.alarm)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S438>/Sum' incorporates:
     *  Memory: '<S438>/Memory'
     */
    Modello_Arduino_2022_DW.Memory_PreviousInput_j =
      Modello_Arduino_2022_P.Memory_InitialCondition;
  }

  /* Memory: '<S438>/Memory' */
  Modello_Arduino_2022_B.Sum_ax = Modello_Arduino_2022_DW.Memory_PreviousInput_j;

  /* Sum: '<S438>/Sum' incorporates:
   *  Constant: '<S438>/Constant4'
   *  Memory: '<S438>/Memory'
   */
  Modello_Arduino_2022_DW.Memory_PreviousInput_j += Modello_Arduino_2022_P.t_AP;

  /* End of Outputs for SubSystem: '<S434>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S434>/Enabled ' incorporates:
   *  EnablePort: '<S436>/Enable'
   */
  /* MATLAB Function: '<S417>/MATLAB Function1' */
  if (Modello_Arduino_2022_DW.alarm > 0.0) {
    Modello_Arduino_2022_DW.Enabled_MODE = true;

    /* Switch: '<S436>/Switch' */
    if (Modello_Arduino_2022_DW.Memory_PreviousInput_j >
        Modello_Arduino_2022_P.time_alarm_SAFE) {
      /* Switch: '<S436>/Switch' incorporates:
       *  Constant: '<S436>/Constant'
       */
      Modello_Arduino_2022_B.Switch_j = Modello_Arduino_2022_P.Constant_Value_k;
    } else {
      /* Switch: '<S436>/Switch' incorporates:
       *  Constant: '<S436>/Constant1'
       */
      Modello_Arduino_2022_B.Switch_j = Modello_Arduino_2022_P.Constant1_Value;
    }

    /* End of Switch: '<S436>/Switch' */
  } else {
    if (Modello_Arduino_2022_DW.Enabled_MODE) {
      /* Disable for Switch: '<S436>/Switch' incorporates:
       *  Outport: '<S436>/Alarm Safe'
       */
      Modello_Arduino_2022_B.Switch_j = Modello_Arduino_2022_P.AlarmSafe_Y0;
      Modello_Arduino_2022_DW.Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S434>/Enabled ' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/load uint16'
   *  Gain: '<S21>/Gain'
   */
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[0] =
    Modello_Arduino_2022_P.loaduint16_Value;
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  Modello_Arduino_2022_B.qY = 10U * Modello_Arduino_2022_B.z;
  if (Modello_Arduino_2022_B.qY > 65535U) {
    Modello_Arduino_2022_B.qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)
    Modello_Arduino_2022_B.qY;
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[3] =
    Modello_Arduino_2022_B.SFunction_o11[6];
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[4] =
    Modello_Arduino_2022_B.SFunction_o11[2];
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[5] =
    Modello_Arduino_2022_P._Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Switch_j);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S21>/Data Type Conversion4' incorporates:
   *  Constant: '<S38>/Constant2'
   */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant2_Value_i);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* Gain: '<S21>/Gain2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Gain2_Gain *
    Modello_Arduino_2022_P.Constant_Value_j[2]);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Gain: '<S21>/Gain2'
   */
  Modello_Arduino_2022_B.Gain1 = (int16_T)(((Modello_Arduino_2022_B.a_n < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n : (int32_T)
    (int16_T)(uint16_T)Modello_Arduino_2022_B.a_n) *
    Modello_Arduino_2022_P.Gain1_Gain_eu) >> 18);

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant_Value_j[1]);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 256.0);
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion3' */
  Modello_Arduino_2022_B.B_Remaining = (int8_T)(Modello_Arduino_2022_B.a_n < 0.0
    ? (int32_T)(int8_T)-(int8_T)(uint8_T)-Modello_Arduino_2022_B.a_n : (int32_T)
    (int8_T)(uint8_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant_Value_e);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion = Modello_Arduino_2022_B.a_n < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (uint32_T)
    Modello_Arduino_2022_B.a_n;

  /* MATLAB Function: '<S17>/Alarm set' incorporates:
   *  Constant: '<S38>/Constant2'
   *  SignalConversion generated from: '<S26>/ SFunction '
   */
  rtb_H_mav[0] = Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0];
  rtb_H_mav[1] = Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1];
  if (Modello_Arduino_2022_B.Switch_j == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (Modello_Arduino_2022_P.Constant2_Value_i == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S17>/Alarm set' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S17>/Type fixed_wing Autopilot generic'
   */
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[0] =
    Modello_Arduino_2022_P.Typefixed_wingAutopilotgeneric_[0];
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[2] = rtb_H_mav[0];
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[1] =
    Modello_Arduino_2022_P.Typefixed_wingAutopilotgeneric_[1];
  Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[3] = rtb_H_mav[1];
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 6;
       Modello_Arduino_2022_B.i++) {
    /* Gain: '<S18>/Gain' */
    Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_dn *
      Modello_Arduino_2022_B.ManualSwitch[Modello_Arduino_2022_B.i];

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    if (Modello_Arduino_2022_B.Sum5 < 0.0) {
      Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
    } else {
      Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
    }

    if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf
        (Modello_Arduino_2022_B.a_n)) {
      Modello_Arduino_2022_B.a_n = 0.0;
    } else {
      Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    Modello_Arduino_2022_B.DataTypeConversion_ld[Modello_Arduino_2022_B.i] =
      (int16_T)(Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)
                (uint16_T)-Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)
                (uint16_T)Modello_Arduino_2022_B.a_n);
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_dn *
    Modello_Arduino_2022_P.Constant_Value_h;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_ld[6] = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_dn *
    Modello_Arduino_2022_P.Constant1_Value_f;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_ld[7] = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_dn *
    Modello_Arduino_2022_P.Constant2_Value_eu;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_ld[8] = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S553>/Gain1' */
  Modello_Arduino_2022_B.Gain1_i = Modello_Arduino_2022_P.Gain1_Gain_jd *
    Modello_Arduino_2022_B.ManualSwitch[7];

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Gain: '<S554>/Gain1'
   */
  Modello_Arduino_2022_B.DataTypeConversion1[0] = (real32_T)
    Modello_Arduino_2022_B.Gain1_l;
  Modello_Arduino_2022_B.DataTypeConversion1[1] = (real32_T)
    Modello_Arduino_2022_B.Gain1_i;
  Modello_Arduino_2022_B.DataTypeConversion1[2] = (real32_T)
    (Modello_Arduino_2022_P.Gain1_Gain_l * Modello_Arduino_2022_B.ManualSwitch[8]);
  Modello_Arduino_2022_B.DataTypeConversion1[3] = (real32_T)
    Modello_Arduino_2022_B.ManualSwitch[3];
  Modello_Arduino_2022_B.DataTypeConversion1[4] = (real32_T)
    Modello_Arduino_2022_B.ManualSwitch[4];
  Modello_Arduino_2022_B.DataTypeConversion1[5] = (real32_T)
    Modello_Arduino_2022_B.ManualSwitch[5];

  /* Gain: '<S557>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Modello_Arduino_2022_B.Gain1_nb = Modello_Arduino_2022_P.Gain1_Gain_hr *
    Modello_Arduino_2022_B.ByteUnpack_o2_h[0];

  /* Gain: '<S558>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Modello_Arduino_2022_B.Gain1_m = Modello_Arduino_2022_P.Gain1_Gain_m *
    Modello_Arduino_2022_B.ByteUnpack_o2_h[1];

  /* Gain: '<S16>/Gain' */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_bx[0] *
    Modello_Arduino_2022_B.Gain1_nb;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_a[0] = Modello_Arduino_2022_B.a_n <
    0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (int32_T)(uint32_T)
    Modello_Arduino_2022_B.a_n;

  /* Gain: '<S16>/Gain' */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_bx[1] *
    Modello_Arduino_2022_B.Gain1_m;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_a[1] = Modello_Arduino_2022_B.a_n <
    0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (int32_T)(uint32_T)
    Modello_Arduino_2022_B.a_n;

  /* Gain: '<S16>/Gain' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_bx[2] *
    Modello_Arduino_2022_B.ByteUnpack_o2_h[2];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_a[2] = Modello_Arduino_2022_B.a_n <
    0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (int32_T)(uint32_T)
    Modello_Arduino_2022_B.a_n;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/alt_r'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain_Gain_bx[3] *
    Modello_Arduino_2022_P.alt_r_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_a[3] = Modello_Arduino_2022_B.a_n <
    0.0 ? -(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (int32_T)(uint32_T)
    Modello_Arduino_2022_B.a_n;

  /* Gain: '<S556>/Gain4' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion3'
   */
  Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = Modello_Arduino_2022_P.Gain4_Gain *
    (real_T)Modello_Arduino_2022_B.ByteUnpack_o4[0];

  /* Gain: '<S16>/Gain1' */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain1_Gain_e *
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_p[0] = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S16>/Gain1' incorporates:
   *  Constant: '<S16>/vel y'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain1_Gain_e *
    Modello_Arduino_2022_P.vely_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_p[1] = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S16>/Gain1' */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain1_Gain_e *
    Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_p[2] = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S555>/Gain1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   *  Gain: '<S559>/Gain1'
   */
  Modello_Arduino_2022_B.Gain1_h = Modello_Arduino_2022_P.Gain1_Gain_f *
    Modello_Arduino_2022_B.ByteUnpack_o2_h[3] *
    Modello_Arduino_2022_P.Gain1_Gain_n;

  /* Gain: '<S16>/Gain2' */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.Gain2_Gain_k *
    Modello_Arduino_2022_B.Gain1_h;

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  Modello_Arduino_2022_B.DataTypeConversion2_h = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Constant: '<S22>/airspeed groundspeed alt climb1'
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   */
  Modello_Arduino_2022_B.AGAC[0] = (real32_T)Modello_Arduino_2022_B.Product1;
  Modello_Arduino_2022_B.AGAC[1] = (real32_T)
    Modello_Arduino_2022_P.airspeedgroundspeedaltclimb1_Va;
  Modello_Arduino_2022_B.AGAC[2] = Modello_Arduino_2022_B.ByteUnpack_o2_h[2];
  Modello_Arduino_2022_B.AGAC[3] = (real32_T)
    Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0;

  /* Gain: '<S33>/Gain' */
  Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 =
    Modello_Arduino_2022_P.Gain_Gain_lb * Modello_Arduino_2022_B.Gain1_h;

  /* Switch: '<S34>/Switch2' incorporates:
   *  Abs: '<S34>/Abs'
   *  Constant: '<S34>/Constant2'
   *  Sum: '<S34>/Sum'
   */
  if (!(Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 >
        Modello_Arduino_2022_P.Switch2_Threshold_a)) {
    Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 =
      Modello_Arduino_2022_P.Constant2_Value - fabs
      (Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0);
  }

  /* End of Switch: '<S34>/Switch2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading_g = (int16_T)(Modello_Arduino_2022_B.a_n < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n : (int32_T)
    (int16_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* Gain: '<S22>/USCITA PERCENTUALE' incorporates:
   *  Constant: '<S6>/Constant'
   */
  Modello_Arduino_2022_B.Sum5 = Modello_Arduino_2022_P.USCITAPERCENTUALE_Gain *
    Modello_Arduino_2022_P.Constant_Value_fg;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  if (Modello_Arduino_2022_B.Sum5 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Sum5);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Sum5);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  Modello_Arduino_2022_B.Throttle = (uint16_T)(Modello_Arduino_2022_B.a_n < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* ManualSwitch: '<S7>/Manual Switch8' incorporates:
   *  Constant: '<S7>/Constant7'
   */
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 8;
       Modello_Arduino_2022_B.i++) {
    if (Modello_Arduino_2022_P.ManualSwitch8_CurrentSetting == 1) {
      Modello_Arduino_2022_B.ManualSwitch1[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_P.Constant7_Value[Modello_Arduino_2022_B.i];
    } else {
      Modello_Arduino_2022_B.ManualSwitch1[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_B.One_time_initialization.ByteUnpack[Modello_Arduino_2022_B.i];
    }
  }

  /* End of ManualSwitch: '<S7>/Manual Switch8' */

  /* S-Function (PWMinterrupt_throttle_v4_4): '<S9>/S-Function Builder6' */
  PWMinterrupt_throttle_v4_4_Outputs_wrapper
    (&Modello_Arduino_2022_B.PWM_throttle);

  /* Sum: '<S590>/Sum5' incorporates:
   *  Constant: '<S590>/manetta_massima'
   *  Constant: '<S590>/manetta_minima'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   *  Product: '<S590>/Divide2'
   *  Product: '<S590>/Multiply1'
   *  Sum: '<S590>/Sum2'
   *  Sum: '<S590>/Sum3'
   *  Sum: '<S590>/Sum4'
   */
  Modello_Arduino_2022_B.Sum5 = ((real_T)Modello_Arduino_2022_B.PWM_throttle -
    Modello_Arduino_2022_B.ManualSwitch1[1]) /
    (Modello_Arduino_2022_B.ManualSwitch1[0] -
     Modello_Arduino_2022_B.ManualSwitch1[1]) *
    (Modello_Arduino_2022_P.attuatore_Tmax -
     Modello_Arduino_2022_P.attuatore_Tmin) +
    Modello_Arduino_2022_P.attuatore_Tmin;

  /* Gain: '<S29>/Gain2' */
  Modello_Arduino_2022_B.Switch_i = Modello_Arduino_2022_P.Gain2_Gain_j *
    Modello_Arduino_2022_B.Sum5;

  /* S-Function (PWMinterrupt_goHome): '<S9>/S-Function Builder2' */
  PWMinterrupt_goHome_Outputs_wrapper(&Modello_Arduino_2022_B.SFunctionBuilder2);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  if (Modello_Arduino_2022_B.SFunctionBuilder2 >
      Modello_Arduino_2022_P.Switch_Threshold_m) {
    Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 =
      Modello_Arduino_2022_P.Constant_Value_b;
  } else {
    Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 =
      Modello_Arduino_2022_P.Constant1_Value_js;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<S38>/ STATI' incorporates:
   *  Constant: '<S38>/Constant2'
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  if (Modello_Arduino_2022_DW.is_active_c26_Modello_Arduino_2 == 0U) {
    Modello_Arduino_2022_DW.is_active_c26_Modello_Arduino_2 = 1U;
    Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
      Modello_Arduino_2022_IN_MANUALE;
  } else {
    switch (Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022) {
     case Modello_Arduino_2_IN_AUTOMATICA:
      if (Modello_Arduino_2022_P.Constant2_Value_i == 1.0) {
        Modello_Arduino_2022_DW.is_AUTOMATICA = 0;
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Ar_IN_Intervento_Pilota;
      } else if (Modello_Arduino_2022_B.Switch_j == 1.0) {
        Modello_Arduino_2022_DW.is_AUTOMATICA = 0;
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_Safe;
      } else if (Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 == 1.0) {
        Modello_Arduino_2022_DW.is_AUTOMATICA = 0;
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_Go_Home;
      } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] == 0) {
        Modello_Arduino_2022_DW.is_AUTOMATICA = 0;
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_202_IN_Stand_By;
      } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 1) {
        Modello_Arduino_2022_DW.is_AUTOMATICA = 0;
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_MANUALE;
      } else {
        switch (Modello_Arduino_2022_DW.is_AUTOMATICA) {
         case Model_IN_ATTERRAGGIO_AUTOMATICO:
          if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[8] == 0) &&
              (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] > 20.0F) &&
              (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 1)) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_202_IN_WAYPOINT;
          } else if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[8] == 0) &&
                     (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] > 20.0F)) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_2_IN_VETTORIALE;
          } else if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[7] == 1) &&
                     (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[8] == 0) &&
                     (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] < 1.0F) &&
                     (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 < 1.0)) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_A_IN_DECOLLO_AUTOMATICO;
          } else {
            Modello_Arduino_2022_B.modo = 4.0;
            Modello_Arduino_2022_B.switch_manetta = 1.0;
            Modello_Arduino_2022_B.switch_equilibratore = 1.0;
            Modello_Arduino_2022_B.switch_alettoni = 1.0;
            Modello_Arduino_2022_B.switch_timone = 1.0;
          }
          break;

         case Modello_A_IN_DECOLLO_AUTOMATICO:
          if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[7] == 0) &&
              (Modello_Arduino_2022_B.Product1 >= 1.0) &&
              ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] == 1) ||
               (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] == 1) ||
               (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[2] == 1))) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_2_IN_VETTORIALE;
          } else if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 1) &&
                     (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] > 30.0F)) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_202_IN_WAYPOINT;
          } else {
            Modello_Arduino_2022_B.modo = 3.0;
            Modello_Arduino_2022_B.switch_manetta = 1.0;
            Modello_Arduino_2022_B.switch_equilibratore = 1.0;
            Modello_Arduino_2022_B.switch_alettoni = 1.0;
            Modello_Arduino_2022_B.switch_timone = 1.0;
          }
          break;

         case Modello_Arduino_2022_IN_TEST:
          if (Modello_Arduino_2022_DW.test1 == 0.0) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_2_IN_VETTORIALE;
          } else {
            Modello_Arduino_2022_B.switch_manetta = 0.0;
            Modello_Arduino_2022_B.switch_equilibratore = 0.0;
            Modello_Arduino_2022_B.switch_alettoni = 0.0;
            Modello_Arduino_2022_B.switch_timone = 0.0;
          }
          break;

         case Modello_Arduino_2_IN_VETTORIALE:
          if (Modello_Arduino_2022_DW.test1 == 1.0) {
            Modello_Arduino_2022_DW.is_AUTOMATICA = Modello_Arduino_2022_IN_TEST;
          } else if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[7] == 1) &&
                     (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 < 1.0)) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_A_IN_DECOLLO_AUTOMATICO;
          } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[8] == 1) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Model_IN_ATTERRAGGIO_AUTOMATICO;
          } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 1) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_202_IN_WAYPOINT;
          } else {
            Modello_Arduino_2022_B.modo = 2.0;
            Modello_Arduino_2022_B.switch_manetta = 1.0;
            Modello_Arduino_2022_B.switch_equilibratore = 1.0;
            Modello_Arduino_2022_B.switch_alettoni = 1.0;
            Modello_Arduino_2022_B.switch_timone = 1.0;
          }
          break;

         default:
          /* case IN_WAYPOINT: */
          if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 0) &&
              ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] == 1) ||
               (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] == 1) ||
               (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[2] == 1) ||
               (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[7] == 1))) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Modello_Arduino_2_IN_VETTORIALE;
          } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[8] == 1) {
            Modello_Arduino_2022_DW.is_AUTOMATICA =
              Model_IN_ATTERRAGGIO_AUTOMATICO;
          } else {
            Modello_Arduino_2022_B.modo = 1.0;
            Modello_Arduino_2022_B.switch_manetta = 1.0;
            Modello_Arduino_2022_B.switch_equilibratore = 1.0;
            Modello_Arduino_2022_B.switch_alettoni = 1.0;
            Modello_Arduino_2022_B.switch_timone = 1.0;
          }
          break;
        }
      }
      break;

     case Modello_Arduino_2022_IN_Go_Home:
      if ((Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 == 0.0) &&
          ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[6] == 1) ||
           (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] == 1) ||
           (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] == 1) ||
           (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[2] == 1) ||
           (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[8] == 1))) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2_IN_AUTOMATICA;
        Modello_Arduino_2022_DW.is_AUTOMATICA = Modello_Arduino_2_IN_VETTORIALE;
      } else if (Modello_Arduino_2022_B.Switch_j == 1.0) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_Safe;
      } else if (Modello_Arduino_2022_P.Constant2_Value_i == 1.0) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Ar_IN_Intervento_Pilota;
      } else {
        Modello_Arduino_2022_B.modo = 5.0;
        Modello_Arduino_2022_B.switch_manetta = 1.0;
        Modello_Arduino_2022_B.switch_equilibratore = 1.0;
        Modello_Arduino_2022_B.switch_alettoni = 1.0;
        Modello_Arduino_2022_B.switch_timone = 1.0;
      }
      break;

     case Modello_Ar_IN_Intervento_Pilota:
      if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 1) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_MANUALE;
      } else {
        Modello_Arduino_2022_B.switch_manetta = 0.0;
        Modello_Arduino_2022_B.switch_equilibratore = 0.0;
        Modello_Arduino_2022_B.switch_alettoni = 0.0;
        Modello_Arduino_2022_B.switch_timone = 0.0;
      }
      break;

     case Modello_Arduino_2022_IN_MANUALE:
      if ((Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 == 1.0) &&
          (Modello_Arduino_2022_B.Switch_j == 0.0)) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_Go_Home;
      } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 0) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_202_IN_Stand_By;
      } else {
        Modello_Arduino_2022_B.switch_manetta = 0.0;
        Modello_Arduino_2022_B.switch_equilibratore = 0.0;
        Modello_Arduino_2022_B.switch_alettoni = 0.0;
        Modello_Arduino_2022_B.switch_timone = 0.0;
      }
      break;

     case Modello_Arduino_2022_IN_Safe:
      if (Modello_Arduino_2022_P.Constant2_Value_i == 1.0) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Ar_IN_Intervento_Pilota;
      } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 1) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_MANUALE;
      } else {
        Modello_Arduino_2022_B.switch_manetta = 1.0;
        Modello_Arduino_2022_B.switch_equilibratore = 1.0;
        Modello_Arduino_2022_B.switch_alettoni = 1.0;
        Modello_Arduino_2022_B.switch_timone = 1.0;
        Modello_Arduino_2022_B.throttle_safe = 0.1;
      }
      break;

     default:
      /* case IN_Stand_By: */
      if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] == 1) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2_IN_AUTOMATICA;
        Modello_Arduino_2022_DW.is_AUTOMATICA = Modello_Arduino_2_IN_VETTORIALE;
      } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 1) {
        Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_MANUALE;
      } else {
        Modello_Arduino_2022_B.switch_manetta = 0.0;
        Modello_Arduino_2022_B.switch_equilibratore = 0.0;
        Modello_Arduino_2022_B.switch_alettoni = 0.0;
        Modello_Arduino_2022_B.switch_timone = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S38>/ STATI' */

  /* S-Function (PWMinterrupt_elevator_v4_4): '<S9>/S-Function Builder1' */
  PWMinterrupt_elevator_v4_4_Outputs_wrapper
    (&Modello_Arduino_2022_B.PWM_elevator);

  /* Product: '<S587>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion13'
   *  Product: '<S588>/Divide'
   *  Sum: '<S587>/Sum'
   *  Sum: '<S587>/Sum1'
   */
  Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 = ((real_T)
    Modello_Arduino_2022_B.PWM_elevator - Modello_Arduino_2022_B.ManualSwitch1[3])
    / (Modello_Arduino_2022_B.ManualSwitch1[2] -
       Modello_Arduino_2022_B.ManualSwitch1[3]);

  /* Sum: '<S587>/Sum2' incorporates:
   *  Constant: '<S587>/Constant8'
   *  Constant: '<S587>/Constant9'
   *  Sum: '<S594>/Sum1'
   */
  Modello_Arduino_2022_B.Saturation_e = Modello_Arduino_2022_P.attuatore_Emax -
    Modello_Arduino_2022_P.attuatore_Emin;

  /* Sum: '<S587>/Sum3' incorporates:
   *  Constant: '<S587>/Constant9'
   *  Product: '<S587>/Divide'
   *  Product: '<S587>/Multiply'
   *  Sum: '<S587>/Sum2'
   */
  Modello_Arduino_2022_B.Sum3 = Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 *
    Modello_Arduino_2022_B.Saturation_e + Modello_Arduino_2022_P.attuatore_Emin;

  /* MATLAB Function: '<S38>/MATLAB Function' */
  if (Modello_Arduino_2022_B.modo == 3.0) {
    Modello_Arduino_2022_B.ATO = 1;
    Modello_Arduino_2022_B.caso = 0;
  } else if (Modello_Arduino_2022_B.modo == 4.0) {
    Modello_Arduino_2022_B.caso = 1;
    Modello_Arduino_2022_B.ATO = 0;
  } else {
    Modello_Arduino_2022_B.ATO = 0;
    Modello_Arduino_2022_B.caso = 0;
  }

  /* Gain: '<S588>/Gain' incorporates:
   *  Constant: '<S588>/Constant8'
   *  Constant: '<S588>/Constant9'
   *  Product: '<S588>/Multiply'
   *  Sum: '<S588>/Sum2'
   *  Sum: '<S588>/Sum3'
   */
  Modello_Arduino_2022_B.Ato_selector =
    (Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 *
     (Modello_Arduino_2022_P.theta_max - Modello_Arduino_2022_P.theta_min) +
     Modello_Arduino_2022_P.theta_min) * Modello_Arduino_2022_P.Gain_Gain_h;

  /* Saturate: '<S588>/Saturation' */
  if (Modello_Arduino_2022_B.Ato_selector > Modello_Arduino_2022_P.theta_max) {
    Modello_Arduino_2022_B.Ato_selector = Modello_Arduino_2022_P.theta_max;
  } else {
    if (Modello_Arduino_2022_B.Ato_selector < Modello_Arduino_2022_P.theta_min)
    {
      Modello_Arduino_2022_B.Ato_selector = Modello_Arduino_2022_P.theta_min;
    }
  }

  /* End of Saturate: '<S588>/Saturation' */

  /* Sum: '<S37>/Sum2' */
  Modello_Arduino_2022_B.Gain1_i = Modello_Arduino_2022_B.Ato_selector -
    Modello_Arduino_2022_B.Gain1_i;

  /* Sum: '<S351>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore beccheggio1'
   *  DiscreteIntegrator: '<S342>/Integrator'
   *  Product: '<S347>/PProd Out'
   */
  Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 = Modello_Arduino_2022_B.Gain1_i *
    Modello_Arduino_2022_P.Kp_becch + Modello_Arduino_2022_DW.Integrator_DSTATE;

  /* Saturate: '<S349>/Saturation' */
  if (Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 >
      Modello_Arduino_2022_P.attuatore_Emax) {
    Modello_Arduino_2022_B.Gain1_h = Modello_Arduino_2022_P.attuatore_Emax;
  } else if (Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0 <
             Modello_Arduino_2022_P.attuatore_Emin) {
    Modello_Arduino_2022_B.Gain1_h = Modello_Arduino_2022_P.attuatore_Emin;
  } else {
    Modello_Arduino_2022_B.Gain1_h = Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0;
  }

  /* End of Saturate: '<S349>/Saturation' */

  /* MultiPortSwitch: '<S304>/Switch Bumpless 2' */
  if ((int32_T)Modello_Arduino_2022_B.switch_equilibratore == 0) {
    Modello_Arduino_2022_B.SwitchBumpless2 = Modello_Arduino_2022_B.Sum3;
  } else {
    Modello_Arduino_2022_B.SwitchBumpless2 = Modello_Arduino_2022_B.Gain1_h;
  }

  /* End of MultiPortSwitch: '<S304>/Switch Bumpless 2' */

  /* MultiPortSwitch: '<S309>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (Modello_Arduino_2022_B.caso != 0) {
    /* Switch: '<S309>/Switch1' incorporates:
     *  Constant: '<S309>/Constant5'
     */
    if (!(Modello_Arduino_2022_B.Product1 >=
          Modello_Arduino_2022_P.Switch1_Threshold)) {
      Modello_Arduino_2022_B.SwitchBumpless2 =
        Modello_Arduino_2022_P.Constant5_Value;
    }

    /* End of Switch: '<S309>/Switch1' */
  }

  /* End of MultiPortSwitch: '<S309>/Multiport Switch2' */

  /* Logic: '<S39>/AND' */
  Ap_sel = ((Modello_Arduino_2022_B.switch_manetta != 0.0) &&
            (Modello_Arduino_2022_B.switch_equilibratore != 0.0) &&
            (Modello_Arduino_2022_B.switch_alettoni != 0.0) &&
            (Modello_Arduino_2022_B.switch_timone != 0.0));

  /* Chart: '<S39>/Chart' incorporates:
   *  Logic: '<S39>/AND'
   */
  if (Modello_Arduino_2022_DW.is_active_c21_Modello_Arduino_2 == 0U) {
    Modello_Arduino_2022_DW.is_active_c21_Modello_Arduino_2 = 1U;
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
      Modello_Arduino_2022_IN_In;
    Modello_Arduino_2022_B.Wp_selector = 0.0;
    Modello_Arduino_2022_B.Vec_selector = 0.0;
    Modello_Arduino_2022_B.Ato_selector = 0.0;
    Modello_Arduino_2022_B.Al_selector = 0.0;
    Modello_Arduino_2022_B.Go_home_selector = 0.0;
  } else {
    switch (Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022) {
     case Modello_Arduino__IN_AutoLanding:
      if ((!(Modello_Arduino_2022_B.switch_manetta != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_equilibratore != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_alettoni != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_timone != 0.0))) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_In;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 2.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2_IN_Vettoriale;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 1.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 1.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_202_IN_Waypoint;
        Modello_Arduino_2022_B.Wp_selector = 1.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 5.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_GoHome;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 1.0;
      } else {
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 1.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      }
      break;

     case Modello_Arduino__IN_AutoTakeoff:
      if ((!(Modello_Arduino_2022_B.switch_manetta != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_equilibratore != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_alettoni != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_timone != 0.0))) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_In;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 1.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_202_IN_Waypoint;
        Modello_Arduino_2022_B.Wp_selector = 1.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 2.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2_IN_Vettoriale;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 1.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else {
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 1.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      }
      break;

     case Modello_Arduino_2022_IN_GoHome:
      if ((!(Modello_Arduino_2022_B.switch_manetta != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_equilibratore != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_alettoni != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_timone != 0.0))) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_In;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else {
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 1.0;
      }
      break;

     case Modello_Arduino_2022_IN_In:
      Modello_Arduino_2022_In(&Ap_sel, &Modello_Arduino_2022_B.Go_home_selector,
        &Modello_Arduino_2022_B.Al_selector,
        &Modello_Arduino_2022_B.Ato_selector,
        &Modello_Arduino_2022_B.Vec_selector,
        &Modello_Arduino_2022_B.Wp_selector);
      break;

     case Modello_Arduino_2_IN_Vettoriale:
      if ((!(Modello_Arduino_2022_B.switch_manetta != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_equilibratore != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_alettoni != 0.0)) ||
          (!(Modello_Arduino_2022_B.switch_timone != 0.0))) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_In;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 1.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_202_IN_Waypoint;
        Modello_Arduino_2022_B.Wp_selector = 1.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else if (Modello_Arduino_2022_B.modo == 5.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino_2022_IN_GoHome;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 1.0;
      } else if (Modello_Arduino_2022_B.modo == 4.0) {
        Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 =
          Modello_Arduino__IN_AutoLanding;
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 0.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 1.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      } else {
        Modello_Arduino_2022_B.Wp_selector = 0.0;
        Modello_Arduino_2022_B.Vec_selector = 1.0;
        Modello_Arduino_2022_B.Ato_selector = 0.0;
        Modello_Arduino_2022_B.Al_selector = 0.0;
        Modello_Arduino_2022_B.Go_home_selector = 0.0;
      }
      break;

     default:
      /* case IN_Waypoint: */
      Modello_Arduino_2022_Waypoint(&Ap_sel,
        &Modello_Arduino_2022_B.Go_home_selector,
        &Modello_Arduino_2022_B.Al_selector,
        &Modello_Arduino_2022_B.Ato_selector,
        &Modello_Arduino_2022_B.Vec_selector,
        &Modello_Arduino_2022_B.Wp_selector);
      break;
    }
  }

  /* End of Chart: '<S39>/Chart' */

  /* Outputs for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' incorporates:
   *  EnablePort: '<S440>/Enable'
   */
  if (Modello_Arduino_2022_B.Ato_selector > 0.0) {
    /* Outputs for Triggered SubSystem: '<S440>/Sample and Hold' incorporates:
     *  TriggerPort: '<S448>/Trigger'
     */
    /* Memory: '<S440>/Memory' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &Modello_Arduino_2022_PrevZCX.SampleandHold_Trig_ZCE_k,
             (Modello_Arduino_2022_DW.Memory_PreviousInput_c));

    /* End of Outputs for SubSystem: '<S440>/Sample and Hold' */

    /* Outputs for Triggered SubSystem: '<S440>/Sample and Hold1' incorporates:
     *  TriggerPort: '<S449>/Trigger'
     */
    /* Memory: '<S440>/Memory1' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &Modello_Arduino_2022_PrevZCX.SampleandHold1_Trig_ZCE,
             (Modello_Arduino_2022_DW.Memory1_PreviousInput_i));

    /* End of Outputs for SubSystem: '<S440>/Sample and Hold1' */

    /* Chart: '<S440>/Chart1' incorporates:
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     */
    if (Modello_Arduino_2022_DW.temporalCounter_i1 < 255U) {
      Modello_Arduino_2022_DW.temporalCounter_i1++;
    }

    if (Modello_Arduino_2022_DW.is_active_c1_Modello_Arduino_20 == 0U) {
      Modello_Arduino_2022_DW.is_active_c1_Modello_Arduino_20 = 1U;
      Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022 =
        Modello_Arduino_2_IN_Fase_0_ATO;
    } else {
      switch (Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022) {
       case Modello_Arduino_2_IN_Fase_0_ATO:
        if (Modello_Arduino_2022_B.modo == 3.0) {
          Modello_Arduino_2022_B.psi_ref_selector = 1.0;
          Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022 =
            Modello_Arduino_2_IN_Fase_1_ATO;
          Modello_Arduino_2022_DW.temporalCounter_i1 = 0U;
        } else {
          Modello_Arduino_2022_B.Fase_ATO = 0.0;
          Modello_Arduino_2022_B.psi_ref_selector = 0.0;
          Modello_Arduino_2022_B.theta_ground_selector = 0.0;
          Modello_Arduino_2022_B.eq_rot = 0.0;
          Modello_Arduino_2022_B.Tas_ref = 0.0;
          Modello_Arduino_2022_B.h_ref = 0.0;
        }
        break;

       case Modello_Arduino_2_IN_Fase_1_ATO:
        if (Modello_Arduino_2022_DW.temporalCounter_i1 >= 250) {
          Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022 =
            Modello_Arduino_2_IN_Fase_2_ATO;
        } else {
          Modello_Arduino_2022_B.Fase_ATO = 1.0;
          Modello_Arduino_2022_B.manetta_ref = 0.1;
          Modello_Arduino_2022_B.psi_ref_selector = 0.0;
          Modello_Arduino_2022_B.h_ref = 0.0;
          Modello_Arduino_2022_B.eq_rot = 2.0;
        }
        break;

       case Modello_Arduino_2_IN_Fase_2_ATO:
        if ((Modello_Arduino_2022_B.Product1 >= 18.0) &&
            (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 >= 10.0)) {
          Modello_Arduino_2022_B.theta_ground_selector = 1.0;
          Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022 =
            Modello_Arduino_2_IN_Fase_3_ATO;
        } else {
          Modello_Arduino_2022_B.Fase_ATO = 2.0;
          Modello_Arduino_2022_B.psi_ref_selector = 0.0;
          Modello_Arduino_2022_B.h_ref = 0.0;
          Modello_Arduino_2022_B.eq_rot = 2.0;
          Modello_Arduino_2022_B.Tas_ref = 25.0;
        }
        break;

       case Modello_Arduino_2_IN_Fase_3_ATO:
        if (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] >= 2.0F) {
          Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022 =
            Modello_Arduino_2_IN_Fase_4_ATO;
        } else {
          Modello_Arduino_2022_B.Fase_ATO = 3.0;
          Modello_Arduino_2022_B.psi_ref_selector = 0.0;
          Modello_Arduino_2022_B.theta_ground_selector = 0.0;
          Modello_Arduino_2022_B.h_ref = 0.0;
          Modello_Arduino_2022_B.Tas_ref = 25.0;
        }
        break;

       default:
        /* case IN_Fase_4_ATO: */
        Modello_Arduino_2022_B.Fase_ATO = 4.0;
        Modello_Arduino_2022_B.psi_ref_selector = 0.0;
        Modello_Arduino_2022_B.h_ref = 35.0;
        Modello_Arduino_2022_B.Tas_ref = 25.0;
        break;
      }
    }

    /* End of Chart: '<S440>/Chart1' */

    /* Update for Memory: '<S440>/Memory' */
    Modello_Arduino_2022_DW.Memory_PreviousInput_c =
      Modello_Arduino_2022_B.psi_ref_selector;

    /* Update for Memory: '<S440>/Memory1' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_i =
      Modello_Arduino_2022_B.theta_ground_selector;
  }

  /* End of Outputs for SubSystem: '<S39>/DECOLLO AUTOMATICO' */

  /* MultiPortSwitch: '<S310>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (Modello_Arduino_2022_B.ATO != 0) {
    /* MultiPortSwitch: '<S310>/Multiport Switch1' incorporates:
     *  Gain: '<S359>/Gain1'
     */
    switch ((int32_T)Modello_Arduino_2022_B.Fase_ATO) {
     case 0:
      Modello_Arduino_2022_B.SwitchBumpless2 =
        Modello_Arduino_2022_P.Gain1_Gain_c * Modello_Arduino_2022_B.eq_rot;
      break;

     case 1:
      Modello_Arduino_2022_B.SwitchBumpless2 =
        Modello_Arduino_2022_P.Gain1_Gain_c * Modello_Arduino_2022_B.eq_rot;
      break;

     case 2:
      Modello_Arduino_2022_B.SwitchBumpless2 =
        Modello_Arduino_2022_P.Gain1_Gain_c * Modello_Arduino_2022_B.eq_rot;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S310>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S310>/Multiport Switch2' */

  /* MultiPortSwitch: '<S37>/Switch Bumpless 1' incorporates:
   *  Gain: '<S37>/Gain'
   */
  if ((int32_T)Modello_Arduino_2022_B.switch_equilibratore != 0) {
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
    if ((int32_T)Modello_Arduino_2022_B.switch_equilibratore == 0) {
      Modello_Arduino_2022_B.Sum3 = Modello_Arduino_2022_P.Constant1_Value_nj;
      Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_P.Constant2_Value_ar;
    } else {
      /* Abs: '<S304>/Abs1' incorporates:
       *  Abs: '<S304>/Abs'
       */
      Modello_Arduino_2022_B.a_n = fabs(Modello_Arduino_2022_B.Gain1_l);
      Modello_Arduino_2022_B.Sum3 = (Modello_Arduino_2022_B.ManualSwitch[4] -
        sin(Modello_Arduino_2022_B.a_n) * Modello_Arduino_2022_B.ManualSwitch[5])
        * Modello_Arduino_2022_P.Kp_q;
      Modello_Arduino_2022_B.a_n *= Modello_Arduino_2022_P.inv_comp_h *
        Modello_Arduino_2022_P.Kp_comp_h;
    }

    /* End of MultiPortSwitch: '<S304>/Switch 1' */

    /* Sum: '<S304>/Sum2' incorporates:
     *  Sum: '<S304>/Sum'
     */
    Modello_Arduino_2022_B.Ato_selector =
      (Modello_Arduino_2022_B.SwitchBumpless2 - Modello_Arduino_2022_B.Sum3) -
      Modello_Arduino_2022_B.a_n;

    /* Saturate: '<S304>/saturatore E2' */
    if (Modello_Arduino_2022_B.Ato_selector >
        Modello_Arduino_2022_P.attuatore_Emax) {
      Modello_Arduino_2022_B.Ato_selector =
        Modello_Arduino_2022_P.attuatore_Emax;
    } else {
      if (Modello_Arduino_2022_B.Ato_selector <
          Modello_Arduino_2022_P.attuatore_Emin) {
        Modello_Arduino_2022_B.Ato_selector =
          Modello_Arduino_2022_P.attuatore_Emin;
      }
    }

    /* End of Saturate: '<S304>/saturatore E2' */
    Modello_Arduino_2022_B.Sum3 = Modello_Arduino_2022_P.inv_E *
      Modello_Arduino_2022_B.Ato_selector;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 1' */

  /* Sum: '<S29>/Sum' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S30>/Gain'
   */
  Modello_Arduino_2022_B.PWM_aileron_p = Modello_Arduino_2022_P.Gain_Gain_od *
    Modello_Arduino_2022_B.Sum3 + Modello_Arduino_2022_P.Constant2_Value_m4;

  /* S-Function (PWMinterrupt_aileron_v4_4): '<S9>/S-Function Builder7' */
  PWMinterrupt_aileron_v4_4_Outputs_wrapper(&Modello_Arduino_2022_B.PWM_aileron);

  /* Product: '<S585>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion14'
   *  Product: '<S586>/Divide'
   *  Sum: '<S585>/Sum'
   *  Sum: '<S585>/Sum1'
   */
  Modello_Arduino_2022_B.Ato_selector = ((real_T)
    Modello_Arduino_2022_B.PWM_aileron - Modello_Arduino_2022_B.ManualSwitch1[5])
    / (Modello_Arduino_2022_B.ManualSwitch1[4] -
       Modello_Arduino_2022_B.ManualSwitch1[5]);

  /* Sum: '<S585>/Sum2' incorporates:
   *  Constant: '<S585>/Constant8'
   *  Constant: '<S585>/Constant9'
   *  Sum: '<S591>/Sum1'
   */
  Modello_Arduino_2022_B.rtb_Sum3_b_tmp = Modello_Arduino_2022_P.attuatore_Amax
    - Modello_Arduino_2022_P.attuatore_Amin;

  /* Sum: '<S585>/Sum3' incorporates:
   *  Constant: '<S585>/Constant9'
   *  Product: '<S585>/Divide'
   *  Product: '<S585>/Multiply'
   *  Sum: '<S585>/Sum2'
   */
  Modello_Arduino_2022_B.Sum3_b = Modello_Arduino_2022_B.Ato_selector *
    Modello_Arduino_2022_B.rtb_Sum3_b_tmp +
    Modello_Arduino_2022_P.attuatore_Amin;

  /* Gain: '<S586>/Gain' incorporates:
   *  Constant: '<S586>/Constant8'
   *  Constant: '<S586>/Constant9'
   *  Product: '<S586>/Multiply'
   *  Sum: '<S586>/Sum2'
   *  Sum: '<S586>/Sum3'
   */
  Modello_Arduino_2022_B.Ato_selector = (Modello_Arduino_2022_B.Ato_selector *
    (Modello_Arduino_2022_P.phi_max - Modello_Arduino_2022_P.phi_min) +
    Modello_Arduino_2022_P.phi_min) * Modello_Arduino_2022_P.Gain_Gain_av;

  /* Saturate: '<S586>/Saturation' */
  if (Modello_Arduino_2022_B.Ato_selector > Modello_Arduino_2022_P.phi_max) {
    Modello_Arduino_2022_B.Ato_selector = Modello_Arduino_2022_P.phi_max;
  } else {
    if (Modello_Arduino_2022_B.Ato_selector < Modello_Arduino_2022_P.phi_min) {
      Modello_Arduino_2022_B.Ato_selector = Modello_Arduino_2022_P.phi_min;
    }
  }

  /* End of Saturate: '<S586>/Saturation' */

  /* Sum: '<S37>/Sum5' */
  Modello_Arduino_2022_B.Gain1_l = Modello_Arduino_2022_B.Ato_selector -
    Modello_Arduino_2022_B.Gain1_l;

  /* Sum: '<S305>/Sum' incorporates:
   *  Constant: '<S305>/Constant3'
   */
  Modello_Arduino_2022_B.Ato_selector = Modello_Arduino_2022_B.Fase_ATO -
    Modello_Arduino_2022_P.Constant3_Value_m;

  /* DiscreteIntegrator: '<S392>/Integrator' */
  if ((Modello_Arduino_2022_B.Ato_selector > 0.0) &&
      (Modello_Arduino_2022_DW.Integrator_PrevResetState <= 0)) {
    Modello_Arduino_2022_DW.Integrator_DSTATE_n =
      Modello_Arduino_2022_P.PIDController_InitialConditio_c;
  }

  /* Sum: '<S401>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore  rollio3'
   *  DiscreteIntegrator: '<S392>/Integrator'
   *  Product: '<S397>/PProd Out'
   */
  Modello_Arduino_2022_B.Sum_nh = Modello_Arduino_2022_B.Gain1_l *
    Modello_Arduino_2022_P.Kp_roll + Modello_Arduino_2022_DW.Integrator_DSTATE_n;

  /* Saturate: '<S399>/Saturation' */
  if (Modello_Arduino_2022_B.Sum_nh > Modello_Arduino_2022_P.attuatore_Amax) {
    Modello_Arduino_2022_B.Saturation_a = Modello_Arduino_2022_P.attuatore_Amax;
  } else if (Modello_Arduino_2022_B.Sum_nh <
             Modello_Arduino_2022_P.attuatore_Amin) {
    Modello_Arduino_2022_B.Saturation_a = Modello_Arduino_2022_P.attuatore_Amin;
  } else {
    Modello_Arduino_2022_B.Saturation_a = Modello_Arduino_2022_B.Sum_nh;
  }

  /* End of Saturate: '<S399>/Saturation' */

  /* MultiPortSwitch: '<S305>/Switch Bumpless 1' incorporates:
   *  Constant: '<S305>/Constant1'
   *  Constant: '<S8>/Kp controllore  velocità rollio3'
   *  Product: '<S305>/Product3'
   */
  if ((int32_T)Modello_Arduino_2022_B.switch_alettoni == 0) {
    Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_P.Constant1_Value_ig;
  } else {
    Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.ManualSwitch[3] *
      Modello_Arduino_2022_P.Kp_p;
  }

  /* End of MultiPortSwitch: '<S305>/Switch Bumpless 1' */

  /* Sum: '<S305>/Sum2' */
  Modello_Arduino_2022_B.Sum2_c = Modello_Arduino_2022_B.Saturation_a -
    Modello_Arduino_2022_B.a_n;

  /* MultiPortSwitch: '<S37>/Switch Bumpless 3' incorporates:
   *  Saturate: '<S37>/saturatore A1'
   */
  if ((int32_T)Modello_Arduino_2022_B.switch_alettoni == 0) {
    Modello_Arduino_2022_B.SignPreSat = Modello_Arduino_2022_B.Sum3_b;
  } else if (Modello_Arduino_2022_B.Sum2_c >
             Modello_Arduino_2022_P.attuatore_Amax) {
    /* Saturate: '<S37>/saturatore A1' */
    Modello_Arduino_2022_B.SignPreSat = Modello_Arduino_2022_P.attuatore_Amax;
  } else if (Modello_Arduino_2022_B.Sum2_c <
             Modello_Arduino_2022_P.attuatore_Amin) {
    /* Saturate: '<S37>/saturatore A1' */
    Modello_Arduino_2022_B.SignPreSat = Modello_Arduino_2022_P.attuatore_Amin;
  } else {
    /* Saturate: '<S37>/saturatore A1' */
    Modello_Arduino_2022_B.SignPreSat = Modello_Arduino_2022_B.Sum2_c;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 3' */

  /* Saturate: '<S37>/saturatore A' */
  if (Modello_Arduino_2022_B.SignPreSat > Modello_Arduino_2022_P.attuatore_Amax)
  {
    Modello_Arduino_2022_B.Alettoni = Modello_Arduino_2022_P.attuatore_Amax;
  } else if (Modello_Arduino_2022_B.SignPreSat <
             Modello_Arduino_2022_P.attuatore_Amin) {
    Modello_Arduino_2022_B.Alettoni = Modello_Arduino_2022_P.attuatore_Amin;
  } else {
    Modello_Arduino_2022_B.Alettoni = Modello_Arduino_2022_B.SignPreSat;
  }

  /* End of Saturate: '<S37>/saturatore A' */

  /* MultiPortSwitch: '<S37>/Switch Bumpless 5' incorporates:
   *  Gain: '<S37>/Gain1'
   */
  if ((int32_T)Modello_Arduino_2022_B.switch_alettoni == 0) {
    Modello_Arduino_2022_B.SignPreSat = Modello_Arduino_2022_B.Sum3_b;
  } else {
    Modello_Arduino_2022_B.SignPreSat = Modello_Arduino_2022_P.inv_A *
      Modello_Arduino_2022_B.Alettoni;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 5' */

  /* Sum: '<S29>/Sum1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S31>/Gain'
   */
  Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Gain_Gain_if *
    Modello_Arduino_2022_B.SignPreSat +
    Modello_Arduino_2022_P.Constant2_Value_m4;

  /* S-Function (PWMinterrupt_rudder_v4_4): '<S9>/S-Function Builder8' */
  PWMinterrupt_rudder_v4_4_Outputs_wrapper(&Modello_Arduino_2022_B.PWM_rudder);

  /* DiscreteTransferFcn: '<S306>/Discrete Washout Filter' */
  Modello_Arduino_2022_B.Sum3_b = (Modello_Arduino_2022_B.ManualSwitch[5] -
    Modello_Arduino_2022_P.DiscreteWashoutFilter_DenCoef[1] *
    Modello_Arduino_2022_DW.DiscreteWashoutFilter_states) /
    Modello_Arduino_2022_P.DiscreteWashoutFilter_DenCoef[0];

  /* MultiPortSwitch: '<S37>/Switch Bumpless 6' incorporates:
   *  Constant: '<S589>/Constant8'
   *  Constant: '<S589>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion15'
   *  Gain: '<S37>/Gain2'
   *  MultiPortSwitch: '<S37>/Switch Bumpless 4'
   *  Product: '<S589>/Divide'
   *  Product: '<S589>/Multiply'
   *  Sum: '<S589>/Sum1'
   *  Sum: '<S589>/Sum2'
   *  Sum: '<S589>/Sum3'
   *  Sum: '<S589>/Sum4'
   */
  if ((int32_T)Modello_Arduino_2022_B.switch_timone == 0) {
    Modello_Arduino_2022_B.Sum2_c = ((real_T)Modello_Arduino_2022_B.PWM_rudder -
      Modello_Arduino_2022_B.ManualSwitch1[7]) /
      (Modello_Arduino_2022_B.ManualSwitch1[6] -
       Modello_Arduino_2022_B.ManualSwitch1[7]) *
      (Modello_Arduino_2022_P.attuatore_Rmax -
       Modello_Arduino_2022_P.attuatore_Rmin) +
      Modello_Arduino_2022_P.attuatore_Rmin;
  } else {
    if ((int32_T)Modello_Arduino_2022_B.switch_timone == 0) {
      /* MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
       *  Constant: '<S589>/Constant8'
       *  Constant: '<S589>/Constant9'
       *  DataTypeConversion: '<S9>/Data Type Conversion15'
       *  Product: '<S589>/Divide'
       *  Product: '<S589>/Multiply'
       *  Sum: '<S589>/Sum1'
       *  Sum: '<S589>/Sum2'
       *  Sum: '<S589>/Sum3'
       *  Sum: '<S589>/Sum4'
       */
      Modello_Arduino_2022_B.Sum2_c = ((real_T)Modello_Arduino_2022_B.PWM_rudder
        - Modello_Arduino_2022_B.ManualSwitch1[7]) /
        (Modello_Arduino_2022_B.ManualSwitch1[6] -
         Modello_Arduino_2022_B.ManualSwitch1[7]) *
        (Modello_Arduino_2022_P.attuatore_Rmax -
         Modello_Arduino_2022_P.attuatore_Rmin) +
        Modello_Arduino_2022_P.attuatore_Rmin;
    } else {
      /* MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
       *  Constant: '<S37>/r_rif'
       *  Constant: '<S8>/K controllo imbardata inversa'
       *  Constant: '<S8>/Kp controllore imbardata'
       *  DiscreteTransferFcn: '<S306>/Discrete Washout Filter'
       *  Gain: '<S8>/Gain3'
       *  Product: '<S37>/  CONTROLLO     IMBARDATA      INVERSA'
       *  Product: '<S37>/Product'
       *  Sum: '<S37>/Sum1'
       *  Sum: '<S37>/Sum9'
       */
      Modello_Arduino_2022_B.Sum2_c = (Modello_Arduino_2022_P.r_rif_Value -
        (Modello_Arduino_2022_P.DiscreteWashoutFilter_NumCoef[0] *
         Modello_Arduino_2022_B.Sum3_b +
         Modello_Arduino_2022_P.DiscreteWashoutFilter_NumCoef[1] *
         Modello_Arduino_2022_DW.DiscreteWashoutFilter_states)) *
        Modello_Arduino_2022_P.Kp_imb + (real_T)
        (Modello_Arduino_2022_P.Gain3_Gain_o * Modello_Arduino_2022_P.K_imb_inv)
        * 0.0078125 * Modello_Arduino_2022_B.Sum2_c;
    }

    /* Saturate: '<S37>/saturatore R' */
    if (Modello_Arduino_2022_B.Sum2_c > Modello_Arduino_2022_P.attuatore_Rmax) {
      Modello_Arduino_2022_B.Sum2_c = Modello_Arduino_2022_P.attuatore_Rmax;
    } else {
      if (Modello_Arduino_2022_B.Sum2_c < Modello_Arduino_2022_P.attuatore_Rmin)
      {
        Modello_Arduino_2022_B.Sum2_c = Modello_Arduino_2022_P.attuatore_Rmin;
      }
    }

    /* End of Saturate: '<S37>/saturatore R' */
    Modello_Arduino_2022_B.Sum2_c *= Modello_Arduino_2022_P.inv_R;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 6' */

  /* Sum: '<S29>/Sum2' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  Modello_Arduino_2022_B.Integrator_e = Modello_Arduino_2022_P.Gain_Gain_bh *
    Modello_Arduino_2022_B.Sum2_c + Modello_Arduino_2022_P.Constant2_Value_m4;

  /* Gain: '<S20>/Gain' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion3'
   *  Gain: '<S556>/Gain4'
   */
  Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_P.Gain4_Gain *
    (real_T)Modello_Arduino_2022_B.ByteUnpack_o4[1] *
    Modello_Arduino_2022_P.Gain_Gain_jr;

  /* Saturate: '<S20>/Saturation' */
  if (Modello_Arduino_2022_B.deltafalllimit >
      Modello_Arduino_2022_P.Saturation_UpperSat) {
    Modello_Arduino_2022_B.deltafalllimit =
      Modello_Arduino_2022_P.Saturation_UpperSat;
  } else {
    if (Modello_Arduino_2022_B.deltafalllimit <
        Modello_Arduino_2022_P.Saturation_LowerSat) {
      Modello_Arduino_2022_B.deltafalllimit =
        Modello_Arduino_2022_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (Modello_Arduino_2022_P.Constant_Value_bh < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_P.Constant_Value_bh);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant_Value_bh);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[0] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.Switch_i < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Switch_i);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Switch_i);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[1] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.PWM_aileron_p < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.PWM_aileron_p);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.PWM_aileron_p);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[2] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.Abs1 < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Abs1);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Abs1);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[3] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.Integrator_e < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.Integrator_e);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Integrator_e);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[4] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (Modello_Arduino_2022_P.Constant1_Value_pa[0] < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_P.Constant1_Value_pa
      [0]);
  } else {
    Modello_Arduino_2022_B.a_n = floor
      (Modello_Arduino_2022_P.Constant1_Value_pa[0]);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[5] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (Modello_Arduino_2022_P.Constant1_Value_pa[1] < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_P.Constant1_Value_pa
      [1]);
  } else {
    Modello_Arduino_2022_B.a_n = floor
      (Modello_Arduino_2022_P.Constant1_Value_pa[1]);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[6] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (Modello_Arduino_2022_P.Constant1_Value_pa[2] < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_P.Constant1_Value_pa
      [2]);
  } else {
    Modello_Arduino_2022_B.a_n = floor
      (Modello_Arduino_2022_P.Constant1_Value_pa[2]);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[7] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (Modello_Arduino_2022_B.deltafalllimit < 0.0) {
    Modello_Arduino_2022_B.a_n = ceil(Modello_Arduino_2022_B.deltafalllimit);
  } else {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.deltafalllimit);
  }

  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  Modello_Arduino_2022_B.Heading[8] = (uint16_T)(Modello_Arduino_2022_B.a_n <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n :
    (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* Memory: '<S2>/Memory' */
  Modello_Arduino_2022_B.Memory_a =
    Modello_Arduino_2022_DW.Memory_PreviousInput_n;

  /* MATLAB Function: '<S569>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S569>/Data Type Conversion'
   *  DataTypeConversion: '<S569>/Data Type Conversion2'
   */
  if (Modello_Arduino_2022_B.SFunction_o14 == 1) {
    Modello_Arduino_2022_DW.P_ref = Modello_Arduino_2022_B.SFunctionBuilder1;
  }

  if (Modello_Arduino_2022_B.SFunction_o16 == 1) {
    Modello_Arduino_2022_DW.P_ref = Modello_Arduino_2022_B.SFunction_o17;
    Modello_Arduino_2022_DW.rl_up = 20.0;
    Modello_Arduino_2022_DW.rl_dw = -20.0;
  }

  /* Product: '<S572>/delta rise limit' incorporates:
   *  MATLAB Function: '<S569>/MATLAB Function'
   *  SampleTimeMath: '<S572>/sample time'
   *
   * About '<S572>/sample time':
   *  y = K where K = ( w * Ts )
   */
  Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_DW.rl_up *
    Modello_Arduino_2022_P.sampletime_WtEt;

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
  Modello_Arduino_2022_B.Integrator_e = Modello_Arduino_2022_DW.P_ref -
    Modello_Arduino_2022_DW.DelayInput2_DSTATE;

  /* Switch: '<S578>/Switch2' incorporates:
   *  RelationalOperator: '<S578>/LowerRelop1'
   */
  if (!(Modello_Arduino_2022_B.Integrator_e >
        Modello_Arduino_2022_B.deltafalllimit)) {
    /* Product: '<S572>/delta fall limit' incorporates:
     *  MATLAB Function: '<S569>/MATLAB Function'
     *  SampleTimeMath: '<S572>/sample time'
     *
     * About '<S572>/sample time':
     *  y = K where K = ( w * Ts )
     */
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_DW.rl_dw *
      Modello_Arduino_2022_P.sampletime_WtEt;

    /* Switch: '<S578>/Switch' incorporates:
     *  RelationalOperator: '<S578>/UpperRelop'
     */
    if (!(Modello_Arduino_2022_B.Integrator_e <
          Modello_Arduino_2022_B.deltafalllimit)) {
      Modello_Arduino_2022_B.deltafalllimit =
        Modello_Arduino_2022_B.Integrator_e;
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
  Modello_Arduino_2022_DW.DelayInput2_DSTATE +=
    Modello_Arduino_2022_B.deltafalllimit;

  /* ManualSwitch: '<S7>/Manual Switch4' */
  if (Modello_Arduino_2022_P.ManualSwitch4_CurrentSetting == 1) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  Constant: '<S7>/Constant3'
     */
    Modello_Arduino_2022_B.DataTypeConversion2 = (real32_T)
      Modello_Arduino_2022_P.Constant3_Value_l;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  UnitDelay: '<S572>/Delay Input2'
     *
     * Block description for '<S572>/Delay Input2':
     *
     *  Store in Global RAM
     */
    Modello_Arduino_2022_B.DataTypeConversion2 = (real32_T)
      Modello_Arduino_2022_DW.DelayInput2_DSTATE;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch4' */

  /* Outputs for Enabled SubSystem: '<S577>/Subsystem1' incorporates:
   *  EnablePort: '<S579>/Enable'
   */
  if (Modello_Arduino_2022_B.SFunction_o14 > 0) {
    /* Inport: '<S579>/T' */
    Modello_Arduino_2022_B.T = Modello_Arduino_2022_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S577>/Subsystem1' */

  /* Switch: '<S577>/Switch1' incorporates:
   *  Constant: '<S577>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  RelationalOperator: '<S577>/NotEqual'
   *  Switch: '<S577>/Switch'
   */
  if (Modello_Arduino_2022_P.Constant_Value_hx !=
      Modello_Arduino_2022_DW.riferimenti[12]) {
    Modello_Arduino_2022_B.Switch1_gg = Modello_Arduino_2022_DW.riferimenti[12];
  } else if (Modello_Arduino_2022_B.T >
             Modello_Arduino_2022_P.Switch_Threshold_p) {
    /* Switch: '<S577>/Switch' */
    Modello_Arduino_2022_B.Switch1_gg = Modello_Arduino_2022_B.T;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = Modello_Arduino_2022_DW.riferimenti[12];
  }

  /* End of Switch: '<S577>/Switch1' */

  /* ManualSwitch: '<S7>/Manual Switch7' */
  if (Modello_Arduino_2022_P.ManualSwitch7_CurrentSetting == 1) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Constant: '<S7>/Constant6'
     */
    Modello_Arduino_2022_B.DataTypeConversion1_j = (real32_T)
      Modello_Arduino_2022_P.Constant6_Value_l;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Modello_Arduino_2022_B.DataTypeConversion1_j =
      Modello_Arduino_2022_B.Switch1_gg;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch7' */

  /* ManualSwitch: '<S7>/Manual Switch5' incorporates:
   *  Constant: '<S7>/Constant4'
   *  DataTypeConversion: '<S569>/Data Type Conversion'
   */
  if (Modello_Arduino_2022_P.ManualSwitch5_CurrentSetting == 1) {
    Modello_Arduino_2022_B.deltafalllimit =
      Modello_Arduino_2022_P.Constant4_Value_j;
  } else {
    Modello_Arduino_2022_B.deltafalllimit =
      Modello_Arduino_2022_B.SFunctionBuilder1;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch5' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Gain: '<S2>/Pa to hPa'
   */
  Modello_Arduino_2022_B.DataTypeConversion_l = (real32_T)
    (Modello_Arduino_2022_P.PatohPa_Gain * Modello_Arduino_2022_B.deltafalllimit);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion2'
   *  Gain: '<S2>/Pa to hPa1'
   *  Gain: '<S556>/Gain1'
   *  Gain: '<S556>/Gain7'
   */
  Modello_Arduino_2022_B.DataTypeConversion1_g = (real32_T)
    (Modello_Arduino_2022_P.Gain1_Gain_p * (real_T)
     Modello_Arduino_2022_B.ByteUnpack_o3[2] * Modello_Arduino_2022_P.Gain7_Gain
     * Modello_Arduino_2022_P.PatohPa1_Gain);

  /* ManualSwitch: '<S7>/Manual Switch6' incorporates:
   *  Constant: '<S7>/Constant5'
   */
  if (Modello_Arduino_2022_P.ManualSwitch6_CurrentSetting == 1) {
    Modello_Arduino_2022_B.Integrator_e =
      Modello_Arduino_2022_P.Constant5_Value_p;
  } else {
    Modello_Arduino_2022_B.Integrator_e =
      Modello_Arduino_2022_B.SFunctionBuilder_o1;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch6' */

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Integrator_e);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  Modello_Arduino_2022_B.DataTypeConversion2_m = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem1' incorporates:
   *  EnablePort: '<S442>/Enable'
   */
  if (Modello_Arduino_2022_B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S442>/Data Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 42;
         Modello_Arduino_2022_B.i++) {
      Modello_Arduino_2022_B.DataTypeConversion4_m[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_DW.WP_dbP_AL[Modello_Arduino_2022_B.i];
    }

    /* End of DataTypeConversion: '<S442>/Data Type Conversion4' */

    /* MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES' incorporates:
     *  DataTypeConversion: '<S442>/Data Type Conversion4'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 =
      Modello_Arduino_2022_B.DataTypeConversion4_m[30] * 0.017453292519943295;
    Modello_Arduino_2022_B.h_Home =
      Modello_Arduino_2022_B.DataTypeConversion4_m[36];
    Modello_Arduino_2022_B.a_n = cos
      (Modello_Arduino_2022_B.DataTypeConversion4_m[25] * 0.017453292519943295);
    Modello_Arduino_2022_B.Switch_i = sin
      (Modello_Arduino_2022_B.DataTypeConversion4_m[24] * 0.017453292519943295);
    Modello_Arduino_2022_B.Abs1 = cos
      (Modello_Arduino_2022_B.DataTypeConversion4_m[24] * 0.017453292519943295);
    Modello_Arduino_2022_B.Al_selector =
      Modello_Arduino_2022_B.DataTypeConversion4_m[31] * 0.017453292519943295 -
      Modello_Arduino_2022_B.DataTypeConversion4_m[30] * 0.017453292519943295;
    Modello_Arduino_2022_B.Al_selector = rt_atan2d_snf(sin
      (Modello_Arduino_2022_B.Al_selector) * Modello_Arduino_2022_B.a_n, sin
      (Modello_Arduino_2022_B.DataTypeConversion4_m[25] * 0.017453292519943295) *
      Modello_Arduino_2022_B.Abs1 - cos(Modello_Arduino_2022_B.Al_selector) *
      (Modello_Arduino_2022_B.Switch_i * Modello_Arduino_2022_B.a_n));
    if (Modello_Arduino_2022_B.Al_selector < 0.0) {
      Modello_Arduino_2022_B.Al_selector = 6.2831853071795862 - fabs
        (Modello_Arduino_2022_B.Al_selector);
    }

    /* MATLAB Function: '<S455>/MATLAB Function' incorporates:
     *  Constant: '<S455>/distance waypoints virtuale'
     *  MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES'
     *  Trigonometry: '<S526>/SinCos'
     */
    Modello_Arduino_2022_B.PWM_aileron_p = sin
      (Modello_Arduino_2022_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    Modello_Arduino_2022_B.Sum_ci = cos
      (Modello_Arduino_2022_P.distancewaypointsvirtuale_Value[0] / 6.378137E+6);
    Modello_Arduino_2022_B.a_n = cos(Modello_Arduino_2022_B.Al_selector);
    Modello_Arduino_2022_B.Gain_fd = asin(Modello_Arduino_2022_B.Abs1 *
      Modello_Arduino_2022_B.PWM_aileron_p * Modello_Arduino_2022_B.a_n +
      Modello_Arduino_2022_B.Switch_i * Modello_Arduino_2022_B.Sum_ci);
    Modello_Arduino_2022_B.Al_selector = sin(Modello_Arduino_2022_B.Al_selector);

    /* MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S455>/alt waypoint virtuale'
     *  Gain: '<S471>/Gain'
     *  Gain: '<S472>/Gain'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Modello_Arduino_2022_B.WP_param_c[12] = Modello_Arduino_2022_P.Gain_Gain_f *
      Modello_Arduino_2022_B.Gain_fd;
    Modello_Arduino_2022_B.WP_param_c[15] = Modello_Arduino_2022_P.Gain_Gain_a *
      (rt_atan2d_snf(Modello_Arduino_2022_B.Al_selector *
                     Modello_Arduino_2022_B.PWM_aileron_p *
                     Modello_Arduino_2022_B.Abs1, Modello_Arduino_2022_B.Sum_ci
                     - Modello_Arduino_2022_B.Switch_i * sin
                     (Modello_Arduino_2022_B.Gain_fd)) +
       Modello_Arduino_2022_B.rtb_Gain1_d_idx_0);
    Modello_Arduino_2022_B.WP_param_c[3] = 1.0;
    Modello_Arduino_2022_B.WP_param_c[6] = 0.0;
    Modello_Arduino_2022_B.WP_param_c[9] = 0.0;
    Modello_Arduino_2022_B.WP_param_c[18] = Modello_Arduino_2022_B.h_Home +
      Modello_Arduino_2022_P.altwaypointvirtuale_Value[0];

    /* MATLAB Function: '<S455>/MATLAB Function' incorporates:
     *  Constant: '<S455>/distance waypoints virtuale'
     */
    Modello_Arduino_2022_B.PWM_aileron_p = sin
      (Modello_Arduino_2022_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    Modello_Arduino_2022_B.Sum_ci = cos
      (Modello_Arduino_2022_P.distancewaypointsvirtuale_Value[1] / 6.378137E+6);
    Modello_Arduino_2022_B.Gain_fd = asin(Modello_Arduino_2022_B.Abs1 *
      Modello_Arduino_2022_B.PWM_aileron_p * Modello_Arduino_2022_B.a_n +
      Modello_Arduino_2022_B.Switch_i * Modello_Arduino_2022_B.Sum_ci);

    /* MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S455>/Constant1'
     *  Constant: '<S455>/alt waypoint virtuale'
     *  Gain: '<S471>/Gain'
     *  Gain: '<S472>/Gain'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Modello_Arduino_2022_B.WP_param_c[13] = Modello_Arduino_2022_P.Gain_Gain_f *
      Modello_Arduino_2022_B.Gain_fd;
    Modello_Arduino_2022_B.WP_param_c[16] = Modello_Arduino_2022_P.Gain_Gain_a *
      (rt_atan2d_snf(Modello_Arduino_2022_B.Al_selector *
                     Modello_Arduino_2022_B.PWM_aileron_p *
                     Modello_Arduino_2022_B.Abs1, Modello_Arduino_2022_B.Sum_ci
                     - Modello_Arduino_2022_B.Switch_i * sin
                     (Modello_Arduino_2022_B.Gain_fd)) +
       Modello_Arduino_2022_B.rtb_Gain1_d_idx_0);
    Modello_Arduino_2022_B.WP_param_c[1] = Modello_Arduino_2022_P.vel_wp2_al;
    Modello_Arduino_2022_B.WP_param_c[4] = 1.0;
    Modello_Arduino_2022_B.WP_param_c[7] = 0.0;
    Modello_Arduino_2022_B.WP_param_c[10] = 0.0;
    Modello_Arduino_2022_B.WP_param_c[19] = Modello_Arduino_2022_B.h_Home +
      Modello_Arduino_2022_P.altwaypointvirtuale_Value[1];

    /* MATLAB Function: '<S455>/MATLAB Function' incorporates:
     *  Constant: '<S455>/distance waypoints virtuale'
     */
    Modello_Arduino_2022_B.PWM_aileron_p = sin
      (Modello_Arduino_2022_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    Modello_Arduino_2022_B.Sum_ci = cos
      (Modello_Arduino_2022_P.distancewaypointsvirtuale_Value[2] / 6.378137E+6);
    Modello_Arduino_2022_B.Gain_fd = asin(Modello_Arduino_2022_B.Abs1 *
      Modello_Arduino_2022_B.PWM_aileron_p * Modello_Arduino_2022_B.a_n +
      Modello_Arduino_2022_B.Switch_i * Modello_Arduino_2022_B.Sum_ci);

    /* MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S455>/Constant'
     *  Constant: '<S455>/Constant1'
     *  Constant: '<S455>/alt waypoint virtuale'
     *  Gain: '<S471>/Gain'
     *  Gain: '<S472>/Gain'
     *  MATLAB Function: '<S455>/MATLAB Function'
     */
    Modello_Arduino_2022_B.WP_param_c[14] = Modello_Arduino_2022_P.Gain_Gain_f *
      Modello_Arduino_2022_B.Gain_fd;
    Modello_Arduino_2022_B.WP_param_c[17] = Modello_Arduino_2022_P.Gain_Gain_a *
      (rt_atan2d_snf(Modello_Arduino_2022_B.Al_selector *
                     Modello_Arduino_2022_B.PWM_aileron_p *
                     Modello_Arduino_2022_B.Abs1, Modello_Arduino_2022_B.Sum_ci
                     - Modello_Arduino_2022_B.Switch_i * sin
                     (Modello_Arduino_2022_B.Gain_fd)) +
       Modello_Arduino_2022_B.rtb_Gain1_d_idx_0);
    Modello_Arduino_2022_B.WP_param_c[2] = Modello_Arduino_2022_P.vel_wp2_al;
    Modello_Arduino_2022_B.WP_param_c[8] = 0.0;
    Modello_Arduino_2022_B.WP_param_c[11] = 0.0;
    Modello_Arduino_2022_B.WP_param_c[20] = Modello_Arduino_2022_B.h_Home +
      Modello_Arduino_2022_P.altwaypointvirtuale_Value[2];
    Modello_Arduino_2022_B.WP_param_c[0] = Modello_Arduino_2022_P.vel_wp1_al;
    Modello_Arduino_2022_B.WP_param_c[5] = 0.0;

    /* Gain: '<S460>/Gain' incorporates:
     *  DataTypeConversion: '<S442>/Data Type Conversion4'
     *  MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES'
     */
    Modello_Arduino_2022_B.Gain = Modello_Arduino_2022_B.DataTypeConversion4_m
      [24] * 0.017453292519943295 * Modello_Arduino_2022_P.Gain_Gain_fy;

    /* Switch: '<S536>/Switch' incorporates:
     *  Abs: '<S536>/Abs'
     *  Bias: '<S536>/Bias'
     *  Bias: '<S536>/Bias1'
     *  Constant: '<S536>/Constant2'
     *  Constant: '<S537>/Constant'
     *  Math: '<S536>/Math Function1'
     *  RelationalOperator: '<S537>/Compare'
     */
    if (fabs(Modello_Arduino_2022_B.Gain) >
        Modello_Arduino_2022_P.CompareToConstant_const) {
      Modello_Arduino_2022_B.Switch_i = rt_modd_snf(Modello_Arduino_2022_B.Gain
        + Modello_Arduino_2022_P.Bias_Bias_a3,
        Modello_Arduino_2022_P.Constant2_Value_b) +
        Modello_Arduino_2022_P.Bias1_Bias_a;
    } else {
      Modello_Arduino_2022_B.Switch_i = Modello_Arduino_2022_B.Gain;
    }

    /* End of Switch: '<S536>/Switch' */

    /* Abs: '<S533>/Abs1' */
    Modello_Arduino_2022_B.Abs1 = fabs(Modello_Arduino_2022_B.Switch_i);

    /* RelationalOperator: '<S535>/Compare' incorporates:
     *  Constant: '<S535>/Constant'
     */
    Ap_sel = (Modello_Arduino_2022_B.Abs1 >
              Modello_Arduino_2022_P.CompareToConstant_const_k);

    /* Gain: '<S461>/Gain' */
    Modello_Arduino_2022_B.Gain_h = Modello_Arduino_2022_P.Gain_Gain_la *
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0;

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
      if (Modello_Arduino_2022_B.Switch_i < 0.0) {
        Modello_Arduino_2022_B.Switch_i = -1.0;
      } else if (Modello_Arduino_2022_B.Switch_i > 0.0) {
        Modello_Arduino_2022_B.Switch_i = 1.0;
      } else if (Modello_Arduino_2022_B.Switch_i == 0.0) {
        Modello_Arduino_2022_B.Switch_i = 0.0;
      } else {
        Modello_Arduino_2022_B.Switch_i = (rtNaN);
      }

      /* End of Signum: '<S533>/Sign1' */
      Modello_Arduino_2022_B.Switch_i *= (Modello_Arduino_2022_B.Abs1 +
        Modello_Arduino_2022_P.Bias_Bias_p) * Modello_Arduino_2022_P.Gain_Gain_j
        + Modello_Arduino_2022_P.Bias1_Bias_ip;
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 =
        Modello_Arduino_2022_P.Constant_Value_m;
    } else {
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 =
        Modello_Arduino_2022_P.Constant1_Value_p;
    }

    /* End of Switch: '<S533>/Switch' */

    /* Sum: '<S525>/Sum' */
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 += Modello_Arduino_2022_B.Gain_h;

    /* Switch: '<S534>/Switch' incorporates:
     *  Abs: '<S534>/Abs'
     *  Bias: '<S534>/Bias'
     *  Bias: '<S534>/Bias1'
     *  Constant: '<S534>/Constant2'
     *  Constant: '<S538>/Constant'
     *  Math: '<S534>/Math Function1'
     *  RelationalOperator: '<S538>/Compare'
     */
    if (fabs(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0) >
        Modello_Arduino_2022_P.CompareToConstant_const_m) {
      Modello_Arduino_2022_B.Sum_ax = rt_modd_snf
        (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 +
         Modello_Arduino_2022_P.Bias_Bias_g,
         Modello_Arduino_2022_P.Constant2_Value_e) +
        Modello_Arduino_2022_P.Bias1_Bias_b;
    } else {
      Modello_Arduino_2022_B.Sum_ax = Modello_Arduino_2022_B.rtb_Gain1_d_idx_0;
    }

    /* End of Switch: '<S534>/Switch' */

    /* Sum: '<S459>/Sum1' incorporates:
     *  Gain: '<S462>/Gain'
     *  Gain: '<S463>/Gain'
     */
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 =
      Modello_Arduino_2022_P.Gain_Gain_d * Modello_Arduino_2022_B.Gain1_nb -
      Modello_Arduino_2022_B.Switch_i;
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Gain_Gain_l *
      Modello_Arduino_2022_B.Gain1_m - Modello_Arduino_2022_B.Sum_ax;

    /* Switch: '<S530>/Switch' incorporates:
     *  Abs: '<S530>/Abs'
     *  Bias: '<S530>/Bias'
     *  Bias: '<S530>/Bias1'
     *  Constant: '<S530>/Constant2'
     *  Constant: '<S531>/Constant'
     *  Math: '<S530>/Math Function1'
     *  RelationalOperator: '<S531>/Compare'
     */
    if (fabs(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0) >
        Modello_Arduino_2022_P.CompareToConstant_const_ky) {
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = rt_modd_snf
        (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 +
         Modello_Arduino_2022_P.Bias_Bias_o,
         Modello_Arduino_2022_P.Constant2_Value_p) +
        Modello_Arduino_2022_P.Bias1_Bias_g;
    }

    /* End of Switch: '<S530>/Switch' */

    /* Abs: '<S527>/Abs1' */
    Modello_Arduino_2022_B.PWM_aileron_p = fabs
      (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0);

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
    if (Modello_Arduino_2022_B.PWM_aileron_p >
        Modello_Arduino_2022_P.CompareToConstant_const_j) {
      /* Signum: '<S527>/Sign1' */
      if (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 < 0.0) {
        Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = -1.0;
      } else if (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 > 0.0) {
        Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = 1.0;
      } else if (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 == 0.0) {
        Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = 0.0;
      } else {
        Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = (rtNaN);
      }

      /* End of Signum: '<S527>/Sign1' */
      Modello_Arduino_2022_B.Sum_ax = ((Modello_Arduino_2022_B.PWM_aileron_p +
        Modello_Arduino_2022_P.Bias_Bias) * Modello_Arduino_2022_P.Gain_Gain_c +
        Modello_Arduino_2022_P.Bias1_Bias) *
        Modello_Arduino_2022_B.rtb_Gain1_d_idx_0;
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 =
        Modello_Arduino_2022_P.Constant_Value_n;
    } else {
      Modello_Arduino_2022_B.Sum_ax = Modello_Arduino_2022_B.rtb_Gain1_d_idx_0;
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 =
        Modello_Arduino_2022_P.Constant1_Value_e;
    }

    /* End of Switch: '<S527>/Switch' */

    /* Sum: '<S524>/Sum' */
    Modello_Arduino_2022_B.Sum_ci = Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 +
      Modello_Arduino_2022_B.Abs1;

    /* Gain: '<S523>/Gain1' */
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = Modello_Arduino_2022_P.Gain1_Gain
      * Modello_Arduino_2022_B.Sum_ax;

    /* Sum: '<S541>/Sum' incorporates:
     *  Constant: '<S541>/Constant'
     *  Constant: '<S541>/f'
     */
    Modello_Arduino_2022_B.Sum_ax = Modello_Arduino_2022_P.f_Value -
      Modello_Arduino_2022_P.Constant_Value_f;

    /* Sqrt: '<S542>/Sqrt' incorporates:
     *  Constant: '<S542>/Constant4'
     *  Product: '<S542>/Product'
     *  Sum: '<S542>/Sum'
     */
    Modello_Arduino_2022_B.Sum_ax = sqrt
      (Modello_Arduino_2022_P.Constant4_Value_n - Modello_Arduino_2022_B.Sum_ax *
       Modello_Arduino_2022_B.Sum_ax);

    /* Gain: '<S540>/Gain1' */
    Modello_Arduino_2022_B.Switch_i *= Modello_Arduino_2022_P.Gain1_Gain_h;

    /* Trigonometry: '<S543>/Trigonometric Function1' */
    Modello_Arduino_2022_B.Abs1 = sin(Modello_Arduino_2022_B.Switch_i);

    /* Sum: '<S543>/Sum1' incorporates:
     *  Constant: '<S543>/Constant'
     *  Product: '<S543>/Product1'
     */
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Constant_Value_o -
      Modello_Arduino_2022_B.Sum_ax * Modello_Arduino_2022_B.Sum_ax *
      Modello_Arduino_2022_B.Abs1 * Modello_Arduino_2022_B.Abs1;

    /* Product: '<S539>/Product1' incorporates:
     *  Constant: '<S539>/Constant1'
     *  Sqrt: '<S539>/sqrt'
     */
    Modello_Arduino_2022_B.PWM_aileron_p =
      Modello_Arduino_2022_P.Constant1_Value_i / sqrt
      (Modello_Arduino_2022_B.Abs1);

    /* Switch: '<S528>/Switch' incorporates:
     *  Abs: '<S528>/Abs'
     *  Bias: '<S528>/Bias'
     *  Bias: '<S528>/Bias1'
     *  Constant: '<S528>/Constant2'
     *  Constant: '<S532>/Constant'
     *  Math: '<S528>/Math Function1'
     *  RelationalOperator: '<S532>/Compare'
     */
    if (fabs(Modello_Arduino_2022_B.Sum_ci) >
        Modello_Arduino_2022_P.CompareToConstant_const_i) {
      Modello_Arduino_2022_B.Sum_ci = rt_modd_snf(Modello_Arduino_2022_B.Sum_ci
        + Modello_Arduino_2022_P.Bias_Bias_a,
        Modello_Arduino_2022_P.Constant2_Value_m) +
        Modello_Arduino_2022_P.Bias1_Bias_i;
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
    Modello_Arduino_2022_B.Switch_i = Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 /
      rt_atan2d_snf(Modello_Arduino_2022_P.Constant2_Value_k,
                    (Modello_Arduino_2022_P.Constant_Value_kr -
                     Modello_Arduino_2022_B.Sum_ax *
                     Modello_Arduino_2022_B.Sum_ax) *
                    Modello_Arduino_2022_B.PWM_aileron_p /
                    Modello_Arduino_2022_B.Abs1) * Modello_Arduino_2022_B.a_n +
      1.0 / rt_atan2d_snf(Modello_Arduino_2022_P.Constant3_Value_h,
                          Modello_Arduino_2022_B.PWM_aileron_p * cos
                          (Modello_Arduino_2022_B.Switch_i)) *
      (Modello_Arduino_2022_P.Gain1_Gain * Modello_Arduino_2022_B.Sum_ci) *
      Modello_Arduino_2022_B.Al_selector;

    /* Gain: '<S464>/Gain' */
    Modello_Arduino_2022_B.Sum_ci = Modello_Arduino_2022_P.Gain_Gain_i *
      Modello_Arduino_2022_B.Gain1_nb;

    /* Gain: '<S465>/Gain' */
    Modello_Arduino_2022_B.Gain_fd = Modello_Arduino_2022_P.Gain_Gain_fp *
      Modello_Arduino_2022_B.Gain1_m;

    /* MATLAB Function: '<S442>/ALLINEAMENTO' incorporates:
     *  Memory: '<S442>/Memory7'
     */
    Modello_Arduino_2022_B.b_a_tmp = Modello_Arduino_2022_B.WP_param_c[(int32_T)
      Modello_Arduino_2022_DW.Memory7_PreviousInput + 11];
    Modello_Arduino_2022_B.a_n = sin((Modello_Arduino_2022_B.b_a_tmp -
      Modello_Arduino_2022_B.Sum_ci) * 3.1415926535897931 / 180.0 / 2.0);
    Modello_Arduino_2022_B.dist_fut = Modello_Arduino_2022_B.WP_param_c[(int32_T)
      Modello_Arduino_2022_DW.Memory7_PreviousInput + 14];
    Modello_Arduino_2022_B.dist = (Modello_Arduino_2022_B.dist_fut -
      Modello_Arduino_2022_B.Gain_fd) * 3.1415926535897931 / 180.0;
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = sin(Modello_Arduino_2022_B.dist /
      2.0);
    Modello_Arduino_2022_B.Al_selector = Modello_Arduino_2022_B.b_a_tmp *
      3.1415926535897931 / 180.0;
    Modello_Arduino_2022_B.PWM_aileron_p = cos
      (Modello_Arduino_2022_B.Al_selector);
    Modello_Arduino_2022_B.a_tmp_tmp = Modello_Arduino_2022_B.Sum_ci *
      3.1415926535897931 / 180.0;
    Modello_Arduino_2022_B.Abs1 = cos(Modello_Arduino_2022_B.a_tmp_tmp);
    Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.Abs1 *
      Modello_Arduino_2022_B.PWM_aileron_p *
      (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 *
       Modello_Arduino_2022_B.rtb_Gain1_d_idx_0) + Modello_Arduino_2022_B.a_n *
      Modello_Arduino_2022_B.a_n;
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = rt_atan2d_snf(sqrt
      (Modello_Arduino_2022_B.a_n), sqrt(1.0 - Modello_Arduino_2022_B.a_n)) *
      2.0 * 6.378137E+6;
    if (Modello_Arduino_2022_DW.Memory7_PreviousInput > 1.0) {
      Modello_Arduino_2022_B.a_tmp_tmp = Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 11];
      Modello_Arduino_2022_B.Al_selector = Modello_Arduino_2022_B.a_tmp_tmp *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.a_n = cos(Modello_Arduino_2022_B.Al_selector);
      Modello_Arduino_2022_B.dist = Modello_Arduino_2022_B.WP_param_c[(int32_T)
        (Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 14];
      Modello_Arduino_2022_B.psi_ref_tmp = (Modello_Arduino_2022_B.dist_fut -
        Modello_Arduino_2022_B.dist) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Al_selector = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.psi_ref_tmp) *
        Modello_Arduino_2022_B.PWM_aileron_p, sin
        (Modello_Arduino_2022_B.WP_param_c[(int32_T)
         Modello_Arduino_2022_DW.Memory7_PreviousInput + 11] *
         3.1415926535897931 / 180.0) * Modello_Arduino_2022_B.a_n - sin
        (Modello_Arduino_2022_B.Al_selector) *
        Modello_Arduino_2022_B.PWM_aileron_p * cos
        (Modello_Arduino_2022_B.psi_ref_tmp)) * 180.0 / 3.1415926535897931;
      Modello_Arduino_2022_B.a_tmp_tmp = sin((Modello_Arduino_2022_B.Sum_ci -
        Modello_Arduino_2022_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Modello_Arduino_2022_B.dist = sin((Modello_Arduino_2022_B.Gain_fd -
        Modello_Arduino_2022_B.dist) * 3.1415926535897931 / 180.0 / 2.0);
      Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.a_n *
        Modello_Arduino_2022_B.Abs1 * (Modello_Arduino_2022_B.dist *
        Modello_Arduino_2022_B.dist) + Modello_Arduino_2022_B.a_tmp_tmp *
        Modello_Arduino_2022_B.a_tmp_tmp;
      Modello_Arduino_2022_B.dist = rt_atan2d_snf(sqrt
        (Modello_Arduino_2022_B.a_n), sqrt(1.0 - Modello_Arduino_2022_B.a_n)) *
        2.0 * 6.378137E+6;
    } else {
      Modello_Arduino_2022_B.Al_selector = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.dist) * Modello_Arduino_2022_B.PWM_aileron_p,
        sin(Modello_Arduino_2022_B.Al_selector) * Modello_Arduino_2022_B.Abs1 -
        cos(Modello_Arduino_2022_B.dist) * (sin(Modello_Arduino_2022_B.a_tmp_tmp)
        * Modello_Arduino_2022_B.PWM_aileron_p)) * 180.0 / 3.1415926535897931;
      Modello_Arduino_2022_B.dist = 0.0;
    }

    if (Modello_Arduino_2022_B.Al_selector < 0.0) {
      Modello_Arduino_2022_B.Al_selector = 360.0 - fabs
        (Modello_Arduino_2022_B.Al_selector);
    }

    Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.WP_param_c[(int32_T)
      Modello_Arduino_2022_DW.Memory7_PreviousInput + 2];
    if (Modello_Arduino_2022_B.a_n == 1.0) {
      Modello_Arduino_2022_B.psi_ref_tmp = Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput + 1.0) + 11];
      Modello_Arduino_2022_B.a_tmp_tmp = sin((Modello_Arduino_2022_B.psi_ref_tmp
        - Modello_Arduino_2022_B.b_a_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Modello_Arduino_2022_B.b_a_tmp = (Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput + 1.0) + 14] -
        Modello_Arduino_2022_B.dist_fut) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.dist_fut = sin(Modello_Arduino_2022_B.b_a_tmp / 2.0);
      Modello_Arduino_2022_B.psi_ref_tmp = Modello_Arduino_2022_B.psi_ref_tmp *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.a_fut_tmp = cos(Modello_Arduino_2022_B.psi_ref_tmp);
      Modello_Arduino_2022_B.dist_fut = Modello_Arduino_2022_B.PWM_aileron_p *
        Modello_Arduino_2022_B.a_fut_tmp * (Modello_Arduino_2022_B.dist_fut *
        Modello_Arduino_2022_B.dist_fut) + Modello_Arduino_2022_B.a_tmp_tmp *
        Modello_Arduino_2022_B.a_tmp_tmp;
      Modello_Arduino_2022_B.dist_fut = rt_atan2d_snf(sqrt
        (Modello_Arduino_2022_B.dist_fut), sqrt(1.0 -
        Modello_Arduino_2022_B.dist_fut)) * 2.0 * 6.378137E+6;
      Modello_Arduino_2022_B.PWM_aileron_p = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.b_a_tmp) * Modello_Arduino_2022_B.a_fut_tmp, sin
        (Modello_Arduino_2022_B.psi_ref_tmp) *
        Modello_Arduino_2022_B.PWM_aileron_p - cos
        (Modello_Arduino_2022_B.b_a_tmp) * (sin
        (Modello_Arduino_2022_B.WP_param_c[(int32_T)
         Modello_Arduino_2022_DW.Memory7_PreviousInput + 11] *
         3.1415926535897931 / 180.0) * Modello_Arduino_2022_B.a_fut_tmp)) *
        180.0 / 3.1415926535897931;
      if (Modello_Arduino_2022_B.PWM_aileron_p < 0.0) {
        Modello_Arduino_2022_B.PWM_aileron_p = 360.0 - fabs
          (Modello_Arduino_2022_B.PWM_aileron_p);
      }

      if (Modello_Arduino_2022_DW.Memory7_PreviousInput > 1.0) {
        Modello_Arduino_2022_B.PWM_aileron_p = fabs
          (Modello_Arduino_2022_B.PWM_aileron_p -
           Modello_Arduino_2022_B.Al_selector);
      } else {
        Modello_Arduino_2022_B.PWM_aileron_p = fabs
          (Modello_Arduino_2022_B.PWM_aileron_p - rt_atan2d_snf(sin
            ((Modello_Arduino_2022_B.WP_param_c[(int32_T)
              Modello_Arduino_2022_DW.Memory7_PreviousInput + 14] -
              Modello_Arduino_2022_B.Gain_fd) * 3.1415926535897931 / 180.0) *
            cos(Modello_Arduino_2022_B.WP_param_c[(int32_T)
                Modello_Arduino_2022_DW.Memory7_PreviousInput + 11] *
                3.1415926535897931 / 180.0), sin
            (Modello_Arduino_2022_B.WP_param_c[(int32_T)
             Modello_Arduino_2022_DW.Memory7_PreviousInput + 11] *
             3.1415926535897931 / 180.0) * cos(Modello_Arduino_2022_B.Sum_ci *
             3.1415926535897931 / 180.0) - cos
            (Modello_Arduino_2022_B.WP_param_c[(int32_T)
             Modello_Arduino_2022_DW.Memory7_PreviousInput + 11] *
             3.1415926535897931 / 180.0) * sin(Modello_Arduino_2022_B.Sum_ci *
             3.1415926535897931 / 180.0) * cos
            ((Modello_Arduino_2022_B.WP_param_c[(int32_T)
              Modello_Arduino_2022_DW.Memory7_PreviousInput + 14] -
              Modello_Arduino_2022_B.Gain_fd) * 3.1415926535897931 / 180.0)) *
           180.0 / 3.1415926535897931);
      }
    } else {
      Modello_Arduino_2022_B.dist_fut = 0.0;
      Modello_Arduino_2022_B.PWM_aileron_p = 0.0;
    }

    if (Modello_Arduino_2022_DW.Memory7_PreviousInput < 2.0) {
      Modello_Arduino_2022_B.Abs1 = 0.0;
    } else if (Modello_Arduino_2022_DW.Memory7_PreviousInput == 2.0) {
      Modello_Arduino_2022_B.b_a_tmp = cos(Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      Modello_Arduino_2022_B.Gain_fd = (Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 14] -
        Modello_Arduino_2022_B.Gain_fd) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Abs1 = fabs(Modello_Arduino_2022_B.Al_selector -
        rt_atan2d_snf(sin(Modello_Arduino_2022_B.Gain_fd) *
                      Modello_Arduino_2022_B.b_a_tmp, sin
                      (Modello_Arduino_2022_B.WP_param_c[(int32_T)
                       (Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) +
                       11] * 3.1415926535897931 / 180.0) *
                      Modello_Arduino_2022_B.Abs1 - cos
                      (Modello_Arduino_2022_B.Gain_fd) * (sin
        (Modello_Arduino_2022_B.Sum_ci * 3.1415926535897931 / 180.0) *
        Modello_Arduino_2022_B.b_a_tmp)) * 180.0 / 3.1415926535897931);
    } else {
      Modello_Arduino_2022_B.Abs1 = cos(Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      Modello_Arduino_2022_B.Sum_ci = Modello_Arduino_2022_B.WP_param_c[(int32_T)
        (Modello_Arduino_2022_DW.Memory7_PreviousInput - 2.0) + 11] *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Gain_fd = (Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 14] -
        Modello_Arduino_2022_B.WP_param_c[(int32_T)
        (Modello_Arduino_2022_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Abs1 = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.Gain_fd) * Modello_Arduino_2022_B.Abs1, cos
        (Modello_Arduino_2022_B.Sum_ci) * sin(Modello_Arduino_2022_B.WP_param_c
        [(int32_T)(Modello_Arduino_2022_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0) - sin(Modello_Arduino_2022_B.Sum_ci) *
        Modello_Arduino_2022_B.Abs1 * cos(Modello_Arduino_2022_B.Gain_fd)) *
        180.0 / 3.1415926535897931;
      if (Modello_Arduino_2022_B.Abs1 < 0.0) {
        Modello_Arduino_2022_B.Abs1 = 360.0 - fabs(Modello_Arduino_2022_B.Abs1);
      }

      Modello_Arduino_2022_B.Abs1 = fabs(Modello_Arduino_2022_B.Al_selector -
        Modello_Arduino_2022_B.Abs1);
    }

    if (Modello_Arduino_2022_B.PWM_aileron_p <= 3.0) {
      Modello_Arduino_2022_B.Al_selector = 1.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 20;
    } else if (Modello_Arduino_2022_B.PWM_aileron_p <= 10.0) {
      Modello_Arduino_2022_B.Al_selector = 30.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 100;
    } else if ((Modello_Arduino_2022_B.PWM_aileron_p > 10.0) &&
               (Modello_Arduino_2022_B.PWM_aileron_p <= 50.0)) {
      Modello_Arduino_2022_B.Al_selector = 80.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 250;
    } else if ((Modello_Arduino_2022_B.PWM_aileron_p > 50.0) &&
               (Modello_Arduino_2022_B.PWM_aileron_p <= 90.0)) {
      Modello_Arduino_2022_B.Al_selector = 100.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 300;
    } else if ((Modello_Arduino_2022_B.PWM_aileron_p > 90.0) &&
               (Modello_Arduino_2022_B.PWM_aileron_p <= 120.0)) {
      Modello_Arduino_2022_B.Al_selector = 150.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 350;
    } else {
      Modello_Arduino_2022_B.Al_selector = 200.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 400;
    }

    if (Modello_Arduino_2022_B.Abs1 <= 10.0) {
      Modello_Arduino_2022_B.soglia_dist = 80;
    } else if ((Modello_Arduino_2022_B.Abs1 > 10.0) &&
               (Modello_Arduino_2022_B.Abs1 <= 50.0)) {
      Modello_Arduino_2022_B.soglia_dist = 200;
    } else if ((Modello_Arduino_2022_B.Abs1 > 50.0) &&
               (Modello_Arduino_2022_B.Abs1 <= 90.0)) {
      Modello_Arduino_2022_B.soglia_dist = 300;
    } else if ((Modello_Arduino_2022_B.Abs1 > 90.0) &&
               (Modello_Arduino_2022_B.Abs1 <= 120.0)) {
      Modello_Arduino_2022_B.soglia_dist = 350;
    } else {
      Modello_Arduino_2022_B.soglia_dist = 400;
    }

    if (Modello_Arduino_2022_B.a_n == 1.0) {
      Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.WP_param_c[(int32_T)
        Modello_Arduino_2022_DW.Memory7_PreviousInput - 1];
      if (Modello_Arduino_2022_B.a_n <= 20.0) {
        Modello_Arduino_2022_B.Al_selector *= 1.1;
      } else if ((Modello_Arduino_2022_B.a_n <= 25.0) &&
                 (Modello_Arduino_2022_B.a_n > 20.0)) {
        Modello_Arduino_2022_B.Al_selector *= 1.2;
      } else if (Modello_Arduino_2022_B.a_n <= 30.0) {
        if (Modello_Arduino_2022_B.a_n > 25.0) {
          Modello_Arduino_2022_B.Al_selector *= 1.3;
        } else {
          Modello_Arduino_2022_B.Al_selector *= 1.4;
        }
      } else {
        Modello_Arduino_2022_B.Al_selector *= 1.4;
      }

      if (((!(Modello_Arduino_2022_B.dist < Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 >
                 Modello_Arduino_2022_B.Al_selector))) &&
          ((!(Modello_Arduino_2022_B.dist > Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 >
                 Modello_Arduino_2022_B.Al_selector))) &&
          (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 <
           Modello_Arduino_2022_B.Al_selector)) {
        if (Modello_Arduino_2022_B.dist_fut >
            Modello_Arduino_2022_B.tolleranza_distWP_fut) {
          Modello_Arduino_2022_DW.Memory7_PreviousInput++;
        } else if (Modello_Arduino_2022_DW.Memory7_PreviousInput < 2.0) {
          Modello_Arduino_2022_DW.Memory7_PreviousInput += 2.0;
        } else {
          Modello_Arduino_2022_DW.flag_d = 1.0;
        }
      }
    } else {
      if (((!(Modello_Arduino_2022_B.dist < Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_DW.flag_d == 0.0))) &&
          ((!(Modello_Arduino_2022_B.dist > Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 > 40.0)) ||
           (!(Modello_Arduino_2022_DW.flag_d == 0.0)))) {
        Modello_Arduino_2022_DW.flag_d = 1.0;
      }
    }

    if (!(Modello_Arduino_2022_B.modo == 4.0)) {
      Modello_Arduino_2022_DW.Memory7_PreviousInput = 1.0;
    }

    /* End of MATLAB Function: '<S442>/ALLINEAMENTO' */

    /* Abs: '<S442>/Abs1' */
    Modello_Arduino_2022_B.a_n = fabs(Modello_Arduino_2022_B.Switch_i);

    /* Chart: '<S442>/Chart1' incorporates:
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  Memory: '<S442>/Memory1'
     *  Memory: '<S442>/Memory2'
     *  Memory: '<S442>/Memory5'
     */
    if (Modello_Arduino_2022_DW.is_active_c10_Modello_Arduino_2 == 0U) {
      Modello_Arduino_2022_DW.is_active_c10_Modello_Arduino_2 = 1U;
      Modello_Arduino_2022_B.maneuver_selector = 1.0;
      Modello_Arduino_2022_B.trig_approach = 0.0;
      Modello_Arduino_2022_B.trig_flare = 0.0;
      Modello_Arduino_2022_B.approach_selector = 1.0;
      Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
        Modello_Arduino__IN_Allignment1;
    } else {
      switch (Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022) {
       case Modello_Arduino_2022_IN_Abort:
        Modello_Arduino_2022_B.maneuver_selector = 1.0;
        Modello_Arduino_2022_B.trig_approach = 0.0;
        Modello_Arduino_2022_B.trig_flare = 0.0;
        Modello_Arduino_2022_B.approach_selector = 0.0;
        break;

       case Modello_Arduino_2_IN_Allignment:
        if ((Modello_Arduino_2022_B.ByteUnpack_o2_h[2] > 35.0F) &&
            (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] < 60.0F) &&
            (Modello_Arduino_2022_B.a_n <=
             Modello_Arduino_2022_B.ByteUnpack_o2_h[2] * 19.081136687728211 +
             100.0) && (Modello_Arduino_2022_B.a_n >=
                        Modello_Arduino_2022_B.ByteUnpack_o2_h[2] *
                        14.300666256711928 + 100.0) &&
            (Modello_Arduino_2022_DW.Memory7_PreviousInput > 1.0)) {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino_202_IN_Approach;
        } else if (Modello_Arduino_2022_B.modo != 4.0) {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino__IN_Allignment1;
        } else {
          Modello_Arduino_2022_B.trig_flare = 0.0;
          Modello_Arduino_2022_B.approach_selector = 0.0;
          Modello_Arduino_2022_B.maneuver_selector = 1.0;
          Modello_Arduino_2022_B.trig_approach = 0.0;
        }
        break;

       case Modello_Arduino__IN_Allignment1:
        if (Modello_Arduino_2022_B.modo == 4.0) {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino_2_IN_Allignment;
        } else {
          Modello_Arduino_2022_B.maneuver_selector = 1.0;
          Modello_Arduino_2022_B.trig_approach = 0.0;
          Modello_Arduino_2022_B.trig_flare = 0.0;
          Modello_Arduino_2022_B.approach_selector = 0.0;
        }
        break;

       case Modello_Arduino_202_IN_Approach:
        if ((Modello_Arduino_2022_B.Switch_i >=
             Modello_Arduino_2022_DW.Memory5_PreviousInput) &&
            ((Modello_Arduino_2022_B.ByteUnpack_o2_h[2] <=
              Modello_Arduino_2022_DW.Memory1_PreviousInput_b + 1.5) ||
             (Modello_Arduino_2022_B.ByteUnpack_o2_h[2] >
              Modello_Arduino_2022_DW.Memory1_PreviousInput_b - 1.0))) {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino_2022_IN_Flare;
        } else if (Modello_Arduino_2022_B.modo != 4.0) {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino__IN_Allignment1;
        } else if (Modello_Arduino_2022_DW.Memory2_PreviousInput_n == 1.0) {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino_2022_IN_Abort;
        } else {
          Modello_Arduino_2022_B.trig_flare = 0.0;
          Modello_Arduino_2022_B.trig_approach = 1.0;
          Modello_Arduino_2022_B.approach_selector = 1.0;
          Modello_Arduino_2022_B.maneuver_selector = 2.0;
        }
        break;

       default:
        /* case IN_Flare: */
        if ((Modello_Arduino_2022_B.Product1 < 3.0) ||
            (!(Modello_Arduino_2022_B.modo != 4.0))) {
          Modello_Arduino_2022_B.trig_approach = 0.0;
          Modello_Arduino_2022_B.trig_flare = 1.0;
          Modello_Arduino_2022_B.approach_selector = 0.0;
          Modello_Arduino_2022_B.maneuver_selector = 3.0;
        } else {
          Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 =
            Modello_Arduino__IN_Allignment1;
        }
        break;
      }
    }

    /* End of Chart: '<S442>/Chart1' */

    /* UnaryMinus: '<S459>/Ze2height' incorporates:
     *  Constant: '<S442>/Constant4'
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  Sum: '<S459>/Sum'
     */
    Modello_Arduino_2022_B.Sum_ax = -(Modello_Arduino_2022_B.ByteUnpack_o2_h[2]
      + Modello_Arduino_2022_P.Constant4_Value_d);

    /* Outputs for Triggered SubSystem: '<S442>/Sample and Hold' incorporates:
     *  TriggerPort: '<S467>/Trigger'
     */
    Modello_Arduino_2022_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &Modello_Arduino_2022_PrevZCX.SampleandHold_Trig_ZCE,
      (Modello_Arduino_2022_B.approach_selector));
    if (Modello_Arduino_2022_B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S467>/In' incorporates:
       *  Abs: '<S442>/Abs2'
       */
      Modello_Arduino_2022_B.In[0] = fabs(Modello_Arduino_2022_B.Sum_ax);
      Modello_Arduino_2022_B.In[1] = Modello_Arduino_2022_B.Switch_i;
    }

    /* End of Outputs for SubSystem: '<S442>/Sample and Hold' */

    /* Outputs for Enabled SubSystem: '<S442>/APPROACH' incorporates:
     *  EnablePort: '<S453>/Enable'
     */
    if (Modello_Arduino_2022_B.trig_approach > 0.0) {
      /* Product: '<S453>/Divide' incorporates:
       *  Constant: '<S453>/x_g0'
       *  Sum: '<S453>/Sum'
       */
      Modello_Arduino_2022_B.Sum_ax = Modello_Arduino_2022_B.In[0] /
        (Modello_Arduino_2022_B.In[1] - Modello_Arduino_2022_P.x_g0_Value);

      /* Abs: '<S453>/Abs' incorporates:
       *  Trigonometry: '<S453>/Atan'
       */
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = fabs(atan
        (Modello_Arduino_2022_B.Sum_ax));

      /* DiscreteIntegrator: '<S453>/Discrete-Time Integrator' */
      if ((Modello_Arduino_2022_B.trig_approach > 0.0) &&
          (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRe_i <= 0)) {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h =
          Modello_Arduino_2022_P.DiscreteTimeIntegrator_IC;
      }

      if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h >=
          Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperSat) {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h =
          Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h <=
            Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerSat) {
          Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h =
            Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      /* Switch: '<S453>/Switch' incorporates:
       *  Constant: '<S453>/Constant3'
       *  Constant: '<S453>/Constant4'
       *  DiscreteIntegrator: '<S453>/Discrete-Time Integrator'
       */
      if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h >
          Modello_Arduino_2022_P.Switch_Threshold_a) {
        Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_P.Constant3_Value_d;
      } else {
        Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_P.Constant4_Value_o;
      }

      /* End of Switch: '<S453>/Switch' */

      /* MATLAB Function: '<S453>/MATLAB Function' */
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 0;
      if ((!Modello_Arduino_2022_DW.x_not_empty) || (Modello_Arduino_2022_B.a_n ==
           0.0)) {
        Modello_Arduino_2022_DW.x[0] = 1.5;
        Modello_Arduino_2022_DW.x[1] = -200.0;
        Modello_Arduino_2022_DW.x[2] = 0.01;
        Modello_Arduino_2022_DW.x[3] = -2.0;
        Modello_Arduino_2022_DW.x_not_empty = true;
      }

      Modello_Arduino_2022_DW.x_new_not_empty =
        ((!Modello_Arduino_2022_DW.x_new_not_empty) ||
         (Modello_Arduino_2022_B.a_n == 0.0) ||
         Modello_Arduino_2022_DW.x_new_not_empty);
      if ((!Modello_Arduino_2022_DW.eps_not_empty) ||
          (Modello_Arduino_2022_B.a_n == 0.0)) {
        Modello_Arduino_2022_DW.eps[0] = 1.0;
        Modello_Arduino_2022_DW.eps[1] = 1.0;
        Modello_Arduino_2022_DW.eps[2] = 1.0;
        Modello_Arduino_2022_DW.eps[3] = 1.0;
        Modello_Arduino_2022_DW.eps_not_empty = true;
      }

      if ((!Modello_Arduino_2022_DW.cycle_count_not_empty) ||
          (Modello_Arduino_2022_B.a_n == 0.0)) {
        Modello_Arduino_2022_DW.cycle_count = 0.0;
        Modello_Arduino_2022_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(Modello_Arduino_2022_DW.eps[0] < 0.1)) ||
                           ((!(Modello_Arduino_2022_DW.eps[1] < 0.1)) ||
                            ((!(Modello_Arduino_2022_DW.eps[2] < 0.1)) ||
                             (!(Modello_Arduino_2022_DW.eps[3] < 0.1)))))) {
        memset(&Modello_Arduino_2022_B.a[0], 0, sizeof(real_T) << 4U);
        Modello_Arduino_2022_B.Abs1 = exp((5.0 - Modello_Arduino_2022_DW.x[1]) *
          -Modello_Arduino_2022_DW.x[2]);
        Modello_Arduino_2022_B.Sum_ci = tan
          (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0);
        Modello_Arduino_2022_B.A[0] = 1.0;
        Modello_Arduino_2022_B.A[4] = Modello_Arduino_2022_B.Sum_ci;
        Modello_Arduino_2022_B.A[8] = 0.0;
        Modello_Arduino_2022_B.A[12] = 0.0;
        Modello_Arduino_2022_B.A[1] = Modello_Arduino_2022_DW.x[2];
        Modello_Arduino_2022_B.A[5] = 0.0;
        Modello_Arduino_2022_B.PWM_aileron_p = Modello_Arduino_2022_DW.x[0] -
          Modello_Arduino_2022_DW.x[3];
        Modello_Arduino_2022_B.A[9] = Modello_Arduino_2022_B.PWM_aileron_p;
        Modello_Arduino_2022_B.A[13] = -Modello_Arduino_2022_DW.x[2];
        Modello_Arduino_2022_B.A[2] = Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.Gain_fd = Modello_Arduino_2022_B.PWM_aileron_p *
          Modello_Arduino_2022_DW.x[2];
        Modello_Arduino_2022_B.A[6] = Modello_Arduino_2022_B.Gain_fd *
          Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.A[10] = Modello_Arduino_2022_B.PWM_aileron_p *
          (Modello_Arduino_2022_DW.x[1] - 5.0) * Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.A[14] = 1.0;
        Modello_Arduino_2022_B.A[3] = Modello_Arduino_2022_DW.x[2] * 18.0 *
          Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.A[7] = Modello_Arduino_2022_B.PWM_aileron_p *
          (Modello_Arduino_2022_DW.x[2] * Modello_Arduino_2022_DW.x[2]) * 18.0 *
          Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.Al_selector = Modello_Arduino_2022_B.Gain_fd *
          18.0;
        Modello_Arduino_2022_B.A[11] = Modello_Arduino_2022_B.Al_selector *
          (Modello_Arduino_2022_DW.x[1] - 5.0) * Modello_Arduino_2022_B.Abs1 +
          Modello_Arduino_2022_B.PWM_aileron_p * 18.0 *
          Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.A[15] = -Modello_Arduino_2022_DW.x[2] * 18.0 *
          Modello_Arduino_2022_B.Abs1;
        Modello_Arduino_2022_B.ipiv[0] = 1;
        Modello_Arduino_2022_B.ipiv[1] = 2;
        Modello_Arduino_2022_B.ipiv[2] = 3;
        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 3;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_B.soglia_dist = Modello_Arduino_2022_B.pipk * 5;
          Modello_Arduino_2022_B.f = 0;
          Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.soglia_dist;
          Modello_Arduino_2022_B.a_n = fabs
            (Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.soglia_dist]);
          Modello_Arduino_2022_B.jy = 2;
          while (Modello_Arduino_2022_B.jy <= 4 - Modello_Arduino_2022_B.pipk) {
            Modello_Arduino_2022_B.i++;
            Modello_Arduino_2022_B.dist = fabs
              (Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.i]);
            if (Modello_Arduino_2022_B.dist > Modello_Arduino_2022_B.a_n) {
              Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.jy - 1;
              Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.dist;
            }

            Modello_Arduino_2022_B.jy++;
          }

          if (Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.soglia_dist +
              Modello_Arduino_2022_B.f] != 0.0) {
            if (Modello_Arduino_2022_B.f != 0) {
              Modello_Arduino_2022_B.f += Modello_Arduino_2022_B.pipk;
              Modello_Arduino_2022_B.ipiv[Modello_Arduino_2022_B.pipk] = (int8_T)
                (Modello_Arduino_2022_B.f + 1);
              Modello_Arduino_2022_B.a_n =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk] =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f] =
                Modello_Arduino_2022_B.a_n;
              Modello_Arduino_2022_B.a_n =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk + 4];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk + 4] =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 4];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 4] =
                Modello_Arduino_2022_B.a_n;
              Modello_Arduino_2022_B.a_n =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk + 8];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk + 8] =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 8];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 8] =
                Modello_Arduino_2022_B.a_n;
              Modello_Arduino_2022_B.a_n =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk + 12];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.pipk + 12] =
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 12];
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 12] =
                Modello_Arduino_2022_B.a_n;
            }

            Modello_Arduino_2022_B.i = (Modello_Arduino_2022_B.soglia_dist -
              Modello_Arduino_2022_B.pipk) + 4;
            Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.soglia_dist + 1;
            while (Modello_Arduino_2022_B.f + 1 <= Modello_Arduino_2022_B.i) {
              Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f] /=
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.soglia_dist];
              Modello_Arduino_2022_B.f++;
            }
          }

          Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.soglia_dist;
          Modello_Arduino_2022_B.jy = Modello_Arduino_2022_B.soglia_dist + 4;
          Modello_Arduino_2022_B.c = 0;
          while (Modello_Arduino_2022_B.c <= 2 - Modello_Arduino_2022_B.pipk) {
            if (Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.jy] != 0.0) {
              Modello_Arduino_2022_B.a_n =
                -Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.jy];
              Modello_Arduino_2022_B.c_ix = Modello_Arduino_2022_B.soglia_dist +
                1;
              Modello_Arduino_2022_B.f = (Modello_Arduino_2022_B.i -
                Modello_Arduino_2022_B.pipk) + 8;
              Modello_Arduino_2022_B.ijA = Modello_Arduino_2022_B.i + 5;
              while (Modello_Arduino_2022_B.ijA + 1 <= Modello_Arduino_2022_B.f)
              {
                Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.ijA] +=
                  Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.c_ix] *
                  Modello_Arduino_2022_B.a_n;
                Modello_Arduino_2022_B.c_ix++;
                Modello_Arduino_2022_B.ijA++;
              }
            }

            Modello_Arduino_2022_B.jy += 4;
            Modello_Arduino_2022_B.i += 4;
            Modello_Arduino_2022_B.c++;
          }
        }

        Modello_Arduino_2022_B.p[0] = 1;
        Modello_Arduino_2022_B.p[1] = 2;
        Modello_Arduino_2022_B.p[2] = 3;
        Modello_Arduino_2022_B.p[3] = 4;
        if (Modello_Arduino_2022_B.ipiv[0] > 1) {
          Modello_Arduino_2022_B.pipk =
            Modello_Arduino_2022_B.p[Modello_Arduino_2022_B.ipiv[0] - 1];
          Modello_Arduino_2022_B.p[Modello_Arduino_2022_B.ipiv[0] - 1] = 1;
          Modello_Arduino_2022_B.p[0] = (int8_T)Modello_Arduino_2022_B.pipk;
        }

        if (Modello_Arduino_2022_B.ipiv[1] > 2) {
          Modello_Arduino_2022_B.pipk =
            Modello_Arduino_2022_B.p[Modello_Arduino_2022_B.ipiv[1] - 1];
          Modello_Arduino_2022_B.p[Modello_Arduino_2022_B.ipiv[1] - 1] =
            Modello_Arduino_2022_B.p[1];
          Modello_Arduino_2022_B.p[1] = (int8_T)Modello_Arduino_2022_B.pipk;
        }

        if (Modello_Arduino_2022_B.ipiv[2] > 3) {
          Modello_Arduino_2022_B.pipk =
            Modello_Arduino_2022_B.p[Modello_Arduino_2022_B.ipiv[2] - 1];
          Modello_Arduino_2022_B.p[Modello_Arduino_2022_B.ipiv[2] - 1] =
            Modello_Arduino_2022_B.p[2];
          Modello_Arduino_2022_B.p[2] = (int8_T)Modello_Arduino_2022_B.pipk;
        }

        Modello_Arduino_2022_B.c = Modello_Arduino_2022_B.p[0] - 1;
        Modello_Arduino_2022_B.a[(Modello_Arduino_2022_B.p[0] - 1) << 2] = 1.0;
        Modello_Arduino_2022_B.soglia_dist = 0;
        while (Modello_Arduino_2022_B.soglia_dist + 1 < 5) {
          Modello_Arduino_2022_B.pipk = Modello_Arduino_2022_B.c << 2;
          Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.pipk +
            Modello_Arduino_2022_B.soglia_dist;
          if (Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] != 0.0) {
            Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.soglia_dist + 1;
            while (Modello_Arduino_2022_B.i + 1 < 5) {
              Modello_Arduino_2022_B.jy = Modello_Arduino_2022_B.pipk +
                Modello_Arduino_2022_B.i;
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.jy] -=
                Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] *
                Modello_Arduino_2022_B.A[(Modello_Arduino_2022_B.soglia_dist <<
                2) + Modello_Arduino_2022_B.i];
              Modello_Arduino_2022_B.i++;
            }
          }

          Modello_Arduino_2022_B.soglia_dist++;
        }

        Modello_Arduino_2022_B.c = Modello_Arduino_2022_B.p[1] - 1;
        Modello_Arduino_2022_B.a[((Modello_Arduino_2022_B.p[1] - 1) << 2) + 1] =
          1.0;
        Modello_Arduino_2022_B.soglia_dist = 1;
        while (Modello_Arduino_2022_B.soglia_dist + 1 < 5) {
          Modello_Arduino_2022_B.pipk = Modello_Arduino_2022_B.c << 2;
          Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.pipk +
            Modello_Arduino_2022_B.soglia_dist;
          if (Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] != 0.0) {
            Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.soglia_dist + 1;
            while (Modello_Arduino_2022_B.i + 1 < 5) {
              Modello_Arduino_2022_B.jy = Modello_Arduino_2022_B.pipk +
                Modello_Arduino_2022_B.i;
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.jy] -=
                Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] *
                Modello_Arduino_2022_B.A[(Modello_Arduino_2022_B.soglia_dist <<
                2) + Modello_Arduino_2022_B.i];
              Modello_Arduino_2022_B.i++;
            }
          }

          Modello_Arduino_2022_B.soglia_dist++;
        }

        Modello_Arduino_2022_B.c = Modello_Arduino_2022_B.p[2] - 1;
        Modello_Arduino_2022_B.a[((Modello_Arduino_2022_B.p[2] - 1) << 2) + 2] =
          1.0;
        Modello_Arduino_2022_B.soglia_dist = 2;
        while (Modello_Arduino_2022_B.soglia_dist + 1 < 5) {
          Modello_Arduino_2022_B.pipk = Modello_Arduino_2022_B.c << 2;
          Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.pipk +
            Modello_Arduino_2022_B.soglia_dist;
          if (Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] != 0.0) {
            Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.soglia_dist + 1;
            while (Modello_Arduino_2022_B.i + 1 < 5) {
              Modello_Arduino_2022_B.jy = Modello_Arduino_2022_B.pipk +
                Modello_Arduino_2022_B.i;
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.jy] -=
                Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] *
                Modello_Arduino_2022_B.A[(Modello_Arduino_2022_B.soglia_dist <<
                2) + Modello_Arduino_2022_B.i];
              Modello_Arduino_2022_B.i++;
            }
          }

          Modello_Arduino_2022_B.soglia_dist++;
        }

        Modello_Arduino_2022_B.jy = (Modello_Arduino_2022_B.p[3] - 1) << 2;
        Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.jy + 3] = 1.0;
        Modello_Arduino_2022_B.soglia_dist = 3;
        while (Modello_Arduino_2022_B.soglia_dist + 1 < 5) {
          Modello_Arduino_2022_B.pipk = Modello_Arduino_2022_B.jy +
            Modello_Arduino_2022_B.soglia_dist;
          if (Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.pipk] != 0.0) {
            Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.soglia_dist + 1;
            while (Modello_Arduino_2022_B.i + 1 < 5) {
              Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.jy +
                Modello_Arduino_2022_B.i;
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.f] -=
                Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.pipk] *
                Modello_Arduino_2022_B.A[(Modello_Arduino_2022_B.soglia_dist <<
                2) + Modello_Arduino_2022_B.i];
              Modello_Arduino_2022_B.i++;
            }
          }

          Modello_Arduino_2022_B.soglia_dist++;
        }

        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 4;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_B.soglia_dist = Modello_Arduino_2022_B.pipk << 2;
          Modello_Arduino_2022_B.a_n =
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 3];
          if (Modello_Arduino_2022_B.a_n != 0.0) {
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 3] =
              Modello_Arduino_2022_B.a_n / Modello_Arduino_2022_B.A[15];
            Modello_Arduino_2022_B.f = 0;
            while (Modello_Arduino_2022_B.f <= 2) {
              Modello_Arduino_2022_B.jy = Modello_Arduino_2022_B.f +
                Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.jy] -=
                Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 3]
                * Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 12];
              Modello_Arduino_2022_B.f++;
            }
          }

          Modello_Arduino_2022_B.a_n =
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 2];
          if (Modello_Arduino_2022_B.a_n != 0.0) {
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 2] =
              Modello_Arduino_2022_B.a_n / Modello_Arduino_2022_B.A[10];
            Modello_Arduino_2022_B.f = 0;
            while (Modello_Arduino_2022_B.f <= 1) {
              Modello_Arduino_2022_B.jy = Modello_Arduino_2022_B.f +
                Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.jy] -=
                Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 2]
                * Modello_Arduino_2022_B.A[Modello_Arduino_2022_B.f + 8];
              Modello_Arduino_2022_B.f++;
            }
          }

          Modello_Arduino_2022_B.a_n =
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 1];
          if (Modello_Arduino_2022_B.a_n != 0.0) {
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 1] =
              Modello_Arduino_2022_B.a_n / Modello_Arduino_2022_B.A[5];
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist] -=
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist + 1] *
              Modello_Arduino_2022_B.A[4];
          }

          if (Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist] !=
              0.0) {
            Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.soglia_dist] /=
              Modello_Arduino_2022_B.A[0];
          }
        }

        Modello_Arduino_2022_B.a_n = (Modello_Arduino_2022_DW.x[1] -
          Modello_Arduino_2022_P.x_g0_Value) * Modello_Arduino_2022_B.Sum_ci +
          Modello_Arduino_2022_DW.x[0];
        Modello_Arduino_2022_B.Sum_ci = Modello_Arduino_2022_B.Gain_fd -
          Modello_Arduino_2022_B.Sum_ci;
        Modello_Arduino_2022_B.PWM_aileron_p =
          Modello_Arduino_2022_B.PWM_aileron_p * Modello_Arduino_2022_B.Abs1 +
          Modello_Arduino_2022_DW.x[3];
        Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.Al_selector *
          Modello_Arduino_2022_B.Abs1 + -0.1;
        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 4;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_B.x_new[Modello_Arduino_2022_B.pipk] =
            Modello_Arduino_2022_DW.x[Modello_Arduino_2022_B.pipk] -
            (((Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.pipk + 4] *
               Modello_Arduino_2022_B.Sum_ci +
               Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.pipk] *
               Modello_Arduino_2022_B.a_n) +
              Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.pipk + 8] *
              Modello_Arduino_2022_B.PWM_aileron_p) +
             Modello_Arduino_2022_B.a[Modello_Arduino_2022_B.pipk + 12] *
             Modello_Arduino_2022_B.Abs1);
        }

        Modello_Arduino_2022_DW.eps[0] = fabs(Modello_Arduino_2022_B.x_new[0] -
          Modello_Arduino_2022_DW.x[0]);
        Modello_Arduino_2022_DW.eps[1] = fabs(Modello_Arduino_2022_B.x_new[1] -
          Modello_Arduino_2022_DW.x[1]);
        Modello_Arduino_2022_DW.eps[2] = fabs(Modello_Arduino_2022_B.x_new[2] -
          Modello_Arduino_2022_DW.x[2]);
        Modello_Arduino_2022_DW.eps[3] = fabs(Modello_Arduino_2022_B.x_new[3] -
          Modello_Arduino_2022_DW.x[3]);
        Modello_Arduino_2022_DW.x[0] = Modello_Arduino_2022_B.x_new[0];
        Modello_Arduino_2022_DW.x[1] = Modello_Arduino_2022_B.x_new[1];
        Modello_Arduino_2022_DW.x[2] = Modello_Arduino_2022_B.x_new[2];
        Modello_Arduino_2022_DW.x[3] = Modello_Arduino_2022_B.x_new[3];
        Modello_Arduino_2022_DW.cycle_count++;
        if (Modello_Arduino_2022_DW.cycle_count > 10.0) {
          Modello_Arduino_2022_B.tolleranza_distWP_fut = 1;
          exitg1 = true;
        }
      }

      if ((Modello_Arduino_2022_DW.eps[0] < 0.1) &&
          (Modello_Arduino_2022_DW.eps[1] < 0.1) &&
          (Modello_Arduino_2022_DW.eps[2] < 0.1) &&
          (Modello_Arduino_2022_DW.eps[3] < 0.1)) {
        Modello_Arduino_2022_B.h_f_out = Modello_Arduino_2022_DW.x[0];
        Modello_Arduino_2022_B.x_f_out = Modello_Arduino_2022_DW.x[1];
        Modello_Arduino_2022_B.k_x_out = Modello_Arduino_2022_DW.x[2];
        Modello_Arduino_2022_B.h_c_out = Modello_Arduino_2022_DW.x[3];
      } else {
        Modello_Arduino_2022_B.h_f_out = 0.0;
        Modello_Arduino_2022_B.x_f_out = 0.0;
        Modello_Arduino_2022_B.k_x_out = 0.0;
        Modello_Arduino_2022_B.h_c_out = 0.0;
      }

      Modello_Arduino_2022_B.no_solution =
        Modello_Arduino_2022_B.tolleranza_distWP_fut;

      /* End of MATLAB Function: '<S453>/MATLAB Function' */

      /* Product: '<S453>/Multiply' incorporates:
       *  Constant: '<S453>/x_g0'
       *  Gain: '<S453>/Gain'
       *  Sum: '<S453>/Sum1'
       */
      Modello_Arduino_2022_B.Multiply = (Modello_Arduino_2022_B.Switch_i -
        Modello_Arduino_2022_P.x_g0_Value) * Modello_Arduino_2022_P.Gain_Gain_k *
        Modello_Arduino_2022_B.Sum_ax;

      /* Constant: '<S453>/Constant1' */
      Modello_Arduino_2022_B.Constant1_c =
        Modello_Arduino_2022_P.Constant1_Value_l;

      /* Update for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S453>/Constant2'
       */
      Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h +=
        Modello_Arduino_2022_P.DiscreteTimeIntegrator_gainval *
        Modello_Arduino_2022_P.Constant2_Value_a;
      if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h >=
          Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperSat) {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h =
          Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h <=
            Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerSat) {
          Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h =
            Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      if (Modello_Arduino_2022_B.trig_approach > 0.0) {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRe_i = 1;
      } else if (Modello_Arduino_2022_B.trig_approach < 0.0) {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRe_i = -1;
      } else if (Modello_Arduino_2022_B.trig_approach == 0.0) {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRe_i = 0;
      } else {
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRe_i = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' */
    }

    /* End of Outputs for SubSystem: '<S442>/APPROACH' */

    /* Outputs for Enabled SubSystem: '<S442>/FLARE' incorporates:
     *  EnablePort: '<S457>/Enable'
     */
    if (Modello_Arduino_2022_B.trig_flare > 0.0) {
      /* Constant: '<S457>/Constant1' */
      Modello_Arduino_2022_B.Constant1 =
        Modello_Arduino_2022_P.Constant1_Value_j;

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
      Modello_Arduino_2022_B.Sum2 = exp((Modello_Arduino_2022_B.Switch_i -
        Modello_Arduino_2022_B.x_f_out) * Modello_Arduino_2022_B.k_x_out *
        Modello_Arduino_2022_P.Gain_Gain_p) * (Modello_Arduino_2022_B.h_f_out -
        Modello_Arduino_2022_B.h_c_out) + Modello_Arduino_2022_B.h_c_out;
    }

    /* End of Outputs for SubSystem: '<S442>/FLARE' */

    /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' */
    switch ((int32_T)Modello_Arduino_2022_B.maneuver_selector) {
     case 1:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' incorporates:
       *  Constant: '<S442>/Constant6'
       */
      Modello_Arduino_2022_B.velocita = Modello_Arduino_2022_P.Constant6_Value;
      break;

     case 2:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' */
      Modello_Arduino_2022_B.velocita = Modello_Arduino_2022_B.Constant1_c;
      break;

     default:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' */
      Modello_Arduino_2022_B.velocita = Modello_Arduino_2022_B.Constant1;
      break;
    }

    /* End of MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' */

    /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' */
    switch ((int32_T)Modello_Arduino_2022_B.maneuver_selector) {
     case 1:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Constant: '<S442>/Constant2'
       */
      Modello_Arduino_2022_B.QUOTA_f = Modello_Arduino_2022_P.Constant2_Value_j;
      break;

     case 2:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S442>/Abs3'
       */
      Modello_Arduino_2022_B.QUOTA_f = fabs(Modello_Arduino_2022_B.Multiply);
      break;

     default:
      /* MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S442>/Abs4'
       */
      Modello_Arduino_2022_B.QUOTA_f = fabs(Modello_Arduino_2022_B.Sum2);
      break;
    }

    /* End of MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' */

    /* Update for Memory: '<S442>/Memory5' */
    Modello_Arduino_2022_DW.Memory5_PreviousInput =
      Modello_Arduino_2022_B.x_f_out;

    /* Update for Memory: '<S442>/Memory1' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_b =
      Modello_Arduino_2022_B.h_f_out;

    /* Update for Memory: '<S442>/Memory2' */
    Modello_Arduino_2022_DW.Memory2_PreviousInput_n =
      Modello_Arduino_2022_B.no_solution;
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem1' */

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S21>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&Modello_Arduino_2022_B.iflogic,
     &Modello_Arduino_2022_B.DataTypeConversion3,
     &Modello_Arduino_2022_P.SIUAVuint8_Value, &Modello_Arduino_2022_B.GC_info[0],
     &Modello_Arduino_2022_B.Val_out_MAV[0], &Modello_Arduino_2022_B.WP_info[0],
     &Modello_Arduino_2022_B.WP_param[0],
     &Modello_Arduino_2022_P.onboard_control_sensor_presentu[0],
     &Modello_Arduino_2022_B.TmpSignalConversionAtSFunctionI[0],
     &Modello_Arduino_2022_B.Gain1, &Modello_Arduino_2022_B.B_Remaining,
     &Modello_Arduino_2022_B.DataTypeConversion,
     &Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[0],
     &Modello_Arduino_2022_B.DataTypeConversion_ld[0],
     &Modello_Arduino_2022_B.DataTypeConversion1[0],
     &Modello_Arduino_2022_B.DataTypeConversion_a[0],
     &Modello_Arduino_2022_B.DataTypeConversion1_p[0],
     &Modello_Arduino_2022_B.DataTypeConversion2_h,
     &Modello_Arduino_2022_B.AGAC[0], &Modello_Arduino_2022_B.Heading_g,
     &Modello_Arduino_2022_B.Throttle, &Modello_Arduino_2022_B.Heading[0],
     &Modello_Arduino_2022_B.Memory_a,
     &Modello_Arduino_2022_B.DataTypeConversion2,
     &Modello_Arduino_2022_B.SFunction_o14,
     &Modello_Arduino_2022_B.DataTypeConversion1_j,
     &Modello_Arduino_2022_B.SFunction_o15,
     &Modello_Arduino_2022_B.DataTypeConversion_l,
     &Modello_Arduino_2022_B.DataTypeConversion1_g,
     &Modello_Arduino_2022_B.DataTypeConversion2_m,
     &Modello_Arduino_2022_B.SFunction_o5[0], &Modello_Arduino_2022_B.Gain,
     &Modello_Arduino_2022_B.Gain_h, &Modello_Arduino_2022_B.h_Home, ((const
       uint16_T*) &Modello_Arduino_2022_U16GND),
     &Modello_Arduino_2022_B.SFunction_o1_g,
     &Modello_Arduino_2022_B.SFunction_o2_e[0],
     &Modello_Arduino_2022_B.SFunction_o3, &Modello_Arduino_2022_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (Modello_Arduino_2022_B.SFunction_o1_g > 0) {
    /* Chart: '<S15>/Chart' */
    if (Modello_Arduino_2022_DW.is_active_c9_Modello_Arduino_20 == 0U) {
      Modello_Arduino_2022_DW.is_active_c9_Modello_Arduino_20 = 1U;
      Modello_Arduino_2022_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (Modello_Arduino_2022_DW.obj_o.Protocol !=
            Modello_Arduino_2022_P.SerialTransmit_Protocol) {
          Modello_Arduino_2022_DW.obj_o.Protocol =
            Modello_Arduino_2022_P.SerialTransmit_Protocol;
        }

        status = Modello_Arduino_2022_B.SFunction_o2_e[Modello_Arduino_2022_DW.i
          - 1];
        MW_Serial_write(Modello_Arduino_2022_DW.obj_o.port, &status, 1.0,
                        Modello_Arduino_2022_DW.obj_o.dataSizeInBytes,
                        Modello_Arduino_2022_DW.obj_o.sendModeEnum,
                        Modello_Arduino_2022_DW.obj_o.dataType,
                        Modello_Arduino_2022_DW.obj_o.sendFormatEnum, 2.0,
                        '\x00');
        if (Modello_Arduino_2022_DW.i < Modello_Arduino_2022_B.SFunction_o3) {
          Modello_Arduino_2022_B.pipk = Modello_Arduino_2022_DW.i + 1;
          if (Modello_Arduino_2022_DW.i + 1 > 255) {
            Modello_Arduino_2022_B.pipk = 255;
          }

          Modello_Arduino_2022_DW.i = (uint8_T)Modello_Arduino_2022_B.pipk;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      Modello_Arduino_2022_DW.i = 1U;
    }

    /* End of Chart: '<S15>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S1>/Data Tversion' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 42;
       Modello_Arduino_2022_B.i++) {
    Modello_Arduino_2022_B.DataTypeConversion4_m[Modello_Arduino_2022_B.i] =
      Modello_Arduino_2022_DW.WP_dbP[Modello_Arduino_2022_B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Tversion' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem2' incorporates:
   *  EnablePort: '<S443>/Enable'
   */
  if (Modello_Arduino_2022_B.Wp_selector > 0.0) {
    /* Gain: '<S544>/Gain' */
    Modello_Arduino_2022_B.Gain_fd = Modello_Arduino_2022_P.Gain_Gain_ky *
      Modello_Arduino_2022_B.Gain1_nb;

    /* Gain: '<S545>/Gain' */
    Modello_Arduino_2022_B.Sum_ci = Modello_Arduino_2022_P.Gain_Gain_dg *
      Modello_Arduino_2022_B.Gain1_m;

    /* MATLAB Function: '<S443>/WAYPOINTS' incorporates:
     *  DataTypeConversion: '<S1>/Data Tversion'
     *  DataTypeConversion: '<S1>/Data Tversion1'
     *  DataTypeConversion: '<S1>/Data Tversion2'
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  Memory: '<S443>/Memory4'
     */
    Modello_Arduino_2022_B.pipk = 1;
    if (Modello_Arduino_2022_DW.Memory4_PreviousInput == 6.0) {
      Modello_Arduino_2022_B.pipk = 0;
    }

    if ((uint8_T)Modello_Arduino_2022_B.GC_info[0] == 3) {
      Modello_Arduino_2022_DW.Memory4_PreviousInput = 1.0;
      Modello_Arduino_2022_DW.lat1 = Modello_Arduino_2022_B.Gain_fd;
      Modello_Arduino_2022_DW.long1 = Modello_Arduino_2022_B.Sum_ci;
      for (Modello_Arduino_2022_B.tolleranza_distWP_fut = 0;
           Modello_Arduino_2022_B.tolleranza_distWP_fut < 6;
           Modello_Arduino_2022_B.tolleranza_distWP_fut++) {
        if (Modello_Arduino_2022_DW.WP_dbI[Modello_Arduino_2022_B.tolleranza_distWP_fut
            + 24] == 1) {
          Modello_Arduino_2022_DW.Memory4_PreviousInput = (real_T)
            Modello_Arduino_2022_B.tolleranza_distWP_fut + 1.0;
        }
      }
    }

    Modello_Arduino_2022_B.Wp_selector =
      Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
      Modello_Arduino_2022_DW.Memory4_PreviousInput + 23];
    Modello_Arduino_2022_B.Switch_i =
      Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
      Modello_Arduino_2022_DW.Memory4_PreviousInput + 29];
    Modello_Arduino_2022_B.QUOTA = Modello_Arduino_2022_B.DataTypeConversion4_m
      [(int32_T)Modello_Arduino_2022_DW.Memory4_PreviousInput + 35];
    Modello_Arduino_2022_B.a_n = sin((Modello_Arduino_2022_B.Wp_selector -
      Modello_Arduino_2022_B.Gain_fd) * 3.1415926535897931 / 180.0 / 2.0);
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = sin
      ((Modello_Arduino_2022_B.Switch_i - Modello_Arduino_2022_B.Sum_ci) *
       3.1415926535897931 / 180.0 / 2.0);
    Modello_Arduino_2022_B.Al_selector = Modello_Arduino_2022_B.Wp_selector *
      3.1415926535897931 / 180.0;
    Modello_Arduino_2022_B.PWM_aileron_p = cos
      (Modello_Arduino_2022_B.Al_selector);
    Modello_Arduino_2022_B.Abs1 = cos(Modello_Arduino_2022_B.Gain_fd *
      3.1415926535897931 / 180.0);
    Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.Abs1 *
      Modello_Arduino_2022_B.PWM_aileron_p *
      (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 *
       Modello_Arduino_2022_B.rtb_Gain1_d_idx_0) + Modello_Arduino_2022_B.a_n *
      Modello_Arduino_2022_B.a_n;
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = rt_atan2d_snf(sqrt
      (Modello_Arduino_2022_B.a_n), sqrt(1.0 - Modello_Arduino_2022_B.a_n)) *
      2.0 * 6.378137E+6;
    if (Modello_Arduino_2022_DW.Memory4_PreviousInput > 1.0) {
      Modello_Arduino_2022_B.a_tmp_tmp =
        Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
        (Modello_Arduino_2022_DW.Memory4_PreviousInput - 1.0) + 23];
      Modello_Arduino_2022_B.Al_selector = Modello_Arduino_2022_B.a_tmp_tmp *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.a_n = cos(Modello_Arduino_2022_B.Al_selector);
      Modello_Arduino_2022_B.dist =
        Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
        (Modello_Arduino_2022_DW.Memory4_PreviousInput - 1.0) + 29];
      Modello_Arduino_2022_B.psi_ref_tmp = (Modello_Arduino_2022_B.Switch_i -
        Modello_Arduino_2022_B.dist) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Al_selector = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.psi_ref_tmp) *
        Modello_Arduino_2022_B.PWM_aileron_p, sin
        (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         Modello_Arduino_2022_DW.Memory4_PreviousInput + 23] *
         3.1415926535897931 / 180.0) * Modello_Arduino_2022_B.a_n - sin
        (Modello_Arduino_2022_B.Al_selector) *
        Modello_Arduino_2022_B.PWM_aileron_p * cos
        (Modello_Arduino_2022_B.psi_ref_tmp)) * 180.0 / 3.1415926535897931;
      Modello_Arduino_2022_B.a_tmp_tmp = sin((Modello_Arduino_2022_B.Gain_fd -
        Modello_Arduino_2022_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Modello_Arduino_2022_B.dist = sin((Modello_Arduino_2022_B.Sum_ci -
        Modello_Arduino_2022_B.dist) * 3.1415926535897931 / 180.0 / 2.0);
      Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.a_n *
        Modello_Arduino_2022_B.Abs1 * (Modello_Arduino_2022_B.dist *
        Modello_Arduino_2022_B.dist) + Modello_Arduino_2022_B.a_tmp_tmp *
        Modello_Arduino_2022_B.a_tmp_tmp;
      Modello_Arduino_2022_B.dist = rt_atan2d_snf(sqrt
        (Modello_Arduino_2022_B.a_n), sqrt(1.0 - Modello_Arduino_2022_B.a_n)) *
        2.0 * 6.378137E+6;
    } else {
      Modello_Arduino_2022_B.a_n = (Modello_Arduino_2022_B.Switch_i -
        Modello_Arduino_2022_DW.long1) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.psi_ref_tmp = Modello_Arduino_2022_DW.lat1 *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Al_selector = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.a_n) * Modello_Arduino_2022_B.PWM_aileron_p, sin
        (Modello_Arduino_2022_B.Al_selector) * cos
        (Modello_Arduino_2022_B.psi_ref_tmp) - cos(Modello_Arduino_2022_B.a_n) *
        (sin(Modello_Arduino_2022_B.psi_ref_tmp) *
         Modello_Arduino_2022_B.PWM_aileron_p)) * 180.0 / 3.1415926535897931;
      Modello_Arduino_2022_B.dist = 0.0;
    }

    if (Modello_Arduino_2022_B.Al_selector < 0.0) {
      Modello_Arduino_2022_B.Al_selector = 360.0 - fabs
        (Modello_Arduino_2022_B.Al_selector);
    }

    if (Modello_Arduino_2022_B.pipk == 1) {
      Modello_Arduino_2022_B.psi_ref_tmp =
        Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
        (Modello_Arduino_2022_DW.Memory4_PreviousInput + 1.0) + 23];
      Modello_Arduino_2022_B.a_tmp_tmp = sin((Modello_Arduino_2022_B.psi_ref_tmp
        - Modello_Arduino_2022_B.Wp_selector) * 3.1415926535897931 / 180.0 / 2.0);
      Modello_Arduino_2022_B.b_a_tmp =
        (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         (Modello_Arduino_2022_DW.Memory4_PreviousInput + 1.0) + 29] -
         Modello_Arduino_2022_B.Switch_i) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.dist_fut = sin(Modello_Arduino_2022_B.b_a_tmp / 2.0);
      Modello_Arduino_2022_B.psi_ref_tmp = Modello_Arduino_2022_B.psi_ref_tmp *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.a_fut_tmp = cos(Modello_Arduino_2022_B.psi_ref_tmp);
      Modello_Arduino_2022_B.dist_fut = Modello_Arduino_2022_B.PWM_aileron_p *
        Modello_Arduino_2022_B.a_fut_tmp * (Modello_Arduino_2022_B.dist_fut *
        Modello_Arduino_2022_B.dist_fut) + Modello_Arduino_2022_B.a_tmp_tmp *
        Modello_Arduino_2022_B.a_tmp_tmp;
      Modello_Arduino_2022_B.dist_fut = rt_atan2d_snf(sqrt
        (Modello_Arduino_2022_B.dist_fut), sqrt(1.0 -
        Modello_Arduino_2022_B.dist_fut)) * 2.0 * 6.378137E+6;
      Modello_Arduino_2022_B.PWM_aileron_p = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.b_a_tmp) * Modello_Arduino_2022_B.a_fut_tmp, sin
        (Modello_Arduino_2022_B.psi_ref_tmp) *
        Modello_Arduino_2022_B.PWM_aileron_p - cos
        (Modello_Arduino_2022_B.b_a_tmp) * (sin
        (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         Modello_Arduino_2022_DW.Memory4_PreviousInput + 23] *
         3.1415926535897931 / 180.0) * Modello_Arduino_2022_B.a_fut_tmp)) *
        180.0 / 3.1415926535897931;
      if (Modello_Arduino_2022_B.PWM_aileron_p < 0.0) {
        Modello_Arduino_2022_B.PWM_aileron_p = 360.0 - fabs
          (Modello_Arduino_2022_B.PWM_aileron_p);
      }

      if (Modello_Arduino_2022_DW.Memory4_PreviousInput > 1.0) {
        Modello_Arduino_2022_B.PWM_aileron_p = fabs
          (Modello_Arduino_2022_B.PWM_aileron_p -
           Modello_Arduino_2022_B.Al_selector);
      } else {
        Modello_Arduino_2022_B.PWM_aileron_p = fabs
          (Modello_Arduino_2022_B.PWM_aileron_p - rt_atan2d_snf(sin
            ((Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
              Modello_Arduino_2022_DW.Memory4_PreviousInput + 29] -
              Modello_Arduino_2022_DW.long1) * 3.1415926535897931 / 180.0) * cos
            (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
             Modello_Arduino_2022_DW.Memory4_PreviousInput + 23] *
             3.1415926535897931 / 180.0), sin
            (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
             Modello_Arduino_2022_DW.Memory4_PreviousInput + 23] *
             3.1415926535897931 / 180.0) * cos(Modello_Arduino_2022_DW.lat1 *
             3.1415926535897931 / 180.0) - cos
            (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
             Modello_Arduino_2022_DW.Memory4_PreviousInput + 23] *
             3.1415926535897931 / 180.0) * sin(Modello_Arduino_2022_DW.lat1 *
             3.1415926535897931 / 180.0) * cos
            ((Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
              Modello_Arduino_2022_DW.Memory4_PreviousInput + 29] -
              Modello_Arduino_2022_DW.long1) * 3.1415926535897931 / 180.0)) *
           180.0 / 3.1415926535897931);
      }
    } else {
      Modello_Arduino_2022_B.dist_fut = 0.0;
      Modello_Arduino_2022_B.PWM_aileron_p = 0.0;
    }

    if (Modello_Arduino_2022_DW.Memory4_PreviousInput < 2.0) {
      Modello_Arduino_2022_B.Abs1 = 0.0;
    } else if (Modello_Arduino_2022_DW.Memory4_PreviousInput == 2.0) {
      Modello_Arduino_2022_B.a_n = Modello_Arduino_2022_B.DataTypeConversion4_m
        [24] * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.b_a_tmp = cos(Modello_Arduino_2022_B.a_n);
      Modello_Arduino_2022_B.Gain_fd =
        (Modello_Arduino_2022_B.DataTypeConversion4_m[30] -
         Modello_Arduino_2022_DW.long1) * 3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Abs1 = fabs(Modello_Arduino_2022_B.Al_selector -
        rt_atan2d_snf(sin(Modello_Arduino_2022_B.Gain_fd) *
                      Modello_Arduino_2022_B.b_a_tmp, cos
                      (Modello_Arduino_2022_DW.lat1 * 3.1415926535897931 / 180.0)
                      * sin(Modello_Arduino_2022_B.a_n) - sin
                      (Modello_Arduino_2022_DW.lat1 * 3.1415926535897931 / 180.0)
                      * Modello_Arduino_2022_B.b_a_tmp * cos
                      (Modello_Arduino_2022_B.Gain_fd)) * 180.0 /
        3.1415926535897931);
    } else {
      Modello_Arduino_2022_B.Abs1 = cos
        (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         (Modello_Arduino_2022_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0);
      Modello_Arduino_2022_B.Sum_ci =
        Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
        (Modello_Arduino_2022_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Gain_fd =
        (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         (Modello_Arduino_2022_DW.Memory4_PreviousInput - 1.0) + 29] -
         Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         (Modello_Arduino_2022_DW.Memory4_PreviousInput - 2.0) + 29]) *
        3.1415926535897931 / 180.0;
      Modello_Arduino_2022_B.Abs1 = rt_atan2d_snf(sin
        (Modello_Arduino_2022_B.Gain_fd) * Modello_Arduino_2022_B.Abs1, cos
        (Modello_Arduino_2022_B.Sum_ci) * sin
        (Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
         (Modello_Arduino_2022_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0) - sin(Modello_Arduino_2022_B.Sum_ci) *
        Modello_Arduino_2022_B.Abs1 * cos(Modello_Arduino_2022_B.Gain_fd)) *
        180.0 / 3.1415926535897931;
      if (Modello_Arduino_2022_B.Abs1 < 0.0) {
        Modello_Arduino_2022_B.Abs1 = 360.0 - fabs(Modello_Arduino_2022_B.Abs1);
      }

      Modello_Arduino_2022_B.Abs1 = fabs(Modello_Arduino_2022_B.Al_selector -
        Modello_Arduino_2022_B.Abs1);
    }

    if (Modello_Arduino_2022_B.PWM_aileron_p <= 10.0) {
      Modello_Arduino_2022_B.Al_selector = 40.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 10;
    } else if ((Modello_Arduino_2022_B.PWM_aileron_p > 10.0) &&
               (Modello_Arduino_2022_B.PWM_aileron_p <= 50.0)) {
      Modello_Arduino_2022_B.Al_selector = 60.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 15;
    } else if ((Modello_Arduino_2022_B.PWM_aileron_p > 50.0) &&
               (Modello_Arduino_2022_B.PWM_aileron_p <= 90.0)) {
      Modello_Arduino_2022_B.Al_selector = 80.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 20;
    } else if ((Modello_Arduino_2022_B.PWM_aileron_p > 90.0) &&
               (Modello_Arduino_2022_B.PWM_aileron_p <= 120.0)) {
      Modello_Arduino_2022_B.Al_selector = 120.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 25;
    } else {
      Modello_Arduino_2022_B.Al_selector = 150.0;
      Modello_Arduino_2022_B.tolleranza_distWP_fut = 30;
    }

    if (Modello_Arduino_2022_B.Abs1 <= 10.0) {
      Modello_Arduino_2022_B.soglia_dist = 50;
    } else if ((Modello_Arduino_2022_B.Abs1 > 10.0) &&
               (Modello_Arduino_2022_B.Abs1 <= 50.0)) {
      Modello_Arduino_2022_B.soglia_dist = 200;
    } else if ((Modello_Arduino_2022_B.Abs1 > 50.0) &&
               (Modello_Arduino_2022_B.Abs1 <= 90.0)) {
      Modello_Arduino_2022_B.soglia_dist = 300;
    } else if ((Modello_Arduino_2022_B.Abs1 > 90.0) &&
               (Modello_Arduino_2022_B.Abs1 <= 120.0)) {
      Modello_Arduino_2022_B.soglia_dist = 350;
    } else {
      Modello_Arduino_2022_B.soglia_dist = 400;
    }

    if (Modello_Arduino_2022_B.pipk == 1) {
      Modello_Arduino_2022_B.VELOCITA =
        Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
        Modello_Arduino_2022_DW.Memory4_PreviousInput + 11];
      if (Modello_Arduino_2022_B.VELOCITA < 15.0) {
        Modello_Arduino_2022_B.VELOCITA = 25.0;
      }

      if (!(Modello_Arduino_2022_B.VELOCITA <= 20.0)) {
        if (Modello_Arduino_2022_B.VELOCITA <= 25.0) {
          Modello_Arduino_2022_B.Al_selector *= 1.2;
        } else if (Modello_Arduino_2022_B.VELOCITA <= 30.0) {
          Modello_Arduino_2022_B.Al_selector *= 1.3;
        } else {
          Modello_Arduino_2022_B.Al_selector *= 1.4;
        }
      }

      if (((!(Modello_Arduino_2022_B.dist < Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 >
                 Modello_Arduino_2022_B.Al_selector))) &&
          ((!(Modello_Arduino_2022_B.dist > Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 >
                 Modello_Arduino_2022_B.Al_selector))) &&
          (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 <
           Modello_Arduino_2022_B.Al_selector)) {
        if (Modello_Arduino_2022_B.dist_fut >
            Modello_Arduino_2022_B.tolleranza_distWP_fut) {
          Modello_Arduino_2022_DW.Memory4_PreviousInput++;
        } else if (Modello_Arduino_2022_DW.Memory4_PreviousInput < 5.0) {
          Modello_Arduino_2022_DW.Memory4_PreviousInput += 2.0;
        } else {
          Modello_Arduino_2022_B.VELOCITA = 22.0;
          Modello_Arduino_2022_B.QUOTA = Modello_Arduino_2022_B.ByteUnpack_o2_h
            [2] + 0.4;
        }
      }

      Modello_Arduino_2022_DW.flag_j = 0.0;
    } else {
      Modello_Arduino_2022_B.VELOCITA =
        Modello_Arduino_2022_B.DataTypeConversion4_m[(int32_T)
        Modello_Arduino_2022_DW.Memory4_PreviousInput + 11];
      if (Modello_Arduino_2022_B.VELOCITA < 15.0) {
        Modello_Arduino_2022_B.VELOCITA = 25.0;
      }

      if (((!(Modello_Arduino_2022_B.dist < Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_DW.flag_j == 0.0))) &&
          ((!(Modello_Arduino_2022_B.dist > Modello_Arduino_2022_B.soglia_dist))
           || (!(Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 > 40.0)) ||
           (!(Modello_Arduino_2022_DW.flag_j == 0.0)))) {
        Modello_Arduino_2022_B.VELOCITA = 22.0;
        Modello_Arduino_2022_B.QUOTA = Modello_Arduino_2022_B.ByteUnpack_o2_h[2]
          + 0.4;
        Modello_Arduino_2022_DW.flag_j = 1.0;
      }
    }

    if ((Modello_Arduino_2022_B.Wp_selector == 0.0) &&
        (Modello_Arduino_2022_B.Switch_i == 0.0) &&
        (Modello_Arduino_2022_B.QUOTA == 0.0)) {
      Modello_Arduino_2022_B.QUOTA = Modello_Arduino_2022_B.ByteUnpack_o2_h[2] +
        0.3;
      Modello_Arduino_2022_B.VELOCITA = 22.0;
    }

    /* Saturate: '<S443>/saturatore V' incorporates:
     *  MATLAB Function: '<S443>/WAYPOINTS'
     */
    if (Modello_Arduino_2022_B.VELOCITA >
        Modello_Arduino_2022_P.saturatoreV_UpperSat) {
      /* Saturate: '<S443>/saturatore V' */
      Modello_Arduino_2022_B.VELOCITA =
        Modello_Arduino_2022_P.saturatoreV_UpperSat;
    } else {
      if (Modello_Arduino_2022_B.VELOCITA <
          Modello_Arduino_2022_P.saturatoreV_LowerSat) {
        /* Saturate: '<S443>/saturatore V' */
        Modello_Arduino_2022_B.VELOCITA =
          Modello_Arduino_2022_P.saturatoreV_LowerSat;
      }
    }

    /* End of Saturate: '<S443>/saturatore V' */
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem' incorporates:
   *  EnablePort: '<S441>/Enable'
   */
  if (Modello_Arduino_2022_B.Vec_selector > 0.0) {
    /* DataTypeConversion: '<S441>/Data Type Conversion3' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    Modello_Arduino_2022_B.Sum_ax = Modello_Arduino_2022_DW.riferimenti[10];

    /* MATLAB Function: '<S441>/VETTORIALE' incorporates:
     *  DataTypeConversion: '<S556>/Data Type Conversion5'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     *  Memory: '<S441>/Memory1'
     *  Memory: '<S441>/Memory2'
     *  Memory: '<S441>/Memory3'
     *  Memory: '<S441>/Memory6'
     */
    if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] !=
         Modello_Arduino_2022_DW.Memory6_PreviousInput) ||
        (Modello_Arduino_2022_B.modo !=
         Modello_Arduino_2022_DW.Memory3_PreviousInput) ||
        (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] !=
         Modello_Arduino_2022_DW.Memory2_PreviousInput_e)) {
      Modello_Arduino_2022_DW.V_ref = Modello_Arduino_2022_B.Product1;
    }

    if ((Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] !=
         Modello_Arduino_2022_DW.Memory6_PreviousInput) ||
        (Modello_Arduino_2022_B.modo !=
         Modello_Arduino_2022_DW.Memory3_PreviousInput) ||
        (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] !=
         Modello_Arduino_2022_DW.Memory1_PreviousInput_o)) {
      Modello_Arduino_2022_DW.ALT_ref = Modello_Arduino_2022_B.ByteUnpack_o2_h[2];
    }

    if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3] == 1) {
      Modello_Arduino_2022_B.V_vett = Modello_Arduino_2022_DW.riferimenti[8];
    } else {
      Modello_Arduino_2022_B.V_vett = Modello_Arduino_2022_DW.V_ref;
    }

    if (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4] == 1) {
      Modello_Arduino_2022_B.h_vett = Modello_Arduino_2022_DW.riferimenti[9];
    } else {
      Modello_Arduino_2022_B.h_vett = Modello_Arduino_2022_DW.ALT_ref;
    }

    /* Update for Memory: '<S441>/Memory1' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_o =
      Modello_Arduino_2022_DW.Memory2_PreviousInput_a[4];

    /* Update for Memory: '<S441>/Memory2' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Modello_Arduino_2022_DW.Memory2_PreviousInput_e =
      Modello_Arduino_2022_DW.Memory2_PreviousInput_a[3];

    /* Update for Memory: '<S441>/Memory3' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Modello_Arduino_2022_DW.Memory3_PreviousInput = Modello_Arduino_2022_B.modo;

    /* Update for Memory: '<S441>/Memory6' incorporates:
     *  MATLAB Function: '<S441>/VETTORIALE'
     */
    Modello_Arduino_2022_DW.Memory6_PreviousInput =
      Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1];
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem3' incorporates:
   *  EnablePort: '<S444>/Enable'
   */
  if (Modello_Arduino_2022_B.Go_home_selector > 0.0) {
    /* Gain: '<S549>/Gain' */
    Modello_Arduino_2022_B.Gain1_nb *= Modello_Arduino_2022_P.Gain_Gain_jv;

    /* MATLAB Function: '<S444>/GO_HOME' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant1'
     *  Gain: '<S550>/Gain'
     */
    Modello_Arduino_2022_B.a_n = sin((0.0 - Modello_Arduino_2022_B.Gain1_nb) *
      3.1415926535897931 / 180.0 / 2.0);
    Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 = sin((0.0 -
      Modello_Arduino_2022_P.Gain_Gain_ii * Modello_Arduino_2022_B.Gain1_m) *
      3.1415926535897931 / 180.0 / 2.0);
    Modello_Arduino_2022_B.a_n = cos(Modello_Arduino_2022_B.Gain1_nb *
      3.1415926535897931 / 180.0) * (Modello_Arduino_2022_B.rtb_Gain1_d_idx_0 *
      Modello_Arduino_2022_B.rtb_Gain1_d_idx_0) + Modello_Arduino_2022_B.a_n *
      Modello_Arduino_2022_B.a_n;
    Modello_Arduino_2022_B.h_goHome = Modello_Arduino_2022_P.Constant_Value_p;
    Modello_Arduino_2022_B.V_goHome = Modello_Arduino_2022_P.Constant1_Value_lp;
    if ((rt_atan2d_snf(sqrt(Modello_Arduino_2022_B.a_n), sqrt(1.0 -
           Modello_Arduino_2022_B.a_n)) * 2.0 * 6.378137E+6 < 30.0) &&
        (Modello_Arduino_2022_DW.flag == 0.0)) {
      Modello_Arduino_2022_DW.flag = 1.0;
      Modello_Arduino_2022_B.h_goHome = Modello_Arduino_2022_P.Constant_Value_p
        + 0.4;
    }

    /* End of MATLAB Function: '<S444>/GO_HOME' */
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem3' */

  /* MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' */
  switch ((int32_T)Modello_Arduino_2022_B.modo) {
   case 1:
    Modello_Arduino_2022_B.Gain1_m = Modello_Arduino_2022_B.QUOTA;
    break;

   case 2:
    Modello_Arduino_2022_B.Gain1_m = Modello_Arduino_2022_B.h_vett;
    break;

   case 3:
    Modello_Arduino_2022_B.Gain1_m = Modello_Arduino_2022_B.h_ref;
    break;

   case 4:
    Modello_Arduino_2022_B.Gain1_m = Modello_Arduino_2022_B.QUOTA_f;
    break;

   default:
    Modello_Arduino_2022_B.Gain1_m = Modello_Arduino_2022_B.h_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' */

  /* Abs: '<S40>/Abs' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion5'
   *  Sum: '<S40>/Sum1'
   */
  Modello_Arduino_2022_B.Gain1_nb = fabs(Modello_Arduino_2022_B.Gain1_m -
    Modello_Arduino_2022_B.ByteUnpack_o2_h[2]);

  /* Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  if (Modello_Arduino_2022_DW.is_active_c23_Modello_Arduino_2 == 0U) {
    Modello_Arduino_2022_DW.is_active_c23_Modello_Arduino_2 = 1U;
    Modello_Arduino_2022_DW.is_c23_Modello_Arduino_2022 =
      Modello_Arduino_2022_IN_Select;
  } else if (Modello_Arduino_2022_DW.is_c23_Modello_Arduino_2022 == 1) {
    if (Modello_Arduino_2022_B.Gain1_nb > 10.0) {
      Modello_Arduino_2022_DW.is_c23_Modello_Arduino_2022 =
        Modello_Arduino_2022_IN_Select;
    }
  } else {
    /* case IN_Select: */
    if (Modello_Arduino_2022_B.Gain1_nb < 10.0) {
      Modello_Arduino_2022_DW.is_c23_Modello_Arduino_2022 =
        Modello_Arduino_2022_IN_Hold;
    }
  }

  /* End of Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */

  /* MATLABSystem: '<S570>/Serial Receive1' */
  if (Modello_Arduino_2022_DW.obj_e.Protocol !=
      Modello_Arduino_2022_P.SerialReceive1_Protocol) {
    Modello_Arduino_2022_DW.obj_e.Protocol =
      Modello_Arduino_2022_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(0, Modello_Arduino_2022_DW.obj_e.DataSizeInBytes,
                 &Modello_Arduino_2022_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S570>/Subsystem2' incorporates:
   *  EnablePort: '<S581>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S581>/Create_message' */
    status = 0U;
    if (!Modello_Arduino_2022_DW.start_found) {
      Modello_Arduino_2022_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (Modello_Arduino_2022_B.i - 1 < 32)) {
        if (Modello_Arduino_2022_B.b_dataOut[(uint8_T)Modello_Arduino_2022_B.i -
            1] == 36) {
          Modello_Arduino_2022_B.tolleranza_distWP_fut = 32 - (uint8_T)
            Modello_Arduino_2022_B.i;
          for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
               Modello_Arduino_2022_B.tolleranza_distWP_fut;
               Modello_Arduino_2022_B.pipk++) {
            Modello_Arduino_2022_DW.message[Modello_Arduino_2022_B.pipk] =
              Modello_Arduino_2022_B.b_dataOut[((uint8_T)
              Modello_Arduino_2022_B.i + Modello_Arduino_2022_B.pipk) - 1];
          }

          Modello_Arduino_2022_DW.counter_k = (uint8_T)(33 - (uint8_T)
            Modello_Arduino_2022_B.i);
          Modello_Arduino_2022_DW.start_found = true;
          exitg1 = true;
        } else {
          Modello_Arduino_2022_B.i++;
        }
      }
    } else {
      Modello_Arduino_2022_B.f = 1;
      exitg1 = false;
      while ((!exitg1) && (Modello_Arduino_2022_B.f - 1 < 32)) {
        if (Modello_Arduino_2022_B.b_dataOut[(uint8_T)Modello_Arduino_2022_B.f -
            1] == 13) {
          Modello_Arduino_2022_DW.end_found = true;
          status = (uint8_T)Modello_Arduino_2022_B.f;
          exitg1 = true;
        } else {
          Modello_Arduino_2022_B.f++;
        }
      }

      if (Modello_Arduino_2022_DW.end_found) {
        if (1 > status) {
          Modello_Arduino_2022_B.tolleranza_distWP_fut = -1;
        } else {
          Modello_Arduino_2022_B.tolleranza_distWP_fut = status - 1;
        }

        for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
             Modello_Arduino_2022_B.tolleranza_distWP_fut;
             Modello_Arduino_2022_B.pipk++) {
          Modello_Arduino_2022_B.f = (int32_T)(((uint32_T)
            Modello_Arduino_2022_B.pipk + Modello_Arduino_2022_DW.counter_k) +
            1U);
          if ((uint32_T)Modello_Arduino_2022_B.f > 255U) {
            Modello_Arduino_2022_B.f = 255;
          }

          Modello_Arduino_2022_DW.message[Modello_Arduino_2022_B.f - 1] =
            Modello_Arduino_2022_B.b_dataOut[Modello_Arduino_2022_B.pipk];
        }

        memcpy(&Modello_Arduino_2022_B.messaggio_b[0],
               &Modello_Arduino_2022_DW.message[0], 80U * sizeof(uint8_T));
        Modello_Arduino_2022_DW.end_found = false;
        Modello_Arduino_2022_DW.counter_k = (uint8_T)(32 - status);
        if (status == 32) {
          Modello_Arduino_2022_DW.start_found = false;
          memset(&Modello_Arduino_2022_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          Modello_Arduino_2022_DW.start_found = true;
          Modello_Arduino_2022_B.tolleranza_distWP_fut = -status;
          for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <=
               Modello_Arduino_2022_B.tolleranza_distWP_fut + 31;
               Modello_Arduino_2022_B.pipk++) {
            Modello_Arduino_2022_DW.message[Modello_Arduino_2022_B.pipk] =
              Modello_Arduino_2022_B.b_dataOut[status +
              Modello_Arduino_2022_B.pipk];
          }

          Modello_Arduino_2022_B.pipk = status + 48;
          if (0 <= Modello_Arduino_2022_B.pipk - 1) {
            memset(&Modello_Arduino_2022_DW.message[-status + 32], 0,
                   ((Modello_Arduino_2022_B.pipk - status) + status) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S581>/Subsystem' incorporates:
         *  EnablePort: '<S583>/Enable'
         */
        /* MATLAB Function: '<S583>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        Modello_Arduino_2022_B.indice_dimario = 0U;
        for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 80;
             Modello_Arduino_2022_B.i++) {
          messaggio = (int8_T)
            Modello_Arduino_2022_B.messaggio_b[Modello_Arduino_2022_B.i];
          if (messaggio == '$') {
            Modello_Arduino_2022_B.pipk = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              Modello_Arduino_2022_B.pipk = 255;
            }

            status = (uint8_T)Modello_Arduino_2022_B.pipk;
          }

          if (messaggio == ',') {
            Modello_Arduino_2022_B.pipk = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              Modello_Arduino_2022_B.pipk = 255;
            }

            find_comma = (uint8_T)Modello_Arduino_2022_B.pipk;
          }

          Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.i] =
            messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 80;
               Modello_Arduino_2022_B.pipk++) {
            Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
              (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk] ==
               '$');
          }

          Modello_Arduino_2022_eml_find(Modello_Arduino_2022_B.messaggio_c,
            &Modello_Arduino_2022_B.eb_data, Modello_Arduino_2022_B.eb_size);
          Modello_Arduino_2022_B.tolleranza_distWP_fut =
            Modello_Arduino_2022_B.eb_data;
          for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk < 5;
               Modello_Arduino_2022_B.pipk++) {
            messaggio =
              Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk +
              Modello_Arduino_2022_B.tolleranza_distWP_fut];
            Modello_Arduino_2022_B.mess_type_n[Modello_Arduino_2022_B.pipk] =
              (messaggio == bb[Modello_Arduino_2022_B.pipk]);
            Modello_Arduino_2022_B.mess_type[Modello_Arduino_2022_B.pipk] =
              messaggio;
          }

          if (Modello_Arduino_2_ifWhileCond_o(Modello_Arduino_2022_B.mess_type_n))
          {
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 80; Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
                (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk]
                 == ',');
            }

            Modello_Arduino_2022_eml_find_o(Modello_Arduino_2022_B.messaggio_c,
              Modello_Arduino_2022_B.comma_gga_data,
              Modello_Arduino_2022_B.eb_size);
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 80; Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
                (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk]
                 == '*');
            }

            Modello_Arduino_2022_eml_find_o(Modello_Arduino_2022_B.messaggio_c,
              Modello_Arduino_2022_B.star_data, Modello_Arduino_2022_B.star_size);
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 80; Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
                (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk]
                 == '$');
            }

            Modello_Arduino_2022_eml_find_o(Modello_Arduino_2022_B.messaggio_c,
              Modello_Arduino_2022_B.fb_data, Modello_Arduino_2022_B.star_size);
            Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_2022_str2double
              (&Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.comma_gga_data
               [2]]);
            if ((real_T)Modello_Arduino_2022_B.comma_gga_data[2] + 3.0 > (real_T)
                Modello_Arduino_2022_B.comma_gga_data[3] - 1.0) {
              Modello_Arduino_2022_B.c = 0;
              Modello_Arduino_2022_B.pipk = 0;
            } else {
              Modello_Arduino_2022_B.c = Modello_Arduino_2022_B.comma_gga_data[2]
                + 2;
              Modello_Arduino_2022_B.pipk =
                Modello_Arduino_2022_B.comma_gga_data[3] - 1;
            }

            Modello_Arduino_2022_B.messaggio_size[0] = 1;
            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.c;
            Modello_Arduino_2022_B.messaggio_size[1] =
              Modello_Arduino_2022_B.tolleranza_distWP_fut;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                = Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.c +
                Modello_Arduino_2022_B.pipk];
            }

            Modello_Arduino_2022_B.b_x = Modello_Arduino_20_str2double_l
              (Modello_Arduino_2022_B.messaggio_data,
               Modello_Arduino_2022_B.messaggio_size);
            if (Modello_Arduino_2022_B.b_x.im == 0.0) {
              Modello_Arduino_2022_B.Go_home_selector =
                Modello_Arduino_2022_B.b_x.re / 60.0;
            } else if (Modello_Arduino_2022_B.b_x.re == 0.0) {
              Modello_Arduino_2022_B.Go_home_selector = 0.0;
            } else {
              Modello_Arduino_2022_B.Go_home_selector =
                Modello_Arduino_2022_B.b_x.re / 60.0;
            }

            Modello_Arduino_2022_B.Gain1_nb = Modello_Arduino_2022_B.Lat_1.re +
              Modello_Arduino_2022_B.Go_home_selector;
            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.eb_size[0] *
              Modello_Arduino_2022_B.eb_size[1] - 1;
            if (0 <= Modello_Arduino_2022_B.tolleranza_distWP_fut) {
              memcpy(&Modello_Arduino_2022_B.tmp_data[0],
                     &Modello_Arduino_2022_B.comma_gga_data[0],
                     (Modello_Arduino_2022_B.tolleranza_distWP_fut + 1) * sizeof
                     (int32_T));
            }

            if (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.tmp_data
                [3]] == 'S') {
              Modello_Arduino_2022_B.Gain1_nb = -Modello_Arduino_2022_B.Gain1_nb;
            }

            Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_2_str2double_lv
              (&Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.comma_gga_data
               [4]]);
            if ((real_T)Modello_Arduino_2022_B.comma_gga_data[4] + 4.0 > (real_T)
                Modello_Arduino_2022_B.comma_gga_data[5] - 1.0) {
              Modello_Arduino_2022_B.f = 0;
              Modello_Arduino_2022_B.i = 0;
            } else {
              Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.comma_gga_data[4]
                + 3;
              Modello_Arduino_2022_B.i = Modello_Arduino_2022_B.comma_gga_data[5]
                - 1;
            }

            Modello_Arduino_2022_B.messaggio_size_c[0] = 1;
            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.i - Modello_Arduino_2022_B.f;
            Modello_Arduino_2022_B.messaggio_size_c[1] =
              Modello_Arduino_2022_B.tolleranza_distWP_fut;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                = Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.f +
                Modello_Arduino_2022_B.pipk];
            }

            Modello_Arduino_2022_B.b_x = Modello_Arduino_20_str2double_l
              (Modello_Arduino_2022_B.messaggio_data,
               Modello_Arduino_2022_B.messaggio_size_c);
            if (Modello_Arduino_2022_B.b_x.im == 0.0) {
              Modello_Arduino_2022_B.Go_home_selector =
                Modello_Arduino_2022_B.b_x.re / 60.0;
            } else if (Modello_Arduino_2022_B.b_x.re == 0.0) {
              Modello_Arduino_2022_B.Go_home_selector = 0.0;
            } else {
              Modello_Arduino_2022_B.Go_home_selector =
                Modello_Arduino_2022_B.b_x.re / 60.0;
            }

            Modello_Arduino_2022_B.Go_home_selector +=
              Modello_Arduino_2022_B.Lat_1.re;
            if (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.tmp_data
                [5]] == 'W') {
              Modello_Arduino_2022_B.Go_home_selector =
                -Modello_Arduino_2022_B.Go_home_selector;
            }

            if ((real_T)Modello_Arduino_2022_B.comma_gga_data[6] + 1.0 > (real_T)
                Modello_Arduino_2022_B.comma_gga_data[7] - 1.0) {
              Modello_Arduino_2022_B.soglia_dist = 0;
              Modello_Arduino_2022_B.f = 0;
            } else {
              Modello_Arduino_2022_B.soglia_dist =
                Modello_Arduino_2022_B.comma_gga_data[6];
              Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.comma_gga_data[7]
                - 1;
            }

            Modello_Arduino_2022_B.messaggio_size_f[0] = 1;
            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.f - Modello_Arduino_2022_B.soglia_dist;
            Modello_Arduino_2022_B.messaggio_size_f[1] =
              Modello_Arduino_2022_B.tolleranza_distWP_fut;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                =
                Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                + Modello_Arduino_2022_B.pipk];
            }

            Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_20_str2double_l
              (Modello_Arduino_2022_B.messaggio_data,
               Modello_Arduino_2022_B.messaggio_size_f);

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Modello_Arduino_2022_B.ComplextoRealImag[2] =
              Modello_Arduino_2022_B.Lat_1.re;
            if ((real_T)Modello_Arduino_2022_B.comma_gga_data[7] + 1.0 > (real_T)
                Modello_Arduino_2022_B.comma_gga_data[8] - 1.0) {
              Modello_Arduino_2022_B.soglia_dist = 0;
              Modello_Arduino_2022_B.pipk = 0;
            } else {
              Modello_Arduino_2022_B.soglia_dist =
                Modello_Arduino_2022_B.comma_gga_data[7];
              Modello_Arduino_2022_B.pipk =
                Modello_Arduino_2022_B.comma_gga_data[8] - 1;
            }

            Modello_Arduino_2022_B.messaggio_size_g[0] = 1;
            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
            Modello_Arduino_2022_B.messaggio_size_g[1] =
              Modello_Arduino_2022_B.tolleranza_distWP_fut;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                =
                Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                + Modello_Arduino_2022_B.pipk];
            }

            Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_20_str2double_l
              (Modello_Arduino_2022_B.messaggio_data,
               Modello_Arduino_2022_B.messaggio_size_g);

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Modello_Arduino_2022_B.ComplextoRealImag[4] =
              Modello_Arduino_2022_B.Lat_1.re;
            if ((real_T)Modello_Arduino_2022_B.comma_gga_data[9] + 1.0 > (real_T)
                Modello_Arduino_2022_B.comma_gga_data[10] - 1.0) {
              Modello_Arduino_2022_B.soglia_dist = 0;
              Modello_Arduino_2022_B.pipk = 0;
            } else {
              Modello_Arduino_2022_B.soglia_dist =
                Modello_Arduino_2022_B.comma_gga_data[9];
              Modello_Arduino_2022_B.pipk =
                Modello_Arduino_2022_B.comma_gga_data[10] - 1;
            }

            Modello_Arduino_2022_B.messaggio_size_g1[0] = 1;
            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
            Modello_Arduino_2022_B.messaggio_size_g1[1] =
              Modello_Arduino_2022_B.tolleranza_distWP_fut;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                =
                Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                + Modello_Arduino_2022_B.pipk];
            }

            Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_20_str2double_l
              (Modello_Arduino_2022_B.messaggio_data,
               Modello_Arduino_2022_B.messaggio_size_g1);

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Modello_Arduino_2022_B.ComplextoRealImag[3] =
              Modello_Arduino_2022_B.Lat_1.re;
            if (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.tmp_data
                [10]] == 'W') {
              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[3] =
                -Modello_Arduino_2022_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
            Modello_Arduino_2022_B.ComplextoRealImag[5] =
              Modello_Arduino_2022_DW.Memory_PreviousInput_l[5];
            Modello_Arduino_2022_B.ComplextoRealImag[6] =
              Modello_Arduino_2022_DW.Memory_PreviousInput_l[6];
            Modello_Arduino_2022_B.ComplextoRealImag[7] =
              Modello_Arduino_2022_DW.Memory_PreviousInput_l[7];
            Modello_Arduino_2022_B.ComplextoRealImag[8] =
              Modello_Arduino_2022_DW.Memory_PreviousInput_l[8];
            if ((real_T)Modello_Arduino_2022_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)Modello_Arduino_2022_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)Modello_Arduino_2022_B.star_data[0] +
                                   1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = Modello_Arduino_2022_B.messaggio_k[status - 1];
            if ((real_T)Modello_Arduino_2022_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)Modello_Arduino_2022_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)Modello_Arduino_2022_B.star_data[0] +
                                   2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = Modello_Arduino_2022_B.messaggio_k[status - 1];
            if ((real_T)Modello_Arduino_2022_B.fb_data[0] + 1.0 > (real_T)
                Modello_Arduino_2022_B.star_data[0] - 1.0) {
              Modello_Arduino_2022_B.f = 0;
              Modello_Arduino_2022_B.soglia_dist = 0;
            } else {
              Modello_Arduino_2022_B.f = Modello_Arduino_2022_B.fb_data[0];
              Modello_Arduino_2022_B.soglia_dist =
                Modello_Arduino_2022_B.star_data[0] - 1;
            }

            Modello_Arduino_2022_B.tolleranza_distWP_fut =
              Modello_Arduino_2022_B.soglia_dist - Modello_Arduino_2022_B.f;
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 Modello_Arduino_2022_B.tolleranza_distWP_fut;
                 Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.NMEA_gga_string_data[Modello_Arduino_2022_B.pipk]
                = (uint8_T)
                Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.f +
                Modello_Arduino_2022_B.pipk];
            }

            status = 0U;
            Modello_Arduino_2022_B.f = 0;
            while (Modello_Arduino_2022_B.f <=
                   Modello_Arduino_2022_B.tolleranza_distWP_fut - 1) {
              status ^=
                Modello_Arduino_2022_B.NMEA_gga_string_data[Modello_Arduino_2022_B.f];
              Modello_Arduino_2022_B.f++;
            }

            if (status != Modello_Arduino_2022_hex2dec(ck_ric)) {
              Modello_Arduino_2022_B.Gain1_nb =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[0];
              Modello_Arduino_2022_B.Go_home_selector =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[2] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[2];
              Modello_Arduino_2022_B.ComplextoRealImag[3] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[3];
              Modello_Arduino_2022_B.ComplextoRealImag[4] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[4];
              Modello_Arduino_2022_B.indice_dimario = 10U;
            }
          } else {
            for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                 5; Modello_Arduino_2022_B.pipk++) {
              Modello_Arduino_2022_B.mess_type_n[Modello_Arduino_2022_B.pipk] =
                (Modello_Arduino_2022_B.mess_type[Modello_Arduino_2022_B.pipk] ==
                 cb[Modello_Arduino_2022_B.pipk]);
            }

            if (Modello_Arduino_2_ifWhileCond_o
                (Modello_Arduino_2022_B.mess_type_n)) {
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   80; Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
                  (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk]
                   == ',');
              }

              Modello_Arduino_2022_eml_find_o(Modello_Arduino_2022_B.messaggio_c,
                Modello_Arduino_2022_B.comma_gga_data,
                Modello_Arduino_2022_B.eb_size);
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   80; Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
                  (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk]
                   == '*');
              }

              Modello_Arduino_2022_eml_find_o(Modello_Arduino_2022_B.messaggio_c,
                Modello_Arduino_2022_B.star_data,
                Modello_Arduino_2022_B.star_size);
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   80; Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_c[Modello_Arduino_2022_B.pipk] =
                  (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.pipk]
                   == '$');
              }

              Modello_Arduino_2022_eml_find_o(Modello_Arduino_2022_B.messaggio_c,
                Modello_Arduino_2022_B.fb_data, Modello_Arduino_2022_B.star_size);
              Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_2022_str2double
                (&Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.comma_gga_data
                 [1]]);
              if ((real_T)Modello_Arduino_2022_B.comma_gga_data[1] + 3.0 >
                  (real_T)Modello_Arduino_2022_B.comma_gga_data[2] - 1.0) {
                Modello_Arduino_2022_B.soglia_dist = 0;
                Modello_Arduino_2022_B.pipk = 0;
              } else {
                Modello_Arduino_2022_B.soglia_dist =
                  Modello_Arduino_2022_B.comma_gga_data[1] + 2;
                Modello_Arduino_2022_B.pipk =
                  Modello_Arduino_2022_B.comma_gga_data[2] - 1;
              }

              Modello_Arduino_2022_B.messaggio_size[0] = 1;
              Modello_Arduino_2022_B.tolleranza_distWP_fut =
                Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.messaggio_size[1] =
                Modello_Arduino_2022_B.tolleranza_distWP_fut;
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   Modello_Arduino_2022_B.tolleranza_distWP_fut;
                   Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                  =
                  Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                  + Modello_Arduino_2022_B.pipk];
              }

              Modello_Arduino_2022_B.b_x = Modello_Arduino_20_str2double_l
                (Modello_Arduino_2022_B.messaggio_data,
                 Modello_Arduino_2022_B.messaggio_size);
              if (Modello_Arduino_2022_B.b_x.im == 0.0) {
                Modello_Arduino_2022_B.Go_home_selector =
                  Modello_Arduino_2022_B.b_x.re / 60.0;
              } else if (Modello_Arduino_2022_B.b_x.re == 0.0) {
                Modello_Arduino_2022_B.Go_home_selector = 0.0;
              } else {
                Modello_Arduino_2022_B.Go_home_selector =
                  Modello_Arduino_2022_B.b_x.re / 60.0;
              }

              Modello_Arduino_2022_B.Gain1_nb = Modello_Arduino_2022_B.Lat_1.re
                + Modello_Arduino_2022_B.Go_home_selector;
              Modello_Arduino_2022_B.tolleranza_distWP_fut =
                Modello_Arduino_2022_B.eb_size[0] *
                Modello_Arduino_2022_B.eb_size[1] - 1;
              if (0 <= Modello_Arduino_2022_B.tolleranza_distWP_fut) {
                memcpy(&Modello_Arduino_2022_B.tmp_data[0],
                       &Modello_Arduino_2022_B.comma_gga_data[0],
                       (Modello_Arduino_2022_B.tolleranza_distWP_fut + 1) *
                       sizeof(int32_T));
              }

              if (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.tmp_data
                  [2]] == 'S') {
                Modello_Arduino_2022_B.Gain1_nb =
                  -Modello_Arduino_2022_B.Gain1_nb;
              }

              Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_2_str2double_lv
                (&Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.comma_gga_data
                 [3]]);
              if ((real_T)Modello_Arduino_2022_B.comma_gga_data[3] + 4.0 >
                  (real_T)Modello_Arduino_2022_B.comma_gga_data[4] - 1.0) {
                Modello_Arduino_2022_B.soglia_dist = 0;
                Modello_Arduino_2022_B.pipk = 0;
              } else {
                Modello_Arduino_2022_B.soglia_dist =
                  Modello_Arduino_2022_B.comma_gga_data[3] + 3;
                Modello_Arduino_2022_B.pipk =
                  Modello_Arduino_2022_B.comma_gga_data[4] - 1;
              }

              Modello_Arduino_2022_B.messaggio_size_c[0] = 1;
              Modello_Arduino_2022_B.tolleranza_distWP_fut =
                Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.messaggio_size_c[1] =
                Modello_Arduino_2022_B.tolleranza_distWP_fut;
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   Modello_Arduino_2022_B.tolleranza_distWP_fut;
                   Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                  =
                  Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                  + Modello_Arduino_2022_B.pipk];
              }

              Modello_Arduino_2022_B.b_x = Modello_Arduino_20_str2double_l
                (Modello_Arduino_2022_B.messaggio_data,
                 Modello_Arduino_2022_B.messaggio_size_c);
              if (Modello_Arduino_2022_B.b_x.im == 0.0) {
                Modello_Arduino_2022_B.Go_home_selector =
                  Modello_Arduino_2022_B.b_x.re / 60.0;
              } else if (Modello_Arduino_2022_B.b_x.re == 0.0) {
                Modello_Arduino_2022_B.Go_home_selector = 0.0;
              } else {
                Modello_Arduino_2022_B.Go_home_selector =
                  Modello_Arduino_2022_B.b_x.re / 60.0;
              }

              Modello_Arduino_2022_B.Go_home_selector +=
                Modello_Arduino_2022_B.Lat_1.re;
              if (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.tmp_data
                  [4]] == 'W') {
                Modello_Arduino_2022_B.Go_home_selector =
                  -Modello_Arduino_2022_B.Go_home_selector;
              }

              Modello_Arduino_2022_B.Lat_1 = Modello_Arduino__str2double_lvk
                (Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[5] =
                Modello_Arduino_2022_B.Lat_1.re;
              if ((real_T)Modello_Arduino_2022_B.comma_gga_data[6] + 1.0 >
                  (real_T)Modello_Arduino_2022_B.comma_gga_data[7] - 1.0) {
                Modello_Arduino_2022_B.soglia_dist = 0;
                Modello_Arduino_2022_B.pipk = 0;
              } else {
                Modello_Arduino_2022_B.soglia_dist =
                  Modello_Arduino_2022_B.comma_gga_data[6];
                Modello_Arduino_2022_B.pipk =
                  Modello_Arduino_2022_B.comma_gga_data[7] - 1;
              }

              Modello_Arduino_2022_B.messaggio_size_f[0] = 1;
              Modello_Arduino_2022_B.tolleranza_distWP_fut =
                Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.messaggio_size_f[1] =
                Modello_Arduino_2022_B.tolleranza_distWP_fut;
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   Modello_Arduino_2022_B.tolleranza_distWP_fut;
                   Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                  =
                  Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                  + Modello_Arduino_2022_B.pipk];
              }

              Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_20_str2double_l
                (Modello_Arduino_2022_B.messaggio_data,
                 Modello_Arduino_2022_B.messaggio_size_f);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[6] =
                Modello_Arduino_2022_B.Lat_1.re;
              if ((real_T)Modello_Arduino_2022_B.comma_gga_data[8] + 1.0 >
                  (real_T)Modello_Arduino_2022_B.comma_gga_data[9] - 1.0) {
                Modello_Arduino_2022_B.soglia_dist = 0;
                Modello_Arduino_2022_B.pipk = 0;
              } else {
                Modello_Arduino_2022_B.soglia_dist =
                  Modello_Arduino_2022_B.comma_gga_data[8];
                Modello_Arduino_2022_B.pipk =
                  Modello_Arduino_2022_B.comma_gga_data[9] - 1;
              }

              Modello_Arduino_2022_B.messaggio_size_g[0] = 1;
              Modello_Arduino_2022_B.tolleranza_distWP_fut =
                Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.messaggio_size_g[1] =
                Modello_Arduino_2022_B.tolleranza_distWP_fut;
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   Modello_Arduino_2022_B.tolleranza_distWP_fut;
                   Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                  =
                  Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                  + Modello_Arduino_2022_B.pipk];
              }

              Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_20_str2double_l
                (Modello_Arduino_2022_B.messaggio_data,
                 Modello_Arduino_2022_B.messaggio_size_g);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[7] =
                Modello_Arduino_2022_B.Lat_1.re;
              if ((real_T)Modello_Arduino_2022_B.comma_gga_data[10] + 1.0 >
                  (real_T)Modello_Arduino_2022_B.comma_gga_data[11] - 1.0) {
                Modello_Arduino_2022_B.soglia_dist = 0;
                Modello_Arduino_2022_B.tolleranza_distWP_fut = 0;
              } else {
                Modello_Arduino_2022_B.soglia_dist =
                  Modello_Arduino_2022_B.comma_gga_data[10];
                Modello_Arduino_2022_B.tolleranza_distWP_fut =
                  Modello_Arduino_2022_B.comma_gga_data[11] - 1;
              }

              Modello_Arduino_2022_B.messaggio_size_g1[0] = 1;
              Modello_Arduino_2022_B.tolleranza_distWP_fut -=
                Modello_Arduino_2022_B.soglia_dist;
              Modello_Arduino_2022_B.messaggio_size_g1[1] =
                Modello_Arduino_2022_B.tolleranza_distWP_fut;
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   Modello_Arduino_2022_B.tolleranza_distWP_fut;
                   Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.messaggio_data[Modello_Arduino_2022_B.pipk]
                  =
                  Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                  + Modello_Arduino_2022_B.pipk];
              }

              Modello_Arduino_2022_B.Lat_1 = Modello_Arduino_20_str2double_l
                (Modello_Arduino_2022_B.messaggio_data,
                 Modello_Arduino_2022_B.messaggio_size_g1);

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[8] =
                Modello_Arduino_2022_B.Lat_1.re;
              Modello_Arduino_2022_B.ComplextoRealImag[2] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[2];
              Modello_Arduino_2022_B.ComplextoRealImag[3] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[3];
              Modello_Arduino_2022_B.ComplextoRealImag[4] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[4];
              if ((real_T)Modello_Arduino_2022_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)Modello_Arduino_2022_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)Modello_Arduino_2022_B.star_data[0]
                                     + 1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = Modello_Arduino_2022_B.messaggio_k[status - 1];
              if ((real_T)Modello_Arduino_2022_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)Modello_Arduino_2022_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)Modello_Arduino_2022_B.star_data[0]
                                     + 2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = Modello_Arduino_2022_B.messaggio_k[status - 1];
              if ((real_T)Modello_Arduino_2022_B.fb_data[0] + 1.0 > (real_T)
                  Modello_Arduino_2022_B.star_data[0] - 1.0) {
                Modello_Arduino_2022_B.soglia_dist = 0;
                Modello_Arduino_2022_B.pipk = 0;
              } else {
                Modello_Arduino_2022_B.soglia_dist =
                  Modello_Arduino_2022_B.fb_data[0];
                Modello_Arduino_2022_B.pipk = Modello_Arduino_2022_B.star_data[0]
                  - 1;
              }

              Modello_Arduino_2022_B.tolleranza_distWP_fut =
                Modello_Arduino_2022_B.pipk - Modello_Arduino_2022_B.soglia_dist;
              for (Modello_Arduino_2022_B.pipk = 0; Modello_Arduino_2022_B.pipk <
                   Modello_Arduino_2022_B.tolleranza_distWP_fut;
                   Modello_Arduino_2022_B.pipk++) {
                Modello_Arduino_2022_B.NMEA_gga_string_data[Modello_Arduino_2022_B.pipk]
                  = (uint8_T)
                  Modello_Arduino_2022_B.messaggio_k[Modello_Arduino_2022_B.soglia_dist
                  + Modello_Arduino_2022_B.pipk];
              }

              status = 0U;
              Modello_Arduino_2022_B.pipk = 0;
              while (Modello_Arduino_2022_B.pipk <=
                     Modello_Arduino_2022_B.tolleranza_distWP_fut - 1) {
                status ^=
                  Modello_Arduino_2022_B.NMEA_gga_string_data[Modello_Arduino_2022_B.pipk];
                Modello_Arduino_2022_B.pipk++;
              }

              if (status != Modello_Arduino_2022_hex2dec(ck_ric)) {
                Modello_Arduino_2022_B.Gain1_nb =
                  Modello_Arduino_2022_DW.Memory_PreviousInput_l[0];
                Modello_Arduino_2022_B.Go_home_selector =
                  Modello_Arduino_2022_DW.Memory_PreviousInput_l[1];

                /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
                Modello_Arduino_2022_B.ComplextoRealImag[5] =
                  Modello_Arduino_2022_DW.Memory_PreviousInput_l[5];
                Modello_Arduino_2022_B.ComplextoRealImag[6] =
                  Modello_Arduino_2022_DW.Memory_PreviousInput_l[6];
                Modello_Arduino_2022_B.ComplextoRealImag[7] =
                  Modello_Arduino_2022_DW.Memory_PreviousInput_l[7];
                Modello_Arduino_2022_B.ComplextoRealImag[8] =
                  Modello_Arduino_2022_DW.Memory_PreviousInput_l[8];
                Modello_Arduino_2022_B.indice_dimario = 20U;
              }
            } else {
              Modello_Arduino_2022_B.Gain1_nb =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[0];
              Modello_Arduino_2022_B.Go_home_selector =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
              Modello_Arduino_2022_B.ComplextoRealImag[2] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[2];
              Modello_Arduino_2022_B.ComplextoRealImag[3] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[3];
              Modello_Arduino_2022_B.ComplextoRealImag[4] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[4];
              Modello_Arduino_2022_B.ComplextoRealImag[5] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[5];
              Modello_Arduino_2022_B.ComplextoRealImag[6] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[6];
              Modello_Arduino_2022_B.ComplextoRealImag[7] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[7];
              Modello_Arduino_2022_B.ComplextoRealImag[8] =
                Modello_Arduino_2022_DW.Memory_PreviousInput_l[8];
            }
          }
        } else {
          Modello_Arduino_2022_B.Gain1_nb =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[0];
          Modello_Arduino_2022_B.Go_home_selector =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[1];

          /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
          Modello_Arduino_2022_B.ComplextoRealImag[2] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[2];
          Modello_Arduino_2022_B.ComplextoRealImag[3] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[3];
          Modello_Arduino_2022_B.ComplextoRealImag[4] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[4];
          Modello_Arduino_2022_B.ComplextoRealImag[5] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[5];
          Modello_Arduino_2022_B.ComplextoRealImag[6] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[6];
          Modello_Arduino_2022_B.ComplextoRealImag[7] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[7];
          Modello_Arduino_2022_B.ComplextoRealImag[8] =
            Modello_Arduino_2022_DW.Memory_PreviousInput_l[8];
        }

        /* End of MATLAB Function: '<S583>/MATLAB Function' */

        /* ComplexToRealImag: '<S583>/Complex to Real-Imag' */
        Modello_Arduino_2022_B.ComplextoRealImag[0] =
          Modello_Arduino_2022_B.Gain1_nb;
        Modello_Arduino_2022_B.ComplextoRealImag[1] =
          Modello_Arduino_2022_B.Go_home_selector;

        /* Update for Memory: '<S583>/Memory' */
        memcpy(&Modello_Arduino_2022_DW.Memory_PreviousInput_l[0],
               &Modello_Arduino_2022_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S581>/Subsystem' */
      } else {
        for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 32;
             Modello_Arduino_2022_B.i++) {
          Modello_Arduino_2022_B.pipk = (int32_T)(((uint32_T)
            Modello_Arduino_2022_DW.counter_k + Modello_Arduino_2022_B.i) + 1U);
          if ((uint32_T)Modello_Arduino_2022_B.pipk > 255U) {
            Modello_Arduino_2022_B.pipk = 255;
          }

          Modello_Arduino_2022_DW.message[Modello_Arduino_2022_B.pipk - 1] =
            Modello_Arduino_2022_B.b_dataOut[Modello_Arduino_2022_B.i];
        }

        Modello_Arduino_2022_B.pipk = (int32_T)
          (Modello_Arduino_2022_DW.counter_k + 32U);
        if (Modello_Arduino_2022_DW.counter_k + 32U > 255U) {
          Modello_Arduino_2022_B.pipk = 255;
        }

        Modello_Arduino_2022_DW.counter_k = (uint8_T)Modello_Arduino_2022_B.pipk;
      }
    }

    /* End of MATLAB Function: '<S581>/Create_message' */
  }

  /* End of MATLABSystem: '<S570>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S570>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S570>/Subsystem1' incorporates:
   *  EnablePort: '<S580>/Enable'
   */
  if (Modello_Arduino_2022_B.SFunction_o14 > 0) {
    /* Switch: '<S580>/Switch' incorporates:
     *  Constant: '<S580>/Constant'
     *  Constant: '<S580>/Constant1'
     *  Constant: '<S580>/Constant3'
     *  Logic: '<S580>/OR'
     *  RelationalOperator: '<S580>/Equal'
     *  RelationalOperator: '<S580>/Equal1'
     *  RelationalOperator: '<S580>/Equal2'
     */
    if ((Modello_Arduino_2022_B.ComplextoRealImag[5] ==
         Modello_Arduino_2022_P.Constant_Value_lv) ||
        (Modello_Arduino_2022_B.ComplextoRealImag[5] ==
         Modello_Arduino_2022_P.Constant1_Value_b) ||
        (Modello_Arduino_2022_B.ComplextoRealImag[5] ==
         Modello_Arduino_2022_P.Constant3_Value_ct)) {
      /* Switch: '<S580>/Switch' */
      Modello_Arduino_2022_B.Switch = Modello_Arduino_2022_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S580>/Switch' incorporates:
       *  Constant: '<S580>/Constant2'
       */
      Modello_Arduino_2022_B.Switch = Modello_Arduino_2022_P.Constant2_Value_d;
    }

    /* End of Switch: '<S580>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S570>/Subsystem1' */

  /* ManualSwitch: '<S7>/Manual Switch1' incorporates:
   *  Constant: '<S7>/Constant8'
   *  Sum: '<S570>/Sum'
   */
  if (Modello_Arduino_2022_P.ManualSwitch1_CurrentSetting == 1) {
    for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 6;
         Modello_Arduino_2022_B.i++) {
      Modello_Arduino_2022_B.ManualSwitch1[Modello_Arduino_2022_B.i] =
        Modello_Arduino_2022_P.Constant8_Value_m[Modello_Arduino_2022_B.i];
    }
  } else {
    Modello_Arduino_2022_B.ManualSwitch1[0] =
      Modello_Arduino_2022_B.ComplextoRealImag[0];
    Modello_Arduino_2022_B.ManualSwitch1[1] =
      Modello_Arduino_2022_B.ComplextoRealImag[1];
    Modello_Arduino_2022_B.ManualSwitch1[2] =
      Modello_Arduino_2022_B.ComplextoRealImag[2];
    Modello_Arduino_2022_B.ManualSwitch1[3] =
      Modello_Arduino_2022_B.ComplextoRealImag[7] -
      Modello_Arduino_2022_B.Switch;
    Modello_Arduino_2022_B.ManualSwitch1[4] =
      Modello_Arduino_2022_B.ComplextoRealImag[4];
    Modello_Arduino_2022_B.ManualSwitch1[5] =
      Modello_Arduino_2022_B.ComplextoRealImag[5];
  }

  /* End of ManualSwitch: '<S7>/Manual Switch1' */

  /* ManualSwitch: '<S7>/Manual Switch3' incorporates:
   *  Constant: '<S7>/Constant2'
   *  MATLAB Function: '<S569>/MATLAB Function1'
   */
  if (Modello_Arduino_2022_P.ManualSwitch3_CurrentSetting == 1) {
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Constant2_Value_o;
  } else {
    /* MATLAB Function: '<S569>/MATLAB Function1' incorporates:
     *  DataTypeConversion: '<S569>/Data Type Conversion'
     *  UnitDelay: '<S572>/Delay Input2'
     *
     * Block description for '<S572>/Delay Input2':
     *
     *  Store in Global RAM
     */
    Modello_Arduino_2022_B.Gain1_nb = log
      (Modello_Arduino_2022_DW.DelayInput2_DSTATE / (real_T)
       Modello_Arduino_2022_B.SFunctionBuilder1);
    Modello_Arduino_2022_B.Abs1 = (real32_T)(29.260958205912335 *
      Modello_Arduino_2022_B.Gain1_nb) * (Modello_Arduino_2022_B.Switch1_gg +
      273.15F) / (real32_T)(1.0 - -0.095098114169215084 *
      Modello_Arduino_2022_B.Gain1_nb);
  }

  /* End of ManualSwitch: '<S7>/Manual Switch3' */

  /* DataTypeConversion: '<S556>/Data Type Conversion4' */
  Modello_Arduino_2022_B.DataTypeConversion4[0] = (real32_T)
    Modello_Arduino_2022_B.ManualSwitch1[0];
  Modello_Arduino_2022_B.DataTypeConversion4[1] = (real32_T)
    Modello_Arduino_2022_B.ManualSwitch1[1];
  Modello_Arduino_2022_B.DataTypeConversion4[2] = (real32_T)
    Modello_Arduino_2022_B.ManualSwitch1[3];
  Modello_Arduino_2022_B.DataTypeConversion4[3] = (real32_T)
    Modello_Arduino_2022_B.Abs1;

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  Gain: '<S561>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_py * Modello_Arduino_2022_B.ManualSwitch[3]
     * Modello_Arduino_2022_P.Gain_Gain_jx));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[3] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  Gain: '<S562>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_kq * Modello_Arduino_2022_B.ManualSwitch[4]
     * Modello_Arduino_2022_P.Gain_Gain_jx));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[4] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  Gain: '<S563>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_e * Modello_Arduino_2022_B.ManualSwitch[5]
     * Modello_Arduino_2022_P.Gain_Gain_jx));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[5] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_jx * Modello_Arduino_2022_B.ManualSwitch[6]));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[0] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_jx * Modello_Arduino_2022_B.ManualSwitch[0]));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[6] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_jx * Modello_Arduino_2022_B.ManualSwitch[7]));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[1] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_jx * Modello_Arduino_2022_B.ManualSwitch[1]));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[7] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_jx * Modello_Arduino_2022_B.ManualSwitch[8]));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[2] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S556>/Data Type Conversion' incorporates:
   *  Gain: '<S556>/Gain'
   *  SignalConversion generated from: '<S556>/Gain'
   */
  Modello_Arduino_2022_B.Switch1_gg = (real32_T)floor((real32_T)
    (Modello_Arduino_2022_P.Gain_Gain_jx * Modello_Arduino_2022_B.ManualSwitch[2]));
  if (rtIsNaNF(Modello_Arduino_2022_B.Switch1_gg) || rtIsInfF
      (Modello_Arduino_2022_B.Switch1_gg)) {
    Modello_Arduino_2022_B.Switch1_gg = 0.0F;
  } else {
    Modello_Arduino_2022_B.Switch1_gg = (real32_T)fmod
      (Modello_Arduino_2022_B.Switch1_gg, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_d[8] = (int16_T)
    (Modello_Arduino_2022_B.Switch1_gg < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Modello_Arduino_2022_B.Switch1_gg : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Switch1_gg);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant5'
   *  Constant: '<S594>/Constant1'
   *  Product: '<S594>/Divide'
   *  Product: '<S594>/Multiply'
   *  Sum: '<S594>/Sum'
   *  Sum: '<S594>/Sum2'
   *  Sum: '<S594>/Sum3'
   */
  Modello_Arduino_2022_B.a_n = floor((Modello_Arduino_2022_B.Sum3 -
    Modello_Arduino_2022_P.attuatore_Emin) / Modello_Arduino_2022_B.Saturation_e
    * (Modello_Arduino_2022_P.Constant2_Value_l -
       Modello_Arduino_2022_P.Constant5_Value_i) +
    Modello_Arduino_2022_P.Constant5_Value_i);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  Modello_Arduino_2022_B.DataTypeConversion_p = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S10>/Constant4'
   *  Constant: '<S10>/Constant6'
   *  Constant: '<S591>/Constant1'
   *  Product: '<S591>/Divide'
   *  Product: '<S591>/Multiply'
   *  Sum: '<S591>/Sum'
   *  Sum: '<S591>/Sum2'
   *  Sum: '<S591>/Sum3'
   */
  Modello_Arduino_2022_B.a_n = floor((Modello_Arduino_2022_B.SignPreSat -
    Modello_Arduino_2022_P.attuatore_Amin) /
    Modello_Arduino_2022_B.rtb_Sum3_b_tmp *
    (Modello_Arduino_2022_P.Constant4_Value_k -
     Modello_Arduino_2022_P.Constant6_Value_a) +
    Modello_Arduino_2022_P.Constant6_Value_a);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_c = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/Constant7'
   *  Constant: '<S592>/Constant'
   *  Constant: '<S592>/Constant1'
   *  Product: '<S592>/Divide'
   *  Product: '<S592>/Multiply'
   *  Sum: '<S592>/Sum'
   *  Sum: '<S592>/Sum1'
   *  Sum: '<S592>/Sum2'
   *  Sum: '<S592>/Sum3'
   */
  Modello_Arduino_2022_B.a_n = floor((Modello_Arduino_2022_B.Sum2_c -
    Modello_Arduino_2022_P.attuatore_Rmin) /
    (Modello_Arduino_2022_P.attuatore_Rmax -
     Modello_Arduino_2022_P.attuatore_Rmin) *
    (Modello_Arduino_2022_P.Constant3_Value_e -
     Modello_Arduino_2022_P.Constant7_Value_h) +
    Modello_Arduino_2022_P.Constant7_Value_h);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  Modello_Arduino_2022_B.DataTypeConversion2_j = (int16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.a_n);

  /* Gain: '<S556>/Gain3' */
  Modello_Arduino_2022_B.Integrator_e *= Modello_Arduino_2022_P.Gain3_Gain;

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.ManualSwitch1[4]);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_h[0] = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  Gain: '<S556>/Gain2'
   */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Gain2_Gain_o *
    Modello_Arduino_2022_B.ManualSwitch1[2]);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_h[1] = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion9'
   */
  Modello_Arduino_2022_B.pipk = (int32_T)fmod
    (Modello_Arduino_2022_B.DataTypeConversion_p, 65536.0);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_h[2] = (uint16_T)
    (Modello_Arduino_2022_B.pipk < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)Modello_Arduino_2022_B.pipk : (int32_T)(uint16_T)
     Modello_Arduino_2022_B.pipk);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion9'
   */
  Modello_Arduino_2022_B.pipk = (int32_T)fmod
    (Modello_Arduino_2022_B.DataTypeConversion1_c, 65536.0);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   */
  Modello_Arduino_2022_B.DataTypeConversion1_h[3] = (uint16_T)
    (Modello_Arduino_2022_B.pipk < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)Modello_Arduino_2022_B.pipk : (int32_T)(uint16_T)
     Modello_Arduino_2022_B.pipk);
  Modello_Arduino_2022_B.DataTypeConversion1_h[4] = (uint16_T)
    Modello_Arduino_2022_B.PWM_throttle;
  Modello_Arduino_2022_B.DataTypeConversion1_h[5] = (uint16_T)
    Modello_Arduino_2022_B.PWM_elevator;
  Modello_Arduino_2022_B.DataTypeConversion1_h[6] = (uint16_T)
    Modello_Arduino_2022_B.PWM_aileron;
  Modello_Arduino_2022_B.DataTypeConversion1_h[7] = (uint16_T)
    Modello_Arduino_2022_B.PWM_rudder;

  /* DataTypeConversion: '<S556>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion9'
   */
  Modello_Arduino_2022_B.pipk = (int32_T)fmod
    (Modello_Arduino_2022_B.DataTypeConversion2_j, 65536.0);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_h[8] = (uint16_T)
    (Modello_Arduino_2022_B.pipk < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -(real_T)Modello_Arduino_2022_B.pipk : (int32_T)(uint16_T)
     Modello_Arduino_2022_B.pipk);

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.Integrator_e);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion1' */
  Modello_Arduino_2022_B.DataTypeConversion1_h[9] = (uint16_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint16_T)Modello_Arduino_2022_B.a_n);

  /* DataTypeConversion: '<S556>/Data Type Conversion6' */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.ManualSwitch1[5]);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 256.0);
  }

  /* SignalConversion generated from: '<S556>/Byte Pack' incorporates:
   *  DataTypeConversion: '<S556>/Data Type Conversion6'
   */
  Modello_Arduino_2022_B.TmpSignalConversionAtBytePackIn[0] = (uint8_T)
    (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
     -Modello_Arduino_2022_B.a_n : (int32_T)(uint8_T)Modello_Arduino_2022_B.a_n);

  /* ManualSwitch: '<S7>/Manual Switch2' incorporates:
   *  Constant: '<S7>/Constant9'
   */
  if (Modello_Arduino_2022_P.ManualSwitch2_CurrentSetting == 1) {
    Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_P.Constant9_Value);
    if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf
        (Modello_Arduino_2022_B.a_n)) {
      Modello_Arduino_2022_B.a_n = 0.0;
    } else {
      Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 256.0);
    }

    /* SignalConversion generated from: '<S556>/Byte Pack' incorporates:
     *  Constant: '<S7>/Constant9'
     */
    Modello_Arduino_2022_B.TmpSignalConversionAtBytePackIn[1] = (uint8_T)
      (Modello_Arduino_2022_B.a_n < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
       -Modello_Arduino_2022_B.a_n : (int32_T)(uint8_T)
       Modello_Arduino_2022_B.a_n);
  } else {
    /* SignalConversion generated from: '<S556>/Byte Pack' */
    Modello_Arduino_2022_B.TmpSignalConversionAtBytePackIn[1] =
      Modello_Arduino_2022_B.indice_dimario;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch2' */

  /* DataTypeConversion: '<S556>/Data Type Conversion8' */
  Modello_Arduino_2022_B.a_n = floor(Modello_Arduino_2022_B.deltafalllimit);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S556>/Data Type Conversion8' */
  Modello_Arduino_2022_B.DataTypeConversion8 = Modello_Arduino_2022_B.a_n < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-Modello_Arduino_2022_B.a_n : (uint32_T)
    Modello_Arduino_2022_B.a_n;

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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_B.DataTypeConversion4[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_B.DataTypeConversion_d[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_B.DataTypeConversion1_h[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_B.TmpSignalConversionAtBytePackIn[0],
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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_B.DataTypeConversion8, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Modello_Arduino_2022_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Modello_Arduino_2022_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S556>/Serial Transmit' */
  if (Modello_Arduino_2022_DW.obj.Protocol !=
      Modello_Arduino_2022_P.SerialTransmit_Protocol_o) {
    Modello_Arduino_2022_DW.obj.Protocol =
      Modello_Arduino_2022_P.SerialTransmit_Protocol_o;
  }

  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 63;
       Modello_Arduino_2022_B.i++) {
    Modello_Arduino_2022_B.dataIn[Modello_Arduino_2022_B.i] =
      Modello_Arduino_2022_B.BytePack[Modello_Arduino_2022_B.i];
  }

  MW_Serial_write(Modello_Arduino_2022_DW.obj.port,
                  &Modello_Arduino_2022_B.dataIn[0], 63.0,
                  Modello_Arduino_2022_DW.obj.dataSizeInBytes,
                  Modello_Arduino_2022_DW.obj.sendModeEnum,
                  Modello_Arduino_2022_DW.obj.dataType,
                  Modello_Arduino_2022_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S556>/Serial Transmit' */

  /* MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation1' */
  switch ((int32_T)Modello_Arduino_2022_B.modo) {
   case 1:
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.VELOCITA;
    break;

   case 2:
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.V_vett;
    break;

   case 3:
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.Tas_ref;
    break;

   case 4:
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.velocita;
    break;

   default:
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.V_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation1' */

  /* Sum: '<S42>/Sum3' */
  Modello_Arduino_2022_B.deltafalllimit -= Modello_Arduino_2022_B.Product1;

  /* Sum: '<S294>/Sum' incorporates:
   *  Constant: '<S8>/Kp AP velocità'
   *  DiscreteIntegrator: '<S285>/Integrator'
   *  Product: '<S290>/PProd Out'
   */
  Modello_Arduino_2022_B.Sum2_c = Modello_Arduino_2022_B.deltafalllimit *
    Modello_Arduino_2022_P.Kp_AP_vel +
    Modello_Arduino_2022_DW.Integrator_DSTATE_e;

  /* Saturate: '<S292>/Saturation' */
  if (Modello_Arduino_2022_B.Sum2_c > Modello_Arduino_2022_P.attuatore_Tmax) {
    Modello_Arduino_2022_B.Saturation_e = Modello_Arduino_2022_P.attuatore_Tmax;
  } else if (Modello_Arduino_2022_B.Sum2_c <
             Modello_Arduino_2022_P.attuatore_Tmin) {
    Modello_Arduino_2022_B.Saturation_e = Modello_Arduino_2022_P.attuatore_Tmin;
  } else {
    Modello_Arduino_2022_B.Saturation_e = Modello_Arduino_2022_B.Sum2_c;
  }

  /* End of Saturate: '<S292>/Saturation' */

  /* DigitalClock: '<S250>/Digital Clock1' */
  Modello_Arduino_2022_B.Product1 = ((Modello_Arduino_2022_M->Timing.clockTick0)
    * 0.02);

  /* MATLAB Function: '<S250>/Smooth Bypass' incorporates:
   *  SignalConversion generated from: '<S250>/Vector Concatenate'
   */
  if (Modello_Arduino_2022_B.switch_manetta == 0.0) {
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.Saturation_e;
    Modello_Arduino_2022_DW.Delay_DSTATE = Modello_Arduino_2022_B.Product1;
  } else {
    if (Modello_Arduino_2022_B.switch_manetta !=
        Modello_Arduino_2022_B.switch_manetta) {
      Modello_Arduino_2022_DW.Delay_DSTATE = Modello_Arduino_2022_B.Product1;
    }

    Modello_Arduino_2022_B.Product1 -= Modello_Arduino_2022_DW.Delay_DSTATE;
    if (Modello_Arduino_2022_B.Product1 < 1.3) {
      if (Modello_Arduino_2022_B.Product1 < 0.2) {
        Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.Sum5;
      } else {
        Modello_Arduino_2022_B.Abs1 = (Modello_Arduino_2022_B.Product1 - 0.2) /
          1.1 * (Modello_Arduino_2022_B.Saturation_e -
                 Modello_Arduino_2022_B.Sum5) + Modello_Arduino_2022_B.Sum5;
      }
    } else {
      Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.Saturation_e;
    }
  }

  /* End of MATLAB Function: '<S250>/Smooth Bypass' */

  /* MultiPortSwitch: '<S250>/Switch Bumpless 1' */
  if ((int32_T)Modello_Arduino_2022_B.switch_manetta == 0) {
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.Sum5;
  }

  /* End of MultiPortSwitch: '<S250>/Switch Bumpless 1' */

  /* HitCross: '<S251>/Hit  Crossing' */
  Modello_Arduino_2022_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &Modello_Arduino_2022_PrevZCX.HitCrossing_Input_ZCE,
    (Modello_Arduino_2022_B.Gain1_m - Modello_Arduino_2022_P.HitCrossing_Offset));
  if (Modello_Arduino_2022_DW.HitCrossing_MODE == 0) {
    if (Modello_Arduino_2022_B.zcEvent != NO_ZCEVENT) {
      /* HitCross: '<S251>/Hit  Crossing' */
      Modello_Arduino_2022_B.HitCrossing = !Modello_Arduino_2022_B.HitCrossing;
      Modello_Arduino_2022_DW.HitCrossing_MODE = 1;
    } else {
      if (Modello_Arduino_2022_B.HitCrossing) {
        /* HitCross: '<S251>/Hit  Crossing' */
        Modello_Arduino_2022_B.HitCrossing = ((!(Modello_Arduino_2022_B.Gain1_m
          != Modello_Arduino_2022_P.HitCrossing_Offset)) &&
          Modello_Arduino_2022_B.HitCrossing);
      }
    }
  } else {
    /* HitCross: '<S251>/Hit  Crossing' */
    Modello_Arduino_2022_B.HitCrossing = ((!(Modello_Arduino_2022_B.Gain1_m !=
      Modello_Arduino_2022_P.HitCrossing_Offset)) &&
      Modello_Arduino_2022_B.HitCrossing);
    Modello_Arduino_2022_DW.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<S251>/Hit  Crossing' */

  /* Outputs for Triggered SubSystem: '<S251>/Enabled Subsystem' incorporates:
   *  TriggerPort: '<S303>/Trigger'
   */
  if (Modello_Arduino_2022_B.HitCrossing &&
      (Modello_Arduino_2022_PrevZCX.EnabledSubsystem_Trig_ZCE != 1)) {
    /* SignalConversion generated from: '<S303>/Out1' incorporates:
     *  Constant: '<S303>/Constant'
     */
    Modello_Arduino_2022_B.OutportBufferForOut1 =
      Modello_Arduino_2022_P.Constant_Value;
  }

  Modello_Arduino_2022_PrevZCX.EnabledSubsystem_Trig_ZCE =
    Modello_Arduino_2022_B.HitCrossing;

  /* End of Outputs for SubSystem: '<S251>/Enabled Subsystem' */

  /* MultiPortSwitch: '<S36>/Switch di selezione riferimeti  per i loop interni 1' */
  if ((int32_T)Modello_Arduino_2022_B.Switch_j == 0) {
    /* MultiPortSwitch: '<S251>/throttle - landing' incorporates:
     *  MATLAB Function: '<S38>/MATLAB Function'
     */
    if (Modello_Arduino_2022_B.caso != 0) {
      /* Switch: '<S251>/Switch' incorporates:
       *  Constant: '<S251>/Constant3'
       */
      if (!(Modello_Arduino_2022_B.OutportBufferForOut1 >
            Modello_Arduino_2022_P.Switch_Threshold)) {
        Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Constant3_Value;
      }

      /* End of Switch: '<S251>/Switch' */
    }

    /* End of MultiPortSwitch: '<S251>/throttle - landing' */
  } else {
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.throttle_safe;
  }

  /* End of MultiPortSwitch: '<S36>/Switch di selezione riferimeti  per i loop interni 1' */

  /* Sum: '<S307>/Sum' incorporates:
   *  Constant: '<S307>/Constant8'
   */
  Modello_Arduino_2022_B.Product1 = Modello_Arduino_2022_B.Fase_ATO -
    Modello_Arduino_2022_P.Constant8_Value_j;

  /* DiscreteIntegrator: '<S307>/Discrete-Time Integrator' */
  if ((Modello_Arduino_2022_B.Product1 > 0.0) &&
      (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE =
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_IC_e;
  }

  if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE >=
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperS_l) {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE =
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE <=
        Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerS_l) {
      Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE =
        Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerS_l;
    }
  }

  /* MultiPortSwitch: '<S307>/Multiport Switch1' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (Modello_Arduino_2022_B.ATO != 0) {
    /* MultiPortSwitch: '<S307>/Switch Bumpless 1' incorporates:
     *  Constant: '<S307>/Constant4'
     *  DiscreteIntegrator: '<S307>/Discrete-Time Integrator'
     */
    switch ((int32_T)Modello_Arduino_2022_B.Fase_ATO) {
     case 0:
      Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Constant4_Value;
      break;

     case 1:
      Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_B.manetta_ref;
      break;

     case 2:
      Modello_Arduino_2022_B.Abs1 =
        Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE;
      break;

     case 3:
      break;
    }

    /* End of MultiPortSwitch: '<S307>/Switch Bumpless 1' */
  }

  /* End of MultiPortSwitch: '<S307>/Multiport Switch1' */

  /* Sum: '<S297>/SumI1' incorporates:
   *  Constant: '<S8>/Ki AP velocità'
   *  Gain: '<S296>/Kt'
   *  Product: '<S282>/IProd Out'
   *  Sum: '<S296>/SumI3'
   */
  Modello_Arduino_2022_B.Abs1 = (Modello_Arduino_2022_B.Abs1 -
    Modello_Arduino_2022_B.Saturation_e) *
    Modello_Arduino_2022_P.PIDController_Kt +
    Modello_Arduino_2022_B.deltafalllimit * Modello_Arduino_2022_P.Ki_AP_vel;

  /* DeadZone: '<S278>/DeadZone' */
  if (Modello_Arduino_2022_B.Sum2_c > Modello_Arduino_2022_P.attuatore_Tmax) {
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.Sum2_c -
      Modello_Arduino_2022_P.attuatore_Tmax;
  } else if (Modello_Arduino_2022_B.Sum2_c >=
             Modello_Arduino_2022_P.attuatore_Tmin) {
    Modello_Arduino_2022_B.deltafalllimit = 0.0;
  } else {
    Modello_Arduino_2022_B.deltafalllimit = Modello_Arduino_2022_B.Sum2_c -
      Modello_Arduino_2022_P.attuatore_Tmin;
  }

  /* End of DeadZone: '<S278>/DeadZone' */

  /* S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */
  Servo_microseconds_alettoni_beta_3_Outputs_wrapper
    (&Modello_Arduino_2022_B.DataTypeConversion1_c,
     &Modello_Arduino_2022_DW.SFunctionBuilder10_DSTATE);

  /* Sum: '<S593>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Product: '<S593>/Multiply'
   *  Sum: '<S593>/Sum1'
   */
  Modello_Arduino_2022_B.a_n = floor((Modello_Arduino_2022_P.Constant_Value_nb -
    Modello_Arduino_2022_P.Constant1_Value_m) * Modello_Arduino_2022_B.Sum5);
  if (rtIsNaN(Modello_Arduino_2022_B.a_n) || rtIsInf(Modello_Arduino_2022_B.a_n))
  {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 65536.0);
  }

  Modello_Arduino_2022_B.Sum3 = floor(Modello_Arduino_2022_P.Constant1_Value_m);
  if (rtIsNaN(Modello_Arduino_2022_B.Sum3) || rtIsInf
      (Modello_Arduino_2022_B.Sum3)) {
    Modello_Arduino_2022_B.Sum3 = 0.0;
  } else {
    Modello_Arduino_2022_B.Sum3 = fmod(Modello_Arduino_2022_B.Sum3, 65536.0);
  }

  /* Sum: '<S593>/Sum' */
  Modello_Arduino_2022_B.Sum = (int16_T)((Modello_Arduino_2022_B.a_n < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-Modello_Arduino_2022_B.a_n : (int32_T)
    (int16_T)(uint16_T)Modello_Arduino_2022_B.a_n) +
    (Modello_Arduino_2022_B.Sum3 < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -Modello_Arduino_2022_B.Sum3 : (int32_T)(int16_T)(uint16_T)
     Modello_Arduino_2022_B.Sum3));

  /* S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper(&Modello_Arduino_2022_B.Sum,
    &Modello_Arduino_2022_DW.SFunctionBuilder4_DSTATE);

  /* S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */
  Servo_microseconds_timone_beta_3_Outputs_wrapper
    (&Modello_Arduino_2022_B.DataTypeConversion2_j,
     &Modello_Arduino_2022_DW.SFunctionBuilder5_DSTATE);

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper
    (&Modello_Arduino_2022_B.DataTypeConversion_p,
     &Modello_Arduino_2022_DW.SFunctionBuilder9_DSTATE);

  /* Outputs for Resettable SubSystem: '<S410>/Resettable Subsystem' */
  Modello_Arduino_2022_B.Sum_ax = Modello_ResettableSubsystem
    (Modello_Arduino_2022_B.SFunction_o4_e[1],
     &Modello_Arduino_2022_DW.ResettableSubsystem,
     &Modello_Arduino_2022_P.ResettableSubsystem,
     &Modello_Arduino_2022_PrevZCX.ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S410>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S410>/Enabled Subsystem' */
  Modello_Ar_EnabledSubsystem(Modello_Arduino_2022_B.SFunction_o4_e[1],
    Modello_Arduino_2022_B.Sum_ax, &Modello_Arduino_2022_B.Sum5,
    &Modello_Arduino_2022_P.EnabledSubsystem_c);

  /* End of Outputs for SubSystem: '<S410>/Enabled Subsystem' */

  /* MATLAB Function: '<S412>/MATLAB Function1' */
  Modello_Arduino_2022_DW.Tf_not_empty = ((!Modello_Arduino_2022_DW.Tf_not_empty)
    || (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[0] == 1) ||
    (Modello_Arduino_2022_DW.Memory2_PreviousInput_a[1] == 0) ||
    Modello_Arduino_2022_DW.Tf_not_empty);

  /* Product: '<S565>/Product4' incorporates:
   *  MATLAB Function: '<S565>/MATLAB Function'
   */
  Modello_Arduino_2022_B.num_254 *= 1.0 - 2.0 *
    Modello_Arduino_2022_B.RateTransition;

  /* S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper
    (&Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&Modello_Arduino_2022_DW.Memory4_PreviousInput_c[0],
         &Modello_Arduino_2022_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S571>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S571>/S-Function Builder */
  Mti_Update_wrapper(&Modello_Arduino_2022_B.SFunctionBuilder[0],
                     &Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S569>/Unit Delay' incorporates:
   *  Constant: '<S569>/Constant3'
   */
  Modello_Arduino_2022_DW.UnitDelay_DSTATE_d =
    Modello_Arduino_2022_P.Constant3_Value_ok;

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&Modello_Arduino_2022_P.Constant1_Value_a,
    &Modello_Arduino_2022_B.SFunctionBuilder_o1_h[0],
    &Modello_Arduino_2022_B.SFunctionBuilder_o2,
    &Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE_l);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&Modello_Arduino_2022_DW.Memory5_PreviousInput_l[0],
         &Modello_Arduino_2022_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  Modello_Arduino_2022_DW.Memory_PreviousInput_h[0] =
    Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[0];
  Modello_Arduino_2022_DW.Memory_PreviousInput_h[1] =
    Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[1];
  Modello_Arduino_2022_DW.Memory_PreviousInput_h[2] =
    Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[2];
  Modello_Arduino_2022_DW.Memory_PreviousInput_h[3] =
    Modello_Arduino_2022_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (Modello_Arduino_2022_B.i = 0; Modello_Arduino_2022_B.i < 8;
       Modello_Arduino_2022_B.i++) {
    Modello_Arduino_2022_DW.Memory_PreviousInput_i[Modello_Arduino_2022_B.i] =
      Modello_Arduino_2022_B.SFunction_o11[Modello_Arduino_2022_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for UnitDelay: '<S565>/Unit Delay' incorporates:
   *  Sum: '<S565>/Sum1'
   */
  Modello_Arduino_2022_DW.UnitDelay_DSTATE =
    Modello_Arduino_2022_B.rtb_Gain1_hx_idx_1 + Modello_Arduino_2022_B.num_254;

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
  Modello_Arduino_2022_DW.Integrator_DSTATE +=
    (((Modello_Arduino_2022_B.SwitchBumpless2 - Modello_Arduino_2022_B.Gain1_h) *
      Modello_Arduino_2022_P.PIDController_Kt_b + Modello_Arduino_2022_B.Gain1_i
      * Modello_Arduino_2022_P.Ki_becch) + (Modello_Arduino_2022_B.Gain1_h -
      Modello_Arduino_2022_B.rtb_Gain1_hx_idx_0) *
     Modello_Arduino_2022_P.PIDController_Kb_a) *
    Modello_Arduino_2022_P.Integrator_gainval;

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
  Modello_Arduino_2022_DW.Integrator_DSTATE_n +=
    (((Modello_Arduino_2022_B.Alettoni - Modello_Arduino_2022_B.Saturation_a) *
      Modello_Arduino_2022_P.PIDController_Kt_o + Modello_Arduino_2022_B.Gain1_l
      * Modello_Arduino_2022_P.Ki_roll) + (Modello_Arduino_2022_B.Saturation_a -
      Modello_Arduino_2022_B.Sum_nh) * Modello_Arduino_2022_P.PIDController_Kb) *
    Modello_Arduino_2022_P.Integrator_gainval_k;
  if (Modello_Arduino_2022_B.Ato_selector > 0.0) {
    Modello_Arduino_2022_DW.Integrator_PrevResetState = 1;
  } else if (Modello_Arduino_2022_B.Ato_selector < 0.0) {
    Modello_Arduino_2022_DW.Integrator_PrevResetState = -1;
  } else if (Modello_Arduino_2022_B.Ato_selector == 0.0) {
    Modello_Arduino_2022_DW.Integrator_PrevResetState = 0;
  } else {
    Modello_Arduino_2022_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S392>/Integrator' */

  /* Update for DiscreteTransferFcn: '<S306>/Discrete Washout Filter' */
  Modello_Arduino_2022_DW.DiscreteWashoutFilter_states =
    Modello_Arduino_2022_B.Sum3_b;

  /* Update for Memory: '<S2>/Memory' */
  Modello_Arduino_2022_DW.Memory_PreviousInput_n =
    Modello_Arduino_2022_B.SFunction_o4;

  /* Signum: '<S276>/SignPreSat' */
  if (Modello_Arduino_2022_B.deltafalllimit < 0.0) {
    /* DataTypeConversion: '<S276>/DataTypeConv1' */
    Modello_Arduino_2022_B.a_n = -1.0;
  } else if (Modello_Arduino_2022_B.deltafalllimit > 0.0) {
    /* DataTypeConversion: '<S276>/DataTypeConv1' */
    Modello_Arduino_2022_B.a_n = 1.0;
  } else if (Modello_Arduino_2022_B.deltafalllimit == 0.0) {
    /* DataTypeConversion: '<S276>/DataTypeConv1' */
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    /* DataTypeConversion: '<S276>/DataTypeConv1' */
    Modello_Arduino_2022_B.a_n = (rtNaN);
  }

  /* End of Signum: '<S276>/SignPreSat' */

  /* DataTypeConversion: '<S276>/DataTypeConv1' */
  if (rtIsNaN(Modello_Arduino_2022_B.a_n)) {
    Modello_Arduino_2022_B.a_n = 0.0;
  } else {
    Modello_Arduino_2022_B.a_n = fmod(Modello_Arduino_2022_B.a_n, 256.0);
  }

  /* Signum: '<S276>/SignPreIntegrator' */
  if (Modello_Arduino_2022_B.Abs1 < 0.0) {
    /* DataTypeConversion: '<S276>/DataTypeConv2' */
    Modello_Arduino_2022_B.Sum3 = -1.0;
  } else if (Modello_Arduino_2022_B.Abs1 > 0.0) {
    /* DataTypeConversion: '<S276>/DataTypeConv2' */
    Modello_Arduino_2022_B.Sum3 = 1.0;
  } else if (Modello_Arduino_2022_B.Abs1 == 0.0) {
    /* DataTypeConversion: '<S276>/DataTypeConv2' */
    Modello_Arduino_2022_B.Sum3 = 0.0;
  } else {
    /* DataTypeConversion: '<S276>/DataTypeConv2' */
    Modello_Arduino_2022_B.Sum3 = (rtNaN);
  }

  /* End of Signum: '<S276>/SignPreIntegrator' */

  /* DataTypeConversion: '<S276>/DataTypeConv2' */
  if (rtIsNaN(Modello_Arduino_2022_B.Sum3)) {
    Modello_Arduino_2022_B.Sum3 = 0.0;
  } else {
    Modello_Arduino_2022_B.Sum3 = fmod(Modello_Arduino_2022_B.Sum3, 256.0);
  }

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S276>/Constant1'
   *  DataTypeConversion: '<S276>/DataTypeConv1'
   *  DataTypeConversion: '<S276>/DataTypeConv2'
   *  Gain: '<S276>/ZeroGain'
   *  Logic: '<S276>/AND3'
   *  RelationalOperator: '<S276>/Equal1'
   *  RelationalOperator: '<S276>/NotEqual'
   */
  if ((Modello_Arduino_2022_P.ZeroGain_Gain * Modello_Arduino_2022_B.Sum2_c !=
       Modello_Arduino_2022_B.deltafalllimit) && ((Modello_Arduino_2022_B.a_n <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-Modello_Arduino_2022_B.a_n :
        (int32_T)(int8_T)(uint8_T)Modello_Arduino_2022_B.a_n) ==
       (Modello_Arduino_2022_B.Sum3 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
        -Modello_Arduino_2022_B.Sum3 : (int32_T)(int8_T)(uint8_T)
        Modello_Arduino_2022_B.Sum3))) {
    Modello_Arduino_2022_B.Abs1 = Modello_Arduino_2022_P.Constant1_Value_c;
  }

  /* End of Switch: '<S276>/Switch' */

  /* Update for DiscreteIntegrator: '<S285>/Integrator' */
  Modello_Arduino_2022_DW.Integrator_DSTATE_e +=
    Modello_Arduino_2022_P.Integrator_gainval_c * Modello_Arduino_2022_B.Abs1;

  /* Update for DiscreteIntegrator: '<S307>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S307>/Constant7'
   */
  Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE +=
    Modello_Arduino_2022_P.DiscreteTimeIntegrator_gainva_a *
    Modello_Arduino_2022_P.Constant7_Value_j;
  if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE >=
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperS_l) {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE =
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE <=
        Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerS_l) {
      Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE =
        Modello_Arduino_2022_P.DiscreteTimeIntegrator_LowerS_l;
    }
  }

  if (Modello_Arduino_2022_B.Product1 > 0.0) {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (Modello_Arduino_2022_B.Product1 < 0.0) {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (Modello_Arduino_2022_B.Product1 == 0.0) {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S307>/Discrete-Time Integrator' */

  /* Update for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

  /* S-Function "Servo_microseconds_alettoni_beta_3_wrapper" Block: <S10>/S-Function Builder10 */
  Servo_microseconds_alettoni_beta_3_Update_wrapper
    (&Modello_Arduino_2022_B.DataTypeConversion1_c,
     &Modello_Arduino_2022_DW.SFunctionBuilder10_DSTATE);

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <S10>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper(&Modello_Arduino_2022_B.Sum,
    &Modello_Arduino_2022_DW.SFunctionBuilder4_DSTATE);

  /* Update for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

  /* S-Function "Servo_microseconds_timone_beta_3_wrapper" Block: <S10>/S-Function Builder5 */
  Servo_microseconds_timone_beta_3_Update_wrapper
    (&Modello_Arduino_2022_B.DataTypeConversion2_j,
     &Modello_Arduino_2022_DW.SFunctionBuilder5_DSTATE);

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <S10>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper
    (&Modello_Arduino_2022_B.DataTypeConversion_p,
     &Modello_Arduino_2022_DW.SFunctionBuilder9_DSTATE);

  /* Update for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S4>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper
    (&Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE_n);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Modello_Arduino_2022_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void Modello_Arduino_2022_step1(void)  /* Sample time: [0.04s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  rtb_PulseGenerator = (Modello_Arduino_2022_DW.clockTickCounter <
                        Modello_Arduino_2022_P.PulseGenerator_Duty) &&
    (Modello_Arduino_2022_DW.clockTickCounter >= 0) ?
    Modello_Arduino_2022_P.PulseGenerator_Amp : 0.0;
  if (Modello_Arduino_2022_DW.clockTickCounter >=
      Modello_Arduino_2022_P.PulseGenerator_Period - 1.0) {
    Modello_Arduino_2022_DW.clockTickCounter = 0;
  } else {
    Modello_Arduino_2022_DW.clockTickCounter++;
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
  rtb_PulseGenerator = (Modello_Arduino_2022_DW.clockTickCounter_c <
                        Modello_Arduino_2022_P.PulseGenerator1_Duty) &&
    (Modello_Arduino_2022_DW.clockTickCounter_c >= 0) ?
    Modello_Arduino_2022_P.PulseGenerator1_Amp : 0.0;
  if (Modello_Arduino_2022_DW.clockTickCounter_c >=
      Modello_Arduino_2022_P.PulseGenerator1_Period - 1.0) {
    Modello_Arduino_2022_DW.clockTickCounter_c = 0;
  } else {
    Modello_Arduino_2022_DW.clockTickCounter_c++;
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
void Modello_Arduino_2022_step2(void)  /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S27>/Add2' incorporates:
   *  Constant: '<S27>/Constant4'
   *  Constant: '<S27>/Constant5'
   *  Memory: '<S27>/Memory2'
   */
  Modello_Arduino_2022_DW.Memory2_PreviousInput +=
    Modello_Arduino_2022_P.Constant4_Value_a +
    Modello_Arduino_2022_P.Constant5_Value_a;

  /* Switch: '<S27>/Switch1' */
  if (Modello_Arduino_2022_DW.Memory2_PreviousInput >
      Modello_Arduino_2022_P.Switch1_Threshold_c) {
    /* Sum: '<S27>/Add2' incorporates:
     *  Constant: '<S27>/Constant4'
     */
    Modello_Arduino_2022_DW.Memory2_PreviousInput =
      Modello_Arduino_2022_P.Constant4_Value_a;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* RateTransition: '<S27>/Rate Transition' */
  Modello_Arduino_2022_DW.RateTransition_Buffer0 =
    Modello_Arduino_2022_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void Modello_Arduino_2022_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Modello_Arduino_2022_M, 0,
                sizeof(RT_MODEL_Modello_Arduino_2022_T));

  /* block I/O */
  (void) memset(((void *) &Modello_Arduino_2022_B), 0,
                sizeof(B_Modello_Arduino_2022_T));

  /* states (dwork) */
  (void) memset((void *)&Modello_Arduino_2022_DW, 0,
                sizeof(DW_Modello_Arduino_2022_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    codertarget_arduinobase_inter_T *obj;
    real_T Switch_g;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S571>/S-Function Builder' */

    /* S-Function Block: <S571>/S-Function Builder */
    Mti_Start_wrapper(&Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE);
    Modello_Arduino_2022_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
    Modello_Arduino_2022_PrevZCX.ResettableSubsystem_Reset_ZCE_n =
      UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.ResettableSubsystem_Reset_ZCE_m =
      UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.ResettableSubsystem_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.SampleandHold_Trig_ZCE_k = UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Modello_Arduino_2022_PrevZCX.ResettableSubsystem_p.ResettableSubsystem_Reset_ZCE_l
      = POS_ZCSIG;
    Modello_Arduino_2022_PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_l
      = POS_ZCSIG;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&Modello_Arduino_2022_DW.Memory4_PreviousInput_c[0],
           &Modello_Arduino_2022_P.Memory4_InitialCondition_g[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S571>/S-Function Builder' */

    /* S-Function Block: <S571>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S569>/Unit Delay' */
    Modello_Arduino_2022_DW.UnitDelay_DSTATE_d =
      Modello_Arduino_2022_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE_l = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      Modello_Arduino_2022_DW.Memory5_PreviousInput_l[i] =
        Modello_Arduino_2022_P.Memory5_InitialCondition_d;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[0] =
      Modello_Arduino_2022_P.Memory1_InitialCondition_bc;
    Modello_Arduino_2022_DW.Memory1_PreviousInput_d[1] =
      Modello_Arduino_2022_P.Memory1_InitialCondition_bc;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[0] =
      Modello_Arduino_2022_P.Memory_InitialCondition_o;
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[1] =
      Modello_Arduino_2022_P.Memory_InitialCondition_o;
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[2] =
      Modello_Arduino_2022_P.Memory_InitialCondition_o;
    Modello_Arduino_2022_DW.Memory_PreviousInput_h[3] =
      Modello_Arduino_2022_P.Memory_InitialCondition_o;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    Modello_Arduino_2022_DW.Memory3_PreviousInput_o =
      Modello_Arduino_2022_P.Memory3_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      Modello_Arduino_2022_DW.Memory_PreviousInput_i[i] =
        Modello_Arduino_2022_P.Memory_InitialCondition_at;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      Modello_Arduino_2022_DW.Memory2_PreviousInput_a[i] =
        Modello_Arduino_2022_P.Memory2_InitialCondition_g[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition' */
    Modello_Arduino_2022_DW.RateTransition_Buffer0 =
      Modello_Arduino_2022_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S27>/Switch' incorporates:
     *  Memory: '<S27>/Memory1'
     */
    Modello_Arduino_2022_DW.Memory1_PreviousInput =
      Modello_Arduino_2022_P.Memory1_InitialCondition_p;

    /* InitializeConditions for Sum: '<S27>/Add' incorporates:
     *  Memory: '<S27>/Memory'
     */
    Modello_Arduino_2022_DW.Memory_PreviousInput =
      Modello_Arduino_2022_P.Memory_InitialCondition_au;

    /* InitializeConditions for UnitDelay: '<S565>/Unit Delay' */
    Modello_Arduino_2022_DW.UnitDelay_DSTATE =
      Modello_Arduino_2022_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S342>/Integrator' */
    Modello_Arduino_2022_DW.Integrator_DSTATE =
      Modello_Arduino_2022_P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S392>/Integrator' */
    Modello_Arduino_2022_DW.Integrator_DSTATE_n =
      Modello_Arduino_2022_P.PIDController_InitialConditio_c;
    Modello_Arduino_2022_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S306>/Discrete Washout Filter' */
    Modello_Arduino_2022_DW.DiscreteWashoutFilter_states =
      Modello_Arduino_2022_P.DiscreteWashoutFilter_InitialSt;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    Modello_Arduino_2022_DW.Memory_PreviousInput_n =
      Modello_Arduino_2022_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S572>/Delay Input2'
     *
     * Block description for '<S572>/Delay Input2':
     *
     *  Store in Global RAM
     */
    Modello_Arduino_2022_DW.DelayInput2_DSTATE =
      Modello_Arduino_2022_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Delay: '<S250>/Delay' */
    Modello_Arduino_2022_DW.Delay_DSTATE =
      Modello_Arduino_2022_P.Delay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S285>/Integrator' */
    Modello_Arduino_2022_DW.Integrator_DSTATE_e =
      Modello_Arduino_2022_P.PIDController_InitialConditio_k;

    /* InitializeConditions for DiscreteIntegrator: '<S307>/Discrete-Time Integrator' */
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE =
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_IC_e;
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

    /* S-Function Block: <S10>/S-Function Builder10 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Modello_Arduino_2022_DW.SFunctionBuilder10_DSTATE = initVector[0];
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
          Modello_Arduino_2022_DW.SFunctionBuilder4_DSTATE = initVector[0];
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
          Modello_Arduino_2022_DW.SFunctionBuilder5_DSTATE = initVector[0];
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
          Modello_Arduino_2022_DW.SFunctionBuilder9_DSTATE = initVector[0];
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
          Modello_Arduino_2022_DW.SFunctionBuilder_DSTATE_n = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
    Modello_Arduino_2022_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    Modello_Arduino_2022_DW.clockTickCounter_c = 0;

    /* InitializeConditions for Sum: '<S27>/Add2' incorporates:
     *  Memory: '<S27>/Memory2'
     */
    Modello_Arduino_2022_DW.Memory2_PreviousInput =
      Modello_Arduino_2022_P.Memory2_InitialCondition_o;

    /* SystemInitialize for Enabled SubSystem: '<S569>/Execution_loop' */
    /* Start for MATLABSystem: '<S573>/I2C Read12' */
    Modello_Arduino_2022_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &Modello_Arduino_2022_DW.obj_f;
    Modello_Arduino_2022_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    Modello_Arduino_2022_DW.obj_f.isInitialized = 0;
    Modello_Arduino_2022_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    Modello_Arduino_2022_DW.obj_f.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_f.SampleTime = Modello_Arduino_2022_P.t_AP;
    obj = &Modello_Arduino_2022_DW.obj_f;
    Modello_Arduino_2022_DW.obj_f.isSetupComplete = false;
    Modello_Arduino_2022_DW.obj_f.isInitialized = 1;
    Modello_Arduino_2022_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Modello_Arduino_2022_B.i2cname,
      0);
    Modello_Arduino_2022_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = Modello_Arduino_2022_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    Modello_Arduino_2022_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S573>/I2C Read1' */
    Modello_Arduino_2022_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &Modello_Arduino_2022_DW.obj_p;
    Modello_Arduino_2022_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    Modello_Arduino_2022_DW.obj_p.isInitialized = 0;
    Modello_Arduino_2022_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    Modello_Arduino_2022_DW.obj_p.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_p.SampleTime = Modello_Arduino_2022_P.t_AP;
    obj = &Modello_Arduino_2022_DW.obj_p;
    Modello_Arduino_2022_DW.obj_p.isSetupComplete = false;
    Modello_Arduino_2022_DW.obj_p.isInitialized = 1;
    Modello_Arduino_2022_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Modello_Arduino_2022_B.i2cname,
      0);
    Modello_Arduino_2022_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = Modello_Arduino_2022_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    Modello_Arduino_2022_DW.obj_p.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S573>/S-Function Builder' incorporates:
     *  Outport: '<S573>/T'
     */
    Modello_Arduino_2022_B.SFunctionBuilder_o1 = Modello_Arduino_2022_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S573>/S-Function Builder1' incorporates:
     *  Outport: '<S573>/p'
     */
    Modello_Arduino_2022_B.SFunctionBuilder1 = Modello_Arduino_2022_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S569>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S569>/MATLAB Function' */
    Modello_Arduino_2022_DW.P_ref = 101325.0;
    Modello_Arduino_2022_DW.rl_up = 300.0;
    Modello_Arduino_2022_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S569>/One_time_initialization' */
    One_time_initializatio_Init(&Modello_Arduino_2022_B.One_time_initialization,
      &Modello_Arduino_2022_DW.One_time_initialization,
      &Modello_Arduino_2022_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S569>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S577>/Subsystem1' */
    /* SystemInitialize for Outport: '<S579>/T_0' incorporates:
     *  Inport: '<S579>/T'
     */
    Modello_Arduino_2022_B.T = Modello_Arduino_2022_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S577>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S570>/Subsystem1' */
    /* SystemInitialize for Switch: '<S580>/Switch' incorporates:
     *  Outport: '<S580>/h_to_subtract'
     */
    Modello_Arduino_2022_B.Switch = Modello_Arduino_2022_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S570>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S570>/Subsystem2' */
    /* SystemInitialize for MATLAB Function: '<S581>/Create_message' */
    Modello_Arduino_2022_DW.end_found = false;
    Modello_Arduino_2022_DW.start_found = false;
    Modello_Arduino_2022_DW.counter_k = 0U;
    memset(&Modello_Arduino_2022_DW.message[0], 0, 80U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S581>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S583>/Memory' */
      Modello_Arduino_2022_DW.Memory_PreviousInput_l[i] =
        Modello_Arduino_2022_P.Memory_InitialCondition_a;

      /* SystemInitialize for ComplexToRealImag: '<S583>/Complex to Real-Imag' incorporates:
       *  Outport: '<S583>/Outport'
       */
      Modello_Arduino_2022_B.ComplextoRealImag[i] =
        Modello_Arduino_2022_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S583>/mario' */
    Modello_Arduino_2022_B.indice_dimario = Modello_Arduino_2022_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S581>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S570>/Subsystem2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&Modello_Arduino_2022_DW.riferimenti[0], &tmp[0], sizeof(real32_T) <<
           4U);
    Modello_Arduino_2022_DW.WP_dbP_not_empty = false;
    Modello_Arduino_2022_DW.WP_dbP_AL_not_empty = false;
    Modello_Arduino_2022_DW.test1 = 0.0;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3' */
    Modello_Arduino_2022_DW.counter = 0U;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    Modello_Arduino_2022_DW.Interr_parz = false;
    memset(&Modello_Arduino_2022_DW.message_i[0], 0, 100U * sizeof(uint8_T));
    Modello_Arduino_2022_DW.counter_af = 0U;
    Modello_Arduino_2022_DW.mess_len = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    Modello_Arduino_2022_DW.is_active_c9_Modello_Arduino_20 = 0U;
    Modello_Arduino_2022_DW.i = 0U;

    /* SystemInitialize for Chart: '<S15>/Chart' incorporates:
     *  SubSystem: '<S24>/sendbyte'
     */
    /* Start for MATLABSystem: '<S25>/Serial Transmit' */
    Modello_Arduino_2022_DW.obj_o.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_o.Protocol =
      Modello_Arduino_2022_P.SerialTransmit_Protocol;
    Modello_Arduino_2022_DW.obj_o.isInitialized = 1;
    Modello_Arduino_2022_DW.obj_o.port = 2.0;
    Modello_Arduino_2022_DW.obj_o.dataSizeInBytes = 1.0;
    Modello_Arduino_2022_DW.obj_o.dataType = 0.0;
    Modello_Arduino_2022_DW.obj_o.sendModeEnum = 0.0;
    Modello_Arduino_2022_DW.obj_o.sendFormatEnum = 0.0;
    Switch_g = rt_roundd_snf(Modello_Arduino_2022_DW.obj_o.port);
    if (Switch_g < 256.0) {
      if (Switch_g >= 0.0) {
        tmp_0 = (uint8_T)Switch_g;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    Modello_Arduino_2022_DW.obj_o.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S25>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
    Modello_Arduino_2022_DW.is_active_c23_Modello_Arduino_2 = 0U;
    Modello_Arduino_2022_DW.is_c23_Modello_Arduino_2022 = 0;

    /* SystemInitialize for Triggered SubSystem: '<S251>/Enabled Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S303>/Out1' incorporates:
     *  Outport: '<S303>/Out1'
     */
    Modello_Arduino_2022_B.OutportBufferForOut1 = Modello_Arduino_2022_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S251>/Enabled Subsystem' */

    /* SystemInitialize for Chart: '<S38>/ STATI' */
    Modello_Arduino_2022_DW.is_AUTOMATICA = 0;
    Modello_Arduino_2022_DW.is_active_c26_Modello_Arduino_2 = 0U;
    Modello_Arduino_2022_DW.is_c26_Modello_Arduino_2022 = 0;
    Modello_Arduino_2022_B.switch_manetta = 0.0;
    Modello_Arduino_2022_B.switch_equilibratore = 0.0;
    Modello_Arduino_2022_B.switch_alettoni = 0.0;
    Modello_Arduino_2022_B.switch_timone = 0.0;
    Modello_Arduino_2022_B.throttle_safe = 0.0;
    Modello_Arduino_2022_B.modo = 1.0;

    /* SystemInitialize for Enabled SubSystem: '<S410>/Enabled Subsystem' */
    Model_EnabledSubsystem_Init(&Switch_g,
      &Modello_Arduino_2022_P.EnabledSubsystem_c);

    /* End of SystemInitialize for SubSystem: '<S410>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S410>/Resettable Subsystem' */
    Mo_ResettableSubsystem_Init(&Modello_Arduino_2022_DW.ResettableSubsystem,
      &Modello_Arduino_2022_P.ResettableSubsystem);

    /* End of SystemInitialize for SubSystem: '<S410>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S411>/Enabled Subsystem' */
    Model_EnabledSubsystem_Init(&Modello_Arduino_2022_B.Switch_m,
      &Modello_Arduino_2022_P.EnabledSubsystem_h);

    /* End of SystemInitialize for SubSystem: '<S411>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S411>/Resettable Subsystem' */
    Mo_ResettableSubsystem_Init(&Modello_Arduino_2022_DW.ResettableSubsystem_p,
      &Modello_Arduino_2022_P.ResettableSubsystem_p);

    /* End of SystemInitialize for SubSystem: '<S411>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S412>/MATLAB Function1' */
    Modello_Arduino_2022_DW.Tf_not_empty = false;

    /* SystemInitialize for Enabled SubSystem: '<S434>/Enabled ' */
    /* SystemInitialize for Switch: '<S436>/Switch' incorporates:
     *  Outport: '<S436>/Alarm Safe'
     */
    Modello_Arduino_2022_B.Switch_j = Modello_Arduino_2022_P.AlarmSafe_Y0;

    /* End of SystemInitialize for SubSystem: '<S434>/Enabled ' */

    /* SystemInitialize for Resettable SubSystem: '<S434>/Resettable Subsystem' */
    /* InitializeConditions for Sum: '<S438>/Sum' incorporates:
     *  Memory: '<S438>/Memory'
     */
    Modello_Arduino_2022_DW.Memory_PreviousInput_j =
      Modello_Arduino_2022_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S434>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S417>/MATLAB Function1' */
    Modello_Arduino_2022_DW.alarm = 0.0;

    /* SystemInitialize for Chart: '<S39>/Chart' */
    Modello_Arduino_2022_DW.is_active_c21_Modello_Arduino_2 = 0U;
    Modello_Arduino_2022_DW.is_c21_Modello_Arduino_2022 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' */
    /* InitializeConditions for Memory: '<S440>/Memory' */
    Modello_Arduino_2022_DW.Memory_PreviousInput_c =
      Modello_Arduino_2022_P.Memory_InitialCondition_n;

    /* InitializeConditions for Memory: '<S440>/Memory1' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_i =
      Modello_Arduino_2022_P.Memory1_InitialCondition;

    /* SystemInitialize for Chart: '<S440>/Chart1' */
    Modello_Arduino_2022_DW.temporalCounter_i1 = 0U;
    Modello_Arduino_2022_DW.is_active_c1_Modello_Arduino_20 = 0U;
    Modello_Arduino_2022_DW.is_c1_Modello_Arduino_2022 = 0;

    /* End of SystemInitialize for SubSystem: '<S39>/DECOLLO AUTOMATICO' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem' */
    /* InitializeConditions for Memory: '<S441>/Memory1' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_o =
      Modello_Arduino_2022_P.Memory1_InitialCondition_l;

    /* InitializeConditions for Memory: '<S441>/Memory2' */
    Modello_Arduino_2022_DW.Memory2_PreviousInput_e =
      Modello_Arduino_2022_P.Memory2_InitialCondition_j;

    /* InitializeConditions for Memory: '<S441>/Memory3' */
    Modello_Arduino_2022_DW.Memory3_PreviousInput =
      Modello_Arduino_2022_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S441>/Memory6' */
    Modello_Arduino_2022_DW.Memory6_PreviousInput =
      Modello_Arduino_2022_P.Memory6_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S441>/VETTORIALE' */
    Modello_Arduino_2022_DW.V_ref = 0.0;
    Modello_Arduino_2022_DW.ALT_ref = 0.0;

    /* SystemInitialize for Outport: '<S441>/Out1' */
    Modello_Arduino_2022_B.V_vett = Modello_Arduino_2022_P.Out1_Y0_e;

    /* SystemInitialize for Outport: '<S441>/Out2' */
    Modello_Arduino_2022_B.h_vett = Modello_Arduino_2022_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem1' */
    /* InitializeConditions for Memory: '<S442>/Memory7' */
    Modello_Arduino_2022_DW.Memory7_PreviousInput =
      Modello_Arduino_2022_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S442>/Memory5' */
    Modello_Arduino_2022_DW.Memory5_PreviousInput =
      Modello_Arduino_2022_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S442>/Memory1' */
    Modello_Arduino_2022_DW.Memory1_PreviousInput_b =
      Modello_Arduino_2022_P.Memory1_InitialCondition_b;

    /* InitializeConditions for Memory: '<S442>/Memory2' */
    Modello_Arduino_2022_DW.Memory2_PreviousInput_n =
      Modello_Arduino_2022_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S442>/ALLINEAMENTO' */
    Modello_Arduino_2022_DW.flag_d = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S442>/APPROACH' */
    /* Start for Constant: '<S453>/Constant1' */
    Modello_Arduino_2022_B.Constant1_c =
      Modello_Arduino_2022_P.Constant1_Value_l;

    /* InitializeConditions for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' */
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_DSTATE_h =
      Modello_Arduino_2022_P.DiscreteTimeIntegrator_IC;
    Modello_Arduino_2022_DW.DiscreteTimeIntegrator_PrevRe_i = 2;

    /* SystemInitialize for MATLAB Function: '<S453>/MATLAB Function' */
    Modello_Arduino_2022_DW.x_not_empty = false;
    Modello_Arduino_2022_DW.x_new_not_empty = false;
    Modello_Arduino_2022_DW.cycle_count_not_empty = false;
    Modello_Arduino_2022_DW.eps_not_empty = false;

    /* SystemInitialize for Product: '<S453>/Multiply' incorporates:
     *  Outport: '<S453>/h_ref'
     */
    Modello_Arduino_2022_B.Multiply = Modello_Arduino_2022_P.h_ref_Y0;

    /* SystemInitialize for Outport: '<S453>/flare_data' */
    Modello_Arduino_2022_B.x_f_out = Modello_Arduino_2022_P.flare_data_Y0;
    Modello_Arduino_2022_B.h_f_out = Modello_Arduino_2022_P.flare_data_Y0;
    Modello_Arduino_2022_B.k_x_out = Modello_Arduino_2022_P.flare_data_Y0;
    Modello_Arduino_2022_B.h_c_out = Modello_Arduino_2022_P.flare_data_Y0;

    /* SystemInitialize for Outport: '<S453>/landing_abort' */
    Modello_Arduino_2022_B.no_solution = Modello_Arduino_2022_P.landing_abort_Y0;

    /* End of SystemInitialize for SubSystem: '<S442>/APPROACH' */

    /* SystemInitialize for Chart: '<S442>/Chart1' */
    Modello_Arduino_2022_DW.is_active_c10_Modello_Arduino_2 = 0U;
    Modello_Arduino_2022_DW.is_c10_Modello_Arduino_2022 = 0;

    /* SystemInitialize for Enabled SubSystem: '<S442>/FLARE' */
    /* Start for Constant: '<S457>/Constant1' */
    Modello_Arduino_2022_B.Constant1 = Modello_Arduino_2022_P.Constant1_Value_j;

    /* SystemInitialize for Sum: '<S457>/Sum2' incorporates:
     *  Outport: '<S457>/h_ref'
     */
    Modello_Arduino_2022_B.Sum2 = Modello_Arduino_2022_P.h_ref_Y0_h;

    /* End of SystemInitialize for SubSystem: '<S442>/FLARE' */

    /* SystemInitialize for Triggered SubSystem: '<S442>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S467>/ ' incorporates:
     *  Inport: '<S467>/In'
     */
    Modello_Arduino_2022_B.In[0] = Modello_Arduino_2022_P._Y0_a[0];
    Modello_Arduino_2022_B.In[1] = Modello_Arduino_2022_P._Y0_a[1];

    /* End of SystemInitialize for SubSystem: '<S442>/Sample and Hold' */

    /* SystemInitialize for MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' incorporates:
     *  Outport: '<S442>/TAS_AL'
     */
    Modello_Arduino_2022_B.velocita = Modello_Arduino_2022_P.TAS_AL_Y0;

    /* SystemInitialize for MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
     *  Outport: '<S442>/QUOTA_AL'
     */
    Modello_Arduino_2022_B.QUOTA_f = Modello_Arduino_2022_P.QUOTA_AL_Y0;

    /* SystemInitialize for Gain: '<S460>/Gain' incorporates:
     *  Outport: '<S442>/H_LAT'
     */
    Modello_Arduino_2022_B.Gain = Modello_Arduino_2022_P.H_LAT_Y0;

    /* SystemInitialize for Gain: '<S461>/Gain' incorporates:
     *  Outport: '<S442>/H_LONG'
     */
    Modello_Arduino_2022_B.Gain_h = Modello_Arduino_2022_P.H_LONG_Y0;

    /* SystemInitialize for Outport: '<S442>/H_ALT' */
    Modello_Arduino_2022_B.h_Home = Modello_Arduino_2022_P.H_ALT_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem2' */
    /* InitializeConditions for Memory: '<S443>/Memory4' */
    Modello_Arduino_2022_DW.Memory4_PreviousInput =
      Modello_Arduino_2022_P.Memory4_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S443>/WAYPOINTS' */
    Modello_Arduino_2022_DW.flag_j = 0.0;
    Modello_Arduino_2022_DW.lat1 = 0.0;
    Modello_Arduino_2022_DW.long1 = 0.0;

    /* SystemInitialize for Saturate: '<S443>/saturatore V' incorporates:
     *  Outport: '<S443>/VELOCITA'
     */
    Modello_Arduino_2022_B.VELOCITA = Modello_Arduino_2022_P.VELOCITA_Y0;

    /* SystemInitialize for Outport: '<S443>/Out3' */
    Modello_Arduino_2022_B.QUOTA = Modello_Arduino_2022_P.Out3_Y0_d;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem3' */
    /* SystemInitialize for MATLAB Function: '<S444>/GO_HOME' */
    Modello_Arduino_2022_DW.flag = 0.0;

    /* SystemInitialize for Outport: '<S444>/Out1' */
    Modello_Arduino_2022_B.V_goHome = Modello_Arduino_2022_P.Out1_Y0_i;

    /* SystemInitialize for Outport: '<S444>/Out2' */
    Modello_Arduino_2022_B.h_goHome = Modello_Arduino_2022_P.Out2_Y0_l;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem3' */

    /* SystemInitialize for Enabled SubSystem: '<S556>/Subsystem1' */
    /* SystemInitialize for MATLAB Function: '<S564>/MATLAB Function' */
    Modello_Arduino_2022_DW.start_found_d = false;
    Modello_Arduino_2022_DW.counter_a = 0U;
    for (i = 0; i < 31; i++) {
      Modello_Arduino_2022_DW.message_e[i] = 0U;
    }

    /* End of SystemInitialize for MATLAB Function: '<S564>/MATLAB Function' */

    /* SystemInitialize for Enabled SubSystem: '<S564>/Subsystem2' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Modello_Arduino_2022_B.ByteUnpack_o2_h[0] =
      Modello_Arduino_2022_P.Out2_Y0_lm;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Modello_Arduino_2022_B.ByteUnpack_o3[0] = Modello_Arduino_2022_P.Out3_Y0_n;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Modello_Arduino_2022_B.ByteUnpack_o2_h[1] =
      Modello_Arduino_2022_P.Out2_Y0_lm;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Modello_Arduino_2022_B.ByteUnpack_o3[1] = Modello_Arduino_2022_P.Out3_Y0_n;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Modello_Arduino_2022_B.ByteUnpack_o2_h[2] =
      Modello_Arduino_2022_P.Out2_Y0_lm;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Modello_Arduino_2022_B.ByteUnpack_o3[2] = Modello_Arduino_2022_P.Out3_Y0_n;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out2'
     */
    Modello_Arduino_2022_B.ByteUnpack_o2_h[3] =
      Modello_Arduino_2022_P.Out2_Y0_lm;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out3'
     */
    Modello_Arduino_2022_B.ByteUnpack_o3[3] = Modello_Arduino_2022_P.Out3_Y0_n;

    /* SystemInitialize for S-Function (byte2any_svd): '<S568>/Byte Unpack' incorporates:
     *  Outport: '<S568>/Out4'
     */
    Modello_Arduino_2022_B.ByteUnpack_o4[0] = Modello_Arduino_2022_P.Out4_Y0_j;
    Modello_Arduino_2022_B.ByteUnpack_o4[1] = Modello_Arduino_2022_P.Out4_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S564>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S556>/Subsystem1' */

    /* Start for MATLABSystem: '<S556>/Serial Receive' */
    Modello_Arduino_2022_DW.obj_c.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_c.Protocol =
      Modello_Arduino_2022_P.SerialReceive_Protocol;
    Modello_Arduino_2022_DW.obj_c.isInitialized = 1;
    Modello_Arduino_2022_DW.obj_c.DataTypeWidth = 1U;
    varargin_1 = 31U * Modello_Arduino_2022_DW.obj_c.DataTypeWidth;
    if (varargin_1 > 65535U) {
      varargin_1 = 65535U;
    }

    Modello_Arduino_2022_DW.obj_c.DataSizeInBytes = (uint16_T)varargin_1;
    MW_SCI_Open(1);
    Modello_Arduino_2022_DW.obj_c.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S556>/Serial Receive' */

    /* Start for MATLABSystem: '<S570>/Serial Receive1' */
    Modello_Arduino_2022_DW.obj_e.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_e.Protocol =
      Modello_Arduino_2022_P.SerialReceive1_Protocol;
    Modello_Arduino_2022_DW.obj_e.isInitialized = 1;
    Modello_Arduino_2022_DW.obj_e.DataTypeWidth = 1U;
    if (Modello_Arduino_2022_DW.obj_e.DataTypeWidth > 2047) {
      Modello_Arduino_2022_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      Modello_Arduino_2022_DW.obj_e.DataSizeInBytes = (uint16_T)
        (Modello_Arduino_2022_DW.obj_e.DataTypeWidth << 5);
    }

    MW_SCI_Open(0);
    Modello_Arduino_2022_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S570>/Serial Receive1' */

    /* Start for MATLABSystem: '<S556>/Serial Transmit' */
    Modello_Arduino_2022_DW.obj.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj.Protocol =
      Modello_Arduino_2022_P.SerialTransmit_Protocol_o;
    Modello_Arduino_2022_DW.obj.isInitialized = 1;
    Modello_Arduino_2022_DW.obj.port = 1.0;
    Modello_Arduino_2022_DW.obj.dataSizeInBytes = 1.0;
    Modello_Arduino_2022_DW.obj.dataType = 0.0;
    Modello_Arduino_2022_DW.obj.sendModeEnum = 0.0;
    Modello_Arduino_2022_DW.obj.sendFormatEnum = 0.0;
    Switch_g = rt_roundd_snf(Modello_Arduino_2022_DW.obj.port);
    if (Switch_g < 256.0) {
      if (Switch_g >= 0.0) {
        tmp_0 = (uint8_T)Switch_g;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    Modello_Arduino_2022_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S556>/Serial Transmit' */

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    Modello_Arduino_2022_DW.obj_d.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_d.isInitialized = 1;
    digitalIOSetup(13, 1);
    Modello_Arduino_2022_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    Modello_Arduino_2022_DW.obj_b.matlabCodegenIsDeleted = false;
    Modello_Arduino_2022_DW.obj_b.isInitialized = 1;
    digitalIOSetup(44, 1);
    Modello_Arduino_2022_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Modello_Arduino_2022_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S569>/One_time_initialization' */
  One_time_initializatio_Term(&Modello_Arduino_2022_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S569>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S569>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S573>/I2C Read12' */
  obj = &Modello_Arduino_2022_DW.obj_f;
  if (!Modello_Arduino_2022_DW.obj_f.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Modello_Arduino_2022_DW.obj_f.isInitialized == 1) &&
        Modello_Arduino_2022_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S573>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S573>/I2C Read1' */
  obj = &Modello_Arduino_2022_DW.obj_p;
  if (!Modello_Arduino_2022_DW.obj_p.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Modello_Arduino_2022_DW.obj_p.isInitialized == 1) &&
        Modello_Arduino_2022_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S573>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S569>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S556>/Serial Receive' */
  if (!Modello_Arduino_2022_DW.obj_c.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S556>/Serial Receive' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S15>/Chart' incorporates:
   *  SubSystem: '<S24>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  if (!Modello_Arduino_2022_DW.obj_o.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S570>/Serial Receive1' */
  if (!Modello_Arduino_2022_DW.obj_e.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S570>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<S556>/Serial Transmit' */
  if (!Modello_Arduino_2022_DW.obj.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S556>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!Modello_Arduino_2022_DW.obj_d.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!Modello_Arduino_2022_DW.obj_b.matlabCodegenIsDeleted) {
    Modello_Arduino_2022_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
