/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PROVA_FINALE_LOAD_ARDUINO_13_10.c
 *
 * Code generated for Simulink model 'PROVA_FINALE_LOAD_ARDUINO_13_10'.
 *
 * Model version                  : 5.19
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 14:08:57 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PROVA_FINALE_LOAD_ARDUINO_13_10.h"
#include "PROVA_FINALE_LOAD_ARDUINO_13_10_private.h"

/* Named constants for Chart: '<S40>/SELEZIONE MODALITA\'  HOLD//SELECT' */
#define PROVA_FINALE_LOAD_ARDUI_IN_Hold ((uint8_T)1U)
#define PROVA_FINALE_LOAD_ARD_IN_Select ((uint8_T)2U)

/* Named constants for Chart: '<S38>/ STATI' */
#define PROVA_FINALE_LOAD_ARDUI_IN_Safe ((uint8_T)5U)
#define PROVA_FINALE_LOAD_ARDUI_IN_TEST ((uint8_T)3U)
#define PROVA_FINALE_LOAD_AR_IN_Go_Home ((uint8_T)2U)
#define PROVA_FINALE_LOAD_AR_IN_MANUALE ((uint8_T)4U)
#define PROVA_FINALE_LOAD_A_IN_Stand_By ((uint8_T)6U)
#define PROVA_FINALE_LOAD_A_IN_WAYPOINT ((uint8_T)5U)
#define PROVA_FINALE_LOAD_IN_AUTOMATICA ((uint8_T)1U)
#define PROVA_FINALE_LOAD_IN_VETTORIALE ((uint8_T)4U)
#define PROVA_FINA_IN_Intervento_Pilota ((uint8_T)3U)
#define PROVA_FIN_IN_DECOLLO_AUTOMATICO ((uint8_T)2U)
#define PROVA_IN_ATTERRAGGIO_AUTOMATICO ((uint8_T)1U)

/* Named constants for Chart: '<S39>/Chart' */
#define PROVA_FINALE_LOAD_ARDUINO_IN_In ((uint8_T)4U)
#define PROVA_FINALE_LOAD_ARD_IN_GoHome ((uint8_T)3U)
#define PROVA_FINALE_LOAD_A_IN_Waypoint ((uint8_T)6U)
#define PROVA_FINALE_LOAD_IN_Vettoriale ((uint8_T)5U)
#define PROVA_FINALE_LOA_IN_AutoLanding ((uint8_T)1U)
#define PROVA_FINALE_LOA_IN_AutoTakeoff ((uint8_T)2U)

/* Named constants for Chart: '<S438>/Chart1' */
#define PROVA_FINALE_LOAD_IN_Fase_0_ATO ((uint8_T)1U)
#define PROVA_FINALE_LOAD_IN_Fase_1_ATO ((uint8_T)2U)
#define PROVA_FINALE_LOAD_IN_Fase_2_ATO ((uint8_T)3U)
#define PROVA_FINALE_LOAD_IN_Fase_3_ATO ((uint8_T)4U)
#define PROVA_FINALE_LOAD_IN_Fase_4_ATO ((uint8_T)5U)

/* Named constants for Chart: '<S440>/Chart1' */
#define PROVA_FINALE_LOAD_ARDU_IN_Abort ((uint8_T)1U)
#define PROVA_FINALE_LOAD_ARDU_IN_Flare ((uint8_T)5U)
#define PROVA_FINALE_LOAD_A_IN_Approach ((uint8_T)4U)
#define PROVA_FINALE_LOAD_IN_Allignment ((uint8_T)2U)
#define PROVA_FINALE_LOA_IN_Allignment1 ((uint8_T)3U)

const uint16_T PROVA_FINALE_LOAD_ARDUINO_13_10_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_PROVA_FINALE_LOAD_ARDUINO_1_T PROVA_FINALE_LOAD_ARDUINO_13__B;

/* Block states (default storage) */
DW_PROVA_FINALE_LOAD_ARDUINO__T PROVA_FINALE_LOAD_ARDUINO_13_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PROVA_FINALE_LOAD_ARD_T PROVA_FINALE_LOAD_ARDUI_PrevZCX;

/* Real-time model */
static RT_MODEL_PROVA_FINALE_LOAD_AR_T PROVA_FINALE_LOAD_ARDUINO_13_M_;
RT_MODEL_PROVA_FINALE_LOAD_AR_T *const PROVA_FINALE_LOAD_ARDUINO_13_M =
  &PROVA_FINALE_LOAD_ARDUINO_13_M_;

/* Forward declaration for local functions */
static void PROVA_FINALE_LOAD_ARDU_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T PROVA_FINALE_LOAD_A_ifWhileCond(const boolean_T x[100]);
static void PROVA_FINALE_LOAD_ARDU_eml_find(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static boolean_T PROVA_FINALE_LOAD_ifWhileCond_o(const boolean_T x[5]);
static void PROVA_FINALE_LOAD_AR_eml_find_o(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void PROVA_FINALE_LOAD_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T PROVA_FINALE_LOAD_AR_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T PROVA_FINALE_LOAD__copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void PROVA_FINALE_LOAD_ARD_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T PROVA_FINALE_LOAD_AR_str2double(const char_T s[2]);
static boolean_T PROVA_FINALE_LOAD__copydigits_k(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void PROVA_FINALE_LOAD_A_readfloat_d(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T PROVA_FINALE_LOAD__str2double_l(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T PROVA_FINALE_LOAD_AR_isUnitImag(const char_T s[3], int32_T k);
static void PROVA_FINALE_LO_readNonFinite_l(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T PROVA_FINALE_LOAD_copydigits_k3(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T PROVA_FINALE_LOA_copyexponent_k(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void PROVA_FINALE_LOAD__readfloat_dt(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T PROVA_FINALE_LOAD_str2double_lv(const char_T s[3]);
static void PROVA_FINALE_L_readNonFinite_ln(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T PROVA_FINALE_LOA_copydigits_k3z(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T PROVA_FINALE_LO_copyexponent_kd(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void PROVA_FINALE_LOAD_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T PROVA_FINALE_LOA_str2double_lvk(char_T s);
static real_T PROVA_FINALE_LOAD_ARDUI_hex2dec(const char_T s[2]);
static void PROVA_FINALE_LOAD_ARDU_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
static void PROVA_FINALE_LOAD_ARDUINO_13_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector);
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
void PROVA_FINALE_LOAD_ARDUINO_13_10_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PROVA_FINALE_LOAD_ARDUINO_13_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(PROVA_FINALE_LOAD_ARDUINO_13_M, 2));
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
  (PROVA_FINALE_LOAD_ARDUINO_13_M->Timing.TaskCounters.TID[1])++;
  if ((PROVA_FINALE_LOAD_ARDUINO_13_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    PROVA_FINALE_LOAD_ARDUINO_13_M->Timing.TaskCounters.TID[1] = 0;
  }

  (PROVA_FINALE_LOAD_ARDUINO_13_M->Timing.TaskCounters.TID[2])++;
  if ((PROVA_FINALE_LOAD_ARDUINO_13_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.1s, 0.0s] */
    PROVA_FINALE_LOAD_ARDUINO_13_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S408>/Enabled Subsystem'
 *    '<S409>/Enabled Subsystem'
 */
void PROVA_EnabledSubsystem_Init(real_T *rty_u0, P_EnabledSubsystem_PROVA_FINA_T
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
void PROVA_FINA_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0, P_EnabledSubsystem_PROVA_FINA_T *localP)
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
void PR_ResettableSubsystem_Init(DW_ResettableSubsystem_PROVA__T *localDW,
  P_ResettableSubsystem_PROVA_F_T *localP)
{
  /* InitializeConditions for Memory: '<S419>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * System reset for atomic system:
 *    '<S408>/Resettable Subsystem'
 *    '<S409>/Resettable Subsystem'
 */
void P_ResettableSubsystem_Reset(DW_ResettableSubsystem_PROVA__T *localDW,
  P_ResettableSubsystem_PROVA_F_T *localP)
{
  /* InitializeConditions for Memory: '<S419>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S408>/Resettable Subsystem'
 *    '<S409>/Resettable Subsystem'
 */
real_T PROVA_F_ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_PROVA__T *localDW, P_ResettableSubsystem_PROVA_F_T
  *localP, ZCE_ResettableSubsystem_PROVA_T *localZCE)
{
  real_T rty_Time_0;

  /* Outputs for Resettable SubSystem: '<S408>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S418>/Reset'
   */
  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_f != POS_ZCSIG))
  {
    P_ResettableSubsystem_Reset(localDW, localP);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_f = (ZCSigState)(rtu_Reset > 0);

  /* Sum: '<S419>/Sum' incorporates:
   *  Constant: '<S419>/Constant4'
   *  Memory: '<S419>/Memory'
   */
  rty_Time_0 = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP +
    localDW->Memory_PreviousInput;

  /* Update for Memory: '<S419>/Memory' */
  localDW->Memory_PreviousInput = rty_Time_0;

  /* End of Outputs for SubSystem: '<S408>/Resettable Subsystem' */
  return rty_Time_0;
}

/* System initialize for enable system: '<S554>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_PRO_T *localB,
  DW_One_time_initialization_PR_T *localDW, P_One_time_initialization_PRO_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S561>/I2C Read' */
  localDW->obj_kf.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_kf;
  localDW->obj_kf.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_kf.isInitialized = 0;
  localDW->obj_kf.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_kf.matlabCodegenIsDeleted = false;
  localDW->obj_kf.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_kf;
  localDW->obj_kf.isSetupComplete = false;
  localDW->obj_kf.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_kf.BusSpeed = 100000U;
  varargin_1 = localDW->obj_kf.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_kf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read1' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read2' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read3' */
  localDW->obj_k4.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k4;
  localDW->obj_k4.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k4.isInitialized = 0;
  localDW->obj_k4.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k4.matlabCodegenIsDeleted = false;
  localDW->obj_k4.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_k4;
  localDW->obj_k4.isSetupComplete = false;
  localDW->obj_k4.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k4.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k4.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k4.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read4' */
  localDW->obj_co.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_co;
  localDW->obj_co.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_co.isInitialized = 0;
  localDW->obj_co.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_co.matlabCodegenIsDeleted = false;
  localDW->obj_co.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_co;
  localDW->obj_co.isSetupComplete = false;
  localDW->obj_co.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_co.BusSpeed = 100000U;
  varargin_1 = localDW->obj_co.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_co.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read5' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read6' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read7' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read8' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read10' */
  localDW->obj_d0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d0;
  localDW->obj_d0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d0.isInitialized = 0;
  localDW->obj_d0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d0.matlabCodegenIsDeleted = false;
  localDW->obj_d0.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_d0;
  localDW->obj_d0.isSetupComplete = false;
  localDW->obj_d0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Read11' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S561>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S561>/I2C Write2' */
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

  /* Start for MATLABSystem: '<S561>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S561>/I2C Read12' */
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

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read' incorporates:
   *  Outport: '<S561>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read1' incorporates:
   *  Outport: '<S561>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read2' incorporates:
   *  Outport: '<S561>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read3' incorporates:
   *  Outport: '<S561>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read4' incorporates:
   *  Outport: '<S561>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read5' incorporates:
   *  Outport: '<S561>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read6' incorporates:
   *  Outport: '<S561>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read7' incorporates:
   *  Outport: '<S561>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read8' incorporates:
   *  Outport: '<S561>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read9' incorporates:
   *  Outport: '<S561>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read10' incorporates:
   *  Outport: '<S561>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S561>/I2C Read11' incorporates:
   *  Outport: '<S561>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S561>/Byte Unpack' incorporates:
     *  Outport: '<S561>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S554>/One_time_initialization' */
void PRO_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_PRO_T *localB, DW_One_time_initialization_PR_T
  *localDW, P_One_time_initialization_PRO_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S554>/One_time_initialization' incorporates:
   *  EnablePort: '<S561>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S561>/I2C Write3' incorporates:
     *  ArithShift: '<S561>/Shift Arithmetic1'
     *  Constant: '<S561>/registro memoria2 '
     *  DataTypeConversion: '<S561>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S561>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S561>/I2C Read' */
    if (localDW->obj_kf.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_kf.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S561>/I2C Read' */

    /* MATLABSystem: '<S561>/I2C Read1' */
    if (localDW->obj_o.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_o.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read1' */

    /* MATLABSystem: '<S561>/I2C Read2' */
    if (localDW->obj_d.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_d.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read2' */

    /* MATLABSystem: '<S561>/I2C Read3' */
    if (localDW->obj_k4.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_k4.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S561>/I2C Read3' */

    /* MATLABSystem: '<S561>/I2C Read4' */
    if (localDW->obj_co.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_co.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read4' */

    /* MATLABSystem: '<S561>/I2C Read5' */
    if (localDW->obj_k.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_k.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read5' */

    /* MATLABSystem: '<S561>/I2C Read6' */
    if (localDW->obj_b.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_b.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read6' */

    /* MATLABSystem: '<S561>/I2C Read7' */
    if (localDW->obj_c.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_c.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read7' */

    /* MATLABSystem: '<S561>/I2C Read8' */
    if (localDW->obj_i.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_i.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read8' */

    /* MATLABSystem: '<S561>/I2C Read9' */
    if (localDW->obj.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read9' */

    /* MATLABSystem: '<S561>/I2C Read10' */
    if (localDW->obj_d0.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_d0.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read10' */

    /* MATLABSystem: '<S561>/I2C Read11' */
    if (localDW->obj_l.SampleTime != PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      localDW->obj_l.SampleTime = PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
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
      /* MATLABSystem: '<S561>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S561>/I2C Read11' */

    /* MATLABSystem: '<S561>/I2C Write1' incorporates:
     *  Constant: '<S561>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S561>/I2C Write2' incorporates:
     *  Constant: '<S561>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_in.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S561>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_d01.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S561>/I2C Read12' */
    if (localDW->obj_ir.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_ir.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_ir.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S561>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S561>/Byte Unpack' */

    /* Unpack: <S561>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S554>/One_time_initialization' */
}

/* Termination for enable system: '<S554>/One_time_initialization' */
void One_time_initializatio_Term(DW_One_time_initialization_PR_T *localDW)
{
  codertarget_arduinobase_int_m_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S561>/I2C Read' */
  obj = &localDW->obj_kf;
  if (!localDW->obj_kf.matlabCodegenIsDeleted) {
    localDW->obj_kf.matlabCodegenIsDeleted = true;
    if ((localDW->obj_kf.isInitialized == 1) && localDW->obj_kf.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read1' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read2' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read3' */
  obj = &localDW->obj_k4;
  if (!localDW->obj_k4.matlabCodegenIsDeleted) {
    localDW->obj_k4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k4.isInitialized == 1) && localDW->obj_k4.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read4' */
  obj = &localDW->obj_co;
  if (!localDW->obj_co.matlabCodegenIsDeleted) {
    localDW->obj_co.matlabCodegenIsDeleted = true;
    if ((localDW->obj_co.isInitialized == 1) && localDW->obj_co.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read5' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read6' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read7' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read8' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read10' */
  obj = &localDW->obj_d0;
  if (!localDW->obj_d0.matlabCodegenIsDeleted) {
    localDW->obj_d0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d0.isInitialized == 1) && localDW->obj_d0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read11' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S561>/I2C Write1' */
  obj_0 = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S561>/I2C Write2' */
  obj_0 = &localDW->obj_in;
  if (!localDW->obj_in.matlabCodegenIsDeleted) {
    localDW->obj_in.matlabCodegenIsDeleted = true;
    if ((localDW->obj_in.isInitialized == 1) && localDW->obj_in.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S561>/I2C Write3' */
  obj_0 = &localDW->obj_d01;
  if (!localDW->obj_d01.matlabCodegenIsDeleted) {
    localDW->obj_d01.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d01.isInitialized == 1) &&
        localDW->obj_d01.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S561>/I2C Read12' */
  obj = &localDW->obj_ir;
  if (!localDW->obj_ir.matlabCodegenIsDeleted) {
    localDW->obj_ir.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ir.isInitialized == 1) && localDW->obj_ir.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S561>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void PROVA_FINALE_LOAD_ARDU_find_254(const uint8_T pack[100], real_T
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
static boolean_T PROVA_FINALE_LOAD_A_ifWhileCond(const boolean_T x[100])
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD_ARDU_eml_find(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOAD_ifWhileCond_o(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD_AR_eml_find_o(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOAD_AR_copydigits(char_T s1[4], int32_T *idx,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOAD__copyexponent(char_T s1[4], int32_T *idx,
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

      PROVA_FINALE_LOAD_ARDUINO_13__B.kexp_d = *k;
      b_k = *k;
      b_success = PROVA_FINALE_LOAD_AR_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > PROVA_FINALE_LOAD_ARDUINO_13__B.kexp_d));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD_ARD_readfloat(char_T s1[4], int32_T *idx, const
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
            PROVA_FINALE_LOAD_ARD_readfloat(s1, idx, s, k, false, &isneg,
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
      PROVA_FINALE_LOAD_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = PROVA_FINALE_LOAD_AR_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = PROVA_FINALE_LOAD__copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static creal_T PROVA_FINALE_LOAD_AR_str2double(const char_T s[2])
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
  PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn = 0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.k_l = 0;
  while ((PROVA_FINALE_LOAD_ARDUINO_13__B.k_l + 1 <= 2) && (c[(uint8_T)
          s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] & 127] ||
          (s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] == '\x00'))) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.k_l++;
  }

  isimag1 = false;
  b_finite = true;
  PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j = 0.0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h = 1;
  PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[0] = '\x00';
  PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[1] = '\x00';
  PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[2] = '\x00';
  PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.k_l + 1 <= 2)) {
    if (s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] == '-') {
      isneg = !isneg;
      PROVA_FINALE_LOAD_ARDUINO_13__B.k_l++;
    } else if ((s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] == ',') ||
               (s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] == '+') || c[(uint8_T)
               s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] & 127]) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.k_l++;
    } else {
      exitg1 = true;
    }
  }

  success = (PROVA_FINALE_LOAD_ARDUINO_13__B.k_l + 1 <= 2);
  if (success && isneg) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[0] = '-';
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h = 2;
  }

  PROVA_FINALE_LOAD_ARDUINO_13__B.e_k = PROVA_FINALE_LOAD_ARDUINO_13__B.k_l + 1;
  if (success) {
    if ((PROVA_FINALE_LOAD_ARDUINO_13__B.k_l + 1 <= 2) &&
        ((s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] == 'j') ||
         (s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_l] == 'i'))) {
      isimag1 = true;
      PROVA_FINALE_LOAD_ARDUINO_13__B.e_k = PROVA_FINALE_LOAD_ARDUINO_13__B.k_l
        + 2;
      while ((PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2) && (c[(uint8_T)s[1] &
              127] || (s[1] == '\x00') || (s[1] == ','))) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.e_k = 3;
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2) && (s[1] == '*')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.e_k = 3;
        PROVA_FINALE_LOAD_ARD_readfloat(PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h, s,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.e_k, false, &isneg, &b_finite,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j, &unusedU2, &success);
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h
          - 1] = '1';
        PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h++;
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.e_k = PROVA_FINALE_LOAD_ARDUINO_13__B.k_l
        + 1;
      PROVA_FINALE_LOAD_readNonFinite(s, &PROVA_FINALE_LOAD_ARDUINO_13__B.e_k,
        &b_finite, &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j);
      if (b_finite) {
        success = PROVA_FINALE_LOAD_AR_copydigits
          (PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o,
           &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h, s,
           &PROVA_FINALE_LOAD_ARDUINO_13__B.e_k, true);
        if (success) {
          success = PROVA_FINALE_LOAD__copyexponent
            (PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o,
             &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h, s,
             &PROVA_FINALE_LOAD_ARDUINO_13__B.e_k);
        }
      } else {
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h >= 2) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[0] == '-')) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h = 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[0] = ' ';
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j =
            -PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2)) {
        tmp = s[PROVA_FINALE_LOAD_ARDUINO_13__B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2) &&
          (s[PROVA_FINALE_LOAD_ARDUINO_13__B.e_k - 1] == '*')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2)) {
          tmp = s[PROVA_FINALE_LOAD_ARDUINO_13__B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2) {
        tmp = s[PROVA_FINALE_LOAD_ARDUINO_13__B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2)) {
      tmp = s[PROVA_FINALE_LOAD_ARDUINO_13__B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn = 1;
  }

  if (success && (PROVA_FINALE_LOAD_ARDUINO_13__B.e_k <= 2)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h -
      1] = ' ';
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h++;
    PROVA_FINALE_LOAD_ARD_readfloat(PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h, s,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.e_k, true, &success, &isneg,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d, &unusedU2, &c_success);
    if (isneg) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn++;
    }

    success = (c_success && (PROVA_FINALE_LOAD_ARDUINO_13__B.e_k > 2) &&
               (isimag1 != success) && unusedU2);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d = 0.0;
  }

  if (success) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_h -
      1] = '\x00';
    switch (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn) {
     case 2:
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn = sscanf
        (&PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[0], "%lf %lf",
         &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j,
         &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn != 2) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j = (rtNaN);
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d = (rtNaN);
      }
      break;

     case 1:
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn = sscanf
        (&PROVA_FINALE_LOAD_ARDUINO_13__B.s1_o[0], "%lf",
         &PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_g);
      if (b_finite) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn == 1) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j =
            PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_g;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j = (rtNaN);
        }
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bn == 1) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d =
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_g;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d;
      x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j;
    } else {
      x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_j;
      x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_d;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOAD__copydigits_k(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD_A_readfloat_d(char_T s1_data[], int32_T *idx,
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
          PROVA_FINALE_LOAD_A_readfloat_d(s1_data, idx, s_data, k, n, false,
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
        *success = PROVA_FINALE_LOAD__copydigits_k(s1_data, &b_idx, s_data, &h_k,
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
              isneg = PROVA_FINALE_LOAD__copydigits_k(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static creal_T PROVA_FINALE_LOAD__str2double_l(const char_T s_data[], const
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
    PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread = 0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.k <= s_size[1])) {
      tmp = s_data[PROVA_FINALE_LOAD_ARDUINO_13__B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.k++;
      } else {
        exitg1 = true;
      }
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.s1_size[0] = 1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1_size[1] = (int8_T)(s_size[1] + 2);
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= PROVA_FINALE_LOAD_ARDUINO_13__B.idx) {
      memset(&PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data[0], 0,
             (PROVA_FINALE_LOAD_ARDUINO_13__B.idx + 1) * sizeof(char_T));
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.idx = 1;
    PROVA_FINALE_LOAD_A_readfloat_d(PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.idx, s_data,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.k, s_size[1], true, &isimag1, &isfinite1,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread = 1;
    }

    if (success) {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.k <= s_size[1]) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data[PROVA_FINALE_LOAD_ARDUINO_13__B.idx
          - 1] = ' ';
        PROVA_FINALE_LOAD_ARDUINO_13__B.idx++;
        PROVA_FINALE_LOAD_A_readfloat_d(PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.idx, s_data,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.k, s_size[1], true, &unusedU0,
          &success, &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2, &foundsign,
          &c_success);
        if (success) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread++;
        }

        success = (c_success && ((PROVA_FINALE_LOAD_ARDUINO_13__B.k > s_size[1])
                    && ((isimag1 != unusedU0) && foundsign)));
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2 = 0.0;
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2 = 0.0;
    }

    if (success) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data[PROVA_FINALE_LOAD_ARDUINO_13__B.idx
        - 1] = '\x00';
      switch (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread) {
       case 2:
        PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread = sscanf
          (&PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data[0], "%lf %lf",
           &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1,
           &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread != 2) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1 = (rtNaN);
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread = sscanf
          (&PROVA_FINALE_LOAD_ARDUINO_13__B.s1_data[0], "%lf",
           &PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1);
        if (isfinite1) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread == 1) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1 =
              PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1 = (rtNaN);
          }
        } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread == 1) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2 =
            PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2;
        x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1;
      } else {
        x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1;
        x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOAD_AR_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LO_readNonFinite_l(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOAD_copydigits_k3(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOA_copyexponent_k(char_T s1[5], int32_T *idx,
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

      PROVA_FINALE_LOAD_ARDUINO_13__B.kexp = *k;
      b_k = *k;
      b_success = PROVA_FINALE_LOAD_copydigits_k3(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > PROVA_FINALE_LOAD_ARDUINO_13__B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD__readfloat_dt(char_T s1[5], int32_T *idx, const
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
    if (PROVA_FINALE_LOAD_AR_isUnitImag(s, b_k)) {
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
          PROVA_FINALE_LOAD__readfloat_dt(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      PROVA_FINALE_LO_readNonFinite_l(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = PROVA_FINALE_LOAD_copydigits_k3(s1, idx, s, k, true);
        if (*success) {
          *success = PROVA_FINALE_LOA_copyexponent_k(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static creal_T PROVA_FINALE_LOAD_str2double_lv(const char_T s[3])
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
  PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b = 0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.k_b = 1;
  exitg1 = false;
  while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.k_b <= 3)) {
    tmp = s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_b - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n = 0.0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n = 1;
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.b_k = 0;
       PROVA_FINALE_LOAD_ARDUINO_13__B.b_k < 5;
       PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] =
      '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.k_b <= 3)) {
    tmp = s[PROVA_FINALE_LOAD_ARDUINO_13__B.k_b - 1];
    if (tmp == '-') {
      isneg = !isneg;
      PROVA_FINALE_LOAD_ARDUINO_13__B.k_b++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  success = (PROVA_FINALE_LOAD_ARDUINO_13__B.k_b <= 3);
  if (success && isneg) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1[0] = '-';
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n = 2;
  }

  PROVA_FINALE_LOAD_ARDUINO_13__B.b_k = PROVA_FINALE_LOAD_ARDUINO_13__B.k_b - 1;
  if (success) {
    if (PROVA_FINALE_LOAD_AR_isUnitImag(s, PROVA_FINALE_LOAD_ARDUINO_13__B.k_b))
    {
      isimag1 = true;
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_k = PROVA_FINALE_LOAD_ARDUINO_13__B.k_b;
      while ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) && (c[(uint8_T)
              s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] & 127] ||
              (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == '\x00') ||
              (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == ','))) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++;
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) &&
          (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == '*')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.k_b =
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 2;
        PROVA_FINALE_LOAD__readfloat_dt(PROVA_FINALE_LOAD_ARDUINO_13__B.s1,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n, s,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.k_b, false, &isneg, &b_finite,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n, &unusedU2, &success);
        PROVA_FINALE_LOAD_ARDUINO_13__B.b_k =
          PROVA_FINALE_LOAD_ARDUINO_13__B.k_b - 1;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.s1[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n
          - 1] = '1';
        PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n++;
      }
    } else {
      PROVA_FINALE_LO_readNonFinite_l(s, &PROVA_FINALE_LOAD_ARDUINO_13__B.k_b,
        &b_finite, &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n);
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_k = PROVA_FINALE_LOAD_ARDUINO_13__B.k_b
        - 1;
      if (b_finite) {
        success = PROVA_FINALE_LOAD_copydigits_k3
          (PROVA_FINALE_LOAD_ARDUINO_13__B.s1,
           &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n, s,
           &PROVA_FINALE_LOAD_ARDUINO_13__B.k_b, true);
        PROVA_FINALE_LOAD_ARDUINO_13__B.b_k =
          PROVA_FINALE_LOAD_ARDUINO_13__B.k_b - 1;
        if (success) {
          success = PROVA_FINALE_LOA_copyexponent_k
            (PROVA_FINALE_LOAD_ARDUINO_13__B.s1,
             &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n, s,
             &PROVA_FINALE_LOAD_ARDUINO_13__B.k_b);
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_k =
            PROVA_FINALE_LOAD_ARDUINO_13__B.k_b - 1;
        }
      } else {
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n >= 2) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.s1[0] == '-')) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n = 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.s1[0] = ' ';
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n =
            -PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n;
        }
      }

      while ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) && (c[(uint8_T)
              s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] & 127] ||
              (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == '\x00') ||
              (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == ','))) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++;
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) &&
          (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == '*')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++;
        while ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) && (c[(uint8_T)
                s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] & 127] ||
                (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == '\x00') ||
                (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == ','))) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++;
        }
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) &&
          ((s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == 'i') ||
           (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == 'j'))) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++;
        isimag1 = true;
      }
    }

    while ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3) && (c[(uint8_T)
            s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] & 127] ||
            (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == '\x00') ||
            (s[PROVA_FINALE_LOAD_ARDUINO_13__B.b_k] == ','))) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_k++;
    }
  }

  if (b_finite) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b = 1;
  }

  if (success && (PROVA_FINALE_LOAD_ARDUINO_13__B.b_k + 1 <= 3)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n - 1]
      = ' ';
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n++;
    PROVA_FINALE_LOAD_ARDUINO_13__B.k_b = PROVA_FINALE_LOAD_ARDUINO_13__B.b_k +
      1;
    PROVA_FINALE_LOAD__readfloat_dt(PROVA_FINALE_LOAD_ARDUINO_13__B.s1,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n, s,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.k_b, true, &success, &isneg,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p, &unusedU2, &c_success);
    if (isneg) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b++;
    }

    success = (c_success && (PROVA_FINALE_LOAD_ARDUINO_13__B.k_b > 3) &&
               (isimag1 != success) && unusedU2);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p = 0.0;
  }

  if (success) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.s1[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_n - 1]
      = '\x00';
    switch (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b) {
     case 2:
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b = sscanf
        (&PROVA_FINALE_LOAD_ARDUINO_13__B.s1[0], "%lf %lf",
         &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n,
         &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b != 2) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n = (rtNaN);
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p = (rtNaN);
      }
      break;

     case 1:
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b = sscanf
        (&PROVA_FINALE_LOAD_ARDUINO_13__B.s1[0], "%lf",
         &PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_l);
      if (b_finite) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b == 1) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n =
            PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_l;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n = (rtNaN);
        }
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_b == 1) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p =
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_l;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p;
      x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n;
    } else {
      x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_n;
      x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_p;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_L_readNonFinite_ln(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LOA_copydigits_k3z(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static boolean_T PROVA_FINALE_LO_copyexponent_kd(char_T s1[3], int32_T *idx,
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
    b_success = PROVA_FINALE_LOA_copydigits_k3z(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static void PROVA_FINALE_LOAD_readfloat_dtp(char_T s1[3], int32_T *idx, char_T s,
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
          PROVA_FINALE_LOAD_readfloat_dtp(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      PROVA_FINALE_L_readNonFinite_ln(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = PROVA_FINALE_LOA_copydigits_k3z(s1, idx, s, k, true);
        if (*success) {
          *success = PROVA_FINALE_LO_copyexponent_kd(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static creal_T PROVA_FINALE_LOA_str2double_lvk(char_T s)
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
  PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj = 0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 1;
  PROVA_FINALE_LOAD_ARDUINO_13__B.i_j = (uint8_T)s & 127;
  if (c[PROVA_FINALE_LOAD_ARDUINO_13__B.i_j] || (s == '\x00')) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l = 0.0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[PROVA_FINALE_LOAD_ARDUINO_13__B.i_j])
    {
      PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e = 2;
  }

  if (success) {
    isneg = false;
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      PROVA_FINALE_LOAD_ARDUINO_13__B.d_k++;
      s1[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e - 1] = '1';
      PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e++;
    } else {
      PROVA_FINALE_L_readNonFinite_ln(s, &PROVA_FINALE_LOAD_ARDUINO_13__B.d_k,
        &b_finite, &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l);
      if (b_finite) {
        success = PROVA_FINALE_LOA_copydigits_k3z(s1,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e, s,
          &PROVA_FINALE_LOAD_ARDUINO_13__B.d_k, true);
        if (success) {
          success = PROVA_FINALE_LO_copyexponent_kd(s1,
            &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e, s,
            &PROVA_FINALE_LOAD_ARDUINO_13__B.d_k);
        }
      } else {
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e >= 2) && (s1[0] == '-')) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e = 1;
          s1[0] = ' ';
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l =
            -PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l;
        }
      }

      while ((PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1) &&
             (c[PROVA_FINALE_LOAD_ARDUINO_13__B.i_j] || ((s == '\x00') || (s ==
                ',')))) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1) && (s == '*')) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1) && ((s == 'i') || (s == 'j')))
      {
        PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1) &&
           (c[PROVA_FINALE_LOAD_ARDUINO_13__B.i_j] || ((s == '\x00') || (s ==
              ',')))) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 2;
    }
  }

  if (b_finite) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj = 1;
  }

  if (success && (PROVA_FINALE_LOAD_ARDUINO_13__B.d_k <= 1)) {
    s1[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e - 1] = ' ';
    PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e++;
    PROVA_FINALE_LOAD_ARDUINO_13__B.d_k = 1;
    PROVA_FINALE_LOAD_readfloat_dtp(s1, &PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e,
      s, &PROVA_FINALE_LOAD_ARDUINO_13__B.d_k, true, &success, &isneg,
      &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh, &foundsign, &c_success);
    if (isneg) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj++;
    }

    success = (c_success && (PROVA_FINALE_LOAD_ARDUINO_13__B.d_k > 1) &&
               (isimag1 != success) && foundsign);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh = 0.0;
  }

  if (success) {
    s1[PROVA_FINALE_LOAD_ARDUINO_13__B.idx_e - 1] = '\x00';
    switch (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj) {
     case 2:
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj = sscanf(&s1[0], "%lf %lf",
        &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj != 2) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l = (rtNaN);
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh = (rtNaN);
      }
      break;

     case 1:
      PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj = sscanf(&s1[0], "%lf",
        &PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_d);
      if (b_finite) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj == 1) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l =
            PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_d;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l = (rtNaN);
        }
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.ntoread_bj == 1) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh =
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_scanned1_d;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh;
      x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l;
    } else {
      x.re = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned1_l;
      x.im = PROVA_FINALE_LOAD_ARDUINO_13__B.scanned2_dh;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S568>/MATLAB Function' */
static real_T PROVA_FINALE_LOAD_ARDUI_hex2dec(const char_T s[2])
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

  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g = tmp_0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx],
                      &PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U],
                   &tmp_2.chunks[0U],
                   &PROVA_FINALE_LOAD_ARDUINO_13__B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx],
                      &PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U],
                   &tmp_3.chunks[0U],
                   &PROVA_FINALE_LOAD_ARDUINO_13__B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx],
                        &PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U],
                     &tmp_4.chunks[0U],
                     &PROVA_FINALE_LOAD_ARDUINO_13__B.sk.chunks[0U], 2);
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.sk = tmp_0;
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.sk = tmp_0;
    }

    uMultiWordMul(&PROVA_FINALE_LOAD_ARDUINO_13__B.sk.chunks[0U], 2,
                  &PROVA_FINALE_LOAD_ARDUINO_13__B.p16.chunks[0U], 2,
                  &PROVA_FINALE_LOAD_ARDUINO_13__B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&PROVA_FINALE_LOAD_ARDUINO_13__B.r.chunks[0U], 4,
                         &PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U], 2);
    MultiWordAdd(&PROVA_FINALE_LOAD_ARDUINO_13__B.a_g.chunks[0U],
                 &PROVA_FINALE_LOAD_ARDUINO_13__B.r3.chunks[0U], &tmp.chunks[0U],
                 2);
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g = tmp;
    uMultiWord2MultiWord(&PROVA_FINALE_LOAD_ARDUINO_13__B.p16.chunks[0U], 2,
                         &PROVA_FINALE_LOAD_ARDUINO_13__B.r2.chunks[0U], 3);
    uMultiWordShl(&PROVA_FINALE_LOAD_ARDUINO_13__B.r2.chunks[0U], 3, 4U,
                  &PROVA_FINALE_LOAD_ARDUINO_13__B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&PROVA_FINALE_LOAD_ARDUINO_13__B.r1.chunks[0U], 3,
                         &PROVA_FINALE_LOAD_ARDUINO_13__B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&PROVA_FINALE_LOAD_ARDUINO_13__B.a_g.chunks[0U], 2,
                            0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&PROVA_FINALE_LOAD_ARDUINO_13__B.a_g.chunks[0U], 2,
                              0) - uMultiWord2Double
          (&PROVA_FINALE_LOAD_ARDUINO_13__B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&PROVA_FINALE_LOAD_ARDUINO_13__B.a_g.chunks[0U], 2,
                              0);
      }
    } else {
      x = uMultiWord2Double(&PROVA_FINALE_LOAD_ARDUINO_13__B.a_g.chunks[0U], 2,
                            0);
    }
  } else {
    x = uMultiWord2Double(&PROVA_FINALE_LOAD_ARDUINO_13__B.a_g.chunks[0U], 2, 0);
  }

  return x;
}

