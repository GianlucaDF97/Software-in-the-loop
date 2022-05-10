/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_gps_26_10.c
 *
 * Code generated for Simulink model 'prova_gps_26_10'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 26 17:30:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_gps_26_10.h"
#include "prova_gps_26_10_private.h"

/* Block signals (default storage) */
B_prova_gps_26_10_T prova_gps_26_10_B;

/* Block states (default storage) */
DW_prova_gps_26_10_T prova_gps_26_10_DW;

/* Real-time model */
static RT_MODEL_prova_gps_26_10_T prova_gps_26_10_M_;
RT_MODEL_prova_gps_26_10_T *const prova_gps_26_10_M = &prova_gps_26_10_M_;

/* Forward declaration for local functions */
static void prova_gps_26_10_eml_find(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static boolean_T prova_gps_26_10_ifWhileCond(const boolean_T x[5]);
static void prova_gps_26_10_eml_find_k(const boolean_T x[80], int32_T i_data[],
  int32_T i_size[2]);
static void prova_gps_26_10_readNonFinite(const char_T s[2], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_gps_26_10_copydigits(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k, boolean_T allowpoint);
static boolean_T prova_gps_26_10_copyexponent(char_T s1[4], int32_T *idx, const
  char_T s[2], int32_T *k);
static void prova_gps_26_10_readfloat(char_T s1[4], int32_T *idx, const char_T
  s[2], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_gps_26_10_str2double(const char_T s[2]);
static boolean_T prova_gps_26_10_copydigits_i(char_T s1_data[], int32_T *idx,
  const char_T s_data[], int32_T *k, int32_T n, boolean_T allowpoint);
static void prova_gps_26_10_readfloat_j(char_T s1_data[], int32_T *idx, const
  char_T s_data[], int32_T *k, int32_T n, boolean_T allowimag, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_gps_26_10_str2double_g(const char_T s_data[], const int32_T
  s_size[2]);
static boolean_T prova_gps_26_10_isUnitImag(const char_T s[3], int32_T k);
static void prova_gps_26_10_readNonFinite_g(const char_T s[3], int32_T *k,
  boolean_T *b_finite, real_T *fv);
static boolean_T prova_gps_26_10_copydigits_iq(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowpoint);
static boolean_T prova_gps_26_10_copyexponent_m(char_T s1[5], int32_T *idx,
  const char_T s[3], int32_T *k);
static void prova_gps_26_10_readfloat_jq(char_T s1[5], int32_T *idx, const
  char_T s[3], int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T
  *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_gps_26_10_str2double_gh(const char_T s[3]);
static void prova_gps_26_1_readNonFinite_gx(char_T s, int32_T *k, boolean_T
  *b_finite, real_T *fv);
static boolean_T prova_gps_26_10_copydigits_iqy(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k, boolean_T allowpoint);
static boolean_T prova_gps_26_10_copyexponent_m0(char_T s1[3], int32_T *idx,
  char_T s, int32_T *k);
static void prova_gps_26_10_readfloat_jqn(char_T s1[3], int32_T *idx, char_T s,
  int32_T *k, boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
  real_T *nfv, boolean_T *foundsign, boolean_T *success);
static creal_T prova_gps_26_10_str2double_ghg(char_T s);
static real_T prova_gps_26_10_hex2dec(const char_T s[2]);
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
void prova_gps_26_10_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(prova_gps_26_10_M, 1));
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
  (prova_gps_26_10_M->Timing.TaskCounters.TID[1])++;
  if ((prova_gps_26_10_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.02s, 0.0s] */
    prova_gps_26_10_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_eml_find(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_ifWhileCond(const boolean_T x[5])
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_eml_find_k(const boolean_T x[80], int32_T i_data[],
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_readNonFinite(const char_T s[2], int32_T *k,
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copydigits(char_T s1[4], int32_T *idx, const
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copyexponent(char_T s1[4], int32_T *idx, const
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
      b_success = prova_gps_26_10_copydigits(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_readfloat(char_T s1[4], int32_T *idx, const char_T
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
            prova_gps_26_10_readfloat(s1, idx, s, k, false, &isneg, b_finite,
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
      prova_gps_26_10_readNonFinite(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_gps_26_10_copydigits(s1, idx, s, k, true);
        if (*success) {
          *success = prova_gps_26_10_copyexponent(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static creal_T prova_gps_26_10_str2double(const char_T s[2])
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
  prova_gps_26_10_B.scanned1_g = 0.0;
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
        prova_gps_26_10_readfloat(s1, &idx, s, &e_k, false, &isneg, &b_finite,
          &prova_gps_26_10_B.scanned1_g, &unusedU2, &success);
      } else {
        s1[idx - 1] = '1';
        idx++;
      }
    } else {
      e_k = k + 1;
      prova_gps_26_10_readNonFinite(s, &e_k, &b_finite,
        &prova_gps_26_10_B.scanned1_g);
      if (b_finite) {
        success = prova_gps_26_10_copydigits(s1, &idx, s, &e_k, true);
        if (success) {
          success = prova_gps_26_10_copyexponent(s1, &idx, s, &e_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          prova_gps_26_10_B.scanned1_g = -prova_gps_26_10_B.scanned1_g;
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
    prova_gps_26_10_readfloat(s1, &idx, s, &e_k, true, &success, &isneg,
      &prova_gps_26_10_B.scanned2_m, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (e_k > 2) && (isimag1 != success) && unusedU2);
  } else {
    prova_gps_26_10_B.scanned2_m = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &prova_gps_26_10_B.scanned1_g,
                       &prova_gps_26_10_B.scanned2_m);
      if (ntoread != 2) {
        prova_gps_26_10_B.scanned1_g = (rtNaN);
        prova_gps_26_10_B.scanned2_m = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &prova_gps_26_10_B.b_scanned1_n);
      if (b_finite) {
        if (ntoread == 1) {
          prova_gps_26_10_B.scanned1_g = prova_gps_26_10_B.b_scanned1_n;
        } else {
          prova_gps_26_10_B.scanned1_g = (rtNaN);
        }
      } else if (ntoread == 1) {
        prova_gps_26_10_B.scanned2_m = prova_gps_26_10_B.b_scanned1_n;
      } else {
        prova_gps_26_10_B.scanned2_m = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_gps_26_10_B.scanned2_m;
      x.im = prova_gps_26_10_B.scanned1_g;
    } else {
      x.re = prova_gps_26_10_B.scanned1_g;
      x.im = prova_gps_26_10_B.scanned2_m;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copydigits_i(char_T s1_data[], int32_T *idx,
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_readfloat_j(char_T s1_data[], int32_T *idx, const
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
          prova_gps_26_10_readfloat_j(s1_data, idx, s_data, k, n, false, &isneg,
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
        *success = prova_gps_26_10_copydigits_i(s1_data, &b_idx, s_data, &h_k, n,
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
              isneg = prova_gps_26_10_copydigits_i(s1_data, idx, s_data, &b_idx,
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static creal_T prova_gps_26_10_str2double_g(const char_T s_data[], const int32_T
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

    prova_gps_26_10_B.s1_size[0] = 1;
    prova_gps_26_10_B.s1_size[1] = (int8_T)(s_size[1] + 2);
    idx = (int8_T)(s_size[1] + 2) - 1;
    if (0 <= idx) {
      memset(&prova_gps_26_10_B.s1_data[0], 0, (idx + 1) * sizeof(char_T));
    }

    idx = 1;
    prova_gps_26_10_readfloat_j(prova_gps_26_10_B.s1_data, &idx, s_data, &k,
      s_size[1], true, &isimag1, &isfinite1, &prova_gps_26_10_B.scanned1,
      &unusedU0, &success);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success) {
      if (k <= s_size[1]) {
        prova_gps_26_10_B.s1_data[idx - 1] = ' ';
        idx++;
        prova_gps_26_10_readfloat_j(prova_gps_26_10_B.s1_data, &idx, s_data, &k,
          s_size[1], true, &unusedU0, &success, &prova_gps_26_10_B.scanned2,
          &foundsign, &c_success);
        if (success) {
          ntoread++;
        }

        success = (c_success && ((k > s_size[1]) && ((isimag1 != unusedU0) &&
          foundsign)));
      } else {
        prova_gps_26_10_B.scanned2 = 0.0;
      }
    } else {
      prova_gps_26_10_B.scanned2 = 0.0;
    }

    if (success) {
      prova_gps_26_10_B.s1_data[idx - 1] = '\x00';
      switch (ntoread) {
       case 2:
        ntoread = sscanf(&prova_gps_26_10_B.s1_data[0], "%lf %lf",
                         &prova_gps_26_10_B.scanned1,
                         &prova_gps_26_10_B.scanned2);
        if (ntoread != 2) {
          prova_gps_26_10_B.scanned1 = (rtNaN);
          prova_gps_26_10_B.scanned2 = (rtNaN);
        }
        break;

       case 1:
        ntoread = sscanf(&prova_gps_26_10_B.s1_data[0], "%lf",
                         &prova_gps_26_10_B.b_scanned1);
        if (isfinite1) {
          if (ntoread == 1) {
            prova_gps_26_10_B.scanned1 = prova_gps_26_10_B.b_scanned1;
          } else {
            prova_gps_26_10_B.scanned1 = (rtNaN);
          }
        } else if (ntoread == 1) {
          prova_gps_26_10_B.scanned2 = prova_gps_26_10_B.b_scanned1;
        } else {
          prova_gps_26_10_B.scanned2 = (rtNaN);
        }
        break;
      }

      if (isimag1) {
        x.re = prova_gps_26_10_B.scanned2;
        x.im = prova_gps_26_10_B.scanned1;
      } else {
        x.re = prova_gps_26_10_B.scanned1;
        x.im = prova_gps_26_10_B.scanned2;
      }
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_isUnitImag(const char_T s[3], int32_T k)
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_readNonFinite_g(const char_T s[3], int32_T *k,
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copydigits_iq(char_T s1[5], int32_T *idx, const
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copyexponent_m(char_T s1[5], int32_T *idx,
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
      b_success = prova_gps_26_10_copydigits_iq(s1, idx, s, &b_k, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_readfloat_jq(char_T s1[5], int32_T *idx, const
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
    if (prova_gps_26_10_isUnitImag(s, b_k)) {
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
          prova_gps_26_10_readfloat_jq(s1, idx, s, k, false, &isneg, b_finite,
            nfv, &unusedU2, success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      prova_gps_26_10_readNonFinite_g(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = prova_gps_26_10_copydigits_iq(s1, idx, s, k, true);
        if (*success) {
          *success = prova_gps_26_10_copyexponent_m(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static creal_T prova_gps_26_10_str2double_gh(const char_T s[3])
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
  prova_gps_26_10_B.scanned1_c = 0.0;
  idx = 1;
  for (b_k = 0; b_k < 5; b_k++) {
    prova_gps_26_10_B.s1[b_k] = '\x00';
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
    prova_gps_26_10_B.s1[0] = '-';
    idx = 2;
  }

  b_k = k - 1;
  if (success) {
    if (prova_gps_26_10_isUnitImag(s, k)) {
      isimag1 = true;
      b_k = k;
      while ((b_k + 1 <= 3) && (c[(uint8_T)s[b_k] & 127] || (s[b_k] == '\x00') ||
              (s[b_k] == ','))) {
        b_k++;
      }

      if ((b_k + 1 <= 3) && (s[b_k] == '*')) {
        k = b_k + 2;
        prova_gps_26_10_readfloat_jq(prova_gps_26_10_B.s1, &idx, s, &k, false,
          &isneg, &b_finite, &prova_gps_26_10_B.scanned1_c, &unusedU2, &success);
        b_k = k - 1;
      } else {
        prova_gps_26_10_B.s1[idx - 1] = '1';
        idx++;
      }
    } else {
      prova_gps_26_10_readNonFinite_g(s, &k, &b_finite,
        &prova_gps_26_10_B.scanned1_c);
      b_k = k - 1;
      if (b_finite) {
        success = prova_gps_26_10_copydigits_iq(prova_gps_26_10_B.s1, &idx, s,
          &k, true);
        b_k = k - 1;
        if (success) {
          success = prova_gps_26_10_copyexponent_m(prova_gps_26_10_B.s1, &idx, s,
            &k);
          b_k = k - 1;
        }
      } else {
        if ((idx >= 2) && (prova_gps_26_10_B.s1[0] == '-')) {
          idx = 1;
          prova_gps_26_10_B.s1[0] = ' ';
          prova_gps_26_10_B.scanned1_c = -prova_gps_26_10_B.scanned1_c;
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
    prova_gps_26_10_B.s1[idx - 1] = ' ';
    idx++;
    k = b_k + 1;
    prova_gps_26_10_readfloat_jq(prova_gps_26_10_B.s1, &idx, s, &k, true,
      &success, &isneg, &prova_gps_26_10_B.scanned2_f, &unusedU2, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (k > 3) && (isimag1 != success) && unusedU2);
  } else {
    prova_gps_26_10_B.scanned2_f = 0.0;
  }

  if (success) {
    prova_gps_26_10_B.s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&prova_gps_26_10_B.s1[0], "%lf %lf",
                       &prova_gps_26_10_B.scanned1_c,
                       &prova_gps_26_10_B.scanned2_f);
      if (ntoread != 2) {
        prova_gps_26_10_B.scanned1_c = (rtNaN);
        prova_gps_26_10_B.scanned2_f = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&prova_gps_26_10_B.s1[0], "%lf",
                       &prova_gps_26_10_B.b_scanned1_g);
      if (b_finite) {
        if (ntoread == 1) {
          prova_gps_26_10_B.scanned1_c = prova_gps_26_10_B.b_scanned1_g;
        } else {
          prova_gps_26_10_B.scanned1_c = (rtNaN);
        }
      } else if (ntoread == 1) {
        prova_gps_26_10_B.scanned2_f = prova_gps_26_10_B.b_scanned1_g;
      } else {
        prova_gps_26_10_B.scanned2_f = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_gps_26_10_B.scanned2_f;
      x.im = prova_gps_26_10_B.scanned1_c;
    } else {
      x.re = prova_gps_26_10_B.scanned1_c;
      x.im = prova_gps_26_10_B.scanned2_f;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_1_readNonFinite_gx(char_T s, int32_T *k, boolean_T
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copydigits_iqy(char_T s1[3], int32_T *idx,
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static boolean_T prova_gps_26_10_copyexponent_m0(char_T s1[3], int32_T *idx,
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
    b_success = prova_gps_26_10_copydigits_iqy(s1, idx, s, &b_k, false);
    *k = b_k;
    success = (b_success && (b_k > 2));
  }

  return success;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void prova_gps_26_10_readfloat_jqn(char_T s1[3], int32_T *idx, char_T s,
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
          prova_gps_26_10_readfloat_jqn(s1, idx, '\x2a', k, false, &isneg,
            b_finite, nfv, &unusedU2, success);
        } else {
          s1[b_idx] = '1';
          *idx = b_idx + 2;
        }
      } else {
        *success = false;
      }
    } else {
      prova_gps_26_1_readNonFinite_gx(s, &b_k, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *idx = b_idx + 1;
        *success = prova_gps_26_10_copydigits_iqy(s1, idx, s, k, true);
        if (*success) {
          *success = prova_gps_26_10_copyexponent_m0(s1, idx, s, k);
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

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static creal_T prova_gps_26_10_str2double_ghg(char_T s)
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
  prova_gps_26_10_B.scanned1_p = 0.0;
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
      prova_gps_26_1_readNonFinite_gx(s, &d_k, &b_finite,
        &prova_gps_26_10_B.scanned1_p);
      if (b_finite) {
        success = prova_gps_26_10_copydigits_iqy(s1, &idx, s, &d_k, true);
        if (success) {
          success = prova_gps_26_10_copyexponent_m0(s1, &idx, s, &d_k);
        }
      } else {
        if ((idx >= 2) && (s1[0] == '-')) {
          idx = 1;
          s1[0] = ' ';
          prova_gps_26_10_B.scanned1_p = -prova_gps_26_10_B.scanned1_p;
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
    prova_gps_26_10_readfloat_jqn(s1, &idx, s, &d_k, true, &success, &isneg,
      &prova_gps_26_10_B.scanned2_l, &foundsign, &c_success);
    if (isneg) {
      ntoread++;
    }

    success = (c_success && (d_k > 1) && (isimag1 != success) && foundsign);
  } else {
    prova_gps_26_10_B.scanned2_l = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    switch (ntoread) {
     case 2:
      ntoread = sscanf(&s1[0], "%lf %lf", &prova_gps_26_10_B.scanned1_p,
                       &prova_gps_26_10_B.scanned2_l);
      if (ntoread != 2) {
        prova_gps_26_10_B.scanned1_p = (rtNaN);
        prova_gps_26_10_B.scanned2_l = (rtNaN);
      }
      break;

     case 1:
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (b_finite) {
        if (ntoread == 1) {
          prova_gps_26_10_B.scanned1_p = b_scanned1;
        } else {
          prova_gps_26_10_B.scanned1_p = (rtNaN);
        }
      } else if (ntoread == 1) {
        prova_gps_26_10_B.scanned2_l = b_scanned1;
      } else {
        prova_gps_26_10_B.scanned2_l = (rtNaN);
      }
      break;
    }

    if (isimag1) {
      x.re = prova_gps_26_10_B.scanned2_l;
      x.im = prova_gps_26_10_B.scanned1_p;
    } else {
      x.re = prova_gps_26_10_B.scanned1_p;
      x.im = prova_gps_26_10_B.scanned2_l;
    }
  }

  return x;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static real_T prova_gps_26_10_hex2dec(const char_T s[2])
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

  prova_gps_26_10_B.a = tmp_1;
  prova_gps_26_10_B.p16 = tmp_2;
  for (idx = last - 1; idx + 1 >= first; idx--) {
    if ((s[idx] >= '0') && (s[idx] <= '9')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_3;
      MultiWordSub(&tmp.chunks[0U], &tmp_3.chunks[0U],
                   &prova_gps_26_10_B.sk.chunks[0U], 2);
    } else if ((s[idx] >= 'A') && (s[idx] <= 'F')) {
      uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
      tmp_0 = tmp_4;
      MultiWordSub(&tmp.chunks[0U], &tmp_4.chunks[0U],
                   &prova_gps_26_10_B.sk.chunks[0U], 2);
    } else if (s[idx] >= 'a') {
      if (s[idx] <= 'f') {
        uLong2MultiWord((uint8_T)s[idx], &tmp.chunks[0U], 2);
        tmp_0 = tmp_5;
        MultiWordSub(&tmp.chunks[0U], &tmp_5.chunks[0U],
                     &prova_gps_26_10_B.sk.chunks[0U], 2);
      } else {
        prova_gps_26_10_B.sk = tmp_1;
      }
    } else {
      prova_gps_26_10_B.sk = tmp_1;
    }

    uMultiWordMul(&prova_gps_26_10_B.sk.chunks[0U], 2,
                  &prova_gps_26_10_B.p16.chunks[0U], 2,
                  &prova_gps_26_10_B.r.chunks[0U], 4);
    uMultiWord2MultiWord(&prova_gps_26_10_B.r.chunks[0U], 4, &tmp.chunks[0U], 2);
    MultiWordAdd(&prova_gps_26_10_B.a.chunks[0U], &tmp.chunks[0U],
                 &tmp_0.chunks[0U], 2);
    prova_gps_26_10_B.a = tmp_0;
    uMultiWord2MultiWord(&prova_gps_26_10_B.p16.chunks[0U], 2,
                         &prova_gps_26_10_B.r2.chunks[0U], 3);
    uMultiWordShl(&prova_gps_26_10_B.r2.chunks[0U], 3, 4U,
                  &prova_gps_26_10_B.r1.chunks[0U], 3);
    uMultiWord2MultiWord(&prova_gps_26_10_B.r1.chunks[0U], 3,
                         &prova_gps_26_10_B.p16.chunks[0U], 2);
  }

  if (b_signed) {
    if (nbits == 64) {
      x = uMultiWord2Double(&prova_gps_26_10_B.a.chunks[0U], 2, 0);
    } else if (((last - first) + 1) << 2 == nbits) {
      if (s[first - 1] >= '8') {
        x = uMultiWord2Double(&prova_gps_26_10_B.a.chunks[0U], 2, 0) -
          uMultiWord2Double(&prova_gps_26_10_B.p16.chunks[0U], 2, 0);
      } else {
        x = uMultiWord2Double(&prova_gps_26_10_B.a.chunks[0U], 2, 0);
      }
    } else {
      x = uMultiWord2Double(&prova_gps_26_10_B.a.chunks[0U], 2, 0);
    }
  } else {
    x = uMultiWord2Double(&prova_gps_26_10_B.a.chunks[0U], 2, 0);
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

/* Model step function for TID0 */
void prova_gps_26_10_step0(void)       /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void prova_gps_26_10_step1(void)       /* Sample time: [0.02s, 0.0s] */
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

  /* MATLABSystem: '<S1>/Serial Receive1' */
  if (prova_gps_26_10_DW.obj_c.Protocol !=
      prova_gps_26_10_P.SerialReceive1_Protocol) {
    prova_gps_26_10_DW.obj_c.Protocol =
      prova_gps_26_10_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, prova_gps_26_10_DW.obj_c.DataSizeInBytes,
                 &prova_gps_26_10_B.b_dataOut[0], &status);

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem2' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (status > 0) {
    /* MATLAB Function: '<S3>/Create_message' */
    status = 0U;
    if (!prova_gps_26_10_DW.start_found) {
      i = 1;
      exitg1 = false;
      while ((!exitg1) && (i - 1 < 32)) {
        if (prova_gps_26_10_B.b_dataOut[(uint8_T)i - 1] == 36) {
          loop_ub = 32 - (uint8_T)i;
          for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i <= loop_ub;
               prova_gps_26_10_B.b_i++) {
            prova_gps_26_10_DW.message[prova_gps_26_10_B.b_i] =
              prova_gps_26_10_B.b_dataOut[((uint8_T)i + prova_gps_26_10_B.b_i) -
              1];
          }

          prova_gps_26_10_DW.counter = (uint8_T)(33 - (uint8_T)i);
          prova_gps_26_10_DW.start_found = true;
          exitg1 = true;
        } else {
          i++;
        }
      }
    } else {
      prova_gps_26_10_B.b_i = 1;
      exitg1 = false;
      while ((!exitg1) && (prova_gps_26_10_B.b_i - 1 < 32)) {
        if (prova_gps_26_10_B.b_dataOut[(uint8_T)prova_gps_26_10_B.b_i - 1] ==
            13) {
          prova_gps_26_10_DW.end_found = true;
          status = (uint8_T)prova_gps_26_10_B.b_i;
          exitg1 = true;
        } else {
          prova_gps_26_10_B.b_i++;
        }
      }

      if (prova_gps_26_10_DW.end_found) {
        if (1 > status) {
          loop_ub = -1;
        } else {
          loop_ub = status - 1;
        }

        for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i <= loop_ub;
             prova_gps_26_10_B.b_i++) {
          i = (int32_T)(((uint32_T)prova_gps_26_10_B.b_i +
                         prova_gps_26_10_DW.counter) + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          prova_gps_26_10_DW.message[i - 1] =
            prova_gps_26_10_B.b_dataOut[prova_gps_26_10_B.b_i];
        }

        memcpy(&prova_gps_26_10_B.messaggio_c[0], &prova_gps_26_10_DW.message[0],
               80U * sizeof(uint8_T));
        prova_gps_26_10_DW.end_found = false;
        prova_gps_26_10_DW.counter = (uint8_T)(32 - status);
        if (status == 32) {
          prova_gps_26_10_DW.start_found = false;
          memset(&prova_gps_26_10_DW.message[0], 0, 80U * sizeof(uint8_T));
        } else {
          prova_gps_26_10_DW.start_found = true;
          loop_ub = -status;
          for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i <= loop_ub + 31;
               prova_gps_26_10_B.b_i++) {
            prova_gps_26_10_DW.message[prova_gps_26_10_B.b_i] =
              prova_gps_26_10_B.b_dataOut[status + prova_gps_26_10_B.b_i];
          }

          prova_gps_26_10_B.b_i = status + 48;
          if (0 <= prova_gps_26_10_B.b_i - 1) {
            memset(&prova_gps_26_10_DW.message[-status + 32], 0,
                   ((prova_gps_26_10_B.b_i - status) + status) * sizeof(uint8_T));
          }
        }

        /* Outputs for Enabled SubSystem: '<S3>/Subsystem' incorporates:
         *  EnablePort: '<S5>/Enable'
         */
        /* MATLAB Function: '<S5>/MATLAB Function' */
        status = 0U;
        find_comma = 0U;
        for (i = 0; i < 80; i++) {
          messaggio = (int8_T)prova_gps_26_10_B.messaggio_c[i];
          if (messaggio == '$') {
            prova_gps_26_10_B.b_i = (int32_T)(status + 1U);
            if (status + 1U > 255U) {
              prova_gps_26_10_B.b_i = 255;
            }

            status = (uint8_T)prova_gps_26_10_B.b_i;
          }

          if (messaggio == ',') {
            prova_gps_26_10_B.b_i = (int32_T)(find_comma + 1U);
            if (find_comma + 1U > 255U) {
              prova_gps_26_10_B.b_i = 255;
            }

            find_comma = (uint8_T)prova_gps_26_10_B.b_i;
          }

          prova_gps_26_10_B.messaggio[i] = messaggio;
        }

        if ((status == 1) && ((find_comma == 12) || (find_comma == 14))) {
          for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
               prova_gps_26_10_B.b_i++) {
            prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
              (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == '$');
          }

          prova_gps_26_10_eml_find(prova_gps_26_10_B.messaggio_m,
            &prova_gps_26_10_B.eb_data, prova_gps_26_10_B.eb_size);
          loop_ub = prova_gps_26_10_B.eb_data;
          for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 5;
               prova_gps_26_10_B.b_i++) {
            messaggio = prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i +
              loop_ub];
            prova_gps_26_10_B.mess_type_j[prova_gps_26_10_B.b_i] = (messaggio ==
              bb[prova_gps_26_10_B.b_i]);
            prova_gps_26_10_B.mess_type[prova_gps_26_10_B.b_i] = messaggio;
          }

          if (prova_gps_26_10_ifWhileCond(prova_gps_26_10_B.mess_type_j)) {
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
                (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == ',');
            }

            prova_gps_26_10_eml_find_k(prova_gps_26_10_B.messaggio_m,
              prova_gps_26_10_B.comma_gga_data, prova_gps_26_10_B.eb_size);
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
                (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == '*');
            }

            prova_gps_26_10_eml_find_k(prova_gps_26_10_B.messaggio_m,
              prova_gps_26_10_B.star_data, prova_gps_26_10_B.star_size);
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
                (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == '$');
            }

            prova_gps_26_10_eml_find_k(prova_gps_26_10_B.messaggio_m,
              prova_gps_26_10_B.fb_data, prova_gps_26_10_B.star_size);
            prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double
              (&prova_gps_26_10_B.messaggio[prova_gps_26_10_B.comma_gga_data[2]]);
            if ((real_T)prova_gps_26_10_B.comma_gga_data[2] + 3.0 > (real_T)
                prova_gps_26_10_B.comma_gga_data[3] - 1.0) {
              i = 0;
              prova_gps_26_10_B.b_i = 0;
            } else {
              i = prova_gps_26_10_B.comma_gga_data[2] + 2;
              prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[3] - 1;
            }

            prova_gps_26_10_B.messaggio_size[0] = 1;
            loop_ub = prova_gps_26_10_B.b_i - i;
            prova_gps_26_10_B.messaggio_size[1] = loop_ub;
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
            }

            prova_gps_26_10_B.b_x = prova_gps_26_10_str2double_g
              (prova_gps_26_10_B.messaggio_data,
               prova_gps_26_10_B.messaggio_size);
            if (prova_gps_26_10_B.b_x.im == 0.0) {
              prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
            } else if (prova_gps_26_10_B.b_x.re == 0.0) {
              prova_gps_26_10_B.rtb_Long_re = 0.0;
            } else {
              prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
            }

            prova_gps_26_10_B.rtb_Lat_re = prova_gps_26_10_B.Lat_1.re +
              prova_gps_26_10_B.rtb_Long_re;
            loop_ub = prova_gps_26_10_B.eb_size[0] * prova_gps_26_10_B.eb_size[1]
              - 1;
            if (0 <= loop_ub) {
              memcpy(&prova_gps_26_10_B.tmp_data[0],
                     &prova_gps_26_10_B.comma_gga_data[0], (loop_ub + 1) *
                     sizeof(int32_T));
            }

            if (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.tmp_data[3]] ==
                'S') {
              prova_gps_26_10_B.rtb_Lat_re = -prova_gps_26_10_B.rtb_Lat_re;
            }

            prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_gh
              (&prova_gps_26_10_B.messaggio[prova_gps_26_10_B.comma_gga_data[4]]);
            if ((real_T)prova_gps_26_10_B.comma_gga_data[4] + 4.0 > (real_T)
                prova_gps_26_10_B.comma_gga_data[5] - 1.0) {
              i = 0;
              prova_gps_26_10_B.b_i = 0;
            } else {
              i = prova_gps_26_10_B.comma_gga_data[4] + 3;
              prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[5] - 1;
            }

            prova_gps_26_10_B.messaggio_size_k[0] = 1;
            loop_ub = prova_gps_26_10_B.b_i - i;
            prova_gps_26_10_B.messaggio_size_k[1] = loop_ub;
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
            }

            prova_gps_26_10_B.b_x = prova_gps_26_10_str2double_g
              (prova_gps_26_10_B.messaggio_data,
               prova_gps_26_10_B.messaggio_size_k);
            if (prova_gps_26_10_B.b_x.im == 0.0) {
              prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
            } else if (prova_gps_26_10_B.b_x.re == 0.0) {
              prova_gps_26_10_B.rtb_Long_re = 0.0;
            } else {
              prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
            }

            prova_gps_26_10_B.rtb_Long_re += prova_gps_26_10_B.Lat_1.re;
            if (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.tmp_data[5]] ==
                'W') {
              prova_gps_26_10_B.rtb_Long_re = -prova_gps_26_10_B.rtb_Long_re;
            }

            if ((real_T)prova_gps_26_10_B.comma_gga_data[6] + 1.0 > (real_T)
                prova_gps_26_10_B.comma_gga_data[7] - 1.0) {
              i = 0;
              prova_gps_26_10_B.b_i = 0;
            } else {
              i = prova_gps_26_10_B.comma_gga_data[6];
              prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[7] - 1;
            }

            prova_gps_26_10_B.messaggio_size_c[0] = 1;
            loop_ub = prova_gps_26_10_B.b_i - i;
            prova_gps_26_10_B.messaggio_size_c[1] = loop_ub;
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
            }

            prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_g
              (prova_gps_26_10_B.messaggio_data,
               prova_gps_26_10_B.messaggio_size_c);
            prova_gps_26_10_B.rtb_V_re = prova_gps_26_10_B.Lat_1.re;
            if ((real_T)prova_gps_26_10_B.comma_gga_data[7] + 1.0 > (real_T)
                prova_gps_26_10_B.comma_gga_data[8] - 1.0) {
              i = 0;
              prova_gps_26_10_B.b_i = 0;
            } else {
              i = prova_gps_26_10_B.comma_gga_data[7];
              prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[8] - 1;
            }

            prova_gps_26_10_B.messaggio_size_b[0] = 1;
            loop_ub = prova_gps_26_10_B.b_i - i;
            prova_gps_26_10_B.messaggio_size_b[1] = loop_ub;
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
            }

            prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_g
              (prova_gps_26_10_B.messaggio_data,
               prova_gps_26_10_B.messaggio_size_b);
            prova_gps_26_10_B.rtb_heading_re = prova_gps_26_10_B.Lat_1.re;
            if ((real_T)prova_gps_26_10_B.comma_gga_data[9] + 1.0 > (real_T)
                prova_gps_26_10_B.comma_gga_data[10] - 1.0) {
              i = 0;
              prova_gps_26_10_B.b_i = 0;
            } else {
              i = prova_gps_26_10_B.comma_gga_data[9];
              prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[10] - 1;
            }

            prova_gps_26_10_B.messaggio_size_p[0] = 1;
            loop_ub = prova_gps_26_10_B.b_i - i;
            prova_gps_26_10_B.messaggio_size_p[1] = loop_ub;
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
            }

            prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_g
              (prova_gps_26_10_B.messaggio_data,
               prova_gps_26_10_B.messaggio_size_p);
            prova_gps_26_10_B.rtb_Magnetic_declination_re =
              prova_gps_26_10_B.Lat_1.re;
            if (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.tmp_data[10]] ==
                'W') {
              prova_gps_26_10_B.rtb_Magnetic_declination_re =
                -prova_gps_26_10_B.Lat_1.re;
            }

            prova_gps_26_10_B.rtb_fix_mode_re =
              prova_gps_26_10_B.ComplextoRealImag[5];
            prova_gps_26_10_B.rtb_n_sat_re =
              prova_gps_26_10_B.ComplextoRealImag[6];
            prova_gps_26_10_B.rtb_h_mean_sea_re =
              prova_gps_26_10_B.ComplextoRealImag[7];
            prova_gps_26_10_B.rtb_h_WGS84_re =
              prova_gps_26_10_B.ComplextoRealImag[8];
            if ((real_T)prova_gps_26_10_B.star_data[0] + 1.0 < 256.0) {
              if ((real_T)prova_gps_26_10_B.star_data[0] + 1.0 >= 0.0) {
                status = (uint8_T)((real_T)prova_gps_26_10_B.star_data[0] + 1.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[0] = prova_gps_26_10_B.messaggio[status - 1];
            if ((real_T)prova_gps_26_10_B.star_data[0] + 2.0 < 256.0) {
              if ((real_T)prova_gps_26_10_B.star_data[0] + 2.0 >= 0.0) {
                status = (uint8_T)((real_T)prova_gps_26_10_B.star_data[0] + 2.0);
              } else {
                status = 0U;
              }
            } else {
              status = MAX_uint8_T;
            }

            ck_ric[1] = prova_gps_26_10_B.messaggio[status - 1];
            if ((real_T)prova_gps_26_10_B.fb_data[0] + 1.0 > (real_T)
                prova_gps_26_10_B.star_data[0] - 1.0) {
              i = 0;
              prova_gps_26_10_B.b_i = 0;
            } else {
              i = prova_gps_26_10_B.fb_data[0];
              prova_gps_26_10_B.b_i = prova_gps_26_10_B.star_data[0] - 1;
            }

            loop_ub = prova_gps_26_10_B.b_i - i;
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.NMEA_gga_string_data[prova_gps_26_10_B.b_i] =
                (uint8_T)prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
            }

            status = 0U;
            prova_gps_26_10_B.b_i = 0;
            while (prova_gps_26_10_B.b_i <= loop_ub - 1) {
              status ^=
                prova_gps_26_10_B.NMEA_gga_string_data[prova_gps_26_10_B.b_i];
              prova_gps_26_10_B.b_i++;
            }

            if (status != prova_gps_26_10_hex2dec(ck_ric)) {
              prova_gps_26_10_B.rtb_Lat_re =
                prova_gps_26_10_B.ComplextoRealImag[0];
              prova_gps_26_10_B.rtb_Long_re =
                prova_gps_26_10_B.ComplextoRealImag[1];
              prova_gps_26_10_B.rtb_V_re = prova_gps_26_10_B.ComplextoRealImag[2];
              prova_gps_26_10_B.rtb_Magnetic_declination_re =
                prova_gps_26_10_B.ComplextoRealImag[3];
              prova_gps_26_10_B.rtb_heading_re =
                prova_gps_26_10_B.ComplextoRealImag[4];
            }
          } else {
            for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 5;
                 prova_gps_26_10_B.b_i++) {
              prova_gps_26_10_B.mess_type_j[prova_gps_26_10_B.b_i] =
                (prova_gps_26_10_B.mess_type[prova_gps_26_10_B.b_i] ==
                 cb[prova_gps_26_10_B.b_i]);
            }

            if (prova_gps_26_10_ifWhileCond(prova_gps_26_10_B.mess_type_j)) {
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
                  (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == ',');
              }

              prova_gps_26_10_eml_find_k(prova_gps_26_10_B.messaggio_m,
                prova_gps_26_10_B.comma_gga_data, prova_gps_26_10_B.eb_size);
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
                  (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == '*');
              }

              prova_gps_26_10_eml_find_k(prova_gps_26_10_B.messaggio_m,
                prova_gps_26_10_B.star_data, prova_gps_26_10_B.star_size);
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < 80;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_m[prova_gps_26_10_B.b_i] =
                  (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.b_i] == '$');
              }

              prova_gps_26_10_eml_find_k(prova_gps_26_10_B.messaggio_m,
                prova_gps_26_10_B.fb_data, prova_gps_26_10_B.star_size);
              prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double
                (&prova_gps_26_10_B.messaggio[prova_gps_26_10_B.comma_gga_data[1]]);
              if ((real_T)prova_gps_26_10_B.comma_gga_data[1] + 3.0 > (real_T)
                  prova_gps_26_10_B.comma_gga_data[2] - 1.0) {
                i = 0;
                prova_gps_26_10_B.b_i = 0;
              } else {
                i = prova_gps_26_10_B.comma_gga_data[1] + 2;
                prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[2] - 1;
              }

              prova_gps_26_10_B.messaggio_size[0] = 1;
              loop_ub = prova_gps_26_10_B.b_i - i;
              prova_gps_26_10_B.messaggio_size[1] = loop_ub;
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                  prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
              }

              prova_gps_26_10_B.b_x = prova_gps_26_10_str2double_g
                (prova_gps_26_10_B.messaggio_data,
                 prova_gps_26_10_B.messaggio_size);
              if (prova_gps_26_10_B.b_x.im == 0.0) {
                prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
              } else if (prova_gps_26_10_B.b_x.re == 0.0) {
                prova_gps_26_10_B.rtb_Long_re = 0.0;
              } else {
                prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
              }

              prova_gps_26_10_B.rtb_Lat_re = prova_gps_26_10_B.Lat_1.re +
                prova_gps_26_10_B.rtb_Long_re;
              loop_ub = prova_gps_26_10_B.eb_size[0] *
                prova_gps_26_10_B.eb_size[1] - 1;
              if (0 <= loop_ub) {
                memcpy(&prova_gps_26_10_B.tmp_data[0],
                       &prova_gps_26_10_B.comma_gga_data[0], (loop_ub + 1) *
                       sizeof(int32_T));
              }

              if (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.tmp_data[2]] ==
                  'S') {
                prova_gps_26_10_B.rtb_Lat_re = -prova_gps_26_10_B.rtb_Lat_re;
              }

              prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_gh
                (&prova_gps_26_10_B.messaggio[prova_gps_26_10_B.comma_gga_data[3]]);
              if ((real_T)prova_gps_26_10_B.comma_gga_data[3] + 4.0 > (real_T)
                  prova_gps_26_10_B.comma_gga_data[4] - 1.0) {
                i = 0;
                prova_gps_26_10_B.b_i = 0;
              } else {
                i = prova_gps_26_10_B.comma_gga_data[3] + 3;
                prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[4] - 1;
              }

              prova_gps_26_10_B.messaggio_size_k[0] = 1;
              loop_ub = prova_gps_26_10_B.b_i - i;
              prova_gps_26_10_B.messaggio_size_k[1] = loop_ub;
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                  prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
              }

              prova_gps_26_10_B.b_x = prova_gps_26_10_str2double_g
                (prova_gps_26_10_B.messaggio_data,
                 prova_gps_26_10_B.messaggio_size_k);
              if (prova_gps_26_10_B.b_x.im == 0.0) {
                prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
              } else if (prova_gps_26_10_B.b_x.re == 0.0) {
                prova_gps_26_10_B.rtb_Long_re = 0.0;
              } else {
                prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.b_x.re / 60.0;
              }

              prova_gps_26_10_B.rtb_Long_re += prova_gps_26_10_B.Lat_1.re;
              if (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.tmp_data[4]] ==
                  'W') {
                prova_gps_26_10_B.rtb_Long_re = -prova_gps_26_10_B.rtb_Long_re;
              }

              prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_ghg
                (prova_gps_26_10_B.messaggio[prova_gps_26_10_B.comma_gga_data[5]]);
              prova_gps_26_10_B.rtb_fix_mode_re = prova_gps_26_10_B.Lat_1.re;
              if ((real_T)prova_gps_26_10_B.comma_gga_data[6] + 1.0 > (real_T)
                  prova_gps_26_10_B.comma_gga_data[7] - 1.0) {
                i = 0;
                prova_gps_26_10_B.b_i = 0;
              } else {
                i = prova_gps_26_10_B.comma_gga_data[6];
                prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[7] - 1;
              }

              prova_gps_26_10_B.messaggio_size_c[0] = 1;
              loop_ub = prova_gps_26_10_B.b_i - i;
              prova_gps_26_10_B.messaggio_size_c[1] = loop_ub;
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                  prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
              }

              prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_g
                (prova_gps_26_10_B.messaggio_data,
                 prova_gps_26_10_B.messaggio_size_c);
              prova_gps_26_10_B.rtb_n_sat_re = prova_gps_26_10_B.Lat_1.re;
              if ((real_T)prova_gps_26_10_B.comma_gga_data[8] + 1.0 > (real_T)
                  prova_gps_26_10_B.comma_gga_data[9] - 1.0) {
                i = 0;
                prova_gps_26_10_B.b_i = 0;
              } else {
                i = prova_gps_26_10_B.comma_gga_data[8];
                prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[9] - 1;
              }

              prova_gps_26_10_B.messaggio_size_b[0] = 1;
              loop_ub = prova_gps_26_10_B.b_i - i;
              prova_gps_26_10_B.messaggio_size_b[1] = loop_ub;
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                  prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
              }

              prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_g
                (prova_gps_26_10_B.messaggio_data,
                 prova_gps_26_10_B.messaggio_size_b);
              prova_gps_26_10_B.rtb_h_mean_sea_re = prova_gps_26_10_B.Lat_1.re;
              if ((real_T)prova_gps_26_10_B.comma_gga_data[10] + 1.0 > (real_T)
                  prova_gps_26_10_B.comma_gga_data[11] - 1.0) {
                i = 0;
                prova_gps_26_10_B.b_i = 0;
              } else {
                i = prova_gps_26_10_B.comma_gga_data[10];
                prova_gps_26_10_B.b_i = prova_gps_26_10_B.comma_gga_data[11] - 1;
              }

              prova_gps_26_10_B.messaggio_size_p[0] = 1;
              loop_ub = prova_gps_26_10_B.b_i - i;
              prova_gps_26_10_B.messaggio_size_p[1] = loop_ub;
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.messaggio_data[prova_gps_26_10_B.b_i] =
                  prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
              }

              prova_gps_26_10_B.Lat_1 = prova_gps_26_10_str2double_g
                (prova_gps_26_10_B.messaggio_data,
                 prova_gps_26_10_B.messaggio_size_p);
              prova_gps_26_10_B.rtb_h_WGS84_re = prova_gps_26_10_B.Lat_1.re;
              prova_gps_26_10_B.rtb_V_re = prova_gps_26_10_B.ComplextoRealImag[2];
              prova_gps_26_10_B.rtb_Magnetic_declination_re =
                prova_gps_26_10_B.ComplextoRealImag[3];
              prova_gps_26_10_B.rtb_heading_re =
                prova_gps_26_10_B.ComplextoRealImag[4];
              if ((real_T)prova_gps_26_10_B.star_data[0] + 1.0 < 256.0) {
                if ((real_T)prova_gps_26_10_B.star_data[0] + 1.0 >= 0.0) {
                  status = (uint8_T)((real_T)prova_gps_26_10_B.star_data[0] +
                                     1.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[0] = prova_gps_26_10_B.messaggio[status - 1];
              if ((real_T)prova_gps_26_10_B.star_data[0] + 2.0 < 256.0) {
                if ((real_T)prova_gps_26_10_B.star_data[0] + 2.0 >= 0.0) {
                  status = (uint8_T)((real_T)prova_gps_26_10_B.star_data[0] +
                                     2.0);
                } else {
                  status = 0U;
                }
              } else {
                status = MAX_uint8_T;
              }

              ck_ric[1] = prova_gps_26_10_B.messaggio[status - 1];
              if ((real_T)prova_gps_26_10_B.fb_data[0] + 1.0 > (real_T)
                  prova_gps_26_10_B.star_data[0] - 1.0) {
                i = 0;
                prova_gps_26_10_B.b_i = 0;
              } else {
                i = prova_gps_26_10_B.fb_data[0];
                prova_gps_26_10_B.b_i = prova_gps_26_10_B.star_data[0] - 1;
              }

              loop_ub = prova_gps_26_10_B.b_i - i;
              for (prova_gps_26_10_B.b_i = 0; prova_gps_26_10_B.b_i < loop_ub;
                   prova_gps_26_10_B.b_i++) {
                prova_gps_26_10_B.NMEA_gga_string_data[prova_gps_26_10_B.b_i] =
                  (uint8_T)prova_gps_26_10_B.messaggio[i + prova_gps_26_10_B.b_i];
              }

              status = 0U;
              prova_gps_26_10_B.b_i = 0;
              while (prova_gps_26_10_B.b_i <= loop_ub - 1) {
                status ^=
                  prova_gps_26_10_B.NMEA_gga_string_data[prova_gps_26_10_B.b_i];
                prova_gps_26_10_B.b_i++;
              }

              if (status != prova_gps_26_10_hex2dec(ck_ric)) {
                prova_gps_26_10_B.rtb_Lat_re =
                  prova_gps_26_10_B.ComplextoRealImag[0];
                prova_gps_26_10_B.rtb_Long_re =
                  prova_gps_26_10_B.ComplextoRealImag[1];
                prova_gps_26_10_B.rtb_fix_mode_re =
                  prova_gps_26_10_B.ComplextoRealImag[5];
                prova_gps_26_10_B.rtb_n_sat_re =
                  prova_gps_26_10_B.ComplextoRealImag[6];
                prova_gps_26_10_B.rtb_h_mean_sea_re =
                  prova_gps_26_10_B.ComplextoRealImag[7];
                prova_gps_26_10_B.rtb_h_WGS84_re =
                  prova_gps_26_10_B.ComplextoRealImag[8];
              }
            } else {
              prova_gps_26_10_B.rtb_Lat_re =
                prova_gps_26_10_B.ComplextoRealImag[0];
              prova_gps_26_10_B.rtb_Long_re =
                prova_gps_26_10_B.ComplextoRealImag[1];
              prova_gps_26_10_B.rtb_V_re = prova_gps_26_10_B.ComplextoRealImag[2];
              prova_gps_26_10_B.rtb_Magnetic_declination_re =
                prova_gps_26_10_B.ComplextoRealImag[3];
              prova_gps_26_10_B.rtb_heading_re =
                prova_gps_26_10_B.ComplextoRealImag[4];
              prova_gps_26_10_B.rtb_fix_mode_re =
                prova_gps_26_10_B.ComplextoRealImag[5];
              prova_gps_26_10_B.rtb_n_sat_re =
                prova_gps_26_10_B.ComplextoRealImag[6];
              prova_gps_26_10_B.rtb_h_mean_sea_re =
                prova_gps_26_10_B.ComplextoRealImag[7];
              prova_gps_26_10_B.rtb_h_WGS84_re =
                prova_gps_26_10_B.ComplextoRealImag[8];
            }
          }
        } else {
          prova_gps_26_10_B.rtb_Lat_re = prova_gps_26_10_B.ComplextoRealImag[0];
          prova_gps_26_10_B.rtb_Long_re = prova_gps_26_10_B.ComplextoRealImag[1];
          prova_gps_26_10_B.rtb_V_re = prova_gps_26_10_B.ComplextoRealImag[2];
          prova_gps_26_10_B.rtb_Magnetic_declination_re =
            prova_gps_26_10_B.ComplextoRealImag[3];
          prova_gps_26_10_B.rtb_heading_re =
            prova_gps_26_10_B.ComplextoRealImag[4];
          prova_gps_26_10_B.rtb_fix_mode_re =
            prova_gps_26_10_B.ComplextoRealImag[5];
          prova_gps_26_10_B.rtb_n_sat_re = prova_gps_26_10_B.ComplextoRealImag[6];
          prova_gps_26_10_B.rtb_h_mean_sea_re =
            prova_gps_26_10_B.ComplextoRealImag[7];
          prova_gps_26_10_B.rtb_h_WGS84_re =
            prova_gps_26_10_B.ComplextoRealImag[8];
        }

        /* End of MATLAB Function: '<S5>/MATLAB Function' */

        /* ComplexToRealImag: '<S5>/Complex to Real-Imag' */
        prova_gps_26_10_B.ComplextoRealImag[0] = prova_gps_26_10_B.rtb_Lat_re;
        prova_gps_26_10_B.ComplextoRealImag[1] = prova_gps_26_10_B.rtb_Long_re;
        prova_gps_26_10_B.ComplextoRealImag[2] = prova_gps_26_10_B.rtb_V_re;
        prova_gps_26_10_B.ComplextoRealImag[3] =
          prova_gps_26_10_B.rtb_Magnetic_declination_re;
        prova_gps_26_10_B.ComplextoRealImag[4] =
          prova_gps_26_10_B.rtb_heading_re;
        prova_gps_26_10_B.ComplextoRealImag[5] =
          prova_gps_26_10_B.rtb_fix_mode_re;
        prova_gps_26_10_B.ComplextoRealImag[6] = prova_gps_26_10_B.rtb_n_sat_re;
        prova_gps_26_10_B.ComplextoRealImag[7] =
          prova_gps_26_10_B.rtb_h_mean_sea_re;
        prova_gps_26_10_B.ComplextoRealImag[8] =
          prova_gps_26_10_B.rtb_h_WGS84_re;

        /* End of Outputs for SubSystem: '<S3>/Subsystem' */
      } else {
        for (i = 0; i < 32; i++) {
          prova_gps_26_10_B.b_i = (int32_T)(((uint32_T)
            prova_gps_26_10_DW.counter + i) + 1U);
          if ((uint32_T)prova_gps_26_10_B.b_i > 255U) {
            prova_gps_26_10_B.b_i = 255;
          }

          prova_gps_26_10_DW.message[prova_gps_26_10_B.b_i - 1] =
            prova_gps_26_10_B.b_dataOut[i];
        }

        prova_gps_26_10_B.b_i = (int32_T)(prova_gps_26_10_DW.counter + 32U);
        if (prova_gps_26_10_DW.counter + 32U > 255U) {
          prova_gps_26_10_B.b_i = 255;
        }

        prova_gps_26_10_DW.counter = (uint8_T)prova_gps_26_10_B.b_i;
      }
    }

    /* End of MATLAB Function: '<S3>/Create_message' */
  }

  /* End of MATLABSystem: '<S1>/Serial Receive1' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem2' */

  /* MATLABSystem: '<Root>/Serial Transmit2' */
  if (prova_gps_26_10_DW.obj.Protocol !=
      prova_gps_26_10_P.SerialTransmit2_Protocol) {
    prova_gps_26_10_DW.obj.Protocol = prova_gps_26_10_P.SerialTransmit2_Protocol;
  }

  prova_gps_26_10_B.rtb_Lat_re = prova_gps_26_10_B.ComplextoRealImag[0];
  MW_Serial_write(prova_gps_26_10_DW.obj.port, &prova_gps_26_10_B.rtb_Lat_re,
                  1.0, prova_gps_26_10_DW.obj.dataSizeInBytes,
                  prova_gps_26_10_DW.obj.sendModeEnum,
                  prova_gps_26_10_DW.obj.dataType,
                  prova_gps_26_10_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit2' */

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem1' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Constant: '<S1>/Constant' */
  if (prova_gps_26_10_P.Constant_Value_e > 0.0) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant3'
     *  Logic: '<S2>/OR'
     *  RelationalOperator: '<S2>/Equal'
     *  RelationalOperator: '<S2>/Equal1'
     *  RelationalOperator: '<S2>/Equal2'
     */
    if ((prova_gps_26_10_B.ComplextoRealImag[5] ==
         prova_gps_26_10_P.Constant_Value) ||
        (prova_gps_26_10_B.ComplextoRealImag[5] ==
         prova_gps_26_10_P.Constant1_Value) ||
        (prova_gps_26_10_B.ComplextoRealImag[5] ==
         prova_gps_26_10_P.Constant3_Value)) {
      /* Switch: '<S2>/Switch' */
      prova_gps_26_10_B.Switch = prova_gps_26_10_B.ComplextoRealImag[7];
    } else {
      /* Switch: '<S2>/Switch' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      prova_gps_26_10_B.Switch = prova_gps_26_10_P.Constant2_Value;
    }

    /* End of Switch: '<S2>/Switch' */
  }

  /* End of Constant: '<S1>/Constant' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */
}

/* Model initialize function */
void prova_gps_26_10_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T tmp;
    int32_T i;
    uint8_T tmp_0;

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem1' */
    /* SystemInitialize for Switch: '<S2>/Switch' incorporates:
     *  Outport: '<S2>/h_to_subtract'
     */
    prova_gps_26_10_B.Switch = prova_gps_26_10_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S3>/Subsystem' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Memory: '<S5>/Memory' */
      prova_gps_26_10_B.ComplextoRealImag[i] =
        prova_gps_26_10_P.Memory_InitialCondition;

      /* SystemInitialize for ComplexToRealImag: '<S5>/Complex to Real-Imag' incorporates:
       *  Outport: '<S5>/Outport'
       */
      prova_gps_26_10_B.ComplextoRealImag[i] = prova_gps_26_10_P.Outport_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S3>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem2' */

    /* Start for MATLABSystem: '<S1>/Serial Receive1' */
    prova_gps_26_10_DW.obj_c.matlabCodegenIsDeleted = false;
    prova_gps_26_10_DW.obj_c.Protocol =
      prova_gps_26_10_P.SerialReceive1_Protocol;
    prova_gps_26_10_DW.obj_c.isInitialized = 1;
    prova_gps_26_10_DW.obj_c.DataTypeWidth = 1U;
    if (prova_gps_26_10_DW.obj_c.DataTypeWidth > 2047) {
      prova_gps_26_10_DW.obj_c.DataSizeInBytes = MAX_uint16_T;
    } else {
      prova_gps_26_10_DW.obj_c.DataSizeInBytes = (uint16_T)
        (prova_gps_26_10_DW.obj_c.DataTypeWidth << 5);
    }

    MW_SCI_Open(1);
    prova_gps_26_10_DW.obj_c.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/Serial Receive1' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit2' */
    prova_gps_26_10_DW.obj.matlabCodegenIsDeleted = false;
    prova_gps_26_10_DW.obj.Protocol = prova_gps_26_10_P.SerialTransmit2_Protocol;
    prova_gps_26_10_DW.obj.isInitialized = 1;
    prova_gps_26_10_DW.obj.port = 0.0;
    prova_gps_26_10_DW.obj.dataSizeInBytes = 8.0;
    prova_gps_26_10_DW.obj.dataType = 6.0;
    prova_gps_26_10_DW.obj.sendModeEnum = 2.0;
    prova_gps_26_10_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(prova_gps_26_10_DW.obj.port);
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
    prova_gps_26_10_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit2' */
  }
}

/* Model terminate function */
void prova_gps_26_10_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Serial Receive1' */
  if (!prova_gps_26_10_DW.obj_c.matlabCodegenIsDeleted) {
    prova_gps_26_10_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Receive1' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit2' */
  if (!prova_gps_26_10_DW.obj.matlabCodegenIsDeleted) {
    prova_gps_26_10_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
