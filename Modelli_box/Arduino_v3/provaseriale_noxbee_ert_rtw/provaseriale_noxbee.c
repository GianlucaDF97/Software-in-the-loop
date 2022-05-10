/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaseriale_noxbee.c
 *
 * Code generated for Simulink model 'provaseriale_noxbee'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:56:51 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaseriale_noxbee.h"
#include "provaseriale_noxbee_private.h"

/* Block signals (default storage) */
B_provaseriale_noxbee_T provaseriale_noxbee_B;

/* Block states (default storage) */
DW_provaseriale_noxbee_T provaseriale_noxbee_DW;

/* Real-time model */
static RT_MODEL_provaseriale_noxbee_T provaseriale_noxbee_M_;
RT_MODEL_provaseriale_noxbee_T *const provaseriale_noxbee_M =
  &provaseriale_noxbee_M_;

/* Forward declaration for local functions */
static void provaseriale_noxbee_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T provaseriale_noxbee_ifWhileCond(const boolean_T x[5]);
static void provaseriale_noxbee_eml_find_n(const boolean_T x[80], int32_T
  i_data[], int32_T i_size[2]);
static void provaseriale_noxb_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T provaseriale_noxbee_copydigits(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T provaseriale_noxbe_copyexponent(char_T s1[4], int32_T *idx,
  const char_T s[2], int32_T *k);
static void provaseriale_noxbee_readfloat(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaseriale_noxbee_str2double(const char_T s[2]);
static boolean_T provaseriale_noxbe_copydigits_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void provaseriale_noxbee_readfloat_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
  *success);
static creal_T provaseriale_noxbe_str2double_i(const char_T s_data[], const
  int32_T s_size[2]);
static boolean_T provaseriale_noxbee_isUnitImag(const char_T s[3], int32_T k);
static void provaseriale_no_readNonFinite_e(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T provaseriale_noxb_copydigits_of(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T provaseriale_nox_copyexponent_a(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void provaseriale_noxbe_readfloat_oc(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaseriale_noxb_str2double_ic(const char_T s[3]);
static void provaseriale_n_readNonFinite_eq(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T provaseriale_nox_copydigits_ofu(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T provaseriale_no_copyexponent_ao(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void provaseriale_noxb_readfloat_ocp(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T provaseriale_nox_str2double_ics(char_T s);
static real_T provaseriale_noxbee_hex2dec(const char_T s[2]);
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

/* System initialize for enable system: '<S2>/One_time_initialization' */
void pr_One_time_initialization_Init(B_One_time_initialization_pro_T *localB,
  DW_One_time_initialization_pr_T *localDW, P_One_time_initialization_pro_T
  *localP)
{
  uint32_T i2cname;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  int32_T i;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S9>/I2C Read' */
  localDW->obj_i.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_i;
  localDW->obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->obj_i.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_i;
  localDW->obj_i.isSetupComplete = false;
  localDW->obj_i.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_i.BusSpeed = 100000U;
  varargin_1 = localDW->obj_i.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read1' */
  localDW->obj_ni.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ni;
  localDW->obj_ni.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ni.isInitialized = 0;
  localDW->obj_ni.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ni.matlabCodegenIsDeleted = false;
  localDW->obj_ni.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_ni;
  localDW->obj_ni.isSetupComplete = false;
  localDW->obj_ni.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ni.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ni.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ni.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read2' */
  localDW->obj_nf.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_nf;
  localDW->obj_nf.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_nf.isInitialized = 0;
  localDW->obj_nf.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_nf.matlabCodegenIsDeleted = false;
  localDW->obj_nf.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_nf;
  localDW->obj_nf.isSetupComplete = false;
  localDW->obj_nf.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_nf.BusSpeed = 100000U;
  varargin_1 = localDW->obj_nf.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_nf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read3' */
  localDW->obj_e.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_e;
  localDW->obj_e.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_e.isInitialized = 0;
  localDW->obj_e.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_e.matlabCodegenIsDeleted = false;
  localDW->obj_e.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_e;
  localDW->obj_e.isSetupComplete = false;
  localDW->obj_e.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_e.BusSpeed = 100000U;
  varargin_1 = localDW->obj_e.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read4' */
  localDW->obj_n.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_n;
  localDW->obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_n.isInitialized = 0;
  localDW->obj_n.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_n.matlabCodegenIsDeleted = false;
  localDW->obj_n.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_n;
  localDW->obj_n.isSetupComplete = false;
  localDW->obj_n.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_n.BusSpeed = 100000U;
  varargin_1 = localDW->obj_n.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read5' */
  localDW->obj_f.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_f;
  localDW->obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_f.isInitialized = 0;
  localDW->obj_f.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_f.matlabCodegenIsDeleted = false;
  localDW->obj_f.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_f;
  localDW->obj_f.isSetupComplete = false;
  localDW->obj_f.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_f.BusSpeed = 100000U;
  varargin_1 = localDW->obj_f.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read6' */
  localDW->obj_ds.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_ds;
  localDW->obj_ds.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_ds.isInitialized = 0;
  localDW->obj_ds.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_ds.matlabCodegenIsDeleted = false;
  localDW->obj_ds.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_ds;
  localDW->obj_ds.isSetupComplete = false;
  localDW->obj_ds.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_ds.BusSpeed = 100000U;
  varargin_1 = localDW->obj_ds.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_ds.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read7' */
  localDW->obj_o.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_o;
  localDW->obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_o.isInitialized = 0;
  localDW->obj_o.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_o;
  localDW->obj_o.isSetupComplete = false;
  localDW->obj_o.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_o.BusSpeed = 100000U;
  varargin_1 = localDW->obj_o.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read8' */
  localDW->obj_d.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_d;
  localDW->obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_d.isInitialized = 0;
  localDW->obj_d.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_d.matlabCodegenIsDeleted = false;
  localDW->obj_d.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_d;
  localDW->obj_d.isSetupComplete = false;
  localDW->obj_d.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_d.BusSpeed = 100000U;
  varargin_1 = localDW->obj_d.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read9' */
  localDW->obj.matlabCodegenIsDeleted = true;
  obj = &localDW->obj;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read10' */
  localDW->obj_m.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_m;
  localDW->obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_m.isInitialized = 0;
  localDW->obj_m.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_m.matlabCodegenIsDeleted = false;
  localDW->obj_m.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_m;
  localDW->obj_m.isSetupComplete = false;
  localDW->obj_m.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_m.BusSpeed = 100000U;
  varargin_1 = localDW->obj_m.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Read11' */
  localDW->obj_b.matlabCodegenIsDeleted = true;
  obj = &localDW->obj_b;
  localDW->obj_b.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj_b.isInitialized = 0;
  localDW->obj_b.SampleTime = -1.0;
  obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj_b.matlabCodegenIsDeleted = false;
  localDW->obj_b.SampleTime = provaseriale_noxbee_P.t_AP;
  obj = &localDW->obj_b;
  localDW->obj_b.isSetupComplete = false;
  localDW->obj_b.isInitialized = 1;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj_b.BusSpeed = 100000U;
  varargin_1 = localDW->obj_b.BusSpeed;
  MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/I2C Write1' */
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

  /* Start for MATLABSystem: '<S9>/I2C Write2' */
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

  /* Start for MATLABSystem: '<S9>/I2C Write3' */
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

  /* Start for MATLABSystem: '<S9>/I2C Read12' */
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

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read' incorporates:
   *  Outport: '<S9>/dig_T1'
   */
  localB->I2CRead = localP->dig_T1_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read1' incorporates:
   *  Outport: '<S9>/dig_T2'
   */
  localB->I2CRead1 = localP->dig_T2_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read2' incorporates:
   *  Outport: '<S9>/dig_T3'
   */
  localB->I2CRead2 = localP->dig_T3_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read3' incorporates:
   *  Outport: '<S9>/dig_p1'
   */
  localB->I2CRead3 = localP->dig_p1_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read4' incorporates:
   *  Outport: '<S9>/dig_p2'
   */
  localB->I2CRead4 = localP->dig_p2_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read5' incorporates:
   *  Outport: '<S9>/dig_p3'
   */
  localB->I2CRead5 = localP->dig_p3_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read6' incorporates:
   *  Outport: '<S9>/dig_p4'
   */
  localB->I2CRead6 = localP->dig_p4_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read7' incorporates:
   *  Outport: '<S9>/dig_p5'
   */
  localB->I2CRead7 = localP->dig_p5_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read8' incorporates:
   *  Outport: '<S9>/dig_p6'
   */
  localB->I2CRead8 = localP->dig_p6_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read9' incorporates:
   *  Outport: '<S9>/dig_p7'
   */
  localB->I2CRead9 = localP->dig_p7_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read10' incorporates:
   *  Outport: '<S9>/dig_p8'
   */
  localB->I2CRead10 = localP->dig_p8_Y0;

  /* SystemInitialize for MATLABSystem: '<S9>/I2C Read11' incorporates:
   *  Outport: '<S9>/dig_p9'
   */
  localB->I2CRead11 = localP->dig_p9_Y0;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for S-Function (byte2any_svd): '<S9>/Byte Unpack' incorporates:
     *  Outport: '<S9>/pwm_max_min'
     */
    localB->ByteUnpack[i] = localP->pwm_max_min_Y0;
  }
}

/* Output and update for enable system: '<S2>/One_time_initialization' */
void provase_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_pro_T *localB, DW_One_time_initialization_pr_T
  *localDW, P_One_time_initialization_pro_T *localP)
{
  uint8_T output_raw_0[16];
  uint8_T SwappedDataBytes_0[2];
  uint8_T output_raw[2];
  uint8_T rtb_TmpSignalConversionAtI2CWri[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Enabled SubSystem: '<S2>/One_time_initialization' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S9>/I2C Write3' incorporates:
     *  ArithShift: '<S9>/Shift Arithmetic1'
     *  Constant: '<S9>/registro memoria2 '
     *  DataTypeConversion: '<S9>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S9>/Bitwise Operator1'
     */
    rtb_TmpSignalConversionAtI2CWri[0] = (uint8_T)((uint32_T)
      localP->registromemoria2_Value >> 8);
    rtb_TmpSignalConversionAtI2CWri[1] = (uint8_T)
      (localP->registromemoria2_Value & localP->BitwiseOperator1_BitMask);

    /* MATLABSystem: '<S9>/I2C Read' */
    if (localDW->obj_i.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_i.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read' */
      localB->I2CRead = 0U;
    }

    /* End of MATLABSystem: '<S9>/I2C Read' */

    /* MATLABSystem: '<S9>/I2C Read1' */
    if (localDW->obj_ni.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_ni.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read1' */
      localB->I2CRead1 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read1' */

    /* MATLABSystem: '<S9>/I2C Read2' */
    if (localDW->obj_nf.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_nf.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read2' */
      localB->I2CRead2 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read2' */

    /* MATLABSystem: '<S9>/I2C Read3' */
    if (localDW->obj_e.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_e.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read3' */
      localB->I2CRead3 = 0U;
    }

    /* End of MATLABSystem: '<S9>/I2C Read3' */

    /* MATLABSystem: '<S9>/I2C Read4' */
    if (localDW->obj_n.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_n.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read4' */
      localB->I2CRead4 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read4' */

    /* MATLABSystem: '<S9>/I2C Read5' */
    if (localDW->obj_f.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_f.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read5' */
      localB->I2CRead5 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read5' */

    /* MATLABSystem: '<S9>/I2C Read6' */
    if (localDW->obj_ds.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_ds.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read6' */
      localB->I2CRead6 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read6' */

    /* MATLABSystem: '<S9>/I2C Read7' */
    if (localDW->obj_o.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_o.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read7' */
      localB->I2CRead7 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read7' */

    /* MATLABSystem: '<S9>/I2C Read8' */
    if (localDW->obj_d.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_d.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read8' */
      localB->I2CRead8 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read8' */

    /* MATLABSystem: '<S9>/I2C Read9' */
    if (localDW->obj.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read9' */
      localB->I2CRead9 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read9' */

    /* MATLABSystem: '<S9>/I2C Read10' */
    if (localDW->obj_m.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_m.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read10' */
      localB->I2CRead10 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read10' */

    /* MATLABSystem: '<S9>/I2C Read11' */
    if (localDW->obj_b.SampleTime != provaseriale_noxbee_P.t_AP) {
      localDW->obj_b.SampleTime = provaseriale_noxbee_P.t_AP;
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
      /* MATLABSystem: '<S9>/I2C Read11' */
      localB->I2CRead11 = 0;
    }

    /* End of MATLABSystem: '<S9>/I2C Read11' */

    /* MATLABSystem: '<S9>/I2C Write1' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant4_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 244U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_nb.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S9>/I2C Write2' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    memcpy((void *)&output_raw[1], (void *)&localP->Constant1_Value, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    output_raw[0] = 245U;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(localDW->obj_p.I2CDriverObj.MW_I2C_HANDLE, 118U,
                       &SwappedDataBytes_0[0], 2U, false, false);

    /* MATLABSystem: '<S9>/I2C Write3' */
    MW_I2C_MasterWrite(localDW->obj_eu.I2CDriverObj.MW_I2C_HANDLE, 80U,
                       &rtb_TmpSignalConversionAtI2CWri[0], 2U, false, false);

    /* MATLABSystem: '<S9>/I2C Read12' */
    if (localDW->obj_l.SampleTime != localP->I2CRead12_SampleTime) {
      localDW->obj_l.SampleTime = localP->I2CRead12_SampleTime;
    }

    MW_I2C_MasterRead(localDW->obj_l.I2CDriverObj.MW_I2C_HANDLE, 80U,
                      &output_raw_0[0], 16U, false, false);
    memcpy((void *)&localB->I2CRead12[0], (void *)&output_raw_0[0], (uint32_T)
           ((size_t)16 * sizeof(uint8_T)));

    /* End of MATLABSystem: '<S9>/I2C Read12' */

    /* S-Function (byte2any_svd): '<S9>/Byte Unpack' */

    /* Unpack: <S9>/Byte Unpack */
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

  /* End of Outputs for SubSystem: '<S2>/One_time_initialization' */
}

/* Termination for enable system: '<S2>/One_time_initialization' */
void pr_One_time_initialization_Term(DW_One_time_initialization_pr_T *localDW)
{
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S9>/I2C Read' */
  obj = &localDW->obj_i;
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read1' */
  obj = &localDW->obj_ni;
  if (!localDW->obj_ni.matlabCodegenIsDeleted) {
    localDW->obj_ni.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ni.isInitialized == 1) && localDW->obj_ni.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read1' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read2' */
  obj = &localDW->obj_nf;
  if (!localDW->obj_nf.matlabCodegenIsDeleted) {
    localDW->obj_nf.matlabCodegenIsDeleted = true;
    if ((localDW->obj_nf.isInitialized == 1) && localDW->obj_nf.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read2' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read3' */
  obj = &localDW->obj_e;
  if (!localDW->obj_e.matlabCodegenIsDeleted) {
    localDW->obj_e.matlabCodegenIsDeleted = true;
    if ((localDW->obj_e.isInitialized == 1) && localDW->obj_e.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read3' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read4' */
  obj = &localDW->obj_n;
  if (!localDW->obj_n.matlabCodegenIsDeleted) {
    localDW->obj_n.matlabCodegenIsDeleted = true;
    if ((localDW->obj_n.isInitialized == 1) && localDW->obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read4' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read5' */
  obj = &localDW->obj_f;
  if (!localDW->obj_f.matlabCodegenIsDeleted) {
    localDW->obj_f.matlabCodegenIsDeleted = true;
    if ((localDW->obj_f.isInitialized == 1) && localDW->obj_f.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read5' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read6' */
  obj = &localDW->obj_ds;
  if (!localDW->obj_ds.matlabCodegenIsDeleted) {
    localDW->obj_ds.matlabCodegenIsDeleted = true;
    if ((localDW->obj_ds.isInitialized == 1) && localDW->obj_ds.isSetupComplete)
    {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read6' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read7' */
  obj = &localDW->obj_o;
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
    if ((localDW->obj_o.isInitialized == 1) && localDW->obj_o.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read7' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read8' */
  obj = &localDW->obj_d;
  if (!localDW->obj_d.matlabCodegenIsDeleted) {
    localDW->obj_d.matlabCodegenIsDeleted = true;
    if ((localDW->obj_d.isInitialized == 1) && localDW->obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read8' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read9' */
  obj = &localDW->obj;
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read9' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read10' */
  obj = &localDW->obj_m;
  if (!localDW->obj_m.matlabCodegenIsDeleted) {
    localDW->obj_m.matlabCodegenIsDeleted = true;
    if ((localDW->obj_m.isInitialized == 1) && localDW->obj_m.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read10' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read11' */
  obj = &localDW->obj_b;
  if (!localDW->obj_b.matlabCodegenIsDeleted) {
    localDW->obj_b.matlabCodegenIsDeleted = true;
    if ((localDW->obj_b.isInitialized == 1) && localDW->obj_b.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read11' */

  /* Terminate for MATLABSystem: '<S9>/I2C Write1' */
  obj_0 = &localDW->obj_nb;
  if (!localDW->obj_nb.matlabCodegenIsDeleted) {
    localDW->obj_nb.matlabCodegenIsDeleted = true;
    if ((localDW->obj_nb.isInitialized == 1) && localDW->obj_nb.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Write1' */

  /* Terminate for MATLABSystem: '<S9>/I2C Write2' */
  obj_0 = &localDW->obj_p;
  if (!localDW->obj_p.matlabCodegenIsDeleted) {
    localDW->obj_p.matlabCodegenIsDeleted = true;
    if ((localDW->obj_p.isInitialized == 1) && localDW->obj_p.isSetupComplete) {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Write2' */

  /* Terminate for MATLABSystem: '<S9>/I2C Write3' */
  obj_0 = &localDW->obj_eu;
  if (!localDW->obj_eu.matlabCodegenIsDeleted) {
    localDW->obj_eu.matlabCodegenIsDeleted = true;
    if ((localDW->obj_eu.isInitialized == 1) && localDW->obj_eu.isSetupComplete)
    {
      MW_I2C_Close(obj_0->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Write3' */

  /* Terminate for MATLABSystem: '<S9>/I2C Read12' */
  obj = &localDW->obj_l;
  if (!localDW->obj_l.matlabCodegenIsDeleted) {
    localDW->obj_l.matlabCodegenIsDeleted = true;
    if ((localDW->obj_l.isInitialized == 1) && localDW->obj_l.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Read12' */
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxbee_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_noxbee_ifWhileCond(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxbee_eml_find_n(const boolean_T x[80], int32_T
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxb_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_noxbee_copydigits(char_T s1[4], int32_T *idx,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_noxbe_copyexponent(char_T s1[4], int32_T *idx,
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

      provaseriale_noxbee_B.kexp_b = *k;
      b_k = *k;
      b_success = provaseriale_noxbee_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > provaseriale_noxbee_B.kexp_b));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxbee_readfloat(char_T s1[4], int32_T *idx, const
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
            provaseriale_noxbee_readfloat(s1, idx, s, k, false, &isneg, b_finite,
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
      provaseriale_noxb_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = provaseriale_noxbee_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = provaseriale_noxbe_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T provaseriale_noxbee_str2double(const char_T s[2])
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
  provaseriale_noxbee_B.ntoread_n = 0;
  provaseriale_noxbee_B.k_o = 0;
  while ((provaseriale_noxbee_B.k_o + 1 <= 2) && (c[(uint8_T)
          s[provaseriale_noxbee_B.k_o] & 127] || (s[provaseriale_noxbee_B.k_o] ==
           '\x00'))) {
    provaseriale_noxbee_B.k_o++;
  }

  isimag1 = false;
  b_finite = true;
  provaseriale_noxbee_B.scanned1_m = 0.0;
  provaseriale_noxbee_B.idx_b = 1;
  provaseriale_noxbee_B.s1_l[0] = '\x00';
  provaseriale_noxbee_B.s1_l[1] = '\x00';
  provaseriale_noxbee_B.s1_l[2] = '\x00';
  provaseriale_noxbee_B.s1_l[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaseriale_noxbee_B.k_o + 1 <= 2)) {
    if (s[provaseriale_noxbee_B.k_o] == '-') {
      isneg = !isneg;
      provaseriale_noxbee_B.k_o++;
    } else if ((s[provaseriale_noxbee_B.k_o] == ',') ||
               (s[provaseriale_noxbee_B.k_o] == '+') || c[(uint8_T)
               s[provaseriale_noxbee_B.k_o] & 127]) {
      provaseriale_noxbee_B.k_o++;
    } else {
      exitg1 = true;
    }
  }

  success = (provaseriale_noxbee_B.k_o + 1 <= 2);
  if (success && isneg) {
    provaseriale_noxbee_B.s1_l[0] = '-';
    provaseriale_noxbee_B.idx_b = 2;
  }

  provaseriale_noxbee_B.e_k = provaseriale_noxbee_B.k_o + 1;
  if (success) {
    if ((provaseriale_noxbee_B.k_o + 1 <= 2) && ((s[provaseriale_noxbee_B.k_o] ==
          'j') || (s[provaseriale_noxbee_B.k_o] == 'i'))) {
      isimag1 = true;
      provaseriale_noxbee_B.e_k = provaseriale_noxbee_B.k_o + 2;
      while ((provaseriale_noxbee_B.e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1]
               == '\x00') || (s[1] == ','))) {
        provaseriale_noxbee_B.e_k = 3;
      }

      if ((provaseriale_noxbee_B.e_k <= 2) && (s[1] == '*')) {
        provaseriale_noxbee_B.e_k = 3;
        provaseriale_noxbee_readfloat(provaseriale_noxbee_B.s1_l,
          &provaseriale_noxbee_B.idx_b, s, &provaseriale_noxbee_B.e_k, false,
          &isneg, &b_finite, &provaseriale_noxbee_B.scanned1_m, &unusedU2,
          &success);
      } else {
        provaseriale_noxbee_B.s1_l[provaseriale_noxbee_B.idx_b - 1] = '1';
        provaseriale_noxbee_B.idx_b++;
      }
    } else {
      provaseriale_noxbee_B.e_k = provaseriale_noxbee_B.k_o + 1;
      provaseriale_noxb_readNonFinite(s, &provaseriale_noxbee_B.e_k, &b_finite,
        &provaseriale_noxbee_B.scanned1_m);
      if (b_finite) {
        success = provaseriale_noxbee_copydigits(provaseriale_noxbee_B.s1_l,
          &provaseriale_noxbee_B.idx_b, s, &provaseriale_noxbee_B.e_k, true);
        if (success) {
          success = provaseriale_noxbe_copyexponent(provaseriale_noxbee_B.s1_l,
            &provaseriale_noxbee_B.idx_b, s, &provaseriale_noxbee_B.e_k);
        }
      } else {
        if ((provaseriale_noxbee_B.idx_b >= 2) && (provaseriale_noxbee_B.s1_l[0]
             == '-')) {
          provaseriale_noxbee_B.idx_b = 1;
          provaseriale_noxbee_B.s1_l[0] = ' ';
          provaseriale_noxbee_B.scanned1_m = -provaseriale_noxbee_B.scanned1_m;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (provaseriale_noxbee_B.e_k <= 2)) {
        tmp = s[provaseriale_noxbee_B.e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          provaseriale_noxbee_B.e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((provaseriale_noxbee_B.e_k <= 2) && (s[provaseriale_noxbee_B.e_k - 1] ==
           '*')) {
        provaseriale_noxbee_B.e_k++;
        exitg1 = false;
        while ((!exitg1) && (provaseriale_noxbee_B.e_k <= 2)) {
          tmp = s[provaseriale_noxbee_B.e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            provaseriale_noxbee_B.e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (provaseriale_noxbee_B.e_k <= 2) {
        tmp = s[provaseriale_noxbee_B.e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          provaseriale_noxbee_B.e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (provaseriale_noxbee_B.e_k <= 2)) {
      tmp = s[provaseriale_noxbee_B.e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        provaseriale_noxbee_B.e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    provaseriale_noxbee_B.ntoread_n = 1;
  }

  if (success && (provaseriale_noxbee_B.e_k <= 2)) {
    provaseriale_noxbee_B.s1_l[provaseriale_noxbee_B.idx_b - 1] = ' ';
    provaseriale_noxbee_B.idx_b++;
    provaseriale_noxbee_readfloat(provaseriale_noxbee_B.s1_l,
      &provaseriale_noxbee_B.idx_b, s, &provaseriale_noxbee_B.e_k, true,
      &success, &isneg, &provaseriale_noxbee_B.scanned2_n, &unusedU2, &c_success);
    if (isneg) {
      provaseriale_noxbee_B.ntoread_n++;
    }

    success = (c_success && (provaseriale_noxbee_B.e_k > 2) && (isimag1 !=
                success) && unusedU2);
  } else {
    provaseriale_noxbee_B.scanned2_n = 0.0;
  }

  if (success) {
    provaseriale_noxbee_B.s1_l[provaseriale_noxbee_B.idx_b - 1] = '\x00';
    switch (provaseriale_noxbee_B.ntoread_n) {
     case 2:
      provaseriale_noxbee_B.ntoread_n = sscanf(&provaseriale_noxbee_B.s1_l[0],
        "%lf %lf", &provaseriale_noxbee_B.scanned1_m,
        &provaseriale_noxbee_B.scanned2_n);
      if (provaseriale_noxbee_B.ntoread_n != 2) {
        provaseriale_noxbee_B.scanned1_m = (rtNaN);
        provaseriale_noxbee_B.scanned2_n = (rtNaN);
      }
      break;

     case 1:
      provaseriale_noxbee_B.ntoread_n = sscanf(&provaseriale_noxbee_B.s1_l[0],
        "%lf", &provaseriale_noxbee_B.b_scanned1_p);
      if (b_finite) {
        if (provaseriale_noxbee_B.ntoread_n == 1) {
          provaseriale_noxbee_B.scanned1_m = provaseriale_noxbee_B.b_scanned1_p;
        } else {
          provaseriale_noxbee_B.scanned1_m = (rtNaN);
        }
      } else if (provaseriale_noxbee_B.ntoread_n == 1) {
        provaseriale_noxbee_B.scanned2_n = provaseriale_noxbee_B.b_scanned1_p;
      } else {
        provaseriale_noxbee_B.scanned2_n = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaseriale_noxbee_B.scanned2_n;
      x.im = provaseriale_noxbee_B.scanned1_m;
    } else {
      x.re = provaseriale_noxbee_B.scanned1_m;
      x.im = provaseriale_noxbee_B.scanned2_n;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_noxbe_copydigits_o(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxbee_readfloat_o(char_T s1_data[], int32_T *idx,
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
          provaseriale_noxbee_readfloat_o(s1_data, idx, s_data, k, n, false,
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
        *success = provaseriale_noxbe_copydigits_o(s1_data, &b_idx, s_data, &h_k,
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
              isneg = provaseriale_noxbe_copydigits_o(s1_data, idx, s_data,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T provaseriale_noxbe_str2double_i(const char_T s_data[], const
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
    provaseriale_noxbee_B.ntoread = 0;
    provaseriale_noxbee_B.k = 1;
    exitg1 = false;
    while ((!exitg1) && (provaseriale_noxbee_B.k <= s_size[1])) {
      tmp = s_data[provaseriale_noxbee_B.k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        provaseriale_noxbee_B.k++;
      } else {
        exitg1 = true;
      }
    }

    provaseriale_noxbee_B.s1_size[0] = 1;
    provaseriale_noxbee_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    provaseriale_noxbee_B.idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= provaseriale_noxbee_B.idx) {
      memset(&provaseriale_noxbee_B.s1_data[0], 0, (provaseriale_noxbee_B.idx +
              1) * sizeof(char_T));
    }

    provaseriale_noxbee_B.idx = 1;
    provaseriale_noxbee_readfloat_o(provaseriale_noxbee_B.s1_data,
      &provaseriale_noxbee_B.idx, s_data, &provaseriale_noxbee_B.k, s_size[1],
      true, &isimag1, &isfinite1, &provaseriale_noxbee_B.scanned1, &unusedU0,
      &success);
    if (isfinite1) {
      provaseriale_noxbee_B.ntoread = 1;
    }

    if (success) {
      if (provaseriale_noxbee_B.k <= s_size[1]) {
        provaseriale_noxbee_B.s1_data[provaseriale_noxbee_B.idx - 1] = ' ';
        provaseriale_noxbee_B.idx++;
        provaseriale_noxbee_readfloat_o(provaseriale_noxbee_B.s1_data,
          &provaseriale_noxbee_B.idx, s_data, &provaseriale_noxbee_B.k, s_size[1],
          true, &unusedU0, &success, &provaseriale_noxbee_B.scanned2, &foundsign,
          &c_success);
        if (success) {
          provaseriale_noxbee_B.ntoread++;
        }

        success = (c_success && ((provaseriale_noxbee_B.k > s_size[1]) &&
                    ((isimag1 != unusedU0) && foundsign)));
      } else {
        provaseriale_noxbee_B.scanned2 = 0.0;
      }
    } else {
      provaseriale_noxbee_B.scanned2 = 0.0;
    }

    if (success) {
      provaseriale_noxbee_B.s1_data[provaseriale_noxbee_B.idx - 1] = '\x00';
      switch (provaseriale_noxbee_B.ntoread) {
       case 2:
        provaseriale_noxbee_B.ntoread = sscanf(&provaseriale_noxbee_B.s1_data[0],
          "%lf %lf", &provaseriale_noxbee_B.scanned1,
          &provaseriale_noxbee_B.scanned2);
        if (provaseriale_noxbee_B.ntoread != 2) {
          provaseriale_noxbee_B.scanned1 = (rtNaN);
          provaseriale_noxbee_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        provaseriale_noxbee_B.ntoread = sscanf(&provaseriale_noxbee_B.s1_data[0],
          "%lf", &provaseriale_noxbee_B.b_scanned1);
        if (isfinite1) {
          if (provaseriale_noxbee_B.ntoread == 1) {
            provaseriale_noxbee_B.scanned1 = provaseriale_noxbee_B.b_scanned1;
          } else {
            provaseriale_noxbee_B.scanned1 = (rtNaN);
          }
        } else if (provaseriale_noxbee_B.ntoread == 1) {
          provaseriale_noxbee_B.scanned2 = provaseriale_noxbee_B.b_scanned1;
        } else {
          provaseriale_noxbee_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = provaseriale_noxbee_B.scanned2;
        x.im = provaseriale_noxbee_B.scanned1;
      } else {
        x.re = provaseriale_noxbee_B.scanned1;
        x.im = provaseriale_noxbee_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_noxbee_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_no_readNonFinite_e(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_noxb_copydigits_of(char_T s1[5], int32_T *idx,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_nox_copyexponent_a(char_T s1[5], int32_T *idx,
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

      provaseriale_noxbee_B.kexp = *k;
      b_k = *k;
      b_success = provaseriale_noxb_copydigits_of(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > provaseriale_noxbee_B.kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxbe_readfloat_oc(char_T s1[5], int32_T *idx, const
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
    if (provaseriale_noxbee_isUnitImag(s, b_k)) {
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
          provaseriale_noxbe_readfloat_oc(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      provaseriale_no_readNonFinite_e(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = provaseriale_noxb_copydigits_of(s1, idx, s, k, true);
        if (*success) {
          *success = provaseriale_nox_copyexponent_a(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T provaseriale_noxb_str2double_ic(const char_T s[3])
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
  provaseriale_noxbee_B.ntoread_l = 0;
  provaseriale_noxbee_B.k_d = 1;
  exitg1 = false;
  while ((!exitg1) && (provaseriale_noxbee_B.k_d <= 3)) {
    tmp = s[provaseriale_noxbee_B.k_d - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      provaseriale_noxbee_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  provaseriale_noxbee_B.scanned1_f = 0.0;
  provaseriale_noxbee_B.idx_d = 1;
  for (provaseriale_noxbee_B.b_k = 0; provaseriale_noxbee_B.b_k < 5;
       provaseriale_noxbee_B.b_k++) {
    provaseriale_noxbee_B.s1[provaseriale_noxbee_B.b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaseriale_noxbee_B.k_d <= 3)) {
    tmp = s[provaseriale_noxbee_B.k_d - 1];
    if (tmp == '-') {
      isneg = !isneg;
      provaseriale_noxbee_B.k_d++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      provaseriale_noxbee_B.k_d++;
    } else {
      exitg1 = true;
    }
  }

  success = (provaseriale_noxbee_B.k_d <= 3);
  if (success && isneg) {
    provaseriale_noxbee_B.s1[0] = '-';
    provaseriale_noxbee_B.idx_d = 2;
  }

  provaseriale_noxbee_B.b_k = provaseriale_noxbee_B.k_d - 1;
  if (success) {
    if (provaseriale_noxbee_isUnitImag(s, provaseriale_noxbee_B.k_d)) {
      isimag1 = true;
      provaseriale_noxbee_B.b_k = provaseriale_noxbee_B.k_d;
      while ((provaseriale_noxbee_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[provaseriale_noxbee_B.b_k] & 127] ||
              (s[provaseriale_noxbee_B.b_k] == '\x00') ||
              (s[provaseriale_noxbee_B.b_k] == ','))) {
        provaseriale_noxbee_B.b_k++;
      }

      if ((provaseriale_noxbee_B.b_k + 1 <= 3) && (s[provaseriale_noxbee_B.b_k] ==
           '*')) {
        provaseriale_noxbee_B.k_d = provaseriale_noxbee_B.b_k + 2;
        provaseriale_noxbe_readfloat_oc(provaseriale_noxbee_B.s1,
          &provaseriale_noxbee_B.idx_d, s, &provaseriale_noxbee_B.k_d, false,
          &isneg, &b_finite, &provaseriale_noxbee_B.scanned1_f, &unusedU2,
          &success);
        provaseriale_noxbee_B.b_k = provaseriale_noxbee_B.k_d - 1;
      } else {
        provaseriale_noxbee_B.s1[provaseriale_noxbee_B.idx_d - 1] = '1';
        provaseriale_noxbee_B.idx_d++;
      }
    } else {
      provaseriale_no_readNonFinite_e(s, &provaseriale_noxbee_B.k_d, &b_finite,
        &provaseriale_noxbee_B.scanned1_f);
      provaseriale_noxbee_B.b_k = provaseriale_noxbee_B.k_d - 1;
      if (b_finite) {
        success = provaseriale_noxb_copydigits_of(provaseriale_noxbee_B.s1,
          &provaseriale_noxbee_B.idx_d, s, &provaseriale_noxbee_B.k_d, true);
        provaseriale_noxbee_B.b_k = provaseriale_noxbee_B.k_d - 1;
        if (success) {
          success = provaseriale_nox_copyexponent_a(provaseriale_noxbee_B.s1,
            &provaseriale_noxbee_B.idx_d, s, &provaseriale_noxbee_B.k_d);
          provaseriale_noxbee_B.b_k = provaseriale_noxbee_B.k_d - 1;
        }
      } else {
        if ((provaseriale_noxbee_B.idx_d >= 2) && (provaseriale_noxbee_B.s1[0] ==
             '-')) {
          provaseriale_noxbee_B.idx_d = 1;
          provaseriale_noxbee_B.s1[0] = ' ';
          provaseriale_noxbee_B.scanned1_f = -provaseriale_noxbee_B.scanned1_f;
        }
      }

      while ((provaseriale_noxbee_B.b_k + 1 <= 3) && (c[(uint8_T)
              s[provaseriale_noxbee_B.b_k] & 127] ||
              (s[provaseriale_noxbee_B.b_k] == '\x00') ||
              (s[provaseriale_noxbee_B.b_k] == ','))) {
        provaseriale_noxbee_B.b_k++;
      }

      if ((provaseriale_noxbee_B.b_k + 1 <= 3) && (s[provaseriale_noxbee_B.b_k] ==
           '*')) {
        provaseriale_noxbee_B.b_k++;
        while ((provaseriale_noxbee_B.b_k + 1 <= 3) && (c[(uint8_T)
                s[provaseriale_noxbee_B.b_k] & 127] ||
                (s[provaseriale_noxbee_B.b_k] == '\x00') ||
                (s[provaseriale_noxbee_B.b_k] == ','))) {
          provaseriale_noxbee_B.b_k++;
        }
      }

      if ((provaseriale_noxbee_B.b_k + 1 <= 3) && ((s[provaseriale_noxbee_B.b_k]
            == 'i') || (s[provaseriale_noxbee_B.b_k] == 'j'))) {
        provaseriale_noxbee_B.b_k++;
        isimag1 = true;
      }
    }

    while ((provaseriale_noxbee_B.b_k + 1 <= 3) && (c[(uint8_T)
            s[provaseriale_noxbee_B.b_k] & 127] || (s[provaseriale_noxbee_B.b_k]
             == '\x00') || (s[provaseriale_noxbee_B.b_k] == ','))) {
      provaseriale_noxbee_B.b_k++;
    }
  }

  if (b_finite) {
    provaseriale_noxbee_B.ntoread_l = 1;
  }

  if (success && (provaseriale_noxbee_B.b_k + 1 <= 3)) {
    provaseriale_noxbee_B.s1[provaseriale_noxbee_B.idx_d - 1] = ' ';
    provaseriale_noxbee_B.idx_d++;
    provaseriale_noxbee_B.k_d = provaseriale_noxbee_B.b_k + 1;
    provaseriale_noxbe_readfloat_oc(provaseriale_noxbee_B.s1,
      &provaseriale_noxbee_B.idx_d, s, &provaseriale_noxbee_B.k_d, true,
      &success, &isneg, &provaseriale_noxbee_B.scanned2_g, &unusedU2, &c_success);
    if (isneg) {
      provaseriale_noxbee_B.ntoread_l++;
    }

    success = (c_success && (provaseriale_noxbee_B.k_d > 3) && (isimag1 !=
                success) && unusedU2);
  } else {
    provaseriale_noxbee_B.scanned2_g = 0.0;
  }

  if (success) {
    provaseriale_noxbee_B.s1[provaseriale_noxbee_B.idx_d - 1] = '\x00';
    switch (provaseriale_noxbee_B.ntoread_l) {
     case 2:
      provaseriale_noxbee_B.ntoread_l = sscanf(&provaseriale_noxbee_B.s1[0],
        "%lf %lf", &provaseriale_noxbee_B.scanned1_f,
        &provaseriale_noxbee_B.scanned2_g);
      if (provaseriale_noxbee_B.ntoread_l != 2) {
        provaseriale_noxbee_B.scanned1_f = (rtNaN);
        provaseriale_noxbee_B.scanned2_g = (rtNaN);
      }
      break;

     case 1:
      provaseriale_noxbee_B.ntoread_l = sscanf(&provaseriale_noxbee_B.s1[0],
        "%lf", &provaseriale_noxbee_B.b_scanned1_g);
      if (b_finite) {
        if (provaseriale_noxbee_B.ntoread_l == 1) {
          provaseriale_noxbee_B.scanned1_f = provaseriale_noxbee_B.b_scanned1_g;
        } else {
          provaseriale_noxbee_B.scanned1_f = (rtNaN);
        }
      } else if (provaseriale_noxbee_B.ntoread_l == 1) {
        provaseriale_noxbee_B.scanned2_g = provaseriale_noxbee_B.b_scanned1_g;
      } else {
        provaseriale_noxbee_B.scanned2_g = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaseriale_noxbee_B.scanned2_g;
      x.im = provaseriale_noxbee_B.scanned1_f;
    } else {
      x.re = provaseriale_noxbee_B.scanned1_f;
      x.im = provaseriale_noxbee_B.scanned2_g;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_n_readNonFinite_eq(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_nox_copydigits_ofu(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static boolean_T provaseriale_no_copyexponent_ao(char_T s1[3], int32_T *idx,
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
    b_success = provaseriale_nox_copydigits_ofu(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void provaseriale_noxb_readfloat_ocp(char_T s1[3], int32_T *idx, char_T s,
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
          provaseriale_noxb_readfloat_ocp(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      provaseriale_n_readNonFinite_eq(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = provaseriale_nox_copydigits_ofu(s1, idx, s, k, true);
        if (*success) {
          *success = provaseriale_no_copyexponent_ao(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T provaseriale_nox_str2double_ics(char_T s)
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
  provaseriale_noxbee_B.ntoread_h = 0;
  provaseriale_noxbee_B.d_k = 1;
  provaseriale_noxbee_B.i_b = (uint8_T)s & 127;
  if (c[provaseriale_noxbee_B.i_b] || (s == '\x00')) {
    provaseriale_noxbee_B.d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  provaseriale_noxbee_B.scanned1_l = 0.0;
  provaseriale_noxbee_B.idx_l = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (provaseriale_noxbee_B.d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      provaseriale_noxbee_B.d_k = 2;
    } else if ((s == ',') || (s == '+') || c[provaseriale_noxbee_B.i_b]) {
      provaseriale_noxbee_B.d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (provaseriale_noxbee_B.d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    provaseriale_noxbee_B.idx_l = 2;
  }

  if (success) {
    isneg = false;
    if (provaseriale_noxbee_B.d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      provaseriale_noxbee_B.d_k++;
      s1[provaseriale_noxbee_B.idx_l - 1] = '1';
      provaseriale_noxbee_B.idx_l++;
    } else {
      provaseriale_n_readNonFinite_eq(s, &provaseriale_noxbee_B.d_k, &b_finite,
        &provaseriale_noxbee_B.scanned1_l);
      if (b_finite) {
        success = provaseriale_nox_copydigits_ofu(s1,
          &provaseriale_noxbee_B.idx_l, s, &provaseriale_noxbee_B.d_k, true);
        if (success) {
          success = provaseriale_no_copyexponent_ao(s1,
            &provaseriale_noxbee_B.idx_l, s, &provaseriale_noxbee_B.d_k);
        }
      } else {
        if ((provaseriale_noxbee_B.idx_l >= 2) && (s1[0] == '-')) {
          provaseriale_noxbee_B.idx_l = 1;
          s1[0] = ' ';
          provaseriale_noxbee_B.scanned1_l = -provaseriale_noxbee_B.scanned1_l;
        }
      }

      while ((provaseriale_noxbee_B.d_k <= 1) && (c[provaseriale_noxbee_B.i_b] ||
              ((s == '\x00') || (s == ',')))) {
        provaseriale_noxbee_B.d_k = 2;
      }

      if ((provaseriale_noxbee_B.d_k <= 1) && (s == '*')) {
        provaseriale_noxbee_B.d_k = 2;
      }

      if ((provaseriale_noxbee_B.d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        provaseriale_noxbee_B.d_k = 2;
        isimag1 = true;
      }
    }

    while ((provaseriale_noxbee_B.d_k <= 1) && (c[provaseriale_noxbee_B.i_b] ||
            ((s == '\x00') || (s == ',')))) {
      provaseriale_noxbee_B.d_k = 2;
    }
  }

  if (b_finite) {
    provaseriale_noxbee_B.ntoread_h = 1;
  }

  if (success && (provaseriale_noxbee_B.d_k <= 1)) {
    s1[provaseriale_noxbee_B.idx_l - 1] = ' ';
    provaseriale_noxbee_B.idx_l++;
    provaseriale_noxbee_B.d_k = 1;
    provaseriale_noxb_readfloat_ocp(s1, &provaseriale_noxbee_B.idx_l, s,
      &provaseriale_noxbee_B.d_k, true, &success, &isneg,
      &provaseriale_noxbee_B.scanned2_j, &foundsign, &c_success);
    if (isneg) {
      provaseriale_noxbee_B.ntoread_h++;
    }

    success = (c_success && (provaseriale_noxbee_B.d_k > 1) && (isimag1 !=
                success) && foundsign);
  } else {
    provaseriale_noxbee_B.scanned2_j = 0.0;
  }

  if (success) {
    s1[provaseriale_noxbee_B.idx_l - 1] = '\x00';
    switch (provaseriale_noxbee_B.ntoread_h) {
     case 2:
      provaseriale_noxbee_B.ntoread_h = sscanf(&s1[0], "%lf %lf",
        &provaseriale_noxbee_B.scanned1_l, &provaseriale_noxbee_B.scanned2_j);
      if (provaseriale_noxbee_B.ntoread_h != 2) {
        provaseriale_noxbee_B.scanned1_l = (rtNaN);
        provaseriale_noxbee_B.scanned2_j = (rtNaN);
      }
      break;

     case 1:
      provaseriale_noxbee_B.ntoread_h = sscanf(&s1[0], "%lf",
        &provaseriale_noxbee_B.b_scanned1_d);
      if (b_finite) {
        if (provaseriale_noxbee_B.ntoread_h == 1) {
          provaseriale_noxbee_B.scanned1_l = provaseriale_noxbee_B.b_scanned1_d;
        } else {
          provaseriale_noxbee_B.scanned1_l = (rtNaN);
        }
      } else if (provaseriale_noxbee_B.ntoread_h == 1) {
        provaseriale_noxbee_B.scanned2_j = provaseriale_noxbee_B.b_scanned1_d;
      } else {
        provaseriale_noxbee_B.scanned2_j = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = provaseriale_noxbee_B.scanned2_j;
      x.im = provaseriale_noxbee_B.scanned1_l;
    } else {
      x.re = provaseriale_noxbee_B.scanned1_l;
      x.im = provaseriale_noxbee_B.scanned2_j;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static real_T provaseriale_noxbee_hex2dec(const char_T s[2])
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

  provaseriale_noxbee_B.a = tmp_0;
  provaseriale_noxbee_B.p16 = tmp_1;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &provaseriale_noxbee_B.r3.chunks[0U], 2);
      tmp = tmp_2;
      MultiWordSub(&provaseriale_noxbee_B.r3.chunks[0U], &tmp_2.chunks[0U],
                   &provaseriale_noxbee_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &provaseriale_noxbee_B.r3.chunks[0U], 2);
      tmp = tmp_3;
      MultiWordSub(&provaseriale_noxbee_B.r3.chunks[0U], &tmp_3.chunks[0U],
                   &provaseriale_noxbee_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &provaseriale_noxbee_B.r3.chunks[0U], 2);
        tmp = tmp_4;
        MultiWordSub(&provaseriale_noxbee_B.r3.chunks[0U], &tmp_4.chunks[0U],
                     &provaseriale_noxbee_B.sk.chunks[0U], 2);
      } else {
        provaseriale_noxbee_B.sk = tmp_0;
      }
    } else {
      provaseriale_noxbee_B.sk = tmp_0;
    }

    uMultiWordMul(&provaseriale_noxbee_B.sk.chunks[0U], 2,
                  &provaseriale_noxbee_B.p16.chunks[0U], 2,
                  &provaseriale_noxbee_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&provaseriale_noxbee_B.r.chunks[0U], 4,
                         &provaseriale_noxbee_B.r3.chunks[0U], 2);
    MultiWordAdd(&provaseriale_noxbee_B.a.chunks[0U],
                 &provaseriale_noxbee_B.r3.chunks[0U], &tmp.chunks[0U], 2);
    provaseriale_noxbee_B.a = tmp;
    uMultiWord2MultiWord(&provaseriale_noxbee_B.p16.chunks[0U], 2,
                         &provaseriale_noxbee_B.r2.chunks[0U], 3);
    uMultiWordShl(&provaseriale_noxbee_B.r2.chunks[0U], 3, 4U,
                  &provaseriale_noxbee_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&provaseriale_noxbee_B.r1.chunks[0U], 3,
                         &provaseriale_noxbee_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&provaseriale_noxbee_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&provaseriale_noxbee_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&provaseriale_noxbee_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&provaseriale_noxbee_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&provaseriale_noxbee_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&provaseriale_noxbee_B.a.chunks[0U], 2, 0);
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
void provaseriale_noxbee_step(void)
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  char_T ck_ric[2];
  char_T messaggio;
  uint8_T output_raw_0[3];
  uint8_T output[2];
  uint8_T output_raw[2];
  uint8_T status;
  uint8_T status_0;
  boolean_T exitg1;

  /* S-Function (Mti): '<S4>/S-Function Builder' */
  Mti_Outputs_wrapper(&provaseriale_noxbee_B.SFunctionBuilder[0],
                      &provaseriale_noxbee_DW.SFunctionBuilder_DSTATE);

  /* MATLABSystem: '<S3>/Serial Receive1' */
  if (provaseriale_noxbee_DW.obj_b.Protocol !=
      provaseriale_noxbee_P.SerialReceive1_Protocol) {
    provaseriale_noxbee_DW.obj_b.Protocol =
      provaseriale_noxbee_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(0, provaseriale_noxbee_DW.obj_b.DataSizeInBytes,
                 &provaseriale_noxbee_B.b_dataOut[0], &status);

  /* S-Function (byte2any_svd): '<S4>/Byte Unpack' */

  /* Unpack: <S4>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&provaseriale_noxbee_B.ByteUnpack_o1[0], (uint8_T*)
             &provaseriale_noxbee_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&provaseriale_noxbee_B.ByteUnpack_o2[0], (uint8_T*)
             &provaseriale_noxbee_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&provaseriale_noxbee_B.ByteUnpack_o3, (uint8_T*)
             &provaseriale_noxbee_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S4>/Byte Reversal' */

  /* ReverseEndian: <S4>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &provaseriale_noxbee_B.ByteUnpack_o2[0];
    real32_T *y0 = &provaseriale_noxbee_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  for (provaseriale_noxbee_B.i = 0; provaseriale_noxbee_B.i < 9;
       provaseriale_noxbee_B.i++) {
    provaseriale_noxbee_B.DataTypeConversion1_k[provaseriale_noxbee_B.i] =
      provaseriale_noxbee_B.ByteReversal[provaseriale_noxbee_B.i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion10' */
  provaseriale_noxbee_B.d7 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[1]);
  if (rtIsNaN(provaseriale_noxbee_B.d7) || rtIsInf(provaseriale_noxbee_B.d7)) {
    provaseriale_noxbee_B.d7 = 0.0;
  } else {
    provaseriale_noxbee_B.d7 = fmod(provaseriale_noxbee_B.d7, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion11' */
  provaseriale_noxbee_B.d6 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[2]);
  if (rtIsNaN(provaseriale_noxbee_B.d6) || rtIsInf(provaseriale_noxbee_B.d6)) {
    provaseriale_noxbee_B.d6 = 0.0;
  } else {
    provaseriale_noxbee_B.d6 = fmod(provaseriale_noxbee_B.d6, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion12' */
  provaseriale_noxbee_B.d5 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[3]);
  if (rtIsNaN(provaseriale_noxbee_B.d5) || rtIsInf(provaseriale_noxbee_B.d5)) {
    provaseriale_noxbee_B.d5 = 0.0;
  } else {
    provaseriale_noxbee_B.d5 = fmod(provaseriale_noxbee_B.d5, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion13' */
  provaseriale_noxbee_B.d4 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[4]);
  if (rtIsNaN(provaseriale_noxbee_B.d4) || rtIsInf(provaseriale_noxbee_B.d4)) {
    provaseriale_noxbee_B.d4 = 0.0;
  } else {
    provaseriale_noxbee_B.d4 = fmod(provaseriale_noxbee_B.d4, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion14' */
  provaseriale_noxbee_B.d3 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[5]);
  if (rtIsNaN(provaseriale_noxbee_B.d3) || rtIsInf(provaseriale_noxbee_B.d3)) {
    provaseriale_noxbee_B.d3 = 0.0;
  } else {
    provaseriale_noxbee_B.d3 = fmod(provaseriale_noxbee_B.d3, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion15' */
  provaseriale_noxbee_B.d2 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[6]);
  if (rtIsNaN(provaseriale_noxbee_B.d2) || rtIsInf(provaseriale_noxbee_B.d2)) {
    provaseriale_noxbee_B.d2 = 0.0;
  } else {
    provaseriale_noxbee_B.d2 = fmod(provaseriale_noxbee_B.d2, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion16' */
  provaseriale_noxbee_B.d1 = floor(provaseriale_noxbee_B.DataTypeConversion1_k[7]);
  if (rtIsNaN(provaseriale_noxbee_B.d1) || rtIsInf(provaseriale_noxbee_B.d1)) {
    provaseriale_noxbee_B.d1 = 0.0;
  } else {
    provaseriale_noxbee_B.d1 = fmod(provaseriale_noxbee_B.d1, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion17' */
  provaseriale_noxbee_B.d = floor(provaseriale_noxbee_B.DataTypeConversion1_k[8]);
  if (rtIsNaN(provaseriale_noxbee_B.d) || rtIsInf(provaseriale_noxbee_B.d)) {
    provaseriale_noxbee_B.d = 0.0;
  } else {
    provaseriale_noxbee_B.d = fmod(provaseriale_noxbee_B.d, 256.0);
  }

  /* Outputs for Enabled SubSystem: '<S2>/One_time_initialization' */
  /* Logic: '<S2>/Logical Operator1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  provase_One_time_initialization(!provaseriale_noxbee_DW.UnitDelay_DSTATE,
    &provaseriale_noxbee_B.One_time_initialization,
    &provaseriale_noxbee_DW.One_time_initialization,
    &provaseriale_noxbee_P.One_time_initialization);

  /* End of Outputs for SubSystem: '<S2>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<S2>/Execution_loop' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* UnitDelay: '<S2>/Unit Delay' */
  if (provaseriale_noxbee_DW.UnitDelay_DSTATE) {
    /* MATLABSystem: '<S6>/I2C Read12' */
    if (provaseriale_noxbee_DW.obj_d.SampleTime != provaseriale_noxbee_P.t_AP) {
      provaseriale_noxbee_DW.obj_d.SampleTime = provaseriale_noxbee_P.t_AP;
    }

    status_0 = 250U;
    status_0 = MW_I2C_MasterWrite
      (provaseriale_noxbee_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE, 118U, &status_0,
       1U, true, false);
    if (0 == status_0) {
      MW_I2C_MasterRead(provaseriale_noxbee_DW.obj_d.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw[0], 2U, false, true);
      memcpy((void *)&output[0], (void *)&output_raw[0], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
    } else {
      output[0] = 0U;
      output[1] = 0U;
    }

    /* MATLABSystem: '<S6>/I2C Read1' */
    if (provaseriale_noxbee_DW.obj_n.SampleTime != provaseriale_noxbee_P.t_AP) {
      provaseriale_noxbee_DW.obj_n.SampleTime = provaseriale_noxbee_P.t_AP;
    }

    status_0 = 247U;
    status_0 = MW_I2C_MasterWrite
      (provaseriale_noxbee_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE, 118U, &status_0,
       1U, true, false);
    if (0 == status_0) {
      MW_I2C_MasterRead(provaseriale_noxbee_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE,
                        118U, &output_raw_0[0], 3U, false, true);
      memcpy((void *)&provaseriale_noxbee_B.output[0], (void *)&output_raw_0[0],
             (uint32_T)((size_t)3 * sizeof(uint8_T)));
    } else {
      provaseriale_noxbee_B.output[0] = 0U;
      provaseriale_noxbee_B.output[1] = 0U;
      provaseriale_noxbee_B.output[2] = 0U;
    }

    /* ArithShift: '<S6>/Shift Arithmetic4' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    provaseriale_noxbee_B.UkYk1 = floor(provaseriale_noxbee_P.Constant1_Value);
    if (rtIsNaN(provaseriale_noxbee_B.UkYk1) || rtIsInf
        (provaseriale_noxbee_B.UkYk1)) {
      provaseriale_noxbee_B.UkYk1 = 0.0;
    } else {
      provaseriale_noxbee_B.UkYk1 = fmod(provaseriale_noxbee_B.UkYk1,
        4.294967296E+9);
    }

    /* ArithShift: '<S6>/Shift Arithmetic3' incorporates:
     *  Constant: '<S6>/Constant5'
     */
    provaseriale_noxbee_B.deltafalllimit = floor
      (provaseriale_noxbee_P.Constant5_Value);
    if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
        (provaseriale_noxbee_B.deltafalllimit)) {
      provaseriale_noxbee_B.deltafalllimit = 0.0;
    } else {
      provaseriale_noxbee_B.deltafalllimit = fmod
        (provaseriale_noxbee_B.deltafalllimit, 4.294967296E+9);
    }

    /* ArithShift: '<S6>/Shift Arithmetic1' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    provaseriale_noxbee_B.rtb_Long_re = floor
      (provaseriale_noxbee_P.Constant6_Value);
    if (rtIsNaN(provaseriale_noxbee_B.rtb_Long_re) || rtIsInf
        (provaseriale_noxbee_B.rtb_Long_re)) {
      provaseriale_noxbee_B.rtb_Long_re = 0.0;
    } else {
      provaseriale_noxbee_B.rtb_Long_re = fmod(provaseriale_noxbee_B.rtb_Long_re,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S6>/Data Type  Conversion1' incorporates:
     *  ArithShift: '<S6>/Shift Arithmetic1'
     *  ArithShift: '<S6>/Shift Arithmetic3'
     *  ArithShift: '<S6>/Shift Arithmetic4'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant7'
     *  MATLABSystem: '<S6>/I2C Read1'
     *  Sum: '<S6>/Sum1'
     *  Sum: '<S6>/Sum4'
     *  Sum: '<S6>/Sum5'
     *  Sum: '<S6>/Sum6'
     */
    provaseriale_noxbee_B.DataTypeConversion1 = (int32_T)
      ((((((provaseriale_noxbee_P.Constant7_Value +
            provaseriale_noxbee_B.output[0]) << (provaseriale_noxbee_B.UkYk1 <
            0.0 ? -(int32_T)(uint32_T)-provaseriale_noxbee_B.UkYk1 : (int32_T)
            (uint32_T)provaseriale_noxbee_B.UkYk1)) +
          ((provaseriale_noxbee_P.Constant10_Value +
            provaseriale_noxbee_B.output[1]) <<
           (provaseriale_noxbee_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
            -provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint32_T)
            provaseriale_noxbee_B.deltafalllimit))) +
         provaseriale_noxbee_P.Constant11_Value) + provaseriale_noxbee_B.output
        [2]) >> (provaseriale_noxbee_B.rtb_Long_re < 0.0 ? -(int32_T)(uint32_T)
                 -provaseriale_noxbee_B.rtb_Long_re : (int32_T)(uint32_T)
                 provaseriale_noxbee_B.rtb_Long_re));

    /* ArithShift: '<S6>/Shift Arithmetic7' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    provaseriale_noxbee_B.UkYk1 = floor(provaseriale_noxbee_P.Constant2_Value);
    if (rtIsNaN(provaseriale_noxbee_B.UkYk1) || rtIsInf
        (provaseriale_noxbee_B.UkYk1)) {
      provaseriale_noxbee_B.UkYk1 = 0.0;
    } else {
      provaseriale_noxbee_B.UkYk1 = fmod(provaseriale_noxbee_B.UkYk1,
        4.294967296E+9);
    }

    /* ArithShift: '<S6>/Shift Arithmetic6' incorporates:
     *  Constant: '<S6>/Constant3'
     */
    provaseriale_noxbee_B.deltafalllimit = floor
      (provaseriale_noxbee_P.Constant3_Value);
    if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
        (provaseriale_noxbee_B.deltafalllimit)) {
      provaseriale_noxbee_B.deltafalllimit = 0.0;
    } else {
      provaseriale_noxbee_B.deltafalllimit = fmod
        (provaseriale_noxbee_B.deltafalllimit, 4.294967296E+9);
    }

    /* ArithShift: '<S6>/Shift Arithmetic2' incorporates:
     *  Constant: '<S6>/Constant4'
     */
    provaseriale_noxbee_B.rtb_Long_re = floor
      (provaseriale_noxbee_P.Constant4_Value);
    if (rtIsNaN(provaseriale_noxbee_B.rtb_Long_re) || rtIsInf
        (provaseriale_noxbee_B.rtb_Long_re)) {
      provaseriale_noxbee_B.rtb_Long_re = 0.0;
    } else {
      provaseriale_noxbee_B.rtb_Long_re = fmod(provaseriale_noxbee_B.rtb_Long_re,
        4.294967296E+9);
    }

    /* DataTypeConversion: '<S6>/Data Type  Conversion' incorporates:
     *  ArithShift: '<S6>/Shift Arithmetic2'
     *  ArithShift: '<S6>/Shift Arithmetic6'
     *  ArithShift: '<S6>/Shift Arithmetic7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant9'
     *  MATLABSystem: '<S6>/I2C Read12'
     *  Sum: '<S6>/Sum'
     *  Sum: '<S6>/Sum2'
     *  Sum: '<S6>/Sum3'
     */
    provaseriale_noxbee_B.DataTypeConversion = (int32_T)
      ((((provaseriale_noxbee_P.Constant8_Value + output[0]) <<
         (provaseriale_noxbee_B.UkYk1 < 0.0 ? -(int32_T)(uint32_T)
          -provaseriale_noxbee_B.UkYk1 : (int32_T)(uint32_T)
          provaseriale_noxbee_B.UkYk1)) +
        ((provaseriale_noxbee_P.Constant9_Value + output[1]) <<
         (provaseriale_noxbee_B.deltafalllimit < 0.0 ? -(int32_T)(uint32_T)
          -provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint32_T)
          provaseriale_noxbee_B.deltafalllimit))) >>
       (provaseriale_noxbee_B.rtb_Long_re < 0.0 ? -(int32_T)(uint32_T)
        -provaseriale_noxbee_B.rtb_Long_re : (int32_T)(uint32_T)
        provaseriale_noxbee_B.rtb_Long_re));

    /* S-Function (calc_T): '<S6>/S-Function Builder' */
    calc_T_Outputs_wrapper
      (&provaseriale_noxbee_B.One_time_initialization.I2CRead,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead1,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead2,
       &provaseriale_noxbee_B.DataTypeConversion,
       &provaseriale_noxbee_B.SFunctionBuilder_o1,
       &provaseriale_noxbee_B.SFunctionBuilder_o2);

    /* S-Function (calc_p): '<S6>/S-Function Builder1' */
    calc_p_Outputs_wrapper
      (&provaseriale_noxbee_B.One_time_initialization.I2CRead3,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead4,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead5,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead6,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead7,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead8,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead9,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead10,
       &provaseriale_noxbee_B.One_time_initialization.I2CRead11,
       &provaseriale_noxbee_B.DataTypeConversion1,
       &provaseriale_noxbee_B.SFunctionBuilder_o2,
       &provaseriale_noxbee_B.SFunctionBuilder1);
  }

  /* End of Outputs for SubSystem: '<S2>/Execution_loop' */

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  if (provaseriale_noxbee_P.Constant4_Value_d == 1.0) {
    provaseriale_noxbee_DW.P_ref = provaseriale_noxbee_B.SFunctionBuilder1;
  }

  if (provaseriale_noxbee_P.Constant2_Value_m == 1.0) {
    provaseriale_noxbee_DW.P_ref = provaseriale_noxbee_P.Constant3_Value_p;
    provaseriale_noxbee_DW.rl_up = 20.0;
    provaseriale_noxbee_DW.rl_dw = -20.0;
  }

  /* Product: '<S5>/delta rise limit' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  SampleTimeMath: '<S5>/sample time'
   *
   * About '<S5>/sample time':
   *  y = K where K = ( w * Ts )
   */
  provaseriale_noxbee_B.deltafalllimit = provaseriale_noxbee_DW.rl_up *
    provaseriale_noxbee_P.sampletime_WtEt;

  /* Sum: '<S5>/Difference Inputs1' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  UnitDelay: '<S5>/Delay Input2'
   *
   * Block description for '<S5>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S5>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaseriale_noxbee_B.UkYk1 = provaseriale_noxbee_DW.P_ref -
    provaseriale_noxbee_DW.DelayInput2_DSTATE;

  /* Switch: '<S11>/Switch2' incorporates:
   *  RelationalOperator: '<S11>/LowerRelop1'
   */
  if (!(provaseriale_noxbee_B.UkYk1 > provaseriale_noxbee_B.deltafalllimit)) {
    /* Product: '<S5>/delta fall limit' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function'
     *  SampleTimeMath: '<S5>/sample time'
     *
     * About '<S5>/sample time':
     *  y = K where K = ( w * Ts )
     */
    provaseriale_noxbee_B.deltafalllimit = provaseriale_noxbee_DW.rl_dw *
      provaseriale_noxbee_P.sampletime_WtEt;

    /* Switch: '<S11>/Switch' incorporates:
     *  RelationalOperator: '<S11>/UpperRelop'
     */
    if (!(provaseriale_noxbee_B.UkYk1 < provaseriale_noxbee_B.deltafalllimit)) {
      provaseriale_noxbee_B.deltafalllimit = provaseriale_noxbee_B.UkYk1;
    }

    /* End of Switch: '<S11>/Switch' */
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Sum: '<S5>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S5>/Delay Input2'
   *
   * Block description for '<S5>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S5>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaseriale_noxbee_DW.DelayInput2_DSTATE +=
    provaseriale_noxbee_B.deltafalllimit;

  /* Outputs for Enabled SubSystem: '<S10>/Subsystem1' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* Constant: '<S1>/Constant4' */
  if (provaseriale_noxbee_P.Constant4_Value_d > 0.0) {
    /* Inport: '<S12>/T' */
    provaseriale_noxbee_B.T = provaseriale_noxbee_B.SFunctionBuilder_o1;
  }

  /* End of Outputs for SubSystem: '<S10>/Subsystem1' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  UnitDelay: '<S5>/Delay Input2'
   *
   * Block description for '<S5>/Delay Input2':
   *
   *  Store in Global RAM
   */
  provaseriale_noxbee_B.deltafalllimit = log
    (provaseriale_noxbee_DW.DelayInput2_DSTATE / (real_T)
     provaseriale_noxbee_B.SFunctionBuilder1);

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S1>/Constant1'
   *  RelationalOperator: '<S10>/NotEqual'
   *  Switch: '<S10>/Switch'
   */
  if (provaseriale_noxbee_P.Constant_Value_e !=
      provaseriale_noxbee_P.Constant1_Value_p) {
    provaseriale_noxbee_B.UkYk1 = provaseriale_noxbee_P.Constant1_Value_p;
  } else if (provaseriale_noxbee_B.T > provaseriale_noxbee_P.Switch_Threshold) {
    /* Switch: '<S10>/Switch' */
    provaseriale_noxbee_B.UkYk1 = provaseriale_noxbee_B.T;
  } else {
    provaseriale_noxbee_B.UkYk1 = provaseriale_noxbee_P.Constant1_Value_p;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion18' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function1'
   */
  provaseriale_noxbee_B.UkYk1 = floor(29.260958205912335 *
    provaseriale_noxbee_B.deltafalllimit * (provaseriale_noxbee_B.UkYk1 + 273.15)
    / (1.0 - -0.095098114169215084 * provaseriale_noxbee_B.deltafalllimit));
  if (rtIsNaN(provaseriale_noxbee_B.UkYk1) || rtIsInf
      (provaseriale_noxbee_B.UkYk1)) {
    provaseriale_noxbee_B.UkYk1 = 0.0;
  } else {
    provaseriale_noxbee_B.UkYk1 = fmod(provaseriale_noxbee_B.UkYk1, 256.0);
  }

  /* Outputs for Enabled SubSystem: '<S3>/Subsystem2' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  /* MATLABSystem: '<S3>/Serial Receive1' */
  if (status > 0) {
    /* MATLAB Function: '<S14>/Create_message' */
    status = 0U;
    if (!provaseriale_noxbee_DW.start_found) {
      provaseriale_noxbee_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (provaseriale_noxbee_B.i - 1 < 32)) {
        if (provaseriale_noxbee_B.b_dataOut[(uint8_T)provaseriale_noxbee_B.i - 1]
            == 36) {
          provaseriale_noxbee_B.loop_ub = 32 - (uint8_T)provaseriale_noxbee_B.i;
          for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <=
               provaseriale_noxbee_B.loop_ub; provaseriale_noxbee_B.b_i++) {
            provaseriale_noxbee_DW.message[provaseriale_noxbee_B.b_i] =
              provaseriale_noxbee_B.b_dataOut[((uint8_T)provaseriale_noxbee_B.i
              + provaseriale_noxbee_B.b_i) - 1];
          }

          provaseriale_noxbee_DW.counter = (uint8_T)(33 - (uint8_T)
            provaseriale_noxbee_B.i);
          provaseriale_noxbee_DW.start_found = true;
          exitg1 = true;
        } else {
          provaseriale_noxbee_B.i++;
        }
      }
    } else {
      provaseriale_noxbee_B.b_i = 1;
      exitg1 = false;
      while ((!exitg1) && (provaseriale_noxbee_B.b_i - 1 < 32)) {
        if (provaseriale_noxbee_B.b_dataOut[(uint8_T)provaseriale_noxbee_B.b_i -
            1] == 13) {
          provaseriale_noxbee_DW.end_found = true;
          status = (uint8_T)provaseriale_noxbee_B.b_i;
          exitg1 = true;
        } else {
          provaseriale_noxbee_B.b_i++;
        }
      }

      if (provaseriale_noxbee_DW.end_found) {
        if (1 > status) {
          provaseriale_noxbee_B.loop_ub = -1;
        } else {
          provaseriale_noxbee_B.loop_ub = status - 1;
        }

        for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <=
             provaseriale_noxbee_B.loop_ub; provaseriale_noxbee_B.b_i++) {
          provaseriale_noxbee_B.i = (int32_T)(((uint32_T)
            provaseriale_noxbee_B.b_i + provaseriale_noxbee_DW.counter) + 1U);
          if ((uint32_T)provaseriale_noxbee_B.i > 255U) {
            provaseriale_noxbee_B.i = 255;
          }

          provaseriale_noxbee_DW.message[provaseriale_noxbee_B.i - 1] =
            provaseriale_noxbee_B.b_dataOut[provaseriale_noxbee_B.b_i];
        }

        memcpy(&provaseriale_noxbee_B.messaggio_c[0],
               &provaseriale_noxbee_DW.message[0], 80U * sizeof(uint8_T));
        provaseriale_noxbee_DW.end_found = false;
        provaseriale_noxbee_DW.counter = (uint8_T)(32 - status);
        if (status == 32) {
          provaseriale_noxbee_DW.start_found = false;
          memset(&provaseriale_noxbee_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          provaseriale_noxbee_DW.start_found = true;
          provaseriale_noxbee_B.loop_ub = -status;
          for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <=
               provaseriale_noxbee_B.loop_ub + 31; provaseriale_noxbee_B.b_i++)
          {
            provaseriale_noxbee_DW.message[provaseriale_noxbee_B.b_i] =
              provaseriale_noxbee_B.b_dataOut[status + provaseriale_noxbee_B.b_i];
          }

          provaseriale_noxbee_B.b_i = status + 48;
          if (0 <= provaseriale_noxbee_B.b_i - 1) {
            memset(&provaseriale_noxbee_DW.message[-status + 32], 0,
                   ((provaseriale_noxbee_B.b_i - status) + status) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S14>/Subsystem' incorporates:
         *  EnablePort: '<S16>/Enable'
         */
        /* MATLAB Function: '<S16>/MATLAB Function' */
        status = 0U;
        status_0 = 0U;
        provaseriale_noxbee_B.indice_dimario = 0U;
        for (provaseriale_noxbee_B.i = 0; provaseriale_noxbee_B.i < 80;
             provaseriale_noxbee_B.i++) {
          messaggio = (int8_T)
            provaseriale_noxbee_B.messaggio_c[provaseriale_noxbee_B.i];
          if (messaggio == '$') {
            provaseriale_noxbee_B.b_i = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              provaseriale_noxbee_B.b_i = 255;
            }

            status = (uint8_T)provaseriale_noxbee_B.b_i;
          }

          if (messaggio == ',') {
            provaseriale_noxbee_B.b_i = (int32_T)(status_0 + 1U);
            if (status_0 + 1U > 255U) {
              provaseriale_noxbee_B.b_i = 255;
            }

            status_0 = (uint8_T)provaseriale_noxbee_B.b_i;
          }

          provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.i] = messaggio;
        }

        if ((status == 1) && ((status_0 == 12) || (status_0 == 14))) {
          for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
               provaseriale_noxbee_B.b_i++) {
            provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
              (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] == '$');
          }

          provaseriale_noxbee_eml_find(provaseriale_noxbee_B.messaggio_m,
            &provaseriale_noxbee_B.eb_data, provaseriale_noxbee_B.eb_size);
          provaseriale_noxbee_B.i = provaseriale_noxbee_B.eb_data;
          for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 5;
               provaseriale_noxbee_B.b_i++) {
            messaggio =
              provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i +
              provaseriale_noxbee_B.i];
            provaseriale_noxbee_B.mess_type_g[provaseriale_noxbee_B.b_i] =
              (messaggio == bb[provaseriale_noxbee_B.b_i]);
            provaseriale_noxbee_B.mess_type[provaseriale_noxbee_B.b_i] =
              messaggio;
          }

          if (provaseriale_noxbee_ifWhileCond(provaseriale_noxbee_B.mess_type_g))
          {
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
                 provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
                (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] ==
                 ',');
            }

            provaseriale_noxbee_eml_find_n(provaseriale_noxbee_B.messaggio_m,
              provaseriale_noxbee_B.comma_gga_data,
              provaseriale_noxbee_B.eb_size);
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
                 provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
                (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] ==
                 '*');
            }

            provaseriale_noxbee_eml_find_n(provaseriale_noxbee_B.messaggio_m,
              provaseriale_noxbee_B.star_data, provaseriale_noxbee_B.star_size);
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
                 provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
                (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] ==
                 '$');
            }

            provaseriale_noxbee_eml_find_n(provaseriale_noxbee_B.messaggio_m,
              provaseriale_noxbee_B.fb_data, provaseriale_noxbee_B.star_size);
            provaseriale_noxbee_B.Lat_1 = provaseriale_noxbee_str2double
              (&provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.comma_gga_data
               [2]]);
            if ((real_T)provaseriale_noxbee_B.comma_gga_data[2] + 3.0 > (real_T)
                provaseriale_noxbee_B.comma_gga_data[3] - 1.0) {
              provaseriale_noxbee_B.loop_ub = 0;
              provaseriale_noxbee_B.b_i = 0;
            } else {
              provaseriale_noxbee_B.loop_ub =
                provaseriale_noxbee_B.comma_gga_data[2] + 2;
              provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.comma_gga_data[3]
                - 1;
            }

            provaseriale_noxbee_B.messaggio_size[0] = 1;
            provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
              provaseriale_noxbee_B.loop_ub;
            provaseriale_noxbee_B.messaggio_size[1] = provaseriale_noxbee_B.i;
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                 provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub +
                provaseriale_noxbee_B.b_i];
            }

            provaseriale_noxbee_B.b_x = provaseriale_noxbe_str2double_i
              (provaseriale_noxbee_B.messaggio_data,
               provaseriale_noxbee_B.messaggio_size);
            if (provaseriale_noxbee_B.b_x.im == 0.0) {
              provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re /
                60.0;
            } else if (provaseriale_noxbee_B.b_x.re == 0.0) {
              provaseriale_noxbee_B.rtb_Long_re = 0.0;
            } else {
              provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re /
                60.0;
            }

            provaseriale_noxbee_B.deltafalllimit =
              provaseriale_noxbee_B.Lat_1.re + provaseriale_noxbee_B.rtb_Long_re;
            provaseriale_noxbee_B.loop_ub = provaseriale_noxbee_B.eb_size[0] *
              provaseriale_noxbee_B.eb_size[1] - 1;
            if (0 <= provaseriale_noxbee_B.loop_ub) {
              memcpy(&provaseriale_noxbee_B.tmp_data[0],
                     &provaseriale_noxbee_B.comma_gga_data[0],
                     (provaseriale_noxbee_B.loop_ub + 1) * sizeof(int32_T));
            }

            if (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.tmp_data[3]]
                == 'S') {
              provaseriale_noxbee_B.deltafalllimit =
                -provaseriale_noxbee_B.deltafalllimit;
            }

            provaseriale_noxbee_B.Lat_1 = provaseriale_noxb_str2double_ic
              (&provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.comma_gga_data
               [4]]);
            if ((real_T)provaseriale_noxbee_B.comma_gga_data[4] + 4.0 > (real_T)
                provaseriale_noxbee_B.comma_gga_data[5] - 1.0) {
              provaseriale_noxbee_B.loop_ub = 0;
              provaseriale_noxbee_B.b_i = 0;
            } else {
              provaseriale_noxbee_B.loop_ub =
                provaseriale_noxbee_B.comma_gga_data[4] + 3;
              provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.comma_gga_data[5]
                - 1;
            }

            provaseriale_noxbee_B.messaggio_size_c[0] = 1;
            provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
              provaseriale_noxbee_B.loop_ub;
            provaseriale_noxbee_B.messaggio_size_c[1] = provaseriale_noxbee_B.i;
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                 provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub +
                provaseriale_noxbee_B.b_i];
            }

            provaseriale_noxbee_B.b_x = provaseriale_noxbe_str2double_i
              (provaseriale_noxbee_B.messaggio_data,
               provaseriale_noxbee_B.messaggio_size_c);
            if (provaseriale_noxbee_B.b_x.im == 0.0) {
              provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re /
                60.0;
            } else if (provaseriale_noxbee_B.b_x.re == 0.0) {
              provaseriale_noxbee_B.rtb_Long_re = 0.0;
            } else {
              provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re /
                60.0;
            }

            provaseriale_noxbee_B.rtb_Long_re += provaseriale_noxbee_B.Lat_1.re;
            if (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.tmp_data[5]]
                == 'W') {
              provaseriale_noxbee_B.rtb_Long_re =
                -provaseriale_noxbee_B.rtb_Long_re;
            }

            if ((real_T)provaseriale_noxbee_B.comma_gga_data[6] + 1.0 > (real_T)
                provaseriale_noxbee_B.comma_gga_data[7] - 1.0) {
              provaseriale_noxbee_B.loop_ub = 0;
              provaseriale_noxbee_B.b_i = 0;
            } else {
              provaseriale_noxbee_B.loop_ub =
                provaseriale_noxbee_B.comma_gga_data[6];
              provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.comma_gga_data[7]
                - 1;
            }

            provaseriale_noxbee_B.messaggio_size_b[0] = 1;
            provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
              provaseriale_noxbee_B.loop_ub;
            provaseriale_noxbee_B.messaggio_size_b[1] = provaseriale_noxbee_B.i;
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                 provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub +
                provaseriale_noxbee_B.b_i];
            }

            provaseriale_noxbee_B.Lat_1 = provaseriale_noxbe_str2double_i
              (provaseriale_noxbee_B.messaggio_data,
               provaseriale_noxbee_B.messaggio_size_b);
            provaseriale_noxbee_B.rtb_V_re = provaseriale_noxbee_B.Lat_1.re;
            if ((real_T)provaseriale_noxbee_B.comma_gga_data[7] + 1.0 > (real_T)
                provaseriale_noxbee_B.comma_gga_data[8] - 1.0) {
              provaseriale_noxbee_B.loop_ub = 0;
              provaseriale_noxbee_B.b_i = 0;
            } else {
              provaseriale_noxbee_B.loop_ub =
                provaseriale_noxbee_B.comma_gga_data[7];
              provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.comma_gga_data[8]
                - 1;
            }

            provaseriale_noxbee_B.messaggio_size_p[0] = 1;
            provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
              provaseriale_noxbee_B.loop_ub;
            provaseriale_noxbee_B.messaggio_size_p[1] = provaseriale_noxbee_B.i;
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                 provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub +
                provaseriale_noxbee_B.b_i];
            }

            provaseriale_noxbee_B.Lat_1 = provaseriale_noxbe_str2double_i
              (provaseriale_noxbee_B.messaggio_data,
               provaseriale_noxbee_B.messaggio_size_p);
            provaseriale_noxbee_B.rtb_heading_re =
              provaseriale_noxbee_B.Lat_1.re;
            if ((real_T)provaseriale_noxbee_B.comma_gga_data[9] + 1.0 > (real_T)
                provaseriale_noxbee_B.comma_gga_data[10] - 1.0) {
              provaseriale_noxbee_B.loop_ub = 0;
              provaseriale_noxbee_B.b_i = 0;
            } else {
              provaseriale_noxbee_B.loop_ub =
                provaseriale_noxbee_B.comma_gga_data[9];
              provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.comma_gga_data
                [10] - 1;
            }

            provaseriale_noxbee_B.messaggio_size_cv[0] = 1;
            provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
              provaseriale_noxbee_B.loop_ub;
            provaseriale_noxbee_B.messaggio_size_cv[1] = provaseriale_noxbee_B.i;
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                 provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub +
                provaseriale_noxbee_B.b_i];
            }

            provaseriale_noxbee_B.Lat_1 = provaseriale_noxbe_str2double_i
              (provaseriale_noxbee_B.messaggio_data,
               provaseriale_noxbee_B.messaggio_size_cv);
            provaseriale_noxbee_B.rtb_Magnetic_declination_re =
              provaseriale_noxbee_B.Lat_1.re;
            if (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.tmp_data
                [10]] == 'W') {
              provaseriale_noxbee_B.rtb_Magnetic_declination_re =
                -provaseriale_noxbee_B.Lat_1.re;
            }

            provaseriale_noxbee_B.rtb_fix_mode_re =
              provaseriale_noxbee_B.ComplextoRealImag[5];
            provaseriale_noxbee_B.rtb_n_sat_re =
              provaseriale_noxbee_B.ComplextoRealImag[6];
            provaseriale_noxbee_B.rtb_h_mean_sea_re =
              provaseriale_noxbee_B.ComplextoRealImag[7];
            provaseriale_noxbee_B.rtb_h_WGS84_re =
              provaseriale_noxbee_B.ComplextoRealImag[8];
            if ((real_T)provaseriale_noxbee_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)provaseriale_noxbee_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)provaseriale_noxbee_B.star_data[0] +
                                   1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = provaseriale_noxbee_B.messaggio[status - 1];
            if ((real_T)provaseriale_noxbee_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)provaseriale_noxbee_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)provaseriale_noxbee_B.star_data[0] +
                                   2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = provaseriale_noxbee_B.messaggio[status - 1];
            if ((real_T)provaseriale_noxbee_B.fb_data[0] + 1.0 > (real_T)
                provaseriale_noxbee_B.star_data[0] - 1.0) {
              provaseriale_noxbee_B.loop_ub = 0;
              provaseriale_noxbee_B.b_i = 0;
            } else {
              provaseriale_noxbee_B.loop_ub = provaseriale_noxbee_B.fb_data[0];
              provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.star_data[0] - 1;
            }

            provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
              provaseriale_noxbee_B.loop_ub;
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                 provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.NMEA_gga_string_data[provaseriale_noxbee_B.b_i]
                = (uint8_T)
                provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub +
                provaseriale_noxbee_B.b_i];
            }

            status = 0U;
            provaseriale_noxbee_B.b_i = 0;
            while (provaseriale_noxbee_B.b_i <= provaseriale_noxbee_B.i - 1) {
              status ^=
                provaseriale_noxbee_B.NMEA_gga_string_data[provaseriale_noxbee_B.b_i];
              provaseriale_noxbee_B.b_i++;
            }

            if (status != provaseriale_noxbee_hex2dec(ck_ric)) {
              provaseriale_noxbee_B.deltafalllimit =
                provaseriale_noxbee_B.ComplextoRealImag[0];
              provaseriale_noxbee_B.rtb_Long_re =
                provaseriale_noxbee_B.ComplextoRealImag[1];
              provaseriale_noxbee_B.rtb_V_re =
                provaseriale_noxbee_B.ComplextoRealImag[2];
              provaseriale_noxbee_B.rtb_Magnetic_declination_re =
                provaseriale_noxbee_B.ComplextoRealImag[3];
              provaseriale_noxbee_B.rtb_heading_re =
                provaseriale_noxbee_B.ComplextoRealImag[4];
              provaseriale_noxbee_B.indice_dimario = 10U;
            }
          } else {
            for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 5;
                 provaseriale_noxbee_B.b_i++) {
              provaseriale_noxbee_B.mess_type_g[provaseriale_noxbee_B.b_i] =
                (provaseriale_noxbee_B.mess_type[provaseriale_noxbee_B.b_i] ==
                 cb[provaseriale_noxbee_B.b_i]);
            }

            if (provaseriale_noxbee_ifWhileCond
                (provaseriale_noxbee_B.mess_type_g)) {
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
                   provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
                  (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] ==
                   ',');
              }

              provaseriale_noxbee_eml_find_n(provaseriale_noxbee_B.messaggio_m,
                provaseriale_noxbee_B.comma_gga_data,
                provaseriale_noxbee_B.eb_size);
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
                   provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
                  (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] ==
                   '*');
              }

              provaseriale_noxbee_eml_find_n(provaseriale_noxbee_B.messaggio_m,
                provaseriale_noxbee_B.star_data, provaseriale_noxbee_B.star_size);
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i < 80;
                   provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_m[provaseriale_noxbee_B.b_i] =
                  (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.b_i] ==
                   '$');
              }

              provaseriale_noxbee_eml_find_n(provaseriale_noxbee_B.messaggio_m,
                provaseriale_noxbee_B.fb_data, provaseriale_noxbee_B.star_size);
              provaseriale_noxbee_B.Lat_1 = provaseriale_noxbee_str2double
                (&provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.comma_gga_data
                 [1]]);
              if ((real_T)provaseriale_noxbee_B.comma_gga_data[1] + 3.0 >
                  (real_T)provaseriale_noxbee_B.comma_gga_data[2] - 1.0) {
                provaseriale_noxbee_B.loop_ub = 0;
                provaseriale_noxbee_B.b_i = 0;
              } else {
                provaseriale_noxbee_B.loop_ub =
                  provaseriale_noxbee_B.comma_gga_data[1] + 2;
                provaseriale_noxbee_B.b_i =
                  provaseriale_noxbee_B.comma_gga_data[2] - 1;
              }

              provaseriale_noxbee_B.messaggio_size[0] = 1;
              provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
                provaseriale_noxbee_B.loop_ub;
              provaseriale_noxbee_B.messaggio_size[1] = provaseriale_noxbee_B.i;
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                   provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                  provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub
                  + provaseriale_noxbee_B.b_i];
              }

              provaseriale_noxbee_B.b_x = provaseriale_noxbe_str2double_i
                (provaseriale_noxbee_B.messaggio_data,
                 provaseriale_noxbee_B.messaggio_size);
              if (provaseriale_noxbee_B.b_x.im == 0.0) {
                provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re
                  / 60.0;
              } else if (provaseriale_noxbee_B.b_x.re == 0.0) {
                provaseriale_noxbee_B.rtb_Long_re = 0.0;
              } else {
                provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re
                  / 60.0;
              }

              provaseriale_noxbee_B.deltafalllimit =
                provaseriale_noxbee_B.Lat_1.re +
                provaseriale_noxbee_B.rtb_Long_re;
              provaseriale_noxbee_B.loop_ub = provaseriale_noxbee_B.eb_size[0] *
                provaseriale_noxbee_B.eb_size[1] - 1;
              if (0 <= provaseriale_noxbee_B.loop_ub) {
                memcpy(&provaseriale_noxbee_B.tmp_data[0],
                       &provaseriale_noxbee_B.comma_gga_data[0],
                       (provaseriale_noxbee_B.loop_ub + 1) * sizeof(int32_T));
              }

              if (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.tmp_data[
                  2]] == 'S') {
                provaseriale_noxbee_B.deltafalllimit =
                  -provaseriale_noxbee_B.deltafalllimit;
              }

              provaseriale_noxbee_B.Lat_1 = provaseriale_noxb_str2double_ic
                (&provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.comma_gga_data
                 [3]]);
              if ((real_T)provaseriale_noxbee_B.comma_gga_data[3] + 4.0 >
                  (real_T)provaseriale_noxbee_B.comma_gga_data[4] - 1.0) {
                provaseriale_noxbee_B.loop_ub = 0;
                provaseriale_noxbee_B.b_i = 0;
              } else {
                provaseriale_noxbee_B.loop_ub =
                  provaseriale_noxbee_B.comma_gga_data[3] + 3;
                provaseriale_noxbee_B.b_i =
                  provaseriale_noxbee_B.comma_gga_data[4] - 1;
              }

              provaseriale_noxbee_B.messaggio_size_c[0] = 1;
              provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
                provaseriale_noxbee_B.loop_ub;
              provaseriale_noxbee_B.messaggio_size_c[1] =
                provaseriale_noxbee_B.i;
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                   provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                  provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub
                  + provaseriale_noxbee_B.b_i];
              }

              provaseriale_noxbee_B.b_x = provaseriale_noxbe_str2double_i
                (provaseriale_noxbee_B.messaggio_data,
                 provaseriale_noxbee_B.messaggio_size_c);
              if (provaseriale_noxbee_B.b_x.im == 0.0) {
                provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re
                  / 60.0;
              } else if (provaseriale_noxbee_B.b_x.re == 0.0) {
                provaseriale_noxbee_B.rtb_Long_re = 0.0;
              } else {
                provaseriale_noxbee_B.rtb_Long_re = provaseriale_noxbee_B.b_x.re
                  / 60.0;
              }

              provaseriale_noxbee_B.rtb_Long_re +=
                provaseriale_noxbee_B.Lat_1.re;
              if (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.tmp_data[
                  4]] == 'W') {
                provaseriale_noxbee_B.rtb_Long_re =
                  -provaseriale_noxbee_B.rtb_Long_re;
              }

              provaseriale_noxbee_B.Lat_1 = provaseriale_nox_str2double_ics
                (provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.comma_gga_data
                 [5]]);
              provaseriale_noxbee_B.rtb_fix_mode_re =
                provaseriale_noxbee_B.Lat_1.re;
              if ((real_T)provaseriale_noxbee_B.comma_gga_data[6] + 1.0 >
                  (real_T)provaseriale_noxbee_B.comma_gga_data[7] - 1.0) {
                provaseriale_noxbee_B.loop_ub = 0;
                provaseriale_noxbee_B.b_i = 0;
              } else {
                provaseriale_noxbee_B.loop_ub =
                  provaseriale_noxbee_B.comma_gga_data[6];
                provaseriale_noxbee_B.b_i =
                  provaseriale_noxbee_B.comma_gga_data[7] - 1;
              }

              provaseriale_noxbee_B.messaggio_size_b[0] = 1;
              provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
                provaseriale_noxbee_B.loop_ub;
              provaseriale_noxbee_B.messaggio_size_b[1] =
                provaseriale_noxbee_B.i;
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                   provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                  provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub
                  + provaseriale_noxbee_B.b_i];
              }

              provaseriale_noxbee_B.Lat_1 = provaseriale_noxbe_str2double_i
                (provaseriale_noxbee_B.messaggio_data,
                 provaseriale_noxbee_B.messaggio_size_b);
              provaseriale_noxbee_B.rtb_n_sat_re =
                provaseriale_noxbee_B.Lat_1.re;
              if ((real_T)provaseriale_noxbee_B.comma_gga_data[8] + 1.0 >
                  (real_T)provaseriale_noxbee_B.comma_gga_data[9] - 1.0) {
                provaseriale_noxbee_B.loop_ub = 0;
                provaseriale_noxbee_B.b_i = 0;
              } else {
                provaseriale_noxbee_B.loop_ub =
                  provaseriale_noxbee_B.comma_gga_data[8];
                provaseriale_noxbee_B.b_i =
                  provaseriale_noxbee_B.comma_gga_data[9] - 1;
              }

              provaseriale_noxbee_B.messaggio_size_p[0] = 1;
              provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
                provaseriale_noxbee_B.loop_ub;
              provaseriale_noxbee_B.messaggio_size_p[1] =
                provaseriale_noxbee_B.i;
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                   provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                  provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub
                  + provaseriale_noxbee_B.b_i];
              }

              provaseriale_noxbee_B.Lat_1 = provaseriale_noxbe_str2double_i
                (provaseriale_noxbee_B.messaggio_data,
                 provaseriale_noxbee_B.messaggio_size_p);
              provaseriale_noxbee_B.rtb_h_mean_sea_re =
                provaseriale_noxbee_B.Lat_1.re;
              if ((real_T)provaseriale_noxbee_B.comma_gga_data[10] + 1.0 >
                  (real_T)provaseriale_noxbee_B.comma_gga_data[11] - 1.0) {
                provaseriale_noxbee_B.loop_ub = 0;
                provaseriale_noxbee_B.b_i = 0;
              } else {
                provaseriale_noxbee_B.loop_ub =
                  provaseriale_noxbee_B.comma_gga_data[10];
                provaseriale_noxbee_B.b_i =
                  provaseriale_noxbee_B.comma_gga_data[11] - 1;
              }

              provaseriale_noxbee_B.messaggio_size_cv[0] = 1;
              provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
                provaseriale_noxbee_B.loop_ub;
              provaseriale_noxbee_B.messaggio_size_cv[1] =
                provaseriale_noxbee_B.i;
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                   provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.messaggio_data[provaseriale_noxbee_B.b_i] =
                  provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub
                  + provaseriale_noxbee_B.b_i];
              }

              provaseriale_noxbee_B.Lat_1 = provaseriale_noxbe_str2double_i
                (provaseriale_noxbee_B.messaggio_data,
                 provaseriale_noxbee_B.messaggio_size_cv);
              provaseriale_noxbee_B.rtb_h_WGS84_re =
                provaseriale_noxbee_B.Lat_1.re;
              provaseriale_noxbee_B.rtb_V_re =
                provaseriale_noxbee_B.ComplextoRealImag[2];
              provaseriale_noxbee_B.rtb_Magnetic_declination_re =
                provaseriale_noxbee_B.ComplextoRealImag[3];
              provaseriale_noxbee_B.rtb_heading_re =
                provaseriale_noxbee_B.ComplextoRealImag[4];
              if ((real_T)provaseriale_noxbee_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)provaseriale_noxbee_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)provaseriale_noxbee_B.star_data[0]
                                     + 1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = provaseriale_noxbee_B.messaggio[status - 1];
              if ((real_T)provaseriale_noxbee_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)provaseriale_noxbee_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)provaseriale_noxbee_B.star_data[0]
                                     + 2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = provaseriale_noxbee_B.messaggio[status - 1];
              if ((real_T)provaseriale_noxbee_B.fb_data[0] + 1.0 > (real_T)
                  provaseriale_noxbee_B.star_data[0] - 1.0) {
                provaseriale_noxbee_B.loop_ub = 0;
                provaseriale_noxbee_B.b_i = 0;
              } else {
                provaseriale_noxbee_B.loop_ub = provaseriale_noxbee_B.fb_data[0];
                provaseriale_noxbee_B.b_i = provaseriale_noxbee_B.star_data[0] -
                  1;
              }

              provaseriale_noxbee_B.i = provaseriale_noxbee_B.b_i -
                provaseriale_noxbee_B.loop_ub;
              for (provaseriale_noxbee_B.b_i = 0; provaseriale_noxbee_B.b_i <
                   provaseriale_noxbee_B.i; provaseriale_noxbee_B.b_i++) {
                provaseriale_noxbee_B.NMEA_gga_string_data[provaseriale_noxbee_B.b_i]
                  = (uint8_T)
                  provaseriale_noxbee_B.messaggio[provaseriale_noxbee_B.loop_ub
                  + provaseriale_noxbee_B.b_i];
              }

              status = 0U;
              provaseriale_noxbee_B.b_i = 0;
              while (provaseriale_noxbee_B.b_i <= provaseriale_noxbee_B.i - 1) {
                status ^=
                  provaseriale_noxbee_B.NMEA_gga_string_data[provaseriale_noxbee_B.b_i];
                provaseriale_noxbee_B.b_i++;
              }

              if (status != provaseriale_noxbee_hex2dec(ck_ric)) {
                provaseriale_noxbee_B.deltafalllimit =
                  provaseriale_noxbee_B.ComplextoRealImag[0];
                provaseriale_noxbee_B.rtb_Long_re =
                  provaseriale_noxbee_B.ComplextoRealImag[1];
                provaseriale_noxbee_B.rtb_fix_mode_re =
                  provaseriale_noxbee_B.ComplextoRealImag[5];
                provaseriale_noxbee_B.rtb_n_sat_re =
                  provaseriale_noxbee_B.ComplextoRealImag[6];
                provaseriale_noxbee_B.rtb_h_mean_sea_re =
                  provaseriale_noxbee_B.ComplextoRealImag[7];
                provaseriale_noxbee_B.rtb_h_WGS84_re =
                  provaseriale_noxbee_B.ComplextoRealImag[8];
                provaseriale_noxbee_B.indice_dimario = 20U;
              }
            } else {
              provaseriale_noxbee_B.deltafalllimit =
                provaseriale_noxbee_B.ComplextoRealImag[0];
              provaseriale_noxbee_B.rtb_Long_re =
                provaseriale_noxbee_B.ComplextoRealImag[1];
              provaseriale_noxbee_B.rtb_V_re =
                provaseriale_noxbee_B.ComplextoRealImag[2];
              provaseriale_noxbee_B.rtb_Magnetic_declination_re =
                provaseriale_noxbee_B.ComplextoRealImag[3];
              provaseriale_noxbee_B.rtb_heading_re =
                provaseriale_noxbee_B.ComplextoRealImag[4];
              provaseriale_noxbee_B.rtb_fix_mode_re =
                provaseriale_noxbee_B.ComplextoRealImag[5];
              provaseriale_noxbee_B.rtb_n_sat_re =
                provaseriale_noxbee_B.ComplextoRealImag[6];
              provaseriale_noxbee_B.rtb_h_mean_sea_re =
                provaseriale_noxbee_B.ComplextoRealImag[7];
              provaseriale_noxbee_B.rtb_h_WGS84_re =
                provaseriale_noxbee_B.ComplextoRealImag[8];
            }
          }
        } else {
          provaseriale_noxbee_B.deltafalllimit =
            provaseriale_noxbee_B.ComplextoRealImag[0];
          provaseriale_noxbee_B.rtb_Long_re =
            provaseriale_noxbee_B.ComplextoRealImag[1];
          provaseriale_noxbee_B.rtb_V_re =
            provaseriale_noxbee_B.ComplextoRealImag[2];
          provaseriale_noxbee_B.rtb_Magnetic_declination_re =
            provaseriale_noxbee_B.ComplextoRealImag[3];
          provaseriale_noxbee_B.rtb_heading_re =
            provaseriale_noxbee_B.ComplextoRealImag[4];
          provaseriale_noxbee_B.rtb_fix_mode_re =
            provaseriale_noxbee_B.ComplextoRealImag[5];
          provaseriale_noxbee_B.rtb_n_sat_re =
            provaseriale_noxbee_B.ComplextoRealImag[6];
          provaseriale_noxbee_B.rtb_h_mean_sea_re =
            provaseriale_noxbee_B.ComplextoRealImag[7];
          provaseriale_noxbee_B.rtb_h_WGS84_re =
            provaseriale_noxbee_B.ComplextoRealImag[8];
        }

        /* End of MATLAB Function: '<S16>/MATLAB Function' */

        /* ComplexToRealImag: '<S16>/Complex to Real-Imag' */
        provaseriale_noxbee_B.ComplextoRealImag[0] =
          provaseriale_noxbee_B.deltafalllimit;
        provaseriale_noxbee_B.ComplextoRealImag[1] =
          provaseriale_noxbee_B.rtb_Long_re;
        provaseriale_noxbee_B.ComplextoRealImag[2] =
          provaseriale_noxbee_B.rtb_V_re;
        provaseriale_noxbee_B.ComplextoRealImag[3] =
          provaseriale_noxbee_B.rtb_Magnetic_declination_re;
        provaseriale_noxbee_B.ComplextoRealImag[4] =
          provaseriale_noxbee_B.rtb_heading_re;
        provaseriale_noxbee_B.ComplextoRealImag[5] =
          provaseriale_noxbee_B.rtb_fix_mode_re;
        provaseriale_noxbee_B.ComplextoRealImag[6] =
          provaseriale_noxbee_B.rtb_n_sat_re;
        provaseriale_noxbee_B.ComplextoRealImag[7] =
          provaseriale_noxbee_B.rtb_h_mean_sea_re;
        provaseriale_noxbee_B.ComplextoRealImag[8] =
          provaseriale_noxbee_B.rtb_h_WGS84_re;

        /* End of Outputs for SubSystem: '<S14>/Subsystem' */
      } else {
        for (provaseriale_noxbee_B.i = 0; provaseriale_noxbee_B.i < 32;
             provaseriale_noxbee_B.i++) {
          provaseriale_noxbee_B.b_i = (int32_T)(((uint32_T)
            provaseriale_noxbee_DW.counter + provaseriale_noxbee_B.i) + 1U);
          if ((uint32_T)provaseriale_noxbee_B.b_i > 255U) {
            provaseriale_noxbee_B.b_i = 255;
          }

          provaseriale_noxbee_DW.message[provaseriale_noxbee_B.b_i - 1] =
            provaseriale_noxbee_B.b_dataOut[provaseriale_noxbee_B.i];
        }

        provaseriale_noxbee_B.b_i = (int32_T)(provaseriale_noxbee_DW.counter +
          32U);
        if (provaseriale_noxbee_DW.counter + 32U > 255U) {
          provaseriale_noxbee_B.b_i = 255;
        }

        provaseriale_noxbee_DW.counter = (uint8_T)provaseriale_noxbee_B.b_i;
      }
    }

    /* End of MATLAB Function: '<S14>/Create_message' */
  }

  /* End of Outputs for SubSystem: '<S3>/Subsystem2' */

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  provaseriale_noxbee_B.deltafalllimit = floor
    (provaseriale_noxbee_B.ComplextoRealImag[0]);
  if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
      (provaseriale_noxbee_B.deltafalllimit)) {
    provaseriale_noxbee_B.deltafalllimit = 0.0;
  } else {
    provaseriale_noxbee_B.deltafalllimit = fmod
      (provaseriale_noxbee_B.deltafalllimit, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion20' */
  provaseriale_noxbee_B.f = (real32_T)floor
    (provaseriale_noxbee_B.SFunctionBuilder_o1);
  if (rtIsNaNF(provaseriale_noxbee_B.f) || rtIsInfF(provaseriale_noxbee_B.f)) {
    provaseriale_noxbee_B.f = 0.0F;
  } else {
    provaseriale_noxbee_B.f = (real32_T)fmod(provaseriale_noxbee_B.f, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  provaseriale_noxbee_B.rtb_Long_re = floor
    (provaseriale_noxbee_B.ComplextoRealImag[1]);
  if (rtIsNaN(provaseriale_noxbee_B.rtb_Long_re) || rtIsInf
      (provaseriale_noxbee_B.rtb_Long_re)) {
    provaseriale_noxbee_B.rtb_Long_re = 0.0;
  } else {
    provaseriale_noxbee_B.rtb_Long_re = fmod(provaseriale_noxbee_B.rtb_Long_re,
      256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion4' */
  provaseriale_noxbee_B.rtb_V_re = floor
    (provaseriale_noxbee_B.ComplextoRealImag[2]);
  if (rtIsNaN(provaseriale_noxbee_B.rtb_V_re) || rtIsInf
      (provaseriale_noxbee_B.rtb_V_re)) {
    provaseriale_noxbee_B.rtb_V_re = 0.0;
  } else {
    provaseriale_noxbee_B.rtb_V_re = fmod(provaseriale_noxbee_B.rtb_V_re, 256.0);
  }

  /* Outputs for Enabled SubSystem: '<S3>/Subsystem1' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  /* Constant: '<S1>/Constant4' */
  if (provaseriale_noxbee_P.Constant4_Value_d > 0.0) {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant3'
     *  Logic: '<S13>/OR'
     *  RelationalOperator: '<S13>/Equal'
     *  RelationalOperator: '<S13>/Equal1'
     *  RelationalOperator: '<S13>/Equal2'
     */
    if ((provaseriale_noxbee_B.ComplextoRealImag[5] ==
         provaseriale_noxbee_P.Constant_Value) ||
        (provaseriale_noxbee_B.ComplextoRealImag[5] ==
         provaseriale_noxbee_P.Constant1_Value_i) ||
        (provaseriale_noxbee_B.ComplextoRealImag[5] ==
         provaseriale_noxbee_P.Constant3_Value_b)) {
      /* Switch: '<S13>/Switch' */
      provaseriale_noxbee_B.Switch = provaseriale_noxbee_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant2'
       */
      provaseriale_noxbee_B.Switch = provaseriale_noxbee_P.Constant2_Value_n;
    }

    /* End of Switch: '<S13>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S3>/Subsystem1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Sum: '<S3>/Sum'
   */
  provaseriale_noxbee_B.rtb_Magnetic_declination_re = floor
    (provaseriale_noxbee_B.ComplextoRealImag[7] - provaseriale_noxbee_B.Switch);
  if (rtIsNaN(provaseriale_noxbee_B.rtb_Magnetic_declination_re) || rtIsInf
      (provaseriale_noxbee_B.rtb_Magnetic_declination_re)) {
    provaseriale_noxbee_B.rtb_Magnetic_declination_re = 0.0;
  } else {
    provaseriale_noxbee_B.rtb_Magnetic_declination_re = fmod
      (provaseriale_noxbee_B.rtb_Magnetic_declination_re, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion6' */
  provaseriale_noxbee_B.rtb_heading_re = floor
    (provaseriale_noxbee_B.ComplextoRealImag[4]);
  if (rtIsNaN(provaseriale_noxbee_B.rtb_heading_re) || rtIsInf
      (provaseriale_noxbee_B.rtb_heading_re)) {
    provaseriale_noxbee_B.rtb_heading_re = 0.0;
  } else {
    provaseriale_noxbee_B.rtb_heading_re = fmod
      (provaseriale_noxbee_B.rtb_heading_re, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion7' */
  provaseriale_noxbee_B.rtb_fix_mode_re = floor
    (provaseriale_noxbee_B.ComplextoRealImag[5]);
  if (rtIsNaN(provaseriale_noxbee_B.rtb_fix_mode_re) || rtIsInf
      (provaseriale_noxbee_B.rtb_fix_mode_re)) {
    provaseriale_noxbee_B.rtb_fix_mode_re = 0.0;
  } else {
    provaseriale_noxbee_B.rtb_fix_mode_re = fmod
      (provaseriale_noxbee_B.rtb_fix_mode_re, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion9' */
  provaseriale_noxbee_B.rtb_n_sat_re = floor
    (provaseriale_noxbee_B.DataTypeConversion1_k[0]);
  if (rtIsNaN(provaseriale_noxbee_B.rtb_n_sat_re) || rtIsInf
      (provaseriale_noxbee_B.rtb_n_sat_re)) {
    provaseriale_noxbee_B.rtb_n_sat_re = 0.0;
  } else {
    provaseriale_noxbee_B.rtb_n_sat_re = fmod(provaseriale_noxbee_B.rtb_n_sat_re,
      256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   */
  if (provaseriale_noxbee_DW.obj.Protocol !=
      provaseriale_noxbee_P.SerialTransmit_Protocol) {
    provaseriale_noxbee_DW.obj.Protocol =
      provaseriale_noxbee_P.SerialTransmit_Protocol;
  }

  provaseriale_noxbee_B.dataIn[0] = (uint8_T)
    (provaseriale_noxbee_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint8_T)
     provaseriale_noxbee_B.deltafalllimit);
  provaseriale_noxbee_B.dataIn[1] = (uint8_T)(provaseriale_noxbee_B.rtb_Long_re <
    0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.rtb_Long_re
    : (int32_T)(uint8_T)provaseriale_noxbee_B.rtb_Long_re);
  provaseriale_noxbee_B.dataIn[2] = (uint8_T)(provaseriale_noxbee_B.rtb_V_re <
    0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.rtb_V_re :
    (int32_T)(uint8_T)provaseriale_noxbee_B.rtb_V_re);
  provaseriale_noxbee_B.dataIn[3] = (uint8_T)
    (provaseriale_noxbee_B.rtb_Magnetic_declination_re < 0.0 ? (int32_T)(uint8_T)
     -(int8_T)(uint8_T)-provaseriale_noxbee_B.rtb_Magnetic_declination_re :
     (int32_T)(uint8_T)provaseriale_noxbee_B.rtb_Magnetic_declination_re);
  provaseriale_noxbee_B.dataIn[4] = (uint8_T)
    (provaseriale_noxbee_B.rtb_heading_re < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.rtb_heading_re : (int32_T)(uint8_T)
     provaseriale_noxbee_B.rtb_heading_re);
  provaseriale_noxbee_B.dataIn[5] = (uint8_T)
    (provaseriale_noxbee_B.rtb_fix_mode_re < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.rtb_fix_mode_re : (int32_T)(uint8_T)
     provaseriale_noxbee_B.rtb_fix_mode_re);

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  provaseriale_noxbee_B.deltafalllimit = floor
    (provaseriale_noxbee_P.Constant5_Value_l[0]);
  if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
      (provaseriale_noxbee_B.deltafalllimit)) {
    provaseriale_noxbee_B.deltafalllimit = 0.0;
  } else {
    provaseriale_noxbee_B.deltafalllimit = fmod
      (provaseriale_noxbee_B.deltafalllimit, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   */
  provaseriale_noxbee_B.dataIn[6] = (uint8_T)
    (provaseriale_noxbee_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint8_T)
     provaseriale_noxbee_B.deltafalllimit);

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  provaseriale_noxbee_B.deltafalllimit = floor
    (provaseriale_noxbee_P.Constant5_Value_l[1]);
  if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
      (provaseriale_noxbee_B.deltafalllimit)) {
    provaseriale_noxbee_B.deltafalllimit = 0.0;
  } else {
    provaseriale_noxbee_B.deltafalllimit = fmod
      (provaseriale_noxbee_B.deltafalllimit, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   */
  provaseriale_noxbee_B.dataIn[7] = (uint8_T)
    (provaseriale_noxbee_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint8_T)
     provaseriale_noxbee_B.deltafalllimit);

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  provaseriale_noxbee_B.deltafalllimit = floor
    (provaseriale_noxbee_P.Constant5_Value_l[2]);
  if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
      (provaseriale_noxbee_B.deltafalllimit)) {
    provaseriale_noxbee_B.deltafalllimit = 0.0;
  } else {
    provaseriale_noxbee_B.deltafalllimit = fmod
      (provaseriale_noxbee_B.deltafalllimit, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   */
  provaseriale_noxbee_B.dataIn[8] = (uint8_T)
    (provaseriale_noxbee_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint8_T)
     provaseriale_noxbee_B.deltafalllimit);

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  provaseriale_noxbee_B.deltafalllimit = floor
    (provaseriale_noxbee_P.Constant5_Value_l[3]);
  if (rtIsNaN(provaseriale_noxbee_B.deltafalllimit) || rtIsInf
      (provaseriale_noxbee_B.deltafalllimit)) {
    provaseriale_noxbee_B.deltafalllimit = 0.0;
  } else {
    provaseriale_noxbee_B.deltafalllimit = fmod
      (provaseriale_noxbee_B.deltafalllimit, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion10'
   *  DataTypeConversion: '<S1>/Data Type Conversion11'
   *  DataTypeConversion: '<S1>/Data Type Conversion12'
   *  DataTypeConversion: '<S1>/Data Type Conversion13'
   *  DataTypeConversion: '<S1>/Data Type Conversion14'
   *  DataTypeConversion: '<S1>/Data Type Conversion15'
   *  DataTypeConversion: '<S1>/Data Type Conversion16'
   *  DataTypeConversion: '<S1>/Data Type Conversion17'
   *  DataTypeConversion: '<S1>/Data Type Conversion18'
   *  DataTypeConversion: '<S1>/Data Type Conversion19'
   *  DataTypeConversion: '<S1>/Data Type Conversion20'
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  DataTypeConversion: '<S1>/Data Type Conversion9'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  SignalConversion generated from: '<Root>/Serial Transmit'
   */
  provaseriale_noxbee_B.dataIn[9] = (uint8_T)
    (provaseriale_noxbee_B.deltafalllimit < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.deltafalllimit : (int32_T)(uint8_T)
     provaseriale_noxbee_B.deltafalllimit);
  provaseriale_noxbee_B.dataIn[10] = (uint8_T)
    (provaseriale_noxbee_B.rtb_n_sat_re < 0.0 ? (int32_T)(uint8_T)-(int8_T)
     (uint8_T)-provaseriale_noxbee_B.rtb_n_sat_re : (int32_T)(uint8_T)
     provaseriale_noxbee_B.rtb_n_sat_re);
  provaseriale_noxbee_B.dataIn[11] = (uint8_T)(provaseriale_noxbee_B.d7 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d7 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d7);
  provaseriale_noxbee_B.dataIn[12] = (uint8_T)(provaseriale_noxbee_B.d6 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d6 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d6);
  provaseriale_noxbee_B.dataIn[13] = (uint8_T)(provaseriale_noxbee_B.d5 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d5 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d5);
  provaseriale_noxbee_B.dataIn[14] = (uint8_T)(provaseriale_noxbee_B.d4 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d4 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d4);
  provaseriale_noxbee_B.dataIn[15] = (uint8_T)(provaseriale_noxbee_B.d3 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d3 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d3);
  provaseriale_noxbee_B.dataIn[16] = (uint8_T)(provaseriale_noxbee_B.d2 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d2 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d2);
  provaseriale_noxbee_B.dataIn[17] = (uint8_T)(provaseriale_noxbee_B.d1 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d1 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d1);
  provaseriale_noxbee_B.dataIn[18] = (uint8_T)(provaseriale_noxbee_B.d < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d);
  provaseriale_noxbee_B.dataIn[19] = (uint8_T)(provaseriale_noxbee_B.UkYk1 < 0.0
    ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.UkYk1 :
    (int32_T)(uint8_T)provaseriale_noxbee_B.UkYk1);
  provaseriale_noxbee_B.dataIn[20] = (uint8_T)
    provaseriale_noxbee_B.SFunctionBuilder1;
  provaseriale_noxbee_B.dataIn[21] = (uint8_T)(provaseriale_noxbee_B.f < 0.0F ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.f : (int32_T)
    (uint8_T)provaseriale_noxbee_B.f);
  provaseriale_noxbee_B.dataIn[22] = provaseriale_noxbee_B.indice_dimario;

  /* DataTypeConversion: '<S1>/Data Type Conversion22' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  provaseriale_noxbee_B.d7 = floor(provaseriale_noxbee_P.Constant6_Value_o[0]);
  if (rtIsNaN(provaseriale_noxbee_B.d7) || rtIsInf(provaseriale_noxbee_B.d7)) {
    provaseriale_noxbee_B.d7 = 0.0;
  } else {
    provaseriale_noxbee_B.d7 = fmod(provaseriale_noxbee_B.d7, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion22'
   */
  provaseriale_noxbee_B.dataIn[23] = (uint8_T)(provaseriale_noxbee_B.d7 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d7 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d7);

  /* DataTypeConversion: '<S1>/Data Type Conversion22' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  provaseriale_noxbee_B.d7 = floor(provaseriale_noxbee_P.Constant6_Value_o[1]);
  if (rtIsNaN(provaseriale_noxbee_B.d7) || rtIsInf(provaseriale_noxbee_B.d7)) {
    provaseriale_noxbee_B.d7 = 0.0;
  } else {
    provaseriale_noxbee_B.d7 = fmod(provaseriale_noxbee_B.d7, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion22'
   */
  provaseriale_noxbee_B.dataIn[24] = (uint8_T)(provaseriale_noxbee_B.d7 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d7 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d7);

  /* DataTypeConversion: '<S1>/Data Type Conversion22' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  provaseriale_noxbee_B.d7 = floor(provaseriale_noxbee_P.Constant6_Value_o[2]);
  if (rtIsNaN(provaseriale_noxbee_B.d7) || rtIsInf(provaseriale_noxbee_B.d7)) {
    provaseriale_noxbee_B.d7 = 0.0;
  } else {
    provaseriale_noxbee_B.d7 = fmod(provaseriale_noxbee_B.d7, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion22'
   */
  provaseriale_noxbee_B.dataIn[25] = (uint8_T)(provaseriale_noxbee_B.d7 < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-provaseriale_noxbee_B.d7 : (int32_T)
    (uint8_T)provaseriale_noxbee_B.d7);
  MW_Serial_write(provaseriale_noxbee_DW.obj.port,
                  &provaseriale_noxbee_B.dataIn[0], 26.0,
                  provaseriale_noxbee_DW.obj.dataSizeInBytes,
                  provaseriale_noxbee_DW.obj.sendModeEnum,
                  provaseriale_noxbee_DW.obj.dataType,
                  provaseriale_noxbee_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* Update for S-Function (Mti): '<S4>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S4>/S-Function Builder */
  Mti_Update_wrapper(&provaseriale_noxbee_B.SFunctionBuilder[0],
                     &provaseriale_noxbee_DW.SFunctionBuilder_DSTATE);

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  provaseriale_noxbee_DW.UnitDelay_DSTATE =
    provaseriale_noxbee_P.Constant3_Value_o;
}

/* Model initialize function */
void provaseriale_noxbee_initialize(void)
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

    /* Start for S-Function (Mti): '<S4>/S-Function Builder' */

    /* S-Function Block: <S4>/S-Function Builder */
    Mti_Start_wrapper(&provaseriale_noxbee_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for S-Function (Mti): '<S4>/S-Function Builder' */

    /* S-Function Block: <S4>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provaseriale_noxbee_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    provaseriale_noxbee_DW.UnitDelay_DSTATE =
      provaseriale_noxbee_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S5>/Delay Input2'
     *
     * Block description for '<S5>/Delay Input2':
     *
     *  Store in Global RAM
     */
    provaseriale_noxbee_DW.DelayInput2_DSTATE =
      provaseriale_noxbee_P.DelayInput2_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S2>/One_time_initialization' */
    pr_One_time_initialization_Init
      (&provaseriale_noxbee_B.One_time_initialization,
       &provaseriale_noxbee_DW.One_time_initialization,
       &provaseriale_noxbee_P.One_time_initialization);

    /* End of SystemInitialize for SubSystem: '<S2>/One_time_initialization' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/Execution_loop' */
    /* Start for MATLABSystem: '<S6>/I2C Read12' */
    provaseriale_noxbee_DW.obj_d.matlabCodegenIsDeleted = true;
    obj = &provaseriale_noxbee_DW.obj_d;
    provaseriale_noxbee_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    provaseriale_noxbee_DW.obj_d.isInitialized = 0;
    provaseriale_noxbee_DW.obj_d.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provaseriale_noxbee_DW.obj_d.matlabCodegenIsDeleted = false;
    provaseriale_noxbee_DW.obj_d.SampleTime = provaseriale_noxbee_P.t_AP;
    obj = &provaseriale_noxbee_DW.obj_d;
    provaseriale_noxbee_DW.obj_d.isSetupComplete = false;
    provaseriale_noxbee_DW.obj_d.isInitialized = 1;
    provaseriale_noxbee_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provaseriale_noxbee_B.i2cname,
      0);
    provaseriale_noxbee_DW.obj_d.BusSpeed = 100000U;
    varargin_1 = provaseriale_noxbee_DW.obj_d.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provaseriale_noxbee_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/I2C Read1' */
    provaseriale_noxbee_DW.obj_n.matlabCodegenIsDeleted = true;
    obj = &provaseriale_noxbee_DW.obj_n;
    provaseriale_noxbee_DW.obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
    provaseriale_noxbee_DW.obj_n.isInitialized = 0;
    provaseriale_noxbee_DW.obj_n.SampleTime = -1.0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    provaseriale_noxbee_DW.obj_n.matlabCodegenIsDeleted = false;
    provaseriale_noxbee_DW.obj_n.SampleTime = provaseriale_noxbee_P.t_AP;
    obj = &provaseriale_noxbee_DW.obj_n;
    provaseriale_noxbee_DW.obj_n.isSetupComplete = false;
    provaseriale_noxbee_DW.obj_n.isInitialized = 1;
    provaseriale_noxbee_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(provaseriale_noxbee_B.i2cname,
      0);
    provaseriale_noxbee_DW.obj_n.BusSpeed = 100000U;
    varargin_1 = provaseriale_noxbee_DW.obj_n.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    provaseriale_noxbee_DW.obj_n.isSetupComplete = true;

    /* SystemInitialize for S-Function (calc_T): '<S6>/S-Function Builder' incorporates:
     *  Outport: '<S6>/T'
     */
    provaseriale_noxbee_B.SFunctionBuilder_o1 = provaseriale_noxbee_P.T_Y0;

    /* SystemInitialize for S-Function (calc_p): '<S6>/S-Function Builder1' incorporates:
     *  Outport: '<S6>/p'
     */
    provaseriale_noxbee_B.SFunctionBuilder1 = provaseriale_noxbee_P.p_Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/Execution_loop' */

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function' */
    provaseriale_noxbee_DW.P_ref = 101325.0;
    provaseriale_noxbee_DW.rl_up = 300.0;
    provaseriale_noxbee_DW.rl_dw = -300.0;

    /* SystemInitialize for Enabled SubSystem: '<S10>/Subsystem1' */
    /* SystemInitialize for Outport: '<S12>/T_0' incorporates:
     *  Inport: '<S12>/T'
     */
    provaseriale_noxbee_B.T = provaseriale_noxbee_P.T_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S10>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S14>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S16>/Memory' */
      provaseriale_noxbee_B.ComplextoRealImag[i] =
        provaseriale_noxbee_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S16>/Complex to Real-Imag' incorporates:
       *  Outport: '<S16>/Outport'
       */
      provaseriale_noxbee_B.ComplextoRealImag[i] =
        provaseriale_noxbee_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<S16>/mario' */
    provaseriale_noxbee_B.indice_dimario = provaseriale_noxbee_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S14>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S3>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Subsystem1' */
    /* SystemInitialize for Switch: '<S13>/Switch' incorporates:
     *  Outport: '<S13>/h_to_subtract'
     */
    provaseriale_noxbee_B.Switch = provaseriale_noxbee_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Subsystem1' */

    /* Start for MATLABSystem: '<S3>/Serial Receive1' */
    provaseriale_noxbee_DW.obj_b.matlabCodegenIsDeleted = false;
    provaseriale_noxbee_DW.obj_b.Protocol =
      provaseriale_noxbee_P.SerialReceive1_Protocol;
    provaseriale_noxbee_DW.obj_b.isInitialized = 1;
    provaseriale_noxbee_DW.obj_b.DataTypeWidth = 1U;
    if (provaseriale_noxbee_DW.obj_b.DataTypeWidth > 2047) {
      provaseriale_noxbee_DW.obj_b.DataSizeInBytes = MAX_uint16_T;
    } else {
      provaseriale_noxbee_DW.obj_b.DataSizeInBytes = (uint16_T)
        (provaseriale_noxbee_DW.obj_b.DataTypeWidth << 5);
    }

    MW_SCI_Open(0);
    provaseriale_noxbee_DW.obj_b.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/Serial Receive1' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    provaseriale_noxbee_DW.obj.matlabCodegenIsDeleted = false;
    provaseriale_noxbee_DW.obj.Protocol =
      provaseriale_noxbee_P.SerialTransmit_Protocol;
    provaseriale_noxbee_DW.obj.isInitialized = 1;
    provaseriale_noxbee_DW.obj.port = 2.0;
    provaseriale_noxbee_DW.obj.dataSizeInBytes = 1.0;
    provaseriale_noxbee_DW.obj.dataType = 0.0;
    provaseriale_noxbee_DW.obj.sendModeEnum = 2.0;
    provaseriale_noxbee_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(provaseriale_noxbee_DW.obj.port);
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
    provaseriale_noxbee_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void provaseriale_noxbee_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Serial Receive1' */
  if (!provaseriale_noxbee_DW.obj_b.matlabCodegenIsDeleted) {
    provaseriale_noxbee_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S2>/One_time_initialization' */
  pr_One_time_initialization_Term
    (&provaseriale_noxbee_DW.One_time_initialization);

  /* End of Terminate for SubSystem: '<S2>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<S2>/Execution_loop' */
  /* Terminate for MATLABSystem: '<S6>/I2C Read12' */
  obj = &provaseriale_noxbee_DW.obj_d;
  if (!provaseriale_noxbee_DW.obj_d.matlabCodegenIsDeleted) {
    provaseriale_noxbee_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((provaseriale_noxbee_DW.obj_d.isInitialized == 1) &&
        provaseriale_noxbee_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/I2C Read12' */

  /* Terminate for MATLABSystem: '<S6>/I2C Read1' */
  obj = &provaseriale_noxbee_DW.obj_n;
  if (!provaseriale_noxbee_DW.obj_n.matlabCodegenIsDeleted) {
    provaseriale_noxbee_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((provaseriale_noxbee_DW.obj_n.isInitialized == 1) &&
        provaseriale_noxbee_DW.obj_n.isSetupComplete) {
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/I2C Read1' */
  /* End of Terminate for SubSystem: '<S2>/Execution_loop' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!provaseriale_noxbee_DW.obj.matlabCodegenIsDeleted) {
    provaseriale_noxbee_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
