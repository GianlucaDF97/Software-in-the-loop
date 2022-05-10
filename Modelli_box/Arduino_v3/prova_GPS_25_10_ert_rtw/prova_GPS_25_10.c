/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_GPS_25_10.c
 *
 * Code generated for Simulink model 'prova_GPS_25_10'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 26 10:31:08 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_GPS_25_10.h"
#include "prova_GPS_25_10_private.h"

const uint16_T prova_GPS_25_10_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_prova_GPS_25_10_T prova_GPS_25_10_B;

/* Block states (default storage) */
DW_prova_GPS_25_10_T prova_GPS_25_10_DW;

/* Real-time model */
static RT_MODEL_prova_GPS_25_10_T prova_GPS_25_10_M_;
RT_MODEL_prova_GPS_25_10_T *const prova_GPS_25_10_M = &prova_GPS_25_10_M_;

/* Forward declaration for local functions */
static void prova_GPS_25_10_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter);
static boolean_T prova_GPS_25_10_ifWhileCond(const boolean_T x[100]);
static void prova_GPS_25_10_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T prova_GPS_25_10_ifWhileCond_h(const boolean_T x[5]);
static void prova_GPS_25_10_eml_find_a(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void prova_GPS_25_10_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_GPS_25_10_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T prova_GPS_25_10_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k);
static void prova_GPS_25_10_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_GPS_25_10_str2double(const char_T s[2]);
static boolean_T prova_GPS_25_10_copydigits_o(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void prova_GPS_25_10_readfloat_e(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_GPS_25_10_str2double_f(const char_T s_data[], const int32_T
  s_size[2]);
static boolean_T prova_GPS_25_10_isUnitImag(const char_T s[3], int32_T k);
static void prova_GPS_25_10_readNonFinite_p(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_GPS_25_10_copydigits_o4(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T prova_GPS_25_10_copyexponent_e(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void prova_GPS_25_10_readfloat_em(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_GPS_25_10_str2double_ft(const char_T s[3]);
static void prova_GPS_25_1_readNonFinite_pn(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T prova_GPS_25_10_copydigits_o4q(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T prova_GPS_25_10_copyexponent_ew(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void prova_GPS_25_10_readfloat_eml(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_GPS_25_10_str2double_ftn(char_T s);
static real_T prova_GPS_25_10_hex2dec(const char_T s[2]);
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
void prova_GPS_25_10_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(prova_GPS_25_10_M, 1));
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
  (prova_GPS_25_10_M->Timing.TaskCounters.TID[1])++;
  if ((prova_GPS_25_10_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    prova_GPS_25_10_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void prova_GPS_25_10_find_254(const uint8_T pack[100], real_T position[3],
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
static boolean_T prova_GPS_25_10_ifWhileCond(const boolean_T x[100])
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_ifWhileCond_h(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_eml_find_a(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copydigits(char_T s1[4], int32_T *idx, const
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copyexponent(char_T s1[4], int32_T *idx, const
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
      b_success = prova_GPS_25_10_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
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
            prova_GPS_25_10_readfloat(s1, idx, s, k, false, &isneg, b_finite,
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
      prova_GPS_25_10_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_GPS_25_10_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = prova_GPS_25_10_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static creal_T prova_GPS_25_10_str2double(const char_T s[2])
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
  prova_GPS_25_10_B.scanned1_g = 0.0;
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
        prova_GPS_25_10_readfloat(s1, &idx, s, &e_k, false, &isneg, &b_finite,
          &prova_GPS_25_10_B.scanned1_g, &unusedU2, &success);
      } else {
        s1[idx - 1] = '1';
        idx++;
      }
    } else {
      e_k = k + 1;
      prova_GPS_25_10_readNonFinite(s, &e_k, &b_finite,
        &prova_GPS_25_10_B.scanned1_g);
      if (b_finite) {
        success = prova_GPS_25_10_copydigits(s1, &idx, s, &e_k, true);
        if (success) {
          success = prova_GPS_25_10_copyexponent(s1, &idx, s, &e_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          prova_GPS_25_10_B.scanned1_g = -prova_GPS_25_10_B.scanned1_g;
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
    prova_GPS_25_10_readfloat(s1, &idx, s, &e_k, true, &success, &isneg,
      &prova_GPS_25_10_B.scanned2_m, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (e_k > 2) && (isimag1 != success) && unusedU2);
  } else {
    prova_GPS_25_10_B.scanned2_m = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &prova_GPS_25_10_B.scanned1_g,
                       &prova_GPS_25_10_B.scanned2_m);
      if (ntoread != 2) {
        prova_GPS_25_10_B.scanned1_g = (rtNaN);
        prova_GPS_25_10_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &prova_GPS_25_10_B.b_scanned1_n);
      if (b_finite) {
        if (ntoread == 1) {
          prova_GPS_25_10_B.scanned1_g = prova_GPS_25_10_B.b_scanned1_n;
        } else {
          prova_GPS_25_10_B.scanned1_g = (rtNaN);
        }
      } else if (ntoread == 1) {
        prova_GPS_25_10_B.scanned2_m = prova_GPS_25_10_B.b_scanned1_n;
      } else {
        prova_GPS_25_10_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_GPS_25_10_B.scanned2_m;
      x.im = prova_GPS_25_10_B.scanned1_g;
    } else {
      x.re = prova_GPS_25_10_B.scanned1_g;
      x.im = prova_GPS_25_10_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copydigits_o(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_readfloat_e(char_T s1_data[], int32_T *idx, const
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
          prova_GPS_25_10_readfloat_e(s1_data, idx, s_data, k, n, false, &isneg,
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
        *success = prova_GPS_25_10_copydigits_o(s1_data, &b_idx, s_data, &h_k, n,
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
              isneg = prova_GPS_25_10_copydigits_o(s1_data, idx, s_data, &b_idx,
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static creal_T prova_GPS_25_10_str2double_f(const char_T s_data[], const int32_T
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

    prova_GPS_25_10_B.s1_size[0] = 1;
    prova_GPS_25_10_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= idx) {
      memset(&prova_GPS_25_10_B.s1_data[0], 0, (idx + 1) * sizeof(char_T));
    }

    idx = 1;
    prova_GPS_25_10_readfloat_e(prova_GPS_25_10_B.s1_data, &idx, s_data, &k,
      s_size[1], true, &isimag1, &isfinite1, &prova_GPS_25_10_B.scanned1,
      &unusedU0, &success);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success) {
      if (k <= s_size[1]) {
        prova_GPS_25_10_B.s1_data[idx - 1] = ' ';
        idx++;
        prova_GPS_25_10_readfloat_e(prova_GPS_25_10_B.s1_data, &idx, s_data, &k,
          s_size[1], true, &unusedU0, &success, &prova_GPS_25_10_B.scanned2,
          &foundsign, &c_success);
        if (success) {
          ntoread++;
        }

        success = (c_success && ((k > s_size[1]) && ((isimag1 != unusedU0) &&
          foundsign)));
      } else {
        prova_GPS_25_10_B.scanned2 = 0.0;
      }
    } else {
      prova_GPS_25_10_B.scanned2 = 0.0;
    }

    if (success) {
      prova_GPS_25_10_B.s1_data[idx - 1] = '\x00';
      switch (ntoread) {
       case 2:
        ntoread = sscanf(&prova_GPS_25_10_B.s1_data[0], "%lf %lf",
                         &prova_GPS_25_10_B.scanned1,
                         &prova_GPS_25_10_B.scanned2);
        if (ntoread != 2) {
          prova_GPS_25_10_B.scanned1 = (rtNaN);
          prova_GPS_25_10_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        ntoread = sscanf(&prova_GPS_25_10_B.s1_data[0], "%lf",
                         &prova_GPS_25_10_B.b_scanned1);
        if (isfinite1) {
          if (ntoread == 1) {
            prova_GPS_25_10_B.scanned1 = prova_GPS_25_10_B.b_scanned1;
          } else {
            prova_GPS_25_10_B.scanned1 = (rtNaN);
          }
        } else if (ntoread == 1) {
          prova_GPS_25_10_B.scanned2 = prova_GPS_25_10_B.b_scanned1;
        } else {
          prova_GPS_25_10_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = prova_GPS_25_10_B.scanned2;
        x.im = prova_GPS_25_10_B.scanned1;
      } else {
        x.re = prova_GPS_25_10_B.scanned1;
        x.im = prova_GPS_25_10_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_readNonFinite_p(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copydigits_o4(char_T s1[5], int32_T *idx, const
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copyexponent_e(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k)
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
      b_success = prova_GPS_25_10_copydigits_o4(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_readfloat_em(char_T s1[5], int32_T *idx, const
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
    if (prova_GPS_25_10_isUnitImag(s, b_k)) {
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
          prova_GPS_25_10_readfloat_em(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      prova_GPS_25_10_readNonFinite_p(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_GPS_25_10_copydigits_o4(s1, idx, s, k, true);
        if (*success) {
          *success = prova_GPS_25_10_copyexponent_e(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static creal_T prova_GPS_25_10_str2double_ft(const char_T s[3])
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
  prova_GPS_25_10_B.scanned1_c = 0.0;
  idx = 1;
  for (b_k = 0; b_k < 5; b_k++) {
    prova_GPS_25_10_B.s1[b_k] = '\x00';
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
    prova_GPS_25_10_B.s1[0] = '-';
    idx = 2;
  }

  b_k = k - 1;
  if (success) {
    if (prova_GPS_25_10_isUnitImag(s, k)) {
      isimag1 = true;
      b_k = k;
      while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00') ||
              (s[b_k] == ','))) {
        b_k++;
      }

      if ((b_k + 1 <= 3) && (s[b_k] == '*')) {
        k = b_k + 2;
        prova_GPS_25_10_readfloat_em(prova_GPS_25_10_B.s1, &idx, s, &k, false,
          &isneg, &b_finite, &prova_GPS_25_10_B.scanned1_c, &unusedU2, &success);
        b_k = k - 1;
      } else {
        prova_GPS_25_10_B.s1[idx - 1] = '1';
        idx++;
      }
    } else {
      prova_GPS_25_10_readNonFinite_p(s, &k, &b_finite,
        &prova_GPS_25_10_B.scanned1_c);
      b_k = k - 1;
      if (b_finite) {
        success = prova_GPS_25_10_copydigits_o4(prova_GPS_25_10_B.s1, &idx, s,
          &k, true);
        b_k = k - 1;
        if (success) {
          success = prova_GPS_25_10_copyexponent_e(prova_GPS_25_10_B.s1, &idx, s,
            &k);
          b_k = k - 1;
        }
      } else {
        if ((idx >= 2) && (prova_GPS_25_10_B.s1[0] == '-')) {
          idx = 1;
          prova_GPS_25_10_B.s1[0] = ' ';
          prova_GPS_25_10_B.scanned1_c = -prova_GPS_25_10_B.scanned1_c;
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
    prova_GPS_25_10_B.s1[idx - 1] = ' ';
    idx++;
    k = b_k + 1;
    prova_GPS_25_10_readfloat_em(prova_GPS_25_10_B.s1, &idx, s, &k, true,
      &success, &isneg, &prova_GPS_25_10_B.scanned2_f, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (k > 3) && (isimag1 != success) && unusedU2);
  } else {
    prova_GPS_25_10_B.scanned2_f = 0.0;
  }

  if (success) {
    prova_GPS_25_10_B.s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&prova_GPS_25_10_B.s1[0], "%lf %lf",
                       &prova_GPS_25_10_B.scanned1_c,
                       &prova_GPS_25_10_B.scanned2_f);
      if (ntoread != 2) {
        prova_GPS_25_10_B.scanned1_c = (rtNaN);
        prova_GPS_25_10_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&prova_GPS_25_10_B.s1[0], "%lf",
                       &prova_GPS_25_10_B.b_scanned1_g);
      if (b_finite) {
        if (ntoread == 1) {
          prova_GPS_25_10_B.scanned1_c = prova_GPS_25_10_B.b_scanned1_g;
        } else {
          prova_GPS_25_10_B.scanned1_c = (rtNaN);
        }
      } else if (ntoread == 1) {
        prova_GPS_25_10_B.scanned2_f = prova_GPS_25_10_B.b_scanned1_g;
      } else {
        prova_GPS_25_10_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_GPS_25_10_B.scanned2_f;
      x.im = prova_GPS_25_10_B.scanned1_c;
    } else {
      x.re = prova_GPS_25_10_B.scanned1_c;
      x.im = prova_GPS_25_10_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_1_readNonFinite_pn(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copydigits_o4q(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static boolean_T prova_GPS_25_10_copyexponent_ew(char_T s1[3], int32_T *idx,
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
    b_success = prova_GPS_25_10_copydigits_o4q(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static void prova_GPS_25_10_readfloat_eml(char_T s1[3], int32_T *idx, char_T s,
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
          prova_GPS_25_10_readfloat_eml(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      prova_GPS_25_1_readNonFinite_pn(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = prova_GPS_25_10_copydigits_o4q(s1, idx, s, k, true);
        if (*success) {
          *success = prova_GPS_25_10_copyexponent_ew(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static creal_T prova_GPS_25_10_str2double_ftn(char_T s)
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
  prova_GPS_25_10_B.scanned1_p = 0.0;
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
      prova_GPS_25_1_readNonFinite_pn(s, &d_k, &b_finite,
        &prova_GPS_25_10_B.scanned1_p);
      if (b_finite) {
        success = prova_GPS_25_10_copydigits_o4q(s1, &idx, s, &d_k, true);
        if (success) {
          success = prova_GPS_25_10_copyexponent_ew(s1, &idx, s, &d_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          prova_GPS_25_10_B.scanned1_p = -prova_GPS_25_10_B.scanned1_p;
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
    prova_GPS_25_10_readfloat_eml(s1, &idx, s, &d_k, true, &success, &isneg,
      &prova_GPS_25_10_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (d_k > 1) && (isimag1 != success) && foundsign);
  } else {
    prova_GPS_25_10_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &prova_GPS_25_10_B.scanned1_p,
                       &prova_GPS_25_10_B.scanned2_l);
      if (ntoread != 2) {
        prova_GPS_25_10_B.scanned1_p = (rtNaN);
        prova_GPS_25_10_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (b_finite) {
        if (ntoread == 1) {
          prova_GPS_25_10_B.scanned1_p = b_scanned1;
        } else {
          prova_GPS_25_10_B.scanned1_p = (rtNaN);
        }
      } else if (ntoread == 1) {
        prova_GPS_25_10_B.scanned2_l = b_scanned1;
      } else {
        prova_GPS_25_10_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_GPS_25_10_B.scanned2_l;
      x.im = prova_GPS_25_10_B.scanned1_p;
    } else {
      x.re = prova_GPS_25_10_B.scanned1_p;
      x.im = prova_GPS_25_10_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S22>/MATLAB Function' */
static real_T prova_GPS_25_10_hex2dec(const char_T s[2])
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

  prova_GPS_25_10_B.a = tmp_1;
  prova_GPS_25_10_B.p16 = tmp_2;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_3;
      MultiWordSub(&tmp.chunks[0U], &tmp_3.chunks[0U],
                   &prova_GPS_25_10_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_4;
      MultiWordSub(&tmp.chunks[0U], &tmp_4.chunks[0U],
                   &prova_GPS_25_10_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
        tmp_0 = tmp_5;
        MultiWordSub(&tmp.chunks[0U], &tmp_5.chunks[0U],
                     &prova_GPS_25_10_B.sk.chunks[0U], 2);
      } else {
        prova_GPS_25_10_B.sk = tmp_1;
      }
    } else {
      prova_GPS_25_10_B.sk = tmp_1;
    }

    uMultiWordMul(&prova_GPS_25_10_B.sk.chunks[0U], 2,
                  &prova_GPS_25_10_B.p16.chunks[0U], 2,
                  &prova_GPS_25_10_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&prova_GPS_25_10_B.r.chunks[0U], 4, &tmp.chunks[0U], 2);
    MultiWordAdd(&prova_GPS_25_10_B.a.chunks[0U], &tmp.chunks[0U],
                 &tmp_0.chunks[0U], 2);
    prova_GPS_25_10_B.a = tmp_0;
    uMultiWord2MultiWord(&prova_GPS_25_10_B.p16.chunks[0U], 2,
                         &prova_GPS_25_10_B.r2.chunks[0U], 3);
    uMultiWordShl(&prova_GPS_25_10_B.r2.chunks[0U], 3, 4U,
                  &prova_GPS_25_10_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&prova_GPS_25_10_B.r1.chunks[0U], 3,
                         &prova_GPS_25_10_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&prova_GPS_25_10_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&prova_GPS_25_10_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&prova_GPS_25_10_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&prova_GPS_25_10_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&prova_GPS_25_10_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&prova_GPS_25_10_B.a.chunks[0U], 2, 0);
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
void prova_GPS_25_10_step0(void)       /* Sample time: [0.02s, 0.0s] */
{
  static const char_T bb[5] = { 'G', 'P', 'R', 'M', 'C' };

  static const char_T cb[5] = { 'G', 'P', 'G', 'G', 'A' };

  int32_T exitg3;
  uint16_T x;
  uint16_T z;
  char_T ck_ric[2];
  char_T messaggio;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T counter;
  uint8_T find_comma;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T y;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&prova_GPS_25_10_P.Constant1_Value_i,
    &prova_GPS_25_10_B.SFunctionBuilder_o1[0],
    &prova_GPS_25_10_B.SFunctionBuilder_o2,
    &prova_GPS_25_10_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  prova_GPS_25_10_B.status = 0;
  prova_GPS_25_10_B.caso = 0;
  memset(&prova_GPS_25_10_B.messaggio_l[0], 0, 100U * sizeof(uint8_T));
  memset(&prova_GPS_25_10_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  prova_GPS_25_10_find_254(prova_GPS_25_10_B.SFunctionBuilder_o1,
    prova_GPS_25_10_B.poss_254, &prova_GPS_25_10_B.num_254);
  if (prova_GPS_25_10_DW.Interr_parz && (prova_GPS_25_10_B.num_254 == 1.0)) {
    prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_DW.counter_m + 1U);
    if (prova_GPS_25_10_DW.counter_m + 1U > 255U) {
      prova_GPS_25_10_B.f_d = 255;
    }

    if (prova_GPS_25_10_B.poss_254[0] != prova_GPS_25_10_B.f_d) {
      prova_GPS_25_10_B.num_254 = 0.0;
    }
  }

  y = !prova_GPS_25_10_DW.Interr_parz;
  if ((prova_GPS_25_10_B.num_254 == 1.0) && y) {
    prova_GPS_25_10_B.caso = 1;
  } else if ((prova_GPS_25_10_B.num_254 == 0.0) &&
             prova_GPS_25_10_DW.Interr_parz) {
    prova_GPS_25_10_B.caso = 2;
  } else if ((prova_GPS_25_10_B.num_254 == 1.0) &&
             prova_GPS_25_10_DW.Interr_parz) {
    prova_GPS_25_10_B.caso = 3;
  } else {
    if ((prova_GPS_25_10_B.num_254 == 2.0) && y) {
      prova_GPS_25_10_B.caso = 4;
    }
  }

  switch (prova_GPS_25_10_B.caso) {
   case 1:
    prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_B.poss_254[(int32_T)
      prova_GPS_25_10_B.num_254 - 1];
    if (prova_GPS_25_10_B.RateTransition == 100.0) {
      prova_GPS_25_10_DW.message_e[0] = prova_GPS_25_10_B.SFunctionBuilder_o1[99];
      prova_GPS_25_10_DW.Interr_parz = true;
    } else if (prova_GPS_25_10_B.SFunctionBuilder_o1[(int32_T)
               (prova_GPS_25_10_B.RateTransition + 1.0) - 1] <= 100) {
      prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.SFunctionBuilder_o1
        [(int32_T)(prova_GPS_25_10_B.poss_254[0] + 1.0) - 1] + 8U);
      prova_GPS_25_10_B.i_g = prova_GPS_25_10_B.f_d;
      if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
        prova_GPS_25_10_B.i_g = 255;
      }

      if (prova_GPS_25_10_B.i_g == prova_GPS_25_10_B.SFunctionBuilder_o2) {
        prova_GPS_25_10_B.num_254 = rt_roundd_snf
          (prova_GPS_25_10_B.RateTransition);
        if (prova_GPS_25_10_B.num_254 < 256.0) {
          if (prova_GPS_25_10_B.num_254 >= 0.0) {
            counter = (uint8_T)prova_GPS_25_10_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.SFunctionBuilder_o1
          [(int32_T)(prova_GPS_25_10_B.RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
          prova_GPS_25_10_B.f_d = 255;
        }

        prova_GPS_25_10_B.RateTransition = rt_roundd_snf
          (prova_GPS_25_10_B.RateTransition + (real_T)prova_GPS_25_10_B.f_d);
        if (prova_GPS_25_10_B.RateTransition < 256.0) {
          if (prova_GPS_25_10_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)prova_GPS_25_10_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          prova_GPS_25_10_B.i = 0;
          prova_GPS_25_10_B.f_d = 0;
        } else {
          prova_GPS_25_10_B.i = counter - 1;
          prova_GPS_25_10_B.f_d = find_comma;
        }

        prova_GPS_25_10_B.caso = prova_GPS_25_10_B.f_d - prova_GPS_25_10_B.i;
        for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
             prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.f_d] =
            prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.i +
            prova_GPS_25_10_B.f_d];
        }

        prova_GPS_25_10_B.status = 1;
        for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 100;
             prova_GPS_25_10_B.i++) {
          prova_GPS_25_10_B.messaggio_l[prova_GPS_25_10_B.i] =
            prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i];
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i] = 0U;
        }

        prova_GPS_25_10_DW.counter_m = 0U;
        prova_GPS_25_10_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
          prova_GPS_25_10_B.f_d = 255;
        }

        if (prova_GPS_25_10_B.f_d > prova_GPS_25_10_B.SFunctionBuilder_o2) {
          prova_GPS_25_10_DW.mess_len = prova_GPS_25_10_B.SFunctionBuilder_o2;
          if (prova_GPS_25_10_B.RateTransition > prova_GPS_25_10_DW.mess_len) {
            prova_GPS_25_10_B.i = 0;
            prova_GPS_25_10_B.f_d = 0;
          } else {
            prova_GPS_25_10_B.i = (int32_T)prova_GPS_25_10_B.RateTransition - 1;
            prova_GPS_25_10_B.f_d = (int32_T)prova_GPS_25_10_DW.mess_len;
          }

          prova_GPS_25_10_B.caso = prova_GPS_25_10_B.f_d - prova_GPS_25_10_B.i;
          for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
               prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
            prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.f_d] =
              prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.i +
              prova_GPS_25_10_B.f_d];
          }

          prova_GPS_25_10_B.f_d = (int32_T)
            (prova_GPS_25_10_B.SFunctionBuilder_o1[(int32_T)
             (prova_GPS_25_10_B.RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
            prova_GPS_25_10_B.f_d = 255;
          }

          prova_GPS_25_10_B.RateTransition = rt_roundd_snf((real_T)
            prova_GPS_25_10_B.f_d - prova_GPS_25_10_DW.mess_len);
          if (prova_GPS_25_10_B.RateTransition < 256.0) {
            if (prova_GPS_25_10_B.RateTransition >= 0.0) {
              prova_GPS_25_10_DW.counter_m = (uint8_T)
                prova_GPS_25_10_B.RateTransition;
            } else {
              prova_GPS_25_10_DW.counter_m = 0U;
            }
          } else {
            prova_GPS_25_10_DW.counter_m = MAX_uint8_T;
          }

          prova_GPS_25_10_DW.Interr_parz = true;
        }
      }
    } else {
      prova_GPS_25_10_DW.Interr_parz = false;
      memset(&prova_GPS_25_10_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      prova_GPS_25_10_DW.counter_m = 0U;
      prova_GPS_25_10_DW.mess_len = 0.0;
      prova_GPS_25_10_B.status = 1;
    }
    break;

   case 2:
    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.x[prova_GPS_25_10_B.f_d] =
        (prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.f_d] != 0);
    }

    if (prova_GPS_25_10_ifWhileCond(prova_GPS_25_10_B.x)) {
      prova_GPS_25_10_B.RateTransition = rt_roundd_snf
        (prova_GPS_25_10_DW.mess_len + 1.0);
      if (prova_GPS_25_10_B.RateTransition < 256.0) {
        if (prova_GPS_25_10_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)prova_GPS_25_10_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      prova_GPS_25_10_B.RateTransition = rt_roundd_snf
        (prova_GPS_25_10_DW.mess_len + (real_T)prova_GPS_25_10_DW.counter_m);
      if (prova_GPS_25_10_B.RateTransition < 256.0) {
        if (prova_GPS_25_10_B.RateTransition >= 0.0) {
          counter = (uint8_T)prova_GPS_25_10_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (find_comma > counter) {
        prova_GPS_25_10_B.status = 1;
      } else {
        prova_GPS_25_10_B.status = find_comma;
      }

      if (1 > prova_GPS_25_10_DW.counter_m) {
        prova_GPS_25_10_B.caso = -1;
      } else {
        prova_GPS_25_10_B.caso = prova_GPS_25_10_DW.counter_m - 1;
      }

      for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <=
           prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
        prova_GPS_25_10_DW.message_e[(prova_GPS_25_10_B.status +
          prova_GPS_25_10_B.f_d) - 1] =
          prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.f_d];
      }

      prova_GPS_25_10_DW.Interr_parz = false;
      prova_GPS_25_10_B.status = 1;
      for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 100;
           prova_GPS_25_10_B.i++) {
        prova_GPS_25_10_B.messaggio_l[prova_GPS_25_10_B.i] =
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i];
        prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i] = 0U;
      }

      prova_GPS_25_10_DW.mess_len = 0.0;
      prova_GPS_25_10_DW.counter_m = 0U;
    } else {
      prova_GPS_25_10_DW.Interr_parz = false;
      prova_GPS_25_10_B.status = 1;
      memset(&prova_GPS_25_10_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      prova_GPS_25_10_DW.mess_len = 0.0;
      prova_GPS_25_10_DW.counter_m = 0U;
    }
    break;

   case 3:
    prova_GPS_25_10_B.RateTransition = rt_roundd_snf(prova_GPS_25_10_DW.mess_len
      + 1.0);
    if (prova_GPS_25_10_B.RateTransition < 256.0) {
      if (prova_GPS_25_10_B.RateTransition >= 0.0) {
        find_comma = (uint8_T)prova_GPS_25_10_B.RateTransition;
      } else {
        find_comma = 0U;
      }
    } else {
      find_comma = MAX_uint8_T;
    }

    prova_GPS_25_10_B.RateTransition = rt_roundd_snf(prova_GPS_25_10_DW.mess_len
      + (real_T)prova_GPS_25_10_DW.counter_m);
    if (prova_GPS_25_10_B.RateTransition < 256.0) {
      if (prova_GPS_25_10_B.RateTransition >= 0.0) {
        counter = (uint8_T)prova_GPS_25_10_B.RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (find_comma > counter) {
      prova_GPS_25_10_B.i = 1;
    } else {
      prova_GPS_25_10_B.i = find_comma;
    }

    if (1 > prova_GPS_25_10_DW.counter_m) {
      prova_GPS_25_10_B.caso = -1;
    } else {
      prova_GPS_25_10_B.caso = prova_GPS_25_10_DW.counter_m - 1;
    }

    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <=
         prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_DW.message_e[(prova_GPS_25_10_B.i + prova_GPS_25_10_B.f_d)
        - 1] = prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.f_d];
    }

    prova_GPS_25_10_DW.Interr_parz = false;
    prova_GPS_25_10_B.status = 1;
    for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 100; prova_GPS_25_10_B.i
         ++) {
      prova_GPS_25_10_B.messaggio_l[prova_GPS_25_10_B.i] =
        prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i];
      prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i] = 0U;
    }

    prova_GPS_25_10_DW.mess_len = 0.0;
    prova_GPS_25_10_DW.counter_m = 0U;
    prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.poss_254[(int32_T)
      prova_GPS_25_10_B.num_254 - 1] + 1.0) - 1;
    if (prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.f_d] <= 100) {
      prova_GPS_25_10_B.i_g = (int32_T)(prova_GPS_25_10_B.SFunctionBuilder_o1
        [(int32_T)(prova_GPS_25_10_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)prova_GPS_25_10_B.i_g > 255U) {
        prova_GPS_25_10_B.i_g = 255;
      }

      prova_GPS_25_10_B.caso = prova_GPS_25_10_B.SFunctionBuilder_o2;
      if (prova_GPS_25_10_B.SFunctionBuilder_o2 < 0) {
        prova_GPS_25_10_B.caso = 0;
      } else {
        if (prova_GPS_25_10_B.SFunctionBuilder_o2 > 255) {
          prova_GPS_25_10_B.caso = 255;
        }
      }

      if (prova_GPS_25_10_B.i_g == prova_GPS_25_10_B.caso) {
        prova_GPS_25_10_B.RateTransition = rt_roundd_snf
          (prova_GPS_25_10_B.poss_254[(int32_T)prova_GPS_25_10_B.num_254 - 1]);
        if (prova_GPS_25_10_B.RateTransition < 256.0) {
          if (prova_GPS_25_10_B.RateTransition >= 0.0) {
            counter = (uint8_T)prova_GPS_25_10_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        prova_GPS_25_10_B.f_d = (int32_T)
          (prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.f_d] + 7U);
        if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
          prova_GPS_25_10_B.f_d = 255;
        }

        prova_GPS_25_10_B.RateTransition = rt_roundd_snf
          (prova_GPS_25_10_B.poss_254[(int32_T)prova_GPS_25_10_B.num_254 - 1] +
           (real_T)prova_GPS_25_10_B.f_d);
        if (prova_GPS_25_10_B.RateTransition < 256.0) {
          if (prova_GPS_25_10_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)prova_GPS_25_10_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          prova_GPS_25_10_B.i = 0;
          prova_GPS_25_10_B.f_d = 0;
        } else {
          prova_GPS_25_10_B.i = counter - 1;
          prova_GPS_25_10_B.f_d = find_comma;
        }

        prova_GPS_25_10_B.caso = prova_GPS_25_10_B.f_d - prova_GPS_25_10_B.i;
        for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
             prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.f_d] =
            prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.i +
            prova_GPS_25_10_B.f_d];
        }

        for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 100;
             prova_GPS_25_10_B.i++) {
          prova_GPS_25_10_B.messaggio_2[prova_GPS_25_10_B.i] =
            prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i];
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i] = 0U;
        }

        prova_GPS_25_10_DW.counter_m = 0U;
        prova_GPS_25_10_DW.mess_len = 0.0;
      } else {
        prova_GPS_25_10_B.i_g = (int32_T)(prova_GPS_25_10_B.SFunctionBuilder_o1
          [(int32_T)(prova_GPS_25_10_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)prova_GPS_25_10_B.i_g > 255U) {
          prova_GPS_25_10_B.i_g = 255;
        }

        prova_GPS_25_10_B.caso = prova_GPS_25_10_B.SFunctionBuilder_o2;
        if (prova_GPS_25_10_B.SFunctionBuilder_o2 < 0) {
          prova_GPS_25_10_B.caso = 0;
        } else {
          if (prova_GPS_25_10_B.SFunctionBuilder_o2 > 255) {
            prova_GPS_25_10_B.caso = 255;
          }
        }

        if (prova_GPS_25_10_B.i_g > prova_GPS_25_10_B.caso) {
          prova_GPS_25_10_DW.mess_len = prova_GPS_25_10_B.SFunctionBuilder_o2;
          if (prova_GPS_25_10_B.poss_254[(int32_T)prova_GPS_25_10_B.num_254 - 1]
              > prova_GPS_25_10_DW.mess_len) {
            prova_GPS_25_10_B.i = 0;
            prova_GPS_25_10_B.caso = 0;
          } else {
            prova_GPS_25_10_B.i = (int32_T)prova_GPS_25_10_B.poss_254[(int32_T)
              prova_GPS_25_10_B.num_254 - 1] - 1;
            prova_GPS_25_10_B.caso = (int32_T)prova_GPS_25_10_DW.mess_len;
          }

          prova_GPS_25_10_B.caso -= prova_GPS_25_10_B.i;
          for (prova_GPS_25_10_B.i_g = 0; prova_GPS_25_10_B.i_g <
               prova_GPS_25_10_B.caso; prova_GPS_25_10_B.i_g++) {
            prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i_g] =
              prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.i +
              prova_GPS_25_10_B.i_g];
          }

          prova_GPS_25_10_B.f_d = (int32_T)
            (prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.f_d] + 8U);
          if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
            prova_GPS_25_10_B.f_d = 255;
          }

          prova_GPS_25_10_B.RateTransition = rt_roundd_snf((real_T)
            prova_GPS_25_10_B.f_d - prova_GPS_25_10_DW.mess_len);
          if (prova_GPS_25_10_B.RateTransition < 256.0) {
            if (prova_GPS_25_10_B.RateTransition >= 0.0) {
              prova_GPS_25_10_DW.counter_m = (uint8_T)
                prova_GPS_25_10_B.RateTransition;
            } else {
              prova_GPS_25_10_DW.counter_m = 0U;
            }
          } else {
            prova_GPS_25_10_DW.counter_m = MAX_uint8_T;
          }

          prova_GPS_25_10_DW.Interr_parz = true;
        }
      }
    } else {
      prova_GPS_25_10_DW.Interr_parz = false;
      memset(&prova_GPS_25_10_B.messaggio_l[0], 0, 100U * sizeof(uint8_T));
      memset(&prova_GPS_25_10_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      prova_GPS_25_10_DW.counter_m = 0U;
      prova_GPS_25_10_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (prova_GPS_25_10_B.SFunctionBuilder_o1[(int32_T)
        (prova_GPS_25_10_B.poss_254[0] + 1.0) - 1] <= 100) {
      prova_GPS_25_10_B.RateTransition = rt_roundd_snf
        (prova_GPS_25_10_B.poss_254[0]);
      if (prova_GPS_25_10_B.RateTransition < 256.0) {
        if (prova_GPS_25_10_B.RateTransition >= 0.0) {
          counter = (uint8_T)prova_GPS_25_10_B.RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.SFunctionBuilder_o1
        [(int32_T)(prova_GPS_25_10_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
        prova_GPS_25_10_B.f_d = 255;
      }

      prova_GPS_25_10_B.RateTransition = rt_roundd_snf
        (prova_GPS_25_10_B.poss_254[0] + (real_T)prova_GPS_25_10_B.f_d);
      if (prova_GPS_25_10_B.RateTransition < 256.0) {
        if (prova_GPS_25_10_B.RateTransition >= 0.0) {
          find_comma = (uint8_T)prova_GPS_25_10_B.RateTransition;
        } else {
          find_comma = 0U;
        }
      } else {
        find_comma = MAX_uint8_T;
      }

      if (counter > find_comma) {
        prova_GPS_25_10_B.status = 0;
        prova_GPS_25_10_B.f_d = 0;
      } else {
        prova_GPS_25_10_B.status = counter - 1;
        prova_GPS_25_10_B.f_d = find_comma;
      }

      prova_GPS_25_10_B.caso = prova_GPS_25_10_B.f_d - prova_GPS_25_10_B.status;
      for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
           prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
        prova_GPS_25_10_B.messaggio_l[prova_GPS_25_10_B.f_d] =
          prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.status +
          prova_GPS_25_10_B.f_d];
      }
    } else {
      prova_GPS_25_10_DW.Interr_parz = false;
      memset(&prova_GPS_25_10_DW.message_e[0], 0, 100U * sizeof(uint8_T));
    }

    prova_GPS_25_10_B.status = 1;
    if ((prova_GPS_25_10_B.SFunctionBuilder_o1[(int32_T)
         (prova_GPS_25_10_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (prova_GPS_25_10_B.poss_254[1] - prova_GPS_25_10_B.poss_254[0] > 3.0)) {
      prova_GPS_25_10_B.RateTransition = rt_roundd_snf((real_T)
        prova_GPS_25_10_B.SFunctionBuilder_o2 - prova_GPS_25_10_B.poss_254[1]);
      prova_GPS_25_10_B.qY = prova_GPS_25_10_B.SFunctionBuilder_o1[(int32_T)
        (prova_GPS_25_10_B.poss_254[1] + 1.0) - 1];
      prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.qY + 7U);
      if (prova_GPS_25_10_B.qY + 7U > 255U) {
        prova_GPS_25_10_B.f_d = 255;
      }

      if (prova_GPS_25_10_B.RateTransition < 2.147483648E+9) {
        if (prova_GPS_25_10_B.RateTransition >= -2.147483648E+9) {
          prova_GPS_25_10_B.i_g = (int32_T)prova_GPS_25_10_B.RateTransition;
        } else {
          prova_GPS_25_10_B.i_g = MIN_int32_T;
        }
      } else {
        prova_GPS_25_10_B.i_g = MAX_int32_T;
      }

      if (prova_GPS_25_10_B.i_g == prova_GPS_25_10_B.f_d) {
        prova_GPS_25_10_B.RateTransition = rt_roundd_snf
          (prova_GPS_25_10_B.poss_254[1]);
        if (prova_GPS_25_10_B.RateTransition < 256.0) {
          if (prova_GPS_25_10_B.RateTransition >= 0.0) {
            counter = (uint8_T)prova_GPS_25_10_B.RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.qY + 7U);
        if (prova_GPS_25_10_B.qY + 7U > 255U) {
          prova_GPS_25_10_B.f_d = 255;
        }

        prova_GPS_25_10_B.RateTransition = rt_roundd_snf
          (prova_GPS_25_10_B.poss_254[1] + (real_T)prova_GPS_25_10_B.f_d);
        if (prova_GPS_25_10_B.RateTransition < 256.0) {
          if (prova_GPS_25_10_B.RateTransition >= 0.0) {
            find_comma = (uint8_T)prova_GPS_25_10_B.RateTransition;
          } else {
            find_comma = 0U;
          }
        } else {
          find_comma = MAX_uint8_T;
        }

        if (counter > find_comma) {
          prova_GPS_25_10_B.status = 0;
          prova_GPS_25_10_B.f_d = 0;
        } else {
          prova_GPS_25_10_B.status = counter - 1;
          prova_GPS_25_10_B.f_d = find_comma;
        }

        prova_GPS_25_10_B.caso = prova_GPS_25_10_B.f_d -
          prova_GPS_25_10_B.status;
        for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
             prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.f_d] =
            prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.status +
            prova_GPS_25_10_B.f_d];
        }

        prova_GPS_25_10_B.status = 2;
        for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 100;
             prova_GPS_25_10_B.i++) {
          prova_GPS_25_10_B.messaggio_2[prova_GPS_25_10_B.i] =
            prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i];
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.i] = 0U;
        }

        prova_GPS_25_10_DW.counter_m = 0U;
        prova_GPS_25_10_DW.mess_len = 0.0;
      } else {
        prova_GPS_25_10_B.RateTransition = rt_roundd_snf
          (prova_GPS_25_10_B.poss_254[1]);
        if (prova_GPS_25_10_B.RateTransition < 2.147483648E+9) {
          if (prova_GPS_25_10_B.RateTransition >= -2.147483648E+9) {
            prova_GPS_25_10_B.f_d = (int32_T)prova_GPS_25_10_B.RateTransition;
          } else {
            prova_GPS_25_10_B.f_d = MIN_int32_T;
          }
        } else {
          prova_GPS_25_10_B.f_d = MAX_int32_T;
        }

        if (prova_GPS_25_10_B.f_d > prova_GPS_25_10_B.SFunctionBuilder_o2) {
          prova_GPS_25_10_B.f_d = -1;
          prova_GPS_25_10_B.caso = 0;
        } else {
          prova_GPS_25_10_B.f_d -= 2;
          prova_GPS_25_10_B.caso = prova_GPS_25_10_B.SFunctionBuilder_o2;
        }

        prova_GPS_25_10_DW.mess_len = (int8_T)((prova_GPS_25_10_B.caso -
          prova_GPS_25_10_B.f_d) - 1);
        if (prova_GPS_25_10_B.RateTransition < 2.147483648E+9) {
          if (prova_GPS_25_10_B.RateTransition >= -2.147483648E+9) {
            prova_GPS_25_10_B.f_d = (int32_T)prova_GPS_25_10_B.RateTransition;
          } else {
            prova_GPS_25_10_B.f_d = MIN_int32_T;
          }
        } else {
          prova_GPS_25_10_B.f_d = MAX_int32_T;
        }

        if (prova_GPS_25_10_B.f_d > prova_GPS_25_10_B.SFunctionBuilder_o2) {
          prova_GPS_25_10_B.i = 0;
          prova_GPS_25_10_B.f_d = 0;
        } else {
          prova_GPS_25_10_B.i = prova_GPS_25_10_B.f_d - 1;
          prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.SFunctionBuilder_o2;
        }

        prova_GPS_25_10_B.caso = prova_GPS_25_10_B.f_d - prova_GPS_25_10_B.i;
        for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
             prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
          prova_GPS_25_10_DW.message_e[prova_GPS_25_10_B.f_d] =
            prova_GPS_25_10_B.SFunctionBuilder_o1[prova_GPS_25_10_B.i +
            prova_GPS_25_10_B.f_d];
        }

        prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_B.qY + 8U);
        if (prova_GPS_25_10_B.qY + 8U > 255U) {
          prova_GPS_25_10_B.f_d = 255;
        }

        prova_GPS_25_10_B.RateTransition = rt_roundd_snf((real_T)
          prova_GPS_25_10_B.f_d - prova_GPS_25_10_DW.mess_len);
        if (prova_GPS_25_10_B.RateTransition < 256.0) {
          if (prova_GPS_25_10_B.RateTransition >= 0.0) {
            prova_GPS_25_10_DW.counter_m = (uint8_T)
              prova_GPS_25_10_B.RateTransition;
          } else {
            prova_GPS_25_10_DW.counter_m = 0U;
          }
        } else {
          prova_GPS_25_10_DW.counter_m = MAX_uint8_T;
        }

        prova_GPS_25_10_DW.Interr_parz = true;
      }
    } else {
      prova_GPS_25_10_DW.Interr_parz = false;
      memset(&prova_GPS_25_10_DW.message_e[0], 0, 100U * sizeof(uint8_T));
      prova_GPS_25_10_DW.counter_m = 0U;
      prova_GPS_25_10_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&prova_GPS_25_10_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
       prova_GPS_25_10_B.f_d++) {
    prova_GPS_25_10_B.buffer[3 * prova_GPS_25_10_B.f_d] = 0U;
  }

  for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
       prova_GPS_25_10_B.f_d++) {
    for (prova_GPS_25_10_B.caso = 0; prova_GPS_25_10_B.caso < 2;
         prova_GPS_25_10_B.caso++) {
      prova_GPS_25_10_B.i = 3 * prova_GPS_25_10_B.f_d + prova_GPS_25_10_B.caso;
      prova_GPS_25_10_B.buffer[prova_GPS_25_10_B.i + 1] =
        prova_GPS_25_10_DW.Memory4_PreviousInput[prova_GPS_25_10_B.i];
    }
  }

  prova_GPS_25_10_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (prova_GPS_25_10_B.i >= 1)) {
    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.x[prova_GPS_25_10_B.f_d] = (prova_GPS_25_10_B.buffer[(3 *
        prova_GPS_25_10_B.f_d + prova_GPS_25_10_B.i) - 1] == 0);
    }

    y = true;
    prova_GPS_25_10_B.f_d = 0;
    exitg2 = false;
    while ((!exitg2) && (prova_GPS_25_10_B.f_d < 100)) {
      if (!prova_GPS_25_10_B.x[prova_GPS_25_10_B.f_d]) {
        y = false;
        exitg2 = true;
      } else {
        prova_GPS_25_10_B.f_d++;
      }
    }

    if (y) {
      counter = (uint8_T)prova_GPS_25_10_B.i;
      exitg1 = true;
    } else {
      prova_GPS_25_10_B.i--;
    }
  }

  if (prova_GPS_25_10_B.status == 1) {
    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.buffer[(counter + 3 * prova_GPS_25_10_B.f_d) - 1] =
        prova_GPS_25_10_B.messaggio_l[prova_GPS_25_10_B.f_d];
    }
  } else if (prova_GPS_25_10_B.status == 2) {
    prova_GPS_25_10_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      prova_GPS_25_10_B.qY = 0U;
    }

    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.buffer[(counter + 3 * prova_GPS_25_10_B.f_d) - 1] =
        prova_GPS_25_10_B.messaggio_l[prova_GPS_25_10_B.f_d];
      prova_GPS_25_10_B.buffer[((int32_T)prova_GPS_25_10_B.qY + 3 *
        prova_GPS_25_10_B.f_d) - 1] =
        prova_GPS_25_10_B.messaggio_2[prova_GPS_25_10_B.f_d];
    }
  } else {
    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.buffer[(counter + 3 * prova_GPS_25_10_B.f_d) - 1] = 0U;
    }
  }

  for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
       prova_GPS_25_10_B.f_d++) {
    prova_GPS_25_10_B.mess_out[prova_GPS_25_10_B.f_d] =
      prova_GPS_25_10_DW.Memory4_PreviousInput[3 * prova_GPS_25_10_B.f_d + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  prova_GPS_25_10_B.Add = prova_GPS_25_10_DW.Memory4_PreviousInput[5] +
    prova_GPS_25_10_P.Constant_Value_i2;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (prova_GPS_25_10_B.mess_out[2] != prova_GPS_25_10_DW.Memory5_PreviousInput
      [2]) {
    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 100;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.x[prova_GPS_25_10_B.f_d] =
        (prova_GPS_25_10_B.mess_out[prova_GPS_25_10_B.f_d] != 0);
    }

    y = true;
    prova_GPS_25_10_B.f_d = 0;
    exitg1 = false;
    while ((!exitg1) && (prova_GPS_25_10_B.f_d < 100)) {
      if (!prova_GPS_25_10_B.x[prova_GPS_25_10_B.f_d]) {
        y = false;
        exitg1 = true;
      } else {
        prova_GPS_25_10_B.f_d++;
      }
    }

    if (!y) {
      if (prova_GPS_25_10_DW.counter > 100) {
        prova_GPS_25_10_DW.counter = 0U;
      }

      prova_GPS_25_10_B.qY = prova_GPS_25_10_DW.counter + 1U;
      if (prova_GPS_25_10_DW.counter + 1U > 65535U) {
        prova_GPS_25_10_B.qY = 65535U;
      }

      prova_GPS_25_10_DW.counter = (uint16_T)prova_GPS_25_10_B.qY;
    }
  }

  prova_GPS_25_10_B.new_mex = prova_GPS_25_10_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  prova_GPS_25_10_B.Memory1[0] = prova_GPS_25_10_DW.Memory1_PreviousInput_j[0];
  prova_GPS_25_10_B.Memory1[1] = prova_GPS_25_10_DW.Memory1_PreviousInput_j[1];

  /* Memory: '<Root>/Memory' */
  prova_GPS_25_10_B.Memory_p[0] = prova_GPS_25_10_DW.Memory_PreviousInput_m[0];
  prova_GPS_25_10_B.Memory_p[1] = prova_GPS_25_10_DW.Memory_PreviousInput_m[1];
  prova_GPS_25_10_B.Memory_p[2] = prova_GPS_25_10_DW.Memory_PreviousInput_m[2];
  prova_GPS_25_10_B.Memory_p[3] = prova_GPS_25_10_DW.Memory_PreviousInput_m[3];

  /* Memory: '<S1>/Memory3' */
  prova_GPS_25_10_B.Memory3 = prova_GPS_25_10_DW.Memory3_PreviousInput;
  for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 8; prova_GPS_25_10_B.i++)
  {
    /* Memory: '<S1>/Memory' */
    prova_GPS_25_10_B.Memory[prova_GPS_25_10_B.i] =
      prova_GPS_25_10_DW.Memory_PreviousInput_g[prova_GPS_25_10_B.i];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&prova_GPS_25_10_B.mess_out[0], &prova_GPS_25_10_B.Add,
     &prova_GPS_25_10_B.new_mex, &prova_GPS_25_10_P.SIUAVuint8_Value,
     &prova_GPS_25_10_B.Memory[0], &prova_GPS_25_10_B.Memory1[0],
     &prova_GPS_25_10_B.Memory_p[0], &prova_GPS_25_10_B.Memory3,
     &prova_GPS_25_10_B.SFunction_o1[0], &prova_GPS_25_10_B.SFunction_o2,
     &prova_GPS_25_10_B.SFunction_o3_m, &prova_GPS_25_10_B.SFunction_o4_n[0],
     &prova_GPS_25_10_B.SFunction_o5[0], &prova_GPS_25_10_B.SFunction_o6,
     &prova_GPS_25_10_B.SFunction_o7[0], &prova_GPS_25_10_B.SFunction_o8,
     &prova_GPS_25_10_B.SFunction_o9[0], &prova_GPS_25_10_B.SFunction_o10[0],
     &prova_GPS_25_10_B.SFunction_o11[0], &prova_GPS_25_10_B.SFunction_o12,
     &prova_GPS_25_10_B.SFunction_o13, &prova_GPS_25_10_B.SFunction_o14,
     &prova_GPS_25_10_B.SFunction_o15, &prova_GPS_25_10_B.SFunction_o16,
     &prova_GPS_25_10_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 9; prova_GPS_25_10_B.i++)
  {
    prova_GPS_25_10_B.Memory2[prova_GPS_25_10_B.i] =
      prova_GPS_25_10_DW.Memory2_PreviousInput_c[prova_GPS_25_10_B.i];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 6; prova_GPS_25_10_B.i++)
  {
    prova_GPS_25_10_B.WP_info_in[prova_GPS_25_10_B.i] =
      prova_GPS_25_10_B.SFunction_o9[prova_GPS_25_10_B.i];
  }

  if ((!prova_GPS_25_10_DW.WP_dbP_not_empty) ||
      ((prova_GPS_25_10_B.SFunction_o7[0] == 3) &&
       (prova_GPS_25_10_B.SFunction_o7[1] == 250))) {
    memset(&prova_GPS_25_10_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    prova_GPS_25_10_DW.WP_dbP_not_empty = true;
    memset(&prova_GPS_25_10_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!prova_GPS_25_10_DW.WP_dbP_AL_not_empty) ||
      ((prova_GPS_25_10_B.SFunction_o7[0] == 3) &&
       (prova_GPS_25_10_B.SFunction_o7[1] == 250))) {
    prova_GPS_25_10_DW.WP_dbP_AL_not_empty = true;
  }

  prova_GPS_25_10_B.GC_info[0] = prova_GPS_25_10_B.SFunction_o7[0];
  prova_GPS_25_10_B.GC_info[1] = prova_GPS_25_10_B.SFunction_o7[1];
  prova_GPS_25_10_B.GC_info[2] = prova_GPS_25_10_B.SFunction_o11[0];
  if (prova_GPS_25_10_B.GC_info[0] == 1) {
    if ((prova_GPS_25_10_B.GC_info[1] > 0) && (prova_GPS_25_10_B.GC_info[1] <= 7))
    {
      if ((real32_T)fabs(prova_GPS_25_10_B.SFunction_o8) > 0.0F) {
        prova_GPS_25_10_DW.riferimenti[prova_GPS_25_10_B.GC_info[1] - 1] = 1.0F;
      } else {
        if (prova_GPS_25_10_B.SFunction_o8 == 0.0F) {
          prova_GPS_25_10_DW.riferimenti[prova_GPS_25_10_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((prova_GPS_25_10_B.GC_info[1] > 7) && (prova_GPS_25_10_B.GC_info[1] <
           12)) {
        prova_GPS_25_10_DW.riferimenti[prova_GPS_25_10_B.GC_info[1] - 1] =
          prova_GPS_25_10_B.SFunction_o8;
      }
    }
  }

  if (prova_GPS_25_10_B.SFunction_o12 == 13) {
    prova_GPS_25_10_DW.riferimenti[prova_GPS_25_10_B.SFunction_o12 - 1] =
      prova_GPS_25_10_B.SFunction_o13;
  }

  memcpy(&prova_GPS_25_10_B.Val_out_MAV[0], &prova_GPS_25_10_DW.riferimenti[0],
         sizeof(real32_T) << 4U);
  if ((prova_GPS_25_10_B.GC_info[0] == 3) && (prova_GPS_25_10_B.GC_info[1] ==
       200)) {
    if (prova_GPS_25_10_B.SFunction_o9[0] > 6) {
      prova_GPS_25_10_B.WP_info_in[0] = 6U;
    }

    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 6;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_DW.WP_dbI[prova_GPS_25_10_B.f_d] =
        prova_GPS_25_10_B.WP_info_in[0];
    }
  }

  if ((prova_GPS_25_10_B.GC_info[0] == 3) && (prova_GPS_25_10_B.GC_info[1] < 200))
  {
    if (prova_GPS_25_10_B.SFunction_o10[1] == 0.0F) {
      prova_GPS_25_10_B.qY = prova_GPS_25_10_B.SFunction_o9[1] + 1U;
      if (prova_GPS_25_10_B.SFunction_o9[1] + 1U > 65535U) {
        prova_GPS_25_10_B.qY = 65535U;
      }

      for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 7;
           prova_GPS_25_10_B.f_d++) {
        prova_GPS_25_10_DW.WP_dbP[((int32_T)prova_GPS_25_10_B.qY + 6 *
          prova_GPS_25_10_B.f_d) - 1] =
          prova_GPS_25_10_B.SFunction_o10[prova_GPS_25_10_B.f_d];
      }

      prova_GPS_25_10_B.qY = prova_GPS_25_10_B.SFunction_o9[1] + 1U;
      if (prova_GPS_25_10_B.SFunction_o9[1] + 1U > 65535U) {
        prova_GPS_25_10_B.qY = 65535U;
      }

      for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 6;
           prova_GPS_25_10_B.f_d++) {
        prova_GPS_25_10_DW.WP_dbI[((int32_T)prova_GPS_25_10_B.qY + 6 *
          (prova_GPS_25_10_B.f_d + 1)) - 1] =
          prova_GPS_25_10_B.WP_info_in[prova_GPS_25_10_B.f_d + 1];
      }
    } else {
      prova_GPS_25_10_B.qY = prova_GPS_25_10_B.SFunction_o9[1] + 1U;
      if (prova_GPS_25_10_B.SFunction_o9[1] + 1U > 65535U) {
        prova_GPS_25_10_B.qY = 65535U;
      }

      for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 6;
           prova_GPS_25_10_B.f_d++) {
        prova_GPS_25_10_DW.WP_dbI[((int32_T)prova_GPS_25_10_B.qY + 6 *
          (prova_GPS_25_10_B.f_d + 1)) - 1] =
          prova_GPS_25_10_B.WP_info_in[prova_GPS_25_10_B.f_d + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_GPS_25_10_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((prova_GPS_25_10_B.SFunction_o6 == 0) && (prova_GPS_25_10_B.SFunction_o3_m
       == 0)) {
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 0U;
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_GPS_25_10_DW.Memory3_PreviousInput = 0U;
  } else if ((prova_GPS_25_10_B.SFunction_o6 == 0) &&
             (prova_GPS_25_10_B.SFunction_o3_m == 3)) {
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 0U;
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_GPS_25_10_DW.Memory3_PreviousInput = 0U;
  } else if ((prova_GPS_25_10_B.SFunction_o6 == 0) &&
             (prova_GPS_25_10_B.SFunction_o3_m == 2)) {
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 0U;
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_GPS_25_10_DW.Memory3_PreviousInput = 0U;
  } else if ((prova_GPS_25_10_B.SFunction_o6 == 0) &&
             (prova_GPS_25_10_B.SFunction_o3_m == 1)) {
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 0U;
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    prova_GPS_25_10_DW.Memory3_PreviousInput = 0U;
  } else {
    switch (prova_GPS_25_10_B.SFunction_o6) {
     case 192:
      prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 192U;
      prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      prova_GPS_25_10_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 208U;
      prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      prova_GPS_25_10_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((prova_GPS_25_10_B.SFunction_o6 == 220) &&
          (prova_GPS_25_10_B.SFunction_o3_m != 5)) {
        if ((prova_GPS_25_10_B.Memory2[0] == 0) && (prova_GPS_25_10_B.Memory2[1]
             == 0) && ((prova_GPS_25_10_B.Memory2[2] == 1) ||
                       (prova_GPS_25_10_B.Memory2[3] == 1) ||
                       (prova_GPS_25_10_B.Memory2[4] == 1) ||
                       (prova_GPS_25_10_B.Memory2[5] == 1) ||
                       (prova_GPS_25_10_B.Memory2[6] == 1) ||
                       (prova_GPS_25_10_B.Memory2[7] == 1))) {
          prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 220U;
          prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          prova_GPS_25_10_DW.Memory3_PreviousInput = 220U;
        } else if ((prova_GPS_25_10_B.Memory2[0] == 0) &&
                   (prova_GPS_25_10_B.Memory2[1] == 1) &&
                   ((prova_GPS_25_10_B.Memory2[2] == 1) ||
                    (prova_GPS_25_10_B.Memory2[3] == 1) ||
                    (prova_GPS_25_10_B.Memory2[4] == 1) ||
                    (prova_GPS_25_10_B.Memory2[5] == 1) ||
                    (prova_GPS_25_10_B.Memory2[6] == 1) ||
                    (prova_GPS_25_10_B.Memory2[7] == 1))) {
          prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 220U;
          prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          prova_GPS_25_10_DW.Memory3_PreviousInput = 220U;
        } else {
          prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 208U;
          prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          prova_GPS_25_10_DW.Memory3_PreviousInput = 208U;
        }
      } else if (prova_GPS_25_10_B.SFunction_o3_m == 5) {
        prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 220U;
        prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] = 192U;
        prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  prova_GPS_25_10_B.qY = 100U * prova_GPS_25_10_B.SFunction_o11[5];
  if (prova_GPS_25_10_B.qY > 65535U) {
    prova_GPS_25_10_B.qY = 65535U;
  }

  if (prova_GPS_25_10_B.SFunction_o11[4] == 0) {
    if ((uint16_T)prova_GPS_25_10_B.qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(prova_GPS_25_10_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
                   (uint32_T)(uint16_T)prova_GPS_25_10_B.qY /
                   prova_GPS_25_10_B.SFunction_o11[4]);
    x = (uint16_T)((uint32_T)(uint16_T)prova_GPS_25_10_B.qY - (uint16_T)
                   ((uint32_T)z * prova_GPS_25_10_B.SFunction_o11[4]));
    if ((x > 0) && (x >= (int32_T)((uint32_T)prova_GPS_25_10_B.SFunction_o11[4] >>
          1) + (prova_GPS_25_10_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  /* RateTransition: '<S25>/Rate Transition' */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_DW.RateTransition_Buffer0;

  /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
   *  Constant: '<S25>/Constant2'
   *  Constant: '<S25>/Constant3'
   *  Memory: '<S25>/Memory1'
   *  Sum: '<S25>/Add1'
   */
  prova_GPS_25_10_DW.Memory1_PreviousInput +=
    prova_GPS_25_10_P.Constant2_Value_j + prova_GPS_25_10_P.Constant3_Value_k;

  /* Switch: '<S25>/Switch' */
  if (prova_GPS_25_10_DW.Memory1_PreviousInput >
      prova_GPS_25_10_P.Switch_Threshold) {
    /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
     *  Constant: '<S25>/Constant2'
     */
    prova_GPS_25_10_DW.Memory1_PreviousInput =
      prova_GPS_25_10_P.Constant2_Value_j;
  }

  /* End of Switch: '<S25>/Switch' */

  /* MATLAB Function: '<S11>/iflogic_function' */
  if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 1.0) ||
      (prova_GPS_25_10_DW.Memory1_PreviousInput == 3.0)) {
    prova_GPS_25_10_B.iflogic = 26U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 2.0) ||
             (prova_GPS_25_10_DW.Memory1_PreviousInput == 4.0)) {
    prova_GPS_25_10_B.iflogic = 30U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             (prova_GPS_25_10_B.RateTransition == 2.0)) {
    prova_GPS_25_10_B.iflogic = 33U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             (prova_GPS_25_10_B.RateTransition == 6.0)) {
    prova_GPS_25_10_B.iflogic = 34U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             (prova_GPS_25_10_B.RateTransition == 0.0)) {
    prova_GPS_25_10_B.iflogic = 0U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             ((prova_GPS_25_10_B.RateTransition == 1.0) ||
              (prova_GPS_25_10_B.RateTransition == 5.0) ||
              (prova_GPS_25_10_B.RateTransition == 9.0))) {
    prova_GPS_25_10_B.iflogic = 1U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             ((prova_GPS_25_10_B.RateTransition == 3.0) ||
              (prova_GPS_25_10_B.RateTransition == 8.0))) {
    prova_GPS_25_10_B.iflogic = 74U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             (prova_GPS_25_10_B.RateTransition == 7.0)) {
    prova_GPS_25_10_B.iflogic = 36U;
  } else if ((prova_GPS_25_10_DW.Memory1_PreviousInput == 0.0) &&
             (prova_GPS_25_10_B.RateTransition == 4.0)) {
    prova_GPS_25_10_B.iflogic = 29U;
  } else {
    prova_GPS_25_10_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S11>/iflogic_function' */

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant1'
   *  Memory: '<S25>/Memory'
   */
  prova_GPS_25_10_DW.Memory_PreviousInput += prova_GPS_25_10_P.Constant_Value_m
    + prova_GPS_25_10_P.Constant1_Value_l;

  /* Gain: '<S11>/Gain' */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain_Gain *
    prova_GPS_25_10_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3 = prova_GPS_25_10_B.RateTransition < 0.0
    ? (uint32_T)-(int32_T)(uint32_T)-prova_GPS_25_10_B.RateTransition :
    (uint32_T)prova_GPS_25_10_B.RateTransition;

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 6;
       prova_GPS_25_10_B.f_d++) {
    prova_GPS_25_10_B.WP_info[prova_GPS_25_10_B.f_d] =
      prova_GPS_25_10_DW.WP_dbI[6 * prova_GPS_25_10_B.f_d];
  }

  for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 7;
       prova_GPS_25_10_B.f_d++) {
    prova_GPS_25_10_B.WP_param[prova_GPS_25_10_B.f_d] =
      prova_GPS_25_10_DW.WP_dbP[6 * prova_GPS_25_10_B.f_d];
  }

  if ((prova_GPS_25_10_B.GC_info[0] == 2) && (prova_GPS_25_10_B.GC_info[1] < 6))
  {
    prova_GPS_25_10_B.qY = prova_GPS_25_10_B.GC_info[1] + 1U;
    if (prova_GPS_25_10_B.GC_info[1] + 1U > 65535U) {
      prova_GPS_25_10_B.qY = 65535U;
    }

    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 6;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.WP_info[prova_GPS_25_10_B.f_d] =
        prova_GPS_25_10_DW.WP_dbI[(6 * prova_GPS_25_10_B.f_d + (int32_T)
        prova_GPS_25_10_B.qY) - 1];
    }

    prova_GPS_25_10_B.qY = prova_GPS_25_10_B.GC_info[1] + 1U;
    if (prova_GPS_25_10_B.GC_info[1] + 1U > 65535U) {
      prova_GPS_25_10_B.qY = 65535U;
    }

    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 7;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.WP_param[prova_GPS_25_10_B.f_d] =
        prova_GPS_25_10_DW.WP_dbP[(6 * prova_GPS_25_10_B.f_d + (int32_T)
        prova_GPS_25_10_B.qY) - 1];
    }
  }

  if ((prova_GPS_25_10_B.GC_info[0] == 3) && (prova_GPS_25_10_B.GC_info[1] < 200))
  {
    prova_GPS_25_10_B.qY = prova_GPS_25_10_B.GC_info[1] + 1U;
    if (prova_GPS_25_10_B.GC_info[1] + 1U > 65535U) {
      prova_GPS_25_10_B.qY = 65535U;
    }

    for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 6;
         prova_GPS_25_10_B.f_d++) {
      prova_GPS_25_10_B.WP_info[prova_GPS_25_10_B.f_d] =
        prova_GPS_25_10_DW.WP_dbI[(6 * prova_GPS_25_10_B.f_d + (int32_T)
        prova_GPS_25_10_B.qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function' */

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Constant: '<S13>/onboard_control_sensor_present uint32'
   */
  prova_GPS_25_10_B.onboard[0] =
    prova_GPS_25_10_P.onboard_control_sensor_presentu[0];
  prova_GPS_25_10_B.onboard[1] =
    prova_GPS_25_10_P.onboard_control_sensor_presentu[1];
  prova_GPS_25_10_B.onboard[2] =
    prova_GPS_25_10_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Gain_Gain_f *
    prova_GPS_25_10_P.Constant_Value_e);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  Constant: '<S13>/load uint16'
   *  Gain: '<S13>/Gain'
   */
  prova_GPS_25_10_B.LVDE[0] = prova_GPS_25_10_P.loaduint16_Value;
  prova_GPS_25_10_B.LVDE[1] = (uint16_T)(prova_GPS_25_10_B.RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-prova_GPS_25_10_B.RateTransition :
    (int32_T)(uint16_T)prova_GPS_25_10_B.RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  prova_GPS_25_10_B.qY = 10U * z;
  if (prova_GPS_25_10_B.qY > 65535U) {
    prova_GPS_25_10_B.qY = 65535U;
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  Constant: '<S13>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_GPS_25_10_B.LVDE[2] = (uint16_T)prova_GPS_25_10_B.qY;
  prova_GPS_25_10_B.LVDE[3] = prova_GPS_25_10_B.SFunction_o11[6];
  prova_GPS_25_10_B.LVDE[4] = prova_GPS_25_10_B.SFunction_o11[2];
  prova_GPS_25_10_B.LVDE[5] = prova_GPS_25_10_P._Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant1_Value_k[0]);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion4'
   */
  prova_GPS_25_10_B.LVDE[6] = (uint16_T)(prova_GPS_25_10_B.RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-prova_GPS_25_10_B.RateTransition :
    (int32_T)(uint16_T)prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant1_Value_k[1]);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion4'
   */
  prova_GPS_25_10_B.LVDE[7] = (uint16_T)(prova_GPS_25_10_B.RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-prova_GPS_25_10_B.RateTransition :
    (int32_T)(uint16_T)prova_GPS_25_10_B.RateTransition);

  /* Gain: '<S13>/Gain2' incorporates:
   *  Constant: '<S13>/Constant3'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Gain2_Gain *
    prova_GPS_25_10_P.Constant3_Value_g);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Gain: '<S13>/Gain1'
   *  Gain: '<S13>/Gain2'
   */
  prova_GPS_25_10_B.B_Current = (int16_T)(((prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition) * prova_GPS_25_10_P.Gain1_Gain_f) >> 18);

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant2_Value_g);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      256.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  prova_GPS_25_10_B.B_Remaining = (int8_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-prova_GPS_25_10_B.RateTransition :
    (int32_T)(int8_T)(uint8_T)prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Constant: '<S9>/Constant'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant_Value_n);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_GPS_25_10_B.DataTypeConversion = prova_GPS_25_10_B.RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-prova_GPS_25_10_B.RateTransition : (uint32_T)
    prova_GPS_25_10_B.RateTransition;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  MATLAB Function: '<S9>/Alarm set'
   */
  prova_GPS_25_10_B.DataTypeConversion1_n[2] =
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[0];
  prova_GPS_25_10_B.DataTypeConversion1_n[3] =
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[1];

  /* MATLAB Function: '<S9>/Alarm set' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (prova_GPS_25_10_P.Constant1_Value_g[0] == 1.0) {
    /* DataTypeConversion: '<S9>/Data Type Conversion1' */
    prova_GPS_25_10_B.DataTypeConversion1_n[2] = 220U;
    prova_GPS_25_10_B.DataTypeConversion1_n[3] = 5U;
  }

  if (prova_GPS_25_10_P.Constant1_Value_g[1] == 1.0) {
    /* DataTypeConversion: '<S9>/Data Type Conversion1' */
    prova_GPS_25_10_B.DataTypeConversion1_n[2] = 216U;
    prova_GPS_25_10_B.DataTypeConversion1_n[3] = 4U;
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  Constant: '<S9>/Type fixed_wing Autopilot generic'
   */
  prova_GPS_25_10_B.DataTypeConversion1_n[0] =
    prova_GPS_25_10_P.Typefixed_wingAutopilotgeneric_[0];
  prova_GPS_25_10_B.DataTypeConversion1_n[1] =
    prova_GPS_25_10_P.Typefixed_wingAutopilotgeneric_[1];

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion5'
   */
  if (prova_GPS_25_10_P.Constant5_Value[0] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant5_Value[0]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant5_Value[0]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[0] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   */
  if (prova_GPS_25_10_P.Constant5_Value[1] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant5_Value[1]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant5_Value[1]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[1] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion7'
   */
  if (prova_GPS_25_10_P.Constant5_Value[2] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant5_Value[2]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant5_Value[2]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[2] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion10'
   */
  if (prova_GPS_25_10_P.Constant5_Value[3] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant5_Value[3]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant5_Value[3]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[3] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   */
  if (prova_GPS_25_10_P.Constant5_Value[4] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant5_Value[4]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant5_Value[4]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[4] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion12'
   */
  if (prova_GPS_25_10_P.Constant5_Value[5] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant5_Value[5]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant5_Value[5]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[5] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (prova_GPS_25_10_P.Constant4_Value[0] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant4_Value[0]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant4_Value[0]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[6] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (prova_GPS_25_10_P.Constant4_Value[1] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant4_Value[1]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant4_Value[1]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[7] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (prova_GPS_25_10_P.Constant4_Value[2] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant4_Value[2]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant4_Value[2]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  prova_GPS_25_10_B.DataTypeConversion3_m[8] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion4' incorporates:
   *  Constant: '<S10>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion10'
   *  DataTypeConversion: '<S10>/Data Type Conversion11'
   *  DataTypeConversion: '<S10>/Data Type Conversion12'
   *  DataTypeConversion: '<S10>/Data Type Conversion13'
   *  DataTypeConversion: '<S10>/Data Type Conversion14'
   *  DataTypeConversion: '<S10>/Data Type Conversion15'
   */
  prova_GPS_25_10_B.DataTypeConversion4[0] = (real32_T)
    prova_GPS_25_10_P.Constant5_Value[6];
  prova_GPS_25_10_B.DataTypeConversion4[1] = (real32_T)
    prova_GPS_25_10_P.Constant5_Value[7];
  prova_GPS_25_10_B.DataTypeConversion4[2] = (real32_T)
    prova_GPS_25_10_P.Constant5_Value[8];
  prova_GPS_25_10_B.DataTypeConversion4[3] = (real32_T)
    prova_GPS_25_10_P.Constant5_Value[3];
  prova_GPS_25_10_B.DataTypeConversion4[4] = (real32_T)
    prova_GPS_25_10_P.Constant5_Value[4];
  prova_GPS_25_10_B.DataTypeConversion4[5] = (real32_T)
    prova_GPS_25_10_P.Constant5_Value[5];

  /* MATLABSystem: '<S18>/Serial Receive1' */
  if (prova_GPS_25_10_DW.obj_m.Protocol !=
      prova_GPS_25_10_P.SerialReceive1_Protocol) {
    prova_GPS_25_10_DW.obj_m.Protocol =
      prova_GPS_25_10_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(3, prova_GPS_25_10_DW.obj_m.DataSizeInBytes,
                 &prova_GPS_25_10_B.b_dataOut[0], &counter);

  /* Outputs for Enabled SubSystem: '<S18>/Subsystem2' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (counter > 0) {
    /* MATLAB Function: '<S20>/Create_message' */
    counter = 0U;
    if (!prova_GPS_25_10_DW.start_found) {
      prova_GPS_25_10_B.i = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_GPS_25_10_B.i - 1 < 32)) {
        if (prova_GPS_25_10_B.b_dataOut[(uint8_T)prova_GPS_25_10_B.i - 1] == 36)
        {
          prova_GPS_25_10_B.caso = 32 - (uint8_T)prova_GPS_25_10_B.i;
          for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <=
               prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
            prova_GPS_25_10_DW.message[prova_GPS_25_10_B.f_d] =
              prova_GPS_25_10_B.b_dataOut[((uint8_T)prova_GPS_25_10_B.i +
              prova_GPS_25_10_B.f_d) - 1];
          }

          prova_GPS_25_10_DW.counter_k = (uint8_T)(33 - (uint8_T)
            prova_GPS_25_10_B.i);
          prova_GPS_25_10_DW.start_found = true;
          exitg1 = true;
        } else {
          prova_GPS_25_10_B.i++;
        }
      }
    } else {
      prova_GPS_25_10_B.f_d = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_GPS_25_10_B.f_d - 1 < 32)) {
        if (prova_GPS_25_10_B.b_dataOut[(uint8_T)prova_GPS_25_10_B.f_d - 1] ==
            13) {
          prova_GPS_25_10_DW.end_found = true;
          counter = (uint8_T)prova_GPS_25_10_B.f_d;
          exitg1 = true;
        } else {
          prova_GPS_25_10_B.f_d++;
        }
      }

      if (prova_GPS_25_10_DW.end_found) {
        if (1 > counter) {
          prova_GPS_25_10_B.caso = -1;
        } else {
          prova_GPS_25_10_B.caso = counter - 1;
        }

        for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <=
             prova_GPS_25_10_B.caso; prova_GPS_25_10_B.f_d++) {
          prova_GPS_25_10_B.i_g = (int32_T)(((uint32_T)prova_GPS_25_10_B.f_d +
            prova_GPS_25_10_DW.counter_k) + 1U);
          if ((uint32_T)prova_GPS_25_10_B.i_g > 255U) {
            prova_GPS_25_10_B.i_g = 255;
          }

          prova_GPS_25_10_DW.message[prova_GPS_25_10_B.i_g - 1] =
            prova_GPS_25_10_B.b_dataOut[prova_GPS_25_10_B.f_d];
        }

        memcpy(&prova_GPS_25_10_B.messaggio_c[0], &prova_GPS_25_10_DW.message[0],
               80U * sizeof(uint8_T));
        prova_GPS_25_10_DW.end_found = false;
        prova_GPS_25_10_DW.counter_k = (uint8_T)(32 - counter);
        if (counter == 32) {
          prova_GPS_25_10_DW.start_found = false;
          memset(&prova_GPS_25_10_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          prova_GPS_25_10_DW.start_found = true;
          prova_GPS_25_10_B.caso = -counter;
          for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <=
               prova_GPS_25_10_B.caso + 31; prova_GPS_25_10_B.f_d++) {
            prova_GPS_25_10_DW.message[prova_GPS_25_10_B.f_d] =
              prova_GPS_25_10_B.b_dataOut[counter + prova_GPS_25_10_B.f_d];
          }

          prova_GPS_25_10_B.f_d = counter + 48;
          if (0 <= prova_GPS_25_10_B.f_d - 1) {
            memset(&prova_GPS_25_10_DW.message[-counter + 32], 0,
                   ((prova_GPS_25_10_B.f_d - counter) + counter) * sizeof
                   (uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S20>/Subsystem' incorporates:
         *  EnablePort: '<S22>/Enable'
         */
        /* MATLAB Function: '<S22>/MATLAB Function' */
        counter = 0U;
        find_comma = 0U;
        for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 80;
             prova_GPS_25_10_B.i++) {
          messaggio = (int8_T)prova_GPS_25_10_B.messaggio_c[prova_GPS_25_10_B.i];
          if (messaggio == '$') {
            prova_GPS_25_10_B.f_d = (int32_T)(counter + 1U);
            if (counter + 1U > 255U) {
              prova_GPS_25_10_B.f_d = 255;
            }

            counter = (uint8_T)prova_GPS_25_10_B.f_d;
          }

          if (messaggio == ',') {
            prova_GPS_25_10_B.f_d = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              prova_GPS_25_10_B.f_d = 255;
            }

            find_comma = (uint8_T)prova_GPS_25_10_B.f_d;
          }

          prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.i] = messaggio;
        }

        if ((counter == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
               prova_GPS_25_10_B.f_d++) {
            prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
              (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == '$');
          }

          prova_GPS_25_10_eml_find(prova_GPS_25_10_B.messaggio_m,
            &prova_GPS_25_10_B.eb_data, prova_GPS_25_10_B.eb_size);
          prova_GPS_25_10_B.status = prova_GPS_25_10_B.eb_data;
          for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 5;
               prova_GPS_25_10_B.f_d++) {
            messaggio = prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d +
              prova_GPS_25_10_B.status];
            prova_GPS_25_10_B.mess_type_j[prova_GPS_25_10_B.f_d] = (messaggio ==
              bb[prova_GPS_25_10_B.f_d]);
            prova_GPS_25_10_B.mess_type[prova_GPS_25_10_B.f_d] = messaggio;
          }

          if (prova_GPS_25_10_ifWhileCond_h(prova_GPS_25_10_B.mess_type_j)) {
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
                 prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
                (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == ',');
            }

            prova_GPS_25_10_eml_find_a(prova_GPS_25_10_B.messaggio_m,
              prova_GPS_25_10_B.comma_gga_data, prova_GPS_25_10_B.eb_size);
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
                 prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
                (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == '*');
            }

            prova_GPS_25_10_eml_find_a(prova_GPS_25_10_B.messaggio_m,
              prova_GPS_25_10_B.star_data, prova_GPS_25_10_B.star_size);
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
                 prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
                (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == '$');
            }

            prova_GPS_25_10_eml_find_a(prova_GPS_25_10_B.messaggio_m,
              prova_GPS_25_10_B.fb_data, prova_GPS_25_10_B.star_size);
            prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double
              (&prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.comma_gga_data[2]]);
            if ((real_T)prova_GPS_25_10_B.comma_gga_data[2] + 3.0 > (real_T)
                prova_GPS_25_10_B.comma_gga_data[3] - 1.0) {
              prova_GPS_25_10_B.caso = 0;
              prova_GPS_25_10_B.f_d = 0;
            } else {
              prova_GPS_25_10_B.caso = prova_GPS_25_10_B.comma_gga_data[2] + 2;
              prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[3] - 1;
            }

            prova_GPS_25_10_B.messaggio_size[0] = 1;
            prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
              prova_GPS_25_10_B.caso;
            prova_GPS_25_10_B.messaggio_size[1] = prova_GPS_25_10_B.status;
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                 prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                prova_GPS_25_10_B.f_d];
            }

            prova_GPS_25_10_B.b_x = prova_GPS_25_10_str2double_f
              (prova_GPS_25_10_B.messaggio_data,
               prova_GPS_25_10_B.messaggio_size);
            if (prova_GPS_25_10_B.b_x.im == 0.0) {
              prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
            } else if (prova_GPS_25_10_B.b_x.re == 0.0) {
              prova_GPS_25_10_B.num_254 = 0.0;
            } else {
              prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
            }

            prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_B.Lat_1.re +
              prova_GPS_25_10_B.num_254;
            prova_GPS_25_10_B.caso = prova_GPS_25_10_B.eb_size[0] *
              prova_GPS_25_10_B.eb_size[1] - 1;
            if (0 <= prova_GPS_25_10_B.caso) {
              memcpy(&prova_GPS_25_10_B.tmp_data[0],
                     &prova_GPS_25_10_B.comma_gga_data[0],
                     (prova_GPS_25_10_B.caso + 1) * sizeof(int32_T));
            }

            if (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.tmp_data[3]] ==
                'S') {
              prova_GPS_25_10_B.RateTransition =
                -prova_GPS_25_10_B.RateTransition;
            }

            prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_ft
              (&prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.comma_gga_data[4]]);
            if ((real_T)prova_GPS_25_10_B.comma_gga_data[4] + 4.0 > (real_T)
                prova_GPS_25_10_B.comma_gga_data[5] - 1.0) {
              prova_GPS_25_10_B.i = 0;
              prova_GPS_25_10_B.f_d = 0;
            } else {
              prova_GPS_25_10_B.i = prova_GPS_25_10_B.comma_gga_data[4] + 3;
              prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[5] - 1;
            }

            prova_GPS_25_10_B.messaggio_size_k[0] = 1;
            prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
              prova_GPS_25_10_B.i;
            prova_GPS_25_10_B.messaggio_size_k[1] = prova_GPS_25_10_B.status;
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                 prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.i +
                prova_GPS_25_10_B.f_d];
            }

            prova_GPS_25_10_B.b_x = prova_GPS_25_10_str2double_f
              (prova_GPS_25_10_B.messaggio_data,
               prova_GPS_25_10_B.messaggio_size_k);
            if (prova_GPS_25_10_B.b_x.im == 0.0) {
              prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
            } else if (prova_GPS_25_10_B.b_x.re == 0.0) {
              prova_GPS_25_10_B.num_254 = 0.0;
            } else {
              prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
            }

            prova_GPS_25_10_B.num_254 += prova_GPS_25_10_B.Lat_1.re;
            if (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.tmp_data[5]] ==
                'W') {
              prova_GPS_25_10_B.num_254 = -prova_GPS_25_10_B.num_254;
            }

            if ((real_T)prova_GPS_25_10_B.comma_gga_data[6] + 1.0 > (real_T)
                prova_GPS_25_10_B.comma_gga_data[7] - 1.0) {
              prova_GPS_25_10_B.i = 0;
              prova_GPS_25_10_B.f_d = 0;
            } else {
              prova_GPS_25_10_B.i = prova_GPS_25_10_B.comma_gga_data[6];
              prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[7] - 1;
            }

            prova_GPS_25_10_B.messaggio_size_c[0] = 1;
            prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
              prova_GPS_25_10_B.i;
            prova_GPS_25_10_B.messaggio_size_c[1] = prova_GPS_25_10_B.status;
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                 prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.i +
                prova_GPS_25_10_B.f_d];
            }

            prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_f
              (prova_GPS_25_10_B.messaggio_data,
               prova_GPS_25_10_B.messaggio_size_c);

            /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
            prova_GPS_25_10_B.ComplextoRealImag[2] = prova_GPS_25_10_B.Lat_1.re;
            if ((real_T)prova_GPS_25_10_B.comma_gga_data[7] + 1.0 > (real_T)
                prova_GPS_25_10_B.comma_gga_data[8] - 1.0) {
              prova_GPS_25_10_B.caso = 0;
              prova_GPS_25_10_B.f_d = 0;
            } else {
              prova_GPS_25_10_B.caso = prova_GPS_25_10_B.comma_gga_data[7];
              prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[8] - 1;
            }

            prova_GPS_25_10_B.messaggio_size_b[0] = 1;
            prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
              prova_GPS_25_10_B.caso;
            prova_GPS_25_10_B.messaggio_size_b[1] = prova_GPS_25_10_B.status;
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                 prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                prova_GPS_25_10_B.f_d];
            }

            prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_f
              (prova_GPS_25_10_B.messaggio_data,
               prova_GPS_25_10_B.messaggio_size_b);

            /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
            prova_GPS_25_10_B.ComplextoRealImag[4] = prova_GPS_25_10_B.Lat_1.re;
            if ((real_T)prova_GPS_25_10_B.comma_gga_data[9] + 1.0 > (real_T)
                prova_GPS_25_10_B.comma_gga_data[10] - 1.0) {
              prova_GPS_25_10_B.caso = 0;
              prova_GPS_25_10_B.f_d = 0;
            } else {
              prova_GPS_25_10_B.caso = prova_GPS_25_10_B.comma_gga_data[9];
              prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[10] - 1;
            }

            prova_GPS_25_10_B.messaggio_size_p[0] = 1;
            prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
              prova_GPS_25_10_B.caso;
            prova_GPS_25_10_B.messaggio_size_p[1] = prova_GPS_25_10_B.status;
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                 prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                prova_GPS_25_10_B.f_d];
            }

            prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_f
              (prova_GPS_25_10_B.messaggio_data,
               prova_GPS_25_10_B.messaggio_size_p);

            /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
            prova_GPS_25_10_B.ComplextoRealImag[3] = prova_GPS_25_10_B.Lat_1.re;
            if (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.tmp_data[10]] ==
                'W') {
              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[3] =
                -prova_GPS_25_10_B.Lat_1.re;
            }

            /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
            prova_GPS_25_10_B.ComplextoRealImag[5] =
              prova_GPS_25_10_DW.Memory_PreviousInput_i[5];
            prova_GPS_25_10_B.ComplextoRealImag[6] =
              prova_GPS_25_10_DW.Memory_PreviousInput_i[6];
            prova_GPS_25_10_B.ComplextoRealImag[7] =
              prova_GPS_25_10_DW.Memory_PreviousInput_i[7];
            prova_GPS_25_10_B.ComplextoRealImag[8] =
              prova_GPS_25_10_DW.Memory_PreviousInput_i[8];
            if ((real_T)prova_GPS_25_10_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)prova_GPS_25_10_B.star_data[0] + 1.0 >= 0.0) {
                counter = (uint8_T)((real_T)prova_GPS_25_10_B.star_data[0] + 1.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[0] = prova_GPS_25_10_B.messaggio[counter - 1];
            if ((real_T)prova_GPS_25_10_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)prova_GPS_25_10_B.star_data[0] + 2.0 >= 0.0) {
                counter = (uint8_T)((real_T)prova_GPS_25_10_B.star_data[0] + 2.0);
              } else {
                counter = 0U;
              }
            } else {
              counter = MAX_uint8_T;
            }

            ck_ric[1] = prova_GPS_25_10_B.messaggio[counter - 1];
            if ((real_T)prova_GPS_25_10_B.fb_data[0] + 1.0 > (real_T)
                prova_GPS_25_10_B.star_data[0] - 1.0) {
              prova_GPS_25_10_B.caso = 0;
              prova_GPS_25_10_B.status = 0;
            } else {
              prova_GPS_25_10_B.caso = prova_GPS_25_10_B.fb_data[0];
              prova_GPS_25_10_B.status = prova_GPS_25_10_B.star_data[0] - 1;
            }

            prova_GPS_25_10_B.status -= prova_GPS_25_10_B.caso;
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                 prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.NMEA_gga_string_data[prova_GPS_25_10_B.f_d] =
                (uint8_T)prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                prova_GPS_25_10_B.f_d];
            }

            counter = 0U;
            prova_GPS_25_10_B.f_d = 0;
            while (prova_GPS_25_10_B.f_d <= prova_GPS_25_10_B.status - 1) {
              counter ^=
                prova_GPS_25_10_B.NMEA_gga_string_data[prova_GPS_25_10_B.f_d];
              prova_GPS_25_10_B.f_d++;
            }

            if (counter != prova_GPS_25_10_hex2dec(ck_ric)) {
              prova_GPS_25_10_B.RateTransition =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[0];
              prova_GPS_25_10_B.num_254 =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[1];

              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[2] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[2];
              prova_GPS_25_10_B.ComplextoRealImag[3] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[3];
              prova_GPS_25_10_B.ComplextoRealImag[4] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[4];
            }
          } else {
            for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 5;
                 prova_GPS_25_10_B.f_d++) {
              prova_GPS_25_10_B.mess_type_j[prova_GPS_25_10_B.f_d] =
                (prova_GPS_25_10_B.mess_type[prova_GPS_25_10_B.f_d] ==
                 cb[prova_GPS_25_10_B.f_d]);
            }

            if (prova_GPS_25_10_ifWhileCond_h(prova_GPS_25_10_B.mess_type_j)) {
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
                   prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
                  (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == ',');
              }

              prova_GPS_25_10_eml_find_a(prova_GPS_25_10_B.messaggio_m,
                prova_GPS_25_10_B.comma_gga_data, prova_GPS_25_10_B.eb_size);
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
                   prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
                  (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == '*');
              }

              prova_GPS_25_10_eml_find_a(prova_GPS_25_10_B.messaggio_m,
                prova_GPS_25_10_B.star_data, prova_GPS_25_10_B.star_size);
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d < 80;
                   prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_m[prova_GPS_25_10_B.f_d] =
                  (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.f_d] == '$');
              }

              prova_GPS_25_10_eml_find_a(prova_GPS_25_10_B.messaggio_m,
                prova_GPS_25_10_B.fb_data, prova_GPS_25_10_B.star_size);
              prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double
                (&prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.comma_gga_data[1]]);
              if ((real_T)prova_GPS_25_10_B.comma_gga_data[1] + 3.0 > (real_T)
                  prova_GPS_25_10_B.comma_gga_data[2] - 1.0) {
                prova_GPS_25_10_B.caso = 0;
                prova_GPS_25_10_B.f_d = 0;
              } else {
                prova_GPS_25_10_B.caso = prova_GPS_25_10_B.comma_gga_data[1] + 2;
                prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[2] - 1;
              }

              prova_GPS_25_10_B.messaggio_size[0] = 1;
              prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
                prova_GPS_25_10_B.caso;
              prova_GPS_25_10_B.messaggio_size[1] = prova_GPS_25_10_B.status;
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                   prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                  prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                  prova_GPS_25_10_B.f_d];
              }

              prova_GPS_25_10_B.b_x = prova_GPS_25_10_str2double_f
                (prova_GPS_25_10_B.messaggio_data,
                 prova_GPS_25_10_B.messaggio_size);
              if (prova_GPS_25_10_B.b_x.im == 0.0) {
                prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
              } else if (prova_GPS_25_10_B.b_x.re == 0.0) {
                prova_GPS_25_10_B.num_254 = 0.0;
              } else {
                prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
              }

              prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_B.Lat_1.re +
                prova_GPS_25_10_B.num_254;
              prova_GPS_25_10_B.caso = prova_GPS_25_10_B.eb_size[0] *
                prova_GPS_25_10_B.eb_size[1] - 1;
              if (0 <= prova_GPS_25_10_B.caso) {
                memcpy(&prova_GPS_25_10_B.tmp_data[0],
                       &prova_GPS_25_10_B.comma_gga_data[0],
                       (prova_GPS_25_10_B.caso + 1) * sizeof(int32_T));
              }

              if (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.tmp_data[2]] ==
                  'S') {
                prova_GPS_25_10_B.RateTransition =
                  -prova_GPS_25_10_B.RateTransition;
              }

              prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_ft
                (&prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.comma_gga_data[3]]);
              if ((real_T)prova_GPS_25_10_B.comma_gga_data[3] + 4.0 > (real_T)
                  prova_GPS_25_10_B.comma_gga_data[4] - 1.0) {
                prova_GPS_25_10_B.i = 0;
                prova_GPS_25_10_B.f_d = 0;
              } else {
                prova_GPS_25_10_B.i = prova_GPS_25_10_B.comma_gga_data[3] + 3;
                prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[4] - 1;
              }

              prova_GPS_25_10_B.messaggio_size_k[0] = 1;
              prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
                prova_GPS_25_10_B.i;
              prova_GPS_25_10_B.messaggio_size_k[1] = prova_GPS_25_10_B.status;
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                   prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                  prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.i +
                  prova_GPS_25_10_B.f_d];
              }

              prova_GPS_25_10_B.b_x = prova_GPS_25_10_str2double_f
                (prova_GPS_25_10_B.messaggio_data,
                 prova_GPS_25_10_B.messaggio_size_k);
              if (prova_GPS_25_10_B.b_x.im == 0.0) {
                prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
              } else if (prova_GPS_25_10_B.b_x.re == 0.0) {
                prova_GPS_25_10_B.num_254 = 0.0;
              } else {
                prova_GPS_25_10_B.num_254 = prova_GPS_25_10_B.b_x.re / 60.0;
              }

              prova_GPS_25_10_B.num_254 += prova_GPS_25_10_B.Lat_1.re;
              if (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.tmp_data[4]] ==
                  'W') {
                prova_GPS_25_10_B.num_254 = -prova_GPS_25_10_B.num_254;
              }

              prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_ftn
                (prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.comma_gga_data[5]]);

              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[5] =
                prova_GPS_25_10_B.Lat_1.re;
              if ((real_T)prova_GPS_25_10_B.comma_gga_data[6] + 1.0 > (real_T)
                  prova_GPS_25_10_B.comma_gga_data[7] - 1.0) {
                prova_GPS_25_10_B.caso = 0;
                prova_GPS_25_10_B.f_d = 0;
              } else {
                prova_GPS_25_10_B.caso = prova_GPS_25_10_B.comma_gga_data[6];
                prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[7] - 1;
              }

              prova_GPS_25_10_B.messaggio_size_c[0] = 1;
              prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
                prova_GPS_25_10_B.caso;
              prova_GPS_25_10_B.messaggio_size_c[1] = prova_GPS_25_10_B.status;
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                   prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                  prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                  prova_GPS_25_10_B.f_d];
              }

              prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_f
                (prova_GPS_25_10_B.messaggio_data,
                 prova_GPS_25_10_B.messaggio_size_c);

              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[6] =
                prova_GPS_25_10_B.Lat_1.re;
              if ((real_T)prova_GPS_25_10_B.comma_gga_data[8] + 1.0 > (real_T)
                  prova_GPS_25_10_B.comma_gga_data[9] - 1.0) {
                prova_GPS_25_10_B.i = 0;
                prova_GPS_25_10_B.f_d = 0;
              } else {
                prova_GPS_25_10_B.i = prova_GPS_25_10_B.comma_gga_data[8];
                prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.comma_gga_data[9] - 1;
              }

              prova_GPS_25_10_B.messaggio_size_b[0] = 1;
              prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
                prova_GPS_25_10_B.i;
              prova_GPS_25_10_B.messaggio_size_b[1] = prova_GPS_25_10_B.status;
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                   prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                  prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.i +
                  prova_GPS_25_10_B.f_d];
              }

              prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_f
                (prova_GPS_25_10_B.messaggio_data,
                 prova_GPS_25_10_B.messaggio_size_b);

              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[7] =
                prova_GPS_25_10_B.Lat_1.re;
              if ((real_T)prova_GPS_25_10_B.comma_gga_data[10] + 1.0 > (real_T)
                  prova_GPS_25_10_B.comma_gga_data[11] - 1.0) {
                prova_GPS_25_10_B.i = 0;
                prova_GPS_25_10_B.caso = 0;
              } else {
                prova_GPS_25_10_B.i = prova_GPS_25_10_B.comma_gga_data[10];
                prova_GPS_25_10_B.caso = prova_GPS_25_10_B.comma_gga_data[11] -
                  1;
              }

              prova_GPS_25_10_B.messaggio_size_p[0] = 1;
              prova_GPS_25_10_B.status = prova_GPS_25_10_B.caso -
                prova_GPS_25_10_B.i;
              prova_GPS_25_10_B.messaggio_size_p[1] = prova_GPS_25_10_B.status;
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                   prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.messaggio_data[prova_GPS_25_10_B.f_d] =
                  prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.i +
                  prova_GPS_25_10_B.f_d];
              }

              prova_GPS_25_10_B.Lat_1 = prova_GPS_25_10_str2double_f
                (prova_GPS_25_10_B.messaggio_data,
                 prova_GPS_25_10_B.messaggio_size_p);

              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[8] =
                prova_GPS_25_10_B.Lat_1.re;
              prova_GPS_25_10_B.ComplextoRealImag[2] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[2];
              prova_GPS_25_10_B.ComplextoRealImag[3] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[3];
              prova_GPS_25_10_B.ComplextoRealImag[4] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[4];
              if ((real_T)prova_GPS_25_10_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)prova_GPS_25_10_B.star_data[0] + 1.0 >= 0.0) {
                  counter = (uint8_T)((real_T)prova_GPS_25_10_B.star_data[0] +
                                      1.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[0] = prova_GPS_25_10_B.messaggio[counter - 1];
              if ((real_T)prova_GPS_25_10_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)prova_GPS_25_10_B.star_data[0] + 2.0 >= 0.0) {
                  counter = (uint8_T)((real_T)prova_GPS_25_10_B.star_data[0] +
                                      2.0);
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              ck_ric[1] = prova_GPS_25_10_B.messaggio[counter - 1];
              if ((real_T)prova_GPS_25_10_B.fb_data[0] + 1.0 > (real_T)
                  prova_GPS_25_10_B.star_data[0] - 1.0) {
                prova_GPS_25_10_B.caso = 0;
                prova_GPS_25_10_B.f_d = 0;
              } else {
                prova_GPS_25_10_B.caso = prova_GPS_25_10_B.fb_data[0];
                prova_GPS_25_10_B.f_d = prova_GPS_25_10_B.star_data[0] - 1;
              }

              prova_GPS_25_10_B.status = prova_GPS_25_10_B.f_d -
                prova_GPS_25_10_B.caso;
              for (prova_GPS_25_10_B.f_d = 0; prova_GPS_25_10_B.f_d <
                   prova_GPS_25_10_B.status; prova_GPS_25_10_B.f_d++) {
                prova_GPS_25_10_B.NMEA_gga_string_data[prova_GPS_25_10_B.f_d] =
                  (uint8_T)prova_GPS_25_10_B.messaggio[prova_GPS_25_10_B.caso +
                  prova_GPS_25_10_B.f_d];
              }

              counter = 0U;
              prova_GPS_25_10_B.f_d = 0;
              while (prova_GPS_25_10_B.f_d <= prova_GPS_25_10_B.status - 1) {
                counter ^=
                  prova_GPS_25_10_B.NMEA_gga_string_data[prova_GPS_25_10_B.f_d];
                prova_GPS_25_10_B.f_d++;
              }

              if (counter != prova_GPS_25_10_hex2dec(ck_ric)) {
                prova_GPS_25_10_B.RateTransition =
                  prova_GPS_25_10_DW.Memory_PreviousInput_i[0];
                prova_GPS_25_10_B.num_254 =
                  prova_GPS_25_10_DW.Memory_PreviousInput_i[1];

                /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
                prova_GPS_25_10_B.ComplextoRealImag[5] =
                  prova_GPS_25_10_DW.Memory_PreviousInput_i[5];
                prova_GPS_25_10_B.ComplextoRealImag[6] =
                  prova_GPS_25_10_DW.Memory_PreviousInput_i[6];
                prova_GPS_25_10_B.ComplextoRealImag[7] =
                  prova_GPS_25_10_DW.Memory_PreviousInput_i[7];
                prova_GPS_25_10_B.ComplextoRealImag[8] =
                  prova_GPS_25_10_DW.Memory_PreviousInput_i[8];
              }
            } else {
              prova_GPS_25_10_B.RateTransition =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[0];
              prova_GPS_25_10_B.num_254 =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[1];

              /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
              prova_GPS_25_10_B.ComplextoRealImag[2] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[2];
              prova_GPS_25_10_B.ComplextoRealImag[3] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[3];
              prova_GPS_25_10_B.ComplextoRealImag[4] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[4];
              prova_GPS_25_10_B.ComplextoRealImag[5] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[5];
              prova_GPS_25_10_B.ComplextoRealImag[6] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[6];
              prova_GPS_25_10_B.ComplextoRealImag[7] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[7];
              prova_GPS_25_10_B.ComplextoRealImag[8] =
                prova_GPS_25_10_DW.Memory_PreviousInput_i[8];
            }
          }
        } else {
          prova_GPS_25_10_B.RateTransition =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[0];
          prova_GPS_25_10_B.num_254 = prova_GPS_25_10_DW.Memory_PreviousInput_i
            [1];

          /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
          prova_GPS_25_10_B.ComplextoRealImag[2] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[2];
          prova_GPS_25_10_B.ComplextoRealImag[3] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[3];
          prova_GPS_25_10_B.ComplextoRealImag[4] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[4];
          prova_GPS_25_10_B.ComplextoRealImag[5] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[5];
          prova_GPS_25_10_B.ComplextoRealImag[6] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[6];
          prova_GPS_25_10_B.ComplextoRealImag[7] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[7];
          prova_GPS_25_10_B.ComplextoRealImag[8] =
            prova_GPS_25_10_DW.Memory_PreviousInput_i[8];
        }

        /* End of MATLAB Function: '<S22>/MATLAB Function' */

        /* ComplexToRealImag: '<S22>/Complex to Real-Imag' */
        prova_GPS_25_10_B.ComplextoRealImag[0] =
          prova_GPS_25_10_B.RateTransition;
        prova_GPS_25_10_B.ComplextoRealImag[1] = prova_GPS_25_10_B.num_254;

        /* Update for Memory: '<S22>/Memory' */
        memcpy(&prova_GPS_25_10_DW.Memory_PreviousInput_i[0],
               &prova_GPS_25_10_B.ComplextoRealImag[0], 9U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S20>/Subsystem' */
      } else {
        for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 32;
             prova_GPS_25_10_B.i++) {
          prova_GPS_25_10_B.f_d = (int32_T)(((uint32_T)
            prova_GPS_25_10_DW.counter_k + prova_GPS_25_10_B.i) + 1U);
          if ((uint32_T)prova_GPS_25_10_B.f_d > 255U) {
            prova_GPS_25_10_B.f_d = 255;
          }

          prova_GPS_25_10_DW.message[prova_GPS_25_10_B.f_d - 1] =
            prova_GPS_25_10_B.b_dataOut[prova_GPS_25_10_B.i];
        }

        prova_GPS_25_10_B.f_d = (int32_T)(prova_GPS_25_10_DW.counter_k + 32U);
        if (prova_GPS_25_10_DW.counter_k + 32U > 255U) {
          prova_GPS_25_10_B.f_d = 255;
        }

        prova_GPS_25_10_DW.counter_k = (uint8_T)prova_GPS_25_10_B.f_d;
      }
    }

    /* End of MATLAB Function: '<S20>/Create_message' */
  }

  /* End of MATLABSystem: '<S18>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S18>/Subsystem2' */

  /* Gain: '<S8>/Gain' */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain_Gain_i[0] *
    prova_GPS_25_10_B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  prova_GPS_25_10_B.DataTypeConversion_j[0] = prova_GPS_25_10_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-prova_GPS_25_10_B.RateTransition : (int32_T)
    (uint32_T)prova_GPS_25_10_B.RateTransition;

  /* Gain: '<S8>/Gain' */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain_Gain_i[1] *
    prova_GPS_25_10_B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  prova_GPS_25_10_B.DataTypeConversion_j[1] = prova_GPS_25_10_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-prova_GPS_25_10_B.RateTransition : (int32_T)
    (uint32_T)prova_GPS_25_10_B.RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Sum: '<S18>/Sum'
   */
  prova_GPS_25_10_B.RateTransition = (prova_GPS_25_10_B.ComplextoRealImag[7] -
    prova_GPS_25_10_B.Switch) * prova_GPS_25_10_P.Gain_Gain_i[2];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  prova_GPS_25_10_B.DataTypeConversion_j[2] = prova_GPS_25_10_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-prova_GPS_25_10_B.RateTransition : (int32_T)
    (uint32_T)prova_GPS_25_10_B.RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/alt_r'
   */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain_Gain_i[3] *
    prova_GPS_25_10_P.alt_r_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  prova_GPS_25_10_B.DataTypeConversion_j[3] = prova_GPS_25_10_B.RateTransition <
    0.0 ? -(int32_T)(uint32_T)-prova_GPS_25_10_B.RateTransition : (int32_T)
    (uint32_T)prova_GPS_25_10_B.RateTransition;

  /* Gain: '<S8>/Gain1' */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain1_Gain *
    prova_GPS_25_10_B.ComplextoRealImag[2];

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  prova_GPS_25_10_B.DataTypeConversion1_k[0] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/vel y'
   */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain1_Gain *
    prova_GPS_25_10_P.vely_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  prova_GPS_25_10_B.DataTypeConversion1_k[1] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/RC Simulated'
   */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain1_Gain *
    prova_GPS_25_10_P.RCSimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  prova_GPS_25_10_B.DataTypeConversion1_k[2] = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* Gain: '<S8>/Gain2' */
  prova_GPS_25_10_B.RateTransition = prova_GPS_25_10_P.Gain2_Gain_o *
    prova_GPS_25_10_B.ComplextoRealImag[4];

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  if (prova_GPS_25_10_B.RateTransition < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.RateTransition);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.RateTransition);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  prova_GPS_25_10_B.DataTypeConversion2 = (uint16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S14>/RC simulated'
   *  Constant: '<S14>/TAS simulated'
   *  Constant: '<S14>/v simulated'
   */
  prova_GPS_25_10_B.DataTypeConversion3_a[0] = (real32_T)
    prova_GPS_25_10_P.TASsimulated_Value;
  prova_GPS_25_10_B.DataTypeConversion3_a[1] = (real32_T)
    prova_GPS_25_10_P.vsimulated_Value;
  prova_GPS_25_10_B.DataTypeConversion3_a[2] = (real32_T)
    prova_GPS_25_10_P.Constant_Value_g;
  prova_GPS_25_10_B.DataTypeConversion3_a[3] = (real32_T)
    prova_GPS_25_10_P.RCsimulated_Value;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/ Heading simulated'
   */
  prova_GPS_25_10_B.RateTransition = floor
    (prova_GPS_25_10_P.Headingsimulated_Value);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion4' */
  prova_GPS_25_10_B.DataTypeConversion4_o = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
   *  Constant: '<S14>/Rpm simulated'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Rpmsimulated_Value);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion5' */
  prova_GPS_25_10_B.DataTypeConversion5 = (uint16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* Gain: '<S27>/Gain2' incorporates:
   *  Constant: '<S12>/Manetta Simulated'
   */
  prova_GPS_25_10_B.num_254 = prova_GPS_25_10_P.Gain2_Gain_f *
    prova_GPS_25_10_P.ManettaSimulated_Value;

  /* Sum: '<S27>/Sum' incorporates:
   *  Constant: '<S12>/Equilibratore Simulated'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S28>/Gain'
   */
  prova_GPS_25_10_B.Sum = prova_GPS_25_10_P.Gain_Gain_d *
    prova_GPS_25_10_P.EquilibratoreSimulated_Value +
    prova_GPS_25_10_P.Constant2_Value_l;

  /* Sum: '<S27>/Sum1' incorporates:
   *  Constant: '<S12>/Alettoni Simulated'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S29>/Gain'
   */
  prova_GPS_25_10_B.Sum1 = prova_GPS_25_10_P.Gain_Gain_n *
    prova_GPS_25_10_P.AlettoniSimulated_Value +
    prova_GPS_25_10_P.Constant2_Value_l;

  /* Sum: '<S27>/Sum2' incorporates:
   *  Constant: '<S12>/Timone Simulated'
   *  Constant: '<S27>/Constant2'
   *  Gain: '<S30>/Gain'
   */
  prova_GPS_25_10_B.Sum2 = prova_GPS_25_10_P.Gain_Gain_p *
    prova_GPS_25_10_P.TimoneSimulated_Value +
    prova_GPS_25_10_P.Constant2_Value_l;

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S12>/Constant2'
   */
  prova_GPS_25_10_B.PatohPa1 = prova_GPS_25_10_P.Gain_Gain_g *
    prova_GPS_25_10_P.Constant2_Value_i;

  /* Saturate: '<S12>/Saturation' */
  if (prova_GPS_25_10_B.PatohPa1 > prova_GPS_25_10_P.Saturation_UpperSat) {
    prova_GPS_25_10_B.PatohPa1 = prova_GPS_25_10_P.Saturation_UpperSat;
  } else {
    if (prova_GPS_25_10_B.PatohPa1 < prova_GPS_25_10_P.Saturation_LowerSat) {
      prova_GPS_25_10_B.PatohPa1 = prova_GPS_25_10_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant'
   */
  if (prova_GPS_25_10_P.Constant_Value_c < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_P.Constant_Value_c);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant_Value_c);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[0] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.num_254 < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.num_254);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.num_254);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[1] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.Sum < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.Sum);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.Sum);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[2] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.Sum1 < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.Sum1);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.Sum1);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[3] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.Sum2 < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.Sum2);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.Sum2);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[4] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (prova_GPS_25_10_P.Constant1_Value_gk[0] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil
      (prova_GPS_25_10_P.Constant1_Value_gk[0]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor
      (prova_GPS_25_10_P.Constant1_Value_gk[0]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[5] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (prova_GPS_25_10_P.Constant1_Value_gk[1] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil
      (prova_GPS_25_10_P.Constant1_Value_gk[1]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor
      (prova_GPS_25_10_P.Constant1_Value_gk[1]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[6] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (prova_GPS_25_10_P.Constant1_Value_gk[2] < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil
      (prova_GPS_25_10_P.Constant1_Value_gk[2]);
  } else {
    prova_GPS_25_10_B.RateTransition = floor
      (prova_GPS_25_10_P.Constant1_Value_gk[2]);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[7] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (prova_GPS_25_10_B.PatohPa1 < 0.0) {
    prova_GPS_25_10_B.RateTransition = ceil(prova_GPS_25_10_B.PatohPa1);
  } else {
    prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_B.PatohPa1);
  }

  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  prova_GPS_25_10_B.Heading[8] = (uint16_T)(prova_GPS_25_10_B.RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -prova_GPS_25_10_B.RateTransition : (int32_T)(uint16_T)
    prova_GPS_25_10_B.RateTransition);

  /* Memory: '<S2>/Memory' */
  prova_GPS_25_10_B.Memory_e = prova_GPS_25_10_DW.Memory_PreviousInput_n;

  /* DataTypeConversion: '<S2>/Data Type Conversion17' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  prova_GPS_25_10_B.DataTypeConversion17 = (real32_T)
    prova_GPS_25_10_P.Constant1_Value_m;

  /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  prova_GPS_25_10_B.DataTypeConversion4_g = (real32_T)
    prova_GPS_25_10_P.Constant5_Value_o;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<S2>/Pa to hPa'
   */
  prova_GPS_25_10_B.DataTypeConversion_a = (real32_T)
    (prova_GPS_25_10_P.PatohPa_Gain * prova_GPS_25_10_P.Constant3_Value_k2);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  prova_GPS_25_10_B.DataTypeConversion1 = (real32_T)
    (prova_GPS_25_10_P.PatohPa1_Gain * prova_GPS_25_10_P.Constant2_Value_a);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  prova_GPS_25_10_B.RateTransition = floor(prova_GPS_25_10_P.Constant4_Value_f);
  if (rtIsNaN(prova_GPS_25_10_B.RateTransition) || rtIsInf
      (prova_GPS_25_10_B.RateTransition)) {
    prova_GPS_25_10_B.RateTransition = 0.0;
  } else {
    prova_GPS_25_10_B.RateTransition = fmod(prova_GPS_25_10_B.RateTransition,
      65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  prova_GPS_25_10_B.DataTypeConversion2_c = (int16_T)
    (prova_GPS_25_10_B.RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-prova_GPS_25_10_B.RateTransition : (int32_T)(int16_T)(uint16_T)
     prova_GPS_25_10_B.RateTransition);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&prova_GPS_25_10_B.iflogic,
    &prova_GPS_25_10_B.DataTypeConversion3, &prova_GPS_25_10_P.SIUAVuint8_Value,
    &prova_GPS_25_10_B.GC_info[0], &prova_GPS_25_10_B.Val_out_MAV[0],
    &prova_GPS_25_10_B.WP_info[0], &prova_GPS_25_10_B.WP_param[0],
    &prova_GPS_25_10_B.onboard[0], &prova_GPS_25_10_B.LVDE[0],
    &prova_GPS_25_10_B.B_Current, &prova_GPS_25_10_B.B_Remaining,
    &prova_GPS_25_10_B.DataTypeConversion,
    &prova_GPS_25_10_B.DataTypeConversion1_n[0],
    &prova_GPS_25_10_B.DataTypeConversion3_m[0],
    &prova_GPS_25_10_B.DataTypeConversion4[0],
    &prova_GPS_25_10_B.DataTypeConversion_j[0],
    &prova_GPS_25_10_B.DataTypeConversion1_k[0],
    &prova_GPS_25_10_B.DataTypeConversion2,
    &prova_GPS_25_10_B.DataTypeConversion3_a[0],
    &prova_GPS_25_10_B.DataTypeConversion4_o,
    &prova_GPS_25_10_B.DataTypeConversion5, &prova_GPS_25_10_B.Heading[0],
    &prova_GPS_25_10_B.Memory_e, &prova_GPS_25_10_B.DataTypeConversion17,
    &prova_GPS_25_10_B.SFunction_o14, &prova_GPS_25_10_B.DataTypeConversion4_g,
    &prova_GPS_25_10_B.SFunction_o15, &prova_GPS_25_10_B.DataTypeConversion_a,
    &prova_GPS_25_10_B.DataTypeConversion1,
    &prova_GPS_25_10_B.DataTypeConversion2_c, &prova_GPS_25_10_B.SFunction_o5[0],
    &prova_GPS_25_10_P.Constant4_Value_j, &prova_GPS_25_10_P.Constant5_Value_f,
    &prova_GPS_25_10_P.Constant10_Value, ((const uint16_T*)
    &prova_GPS_25_10_U16GND), &prova_GPS_25_10_B.SFunction_o1_m,
    &prova_GPS_25_10_B.SFunction_o2_n[0], &prova_GPS_25_10_B.SFunction_o3,
    &prova_GPS_25_10_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (prova_GPS_25_10_B.SFunction_o1_m > 0) {
    /* Chart: '<S7>/Chart' */
    if (prova_GPS_25_10_DW.is_active_c9_prova_GPS_25_10 == 0U) {
      prova_GPS_25_10_DW.is_active_c9_prova_GPS_25_10 = 1U;
      prova_GPS_25_10_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (prova_GPS_25_10_DW.obj.Protocol !=
            prova_GPS_25_10_P.SerialTransmit_Protocol) {
          prova_GPS_25_10_DW.obj.Protocol =
            prova_GPS_25_10_P.SerialTransmit_Protocol;
        }

        counter = prova_GPS_25_10_B.SFunction_o2_n[prova_GPS_25_10_DW.i - 1];
        MW_Serial_write(prova_GPS_25_10_DW.obj.port, &counter, 1.0,
                        prova_GPS_25_10_DW.obj.dataSizeInBytes,
                        prova_GPS_25_10_DW.obj.sendModeEnum,
                        prova_GPS_25_10_DW.obj.dataType,
                        prova_GPS_25_10_DW.obj.sendFormatEnum, 2.0, '\x00');
        if (prova_GPS_25_10_DW.i < prova_GPS_25_10_B.SFunction_o3) {
          prova_GPS_25_10_B.f_d = prova_GPS_25_10_DW.i + 1;
          if (prova_GPS_25_10_DW.i + 1 > 255) {
            prova_GPS_25_10_B.f_d = 255;
          }

          prova_GPS_25_10_DW.i = (uint8_T)prova_GPS_25_10_B.f_d;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      prova_GPS_25_10_DW.i = 1U;
    }

    /* End of Chart: '<S7>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&prova_GPS_25_10_DW.Memory4_PreviousInput[0],
         &prova_GPS_25_10_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&prova_GPS_25_10_P.Constant1_Value_i,
    &prova_GPS_25_10_B.SFunctionBuilder_o1[0],
    &prova_GPS_25_10_B.SFunctionBuilder_o2,
    &prova_GPS_25_10_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&prova_GPS_25_10_DW.Memory5_PreviousInput[0],
         &prova_GPS_25_10_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  prova_GPS_25_10_DW.Memory_PreviousInput_m[0] =
    prova_GPS_25_10_B.DataTypeConversion1_n[0];
  prova_GPS_25_10_DW.Memory_PreviousInput_m[1] =
    prova_GPS_25_10_B.DataTypeConversion1_n[1];
  prova_GPS_25_10_DW.Memory_PreviousInput_m[2] =
    prova_GPS_25_10_B.DataTypeConversion1_n[2];
  prova_GPS_25_10_DW.Memory_PreviousInput_m[3] =
    prova_GPS_25_10_B.DataTypeConversion1_n[3];

  /* Update for Memory: '<S1>/Memory' */
  for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 8; prova_GPS_25_10_B.i++)
  {
    prova_GPS_25_10_DW.Memory_PreviousInput_g[prova_GPS_25_10_B.i] =
      prova_GPS_25_10_B.SFunction_o11[prova_GPS_25_10_B.i];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_GPS_25_10_DW.Memory2_PreviousInput_c[0] = (uint8_T)AP_mode_idx_0;
  prova_GPS_25_10_DW.Memory2_PreviousInput_c[1] = (uint8_T)AP_mode_idx_1;
  for (prova_GPS_25_10_B.i = 0; prova_GPS_25_10_B.i < 7; prova_GPS_25_10_B.i++)
  {
    prova_GPS_25_10_B.f = rt_roundf_snf
      (prova_GPS_25_10_DW.riferimenti[prova_GPS_25_10_B.i]);
    if (prova_GPS_25_10_B.f < 256.0F) {
      if (prova_GPS_25_10_B.f >= 0.0F) {
        prova_GPS_25_10_DW.Memory2_PreviousInput_c[prova_GPS_25_10_B.i + 2] =
          (uint8_T)prova_GPS_25_10_B.f;
      } else {
        prova_GPS_25_10_DW.Memory2_PreviousInput_c[prova_GPS_25_10_B.i + 2] = 0U;
      }
    } else {
      prova_GPS_25_10_DW.Memory2_PreviousInput_c[prova_GPS_25_10_B.i + 2] =
        MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for Memory: '<S2>/Memory' */
  prova_GPS_25_10_DW.Memory_PreviousInput_n = prova_GPS_25_10_B.SFunction_o4;
}

/* Model step function for TID1 */
void prova_GPS_25_10_step1(void)       /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S25>/Add2' incorporates:
   *  Constant: '<S25>/Constant4'
   *  Constant: '<S25>/Constant5'
   *  Memory: '<S25>/Memory2'
   */
  prova_GPS_25_10_DW.Memory2_PreviousInput +=
    prova_GPS_25_10_P.Constant4_Value_d + prova_GPS_25_10_P.Constant5_Value_k;

  /* Switch: '<S25>/Switch1' */
  if (prova_GPS_25_10_DW.Memory2_PreviousInput >
      prova_GPS_25_10_P.Switch1_Threshold) {
    /* Sum: '<S25>/Add2' incorporates:
     *  Constant: '<S25>/Constant4'
     */
    prova_GPS_25_10_DW.Memory2_PreviousInput =
      prova_GPS_25_10_P.Constant4_Value_d;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* RateTransition: '<S25>/Rate Transition' */
  prova_GPS_25_10_DW.RateTransition_Buffer0 =
    prova_GPS_25_10_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void prova_GPS_25_10_initialize(void)
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
    memcpy(&prova_GPS_25_10_DW.Memory4_PreviousInput[0],
           &prova_GPS_25_10_P.Memory4_InitialCondition[0], 300U * sizeof(uint8_T));

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          prova_GPS_25_10_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      prova_GPS_25_10_DW.Memory5_PreviousInput[i] =
        prova_GPS_25_10_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[0] =
      prova_GPS_25_10_P.Memory1_InitialCondition_l;
    prova_GPS_25_10_DW.Memory1_PreviousInput_j[1] =
      prova_GPS_25_10_P.Memory1_InitialCondition_l;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    prova_GPS_25_10_DW.Memory_PreviousInput_m[0] =
      prova_GPS_25_10_P.Memory_InitialCondition_f;
    prova_GPS_25_10_DW.Memory_PreviousInput_m[1] =
      prova_GPS_25_10_P.Memory_InitialCondition_f;
    prova_GPS_25_10_DW.Memory_PreviousInput_m[2] =
      prova_GPS_25_10_P.Memory_InitialCondition_f;
    prova_GPS_25_10_DW.Memory_PreviousInput_m[3] =
      prova_GPS_25_10_P.Memory_InitialCondition_f;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    prova_GPS_25_10_DW.Memory3_PreviousInput =
      prova_GPS_25_10_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      prova_GPS_25_10_DW.Memory_PreviousInput_g[i] =
        prova_GPS_25_10_P.Memory_InitialCondition_o;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      prova_GPS_25_10_DW.Memory2_PreviousInput_c[i] =
        prova_GPS_25_10_P.Memory2_InitialCondition_j[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S25>/Rate Transition' */
    prova_GPS_25_10_DW.RateTransition_Buffer0 =
      prova_GPS_25_10_P.RateTransition_InitialCondition;

    /* InitializeConditions for DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
     *  Memory: '<S25>/Memory1'
     */
    prova_GPS_25_10_DW.Memory1_PreviousInput =
      prova_GPS_25_10_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S25>/Add' incorporates:
     *  Memory: '<S25>/Memory'
     */
    prova_GPS_25_10_DW.Memory_PreviousInput =
      prova_GPS_25_10_P.Memory_InitialCondition_k;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    prova_GPS_25_10_DW.Memory_PreviousInput_n =
      prova_GPS_25_10_P.Memory_InitialCondition_d;

    /* InitializeConditions for Sum: '<S25>/Add2' incorporates:
     *  Memory: '<S25>/Memory2'
     */
    prova_GPS_25_10_DW.Memory2_PreviousInput =
      prova_GPS_25_10_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&prova_GPS_25_10_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S7>/Chart' incorporates:
     *  SubSystem: '<S16>/sendbyte'
     */
    /* Start for MATLABSystem: '<S17>/Serial Transmit' */
    prova_GPS_25_10_DW.obj.matlabCodegenIsDeleted = false;
    prova_GPS_25_10_DW.obj.Protocol = prova_GPS_25_10_P.SerialTransmit_Protocol;
    prova_GPS_25_10_DW.obj.isInitialized = 1;
    prova_GPS_25_10_DW.obj.port = 2.0;
    prova_GPS_25_10_DW.obj.dataSizeInBytes = 1.0;
    prova_GPS_25_10_DW.obj.dataType = 0.0;
    prova_GPS_25_10_DW.obj.sendModeEnum = 0.0;
    prova_GPS_25_10_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(prova_GPS_25_10_DW.obj.port);
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
    prova_GPS_25_10_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S17>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/Subsystem1' */
    /* SystemInitialize for Switch: '<S19>/Switch' incorporates:
     *  Outport: '<S19>/h_to_subtract'
     */
    prova_GPS_25_10_B.Switch = prova_GPS_25_10_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S20>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S22>/Memory' */
      prova_GPS_25_10_DW.Memory_PreviousInput_i[i] =
        prova_GPS_25_10_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S22>/Complex to Real-Imag' incorporates:
       *  Outport: '<S22>/Outport'
       */
      prova_GPS_25_10_B.ComplextoRealImag[i] = prova_GPS_25_10_P.Outport_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S20>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S18>/Subsystem2' */

    /* Start for MATLABSystem: '<S18>/Serial Receive1' */
    prova_GPS_25_10_DW.obj_m.matlabCodegenIsDeleted = false;
    prova_GPS_25_10_DW.obj_m.Protocol =
      prova_GPS_25_10_P.SerialReceive1_Protocol;
    prova_GPS_25_10_DW.obj_m.isInitialized = 1;
    prova_GPS_25_10_DW.obj_m.DataTypeWidth = 1U;
    if (prova_GPS_25_10_DW.obj_m.DataTypeWidth > 2047) {
      prova_GPS_25_10_DW.obj_m.DataSizeInBytes = MAX_uint16_T;
    } else {
      prova_GPS_25_10_DW.obj_m.DataSizeInBytes = (uint16_T)
        (prova_GPS_25_10_DW.obj_m.DataTypeWidth << 5);
    }

    MW_SCI_Open(3);
    prova_GPS_25_10_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S18>/Serial Receive1' */
  }
}

/* Model terminate function */
void prova_GPS_25_10_terminate(void)
{
  /* Terminate for MATLABSystem: '<S18>/Serial Receive1' */
  if (!prova_GPS_25_10_DW.obj_m.matlabCodegenIsDeleted) {
    prova_GPS_25_10_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S18>/Serial Receive1' */

  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S7>/Chart' incorporates:
   *  SubSystem: '<S16>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S17>/Serial Transmit' */
  if (!prova_GPS_25_10_DW.obj.matlabCodegenIsDeleted) {
    prova_GPS_25_10_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S17>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
