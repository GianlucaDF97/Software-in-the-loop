/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaLOG_09_28.c
 *
 * Code generated for Simulink model 'provaLOG_09_28'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  1 12:19:19 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaLOG_09_28.h"
#include "provaLOG_09_28_private.h"

const uint16_T provaLOG_09_28_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_provaLOG_09_28_T provaLOG_09_28_B;

/* Block states (default storage) */
DW_provaLOG_09_28_T provaLOG_09_28_DW;

/* Real-time model */
static RT_MODEL_provaLOG_09_28_T provaLOG_09_28_M_;
RT_MODEL_provaLOG_09_28_T *const provaLOG_09_28_M = &provaLOG_09_28_M_;

/* Forward declaration for local functions */
static void provaLOG_09_28_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter);
static boolean_T provaLOG_09_28_ifWhileCond(const boolean_T x[100]);
static void provaLOG_09_28_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T provaLOG_09_28_ifWhileCond_h(const boolean_T x[5]);
static void provaLOG_09_28_eml_find_a(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void provaLOG_09_28_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T provaLOG_09_28_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T provaLOG_09_28_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k);
static void provaLOG_09_28_readfloat(char_T s1[4], int32_T *idx, const char_T s
  [2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaLOG_09_28_str2double(const char_T s[2]);
static boolean_T provaLOG_09_28_copydigits_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void provaLOG_09_28_readfloat_e(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaLOG_09_28_str2double_f(const char_T s_data[], const int32_T
  s_size[2]);
static boolean_T provaLOG_09_28_isUnitImag(const char_T s[3], int32_T k);
static void provaLOG_09_28_readNonFinite_p(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T provaLOG_09_28_copydigits_o4(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T provaLOG_09_28_copyexponent_e(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k);
static void provaLOG_09_28_readfloat_em(char_T s1[5], int32_T *idx, const char_T
  s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaLOG_09_28_str2double_ft(const char_T s[3]);
static void provaLOG_09_28_readNonFinite_pn(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T provaLOG_09_28_copydigits_o4q(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T provaLOG_09_28_copyexponent_ew(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void provaLOG_09_28_readfloat_eml(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaLOG_09_28_str2double_ftn(char_T s);
static real_T provaLOG_09_28_hex2dec(const char_T s[2]);
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
void provaLOG_09_28_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(provaLOG_09_28_M, 1));
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
  (provaLOG_09_28_M->Timing.TaskCounters.TID[1])++;
  if ((provaLOG_09_28_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    provaLOG_09_28_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for enable system: '<S3>/One_time_initialization' */
void One_time_initializatio_Init(B_One_time_initialization_pro_T *localB,
  DW_One_time_initialization_pr_T *localDW, P_One_time_initialization_pro_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_j_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S38>/I2C Read' */
  localDW->obj_po.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_po;
  localDW->obj_po.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_po.isInitialized = 0;
  localDW->obj_po.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_po.matlabCodegenIsDeleted = false;
  localDW->obj_po.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_po;
  localDW->obj_po.isSetupComplete = false;
  localDW->obj_po.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_po.BusSpeed = 100000U;
  varargin_1 = localDW->obj_po.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_po.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read1' */
  localDW->obj_h.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_h;
  localDW->obj_h.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_h.isInitialized = 0;
  localDW->obj_h.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_h.matlabCodegenIsDeleted = false;
  localDW->obj_h.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_h;
  localDW->obj_h.isSetupComplete = false;
  localDW->obj_h.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_h.BusSpeed = 100000U;
  varargin_1 = localDW->obj_h.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read2' */
  localDW->obj_pb.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_pb;
  localDW->obj_pb.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_pb.isInitialized = 0;
  localDW->obj_pb.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_pb.matlabCodegenIsDeleted = false;
  localDW->obj_pb.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_pb;
  localDW->obj_pb.isSetupComplete = false;
  localDW->obj_pb.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_pb.BusSpeed = 100000U;
  varargin_1 = localDW->obj_pb.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_pb.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read3' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read4' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read5' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  localDW->obj_p.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  localDW->obj_p.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read6' */
  localDW->obj_g.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_g;
  localDW->obj_g.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_g.isInitialized = 0;
  localDW->obj_g.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_g.matlabCodegenIsDeleted = false;
  localDW->obj_g.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_g;
  localDW->obj_g.isSetupComplete = false;
  localDW->obj_g.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_g.BusSpeed = 100000U;
  varargin_1 = localDW->obj_g.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read7' */
  localDW->obj_j.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_j;
  localDW->obj_j.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_j.isInitialized = 0;
  localDW->obj_j.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_j.matlabCodegenIsDeleted = false;
  localDW->obj_j.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_j;
  localDW->obj_j.isSetupComplete = false;
  localDW->obj_j.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_j.BusSpeed = 100000U;
  varargin_1 = localDW->obj_j.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read8' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read10' */
  localDW->obj_g3.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_g3;
  localDW->obj_g3.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_g3.isInitialized = 0;
  localDW->obj_g3.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_g3.matlabCodegenIsDeleted = false;
  localDW->obj_g3.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_g3;
  localDW->obj_g3.isSetupComplete = false;
  localDW->obj_g3.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_g3.BusSpeed = 100000U;
  varargin_1 = localDW->obj_g3.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_g3.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read11' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = provaLOG_09_28_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S38>/I2C Write2' */
  localDW->obj_pd.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_pd;
  localDW->obj_pd.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_pd.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_pd.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_pd;
  localDW->obj_pd.isSetupComplete = false;
  localDW->obj_pd.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_pd.BusSpeed = 100000U;
  varargin_1 = localDW->obj_pd.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_pd.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Write3' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S38>/I2C Read12' */
  localDW->obj_be.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_be;
  localDW->obj_be.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_be.isInitialized = 0;
  localDW->obj_be.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_be.matlabCodegenIsDeleted = false;
  localDW->obj_be.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_be;
  localDW->obj_be.isSetupComplete = false;
  localDW->obj_be.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_be.BusSpeed = 100000U;
  varargin_1 = localDW->obj_be.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_be.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read' incorporates:
   *  Outport: '<S38>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read1' incorporates:
   *  Outport: '<S38>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read2' incorporates:
   *  Outport: '<S38>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read3' incorporates:
   *  Outport: '<S38>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read4' incorporates:
   *  Outport: '<S38>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read5' incorporates:
   *  Outport: '<S38>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read6' incorporates:
   *  Outport: '<S38>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read7' incorporates:
   *  Outport: '<S38>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read8' incorporates:
   *  Outport: '<S38>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read9' incorporates:
   *  Outport: '<S38>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read10' incorporates:
   *  Outport: '<S38>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S38>/I2C Read11' incorporates:
   *  Outport: '<S38>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S38>/Byte Unpack' incorporates:
     *  Outport: '<S38>/pwm_max_min'
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
   *  EnablePort: '<S38>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S38>/I2C Write3' incorporates:
     *  ArithShift: '<S38>/Shift Arithmetic1'
     *  Constant: '<S38>/registro memoria2 '
     *  DataTypeConversion: '<S38>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S38>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S38>/I2C Read' */
    if (localDW->obj_po.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_po.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_po.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_po.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S38>/I2C Read' */

    /* MATLABSystem: '<S38>/I2C Read1' */
    if (localDW->obj_h.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_h.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_h.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read1' */

    /* MATLABSystem: '<S38>/I2C Read2' */
    if (localDW->obj_pb.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_pb.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_pb.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_pb.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read2' */

    /* MATLABSystem: '<S38>/I2C Read3' */
    if (localDW->obj_l.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_l.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S38>/I2C Read3' */

    /* MATLABSystem: '<S38>/I2C Read4' */
    if (localDW->obj_b.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_b.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read4' */

    /* MATLABSystem: '<S38>/I2C Read5' */
    if (localDW->obj_p.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_p.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read5' */

    /* MATLABSystem: '<S38>/I2C Read6' */
    if (localDW->obj_g.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_g.SampleTime = provaLOG_09_28_P.t_AP;
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
      /* MATLABSystem: '<S38>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read6' */

    /* MATLABSystem: '<S38>/I2C Read7' */
    if (localDW->obj_j.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_j.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read7' */

    /* MATLABSystem: '<S38>/I2C Read8' */
    if (localDW->obj_c.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_c.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read8' */

    /* MATLABSystem: '<S38>/I2C Read9' */
    if (localDW->obj.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj.SampleTime = provaLOG_09_28_P.t_AP;
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
      /* MATLABSystem: '<S38>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read9' */

    /* MATLABSystem: '<S38>/I2C Read10' */
    if (localDW->obj_g3.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_g3.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_g3.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_g3.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read10' */

    /* MATLABSystem: '<S38>/I2C Read11' */
    if (localDW->obj_m.SampleTime != provaLOG_09_28_P.t_AP) {
      localDW->obj_m.SampleTime = provaLOG_09_28_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S38>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S38>/I2C Read11' */

    /* MATLABSystem: '<S38>/I2C Write1' incorporates:
     *  Constant: '<S38>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S38>/I2C Write2' incorporates:
     *  Constant: '<S38>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_pd.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S38>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S38>/I2C Read12' */
    if (localDW->obj_be.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_be.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_be.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S38>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S38>/Byte Unpack' */

    /* Unpack: <S38>/Byte Unpack */
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
  codertarget_arduinobase_int_j_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S38>/I2C Read' */
  obj = &localDW->obj_po;
  if (!localDW->obj_po.matlabCodegenIsDeleted) {
    localDW->obj_po.matlabCodegenIsDeleted = true;
    if ((localDW->obj_po.isInitialized == 1) && localDW->obj_po.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read1' */
  obj = &localDW->obj_h;
  if (!localDW->obj_h.matlabCodegenIsDeleted) {
    localDW->obj_h.matlabCodegenIsDeleted = true;
    if ((localDW->obj_h.isInitialized == 1) && localDW->obj_h.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read2' */
  obj = &localDW->obj_pb;
  if (!localDW->obj_pb.matlabCodegenIsDeleted) {
    localDW->obj_pb.matlabCodegenIsDeleted = true;
    if ((localDW->obj_pb.isInitialized == 1) && localDW->obj_pb.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read3' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read4' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read5' */
  obj = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read6' */
  obj = &localDW->obj_g;
  if (!localDW->obj_g.matlabCodegenIsDeleted) {
    localDW->obj_g.matlabCodegenIsDeleted = true;
    if ((localDW->obj_g.isInitialized == 1) && localDW->obj_g.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read7' */
  obj = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read8' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read10' */
  obj = &localDW->obj_g3;
  if (!localDW->obj_g3.matlabCodegenIsDeleted) {
    localDW->obj_g3.matlabCodegenIsDeleted = true;
    if ((localDW->obj_g3.isInitialized == 1) && localDW->obj_g3.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read11' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S38>/I2C Write1' */
  obj_0 = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S38>/I2C Write2' */
  obj_0 = &localDW->obj_pd;
  if (!localDW->obj_pd.matlabCodegenIsDeleted) {
    localDW->obj_pd.matlabCodegenIsDeleted = true;
    if ((localDW->obj_pd.isInitialized == 1) && localDW->obj_pd.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S38>/I2C Write3' */
  obj_0 = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S38>/I2C Read12' */
  obj = &localDW->obj_be;
  if (!localDW->obj_be.matlabCodegenIsDeleted) {
    localDW->obj_be.matlabCodegenIsDeleted = true;
    if ((localDW->obj_be.isInitialized == 1) && localDW->obj_be.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/I2C Read12' */
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void provaLOG_09_28_find_254(const uint8_T pack[100], real_T position[3],
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
static boolean_T provaLOG_09_28_ifWhileCond(const boolean_T x[100])
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_ifWhileCond_h(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_eml_find_a(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copydigits(char_T s1[4], int32_T *idx, const
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copyexponent(char_T s1[4], int32_T *idx, const
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

      provaLOG_09_28_B.kexp_l = *k;
      b_k = *k;
      b_success = provaLOG_09_28_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > provaLOG_09_28_B.kexp_l));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readfloat(char_T s1[4], int32_T *idx, const char_T s
  [2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
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
            provaLOG_09_28_readfloat(s1, idx, s, k, false, &isneg, b_finite, nfv,
              &unusedU2, success);
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
      provaLOG_09_28_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = provaLOG_09_28_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = provaLOG_09_28_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static creal_T provaLOG_09_28_str2double(const char_T s[2])
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
  provaLOG_09_28_B.ntoread_b = 0;
  provaLOG_09_28_B.k_b = 0;
  while ((provaLOG_09_28_B.k_b + 1 <= 2) && (c[(uint8_T)s[provaLOG_09_28_B.k_b]
          & 127] || (s[provaLOG_09_28_B.k_b] == '\x00'))) {
    provaLOG_09_28_B.k_b++;
  }

  isimag1 = false;
  b_finite = true;
  provaLOG_09_28_B.scanned1_g = 0.0;
  provaLOG_09_28_B.idx_n = 1;
  provaLOG_09_28_B.s1_g[0] = '\x00';
  provaLOG_09_28_B.s1_g[1] = '\x00';
  provaLOG_09_28_B.s1_g[2] = '\x00';
  provaLOG_09_28_B.s1_g[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaLOG_09_28_B.k_b + 1 <= 2)) {
    if (s[provaLOG_09_28_B.k_b] == '-') {
      isneg = !isneg;
      provaLOG_09_28_B.k_b++;
    } else if ((s[provaLOG_09_28_B.k_b] == ',') || (s[provaLOG_09_28_B.k_b] ==
                '+') || c[(uint8_T)s[provaLOG_09_28_B.k_b] & 127]) {
      provaLOG_09_28_B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  success = (provaLOG_09_28_B.k_b + 1 <= 2);
  if (success && isneg) {
    provaLOG_09_28_B.s1_g[0] = '-';
    provaLOG_09_28_B.idx_n = 2;
  }

  provaLOG_09_28_B.e_k = provaLOG_09_28_B.k_b + 1;
  if (success) {
    if ((provaLOG_09_28_B.k_b + 1 <= 2) && ((s[provaLOG_09_28_B.k_b] == 'j') ||
         (s[provaLOG_09_28_B.k_b] == 'i'))) {
      isimag1 = true;
      provaLOG_09_28_B.e_k = provaLOG_09_28_B.k_b + 2;
      while ((provaLOG_09_28_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1] ==
               '\x00') || (s[1] == ','))) {
        provaLOG_09_28_B.e_k = 3;
      }

      if ((provaLOG_09_28_B.e_k <= 2) && (s[1] == '*')) {
        provaLOG_09_28_B.e_k = 3;
        provaLOG_09_28_readfloat(provaLOG_09_28_B.s1_g, &provaLOG_09_28_B.idx_n,
          s, &provaLOG_09_28_B.e_k, false, &isneg, &b_finite,
          &provaLOG_09_28_B.scanned1_g, &unusedU2, &success);
      } else {
        provaLOG_09_28_B.s1_g[provaLOG_09_28_B.idx_n - 1] = '1';
        provaLOG_09_28_B.idx_n++;
      }
    } else {
      provaLOG_09_28_B.e_k = provaLOG_09_28_B.k_b + 1;
      provaLOG_09_28_readNonFinite(s, &provaLOG_09_28_B.e_k, &b_finite,
        &provaLOG_09_28_B.scanned1_g);
      if (b_finite) {
        success = provaLOG_09_28_copydigits(provaLOG_09_28_B.s1_g,
          &provaLOG_09_28_B.idx_n, s, &provaLOG_09_28_B.e_k, true);
        if (success) {
          success = provaLOG_09_28_copyexponent(provaLOG_09_28_B.s1_g,
            &provaLOG_09_28_B.idx_n, s, &provaLOG_09_28_B.e_k);
        }
      } else {
        if ((provaLOG_09_28_B.idx_n >= 2) && (provaLOG_09_28_B.s1_g[0] == '-'))
        {
          provaLOG_09_28_B.idx_n = 1;
          provaLOG_09_28_B.s1_g[0] = ' ';
          provaLOG_09_28_B.scanned1_g = -provaLOG_09_28_B.scanned1_g;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (provaLOG_09_28_B.e_k <= 2)) {
        tmp = s[provaLOG_09_28_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          provaLOG_09_28_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((provaLOG_09_28_B.e_k <= 2) && (s[provaLOG_09_28_B.e_k - 1] == '*')) {
        provaLOG_09_28_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (provaLOG_09_28_B.e_k <= 2)) {
          tmp = s[provaLOG_09_28_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            provaLOG_09_28_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (provaLOG_09_28_B.e_k <= 2) {
        tmp = s[provaLOG_09_28_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          provaLOG_09_28_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (provaLOG_09_28_B.e_k <= 2)) {
      tmp = s[provaLOG_09_28_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        provaLOG_09_28_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    provaLOG_09_28_B.ntoread_b = 1;
  }

  if (success && (provaLOG_09_28_B.e_k <= 2)) {
    provaLOG_09_28_B.s1_g[provaLOG_09_28_B.idx_n - 1] = ' ';
    provaLOG_09_28_B.idx_n++;
    provaLOG_09_28_readfloat(provaLOG_09_28_B.s1_g, &provaLOG_09_28_B.idx_n, s,
      &provaLOG_09_28_B.e_k, true, &success, &isneg,
      &provaLOG_09_28_B.scanned2_m, &unusedU2, &c_success);
    if (isneg) {
      provaLOG_09_28_B.ntoread_b++;
    }

    success = (c_success && (provaLOG_09_28_B.e_k > 2) && (isimag1 != success) &&
               unusedU2);
  } else {
    provaLOG_09_28_B.scanned2_m = 0.0;
  }

  if (success) {
    provaLOG_09_28_B.s1_g[provaLOG_09_28_B.idx_n - 1] = '\x00';
    switch (provaLOG_09_28_B.ntoread_b) {
     case 2:
      provaLOG_09_28_B.ntoread_b = sscanf(&provaLOG_09_28_B.s1_g[0], "%lf %lf",
        &provaLOG_09_28_B.scanned1_g, &provaLOG_09_28_B.scanned2_m);
      if (provaLOG_09_28_B.ntoread_b != 2) {
        provaLOG_09_28_B.scanned1_g = (rtNaN);
        provaLOG_09_28_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      provaLOG_09_28_B.ntoread_b = sscanf(&provaLOG_09_28_B.s1_g[0], "%lf",
        &provaLOG_09_28_B.b_scanned1_n);
      if (b_finite) {
        if (provaLOG_09_28_B.ntoread_b == 1) {
          provaLOG_09_28_B.scanned1_g = provaLOG_09_28_B.b_scanned1_n;
        } else {
          provaLOG_09_28_B.scanned1_g = (rtNaN);
        }
      } else if (provaLOG_09_28_B.ntoread_b == 1) {
        provaLOG_09_28_B.scanned2_m = provaLOG_09_28_B.b_scanned1_n;
      } else {
        provaLOG_09_28_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaLOG_09_28_B.scanned2_m;
      x.im = provaLOG_09_28_B.scanned1_g;
    } else {
      x.re = provaLOG_09_28_B.scanned1_g;
      x.im = provaLOG_09_28_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copydigits_o(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readfloat_e(char_T s1_data[], int32_T *idx, const
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
          provaLOG_09_28_readfloat_e(s1_data, idx, s_data, k, n, false, &isneg,
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
        *success = provaLOG_09_28_copydigits_o(s1_data, &b_idx, s_data, &h_k, n,
          true);
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
              isneg = provaLOG_09_28_copydigits_o(s1_data, idx, s_data, &b_idx,
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static creal_T provaLOG_09_28_str2double_f(const char_T s_data[], const int32_T
  s_size[2])
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
    provaLOG_09_28_B.ntoread = 0;
    provaLOG_09_28_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (provaLOG_09_28_B.k <= s_size[1])) {
      tmp = s_data[provaLOG_09_28_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        provaLOG_09_28_B.k++;
      } else {
        exitg1 = true;
      }
    }

    provaLOG_09_28_B.s1_size[0] = 1;
    provaLOG_09_28_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    provaLOG_09_28_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= provaLOG_09_28_B.idx) {
      memset(&provaLOG_09_28_B.s1_data[0], 0, (provaLOG_09_28_B.idx + 1) *
             sizeof(char_T));
    }

    provaLOG_09_28_B.idx = 1;
    provaLOG_09_28_readfloat_e(provaLOG_09_28_B.s1_data, &provaLOG_09_28_B.idx,
      s_data, &provaLOG_09_28_B.k, s_size[1], true, &isimag1, &isfinite1,
      &provaLOG_09_28_B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      provaLOG_09_28_B.ntoread = 1;
    }

    if (success) {
      if (provaLOG_09_28_B.k <= s_size[1]) {
        provaLOG_09_28_B.s1_data[provaLOG_09_28_B.idx - 1] = ' ';
        provaLOG_09_28_B.idx++;
        provaLOG_09_28_readfloat_e(provaLOG_09_28_B.s1_data,
          &provaLOG_09_28_B.idx, s_data, &provaLOG_09_28_B.k, s_size[1], true,
          &unusedU0, &success, &provaLOG_09_28_B.scanned2, &foundsign,
          &c_success);
        if (success) {
          provaLOG_09_28_B.ntoread++;
        }

        success = (c_success && ((provaLOG_09_28_B.k > s_size[1]) && ((isimag1
          != unusedU0) && foundsign)));
      } else {
        provaLOG_09_28_B.scanned2 = 0.0;
      }
    } else {
      provaLOG_09_28_B.scanned2 = 0.0;
    }

    if (success) {
      provaLOG_09_28_B.s1_data[provaLOG_09_28_B.idx - 1] = '\x00';
      switch (provaLOG_09_28_B.ntoread) {
       case 2:
        provaLOG_09_28_B.ntoread = sscanf(&provaLOG_09_28_B.s1_data[0],
          "%lf %lf", &provaLOG_09_28_B.scanned1, &provaLOG_09_28_B.scanned2);
        if (provaLOG_09_28_B.ntoread != 2) {
          provaLOG_09_28_B.scanned1 = (rtNaN);
          provaLOG_09_28_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        provaLOG_09_28_B.ntoread = sscanf(&provaLOG_09_28_B.s1_data[0], "%lf",
          &provaLOG_09_28_B.b_scanned1);
        if (isfinite1) {
          if (provaLOG_09_28_B.ntoread == 1) {
            provaLOG_09_28_B.scanned1 = provaLOG_09_28_B.b_scanned1;
          } else {
            provaLOG_09_28_B.scanned1 = (rtNaN);
          }
        } else if (provaLOG_09_28_B.ntoread == 1) {
          provaLOG_09_28_B.scanned2 = provaLOG_09_28_B.b_scanned1;
        } else {
          provaLOG_09_28_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = provaLOG_09_28_B.scanned2;
        x.im = provaLOG_09_28_B.scanned1;
      } else {
        x.re = provaLOG_09_28_B.scanned1;
        x.im = provaLOG_09_28_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readNonFinite_p(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copydigits_o4(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copyexponent_e(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k)
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

      provaLOG_09_28_B.kexp = *k;
      b_k = *k;
      b_success = provaLOG_09_28_copydigits_o4(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > provaLOG_09_28_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readfloat_em(char_T s1[5], int32_T *idx, const char_T
  s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
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
    if (provaLOG_09_28_isUnitImag(s, b_k)) {
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
          provaLOG_09_28_readfloat_em(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      provaLOG_09_28_readNonFinite_p(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = provaLOG_09_28_copydigits_o4(s1, idx, s, k, true);
        if (*success) {
          *success = provaLOG_09_28_copyexponent_e(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static creal_T provaLOG_09_28_str2double_ft(const char_T s[3])
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
  provaLOG_09_28_B.ntoread_o = 0;
  provaLOG_09_28_B.k_d = 1;
  exitg1 = false;
  while ((!exitg1) && (provaLOG_09_28_B.k_d <= 3)) {
    tmp = s[provaLOG_09_28_B.k_d - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      provaLOG_09_28_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  provaLOG_09_28_B.scanned1_c = 0.0;
  provaLOG_09_28_B.idx_l = 1;
  for (provaLOG_09_28_B.b_k = 0; provaLOG_09_28_B.b_k < 5; provaLOG_09_28_B.b_k
       ++) {
    provaLOG_09_28_B.s1[provaLOG_09_28_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaLOG_09_28_B.k_d <= 3)) {
    tmp = s[provaLOG_09_28_B.k_d - 1];
    if (tmp == '-') {
      isneg = !isneg;
      provaLOG_09_28_B.k_d++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      provaLOG_09_28_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  success = (provaLOG_09_28_B.k_d <= 3);
  if (success && isneg) {
    provaLOG_09_28_B.s1[0] = '-';
    provaLOG_09_28_B.idx_l = 2;
  }

  provaLOG_09_28_B.b_k = provaLOG_09_28_B.k_d - 1;
  if (success) {
    if (provaLOG_09_28_isUnitImag(s, provaLOG_09_28_B.k_d)) {
      isimag1 = true;
      provaLOG_09_28_B.b_k = provaLOG_09_28_B.k_d;
      while ((provaLOG_09_28_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[provaLOG_09_28_B.b_k] & 127] || (s[provaLOG_09_28_B.b_k] ==
               '\x00') || (s[provaLOG_09_28_B.b_k] == ','))) {
        provaLOG_09_28_B.b_k++;
      }

      if ((provaLOG_09_28_B.b_k + 1 <= 3) && (s[provaLOG_09_28_B.b_k] == '*')) {
        provaLOG_09_28_B.k_d = provaLOG_09_28_B.b_k + 2;
        provaLOG_09_28_readfloat_em(provaLOG_09_28_B.s1, &provaLOG_09_28_B.idx_l,
          s, &provaLOG_09_28_B.k_d, false, &isneg, &b_finite,
          &provaLOG_09_28_B.scanned1_c, &unusedU2, &success);
        provaLOG_09_28_B.b_k = provaLOG_09_28_B.k_d - 1;
      } else {
        provaLOG_09_28_B.s1[provaLOG_09_28_B.idx_l - 1] = '1';
        provaLOG_09_28_B.idx_l++;
      }
    } else {
      provaLOG_09_28_readNonFinite_p(s, &provaLOG_09_28_B.k_d, &b_finite,
        &provaLOG_09_28_B.scanned1_c);
      provaLOG_09_28_B.b_k = provaLOG_09_28_B.k_d - 1;
      if (b_finite) {
        success = provaLOG_09_28_copydigits_o4(provaLOG_09_28_B.s1,
          &provaLOG_09_28_B.idx_l, s, &provaLOG_09_28_B.k_d, true);
        provaLOG_09_28_B.b_k = provaLOG_09_28_B.k_d - 1;
        if (success) {
          success = provaLOG_09_28_copyexponent_e(provaLOG_09_28_B.s1,
            &provaLOG_09_28_B.idx_l, s, &provaLOG_09_28_B.k_d);
          provaLOG_09_28_B.b_k = provaLOG_09_28_B.k_d - 1;
        }
      } else {
        if ((provaLOG_09_28_B.idx_l >= 2) && (provaLOG_09_28_B.s1[0] == '-')) {
          provaLOG_09_28_B.idx_l = 1;
          provaLOG_09_28_B.s1[0] = ' ';
          provaLOG_09_28_B.scanned1_c = -provaLOG_09_28_B.scanned1_c;
        }
      }

      while ((provaLOG_09_28_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[provaLOG_09_28_B.b_k] & 127] || (s[provaLOG_09_28_B.b_k] ==
               '\x00') || (s[provaLOG_09_28_B.b_k] == ','))) {
        provaLOG_09_28_B.b_k++;
      }

      if ((provaLOG_09_28_B.b_k + 1 <= 3) && (s[provaLOG_09_28_B.b_k] == '*')) {
        provaLOG_09_28_B.b_k++;
        while ((provaLOG_09_28_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[provaLOG_09_28_B.b_k] & 127] || (s[provaLOG_09_28_B.b_k] ==
                 '\x00') || (s[provaLOG_09_28_B.b_k] == ','))) {
          provaLOG_09_28_B.b_k++;
        }
      }

      if ((provaLOG_09_28_B.b_k + 1 <= 3) && ((s[provaLOG_09_28_B.b_k] == 'i') ||
           (s[provaLOG_09_28_B.b_k] == 'j'))) {
        provaLOG_09_28_B.b_k++;
        isimag1 = true;
      }
    }

    while ((provaLOG_09_28_B.b_k + 1 <= 3) && (c[(uint8_T)s[provaLOG_09_28_B.b_k]
            & 127] || (s[provaLOG_09_28_B.b_k] == '\x00') ||
            (s[provaLOG_09_28_B.b_k] == ','))) {
      provaLOG_09_28_B.b_k++;
    }
  }

  if (b_finite) {
    provaLOG_09_28_B.ntoread_o = 1;
  }

  if (success && (provaLOG_09_28_B.b_k + 1 <= 3)) {
    provaLOG_09_28_B.s1[provaLOG_09_28_B.idx_l - 1] = ' ';
    provaLOG_09_28_B.idx_l++;
    provaLOG_09_28_B.k_d = provaLOG_09_28_B.b_k + 1;
    provaLOG_09_28_readfloat_em(provaLOG_09_28_B.s1, &provaLOG_09_28_B.idx_l, s,
      &provaLOG_09_28_B.k_d, true, &success, &isneg,
      &provaLOG_09_28_B.scanned2_f, &unusedU2, &c_success);
    if (isneg) {
      provaLOG_09_28_B.ntoread_o++;
    }

    success = (c_success && (provaLOG_09_28_B.k_d > 3) && (isimag1 != success) &&
               unusedU2);
  } else {
    provaLOG_09_28_B.scanned2_f = 0.0;
  }

  if (success) {
    provaLOG_09_28_B.s1[provaLOG_09_28_B.idx_l - 1] = '\x00';
    switch (provaLOG_09_28_B.ntoread_o) {
     case 2:
      provaLOG_09_28_B.ntoread_o = sscanf(&provaLOG_09_28_B.s1[0], "%lf %lf",
        &provaLOG_09_28_B.scanned1_c, &provaLOG_09_28_B.scanned2_f);
      if (provaLOG_09_28_B.ntoread_o != 2) {
        provaLOG_09_28_B.scanned1_c = (rtNaN);
        provaLOG_09_28_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      provaLOG_09_28_B.ntoread_o = sscanf(&provaLOG_09_28_B.s1[0], "%lf",
        &provaLOG_09_28_B.b_scanned1_g);
      if (b_finite) {
        if (provaLOG_09_28_B.ntoread_o == 1) {
          provaLOG_09_28_B.scanned1_c = provaLOG_09_28_B.b_scanned1_g;
        } else {
          provaLOG_09_28_B.scanned1_c = (rtNaN);
        }
      } else if (provaLOG_09_28_B.ntoread_o == 1) {
        provaLOG_09_28_B.scanned2_f = provaLOG_09_28_B.b_scanned1_g;
      } else {
        provaLOG_09_28_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaLOG_09_28_B.scanned2_f;
      x.im = provaLOG_09_28_B.scanned1_c;
    } else {
      x.re = provaLOG_09_28_B.scanned1_c;
      x.im = provaLOG_09_28_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readNonFinite_pn(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copydigits_o4q(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static boolean_T provaLOG_09_28_copyexponent_ew(char_T s1[3], int32_T *idx,
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
    b_success = provaLOG_09_28_copydigits_o4q(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static void provaLOG_09_28_readfloat_eml(char_T s1[3], int32_T *idx, char_T s,
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
          provaLOG_09_28_readfloat_eml(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      provaLOG_09_28_readNonFinite_pn(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = provaLOG_09_28_copydigits_o4q(s1, idx, s, k, true);
        if (*success) {
          *success = provaLOG_09_28_copyexponent_ew(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static creal_T provaLOG_09_28_str2double_ftn(char_T s)
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
  provaLOG_09_28_B.ntoread_bn = 0;
  provaLOG_09_28_B.d_k = 1;
  provaLOG_09_28_B.i_d = (uint8_T)s & 127;
  if (c[provaLOG_09_28_B.i_d] || (s == '\x00')) {
    provaLOG_09_28_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  provaLOG_09_28_B.scanned1_p = 0.0;
  provaLOG_09_28_B.idx_h = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaLOG_09_28_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      provaLOG_09_28_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[provaLOG_09_28_B.i_d]) {
      provaLOG_09_28_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (provaLOG_09_28_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    provaLOG_09_28_B.idx_h = 2;
  }

  if (success) {
    isneg = false;
    if (provaLOG_09_28_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      provaLOG_09_28_B.d_k++;
      s1[provaLOG_09_28_B.idx_h - 1] = '1';
      provaLOG_09_28_B.idx_h++;
    } else {
      provaLOG_09_28_readNonFinite_pn(s, &provaLOG_09_28_B.d_k, &b_finite,
        &provaLOG_09_28_B.scanned1_p);
      if (b_finite) {
        success = provaLOG_09_28_copydigits_o4q(s1, &provaLOG_09_28_B.idx_h, s,
          &provaLOG_09_28_B.d_k, true);
        if (success) {
          success = provaLOG_09_28_copyexponent_ew(s1, &provaLOG_09_28_B.idx_h,
            s, &provaLOG_09_28_B.d_k);
        }
      } else {
        if ((provaLOG_09_28_B.idx_h >= 2) && (s1[0] == '-')) {
          provaLOG_09_28_B.idx_h = 1;
          s1[0] = ' ';
          provaLOG_09_28_B.scanned1_p = -provaLOG_09_28_B.scanned1_p;
        }
      }

      while ((provaLOG_09_28_B.d_k <= 1) && (c[provaLOG_09_28_B.i_d] || ((s ==
                '\x00') || (s == ',')))) {
        provaLOG_09_28_B.d_k = 2;
      }

      if ((provaLOG_09_28_B.d_k <= 1) && (s == '*')) {
        provaLOG_09_28_B.d_k = 2;
      }

      if ((provaLOG_09_28_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        provaLOG_09_28_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((provaLOG_09_28_B.d_k <= 1) && (c[provaLOG_09_28_B.i_d] || ((s ==
              '\x00') || (s == ',')))) {
      provaLOG_09_28_B.d_k = 2;
    }
  }

  if (b_finite) {
    provaLOG_09_28_B.ntoread_bn = 1;
  }

  if (success && (provaLOG_09_28_B.d_k <= 1)) {
    s1[provaLOG_09_28_B.idx_h - 1] = ' ';
    provaLOG_09_28_B.idx_h++;
    provaLOG_09_28_B.d_k = 1;
    provaLOG_09_28_readfloat_eml(s1, &provaLOG_09_28_B.idx_h, s,
      &provaLOG_09_28_B.d_k, true, &success, &isneg,
      &provaLOG_09_28_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      provaLOG_09_28_B.ntoread_bn++;
    }

    success = (c_success && (provaLOG_09_28_B.d_k > 1) && (isimag1 != success) &&
               foundsign);
  } else {
    provaLOG_09_28_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[provaLOG_09_28_B.idx_h - 1] = '\x00';
    switch (provaLOG_09_28_B.ntoread_bn) {
     case 2:
      provaLOG_09_28_B.ntoread_bn = sscanf(&s1[0], "%lf %lf",
        &provaLOG_09_28_B.scanned1_p, &provaLOG_09_28_B.scanned2_l);
      if (provaLOG_09_28_B.ntoread_bn != 2) {
        provaLOG_09_28_B.scanned1_p = (rtNaN);
        provaLOG_09_28_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      provaLOG_09_28_B.ntoread_bn = sscanf(&s1[0], "%lf",
        &provaLOG_09_28_B.b_scanned1_j);
      if (b_finite) {
        if (provaLOG_09_28_B.ntoread_bn == 1) {
          provaLOG_09_28_B.scanned1_p = provaLOG_09_28_B.b_scanned1_j;
        } else {
          provaLOG_09_28_B.scanned1_p = (rtNaN);
        }
      } else if (provaLOG_09_28_B.ntoread_bn == 1) {
        provaLOG_09_28_B.scanned2_l = provaLOG_09_28_B.b_scanned1_j;
      } else {
        provaLOG_09_28_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaLOG_09_28_B.scanned2_l;
      x.im = provaLOG_09_28_B.scanned1_p;
    } else {
      x.re = provaLOG_09_28_B.scanned1_p;
      x.im = provaLOG_09_28_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S23>/MATLAB Function' */
static real_T provaLOG_09_28_hex2dec(const char_T s[2])
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

  provaLOG_09_28_B.a = tmp_0;
  provaLOG_09_28_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &provaLOG_09_28_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&provaLOG_09_28_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &provaLOG_09_28_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &provaLOG_09_28_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&provaLOG_09_28_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &provaLOG_09_28_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &provaLOG_09_28_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&provaLOG_09_28_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &provaLOG_09_28_B.sk.chunks[0U], 2);
      } else {
        provaLOG_09_28_B.sk = tmp_0;
      }
    } else {
      provaLOG_09_28_B.sk = tmp_0;
    }

    uMultiWordMul(&provaLOG_09_28_B.sk.chunks[0U], 2,
                  &provaLOG_09_28_B.p16.chunks[0U], 2,
                  &provaLOG_09_28_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&provaLOG_09_28_B.r.chunks[0U], 4,
                         &provaLOG_09_28_B.r3.chunks[0U], 2);
    MultiWordAdd(&provaLOG_09_28_B.a.chunks[0U], &provaLOG_09_28_B.r3.chunks[0U],
                 &tmp.chunks[0U], 2);
    provaLOG_09_28_B.a = tmp;
    uMultiWord2MultiWord(&provaLOG_09_28_B.p16.chunks[0U], 2,
                         &provaLOG_09_28_B.r2.chunks[0U], 3);
    uMultiWordShl(&provaLOG_09_28_B.r2.chunks[0U], 3, 4U,
                  &provaLOG_09_28_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&provaLOG_09_28_B.r1.chunks[0U], 3,
                         &provaLOG_09_28_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&provaLOG_09_28_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&provaLOG_09_28_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&provaLOG_09_28_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&provaLOG_09_28_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&provaLOG_09_28_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&provaLOG_09_28_B.a.chunks[0U], 2, 0);
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
void provaLOG_09_28_step0(void)        /* Sample time: [0.02s, 0.0s] */
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

  /* S-Function (Mti): '<S26>/S-Function Builder' */
  Mti_Outputs_wrapper(&provaLOG_09_28_B.SFunctionBuilder[0],
                      &provaLOG_09_28_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S26>/Byte Unpack' */

  /* Unpack: <S26>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&provaLOG_09_28_B.ByteUnpack_o1[0], (uint8_T*)
             &provaLOG_09_28_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&provaLOG_09_28_B.ByteUnpack_o2[0], (uint8_T*)
             &provaLOG_09_28_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&provaLOG_09_28_B.ByteUnpack_o3, (uint8_T*)
             &provaLOG_09_28_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S26>/Byte Reversal' */

  /* ReverseEndian: <S26>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &provaLOG_09_28_B.ByteUnpack_o2[0];
    real32_T *y0 = &provaLOG_09_28_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&provaLOG_09_28_P.Constant1_Value_i,
    &provaLOG_09_28_B.SFunctionBuilder_o1_j[0],
    &provaLOG_09_28_B.SFunctionBuilder_o2,
    &provaLOG_09_28_DW.SFunctionBuilder_DSTATE_c);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  provaLOG_09_28_B.status = 0;
  provaLOG_09_28_B.caso = 0;
  memset(&provaLOG_09_28_B.messaggio_l[0], 0, 100U * sizeof(uint8_T));
  memset(&provaLOG_09_28_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  provaLOG_09_28_find_254(provaLOG_09_28_B.SFunctionBuilder_o1_j,
    provaLOG_09_28_B.poss_254, &provaLOG_09_28_B.num_254);
  if (provaLOG_09_28_DW.Interr_parz && (provaLOG_09_28_B.num_254 == 1.0)) {
    provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_DW.counter_m + 1U);
    if (provaLOG_09_28_DW.counter_m + 1U > 255U) {
      provaLOG_09_28_B.f_l = 255;
    }

    if (provaLOG_09_28_B.poss_254[0] != provaLOG_09_28_B.f_l) {
      provaLOG_09_28_B.num_254 = 0.0;
    }
  }

  y = !provaLOG_09_28_DW.Interr_parz;
  if ((provaLOG_09_28_B.num_254 == 1.0) && y) {
    provaLOG_09_28_B.caso = 1;
  } else if ((provaLOG_09_28_B.num_254 == 0.0) && provaLOG_09_28_DW.Interr_parz)
  {
    provaLOG_09_28_B.caso = 2;
  } else if ((provaLOG_09_28_B.num_254 == 1.0) && provaLOG_09_28_DW.Interr_parz)
  {
    provaLOG_09_28_B.caso = 3;
  } else {
    if ((provaLOG_09_28_B.num_254 == 2.0) && y) {
      provaLOG_09_28_B.caso = 4;
    }
  }

  switch (provaLOG_09_28_B.caso) {
   case 1:
    provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.poss_254[(int32_T)
      provaLOG_09_28_B.num_254 - 1];
    if (provaLOG_09_28_B.RateTransition == 100.0) {
      provaLOG_09_28_DW.message_e[0] = provaLOG_09_28_B.SFunctionBuilder_o1_j[99];
      provaLOG_09_28_DW.Interr_parz = true;
    } else if (provaLOG_09_28_B.SFunctionBuilder_o1_j[(int32_T)
               (provaLOG_09_28_B.RateTransition + 1.0) - 1] <= 100) {
      provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.SFunctionBuilder_o1_j
        [(int32_T)(provaLOG_09_28_B.poss_254[0] + 1.0) - 1] + 8U);
      provaLOG_09_28_B.i = provaLOG_09_28_B.f_l;
      if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
        provaLOG_09_28_B.i = 255;
      }

      if (provaLOG_09_28_B.i == provaLOG_09_28_B.SFunctionBuilder_o2) {
        provaLOG_09_28_B.UkYk1 = rt_roundd_snf(provaLOG_09_28_B.RateTransition);
        if (provaLOG_09_28_B.UkYk1 < 256.0) {
          if (provaLOG_09_28_B.UkYk1 >= 0.0) {
            counter = (uint8_T)provaLOG_09_28_B.UkYk1;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.SFunctionBuilder_o1_j
          [(int32_T)(provaLOG_09_28_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
          provaLOG_09_28_B.f_l = 255;
        }

        provaLOG_09_28_B.RateTransition = rt_roundd_snf
          (provaLOG_09_28_B.RateTransition + (real_T)provaLOG_09_28_B.f_l);
        if (provaLOG_09_28_B.RateTransition < 256.0) {
          if (provaLOG_09_28_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)provaLOG_09_28_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          provaLOG_09_28_B.i = 0;
          provaLOG_09_28_B.f_l = 0;
        } else {
          provaLOG_09_28_B.i = counter - 1;
          provaLOG_09_28_B.f_l = find_comma;
        }

        provaLOG_09_28_B.caso = provaLOG_09_28_B.f_l - provaLOG_09_28_B.i;
        for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
             provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.f_l] =
            provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.i +
            provaLOG_09_28_B.f_l];
        }

        provaLOG_09_28_B.status = 1;
        for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 100;
             provaLOG_09_28_B.i++) {
          provaLOG_09_28_B.messaggio_l[provaLOG_09_28_B.i] =
            provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i];
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i] = 0U;
        }

        provaLOG_09_28_DW.counter_m = 0U;
        provaLOG_09_28_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
          provaLOG_09_28_B.f_l = 255;
        }

        if (provaLOG_09_28_B.f_l > provaLOG_09_28_B.SFunctionBuilder_o2) {
          provaLOG_09_28_DW.mess_len = provaLOG_09_28_B.SFunctionBuilder_o2;
          if (provaLOG_09_28_B.RateTransition > provaLOG_09_28_DW.mess_len) {
            provaLOG_09_28_B.i = 0;
            provaLOG_09_28_B.f_l = 0;
          } else {
            provaLOG_09_28_B.i = (int32_T)provaLOG_09_28_B.RateTransition - 1;
            provaLOG_09_28_B.f_l = (int32_T)provaLOG_09_28_DW.mess_len;
          }

          provaLOG_09_28_B.caso = provaLOG_09_28_B.f_l - provaLOG_09_28_B.i;
          for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
               provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
            provaLOG_09_28_DW.message_e[provaLOG_09_28_B.f_l] =
              provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.i +
              provaLOG_09_28_B.f_l];
          }

          provaLOG_09_28_B.f_l = (int32_T)
            (provaLOG_09_28_B.SFunctionBuilder_o1_j[(int32_T)
             (provaLOG_09_28_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
            provaLOG_09_28_B.f_l = 255;
          }

          provaLOG_09_28_B.RateTransition = rt_roundd_snf((real_T)
            provaLOG_09_28_B.f_l - provaLOG_09_28_DW.mess_len);
          if (provaLOG_09_28_B.RateTransition < 256.0) {
            if (provaLOG_09_28_B.RateTransition >= 0.0) {
              provaLOG_09_28_DW.counter_m = (uint8_T)
                provaLOG_09_28_B.RateTransition;
            } else {
              provaLOG_09_28_DW.counter_m = 0U;
            }
          } else {
            provaLOG_09_28_DW.counter_m = MAX_uint8_T;
          }

          provaLOG_09_28_DW.Interr_parz = true;
        }
      }
    } else {
      provaLOG_09_28_DW.Interr_parz = false;
      memset(&provaLOG_09_28_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      provaLOG_09_28_DW.counter_m = 0U;
      provaLOG_09_28_DW.mess_len = 0.0;
      provaLOG_09_28_B.status = 1;
    }
    break;

   case 2:
    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.x[provaLOG_09_28_B.f_l] =
        (provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.f_l] != 0);
    }

    if (provaLOG_09_28_ifWhileCond(provaLOG_09_28_B.x)) {
      provaLOG_09_28_B.RateTransition = rt_roundd_snf(provaLOG_09_28_DW.mess_len
        + 1.0);
      if (provaLOG_09_28_B.RateTransition < 256.0) {
        if (provaLOG_09_28_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)provaLOG_09_28_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      provaLOG_09_28_B.RateTransition = rt_roundd_snf(provaLOG_09_28_DW.mess_len
        + (real_T)provaLOG_09_28_DW.counter_m);
      if (provaLOG_09_28_B.RateTransition < 256.0) {
        if (provaLOG_09_28_B.RateTransition >= 0.0) {
          counter = (uint8_T)provaLOG_09_28_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (find_comma > counter) {
        provaLOG_09_28_B.status = 1;
      } else {
        provaLOG_09_28_B.status = find_comma;
      }

      if (1 > provaLOG_09_28_DW.counter_m) {
        provaLOG_09_28_B.caso = -1;
      } else {
        provaLOG_09_28_B.caso = provaLOG_09_28_DW.counter_m - 1;
      }

      for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <=
           provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
        provaLOG_09_28_DW.message_e[(provaLOG_09_28_B.status +
          provaLOG_09_28_B.f_l) - 1] =
          provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.f_l];
      }

      provaLOG_09_28_DW.Interr_parz = false;
      provaLOG_09_28_B.status = 1;
      for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 100; provaLOG_09_28_B.i
           ++) {
        provaLOG_09_28_B.messaggio_l[provaLOG_09_28_B.i] =
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i];
        provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i] = 0U;
      }

      provaLOG_09_28_DW.mess_len = 0.0;
      provaLOG_09_28_DW.counter_m = 0U;
    } else {
      provaLOG_09_28_DW.Interr_parz = false;
      provaLOG_09_28_B.status = 1;
      memset(&provaLOG_09_28_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      provaLOG_09_28_DW.mess_len = 0.0;
      provaLOG_09_28_DW.counter_m = 0U;
    }
    break;

   case 3:
    provaLOG_09_28_B.RateTransition = rt_roundd_snf(provaLOG_09_28_DW.mess_len +
      1.0);
    if (provaLOG_09_28_B.RateTransition < 256.0) {
      if (provaLOG_09_28_B.RateTransition >= 0.0) {
        find_comma = (uint8_T)provaLOG_09_28_B.RateTransition;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    provaLOG_09_28_B.RateTransition = rt_roundd_snf(provaLOG_09_28_DW.mess_len +
      (real_T)provaLOG_09_28_DW.counter_m);
    if (provaLOG_09_28_B.RateTransition < 256.0) {
      if (provaLOG_09_28_B.RateTransition >= 0.0) {
        counter = (uint8_T)provaLOG_09_28_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (find_comma > counter) {
      provaLOG_09_28_B.i = 1;
    } else {
      provaLOG_09_28_B.i = find_comma;
    }

    if (1 > provaLOG_09_28_DW.counter_m) {
      provaLOG_09_28_B.caso = -1;
    } else {
      provaLOG_09_28_B.caso = provaLOG_09_28_DW.counter_m - 1;
    }

    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <= provaLOG_09_28_B.caso;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_DW.message_e[(provaLOG_09_28_B.i + provaLOG_09_28_B.f_l) -
        1] = provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.f_l];
    }

    provaLOG_09_28_DW.Interr_parz = false;
    provaLOG_09_28_B.status = 1;
    for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 100; provaLOG_09_28_B.i++)
    {
      provaLOG_09_28_B.messaggio_l[provaLOG_09_28_B.i] =
        provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i];
      provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i] = 0U;
    }

    provaLOG_09_28_DW.mess_len = 0.0;
    provaLOG_09_28_DW.counter_m = 0U;
    provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.poss_254[(int32_T)
      provaLOG_09_28_B.num_254 - 1] + 1.0) - 1;
    if (provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.f_l] <= 100) {
      provaLOG_09_28_B.i = (int32_T)(provaLOG_09_28_B.SFunctionBuilder_o1_j
        [(int32_T)(provaLOG_09_28_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)provaLOG_09_28_B.i > 255U) {
        provaLOG_09_28_B.i = 255;
      }

      provaLOG_09_28_B.caso = provaLOG_09_28_B.SFunctionBuilder_o2;
      if (provaLOG_09_28_B.SFunctionBuilder_o2 < 0) {
        provaLOG_09_28_B.caso = 0;
      } else {
        if (provaLOG_09_28_B.SFunctionBuilder_o2 > 255) {
          provaLOG_09_28_B.caso = 255;
        }
      }

      if (provaLOG_09_28_B.i == provaLOG_09_28_B.caso) {
        provaLOG_09_28_B.RateTransition = rt_roundd_snf
          (provaLOG_09_28_B.poss_254[(int32_T)provaLOG_09_28_B.num_254 - 1]);
        if (provaLOG_09_28_B.RateTransition < 256.0) {
          if (provaLOG_09_28_B.RateTransition >= 0.0) {
            counter = (uint8_T)provaLOG_09_28_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provaLOG_09_28_B.f_l = (int32_T)
          (provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.f_l] + 7U);
        if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
          provaLOG_09_28_B.f_l = 255;
        }

        provaLOG_09_28_B.RateTransition = rt_roundd_snf
          (provaLOG_09_28_B.poss_254[(int32_T)provaLOG_09_28_B.num_254 - 1] +
           (real_T)provaLOG_09_28_B.f_l);
        if (provaLOG_09_28_B.RateTransition < 256.0) {
          if (provaLOG_09_28_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)provaLOG_09_28_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          provaLOG_09_28_B.i = 0;
          provaLOG_09_28_B.f_l = 0;
        } else {
          provaLOG_09_28_B.i = counter - 1;
          provaLOG_09_28_B.f_l = find_comma;
        }

        provaLOG_09_28_B.caso = provaLOG_09_28_B.f_l - provaLOG_09_28_B.i;
        for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
             provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.f_l] =
            provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.i +
            provaLOG_09_28_B.f_l];
        }

        for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 100;
             provaLOG_09_28_B.i++) {
          provaLOG_09_28_B.messaggio_2[provaLOG_09_28_B.i] =
            provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i];
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i] = 0U;
        }

        provaLOG_09_28_DW.counter_m = 0U;
        provaLOG_09_28_DW.mess_len = 0.0;
      } else {
        provaLOG_09_28_B.i = (int32_T)(provaLOG_09_28_B.SFunctionBuilder_o1_j
          [(int32_T)(provaLOG_09_28_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)provaLOG_09_28_B.i > 255U) {
          provaLOG_09_28_B.i = 255;
        }

        provaLOG_09_28_B.caso = provaLOG_09_28_B.SFunctionBuilder_o2;
        if (provaLOG_09_28_B.SFunctionBuilder_o2 < 0) {
          provaLOG_09_28_B.caso = 0;
        } else {
          if (provaLOG_09_28_B.SFunctionBuilder_o2 > 255) {
            provaLOG_09_28_B.caso = 255;
          }
        }

        if (provaLOG_09_28_B.i > provaLOG_09_28_B.caso) {
          provaLOG_09_28_DW.mess_len = provaLOG_09_28_B.SFunctionBuilder_o2;
          if (provaLOG_09_28_B.poss_254[(int32_T)provaLOG_09_28_B.num_254 - 1] >
              provaLOG_09_28_DW.mess_len) {
            provaLOG_09_28_B.x_d = 0;
            provaLOG_09_28_B.caso = 0;
          } else {
            provaLOG_09_28_B.x_d = (int32_T)provaLOG_09_28_B.poss_254[(int32_T)
              provaLOG_09_28_B.num_254 - 1] - 1;
            provaLOG_09_28_B.caso = (int32_T)provaLOG_09_28_DW.mess_len;
          }

          provaLOG_09_28_B.caso -= provaLOG_09_28_B.x_d;
          for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i <
               provaLOG_09_28_B.caso; provaLOG_09_28_B.i++) {
            provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i] =
              provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.x_d +
              provaLOG_09_28_B.i];
          }

          provaLOG_09_28_B.f_l = (int32_T)
            (provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.f_l] + 8U);
          if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
            provaLOG_09_28_B.f_l = 255;
          }

          provaLOG_09_28_B.RateTransition = rt_roundd_snf((real_T)
            provaLOG_09_28_B.f_l - provaLOG_09_28_DW.mess_len);
          if (provaLOG_09_28_B.RateTransition < 256.0) {
            if (provaLOG_09_28_B.RateTransition >= 0.0) {
              provaLOG_09_28_DW.counter_m = (uint8_T)
                provaLOG_09_28_B.RateTransition;
            } else {
              provaLOG_09_28_DW.counter_m = 0U;
            }
          } else {
            provaLOG_09_28_DW.counter_m = MAX_uint8_T;
          }

          provaLOG_09_28_DW.Interr_parz = true;
        }
      }
    } else {
      provaLOG_09_28_DW.Interr_parz = false;
      memset(&provaLOG_09_28_B.messaggio_l[0], 0, 100U * sizeof(uint8_T));
      memset(&provaLOG_09_28_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      provaLOG_09_28_DW.counter_m = 0U;
      provaLOG_09_28_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (provaLOG_09_28_B.SFunctionBuilder_o1_j[(int32_T)
        (provaLOG_09_28_B.poss_254[0] + 1.0) - 1] <= 100) {
      provaLOG_09_28_B.RateTransition = rt_roundd_snf(provaLOG_09_28_B.poss_254
        [0]);
      if (provaLOG_09_28_B.RateTransition < 256.0) {
        if (provaLOG_09_28_B.RateTransition >= 0.0) {
          counter = (uint8_T)provaLOG_09_28_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.SFunctionBuilder_o1_j
        [(int32_T)(provaLOG_09_28_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
        provaLOG_09_28_B.f_l = 255;
      }

      provaLOG_09_28_B.RateTransition = rt_roundd_snf(provaLOG_09_28_B.poss_254
        [0] + (real_T)provaLOG_09_28_B.f_l);
      if (provaLOG_09_28_B.RateTransition < 256.0) {
        if (provaLOG_09_28_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)provaLOG_09_28_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (counter > find_comma) {
        provaLOG_09_28_B.status = 0;
        provaLOG_09_28_B.f_l = 0;
      } else {
        provaLOG_09_28_B.status = counter - 1;
        provaLOG_09_28_B.f_l = find_comma;
      }

      provaLOG_09_28_B.caso = provaLOG_09_28_B.f_l - provaLOG_09_28_B.status;
      for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
           provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
        provaLOG_09_28_B.messaggio_l[provaLOG_09_28_B.f_l] =
          provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.status +
          provaLOG_09_28_B.f_l];
      }
    } else {
      provaLOG_09_28_DW.Interr_parz = false;
      memset(&provaLOG_09_28_DW.message_e[0], 0, 100U * sizeof(uint8_T));
    }

    provaLOG_09_28_B.status = 1;
    if ((provaLOG_09_28_B.SFunctionBuilder_o1_j[(int32_T)
         (provaLOG_09_28_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (provaLOG_09_28_B.poss_254[1] - provaLOG_09_28_B.poss_254[0] > 3.0)) {
      provaLOG_09_28_B.RateTransition = rt_roundd_snf((real_T)
        provaLOG_09_28_B.SFunctionBuilder_o2 - provaLOG_09_28_B.poss_254[1]);
      provaLOG_09_28_B.qY = provaLOG_09_28_B.SFunctionBuilder_o1_j[(int32_T)
        (provaLOG_09_28_B.poss_254[1] + 1.0) - 1];
      provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.qY + 7U);
      if (provaLOG_09_28_B.qY + 7U > 255U) {
        provaLOG_09_28_B.f_l = 255;
      }

      if (provaLOG_09_28_B.RateTransition < 2.147483648E+9) {
        if (provaLOG_09_28_B.RateTransition >= -2.147483648E+9) {
          provaLOG_09_28_B.i = (int32_T)provaLOG_09_28_B.RateTransition;
        } else {
          provaLOG_09_28_B.i = MIN_int32_T;
        }
      } else {
        provaLOG_09_28_B.i = MAX_int32_T;
      }

      if (provaLOG_09_28_B.i == provaLOG_09_28_B.f_l) {
        provaLOG_09_28_B.RateTransition = rt_roundd_snf
          (provaLOG_09_28_B.poss_254[1]);
        if (provaLOG_09_28_B.RateTransition < 256.0) {
          if (provaLOG_09_28_B.RateTransition >= 0.0) {
            counter = (uint8_T)provaLOG_09_28_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.qY + 7U);
        if (provaLOG_09_28_B.qY + 7U > 255U) {
          provaLOG_09_28_B.f_l = 255;
        }

        provaLOG_09_28_B.RateTransition = rt_roundd_snf
          (provaLOG_09_28_B.poss_254[1] + (real_T)provaLOG_09_28_B.f_l);
        if (provaLOG_09_28_B.RateTransition < 256.0) {
          if (provaLOG_09_28_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)provaLOG_09_28_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          provaLOG_09_28_B.status = 0;
          provaLOG_09_28_B.f_l = 0;
        } else {
          provaLOG_09_28_B.status = counter - 1;
          provaLOG_09_28_B.f_l = find_comma;
        }

        provaLOG_09_28_B.caso = provaLOG_09_28_B.f_l - provaLOG_09_28_B.status;
        for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
             provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.f_l] =
            provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.status +
            provaLOG_09_28_B.f_l];
        }

        provaLOG_09_28_B.status = 2;
        for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 100;
             provaLOG_09_28_B.i++) {
          provaLOG_09_28_B.messaggio_2[provaLOG_09_28_B.i] =
            provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i];
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.i] = 0U;
        }

        provaLOG_09_28_DW.counter_m = 0U;
        provaLOG_09_28_DW.mess_len = 0.0;
      } else {
        provaLOG_09_28_B.RateTransition = rt_roundd_snf
          (provaLOG_09_28_B.poss_254[1]);
        if (provaLOG_09_28_B.RateTransition < 2.147483648E+9) {
          if (provaLOG_09_28_B.RateTransition >= -2.147483648E+9) {
            provaLOG_09_28_B.f_l = (int32_T)provaLOG_09_28_B.RateTransition;
          } else {
            provaLOG_09_28_B.f_l = MIN_int32_T;
          }
        } else {
          provaLOG_09_28_B.f_l = MAX_int32_T;
        }

        if (provaLOG_09_28_B.f_l > provaLOG_09_28_B.SFunctionBuilder_o2) {
          provaLOG_09_28_B.f_l = -1;
          provaLOG_09_28_B.caso = 0;
        } else {
          provaLOG_09_28_B.f_l -= 2;
          provaLOG_09_28_B.caso = provaLOG_09_28_B.SFunctionBuilder_o2;
        }

        provaLOG_09_28_DW.mess_len = (int8_T)((provaLOG_09_28_B.caso -
          provaLOG_09_28_B.f_l) - 1);
        if (provaLOG_09_28_B.RateTransition < 2.147483648E+9) {
          if (provaLOG_09_28_B.RateTransition >= -2.147483648E+9) {
            provaLOG_09_28_B.f_l = (int32_T)provaLOG_09_28_B.RateTransition;
          } else {
            provaLOG_09_28_B.f_l = MIN_int32_T;
          }
        } else {
          provaLOG_09_28_B.f_l = MAX_int32_T;
        }

        if (provaLOG_09_28_B.f_l > provaLOG_09_28_B.SFunctionBuilder_o2) {
          provaLOG_09_28_B.i = 0;
          provaLOG_09_28_B.f_l = 0;
        } else {
          provaLOG_09_28_B.i = provaLOG_09_28_B.f_l - 1;
          provaLOG_09_28_B.f_l = provaLOG_09_28_B.SFunctionBuilder_o2;
        }

        provaLOG_09_28_B.caso = provaLOG_09_28_B.f_l - provaLOG_09_28_B.i;
        for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
             provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
          provaLOG_09_28_DW.message_e[provaLOG_09_28_B.f_l] =
            provaLOG_09_28_B.SFunctionBuilder_o1_j[provaLOG_09_28_B.i +
            provaLOG_09_28_B.f_l];
        }

        provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.qY + 8U);
        if (provaLOG_09_28_B.qY + 8U > 255U) {
          provaLOG_09_28_B.f_l = 255;
        }

        provaLOG_09_28_B.RateTransition = rt_roundd_snf((real_T)
          provaLOG_09_28_B.f_l - provaLOG_09_28_DW.mess_len);
        if (provaLOG_09_28_B.RateTransition < 256.0) {
          if (provaLOG_09_28_B.RateTransition >= 0.0) {
            provaLOG_09_28_DW.counter_m = (uint8_T)
              provaLOG_09_28_B.RateTransition;
          } else {
            provaLOG_09_28_DW.counter_m = 0U;
          }
        } else {
          provaLOG_09_28_DW.counter_m = MAX_uint8_T;
        }

        provaLOG_09_28_DW.Interr_parz = true;
      }
    } else {
      provaLOG_09_28_DW.Interr_parz = false;
      memset(&provaLOG_09_28_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      provaLOG_09_28_DW.counter_m = 0U;
      provaLOG_09_28_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&provaLOG_09_28_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
       provaLOG_09_28_B.f_l++) {
    provaLOG_09_28_B.buffer[3 * provaLOG_09_28_B.f_l] = 0U;
  }

  for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
       provaLOG_09_28_B.f_l++) {
    for (provaLOG_09_28_B.caso = 0; provaLOG_09_28_B.caso < 2;
         provaLOG_09_28_B.caso++) {
      provaLOG_09_28_B.i = 3 * provaLOG_09_28_B.f_l + provaLOG_09_28_B.caso;
      provaLOG_09_28_B.buffer[provaLOG_09_28_B.i + 1] =
        provaLOG_09_28_DW.Memory4_PreviousInput[provaLOG_09_28_B.i];
    }
  }

  provaLOG_09_28_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (provaLOG_09_28_B.i >= 1)) {
    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.x[provaLOG_09_28_B.f_l] = (provaLOG_09_28_B.buffer[(3 *
        provaLOG_09_28_B.f_l + provaLOG_09_28_B.i) - 1] == 0);
    }

    y = true;
    provaLOG_09_28_B.f_l = 0;
    exitg2 = false;
    while ((!exitg2) && (provaLOG_09_28_B.f_l < 100)) {
      if (!provaLOG_09_28_B.x[provaLOG_09_28_B.f_l]) {
        y = false;
        exitg2 = true;
      } else {
        provaLOG_09_28_B.f_l++;
      }
    }

    if (y) {
      counter = (uint8_T)provaLOG_09_28_B.i;
      exitg1 = true;
    } else {
      provaLOG_09_28_B.i--;
    }
  }

  if (provaLOG_09_28_B.status == 1) {
    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.buffer[(counter + 3 * provaLOG_09_28_B.f_l) - 1] =
        provaLOG_09_28_B.messaggio_l[provaLOG_09_28_B.f_l];
    }
  } else if (provaLOG_09_28_B.status == 2) {
    provaLOG_09_28_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      provaLOG_09_28_B.qY = 0U;
    }

    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.buffer[(counter + 3 * provaLOG_09_28_B.f_l) - 1] =
        provaLOG_09_28_B.messaggio_l[provaLOG_09_28_B.f_l];
      provaLOG_09_28_B.buffer[((int32_T)provaLOG_09_28_B.qY + 3 *
        provaLOG_09_28_B.f_l) - 1] =
        provaLOG_09_28_B.messaggio_2[provaLOG_09_28_B.f_l];
    }
  } else {
    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.buffer[(counter + 3 * provaLOG_09_28_B.f_l) - 1] = 0U;
    }
  }

  for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
       provaLOG_09_28_B.f_l++) {
    provaLOG_09_28_B.mess_out[provaLOG_09_28_B.f_l] =
      provaLOG_09_28_DW.Memory4_PreviousInput[3 * provaLOG_09_28_B.f_l + 2];
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion5'
   */
  if (provaLOG_09_28_B.ByteReversal[0] < 0.0F) {
    provaLOG_09_28_B.f = (real32_T)ceil(provaLOG_09_28_B.ByteReversal[0]);
  } else {
    provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.ByteReversal[0]);
  }

  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[0] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion6'
   */
  if (provaLOG_09_28_B.ByteReversal[1] < 0.0F) {
    provaLOG_09_28_B.f = (real32_T)ceil(provaLOG_09_28_B.ByteReversal[1]);
  } else {
    provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.ByteReversal[1]);
  }

  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[1] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion7'
   */
  if (provaLOG_09_28_B.ByteReversal[2] < 0.0F) {
    provaLOG_09_28_B.f = (real32_T)ceil(provaLOG_09_28_B.ByteReversal[2]);
  } else {
    provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.ByteReversal[2]);
  }

  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[2] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion10'
   */
  if (provaLOG_09_28_B.ByteReversal[3] < 0.0F) {
    provaLOG_09_28_B.f = (real32_T)ceil(provaLOG_09_28_B.ByteReversal[3]);
  } else {
    provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.ByteReversal[3]);
  }

  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[3] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion11'
   */
  if (provaLOG_09_28_B.ByteReversal[4] < 0.0F) {
    provaLOG_09_28_B.f = (real32_T)ceil(provaLOG_09_28_B.ByteReversal[4]);
  } else {
    provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.ByteReversal[4]);
  }

  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[4] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion12'
   */
  if (provaLOG_09_28_B.ByteReversal[5] < 0.0F) {
    provaLOG_09_28_B.f = (real32_T)ceil(provaLOG_09_28_B.ByteReversal[5]);
  } else {
    provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.ByteReversal[5]);
  }

  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[5] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant4'
   */
  if (provaLOG_09_28_P.Constant4_Value_l[0] < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant4_Value_l[0]);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant4_Value_l[0]);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[6] = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant4'
   */
  if (provaLOG_09_28_P.Constant4_Value_l[1] < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant4_Value_l[1]);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant4_Value_l[1]);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[7] = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant4'
   */
  if (provaLOG_09_28_P.Constant4_Value_l[2] < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant4_Value_l[2]);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant4_Value_l[2]);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_m[8] = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S11>/Data Type Conversion4' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion10'
   *  DataTypeConversion: '<S11>/Data Type Conversion11'
   *  DataTypeConversion: '<S11>/Data Type Conversion12'
   *  DataTypeConversion: '<S11>/Data Type Conversion13'
   *  DataTypeConversion: '<S11>/Data Type Conversion14'
   *  DataTypeConversion: '<S11>/Data Type Conversion15'
   */
  provaLOG_09_28_B.DataTypeConversion4[0] = provaLOG_09_28_B.ByteReversal[6];
  provaLOG_09_28_B.DataTypeConversion4[1] = provaLOG_09_28_B.ByteReversal[7];
  provaLOG_09_28_B.DataTypeConversion4[2] = provaLOG_09_28_B.ByteReversal[8];
  provaLOG_09_28_B.DataTypeConversion4[3] = provaLOG_09_28_B.ByteReversal[3];
  provaLOG_09_28_B.DataTypeConversion4[4] = provaLOG_09_28_B.ByteReversal[4];
  provaLOG_09_28_B.DataTypeConversion4[5] = provaLOG_09_28_B.ByteReversal[5];

  /* RateTransition: '<S27>/Rate Transition' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_DW.RateTransition_Buffer0;

  /* Sum: '<S27>/Add1' incorporates:
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Memory: '<S27>/Memory1'
   */
  provaLOG_09_28_B.num_254 = (provaLOG_09_28_P.Constant2_Value_j +
    provaLOG_09_28_P.Constant3_Value_k) +
    provaLOG_09_28_DW.Memory1_PreviousInput;

  /* Switch: '<S27>/Switch' */
  if (provaLOG_09_28_B.num_254 > provaLOG_09_28_P.Switch_Threshold) {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    provaLOG_09_28_DW.Memory1_PreviousInput = provaLOG_09_28_P.Constant2_Value_j;
  } else {
    /* Switch: '<S27>/Switch' */
    provaLOG_09_28_DW.Memory1_PreviousInput = provaLOG_09_28_B.num_254;
  }

  /* End of Switch: '<S27>/Switch' */

  /* MATLAB Function: '<S12>/iflogic_function' */
  if ((provaLOG_09_28_DW.Memory1_PreviousInput == 1.0) ||
      (provaLOG_09_28_DW.Memory1_PreviousInput == 3.0)) {
    provaLOG_09_28_B.iflogic = 26U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 2.0) ||
             (provaLOG_09_28_DW.Memory1_PreviousInput == 4.0)) {
    provaLOG_09_28_B.iflogic = 30U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             (provaLOG_09_28_B.RateTransition == 2.0)) {
    provaLOG_09_28_B.iflogic = 33U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             (provaLOG_09_28_B.RateTransition == 6.0)) {
    provaLOG_09_28_B.iflogic = 34U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             (provaLOG_09_28_B.RateTransition == 0.0)) {
    provaLOG_09_28_B.iflogic = 0U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             ((provaLOG_09_28_B.RateTransition == 1.0) ||
              (provaLOG_09_28_B.RateTransition == 5.0) ||
              (provaLOG_09_28_B.RateTransition == 9.0))) {
    provaLOG_09_28_B.iflogic = 1U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             ((provaLOG_09_28_B.RateTransition == 3.0) ||
              (provaLOG_09_28_B.RateTransition == 8.0))) {
    provaLOG_09_28_B.iflogic = 74U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             (provaLOG_09_28_B.RateTransition == 7.0)) {
    provaLOG_09_28_B.iflogic = 36U;
  } else if ((provaLOG_09_28_DW.Memory1_PreviousInput == 0.0) &&
             (provaLOG_09_28_B.RateTransition == 4.0)) {
    provaLOG_09_28_B.iflogic = 29U;
  } else {
    provaLOG_09_28_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S12>/iflogic_function' */

  /* Sum: '<S27>/Add' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Memory: '<S27>/Memory'
   */
  provaLOG_09_28_DW.Memory_PreviousInput += provaLOG_09_28_P.Constant_Value_m +
    provaLOG_09_28_P.Constant1_Value_l;

  /* Gain: '<S12>/Gain' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain_Gain *
    provaLOG_09_28_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3 = provaLOG_09_28_B.RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (uint32_T)
    provaLOG_09_28_B.RateTransition;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  provaLOG_09_28_B.Add = provaLOG_09_28_DW.Memory4_PreviousInput[5] +
    provaLOG_09_28_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (provaLOG_09_28_B.mess_out[2] != provaLOG_09_28_DW.Memory5_PreviousInput[2])
  {
    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 100;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.x[provaLOG_09_28_B.f_l] =
        (provaLOG_09_28_B.mess_out[provaLOG_09_28_B.f_l] != 0);
    }

    y = true;
    provaLOG_09_28_B.f_l = 0;
    exitg1 = false;
    while ((!exitg1) && (provaLOG_09_28_B.f_l < 100)) {
      if (!provaLOG_09_28_B.x[provaLOG_09_28_B.f_l]) {
        y = false;
        exitg1 = true;
      } else {
        provaLOG_09_28_B.f_l++;
      }
    }

    if (!y) {
      if (provaLOG_09_28_DW.counter > 100) {
        provaLOG_09_28_DW.counter = 0U;
      }

      provaLOG_09_28_B.qY = provaLOG_09_28_DW.counter + 1U;
      if (provaLOG_09_28_DW.counter + 1U > 65535U) {
        provaLOG_09_28_B.qY = 65535U;
      }

      provaLOG_09_28_DW.counter = (uint16_T)provaLOG_09_28_B.qY;
    }
  }

  provaLOG_09_28_B.new_mex = provaLOG_09_28_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  provaLOG_09_28_B.Memory1[0] = provaLOG_09_28_DW.Memory1_PreviousInput_j[0];
  provaLOG_09_28_B.Memory1[1] = provaLOG_09_28_DW.Memory1_PreviousInput_j[1];

  /* Memory: '<Root>/Memory' */
  provaLOG_09_28_B.Memory_p[0] = provaLOG_09_28_DW.Memory_PreviousInput_m[0];
  provaLOG_09_28_B.Memory_p[1] = provaLOG_09_28_DW.Memory_PreviousInput_m[1];
  provaLOG_09_28_B.Memory_p[2] = provaLOG_09_28_DW.Memory_PreviousInput_m[2];
  provaLOG_09_28_B.Memory_p[3] = provaLOG_09_28_DW.Memory_PreviousInput_m[3];

  /* Memory: '<S1>/Memory3' */
  provaLOG_09_28_B.Memory3 = provaLOG_09_28_DW.Memory3_PreviousInput;
  for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 8; provaLOG_09_28_B.i++) {
    /* Memory: '<S1>/Memory' */
    provaLOG_09_28_B.Memory[provaLOG_09_28_B.i] =
      provaLOG_09_28_DW.Memory_PreviousInput_g[provaLOG_09_28_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&provaLOG_09_28_B.mess_out[0], &provaLOG_09_28_B.Add,
     &provaLOG_09_28_B.new_mex, &provaLOG_09_28_P.SIUAVuint8_Value,
     &provaLOG_09_28_B.Memory[0], &provaLOG_09_28_B.Memory1[0],
     &provaLOG_09_28_B.Memory_p[0], &provaLOG_09_28_B.Memory3,
     &provaLOG_09_28_B.SFunction_o1[0], &provaLOG_09_28_B.SFunction_o2,
     &provaLOG_09_28_B.SFunction_o3_m, &provaLOG_09_28_B.SFunction_o4_n[0],
     &provaLOG_09_28_B.SFunction_o5[0], &provaLOG_09_28_B.SFunction_o6,
     &provaLOG_09_28_B.SFunction_o7[0], &provaLOG_09_28_B.SFunction_o8,
     &provaLOG_09_28_B.SFunction_o9[0], &provaLOG_09_28_B.SFunction_o10[0],
     &provaLOG_09_28_B.SFunction_o11[0], &provaLOG_09_28_B.SFunction_o12,
     &provaLOG_09_28_B.SFunction_o13, &provaLOG_09_28_B.SFunction_o14,
     &provaLOG_09_28_B.SFunction_o15, &provaLOG_09_28_B.SFunction_o16,
     &provaLOG_09_28_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 9; provaLOG_09_28_B.i++) {
    provaLOG_09_28_B.Memory2[provaLOG_09_28_B.i] =
      provaLOG_09_28_DW.Memory2_PreviousInput_c[provaLOG_09_28_B.i];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 6; provaLOG_09_28_B.i++) {
    provaLOG_09_28_B.WP_info_in[provaLOG_09_28_B.i] =
      provaLOG_09_28_B.SFunction_o9[provaLOG_09_28_B.i];
  }

  if ((!provaLOG_09_28_DW.WP_dbP_not_empty) || ((provaLOG_09_28_B.SFunction_o7[0]
        == 3) && (provaLOG_09_28_B.SFunction_o7[1] == 250))) {
    memset(&provaLOG_09_28_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    provaLOG_09_28_DW.WP_dbP_not_empty = true;
    memset(&provaLOG_09_28_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!provaLOG_09_28_DW.WP_dbP_AL_not_empty) ||
      ((provaLOG_09_28_B.SFunction_o7[0] == 3) &&
       (provaLOG_09_28_B.SFunction_o7[1] == 250))) {
    memset(&provaLOG_09_28_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    provaLOG_09_28_DW.WP_dbP_AL_not_empty = true;
  }

  provaLOG_09_28_B.GC_info[0] = provaLOG_09_28_B.SFunction_o7[0];
  provaLOG_09_28_B.GC_info[1] = provaLOG_09_28_B.SFunction_o7[1];
  provaLOG_09_28_B.GC_info[2] = provaLOG_09_28_B.SFunction_o11[0];
  if (provaLOG_09_28_B.GC_info[0] == 1) {
    if ((provaLOG_09_28_B.GC_info[1] > 0) && (provaLOG_09_28_B.GC_info[1] <= 7))
    {
      if ((real32_T)fabs(provaLOG_09_28_B.SFunction_o8) > 0.0F) {
        provaLOG_09_28_DW.riferimenti[provaLOG_09_28_B.GC_info[1] - 1] = 1.0F;
      } else {
        if (provaLOG_09_28_B.SFunction_o8 == 0.0F) {
          provaLOG_09_28_DW.riferimenti[provaLOG_09_28_B.GC_info[1] - 1] = 0.0F;
        }
      }
    } else {
      if ((provaLOG_09_28_B.GC_info[1] > 7) && (provaLOG_09_28_B.GC_info[1] < 12))
      {
        provaLOG_09_28_DW.riferimenti[provaLOG_09_28_B.GC_info[1] - 1] =
          provaLOG_09_28_B.SFunction_o8;
      }
    }
  }

  if (provaLOG_09_28_B.SFunction_o12 == 13) {
    provaLOG_09_28_DW.riferimenti[provaLOG_09_28_B.SFunction_o12 - 1] =
      provaLOG_09_28_B.SFunction_o13;
  }

  memcpy(&provaLOG_09_28_B.Val_out_MAV[0], &provaLOG_09_28_DW.riferimenti[0],
         sizeof(real32_T) << 4U);
  if ((provaLOG_09_28_B.GC_info[0] == 3) && (provaLOG_09_28_B.GC_info[1] == 200))
  {
    if (provaLOG_09_28_B.SFunction_o9[0] > 6) {
      provaLOG_09_28_B.WP_info_in[0] = 6U;
    }

    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 6;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_DW.WP_dbI[provaLOG_09_28_B.f_l] =
        provaLOG_09_28_B.WP_info_in[0];
    }
  }

  if ((provaLOG_09_28_B.GC_info[0] == 3) && (provaLOG_09_28_B.GC_info[1] < 200))
  {
    if (provaLOG_09_28_B.SFunction_o10[1] == 0.0F) {
      provaLOG_09_28_B.qY = provaLOG_09_28_B.SFunction_o9[1] + 1U;
      if (provaLOG_09_28_B.SFunction_o9[1] + 1U > 65535U) {
        provaLOG_09_28_B.qY = 65535U;
      }

      for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 7;
           provaLOG_09_28_B.f_l++) {
        provaLOG_09_28_DW.WP_dbP[((int32_T)provaLOG_09_28_B.qY + 6 *
          provaLOG_09_28_B.f_l) - 1] =
          provaLOG_09_28_B.SFunction_o10[provaLOG_09_28_B.f_l];
      }

      provaLOG_09_28_B.qY = provaLOG_09_28_B.SFunction_o9[1] + 1U;
      if (provaLOG_09_28_B.SFunction_o9[1] + 1U > 65535U) {
        provaLOG_09_28_B.qY = 65535U;
      }

      for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 6;
           provaLOG_09_28_B.f_l++) {
        provaLOG_09_28_DW.WP_dbI[((int32_T)provaLOG_09_28_B.qY + 6 *
          (provaLOG_09_28_B.f_l + 1)) - 1] =
          provaLOG_09_28_B.WP_info_in[provaLOG_09_28_B.f_l + 1];
      }
    } else {
      provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_B.SFunction_o10[0] + 1.0F);
      for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 7; provaLOG_09_28_B.i++)
      {
        provaLOG_09_28_DW.WP_dbP_AL[(provaLOG_09_28_B.f_l + 6 *
          provaLOG_09_28_B.i) - 1] =
          provaLOG_09_28_B.SFunction_o10[provaLOG_09_28_B.i];
      }

      provaLOG_09_28_B.qY = provaLOG_09_28_B.SFunction_o9[1] + 1U;
      if (provaLOG_09_28_B.SFunction_o9[1] + 1U > 65535U) {
        provaLOG_09_28_B.qY = 65535U;
      }

      for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 6;
           provaLOG_09_28_B.f_l++) {
        provaLOG_09_28_DW.WP_dbI[((int32_T)provaLOG_09_28_B.qY + 6 *
          (provaLOG_09_28_B.f_l + 1)) - 1] =
          provaLOG_09_28_B.WP_info_in[provaLOG_09_28_B.f_l + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provaLOG_09_28_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((provaLOG_09_28_B.SFunction_o6 == 0) && (provaLOG_09_28_B.SFunction_o3_m ==
       0)) {
    provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 0U;
    provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provaLOG_09_28_DW.Memory3_PreviousInput = 0U;
  } else if ((provaLOG_09_28_B.SFunction_o6 == 0) &&
             (provaLOG_09_28_B.SFunction_o3_m == 3)) {
    provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 0U;
    provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provaLOG_09_28_DW.Memory3_PreviousInput = 0U;
    provaLOG_09_28_DW.test1 = 0.0;
  } else if ((provaLOG_09_28_B.SFunction_o6 == 0) &&
             (provaLOG_09_28_B.SFunction_o3_m == 2)) {
    provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 0U;
    provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    provaLOG_09_28_DW.Memory3_PreviousInput = 0U;
    provaLOG_09_28_DW.test1 = 0.0;
  } else if ((provaLOG_09_28_B.SFunction_o6 == 0) &&
             (provaLOG_09_28_B.SFunction_o3_m == 1)) {
    provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 0U;
    provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    provaLOG_09_28_DW.Memory3_PreviousInput = 0U;
    provaLOG_09_28_DW.test1 = 1.0;
  } else {
    switch (provaLOG_09_28_B.SFunction_o6) {
     case 192:
      provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 192U;
      provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      provaLOG_09_28_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 208U;
      provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      provaLOG_09_28_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((provaLOG_09_28_B.SFunction_o6 == 220) &&
          (provaLOG_09_28_B.SFunction_o3_m != 5)) {
        if ((provaLOG_09_28_B.Memory2[0] == 0) && (provaLOG_09_28_B.Memory2[1] ==
             0) && ((provaLOG_09_28_B.Memory2[2] == 1) ||
                    (provaLOG_09_28_B.Memory2[3] == 1) ||
                    (provaLOG_09_28_B.Memory2[4] == 1) ||
                    (provaLOG_09_28_B.Memory2[5] == 1) ||
                    (provaLOG_09_28_B.Memory2[6] == 1) ||
                    (provaLOG_09_28_B.Memory2[7] == 1))) {
          provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 220U;
          provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          provaLOG_09_28_DW.Memory3_PreviousInput = 220U;
        } else if ((provaLOG_09_28_B.Memory2[0] == 0) &&
                   (provaLOG_09_28_B.Memory2[1] == 1) &&
                   ((provaLOG_09_28_B.Memory2[2] == 1) ||
                    (provaLOG_09_28_B.Memory2[3] == 1) ||
                    (provaLOG_09_28_B.Memory2[4] == 1) ||
                    (provaLOG_09_28_B.Memory2[5] == 1) ||
                    (provaLOG_09_28_B.Memory2[6] == 1) ||
                    (provaLOG_09_28_B.Memory2[7] == 1))) {
          provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 220U;
          provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          provaLOG_09_28_DW.Memory3_PreviousInput = 220U;
        } else {
          provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 208U;
          provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          provaLOG_09_28_DW.Memory3_PreviousInput = 208U;
        }
      } else if (provaLOG_09_28_B.SFunction_o3_m == 5) {
        provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 220U;
        provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        provaLOG_09_28_DW.Memory1_PreviousInput_j[0] = 192U;
        provaLOG_09_28_DW.Memory1_PreviousInput_j[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  provaLOG_09_28_B.qY = 100U * provaLOG_09_28_B.SFunction_o11[5];
  if (provaLOG_09_28_B.qY > 65535U) {
    provaLOG_09_28_B.qY = 65535U;
  }

  if (provaLOG_09_28_B.SFunction_o11[4] == 0) {
    if ((uint16_T)provaLOG_09_28_B.qY == 0) {
      provaLOG_09_28_B.z = 0U;
    } else {
      provaLOG_09_28_B.z = MAX_uint16_T;
    }
  } else {
    provaLOG_09_28_B.z = (uint16_T)(provaLOG_09_28_B.SFunction_o11[4] == 0U ?
      MAX_uint32_T : (uint32_T)(uint16_T)provaLOG_09_28_B.qY /
      provaLOG_09_28_B.SFunction_o11[4]);
    provaLOG_09_28_B.x_e = (uint16_T)((uint32_T)(uint16_T)provaLOG_09_28_B.qY -
      (uint16_T)((uint32_T)provaLOG_09_28_B.z * provaLOG_09_28_B.SFunction_o11[4]));
    if ((provaLOG_09_28_B.x_e > 0) && (provaLOG_09_28_B.x_e >= (int32_T)
         ((uint32_T)provaLOG_09_28_B.SFunction_o11[4] >> 1) +
         (provaLOG_09_28_B.SFunction_o11[4] & 1))) {
      provaLOG_09_28_B.z++;
    }
  }

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 6; provaLOG_09_28_B.f_l
       ++) {
    provaLOG_09_28_B.WP_info[provaLOG_09_28_B.f_l] = provaLOG_09_28_DW.WP_dbI[6 *
      provaLOG_09_28_B.f_l];
  }

  for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 7; provaLOG_09_28_B.f_l
       ++) {
    provaLOG_09_28_B.WP_param[provaLOG_09_28_B.f_l] = provaLOG_09_28_DW.WP_dbP[6
      * provaLOG_09_28_B.f_l];
  }

  if ((provaLOG_09_28_B.GC_info[0] == 2) && (provaLOG_09_28_B.GC_info[1] < 6)) {
    provaLOG_09_28_B.qY = provaLOG_09_28_B.GC_info[1] + 1U;
    if (provaLOG_09_28_B.GC_info[1] + 1U > 65535U) {
      provaLOG_09_28_B.qY = 65535U;
    }

    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 6;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.WP_info[provaLOG_09_28_B.f_l] = provaLOG_09_28_DW.WP_dbI
        [(6 * provaLOG_09_28_B.f_l + (int32_T)provaLOG_09_28_B.qY) - 1];
    }

    provaLOG_09_28_B.qY = provaLOG_09_28_B.GC_info[1] + 1U;
    if (provaLOG_09_28_B.GC_info[1] + 1U > 65535U) {
      provaLOG_09_28_B.qY = 65535U;
    }

    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 7;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.WP_param[provaLOG_09_28_B.f_l] =
        provaLOG_09_28_DW.WP_dbP[(6 * provaLOG_09_28_B.f_l + (int32_T)
        provaLOG_09_28_B.qY) - 1];
    }
  }

  if ((provaLOG_09_28_B.GC_info[0] == 3) && (provaLOG_09_28_B.GC_info[1] < 200))
  {
    provaLOG_09_28_B.qY = provaLOG_09_28_B.GC_info[1] + 1U;
    if (provaLOG_09_28_B.GC_info[1] + 1U > 65535U) {
      provaLOG_09_28_B.qY = 65535U;
    }

    for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 6;
         provaLOG_09_28_B.f_l++) {
      provaLOG_09_28_B.WP_info[provaLOG_09_28_B.f_l] = provaLOG_09_28_DW.WP_dbI
        [(6 * provaLOG_09_28_B.f_l + (int32_T)provaLOG_09_28_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S16>/MATLAB Function' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  Constant: '<S14>/onboard_control_sensor_present uint32'
   */
  provaLOG_09_28_B.onboard[0] =
    provaLOG_09_28_P.onboard_control_sensor_presentu[0];
  provaLOG_09_28_B.onboard[1] =
    provaLOG_09_28_P.onboard_control_sensor_presentu[1];
  provaLOG_09_28_B.onboard[2] =
    provaLOG_09_28_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S14>/Gain' incorporates:
   *  Constant: '<S14>/Constant'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Gain_Gain_f *
    provaLOG_09_28_P.Constant_Value_e);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Constant: '<S14>/load uint16'
   *  Gain: '<S14>/Gain'
   */
  provaLOG_09_28_B.LVDE[0] = provaLOG_09_28_P.loaduint16_Value;
  provaLOG_09_28_B.LVDE[1] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  provaLOG_09_28_B.qY = 10U * provaLOG_09_28_B.z;
  if (provaLOG_09_28_B.qY > 65535U) {
    provaLOG_09_28_B.qY = 65535U;
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Constant: '<S14>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provaLOG_09_28_B.LVDE[2] = (uint16_T)provaLOG_09_28_B.qY;
  provaLOG_09_28_B.LVDE[3] = provaLOG_09_28_B.SFunction_o11[6];
  provaLOG_09_28_B.LVDE[4] = provaLOG_09_28_B.SFunction_o11[2];
  provaLOG_09_28_B.LVDE[5] = provaLOG_09_28_P._Value;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_k[0]);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  provaLOG_09_28_B.LVDE[6] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_k[1]);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  provaLOG_09_28_B.LVDE[7] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* Gain: '<S14>/Gain2' incorporates:
   *  Constant: '<S14>/Constant3'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Gain2_Gain *
    provaLOG_09_28_P.Constant3_Value_g);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Gain: '<S14>/Gain1'
   *  Gain: '<S14>/Gain2'
   */
  provaLOG_09_28_B.B_Current = (int16_T)(((provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(int16_T)(uint16_T)provaLOG_09_28_B.RateTransition) *
    provaLOG_09_28_P.Gain1_Gain_f) >> 18);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<S14>/Constant2'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant2_Value_g);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion3' */
  provaLOG_09_28_B.B_Remaining = (int8_T)(provaLOG_09_28_B.RateTransition < 0.0 ?
    (int32_T)(int8_T)-(int8_T)(uint8_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(int8_T)(uint8_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant_Value_n);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  provaLOG_09_28_B.DataTypeConversion = provaLOG_09_28_B.RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (uint32_T)
    provaLOG_09_28_B.RateTransition;

  /* MATLAB Function: '<S10>/Alarm set' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_H_mav[0] = provaLOG_09_28_DW.Memory1_PreviousInput_j[0];
  rtb_H_mav[1] = provaLOG_09_28_DW.Memory1_PreviousInput_j[1];
  if (provaLOG_09_28_P.Constant1_Value_g[0] == 1.0) {
    rtb_H_mav[0] = 220U;
    rtb_H_mav[1] = 5U;
  }

  if (provaLOG_09_28_P.Constant1_Value_g[1] == 1.0) {
    rtb_H_mav[0] = 216U;
    rtb_H_mav[1] = 4U;
  }

  /* End of MATLAB Function: '<S10>/Alarm set' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S10>/Type fixed_wing Autopilot generic'
   */
  provaLOG_09_28_B.DataTypeConversion1_n[0] =
    provaLOG_09_28_P.Typefixed_wingAutopilotgeneric_[0];
  provaLOG_09_28_B.DataTypeConversion1_n[1] =
    provaLOG_09_28_P.Typefixed_wingAutopilotgeneric_[1];
  provaLOG_09_28_B.DataTypeConversion1_n[2] = rtb_H_mav[0];
  provaLOG_09_28_B.DataTypeConversion1_n[3] = rtb_H_mav[1];

  /* MATLABSystem: '<S19>/Serial Receive1' */
  if (provaLOG_09_28_DW.obj_m.Protocol !=
      provaLOG_09_28_P.SerialReceive1_Protocol) {
    provaLOG_09_28_DW.obj_m.Protocol = provaLOG_09_28_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(0, provaLOG_09_28_DW.obj_m.DataSizeInBytes,
                 &provaLOG_09_28_B.b_dataOut[0], &counter);

  /* Outputs for Enabled SubSystem: '<S19>/Subsystem2' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (counter > 0) {
    /* MATLAB Function: '<S21>/Create_message' */
    counter = 0U;
    if (!provaLOG_09_28_DW.start_found) {
      provaLOG_09_28_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (provaLOG_09_28_B.i - 1 < 32)) {
        if (provaLOG_09_28_B.b_dataOut[(uint8_T)provaLOG_09_28_B.i - 1] == 36) {
          provaLOG_09_28_B.caso = 32 - (uint8_T)provaLOG_09_28_B.i;
          for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <=
               provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
            provaLOG_09_28_DW.message[provaLOG_09_28_B.f_l] =
              provaLOG_09_28_B.b_dataOut[((uint8_T)provaLOG_09_28_B.i +
              provaLOG_09_28_B.f_l) - 1];
          }

          provaLOG_09_28_DW.counter_k = (uint8_T)(33 - (uint8_T)
            provaLOG_09_28_B.i);
          provaLOG_09_28_DW.start_found = true;
          exitg1 = true;
        } else {
          provaLOG_09_28_B.i++;
        }
      }
    } else {
      provaLOG_09_28_B.f_l = 1;
      exitg1 = false;
      while ((!exitg1) && (provaLOG_09_28_B.f_l - 1 < 32)) {
        if (provaLOG_09_28_B.b_dataOut[(uint8_T)provaLOG_09_28_B.f_l - 1] == 13)
        {
          provaLOG_09_28_DW.end_found = true;
          counter = (uint8_T)provaLOG_09_28_B.f_l;
          exitg1 = true;
        } else {
          provaLOG_09_28_B.f_l++;
        }
      }

      if (provaLOG_09_28_DW.end_found) {
        if (1 > counter) {
          provaLOG_09_28_B.caso = -1;
        } else {
          provaLOG_09_28_B.caso = counter - 1;
        }

        for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <=
             provaLOG_09_28_B.caso; provaLOG_09_28_B.f_l++) {
          provaLOG_09_28_B.i = (int32_T)(((uint32_T)provaLOG_09_28_B.f_l +
            provaLOG_09_28_DW.counter_k) + 1U);
          if ((uint32_T)provaLOG_09_28_B.i > 255U) {
            provaLOG_09_28_B.i = 255;
          }

          provaLOG_09_28_DW.message[provaLOG_09_28_B.i - 1] =
            provaLOG_09_28_B.b_dataOut[provaLOG_09_28_B.f_l];
        }

        memcpy(&provaLOG_09_28_B.messaggio_c[0], &provaLOG_09_28_DW.message[0],
               80U * sizeof(uint8_T));
        provaLOG_09_28_DW.end_found = false;
        provaLOG_09_28_DW.counter_k = (uint8_T)(32 - counter);
        if (counter == 32) {
          provaLOG_09_28_DW.start_found = false;
          memset(&provaLOG_09_28_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          provaLOG_09_28_DW.start_found = true;
          provaLOG_09_28_B.caso = -counter;
          for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <=
               provaLOG_09_28_B.caso + 31; provaLOG_09_28_B.f_l++) {
            provaLOG_09_28_DW.message[provaLOG_09_28_B.f_l] =
              provaLOG_09_28_B.b_dataOut[counter + provaLOG_09_28_B.f_l];
          }

          provaLOG_09_28_B.f_l = counter + 48;
          if (0 <= provaLOG_09_28_B.f_l - 1) {
            memset(&provaLOG_09_28_DW.message[-counter + 32], 0,
                   ((provaLOG_09_28_B.f_l - counter) + counter) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S21>/Subsystem' incorporates:
         *  EnablePort: '<S23>/Enable'
         */
        /* MATLAB Function: '<S23>/MATLAB Function' */
        counter = 0U;
        find_comma = 0U;
        provaLOG_09_28_B.indice_dimario = 0U;
        for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 80; provaLOG_09_28_B.i
             ++) {
          messaggio = (int8_T)provaLOG_09_28_B.messaggio_c[provaLOG_09_28_B.i];
          if (messaggio == '$') {
            provaLOG_09_28_B.f_l = (int32_T)(counter + 1U);
            if (counter + 1U > 255U) {
              provaLOG_09_28_B.f_l = 255;
            }

            counter = (uint8_T)provaLOG_09_28_B.f_l;
          }

          if (messaggio == ',') {
            provaLOG_09_28_B.f_l = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              provaLOG_09_28_B.f_l = 255;
            }

            find_comma = (uint8_T)provaLOG_09_28_B.f_l;
          }

          provaLOG_09_28_B.messaggio[provaLOG_09_28_B.i] = messaggio;
        }

        if ((counter == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
               provaLOG_09_28_B.f_l++) {
            provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
              (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == '$');
          }

          provaLOG_09_28_eml_find(provaLOG_09_28_B.messaggio_m,
            &provaLOG_09_28_B.eb_data, provaLOG_09_28_B.eb_size);
          provaLOG_09_28_B.status = provaLOG_09_28_B.eb_data;
          for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 5;
               provaLOG_09_28_B.f_l++) {
            messaggio = provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l +
              provaLOG_09_28_B.status];
            provaLOG_09_28_B.mess_type_d[provaLOG_09_28_B.f_l] = (messaggio ==
              bb[provaLOG_09_28_B.f_l]);
            provaLOG_09_28_B.mess_type[provaLOG_09_28_B.f_l] = messaggio;
          }

          if (provaLOG_09_28_ifWhileCond_h(provaLOG_09_28_B.mess_type_d)) {
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
                 provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
                (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == ',');
            }

            provaLOG_09_28_eml_find_a(provaLOG_09_28_B.messaggio_m,
              provaLOG_09_28_B.comma_gga_data, provaLOG_09_28_B.eb_size);
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
                 provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
                (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == '*');
            }

            provaLOG_09_28_eml_find_a(provaLOG_09_28_B.messaggio_m,
              provaLOG_09_28_B.star_data, provaLOG_09_28_B.star_size);
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
                 provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
                (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == '$');
            }

            provaLOG_09_28_eml_find_a(provaLOG_09_28_B.messaggio_m,
              provaLOG_09_28_B.fb_data, provaLOG_09_28_B.star_size);
            provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double
              (&provaLOG_09_28_B.messaggio[provaLOG_09_28_B.comma_gga_data[2]]);
            if ((real_T)provaLOG_09_28_B.comma_gga_data[2] + 3.0 > (real_T)
                provaLOG_09_28_B.comma_gga_data[3] - 1.0) {
              provaLOG_09_28_B.caso = 0;
              provaLOG_09_28_B.f_l = 0;
            } else {
              provaLOG_09_28_B.caso = provaLOG_09_28_B.comma_gga_data[2] + 2;
              provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[3] - 1;
            }

            provaLOG_09_28_B.messaggio_size[0] = 1;
            provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
              provaLOG_09_28_B.caso;
            provaLOG_09_28_B.messaggio_size[1] = provaLOG_09_28_B.status;
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                 provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                provaLOG_09_28_B.f_l];
            }

            provaLOG_09_28_B.b_x = provaLOG_09_28_str2double_f
              (provaLOG_09_28_B.messaggio_data, provaLOG_09_28_B.messaggio_size);
            if (provaLOG_09_28_B.b_x.im == 0.0) {
              provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
            } else if (provaLOG_09_28_B.b_x.re == 0.0) {
              provaLOG_09_28_B.RateTransition = 0.0;
            } else {
              provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
            }

            provaLOG_09_28_B.num_254 = provaLOG_09_28_B.Lat_1.re +
              provaLOG_09_28_B.RateTransition;
            provaLOG_09_28_B.caso = provaLOG_09_28_B.eb_size[0] *
              provaLOG_09_28_B.eb_size[1] - 1;
            if (0 <= provaLOG_09_28_B.caso) {
              memcpy(&provaLOG_09_28_B.tmp_data[0],
                     &provaLOG_09_28_B.comma_gga_data[0], (provaLOG_09_28_B.caso
                      + 1) * sizeof(int32_T));
            }

            if (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.tmp_data[3]] == 'S')
            {
              provaLOG_09_28_B.num_254 = -provaLOG_09_28_B.num_254;
            }

            provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_ft
              (&provaLOG_09_28_B.messaggio[provaLOG_09_28_B.comma_gga_data[4]]);
            if ((real_T)provaLOG_09_28_B.comma_gga_data[4] + 4.0 > (real_T)
                provaLOG_09_28_B.comma_gga_data[5] - 1.0) {
              provaLOG_09_28_B.i = 0;
              provaLOG_09_28_B.f_l = 0;
            } else {
              provaLOG_09_28_B.i = provaLOG_09_28_B.comma_gga_data[4] + 3;
              provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[5] - 1;
            }

            provaLOG_09_28_B.messaggio_size_k[0] = 1;
            provaLOG_09_28_B.status = provaLOG_09_28_B.f_l - provaLOG_09_28_B.i;
            provaLOG_09_28_B.messaggio_size_k[1] = provaLOG_09_28_B.status;
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                 provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                provaLOG_09_28_B.messaggio[provaLOG_09_28_B.i +
                provaLOG_09_28_B.f_l];
            }

            provaLOG_09_28_B.b_x = provaLOG_09_28_str2double_f
              (provaLOG_09_28_B.messaggio_data,
               provaLOG_09_28_B.messaggio_size_k);
            if (provaLOG_09_28_B.b_x.im == 0.0) {
              provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
            } else if (provaLOG_09_28_B.b_x.re == 0.0) {
              provaLOG_09_28_B.RateTransition = 0.0;
            } else {
              provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
            }

            provaLOG_09_28_B.RateTransition += provaLOG_09_28_B.Lat_1.re;
            if (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.tmp_data[5]] == 'W')
            {
              provaLOG_09_28_B.RateTransition = -provaLOG_09_28_B.RateTransition;
            }

            if ((real_T)provaLOG_09_28_B.comma_gga_data[6] + 1.0 > (real_T)
                provaLOG_09_28_B.comma_gga_data[7] - 1.0) {
              provaLOG_09_28_B.i = 0;
              provaLOG_09_28_B.f_l = 0;
            } else {
              provaLOG_09_28_B.i = provaLOG_09_28_B.comma_gga_data[6];
              provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[7] - 1;
            }

            provaLOG_09_28_B.messaggio_size_c[0] = 1;
            provaLOG_09_28_B.status = provaLOG_09_28_B.f_l - provaLOG_09_28_B.i;
            provaLOG_09_28_B.messaggio_size_c[1] = provaLOG_09_28_B.status;
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                 provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                provaLOG_09_28_B.messaggio[provaLOG_09_28_B.i +
                provaLOG_09_28_B.f_l];
            }

            provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_f
              (provaLOG_09_28_B.messaggio_data,
               provaLOG_09_28_B.messaggio_size_c);

            /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
            provaLOG_09_28_B.ComplextoRealImag[2] = provaLOG_09_28_B.Lat_1.re;
            if ((real_T)provaLOG_09_28_B.comma_gga_data[7] + 1.0 > (real_T)
                provaLOG_09_28_B.comma_gga_data[8] - 1.0) {
              provaLOG_09_28_B.caso = 0;
              provaLOG_09_28_B.f_l = 0;
            } else {
              provaLOG_09_28_B.caso = provaLOG_09_28_B.comma_gga_data[7];
              provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[8] - 1;
            }

            provaLOG_09_28_B.messaggio_size_b[0] = 1;
            provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
              provaLOG_09_28_B.caso;
            provaLOG_09_28_B.messaggio_size_b[1] = provaLOG_09_28_B.status;
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                 provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                provaLOG_09_28_B.f_l];
            }

            provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_f
              (provaLOG_09_28_B.messaggio_data,
               provaLOG_09_28_B.messaggio_size_b);

            /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
            provaLOG_09_28_B.ComplextoRealImag[4] = provaLOG_09_28_B.Lat_1.re;
            if ((real_T)provaLOG_09_28_B.comma_gga_data[9] + 1.0 > (real_T)
                provaLOG_09_28_B.comma_gga_data[10] - 1.0) {
              provaLOG_09_28_B.caso = 0;
              provaLOG_09_28_B.f_l = 0;
            } else {
              provaLOG_09_28_B.caso = provaLOG_09_28_B.comma_gga_data[9];
              provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[10] - 1;
            }

            provaLOG_09_28_B.messaggio_size_p[0] = 1;
            provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
              provaLOG_09_28_B.caso;
            provaLOG_09_28_B.messaggio_size_p[1] = provaLOG_09_28_B.status;
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                 provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                provaLOG_09_28_B.f_l];
            }

            provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_f
              (provaLOG_09_28_B.messaggio_data,
               provaLOG_09_28_B.messaggio_size_p);

            /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
            provaLOG_09_28_B.ComplextoRealImag[3] = provaLOG_09_28_B.Lat_1.re;
            if (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.tmp_data[10]] == 'W')
            {
              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[3] = -provaLOG_09_28_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
            provaLOG_09_28_B.ComplextoRealImag[5] =
              provaLOG_09_28_DW.Memory_PreviousInput_i[5];
            provaLOG_09_28_B.ComplextoRealImag[6] =
              provaLOG_09_28_DW.Memory_PreviousInput_i[6];
            provaLOG_09_28_B.ComplextoRealImag[7] =
              provaLOG_09_28_DW.Memory_PreviousInput_i[7];
            provaLOG_09_28_B.ComplextoRealImag[8] =
              provaLOG_09_28_DW.Memory_PreviousInput_i[8];
            if ((real_T)provaLOG_09_28_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)provaLOG_09_28_B.star_data[0] + 1.0 >= 0.0) {
                counter = (uint8_T)((real_T)provaLOG_09_28_B.star_data[0] + 1.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[0] = provaLOG_09_28_B.messaggio[counter - 1];
            if ((real_T)provaLOG_09_28_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)provaLOG_09_28_B.star_data[0] + 2.0 >= 0.0) {
                counter = (uint8_T)((real_T)provaLOG_09_28_B.star_data[0] + 2.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[1] = provaLOG_09_28_B.messaggio[counter - 1];
            if ((real_T)provaLOG_09_28_B.fb_data[0] + 1.0 > (real_T)
                provaLOG_09_28_B.star_data[0] - 1.0) {
              provaLOG_09_28_B.caso = 0;
              provaLOG_09_28_B.status = 0;
            } else {
              provaLOG_09_28_B.caso = provaLOG_09_28_B.fb_data[0];
              provaLOG_09_28_B.status = provaLOG_09_28_B.star_data[0] - 1;
            }

            provaLOG_09_28_B.status -= provaLOG_09_28_B.caso;
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                 provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.NMEA_gga_string_data[provaLOG_09_28_B.f_l] =
                (uint8_T)provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                provaLOG_09_28_B.f_l];
            }

            counter = 0U;
            provaLOG_09_28_B.f_l = 0;
            while (provaLOG_09_28_B.f_l <= provaLOG_09_28_B.status - 1) {
              counter ^=
                provaLOG_09_28_B.NMEA_gga_string_data[provaLOG_09_28_B.f_l];
              provaLOG_09_28_B.f_l++;
            }

            if (counter != provaLOG_09_28_hex2dec(ck_ric)) {
              provaLOG_09_28_B.num_254 =
                provaLOG_09_28_DW.Memory_PreviousInput_i[0];
              provaLOG_09_28_B.RateTransition =
                provaLOG_09_28_DW.Memory_PreviousInput_i[1];

              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[2] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[2];
              provaLOG_09_28_B.ComplextoRealImag[3] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[3];
              provaLOG_09_28_B.ComplextoRealImag[4] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[4];
              provaLOG_09_28_B.indice_dimario = 10U;
            }
          } else {
            for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 5;
                 provaLOG_09_28_B.f_l++) {
              provaLOG_09_28_B.mess_type_d[provaLOG_09_28_B.f_l] =
                (provaLOG_09_28_B.mess_type[provaLOG_09_28_B.f_l] ==
                 cb[provaLOG_09_28_B.f_l]);
            }

            if (provaLOG_09_28_ifWhileCond_h(provaLOG_09_28_B.mess_type_d)) {
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
                   provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
                  (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == ',');
              }

              provaLOG_09_28_eml_find_a(provaLOG_09_28_B.messaggio_m,
                provaLOG_09_28_B.comma_gga_data, provaLOG_09_28_B.eb_size);
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
                   provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
                  (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == '*');
              }

              provaLOG_09_28_eml_find_a(provaLOG_09_28_B.messaggio_m,
                provaLOG_09_28_B.star_data, provaLOG_09_28_B.star_size);
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l < 80;
                   provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_m[provaLOG_09_28_B.f_l] =
                  (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.f_l] == '$');
              }

              provaLOG_09_28_eml_find_a(provaLOG_09_28_B.messaggio_m,
                provaLOG_09_28_B.fb_data, provaLOG_09_28_B.star_size);
              provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double
                (&provaLOG_09_28_B.messaggio[provaLOG_09_28_B.comma_gga_data[1]]);
              if ((real_T)provaLOG_09_28_B.comma_gga_data[1] + 3.0 > (real_T)
                  provaLOG_09_28_B.comma_gga_data[2] - 1.0) {
                provaLOG_09_28_B.caso = 0;
                provaLOG_09_28_B.f_l = 0;
              } else {
                provaLOG_09_28_B.caso = provaLOG_09_28_B.comma_gga_data[1] + 2;
                provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[2] - 1;
              }

              provaLOG_09_28_B.messaggio_size[0] = 1;
              provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
                provaLOG_09_28_B.caso;
              provaLOG_09_28_B.messaggio_size[1] = provaLOG_09_28_B.status;
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                   provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                  provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                  provaLOG_09_28_B.f_l];
              }

              provaLOG_09_28_B.b_x = provaLOG_09_28_str2double_f
                (provaLOG_09_28_B.messaggio_data,
                 provaLOG_09_28_B.messaggio_size);
              if (provaLOG_09_28_B.b_x.im == 0.0) {
                provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
              } else if (provaLOG_09_28_B.b_x.re == 0.0) {
                provaLOG_09_28_B.RateTransition = 0.0;
              } else {
                provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
              }

              provaLOG_09_28_B.num_254 = provaLOG_09_28_B.Lat_1.re +
                provaLOG_09_28_B.RateTransition;
              provaLOG_09_28_B.caso = provaLOG_09_28_B.eb_size[0] *
                provaLOG_09_28_B.eb_size[1] - 1;
              if (0 <= provaLOG_09_28_B.caso) {
                memcpy(&provaLOG_09_28_B.tmp_data[0],
                       &provaLOG_09_28_B.comma_gga_data[0],
                       (provaLOG_09_28_B.caso + 1) * sizeof(int32_T));
              }

              if (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.tmp_data[2]] ==
                  'S') {
                provaLOG_09_28_B.num_254 = -provaLOG_09_28_B.num_254;
              }

              provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_ft
                (&provaLOG_09_28_B.messaggio[provaLOG_09_28_B.comma_gga_data[3]]);
              if ((real_T)provaLOG_09_28_B.comma_gga_data[3] + 4.0 > (real_T)
                  provaLOG_09_28_B.comma_gga_data[4] - 1.0) {
                provaLOG_09_28_B.i = 0;
                provaLOG_09_28_B.f_l = 0;
              } else {
                provaLOG_09_28_B.i = provaLOG_09_28_B.comma_gga_data[3] + 3;
                provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[4] - 1;
              }

              provaLOG_09_28_B.messaggio_size_k[0] = 1;
              provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
                provaLOG_09_28_B.i;
              provaLOG_09_28_B.messaggio_size_k[1] = provaLOG_09_28_B.status;
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                   provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                  provaLOG_09_28_B.messaggio[provaLOG_09_28_B.i +
                  provaLOG_09_28_B.f_l];
              }

              provaLOG_09_28_B.b_x = provaLOG_09_28_str2double_f
                (provaLOG_09_28_B.messaggio_data,
                 provaLOG_09_28_B.messaggio_size_k);
              if (provaLOG_09_28_B.b_x.im == 0.0) {
                provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
              } else if (provaLOG_09_28_B.b_x.re == 0.0) {
                provaLOG_09_28_B.RateTransition = 0.0;
              } else {
                provaLOG_09_28_B.RateTransition = provaLOG_09_28_B.b_x.re / 60.0;
              }

              provaLOG_09_28_B.RateTransition += provaLOG_09_28_B.Lat_1.re;
              if (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.tmp_data[4]] ==
                  'W') {
                provaLOG_09_28_B.RateTransition =
                  -provaLOG_09_28_B.RateTransition;
              }

              provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_ftn
                (provaLOG_09_28_B.messaggio[provaLOG_09_28_B.comma_gga_data[5]]);

              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[5] = provaLOG_09_28_B.Lat_1.re;
              if ((real_T)provaLOG_09_28_B.comma_gga_data[6] + 1.0 > (real_T)
                  provaLOG_09_28_B.comma_gga_data[7] - 1.0) {
                provaLOG_09_28_B.caso = 0;
                provaLOG_09_28_B.f_l = 0;
              } else {
                provaLOG_09_28_B.caso = provaLOG_09_28_B.comma_gga_data[6];
                provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[7] - 1;
              }

              provaLOG_09_28_B.messaggio_size_c[0] = 1;
              provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
                provaLOG_09_28_B.caso;
              provaLOG_09_28_B.messaggio_size_c[1] = provaLOG_09_28_B.status;
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                   provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                  provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                  provaLOG_09_28_B.f_l];
              }

              provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_f
                (provaLOG_09_28_B.messaggio_data,
                 provaLOG_09_28_B.messaggio_size_c);

              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[6] = provaLOG_09_28_B.Lat_1.re;
              if ((real_T)provaLOG_09_28_B.comma_gga_data[8] + 1.0 > (real_T)
                  provaLOG_09_28_B.comma_gga_data[9] - 1.0) {
                provaLOG_09_28_B.i = 0;
                provaLOG_09_28_B.f_l = 0;
              } else {
                provaLOG_09_28_B.i = provaLOG_09_28_B.comma_gga_data[8];
                provaLOG_09_28_B.f_l = provaLOG_09_28_B.comma_gga_data[9] - 1;
              }

              provaLOG_09_28_B.messaggio_size_b[0] = 1;
              provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
                provaLOG_09_28_B.i;
              provaLOG_09_28_B.messaggio_size_b[1] = provaLOG_09_28_B.status;
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                   provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                  provaLOG_09_28_B.messaggio[provaLOG_09_28_B.i +
                  provaLOG_09_28_B.f_l];
              }

              provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_f
                (provaLOG_09_28_B.messaggio_data,
                 provaLOG_09_28_B.messaggio_size_b);

              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[7] = provaLOG_09_28_B.Lat_1.re;
              if ((real_T)provaLOG_09_28_B.comma_gga_data[10] + 1.0 > (real_T)
                  provaLOG_09_28_B.comma_gga_data[11] - 1.0) {
                provaLOG_09_28_B.x_d = 0;
                provaLOG_09_28_B.caso = 0;
              } else {
                provaLOG_09_28_B.x_d = provaLOG_09_28_B.comma_gga_data[10];
                provaLOG_09_28_B.caso = provaLOG_09_28_B.comma_gga_data[11] - 1;
              }

              provaLOG_09_28_B.messaggio_size_p[0] = 1;
              provaLOG_09_28_B.status = provaLOG_09_28_B.caso -
                provaLOG_09_28_B.x_d;
              provaLOG_09_28_B.messaggio_size_p[1] = provaLOG_09_28_B.status;
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                   provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.messaggio_data[provaLOG_09_28_B.f_l] =
                  provaLOG_09_28_B.messaggio[provaLOG_09_28_B.x_d +
                  provaLOG_09_28_B.f_l];
              }

              provaLOG_09_28_B.Lat_1 = provaLOG_09_28_str2double_f
                (provaLOG_09_28_B.messaggio_data,
                 provaLOG_09_28_B.messaggio_size_p);

              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[8] = provaLOG_09_28_B.Lat_1.re;
              provaLOG_09_28_B.ComplextoRealImag[2] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[2];
              provaLOG_09_28_B.ComplextoRealImag[3] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[3];
              provaLOG_09_28_B.ComplextoRealImag[4] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[4];
              if ((real_T)provaLOG_09_28_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)provaLOG_09_28_B.star_data[0] + 1.0 >= 0.0) {
                  counter = (uint8_T)((real_T)provaLOG_09_28_B.star_data[0] +
                                      1.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[0] = provaLOG_09_28_B.messaggio[counter - 1];
              if ((real_T)provaLOG_09_28_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)provaLOG_09_28_B.star_data[0] + 2.0 >= 0.0) {
                  counter = (uint8_T)((real_T)provaLOG_09_28_B.star_data[0] +
                                      2.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[1] = provaLOG_09_28_B.messaggio[counter - 1];
              if ((real_T)provaLOG_09_28_B.fb_data[0] + 1.0 > (real_T)
                  provaLOG_09_28_B.star_data[0] - 1.0) {
                provaLOG_09_28_B.caso = 0;
                provaLOG_09_28_B.f_l = 0;
              } else {
                provaLOG_09_28_B.caso = provaLOG_09_28_B.fb_data[0];
                provaLOG_09_28_B.f_l = provaLOG_09_28_B.star_data[0] - 1;
              }

              provaLOG_09_28_B.status = provaLOG_09_28_B.f_l -
                provaLOG_09_28_B.caso;
              for (provaLOG_09_28_B.f_l = 0; provaLOG_09_28_B.f_l <
                   provaLOG_09_28_B.status; provaLOG_09_28_B.f_l++) {
                provaLOG_09_28_B.NMEA_gga_string_data[provaLOG_09_28_B.f_l] =
                  (uint8_T)provaLOG_09_28_B.messaggio[provaLOG_09_28_B.caso +
                  provaLOG_09_28_B.f_l];
              }

              counter = 0U;
              provaLOG_09_28_B.f_l = 0;
              while (provaLOG_09_28_B.f_l <= provaLOG_09_28_B.status - 1) {
                counter ^=
                  provaLOG_09_28_B.NMEA_gga_string_data[provaLOG_09_28_B.f_l];
                provaLOG_09_28_B.f_l++;
              }

              if (counter != provaLOG_09_28_hex2dec(ck_ric)) {
                provaLOG_09_28_B.num_254 =
                  provaLOG_09_28_DW.Memory_PreviousInput_i[0];
                provaLOG_09_28_B.RateTransition =
                  provaLOG_09_28_DW.Memory_PreviousInput_i[1];

                /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
                provaLOG_09_28_B.ComplextoRealImag[5] =
                  provaLOG_09_28_DW.Memory_PreviousInput_i[5];
                provaLOG_09_28_B.ComplextoRealImag[6] =
                  provaLOG_09_28_DW.Memory_PreviousInput_i[6];
                provaLOG_09_28_B.ComplextoRealImag[7] =
                  provaLOG_09_28_DW.Memory_PreviousInput_i[7];
                provaLOG_09_28_B.ComplextoRealImag[8] =
                  provaLOG_09_28_DW.Memory_PreviousInput_i[8];
                provaLOG_09_28_B.indice_dimario = 20U;
              }
            } else {
              provaLOG_09_28_B.num_254 =
                provaLOG_09_28_DW.Memory_PreviousInput_i[0];
              provaLOG_09_28_B.RateTransition =
                provaLOG_09_28_DW.Memory_PreviousInput_i[1];

              /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
              provaLOG_09_28_B.ComplextoRealImag[2] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[2];
              provaLOG_09_28_B.ComplextoRealImag[3] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[3];
              provaLOG_09_28_B.ComplextoRealImag[4] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[4];
              provaLOG_09_28_B.ComplextoRealImag[5] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[5];
              provaLOG_09_28_B.ComplextoRealImag[6] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[6];
              provaLOG_09_28_B.ComplextoRealImag[7] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[7];
              provaLOG_09_28_B.ComplextoRealImag[8] =
                provaLOG_09_28_DW.Memory_PreviousInput_i[8];
            }
          }
        } else {
          provaLOG_09_28_B.num_254 = provaLOG_09_28_DW.Memory_PreviousInput_i[0];
          provaLOG_09_28_B.RateTransition =
            provaLOG_09_28_DW.Memory_PreviousInput_i[1];

          /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
          provaLOG_09_28_B.ComplextoRealImag[2] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[2];
          provaLOG_09_28_B.ComplextoRealImag[3] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[3];
          provaLOG_09_28_B.ComplextoRealImag[4] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[4];
          provaLOG_09_28_B.ComplextoRealImag[5] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[5];
          provaLOG_09_28_B.ComplextoRealImag[6] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[6];
          provaLOG_09_28_B.ComplextoRealImag[7] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[7];
          provaLOG_09_28_B.ComplextoRealImag[8] =
            provaLOG_09_28_DW.Memory_PreviousInput_i[8];
        }

        /* End of MATLAB Function: '<S23>/MATLAB Function' */

        /* ComplexToRealImag: '<S23>/Complex to Real-Imag' */
        provaLOG_09_28_B.ComplextoRealImag[0] = provaLOG_09_28_B.num_254;
        provaLOG_09_28_B.ComplextoRealImag[1] = provaLOG_09_28_B.RateTransition;

        /* Update for Memory: '<S23>/Memory' */
        memcpy(&provaLOG_09_28_DW.Memory_PreviousInput_i[0],
               &provaLOG_09_28_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S21>/Subsystem' */
      } else {
        for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 32; provaLOG_09_28_B.i
             ++) {
          provaLOG_09_28_B.f_l = (int32_T)(((uint32_T)
            provaLOG_09_28_DW.counter_k + provaLOG_09_28_B.i) + 1U);
          if ((uint32_T)provaLOG_09_28_B.f_l > 255U) {
            provaLOG_09_28_B.f_l = 255;
          }

          provaLOG_09_28_DW.message[provaLOG_09_28_B.f_l - 1] =
            provaLOG_09_28_B.b_dataOut[provaLOG_09_28_B.i];
        }

        provaLOG_09_28_B.f_l = (int32_T)(provaLOG_09_28_DW.counter_k + 32U);
        if (provaLOG_09_28_DW.counter_k + 32U > 255U) {
          provaLOG_09_28_B.f_l = 255;
        }

        provaLOG_09_28_DW.counter_k = (uint8_T)provaLOG_09_28_B.f_l;
      }
    }

    /* End of MATLAB Function: '<S21>/Create_message' */
  }

  /* End of MATLABSystem: '<S19>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S19>/Subsystem2' */

  /* Sum: '<S19>/Sum' */
  provaLOG_09_28_B.num_254 = provaLOG_09_28_B.ComplextoRealImag[7] -
    provaLOG_09_28_B.Switch;

  /* Gain: '<S9>/Gain' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain_Gain_i[0] *
    provaLOG_09_28_B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  provaLOG_09_28_B.DataTypeConversion_j[0] = provaLOG_09_28_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (int32_T)
    (uint32_T)provaLOG_09_28_B.RateTransition;

  /* Gain: '<S9>/Gain' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain_Gain_i[1] *
    provaLOG_09_28_B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  provaLOG_09_28_B.DataTypeConversion_j[1] = provaLOG_09_28_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (int32_T)
    (uint32_T)provaLOG_09_28_B.RateTransition;

  /* Gain: '<S9>/Gain' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain_Gain_i[2] *
    provaLOG_09_28_B.num_254;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  provaLOG_09_28_B.DataTypeConversion_j[2] = provaLOG_09_28_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (int32_T)
    (uint32_T)provaLOG_09_28_B.RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/alt_r'
   */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain_Gain_i[3] *
    provaLOG_09_28_P.alt_r_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  provaLOG_09_28_B.DataTypeConversion_j[3] = provaLOG_09_28_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (int32_T)
    (uint32_T)provaLOG_09_28_B.RateTransition;

  /* Gain: '<S9>/Gain1' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain1_Gain *
    provaLOG_09_28_B.ComplextoRealImag[2];

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  provaLOG_09_28_B.DataTypeConversion1_k[0] = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/vel y'
   */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain1_Gain *
    provaLOG_09_28_P.vely_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  provaLOG_09_28_B.DataTypeConversion1_k[1] = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/RC Simulated'
   */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain1_Gain *
    provaLOG_09_28_P.RCSimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  provaLOG_09_28_B.DataTypeConversion1_k[2] = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* Gain: '<S9>/Gain2' */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_P.Gain2_Gain_o *
    provaLOG_09_28_B.ComplextoRealImag[4];

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  if (provaLOG_09_28_B.RateTransition < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.RateTransition);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.RateTransition);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  provaLOG_09_28_B.DataTypeConversion2 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* SignalConversion generated from: '<S38>/Enable' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !provaLOG_09_28_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S3>/One_time_initialization' */
  pro_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &provaLOG_09_28_B.One_time_initialization,
    &provaLOG_09_28_DW.One_time_initialization,
    &provaLOG_09_28_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S3>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S3>/Execution_loop' incorporates:
   *  EnablePort: '<S35>/Enable'
   */
  /* UnitDelay: '<S3>/Unit Delay' */
  if (provaLOG_09_28_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S35>/I2C Read12' */
    if (provaLOG_09_28_DW.obj_f.SampleTime != provaLOG_09_28_P.t_AP) {
      provaLOG_09_28_DW.obj_f.SampleTime = provaLOG_09_28_P.t_AP;
    }

    counter = 250U;
    counter = MW_I2C_MasterWrite
      (provaLOG_09_28_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter, 1U,
       true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(provaLOG_09_28_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&rtb_H_mav[0], (void *)&output_raw[0], (uint32_T)((size_t)2
              * sizeof(uint8_T)));
    } else {
      rtb_H_mav[0] = 0U;
      rtb_H_mav[1] = 0U;
    }

    /* MATLABSystem: '<S35>/I2C Read1' */
    if (provaLOG_09_28_DW.obj_d.SampleTime != provaLOG_09_28_P.t_AP) {
      provaLOG_09_28_DW.obj_d.SampleTime = provaLOG_09_28_P.t_AP;
    }

    counter = 247U;
    counter = MW_I2C_MasterWrite
      (provaLOG_09_28_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U, &counter, 1U,
       true, false);
    if (0 == counter) {
      MW_I2C_MasterRead(provaLOG_09_28_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &provaLOG_09_28_B.output_raw[0], 3U, false, true);
      memcpy((void *)&provaLOG_09_28_B.output[0], (void *)
             &provaLOG_09_28_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
              (uint8_T)));
    } else {
      provaLOG_09_28_B.output[0] = 0U;
      provaLOG_09_28_B.output[1] = 0U;
      provaLOG_09_28_B.output[2] = 0U;
    }

    /* ArithShift: '<S35>/Shift Arithmetic4' incorporates:
     *  Constant: '<S35>/Constant1'
     */
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_n);
    if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
        (provaLOG_09_28_B.RateTransition)) {
      provaLOG_09_28_B.RateTransition = 0.0;
    } else {
      provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
        4.294967296E+9);
    }

    /* ArithShift: '<S35>/Shift Arithmetic3' incorporates:
     *  Constant: '<S35>/Constant5'
     */
    provaLOG_09_28_B.UkYk1 = floor(provaLOG_09_28_P.Constant5_Value);
    if (rtIsNaN(provaLOG_09_28_B.UkYk1) || rtIsInf(provaLOG_09_28_B.UkYk1)) {
      provaLOG_09_28_B.UkYk1 = 0.0;
    } else {
      provaLOG_09_28_B.UkYk1 = fmod(provaLOG_09_28_B.UkYk1, 4.294967296E+9);
    }

    /* ArithShift: '<S35>/Shift Arithmetic1' incorporates:
     *  Constant: '<S35>/Constant6'
     */
    provaLOG_09_28_B.deltafalllimit = floor(provaLOG_09_28_P.Constant6_Value);
    if (rtIsNaN(provaLOG_09_28_B.deltafalllimit) || rtIsInf
        (provaLOG_09_28_B.deltafalllimit)) {
      provaLOG_09_28_B.deltafalllimit = 0.0;
    } else {
      provaLOG_09_28_B.deltafalllimit = fmod(provaLOG_09_28_B.deltafalllimit,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S35>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S35>/Shift Arithmetic1'
     *  ArithShift: '<S35>/Shift Arithmetic3'
     *  ArithShift: '<S35>/Shift Arithmetic4'
     *  Constant: '<S35>/Constant10'
     *  Constant: '<S35>/Constant11'
     *  Constant: '<S35>/Constant7'
     *  MATLABSystem: '<S35>/I2C Read1'
     *  Sum: '<S35>/Sum1'
     *  Sum: '<S35>/Sum4'
     *  Sum: '<S35>/Sum5'
     *  Sum: '<S35>/Sum6'
     */
    provaLOG_09_28_B.DataTypeConversion1_a = (int32_T)
      ((((((provaLOG_09_28_P.Constant7_Value_e + provaLOG_09_28_B.output[0]) <<
           (provaLOG_09_28_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
            -provaLOG_09_28_B.RateTransition : (int32_T)(uint32_T)
            provaLOG_09_28_B.RateTransition)) +
          ((provaLOG_09_28_P.Constant10_Value_m + provaLOG_09_28_B.output[1]) <<
           (provaLOG_09_28_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
            -provaLOG_09_28_B.UkYk1 : (int32_T)(uint32_T)provaLOG_09_28_B.UkYk1)))
         + provaLOG_09_28_P.Constant11_Value) + provaLOG_09_28_B.output[2]) >>
       (provaLOG_09_28_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -provaLOG_09_28_B.deltafalllimit : (int32_T)(uint32_T)
        provaLOG_09_28_B.deltafalllimit));

    /* ArithShift: '<S35>/Shift Arithmetic7' incorporates:
     *  Constant: '<S35>/Constant2'
     */
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant2_Value_c);
    if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
        (provaLOG_09_28_B.RateTransition)) {
      provaLOG_09_28_B.RateTransition = 0.0;
    } else {
      provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
        4.294967296E+9);
    }

    /* ArithShift: '<S35>/Shift Arithmetic6' incorporates:
     *  Constant: '<S35>/Constant3'
     */
    provaLOG_09_28_B.UkYk1 = floor(provaLOG_09_28_P.Constant3_Value_p);
    if (rtIsNaN(provaLOG_09_28_B.UkYk1) || rtIsInf(provaLOG_09_28_B.UkYk1)) {
      provaLOG_09_28_B.UkYk1 = 0.0;
    } else {
      provaLOG_09_28_B.UkYk1 = fmod(provaLOG_09_28_B.UkYk1, 4.294967296E+9);
    }

    /* ArithShift: '<S35>/Shift Arithmetic2' incorporates:
     *  Constant: '<S35>/Constant4'
     */
    provaLOG_09_28_B.deltafalllimit = floor(provaLOG_09_28_P.Constant4_Value);
    if (rtIsNaN(provaLOG_09_28_B.deltafalllimit) || rtIsInf
        (provaLOG_09_28_B.deltafalllimit)) {
      provaLOG_09_28_B.deltafalllimit = 0.0;
    } else {
      provaLOG_09_28_B.deltafalllimit = fmod(provaLOG_09_28_B.deltafalllimit,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S35>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S35>/Shift Arithmetic2'
     *  ArithShift: '<S35>/Shift Arithmetic6'
     *  ArithShift: '<S35>/Shift Arithmetic7'
     *  Constant: '<S35>/Constant8'
     *  Constant: '<S35>/Constant9'
     *  MATLABSystem: '<S35>/I2C Read12'
     *  Sum: '<S35>/Sum'
     *  Sum: '<S35>/Sum2'
     *  Sum: '<S35>/Sum3'
     */
    provaLOG_09_28_B.DataTypeConversion_h = (int32_T)
      ((((provaLOG_09_28_P.Constant8_Value_p + rtb_H_mav[0]) <<
         (provaLOG_09_28_B.RateTransition < 0.0 ? -(int32_T)(uint32_T)
          -provaLOG_09_28_B.RateTransition : (int32_T)(uint32_T)
          provaLOG_09_28_B.RateTransition)) +
        ((provaLOG_09_28_P.Constant9_Value_o + rtb_H_mav[1]) <<
         (provaLOG_09_28_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
          -provaLOG_09_28_B.UkYk1 : (int32_T)(uint32_T)provaLOG_09_28_B.UkYk1)))
       >> (provaLOG_09_28_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
           -provaLOG_09_28_B.deltafalllimit : (int32_T)(uint32_T)
           provaLOG_09_28_B.deltafalllimit));

    /* S-Function (calc_T): '<S35>/S-Function Builder' */
    calc_T_Outputs_wrapper(&provaLOG_09_28_B.One_time_initialization.I2CRead,
      &provaLOG_09_28_B.One_time_initialization.I2CRead1,
      &provaLOG_09_28_B.One_time_initialization.I2CRead2,
      &provaLOG_09_28_B.DataTypeConversion_h,
      &provaLOG_09_28_B.SFunctionBuilder_o1,
      &provaLOG_09_28_B.SFunctionBuilder_o2_a);

    /* S-Function (calc_p): '<S35>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&provaLOG_09_28_B.One_time_initialization.I2CRead3,
      &provaLOG_09_28_B.One_time_initialization.I2CRead4,
      &provaLOG_09_28_B.One_time_initialization.I2CRead5,
      &provaLOG_09_28_B.One_time_initialization.I2CRead6,
      &provaLOG_09_28_B.One_time_initialization.I2CRead7,
      &provaLOG_09_28_B.One_time_initialization.I2CRead8,
      &provaLOG_09_28_B.One_time_initialization.I2CRead9,
      &provaLOG_09_28_B.One_time_initialization.I2CRead10,
      &provaLOG_09_28_B.One_time_initialization.I2CRead11,
      &provaLOG_09_28_B.DataTypeConversion1_a,
      &provaLOG_09_28_B.SFunctionBuilder_o2_a,
      &provaLOG_09_28_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S3>/Execution_loop' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (provaLOG_09_28_P.Constant2_Value_gi == 1.0) {
    provaLOG_09_28_DW.P_ref = provaLOG_09_28_B.SFunctionBuilder1;
  }

  if (provaLOG_09_28_P.Constant_Value_j == 1.0) {
    provaLOG_09_28_DW.P_ref = provaLOG_09_28_P.Constant1_Value_k3;
    provaLOG_09_28_DW.rl_up = 20.0;
    provaLOG_09_28_DW.rl_dw = -20.0;
  }

  /* Product: '<S34>/delta rise limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S34>/sample time'
   *
   * About '<S34>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provaLOG_09_28_B.RateTransition = provaLOG_09_28_DW.rl_up *
    provaLOG_09_28_P.sampletime_WtEt;

  /* Sum: '<S34>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S34>/Delay Input2'
   *
   * Block description for '<S34>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S34>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaLOG_09_28_B.UkYk1 = provaLOG_09_28_DW.P_ref -
    provaLOG_09_28_DW.DelayInput2_DSTATE;

  /* Product: '<S34>/delta fall limit' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SampleTimeMath: '<S34>/sample time'
   *
   * About '<S34>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provaLOG_09_28_B.deltafalllimit = provaLOG_09_28_DW.rl_dw *
    provaLOG_09_28_P.sampletime_WtEt;

  /* Switch: '<S40>/Switch2' incorporates:
   *  RelationalOperator: '<S40>/LowerRelop1'
   *  RelationalOperator: '<S40>/UpperRelop'
   *  Switch: '<S40>/Switch'
   */
  if (provaLOG_09_28_B.UkYk1 > provaLOG_09_28_B.RateTransition) {
    provaLOG_09_28_B.UkYk1 = provaLOG_09_28_B.RateTransition;
  } else {
    if (provaLOG_09_28_B.UkYk1 < provaLOG_09_28_B.deltafalllimit) {
      /* Switch: '<S40>/Switch' */
      provaLOG_09_28_B.UkYk1 = provaLOG_09_28_B.deltafalllimit;
    }
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Sum: '<S34>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S34>/Delay Input2'
   *
   * Block description for '<S34>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S34>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaLOG_09_28_DW.DelayInput2_DSTATE += provaLOG_09_28_B.UkYk1;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S34>/Delay Input2'
   *
   * Block description for '<S34>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaLOG_09_28_B.DataTypeConversion3_j = (real32_T)
    provaLOG_09_28_DW.DelayInput2_DSTATE;

  /* Outputs for Enabled SubSystem: '<S39>/Subsystem1' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (provaLOG_09_28_P.Constant2_Value_gi > 0.0) {
    /* Inport: '<S41>/T' */
    provaLOG_09_28_B.T = provaLOG_09_28_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S39>/Subsystem1' */

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  provaLOG_09_28_B.h_ = (real32_T)log((real32_T)
    provaLOG_09_28_B.SFunctionBuilder1 / provaLOG_09_28_B.DataTypeConversion3_j)
    * -8333.33301F;

  /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
   *  Constant: '<S15>/RC simulated'
   *  Constant: '<S15>/TAS simulated'
   *  Constant: '<S15>/v simulated'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  provaLOG_09_28_B.DataTypeConversion3_a[0] = (real32_T)
    provaLOG_09_28_P.TASsimulated_Value;
  provaLOG_09_28_B.DataTypeConversion3_a[1] = (real32_T)
    provaLOG_09_28_P.vsimulated_Value;
  provaLOG_09_28_B.DataTypeConversion3_a[2] = provaLOG_09_28_B.h_;
  provaLOG_09_28_B.DataTypeConversion3_a[3] = (real32_T)
    provaLOG_09_28_P.RCsimulated_Value;

  /* DataTypeConversion: '<S15>/Data Type Conversion4' incorporates:
   *  Constant: '<S15>/ Heading simulated'
   */
  provaLOG_09_28_B.RateTransition = floor
    (provaLOG_09_28_P.Headingsimulated_Value);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion4' */
  provaLOG_09_28_B.DataTypeConversion4_o = (int16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S15>/Data Type Conversion5' incorporates:
   *  Constant: '<S15>/Rpm simulated'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Rpmsimulated_Value);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion5' */
  provaLOG_09_28_B.DataTypeConversion5 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* Gain: '<S29>/Gain2' incorporates:
   *  Constant: '<S13>/Manetta Simulated'
   */
  provaLOG_09_28_B.UkYk1 = provaLOG_09_28_P.Gain2_Gain_f *
    provaLOG_09_28_P.ManettaSimulated_Value;

  /* Sum: '<S29>/Sum' incorporates:
   *  Constant: '<S13>/Equilibratore Simulated'
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S30>/Gain'
   */
  provaLOG_09_28_B.deltafalllimit = provaLOG_09_28_P.Gain_Gain_d *
    provaLOG_09_28_P.EquilibratoreSimulated_Value +
    provaLOG_09_28_P.Constant2_Value_l;

  /* Sum: '<S29>/Sum1' incorporates:
   *  Constant: '<S13>/Alettoni Simulated'
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S31>/Gain'
   */
  provaLOG_09_28_B.Sum1 = provaLOG_09_28_P.Gain_Gain_n *
    provaLOG_09_28_P.AlettoniSimulated_Value +
    provaLOG_09_28_P.Constant2_Value_l;

  /* Sum: '<S29>/Sum2' incorporates:
   *  Constant: '<S13>/Timone Simulated'
   *  Constant: '<S29>/Constant2'
   *  Gain: '<S32>/Gain'
   */
  provaLOG_09_28_B.Gain3 = provaLOG_09_28_P.Gain_Gain_p *
    provaLOG_09_28_P.TimoneSimulated_Value + provaLOG_09_28_P.Constant2_Value_l;

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  provaLOG_09_28_B.PatohPa = provaLOG_09_28_P.Gain_Gain_g *
    provaLOG_09_28_P.Constant2_Value_i;

  /* Saturate: '<S13>/Saturation' */
  if (provaLOG_09_28_B.PatohPa > provaLOG_09_28_P.Saturation_UpperSat) {
    provaLOG_09_28_B.PatohPa = provaLOG_09_28_P.Saturation_UpperSat;
  } else {
    if (provaLOG_09_28_B.PatohPa < provaLOG_09_28_P.Saturation_LowerSat) {
      provaLOG_09_28_B.PatohPa = provaLOG_09_28_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (provaLOG_09_28_P.Constant_Value_c < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant_Value_c);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant_Value_c);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[0] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (provaLOG_09_28_B.UkYk1 < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.UkYk1);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.UkYk1);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[1] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (provaLOG_09_28_B.deltafalllimit < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.deltafalllimit);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.deltafalllimit);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[2] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (provaLOG_09_28_B.Sum1 < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.Sum1);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.Sum1);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[3] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (provaLOG_09_28_B.Gain3 < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.Gain3);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.Gain3);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[4] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (provaLOG_09_28_P.Constant1_Value_gk[0] < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant1_Value_gk[0]);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_gk
      [0]);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[5] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (provaLOG_09_28_P.Constant1_Value_gk[1] < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant1_Value_gk[1]);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_gk
      [1]);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[6] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (provaLOG_09_28_P.Constant1_Value_gk[2] < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_P.Constant1_Value_gk[2]);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_gk
      [2]);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[7] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  if (provaLOG_09_28_B.PatohPa < 0.0) {
    provaLOG_09_28_B.RateTransition = ceil(provaLOG_09_28_B.PatohPa);
  } else {
    provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.PatohPa);
  }

  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  provaLOG_09_28_B.Heading[8] = (uint16_T)(provaLOG_09_28_B.RateTransition < 0.0
    ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.RateTransition :
    (int32_T)(uint16_T)provaLOG_09_28_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  provaLOG_09_28_B.Memory_e = provaLOG_09_28_DW.Memory_PreviousInput_n;

  /* Switch: '<S39>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S39>/NotEqual'
   *  Switch: '<S39>/Switch'
   */
  if (provaLOG_09_28_P.Constant_Value_o != provaLOG_09_28_P.T_0_Value) {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    provaLOG_09_28_B.DataTypeConversion4_g = (real32_T)
      provaLOG_09_28_P.T_0_Value;
  } else if (provaLOG_09_28_B.T > provaLOG_09_28_P.Switch_Threshold_l) {
    /* Switch: '<S39>/Switch' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion4'
     */
    provaLOG_09_28_B.DataTypeConversion4_g = provaLOG_09_28_B.T;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    provaLOG_09_28_B.DataTypeConversion4_g = (real32_T)
      provaLOG_09_28_P.T_0_Value;
  }

  /* End of Switch: '<S39>/Switch1' */

  /* Gain: '<S2>/Pa to hPa' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  provaLOG_09_28_B.PatohPa = provaLOG_09_28_P.PatohPa_Gain * (real_T)
    provaLOG_09_28_B.SFunctionBuilder1;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  provaLOG_09_28_B.DataTypeConversion_a = (real32_T)provaLOG_09_28_B.PatohPa;

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  provaLOG_09_28_B.DataTypeConversion1 = (real32_T)
    (provaLOG_09_28_P.PatohPa1_Gain * provaLOG_09_28_P.Constant2_Value_a);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.SFunctionBuilder_o1);
  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  provaLOG_09_28_B.DataTypeConversion2_c = (int16_T)(provaLOG_09_28_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&provaLOG_09_28_B.iflogic,
    &provaLOG_09_28_B.DataTypeConversion3, &provaLOG_09_28_P.SIUAVuint8_Value,
    &provaLOG_09_28_B.GC_info[0], &provaLOG_09_28_B.Val_out_MAV[0],
    &provaLOG_09_28_B.WP_info[0], &provaLOG_09_28_B.WP_param[0],
    &provaLOG_09_28_B.onboard[0], &provaLOG_09_28_B.LVDE[0],
    &provaLOG_09_28_B.B_Current, &provaLOG_09_28_B.B_Remaining,
    &provaLOG_09_28_B.DataTypeConversion,
    &provaLOG_09_28_B.DataTypeConversion1_n[0],
    &provaLOG_09_28_B.DataTypeConversion3_m[0],
    &provaLOG_09_28_B.DataTypeConversion4[0],
    &provaLOG_09_28_B.DataTypeConversion_j[0],
    &provaLOG_09_28_B.DataTypeConversion1_k[0],
    &provaLOG_09_28_B.DataTypeConversion2,
    &provaLOG_09_28_B.DataTypeConversion3_a[0],
    &provaLOG_09_28_B.DataTypeConversion4_o,
    &provaLOG_09_28_B.DataTypeConversion5, &provaLOG_09_28_B.Heading[0],
    &provaLOG_09_28_B.Memory_e, &provaLOG_09_28_B.DataTypeConversion3_j,
    &provaLOG_09_28_B.SFunction_o14, &provaLOG_09_28_B.DataTypeConversion4_g,
    &provaLOG_09_28_B.SFunction_o15, &provaLOG_09_28_B.DataTypeConversion_a,
    &provaLOG_09_28_B.DataTypeConversion1,
    &provaLOG_09_28_B.DataTypeConversion2_c, &provaLOG_09_28_B.SFunction_o5[0],
    &provaLOG_09_28_P.Constant4_Value_j, &provaLOG_09_28_P.Constant5_Value_f,
    &provaLOG_09_28_P.Constant10_Value, ((const uint16_T*)
    &provaLOG_09_28_U16GND), &provaLOG_09_28_B.SFunction_o1_m,
    &provaLOG_09_28_B.SFunction_o2_n[0], &provaLOG_09_28_B.SFunction_o3,
    &provaLOG_09_28_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (provaLOG_09_28_B.SFunction_o1_m > 0) {
    /* Chart: '<S8>/Chart' */
    if (provaLOG_09_28_DW.is_active_c9_provaLOG_09_28 == 0U) {
      provaLOG_09_28_DW.is_active_c9_provaLOG_09_28 = 1U;
      provaLOG_09_28_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (provaLOG_09_28_DW.obj_j.Protocol !=
            provaLOG_09_28_P.SerialTransmit_Protocol) {
          provaLOG_09_28_DW.obj_j.Protocol =
            provaLOG_09_28_P.SerialTransmit_Protocol;
        }

        counter = provaLOG_09_28_B.SFunction_o2_n[provaLOG_09_28_DW.i - 1];
        MW_Serial_write(provaLOG_09_28_DW.obj_j.port, &counter, 1.0,
                        provaLOG_09_28_DW.obj_j.dataSizeInBytes,
                        provaLOG_09_28_DW.obj_j.sendModeEnum,
                        provaLOG_09_28_DW.obj_j.dataType,
                        provaLOG_09_28_DW.obj_j.sendFormatEnum, 2.0, '\x00');
        if (provaLOG_09_28_DW.i < provaLOG_09_28_B.SFunction_o3) {
          provaLOG_09_28_B.f_l = provaLOG_09_28_DW.i + 1;
          if (provaLOG_09_28_DW.i + 1 > 255) {
            provaLOG_09_28_B.f_l = 255;
          }

          provaLOG_09_28_DW.i = (uint8_T)provaLOG_09_28_B.f_l;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      provaLOG_09_28_DW.i = 1U;
    }

    /* End of Chart: '<S8>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  provaLOG_09_28_B.DataTypeConversion6[0] = (real32_T)
    provaLOG_09_28_B.ComplextoRealImag[0];
  provaLOG_09_28_B.DataTypeConversion6[1] = (real32_T)
    provaLOG_09_28_B.ComplextoRealImag[1];
  provaLOG_09_28_B.DataTypeConversion6[2] = (real32_T)provaLOG_09_28_B.num_254;
  provaLOG_09_28_B.DataTypeConversion6[3] = provaLOG_09_28_B.h_;

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.DataTypeConversion4[0]);
  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* Gain: '<S2>/Gain' */
  provaLOG_09_28_B.h_ = (real32_T)provaLOG_09_28_P.Gain_Gain_e * 0.00390625F;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Gain: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)(provaLOG_09_28_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
               -provaLOG_09_28_B.f : (int32_T)(int16_T)(uint16_T)
               provaLOG_09_28_B.f)), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[0] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.DataTypeConversion4[1]);
  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Gain: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)(provaLOG_09_28_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
               -provaLOG_09_28_B.f : (int32_T)(int16_T)(uint16_T)
               provaLOG_09_28_B.f)), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[1] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  provaLOG_09_28_B.f = (real32_T)floor(provaLOG_09_28_B.DataTypeConversion4[2]);
  if (rtIsNaNF(provaLOG_09_28_B.f) || rtIsInfF(provaLOG_09_28_B.f)) {
    provaLOG_09_28_B.f = 0.0F;
  } else {
    provaLOG_09_28_B.f = (real32_T)fmod(provaLOG_09_28_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Gain: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)(provaLOG_09_28_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
               -provaLOG_09_28_B.f : (int32_T)(int16_T)(uint16_T)
               provaLOG_09_28_B.f)), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[2] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)provaLOG_09_28_B.DataTypeConversion3_m[3]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[3] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)provaLOG_09_28_B.DataTypeConversion3_m[4]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[4] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)provaLOG_09_28_B.DataTypeConversion3_m[5]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[5] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)provaLOG_09_28_B.DataTypeConversion3_m[0]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[6] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)provaLOG_09_28_B.DataTypeConversion3_m[1]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[7] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  provaLOG_09_28_B.f = (real32_T)fmod((real32_T)floor(provaLOG_09_28_B.h_ *
    (real32_T)provaLOG_09_28_B.DataTypeConversion3_m[2]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  provaLOG_09_28_B.DataTypeConversion3_p[8] = (int16_T)(provaLOG_09_28_B.f <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-provaLOG_09_28_B.f : (int32_T)
    (int16_T)(uint16_T)provaLOG_09_28_B.f);

  /* DataTypeConversion: '<S2>/Data Type Conversion10' */
  provaLOG_09_28_B.DataTypeConversion10 = provaLOG_09_28_B.DataTypeConversion2;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  provaLOG_09_28_B.DataTypeConversion11[0] = (uint16_T)
    ((provaLOG_09_28_P.Gain2_Gain_n * provaLOG_09_28_B.DataTypeConversion1_k[0])
     >> 8);
  provaLOG_09_28_B.DataTypeConversion11[1] = (uint16_T)
    ((provaLOG_09_28_P.Gain2_Gain_n * provaLOG_09_28_B.DataTypeConversion1_k[1])
     >> 8);
  provaLOG_09_28_B.DataTypeConversion11[2] = (uint16_T)
    ((provaLOG_09_28_P.Gain2_Gain_n * provaLOG_09_28_B.DataTypeConversion1_k[2])
     >> 8);

  /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
   *  Constant: '<S2>/Constant'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant_Value_ez);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  provaLOG_09_28_B.DataTypeConversion12 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion13' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant3_Value_o);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  provaLOG_09_28_B.DataTypeConversion13 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant7_Value);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  provaLOG_09_28_B.DataTypeConversion14 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant8_Value);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  provaLOG_09_28_B.DataTypeConversion15 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion21' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant9_Value);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion21' */
  provaLOG_09_28_B.DataTypeConversion21 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion20' incorporates:
   *  Constant: '<S2>/Constant6'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant6_Value_l);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  provaLOG_09_28_B.DataTypeConversion20 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion19' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_P.Constant1_Value_b);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  provaLOG_09_28_B.DataTypeConversion19 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion18' incorporates:
   *  Gain: '<S2>/Gain3'
   */
  provaLOG_09_28_B.RateTransition = floor((real_T)provaLOG_09_28_P.Gain3_Gain *
    provaLOG_09_28_B.SFunctionBuilder_o1);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  provaLOG_09_28_B.DataTypeConversion18 = (uint16_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-provaLOG_09_28_B.RateTransition : (int32_T)(uint16_T)
     provaLOG_09_28_B.RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.ComplextoRealImag[5]);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  provaLOG_09_28_B.DataTypeConversion8[0] = (uint8_T)
    (provaLOG_09_28_B.RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
     -provaLOG_09_28_B.RateTransition : (int32_T)(uint8_T)
     provaLOG_09_28_B.RateTransition);
  provaLOG_09_28_B.DataTypeConversion8[1] = provaLOG_09_28_B.indice_dimario;

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  provaLOG_09_28_B.RateTransition = floor(provaLOG_09_28_B.PatohPa);
  if (rtIsNaN(provaLOG_09_28_B.RateTransition) || rtIsInf
      (provaLOG_09_28_B.RateTransition)) {
    provaLOG_09_28_B.RateTransition = 0.0;
  } else {
    provaLOG_09_28_B.RateTransition = fmod(provaLOG_09_28_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  provaLOG_09_28_B.DataTypeConversion16 = provaLOG_09_28_B.RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-provaLOG_09_28_B.RateTransition : (uint32_T)
    provaLOG_09_28_B.RateTransition;

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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion6[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion3_p[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion10, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion11[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion12, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion13, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion14, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion15, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion21, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion20, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion19, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion18, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion8[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_B.DataTypeConversion16, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&provaLOG_09_28_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &provaLOG_09_28_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S2>/Serial Transmit1' */
  if (provaLOG_09_28_DW.obj.Protocol !=
      provaLOG_09_28_P.SerialTransmit1_Protocol) {
    provaLOG_09_28_DW.obj.Protocol = provaLOG_09_28_P.SerialTransmit1_Protocol;
  }

  memcpy(&provaLOG_09_28_B.dataIn[0], &provaLOG_09_28_B.BytePack[0], 67U *
         sizeof(uint8_T));
  MW_Serial_write(provaLOG_09_28_DW.obj.port, &provaLOG_09_28_B.dataIn[0], 67.0,
                  provaLOG_09_28_DW.obj.dataSizeInBytes,
                  provaLOG_09_28_DW.obj.sendModeEnum,
                  provaLOG_09_28_DW.obj.dataType,
                  provaLOG_09_28_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S2>/Serial Transmit1' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&provaLOG_09_28_DW.Memory4_PreviousInput[0], &provaLOG_09_28_B.buffer[0],
         300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S26>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S26>/S-Function Builder */
  Mti_Update_wrapper(&provaLOG_09_28_B.SFunctionBuilder[0],
                     &provaLOG_09_28_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&provaLOG_09_28_P.Constant1_Value_i,
    &provaLOG_09_28_B.SFunctionBuilder_o1_j[0],
    &provaLOG_09_28_B.SFunctionBuilder_o2,
    &provaLOG_09_28_DW.SFunctionBuilder_DSTATE_c);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&provaLOG_09_28_DW.Memory5_PreviousInput[0],
         &provaLOG_09_28_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  provaLOG_09_28_DW.Memory_PreviousInput_m[0] =
    provaLOG_09_28_B.DataTypeConversion1_n[0];
  provaLOG_09_28_DW.Memory_PreviousInput_m[1] =
    provaLOG_09_28_B.DataTypeConversion1_n[1];
  provaLOG_09_28_DW.Memory_PreviousInput_m[2] =
    provaLOG_09_28_B.DataTypeConversion1_n[2];
  provaLOG_09_28_DW.Memory_PreviousInput_m[3] =
    provaLOG_09_28_B.DataTypeConversion1_n[3];

  /* Update for Memory: '<S1>/Memory' */
  for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 8; provaLOG_09_28_B.i++) {
    provaLOG_09_28_DW.Memory_PreviousInput_g[provaLOG_09_28_B.i] =
      provaLOG_09_28_B.SFunction_o11[provaLOG_09_28_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  provaLOG_09_28_DW.Memory2_PreviousInput_c[0] = (uint8_T)AP_mode_idx_0;
  provaLOG_09_28_DW.Memory2_PreviousInput_c[1] = (uint8_T)AP_mode_idx_1;
  for (provaLOG_09_28_B.i = 0; provaLOG_09_28_B.i < 7; provaLOG_09_28_B.i++) {
    provaLOG_09_28_B.f = rt_roundf_snf
      (provaLOG_09_28_DW.riferimenti[provaLOG_09_28_B.i]);
    if (provaLOG_09_28_B.f < 256.0F) {
      if (provaLOG_09_28_B.f >= 0.0F) {
        provaLOG_09_28_DW.Memory2_PreviousInput_c[provaLOG_09_28_B.i + 2] =
          (uint8_T)provaLOG_09_28_B.f;
      } else {
        provaLOG_09_28_DW.Memory2_PreviousInput_c[provaLOG_09_28_B.i + 2] = 0U;
      }
    } else {
      provaLOG_09_28_DW.Memory2_PreviousInput_c[provaLOG_09_28_B.i + 2] =
        MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  provaLOG_09_28_DW.UnitDelay_DSTATE = provaLOG_09_28_P.Constant3_Value_c;

  /* Update for Memory: '<S2>/Memory' */
  provaLOG_09_28_DW.Memory_PreviousInput_n = provaLOG_09_28_B.SFunction_o4;
}

/* Model step function for TID1 */
void provaLOG_09_28_step1(void)        /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S27>/Add2' incorporates:
   *  Constant: '<S27>/Constant4'
   *  Constant: '<S27>/Constant5'
   *  Memory: '<S27>/Memory2'
   */
  provaLOG_09_28_DW.Memory2_PreviousInput += provaLOG_09_28_P.Constant4_Value_d
    + provaLOG_09_28_P.Constant5_Value_k;

  /* Switch: '<S27>/Switch1' */
  if (provaLOG_09_28_DW.Memory2_PreviousInput >
      provaLOG_09_28_P.Switch1_Threshold) {
    /* Sum: '<S27>/Add2' incorporates:
     *  Constant: '<S27>/Constant4'
     */
    provaLOG_09_28_DW.Memory2_PreviousInput = provaLOG_09_28_P.Constant4_Value_d;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* RateTransition: '<S27>/Rate Transition' */
  provaLOG_09_28_DW.RateTransition_Buffer0 =
    provaLOG_09_28_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void provaLOG_09_28_initialize(void)
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

    /* Start for S-Function (Mti): '<S26>/S-Function Builder' */

    /* S-Function Block: <S26>/S-Function Builder */
    Mti_Start_wrapper(&provaLOG_09_28_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&provaLOG_09_28_DW.Memory4_PreviousInput[0],
           &provaLOG_09_28_P.Memory4_InitialCondition[0], 300U * sizeof(uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S26>/S-Function Builder' */

    /* S-Function Block: <S26>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provaLOG_09_28_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provaLOG_09_28_DW.SFunctionBuilder_DSTATE_c = initVector[0];
        }
      }
    }

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition' */
    provaLOG_09_28_DW.RateTransition_Buffer0 =
      provaLOG_09_28_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S27>/Switch' incorporates:
     *  Memory: '<S27>/Memory1'
     */
    provaLOG_09_28_DW.Memory1_PreviousInput =
      provaLOG_09_28_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S27>/Add' incorporates:
     *  Memory: '<S27>/Memory'
     */
    provaLOG_09_28_DW.Memory_PreviousInput =
      provaLOG_09_28_P.Memory_InitialCondition_k;

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      provaLOG_09_28_DW.Memory5_PreviousInput[i] =
        provaLOG_09_28_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    provaLOG_09_28_DW.Memory1_PreviousInput_j[0] =
      provaLOG_09_28_P.Memory1_InitialCondition_l;
    provaLOG_09_28_DW.Memory1_PreviousInput_j[1] =
      provaLOG_09_28_P.Memory1_InitialCondition_l;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    provaLOG_09_28_DW.Memory_PreviousInput_m[0] =
      provaLOG_09_28_P.Memory_InitialCondition_f;
    provaLOG_09_28_DW.Memory_PreviousInput_m[1] =
      provaLOG_09_28_P.Memory_InitialCondition_f;
    provaLOG_09_28_DW.Memory_PreviousInput_m[2] =
      provaLOG_09_28_P.Memory_InitialCondition_f;
    provaLOG_09_28_DW.Memory_PreviousInput_m[3] =
      provaLOG_09_28_P.Memory_InitialCondition_f;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    provaLOG_09_28_DW.Memory3_PreviousInput =
      provaLOG_09_28_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      provaLOG_09_28_DW.Memory_PreviousInput_g[i] =
        provaLOG_09_28_P.Memory_InitialCondition_o;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      provaLOG_09_28_DW.Memory2_PreviousInput_c[i] =
        provaLOG_09_28_P.Memory2_InitialCondition_j[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    provaLOG_09_28_DW.UnitDelay_DSTATE =
      provaLOG_09_28_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S34>/Delay Input2'
     *
     * Block description for '<S34>/Delay Input2':
     *
     *  Store in Global RAM
     */
    provaLOG_09_28_DW.DelayInput2_DSTATE =
      provaLOG_09_28_P.DelayInput2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    provaLOG_09_28_DW.Memory_PreviousInput_n =
      provaLOG_09_28_P.Memory_InitialCondition_d;

    /* InitializeConditions for Sum: '<S27>/Add2' incorporates:
     *  Memory: '<S27>/Memory2'
     */
    provaLOG_09_28_DW.Memory2_PreviousInput =
      provaLOG_09_28_P.Memory2_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
     *  SubSystem: '<S17>/sendbyte'
     */
    /* Start for MATLABSystem: '<S18>/Serial Transmit' */
    provaLOG_09_28_DW.obj_j.matlabCodegenIsDeleted = false;
    provaLOG_09_28_DW.obj_j.Protocol = provaLOG_09_28_P.SerialTransmit_Protocol;
    provaLOG_09_28_DW.obj_j.isInitialized = 1;
    provaLOG_09_28_DW.obj_j.port = 1.0;
    provaLOG_09_28_DW.obj_j.dataSizeInBytes = 1.0;
    provaLOG_09_28_DW.obj_j.dataType = 0.0;
    provaLOG_09_28_DW.obj_j.sendModeEnum = 0.0;
    provaLOG_09_28_DW.obj_j.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(provaLOG_09_28_DW.obj_j.port);
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
    provaLOG_09_28_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S18>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S19>/Subsystem1' */
    /* SystemInitialize for Switch: '<S20>/Switch' incorporates:
     *  Outport: '<S20>/h_to_subtract'
     */
    provaLOG_09_28_B.Switch = provaLOG_09_28_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S19>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S19>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S21>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S23>/Memory' */
      provaLOG_09_28_DW.Memory_PreviousInput_i[i] =
        provaLOG_09_28_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S23>/Complex to Real-Imag' incorporates:
       *  Outport: '<S23>/Outport'
       */
      provaLOG_09_28_B.ComplextoRealImag[i] = provaLOG_09_28_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S23>/mario' */
    provaLOG_09_28_B.indice_dimario = provaLOG_09_28_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S21>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S19>/Subsystem2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&provaLOG_09_28_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S3>/Execution_loop' */
    /* Start for MATLABSystem: '<S35>/I2C Read12' */
    provaLOG_09_28_DW.obj_f.matlabCodegenIsDeleted = true;
    obj = &provaLOG_09_28_DW.obj_f;
    provaLOG_09_28_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    provaLOG_09_28_DW.obj_f.isInitialized = 0;
    provaLOG_09_28_DW.obj_f.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provaLOG_09_28_DW.obj_f.matlabCodegenIsDeleted = false;
    provaLOG_09_28_DW.obj_f.SampleTime = provaLOG_09_28_P.t_AP;
    obj = &provaLOG_09_28_DW.obj_f;
    provaLOG_09_28_DW.obj_f.isSetupComplete = false;
    provaLOG_09_28_DW.obj_f.isInitialized = 1;
    provaLOG_09_28_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provaLOG_09_28_B.i2cname, 0);
    provaLOG_09_28_DW.obj_f.BusSpeed = 100000U;
    varargin_1 = provaLOG_09_28_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provaLOG_09_28_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Read1' */
    provaLOG_09_28_DW.obj_d.matlabCodegenIsDeleted = true;
    obj = &provaLOG_09_28_DW.obj_d;
    provaLOG_09_28_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    provaLOG_09_28_DW.obj_d.isInitialized = 0;
    provaLOG_09_28_DW.obj_d.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provaLOG_09_28_DW.obj_d.matlabCodegenIsDeleted = false;
    provaLOG_09_28_DW.obj_d.SampleTime = provaLOG_09_28_P.t_AP;
    obj = &provaLOG_09_28_DW.obj_d;
    provaLOG_09_28_DW.obj_d.isSetupComplete = false;
    provaLOG_09_28_DW.obj_d.isInitialized = 1;
    provaLOG_09_28_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provaLOG_09_28_B.i2cname, 0);
    provaLOG_09_28_DW.obj_d.BusSpeed = 100000U;
    varargin_1 = provaLOG_09_28_DW.obj_d.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provaLOG_09_28_DW.obj_d.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S35>/S-Function Builder' incorporates:
     *  Outport: '<S35>/T'
     */
    provaLOG_09_28_B.SFunctionBuilder_o1 = provaLOG_09_28_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S35>/S-Function Builder1' incorporates:
     *  Outport: '<S35>/p'
     */
    provaLOG_09_28_B.SFunctionBuilder1 = provaLOG_09_28_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    provaLOG_09_28_DW.P_ref = 101325.0;
    provaLOG_09_28_DW.rl_up = 300.0;
    provaLOG_09_28_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S3>/One_time_initialization' */
    One_time_initializatio_Init(&provaLOG_09_28_B.One_time_initialization,
      &provaLOG_09_28_DW.One_time_initialization,
      &provaLOG_09_28_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S3>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem1' */
    /* SystemInitialize for Outport: '<S41>/T_0' incorporates:
     *  Inport: '<S41>/T'
     */
    provaLOG_09_28_B.T = provaLOG_09_28_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S39>/Subsystem1' */

    /* Start for MATLABSystem: '<S19>/Serial Receive1' */
    provaLOG_09_28_DW.obj_m.matlabCodegenIsDeleted = false;
    provaLOG_09_28_DW.obj_m.Protocol = provaLOG_09_28_P.SerialReceive1_Protocol;
    provaLOG_09_28_DW.obj_m.isInitialized = 1;
    provaLOG_09_28_DW.obj_m.DataTypeWidth = 1U;
    if (provaLOG_09_28_DW.obj_m.DataTypeWidth > 2047) {
      provaLOG_09_28_DW.obj_m.DataSizeInBytes = MAX_uint16_T;
    } else {
      provaLOG_09_28_DW.obj_m.DataSizeInBytes = (uint16_T)
        (provaLOG_09_28_DW.obj_m.DataTypeWidth << 5);
    }

    MW_SCI_Open(0);
    provaLOG_09_28_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S19>/Serial Receive1' */

    /* Start for MATLABSystem: '<S2>/Serial Transmit1' */
    provaLOG_09_28_DW.obj.matlabCodegenIsDeleted = false;
    provaLOG_09_28_DW.obj.Protocol = provaLOG_09_28_P.SerialTransmit1_Protocol;
    provaLOG_09_28_DW.obj.isInitialized = 1;
    provaLOG_09_28_DW.obj.port = 2.0;
    provaLOG_09_28_DW.obj.dataSizeInBytes = 1.0;
    provaLOG_09_28_DW.obj.dataType = 0.0;
    provaLOG_09_28_DW.obj.sendModeEnum = 0.0;
    provaLOG_09_28_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(provaLOG_09_28_DW.obj.port);
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
    provaLOG_09_28_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit1' */
  }
}

/* Model terminate function */
void provaLOG_09_28_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S19>/Serial Receive1' */
  if (!provaLOG_09_28_DW.obj_m.matlabCodegenIsDeleted) {
    provaLOG_09_28_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S19>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S3>/One_time_initialization' */
  One_time_initializatio_Term(&provaLOG_09_28_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S3>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S3>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S35>/I2C Read12' */
  obj = &provaLOG_09_28_DW.obj_f;
  if (!provaLOG_09_28_DW.obj_f.matlabCodegenIsDeleted) {
    provaLOG_09_28_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((provaLOG_09_28_DW.obj_f.isInitialized == 1) &&
        provaLOG_09_28_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S35>/I2C Read1' */
  obj = &provaLOG_09_28_DW.obj_d;
  if (!provaLOG_09_28_DW.obj_d.matlabCodegenIsDeleted) {
    provaLOG_09_28_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((provaLOG_09_28_DW.obj_d.isInitialized == 1) &&
        provaLOG_09_28_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S3>/Execution_loop' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S17>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S18>/Serial Transmit' */
  if (!provaLOG_09_28_DW.obj_j.matlabCodegenIsDeleted) {
    provaLOG_09_28_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S18>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
  if (!provaLOG_09_28_DW.obj.matlabCodegenIsDeleted) {
    provaLOG_09_28_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
