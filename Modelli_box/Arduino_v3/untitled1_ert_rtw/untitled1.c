/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:27:47 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_private.h"

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Forward declaration for local functions */
static void untitled1_eml_find(const boolean_T x[80], int32_T i_data[], int32_T
  i_size[2]);
static boolean_T untitled1_ifWhileCond(const boolean_T x[5]);
static void untitled1_eml_find_n(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void untitled1_readNonFinite(const char_T s[2], int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T untitled1_copydigits(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowpoint);
static boolean_T untitled1_copyexponent(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k);
static void untitled1_readfloat(char_T s1[4], int32_T *idx, const char_T s[2],
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T untitled1_str2double(const char_T s[2]);
static boolean_T untitled1_copydigits_o(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void untitled1_readfloat_o(char_T s1_data[], int32_T *idx, const char_T
  s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T untitled1_str2double_i(const char_T s_data[], const int32_T
  s_size[2]);
static boolean_T untitled1_isUnitImag(const char_T s[3], int32_T k);
static void untitled1_readNonFinite_e(const char_T s[3], int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T untitled1_copydigits_of(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T untitled1_copyexponent_a(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k);
static void untitled1_readfloat_oc(char_T s1[5], int32_T *idx, const char_T s[3],
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T untitled1_str2double_ic(const char_T s[3]);
static void untitled1_readNonFinite_eq(char_T s, int32_T *k, boolean_T *b_finite,
  real_T *fv);
static boolean_T untitled1_copydigits_ofu(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowpoint);
static boolean_T untitled1_copyexponent_ao(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k);
static void untitled1_readfloat_ocp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T untitled1_str2double_ics(char_T s);
static real_T untitled1_hex2dec(const char_T s[2]);
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

/* System initialize for enable system: '<S20>/One_time_initialization' */
void un_One_time_initialization_Init(B_One_time_initialization_unt_T *localB,
  DW_One_time_initialization_un_T *localDW, P_One_time_initialization_unt_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S27>/I2C Read' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read1' */
  localDW->obj_ni.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ni;
  localDW->obj_ni.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ni.isInitialized = 0;
  localDW->obj_ni.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ni.matlabCodegenIsDeleted = false;
  localDW->obj_ni.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_ni;
  localDW->obj_ni.isSetupComplete = false;
  localDW->obj_ni.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ni.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ni.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ni.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read2' */
  localDW->obj_nf.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_nf;
  localDW->obj_nf.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_nf.isInitialized = 0;
  localDW->obj_nf.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_nf.matlabCodegenIsDeleted = false;
  localDW->obj_nf.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_nf;
  localDW->obj_nf.isSetupComplete = false;
  localDW->obj_nf.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_nf.BusSpeed = 100000U;
  varargin_1 = localDW->obj_nf.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_nf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read3' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  localDW->obj_e.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  localDW->obj_e.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read4' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read5' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read6' */
  localDW->obj_ds.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ds;
  localDW->obj_ds.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ds.isInitialized = 0;
  localDW->obj_ds.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ds.matlabCodegenIsDeleted = false;
  localDW->obj_ds.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_ds;
  localDW->obj_ds.isSetupComplete = false;
  localDW->obj_ds.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ds.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ds.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ds.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read7' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read8' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read10' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read11' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = untitled1_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Write1' */
  localDW->obj_nb.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_nb;
  localDW->obj_nb.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_nb.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_nb.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_nb;
  localDW->obj_nb.isSetupComplete = false;
  localDW->obj_nb.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_nb.BusSpeed = 100000U;
  varargin_1 = localDW->obj_nb.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_nb.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Write2' */
  localDW->obj_p.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_p;
  localDW->obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_p.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_p.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_p;
  localDW->obj_p.isSetupComplete = false;
  localDW->obj_p.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_p.BusSpeed = 100000U;
  varargin_1 = localDW->obj_p.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Write3' */
  localDW->obj_eu.matlabCodegenIsDeleted = true;
  obj_0 = &localDW->obj_eu;
  localDW->obj_eu.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_eu.isInitialized = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_eu.matlabCodegenIsDeleted = false;
  obj_0 = &localDW->obj_eu;
  localDW->obj_eu.isSetupComplete = false;
  localDW->obj_eu.isInitialized = 1;
  i2cname = 0;
  obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_eu.BusSpeed = 100000U;
  varargin_1 = localDW->obj_eu.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_eu.isSetupComplete = true;

  /* Start for MATLABSystem: '<S27>/I2C Read12' */
  localDW->obj_l.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_l;
  localDW->obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_l.isInitialized = 0;
  localDW->obj_l.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_l.matlabCodegenIsDeleted = false;
  localDW->obj_l.SampleTime = localP->I2CRead12_SampleTime;
  obj = &localDW->obj_l;
  localDW->obj_l.isSetupComplete = false;
  localDW->obj_l.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_l.BusSpeed = 100000U;
  varargin_1 = localDW->obj_l.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_l.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read' incorporates:
   *  Outport: '<S27>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read1' incorporates:
   *  Outport: '<S27>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read2' incorporates:
   *  Outport: '<S27>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read3' incorporates:
   *  Outport: '<S27>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read4' incorporates:
   *  Outport: '<S27>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read5' incorporates:
   *  Outport: '<S27>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read6' incorporates:
   *  Outport: '<S27>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read7' incorporates:
   *  Outport: '<S27>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read8' incorporates:
   *  Outport: '<S27>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read9' incorporates:
   *  Outport: '<S27>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read10' incorporates:
   *  Outport: '<S27>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S27>/I2C Read11' incorporates:
   *  Outport: '<S27>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S27>/Byte Unpack' incorporates:
     *  Outport: '<S27>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S20>/One_time_initialization' */
void untitle_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_unt_T *localB, DW_One_time_initialization_un_T
  *localDW, P_One_time_initialization_unt_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S20>/One_time_initialization' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S27>/I2C Write3' incorporates:
     *  ArithShift: '<S27>/Shift Arithmetic1'
     *  Constant: '<S27>/registro memoria2 '
     *  DataTypeConversion: '<S27>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S27>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S27>/I2C Read' */
    if (localDW->obj_i.SampleTime != untitled1_P.t_AP) {
      localDW->obj_i.SampleTime = untitled1_P.t_AP;
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_i.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S27>/I2C Read' */

    /* MATLABSystem: '<S27>/I2C Read1' */
    if (localDW->obj_ni.SampleTime != untitled1_P.t_AP) {
      localDW->obj_ni.SampleTime = untitled1_P.t_AP;
    }

    status = 138U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ni.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ni.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead1, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read1' */

    /* MATLABSystem: '<S27>/I2C Read2' */
    if (localDW->obj_nf.SampleTime != untitled1_P.t_AP) {
      localDW->obj_nf.SampleTime = untitled1_P.t_AP;
    }

    status = 140U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_nf.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_nf.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead2, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read2' */

    /* MATLABSystem: '<S27>/I2C Read3' */
    if (localDW->obj_e.SampleTime != untitled1_P.t_AP) {
      localDW->obj_e.SampleTime = untitled1_P.t_AP;
    }

    status = 142U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_e.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead3, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(uint16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S27>/I2C Read3' */

    /* MATLABSystem: '<S27>/I2C Read4' */
    if (localDW->obj_n.SampleTime != untitled1_P.t_AP) {
      localDW->obj_n.SampleTime = untitled1_P.t_AP;
    }

    status = 144U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead4, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read4' */

    /* MATLABSystem: '<S27>/I2C Read5' */
    if (localDW->obj_f.SampleTime != untitled1_P.t_AP) {
      localDW->obj_f.SampleTime = untitled1_P.t_AP;
    }

    status = 146U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_f.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead5, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read5' */

    /* MATLABSystem: '<S27>/I2C Read6' */
    if (localDW->obj_ds.SampleTime != untitled1_P.t_AP) {
      localDW->obj_ds.SampleTime = untitled1_P.t_AP;
    }

    status = 148U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_ds.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_ds.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead6, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read6' */

    /* MATLABSystem: '<S27>/I2C Read7' */
    if (localDW->obj_o.SampleTime != untitled1_P.t_AP) {
      localDW->obj_o.SampleTime = untitled1_P.t_AP;
    }

    status = 150U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_o.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead7, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read7' */

    /* MATLABSystem: '<S27>/I2C Read8' */
    if (localDW->obj_d.SampleTime != untitled1_P.t_AP) {
      localDW->obj_d.SampleTime = untitled1_P.t_AP;
    }

    status = 152U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead8, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read8' */

    /* MATLABSystem: '<S27>/I2C Read9' */
    if (localDW->obj.SampleTime != untitled1_P.t_AP) {
      localDW->obj.SampleTime = untitled1_P.t_AP;
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
      /* MATLABSystem: '<S27>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read9' */

    /* MATLABSystem: '<S27>/I2C Read10' */
    if (localDW->obj_m.SampleTime != untitled1_P.t_AP) {
      localDW->obj_m.SampleTime = untitled1_P.t_AP;
    }

    status = 156U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_m.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead10, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read10' */

    /* MATLABSystem: '<S27>/I2C Read11' */
    if (localDW->obj_b.SampleTime != untitled1_P.t_AP) {
      localDW->obj_b.SampleTime = untitled1_P.t_AP;
    }

    status = 158U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(localDW->obj_b.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&localB->I2CRead11, (void *)&output_raw[0], (uint32_T)
             ((size_t)1 * sizeof(int16_T)));
    } else {
      /* MATLABSystem: '<S27>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S27>/I2C Read11' */

    /* MATLABSystem: '<S27>/I2C Write1' incorporates:
     *  Constant: '<S27>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_nb.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S27>/I2C Write2' incorporates:
     *  Constant: '<S27>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S27>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_eu.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S27>/I2C Read12' */
    if (localDW->obj_l.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_l.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S27>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S27>/Byte Unpack' */

    /* Unpack: <S27>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S20>/One_time_initialization' */
}

/* Termination for enable system: '<S20>/One_time_initialization' */
void un_One_time_initialization_Term(DW_One_time_initialization_un_T *localDW)
{
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S27>/I2C Read' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read1' */
  obj = &localDW->obj_ni;
  if (!localDW->obj_ni.matlabCodegenIsDeleted) {
    localDW->obj_ni.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ni.isInitialized == 1) && localDW->obj_ni.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read2' */
  obj = &localDW->obj_nf;
  if (!localDW->obj_nf.matlabCodegenIsDeleted) {
    localDW->obj_nf.matlabCodegenIsDeleted = true;
    if ((localDW->obj_nf.isInitialized == 1) && localDW->obj_nf.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read3' */
  obj = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read4' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read5' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read6' */
  obj = &localDW->obj_ds;
  if (!localDW->obj_ds.matlabCodegenIsDeleted) {
    localDW->obj_ds.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ds.isInitialized == 1) && localDW->obj_ds.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read7' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read8' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read10' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read11' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S27>/I2C Write1' */
  obj_0 = &localDW->obj_nb;
  if (!localDW->obj_nb.matlabCodegenIsDeleted) {
    localDW->obj_nb.matlabCodegenIsDeleted = true;
    if ((localDW->obj_nb.isInitialized == 1) && localDW->obj_nb.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S27>/I2C Write2' */
  obj_0 = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S27>/I2C Write3' */
  obj_0 = &localDW->obj_eu;
  if (!localDW->obj_eu.matlabCodegenIsDeleted) {
    localDW->obj_eu.matlabCodegenIsDeleted = true;
    if ((localDW->obj_eu.isInitialized == 1) && localDW->obj_eu.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S27>/I2C Read12' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/I2C Read12' */
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_eml_find(const boolean_T x[80], int32_T i_data[], int32_T
  i_size[2])
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_ifWhileCond(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_eml_find_n(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readNonFinite(const char_T s[2], int32_T *k, boolean_T
  *b_finite, real_T *fv)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copydigits(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copyexponent(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k)
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

      untitled1_B.kexp_b = *k;
      b_k = *k;
      b_success = untitled1_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > untitled1_B.kexp_b));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readfloat(char_T s1[4], int32_T *idx, const char_T s[2],
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
            untitled1_readfloat(s1, idx, s, k, false, &isneg, b_finite, nfv,
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
      untitled1_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = untitled1_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = untitled1_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static creal_T untitled1_str2double(const char_T s[2])
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
  untitled1_B.ntoread_h = 0;
  untitled1_B.k_b = 0;
  while ((untitled1_B.k_b + 1 <= 2) && (c[(uint8_T)s[untitled1_B.k_b] & 127] ||
          (s[untitled1_B.k_b] == '\x00'))) {
    untitled1_B.k_b++;
  }

  isimag1 = false;
  b_finite = true;
  untitled1_B.scanned1_l = 0.0;
  untitled1_B.idx_l = 1;
  untitled1_B.s1_l[0] = '\x00';
  untitled1_B.s1_l[1] = '\x00';
  untitled1_B.s1_l[2] = '\x00';
  untitled1_B.s1_l[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (untitled1_B.k_b + 1 <= 2)) {
    if (s[untitled1_B.k_b] == '-') {
      isneg = !isneg;
      untitled1_B.k_b++;
    } else if ((s[untitled1_B.k_b] == ',') || (s[untitled1_B.k_b] == '+') || c
               [(uint8_T)s[untitled1_B.k_b] & 127]) {
      untitled1_B.k_b++;
    } else {
      exitg1 = true;
    }
  }

  success = (untitled1_B.k_b + 1 <= 2);
  if (success && isneg) {
    untitled1_B.s1_l[0] = '-';
    untitled1_B.idx_l = 2;
  }

  untitled1_B.e_k = untitled1_B.k_b + 1;
  if (success) {
    if ((untitled1_B.k_b + 1 <= 2) && ((s[untitled1_B.k_b] == 'j') ||
         (s[untitled1_B.k_b] == 'i'))) {
      isimag1 = true;
      untitled1_B.e_k = untitled1_B.k_b + 2;
      while ((untitled1_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1] ==
               '\x00') || (s[1] == ','))) {
        untitled1_B.e_k = 3;
      }

      if ((untitled1_B.e_k <= 2) && (s[1] == '*')) {
        untitled1_B.e_k = 3;
        untitled1_readfloat(untitled1_B.s1_l, &untitled1_B.idx_l, s,
                            &untitled1_B.e_k, false, &isneg, &b_finite,
                            &untitled1_B.scanned1_l, &unusedU2, &success);
      } else {
        untitled1_B.s1_l[untitled1_B.idx_l - 1] = '1';
        untitled1_B.idx_l++;
      }
    } else {
      untitled1_B.e_k = untitled1_B.k_b + 1;
      untitled1_readNonFinite(s, &untitled1_B.e_k, &b_finite,
        &untitled1_B.scanned1_l);
      if (b_finite) {
        success = untitled1_copydigits(untitled1_B.s1_l, &untitled1_B.idx_l, s,
          &untitled1_B.e_k, true);
        if (success) {
          success = untitled1_copyexponent(untitled1_B.s1_l, &untitled1_B.idx_l,
            s, &untitled1_B.e_k);
        }
      } else {
        if ((untitled1_B.idx_l >= 2) && (untitled1_B.s1_l[0] == '-')) {
          untitled1_B.idx_l = 1;
          untitled1_B.s1_l[0] = ' ';
          untitled1_B.scanned1_l = -untitled1_B.scanned1_l;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (untitled1_B.e_k <= 2)) {
        tmp = s[untitled1_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          untitled1_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((untitled1_B.e_k <= 2) && (s[untitled1_B.e_k - 1] == '*')) {
        untitled1_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (untitled1_B.e_k <= 2)) {
          tmp = s[untitled1_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            untitled1_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (untitled1_B.e_k <= 2) {
        tmp = s[untitled1_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          untitled1_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (untitled1_B.e_k <= 2)) {
      tmp = s[untitled1_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        untitled1_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    untitled1_B.ntoread_h = 1;
  }

  if (success && (untitled1_B.e_k <= 2)) {
    untitled1_B.s1_l[untitled1_B.idx_l - 1] = ' ';
    untitled1_B.idx_l++;
    untitled1_readfloat(untitled1_B.s1_l, &untitled1_B.idx_l, s,
                        &untitled1_B.e_k, true, &success, &isneg,
                        &untitled1_B.scanned2_j, &unusedU2, &c_success);
    if (isneg) {
      untitled1_B.ntoread_h++;
    }

    success = (c_success && (untitled1_B.e_k > 2) && (isimag1 != success) &&
               unusedU2);
  } else {
    untitled1_B.scanned2_j = 0.0;
  }

  if (success) {
    untitled1_B.s1_l[untitled1_B.idx_l - 1] = '\x00';
    switch (untitled1_B.ntoread_h) {
     case 2:
      untitled1_B.ntoread_h = sscanf(&untitled1_B.s1_l[0], "%lf %lf",
        &untitled1_B.scanned1_l, &untitled1_B.scanned2_j);
      if (untitled1_B.ntoread_h != 2) {
        untitled1_B.scanned1_l = (rtNaN);
        untitled1_B.scanned2_j = (rtNaN);
      }
      break;

     case 1:
      untitled1_B.ntoread_h = sscanf(&untitled1_B.s1_l[0], "%lf",
        &untitled1_B.b_scanned1_d);
      if (b_finite) {
        if (untitled1_B.ntoread_h == 1) {
          untitled1_B.scanned1_l = untitled1_B.b_scanned1_d;
        } else {
          untitled1_B.scanned1_l = (rtNaN);
        }
      } else if (untitled1_B.ntoread_h == 1) {
        untitled1_B.scanned2_j = untitled1_B.b_scanned1_d;
      } else {
        untitled1_B.scanned2_j = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = untitled1_B.scanned2_j;
      x.im = untitled1_B.scanned1_l;
    } else {
      x.re = untitled1_B.scanned1_l;
      x.im = untitled1_B.scanned2_j;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copydigits_o(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readfloat_o(char_T s1_data[], int32_T *idx, const char_T
  s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
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
          untitled1_readfloat_o(s1_data, idx, s_data, k, n, false, &isneg,
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
        *success = untitled1_copydigits_o(s1_data, &b_idx, s_data, &h_k, n, true);
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
              isneg = untitled1_copydigits_o(s1_data, idx, s_data, &b_idx, n,
                false);
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static creal_T untitled1_str2double_i(const char_T s_data[], const int32_T
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
    untitled1_B.ntoread = 0;
    untitled1_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (untitled1_B.k <= s_size[1])) {
      tmp = s_data[untitled1_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        untitled1_B.k++;
      } else {
        exitg1 = true;
      }
    }

    untitled1_B.s1_size[0] = 1;
    untitled1_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    untitled1_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= untitled1_B.idx) {
      memset(&untitled1_B.s1_data[0], 0, (untitled1_B.idx + 1) * sizeof(char_T));
    }

    untitled1_B.idx = 1;
    untitled1_readfloat_o(untitled1_B.s1_data, &untitled1_B.idx, s_data,
                          &untitled1_B.k, s_size[1], true, &isimag1, &isfinite1,
                          &untitled1_B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      untitled1_B.ntoread = 1;
    }

    if (success) {
      if (untitled1_B.k <= s_size[1]) {
        untitled1_B.s1_data[untitled1_B.idx - 1] = ' ';
        untitled1_B.idx++;
        untitled1_readfloat_o(untitled1_B.s1_data, &untitled1_B.idx, s_data,
                              &untitled1_B.k, s_size[1], true, &unusedU0,
                              &success, &untitled1_B.scanned2, &foundsign,
                              &c_success);
        if (success) {
          untitled1_B.ntoread++;
        }

        success = (c_success && ((untitled1_B.k > s_size[1]) && ((isimag1 !=
          unusedU0) && foundsign)));
      } else {
        untitled1_B.scanned2 = 0.0;
      }
    } else {
      untitled1_B.scanned2 = 0.0;
    }

    if (success) {
      untitled1_B.s1_data[untitled1_B.idx - 1] = '\x00';
      switch (untitled1_B.ntoread) {
       case 2:
        untitled1_B.ntoread = sscanf(&untitled1_B.s1_data[0], "%lf %lf",
          &untitled1_B.scanned1, &untitled1_B.scanned2);
        if (untitled1_B.ntoread != 2) {
          untitled1_B.scanned1 = (rtNaN);
          untitled1_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        untitled1_B.ntoread = sscanf(&untitled1_B.s1_data[0], "%lf",
          &untitled1_B.b_scanned1);
        if (isfinite1) {
          if (untitled1_B.ntoread == 1) {
            untitled1_B.scanned1 = untitled1_B.b_scanned1;
          } else {
            untitled1_B.scanned1 = (rtNaN);
          }
        } else if (untitled1_B.ntoread == 1) {
          untitled1_B.scanned2 = untitled1_B.b_scanned1;
        } else {
          untitled1_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = untitled1_B.scanned2;
        x.im = untitled1_B.scanned1;
      } else {
        x.re = untitled1_B.scanned1;
        x.im = untitled1_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readNonFinite_e(const char_T s[3], int32_T *k, boolean_T
  *b_finite, real_T *fv)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copydigits_of(char_T s1[5], int32_T *idx, const
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copyexponent_a(char_T s1[5], int32_T *idx, const
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

      untitled1_B.kexp = *k;
      b_k = *k;
      b_success = untitled1_copydigits_of(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > untitled1_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readfloat_oc(char_T s1[5], int32_T *idx, const char_T s[3],
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
    if (untitled1_isUnitImag(s, b_k)) {
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
          untitled1_readfloat_oc(s1, idx, s, k, false, &isneg, b_finite, nfv,
            &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      untitled1_readNonFinite_e(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = untitled1_copydigits_of(s1, idx, s, k, true);
        if (*success) {
          *success = untitled1_copyexponent_a(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static creal_T untitled1_str2double_ic(const char_T s[3])
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
  untitled1_B.ntoread_n = 0;
  untitled1_B.k_o = 1;
  exitg1 = false;
  while ((!exitg1) && (untitled1_B.k_o <= 3)) {
    tmp = s[untitled1_B.k_o - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      untitled1_B.k_o++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  untitled1_B.scanned1_m = 0.0;
  untitled1_B.idx_b = 1;
  for (untitled1_B.b_k = 0; untitled1_B.b_k < 5; untitled1_B.b_k++) {
    untitled1_B.s1[untitled1_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (untitled1_B.k_o <= 3)) {
    tmp = s[untitled1_B.k_o - 1];
    if (tmp == '-') {
      isneg = !isneg;
      untitled1_B.k_o++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      untitled1_B.k_o++;
    } else {
      exitg1 = true;
    }
  }

  success = (untitled1_B.k_o <= 3);
  if (success && isneg) {
    untitled1_B.s1[0] = '-';
    untitled1_B.idx_b = 2;
  }

  untitled1_B.b_k = untitled1_B.k_o - 1;
  if (success) {
    if (untitled1_isUnitImag(s, untitled1_B.k_o)) {
      isimag1 = true;
      untitled1_B.b_k = untitled1_B.k_o;
      while ((untitled1_B.b_k + 1 <= 3) && (c[(uint8_T)s[untitled1_B.b_k] & 127]
              || (s[untitled1_B.b_k] == '\x00') || (s[untitled1_B.b_k] == ',')))
      {
        untitled1_B.b_k++;
      }

      if ((untitled1_B.b_k + 1 <= 3) && (s[untitled1_B.b_k] == '*')) {
        untitled1_B.k_o = untitled1_B.b_k + 2;
        untitled1_readfloat_oc(untitled1_B.s1, &untitled1_B.idx_b, s,
          &untitled1_B.k_o, false, &isneg, &b_finite, &untitled1_B.scanned1_m,
          &unusedU2, &success);
        untitled1_B.b_k = untitled1_B.k_o - 1;
      } else {
        untitled1_B.s1[untitled1_B.idx_b - 1] = '1';
        untitled1_B.idx_b++;
      }
    } else {
      untitled1_readNonFinite_e(s, &untitled1_B.k_o, &b_finite,
        &untitled1_B.scanned1_m);
      untitled1_B.b_k = untitled1_B.k_o - 1;
      if (b_finite) {
        success = untitled1_copydigits_of(untitled1_B.s1, &untitled1_B.idx_b, s,
          &untitled1_B.k_o, true);
        untitled1_B.b_k = untitled1_B.k_o - 1;
        if (success) {
          success = untitled1_copyexponent_a(untitled1_B.s1, &untitled1_B.idx_b,
            s, &untitled1_B.k_o);
          untitled1_B.b_k = untitled1_B.k_o - 1;
        }
      } else {
        if ((untitled1_B.idx_b >= 2) && (untitled1_B.s1[0] == '-')) {
          untitled1_B.idx_b = 1;
          untitled1_B.s1[0] = ' ';
          untitled1_B.scanned1_m = -untitled1_B.scanned1_m;
        }
      }

      while ((untitled1_B.b_k + 1 <= 3) && (c[(uint8_T)s[untitled1_B.b_k] & 127]
              || (s[untitled1_B.b_k] == '\x00') || (s[untitled1_B.b_k] == ',')))
      {
        untitled1_B.b_k++;
      }

      if ((untitled1_B.b_k + 1 <= 3) && (s[untitled1_B.b_k] == '*')) {
        untitled1_B.b_k++;
        while ((untitled1_B.b_k + 1 <= 3) && (c[(uint8_T)s[untitled1_B.b_k] &
                127] || (s[untitled1_B.b_k] == '\x00') || (s[untitled1_B.b_k] ==
                 ','))) {
          untitled1_B.b_k++;
        }
      }

      if ((untitled1_B.b_k + 1 <= 3) && ((s[untitled1_B.b_k] == 'i') ||
           (s[untitled1_B.b_k] == 'j'))) {
        untitled1_B.b_k++;
        isimag1 = true;
      }
    }

    while ((untitled1_B.b_k + 1 <= 3) && (c[(uint8_T)s[untitled1_B.b_k] & 127] ||
            (s[untitled1_B.b_k] == '\x00') || (s[untitled1_B.b_k] == ','))) {
      untitled1_B.b_k++;
    }
  }

  if (b_finite) {
    untitled1_B.ntoread_n = 1;
  }

  if (success && (untitled1_B.b_k + 1 <= 3)) {
    untitled1_B.s1[untitled1_B.idx_b - 1] = ' ';
    untitled1_B.idx_b++;
    untitled1_B.k_o = untitled1_B.b_k + 1;
    untitled1_readfloat_oc(untitled1_B.s1, &untitled1_B.idx_b, s,
      &untitled1_B.k_o, true, &success, &isneg, &untitled1_B.scanned2_n,
      &unusedU2, &c_success);
    if (isneg) {
      untitled1_B.ntoread_n++;
    }

    success = (c_success && (untitled1_B.k_o > 3) && (isimag1 != success) &&
               unusedU2);
  } else {
    untitled1_B.scanned2_n = 0.0;
  }

  if (success) {
    untitled1_B.s1[untitled1_B.idx_b - 1] = '\x00';
    switch (untitled1_B.ntoread_n) {
     case 2:
      untitled1_B.ntoread_n = sscanf(&untitled1_B.s1[0], "%lf %lf",
        &untitled1_B.scanned1_m, &untitled1_B.scanned2_n);
      if (untitled1_B.ntoread_n != 2) {
        untitled1_B.scanned1_m = (rtNaN);
        untitled1_B.scanned2_n = (rtNaN);
      }
      break;

     case 1:
      untitled1_B.ntoread_n = sscanf(&untitled1_B.s1[0], "%lf",
        &untitled1_B.b_scanned1_p);
      if (b_finite) {
        if (untitled1_B.ntoread_n == 1) {
          untitled1_B.scanned1_m = untitled1_B.b_scanned1_p;
        } else {
          untitled1_B.scanned1_m = (rtNaN);
        }
      } else if (untitled1_B.ntoread_n == 1) {
        untitled1_B.scanned2_n = untitled1_B.b_scanned1_p;
      } else {
        untitled1_B.scanned2_n = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = untitled1_B.scanned2_n;
      x.im = untitled1_B.scanned1_m;
    } else {
      x.re = untitled1_B.scanned1_m;
      x.im = untitled1_B.scanned2_n;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readNonFinite_eq(char_T s, int32_T *k, boolean_T *b_finite,
  real_T *fv)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copydigits_ofu(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static boolean_T untitled1_copyexponent_ao(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k)
{
  int32_T b_k;
  boolean_T b_success;
  boolean_T success;
  success = true;
  if ((*k <= 1) && ((s == 'E') || (s == 'e'))) {
    s1[*idx - 1] = 'e';
    (*idx)++;
    b_k = 2;
    b_success = untitled1_copydigits_ofu(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static void untitled1_readfloat_ocp(char_T s1[3], int32_T *idx, char_T s,
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
          untitled1_readfloat_ocp(s1, idx, '\x2a', k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      untitled1_readNonFinite_eq(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = untitled1_copydigits_ofu(s1, idx, s, k, true);
        if (*success) {
          *success = untitled1_copyexponent_ao(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static creal_T untitled1_str2double_ics(char_T s)
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
  untitled1_B.ntoread_e = 0;
  untitled1_B.d_k = 1;
  untitled1_B.i_b = (uint8_T)s & 127;
  if (c[untitled1_B.i_b] || (s == '\x00')) {
    untitled1_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  untitled1_B.scanned1_g = 0.0;
  untitled1_B.idx_d = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (untitled1_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      untitled1_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[untitled1_B.i_b]) {
      untitled1_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (untitled1_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    untitled1_B.idx_d = 2;
  }

  if (success) {
    isneg = false;
    if (untitled1_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      untitled1_B.d_k++;
      s1[untitled1_B.idx_d - 1] = '1';
      untitled1_B.idx_d++;
    } else {
      untitled1_readNonFinite_eq(s, &untitled1_B.d_k, &b_finite,
        &untitled1_B.scanned1_g);
      if (b_finite) {
        success = untitled1_copydigits_ofu(s1, &untitled1_B.idx_d, s,
          &untitled1_B.d_k, true);
        if (success) {
          success = untitled1_copyexponent_ao(s1, &untitled1_B.idx_d, s,
            &untitled1_B.d_k);
        }
      } else {
        if ((untitled1_B.idx_d >= 2) && (s1[0] == '-')) {
          untitled1_B.idx_d = 1;
          s1[0] = ' ';
          untitled1_B.scanned1_g = -untitled1_B.scanned1_g;
        }
      }

      while ((untitled1_B.d_k <= 1) && (c[untitled1_B.i_b] || ((s == '\x00') ||
               (s == ',')))) {
        untitled1_B.d_k = 2;
      }

      if ((untitled1_B.d_k <= 1) && (s == '*')) {
        untitled1_B.d_k = 2;
      }

      if ((untitled1_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        untitled1_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((untitled1_B.d_k <= 1) && (c[untitled1_B.i_b] || ((s == '\x00') || (s
              == ',')))) {
      untitled1_B.d_k = 2;
    }
  }

  if (b_finite) {
    untitled1_B.ntoread_e = 1;
  }

  if (success && (untitled1_B.d_k <= 1)) {
    s1[untitled1_B.idx_d - 1] = ' ';
    untitled1_B.idx_d++;
    untitled1_B.d_k = 1;
    untitled1_readfloat_ocp(s1, &untitled1_B.idx_d, s, &untitled1_B.d_k, true,
      &success, &isneg, &untitled1_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      untitled1_B.ntoread_e++;
    }

    success = (c_success && (untitled1_B.d_k > 1) && (isimag1 != success) &&
               foundsign);
  } else {
    untitled1_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[untitled1_B.idx_d - 1] = '\x00';
    switch (untitled1_B.ntoread_e) {
     case 2:
      untitled1_B.ntoread_e = sscanf(&s1[0], "%lf %lf", &untitled1_B.scanned1_g,
        &untitled1_B.scanned2_l);
      if (untitled1_B.ntoread_e != 2) {
        untitled1_B.scanned1_g = (rtNaN);
        untitled1_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      untitled1_B.ntoread_e = sscanf(&s1[0], "%lf", &untitled1_B.b_scanned1_dh);
      if (b_finite) {
        if (untitled1_B.ntoread_e == 1) {
          untitled1_B.scanned1_g = untitled1_B.b_scanned1_dh;
        } else {
          untitled1_B.scanned1_g = (rtNaN);
        }
      } else if (untitled1_B.ntoread_e == 1) {
        untitled1_B.scanned2_l = untitled1_B.b_scanned1_dh;
      } else {
        untitled1_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = untitled1_B.scanned2_l;
      x.im = untitled1_B.scanned1_g;
    } else {
      x.re = untitled1_B.scanned1_g;
      x.im = untitled1_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S34>/MATLAB Function' */
static real_T untitled1_hex2dec(const char_T s[2])
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

  untitled1_B.a = tmp_0;
  untitled1_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &untitled1_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&untitled1_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &untitled1_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &untitled1_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&untitled1_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &untitled1_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &untitled1_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&untitled1_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &untitled1_B.sk.chunks[0U], 2);
      } else {
        untitled1_B.sk = tmp_0;
      }
    } else {
      untitled1_B.sk = tmp_0;
    }

    uMultiWordMul(&untitled1_B.sk.chunks[0U], 2, &untitled1_B.p16.chunks[0U], 2,
                  &untitled1_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&untitled1_B.r.chunks[0U], 4, &untitled1_B.r3.chunks[0U],
                         2);
    MultiWordAdd(&untitled1_B.a.chunks[0U], &untitled1_B.r3.chunks[0U],
                 &tmp.chunks[0U], 2);
    untitled1_B.a = tmp;
    uMultiWord2MultiWord(&untitled1_B.p16.chunks[0U], 2, &untitled1_B.r2.chunks
                         [0U], 3);
    uMultiWordShl(&untitled1_B.r2.chunks[0U], 3, 4U, &untitled1_B.r1.chunks[0U],
                  3);
    uMultiWord2MultiWord(&untitled1_B.r1.chunks[0U], 3, &untitled1_B.p16.chunks
                         [0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&untitled1_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&untitled1_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&untitled1_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&untitled1_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&untitled1_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&untitled1_B.a.chunks[0U], 2, 0);
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
void untitled1_step(void)
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  int32_T exitg2;
  char_T ck_ric[2];
  char_T messaggio;
  uint8_T output_raw_0[3];
  uint8_T output[2];
  uint8_T output_raw[2];
  uint8_T find_comma;
  uint8_T status;
  boolean_T exitg1;
  boolean_T guard1 = false;

  /* S-Function (Mti): '<S22>/S-Function Builder' */
  Mti_Outputs_wrapper(&untitled1_B.SFunctionBuilder[0],
                      &untitled1_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S22>/Byte Unpack' */

  /* Unpack: <S22>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&untitled1_B.ByteUnpack_o1[0], (uint8_T*)
             &untitled1_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&untitled1_B.ByteUnpack_o2[0], (uint8_T*)
             &untitled1_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&untitled1_B.ByteUnpack_o3_o, (uint8_T*)
             &untitled1_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S22>/Byte Reversal' */

  /* ReverseEndian: <S22>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &untitled1_B.ByteUnpack_o2[0];
    real32_T *y0 = &untitled1_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Outputs for Enabled SubSystem: '<S20>/One_time_initialization' */
  /* Logic: '<S20>/Logical Operator1' incorporates:
   *  UnitDelay: '<S20>/Unit Delay'
   */
  untitle_One_time_initialization(!untitled1_DW.UnitDelay_DSTATE_j,
    &untitled1_B.One_time_initialization, &untitled1_DW.One_time_initialization,
    &untitled1_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S20>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S20>/Execution_loop' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  /* UnitDelay: '<S20>/Unit Delay' */
  if (untitled1_DW.UnitDelay_DSTATE_j) {
    /* MATLABSystem: '<S24>/I2C Read12' */
    if (untitled1_DW.obj_d.SampleTime != untitled1_P.t_AP) {
      untitled1_DW.obj_d.SampleTime = untitled1_P.t_AP;
    }

    status = 250U;
    status = MW_I2C_MasterWrite(untitled1_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE,
      118U, &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(untitled1_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw[0], 2U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw[0], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
    }

    /* MATLABSystem: '<S24>/I2C Read1' */
    if (untitled1_DW.obj_n.SampleTime != untitled1_P.t_AP) {
      untitled1_DW.obj_n.SampleTime = untitled1_P.t_AP;
    }

    status = 247U;
    status = MW_I2C_MasterWrite(untitled1_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE,
      118U, &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(untitled1_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U,
                        &output_raw_0[0], 3U, false, true);
      memcpy((void *)&untitled1_B.output[0], (void *)&output_raw_0[0], (uint32_T)
             ((size_t)3 * sizeof(uint8_T)));
    } else {
      untitled1_B.output[0] = 0U;
      untitled1_B.output[1] = 0U;
      untitled1_B.output[2] = 0U;
    }

    /* ArithShift: '<S24>/Shift Arithmetic4' incorporates:
     *  Constant: '<S24>/Constant1'
     */
    untitled1_B.UkYk1 = floor(untitled1_P.Constant1_Value);
    if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
      untitled1_B.UkYk1 = 0.0;
    } else {
      untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 4.294967296E+9);
    }

    /* ArithShift: '<S24>/Shift Arithmetic3' incorporates:
     *  Constant: '<S24>/Constant5'
     */
    untitled1_B.deltafalllimit = floor(untitled1_P.Constant5_Value);
    if (rtIsNaN(untitled1_B.deltafalllimit) || rtIsInf
        (untitled1_B.deltafalllimit)) {
      untitled1_B.deltafalllimit = 0.0;
    } else {
      untitled1_B.deltafalllimit = fmod(untitled1_B.deltafalllimit,
        4.294967296E+9);
    }

    /* ArithShift: '<S24>/Shift Arithmetic1' incorporates:
     *  Constant: '<S24>/Constant6'
     */
    untitled1_B.rtb_V_re = floor(untitled1_P.Constant6_Value);
    if (rtIsNaN(untitled1_B.rtb_V_re) || rtIsInf(untitled1_B.rtb_V_re)) {
      untitled1_B.rtb_V_re = 0.0;
    } else {
      untitled1_B.rtb_V_re = fmod(untitled1_B.rtb_V_re, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S24>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S24>/Shift Arithmetic1'
     *  ArithShift: '<S24>/Shift Arithmetic3'
     *  ArithShift: '<S24>/Shift Arithmetic4'
     *  Constant: '<S24>/Constant10'
     *  Constant: '<S24>/Constant11'
     *  Constant: '<S24>/Constant7'
     *  MATLABSystem: '<S24>/I2C Read1'
     *  Sum: '<S24>/Sum1'
     *  Sum: '<S24>/Sum4'
     *  Sum: '<S24>/Sum5'
     *  Sum: '<S24>/Sum6'
     */
    untitled1_B.DataTypeConversion1 = (int32_T)((((((untitled1_P.Constant7_Value
      + untitled1_B.output[0]) << (untitled1_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
      -untitled1_B.UkYk1 : (int32_T)(uint32_T)untitled1_B.UkYk1)) +
      ((untitled1_P.Constant10_Value + untitled1_B.output[1]) <<
       (untitled1_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
        -untitled1_B.deltafalllimit : (int32_T)(uint32_T)
        untitled1_B.deltafalllimit))) + untitled1_P.Constant11_Value) +
      untitled1_B.output[2]) >> (untitled1_B.rtb_V_re < 0.0 ? -(int32_T)
      (uint32_T)-untitled1_B.rtb_V_re : (int32_T)(uint32_T)untitled1_B.rtb_V_re));

    /* ArithShift: '<S24>/Shift Arithmetic7' incorporates:
     *  Constant: '<S24>/Constant2'
     */
    untitled1_B.UkYk1 = floor(untitled1_P.Constant2_Value);
    if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
      untitled1_B.UkYk1 = 0.0;
    } else {
      untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 4.294967296E+9);
    }

    /* ArithShift: '<S24>/Shift Arithmetic6' incorporates:
     *  Constant: '<S24>/Constant3'
     */
    untitled1_B.deltafalllimit = floor(untitled1_P.Constant3_Value);
    if (rtIsNaN(untitled1_B.deltafalllimit) || rtIsInf
        (untitled1_B.deltafalllimit)) {
      untitled1_B.deltafalllimit = 0.0;
    } else {
      untitled1_B.deltafalllimit = fmod(untitled1_B.deltafalllimit,
        4.294967296E+9);
    }

    /* ArithShift: '<S24>/Shift Arithmetic2' incorporates:
     *  Constant: '<S24>/Constant4'
     */
    untitled1_B.rtb_V_re = floor(untitled1_P.Constant4_Value);
    if (rtIsNaN(untitled1_B.rtb_V_re) || rtIsInf(untitled1_B.rtb_V_re)) {
      untitled1_B.rtb_V_re = 0.0;
    } else {
      untitled1_B.rtb_V_re = fmod(untitled1_B.rtb_V_re, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S24>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S24>/Shift Arithmetic2'
     *  ArithShift: '<S24>/Shift Arithmetic6'
     *  ArithShift: '<S24>/Shift Arithmetic7'
     *  Constant: '<S24>/Constant8'
     *  Constant: '<S24>/Constant9'
     *  MATLABSystem: '<S24>/I2C Read12'
     *  Sum: '<S24>/Sum'
     *  Sum: '<S24>/Sum2'
     *  Sum: '<S24>/Sum3'
     */
    untitled1_B.DataTypeConversion = (int32_T)((((untitled1_P.Constant8_Value +
      output[0]) << (untitled1_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
                     -untitled1_B.UkYk1 : (int32_T)(uint32_T)untitled1_B.UkYk1))
      + ((untitled1_P.Constant9_Value + output[1]) <<
         (untitled1_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
          -untitled1_B.deltafalllimit : (int32_T)(uint32_T)
          untitled1_B.deltafalllimit))) >> (untitled1_B.rtb_V_re < 0.0 ?
      -(int32_T)(uint32_T)-untitled1_B.rtb_V_re : (int32_T)(uint32_T)
      untitled1_B.rtb_V_re));

    /* S-Function (calc_T): '<S24>/S-Function Builder' */
    calc_T_Outputs_wrapper(&untitled1_B.One_time_initialization.I2CRead,
      &untitled1_B.One_time_initialization.I2CRead1,
      &untitled1_B.One_time_initialization.I2CRead2,
      &untitled1_B.DataTypeConversion, &untitled1_B.SFunctionBuilder_o1,
      &untitled1_B.SFunctionBuilder_o2);

    /* S-Function (calc_p): '<S24>/S-Function Builder1' */
    calc_p_Outputs_wrapper(&untitled1_B.One_time_initialization.I2CRead3,
      &untitled1_B.One_time_initialization.I2CRead4,
      &untitled1_B.One_time_initialization.I2CRead5,
      &untitled1_B.One_time_initialization.I2CRead6,
      &untitled1_B.One_time_initialization.I2CRead7,
      &untitled1_B.One_time_initialization.I2CRead8,
      &untitled1_B.One_time_initialization.I2CRead9,
      &untitled1_B.One_time_initialization.I2CRead10,
      &untitled1_B.One_time_initialization.I2CRead11,
      &untitled1_B.DataTypeConversion1, &untitled1_B.SFunctionBuilder_o2,
      &untitled1_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S20>/Execution_loop' */

  /* MATLABSystem: '<S7>/Serial Receive' */
  if (untitled1_DW.obj_k.Protocol != untitled1_P.SerialReceive_Protocol) {
    untitled1_DW.obj_k.Protocol = untitled1_P.SerialReceive_Protocol;
  }

  MW_Serial_read(1, untitled1_DW.obj_k.DataSizeInBytes,
                 &untitled1_B.b_dataOut_b[0], &status);

  /* Outputs for Enabled SubSystem: '<S7>/Subsystem1' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S15>/MATLAB Function' */
    for (untitled1_B.i = 0; untitled1_B.i < 31; untitled1_B.i++) {
      untitled1_B.messaggio[untitled1_B.i] = 0U;
    }

    guard1 = false;
    if (!untitled1_DW.start_found_g) {
      untitled1_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (untitled1_B.i - 1 < 30)) {
        if ((untitled1_B.b_dataOut_b[(uint8_T)untitled1_B.i - 1] == 255) &&
            (untitled1_B.b_dataOut_b[(uint8_T)untitled1_B.i] == 254)) {
          untitled1_B.loop_ub = 31 - (uint8_T)untitled1_B.i;
          for (untitled1_B.b_i = 0; untitled1_B.b_i <= untitled1_B.loop_ub;
               untitled1_B.b_i++) {
            untitled1_DW.message_i[untitled1_B.b_i] = untitled1_B.b_dataOut_b
              [((uint8_T)untitled1_B.i + untitled1_B.b_i) - 1];
          }

          untitled1_DW.counter_b = (uint8_T)(32 - (uint8_T)untitled1_B.i);
          untitled1_DW.start_found_g = true;
          exitg1 = true;
        } else {
          untitled1_B.i++;
        }
      }

      if (untitled1_DW.counter_b == 31) {
        for (untitled1_B.i = 0; untitled1_B.i < 31; untitled1_B.i++) {
          untitled1_B.messaggio[untitled1_B.i] =
            untitled1_DW.message_i[untitled1_B.i];
          untitled1_DW.message_i[untitled1_B.i] = 0U;
        }

        untitled1_DW.start_found_g = false;
        untitled1_DW.counter_b = 0U;
        guard1 = true;
      }
    } else {
      untitled1_B.qY = 31U - /*MW:OvSatOk*/ untitled1_DW.counter_b;
      if (31U - untitled1_DW.counter_b > 31U) {
        untitled1_B.qY = 0U;
      }

      untitled1_B.b_i = (int32_T)(untitled1_DW.counter_b + 1U);
      if (untitled1_DW.counter_b + 1U > 255U) {
        untitled1_B.b_i = 255;
      }

      if ((uint8_T)untitled1_B.b_i > 31) {
        untitled1_B.i = 1;
      } else {
        untitled1_B.i = (uint8_T)untitled1_B.b_i;
      }

      if (1 > (uint8_T)untitled1_B.qY) {
        untitled1_B.loop_ub = -1;
      } else {
        untitled1_B.loop_ub = (uint8_T)untitled1_B.qY - 1;
      }

      for (untitled1_B.b_i = 0; untitled1_B.b_i <= untitled1_B.loop_ub;
           untitled1_B.b_i++) {
        untitled1_DW.message_i[(untitled1_B.i + untitled1_B.b_i) - 1] =
          untitled1_B.b_dataOut_b[untitled1_B.b_i];
      }

      untitled1_B.qY = 31U - /*MW:OvSatOk*/ untitled1_DW.counter_b;
      if (31U - untitled1_DW.counter_b > 31U) {
        untitled1_B.qY = 0U;
      }

      untitled1_DW.counter_b = (uint8_T)untitled1_B.qY;
      for (untitled1_B.i = 0; untitled1_B.i < 31; untitled1_B.i++) {
        untitled1_B.messaggio[untitled1_B.i] =
          untitled1_DW.message_i[untitled1_B.i];
        untitled1_DW.message_i[untitled1_B.i] = 0U;
      }

      status = untitled1_DW.counter_b;
      do {
        exitg2 = 0;
        if (status < 31) {
          if ((untitled1_B.b_dataOut_b[status - 1] == 255) &&
              (untitled1_B.b_dataOut_b[status] == 254)) {
            untitled1_B.loop_ub = 31 - status;
            for (untitled1_B.b_i = 0; untitled1_B.b_i <= untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_DW.message_i[untitled1_B.b_i] = untitled1_B.b_dataOut_b
                [(status + untitled1_B.b_i) - 1];
            }

            untitled1_B.qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              untitled1_B.qY = 0U;
            }

            untitled1_DW.counter_b = (uint8_T)(31 - (int32_T)untitled1_B.qY);
            untitled1_DW.start_found_g = true;
            guard1 = true;
            exitg2 = 1;
          } else {
            untitled1_DW.start_found_g = false;
            untitled1_DW.counter_b = 0U;
            status++;
          }
        } else {
          guard1 = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (guard1) {
      /* Outputs for Enabled SubSystem: '<S15>/Subsystem2' incorporates:
       *  EnablePort: '<S19>/Enable'
       */
      /* S-Function (byte2any_svd): '<S19>/Byte Unpack' */

      /* Unpack: <S19>/Byte Unpack */
      {
        uint32_T MW_inputPortOffset = 0;
        uint32_T MW_outputPortWidth = 0;
        uint32_T MW_remainder2 = 0;

        /* Packed input data type - uint8_T */
        /* Unpacking the values to output 1 */
        /* Output data type - uint8_T, size - 2 */
        {
          MW_outputPortWidth = 2 * sizeof(uint8_T);
          memcpy((uint8_T*)&untitled1_B.ByteUnpack_o1_j[0], (uint8_T*)
                 &untitled1_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&untitled1_B.ByteUnpack_o2_e[0], (uint8_T*)
                 &untitled1_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&untitled1_B.ByteUnpack_o3[0], (uint8_T*)
                 &untitled1_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&untitled1_B.ByteUnpack_o4[0], (uint8_T*)
                 &untitled1_B.messaggio[0] + MW_inputPortOffset,
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
          memcpy((uint8_T*)&untitled1_B.ByteUnpack_o5, (uint8_T*)
                 &untitled1_B.messaggio[0] + MW_inputPortOffset,
                 MW_outputPortWidth);
        }
      }

      /* End of Outputs for SubSystem: '<S15>/Subsystem2' */
    }

    /* End of MATLAB Function: '<S15>/MATLAB Function' */
  }

  /* End of MATLABSystem: '<S7>/Serial Receive' */
  /* End of Outputs for SubSystem: '<S7>/Subsystem1' */

  /* MATLAB Function: '<S20>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   */
  if (untitled1_P.Constant4_Value_d == 1.0) {
    untitled1_DW.P_ref = untitled1_B.SFunctionBuilder1;
  }

  if (untitled1_P.Constant2_Value_m == 1.0) {
    untitled1_DW.P_ref = untitled1_P.Constant3_Value_p;
    untitled1_DW.rl_up = 20.0;
    untitled1_DW.rl_dw = -20.0;
  }

  /* Product: '<S23>/delta rise limit' incorporates:
   *  MATLAB Function: '<S20>/MATLAB Function'
   *  SampleTimeMath: '<S23>/sample time'
   *
   * About '<S23>/sample time':
   *  y = K where K = ( w * Ts )
   */
  untitled1_B.deltafalllimit = untitled1_DW.rl_up * untitled1_P.sampletime_WtEt;

  /* Sum: '<S23>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S20>/MATLAB Function'
   *  UnitDelay: '<S23>/Delay Input2'
   *
   * Block description for '<S23>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S23>/Delay Input2':
   *
   *  Store in Global RAM
   */
  untitled1_B.UkYk1 = untitled1_DW.P_ref - untitled1_DW.DelayInput2_DSTATE;

  /* Switch: '<S29>/Switch2' incorporates:
   *  RelationalOperator: '<S29>/LowerRelop1'
   */
  if (!(untitled1_B.UkYk1 > untitled1_B.deltafalllimit)) {
    /* Product: '<S23>/delta fall limit' incorporates:
     *  MATLAB Function: '<S20>/MATLAB Function'
     *  SampleTimeMath: '<S23>/sample time'
     *
     * About '<S23>/sample time':
     *  y = K where K = ( w * Ts )
     */
    untitled1_B.deltafalllimit = untitled1_DW.rl_dw *
      untitled1_P.sampletime_WtEt;

    /* Switch: '<S29>/Switch' incorporates:
     *  RelationalOperator: '<S29>/UpperRelop'
     */
    if (!(untitled1_B.UkYk1 < untitled1_B.deltafalllimit)) {
      untitled1_B.deltafalllimit = untitled1_B.UkYk1;
    }

    /* End of Switch: '<S29>/Switch' */
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Sum: '<S23>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S23>/Delay Input2'
   *
   * Block description for '<S23>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S23>/Delay Input2':
   *
   *  Store in Global RAM
   */
  untitled1_DW.DelayInput2_DSTATE += untitled1_B.deltafalllimit;

  /* Outputs for Enabled SubSystem: '<S28>/Subsystem1' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  /* Constant: '<S2>/Constant4' */
  if (untitled1_P.Constant4_Value_d > 0.0) {
    /* Inport: '<S30>/T' */
    untitled1_B.T = untitled1_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S28>/Subsystem1' */

  /* MATLABSystem: '<S21>/Serial Receive1' */
  if (untitled1_DW.obj_b.Protocol != untitled1_P.SerialReceive1_Protocol) {
    untitled1_DW.obj_b.Protocol = untitled1_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(0, untitled1_DW.obj_b.DataSizeInBytes, &untitled1_B.b_dataOut[0],
                 &status);

  /* Outputs for Enabled SubSystem: '<S21>/Subsystem2' incorporates:
   *  EnablePort: '<S32>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S32>/Create_message' */
    status = 0U;
    if (!untitled1_DW.start_found) {
      untitled1_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (untitled1_B.i - 1 < 32)) {
        if (untitled1_B.b_dataOut[(uint8_T)untitled1_B.i - 1] == 36) {
          untitled1_B.loop_ub = 32 - (uint8_T)untitled1_B.i;
          for (untitled1_B.b_i = 0; untitled1_B.b_i <= untitled1_B.loop_ub;
               untitled1_B.b_i++) {
            untitled1_DW.message[untitled1_B.b_i] = untitled1_B.b_dataOut
              [((uint8_T)untitled1_B.i + untitled1_B.b_i) - 1];
          }

          untitled1_DW.counter = (uint8_T)(33 - (uint8_T)untitled1_B.i);
          untitled1_DW.start_found = true;
          exitg1 = true;
        } else {
          untitled1_B.i++;
        }
      }
    } else {
      untitled1_B.b_i = 1;
      exitg1 = false;
      while ((!exitg1) && (untitled1_B.b_i - 1 < 32)) {
        if (untitled1_B.b_dataOut[(uint8_T)untitled1_B.b_i - 1] == 13) {
          untitled1_DW.end_found = true;
          status = (uint8_T)untitled1_B.b_i;
          exitg1 = true;
        } else {
          untitled1_B.b_i++;
        }
      }

      if (untitled1_DW.end_found) {
        if (1 > status) {
          untitled1_B.loop_ub = -1;
        } else {
          untitled1_B.loop_ub = status - 1;
        }

        for (untitled1_B.b_i = 0; untitled1_B.b_i <= untitled1_B.loop_ub;
             untitled1_B.b_i++) {
          untitled1_B.i = (int32_T)(((uint32_T)untitled1_B.b_i +
            untitled1_DW.counter) + 1U);
          if ((uint32_T)untitled1_B.i > 255U) {
            untitled1_B.i = 255;
          }

          untitled1_DW.message[untitled1_B.i - 1] =
            untitled1_B.b_dataOut[untitled1_B.b_i];
        }

        memcpy(&untitled1_B.messaggio_k[0], &untitled1_DW.message[0], 80U *
               sizeof(uint8_T));
        untitled1_DW.end_found = false;
        untitled1_DW.counter = (uint8_T)(32 - status);
        if (status == 32) {
          untitled1_DW.start_found = false;
          memset(&untitled1_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          untitled1_DW.start_found = true;
          untitled1_B.loop_ub = -status;
          for (untitled1_B.b_i = 0; untitled1_B.b_i <= untitled1_B.loop_ub + 31;
               untitled1_B.b_i++) {
            untitled1_DW.message[untitled1_B.b_i] = untitled1_B.b_dataOut[status
              + untitled1_B.b_i];
          }

          untitled1_B.b_i = status + 48;
          if (0 <= untitled1_B.b_i - 1) {
            memset(&untitled1_DW.message[-status + 32], 0, ((untitled1_B.b_i -
                     status) + status) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S32>/Subsystem' incorporates:
         *  EnablePort: '<S34>/Enable'
         */
        /* MATLAB Function: '<S34>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        untitled1_B.indice_dimario = 0U;
        for (untitled1_B.i = 0; untitled1_B.i < 80; untitled1_B.i++) {
          messaggio = (int8_T)untitled1_B.messaggio_k[untitled1_B.i];
          if (messaggio == '$') {
            untitled1_B.b_i = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              untitled1_B.b_i = 255;
            }

            status = (uint8_T)untitled1_B.b_i;
          }

          if (messaggio == ',') {
            untitled1_B.b_i = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              untitled1_B.b_i = 255;
            }

            find_comma = (uint8_T)untitled1_B.b_i;
          }

          untitled1_B.messaggio_m[untitled1_B.i] = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++) {
            untitled1_B.messaggio_c[untitled1_B.b_i] =
              (untitled1_B.messaggio_m[untitled1_B.b_i] == '$');
          }

          untitled1_eml_find(untitled1_B.messaggio_c, &untitled1_B.eb_data,
                             untitled1_B.eb_size);
          untitled1_B.loop_ub = untitled1_B.eb_data;
          for (untitled1_B.b_i = 0; untitled1_B.b_i < 5; untitled1_B.b_i++) {
            messaggio = untitled1_B.messaggio_m[untitled1_B.b_i +
              untitled1_B.loop_ub];
            untitled1_B.mess_type_d[untitled1_B.b_i] = (messaggio ==
              bb[untitled1_B.b_i]);
            untitled1_B.mess_type[untitled1_B.b_i] = messaggio;
          }

          if (untitled1_ifWhileCond(untitled1_B.mess_type_d)) {
            for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++) {
              untitled1_B.messaggio_c[untitled1_B.b_i] =
                (untitled1_B.messaggio_m[untitled1_B.b_i] == ',');
            }

            untitled1_eml_find_n(untitled1_B.messaggio_c,
                                 untitled1_B.comma_gga_data, untitled1_B.eb_size);
            for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++) {
              untitled1_B.messaggio_c[untitled1_B.b_i] =
                (untitled1_B.messaggio_m[untitled1_B.b_i] == '*');
            }

            untitled1_eml_find_n(untitled1_B.messaggio_c, untitled1_B.star_data,
                                 untitled1_B.star_size);
            for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++) {
              untitled1_B.messaggio_c[untitled1_B.b_i] =
                (untitled1_B.messaggio_m[untitled1_B.b_i] == '$');
            }

            untitled1_eml_find_n(untitled1_B.messaggio_c, untitled1_B.fb_data,
                                 untitled1_B.star_size);
            untitled1_B.Lat_1 = untitled1_str2double
              (&untitled1_B.messaggio_m[untitled1_B.comma_gga_data[2]]);
            if ((real_T)untitled1_B.comma_gga_data[2] + 3.0 > (real_T)
                untitled1_B.comma_gga_data[3] - 1.0) {
              untitled1_B.i = 0;
              untitled1_B.b_i = 0;
            } else {
              untitled1_B.i = untitled1_B.comma_gga_data[2] + 2;
              untitled1_B.b_i = untitled1_B.comma_gga_data[3] - 1;
            }

            untitled1_B.messaggio_size[0] = 1;
            untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
            untitled1_B.messaggio_size[1] = untitled1_B.loop_ub;
            for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_B.messaggio_data[untitled1_B.b_i] =
                untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
            }

            untitled1_B.b_x = untitled1_str2double_i(untitled1_B.messaggio_data,
              untitled1_B.messaggio_size);
            if (untitled1_B.b_x.im == 0.0) {
              untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
            } else if (untitled1_B.b_x.re == 0.0) {
              untitled1_B.deltafalllimit = 0.0;
            } else {
              untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
            }

            untitled1_B.UkYk1 = untitled1_B.Lat_1.re +
              untitled1_B.deltafalllimit;
            untitled1_B.loop_ub = untitled1_B.eb_size[0] * untitled1_B.eb_size[1]
              - 1;
            if (0 <= untitled1_B.loop_ub) {
              memcpy(&untitled1_B.tmp_data[0], &untitled1_B.comma_gga_data[0],
                     (untitled1_B.loop_ub + 1) * sizeof(int32_T));
            }

            if (untitled1_B.messaggio_m[untitled1_B.tmp_data[3]] == 'S') {
              untitled1_B.UkYk1 = -untitled1_B.UkYk1;
            }

            untitled1_B.Lat_1 = untitled1_str2double_ic
              (&untitled1_B.messaggio_m[untitled1_B.comma_gga_data[4]]);
            if ((real_T)untitled1_B.comma_gga_data[4] + 4.0 > (real_T)
                untitled1_B.comma_gga_data[5] - 1.0) {
              untitled1_B.i = 0;
              untitled1_B.b_i = 0;
            } else {
              untitled1_B.i = untitled1_B.comma_gga_data[4] + 3;
              untitled1_B.b_i = untitled1_B.comma_gga_data[5] - 1;
            }

            untitled1_B.messaggio_size_c[0] = 1;
            untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
            untitled1_B.messaggio_size_c[1] = untitled1_B.loop_ub;
            for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_B.messaggio_data[untitled1_B.b_i] =
                untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
            }

            untitled1_B.b_x = untitled1_str2double_i(untitled1_B.messaggio_data,
              untitled1_B.messaggio_size_c);
            if (untitled1_B.b_x.im == 0.0) {
              untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
            } else if (untitled1_B.b_x.re == 0.0) {
              untitled1_B.deltafalllimit = 0.0;
            } else {
              untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
            }

            untitled1_B.deltafalllimit += untitled1_B.Lat_1.re;
            if (untitled1_B.messaggio_m[untitled1_B.tmp_data[5]] == 'W') {
              untitled1_B.deltafalllimit = -untitled1_B.deltafalllimit;
            }

            if ((real_T)untitled1_B.comma_gga_data[6] + 1.0 > (real_T)
                untitled1_B.comma_gga_data[7] - 1.0) {
              untitled1_B.g = 0;
              untitled1_B.i = 0;
            } else {
              untitled1_B.g = untitled1_B.comma_gga_data[6];
              untitled1_B.i = untitled1_B.comma_gga_data[7] - 1;
            }

            untitled1_B.messaggio_size_f[0] = 1;
            untitled1_B.loop_ub = untitled1_B.i - untitled1_B.g;
            untitled1_B.messaggio_size_f[1] = untitled1_B.loop_ub;
            for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_B.messaggio_data[untitled1_B.b_i] =
                untitled1_B.messaggio_m[untitled1_B.g + untitled1_B.b_i];
            }

            untitled1_B.Lat_1 = untitled1_str2double_i
              (untitled1_B.messaggio_data, untitled1_B.messaggio_size_f);
            untitled1_B.rtb_V_re = untitled1_B.Lat_1.re;
            if ((real_T)untitled1_B.comma_gga_data[7] + 1.0 > (real_T)
                untitled1_B.comma_gga_data[8] - 1.0) {
              untitled1_B.i = 0;
              untitled1_B.b_i = 0;
            } else {
              untitled1_B.i = untitled1_B.comma_gga_data[7];
              untitled1_B.b_i = untitled1_B.comma_gga_data[8] - 1;
            }

            untitled1_B.messaggio_size_g[0] = 1;
            untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
            untitled1_B.messaggio_size_g[1] = untitled1_B.loop_ub;
            for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_B.messaggio_data[untitled1_B.b_i] =
                untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
            }

            untitled1_B.Lat_1 = untitled1_str2double_i
              (untitled1_B.messaggio_data, untitled1_B.messaggio_size_g);
            untitled1_B.rtb_heading_re = untitled1_B.Lat_1.re;
            if ((real_T)untitled1_B.comma_gga_data[9] + 1.0 > (real_T)
                untitled1_B.comma_gga_data[10] - 1.0) {
              untitled1_B.i = 0;
              untitled1_B.b_i = 0;
            } else {
              untitled1_B.i = untitled1_B.comma_gga_data[9];
              untitled1_B.b_i = untitled1_B.comma_gga_data[10] - 1;
            }

            untitled1_B.messaggio_size_g1[0] = 1;
            untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
            untitled1_B.messaggio_size_g1[1] = untitled1_B.loop_ub;
            for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_B.messaggio_data[untitled1_B.b_i] =
                untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
            }

            untitled1_B.Lat_1 = untitled1_str2double_i
              (untitled1_B.messaggio_data, untitled1_B.messaggio_size_g1);
            untitled1_B.rtb_Magnetic_declination_re = untitled1_B.Lat_1.re;
            if (untitled1_B.messaggio_m[untitled1_B.tmp_data[10]] == 'W') {
              untitled1_B.rtb_Magnetic_declination_re = -untitled1_B.Lat_1.re;
            }

            untitled1_B.rtb_fix_mode_re = untitled1_B.ComplextoRealImag[5];
            untitled1_B.rtb_n_sat_re = untitled1_B.ComplextoRealImag[6];
            untitled1_B.rtb_h_mean_sea_re = untitled1_B.ComplextoRealImag[7];
            untitled1_B.rtb_h_WGS84_re = untitled1_B.ComplextoRealImag[8];
            if ((real_T)untitled1_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)untitled1_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)untitled1_B.star_data[0] + 1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = untitled1_B.messaggio_m[status - 1];
            if ((real_T)untitled1_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)untitled1_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)untitled1_B.star_data[0] + 2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = untitled1_B.messaggio_m[status - 1];
            if ((real_T)untitled1_B.fb_data[0] + 1.0 > (real_T)
                untitled1_B.star_data[0] - 1.0) {
              untitled1_B.i = 0;
              untitled1_B.b_i = 0;
            } else {
              untitled1_B.i = untitled1_B.fb_data[0];
              untitled1_B.b_i = untitled1_B.star_data[0] - 1;
            }

            untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
            for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                 untitled1_B.b_i++) {
              untitled1_B.NMEA_gga_string_data[untitled1_B.b_i] = (uint8_T)
                untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
            }

            status = 0U;
            untitled1_B.b_i = 0;
            while (untitled1_B.b_i <= untitled1_B.loop_ub - 1) {
              status ^= untitled1_B.NMEA_gga_string_data[untitled1_B.b_i];
              untitled1_B.b_i++;
            }

            if (status != untitled1_hex2dec(ck_ric)) {
              untitled1_B.UkYk1 = untitled1_B.ComplextoRealImag[0];
              untitled1_B.deltafalllimit = untitled1_B.ComplextoRealImag[1];
              untitled1_B.rtb_V_re = untitled1_B.ComplextoRealImag[2];
              untitled1_B.rtb_Magnetic_declination_re =
                untitled1_B.ComplextoRealImag[3];
              untitled1_B.rtb_heading_re = untitled1_B.ComplextoRealImag[4];
              untitled1_B.indice_dimario = 10U;
            }
          } else {
            for (untitled1_B.b_i = 0; untitled1_B.b_i < 5; untitled1_B.b_i++) {
              untitled1_B.mess_type_d[untitled1_B.b_i] =
                (untitled1_B.mess_type[untitled1_B.b_i] == cb[untitled1_B.b_i]);
            }

            if (untitled1_ifWhileCond(untitled1_B.mess_type_d)) {
              for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++)
              {
                untitled1_B.messaggio_c[untitled1_B.b_i] =
                  (untitled1_B.messaggio_m[untitled1_B.b_i] == ',');
              }

              untitled1_eml_find_n(untitled1_B.messaggio_c,
                                   untitled1_B.comma_gga_data,
                                   untitled1_B.eb_size);
              for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++)
              {
                untitled1_B.messaggio_c[untitled1_B.b_i] =
                  (untitled1_B.messaggio_m[untitled1_B.b_i] == '*');
              }

              untitled1_eml_find_n(untitled1_B.messaggio_c,
                                   untitled1_B.star_data, untitled1_B.star_size);
              for (untitled1_B.b_i = 0; untitled1_B.b_i < 80; untitled1_B.b_i++)
              {
                untitled1_B.messaggio_c[untitled1_B.b_i] =
                  (untitled1_B.messaggio_m[untitled1_B.b_i] == '$');
              }

              untitled1_eml_find_n(untitled1_B.messaggio_c, untitled1_B.fb_data,
                                   untitled1_B.star_size);
              untitled1_B.Lat_1 = untitled1_str2double
                (&untitled1_B.messaggio_m[untitled1_B.comma_gga_data[1]]);
              if ((real_T)untitled1_B.comma_gga_data[1] + 3.0 > (real_T)
                  untitled1_B.comma_gga_data[2] - 1.0) {
                untitled1_B.i = 0;
                untitled1_B.b_i = 0;
              } else {
                untitled1_B.i = untitled1_B.comma_gga_data[1] + 2;
                untitled1_B.b_i = untitled1_B.comma_gga_data[2] - 1;
              }

              untitled1_B.messaggio_size[0] = 1;
              untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
              untitled1_B.messaggio_size[1] = untitled1_B.loop_ub;
              for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                   untitled1_B.b_i++) {
                untitled1_B.messaggio_data[untitled1_B.b_i] =
                  untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
              }

              untitled1_B.b_x = untitled1_str2double_i
                (untitled1_B.messaggio_data, untitled1_B.messaggio_size);
              if (untitled1_B.b_x.im == 0.0) {
                untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
              } else if (untitled1_B.b_x.re == 0.0) {
                untitled1_B.deltafalllimit = 0.0;
              } else {
                untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
              }

              untitled1_B.UkYk1 = untitled1_B.Lat_1.re +
                untitled1_B.deltafalllimit;
              untitled1_B.loop_ub = untitled1_B.eb_size[0] *
                untitled1_B.eb_size[1] - 1;
              if (0 <= untitled1_B.loop_ub) {
                memcpy(&untitled1_B.tmp_data[0], &untitled1_B.comma_gga_data[0],
                       (untitled1_B.loop_ub + 1) * sizeof(int32_T));
              }

              if (untitled1_B.messaggio_m[untitled1_B.tmp_data[2]] == 'S') {
                untitled1_B.UkYk1 = -untitled1_B.UkYk1;
              }

              untitled1_B.Lat_1 = untitled1_str2double_ic
                (&untitled1_B.messaggio_m[untitled1_B.comma_gga_data[3]]);
              if ((real_T)untitled1_B.comma_gga_data[3] + 4.0 > (real_T)
                  untitled1_B.comma_gga_data[4] - 1.0) {
                untitled1_B.i = 0;
                untitled1_B.b_i = 0;
              } else {
                untitled1_B.i = untitled1_B.comma_gga_data[3] + 3;
                untitled1_B.b_i = untitled1_B.comma_gga_data[4] - 1;
              }

              untitled1_B.messaggio_size_c[0] = 1;
              untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
              untitled1_B.messaggio_size_c[1] = untitled1_B.loop_ub;
              for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                   untitled1_B.b_i++) {
                untitled1_B.messaggio_data[untitled1_B.b_i] =
                  untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
              }

              untitled1_B.b_x = untitled1_str2double_i
                (untitled1_B.messaggio_data, untitled1_B.messaggio_size_c);
              if (untitled1_B.b_x.im == 0.0) {
                untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
              } else if (untitled1_B.b_x.re == 0.0) {
                untitled1_B.deltafalllimit = 0.0;
              } else {
                untitled1_B.deltafalllimit = untitled1_B.b_x.re / 60.0;
              }

              untitled1_B.deltafalllimit += untitled1_B.Lat_1.re;
              if (untitled1_B.messaggio_m[untitled1_B.tmp_data[4]] == 'W') {
                untitled1_B.deltafalllimit = -untitled1_B.deltafalllimit;
              }

              untitled1_B.Lat_1 = untitled1_str2double_ics
                (untitled1_B.messaggio_m[untitled1_B.comma_gga_data[5]]);
              untitled1_B.rtb_fix_mode_re = untitled1_B.Lat_1.re;
              if ((real_T)untitled1_B.comma_gga_data[6] + 1.0 > (real_T)
                  untitled1_B.comma_gga_data[7] - 1.0) {
                untitled1_B.i = 0;
                untitled1_B.b_i = 0;
              } else {
                untitled1_B.i = untitled1_B.comma_gga_data[6];
                untitled1_B.b_i = untitled1_B.comma_gga_data[7] - 1;
              }

              untitled1_B.messaggio_size_f[0] = 1;
              untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
              untitled1_B.messaggio_size_f[1] = untitled1_B.loop_ub;
              for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                   untitled1_B.b_i++) {
                untitled1_B.messaggio_data[untitled1_B.b_i] =
                  untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
              }

              untitled1_B.Lat_1 = untitled1_str2double_i
                (untitled1_B.messaggio_data, untitled1_B.messaggio_size_f);
              untitled1_B.rtb_n_sat_re = untitled1_B.Lat_1.re;
              if ((real_T)untitled1_B.comma_gga_data[8] + 1.0 > (real_T)
                  untitled1_B.comma_gga_data[9] - 1.0) {
                untitled1_B.i = 0;
                untitled1_B.b_i = 0;
              } else {
                untitled1_B.i = untitled1_B.comma_gga_data[8];
                untitled1_B.b_i = untitled1_B.comma_gga_data[9] - 1;
              }

              untitled1_B.messaggio_size_g[0] = 1;
              untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
              untitled1_B.messaggio_size_g[1] = untitled1_B.loop_ub;
              for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                   untitled1_B.b_i++) {
                untitled1_B.messaggio_data[untitled1_B.b_i] =
                  untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
              }

              untitled1_B.Lat_1 = untitled1_str2double_i
                (untitled1_B.messaggio_data, untitled1_B.messaggio_size_g);
              untitled1_B.rtb_h_mean_sea_re = untitled1_B.Lat_1.re;
              if ((real_T)untitled1_B.comma_gga_data[10] + 1.0 > (real_T)
                  untitled1_B.comma_gga_data[11] - 1.0) {
                untitled1_B.i = 0;
                untitled1_B.b_i = 0;
              } else {
                untitled1_B.i = untitled1_B.comma_gga_data[10];
                untitled1_B.b_i = untitled1_B.comma_gga_data[11] - 1;
              }

              untitled1_B.messaggio_size_g1[0] = 1;
              untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
              untitled1_B.messaggio_size_g1[1] = untitled1_B.loop_ub;
              for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                   untitled1_B.b_i++) {
                untitled1_B.messaggio_data[untitled1_B.b_i] =
                  untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
              }

              untitled1_B.Lat_1 = untitled1_str2double_i
                (untitled1_B.messaggio_data, untitled1_B.messaggio_size_g1);
              untitled1_B.rtb_h_WGS84_re = untitled1_B.Lat_1.re;
              untitled1_B.rtb_V_re = untitled1_B.ComplextoRealImag[2];
              untitled1_B.rtb_Magnetic_declination_re =
                untitled1_B.ComplextoRealImag[3];
              untitled1_B.rtb_heading_re = untitled1_B.ComplextoRealImag[4];
              if ((real_T)untitled1_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)untitled1_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)untitled1_B.star_data[0] + 1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = untitled1_B.messaggio_m[status - 1];
              if ((real_T)untitled1_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)untitled1_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)untitled1_B.star_data[0] + 2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = untitled1_B.messaggio_m[status - 1];
              if ((real_T)untitled1_B.fb_data[0] + 1.0 > (real_T)
                  untitled1_B.star_data[0] - 1.0) {
                untitled1_B.i = 0;
                untitled1_B.b_i = 0;
              } else {
                untitled1_B.i = untitled1_B.fb_data[0];
                untitled1_B.b_i = untitled1_B.star_data[0] - 1;
              }

              untitled1_B.loop_ub = untitled1_B.b_i - untitled1_B.i;
              for (untitled1_B.b_i = 0; untitled1_B.b_i < untitled1_B.loop_ub;
                   untitled1_B.b_i++) {
                untitled1_B.NMEA_gga_string_data[untitled1_B.b_i] = (uint8_T)
                  untitled1_B.messaggio_m[untitled1_B.i + untitled1_B.b_i];
              }

              status = 0U;
              untitled1_B.b_i = 0;
              while (untitled1_B.b_i <= untitled1_B.loop_ub - 1) {
                status ^= untitled1_B.NMEA_gga_string_data[untitled1_B.b_i];
                untitled1_B.b_i++;
              }

              if (status != untitled1_hex2dec(ck_ric)) {
                untitled1_B.UkYk1 = untitled1_B.ComplextoRealImag[0];
                untitled1_B.deltafalllimit = untitled1_B.ComplextoRealImag[1];
                untitled1_B.rtb_fix_mode_re = untitled1_B.ComplextoRealImag[5];
                untitled1_B.rtb_n_sat_re = untitled1_B.ComplextoRealImag[6];
                untitled1_B.rtb_h_mean_sea_re = untitled1_B.ComplextoRealImag[7];
                untitled1_B.rtb_h_WGS84_re = untitled1_B.ComplextoRealImag[8];
                untitled1_B.indice_dimario = 20U;
              }
            } else {
              untitled1_B.UkYk1 = untitled1_B.ComplextoRealImag[0];
              untitled1_B.deltafalllimit = untitled1_B.ComplextoRealImag[1];
              untitled1_B.rtb_V_re = untitled1_B.ComplextoRealImag[2];
              untitled1_B.rtb_Magnetic_declination_re =
                untitled1_B.ComplextoRealImag[3];
              untitled1_B.rtb_heading_re = untitled1_B.ComplextoRealImag[4];
              untitled1_B.rtb_fix_mode_re = untitled1_B.ComplextoRealImag[5];
              untitled1_B.rtb_n_sat_re = untitled1_B.ComplextoRealImag[6];
              untitled1_B.rtb_h_mean_sea_re = untitled1_B.ComplextoRealImag[7];
              untitled1_B.rtb_h_WGS84_re = untitled1_B.ComplextoRealImag[8];
            }
          }
        } else {
          untitled1_B.UkYk1 = untitled1_B.ComplextoRealImag[0];
          untitled1_B.deltafalllimit = untitled1_B.ComplextoRealImag[1];
          untitled1_B.rtb_V_re = untitled1_B.ComplextoRealImag[2];
          untitled1_B.rtb_Magnetic_declination_re =
            untitled1_B.ComplextoRealImag[3];
          untitled1_B.rtb_heading_re = untitled1_B.ComplextoRealImag[4];
          untitled1_B.rtb_fix_mode_re = untitled1_B.ComplextoRealImag[5];
          untitled1_B.rtb_n_sat_re = untitled1_B.ComplextoRealImag[6];
          untitled1_B.rtb_h_mean_sea_re = untitled1_B.ComplextoRealImag[7];
          untitled1_B.rtb_h_WGS84_re = untitled1_B.ComplextoRealImag[8];
        }

        /* End of MATLAB Function: '<S34>/MATLAB Function' */

        /* ComplexToRealImag: '<S34>/Complex to Real-Imag' */
        untitled1_B.ComplextoRealImag[0] = untitled1_B.UkYk1;
        untitled1_B.ComplextoRealImag[1] = untitled1_B.deltafalllimit;
        untitled1_B.ComplextoRealImag[2] = untitled1_B.rtb_V_re;
        untitled1_B.ComplextoRealImag[3] =
          untitled1_B.rtb_Magnetic_declination_re;
        untitled1_B.ComplextoRealImag[4] = untitled1_B.rtb_heading_re;
        untitled1_B.ComplextoRealImag[5] = untitled1_B.rtb_fix_mode_re;
        untitled1_B.ComplextoRealImag[6] = untitled1_B.rtb_n_sat_re;
        untitled1_B.ComplextoRealImag[7] = untitled1_B.rtb_h_mean_sea_re;
        untitled1_B.ComplextoRealImag[8] = untitled1_B.rtb_h_WGS84_re;

        /* End of Outputs for SubSystem: '<S32>/Subsystem' */
      } else {
        for (untitled1_B.i = 0; untitled1_B.i < 32; untitled1_B.i++) {
          untitled1_B.b_i = (int32_T)(((uint32_T)untitled1_DW.counter +
            untitled1_B.i) + 1U);
          if ((uint32_T)untitled1_B.b_i > 255U) {
            untitled1_B.b_i = 255;
          }

          untitled1_DW.message[untitled1_B.b_i - 1] =
            untitled1_B.b_dataOut[untitled1_B.i];
        }

        untitled1_B.b_i = (int32_T)(untitled1_DW.counter + 32U);
        if (untitled1_DW.counter + 32U > 255U) {
          untitled1_B.b_i = 255;
        }

        untitled1_DW.counter = (uint8_T)untitled1_B.b_i;
      }
    }

    /* End of MATLAB Function: '<S32>/Create_message' */
  }

  /* End of MATLABSystem: '<S21>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S21>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S21>/Subsystem1' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  /* Constant: '<S2>/Constant4' */
  if (untitled1_P.Constant4_Value_d > 0.0) {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant3'
     *  Logic: '<S31>/OR'
     *  RelationalOperator: '<S31>/Equal'
     *  RelationalOperator: '<S31>/Equal1'
     *  RelationalOperator: '<S31>/Equal2'
     */
    if ((untitled1_B.ComplextoRealImag[5] == untitled1_P.Constant_Value) ||
        (untitled1_B.ComplextoRealImag[5] == untitled1_P.Constant1_Value_i) ||
        (untitled1_B.ComplextoRealImag[5] == untitled1_P.Constant3_Value_b)) {
      /* Switch: '<S31>/Switch' */
      untitled1_B.Switch = untitled1_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S31>/Switch' incorporates:
       *  Constant: '<S31>/Constant2'
       */
      untitled1_B.Switch = untitled1_P.Constant2_Value_n;
    }

    /* End of Switch: '<S31>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S21>/Subsystem1' */

  /* MATLAB Function: '<S20>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   *  UnitDelay: '<S23>/Delay Input2'
   *
   * Block description for '<S23>/Delay Input2':
   *
   *  Store in Global RAM
   */
  untitled1_B.deltafalllimit = log(untitled1_DW.DelayInput2_DSTATE / (real_T)
    untitled1_B.SFunctionBuilder1);

  /* DataTypeConversion: '<S7>/Data Type Conversion4' incorporates:
   *  Sum: '<S21>/Sum'
   */
  untitled1_B.DataTypeConversion4[0] = (real32_T)untitled1_B.ComplextoRealImag[0];
  untitled1_B.DataTypeConversion4[1] = (real32_T)untitled1_B.ComplextoRealImag[1];
  untitled1_B.DataTypeConversion4[2] = (real32_T)(untitled1_B.ComplextoRealImag
    [7] - untitled1_B.Switch);

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S2>/Constant1'
   *  RelationalOperator: '<S28>/NotEqual'
   *  Switch: '<S28>/Switch'
   */
  if (untitled1_P.Constant_Value_e != untitled1_P.Constant1_Value_p) {
    untitled1_B.UkYk1 = untitled1_P.Constant1_Value_p;
  } else if (untitled1_B.T > untitled1_P.Switch_Threshold) {
    /* Switch: '<S28>/Switch' */
    untitled1_B.UkYk1 = untitled1_B.T;
  } else {
    untitled1_B.UkYk1 = untitled1_P.Constant1_Value_p;
  }

  /* End of Switch: '<S28>/Switch1' */

  /* DataTypeConversion: '<S7>/Data Type Conversion4' incorporates:
   *  MATLAB Function: '<S20>/MATLAB Function1'
   */
  untitled1_B.DataTypeConversion4[3] = (real32_T)(29.260958205912335 *
    untitled1_B.deltafalllimit * (untitled1_B.UkYk1 + 273.15) / (1.0 -
    -0.095098114169215084 * untitled1_B.deltafalllimit));

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  for (untitled1_B.i = 0; untitled1_B.i < 9; untitled1_B.i++) {
    untitled1_B.DataTypeConversion1_c[untitled1_B.i] =
      untitled1_B.ByteReversal[untitled1_B.i];
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion1' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S12>/Gain'
   *  Gain: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain *
    untitled1_B.DataTypeConversion1_c[3] * untitled1_P.Gain_Gain_o));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[3] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_p *
    untitled1_B.DataTypeConversion1_c[4] * untitled1_P.Gain_Gain_o));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[4] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S14>/Gain'
   *  Gain: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_d *
    untitled1_B.DataTypeConversion1_c[5] * untitled1_P.Gain_Gain_o));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[5] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  SignalConversion generated from: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_o *
    untitled1_B.DataTypeConversion1_c[6]));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[0] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  SignalConversion generated from: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_o *
    untitled1_B.DataTypeConversion1_c[0]));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[6] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  SignalConversion generated from: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_o *
    untitled1_B.DataTypeConversion1_c[7]));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[1] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  SignalConversion generated from: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_o *
    untitled1_B.DataTypeConversion1_c[1]));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[7] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  SignalConversion generated from: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_o *
    untitled1_B.DataTypeConversion1_c[8]));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[2] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  SignalConversion generated from: '<S7>/Gain'
   */
  untitled1_B.f = (real32_T)floor((real32_T)(untitled1_P.Gain_Gain_o *
    untitled1_B.DataTypeConversion1_c[2]));
  if (rtIsNaNF(untitled1_B.f) || rtIsInfF(untitled1_B.f)) {
    untitled1_B.f = 0.0F;
  } else {
    untitled1_B.f = (real32_T)fmod(untitled1_B.f, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  untitled1_B.DataTypeConversion_g[8] = (int16_T)(untitled1_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-untitled1_B.f : (int32_T)(int16_T)
    (uint16_T)untitled1_B.f);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.UkYk1 = floor(untitled1_B.ComplextoRealImag[4]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[0] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Gain: '<S7>/Gain2'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain2_Gain *
    untitled1_B.ComplextoRealImag[2]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[1] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant1_Value_pg[0]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[2] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant1_Value_pg[1]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[3] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant2_Value_f);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[4] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant3_Value_n);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[5] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant4_Value_k);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[6] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant5'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant5_Value_i);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[7] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant1_Value_pg[2]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[8] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Gain: '<S7>/Gain3'
   */
  untitled1_B.UkYk1 = floor((real_T)untitled1_P.Gain3_Gain *
    untitled1_B.SFunctionBuilder_o1);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  untitled1_B.DataTypeConversion1_l[9] = (uint16_T)(untitled1_B.UkYk1 < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-untitled1_B.UkYk1 : (int32_T)
    (uint16_T)untitled1_B.UkYk1);

  /* DataTypeConversion: '<S7>/Data Type Conversion6' */
  untitled1_B.UkYk1 = floor(untitled1_B.ComplextoRealImag[5]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* SignalConversion generated from: '<S7>/Byte Pack' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion6'
   */
  untitled1_B.TmpSignalConversionAtBytePackIn[0] = (uint8_T)(untitled1_B.UkYk1 <
    0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)
    (uint8_T)untitled1_B.UkYk1);
  untitled1_B.TmpSignalConversionAtBytePackIn[1] = untitled1_B.indice_dimario;

  /* DataTypeConversion: '<S7>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   */
  untitled1_B.DataTypeConversion8 = untitled1_B.SFunctionBuilder1;

  /* S-Function (any2byte_svd): '<S7>/Byte Pack' incorporates:
   *  Constant: '<S7>/Fine MSG1'
   *  Constant: '<S7>/Inizio MSG'
   */

  /* Pack: <S7>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_B.DataTypeConversion4[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_B.DataTypeConversion_g[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_B.DataTypeConversion1_l[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_B.TmpSignalConversionAtBytePackIn[0],
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
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_B.DataTypeConversion8, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&untitled1_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&untitled1_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S7>/Serial Transmit' */
  if (untitled1_DW.obj_a.Protocol != untitled1_P.SerialTransmit_Protocol) {
    untitled1_DW.obj_a.Protocol = untitled1_P.SerialTransmit_Protocol;
  }

  for (untitled1_B.i = 0; untitled1_B.i < 63; untitled1_B.i++) {
    untitled1_B.dataIn[untitled1_B.i] = untitled1_B.BytePack[untitled1_B.i];
  }

  MW_Serial_write(untitled1_DW.obj_a.port, &untitled1_B.dataIn[0], 63.0,
                  untitled1_DW.obj_a.dataSizeInBytes,
                  untitled1_DW.obj_a.sendModeEnum, untitled1_DW.obj_a.dataType,
                  untitled1_DW.obj_a.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S7>/Serial Transmit' */

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S7>/Constant'
   */
  untitled1_B.UkYk1 = untitled1_P.Constant_Value_e4 *
    untitled1_P.Constant_Value_o;
  untitled1_B.deltafalllimit = untitled1_B.UkYk1 / (untitled1_B.UkYk1 + 1.0);

  /* Gain: '<S7>/Gain1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   */
  untitled1_B.rtb_V_re = untitled1_P.Gain1_Gain_p * (real_T)
    untitled1_B.ByteUnpack_o3[1];

  /* Sum: '<S16>/Sum' incorporates:
   *  UnitDelay: '<S16>/Unit Delay'
   */
  untitled1_DW.UnitDelay_DSTATE += untitled1_B.rtb_V_re;

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  if (untitled1_DW.obj.Protocol != untitled1_P.SerialTransmit_Protocol_h) {
    untitled1_DW.obj.Protocol = untitled1_P.SerialTransmit_Protocol_h;
  }

  for (untitled1_B.i = 0; untitled1_B.i < 6; untitled1_B.i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    untitled1_B.UkYk1 = floor(untitled1_B.DataTypeConversion1_c[untitled1_B.i]);
    if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
      untitled1_B.UkYk1 = 0.0;
    } else {
      untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
    }

    untitled1_B.dataIn_p[untitled1_B.i] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ?
      (int32_T)(uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
      untitled1_B.UkYk1);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<S3>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain *
    untitled1_B.DataTypeConversion1_c[6]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[6] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<S4>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain_n *
    untitled1_B.DataTypeConversion1_c[7]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[7] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<S5>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain_h *
    untitled1_B.DataTypeConversion1_c[8]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[8] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  MATLAB Function: '<S16>/MATLAB Function'
   *  Product: '<S16>/Product1'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  untitled1_B.UkYk1 = floor(untitled1_B.deltafalllimit *
    untitled1_DW.UnitDelay_DSTATE);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[9] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Gain: '<S7>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain_p * (real_T)
    untitled1_B.ByteUnpack_o3[0]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[10] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion5'
   *  Gain: '<S8>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain_l *
    untitled1_B.ByteUnpack_o2_e[0]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[11] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion5'
   *  Gain: '<S9>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain_k *
    untitled1_B.ByteUnpack_o2_e[1]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[12] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion5'
   */
  untitled1_B.UkYk1 = floor(untitled1_B.ByteUnpack_o2_e[2]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[13] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion3'
   *  Gain: '<S7>/Gain4'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain4_Gain * (real_T)
    untitled1_B.ByteUnpack_o4[0]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[14] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion5'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S6>/Gain1'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain1_Gain_c *
    untitled1_B.ByteUnpack_o2_e[3] * untitled1_P.Gain1_Gain_m);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[15] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  untitled1_B.UkYk1 = floor(untitled1_B.DataTypeConversion1_c[8]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[16] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Constant_Value_k);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[17] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion3'
   *  Gain: '<S7>/Gain4'
   */
  untitled1_B.UkYk1 = floor(untitled1_P.Gain4_Gain * (real_T)
    untitled1_B.ByteUnpack_o4[1]);
  if (rtIsNaN(untitled1_B.UkYk1) || rtIsInf(untitled1_B.UkYk1)) {
    untitled1_B.UkYk1 = 0.0;
  } else {
    untitled1_B.UkYk1 = fmod(untitled1_B.UkYk1, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  untitled1_B.dataIn_p[18] = (uint8_T)(untitled1_B.UkYk1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-untitled1_B.UkYk1 : (int32_T)(uint8_T)
    untitled1_B.UkYk1);
  MW_Serial_write(untitled1_DW.obj.port, &untitled1_B.dataIn_p[0], 19.0,
                  untitled1_DW.obj.dataSizeInBytes,
                  untitled1_DW.obj.sendModeEnum, untitled1_DW.obj.dataType,
                  untitled1_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* Product: '<S16>/Product4' incorporates:
   *  MATLAB Function: '<S16>/MATLAB Function'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  untitled1_DW.UnitDelay_DSTATE *= 1.0 - 2.0 * untitled1_B.deltafalllimit;

  /* Sum: '<S16>/Sum1' incorporates:
   *  UnitDelay: '<S16>/Unit Delay'
   */
  untitled1_DW.UnitDelay_DSTATE += untitled1_B.rtb_V_re;

  /* Update for S-Function (Mti): '<S22>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S22>/S-Function Builder */
  Mti_Update_wrapper(&untitled1_B.SFunctionBuilder[0],
                     &untitled1_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S20>/Unit Delay' incorporates:
   *  Constant: '<S20>/Constant3'
   */
  untitled1_DW.UnitDelay_DSTATE_j = untitled1_P.Constant3_Value_o;
}

/* Model initialize function */
void untitled1_initialize(void)
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

    /* Start for S-Function (Mti): '<S22>/S-Function Builder' */

    /* S-Function Block: <S22>/S-Function Builder */
    Mti_Start_wrapper(&untitled1_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for S-Function (Mti): '<S22>/S-Function Builder' */

    /* S-Function Block: <S22>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          untitled1_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
    untitled1_DW.UnitDelay_DSTATE_j = untitled1_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S23>/Delay Input2'
     *
     * Block description for '<S23>/Delay Input2':
     *
     *  Store in Global RAM
     */
    untitled1_DW.DelayInput2_DSTATE = untitled1_P.DelayInput2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
    untitled1_DW.UnitDelay_DSTATE = untitled1_P.UnitDelay_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S20>/One_time_initialization' */
    un_One_time_initialization_Init(&untitled1_B.One_time_initialization,
      &untitled1_DW.One_time_initialization,
      &untitled1_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S20>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S20>/Execution_loop' */
    /* Start for MATLABSystem: '<S24>/I2C Read12' */
    untitled1_DW.obj_d.matlabCodegenIsDeleted = true;
    obj = &untitled1_DW.obj_d;
    untitled1_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    untitled1_DW.obj_d.isInitialized = 0;
    untitled1_DW.obj_d.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    untitled1_DW.obj_d.matlabCodegenIsDeleted = false;
    untitled1_DW.obj_d.SampleTime = untitled1_P.t_AP;
    obj = &untitled1_DW.obj_d;
    untitled1_DW.obj_d.isSetupComplete = false;
    untitled1_DW.obj_d.isInitialized = 1;
    untitled1_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(untitled1_B.i2cname, 0);
    untitled1_DW.obj_d.BusSpeed = 100000U;
    varargin_1 = untitled1_DW.obj_d.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    untitled1_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S24>/I2C Read1' */
    untitled1_DW.obj_n.matlabCodegenIsDeleted = true;
    obj = &untitled1_DW.obj_n;
    untitled1_DW.obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
    untitled1_DW.obj_n.isInitialized = 0;
    untitled1_DW.obj_n.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    untitled1_DW.obj_n.matlabCodegenIsDeleted = false;
    untitled1_DW.obj_n.SampleTime = untitled1_P.t_AP;
    obj = &untitled1_DW.obj_n;
    untitled1_DW.obj_n.isSetupComplete = false;
    untitled1_DW.obj_n.isInitialized = 1;
    untitled1_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(untitled1_B.i2cname, 0);
    untitled1_DW.obj_n.BusSpeed = 100000U;
    varargin_1 = untitled1_DW.obj_n.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    untitled1_DW.obj_n.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S24>/S-Function Builder' incorporates:
     *  Outport: '<S24>/T'
     */
    untitled1_B.SFunctionBuilder_o1 = untitled1_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S24>/S-Function Builder1' incorporates:
     *  Outport: '<S24>/p'
     */
    untitled1_B.SFunctionBuilder1 = untitled1_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S20>/Execution_loop' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Subsystem1' */
    /* SystemInitialize for Enabled SubSystem: '<S15>/Subsystem2' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out2'
     */
    untitled1_B.ByteUnpack_o2_e[0] = untitled1_P.Out2_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out3'
     */
    untitled1_B.ByteUnpack_o3[0] = untitled1_P.Out3_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out2'
     */
    untitled1_B.ByteUnpack_o2_e[1] = untitled1_P.Out2_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out3'
     */
    untitled1_B.ByteUnpack_o3[1] = untitled1_P.Out3_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out2'
     */
    untitled1_B.ByteUnpack_o2_e[2] = untitled1_P.Out2_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out3'
     */
    untitled1_B.ByteUnpack_o3[2] = untitled1_P.Out3_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out2'
     */
    untitled1_B.ByteUnpack_o2_e[3] = untitled1_P.Out2_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out3'
     */
    untitled1_B.ByteUnpack_o3[3] = untitled1_P.Out3_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S19>/Byte Unpack' incorporates:
     *  Outport: '<S19>/Out4'
     */
    untitled1_B.ByteUnpack_o4[0] = untitled1_P.Out4_Y0;
    untitled1_B.ByteUnpack_o4[1] = untitled1_P.Out4_Y0;

    /* End of SystemInitialize for SubSystem: '<S15>/Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S7>/Subsystem1' */

    /* SystemInitialize for MATLAB Function: '<S20>/MATLAB Function' */
    untitled1_DW.P_ref = 101325.0;
    untitled1_DW.rl_up = 300.0;
    untitled1_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S28>/Subsystem1' */
    /* SystemInitialize for Outport: '<S30>/T_0' incorporates:
     *  Inport: '<S30>/T'
     */
    untitled1_B.T = untitled1_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S28>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S21>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S34>/Memory' */
      untitled1_B.ComplextoRealImag[i] = untitled1_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S34>/Complex to Real-Imag' incorporates:
       *  Outport: '<S34>/Outport'
       */
      untitled1_B.ComplextoRealImag[i] = untitled1_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S34>/mario' */
    untitled1_B.indice_dimario = untitled1_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S32>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S21>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S21>/Subsystem1' */
    /* SystemInitialize for Switch: '<S31>/Switch' incorporates:
     *  Outport: '<S31>/h_to_subtract'
     */
    untitled1_B.Switch = untitled1_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S21>/Subsystem1' */

    /* Start for MATLABSystem: '<S7>/Serial Receive' */
    untitled1_DW.obj_k.matlabCodegenIsDeleted = false;
    untitled1_DW.obj_k.Protocol = untitled1_P.SerialReceive_Protocol;
    untitled1_DW.obj_k.isInitialized = 1;
    untitled1_DW.obj_k.DataTypeWidth = 1U;
    varargin_1 = 31U * untitled1_DW.obj_k.DataTypeWidth;
    if (varargin_1 > 65535U) {
      varargin_1 = 65535U;
    }

    untitled1_DW.obj_k.DataSizeInBytes = (uint16_T)varargin_1;
    MW_SCI_Open(1);
    untitled1_DW.obj_k.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/Serial Receive' */

    /* Start for MATLABSystem: '<S21>/Serial Receive1' */
    untitled1_DW.obj_b.matlabCodegenIsDeleted = false;
    untitled1_DW.obj_b.Protocol = untitled1_P.SerialReceive1_Protocol;
    untitled1_DW.obj_b.isInitialized = 1;
    untitled1_DW.obj_b.DataTypeWidth = 1U;
    if (untitled1_DW.obj_b.DataTypeWidth > 2047) {
      untitled1_DW.obj_b.DataSizeInBytes = MAX_uint16_T;
    } else {
      untitled1_DW.obj_b.DataSizeInBytes = (uint16_T)
        (untitled1_DW.obj_b.DataTypeWidth << 5);
    }

    MW_SCI_Open(0);
    untitled1_DW.obj_b.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S21>/Serial Receive1' */

    /* Start for MATLABSystem: '<S7>/Serial Transmit' */
    untitled1_DW.obj_a.matlabCodegenIsDeleted = false;
    untitled1_DW.obj_a.Protocol = untitled1_P.SerialTransmit_Protocol;
    untitled1_DW.obj_a.isInitialized = 1;
    untitled1_DW.obj_a.port = 1.0;
    untitled1_DW.obj_a.dataSizeInBytes = 1.0;
    untitled1_DW.obj_a.dataType = 0.0;
    untitled1_DW.obj_a.sendModeEnum = 0.0;
    untitled1_DW.obj_a.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(untitled1_DW.obj_a.port);
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
    untitled1_DW.obj_a.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/Serial Transmit' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    untitled1_DW.obj.matlabCodegenIsDeleted = false;
    untitled1_DW.obj.Protocol = untitled1_P.SerialTransmit_Protocol_h;
    untitled1_DW.obj.isInitialized = 1;
    untitled1_DW.obj.port = 2.0;
    untitled1_DW.obj.dataSizeInBytes = 1.0;
    untitled1_DW.obj.dataType = 0.0;
    untitled1_DW.obj.sendModeEnum = 2.0;
    untitled1_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(untitled1_DW.obj.port);
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
    untitled1_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void untitled1_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for Enabled SubSystem: '<S20>/One_time_initialization' */
  un_One_time_initialization_Term(&untitled1_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S20>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S20>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S24>/I2C Read12' */
  obj = &untitled1_DW.obj_d;
  if (!untitled1_DW.obj_d.matlabCodegenIsDeleted) {
    untitled1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_d.isInitialized == 1) &&
        untitled1_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S24>/I2C Read1' */
  obj = &untitled1_DW.obj_n;
  if (!untitled1_DW.obj_n.matlabCodegenIsDeleted) {
    untitled1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_n.isInitialized == 1) &&
        untitled1_DW.obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S20>/Execution_loop' */

  /* Terminate for MATLABSystem: '<S7>/Serial Receive' */
  if (!untitled1_DW.obj_k.matlabCodegenIsDeleted) {
    untitled1_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S21>/Serial Receive1' */
  if (!untitled1_DW.obj_b.matlabCodegenIsDeleted) {
    untitled1_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S21>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<S7>/Serial Transmit' */
  if (!untitled1_DW.obj_a.matlabCodegenIsDeleted) {
    untitled1_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