/* Function for Chart: '<S39>/Chart' */
static void PROVA_FINALE_LOAD_ARDU_Waypoint(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 5.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_ARD_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_ARDUINO_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 2.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 4.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOA_IN_AutoLanding;
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
static void PROVA_FINALE_LOAD_ARDUINO_13_In(const boolean_T *Ap_sel, real_T
  *Go_home_selector, real_T *Al_selector, real_T *Ato_selector, real_T
  *Vec_selector, real_T *Wp_selector)
{
  if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 1.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_A_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 2.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 5.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_ARD_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 4.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOA_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 3.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOA_IN_AutoTakeoff;
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

/* Model step function for TID0 */
void PROVA_FINALE_LOAD_ARDUINO_13_10_step0(void) /* Sample time: [0.02s, 0.0s] */
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

  /* S-Function (Mti): '<S556>/S-Function Builder' */
  Mti_Outputs_wrapper(&PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder[0],
                      &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S556>/Byte Unpack' */

  /* Unpack: <S556>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&PROVA_FINALE_LOAD_ARDUINO_13__B.ByteUnpack_o1[0],
             (uint8_T*)&PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder[0] +
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
      memcpy((uint8_T*)&PROVA_FINALE_LOAD_ARDUINO_13__B.ByteUnpack_o2[0],
             (uint8_T*)&PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder[0] +
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
      memcpy((uint8_T*)&PROVA_FINALE_LOAD_ARDUINO_13__B.ByteUnpack_o3, (uint8_T*)
             &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder[0] +
             MW_inputPortOffset, MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S556>/Byte Reversal' */

  /* ReverseEndian: <S556>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &PROVA_FINALE_LOAD_ARDUINO_13__B.ByteUnpack_o2[0];
    real32_T *y0 = &PROVA_FINALE_LOAD_ARDUINO_13__B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S554>/One_time_initialization' */
  /* Logic: '<S554>/Logical Operator1' incorporates:
   *  UnitDelay: '<S554>/Unit Delay'
   */
  PRO_One_time_initialization(!PROVA_FINALE_LOAD_ARDUINO_13_DW.UnitDelay_DSTATE,
    &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization,
    &PROVA_FINALE_LOAD_ARDUINO_13_DW.One_time_initialization,
    &PROVA_FINALE_LOAD_ARDUINO_13__P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S554>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S554>/Execution_loop' incorporates:
   *  EnablePort: '<S558>/Enable'
   */
  /* UnitDelay: '<S554>/Unit Delay' */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S558>/I2C Read12' */
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.SampleTime !=
        PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.SampleTime =
        PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S558>/I2C Read1' */
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.SampleTime !=
        PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.SampleTime =
        PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &PROVA_FINALE_LOAD_ARDUINO_13__B.output_raw[0], 3U, false, true);
      memcpy((void *)&PROVA_FINALE_LOAD_ARDUINO_13__B.output[0], (void *)
             &PROVA_FINALE_LOAD_ARDUINO_13__B.output_raw[0], (uint32_T)((size_t)
              3 * sizeof(uint8_T)));
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.output[0] = 0U;
      PROVA_FINALE_LOAD_ARDUINO_13__B.output[1] = 0U;
      PROVA_FINALE_LOAD_ARDUINO_13__B.output[2] = 0U;
    }

    /* ArithShift: '<S558>/Shift Arithmetic4' incorporates:
     *  Constant: '<S558>/Constant1'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_o);
    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
    }

    /* ArithShift: '<S558>/Shift Arithmetic3' incorporates:
     *  Constant: '<S558>/Constant5'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant5_Value_n);
    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o, 4.294967296E+9);
    }

    /* ArithShift: '<S558>/Shift Arithmetic1' incorporates:
     *  Constant: '<S558>/Constant6'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant6_Value);
    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.num_254) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S558>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S558>/Shift Arithmetic1'
     *  ArithShift: '<S558>/Shift Arithmetic3'
     *  ArithShift: '<S558>/Shift Arithmetic4'
     *  Constant: '<S558>/Constant10'
     *  Constant: '<S558>/Constant11'
     *  Constant: '<S558>/Constant7'
     *  MATLABSystem: '<S558>/I2C Read1'
     *  Sum: '<S558>/Sum1'
     *  Sum: '<S558>/Sum4'
     *  Sum: '<S558>/Sum5'
     *  Sum: '<S558>/Sum6'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_i = (int32_T)
      ((((((PROVA_FINALE_LOAD_ARDUINO_13__P.Constant7_Value +
            PROVA_FINALE_LOAD_ARDUINO_13__B.output[0]) <<
           (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? -(int32_T)(uint32_T)
            -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint32_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) +
          ((PROVA_FINALE_LOAD_ARDUINO_13__P.Constant10_Value +
            PROVA_FINALE_LOAD_ARDUINO_13__B.output[1]) <<
           (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
            -PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o : (int32_T)(uint32_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o))) +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Constant11_Value) +
        PROVA_FINALE_LOAD_ARDUINO_13__B.output[2]) >>
       (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 < 0.0 ? -(int32_T)(uint32_T)
        -PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 : (int32_T)(uint32_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.num_254));

    /* ArithShift: '<S558>/Shift Arithmetic7' incorporates:
     *  Constant: '<S558>/Constant2'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_a);
    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
    }

    /* ArithShift: '<S558>/Shift Arithmetic6' incorporates:
     *  Constant: '<S558>/Constant3'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant3_Value_c0);
    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o, 4.294967296E+9);
    }

    /* ArithShift: '<S558>/Shift Arithmetic2' incorporates:
     *  Constant: '<S558>/Constant4'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant4_Value_l);
    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.num_254) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S558>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S558>/Shift Arithmetic2'
     *  ArithShift: '<S558>/Shift Arithmetic6'
     *  ArithShift: '<S558>/Shift Arithmetic7'
     *  Constant: '<S558>/Constant8'
     *  Constant: '<S558>/Constant9'
     *  MATLABSystem: '<S558>/I2C Read12'
     *  Sum: '<S558>/Sum'
     *  Sum: '<S558>/Sum2'
     *  Sum: '<S558>/Sum3'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ay = (int32_T)
      ((((PROVA_FINALE_LOAD_ARDUINO_13__P.Constant8_Value_e + rtb_H_mav[0]) <<
         (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? -(int32_T)(uint32_T)
          -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint32_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) +
        ((PROVA_FINALE_LOAD_ARDUINO_13__P.Constant9_Value + rtb_H_mav[1]) <<
         (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o < 0.0 ? -(int32_T)(uint32_T)
          -PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o : (int32_T)(uint32_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o))) >>
       (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 < 0.0 ? -(int32_T)(uint32_T)
        -PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 : (int32_T)(uint32_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.num_254));

    /* S-Function (calc_T): '<S558>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead1,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead2,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ay,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S558>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead3,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead4,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead5,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead6,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead7,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead8,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead9,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead10,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.I2CRead11,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_i,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2_a,
       &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S554>/Execution_loop' */

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_a,
    &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[0],
    &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2,
    &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE_l);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
  PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
  memset(&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[0], 0, 100U * sizeof
         (uint8_T));
  memset(&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_2[0], 0, 100U * sizeof
         (uint8_T));
  PROVA_FINALE_LOAD_ARDU_find_254
    (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h,
     PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.num_254);
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz &&
      (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 1.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a + 1U);
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a + 1U > 255U) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] !=
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = 0.0;
    }
  }

  Ap_sel = !PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz;
  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 1.0) && Ap_sel) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 1;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 0.0) &&
             PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 2;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 1.0) &&
             PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 3;
  } else {
    if ((PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 2.0) && Ap_sel) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 4;
    }
  }

  switch (PROVA_FINALE_LOAD_ARDUINO_13__B.caso) {
   case 1:
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 - 1];
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 100.0) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0] =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[99];
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = true;
    } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
               (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 + 1.0) - 1] <= 100) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] + 1.0) - 1] + 8U);
      PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
      if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 255;
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol ==
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o >= 0.0) {
            status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
          (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
           (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 + 1.0) - 1] + 7U);
        if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 + (real_T)
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
            find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = status - 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.i = find_comma;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = PROVA_FINALE_LOAD_ARDUINO_13__B.i
          - PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
             PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
            =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i < 100;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            = 0U;
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
        }

        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO >
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2;
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >
              PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = (int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 - 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len;
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
          for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
               PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              =
              PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
              + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
            (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
             (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 + 1.0) - 1] + 8U);
          if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf((real_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
            PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len);
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = (uint8_T)
                PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
            }
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = MAX_uint8_T;
          }

          PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = true;
        }
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
      memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
    }
    break;

   case 2:
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.x[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO] =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
         != 0);
    }

    if (PROVA_FINALE_LOAD_A_ifWhileCond(PROVA_FINALE_LOAD_ARDUINO_13__B.x)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len + 1.0);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
          find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len + (real_T)
         PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
          status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      if (find_comma > status) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.AL = find_comma;
      }

      if (1 > PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = -1;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a - 1;
      }

      for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <=
           PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i
          [(PROVA_FINALE_LOAD_ARDUINO_13__B.AL +
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
      }

      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
      for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.i < 100;
           PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
          =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
        PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
          = 0U;
      }

      PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
      memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
    }
    break;

   case 3:
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len + 1.0);
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
        find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len + (real_T)
       PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a);
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
        status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    if (find_comma > status) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 1;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = find_comma;
    }

    if (1 > PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = -1;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a - 1;
    }

    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <=
         PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i
        [(PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol +
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
    }

    PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
    PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.i < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
        =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
      PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
        = 0U;
    }

    PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
      (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[(int32_T)
       PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 - 1] + 1.0) - 1;
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
        <= 100) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = (int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] + 1.0) - 1] + 8U);
      if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol > 255U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 255;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2 < 0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
      } else {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2 > 255) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 255;
        }
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol ==
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[(int32_T)
           PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 - 1]);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
            status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
          (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
           + 7U);
        if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[(int32_T)
           PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 - 1] + (real_T)
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
            find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = status - 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = find_comma;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
             PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
            =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
        }

        for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i < 100;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_2[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            = 0U;
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = (int32_T)
          (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
           (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] + 1.0) - 1] + 8U);
        if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 255;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2;
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2 < 0) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
        } else {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2 > 255) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 255;
          }
        }

        if (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol >
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2;
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[(int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 - 1] >
              PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i = (int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[(int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 - 1] - 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso = (int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len;
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.caso -=
            PROVA_FINALE_LOAD_ARDUINO_13__B.i;
          for (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
               PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol <
               PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
               PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol++) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              =
              PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.i
              + PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol];
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
            (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
             + 8U);
          if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf((real_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
            PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len);
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = (uint8_T)
                PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
            }
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = MAX_uint8_T;
          }

          PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = true;
        }
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
      memset(&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[0], 0, 100U * sizeof
             (uint8_T));
      memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] + 1.0) - 1] <= 100) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0]);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
          status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
        } else {
          status = 0U;
        }
      } else {
        status = MAX_uint8_T;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] + 1.0) - 1] + 7U);
      if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] + (real_T)
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
          find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (status > find_comma) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.AL = status - 1;
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = find_comma;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
        - PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
      for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
           PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
          =
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.AL
          + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
      memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
    if ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1] + 1.0) - 1] <= 100) &&
        (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[0] > 3.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf((real_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2 -
        PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1]);
      PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1] + 1.0) - 1];
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 7U);
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 7U > 255U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 2.147483648E+9) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= -2.147483648E+9) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = (int32_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = MIN_int32_T;
        }
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = MAX_int32_T;
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol ==
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1]);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
            status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            status = 0U;
          }
        } else {
          status = MAX_uint8_T;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
          (PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 7U);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 7U > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1] + (real_T)
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
            find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (status > find_comma) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.AL = status - 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = find_comma;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
          PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
             PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
            =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.AL
            + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 2;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i < 100;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_2[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            = 0U;
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf
          (PROVA_FINALE_LOAD_ARDUINO_13__B.lat_end[1]);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 2.147483648E+9) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= -2.147483648E+9) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = MIN_int32_T;
          }
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = MAX_int32_T;
        }

        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO >
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = -1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -= 2;
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2;
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = (int8_T)
          ((PROVA_FINALE_LOAD_ARDUINO_13__B.caso -
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 2.147483648E+9) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= -2.147483648E+9) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = MIN_int32_T;
          }
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = MAX_int32_T;
        }

        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO >
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO - 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
             PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
            =
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
          (PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 8U);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 8U > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = rt_roundd_snf((real_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
          PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len);
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 256.0) {
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >= 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = (uint8_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
          }
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = MAX_uint8_T;
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = true;
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
      memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0], 0, 100U * sizeof
             (uint8_T));
      PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[0], 0, 300U * sizeof(uint8_T));
  status = 0U;
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[3 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO] = 0U;
  }

  for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.caso < 2;
         PROVA_FINALE_LOAD_ARDUINO_13__B.caso++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 3 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
      PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
        + 1] =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput_c[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol];
    }
  }

  PROVA_FINALE_LOAD_ARDUINO_13__B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.i >= 1)) {
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.x[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO] =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[(3 *
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
          PROVA_FINALE_LOAD_ARDUINO_13__B.i) - 1] == 0);
    }

    Ap_sel = true;
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
    exitg2 = false;
    while ((!exitg2) && (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100)) {
      if (!PROVA_FINALE_LOAD_ARDUINO_13__B.x[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO])
      {
        Ap_sel = false;
        exitg2 = true;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++;
      }
    }

    if (Ap_sel) {
      status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.i;
      exitg1 = true;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.i--;
    }
  }

  if (PROVA_FINALE_LOAD_ARDUINO_13__B.AL == 1) {
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[(status + 3 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] =
        PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
    }
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.AL == 2) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.qY = status - /*MW:OvSatOk*/ 1U;
    if (status - 1U > status) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 0U;
    }

    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[(status + 3 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] =
        PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_i[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
      PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[((int32_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 3 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] =
        PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_2[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
    }
  } else {
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[(status + 3 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] = 0U;
    }
  }

  for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.mess_out[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
      = PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput_c[3 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Add =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput_c[5] +
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_gw;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.mess_out[2] !=
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory5_PreviousInput_l[2]) {
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.x[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO] =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.mess_out[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
         != 0);
    }

    Ap_sel = true;
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
    exitg1 = false;
    while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 100)) {
      if (!PROVA_FINALE_LOAD_ARDUINO_13__B.x[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO])
      {
        Ap_sel = false;
        exitg1 = true;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++;
      }
    }

    if (!Ap_sel) {
      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.counter > 100) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter = 0U;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter + 1U;
      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.counter + 1U > 65535U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
      }

      PROVA_FINALE_LOAD_ARDUINO_13_DW.counter = (uint16_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY;
    }
  }

  PROVA_FINALE_LOAD_ARDUINO_13__B.new_mex =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory1[0] =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0];
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory1[1] =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1];

  /* Memory: '<Root>/Memory' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_k[0] =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[0];
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_k[1] =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[1];
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_k[2] =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[2];
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_k[3] =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[3];

  /* Memory: '<S1>/Memory3' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory3 =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o;
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       8; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    /* Memory: '<S1>/Memory' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Memory[PROVA_FINALE_LOAD_ARDUINO_13__B.i] =
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_ic[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.mess_out[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Add,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.new_mex,
     &PROVA_FINALE_LOAD_ARDUINO_13__P.SIUAVuint8_Value,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Memory[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Memory1[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_k[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Memory3,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o1[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o2,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4_n[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o5[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o8,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o10[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o12,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o13,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o14,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o15,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o16,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       6; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info_in[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
      =
      PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
  }

  if ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_not_empty) ||
      ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[0] == 3) &&
       (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[1] == 250))) {
    memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_not_empty = true;
    memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_AL_not_empty) ||
      ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[0] == 3) &&
       (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[1] == 250))) {
    memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_AL[0], 0, 42U * sizeof
           (real32_T));
    PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_AL_not_empty = true;
  }

  PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[0];
  PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o7[1];
  PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[2] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[0];
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] == 1) {
    if ((PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] > 0) &&
        (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o8) > 0.0F) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info
          [1] - 1] = 1.0F;
      } else {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o8 == 0.0F) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info
            [1] - 1] = 0.0F;
        }
      }
    } else {
      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] > 7) &&
          (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] < 12)) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info
          [1] - 1] = PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o8;
      }
    }
  }

  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o12 == 13) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o12
      - 1] = PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o13;
  }

  memcpy(&PROVA_FINALE_LOAD_ARDUINO_13__B.Val_out_MAV[0],
         &PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] == 3) &&
      (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] == 200)) {
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[0] > 6) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info_in[0] = 6U;
    }

    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 6;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
        = PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info_in[0];
    }
  }

  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] == 3) &&
      (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] < 200)) {
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o10[1] == 0.0F) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[1] + 1U;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[1] + 1U > 65535U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
      }

      for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 7;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP[((int32_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 6 *
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o10[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[1] + 1U;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[1] + 1U > 65535U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
      }

      for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 6;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[((int32_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 6 *
          (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + 1)) - 1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info_in[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
          + 1];
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o10[0] + 1.0F);
      for (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol < 7;
           PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol++) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_AL
          [(PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + 6 *
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol) - 1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o10[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol];
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
        PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[1] + 1U;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o9[1] + 1U > 65535U) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
      }

      for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 6;
           PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[((int32_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.qY + 6 *
          (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + 1)) - 1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info_in[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
          + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6 == 0) &&
      (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j == 0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 0U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6 == 0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j == 3)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.test1 = 0.0;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6 == 0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j == 2)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.test1 = 0.0;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6 == 0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j == 1)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.test1 = 1.0;
  } else {
    switch (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6) {
     case 192:
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 192U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 192U;
      break;

     case 208:
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 208U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 208U;
      break;

     default:
      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o6 == 220) &&
          (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j != 5)) {
        if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] == 0) &&
            ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[2] == 1) ||
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[3] == 1) ||
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] == 1) ||
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[5] == 1) ||
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6] == 1) ||
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[7] == 1)))
        {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 220U;
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 220U;
        } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] ==
                    0) &&
                   (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] ==
                    1) &&
                   ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[2] ==
                     1) ||
                    (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[3] ==
                     1) ||
                    (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] ==
                     1) ||
                    (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[5] ==
                     1) ||
                    (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6] ==
                     1) ||
                    (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[7] ==
                     1))) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 220U;
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 220U;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 208U;
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o = 208U;
        }
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3_j == 5) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 220U;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] = 192U;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 100U *
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[5];
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.qY > 65535U) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
  }

  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[4] == 0) {
    if ((uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.qY == 0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.z = 0U;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.z = MAX_uint16_T;
    }
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.z = (uint16_T)
      (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[4] == 0U ? MAX_uint32_T :
       (uint32_T)(uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.qY /
       PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.qY -
                   (uint16_T)((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.z *
      PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[4] >> 1) +
                    (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[4] & 1))) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.z++;
    }
  }

  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] = (uint8_T)
    AP_mode_idx_0;
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] = (uint8_T)
    AP_mode_idx_1;
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       7; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.f = rt_roundf_snf
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[PROVA_FINALE_LOAD_ARDUINO_13__B.i]);
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.f < 256.0F) {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.f >= 0.0F) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[PROVA_FINALE_LOAD_ARDUINO_13__B.i
          + 2] = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.f;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[PROVA_FINALE_LOAD_ARDUINO_13__B.i
          + 2] = 0U;
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[PROVA_FINALE_LOAD_ARDUINO_13__B.i
        + 2] = MAX_uint8_T;
    }
  }

  /* Outputs for Enabled SubSystem: '<S562>/Subsystem1' incorporates:
   *  EnablePort: '<S564>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o14 > 0) {
    /* Inport: '<S564>/T' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.T =
      PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S562>/Subsystem1' */

  /* Switch: '<S562>/Switch1' incorporates:
   *  Constant: '<S562>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  RelationalOperator: '<S562>/NotEqual'
   *  Switch: '<S562>/Switch'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_hx !=
      PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[12]) {
    /* Switch: '<S562>/Switch1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch1 =
      PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[12];
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.T >
             PROVA_FINALE_LOAD_ARDUINO_13__P.Switch_Threshold_p) {
    /* Switch: '<S562>/Switch' incorporates:
     *  Switch: '<S562>/Switch1'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch1 = PROVA_FINALE_LOAD_ARDUINO_13__B.T;
  } else {
    /* Switch: '<S562>/Switch1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch1 =
      PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[12];
  }

  /* End of Switch: '<S562>/Switch1' */

  /* RateTransition: '<S27>/Rate Transition' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.RateTransition_Buffer0;

  /* Sum: '<S27>/Add1' incorporates:
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Memory: '<S27>/Memory1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_jg +
     PROVA_FINALE_LOAD_ARDUINO_13__P.Constant3_Value_o) +
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput;

  /* Switch: '<S27>/Switch' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o >
      PROVA_FINALE_LOAD_ARDUINO_13__P.Switch_Threshold_f) {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_jg;
  } else {
    /* Switch: '<S27>/Switch' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o;
  }

  /* End of Switch: '<S27>/Switch' */

  /* MATLAB Function: '<S19>/iflogic_function' */
  if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 1.0) ||
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 3.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 26U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 2.0) ||
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 4.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 30U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 2.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 33U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 6.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 34U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 0.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 0U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             ((PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 1.0) ||
              (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 5.0) ||
              (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 9.0))) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 1U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             ((PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 3.0) ||
              (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 8.0))) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 74U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 7.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 36U;
  } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput == 0.0) &&
             (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 == 4.0)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = 29U;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S19>/iflogic_function' */

  /* Sum: '<S27>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Memory: '<S27>/Memory'
   */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput +=
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_m +
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_n;

  /* Gain: '<S19>/Gain' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_c *
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion3 =
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (uint32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 6;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
      = PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[6 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
  }

  for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 7;
       PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
      = PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP[6 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
  }

  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] == 2) &&
      (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] < 6)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
      PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] + 1U;
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] + 1U > 65535U) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
    }

    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 6;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
        = PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[(6 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + (int32_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY) - 1];
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
      PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] + 1U;
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] + 1U > 65535U) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
    }

    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 7;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
        = PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP[(6 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + (int32_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY) - 1];
    }
  }

  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] == 3) &&
      (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] < 200)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.qY =
      PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] + 1U;
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[1] + 1U > 65535U) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
    }

    for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 6;
         PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
        = PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[(6 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO + (int32_T)
        PROVA_FINALE_LOAD_ARDUINO_13__B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function' */

  /* Gain: '<S21>/Gain' incorporates:
   *  Constant: '<S7>/Constant'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_by *
     PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_jp[0]);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* MATLABSystem: '<S555>/Serial Receive1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.Protocol !=
      PROVA_FINALE_LOAD_ARDUINO_13__P.SerialReceive1_Protocol) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.Protocol =
      PROVA_FINALE_LOAD_ARDUINO_13__P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.DataSizeInBytes,
                 &PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S555>/Subsystem2' incorporates:
   *  EnablePort: '<S566>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S566>/Create_message' */
    status = 0U;
    if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.start_found) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.i - 1 < 32)) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[(uint8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.i - 1] == 36) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 32 - (uint8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.i;
          for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <=
               PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              = PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[((uint8_T)
              PROVA_FINALE_LOAD_ARDUINO_13__B.i +
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) - 1];
          }

          PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k = (uint8_T)(33 - (uint8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.i);
          PROVA_FINALE_LOAD_ARDUINO_13_DW.start_found = true;
          exitg1 = true;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.i++;
        }
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 1;
      exitg1 = false;
      while ((!exitg1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.caso - 1 < 32)) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[(uint8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso - 1] == 13) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.end_found = true;
          status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          exitg1 = true;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
        }
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.end_found) {
        if (1 > status) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = -1;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = status - 1;
        }

        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <=
             PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = (int32_T)(((uint32_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
            PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k) + 1U);
          if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol > 255U) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 255;
          }

          PROVA_FINALE_LOAD_ARDUINO_13_DW.message[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            - 1] =
            PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
        }

        memcpy(&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_k[0],
               &PROVA_FINALE_LOAD_ARDUINO_13_DW.message[0], 80U * sizeof(uint8_T));
        PROVA_FINALE_LOAD_ARDUINO_13_DW.end_found = false;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k = (uint8_T)(32 - status);
        if (status == 32) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.start_found = false;
          memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message[0], 0, 80U * sizeof
                 (uint8_T));
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.start_found = true;
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso = -status;
          for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <=
               PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 31;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.message[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              = PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[status +
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = status + 48;
          if (0 <= PROVA_FINALE_LOAD_ARDUINO_13__B.ATO - 1) {
            memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message[-status + 32], 0,
                   ((PROVA_FINALE_LOAD_ARDUINO_13__B.ATO - status) + status) *
                   sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S566>/Subsystem' incorporates:
         *  EnablePort: '<S568>/Enable'
         */
        /* MATLAB Function: '<S568>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i < 80;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
          messaggio = (int8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_k[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
          if (messaggio == '$') {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
            }

            status = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
          }

          if (messaggio == ',') {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
            }

            find_comma = (uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
            = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              =
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
               == '$');
          }

          PROVA_FINALE_LOAD_ARDU_eml_find
            (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
             &PROVA_FINALE_LOAD_ARDUINO_13__B.eb_data,
             PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size);
          PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
            PROVA_FINALE_LOAD_ARDUINO_13__B.eb_data;
          for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 5;
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
            messaggio =
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
              + PROVA_FINALE_LOAD_ARDUINO_13__B.AL];
            PROVA_FINALE_LOAD_ARDUINO_13__B.mess_type_l[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              = (messaggio == bb[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]);
            PROVA_FINALE_LOAD_ARDUINO_13__B.mess_type[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              = messaggio;
          }

          if (PROVA_FINALE_LOAD_ifWhileCond_o
              (PROVA_FINALE_LOAD_ARDUINO_13__B.mess_type_l)) {
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                 == ',');
            }

            PROVA_FINALE_LOAD_AR_eml_find_o
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
               PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size);
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                 == '*');
            }

            PROVA_FINALE_LOAD_AR_eml_find_o
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
               PROVA_FINALE_LOAD_ARDUINO_13__B.star_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.star_size);
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                 == '$');
            }

            PROVA_FINALE_LOAD_AR_eml_find_o
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
               PROVA_FINALE_LOAD_ARDUINO_13__B.fb_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.star_size);
            PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
              PROVA_FINALE_LOAD_AR_str2double
              (&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data
               [2]]);
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[2] + 3.0 >
                (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[3] - 1.0)
            {
              PROVA_FINALE_LOAD_ARDUINO_13__B.c = 0;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.c =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[2] + 2;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[3] - 1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size[0] = 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
              PROVA_FINALE_LOAD_ARDUINO_13__B.c;
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size[1] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                 PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.c
                + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.b_x =
              PROVA_FINALE_LOAD__str2double_l
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size);
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.im == 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
            } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re == 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re = 0.0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re +
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
              PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size[0] *
              PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size[1] - 1;
            if (0 <= PROVA_FINALE_LOAD_ARDUINO_13__B.caso) {
              memcpy(&PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data[0],
                     &PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[0],
                     (PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1) * sizeof(int32_T));
            }

            if (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data
                [3]] == 'S') {
              PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
                -PROVA_FINALE_LOAD_ARDUINO_13__B.num_254;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
              PROVA_FINALE_LOAD_str2double_lv
              (&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data
               [4]]);
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[4] + 4.0 >
                (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[5] - 1.0)
            {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
              PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[4] + 3;
              PROVA_FINALE_LOAD_ARDUINO_13__B.i =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[5] - 1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_b[0] = 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
              PROVA_FINALE_LOAD_ARDUINO_13__B.i -
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_b[1] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                 PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.b_x =
              PROVA_FINALE_LOAD__str2double_l
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_b);
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.im == 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
            } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re == 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re = 0.0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re +=
              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data
                [5]] == 'W') {
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                -PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;
            }

            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[6] + 1.0 >
                (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[7] - 1.0)
            {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[6];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[7] - 1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_p[0] = 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_p[1] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                 PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
              PROVA_FINALE_LOAD__str2double_l
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_p);

            /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[7] + 1.0 >
                (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[8] - 1.0)
            {
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[7];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[8] - 1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_c[0] = 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_c[1] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                 PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
              PROVA_FINALE_LOAD__str2double_l
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_c);

            /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[4] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[9] + 1.0 >
                (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[10] - 1.0)
            {
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[9];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[10] - 1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_f[0] = 1;
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
            PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_f[1] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                 PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
              PROVA_FINALE_LOAD__str2double_l
              (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
               PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_f);

            /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[3] =
              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data
                [10]] == 'W') {
              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[3] =
                -PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[5] =
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[5];
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[6] =
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[6];
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[7] =
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[7];
            PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[8] =
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[8];
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 1.0 <
                256.0) {
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 1.0 >=
                  0.0) {
                status = (uint8_T)((real_T)
                                   PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0]
                                   + 1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[status - 1];
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 2.0 <
                256.0) {
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 2.0 >=
                  0.0) {
                status = (uint8_T)((real_T)
                                   PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0]
                                   + 2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[status - 1];
            if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.fb_data[0] + 1.0 >
                (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] - 1.0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                PROVA_FINALE_LOAD_ARDUINO_13__B.fb_data[0];
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] - 1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.AL -=
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                 PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.NMEA_gga_string_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                = (uint8_T)
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
            }

            status = 0U;
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol <=
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL - 1) {
              status ^=
                PROVA_FINALE_LOAD_ARDUINO_13__B.NMEA_gga_string_data[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol];
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol++;
            }

            if (status != PROVA_FINALE_LOAD_ARDUI_hex2dec(ck_ric)) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[0];
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[2];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[3] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[3];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[4] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[4];
            }
          } else {
            for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 5;
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.mess_type_l[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                (PROVA_FINALE_LOAD_ARDUINO_13__B.mess_type[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                 == cb[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]);
            }

            if (PROVA_FINALE_LOAD_ifWhileCond_o
                (PROVA_FINALE_LOAD_ARDUINO_13__B.mess_type_l)) {
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                   == ',');
              }

              PROVA_FINALE_LOAD_AR_eml_find_o
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size);
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                   == '*');
              }

              PROVA_FINALE_LOAD_AR_eml_find_o
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.star_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.star_size);
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 80;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                   == '$');
              }

              PROVA_FINALE_LOAD_AR_eml_find_o
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_c,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.fb_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.star_size);
              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
                PROVA_FINALE_LOAD_AR_str2double
                (&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data
                 [1]]);
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[1] +
                  3.0 > (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[2]
                  - 1.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[1] + 2;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[2] - 1;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size[0] = 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size[1] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                  + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.b_x =
                PROVA_FINALE_LOAD__str2double_l
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size);
              if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.im == 0.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
              } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re == 0.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re = 0.0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
                PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re +
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size[0] *
                PROVA_FINALE_LOAD_ARDUINO_13__B.eb_size[1] - 1;
              if (0 <= PROVA_FINALE_LOAD_ARDUINO_13__B.caso) {
                memcpy(&PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data[0],
                       &PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[0],
                       (PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1) * sizeof
                       (int32_T));
              }

              if (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data
                  [2]] == 'S') {
                PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
                  -PROVA_FINALE_LOAD_ARDUINO_13__B.num_254;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
                PROVA_FINALE_LOAD_str2double_lv
                (&PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data
                 [3]]);
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[3] +
                  4.0 > (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[4]
                  - 1.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[3] + 3;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[4] - 1;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_b[0] = 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_b[1] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                  + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.b_x =
                PROVA_FINALE_LOAD__str2double_l
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_b);
              if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.im == 0.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
              } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re == 0.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re = 0.0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.b_x.re / 60.0;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re +=
                PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
              if (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.tmp_data
                  [4]] == 'W') {
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                  -PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
                PROVA_FINALE_LOA_str2double_lvk
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[5] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[6] +
                  1.0 > (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[7]
                  - 1.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[6];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[7] - 1;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_p[0] = 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_p[1] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                  + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
                PROVA_FINALE_LOAD__str2double_l
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_p);

              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[6] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[8] +
                  1.0 > (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[9]
                  - 1.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[8];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[9] - 1;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_c[0] = 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_c[1] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                  + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
                PROVA_FINALE_LOAD__str2double_l
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_c);

              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[7] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[10] +
                  1.0 > (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data
                  [11] - 1.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.i =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[10];
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.comma_gga_data[11] - 1;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_f[0] = 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso -
                PROVA_FINALE_LOAD_ARDUINO_13__B.i;
              PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_f[1] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.i
                  + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1 =
                PROVA_FINALE_LOAD__str2double_l
                (PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_data,
                 PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio_size_f);

              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[8] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.Lat_1.re;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[2];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[3] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[3];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[4] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[4];
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 1.0 <
                  256.0) {
                if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 1.0 >=
                    0.0) {
                  status = (uint8_T)((real_T)
                                     PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0]
                                     + 1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[status - 1];
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 2.0 <
                  256.0) {
                if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] + 2.0 >=
                    0.0) {
                  status = (uint8_T)((real_T)
                                     PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0]
                                     + 2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[status - 1];
              if ((real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.fb_data[0] + 1.0 >
                  (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] - 1.0) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
              } else {
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.fb_data[0];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
                  PROVA_FINALE_LOAD_ARDUINO_13__B.star_data[0] - 1;
              }

              PROVA_FINALE_LOAD_ARDUINO_13__B.AL =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO -
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
              for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <
                   PROVA_FINALE_LOAD_ARDUINO_13__B.AL;
                   PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.NMEA_gga_string_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                  = (uint8_T)
                  PROVA_FINALE_LOAD_ARDUINO_13__B.messaggio[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                  + PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              }

              status = 0U;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
              while (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO <=
                     PROVA_FINALE_LOAD_ARDUINO_13__B.AL - 1) {
                status ^=
                  PROVA_FINALE_LOAD_ARDUINO_13__B.NMEA_gga_string_data[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++;
              }

              if (status != PROVA_FINALE_LOAD_ARDUI_hex2dec(ck_ric)) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[0];
                PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[1];

                /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
                PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[5] =
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[5];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[6] =
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[6];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[7] =
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[7];
                PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[8] =
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[8];
              }
            } else {
              PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[0];
              PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[1];

              /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[2];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[3] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[3];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[4] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[4];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[5] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[5];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[6] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[6];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[7] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[7];
              PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[8] =
                PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[8];
            }
          }
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[0];
          PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[1];

          /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[2];
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[3] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[3];
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[4] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[4];
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[5] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[5];
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[6] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[6];
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[7] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[7];
          PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[8] =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[8];
        }

        /* End of MATLAB Function: '<S568>/MATLAB Function' */

        /* ComplexToRealImag: '<S568>/Complex to Real-Imag' */
        PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.num_254;
        PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;

        /* Update for Memory: '<S568>/Memory' */
        memcpy(&PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[0],
               &PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0], 9U *
               sizeof(real_T));

        /* End of Outputs for SubSystem: '<S566>/Subsystem' */
      } else {
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i < 32;
             PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)(((uint32_T)
            PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k +
            PROVA_FINALE_LOAD_ARDUINO_13__B.i) + 1U);
          if ((uint32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.ATO > 255U) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
          }

          PROVA_FINALE_LOAD_ARDUINO_13_DW.message[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
            - 1] =
            PROVA_FINALE_LOAD_ARDUINO_13__B.b_dataOut[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = (int32_T)
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k + 32U);
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k + 32U > 255U) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k = (uint8_T)
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
      }
    }

    /* End of MATLAB Function: '<S566>/Create_message' */
  }

  /* End of MATLABSystem: '<S555>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S555>/Subsystem2' */

  /* Outputs for Resettable SubSystem: '<S409>/Resettable Subsystem' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut = PROVA_F_ResettableSubsystem
    (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4_n[0],
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.ResettableSubsystem_o,
     &PROVA_FINALE_LOAD_ARDUINO_13__P.ResettableSubsystem_o,
     &PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem_o);

  /* End of Outputs for SubSystem: '<S409>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S409>/Enabled Subsystem' */
  PROVA_FINA_EnabledSubsystem(PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4_n[0],
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut,
    &PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_l,
    &PROVA_FINALE_LOAD_ARDUINO_13__P.EnabledSubsystem_j);

  /* End of Outputs for SubSystem: '<S409>/Enabled Subsystem' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       9; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
      =
      PROVA_FINALE_LOAD_ARDUINO_13__B.ByteReversal[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* Gain: '<S550>/Gain1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_e *
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[6];

  /* MATLAB Function: '<S415>/MATLAB Function1' */
  guard1 = false;
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] == 1) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_l != 0.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_i;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o =
        PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2];
    }

    /* End of Switch: '<S38>/Switch' */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o >
        PROVA_FINALE_LOAD_ARDUINO_13__P.safe_V) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.alarm = 1.0;
    } else if (fabs(PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_mz *
                    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m) >
               PROVA_FINALE_LOAD_ARDUINO_13__P.safe_phi) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 1) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.alarm = 0.0;
    }
  }

  /* Outputs for Resettable SubSystem: '<S432>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S435>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (PROVA_FINALE_LOAD_ARDUINO_13_DW.alarm)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S436>/Sum' incorporates:
     *  Memory: '<S436>/Memory'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition;
  }

  /* Sum: '<S436>/Sum' incorporates:
   *  Constant: '<S436>/Constant4'
   *  Memory: '<S436>/Memory'
   */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h +=
    PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;

  /* End of Outputs for SubSystem: '<S432>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S432>/Enabled ' incorporates:
   *  EnablePort: '<S434>/Enable'
   */
  /* MATLAB Function: '<S415>/MATLAB Function1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.alarm > 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Enabled_MODE = true;

    /* Switch: '<S434>/Switch' */
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h >
        PROVA_FINALE_LOAD_ARDUINO_13__P.time_alarm_SAFE) {
      /* Switch: '<S434>/Switch' incorporates:
       *  Constant: '<S434>/Constant'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value;
    } else {
      /* Switch: '<S434>/Switch' incorporates:
       *  Constant: '<S434>/Constant1'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value;
    }

    /* End of Switch: '<S434>/Switch' */
  } else {
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Enabled_MODE) {
      /* Disable for Switch: '<S434>/Switch' incorporates:
       *  Outport: '<S434>/Alarm Safe'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch =
        PROVA_FINALE_LOAD_ARDUINO_13__P.AlarmSafe_Y0;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S432>/Enabled ' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/load uint16'
   *  Gain: '<S21>/Gain'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[0] =
    PROVA_FINALE_LOAD_ARDUINO_13__P.loaduint16_Value;
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 10U * PROVA_FINALE_LOAD_ARDUINO_13__B.z;
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.qY > 65535U) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S21>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.qY;
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[3] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[6];
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[4] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[2];
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[5] =
    PROVA_FINALE_LOAD_ARDUINO_13__P._Value;

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S21>/Data Type Conversion4' incorporates:
   *  Constant: '<S38>/Constant2'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_k);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion4'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S21>/Gain2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Gain2_Gain *
     PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_jp[2]);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Gain: '<S21>/Gain2'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1 = (int16_T)
    (((PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
       (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
       (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) *
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_eu) >> 18);

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Constant: '<S7>/Constant'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_jp[1]);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 256.0);
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion3' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.B_Remaining = (int8_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int8_T)-(int8_T)
     (uint8_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int8_T)(uint8_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/Constant'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_e);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion =
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (uint32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* MATLAB Function: '<S17>/Alarm set' incorporates:
   *  Constant: '<S38>/Constant2'
   *  SignalConversion generated from: '<S26>/ SFunction '
   */
  rtb_H_mav[0] = PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0];
  rtb_H_mav[1] = PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1];
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_k == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S17>/Alarm set' */

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S17>/Type fixed_wing Autopilot generic'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[0] =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Typefixed_wingAutopilotgeneric_[0];
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[2] =
    rtb_H_mav[0];
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[1] =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Typefixed_wingAutopilotgeneric_[1];
  PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[3] =
    rtb_H_mav[1];
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       6; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    /* Gain: '<S18>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_dn *
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[PROVA_FINALE_LOAD_ARDUINO_13__B.i];

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
    }

    if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ld[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
      = (int16_T)(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)
                  -(int16_T)(uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 :
                  (int32_T)(int16_T)(uint16_T)
                  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_dn *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_hxg;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ld[6] = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_dn *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_f;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ld[7] = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_dn *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_e;

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ld[8] = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S551>/Gain1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_b =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_h *
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[7];

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Gain: '<S552>/Gain1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[0] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m;
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[1] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_b;
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[2] = (real32_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_n *
     PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[8]);
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[3] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[3];
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[4] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[4];
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[5] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[5];

  /* MATLAB Function: '<S554>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion'
   *  DataTypeConversion: '<S554>/Data Type Conversion2'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o14 == 1) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.P_ref =
      PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1;
  }

  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o16 == 1) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.P_ref =
      PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o17;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.rl_up = 20.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.rl_dw = -20.0;
  }

  /* Product: '<S557>/delta rise limit' incorporates:
   *  MATLAB Function: '<S554>/MATLAB Function'
   *  SampleTimeMath: '<S557>/sample time'
   *
   * About '<S557>/sample time':
   *  y = K where K = ( w * Ts )
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = PROVA_FINALE_LOAD_ARDUINO_13_DW.rl_up
    * PROVA_FINALE_LOAD_ARDUINO_13__P.sampletime_WtEt;

  /* Sum: '<S557>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S554>/MATLAB Function'
   *  UnitDelay: '<S557>/Delay Input2'
   *
   * Block description for '<S557>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S557>/Delay Input2':
   *
   *  Store in Global RAM
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.P_ref -
    PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE;

  /* Switch: '<S563>/Switch2' incorporates:
   *  RelationalOperator: '<S563>/LowerRelop1'
   */
  if (!(PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 >
        PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o)) {
    /* Product: '<S557>/delta fall limit' incorporates:
     *  MATLAB Function: '<S554>/MATLAB Function'
     *  SampleTimeMath: '<S557>/sample time'
     *
     * About '<S557>/sample time':
     *  y = K where K = ( w * Ts )
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
      PROVA_FINALE_LOAD_ARDUINO_13_DW.rl_dw *
      PROVA_FINALE_LOAD_ARDUINO_13__P.sampletime_WtEt;

    /* Switch: '<S563>/Switch' incorporates:
     *  RelationalOperator: '<S563>/UpperRelop'
     */
    if (!(PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 <
          PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
        PROVA_FINALE_LOAD_ARDUINO_13__B.num_254;
    }

    /* End of Switch: '<S563>/Switch' */
  }

  /* End of Switch: '<S563>/Switch2' */

  /* Sum: '<S557>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S557>/Delay Input2'
   *
   * Block description for '<S557>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S557>/Delay Input2':
   *
   *  Store in Global RAM
   */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE +=
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o;

  /* MATLAB Function: '<S554>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion'
   *  UnitDelay: '<S557>/Delay Input2'
   *
   * Block description for '<S557>/Delay Input2':
   *
   *  Store in Global RAM
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = log
    (PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE / (real_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1);
  PROVA_FINALE_LOAD_ARDUINO_13__B.h_ = (real32_T)(29.260958205912335 *
    PROVA_FINALE_LOAD_ARDUINO_13__B.num_254) *
    (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch1 + 273.15F) / (real32_T)(1.0 -
    -0.095098114169215084 * PROVA_FINALE_LOAD_ARDUINO_13__B.num_254);

  /* DataTypeConversion: '<S554>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion'
   *  MATLAB Function: '<S554>/MATLAB Function1'
   *  UnitDelay: '<S557>/Delay Input2'
   *
   * Block description for '<S557>/Delay Input2':
   *
   *  Store in Global RAM
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = (real32_T)(log
    (PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE / (real_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1) * 29.260958205912335) *
    (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch1 + 273.15F) / (real32_T)(1.0 - log
    (PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE / (real_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1) * -0.095098114169215084);

  /* Gain: '<S16>/Gain' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_bx[0] *
    PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_a[0] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? -(int32_T)(uint32_T)
    -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* Gain: '<S16>/Gain' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_bx[1] *
    PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_a[1] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? -(int32_T)(uint32_T)
    -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* Gain: '<S16>/Gain' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_bx[2] *
    PROVA_FINALE_LOAD_ARDUINO_13__B.num_254;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_a[2] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? -(int32_T)(uint32_T)
    -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/alt_r'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_bx[3] *
    PROVA_FINALE_LOAD_ARDUINO_13__P.alt_r_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_a[3] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? -(int32_T)(uint32_T)
    -PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* Gain: '<S16>/Gain1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_ej *
    PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2];

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_p[0] = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S16>/Gain1' incorporates:
   *  Constant: '<S16>/vel y'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_ej *
    PROVA_FINALE_LOAD_ARDUINO_13__P.vely_Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_p[1] = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S16>/Gain1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_ej * 0.0;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_p[2] = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S553>/Gain1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_n1 *
    PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[4];

  /* Gain: '<S16>/Gain2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain2_Gain_k *
    PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_h = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Constant: '<S22>/airspeed groundspeed alt climb1'
   *  DataTypeConversion: '<S554>/Data Type Conversion1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.AGAC[0] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2];
  PROVA_FINALE_LOAD_ARDUINO_13__B.AGAC[1] = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13__P.airspeedgroundspeedaltclimb1_Va;
  PROVA_FINALE_LOAD_ARDUINO_13__B.AGAC[2] = PROVA_FINALE_LOAD_ARDUINO_13__B.h_;
  PROVA_FINALE_LOAD_ARDUINO_13__B.AGAC[3] = (real32_T)0.0;

  /* Gain: '<S33>/Gain' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_l *
    PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re;

  /* Switch: '<S34>/Switch2' incorporates:
   *  Abs: '<S34>/Abs'
   *  Constant: '<S34>/Constant2'
   *  Sum: '<S34>/Sum'
   */
  if (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o >
        PROVA_FINALE_LOAD_ARDUINO_13__P.Switch2_Threshold_a)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value - fabs
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
  }

  /* End of Switch: '<S34>/Switch2' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading_g = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Gain: '<S22>/USCITA PERCENTUALE' incorporates:
   *  Constant: '<S6>/Constant'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.USCITAPERCENTUALE_Gain *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_c;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Throttle = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* S-Function (PWMinterrupt_throttle_v4_4): '<S9>/S-Function Builder6' */
  PWMinterrupt_throttle_v4_4_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_throttle);

  /* Product: '<S575>/Divide2' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   *  Product: '<S578>/Multiply'
   *  Sum: '<S575>/Sum3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re =
    PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[0] -
    PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[1];

  /* Sum: '<S575>/Sum5' incorporates:
   *  Constant: '<S575>/manetta_massima'
   *  Constant: '<S575>/manetta_minima'
   *  DataTypeConversion: '<S9>/Data Type Conversion12'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   *  Product: '<S575>/Divide2'
   *  Product: '<S575>/Multiply1'
   *  Sum: '<S575>/Sum2'
   *  Sum: '<S575>/Sum4'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum5 = (real_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_throttle -
     PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[1]) /
    PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re *
    (PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Tmax -
     PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Tmin) +
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Tmin;

  /* Gain: '<S29>/Gain2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain2_Gain_j *
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum5;

  /* S-Function (PWMinterrupt_goHome): '<S9>/S-Function Builder2' */
  PWMinterrupt_goHome_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder2);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder2 >
      PROVA_FINALE_LOAD_ARDUINO_13__P.Switch_Threshold_m) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_b;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_js;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<S38>/ STATI' incorporates:
   *  Constant: '<S38>/Constant2'
   *  DataTypeConversion: '<S554>/Data Type Conversion1'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c26_PROVA_FINALE_LOAD == 0U) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c26_PROVA_FINALE_LOAD = 1U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_AR_IN_MANUALE;
  } else {
    switch (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN) {
     case PROVA_FINALE_LOAD_IN_AUTOMATICA:
      if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_k == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA = 0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINA_IN_Intervento_Pilota;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA = 0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARDUI_IN_Safe;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA = 0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_AR_IN_Go_Home;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] == 0)
      {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA = 0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_A_IN_Stand_By;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 1)
      {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA = 0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_AR_IN_MANUALE;
      } else {
        switch (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA) {
         case PROVA_IN_ATTERRAGGIO_AUTOMATICO:
          if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[8] == 0) &&
              (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ > 20.0F) &&
              (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6] == 1))
          {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_A_IN_WAYPOINT;
          } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[8]
                      == 0) && (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ > 20.0F)) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_IN_VETTORIALE;
          } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[7]
                      == 1) &&
                     (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[8]
                      == 0) && (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ < 1.0F) &&
                     (PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] < 1.0))
          {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FIN_IN_DECOLLO_AUTOMATICO;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.modo = 4.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 1.0;
          }
          break;

         case PROVA_FIN_IN_DECOLLO_AUTOMATICO:
          if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[7] == 0) &&
              (PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] >= 1.0) &&
              ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[3] == 1)
               || (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] ==
                   1) ||
               (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[2] == 1)))
          {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_IN_VETTORIALE;
          } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6]
                      == 1) && (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ > 30.0F)) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_A_IN_WAYPOINT;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.modo = 3.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 1.0;
          }
          break;

         case PROVA_FINALE_LOAD_ARDUI_IN_TEST:
          if (PROVA_FINALE_LOAD_ARDUINO_13_DW.test1 == 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_IN_VETTORIALE;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 0.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 0.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 0.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 0.0;
          }
          break;

         case PROVA_FINALE_LOAD_IN_VETTORIALE:
          if (PROVA_FINALE_LOAD_ARDUINO_13_DW.test1 == 1.0) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_ARDUI_IN_TEST;
          } else if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[7]
                      == 1) &&
                     (PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] < 1.0))
          {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FIN_IN_DECOLLO_AUTOMATICO;
          } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[8] ==
                     1) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_IN_ATTERRAGGIO_AUTOMATICO;
          } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6] ==
                     1) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_A_IN_WAYPOINT;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.modo = 2.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 1.0;
          }
          break;

         default:
          /* case IN_WAYPOINT: */
          if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6] == 0) &&
              ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[3] == 1)
               || (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] ==
                   1) ||
               (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[2] == 1)
               || (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[7] ==
                   1))) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_FINALE_LOAD_IN_VETTORIALE;
          } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[8] ==
                     1) {
            PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
              PROVA_IN_ATTERRAGGIO_AUTOMATICO;
          } else {
            PROVA_FINALE_LOAD_ARDUINO_13__B.modo = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 1.0;
            PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 1.0;
          }
          break;
        }
      }
      break;

     case PROVA_FINALE_LOAD_AR_IN_Go_Home:
      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home == 0.0) &&
          ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[6] == 1) ||
           (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[3] == 1) ||
           (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] == 1) ||
           (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[2] == 1) ||
           (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[8] == 1))) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_IN_AUTOMATICA;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
          PROVA_FINALE_LOAD_IN_VETTORIALE;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARDUI_IN_Safe;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_k == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINA_IN_Intervento_Pilota;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.modo = 5.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 1.0;
      }
      break;

     case PROVA_FINA_IN_Intervento_Pilota:
      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 1) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_AR_IN_MANUALE;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 0.0;
      }
      break;

     case PROVA_FINALE_LOAD_AR_IN_MANUALE:
      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home == 1.0) &&
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch == 0.0)) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_AR_IN_Go_Home;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 0)
      {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_A_IN_Stand_By;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 0.0;
      }
      break;

     case PROVA_FINALE_LOAD_ARDUI_IN_Safe:
      if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_k == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINA_IN_Intervento_Pilota;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 1)
      {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_AR_IN_MANUALE;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 1.0;
      }
      break;

     default:
      /* case IN_Stand_By: */
      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] == 1) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_IN_AUTOMATICA;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA =
          PROVA_FINALE_LOAD_IN_VETTORIALE;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 1)
      {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_AR_IN_MANUALE;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S38>/ STATI' */

  /* S-Function (PWMinterrupt_elevator_v4_4): '<S9>/S-Function Builder1' */
  PWMinterrupt_elevator_v4_4_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_elevator);

  /* Product: '<S572>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion13'
   *  DataTypeConversion: '<S9>/Data Type Conversion6'
   *  DataTypeConversion: '<S9>/Data Type Conversion7'
   *  Product: '<S573>/Divide'
   *  Product: '<S579>/Multiply'
   *  Sum: '<S572>/Sum'
   *  Sum: '<S572>/Sum1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home =
    PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[2] -
    PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[3];
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu = (real_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_elevator -
     PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[3]) /
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home;

  /* Sum: '<S572>/Sum2' incorporates:
   *  Constant: '<S572>/Constant8'
   *  Constant: '<S572>/Constant9'
   *  Sum: '<S579>/Sum1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Sum3_o_tmp =
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emax -
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin;

  /* Sum: '<S572>/Sum3' incorporates:
   *  Constant: '<S572>/Constant9'
   *  Product: '<S572>/Divide'
   *  Product: '<S572>/Multiply'
   *  Sum: '<S572>/Sum2'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o =
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu *
    PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Sum3_o_tmp +
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin;

  /* MATLAB Function: '<S38>/MATLAB Function' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 3.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 4.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
  }

  /* Gain: '<S573>/Gain' incorporates:
   *  Constant: '<S573>/Constant8'
   *  Constant: '<S573>/Constant9'
   *  Product: '<S573>/Multiply'
   *  Sum: '<S573>/Sum2'
   *  Sum: '<S573>/Sum3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu
    * (PROVA_FINALE_LOAD_ARDUINO_13__P.theta_max -
       PROVA_FINALE_LOAD_ARDUINO_13__P.theta_min) +
    PROVA_FINALE_LOAD_ARDUINO_13__P.theta_min) *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_h;

  /* Saturate: '<S573>/Saturation' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >
      PROVA_FINALE_LOAD_ARDUINO_13__P.theta_max) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.theta_max;
  } else {
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <
        PROVA_FINALE_LOAD_ARDUINO_13__P.theta_min) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.theta_min;
    }
  }

  /* End of Saturate: '<S573>/Saturation' */

  /* Sum: '<S37>/Sum2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_b = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1
    - PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_b;

  /* Sum: '<S349>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore beccheggio1'
   *  DiscreteIntegrator: '<S340>/Integrator'
   *  Product: '<S345>/PProd Out'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu =
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_b *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Kp_becch +
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE;

  /* Saturate: '<S347>/Saturation' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu >
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emax) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emax;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu <
             PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu;
  }

  /* End of Saturate: '<S347>/Saturation' */

  /* MultiPortSwitch: '<S302>/Switch Bumpless 2' */
  if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore == 0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation;
  }

  /* End of MultiPortSwitch: '<S302>/Switch Bumpless 2' */

  /* MultiPortSwitch: '<S307>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.AL != 0) {
    /* Switch: '<S307>/Switch1' incorporates:
     *  Constant: '<S307>/Constant5'
     */
    if (!(PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] >=
          PROVA_FINALE_LOAD_ARDUINO_13__P.Switch1_Threshold)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant5_Value;
    }

    /* End of Switch: '<S307>/Switch1' */
  }

  /* End of MultiPortSwitch: '<S307>/Multiport Switch2' */

  /* Logic: '<S39>/AND' */
  Ap_sel = ((PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta != 0.0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore != 0.0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni != 0.0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone != 0.0));

  /* Chart: '<S39>/Chart' incorporates:
   *  Logic: '<S39>/AND'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c21_PROVA_FINALE_LOAD == 0U) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c21_PROVA_FINALE_LOAD = 1U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_ARDUINO_IN_In;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
  } else {
    switch (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN) {
     case PROVA_FINALE_LOA_IN_AutoLanding:
      if ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone != 0.0))) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARDUINO_IN_In;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 2.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_IN_Vettoriale;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_A_IN_Waypoint;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 5.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARD_IN_GoHome;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 1.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      }
      break;

     case PROVA_FINALE_LOA_IN_AutoTakeoff:
      if ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone != 0.0))) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARDUINO_IN_In;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_A_IN_Waypoint;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 2.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_IN_Vettoriale;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      }
      break;

     case PROVA_FINALE_LOAD_ARD_IN_GoHome:
      if ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone != 0.0))) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARDUINO_IN_In;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 1.0;
      }
      break;

     case PROVA_FINALE_LOAD_ARDUINO_IN_In:
      PROVA_FINALE_LOAD_ARDUINO_13_In(&Ap_sel,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector);
      break;

     case PROVA_FINALE_LOAD_IN_Vettoriale:
      if ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni != 0.0)) ||
          (!(PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone != 0.0))) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARDUINO_IN_In;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_A_IN_Waypoint;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 5.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOAD_ARD_IN_GoHome;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 1.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 4.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN =
          PROVA_FINALE_LOA_IN_AutoLanding;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector = 0.0;
      }
      break;

     default:
      /* case IN_Waypoint: */
      PROVA_FINALE_LOAD_ARDU_Waypoint(&Ap_sel,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector,
        &PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector);
      break;
    }
  }

  /* End of Chart: '<S39>/Chart' */

  /* Outputs for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' incorporates:
   *  EnablePort: '<S438>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector > 0.0) {
    /* Outputs for Triggered SubSystem: '<S438>/Sample and Hold' incorporates:
     *  TriggerPort: '<S446>/Trigger'
     */
    /* Memory: '<S438>/Memory' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &PROVA_FINALE_LOAD_ARDUI_PrevZCX.SampleandHold_Trig_ZCE_h,
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_i));

    /* End of Outputs for SubSystem: '<S438>/Sample and Hold' */

    /* Outputs for Triggered SubSystem: '<S438>/Sample and Hold1' incorporates:
     *  TriggerPort: '<S447>/Trigger'
     */
    /* Memory: '<S438>/Memory1' */
    rt_ZCFcn(RISING_ZERO_CROSSING,
             &PROVA_FINALE_LOAD_ARDUI_PrevZCX.SampleandHold1_Trig_ZCE,
             (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_o));

    /* End of Outputs for SubSystem: '<S438>/Sample and Hold1' */

    /* Chart: '<S438>/Chart1' incorporates:
     *  DataTypeConversion: '<S554>/Data Type Conversion1'
     */
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.temporalCounter_i1 < 255U) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.temporalCounter_i1++;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c1_PROVA_FINALE_LOAD_ == 0U) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c1_PROVA_FINALE_LOAD_ = 1U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO =
        PROVA_FINALE_LOAD_IN_Fase_0_ATO;
    } else {
      switch (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO) {
       case PROVA_FINALE_LOAD_IN_Fase_0_ATO:
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 3.0) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO =
            PROVA_FINALE_LOAD_IN_Fase_1_ATO;
          PROVA_FINALE_LOAD_ARDUINO_13_DW.temporalCounter_i1 = 0U;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.theta_ground_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.eq_rot = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.h_ref = 0.0;
        }
        break;

       case PROVA_FINALE_LOAD_IN_Fase_1_ATO:
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.temporalCounter_i1 >= 250) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO =
            PROVA_FINALE_LOAD_IN_Fase_2_ATO;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.h_ref = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.eq_rot = 2.0;
        }
        break;

       case PROVA_FINALE_LOAD_IN_Fase_2_ATO:
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] >= 18.0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] >= 10.0)) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.theta_ground_selector = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO =
            PROVA_FINALE_LOAD_IN_Fase_3_ATO;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO = 2.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.h_ref = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.eq_rot = 2.0;
        }
        break;

       case PROVA_FINALE_LOAD_IN_Fase_3_ATO:
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ >= 2.0F) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO =
            PROVA_FINALE_LOAD_IN_Fase_4_ATO;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO = 3.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.theta_ground_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.h_ref = 0.0;
        }
        break;

       default:
        /* case IN_Fase_4_ATO: */
        PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO = 4.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_ref = 35.0;
        break;
      }
    }

    /* End of Chart: '<S438>/Chart1' */

    /* Update for Memory: '<S438>/Memory' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_i =
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_selector;

    /* Update for Memory: '<S438>/Memory1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_o =
      PROVA_FINALE_LOAD_ARDUINO_13__B.theta_ground_selector;
  }

  /* End of Outputs for SubSystem: '<S39>/DECOLLO AUTOMATICO' */

  /* MultiPortSwitch: '<S308>/Multiport Switch2' incorporates:
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO != 0) {
    /* MultiPortSwitch: '<S308>/Multiport Switch1' incorporates:
     *  Gain: '<S357>/Gain1'
     */
    switch ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO) {
     case 0:
      PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_jm *
        PROVA_FINALE_LOAD_ARDUINO_13__B.eq_rot;
      break;

     case 1:
      PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_jm *
        PROVA_FINALE_LOAD_ARDUINO_13__B.eq_rot;
      break;

     case 2:
      PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_jm *
        PROVA_FINALE_LOAD_ARDUINO_13__B.eq_rot;
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
  if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore != 0) {
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
    if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore == 0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_fj;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_i4;
    } else {
      /* Abs: '<S302>/Abs1' incorporates:
       *  Abs: '<S302>/Abs'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m);
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[4] - sin
         (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) *
         PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[5]) *
        PROVA_FINALE_LOAD_ARDUINO_13__P.Kp_q;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 *=
        PROVA_FINALE_LOAD_ARDUINO_13__P.inv_comp_h *
        PROVA_FINALE_LOAD_ARDUINO_13__P.Kp_comp_h;
    }

    /* End of MultiPortSwitch: '<S302>/Switch 1' */

    /* Sum: '<S302>/Sum2' incorporates:
     *  Sum: '<S302>/Sum'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      (PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o) -
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

    /* Saturate: '<S302>/saturatore E2' */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >
        PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emax) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emax;
    } else {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <
          PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
          PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin;
      }
    }

    /* End of Saturate: '<S302>/saturatore E2' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o =
      PROVA_FINALE_LOAD_ARDUINO_13__P.inv_E *
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 1' */

  /* Sum: '<S29>/Sum' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S30>/Gain'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Rn =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_od *
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o +
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_m;

  /* S-Function (PWMinterrupt_aileron_v4_4): '<S9>/S-Function Builder7' */
  PWMinterrupt_aileron_v4_4_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_aileron);

  /* Product: '<S570>/Divide' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion14'
   *  DataTypeConversion: '<S9>/Data Type Conversion8'
   *  DataTypeConversion: '<S9>/Data Type Conversion9'
   *  Product: '<S571>/Divide'
   *  Product: '<S576>/Multiply'
   *  Sum: '<S570>/Sum'
   *  Sum: '<S570>/Sum1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector =
    PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[4] -
    PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[5];
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o = (real_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_aileron -
     PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[5]) /
    PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector;

  /* Sum: '<S570>/Sum2' incorporates:
   *  Constant: '<S570>/Constant8'
   *  Constant: '<S570>/Constant9'
   *  Sum: '<S576>/Sum1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Sum3_b_tmp =
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax -
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin;

  /* Sum: '<S570>/Sum3' incorporates:
   *  Constant: '<S570>/Constant9'
   *  Product: '<S570>/Divide'
   *  Product: '<S570>/Multiply'
   *  Sum: '<S570>/Sum2'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_b = PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o
    * PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Sum3_b_tmp +
    PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin;

  /* Gain: '<S571>/Gain' incorporates:
   *  Constant: '<S571>/Constant8'
   *  Constant: '<S571>/Constant9'
   *  Product: '<S571>/Multiply'
   *  Sum: '<S571>/Sum2'
   *  Sum: '<S571>/Sum3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o *
    (PROVA_FINALE_LOAD_ARDUINO_13__P.phi_max -
     PROVA_FINALE_LOAD_ARDUINO_13__P.phi_min) +
    PROVA_FINALE_LOAD_ARDUINO_13__P.phi_min) *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_a;

  /* Saturate: '<S571>/Saturation' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >
      PROVA_FINALE_LOAD_ARDUINO_13__P.phi_max) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.phi_max;
  } else {
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <
        PROVA_FINALE_LOAD_ARDUINO_13__P.phi_min) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__P.phi_min;
    }
  }

  /* End of Saturate: '<S571>/Saturation' */

  /* Sum: '<S37>/Sum5' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1
    - PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m;

  /* Sum: '<S303>/Sum' incorporates:
   *  Constant: '<S303>/Constant3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o =
    PROVA_FINALE_LOAD_ARDUINO_13__B.Fase_ATO -
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant3_Value_cr;

  /* DiscreteIntegrator: '<S390>/Integrator' */
  if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o > 0.0) &&
      (PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_PrevResetState <= 0)) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE_p =
      PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_InitialConditio_d;
  }

  /* Sum: '<S399>/Sum' incorporates:
   *  Constant: '<S8>/Kp controllore  rollio3'
   *  DiscreteIntegrator: '<S390>/Integrator'
   *  Product: '<S395>/PProd Out'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_n3 =
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Kp_roll +
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE_p;

  /* Saturate: '<S397>/Saturation' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_n3 >
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation_f =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_n3 <
             PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation_f =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation_f =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_n3;
  }

  /* End of Saturate: '<S397>/Saturation' */

  /* MultiPortSwitch: '<S303>/Switch Bumpless 1' incorporates:
   *  Constant: '<S303>/Constant1'
   *  Constant: '<S8>/Kp controllore  velocità rollio3'
   *  Product: '<S303>/Product3'
   */
  if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni == 0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_ng;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[3] *
      PROVA_FINALE_LOAD_ARDUINO_13__P.Kp_p;
  }

  /* End of MultiPortSwitch: '<S303>/Switch Bumpless 1' */

  /* Sum: '<S303>/Sum2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o =
    PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation_f -
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;

  /* MultiPortSwitch: '<S37>/Switch Bumpless 3' incorporates:
   *  Saturate: '<S37>/saturatore A1'
   */
  if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni == 0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_b;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o >
             PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax) {
    /* Saturate: '<S37>/saturatore A1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o <
             PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin) {
    /* Saturate: '<S37>/saturatore A1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin;
  } else {
    /* Saturate: '<S37>/saturatore A1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 3' */

  /* Saturate: '<S37>/saturatore A' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c >
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amax;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c <
             PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni =
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c;
  }

  /* End of Saturate: '<S37>/saturatore A' */

  /* MultiPortSwitch: '<S37>/Switch Bumpless 5' incorporates:
   *  Gain: '<S37>/Gain1'
   */
  if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni == 0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_b;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c =
      PROVA_FINALE_LOAD_ARDUINO_13__P.inv_A *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 5' */

  /* Sum: '<S29>/Sum1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S31>/Gain'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_i *
    PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c +
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_m;

  /* S-Function (PWMinterrupt_rudder_v4_4): '<S9>/S-Function Builder8' */
  PWMinterrupt_rudder_v4_4_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_rudder);

  /* DiscreteTransferFcn: '<S304>/Discrete Washout Filter' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.denAccum =
    (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_cx[5] -
     PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteWashoutFilter_DenCoef[1] *
     PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteWashoutFilter_states) /
    PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteWashoutFilter_DenCoef[0];

  /* MultiPortSwitch: '<S37>/Switch Bumpless 6' incorporates:
   *  Constant: '<S574>/Constant8'
   *  Constant: '<S574>/Constant9'
   *  DataTypeConversion: '<S9>/Data Type Conversion10'
   *  DataTypeConversion: '<S9>/Data Type Conversion11'
   *  DataTypeConversion: '<S9>/Data Type Conversion15'
   *  Gain: '<S37>/Gain2'
   *  MultiPortSwitch: '<S37>/Switch Bumpless 4'
   *  Product: '<S574>/Divide'
   *  Product: '<S574>/Multiply'
   *  Sum: '<S574>/Sum1'
   *  Sum: '<S574>/Sum2'
   *  Sum: '<S574>/Sum3'
   *  Sum: '<S574>/Sum4'
   */
  if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone == 0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o = (real_T)
      (PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_rudder -
       PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[7]) /
      (real_T)
      (PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[6] -
       PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[7]) *
      (PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmax -
       PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin) +
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin;
  } else {
    if ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone == 0) {
      /* MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
       *  Constant: '<S574>/Constant8'
       *  Constant: '<S574>/Constant9'
       *  DataTypeConversion: '<S9>/Data Type Conversion10'
       *  DataTypeConversion: '<S9>/Data Type Conversion11'
       *  DataTypeConversion: '<S9>/Data Type Conversion15'
       *  Product: '<S574>/Divide'
       *  Product: '<S574>/Multiply'
       *  Sum: '<S574>/Sum1'
       *  Sum: '<S574>/Sum2'
       *  Sum: '<S574>/Sum3'
       *  Sum: '<S574>/Sum4'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o = (real_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.PWM_rudder -
         PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[7]) /
        (real_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[6] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[7]) *
        (PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmax -
         PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin) +
        PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin;
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
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o =
        (PROVA_FINALE_LOAD_ARDUINO_13__P.r_rif_Value -
         (PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteWashoutFilter_NumCoef[0] *
          PROVA_FINALE_LOAD_ARDUINO_13__B.denAccum +
          PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteWashoutFilter_NumCoef[1] *
          PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteWashoutFilter_states)) *
        PROVA_FINALE_LOAD_ARDUINO_13__P.Kp_imb + (real_T)
        (PROVA_FINALE_LOAD_ARDUINO_13__P.Gain3_Gain *
         PROVA_FINALE_LOAD_ARDUINO_13__P.K_imb_inv) * 0.0078125 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o;
    }

    /* Saturate: '<S37>/saturatore R' */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o >
        PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmax) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o =
        PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmax;
    } else {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o <
          PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o =
          PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin;
      }
    }

    /* End of Saturate: '<S37>/saturatore R' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o *=
      PROVA_FINALE_LOAD_ARDUINO_13__P.inv_R;
  }

  /* End of MultiPortSwitch: '<S37>/Switch Bumpless 6' */

  /* Sum: '<S29>/Sum2' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_bh *
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o +
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_m;

  /* Gain: '<S20>/Gain' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_jr *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_b;

  /* Saturate: '<S20>/Saturation' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >
      PROVA_FINALE_LOAD_ARDUINO_13__P.Saturation_UpperSat) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Saturation_UpperSat;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <
             PROVA_FINALE_LOAD_ARDUINO_13__P.Saturation_LowerSat) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Saturation_LowerSat;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_bh < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_bh);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_bh);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[0] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[1] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[2] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[3] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[4] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[0] < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[0]);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[0]);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[5] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[1] < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[1]);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[1]);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[6] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[2] < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[2]);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_pa[2]);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[7] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut;
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = ceil
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);
  }

  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[8] = (uint16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* Memory: '<S2>/Memory' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_a =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_n;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S557>/Delay Input2'
   *
   * Block description for '<S557>/Delay Input2':
   *
   *  Store in Global RAM
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2 = (real32_T)
    PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S554>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_l = (real32_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__P.PatohPa_Gain * (real_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_g = (real32_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__P.PatohPa1_Gain *
     PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_jt);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.f = (real32_T)floor
    (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1);
  if (rtIsNaNF(PROVA_FINALE_LOAD_ARDUINO_13__B.f) || rtIsInfF
      (PROVA_FINALE_LOAD_ARDUINO_13__B.f)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.f = 0.0F;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.f = (real32_T)fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_m = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.f : (int32_T)(int16_T)(uint16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.f);

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem1' incorporates:
   *  EnablePort: '<S440>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector > 0.0) {
    /* DataTypeConversion: '<S440>/Data Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function1'
     */
    for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0;
         PROVA_FINALE_LOAD_ARDUINO_13__B.i < 42;
         PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
        =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_AL[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
    }

    /* End of DataTypeConversion: '<S440>/Data Type Conversion4' */

    /* MATLAB Function: '<S440>/CALIBRATING_HOME_COORDINATES' incorporates:
     *  DataTypeConversion: '<S440>/Data Type Conversion4'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Rn =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[30] *
      0.017453292519943295;
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_Home =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[36];
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[25] *
       0.017453292519943295);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[24] *
       0.017453292519943295);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[24] *
       0.017453292519943295);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[31] *
      0.017453292519943295 -
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[30] *
      0.017453292519943295;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = rt_atan2d_snf(sin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o) *
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, sin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[25] *
       0.017453292519943295) * PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector - cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o) *
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk *
       PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1));
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o < 0.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = 6.2831853071795862 - fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
    }

    /* MATLAB Function: '<S453>/MATLAB Function' incorporates:
     *  Constant: '<S453>/distance waypoints virtuale'
     *  MATLAB Function: '<S440>/CALIBRATING_HOME_COORDINATES'
     *  Trigonometry: '<S524>/SinCos'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__P.distancewaypointsvirtuale_Value[0] /
       6.378137E+6);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__P.distancewaypointsvirtuale_Value[0] /
       6.378137E+6);
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n = asin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
       PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 +
       PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);

    /* MATLAB Function: '<S453>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S453>/alt waypoint virtuale'
     *  Gain: '<S469>/Gain'
     *  Gain: '<S470>/Gain'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[12] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_es *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[15] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_k * (rt_atan2d_snf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector,
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk * sin
       (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n)) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[3] = 1.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[6] = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[9] = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[18] =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_Home +
      PROVA_FINALE_LOAD_ARDUINO_13__P.altwaypointvirtuale_Value[0];

    /* MATLAB Function: '<S453>/MATLAB Function' incorporates:
     *  Constant: '<S453>/distance waypoints virtuale'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__P.distancewaypointsvirtuale_Value[1] /
       6.378137E+6);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__P.distancewaypointsvirtuale_Value[1] /
       6.378137E+6);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n = asin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
       PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 +
       PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar);

    /* MATLAB Function: '<S453>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S453>/Constant1'
     *  Constant: '<S453>/alt waypoint virtuale'
     *  Gain: '<S469>/Gain'
     *  Gain: '<S470>/Gain'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[13] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_es *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[16] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_k * (rt_atan2d_snf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector,
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk * sin
       (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n)) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[1] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.vel_wp2_al;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[4] = 1.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[7] = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[10] = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[19] =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_Home +
      PROVA_FINALE_LOAD_ARDUINO_13__P.altwaypointvirtuale_Value[1];

    /* MATLAB Function: '<S453>/MATLAB Function' incorporates:
     *  Constant: '<S453>/distance waypoints virtuale'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__P.distancewaypointsvirtuale_Value[2] /
       6.378137E+6);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__P.distancewaypointsvirtuale_Value[2] /
       6.378137E+6);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n = asin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
       PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 +
       PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar);

    /* MATLAB Function: '<S453>/AUTOLANDING_WAYPOINTS' incorporates:
     *  Constant: '<S453>/Constant'
     *  Constant: '<S453>/Constant1'
     *  Constant: '<S453>/alt waypoint virtuale'
     *  Gain: '<S469>/Gain'
     *  Gain: '<S470>/Gain'
     *  MATLAB Function: '<S453>/MATLAB Function'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[14] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_es *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[17] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_k * (rt_atan2d_snf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector,
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk * sin
       (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n)) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[2] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.vel_wp2_al;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[8] = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[11] = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[20] =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_Home +
      PROVA_FINALE_LOAD_ARDUINO_13__P.altwaypointvirtuale_Value[2];
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[0] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.vel_wp1_al;
    PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[5] = 0.0;

    /* Gain: '<S458>/Gain' incorporates:
     *  DataTypeConversion: '<S440>/Data Type Conversion4'
     *  MATLAB Function: '<S440>/CALIBRATING_HOME_COORDINATES'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[24] *
      0.017453292519943295 * PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_p;

    /* Switch: '<S534>/Switch' incorporates:
     *  Abs: '<S534>/Abs'
     *  Bias: '<S534>/Bias'
     *  Bias: '<S534>/Bias1'
     *  Constant: '<S534>/Constant2'
     *  Constant: '<S535>/Constant'
     *  Math: '<S534>/Math Function1'
     *  RelationalOperator: '<S535>/Compare'
     */
    if (fabs(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain) >
        PROVA_FINALE_LOAD_ARDUINO_13__P.CompareToConstant_const) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk = rt_modd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Bias_Bias_e,
         PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_n) +
        PROVA_FINALE_LOAD_ARDUINO_13__P.Bias1_Bias_j;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Gain;
    }

    /* End of Switch: '<S534>/Switch' */

    /* Abs: '<S531>/Abs1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = fabs
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);

    /* RelationalOperator: '<S533>/Compare' incorporates:
     *  Constant: '<S533>/Constant'
     */
    Ap_sel = (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector >
              PROVA_FINALE_LOAD_ARDUINO_13__P.CompareToConstant_const_d);

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
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk = -1.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk > 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk = 1.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk == 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk = (rtNaN);
      }

      /* End of Signum: '<S531>/Sign1' */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk *=
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Bias_Bias_f) *
        PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_mn +
        PROVA_FINALE_LOAD_ARDUINO_13__P.Bias1_Bias_f;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_d;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_d5;
    }

    /* End of Switch: '<S531>/Switch' */

    /* Gain: '<S459>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_g =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_b2 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;

    /* Sum: '<S523>/Sum' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Rn =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_g;

    /* Sum: '<S457>/Sum1' incorporates:
     *  Gain: '<S461>/Gain'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_f *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0] -
      PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk;

    /* Switch: '<S528>/Switch' incorporates:
     *  Abs: '<S528>/Abs'
     *  Bias: '<S528>/Bias'
     *  Bias: '<S528>/Bias1'
     *  Constant: '<S528>/Constant2'
     *  Constant: '<S529>/Constant'
     *  Math: '<S528>/Math Function1'
     *  RelationalOperator: '<S529>/Compare'
     */
    if (fabs(PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector) >
        PROVA_FINALE_LOAD_ARDUINO_13__P.CompareToConstant_const_b) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = rt_modd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Bias_Bias_n,
         PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_i) +
        PROVA_FINALE_LOAD_ARDUINO_13__P.Bias1_Bias_n;
    }

    /* End of Switch: '<S528>/Switch' */

    /* Abs: '<S525>/Abs1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = fabs
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);

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
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f >
        PROVA_FINALE_LOAD_ARDUINO_13__P.CompareToConstant_const_dp) {
      /* Signum: '<S525>/Sign1' */
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = -1.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector > 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 1.0;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector == 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 0.0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = (rtNaN);
      }

      /* End of Signum: '<S525>/Sign1' */
      PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f +
          PROVA_FINALE_LOAD_ARDUINO_13__P.Bias_Bias) *
         PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_b +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Bias1_Bias) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_n;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_p;
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
    if (fabs(PROVA_FINALE_LOAD_ARDUINO_13__B.Rn) >
        PROVA_FINALE_LOAD_ARDUINO_13__P.CompareToConstant_const_p) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = rt_modd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Bias_Bias_jc,
         PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_b) +
        PROVA_FINALE_LOAD_ARDUINO_13__P.Bias1_Bias_gb;
    }

    /* End of Switch: '<S532>/Switch' */

    /* Sum: '<S522>/Sum' incorporates:
     *  Gain: '<S460>/Gain'
     *  Sum: '<S457>/Sum1'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar =
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_d *
       PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[1] -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Rn) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector;

    /* Gain: '<S521>/Gain1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain *
      PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut;

    /* Sum: '<S539>/Sum' incorporates:
     *  Constant: '<S539>/Constant'
     *  Constant: '<S539>/f'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
      PROVA_FINALE_LOAD_ARDUINO_13__P.f_Value -
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_j;

    /* Sqrt: '<S540>/Sqrt' incorporates:
     *  Constant: '<S540>/Constant4'
     *  Product: '<S540>/Product'
     *  Sum: '<S540>/Sum'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut = sqrt
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant4_Value_o -
       PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut *
       PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut);

    /* Gain: '<S538>/Gain1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk *=
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain_j;

    /* Trigonometry: '<S541>/Trigonometric Function1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);

    /* Sum: '<S541>/Sum1' incorporates:
     *  Constant: '<S541>/Constant'
     *  Product: '<S541>/Product1'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_nw -
      PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut *
      PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f;

    /* Product: '<S537>/Product1' incorporates:
     *  Constant: '<S537>/Constant1'
     *  Sqrt: '<S537>/sqrt'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Rn =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_j / sqrt
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f);

    /* Switch: '<S526>/Switch' incorporates:
     *  Abs: '<S526>/Abs'
     *  Bias: '<S526>/Bias'
     *  Bias: '<S526>/Bias1'
     *  Constant: '<S526>/Constant2'
     *  Constant: '<S530>/Constant'
     *  Math: '<S526>/Math Function1'
     *  RelationalOperator: '<S530>/Compare'
     */
    if (fabs(PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) >
        PROVA_FINALE_LOAD_ARDUINO_13__P.CompareToConstant_const_g) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar = rt_modd_snf
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar +
         PROVA_FINALE_LOAD_ARDUINO_13__P.Bias_Bias_j,
         PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_gk) +
        PROVA_FINALE_LOAD_ARDUINO_13__P.Bias1_Bias_g;
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
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector / rt_atan2d_snf
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_j,
       (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_h -
        PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut *
        PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut) *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Rn /
       PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f) *
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 + 1.0 / rt_atan2d_snf
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Constant3_Value_f,
       PROVA_FINALE_LOAD_ARDUINO_13__B.Rn * cos
       (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk)) *
      (PROVA_FINALE_LOAD_ARDUINO_13__P.Gain1_Gain *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o;

    /* Gain: '<S462>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_o *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0];

    /* Gain: '<S463>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_ov *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[1];

    /* MATLAB Function: '<S440>/ALLINEAMENTO' incorporates:
     *  Memory: '<S440>/Memory7'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp =
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 11];
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = sin
      ((PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp -
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) * 3.1415926535897931 / 180.0 /
       2.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut =
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 14];
    PROVA_FINALE_LOAD_ARDUINO_13__B.dist =
      (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) * 3.1415926535897931 / 180.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = sin
      (PROVA_FINALE_LOAD_ARDUINO_13__B.dist / 2.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp * 3.1415926535897931 / 180.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar * 3.1415926535897931 / 180.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp);
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = PROVA_FINALE_LOAD_ARDUINO_13__B.Rn *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = rt_atan2d_snf(sqrt
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1), sqrt(1.0 -
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) * 2.0 * 6.378137E+6;
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput > 1.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 11];
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist =
        PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 14];
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut -
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f, sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 11] *
         3.1415926535897931 / 180.0) * PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 -
        sin(PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f * cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp = sin
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar -
          PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp) * 3.1415926535897931 /
         180.0 / 2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist = sin
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n -
          PROVA_FINALE_LOAD_ARDUINO_13__B.dist) * 3.1415926535897931 / 180.0 /
         2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn *
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist *
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist) +
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist = rt_atan2d_snf(sqrt
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1), sqrt(1.0 -
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) * 2.0 * 6.378137E+6;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f, sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn - cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist) * (sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f)) * 180.0 /
        3.1415926535897931;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist = 0.0;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector < 0.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 360.0 - fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
      PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 2];
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 1.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 1.0) + 11];
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp = sin
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp -
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp) * 3.1415926535897931 / 180.0 /
         2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 1.0) + 14] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut = sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp / 2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp);
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp *
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut *
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut) +
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut = rt_atan2d_snf(sqrt
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut), sqrt(1.0 -
        PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut)) * 2.0 * 6.378137E+6;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp, sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f - cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp) * (sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 11] *
         3.1415926535897931 / 180.0) * PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp))
        * 180.0 / 3.1415926535897931;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = 360.0 - fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f);
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput > 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f -
           PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f - rt_atan2d_snf(sin
            ((PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 14] -
              PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) * 3.1415926535897931 /
             180.0) * cos(PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
                          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput
                          + 11] * 3.1415926535897931 / 180.0), sin
            (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
             PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 11] *
             3.1415926535897931 / 180.0) * cos
            (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar * 3.1415926535897931 / 180.0)
            - cos(PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 11] *
                  3.1415926535897931 / 180.0) * sin
            (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar * 3.1415926535897931 / 180.0)
            * cos((PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
                   PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput + 14] -
                   PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) * 3.1415926535897931 /
                  180.0)) * 180.0 / 3.1415926535897931);
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = 0.0;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput < 2.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = 0.0;
    } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput == 2.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 14] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector - rt_atan2d_snf(sin
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) *
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp, sin
          (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
           (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 11] *
           3.1415926535897931 / 180.0) * PROVA_FINALE_LOAD_ARDUINO_13__B.Rn -
          cos(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) * (sin
           (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar * 3.1415926535897931 / 180.0)
           * PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp)) * 180.0 /
         3.1415926535897931);
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar =
        PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 2.0) + 11] *
        3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 14] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn, cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) * sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1.0) + 11] *
         3.1415926535897931 / 180.0) - sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn * cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n)) * 180.0 / 3.1415926535897931;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = 360.0 - fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector -
         PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 3.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 1.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 20;
    } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 10.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 30.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 100;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f > 10.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 50.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 80.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 250;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f > 50.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 90.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 100.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 300;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f > 90.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 120.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 150.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 350;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 200.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 400;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 10.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 80;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Rn > 10.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 50.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 200;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Rn > 50.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 90.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 300;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Rn > 90.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 120.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 350;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 400;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 1.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param_m[(int32_T)
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput - 1];
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <= 20.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.1;
      } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <= 25.0) &&
                 (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 > 20.0)) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.2;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <= 30.0) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 > 25.0) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.3;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.4;
        }
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.4;
      }

      if (((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist <
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o >
              PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector))) &&
          ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist >
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o >
              PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector))) &&
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o <
           PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector)) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut >
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput++;
        } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput < 2.0)
        {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput += 2.0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_c = 1.0;
        }
      }
    } else {
      if (((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist <
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_c == 0.0))) &&
          ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist >
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o > 40.0)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_c == 0.0)))) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_c = 1.0;
      }
    }

    if (!(PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 4.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput = 1.0;
    }

    /* End of MATLAB Function: '<S440>/ALLINEAMENTO' */

    /* Abs: '<S440>/Abs1' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fabs
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk);

    /* Chart: '<S440>/Chart1' incorporates:
     *  DataTypeConversion: '<S554>/Data Type Conversion1'
     *  Memory: '<S440>/Memory1'
     *  Memory: '<S440>/Memory2'
     *  Memory: '<S440>/Memory5'
     */
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c10_PROVA_FINALE_LOAD == 0U) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c10_PROVA_FINALE_LOAD = 1U;
      PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector = 1.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector = 1.0;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
        PROVA_FINALE_LOA_IN_Allignment1;
    } else {
      switch (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN) {
       case PROVA_FINALE_LOAD_ARDU_IN_Abort:
        PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector = 0.0;
        break;

       case PROVA_FINALE_LOAD_IN_Allignment:
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.h_ > 35.0F) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ < 60.0F) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <=
             PROVA_FINALE_LOAD_ARDUINO_13__B.h_ * 19.081136687728211 + 100.0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 >=
             PROVA_FINALE_LOAD_ARDUINO_13__B.h_ * 14.300666256711928 + 100.0) &&
            (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput > 1.0)) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOAD_A_IN_Approach;
        } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo != 4.0) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOA_IN_Allignment1;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach = 0.0;
        }
        break;

       case PROVA_FINALE_LOA_IN_Allignment1:
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo == 4.0) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOAD_IN_Allignment;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector = 0.0;
        }
        break;

       case PROVA_FINALE_LOAD_A_IN_Approach:
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk >=
             PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory5_PreviousInput) &&
            ((PROVA_FINALE_LOAD_ARDUINO_13__B.h_ <=
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_l + 1.5) ||
             (PROVA_FINALE_LOAD_ARDUINO_13__B.h_ >
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_l - 1.0))) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOAD_ARDU_IN_Flare;
        } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.modo != 4.0) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOA_IN_Allignment1;
        } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_f ==
                   1.0) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOAD_ARDU_IN_Abort;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector = 2.0;
        }
        break;

       default:
        /* case IN_Flare: */
        if ((PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[2] < 3.0) ||
            (!(PROVA_FINALE_LOAD_ARDUINO_13__B.modo != 4.0))) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare = 1.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector = 0.0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector = 3.0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN =
            PROVA_FINALE_LOA_IN_Allignment1;
        }
        break;
      }
    }

    /* End of Chart: '<S440>/Chart1' */

    /* Outputs for Triggered SubSystem: '<S440>/Sample and Hold' incorporates:
     *  TriggerPort: '<S465>/Trigger'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &PROVA_FINALE_LOAD_ARDUI_PrevZCX.SampleandHold_Trig_ZCE,
      (PROVA_FINALE_LOAD_ARDUINO_13__B.approach_selector));
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.zcEvent != NO_ZCEVENT) {
      /* Inport: '<S465>/In' incorporates:
       *  Abs: '<S440>/Abs2'
       *  Constant: '<S440>/Constant4'
       *  Sum: '<S457>/Sum'
       *  UnaryMinus: '<S457>/Ze2height'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.In[0] = fabs
        (-(PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 +
           PROVA_FINALE_LOAD_ARDUINO_13__P.Constant4_Value_j));
      PROVA_FINALE_LOAD_ARDUINO_13__B.In[1] =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk;
    }

    /* End of Outputs for SubSystem: '<S440>/Sample and Hold' */

    /* Outputs for Enabled SubSystem: '<S440>/APPROACH' incorporates:
     *  EnablePort: '<S451>/Enable'
     */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach > 0.0) {
      /* Product: '<S451>/Divide' incorporates:
       *  Constant: '<S451>/x_g0'
       *  Sum: '<S451>/Sum'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut =
        PROVA_FINALE_LOAD_ARDUINO_13__B.In[0] /
        (PROVA_FINALE_LOAD_ARDUINO_13__B.In[1] -
         PROVA_FINALE_LOAD_ARDUINO_13__P.x_g0_Value);

      /* Abs: '<S451>/Abs' incorporates:
       *  Trigonometry: '<S451>/Atan'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = fabs(atan
        (PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut));

      /* DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
      if ((PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach > 0.0) &&
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_PrevRese <= 0))
      {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE =
          PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_IC;
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE >=
          PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_UpperSat) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE =
          PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE <=
            PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_LowerSat) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE =
            PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      /* Switch: '<S451>/Switch' incorporates:
       *  Constant: '<S451>/Constant3'
       *  Constant: '<S451>/Constant4'
       *  DiscreteIntegrator: '<S451>/Discrete-Time Integrator'
       */
      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE >
          PROVA_FINALE_LOAD_ARDUINO_13__P.Switch_Threshold) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
          PROVA_FINALE_LOAD_ARDUINO_13__P.Constant3_Value;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
          PROVA_FINALE_LOAD_ARDUINO_13__P.Constant4_Value;
      }

      /* End of Switch: '<S451>/Switch' */

      /* MATLAB Function: '<S451>/MATLAB Function' */
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
      if ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.x_not_empty) ||
          (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 0.0)) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[0] = 1.5;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1] = -200.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2] = 0.01;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[3] = -2.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x_not_empty = true;
      }

      PROVA_FINALE_LOAD_ARDUINO_13_DW.x_new_not_empty =
        ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.x_new_not_empty) ||
         (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 0.0) ||
         PROVA_FINALE_LOAD_ARDUINO_13_DW.x_new_not_empty);
      if ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.eps_not_empty) ||
          (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 0.0)) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[0] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[1] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[2] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[3] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps_not_empty = true;
      }

      if ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.cycle_count_not_empty) ||
          (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 == 0.0)) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.cycle_count = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[0] < 0.1)) ||
                           ((!(PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[1] < 0.1)) ||
                            ((!(PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[2] < 0.1)) ||
                (!(PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[3] < 0.1)))))) {
        memset(&PROVA_FINALE_LOAD_ARDUINO_13__B.a[0], 0, sizeof(real_T) << 4U);
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = exp((5.0 -
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1]) *
          -PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2]);
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar = tan
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o);
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[0] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[4] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[8] = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[12] = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[1] =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2];
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[5] = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[0] -
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[3];
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[9] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[13] =
          -PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2];
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[2] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2];
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[6] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[10] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1] - 5.0) *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[14] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[3] =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2] * 18.0 *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[7] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2] *
           PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2]) * 18.0 *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n * 18.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[11] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1] - 5.0) *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn +
          PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f * 18.0 *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.A[15] =
          -PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2] * 18.0 *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn;
        PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[0] = 1;
        PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[1] = 2;
        PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[2] = 3;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 3;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.caso =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO * 5;
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol = 0;
          PROVA_FINALE_LOAD_ARDUINO_13__B.i =
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fabs
            (PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.caso]);
          PROVA_FINALE_LOAD_ARDUINO_13__B.jy = 2;
          while (PROVA_FINALE_LOAD_ARDUINO_13__B.jy <= 4 -
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i++;
            PROVA_FINALE_LOAD_ARDUINO_13__B.dist = fabs
              (PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.i]);
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.dist >
                PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                PROVA_FINALE_LOAD_ARDUINO_13__B.jy - 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
                PROVA_FINALE_LOAD_ARDUINO_13__B.dist;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.jy++;
          }

          if (PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
              + PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol] != 0.0) {
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol != 0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol +=
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                = (int8_T)(PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol + 1);
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
                = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 4];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 4] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 4];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 4] = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 8];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 8] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 8];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 8] = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 12];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 12] =
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 12];
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 12] = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.i =
              (PROVA_FINALE_LOAD_ARDUINO_13__B.caso -
               PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) + 4;
            PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol + 1 <=
                   PROVA_FINALE_LOAD_ARDUINO_13__B.i) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
                /=
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.caso];
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.i =
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          PROVA_FINALE_LOAD_ARDUINO_13__B.jy =
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 4;
          PROVA_FINALE_LOAD_ARDUINO_13__B.c = 0;
          while (PROVA_FINALE_LOAD_ARDUINO_13__B.c <= 2 -
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) {
            if (PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jy]
                != 0.0) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
                -PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.jy];
              PROVA_FINALE_LOAD_ARDUINO_13__B.c_ix =
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1;
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                (PROVA_FINALE_LOAD_ARDUINO_13__B.i -
                 PROVA_FINALE_LOAD_ARDUINO_13__B.ATO) + 8;
              PROVA_FINALE_LOAD_ARDUINO_13__B.ijA =
                PROVA_FINALE_LOAD_ARDUINO_13__B.i + 5;
              while (PROVA_FINALE_LOAD_ARDUINO_13__B.ijA + 1 <=
                     PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol) {
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.ijA]
                  +=
                  PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.c_ix]
                  * PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
                PROVA_FINALE_LOAD_ARDUINO_13__B.c_ix++;
                PROVA_FINALE_LOAD_ARDUINO_13__B.ijA++;
              }
            }

            PROVA_FINALE_LOAD_ARDUINO_13__B.jy += 4;
            PROVA_FINALE_LOAD_ARDUINO_13__B.i += 4;
            PROVA_FINALE_LOAD_ARDUINO_13__B.c++;
          }
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.p[0] = 1;
        PROVA_FINALE_LOAD_ARDUINO_13__B.p[1] = 2;
        PROVA_FINALE_LOAD_ARDUINO_13__B.p[2] = 3;
        PROVA_FINALE_LOAD_ARDUINO_13__B.p[3] = 4;
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[0] > 1) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.p[PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv
            [0] - 1];
          PROVA_FINALE_LOAD_ARDUINO_13__B.p[PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[
            0] - 1] = 1;
          PROVA_FINALE_LOAD_ARDUINO_13__B.p[0] = (int8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
        }

        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[1] > 2) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.p[PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv
            [1] - 1];
          PROVA_FINALE_LOAD_ARDUINO_13__B.p[PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[
            1] - 1] = PROVA_FINALE_LOAD_ARDUINO_13__B.p[1];
          PROVA_FINALE_LOAD_ARDUINO_13__B.p[1] = (int8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
        }

        if (PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[2] > 3) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.p[PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv
            [2] - 1];
          PROVA_FINALE_LOAD_ARDUINO_13__B.p[PROVA_FINALE_LOAD_ARDUINO_13__B.ipiv[
            2] - 1] = PROVA_FINALE_LOAD_ARDUINO_13__B.p[2];
          PROVA_FINALE_LOAD_ARDUINO_13__B.p[2] = (int8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.c = PROVA_FINALE_LOAD_ARDUINO_13__B.p[0]
          - 1;
        PROVA_FINALE_LOAD_ARDUINO_13__B.a[(PROVA_FINALE_LOAD_ARDUINO_13__B.p[0]
          - 1) << 2] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
        while (PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1 < 5) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.c << 2;
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i =
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.i + 1 < 5) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jy =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jy]
                -=
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
                * PROVA_FINALE_LOAD_ARDUINO_13__B.A
                [(PROVA_FINALE_LOAD_ARDUINO_13__B.caso << 2) +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i];
              PROVA_FINALE_LOAD_ARDUINO_13__B.i++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.c = PROVA_FINALE_LOAD_ARDUINO_13__B.p[1]
          - 1;
        PROVA_FINALE_LOAD_ARDUINO_13__B.a[((PROVA_FINALE_LOAD_ARDUINO_13__B.p[1]
          - 1) << 2) + 1] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 1;
        while (PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1 < 5) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.c << 2;
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i =
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.i + 1 < 5) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jy =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jy]
                -=
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
                * PROVA_FINALE_LOAD_ARDUINO_13__B.A
                [(PROVA_FINALE_LOAD_ARDUINO_13__B.caso << 2) +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i];
              PROVA_FINALE_LOAD_ARDUINO_13__B.i++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.c = PROVA_FINALE_LOAD_ARDUINO_13__B.p[2]
          - 1;
        PROVA_FINALE_LOAD_ARDUINO_13__B.a[((PROVA_FINALE_LOAD_ARDUINO_13__B.p[2]
          - 1) << 2) + 2] = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 2;
        while (PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1 < 5) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.c << 2;
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i =
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.i + 1 < 5) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jy =
                PROVA_FINALE_LOAD_ARDUINO_13__B.ATO +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jy]
                -=
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
                * PROVA_FINALE_LOAD_ARDUINO_13__B.A
                [(PROVA_FINALE_LOAD_ARDUINO_13__B.caso << 2) +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i];
              PROVA_FINALE_LOAD_ARDUINO_13__B.i++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.jy = (PROVA_FINALE_LOAD_ARDUINO_13__B.p
          [3] - 1) << 2;
        PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jy + 3]
          = 1.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 3;
        while (PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1 < 5) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13__B.jy +
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso;
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
              != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.i =
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso + 1;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.i + 1 < 5) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
                PROVA_FINALE_LOAD_ARDUINO_13__B.jy +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
                -=
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                * PROVA_FINALE_LOAD_ARDUINO_13__B.A
                [(PROVA_FINALE_LOAD_ARDUINO_13__B.caso << 2) +
                PROVA_FINALE_LOAD_ARDUINO_13__B.i];
              PROVA_FINALE_LOAD_ARDUINO_13__B.i++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
        }

        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 4;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol =
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO << 2;
          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            + 3];
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
              + 3] = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 /
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[15];
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.caso <= 2) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jy =
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso +
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jy]
                -=
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 3] *
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                + 12];
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            + 2];
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
              + 2] = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 /
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[10];
            PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 0;
            while (PROVA_FINALE_LOAD_ARDUINO_13__B.caso <= 1) {
              PROVA_FINALE_LOAD_ARDUINO_13__B.jy =
                PROVA_FINALE_LOAD_ARDUINO_13__B.caso +
                PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol;
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jy]
                -=
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
                + 2] *
                PROVA_FINALE_LOAD_ARDUINO_13__B.A[PROVA_FINALE_LOAD_ARDUINO_13__B.caso
                + 8];
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso++;
            }
          }

          PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
            + 1];
          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
              + 1] = PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 /
              PROVA_FINALE_LOAD_ARDUINO_13__B.A[5];
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              -=
              PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol
              + 1] * PROVA_FINALE_LOAD_ARDUINO_13__B.A[4];
          }

          if (PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              != 0.0) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.jBcol]
              /= PROVA_FINALE_LOAD_ARDUINO_13__B.A[0];
          }
        }

        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1] -
           PROVA_FINALE_LOAD_ARDUINO_13__P.x_g0_Value) *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar +
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[0];
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n -
          PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar;
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn +
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[3];
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn =
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *
          PROVA_FINALE_LOAD_ARDUINO_13__B.Rn + -0.1;
        for (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO < 4;
             PROVA_FINALE_LOAD_ARDUINO_13__B.ATO++) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
            =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.x[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
            - (((PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                 + 4] * PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar +
                 PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO]
                 * PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) +
                PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
                + 8] * PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f) +
               PROVA_FINALE_LOAD_ARDUINO_13__B.a[PROVA_FINALE_LOAD_ARDUINO_13__B.ATO
               + 12] * PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
        }

        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[0] = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[0] -
           PROVA_FINALE_LOAD_ARDUINO_13_DW.x[0]);
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[1] = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[1] -
           PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1]);
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[2] = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[2] -
           PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2]);
        PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[3] = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[3] -
           PROVA_FINALE_LOAD_ARDUINO_13_DW.x[3]);
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[0] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[0];
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[1];
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[2];
        PROVA_FINALE_LOAD_ARDUINO_13_DW.x[3] =
          PROVA_FINALE_LOAD_ARDUINO_13__B.x_new[3];
        PROVA_FINALE_LOAD_ARDUINO_13_DW.cycle_count++;
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.cycle_count > 10.0) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 1;
          exitg1 = true;
        }
      }

      if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[0] < 0.1) &&
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[1] < 0.1) &&
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[2] < 0.1) &&
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.eps[3] < 0.1)) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_f_out =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[0];
        PROVA_FINALE_LOAD_ARDUINO_13__B.x_f_out =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[1];
        PROVA_FINALE_LOAD_ARDUINO_13__B.k_x_out =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[2];
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_c_out =
          PROVA_FINALE_LOAD_ARDUINO_13_DW.x[3];
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_f_out = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.x_f_out = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.k_x_out = 0.0;
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_c_out = 0.0;
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.no_solution =
        PROVA_FINALE_LOAD_ARDUINO_13__B.AL;

      /* End of MATLAB Function: '<S451>/MATLAB Function' */

      /* Product: '<S451>/Multiply' incorporates:
       *  Constant: '<S451>/x_g0'
       *  Gain: '<S451>/Gain'
       *  Sum: '<S451>/Sum1'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk -
         PROVA_FINALE_LOAD_ARDUINO_13__P.x_g0_Value) *
        PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_e0 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut;

      /* Update for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S451>/Constant2'
       */
      PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE +=
        PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_gainval *
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_g;
      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE >=
          PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_UpperSat) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE =
          PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_UpperSat;
      } else {
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE <=
            PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_LowerSat) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE =
            PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_LowerSat;
        }
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach > 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_PrevRese = 1;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_PrevRese = -1;
      } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.trig_approach == 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
    }

    /* End of Outputs for SubSystem: '<S440>/APPROACH' */

    /* Outputs for Enabled SubSystem: '<S440>/FLARE' incorporates:
     *  EnablePort: '<S455>/Enable'
     */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.trig_flare > 0.0) {
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
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2 = exp
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk -
          PROVA_FINALE_LOAD_ARDUINO_13__B.x_f_out) *
         PROVA_FINALE_LOAD_ARDUINO_13__B.k_x_out *
         PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_j) *
        (PROVA_FINALE_LOAD_ARDUINO_13__B.h_f_out -
         PROVA_FINALE_LOAD_ARDUINO_13__B.h_c_out) +
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_c_out;
    }

    /* End of Outputs for SubSystem: '<S440>/FLARE' */

    /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' */
    switch ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.maneuver_selector) {
     case 1:
      /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Constant: '<S440>/Constant2'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA_m =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant2_Value_n3;
      break;

     case 2:
      /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S440>/Abs3'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA_m = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply);
      break;

     default:
      /* MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
       *  Abs: '<S440>/Abs4'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA_m = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2);
      break;
    }

    /* End of MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' */

    /* Update for Memory: '<S440>/Memory5' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory5_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__B.x_f_out;

    /* Update for Memory: '<S440>/Memory1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_l =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_f_out;

    /* Update for Memory: '<S440>/Memory2' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_f =
      PROVA_FINALE_LOAD_ARDUINO_13__B.no_solution;
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem1' */

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S21>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.iflogic,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion3,
     &PROVA_FINALE_LOAD_ARDUINO_13__P.SIUAVuint8_Value,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Val_out_MAV[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.WP_info[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.WP_param[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__P.onboard_control_sensor_presentu[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctionI[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.B_Remaining,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_ld[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_a[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_p[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_h,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.AGAC[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Heading_g,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Throttle,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Heading[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Memory_a,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o14,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Switch1,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o15,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_l,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_g,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_m,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o5[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Gain,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_g,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.h_Home, ((const uint16_T*)
      &PROVA_FINALE_LOAD_ARDUINO_13_10_U16GND),
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o1_j,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o2_f[0],
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3,
     &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o1_j > 0) {
    /* Chart: '<S15>/Chart' */
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c9_PROVA_FINALE_LOAD_ == 0U) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c9_PROVA_FINALE_LOAD_ = 1U;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.Protocol !=
            PROVA_FINALE_LOAD_ARDUINO_13__P.SerialTransmit_Protocol) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.Protocol =
            PROVA_FINALE_LOAD_ARDUINO_13__P.SerialTransmit_Protocol;
        }

        status =
          PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o2_f[PROVA_FINALE_LOAD_ARDUINO_13_DW.i
          - 1];
        MW_Serial_write(PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.port, &status, 1.0,
                        PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.dataSizeInBytes,
                        PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.sendModeEnum,
                        PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.dataType,
                        PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.sendFormatEnum, 2.0,
                        '\x00');
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.i <
            PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o3) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.ATO =
            PROVA_FINALE_LOAD_ARDUINO_13_DW.i + 1;
          if (PROVA_FINALE_LOAD_ARDUINO_13_DW.i + 1 > 255) {
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 255;
          }

          PROVA_FINALE_LOAD_ARDUINO_13_DW.i = (uint8_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.ATO;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      PROVA_FINALE_LOAD_ARDUINO_13_DW.i = 1U;
    }

    /* End of Chart: '<S15>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S1>/Data Tversion' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       42; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
      = PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Tversion' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem2' incorporates:
   *  EnablePort: '<S441>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector > 0.0) {
    /* Gain: '<S542>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_bu *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0];

    /* Gain: '<S543>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_jz *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[1];

    /* MATLAB Function: '<S441>/WAYPOINTS' incorporates:
     *  DataTypeConversion: '<S1>/Data Tversion'
     *  DataTypeConversion: '<S1>/Data Tversion1'
     *  DataTypeConversion: '<S1>/Data Tversion2'
     *  DataTypeConversion: '<S554>/Data Type Conversion1'
     *  Memory: '<S441>/Memory4'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 1;
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput == 6.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.ATO = 0;
    }

    if ((uint8_T)PROVA_FINALE_LOAD_ARDUINO_13__B.GC_info[0] == 3) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput = 1.0;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.long1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar;
      for (PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 0;
           PROVA_FINALE_LOAD_ARDUINO_13__B.AL < 6;
           PROVA_FINALE_LOAD_ARDUINO_13__B.AL++) {
        if (PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbI[PROVA_FINALE_LOAD_ARDUINO_13__B.AL
            + 24] == 1) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput = (real_T)
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL + 1.0;
        }
      }
    }

    PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 23];
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 29];
    PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA =
      PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 35];
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = sin
      ((PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector -
        PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) * 3.1415926535897931 / 180.0 /
       2.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = sin
      ((PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk -
        PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) * 3.1415926535897931 / 180.0 /
       2.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector * 3.1415926535897931 / 180.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n * 3.1415926535897931 / 180.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = PROVA_FINALE_LOAD_ARDUINO_13__B.Rn *
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o *
       PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = rt_atan2d_snf(sqrt
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1), sqrt(1.0 -
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) * 2.0 * 6.378137E+6;
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput > 1.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 1.0) + 23];
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector =
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist =
        PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 1.0) + 29];
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk -
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f, sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 23] *
         3.1415926535897931 / 180.0) * PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 -
        sin(PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f * cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp = sin
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n -
          PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp) * 3.1415926535897931 /
         180.0 / 2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist = sin
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar -
          PROVA_FINALE_LOAD_ARDUINO_13__B.dist) * 3.1415926535897931 / 180.0 /
         2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn *
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist *
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist) +
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist = rt_atan2d_snf(sqrt
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1), sqrt(1.0 -
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) * 2.0 * 6.378137E+6;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk -
         PROVA_FINALE_LOAD_ARDUINO_13_DW.long1) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f, sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector) * cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp) - cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) * (sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f)) * 180.0 /
        3.1415926535897931;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist = 0.0;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector < 0.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 360.0 - fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO == 1) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 1.0) + 23];
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp = sin
        ((PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp -
          PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector) * 3.1415926535897931 /
         180.0 / 2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 1.0) + 29] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut = sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp / 2.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp =
        PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp);
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut =
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp *
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut *
         PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut) +
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_tmp_tmp;
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut = rt_atan2d_snf(sqrt
        (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut), sqrt(1.0 -
        PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut)) * 2.0 * 6.378137E+6;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp, sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.psi_ref_tmp) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f - cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp) * (sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 23] *
         3.1415926535897931 / 180.0) * PROVA_FINALE_LOAD_ARDUINO_13__B.a_fut_tmp))
        * 180.0 / 3.1415926535897931;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = 360.0 - fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f);
      }

      if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput > 1.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f -
           PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector);
      } else {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f - rt_atan2d_snf(sin
            ((PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
              PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 29] -
              PROVA_FINALE_LOAD_ARDUINO_13_DW.long1) * 3.1415926535897931 /
             180.0) * cos(PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4
                          [(int32_T)
                          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput
                          + 23] * 3.1415926535897931 / 180.0), sin
            (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
             PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 23] *
             3.1415926535897931 / 180.0) * cos
            (PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 * 3.1415926535897931 / 180.0)
            - cos(PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
                  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 23] *
                  3.1415926535897931 / 180.0) * sin
            (PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 * 3.1415926535897931 / 180.0) *
            cos((PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
                 PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 29] -
                 PROVA_FINALE_LOAD_ARDUINO_13_DW.long1) * 3.1415926535897931 /
                180.0)) * 180.0 / 3.1415926535897931);
      }
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut = 0.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f = 0.0;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput < 2.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = 0.0;
    } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput == 2.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[24] *
        3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[30] -
         PROVA_FINALE_LOAD_ARDUINO_13_DW.long1) * 3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector - rt_atan2d_snf(sin
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) *
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp, cos
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 * 3.1415926535897931 / 180.0) *
          sin(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) - sin
          (PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 * 3.1415926535897931 / 180.0) *
          PROVA_FINALE_LOAD_ARDUINO_13__B.b_a_tmp * cos
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n)) * 180.0 / 3.1415926535897931);
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0);
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar =
        PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n =
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 1.0) + 29] -
         PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 2.0) + 29]) *
        3.1415926535897931 / 180.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = rt_atan2d_snf(sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn, cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) * sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
         (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput - 1.0) + 23] *
         3.1415926535897931 / 180.0) - sin
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_ar) *
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn * cos
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_n)) * 180.0 / 3.1415926535897931;
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn < 0.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = 360.0 - fabs
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
      }

      PROVA_FINALE_LOAD_ARDUINO_13__B.Rn = fabs
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector -
         PROVA_FINALE_LOAD_ARDUINO_13__B.Rn);
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 10.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 40.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 100;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f > 10.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 50.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 60.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 250;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f > 50.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 90.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 80.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 300;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f > 90.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply_f <= 120.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 120.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 350;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector = 150.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.AL = 400;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 10.0) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 50;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Rn > 10.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 50.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 200;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Rn > 50.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 90.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 300;
    } else if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Rn > 90.0) &&
               (PROVA_FINALE_LOAD_ARDUINO_13__B.Rn <= 120.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 350;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.caso = 400;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13__B.ATO == 1) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 =
        PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion4[(int32_T)
        PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput + 11];
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 15.0) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 25.0;
      }

      if (!(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <= 20.0)) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <= 25.0) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.2;
        } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 <= 30.0) {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.3;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector *= 1.4;
        }
      }

      if (((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist <
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o >
              PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector))) &&
          ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist >
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o >
              PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector))) &&
          (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o <
           PROVA_FINALE_LOAD_ARDUINO_13__B.Al_selector)) {
        if (PROVA_FINALE_LOAD_ARDUINO_13__B.dist_fut >
            PROVA_FINALE_LOAD_ARDUINO_13__B.AL) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput++;
        } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput < 5.0)
        {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput += 2.0;
        } else {
          PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA =
            PROVA_FINALE_LOAD_ARDUINO_13__B.h_ + 0.4;
        }
      }

      PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_m = 0.0;
    } else {
      if (((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist <
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_m == 0.0))) &&
          ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.dist >
              PROVA_FINALE_LOAD_ARDUINO_13__B.caso)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o > 40.0)) ||
           (!(PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_m == 0.0)))) {
        PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA =
          PROVA_FINALE_LOAD_ARDUINO_13__B.h_ + 0.4;
        PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_m = 1.0;
      }
    }

    if ((PROVA_FINALE_LOAD_ARDUINO_13__B.Wp_selector == 0.0) &&
        (PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_bk == 0.0) &&
        (PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA == 0.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA = PROVA_FINALE_LOAD_ARDUINO_13__B.h_
        + 0.3;
    }

    /* End of MATLAB Function: '<S441>/WAYPOINTS' */
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem' incorporates:
   *  EnablePort: '<S439>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Vec_selector > 0.0) {
    /* MATLAB Function: '<S439>/VETTORIALE' incorporates:
     *  DataTypeConversion: '<S554>/Data Type Conversion1'
     *  MATLAB Function: '<S1>/MATLAB Function1'
     *  Memory: '<S439>/Memory1'
     *  Memory: '<S439>/Memory3'
     *  Memory: '<S439>/Memory6'
     */
    if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] !=
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory6_PreviousInput) ||
        (PROVA_FINALE_LOAD_ARDUINO_13__B.modo !=
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput) ||
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] !=
         PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_h)) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.ALT_ref =
        PROVA_FINALE_LOAD_ARDUINO_13__B.h_;
    }

    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4] == 1) {
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_vett =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[9];
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_vett =
        PROVA_FINALE_LOAD_ARDUINO_13_DW.ALT_ref;
    }

    /* Update for Memory: '<S439>/Memory1' incorporates:
     *  MATLAB Function: '<S439>/VETTORIALE'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_h =
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[4];

    /* Update for Memory: '<S439>/Memory3' incorporates:
     *  MATLAB Function: '<S439>/VETTORIALE'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__B.modo;

    /* Update for Memory: '<S439>/Memory6' incorporates:
     *  MATLAB Function: '<S439>/VETTORIALE'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory6_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1];
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem3' incorporates:
   *  EnablePort: '<S442>/Enable'
   */
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector > 0.0) {
    /* Gain: '<S547>/Gain' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_ji *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[0];

    /* MATLAB Function: '<S442>/GO_HOME' incorporates:
     *  Constant: '<S39>/Constant'
     *  Gain: '<S548>/Gain'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = sin((0.0 -
      PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector) * 3.1415926535897931 /
      180.0 / 2.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o = sin((0.0 -
      PROVA_FINALE_LOAD_ARDUINO_13__P.Gain_Gain_gf *
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[1]) * 3.1415926535897931
      / 180.0 / 2.0);
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = cos
      (PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector * 3.1415926535897931 /
       180.0) * (PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o *
                 PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_o) +
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 *
      PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_goHome =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_g;
    if ((rt_atan2d_snf(sqrt(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1), sqrt(1.0 -
           PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) * 2.0 * 6.378137E+6 < 30.0) &&
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.flag == 0.0)) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.flag = 1.0;
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_goHome =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Constant_Value_g + 0.4;
    }

    /* End of MATLAB Function: '<S442>/GO_HOME' */
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem3' */

  /* MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' */
  switch ((int32_T)PROVA_FINALE_LOAD_ARDUINO_13__B.modo) {
   case 1:
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA;
    break;

   case 2:
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_vett;
    break;

   case 3:
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_ref;
    break;

   case 4:
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA_m;
    break;

   default:
    PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector =
      PROVA_FINALE_LOAD_ARDUINO_13__B.h_goHome;
    break;
  }

  /* End of MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' */

  /* Abs: '<S40>/Abs' incorporates:
   *  Sum: '<S40>/Sum1'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 = fabs
    (PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector -
     PROVA_FINALE_LOAD_ARDUINO_13__B.num_254);

  /* Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c23_PROVA_FINALE_LOAD == 0U) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c23_PROVA_FINALE_LOAD = 1U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c23_PROVA_FINALE_LOAD_ARDUIN =
      PROVA_FINALE_LOAD_ARD_IN_Select;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c23_PROVA_FINALE_LOAD_ARDUIN ==
             1) {
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 > 10.0) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c23_PROVA_FINALE_LOAD_ARDUIN =
        PROVA_FINALE_LOAD_ARD_IN_Select;
    }
  } else {
    /* case IN_Select: */
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.num_254 < 10.0) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c23_PROVA_FINALE_LOAD_ARDUIN =
        PROVA_FINALE_LOAD_ARDUI_IN_Hold;
    }
  }

  /* End of Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S576>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion9'
   *  Product: '<S576>/Divide'
   *  Product: '<S576>/Multiply'
   *  Sum: '<S576>/Sum'
   *  Sum: '<S576>/Sum3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    ((PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni_c -
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Amin) /
     PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Sum3_b_tmp *
     PROVA_FINALE_LOAD_ARDUINO_13__B.Ato_selector + (real_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[5]);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_c = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */
  Servo_microseconds_alettoni_beta_3_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_c,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder10_DSTATE);

  /* Sum: '<S578>/Sum' incorporates:
   *  Product: '<S578>/Multiply'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    (PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Long_re *
     PROVA_FINALE_LOAD_ARDUINO_13__B.Sum5);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* Sum: '<S578>/Sum' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.Sum = (int16_T)
    ((PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
      (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) + (int16_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[1]);

  /* S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.Sum,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder4_DSTATE);

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S577>/Constant'
   *  Constant: '<S577>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion10'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   *  Product: '<S577>/Divide'
   *  Product: '<S577>/Multiply'
   *  Sum: '<S577>/Sum'
   *  Sum: '<S577>/Sum1'
   *  Sum: '<S577>/Sum2'
   *  Sum: '<S577>/Sum3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    ((PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2_o -
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin) /
     (PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmax -
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Rmin) * (real_T)
     (PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[6] -
      PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[7]) +
     (real_T)PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack
     [7]);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_j = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */
  Servo_microseconds_timone_beta_3_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_j,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder5_DSTATE);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S579>/Constant1'
   *  DataTypeConversion: '<S10>/Data Type Conversion7'
   *  Product: '<S579>/Divide'
   *  Product: '<S579>/Multiply'
   *  Sum: '<S579>/Sum'
   *  Sum: '<S579>/Sum3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = floor
    ((PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_o -
      PROVA_FINALE_LOAD_ARDUINO_13__P.attuatore_Emin) /
     PROVA_FINALE_LOAD_ARDUINO_13__B.rtb_Sum3_o_tmp *
     PROVA_FINALE_LOAD_ARDUINO_13__B.Go_Home + (real_T)
     PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization.ByteUnpack[3]);
  if (rtIsNaN(PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1) || rtIsInf
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1)) {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = 0.0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 = fmod
      (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_p = (int16_T)
    (PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1 : (int32_T)(int16_T)
     (uint16_T)PROVA_FINALE_LOAD_ARDUINO_13__B.a_g1);

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_p,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder9_DSTATE);

  /* HitCross: '<S250>/Hit  Crossing' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &PROVA_FINALE_LOAD_ARDUI_PrevZCX.HitCrossing_Input_ZCE,
    (PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector -
     PROVA_FINALE_LOAD_ARDUINO_13__P.HitCrossing_Offset));
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.HitCrossing_MODE == 0) {
    if (PROVA_FINALE_LOAD_ARDUINO_13__B.zcEvent != NO_ZCEVENT) {
      /* HitCross: '<S250>/Hit  Crossing' */
      PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing =
        !PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing;
      PROVA_FINALE_LOAD_ARDUINO_13_DW.HitCrossing_MODE = 1;
    } else {
      if (PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing) {
        /* HitCross: '<S250>/Hit  Crossing' */
        PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing =
          ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector !=
              PROVA_FINALE_LOAD_ARDUINO_13__P.HitCrossing_Offset)) &&
           PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing);
      }
    }
  } else {
    /* HitCross: '<S250>/Hit  Crossing' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing =
      ((!(PROVA_FINALE_LOAD_ARDUINO_13__B.Go_home_selector !=
          PROVA_FINALE_LOAD_ARDUINO_13__P.HitCrossing_Offset)) &&
       PROVA_FINALE_LOAD_ARDUINO_13__B.HitCrossing);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<S250>/Hit  Crossing' */

  /* Abs: '<S416>/Abs1' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut = fabs
    (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum3_b);

  /* Outputs for Resettable SubSystem: '<S408>/Resettable Subsystem' */
  PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut = PROVA_F_ResettableSubsystem
    (PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4_n[1],
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.ResettableSubsystem,
     &PROVA_FINALE_LOAD_ARDUINO_13__P.ResettableSubsystem,
     &PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem);

  /* End of Outputs for SubSystem: '<S408>/Resettable Subsystem' */

  /* Outputs for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  PROVA_FINA_EnabledSubsystem(PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4_n[1],
    PROVA_FINALE_LOAD_ARDUINO_13__B.IProdOut,
    &PROVA_FINALE_LOAD_ARDUINO_13__B.num_254,
    &PROVA_FINALE_LOAD_ARDUINO_13__P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S408>/Enabled Subsystem' */

  /* MATLAB Function: '<S410>/MATLAB Function1' */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Tf_not_empty =
    ((!PROVA_FINALE_LOAD_ARDUINO_13_DW.Tf_not_empty) ||
     (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[0] == 1) ||
     (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[1] == 0) ||
     PROVA_FINALE_LOAD_ARDUINO_13_DW.Tf_not_empty);

  /* S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput_c[0],
         &PROVA_FINALE_LOAD_ARDUINO_13__B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S556>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S556>/S-Function Builder */
  Mti_Update_wrapper(&PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder[0],
                     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S554>/Unit Delay' incorporates:
   *  Constant: '<S554>/Constant3'
   */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.UnitDelay_DSTATE =
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant3_Value_ok;

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&PROVA_FINALE_LOAD_ARDUINO_13__P.Constant1_Value_a,
    &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1_h[0],
    &PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o2,
    &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE_l);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory5_PreviousInput_l[0],
         &PROVA_FINALE_LOAD_ARDUINO_13__B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[0] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[0];
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[1] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[1];
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[2] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[2];
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[3] =
    PROVA_FINALE_LOAD_ARDUINO_13__B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (PROVA_FINALE_LOAD_ARDUINO_13__B.i = 0; PROVA_FINALE_LOAD_ARDUINO_13__B.i <
       8; PROVA_FINALE_LOAD_ARDUINO_13__B.i++) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_ic[PROVA_FINALE_LOAD_ARDUINO_13__B.i]
      =
      PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o11[PROVA_FINALE_LOAD_ARDUINO_13__B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

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
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE +=
    (((PROVA_FINALE_LOAD_ARDUINO_13__B.SwitchBumpless2 -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation) *
      PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_Kt_m +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_b *
      PROVA_FINALE_LOAD_ARDUINO_13__P.Ki_becch) +
     (PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation -
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_nu) *
     PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_Kb_k) *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Integrator_gainval;

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
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE_p +=
    (((PROVA_FINALE_LOAD_ARDUINO_13__B.Alettoni -
       PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation_f) *
      PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_Kt +
      PROVA_FINALE_LOAD_ARDUINO_13__B.Gain1_m *
      PROVA_FINALE_LOAD_ARDUINO_13__P.Ki_roll) +
     (PROVA_FINALE_LOAD_ARDUINO_13__B.Saturation_f -
      PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_n3) *
     PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_Kb) *
    PROVA_FINALE_LOAD_ARDUINO_13__P.Integrator_gainval_g;
  if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o > 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_PrevResetState = 1;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o < 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_PrevResetState = -1;
  } else if (PROVA_FINALE_LOAD_ARDUINO_13__B.Sum_o == 0.0) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_PrevResetState = 0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S390>/Integrator' */

  /* Update for DiscreteTransferFcn: '<S304>/Discrete Washout Filter' */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteWashoutFilter_states =
    PROVA_FINALE_LOAD_ARDUINO_13__B.denAccum;

  /* Update for Memory: '<S2>/Memory' */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_n =
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunction_o4;

  /* Update for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

  /* S-Function "Servo_microseconds_alettoni_beta_3_wrapper" Block: <S10>/S-Function Builder10 */
  Servo_microseconds_alettoni_beta_3_Update_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion1_c,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder10_DSTATE);

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<S10>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <S10>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.Sum,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder4_DSTATE);

  /* Update for S-Function (Servo_microseconds_timone_beta_3): '<S10>/S-Function Builder5' */

  /* S-Function "Servo_microseconds_timone_beta_3_wrapper" Block: <S10>/S-Function Builder5 */
  Servo_microseconds_timone_beta_3_Update_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion2_j,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder5_DSTATE);

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<S10>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <S10>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13__B.DataTypeConversion_p,
     &PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder9_DSTATE);

  /* Update for S-Function (Risoluzione_12bit): '<S4>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S4>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper
    (&PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE_n);
}

/* Model step function for TID1 */
void PROVA_FINALE_LOAD_ARDUINO_13_10_step1(void) /* Sample time: [0.04s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  rtb_PulseGenerator = (PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter <
                        PROVA_FINALE_LOAD_ARDUINO_13__P.PulseGenerator_Duty) &&
    (PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter >= 0) ?
    PROVA_FINALE_LOAD_ARDUINO_13__P.PulseGenerator_Amp : 0.0;
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter >=
      PROVA_FINALE_LOAD_ARDUINO_13__P.PulseGenerator_Period - 1.0) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter = 0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter++;
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
  rtb_PulseGenerator = (PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter_c <
                        PROVA_FINALE_LOAD_ARDUINO_13__P.PulseGenerator1_Duty) &&
    (PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter_c >= 0) ?
    PROVA_FINALE_LOAD_ARDUINO_13__P.PulseGenerator1_Amp : 0.0;
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter_c >=
      PROVA_FINALE_LOAD_ARDUINO_13__P.PulseGenerator1_Period - 1.0) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter_c = 0;
  } else {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter_c++;
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
void PROVA_FINALE_LOAD_ARDUINO_13_10_step2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S27>/Add2' incorporates:
   *  Constant: '<S27>/Constant4'
   *  Constant: '<S27>/Constant5'
   *  Memory: '<S27>/Memory2'
   */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput +=
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant4_Value_a +
    PROVA_FINALE_LOAD_ARDUINO_13__P.Constant5_Value_a;

  /* Switch: '<S27>/Switch1' */
  if (PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput >
      PROVA_FINALE_LOAD_ARDUINO_13__P.Switch1_Threshold_c) {
    /* Sum: '<S27>/Add2' incorporates:
     *  Constant: '<S27>/Constant4'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Constant4_Value_a;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* RateTransition: '<S27>/Rate Transition' */
  PROVA_FINALE_LOAD_ARDUINO_13_DW.RateTransition_Buffer0 =
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void PROVA_FINALE_LOAD_ARDUINO_13_10_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PROVA_FINALE_LOAD_ARDUINO_13_M, 0,
                sizeof(RT_MODEL_PROVA_FINALE_LOAD_AR_T));

  /* block I/O */
  (void) memset(((void *) &PROVA_FINALE_LOAD_ARDUINO_13__B), 0,
                sizeof(B_PROVA_FINALE_LOAD_ARDUINO_1_T));

  /* states (dwork) */
  (void) memset((void *)&PROVA_FINALE_LOAD_ARDUINO_13_DW, 0,
                sizeof(DW_PROVA_FINALE_LOAD_ARDUINO__T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    codertarget_arduinobase_inter_T *obj;
    real_T Switch_a;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S556>/S-Function Builder' */

    /* S-Function Block: <S556>/S-Function Builder */
    Mti_Start_wrapper(&PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE);
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem_Reset_ZCE_p =
      UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem_Reset_ZCE_h =
      UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem_Reset_ZCE =
      UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.SampleandHold_Trig_ZCE_h =
      UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.SampleandHold1_Trig_ZCE =
      UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem_o.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;
    PROVA_FINALE_LOAD_ARDUI_PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_f
      = POS_ZCSIG;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput_c[0],
           &PROVA_FINALE_LOAD_ARDUINO_13__P.Memory4_InitialCondition_g[0], 300U *
           sizeof(uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S556>/S-Function Builder' */

    /* S-Function Block: <S556>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S554>/Unit Delay' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.UnitDelay_DSTATE =
      PROVA_FINALE_LOAD_ARDUINO_13__P.UnitDelay_InitialCondition;

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE_l =
            initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory5_PreviousInput_l[i] =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Memory5_InitialCondition_d;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[0] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory1_InitialCondition_b;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_d[1] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory1_InitialCondition_b;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[0] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_o;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[1] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_o;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[2] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_o;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h5[3] =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_o;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput_o =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory3_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_ic[i] =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_at;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_a[i] =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Memory2_InitialCondition_g[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.RateTransition_Buffer0 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S27>/Switch' incorporates:
     *  Memory: '<S27>/Memory1'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory1_InitialCondition_p;

    /* InitializeConditions for Sum: '<S27>/Add' incorporates:
     *  Memory: '<S27>/Memory'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_au;

    /* InitializeConditions for UnitDelay: '<S557>/Delay Input2'
     *
     * Block description for '<S557>/Delay Input2':
     *
     *  Store in Global RAM
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.DelayInput2_DSTATE =
      PROVA_FINALE_LOAD_ARDUINO_13__P.DelayInput2_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S340>/Integrator' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE =
      PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_InitialConditionF;

    /* InitializeConditions for DiscreteIntegrator: '<S390>/Integrator' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_DSTATE_p =
      PROVA_FINALE_LOAD_ARDUINO_13__P.PIDController_InitialConditio_d;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S304>/Discrete Washout Filter' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteWashoutFilter_states =
      PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteWashoutFilter_InitialSt;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_n =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_g;

    /* InitializeConditions for S-Function (Servo_microseconds_alettoni_beta_3): '<S10>/S-Function Builder10' */

    /* S-Function Block: <S10>/S-Function Builder10 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder10_DSTATE =
            initVector[0];
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
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder4_DSTATE = initVector
            [0];
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
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder5_DSTATE = initVector
            [0];
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
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder9_DSTATE = initVector
            [0];
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
          PROVA_FINALE_LOAD_ARDUINO_13_DW.SFunctionBuilder_DSTATE_n =
            initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter = 0;

    /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.clockTickCounter_c = 0;

    /* InitializeConditions for Sum: '<S27>/Add2' incorporates:
     *  Memory: '<S27>/Memory2'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory2_InitialCondition_o;

    /* SystemInitialize for Enabled SubSystem: '<S554>/Execution_loop' */
    /* Start for MATLABSystem: '<S558>/I2C Read12' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.isInitialized = 0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.matlabCodegenIsDeleted = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.SampleTime =
      PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
    obj = &PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.isSetupComplete = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.isInitialized = 1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (PROVA_FINALE_LOAD_ARDUINO_13__B.i2cname, 0);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S558>/I2C Read1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.isInitialized = 0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.matlabCodegenIsDeleted = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.SampleTime =
      PROVA_FINALE_LOAD_ARDUINO_13__P.t_AP;
    obj = &PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.isSetupComplete = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.isInitialized = 1;
    PROVA_FINALE_LOAD_ARDUINO_13__B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (PROVA_FINALE_LOAD_ARDUINO_13__B.i2cname, 0);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S558>/S-Function Builder' incorporates:
     *  Outport: '<S558>/T'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder_o1 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S558>/S-Function Builder1' incorporates:
     *  Outport: '<S558>/p'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.SFunctionBuilder1 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S554>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S554>/MATLAB Function' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.P_ref = 101325.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.rl_up = 300.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S554>/One_time_initialization' */
    One_time_initializatio_Init
      (&PROVA_FINALE_LOAD_ARDUINO_13__B.One_time_initialization,
       &PROVA_FINALE_LOAD_ARDUINO_13_DW.One_time_initialization,
       &PROVA_FINALE_LOAD_ARDUINO_13__P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S554>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S562>/Subsystem1' */
    /* SystemInitialize for Outport: '<S564>/T_0' incorporates:
     *  Inport: '<S564>/T'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.T = PROVA_FINALE_LOAD_ARDUINO_13__P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S562>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S555>/Subsystem2' */
    /* SystemInitialize for MATLAB Function: '<S566>/Create_message' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.end_found = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.start_found = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_k = 0U;
    memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message[0], 0, 80U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S566>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S568>/Memory' */
      PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_l[i] =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_ab;

      /* SystemInitialize for ComplexToRealImag: '<S568>/Complex to Real-Imag' incorporates:
       *  Outport: '<S568>/Outport'
       */
      PROVA_FINALE_LOAD_ARDUINO_13__B.ComplextoRealImag[i] =
        PROVA_FINALE_LOAD_ARDUINO_13__P.Outport_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S566>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S555>/Subsystem2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&PROVA_FINALE_LOAD_ARDUINO_13_DW.riferimenti[0], &tmp[0], sizeof
           (real32_T) << 4U);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_not_empty = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.WP_dbP_AL_not_empty = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.test1 = 0.0;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.counter = 0U;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function4' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Interr_parz = false;
    memset(&PROVA_FINALE_LOAD_ARDUINO_13_DW.message_i[0], 0, 100U * sizeof
           (uint8_T));
    PROVA_FINALE_LOAD_ARDUINO_13_DW.counter_a = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.mess_len = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c9_PROVA_FINALE_LOAD_ = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.i = 0U;

    /* SystemInitialize for Chart: '<S15>/Chart' incorporates:
     *  SubSystem: '<S24>/sendbyte'
     */
    /* Start for MATLABSystem: '<S25>/Serial Transmit' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.matlabCodegenIsDeleted = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.Protocol =
      PROVA_FINALE_LOAD_ARDUINO_13__P.SerialTransmit_Protocol;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.isInitialized = 1;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.port = 2.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.dataSizeInBytes = 1.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.dataType = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.sendModeEnum = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.sendFormatEnum = 0.0;
    Switch_a = rt_roundd_snf(PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.port);
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
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S25>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c23_PROVA_FINALE_LOAD = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c23_PROVA_FINALE_LOAD_ARDUIN = 0;

    /* SystemInitialize for Chart: '<S38>/ STATI' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_AUTOMATICA = 0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c26_PROVA_FINALE_LOAD = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN = 0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.switch_manetta = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.switch_equilibratore = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.switch_alettoni = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.switch_timone = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.modo = 1.0;

    /* SystemInitialize for Enabled SubSystem: '<S408>/Enabled Subsystem' */
    PROVA_EnabledSubsystem_Init(&Switch_a,
      &PROVA_FINALE_LOAD_ARDUINO_13__P.EnabledSubsystem_h);

    /* End of SystemInitialize for SubSystem: '<S408>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S408>/Resettable Subsystem' */
    PR_ResettableSubsystem_Init
      (&PROVA_FINALE_LOAD_ARDUINO_13_DW.ResettableSubsystem,
       &PROVA_FINALE_LOAD_ARDUINO_13__P.ResettableSubsystem);

    /* End of SystemInitialize for SubSystem: '<S408>/Resettable Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S409>/Enabled Subsystem' */
    PROVA_EnabledSubsystem_Init(&PROVA_FINALE_LOAD_ARDUINO_13__B.Switch_l,
      &PROVA_FINALE_LOAD_ARDUINO_13__P.EnabledSubsystem_j);

    /* End of SystemInitialize for SubSystem: '<S409>/Enabled Subsystem' */

    /* SystemInitialize for Resettable SubSystem: '<S409>/Resettable Subsystem' */
    PR_ResettableSubsystem_Init
      (&PROVA_FINALE_LOAD_ARDUINO_13_DW.ResettableSubsystem_o,
       &PROVA_FINALE_LOAD_ARDUINO_13__P.ResettableSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S409>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S410>/MATLAB Function1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Tf_not_empty = false;

    /* SystemInitialize for Enabled SubSystem: '<S432>/Enabled ' */
    /* SystemInitialize for Switch: '<S434>/Switch' incorporates:
     *  Outport: '<S434>/Alarm Safe'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Switch =
      PROVA_FINALE_LOAD_ARDUINO_13__P.AlarmSafe_Y0;

    /* End of SystemInitialize for SubSystem: '<S432>/Enabled ' */

    /* SystemInitialize for Resettable SubSystem: '<S432>/Resettable Subsystem' */
    /* InitializeConditions for Sum: '<S436>/Sum' incorporates:
     *  Memory: '<S436>/Memory'
     */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_h =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S432>/Resettable Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S415>/MATLAB Function1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.alarm = 0.0;

    /* SystemInitialize for Chart: '<S39>/Chart' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c21_PROVA_FINALE_LOAD = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN = 0;

    /* SystemInitialize for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' */
    /* InitializeConditions for Memory: '<S438>/Memory' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory_PreviousInput_i =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory_InitialCondition_a;

    /* InitializeConditions for Memory: '<S438>/Memory1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_o =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory1_InitialCondition;

    /* SystemInitialize for Chart: '<S438>/Chart1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.temporalCounter_i1 = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c1_PROVA_FINALE_LOAD_ = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO = 0;

    /* End of SystemInitialize for SubSystem: '<S39>/DECOLLO AUTOMATICO' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem' */
    /* InitializeConditions for Memory: '<S439>/Memory1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_h =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<S439>/Memory3' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory3_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S439>/Memory6' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory6_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory6_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S439>/VETTORIALE' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.ALT_ref = 0.0;

    /* SystemInitialize for Outport: '<S439>/Out2' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_vett =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem1' */
    /* InitializeConditions for Memory: '<S440>/Memory7' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory7_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S440>/Memory5' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory5_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S440>/Memory1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory1_PreviousInput_l =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory1_InitialCondition_f;

    /* InitializeConditions for Memory: '<S440>/Memory2' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory2_PreviousInput_f =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S440>/ALLINEAMENTO' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_c = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S440>/APPROACH' */
    /* InitializeConditions for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_DSTATE =
      PROVA_FINALE_LOAD_ARDUINO_13__P.DiscreteTimeIntegrator_IC;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* SystemInitialize for MATLAB Function: '<S451>/MATLAB Function' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.x_not_empty = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.x_new_not_empty = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.cycle_count_not_empty = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.eps_not_empty = false;

    /* SystemInitialize for Product: '<S451>/Multiply' incorporates:
     *  Outport: '<S451>/h_ref'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Multiply =
      PROVA_FINALE_LOAD_ARDUINO_13__P.h_ref_Y0;

    /* SystemInitialize for Outport: '<S451>/flare_data' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.x_f_out =
      PROVA_FINALE_LOAD_ARDUINO_13__P.flare_data_Y0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_f_out =
      PROVA_FINALE_LOAD_ARDUINO_13__P.flare_data_Y0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.k_x_out =
      PROVA_FINALE_LOAD_ARDUINO_13__P.flare_data_Y0;
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_c_out =
      PROVA_FINALE_LOAD_ARDUINO_13__P.flare_data_Y0;

    /* SystemInitialize for Outport: '<S451>/landing_abort' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.no_solution =
      PROVA_FINALE_LOAD_ARDUINO_13__P.landing_abort_Y0;

    /* End of SystemInitialize for SubSystem: '<S440>/APPROACH' */

    /* SystemInitialize for Chart: '<S440>/Chart1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_active_c10_PROVA_FINALE_LOAD = 0U;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN = 0;

    /* SystemInitialize for Enabled SubSystem: '<S440>/FLARE' */
    /* SystemInitialize for Sum: '<S455>/Sum2' incorporates:
     *  Outport: '<S455>/h_ref'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Sum2 =
      PROVA_FINALE_LOAD_ARDUINO_13__P.h_ref_Y0_n;

    /* End of SystemInitialize for SubSystem: '<S440>/FLARE' */

    /* SystemInitialize for Triggered SubSystem: '<S440>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S465>/ ' incorporates:
     *  Inport: '<S465>/In'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.In[0] =
      PROVA_FINALE_LOAD_ARDUINO_13__P._Y0_b[0];
    PROVA_FINALE_LOAD_ARDUINO_13__B.In[1] =
      PROVA_FINALE_LOAD_ARDUINO_13__P._Y0_b[1];

    /* End of SystemInitialize for SubSystem: '<S440>/Sample and Hold' */

    /* SystemInitialize for MultiPortSwitch: '<S440>/Switch di selezione  Task - Waypoint navigation4' incorporates:
     *  Outport: '<S440>/QUOTA_AL'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA_m =
      PROVA_FINALE_LOAD_ARDUINO_13__P.QUOTA_AL_Y0;

    /* SystemInitialize for Gain: '<S458>/Gain' incorporates:
     *  Outport: '<S440>/H_LAT'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain =
      PROVA_FINALE_LOAD_ARDUINO_13__P.H_LAT_Y0;

    /* SystemInitialize for Gain: '<S459>/Gain' incorporates:
     *  Outport: '<S440>/H_LONG'
     */
    PROVA_FINALE_LOAD_ARDUINO_13__B.Gain_g =
      PROVA_FINALE_LOAD_ARDUINO_13__P.H_LONG_Y0;

    /* SystemInitialize for Outport: '<S440>/H_ALT' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_Home =
      PROVA_FINALE_LOAD_ARDUINO_13__P.H_ALT_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem2' */
    /* InitializeConditions for Memory: '<S441>/Memory4' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.Memory4_PreviousInput =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Memory4_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S441>/WAYPOINTS' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.flag_m = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.lat1 = 0.0;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.long1 = 0.0;

    /* SystemInitialize for Outport: '<S441>/Out3' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.QUOTA =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Out3_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem3' */
    /* SystemInitialize for MATLAB Function: '<S442>/GO_HOME' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.flag = 0.0;

    /* SystemInitialize for Outport: '<S442>/Out2' */
    PROVA_FINALE_LOAD_ARDUINO_13__B.h_goHome =
      PROVA_FINALE_LOAD_ARDUINO_13__P.Out2_Y0_c;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem3' */

    /* Start for MATLABSystem: '<S555>/Serial Receive1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.matlabCodegenIsDeleted = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.Protocol =
      PROVA_FINALE_LOAD_ARDUINO_13__P.SerialReceive1_Protocol;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.isInitialized = 1;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.DataTypeWidth = 1U;
    if (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.DataTypeWidth > 2047) {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.DataSizeInBytes = (uint16_T)
        (PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S555>/Serial Receive1' */

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_d.matlabCodegenIsDeleted = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_d.isInitialized = 1;
    digitalIOSetup(13, 1);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_b.matlabCodegenIsDeleted = false;
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_b.isInitialized = 1;
    digitalIOSetup(44, 1);
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void PROVA_FINALE_LOAD_ARDUINO_13_10_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S554>/One_time_initialization' */
  One_time_initializatio_Term
    (&PROVA_FINALE_LOAD_ARDUINO_13_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S554>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S554>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S558>/I2C Read12' */
  obj = &PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f;
  if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.matlabCodegenIsDeleted) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.isInitialized == 1) &&
        PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S558>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S558>/I2C Read1' */
  obj = &PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p;
  if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.matlabCodegenIsDeleted) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.isInitialized == 1) &&
        PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S558>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S554>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S555>/Serial Receive1' */
  if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.matlabCodegenIsDeleted) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S555>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S15>/Chart' incorporates:
   *  SubSystem: '<S24>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.matlabCodegenIsDeleted) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S25>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_d.matlabCodegenIsDeleted) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_b.matlabCodegenIsDeleted) {
    PROVA_FINALE_LOAD_ARDUINO_13_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
