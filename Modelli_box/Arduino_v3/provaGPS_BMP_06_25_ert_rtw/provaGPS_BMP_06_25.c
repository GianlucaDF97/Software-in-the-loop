/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaGPS_BMP_06_25.c
 *
 * Code generated for Simulink model 'provaGPS_BMP_06_25'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul 27 11:24:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaGPS_BMP_06_25.h"
#include "provaGPS_BMP_06_25_private.h"

const uint16_T provaGPS_BMP_06_25_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_provaGPS_BMP_06_25_T provaGPS_BMP_06_25_B;

/* Block states (default storage) */
DW_provaGPS_BMP_06_25_T provaGPS_BMP_06_25_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_provaGPS_BMP_06_25_T provaGPS_BMP_06_25_Y;

/* Real-time model */
static RT_MODEL_provaGPS_BMP_06_25_T provaGPS_BMP_06_25_M_;
RT_MODEL_provaGPS_BMP_06_25_T *const provaGPS_BMP_06_25_M =
  &provaGPS_BMP_06_25_M_;

/* Forward declaration for local functions */
static void provaGPS_BMP_06_25_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T provaGPS_BMP_06_25_ifWhileCond(const boolean_T x[100]);
static void provaGPS_BMP_06_25_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T provaGPS_BMP_06_2_ifWhileCond_k(const boolean_T x[5]);
static void provaGPS_BMP_06_25_eml_find_e(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void provaGPS_BMP_06_2_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T provaGPS_BMP_06_25_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T provaGPS_BMP_06_25_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void provaGPS_BMP_06_25_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaGPS_BMP_06_25_str2double(const char_T s[2]);
static boolean_T provaGPS_BMP_06_25_copydigits_g(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void provaGPS_BMP_06_25_readfloat_i(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaGPS_BMP_06_25_str2double_i(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T provaGPS_BMP_06_25_isUnitImag(const char_T s[3], int32_T k);
static void provaGPS_BMP_06_readNonFinite_e(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T provaGPS_BMP_06_2_copydigits_gt(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T provaGPS_BMP_06__copyexponent_g(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void provaGPS_BMP_06_25_readfloat_iz(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaGPS_BMP_06_2_str2double_i2(const char_T s[3]);
static void provaGPS_BMP_0_readNonFinite_ec(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T provaGPS_BMP_06__copydigits_gt3(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T provaGPS_BMP_06_copyexponent_gr(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void provaGPS_BMP_06_2_readfloat_izz(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaGPS_BMP_06__str2double_i2v(char_T s);
static real_T provaGPS_BMP_06_25_hex2dec(const char_T s[2]);
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
void provaGPS_BMP_06_25_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(provaGPS_BMP_06_25_M, 1));
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
  (provaGPS_BMP_06_25_M->Timing.TaskCounters.TID[1])++;
  if ((provaGPS_BMP_06_25_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    provaGPS_BMP_06_25_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_pro_T *localB,
  DW_One_time_initialization_pr_T *localDW, P_One_time_initialization_pro_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S33>/I2C Read' */
  localDW->obj_n0.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n0;
  localDW->obj_n0.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n0.isInitialized = 0;
  localDW->obj_n0.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n0.matlabCodegenIsDeleted = false;
  localDW->obj_n0.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_n0;
  localDW->obj_n0.isSetupComplete = false;
  localDW->obj_n0.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n0.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n0.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read1' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read2' */
  localDW->obj_ba.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ba;
  localDW->obj_ba.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ba.isInitialized = 0;
  localDW->obj_ba.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ba.matlabCodegenIsDeleted = false;
  localDW->obj_ba.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_ba;
  localDW->obj_ba.isSetupComplete = false;
  localDW->obj_ba.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ba.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ba.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ba.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read3' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read5' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read6' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read7' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read8' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Read11' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = provaGPS_BMP_06_25_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S33>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S33>/I2C Write2' */
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

  /* Start for MATLABSystem: '<S33>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S33>/I2C Read12' */
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
    if (localDW->obj_n0.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_n0.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S33>/I2C Read' */

    /* MATLABSystem: '<S33>/I2C Read1' */
    if (localDW->obj_d.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_d.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read1' */

    /* MATLABSystem: '<S33>/I2C Read2' */
    if (localDW->obj_ba.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_ba.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read2' */

    /* MATLABSystem: '<S33>/I2C Read3' */
    if (localDW->obj_o.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_o.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
    if (localDW->obj_i.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_i.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read4' */

    /* MATLABSystem: '<S33>/I2C Read5' */
    if (localDW->obj_n.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_n.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read5' */

    /* MATLABSystem: '<S33>/I2C Read6' */
    if (localDW->obj_m.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_m.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read6' */

    /* MATLABSystem: '<S33>/I2C Read7' */
    if (localDW->obj_b.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_b.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read7' */

    /* MATLABSystem: '<S33>/I2C Read8' */
    if (localDW->obj_l.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_l.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read8' */

    /* MATLABSystem: '<S33>/I2C Read9' */
    if (localDW->obj.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
    if (localDW->obj_f.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_f.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
      /* MATLABSystem: '<S33>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S33>/I2C Read10' */

    /* MATLABSystem: '<S33>/I2C Read11' */
    if (localDW->obj_p.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      localDW->obj_p.SampleTime = provaGPS_BMP_06_25_P.t_AP;
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
    MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S33>/I2C Write2' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_n4.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S33>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_ff.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S33>/I2C Read12' */
    if (localDW->obj_h.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_h.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 80U,
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
void One_time_initializatio_Term(DW_One_time_initialization_pr_T *localDW)
{
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S33>/I2C Read' */
  obj = &localDW->obj_n0;
  if (!localDW->obj_n0.matlabCodegenIsDeleted) {
    localDW->obj_n0.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n0.isInitialized == 1) && localDW->obj_n0.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read1' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read2' */
  obj = &localDW->obj_ba;
  if (!localDW->obj_ba.matlabCodegenIsDeleted) {
    localDW->obj_ba.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ba.isInitialized == 1) && localDW->obj_ba.isSetupComplete)
    {
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
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read5' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read6' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read7' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read8' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
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
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read11' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S33>/I2C Write1' */
  obj_0 = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S33>/I2C Write2' */
  obj_0 = &localDW->obj_n4;
  if (!localDW->obj_n4.matlabCodegenIsDeleted) {
    localDW->obj_n4.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n4.isInitialized == 1) && localDW->obj_n4.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S33>/I2C Write3' */
  obj_0 = &localDW->obj_ff;
  if (!localDW->obj_ff.matlabCodegenIsDeleted) {
    localDW->obj_ff.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ff.isInitialized == 1) && localDW->obj_ff.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S33>/I2C Read12' */
  obj = &localDW->obj_h;
  if (!localDW->obj_h.matlabCodegenIsDeleted) {
    localDW->obj_h.matlabCodegenIsDeleted = true;
    if ((localDW->obj_h.isInitialized == 1) && localDW->obj_h.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void provaGPS_BMP_06_25_find_254(const uint8_T pack[100], real_T
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
static boolean_T provaGPS_BMP_06_25_ifWhileCond(const boolean_T x[100])
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_25_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_2_ifWhileCond_k(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_25_eml_find_e(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_2_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_25_copydigits(char_T s1[4], int32_T *idx, const
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_25_copyexponent(char_T s1[4], int32_T *idx,
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

      provaGPS_BMP_06_25_B.kexp_l = *k;
      b_k = *k;
      b_success = provaGPS_BMP_06_25_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > provaGPS_BMP_06_25_B.kexp_l));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_25_readfloat(char_T s1[4], int32_T *idx, const
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
            provaGPS_BMP_06_25_readfloat(s1, idx, s, k, false, &isneg, b_finite,
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
      provaGPS_BMP_06_2_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = provaGPS_BMP_06_25_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = provaGPS_BMP_06_25_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static creal_T provaGPS_BMP_06_25_str2double(const char_T s[2])
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
  provaGPS_BMP_06_25_B.ntoread_b = 0;
  provaGPS_BMP_06_25_B.k_b = 0;
  while ((provaGPS_BMP_06_25_B.k_b + 1 <= 2) && (c[(uint8_T)
          s[provaGPS_BMP_06_25_B.k_b] & 127] || (s[provaGPS_BMP_06_25_B.k_b] ==
           '\x00'))) {
    provaGPS_BMP_06_25_B.k_b++;
  }

  isimag1 = false;
  b_finite = true;
  provaGPS_BMP_06_25_B.scanned1_g = 0.0;
  provaGPS_BMP_06_25_B.idx_n = 1;
  provaGPS_BMP_06_25_B.s1_g[0] = '\x00';
  provaGPS_BMP_06_25_B.s1_g[1] = '\x00';
  provaGPS_BMP_06_25_B.s1_g[2] = '\x00';
  provaGPS_BMP_06_25_B.s1_g[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaGPS_BMP_06_25_B.k_b + 1 <= 2)) {
    if (s[provaGPS_BMP_06_25_B.k_b] == '-') {
      isneg = !isneg;
      provaGPS_BMP_06_25_B.k_b++;
    } else if ((s[provaGPS_BMP_06_25_B.k_b] == ',') ||
               (s[provaGPS_BMP_06_25_B.k_b] == '+') || c[(uint8_T)
               s[provaGPS_BMP_06_25_B.k_b] & 127]) {
      provaGPS_BMP_06_25_B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  success = (provaGPS_BMP_06_25_B.k_b + 1 <= 2);
  if (success && isneg) {
    provaGPS_BMP_06_25_B.s1_g[0] = '-';
    provaGPS_BMP_06_25_B.idx_n = 2;
  }

  provaGPS_BMP_06_25_B.e_k = provaGPS_BMP_06_25_B.k_b + 1;
  if (success) {
    if ((provaGPS_BMP_06_25_B.k_b + 1 <= 2) && ((s[provaGPS_BMP_06_25_B.k_b] ==
          'j') || (s[provaGPS_BMP_06_25_B.k_b] == 'i'))) {
      isimag1 = true;
      provaGPS_BMP_06_25_B.e_k = provaGPS_BMP_06_25_B.k_b + 2;
      while ((provaGPS_BMP_06_25_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1]
               == '\x00') || (s[1] == ','))) {
        provaGPS_BMP_06_25_B.e_k = 3;
      }

      if ((provaGPS_BMP_06_25_B.e_k <= 2) && (s[1] == '*')) {
        provaGPS_BMP_06_25_B.e_k = 3;
        provaGPS_BMP_06_25_readfloat(provaGPS_BMP_06_25_B.s1_g,
          &provaGPS_BMP_06_25_B.idx_n, s, &provaGPS_BMP_06_25_B.e_k, false,
          &isneg, &b_finite, &provaGPS_BMP_06_25_B.scanned1_g, &unusedU2,
          &success);
      } else {
        provaGPS_BMP_06_25_B.s1_g[provaGPS_BMP_06_25_B.idx_n - 1] = '1';
        provaGPS_BMP_06_25_B.idx_n++;
      }
    } else {
      provaGPS_BMP_06_25_B.e_k = provaGPS_BMP_06_25_B.k_b + 1;
      provaGPS_BMP_06_2_readNonFinite(s, &provaGPS_BMP_06_25_B.e_k, &b_finite,
        &provaGPS_BMP_06_25_B.scanned1_g);
      if (b_finite) {
        success = provaGPS_BMP_06_25_copydigits(provaGPS_BMP_06_25_B.s1_g,
          &provaGPS_BMP_06_25_B.idx_n, s, &provaGPS_BMP_06_25_B.e_k, true);
        if (success) {
          success = provaGPS_BMP_06_25_copyexponent(provaGPS_BMP_06_25_B.s1_g,
            &provaGPS_BMP_06_25_B.idx_n, s, &provaGPS_BMP_06_25_B.e_k);
        }
      } else {
        if ((provaGPS_BMP_06_25_B.idx_n >= 2) && (provaGPS_BMP_06_25_B.s1_g[0] ==
             '-')) {
          provaGPS_BMP_06_25_B.idx_n = 1;
          provaGPS_BMP_06_25_B.s1_g[0] = ' ';
          provaGPS_BMP_06_25_B.scanned1_g = -provaGPS_BMP_06_25_B.scanned1_g;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (provaGPS_BMP_06_25_B.e_k <= 2)) {
        tmp = s[provaGPS_BMP_06_25_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          provaGPS_BMP_06_25_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((provaGPS_BMP_06_25_B.e_k <= 2) && (s[provaGPS_BMP_06_25_B.e_k - 1] ==
           '*')) {
        provaGPS_BMP_06_25_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (provaGPS_BMP_06_25_B.e_k <= 2)) {
          tmp = s[provaGPS_BMP_06_25_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            provaGPS_BMP_06_25_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (provaGPS_BMP_06_25_B.e_k <= 2) {
        tmp = s[provaGPS_BMP_06_25_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          provaGPS_BMP_06_25_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (provaGPS_BMP_06_25_B.e_k <= 2)) {
      tmp = s[provaGPS_BMP_06_25_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        provaGPS_BMP_06_25_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    provaGPS_BMP_06_25_B.ntoread_b = 1;
  }

  if (success && (provaGPS_BMP_06_25_B.e_k <= 2)) {
    provaGPS_BMP_06_25_B.s1_g[provaGPS_BMP_06_25_B.idx_n - 1] = ' ';
    provaGPS_BMP_06_25_B.idx_n++;
    provaGPS_BMP_06_25_readfloat(provaGPS_BMP_06_25_B.s1_g,
      &provaGPS_BMP_06_25_B.idx_n, s, &provaGPS_BMP_06_25_B.e_k, true, &success,
      &isneg, &provaGPS_BMP_06_25_B.scanned2_m, &unusedU2, &c_success);
    if (isneg) {
      provaGPS_BMP_06_25_B.ntoread_b++;
    }

    success = (c_success && (provaGPS_BMP_06_25_B.e_k > 2) && (isimag1 !=
                success) && unusedU2);
  } else {
    provaGPS_BMP_06_25_B.scanned2_m = 0.0;
  }

  if (success) {
    provaGPS_BMP_06_25_B.s1_g[provaGPS_BMP_06_25_B.idx_n - 1] = '\x00';
    switch (provaGPS_BMP_06_25_B.ntoread_b) {
     case 2:
      provaGPS_BMP_06_25_B.ntoread_b = sscanf(&provaGPS_BMP_06_25_B.s1_g[0],
        "%lf %lf", &provaGPS_BMP_06_25_B.scanned1_g,
        &provaGPS_BMP_06_25_B.scanned2_m);
      if (provaGPS_BMP_06_25_B.ntoread_b != 2) {
        provaGPS_BMP_06_25_B.scanned1_g = (rtNaN);
        provaGPS_BMP_06_25_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      provaGPS_BMP_06_25_B.ntoread_b = sscanf(&provaGPS_BMP_06_25_B.s1_g[0],
        "%lf", &provaGPS_BMP_06_25_B.b_scanned1_n);
      if (b_finite) {
        if (provaGPS_BMP_06_25_B.ntoread_b == 1) {
          provaGPS_BMP_06_25_B.scanned1_g = provaGPS_BMP_06_25_B.b_scanned1_n;
        } else {
          provaGPS_BMP_06_25_B.scanned1_g = (rtNaN);
        }
      } else if (provaGPS_BMP_06_25_B.ntoread_b == 1) {
        provaGPS_BMP_06_25_B.scanned2_m = provaGPS_BMP_06_25_B.b_scanned1_n;
      } else {
        provaGPS_BMP_06_25_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaGPS_BMP_06_25_B.scanned2_m;
      x.im = provaGPS_BMP_06_25_B.scanned1_g;
    } else {
      x.re = provaGPS_BMP_06_25_B.scanned1_g;
      x.im = provaGPS_BMP_06_25_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_25_copydigits_g(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_25_readfloat_i(char_T s1_data[], int32_T *idx, const
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
          provaGPS_BMP_06_25_readfloat_i(s1_data, idx, s_data, k, n, false,
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
        *success = provaGPS_BMP_06_25_copydigits_g(s1_data, &b_idx, s_data, &h_k,
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
              isneg = provaGPS_BMP_06_25_copydigits_g(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static creal_T provaGPS_BMP_06_25_str2double_i(const char_T s_data[], const
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
    provaGPS_BMP_06_25_B.ntoread = 0;
    provaGPS_BMP_06_25_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (provaGPS_BMP_06_25_B.k <= s_size[1])) {
      tmp = s_data[provaGPS_BMP_06_25_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        provaGPS_BMP_06_25_B.k++;
      } else {
        exitg1 = true;
      }
    }

    provaGPS_BMP_06_25_B.s1_size[0] = 1;
    provaGPS_BMP_06_25_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    provaGPS_BMP_06_25_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= provaGPS_BMP_06_25_B.idx) {
      memset(&provaGPS_BMP_06_25_B.s1_data[0], 0, (provaGPS_BMP_06_25_B.idx + 1)
             * sizeof(char_T));
    }

    provaGPS_BMP_06_25_B.idx = 1;
    provaGPS_BMP_06_25_readfloat_i(provaGPS_BMP_06_25_B.s1_data,
      &provaGPS_BMP_06_25_B.idx, s_data, &provaGPS_BMP_06_25_B.k, s_size[1],
      true, &isimag1, &isfinite1, &provaGPS_BMP_06_25_B.scanned1, &unusedU0,
      &success);
    if (isfinite1) {
      provaGPS_BMP_06_25_B.ntoread = 1;
    }

    if (success) {
      if (provaGPS_BMP_06_25_B.k <= s_size[1]) {
        provaGPS_BMP_06_25_B.s1_data[provaGPS_BMP_06_25_B.idx - 1] = ' ';
        provaGPS_BMP_06_25_B.idx++;
        provaGPS_BMP_06_25_readfloat_i(provaGPS_BMP_06_25_B.s1_data,
          &provaGPS_BMP_06_25_B.idx, s_data, &provaGPS_BMP_06_25_B.k, s_size[1],
          true, &unusedU0, &success, &provaGPS_BMP_06_25_B.scanned2, &foundsign,
          &c_success);
        if (success) {
          provaGPS_BMP_06_25_B.ntoread++;
        }

        success = (c_success && ((provaGPS_BMP_06_25_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        provaGPS_BMP_06_25_B.scanned2 = 0.0;
      }
    } else {
      provaGPS_BMP_06_25_B.scanned2 = 0.0;
    }

    if (success) {
      provaGPS_BMP_06_25_B.s1_data[provaGPS_BMP_06_25_B.idx - 1] = '\x00';
      switch (provaGPS_BMP_06_25_B.ntoread) {
       case 2:
        provaGPS_BMP_06_25_B.ntoread = sscanf(&provaGPS_BMP_06_25_B.s1_data[0],
          "%lf %lf", &provaGPS_BMP_06_25_B.scanned1,
          &provaGPS_BMP_06_25_B.scanned2);
        if (provaGPS_BMP_06_25_B.ntoread != 2) {
          provaGPS_BMP_06_25_B.scanned1 = (rtNaN);
          provaGPS_BMP_06_25_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        provaGPS_BMP_06_25_B.ntoread = sscanf(&provaGPS_BMP_06_25_B.s1_data[0],
          "%lf", &provaGPS_BMP_06_25_B.b_scanned1);
        if (isfinite1) {
          if (provaGPS_BMP_06_25_B.ntoread == 1) {
            provaGPS_BMP_06_25_B.scanned1 = provaGPS_BMP_06_25_B.b_scanned1;
          } else {
            provaGPS_BMP_06_25_B.scanned1 = (rtNaN);
          }
        } else if (provaGPS_BMP_06_25_B.ntoread == 1) {
          provaGPS_BMP_06_25_B.scanned2 = provaGPS_BMP_06_25_B.b_scanned1;
        } else {
          provaGPS_BMP_06_25_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = provaGPS_BMP_06_25_B.scanned2;
        x.im = provaGPS_BMP_06_25_B.scanned1;
      } else {
        x.re = provaGPS_BMP_06_25_B.scanned1;
        x.im = provaGPS_BMP_06_25_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_25_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_readNonFinite_e(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_2_copydigits_gt(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06__copyexponent_g(char_T s1[5], int32_T *idx,
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

      provaGPS_BMP_06_25_B.kexp = *k;
      b_k = *k;
      b_success = provaGPS_BMP_06_2_copydigits_gt(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > provaGPS_BMP_06_25_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_25_readfloat_iz(char_T s1[5], int32_T *idx, const
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
    if (provaGPS_BMP_06_25_isUnitImag(s, b_k)) {
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
          provaGPS_BMP_06_25_readfloat_iz(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      provaGPS_BMP_06_readNonFinite_e(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = provaGPS_BMP_06_2_copydigits_gt(s1, idx, s, k, true);
        if (*success) {
          *success = provaGPS_BMP_06__copyexponent_g(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static creal_T provaGPS_BMP_06_2_str2double_i2(const char_T s[3])
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
  provaGPS_BMP_06_25_B.ntoread_o = 0;
  provaGPS_BMP_06_25_B.k_d = 1;
  exitg1 = false;
  while ((!exitg1) && (provaGPS_BMP_06_25_B.k_d <= 3)) {
    tmp = s[provaGPS_BMP_06_25_B.k_d - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      provaGPS_BMP_06_25_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  provaGPS_BMP_06_25_B.scanned1_c = 0.0;
  provaGPS_BMP_06_25_B.idx_l = 1;
  for (provaGPS_BMP_06_25_B.b_k = 0; provaGPS_BMP_06_25_B.b_k < 5;
       provaGPS_BMP_06_25_B.b_k++) {
    provaGPS_BMP_06_25_B.s1[provaGPS_BMP_06_25_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaGPS_BMP_06_25_B.k_d <= 3)) {
    tmp = s[provaGPS_BMP_06_25_B.k_d - 1];
    if (tmp == '-') {
      isneg = !isneg;
      provaGPS_BMP_06_25_B.k_d++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      provaGPS_BMP_06_25_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  success = (provaGPS_BMP_06_25_B.k_d <= 3);
  if (success && isneg) {
    provaGPS_BMP_06_25_B.s1[0] = '-';
    provaGPS_BMP_06_25_B.idx_l = 2;
  }

  provaGPS_BMP_06_25_B.b_k = provaGPS_BMP_06_25_B.k_d - 1;
  if (success) {
    if (provaGPS_BMP_06_25_isUnitImag(s, provaGPS_BMP_06_25_B.k_d)) {
      isimag1 = true;
      provaGPS_BMP_06_25_B.b_k = provaGPS_BMP_06_25_B.k_d;
      while ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[provaGPS_BMP_06_25_B.b_k] & 127] || (s[provaGPS_BMP_06_25_B.b_k]
               == '\x00') || (s[provaGPS_BMP_06_25_B.b_k] == ','))) {
        provaGPS_BMP_06_25_B.b_k++;
      }

      if ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && (s[provaGPS_BMP_06_25_B.b_k] ==
           '*')) {
        provaGPS_BMP_06_25_B.k_d = provaGPS_BMP_06_25_B.b_k + 2;
        provaGPS_BMP_06_25_readfloat_iz(provaGPS_BMP_06_25_B.s1,
          &provaGPS_BMP_06_25_B.idx_l, s, &provaGPS_BMP_06_25_B.k_d, false,
          &isneg, &b_finite, &provaGPS_BMP_06_25_B.scanned1_c, &unusedU2,
          &success);
        provaGPS_BMP_06_25_B.b_k = provaGPS_BMP_06_25_B.k_d - 1;
      } else {
        provaGPS_BMP_06_25_B.s1[provaGPS_BMP_06_25_B.idx_l - 1] = '1';
        provaGPS_BMP_06_25_B.idx_l++;
      }
    } else {
      provaGPS_BMP_06_readNonFinite_e(s, &provaGPS_BMP_06_25_B.k_d, &b_finite,
        &provaGPS_BMP_06_25_B.scanned1_c);
      provaGPS_BMP_06_25_B.b_k = provaGPS_BMP_06_25_B.k_d - 1;
      if (b_finite) {
        success = provaGPS_BMP_06_2_copydigits_gt(provaGPS_BMP_06_25_B.s1,
          &provaGPS_BMP_06_25_B.idx_l, s, &provaGPS_BMP_06_25_B.k_d, true);
        provaGPS_BMP_06_25_B.b_k = provaGPS_BMP_06_25_B.k_d - 1;
        if (success) {
          success = provaGPS_BMP_06__copyexponent_g(provaGPS_BMP_06_25_B.s1,
            &provaGPS_BMP_06_25_B.idx_l, s, &provaGPS_BMP_06_25_B.k_d);
          provaGPS_BMP_06_25_B.b_k = provaGPS_BMP_06_25_B.k_d - 1;
        }
      } else {
        if ((provaGPS_BMP_06_25_B.idx_l >= 2) && (provaGPS_BMP_06_25_B.s1[0] ==
             '-')) {
          provaGPS_BMP_06_25_B.idx_l = 1;
          provaGPS_BMP_06_25_B.s1[0] = ' ';
          provaGPS_BMP_06_25_B.scanned1_c = -provaGPS_BMP_06_25_B.scanned1_c;
        }
      }

      while ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[provaGPS_BMP_06_25_B.b_k] & 127] || (s[provaGPS_BMP_06_25_B.b_k]
               == '\x00') || (s[provaGPS_BMP_06_25_B.b_k] == ','))) {
        provaGPS_BMP_06_25_B.b_k++;
      }

      if ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && (s[provaGPS_BMP_06_25_B.b_k] ==
           '*')) {
        provaGPS_BMP_06_25_B.b_k++;
        while ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[provaGPS_BMP_06_25_B.b_k] & 127] ||
                (s[provaGPS_BMP_06_25_B.b_k] == '\x00') ||
                (s[provaGPS_BMP_06_25_B.b_k] == ','))) {
          provaGPS_BMP_06_25_B.b_k++;
        }
      }

      if ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && ((s[provaGPS_BMP_06_25_B.b_k] ==
            'i') || (s[provaGPS_BMP_06_25_B.b_k] == 'j'))) {
        provaGPS_BMP_06_25_B.b_k++;
        isimag1 = true;
      }
    }

    while ((provaGPS_BMP_06_25_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[provaGPS_BMP_06_25_B.b_k] & 127] || (s[provaGPS_BMP_06_25_B.b_k] ==
             '\x00') || (s[provaGPS_BMP_06_25_B.b_k] == ','))) {
      provaGPS_BMP_06_25_B.b_k++;
    }
  }

  if (b_finite) {
    provaGPS_BMP_06_25_B.ntoread_o = 1;
  }

  if (success && (provaGPS_BMP_06_25_B.b_k + 1 <= 3)) {
    provaGPS_BMP_06_25_B.s1[provaGPS_BMP_06_25_B.idx_l - 1] = ' ';
    provaGPS_BMP_06_25_B.idx_l++;
    provaGPS_BMP_06_25_B.k_d = provaGPS_BMP_06_25_B.b_k + 1;
    provaGPS_BMP_06_25_readfloat_iz(provaGPS_BMP_06_25_B.s1,
      &provaGPS_BMP_06_25_B.idx_l, s, &provaGPS_BMP_06_25_B.k_d, true, &success,
      &isneg, &provaGPS_BMP_06_25_B.scanned2_f, &unusedU2, &c_success);
    if (isneg) {
      provaGPS_BMP_06_25_B.ntoread_o++;
    }

    success = (c_success && (provaGPS_BMP_06_25_B.k_d > 3) && (isimag1 !=
                success) && unusedU2);
  } else {
    provaGPS_BMP_06_25_B.scanned2_f = 0.0;
  }

  if (success) {
    provaGPS_BMP_06_25_B.s1[provaGPS_BMP_06_25_B.idx_l - 1] = '\x00';
    switch (provaGPS_BMP_06_25_B.ntoread_o) {
     case 2:
      provaGPS_BMP_06_25_B.ntoread_o = sscanf(&provaGPS_BMP_06_25_B.s1[0],
        "%lf %lf", &provaGPS_BMP_06_25_B.scanned1_c,
        &provaGPS_BMP_06_25_B.scanned2_f);
      if (provaGPS_BMP_06_25_B.ntoread_o != 2) {
        provaGPS_BMP_06_25_B.scanned1_c = (rtNaN);
        provaGPS_BMP_06_25_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      provaGPS_BMP_06_25_B.ntoread_o = sscanf(&provaGPS_BMP_06_25_B.s1[0], "%lf",
        &provaGPS_BMP_06_25_B.b_scanned1_g);
      if (b_finite) {
        if (provaGPS_BMP_06_25_B.ntoread_o == 1) {
          provaGPS_BMP_06_25_B.scanned1_c = provaGPS_BMP_06_25_B.b_scanned1_g;
        } else {
          provaGPS_BMP_06_25_B.scanned1_c = (rtNaN);
        }
      } else if (provaGPS_BMP_06_25_B.ntoread_o == 1) {
        provaGPS_BMP_06_25_B.scanned2_f = provaGPS_BMP_06_25_B.b_scanned1_g;
      } else {
        provaGPS_BMP_06_25_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaGPS_BMP_06_25_B.scanned2_f;
      x.im = provaGPS_BMP_06_25_B.scanned1_c;
    } else {
      x.re = provaGPS_BMP_06_25_B.scanned1_c;
      x.im = provaGPS_BMP_06_25_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_0_readNonFinite_ec(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06__copydigits_gt3(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static boolean_T provaGPS_BMP_06_copyexponent_gr(char_T s1[3], int32_T *idx,
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
    b_success = provaGPS_BMP_06__copydigits_gt3(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static void provaGPS_BMP_06_2_readfloat_izz(char_T s1[3], int32_T *idx, char_T s,
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
          provaGPS_BMP_06_2_readfloat_izz(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      provaGPS_BMP_0_readNonFinite_ec(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = provaGPS_BMP_06__copydigits_gt3(s1, idx, s, k, true);
        if (*success) {
          *success = provaGPS_BMP_06_copyexponent_gr(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static creal_T provaGPS_BMP_06__str2double_i2v(char_T s)
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
  provaGPS_BMP_06_25_B.ntoread_bn = 0;
  provaGPS_BMP_06_25_B.d_k = 1;
  provaGPS_BMP_06_25_B.i_d = (uint8_T)s & 127;
  if (c[provaGPS_BMP_06_25_B.i_d] || (s == '\x00')) {
    provaGPS_BMP_06_25_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  provaGPS_BMP_06_25_B.scanned1_p = 0.0;
  provaGPS_BMP_06_25_B.idx_h = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaGPS_BMP_06_25_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      provaGPS_BMP_06_25_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[provaGPS_BMP_06_25_B.i_d]) {
      provaGPS_BMP_06_25_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (provaGPS_BMP_06_25_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    provaGPS_BMP_06_25_B.idx_h = 2;
  }

  if (success) {
    isneg = false;
    if (provaGPS_BMP_06_25_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      provaGPS_BMP_06_25_B.d_k++;
      s1[provaGPS_BMP_06_25_B.idx_h - 1] = '1';
      provaGPS_BMP_06_25_B.idx_h++;
    } else {
      provaGPS_BMP_0_readNonFinite_ec(s, &provaGPS_BMP_06_25_B.d_k, &b_finite,
        &provaGPS_BMP_06_25_B.scanned1_p);
      if (b_finite) {
        success = provaGPS_BMP_06__copydigits_gt3(s1,
          &provaGPS_BMP_06_25_B.idx_h, s, &provaGPS_BMP_06_25_B.d_k, true);
        if (success) {
          success = provaGPS_BMP_06_copyexponent_gr(s1,
            &provaGPS_BMP_06_25_B.idx_h, s, &provaGPS_BMP_06_25_B.d_k);
        }
      } else {
        if ((provaGPS_BMP_06_25_B.idx_h >= 2) && (s1[0] == '-')) {
          provaGPS_BMP_06_25_B.idx_h = 1;
          s1[0] = ' ';
          provaGPS_BMP_06_25_B.scanned1_p = -provaGPS_BMP_06_25_B.scanned1_p;
        }
      }

      while ((provaGPS_BMP_06_25_B.d_k <= 1) && (c[provaGPS_BMP_06_25_B.i_d] ||
              ((s == '\x00') || (s == ',')))) {
        provaGPS_BMP_06_25_B.d_k = 2;
      }

      if ((provaGPS_BMP_06_25_B.d_k <= 1) && (s == '*')) {
        provaGPS_BMP_06_25_B.d_k = 2;
      }

      if ((provaGPS_BMP_06_25_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        provaGPS_BMP_06_25_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((provaGPS_BMP_06_25_B.d_k <= 1) && (c[provaGPS_BMP_06_25_B.i_d] ||
            ((s == '\x00') || (s == ',')))) {
      provaGPS_BMP_06_25_B.d_k = 2;
    }
  }

  if (b_finite) {
    provaGPS_BMP_06_25_B.ntoread_bn = 1;
  }

  if (success && (provaGPS_BMP_06_25_B.d_k <= 1)) {
    s1[provaGPS_BMP_06_25_B.idx_h - 1] = ' ';
    provaGPS_BMP_06_25_B.idx_h++;
    provaGPS_BMP_06_25_B.d_k = 1;
    provaGPS_BMP_06_2_readfloat_izz(s1, &provaGPS_BMP_06_25_B.idx_h, s,
      &provaGPS_BMP_06_25_B.d_k, true, &success, &isneg,
      &provaGPS_BMP_06_25_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      provaGPS_BMP_06_25_B.ntoread_bn++;
    }

    success = (c_success && (provaGPS_BMP_06_25_B.d_k > 1) && (isimag1 !=
                success) && foundsign);
  } else {
    provaGPS_BMP_06_25_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[provaGPS_BMP_06_25_B.idx_h - 1] = '\x00';
    switch (provaGPS_BMP_06_25_B.ntoread_bn) {
     case 2:
      provaGPS_BMP_06_25_B.ntoread_bn = sscanf(&s1[0], "%lf %lf",
        &provaGPS_BMP_06_25_B.scanned1_p, &provaGPS_BMP_06_25_B.scanned2_l);
      if (provaGPS_BMP_06_25_B.ntoread_bn != 2) {
        provaGPS_BMP_06_25_B.scanned1_p = (rtNaN);
        provaGPS_BMP_06_25_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      provaGPS_BMP_06_25_B.ntoread_bn = sscanf(&s1[0], "%lf",
        &provaGPS_BMP_06_25_B.b_scanned1_j);
      if (b_finite) {
        if (provaGPS_BMP_06_25_B.ntoread_bn == 1) {
          provaGPS_BMP_06_25_B.scanned1_p = provaGPS_BMP_06_25_B.b_scanned1_j;
        } else {
          provaGPS_BMP_06_25_B.scanned1_p = (rtNaN);
        }
      } else if (provaGPS_BMP_06_25_B.ntoread_bn == 1) {
        provaGPS_BMP_06_25_B.scanned2_l = provaGPS_BMP_06_25_B.b_scanned1_j;
      } else {
        provaGPS_BMP_06_25_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaGPS_BMP_06_25_B.scanned2_l;
      x.im = provaGPS_BMP_06_25_B.scanned1_p;
    } else {
      x.re = provaGPS_BMP_06_25_B.scanned1_p;
      x.im = provaGPS_BMP_06_25_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S38>/MATLAB Function' */
static real_T provaGPS_BMP_06_25_hex2dec(const char_T s[2])
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

  provaGPS_BMP_06_25_B.a = tmp_0;
  provaGPS_BMP_06_25_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &provaGPS_BMP_06_25_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&provaGPS_BMP_06_25_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &provaGPS_BMP_06_25_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &provaGPS_BMP_06_25_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&provaGPS_BMP_06_25_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &provaGPS_BMP_06_25_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &provaGPS_BMP_06_25_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&provaGPS_BMP_06_25_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &provaGPS_BMP_06_25_B.sk.chunks[0U], 2);
      } else {
        provaGPS_BMP_06_25_B.sk = tmp_0;
      }
    } else {
      provaGPS_BMP_06_25_B.sk = tmp_0;
    }

    uMultiWordMul(&provaGPS_BMP_06_25_B.sk.chunks[0U], 2,
                  &provaGPS_BMP_06_25_B.p16.chunks[0U], 2,
                  &provaGPS_BMP_06_25_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&provaGPS_BMP_06_25_B.r.chunks[0U], 4,
                         &provaGPS_BMP_06_25_B.r3.chunks[0U], 2);
    MultiWordAdd(&provaGPS_BMP_06_25_B.a.chunks[0U],
                 &provaGPS_BMP_06_25_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    provaGPS_BMP_06_25_B.a = tmp;
    uMultiWord2MultiWord(&provaGPS_BMP_06_25_B.p16.chunks[0U], 2,
                         &provaGPS_BMP_06_25_B.r2.chunks[0U], 3);
    uMultiWordShl(&provaGPS_BMP_06_25_B.r2.chunks[0U], 3, 4U,
                  &provaGPS_BMP_06_25_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&provaGPS_BMP_06_25_B.r1.chunks[0U], 3,
                         &provaGPS_BMP_06_25_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&provaGPS_BMP_06_25_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&provaGPS_BMP_06_25_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&provaGPS_BMP_06_25_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&provaGPS_BMP_06_25_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&provaGPS_BMP_06_25_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&provaGPS_BMP_06_25_B.a.chunks[0U], 2, 0);
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
void provaGPS_BMP_06_25_step0(void)    /* Sample time: [0.02s, 0.0s] */
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
  Seriale_mav_Outputs_wrapper(&provaGPS_BMP_06_25_P.Constant1_Value_h,
    &provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[0],
    &provaGPS_BMP_06_25_B.SFunctionBuilder_o2,
    &provaGPS_BMP_06_25_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  provaGPS_BMP_06_25_B.status = 0;
  provaGPS_BMP_06_25_B.caso = 0;
  memset(&provaGPS_BMP_06_25_B.messaggio_j[0], 0, 100U * sizeof(uint8_T));
  memset(&provaGPS_BMP_06_25_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  provaGPS_BMP_06_25_find_254(provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e,
    provaGPS_BMP_06_25_B.poss_254, &provaGPS_BMP_06_25_B.num_254);
  if (provaGPS_BMP_06_25_DW.Interr_parz && (provaGPS_BMP_06_25_B.num_254 == 1.0))
  {
    provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_DW.counter_b + 1U);
    if (provaGPS_BMP_06_25_DW.counter_b + 1U > 255U) {
      provaGPS_BMP_06_25_B.f_l = 255;
    }

    if (provaGPS_BMP_06_25_B.poss_254[0] != provaGPS_BMP_06_25_B.f_l) {
      provaGPS_BMP_06_25_B.num_254 = 0.0;
    }
  }

  y = !provaGPS_BMP_06_25_DW.Interr_parz;
  if ((provaGPS_BMP_06_25_B.num_254 == 1.0) && y) {
    provaGPS_BMP_06_25_B.caso = 1;
  } else if ((provaGPS_BMP_06_25_B.num_254 == 0.0) &&
             provaGPS_BMP_06_25_DW.Interr_parz) {
    provaGPS_BMP_06_25_B.caso = 2;
  } else if ((provaGPS_BMP_06_25_B.num_254 == 1.0) &&
             provaGPS_BMP_06_25_DW.Interr_parz) {
    provaGPS_BMP_06_25_B.caso = 3;
  } else {
    if ((provaGPS_BMP_06_25_B.num_254 == 2.0) && y) {
      provaGPS_BMP_06_25_B.caso = 4;
    }
  }

  switch (provaGPS_BMP_06_25_B.caso) {
   case 1:
    provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_B.poss_254[(int32_T)
      provaGPS_BMP_06_25_B.num_254 - 1];
    if (provaGPS_BMP_06_25_B.RateTransition == 100.0) {
      provaGPS_BMP_06_25_DW.message_l[0] =
        provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[99];
      provaGPS_BMP_06_25_DW.Interr_parz = true;
    } else if (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
               (provaGPS_BMP_06_25_B.RateTransition + 1.0) - 1] <= 100) {
      provaGPS_BMP_06_25_B.f_l = (int32_T)
        (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
         (provaGPS_BMP_06_25_B.poss_254[0] + 1.0) - 1] + 8U);
      provaGPS_BMP_06_25_B.i = provaGPS_BMP_06_25_B.f_l;
      if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
        provaGPS_BMP_06_25_B.i = 255;
      }

      if (provaGPS_BMP_06_25_B.i == provaGPS_BMP_06_25_B.SFunctionBuilder_o2) {
        provaGPS_BMP_06_25_B.num_254 = rt_roundd_snf
          (provaGPS_BMP_06_25_B.RateTransition);
        if (provaGPS_BMP_06_25_B.num_254 < 256.0) {
          if (provaGPS_BMP_06_25_B.num_254 >= 0.0) {
            counter = (uint8_T)provaGPS_BMP_06_25_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provaGPS_BMP_06_25_B.f_l = (int32_T)
          (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
           (provaGPS_BMP_06_25_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
          provaGPS_BMP_06_25_B.f_l = 255;
        }

        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
          (provaGPS_BMP_06_25_B.RateTransition + (real_T)
           provaGPS_BMP_06_25_B.f_l);
        if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
          if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          provaGPS_BMP_06_25_B.i = 0;
          provaGPS_BMP_06_25_B.f_l = 0;
        } else {
          provaGPS_BMP_06_25_B.i = counter - 1;
          provaGPS_BMP_06_25_B.f_l = find_comma;
        }

        provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.f_l -
          provaGPS_BMP_06_25_B.i;
        for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
             provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.f_l] =
            provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.i +
            provaGPS_BMP_06_25_B.f_l];
        }

        provaGPS_BMP_06_25_B.status = 1;
        for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 100;
             provaGPS_BMP_06_25_B.i++) {
          provaGPS_BMP_06_25_B.messaggio_j[provaGPS_BMP_06_25_B.i] =
            provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i];
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i] = 0U;
        }

        provaGPS_BMP_06_25_DW.counter_b = 0U;
        provaGPS_BMP_06_25_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
          provaGPS_BMP_06_25_B.f_l = 255;
        }

        if (provaGPS_BMP_06_25_B.f_l > provaGPS_BMP_06_25_B.SFunctionBuilder_o2)
        {
          provaGPS_BMP_06_25_DW.mess_len =
            provaGPS_BMP_06_25_B.SFunctionBuilder_o2;
          if (provaGPS_BMP_06_25_B.RateTransition >
              provaGPS_BMP_06_25_DW.mess_len) {
            provaGPS_BMP_06_25_B.i = 0;
            provaGPS_BMP_06_25_B.f_l = 0;
          } else {
            provaGPS_BMP_06_25_B.i = (int32_T)
              provaGPS_BMP_06_25_B.RateTransition - 1;
            provaGPS_BMP_06_25_B.f_l = (int32_T)provaGPS_BMP_06_25_DW.mess_len;
          }

          provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.f_l -
            provaGPS_BMP_06_25_B.i;
          for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
               provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
            provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.f_l] =
              provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.i
              + provaGPS_BMP_06_25_B.f_l];
          }

          provaGPS_BMP_06_25_B.f_l = (int32_T)
            (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
             (provaGPS_BMP_06_25_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
            provaGPS_BMP_06_25_B.f_l = 255;
          }

          provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf((real_T)
            provaGPS_BMP_06_25_B.f_l - provaGPS_BMP_06_25_DW.mess_len);
          if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
            if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
              provaGPS_BMP_06_25_DW.counter_b = (uint8_T)
                provaGPS_BMP_06_25_B.RateTransition;
            } else {
              provaGPS_BMP_06_25_DW.counter_b = 0U;
            }
          } else {
            provaGPS_BMP_06_25_DW.counter_b = MAX_uint8_T;
          }

          provaGPS_BMP_06_25_DW.Interr_parz = true;
        }
      }
    } else {
      provaGPS_BMP_06_25_DW.Interr_parz = false;
      memset(&provaGPS_BMP_06_25_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      provaGPS_BMP_06_25_DW.counter_b = 0U;
      provaGPS_BMP_06_25_DW.mess_len = 0.0;
      provaGPS_BMP_06_25_B.status = 1;
    }
    break;

   case 2:
    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.x[provaGPS_BMP_06_25_B.f_l] =
        (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.f_l] !=
         0);
    }

    if (provaGPS_BMP_06_25_ifWhileCond(provaGPS_BMP_06_25_B.x)) {
      provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
        (provaGPS_BMP_06_25_DW.mess_len + 1.0);
      if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
        if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
        (provaGPS_BMP_06_25_DW.mess_len + (real_T)
         provaGPS_BMP_06_25_DW.counter_b);
      if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
        if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
          counter = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (find_comma > counter) {
        provaGPS_BMP_06_25_B.status = 1;
      } else {
        provaGPS_BMP_06_25_B.status = find_comma;
      }

      if (1 > provaGPS_BMP_06_25_DW.counter_b) {
        provaGPS_BMP_06_25_B.caso = -1;
      } else {
        provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_DW.counter_b - 1;
      }

      for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <=
           provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
        provaGPS_BMP_06_25_DW.message_l[(provaGPS_BMP_06_25_B.status +
          provaGPS_BMP_06_25_B.f_l) - 1] =
          provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.f_l];
      }

      provaGPS_BMP_06_25_DW.Interr_parz = false;
      provaGPS_BMP_06_25_B.status = 1;
      for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 100;
           provaGPS_BMP_06_25_B.i++) {
        provaGPS_BMP_06_25_B.messaggio_j[provaGPS_BMP_06_25_B.i] =
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i];
        provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i] = 0U;
      }

      provaGPS_BMP_06_25_DW.mess_len = 0.0;
      provaGPS_BMP_06_25_DW.counter_b = 0U;
    } else {
      provaGPS_BMP_06_25_DW.Interr_parz = false;
      provaGPS_BMP_06_25_B.status = 1;
      memset(&provaGPS_BMP_06_25_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      provaGPS_BMP_06_25_DW.mess_len = 0.0;
      provaGPS_BMP_06_25_DW.counter_b = 0U;
    }
    break;

   case 3:
    provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
      (provaGPS_BMP_06_25_DW.mess_len + 1.0);
    if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
      if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
        find_comma = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
      (provaGPS_BMP_06_25_DW.mess_len + (real_T)provaGPS_BMP_06_25_DW.counter_b);
    if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
      if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
        counter = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (find_comma > counter) {
      provaGPS_BMP_06_25_B.i = 1;
    } else {
      provaGPS_BMP_06_25_B.i = find_comma;
    }

    if (1 > provaGPS_BMP_06_25_DW.counter_b) {
      provaGPS_BMP_06_25_B.caso = -1;
    } else {
      provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_DW.counter_b - 1;
    }

    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <=
         provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_DW.message_l[(provaGPS_BMP_06_25_B.i +
        provaGPS_BMP_06_25_B.f_l) - 1] =
        provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.f_l];
    }

    provaGPS_BMP_06_25_DW.Interr_parz = false;
    provaGPS_BMP_06_25_B.status = 1;
    for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 100;
         provaGPS_BMP_06_25_B.i++) {
      provaGPS_BMP_06_25_B.messaggio_j[provaGPS_BMP_06_25_B.i] =
        provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i];
      provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i] = 0U;
    }

    provaGPS_BMP_06_25_DW.mess_len = 0.0;
    provaGPS_BMP_06_25_DW.counter_b = 0U;
    provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_B.poss_254[(int32_T)
      provaGPS_BMP_06_25_B.num_254 - 1] + 1.0) - 1;
    if (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.f_l] <=
        100) {
      provaGPS_BMP_06_25_B.i = (int32_T)
        (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
         (provaGPS_BMP_06_25_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)provaGPS_BMP_06_25_B.i > 255U) {
        provaGPS_BMP_06_25_B.i = 255;
      }

      provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.SFunctionBuilder_o2;
      if (provaGPS_BMP_06_25_B.SFunctionBuilder_o2 < 0) {
        provaGPS_BMP_06_25_B.caso = 0;
      } else {
        if (provaGPS_BMP_06_25_B.SFunctionBuilder_o2 > 255) {
          provaGPS_BMP_06_25_B.caso = 255;
        }
      }

      if (provaGPS_BMP_06_25_B.i == provaGPS_BMP_06_25_B.caso) {
        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
          (provaGPS_BMP_06_25_B.poss_254[(int32_T)provaGPS_BMP_06_25_B.num_254 -
           1]);
        if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
          if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
            counter = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provaGPS_BMP_06_25_B.f_l = (int32_T)
          (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.f_l]
           + 7U);
        if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
          provaGPS_BMP_06_25_B.f_l = 255;
        }

        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
          (provaGPS_BMP_06_25_B.poss_254[(int32_T)provaGPS_BMP_06_25_B.num_254 -
           1] + (real_T)provaGPS_BMP_06_25_B.f_l);
        if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
          if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          provaGPS_BMP_06_25_B.i = 0;
          provaGPS_BMP_06_25_B.f_l = 0;
        } else {
          provaGPS_BMP_06_25_B.i = counter - 1;
          provaGPS_BMP_06_25_B.f_l = find_comma;
        }

        provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.f_l -
          provaGPS_BMP_06_25_B.i;
        for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
             provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.f_l] =
            provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.i +
            provaGPS_BMP_06_25_B.f_l];
        }

        for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 100;
             provaGPS_BMP_06_25_B.i++) {
          provaGPS_BMP_06_25_B.messaggio_2[provaGPS_BMP_06_25_B.i] =
            provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i];
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i] = 0U;
        }

        provaGPS_BMP_06_25_DW.counter_b = 0U;
        provaGPS_BMP_06_25_DW.mess_len = 0.0;
      } else {
        provaGPS_BMP_06_25_B.i = (int32_T)
          (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
           (provaGPS_BMP_06_25_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)provaGPS_BMP_06_25_B.i > 255U) {
          provaGPS_BMP_06_25_B.i = 255;
        }

        provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.SFunctionBuilder_o2;
        if (provaGPS_BMP_06_25_B.SFunctionBuilder_o2 < 0) {
          provaGPS_BMP_06_25_B.caso = 0;
        } else {
          if (provaGPS_BMP_06_25_B.SFunctionBuilder_o2 > 255) {
            provaGPS_BMP_06_25_B.caso = 255;
          }
        }

        if (provaGPS_BMP_06_25_B.i > provaGPS_BMP_06_25_B.caso) {
          provaGPS_BMP_06_25_DW.mess_len =
            provaGPS_BMP_06_25_B.SFunctionBuilder_o2;
          if (provaGPS_BMP_06_25_B.poss_254[(int32_T)
              provaGPS_BMP_06_25_B.num_254 - 1] > provaGPS_BMP_06_25_DW.mess_len)
          {
            provaGPS_BMP_06_25_B.x_d = 0;
            provaGPS_BMP_06_25_B.caso = 0;
          } else {
            provaGPS_BMP_06_25_B.x_d = (int32_T)provaGPS_BMP_06_25_B.poss_254
              [(int32_T)provaGPS_BMP_06_25_B.num_254 - 1] - 1;
            provaGPS_BMP_06_25_B.caso = (int32_T)provaGPS_BMP_06_25_DW.mess_len;
          }

          provaGPS_BMP_06_25_B.caso -= provaGPS_BMP_06_25_B.x_d;
          for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i <
               provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.i++) {
            provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i] =
              provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.x_d
              + provaGPS_BMP_06_25_B.i];
          }

          provaGPS_BMP_06_25_B.f_l = (int32_T)
            (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.f_l]
             + 8U);
          if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
            provaGPS_BMP_06_25_B.f_l = 255;
          }

          provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf((real_T)
            provaGPS_BMP_06_25_B.f_l - provaGPS_BMP_06_25_DW.mess_len);
          if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
            if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
              provaGPS_BMP_06_25_DW.counter_b = (uint8_T)
                provaGPS_BMP_06_25_B.RateTransition;
            } else {
              provaGPS_BMP_06_25_DW.counter_b = 0U;
            }
          } else {
            provaGPS_BMP_06_25_DW.counter_b = MAX_uint8_T;
          }

          provaGPS_BMP_06_25_DW.Interr_parz = true;
        }
      }
    } else {
      provaGPS_BMP_06_25_DW.Interr_parz = false;
      memset(&provaGPS_BMP_06_25_B.messaggio_j[0], 0, 100U * sizeof(uint8_T));
      memset(&provaGPS_BMP_06_25_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      provaGPS_BMP_06_25_DW.counter_b = 0U;
      provaGPS_BMP_06_25_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
        (provaGPS_BMP_06_25_B.poss_254[0] + 1.0) - 1] <= 100) {
      provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
        (provaGPS_BMP_06_25_B.poss_254[0]);
      if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
        if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
          counter = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      provaGPS_BMP_06_25_B.f_l = (int32_T)
        (provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
         (provaGPS_BMP_06_25_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
        provaGPS_BMP_06_25_B.f_l = 255;
      }

      provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
        (provaGPS_BMP_06_25_B.poss_254[0] + (real_T)provaGPS_BMP_06_25_B.f_l);
      if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
        if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (counter > find_comma) {
        provaGPS_BMP_06_25_B.status = 0;
        provaGPS_BMP_06_25_B.f_l = 0;
      } else {
        provaGPS_BMP_06_25_B.status = counter - 1;
        provaGPS_BMP_06_25_B.f_l = find_comma;
      }

      provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.f_l -
        provaGPS_BMP_06_25_B.status;
      for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
           provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
        provaGPS_BMP_06_25_B.messaggio_j[provaGPS_BMP_06_25_B.f_l] =
          provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.status
          + provaGPS_BMP_06_25_B.f_l];
      }
    } else {
      provaGPS_BMP_06_25_DW.Interr_parz = false;
      memset(&provaGPS_BMP_06_25_DW.message_l[0], 0, 100U * sizeof(uint8_T));
    }

    provaGPS_BMP_06_25_B.status = 1;
    if ((provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[(int32_T)
         (provaGPS_BMP_06_25_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (provaGPS_BMP_06_25_B.poss_254[1] - provaGPS_BMP_06_25_B.poss_254[0] >
         3.0)) {
      provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf((real_T)
        provaGPS_BMP_06_25_B.SFunctionBuilder_o2 -
        provaGPS_BMP_06_25_B.poss_254[1]);
      provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e
        [(int32_T)(provaGPS_BMP_06_25_B.poss_254[1] + 1.0) - 1];
      provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_B.qY + 7U);
      if (provaGPS_BMP_06_25_B.qY + 7U > 255U) {
        provaGPS_BMP_06_25_B.f_l = 255;
      }

      if (provaGPS_BMP_06_25_B.RateTransition < 2.147483648E+9) {
        if (provaGPS_BMP_06_25_B.RateTransition >= -2.147483648E+9) {
          provaGPS_BMP_06_25_B.i = (int32_T)provaGPS_BMP_06_25_B.RateTransition;
        } else {
          provaGPS_BMP_06_25_B.i = MIN_int32_T;
        }
      } else {
        provaGPS_BMP_06_25_B.i = MAX_int32_T;
      }

      if (provaGPS_BMP_06_25_B.i == provaGPS_BMP_06_25_B.f_l) {
        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
          (provaGPS_BMP_06_25_B.poss_254[1]);
        if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
          if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
            counter = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_B.qY + 7U);
        if (provaGPS_BMP_06_25_B.qY + 7U > 255U) {
          provaGPS_BMP_06_25_B.f_l = 255;
        }

        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
          (provaGPS_BMP_06_25_B.poss_254[1] + (real_T)provaGPS_BMP_06_25_B.f_l);
        if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
          if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)provaGPS_BMP_06_25_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          provaGPS_BMP_06_25_B.status = 0;
          provaGPS_BMP_06_25_B.f_l = 0;
        } else {
          provaGPS_BMP_06_25_B.status = counter - 1;
          provaGPS_BMP_06_25_B.f_l = find_comma;
        }

        provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.f_l -
          provaGPS_BMP_06_25_B.status;
        for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
             provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.f_l] =
            provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.status
            + provaGPS_BMP_06_25_B.f_l];
        }

        provaGPS_BMP_06_25_B.status = 2;
        for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 100;
             provaGPS_BMP_06_25_B.i++) {
          provaGPS_BMP_06_25_B.messaggio_2[provaGPS_BMP_06_25_B.i] =
            provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i];
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.i] = 0U;
        }

        provaGPS_BMP_06_25_DW.counter_b = 0U;
        provaGPS_BMP_06_25_DW.mess_len = 0.0;
      } else {
        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf
          (provaGPS_BMP_06_25_B.poss_254[1]);
        if (provaGPS_BMP_06_25_B.RateTransition < 2.147483648E+9) {
          if (provaGPS_BMP_06_25_B.RateTransition >= -2.147483648E+9) {
            provaGPS_BMP_06_25_B.f_l = (int32_T)
              provaGPS_BMP_06_25_B.RateTransition;
          } else {
            provaGPS_BMP_06_25_B.f_l = MIN_int32_T;
          }
        } else {
          provaGPS_BMP_06_25_B.f_l = MAX_int32_T;
        }

        if (provaGPS_BMP_06_25_B.f_l > provaGPS_BMP_06_25_B.SFunctionBuilder_o2)
        {
          provaGPS_BMP_06_25_B.f_l = -1;
          provaGPS_BMP_06_25_B.caso = 0;
        } else {
          provaGPS_BMP_06_25_B.f_l -= 2;
          provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.SFunctionBuilder_o2;
        }

        provaGPS_BMP_06_25_DW.mess_len = (int8_T)((provaGPS_BMP_06_25_B.caso -
          provaGPS_BMP_06_25_B.f_l) - 1);
        if (provaGPS_BMP_06_25_B.RateTransition < 2.147483648E+9) {
          if (provaGPS_BMP_06_25_B.RateTransition >= -2.147483648E+9) {
            provaGPS_BMP_06_25_B.f_l = (int32_T)
              provaGPS_BMP_06_25_B.RateTransition;
          } else {
            provaGPS_BMP_06_25_B.f_l = MIN_int32_T;
          }
        } else {
          provaGPS_BMP_06_25_B.f_l = MAX_int32_T;
        }

        if (provaGPS_BMP_06_25_B.f_l > provaGPS_BMP_06_25_B.SFunctionBuilder_o2)
        {
          provaGPS_BMP_06_25_B.i = 0;
          provaGPS_BMP_06_25_B.f_l = 0;
        } else {
          provaGPS_BMP_06_25_B.i = provaGPS_BMP_06_25_B.f_l - 1;
          provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.SFunctionBuilder_o2;
        }

        provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.f_l -
          provaGPS_BMP_06_25_B.i;
        for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
             provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
          provaGPS_BMP_06_25_DW.message_l[provaGPS_BMP_06_25_B.f_l] =
            provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[provaGPS_BMP_06_25_B.i +
            provaGPS_BMP_06_25_B.f_l];
        }

        provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_B.qY + 8U);
        if (provaGPS_BMP_06_25_B.qY + 8U > 255U) {
          provaGPS_BMP_06_25_B.f_l = 255;
        }

        provaGPS_BMP_06_25_B.RateTransition = rt_roundd_snf((real_T)
          provaGPS_BMP_06_25_B.f_l - provaGPS_BMP_06_25_DW.mess_len);
        if (provaGPS_BMP_06_25_B.RateTransition < 256.0) {
          if (provaGPS_BMP_06_25_B.RateTransition >= 0.0) {
            provaGPS_BMP_06_25_DW.counter_b = (uint8_T)
              provaGPS_BMP_06_25_B.RateTransition;
          } else {
            provaGPS_BMP_06_25_DW.counter_b = 0U;
          }
        } else {
          provaGPS_BMP_06_25_DW.counter_b = MAX_uint8_T;
        }

        provaGPS_BMP_06_25_DW.Interr_parz = true;
      }
    } else {
      provaGPS_BMP_06_25_DW.Interr_parz = false;
      memset(&provaGPS_BMP_06_25_DW.message_l[0], 0, 100U * sizeof(uint8_T));
      provaGPS_BMP_06_25_DW.counter_b = 0U;
      provaGPS_BMP_06_25_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&provaGPS_BMP_06_25_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
       provaGPS_BMP_06_25_B.f_l++) {
    provaGPS_BMP_06_25_B.buffer[3 * provaGPS_BMP_06_25_B.f_l] = 0U;
  }

  for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
       provaGPS_BMP_06_25_B.f_l++) {
    for (provaGPS_BMP_06_25_B.caso = 0; provaGPS_BMP_06_25_B.caso < 2;
         provaGPS_BMP_06_25_B.caso++) {
      provaGPS_BMP_06_25_B.i = 3 * provaGPS_BMP_06_25_B.f_l +
        provaGPS_BMP_06_25_B.caso;
      provaGPS_BMP_06_25_B.buffer[provaGPS_BMP_06_25_B.i + 1] =
        provaGPS_BMP_06_25_DW.Memory4_PreviousInput[provaGPS_BMP_06_25_B.i];
    }
  }

  provaGPS_BMP_06_25_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (provaGPS_BMP_06_25_B.i >= 1)) {
    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.x[provaGPS_BMP_06_25_B.f_l] =
        (provaGPS_BMP_06_25_B.buffer[(3 * provaGPS_BMP_06_25_B.f_l +
          provaGPS_BMP_06_25_B.i) - 1] == 0);
    }

    y = true;
    provaGPS_BMP_06_25_B.f_l = 0;
    exitg2 = false;
    while ((!exitg2) && (provaGPS_BMP_06_25_B.f_l < 100)) {
      if (!provaGPS_BMP_06_25_B.x[provaGPS_BMP_06_25_B.f_l]) {
        y = false;
        exitg2 = true;
      } else {
        provaGPS_BMP_06_25_B.f_l++;
      }
    }

    if (y) {
      counter = (uint8_T)provaGPS_BMP_06_25_B.i;
      exitg1 = true;
    } else {
      provaGPS_BMP_06_25_B.i--;
    }
  }

  if (provaGPS_BMP_06_25_B.status == 1) {
    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.buffer[(counter + 3 * provaGPS_BMP_06_25_B.f_l) - 1] =
        provaGPS_BMP_06_25_B.messaggio_j[provaGPS_BMP_06_25_B.f_l];
    }
  } else if (provaGPS_BMP_06_25_B.status == 2) {
    provaGPS_BMP_06_25_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      provaGPS_BMP_06_25_B.qY = 0U;
    }

    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.buffer[(counter + 3 * provaGPS_BMP_06_25_B.f_l) - 1] =
        provaGPS_BMP_06_25_B.messaggio_j[provaGPS_BMP_06_25_B.f_l];
      provaGPS_BMP_06_25_B.buffer[((int32_T)provaGPS_BMP_06_25_B.qY + 3 *
        provaGPS_BMP_06_25_B.f_l) - 1] =
        provaGPS_BMP_06_25_B.messaggio_2[provaGPS_BMP_06_25_B.f_l];
    }
  } else {
    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.buffer[(counter + 3 * provaGPS_BMP_06_25_B.f_l) - 1] =
        0U;
    }
  }

  for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
       provaGPS_BMP_06_25_B.f_l++) {
    provaGPS_BMP_06_25_B.mess_out[provaGPS_BMP_06_25_B.f_l] =
      provaGPS_BMP_06_25_DW.Memory4_PreviousInput[3 * provaGPS_BMP_06_25_B.f_l +
      2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  provaGPS_BMP_06_25_B.Add = provaGPS_BMP_06_25_DW.Memory4_PreviousInput[5] +
    provaGPS_BMP_06_25_P.Constant_Value_jl;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (provaGPS_BMP_06_25_B.mess_out[2] !=
      provaGPS_BMP_06_25_DW.Memory5_PreviousInput[2]) {
    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 100;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.x[provaGPS_BMP_06_25_B.f_l] =
        (provaGPS_BMP_06_25_B.mess_out[provaGPS_BMP_06_25_B.f_l] != 0);
    }

    y = true;
    provaGPS_BMP_06_25_B.f_l = 0;
    exitg1 = false;
    while ((!exitg1) && (provaGPS_BMP_06_25_B.f_l < 100)) {
      if (!provaGPS_BMP_06_25_B.x[provaGPS_BMP_06_25_B.f_l]) {
        y = false;
        exitg1 = true;
      } else {
        provaGPS_BMP_06_25_B.f_l++;
      }
    }

    if (!y) {
      if (provaGPS_BMP_06_25_DW.counter > 100) {
        provaGPS_BMP_06_25_DW.counter = 0U;
      }

      provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_DW.counter + 1U;
      if (provaGPS_BMP_06_25_DW.counter + 1U > 65535U) {
        provaGPS_BMP_06_25_B.qY = 65535U;
      }

      provaGPS_BMP_06_25_DW.counter = (uint16_T)provaGPS_BMP_06_25_B.qY;
    }
  }

  provaGPS_BMP_06_25_B.new_mex = provaGPS_BMP_06_25_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  provaGPS_BMP_06_25_B.Memory1[0] =
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0];
  provaGPS_BMP_06_25_B.Memory1[1] =
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1];

  /* Memory: '<Root>/Memory' */
  provaGPS_BMP_06_25_B.Memory_k[0] =
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[0];
  provaGPS_BMP_06_25_B.Memory_k[1] =
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[1];
  provaGPS_BMP_06_25_B.Memory_k[2] =
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[2];
  provaGPS_BMP_06_25_B.Memory_k[3] =
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[3];

  /* Memory: '<S1>/Memory3' */
  provaGPS_BMP_06_25_B.Memory3 = provaGPS_BMP_06_25_DW.Memory3_PreviousInput;
  for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 8;
       provaGPS_BMP_06_25_B.i++) {
    /* Memory: '<S1>/Memory' */
    provaGPS_BMP_06_25_B.Memory[provaGPS_BMP_06_25_B.i] =
      provaGPS_BMP_06_25_DW.Memory_PreviousInput_e[provaGPS_BMP_06_25_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&provaGPS_BMP_06_25_B.mess_out[0], &provaGPS_BMP_06_25_B.Add,
     &provaGPS_BMP_06_25_B.new_mex, &provaGPS_BMP_06_25_P.SIUAVuint8_Value,
     &provaGPS_BMP_06_25_B.Memory[0], &provaGPS_BMP_06_25_B.Memory1[0],
     &provaGPS_BMP_06_25_B.Memory_k[0], &provaGPS_BMP_06_25_B.Memory3,
     &provaGPS_BMP_06_25_B.SFunction_o1[0], &provaGPS_BMP_06_25_B.SFunction_o2,
     &provaGPS_BMP_06_25_B.SFunction_o3_f, &provaGPS_BMP_06_25_B.SFunction_o4_j
     [0], &provaGPS_BMP_06_25_B.SFunction_o5[0],
     &provaGPS_BMP_06_25_B.SFunction_o6, &provaGPS_BMP_06_25_B.SFunction_o7[0],
     &provaGPS_BMP_06_25_B.SFunction_o8, &provaGPS_BMP_06_25_B.SFunction_o9[0],
     &provaGPS_BMP_06_25_B.SFunction_o10[0],
     &provaGPS_BMP_06_25_B.SFunction_o11[0], &provaGPS_BMP_06_25_B.SFunction_o12,
     &provaGPS_BMP_06_25_B.SFunction_o13, &provaGPS_BMP_06_25_B.SFunction_o14,
     &provaGPS_BMP_06_25_B.SFunction_o15, &provaGPS_BMP_06_25_B.SFunction_o16,
     &provaGPS_BMP_06_25_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 9;
       provaGPS_BMP_06_25_B.i++) {
    provaGPS_BMP_06_25_B.Memory2[provaGPS_BMP_06_25_B.i] =
      provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[provaGPS_BMP_06_25_B.i];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 6;
       provaGPS_BMP_06_25_B.i++) {
    provaGPS_BMP_06_25_B.WP_info_in[provaGPS_BMP_06_25_B.i] =
      provaGPS_BMP_06_25_B.SFunction_o9[provaGPS_BMP_06_25_B.i];
  }

  if ((!provaGPS_BMP_06_25_DW.WP_dbP_not_empty) ||
      ((provaGPS_BMP_06_25_B.SFunction_o7[0] == 3) &&
       (provaGPS_BMP_06_25_B.SFunction_o7[1] == 250))) {
    memset(&provaGPS_BMP_06_25_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    provaGPS_BMP_06_25_DW.WP_dbP_not_empty = true;
    memset(&provaGPS_BMP_06_25_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!provaGPS_BMP_06_25_DW.WP_dbP_AL_not_empty) ||
      ((provaGPS_BMP_06_25_B.SFunction_o7[0] == 3) &&
       (provaGPS_BMP_06_25_B.SFunction_o7[1] == 250))) {
    memset(&provaGPS_BMP_06_25_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    provaGPS_BMP_06_25_DW.WP_dbP_AL_not_empty = true;
  }

  provaGPS_BMP_06_25_B.GC_info[0] = provaGPS_BMP_06_25_B.SFunction_o7[0];
  provaGPS_BMP_06_25_B.GC_info[1] = provaGPS_BMP_06_25_B.SFunction_o7[1];
  provaGPS_BMP_06_25_B.GC_info[2] = provaGPS_BMP_06_25_B.SFunction_o11[0];
  if (provaGPS_BMP_06_25_B.GC_info[0] == 1) {
    if ((provaGPS_BMP_06_25_B.GC_info[1] > 0) && (provaGPS_BMP_06_25_B.GC_info[1]
         <= 7)) {
      if ((real32_T)fabs(provaGPS_BMP_06_25_B.SFunction_o8) > 0.0F) {
        provaGPS_BMP_06_25_DW.riferimenti[provaGPS_BMP_06_25_B.GC_info[1] - 1] =
          1.0F;
      } else {
        if (provaGPS_BMP_06_25_B.SFunction_o8 == 0.0F) {
          provaGPS_BMP_06_25_DW.riferimenti[provaGPS_BMP_06_25_B.GC_info[1] - 1]
            = 0.0F;
        }
      }
    } else {
      if ((provaGPS_BMP_06_25_B.GC_info[1] > 7) &&
          (provaGPS_BMP_06_25_B.GC_info[1] < 12)) {
        provaGPS_BMP_06_25_DW.riferimenti[provaGPS_BMP_06_25_B.GC_info[1] - 1] =
          provaGPS_BMP_06_25_B.SFunction_o8;
      }
    }
  }

  if (provaGPS_BMP_06_25_B.SFunction_o12 == 13) {
    provaGPS_BMP_06_25_DW.riferimenti[provaGPS_BMP_06_25_B.SFunction_o12 - 1] =
      provaGPS_BMP_06_25_B.SFunction_o13;
  }

  memcpy(&provaGPS_BMP_06_25_B.Val_out_MAV[0],
         &provaGPS_BMP_06_25_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((provaGPS_BMP_06_25_B.GC_info[0] == 3) && (provaGPS_BMP_06_25_B.GC_info[1]
       == 200)) {
    if (provaGPS_BMP_06_25_B.SFunction_o9[0] > 6) {
      provaGPS_BMP_06_25_B.WP_info_in[0] = 6U;
    }

    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 6;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_DW.WP_dbI[provaGPS_BMP_06_25_B.f_l] =
        provaGPS_BMP_06_25_B.WP_info_in[0];
    }
  }

  if ((provaGPS_BMP_06_25_B.GC_info[0] == 3) && (provaGPS_BMP_06_25_B.GC_info[1]
       < 200)) {
    if (provaGPS_BMP_06_25_B.SFunction_o10[1] == 0.0F) {
      provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.SFunction_o9[1] + 1U;
      if (provaGPS_BMP_06_25_B.SFunction_o9[1] + 1U > 65535U) {
        provaGPS_BMP_06_25_B.qY = 65535U;
      }

      for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 7;
           provaGPS_BMP_06_25_B.f_l++) {
        provaGPS_BMP_06_25_DW.WP_dbP[((int32_T)provaGPS_BMP_06_25_B.qY + 6 *
          provaGPS_BMP_06_25_B.f_l) - 1] =
          provaGPS_BMP_06_25_B.SFunction_o10[provaGPS_BMP_06_25_B.f_l];
      }

      provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.SFunction_o9[1] + 1U;
      if (provaGPS_BMP_06_25_B.SFunction_o9[1] + 1U > 65535U) {
        provaGPS_BMP_06_25_B.qY = 65535U;
      }

      for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 6;
           provaGPS_BMP_06_25_B.f_l++) {
        provaGPS_BMP_06_25_DW.WP_dbI[((int32_T)provaGPS_BMP_06_25_B.qY + 6 *
          (provaGPS_BMP_06_25_B.f_l + 1)) - 1] =
          provaGPS_BMP_06_25_B.WP_info_in[provaGPS_BMP_06_25_B.f_l + 1];
      }
    } else {
      provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_B.SFunction_o10[0]
        + 1.0F);
      for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 7;
           provaGPS_BMP_06_25_B.i++) {
        provaGPS_BMP_06_25_DW.WP_dbP_AL[(provaGPS_BMP_06_25_B.f_l + 6 *
          provaGPS_BMP_06_25_B.i) - 1] =
          provaGPS_BMP_06_25_B.SFunction_o10[provaGPS_BMP_06_25_B.i];
      }

      provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.SFunction_o9[1] + 1U;
      if (provaGPS_BMP_06_25_B.SFunction_o9[1] + 1U > 65535U) {
        provaGPS_BMP_06_25_B.qY = 65535U;
      }

      for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 6;
           provaGPS_BMP_06_25_B.f_l++) {
        provaGPS_BMP_06_25_DW.WP_dbI[((int32_T)provaGPS_BMP_06_25_B.qY + 6 *
          (provaGPS_BMP_06_25_B.f_l + 1)) - 1] =
          provaGPS_BMP_06_25_B.WP_info_in[provaGPS_BMP_06_25_B.f_l + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((provaGPS_BMP_06_25_B.SFunction_o6 == 0) &&
      (provaGPS_BMP_06_25_B.SFunction_o3_f == 0)) {
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 0U;
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 0U;
  } else if ((provaGPS_BMP_06_25_B.SFunction_o6 == 0) &&
             (provaGPS_BMP_06_25_B.SFunction_o3_f == 3)) {
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 0U;
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 0U;
    provaGPS_BMP_06_25_DW.test1 = 0.0;
  } else if ((provaGPS_BMP_06_25_B.SFunction_o6 == 0) &&
             (provaGPS_BMP_06_25_B.SFunction_o3_f == 2)) {
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 0U;
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 0U;
    provaGPS_BMP_06_25_DW.test1 = 0.0;
  } else if ((provaGPS_BMP_06_25_B.SFunction_o6 == 0) &&
             (provaGPS_BMP_06_25_B.SFunction_o3_f == 1)) {
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 0U;
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 0U;
    provaGPS_BMP_06_25_DW.test1 = 1.0;
  } else {
    switch (provaGPS_BMP_06_25_B.SFunction_o6) {
     case 192:
      provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 192U;
      provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 208U;
      provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((provaGPS_BMP_06_25_B.SFunction_o6 == 220) &&
          (provaGPS_BMP_06_25_B.SFunction_o3_f != 5)) {
        if ((provaGPS_BMP_06_25_B.Memory2[0] == 0) &&
            (provaGPS_BMP_06_25_B.Memory2[1] == 0) &&
            ((provaGPS_BMP_06_25_B.Memory2[2] == 1) ||
             (provaGPS_BMP_06_25_B.Memory2[3] == 1) ||
             (provaGPS_BMP_06_25_B.Memory2[4] == 1) ||
             (provaGPS_BMP_06_25_B.Memory2[5] == 1) ||
             (provaGPS_BMP_06_25_B.Memory2[6] == 1) ||
             (provaGPS_BMP_06_25_B.Memory2[7] == 1))) {
          provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 220U;
          provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 220U;
        } else if ((provaGPS_BMP_06_25_B.Memory2[0] == 0) &&
                   (provaGPS_BMP_06_25_B.Memory2[1] == 1) &&
                   ((provaGPS_BMP_06_25_B.Memory2[2] == 1) ||
                    (provaGPS_BMP_06_25_B.Memory2[3] == 1) ||
                    (provaGPS_BMP_06_25_B.Memory2[4] == 1) ||
                    (provaGPS_BMP_06_25_B.Memory2[5] == 1) ||
                    (provaGPS_BMP_06_25_B.Memory2[6] == 1) ||
                    (provaGPS_BMP_06_25_B.Memory2[7] == 1))) {
          provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 220U;
          provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 220U;
        } else {
          provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 208U;
          provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          provaGPS_BMP_06_25_DW.Memory3_PreviousInput = 208U;
        }
      } else if (provaGPS_BMP_06_25_B.SFunction_o3_f == 5) {
        provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 220U;
        provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] = 192U;
        provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  provaGPS_BMP_06_25_B.qY = 100U * provaGPS_BMP_06_25_B.SFunction_o11[5];
  if (provaGPS_BMP_06_25_B.qY > 65535U) {
    provaGPS_BMP_06_25_B.qY = 65535U;
  }

  if (provaGPS_BMP_06_25_B.SFunction_o11[4] == 0) {
    if ((uint16_T)provaGPS_BMP_06_25_B.qY == 0) {
      provaGPS_BMP_06_25_B.z = 0U;
    } else {
      provaGPS_BMP_06_25_B.z = MAX_uint16_T;
    }
  } else {
    provaGPS_BMP_06_25_B.z = (uint16_T)(provaGPS_BMP_06_25_B.SFunction_o11[4] ==
      0U ? MAX_uint32_T : (uint32_T)(uint16_T)provaGPS_BMP_06_25_B.qY /
      provaGPS_BMP_06_25_B.SFunction_o11[4]);
    provaGPS_BMP_06_25_B.x_e = (uint16_T)((uint32_T)(uint16_T)
      provaGPS_BMP_06_25_B.qY - (uint16_T)((uint32_T)provaGPS_BMP_06_25_B.z *
      provaGPS_BMP_06_25_B.SFunction_o11[4]));
    if ((provaGPS_BMP_06_25_B.x_e > 0) && (provaGPS_BMP_06_25_B.x_e >= (int32_T)
         ((uint32_T)provaGPS_BMP_06_25_B.SFunction_o11[4] >> 1) +
         (provaGPS_BMP_06_25_B.SFunction_o11[4] & 1))) {
      provaGPS_BMP_06_25_B.z++;
    }
  }

  /* RateTransition: '<S22>/Rate Transition' */
  provaGPS_BMP_06_25_B.RateTransition =
    provaGPS_BMP_06_25_DW.RateTransition_Buffer0;

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant3'
   *  Memory: '<S22>/Memory1'
   */
  provaGPS_BMP_06_25_B.num_254 = (provaGPS_BMP_06_25_P.Constant2_Value_c +
    provaGPS_BMP_06_25_P.Constant3_Value_b) +
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput;

  /* Switch: '<S22>/Switch' */
  if (provaGPS_BMP_06_25_B.num_254 > provaGPS_BMP_06_25_P.Switch_Threshold) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant2'
     */
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput =
      provaGPS_BMP_06_25_P.Constant2_Value_c;
  } else {
    /* Switch: '<S22>/Switch' */
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput = provaGPS_BMP_06_25_B.num_254;
  }

  /* End of Switch: '<S22>/Switch' */

  /* MATLAB Function: '<S14>/iflogic_function' */
  if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 1.0) ||
      (provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 3.0)) {
    provaGPS_BMP_06_25_B.iflogic = 26U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 2.0) ||
             (provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 4.0)) {
    provaGPS_BMP_06_25_B.iflogic = 30U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             (provaGPS_BMP_06_25_B.RateTransition == 2.0)) {
    provaGPS_BMP_06_25_B.iflogic = 33U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             (provaGPS_BMP_06_25_B.RateTransition == 6.0)) {
    provaGPS_BMP_06_25_B.iflogic = 34U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             (provaGPS_BMP_06_25_B.RateTransition == 0.0)) {
    provaGPS_BMP_06_25_B.iflogic = 0U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             ((provaGPS_BMP_06_25_B.RateTransition == 1.0) ||
              (provaGPS_BMP_06_25_B.RateTransition == 5.0) ||
              (provaGPS_BMP_06_25_B.RateTransition == 9.0))) {
    provaGPS_BMP_06_25_B.iflogic = 1U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             ((provaGPS_BMP_06_25_B.RateTransition == 3.0) ||
              (provaGPS_BMP_06_25_B.RateTransition == 8.0))) {
    provaGPS_BMP_06_25_B.iflogic = 74U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             (provaGPS_BMP_06_25_B.RateTransition == 7.0)) {
    provaGPS_BMP_06_25_B.iflogic = 36U;
  } else if ((provaGPS_BMP_06_25_DW.Memory1_PreviousInput == 0.0) &&
             (provaGPS_BMP_06_25_B.RateTransition == 4.0)) {
    provaGPS_BMP_06_25_B.iflogic = 29U;
  } else {
    provaGPS_BMP_06_25_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S14>/iflogic_function' */

  /* Sum: '<S22>/Add' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Memory: '<S22>/Memory'
   */
  provaGPS_BMP_06_25_DW.Memory_PreviousInput +=
    provaGPS_BMP_06_25_P.Constant_Value_j +
    provaGPS_BMP_06_25_P.Constant1_Value_n;

  /* Gain: '<S14>/Gain' */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain *
    provaGPS_BMP_06_25_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  provaGPS_BMP_06_25_B.DataTypeConversion3 = provaGPS_BMP_06_25_B.RateTransition
    < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-provaGPS_BMP_06_25_B.RateTransition :
    (uint32_T)provaGPS_BMP_06_25_B.RateTransition;

  /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 6;
       provaGPS_BMP_06_25_B.f_l++) {
    provaGPS_BMP_06_25_B.WP_info[provaGPS_BMP_06_25_B.f_l] =
      provaGPS_BMP_06_25_DW.WP_dbI[6 * provaGPS_BMP_06_25_B.f_l];
  }

  for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 7;
       provaGPS_BMP_06_25_B.f_l++) {
    provaGPS_BMP_06_25_B.WP_param[provaGPS_BMP_06_25_B.f_l] =
      provaGPS_BMP_06_25_DW.WP_dbP[6 * provaGPS_BMP_06_25_B.f_l];
  }

  if ((provaGPS_BMP_06_25_B.GC_info[0] == 2) && (provaGPS_BMP_06_25_B.GC_info[1]
       < 6)) {
    provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.GC_info[1] + 1U;
    if (provaGPS_BMP_06_25_B.GC_info[1] + 1U > 65535U) {
      provaGPS_BMP_06_25_B.qY = 65535U;
    }

    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 6;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.WP_info[provaGPS_BMP_06_25_B.f_l] =
        provaGPS_BMP_06_25_DW.WP_dbI[(6 * provaGPS_BMP_06_25_B.f_l + (int32_T)
        provaGPS_BMP_06_25_B.qY) - 1];
    }

    provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.GC_info[1] + 1U;
    if (provaGPS_BMP_06_25_B.GC_info[1] + 1U > 65535U) {
      provaGPS_BMP_06_25_B.qY = 65535U;
    }

    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 7;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.WP_param[provaGPS_BMP_06_25_B.f_l] =
        provaGPS_BMP_06_25_DW.WP_dbP[(6 * provaGPS_BMP_06_25_B.f_l + (int32_T)
        provaGPS_BMP_06_25_B.qY) - 1];
    }
  }

  if ((provaGPS_BMP_06_25_B.GC_info[0] == 3) && (provaGPS_BMP_06_25_B.GC_info[1]
       < 200)) {
    provaGPS_BMP_06_25_B.qY = provaGPS_BMP_06_25_B.GC_info[1] + 1U;
    if (provaGPS_BMP_06_25_B.GC_info[1] + 1U > 65535U) {
      provaGPS_BMP_06_25_B.qY = 65535U;
    }

    for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 6;
         provaGPS_BMP_06_25_B.f_l++) {
      provaGPS_BMP_06_25_B.WP_info[provaGPS_BMP_06_25_B.f_l] =
        provaGPS_BMP_06_25_DW.WP_dbI[(6 * provaGPS_BMP_06_25_B.f_l + (int32_T)
        provaGPS_BMP_06_25_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S18>/MATLAB Function' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
   *  Constant: '<S16>/onboard_control_sensor_present uint32'
   */
  provaGPS_BMP_06_25_B.onboard[0] =
    provaGPS_BMP_06_25_P.onboard_control_sensor_presentu[0];
  provaGPS_BMP_06_25_B.onboard[1] =
    provaGPS_BMP_06_25_P.onboard_control_sensor_presentu[1];
  provaGPS_BMP_06_25_B.onboard[2] =
    provaGPS_BMP_06_25_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/Constant'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor(provaGPS_BMP_06_25_P.Gain_Gain_i *
    provaGPS_BMP_06_25_P.Constant_Value_h);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' incorporates:
   *  Constant: '<S16>/load uint16'
   *  Gain: '<S16>/Gain'
   */
  provaGPS_BMP_06_25_B.LVDE[0] = provaGPS_BMP_06_25_P.loaduint16_Value;
  provaGPS_BMP_06_25_B.LVDE[1] = (uint16_T)(provaGPS_BMP_06_25_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
    provaGPS_BMP_06_25_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  provaGPS_BMP_06_25_B.qY = 10U * provaGPS_BMP_06_25_B.z;
  if (provaGPS_BMP_06_25_B.qY > 65535U) {
    provaGPS_BMP_06_25_B.qY = 65535U;
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' incorporates:
   *  Constant: '<S16>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provaGPS_BMP_06_25_B.LVDE[2] = (uint16_T)provaGPS_BMP_06_25_B.qY;
  provaGPS_BMP_06_25_B.LVDE[3] = provaGPS_BMP_06_25_B.SFunction_o11[6];
  provaGPS_BMP_06_25_B.LVDE[4] = provaGPS_BMP_06_25_B.SFunction_o11[2];
  provaGPS_BMP_06_25_B.LVDE[5] = provaGPS_BMP_06_25_P._Value;

  /* DataTypeConversion: '<S16>/Data Type Conversion4' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor
    (provaGPS_BMP_06_25_P.Constant1_Value_p[0]);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S16>/Data Type Conversion4'
   */
  provaGPS_BMP_06_25_B.LVDE[6] = (uint16_T)(provaGPS_BMP_06_25_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
    provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion4' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor
    (provaGPS_BMP_06_25_P.Constant1_Value_p[1]);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S16>/Data Type Conversion4'
   */
  provaGPS_BMP_06_25_B.LVDE[7] = (uint16_T)(provaGPS_BMP_06_25_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
    provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S16>/Gain2' incorporates:
   *  Constant: '<S16>/Constant3'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor(provaGPS_BMP_06_25_P.Gain2_Gain *
    provaGPS_BMP_06_25_P.Constant3_Value_c);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Gain: '<S16>/Gain1'
   *  Gain: '<S16>/Gain2'
   */
  provaGPS_BMP_06_25_B.B_Current = (int16_T)
    (((provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
       (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
       (uint16_T)provaGPS_BMP_06_25_B.RateTransition) *
      provaGPS_BMP_06_25_P.Gain1_Gain_f) >> 18);

  /* DataTypeConversion: '<S16>/Data Type Conversion3' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor
    (provaGPS_BMP_06_25_P.Constant2_Value_g);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion3' */
  provaGPS_BMP_06_25_B.B_Remaining = (int8_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int8_T)-(int8_T)
     (uint8_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int8_T)(uint8_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor
    (provaGPS_BMP_06_25_P.Constant_Value_c);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion = provaGPS_BMP_06_25_B.RateTransition <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-provaGPS_BMP_06_25_B.RateTransition :
    (uint32_T)provaGPS_BMP_06_25_B.RateTransition;

  /* MATLAB Function: '<S12>/Alarm set' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  rtb_H_mav[0] = provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0];
  rtb_H_mav[1] = provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1];
  if (provaGPS_BMP_06_25_P.Constant1_Value_k[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (provaGPS_BMP_06_25_P.Constant1_Value_k[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S12>/Alarm set' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Type fixed_wing Autopilot generic'
   */
  provaGPS_BMP_06_25_B.DataTypeConversion1_hk[0] =
    provaGPS_BMP_06_25_P.Typefixed_wingAutopilotgeneric_[0];
  provaGPS_BMP_06_25_B.DataTypeConversion1_hk[1] =
    provaGPS_BMP_06_25_P.Typefixed_wingAutopilotgeneric_[1];
  provaGPS_BMP_06_25_B.DataTypeConversion1_hk[2] = rtb_H_mav[0];
  provaGPS_BMP_06_25_B.DataTypeConversion1_hk[3] = rtb_H_mav[1];

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/ACC simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.ACCsimulated_Value[0];

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[0] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/ACC simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.ACCsimulated_Value[1];

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[1] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/ACC simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.ACCsimulated_Value[2];

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[2] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/p simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.psimulated_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[3] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/q simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.qsimulated_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[4] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/r simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.rsimulated_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[5] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.Constant_Value_n;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[6] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.Constant1_Value_nf;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[7] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_e *
    provaGPS_BMP_06_25_P.Constant2_Value_j;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_c[8] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/p simulated'
   *  Constant: '<S13>/phi simulated'
   *  Constant: '<S13>/psi simulated'
   *  Constant: '<S13>/q simulated'
   *  Constant: '<S13>/r simulated'
   *  Constant: '<S13>/theta simulated'
   */
  provaGPS_BMP_06_25_B.DataTypeConversion1[0] = (real32_T)
    provaGPS_BMP_06_25_P.phisimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion1[1] = (real32_T)
    provaGPS_BMP_06_25_P.thetasimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion1[2] = (real32_T)
    provaGPS_BMP_06_25_P.psisimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion1[3] = (real32_T)
    provaGPS_BMP_06_25_P.psimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion1[4] = (real32_T)
    provaGPS_BMP_06_25_P.qsimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion1[5] = (real32_T)
    provaGPS_BMP_06_25_P.rsimulated_Value;

  /* MATLABSystem: '<Root>/Serial Receive1' */
  if (provaGPS_BMP_06_25_DW.obj_l.Protocol !=
      provaGPS_BMP_06_25_P.SerialReceive1_Protocol) {
    provaGPS_BMP_06_25_DW.obj_l.Protocol =
      provaGPS_BMP_06_25_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, provaGPS_BMP_06_25_DW.obj_l.DataSizeInBytes,
                 &provaGPS_BMP_06_25_B.b_dataOut[0], &counter);

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem2' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (counter > 0) {
    /* MATLAB Function: '<S5>/Create_message' */
    counter = 0U;
    if (!provaGPS_BMP_06_25_DW.start_found) {
      provaGPS_BMP_06_25_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (provaGPS_BMP_06_25_B.i - 1 < 32)) {
        if (provaGPS_BMP_06_25_B.b_dataOut[(uint8_T)provaGPS_BMP_06_25_B.i - 1] ==
            36) {
          provaGPS_BMP_06_25_B.caso = 32 - (uint8_T)provaGPS_BMP_06_25_B.i;
          for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <=
               provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
            provaGPS_BMP_06_25_DW.message[provaGPS_BMP_06_25_B.f_l] =
              provaGPS_BMP_06_25_B.b_dataOut[((uint8_T)provaGPS_BMP_06_25_B.i +
              provaGPS_BMP_06_25_B.f_l) - 1];
          }

          provaGPS_BMP_06_25_DW.counter_c = (uint8_T)(33 - (uint8_T)
            provaGPS_BMP_06_25_B.i);
          provaGPS_BMP_06_25_DW.start_found = true;
          exitg1 = true;
        } else {
          provaGPS_BMP_06_25_B.i++;
        }
      }
    } else {
      provaGPS_BMP_06_25_B.f_l = 1;
      exitg1 = false;
      while ((!exitg1) && (provaGPS_BMP_06_25_B.f_l - 1 < 32)) {
        if (provaGPS_BMP_06_25_B.b_dataOut[(uint8_T)provaGPS_BMP_06_25_B.f_l - 1]
            == 13) {
          provaGPS_BMP_06_25_DW.end_found = true;
          counter = (uint8_T)provaGPS_BMP_06_25_B.f_l;
          exitg1 = true;
        } else {
          provaGPS_BMP_06_25_B.f_l++;
        }
      }

      if (provaGPS_BMP_06_25_DW.end_found) {
        if (1 > counter) {
          provaGPS_BMP_06_25_B.caso = -1;
        } else {
          provaGPS_BMP_06_25_B.caso = counter - 1;
        }

        for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <=
             provaGPS_BMP_06_25_B.caso; provaGPS_BMP_06_25_B.f_l++) {
          provaGPS_BMP_06_25_B.i = (int32_T)(((uint32_T)provaGPS_BMP_06_25_B.f_l
            + provaGPS_BMP_06_25_DW.counter_c) + 1U);
          if ((uint32_T)provaGPS_BMP_06_25_B.i > 255U) {
            provaGPS_BMP_06_25_B.i = 255;
          }

          provaGPS_BMP_06_25_DW.message[provaGPS_BMP_06_25_B.i - 1] =
            provaGPS_BMP_06_25_B.b_dataOut[provaGPS_BMP_06_25_B.f_l];
        }

        memcpy(&provaGPS_BMP_06_25_B.messaggio_c[0],
               &provaGPS_BMP_06_25_DW.message[0], 80U * sizeof(uint8_T));
        provaGPS_BMP_06_25_DW.end_found = false;
        provaGPS_BMP_06_25_DW.counter_c = (uint8_T)(32 - counter);
        if (counter == 32) {
          provaGPS_BMP_06_25_DW.start_found = false;
          memset(&provaGPS_BMP_06_25_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          provaGPS_BMP_06_25_DW.start_found = true;
          provaGPS_BMP_06_25_B.caso = -counter;
          for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <=
               provaGPS_BMP_06_25_B.caso + 31; provaGPS_BMP_06_25_B.f_l++) {
            provaGPS_BMP_06_25_DW.message[provaGPS_BMP_06_25_B.f_l] =
              provaGPS_BMP_06_25_B.b_dataOut[counter + provaGPS_BMP_06_25_B.f_l];
          }

          provaGPS_BMP_06_25_B.f_l = counter + 48;
          if (0 <= provaGPS_BMP_06_25_B.f_l - 1) {
            memset(&provaGPS_BMP_06_25_DW.message[-counter + 32], 0,
                   ((provaGPS_BMP_06_25_B.f_l - counter) + counter) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
         *  EnablePort: '<S38>/Enable'
         */
        /* MATLAB Function: '<S38>/MATLAB Function' */
        counter = 0U;
        find_comma = 0U;

        /* Outport: '<Root>/mario' incorporates:
         *  MATLAB Function: '<S38>/MATLAB Function'
         */
        provaGPS_BMP_06_25_Y.mario = 0U;

        /* MATLAB Function: '<S38>/MATLAB Function' */
        for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 80;
             provaGPS_BMP_06_25_B.i++) {
          messaggio = (int8_T)
            provaGPS_BMP_06_25_B.messaggio_c[provaGPS_BMP_06_25_B.i];
          if (messaggio == '$') {
            provaGPS_BMP_06_25_B.f_l = (int32_T)(counter + 1U);
            if (counter + 1U > 255U) {
              provaGPS_BMP_06_25_B.f_l = 255;
            }

            counter = (uint8_T)provaGPS_BMP_06_25_B.f_l;
          }

          if (messaggio == ',') {
            provaGPS_BMP_06_25_B.f_l = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              provaGPS_BMP_06_25_B.f_l = 255;
            }

            find_comma = (uint8_T)provaGPS_BMP_06_25_B.f_l;
          }

          provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.i] = messaggio;
        }

        if ((counter == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
               provaGPS_BMP_06_25_B.f_l++) {
            provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
              (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] == '$');
          }

          provaGPS_BMP_06_25_eml_find(provaGPS_BMP_06_25_B.messaggio_m,
            &provaGPS_BMP_06_25_B.eb_data, provaGPS_BMP_06_25_B.eb_size);
          provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.eb_data;
          for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 5;
               provaGPS_BMP_06_25_B.f_l++) {
            messaggio = provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l
              + provaGPS_BMP_06_25_B.status];
            provaGPS_BMP_06_25_B.mess_type_d[provaGPS_BMP_06_25_B.f_l] =
              (messaggio == bb[provaGPS_BMP_06_25_B.f_l]);
            provaGPS_BMP_06_25_B.mess_type[provaGPS_BMP_06_25_B.f_l] = messaggio;
          }

          if (provaGPS_BMP_06_2_ifWhileCond_k(provaGPS_BMP_06_25_B.mess_type_d))
          {
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
                 provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
                (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] == ',');
            }

            provaGPS_BMP_06_25_eml_find_e(provaGPS_BMP_06_25_B.messaggio_m,
              provaGPS_BMP_06_25_B.comma_gga_data, provaGPS_BMP_06_25_B.eb_size);
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
                 provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
                (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] == '*');
            }

            provaGPS_BMP_06_25_eml_find_e(provaGPS_BMP_06_25_B.messaggio_m,
              provaGPS_BMP_06_25_B.star_data, provaGPS_BMP_06_25_B.star_size);
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
                 provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
                (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] == '$');
            }

            provaGPS_BMP_06_25_eml_find_e(provaGPS_BMP_06_25_B.messaggio_m,
              provaGPS_BMP_06_25_B.fb_data, provaGPS_BMP_06_25_B.star_size);
            provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double
              (&provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.comma_gga_data
               [2]]);
            if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[2] + 3.0 > (real_T)
                provaGPS_BMP_06_25_B.comma_gga_data[3] - 1.0) {
              provaGPS_BMP_06_25_B.caso = 0;
              provaGPS_BMP_06_25_B.f_l = 0;
            } else {
              provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.comma_gga_data[2]
                + 2;
              provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[3]
                - 1;
            }

            provaGPS_BMP_06_25_B.messaggio_size[0] = 1;
            provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
              provaGPS_BMP_06_25_B.caso;
            provaGPS_BMP_06_25_B.messaggio_size[1] = provaGPS_BMP_06_25_B.status;
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                 provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                provaGPS_BMP_06_25_B.f_l];
            }

            provaGPS_BMP_06_25_B.b_x = provaGPS_BMP_06_25_str2double_i
              (provaGPS_BMP_06_25_B.messaggio_data,
               provaGPS_BMP_06_25_B.messaggio_size);
            if (provaGPS_BMP_06_25_B.b_x.im == 0.0) {
              provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re / 60.0;
            } else if (provaGPS_BMP_06_25_B.b_x.re == 0.0) {
              provaGPS_BMP_06_25_B.num_254 = 0.0;
            } else {
              provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re / 60.0;
            }

            provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_B.Lat_1.re
              + provaGPS_BMP_06_25_B.num_254;
            provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.eb_size[0] *
              provaGPS_BMP_06_25_B.eb_size[1] - 1;
            if (0 <= provaGPS_BMP_06_25_B.caso) {
              memcpy(&provaGPS_BMP_06_25_B.tmp_data[0],
                     &provaGPS_BMP_06_25_B.comma_gga_data[0],
                     (provaGPS_BMP_06_25_B.caso + 1) * sizeof(int32_T));
            }

            if (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.tmp_data[3]]
                == 'S') {
              provaGPS_BMP_06_25_B.RateTransition =
                -provaGPS_BMP_06_25_B.RateTransition;
            }

            provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_2_str2double_i2
              (&provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.comma_gga_data
               [4]]);
            if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[4] + 4.0 > (real_T)
                provaGPS_BMP_06_25_B.comma_gga_data[5] - 1.0) {
              provaGPS_BMP_06_25_B.i = 0;
              provaGPS_BMP_06_25_B.f_l = 0;
            } else {
              provaGPS_BMP_06_25_B.i = provaGPS_BMP_06_25_B.comma_gga_data[4] +
                3;
              provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[5]
                - 1;
            }

            provaGPS_BMP_06_25_B.messaggio_size_k[0] = 1;
            provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
              provaGPS_BMP_06_25_B.i;
            provaGPS_BMP_06_25_B.messaggio_size_k[1] =
              provaGPS_BMP_06_25_B.status;
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                 provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.i +
                provaGPS_BMP_06_25_B.f_l];
            }

            provaGPS_BMP_06_25_B.b_x = provaGPS_BMP_06_25_str2double_i
              (provaGPS_BMP_06_25_B.messaggio_data,
               provaGPS_BMP_06_25_B.messaggio_size_k);
            if (provaGPS_BMP_06_25_B.b_x.im == 0.0) {
              provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re / 60.0;
            } else if (provaGPS_BMP_06_25_B.b_x.re == 0.0) {
              provaGPS_BMP_06_25_B.num_254 = 0.0;
            } else {
              provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re / 60.0;
            }

            provaGPS_BMP_06_25_B.num_254 += provaGPS_BMP_06_25_B.Lat_1.re;
            if (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.tmp_data[5]]
                == 'W') {
              provaGPS_BMP_06_25_B.num_254 = -provaGPS_BMP_06_25_B.num_254;
            }

            if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[6] + 1.0 > (real_T)
                provaGPS_BMP_06_25_B.comma_gga_data[7] - 1.0) {
              provaGPS_BMP_06_25_B.i = 0;
              provaGPS_BMP_06_25_B.f_l = 0;
            } else {
              provaGPS_BMP_06_25_B.i = provaGPS_BMP_06_25_B.comma_gga_data[6];
              provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[7]
                - 1;
            }

            provaGPS_BMP_06_25_B.messaggio_size_c[0] = 1;
            provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
              provaGPS_BMP_06_25_B.i;
            provaGPS_BMP_06_25_B.messaggio_size_c[1] =
              provaGPS_BMP_06_25_B.status;
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                 provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.i +
                provaGPS_BMP_06_25_B.f_l];
            }

            provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double_i
              (provaGPS_BMP_06_25_B.messaggio_data,
               provaGPS_BMP_06_25_B.messaggio_size_c);

            /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
            provaGPS_BMP_06_25_B.ComplextoRealImag[2] =
              provaGPS_BMP_06_25_B.Lat_1.re;
            if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[7] + 1.0 > (real_T)
                provaGPS_BMP_06_25_B.comma_gga_data[8] - 1.0) {
              provaGPS_BMP_06_25_B.caso = 0;
              provaGPS_BMP_06_25_B.f_l = 0;
            } else {
              provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.comma_gga_data[7];
              provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[8]
                - 1;
            }

            provaGPS_BMP_06_25_B.messaggio_size_b[0] = 1;
            provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
              provaGPS_BMP_06_25_B.caso;
            provaGPS_BMP_06_25_B.messaggio_size_b[1] =
              provaGPS_BMP_06_25_B.status;
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                 provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                provaGPS_BMP_06_25_B.f_l];
            }

            provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double_i
              (provaGPS_BMP_06_25_B.messaggio_data,
               provaGPS_BMP_06_25_B.messaggio_size_b);

            /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
            provaGPS_BMP_06_25_B.ComplextoRealImag[4] =
              provaGPS_BMP_06_25_B.Lat_1.re;
            if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[9] + 1.0 > (real_T)
                provaGPS_BMP_06_25_B.comma_gga_data[10] - 1.0) {
              provaGPS_BMP_06_25_B.caso = 0;
              provaGPS_BMP_06_25_B.f_l = 0;
            } else {
              provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.comma_gga_data[9];
              provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[10]
                - 1;
            }

            provaGPS_BMP_06_25_B.messaggio_size_p[0] = 1;
            provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
              provaGPS_BMP_06_25_B.caso;
            provaGPS_BMP_06_25_B.messaggio_size_p[1] =
              provaGPS_BMP_06_25_B.status;
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                 provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                provaGPS_BMP_06_25_B.f_l];
            }

            provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double_i
              (provaGPS_BMP_06_25_B.messaggio_data,
               provaGPS_BMP_06_25_B.messaggio_size_p);

            /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
            provaGPS_BMP_06_25_B.ComplextoRealImag[3] =
              provaGPS_BMP_06_25_B.Lat_1.re;
            if (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.tmp_data[10]]
                == 'W') {
              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[3] =
                -provaGPS_BMP_06_25_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
            provaGPS_BMP_06_25_B.ComplextoRealImag[5] =
              provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[5];
            provaGPS_BMP_06_25_B.ComplextoRealImag[6] =
              provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[6];
            provaGPS_BMP_06_25_B.ComplextoRealImag[7] =
              provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[7];
            provaGPS_BMP_06_25_B.ComplextoRealImag[8] =
              provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[8];
            if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 1.0 >= 0.0) {
                counter = (uint8_T)((real_T)provaGPS_BMP_06_25_B.star_data[0] +
                                    1.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[0] = provaGPS_BMP_06_25_B.messaggio[counter - 1];
            if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 2.0 >= 0.0) {
                counter = (uint8_T)((real_T)provaGPS_BMP_06_25_B.star_data[0] +
                                    2.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[1] = provaGPS_BMP_06_25_B.messaggio[counter - 1];
            if ((real_T)provaGPS_BMP_06_25_B.fb_data[0] + 1.0 > (real_T)
                provaGPS_BMP_06_25_B.star_data[0] - 1.0) {
              provaGPS_BMP_06_25_B.caso = 0;
              provaGPS_BMP_06_25_B.status = 0;
            } else {
              provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.fb_data[0];
              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.star_data[0] -
                1;
            }

            provaGPS_BMP_06_25_B.status -= provaGPS_BMP_06_25_B.caso;
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                 provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.NMEA_gga_string_data[provaGPS_BMP_06_25_B.f_l]
                = (uint8_T)
                provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                provaGPS_BMP_06_25_B.f_l];
            }

            counter = 0U;
            provaGPS_BMP_06_25_B.f_l = 0;
            while (provaGPS_BMP_06_25_B.f_l <= provaGPS_BMP_06_25_B.status - 1)
            {
              counter ^=
                provaGPS_BMP_06_25_B.NMEA_gga_string_data[provaGPS_BMP_06_25_B.f_l];
              provaGPS_BMP_06_25_B.f_l++;
            }

            if (counter != provaGPS_BMP_06_25_hex2dec(ck_ric)) {
              provaGPS_BMP_06_25_B.RateTransition =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[0];
              provaGPS_BMP_06_25_B.num_254 =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[1];

              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[2] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[2];
              provaGPS_BMP_06_25_B.ComplextoRealImag[3] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[3];
              provaGPS_BMP_06_25_B.ComplextoRealImag[4] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[4];

              /* Outport: '<Root>/mario' */
              provaGPS_BMP_06_25_Y.mario = 10U;
            }
          } else {
            for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 5;
                 provaGPS_BMP_06_25_B.f_l++) {
              provaGPS_BMP_06_25_B.mess_type_d[provaGPS_BMP_06_25_B.f_l] =
                (provaGPS_BMP_06_25_B.mess_type[provaGPS_BMP_06_25_B.f_l] ==
                 cb[provaGPS_BMP_06_25_B.f_l]);
            }

            if (provaGPS_BMP_06_2_ifWhileCond_k(provaGPS_BMP_06_25_B.mess_type_d))
            {
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
                   provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
                  (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] ==
                   ',');
              }

              provaGPS_BMP_06_25_eml_find_e(provaGPS_BMP_06_25_B.messaggio_m,
                provaGPS_BMP_06_25_B.comma_gga_data,
                provaGPS_BMP_06_25_B.eb_size);
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
                   provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
                  (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] ==
                   '*');
              }

              provaGPS_BMP_06_25_eml_find_e(provaGPS_BMP_06_25_B.messaggio_m,
                provaGPS_BMP_06_25_B.star_data, provaGPS_BMP_06_25_B.star_size);
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l < 80;
                   provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_m[provaGPS_BMP_06_25_B.f_l] =
                  (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.f_l] ==
                   '$');
              }

              provaGPS_BMP_06_25_eml_find_e(provaGPS_BMP_06_25_B.messaggio_m,
                provaGPS_BMP_06_25_B.fb_data, provaGPS_BMP_06_25_B.star_size);
              provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double
                (&provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.comma_gga_data
                 [1]]);
              if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[1] + 3.0 > (real_T)
                  provaGPS_BMP_06_25_B.comma_gga_data[2] - 1.0) {
                provaGPS_BMP_06_25_B.caso = 0;
                provaGPS_BMP_06_25_B.f_l = 0;
              } else {
                provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.comma_gga_data
                  [1] + 2;
                provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[2]
                  - 1;
              }

              provaGPS_BMP_06_25_B.messaggio_size[0] = 1;
              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
                provaGPS_BMP_06_25_B.caso;
              provaGPS_BMP_06_25_B.messaggio_size[1] =
                provaGPS_BMP_06_25_B.status;
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                   provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                  provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                  provaGPS_BMP_06_25_B.f_l];
              }

              provaGPS_BMP_06_25_B.b_x = provaGPS_BMP_06_25_str2double_i
                (provaGPS_BMP_06_25_B.messaggio_data,
                 provaGPS_BMP_06_25_B.messaggio_size);
              if (provaGPS_BMP_06_25_B.b_x.im == 0.0) {
                provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re /
                  60.0;
              } else if (provaGPS_BMP_06_25_B.b_x.re == 0.0) {
                provaGPS_BMP_06_25_B.num_254 = 0.0;
              } else {
                provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re /
                  60.0;
              }

              provaGPS_BMP_06_25_B.RateTransition =
                provaGPS_BMP_06_25_B.Lat_1.re + provaGPS_BMP_06_25_B.num_254;
              provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.eb_size[0] *
                provaGPS_BMP_06_25_B.eb_size[1] - 1;
              if (0 <= provaGPS_BMP_06_25_B.caso) {
                memcpy(&provaGPS_BMP_06_25_B.tmp_data[0],
                       &provaGPS_BMP_06_25_B.comma_gga_data[0],
                       (provaGPS_BMP_06_25_B.caso + 1) * sizeof(int32_T));
              }

              if (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.tmp_data[2]]
                  == 'S') {
                provaGPS_BMP_06_25_B.RateTransition =
                  -provaGPS_BMP_06_25_B.RateTransition;
              }

              provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_2_str2double_i2
                (&provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.comma_gga_data
                 [3]]);
              if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[3] + 4.0 > (real_T)
                  provaGPS_BMP_06_25_B.comma_gga_data[4] - 1.0) {
                provaGPS_BMP_06_25_B.i = 0;
                provaGPS_BMP_06_25_B.f_l = 0;
              } else {
                provaGPS_BMP_06_25_B.i = provaGPS_BMP_06_25_B.comma_gga_data[3]
                  + 3;
                provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[4]
                  - 1;
              }

              provaGPS_BMP_06_25_B.messaggio_size_k[0] = 1;
              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
                provaGPS_BMP_06_25_B.i;
              provaGPS_BMP_06_25_B.messaggio_size_k[1] =
                provaGPS_BMP_06_25_B.status;
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                   provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                  provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.i +
                  provaGPS_BMP_06_25_B.f_l];
              }

              provaGPS_BMP_06_25_B.b_x = provaGPS_BMP_06_25_str2double_i
                (provaGPS_BMP_06_25_B.messaggio_data,
                 provaGPS_BMP_06_25_B.messaggio_size_k);
              if (provaGPS_BMP_06_25_B.b_x.im == 0.0) {
                provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re /
                  60.0;
              } else if (provaGPS_BMP_06_25_B.b_x.re == 0.0) {
                provaGPS_BMP_06_25_B.num_254 = 0.0;
              } else {
                provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.b_x.re /
                  60.0;
              }

              provaGPS_BMP_06_25_B.num_254 += provaGPS_BMP_06_25_B.Lat_1.re;
              if (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.tmp_data[4]]
                  == 'W') {
                provaGPS_BMP_06_25_B.num_254 = -provaGPS_BMP_06_25_B.num_254;
              }

              provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06__str2double_i2v
                (provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.comma_gga_data
                 [5]]);

              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[5] =
                provaGPS_BMP_06_25_B.Lat_1.re;
              if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[6] + 1.0 > (real_T)
                  provaGPS_BMP_06_25_B.comma_gga_data[7] - 1.0) {
                provaGPS_BMP_06_25_B.caso = 0;
                provaGPS_BMP_06_25_B.f_l = 0;
              } else {
                provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.comma_gga_data
                  [6];
                provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[7]
                  - 1;
              }

              provaGPS_BMP_06_25_B.messaggio_size_c[0] = 1;
              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
                provaGPS_BMP_06_25_B.caso;
              provaGPS_BMP_06_25_B.messaggio_size_c[1] =
                provaGPS_BMP_06_25_B.status;
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                   provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                  provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                  provaGPS_BMP_06_25_B.f_l];
              }

              provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double_i
                (provaGPS_BMP_06_25_B.messaggio_data,
                 provaGPS_BMP_06_25_B.messaggio_size_c);

              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[6] =
                provaGPS_BMP_06_25_B.Lat_1.re;
              if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[8] + 1.0 > (real_T)
                  provaGPS_BMP_06_25_B.comma_gga_data[9] - 1.0) {
                provaGPS_BMP_06_25_B.i = 0;
                provaGPS_BMP_06_25_B.f_l = 0;
              } else {
                provaGPS_BMP_06_25_B.i = provaGPS_BMP_06_25_B.comma_gga_data[8];
                provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.comma_gga_data[9]
                  - 1;
              }

              provaGPS_BMP_06_25_B.messaggio_size_b[0] = 1;
              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
                provaGPS_BMP_06_25_B.i;
              provaGPS_BMP_06_25_B.messaggio_size_b[1] =
                provaGPS_BMP_06_25_B.status;
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                   provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                  provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.i +
                  provaGPS_BMP_06_25_B.f_l];
              }

              provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double_i
                (provaGPS_BMP_06_25_B.messaggio_data,
                 provaGPS_BMP_06_25_B.messaggio_size_b);

              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[7] =
                provaGPS_BMP_06_25_B.Lat_1.re;
              if ((real_T)provaGPS_BMP_06_25_B.comma_gga_data[10] + 1.0 >
                  (real_T)provaGPS_BMP_06_25_B.comma_gga_data[11] - 1.0) {
                provaGPS_BMP_06_25_B.x_d = 0;
                provaGPS_BMP_06_25_B.caso = 0;
              } else {
                provaGPS_BMP_06_25_B.x_d = provaGPS_BMP_06_25_B.comma_gga_data
                  [10];
                provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.comma_gga_data
                  [11] - 1;
              }

              provaGPS_BMP_06_25_B.messaggio_size_p[0] = 1;
              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.caso -
                provaGPS_BMP_06_25_B.x_d;
              provaGPS_BMP_06_25_B.messaggio_size_p[1] =
                provaGPS_BMP_06_25_B.status;
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                   provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.messaggio_data[provaGPS_BMP_06_25_B.f_l] =
                  provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.x_d +
                  provaGPS_BMP_06_25_B.f_l];
              }

              provaGPS_BMP_06_25_B.Lat_1 = provaGPS_BMP_06_25_str2double_i
                (provaGPS_BMP_06_25_B.messaggio_data,
                 provaGPS_BMP_06_25_B.messaggio_size_p);

              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[8] =
                provaGPS_BMP_06_25_B.Lat_1.re;
              provaGPS_BMP_06_25_B.ComplextoRealImag[2] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[2];
              provaGPS_BMP_06_25_B.ComplextoRealImag[3] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[3];
              provaGPS_BMP_06_25_B.ComplextoRealImag[4] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[4];
              if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 1.0 >= 0.0) {
                  counter = (uint8_T)((real_T)provaGPS_BMP_06_25_B.star_data[0]
                                      + 1.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[0] = provaGPS_BMP_06_25_B.messaggio[counter - 1];
              if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)provaGPS_BMP_06_25_B.star_data[0] + 2.0 >= 0.0) {
                  counter = (uint8_T)((real_T)provaGPS_BMP_06_25_B.star_data[0]
                                      + 2.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[1] = provaGPS_BMP_06_25_B.messaggio[counter - 1];
              if ((real_T)provaGPS_BMP_06_25_B.fb_data[0] + 1.0 > (real_T)
                  provaGPS_BMP_06_25_B.star_data[0] - 1.0) {
                provaGPS_BMP_06_25_B.caso = 0;
                provaGPS_BMP_06_25_B.f_l = 0;
              } else {
                provaGPS_BMP_06_25_B.caso = provaGPS_BMP_06_25_B.fb_data[0];
                provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_B.star_data[0] - 1;
              }

              provaGPS_BMP_06_25_B.status = provaGPS_BMP_06_25_B.f_l -
                provaGPS_BMP_06_25_B.caso;
              for (provaGPS_BMP_06_25_B.f_l = 0; provaGPS_BMP_06_25_B.f_l <
                   provaGPS_BMP_06_25_B.status; provaGPS_BMP_06_25_B.f_l++) {
                provaGPS_BMP_06_25_B.NMEA_gga_string_data[provaGPS_BMP_06_25_B.f_l]
                  = (uint8_T)
                  provaGPS_BMP_06_25_B.messaggio[provaGPS_BMP_06_25_B.caso +
                  provaGPS_BMP_06_25_B.f_l];
              }

              counter = 0U;
              provaGPS_BMP_06_25_B.f_l = 0;
              while (provaGPS_BMP_06_25_B.f_l <= provaGPS_BMP_06_25_B.status - 1)
              {
                counter ^=
                  provaGPS_BMP_06_25_B.NMEA_gga_string_data[provaGPS_BMP_06_25_B.f_l];
                provaGPS_BMP_06_25_B.f_l++;
              }

              if (counter != provaGPS_BMP_06_25_hex2dec(ck_ric)) {
                provaGPS_BMP_06_25_B.RateTransition =
                  provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[0];
                provaGPS_BMP_06_25_B.num_254 =
                  provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[1];

                /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
                provaGPS_BMP_06_25_B.ComplextoRealImag[5] =
                  provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[5];
                provaGPS_BMP_06_25_B.ComplextoRealImag[6] =
                  provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[6];
                provaGPS_BMP_06_25_B.ComplextoRealImag[7] =
                  provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[7];
                provaGPS_BMP_06_25_B.ComplextoRealImag[8] =
                  provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[8];

                /* Outport: '<Root>/mario' */
                provaGPS_BMP_06_25_Y.mario = 20U;
              }
            } else {
              provaGPS_BMP_06_25_B.RateTransition =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[0];
              provaGPS_BMP_06_25_B.num_254 =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[1];

              /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
              provaGPS_BMP_06_25_B.ComplextoRealImag[2] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[2];
              provaGPS_BMP_06_25_B.ComplextoRealImag[3] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[3];
              provaGPS_BMP_06_25_B.ComplextoRealImag[4] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[4];
              provaGPS_BMP_06_25_B.ComplextoRealImag[5] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[5];
              provaGPS_BMP_06_25_B.ComplextoRealImag[6] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[6];
              provaGPS_BMP_06_25_B.ComplextoRealImag[7] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[7];
              provaGPS_BMP_06_25_B.ComplextoRealImag[8] =
                provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[8];
            }
          }
        } else {
          provaGPS_BMP_06_25_B.RateTransition =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[0];
          provaGPS_BMP_06_25_B.num_254 =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[1];

          /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
          provaGPS_BMP_06_25_B.ComplextoRealImag[2] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[2];
          provaGPS_BMP_06_25_B.ComplextoRealImag[3] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[3];
          provaGPS_BMP_06_25_B.ComplextoRealImag[4] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[4];
          provaGPS_BMP_06_25_B.ComplextoRealImag[5] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[5];
          provaGPS_BMP_06_25_B.ComplextoRealImag[6] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[6];
          provaGPS_BMP_06_25_B.ComplextoRealImag[7] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[7];
          provaGPS_BMP_06_25_B.ComplextoRealImag[8] =
            provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[8];
        }

        /* ComplexToRealImag: '<S38>/Complex to Real-Imag' */
        provaGPS_BMP_06_25_B.ComplextoRealImag[0] =
          provaGPS_BMP_06_25_B.RateTransition;
        provaGPS_BMP_06_25_B.ComplextoRealImag[1] = provaGPS_BMP_06_25_B.num_254;

        /* Update for Memory: '<S38>/Memory' */
        memcpy(&provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[0],
               &provaGPS_BMP_06_25_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S5>/Subsystem' */
      } else {
        for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 32;
             provaGPS_BMP_06_25_B.i++) {
          provaGPS_BMP_06_25_B.f_l = (int32_T)(((uint32_T)
            provaGPS_BMP_06_25_DW.counter_c + provaGPS_BMP_06_25_B.i) + 1U);
          if ((uint32_T)provaGPS_BMP_06_25_B.f_l > 255U) {
            provaGPS_BMP_06_25_B.f_l = 255;
          }

          provaGPS_BMP_06_25_DW.message[provaGPS_BMP_06_25_B.f_l - 1] =
            provaGPS_BMP_06_25_B.b_dataOut[provaGPS_BMP_06_25_B.i];
        }

        provaGPS_BMP_06_25_B.f_l = (int32_T)(provaGPS_BMP_06_25_DW.counter_c +
          32U);
        if (provaGPS_BMP_06_25_DW.counter_c + 32U > 255U) {
          provaGPS_BMP_06_25_B.f_l = 255;
        }

        provaGPS_BMP_06_25_DW.counter_c = (uint8_T)provaGPS_BMP_06_25_B.f_l;
      }
    }

    /* End of MATLAB Function: '<S5>/Create_message' */
  }

  /* End of MATLABSystem: '<Root>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (provaGPS_BMP_06_25_B.SFunction_o14 > 0) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant3'
     *  Logic: '<S4>/OR'
     *  RelationalOperator: '<S4>/Equal'
     *  RelationalOperator: '<S4>/Equal1'
     *  RelationalOperator: '<S4>/Equal2'
     */
    if ((provaGPS_BMP_06_25_B.ComplextoRealImag[5] ==
         provaGPS_BMP_06_25_P.Constant_Value) ||
        (provaGPS_BMP_06_25_B.ComplextoRealImag[5] ==
         provaGPS_BMP_06_25_P.Constant1_Value_g) ||
        (provaGPS_BMP_06_25_B.ComplextoRealImag[5] ==
         provaGPS_BMP_06_25_P.Constant3_Value_d)) {
      /* Switch: '<S4>/Switch' */
      provaGPS_BMP_06_25_B.Switch = provaGPS_BMP_06_25_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Constant2'
       */
      provaGPS_BMP_06_25_B.Switch = provaGPS_BMP_06_25_P.Constant2_Value_i;
    }

    /* End of Switch: '<S4>/Switch' */
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* Gain: '<S11>/Gain' */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_h[0] *
    provaGPS_BMP_06_25_B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_n[0] =
    provaGPS_BMP_06_25_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint32_T)
    provaGPS_BMP_06_25_B.RateTransition;

  /* Gain: '<S11>/Gain' */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_h[1] *
    provaGPS_BMP_06_25_B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_n[1] =
    provaGPS_BMP_06_25_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint32_T)
    provaGPS_BMP_06_25_B.RateTransition;

  /* Gain: '<S11>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  provaGPS_BMP_06_25_B.RateTransition = (provaGPS_BMP_06_25_B.ComplextoRealImag
    [7] - provaGPS_BMP_06_25_B.Switch) * provaGPS_BMP_06_25_P.Gain_Gain_h[2];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_n[2] =
    provaGPS_BMP_06_25_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint32_T)
    provaGPS_BMP_06_25_B.RateTransition;

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/alt_r'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain_Gain_h[3] *
    provaGPS_BMP_06_25_P.alt_r_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  provaGPS_BMP_06_25_B.DataTypeConversion_n[3] =
    provaGPS_BMP_06_25_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
    -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint32_T)
    provaGPS_BMP_06_25_B.RateTransition;

  /* Gain: '<S11>/Gain1' */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain1_Gain *
    provaGPS_BMP_06_25_B.ComplextoRealImag[2];

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.DataTypeConversion1_h[0] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S11>/Gain1' incorporates:
   *  Constant: '<S11>/vel y'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain1_Gain *
    provaGPS_BMP_06_25_P.vely_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.DataTypeConversion1_h[1] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S11>/Gain1' incorporates:
   *  Constant: '<S11>/RC Simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain1_Gain *
    provaGPS_BMP_06_25_P.RCSimulated_Value;

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.DataTypeConversion1_h[2] = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S11>/Gain2' */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_P.Gain2_Gain_k *
    provaGPS_BMP_06_25_B.ComplextoRealImag[4];

  /* DataTypeConversion: '<S11>/Data Type Conversion2' */
  if (provaGPS_BMP_06_25_B.RateTransition < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.RateTransition);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.RateTransition);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion2' */
  provaGPS_BMP_06_25_B.DataTypeConversion2 = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* SignalConversion generated from: '<S33>/Enable' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !provaGPS_BMP_06_25_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  pro_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &provaGPS_BMP_06_25_B.One_time_initialization,
    &provaGPS_BMP_06_25_DW.One_time_initialization,
    &provaGPS_BMP_06_25_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (provaGPS_BMP_06_25_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S30>/I2C Read12' */
    if (provaGPS_BMP_06_25_DW.obj_d.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      provaGPS_BMP_06_25_DW.obj_d.SampleTime = provaGPS_BMP_06_25_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (provaGPS_BMP_06_25_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter,
       1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(provaGPS_BMP_06_25_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S30>/I2C Read1' */
    if (provaGPS_BMP_06_25_DW.obj_i.SampleTime != provaGPS_BMP_06_25_P.t_AP) {
      provaGPS_BMP_06_25_DW.obj_i.SampleTime = provaGPS_BMP_06_25_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (provaGPS_BMP_06_25_DW.obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter,
       1U, true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(provaGPS_BMP_06_25_DW.obj_i.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &provaGPS_BMP_06_25_B.output_raw[0], 3U, false,
                        true);
      memcpy((void *)&provaGPS_BMP_06_25_B.output[0], (void *)
             &provaGPS_BMP_06_25_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
              (uint8_T)));
    } else {
      provaGPS_BMP_06_25_B.output[0] = 0U;
      provaGPS_BMP_06_25_B.output[1] = 0U;
      provaGPS_BMP_06_25_B.output[2] = 0U;
    }

    /* ArithShift: '<S30>/Shift Arithmetic4' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_P.Constant1_Value);
    if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
        (provaGPS_BMP_06_25_B.RateTransition)) {
      provaGPS_BMP_06_25_B.RateTransition = 0.0;
    } else {
      provaGPS_BMP_06_25_B.RateTransition = fmod
        (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic3' incorporates:
     *  Constant: '<S30>/Constant5'
     */
    provaGPS_BMP_06_25_B.num_254 = floor(provaGPS_BMP_06_25_P.Constant5_Value);
    if (rtIsNaN(provaGPS_BMP_06_25_B.num_254) || rtIsInf
        (provaGPS_BMP_06_25_B.num_254)) {
      provaGPS_BMP_06_25_B.num_254 = 0.0;
    } else {
      provaGPS_BMP_06_25_B.num_254 = fmod(provaGPS_BMP_06_25_B.num_254,
        4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic1' incorporates:
     *  Constant: '<S30>/Constant6'
     */
    provaGPS_BMP_06_25_B.deltafalllimit = floor
      (provaGPS_BMP_06_25_P.Constant6_Value);
    if (rtIsNaN(provaGPS_BMP_06_25_B.deltafalllimit) || rtIsInf
        (provaGPS_BMP_06_25_B.deltafalllimit)) {
      provaGPS_BMP_06_25_B.deltafalllimit = 0.0;
    } else {
      provaGPS_BMP_06_25_B.deltafalllimit = fmod
        (provaGPS_BMP_06_25_B.deltafalllimit, 4.294967296E+9);
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
    provaGPS_BMP_06_25_B.DataTypeConversion1_l = (int32_T)
      ((((((provaGPS_BMP_06_25_P.Constant7_Value + provaGPS_BMP_06_25_B.output[0])
           << (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
               -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint32_T)
               provaGPS_BMP_06_25_B.RateTransition)) +
          ((provaGPS_BMP_06_25_P.Constant10_Value_i +
            provaGPS_BMP_06_25_B.output[1]) << (provaGPS_BMP_06_25_B.num_254 <
            0.0 ? -(int32_T)(uint32_T)-provaGPS_BMP_06_25_B.num_254 : (int32_T)
            (uint32_T)provaGPS_BMP_06_25_B.num_254))) +
         provaGPS_BMP_06_25_P.Constant11_Value) + provaGPS_BMP_06_25_B.output[2])
       >> (provaGPS_BMP_06_25_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
           -provaGPS_BMP_06_25_B.deltafalllimit : (int32_T)(uint32_T)
           provaGPS_BMP_06_25_B.deltafalllimit));

    /* ArithShift: '<S30>/Shift Arithmetic7' incorporates:
     *  Constant: '<S30>/Constant2'
     */
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_P.Constant2_Value);
    if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
        (provaGPS_BMP_06_25_B.RateTransition)) {
      provaGPS_BMP_06_25_B.RateTransition = 0.0;
    } else {
      provaGPS_BMP_06_25_B.RateTransition = fmod
        (provaGPS_BMP_06_25_B.RateTransition, 4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic6' incorporates:
     *  Constant: '<S30>/Constant3'
     */
    provaGPS_BMP_06_25_B.num_254 = floor(provaGPS_BMP_06_25_P.Constant3_Value);
    if (rtIsNaN(provaGPS_BMP_06_25_B.num_254) || rtIsInf
        (provaGPS_BMP_06_25_B.num_254)) {
      provaGPS_BMP_06_25_B.num_254 = 0.0;
    } else {
      provaGPS_BMP_06_25_B.num_254 = fmod(provaGPS_BMP_06_25_B.num_254,
        4.294967296E+9);
    }

    /* ArithShift: '<S30>/Shift Arithmetic2' incorporates:
     *  Constant: '<S30>/Constant4'
     */
    provaGPS_BMP_06_25_B.deltafalllimit = floor
      (provaGPS_BMP_06_25_P.Constant4_Value);
    if (rtIsNaN(provaGPS_BMP_06_25_B.deltafalllimit) || rtIsInf
        (provaGPS_BMP_06_25_B.deltafalllimit)) {
      provaGPS_BMP_06_25_B.deltafalllimit = 0.0;
    } else {
      provaGPS_BMP_06_25_B.deltafalllimit = fmod
        (provaGPS_BMP_06_25_B.deltafalllimit, 4.294967296E+9);
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
    provaGPS_BMP_06_25_B.DataTypeConversion_p = (int32_T)
      ((((provaGPS_BMP_06_25_P.Constant8_Value + rtb_H_mav[0]) <<
         (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint32_T)
          provaGPS_BMP_06_25_B.RateTransition)) +
        ((provaGPS_BMP_06_25_P.Constant9_Value + rtb_H_mav[1]) <<
         (provaGPS_BMP_06_25_B.num_254 < 0.0 ? -(int32_T)(uint32_T)
          -provaGPS_BMP_06_25_B.num_254 : (int32_T)(uint32_T)
          provaGPS_BMP_06_25_B.num_254))) >>
       (provaGPS_BMP_06_25_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -provaGPS_BMP_06_25_B.deltafalllimit : (int32_T)(uint32_T)
        provaGPS_BMP_06_25_B.deltafalllimit));

    /* S-Function (calc_T): '<S30>/S-Function Builder' */
    calc_T_Outputs_wrapper(&provaGPS_BMP_06_25_B.One_time_initialization.I2CRead,
      &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead1,
      &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead2,
      &provaGPS_BMP_06_25_B.DataTypeConversion_p,
      &provaGPS_BMP_06_25_B.SFunctionBuilder_o1,
      &provaGPS_BMP_06_25_B.SFunctionBuilder_o2_i);

    /* S-Function (calc_p): '<S30>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&provaGPS_BMP_06_25_B.One_time_initialization.I2CRead3,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead4,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead5,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead6,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead7,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead8,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead9,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead10,
       &provaGPS_BMP_06_25_B.One_time_initialization.I2CRead11,
       &provaGPS_BMP_06_25_B.DataTypeConversion1_l,
       &provaGPS_BMP_06_25_B.SFunctionBuilder_o2_i,
       &provaGPS_BMP_06_25_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (provaGPS_BMP_06_25_P.Constant2_Value_e == 1.0) {
    provaGPS_BMP_06_25_DW.P_ref = provaGPS_BMP_06_25_B.SFunctionBuilder1;
  }

  if (provaGPS_BMP_06_25_P.Constant_Value_a == 1.0) {
    provaGPS_BMP_06_25_DW.P_ref = provaGPS_BMP_06_25_P.Constant1_Value_kc;
    provaGPS_BMP_06_25_DW.rl_up = 20.0;
    provaGPS_BMP_06_25_DW.rl_dw = -20.0;
  }

  /* Product: '<S29>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S29>/sample time'
   *
   * About '<S29>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provaGPS_BMP_06_25_B.RateTransition = provaGPS_BMP_06_25_DW.rl_up *
    provaGPS_BMP_06_25_P.sampletime_WtEt;

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
  provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_DW.P_ref -
    provaGPS_BMP_06_25_DW.DelayInput2_DSTATE;

  /* Product: '<S29>/delta fall limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S29>/sample time'
   *
   * About '<S29>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provaGPS_BMP_06_25_B.deltafalllimit = provaGPS_BMP_06_25_DW.rl_dw *
    provaGPS_BMP_06_25_P.sampletime_WtEt;

  /* Switch: '<S35>/Switch2' incorporates:
   *  RelationalOperator: '<S35>/LowerRelop1'
   *  RelationalOperator: '<S35>/UpperRelop'
   *  Switch: '<S35>/Switch'
   */
  if (provaGPS_BMP_06_25_B.num_254 > provaGPS_BMP_06_25_B.RateTransition) {
    provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.RateTransition;
  } else {
    if (provaGPS_BMP_06_25_B.num_254 < provaGPS_BMP_06_25_B.deltafalllimit) {
      /* Switch: '<S35>/Switch' */
      provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_B.deltafalllimit;
    }
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
  provaGPS_BMP_06_25_DW.DelayInput2_DSTATE += provaGPS_BMP_06_25_B.num_254;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S29>/Delay Input2'
   *
   * Block description for '<S29>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaGPS_BMP_06_25_B.DataTypeConversion3_m = (real32_T)
    provaGPS_BMP_06_25_DW.DelayInput2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S34>/Subsystem1' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (provaGPS_BMP_06_25_P.Constant2_Value_e > 0.0) {
    /* Inport: '<S36>/T' */
    provaGPS_BMP_06_25_B.T = provaGPS_BMP_06_25_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S34>/Subsystem1' */

  /* DataTypeConversion: '<S17>/Data Type Conversion3' incorporates:
   *  Constant: '<S17>/RC simulated'
   *  Constant: '<S17>/TAS simulated'
   *  Constant: '<S17>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  MATLAB Function: '<S3>/MATLAB Function1'
   */
  provaGPS_BMP_06_25_B.DataTypeConversion3_p[0] = (real32_T)
    provaGPS_BMP_06_25_P.TASsimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion3_p[1] = (real32_T)
    provaGPS_BMP_06_25_P.vsimulated_Value;
  provaGPS_BMP_06_25_B.DataTypeConversion3_p[2] = (real32_T)log((real32_T)
    provaGPS_BMP_06_25_B.SFunctionBuilder1 /
    provaGPS_BMP_06_25_B.DataTypeConversion3_m) * -8333.33301F;
  provaGPS_BMP_06_25_B.DataTypeConversion3_p[3] = (real32_T)
    provaGPS_BMP_06_25_P.RCsimulated_Value;

  /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
   *  Constant: '<S17>/ Heading simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor
    (provaGPS_BMP_06_25_P.Headingsimulated_Value);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion4' */
  provaGPS_BMP_06_25_B.DataTypeConversion4_h = (int16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(int16_T)
     (uint16_T)provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion5' incorporates:
   *  Constant: '<S17>/Rpm simulated'
   */
  provaGPS_BMP_06_25_B.RateTransition = floor
    (provaGPS_BMP_06_25_P.Rpmsimulated_Value);
  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion5' */
  provaGPS_BMP_06_25_B.DataTypeConversion5 = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* Gain: '<S24>/Gain2' incorporates:
   *  Constant: '<S15>/Manetta Simulated'
   */
  provaGPS_BMP_06_25_B.num_254 = provaGPS_BMP_06_25_P.Gain2_Gain_f *
    provaGPS_BMP_06_25_P.ManettaSimulated_Value;

  /* Sum: '<S24>/Sum' incorporates:
   *  Constant: '<S15>/Equilibratore Simulated'
   *  Constant: '<S24>/Constant2'
   *  Gain: '<S25>/Gain'
   */
  provaGPS_BMP_06_25_B.deltafalllimit = provaGPS_BMP_06_25_P.Gain_Gain_c *
    provaGPS_BMP_06_25_P.EquilibratoreSimulated_Value +
    provaGPS_BMP_06_25_P.Constant2_Value_gt;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Constant: '<S15>/Alettoni Simulated'
   *  Constant: '<S24>/Constant2'
   *  Gain: '<S26>/Gain'
   */
  provaGPS_BMP_06_25_B.Sum1 = provaGPS_BMP_06_25_P.Gain_Gain_h4 *
    provaGPS_BMP_06_25_P.AlettoniSimulated_Value +
    provaGPS_BMP_06_25_P.Constant2_Value_gt;

  /* Sum: '<S24>/Sum2' incorporates:
   *  Constant: '<S15>/Timone Simulated'
   *  Constant: '<S24>/Constant2'
   *  Gain: '<S27>/Gain'
   */
  provaGPS_BMP_06_25_B.Sum2 = provaGPS_BMP_06_25_P.Gain_Gain_m *
    provaGPS_BMP_06_25_P.TimoneSimulated_Value +
    provaGPS_BMP_06_25_P.Constant2_Value_gt;

  /* Gain: '<S15>/Gain' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  provaGPS_BMP_06_25_B.PatohPa1 = provaGPS_BMP_06_25_P.Gain_Gain_l *
    provaGPS_BMP_06_25_P.Constant2_Value_h;

  /* Saturate: '<S15>/Saturation' */
  if (provaGPS_BMP_06_25_B.PatohPa1 > provaGPS_BMP_06_25_P.Saturation_UpperSat)
  {
    provaGPS_BMP_06_25_B.PatohPa1 = provaGPS_BMP_06_25_P.Saturation_UpperSat;
  } else {
    if (provaGPS_BMP_06_25_B.PatohPa1 < provaGPS_BMP_06_25_P.Saturation_LowerSat)
    {
      provaGPS_BMP_06_25_B.PatohPa1 = provaGPS_BMP_06_25_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  if (provaGPS_BMP_06_25_P.Constant_Value_p < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_P.Constant_Value_p);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_P.Constant_Value_p);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[0] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.num_254 < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil(provaGPS_BMP_06_25_B.num_254);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor(provaGPS_BMP_06_25_B.num_254);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[1] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.deltafalllimit < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_B.deltafalllimit);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_B.deltafalllimit);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[2] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.Sum1 < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil(provaGPS_BMP_06_25_B.Sum1);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor(provaGPS_BMP_06_25_B.Sum1);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[3] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.Sum2 < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil(provaGPS_BMP_06_25_B.Sum2);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor(provaGPS_BMP_06_25_B.Sum2);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[4] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  if (provaGPS_BMP_06_25_P.Constant1_Value_c[0] < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_P.Constant1_Value_c[0]);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_P.Constant1_Value_c[0]);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[5] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  if (provaGPS_BMP_06_25_P.Constant1_Value_c[1] < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_P.Constant1_Value_c[1]);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_P.Constant1_Value_c[1]);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[6] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  if (provaGPS_BMP_06_25_P.Constant1_Value_c[2] < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil
      (provaGPS_BMP_06_25_P.Constant1_Value_c[2]);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor
      (provaGPS_BMP_06_25_P.Constant1_Value_c[2]);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[7] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  if (provaGPS_BMP_06_25_B.PatohPa1 < 0.0) {
    provaGPS_BMP_06_25_B.RateTransition = ceil(provaGPS_BMP_06_25_B.PatohPa1);
  } else {
    provaGPS_BMP_06_25_B.RateTransition = floor(provaGPS_BMP_06_25_B.PatohPa1);
  }

  if (rtIsNaN(provaGPS_BMP_06_25_B.RateTransition) || rtIsInf
      (provaGPS_BMP_06_25_B.RateTransition)) {
    provaGPS_BMP_06_25_B.RateTransition = 0.0;
  } else {
    provaGPS_BMP_06_25_B.RateTransition = fmod
      (provaGPS_BMP_06_25_B.RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  provaGPS_BMP_06_25_B.Heading[8] = (uint16_T)
    (provaGPS_BMP_06_25_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaGPS_BMP_06_25_B.RateTransition : (int32_T)(uint16_T)
     provaGPS_BMP_06_25_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  provaGPS_BMP_06_25_B.Memory_n = provaGPS_BMP_06_25_DW.Memory_PreviousInput_f;

  /* Switch: '<S34>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S34>/NotEqual'
   *  Switch: '<S34>/Switch'
   */
  if (provaGPS_BMP_06_25_P.Constant_Value_o != provaGPS_BMP_06_25_P.T_0_Value) {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    provaGPS_BMP_06_25_B.DataTypeConversion4 = (real32_T)
      provaGPS_BMP_06_25_P.T_0_Value;
  } else if (provaGPS_BMP_06_25_B.T > provaGPS_BMP_06_25_P.Switch_Threshold_c) {
    /* Switch: '<S34>/Switch' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion4'
     */
    provaGPS_BMP_06_25_B.DataTypeConversion4 = provaGPS_BMP_06_25_B.T;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    provaGPS_BMP_06_25_B.DataTypeConversion4 = (real32_T)
      provaGPS_BMP_06_25_P.T_0_Value;
  }

  /* End of Switch: '<S34>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S2>/Pa to hPa'
   */
  provaGPS_BMP_06_25_B.DataTypeConversion_g = (real32_T)
    (provaGPS_BMP_06_25_P.PatohPa_Gain * (real_T)
     provaGPS_BMP_06_25_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  provaGPS_BMP_06_25_B.DataTypeConversion1_n = (real32_T)
    (provaGPS_BMP_06_25_P.PatohPa1_Gain *
     provaGPS_BMP_06_25_P.Constant2_Value_eg);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  provaGPS_BMP_06_25_B.f = (real32_T)floor
    (provaGPS_BMP_06_25_B.SFunctionBuilder_o1);
  if (rtIsNaNF(provaGPS_BMP_06_25_B.f) || rtIsInfF(provaGPS_BMP_06_25_B.f)) {
    provaGPS_BMP_06_25_B.f = 0.0F;
  } else {
    provaGPS_BMP_06_25_B.f = (real32_T)fmod(provaGPS_BMP_06_25_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  provaGPS_BMP_06_25_B.DataTypeConversion2_d = (int16_T)(provaGPS_BMP_06_25_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaGPS_BMP_06_25_B.f :
    (int32_T)(int16_T)(uint16_T)provaGPS_BMP_06_25_B.f);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&provaGPS_BMP_06_25_B.iflogic,
    &provaGPS_BMP_06_25_B.DataTypeConversion3,
    &provaGPS_BMP_06_25_P.SIUAVuint8_Value, &provaGPS_BMP_06_25_B.GC_info[0],
    &provaGPS_BMP_06_25_B.Val_out_MAV[0], &provaGPS_BMP_06_25_B.WP_info[0],
    &provaGPS_BMP_06_25_B.WP_param[0], &provaGPS_BMP_06_25_B.onboard[0],
    &provaGPS_BMP_06_25_B.LVDE[0], &provaGPS_BMP_06_25_B.B_Current,
    &provaGPS_BMP_06_25_B.B_Remaining, &provaGPS_BMP_06_25_B.DataTypeConversion,
    &provaGPS_BMP_06_25_B.DataTypeConversion1_hk[0],
    &provaGPS_BMP_06_25_B.DataTypeConversion_c[0],
    &provaGPS_BMP_06_25_B.DataTypeConversion1[0],
    &provaGPS_BMP_06_25_B.DataTypeConversion_n[0],
    &provaGPS_BMP_06_25_B.DataTypeConversion1_h[0],
    &provaGPS_BMP_06_25_B.DataTypeConversion2,
    &provaGPS_BMP_06_25_B.DataTypeConversion3_p[0],
    &provaGPS_BMP_06_25_B.DataTypeConversion4_h,
    &provaGPS_BMP_06_25_B.DataTypeConversion5, &provaGPS_BMP_06_25_B.Heading[0],
    &provaGPS_BMP_06_25_B.Memory_n, &provaGPS_BMP_06_25_B.DataTypeConversion3_m,
    &provaGPS_BMP_06_25_B.SFunction_o14,
    &provaGPS_BMP_06_25_B.DataTypeConversion4,
    &provaGPS_BMP_06_25_B.SFunction_o15,
    &provaGPS_BMP_06_25_B.DataTypeConversion_g,
    &provaGPS_BMP_06_25_B.DataTypeConversion1_n,
    &provaGPS_BMP_06_25_B.DataTypeConversion2_d,
    &provaGPS_BMP_06_25_B.SFunction_o5[0],
    &provaGPS_BMP_06_25_P.Constant4_Value_b,
    &provaGPS_BMP_06_25_P.Constant5_Value_a,
    &provaGPS_BMP_06_25_P.Constant10_Value, ((const uint16_T*)
    &provaGPS_BMP_06_25_U16GND), &provaGPS_BMP_06_25_B.SFunction_o1_g,
    &provaGPS_BMP_06_25_B.SFunction_o2_b[0], &provaGPS_BMP_06_25_B.SFunction_o3,
    &provaGPS_BMP_06_25_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (provaGPS_BMP_06_25_B.SFunction_o1_g > 0) {
    /* Chart: '<S10>/Chart' */
    if (provaGPS_BMP_06_25_DW.is_active_c9_provaGPS_BMP_06_25 == 0U) {
      provaGPS_BMP_06_25_DW.is_active_c9_provaGPS_BMP_06_25 = 1U;
      provaGPS_BMP_06_25_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (provaGPS_BMP_06_25_DW.obj.Protocol !=
            provaGPS_BMP_06_25_P.SerialTransmit_Protocol) {
          provaGPS_BMP_06_25_DW.obj.Protocol =
            provaGPS_BMP_06_25_P.SerialTransmit_Protocol;
        }

        counter = provaGPS_BMP_06_25_B.SFunction_o2_b[provaGPS_BMP_06_25_DW.i -
          1];
        MW_Serial_write(provaGPS_BMP_06_25_DW.obj.port, &counter, 1.0,
                        provaGPS_BMP_06_25_DW.obj.dataSizeInBytes,
                        provaGPS_BMP_06_25_DW.obj.sendModeEnum,
                        provaGPS_BMP_06_25_DW.obj.dataType,
                        provaGPS_BMP_06_25_DW.obj.sendFormatEnum, 2.0, '\x00');
        if (provaGPS_BMP_06_25_DW.i < provaGPS_BMP_06_25_B.SFunction_o3) {
          provaGPS_BMP_06_25_B.f_l = provaGPS_BMP_06_25_DW.i + 1;
          if (provaGPS_BMP_06_25_DW.i + 1 > 255) {
            provaGPS_BMP_06_25_B.f_l = 255;
          }

          provaGPS_BMP_06_25_DW.i = (uint8_T)provaGPS_BMP_06_25_B.f_l;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      provaGPS_BMP_06_25_DW.i = 1U;
    }

    /* End of Chart: '<S10>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&provaGPS_BMP_06_25_DW.Memory4_PreviousInput[0],
         &provaGPS_BMP_06_25_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&provaGPS_BMP_06_25_P.Constant1_Value_h,
    &provaGPS_BMP_06_25_B.SFunctionBuilder_o1_e[0],
    &provaGPS_BMP_06_25_B.SFunctionBuilder_o2,
    &provaGPS_BMP_06_25_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&provaGPS_BMP_06_25_DW.Memory5_PreviousInput[0],
         &provaGPS_BMP_06_25_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[0] =
    provaGPS_BMP_06_25_B.DataTypeConversion1_hk[0];
  provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[1] =
    provaGPS_BMP_06_25_B.DataTypeConversion1_hk[1];
  provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[2] =
    provaGPS_BMP_06_25_B.DataTypeConversion1_hk[2];
  provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[3] =
    provaGPS_BMP_06_25_B.DataTypeConversion1_hk[3];

  /* Update for Memory: '<S1>/Memory' */
  for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 8;
       provaGPS_BMP_06_25_B.i++) {
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_e[provaGPS_BMP_06_25_B.i] =
      provaGPS_BMP_06_25_B.SFunction_o11[provaGPS_BMP_06_25_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[0] = (uint8_T)AP_mode_idx_0;
  provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[1] = (uint8_T)AP_mode_idx_1;
  for (provaGPS_BMP_06_25_B.i = 0; provaGPS_BMP_06_25_B.i < 7;
       provaGPS_BMP_06_25_B.i++) {
    provaGPS_BMP_06_25_B.f = rt_roundf_snf
      (provaGPS_BMP_06_25_DW.riferimenti[provaGPS_BMP_06_25_B.i]);
    if (provaGPS_BMP_06_25_B.f < 256.0F) {
      if (provaGPS_BMP_06_25_B.f >= 0.0F) {
        provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[provaGPS_BMP_06_25_B.i + 2]
          = (uint8_T)provaGPS_BMP_06_25_B.f;
      } else {
        provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[provaGPS_BMP_06_25_B.i + 2]
          = 0U;
      }
    } else {
      provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[provaGPS_BMP_06_25_B.i + 2] =
        MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  provaGPS_BMP_06_25_DW.UnitDelay_DSTATE =
    provaGPS_BMP_06_25_P.Constant3_Value_g;

  /* Update for Memory: '<S2>/Memory' */
  provaGPS_BMP_06_25_DW.Memory_PreviousInput_f =
    provaGPS_BMP_06_25_B.SFunction_o4;
}

/* Model step function for TID1 */
void provaGPS_BMP_06_25_step1(void)    /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S22>/Add2' incorporates:
   *  Constant: '<S22>/Constant4'
   *  Constant: '<S22>/Constant5'
   *  Memory: '<S22>/Memory2'
   */
  provaGPS_BMP_06_25_DW.Memory2_PreviousInput +=
    provaGPS_BMP_06_25_P.Constant4_Value_n +
    provaGPS_BMP_06_25_P.Constant5_Value_d;

  /* Switch: '<S22>/Switch1' */
  if (provaGPS_BMP_06_25_DW.Memory2_PreviousInput >
      provaGPS_BMP_06_25_P.Switch1_Threshold) {
    /* Sum: '<S22>/Add2' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    provaGPS_BMP_06_25_DW.Memory2_PreviousInput =
      provaGPS_BMP_06_25_P.Constant4_Value_n;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* RateTransition: '<S22>/Rate Transition' */
  provaGPS_BMP_06_25_DW.RateTransition_Buffer0 =
    provaGPS_BMP_06_25_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void provaGPS_BMP_06_25_initialize(void)
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
    memcpy(&provaGPS_BMP_06_25_DW.Memory4_PreviousInput[0],
           &provaGPS_BMP_06_25_P.Memory4_InitialCondition[0], 300U * sizeof
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
          provaGPS_BMP_06_25_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      provaGPS_BMP_06_25_DW.Memory5_PreviousInput[i] =
        provaGPS_BMP_06_25_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[0] =
      provaGPS_BMP_06_25_P.Memory1_InitialCondition_g;
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput_m[1] =
      provaGPS_BMP_06_25_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[0] =
      provaGPS_BMP_06_25_P.Memory_InitialCondition_gh;
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[1] =
      provaGPS_BMP_06_25_P.Memory_InitialCondition_gh;
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[2] =
      provaGPS_BMP_06_25_P.Memory_InitialCondition_gh;
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_m[3] =
      provaGPS_BMP_06_25_P.Memory_InitialCondition_gh;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    provaGPS_BMP_06_25_DW.Memory3_PreviousInput =
      provaGPS_BMP_06_25_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      provaGPS_BMP_06_25_DW.Memory_PreviousInput_e[i] =
        provaGPS_BMP_06_25_P.Memory_InitialCondition_o;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      provaGPS_BMP_06_25_DW.Memory2_PreviousInput_a[i] =
        provaGPS_BMP_06_25_P.Memory2_InitialCondition_p[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S22>/Rate Transition' */
    provaGPS_BMP_06_25_DW.RateTransition_Buffer0 =
      provaGPS_BMP_06_25_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S22>/Switch' incorporates:
     *  Memory: '<S22>/Memory1'
     */
    provaGPS_BMP_06_25_DW.Memory1_PreviousInput =
      provaGPS_BMP_06_25_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S22>/Add' incorporates:
     *  Memory: '<S22>/Memory'
     */
    provaGPS_BMP_06_25_DW.Memory_PreviousInput =
      provaGPS_BMP_06_25_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    provaGPS_BMP_06_25_DW.UnitDelay_DSTATE =
      provaGPS_BMP_06_25_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S29>/Delay Input2'
     *
     * Block description for '<S29>/Delay Input2':
     *
     *  Store in Global RAM
     */
    provaGPS_BMP_06_25_DW.DelayInput2_DSTATE =
      provaGPS_BMP_06_25_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    provaGPS_BMP_06_25_DW.Memory_PreviousInput_f =
      provaGPS_BMP_06_25_P.Memory_InitialCondition_h;

    /* InitializeConditions for Sum: '<S22>/Add2' incorporates:
     *  Memory: '<S22>/Memory2'
     */
    provaGPS_BMP_06_25_DW.Memory2_PreviousInput =
      provaGPS_BMP_06_25_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&provaGPS_BMP_06_25_DW.riferimenti[0], &tmp[0], sizeof(real32_T) <<
           4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S10>/Chart' incorporates:
     *  SubSystem: '<S19>/sendbyte'
     */
    /* Start for MATLABSystem: '<S20>/Serial Transmit' */
    provaGPS_BMP_06_25_DW.obj.matlabCodegenIsDeleted = false;
    provaGPS_BMP_06_25_DW.obj.Protocol =
      provaGPS_BMP_06_25_P.SerialTransmit_Protocol;
    provaGPS_BMP_06_25_DW.obj.isInitialized = 1;
    provaGPS_BMP_06_25_DW.obj.port = 2.0;
    provaGPS_BMP_06_25_DW.obj.dataSizeInBytes = 1.0;
    provaGPS_BMP_06_25_DW.obj.dataType = 0.0;
    provaGPS_BMP_06_25_DW.obj.sendModeEnum = 0.0;
    provaGPS_BMP_06_25_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(provaGPS_BMP_06_25_DW.obj.port);
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
    provaGPS_BMP_06_25_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S20>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S30>/I2C Read12' */
    provaGPS_BMP_06_25_DW.obj_d.matlabCodegenIsDeleted = true;
    obj = &provaGPS_BMP_06_25_DW.obj_d;
    provaGPS_BMP_06_25_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    provaGPS_BMP_06_25_DW.obj_d.isInitialized = 0;
    provaGPS_BMP_06_25_DW.obj_d.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provaGPS_BMP_06_25_DW.obj_d.matlabCodegenIsDeleted = false;
    provaGPS_BMP_06_25_DW.obj_d.SampleTime = provaGPS_BMP_06_25_P.t_AP;
    obj = &provaGPS_BMP_06_25_DW.obj_d;
    provaGPS_BMP_06_25_DW.obj_d.isSetupComplete = false;
    provaGPS_BMP_06_25_DW.obj_d.isInitialized = 1;
    provaGPS_BMP_06_25_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provaGPS_BMP_06_25_B.i2cname,
      0);
    provaGPS_BMP_06_25_DW.obj_d.BusSpeed = 100000U;
    varargin_1 = provaGPS_BMP_06_25_DW.obj_d.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provaGPS_BMP_06_25_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S30>/I2C Read1' */
    provaGPS_BMP_06_25_DW.obj_i.matlabCodegenIsDeleted = true;
    obj = &provaGPS_BMP_06_25_DW.obj_i;
    provaGPS_BMP_06_25_DW.obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
    provaGPS_BMP_06_25_DW.obj_i.isInitialized = 0;
    provaGPS_BMP_06_25_DW.obj_i.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provaGPS_BMP_06_25_DW.obj_i.matlabCodegenIsDeleted = false;
    provaGPS_BMP_06_25_DW.obj_i.SampleTime = provaGPS_BMP_06_25_P.t_AP;
    obj = &provaGPS_BMP_06_25_DW.obj_i;
    provaGPS_BMP_06_25_DW.obj_i.isSetupComplete = false;
    provaGPS_BMP_06_25_DW.obj_i.isInitialized = 1;
    provaGPS_BMP_06_25_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provaGPS_BMP_06_25_B.i2cname,
      0);
    provaGPS_BMP_06_25_DW.obj_i.BusSpeed = 100000U;
    varargin_1 = provaGPS_BMP_06_25_DW.obj_i.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provaGPS_BMP_06_25_DW.obj_i.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S30>/S-Function Builder' incorporates:
     *  Outport: '<S30>/T'
     */
    provaGPS_BMP_06_25_B.SFunctionBuilder_o1 = provaGPS_BMP_06_25_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S30>/S-Function Builder1' incorporates:
     *  Outport: '<S30>/p'
     */
    provaGPS_BMP_06_25_B.SFunctionBuilder1 = provaGPS_BMP_06_25_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    provaGPS_BMP_06_25_DW.P_ref = 101325.0;
    provaGPS_BMP_06_25_DW.rl_up = 300.0;
    provaGPS_BMP_06_25_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init(&provaGPS_BMP_06_25_B.One_time_initialization,
      &provaGPS_BMP_06_25_DW.One_time_initialization,
      &provaGPS_BMP_06_25_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S34>/Subsystem1' */
    /* SystemInitialize for Outport: '<S36>/T_0' incorporates:
     *  Inport: '<S36>/T'
     */
    provaGPS_BMP_06_25_B.T = provaGPS_BMP_06_25_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S34>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* SystemInitialize for Switch: '<S4>/Switch' incorporates:
     *  Outport: '<S4>/h_to_subtract'
     */
    provaGPS_BMP_06_25_B.Switch = provaGPS_BMP_06_25_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S5>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S38>/Memory' */
      provaGPS_BMP_06_25_DW.Memory_PreviousInput_g[i] =
        provaGPS_BMP_06_25_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S38>/Complex to Real-Imag' incorporates:
       *  Outport: '<S38>/Outport'
       */
      provaGPS_BMP_06_25_B.ComplextoRealImag[i] =
        provaGPS_BMP_06_25_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<Root>/mario' incorporates:
     *  Outport: '<S38>/mario'
     */
    provaGPS_BMP_06_25_Y.mario = provaGPS_BMP_06_25_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem2' */

    /* Start for MATLABSystem: '<Root>/Serial Receive1' */
    provaGPS_BMP_06_25_DW.obj_l.matlabCodegenIsDeleted = false;
    provaGPS_BMP_06_25_DW.obj_l.Protocol =
      provaGPS_BMP_06_25_P.SerialReceive1_Protocol;
    provaGPS_BMP_06_25_DW.obj_l.isInitialized = 1;
    provaGPS_BMP_06_25_DW.obj_l.DataTypeWidth = 1U;
    if (provaGPS_BMP_06_25_DW.obj_l.DataTypeWidth > 2047) {
      provaGPS_BMP_06_25_DW.obj_l.DataSizeInBytes = MAX_uint16_T;
    } else {
      provaGPS_BMP_06_25_DW.obj_l.DataSizeInBytes = (uint16_T)
        (provaGPS_BMP_06_25_DW.obj_l.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    provaGPS_BMP_06_25_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive1' */
  }
}

/* Model terminate function */
void provaGPS_BMP_06_25_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive1' */
  if (!provaGPS_BMP_06_25_DW.obj_l.matlabCodegenIsDeleted) {
    provaGPS_BMP_06_25_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term(&provaGPS_BMP_06_25_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S30>/I2C Read12' */
  obj = &provaGPS_BMP_06_25_DW.obj_d;
  if (!provaGPS_BMP_06_25_DW.obj_d.matlabCodegenIsDeleted) {
    provaGPS_BMP_06_25_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((provaGPS_BMP_06_25_DW.obj_d.isInitialized == 1) &&
        provaGPS_BMP_06_25_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S30>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S30>/I2C Read1' */
  obj = &provaGPS_BMP_06_25_DW.obj_i;
  if (!provaGPS_BMP_06_25_DW.obj_i.matlabCodegenIsDeleted) {
    provaGPS_BMP_06_25_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((provaGPS_BMP_06_25_DW.obj_i.isInitialized == 1) &&
        provaGPS_BMP_06_25_DW.obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S30>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S10>/Chart' incorporates:
   *  SubSystem: '<S19>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S20>/Serial Transmit' */
  if (!provaGPS_BMP_06_25_DW.obj.matlabCodegenIsDeleted) {
    provaGPS_BMP_06_25_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S20>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
