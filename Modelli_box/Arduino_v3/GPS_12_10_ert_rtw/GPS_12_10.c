/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GPS_12_10.c
 *
 * Code generated for Simulink model 'GPS_12_10'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 16:53:32 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GPS_12_10.h"
#include "GPS_12_10_private.h"

/* Block signals (default storage) */
B_GPS_12_10_T GPS_12_10_B;

/* Block states (default storage) */
DW_GPS_12_10_T GPS_12_10_DW;

/* External inputs (root inport signals with default storage) */
ExtU_GPS_12_10_T GPS_12_10_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_GPS_12_10_T GPS_12_10_Y;

/* Real-time model */
static RT_MODEL_GPS_12_10_T GPS_12_10_M_;
RT_MODEL_GPS_12_10_T *const GPS_12_10_M = &GPS_12_10_M_;

/* Forward declaration for local functions */
static void GPS_12_10_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter);
static boolean_T GPS_12_10_ifWhileCond(const boolean_T x[100]);
static void GPS_12_10_eml_find(const boolean_T x[80], int32_T i_data[], int32_T
  i_size[2]);
static boolean_T GPS_12_10_ifWhileCond_b(const boolean_T x[5]);
static void GPS_12_10_eml_find_o(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void GPS_12_10_readNonFinite(const char_T s[2], int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T GPS_12_10_copydigits(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowpoint);
static boolean_T GPS_12_10_copyexponent(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k);
static void GPS_12_10_readfloat(char_T s1[4], int32_T *idx, const char_T s[2],
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T GPS_12_10_str2double(const char_T s[2]);
static boolean_T GPS_12_10_copydigits_a(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void GPS_12_10_readfloat_o(char_T s1_data[], int32_T *idx, const char_T
  s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T GPS_12_10_str2double_j(const char_T s_data[], const int32_T
  s_size[2]);
static boolean_T GPS_12_10_isUnitImag(const char_T s[3], int32_T k);
static void GPS_12_10_readNonFinite_c(const char_T s[3], int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T GPS_12_10_copydigits_a0(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T GPS_12_10_copyexponent_f(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k);
static void GPS_12_10_readfloat_oc(char_T s1[5], int32_T *idx, const char_T s[3],
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T GPS_12_10_str2double_ja(const char_T s[3]);
static void GPS_12_10_readNonFinite_cy(char_T s, int32_T *k, boolean_T *b_finite,
  real_T *fv);
static boolean_T GPS_12_10_copydigits_a0f(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowpoint);
static boolean_T GPS_12_10_copyexponent_f0(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k);
static void GPS_12_10_readfloat_ocy(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T GPS_12_10_str2double_jae(char_T s);
static real_T GPS_12_10_hex2dec(const char_T s[2]);
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

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void GPS_12_10_find_254(const uint8_T pack[100], real_T position[3],
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
static boolean_T GPS_12_10_ifWhileCond(const boolean_T x[100])
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_eml_find(const boolean_T x[80], int32_T i_data[], int32_T
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_ifWhileCond_b(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_eml_find_o(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readNonFinite(const char_T s[2], int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copydigits(char_T s1[4], int32_T *idx, const char_T
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copyexponent(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k)
{
  int32_T b_k;
  int32_T kexp;
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

      kexp = *k;
      b_k = *k;
      b_success = GPS_12_10_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readfloat(char_T s1[4], int32_T *idx, const char_T s[2],
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
            GPS_12_10_readfloat(s1, idx, s, k, false, &isneg, b_finite, nfv,
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
      GPS_12_10_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = GPS_12_10_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = GPS_12_10_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static creal_T GPS_12_10_str2double(const char_T s[2])
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
  int32_T e_k;
  int32_T idx;
  int32_T k;
  int32_T ntoread;
  char_T s1[4];
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
  ntoread = 0;
  k = 0;
  while ((k + 1 <= 2) && (c[(uint8_T)s[k] & 127] || (s[k] == '\x00'))) {
    k++;
  }

  isimag1 = false;
  b_finite = true;
  GPS_12_10_B.scanned1_g = 0.0;
  idx = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  s1[3] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (k + 1 <= 2)) {
    if (s[k] == '-') {
      isneg = !isneg;
      k++;
    } else if ((s[k] == ',') || (s[k] == '+') || c[(uint8_T)s[k] & 127]) {
      k++;
    } else {
      exitg1 = true;
    }
  }

  success = (k + 1 <= 2);
  if (success && isneg) {
    s1[0] = '-';
    idx = 2;
  }

  e_k = k + 1;
  if (success) {
    if ((k + 1 <= 2) && ((s[k] == 'j') || (s[k] == 'i'))) {
      isimag1 = true;
      e_k = k + 2;
      while ((e_k <= 2) && (c[(uint8_T)s[1] & 127] || (s[1] == '\x00') || (s[1] ==
               ','))) {
        e_k = 3;
      }

      if ((e_k <= 2) && (s[1] == '*')) {
        e_k = 3;
        GPS_12_10_readfloat(s1, &idx, s, &e_k, false, &isneg, &b_finite,
                            &GPS_12_10_B.scanned1_g, &unusedU2, &success);
      } else {
        s1[idx - 1] = '1';
        idx++;
      }
    } else {
      e_k = k + 1;
      GPS_12_10_readNonFinite(s, &e_k, &b_finite, &GPS_12_10_B.scanned1_g);
      if (b_finite) {
        success = GPS_12_10_copydigits(s1, &idx, s, &e_k, true);
        if (success) {
          success = GPS_12_10_copyexponent(s1, &idx, s, &e_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          GPS_12_10_B.scanned1_g = -GPS_12_10_B.scanned1_g;
        }
      }

      exitg1 = false;
      while ((!exitg1) && (e_k <= 2)) {
        tmp = s[e_k - 1];
        if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
          e_k++;
        } else {
          exitg1 = true;
        }
      }

      if ((e_k <= 2) && (s[e_k - 1] == '*')) {
        e_k++;
        exitg1 = false;
        while ((!exitg1) && (e_k <= 2)) {
          tmp = s[e_k - 1];
          if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
            e_k++;
          } else {
            exitg1 = true;
          }
        }
      }

      if (e_k <= 2) {
        tmp = s[e_k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          e_k++;
          isimag1 = true;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (e_k <= 2)) {
      tmp = s[e_k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00') || (tmp == ',')) {
        e_k++;
      } else {
        exitg1 = true;
      }
    }
  }

  if (b_finite) {
    ntoread = 1;
  }

  if (success && (e_k <= 2)) {
    s1[idx - 1] = ' ';
    idx++;
    GPS_12_10_readfloat(s1, &idx, s, &e_k, true, &success, &isneg,
                        &GPS_12_10_B.scanned2_m, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (e_k > 2) && (isimag1 != success) && unusedU2);
  } else {
    GPS_12_10_B.scanned2_m = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &GPS_12_10_B.scanned1_g,
                       &GPS_12_10_B.scanned2_m);
      if (ntoread != 2) {
        GPS_12_10_B.scanned1_g = (rtNaN);
        GPS_12_10_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &GPS_12_10_B.b_scanned1_n);
      if (b_finite) {
        if (ntoread == 1) {
          GPS_12_10_B.scanned1_g = GPS_12_10_B.b_scanned1_n;
        } else {
          GPS_12_10_B.scanned1_g = (rtNaN);
        }
      } else if (ntoread == 1) {
        GPS_12_10_B.scanned2_m = GPS_12_10_B.b_scanned1_n;
      } else {
        GPS_12_10_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = GPS_12_10_B.scanned2_m;
      x.im = GPS_12_10_B.scanned1_g;
    } else {
      x.re = GPS_12_10_B.scanned1_g;
      x.im = GPS_12_10_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copydigits_a(char_T s1_data[], int32_T *idx, const
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readfloat_o(char_T s1_data[], int32_T *idx, const char_T
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
          GPS_12_10_readfloat_o(s1_data, idx, s_data, k, n, false, &isneg,
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
        *success = GPS_12_10_copydigits_a(s1_data, &b_idx, s_data, &h_k, n, true);
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
              isneg = GPS_12_10_copydigits_a(s1_data, idx, s_data, &b_idx, n,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static creal_T GPS_12_10_str2double_j(const char_T s_data[], const int32_T
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
  int32_T idx;
  int32_T k;
  int32_T ntoread;
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
    ntoread = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= s_size[1])) {
      tmp = s_data[k - 1];
      if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
        k++;
      } else {
        exitg1 = true;
      }
    }

    GPS_12_10_B.s1_size[0] = 1;
    GPS_12_10_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= idx) {
      memset(&GPS_12_10_B.s1_data[0], 0, (idx + 1) * sizeof(char_T));
    }

    idx = 1;
    GPS_12_10_readfloat_o(GPS_12_10_B.s1_data, &idx, s_data, &k, s_size[1], true,
                          &isimag1, &isfinite1, &GPS_12_10_B.scanned1, &unusedU0,
                          &success);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success) {
      if (k <= s_size[1]) {
        GPS_12_10_B.s1_data[idx - 1] = ' ';
        idx++;
        GPS_12_10_readfloat_o(GPS_12_10_B.s1_data, &idx, s_data, &k, s_size[1],
                              true, &unusedU0, &success, &GPS_12_10_B.scanned2,
                              &foundsign, &c_success);
        if (success) {
          ntoread++;
        }

        success = (c_success && ((k > s_size[1]) && ((isimag1 != unusedU0) &&
          foundsign)));
      } else {
        GPS_12_10_B.scanned2 = 0.0;
      }
    } else {
      GPS_12_10_B.scanned2 = 0.0;
    }

    if (success) {
      GPS_12_10_B.s1_data[idx - 1] = '\x00';
      switch (ntoread) {
       case 2:
        ntoread = sscanf(&GPS_12_10_B.s1_data[0], "%lf %lf",
                         &GPS_12_10_B.scanned1, &GPS_12_10_B.scanned2);
        if (ntoread != 2) {
          GPS_12_10_B.scanned1 = (rtNaN);
          GPS_12_10_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        ntoread = sscanf(&GPS_12_10_B.s1_data[0], "%lf", &GPS_12_10_B.b_scanned1);
        if (isfinite1) {
          if (ntoread == 1) {
            GPS_12_10_B.scanned1 = GPS_12_10_B.b_scanned1;
          } else {
            GPS_12_10_B.scanned1 = (rtNaN);
          }
        } else if (ntoread == 1) {
          GPS_12_10_B.scanned2 = GPS_12_10_B.b_scanned1;
        } else {
          GPS_12_10_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = GPS_12_10_B.scanned2;
        x.im = GPS_12_10_B.scanned1;
      } else {
        x.re = GPS_12_10_B.scanned1;
        x.im = GPS_12_10_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readNonFinite_c(const char_T s[3], int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copydigits_a0(char_T s1[5], int32_T *idx, const
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copyexponent_f(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k)
{
  int32_T b_k;
  int32_T kexp;
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

      kexp = *k;
      b_k = *k;
      b_success = GPS_12_10_copydigits_a0(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readfloat_oc(char_T s1[5], int32_T *idx, const char_T s[3],
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
    if (GPS_12_10_isUnitImag(s, b_k)) {
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
          GPS_12_10_readfloat_oc(s1, idx, s, k, false, &isneg, b_finite, nfv,
            &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      GPS_12_10_readNonFinite_c(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = GPS_12_10_copydigits_a0(s1, idx, s, k, true);
        if (*success) {
          *success = GPS_12_10_copyexponent_f(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static creal_T GPS_12_10_str2double_ja(const char_T s[3])
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
  int32_T b_k;
  int32_T idx;
  int32_T k;
  int32_T ntoread;
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
  ntoread = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k <= 3)) {
    tmp = s[k - 1];
    if (c[(uint8_T)tmp & 127] || (tmp == '\x00')) {
      k++;
    } else {
      exitg1 = true;
    }
  }

  isimag1 = false;
  b_finite = true;
  GPS_12_10_B.scanned1_c = 0.0;
  idx = 1;
  for (b_k = 0; b_k < 5; b_k++) {
    GPS_12_10_B.s1[b_k] = '\x00';
  }

  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (k <= 3)) {
    tmp = s[k - 1];
    if (tmp == '-') {
      isneg = !isneg;
      k++;
    } else if ((tmp == ',') || (tmp == '+') || c[(uint8_T)tmp & 127]) {
      k++;
    } else {
      exitg1 = true;
    }
  }

  success = (k <= 3);
  if (success && isneg) {
    GPS_12_10_B.s1[0] = '-';
    idx = 2;
  }

  b_k = k - 1;
  if (success) {
    if (GPS_12_10_isUnitImag(s, k)) {
      isimag1 = true;
      b_k = k;
      while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00') ||
              (s[b_k] == ','))) {
        b_k++;
      }

      if ((b_k + 1 <= 3) && (s[b_k] == '*')) {
        k = b_k + 2;
        GPS_12_10_readfloat_oc(GPS_12_10_B.s1, &idx, s, &k, false, &isneg,
          &b_finite, &GPS_12_10_B.scanned1_c, &unusedU2, &success);
        b_k = k - 1;
      } else {
        GPS_12_10_B.s1[idx - 1] = '1';
        idx++;
      }
    } else {
      GPS_12_10_readNonFinite_c(s, &k, &b_finite, &GPS_12_10_B.scanned1_c);
      b_k = k - 1;
      if (b_finite) {
        success = GPS_12_10_copydigits_a0(GPS_12_10_B.s1, &idx, s, &k, true);
        b_k = k - 1;
        if (success) {
          success = GPS_12_10_copyexponent_f(GPS_12_10_B.s1, &idx, s, &k);
          b_k = k - 1;
        }
      } else {
        if ((idx >= 2) && (GPS_12_10_B.s1[0] == '-')) {
          idx = 1;
          GPS_12_10_B.s1[0] = ' ';
          GPS_12_10_B.scanned1_c = -GPS_12_10_B.scanned1_c;
        }
      }

      while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00') ||
              (s[b_k] == ','))) {
        b_k++;
      }

      if ((b_k + 1 <= 3) && (s[b_k] == '*')) {
        b_k++;
        while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00')
                || (s[b_k] == ','))) {
          b_k++;
        }
      }

      if ((b_k + 1 <= 3) && ((s[b_k] == 'i') || (s[b_k] == 'j'))) {
        b_k++;
        isimag1 = true;
      }
    }

    while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00') ||
            (s[b_k] == ','))) {
      b_k++;
    }
  }

  if (b_finite) {
    ntoread = 1;
  }

  if (success && (b_k + 1 <= 3)) {
    GPS_12_10_B.s1[idx - 1] = ' ';
    idx++;
    k = b_k + 1;
    GPS_12_10_readfloat_oc(GPS_12_10_B.s1, &idx, s, &k, true, &success, &isneg,
      &GPS_12_10_B.scanned2_f, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (k > 3) && (isimag1 != success) && unusedU2);
  } else {
    GPS_12_10_B.scanned2_f = 0.0;
  }

  if (success) {
    GPS_12_10_B.s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&GPS_12_10_B.s1[0], "%lf %lf", &GPS_12_10_B.scanned1_c,
                       &GPS_12_10_B.scanned2_f);
      if (ntoread != 2) {
        GPS_12_10_B.scanned1_c = (rtNaN);
        GPS_12_10_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&GPS_12_10_B.s1[0], "%lf", &GPS_12_10_B.b_scanned1_g);
      if (b_finite) {
        if (ntoread == 1) {
          GPS_12_10_B.scanned1_c = GPS_12_10_B.b_scanned1_g;
        } else {
          GPS_12_10_B.scanned1_c = (rtNaN);
        }
      } else if (ntoread == 1) {
        GPS_12_10_B.scanned2_f = GPS_12_10_B.b_scanned1_g;
      } else {
        GPS_12_10_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = GPS_12_10_B.scanned2_f;
      x.im = GPS_12_10_B.scanned1_c;
    } else {
      x.re = GPS_12_10_B.scanned1_c;
      x.im = GPS_12_10_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readNonFinite_cy(char_T s, int32_T *k, boolean_T *b_finite,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copydigits_a0f(char_T s1[3], int32_T *idx, char_T s,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static boolean_T GPS_12_10_copyexponent_f0(char_T s1[3], int32_T *idx, char_T s,
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
    b_success = GPS_12_10_copydigits_a0f(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void GPS_12_10_readfloat_ocy(char_T s1[3], int32_T *idx, char_T s,
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
          GPS_12_10_readfloat_ocy(s1, idx, '\x2a', k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      GPS_12_10_readNonFinite_cy(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = GPS_12_10_copydigits_a0f(s1, idx, s, k, true);
        if (*success) {
          *success = GPS_12_10_copyexponent_f0(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static creal_T GPS_12_10_str2double_jae(char_T s)
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
  real_T b_scanned1;
  int32_T d_k;
  int32_T idx;
  int32_T ntoread;
  int32_T tmp;
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
  ntoread = 0;
  d_k = 1;
  tmp = (uint8_T)s & 127;
  if (c[tmp] || (s == '\x00')) {
    d_k = 2;
  }

  isimag1 = false;
  b_finite = true;
  GPS_12_10_B.scanned1_p = 0.0;
  idx = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (d_k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      d_k = 2;
    } else if ((s == ',') || (s == '+') || c[tmp]) {
      d_k = 2;
    } else {
      exitg1 = true;
    }
  }

  success = (d_k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    idx = 2;
  }

  if (success) {
    isneg = false;
    if (d_k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }

    if (isneg) {
      isimag1 = true;
      d_k++;
      s1[idx - 1] = '1';
      idx++;
    } else {
      GPS_12_10_readNonFinite_cy(s, &d_k, &b_finite, &GPS_12_10_B.scanned1_p);
      if (b_finite) {
        success = GPS_12_10_copydigits_a0f(s1, &idx, s, &d_k, true);
        if (success) {
          success = GPS_12_10_copyexponent_f0(s1, &idx, s, &d_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          GPS_12_10_B.scanned1_p = -GPS_12_10_B.scanned1_p;
        }
      }

      while ((d_k <= 1) && (c[tmp] || ((s == '\x00') || (s == ',')))) {
        d_k = 2;
      }

      if ((d_k <= 1) && (s == '*')) {
        d_k = 2;
      }

      if ((d_k <= 1) && ((s == 'i') || (s == 'j'))) {
        d_k = 2;
        isimag1 = true;
      }
    }

    while ((d_k <= 1) && (c[tmp] || ((s == '\x00') || (s == ',')))) {
      d_k = 2;
    }
  }

  if (b_finite) {
    ntoread = 1;
  }

  if (success && (d_k <= 1)) {
    s1[idx - 1] = ' ';
    idx++;
    d_k = 1;
    GPS_12_10_readfloat_ocy(s1, &idx, s, &d_k, true, &success, &isneg,
      &GPS_12_10_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (d_k > 1) && (isimag1 != success) && foundsign);
  } else {
    GPS_12_10_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &GPS_12_10_B.scanned1_p,
                       &GPS_12_10_B.scanned2_l);
      if (ntoread != 2) {
        GPS_12_10_B.scanned1_p = (rtNaN);
        GPS_12_10_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (b_finite) {
        if (ntoread == 1) {
          GPS_12_10_B.scanned1_p = b_scanned1;
        } else {
          GPS_12_10_B.scanned1_p = (rtNaN);
        }
      } else if (ntoread == 1) {
        GPS_12_10_B.scanned2_l = b_scanned1;
      } else {
        GPS_12_10_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = GPS_12_10_B.scanned2_l;
      x.im = GPS_12_10_B.scanned1_p;
    } else {
      x.re = GPS_12_10_B.scanned1_p;
      x.im = GPS_12_10_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T GPS_12_10_hex2dec(const char_T s[2])
{
  static const uint64m_T tmp_1 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_2 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 48U, 0U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { 55U, 0U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { 87U, 0U }/* chunks */
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
  uint64m_T tmp_0;
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

  GPS_12_10_B.a = tmp_1;
  GPS_12_10_B.p16 = tmp_2;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_3;
      MultiWordSub(&tmp.chunks[0U], &tmp_3.chunks[0U], &GPS_12_10_B.sk.chunks[0U],
                   2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_4;
      MultiWordSub(&tmp.chunks[0U], &tmp_4.chunks[0U], &GPS_12_10_B.sk.chunks[0U],
                   2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
        tmp_0 = tmp_5;
        MultiWordSub(&tmp.chunks[0U], &tmp_5.chunks[0U], &GPS_12_10_B.sk.chunks
                     [0U], 2);
      } else {
        GPS_12_10_B.sk = tmp_1;
      }
    } else {
      GPS_12_10_B.sk = tmp_1;
    }

    uMultiWordMul(&GPS_12_10_B.sk.chunks[0U], 2, &GPS_12_10_B.p16.chunks[0U], 2,
                  &GPS_12_10_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&GPS_12_10_B.r.chunks[0U], 4, &tmp.chunks[0U], 2);
    MultiWordAdd(&GPS_12_10_B.a.chunks[0U], &tmp.chunks[0U], &tmp_0.chunks[0U],
                 2);
    GPS_12_10_B.a = tmp_0;
    uMultiWord2MultiWord(&GPS_12_10_B.p16.chunks[0U], 2, &GPS_12_10_B.r2.chunks
                         [0U], 3);
    uMultiWordShl(&GPS_12_10_B.r2.chunks[0U], 3, 4U, &GPS_12_10_B.r1.chunks[0U],
                  3);
    uMultiWord2MultiWord(&GPS_12_10_B.r1.chunks[0U], 3, &GPS_12_10_B.p16.chunks
                         [0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&GPS_12_10_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&GPS_12_10_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&GPS_12_10_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&GPS_12_10_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&GPS_12_10_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&GPS_12_10_B.a.chunks[0U], 2, 0);
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

/* Model step function */
void GPS_12_10_step(void)
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  real32_T tmp;
  char_T ck_ric[2];
  char_T messaggio;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T counter;
  uint8_T find_comma;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T y;

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&GPS_12_10_P.Constant1_Value_k,
    &GPS_12_10_B.SFunctionBuilder_o1[0], &GPS_12_10_B.SFunctionBuilder_o2,
    &GPS_12_10_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  GPS_12_10_B.status = 0;
  GPS_12_10_B.caso = 0;
  memset(&GPS_12_10_B.messaggio_c[0], 0, 100U * sizeof(uint8_T));
  memset(&GPS_12_10_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  GPS_12_10_find_254(GPS_12_10_B.SFunctionBuilder_o1, GPS_12_10_B.poss_254,
                     &GPS_12_10_B.num_254);
  if (GPS_12_10_DW.Interr_parz && (GPS_12_10_B.num_254 == 1.0)) {
    GPS_12_10_B.f = (int32_T)(GPS_12_10_DW.counter_l + 1U);
    if (GPS_12_10_DW.counter_l + 1U > 255U) {
      GPS_12_10_B.f = 255;
    }

    if (GPS_12_10_B.poss_254[0] != GPS_12_10_B.f) {
      GPS_12_10_B.num_254 = 0.0;
    }
  }

  y = !GPS_12_10_DW.Interr_parz;
  if ((GPS_12_10_B.num_254 == 1.0) && y) {
    GPS_12_10_B.caso = 1;
  } else if ((GPS_12_10_B.num_254 == 0.0) && GPS_12_10_DW.Interr_parz) {
    GPS_12_10_B.caso = 2;
  } else if ((GPS_12_10_B.num_254 == 1.0) && GPS_12_10_DW.Interr_parz) {
    GPS_12_10_B.caso = 3;
  } else {
    if ((GPS_12_10_B.num_254 == 2.0) && y) {
      GPS_12_10_B.caso = 4;
    }
  }

  switch (GPS_12_10_B.caso) {
   case 1:
    GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.poss_254[(int32_T)GPS_12_10_B.num_254 -
      1];
    if (GPS_12_10_B.rtb_Lat_re == 100.0) {
      GPS_12_10_DW.message_o[0] = GPS_12_10_B.SFunctionBuilder_o1[99];
      GPS_12_10_DW.Interr_parz = true;
    } else if (GPS_12_10_B.SFunctionBuilder_o1[(int32_T)(GPS_12_10_B.rtb_Lat_re
                + 1.0) - 1] <= 100) {
      GPS_12_10_B.f = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
        (GPS_12_10_B.poss_254[0] + 1.0) - 1] + 8U);
      GPS_12_10_B.i_d = GPS_12_10_B.f;
      if ((uint32_T)GPS_12_10_B.f > 255U) {
        GPS_12_10_B.i_d = 255;
      }

      if (GPS_12_10_B.i_d == GPS_12_10_B.SFunctionBuilder_o2) {
        GPS_12_10_B.num_254 = rt_roundd_snf(GPS_12_10_B.rtb_Lat_re);
        if (GPS_12_10_B.num_254 < 256.0) {
          if (GPS_12_10_B.num_254 >= 0.0) {
            counter = (uint8_T)GPS_12_10_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        GPS_12_10_B.f = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
          (GPS_12_10_B.rtb_Lat_re + 1.0) - 1] + 7U);
        if ((uint32_T)GPS_12_10_B.f > 255U) {
          GPS_12_10_B.f = 255;
        }

        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.rtb_Lat_re + (real_T)
          GPS_12_10_B.f);
        if (GPS_12_10_B.rtb_Lat_re < 256.0) {
          if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
            find_comma = (uint8_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          GPS_12_10_B.i = 0;
          GPS_12_10_B.f = 0;
        } else {
          GPS_12_10_B.i = counter - 1;
          GPS_12_10_B.f = find_comma;
        }

        GPS_12_10_B.caso = GPS_12_10_B.f - GPS_12_10_B.i;
        for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.caso; GPS_12_10_B.f
             ++) {
          GPS_12_10_DW.message_o[GPS_12_10_B.f] =
            GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.i + GPS_12_10_B.f];
        }

        GPS_12_10_B.status = 1;
        for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 100; GPS_12_10_B.i++) {
          GPS_12_10_B.messaggio_c[GPS_12_10_B.i] =
            GPS_12_10_DW.message_o[GPS_12_10_B.i];
          GPS_12_10_DW.message_o[GPS_12_10_B.i] = 0U;
        }

        GPS_12_10_DW.counter_l = 0U;
        GPS_12_10_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)GPS_12_10_B.f > 255U) {
          GPS_12_10_B.f = 255;
        }

        if (GPS_12_10_B.f > GPS_12_10_B.SFunctionBuilder_o2) {
          GPS_12_10_DW.mess_len = GPS_12_10_B.SFunctionBuilder_o2;
          if (GPS_12_10_B.rtb_Lat_re > GPS_12_10_DW.mess_len) {
            GPS_12_10_B.i = 0;
            GPS_12_10_B.f = 0;
          } else {
            GPS_12_10_B.i = (int32_T)GPS_12_10_B.rtb_Lat_re - 1;
            GPS_12_10_B.f = (int32_T)GPS_12_10_DW.mess_len;
          }

          GPS_12_10_B.caso = GPS_12_10_B.f - GPS_12_10_B.i;
          for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.caso;
               GPS_12_10_B.f++) {
            GPS_12_10_DW.message_o[GPS_12_10_B.f] =
              GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.i + GPS_12_10_B.f];
          }

          GPS_12_10_B.f = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
            (GPS_12_10_B.rtb_Lat_re + 1.0) - 1] + 8U);
          if ((uint32_T)GPS_12_10_B.f > 255U) {
            GPS_12_10_B.f = 255;
          }

          GPS_12_10_B.rtb_Lat_re = rt_roundd_snf((real_T)GPS_12_10_B.f -
            GPS_12_10_DW.mess_len);
          if (GPS_12_10_B.rtb_Lat_re < 256.0) {
            if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
              GPS_12_10_DW.counter_l = (uint8_T)GPS_12_10_B.rtb_Lat_re;
            } else {
              GPS_12_10_DW.counter_l = 0U;
            }
          } else {
            GPS_12_10_DW.counter_l = MAX_uint8_T;
          }

          GPS_12_10_DW.Interr_parz = true;
        }
      }
    } else {
      GPS_12_10_DW.Interr_parz = false;
      memset(&GPS_12_10_DW.message_o[0], 0, 100U * sizeof(uint8_T));
      GPS_12_10_DW.counter_l = 0U;
      GPS_12_10_DW.mess_len = 0.0;
      GPS_12_10_B.status = 1;
    }
    break;

   case 2:
    for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
      GPS_12_10_B.x[GPS_12_10_B.f] =
        (GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.f] != 0);
    }

    if (GPS_12_10_ifWhileCond(GPS_12_10_B.x)) {
      GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_DW.mess_len + 1.0);
      if (GPS_12_10_B.rtb_Lat_re < 256.0) {
        if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
          find_comma = (uint8_T)GPS_12_10_B.rtb_Lat_re;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_DW.mess_len + (real_T)
        GPS_12_10_DW.counter_l);
      if (GPS_12_10_B.rtb_Lat_re < 256.0) {
        if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
          counter = (uint8_T)GPS_12_10_B.rtb_Lat_re;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (find_comma > counter) {
        GPS_12_10_B.status = 1;
      } else {
        GPS_12_10_B.status = find_comma;
      }

      if (1 > GPS_12_10_DW.counter_l) {
        GPS_12_10_B.caso = -1;
      } else {
        GPS_12_10_B.caso = GPS_12_10_DW.counter_l - 1;
      }

      for (GPS_12_10_B.f = 0; GPS_12_10_B.f <= GPS_12_10_B.caso; GPS_12_10_B.f++)
      {
        GPS_12_10_DW.message_o[(GPS_12_10_B.status + GPS_12_10_B.f) - 1] =
          GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.f];
      }

      GPS_12_10_DW.Interr_parz = false;
      GPS_12_10_B.status = 1;
      for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 100; GPS_12_10_B.i++) {
        GPS_12_10_B.messaggio_c[GPS_12_10_B.i] =
          GPS_12_10_DW.message_o[GPS_12_10_B.i];
        GPS_12_10_DW.message_o[GPS_12_10_B.i] = 0U;
      }

      GPS_12_10_DW.mess_len = 0.0;
      GPS_12_10_DW.counter_l = 0U;
    } else {
      GPS_12_10_DW.Interr_parz = false;
      GPS_12_10_B.status = 1;
      memset(&GPS_12_10_DW.message_o[0], 0, 100U * sizeof(uint8_T));
      GPS_12_10_DW.mess_len = 0.0;
      GPS_12_10_DW.counter_l = 0U;
    }
    break;

   case 3:
    GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_DW.mess_len + 1.0);
    if (GPS_12_10_B.rtb_Lat_re < 256.0) {
      if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
        find_comma = (uint8_T)GPS_12_10_B.rtb_Lat_re;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_DW.mess_len + (real_T)
      GPS_12_10_DW.counter_l);
    if (GPS_12_10_B.rtb_Lat_re < 256.0) {
      if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
        counter = (uint8_T)GPS_12_10_B.rtb_Lat_re;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (find_comma > counter) {
      GPS_12_10_B.i = 1;
    } else {
      GPS_12_10_B.i = find_comma;
    }

    if (1 > GPS_12_10_DW.counter_l) {
      GPS_12_10_B.caso = -1;
    } else {
      GPS_12_10_B.caso = GPS_12_10_DW.counter_l - 1;
    }

    for (GPS_12_10_B.f = 0; GPS_12_10_B.f <= GPS_12_10_B.caso; GPS_12_10_B.f++)
    {
      GPS_12_10_DW.message_o[(GPS_12_10_B.i + GPS_12_10_B.f) - 1] =
        GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.f];
    }

    GPS_12_10_DW.Interr_parz = false;
    GPS_12_10_B.status = 1;
    for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 100; GPS_12_10_B.i++) {
      GPS_12_10_B.messaggio_c[GPS_12_10_B.i] =
        GPS_12_10_DW.message_o[GPS_12_10_B.i];
      GPS_12_10_DW.message_o[GPS_12_10_B.i] = 0U;
    }

    GPS_12_10_DW.mess_len = 0.0;
    GPS_12_10_DW.counter_l = 0U;
    GPS_12_10_B.f = (int32_T)(GPS_12_10_B.poss_254[(int32_T)GPS_12_10_B.num_254
      - 1] + 1.0) - 1;
    if (GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.f] <= 100) {
      GPS_12_10_B.i_d = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
        (GPS_12_10_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)GPS_12_10_B.i_d > 255U) {
        GPS_12_10_B.i_d = 255;
      }

      GPS_12_10_B.caso = GPS_12_10_B.SFunctionBuilder_o2;
      if (GPS_12_10_B.SFunctionBuilder_o2 < 0) {
        GPS_12_10_B.caso = 0;
      } else {
        if (GPS_12_10_B.SFunctionBuilder_o2 > 255) {
          GPS_12_10_B.caso = 255;
        }
      }

      if (GPS_12_10_B.i_d == GPS_12_10_B.caso) {
        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[(int32_T)
          GPS_12_10_B.num_254 - 1]);
        if (GPS_12_10_B.rtb_Lat_re < 256.0) {
          if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
            counter = (uint8_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        GPS_12_10_B.f = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.f]
          + 7U);
        if ((uint32_T)GPS_12_10_B.f > 255U) {
          GPS_12_10_B.f = 255;
        }

        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[(int32_T)
          GPS_12_10_B.num_254 - 1] + (real_T)GPS_12_10_B.f);
        if (GPS_12_10_B.rtb_Lat_re < 256.0) {
          if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
            find_comma = (uint8_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          GPS_12_10_B.i = 0;
          GPS_12_10_B.f = 0;
        } else {
          GPS_12_10_B.i = counter - 1;
          GPS_12_10_B.f = find_comma;
        }

        GPS_12_10_B.caso = GPS_12_10_B.f - GPS_12_10_B.i;
        for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.caso; GPS_12_10_B.f
             ++) {
          GPS_12_10_DW.message_o[GPS_12_10_B.f] =
            GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.i + GPS_12_10_B.f];
        }

        for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 100; GPS_12_10_B.i++) {
          GPS_12_10_B.messaggio_2[GPS_12_10_B.i] =
            GPS_12_10_DW.message_o[GPS_12_10_B.i];
          GPS_12_10_DW.message_o[GPS_12_10_B.i] = 0U;
        }

        GPS_12_10_DW.counter_l = 0U;
        GPS_12_10_DW.mess_len = 0.0;
      } else {
        GPS_12_10_B.i_d = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
          (GPS_12_10_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)GPS_12_10_B.i_d > 255U) {
          GPS_12_10_B.i_d = 255;
        }

        GPS_12_10_B.caso = GPS_12_10_B.SFunctionBuilder_o2;
        if (GPS_12_10_B.SFunctionBuilder_o2 < 0) {
          GPS_12_10_B.caso = 0;
        } else {
          if (GPS_12_10_B.SFunctionBuilder_o2 > 255) {
            GPS_12_10_B.caso = 255;
          }
        }

        if (GPS_12_10_B.i_d > GPS_12_10_B.caso) {
          GPS_12_10_DW.mess_len = GPS_12_10_B.SFunctionBuilder_o2;
          if (GPS_12_10_B.poss_254[(int32_T)GPS_12_10_B.num_254 - 1] >
              GPS_12_10_DW.mess_len) {
            GPS_12_10_B.i = 0;
            GPS_12_10_B.caso = 0;
          } else {
            GPS_12_10_B.i = (int32_T)GPS_12_10_B.poss_254[(int32_T)
              GPS_12_10_B.num_254 - 1] - 1;
            GPS_12_10_B.caso = (int32_T)GPS_12_10_DW.mess_len;
          }

          GPS_12_10_B.caso -= GPS_12_10_B.i;
          for (GPS_12_10_B.i_d = 0; GPS_12_10_B.i_d < GPS_12_10_B.caso;
               GPS_12_10_B.i_d++) {
            GPS_12_10_DW.message_o[GPS_12_10_B.i_d] =
              GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.i + GPS_12_10_B.i_d];
          }

          GPS_12_10_B.f = (int32_T)
            (GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.f] + 8U);
          if ((uint32_T)GPS_12_10_B.f > 255U) {
            GPS_12_10_B.f = 255;
          }

          GPS_12_10_B.rtb_Lat_re = rt_roundd_snf((real_T)GPS_12_10_B.f -
            GPS_12_10_DW.mess_len);
          if (GPS_12_10_B.rtb_Lat_re < 256.0) {
            if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
              GPS_12_10_DW.counter_l = (uint8_T)GPS_12_10_B.rtb_Lat_re;
            } else {
              GPS_12_10_DW.counter_l = 0U;
            }
          } else {
            GPS_12_10_DW.counter_l = MAX_uint8_T;
          }

          GPS_12_10_DW.Interr_parz = true;
        }
      }
    } else {
      GPS_12_10_DW.Interr_parz = false;
      memset(&GPS_12_10_B.messaggio_c[0], 0, 100U * sizeof(uint8_T));
      memset(&GPS_12_10_DW.message_o[0], 0, 100U * sizeof(uint8_T));
      GPS_12_10_DW.counter_l = 0U;
      GPS_12_10_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (GPS_12_10_B.SFunctionBuilder_o1[(int32_T)(GPS_12_10_B.poss_254[0] + 1.0)
        - 1] <= 100) {
      GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[0]);
      if (GPS_12_10_B.rtb_Lat_re < 256.0) {
        if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
          counter = (uint8_T)GPS_12_10_B.rtb_Lat_re;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      GPS_12_10_B.f = (int32_T)(GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
        (GPS_12_10_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)GPS_12_10_B.f > 255U) {
        GPS_12_10_B.f = 255;
      }

      GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[0] + (real_T)
        GPS_12_10_B.f);
      if (GPS_12_10_B.rtb_Lat_re < 256.0) {
        if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
          find_comma = (uint8_T)GPS_12_10_B.rtb_Lat_re;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (counter > find_comma) {
        GPS_12_10_B.status = 0;
        GPS_12_10_B.f = 0;
      } else {
        GPS_12_10_B.status = counter - 1;
        GPS_12_10_B.f = find_comma;
      }

      GPS_12_10_B.caso = GPS_12_10_B.f - GPS_12_10_B.status;
      for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.caso; GPS_12_10_B.f++)
      {
        GPS_12_10_B.messaggio_c[GPS_12_10_B.f] =
          GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.status + GPS_12_10_B.f];
      }
    } else {
      GPS_12_10_DW.Interr_parz = false;
      memset(&GPS_12_10_DW.message_o[0], 0, 100U * sizeof(uint8_T));
    }

    GPS_12_10_B.status = 1;
    if ((GPS_12_10_B.SFunctionBuilder_o1[(int32_T)(GPS_12_10_B.poss_254[1] + 1.0)
         - 1] <= 100) && (GPS_12_10_B.poss_254[1] - GPS_12_10_B.poss_254[0] >
                          3.0)) {
      GPS_12_10_B.rtb_Lat_re = rt_roundd_snf((real_T)
        GPS_12_10_B.SFunctionBuilder_o2 - GPS_12_10_B.poss_254[1]);
      GPS_12_10_B.qY = GPS_12_10_B.SFunctionBuilder_o1[(int32_T)
        (GPS_12_10_B.poss_254[1] + 1.0) - 1];
      GPS_12_10_B.f = (int32_T)(GPS_12_10_B.qY + 7U);
      if (GPS_12_10_B.qY + 7U > 255U) {
        GPS_12_10_B.f = 255;
      }

      if (GPS_12_10_B.rtb_Lat_re < 2.147483648E+9) {
        if (GPS_12_10_B.rtb_Lat_re >= -2.147483648E+9) {
          GPS_12_10_B.i_d = (int32_T)GPS_12_10_B.rtb_Lat_re;
        } else {
          GPS_12_10_B.i_d = MIN_int32_T;
        }
      } else {
        GPS_12_10_B.i_d = MAX_int32_T;
      }

      if (GPS_12_10_B.i_d == GPS_12_10_B.f) {
        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[1]);
        if (GPS_12_10_B.rtb_Lat_re < 256.0) {
          if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
            counter = (uint8_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        GPS_12_10_B.f = (int32_T)(GPS_12_10_B.qY + 7U);
        if (GPS_12_10_B.qY + 7U > 255U) {
          GPS_12_10_B.f = 255;
        }

        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[1] + (real_T)
          GPS_12_10_B.f);
        if (GPS_12_10_B.rtb_Lat_re < 256.0) {
          if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
            find_comma = (uint8_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          GPS_12_10_B.status = 0;
          GPS_12_10_B.f = 0;
        } else {
          GPS_12_10_B.status = counter - 1;
          GPS_12_10_B.f = find_comma;
        }

        GPS_12_10_B.caso = GPS_12_10_B.f - GPS_12_10_B.status;
        for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.caso; GPS_12_10_B.f
             ++) {
          GPS_12_10_DW.message_o[GPS_12_10_B.f] =
            GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.status + GPS_12_10_B.f];
        }

        GPS_12_10_B.status = 2;
        for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 100; GPS_12_10_B.i++) {
          GPS_12_10_B.messaggio_2[GPS_12_10_B.i] =
            GPS_12_10_DW.message_o[GPS_12_10_B.i];
          GPS_12_10_DW.message_o[GPS_12_10_B.i] = 0U;
        }

        GPS_12_10_DW.counter_l = 0U;
        GPS_12_10_DW.mess_len = 0.0;
      } else {
        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf(GPS_12_10_B.poss_254[1]);
        if (GPS_12_10_B.rtb_Lat_re < 2.147483648E+9) {
          if (GPS_12_10_B.rtb_Lat_re >= -2.147483648E+9) {
            GPS_12_10_B.f = (int32_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            GPS_12_10_B.f = MIN_int32_T;
          }
        } else {
          GPS_12_10_B.f = MAX_int32_T;
        }

        if (GPS_12_10_B.f > GPS_12_10_B.SFunctionBuilder_o2) {
          GPS_12_10_B.f = -1;
          GPS_12_10_B.caso = 0;
        } else {
          GPS_12_10_B.f -= 2;
          GPS_12_10_B.caso = GPS_12_10_B.SFunctionBuilder_o2;
        }

        GPS_12_10_DW.mess_len = (int8_T)((GPS_12_10_B.caso - GPS_12_10_B.f) - 1);
        if (GPS_12_10_B.rtb_Lat_re < 2.147483648E+9) {
          if (GPS_12_10_B.rtb_Lat_re >= -2.147483648E+9) {
            GPS_12_10_B.f = (int32_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            GPS_12_10_B.f = MIN_int32_T;
          }
        } else {
          GPS_12_10_B.f = MAX_int32_T;
        }

        if (GPS_12_10_B.f > GPS_12_10_B.SFunctionBuilder_o2) {
          GPS_12_10_B.i = 0;
          GPS_12_10_B.f = 0;
        } else {
          GPS_12_10_B.i = GPS_12_10_B.f - 1;
          GPS_12_10_B.f = GPS_12_10_B.SFunctionBuilder_o2;
        }

        GPS_12_10_B.caso = GPS_12_10_B.f - GPS_12_10_B.i;
        for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.caso; GPS_12_10_B.f
             ++) {
          GPS_12_10_DW.message_o[GPS_12_10_B.f] =
            GPS_12_10_B.SFunctionBuilder_o1[GPS_12_10_B.i + GPS_12_10_B.f];
        }

        GPS_12_10_B.f = (int32_T)(GPS_12_10_B.qY + 8U);
        if (GPS_12_10_B.qY + 8U > 255U) {
          GPS_12_10_B.f = 255;
        }

        GPS_12_10_B.rtb_Lat_re = rt_roundd_snf((real_T)GPS_12_10_B.f -
          GPS_12_10_DW.mess_len);
        if (GPS_12_10_B.rtb_Lat_re < 256.0) {
          if (GPS_12_10_B.rtb_Lat_re >= 0.0) {
            GPS_12_10_DW.counter_l = (uint8_T)GPS_12_10_B.rtb_Lat_re;
          } else {
            GPS_12_10_DW.counter_l = 0U;
          }
        } else {
          GPS_12_10_DW.counter_l = MAX_uint8_T;
        }

        GPS_12_10_DW.Interr_parz = true;
      }
    } else {
      GPS_12_10_DW.Interr_parz = false;
      memset(&GPS_12_10_DW.message_o[0], 0, 100U * sizeof(uint8_T));
      GPS_12_10_DW.counter_l = 0U;
      GPS_12_10_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&GPS_12_10_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
    GPS_12_10_B.buffer[3 * GPS_12_10_B.f] = 0U;
  }

  for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
    for (GPS_12_10_B.caso = 0; GPS_12_10_B.caso < 2; GPS_12_10_B.caso++) {
      GPS_12_10_B.i = 3 * GPS_12_10_B.f + GPS_12_10_B.caso;
      GPS_12_10_B.buffer[GPS_12_10_B.i + 1] =
        GPS_12_10_DW.Memory4_PreviousInput[GPS_12_10_B.i];
    }
  }

  GPS_12_10_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (GPS_12_10_B.i >= 1)) {
    for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
      GPS_12_10_B.x[GPS_12_10_B.f] = (GPS_12_10_B.buffer[(3 * GPS_12_10_B.f +
        GPS_12_10_B.i) - 1] == 0);
    }

    y = true;
    GPS_12_10_B.f = 0;
    exitg2 = false;
    while ((!exitg2) && (GPS_12_10_B.f < 100)) {
      if (!GPS_12_10_B.x[GPS_12_10_B.f]) {
        y = false;
        exitg2 = true;
      } else {
        GPS_12_10_B.f++;
      }
    }

    if (y) {
      counter = (uint8_T)GPS_12_10_B.i;
      exitg1 = true;
    } else {
      GPS_12_10_B.i--;
    }
  }

  if (GPS_12_10_B.status == 1) {
    for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
      GPS_12_10_B.buffer[(counter + 3 * GPS_12_10_B.f) - 1] =
        GPS_12_10_B.messaggio_c[GPS_12_10_B.f];
    }
  } else if (GPS_12_10_B.status == 2) {
    GPS_12_10_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      GPS_12_10_B.qY = 0U;
    }

    for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
      GPS_12_10_B.buffer[(counter + 3 * GPS_12_10_B.f) - 1] =
        GPS_12_10_B.messaggio_c[GPS_12_10_B.f];
      GPS_12_10_B.buffer[((int32_T)GPS_12_10_B.qY + 3 * GPS_12_10_B.f) - 1] =
        GPS_12_10_B.messaggio_2[GPS_12_10_B.f];
    }
  } else {
    for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
      GPS_12_10_B.buffer[(counter + 3 * GPS_12_10_B.f) - 1] = 0U;
    }
  }

  for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
    GPS_12_10_B.mess_out[GPS_12_10_B.f] = GPS_12_10_DW.Memory4_PreviousInput[3 *
      GPS_12_10_B.f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  GPS_12_10_B.Add = GPS_12_10_DW.Memory4_PreviousInput[5] +
    GPS_12_10_P.Constant_Value_o;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (GPS_12_10_B.mess_out[2] != GPS_12_10_DW.Memory5_PreviousInput[2]) {
    for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 100; GPS_12_10_B.f++) {
      GPS_12_10_B.x[GPS_12_10_B.f] = (GPS_12_10_B.mess_out[GPS_12_10_B.f] != 0);
    }

    y = true;
    GPS_12_10_B.f = 0;
    exitg1 = false;
    while ((!exitg1) && (GPS_12_10_B.f < 100)) {
      if (!GPS_12_10_B.x[GPS_12_10_B.f]) {
        y = false;
        exitg1 = true;
      } else {
        GPS_12_10_B.f++;
      }
    }

    if (!y) {
      if (GPS_12_10_DW.counter > 100) {
        GPS_12_10_DW.counter = 0U;
      }

      GPS_12_10_B.qY = GPS_12_10_DW.counter + 1U;
      if (GPS_12_10_DW.counter + 1U > 65535U) {
        GPS_12_10_B.qY = 65535U;
      }

      GPS_12_10_DW.counter = (uint16_T)GPS_12_10_B.qY;
    }
  }

  GPS_12_10_B.new_mex = GPS_12_10_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  GPS_12_10_B.Memory1[0] = GPS_12_10_DW.Memory1_PreviousInput[0];
  GPS_12_10_B.Memory1[1] = GPS_12_10_DW.Memory1_PreviousInput[1];

  /* Memory: '<Root>/Memory' */
  GPS_12_10_B.Memory_h[0] = GPS_12_10_DW.Memory_PreviousInput_g[0];
  GPS_12_10_B.Memory_h[1] = GPS_12_10_DW.Memory_PreviousInput_g[1];
  GPS_12_10_B.Memory_h[2] = GPS_12_10_DW.Memory_PreviousInput_g[2];
  GPS_12_10_B.Memory_h[3] = GPS_12_10_DW.Memory_PreviousInput_g[3];

  /* Memory: '<S1>/Memory3' */
  GPS_12_10_B.Memory3 = GPS_12_10_DW.Memory3_PreviousInput;
  for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 8; GPS_12_10_B.i++) {
    /* Memory: '<S1>/Memory' */
    GPS_12_10_B.Memory[GPS_12_10_B.i] =
      GPS_12_10_DW.Memory_PreviousInput_e[GPS_12_10_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper(&GPS_12_10_B.mess_out[0],
    &GPS_12_10_B.Add, &GPS_12_10_B.new_mex, &GPS_12_10_P.SIUAVuint8_Value,
    &GPS_12_10_B.Memory[0], &GPS_12_10_B.Memory1[0], &GPS_12_10_B.Memory_h[0],
    &GPS_12_10_B.Memory3, &GPS_12_10_B.SFunction_o1[0],
    &GPS_12_10_B.SFunction_o2, &GPS_12_10_B.SFunction_o3,
    &GPS_12_10_B.SFunction_o4[0], &GPS_12_10_B.SFunction_o5[0],
    &GPS_12_10_B.SFunction_o6, &GPS_12_10_B.SFunction_o7[0],
    &GPS_12_10_B.SFunction_o8, &GPS_12_10_B.SFunction_o9[0],
    &GPS_12_10_B.SFunction_o10[0], &GPS_12_10_B.SFunction_o11[0],
    &GPS_12_10_B.SFunction_o12, &GPS_12_10_B.SFunction_o13,
    &GPS_12_10_B.SFunction_o14, &GPS_12_10_B.SFunction_o15,
    &GPS_12_10_B.SFunction_o16, &GPS_12_10_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  if ((!GPS_12_10_DW.WP_dbP_not_empty) || ((GPS_12_10_B.SFunction_o7[0] == 3) &&
       (GPS_12_10_B.SFunction_o7[1] == 250))) {
    GPS_12_10_DW.WP_dbP_not_empty = true;
  }

  if ((!GPS_12_10_DW.WP_dbP_AL_not_empty) || ((GPS_12_10_B.SFunction_o7[0] == 3)
       && (GPS_12_10_B.SFunction_o7[1] == 250))) {
    GPS_12_10_DW.WP_dbP_AL_not_empty = true;
  }

  if (GPS_12_10_B.SFunction_o7[0] == 1) {
    if ((GPS_12_10_B.SFunction_o7[1] > 0) && (GPS_12_10_B.SFunction_o7[1] <= 7))
    {
      if ((real32_T)fabs(GPS_12_10_B.SFunction_o8) > 0.0F) {
        GPS_12_10_DW.riferimenti[GPS_12_10_B.SFunction_o7[1] - 1] = 1.0F;
      } else {
        if (GPS_12_10_B.SFunction_o8 == 0.0F) {
          GPS_12_10_DW.riferimenti[GPS_12_10_B.SFunction_o7[1] - 1] = 0.0F;
        }
      }
    } else {
      if ((GPS_12_10_B.SFunction_o7[1] > 7) && (GPS_12_10_B.SFunction_o7[1] < 12))
      {
        GPS_12_10_DW.riferimenti[GPS_12_10_B.SFunction_o7[1] - 1] =
          GPS_12_10_B.SFunction_o8;
      }
    }
  }

  if (GPS_12_10_B.SFunction_o12 == 13) {
    GPS_12_10_DW.riferimenti[GPS_12_10_B.SFunction_o12 - 1] =
      GPS_12_10_B.SFunction_o13;
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  GPS_12_10_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory1'
   *  Memory: '<S1>/Memory2'
   */
  if ((GPS_12_10_B.SFunction_o6 == 0) && (GPS_12_10_B.SFunction_o3 == 0)) {
    GPS_12_10_DW.Memory1_PreviousInput[0] = 0U;
    GPS_12_10_DW.Memory1_PreviousInput[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' incorporates:
     *  Memory: '<S1>/Memory1'
     */
    GPS_12_10_DW.Memory3_PreviousInput = 0U;
  } else if ((GPS_12_10_B.SFunction_o6 == 0) && (GPS_12_10_B.SFunction_o3 == 3))
  {
    GPS_12_10_DW.Memory1_PreviousInput[0] = 0U;
    GPS_12_10_DW.Memory1_PreviousInput[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' incorporates:
     *  Memory: '<S1>/Memory1'
     */
    GPS_12_10_DW.Memory3_PreviousInput = 0U;
  } else if ((GPS_12_10_B.SFunction_o6 == 0) && (GPS_12_10_B.SFunction_o3 == 2))
  {
    GPS_12_10_DW.Memory1_PreviousInput[0] = 0U;
    GPS_12_10_DW.Memory1_PreviousInput[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' incorporates:
     *  Memory: '<S1>/Memory1'
     */
    GPS_12_10_DW.Memory3_PreviousInput = 0U;
  } else if ((GPS_12_10_B.SFunction_o6 == 0) && (GPS_12_10_B.SFunction_o3 == 1))
  {
    GPS_12_10_DW.Memory1_PreviousInput[0] = 0U;
    GPS_12_10_DW.Memory1_PreviousInput[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' incorporates:
     *  Memory: '<S1>/Memory1'
     */
    GPS_12_10_DW.Memory3_PreviousInput = 0U;
  } else {
    switch (GPS_12_10_B.SFunction_o6) {
     case 192:
      GPS_12_10_DW.Memory1_PreviousInput[0] = 192U;
      GPS_12_10_DW.Memory1_PreviousInput[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' incorporates:
       *  Memory: '<S1>/Memory1'
       */
      GPS_12_10_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      GPS_12_10_DW.Memory1_PreviousInput[0] = 208U;
      GPS_12_10_DW.Memory1_PreviousInput[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' incorporates:
       *  Memory: '<S1>/Memory1'
       */
      GPS_12_10_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((GPS_12_10_B.SFunction_o6 == 220) && (GPS_12_10_B.SFunction_o3 != 5))
      {
        if ((GPS_12_10_DW.Memory2_PreviousInput[0] == 0) &&
            (GPS_12_10_DW.Memory2_PreviousInput[1] == 0) &&
            ((GPS_12_10_DW.Memory2_PreviousInput[2] == 1) ||
             (GPS_12_10_DW.Memory2_PreviousInput[3] == 1) ||
             (GPS_12_10_DW.Memory2_PreviousInput[4] == 1) ||
             (GPS_12_10_DW.Memory2_PreviousInput[5] == 1) ||
             (GPS_12_10_DW.Memory2_PreviousInput[6] == 1) ||
             (GPS_12_10_DW.Memory2_PreviousInput[7] == 1))) {
          GPS_12_10_DW.Memory1_PreviousInput[0] = 220U;
          GPS_12_10_DW.Memory1_PreviousInput[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' incorporates:
           *  Memory: '<S1>/Memory1'
           */
          GPS_12_10_DW.Memory3_PreviousInput = 220U;
        } else if ((GPS_12_10_DW.Memory2_PreviousInput[0] == 0) &&
                   (GPS_12_10_DW.Memory2_PreviousInput[1] == 1) &&
                   ((GPS_12_10_DW.Memory2_PreviousInput[2] == 1) ||
                    (GPS_12_10_DW.Memory2_PreviousInput[3] == 1) ||
                    (GPS_12_10_DW.Memory2_PreviousInput[4] == 1) ||
                    (GPS_12_10_DW.Memory2_PreviousInput[5] == 1) ||
                    (GPS_12_10_DW.Memory2_PreviousInput[6] == 1) ||
                    (GPS_12_10_DW.Memory2_PreviousInput[7] == 1))) {
          GPS_12_10_DW.Memory1_PreviousInput[0] = 220U;
          GPS_12_10_DW.Memory1_PreviousInput[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' incorporates:
           *  Memory: '<S1>/Memory1'
           */
          GPS_12_10_DW.Memory3_PreviousInput = 220U;
        } else {
          GPS_12_10_DW.Memory1_PreviousInput[0] = 208U;
          GPS_12_10_DW.Memory1_PreviousInput[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' incorporates:
           *  Memory: '<S1>/Memory1'
           */
          GPS_12_10_DW.Memory3_PreviousInput = 208U;
        }
      } else if (GPS_12_10_B.SFunction_o3 == 5) {
        GPS_12_10_DW.Memory1_PreviousInput[0] = 220U;
        GPS_12_10_DW.Memory1_PreviousInput[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        GPS_12_10_DW.Memory1_PreviousInput[0] = 192U;
        GPS_12_10_DW.Memory1_PreviousInput[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  /* MATLABSystem: '<Root>/Serial Receive1' */
  if (GPS_12_10_DW.obj_h.Protocol != GPS_12_10_P.SerialReceive1_Protocol) {
    GPS_12_10_DW.obj_h.Protocol = GPS_12_10_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, GPS_12_10_DW.obj_h.DataSizeInBytes, &GPS_12_10_B.b_dataOut[0],
                 &counter);

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem2' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (counter > 0) {
    /* MATLAB Function: '<S3>/Create_message' */
    counter = 0U;
    if (!GPS_12_10_DW.start_found) {
      GPS_12_10_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (GPS_12_10_B.i - 1 < 32)) {
        if (GPS_12_10_B.b_dataOut[(uint8_T)GPS_12_10_B.i - 1] == 36) {
          GPS_12_10_B.caso = 32 - (uint8_T)GPS_12_10_B.i;
          for (GPS_12_10_B.f = 0; GPS_12_10_B.f <= GPS_12_10_B.caso;
               GPS_12_10_B.f++) {
            GPS_12_10_DW.message[GPS_12_10_B.f] = GPS_12_10_B.b_dataOut
              [((uint8_T)GPS_12_10_B.i + GPS_12_10_B.f) - 1];
          }

          GPS_12_10_DW.counter_o = (uint8_T)(33 - (uint8_T)GPS_12_10_B.i);
          GPS_12_10_DW.start_found = true;
          exitg1 = true;
        } else {
          GPS_12_10_B.i++;
        }
      }
    } else {
      GPS_12_10_B.f = 1;
      exitg1 = false;
      while ((!exitg1) && (GPS_12_10_B.f - 1 < 32)) {
        if (GPS_12_10_B.b_dataOut[(uint8_T)GPS_12_10_B.f - 1] == 13) {
          GPS_12_10_DW.end_found = true;
          counter = (uint8_T)GPS_12_10_B.f;
          exitg1 = true;
        } else {
          GPS_12_10_B.f++;
        }
      }

      if (GPS_12_10_DW.end_found) {
        if (1 > counter) {
          GPS_12_10_B.caso = -1;
        } else {
          GPS_12_10_B.caso = counter - 1;
        }

        for (GPS_12_10_B.f = 0; GPS_12_10_B.f <= GPS_12_10_B.caso; GPS_12_10_B.f
             ++) {
          GPS_12_10_B.i_d = (int32_T)(((uint32_T)GPS_12_10_B.f +
            GPS_12_10_DW.counter_o) + 1U);
          if ((uint32_T)GPS_12_10_B.i_d > 255U) {
            GPS_12_10_B.i_d = 255;
          }

          GPS_12_10_DW.message[GPS_12_10_B.i_d - 1] =
            GPS_12_10_B.b_dataOut[GPS_12_10_B.f];
        }

        memcpy(&GPS_12_10_B.messaggio_cl[0], &GPS_12_10_DW.message[0], 80U *
               sizeof(uint8_T));
        GPS_12_10_DW.end_found = false;
        GPS_12_10_DW.counter_o = (uint8_T)(32 - counter);
        if (counter == 32) {
          GPS_12_10_DW.start_found = false;
          memset(&GPS_12_10_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          GPS_12_10_DW.start_found = true;
          GPS_12_10_B.caso = -counter;
          for (GPS_12_10_B.f = 0; GPS_12_10_B.f <= GPS_12_10_B.caso + 31;
               GPS_12_10_B.f++) {
            GPS_12_10_DW.message[GPS_12_10_B.f] = GPS_12_10_B.b_dataOut[counter
              + GPS_12_10_B.f];
          }

          GPS_12_10_B.f = counter + 48;
          if (0 <= GPS_12_10_B.f - 1) {
            memset(&GPS_12_10_DW.message[-counter + 32], 0, ((GPS_12_10_B.f -
                     counter) + counter) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S3>/Subsystem' incorporates:
         *  EnablePort: '<S9>/Enable'
         */
        /* MATLAB Function: '<S9>/MATLAB Function' */
        counter = 0U;
        find_comma = 0U;

        /* Outport: '<Root>/mario' incorporates:
         *  MATLAB Function: '<S9>/MATLAB Function'
         */
        GPS_12_10_Y.mario = 0U;

        /* MATLAB Function: '<S9>/MATLAB Function' */
        for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 80; GPS_12_10_B.i++) {
          messaggio = (int8_T)GPS_12_10_B.messaggio_cl[GPS_12_10_B.i];
          if (messaggio == '$') {
            GPS_12_10_B.f = (int32_T)(counter + 1U);
            if (counter + 1U > 255U) {
              GPS_12_10_B.f = 255;
            }

            counter = (uint8_T)GPS_12_10_B.f;
          }

          if (messaggio == ',') {
            GPS_12_10_B.f = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              GPS_12_10_B.f = 255;
            }

            find_comma = (uint8_T)GPS_12_10_B.f;
          }

          GPS_12_10_B.messaggio[GPS_12_10_B.i] = messaggio;
        }

        if ((counter == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
            GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
              (GPS_12_10_B.messaggio[GPS_12_10_B.f] == '$');
          }

          GPS_12_10_eml_find(GPS_12_10_B.messaggio_m, &GPS_12_10_B.eb_data,
                             GPS_12_10_B.eb_size);
          GPS_12_10_B.status = GPS_12_10_B.eb_data;
          for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 5; GPS_12_10_B.f++) {
            messaggio = GPS_12_10_B.messaggio[GPS_12_10_B.f + GPS_12_10_B.status];
            GPS_12_10_B.mess_type_j[GPS_12_10_B.f] = (messaggio ==
              bb[GPS_12_10_B.f]);
            GPS_12_10_B.mess_type[GPS_12_10_B.f] = messaggio;
          }

          if (GPS_12_10_ifWhileCond_b(GPS_12_10_B.mess_type_j)) {
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
                (GPS_12_10_B.messaggio[GPS_12_10_B.f] == ',');
            }

            GPS_12_10_eml_find_o(GPS_12_10_B.messaggio_m,
                                 GPS_12_10_B.comma_gga_data, GPS_12_10_B.eb_size);
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
                (GPS_12_10_B.messaggio[GPS_12_10_B.f] == '*');
            }

            GPS_12_10_eml_find_o(GPS_12_10_B.messaggio_m, GPS_12_10_B.star_data,
                                 GPS_12_10_B.star_size);
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
                (GPS_12_10_B.messaggio[GPS_12_10_B.f] == '$');
            }

            GPS_12_10_eml_find_o(GPS_12_10_B.messaggio_m, GPS_12_10_B.fb_data,
                                 GPS_12_10_B.star_size);
            GPS_12_10_B.Lat_1 = GPS_12_10_str2double
              (&GPS_12_10_B.messaggio[GPS_12_10_B.comma_gga_data[2]]);
            if ((real_T)GPS_12_10_B.comma_gga_data[2] + 3.0 > (real_T)
                GPS_12_10_B.comma_gga_data[3] - 1.0) {
              GPS_12_10_B.caso = 0;
              GPS_12_10_B.f = 0;
            } else {
              GPS_12_10_B.caso = GPS_12_10_B.comma_gga_data[2] + 2;
              GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[3] - 1;
            }

            GPS_12_10_B.messaggio_size[0] = 1;
            GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.caso;
            GPS_12_10_B.messaggio_size[1] = GPS_12_10_B.status;
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                 GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
            }

            GPS_12_10_B.b_x = GPS_12_10_str2double_j(GPS_12_10_B.messaggio_data,
              GPS_12_10_B.messaggio_size);
            if (GPS_12_10_B.b_x.im == 0.0) {
              GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
            } else if (GPS_12_10_B.b_x.re == 0.0) {
              GPS_12_10_B.num_254 = 0.0;
            } else {
              GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
            }

            GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.Lat_1.re + GPS_12_10_B.num_254;
            GPS_12_10_B.caso = GPS_12_10_B.eb_size[0] * GPS_12_10_B.eb_size[1] -
              1;
            if (0 <= GPS_12_10_B.caso) {
              memcpy(&GPS_12_10_B.tmp_data[0], &GPS_12_10_B.comma_gga_data[0],
                     (GPS_12_10_B.caso + 1) * sizeof(int32_T));
            }

            if (GPS_12_10_B.messaggio[GPS_12_10_B.tmp_data[3]] == 'S') {
              GPS_12_10_B.rtb_Lat_re = -GPS_12_10_B.rtb_Lat_re;
            }

            GPS_12_10_B.Lat_1 = GPS_12_10_str2double_ja
              (&GPS_12_10_B.messaggio[GPS_12_10_B.comma_gga_data[4]]);
            if ((real_T)GPS_12_10_B.comma_gga_data[4] + 4.0 > (real_T)
                GPS_12_10_B.comma_gga_data[5] - 1.0) {
              GPS_12_10_B.i = 0;
              GPS_12_10_B.f = 0;
            } else {
              GPS_12_10_B.i = GPS_12_10_B.comma_gga_data[4] + 3;
              GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[5] - 1;
            }

            GPS_12_10_B.messaggio_size_k[0] = 1;
            GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.i;
            GPS_12_10_B.messaggio_size_k[1] = GPS_12_10_B.status;
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                 GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                GPS_12_10_B.messaggio[GPS_12_10_B.i + GPS_12_10_B.f];
            }

            GPS_12_10_B.b_x = GPS_12_10_str2double_j(GPS_12_10_B.messaggio_data,
              GPS_12_10_B.messaggio_size_k);
            if (GPS_12_10_B.b_x.im == 0.0) {
              GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
            } else if (GPS_12_10_B.b_x.re == 0.0) {
              GPS_12_10_B.num_254 = 0.0;
            } else {
              GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
            }

            GPS_12_10_B.num_254 += GPS_12_10_B.Lat_1.re;
            if (GPS_12_10_B.messaggio[GPS_12_10_B.tmp_data[5]] == 'W') {
              GPS_12_10_B.num_254 = -GPS_12_10_B.num_254;
            }

            if ((real_T)GPS_12_10_B.comma_gga_data[6] + 1.0 > (real_T)
                GPS_12_10_B.comma_gga_data[7] - 1.0) {
              GPS_12_10_B.i = 0;
              GPS_12_10_B.f = 0;
            } else {
              GPS_12_10_B.i = GPS_12_10_B.comma_gga_data[6];
              GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[7] - 1;
            }

            GPS_12_10_B.messaggio_size_c[0] = 1;
            GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.i;
            GPS_12_10_B.messaggio_size_c[1] = GPS_12_10_B.status;
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                 GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                GPS_12_10_B.messaggio[GPS_12_10_B.i + GPS_12_10_B.f];
            }

            GPS_12_10_B.Lat_1 = GPS_12_10_str2double_j
              (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_c);
            GPS_12_10_B.rtb_V_re = GPS_12_10_B.Lat_1.re;
            if ((real_T)GPS_12_10_B.comma_gga_data[7] + 1.0 > (real_T)
                GPS_12_10_B.comma_gga_data[8] - 1.0) {
              GPS_12_10_B.caso = 0;
              GPS_12_10_B.f = 0;
            } else {
              GPS_12_10_B.caso = GPS_12_10_B.comma_gga_data[7];
              GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[8] - 1;
            }

            GPS_12_10_B.messaggio_size_b[0] = 1;
            GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.caso;
            GPS_12_10_B.messaggio_size_b[1] = GPS_12_10_B.status;
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                 GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
            }

            GPS_12_10_B.Lat_1 = GPS_12_10_str2double_j
              (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_b);
            GPS_12_10_B.rtb_heading_re = GPS_12_10_B.Lat_1.re;
            if ((real_T)GPS_12_10_B.comma_gga_data[9] + 1.0 > (real_T)
                GPS_12_10_B.comma_gga_data[10] - 1.0) {
              GPS_12_10_B.caso = 0;
              GPS_12_10_B.f = 0;
            } else {
              GPS_12_10_B.caso = GPS_12_10_B.comma_gga_data[9];
              GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[10] - 1;
            }

            GPS_12_10_B.messaggio_size_p[0] = 1;
            GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.caso;
            GPS_12_10_B.messaggio_size_p[1] = GPS_12_10_B.status;
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                 GPS_12_10_B.f++) {
              GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
            }

            GPS_12_10_B.Lat_1 = GPS_12_10_str2double_j
              (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_p);
            GPS_12_10_B.rtb_Magnetic_declination_re = GPS_12_10_B.Lat_1.re;
            if (GPS_12_10_B.messaggio[GPS_12_10_B.tmp_data[10]] == 'W') {
              GPS_12_10_B.rtb_Magnetic_declination_re = -GPS_12_10_B.Lat_1.re;
            }

            GPS_12_10_B.rtb_fix_mode_re = GPS_12_10_B.ComplextoRealImag[5];
            GPS_12_10_B.rtb_n_sat_re = GPS_12_10_B.ComplextoRealImag[6];
            GPS_12_10_B.rtb_h_mean_sea_re = GPS_12_10_B.ComplextoRealImag[7];
            GPS_12_10_B.rtb_h_WGS84_re = GPS_12_10_B.ComplextoRealImag[8];
            if ((real_T)GPS_12_10_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)GPS_12_10_B.star_data[0] + 1.0 >= 0.0) {
                counter = (uint8_T)((real_T)GPS_12_10_B.star_data[0] + 1.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[0] = GPS_12_10_B.messaggio[counter - 1];
            if ((real_T)GPS_12_10_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)GPS_12_10_B.star_data[0] + 2.0 >= 0.0) {
                counter = (uint8_T)((real_T)GPS_12_10_B.star_data[0] + 2.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[1] = GPS_12_10_B.messaggio[counter - 1];
            if ((real_T)GPS_12_10_B.fb_data[0] + 1.0 > (real_T)
                GPS_12_10_B.star_data[0] - 1.0) {
              GPS_12_10_B.caso = 0;
              GPS_12_10_B.status = 0;
            } else {
              GPS_12_10_B.caso = GPS_12_10_B.fb_data[0];
              GPS_12_10_B.status = GPS_12_10_B.star_data[0] - 1;
            }

            GPS_12_10_B.status -= GPS_12_10_B.caso;
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                 GPS_12_10_B.f++) {
              GPS_12_10_B.NMEA_gga_string_data[GPS_12_10_B.f] = (uint8_T)
                GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
            }

            counter = 0U;
            GPS_12_10_B.f = 0;
            while (GPS_12_10_B.f <= GPS_12_10_B.status - 1) {
              counter ^= GPS_12_10_B.NMEA_gga_string_data[GPS_12_10_B.f];
              GPS_12_10_B.f++;
            }

            if (counter != GPS_12_10_hex2dec(ck_ric)) {
              GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.ComplextoRealImag[0];
              GPS_12_10_B.num_254 = GPS_12_10_B.ComplextoRealImag[1];
              GPS_12_10_B.rtb_V_re = GPS_12_10_B.ComplextoRealImag[2];
              GPS_12_10_B.rtb_Magnetic_declination_re =
                GPS_12_10_B.ComplextoRealImag[3];
              GPS_12_10_B.rtb_heading_re = GPS_12_10_B.ComplextoRealImag[4];

              /* Outport: '<Root>/mario' */
              GPS_12_10_Y.mario = 10U;
            }
          } else {
            for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 5; GPS_12_10_B.f++) {
              GPS_12_10_B.mess_type_j[GPS_12_10_B.f] =
                (GPS_12_10_B.mess_type[GPS_12_10_B.f] == cb[GPS_12_10_B.f]);
            }

            if (GPS_12_10_ifWhileCond_b(GPS_12_10_B.mess_type_j)) {
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
                  (GPS_12_10_B.messaggio[GPS_12_10_B.f] == ',');
              }

              GPS_12_10_eml_find_o(GPS_12_10_B.messaggio_m,
                                   GPS_12_10_B.comma_gga_data,
                                   GPS_12_10_B.eb_size);
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
                  (GPS_12_10_B.messaggio[GPS_12_10_B.f] == '*');
              }

              GPS_12_10_eml_find_o(GPS_12_10_B.messaggio_m,
                                   GPS_12_10_B.star_data, GPS_12_10_B.star_size);
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < 80; GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_m[GPS_12_10_B.f] =
                  (GPS_12_10_B.messaggio[GPS_12_10_B.f] == '$');
              }

              GPS_12_10_eml_find_o(GPS_12_10_B.messaggio_m, GPS_12_10_B.fb_data,
                                   GPS_12_10_B.star_size);
              GPS_12_10_B.Lat_1 = GPS_12_10_str2double
                (&GPS_12_10_B.messaggio[GPS_12_10_B.comma_gga_data[1]]);
              if ((real_T)GPS_12_10_B.comma_gga_data[1] + 3.0 > (real_T)
                  GPS_12_10_B.comma_gga_data[2] - 1.0) {
                GPS_12_10_B.caso = 0;
                GPS_12_10_B.f = 0;
              } else {
                GPS_12_10_B.caso = GPS_12_10_B.comma_gga_data[1] + 2;
                GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[2] - 1;
              }

              GPS_12_10_B.messaggio_size[0] = 1;
              GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.caso;
              GPS_12_10_B.messaggio_size[1] = GPS_12_10_B.status;
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                   GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                  GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
              }

              GPS_12_10_B.b_x = GPS_12_10_str2double_j
                (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size);
              if (GPS_12_10_B.b_x.im == 0.0) {
                GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
              } else if (GPS_12_10_B.b_x.re == 0.0) {
                GPS_12_10_B.num_254 = 0.0;
              } else {
                GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
              }

              GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.Lat_1.re +
                GPS_12_10_B.num_254;
              GPS_12_10_B.caso = GPS_12_10_B.eb_size[0] * GPS_12_10_B.eb_size[1]
                - 1;
              if (0 <= GPS_12_10_B.caso) {
                memcpy(&GPS_12_10_B.tmp_data[0], &GPS_12_10_B.comma_gga_data[0],
                       (GPS_12_10_B.caso + 1) * sizeof(int32_T));
              }

              if (GPS_12_10_B.messaggio[GPS_12_10_B.tmp_data[2]] == 'S') {
                GPS_12_10_B.rtb_Lat_re = -GPS_12_10_B.rtb_Lat_re;
              }

              GPS_12_10_B.Lat_1 = GPS_12_10_str2double_ja
                (&GPS_12_10_B.messaggio[GPS_12_10_B.comma_gga_data[3]]);
              if ((real_T)GPS_12_10_B.comma_gga_data[3] + 4.0 > (real_T)
                  GPS_12_10_B.comma_gga_data[4] - 1.0) {
                GPS_12_10_B.i = 0;
                GPS_12_10_B.f = 0;
              } else {
                GPS_12_10_B.i = GPS_12_10_B.comma_gga_data[3] + 3;
                GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[4] - 1;
              }

              GPS_12_10_B.messaggio_size_k[0] = 1;
              GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.i;
              GPS_12_10_B.messaggio_size_k[1] = GPS_12_10_B.status;
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                   GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                  GPS_12_10_B.messaggio[GPS_12_10_B.i + GPS_12_10_B.f];
              }

              GPS_12_10_B.b_x = GPS_12_10_str2double_j
                (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_k);
              if (GPS_12_10_B.b_x.im == 0.0) {
                GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
              } else if (GPS_12_10_B.b_x.re == 0.0) {
                GPS_12_10_B.num_254 = 0.0;
              } else {
                GPS_12_10_B.num_254 = GPS_12_10_B.b_x.re / 60.0;
              }

              GPS_12_10_B.num_254 += GPS_12_10_B.Lat_1.re;
              if (GPS_12_10_B.messaggio[GPS_12_10_B.tmp_data[4]] == 'W') {
                GPS_12_10_B.num_254 = -GPS_12_10_B.num_254;
              }

              GPS_12_10_B.Lat_1 = GPS_12_10_str2double_jae
                (GPS_12_10_B.messaggio[GPS_12_10_B.comma_gga_data[5]]);
              GPS_12_10_B.rtb_fix_mode_re = GPS_12_10_B.Lat_1.re;
              if ((real_T)GPS_12_10_B.comma_gga_data[6] + 1.0 > (real_T)
                  GPS_12_10_B.comma_gga_data[7] - 1.0) {
                GPS_12_10_B.caso = 0;
                GPS_12_10_B.f = 0;
              } else {
                GPS_12_10_B.caso = GPS_12_10_B.comma_gga_data[6];
                GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[7] - 1;
              }

              GPS_12_10_B.messaggio_size_c[0] = 1;
              GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.caso;
              GPS_12_10_B.messaggio_size_c[1] = GPS_12_10_B.status;
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                   GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                  GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
              }

              GPS_12_10_B.Lat_1 = GPS_12_10_str2double_j
                (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_c);
              GPS_12_10_B.rtb_n_sat_re = GPS_12_10_B.Lat_1.re;
              if ((real_T)GPS_12_10_B.comma_gga_data[8] + 1.0 > (real_T)
                  GPS_12_10_B.comma_gga_data[9] - 1.0) {
                GPS_12_10_B.i = 0;
                GPS_12_10_B.f = 0;
              } else {
                GPS_12_10_B.i = GPS_12_10_B.comma_gga_data[8];
                GPS_12_10_B.f = GPS_12_10_B.comma_gga_data[9] - 1;
              }

              GPS_12_10_B.messaggio_size_b[0] = 1;
              GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.i;
              GPS_12_10_B.messaggio_size_b[1] = GPS_12_10_B.status;
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                   GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                  GPS_12_10_B.messaggio[GPS_12_10_B.i + GPS_12_10_B.f];
              }

              GPS_12_10_B.Lat_1 = GPS_12_10_str2double_j
                (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_b);
              GPS_12_10_B.rtb_h_mean_sea_re = GPS_12_10_B.Lat_1.re;
              if ((real_T)GPS_12_10_B.comma_gga_data[10] + 1.0 > (real_T)
                  GPS_12_10_B.comma_gga_data[11] - 1.0) {
                GPS_12_10_B.i = 0;
                GPS_12_10_B.caso = 0;
              } else {
                GPS_12_10_B.i = GPS_12_10_B.comma_gga_data[10];
                GPS_12_10_B.caso = GPS_12_10_B.comma_gga_data[11] - 1;
              }

              GPS_12_10_B.messaggio_size_p[0] = 1;
              GPS_12_10_B.status = GPS_12_10_B.caso - GPS_12_10_B.i;
              GPS_12_10_B.messaggio_size_p[1] = GPS_12_10_B.status;
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                   GPS_12_10_B.f++) {
                GPS_12_10_B.messaggio_data[GPS_12_10_B.f] =
                  GPS_12_10_B.messaggio[GPS_12_10_B.i + GPS_12_10_B.f];
              }

              GPS_12_10_B.Lat_1 = GPS_12_10_str2double_j
                (GPS_12_10_B.messaggio_data, GPS_12_10_B.messaggio_size_p);
              GPS_12_10_B.rtb_h_WGS84_re = GPS_12_10_B.Lat_1.re;
              GPS_12_10_B.rtb_V_re = GPS_12_10_B.ComplextoRealImag[2];
              GPS_12_10_B.rtb_Magnetic_declination_re =
                GPS_12_10_B.ComplextoRealImag[3];
              GPS_12_10_B.rtb_heading_re = GPS_12_10_B.ComplextoRealImag[4];
              if ((real_T)GPS_12_10_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)GPS_12_10_B.star_data[0] + 1.0 >= 0.0) {
                  counter = (uint8_T)((real_T)GPS_12_10_B.star_data[0] + 1.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[0] = GPS_12_10_B.messaggio[counter - 1];
              if ((real_T)GPS_12_10_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)GPS_12_10_B.star_data[0] + 2.0 >= 0.0) {
                  counter = (uint8_T)((real_T)GPS_12_10_B.star_data[0] + 2.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[1] = GPS_12_10_B.messaggio[counter - 1];
              if ((real_T)GPS_12_10_B.fb_data[0] + 1.0 > (real_T)
                  GPS_12_10_B.star_data[0] - 1.0) {
                GPS_12_10_B.caso = 0;
                GPS_12_10_B.f = 0;
              } else {
                GPS_12_10_B.caso = GPS_12_10_B.fb_data[0];
                GPS_12_10_B.f = GPS_12_10_B.star_data[0] - 1;
              }

              GPS_12_10_B.status = GPS_12_10_B.f - GPS_12_10_B.caso;
              for (GPS_12_10_B.f = 0; GPS_12_10_B.f < GPS_12_10_B.status;
                   GPS_12_10_B.f++) {
                GPS_12_10_B.NMEA_gga_string_data[GPS_12_10_B.f] = (uint8_T)
                  GPS_12_10_B.messaggio[GPS_12_10_B.caso + GPS_12_10_B.f];
              }

              counter = 0U;
              GPS_12_10_B.f = 0;
              while (GPS_12_10_B.f <= GPS_12_10_B.status - 1) {
                counter ^= GPS_12_10_B.NMEA_gga_string_data[GPS_12_10_B.f];
                GPS_12_10_B.f++;
              }

              if (counter != GPS_12_10_hex2dec(ck_ric)) {
                GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.ComplextoRealImag[0];
                GPS_12_10_B.num_254 = GPS_12_10_B.ComplextoRealImag[1];
                GPS_12_10_B.rtb_fix_mode_re = GPS_12_10_B.ComplextoRealImag[5];
                GPS_12_10_B.rtb_n_sat_re = GPS_12_10_B.ComplextoRealImag[6];
                GPS_12_10_B.rtb_h_mean_sea_re = GPS_12_10_B.ComplextoRealImag[7];
                GPS_12_10_B.rtb_h_WGS84_re = GPS_12_10_B.ComplextoRealImag[8];

                /* Outport: '<Root>/mario' */
                GPS_12_10_Y.mario = 20U;
              }
            } else {
              GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.ComplextoRealImag[0];
              GPS_12_10_B.num_254 = GPS_12_10_B.ComplextoRealImag[1];
              GPS_12_10_B.rtb_V_re = GPS_12_10_B.ComplextoRealImag[2];
              GPS_12_10_B.rtb_Magnetic_declination_re =
                GPS_12_10_B.ComplextoRealImag[3];
              GPS_12_10_B.rtb_heading_re = GPS_12_10_B.ComplextoRealImag[4];
              GPS_12_10_B.rtb_fix_mode_re = GPS_12_10_B.ComplextoRealImag[5];
              GPS_12_10_B.rtb_n_sat_re = GPS_12_10_B.ComplextoRealImag[6];
              GPS_12_10_B.rtb_h_mean_sea_re = GPS_12_10_B.ComplextoRealImag[7];
              GPS_12_10_B.rtb_h_WGS84_re = GPS_12_10_B.ComplextoRealImag[8];
            }
          }
        } else {
          GPS_12_10_B.rtb_Lat_re = GPS_12_10_B.ComplextoRealImag[0];
          GPS_12_10_B.num_254 = GPS_12_10_B.ComplextoRealImag[1];
          GPS_12_10_B.rtb_V_re = GPS_12_10_B.ComplextoRealImag[2];
          GPS_12_10_B.rtb_Magnetic_declination_re =
            GPS_12_10_B.ComplextoRealImag[3];
          GPS_12_10_B.rtb_heading_re = GPS_12_10_B.ComplextoRealImag[4];
          GPS_12_10_B.rtb_fix_mode_re = GPS_12_10_B.ComplextoRealImag[5];
          GPS_12_10_B.rtb_n_sat_re = GPS_12_10_B.ComplextoRealImag[6];
          GPS_12_10_B.rtb_h_mean_sea_re = GPS_12_10_B.ComplextoRealImag[7];
          GPS_12_10_B.rtb_h_WGS84_re = GPS_12_10_B.ComplextoRealImag[8];
        }

        /* ComplexToRealImag: '<S9>/Complex to Real-Imag' */
        GPS_12_10_B.ComplextoRealImag[0] = GPS_12_10_B.rtb_Lat_re;
        GPS_12_10_B.ComplextoRealImag[1] = GPS_12_10_B.num_254;
        GPS_12_10_B.ComplextoRealImag[2] = GPS_12_10_B.rtb_V_re;
        GPS_12_10_B.ComplextoRealImag[3] =
          GPS_12_10_B.rtb_Magnetic_declination_re;
        GPS_12_10_B.ComplextoRealImag[4] = GPS_12_10_B.rtb_heading_re;
        GPS_12_10_B.ComplextoRealImag[5] = GPS_12_10_B.rtb_fix_mode_re;
        GPS_12_10_B.ComplextoRealImag[6] = GPS_12_10_B.rtb_n_sat_re;
        GPS_12_10_B.ComplextoRealImag[7] = GPS_12_10_B.rtb_h_mean_sea_re;
        GPS_12_10_B.ComplextoRealImag[8] = GPS_12_10_B.rtb_h_WGS84_re;

        /* End of Outputs for SubSystem: '<S3>/Subsystem' */
      } else {
        for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 32; GPS_12_10_B.i++) {
          GPS_12_10_B.f = (int32_T)(((uint32_T)GPS_12_10_DW.counter_o +
            GPS_12_10_B.i) + 1U);
          if ((uint32_T)GPS_12_10_B.f > 255U) {
            GPS_12_10_B.f = 255;
          }

          GPS_12_10_DW.message[GPS_12_10_B.f - 1] =
            GPS_12_10_B.b_dataOut[GPS_12_10_B.i];
        }

        GPS_12_10_B.f = (int32_T)(GPS_12_10_DW.counter_o + 32U);
        if (GPS_12_10_DW.counter_o + 32U > 255U) {
          GPS_12_10_B.f = 255;
        }

        GPS_12_10_DW.counter_o = (uint8_T)GPS_12_10_B.f;
      }
    }

    /* End of MATLAB Function: '<S3>/Create_message' */
  }

  /* End of MATLABSystem: '<Root>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Inport: '<Root>/Cal_alt' */
  if (GPS_12_10_U.Cal_alt > 0.0) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant3'
     *  Logic: '<S2>/OR'
     *  RelationalOperator: '<S2>/Equal'
     *  RelationalOperator: '<S2>/Equal1'
     *  RelationalOperator: '<S2>/Equal2'
     */
    if ((GPS_12_10_B.ComplextoRealImag[5] == GPS_12_10_P.Constant_Value) ||
        (GPS_12_10_B.ComplextoRealImag[5] == GPS_12_10_P.Constant1_Value) ||
        (GPS_12_10_B.ComplextoRealImag[5] == GPS_12_10_P.Constant3_Value)) {
      /* Switch: '<S2>/Switch' */
      GPS_12_10_B.Switch = GPS_12_10_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S2>/Switch' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      GPS_12_10_B.Switch = GPS_12_10_P.Constant2_Value;
    }

    /* End of Switch: '<S2>/Switch' */
  }

  /* End of Inport: '<Root>/Cal_alt' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<Root>/Serial Transmit'
   *  Sum: '<Root>/Sum'
   */
  if (GPS_12_10_DW.obj.Protocol != GPS_12_10_P.SerialTransmit_Protocol) {
    GPS_12_10_DW.obj.Protocol = GPS_12_10_P.SerialTransmit_Protocol;
  }

  GPS_12_10_B.dataIn[0] = GPS_12_10_B.ComplextoRealImag[0];
  GPS_12_10_B.dataIn[1] = GPS_12_10_B.ComplextoRealImag[1];
  GPS_12_10_B.dataIn[2] = GPS_12_10_B.ComplextoRealImag[2];
  GPS_12_10_B.dataIn[3] = GPS_12_10_B.ComplextoRealImag[7] - GPS_12_10_B.Switch;
  GPS_12_10_B.dataIn[4] = GPS_12_10_B.ComplextoRealImag[4];
  GPS_12_10_B.dataIn[5] = GPS_12_10_B.ComplextoRealImag[5];
  MW_Serial_write(GPS_12_10_DW.obj.port, &GPS_12_10_B.dataIn[0], 6.0,
                  GPS_12_10_DW.obj.dataSizeInBytes,
                  GPS_12_10_DW.obj.sendModeEnum, GPS_12_10_DW.obj.dataType,
                  GPS_12_10_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&GPS_12_10_DW.Memory4_PreviousInput[0], &GPS_12_10_B.buffer[0], 300U *
         sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&GPS_12_10_P.Constant1_Value_k,
    &GPS_12_10_B.SFunctionBuilder_o1[0], &GPS_12_10_B.SFunctionBuilder_o2,
    &GPS_12_10_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&GPS_12_10_DW.Memory5_PreviousInput[0], &GPS_12_10_B.mess_out[0], 100U *
         sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  GPS_12_10_DW.Memory_PreviousInput_g[0] = 0U;
  GPS_12_10_DW.Memory_PreviousInput_g[1] = 0U;
  GPS_12_10_DW.Memory_PreviousInput_g[2] = 0U;
  GPS_12_10_DW.Memory_PreviousInput_g[3] = 0U;

  /* Update for Memory: '<S1>/Memory' */
  for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 8; GPS_12_10_B.i++) {
    GPS_12_10_DW.Memory_PreviousInput_e[GPS_12_10_B.i] =
      GPS_12_10_B.SFunction_o11[GPS_12_10_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  GPS_12_10_DW.Memory2_PreviousInput[0] = (uint8_T)AP_mode_idx_0;
  GPS_12_10_DW.Memory2_PreviousInput[1] = (uint8_T)AP_mode_idx_1;
  for (GPS_12_10_B.i = 0; GPS_12_10_B.i < 7; GPS_12_10_B.i++) {
    tmp = rt_roundf_snf(GPS_12_10_DW.riferimenti[GPS_12_10_B.i]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        GPS_12_10_DW.Memory2_PreviousInput[GPS_12_10_B.i + 2] = (uint8_T)tmp;
      } else {
        GPS_12_10_DW.Memory2_PreviousInput[GPS_12_10_B.i + 2] = 0U;
      }
    } else {
      GPS_12_10_DW.Memory2_PreviousInput[GPS_12_10_B.i + 2] = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */
}

/* Model initialize function */
void GPS_12_10_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    real_T tmp_0;
    int32_T i;
    uint8_T tmp_1;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&GPS_12_10_DW.Memory4_PreviousInput[0],
           &GPS_12_10_P.Memory4_InitialCondition[0], 300U * sizeof(uint8_T));

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          GPS_12_10_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      GPS_12_10_DW.Memory5_PreviousInput[i] =
        GPS_12_10_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    GPS_12_10_DW.Memory1_PreviousInput[0] = GPS_12_10_P.Memory1_InitialCondition;
    GPS_12_10_DW.Memory1_PreviousInput[1] = GPS_12_10_P.Memory1_InitialCondition;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    GPS_12_10_DW.Memory_PreviousInput_g[0] =
      GPS_12_10_P.Memory_InitialCondition_c;
    GPS_12_10_DW.Memory_PreviousInput_g[1] =
      GPS_12_10_P.Memory_InitialCondition_c;
    GPS_12_10_DW.Memory_PreviousInput_g[2] =
      GPS_12_10_P.Memory_InitialCondition_c;
    GPS_12_10_DW.Memory_PreviousInput_g[3] =
      GPS_12_10_P.Memory_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    GPS_12_10_DW.Memory3_PreviousInput = GPS_12_10_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      GPS_12_10_DW.Memory_PreviousInput_e[i] =
        GPS_12_10_P.Memory_InitialCondition_m;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      GPS_12_10_DW.Memory2_PreviousInput[i] =
        GPS_12_10_P.Memory2_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&GPS_12_10_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S3>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S9>/Memory' */
      GPS_12_10_B.ComplextoRealImag[i] = GPS_12_10_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S9>/Complex to Real-Imag' incorporates:
       *  Outport: '<S9>/Outport'
       */
      GPS_12_10_B.ComplextoRealImag[i] = GPS_12_10_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<Root>/mario' incorporates:
     *  Outport: '<S9>/mario'
     */
    GPS_12_10_Y.mario = GPS_12_10_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* SystemInitialize for Switch: '<S2>/Switch' incorporates:
     *  Outport: '<S2>/h_to_subtract'
     */
    GPS_12_10_B.Switch = GPS_12_10_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* Start for MATLABSystem: '<Root>/Serial Receive1' */
    GPS_12_10_DW.obj_h.matlabCodegenIsDeleted = false;
    GPS_12_10_DW.obj_h.Protocol = GPS_12_10_P.SerialReceive1_Protocol;
    GPS_12_10_DW.obj_h.isInitialized = 1;
    GPS_12_10_DW.obj_h.DataTypeWidth = 1U;
    if (GPS_12_10_DW.obj_h.DataTypeWidth > 2047) {
      GPS_12_10_DW.obj_h.DataSizeInBytes = MAX_uint16_T;
    } else {
      GPS_12_10_DW.obj_h.DataSizeInBytes = (uint16_T)
        (GPS_12_10_DW.obj_h.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    GPS_12_10_DW.obj_h.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive1' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    GPS_12_10_DW.obj.matlabCodegenIsDeleted = false;
    GPS_12_10_DW.obj.Protocol = GPS_12_10_P.SerialTransmit_Protocol;
    GPS_12_10_DW.obj.isInitialized = 1;
    GPS_12_10_DW.obj.port = 0.0;
    GPS_12_10_DW.obj.dataSizeInBytes = 8.0;
    GPS_12_10_DW.obj.dataType = 6.0;
    GPS_12_10_DW.obj.sendModeEnum = 2.0;
    GPS_12_10_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(GPS_12_10_DW.obj.port);
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
    GPS_12_10_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void GPS_12_10_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive1' */
  if (!GPS_12_10_DW.obj_h.matlabCodegenIsDeleted) {
    GPS_12_10_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!GPS_12_10_DW.obj.matlabCodegenIsDeleted) {
    GPS_12_10_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
