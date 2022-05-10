/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LOG_DATI_GPS_BMP_07_09.c
 *
 * Code generated for Simulink model 'LOG_DATI_GPS_BMP_07_09'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jul  9 17:16:27 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LOG_DATI_GPS_BMP_07_09.h"
#include "LOG_DATI_GPS_BMP_07_09_private.h"

const uint16_T LOG_DATI_GPS_BMP_07_09_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_LOG_DATI_GPS_BMP_07_09_T LOG_DATI_GPS_BMP_07_09_B;

/* Block states (default storage) */
DW_LOG_DATI_GPS_BMP_07_09_T LOG_DATI_GPS_BMP_07_09_DW;

/* Real-time model */
static RT_MODEL_LOG_DATI_GPS_BMP_07__T LOG_DATI_GPS_BMP_07_09_M_;
RT_MODEL_LOG_DATI_GPS_BMP_07__T *const LOG_DATI_GPS_BMP_07_09_M =
  &LOG_DATI_GPS_BMP_07_09_M_;

/* Forward declaration for local functions */
static void LOG_DATI_GPS_BMP_07_09_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T LOG_DATI_GPS_BMP_07_ifWhileCond(const boolean_T x[100]);
static void LOG_DATI_GPS_BMP_07_09_eml_find(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static boolean_T LOG_DATI_GPS_BMP__ifWhileCond_k(const boolean_T x[5]);
static void LOG_DATI_GPS_BMP_07__eml_find_e(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void LOG_DATI_GPS_BMP__readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T LOG_DATI_GPS_BMP_07__copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T LOG_DATI_GPS_BMP_0_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void LOG_DATI_GPS_BMP_07_0_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T LOG_DATI_GPS_BMP_07__str2double(const char_T s[2]);
static boolean_T LOG_DATI_GPS_BMP_0_copydigits_g(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void LOG_DATI_GPS_BMP_07_readfloat_i(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T LOG_DATI_GPS_BMP_0_str2double_i(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T LOG_DATI_GPS_BMP_07__isUnitImag(const char_T s[3], int32_T k);
static void LOG_DATI_GPS_BM_readNonFinite_e(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T LOG_DATI_GPS_BMP__copydigits_gt(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T LOG_DATI_GPS_BMP_copyexponent_g(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void LOG_DATI_GPS_BMP_0_readfloat_iz(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T LOG_DATI_GPS_BMP__str2double_i2(const char_T s[3]);
static void LOG_DATI_GPS_B_readNonFinite_ec(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T LOG_DATI_GPS_BMP_copydigits_gt3(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T LOG_DATI_GPS_BM_copyexponent_gr(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void LOG_DATI_GPS_BMP__readfloat_izz(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T LOG_DATI_GPS_BMP_str2double_i2v(char_T s);
static real_T LOG_DATI_GPS_BMP_07_09_hex2dec(const char_T s[2]);
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
void LOG_DATI_GPS_BMP_07_09_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(LOG_DATI_GPS_BMP_07_09_M, 1));
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
  (LOG_DATI_GPS_BMP_07_09_M->Timing.TaskCounters.TID[1])++;
  if ((LOG_DATI_GPS_BMP_07_09_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    LOG_DATI_GPS_BMP_07_09_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_LOG_T *localB,
  DW_One_time_initialization_LO_T *localDW, P_One_time_initialization_LOG_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S36>/I2C Read' */
  localDW->obj_n0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n0;
  localDW->obj_n0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n0.isInitialized = 0;
  localDW->obj_n0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n0.matlabCodegenIsDeleted = false;
  localDW->obj_n0.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_n0;
  localDW->obj_n0.isSetupComplete = false;
  localDW->obj_n0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read1' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read2' */
  localDW->obj_ba.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ba;
  localDW->obj_ba.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ba.isInitialized = 0;
  localDW->obj_ba.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ba.matlabCodegenIsDeleted = false;
  localDW->obj_ba.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_ba;
  localDW->obj_ba.isSetupComplete = false;
  localDW->obj_ba.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ba.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ba.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ba.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read3' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read4' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read5' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read6' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read7' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read8' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read10' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Read11' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S36>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S36>/I2C Write2' */
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

  /* Start for MATLABSystem: '<S36>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S36>/I2C Read12' */
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

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read' incorporates:
   *  Outport: '<S36>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read1' incorporates:
   *  Outport: '<S36>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read2' incorporates:
   *  Outport: '<S36>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read3' incorporates:
   *  Outport: '<S36>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read4' incorporates:
   *  Outport: '<S36>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read5' incorporates:
   *  Outport: '<S36>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read6' incorporates:
   *  Outport: '<S36>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read7' incorporates:
   *  Outport: '<S36>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read8' incorporates:
   *  Outport: '<S36>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read9' incorporates:
   *  Outport: '<S36>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read10' incorporates:
   *  Outport: '<S36>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S36>/I2C Read11' incorporates:
   *  Outport: '<S36>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S36>/Byte Unpack' incorporates:
     *  Outport: '<S36>/pwm_max_min'
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
   *  EnablePort: '<S36>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S36>/I2C Write3' incorporates:
     *  ArithShift: '<S36>/Shift Arithmetic1'
     *  Constant: '<S36>/registro memoria2 '
     *  DataTypeConversion: '<S36>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S36>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S36>/I2C Read' */
    if (localDW->obj_n0.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_n0.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S36>/I2C Read' */

    /* MATLABSystem: '<S36>/I2C Read1' */
    if (localDW->obj_d.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_d.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read1' */

    /* MATLABSystem: '<S36>/I2C Read2' */
    if (localDW->obj_ba.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_ba.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read2' */

    /* MATLABSystem: '<S36>/I2C Read3' */
    if (localDW->obj_o.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_o.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S36>/I2C Read3' */

    /* MATLABSystem: '<S36>/I2C Read4' */
    if (localDW->obj_i.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_i.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read4' */

    /* MATLABSystem: '<S36>/I2C Read5' */
    if (localDW->obj_n.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_n.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read5' */

    /* MATLABSystem: '<S36>/I2C Read6' */
    if (localDW->obj_m.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_m.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read6' */

    /* MATLABSystem: '<S36>/I2C Read7' */
    if (localDW->obj_b.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_b.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read7' */

    /* MATLABSystem: '<S36>/I2C Read8' */
    if (localDW->obj_l.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_l.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read8' */

    /* MATLABSystem: '<S36>/I2C Read9' */
    if (localDW->obj.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read9' */

    /* MATLABSystem: '<S36>/I2C Read10' */
    if (localDW->obj_f.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_f.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read10' */

    /* MATLABSystem: '<S36>/I2C Read11' */
    if (localDW->obj_p.SampleTime != LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      localDW->obj_p.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
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
      /* MATLABSystem: '<S36>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S36>/I2C Read11' */

    /* MATLABSystem: '<S36>/I2C Write1' incorporates:
     *  Constant: '<S36>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S36>/I2C Write2' incorporates:
     *  Constant: '<S36>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_n4.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S36>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_ff.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S36>/I2C Read12' */
    if (localDW->obj_h.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_h.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S36>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S36>/Byte Unpack' */

    /* Unpack: <S36>/Byte Unpack */
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
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S36>/I2C Read' */
  obj = &localDW->obj_n0;
  if (!localDW->obj_n0.matlabCodegenIsDeleted) {
    localDW->obj_n0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n0.isInitialized == 1) && localDW->obj_n0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read1' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read2' */
  obj = &localDW->obj_ba;
  if (!localDW->obj_ba.matlabCodegenIsDeleted) {
    localDW->obj_ba.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ba.isInitialized == 1) && localDW->obj_ba.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read3' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read4' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read5' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read6' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read7' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read8' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read10' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read11' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S36>/I2C Write1' */
  obj_0 = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S36>/I2C Write2' */
  obj_0 = &localDW->obj_n4;
  if (!localDW->obj_n4.matlabCodegenIsDeleted) {
    localDW->obj_n4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n4.isInitialized == 1) && localDW->obj_n4.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S36>/I2C Write3' */
  obj_0 = &localDW->obj_ff;
  if (!localDW->obj_ff.matlabCodegenIsDeleted) {
    localDW->obj_ff.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ff.isInitialized == 1) && localDW->obj_ff.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S36>/I2C Read12' */
  obj = &localDW->obj_h;
  if (!localDW->obj_h.matlabCodegenIsDeleted) {
    localDW->obj_h.matlabCodegenIsDeleted = true;
    if ((localDW->obj_h.isInitialized == 1) && localDW->obj_h.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void LOG_DATI_GPS_BMP_07_09_find_254(const uint8_T pack[100], real_T
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP_07_09_eml_find(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP__ifWhileCond_k(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP_07__eml_find_e(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP__readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP_07__copydigits(char_T s1[4], int32_T *idx,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP_0_copyexponent(char_T s1[4], int32_T *idx,
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

      LOG_DATI_GPS_BMP_07_09_B.kexp_l = *k;
      b_k = *k;
      b_success = LOG_DATI_GPS_BMP_07__copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > LOG_DATI_GPS_BMP_07_09_B.kexp_l));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP_07_0_readfloat(char_T s1[4], int32_T *idx, const
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
            LOG_DATI_GPS_BMP_07_0_readfloat(s1, idx, s, k, false, &isneg,
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
      LOG_DATI_GPS_BMP__readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = LOG_DATI_GPS_BMP_07__copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = LOG_DATI_GPS_BMP_0_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static creal_T LOG_DATI_GPS_BMP_07__str2double(const char_T s[2])
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
  LOG_DATI_GPS_BMP_07_09_B.ntoread_b = 0;
  LOG_DATI_GPS_BMP_07_09_B.k_b = 0;
  while ((LOG_DATI_GPS_BMP_07_09_B.k_b + 1 <= 2) && (c[(uint8_T)
          s[LOG_DATI_GPS_BMP_07_09_B.k_b] & 127] ||
          (s[LOG_DATI_GPS_BMP_07_09_B.k_b] == '\x00'))) {
    LOG_DATI_GPS_BMP_07_09_B.k_b++;
  }

  isimag1 = false;
  b_finite = true;
  LOG_DATI_GPS_BMP_07_09_B.scanned1_g = 0.0;
  LOG_DATI_GPS_BMP_07_09_B.idx_n = 1;
  LOG_DATI_GPS_BMP_07_09_B.s1_g[0] = '\x00';
  LOG_DATI_GPS_BMP_07_09_B.s1_g[1] = '\x00';
  LOG_DATI_GPS_BMP_07_09_B.s1_g[2] = '\x00';
  LOG_DATI_GPS_BMP_07_09_B.s1_g[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.k_b + 1 <= 2)) {
    if (s[LOG_DATI_GPS_BMP_07_09_B.k_b] == '-') {
      isneg = !isneg;
      LOG_DATI_GPS_BMP_07_09_B.k_b++;
    } else if ((s[LOG_DATI_GPS_BMP_07_09_B.k_b] == ',') ||
               (s[LOG_DATI_GPS_BMP_07_09_B.k_b] == '+') || c[(uint8_T)
               s[LOG_DATI_GPS_BMP_07_09_B.k_b] & 127]) {
      LOG_DATI_GPS_BMP_07_09_B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  success = (LOG_DATI_GPS_BMP_07_09_B.k_b + 1 <= 2);
  if (success && isneg) {
    LOG_DATI_GPS_BMP_07_09_B.s1_g[0] = '-';
    LOG_DATI_GPS_BMP_07_09_B.idx_n = 2;
  }

  LOG_DATI_GPS_BMP_07_09_B.e_k = LOG_DATI_GPS_BMP_07_09_B.k_b + 1;
  if (success) {
    if ((LOG_DATI_GPS_BMP_07_09_B.k_b + 1 <= 2) &&
        ((s[LOG_DATI_GPS_BMP_07_09_B.k_b] == 'j') ||
         (s[LOG_DATI_GPS_BMP_07_09_B.k_b] == 'i'))) {
      isimag1 = true;
      LOG_DATI_GPS_BMP_07_09_B.e_k = LOG_DATI_GPS_BMP_07_09_B.k_b + 2;
      while ((LOG_DATI_GPS_BMP_07_09_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] ||
              (s[1] == '\x00') || (s[1] == ','))) {
        LOG_DATI_GPS_BMP_07_09_B.e_k = 3;
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.e_k <= 2) && (s[1] == '*')) {
        LOG_DATI_GPS_BMP_07_09_B.e_k = 3;
        LOG_DATI_GPS_BMP_07_0_readfloat(LOG_DATI_GPS_BMP_07_09_B.s1_g,
          &LOG_DATI_GPS_BMP_07_09_B.idx_n, s, &LOG_DATI_GPS_BMP_07_09_B.e_k,
          false, &isneg, &b_finite, &LOG_DATI_GPS_BMP_07_09_B.scanned1_g,
          &unusedU2, &success);
      } else {
        LOG_DATI_GPS_BMP_07_09_B.s1_g[LOG_DATI_GPS_BMP_07_09_B.idx_n - 1] = '1';
        LOG_DATI_GPS_BMP_07_09_B.idx_n++;
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_B.e_k = LOG_DATI_GPS_BMP_07_09_B.k_b + 1;
      LOG_DATI_GPS_BMP__readNonFinite(s, &LOG_DATI_GPS_BMP_07_09_B.e_k,
        &b_finite, &LOG_DATI_GPS_BMP_07_09_B.scanned1_g);
      if (b_finite) {
        success = LOG_DATI_GPS_BMP_07__copydigits(LOG_DATI_GPS_BMP_07_09_B.s1_g,
          &LOG_DATI_GPS_BMP_07_09_B.idx_n, s, &LOG_DATI_GPS_BMP_07_09_B.e_k,
          true);
        if (success) {
          success = LOG_DATI_GPS_BMP_0_copyexponent
            (LOG_DATI_GPS_BMP_07_09_B.s1_g, &LOG_DATI_GPS_BMP_07_09_B.idx_n, s,
             &LOG_DATI_GPS_BMP_07_09_B.e_k);
        }
      } else {
        if ((LOG_DATI_GPS_BMP_07_09_B.idx_n >= 2) &&
            (LOG_DATI_GPS_BMP_07_09_B.s1_g[0] == '-')) {
          LOG_DATI_GPS_BMP_07_09_B.idx_n = 1;
          LOG_DATI_GPS_BMP_07_09_B.s1_g[0] = ' ';
          LOG_DATI_GPS_BMP_07_09_B.scanned1_g =
            -LOG_DATI_GPS_BMP_07_09_B.scanned1_g;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.e_k <= 2)) {
        tmp = s[LOG_DATI_GPS_BMP_07_09_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          LOG_DATI_GPS_BMP_07_09_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.e_k <= 2) && (s[LOG_DATI_GPS_BMP_07_09_B.e_k
           - 1] == '*')) {
        LOG_DATI_GPS_BMP_07_09_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.e_k <= 2)) {
          tmp = s[LOG_DATI_GPS_BMP_07_09_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            LOG_DATI_GPS_BMP_07_09_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (LOG_DATI_GPS_BMP_07_09_B.e_k <= 2) {
        tmp = s[LOG_DATI_GPS_BMP_07_09_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          LOG_DATI_GPS_BMP_07_09_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.e_k <= 2)) {
      tmp = s[LOG_DATI_GPS_BMP_07_09_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        LOG_DATI_GPS_BMP_07_09_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    LOG_DATI_GPS_BMP_07_09_B.ntoread_b = 1;
  }

  if (success && (LOG_DATI_GPS_BMP_07_09_B.e_k <= 2)) {
    LOG_DATI_GPS_BMP_07_09_B.s1_g[LOG_DATI_GPS_BMP_07_09_B.idx_n - 1] = ' ';
    LOG_DATI_GPS_BMP_07_09_B.idx_n++;
    LOG_DATI_GPS_BMP_07_0_readfloat(LOG_DATI_GPS_BMP_07_09_B.s1_g,
      &LOG_DATI_GPS_BMP_07_09_B.idx_n, s, &LOG_DATI_GPS_BMP_07_09_B.e_k, true,
      &success, &isneg, &LOG_DATI_GPS_BMP_07_09_B.scanned2_m, &unusedU2,
      &c_success);
    if (isneg) {
      LOG_DATI_GPS_BMP_07_09_B.ntoread_b++;
    }

    success = (c_success && (LOG_DATI_GPS_BMP_07_09_B.e_k > 2) && (isimag1 !=
                success) && unusedU2);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.scanned2_m = 0.0;
  }

  if (success) {
    LOG_DATI_GPS_BMP_07_09_B.s1_g[LOG_DATI_GPS_BMP_07_09_B.idx_n - 1] = '\x00';
    switch (LOG_DATI_GPS_BMP_07_09_B.ntoread_b) {
     case 2:
      LOG_DATI_GPS_BMP_07_09_B.ntoread_b = sscanf
        (&LOG_DATI_GPS_BMP_07_09_B.s1_g[0], "%lf %lf",
         &LOG_DATI_GPS_BMP_07_09_B.scanned1_g,
         &LOG_DATI_GPS_BMP_07_09_B.scanned2_m);
      if (LOG_DATI_GPS_BMP_07_09_B.ntoread_b != 2) {
        LOG_DATI_GPS_BMP_07_09_B.scanned1_g = (rtNaN);
        LOG_DATI_GPS_BMP_07_09_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      LOG_DATI_GPS_BMP_07_09_B.ntoread_b = sscanf
        (&LOG_DATI_GPS_BMP_07_09_B.s1_g[0], "%lf",
         &LOG_DATI_GPS_BMP_07_09_B.b_scanned1_n);
      if (b_finite) {
        if (LOG_DATI_GPS_BMP_07_09_B.ntoread_b == 1) {
          LOG_DATI_GPS_BMP_07_09_B.scanned1_g =
            LOG_DATI_GPS_BMP_07_09_B.b_scanned1_n;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.scanned1_g = (rtNaN);
        }
      } else if (LOG_DATI_GPS_BMP_07_09_B.ntoread_b == 1) {
        LOG_DATI_GPS_BMP_07_09_B.scanned2_m =
          LOG_DATI_GPS_BMP_07_09_B.b_scanned1_n;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = LOG_DATI_GPS_BMP_07_09_B.scanned2_m;
      x.im = LOG_DATI_GPS_BMP_07_09_B.scanned1_g;
    } else {
      x.re = LOG_DATI_GPS_BMP_07_09_B.scanned1_g;
      x.im = LOG_DATI_GPS_BMP_07_09_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP_0_copydigits_g(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP_07_readfloat_i(char_T s1_data[], int32_T *idx,
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
          LOG_DATI_GPS_BMP_07_readfloat_i(s1_data, idx, s_data, k, n, false,
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
        *success = LOG_DATI_GPS_BMP_0_copydigits_g(s1_data, &b_idx, s_data, &h_k,
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
              isneg = LOG_DATI_GPS_BMP_0_copydigits_g(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static creal_T LOG_DATI_GPS_BMP_0_str2double_i(const char_T s_data[], const
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
    LOG_DATI_GPS_BMP_07_09_B.ntoread = 0;
    LOG_DATI_GPS_BMP_07_09_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.k <= s_size[1])) {
      tmp = s_data[LOG_DATI_GPS_BMP_07_09_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        LOG_DATI_GPS_BMP_07_09_B.k++;
      } else {
        exitg1 = true;
      }
    }

    LOG_DATI_GPS_BMP_07_09_B.s1_size[0] = 1;
    LOG_DATI_GPS_BMP_07_09_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    LOG_DATI_GPS_BMP_07_09_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= LOG_DATI_GPS_BMP_07_09_B.idx) {
      memset(&LOG_DATI_GPS_BMP_07_09_B.s1_data[0], 0,
             (LOG_DATI_GPS_BMP_07_09_B.idx + 1) * sizeof(char_T));
    }

    LOG_DATI_GPS_BMP_07_09_B.idx = 1;
    LOG_DATI_GPS_BMP_07_readfloat_i(LOG_DATI_GPS_BMP_07_09_B.s1_data,
      &LOG_DATI_GPS_BMP_07_09_B.idx, s_data, &LOG_DATI_GPS_BMP_07_09_B.k,
      s_size[1], true, &isimag1, &isfinite1, &LOG_DATI_GPS_BMP_07_09_B.scanned1,
      &unusedU0, &success);
    if (isfinite1) {
      LOG_DATI_GPS_BMP_07_09_B.ntoread = 1;
    }

    if (success) {
      if (LOG_DATI_GPS_BMP_07_09_B.k <= s_size[1]) {
        LOG_DATI_GPS_BMP_07_09_B.s1_data[LOG_DATI_GPS_BMP_07_09_B.idx - 1] = ' ';
        LOG_DATI_GPS_BMP_07_09_B.idx++;
        LOG_DATI_GPS_BMP_07_readfloat_i(LOG_DATI_GPS_BMP_07_09_B.s1_data,
          &LOG_DATI_GPS_BMP_07_09_B.idx, s_data, &LOG_DATI_GPS_BMP_07_09_B.k,
          s_size[1], true, &unusedU0, &success,
          &LOG_DATI_GPS_BMP_07_09_B.scanned2, &foundsign, &c_success);
        if (success) {
          LOG_DATI_GPS_BMP_07_09_B.ntoread++;
        }

        success = (c_success && ((LOG_DATI_GPS_BMP_07_09_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        LOG_DATI_GPS_BMP_07_09_B.scanned2 = 0.0;
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_B.scanned2 = 0.0;
    }

    if (success) {
      LOG_DATI_GPS_BMP_07_09_B.s1_data[LOG_DATI_GPS_BMP_07_09_B.idx - 1] =
        '\x00';
      switch (LOG_DATI_GPS_BMP_07_09_B.ntoread) {
       case 2:
        LOG_DATI_GPS_BMP_07_09_B.ntoread = sscanf
          (&LOG_DATI_GPS_BMP_07_09_B.s1_data[0], "%lf %lf",
           &LOG_DATI_GPS_BMP_07_09_B.scanned1,
           &LOG_DATI_GPS_BMP_07_09_B.scanned2);
        if (LOG_DATI_GPS_BMP_07_09_B.ntoread != 2) {
          LOG_DATI_GPS_BMP_07_09_B.scanned1 = (rtNaN);
          LOG_DATI_GPS_BMP_07_09_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        LOG_DATI_GPS_BMP_07_09_B.ntoread = sscanf
          (&LOG_DATI_GPS_BMP_07_09_B.s1_data[0], "%lf",
           &LOG_DATI_GPS_BMP_07_09_B.b_scanned1);
        if (isfinite1) {
          if (LOG_DATI_GPS_BMP_07_09_B.ntoread == 1) {
            LOG_DATI_GPS_BMP_07_09_B.scanned1 =
              LOG_DATI_GPS_BMP_07_09_B.b_scanned1;
          } else {
            LOG_DATI_GPS_BMP_07_09_B.scanned1 = (rtNaN);
          }
        } else if (LOG_DATI_GPS_BMP_07_09_B.ntoread == 1) {
          LOG_DATI_GPS_BMP_07_09_B.scanned2 =
            LOG_DATI_GPS_BMP_07_09_B.b_scanned1;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = LOG_DATI_GPS_BMP_07_09_B.scanned2;
        x.im = LOG_DATI_GPS_BMP_07_09_B.scanned1;
      } else {
        x.re = LOG_DATI_GPS_BMP_07_09_B.scanned1;
        x.im = LOG_DATI_GPS_BMP_07_09_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP_07__isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BM_readNonFinite_e(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP__copydigits_gt(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP_copyexponent_g(char_T s1[5], int32_T *idx,
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

      LOG_DATI_GPS_BMP_07_09_B.kexp = *k;
      b_k = *k;
      b_success = LOG_DATI_GPS_BMP__copydigits_gt(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > LOG_DATI_GPS_BMP_07_09_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP_0_readfloat_iz(char_T s1[5], int32_T *idx, const
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
    if (LOG_DATI_GPS_BMP_07__isUnitImag(s, b_k)) {
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
          LOG_DATI_GPS_BMP_0_readfloat_iz(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      LOG_DATI_GPS_BM_readNonFinite_e(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = LOG_DATI_GPS_BMP__copydigits_gt(s1, idx, s, k, true);
        if (*success) {
          *success = LOG_DATI_GPS_BMP_copyexponent_g(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static creal_T LOG_DATI_GPS_BMP__str2double_i2(const char_T s[3])
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
  LOG_DATI_GPS_BMP_07_09_B.ntoread_o = 0;
  LOG_DATI_GPS_BMP_07_09_B.k_d = 1;
  exitg1 = false;
  while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.k_d <= 3)) {
    tmp = s[LOG_DATI_GPS_BMP_07_09_B.k_d - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      LOG_DATI_GPS_BMP_07_09_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  LOG_DATI_GPS_BMP_07_09_B.scanned1_c = 0.0;
  LOG_DATI_GPS_BMP_07_09_B.idx_l = 1;
  for (LOG_DATI_GPS_BMP_07_09_B.b_k = 0; LOG_DATI_GPS_BMP_07_09_B.b_k < 5;
       LOG_DATI_GPS_BMP_07_09_B.b_k++) {
    LOG_DATI_GPS_BMP_07_09_B.s1[LOG_DATI_GPS_BMP_07_09_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.k_d <= 3)) {
    tmp = s[LOG_DATI_GPS_BMP_07_09_B.k_d - 1];
    if (tmp == '-') {
      isneg = !isneg;
      LOG_DATI_GPS_BMP_07_09_B.k_d++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      LOG_DATI_GPS_BMP_07_09_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  success = (LOG_DATI_GPS_BMP_07_09_B.k_d <= 3);
  if (success && isneg) {
    LOG_DATI_GPS_BMP_07_09_B.s1[0] = '-';
    LOG_DATI_GPS_BMP_07_09_B.idx_l = 2;
  }

  LOG_DATI_GPS_BMP_07_09_B.b_k = LOG_DATI_GPS_BMP_07_09_B.k_d - 1;
  if (success) {
    if (LOG_DATI_GPS_BMP_07__isUnitImag(s, LOG_DATI_GPS_BMP_07_09_B.k_d)) {
      isimag1 = true;
      LOG_DATI_GPS_BMP_07_09_B.b_k = LOG_DATI_GPS_BMP_07_09_B.k_d;
      while ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[LOG_DATI_GPS_BMP_07_09_B.b_k] & 127] ||
              (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == '\x00') ||
              (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == ','))) {
        LOG_DATI_GPS_BMP_07_09_B.b_k++;
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) &&
          (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == '*')) {
        LOG_DATI_GPS_BMP_07_09_B.k_d = LOG_DATI_GPS_BMP_07_09_B.b_k + 2;
        LOG_DATI_GPS_BMP_0_readfloat_iz(LOG_DATI_GPS_BMP_07_09_B.s1,
          &LOG_DATI_GPS_BMP_07_09_B.idx_l, s, &LOG_DATI_GPS_BMP_07_09_B.k_d,
          false, &isneg, &b_finite, &LOG_DATI_GPS_BMP_07_09_B.scanned1_c,
          &unusedU2, &success);
        LOG_DATI_GPS_BMP_07_09_B.b_k = LOG_DATI_GPS_BMP_07_09_B.k_d - 1;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.s1[LOG_DATI_GPS_BMP_07_09_B.idx_l - 1] = '1';
        LOG_DATI_GPS_BMP_07_09_B.idx_l++;
      }
    } else {
      LOG_DATI_GPS_BM_readNonFinite_e(s, &LOG_DATI_GPS_BMP_07_09_B.k_d,
        &b_finite, &LOG_DATI_GPS_BMP_07_09_B.scanned1_c);
      LOG_DATI_GPS_BMP_07_09_B.b_k = LOG_DATI_GPS_BMP_07_09_B.k_d - 1;
      if (b_finite) {
        success = LOG_DATI_GPS_BMP__copydigits_gt(LOG_DATI_GPS_BMP_07_09_B.s1,
          &LOG_DATI_GPS_BMP_07_09_B.idx_l, s, &LOG_DATI_GPS_BMP_07_09_B.k_d,
          true);
        LOG_DATI_GPS_BMP_07_09_B.b_k = LOG_DATI_GPS_BMP_07_09_B.k_d - 1;
        if (success) {
          success = LOG_DATI_GPS_BMP_copyexponent_g(LOG_DATI_GPS_BMP_07_09_B.s1,
            &LOG_DATI_GPS_BMP_07_09_B.idx_l, s, &LOG_DATI_GPS_BMP_07_09_B.k_d);
          LOG_DATI_GPS_BMP_07_09_B.b_k = LOG_DATI_GPS_BMP_07_09_B.k_d - 1;
        }
      } else {
        if ((LOG_DATI_GPS_BMP_07_09_B.idx_l >= 2) &&
            (LOG_DATI_GPS_BMP_07_09_B.s1[0] == '-')) {
          LOG_DATI_GPS_BMP_07_09_B.idx_l = 1;
          LOG_DATI_GPS_BMP_07_09_B.s1[0] = ' ';
          LOG_DATI_GPS_BMP_07_09_B.scanned1_c =
            -LOG_DATI_GPS_BMP_07_09_B.scanned1_c;
        }
      }

      while ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[LOG_DATI_GPS_BMP_07_09_B.b_k] & 127] ||
              (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == '\x00') ||
              (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == ','))) {
        LOG_DATI_GPS_BMP_07_09_B.b_k++;
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) &&
          (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == '*')) {
        LOG_DATI_GPS_BMP_07_09_B.b_k++;
        while ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[LOG_DATI_GPS_BMP_07_09_B.b_k] & 127] ||
                (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == '\x00') ||
                (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == ','))) {
          LOG_DATI_GPS_BMP_07_09_B.b_k++;
        }
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) &&
          ((s[LOG_DATI_GPS_BMP_07_09_B.b_k] == 'i') ||
           (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == 'j'))) {
        LOG_DATI_GPS_BMP_07_09_B.b_k++;
        isimag1 = true;
      }
    }

    while ((LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[LOG_DATI_GPS_BMP_07_09_B.b_k] & 127] ||
            (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == '\x00') ||
            (s[LOG_DATI_GPS_BMP_07_09_B.b_k] == ','))) {
      LOG_DATI_GPS_BMP_07_09_B.b_k++;
    }
  }

  if (b_finite) {
    LOG_DATI_GPS_BMP_07_09_B.ntoread_o = 1;
  }

  if (success && (LOG_DATI_GPS_BMP_07_09_B.b_k + 1 <= 3)) {
    LOG_DATI_GPS_BMP_07_09_B.s1[LOG_DATI_GPS_BMP_07_09_B.idx_l - 1] = ' ';
    LOG_DATI_GPS_BMP_07_09_B.idx_l++;
    LOG_DATI_GPS_BMP_07_09_B.k_d = LOG_DATI_GPS_BMP_07_09_B.b_k + 1;
    LOG_DATI_GPS_BMP_0_readfloat_iz(LOG_DATI_GPS_BMP_07_09_B.s1,
      &LOG_DATI_GPS_BMP_07_09_B.idx_l, s, &LOG_DATI_GPS_BMP_07_09_B.k_d, true,
      &success, &isneg, &LOG_DATI_GPS_BMP_07_09_B.scanned2_f, &unusedU2,
      &c_success);
    if (isneg) {
      LOG_DATI_GPS_BMP_07_09_B.ntoread_o++;
    }

    success = (c_success && (LOG_DATI_GPS_BMP_07_09_B.k_d > 3) && (isimag1 !=
                success) && unusedU2);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.scanned2_f = 0.0;
  }

  if (success) {
    LOG_DATI_GPS_BMP_07_09_B.s1[LOG_DATI_GPS_BMP_07_09_B.idx_l - 1] = '\x00';
    switch (LOG_DATI_GPS_BMP_07_09_B.ntoread_o) {
     case 2:
      LOG_DATI_GPS_BMP_07_09_B.ntoread_o = sscanf(&LOG_DATI_GPS_BMP_07_09_B.s1[0],
        "%lf %lf", &LOG_DATI_GPS_BMP_07_09_B.scanned1_c,
        &LOG_DATI_GPS_BMP_07_09_B.scanned2_f);
      if (LOG_DATI_GPS_BMP_07_09_B.ntoread_o != 2) {
        LOG_DATI_GPS_BMP_07_09_B.scanned1_c = (rtNaN);
        LOG_DATI_GPS_BMP_07_09_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      LOG_DATI_GPS_BMP_07_09_B.ntoread_o = sscanf(&LOG_DATI_GPS_BMP_07_09_B.s1[0],
        "%lf", &LOG_DATI_GPS_BMP_07_09_B.b_scanned1_g);
      if (b_finite) {
        if (LOG_DATI_GPS_BMP_07_09_B.ntoread_o == 1) {
          LOG_DATI_GPS_BMP_07_09_B.scanned1_c =
            LOG_DATI_GPS_BMP_07_09_B.b_scanned1_g;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.scanned1_c = (rtNaN);
        }
      } else if (LOG_DATI_GPS_BMP_07_09_B.ntoread_o == 1) {
        LOG_DATI_GPS_BMP_07_09_B.scanned2_f =
          LOG_DATI_GPS_BMP_07_09_B.b_scanned1_g;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = LOG_DATI_GPS_BMP_07_09_B.scanned2_f;
      x.im = LOG_DATI_GPS_BMP_07_09_B.scanned1_c;
    } else {
      x.re = LOG_DATI_GPS_BMP_07_09_B.scanned1_c;
      x.im = LOG_DATI_GPS_BMP_07_09_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_B_readNonFinite_ec(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BMP_copydigits_gt3(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static boolean_T LOG_DATI_GPS_BM_copyexponent_gr(char_T s1[3], int32_T *idx,
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
    b_success = LOG_DATI_GPS_BMP_copydigits_gt3(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static void LOG_DATI_GPS_BMP__readfloat_izz(char_T s1[3], int32_T *idx, char_T s,
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
          LOG_DATI_GPS_BMP__readfloat_izz(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      LOG_DATI_GPS_B_readNonFinite_ec(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = LOG_DATI_GPS_BMP_copydigits_gt3(s1, idx, s, k, true);
        if (*success) {
          *success = LOG_DATI_GPS_BM_copyexponent_gr(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static creal_T LOG_DATI_GPS_BMP_str2double_i2v(char_T s)
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
  LOG_DATI_GPS_BMP_07_09_B.ntoread_bn = 0;
  LOG_DATI_GPS_BMP_07_09_B.d_k = 1;
  LOG_DATI_GPS_BMP_07_09_B.i_d = (uint8_T)s & 127;
  if (c[LOG_DATI_GPS_BMP_07_09_B.i_d] || (s == '\x00')) {
    LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  LOG_DATI_GPS_BMP_07_09_B.scanned1_p = 0.0;
  LOG_DATI_GPS_BMP_07_09_B.idx_h = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[LOG_DATI_GPS_BMP_07_09_B.i_d]) {
      LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (LOG_DATI_GPS_BMP_07_09_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    LOG_DATI_GPS_BMP_07_09_B.idx_h = 2;
  }

  if (success) {
    isneg = false;
    if (LOG_DATI_GPS_BMP_07_09_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      LOG_DATI_GPS_BMP_07_09_B.d_k++;
      s1[LOG_DATI_GPS_BMP_07_09_B.idx_h - 1] = '1';
      LOG_DATI_GPS_BMP_07_09_B.idx_h++;
    } else {
      LOG_DATI_GPS_B_readNonFinite_ec(s, &LOG_DATI_GPS_BMP_07_09_B.d_k,
        &b_finite, &LOG_DATI_GPS_BMP_07_09_B.scanned1_p);
      if (b_finite) {
        success = LOG_DATI_GPS_BMP_copydigits_gt3(s1,
          &LOG_DATI_GPS_BMP_07_09_B.idx_h, s, &LOG_DATI_GPS_BMP_07_09_B.d_k,
          true);
        if (success) {
          success = LOG_DATI_GPS_BM_copyexponent_gr(s1,
            &LOG_DATI_GPS_BMP_07_09_B.idx_h, s, &LOG_DATI_GPS_BMP_07_09_B.d_k);
        }
      } else {
        if ((LOG_DATI_GPS_BMP_07_09_B.idx_h >= 2) && (s1[0] == '-')) {
          LOG_DATI_GPS_BMP_07_09_B.idx_h = 1;
          s1[0] = ' ';
          LOG_DATI_GPS_BMP_07_09_B.scanned1_p =
            -LOG_DATI_GPS_BMP_07_09_B.scanned1_p;
        }
      }

      while ((LOG_DATI_GPS_BMP_07_09_B.d_k <= 1) &&
             (c[LOG_DATI_GPS_BMP_07_09_B.i_d] || ((s == '\x00') || (s == ','))))
      {
        LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.d_k <= 1) && (s == '*')) {
        LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
      }

      if ((LOG_DATI_GPS_BMP_07_09_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((LOG_DATI_GPS_BMP_07_09_B.d_k <= 1) &&
           (c[LOG_DATI_GPS_BMP_07_09_B.i_d] || ((s == '\x00') || (s == ',')))) {
      LOG_DATI_GPS_BMP_07_09_B.d_k = 2;
    }
  }

  if (b_finite) {
    LOG_DATI_GPS_BMP_07_09_B.ntoread_bn = 1;
  }

  if (success && (LOG_DATI_GPS_BMP_07_09_B.d_k <= 1)) {
    s1[LOG_DATI_GPS_BMP_07_09_B.idx_h - 1] = ' ';
    LOG_DATI_GPS_BMP_07_09_B.idx_h++;
    LOG_DATI_GPS_BMP_07_09_B.d_k = 1;
    LOG_DATI_GPS_BMP__readfloat_izz(s1, &LOG_DATI_GPS_BMP_07_09_B.idx_h, s,
      &LOG_DATI_GPS_BMP_07_09_B.d_k, true, &success, &isneg,
      &LOG_DATI_GPS_BMP_07_09_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      LOG_DATI_GPS_BMP_07_09_B.ntoread_bn++;
    }

    success = (c_success && (LOG_DATI_GPS_BMP_07_09_B.d_k > 1) && (isimag1 !=
                success) && foundsign);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[LOG_DATI_GPS_BMP_07_09_B.idx_h - 1] = '\x00';
    switch (LOG_DATI_GPS_BMP_07_09_B.ntoread_bn) {
     case 2:
      LOG_DATI_GPS_BMP_07_09_B.ntoread_bn = sscanf(&s1[0], "%lf %lf",
        &LOG_DATI_GPS_BMP_07_09_B.scanned1_p,
        &LOG_DATI_GPS_BMP_07_09_B.scanned2_l);
      if (LOG_DATI_GPS_BMP_07_09_B.ntoread_bn != 2) {
        LOG_DATI_GPS_BMP_07_09_B.scanned1_p = (rtNaN);
        LOG_DATI_GPS_BMP_07_09_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      LOG_DATI_GPS_BMP_07_09_B.ntoread_bn = sscanf(&s1[0], "%lf",
        &LOG_DATI_GPS_BMP_07_09_B.b_scanned1_j);
      if (b_finite) {
        if (LOG_DATI_GPS_BMP_07_09_B.ntoread_bn == 1) {
          LOG_DATI_GPS_BMP_07_09_B.scanned1_p =
            LOG_DATI_GPS_BMP_07_09_B.b_scanned1_j;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.scanned1_p = (rtNaN);
        }
      } else if (LOG_DATI_GPS_BMP_07_09_B.ntoread_bn == 1) {
        LOG_DATI_GPS_BMP_07_09_B.scanned2_l =
          LOG_DATI_GPS_BMP_07_09_B.b_scanned1_j;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = LOG_DATI_GPS_BMP_07_09_B.scanned2_l;
      x.im = LOG_DATI_GPS_BMP_07_09_B.scanned1_p;
    } else {
      x.re = LOG_DATI_GPS_BMP_07_09_B.scanned1_p;
      x.im = LOG_DATI_GPS_BMP_07_09_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S41>/MATLAB Function' */
static real_T LOG_DATI_GPS_BMP_07_09_hex2dec(const char_T s[2])
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

  LOG_DATI_GPS_BMP_07_09_B.a = tmp_0;
  LOG_DATI_GPS_BMP_07_09_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U],
                      2);
      tmp = tmp_2;
      MultiWordSub(&LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &LOG_DATI_GPS_BMP_07_09_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U],
                      2);
      tmp = tmp_3;
      MultiWordSub(&LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &LOG_DATI_GPS_BMP_07_09_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U],
                        2);
        tmp = tmp_4;
        MultiWordSub(&LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &LOG_DATI_GPS_BMP_07_09_B.sk.chunks[0U], 2);
      } else {
        LOG_DATI_GPS_BMP_07_09_B.sk = tmp_0;
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_B.sk = tmp_0;
    }

    uMultiWordMul(&LOG_DATI_GPS_BMP_07_09_B.sk.chunks[0U], 2,
                  &LOG_DATI_GPS_BMP_07_09_B.p16.chunks[0U], 2,
                  &LOG_DATI_GPS_BMP_07_09_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&LOG_DATI_GPS_BMP_07_09_B.r.chunks[0U], 4,
                         &LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U], 2);
    MultiWordAdd(&LOG_DATI_GPS_BMP_07_09_B.a.chunks[0U],
                 &LOG_DATI_GPS_BMP_07_09_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    LOG_DATI_GPS_BMP_07_09_B.a = tmp;
    uMultiWord2MultiWord(&LOG_DATI_GPS_BMP_07_09_B.p16.chunks[0U], 2,
                         &LOG_DATI_GPS_BMP_07_09_B.r2.chunks[0U], 3);
    uMultiWordShl(&LOG_DATI_GPS_BMP_07_09_B.r2.chunks[0U], 3, 4U,
                  &LOG_DATI_GPS_BMP_07_09_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&LOG_DATI_GPS_BMP_07_09_B.r1.chunks[0U], 3,
                         &LOG_DATI_GPS_BMP_07_09_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&LOG_DATI_GPS_BMP_07_09_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&LOG_DATI_GPS_BMP_07_09_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&LOG_DATI_GPS_BMP_07_09_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&LOG_DATI_GPS_BMP_07_09_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&LOG_DATI_GPS_BMP_07_09_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&LOG_DATI_GPS_BMP_07_09_B.a.chunks[0U], 2, 0);
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
void LOG_DATI_GPS_BMP_07_09_step0(void) /* Sample time: [0.02s, 0.0s] */
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
  Seriale_mav_Outputs_wrapper(&LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_h,
    &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[0],
    &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2,
    &LOG_DATI_GPS_BMP_07_09_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  LOG_DATI_GPS_BMP_07_09_B.status = 0;
  LOG_DATI_GPS_BMP_07_09_B.caso = 0;
  memset(&LOG_DATI_GPS_BMP_07_09_B.messaggio_j[0], 0, 100U * sizeof(uint8_T));
  memset(&LOG_DATI_GPS_BMP_07_09_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  LOG_DATI_GPS_BMP_07_09_find_254(LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e,
    LOG_DATI_GPS_BMP_07_09_B.poss_254, &LOG_DATI_GPS_BMP_07_09_B.num_254);
  if (LOG_DATI_GPS_BMP_07_09_DW.Interr_parz && (LOG_DATI_GPS_BMP_07_09_B.num_254
       == 1.0)) {
    LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(LOG_DATI_GPS_BMP_07_09_DW.counter_b
      + 1U);
    if (LOG_DATI_GPS_BMP_07_09_DW.counter_b + 1U > 255U) {
      LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
    }

    if (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] != LOG_DATI_GPS_BMP_07_09_B.f_l) {
      LOG_DATI_GPS_BMP_07_09_B.num_254 = 0.0;
    }
  }

  y = !LOG_DATI_GPS_BMP_07_09_DW.Interr_parz;
  if ((LOG_DATI_GPS_BMP_07_09_B.num_254 == 1.0) && y) {
    LOG_DATI_GPS_BMP_07_09_B.caso = 1;
  } else if ((LOG_DATI_GPS_BMP_07_09_B.num_254 == 0.0) &&
             LOG_DATI_GPS_BMP_07_09_DW.Interr_parz) {
    LOG_DATI_GPS_BMP_07_09_B.caso = 2;
  } else if ((LOG_DATI_GPS_BMP_07_09_B.num_254 == 1.0) &&
             LOG_DATI_GPS_BMP_07_09_DW.Interr_parz) {
    LOG_DATI_GPS_BMP_07_09_B.caso = 3;
  } else {
    if ((LOG_DATI_GPS_BMP_07_09_B.num_254 == 2.0) && y) {
      LOG_DATI_GPS_BMP_07_09_B.caso = 4;
    }
  }

  switch (LOG_DATI_GPS_BMP_07_09_B.caso) {
   case 1:
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_B.poss_254
      [(int32_T)LOG_DATI_GPS_BMP_07_09_B.num_254 - 1];
    if (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 100.0) {
      LOG_DATI_GPS_BMP_07_09_DW.message_l[0] =
        LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[99];
      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = true;
    } else if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
               (LOG_DATI_GPS_BMP_07_09_B.RateTransition + 1.0) - 1] <= 100) {
      LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
        (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] + 1.0) - 1] + 8U);
      LOG_DATI_GPS_BMP_07_09_B.i = LOG_DATI_GPS_BMP_07_09_B.f_l;
      if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
        LOG_DATI_GPS_BMP_07_09_B.i = 255;
      }

      if (LOG_DATI_GPS_BMP_07_09_B.i ==
          LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2) {
        LOG_DATI_GPS_BMP_07_09_B.UkYk1 = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
        if (LOG_DATI_GPS_BMP_07_09_B.UkYk1 < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.UkYk1 >= 0.0) {
            counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.UkYk1;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
          (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
           (LOG_DATI_GPS_BMP_07_09_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
        }

        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.RateTransition + (real_T)
           LOG_DATI_GPS_BMP_07_09_B.f_l);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          LOG_DATI_GPS_BMP_07_09_B.i = 0;
          LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.i = counter - 1;
          LOG_DATI_GPS_BMP_07_09_B.f_l = find_comma;
        }

        LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.f_l -
          LOG_DATI_GPS_BMP_07_09_B.i;
        for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
             LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.f_l] =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.i
            + LOG_DATI_GPS_BMP_07_09_B.f_l];
        }

        LOG_DATI_GPS_BMP_07_09_B.status = 1;
        for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 100;
             LOG_DATI_GPS_BMP_07_09_B.i++) {
          LOG_DATI_GPS_BMP_07_09_B.messaggio_j[LOG_DATI_GPS_BMP_07_09_B.i] =
            LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i];
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i] = 0U;
        }

        LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
        LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
        }

        if (LOG_DATI_GPS_BMP_07_09_B.f_l >
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2) {
          LOG_DATI_GPS_BMP_07_09_DW.mess_len =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2;
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >
              LOG_DATI_GPS_BMP_07_09_DW.mess_len) {
            LOG_DATI_GPS_BMP_07_09_B.i = 0;
            LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
          } else {
            LOG_DATI_GPS_BMP_07_09_B.i = (int32_T)
              LOG_DATI_GPS_BMP_07_09_B.RateTransition - 1;
            LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
              LOG_DATI_GPS_BMP_07_09_DW.mess_len;
          }

          LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.f_l -
            LOG_DATI_GPS_BMP_07_09_B.i;
          for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
               LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
            LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.f_l] =
              LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.i
              + LOG_DATI_GPS_BMP_07_09_B.f_l];
          }

          LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
            (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
             (LOG_DATI_GPS_BMP_07_09_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
            LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
          }

          LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf((real_T)
            LOG_DATI_GPS_BMP_07_09_B.f_l - LOG_DATI_GPS_BMP_07_09_DW.mess_len);
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
            if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
              LOG_DATI_GPS_BMP_07_09_DW.counter_b = (uint8_T)
                LOG_DATI_GPS_BMP_07_09_B.RateTransition;
            } else {
              LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
            }
          } else {
            LOG_DATI_GPS_BMP_07_09_DW.counter_b = MAX_uint8_T;
          }

          LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = true;
        }
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_09_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
      LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
      LOG_DATI_GPS_BMP_07_09_B.status = 1;
    }
    break;

   case 2:
    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.x[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.f_l]
         != 0);
    }

    if (LOG_DATI_GPS_BMP_07_ifWhileCond(LOG_DATI_GPS_BMP_07_09_B.x)) {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_09_DW.mess_len + 1.0);
      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_09_DW.mess_len + (real_T)
         LOG_DATI_GPS_BMP_07_09_DW.counter_b);
      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
          counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (find_comma > counter) {
        LOG_DATI_GPS_BMP_07_09_B.status = 1;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.status = find_comma;
      }

      if (1 > LOG_DATI_GPS_BMP_07_09_DW.counter_b) {
        LOG_DATI_GPS_BMP_07_09_B.caso = -1;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_DW.counter_b - 1;
      }

      for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <=
           LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
        LOG_DATI_GPS_BMP_07_09_DW.message_l[(LOG_DATI_GPS_BMP_07_09_B.status +
          LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] =
          LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.f_l];
      }

      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
      LOG_DATI_GPS_BMP_07_09_B.status = 1;
      for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 100;
           LOG_DATI_GPS_BMP_07_09_B.i++) {
        LOG_DATI_GPS_BMP_07_09_B.messaggio_j[LOG_DATI_GPS_BMP_07_09_B.i] =
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i];
        LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i] = 0U;
      }

      LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
      LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
      LOG_DATI_GPS_BMP_07_09_B.status = 1;
      memset(&LOG_DATI_GPS_BMP_07_09_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
      LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
    }
    break;

   case 3:
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
      (LOG_DATI_GPS_BMP_07_09_DW.mess_len + 1.0);
    if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
        find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
      (LOG_DATI_GPS_BMP_07_09_DW.mess_len + (real_T)
       LOG_DATI_GPS_BMP_07_09_DW.counter_b);
    if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
        counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (find_comma > counter) {
      LOG_DATI_GPS_BMP_07_09_B.i = 1;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.i = find_comma;
    }

    if (1 > LOG_DATI_GPS_BMP_07_09_DW.counter_b) {
      LOG_DATI_GPS_BMP_07_09_B.caso = -1;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_DW.counter_b - 1;
    }

    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <=
         LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_DW.message_l[(LOG_DATI_GPS_BMP_07_09_B.i +
        LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] =
        LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.f_l];
    }

    LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
    LOG_DATI_GPS_BMP_07_09_B.status = 1;
    for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 100;
         LOG_DATI_GPS_BMP_07_09_B.i++) {
      LOG_DATI_GPS_BMP_07_09_B.messaggio_j[LOG_DATI_GPS_BMP_07_09_B.i] =
        LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i];
      LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i] = 0U;
    }

    LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
    LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
    LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(LOG_DATI_GPS_BMP_07_09_B.poss_254
      [(int32_T)LOG_DATI_GPS_BMP_07_09_B.num_254 - 1] + 1.0) - 1;
    if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.f_l]
        <= 100) {
      LOG_DATI_GPS_BMP_07_09_B.i = (int32_T)
        (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.i > 255U) {
        LOG_DATI_GPS_BMP_07_09_B.i = 255;
      }

      LOG_DATI_GPS_BMP_07_09_B.caso =
        LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2;
      if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2 < 0) {
        LOG_DATI_GPS_BMP_07_09_B.caso = 0;
      } else {
        if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2 > 255) {
          LOG_DATI_GPS_BMP_07_09_B.caso = 255;
        }
      }

      if (LOG_DATI_GPS_BMP_07_09_B.i == LOG_DATI_GPS_BMP_07_09_B.caso) {
        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.poss_254[(int32_T)
           LOG_DATI_GPS_BMP_07_09_B.num_254 - 1]);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
            counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
          (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.f_l]
           + 7U);
        if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
        }

        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.poss_254[(int32_T)
           LOG_DATI_GPS_BMP_07_09_B.num_254 - 1] + (real_T)
           LOG_DATI_GPS_BMP_07_09_B.f_l);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          LOG_DATI_GPS_BMP_07_09_B.i = 0;
          LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.i = counter - 1;
          LOG_DATI_GPS_BMP_07_09_B.f_l = find_comma;
        }

        LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.f_l -
          LOG_DATI_GPS_BMP_07_09_B.i;
        for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
             LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.f_l] =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.i
            + LOG_DATI_GPS_BMP_07_09_B.f_l];
        }

        for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 100;
             LOG_DATI_GPS_BMP_07_09_B.i++) {
          LOG_DATI_GPS_BMP_07_09_B.messaggio_2[LOG_DATI_GPS_BMP_07_09_B.i] =
            LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i];
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i] = 0U;
        }

        LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
        LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.i = (int32_T)
          (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
           (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.i > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.i = 255;
        }

        LOG_DATI_GPS_BMP_07_09_B.caso =
          LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2;
        if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2 < 0) {
          LOG_DATI_GPS_BMP_07_09_B.caso = 0;
        } else {
          if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2 > 255) {
            LOG_DATI_GPS_BMP_07_09_B.caso = 255;
          }
        }

        if (LOG_DATI_GPS_BMP_07_09_B.i > LOG_DATI_GPS_BMP_07_09_B.caso) {
          LOG_DATI_GPS_BMP_07_09_DW.mess_len =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2;
          if (LOG_DATI_GPS_BMP_07_09_B.poss_254[(int32_T)
              LOG_DATI_GPS_BMP_07_09_B.num_254 - 1] >
              LOG_DATI_GPS_BMP_07_09_DW.mess_len) {
            LOG_DATI_GPS_BMP_07_09_B.x_d = 0;
            LOG_DATI_GPS_BMP_07_09_B.caso = 0;
          } else {
            LOG_DATI_GPS_BMP_07_09_B.x_d = (int32_T)
              LOG_DATI_GPS_BMP_07_09_B.poss_254[(int32_T)
              LOG_DATI_GPS_BMP_07_09_B.num_254 - 1] - 1;
            LOG_DATI_GPS_BMP_07_09_B.caso = (int32_T)
              LOG_DATI_GPS_BMP_07_09_DW.mess_len;
          }

          LOG_DATI_GPS_BMP_07_09_B.caso -= LOG_DATI_GPS_BMP_07_09_B.x_d;
          for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i <
               LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.i++) {
            LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i] =
              LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.x_d
              + LOG_DATI_GPS_BMP_07_09_B.i];
          }

          LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
            (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.f_l]
             + 8U);
          if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
            LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
          }

          LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf((real_T)
            LOG_DATI_GPS_BMP_07_09_B.f_l - LOG_DATI_GPS_BMP_07_09_DW.mess_len);
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
            if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
              LOG_DATI_GPS_BMP_07_09_DW.counter_b = (uint8_T)
                LOG_DATI_GPS_BMP_07_09_B.RateTransition;
            } else {
              LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
            }
          } else {
            LOG_DATI_GPS_BMP_07_09_DW.counter_b = MAX_uint8_T;
          }

          LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = true;
        }
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_09_B.messaggio_j[0], 0, 100U * sizeof(uint8_T));
      memset(&LOG_DATI_GPS_BMP_07_09_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
      LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
        (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] + 1.0) - 1] <= 100) {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_09_B.poss_254[0]);
      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
          counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
        (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
        LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
      }

      LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
        (LOG_DATI_GPS_BMP_07_09_B.poss_254[0] + (real_T)
         LOG_DATI_GPS_BMP_07_09_B.f_l);
      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (counter > find_comma) {
        LOG_DATI_GPS_BMP_07_09_B.status = 0;
        LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.status = counter - 1;
        LOG_DATI_GPS_BMP_07_09_B.f_l = find_comma;
      }

      LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.f_l -
        LOG_DATI_GPS_BMP_07_09_B.status;
      for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
           LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
        LOG_DATI_GPS_BMP_07_09_B.messaggio_j[LOG_DATI_GPS_BMP_07_09_B.f_l] =
          LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.status
          + LOG_DATI_GPS_BMP_07_09_B.f_l];
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_09_DW.message_l[0], 0, 100U * sizeof(uint8_T));
    }

    LOG_DATI_GPS_BMP_07_09_B.status = 1;
    if ((LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
         (LOG_DATI_GPS_BMP_07_09_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (LOG_DATI_GPS_BMP_07_09_B.poss_254[1] -
         LOG_DATI_GPS_BMP_07_09_B.poss_254[0] > 3.0)) {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf((real_T)
        LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2 -
        LOG_DATI_GPS_BMP_07_09_B.poss_254[1]);
      LOG_DATI_GPS_BMP_07_09_B.qY =
        LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[(int32_T)
        (LOG_DATI_GPS_BMP_07_09_B.poss_254[1] + 1.0) - 1];
      LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(LOG_DATI_GPS_BMP_07_09_B.qY + 7U);
      if (LOG_DATI_GPS_BMP_07_09_B.qY + 7U > 255U) {
        LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
      }

      if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 2.147483648E+9) {
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= -2.147483648E+9) {
          LOG_DATI_GPS_BMP_07_09_B.i = (int32_T)
            LOG_DATI_GPS_BMP_07_09_B.RateTransition;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.i = MIN_int32_T;
        }
      } else {
        LOG_DATI_GPS_BMP_07_09_B.i = MAX_int32_T;
      }

      if (LOG_DATI_GPS_BMP_07_09_B.i == LOG_DATI_GPS_BMP_07_09_B.f_l) {
        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.poss_254[1]);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
            counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(LOG_DATI_GPS_BMP_07_09_B.qY +
          7U);
        if (LOG_DATI_GPS_BMP_07_09_B.qY + 7U > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
        }

        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.poss_254[1] + (real_T)
           LOG_DATI_GPS_BMP_07_09_B.f_l);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          LOG_DATI_GPS_BMP_07_09_B.status = 0;
          LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.status = counter - 1;
          LOG_DATI_GPS_BMP_07_09_B.f_l = find_comma;
        }

        LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.f_l -
          LOG_DATI_GPS_BMP_07_09_B.status;
        for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
             LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.f_l] =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.status
            + LOG_DATI_GPS_BMP_07_09_B.f_l];
        }

        LOG_DATI_GPS_BMP_07_09_B.status = 2;
        for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 100;
             LOG_DATI_GPS_BMP_07_09_B.i++) {
          LOG_DATI_GPS_BMP_07_09_B.messaggio_2[LOG_DATI_GPS_BMP_07_09_B.i] =
            LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i];
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.i] = 0U;
        }

        LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
        LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf
          (LOG_DATI_GPS_BMP_07_09_B.poss_254[1]);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 2.147483648E+9) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= -2.147483648E+9) {
            LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
              LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            LOG_DATI_GPS_BMP_07_09_B.f_l = MIN_int32_T;
          }
        } else {
          LOG_DATI_GPS_BMP_07_09_B.f_l = MAX_int32_T;
        }

        if (LOG_DATI_GPS_BMP_07_09_B.f_l >
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = -1;
          LOG_DATI_GPS_BMP_07_09_B.caso = 0;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.f_l -= 2;
          LOG_DATI_GPS_BMP_07_09_B.caso =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2;
        }

        LOG_DATI_GPS_BMP_07_09_DW.mess_len = (int8_T)
          ((LOG_DATI_GPS_BMP_07_09_B.caso - LOG_DATI_GPS_BMP_07_09_B.f_l) - 1);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 2.147483648E+9) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= -2.147483648E+9) {
            LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
              LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            LOG_DATI_GPS_BMP_07_09_B.f_l = MIN_int32_T;
          }
        } else {
          LOG_DATI_GPS_BMP_07_09_B.f_l = MAX_int32_T;
        }

        if (LOG_DATI_GPS_BMP_07_09_B.f_l >
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2) {
          LOG_DATI_GPS_BMP_07_09_B.i = 0;
          LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.i = LOG_DATI_GPS_BMP_07_09_B.f_l - 1;
          LOG_DATI_GPS_BMP_07_09_B.f_l =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2;
        }

        LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.f_l -
          LOG_DATI_GPS_BMP_07_09_B.i;
        for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
             LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
          LOG_DATI_GPS_BMP_07_09_DW.message_l[LOG_DATI_GPS_BMP_07_09_B.f_l] =
            LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[LOG_DATI_GPS_BMP_07_09_B.i
            + LOG_DATI_GPS_BMP_07_09_B.f_l];
        }

        LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(LOG_DATI_GPS_BMP_07_09_B.qY +
          8U);
        if (LOG_DATI_GPS_BMP_07_09_B.qY + 8U > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
        }

        LOG_DATI_GPS_BMP_07_09_B.RateTransition = rt_roundd_snf((real_T)
          LOG_DATI_GPS_BMP_07_09_B.f_l - LOG_DATI_GPS_BMP_07_09_DW.mess_len);
        if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 256.0) {
          if (LOG_DATI_GPS_BMP_07_09_B.RateTransition >= 0.0) {
            LOG_DATI_GPS_BMP_07_09_DW.counter_b = (uint8_T)
              LOG_DATI_GPS_BMP_07_09_B.RateTransition;
          } else {
            LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
          }
        } else {
          LOG_DATI_GPS_BMP_07_09_DW.counter_b = MAX_uint8_T;
        }

        LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = true;
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.Interr_parz = false;
      memset(&LOG_DATI_GPS_BMP_07_09_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      LOG_DATI_GPS_BMP_07_09_DW.counter_b = 0U;
      LOG_DATI_GPS_BMP_07_09_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&LOG_DATI_GPS_BMP_07_09_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
       LOG_DATI_GPS_BMP_07_09_B.f_l++) {
    LOG_DATI_GPS_BMP_07_09_B.buffer[3 * LOG_DATI_GPS_BMP_07_09_B.f_l] = 0U;
  }

  for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
       LOG_DATI_GPS_BMP_07_09_B.f_l++) {
    for (LOG_DATI_GPS_BMP_07_09_B.caso = 0; LOG_DATI_GPS_BMP_07_09_B.caso < 2;
         LOG_DATI_GPS_BMP_07_09_B.caso++) {
      LOG_DATI_GPS_BMP_07_09_B.i = 3 * LOG_DATI_GPS_BMP_07_09_B.f_l +
        LOG_DATI_GPS_BMP_07_09_B.caso;
      LOG_DATI_GPS_BMP_07_09_B.buffer[LOG_DATI_GPS_BMP_07_09_B.i + 1] =
        LOG_DATI_GPS_BMP_07_09_DW.Memory4_PreviousInput[LOG_DATI_GPS_BMP_07_09_B.i];
    }
  }

  LOG_DATI_GPS_BMP_07_09_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.i >= 1)) {
    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.x[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        (LOG_DATI_GPS_BMP_07_09_B.buffer[(3 * LOG_DATI_GPS_BMP_07_09_B.f_l +
          LOG_DATI_GPS_BMP_07_09_B.i) - 1] == 0);
    }

    y = true;
    LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
    exitg2 = false;
    while ((!exitg2) && (LOG_DATI_GPS_BMP_07_09_B.f_l < 100)) {
      if (!LOG_DATI_GPS_BMP_07_09_B.x[LOG_DATI_GPS_BMP_07_09_B.f_l]) {
        y = false;
        exitg2 = true;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.f_l++;
      }
    }

    if (y) {
      counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.i;
      exitg1 = true;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.i--;
    }
  }

  if (LOG_DATI_GPS_BMP_07_09_B.status == 1) {
    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.buffer[(counter + 3 *
        LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] =
        LOG_DATI_GPS_BMP_07_09_B.messaggio_j[LOG_DATI_GPS_BMP_07_09_B.f_l];
    }
  } else if (LOG_DATI_GPS_BMP_07_09_B.status == 2) {
    LOG_DATI_GPS_BMP_07_09_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      LOG_DATI_GPS_BMP_07_09_B.qY = 0U;
    }

    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.buffer[(counter + 3 *
        LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] =
        LOG_DATI_GPS_BMP_07_09_B.messaggio_j[LOG_DATI_GPS_BMP_07_09_B.f_l];
      LOG_DATI_GPS_BMP_07_09_B.buffer[((int32_T)LOG_DATI_GPS_BMP_07_09_B.qY + 3 *
        LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] =
        LOG_DATI_GPS_BMP_07_09_B.messaggio_2[LOG_DATI_GPS_BMP_07_09_B.f_l];
    }
  } else {
    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.buffer[(counter + 3 *
        LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] = 0U;
    }
  }

  for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
       LOG_DATI_GPS_BMP_07_09_B.f_l++) {
    LOG_DATI_GPS_BMP_07_09_B.mess_out[LOG_DATI_GPS_BMP_07_09_B.f_l] =
      LOG_DATI_GPS_BMP_07_09_DW.Memory4_PreviousInput[3 *
      LOG_DATI_GPS_BMP_07_09_B.f_l + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  LOG_DATI_GPS_BMP_07_09_B.Add =
    LOG_DATI_GPS_BMP_07_09_DW.Memory4_PreviousInput[5] +
    LOG_DATI_GPS_BMP_07_09_P.Constant_Value_jl;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (LOG_DATI_GPS_BMP_07_09_B.mess_out[2] !=
      LOG_DATI_GPS_BMP_07_09_DW.Memory5_PreviousInput[2]) {
    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 100;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.x[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        (LOG_DATI_GPS_BMP_07_09_B.mess_out[LOG_DATI_GPS_BMP_07_09_B.f_l] != 0);
    }

    y = true;
    LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
    exitg1 = false;
    while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.f_l < 100)) {
      if (!LOG_DATI_GPS_BMP_07_09_B.x[LOG_DATI_GPS_BMP_07_09_B.f_l]) {
        y = false;
        exitg1 = true;
      } else {
        LOG_DATI_GPS_BMP_07_09_B.f_l++;
      }
    }

    if (!y) {
      if (LOG_DATI_GPS_BMP_07_09_DW.counter > 100) {
        LOG_DATI_GPS_BMP_07_09_DW.counter = 0U;
      }

      LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_DW.counter + 1U;
      if (LOG_DATI_GPS_BMP_07_09_DW.counter + 1U > 65535U) {
        LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
      }

      LOG_DATI_GPS_BMP_07_09_DW.counter = (uint16_T)LOG_DATI_GPS_BMP_07_09_B.qY;
    }
  }

  LOG_DATI_GPS_BMP_07_09_B.new_mex = LOG_DATI_GPS_BMP_07_09_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  LOG_DATI_GPS_BMP_07_09_B.Memory1[0] =
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0];
  LOG_DATI_GPS_BMP_07_09_B.Memory1[1] =
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1];

  /* Memory: '<Root>/Memory' */
  LOG_DATI_GPS_BMP_07_09_B.Memory_k[0] =
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[0];
  LOG_DATI_GPS_BMP_07_09_B.Memory_k[1] =
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[1];
  LOG_DATI_GPS_BMP_07_09_B.Memory_k[2] =
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[2];
  LOG_DATI_GPS_BMP_07_09_B.Memory_k[3] =
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[3];

  /* Memory: '<S1>/Memory3' */
  LOG_DATI_GPS_BMP_07_09_B.Memory3 =
    LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput;
  for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 8;
       LOG_DATI_GPS_BMP_07_09_B.i++) {
    /* Memory: '<S1>/Memory' */
    LOG_DATI_GPS_BMP_07_09_B.Memory[LOG_DATI_GPS_BMP_07_09_B.i] =
      LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_e[LOG_DATI_GPS_BMP_07_09_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&LOG_DATI_GPS_BMP_07_09_B.mess_out[0], &LOG_DATI_GPS_BMP_07_09_B.Add,
     &LOG_DATI_GPS_BMP_07_09_B.new_mex,
     &LOG_DATI_GPS_BMP_07_09_P.SIUAVuint8_Value,
     &LOG_DATI_GPS_BMP_07_09_B.Memory[0], &LOG_DATI_GPS_BMP_07_09_B.Memory1[0],
     &LOG_DATI_GPS_BMP_07_09_B.Memory_k[0], &LOG_DATI_GPS_BMP_07_09_B.Memory3,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o1[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o2,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o4_j[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o5[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o6,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o8,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o10[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o12,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o13,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o14,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o15,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o16,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 9;
       LOG_DATI_GPS_BMP_07_09_B.i++) {
    LOG_DATI_GPS_BMP_07_09_B.Memory2[LOG_DATI_GPS_BMP_07_09_B.i] =
      LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[LOG_DATI_GPS_BMP_07_09_B.i];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 6;
       LOG_DATI_GPS_BMP_07_09_B.i++) {
    LOG_DATI_GPS_BMP_07_09_B.WP_info_in[LOG_DATI_GPS_BMP_07_09_B.i] =
      LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[LOG_DATI_GPS_BMP_07_09_B.i];
  }

  if ((!LOG_DATI_GPS_BMP_07_09_DW.WP_dbP_not_empty) ||
      ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[0] == 3) &&
       (LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[1] == 250))) {
    memset(&LOG_DATI_GPS_BMP_07_09_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    LOG_DATI_GPS_BMP_07_09_DW.WP_dbP_not_empty = true;
    memset(&LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!LOG_DATI_GPS_BMP_07_09_DW.WP_dbP_AL_not_empty) ||
      ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[0] == 3) &&
       (LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[1] == 250))) {
    memset(&LOG_DATI_GPS_BMP_07_09_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    LOG_DATI_GPS_BMP_07_09_DW.WP_dbP_AL_not_empty = true;
  }

  LOG_DATI_GPS_BMP_07_09_B.GC_info[0] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[0];
  LOG_DATI_GPS_BMP_07_09_B.GC_info[1] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o7[1];
  LOG_DATI_GPS_BMP_07_09_B.GC_info[2] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[0];
  if (LOG_DATI_GPS_BMP_07_09_B.GC_info[0] == 1) {
    if ((LOG_DATI_GPS_BMP_07_09_B.GC_info[1] > 0) &&
        (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(LOG_DATI_GPS_BMP_07_09_B.SFunction_o8) > 0.0F) {
        LOG_DATI_GPS_BMP_07_09_DW.riferimenti[LOG_DATI_GPS_BMP_07_09_B.GC_info[1]
          - 1] = 1.0F;
      } else {
        if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o8 == 0.0F) {
          LOG_DATI_GPS_BMP_07_09_DW.riferimenti[LOG_DATI_GPS_BMP_07_09_B.GC_info[
            1] - 1] = 0.0F;
        }
      }
    } else {
      if ((LOG_DATI_GPS_BMP_07_09_B.GC_info[1] > 7) &&
          (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] < 12)) {
        LOG_DATI_GPS_BMP_07_09_DW.riferimenti[LOG_DATI_GPS_BMP_07_09_B.GC_info[1]
          - 1] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o8;
      }
    }
  }

  if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o12 == 13) {
    LOG_DATI_GPS_BMP_07_09_DW.riferimenti[LOG_DATI_GPS_BMP_07_09_B.SFunction_o12
      - 1] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o13;
  }

  memcpy(&LOG_DATI_GPS_BMP_07_09_B.Val_out_MAV[0],
         &LOG_DATI_GPS_BMP_07_09_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((LOG_DATI_GPS_BMP_07_09_B.GC_info[0] == 3) &&
      (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] == 200)) {
    if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[0] > 6) {
      LOG_DATI_GPS_BMP_07_09_B.WP_info_in[0] = 6U;
    }

    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 6;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        LOG_DATI_GPS_BMP_07_09_B.WP_info_in[0];
    }
  }

  if ((LOG_DATI_GPS_BMP_07_09_B.GC_info[0] == 3) &&
      (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] < 200)) {
    if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o10[1] == 0.0F) {
      LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[1] +
        1U;
      if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[1] + 1U > 65535U) {
        LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
      }

      for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 7;
           LOG_DATI_GPS_BMP_07_09_B.f_l++) {
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbP[((int32_T)LOG_DATI_GPS_BMP_07_09_B.qY +
          6 * LOG_DATI_GPS_BMP_07_09_B.f_l) - 1] =
          LOG_DATI_GPS_BMP_07_09_B.SFunction_o10[LOG_DATI_GPS_BMP_07_09_B.f_l];
      }

      LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[1] +
        1U;
      if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[1] + 1U > 65535U) {
        LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
      }

      for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 6;
           LOG_DATI_GPS_BMP_07_09_B.f_l++) {
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[((int32_T)LOG_DATI_GPS_BMP_07_09_B.qY +
          6 * (LOG_DATI_GPS_BMP_07_09_B.f_l + 1)) - 1] =
          LOG_DATI_GPS_BMP_07_09_B.WP_info_in[LOG_DATI_GPS_BMP_07_09_B.f_l + 1];
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
        (LOG_DATI_GPS_BMP_07_09_B.SFunction_o10[0] + 1.0F);
      for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 7;
           LOG_DATI_GPS_BMP_07_09_B.i++) {
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbP_AL[(LOG_DATI_GPS_BMP_07_09_B.f_l + 6 *
          LOG_DATI_GPS_BMP_07_09_B.i) - 1] =
          LOG_DATI_GPS_BMP_07_09_B.SFunction_o10[LOG_DATI_GPS_BMP_07_09_B.i];
      }

      LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[1] +
        1U;
      if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o9[1] + 1U > 65535U) {
        LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
      }

      for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 6;
           LOG_DATI_GPS_BMP_07_09_B.f_l++) {
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[((int32_T)LOG_DATI_GPS_BMP_07_09_B.qY +
          6 * (LOG_DATI_GPS_BMP_07_09_B.f_l + 1)) - 1] =
          LOG_DATI_GPS_BMP_07_09_B.WP_info_in[LOG_DATI_GPS_BMP_07_09_B.f_l + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o6 == 0) &&
      (LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f == 0)) {
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 0U;
  } else if ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o6 == 0) &&
             (LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f == 3)) {
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.test1 = 0.0;
  } else if ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o6 == 0) &&
             (LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f == 2)) {
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.test1 = 0.0;
  } else if ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o6 == 0) &&
             (LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f == 1)) {
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 0U;
    LOG_DATI_GPS_BMP_07_09_DW.test1 = 1.0;
  } else {
    switch (LOG_DATI_GPS_BMP_07_09_B.SFunction_o6) {
     case 192:
      LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 192U;
      LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 208U;
      LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((LOG_DATI_GPS_BMP_07_09_B.SFunction_o6 == 220) &&
          (LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f != 5)) {
        if ((LOG_DATI_GPS_BMP_07_09_B.Memory2[0] == 0) &&
            (LOG_DATI_GPS_BMP_07_09_B.Memory2[1] == 0) &&
            ((LOG_DATI_GPS_BMP_07_09_B.Memory2[2] == 1) ||
             (LOG_DATI_GPS_BMP_07_09_B.Memory2[3] == 1) ||
             (LOG_DATI_GPS_BMP_07_09_B.Memory2[4] == 1) ||
             (LOG_DATI_GPS_BMP_07_09_B.Memory2[5] == 1) ||
             (LOG_DATI_GPS_BMP_07_09_B.Memory2[6] == 1) ||
             (LOG_DATI_GPS_BMP_07_09_B.Memory2[7] == 1))) {
          LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 220U;
          LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 220U;
        } else if ((LOG_DATI_GPS_BMP_07_09_B.Memory2[0] == 0) &&
                   (LOG_DATI_GPS_BMP_07_09_B.Memory2[1] == 1) &&
                   ((LOG_DATI_GPS_BMP_07_09_B.Memory2[2] == 1) ||
                    (LOG_DATI_GPS_BMP_07_09_B.Memory2[3] == 1) ||
                    (LOG_DATI_GPS_BMP_07_09_B.Memory2[4] == 1) ||
                    (LOG_DATI_GPS_BMP_07_09_B.Memory2[5] == 1) ||
                    (LOG_DATI_GPS_BMP_07_09_B.Memory2[6] == 1) ||
                    (LOG_DATI_GPS_BMP_07_09_B.Memory2[7] == 1))) {
          LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 220U;
          LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 220U;
        } else {
          LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 208U;
          LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput = 208U;
        }
      } else if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o3_f == 5) {
        LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 220U;
        LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] = 192U;
        LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  LOG_DATI_GPS_BMP_07_09_B.qY = 100U * LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[5];
  if (LOG_DATI_GPS_BMP_07_09_B.qY > 65535U) {
    LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
  }

  if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[4] == 0) {
    if ((uint16_T)LOG_DATI_GPS_BMP_07_09_B.qY == 0) {
      LOG_DATI_GPS_BMP_07_09_B.z = 0U;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.z = MAX_uint16_T;
    }
  } else {
    LOG_DATI_GPS_BMP_07_09_B.z = (uint16_T)
      (LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
       (uint32_T)(uint16_T)LOG_DATI_GPS_BMP_07_09_B.qY /
       LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[4]);
    LOG_DATI_GPS_BMP_07_09_B.x_e = (uint16_T)((uint32_T)(uint16_T)
      LOG_DATI_GPS_BMP_07_09_B.qY - (uint16_T)((uint32_T)
      LOG_DATI_GPS_BMP_07_09_B.z * LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[4]));
    if ((LOG_DATI_GPS_BMP_07_09_B.x_e > 0) && (LOG_DATI_GPS_BMP_07_09_B.x_e >=
         (int32_T)((uint32_T)LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[4] >> 1) +
         (LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[4] & 1))) {
      LOG_DATI_GPS_BMP_07_09_B.z++;
    }
  }

  /* RateTransition: '<S25>/Rate Transition' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition =
    LOG_DATI_GPS_BMP_07_09_DW.RateTransition_Buffer0;

  /* Sum: '<S25>/Add1' incorporates:
   *  Constant: '<S25>/Constant2'
   *  Constant: '<S25>/Constant3'
   *  Memory: '<S25>/Memory1'
   */
  LOG_DATI_GPS_BMP_07_09_B.num_254 = (LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_c
    + LOG_DATI_GPS_BMP_07_09_P.Constant3_Value_b) +
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput;

  /* Switch: '<S25>/Switch' */
  if (LOG_DATI_GPS_BMP_07_09_B.num_254 >
      LOG_DATI_GPS_BMP_07_09_P.Switch_Threshold) {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Constant2'
     */
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_c;
  } else {
    /* Switch: '<S25>/Switch' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_B.num_254;
  }

  /* End of Switch: '<S25>/Switch' */

  /* MATLAB Function: '<S14>/iflogic_function' */
  if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 1.0) ||
      (LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 3.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 26U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 2.0) ||
             (LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 4.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 30U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 2.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 33U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 6.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 34U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 0.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 0U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             ((LOG_DATI_GPS_BMP_07_09_B.RateTransition == 1.0) ||
              (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 5.0) ||
              (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 9.0))) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 1U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             ((LOG_DATI_GPS_BMP_07_09_B.RateTransition == 3.0) ||
              (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 8.0))) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 74U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 7.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 36U;
  } else if ((LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput == 0.0) &&
             (LOG_DATI_GPS_BMP_07_09_B.RateTransition == 4.0)) {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = 29U;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S14>/iflogic_function' */

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant1'
   *  Memory: '<S25>/Memory'
   */
  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput +=
    LOG_DATI_GPS_BMP_07_09_P.Constant_Value_j +
    LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_n;

  /* Gain: '<S14>/Gain' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain *
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3 =
    LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.RateTransition;

  /* MATLAB Function: '<S21>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 6;
       LOG_DATI_GPS_BMP_07_09_B.f_l++) {
    LOG_DATI_GPS_BMP_07_09_B.WP_info[LOG_DATI_GPS_BMP_07_09_B.f_l] =
      LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[6 * LOG_DATI_GPS_BMP_07_09_B.f_l];
  }

  for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 7;
       LOG_DATI_GPS_BMP_07_09_B.f_l++) {
    LOG_DATI_GPS_BMP_07_09_B.WP_param[LOG_DATI_GPS_BMP_07_09_B.f_l] =
      LOG_DATI_GPS_BMP_07_09_DW.WP_dbP[6 * LOG_DATI_GPS_BMP_07_09_B.f_l];
  }

  if ((LOG_DATI_GPS_BMP_07_09_B.GC_info[0] == 2) &&
      (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] < 6)) {
    LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_B.GC_info[1] + 1U;
    if (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] + 1U > 65535U) {
      LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
    }

    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 6;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.WP_info[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[(6 * LOG_DATI_GPS_BMP_07_09_B.f_l +
        (int32_T)LOG_DATI_GPS_BMP_07_09_B.qY) - 1];
    }

    LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_B.GC_info[1] + 1U;
    if (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] + 1U > 65535U) {
      LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
    }

    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 7;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.WP_param[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbP[(6 * LOG_DATI_GPS_BMP_07_09_B.f_l +
        (int32_T)LOG_DATI_GPS_BMP_07_09_B.qY) - 1];
    }
  }

  if ((LOG_DATI_GPS_BMP_07_09_B.GC_info[0] == 3) &&
      (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] < 200)) {
    LOG_DATI_GPS_BMP_07_09_B.qY = LOG_DATI_GPS_BMP_07_09_B.GC_info[1] + 1U;
    if (LOG_DATI_GPS_BMP_07_09_B.GC_info[1] + 1U > 65535U) {
      LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
    }

    for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l < 6;
         LOG_DATI_GPS_BMP_07_09_B.f_l++) {
      LOG_DATI_GPS_BMP_07_09_B.WP_info[LOG_DATI_GPS_BMP_07_09_B.f_l] =
        LOG_DATI_GPS_BMP_07_09_DW.WP_dbI[(6 * LOG_DATI_GPS_BMP_07_09_B.f_l +
        (int32_T)LOG_DATI_GPS_BMP_07_09_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S21>/MATLAB Function' */

  /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
   *  Constant: '<S19>/onboard_control_sensor_present uint32'
   */
  LOG_DATI_GPS_BMP_07_09_B.onboard[0] =
    LOG_DATI_GPS_BMP_07_09_P.onboard_control_sensor_presentu[0];
  LOG_DATI_GPS_BMP_07_09_B.onboard[1] =
    LOG_DATI_GPS_BMP_07_09_P.onboard_control_sensor_presentu[1];
  LOG_DATI_GPS_BMP_07_09_B.onboard[2] =
    LOG_DATI_GPS_BMP_07_09_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S19>/Gain' incorporates:
   *  Constant: '<S19>/Constant'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_i *
     LOG_DATI_GPS_BMP_07_09_P.Constant_Value_h);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
   *  Constant: '<S19>/load uint16'
   *  Gain: '<S19>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.LVDE[0] = LOG_DATI_GPS_BMP_07_09_P.loaduint16_Value;
  LOG_DATI_GPS_BMP_07_09_B.LVDE[1] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  LOG_DATI_GPS_BMP_07_09_B.qY = 10U * LOG_DATI_GPS_BMP_07_09_B.z;
  if (LOG_DATI_GPS_BMP_07_09_B.qY > 65535U) {
    LOG_DATI_GPS_BMP_07_09_B.qY = 65535U;
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
   *  Constant: '<S19>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  LOG_DATI_GPS_BMP_07_09_B.LVDE[2] = (uint16_T)LOG_DATI_GPS_BMP_07_09_B.qY;
  LOG_DATI_GPS_BMP_07_09_B.LVDE[3] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[6];
  LOG_DATI_GPS_BMP_07_09_B.LVDE[4] = LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[2];
  LOG_DATI_GPS_BMP_07_09_B.LVDE[5] = LOG_DATI_GPS_BMP_07_09_P._Value;

  /* DataTypeConversion: '<S19>/Data Type Conversion4' incorporates:
   *  Constant: '<S19>/Constant1'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_p[0]);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion4'
   */
  LOG_DATI_GPS_BMP_07_09_B.LVDE[6] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S19>/Data Type Conversion4' incorporates:
   *  Constant: '<S19>/Constant1'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_p[1]);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion4'
   */
  LOG_DATI_GPS_BMP_07_09_B.LVDE[7] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S19>/Gain2' incorporates:
   *  Constant: '<S19>/Constant3'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Gain2_Gain *
     LOG_DATI_GPS_BMP_07_09_P.Constant3_Value_c);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
   *  Gain: '<S19>/Gain1'
   *  Gain: '<S19>/Gain2'
   */
  LOG_DATI_GPS_BMP_07_09_B.B_Current = (int16_T)
    (((LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)
       -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
       (int16_T)(uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition) *
      LOG_DATI_GPS_BMP_07_09_P.Gain1_Gain_f) >> 18);

  /* DataTypeConversion: '<S19>/Data Type Conversion3' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_g);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S19>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.B_Remaining = (int8_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int8_T)-(int8_T)
     (uint8_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int8_T)
     (uint8_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Constant_Value_c);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion =
    LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.RateTransition;

  /* MATLAB Function: '<S12>/Alarm set' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  rtb_H_mav[0] = LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0];
  rtb_H_mav[1] = LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1];
  if (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_k[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_k[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S12>/Alarm set' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Type fixed_wing Autopilot generic'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[0] =
    LOG_DATI_GPS_BMP_07_09_P.Typefixed_wingAutopilotgeneric_[0];
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[1] =
    LOG_DATI_GPS_BMP_07_09_P.Typefixed_wingAutopilotgeneric_[1];
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[2] = rtb_H_mav[0];
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[3] = rtb_H_mav[1];

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/ACC simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.ACCsimulated_Value[0];

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[0] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/ACC simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.ACCsimulated_Value[1];

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[1] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/ACC simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.ACCsimulated_Value[2];

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[2] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/p simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.psimulated_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[3] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/q simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.qsimulated_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[4] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/r simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.rsimulated_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[5] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.Constant_Value_n;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[6] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_nf;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[7] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_e
    * LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_j;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[8] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/p simulated'
   *  Constant: '<S13>/phi simulated'
   *  Constant: '<S13>/psi simulated'
   *  Constant: '<S13>/q simulated'
   *  Constant: '<S13>/r simulated'
   *  Constant: '<S13>/theta simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[0] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.phisimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[1] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.thetasimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[2] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.psisimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[3] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.psimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[4] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.qsimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[5] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.rsimulated_Value;

  /* MATLABSystem: '<Root>/Serial Receive1' */
  if (LOG_DATI_GPS_BMP_07_09_DW.obj_l.Protocol !=
      LOG_DATI_GPS_BMP_07_09_P.SerialReceive1_Protocol) {
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.Protocol =
      LOG_DATI_GPS_BMP_07_09_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, LOG_DATI_GPS_BMP_07_09_DW.obj_l.DataSizeInBytes,
                 &LOG_DATI_GPS_BMP_07_09_B.b_dataOut[0], &counter);

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem2' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (counter > 0) {
    /* MATLAB Function: '<S5>/Create_message' */
    counter = 0U;
    if (!LOG_DATI_GPS_BMP_07_09_DW.start_found) {
      LOG_DATI_GPS_BMP_07_09_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.i - 1 < 32)) {
        if (LOG_DATI_GPS_BMP_07_09_B.b_dataOut[(uint8_T)
            LOG_DATI_GPS_BMP_07_09_B.i - 1] == 36) {
          LOG_DATI_GPS_BMP_07_09_B.caso = 32 - (uint8_T)
            LOG_DATI_GPS_BMP_07_09_B.i;
          for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <=
               LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
            LOG_DATI_GPS_BMP_07_09_DW.message[LOG_DATI_GPS_BMP_07_09_B.f_l] =
              LOG_DATI_GPS_BMP_07_09_B.b_dataOut[((uint8_T)
              LOG_DATI_GPS_BMP_07_09_B.i + LOG_DATI_GPS_BMP_07_09_B.f_l) - 1];
          }

          LOG_DATI_GPS_BMP_07_09_DW.counter_c = (uint8_T)(33 - (uint8_T)
            LOG_DATI_GPS_BMP_07_09_B.i);
          LOG_DATI_GPS_BMP_07_09_DW.start_found = true;
          exitg1 = true;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.i++;
        }
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_B.f_l = 1;
      exitg1 = false;
      while ((!exitg1) && (LOG_DATI_GPS_BMP_07_09_B.f_l - 1 < 32)) {
        if (LOG_DATI_GPS_BMP_07_09_B.b_dataOut[(uint8_T)
            LOG_DATI_GPS_BMP_07_09_B.f_l - 1] == 13) {
          LOG_DATI_GPS_BMP_07_09_DW.end_found = true;
          counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.f_l;
          exitg1 = true;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.f_l++;
        }
      }

      if (LOG_DATI_GPS_BMP_07_09_DW.end_found) {
        if (1 > counter) {
          LOG_DATI_GPS_BMP_07_09_B.caso = -1;
        } else {
          LOG_DATI_GPS_BMP_07_09_B.caso = counter - 1;
        }

        for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <=
             LOG_DATI_GPS_BMP_07_09_B.caso; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
          LOG_DATI_GPS_BMP_07_09_B.i = (int32_T)(((uint32_T)
            LOG_DATI_GPS_BMP_07_09_B.f_l + LOG_DATI_GPS_BMP_07_09_DW.counter_c)
            + 1U);
          if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.i > 255U) {
            LOG_DATI_GPS_BMP_07_09_B.i = 255;
          }

          LOG_DATI_GPS_BMP_07_09_DW.message[LOG_DATI_GPS_BMP_07_09_B.i - 1] =
            LOG_DATI_GPS_BMP_07_09_B.b_dataOut[LOG_DATI_GPS_BMP_07_09_B.f_l];
        }

        memcpy(&LOG_DATI_GPS_BMP_07_09_B.messaggio_c[0],
               &LOG_DATI_GPS_BMP_07_09_DW.message[0], 80U * sizeof(uint8_T));
        LOG_DATI_GPS_BMP_07_09_DW.end_found = false;
        LOG_DATI_GPS_BMP_07_09_DW.counter_c = (uint8_T)(32 - counter);
        if (counter == 32) {
          LOG_DATI_GPS_BMP_07_09_DW.start_found = false;
          memset(&LOG_DATI_GPS_BMP_07_09_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          LOG_DATI_GPS_BMP_07_09_DW.start_found = true;
          LOG_DATI_GPS_BMP_07_09_B.caso = -counter;
          for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <=
               LOG_DATI_GPS_BMP_07_09_B.caso + 31; LOG_DATI_GPS_BMP_07_09_B.f_l
               ++) {
            LOG_DATI_GPS_BMP_07_09_DW.message[LOG_DATI_GPS_BMP_07_09_B.f_l] =
              LOG_DATI_GPS_BMP_07_09_B.b_dataOut[counter +
              LOG_DATI_GPS_BMP_07_09_B.f_l];
          }

          LOG_DATI_GPS_BMP_07_09_B.f_l = counter + 48;
          if (0 <= LOG_DATI_GPS_BMP_07_09_B.f_l - 1) {
            memset(&LOG_DATI_GPS_BMP_07_09_DW.message[-counter + 32], 0,
                   ((LOG_DATI_GPS_BMP_07_09_B.f_l - counter) + counter) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
         *  EnablePort: '<S41>/Enable'
         */
        /* MATLAB Function: '<S41>/MATLAB Function' */
        counter = 0U;
        find_comma = 0U;
        LOG_DATI_GPS_BMP_07_09_B.indice_dimario = 0U;
        for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 80;
             LOG_DATI_GPS_BMP_07_09_B.i++) {
          messaggio = (int8_T)
            LOG_DATI_GPS_BMP_07_09_B.messaggio_c[LOG_DATI_GPS_BMP_07_09_B.i];
          if (messaggio == '$') {
            LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(counter + 1U);
            if (counter + 1U > 255U) {
              LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
            }

            counter = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.f_l;
          }

          if (messaggio == ',') {
            LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
            }

            find_comma = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.f_l;
          }

          LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.i] =
            messaggio;
        }

        if ((counter == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
               80; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
            LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l] =
              (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l] ==
               '$');
          }

          LOG_DATI_GPS_BMP_07_09_eml_find(LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
            &LOG_DATI_GPS_BMP_07_09_B.eb_data, LOG_DATI_GPS_BMP_07_09_B.eb_size);
          LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.eb_data;
          for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
               5; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
            messaggio =
              LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l +
              LOG_DATI_GPS_BMP_07_09_B.status];
            LOG_DATI_GPS_BMP_07_09_B.mess_type_d[LOG_DATI_GPS_BMP_07_09_B.f_l] =
              (messaggio == bb[LOG_DATI_GPS_BMP_07_09_B.f_l]);
            LOG_DATI_GPS_BMP_07_09_B.mess_type[LOG_DATI_GPS_BMP_07_09_B.f_l] =
              messaggio;
          }

          if (LOG_DATI_GPS_BMP__ifWhileCond_k
              (LOG_DATI_GPS_BMP_07_09_B.mess_type_d)) {
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 80; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l]
                 == ',');
            }

            LOG_DATI_GPS_BMP_07__eml_find_e(LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
              LOG_DATI_GPS_BMP_07_09_B.comma_gga_data,
              LOG_DATI_GPS_BMP_07_09_B.eb_size);
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 80; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l]
                 == '*');
            }

            LOG_DATI_GPS_BMP_07__eml_find_e(LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
              LOG_DATI_GPS_BMP_07_09_B.star_data,
              LOG_DATI_GPS_BMP_07_09_B.star_size);
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 80; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l]
                 == '$');
            }

            LOG_DATI_GPS_BMP_07__eml_find_e(LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
              LOG_DATI_GPS_BMP_07_09_B.fb_data,
              LOG_DATI_GPS_BMP_07_09_B.star_size);
            LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_07__str2double
              (&LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.comma_gga_data
               [2]]);
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[2] + 3.0 >
                (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[3] - 1.0) {
              LOG_DATI_GPS_BMP_07_09_B.caso = 0;
              LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.caso =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[2] + 2;
              LOG_DATI_GPS_BMP_07_09_B.f_l =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[3] - 1;
            }

            LOG_DATI_GPS_BMP_07_09_B.messaggio_size[0] = 1;
            LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
              LOG_DATI_GPS_BMP_07_09_B.caso;
            LOG_DATI_GPS_BMP_07_09_B.messaggio_size[1] =
              LOG_DATI_GPS_BMP_07_09_B.status;
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l++)
            {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                + LOG_DATI_GPS_BMP_07_09_B.f_l];
            }

            LOG_DATI_GPS_BMP_07_09_B.b_x = LOG_DATI_GPS_BMP_0_str2double_i
              (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
               LOG_DATI_GPS_BMP_07_09_B.messaggio_size);
            if (LOG_DATI_GPS_BMP_07_09_B.b_x.im == 0.0) {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
            } else if (LOG_DATI_GPS_BMP_07_09_B.b_x.re == 0.0) {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
            }

            LOG_DATI_GPS_BMP_07_09_B.num_254 = LOG_DATI_GPS_BMP_07_09_B.Lat_1.re
              + LOG_DATI_GPS_BMP_07_09_B.RateTransition;
            LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.eb_size[0] *
              LOG_DATI_GPS_BMP_07_09_B.eb_size[1] - 1;
            if (0 <= LOG_DATI_GPS_BMP_07_09_B.caso) {
              memcpy(&LOG_DATI_GPS_BMP_07_09_B.tmp_data[0],
                     &LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[0],
                     (LOG_DATI_GPS_BMP_07_09_B.caso + 1) * sizeof(int32_T));
            }

            if (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.tmp_data
                [3]] == 'S') {
              LOG_DATI_GPS_BMP_07_09_B.num_254 =
                -LOG_DATI_GPS_BMP_07_09_B.num_254;
            }

            LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP__str2double_i2
              (&LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.comma_gga_data
               [4]]);
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[4] + 4.0 >
                (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[5] - 1.0) {
              LOG_DATI_GPS_BMP_07_09_B.i = 0;
              LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.i =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[4] + 3;
              LOG_DATI_GPS_BMP_07_09_B.f_l =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[5] - 1;
            }

            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_k[0] = 1;
            LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
              LOG_DATI_GPS_BMP_07_09_B.i;
            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_k[1] =
              LOG_DATI_GPS_BMP_07_09_B.status;
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l++)
            {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                = LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.i
                + LOG_DATI_GPS_BMP_07_09_B.f_l];
            }

            LOG_DATI_GPS_BMP_07_09_B.b_x = LOG_DATI_GPS_BMP_0_str2double_i
              (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
               LOG_DATI_GPS_BMP_07_09_B.messaggio_size_k);
            if (LOG_DATI_GPS_BMP_07_09_B.b_x.im == 0.0) {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
            } else if (LOG_DATI_GPS_BMP_07_09_B.b_x.re == 0.0) {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
            }

            LOG_DATI_GPS_BMP_07_09_B.RateTransition +=
              LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
            if (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.tmp_data
                [5]] == 'W') {
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                -LOG_DATI_GPS_BMP_07_09_B.RateTransition;
            }

            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[6] + 1.0 >
                (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[7] - 1.0) {
              LOG_DATI_GPS_BMP_07_09_B.i = 0;
              LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.i =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[6];
              LOG_DATI_GPS_BMP_07_09_B.f_l =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[7] - 1;
            }

            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_c[0] = 1;
            LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
              LOG_DATI_GPS_BMP_07_09_B.i;
            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_c[1] =
              LOG_DATI_GPS_BMP_07_09_B.status;
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l++)
            {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                = LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.i
                + LOG_DATI_GPS_BMP_07_09_B.f_l];
            }

            LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_0_str2double_i
              (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
               LOG_DATI_GPS_BMP_07_09_B.messaggio_size_c);

            /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[2] =
              LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[7] + 1.0 >
                (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[8] - 1.0) {
              LOG_DATI_GPS_BMP_07_09_B.caso = 0;
              LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.caso =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[7];
              LOG_DATI_GPS_BMP_07_09_B.f_l =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[8] - 1;
            }

            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_b[0] = 1;
            LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
              LOG_DATI_GPS_BMP_07_09_B.caso;
            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_b[1] =
              LOG_DATI_GPS_BMP_07_09_B.status;
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l++)
            {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                + LOG_DATI_GPS_BMP_07_09_B.f_l];
            }

            LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_0_str2double_i
              (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
               LOG_DATI_GPS_BMP_07_09_B.messaggio_size_b);

            /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[4] =
              LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[9] + 1.0 >
                (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[10] - 1.0) {
              LOG_DATI_GPS_BMP_07_09_B.caso = 0;
              LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.caso =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[9];
              LOG_DATI_GPS_BMP_07_09_B.f_l =
                LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[10] - 1;
            }

            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_p[0] = 1;
            LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
              LOG_DATI_GPS_BMP_07_09_B.caso;
            LOG_DATI_GPS_BMP_07_09_B.messaggio_size_p[1] =
              LOG_DATI_GPS_BMP_07_09_B.status;
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l++)
            {
              LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                + LOG_DATI_GPS_BMP_07_09_B.f_l];
            }

            LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_0_str2double_i
              (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
               LOG_DATI_GPS_BMP_07_09_B.messaggio_size_p);

            /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[3] =
              LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
            if (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.tmp_data
                [10]] == 'W') {
              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[3] =
                -LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] =
              LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[5];
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[6] =
              LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[6];
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[7] =
              LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[7];
            LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[8] =
              LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[8];
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 1.0 >= 0.0) {
                counter = (uint8_T)((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0]
                                    + 1.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[0] = LOG_DATI_GPS_BMP_07_09_B.messaggio[counter - 1];
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 2.0 >= 0.0) {
                counter = (uint8_T)((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0]
                                    + 2.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[1] = LOG_DATI_GPS_BMP_07_09_B.messaggio[counter - 1];
            if ((real_T)LOG_DATI_GPS_BMP_07_09_B.fb_data[0] + 1.0 > (real_T)
                LOG_DATI_GPS_BMP_07_09_B.star_data[0] - 1.0) {
              LOG_DATI_GPS_BMP_07_09_B.caso = 0;
              LOG_DATI_GPS_BMP_07_09_B.status = 0;
            } else {
              LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.fb_data[0];
              LOG_DATI_GPS_BMP_07_09_B.status =
                LOG_DATI_GPS_BMP_07_09_B.star_data[0] - 1;
            }

            LOG_DATI_GPS_BMP_07_09_B.status -= LOG_DATI_GPS_BMP_07_09_B.caso;
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l++)
            {
              LOG_DATI_GPS_BMP_07_09_B.NMEA_gga_string_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                = (uint8_T)
                LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                + LOG_DATI_GPS_BMP_07_09_B.f_l];
            }

            counter = 0U;
            LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
            while (LOG_DATI_GPS_BMP_07_09_B.f_l <=
                   LOG_DATI_GPS_BMP_07_09_B.status - 1) {
              counter ^=
                LOG_DATI_GPS_BMP_07_09_B.NMEA_gga_string_data[LOG_DATI_GPS_BMP_07_09_B.f_l];
              LOG_DATI_GPS_BMP_07_09_B.f_l++;
            }

            if (counter != LOG_DATI_GPS_BMP_07_09_hex2dec(ck_ric)) {
              LOG_DATI_GPS_BMP_07_09_B.num_254 =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[0];
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[1];

              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[2] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[2];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[3] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[3];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[4] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[4];
              LOG_DATI_GPS_BMP_07_09_B.indice_dimario = 10U;
            }
          } else {
            for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0; LOG_DATI_GPS_BMP_07_09_B.f_l <
                 5; LOG_DATI_GPS_BMP_07_09_B.f_l++) {
              LOG_DATI_GPS_BMP_07_09_B.mess_type_d[LOG_DATI_GPS_BMP_07_09_B.f_l]
                =
                (LOG_DATI_GPS_BMP_07_09_B.mess_type[LOG_DATI_GPS_BMP_07_09_B.f_l]
                 == cb[LOG_DATI_GPS_BMP_07_09_B.f_l]);
            }

            if (LOG_DATI_GPS_BMP__ifWhileCond_k
                (LOG_DATI_GPS_BMP_07_09_B.mess_type_d)) {
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l < 80;
                   LOG_DATI_GPS_BMP_07_09_B.f_l++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l]
                   == ',');
              }

              LOG_DATI_GPS_BMP_07__eml_find_e
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
                 LOG_DATI_GPS_BMP_07_09_B.comma_gga_data,
                 LOG_DATI_GPS_BMP_07_09_B.eb_size);
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l < 80;
                   LOG_DATI_GPS_BMP_07_09_B.f_l++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l]
                   == '*');
              }

              LOG_DATI_GPS_BMP_07__eml_find_e
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
                 LOG_DATI_GPS_BMP_07_09_B.star_data,
                 LOG_DATI_GPS_BMP_07_09_B.star_size);
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l < 80;
                   LOG_DATI_GPS_BMP_07_09_B.f_l++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_m[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.f_l]
                   == '$');
              }

              LOG_DATI_GPS_BMP_07__eml_find_e
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_m,
                 LOG_DATI_GPS_BMP_07_09_B.fb_data,
                 LOG_DATI_GPS_BMP_07_09_B.star_size);
              LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_07__str2double
                (&LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.comma_gga_data
                 [1]]);
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[1] + 3.0 >
                  (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[2] - 1.0) {
                LOG_DATI_GPS_BMP_07_09_B.caso = 0;
                LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.caso =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[1] + 2;
                LOG_DATI_GPS_BMP_07_09_B.f_l =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[2] - 1;
              }

              LOG_DATI_GPS_BMP_07_09_B.messaggio_size[0] = 1;
              LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
                LOG_DATI_GPS_BMP_07_09_B.caso;
              LOG_DATI_GPS_BMP_07_09_B.messaggio_size[1] =
                LOG_DATI_GPS_BMP_07_09_B.status;
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l <
                   LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l
                   ++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                  + LOG_DATI_GPS_BMP_07_09_B.f_l];
              }

              LOG_DATI_GPS_BMP_07_09_B.b_x = LOG_DATI_GPS_BMP_0_str2double_i
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
                 LOG_DATI_GPS_BMP_07_09_B.messaggio_size);
              if (LOG_DATI_GPS_BMP_07_09_B.b_x.im == 0.0) {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                  LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
              } else if (LOG_DATI_GPS_BMP_07_09_B.b_x.re == 0.0) {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                  LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
              }

              LOG_DATI_GPS_BMP_07_09_B.num_254 =
                LOG_DATI_GPS_BMP_07_09_B.Lat_1.re +
                LOG_DATI_GPS_BMP_07_09_B.RateTransition;
              LOG_DATI_GPS_BMP_07_09_B.caso = LOG_DATI_GPS_BMP_07_09_B.eb_size[0]
                * LOG_DATI_GPS_BMP_07_09_B.eb_size[1] - 1;
              if (0 <= LOG_DATI_GPS_BMP_07_09_B.caso) {
                memcpy(&LOG_DATI_GPS_BMP_07_09_B.tmp_data[0],
                       &LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[0],
                       (LOG_DATI_GPS_BMP_07_09_B.caso + 1) * sizeof(int32_T));
              }

              if (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.tmp_data
                  [2]] == 'S') {
                LOG_DATI_GPS_BMP_07_09_B.num_254 =
                  -LOG_DATI_GPS_BMP_07_09_B.num_254;
              }

              LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP__str2double_i2
                (&LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.comma_gga_data
                 [3]]);
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[3] + 4.0 >
                  (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[4] - 1.0) {
                LOG_DATI_GPS_BMP_07_09_B.i = 0;
                LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.i =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[3] + 3;
                LOG_DATI_GPS_BMP_07_09_B.f_l =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[4] - 1;
              }

              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_k[0] = 1;
              LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
                LOG_DATI_GPS_BMP_07_09_B.i;
              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_k[1] =
                LOG_DATI_GPS_BMP_07_09_B.status;
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l <
                   LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l
                   ++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.i
                  + LOG_DATI_GPS_BMP_07_09_B.f_l];
              }

              LOG_DATI_GPS_BMP_07_09_B.b_x = LOG_DATI_GPS_BMP_0_str2double_i
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
                 LOG_DATI_GPS_BMP_07_09_B.messaggio_size_k);
              if (LOG_DATI_GPS_BMP_07_09_B.b_x.im == 0.0) {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                  LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
              } else if (LOG_DATI_GPS_BMP_07_09_B.b_x.re == 0.0) {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                  LOG_DATI_GPS_BMP_07_09_B.b_x.re / 60.0;
              }

              LOG_DATI_GPS_BMP_07_09_B.RateTransition +=
                LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
              if (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.tmp_data
                  [4]] == 'W') {
                LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                  -LOG_DATI_GPS_BMP_07_09_B.RateTransition;
              }

              LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_str2double_i2v
                (LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] =
                LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[6] + 1.0 >
                  (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[7] - 1.0) {
                LOG_DATI_GPS_BMP_07_09_B.caso = 0;
                LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.caso =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[6];
                LOG_DATI_GPS_BMP_07_09_B.f_l =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[7] - 1;
              }

              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_c[0] = 1;
              LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
                LOG_DATI_GPS_BMP_07_09_B.caso;
              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_c[1] =
                LOG_DATI_GPS_BMP_07_09_B.status;
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l <
                   LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l
                   ++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                  + LOG_DATI_GPS_BMP_07_09_B.f_l];
              }

              LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_0_str2double_i
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
                 LOG_DATI_GPS_BMP_07_09_B.messaggio_size_c);

              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[6] =
                LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[8] + 1.0 >
                  (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[9] - 1.0) {
                LOG_DATI_GPS_BMP_07_09_B.i = 0;
                LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.i =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[8];
                LOG_DATI_GPS_BMP_07_09_B.f_l =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[9] - 1;
              }

              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_b[0] = 1;
              LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
                LOG_DATI_GPS_BMP_07_09_B.i;
              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_b[1] =
                LOG_DATI_GPS_BMP_07_09_B.status;
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l <
                   LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l
                   ++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.i
                  + LOG_DATI_GPS_BMP_07_09_B.f_l];
              }

              LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_0_str2double_i
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
                 LOG_DATI_GPS_BMP_07_09_B.messaggio_size_b);

              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[7] =
                LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[10] + 1.0 >
                  (real_T)LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[11] - 1.0) {
                LOG_DATI_GPS_BMP_07_09_B.x_d = 0;
                LOG_DATI_GPS_BMP_07_09_B.caso = 0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.x_d =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[10];
                LOG_DATI_GPS_BMP_07_09_B.caso =
                  LOG_DATI_GPS_BMP_07_09_B.comma_gga_data[11] - 1;
              }

              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_p[0] = 1;
              LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.caso -
                LOG_DATI_GPS_BMP_07_09_B.x_d;
              LOG_DATI_GPS_BMP_07_09_B.messaggio_size_p[1] =
                LOG_DATI_GPS_BMP_07_09_B.status;
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l <
                   LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l
                   ++) {
                LOG_DATI_GPS_BMP_07_09_B.messaggio_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  =
                  LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.x_d
                  + LOG_DATI_GPS_BMP_07_09_B.f_l];
              }

              LOG_DATI_GPS_BMP_07_09_B.Lat_1 = LOG_DATI_GPS_BMP_0_str2double_i
                (LOG_DATI_GPS_BMP_07_09_B.messaggio_data,
                 LOG_DATI_GPS_BMP_07_09_B.messaggio_size_p);

              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[8] =
                LOG_DATI_GPS_BMP_07_09_B.Lat_1.re;
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[2] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[2];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[3] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[3];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[4] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[4];
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 1.0 >= 0.0)
                {
                  counter = (uint8_T)((real_T)
                                      LOG_DATI_GPS_BMP_07_09_B.star_data[0] +
                                      1.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[0] = LOG_DATI_GPS_BMP_07_09_B.messaggio[counter - 1];
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)LOG_DATI_GPS_BMP_07_09_B.star_data[0] + 2.0 >= 0.0)
                {
                  counter = (uint8_T)((real_T)
                                      LOG_DATI_GPS_BMP_07_09_B.star_data[0] +
                                      2.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[1] = LOG_DATI_GPS_BMP_07_09_B.messaggio[counter - 1];
              if ((real_T)LOG_DATI_GPS_BMP_07_09_B.fb_data[0] + 1.0 > (real_T)
                  LOG_DATI_GPS_BMP_07_09_B.star_data[0] - 1.0) {
                LOG_DATI_GPS_BMP_07_09_B.caso = 0;
                LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
              } else {
                LOG_DATI_GPS_BMP_07_09_B.caso =
                  LOG_DATI_GPS_BMP_07_09_B.fb_data[0];
                LOG_DATI_GPS_BMP_07_09_B.f_l =
                  LOG_DATI_GPS_BMP_07_09_B.star_data[0] - 1;
              }

              LOG_DATI_GPS_BMP_07_09_B.status = LOG_DATI_GPS_BMP_07_09_B.f_l -
                LOG_DATI_GPS_BMP_07_09_B.caso;
              for (LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
                   LOG_DATI_GPS_BMP_07_09_B.f_l <
                   LOG_DATI_GPS_BMP_07_09_B.status; LOG_DATI_GPS_BMP_07_09_B.f_l
                   ++) {
                LOG_DATI_GPS_BMP_07_09_B.NMEA_gga_string_data[LOG_DATI_GPS_BMP_07_09_B.f_l]
                  = (uint8_T)
                  LOG_DATI_GPS_BMP_07_09_B.messaggio[LOG_DATI_GPS_BMP_07_09_B.caso
                  + LOG_DATI_GPS_BMP_07_09_B.f_l];
              }

              counter = 0U;
              LOG_DATI_GPS_BMP_07_09_B.f_l = 0;
              while (LOG_DATI_GPS_BMP_07_09_B.f_l <=
                     LOG_DATI_GPS_BMP_07_09_B.status - 1) {
                counter ^=
                  LOG_DATI_GPS_BMP_07_09_B.NMEA_gga_string_data[LOG_DATI_GPS_BMP_07_09_B.f_l];
                LOG_DATI_GPS_BMP_07_09_B.f_l++;
              }

              if (counter != LOG_DATI_GPS_BMP_07_09_hex2dec(ck_ric)) {
                LOG_DATI_GPS_BMP_07_09_B.num_254 =
                  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[0];
                LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[1];

                /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
                LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] =
                  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[5];
                LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[6] =
                  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[6];
                LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[7] =
                  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[7];
                LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[8] =
                  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[8];
                LOG_DATI_GPS_BMP_07_09_B.indice_dimario = 20U;
              }
            } else {
              LOG_DATI_GPS_BMP_07_09_B.num_254 =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[0];
              LOG_DATI_GPS_BMP_07_09_B.RateTransition =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[1];

              /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[2] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[2];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[3] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[3];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[4] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[4];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[5];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[6] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[6];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[7] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[7];
              LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[8] =
                LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[8];
            }
          }
        } else {
          LOG_DATI_GPS_BMP_07_09_B.num_254 =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[0];
          LOG_DATI_GPS_BMP_07_09_B.RateTransition =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[1];

          /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[2] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[2];
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[3] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[3];
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[4] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[4];
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[5];
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[6] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[6];
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[7] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[7];
          LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[8] =
            LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[8];
        }

        /* End of MATLAB Function: '<S41>/MATLAB Function' */

        /* ComplexToRealImag: '<S41>/Complex to Real-Imag' */
        LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[0] =
          LOG_DATI_GPS_BMP_07_09_B.num_254;
        LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[1] =
          LOG_DATI_GPS_BMP_07_09_B.RateTransition;

        /* Update for Memory: '<S41>/Memory' */
        memcpy(&LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[0],
               &LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[0], 9U * sizeof
               (real_T));

        /* End of Outputs for SubSystem: '<S5>/Subsystem' */
      } else {
        for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 32;
             LOG_DATI_GPS_BMP_07_09_B.i++) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)(((uint32_T)
            LOG_DATI_GPS_BMP_07_09_DW.counter_c + LOG_DATI_GPS_BMP_07_09_B.i) +
            1U);
          if ((uint32_T)LOG_DATI_GPS_BMP_07_09_B.f_l > 255U) {
            LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
          }

          LOG_DATI_GPS_BMP_07_09_DW.message[LOG_DATI_GPS_BMP_07_09_B.f_l - 1] =
            LOG_DATI_GPS_BMP_07_09_B.b_dataOut[LOG_DATI_GPS_BMP_07_09_B.i];
        }

        LOG_DATI_GPS_BMP_07_09_B.f_l = (int32_T)
          (LOG_DATI_GPS_BMP_07_09_DW.counter_c + 32U);
        if (LOG_DATI_GPS_BMP_07_09_DW.counter_c + 32U > 255U) {
          LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
        }

        LOG_DATI_GPS_BMP_07_09_DW.counter_c = (uint8_T)
          LOG_DATI_GPS_BMP_07_09_B.f_l;
      }
    }

    /* End of MATLAB Function: '<S5>/Create_message' */
  }

  /* End of MATLABSystem: '<Root>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o14 > 0) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant3'
     *  Logic: '<S4>/OR'
     *  RelationalOperator: '<S4>/Equal'
     *  RelationalOperator: '<S4>/Equal1'
     *  RelationalOperator: '<S4>/Equal2'
     */
    if ((LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] ==
         LOG_DATI_GPS_BMP_07_09_P.Constant_Value) ||
        (LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] ==
         LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_g) ||
        (LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5] ==
         LOG_DATI_GPS_BMP_07_09_P.Constant3_Value_d)) {
      /* Switch: '<S4>/Switch' */
      LOG_DATI_GPS_BMP_07_09_B.Switch =
        LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Constant2'
       */
      LOG_DATI_GPS_BMP_07_09_B.Switch =
        LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_i;
    }

    /* End of Switch: '<S4>/Switch' */
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* Sum: '<Root>/Sum' */
  LOG_DATI_GPS_BMP_07_09_B.num_254 = LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag
    [7] - LOG_DATI_GPS_BMP_07_09_B.Switch;

  /* Gain: '<S11>/Gain' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition =
    LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_h[0] *
    LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_n[0] =
    LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.RateTransition;

  /* Gain: '<S11>/Gain' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition =
    LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_h[1] *
    LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_n[1] =
    LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.RateTransition;

  /* Gain: '<S11>/Gain' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition =
    LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_h[2] * LOG_DATI_GPS_BMP_07_09_B.num_254;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_n[2] =
    LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.RateTransition;

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/alt_r'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition =
    LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_h[3] *
    LOG_DATI_GPS_BMP_07_09_P.alt_r_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_n[3] =
    LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.RateTransition;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Gain: '<S11>/Gain1'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Gain1_Gain *
     LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[2]);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[0] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/vel y'
   *  Gain: '<S11>/Gain1'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Gain1_Gain * LOG_DATI_GPS_BMP_07_09_P.vely_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[1] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/RC Simulated'
   *  Gain: '<S11>/Gain1'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Gain1_Gain *
     LOG_DATI_GPS_BMP_07_09_P.RCSimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[2] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S11>/Gain2' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition =
    LOG_DATI_GPS_BMP_07_09_P.Gain2_Gain_k *
    LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[4];

  /* DataTypeConversion: '<S11>/Data Type Conversion2' */
  if (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion10' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion10 = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* SignalConversion generated from: '<S36>/Enable' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !LOG_DATI_GPS_BMP_07_09_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  LOG_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization,
    &LOG_DATI_GPS_BMP_07_09_DW.One_time_initialization,
    &LOG_DATI_GPS_BMP_07_09_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (LOG_DATI_GPS_BMP_07_09_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S33>/I2C Read12' */
    if (LOG_DATI_GPS_BMP_07_09_DW.obj_d.SampleTime !=
        LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      LOG_DATI_GPS_BMP_07_09_DW.obj_d.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (LOG_DATI_GPS_BMP_07_09_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &counter, 1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead
        (LOG_DATI_GPS_BMP_07_09_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S33>/I2C Read1' */
    if (LOG_DATI_GPS_BMP_07_09_DW.obj_i.SampleTime !=
        LOG_DATI_GPS_BMP_07_09_P.t_AP) {
      LOG_DATI_GPS_BMP_07_09_DW.obj_i.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (LOG_DATI_GPS_BMP_07_09_DW.obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &counter, 1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead
        (LOG_DATI_GPS_BMP_07_09_DW.obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &LOG_DATI_GPS_BMP_07_09_B.output_raw[0], 3U, false, true);
      memcpy((void *)&LOG_DATI_GPS_BMP_07_09_B.output[0], (void *)
             &LOG_DATI_GPS_BMP_07_09_B.output_raw[0], (uint32_T)((size_t)3 *
              sizeof(uint8_T)));
    } else {
      LOG_DATI_GPS_BMP_07_09_B.output[0] = 0U;
      LOG_DATI_GPS_BMP_07_09_B.output[1] = 0U;
      LOG_DATI_GPS_BMP_07_09_B.output[2] = 0U;
    }

    /* ArithShift: '<S33>/Shift Arithmetic4' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
        (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
        (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S33>/Shift Arithmetic3' incorporates:
     *  Constant: '<S33>/Constant5'
     */
    LOG_DATI_GPS_BMP_07_09_B.UkYk1 = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant5_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.UkYk1) || rtIsInf
        (LOG_DATI_GPS_BMP_07_09_B.UkYk1)) {
      LOG_DATI_GPS_BMP_07_09_B.UkYk1 = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.UkYk1 = fmod(LOG_DATI_GPS_BMP_07_09_B.UkYk1,
        4.294967296E+9);
    }

    /* ArithShift: '<S33>/Shift Arithmetic1' incorporates:
     *  Constant: '<S33>/Constant6'
     */
    LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant6_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.deltafalllimit) || rtIsInf
        (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit)) {
      LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = fmod
        (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S33>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S33>/Shift Arithmetic1'
     *  ArithShift: '<S33>/Shift Arithmetic3'
     *  ArithShift: '<S33>/Shift Arithmetic4'
     *  Constant: '<S33>/Constant10'
     *  Constant: '<S33>/Constant11'
     *  Constant: '<S33>/Constant7'
     *  MATLABSystem: '<S33>/I2C Read1'
     *  Sum: '<S33>/Sum1'
     *  Sum: '<S33>/Sum4'
     *  Sum: '<S33>/Sum5'
     *  Sum: '<S33>/Sum6'
     */
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_l = (int32_T)
      ((((((LOG_DATI_GPS_BMP_07_09_P.Constant7_Value +
            LOG_DATI_GPS_BMP_07_09_B.output[0]) <<
           (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
            -LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint32_T)
            LOG_DATI_GPS_BMP_07_09_B.RateTransition)) +
          ((LOG_DATI_GPS_BMP_07_09_P.Constant10_Value_i +
            LOG_DATI_GPS_BMP_07_09_B.output[1]) <<
           (LOG_DATI_GPS_BMP_07_09_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
            -LOG_DATI_GPS_BMP_07_09_B.UkYk1 : (int32_T)(uint32_T)
            LOG_DATI_GPS_BMP_07_09_B.UkYk1))) +
         LOG_DATI_GPS_BMP_07_09_P.Constant11_Value) +
        LOG_DATI_GPS_BMP_07_09_B.output[2]) >>
       (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -LOG_DATI_GPS_BMP_07_09_B.deltafalllimit : (int32_T)(uint32_T)
        LOG_DATI_GPS_BMP_07_09_B.deltafalllimit));

    /* ArithShift: '<S33>/Shift Arithmetic7' incorporates:
     *  Constant: '<S33>/Constant2'
     */
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant2_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
        (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
        (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S33>/Shift Arithmetic6' incorporates:
     *  Constant: '<S33>/Constant3'
     */
    LOG_DATI_GPS_BMP_07_09_B.UkYk1 = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant3_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.UkYk1) || rtIsInf
        (LOG_DATI_GPS_BMP_07_09_B.UkYk1)) {
      LOG_DATI_GPS_BMP_07_09_B.UkYk1 = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.UkYk1 = fmod(LOG_DATI_GPS_BMP_07_09_B.UkYk1,
        4.294967296E+9);
    }

    /* ArithShift: '<S33>/Shift Arithmetic2' incorporates:
     *  Constant: '<S33>/Constant4'
     */
    LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant4_Value);
    if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.deltafalllimit) || rtIsInf
        (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit)) {
      LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = 0.0;
    } else {
      LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = fmod
        (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S33>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S33>/Shift Arithmetic2'
     *  ArithShift: '<S33>/Shift Arithmetic6'
     *  ArithShift: '<S33>/Shift Arithmetic7'
     *  Constant: '<S33>/Constant8'
     *  Constant: '<S33>/Constant9'
     *  MATLABSystem: '<S33>/I2C Read12'
     *  Sum: '<S33>/Sum'
     *  Sum: '<S33>/Sum2'
     *  Sum: '<S33>/Sum3'
     */
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_p = (int32_T)
      ((((LOG_DATI_GPS_BMP_07_09_P.Constant8_Value + rtb_H_mav[0]) <<
         (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint32_T)
          LOG_DATI_GPS_BMP_07_09_B.RateTransition)) + ((rtb_H_mav[1] +
          LOG_DATI_GPS_BMP_07_09_P.Constant9_Value) <<
         (LOG_DATI_GPS_BMP_07_09_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
          -LOG_DATI_GPS_BMP_07_09_B.UkYk1 : (int32_T)(uint32_T)
          LOG_DATI_GPS_BMP_07_09_B.UkYk1))) >>
       (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -LOG_DATI_GPS_BMP_07_09_B.deltafalllimit : (int32_T)(uint32_T)
        LOG_DATI_GPS_BMP_07_09_B.deltafalllimit));

    /* S-Function (calc_T): '<S33>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead1,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead2,
       &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_p,
       &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1,
       &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2_i);

    /* S-Function (calc_p): '<S33>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead3,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead4,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead5,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead6,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead7,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead8,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead9,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead10,
       &LOG_DATI_GPS_BMP_07_09_B.One_time_initialization.I2CRead11,
       &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_l,
       &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2_i,
       &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_e == 1.0) {
    LOG_DATI_GPS_BMP_07_09_DW.P_ref = LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder1;
  }

  if (LOG_DATI_GPS_BMP_07_09_P.Constant_Value_a == 1.0) {
    LOG_DATI_GPS_BMP_07_09_DW.P_ref =
      LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_kc;
    LOG_DATI_GPS_BMP_07_09_DW.rl_up = 20.0;
    LOG_DATI_GPS_BMP_07_09_DW.rl_dw = -20.0;
  }

  /* Product: '<S32>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S32>/sample time'
   *
   * About '<S32>/sample time':
   *  y = K where K = ( w * Ts )
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = LOG_DATI_GPS_BMP_07_09_DW.rl_up *
    LOG_DATI_GPS_BMP_07_09_P.sampletime_WtEt;

  /* Sum: '<S32>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S32>/Delay Input2'
   *
   * Block description for '<S32>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S32>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LOG_DATI_GPS_BMP_07_09_B.UkYk1 = LOG_DATI_GPS_BMP_07_09_DW.P_ref -
    LOG_DATI_GPS_BMP_07_09_DW.DelayInput2_DSTATE;

  /* Product: '<S32>/delta fall limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S32>/sample time'
   *
   * About '<S32>/sample time':
   *  y = K where K = ( w * Ts )
   */
  LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = LOG_DATI_GPS_BMP_07_09_DW.rl_dw *
    LOG_DATI_GPS_BMP_07_09_P.sampletime_WtEt;

  /* Switch: '<S38>/Switch2' incorporates:
   *  RelationalOperator: '<S38>/LowerRelop1'
   *  RelationalOperator: '<S38>/UpperRelop'
   *  Switch: '<S38>/Switch'
   */
  if (LOG_DATI_GPS_BMP_07_09_B.UkYk1 > LOG_DATI_GPS_BMP_07_09_B.RateTransition)
  {
    LOG_DATI_GPS_BMP_07_09_B.UkYk1 = LOG_DATI_GPS_BMP_07_09_B.RateTransition;
  } else {
    if (LOG_DATI_GPS_BMP_07_09_B.UkYk1 < LOG_DATI_GPS_BMP_07_09_B.deltafalllimit)
    {
      /* Switch: '<S38>/Switch' */
      LOG_DATI_GPS_BMP_07_09_B.UkYk1 = LOG_DATI_GPS_BMP_07_09_B.deltafalllimit;
    }
  }

  /* End of Switch: '<S38>/Switch2' */

  /* Sum: '<S32>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S32>/Delay Input2'
   *
   * Block description for '<S32>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S32>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LOG_DATI_GPS_BMP_07_09_DW.DelayInput2_DSTATE += LOG_DATI_GPS_BMP_07_09_B.UkYk1;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S32>/Delay Input2'
   *
   * Block description for '<S32>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_m = (real32_T)
    LOG_DATI_GPS_BMP_07_09_DW.DelayInput2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S37>/Subsystem1' incorporates:
   *  EnablePort: '<S39>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_e > 0.0) {
    /* Inport: '<S39>/T' */
    LOG_DATI_GPS_BMP_07_09_B.T = LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S37>/Subsystem1' */

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  LOG_DATI_GPS_BMP_07_09_B.h_ = (real32_T)log((real32_T)
    LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder1 /
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_m) * -8333.33301F;

  /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
   *  Constant: '<S20>/RC simulated'
   *  Constant: '<S20>/TAS simulated'
   *  Constant: '<S20>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_p[0] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.TASsimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_p[1] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.vsimulated_Value;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_p[2] =
    LOG_DATI_GPS_BMP_07_09_B.h_;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_p[3] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_P.RCsimulated_Value;

  /* DataTypeConversion: '<S20>/Data Type Conversion4' incorporates:
   *  Constant: '<S20>/ Heading simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Headingsimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion4' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion4_h = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S20>/Data Type Conversion5' incorporates:
   *  Constant: '<S20>/Rpm simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.Rpmsimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion5' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5 = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Gain: '<S27>/Gain2' incorporates:
   *  Constant: '<S18>/Manetta Simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.UkYk1 = LOG_DATI_GPS_BMP_07_09_P.Gain2_Gain_f *
    LOG_DATI_GPS_BMP_07_09_P.ManettaSimulated_Value;

  /* Sum: '<S27>/Sum' incorporates:
   *  Constant: '<S18>/Equilibratore Simulated'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S28>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_c
    * LOG_DATI_GPS_BMP_07_09_P.EquilibratoreSimulated_Value +
    LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_gt;

  /* Sum: '<S27>/Sum1' incorporates:
   *  Constant: '<S18>/Alettoni Simulated'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S29>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.Sum1 = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_h4 *
    LOG_DATI_GPS_BMP_07_09_P.AlettoniSimulated_Value +
    LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_gt;

  /* Sum: '<S27>/Sum2' incorporates:
   *  Constant: '<S18>/Timone Simulated'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S30>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.Sum2 = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_m *
    LOG_DATI_GPS_BMP_07_09_P.TimoneSimulated_Value +
    LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_gt;

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  LOG_DATI_GPS_BMP_07_09_B.PatohPa1 = LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_l *
    LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_h;

  /* Saturate: '<S18>/Saturation' */
  if (LOG_DATI_GPS_BMP_07_09_B.PatohPa1 >
      LOG_DATI_GPS_BMP_07_09_P.Saturation_UpperSat) {
    LOG_DATI_GPS_BMP_07_09_B.PatohPa1 =
      LOG_DATI_GPS_BMP_07_09_P.Saturation_UpperSat;
  } else {
    if (LOG_DATI_GPS_BMP_07_09_B.PatohPa1 <
        LOG_DATI_GPS_BMP_07_09_P.Saturation_LowerSat) {
      LOG_DATI_GPS_BMP_07_09_B.PatohPa1 =
        LOG_DATI_GPS_BMP_07_09_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant_Value_p < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_P.Constant_Value_p);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant_Value_p);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[0] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_09_B.UkYk1 < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.UkYk1);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.UkYk1);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[1] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[2] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_09_B.Sum1 < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil(LOG_DATI_GPS_BMP_07_09_B.Sum1);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.Sum1);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[3] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_09_B.Sum2 < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil(LOG_DATI_GPS_BMP_07_09_B.Sum2);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.Sum2);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[4] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[0] < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[0]);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[0]);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[5] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[1] < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[1]);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[1]);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[6] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[2] < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[2]);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_c[2]);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[7] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  if (LOG_DATI_GPS_BMP_07_09_B.PatohPa1 < 0.0) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = ceil
      (LOG_DATI_GPS_BMP_07_09_B.PatohPa1);
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
      (LOG_DATI_GPS_BMP_07_09_B.PatohPa1);
  }

  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  LOG_DATI_GPS_BMP_07_09_B.Heading[8] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  LOG_DATI_GPS_BMP_07_09_B.Memory_n =
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_f;

  /* Switch: '<S37>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S37>/NotEqual'
   *  Switch: '<S37>/Switch'
   */
  if (LOG_DATI_GPS_BMP_07_09_P.Constant_Value_o !=
      LOG_DATI_GPS_BMP_07_09_P.T_0_Value) {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion4 = (real32_T)
      LOG_DATI_GPS_BMP_07_09_P.T_0_Value;
  } else if (LOG_DATI_GPS_BMP_07_09_B.T >
             LOG_DATI_GPS_BMP_07_09_P.Switch_Threshold_c) {
    /* Switch: '<S37>/Switch' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion4'
     */
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion4 = LOG_DATI_GPS_BMP_07_09_B.T;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion4 = (real32_T)
      LOG_DATI_GPS_BMP_07_09_P.T_0_Value;
  }

  /* End of Switch: '<S37>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_g = (real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.PatohPa_Gain * (real_T)
     LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_n = (real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.PatohPa1_Gain *
     LOG_DATI_GPS_BMP_07_09_P.Constant2_Value_eg);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor
    (LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1);
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion2 = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&LOG_DATI_GPS_BMP_07_09_B.iflogic,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3,
     &LOG_DATI_GPS_BMP_07_09_P.SIUAVuint8_Value,
     &LOG_DATI_GPS_BMP_07_09_B.GC_info[0],
     &LOG_DATI_GPS_BMP_07_09_B.Val_out_MAV[0],
     &LOG_DATI_GPS_BMP_07_09_B.WP_info[0], &LOG_DATI_GPS_BMP_07_09_B.WP_param[0],
     &LOG_DATI_GPS_BMP_07_09_B.onboard[0], &LOG_DATI_GPS_BMP_07_09_B.LVDE[0],
     &LOG_DATI_GPS_BMP_07_09_B.B_Current, &LOG_DATI_GPS_BMP_07_09_B.B_Remaining,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[0],
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_c[0],
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1[0],
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_n[0],
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[0],
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion10,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_p[0],
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion4_h,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5,
     &LOG_DATI_GPS_BMP_07_09_B.Heading[0], &LOG_DATI_GPS_BMP_07_09_B.Memory_n,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_m,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o14,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion4,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o15,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_g,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_n,
     &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion2,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o5[0],
     &LOG_DATI_GPS_BMP_07_09_P.Constant4_Value_b,
     &LOG_DATI_GPS_BMP_07_09_P.Constant5_Value_a,
     &LOG_DATI_GPS_BMP_07_09_P.Constant10_Value, ((const uint16_T*)
      &LOG_DATI_GPS_BMP_07_09_U16GND), &LOG_DATI_GPS_BMP_07_09_B.SFunction_o1_g,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o2_b[0],
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o3,
     &LOG_DATI_GPS_BMP_07_09_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (LOG_DATI_GPS_BMP_07_09_B.SFunction_o1_g > 0) {
    /* Chart: '<S10>/Chart' */
    if (LOG_DATI_GPS_BMP_07_09_DW.is_active_c9_LOG_DATI_GPS_BMP_0 == 0U) {
      LOG_DATI_GPS_BMP_07_09_DW.is_active_c9_LOG_DATI_GPS_BMP_0 = 1U;
      LOG_DATI_GPS_BMP_07_09_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (LOG_DATI_GPS_BMP_07_09_DW.obj_a.Protocol !=
            LOG_DATI_GPS_BMP_07_09_P.SerialTransmit_Protocol) {
          LOG_DATI_GPS_BMP_07_09_DW.obj_a.Protocol =
            LOG_DATI_GPS_BMP_07_09_P.SerialTransmit_Protocol;
        }

        counter =
          LOG_DATI_GPS_BMP_07_09_B.SFunction_o2_b[LOG_DATI_GPS_BMP_07_09_DW.i -
          1];
        MW_Serial_write(LOG_DATI_GPS_BMP_07_09_DW.obj_a.port, &counter, 1.0,
                        LOG_DATI_GPS_BMP_07_09_DW.obj_a.dataSizeInBytes,
                        LOG_DATI_GPS_BMP_07_09_DW.obj_a.sendModeEnum,
                        LOG_DATI_GPS_BMP_07_09_DW.obj_a.dataType,
                        LOG_DATI_GPS_BMP_07_09_DW.obj_a.sendFormatEnum, 2.0,
                        '\x00');
        if (LOG_DATI_GPS_BMP_07_09_DW.i < LOG_DATI_GPS_BMP_07_09_B.SFunction_o3)
        {
          LOG_DATI_GPS_BMP_07_09_B.f_l = LOG_DATI_GPS_BMP_07_09_DW.i + 1;
          if (LOG_DATI_GPS_BMP_07_09_DW.i + 1 > 255) {
            LOG_DATI_GPS_BMP_07_09_B.f_l = 255;
          }

          LOG_DATI_GPS_BMP_07_09_DW.i = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.f_l;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      LOG_DATI_GPS_BMP_07_09_DW.i = 1U;
    }

    /* End of Chart: '<S10>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion6[0] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[0];
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion6[1] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[1];
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion6[2] = (real32_T)
    LOG_DATI_GPS_BMP_07_09_B.num_254;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion6[3] = LOG_DATI_GPS_BMP_07_09_B.h_;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/phi simulated'
   *  Gain: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk *
     LOG_DATI_GPS_BMP_07_09_P.phisimulated_Value));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[0] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/theta simulated'
   *  Gain: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk *
     LOG_DATI_GPS_BMP_07_09_P.thetasimulated_Value));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[1] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/psi simulated'
   *  Gain: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk *
     LOG_DATI_GPS_BMP_07_09_P.psisimulated_Value));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[2] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/p simulated'
   *  Gain: '<S15>/Gain'
   *  Gain: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_cw *
     LOG_DATI_GPS_BMP_07_09_P.psimulated_Value *
     LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[3] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/q simulated'
   *  Gain: '<S16>/Gain'
   *  Gain: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mu *
     LOG_DATI_GPS_BMP_07_09_P.qsimulated_Value *
     LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[4] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/r simulated'
   *  Gain: '<S17>/Gain'
   *  Gain: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_k *
     LOG_DATI_GPS_BMP_07_09_P.rsimulated_Value *
     LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[5] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/ACC simulated'
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk *
     LOG_DATI_GPS_BMP_07_09_P.ACCsimulated_Value[0]));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[6] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/ACC simulated'
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk *
     LOG_DATI_GPS_BMP_07_09_P.ACCsimulated_Value[1]));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[7] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/ACC simulated'
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor((real32_T)
    (LOG_DATI_GPS_BMP_07_09_P.Gain_Gain_mk *
     LOG_DATI_GPS_BMP_07_09_P.ACCsimulated_Value[2]));
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[8] = (int16_T)
    (LOG_DATI_GPS_BMP_07_09_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -LOG_DATI_GPS_BMP_07_09_B.f : (int32_T)(int16_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.f);

  /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
   *  Constant: '<S18>/Timone Simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_P.TimoneSimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Constant: '<S2>/Constant6'
   */
  LOG_DATI_GPS_BMP_07_09_B.UkYk1 = floor
    (LOG_DATI_GPS_BMP_07_09_P.Constant6_Value_k);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.UkYk1) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.UkYk1)) {
    LOG_DATI_GPS_BMP_07_09_B.UkYk1 = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.UkYk1 = fmod(LOG_DATI_GPS_BMP_07_09_B.UkYk1,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
   *  Constant: '<S18>/Manetta Simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = floor
    (LOG_DATI_GPS_BMP_07_09_P.ManettaSimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.deltafalllimit) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit)) {
    LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.deltafalllimit = fmod
      (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion3' incorporates:
   *  Constant: '<S18>/Equilibratore Simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.num_254 = floor
    (LOG_DATI_GPS_BMP_07_09_P.EquilibratoreSimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.num_254) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.num_254)) {
    LOG_DATI_GPS_BMP_07_09_B.num_254 = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.num_254 = fmod(LOG_DATI_GPS_BMP_07_09_B.num_254,
      65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
   *  Constant: '<S18>/Alettoni Simulated'
   */
  LOG_DATI_GPS_BMP_07_09_B.Sum1 = floor
    (LOG_DATI_GPS_BMP_07_09_P.AlettoniSimulated_Value);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.Sum1) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.Sum1)) {
    LOG_DATI_GPS_BMP_07_09_B.Sum1 = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.Sum1 = fmod(LOG_DATI_GPS_BMP_07_09_B.Sum1, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  DataTypeConversion: '<S18>/Data Type Conversion2'
   *  DataTypeConversion: '<S18>/Data Type Conversion3'
   *  DataTypeConversion: '<S18>/Data Type Conversion4'
   *  DataTypeConversion: '<S2>/Data Type Conversion11'
   *  Gain: '<S2>/Gain2'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[0] =
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion10;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[1] = (uint16_T)
    ((LOG_DATI_GPS_BMP_07_09_P.Gain2_Gain_l *
      LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[0]) >> 8);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[2] = (uint16_T)
    ((LOG_DATI_GPS_BMP_07_09_P.Gain2_Gain_l *
      LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[1]) >> 8);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[3] = (uint16_T)
    ((LOG_DATI_GPS_BMP_07_09_P.Gain2_Gain_l *
      LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_g[2]) >> 8);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[4] =
    LOG_DATI_GPS_BMP_07_09_P.Constant_Value_ja;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[5] =
    LOG_DATI_GPS_BMP_07_09_P.Constant3_Value_n;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[6] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[7] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.UkYk1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.UkYk1 : (int32_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.UkYk1);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[8] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.deltafalllimit < 0.0 ? (int32_T)(uint16_T)
     -(int16_T)(uint16_T)-LOG_DATI_GPS_BMP_07_09_B.deltafalllimit : (int32_T)
     (uint16_T)LOG_DATI_GPS_BMP_07_09_B.deltafalllimit);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[9] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.num_254 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.num_254 : (int32_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.num_254);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[10] =
    LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_px;
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[11] = (uint16_T)
    (LOG_DATI_GPS_BMP_07_09_B.Sum1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-LOG_DATI_GPS_BMP_07_09_B.Sum1 : (int32_T)(uint16_T)
     LOG_DATI_GPS_BMP_07_09_B.Sum1);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  LOG_DATI_GPS_BMP_07_09_B.RateTransition = floor
    (LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[5]);
  if (rtIsNaN(LOG_DATI_GPS_BMP_07_09_B.RateTransition) || rtIsInf
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition)) {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = 0.0;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.RateTransition = fmod
      (LOG_DATI_GPS_BMP_07_09_B.RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion8[0] = (uint8_T)
    (LOG_DATI_GPS_BMP_07_09_B.RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-LOG_DATI_GPS_BMP_07_09_B.RateTransition : (int32_T)(uint8_T)
     LOG_DATI_GPS_BMP_07_09_B.RateTransition);
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion8[1] =
    LOG_DATI_GPS_BMP_07_09_B.indice_dimario;

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)floor
    (LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion_g);
  if (rtIsNaNF(LOG_DATI_GPS_BMP_07_09_B.f) || rtIsInfF
      (LOG_DATI_GPS_BMP_07_09_B.f)) {
    LOG_DATI_GPS_BMP_07_09_B.f = 0.0F;
  } else {
    LOG_DATI_GPS_BMP_07_09_B.f = (real32_T)fmod(LOG_DATI_GPS_BMP_07_09_B.f,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion9 = LOG_DATI_GPS_BMP_07_09_B.f <
    0.0F ? (uint32_T)-(int32_T)(uint32_T)-LOG_DATI_GPS_BMP_07_09_B.f : (uint32_T)
    LOG_DATI_GPS_BMP_07_09_B.f;

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
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion6[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion3_f[0],
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
    /* Input data type - uint16_T, size - 12 */
    {
      MW_inputPortWidth = 12 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion5_f[0],
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
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion8[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion9, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&LOG_DATI_GPS_BMP_07_09_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &LOG_DATI_GPS_BMP_07_09_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S2>/Serial Transmit' */
  if (LOG_DATI_GPS_BMP_07_09_DW.obj.Protocol !=
      LOG_DATI_GPS_BMP_07_09_P.SerialTransmit_Protocol_h) {
    LOG_DATI_GPS_BMP_07_09_DW.obj.Protocol =
      LOG_DATI_GPS_BMP_07_09_P.SerialTransmit_Protocol_h;
  }

  memcpy(&LOG_DATI_GPS_BMP_07_09_B.dataIn[0],
         &LOG_DATI_GPS_BMP_07_09_B.BytePack[0], 67U * sizeof(uint8_T));
  MW_Serial_write(LOG_DATI_GPS_BMP_07_09_DW.obj.port,
                  &LOG_DATI_GPS_BMP_07_09_B.dataIn[0], 67.0,
                  LOG_DATI_GPS_BMP_07_09_DW.obj.dataSizeInBytes,
                  LOG_DATI_GPS_BMP_07_09_DW.obj.sendModeEnum,
                  LOG_DATI_GPS_BMP_07_09_DW.obj.dataType,
                  LOG_DATI_GPS_BMP_07_09_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S2>/Serial Transmit' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&LOG_DATI_GPS_BMP_07_09_DW.Memory4_PreviousInput[0],
         &LOG_DATI_GPS_BMP_07_09_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&LOG_DATI_GPS_BMP_07_09_P.Constant1_Value_h,
    &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1_e[0],
    &LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o2,
    &LOG_DATI_GPS_BMP_07_09_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&LOG_DATI_GPS_BMP_07_09_DW.Memory5_PreviousInput[0],
         &LOG_DATI_GPS_BMP_07_09_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[0] =
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[0];
  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[1] =
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[1];
  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[2] =
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[2];
  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[3] =
    LOG_DATI_GPS_BMP_07_09_B.DataTypeConversion1_h[3];

  /* Update for Memory: '<S1>/Memory' */
  for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 8;
       LOG_DATI_GPS_BMP_07_09_B.i++) {
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_e[LOG_DATI_GPS_BMP_07_09_B.i]
      = LOG_DATI_GPS_BMP_07_09_B.SFunction_o11[LOG_DATI_GPS_BMP_07_09_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[0] = (uint8_T)AP_mode_idx_0;
  LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[1] = (uint8_T)AP_mode_idx_1;
  for (LOG_DATI_GPS_BMP_07_09_B.i = 0; LOG_DATI_GPS_BMP_07_09_B.i < 7;
       LOG_DATI_GPS_BMP_07_09_B.i++) {
    LOG_DATI_GPS_BMP_07_09_B.f = rt_roundf_snf
      (LOG_DATI_GPS_BMP_07_09_DW.riferimenti[LOG_DATI_GPS_BMP_07_09_B.i]);
    if (LOG_DATI_GPS_BMP_07_09_B.f < 256.0F) {
      if (LOG_DATI_GPS_BMP_07_09_B.f >= 0.0F) {
        LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[LOG_DATI_GPS_BMP_07_09_B.i
          + 2] = (uint8_T)LOG_DATI_GPS_BMP_07_09_B.f;
      } else {
        LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[LOG_DATI_GPS_BMP_07_09_B.i
          + 2] = 0U;
      }
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[LOG_DATI_GPS_BMP_07_09_B.i
        + 2] = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  LOG_DATI_GPS_BMP_07_09_DW.UnitDelay_DSTATE =
    LOG_DATI_GPS_BMP_07_09_P.Constant3_Value_g;

  /* Update for Memory: '<S2>/Memory' */
  LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_f =
    LOG_DATI_GPS_BMP_07_09_B.SFunction_o4;
}

/* Model step function for TID1 */
void LOG_DATI_GPS_BMP_07_09_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S25>/Add2' incorporates:
   *  Constant: '<S25>/Constant4'
   *  Constant: '<S25>/Constant5'
   *  Memory: '<S25>/Memory2'
   */
  LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput +=
    LOG_DATI_GPS_BMP_07_09_P.Constant4_Value_n +
    LOG_DATI_GPS_BMP_07_09_P.Constant5_Value_d;

  /* Switch: '<S25>/Switch1' */
  if (LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput >
      LOG_DATI_GPS_BMP_07_09_P.Switch1_Threshold) {
    /* Sum: '<S25>/Add2' incorporates:
     *  Constant: '<S25>/Constant4'
     */
    LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_P.Constant4_Value_n;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* RateTransition: '<S25>/Rate Transition' */
  LOG_DATI_GPS_BMP_07_09_DW.RateTransition_Buffer0 =
    LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void LOG_DATI_GPS_BMP_07_09_initialize(void)
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
    memcpy(&LOG_DATI_GPS_BMP_07_09_DW.Memory4_PreviousInput[0],
           &LOG_DATI_GPS_BMP_07_09_P.Memory4_InitialCondition[0], 300U * sizeof
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
          LOG_DATI_GPS_BMP_07_09_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      LOG_DATI_GPS_BMP_07_09_DW.Memory5_PreviousInput[i] =
        LOG_DATI_GPS_BMP_07_09_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[0] =
      LOG_DATI_GPS_BMP_07_09_P.Memory1_InitialCondition_g;
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput_m[1] =
      LOG_DATI_GPS_BMP_07_09_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[0] =
      LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_gh;
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[1] =
      LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_gh;
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[2] =
      LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_gh;
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_m[3] =
      LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_gh;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory3_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_e[i] =
        LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_o;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput_a[i] =
        LOG_DATI_GPS_BMP_07_09_P.Memory2_InitialCondition_p[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S25>/Rate Transition' */
    LOG_DATI_GPS_BMP_07_09_DW.RateTransition_Buffer0 =
      LOG_DATI_GPS_BMP_07_09_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S25>/Switch' incorporates:
     *  Memory: '<S25>/Memory1'
     */
    LOG_DATI_GPS_BMP_07_09_DW.Memory1_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S25>/Add' incorporates:
     *  Memory: '<S25>/Memory'
     */
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    LOG_DATI_GPS_BMP_07_09_DW.UnitDelay_DSTATE =
      LOG_DATI_GPS_BMP_07_09_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S32>/Delay Input2'
     *
     * Block description for '<S32>/Delay Input2':
     *
     *  Store in Global RAM
     */
    LOG_DATI_GPS_BMP_07_09_DW.DelayInput2_DSTATE =
      LOG_DATI_GPS_BMP_07_09_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_f =
      LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition_h;

    /* InitializeConditions for Sum: '<S25>/Add2' incorporates:
     *  Memory: '<S25>/Memory2'
     */
    LOG_DATI_GPS_BMP_07_09_DW.Memory2_PreviousInput =
      LOG_DATI_GPS_BMP_07_09_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&LOG_DATI_GPS_BMP_07_09_DW.riferimenti[0], &tmp[0], sizeof(real32_T) <<
           4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S10>/Chart' incorporates:
     *  SubSystem: '<S22>/sendbyte'
     */
    /* Start for MATLABSystem: '<S23>/Serial Transmit' */
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.Protocol =
      LOG_DATI_GPS_BMP_07_09_P.SerialTransmit_Protocol;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.port = 2.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.dataSizeInBytes = 1.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.dataType = 0.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.sendModeEnum = 0.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(LOG_DATI_GPS_BMP_07_09_DW.obj_a.port);
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
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S23>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S33>/I2C Read12' */
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.matlabCodegenIsDeleted = true;
    obj = &LOG_DATI_GPS_BMP_07_09_DW.obj_d;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.isInitialized = 0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
    obj = &LOG_DATI_GPS_BMP_07_09_DW.obj_d;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.isSetupComplete = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_09_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (LOG_DATI_GPS_BMP_07_09_B.i2cname, 0);
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.BusSpeed = 100000U;
    varargin_1 = LOG_DATI_GPS_BMP_07_09_DW.obj_d.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S33>/I2C Read1' */
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.matlabCodegenIsDeleted = true;
    obj = &LOG_DATI_GPS_BMP_07_09_DW.obj_i;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.isInitialized = 0;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.SampleTime = LOG_DATI_GPS_BMP_07_09_P.t_AP;
    obj = &LOG_DATI_GPS_BMP_07_09_DW.obj_i;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.isSetupComplete = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_09_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (LOG_DATI_GPS_BMP_07_09_B.i2cname, 0);
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.BusSpeed = 100000U;
    varargin_1 = LOG_DATI_GPS_BMP_07_09_DW.obj_i.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S33>/S-Function Builder' incorporates:
     *  Outport: '<S33>/T'
     */
    LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder_o1 = LOG_DATI_GPS_BMP_07_09_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S33>/S-Function Builder1' incorporates:
     *  Outport: '<S33>/p'
     */
    LOG_DATI_GPS_BMP_07_09_B.SFunctionBuilder1 = LOG_DATI_GPS_BMP_07_09_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    LOG_DATI_GPS_BMP_07_09_DW.P_ref = 101325.0;
    LOG_DATI_GPS_BMP_07_09_DW.rl_up = 300.0;
    LOG_DATI_GPS_BMP_07_09_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init
      (&LOG_DATI_GPS_BMP_07_09_B.One_time_initialization,
       &LOG_DATI_GPS_BMP_07_09_DW.One_time_initialization,
       &LOG_DATI_GPS_BMP_07_09_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S37>/Subsystem1' */
    /* SystemInitialize for Outport: '<S39>/T_0' incorporates:
     *  Inport: '<S39>/T'
     */
    LOG_DATI_GPS_BMP_07_09_B.T = LOG_DATI_GPS_BMP_07_09_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S37>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* SystemInitialize for Switch: '<S4>/Switch' incorporates:
     *  Outport: '<S4>/h_to_subtract'
     */
    LOG_DATI_GPS_BMP_07_09_B.Switch = LOG_DATI_GPS_BMP_07_09_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S5>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S41>/Memory' */
      LOG_DATI_GPS_BMP_07_09_DW.Memory_PreviousInput_g[i] =
        LOG_DATI_GPS_BMP_07_09_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S41>/Complex to Real-Imag' incorporates:
       *  Outport: '<S41>/Outport'
       */
      LOG_DATI_GPS_BMP_07_09_B.ComplextoRealImag[i] =
        LOG_DATI_GPS_BMP_07_09_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S41>/mario' */
    LOG_DATI_GPS_BMP_07_09_B.indice_dimario = LOG_DATI_GPS_BMP_07_09_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem2' */

    /* Start for MATLABSystem: '<Root>/Serial Receive1' */
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.Protocol =
      LOG_DATI_GPS_BMP_07_09_P.SerialReceive1_Protocol;
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.DataTypeWidth = 1U;
    if (LOG_DATI_GPS_BMP_07_09_DW.obj_l.DataTypeWidth > 2047) {
      LOG_DATI_GPS_BMP_07_09_DW.obj_l.DataSizeInBytes = MAX_uint16_T;
    } else {
      LOG_DATI_GPS_BMP_07_09_DW.obj_l.DataSizeInBytes = (uint16_T)
        (LOG_DATI_GPS_BMP_07_09_DW.obj_l.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive1' */

    /* Start for MATLABSystem: '<S2>/Serial Transmit' */
    LOG_DATI_GPS_BMP_07_09_DW.obj.matlabCodegenIsDeleted = false;
    LOG_DATI_GPS_BMP_07_09_DW.obj.Protocol =
      LOG_DATI_GPS_BMP_07_09_P.SerialTransmit_Protocol_h;
    LOG_DATI_GPS_BMP_07_09_DW.obj.isInitialized = 1;
    LOG_DATI_GPS_BMP_07_09_DW.obj.port = 0.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj.dataSizeInBytes = 1.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj.dataType = 0.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj.sendModeEnum = 0.0;
    LOG_DATI_GPS_BMP_07_09_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(LOG_DATI_GPS_BMP_07_09_DW.obj.port);
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
    LOG_DATI_GPS_BMP_07_09_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit' */
  }
}

/* Model terminate function */
void LOG_DATI_GPS_BMP_07_09_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive1' */
  if (!LOG_DATI_GPS_BMP_07_09_DW.obj_l.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_09_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term(&LOG_DATI_GPS_BMP_07_09_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S33>/I2C Read12' */
  obj = &LOG_DATI_GPS_BMP_07_09_DW.obj_d;
  if (!LOG_DATI_GPS_BMP_07_09_DW.obj_d.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_09_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((LOG_DATI_GPS_BMP_07_09_DW.obj_d.isInitialized == 1) &&
        LOG_DATI_GPS_BMP_07_09_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read1' */
  obj = &LOG_DATI_GPS_BMP_07_09_DW.obj_i;
  if (!LOG_DATI_GPS_BMP_07_09_DW.obj_i.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_09_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((LOG_DATI_GPS_BMP_07_09_DW.obj_i.isInitialized == 1) &&
        LOG_DATI_GPS_BMP_07_09_DW.obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S10>/Chart' incorporates:
   *  SubSystem: '<S22>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S23>/Serial Transmit' */
  if (!LOG_DATI_GPS_BMP_07_09_DW.obj_a.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_09_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S23>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit' */
  if (!LOG_DATI_GPS_BMP_07_09_DW.obj.matlabCodegenIsDeleted) {
    LOG_DATI_GPS_BMP_07_09_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
