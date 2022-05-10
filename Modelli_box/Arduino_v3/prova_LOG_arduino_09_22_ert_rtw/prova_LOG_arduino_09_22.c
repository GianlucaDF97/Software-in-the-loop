/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_arduino_09_22.c
 *
 * Code generated for Simulink model 'prova_LOG_arduino_09_22'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 16:59:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_LOG_arduino_09_22.h"
#include "prova_LOG_arduino_09_22_private.h"

/* Block signals (default storage) */
B_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_B;

/* Block states (default storage) */
DW_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_DW;

/* External inputs (root inport signals with default storage) */
ExtU_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_U;

/* Real-time model */
static RT_MODEL_prova_LOG_arduino_09_T prova_LOG_arduino_09_22_M_;
RT_MODEL_prova_LOG_arduino_09_T *const prova_LOG_arduino_09_22_M =
  &prova_LOG_arduino_09_22_M_;

/* Forward declaration for local functions */
static void prova_LOG_arduino_09_2_eml_find(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static boolean_T prova_LOG_arduino_0_ifWhileCond(const boolean_T x[5]);
static void prova_LOG_arduino_09_eml_find_g(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void prova_LOG_arduino_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_LOG_arduino_09_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T prova_LOG_arduino__copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void prova_LOG_arduino_09__readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_LOG_arduino_09_str2double(const char_T s[2]);
static boolean_T prova_LOG_arduino__copydigits_f(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void prova_LOG_arduino_0_readfloat_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T prova_LOG_arduino__str2double_b(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T prova_LOG_arduino_09_isUnitImag(const char_T s[3], int32_T k);
static void prova_LOG_ardui_readNonFinite_p(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_LOG_arduino_copydigits_fx(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T prova_LOG_arduin_copyexponent_n(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void prova_LOG_arduino__readfloat_of(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_LOG_arduino_str2double_bq(const char_T s[3]);
static void prova_LOG_ardu_readNonFinite_pe(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T prova_LOG_arduin_copydigits_fxt(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T prova_LOG_ardui_copyexponent_nt(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void prova_LOG_arduino_readfloat_ofr(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_LOG_arduin_str2double_bqm(char_T s);
static real_T prova_LOG_arduino_09_22_hex2dec(const char_T s[2]);
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

/* System initialize for enable system: '<S1>/One_time_initialization' */
void pr_One_time_initialization_Init(B_One_time_initialization_pro_T *localB,
  DW_One_time_initialization_pr_T *localDW, P_One_time_initialization_pro_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_l_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S11>/I2C Read' */
  localDW->obj_ny.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ny;
  localDW->obj_ny.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ny.isInitialized = 0;
  localDW->obj_ny.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ny.matlabCodegenIsDeleted = false;
  localDW->obj_ny.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_ny;
  localDW->obj_ny.isSetupComplete = false;
  localDW->obj_ny.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ny.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ny.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ny.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read1' */
  localDW->obj_jx.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_jx;
  localDW->obj_jx.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_jx.isInitialized = 0;
  localDW->obj_jx.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_jx.matlabCodegenIsDeleted = false;
  localDW->obj_jx.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_jx;
  localDW->obj_jx.isSetupComplete = false;
  localDW->obj_jx.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_jx.BusSpeed = 100000U;
  varargin_1 = localDW->obj_jx.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_jx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read2' */
  localDW->obj_c.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_c;
  localDW->obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_c.isInitialized = 0;
  localDW->obj_c.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_c.matlabCodegenIsDeleted = false;
  localDW->obj_c.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_c;
  localDW->obj_c.isSetupComplete = false;
  localDW->obj_c.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_c.BusSpeed = 100000U;
  varargin_1 = localDW->obj_c.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read3' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read4' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read5' */
  localDW->obj_bu.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_bu;
  localDW->obj_bu.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_bu.isInitialized = 0;
  localDW->obj_bu.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_bu.matlabCodegenIsDeleted = false;
  localDW->obj_bu.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_bu;
  localDW->obj_bu.isSetupComplete = false;
  localDW->obj_bu.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_bu.BusSpeed = 100000U;
  varargin_1 = localDW->obj_bu.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_bu.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read6' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read7' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read8' */
  localDW->obj_k.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_k;
  localDW->obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_k.isInitialized = 0;
  localDW->obj_k.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_k.matlabCodegenIsDeleted = false;
  localDW->obj_k.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_k;
  localDW->obj_k.isSetupComplete = false;
  localDW->obj_k.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_k.BusSpeed = 100000U;
  varargin_1 = localDW->obj_k.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read10' */
  localDW->obj_cb.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_cb;
  localDW->obj_cb.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_cb.isInitialized = 0;
  localDW->obj_cb.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_cb.matlabCodegenIsDeleted = false;
  localDW->obj_cb.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_cb;
  localDW->obj_cb.isSetupComplete = false;
  localDW->obj_cb.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_cb.BusSpeed = 100000U;
  varargin_1 = localDW->obj_cb.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_cb.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read11' */
  localDW->obj_j.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_j;
  localDW->obj_j.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_j.isInitialized = 0;
  localDW->obj_j.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_j.matlabCodegenIsDeleted = false;
  localDW->obj_j.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
  obj = &localDW->obj_j;
  localDW->obj_j.isSetupComplete = false;
  localDW->obj_j.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_j.BusSpeed = 100000U;
  varargin_1 = localDW->obj_j.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Write1' */
  localDW->obj_bh.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_bh;
  localDW->obj_bh.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_bh.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_bh.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_bh;
  localDW->obj_bh.isSetupComplete = false;
  localDW->obj_bh.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_bh.BusSpeed = 100000U;
  varargin_1 = localDW->obj_bh.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_bh.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Write2' */
  localDW->obj_a.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_a;
  localDW->obj_a.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_a.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_a.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_a;
  localDW->obj_a.isSetupComplete = false;
  localDW->obj_a.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_a.BusSpeed = 100000U;
  varargin_1 = localDW->obj_a.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Write3' */
  localDW->obj_js.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_js;
  localDW->obj_js.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_js.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_js.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_js;
  localDW->obj_js.isSetupComplete = false;
  localDW->obj_js.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_js.BusSpeed = 100000U;
  varargin_1 = localDW->obj_js.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_js.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/I2C Read12' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read' incorporates:
   *  Outport: '<S11>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read1' incorporates:
   *  Outport: '<S11>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read2' incorporates:
   *  Outport: '<S11>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read3' incorporates:
   *  Outport: '<S11>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read4' incorporates:
   *  Outport: '<S11>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read5' incorporates:
   *  Outport: '<S11>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read6' incorporates:
   *  Outport: '<S11>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read7' incorporates:
   *  Outport: '<S11>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read8' incorporates:
   *  Outport: '<S11>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read9' incorporates:
   *  Outport: '<S11>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read10' incorporates:
   *  Outport: '<S11>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S11>/I2C Read11' incorporates:
   *  Outport: '<S11>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S11>/Byte Unpack' incorporates:
     *  Outport: '<S11>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S1>/One_time_initialization' */
void prova_L_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_pro_T *localB, DW_One_time_initialization_pr_T
  *localDW, P_One_time_initialization_pro_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S1>/One_time_initialization' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S11>/I2C Write3' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic1'
     *  Constant: '<S11>/registro memoria2 '
     *  DataTypeConversion: '<S11>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S11>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S11>/I2C Read' */
    if (localDW->obj_ny.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_ny.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ny.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ny.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S11>/I2C Read' */

    /* MATLABSystem: '<S11>/I2C Read1' */
    if (localDW->obj_jx.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_jx.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_jx.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_jx.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read1' */

    /* MATLABSystem: '<S11>/I2C Read2' */
    if (localDW->obj_c.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_c.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read2' */

    /* MATLABSystem: '<S11>/I2C Read3' */
    if (localDW->obj_n.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_n.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S11>/I2C Read3' */

    /* MATLABSystem: '<S11>/I2C Read4' */
    if (localDW->obj_m.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_m.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read4' */

    /* MATLABSystem: '<S11>/I2C Read5' */
    if (localDW->obj_bu.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_bu.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_bu.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_bu.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read5' */

    /* MATLABSystem: '<S11>/I2C Read6' */
    if (localDW->obj_l.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_l.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read6' */

    /* MATLABSystem: '<S11>/I2C Read7' */
    if (localDW->obj_b.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_b.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
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
      /* MATLABSystem: '<S11>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read7' */

    /* MATLABSystem: '<S11>/I2C Read8' */
    if (localDW->obj_k.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_k.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_k.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read8' */

    /* MATLABSystem: '<S11>/I2C Read9' */
    if (localDW->obj.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
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
      /* MATLABSystem: '<S11>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read9' */

    /* MATLABSystem: '<S11>/I2C Read10' */
    if (localDW->obj_cb.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_cb.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_cb.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_cb.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read10' */

    /* MATLABSystem: '<S11>/I2C Read11' */
    if (localDW->obj_j.SampleTime != prova_LOG_arduino_09_22_P.t_AP) {
      localDW->obj_j.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_j.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S11>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S11>/I2C Read11' */

    /* MATLABSystem: '<S11>/I2C Write1' incorporates:
     *  Constant: '<S11>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_bh.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S11>/I2C Write2' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_a.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S11>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_js.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S11>/I2C Read12' */
    if (localDW->obj_o.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_o.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S11>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S11>/Byte Unpack' */

    /* Unpack: <S11>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S1>/One_time_initialization' */
}

/* Termination for enable system: '<S1>/One_time_initialization' */
void pr_One_time_initialization_Term(DW_One_time_initialization_pr_T *localDW)
{
  codertarget_arduinobase_int_l_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S11>/I2C Read' */
  obj = &localDW->obj_ny;
  if (!localDW->obj_ny.matlabCodegenIsDeleted) {
    localDW->obj_ny.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ny.isInitialized == 1) && localDW->obj_ny.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read1' */
  obj = &localDW->obj_jx;
  if (!localDW->obj_jx.matlabCodegenIsDeleted) {
    localDW->obj_jx.matlabCodegenIsDeleted = true;
    if ((localDW->obj_jx.isInitialized == 1) && localDW->obj_jx.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read2' */
  obj = &localDW->obj_c;
  if (!localDW->obj_c.matlabCodegenIsDeleted) {
    localDW->obj_c.matlabCodegenIsDeleted = true;
    if ((localDW->obj_c.isInitialized == 1) && localDW->obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read3' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read4' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read5' */
  obj = &localDW->obj_bu;
  if (!localDW->obj_bu.matlabCodegenIsDeleted) {
    localDW->obj_bu.matlabCodegenIsDeleted = true;
    if ((localDW->obj_bu.isInitialized == 1) && localDW->obj_bu.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read6' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read7' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read8' */
  obj = &localDW->obj_k;
  if (!localDW->obj_k.matlabCodegenIsDeleted) {
    localDW->obj_k.matlabCodegenIsDeleted = true;
    if ((localDW->obj_k.isInitialized == 1) && localDW->obj_k.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read10' */
  obj = &localDW->obj_cb;
  if (!localDW->obj_cb.matlabCodegenIsDeleted) {
    localDW->obj_cb.matlabCodegenIsDeleted = true;
    if ((localDW->obj_cb.isInitialized == 1) && localDW->obj_cb.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read11' */
  obj = &localDW->obj_j;
  if (!localDW->obj_j.matlabCodegenIsDeleted) {
    localDW->obj_j.matlabCodegenIsDeleted = true;
    if ((localDW->obj_j.isInitialized == 1) && localDW->obj_j.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S11>/I2C Write1' */
  obj_0 = &localDW->obj_bh;
  if (!localDW->obj_bh.matlabCodegenIsDeleted) {
    localDW->obj_bh.matlabCodegenIsDeleted = true;
    if ((localDW->obj_bh.isInitialized == 1) && localDW->obj_bh.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S11>/I2C Write2' */
  obj_0 = &localDW->obj_a;
  if (!localDW->obj_a.matlabCodegenIsDeleted) {
    localDW->obj_a.matlabCodegenIsDeleted = true;
    if ((localDW->obj_a.isInitialized == 1) && localDW->obj_a.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S11>/I2C Write3' */
  obj_0 = &localDW->obj_js;
  if (!localDW->obj_js.matlabCodegenIsDeleted) {
    localDW->obj_js.matlabCodegenIsDeleted = true;
    if ((localDW->obj_js.isInitialized == 1) && localDW->obj_js.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S11>/I2C Read12' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/I2C Read12' */
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino_09_2_eml_find(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduino_0_ifWhileCond(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino_09_eml_find_g(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduino_09_copydigits(char_T s1[4], int32_T *idx,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduino__copyexponent(char_T s1[4], int32_T *idx,
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

      prova_LOG_arduino_09_22_B.kexp_n = *k;
      b_k = *k;
      b_success = prova_LOG_arduino_09_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > prova_LOG_arduino_09_22_B.kexp_n));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino_09__readfloat(char_T s1[4], int32_T *idx, const
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
            prova_LOG_arduino_09__readfloat(s1, idx, s, k, false, &isneg,
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
      prova_LOG_arduino_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_LOG_arduino_09_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = prova_LOG_arduino__copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static creal_T prova_LOG_arduino_09_str2double(const char_T s[2])
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
  prova_LOG_arduino_09_22_B.ntoread_b = 0;
  prova_LOG_arduino_09_22_B.k_lx = 0;
  while ((prova_LOG_arduino_09_22_B.k_lx + 1 <= 2) && (c[(uint8_T)
          s[prova_LOG_arduino_09_22_B.k_lx] & 127] ||
          (s[prova_LOG_arduino_09_22_B.k_lx] == '\x00'))) {
    prova_LOG_arduino_09_22_B.k_lx++;
  }

  isimag1 = false;
  b_finite = true;
  prova_LOG_arduino_09_22_B.scanned1_g = 0.0;
  prova_LOG_arduino_09_22_B.idx_o = 1;
  prova_LOG_arduino_09_22_B.s1_g[0] = '\x00';
  prova_LOG_arduino_09_22_B.s1_g[1] = '\x00';
  prova_LOG_arduino_09_22_B.s1_g[2] = '\x00';
  prova_LOG_arduino_09_22_B.s1_g[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_arduino_09_22_B.k_lx + 1 <= 2)) {
    if (s[prova_LOG_arduino_09_22_B.k_lx] == '-') {
      isneg = !isneg;
      prova_LOG_arduino_09_22_B.k_lx++;
    } else if ((s[prova_LOG_arduino_09_22_B.k_lx] == ',') ||
               (s[prova_LOG_arduino_09_22_B.k_lx] == '+') || c[(uint8_T)
               s[prova_LOG_arduino_09_22_B.k_lx] & 127]) {
      prova_LOG_arduino_09_22_B.k_lx++;
    } else {
      exitg1 = true;
    }
  }

  success = (prova_LOG_arduino_09_22_B.k_lx + 1 <= 2);
  if (success && isneg) {
    prova_LOG_arduino_09_22_B.s1_g[0] = '-';
    prova_LOG_arduino_09_22_B.idx_o = 2;
  }

  prova_LOG_arduino_09_22_B.e_k = prova_LOG_arduino_09_22_B.k_lx + 1;
  if (success) {
    if ((prova_LOG_arduino_09_22_B.k_lx + 1 <= 2) &&
        ((s[prova_LOG_arduino_09_22_B.k_lx] == 'j') ||
         (s[prova_LOG_arduino_09_22_B.k_lx] == 'i'))) {
      isimag1 = true;
      prova_LOG_arduino_09_22_B.e_k = prova_LOG_arduino_09_22_B.k_lx + 2;
      while ((prova_LOG_arduino_09_22_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] ||
              (s[1] == '\x00') || (s[1] == ','))) {
        prova_LOG_arduino_09_22_B.e_k = 3;
      }

      if ((prova_LOG_arduino_09_22_B.e_k <= 2) && (s[1] == '*')) {
        prova_LOG_arduino_09_22_B.e_k = 3;
        prova_LOG_arduino_09__readfloat(prova_LOG_arduino_09_22_B.s1_g,
          &prova_LOG_arduino_09_22_B.idx_o, s, &prova_LOG_arduino_09_22_B.e_k,
          false, &isneg, &b_finite, &prova_LOG_arduino_09_22_B.scanned1_g,
          &unusedU2, &success);
      } else {
        prova_LOG_arduino_09_22_B.s1_g[prova_LOG_arduino_09_22_B.idx_o - 1] =
          '1';
        prova_LOG_arduino_09_22_B.idx_o++;
      }
    } else {
      prova_LOG_arduino_09_22_B.e_k = prova_LOG_arduino_09_22_B.k_lx + 1;
      prova_LOG_arduino_readNonFinite(s, &prova_LOG_arduino_09_22_B.e_k,
        &b_finite, &prova_LOG_arduino_09_22_B.scanned1_g);
      if (b_finite) {
        success = prova_LOG_arduino_09_copydigits(prova_LOG_arduino_09_22_B.s1_g,
          &prova_LOG_arduino_09_22_B.idx_o, s, &prova_LOG_arduino_09_22_B.e_k,
          true);
        if (success) {
          success = prova_LOG_arduino__copyexponent
            (prova_LOG_arduino_09_22_B.s1_g, &prova_LOG_arduino_09_22_B.idx_o, s,
             &prova_LOG_arduino_09_22_B.e_k);
        }
      } else {
        if ((prova_LOG_arduino_09_22_B.idx_o >= 2) &&
            (prova_LOG_arduino_09_22_B.s1_g[0] == '-')) {
          prova_LOG_arduino_09_22_B.idx_o = 1;
          prova_LOG_arduino_09_22_B.s1_g[0] = ' ';
          prova_LOG_arduino_09_22_B.scanned1_g =
            -prova_LOG_arduino_09_22_B.scanned1_g;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (prova_LOG_arduino_09_22_B.e_k <= 2)) {
        tmp = s[prova_LOG_arduino_09_22_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          prova_LOG_arduino_09_22_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((prova_LOG_arduino_09_22_B.e_k <= 2) &&
          (s[prova_LOG_arduino_09_22_B.e_k - 1] == '*')) {
        prova_LOG_arduino_09_22_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (prova_LOG_arduino_09_22_B.e_k <= 2)) {
          tmp = s[prova_LOG_arduino_09_22_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            prova_LOG_arduino_09_22_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (prova_LOG_arduino_09_22_B.e_k <= 2) {
        tmp = s[prova_LOG_arduino_09_22_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          prova_LOG_arduino_09_22_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (prova_LOG_arduino_09_22_B.e_k <= 2)) {
      tmp = s[prova_LOG_arduino_09_22_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        prova_LOG_arduino_09_22_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    prova_LOG_arduino_09_22_B.ntoread_b = 1;
  }

  if (success && (prova_LOG_arduino_09_22_B.e_k <= 2)) {
    prova_LOG_arduino_09_22_B.s1_g[prova_LOG_arduino_09_22_B.idx_o - 1] = ' ';
    prova_LOG_arduino_09_22_B.idx_o++;
    prova_LOG_arduino_09__readfloat(prova_LOG_arduino_09_22_B.s1_g,
      &prova_LOG_arduino_09_22_B.idx_o, s, &prova_LOG_arduino_09_22_B.e_k, true,
      &success, &isneg, &prova_LOG_arduino_09_22_B.scanned2_m, &unusedU2,
      &c_success);
    if (isneg) {
      prova_LOG_arduino_09_22_B.ntoread_b++;
    }

    success = (c_success && (prova_LOG_arduino_09_22_B.e_k > 2) && (isimag1 !=
                success) && unusedU2);
  } else {
    prova_LOG_arduino_09_22_B.scanned2_m = 0.0;
  }

  if (success) {
    prova_LOG_arduino_09_22_B.s1_g[prova_LOG_arduino_09_22_B.idx_o - 1] = '\x00';
    switch (prova_LOG_arduino_09_22_B.ntoread_b) {
     case 2:
      prova_LOG_arduino_09_22_B.ntoread_b = sscanf
        (&prova_LOG_arduino_09_22_B.s1_g[0], "%lf %lf",
         &prova_LOG_arduino_09_22_B.scanned1_g,
         &prova_LOG_arduino_09_22_B.scanned2_m);
      if (prova_LOG_arduino_09_22_B.ntoread_b != 2) {
        prova_LOG_arduino_09_22_B.scanned1_g = (rtNaN);
        prova_LOG_arduino_09_22_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      prova_LOG_arduino_09_22_B.ntoread_b = sscanf
        (&prova_LOG_arduino_09_22_B.s1_g[0], "%lf",
         &prova_LOG_arduino_09_22_B.b_scanned1_n);
      if (b_finite) {
        if (prova_LOG_arduino_09_22_B.ntoread_b == 1) {
          prova_LOG_arduino_09_22_B.scanned1_g =
            prova_LOG_arduino_09_22_B.b_scanned1_n;
        } else {
          prova_LOG_arduino_09_22_B.scanned1_g = (rtNaN);
        }
      } else if (prova_LOG_arduino_09_22_B.ntoread_b == 1) {
        prova_LOG_arduino_09_22_B.scanned2_m =
          prova_LOG_arduino_09_22_B.b_scanned1_n;
      } else {
        prova_LOG_arduino_09_22_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_LOG_arduino_09_22_B.scanned2_m;
      x.im = prova_LOG_arduino_09_22_B.scanned1_g;
    } else {
      x.re = prova_LOG_arduino_09_22_B.scanned1_g;
      x.im = prova_LOG_arduino_09_22_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduino__copydigits_f(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino_0_readfloat_o(char_T s1_data[], int32_T *idx,
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
          prova_LOG_arduino_0_readfloat_o(s1_data, idx, s_data, k, n, false,
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
        *success = prova_LOG_arduino__copydigits_f(s1_data, &b_idx, s_data, &h_k,
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
              isneg = prova_LOG_arduino__copydigits_f(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static creal_T prova_LOG_arduino__str2double_b(const char_T s_data[], const
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
    prova_LOG_arduino_09_22_B.ntoread = 0;
    prova_LOG_arduino_09_22_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (prova_LOG_arduino_09_22_B.k <= s_size[1])) {
      tmp = s_data[prova_LOG_arduino_09_22_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        prova_LOG_arduino_09_22_B.k++;
      } else {
        exitg1 = true;
      }
    }

    prova_LOG_arduino_09_22_B.s1_size[0] = 1;
    prova_LOG_arduino_09_22_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    prova_LOG_arduino_09_22_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= prova_LOG_arduino_09_22_B.idx) {
      memset(&prova_LOG_arduino_09_22_B.s1_data[0], 0,
             (prova_LOG_arduino_09_22_B.idx + 1) * sizeof(char_T));
    }

    prova_LOG_arduino_09_22_B.idx = 1;
    prova_LOG_arduino_0_readfloat_o(prova_LOG_arduino_09_22_B.s1_data,
      &prova_LOG_arduino_09_22_B.idx, s_data, &prova_LOG_arduino_09_22_B.k,
      s_size[1], true, &isimag1, &isfinite1, &prova_LOG_arduino_09_22_B.scanned1,
      &unusedU0, &success);
    if (isfinite1) {
      prova_LOG_arduino_09_22_B.ntoread = 1;
    }

    if (success) {
      if (prova_LOG_arduino_09_22_B.k <= s_size[1]) {
        prova_LOG_arduino_09_22_B.s1_data[prova_LOG_arduino_09_22_B.idx - 1] =
          ' ';
        prova_LOG_arduino_09_22_B.idx++;
        prova_LOG_arduino_0_readfloat_o(prova_LOG_arduino_09_22_B.s1_data,
          &prova_LOG_arduino_09_22_B.idx, s_data, &prova_LOG_arduino_09_22_B.k,
          s_size[1], true, &unusedU0, &success,
          &prova_LOG_arduino_09_22_B.scanned2, &foundsign, &c_success);
        if (success) {
          prova_LOG_arduino_09_22_B.ntoread++;
        }

        success = (c_success && ((prova_LOG_arduino_09_22_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        prova_LOG_arduino_09_22_B.scanned2 = 0.0;
      }
    } else {
      prova_LOG_arduino_09_22_B.scanned2 = 0.0;
    }

    if (success) {
      prova_LOG_arduino_09_22_B.s1_data[prova_LOG_arduino_09_22_B.idx - 1] =
        '\x00';
      switch (prova_LOG_arduino_09_22_B.ntoread) {
       case 2:
        prova_LOG_arduino_09_22_B.ntoread = sscanf
          (&prova_LOG_arduino_09_22_B.s1_data[0], "%lf %lf",
           &prova_LOG_arduino_09_22_B.scanned1,
           &prova_LOG_arduino_09_22_B.scanned2);
        if (prova_LOG_arduino_09_22_B.ntoread != 2) {
          prova_LOG_arduino_09_22_B.scanned1 = (rtNaN);
          prova_LOG_arduino_09_22_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        prova_LOG_arduino_09_22_B.ntoread = sscanf
          (&prova_LOG_arduino_09_22_B.s1_data[0], "%lf",
           &prova_LOG_arduino_09_22_B.b_scanned1);
        if (isfinite1) {
          if (prova_LOG_arduino_09_22_B.ntoread == 1) {
            prova_LOG_arduino_09_22_B.scanned1 =
              prova_LOG_arduino_09_22_B.b_scanned1;
          } else {
            prova_LOG_arduino_09_22_B.scanned1 = (rtNaN);
          }
        } else if (prova_LOG_arduino_09_22_B.ntoread == 1) {
          prova_LOG_arduino_09_22_B.scanned2 =
            prova_LOG_arduino_09_22_B.b_scanned1;
        } else {
          prova_LOG_arduino_09_22_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = prova_LOG_arduino_09_22_B.scanned2;
        x.im = prova_LOG_arduino_09_22_B.scanned1;
      } else {
        x.re = prova_LOG_arduino_09_22_B.scanned1;
        x.im = prova_LOG_arduino_09_22_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduino_09_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_ardui_readNonFinite_p(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduino_copydigits_fx(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduin_copyexponent_n(char_T s1[5], int32_T *idx,
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

      prova_LOG_arduino_09_22_B.kexp = *k;
      b_k = *k;
      b_success = prova_LOG_arduino_copydigits_fx(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > prova_LOG_arduino_09_22_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino__readfloat_of(char_T s1[5], int32_T *idx, const
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
    if (prova_LOG_arduino_09_isUnitImag(s, b_k)) {
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
          prova_LOG_arduino__readfloat_of(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      prova_LOG_ardui_readNonFinite_p(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_LOG_arduino_copydigits_fx(s1, idx, s, k, true);
        if (*success) {
          *success = prova_LOG_arduin_copyexponent_n(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static creal_T prova_LOG_arduino_str2double_bq(const char_T s[3])
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
  prova_LOG_arduino_09_22_B.ntoread_d = 0;
  prova_LOG_arduino_09_22_B.k_l = 1;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_arduino_09_22_B.k_l <= 3)) {
    tmp = s[prova_LOG_arduino_09_22_B.k_l - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      prova_LOG_arduino_09_22_B.k_l++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  prova_LOG_arduino_09_22_B.scanned1_c = 0.0;
  prova_LOG_arduino_09_22_B.idx_d = 1;
  for (prova_LOG_arduino_09_22_B.b_k = 0; prova_LOG_arduino_09_22_B.b_k < 5;
       prova_LOG_arduino_09_22_B.b_k++) {
    prova_LOG_arduino_09_22_B.s1[prova_LOG_arduino_09_22_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_arduino_09_22_B.k_l <= 3)) {
    tmp = s[prova_LOG_arduino_09_22_B.k_l - 1];
    if (tmp == '-') {
      isneg = !isneg;
      prova_LOG_arduino_09_22_B.k_l++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      prova_LOG_arduino_09_22_B.k_l++;
    } else {
      exitg1 = true;
    }
  }

  success = (prova_LOG_arduino_09_22_B.k_l <= 3);
  if (success && isneg) {
    prova_LOG_arduino_09_22_B.s1[0] = '-';
    prova_LOG_arduino_09_22_B.idx_d = 2;
  }

  prova_LOG_arduino_09_22_B.b_k = prova_LOG_arduino_09_22_B.k_l - 1;
  if (success) {
    if (prova_LOG_arduino_09_isUnitImag(s, prova_LOG_arduino_09_22_B.k_l)) {
      isimag1 = true;
      prova_LOG_arduino_09_22_B.b_k = prova_LOG_arduino_09_22_B.k_l;
      while ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[prova_LOG_arduino_09_22_B.b_k] & 127] ||
              (s[prova_LOG_arduino_09_22_B.b_k] == '\x00') ||
              (s[prova_LOG_arduino_09_22_B.b_k] == ','))) {
        prova_LOG_arduino_09_22_B.b_k++;
      }

      if ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) &&
          (s[prova_LOG_arduino_09_22_B.b_k] == '*')) {
        prova_LOG_arduino_09_22_B.k_l = prova_LOG_arduino_09_22_B.b_k + 2;
        prova_LOG_arduino__readfloat_of(prova_LOG_arduino_09_22_B.s1,
          &prova_LOG_arduino_09_22_B.idx_d, s, &prova_LOG_arduino_09_22_B.k_l,
          false, &isneg, &b_finite, &prova_LOG_arduino_09_22_B.scanned1_c,
          &unusedU2, &success);
        prova_LOG_arduino_09_22_B.b_k = prova_LOG_arduino_09_22_B.k_l - 1;
      } else {
        prova_LOG_arduino_09_22_B.s1[prova_LOG_arduino_09_22_B.idx_d - 1] = '1';
        prova_LOG_arduino_09_22_B.idx_d++;
      }
    } else {
      prova_LOG_ardui_readNonFinite_p(s, &prova_LOG_arduino_09_22_B.k_l,
        &b_finite, &prova_LOG_arduino_09_22_B.scanned1_c);
      prova_LOG_arduino_09_22_B.b_k = prova_LOG_arduino_09_22_B.k_l - 1;
      if (b_finite) {
        success = prova_LOG_arduino_copydigits_fx(prova_LOG_arduino_09_22_B.s1,
          &prova_LOG_arduino_09_22_B.idx_d, s, &prova_LOG_arduino_09_22_B.k_l,
          true);
        prova_LOG_arduino_09_22_B.b_k = prova_LOG_arduino_09_22_B.k_l - 1;
        if (success) {
          success = prova_LOG_arduin_copyexponent_n(prova_LOG_arduino_09_22_B.s1,
            &prova_LOG_arduino_09_22_B.idx_d, s, &prova_LOG_arduino_09_22_B.k_l);
          prova_LOG_arduino_09_22_B.b_k = prova_LOG_arduino_09_22_B.k_l - 1;
        }
      } else {
        if ((prova_LOG_arduino_09_22_B.idx_d >= 2) &&
            (prova_LOG_arduino_09_22_B.s1[0] == '-')) {
          prova_LOG_arduino_09_22_B.idx_d = 1;
          prova_LOG_arduino_09_22_B.s1[0] = ' ';
          prova_LOG_arduino_09_22_B.scanned1_c =
            -prova_LOG_arduino_09_22_B.scanned1_c;
        }
      }

      while ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[prova_LOG_arduino_09_22_B.b_k] & 127] ||
              (s[prova_LOG_arduino_09_22_B.b_k] == '\x00') ||
              (s[prova_LOG_arduino_09_22_B.b_k] == ','))) {
        prova_LOG_arduino_09_22_B.b_k++;
      }

      if ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) &&
          (s[prova_LOG_arduino_09_22_B.b_k] == '*')) {
        prova_LOG_arduino_09_22_B.b_k++;
        while ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[prova_LOG_arduino_09_22_B.b_k] & 127] ||
                (s[prova_LOG_arduino_09_22_B.b_k] == '\x00') ||
                (s[prova_LOG_arduino_09_22_B.b_k] == ','))) {
          prova_LOG_arduino_09_22_B.b_k++;
        }
      }

      if ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) &&
          ((s[prova_LOG_arduino_09_22_B.b_k] == 'i') ||
           (s[prova_LOG_arduino_09_22_B.b_k] == 'j'))) {
        prova_LOG_arduino_09_22_B.b_k++;
        isimag1 = true;
      }
    }

    while ((prova_LOG_arduino_09_22_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[prova_LOG_arduino_09_22_B.b_k] & 127] ||
            (s[prova_LOG_arduino_09_22_B.b_k] == '\x00') ||
            (s[prova_LOG_arduino_09_22_B.b_k] == ','))) {
      prova_LOG_arduino_09_22_B.b_k++;
    }
  }

  if (b_finite) {
    prova_LOG_arduino_09_22_B.ntoread_d = 1;
  }

  if (success && (prova_LOG_arduino_09_22_B.b_k + 1 <= 3)) {
    prova_LOG_arduino_09_22_B.s1[prova_LOG_arduino_09_22_B.idx_d - 1] = ' ';
    prova_LOG_arduino_09_22_B.idx_d++;
    prova_LOG_arduino_09_22_B.k_l = prova_LOG_arduino_09_22_B.b_k + 1;
    prova_LOG_arduino__readfloat_of(prova_LOG_arduino_09_22_B.s1,
      &prova_LOG_arduino_09_22_B.idx_d, s, &prova_LOG_arduino_09_22_B.k_l, true,
      &success, &isneg, &prova_LOG_arduino_09_22_B.scanned2_f, &unusedU2,
      &c_success);
    if (isneg) {
      prova_LOG_arduino_09_22_B.ntoread_d++;
    }

    success = (c_success && (prova_LOG_arduino_09_22_B.k_l > 3) && (isimag1 !=
                success) && unusedU2);
  } else {
    prova_LOG_arduino_09_22_B.scanned2_f = 0.0;
  }

  if (success) {
    prova_LOG_arduino_09_22_B.s1[prova_LOG_arduino_09_22_B.idx_d - 1] = '\x00';
    switch (prova_LOG_arduino_09_22_B.ntoread_d) {
     case 2:
      prova_LOG_arduino_09_22_B.ntoread_d = sscanf
        (&prova_LOG_arduino_09_22_B.s1[0], "%lf %lf",
         &prova_LOG_arduino_09_22_B.scanned1_c,
         &prova_LOG_arduino_09_22_B.scanned2_f);
      if (prova_LOG_arduino_09_22_B.ntoread_d != 2) {
        prova_LOG_arduino_09_22_B.scanned1_c = (rtNaN);
        prova_LOG_arduino_09_22_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      prova_LOG_arduino_09_22_B.ntoread_d = sscanf
        (&prova_LOG_arduino_09_22_B.s1[0], "%lf",
         &prova_LOG_arduino_09_22_B.b_scanned1_g);
      if (b_finite) {
        if (prova_LOG_arduino_09_22_B.ntoread_d == 1) {
          prova_LOG_arduino_09_22_B.scanned1_c =
            prova_LOG_arduino_09_22_B.b_scanned1_g;
        } else {
          prova_LOG_arduino_09_22_B.scanned1_c = (rtNaN);
        }
      } else if (prova_LOG_arduino_09_22_B.ntoread_d == 1) {
        prova_LOG_arduino_09_22_B.scanned2_f =
          prova_LOG_arduino_09_22_B.b_scanned1_g;
      } else {
        prova_LOG_arduino_09_22_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_LOG_arduino_09_22_B.scanned2_f;
      x.im = prova_LOG_arduino_09_22_B.scanned1_c;
    } else {
      x.re = prova_LOG_arduino_09_22_B.scanned1_c;
      x.im = prova_LOG_arduino_09_22_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_ardu_readNonFinite_pe(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_arduin_copydigits_fxt(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static boolean_T prova_LOG_ardui_copyexponent_nt(char_T s1[3], int32_T *idx,
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
    b_success = prova_LOG_arduin_copydigits_fxt(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static void prova_LOG_arduino_readfloat_ofr(char_T s1[3], int32_T *idx, char_T s,
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
          prova_LOG_arduino_readfloat_ofr(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      prova_LOG_ardu_readNonFinite_pe(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = prova_LOG_arduin_copydigits_fxt(s1, idx, s, k, true);
        if (*success) {
          *success = prova_LOG_ardui_copyexponent_nt(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static creal_T prova_LOG_arduin_str2double_bqm(char_T s)
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
  prova_LOG_arduino_09_22_B.ntoread_l = 0;
  prova_LOG_arduino_09_22_B.d_k = 1;
  prova_LOG_arduino_09_22_B.i_h = (uint8_T)s & 127;
  if (c[prova_LOG_arduino_09_22_B.i_h] || (s == '\x00')) {
    prova_LOG_arduino_09_22_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  prova_LOG_arduino_09_22_B.scanned1_p = 0.0;
  prova_LOG_arduino_09_22_B.idx_b = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (prova_LOG_arduino_09_22_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      prova_LOG_arduino_09_22_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[prova_LOG_arduino_09_22_B.i_h]) {
      prova_LOG_arduino_09_22_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (prova_LOG_arduino_09_22_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    prova_LOG_arduino_09_22_B.idx_b = 2;
  }

  if (success) {
    isneg = false;
    if (prova_LOG_arduino_09_22_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      prova_LOG_arduino_09_22_B.d_k++;
      s1[prova_LOG_arduino_09_22_B.idx_b - 1] = '1';
      prova_LOG_arduino_09_22_B.idx_b++;
    } else {
      prova_LOG_ardu_readNonFinite_pe(s, &prova_LOG_arduino_09_22_B.d_k,
        &b_finite, &prova_LOG_arduino_09_22_B.scanned1_p);
      if (b_finite) {
        success = prova_LOG_arduin_copydigits_fxt(s1,
          &prova_LOG_arduino_09_22_B.idx_b, s, &prova_LOG_arduino_09_22_B.d_k,
          true);
        if (success) {
          success = prova_LOG_ardui_copyexponent_nt(s1,
            &prova_LOG_arduino_09_22_B.idx_b, s, &prova_LOG_arduino_09_22_B.d_k);
        }
      } else {
        if ((prova_LOG_arduino_09_22_B.idx_b >= 2) && (s1[0] == '-')) {
          prova_LOG_arduino_09_22_B.idx_b = 1;
          s1[0] = ' ';
          prova_LOG_arduino_09_22_B.scanned1_p =
            -prova_LOG_arduino_09_22_B.scanned1_p;
        }
      }

      while ((prova_LOG_arduino_09_22_B.d_k <= 1) &&
             (c[prova_LOG_arduino_09_22_B.i_h] || ((s == '\x00') || (s == ','))))
      {
        prova_LOG_arduino_09_22_B.d_k = 2;
      }

      if ((prova_LOG_arduino_09_22_B.d_k <= 1) && (s == '*')) {
        prova_LOG_arduino_09_22_B.d_k = 2;
      }

      if ((prova_LOG_arduino_09_22_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        prova_LOG_arduino_09_22_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((prova_LOG_arduino_09_22_B.d_k <= 1) &&
           (c[prova_LOG_arduino_09_22_B.i_h] || ((s == '\x00') || (s == ','))))
    {
      prova_LOG_arduino_09_22_B.d_k = 2;
    }
  }

  if (b_finite) {
    prova_LOG_arduino_09_22_B.ntoread_l = 1;
  }

  if (success && (prova_LOG_arduino_09_22_B.d_k <= 1)) {
    s1[prova_LOG_arduino_09_22_B.idx_b - 1] = ' ';
    prova_LOG_arduino_09_22_B.idx_b++;
    prova_LOG_arduino_09_22_B.d_k = 1;
    prova_LOG_arduino_readfloat_ofr(s1, &prova_LOG_arduino_09_22_B.idx_b, s,
      &prova_LOG_arduino_09_22_B.d_k, true, &success, &isneg,
      &prova_LOG_arduino_09_22_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      prova_LOG_arduino_09_22_B.ntoread_l++;
    }

    success = (c_success && (prova_LOG_arduino_09_22_B.d_k > 1) && (isimag1 !=
                success) && foundsign);
  } else {
    prova_LOG_arduino_09_22_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[prova_LOG_arduino_09_22_B.idx_b - 1] = '\x00';
    switch (prova_LOG_arduino_09_22_B.ntoread_l) {
     case 2:
      prova_LOG_arduino_09_22_B.ntoread_l = sscanf(&s1[0], "%lf %lf",
        &prova_LOG_arduino_09_22_B.scanned1_p,
        &prova_LOG_arduino_09_22_B.scanned2_l);
      if (prova_LOG_arduino_09_22_B.ntoread_l != 2) {
        prova_LOG_arduino_09_22_B.scanned1_p = (rtNaN);
        prova_LOG_arduino_09_22_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      prova_LOG_arduino_09_22_B.ntoread_l = sscanf(&s1[0], "%lf",
        &prova_LOG_arduino_09_22_B.b_scanned1_j);
      if (b_finite) {
        if (prova_LOG_arduino_09_22_B.ntoread_l == 1) {
          prova_LOG_arduino_09_22_B.scanned1_p =
            prova_LOG_arduino_09_22_B.b_scanned1_j;
        } else {
          prova_LOG_arduino_09_22_B.scanned1_p = (rtNaN);
        }
      } else if (prova_LOG_arduino_09_22_B.ntoread_l == 1) {
        prova_LOG_arduino_09_22_B.scanned2_l =
          prova_LOG_arduino_09_22_B.b_scanned1_j;
      } else {
        prova_LOG_arduino_09_22_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_LOG_arduino_09_22_B.scanned2_l;
      x.im = prova_LOG_arduino_09_22_B.scanned1_p;
    } else {
      x.re = prova_LOG_arduino_09_22_B.scanned1_p;
      x.im = prova_LOG_arduino_09_22_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S18>/MATLAB Function' */
static real_T prova_LOG_arduino_09_22_hex2dec(const char_T s[2])
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

  prova_LOG_arduino_09_22_B.a = tmp_0;
  prova_LOG_arduino_09_22_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &prova_LOG_arduino_09_22_B.r3.chunks[0U],
                      2);
      tmp = tmp_2;
      MultiWordSub(&prova_LOG_arduino_09_22_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &prova_LOG_arduino_09_22_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &prova_LOG_arduino_09_22_B.r3.chunks[0U],
                      2);
      tmp = tmp_3;
      MultiWordSub(&prova_LOG_arduino_09_22_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &prova_LOG_arduino_09_22_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &prova_LOG_arduino_09_22_B.r3.chunks[0U],
                        2);
        tmp = tmp_4;
        MultiWordSub(&prova_LOG_arduino_09_22_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &prova_LOG_arduino_09_22_B.sk.chunks[0U], 2);
      } else {
        prova_LOG_arduino_09_22_B.sk = tmp_0;
      }
    } else {
      prova_LOG_arduino_09_22_B.sk = tmp_0;
    }

    uMultiWordMul(&prova_LOG_arduino_09_22_B.sk.chunks[0U], 2,
                  &prova_LOG_arduino_09_22_B.p16.chunks[0U], 2,
                  &prova_LOG_arduino_09_22_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&prova_LOG_arduino_09_22_B.r.chunks[0U], 4,
                         &prova_LOG_arduino_09_22_B.r3.chunks[0U], 2);
    MultiWordAdd(&prova_LOG_arduino_09_22_B.a.chunks[0U],
                 &prova_LOG_arduino_09_22_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    prova_LOG_arduino_09_22_B.a = tmp;
    uMultiWord2MultiWord(&prova_LOG_arduino_09_22_B.p16.chunks[0U], 2,
                         &prova_LOG_arduino_09_22_B.r2.chunks[0U], 3);
    uMultiWordShl(&prova_LOG_arduino_09_22_B.r2.chunks[0U], 3, 4U,
                  &prova_LOG_arduino_09_22_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&prova_LOG_arduino_09_22_B.r1.chunks[0U], 3,
                         &prova_LOG_arduino_09_22_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&prova_LOG_arduino_09_22_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&prova_LOG_arduino_09_22_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&prova_LOG_arduino_09_22_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&prova_LOG_arduino_09_22_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&prova_LOG_arduino_09_22_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&prova_LOG_arduino_09_22_B.a.chunks[0U], 2, 0);
  }

  return x;
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

/* Model step function */
void prova_LOG_arduino_09_22_step(void)
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  char_T ck_ric[2];
  char_T messaggio;
  uint8_T output_raw_0[3];
  uint8_T output[2];
  uint8_T output_raw[2];
  uint8_T find_comma;
  uint8_T status;
  boolean_T exitg1;
  boolean_T rtb_HiddenBuf_InsertedFor_One_t;

  /* S-Function (Mti): '<S3>/S-Function Builder' */
  Mti_Outputs_wrapper(&prova_LOG_arduino_09_22_B.SFunctionBuilder[0],
                      &prova_LOG_arduino_09_22_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S3>/Byte Unpack' */

  /* Unpack: <S3>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&prova_LOG_arduino_09_22_B.ByteUnpack_o1[0], (uint8_T*)
             &prova_LOG_arduino_09_22_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&prova_LOG_arduino_09_22_B.ByteUnpack_o2[0], (uint8_T*)
             &prova_LOG_arduino_09_22_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&prova_LOG_arduino_09_22_B.ByteUnpack_o3, (uint8_T*)
             &prova_LOG_arduino_09_22_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S3>/Byte Reversal' */

  /* ReverseEndian: <S3>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &prova_LOG_arduino_09_22_B.ByteUnpack_o2[0];
    real32_T *y0 = &prova_LOG_arduino_09_22_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* SignalConversion generated from: '<S11>/Enable' incorporates:
   *  Logic: '<S1>/Logical Operator1'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_HiddenBuf_InsertedFor_One_t = !prova_LOG_arduino_09_22_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S1>/One_time_initialization' */
  prova_L_One_time_initialization(rtb_HiddenBuf_InsertedFor_One_t,
    &prova_LOG_arduino_09_22_B.One_time_initialization,
    &prova_LOG_arduino_09_22_DW.One_time_initialization,
    &prova_LOG_arduino_09_22_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S1>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S1>/Execution_loop' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* UnitDelay: '<S1>/Unit Delay' */
  if (prova_LOG_arduino_09_22_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S8>/I2C Read12' */
    if (prova_LOG_arduino_09_22_DW.obj_g.SampleTime !=
        prova_LOG_arduino_09_22_P.t_AP) {
      prova_LOG_arduino_09_22_DW.obj_g.SampleTime =
        prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite
      (prova_LOG_arduino_09_22_DW.obj_g.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead
        (prova_LOG_arduino_09_22_DW.obj_g.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw[0], 2U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw[0], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
    }

    /* MATLABSystem: '<S8>/I2C Read1' */
    if (prova_LOG_arduino_09_22_DW.obj_c.SampleTime !=
        prova_LOG_arduino_09_22_P.t_AP) {
      prova_LOG_arduino_09_22_DW.obj_c.SampleTime =
        prova_LOG_arduino_09_22_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite
      (prova_LOG_arduino_09_22_DW.obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
       &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead
        (prova_LOG_arduino_09_22_DW.obj_c.I2CDriverObj.MW_I2C_HANDLE, 118U,
         &output_raw_0[0], 3U, false, true);
      memcpy((void *)&prova_LOG_arduino_09_22_B.output[0], (void *)
             &output_raw_0[0], (uint32_T)((size_t)3 * sizeof(uint8_T)));
    } else {
      prova_LOG_arduino_09_22_B.output[0] = 0U;
      prova_LOG_arduino_09_22_B.output[1] = 0U;
      prova_LOG_arduino_09_22_B.output[2] = 0U;
    }

    /* ArithShift: '<S8>/Shift Arithmetic4' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
      (prova_LOG_arduino_09_22_P.Constant1_Value);
    if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
        (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
      prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
    } else {
      prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
        (prova_LOG_arduino_09_22_B.rtb_Lat_re, 4.294967296E+9);
    }

    /* ArithShift: '<S8>/Shift Arithmetic3' incorporates:
     *  Constant: '<S8>/Constant5'
     */
    prova_LOG_arduino_09_22_B.rtb_Long_re = floor
      (prova_LOG_arduino_09_22_P.Constant5_Value);
    if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Long_re) || rtIsInf
        (prova_LOG_arduino_09_22_B.rtb_Long_re)) {
      prova_LOG_arduino_09_22_B.rtb_Long_re = 0.0;
    } else {
      prova_LOG_arduino_09_22_B.rtb_Long_re = fmod
        (prova_LOG_arduino_09_22_B.rtb_Long_re, 4.294967296E+9);
    }

    /* ArithShift: '<S8>/Shift Arithmetic1' incorporates:
     *  Constant: '<S8>/Constant6'
     */
    prova_LOG_arduino_09_22_B.rtb_V_re = floor
      (prova_LOG_arduino_09_22_P.Constant6_Value);
    if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_V_re) || rtIsInf
        (prova_LOG_arduino_09_22_B.rtb_V_re)) {
      prova_LOG_arduino_09_22_B.rtb_V_re = 0.0;
    } else {
      prova_LOG_arduino_09_22_B.rtb_V_re = fmod
        (prova_LOG_arduino_09_22_B.rtb_V_re, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S8>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S8>/Shift Arithmetic1'
     *  ArithShift: '<S8>/Shift Arithmetic3'
     *  ArithShift: '<S8>/Shift Arithmetic4'
     *  Constant: '<S8>/Constant10'
     *  Constant: '<S8>/Constant11'
     *  Constant: '<S8>/Constant7'
     *  MATLABSystem: '<S8>/I2C Read1'
     *  Sum: '<S8>/Sum1'
     *  Sum: '<S8>/Sum4'
     *  Sum: '<S8>/Sum5'
     *  Sum: '<S8>/Sum6'
     */
    prova_LOG_arduino_09_22_B.DataTypeConversion1 = (int32_T)
      ((((((prova_LOG_arduino_09_22_P.Constant7_Value +
            prova_LOG_arduino_09_22_B.output[0]) <<
           (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? -(int32_T)(uint32_T)
            -prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint32_T)
            prova_LOG_arduino_09_22_B.rtb_Lat_re)) +
          ((prova_LOG_arduino_09_22_P.Constant10_Value +
            prova_LOG_arduino_09_22_B.output[1]) <<
           (prova_LOG_arduino_09_22_B.rtb_Long_re < 0.0 ? -(int32_T)(uint32_T)
            -prova_LOG_arduino_09_22_B.rtb_Long_re : (int32_T)(uint32_T)
            prova_LOG_arduino_09_22_B.rtb_Long_re))) +
         prova_LOG_arduino_09_22_P.Constant11_Value) +
        prova_LOG_arduino_09_22_B.output[2]) >>
       (prova_LOG_arduino_09_22_B.rtb_V_re < 0.0 ? -(int32_T)(uint32_T)
        -prova_LOG_arduino_09_22_B.rtb_V_re : (int32_T)(uint32_T)
        prova_LOG_arduino_09_22_B.rtb_V_re));

    /* ArithShift: '<S8>/Shift Arithmetic7' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
      (prova_LOG_arduino_09_22_P.Constant2_Value);
    if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
        (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
      prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
    } else {
      prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
        (prova_LOG_arduino_09_22_B.rtb_Lat_re, 4.294967296E+9);
    }

    /* ArithShift: '<S8>/Shift Arithmetic6' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    prova_LOG_arduino_09_22_B.rtb_Long_re = floor
      (prova_LOG_arduino_09_22_P.Constant3_Value);
    if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Long_re) || rtIsInf
        (prova_LOG_arduino_09_22_B.rtb_Long_re)) {
      prova_LOG_arduino_09_22_B.rtb_Long_re = 0.0;
    } else {
      prova_LOG_arduino_09_22_B.rtb_Long_re = fmod
        (prova_LOG_arduino_09_22_B.rtb_Long_re, 4.294967296E+9);
    }

    /* ArithShift: '<S8>/Shift Arithmetic2' incorporates:
     *  Constant: '<S8>/Constant4'
     */
    prova_LOG_arduino_09_22_B.rtb_V_re = floor
      (prova_LOG_arduino_09_22_P.Constant4_Value);
    if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_V_re) || rtIsInf
        (prova_LOG_arduino_09_22_B.rtb_V_re)) {
      prova_LOG_arduino_09_22_B.rtb_V_re = 0.0;
    } else {
      prova_LOG_arduino_09_22_B.rtb_V_re = fmod
        (prova_LOG_arduino_09_22_B.rtb_V_re, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S8>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S8>/Shift Arithmetic2'
     *  ArithShift: '<S8>/Shift Arithmetic6'
     *  ArithShift: '<S8>/Shift Arithmetic7'
     *  Constant: '<S8>/Constant8'
     *  Constant: '<S8>/Constant9'
     *  MATLABSystem: '<S8>/I2C Read12'
     *  Sum: '<S8>/Sum'
     *  Sum: '<S8>/Sum2'
     *  Sum: '<S8>/Sum3'
     */
    prova_LOG_arduino_09_22_B.DataTypeConversion = (int32_T)
      ((((prova_LOG_arduino_09_22_P.Constant8_Value + output[0]) <<
         (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? -(int32_T)(uint32_T)
          -prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint32_T)
          prova_LOG_arduino_09_22_B.rtb_Lat_re)) +
        ((prova_LOG_arduino_09_22_P.Constant9_Value + output[1]) <<
         (prova_LOG_arduino_09_22_B.rtb_Long_re < 0.0 ? -(int32_T)(uint32_T)
          -prova_LOG_arduino_09_22_B.rtb_Long_re : (int32_T)(uint32_T)
          prova_LOG_arduino_09_22_B.rtb_Long_re))) >>
       (prova_LOG_arduino_09_22_B.rtb_V_re < 0.0 ? -(int32_T)(uint32_T)
        -prova_LOG_arduino_09_22_B.rtb_V_re : (int32_T)(uint32_T)
        prova_LOG_arduino_09_22_B.rtb_V_re));

    /* S-Function (calc_T): '<S8>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead1,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead2,
       &prova_LOG_arduino_09_22_B.DataTypeConversion,
       &prova_LOG_arduino_09_22_B.SFunctionBuilder_o1,
       &prova_LOG_arduino_09_22_B.SFunctionBuilder_o2);

    /* S-Function (calc_p): '<S8>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead3,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead4,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead5,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead6,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead7,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead8,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead9,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead10,
       &prova_LOG_arduino_09_22_B.One_time_initialization.I2CRead11,
       &prova_LOG_arduino_09_22_B.DataTypeConversion1,
       &prova_LOG_arduino_09_22_B.SFunctionBuilder_o2,
       &prova_LOG_arduino_09_22_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S1>/Execution_loop' */

  /* MATLABSystem: '<S2>/Serial Receive1' */
  if (prova_LOG_arduino_09_22_DW.obj_ga.Protocol !=
      prova_LOG_arduino_09_22_P.SerialReceive1_Protocol) {
    prova_LOG_arduino_09_22_DW.obj_ga.Protocol =
      prova_LOG_arduino_09_22_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, prova_LOG_arduino_09_22_DW.obj_ga.DataSizeInBytes,
                 &prova_LOG_arduino_09_22_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem2' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S16>/Create_message' */
    status = 0U;
    if (!prova_LOG_arduino_09_22_DW.start_found) {
      prova_LOG_arduino_09_22_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_LOG_arduino_09_22_B.i - 1 < 32)) {
        if (prova_LOG_arduino_09_22_B.b_dataOut[(uint8_T)
            prova_LOG_arduino_09_22_B.i - 1] == 36) {
          prova_LOG_arduino_09_22_B.loop_ub = 32 - (uint8_T)
            prova_LOG_arduino_09_22_B.i;
          for (prova_LOG_arduino_09_22_B.b_i = 0; prova_LOG_arduino_09_22_B.b_i <=
               prova_LOG_arduino_09_22_B.loop_ub; prova_LOG_arduino_09_22_B.b_i
               ++) {
            prova_LOG_arduino_09_22_DW.message[prova_LOG_arduino_09_22_B.b_i] =
              prova_LOG_arduino_09_22_B.b_dataOut[((uint8_T)
              prova_LOG_arduino_09_22_B.i + prova_LOG_arduino_09_22_B.b_i) - 1];
          }

          prova_LOG_arduino_09_22_DW.counter = (uint8_T)(33 - (uint8_T)
            prova_LOG_arduino_09_22_B.i);
          prova_LOG_arduino_09_22_DW.start_found = true;
          exitg1 = true;
        } else {
          prova_LOG_arduino_09_22_B.i++;
        }
      }
    } else {
      prova_LOG_arduino_09_22_B.b_i = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_LOG_arduino_09_22_B.b_i - 1 < 32)) {
        if (prova_LOG_arduino_09_22_B.b_dataOut[(uint8_T)
            prova_LOG_arduino_09_22_B.b_i - 1] == 13) {
          prova_LOG_arduino_09_22_DW.end_found = true;
          status = (uint8_T)prova_LOG_arduino_09_22_B.b_i;
          exitg1 = true;
        } else {
          prova_LOG_arduino_09_22_B.b_i++;
        }
      }

      if (prova_LOG_arduino_09_22_DW.end_found) {
        if (1 > status) {
          prova_LOG_arduino_09_22_B.loop_ub = -1;
        } else {
          prova_LOG_arduino_09_22_B.loop_ub = status - 1;
        }

        for (prova_LOG_arduino_09_22_B.b_i = 0; prova_LOG_arduino_09_22_B.b_i <=
             prova_LOG_arduino_09_22_B.loop_ub; prova_LOG_arduino_09_22_B.b_i++)
        {
          prova_LOG_arduino_09_22_B.i = (int32_T)(((uint32_T)
            prova_LOG_arduino_09_22_B.b_i + prova_LOG_arduino_09_22_DW.counter)
            + 1U);
          if ((uint32_T)prova_LOG_arduino_09_22_B.i > 255U) {
            prova_LOG_arduino_09_22_B.i = 255;
          }

          prova_LOG_arduino_09_22_DW.message[prova_LOG_arduino_09_22_B.i - 1] =
            prova_LOG_arduino_09_22_B.b_dataOut[prova_LOG_arduino_09_22_B.b_i];
        }

        memcpy(&prova_LOG_arduino_09_22_B.messaggio_c[0],
               &prova_LOG_arduino_09_22_DW.message[0], 80U * sizeof(uint8_T));
        prova_LOG_arduino_09_22_DW.end_found = false;
        prova_LOG_arduino_09_22_DW.counter = (uint8_T)(32 - status);
        if (status == 32) {
          prova_LOG_arduino_09_22_DW.start_found = false;
          memset(&prova_LOG_arduino_09_22_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          prova_LOG_arduino_09_22_DW.start_found = true;
          prova_LOG_arduino_09_22_B.loop_ub = -status;
          for (prova_LOG_arduino_09_22_B.b_i = 0; prova_LOG_arduino_09_22_B.b_i <=
               prova_LOG_arduino_09_22_B.loop_ub + 31;
               prova_LOG_arduino_09_22_B.b_i++) {
            prova_LOG_arduino_09_22_DW.message[prova_LOG_arduino_09_22_B.b_i] =
              prova_LOG_arduino_09_22_B.b_dataOut[status +
              prova_LOG_arduino_09_22_B.b_i];
          }

          prova_LOG_arduino_09_22_B.b_i = status + 48;
          if (0 <= prova_LOG_arduino_09_22_B.b_i - 1) {
            memset(&prova_LOG_arduino_09_22_DW.message[-status + 32], 0,
                   ((prova_LOG_arduino_09_22_B.b_i - status) + status) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S16>/Subsystem' incorporates:
         *  EnablePort: '<S18>/Enable'
         */
        /* MATLAB Function: '<S18>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        prova_LOG_arduino_09_22_B.indice_dimario = 0U;
        for (prova_LOG_arduino_09_22_B.i = 0; prova_LOG_arduino_09_22_B.i < 80;
             prova_LOG_arduino_09_22_B.i++) {
          messaggio = (int8_T)
            prova_LOG_arduino_09_22_B.messaggio_c[prova_LOG_arduino_09_22_B.i];
          if (messaggio == '$') {
            prova_LOG_arduino_09_22_B.b_i = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              prova_LOG_arduino_09_22_B.b_i = 255;
            }

            status = (uint8_T)prova_LOG_arduino_09_22_B.b_i;
          }

          if (messaggio == ',') {
            prova_LOG_arduino_09_22_B.b_i = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              prova_LOG_arduino_09_22_B.b_i = 255;
            }

            find_comma = (uint8_T)prova_LOG_arduino_09_22_B.b_i;
          }

          prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.i] =
            messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (prova_LOG_arduino_09_22_B.b_i = 0; prova_LOG_arduino_09_22_B.b_i <
               80; prova_LOG_arduino_09_22_B.b_i++) {
            prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
              =
              (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
               == '$');
          }

          prova_LOG_arduino_09_2_eml_find(prova_LOG_arduino_09_22_B.messaggio_m,
            &prova_LOG_arduino_09_22_B.eb_data,
            prova_LOG_arduino_09_22_B.eb_size);
          prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.eb_data;
          for (prova_LOG_arduino_09_22_B.b_i = 0; prova_LOG_arduino_09_22_B.b_i <
               5; prova_LOG_arduino_09_22_B.b_i++) {
            messaggio =
              prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i
              + prova_LOG_arduino_09_22_B.i];
            prova_LOG_arduino_09_22_B.mess_type_d[prova_LOG_arduino_09_22_B.b_i]
              = (messaggio == bb[prova_LOG_arduino_09_22_B.b_i]);
            prova_LOG_arduino_09_22_B.mess_type[prova_LOG_arduino_09_22_B.b_i] =
              messaggio;
          }

          if (prova_LOG_arduino_0_ifWhileCond
              (prova_LOG_arduino_09_22_B.mess_type_d)) {
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < 80;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
                =
                (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
                 == ',');
            }

            prova_LOG_arduino_09_eml_find_g
              (prova_LOG_arduino_09_22_B.messaggio_m,
               prova_LOG_arduino_09_22_B.comma_gga_data,
               prova_LOG_arduino_09_22_B.eb_size);
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < 80;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
                =
                (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
                 == '*');
            }

            prova_LOG_arduino_09_eml_find_g
              (prova_LOG_arduino_09_22_B.messaggio_m,
               prova_LOG_arduino_09_22_B.star_data,
               prova_LOG_arduino_09_22_B.star_size);
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < 80;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
                =
                (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
                 == '$');
            }

            prova_LOG_arduino_09_eml_find_g
              (prova_LOG_arduino_09_22_B.messaggio_m,
               prova_LOG_arduino_09_22_B.fb_data,
               prova_LOG_arduino_09_22_B.star_size);
            prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino_09_str2double
              (&prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.comma_gga_data
               [2]]);
            if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[2] + 3.0 >
                (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[3] - 1.0) {
              prova_LOG_arduino_09_22_B.loop_ub = 0;
              prova_LOG_arduino_09_22_B.b_i = 0;
            } else {
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.comma_gga_data[2] + 2;
              prova_LOG_arduino_09_22_B.b_i =
                prova_LOG_arduino_09_22_B.comma_gga_data[3] - 1;
            }

            prova_LOG_arduino_09_22_B.messaggio_size[0] = 1;
            prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
              prova_LOG_arduino_09_22_B.loop_ub;
            prova_LOG_arduino_09_22_B.messaggio_size[1] =
              prova_LOG_arduino_09_22_B.i;
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                =
                prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                + prova_LOG_arduino_09_22_B.b_i];
            }

            prova_LOG_arduino_09_22_B.b_x = prova_LOG_arduino__str2double_b
              (prova_LOG_arduino_09_22_B.messaggio_data,
               prova_LOG_arduino_09_22_B.messaggio_size);
            if (prova_LOG_arduino_09_22_B.b_x.im == 0.0) {
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                prova_LOG_arduino_09_22_B.b_x.re / 60.0;
            } else if (prova_LOG_arduino_09_22_B.b_x.re == 0.0) {
              prova_LOG_arduino_09_22_B.rtb_Long_re = 0.0;
            } else {
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                prova_LOG_arduino_09_22_B.b_x.re / 60.0;
            }

            prova_LOG_arduino_09_22_B.rtb_Lat_re =
              prova_LOG_arduino_09_22_B.Lat_1.re +
              prova_LOG_arduino_09_22_B.rtb_Long_re;
            prova_LOG_arduino_09_22_B.loop_ub =
              prova_LOG_arduino_09_22_B.eb_size[0] *
              prova_LOG_arduino_09_22_B.eb_size[1] - 1;
            if (0 <= prova_LOG_arduino_09_22_B.loop_ub) {
              memcpy(&prova_LOG_arduino_09_22_B.tmp_data[0],
                     &prova_LOG_arduino_09_22_B.comma_gga_data[0],
                     (prova_LOG_arduino_09_22_B.loop_ub + 1) * sizeof(int32_T));
            }

            if (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.tmp_data
                [3]] == 'S') {
              prova_LOG_arduino_09_22_B.rtb_Lat_re =
                -prova_LOG_arduino_09_22_B.rtb_Lat_re;
            }

            prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino_str2double_bq
              (&prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.comma_gga_data
               [4]]);
            if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[4] + 4.0 >
                (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[5] - 1.0) {
              prova_LOG_arduino_09_22_B.loop_ub = 0;
              prova_LOG_arduino_09_22_B.b_i = 0;
            } else {
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.comma_gga_data[4] + 3;
              prova_LOG_arduino_09_22_B.b_i =
                prova_LOG_arduino_09_22_B.comma_gga_data[5] - 1;
            }

            prova_LOG_arduino_09_22_B.messaggio_size_k[0] = 1;
            prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
              prova_LOG_arduino_09_22_B.loop_ub;
            prova_LOG_arduino_09_22_B.messaggio_size_k[1] =
              prova_LOG_arduino_09_22_B.i;
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                =
                prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                + prova_LOG_arduino_09_22_B.b_i];
            }

            prova_LOG_arduino_09_22_B.b_x = prova_LOG_arduino__str2double_b
              (prova_LOG_arduino_09_22_B.messaggio_data,
               prova_LOG_arduino_09_22_B.messaggio_size_k);
            if (prova_LOG_arduino_09_22_B.b_x.im == 0.0) {
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                prova_LOG_arduino_09_22_B.b_x.re / 60.0;
            } else if (prova_LOG_arduino_09_22_B.b_x.re == 0.0) {
              prova_LOG_arduino_09_22_B.rtb_Long_re = 0.0;
            } else {
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                prova_LOG_arduino_09_22_B.b_x.re / 60.0;
            }

            prova_LOG_arduino_09_22_B.rtb_Long_re +=
              prova_LOG_arduino_09_22_B.Lat_1.re;
            if (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.tmp_data
                [5]] == 'W') {
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                -prova_LOG_arduino_09_22_B.rtb_Long_re;
            }

            if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[6] + 1.0 >
                (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[7] - 1.0) {
              prova_LOG_arduino_09_22_B.loop_ub = 0;
              prova_LOG_arduino_09_22_B.b_i = 0;
            } else {
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.comma_gga_data[6];
              prova_LOG_arduino_09_22_B.b_i =
                prova_LOG_arduino_09_22_B.comma_gga_data[7] - 1;
            }

            prova_LOG_arduino_09_22_B.messaggio_size_c[0] = 1;
            prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
              prova_LOG_arduino_09_22_B.loop_ub;
            prova_LOG_arduino_09_22_B.messaggio_size_c[1] =
              prova_LOG_arduino_09_22_B.i;
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                =
                prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                + prova_LOG_arduino_09_22_B.b_i];
            }

            prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino__str2double_b
              (prova_LOG_arduino_09_22_B.messaggio_data,
               prova_LOG_arduino_09_22_B.messaggio_size_c);
            prova_LOG_arduino_09_22_B.rtb_V_re =
              prova_LOG_arduino_09_22_B.Lat_1.re;
            if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[7] + 1.0 >
                (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[8] - 1.0) {
              prova_LOG_arduino_09_22_B.loop_ub = 0;
              prova_LOG_arduino_09_22_B.b_i = 0;
            } else {
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.comma_gga_data[7];
              prova_LOG_arduino_09_22_B.b_i =
                prova_LOG_arduino_09_22_B.comma_gga_data[8] - 1;
            }

            prova_LOG_arduino_09_22_B.messaggio_size_b[0] = 1;
            prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
              prova_LOG_arduino_09_22_B.loop_ub;
            prova_LOG_arduino_09_22_B.messaggio_size_b[1] =
              prova_LOG_arduino_09_22_B.i;
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                =
                prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                + prova_LOG_arduino_09_22_B.b_i];
            }

            prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino__str2double_b
              (prova_LOG_arduino_09_22_B.messaggio_data,
               prova_LOG_arduino_09_22_B.messaggio_size_b);
            prova_LOG_arduino_09_22_B.rtb_heading_re =
              prova_LOG_arduino_09_22_B.Lat_1.re;
            if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[9] + 1.0 >
                (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[10] - 1.0) {
              prova_LOG_arduino_09_22_B.loop_ub = 0;
              prova_LOG_arduino_09_22_B.b_i = 0;
            } else {
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.comma_gga_data[9];
              prova_LOG_arduino_09_22_B.b_i =
                prova_LOG_arduino_09_22_B.comma_gga_data[10] - 1;
            }

            prova_LOG_arduino_09_22_B.messaggio_size_p[0] = 1;
            prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
              prova_LOG_arduino_09_22_B.loop_ub;
            prova_LOG_arduino_09_22_B.messaggio_size_p[1] =
              prova_LOG_arduino_09_22_B.i;
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                =
                prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                + prova_LOG_arduino_09_22_B.b_i];
            }

            prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino__str2double_b
              (prova_LOG_arduino_09_22_B.messaggio_data,
               prova_LOG_arduino_09_22_B.messaggio_size_p);
            prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re =
              prova_LOG_arduino_09_22_B.Lat_1.re;
            if (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.tmp_data
                [10]] == 'W') {
              prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re =
                -prova_LOG_arduino_09_22_B.Lat_1.re;
            }

            prova_LOG_arduino_09_22_B.rtb_fix_mode_re =
              prova_LOG_arduino_09_22_B.ComplextoRealImag[5];
            prova_LOG_arduino_09_22_B.rtb_n_sat_re =
              prova_LOG_arduino_09_22_B.ComplextoRealImag[6];
            prova_LOG_arduino_09_22_B.rtb_h_mean_sea_re =
              prova_LOG_arduino_09_22_B.ComplextoRealImag[7];
            prova_LOG_arduino_09_22_B.rtb_h_WGS84_re =
              prova_LOG_arduino_09_22_B.ComplextoRealImag[8];
            if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)prova_LOG_arduino_09_22_B.star_data[0]
                                   + 1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = prova_LOG_arduino_09_22_B.messaggio[status - 1];
            if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)prova_LOG_arduino_09_22_B.star_data[0]
                                   + 2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = prova_LOG_arduino_09_22_B.messaggio[status - 1];
            if ((real_T)prova_LOG_arduino_09_22_B.fb_data[0] + 1.0 > (real_T)
                prova_LOG_arduino_09_22_B.star_data[0] - 1.0) {
              prova_LOG_arduino_09_22_B.loop_ub = 0;
              prova_LOG_arduino_09_22_B.b_i = 0;
            } else {
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.fb_data[0];
              prova_LOG_arduino_09_22_B.b_i =
                prova_LOG_arduino_09_22_B.star_data[0] - 1;
            }

            prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
              prova_LOG_arduino_09_22_B.loop_ub;
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.NMEA_gga_string_data[prova_LOG_arduino_09_22_B.b_i]
                = (uint8_T)
                prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                + prova_LOG_arduino_09_22_B.b_i];
            }

            status = 0U;
            prova_LOG_arduino_09_22_B.b_i = 0;
            while (prova_LOG_arduino_09_22_B.b_i <= prova_LOG_arduino_09_22_B.i
                   - 1) {
              status ^=
                prova_LOG_arduino_09_22_B.NMEA_gga_string_data[prova_LOG_arduino_09_22_B.b_i];
              prova_LOG_arduino_09_22_B.b_i++;
            }

            if (status != prova_LOG_arduino_09_22_hex2dec(ck_ric)) {
              prova_LOG_arduino_09_22_B.rtb_Lat_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[0];
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[1];
              prova_LOG_arduino_09_22_B.rtb_V_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[2];
              prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[3];
              prova_LOG_arduino_09_22_B.rtb_heading_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[4];
              prova_LOG_arduino_09_22_B.indice_dimario = 10U;
            }
          } else {
            for (prova_LOG_arduino_09_22_B.b_i = 0;
                 prova_LOG_arduino_09_22_B.b_i < 5;
                 prova_LOG_arduino_09_22_B.b_i++) {
              prova_LOG_arduino_09_22_B.mess_type_d[prova_LOG_arduino_09_22_B.b_i]
                =
                (prova_LOG_arduino_09_22_B.mess_type[prova_LOG_arduino_09_22_B.b_i]
                 == cb[prova_LOG_arduino_09_22_B.b_i]);
            }

            if (prova_LOG_arduino_0_ifWhileCond
                (prova_LOG_arduino_09_22_B.mess_type_d)) {
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < 80;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
                  =
                  (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
                   == ',');
              }

              prova_LOG_arduino_09_eml_find_g
                (prova_LOG_arduino_09_22_B.messaggio_m,
                 prova_LOG_arduino_09_22_B.comma_gga_data,
                 prova_LOG_arduino_09_22_B.eb_size);
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < 80;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
                  =
                  (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
                   == '*');
              }

              prova_LOG_arduino_09_eml_find_g
                (prova_LOG_arduino_09_22_B.messaggio_m,
                 prova_LOG_arduino_09_22_B.star_data,
                 prova_LOG_arduino_09_22_B.star_size);
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < 80;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_m[prova_LOG_arduino_09_22_B.b_i]
                  =
                  (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.b_i]
                   == '$');
              }

              prova_LOG_arduino_09_eml_find_g
                (prova_LOG_arduino_09_22_B.messaggio_m,
                 prova_LOG_arduino_09_22_B.fb_data,
                 prova_LOG_arduino_09_22_B.star_size);
              prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino_09_str2double(
                &prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.comma_gga_data
                [1]]);
              if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[1] + 3.0 >
                  (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[2] - 1.0) {
                prova_LOG_arduino_09_22_B.loop_ub = 0;
                prova_LOG_arduino_09_22_B.b_i = 0;
              } else {
                prova_LOG_arduino_09_22_B.loop_ub =
                  prova_LOG_arduino_09_22_B.comma_gga_data[1] + 2;
                prova_LOG_arduino_09_22_B.b_i =
                  prova_LOG_arduino_09_22_B.comma_gga_data[2] - 1;
              }

              prova_LOG_arduino_09_22_B.messaggio_size[0] = 1;
              prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
                prova_LOG_arduino_09_22_B.loop_ub;
              prova_LOG_arduino_09_22_B.messaggio_size[1] =
                prova_LOG_arduino_09_22_B.i;
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                  =
                  prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                  + prova_LOG_arduino_09_22_B.b_i];
              }

              prova_LOG_arduino_09_22_B.b_x = prova_LOG_arduino__str2double_b
                (prova_LOG_arduino_09_22_B.messaggio_data,
                 prova_LOG_arduino_09_22_B.messaggio_size);
              if (prova_LOG_arduino_09_22_B.b_x.im == 0.0) {
                prova_LOG_arduino_09_22_B.rtb_Long_re =
                  prova_LOG_arduino_09_22_B.b_x.re / 60.0;
              } else if (prova_LOG_arduino_09_22_B.b_x.re == 0.0) {
                prova_LOG_arduino_09_22_B.rtb_Long_re = 0.0;
              } else {
                prova_LOG_arduino_09_22_B.rtb_Long_re =
                  prova_LOG_arduino_09_22_B.b_x.re / 60.0;
              }

              prova_LOG_arduino_09_22_B.rtb_Lat_re =
                prova_LOG_arduino_09_22_B.Lat_1.re +
                prova_LOG_arduino_09_22_B.rtb_Long_re;
              prova_LOG_arduino_09_22_B.loop_ub =
                prova_LOG_arduino_09_22_B.eb_size[0] *
                prova_LOG_arduino_09_22_B.eb_size[1] - 1;
              if (0 <= prova_LOG_arduino_09_22_B.loop_ub) {
                memcpy(&prova_LOG_arduino_09_22_B.tmp_data[0],
                       &prova_LOG_arduino_09_22_B.comma_gga_data[0],
                       (prova_LOG_arduino_09_22_B.loop_ub + 1) * sizeof(int32_T));
              }

              if (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.tmp_data
                  [2]] == 'S') {
                prova_LOG_arduino_09_22_B.rtb_Lat_re =
                  -prova_LOG_arduino_09_22_B.rtb_Lat_re;
              }

              prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino_str2double_bq(
                &prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.comma_gga_data
                [3]]);
              if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[3] + 4.0 >
                  (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[4] - 1.0) {
                prova_LOG_arduino_09_22_B.loop_ub = 0;
                prova_LOG_arduino_09_22_B.b_i = 0;
              } else {
                prova_LOG_arduino_09_22_B.loop_ub =
                  prova_LOG_arduino_09_22_B.comma_gga_data[3] + 3;
                prova_LOG_arduino_09_22_B.b_i =
                  prova_LOG_arduino_09_22_B.comma_gga_data[4] - 1;
              }

              prova_LOG_arduino_09_22_B.messaggio_size_k[0] = 1;
              prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
                prova_LOG_arduino_09_22_B.loop_ub;
              prova_LOG_arduino_09_22_B.messaggio_size_k[1] =
                prova_LOG_arduino_09_22_B.i;
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                  =
                  prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                  + prova_LOG_arduino_09_22_B.b_i];
              }

              prova_LOG_arduino_09_22_B.b_x = prova_LOG_arduino__str2double_b
                (prova_LOG_arduino_09_22_B.messaggio_data,
                 prova_LOG_arduino_09_22_B.messaggio_size_k);
              if (prova_LOG_arduino_09_22_B.b_x.im == 0.0) {
                prova_LOG_arduino_09_22_B.rtb_Long_re =
                  prova_LOG_arduino_09_22_B.b_x.re / 60.0;
              } else if (prova_LOG_arduino_09_22_B.b_x.re == 0.0) {
                prova_LOG_arduino_09_22_B.rtb_Long_re = 0.0;
              } else {
                prova_LOG_arduino_09_22_B.rtb_Long_re =
                  prova_LOG_arduino_09_22_B.b_x.re / 60.0;
              }

              prova_LOG_arduino_09_22_B.rtb_Long_re +=
                prova_LOG_arduino_09_22_B.Lat_1.re;
              if (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.tmp_data
                  [4]] == 'W') {
                prova_LOG_arduino_09_22_B.rtb_Long_re =
                  -prova_LOG_arduino_09_22_B.rtb_Long_re;
              }

              prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduin_str2double_bqm
                (prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.comma_gga_data
                 [5]]);
              prova_LOG_arduino_09_22_B.rtb_fix_mode_re =
                prova_LOG_arduino_09_22_B.Lat_1.re;
              if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[6] + 1.0 >
                  (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[7] - 1.0) {
                prova_LOG_arduino_09_22_B.loop_ub = 0;
                prova_LOG_arduino_09_22_B.b_i = 0;
              } else {
                prova_LOG_arduino_09_22_B.loop_ub =
                  prova_LOG_arduino_09_22_B.comma_gga_data[6];
                prova_LOG_arduino_09_22_B.b_i =
                  prova_LOG_arduino_09_22_B.comma_gga_data[7] - 1;
              }

              prova_LOG_arduino_09_22_B.messaggio_size_c[0] = 1;
              prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
                prova_LOG_arduino_09_22_B.loop_ub;
              prova_LOG_arduino_09_22_B.messaggio_size_c[1] =
                prova_LOG_arduino_09_22_B.i;
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                  =
                  prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                  + prova_LOG_arduino_09_22_B.b_i];
              }

              prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino__str2double_b
                (prova_LOG_arduino_09_22_B.messaggio_data,
                 prova_LOG_arduino_09_22_B.messaggio_size_c);
              prova_LOG_arduino_09_22_B.rtb_n_sat_re =
                prova_LOG_arduino_09_22_B.Lat_1.re;
              if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[8] + 1.0 >
                  (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[9] - 1.0) {
                prova_LOG_arduino_09_22_B.loop_ub = 0;
                prova_LOG_arduino_09_22_B.b_i = 0;
              } else {
                prova_LOG_arduino_09_22_B.loop_ub =
                  prova_LOG_arduino_09_22_B.comma_gga_data[8];
                prova_LOG_arduino_09_22_B.b_i =
                  prova_LOG_arduino_09_22_B.comma_gga_data[9] - 1;
              }

              prova_LOG_arduino_09_22_B.messaggio_size_b[0] = 1;
              prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
                prova_LOG_arduino_09_22_B.loop_ub;
              prova_LOG_arduino_09_22_B.messaggio_size_b[1] =
                prova_LOG_arduino_09_22_B.i;
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                  =
                  prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                  + prova_LOG_arduino_09_22_B.b_i];
              }

              prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino__str2double_b
                (prova_LOG_arduino_09_22_B.messaggio_data,
                 prova_LOG_arduino_09_22_B.messaggio_size_b);
              prova_LOG_arduino_09_22_B.rtb_h_mean_sea_re =
                prova_LOG_arduino_09_22_B.Lat_1.re;
              if ((real_T)prova_LOG_arduino_09_22_B.comma_gga_data[10] + 1.0 >
                  (real_T)prova_LOG_arduino_09_22_B.comma_gga_data[11] - 1.0) {
                prova_LOG_arduino_09_22_B.loop_ub = 0;
                prova_LOG_arduino_09_22_B.b_i = 0;
              } else {
                prova_LOG_arduino_09_22_B.loop_ub =
                  prova_LOG_arduino_09_22_B.comma_gga_data[10];
                prova_LOG_arduino_09_22_B.b_i =
                  prova_LOG_arduino_09_22_B.comma_gga_data[11] - 1;
              }

              prova_LOG_arduino_09_22_B.messaggio_size_p[0] = 1;
              prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
                prova_LOG_arduino_09_22_B.loop_ub;
              prova_LOG_arduino_09_22_B.messaggio_size_p[1] =
                prova_LOG_arduino_09_22_B.i;
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.messaggio_data[prova_LOG_arduino_09_22_B.b_i]
                  =
                  prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                  + prova_LOG_arduino_09_22_B.b_i];
              }

              prova_LOG_arduino_09_22_B.Lat_1 = prova_LOG_arduino__str2double_b
                (prova_LOG_arduino_09_22_B.messaggio_data,
                 prova_LOG_arduino_09_22_B.messaggio_size_p);
              prova_LOG_arduino_09_22_B.rtb_h_WGS84_re =
                prova_LOG_arduino_09_22_B.Lat_1.re;
              prova_LOG_arduino_09_22_B.rtb_V_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[2];
              prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[3];
              prova_LOG_arduino_09_22_B.rtb_heading_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[4];
              if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 1.0 < 256.0)
              {
                if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 1.0 >= 0.0)
                {
                  status = (uint8_T)((real_T)
                                     prova_LOG_arduino_09_22_B.star_data[0] +
                                     1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = prova_LOG_arduino_09_22_B.messaggio[status - 1];
              if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 2.0 < 256.0)
              {
                if ((real_T)prova_LOG_arduino_09_22_B.star_data[0] + 2.0 >= 0.0)
                {
                  status = (uint8_T)((real_T)
                                     prova_LOG_arduino_09_22_B.star_data[0] +
                                     2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = prova_LOG_arduino_09_22_B.messaggio[status - 1];
              if ((real_T)prova_LOG_arduino_09_22_B.fb_data[0] + 1.0 > (real_T)
                  prova_LOG_arduino_09_22_B.star_data[0] - 1.0) {
                prova_LOG_arduino_09_22_B.loop_ub = 0;
                prova_LOG_arduino_09_22_B.b_i = 0;
              } else {
                prova_LOG_arduino_09_22_B.loop_ub =
                  prova_LOG_arduino_09_22_B.fb_data[0];
                prova_LOG_arduino_09_22_B.b_i =
                  prova_LOG_arduino_09_22_B.star_data[0] - 1;
              }

              prova_LOG_arduino_09_22_B.i = prova_LOG_arduino_09_22_B.b_i -
                prova_LOG_arduino_09_22_B.loop_ub;
              for (prova_LOG_arduino_09_22_B.b_i = 0;
                   prova_LOG_arduino_09_22_B.b_i < prova_LOG_arduino_09_22_B.i;
                   prova_LOG_arduino_09_22_B.b_i++) {
                prova_LOG_arduino_09_22_B.NMEA_gga_string_data[prova_LOG_arduino_09_22_B.b_i]
                  = (uint8_T)
                  prova_LOG_arduino_09_22_B.messaggio[prova_LOG_arduino_09_22_B.loop_ub
                  + prova_LOG_arduino_09_22_B.b_i];
              }

              status = 0U;
              prova_LOG_arduino_09_22_B.b_i = 0;
              while (prova_LOG_arduino_09_22_B.b_i <=
                     prova_LOG_arduino_09_22_B.i - 1) {
                status ^=
                  prova_LOG_arduino_09_22_B.NMEA_gga_string_data[prova_LOG_arduino_09_22_B.b_i];
                prova_LOG_arduino_09_22_B.b_i++;
              }

              if (status != prova_LOG_arduino_09_22_hex2dec(ck_ric)) {
                prova_LOG_arduino_09_22_B.rtb_Lat_re =
                  prova_LOG_arduino_09_22_B.ComplextoRealImag[0];
                prova_LOG_arduino_09_22_B.rtb_Long_re =
                  prova_LOG_arduino_09_22_B.ComplextoRealImag[1];
                prova_LOG_arduino_09_22_B.rtb_fix_mode_re =
                  prova_LOG_arduino_09_22_B.ComplextoRealImag[5];
                prova_LOG_arduino_09_22_B.rtb_n_sat_re =
                  prova_LOG_arduino_09_22_B.ComplextoRealImag[6];
                prova_LOG_arduino_09_22_B.rtb_h_mean_sea_re =
                  prova_LOG_arduino_09_22_B.ComplextoRealImag[7];
                prova_LOG_arduino_09_22_B.rtb_h_WGS84_re =
                  prova_LOG_arduino_09_22_B.ComplextoRealImag[8];
                prova_LOG_arduino_09_22_B.indice_dimario = 20U;
              }
            } else {
              prova_LOG_arduino_09_22_B.rtb_Lat_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[0];
              prova_LOG_arduino_09_22_B.rtb_Long_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[1];
              prova_LOG_arduino_09_22_B.rtb_V_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[2];
              prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[3];
              prova_LOG_arduino_09_22_B.rtb_heading_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[4];
              prova_LOG_arduino_09_22_B.rtb_fix_mode_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[5];
              prova_LOG_arduino_09_22_B.rtb_n_sat_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[6];
              prova_LOG_arduino_09_22_B.rtb_h_mean_sea_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[7];
              prova_LOG_arduino_09_22_B.rtb_h_WGS84_re =
                prova_LOG_arduino_09_22_B.ComplextoRealImag[8];
            }
          }
        } else {
          prova_LOG_arduino_09_22_B.rtb_Lat_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[0];
          prova_LOG_arduino_09_22_B.rtb_Long_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[1];
          prova_LOG_arduino_09_22_B.rtb_V_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[2];
          prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[3];
          prova_LOG_arduino_09_22_B.rtb_heading_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[4];
          prova_LOG_arduino_09_22_B.rtb_fix_mode_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[5];
          prova_LOG_arduino_09_22_B.rtb_n_sat_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[6];
          prova_LOG_arduino_09_22_B.rtb_h_mean_sea_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[7];
          prova_LOG_arduino_09_22_B.rtb_h_WGS84_re =
            prova_LOG_arduino_09_22_B.ComplextoRealImag[8];
        }

        /* End of MATLAB Function: '<S18>/MATLAB Function' */

        /* ComplexToRealImag: '<S18>/Complex to Real-Imag' */
        prova_LOG_arduino_09_22_B.ComplextoRealImag[0] =
          prova_LOG_arduino_09_22_B.rtb_Lat_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[1] =
          prova_LOG_arduino_09_22_B.rtb_Long_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[2] =
          prova_LOG_arduino_09_22_B.rtb_V_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[3] =
          prova_LOG_arduino_09_22_B.rtb_Magnetic_declination_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[4] =
          prova_LOG_arduino_09_22_B.rtb_heading_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[5] =
          prova_LOG_arduino_09_22_B.rtb_fix_mode_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[6] =
          prova_LOG_arduino_09_22_B.rtb_n_sat_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[7] =
          prova_LOG_arduino_09_22_B.rtb_h_mean_sea_re;
        prova_LOG_arduino_09_22_B.ComplextoRealImag[8] =
          prova_LOG_arduino_09_22_B.rtb_h_WGS84_re;

        /* End of Outputs for SubSystem: '<S16>/Subsystem' */
      } else {
        for (prova_LOG_arduino_09_22_B.i = 0; prova_LOG_arduino_09_22_B.i < 32;
             prova_LOG_arduino_09_22_B.i++) {
          prova_LOG_arduino_09_22_B.b_i = (int32_T)(((uint32_T)
            prova_LOG_arduino_09_22_DW.counter + prova_LOG_arduino_09_22_B.i) +
            1U);
          if ((uint32_T)prova_LOG_arduino_09_22_B.b_i > 255U) {
            prova_LOG_arduino_09_22_B.b_i = 255;
          }

          prova_LOG_arduino_09_22_DW.message[prova_LOG_arduino_09_22_B.b_i - 1] =
            prova_LOG_arduino_09_22_B.b_dataOut[prova_LOG_arduino_09_22_B.i];
        }

        prova_LOG_arduino_09_22_B.b_i = (int32_T)
          (prova_LOG_arduino_09_22_DW.counter + 32U);
        if (prova_LOG_arduino_09_22_DW.counter + 32U > 255U) {
          prova_LOG_arduino_09_22_B.b_i = 255;
        }

        prova_LOG_arduino_09_22_DW.counter = (uint8_T)
          prova_LOG_arduino_09_22_B.b_i;
      }
    }

    /* End of MATLAB Function: '<S16>/Create_message' */
  }

  /* End of MATLABSystem: '<S2>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* Constant: '<Root>/Constant3' */
  if (prova_LOG_arduino_09_22_P.Constant3_Value_i > 0.0) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S15>/Constant3'
     *  Logic: '<S15>/OR'
     *  RelationalOperator: '<S15>/Equal'
     *  RelationalOperator: '<S15>/Equal1'
     *  RelationalOperator: '<S15>/Equal2'
     */
    if ((prova_LOG_arduino_09_22_B.ComplextoRealImag[5] ==
         prova_LOG_arduino_09_22_P.Constant_Value) ||
        (prova_LOG_arduino_09_22_B.ComplextoRealImag[5] ==
         prova_LOG_arduino_09_22_P.Constant1_Value_k) ||
        (prova_LOG_arduino_09_22_B.ComplextoRealImag[5] ==
         prova_LOG_arduino_09_22_P.Constant3_Value_l)) {
      /* Switch: '<S15>/Switch' */
      prova_LOG_arduino_09_22_B.Switch =
        prova_LOG_arduino_09_22_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S15>/Switch' incorporates:
       *  Constant: '<S15>/Constant2'
       */
      prova_LOG_arduino_09_22_B.Switch =
        prova_LOG_arduino_09_22_P.Constant2_Value_n;
    }

    /* End of Switch: '<S15>/Switch' */
  }

  /* End of Constant: '<Root>/Constant3' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S12>/Subsystem1' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  /* Constant: '<Root>/Constant2' */
  if (prova_LOG_arduino_09_22_P.Constant2_Value_d > 0.0) {
    /* Inport: '<S14>/T' */
    prova_LOG_arduino_09_22_B.T = prova_LOG_arduino_09_22_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S12>/Subsystem1' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if (prova_LOG_arduino_09_22_P.Constant2_Value_d == 1.0) {
    prova_LOG_arduino_09_22_DW.P_ref =
      prova_LOG_arduino_09_22_B.SFunctionBuilder1;
  }

  if (prova_LOG_arduino_09_22_P.Constant_Value_d == 1.0) {
    prova_LOG_arduino_09_22_DW.P_ref =
      prova_LOG_arduino_09_22_P.Constant1_Value_c;
    prova_LOG_arduino_09_22_DW.rl_up = 20.0;
    prova_LOG_arduino_09_22_DW.rl_dw = -20.0;
  }

  /* Product: '<S7>/delta rise limit' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  SampleTimeMath: '<S7>/sample time'
   *
   * About '<S7>/sample time':
   *  y = K where K = ( w * Ts )
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = prova_LOG_arduino_09_22_DW.rl_up *
    prova_LOG_arduino_09_22_P.sampletime_WtEt;

  /* Sum: '<S7>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  UnitDelay: '<S7>/Delay Input2'
   *
   * Block description for '<S7>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/Delay Input2':
   *
   *  Store in Global RAM
   */
  prova_LOG_arduino_09_22_B.rtb_Long_re = prova_LOG_arduino_09_22_DW.P_ref -
    prova_LOG_arduino_09_22_DW.DelayInput2_DSTATE;

  /* Product: '<S7>/delta fall limit' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  SampleTimeMath: '<S7>/sample time'
   *
   * About '<S7>/sample time':
   *  y = K where K = ( w * Ts )
   */
  prova_LOG_arduino_09_22_B.rtb_V_re = prova_LOG_arduino_09_22_DW.rl_dw *
    prova_LOG_arduino_09_22_P.sampletime_WtEt;

  /* Switch: '<S13>/Switch2' incorporates:
   *  RelationalOperator: '<S13>/LowerRelop1'
   *  RelationalOperator: '<S13>/UpperRelop'
   *  Switch: '<S13>/Switch'
   */
  if (prova_LOG_arduino_09_22_B.rtb_Long_re >
      prova_LOG_arduino_09_22_B.rtb_Lat_re) {
    prova_LOG_arduino_09_22_B.rtb_Long_re = prova_LOG_arduino_09_22_B.rtb_Lat_re;
  } else {
    if (prova_LOG_arduino_09_22_B.rtb_Long_re <
        prova_LOG_arduino_09_22_B.rtb_V_re) {
      /* Switch: '<S13>/Switch' */
      prova_LOG_arduino_09_22_B.rtb_Long_re = prova_LOG_arduino_09_22_B.rtb_V_re;
    }
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Sum: '<S7>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S7>/Delay Input2'
   *
   * Block description for '<S7>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/Delay Input2':
   *
   *  Store in Global RAM
   */
  prova_LOG_arduino_09_22_DW.DelayInput2_DSTATE +=
    prova_LOG_arduino_09_22_B.rtb_Long_re;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  UnitDelay: '<S7>/Delay Input2'
   *
   * Block description for '<S7>/Delay Input2':
   *
   *  Store in Global RAM
   */
  prova_LOG_arduino_09_22_B.rtb_Long_re = log
    (prova_LOG_arduino_09_22_DW.DelayInput2_DSTATE / (real_T)
     prova_LOG_arduino_09_22_B.SFunctionBuilder1);

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Sum: '<S2>/Sum'
   */
  prova_LOG_arduino_09_22_B.DataTypeConversion4[0] = (real32_T)
    prova_LOG_arduino_09_22_B.ComplextoRealImag[0];
  prova_LOG_arduino_09_22_B.DataTypeConversion4[1] = (real32_T)
    prova_LOG_arduino_09_22_B.ComplextoRealImag[1];
  prova_LOG_arduino_09_22_B.DataTypeConversion4[2] = (real32_T)
    (prova_LOG_arduino_09_22_B.ComplextoRealImag[7] -
     prova_LOG_arduino_09_22_B.Switch);

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<Root>/T_0'
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/NotEqual'
   *  Switch: '<S12>/Switch'
   */
  if (prova_LOG_arduino_09_22_P.Constant_Value_a !=
      prova_LOG_arduino_09_22_P.T_0_Value) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = prova_LOG_arduino_09_22_P.T_0_Value;
  } else if (prova_LOG_arduino_09_22_B.T >
             prova_LOG_arduino_09_22_P.Switch_Threshold) {
    /* Switch: '<S12>/Switch' */
    prova_LOG_arduino_09_22_B.rtb_Lat_re = prova_LOG_arduino_09_22_B.T;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = prova_LOG_arduino_09_22_P.T_0_Value;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_arduino_09_22_B.DataTypeConversion4[3] = (real32_T)
    (29.260958205912335 * prova_LOG_arduino_09_22_B.rtb_Long_re *
     (prova_LOG_arduino_09_22_B.rtb_Lat_re + 273.15) / (1.0 -
      -0.095098114169215084 * prova_LOG_arduino_09_22_B.rtb_Long_re));

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_k *
     prova_LOG_arduino_09_22_B.ByteReversal[0]);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[0] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_k *
     prova_LOG_arduino_09_22_B.ByteReversal[1]);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[1] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_k *
     prova_LOG_arduino_09_22_B.ByteReversal[2]);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[2] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<S4>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain *
     prova_LOG_arduino_09_22_B.ByteReversal[3] *
     prova_LOG_arduino_09_22_P.Gain_Gain_k);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[3] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<S5>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_o *
     prova_LOG_arduino_09_22_B.ByteReversal[4] *
     prova_LOG_arduino_09_22_P.Gain_Gain_k);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[4] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<S6>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_c *
     prova_LOG_arduino_09_22_B.ByteReversal[5] *
     prova_LOG_arduino_09_22_P.Gain_Gain_k);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[5] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_k *
     prova_LOG_arduino_09_22_B.ByteReversal[6]);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[6] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_k *
     prova_LOG_arduino_09_22_B.ByteReversal[7]);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[7] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  prova_LOG_arduino_09_22_B.f = (real32_T)floor
    (prova_LOG_arduino_09_22_P.Gain_Gain_k *
     prova_LOG_arduino_09_22_B.ByteReversal[8]);
  if (rtIsNaNF(prova_LOG_arduino_09_22_B.f) || rtIsInfF
      (prova_LOG_arduino_09_22_B.f)) {
    prova_LOG_arduino_09_22_B.f = 0.0F;
  } else {
    prova_LOG_arduino_09_22_B.f = (real32_T)fmod(prova_LOG_arduino_09_22_B.f,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  prova_LOG_arduino_09_22_B.DataTypeConversion1_o[8] = (int16_T)
    (prova_LOG_arduino_09_22_B.f < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -prova_LOG_arduino_09_22_B.f : (int32_T)(int16_T)(uint16_T)
     prova_LOG_arduino_09_22_B.f);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_B.ComplextoRealImag[4]);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[0] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.Gain2_Gain *
     prova_LOG_arduino_09_22_B.ComplextoRealImag[2]);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[1] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/PWM_autopilota'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.PWM_autopilota_Value[0]);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[2] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/PWM_autopilota'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.PWM_autopilota_Value[1]);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[3] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/manetta'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.manetta_Value);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[4] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Equilibratore'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.Equilibratore_Value);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[5] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Alettoni'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.Alettoni_Value);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[6] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Timone'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.Timone_Value);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[7] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/PWM_autopilota'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_P.PWM_autopilota_Value[2]);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[8] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor((real_T)
    prova_LOG_arduino_09_22_P.Gain3_Gain *
    prova_LOG_arduino_09_22_B.SFunctionBuilder_o1);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  prova_LOG_arduino_09_22_B.DataTypeConversion2[9] = (uint16_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint16_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  prova_LOG_arduino_09_22_B.rtb_Lat_re = floor
    (prova_LOG_arduino_09_22_B.ComplextoRealImag[5]);
  if (rtIsNaN(prova_LOG_arduino_09_22_B.rtb_Lat_re) || rtIsInf
      (prova_LOG_arduino_09_22_B.rtb_Lat_re)) {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = 0.0;
  } else {
    prova_LOG_arduino_09_22_B.rtb_Lat_re = fmod
      (prova_LOG_arduino_09_22_B.rtb_Lat_re, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  prova_LOG_arduino_09_22_B.DataTypeConversion7[0] = (uint8_T)
    (prova_LOG_arduino_09_22_B.rtb_Lat_re < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-prova_LOG_arduino_09_22_B.rtb_Lat_re : (int32_T)(uint8_T)
     prova_LOG_arduino_09_22_B.rtb_Lat_re);
  prova_LOG_arduino_09_22_B.DataTypeConversion7[1] =
    prova_LOG_arduino_09_22_B.indice_dimario;

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  prova_LOG_arduino_09_22_B.DataTypeConversion8 =
    prova_LOG_arduino_09_22_B.SFunctionBuilder1;

  /* S-Function (any2byte_svd): '<Root>/Byte Pack' incorporates:
   *  Constant: '<Root>/Fine MSG1'
   *  Constant: '<Root>/Inizio MSG'
   */

  /* Pack: <Root>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_B.DataTypeConversion4[0],
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_B.DataTypeConversion1_o[0],
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_B.DataTypeConversion2[0],
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_B.DataTypeConversion7[0],
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_B.DataTypeConversion8, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_arduino_09_22_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_arduino_09_22_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<Root>/Serial Transmit' */
  if (prova_LOG_arduino_09_22_DW.obj.Protocol !=
      prova_LOG_arduino_09_22_P.SerialTransmit_Protocol) {
    prova_LOG_arduino_09_22_DW.obj.Protocol =
      prova_LOG_arduino_09_22_P.SerialTransmit_Protocol;
  }

  for (prova_LOG_arduino_09_22_B.i = 0; prova_LOG_arduino_09_22_B.i < 63;
       prova_LOG_arduino_09_22_B.i++) {
    prova_LOG_arduino_09_22_B.dataIn[prova_LOG_arduino_09_22_B.i] =
      prova_LOG_arduino_09_22_B.BytePack[prova_LOG_arduino_09_22_B.i];
  }

  MW_Serial_write(prova_LOG_arduino_09_22_DW.obj.port,
                  &prova_LOG_arduino_09_22_B.dataIn[0], 63.0,
                  prova_LOG_arduino_09_22_DW.obj.dataSizeInBytes,
                  prova_LOG_arduino_09_22_DW.obj.sendModeEnum,
                  prova_LOG_arduino_09_22_DW.obj.dataType,
                  prova_LOG_arduino_09_22_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */

  /* Update for S-Function (Mti): '<S3>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S3>/S-Function Builder */
  Mti_Update_wrapper(&prova_LOG_arduino_09_22_B.SFunctionBuilder[0],
                     &prova_LOG_arduino_09_22_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  prova_LOG_arduino_09_22_DW.UnitDelay_DSTATE =
    prova_LOG_arduino_09_22_P.Constant3_Value_o;
}

/* Model initialize function */
void prova_LOG_arduino_09_22_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_inter_T *obj;
    real_T tmp;
    int32_T i;
    uint32_T varargin_1;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S3>/S-Function Builder' */

    /* S-Function Block: <S3>/S-Function Builder */
    Mti_Start_wrapper(&prova_LOG_arduino_09_22_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for S-Function (Mti): '<S3>/S-Function Builder' */

    /* S-Function Block: <S3>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          prova_LOG_arduino_09_22_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
    prova_LOG_arduino_09_22_DW.UnitDelay_DSTATE =
      prova_LOG_arduino_09_22_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Delay Input2'
     *
     * Block description for '<S7>/Delay Input2':
     *
     *  Store in Global RAM
     */
    prova_LOG_arduino_09_22_DW.DelayInput2_DSTATE =
      prova_LOG_arduino_09_22_P.DelayInput2_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S1>/One_time_initialization' */
    pr_One_time_initialization_Init
      (&prova_LOG_arduino_09_22_B.One_time_initialization,
       &prova_LOG_arduino_09_22_DW.One_time_initialization,
       &prova_LOG_arduino_09_22_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S1>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/Execution_loop' */
    /* Start for MATLABSystem: '<S8>/I2C Read12' */
    prova_LOG_arduino_09_22_DW.obj_g.matlabCodegenIsDeleted = true;
    obj = &prova_LOG_arduino_09_22_DW.obj_g;
    prova_LOG_arduino_09_22_DW.obj_g.DefaultMaximumBusSpeedInHz = 400000.0;
    prova_LOG_arduino_09_22_DW.obj_g.isInitialized = 0;
    prova_LOG_arduino_09_22_DW.obj_g.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    prova_LOG_arduino_09_22_DW.obj_g.matlabCodegenIsDeleted = false;
    prova_LOG_arduino_09_22_DW.obj_g.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    obj = &prova_LOG_arduino_09_22_DW.obj_g;
    prova_LOG_arduino_09_22_DW.obj_g.isSetupComplete = false;
    prova_LOG_arduino_09_22_DW.obj_g.isInitialized = 1;
    prova_LOG_arduino_09_22_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (prova_LOG_arduino_09_22_B.i2cname, 0);
    prova_LOG_arduino_09_22_DW.obj_g.BusSpeed = 100000U;
    varargin_1 = prova_LOG_arduino_09_22_DW.obj_g.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    prova_LOG_arduino_09_22_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/I2C Read1' */
    prova_LOG_arduino_09_22_DW.obj_c.matlabCodegenIsDeleted = true;
    obj = &prova_LOG_arduino_09_22_DW.obj_c;
    prova_LOG_arduino_09_22_DW.obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
    prova_LOG_arduino_09_22_DW.obj_c.isInitialized = 0;
    prova_LOG_arduino_09_22_DW.obj_c.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    prova_LOG_arduino_09_22_DW.obj_c.matlabCodegenIsDeleted = false;
    prova_LOG_arduino_09_22_DW.obj_c.SampleTime = prova_LOG_arduino_09_22_P.t_AP;
    obj = &prova_LOG_arduino_09_22_DW.obj_c;
    prova_LOG_arduino_09_22_DW.obj_c.isSetupComplete = false;
    prova_LOG_arduino_09_22_DW.obj_c.isInitialized = 1;
    prova_LOG_arduino_09_22_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (prova_LOG_arduino_09_22_B.i2cname, 0);
    prova_LOG_arduino_09_22_DW.obj_c.BusSpeed = 100000U;
    varargin_1 = prova_LOG_arduino_09_22_DW.obj_c.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    prova_LOG_arduino_09_22_DW.obj_c.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S8>/S-Function Builder' incorporates:
     *  Outport: '<S8>/T'
     */
    prova_LOG_arduino_09_22_B.SFunctionBuilder_o1 =
      prova_LOG_arduino_09_22_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S8>/S-Function Builder1' incorporates:
     *  Outport: '<S8>/p'
     */
    prova_LOG_arduino_09_22_B.SFunctionBuilder1 = prova_LOG_arduino_09_22_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Execution_loop' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S16>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S18>/Memory' */
      prova_LOG_arduino_09_22_B.ComplextoRealImag[i] =
        prova_LOG_arduino_09_22_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S18>/Complex to Real-Imag' incorporates:
       *  Outport: '<S18>/Outport'
       */
      prova_LOG_arduino_09_22_B.ComplextoRealImag[i] =
        prova_LOG_arduino_09_22_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S18>/mario' */
    prova_LOG_arduino_09_22_B.indice_dimario =
      prova_LOG_arduino_09_22_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S16>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem1' */
    /* SystemInitialize for Switch: '<S15>/Switch' incorporates:
     *  Outport: '<S15>/h_to_subtract'
     */
    prova_LOG_arduino_09_22_B.Switch =
      prova_LOG_arduino_09_22_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S12>/Subsystem1' */
    /* SystemInitialize for Outport: '<S14>/T_0' incorporates:
     *  Inport: '<S14>/T'
     */
    prova_LOG_arduino_09_22_B.T = prova_LOG_arduino_09_22_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S12>/Subsystem1' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
    prova_LOG_arduino_09_22_DW.P_ref = 101325.0;
    prova_LOG_arduino_09_22_DW.rl_up = 300.0;
    prova_LOG_arduino_09_22_DW.rl_dw = -300.0;

    /* Start for MATLABSystem: '<S2>/Serial Receive1' */
    prova_LOG_arduino_09_22_DW.obj_ga.matlabCodegenIsDeleted = false;
    prova_LOG_arduino_09_22_DW.obj_ga.Protocol =
      prova_LOG_arduino_09_22_P.SerialReceive1_Protocol;
    prova_LOG_arduino_09_22_DW.obj_ga.isInitialized = 1;
    prova_LOG_arduino_09_22_DW.obj_ga.DataTypeWidth = 1U;
    if (prova_LOG_arduino_09_22_DW.obj_ga.DataTypeWidth > 2047) {
      prova_LOG_arduino_09_22_DW.obj_ga.DataSizeInBytes = MAX_uint16_T;
    } else {
      prova_LOG_arduino_09_22_DW.obj_ga.DataSizeInBytes = (uint16_T)
        (prova_LOG_arduino_09_22_DW.obj_ga.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    prova_LOG_arduino_09_22_DW.obj_ga.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Receive1' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    prova_LOG_arduino_09_22_DW.obj.matlabCodegenIsDeleted = false;
    prova_LOG_arduino_09_22_DW.obj.Protocol =
      prova_LOG_arduino_09_22_P.SerialTransmit_Protocol;
    prova_LOG_arduino_09_22_DW.obj.isInitialized = 1;
    prova_LOG_arduino_09_22_DW.obj.port = 0.0;
    prova_LOG_arduino_09_22_DW.obj.dataSizeInBytes = 1.0;
    prova_LOG_arduino_09_22_DW.obj.dataType = 0.0;
    prova_LOG_arduino_09_22_DW.obj.sendModeEnum = 0.0;
    prova_LOG_arduino_09_22_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(prova_LOG_arduino_09_22_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    prova_LOG_arduino_09_22_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void prova_LOG_arduino_09_22_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S1>/One_time_initialization' */
  pr_One_time_initialization_Term
    (&prova_LOG_arduino_09_22_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S1>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S1>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S8>/I2C Read12' */
  obj = &prova_LOG_arduino_09_22_DW.obj_g;
  if (!prova_LOG_arduino_09_22_DW.obj_g.matlabCodegenIsDeleted) {
    prova_LOG_arduino_09_22_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((prova_LOG_arduino_09_22_DW.obj_g.isInitialized == 1) &&
        prova_LOG_arduino_09_22_DW.obj_g.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S8>/I2C Read1' */
  obj = &prova_LOG_arduino_09_22_DW.obj_c;
  if (!prova_LOG_arduino_09_22_DW.obj_c.matlabCodegenIsDeleted) {
    prova_LOG_arduino_09_22_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((prova_LOG_arduino_09_22_DW.obj_c.isInitialized == 1) &&
        prova_LOG_arduino_09_22_DW.obj_c.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S1>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S2>/Serial Receive1' */
  if (!prova_LOG_arduino_09_22_DW.obj_ga.matlabCodegenIsDeleted) {
    prova_LOG_arduino_09_22_DW.obj_ga.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!prova_LOG_arduino_09_22_DW.obj.matlabCodegenIsDeleted) {
    prova_LOG_arduino_09_22_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
