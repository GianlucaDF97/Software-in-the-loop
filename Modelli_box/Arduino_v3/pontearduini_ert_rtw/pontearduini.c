/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pontearduini.c
 *
 * Code generated for Simulink model 'pontearduini'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Oct 25 17:17:38 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pontearduini.h"
#include "pontearduini_private.h"

/* Block signals (default storage) */
B_pontearduini_T pontearduini_B;

/* Block states (default storage) */
DW_pontearduini_T pontearduini_DW;

/* External inputs (root inport signals with default storage) */
ExtU_pontearduini_T pontearduini_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_pontearduini_T pontearduini_Y;

/* Real-time model */
static RT_MODEL_pontearduini_T pontearduini_M_;
RT_MODEL_pontearduini_T *const pontearduini_M = &pontearduini_M_;

/* Forward declaration for local functions */
static void pontearduini_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T pontearduini_ifWhileCond(const boolean_T x[5]);
static void pontearduini_eml_find_b(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void pontearduini_readNonFinite(const char_T s[2], int32_T *k, boolean_T *
  b_finite, real_T *fv);
static boolean_T pontearduini_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T pontearduini_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k);
static void pontearduini_readfloat(char_T s1[4], int32_T *idx, const char_T s[2],
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T pontearduini_str2double(const char_T s[2]);
static boolean_T pontearduini_copydigits_o(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void pontearduini_readfloat_g(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T pontearduini_str2double_a(const char_T s_data[], const int32_T
  s_size[2]);
static boolean_T pontearduini_isUnitImag(const char_T s[3], int32_T k);
static void pontearduini_readNonFinite_g(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T pontearduini_copydigits_o5(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T pontearduini_copyexponent_k(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k);
static void pontearduini_readfloat_g1(char_T s1[5], int32_T *idx, const char_T
  s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T pontearduini_str2double_al(const char_T s[3]);
static void pontearduini_readNonFinite_gh(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T pontearduini_copydigits_o5m(char_T s1[3], int32_T *idx, char_T
  s, int32_T *k, boolean_T allowpoint);
static boolean_T pontearduini_copyexponent_ke(char_T s1[3], int32_T *idx, char_T
  s, int32_T *k);
static void pontearduini_readfloat_g1h(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T pontearduini_str2double_al0(char_T s);
static real_T pontearduini_hex2dec(const char_T s[2]);
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_ifWhileCond(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_eml_find_b(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readNonFinite(const char_T s[2], int32_T *k, boolean_T *
  b_finite, real_T *fv)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copydigits(char_T s1[4], int32_T *idx, const
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k)
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
      b_success = pontearduini_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readfloat(char_T s1[4], int32_T *idx, const char_T s[2],
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
            pontearduini_readfloat(s1, idx, s, k, false, &isneg, b_finite, nfv,
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
      pontearduini_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = pontearduini_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = pontearduini_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static creal_T pontearduini_str2double(const char_T s[2])
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
  pontearduini_B.scanned1_g = 0.0;
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
        pontearduini_readfloat(s1, &idx, s, &e_k, false, &isneg, &b_finite,
          &pontearduini_B.scanned1_g, &unusedU2, &success);
      } else {
        s1[idx - 1] = '1';
        idx++;
      }
    } else {
      e_k = k + 1;
      pontearduini_readNonFinite(s, &e_k, &b_finite, &pontearduini_B.scanned1_g);
      if (b_finite) {
        success = pontearduini_copydigits(s1, &idx, s, &e_k, true);
        if (success) {
          success = pontearduini_copyexponent(s1, &idx, s, &e_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          pontearduini_B.scanned1_g = -pontearduini_B.scanned1_g;
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
    pontearduini_readfloat(s1, &idx, s, &e_k, true, &success, &isneg,
      &pontearduini_B.scanned2_m, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (e_k > 2) && (isimag1 != success) && unusedU2);
  } else {
    pontearduini_B.scanned2_m = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &pontearduini_B.scanned1_g,
                       &pontearduini_B.scanned2_m);
      if (ntoread != 2) {
        pontearduini_B.scanned1_g = (rtNaN);
        pontearduini_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &pontearduini_B.b_scanned1_n);
      if (b_finite) {
        if (ntoread == 1) {
          pontearduini_B.scanned1_g = pontearduini_B.b_scanned1_n;
        } else {
          pontearduini_B.scanned1_g = (rtNaN);
        }
      } else if (ntoread == 1) {
        pontearduini_B.scanned2_m = pontearduini_B.b_scanned1_n;
      } else {
        pontearduini_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = pontearduini_B.scanned2_m;
      x.im = pontearduini_B.scanned1_g;
    } else {
      x.re = pontearduini_B.scanned1_g;
      x.im = pontearduini_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copydigits_o(char_T s1_data[], int32_T *idx, const
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readfloat_g(char_T s1_data[], int32_T *idx, const
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
          pontearduini_readfloat_g(s1_data, idx, s_data, k, n, false, &isneg,
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
        *success = pontearduini_copydigits_o(s1_data, &b_idx, s_data, &h_k, n,
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
              isneg = pontearduini_copydigits_o(s1_data, idx, s_data, &b_idx, n,
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static creal_T pontearduini_str2double_a(const char_T s_data[], const int32_T
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

    pontearduini_B.s1_size[0] = 1;
    pontearduini_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= idx) {
      memset(&pontearduini_B.s1_data[0], 0, (idx + 1) * sizeof(char_T));
    }

    idx = 1;
    pontearduini_readfloat_g(pontearduini_B.s1_data, &idx, s_data, &k, s_size[1],
      true, &isimag1, &isfinite1, &pontearduini_B.scanned1, &unusedU0, &success);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success) {
      if (k <= s_size[1]) {
        pontearduini_B.s1_data[idx - 1] = ' ';
        idx++;
        pontearduini_readfloat_g(pontearduini_B.s1_data, &idx, s_data, &k,
          s_size[1], true, &unusedU0, &success, &pontearduini_B.scanned2,
          &foundsign, &c_success);
        if (success) {
          ntoread++;
        }

        success = (c_success && ((k > s_size[1]) && ((isimag1 != unusedU0) &&
          foundsign)));
      } else {
        pontearduini_B.scanned2 = 0.0;
      }
    } else {
      pontearduini_B.scanned2 = 0.0;
    }

    if (success) {
      pontearduini_B.s1_data[idx - 1] = '\x00';
      switch (ntoread) {
       case 2:
        ntoread = sscanf(&pontearduini_B.s1_data[0], "%lf %lf",
                         &pontearduini_B.scanned1, &pontearduini_B.scanned2);
        if (ntoread != 2) {
          pontearduini_B.scanned1 = (rtNaN);
          pontearduini_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        ntoread = sscanf(&pontearduini_B.s1_data[0], "%lf",
                         &pontearduini_B.b_scanned1);
        if (isfinite1) {
          if (ntoread == 1) {
            pontearduini_B.scanned1 = pontearduini_B.b_scanned1;
          } else {
            pontearduini_B.scanned1 = (rtNaN);
          }
        } else if (ntoread == 1) {
          pontearduini_B.scanned2 = pontearduini_B.b_scanned1;
        } else {
          pontearduini_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = pontearduini_B.scanned2;
        x.im = pontearduini_B.scanned1;
      } else {
        x.re = pontearduini_B.scanned1;
        x.im = pontearduini_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readNonFinite_g(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copydigits_o5(char_T s1[5], int32_T *idx, const
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copyexponent_k(char_T s1[5], int32_T *idx, const
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
      b_success = pontearduini_copydigits_o5(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readfloat_g1(char_T s1[5], int32_T *idx, const char_T
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
    if (pontearduini_isUnitImag(s, b_k)) {
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
          pontearduini_readfloat_g1(s1, idx, s, k, false, &isneg, b_finite, nfv,
            &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      pontearduini_readNonFinite_g(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = pontearduini_copydigits_o5(s1, idx, s, k, true);
        if (*success) {
          *success = pontearduini_copyexponent_k(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static creal_T pontearduini_str2double_al(const char_T s[3])
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
  pontearduini_B.scanned1_c = 0.0;
  idx = 1;
  for (b_k = 0; b_k < 5; b_k++) {
    pontearduini_B.s1[b_k] = '\x00';
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
    pontearduini_B.s1[0] = '-';
    idx = 2;
  }

  b_k = k - 1;
  if (success) {
    if (pontearduini_isUnitImag(s, k)) {
      isimag1 = true;
      b_k = k;
      while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00') ||
              (s[b_k] == ','))) {
        b_k++;
      }

      if ((b_k + 1 <= 3) && (s[b_k] == '*')) {
        k = b_k + 2;
        pontearduini_readfloat_g1(pontearduini_B.s1, &idx, s, &k, false, &isneg,
          &b_finite, &pontearduini_B.scanned1_c, &unusedU2, &success);
        b_k = k - 1;
      } else {
        pontearduini_B.s1[idx - 1] = '1';
        idx++;
      }
    } else {
      pontearduini_readNonFinite_g(s, &k, &b_finite, &pontearduini_B.scanned1_c);
      b_k = k - 1;
      if (b_finite) {
        success = pontearduini_copydigits_o5(pontearduini_B.s1, &idx, s, &k,
          true);
        b_k = k - 1;
        if (success) {
          success = pontearduini_copyexponent_k(pontearduini_B.s1, &idx, s, &k);
          b_k = k - 1;
        }
      } else {
        if ((idx >= 2) && (pontearduini_B.s1[0] == '-')) {
          idx = 1;
          pontearduini_B.s1[0] = ' ';
          pontearduini_B.scanned1_c = -pontearduini_B.scanned1_c;
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
    pontearduini_B.s1[idx - 1] = ' ';
    idx++;
    k = b_k + 1;
    pontearduini_readfloat_g1(pontearduini_B.s1, &idx, s, &k, true, &success,
      &isneg, &pontearduini_B.scanned2_f, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (k > 3) && (isimag1 != success) && unusedU2);
  } else {
    pontearduini_B.scanned2_f = 0.0;
  }

  if (success) {
    pontearduini_B.s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&pontearduini_B.s1[0], "%lf %lf",
                       &pontearduini_B.scanned1_c, &pontearduini_B.scanned2_f);
      if (ntoread != 2) {
        pontearduini_B.scanned1_c = (rtNaN);
        pontearduini_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&pontearduini_B.s1[0], "%lf",
                       &pontearduini_B.b_scanned1_g);
      if (b_finite) {
        if (ntoread == 1) {
          pontearduini_B.scanned1_c = pontearduini_B.b_scanned1_g;
        } else {
          pontearduini_B.scanned1_c = (rtNaN);
        }
      } else if (ntoread == 1) {
        pontearduini_B.scanned2_f = pontearduini_B.b_scanned1_g;
      } else {
        pontearduini_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = pontearduini_B.scanned2_f;
      x.im = pontearduini_B.scanned1_c;
    } else {
      x.re = pontearduini_B.scanned1_c;
      x.im = pontearduini_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readNonFinite_gh(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copydigits_o5m(char_T s1[3], int32_T *idx, char_T
  s, int32_T *k, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static boolean_T pontearduini_copyexponent_ke(char_T s1[3], int32_T *idx, char_T
  s, int32_T *k)
{
  int32_T b_k;
  boolean_T b_success;
  boolean_T success;
  success = true;
  if ((*k <= 1) && ((s == 'E') || (s == 'e'))) {
    s1[*idx - 1] = 'e';
    (*idx)++;
    b_k = 2;
    b_success = pontearduini_copydigits_o5m(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void pontearduini_readfloat_g1h(char_T s1[3], int32_T *idx, char_T s,
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
          pontearduini_readfloat_g1h(s1, idx, '\x2a', k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      pontearduini_readNonFinite_gh(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = pontearduini_copydigits_o5m(s1, idx, s, k, true);
        if (*success) {
          *success = pontearduini_copyexponent_ke(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static creal_T pontearduini_str2double_al0(char_T s)
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
  pontearduini_B.scanned1_p = 0.0;
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
      pontearduini_readNonFinite_gh(s, &d_k, &b_finite,
        &pontearduini_B.scanned1_p);
      if (b_finite) {
        success = pontearduini_copydigits_o5m(s1, &idx, s, &d_k, true);
        if (success) {
          success = pontearduini_copyexponent_ke(s1, &idx, s, &d_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          pontearduini_B.scanned1_p = -pontearduini_B.scanned1_p;
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
    pontearduini_readfloat_g1h(s1, &idx, s, &d_k, true, &success, &isneg,
      &pontearduini_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (d_k > 1) && (isimag1 != success) && foundsign);
  } else {
    pontearduini_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &pontearduini_B.scanned1_p,
                       &pontearduini_B.scanned2_l);
      if (ntoread != 2) {
        pontearduini_B.scanned1_p = (rtNaN);
        pontearduini_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (b_finite) {
        if (ntoread == 1) {
          pontearduini_B.scanned1_p = b_scanned1;
        } else {
          pontearduini_B.scanned1_p = (rtNaN);
        }
      } else if (ntoread == 1) {
        pontearduini_B.scanned2_l = b_scanned1;
      } else {
        pontearduini_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = pontearduini_B.scanned2_l;
      x.im = pontearduini_B.scanned1_p;
    } else {
      x.re = pontearduini_B.scanned1_p;
      x.im = pontearduini_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static real_T pontearduini_hex2dec(const char_T s[2])
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

  pontearduini_B.a = tmp_1;
  pontearduini_B.p16 = tmp_2;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_3;
      MultiWordSub(&tmp.chunks[0U], &tmp_3.chunks[0U],
                   &pontearduini_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_4;
      MultiWordSub(&tmp.chunks[0U], &tmp_4.chunks[0U],
                   &pontearduini_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
        tmp_0 = tmp_5;
        MultiWordSub(&tmp.chunks[0U], &tmp_5.chunks[0U],
                     &pontearduini_B.sk.chunks[0U], 2);
      } else {
        pontearduini_B.sk = tmp_1;
      }
    } else {
      pontearduini_B.sk = tmp_1;
    }

    uMultiWordMul(&pontearduini_B.sk.chunks[0U], 2, &pontearduini_B.p16.chunks
                  [0U], 2, &pontearduini_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&pontearduini_B.r.chunks[0U], 4, &tmp.chunks[0U], 2);
    MultiWordAdd(&pontearduini_B.a.chunks[0U], &tmp.chunks[0U], &tmp_0.chunks[0U],
                 2);
    pontearduini_B.a = tmp_0;
    uMultiWord2MultiWord(&pontearduini_B.p16.chunks[0U], 2,
                         &pontearduini_B.r2.chunks[0U], 3);
    uMultiWordShl(&pontearduini_B.r2.chunks[0U], 3, 4U,
                  &pontearduini_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&pontearduini_B.r1.chunks[0U], 3,
                         &pontearduini_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&pontearduini_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&pontearduini_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&pontearduini_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&pontearduini_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&pontearduini_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&pontearduini_B.a.chunks[0U], 2, 0);
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
void pontearduini_step(void)
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  int32_T i;
  int32_T loop_ub;
  char_T ck_ric[2];
  char_T messaggio;
  uint8_T find_comma;
  uint8_T status;
  boolean_T exitg1;

  /* MATLABSystem: '<Root>/Serial Receive1' */
  if (pontearduini_DW.obj_n.Protocol != pontearduini_P.SerialReceive1_Protocol)
  {
    pontearduini_DW.obj_n.Protocol = pontearduini_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(3, pontearduini_DW.obj_n.DataSizeInBytes,
                 &pontearduini_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem2' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S2>/Create_message' */
    status = 0U;
    if (!pontearduini_DW.start_found) {
      i = 1;
      exitg1 = false;
      while ((!exitg1) && (i - 1 < 32)) {
        if (pontearduini_B.b_dataOut[(uint8_T)i - 1] == 36) {
          loop_ub = 32 - (uint8_T)i;
          for (pontearduini_B.b_i = 0; pontearduini_B.b_i <= loop_ub;
               pontearduini_B.b_i++) {
            pontearduini_DW.message[pontearduini_B.b_i] =
              pontearduini_B.b_dataOut[((uint8_T)i + pontearduini_B.b_i) - 1];
          }

          pontearduini_DW.counter = (uint8_T)(33 - (uint8_T)i);
          pontearduini_DW.start_found = true;
          exitg1 = true;
        } else {
          i++;
        }
      }
    } else {
      pontearduini_B.b_i = 1;
      exitg1 = false;
      while ((!exitg1) && (pontearduini_B.b_i - 1 < 32)) {
        if (pontearduini_B.b_dataOut[(uint8_T)pontearduini_B.b_i - 1] == 13) {
          pontearduini_DW.end_found = true;
          status = (uint8_T)pontearduini_B.b_i;
          exitg1 = true;
        } else {
          pontearduini_B.b_i++;
        }
      }

      if (pontearduini_DW.end_found) {
        if (1 > status) {
          loop_ub = -1;
        } else {
          loop_ub = status - 1;
        }

        for (pontearduini_B.b_i = 0; pontearduini_B.b_i <= loop_ub;
             pontearduini_B.b_i++) {
          i = (int32_T)(((uint32_T)pontearduini_B.b_i + pontearduini_DW.counter)
                        + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          pontearduini_DW.message[i - 1] =
            pontearduini_B.b_dataOut[pontearduini_B.b_i];
        }

        memcpy(&pontearduini_B.messaggio_c[0], &pontearduini_DW.message[0], 80U *
               sizeof(uint8_T));
        pontearduini_DW.end_found = false;
        pontearduini_DW.counter = (uint8_T)(32 - status);
        if (status == 32) {
          pontearduini_DW.start_found = false;
          memset(&pontearduini_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          pontearduini_DW.start_found = true;
          loop_ub = -status;
          for (pontearduini_B.b_i = 0; pontearduini_B.b_i <= loop_ub + 31;
               pontearduini_B.b_i++) {
            pontearduini_DW.message[pontearduini_B.b_i] =
              pontearduini_B.b_dataOut[status + pontearduini_B.b_i];
          }

          pontearduini_B.b_i = status + 48;
          if (0 <= pontearduini_B.b_i - 1) {
            memset(&pontearduini_DW.message[-status + 32], 0,
                   ((pontearduini_B.b_i - status) + status) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
         *  EnablePort: '<S4>/Enable'
         */
        /* MATLAB Function: '<S4>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;

        /* Outport: '<Root>/mario' incorporates:
         *  MATLAB Function: '<S4>/MATLAB Function'
         */
        pontearduini_Y.mario = 0U;

        /* MATLAB Function: '<S4>/MATLAB Function' */
        for (i = 0; i < 80; i++) {
          messaggio = (int8_T)pontearduini_B.messaggio_c[i];
          if (messaggio == '$') {
            pontearduini_B.b_i = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              pontearduini_B.b_i = 255;
            }

            status = (uint8_T)pontearduini_B.b_i;
          }

          if (messaggio == ',') {
            pontearduini_B.b_i = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              pontearduini_B.b_i = 255;
            }

            find_comma = (uint8_T)pontearduini_B.b_i;
          }

          pontearduini_B.messaggio[i] = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
               pontearduini_B.b_i++) {
            pontearduini_B.messaggio_m[pontearduini_B.b_i] =
              (pontearduini_B.messaggio[pontearduini_B.b_i] == '$');
          }

          pontearduini_eml_find(pontearduini_B.messaggio_m,
                                &pontearduini_B.eb_data, pontearduini_B.eb_size);
          loop_ub = pontearduini_B.eb_data;
          for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 5;
               pontearduini_B.b_i++) {
            messaggio = pontearduini_B.messaggio[pontearduini_B.b_i + loop_ub];
            pontearduini_B.mess_type_j[pontearduini_B.b_i] = (messaggio ==
              bb[pontearduini_B.b_i]);
            pontearduini_B.mess_type[pontearduini_B.b_i] = messaggio;
          }

          if (pontearduini_ifWhileCond(pontearduini_B.mess_type_j)) {
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_m[pontearduini_B.b_i] =
                (pontearduini_B.messaggio[pontearduini_B.b_i] == ',');
            }

            pontearduini_eml_find_b(pontearduini_B.messaggio_m,
              pontearduini_B.comma_gga_data, pontearduini_B.eb_size);
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_m[pontearduini_B.b_i] =
                (pontearduini_B.messaggio[pontearduini_B.b_i] == '*');
            }

            pontearduini_eml_find_b(pontearduini_B.messaggio_m,
              pontearduini_B.star_data, pontearduini_B.star_size);
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_m[pontearduini_B.b_i] =
                (pontearduini_B.messaggio[pontearduini_B.b_i] == '$');
            }

            pontearduini_eml_find_b(pontearduini_B.messaggio_m,
              pontearduini_B.fb_data, pontearduini_B.star_size);
            pontearduini_B.Lat_1 = pontearduini_str2double
              (&pontearduini_B.messaggio[pontearduini_B.comma_gga_data[2]]);
            if ((real_T)pontearduini_B.comma_gga_data[2] + 3.0 > (real_T)
                pontearduini_B.comma_gga_data[3] - 1.0) {
              i = 0;
              pontearduini_B.b_i = 0;
            } else {
              i = pontearduini_B.comma_gga_data[2] + 2;
              pontearduini_B.b_i = pontearduini_B.comma_gga_data[3] - 1;
            }

            pontearduini_B.messaggio_size[0] = 1;
            loop_ub = pontearduini_B.b_i - i;
            pontearduini_B.messaggio_size[1] = loop_ub;
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                pontearduini_B.messaggio[i + pontearduini_B.b_i];
            }

            pontearduini_B.b_x = pontearduini_str2double_a
              (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size);
            if (pontearduini_B.b_x.im == 0.0) {
              pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
            } else if (pontearduini_B.b_x.re == 0.0) {
              pontearduini_B.rtb_Long_re = 0.0;
            } else {
              pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
            }

            pontearduini_B.rtb_Lat_re = pontearduini_B.Lat_1.re +
              pontearduini_B.rtb_Long_re;
            loop_ub = pontearduini_B.eb_size[0] * pontearduini_B.eb_size[1] - 1;
            if (0 <= loop_ub) {
              memcpy(&pontearduini_B.tmp_data[0],
                     &pontearduini_B.comma_gga_data[0], (loop_ub + 1) * sizeof
                     (int32_T));
            }

            if (pontearduini_B.messaggio[pontearduini_B.tmp_data[3]] == 'S') {
              pontearduini_B.rtb_Lat_re = -pontearduini_B.rtb_Lat_re;
            }

            pontearduini_B.Lat_1 = pontearduini_str2double_al
              (&pontearduini_B.messaggio[pontearduini_B.comma_gga_data[4]]);
            if ((real_T)pontearduini_B.comma_gga_data[4] + 4.0 > (real_T)
                pontearduini_B.comma_gga_data[5] - 1.0) {
              i = 0;
              pontearduini_B.b_i = 0;
            } else {
              i = pontearduini_B.comma_gga_data[4] + 3;
              pontearduini_B.b_i = pontearduini_B.comma_gga_data[5] - 1;
            }

            pontearduini_B.messaggio_size_k[0] = 1;
            loop_ub = pontearduini_B.b_i - i;
            pontearduini_B.messaggio_size_k[1] = loop_ub;
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                pontearduini_B.messaggio[i + pontearduini_B.b_i];
            }

            pontearduini_B.b_x = pontearduini_str2double_a
              (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_k);
            if (pontearduini_B.b_x.im == 0.0) {
              pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
            } else if (pontearduini_B.b_x.re == 0.0) {
              pontearduini_B.rtb_Long_re = 0.0;
            } else {
              pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
            }

            pontearduini_B.rtb_Long_re += pontearduini_B.Lat_1.re;
            if (pontearduini_B.messaggio[pontearduini_B.tmp_data[5]] == 'W') {
              pontearduini_B.rtb_Long_re = -pontearduini_B.rtb_Long_re;
            }

            if ((real_T)pontearduini_B.comma_gga_data[6] + 1.0 > (real_T)
                pontearduini_B.comma_gga_data[7] - 1.0) {
              i = 0;
              pontearduini_B.b_i = 0;
            } else {
              i = pontearduini_B.comma_gga_data[6];
              pontearduini_B.b_i = pontearduini_B.comma_gga_data[7] - 1;
            }

            pontearduini_B.messaggio_size_c[0] = 1;
            loop_ub = pontearduini_B.b_i - i;
            pontearduini_B.messaggio_size_c[1] = loop_ub;
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                pontearduini_B.messaggio[i + pontearduini_B.b_i];
            }

            pontearduini_B.Lat_1 = pontearduini_str2double_a
              (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_c);
            pontearduini_B.rtb_V_re = pontearduini_B.Lat_1.re;
            if ((real_T)pontearduini_B.comma_gga_data[7] + 1.0 > (real_T)
                pontearduini_B.comma_gga_data[8] - 1.0) {
              i = 0;
              pontearduini_B.b_i = 0;
            } else {
              i = pontearduini_B.comma_gga_data[7];
              pontearduini_B.b_i = pontearduini_B.comma_gga_data[8] - 1;
            }

            pontearduini_B.messaggio_size_b[0] = 1;
            loop_ub = pontearduini_B.b_i - i;
            pontearduini_B.messaggio_size_b[1] = loop_ub;
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                pontearduini_B.messaggio[i + pontearduini_B.b_i];
            }

            pontearduini_B.Lat_1 = pontearduini_str2double_a
              (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_b);
            pontearduini_B.rtb_heading_re = pontearduini_B.Lat_1.re;
            if ((real_T)pontearduini_B.comma_gga_data[9] + 1.0 > (real_T)
                pontearduini_B.comma_gga_data[10] - 1.0) {
              i = 0;
              pontearduini_B.b_i = 0;
            } else {
              i = pontearduini_B.comma_gga_data[9];
              pontearduini_B.b_i = pontearduini_B.comma_gga_data[10] - 1;
            }

            pontearduini_B.messaggio_size_p[0] = 1;
            loop_ub = pontearduini_B.b_i - i;
            pontearduini_B.messaggio_size_p[1] = loop_ub;
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                 pontearduini_B.b_i++) {
              pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                pontearduini_B.messaggio[i + pontearduini_B.b_i];
            }

            pontearduini_B.Lat_1 = pontearduini_str2double_a
              (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_p);
            pontearduini_B.rtb_Magnetic_declination_re = pontearduini_B.Lat_1.re;
            if (pontearduini_B.messaggio[pontearduini_B.tmp_data[10]] == 'W') {
              pontearduini_B.rtb_Magnetic_declination_re =
                -pontearduini_B.Lat_1.re;
            }

            pontearduini_B.rtb_fix_mode_re = pontearduini_B.ComplextoRealImag[5];
            pontearduini_B.rtb_n_sat_re = pontearduini_B.ComplextoRealImag[6];
            pontearduini_B.rtb_h_mean_sea_re = pontearduini_B.ComplextoRealImag
              [7];
            pontearduini_B.rtb_h_WGS84_re = pontearduini_B.ComplextoRealImag[8];
            if ((real_T)pontearduini_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)pontearduini_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)pontearduini_B.star_data[0] + 1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = pontearduini_B.messaggio[status - 1];
            if ((real_T)pontearduini_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)pontearduini_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)pontearduini_B.star_data[0] + 2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = pontearduini_B.messaggio[status - 1];
            if ((real_T)pontearduini_B.fb_data[0] + 1.0 > (real_T)
                pontearduini_B.star_data[0] - 1.0) {
              i = 0;
              pontearduini_B.b_i = 0;
            } else {
              i = pontearduini_B.fb_data[0];
              pontearduini_B.b_i = pontearduini_B.star_data[0] - 1;
            }

            loop_ub = pontearduini_B.b_i - i;
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                 pontearduini_B.b_i++) {
              pontearduini_B.NMEA_gga_string_data[pontearduini_B.b_i] = (uint8_T)
                pontearduini_B.messaggio[i + pontearduini_B.b_i];
            }

            status = 0U;
            pontearduini_B.b_i = 0;
            while (pontearduini_B.b_i <= loop_ub - 1) {
              status ^= pontearduini_B.NMEA_gga_string_data[pontearduini_B.b_i];
              pontearduini_B.b_i++;
            }

            if (status != pontearduini_hex2dec(ck_ric)) {
              pontearduini_B.rtb_Lat_re = pontearduini_B.ComplextoRealImag[0];
              pontearduini_B.rtb_Long_re = pontearduini_B.ComplextoRealImag[1];
              pontearduini_B.rtb_V_re = pontearduini_B.ComplextoRealImag[2];
              pontearduini_B.rtb_Magnetic_declination_re =
                pontearduini_B.ComplextoRealImag[3];
              pontearduini_B.rtb_heading_re = pontearduini_B.ComplextoRealImag[4];

              /* Outport: '<Root>/mario' */
              pontearduini_Y.mario = 10U;
            }
          } else {
            for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 5;
                 pontearduini_B.b_i++) {
              pontearduini_B.mess_type_j[pontearduini_B.b_i] =
                (pontearduini_B.mess_type[pontearduini_B.b_i] ==
                 cb[pontearduini_B.b_i]);
            }

            if (pontearduini_ifWhileCond(pontearduini_B.mess_type_j)) {
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_m[pontearduini_B.b_i] =
                  (pontearduini_B.messaggio[pontearduini_B.b_i] == ',');
              }

              pontearduini_eml_find_b(pontearduini_B.messaggio_m,
                pontearduini_B.comma_gga_data, pontearduini_B.eb_size);
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_m[pontearduini_B.b_i] =
                  (pontearduini_B.messaggio[pontearduini_B.b_i] == '*');
              }

              pontearduini_eml_find_b(pontearduini_B.messaggio_m,
                pontearduini_B.star_data, pontearduini_B.star_size);
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < 80;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_m[pontearduini_B.b_i] =
                  (pontearduini_B.messaggio[pontearduini_B.b_i] == '$');
              }

              pontearduini_eml_find_b(pontearduini_B.messaggio_m,
                pontearduini_B.fb_data, pontearduini_B.star_size);
              pontearduini_B.Lat_1 = pontearduini_str2double
                (&pontearduini_B.messaggio[pontearduini_B.comma_gga_data[1]]);
              if ((real_T)pontearduini_B.comma_gga_data[1] + 3.0 > (real_T)
                  pontearduini_B.comma_gga_data[2] - 1.0) {
                i = 0;
                pontearduini_B.b_i = 0;
              } else {
                i = pontearduini_B.comma_gga_data[1] + 2;
                pontearduini_B.b_i = pontearduini_B.comma_gga_data[2] - 1;
              }

              pontearduini_B.messaggio_size[0] = 1;
              loop_ub = pontearduini_B.b_i - i;
              pontearduini_B.messaggio_size[1] = loop_ub;
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                  pontearduini_B.messaggio[i + pontearduini_B.b_i];
              }

              pontearduini_B.b_x = pontearduini_str2double_a
                (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size);
              if (pontearduini_B.b_x.im == 0.0) {
                pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
              } else if (pontearduini_B.b_x.re == 0.0) {
                pontearduini_B.rtb_Long_re = 0.0;
              } else {
                pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
              }

              pontearduini_B.rtb_Lat_re = pontearduini_B.Lat_1.re +
                pontearduini_B.rtb_Long_re;
              loop_ub = pontearduini_B.eb_size[0] * pontearduini_B.eb_size[1] -
                1;
              if (0 <= loop_ub) {
                memcpy(&pontearduini_B.tmp_data[0],
                       &pontearduini_B.comma_gga_data[0], (loop_ub + 1) * sizeof
                       (int32_T));
              }

              if (pontearduini_B.messaggio[pontearduini_B.tmp_data[2]] == 'S') {
                pontearduini_B.rtb_Lat_re = -pontearduini_B.rtb_Lat_re;
              }

              pontearduini_B.Lat_1 = pontearduini_str2double_al
                (&pontearduini_B.messaggio[pontearduini_B.comma_gga_data[3]]);
              if ((real_T)pontearduini_B.comma_gga_data[3] + 4.0 > (real_T)
                  pontearduini_B.comma_gga_data[4] - 1.0) {
                i = 0;
                pontearduini_B.b_i = 0;
              } else {
                i = pontearduini_B.comma_gga_data[3] + 3;
                pontearduini_B.b_i = pontearduini_B.comma_gga_data[4] - 1;
              }

              pontearduini_B.messaggio_size_k[0] = 1;
              loop_ub = pontearduini_B.b_i - i;
              pontearduini_B.messaggio_size_k[1] = loop_ub;
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                  pontearduini_B.messaggio[i + pontearduini_B.b_i];
              }

              pontearduini_B.b_x = pontearduini_str2double_a
                (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_k);
              if (pontearduini_B.b_x.im == 0.0) {
                pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
              } else if (pontearduini_B.b_x.re == 0.0) {
                pontearduini_B.rtb_Long_re = 0.0;
              } else {
                pontearduini_B.rtb_Long_re = pontearduini_B.b_x.re / 60.0;
              }

              pontearduini_B.rtb_Long_re += pontearduini_B.Lat_1.re;
              if (pontearduini_B.messaggio[pontearduini_B.tmp_data[4]] == 'W') {
                pontearduini_B.rtb_Long_re = -pontearduini_B.rtb_Long_re;
              }

              pontearduini_B.Lat_1 = pontearduini_str2double_al0
                (pontearduini_B.messaggio[pontearduini_B.comma_gga_data[5]]);
              pontearduini_B.rtb_fix_mode_re = pontearduini_B.Lat_1.re;
              if ((real_T)pontearduini_B.comma_gga_data[6] + 1.0 > (real_T)
                  pontearduini_B.comma_gga_data[7] - 1.0) {
                i = 0;
                pontearduini_B.b_i = 0;
              } else {
                i = pontearduini_B.comma_gga_data[6];
                pontearduini_B.b_i = pontearduini_B.comma_gga_data[7] - 1;
              }

              pontearduini_B.messaggio_size_c[0] = 1;
              loop_ub = pontearduini_B.b_i - i;
              pontearduini_B.messaggio_size_c[1] = loop_ub;
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                  pontearduini_B.messaggio[i + pontearduini_B.b_i];
              }

              pontearduini_B.Lat_1 = pontearduini_str2double_a
                (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_c);
              pontearduini_B.rtb_n_sat_re = pontearduini_B.Lat_1.re;
              if ((real_T)pontearduini_B.comma_gga_data[8] + 1.0 > (real_T)
                  pontearduini_B.comma_gga_data[9] - 1.0) {
                i = 0;
                pontearduini_B.b_i = 0;
              } else {
                i = pontearduini_B.comma_gga_data[8];
                pontearduini_B.b_i = pontearduini_B.comma_gga_data[9] - 1;
              }

              pontearduini_B.messaggio_size_b[0] = 1;
              loop_ub = pontearduini_B.b_i - i;
              pontearduini_B.messaggio_size_b[1] = loop_ub;
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                  pontearduini_B.messaggio[i + pontearduini_B.b_i];
              }

              pontearduini_B.Lat_1 = pontearduini_str2double_a
                (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_b);
              pontearduini_B.rtb_h_mean_sea_re = pontearduini_B.Lat_1.re;
              if ((real_T)pontearduini_B.comma_gga_data[10] + 1.0 > (real_T)
                  pontearduini_B.comma_gga_data[11] - 1.0) {
                i = 0;
                pontearduini_B.b_i = 0;
              } else {
                i = pontearduini_B.comma_gga_data[10];
                pontearduini_B.b_i = pontearduini_B.comma_gga_data[11] - 1;
              }

              pontearduini_B.messaggio_size_p[0] = 1;
              loop_ub = pontearduini_B.b_i - i;
              pontearduini_B.messaggio_size_p[1] = loop_ub;
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                   pontearduini_B.b_i++) {
                pontearduini_B.messaggio_data[pontearduini_B.b_i] =
                  pontearduini_B.messaggio[i + pontearduini_B.b_i];
              }

              pontearduini_B.Lat_1 = pontearduini_str2double_a
                (pontearduini_B.messaggio_data, pontearduini_B.messaggio_size_p);
              pontearduini_B.rtb_h_WGS84_re = pontearduini_B.Lat_1.re;
              pontearduini_B.rtb_V_re = pontearduini_B.ComplextoRealImag[2];
              pontearduini_B.rtb_Magnetic_declination_re =
                pontearduini_B.ComplextoRealImag[3];
              pontearduini_B.rtb_heading_re = pontearduini_B.ComplextoRealImag[4];
              if ((real_T)pontearduini_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)pontearduini_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)pontearduini_B.star_data[0] + 1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = pontearduini_B.messaggio[status - 1];
              if ((real_T)pontearduini_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)pontearduini_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)pontearduini_B.star_data[0] + 2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = pontearduini_B.messaggio[status - 1];
              if ((real_T)pontearduini_B.fb_data[0] + 1.0 > (real_T)
                  pontearduini_B.star_data[0] - 1.0) {
                i = 0;
                pontearduini_B.b_i = 0;
              } else {
                i = pontearduini_B.fb_data[0];
                pontearduini_B.b_i = pontearduini_B.star_data[0] - 1;
              }

              loop_ub = pontearduini_B.b_i - i;
              for (pontearduini_B.b_i = 0; pontearduini_B.b_i < loop_ub;
                   pontearduini_B.b_i++) {
                pontearduini_B.NMEA_gga_string_data[pontearduini_B.b_i] =
                  (uint8_T)pontearduini_B.messaggio[i + pontearduini_B.b_i];
              }

              status = 0U;
              pontearduini_B.b_i = 0;
              while (pontearduini_B.b_i <= loop_ub - 1) {
                status ^= pontearduini_B.NMEA_gga_string_data[pontearduini_B.b_i];
                pontearduini_B.b_i++;
              }

              if (status != pontearduini_hex2dec(ck_ric)) {
                pontearduini_B.rtb_Lat_re = pontearduini_B.ComplextoRealImag[0];
                pontearduini_B.rtb_Long_re = pontearduini_B.ComplextoRealImag[1];
                pontearduini_B.rtb_fix_mode_re =
                  pontearduini_B.ComplextoRealImag[5];
                pontearduini_B.rtb_n_sat_re = pontearduini_B.ComplextoRealImag[6];
                pontearduini_B.rtb_h_mean_sea_re =
                  pontearduini_B.ComplextoRealImag[7];
                pontearduini_B.rtb_h_WGS84_re =
                  pontearduini_B.ComplextoRealImag[8];

                /* Outport: '<Root>/mario' */
                pontearduini_Y.mario = 20U;
              }
            } else {
              pontearduini_B.rtb_Lat_re = pontearduini_B.ComplextoRealImag[0];
              pontearduini_B.rtb_Long_re = pontearduini_B.ComplextoRealImag[1];
              pontearduini_B.rtb_V_re = pontearduini_B.ComplextoRealImag[2];
              pontearduini_B.rtb_Magnetic_declination_re =
                pontearduini_B.ComplextoRealImag[3];
              pontearduini_B.rtb_heading_re = pontearduini_B.ComplextoRealImag[4];
              pontearduini_B.rtb_fix_mode_re = pontearduini_B.ComplextoRealImag
                [5];
              pontearduini_B.rtb_n_sat_re = pontearduini_B.ComplextoRealImag[6];
              pontearduini_B.rtb_h_mean_sea_re =
                pontearduini_B.ComplextoRealImag[7];
              pontearduini_B.rtb_h_WGS84_re = pontearduini_B.ComplextoRealImag[8];
            }
          }
        } else {
          pontearduini_B.rtb_Lat_re = pontearduini_B.ComplextoRealImag[0];
          pontearduini_B.rtb_Long_re = pontearduini_B.ComplextoRealImag[1];
          pontearduini_B.rtb_V_re = pontearduini_B.ComplextoRealImag[2];
          pontearduini_B.rtb_Magnetic_declination_re =
            pontearduini_B.ComplextoRealImag[3];
          pontearduini_B.rtb_heading_re = pontearduini_B.ComplextoRealImag[4];
          pontearduini_B.rtb_fix_mode_re = pontearduini_B.ComplextoRealImag[5];
          pontearduini_B.rtb_n_sat_re = pontearduini_B.ComplextoRealImag[6];
          pontearduini_B.rtb_h_mean_sea_re = pontearduini_B.ComplextoRealImag[7];
          pontearduini_B.rtb_h_WGS84_re = pontearduini_B.ComplextoRealImag[8];
        }

        /* ComplexToRealImag: '<S4>/Complex to Real-Imag' */
        pontearduini_B.ComplextoRealImag[0] = pontearduini_B.rtb_Lat_re;
        pontearduini_B.ComplextoRealImag[1] = pontearduini_B.rtb_Long_re;
        pontearduini_B.ComplextoRealImag[2] = pontearduini_B.rtb_V_re;
        pontearduini_B.ComplextoRealImag[3] =
          pontearduini_B.rtb_Magnetic_declination_re;
        pontearduini_B.ComplextoRealImag[4] = pontearduini_B.rtb_heading_re;
        pontearduini_B.ComplextoRealImag[5] = pontearduini_B.rtb_fix_mode_re;
        pontearduini_B.ComplextoRealImag[6] = pontearduini_B.rtb_n_sat_re;
        pontearduini_B.ComplextoRealImag[7] = pontearduini_B.rtb_h_mean_sea_re;
        pontearduini_B.ComplextoRealImag[8] = pontearduini_B.rtb_h_WGS84_re;

        /* End of Outputs for SubSystem: '<S2>/Subsystem' */
      } else {
        for (i = 0; i < 32; i++) {
          pontearduini_B.b_i = (int32_T)(((uint32_T)pontearduini_DW.counter + i)
            + 1U);
          if ((uint32_T)pontearduini_B.b_i > 255U) {
            pontearduini_B.b_i = 255;
          }

          pontearduini_DW.message[pontearduini_B.b_i - 1] =
            pontearduini_B.b_dataOut[i];
        }

        pontearduini_B.b_i = (int32_T)(pontearduini_DW.counter + 32U);
        if (pontearduini_DW.counter + 32U > 255U) {
          pontearduini_B.b_i = 255;
        }

        pontearduini_DW.counter = (uint8_T)pontearduini_B.b_i;
      }
    }

    /* End of MATLAB Function: '<S2>/Create_message' */
  }

  /* End of MATLABSystem: '<Root>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Inport: '<Root>/Cal_alt' */
  if (pontearduini_U.Cal_alt > 0.0) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant3'
     *  Logic: '<S1>/OR'
     *  RelationalOperator: '<S1>/Equal'
     *  RelationalOperator: '<S1>/Equal1'
     *  RelationalOperator: '<S1>/Equal2'
     */
    if ((pontearduini_B.ComplextoRealImag[5] == pontearduini_P.Constant_Value) ||
        (pontearduini_B.ComplextoRealImag[5] == pontearduini_P.Constant1_Value) ||
        (pontearduini_B.ComplextoRealImag[5] == pontearduini_P.Constant3_Value))
    {
      /* Switch: '<S1>/Switch' */
      pontearduini_B.Switch = pontearduini_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      pontearduini_B.Switch = pontearduini_P.Constant2_Value;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* End of Inport: '<Root>/Cal_alt' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* MATLABSystem: '<Root>/Serial Transmit1' incorporates:
   *  SignalConversion generated from: '<Root>/Serial Transmit1'
   *  Sum: '<Root>/Sum'
   */
  if (pontearduini_DW.obj.Protocol != pontearduini_P.SerialTransmit1_Protocol) {
    pontearduini_DW.obj.Protocol = pontearduini_P.SerialTransmit1_Protocol;
  }

  pontearduini_B.dataIn[0] = pontearduini_B.ComplextoRealImag[0];
  pontearduini_B.dataIn[1] = pontearduini_B.ComplextoRealImag[1];
  pontearduini_B.dataIn[2] = pontearduini_B.ComplextoRealImag[2];
  pontearduini_B.dataIn[3] = pontearduini_B.ComplextoRealImag[7] -
    pontearduini_B.Switch;
  pontearduini_B.dataIn[4] = pontearduini_B.ComplextoRealImag[4];
  pontearduini_B.dataIn[5] = pontearduini_B.ComplextoRealImag[5];
  MW_Serial_write(pontearduini_DW.obj.port, &pontearduini_B.dataIn[0], 6.0,
                  pontearduini_DW.obj.dataSizeInBytes,
                  pontearduini_DW.obj.sendModeEnum, pontearduini_DW.obj.dataType,
                  pontearduini_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit1' */
}

/* Model initialize function */
void pontearduini_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T tmp;
    int32_T i;
    uint8_T tmp_0;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S4>/Memory' */
      pontearduini_B.ComplextoRealImag[i] =
        pontearduini_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S4>/Complex to Real-Imag' incorporates:
       *  Outport: '<S4>/Outport'
       */
      pontearduini_B.ComplextoRealImag[i] = pontearduini_P.Outport_Y0;
    }

    /* SystemInitialize for Outport: '<Root>/mario' incorporates:
     *  Outport: '<S4>/mario'
     */
    pontearduini_Y.mario = pontearduini_P.mario_Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* SystemInitialize for Switch: '<S1>/Switch' incorporates:
     *  Outport: '<S1>/h_to_subtract'
     */
    pontearduini_B.Switch = pontearduini_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* Start for MATLABSystem: '<Root>/Serial Receive1' */
    pontearduini_DW.obj_n.matlabCodegenIsDeleted = false;
    pontearduini_DW.obj_n.Protocol = pontearduini_P.SerialReceive1_Protocol;
    pontearduini_DW.obj_n.isInitialized = 1;
    pontearduini_DW.obj_n.DataTypeWidth = 1U;
    if (pontearduini_DW.obj_n.DataTypeWidth > 2047) {
      pontearduini_DW.obj_n.DataSizeInBytes = MAX_uint16_T;
    } else {
      pontearduini_DW.obj_n.DataSizeInBytes = (uint16_T)
        (pontearduini_DW.obj_n.DataTypeWidth << 5);
    }

    MW_SCI_Open(3);
    pontearduini_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive1' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit1' */
    pontearduini_DW.obj.matlabCodegenIsDeleted = false;
    pontearduini_DW.obj.Protocol = pontearduini_P.SerialTransmit1_Protocol;
    pontearduini_DW.obj.isInitialized = 1;
    pontearduini_DW.obj.port = 0.0;
    pontearduini_DW.obj.dataSizeInBytes = 8.0;
    pontearduini_DW.obj.dataType = 6.0;
    pontearduini_DW.obj.sendModeEnum = 2.0;
    pontearduini_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(pontearduini_DW.obj.port);
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
    pontearduini_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit1' */
  }
}

/* Model terminate function */
void pontearduini_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive1' */
  if (!pontearduini_DW.obj_n.matlabCodegenIsDeleted) {
    pontearduini_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit1' */
  if (!pontearduini_DW.obj.matlabCodegenIsDeleted) {
    pontearduini_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
