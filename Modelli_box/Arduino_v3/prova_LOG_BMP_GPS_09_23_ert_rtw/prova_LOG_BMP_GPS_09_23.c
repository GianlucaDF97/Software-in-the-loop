/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_BMP_GPS_09_23.c
 *
 * Code generated for Simulink model 'prova_LOG_BMP_GPS_09_23'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Apr  4 13:18:27 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_LOG_BMP_GPS_09_23.h"
#include "prova_LOG_BMP_GPS_09_23_private.h"

const uint16_T prova_LOG_BMP_GPS_09_23_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_prova_LOG_BMP_GPS_09_23_T prova_LOG_BMP_GPS_09_23_B;

/* Block states (default storage) */
DW_prova_LOG_BMP_GPS_09_23_T prova_LOG_BMP_GPS_09_23_DW;

/* Real-time model */
static RT_MODEL_prova_LOG_BMP_GPS_09_T prova_LOG_BMP_GPS_09_23_M_;
RT_MODEL_prova_LOG_BMP_GPS_09_T *const prova_LOG_BMP_GPS_09_23_M =
  &prova_LOG_BMP_GPS_09_23_M_;

/* Forward declaration for local functions */
static void prova_LOG_BMP_GPS_09_2_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T prova_LOG_BMP_GPS_0_ifWhileCond(const boolean_T x[100]);
static void prova_LOG_BMP_GPS_09_2_eml_find(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static boolean_T prova_LOG_BMP_GPS_ifWhileCond_m(const boolean_T x[5]);
static void prova_LOG_BMP_GPS_09_eml_find_k(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void prova_LOG_BMP_GPS_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_LOG_BMP_GPS_09_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T prova_LOG_BMP_GPS__copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void prova_LOG_BMP_GPS_09__readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_LOG_BMP_GPS_09_str2double(const char_T s[2]);
static boolean_T prova_LOG_BMP_GPS__copydigits_a(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void prova_LOG_BMP_GPS_0_readfloat_b(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T prova_LOG_BMP_GPS__str2double_n(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T prova_LOG_BMP_GPS_09_isUnitImag(const char_T s[3], int32_T k);
static void prova_LOG_BMP_G_readNonFinite_k(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_LOG_BMP_GPS_copydigits_ap(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T prova_LOG_BMP_GP_copyexponent_o(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void prova_LOG_BMP_GPS__readfloat_bh(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_LOG_BMP_GPS_str2double_nq(const char_T s[3]);
static void prova_LOG_BMP__readNonFinite_k0(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T prova_LOG_BMP_GP_copydigits_apy(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T prova_LOG_BMP_G_copyexponent_om(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void prova_LOG_BMP_GPS_readfloat_bh1(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_LOG_BMP_GP_str2double_nqh(char_T s);
static real_T prova_LOG_BMP_GPS_09_23_hex2dec(const char_T s[2]);
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
void prova_LOG_BMP_GPS_09_23_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(prova_LOG_BMP_GPS_09_23_M, 1));
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
  (prova_LOG_BMP_GPS_09_23_M->Timing.TaskCounters.TID[1])++;
  if ((prova_LOG_BMP_GPS_09_23_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    prova_LOG_BMP_GPS_09_23_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_pro_T *localB,
  DW_One_time_initialization_pr_T *localDW, P_One_time_initialization_pro_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_o_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S40>/I2C Read' */
  localDW->obj_ag.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ag;
  localDW->obj_ag.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ag.isInitialized = 0;
  localDW->obj_ag.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ag.matlabCodegenIsDeleted = false;
  localDW->obj_ag.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_ag;
  localDW->obj_ag.isSetupComplete = false;
  localDW->obj_ag.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ag.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ag.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ag.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read1' */
  localDW->obj_fz.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_fz;
  localDW->obj_fz.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_fz.isInitialized = 0;
  localDW->obj_fz.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_fz.matlabCodegenIsDeleted = false;
  localDW->obj_fz.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_fz;
  localDW->obj_fz.isSetupComplete = false;
  localDW->obj_fz.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_fz.BusSpeed = 100000U;
  varargin_1 = localDW->obj_fz.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_fz.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read2' */
  localDW->obj_f2.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f2;
  localDW->obj_f2.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f2.isInitialized = 0;
  localDW->obj_f2.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f2.matlabCodegenIsDeleted = false;
  localDW->obj_f2.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_f2;
  localDW->obj_f2.isSetupComplete = false;
  localDW->obj_f2.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f2.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f2.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f2.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read3' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read4' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read5' */
  localDW->obj_a.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_a;
  localDW->obj_a.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_a.isInitialized = 0;
  localDW->obj_a.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_a.matlabCodegenIsDeleted = false;
  localDW->obj_a.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_a;
  localDW->obj_a.isSetupComplete = false;
  localDW->obj_a.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_a.BusSpeed = 100000U;
  varargin_1 = localDW->obj_a.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read6' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read7' */
  localDW->obj_ef.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ef;
  localDW->obj_ef.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ef.isInitialized = 0;
  localDW->obj_ef.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ef.matlabCodegenIsDeleted = false;
  localDW->obj_ef.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_ef;
  localDW->obj_ef.isSetupComplete = false;
  localDW->obj_ef.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ef.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ef.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ef.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read8' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  localDW->obj_e.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  localDW->obj_e.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read10' */
  localDW->obj_it.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_it;
  localDW->obj_it.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_it.isInitialized = 0;
  localDW->obj_it.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_it.matlabCodegenIsDeleted = false;
  localDW->obj_it.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_it;
  localDW->obj_it.isSetupComplete = false;
  localDW->obj_it.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_it.BusSpeed = 100000U;
  varargin_1 = localDW->obj_it.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_it.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Read11' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S40>/I2C Write2' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S40>/I2C Read12' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read' incorporates:
   *  Outport: '<S40>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read1' incorporates:
   *  Outport: '<S40>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read2' incorporates:
   *  Outport: '<S40>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read3' incorporates:
   *  Outport: '<S40>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read4' incorporates:
   *  Outport: '<S40>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read5' incorporates:
   *  Outport: '<S40>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read6' incorporates:
   *  Outport: '<S40>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read7' incorporates:
   *  Outport: '<S40>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read8' incorporates:
   *  Outport: '<S40>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read9' incorporates:
   *  Outport: '<S40>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read10' incorporates:
   *  Outport: '<S40>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S40>/I2C Read11' incorporates:
   *  Outport: '<S40>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S40>/Byte Unpack' incorporates:
     *  Outport: '<S40>/pwm_max_min'
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
   *  EnablePort: '<S40>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S40>/I2C Write3' incorporates:
     *  ArithShift: '<S40>/Shift Arithmetic1'
     *  Constant: '<S40>/registro memoria2 '
     *  DataTypeConversion: '<S40>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S40>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S40>/I2C Read' */
    if (localDW->obj_ag.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_ag.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ag.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ag.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S40>/I2C Read' */

    /* MATLABSystem: '<S40>/I2C Read1' */
    if (localDW->obj_fz.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_fz.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_fz.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_fz.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read1' */

    /* MATLABSystem: '<S40>/I2C Read2' */
    if (localDW->obj_f2.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_f2.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f2.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f2.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read2' */

    /* MATLABSystem: '<S40>/I2C Read3' */
    if (localDW->obj_f.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_f.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S40>/I2C Read3' */

    /* MATLABSystem: '<S40>/I2C Read4' */
    if (localDW->obj_p.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_p.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read4' */

    /* MATLABSystem: '<S40>/I2C Read5' */
    if (localDW->obj_a.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_a.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read5' */

    /* MATLABSystem: '<S40>/I2C Read6' */
    if (localDW->obj_k.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_k.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read6' */

    /* MATLABSystem: '<S40>/I2C Read7' */
    if (localDW->obj_ef.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_ef.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ef.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ef.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read7' */

    /* MATLABSystem: '<S40>/I2C Read8' */
    if (localDW->obj_e.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_e.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read8' */

    /* MATLABSystem: '<S40>/I2C Read9' */
    if (localDW->obj.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
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
      /* MATLABSystem: '<S40>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read9' */

    /* MATLABSystem: '<S40>/I2C Read10' */
    if (localDW->obj_it.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_it.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_it.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_it.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read10' */

    /* MATLABSystem: '<S40>/I2C Read11' */
    if (localDW->obj_i.SampleTime != prova_LOG_BMP_GPS_09_23_P.t_AP) {
      localDW->obj_i.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S40>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S40>/I2C Read11' */

    /* MATLABSystem: '<S40>/I2C Write1' incorporates:
     *  Constant: '<S40>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S40>/I2C Write2' incorporates:
     *  Constant: '<S40>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S40>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_i2.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S40>/I2C Read12' */
    if (localDW->obj_m.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_m.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S40>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S40>/Byte Unpack' */

    /* Unpack: <S40>/Byte Unpack */
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
  codertarget_arduinobase_int_o_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S40>/I2C Read' */
  obj = &localDW->obj_ag;
  if (!localDW->obj_ag.matlabCodegenIsDeleted) {
    localDW->obj_ag.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ag.isInitialized == 1) && localDW->obj_ag.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read1' */
  obj = &localDW->obj_fz;
  if (!localDW->obj_fz.matlabCodegenIsDeleted) {
    localDW->obj_fz.matlabCodegenIsDeleted = true;
    if ((localDW->obj_fz.isInitialized == 1) && localDW->obj_fz.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read2' */
  obj = &localDW->obj_f2;
  if (!localDW->obj_f2.matlabCodegenIsDeleted) {
    localDW->obj_f2.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f2.isInitialized == 1) && localDW->obj_f2.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read3' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read4' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read5' */
  obj = &localDW->obj_a;
  if (!localDW->obj_a.matlabCodegenIsDeleted) {
    localDW->obj_a.matlabCodegenIsDeleted = true;
    if ((localDW->obj_a.isInitialized == 1) && localDW->obj_a.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read6' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read7' */
  obj = &localDW->obj_ef;
  if (!localDW->obj_ef.matlabCodegenIsDeleted) {
    localDW->obj_ef.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ef.isInitialized == 1) && localDW->obj_ef.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read8' */
  obj = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read10' */
  obj = &localDW->obj_it;
  if (!localDW->obj_it.matlabCodegenIsDeleted) {
    localDW->obj_it.matlabCodegenIsDeleted = true;
    if ((localDW->obj_it.isInitialized == 1) && localDW->obj_it.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read11' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S40>/I2C Write1' */
  obj_0 = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S40>/I2C Write2' */
  obj_0 = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S40>/I2C Write3' */
  obj_0 = &localDW->obj_i2;
  if (!localDW->obj_i2.matlabCodegenIsDeleted) {
    localDW->obj_i2.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i2.isInitialized == 1) && localDW->obj_i2.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S40>/I2C Read12' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void prova_LOG_BMP_GPS_09_2_find_254(const uint8_T pack[100], real_T
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
static boolean_T prova_LOG_BMP_GPS_0_ifWhileCond(const boolean_T x[100])
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS_09_2_eml_find(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GPS_ifWhileCond_m(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS_09_eml_find_k(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GPS_09_copydigits(char_T s1[4], int32_T *idx,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GPS__copyexponent(char_T s1[4], int32_T *idx,
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

      prova_LOG_BMP_GPS_09_23_B.kexp_l = *k;
      b_k = *k;
      b_success = prova_LOG_BMP_GPS_09_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > prova_LOG_BMP_GPS_09_23_B.kexp_l));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS_09__readfloat(char_T s1[4], int32_T *idx, const
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
            prova_LOG_BMP_GPS_09__readfloat(s1, idx, s, k, false, &isneg,
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
      prova_LOG_BMP_GPS_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_LOG_BMP_GPS_09_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = prova_LOG_BMP_GPS__copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static creal_T prova_LOG_BMP_GPS_09_str2double(const char_T s[2])
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
  prova_LOG_BMP_GPS_09_23_B.ntoread_b = 0;
  prova_LOG_BMP_GPS_09_23_B.k_b = 0;
  while ((prova_LOG_BMP_GPS_09_23_B.k_b + 1 <= 2) && (c[(uint8_T)
          s[prova_LOG_BMP_GPS_09_23_B.k_b] & 127] ||
          (s[prova_LOG_BMP_GPS_09_23_B.k_b] == '\x00'))) {
    prova_LOG_BMP_GPS_09_23_B.k_b++;
  }

  isimag1 = false;
  b_finite = true;
  prova_LOG_BMP_GPS_09_23_B.scanned1_g = 0.0;
  prova_LOG_BMP_GPS_09_23_B.idx_n = 1;
  prova_LOG_BMP_GPS_09_23_B.s1_g[0] = '\x00';
  prova_LOG_BMP_GPS_09_23_B.s1_g[1] = '\x00';
  prova_LOG_BMP_GPS_09_23_B.s1_g[2] = '\x00';
  prova_LOG_BMP_GPS_09_23_B.s1_g[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.k_b + 1 <= 2)) {
    if (s[prova_LOG_BMP_GPS_09_23_B.k_b] == '-') {
      isneg = !isneg;
      prova_LOG_BMP_GPS_09_23_B.k_b++;
    } else if ((s[prova_LOG_BMP_GPS_09_23_B.k_b] == ',') ||
               (s[prova_LOG_BMP_GPS_09_23_B.k_b] == '+') || c[(uint8_T)
               s[prova_LOG_BMP_GPS_09_23_B.k_b] & 127]) {
      prova_LOG_BMP_GPS_09_23_B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  success = (prova_LOG_BMP_GPS_09_23_B.k_b + 1 <= 2);
  if (success && isneg) {
    prova_LOG_BMP_GPS_09_23_B.s1_g[0] = '-';
    prova_LOG_BMP_GPS_09_23_B.idx_n = 2;
  }

  prova_LOG_BMP_GPS_09_23_B.e_k = prova_LOG_BMP_GPS_09_23_B.k_b + 1;
  if (success) {
    if ((prova_LOG_BMP_GPS_09_23_B.k_b + 1 <= 2) &&
        ((s[prova_LOG_BMP_GPS_09_23_B.k_b] == 'j') ||
         (s[prova_LOG_BMP_GPS_09_23_B.k_b] == 'i'))) {
      isimag1 = true;
      prova_LOG_BMP_GPS_09_23_B.e_k = prova_LOG_BMP_GPS_09_23_B.k_b + 2;
      while ((prova_LOG_BMP_GPS_09_23_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] ||
              (s[1] == '\x00') || (s[1] == ','))) {
        prova_LOG_BMP_GPS_09_23_B.e_k = 3;
      }

      if ((prova_LOG_BMP_GPS_09_23_B.e_k <= 2) && (s[1] == '*')) {
        prova_LOG_BMP_GPS_09_23_B.e_k = 3;
        prova_LOG_BMP_GPS_09__readfloat(prova_LOG_BMP_GPS_09_23_B.s1_g,
          &prova_LOG_BMP_GPS_09_23_B.idx_n, s, &prova_LOG_BMP_GPS_09_23_B.e_k,
          false, &isneg, &b_finite, &prova_LOG_BMP_GPS_09_23_B.scanned1_g,
          &unusedU2, &success);
      } else {
        prova_LOG_BMP_GPS_09_23_B.s1_g[prova_LOG_BMP_GPS_09_23_B.idx_n - 1] =
          '1';
        prova_LOG_BMP_GPS_09_23_B.idx_n++;
      }
    } else {
      prova_LOG_BMP_GPS_09_23_B.e_k = prova_LOG_BMP_GPS_09_23_B.k_b + 1;
      prova_LOG_BMP_GPS_readNonFinite(s, &prova_LOG_BMP_GPS_09_23_B.e_k,
        &b_finite, &prova_LOG_BMP_GPS_09_23_B.scanned1_g);
      if (b_finite) {
        success = prova_LOG_BMP_GPS_09_copydigits(prova_LOG_BMP_GPS_09_23_B.s1_g,
          &prova_LOG_BMP_GPS_09_23_B.idx_n, s, &prova_LOG_BMP_GPS_09_23_B.e_k,
          true);
        if (success) {
          success = prova_LOG_BMP_GPS__copyexponent
            (prova_LOG_BMP_GPS_09_23_B.s1_g, &prova_LOG_BMP_GPS_09_23_B.idx_n, s,
             &prova_LOG_BMP_GPS_09_23_B.e_k);
        }
      } else {
        if ((prova_LOG_BMP_GPS_09_23_B.idx_n >= 2) &&
            (prova_LOG_BMP_GPS_09_23_B.s1_g[0] == '-')) {
          prova_LOG_BMP_GPS_09_23_B.idx_n = 1;
          prova_LOG_BMP_GPS_09_23_B.s1_g[0] = ' ';
          prova_LOG_BMP_GPS_09_23_B.scanned1_g =
            -prova_LOG_BMP_GPS_09_23_B.scanned1_g;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.e_k <= 2)) {
        tmp = s[prova_LOG_BMP_GPS_09_23_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          prova_LOG_BMP_GPS_09_23_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((prova_LOG_BMP_GPS_09_23_B.e_k <= 2) &&
          (s[prova_LOG_BMP_GPS_09_23_B.e_k - 1] == '*')) {
        prova_LOG_BMP_GPS_09_23_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.e_k <= 2)) {
          tmp = s[prova_LOG_BMP_GPS_09_23_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            prova_LOG_BMP_GPS_09_23_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (prova_LOG_BMP_GPS_09_23_B.e_k <= 2) {
        tmp = s[prova_LOG_BMP_GPS_09_23_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          prova_LOG_BMP_GPS_09_23_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.e_k <= 2)) {
      tmp = s[prova_LOG_BMP_GPS_09_23_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        prova_LOG_BMP_GPS_09_23_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    prova_LOG_BMP_GPS_09_23_B.ntoread_b = 1;
  }

  if (success && (prova_LOG_BMP_GPS_09_23_B.e_k <= 2)) {
    prova_LOG_BMP_GPS_09_23_B.s1_g[prova_LOG_BMP_GPS_09_23_B.idx_n - 1] = ' ';
    prova_LOG_BMP_GPS_09_23_B.idx_n++;
    prova_LOG_BMP_GPS_09__readfloat(prova_LOG_BMP_GPS_09_23_B.s1_g,
      &prova_LOG_BMP_GPS_09_23_B.idx_n, s, &prova_LOG_BMP_GPS_09_23_B.e_k, true,
      &success, &isneg, &prova_LOG_BMP_GPS_09_23_B.scanned2_m, &unusedU2,
      &c_success);
    if (isneg) {
      prova_LOG_BMP_GPS_09_23_B.ntoread_b++;
    }

    success = (c_success && (prova_LOG_BMP_GPS_09_23_B.e_k > 2) && (isimag1 !=
                success) && unusedU2);
  } else {
    prova_LOG_BMP_GPS_09_23_B.scanned2_m = 0.0;
  }

  if (success) {
    prova_LOG_BMP_GPS_09_23_B.s1_g[prova_LOG_BMP_GPS_09_23_B.idx_n - 1] = '\x00';
    switch (prova_LOG_BMP_GPS_09_23_B.ntoread_b) {
     case 2:
      prova_LOG_BMP_GPS_09_23_B.ntoread_b = sscanf
        (&prova_LOG_BMP_GPS_09_23_B.s1_g[0], "%lf %lf",
         &prova_LOG_BMP_GPS_09_23_B.scanned1_g,
         &prova_LOG_BMP_GPS_09_23_B.scanned2_m);
      if (prova_LOG_BMP_GPS_09_23_B.ntoread_b != 2) {
        prova_LOG_BMP_GPS_09_23_B.scanned1_g = (rtNaN);
        prova_LOG_BMP_GPS_09_23_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      prova_LOG_BMP_GPS_09_23_B.ntoread_b = sscanf
        (&prova_LOG_BMP_GPS_09_23_B.s1_g[0], "%lf",
         &prova_LOG_BMP_GPS_09_23_B.b_scanned1_n);
      if (b_finite) {
        if (prova_LOG_BMP_GPS_09_23_B.ntoread_b == 1) {
          prova_LOG_BMP_GPS_09_23_B.scanned1_g =
            prova_LOG_BMP_GPS_09_23_B.b_scanned1_n;
        } else {
          prova_LOG_BMP_GPS_09_23_B.scanned1_g = (rtNaN);
        }
      } else if (prova_LOG_BMP_GPS_09_23_B.ntoread_b == 1) {
        prova_LOG_BMP_GPS_09_23_B.scanned2_m =
          prova_LOG_BMP_GPS_09_23_B.b_scanned1_n;
      } else {
        prova_LOG_BMP_GPS_09_23_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_LOG_BMP_GPS_09_23_B.scanned2_m;
      x.im = prova_LOG_BMP_GPS_09_23_B.scanned1_g;
    } else {
      x.re = prova_LOG_BMP_GPS_09_23_B.scanned1_g;
      x.im = prova_LOG_BMP_GPS_09_23_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GPS__copydigits_a(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS_0_readfloat_b(char_T s1_data[], int32_T *idx,
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
          prova_LOG_BMP_GPS_0_readfloat_b(s1_data, idx, s_data, k, n, false,
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
        *success = prova_LOG_BMP_GPS__copydigits_a(s1_data, &b_idx, s_data, &h_k,
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
              isneg = prova_LOG_BMP_GPS__copydigits_a(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static creal_T prova_LOG_BMP_GPS__str2double_n(const char_T s_data[], const
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
    prova_LOG_BMP_GPS_09_23_B.ntoread = 0;
    prova_LOG_BMP_GPS_09_23_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.k <= s_size[1])) {
      tmp = s_data[prova_LOG_BMP_GPS_09_23_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        prova_LOG_BMP_GPS_09_23_B.k++;
      } else {
        exitg1 = true;
      }
    }

    prova_LOG_BMP_GPS_09_23_B.s1_size[0] = 1;
    prova_LOG_BMP_GPS_09_23_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    prova_LOG_BMP_GPS_09_23_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= prova_LOG_BMP_GPS_09_23_B.idx) {
      memset(&prova_LOG_BMP_GPS_09_23_B.s1_data[0], 0,
             (prova_LOG_BMP_GPS_09_23_B.idx + 1) * sizeof(char_T));
    }

    prova_LOG_BMP_GPS_09_23_B.idx = 1;
    prova_LOG_BMP_GPS_0_readfloat_b(prova_LOG_BMP_GPS_09_23_B.s1_data,
      &prova_LOG_BMP_GPS_09_23_B.idx, s_data, &prova_LOG_BMP_GPS_09_23_B.k,
      s_size[1], true, &isimag1, &isfinite1, &prova_LOG_BMP_GPS_09_23_B.scanned1,
      &unusedU0, &success);
    if (isfinite1) {
      prova_LOG_BMP_GPS_09_23_B.ntoread = 1;
    }

    if (success) {
      if (prova_LOG_BMP_GPS_09_23_B.k <= s_size[1]) {
        prova_LOG_BMP_GPS_09_23_B.s1_data[prova_LOG_BMP_GPS_09_23_B.idx - 1] =
          ' ';
        prova_LOG_BMP_GPS_09_23_B.idx++;
        prova_LOG_BMP_GPS_0_readfloat_b(prova_LOG_BMP_GPS_09_23_B.s1_data,
          &prova_LOG_BMP_GPS_09_23_B.idx, s_data, &prova_LOG_BMP_GPS_09_23_B.k,
          s_size[1], true, &unusedU0, &success,
          &prova_LOG_BMP_GPS_09_23_B.scanned2, &foundsign, &c_success);
        if (success) {
          prova_LOG_BMP_GPS_09_23_B.ntoread++;
        }

        success = (c_success && ((prova_LOG_BMP_GPS_09_23_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        prova_LOG_BMP_GPS_09_23_B.scanned2 = 0.0;
      }
    } else {
      prova_LOG_BMP_GPS_09_23_B.scanned2 = 0.0;
    }

    if (success) {
      prova_LOG_BMP_GPS_09_23_B.s1_data[prova_LOG_BMP_GPS_09_23_B.idx - 1] =
        '\x00';
      switch (prova_LOG_BMP_GPS_09_23_B.ntoread) {
       case 2:
        prova_LOG_BMP_GPS_09_23_B.ntoread = sscanf
          (&prova_LOG_BMP_GPS_09_23_B.s1_data[0], "%lf %lf",
           &prova_LOG_BMP_GPS_09_23_B.scanned1,
           &prova_LOG_BMP_GPS_09_23_B.scanned2);
        if (prova_LOG_BMP_GPS_09_23_B.ntoread != 2) {
          prova_LOG_BMP_GPS_09_23_B.scanned1 = (rtNaN);
          prova_LOG_BMP_GPS_09_23_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        prova_LOG_BMP_GPS_09_23_B.ntoread = sscanf
          (&prova_LOG_BMP_GPS_09_23_B.s1_data[0], "%lf",
           &prova_LOG_BMP_GPS_09_23_B.b_scanned1);
        if (isfinite1) {
          if (prova_LOG_BMP_GPS_09_23_B.ntoread == 1) {
            prova_LOG_BMP_GPS_09_23_B.scanned1 =
              prova_LOG_BMP_GPS_09_23_B.b_scanned1;
          } else {
            prova_LOG_BMP_GPS_09_23_B.scanned1 = (rtNaN);
          }
        } else if (prova_LOG_BMP_GPS_09_23_B.ntoread == 1) {
          prova_LOG_BMP_GPS_09_23_B.scanned2 =
            prova_LOG_BMP_GPS_09_23_B.b_scanned1;
        } else {
          prova_LOG_BMP_GPS_09_23_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = prova_LOG_BMP_GPS_09_23_B.scanned2;
        x.im = prova_LOG_BMP_GPS_09_23_B.scanned1;
      } else {
        x.re = prova_LOG_BMP_GPS_09_23_B.scanned1;
        x.im = prova_LOG_BMP_GPS_09_23_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GPS_09_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_G_readNonFinite_k(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GPS_copydigits_ap(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GP_copyexponent_o(char_T s1[5], int32_T *idx,
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

      prova_LOG_BMP_GPS_09_23_B.kexp = *k;
      b_k = *k;
      b_success = prova_LOG_BMP_GPS_copydigits_ap(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > prova_LOG_BMP_GPS_09_23_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS__readfloat_bh(char_T s1[5], int32_T *idx, const
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
    if (prova_LOG_BMP_GPS_09_isUnitImag(s, b_k)) {
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
          prova_LOG_BMP_GPS__readfloat_bh(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      prova_LOG_BMP_G_readNonFinite_k(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_LOG_BMP_GPS_copydigits_ap(s1, idx, s, k, true);
        if (*success) {
          *success = prova_LOG_BMP_GP_copyexponent_o(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static creal_T prova_LOG_BMP_GPS_str2double_nq(const char_T s[3])
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
  prova_LOG_BMP_GPS_09_23_B.ntoread_o = 0;
  prova_LOG_BMP_GPS_09_23_B.k_d = 1;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.k_d <= 3)) {
    tmp = s[prova_LOG_BMP_GPS_09_23_B.k_d - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      prova_LOG_BMP_GPS_09_23_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  prova_LOG_BMP_GPS_09_23_B.scanned1_c = 0.0;
  prova_LOG_BMP_GPS_09_23_B.idx_l = 1;
  for (prova_LOG_BMP_GPS_09_23_B.b_k = 0; prova_LOG_BMP_GPS_09_23_B.b_k < 5;
       prova_LOG_BMP_GPS_09_23_B.b_k++) {
    prova_LOG_BMP_GPS_09_23_B.s1[prova_LOG_BMP_GPS_09_23_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.k_d <= 3)) {
    tmp = s[prova_LOG_BMP_GPS_09_23_B.k_d - 1];
    if (tmp == '-') {
      isneg = !isneg;
      prova_LOG_BMP_GPS_09_23_B.k_d++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      prova_LOG_BMP_GPS_09_23_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  success = (prova_LOG_BMP_GPS_09_23_B.k_d <= 3);
  if (success && isneg) {
    prova_LOG_BMP_GPS_09_23_B.s1[0] = '-';
    prova_LOG_BMP_GPS_09_23_B.idx_l = 2;
  }

  prova_LOG_BMP_GPS_09_23_B.b_k = prova_LOG_BMP_GPS_09_23_B.k_d - 1;
  if (success) {
    if (prova_LOG_BMP_GPS_09_isUnitImag(s, prova_LOG_BMP_GPS_09_23_B.k_d)) {
      isimag1 = true;
      prova_LOG_BMP_GPS_09_23_B.b_k = prova_LOG_BMP_GPS_09_23_B.k_d;
      while ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[prova_LOG_BMP_GPS_09_23_B.b_k] & 127] ||
              (s[prova_LOG_BMP_GPS_09_23_B.b_k] == '\x00') ||
              (s[prova_LOG_BMP_GPS_09_23_B.b_k] == ','))) {
        prova_LOG_BMP_GPS_09_23_B.b_k++;
      }

      if ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) &&
          (s[prova_LOG_BMP_GPS_09_23_B.b_k] == '*')) {
        prova_LOG_BMP_GPS_09_23_B.k_d = prova_LOG_BMP_GPS_09_23_B.b_k + 2;
        prova_LOG_BMP_GPS__readfloat_bh(prova_LOG_BMP_GPS_09_23_B.s1,
          &prova_LOG_BMP_GPS_09_23_B.idx_l, s, &prova_LOG_BMP_GPS_09_23_B.k_d,
          false, &isneg, &b_finite, &prova_LOG_BMP_GPS_09_23_B.scanned1_c,
          &unusedU2, &success);
        prova_LOG_BMP_GPS_09_23_B.b_k = prova_LOG_BMP_GPS_09_23_B.k_d - 1;
      } else {
        prova_LOG_BMP_GPS_09_23_B.s1[prova_LOG_BMP_GPS_09_23_B.idx_l - 1] = '1';
        prova_LOG_BMP_GPS_09_23_B.idx_l++;
      }
    } else {
      prova_LOG_BMP_G_readNonFinite_k(s, &prova_LOG_BMP_GPS_09_23_B.k_d,
        &b_finite, &prova_LOG_BMP_GPS_09_23_B.scanned1_c);
      prova_LOG_BMP_GPS_09_23_B.b_k = prova_LOG_BMP_GPS_09_23_B.k_d - 1;
      if (b_finite) {
        success = prova_LOG_BMP_GPS_copydigits_ap(prova_LOG_BMP_GPS_09_23_B.s1,
          &prova_LOG_BMP_GPS_09_23_B.idx_l, s, &prova_LOG_BMP_GPS_09_23_B.k_d,
          true);
        prova_LOG_BMP_GPS_09_23_B.b_k = prova_LOG_BMP_GPS_09_23_B.k_d - 1;
        if (success) {
          success = prova_LOG_BMP_GP_copyexponent_o(prova_LOG_BMP_GPS_09_23_B.s1,
            &prova_LOG_BMP_GPS_09_23_B.idx_l, s, &prova_LOG_BMP_GPS_09_23_B.k_d);
          prova_LOG_BMP_GPS_09_23_B.b_k = prova_LOG_BMP_GPS_09_23_B.k_d - 1;
        }
      } else {
        if ((prova_LOG_BMP_GPS_09_23_B.idx_l >= 2) &&
            (prova_LOG_BMP_GPS_09_23_B.s1[0] == '-')) {
          prova_LOG_BMP_GPS_09_23_B.idx_l = 1;
          prova_LOG_BMP_GPS_09_23_B.s1[0] = ' ';
          prova_LOG_BMP_GPS_09_23_B.scanned1_c =
            -prova_LOG_BMP_GPS_09_23_B.scanned1_c;
        }
      }

      while ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[prova_LOG_BMP_GPS_09_23_B.b_k] & 127] ||
              (s[prova_LOG_BMP_GPS_09_23_B.b_k] == '\x00') ||
              (s[prova_LOG_BMP_GPS_09_23_B.b_k] == ','))) {
        prova_LOG_BMP_GPS_09_23_B.b_k++;
      }

      if ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) &&
          (s[prova_LOG_BMP_GPS_09_23_B.b_k] == '*')) {
        prova_LOG_BMP_GPS_09_23_B.b_k++;
        while ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[prova_LOG_BMP_GPS_09_23_B.b_k] & 127] ||
                (s[prova_LOG_BMP_GPS_09_23_B.b_k] == '\x00') ||
                (s[prova_LOG_BMP_GPS_09_23_B.b_k] == ','))) {
          prova_LOG_BMP_GPS_09_23_B.b_k++;
        }
      }

      if ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) &&
          ((s[prova_LOG_BMP_GPS_09_23_B.b_k] == 'i') ||
           (s[prova_LOG_BMP_GPS_09_23_B.b_k] == 'j'))) {
        prova_LOG_BMP_GPS_09_23_B.b_k++;
        isimag1 = true;
      }
    }

    while ((prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[prova_LOG_BMP_GPS_09_23_B.b_k] & 127] ||
            (s[prova_LOG_BMP_GPS_09_23_B.b_k] == '\x00') ||
            (s[prova_LOG_BMP_GPS_09_23_B.b_k] == ','))) {
      prova_LOG_BMP_GPS_09_23_B.b_k++;
    }
  }

  if (b_finite) {
    prova_LOG_BMP_GPS_09_23_B.ntoread_o = 1;
  }

  if (success && (prova_LOG_BMP_GPS_09_23_B.b_k + 1 <= 3)) {
    prova_LOG_BMP_GPS_09_23_B.s1[prova_LOG_BMP_GPS_09_23_B.idx_l - 1] = ' ';
    prova_LOG_BMP_GPS_09_23_B.idx_l++;
    prova_LOG_BMP_GPS_09_23_B.k_d = prova_LOG_BMP_GPS_09_23_B.b_k + 1;
    prova_LOG_BMP_GPS__readfloat_bh(prova_LOG_BMP_GPS_09_23_B.s1,
      &prova_LOG_BMP_GPS_09_23_B.idx_l, s, &prova_LOG_BMP_GPS_09_23_B.k_d, true,
      &success, &isneg, &prova_LOG_BMP_GPS_09_23_B.scanned2_f, &unusedU2,
      &c_success);
    if (isneg) {
      prova_LOG_BMP_GPS_09_23_B.ntoread_o++;
    }

    success = (c_success && (prova_LOG_BMP_GPS_09_23_B.k_d > 3) && (isimag1 !=
                success) && unusedU2);
  } else {
    prova_LOG_BMP_GPS_09_23_B.scanned2_f = 0.0;
  }

  if (success) {
    prova_LOG_BMP_GPS_09_23_B.s1[prova_LOG_BMP_GPS_09_23_B.idx_l - 1] = '\x00';
    switch (prova_LOG_BMP_GPS_09_23_B.ntoread_o) {
     case 2:
      prova_LOG_BMP_GPS_09_23_B.ntoread_o = sscanf
        (&prova_LOG_BMP_GPS_09_23_B.s1[0], "%lf %lf",
         &prova_LOG_BMP_GPS_09_23_B.scanned1_c,
         &prova_LOG_BMP_GPS_09_23_B.scanned2_f);
      if (prova_LOG_BMP_GPS_09_23_B.ntoread_o != 2) {
        prova_LOG_BMP_GPS_09_23_B.scanned1_c = (rtNaN);
        prova_LOG_BMP_GPS_09_23_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      prova_LOG_BMP_GPS_09_23_B.ntoread_o = sscanf
        (&prova_LOG_BMP_GPS_09_23_B.s1[0], "%lf",
         &prova_LOG_BMP_GPS_09_23_B.b_scanned1_g);
      if (b_finite) {
        if (prova_LOG_BMP_GPS_09_23_B.ntoread_o == 1) {
          prova_LOG_BMP_GPS_09_23_B.scanned1_c =
            prova_LOG_BMP_GPS_09_23_B.b_scanned1_g;
        } else {
          prova_LOG_BMP_GPS_09_23_B.scanned1_c = (rtNaN);
        }
      } else if (prova_LOG_BMP_GPS_09_23_B.ntoread_o == 1) {
        prova_LOG_BMP_GPS_09_23_B.scanned2_f =
          prova_LOG_BMP_GPS_09_23_B.b_scanned1_g;
      } else {
        prova_LOG_BMP_GPS_09_23_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_LOG_BMP_GPS_09_23_B.scanned2_f;
      x.im = prova_LOG_BMP_GPS_09_23_B.scanned1_c;
    } else {
      x.re = prova_LOG_BMP_GPS_09_23_B.scanned1_c;
      x.im = prova_LOG_BMP_GPS_09_23_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP__readNonFinite_k0(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_GP_copydigits_apy(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static boolean_T prova_LOG_BMP_G_copyexponent_om(char_T s1[3], int32_T *idx,
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
    b_success = prova_LOG_BMP_GP_copydigits_apy(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static void prova_LOG_BMP_GPS_readfloat_bh1(char_T s1[3], int32_T *idx, char_T s,
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
          prova_LOG_BMP_GPS_readfloat_bh1(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      prova_LOG_BMP__readNonFinite_k0(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = prova_LOG_BMP_GP_copydigits_apy(s1, idx, s, k, true);
        if (*success) {
          *success = prova_LOG_BMP_G_copyexponent_om(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static creal_T prova_LOG_BMP_GP_str2double_nqh(char_T s)
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
  prova_LOG_BMP_GPS_09_23_B.ntoread_bn = 0;
  prova_LOG_BMP_GPS_09_23_B.d_k = 1;
  prova_LOG_BMP_GPS_09_23_B.i_d = (uint8_T)s & 127;
  if (c[prova_LOG_BMP_GPS_09_23_B.i_d] || (s == '\x00')) {
    prova_LOG_BMP_GPS_09_23_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  prova_LOG_BMP_GPS_09_23_B.scanned1_p = 0.0;
  prova_LOG_BMP_GPS_09_23_B.idx_h = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      prova_LOG_BMP_GPS_09_23_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[prova_LOG_BMP_GPS_09_23_B.i_d]) {
      prova_LOG_BMP_GPS_09_23_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (prova_LOG_BMP_GPS_09_23_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    prova_LOG_BMP_GPS_09_23_B.idx_h = 2;
  }

  if (success) {
    isneg = false;
    if (prova_LOG_BMP_GPS_09_23_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      prova_LOG_BMP_GPS_09_23_B.d_k++;
      s1[prova_LOG_BMP_GPS_09_23_B.idx_h - 1] = '1';
      prova_LOG_BMP_GPS_09_23_B.idx_h++;
    } else {
      prova_LOG_BMP__readNonFinite_k0(s, &prova_LOG_BMP_GPS_09_23_B.d_k,
        &b_finite, &prova_LOG_BMP_GPS_09_23_B.scanned1_p);
      if (b_finite) {
        success = prova_LOG_BMP_GP_copydigits_apy(s1,
          &prova_LOG_BMP_GPS_09_23_B.idx_h, s, &prova_LOG_BMP_GPS_09_23_B.d_k,
          true);
        if (success) {
          success = prova_LOG_BMP_G_copyexponent_om(s1,
            &prova_LOG_BMP_GPS_09_23_B.idx_h, s, &prova_LOG_BMP_GPS_09_23_B.d_k);
        }
      } else {
        if ((prova_LOG_BMP_GPS_09_23_B.idx_h >= 2) && (s1[0] == '-')) {
          prova_LOG_BMP_GPS_09_23_B.idx_h = 1;
          s1[0] = ' ';
          prova_LOG_BMP_GPS_09_23_B.scanned1_p =
            -prova_LOG_BMP_GPS_09_23_B.scanned1_p;
        }
      }

      while ((prova_LOG_BMP_GPS_09_23_B.d_k <= 1) &&
             (c[prova_LOG_BMP_GPS_09_23_B.i_d] || ((s == '\x00') || (s == ','))))
      {
        prova_LOG_BMP_GPS_09_23_B.d_k = 2;
      }

      if ((prova_LOG_BMP_GPS_09_23_B.d_k <= 1) && (s == '*')) {
        prova_LOG_BMP_GPS_09_23_B.d_k = 2;
      }

      if ((prova_LOG_BMP_GPS_09_23_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        prova_LOG_BMP_GPS_09_23_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((prova_LOG_BMP_GPS_09_23_B.d_k <= 1) &&
           (c[prova_LOG_BMP_GPS_09_23_B.i_d] || ((s == '\x00') || (s == ','))))
    {
      prova_LOG_BMP_GPS_09_23_B.d_k = 2;
    }
  }

  if (b_finite) {
    prova_LOG_BMP_GPS_09_23_B.ntoread_bn = 1;
  }

  if (success && (prova_LOG_BMP_GPS_09_23_B.d_k <= 1)) {
    s1[prova_LOG_BMP_GPS_09_23_B.idx_h - 1] = ' ';
    prova_LOG_BMP_GPS_09_23_B.idx_h++;
    prova_LOG_BMP_GPS_09_23_B.d_k = 1;
    prova_LOG_BMP_GPS_readfloat_bh1(s1, &prova_LOG_BMP_GPS_09_23_B.idx_h, s,
      &prova_LOG_BMP_GPS_09_23_B.d_k, true, &success, &isneg,
      &prova_LOG_BMP_GPS_09_23_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      prova_LOG_BMP_GPS_09_23_B.ntoread_bn++;
    }

    success = (c_success && (prova_LOG_BMP_GPS_09_23_B.d_k > 1) && (isimag1 !=
                success) && foundsign);
  } else {
    prova_LOG_BMP_GPS_09_23_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[prova_LOG_BMP_GPS_09_23_B.idx_h - 1] = '\x00';
    switch (prova_LOG_BMP_GPS_09_23_B.ntoread_bn) {
     case 2:
      prova_LOG_BMP_GPS_09_23_B.ntoread_bn = sscanf(&s1[0], "%lf %lf",
        &prova_LOG_BMP_GPS_09_23_B.scanned1_p,
        &prova_LOG_BMP_GPS_09_23_B.scanned2_l);
      if (prova_LOG_BMP_GPS_09_23_B.ntoread_bn != 2) {
        prova_LOG_BMP_GPS_09_23_B.scanned1_p = (rtNaN);
        prova_LOG_BMP_GPS_09_23_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      prova_LOG_BMP_GPS_09_23_B.ntoread_bn = sscanf(&s1[0], "%lf",
        &prova_LOG_BMP_GPS_09_23_B.b_scanned1_j);
      if (b_finite) {
        if (prova_LOG_BMP_GPS_09_23_B.ntoread_bn == 1) {
          prova_LOG_BMP_GPS_09_23_B.scanned1_p =
            prova_LOG_BMP_GPS_09_23_B.b_scanned1_j;
        } else {
          prova_LOG_BMP_GPS_09_23_B.scanned1_p = (rtNaN);
        }
      } else if (prova_LOG_BMP_GPS_09_23_B.ntoread_bn == 1) {
        prova_LOG_BMP_GPS_09_23_B.scanned2_l =
          prova_LOG_BMP_GPS_09_23_B.b_scanned1_j;
      } else {
        prova_LOG_BMP_GPS_09_23_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_LOG_BMP_GPS_09_23_B.scanned2_l;
      x.im = prova_LOG_BMP_GPS_09_23_B.scanned1_p;
    } else {
      x.re = prova_LOG_BMP_GPS_09_23_B.scanned1_p;
      x.im = prova_LOG_BMP_GPS_09_23_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S26>/MATLAB Function' */
static real_T prova_LOG_BMP_GPS_09_23_hex2dec(const char_T s[2])
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

  prova_LOG_BMP_GPS_09_23_B.a = tmp_0;
  prova_LOG_BMP_GPS_09_23_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U],
                      2);
      tmp = tmp_2;
      MultiWordSub(&prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &prova_LOG_BMP_GPS_09_23_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U],
                      2);
      tmp = tmp_3;
      MultiWordSub(&prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &prova_LOG_BMP_GPS_09_23_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U],
                        2);
        tmp = tmp_4;
        MultiWordSub(&prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &prova_LOG_BMP_GPS_09_23_B.sk.chunks[0U], 2);
      } else {
        prova_LOG_BMP_GPS_09_23_B.sk = tmp_0;
      }
    } else {
      prova_LOG_BMP_GPS_09_23_B.sk = tmp_0;
    }

    uMultiWordMul(&prova_LOG_BMP_GPS_09_23_B.sk.chunks[0U], 2,
                  &prova_LOG_BMP_GPS_09_23_B.p16.chunks[0U], 2,
                  &prova_LOG_BMP_GPS_09_23_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&prova_LOG_BMP_GPS_09_23_B.r.chunks[0U], 4,
                         &prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U], 2);
    MultiWordAdd(&prova_LOG_BMP_GPS_09_23_B.a.chunks[0U],
                 &prova_LOG_BMP_GPS_09_23_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    prova_LOG_BMP_GPS_09_23_B.a = tmp;
    uMultiWord2MultiWord(&prova_LOG_BMP_GPS_09_23_B.p16.chunks[0U], 2,
                         &prova_LOG_BMP_GPS_09_23_B.r2.chunks[0U], 3);
    uMultiWordShl(&prova_LOG_BMP_GPS_09_23_B.r2.chunks[0U], 3, 4U,
                  &prova_LOG_BMP_GPS_09_23_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&prova_LOG_BMP_GPS_09_23_B.r1.chunks[0U], 3,
                         &prova_LOG_BMP_GPS_09_23_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&prova_LOG_BMP_GPS_09_23_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&prova_LOG_BMP_GPS_09_23_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&prova_LOG_BMP_GPS_09_23_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&prova_LOG_BMP_GPS_09_23_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&prova_LOG_BMP_GPS_09_23_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&prova_LOG_BMP_GPS_09_23_B.a.chunks[0U], 2, 0);
  }

  return x;
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
void prova_LOG_BMP_GPS_09_23_step0(void) /* Sample time: [0.02s, 0.0s] */
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  int32_T exitg3;
  char_T ck_ric[2];
  char_T messaggio;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T output_raw[2];
  uint8_T rtb_H_mav[2];
  uint8_T counter;
  uint8_T find_comma;
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
  Seriale_mav_Outputs_wrapper(&prova_LOG_BMP_GPS_09_23_P.Constant1_Value_i,
    &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[0],
    &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2,
    &prova_LOG_BMP_GPS_09_23_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  prova_LOG_BMP_GPS_09_23_B.status = 0;
  prova_LOG_BMP_GPS_09_23_B.caso = 0;
  memset(&prova_LOG_BMP_GPS_09_23_B.messaggio_d[0], 0, 100U * sizeof(uint8_T));
  memset(&prova_LOG_BMP_GPS_09_23_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  prova_LOG_BMP_GPS_09_2_find_254
    (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g,
     prova_LOG_BMP_GPS_09_23_B.poss_254, &prova_LOG_BMP_GPS_09_23_B.num_254);
  if (prova_LOG_BMP_GPS_09_23_DW.Interr_parz &&
      (prova_LOG_BMP_GPS_09_23_B.num_254 == 1.0)) {
    prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
      (prova_LOG_BMP_GPS_09_23_DW.counter_o + 1U);
    if (prova_LOG_BMP_GPS_09_23_DW.counter_o + 1U > 255U) {
      prova_LOG_BMP_GPS_09_23_B.f_l = 255;
    }

    if (prova_LOG_BMP_GPS_09_23_B.poss_254[0] != prova_LOG_BMP_GPS_09_23_B.f_l)
    {
      prova_LOG_BMP_GPS_09_23_B.num_254 = 0.0;
    }
  }

  y = !prova_LOG_BMP_GPS_09_23_DW.Interr_parz;
  if ((prova_LOG_BMP_GPS_09_23_B.num_254 == 1.0) && y) {
    prova_LOG_BMP_GPS_09_23_B.caso = 1;
  } else if ((prova_LOG_BMP_GPS_09_23_B.num_254 == 0.0) &&
             prova_LOG_BMP_GPS_09_23_DW.Interr_parz) {
    prova_LOG_BMP_GPS_09_23_B.caso = 2;
  } else if ((prova_LOG_BMP_GPS_09_23_B.num_254 == 1.0) &&
             prova_LOG_BMP_GPS_09_23_DW.Interr_parz) {
    prova_LOG_BMP_GPS_09_23_B.caso = 3;
  } else {
    if ((prova_LOG_BMP_GPS_09_23_B.num_254 == 2.0) && y) {
      prova_LOG_BMP_GPS_09_23_B.caso = 4;
    }
  }

  switch (prova_LOG_BMP_GPS_09_23_B.caso) {
   case 1:
    prova_LOG_BMP_GPS_09_23_B.RateTransition =
      prova_LOG_BMP_GPS_09_23_B.poss_254[(int32_T)
      prova_LOG_BMP_GPS_09_23_B.num_254 - 1];
    if (prova_LOG_BMP_GPS_09_23_B.RateTransition == 100.0) {
      prova_LOG_BMP_GPS_09_23_DW.message_k[0] =
        prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[99];
      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = true;
    } else if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
               (prova_LOG_BMP_GPS_09_23_B.RateTransition + 1.0) - 1] <= 100) {
      prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
        (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
         (prova_LOG_BMP_GPS_09_23_B.poss_254[0] + 1.0) - 1] + 8U);
      prova_LOG_BMP_GPS_09_23_B.i = prova_LOG_BMP_GPS_09_23_B.f_l;
      if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
        prova_LOG_BMP_GPS_09_23_B.i = 255;
      }

      if (prova_LOG_BMP_GPS_09_23_B.i ==
          prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2) {
        prova_LOG_BMP_GPS_09_23_B.UkYk1 = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.RateTransition);
        if (prova_LOG_BMP_GPS_09_23_B.UkYk1 < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.UkYk1 >= 0.0) {
            counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.UkYk1;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
          (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
           (prova_LOG_BMP_GPS_09_23_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
          prova_LOG_BMP_GPS_09_23_B.f_l = 255;
        }

        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.RateTransition + (real_T)
           prova_LOG_BMP_GPS_09_23_B.f_l);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          prova_LOG_BMP_GPS_09_23_B.i = 0;
          prova_LOG_BMP_GPS_09_23_B.f_l = 0;
        } else {
          prova_LOG_BMP_GPS_09_23_B.i = counter - 1;
          prova_LOG_BMP_GPS_09_23_B.f_l = find_comma;
        }

        prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.f_l -
          prova_LOG_BMP_GPS_09_23_B.i;
        for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
             prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.f_l] =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.i
            + prova_LOG_BMP_GPS_09_23_B.f_l];
        }

        prova_LOG_BMP_GPS_09_23_B.status = 1;
        for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 100;
             prova_LOG_BMP_GPS_09_23_B.i++) {
          prova_LOG_BMP_GPS_09_23_B.messaggio_d[prova_LOG_BMP_GPS_09_23_B.i] =
            prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i];
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i] = 0U;
        }

        prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
        prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
          prova_LOG_BMP_GPS_09_23_B.f_l = 255;
        }

        if (prova_LOG_BMP_GPS_09_23_B.f_l >
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2) {
          prova_LOG_BMP_GPS_09_23_DW.mess_len =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2;
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >
              prova_LOG_BMP_GPS_09_23_DW.mess_len) {
            prova_LOG_BMP_GPS_09_23_B.i = 0;
            prova_LOG_BMP_GPS_09_23_B.f_l = 0;
          } else {
            prova_LOG_BMP_GPS_09_23_B.i = (int32_T)
              prova_LOG_BMP_GPS_09_23_B.RateTransition - 1;
            prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
              prova_LOG_BMP_GPS_09_23_DW.mess_len;
          }

          prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.f_l -
            prova_LOG_BMP_GPS_09_23_B.i;
          for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
               prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++)
          {
            prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.f_l] =
              prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.i
              + prova_LOG_BMP_GPS_09_23_B.f_l];
          }

          prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
            (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
             (prova_LOG_BMP_GPS_09_23_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
            prova_LOG_BMP_GPS_09_23_B.f_l = 255;
          }

          prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf((real_T)
            prova_LOG_BMP_GPS_09_23_B.f_l - prova_LOG_BMP_GPS_09_23_DW.mess_len);
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
            if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
              prova_LOG_BMP_GPS_09_23_DW.counter_o = (uint8_T)
                prova_LOG_BMP_GPS_09_23_B.RateTransition;
            } else {
              prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
            }
          } else {
            prova_LOG_BMP_GPS_09_23_DW.counter_o = MAX_uint8_T;
          }

          prova_LOG_BMP_GPS_09_23_DW.Interr_parz = true;
        }
      }
    } else {
      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_BMP_GPS_09_23_DW.message_k[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
      prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
      prova_LOG_BMP_GPS_09_23_B.status = 1;
    }
    break;

   case 2:
    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.x[prova_LOG_BMP_GPS_09_23_B.f_l] =
        (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.f_l]
         != 0);
    }

    if (prova_LOG_BMP_GPS_0_ifWhileCond(prova_LOG_BMP_GPS_09_23_B.x)) {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
        (prova_LOG_BMP_GPS_09_23_DW.mess_len + 1.0);
      if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
        (prova_LOG_BMP_GPS_09_23_DW.mess_len + (real_T)
         prova_LOG_BMP_GPS_09_23_DW.counter_o);
      if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
          counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (find_comma > counter) {
        prova_LOG_BMP_GPS_09_23_B.status = 1;
      } else {
        prova_LOG_BMP_GPS_09_23_B.status = find_comma;
      }

      if (1 > prova_LOG_BMP_GPS_09_23_DW.counter_o) {
        prova_LOG_BMP_GPS_09_23_B.caso = -1;
      } else {
        prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_DW.counter_o -
          1;
      }

      for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <=
           prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
        prova_LOG_BMP_GPS_09_23_DW.message_k[(prova_LOG_BMP_GPS_09_23_B.status +
          prova_LOG_BMP_GPS_09_23_B.f_l) - 1] =
          prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.f_l];
      }

      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
      prova_LOG_BMP_GPS_09_23_B.status = 1;
      for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 100;
           prova_LOG_BMP_GPS_09_23_B.i++) {
        prova_LOG_BMP_GPS_09_23_B.messaggio_d[prova_LOG_BMP_GPS_09_23_B.i] =
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i];
        prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i] = 0U;
      }

      prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
      prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
    } else {
      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
      prova_LOG_BMP_GPS_09_23_B.status = 1;
      memset(&prova_LOG_BMP_GPS_09_23_DW.message_k[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
      prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
    }
    break;

   case 3:
    prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
      (prova_LOG_BMP_GPS_09_23_DW.mess_len + 1.0);
    if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
      if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
        find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
      (prova_LOG_BMP_GPS_09_23_DW.mess_len + (real_T)
       prova_LOG_BMP_GPS_09_23_DW.counter_o);
    if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
      if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
        counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (find_comma > counter) {
      prova_LOG_BMP_GPS_09_23_B.i = 1;
    } else {
      prova_LOG_BMP_GPS_09_23_B.i = find_comma;
    }

    if (1 > prova_LOG_BMP_GPS_09_23_DW.counter_o) {
      prova_LOG_BMP_GPS_09_23_B.caso = -1;
    } else {
      prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_DW.counter_o - 1;
    }

    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <=
         prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_DW.message_k[(prova_LOG_BMP_GPS_09_23_B.i +
        prova_LOG_BMP_GPS_09_23_B.f_l) - 1] =
        prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.f_l];
    }

    prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
    prova_LOG_BMP_GPS_09_23_B.status = 1;
    for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 100;
         prova_LOG_BMP_GPS_09_23_B.i++) {
      prova_LOG_BMP_GPS_09_23_B.messaggio_d[prova_LOG_BMP_GPS_09_23_B.i] =
        prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i];
      prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i] = 0U;
    }

    prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
    prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
    prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
      (prova_LOG_BMP_GPS_09_23_B.poss_254[(int32_T)
       prova_LOG_BMP_GPS_09_23_B.num_254 - 1] + 1.0) - 1;
    if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.f_l]
        <= 100) {
      prova_LOG_BMP_GPS_09_23_B.i = (int32_T)
        (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
         (prova_LOG_BMP_GPS_09_23_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.i > 255U) {
        prova_LOG_BMP_GPS_09_23_B.i = 255;
      }

      prova_LOG_BMP_GPS_09_23_B.caso =
        prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2;
      if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2 < 0) {
        prova_LOG_BMP_GPS_09_23_B.caso = 0;
      } else {
        if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2 > 255) {
          prova_LOG_BMP_GPS_09_23_B.caso = 255;
        }
      }

      if (prova_LOG_BMP_GPS_09_23_B.i == prova_LOG_BMP_GPS_09_23_B.caso) {
        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.poss_254[(int32_T)
           prova_LOG_BMP_GPS_09_23_B.num_254 - 1]);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
            counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
          (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.f_l]
           + 7U);
        if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
          prova_LOG_BMP_GPS_09_23_B.f_l = 255;
        }

        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.poss_254[(int32_T)
           prova_LOG_BMP_GPS_09_23_B.num_254 - 1] + (real_T)
           prova_LOG_BMP_GPS_09_23_B.f_l);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          prova_LOG_BMP_GPS_09_23_B.i = 0;
          prova_LOG_BMP_GPS_09_23_B.f_l = 0;
        } else {
          prova_LOG_BMP_GPS_09_23_B.i = counter - 1;
          prova_LOG_BMP_GPS_09_23_B.f_l = find_comma;
        }

        prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.f_l -
          prova_LOG_BMP_GPS_09_23_B.i;
        for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
             prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.f_l] =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.i
            + prova_LOG_BMP_GPS_09_23_B.f_l];
        }

        for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 100;
             prova_LOG_BMP_GPS_09_23_B.i++) {
          prova_LOG_BMP_GPS_09_23_B.messaggio_2[prova_LOG_BMP_GPS_09_23_B.i] =
            prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i];
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i] = 0U;
        }

        prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
        prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
      } else {
        prova_LOG_BMP_GPS_09_23_B.i = (int32_T)
          (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
           (prova_LOG_BMP_GPS_09_23_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.i > 255U) {
          prova_LOG_BMP_GPS_09_23_B.i = 255;
        }

        prova_LOG_BMP_GPS_09_23_B.caso =
          prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2;
        if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2 < 0) {
          prova_LOG_BMP_GPS_09_23_B.caso = 0;
        } else {
          if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2 > 255) {
            prova_LOG_BMP_GPS_09_23_B.caso = 255;
          }
        }

        if (prova_LOG_BMP_GPS_09_23_B.i > prova_LOG_BMP_GPS_09_23_B.caso) {
          prova_LOG_BMP_GPS_09_23_DW.mess_len =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2;
          if (prova_LOG_BMP_GPS_09_23_B.poss_254[(int32_T)
              prova_LOG_BMP_GPS_09_23_B.num_254 - 1] >
              prova_LOG_BMP_GPS_09_23_DW.mess_len) {
            prova_LOG_BMP_GPS_09_23_B.x_d = 0;
            prova_LOG_BMP_GPS_09_23_B.caso = 0;
          } else {
            prova_LOG_BMP_GPS_09_23_B.x_d = (int32_T)
              prova_LOG_BMP_GPS_09_23_B.poss_254[(int32_T)
              prova_LOG_BMP_GPS_09_23_B.num_254 - 1] - 1;
            prova_LOG_BMP_GPS_09_23_B.caso = (int32_T)
              prova_LOG_BMP_GPS_09_23_DW.mess_len;
          }

          prova_LOG_BMP_GPS_09_23_B.caso -= prova_LOG_BMP_GPS_09_23_B.x_d;
          for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i <
               prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.i++) {
            prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i] =
              prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.x_d
              + prova_LOG_BMP_GPS_09_23_B.i];
          }

          prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
            (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.f_l]
             + 8U);
          if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
            prova_LOG_BMP_GPS_09_23_B.f_l = 255;
          }

          prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf((real_T)
            prova_LOG_BMP_GPS_09_23_B.f_l - prova_LOG_BMP_GPS_09_23_DW.mess_len);
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
            if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
              prova_LOG_BMP_GPS_09_23_DW.counter_o = (uint8_T)
                prova_LOG_BMP_GPS_09_23_B.RateTransition;
            } else {
              prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
            }
          } else {
            prova_LOG_BMP_GPS_09_23_DW.counter_o = MAX_uint8_T;
          }

          prova_LOG_BMP_GPS_09_23_DW.Interr_parz = true;
        }
      }
    } else {
      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_BMP_GPS_09_23_B.messaggio_d[0], 0, 100U * sizeof(uint8_T));
      memset(&prova_LOG_BMP_GPS_09_23_DW.message_k[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
      prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
        (prova_LOG_BMP_GPS_09_23_B.poss_254[0] + 1.0) - 1] <= 100) {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
        (prova_LOG_BMP_GPS_09_23_B.poss_254[0]);
      if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
          counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
        (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
         (prova_LOG_BMP_GPS_09_23_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
        prova_LOG_BMP_GPS_09_23_B.f_l = 255;
      }

      prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
        (prova_LOG_BMP_GPS_09_23_B.poss_254[0] + (real_T)
         prova_LOG_BMP_GPS_09_23_B.f_l);
      if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (counter > find_comma) {
        prova_LOG_BMP_GPS_09_23_B.status = 0;
        prova_LOG_BMP_GPS_09_23_B.f_l = 0;
      } else {
        prova_LOG_BMP_GPS_09_23_B.status = counter - 1;
        prova_LOG_BMP_GPS_09_23_B.f_l = find_comma;
      }

      prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.f_l -
        prova_LOG_BMP_GPS_09_23_B.status;
      for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
           prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
        prova_LOG_BMP_GPS_09_23_B.messaggio_d[prova_LOG_BMP_GPS_09_23_B.f_l] =
          prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.status
          + prova_LOG_BMP_GPS_09_23_B.f_l];
      }
    } else {
      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_BMP_GPS_09_23_DW.message_k[0], 0, 100U * sizeof(uint8_T));
    }

    prova_LOG_BMP_GPS_09_23_B.status = 1;
    if ((prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
         (prova_LOG_BMP_GPS_09_23_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (prova_LOG_BMP_GPS_09_23_B.poss_254[1] -
         prova_LOG_BMP_GPS_09_23_B.poss_254[0] > 3.0)) {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf((real_T)
        prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2 -
        prova_LOG_BMP_GPS_09_23_B.poss_254[1]);
      prova_LOG_BMP_GPS_09_23_B.qY =
        prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[(int32_T)
        (prova_LOG_BMP_GPS_09_23_B.poss_254[1] + 1.0) - 1];
      prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)(prova_LOG_BMP_GPS_09_23_B.qY +
        7U);
      if (prova_LOG_BMP_GPS_09_23_B.qY + 7U > 255U) {
        prova_LOG_BMP_GPS_09_23_B.f_l = 255;
      }

      if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 2.147483648E+9) {
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= -2.147483648E+9) {
          prova_LOG_BMP_GPS_09_23_B.i = (int32_T)
            prova_LOG_BMP_GPS_09_23_B.RateTransition;
        } else {
          prova_LOG_BMP_GPS_09_23_B.i = MIN_int32_T;
        }
      } else {
        prova_LOG_BMP_GPS_09_23_B.i = MAX_int32_T;
      }

      if (prova_LOG_BMP_GPS_09_23_B.i == prova_LOG_BMP_GPS_09_23_B.f_l) {
        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.poss_254[1]);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
            counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)(prova_LOG_BMP_GPS_09_23_B.qY +
          7U);
        if (prova_LOG_BMP_GPS_09_23_B.qY + 7U > 255U) {
          prova_LOG_BMP_GPS_09_23_B.f_l = 255;
        }

        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.poss_254[1] + (real_T)
           prova_LOG_BMP_GPS_09_23_B.f_l);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          prova_LOG_BMP_GPS_09_23_B.status = 0;
          prova_LOG_BMP_GPS_09_23_B.f_l = 0;
        } else {
          prova_LOG_BMP_GPS_09_23_B.status = counter - 1;
          prova_LOG_BMP_GPS_09_23_B.f_l = find_comma;
        }

        prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.f_l -
          prova_LOG_BMP_GPS_09_23_B.status;
        for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
             prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.f_l] =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.status
            + prova_LOG_BMP_GPS_09_23_B.f_l];
        }

        prova_LOG_BMP_GPS_09_23_B.status = 2;
        for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 100;
             prova_LOG_BMP_GPS_09_23_B.i++) {
          prova_LOG_BMP_GPS_09_23_B.messaggio_2[prova_LOG_BMP_GPS_09_23_B.i] =
            prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i];
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.i] = 0U;
        }

        prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
        prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
      } else {
        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf
          (prova_LOG_BMP_GPS_09_23_B.poss_254[1]);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 2.147483648E+9) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= -2.147483648E+9) {
            prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
              prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            prova_LOG_BMP_GPS_09_23_B.f_l = MIN_int32_T;
          }
        } else {
          prova_LOG_BMP_GPS_09_23_B.f_l = MAX_int32_T;
        }

        if (prova_LOG_BMP_GPS_09_23_B.f_l >
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2) {
          prova_LOG_BMP_GPS_09_23_B.f_l = -1;
          prova_LOG_BMP_GPS_09_23_B.caso = 0;
        } else {
          prova_LOG_BMP_GPS_09_23_B.f_l -= 2;
          prova_LOG_BMP_GPS_09_23_B.caso =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2;
        }

        prova_LOG_BMP_GPS_09_23_DW.mess_len = (int8_T)
          ((prova_LOG_BMP_GPS_09_23_B.caso - prova_LOG_BMP_GPS_09_23_B.f_l) - 1);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 2.147483648E+9) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= -2.147483648E+9) {
            prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
              prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            prova_LOG_BMP_GPS_09_23_B.f_l = MIN_int32_T;
          }
        } else {
          prova_LOG_BMP_GPS_09_23_B.f_l = MAX_int32_T;
        }

        if (prova_LOG_BMP_GPS_09_23_B.f_l >
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2) {
          prova_LOG_BMP_GPS_09_23_B.i = 0;
          prova_LOG_BMP_GPS_09_23_B.f_l = 0;
        } else {
          prova_LOG_BMP_GPS_09_23_B.i = prova_LOG_BMP_GPS_09_23_B.f_l - 1;
          prova_LOG_BMP_GPS_09_23_B.f_l =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2;
        }

        prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.f_l -
          prova_LOG_BMP_GPS_09_23_B.i;
        for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
             prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
          prova_LOG_BMP_GPS_09_23_DW.message_k[prova_LOG_BMP_GPS_09_23_B.f_l] =
            prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[prova_LOG_BMP_GPS_09_23_B.i
            + prova_LOG_BMP_GPS_09_23_B.f_l];
        }

        prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)(prova_LOG_BMP_GPS_09_23_B.qY +
          8U);
        if (prova_LOG_BMP_GPS_09_23_B.qY + 8U > 255U) {
          prova_LOG_BMP_GPS_09_23_B.f_l = 255;
        }

        prova_LOG_BMP_GPS_09_23_B.RateTransition = rt_roundd_snf((real_T)
          prova_LOG_BMP_GPS_09_23_B.f_l - prova_LOG_BMP_GPS_09_23_DW.mess_len);
        if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 256.0) {
          if (prova_LOG_BMP_GPS_09_23_B.RateTransition >= 0.0) {
            prova_LOG_BMP_GPS_09_23_DW.counter_o = (uint8_T)
              prova_LOG_BMP_GPS_09_23_B.RateTransition;
          } else {
            prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
          }
        } else {
          prova_LOG_BMP_GPS_09_23_DW.counter_o = MAX_uint8_T;
        }

        prova_LOG_BMP_GPS_09_23_DW.Interr_parz = true;
      }
    } else {
      prova_LOG_BMP_GPS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_BMP_GPS_09_23_DW.message_k[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_BMP_GPS_09_23_DW.counter_o = 0U;
      prova_LOG_BMP_GPS_09_23_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&prova_LOG_BMP_GPS_09_23_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
       prova_LOG_BMP_GPS_09_23_B.f_l++) {
    prova_LOG_BMP_GPS_09_23_B.buffer[3 * prova_LOG_BMP_GPS_09_23_B.f_l] = 0U;
  }

  for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
       prova_LOG_BMP_GPS_09_23_B.f_l++) {
    for (prova_LOG_BMP_GPS_09_23_B.caso = 0; prova_LOG_BMP_GPS_09_23_B.caso < 2;
         prova_LOG_BMP_GPS_09_23_B.caso++) {
      prova_LOG_BMP_GPS_09_23_B.i = 3 * prova_LOG_BMP_GPS_09_23_B.f_l +
        prova_LOG_BMP_GPS_09_23_B.caso;
      prova_LOG_BMP_GPS_09_23_B.buffer[prova_LOG_BMP_GPS_09_23_B.i + 1] =
        prova_LOG_BMP_GPS_09_23_DW.Memory4_PreviousInput[prova_LOG_BMP_GPS_09_23_B.i];
    }
  }

  prova_LOG_BMP_GPS_09_23_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.i >= 1)) {
    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.x[prova_LOG_BMP_GPS_09_23_B.f_l] =
        (prova_LOG_BMP_GPS_09_23_B.buffer[(3 * prova_LOG_BMP_GPS_09_23_B.f_l +
          prova_LOG_BMP_GPS_09_23_B.i) - 1] == 0);
    }

    y = true;
    prova_LOG_BMP_GPS_09_23_B.f_l = 0;
    exitg2 = false;
    while ((!exitg2) && (prova_LOG_BMP_GPS_09_23_B.f_l < 100)) {
      if (!prova_LOG_BMP_GPS_09_23_B.x[prova_LOG_BMP_GPS_09_23_B.f_l]) {
        y = false;
        exitg2 = true;
      } else {
        prova_LOG_BMP_GPS_09_23_B.f_l++;
      }
    }

    if (y) {
      counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.i;
      exitg1 = true;
    } else {
      prova_LOG_BMP_GPS_09_23_B.i--;
    }
  }

  if (prova_LOG_BMP_GPS_09_23_B.status == 1) {
    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.buffer[(counter + 3 *
        prova_LOG_BMP_GPS_09_23_B.f_l) - 1] =
        prova_LOG_BMP_GPS_09_23_B.messaggio_d[prova_LOG_BMP_GPS_09_23_B.f_l];
    }
  } else if (prova_LOG_BMP_GPS_09_23_B.status == 2) {
    prova_LOG_BMP_GPS_09_23_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      prova_LOG_BMP_GPS_09_23_B.qY = 0U;
    }

    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.buffer[(counter + 3 *
        prova_LOG_BMP_GPS_09_23_B.f_l) - 1] =
        prova_LOG_BMP_GPS_09_23_B.messaggio_d[prova_LOG_BMP_GPS_09_23_B.f_l];
      prova_LOG_BMP_GPS_09_23_B.buffer[((int32_T)prova_LOG_BMP_GPS_09_23_B.qY +
        3 * prova_LOG_BMP_GPS_09_23_B.f_l) - 1] =
        prova_LOG_BMP_GPS_09_23_B.messaggio_2[prova_LOG_BMP_GPS_09_23_B.f_l];
    }
  } else {
    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.buffer[(counter + 3 *
        prova_LOG_BMP_GPS_09_23_B.f_l) - 1] = 0U;
    }
  }

  for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
       prova_LOG_BMP_GPS_09_23_B.f_l++) {
    prova_LOG_BMP_GPS_09_23_B.mess_out[prova_LOG_BMP_GPS_09_23_B.f_l] =
      prova_LOG_BMP_GPS_09_23_DW.Memory4_PreviousInput[3 *
      prova_LOG_BMP_GPS_09_23_B.f_l + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  prova_LOG_BMP_GPS_09_23_B.Add =
    prova_LOG_BMP_GPS_09_23_DW.Memory4_PreviousInput[5] +
    prova_LOG_BMP_GPS_09_23_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (prova_LOG_BMP_GPS_09_23_B.mess_out[2] !=
      prova_LOG_BMP_GPS_09_23_DW.Memory5_PreviousInput[2]) {
    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 100;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.x[prova_LOG_BMP_GPS_09_23_B.f_l] =
        (prova_LOG_BMP_GPS_09_23_B.mess_out[prova_LOG_BMP_GPS_09_23_B.f_l] != 0);
    }

    y = true;
    prova_LOG_BMP_GPS_09_23_B.f_l = 0;
    exitg1 = false;
    while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.f_l < 100)) {
      if (!prova_LOG_BMP_GPS_09_23_B.x[prova_LOG_BMP_GPS_09_23_B.f_l]) {
        y = false;
        exitg1 = true;
      } else {
        prova_LOG_BMP_GPS_09_23_B.f_l++;
      }
    }

    if (!y) {
      if (prova_LOG_BMP_GPS_09_23_DW.counter > 100) {
        prova_LOG_BMP_GPS_09_23_DW.counter = 0U;
      }

      prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_DW.counter + 1U;
      if (prova_LOG_BMP_GPS_09_23_DW.counter + 1U > 65535U) {
        prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
      }

      prova_LOG_BMP_GPS_09_23_DW.counter = (uint16_T)
        prova_LOG_BMP_GPS_09_23_B.qY;
    }
  }

  prova_LOG_BMP_GPS_09_23_B.new_mex = prova_LOG_BMP_GPS_09_23_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  prova_LOG_BMP_GPS_09_23_B.Memory1[0] =
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0];
  prova_LOG_BMP_GPS_09_23_B.Memory1[1] =
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1];

  /* Memory: '<Root>/Memory' */
  prova_LOG_BMP_GPS_09_23_B.Memory_c[0] =
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[0];
  prova_LOG_BMP_GPS_09_23_B.Memory_c[1] =
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[1];
  prova_LOG_BMP_GPS_09_23_B.Memory_c[2] =
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[2];
  prova_LOG_BMP_GPS_09_23_B.Memory_c[3] =
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[3];

  /* Memory: '<S1>/Memory3' */
  prova_LOG_BMP_GPS_09_23_B.Memory3 =
    prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput;
  for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 8;
       prova_LOG_BMP_GPS_09_23_B.i++) {
    /* Memory: '<S1>/Memory' */
    prova_LOG_BMP_GPS_09_23_B.Memory[prova_LOG_BMP_GPS_09_23_B.i] =
      prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_c[prova_LOG_BMP_GPS_09_23_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&prova_LOG_BMP_GPS_09_23_B.mess_out[0], &prova_LOG_BMP_GPS_09_23_B.Add,
     &prova_LOG_BMP_GPS_09_23_B.new_mex,
     &prova_LOG_BMP_GPS_09_23_P.SIUAVuint8_Value,
     &prova_LOG_BMP_GPS_09_23_B.Memory[0], &prova_LOG_BMP_GPS_09_23_B.Memory1[0],
     &prova_LOG_BMP_GPS_09_23_B.Memory_c[0], &prova_LOG_BMP_GPS_09_23_B.Memory3,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o1[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o2,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o4_b[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o5[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o6,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o7[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o8,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o9[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o10[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o11[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o12,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o13,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o14,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o15,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o16,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 9;
       prova_LOG_BMP_GPS_09_23_B.i++) {
    prova_LOG_BMP_GPS_09_23_B.Memory2[prova_LOG_BMP_GPS_09_23_B.i] =
      prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[prova_LOG_BMP_GPS_09_23_B.i];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 6;
       prova_LOG_BMP_GPS_09_23_B.i++) {
    prova_LOG_BMP_GPS_09_23_B.WP_info_in[prova_LOG_BMP_GPS_09_23_B.i] =
      prova_LOG_BMP_GPS_09_23_B.SFunction_o9[prova_LOG_BMP_GPS_09_23_B.i];
  }

  if ((!prova_LOG_BMP_GPS_09_23_DW.WP_dbP_not_empty) ||
      ((prova_LOG_BMP_GPS_09_23_B.SFunction_o7[0] == 3) &&
       (prova_LOG_BMP_GPS_09_23_B.SFunction_o7[1] == 250))) {
    memset(&prova_LOG_BMP_GPS_09_23_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    prova_LOG_BMP_GPS_09_23_DW.WP_dbP_not_empty = true;
    memset(&prova_LOG_BMP_GPS_09_23_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!prova_LOG_BMP_GPS_09_23_DW.WP_dbP_AL_not_empty) ||
      ((prova_LOG_BMP_GPS_09_23_B.SFunction_o7[0] == 3) &&
       (prova_LOG_BMP_GPS_09_23_B.SFunction_o7[1] == 250))) {
    memset(&prova_LOG_BMP_GPS_09_23_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    prova_LOG_BMP_GPS_09_23_DW.WP_dbP_AL_not_empty = true;
  }

  prova_LOG_BMP_GPS_09_23_B.GC_info[0] = prova_LOG_BMP_GPS_09_23_B.SFunction_o7
    [0];
  prova_LOG_BMP_GPS_09_23_B.GC_info[1] = prova_LOG_BMP_GPS_09_23_B.SFunction_o7
    [1];
  prova_LOG_BMP_GPS_09_23_B.GC_info[2] =
    prova_LOG_BMP_GPS_09_23_B.SFunction_o11[0];
  if (prova_LOG_BMP_GPS_09_23_B.GC_info[0] == 1) {
    if ((prova_LOG_BMP_GPS_09_23_B.GC_info[1] > 0) &&
        (prova_LOG_BMP_GPS_09_23_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(prova_LOG_BMP_GPS_09_23_B.SFunction_o8) > 0.0F) {
        prova_LOG_BMP_GPS_09_23_DW.riferimenti[prova_LOG_BMP_GPS_09_23_B.GC_info[
          1] - 1] = 1.0F;
      } else {
        if (prova_LOG_BMP_GPS_09_23_B.SFunction_o8 == 0.0F) {
          prova_LOG_BMP_GPS_09_23_DW.riferimenti[prova_LOG_BMP_GPS_09_23_B.GC_info
            [1] - 1] = 0.0F;
        }
      }
    } else {
      if ((prova_LOG_BMP_GPS_09_23_B.GC_info[1] > 7) &&
          (prova_LOG_BMP_GPS_09_23_B.GC_info[1] < 12)) {
        prova_LOG_BMP_GPS_09_23_DW.riferimenti[prova_LOG_BMP_GPS_09_23_B.GC_info[
          1] - 1] = prova_LOG_BMP_GPS_09_23_B.SFunction_o8;
      }
    }
  }

  if (prova_LOG_BMP_GPS_09_23_B.SFunction_o12 == 13) {
    prova_LOG_BMP_GPS_09_23_DW.riferimenti[prova_LOG_BMP_GPS_09_23_B.SFunction_o12
      - 1] = prova_LOG_BMP_GPS_09_23_B.SFunction_o13;
  }

  memcpy(&prova_LOG_BMP_GPS_09_23_B.Val_out_MAV[0],
         &prova_LOG_BMP_GPS_09_23_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((prova_LOG_BMP_GPS_09_23_B.GC_info[0] == 3) &&
      (prova_LOG_BMP_GPS_09_23_B.GC_info[1] == 200)) {
    if (prova_LOG_BMP_GPS_09_23_B.SFunction_o9[0] > 6) {
      prova_LOG_BMP_GPS_09_23_B.WP_info_in[0] = 6U;
    }

    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 6;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_DW.WP_dbI[prova_LOG_BMP_GPS_09_23_B.f_l] =
        prova_LOG_BMP_GPS_09_23_B.WP_info_in[0];
    }
  }

  if ((prova_LOG_BMP_GPS_09_23_B.GC_info[0] == 3) &&
      (prova_LOG_BMP_GPS_09_23_B.GC_info[1] < 200)) {
    if (prova_LOG_BMP_GPS_09_23_B.SFunction_o10[1] == 0.0F) {
      prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_B.SFunction_o9[1] +
        1U;
      if (prova_LOG_BMP_GPS_09_23_B.SFunction_o9[1] + 1U > 65535U) {
        prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
      }

      for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 7;
           prova_LOG_BMP_GPS_09_23_B.f_l++) {
        prova_LOG_BMP_GPS_09_23_DW.WP_dbP[((int32_T)prova_LOG_BMP_GPS_09_23_B.qY
          + 6 * prova_LOG_BMP_GPS_09_23_B.f_l) - 1] =
          prova_LOG_BMP_GPS_09_23_B.SFunction_o10[prova_LOG_BMP_GPS_09_23_B.f_l];
      }

      prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_B.SFunction_o9[1] +
        1U;
      if (prova_LOG_BMP_GPS_09_23_B.SFunction_o9[1] + 1U > 65535U) {
        prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
      }

      for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 6;
           prova_LOG_BMP_GPS_09_23_B.f_l++) {
        prova_LOG_BMP_GPS_09_23_DW.WP_dbI[((int32_T)prova_LOG_BMP_GPS_09_23_B.qY
          + 6 * (prova_LOG_BMP_GPS_09_23_B.f_l + 1)) - 1] =
          prova_LOG_BMP_GPS_09_23_B.WP_info_in[prova_LOG_BMP_GPS_09_23_B.f_l + 1];
      }
    } else {
      prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
        (prova_LOG_BMP_GPS_09_23_B.SFunction_o10[0] + 1.0F);
      for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 7;
           prova_LOG_BMP_GPS_09_23_B.i++) {
        prova_LOG_BMP_GPS_09_23_DW.WP_dbP_AL[(prova_LOG_BMP_GPS_09_23_B.f_l + 6 *
          prova_LOG_BMP_GPS_09_23_B.i) - 1] =
          prova_LOG_BMP_GPS_09_23_B.SFunction_o10[prova_LOG_BMP_GPS_09_23_B.i];
      }

      prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_B.SFunction_o9[1] +
        1U;
      if (prova_LOG_BMP_GPS_09_23_B.SFunction_o9[1] + 1U > 65535U) {
        prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
      }

      for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 6;
           prova_LOG_BMP_GPS_09_23_B.f_l++) {
        prova_LOG_BMP_GPS_09_23_DW.WP_dbI[((int32_T)prova_LOG_BMP_GPS_09_23_B.qY
          + 6 * (prova_LOG_BMP_GPS_09_23_B.f_l + 1)) - 1] =
          prova_LOG_BMP_GPS_09_23_B.WP_info_in[prova_LOG_BMP_GPS_09_23_B.f_l + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((prova_LOG_BMP_GPS_09_23_B.SFunction_o6 == 0) &&
      (prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j == 0)) {
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 0U;
  } else if ((prova_LOG_BMP_GPS_09_23_B.SFunction_o6 == 0) &&
             (prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j == 3)) {
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 0U;
    prova_LOG_BMP_GPS_09_23_DW.test1 = 0.0;
  } else if ((prova_LOG_BMP_GPS_09_23_B.SFunction_o6 == 0) &&
             (prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j == 2)) {
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 0U;
    prova_LOG_BMP_GPS_09_23_DW.test1 = 0.0;
  } else if ((prova_LOG_BMP_GPS_09_23_B.SFunction_o6 == 0) &&
             (prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j == 1)) {
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 0U;
    prova_LOG_BMP_GPS_09_23_DW.test1 = 1.0;
  } else {
    switch (prova_LOG_BMP_GPS_09_23_B.SFunction_o6) {
     case 192:
      prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 192U;
      prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 208U;
      prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((prova_LOG_BMP_GPS_09_23_B.SFunction_o6 == 220) &&
          (prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j != 5)) {
        if ((prova_LOG_BMP_GPS_09_23_B.Memory2[0] == 0) &&
            (prova_LOG_BMP_GPS_09_23_B.Memory2[1] == 0) &&
            ((prova_LOG_BMP_GPS_09_23_B.Memory2[2] == 1) ||
             (prova_LOG_BMP_GPS_09_23_B.Memory2[3] == 1) ||
             (prova_LOG_BMP_GPS_09_23_B.Memory2[4] == 1) ||
             (prova_LOG_BMP_GPS_09_23_B.Memory2[5] == 1) ||
             (prova_LOG_BMP_GPS_09_23_B.Memory2[6] == 1) ||
             (prova_LOG_BMP_GPS_09_23_B.Memory2[7] == 1))) {
          prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 220U;
          prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 220U;
        } else if ((prova_LOG_BMP_GPS_09_23_B.Memory2[0] == 0) &&
                   (prova_LOG_BMP_GPS_09_23_B.Memory2[1] == 1) &&
                   ((prova_LOG_BMP_GPS_09_23_B.Memory2[2] == 1) ||
                    (prova_LOG_BMP_GPS_09_23_B.Memory2[3] == 1) ||
                    (prova_LOG_BMP_GPS_09_23_B.Memory2[4] == 1) ||
                    (prova_LOG_BMP_GPS_09_23_B.Memory2[5] == 1) ||
                    (prova_LOG_BMP_GPS_09_23_B.Memory2[6] == 1) ||
                    (prova_LOG_BMP_GPS_09_23_B.Memory2[7] == 1))) {
          prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 220U;
          prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 220U;
        } else {
          prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 208U;
          prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput = 208U;
        }
      } else if (prova_LOG_BMP_GPS_09_23_B.SFunction_o3_j == 5) {
        prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 220U;
        prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] = 192U;
        prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  prova_LOG_BMP_GPS_09_23_B.qY = 100U * prova_LOG_BMP_GPS_09_23_B.SFunction_o11
    [5];
  if (prova_LOG_BMP_GPS_09_23_B.qY > 65535U) {
    prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
  }

  if (prova_LOG_BMP_GPS_09_23_B.SFunction_o11[4] == 0) {
    if ((uint16_T)prova_LOG_BMP_GPS_09_23_B.qY == 0) {
      prova_LOG_BMP_GPS_09_23_B.z = 0U;
    } else {
      prova_LOG_BMP_GPS_09_23_B.z = MAX_uint16_T;
    }
  } else {
    prova_LOG_BMP_GPS_09_23_B.z = (uint16_T)
      (prova_LOG_BMP_GPS_09_23_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
       (uint32_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.qY /
       prova_LOG_BMP_GPS_09_23_B.SFunction_o11[4]);
    prova_LOG_BMP_GPS_09_23_B.x_e = (uint16_T)((uint32_T)(uint16_T)
      prova_LOG_BMP_GPS_09_23_B.qY - (uint16_T)((uint32_T)
      prova_LOG_BMP_GPS_09_23_B.z * prova_LOG_BMP_GPS_09_23_B.SFunction_o11[4]));
    if ((prova_LOG_BMP_GPS_09_23_B.x_e > 0) && (prova_LOG_BMP_GPS_09_23_B.x_e >=
         (int32_T)((uint32_T)prova_LOG_BMP_GPS_09_23_B.SFunction_o11[4] >> 1) +
         (prova_LOG_BMP_GPS_09_23_B.SFunction_o11[4] & 1))) {
      prova_LOG_BMP_GPS_09_23_B.z++;
    }
  }

  /* RateTransition: '<S29>/Rate Transition' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_DW.RateTransition_Buffer0;

  /* Sum: '<S29>/Add1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  Memory: '<S29>/Memory1'
   */
  prova_LOG_BMP_GPS_09_23_B.num_254 =
    (prova_LOG_BMP_GPS_09_23_P.Constant2_Value_b +
     prova_LOG_BMP_GPS_09_23_P.Constant3_Value_d) +
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput;

  /* Switch: '<S29>/Switch' */
  if (prova_LOG_BMP_GPS_09_23_B.num_254 >
      prova_LOG_BMP_GPS_09_23_P.Switch_Threshold) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant2'
     */
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput =
      prova_LOG_BMP_GPS_09_23_P.Constant2_Value_b;
  } else {
    /* Switch: '<S29>/Switch' */
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput =
      prova_LOG_BMP_GPS_09_23_B.num_254;
  }

  /* End of Switch: '<S29>/Switch' */

  /* MATLAB Function: '<S12>/iflogic_function' */
  if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 1.0) ||
      (prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 3.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 26U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 2.0) ||
             (prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 4.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 30U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (prova_LOG_BMP_GPS_09_23_B.RateTransition == 2.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 33U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (prova_LOG_BMP_GPS_09_23_B.RateTransition == 6.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 34U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (prova_LOG_BMP_GPS_09_23_B.RateTransition == 0.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 0U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             ((prova_LOG_BMP_GPS_09_23_B.RateTransition == 1.0) ||
              (prova_LOG_BMP_GPS_09_23_B.RateTransition == 5.0) ||
              (prova_LOG_BMP_GPS_09_23_B.RateTransition == 9.0))) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 1U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             ((prova_LOG_BMP_GPS_09_23_B.RateTransition == 3.0) ||
              (prova_LOG_BMP_GPS_09_23_B.RateTransition == 8.0))) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 74U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (prova_LOG_BMP_GPS_09_23_B.RateTransition == 7.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 36U;
  } else if ((prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (prova_LOG_BMP_GPS_09_23_B.RateTransition == 4.0)) {
    prova_LOG_BMP_GPS_09_23_B.iflogic = 29U;
  } else {
    prova_LOG_BMP_GPS_09_23_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S12>/iflogic_function' */

  /* Sum: '<S29>/Add' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant1'
   *  Memory: '<S29>/Memory'
   */
  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput +=
    prova_LOG_BMP_GPS_09_23_P.Constant_Value_e +
    prova_LOG_BMP_GPS_09_23_P.Constant1_Value_b;

  /* Gain: '<S12>/Gain' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = prova_LOG_BMP_GPS_09_23_P.Gain_Gain
    * prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3 =
    prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (uint32_T)
    prova_LOG_BMP_GPS_09_23_B.RateTransition;

  /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 6;
       prova_LOG_BMP_GPS_09_23_B.f_l++) {
    prova_LOG_BMP_GPS_09_23_B.WP_info[prova_LOG_BMP_GPS_09_23_B.f_l] =
      prova_LOG_BMP_GPS_09_23_DW.WP_dbI[6 * prova_LOG_BMP_GPS_09_23_B.f_l];
  }

  for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 7;
       prova_LOG_BMP_GPS_09_23_B.f_l++) {
    prova_LOG_BMP_GPS_09_23_B.WP_param[prova_LOG_BMP_GPS_09_23_B.f_l] =
      prova_LOG_BMP_GPS_09_23_DW.WP_dbP[6 * prova_LOG_BMP_GPS_09_23_B.f_l];
  }

  if ((prova_LOG_BMP_GPS_09_23_B.GC_info[0] == 2) &&
      (prova_LOG_BMP_GPS_09_23_B.GC_info[1] < 6)) {
    prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_B.GC_info[1] + 1U;
    if (prova_LOG_BMP_GPS_09_23_B.GC_info[1] + 1U > 65535U) {
      prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
    }

    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 6;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.WP_info[prova_LOG_BMP_GPS_09_23_B.f_l] =
        prova_LOG_BMP_GPS_09_23_DW.WP_dbI[(6 * prova_LOG_BMP_GPS_09_23_B.f_l +
        (int32_T)prova_LOG_BMP_GPS_09_23_B.qY) - 1];
    }

    prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_B.GC_info[1] + 1U;
    if (prova_LOG_BMP_GPS_09_23_B.GC_info[1] + 1U > 65535U) {
      prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
    }

    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 7;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.WP_param[prova_LOG_BMP_GPS_09_23_B.f_l] =
        prova_LOG_BMP_GPS_09_23_DW.WP_dbP[(6 * prova_LOG_BMP_GPS_09_23_B.f_l +
        (int32_T)prova_LOG_BMP_GPS_09_23_B.qY) - 1];
    }
  }

  if ((prova_LOG_BMP_GPS_09_23_B.GC_info[0] == 3) &&
      (prova_LOG_BMP_GPS_09_23_B.GC_info[1] < 200)) {
    prova_LOG_BMP_GPS_09_23_B.qY = prova_LOG_BMP_GPS_09_23_B.GC_info[1] + 1U;
    if (prova_LOG_BMP_GPS_09_23_B.GC_info[1] + 1U > 65535U) {
      prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
    }

    for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l < 6;
         prova_LOG_BMP_GPS_09_23_B.f_l++) {
      prova_LOG_BMP_GPS_09_23_B.WP_info[prova_LOG_BMP_GPS_09_23_B.f_l] =
        prova_LOG_BMP_GPS_09_23_DW.WP_dbI[(6 * prova_LOG_BMP_GPS_09_23_B.f_l +
        (int32_T)prova_LOG_BMP_GPS_09_23_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S19>/MATLAB Function' */

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/onboard_control_sensor_present uint32'
   */
  prova_LOG_BMP_GPS_09_23_B.onboard[0] =
    prova_LOG_BMP_GPS_09_23_P.onboard_control_sensor_presentu[0];
  prova_LOG_BMP_GPS_09_23_B.onboard[1] =
    prova_LOG_BMP_GPS_09_23_P.onboard_control_sensor_presentu[1];
  prova_LOG_BMP_GPS_09_23_B.onboard[2] =
    prova_LOG_BMP_GPS_09_23_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S17>/Constant'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_c *
     prova_LOG_BMP_GPS_09_23_P.Constant_Value_o);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  Constant: '<S17>/load uint16'
   *  Gain: '<S17>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.LVDE[0] = prova_LOG_BMP_GPS_09_23_P.loaduint16_Value;
  prova_LOG_BMP_GPS_09_23_B.LVDE[1] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  prova_LOG_BMP_GPS_09_23_B.qY = 10U * prova_LOG_BMP_GPS_09_23_B.z;
  if (prova_LOG_BMP_GPS_09_23_B.qY > 65535U) {
    prova_LOG_BMP_GPS_09_23_B.qY = 65535U;
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  Constant: '<S17>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_BMP_GPS_09_23_B.LVDE[2] = (uint16_T)prova_LOG_BMP_GPS_09_23_B.qY;
  prova_LOG_BMP_GPS_09_23_B.LVDE[3] = prova_LOG_BMP_GPS_09_23_B.SFunction_o11[6];
  prova_LOG_BMP_GPS_09_23_B.LVDE[4] = prova_LOG_BMP_GPS_09_23_B.SFunction_o11[2];
  prova_LOG_BMP_GPS_09_23_B.LVDE[5] = prova_LOG_BMP_GPS_09_23_P._Value;

  /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_l[0]);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion4'
   */
  prova_LOG_BMP_GPS_09_23_B.LVDE[6] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_l[1]);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion4'
   */
  prova_LOG_BMP_GPS_09_23_B.LVDE[7] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* Gain: '<S17>/Gain2' incorporates:
   *  Constant: '<S17>/Constant3'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Gain2_Gain *
     prova_LOG_BMP_GPS_09_23_P.Constant3_Value_m1);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Gain: '<S17>/Gain1'
   *  Gain: '<S17>/Gain2'
   */
  prova_LOG_BMP_GPS_09_23_B.B_Current = (int16_T)
    (((prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
       -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
       (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition) *
      prova_LOG_BMP_GPS_09_23_P.Gain1_Gain_f) >> 18);

  /* DataTypeConversion: '<S17>/Data Type Conversion3' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant2_Value_ac);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.B_Remaining = (int8_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int8_T)-(int8_T)
     (uint8_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(int8_T)
     (uint8_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant_Value_n);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion =
    prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (uint32_T)
    prova_LOG_BMP_GPS_09_23_B.RateTransition;

  /* MATLAB Function: '<S10>/Alarm set' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_H_mav[0] = prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0];
  rtb_H_mav[1] = prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1];
  if (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_j[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_j[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S10>/Alarm set' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S10>/Type fixed_wing Autopilot generic'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[0] =
    prova_LOG_BMP_GPS_09_23_P.Typefixed_wingAutopilotgeneric_[0];
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[1] =
    prova_LOG_BMP_GPS_09_23_P.Typefixed_wingAutopilotgeneric_[1];
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[2] = rtb_H_mav[0];
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[3] = rtb_H_mav[1];

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant9'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant9_Value < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant9_Value);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant9_Value);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[0] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant10'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant10_Value < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant10_Value);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant10_Value);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[1] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant11'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant11_Value < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant11_Value);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant11_Value);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[2] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant6'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant6_Value_g < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant6_Value_g);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant6_Value_g);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[3] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant8'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant8_Value < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant8_Value);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant8_Value);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[4] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant7'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant7_Value < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant7_Value);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant7_Value);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[5] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[0] < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[0]);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[0]);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[6] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[1] < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[1]);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[1]);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[7] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[2] < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[2]);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_a[2]);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[8] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Constant: '<S11>/Constant6'
   *  Constant: '<S11>/Constant7'
   *  Constant: '<S11>/Constant8'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[0] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.Constant12_Value;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[1] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.Constant4_Value_n;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[2] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.Constant5_Value_i;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[3] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.Constant6_Value_g;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[4] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.Constant8_Value;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[5] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.Constant7_Value;

  /* MATLABSystem: '<S22>/Serial Receive1' */
  if (prova_LOG_BMP_GPS_09_23_DW.obj_e.Protocol !=
      prova_LOG_BMP_GPS_09_23_P.SerialReceive1_Protocol) {
    prova_LOG_BMP_GPS_09_23_DW.obj_e.Protocol =
      prova_LOG_BMP_GPS_09_23_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, prova_LOG_BMP_GPS_09_23_DW.obj_e.DataSizeInBytes,
                 &prova_LOG_BMP_GPS_09_23_B.b_dataOut[0], &counter);

  /* Outputs for Enabled SubSystem: '<S22>/Subsystem2' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  if (counter > 0) {
    /* MATLAB Function: '<S24>/Create_message' */
    counter = 0U;
    if (!prova_LOG_BMP_GPS_09_23_DW.start_found) {
      prova_LOG_BMP_GPS_09_23_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.i - 1 < 32)) {
        if (prova_LOG_BMP_GPS_09_23_B.b_dataOut[(uint8_T)
            prova_LOG_BMP_GPS_09_23_B.i - 1] == 36) {
          prova_LOG_BMP_GPS_09_23_B.caso = 32 - (uint8_T)
            prova_LOG_BMP_GPS_09_23_B.i;
          for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <=
               prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++)
          {
            prova_LOG_BMP_GPS_09_23_DW.message[prova_LOG_BMP_GPS_09_23_B.f_l] =
              prova_LOG_BMP_GPS_09_23_B.b_dataOut[((uint8_T)
              prova_LOG_BMP_GPS_09_23_B.i + prova_LOG_BMP_GPS_09_23_B.f_l) - 1];
          }

          prova_LOG_BMP_GPS_09_23_DW.counter_g = (uint8_T)(33 - (uint8_T)
            prova_LOG_BMP_GPS_09_23_B.i);
          prova_LOG_BMP_GPS_09_23_DW.start_found = true;
          exitg1 = true;
        } else {
          prova_LOG_BMP_GPS_09_23_B.i++;
        }
      }
    } else {
      prova_LOG_BMP_GPS_09_23_B.f_l = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_LOG_BMP_GPS_09_23_B.f_l - 1 < 32)) {
        if (prova_LOG_BMP_GPS_09_23_B.b_dataOut[(uint8_T)
            prova_LOG_BMP_GPS_09_23_B.f_l - 1] == 13) {
          prova_LOG_BMP_GPS_09_23_DW.end_found = true;
          counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.f_l;
          exitg1 = true;
        } else {
          prova_LOG_BMP_GPS_09_23_B.f_l++;
        }
      }

      if (prova_LOG_BMP_GPS_09_23_DW.end_found) {
        if (1 > counter) {
          prova_LOG_BMP_GPS_09_23_B.caso = -1;
        } else {
          prova_LOG_BMP_GPS_09_23_B.caso = counter - 1;
        }

        for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <=
             prova_LOG_BMP_GPS_09_23_B.caso; prova_LOG_BMP_GPS_09_23_B.f_l++) {
          prova_LOG_BMP_GPS_09_23_B.i = (int32_T)(((uint32_T)
            prova_LOG_BMP_GPS_09_23_B.f_l + prova_LOG_BMP_GPS_09_23_DW.counter_g)
            + 1U);
          if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.i > 255U) {
            prova_LOG_BMP_GPS_09_23_B.i = 255;
          }

          prova_LOG_BMP_GPS_09_23_DW.message[prova_LOG_BMP_GPS_09_23_B.i - 1] =
            prova_LOG_BMP_GPS_09_23_B.b_dataOut[prova_LOG_BMP_GPS_09_23_B.f_l];
        }

        memcpy(&prova_LOG_BMP_GPS_09_23_B.messaggio_c[0],
               &prova_LOG_BMP_GPS_09_23_DW.message[0], 80U * sizeof(uint8_T));
        prova_LOG_BMP_GPS_09_23_DW.end_found = false;
        prova_LOG_BMP_GPS_09_23_DW.counter_g = (uint8_T)(32 - counter);
        if (counter == 32) {
          prova_LOG_BMP_GPS_09_23_DW.start_found = false;
          memset(&prova_LOG_BMP_GPS_09_23_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          prova_LOG_BMP_GPS_09_23_DW.start_found = true;
          prova_LOG_BMP_GPS_09_23_B.caso = -counter;
          for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <=
               prova_LOG_BMP_GPS_09_23_B.caso + 31;
               prova_LOG_BMP_GPS_09_23_B.f_l++) {
            prova_LOG_BMP_GPS_09_23_DW.message[prova_LOG_BMP_GPS_09_23_B.f_l] =
              prova_LOG_BMP_GPS_09_23_B.b_dataOut[counter +
              prova_LOG_BMP_GPS_09_23_B.f_l];
          }

          prova_LOG_BMP_GPS_09_23_B.f_l = counter + 48;
          if (0 <= prova_LOG_BMP_GPS_09_23_B.f_l - 1) {
            memset(&prova_LOG_BMP_GPS_09_23_DW.message[-counter + 32], 0,
                   ((prova_LOG_BMP_GPS_09_23_B.f_l - counter) + counter) *
                   sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S24>/Subsystem' incorporates:
         *  EnablePort: '<S26>/Enable'
         */
        /* MATLAB Function: '<S26>/MATLAB Function' */
        counter = 0U;
        find_comma = 0U;
        prova_LOG_BMP_GPS_09_23_B.indice_dimario = 0U;
        for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 80;
             prova_LOG_BMP_GPS_09_23_B.i++) {
          messaggio = (int8_T)
            prova_LOG_BMP_GPS_09_23_B.messaggio_c[prova_LOG_BMP_GPS_09_23_B.i];
          if (messaggio == '$') {
            prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)(counter + 1U);
            if (counter + 1U > 255U) {
              prova_LOG_BMP_GPS_09_23_B.f_l = 255;
            }

            counter = (uint8_T)prova_LOG_BMP_GPS_09_23_B.f_l;
          }

          if (messaggio == ',') {
            prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              prova_LOG_BMP_GPS_09_23_B.f_l = 255;
            }

            find_comma = (uint8_T)prova_LOG_BMP_GPS_09_23_B.f_l;
          }

          prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.i] =
            messaggio;
        }

        if ((counter == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
               80; prova_LOG_BMP_GPS_09_23_B.f_l++) {
            prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
              =
              (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
               == '$');
          }

          prova_LOG_BMP_GPS_09_2_eml_find(prova_LOG_BMP_GPS_09_23_B.messaggio_m,
            &prova_LOG_BMP_GPS_09_23_B.eb_data,
            prova_LOG_BMP_GPS_09_23_B.eb_size);
          prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.eb_data;
          for (prova_LOG_BMP_GPS_09_23_B.f_l = 0; prova_LOG_BMP_GPS_09_23_B.f_l <
               5; prova_LOG_BMP_GPS_09_23_B.f_l++) {
            messaggio =
              prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l
              + prova_LOG_BMP_GPS_09_23_B.status];
            prova_LOG_BMP_GPS_09_23_B.mess_type_d[prova_LOG_BMP_GPS_09_23_B.f_l]
              = (messaggio == bb[prova_LOG_BMP_GPS_09_23_B.f_l]);
            prova_LOG_BMP_GPS_09_23_B.mess_type[prova_LOG_BMP_GPS_09_23_B.f_l] =
              messaggio;
          }

          if (prova_LOG_BMP_GPS_ifWhileCond_m
              (prova_LOG_BMP_GPS_09_23_B.mess_type_d)) {
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l < 80;
                 prova_LOG_BMP_GPS_09_23_B.f_l++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
                 == ',');
            }

            prova_LOG_BMP_GPS_09_eml_find_k
              (prova_LOG_BMP_GPS_09_23_B.messaggio_m,
               prova_LOG_BMP_GPS_09_23_B.comma_gga_data,
               prova_LOG_BMP_GPS_09_23_B.eb_size);
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l < 80;
                 prova_LOG_BMP_GPS_09_23_B.f_l++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
                 == '*');
            }

            prova_LOG_BMP_GPS_09_eml_find_k
              (prova_LOG_BMP_GPS_09_23_B.messaggio_m,
               prova_LOG_BMP_GPS_09_23_B.star_data,
               prova_LOG_BMP_GPS_09_23_B.star_size);
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l < 80;
                 prova_LOG_BMP_GPS_09_23_B.f_l++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
                 == '$');
            }

            prova_LOG_BMP_GPS_09_eml_find_k
              (prova_LOG_BMP_GPS_09_23_B.messaggio_m,
               prova_LOG_BMP_GPS_09_23_B.fb_data,
               prova_LOG_BMP_GPS_09_23_B.star_size);
            prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS_09_str2double
              (&prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.comma_gga_data
               [2]]);
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[2] + 3.0 >
                (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[3] - 1.0) {
              prova_LOG_BMP_GPS_09_23_B.caso = 0;
              prova_LOG_BMP_GPS_09_23_B.f_l = 0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.caso =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[2] + 2;
              prova_LOG_BMP_GPS_09_23_B.f_l =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[3] - 1;
            }

            prova_LOG_BMP_GPS_09_23_B.messaggio_size[0] = 1;
            prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
              prova_LOG_BMP_GPS_09_23_B.caso;
            prova_LOG_BMP_GPS_09_23_B.messaggio_size[1] =
              prova_LOG_BMP_GPS_09_23_B.status;
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l <
                 prova_LOG_BMP_GPS_09_23_B.status; prova_LOG_BMP_GPS_09_23_B.f_l
                 ++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                + prova_LOG_BMP_GPS_09_23_B.f_l];
            }

            prova_LOG_BMP_GPS_09_23_B.b_x = prova_LOG_BMP_GPS__str2double_n
              (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
               prova_LOG_BMP_GPS_09_23_B.messaggio_size);
            if (prova_LOG_BMP_GPS_09_23_B.b_x.im == 0.0) {
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
            } else if (prova_LOG_BMP_GPS_09_23_B.b_x.re == 0.0) {
              prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
            }

            prova_LOG_BMP_GPS_09_23_B.num_254 =
              prova_LOG_BMP_GPS_09_23_B.Lat_1.re +
              prova_LOG_BMP_GPS_09_23_B.RateTransition;
            prova_LOG_BMP_GPS_09_23_B.caso = prova_LOG_BMP_GPS_09_23_B.eb_size[0]
              * prova_LOG_BMP_GPS_09_23_B.eb_size[1] - 1;
            if (0 <= prova_LOG_BMP_GPS_09_23_B.caso) {
              memcpy(&prova_LOG_BMP_GPS_09_23_B.tmp_data[0],
                     &prova_LOG_BMP_GPS_09_23_B.comma_gga_data[0],
                     (prova_LOG_BMP_GPS_09_23_B.caso + 1) * sizeof(int32_T));
            }

            if (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.tmp_data
                [3]] == 'S') {
              prova_LOG_BMP_GPS_09_23_B.num_254 =
                -prova_LOG_BMP_GPS_09_23_B.num_254;
            }

            prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS_str2double_nq
              (&prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.comma_gga_data
               [4]]);
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[4] + 4.0 >
                (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[5] - 1.0) {
              prova_LOG_BMP_GPS_09_23_B.i = 0;
              prova_LOG_BMP_GPS_09_23_B.f_l = 0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.i =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[4] + 3;
              prova_LOG_BMP_GPS_09_23_B.f_l =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[5] - 1;
            }

            prova_LOG_BMP_GPS_09_23_B.messaggio_size_k[0] = 1;
            prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
              prova_LOG_BMP_GPS_09_23_B.i;
            prova_LOG_BMP_GPS_09_23_B.messaggio_size_k[1] =
              prova_LOG_BMP_GPS_09_23_B.status;
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l <
                 prova_LOG_BMP_GPS_09_23_B.status; prova_LOG_BMP_GPS_09_23_B.f_l
                 ++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.i
                + prova_LOG_BMP_GPS_09_23_B.f_l];
            }

            prova_LOG_BMP_GPS_09_23_B.b_x = prova_LOG_BMP_GPS__str2double_n
              (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
               prova_LOG_BMP_GPS_09_23_B.messaggio_size_k);
            if (prova_LOG_BMP_GPS_09_23_B.b_x.im == 0.0) {
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
            } else if (prova_LOG_BMP_GPS_09_23_B.b_x.re == 0.0) {
              prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
            }

            prova_LOG_BMP_GPS_09_23_B.RateTransition +=
              prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
            if (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.tmp_data
                [5]] == 'W') {
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                -prova_LOG_BMP_GPS_09_23_B.RateTransition;
            }

            if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[6] + 1.0 >
                (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[7] - 1.0) {
              prova_LOG_BMP_GPS_09_23_B.i = 0;
              prova_LOG_BMP_GPS_09_23_B.f_l = 0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.i =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[6];
              prova_LOG_BMP_GPS_09_23_B.f_l =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[7] - 1;
            }

            prova_LOG_BMP_GPS_09_23_B.messaggio_size_c[0] = 1;
            prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
              prova_LOG_BMP_GPS_09_23_B.i;
            prova_LOG_BMP_GPS_09_23_B.messaggio_size_c[1] =
              prova_LOG_BMP_GPS_09_23_B.status;
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l <
                 prova_LOG_BMP_GPS_09_23_B.status; prova_LOG_BMP_GPS_09_23_B.f_l
                 ++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.i
                + prova_LOG_BMP_GPS_09_23_B.f_l];
            }

            prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS__str2double_n
              (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
               prova_LOG_BMP_GPS_09_23_B.messaggio_size_c);

            /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[2] =
              prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[7] + 1.0 >
                (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[8] - 1.0) {
              prova_LOG_BMP_GPS_09_23_B.caso = 0;
              prova_LOG_BMP_GPS_09_23_B.f_l = 0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.caso =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[7];
              prova_LOG_BMP_GPS_09_23_B.f_l =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[8] - 1;
            }

            prova_LOG_BMP_GPS_09_23_B.messaggio_size_b[0] = 1;
            prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
              prova_LOG_BMP_GPS_09_23_B.caso;
            prova_LOG_BMP_GPS_09_23_B.messaggio_size_b[1] =
              prova_LOG_BMP_GPS_09_23_B.status;
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l <
                 prova_LOG_BMP_GPS_09_23_B.status; prova_LOG_BMP_GPS_09_23_B.f_l
                 ++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                + prova_LOG_BMP_GPS_09_23_B.f_l];
            }

            prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS__str2double_n
              (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
               prova_LOG_BMP_GPS_09_23_B.messaggio_size_b);

            /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[4] =
              prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[9] + 1.0 >
                (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[10] - 1.0) {
              prova_LOG_BMP_GPS_09_23_B.caso = 0;
              prova_LOG_BMP_GPS_09_23_B.f_l = 0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.caso =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[9];
              prova_LOG_BMP_GPS_09_23_B.f_l =
                prova_LOG_BMP_GPS_09_23_B.comma_gga_data[10] - 1;
            }

            prova_LOG_BMP_GPS_09_23_B.messaggio_size_p[0] = 1;
            prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
              prova_LOG_BMP_GPS_09_23_B.caso;
            prova_LOG_BMP_GPS_09_23_B.messaggio_size_p[1] =
              prova_LOG_BMP_GPS_09_23_B.status;
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l <
                 prova_LOG_BMP_GPS_09_23_B.status; prova_LOG_BMP_GPS_09_23_B.f_l
                 ++) {
              prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                + prova_LOG_BMP_GPS_09_23_B.f_l];
            }

            prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS__str2double_n
              (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
               prova_LOG_BMP_GPS_09_23_B.messaggio_size_p);

            /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[3] =
              prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
            if (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.tmp_data
                [10]] == 'W') {
              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[3] =
                -prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[5] =
              prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[5];
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[6] =
              prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[6];
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[7] =
              prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[7];
            prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[8] =
              prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[8];
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 1.0 >= 0.0) {
                counter = (uint8_T)((real_T)prova_LOG_BMP_GPS_09_23_B.star_data
                                    [0] + 1.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[0] = prova_LOG_BMP_GPS_09_23_B.messaggio[counter - 1];
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 2.0 >= 0.0) {
                counter = (uint8_T)((real_T)prova_LOG_BMP_GPS_09_23_B.star_data
                                    [0] + 2.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[1] = prova_LOG_BMP_GPS_09_23_B.messaggio[counter - 1];
            if ((real_T)prova_LOG_BMP_GPS_09_23_B.fb_data[0] + 1.0 > (real_T)
                prova_LOG_BMP_GPS_09_23_B.star_data[0] - 1.0) {
              prova_LOG_BMP_GPS_09_23_B.caso = 0;
              prova_LOG_BMP_GPS_09_23_B.status = 0;
            } else {
              prova_LOG_BMP_GPS_09_23_B.caso =
                prova_LOG_BMP_GPS_09_23_B.fb_data[0];
              prova_LOG_BMP_GPS_09_23_B.status =
                prova_LOG_BMP_GPS_09_23_B.star_data[0] - 1;
            }

            prova_LOG_BMP_GPS_09_23_B.status -= prova_LOG_BMP_GPS_09_23_B.caso;
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l <
                 prova_LOG_BMP_GPS_09_23_B.status; prova_LOG_BMP_GPS_09_23_B.f_l
                 ++) {
              prova_LOG_BMP_GPS_09_23_B.NMEA_gga_string_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                = (uint8_T)
                prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                + prova_LOG_BMP_GPS_09_23_B.f_l];
            }

            counter = 0U;
            prova_LOG_BMP_GPS_09_23_B.f_l = 0;
            while (prova_LOG_BMP_GPS_09_23_B.f_l <=
                   prova_LOG_BMP_GPS_09_23_B.status - 1) {
              counter ^=
                prova_LOG_BMP_GPS_09_23_B.NMEA_gga_string_data[prova_LOG_BMP_GPS_09_23_B.f_l];
              prova_LOG_BMP_GPS_09_23_B.f_l++;
            }

            if (counter != prova_LOG_BMP_GPS_09_23_hex2dec(ck_ric)) {
              prova_LOG_BMP_GPS_09_23_B.num_254 =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[0];
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[1];

              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[2] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[2];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[3] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[3];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[4] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[4];
              prova_LOG_BMP_GPS_09_23_B.indice_dimario = 10U;
            }
          } else {
            for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                 prova_LOG_BMP_GPS_09_23_B.f_l < 5;
                 prova_LOG_BMP_GPS_09_23_B.f_l++) {
              prova_LOG_BMP_GPS_09_23_B.mess_type_d[prova_LOG_BMP_GPS_09_23_B.f_l]
                =
                (prova_LOG_BMP_GPS_09_23_B.mess_type[prova_LOG_BMP_GPS_09_23_B.f_l]
                 == cb[prova_LOG_BMP_GPS_09_23_B.f_l]);
            }

            if (prova_LOG_BMP_GPS_ifWhileCond_m
                (prova_LOG_BMP_GPS_09_23_B.mess_type_d)) {
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l < 80;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
                   == ',');
              }

              prova_LOG_BMP_GPS_09_eml_find_k
                (prova_LOG_BMP_GPS_09_23_B.messaggio_m,
                 prova_LOG_BMP_GPS_09_23_B.comma_gga_data,
                 prova_LOG_BMP_GPS_09_23_B.eb_size);
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l < 80;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
                   == '*');
              }

              prova_LOG_BMP_GPS_09_eml_find_k
                (prova_LOG_BMP_GPS_09_23_B.messaggio_m,
                 prova_LOG_BMP_GPS_09_23_B.star_data,
                 prova_LOG_BMP_GPS_09_23_B.star_size);
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l < 80;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_m[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.f_l]
                   == '$');
              }

              prova_LOG_BMP_GPS_09_eml_find_k
                (prova_LOG_BMP_GPS_09_23_B.messaggio_m,
                 prova_LOG_BMP_GPS_09_23_B.fb_data,
                 prova_LOG_BMP_GPS_09_23_B.star_size);
              prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS_09_str2double(
                &prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.comma_gga_data
                [1]]);
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[1] + 3.0 >
                  (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[2] - 1.0) {
                prova_LOG_BMP_GPS_09_23_B.caso = 0;
                prova_LOG_BMP_GPS_09_23_B.f_l = 0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.caso =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[1] + 2;
                prova_LOG_BMP_GPS_09_23_B.f_l =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[2] - 1;
              }

              prova_LOG_BMP_GPS_09_23_B.messaggio_size[0] = 1;
              prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
                prova_LOG_BMP_GPS_09_23_B.caso;
              prova_LOG_BMP_GPS_09_23_B.messaggio_size[1] =
                prova_LOG_BMP_GPS_09_23_B.status;
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l <
                   prova_LOG_BMP_GPS_09_23_B.status;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                  + prova_LOG_BMP_GPS_09_23_B.f_l];
              }

              prova_LOG_BMP_GPS_09_23_B.b_x = prova_LOG_BMP_GPS__str2double_n
                (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
                 prova_LOG_BMP_GPS_09_23_B.messaggio_size);
              if (prova_LOG_BMP_GPS_09_23_B.b_x.im == 0.0) {
                prova_LOG_BMP_GPS_09_23_B.RateTransition =
                  prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
              } else if (prova_LOG_BMP_GPS_09_23_B.b_x.re == 0.0) {
                prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.RateTransition =
                  prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
              }

              prova_LOG_BMP_GPS_09_23_B.num_254 =
                prova_LOG_BMP_GPS_09_23_B.Lat_1.re +
                prova_LOG_BMP_GPS_09_23_B.RateTransition;
              prova_LOG_BMP_GPS_09_23_B.caso =
                prova_LOG_BMP_GPS_09_23_B.eb_size[0] *
                prova_LOG_BMP_GPS_09_23_B.eb_size[1] - 1;
              if (0 <= prova_LOG_BMP_GPS_09_23_B.caso) {
                memcpy(&prova_LOG_BMP_GPS_09_23_B.tmp_data[0],
                       &prova_LOG_BMP_GPS_09_23_B.comma_gga_data[0],
                       (prova_LOG_BMP_GPS_09_23_B.caso + 1) * sizeof(int32_T));
              }

              if (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.tmp_data
                  [2]] == 'S') {
                prova_LOG_BMP_GPS_09_23_B.num_254 =
                  -prova_LOG_BMP_GPS_09_23_B.num_254;
              }

              prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS_str2double_nq(
                &prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.comma_gga_data
                [3]]);
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[3] + 4.0 >
                  (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[4] - 1.0) {
                prova_LOG_BMP_GPS_09_23_B.i = 0;
                prova_LOG_BMP_GPS_09_23_B.f_l = 0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.i =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[3] + 3;
                prova_LOG_BMP_GPS_09_23_B.f_l =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[4] - 1;
              }

              prova_LOG_BMP_GPS_09_23_B.messaggio_size_k[0] = 1;
              prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
                prova_LOG_BMP_GPS_09_23_B.i;
              prova_LOG_BMP_GPS_09_23_B.messaggio_size_k[1] =
                prova_LOG_BMP_GPS_09_23_B.status;
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l <
                   prova_LOG_BMP_GPS_09_23_B.status;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.i
                  + prova_LOG_BMP_GPS_09_23_B.f_l];
              }

              prova_LOG_BMP_GPS_09_23_B.b_x = prova_LOG_BMP_GPS__str2double_n
                (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
                 prova_LOG_BMP_GPS_09_23_B.messaggio_size_k);
              if (prova_LOG_BMP_GPS_09_23_B.b_x.im == 0.0) {
                prova_LOG_BMP_GPS_09_23_B.RateTransition =
                  prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
              } else if (prova_LOG_BMP_GPS_09_23_B.b_x.re == 0.0) {
                prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.RateTransition =
                  prova_LOG_BMP_GPS_09_23_B.b_x.re / 60.0;
              }

              prova_LOG_BMP_GPS_09_23_B.RateTransition +=
                prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
              if (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.tmp_data
                  [4]] == 'W') {
                prova_LOG_BMP_GPS_09_23_B.RateTransition =
                  -prova_LOG_BMP_GPS_09_23_B.RateTransition;
              }

              prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GP_str2double_nqh
                (prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[5] =
                prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[6] + 1.0 >
                  (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[7] - 1.0) {
                prova_LOG_BMP_GPS_09_23_B.caso = 0;
                prova_LOG_BMP_GPS_09_23_B.f_l = 0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.caso =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[6];
                prova_LOG_BMP_GPS_09_23_B.f_l =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[7] - 1;
              }

              prova_LOG_BMP_GPS_09_23_B.messaggio_size_c[0] = 1;
              prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
                prova_LOG_BMP_GPS_09_23_B.caso;
              prova_LOG_BMP_GPS_09_23_B.messaggio_size_c[1] =
                prova_LOG_BMP_GPS_09_23_B.status;
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l <
                   prova_LOG_BMP_GPS_09_23_B.status;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                  + prova_LOG_BMP_GPS_09_23_B.f_l];
              }

              prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS__str2double_n
                (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
                 prova_LOG_BMP_GPS_09_23_B.messaggio_size_c);

              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[6] =
                prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[8] + 1.0 >
                  (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[9] - 1.0) {
                prova_LOG_BMP_GPS_09_23_B.i = 0;
                prova_LOG_BMP_GPS_09_23_B.f_l = 0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.i =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[8];
                prova_LOG_BMP_GPS_09_23_B.f_l =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[9] - 1;
              }

              prova_LOG_BMP_GPS_09_23_B.messaggio_size_b[0] = 1;
              prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
                prova_LOG_BMP_GPS_09_23_B.i;
              prova_LOG_BMP_GPS_09_23_B.messaggio_size_b[1] =
                prova_LOG_BMP_GPS_09_23_B.status;
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l <
                   prova_LOG_BMP_GPS_09_23_B.status;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.i
                  + prova_LOG_BMP_GPS_09_23_B.f_l];
              }

              prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS__str2double_n
                (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
                 prova_LOG_BMP_GPS_09_23_B.messaggio_size_b);

              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[7] =
                prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[10] + 1.0 >
                  (real_T)prova_LOG_BMP_GPS_09_23_B.comma_gga_data[11] - 1.0) {
                prova_LOG_BMP_GPS_09_23_B.x_d = 0;
                prova_LOG_BMP_GPS_09_23_B.caso = 0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.x_d =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[10];
                prova_LOG_BMP_GPS_09_23_B.caso =
                  prova_LOG_BMP_GPS_09_23_B.comma_gga_data[11] - 1;
              }

              prova_LOG_BMP_GPS_09_23_B.messaggio_size_p[0] = 1;
              prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.caso
                - prova_LOG_BMP_GPS_09_23_B.x_d;
              prova_LOG_BMP_GPS_09_23_B.messaggio_size_p[1] =
                prova_LOG_BMP_GPS_09_23_B.status;
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l <
                   prova_LOG_BMP_GPS_09_23_B.status;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.messaggio_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                  =
                  prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.x_d
                  + prova_LOG_BMP_GPS_09_23_B.f_l];
              }

              prova_LOG_BMP_GPS_09_23_B.Lat_1 = prova_LOG_BMP_GPS__str2double_n
                (prova_LOG_BMP_GPS_09_23_B.messaggio_data,
                 prova_LOG_BMP_GPS_09_23_B.messaggio_size_p);

              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[8] =
                prova_LOG_BMP_GPS_09_23_B.Lat_1.re;
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[2] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[2];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[3] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[3];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[4] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[4];
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 1.0 < 256.0)
              {
                if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 1.0 >= 0.0)
                {
                  counter = (uint8_T)((real_T)
                                      prova_LOG_BMP_GPS_09_23_B.star_data[0] +
                                      1.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[0] = prova_LOG_BMP_GPS_09_23_B.messaggio[counter - 1];
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 2.0 < 256.0)
              {
                if ((real_T)prova_LOG_BMP_GPS_09_23_B.star_data[0] + 2.0 >= 0.0)
                {
                  counter = (uint8_T)((real_T)
                                      prova_LOG_BMP_GPS_09_23_B.star_data[0] +
                                      2.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[1] = prova_LOG_BMP_GPS_09_23_B.messaggio[counter - 1];
              if ((real_T)prova_LOG_BMP_GPS_09_23_B.fb_data[0] + 1.0 > (real_T)
                  prova_LOG_BMP_GPS_09_23_B.star_data[0] - 1.0) {
                prova_LOG_BMP_GPS_09_23_B.caso = 0;
                prova_LOG_BMP_GPS_09_23_B.f_l = 0;
              } else {
                prova_LOG_BMP_GPS_09_23_B.caso =
                  prova_LOG_BMP_GPS_09_23_B.fb_data[0];
                prova_LOG_BMP_GPS_09_23_B.f_l =
                  prova_LOG_BMP_GPS_09_23_B.star_data[0] - 1;
              }

              prova_LOG_BMP_GPS_09_23_B.status = prova_LOG_BMP_GPS_09_23_B.f_l -
                prova_LOG_BMP_GPS_09_23_B.caso;
              for (prova_LOG_BMP_GPS_09_23_B.f_l = 0;
                   prova_LOG_BMP_GPS_09_23_B.f_l <
                   prova_LOG_BMP_GPS_09_23_B.status;
                   prova_LOG_BMP_GPS_09_23_B.f_l++) {
                prova_LOG_BMP_GPS_09_23_B.NMEA_gga_string_data[prova_LOG_BMP_GPS_09_23_B.f_l]
                  = (uint8_T)
                  prova_LOG_BMP_GPS_09_23_B.messaggio[prova_LOG_BMP_GPS_09_23_B.caso
                  + prova_LOG_BMP_GPS_09_23_B.f_l];
              }

              counter = 0U;
              prova_LOG_BMP_GPS_09_23_B.f_l = 0;
              while (prova_LOG_BMP_GPS_09_23_B.f_l <=
                     prova_LOG_BMP_GPS_09_23_B.status - 1) {
                counter ^=
                  prova_LOG_BMP_GPS_09_23_B.NMEA_gga_string_data[prova_LOG_BMP_GPS_09_23_B.f_l];
                prova_LOG_BMP_GPS_09_23_B.f_l++;
              }

              if (counter != prova_LOG_BMP_GPS_09_23_hex2dec(ck_ric)) {
                prova_LOG_BMP_GPS_09_23_B.num_254 =
                  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[0];
                prova_LOG_BMP_GPS_09_23_B.RateTransition =
                  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[1];

                /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
                prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[5] =
                  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[5];
                prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[6] =
                  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[6];
                prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[7] =
                  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[7];
                prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[8] =
                  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[8];
                prova_LOG_BMP_GPS_09_23_B.indice_dimario = 20U;
              }
            } else {
              prova_LOG_BMP_GPS_09_23_B.num_254 =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[0];
              prova_LOG_BMP_GPS_09_23_B.RateTransition =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[1];

              /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[2] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[2];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[3] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[3];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[4] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[4];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[5] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[5];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[6] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[6];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[7] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[7];
              prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[8] =
                prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[8];
            }
          }
        } else {
          prova_LOG_BMP_GPS_09_23_B.num_254 =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[0];
          prova_LOG_BMP_GPS_09_23_B.RateTransition =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[1];

          /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[2] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[2];
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[3] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[3];
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[4] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[4];
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[5] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[5];
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[6] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[6];
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[7] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[7];
          prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[8] =
            prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[8];
        }

        /* End of MATLAB Function: '<S26>/MATLAB Function' */

        /* ComplexToRealImag: '<S26>/Complex to Real-Imag' */
        prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[0] =
          prova_LOG_BMP_GPS_09_23_B.num_254;
        prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[1] =
          prova_LOG_BMP_GPS_09_23_B.RateTransition;

        /* Update for Memory: '<S26>/Memory' */
        memcpy(&prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[0],
               &prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[0], 9U * sizeof
               (real_T));

        /* End of Outputs for SubSystem: '<S24>/Subsystem' */
      } else {
        for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 32;
             prova_LOG_BMP_GPS_09_23_B.i++) {
          prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)(((uint32_T)
            prova_LOG_BMP_GPS_09_23_DW.counter_g + prova_LOG_BMP_GPS_09_23_B.i)
            + 1U);
          if ((uint32_T)prova_LOG_BMP_GPS_09_23_B.f_l > 255U) {
            prova_LOG_BMP_GPS_09_23_B.f_l = 255;
          }

          prova_LOG_BMP_GPS_09_23_DW.message[prova_LOG_BMP_GPS_09_23_B.f_l - 1] =
            prova_LOG_BMP_GPS_09_23_B.b_dataOut[prova_LOG_BMP_GPS_09_23_B.i];
        }

        prova_LOG_BMP_GPS_09_23_B.f_l = (int32_T)
          (prova_LOG_BMP_GPS_09_23_DW.counter_g + 32U);
        if (prova_LOG_BMP_GPS_09_23_DW.counter_g + 32U > 255U) {
          prova_LOG_BMP_GPS_09_23_B.f_l = 255;
        }

        prova_LOG_BMP_GPS_09_23_DW.counter_g = (uint8_T)
          prova_LOG_BMP_GPS_09_23_B.f_l;
      }
    }

    /* End of MATLAB Function: '<S24>/Create_message' */
  }

  /* End of MATLABSystem: '<S22>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S22>/Subsystem2' */

  /* Sum: '<S22>/Sum' */
  prova_LOG_BMP_GPS_09_23_B.num_254 =
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[7] -
    prova_LOG_BMP_GPS_09_23_B.Switch;

  /* Gain: '<S9>/Gain' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain_Gain_b[0] *
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_l[0] =
    prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint32_T)
    prova_LOG_BMP_GPS_09_23_B.RateTransition;

  /* Gain: '<S9>/Gain' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain_Gain_b[1] *
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_l[1] =
    prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint32_T)
    prova_LOG_BMP_GPS_09_23_B.RateTransition;

  /* Gain: '<S9>/Gain' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain_Gain_b[2] * prova_LOG_BMP_GPS_09_23_B.num_254;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_l[2] =
    prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint32_T)
    prova_LOG_BMP_GPS_09_23_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/alt_r'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain_Gain_b[3] *
    prova_LOG_BMP_GPS_09_23_P.alt_r_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_l[3] =
    prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint32_T)
    prova_LOG_BMP_GPS_09_23_B.RateTransition;

  /* Gain: '<S9>/Gain1' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain1_Gain *
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[2];

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[0] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/vel y'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain1_Gain * prova_LOG_BMP_GPS_09_23_P.vely_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[1] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/RC Simulated'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain1_Gain *
    prova_LOG_BMP_GPS_09_23_P.RCSimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[2] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* Gain: '<S9>/Gain2' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition =
    prova_LOG_BMP_GPS_09_23_P.Gain2_Gain_j *
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[4];

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  if (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.RateTransition);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion2 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* SignalConversion generated from: '<S40>/Enable' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !prova_LOG_BMP_GPS_09_23_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  pro_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &prova_LOG_BMP_GPS_09_23_B.One_time_initialization,
    &prova_LOG_BMP_GPS_09_23_DW.One_time_initialization,
    &prova_LOG_BMP_GPS_09_23_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (prova_LOG_BMP_GPS_09_23_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S37>/I2C Read12' */
    if (prova_LOG_BMP_GPS_09_23_DW.obj_ff.SampleTime !=
        prova_LOG_BMP_GPS_09_23_P.t_AP) {
      prova_LOG_BMP_GPS_09_23_DW.obj_ff.SampleTime =
        prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (prova_LOG_BMP_GPS_09_23_DW.obj_ff.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &counter, 1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead
        (prova_LOG_BMP_GPS_09_23_DW.obj_ff.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S37>/I2C Read1' */
    if (prova_LOG_BMP_GPS_09_23_DW.obj_p.SampleTime !=
        prova_LOG_BMP_GPS_09_23_P.t_AP) {
      prova_LOG_BMP_GPS_09_23_DW.obj_p.SampleTime =
        prova_LOG_BMP_GPS_09_23_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (prova_LOG_BMP_GPS_09_23_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &counter, 1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead
        (prova_LOG_BMP_GPS_09_23_DW.obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &prova_LOG_BMP_GPS_09_23_B.output_raw[0], 3U, false, true);
      memcpy((void *)&prova_LOG_BMP_GPS_09_23_B.output[0], (void *)
             &prova_LOG_BMP_GPS_09_23_B.output_raw[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      prova_LOG_BMP_GPS_09_23_B.output[0] = 0U;
      prova_LOG_BMP_GPS_09_23_B.output[1] = 0U;
      prova_LOG_BMP_GPS_09_23_B.output[2] = 0U;
    }

    /* ArithShift: '<S37>/Shift Arithmetic4' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_e);
    if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
        (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
    } else {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
        (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S37>/Shift Arithmetic3' incorporates:
     *  Constant: '<S37>/Constant5'
     */
    prova_LOG_BMP_GPS_09_23_B.UkYk1 = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant5_Value);
    if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.UkYk1) || rtIsInf
        (prova_LOG_BMP_GPS_09_23_B.UkYk1)) {
      prova_LOG_BMP_GPS_09_23_B.UkYk1 = 0.0;
    } else {
      prova_LOG_BMP_GPS_09_23_B.UkYk1 = fmod(prova_LOG_BMP_GPS_09_23_B.UkYk1,
        4.294967296E+9);
    }

    /* ArithShift: '<S37>/Shift Arithmetic1' incorporates:
     *  Constant: '<S37>/Constant6'
     */
    prova_LOG_BMP_GPS_09_23_B.deltafalllimit = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant6_Value);
    if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.deltafalllimit) || rtIsInf
        (prova_LOG_BMP_GPS_09_23_B.deltafalllimit)) {
      prova_LOG_BMP_GPS_09_23_B.deltafalllimit = 0.0;
    } else {
      prova_LOG_BMP_GPS_09_23_B.deltafalllimit = fmod
        (prova_LOG_BMP_GPS_09_23_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S37>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S37>/Shift Arithmetic1'
     *  ArithShift: '<S37>/Shift Arithmetic3'
     *  ArithShift: '<S37>/Shift Arithmetic4'
     *  Constant: '<S37>/Constant10'
     *  Constant: '<S37>/Constant11'
     *  Constant: '<S37>/Constant7'
     *  MATLABSystem: '<S37>/I2C Read1'
     *  Sum: '<S37>/Sum1'
     *  Sum: '<S37>/Sum4'
     *  Sum: '<S37>/Sum5'
     *  Sum: '<S37>/Sum6'
     */
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_d = (int32_T)
      ((((((prova_LOG_BMP_GPS_09_23_P.Constant7_Value_m +
            prova_LOG_BMP_GPS_09_23_B.output[0]) <<
           (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
            -prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint32_T)
            prova_LOG_BMP_GPS_09_23_B.RateTransition)) +
          ((prova_LOG_BMP_GPS_09_23_P.Constant10_Value_i +
            prova_LOG_BMP_GPS_09_23_B.output[1]) <<
           (prova_LOG_BMP_GPS_09_23_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
            -prova_LOG_BMP_GPS_09_23_B.UkYk1 : (int32_T)(uint32_T)
            prova_LOG_BMP_GPS_09_23_B.UkYk1))) +
         prova_LOG_BMP_GPS_09_23_P.Constant11_Value_f) +
        prova_LOG_BMP_GPS_09_23_B.output[2]) >>
       (prova_LOG_BMP_GPS_09_23_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -prova_LOG_BMP_GPS_09_23_B.deltafalllimit : (int32_T)(uint32_T)
        prova_LOG_BMP_GPS_09_23_B.deltafalllimit));

    /* ArithShift: '<S37>/Shift Arithmetic7' incorporates:
     *  Constant: '<S37>/Constant2'
     */
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant2_Value_a);
    if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
        (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
    } else {
      prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
        (prova_LOG_BMP_GPS_09_23_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S37>/Shift Arithmetic6' incorporates:
     *  Constant: '<S37>/Constant3'
     */
    prova_LOG_BMP_GPS_09_23_B.UkYk1 = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_m);
    if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.UkYk1) || rtIsInf
        (prova_LOG_BMP_GPS_09_23_B.UkYk1)) {
      prova_LOG_BMP_GPS_09_23_B.UkYk1 = 0.0;
    } else {
      prova_LOG_BMP_GPS_09_23_B.UkYk1 = fmod(prova_LOG_BMP_GPS_09_23_B.UkYk1,
        4.294967296E+9);
    }

    /* ArithShift: '<S37>/Shift Arithmetic2' incorporates:
     *  Constant: '<S37>/Constant4'
     */
    prova_LOG_BMP_GPS_09_23_B.deltafalllimit = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant4_Value);
    if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.deltafalllimit) || rtIsInf
        (prova_LOG_BMP_GPS_09_23_B.deltafalllimit)) {
      prova_LOG_BMP_GPS_09_23_B.deltafalllimit = 0.0;
    } else {
      prova_LOG_BMP_GPS_09_23_B.deltafalllimit = fmod
        (prova_LOG_BMP_GPS_09_23_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S37>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S37>/Shift Arithmetic2'
     *  ArithShift: '<S37>/Shift Arithmetic6'
     *  ArithShift: '<S37>/Shift Arithmetic7'
     *  Constant: '<S37>/Constant8'
     *  Constant: '<S37>/Constant9'
     *  MATLABSystem: '<S37>/I2C Read12'
     *  Sum: '<S37>/Sum'
     *  Sum: '<S37>/Sum2'
     *  Sum: '<S37>/Sum3'
     */
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_i = (int32_T)
      ((((prova_LOG_BMP_GPS_09_23_P.Constant8_Value_p + rtb_H_mav[0]) <<
         (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint32_T)
          prova_LOG_BMP_GPS_09_23_B.RateTransition)) +
        ((prova_LOG_BMP_GPS_09_23_P.Constant9_Value_m + rtb_H_mav[1]) <<
         (prova_LOG_BMP_GPS_09_23_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
          -prova_LOG_BMP_GPS_09_23_B.UkYk1 : (int32_T)(uint32_T)
          prova_LOG_BMP_GPS_09_23_B.UkYk1))) >>
       (prova_LOG_BMP_GPS_09_23_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -prova_LOG_BMP_GPS_09_23_B.deltafalllimit : (int32_T)(uint32_T)
        prova_LOG_BMP_GPS_09_23_B.deltafalllimit));

    /* S-Function (calc_T): '<S37>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead1,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead2,
       &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_i,
       &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1,
       &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2_d);

    /* S-Function (calc_p): '<S37>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead3,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead4,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead5,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead6,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead7,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead8,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead9,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead10,
       &prova_LOG_BMP_GPS_09_23_B.One_time_initialization.I2CRead11,
       &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_d,
       &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2_d,
       &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant2_Value_o == 1.0) {
    prova_LOG_BMP_GPS_09_23_DW.P_ref =
      prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder1;
  }

  if (prova_LOG_BMP_GPS_09_23_P.Constant_Value_d == 1.0) {
    prova_LOG_BMP_GPS_09_23_DW.P_ref =
      prova_LOG_BMP_GPS_09_23_P.Constant1_Value_l0;
    prova_LOG_BMP_GPS_09_23_DW.rl_up = 20.0;
    prova_LOG_BMP_GPS_09_23_DW.rl_dw = -20.0;
  }

  /* Product: '<S36>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S36>/sample time'
   *
   * About '<S36>/sample time':
   *  y = K where K = ( w * Ts )
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = prova_LOG_BMP_GPS_09_23_DW.rl_up *
    prova_LOG_BMP_GPS_09_23_P.sampletime_WtEt;

  /* Sum: '<S36>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S36>/Delay Input2'
   *
   * Block description for '<S36>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S36>/Delay Input2':
   *
   *  Store in Global RAM
   */
  prova_LOG_BMP_GPS_09_23_B.UkYk1 = prova_LOG_BMP_GPS_09_23_DW.P_ref -
    prova_LOG_BMP_GPS_09_23_DW.DelayInput2_DSTATE;

  /* Product: '<S36>/delta fall limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S36>/sample time'
   *
   * About '<S36>/sample time':
   *  y = K where K = ( w * Ts )
   */
  prova_LOG_BMP_GPS_09_23_B.deltafalllimit = prova_LOG_BMP_GPS_09_23_DW.rl_dw *
    prova_LOG_BMP_GPS_09_23_P.sampletime_WtEt;

  /* Switch: '<S42>/Switch2' incorporates:
   *  RelationalOperator: '<S42>/LowerRelop1'
   *  RelationalOperator: '<S42>/UpperRelop'
   *  Switch: '<S42>/Switch'
   */
  if (prova_LOG_BMP_GPS_09_23_B.UkYk1 > prova_LOG_BMP_GPS_09_23_B.RateTransition)
  {
    prova_LOG_BMP_GPS_09_23_B.UkYk1 = prova_LOG_BMP_GPS_09_23_B.RateTransition;
  } else {
    if (prova_LOG_BMP_GPS_09_23_B.UkYk1 <
        prova_LOG_BMP_GPS_09_23_B.deltafalllimit) {
      /* Switch: '<S42>/Switch' */
      prova_LOG_BMP_GPS_09_23_B.UkYk1 = prova_LOG_BMP_GPS_09_23_B.deltafalllimit;
    }
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Sum: '<S36>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S36>/Delay Input2'
   *
   * Block description for '<S36>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S36>/Delay Input2':
   *
   *  Store in Global RAM
   */
  prova_LOG_BMP_GPS_09_23_DW.DelayInput2_DSTATE +=
    prova_LOG_BMP_GPS_09_23_B.UkYk1;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S36>/Delay Input2'
   *
   * Block description for '<S36>/Delay Input2':
   *
   *  Store in Global RAM
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_b = (real32_T)
    prova_LOG_BMP_GPS_09_23_DW.DelayInput2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S41>/Subsystem1' incorporates:
   *  EnablePort: '<S43>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (prova_LOG_BMP_GPS_09_23_P.Constant2_Value_o > 0.0) {
    /* Inport: '<S43>/T' */
    prova_LOG_BMP_GPS_09_23_B.T = prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S41>/Subsystem1' */

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S41>/NotEqual'
   *  Switch: '<S41>/Switch'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant_Value_j !=
      prova_LOG_BMP_GPS_09_23_P.T_0_Value) {
    prova_LOG_BMP_GPS_09_23_B.UkYk1 = prova_LOG_BMP_GPS_09_23_P.T_0_Value;
  } else if (prova_LOG_BMP_GPS_09_23_B.T >
             prova_LOG_BMP_GPS_09_23_P.Switch_Threshold_k) {
    /* Switch: '<S41>/Switch' */
    prova_LOG_BMP_GPS_09_23_B.UkYk1 = prova_LOG_BMP_GPS_09_23_B.T;
  } else {
    prova_LOG_BMP_GPS_09_23_B.UkYk1 = prova_LOG_BMP_GPS_09_23_P.T_0_Value;
  }

  /* End of Switch: '<S41>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  prova_LOG_BMP_GPS_09_23_B.h_ = (real32_T)log((real32_T)
    prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder1 /
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_b) * -8333.33301F;

  /* DataTypeConversion: '<S18>/Data Type Conversion3' incorporates:
   *  Constant: '<S18>/RC simulated'
   *  Constant: '<S18>/TAS simulated'
   *  Constant: '<S18>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_m[0] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.TASsimulated_Value;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_m[1] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.vsimulated_Value;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_m[2] =
    prova_LOG_BMP_GPS_09_23_B.h_;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_m[3] = (real32_T)
    prova_LOG_BMP_GPS_09_23_P.RCsimulated_Value;

  /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
   *  Constant: '<S18>/ Heading simulated'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Headingsimulated_Value);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion4' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion4_i = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (int16_T)(uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion5' incorporates:
   *  Constant: '<S18>/Rpm simulated'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Rpmsimulated_Value);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion5' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion5 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* Gain: '<S31>/Gain2' incorporates:
   *  Constant: '<S16>/Manetta Simulated'
   */
  prova_LOG_BMP_GPS_09_23_B.deltafalllimit =
    prova_LOG_BMP_GPS_09_23_P.Gain2_Gain_o *
    prova_LOG_BMP_GPS_09_23_P.ManettaSimulated_Value;

  /* Sum: '<S31>/Sum' incorporates:
   *  Constant: '<S16>/Equilibratore Simulated'
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.Sum = prova_LOG_BMP_GPS_09_23_P.Gain_Gain_o *
    prova_LOG_BMP_GPS_09_23_P.EquilibratoreSimulated_Value +
    prova_LOG_BMP_GPS_09_23_P.Constant2_Value_d;

  /* Sum: '<S31>/Sum1' incorporates:
   *  Constant: '<S16>/Alettoni Simulated'
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S33>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.Sum1 = prova_LOG_BMP_GPS_09_23_P.Gain_Gain_n *
    prova_LOG_BMP_GPS_09_23_P.AlettoniSimulated_Value +
    prova_LOG_BMP_GPS_09_23_P.Constant2_Value_d;

  /* Sum: '<S31>/Sum2' incorporates:
   *  Constant: '<S16>/Timone Simulated'
   *  Constant: '<S31>/Constant2'
   *  Gain: '<S34>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.Sum2 = prova_LOG_BMP_GPS_09_23_P.Gain_Gain_l *
    prova_LOG_BMP_GPS_09_23_P.TimoneSimulated_Value +
    prova_LOG_BMP_GPS_09_23_P.Constant2_Value_d;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  prova_LOG_BMP_GPS_09_23_B.Gain3 = prova_LOG_BMP_GPS_09_23_P.Gain_Gain_bp *
    prova_LOG_BMP_GPS_09_23_P.Constant2_Value_p;

  /* Saturate: '<S16>/Saturation' */
  if (prova_LOG_BMP_GPS_09_23_B.Gain3 >
      prova_LOG_BMP_GPS_09_23_P.Saturation_UpperSat) {
    prova_LOG_BMP_GPS_09_23_B.Gain3 =
      prova_LOG_BMP_GPS_09_23_P.Saturation_UpperSat;
  } else {
    if (prova_LOG_BMP_GPS_09_23_B.Gain3 <
        prova_LOG_BMP_GPS_09_23_P.Saturation_LowerSat) {
      prova_LOG_BMP_GPS_09_23_B.Gain3 =
        prova_LOG_BMP_GPS_09_23_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant_Value_g < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant_Value_g);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant_Value_g);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[0] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.deltafalllimit < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.deltafalllimit);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.deltafalllimit);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[1] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.Sum < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.Sum);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.Sum);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[2] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.Sum1 < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.Sum1);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.Sum1);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[3] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.Sum2 < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.Sum2);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.Sum2);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[4] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[0] < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[0]);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[0]);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[5] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[1] < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[1]);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[1]);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[6] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  if (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[2] < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[2]);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_d[2]);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[7] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_BMP_GPS_09_23_B.Gain3 < 0.0) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = ceil
      (prova_LOG_BMP_GPS_09_23_B.Gain3);
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
      (prova_LOG_BMP_GPS_09_23_B.Gain3);
  }

  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_BMP_GPS_09_23_B.Heading[8] = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  prova_LOG_BMP_GPS_09_23_B.Memory_i =
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_c2;

  /* DataTypeConversion: '<S2>/Data Type Conversion4' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion4 = (real32_T)
    prova_LOG_BMP_GPS_09_23_B.UkYk1;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_k = (real32_T)
    (prova_LOG_BMP_GPS_09_23_P.PatohPa_Gain * (real_T)
     prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_b = (real32_T)
    (prova_LOG_BMP_GPS_09_23_P.PatohPa1_Gain *
     prova_LOG_BMP_GPS_09_23_P.Constant2_Value_l);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor
    (prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1);
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion2_d = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&prova_LOG_BMP_GPS_09_23_B.iflogic,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3,
     &prova_LOG_BMP_GPS_09_23_P.SIUAVuint8_Value,
     &prova_LOG_BMP_GPS_09_23_B.GC_info[0],
     &prova_LOG_BMP_GPS_09_23_B.Val_out_MAV[0],
     &prova_LOG_BMP_GPS_09_23_B.WP_info[0], &prova_LOG_BMP_GPS_09_23_B.WP_param
     [0], &prova_LOG_BMP_GPS_09_23_B.onboard[0],
     &prova_LOG_BMP_GPS_09_23_B.LVDE[0], &prova_LOG_BMP_GPS_09_23_B.B_Current,
     &prova_LOG_BMP_GPS_09_23_B.B_Remaining,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[0],
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_j[0],
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1[0],
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_l[0],
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[0],
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion2,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_m[0],
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion4_i,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion5,
     &prova_LOG_BMP_GPS_09_23_B.Heading[0], &prova_LOG_BMP_GPS_09_23_B.Memory_i,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_b,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o14,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion4,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o15,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_k,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_b,
     &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion2_d,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o5[0],
     &prova_LOG_BMP_GPS_09_23_P.Constant4_Value_g,
     &prova_LOG_BMP_GPS_09_23_P.Constant5_Value_j,
     &prova_LOG_BMP_GPS_09_23_P.Constant10_Value_f, ((const uint16_T*)
      &prova_LOG_BMP_GPS_09_23_U16GND),
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o1_k,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o2_i[0],
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o3,
     &prova_LOG_BMP_GPS_09_23_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (prova_LOG_BMP_GPS_09_23_B.SFunction_o1_k > 0) {
    /* Chart: '<S8>/Chart' */
    if (prova_LOG_BMP_GPS_09_23_DW.is_active_c9_prova_LOG_BMP_GPS_ == 0U) {
      prova_LOG_BMP_GPS_09_23_DW.is_active_c9_prova_LOG_BMP_GPS_ = 1U;
      prova_LOG_BMP_GPS_09_23_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (prova_LOG_BMP_GPS_09_23_DW.obj_f.Protocol !=
            prova_LOG_BMP_GPS_09_23_P.SerialTransmit_Protocol) {
          prova_LOG_BMP_GPS_09_23_DW.obj_f.Protocol =
            prova_LOG_BMP_GPS_09_23_P.SerialTransmit_Protocol;
        }

        counter =
          prova_LOG_BMP_GPS_09_23_B.SFunction_o2_i[prova_LOG_BMP_GPS_09_23_DW.i
          - 1];
        MW_Serial_write(prova_LOG_BMP_GPS_09_23_DW.obj_f.port, &counter, 1.0,
                        prova_LOG_BMP_GPS_09_23_DW.obj_f.dataSizeInBytes,
                        prova_LOG_BMP_GPS_09_23_DW.obj_f.sendModeEnum,
                        prova_LOG_BMP_GPS_09_23_DW.obj_f.dataType,
                        prova_LOG_BMP_GPS_09_23_DW.obj_f.sendFormatEnum, 2.0,
                        '\x00');
        if (prova_LOG_BMP_GPS_09_23_DW.i <
            prova_LOG_BMP_GPS_09_23_B.SFunction_o3) {
          prova_LOG_BMP_GPS_09_23_B.f_l = prova_LOG_BMP_GPS_09_23_DW.i + 1;
          if (prova_LOG_BMP_GPS_09_23_DW.i + 1 > 255) {
            prova_LOG_BMP_GPS_09_23_B.f_l = 255;
          }

          prova_LOG_BMP_GPS_09_23_DW.i = (uint8_T)prova_LOG_BMP_GPS_09_23_B.f_l;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      prova_LOG_BMP_GPS_09_23_DW.i = 1U;
    }

    /* End of Chart: '<S8>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion6[0] = (real32_T)
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[0];
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion6[1] = (real32_T)
    prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[1];
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion6[2] = (real32_T)
    prova_LOG_BMP_GPS_09_23_B.num_254;
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion6[3] =
    prova_LOG_BMP_GPS_09_23_B.h_;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant4'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m *
     prova_LOG_BMP_GPS_09_23_P.Constant4_Value_n));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[0] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m *
     prova_LOG_BMP_GPS_09_23_P.Constant12_Value));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[1] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant5'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m *
     prova_LOG_BMP_GPS_09_23_P.Constant5_Value_i));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[2] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant6'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_lz *
     prova_LOG_BMP_GPS_09_23_P.Constant6_Value_g *
     prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[3] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant8'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_j *
     prova_LOG_BMP_GPS_09_23_P.Constant8_Value *
     prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[4] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant7'
   *  Gain: '<S15>/Gain'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_br *
     prova_LOG_BMP_GPS_09_23_P.Constant7_Value *
     prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[5] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant9'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m *
     prova_LOG_BMP_GPS_09_23_P.Constant9_Value));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[6] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant10'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m *
     prova_LOG_BMP_GPS_09_23_P.Constant10_Value));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[7] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant11'
   *  Gain: '<S2>/Gain'
   */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor((real32_T)
    (prova_LOG_BMP_GPS_09_23_P.Gain_Gain_m *
     prova_LOG_BMP_GPS_09_23_P.Constant11_Value));
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[8] = (int16_T)
    (prova_LOG_BMP_GPS_09_23_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_BMP_GPS_09_23_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_BMP_GPS_09_23_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion10' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion10 =
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion2;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion11[0] = (uint16_T)
    ((prova_LOG_BMP_GPS_09_23_P.Gain2_Gain_p *
      prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[0]) >> 8);
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion11[1] = (uint16_T)
    ((prova_LOG_BMP_GPS_09_23_P.Gain2_Gain_p *
      prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[1]) >> 8);
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion11[2] = (uint16_T)
    ((prova_LOG_BMP_GPS_09_23_P.Gain2_Gain_p *
      prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_l[2]) >> 8);

  /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
   *  Constant: '<S2>/Constant'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant_Value_or);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion12 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion13' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant3_Value_mm);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion13 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant7_Value_l);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion14 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant8_Value_m);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion15 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion21' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant9_Value_b);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion21' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion21 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion20' incorporates:
   *  Constant: '<S2>/Constant6'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant6_Value_k);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion20 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion19' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Constant1_Value_ja);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion19 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion18' incorporates:
   *  Gain: '<S2>/Gain3'
   */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_P.Gain3_Gain * prova_LOG_BMP_GPS_09_23_B.UkYk1);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion18 = (uint16_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)
     (uint16_T)prova_LOG_BMP_GPS_09_23_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  prova_LOG_BMP_GPS_09_23_B.RateTransition = floor
    (prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[5]);
  if (rtIsNaN(prova_LOG_BMP_GPS_09_23_B.RateTransition) || rtIsInf
      (prova_LOG_BMP_GPS_09_23_B.RateTransition)) {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = 0.0;
  } else {
    prova_LOG_BMP_GPS_09_23_B.RateTransition = fmod
      (prova_LOG_BMP_GPS_09_23_B.RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion8[0] = (uint8_T)
    (prova_LOG_BMP_GPS_09_23_B.RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-prova_LOG_BMP_GPS_09_23_B.RateTransition : (int32_T)(uint8_T)
     prova_LOG_BMP_GPS_09_23_B.RateTransition);
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion8[1] =
    prova_LOG_BMP_GPS_09_23_B.indice_dimario;

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  prova_LOG_BMP_GPS_09_23_B.f = (real32_T)floor
    (prova_LOG_BMP_GPS_09_23_B.DataTypeConversion_k);
  if (rtIsNaNF(prova_LOG_BMP_GPS_09_23_B.f) || rtIsInfF
      (prova_LOG_BMP_GPS_09_23_B.f)) {
    prova_LOG_BMP_GPS_09_23_B.f = 0.0F;
  } else {
    prova_LOG_BMP_GPS_09_23_B.f = (real32_T)fmod(prova_LOG_BMP_GPS_09_23_B.f,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  prova_LOG_BMP_GPS_09_23_B.DataTypeConversion16 = prova_LOG_BMP_GPS_09_23_B.f <
    0.0F ? (uint32_T)-(int32_T)(uint32_T)-prova_LOG_BMP_GPS_09_23_B.f :
    (uint32_T)prova_LOG_BMP_GPS_09_23_B.f;

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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion6[0],
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion3_k[0],
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
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion10, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion11[0],
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
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion12, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion13, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion14, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion15, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion21, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion20, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion19, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion18, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion8[0],
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

    /* Packing the values of Input 15 */
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_B.DataTypeConversion16, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_BMP_GPS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_BMP_GPS_09_23_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S2>/Serial Transmit1' */
  if (prova_LOG_BMP_GPS_09_23_DW.obj.Protocol !=
      prova_LOG_BMP_GPS_09_23_P.SerialTransmit1_Protocol) {
    prova_LOG_BMP_GPS_09_23_DW.obj.Protocol =
      prova_LOG_BMP_GPS_09_23_P.SerialTransmit1_Protocol;
  }

  memcpy(&prova_LOG_BMP_GPS_09_23_B.dataIn[0],
         &prova_LOG_BMP_GPS_09_23_B.BytePack[0], 67U * sizeof(uint8_T));
  MW_Serial_write(prova_LOG_BMP_GPS_09_23_DW.obj.port,
                  &prova_LOG_BMP_GPS_09_23_B.dataIn[0], 67.0,
                  prova_LOG_BMP_GPS_09_23_DW.obj.dataSizeInBytes,
                  prova_LOG_BMP_GPS_09_23_DW.obj.sendModeEnum,
                  prova_LOG_BMP_GPS_09_23_DW.obj.dataType,
                  prova_LOG_BMP_GPS_09_23_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S2>/Serial Transmit1' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&prova_LOG_BMP_GPS_09_23_DW.Memory4_PreviousInput[0],
         &prova_LOG_BMP_GPS_09_23_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&prova_LOG_BMP_GPS_09_23_P.Constant1_Value_i,
    &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1_g[0],
    &prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o2,
    &prova_LOG_BMP_GPS_09_23_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&prova_LOG_BMP_GPS_09_23_DW.Memory5_PreviousInput[0],
         &prova_LOG_BMP_GPS_09_23_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[0] =
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[0];
  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[1] =
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[1];
  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[2] =
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[2];
  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[3] =
    prova_LOG_BMP_GPS_09_23_B.DataTypeConversion1_n[3];

  /* Update for Memory: '<S1>/Memory' */
  for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 8;
       prova_LOG_BMP_GPS_09_23_B.i++) {
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_c[prova_LOG_BMP_GPS_09_23_B.i]
      = prova_LOG_BMP_GPS_09_23_B.SFunction_o11[prova_LOG_BMP_GPS_09_23_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[0] = (uint8_T)AP_mode_idx_0;
  prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[1] = (uint8_T)AP_mode_idx_1;
  for (prova_LOG_BMP_GPS_09_23_B.i = 0; prova_LOG_BMP_GPS_09_23_B.i < 7;
       prova_LOG_BMP_GPS_09_23_B.i++) {
    prova_LOG_BMP_GPS_09_23_B.f = rt_roundf_snf
      (prova_LOG_BMP_GPS_09_23_DW.riferimenti[prova_LOG_BMP_GPS_09_23_B.i]);
    if (prova_LOG_BMP_GPS_09_23_B.f < 256.0F) {
      if (prova_LOG_BMP_GPS_09_23_B.f >= 0.0F) {
        prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[prova_LOG_BMP_GPS_09_23_B.i
          + 2] = (uint8_T)prova_LOG_BMP_GPS_09_23_B.f;
      } else {
        prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[prova_LOG_BMP_GPS_09_23_B.i
          + 2] = 0U;
      }
    } else {
      prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[prova_LOG_BMP_GPS_09_23_B.i
        + 2] = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  prova_LOG_BMP_GPS_09_23_DW.UnitDelay_DSTATE =
    prova_LOG_BMP_GPS_09_23_P.Constant3_Value_g;

  /* Update for Memory: '<S2>/Memory' */
  prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_c2 =
    prova_LOG_BMP_GPS_09_23_B.SFunction_o4;
}

/* Model step function for TID1 */
void prova_LOG_BMP_GPS_09_23_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S29>/Add2' incorporates:
   *  Constant: '<S29>/Constant4'
   *  Constant: '<S29>/Constant5'
   *  Memory: '<S29>/Memory2'
   */
  prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput +=
    prova_LOG_BMP_GPS_09_23_P.Constant4_Value_f +
    prova_LOG_BMP_GPS_09_23_P.Constant5_Value_e;

  /* Switch: '<S29>/Switch1' */
  if (prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput >
      prova_LOG_BMP_GPS_09_23_P.Switch1_Threshold) {
    /* Sum: '<S29>/Add2' incorporates:
     *  Constant: '<S29>/Constant4'
     */
    prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput =
      prova_LOG_BMP_GPS_09_23_P.Constant4_Value_f;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* RateTransition: '<S29>/Rate Transition' */
  prova_LOG_BMP_GPS_09_23_DW.RateTransition_Buffer0 =
    prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void prova_LOG_BMP_GPS_09_23_initialize(void)
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
    memcpy(&prova_LOG_BMP_GPS_09_23_DW.Memory4_PreviousInput[0],
           &prova_LOG_BMP_GPS_09_23_P.Memory4_InitialCondition[0], 300U * sizeof
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
          prova_LOG_BMP_GPS_09_23_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      prova_LOG_BMP_GPS_09_23_DW.Memory5_PreviousInput[i] =
        prova_LOG_BMP_GPS_09_23_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[0] =
      prova_LOG_BMP_GPS_09_23_P.Memory1_InitialCondition_j;
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput_c[1] =
      prova_LOG_BMP_GPS_09_23_P.Memory1_InitialCondition_j;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[0] =
      prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_i;
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[1] =
      prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_i;
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[2] =
      prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_i;
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_k[3] =
      prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_i;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    prova_LOG_BMP_GPS_09_23_DW.Memory3_PreviousInput =
      prova_LOG_BMP_GPS_09_23_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_c[i] =
        prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_lq;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput_i[i] =
        prova_LOG_BMP_GPS_09_23_P.Memory2_InitialCondition_j[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S29>/Rate Transition' */
    prova_LOG_BMP_GPS_09_23_DW.RateTransition_Buffer0 =
      prova_LOG_BMP_GPS_09_23_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S29>/Switch' incorporates:
     *  Memory: '<S29>/Memory1'
     */
    prova_LOG_BMP_GPS_09_23_DW.Memory1_PreviousInput =
      prova_LOG_BMP_GPS_09_23_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S29>/Add' incorporates:
     *  Memory: '<S29>/Memory'
     */
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput =
      prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    prova_LOG_BMP_GPS_09_23_DW.UnitDelay_DSTATE =
      prova_LOG_BMP_GPS_09_23_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S36>/Delay Input2'
     *
     * Block description for '<S36>/Delay Input2':
     *
     *  Store in Global RAM
     */
    prova_LOG_BMP_GPS_09_23_DW.DelayInput2_DSTATE =
      prova_LOG_BMP_GPS_09_23_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_c2 =
      prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition_m;

    /* InitializeConditions for Sum: '<S29>/Add2' incorporates:
     *  Memory: '<S29>/Memory2'
     */
    prova_LOG_BMP_GPS_09_23_DW.Memory2_PreviousInput =
      prova_LOG_BMP_GPS_09_23_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&prova_LOG_BMP_GPS_09_23_DW.riferimenti[0], &tmp[0], sizeof(real32_T)
           << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
     *  SubSystem: '<S20>/sendbyte'
     */
    /* Start for MATLABSystem: '<S21>/Serial Transmit' */
    prova_LOG_BMP_GPS_09_23_DW.obj_f.matlabCodegenIsDeleted = false;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.Protocol =
      prova_LOG_BMP_GPS_09_23_P.SerialTransmit_Protocol;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.isInitialized = 1;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.port = 2.0;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.dataSizeInBytes = 1.0;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.dataType = 0.0;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.sendModeEnum = 0.0;
    prova_LOG_BMP_GPS_09_23_DW.obj_f.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(prova_LOG_BMP_GPS_09_23_DW.obj_f.port);
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
    prova_LOG_BMP_GPS_09_23_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S21>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S22>/Subsystem1' */
    /* SystemInitialize for Switch: '<S23>/Switch' incorporates:
     *  Outport: '<S23>/h_to_subtract'
     */
    prova_LOG_BMP_GPS_09_23_B.Switch =
      prova_LOG_BMP_GPS_09_23_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S22>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S22>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S24>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S26>/Memory' */
      prova_LOG_BMP_GPS_09_23_DW.Memory_PreviousInput_e[i] =
        prova_LOG_BMP_GPS_09_23_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S26>/Complex to Real-Imag' incorporates:
       *  Outport: '<S26>/Outport'
       */
      prova_LOG_BMP_GPS_09_23_B.ComplextoRealImag[i] =
        prova_LOG_BMP_GPS_09_23_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S26>/mario' */
    prova_LOG_BMP_GPS_09_23_B.indice_dimario =
      prova_LOG_BMP_GPS_09_23_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S24>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S22>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S37>/I2C Read12' */
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.matlabCodegenIsDeleted = true;
    obj = &prova_LOG_BMP_GPS_09_23_DW.obj_ff;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.DefaultMaximumBusSpeedInHz = 400000.0;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.isInitialized = 0;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.matlabCodegenIsDeleted = false;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.SampleTime =
      prova_LOG_BMP_GPS_09_23_P.t_AP;
    obj = &prova_LOG_BMP_GPS_09_23_DW.obj_ff;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.isSetupComplete = false;
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.isInitialized = 1;
    prova_LOG_BMP_GPS_09_23_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (prova_LOG_BMP_GPS_09_23_B.i2cname, 0);
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.BusSpeed = 100000U;
    varargin_1 = prova_LOG_BMP_GPS_09_23_DW.obj_ff.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.isSetupComplete = true;

    /* Start for MATLABSystem: '<S37>/I2C Read1' */
    prova_LOG_BMP_GPS_09_23_DW.obj_p.matlabCodegenIsDeleted = true;
    obj = &prova_LOG_BMP_GPS_09_23_DW.obj_p;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.isInitialized = 0;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.matlabCodegenIsDeleted = false;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.SampleTime = prova_LOG_BMP_GPS_09_23_P.t_AP;
    obj = &prova_LOG_BMP_GPS_09_23_DW.obj_p;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.isSetupComplete = false;
    prova_LOG_BMP_GPS_09_23_DW.obj_p.isInitialized = 1;
    prova_LOG_BMP_GPS_09_23_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (prova_LOG_BMP_GPS_09_23_B.i2cname, 0);
    prova_LOG_BMP_GPS_09_23_DW.obj_p.BusSpeed = 100000U;
    varargin_1 = prova_LOG_BMP_GPS_09_23_DW.obj_p.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    prova_LOG_BMP_GPS_09_23_DW.obj_p.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S37>/S-Function Builder' incorporates:
     *  Outport: '<S37>/T'
     */
    prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder_o1 =
      prova_LOG_BMP_GPS_09_23_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S37>/S-Function Builder1' incorporates:
     *  Outport: '<S37>/p'
     */
    prova_LOG_BMP_GPS_09_23_B.SFunctionBuilder1 = prova_LOG_BMP_GPS_09_23_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    prova_LOG_BMP_GPS_09_23_DW.P_ref = 101325.0;
    prova_LOG_BMP_GPS_09_23_DW.rl_up = 300.0;
    prova_LOG_BMP_GPS_09_23_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init
      (&prova_LOG_BMP_GPS_09_23_B.One_time_initialization,
       &prova_LOG_BMP_GPS_09_23_DW.One_time_initialization,
       &prova_LOG_BMP_GPS_09_23_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem1' */
    /* SystemInitialize for Outport: '<S43>/T_0' incorporates:
     *  Inport: '<S43>/T'
     */
    prova_LOG_BMP_GPS_09_23_B.T = prova_LOG_BMP_GPS_09_23_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem1' */

    /* Start for MATLABSystem: '<S22>/Serial Receive1' */
    prova_LOG_BMP_GPS_09_23_DW.obj_e.matlabCodegenIsDeleted = false;
    prova_LOG_BMP_GPS_09_23_DW.obj_e.Protocol =
      prova_LOG_BMP_GPS_09_23_P.SerialReceive1_Protocol;
    prova_LOG_BMP_GPS_09_23_DW.obj_e.isInitialized = 1;
    prova_LOG_BMP_GPS_09_23_DW.obj_e.DataTypeWidth = 1U;
    if (prova_LOG_BMP_GPS_09_23_DW.obj_e.DataTypeWidth > 2047) {
      prova_LOG_BMP_GPS_09_23_DW.obj_e.DataSizeInBytes = MAX_uint16_T;
    } else {
      prova_LOG_BMP_GPS_09_23_DW.obj_e.DataSizeInBytes = (uint16_T)
        (prova_LOG_BMP_GPS_09_23_DW.obj_e.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    prova_LOG_BMP_GPS_09_23_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S22>/Serial Receive1' */

    /* Start for MATLABSystem: '<S2>/Serial Transmit1' */
    prova_LOG_BMP_GPS_09_23_DW.obj.matlabCodegenIsDeleted = false;
    prova_LOG_BMP_GPS_09_23_DW.obj.Protocol =
      prova_LOG_BMP_GPS_09_23_P.SerialTransmit1_Protocol;
    prova_LOG_BMP_GPS_09_23_DW.obj.isInitialized = 1;
    prova_LOG_BMP_GPS_09_23_DW.obj.port = 0.0;
    prova_LOG_BMP_GPS_09_23_DW.obj.dataSizeInBytes = 1.0;
    prova_LOG_BMP_GPS_09_23_DW.obj.dataType = 0.0;
    prova_LOG_BMP_GPS_09_23_DW.obj.sendModeEnum = 0.0;
    prova_LOG_BMP_GPS_09_23_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(prova_LOG_BMP_GPS_09_23_DW.obj.port);
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
    prova_LOG_BMP_GPS_09_23_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit1' */
  }
}

/* Model terminate function */
void prova_LOG_BMP_GPS_09_23_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S22>/Serial Receive1' */
  if (!prova_LOG_BMP_GPS_09_23_DW.obj_e.matlabCodegenIsDeleted) {
    prova_LOG_BMP_GPS_09_23_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S22>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term
    (&prova_LOG_BMP_GPS_09_23_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S37>/I2C Read12' */
  obj = &prova_LOG_BMP_GPS_09_23_DW.obj_ff;
  if (!prova_LOG_BMP_GPS_09_23_DW.obj_ff.matlabCodegenIsDeleted) {
    prova_LOG_BMP_GPS_09_23_DW.obj_ff.matlabCodegenIsDeleted = true;
    if ((prova_LOG_BMP_GPS_09_23_DW.obj_ff.isInitialized == 1) &&
        prova_LOG_BMP_GPS_09_23_DW.obj_ff.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S37>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S37>/I2C Read1' */
  obj = &prova_LOG_BMP_GPS_09_23_DW.obj_p;
  if (!prova_LOG_BMP_GPS_09_23_DW.obj_p.matlabCodegenIsDeleted) {
    prova_LOG_BMP_GPS_09_23_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((prova_LOG_BMP_GPS_09_23_DW.obj_p.isInitialized == 1) &&
        prova_LOG_BMP_GPS_09_23_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S37>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S20>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S21>/Serial Transmit' */
  if (!prova_LOG_BMP_GPS_09_23_DW.obj_f.matlabCodegenIsDeleted) {
    prova_LOG_BMP_GPS_09_23_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S21>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
  if (!prova_LOG_BMP_GPS_09_23_DW.obj.matlabCodegenIsDeleted) {
    prova_LOG_BMP_GPS_09_23_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
