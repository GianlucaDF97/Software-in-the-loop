//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.cpp
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.49
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Tue Dec 20 09:36:06 2022
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Aenea_model.h"
#include "Aenea_model_private.h"

// Named constants for Chart: '<S35>/SELEZIONE MODALITA\'  HOLD//SELECT'
const uint8_T Aenea_model_IN_Hold = 1U;
const uint8_T Aenea_model_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T Aenea_model_IN_Select = 2U;

// Named constants for Chart: '<S33>/ STATI'
const uint8_T Aenea_IN_ATTERRAGGIO_AUTOMATICO = 1U;
const uint8_T Aenea_mod_IN_DECOLLO_AUTOMATICO = 2U;
const uint8_T Aenea_mode_IN_Intervento_Pilota = 3U;
const uint8_T Aenea_model_IN_AUTOMATICA = 1U;
const uint8_T Aenea_model_IN_Go_Home = 2U;
const uint8_T Aenea_model_IN_MANUALE = 4U;
const uint8_T Aenea_model_IN_Safe = 5U;
const uint8_T Aenea_model_IN_Stand_By = 6U;
const uint8_T Aenea_model_IN_TEST = 3U;
const uint8_T Aenea_model_IN_VETTORIALE = 4U;
const uint8_T Aenea_model_IN_WAYPOINT = 5U;

// Named constants for Chart: '<S34>/Chart'
const uint8_T Aenea_model_IN_AutoLanding = 1U;
const uint8_T Aenea_model_IN_AutoTakeoff = 2U;
const uint8_T Aenea_model_IN_GoHome = 3U;
const uint8_T Aenea_model_IN_In = 4U;
const uint8_T Aenea_model_IN_Vettoriale = 5U;
const uint8_T Aenea_model_IN_Waypoint = 6U;

// Named constants for Chart: '<S435>/Chart1'
const uint8_T Aenea_model_IN_Fase_0_ATO = 1U;
const uint8_T Aenea_model_IN_Fase_1_ATO = 2U;
const uint8_T Aenea_model_IN_Fase_2_ATO = 3U;
const uint8_T Aenea_model_IN_Fase_3_ATO = 4U;
const uint8_T Aenea_model_IN_Fase_4_ATO = 5U;

// Named constants for Chart: '<S437>/Chart1'
const uint8_T Aenea_model_IN_Abort = 1U;
const uint8_T Aenea_model_IN_Allignment = 2U;
const uint8_T Aenea_model_IN_Allignment1 = 3U;
const uint8_T Aenea_model_IN_Approach = 4U;
const uint8_T Aenea_model_IN_Flare = 5U;

// Block signals (default storage)
B_Aenea_model_T Aenea_model_B;

// Block states (default storage)
DW_Aenea_model_T Aenea_model_DW;

// Previous zero-crossings (trigger) states
PrevZCX_Aenea_model_T Aenea_model_PrevZCX;

// Real-time model
RT_MODEL_Aenea_model_T Aenea_model_M_ = RT_MODEL_Aenea_model_T();
RT_MODEL_Aenea_model_T *const Aenea_model_M = &Aenea_model_M_;

// Forward declaration for local functions
static void Aenea_model_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter);
static boolean_T Aenea_model_ifWhileCond(const boolean_T x[100]);
static void Aenea_model_xgetrf(real_T A[121], int32_T ipiv[11], int32_T *info);
static int32_T Aenea_model_xgetrfs(real_T A[121], real_T B[198]);
static void Aenea_model_mldivide(const real_T A[121], const real_T B[198],
  real_T Y[198]);
static void Aenea_model_measure_F1B(const real_T stato[18], const real_T EULERO
  [3], real_T rx, real_T ry, real_T rz, real_T g, real_T Y[11]);
static void Aenea_model_f_pred_F1B(const real_T prediction[18], real_T a, real_T
  dt, real_T f[18]);
static void Aenea_model_Waypoint(const boolean_T *Ap_sel, real_T *Wp_selector,
  real_T *Vec_selector, real_T *Ato_selector, real_T *Al_selector, real_T
  *Go_home_selector);
static void Aenea_model_In(const boolean_T *Ap_sel, real_T *Wp_selector, real_T *
  Vec_selector, real_T *Ato_selector, real_T *Al_selector, real_T
  *Go_home_selector);
static void rate_scheduler(void);

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Aenea_model_M->Timing.TaskCounters.TID[1])++;
  if ((Aenea_model_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.1s, 0.0s] 
    Aenea_model_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for enable system:
//    '<S405>/Enabled Subsystem'
//    '<S406>/Enabled Subsystem'
//
void Aenea_model_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0)
{
  // Outputs for Enabled SubSystem: '<S405>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S414>/Enable'

  if (rtu_Enable > 0) {
    // Switch: '<S414>/Switch'
    *rty_u0 = !(rtu_Time > 2.0);
  }

  // End of Outputs for SubSystem: '<S405>/Enabled Subsystem'
}

//
// System reset for atomic system:
//    '<S405>/Resettable Subsystem'
//    '<S406>/Resettable Subsystem'
//
void Aenea_ResettableSubsystem_Reset(DW_ResettableSubsystem_Aenea__T *localDW)
{
  // InitializeConditions for Memory: '<S416>/Memory'
  localDW->Memory_PreviousInput = 0.0;
}

//
// Output and update for atomic system:
//    '<S405>/Resettable Subsystem'
//    '<S406>/Resettable Subsystem'
//
void Aenea_model_ResettableSubsystem(uint8_T rtu_Reset, real_T *rty_Time,
  DW_ResettableSubsystem_Aenea__T *localDW, ZCE_ResettableSubsystem_Aenea_T
  *localZCE)
{
  // Outputs for Resettable SubSystem: '<S405>/Resettable Subsystem' incorporates:
  //   ResetPort: '<S415>/Reset'

  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_k != POS_ZCSIG))
  {
    Aenea_ResettableSubsystem_Reset(localDW);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_k = (rtu_Reset > 0);

  // Sum: '<S416>/Sum' incorporates:
  //   Constant: '<S416>/Constant4'
  //   Memory: '<S416>/Memory'

  *rty_Time = localDW->Memory_PreviousInput + 0.02;

  // Update for Memory: '<S416>/Memory'
  localDW->Memory_PreviousInput = *rty_Time;

  // End of Outputs for SubSystem: '<S405>/Resettable Subsystem'
}

// Function for MATLAB Function: '<S1>/MATLAB Function4'
static void Aenea_model_find_254(const uint8_T pack[100], real_T position[3],
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
      position[static_cast<int32_T>(*counter) - 1] = static_cast<real_T>(i) +
        1.0;
    }
  }

  if (*counter > 1.0) {
    i = static_cast<int32_T>(position[0]);
    tmp = static_cast<int32_T>(pack[i] + 8U);
    if (static_cast<uint32_T>(tmp) > 255U) {
      tmp = 255;
    }

    i += tmp;
    if (i < 256) {
      tmp_0 = static_cast<uint8_T>(i);
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
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S1>/MATLAB Function4'
static boolean_T Aenea_model_ifWhileCond(const boolean_T x[100])
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

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (std::abs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = std::floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = std::ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S552>/DEFINITIVA'
static void Aenea_model_xgetrf(real_T A[121], int32_T ipiv[11], int32_T *info)
{
  int32_T c;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int32_T jA;
  for (j = 0; j < 11; j++) {
    ipiv[j] = j + 1;
  }

  *info = 0;
  for (j = 0; j < 10; j++) {
    c = j * 12;
    jA = 0;
    ix = c;
    Aenea_model_B.smax_b = std::abs(A[c]);
    for (iy = 2; iy <= 11 - j; iy++) {
      ix++;
      Aenea_model_B.y_p = std::abs(A[ix]);
      if (Aenea_model_B.y_p > Aenea_model_B.smax_b) {
        jA = iy - 1;
        Aenea_model_B.smax_b = Aenea_model_B.y_p;
      }
    }

    if (A[c + jA] != 0.0) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = iy + 1;
        ix = j;
        for (jA = 0; jA < 11; jA++) {
          Aenea_model_B.smax_b = A[ix];
          A[ix] = A[iy];
          A[iy] = Aenea_model_B.smax_b;
          ix += 11;
          iy += 11;
        }
      }

      jA = (c - j) + 11;
      for (ix = c + 1; ix < jA; ix++) {
        A[ix] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    jA = c;
    ix = c + 11;
    for (iy = 0; iy <= 9 - j; iy++) {
      if (A[ix] != 0.0) {
        Aenea_model_B.smax_b = -A[ix];
        c_ix = c + 1;
        d = (jA - j) + 22;
        for (ijA = jA + 12; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * Aenea_model_B.smax_b;
          c_ix++;
        }
      }

      ix += 11;
      jA += 11;
    }
  }

  if ((*info == 0) && (!(A[120] != 0.0))) {
    *info = 11;
  }
}

// Function for MATLAB Function: '<S552>/DEFINITIVA'
static int32_T Aenea_model_xgetrfs(real_T A[121], real_T B[198])
{
  int32_T b_i;
  int32_T info;
  int32_T ipiv;
  int32_T j;
  int32_T jBcol;
  int32_T kAcol;
  int32_T tmp;
  Aenea_model_xgetrf(A, Aenea_model_B.ipiv, &info);
  for (Aenea_model_B.i_p = 0; Aenea_model_B.i_p < 10; Aenea_model_B.i_p++) {
    ipiv = Aenea_model_B.ipiv[Aenea_model_B.i_p];
    if (Aenea_model_B.i_p + 1 != ipiv) {
      for (j = 0; j < 18; j++) {
        jBcol = 11 * j + Aenea_model_B.i_p;
        Aenea_model_B.temp = B[jBcol];
        tmp = (ipiv + 11 * j) - 1;
        B[jBcol] = B[tmp];
        B[tmp] = Aenea_model_B.temp;
      }
    }
  }

  for (j = 0; j < 18; j++) {
    jBcol = 11 * j;
    for (ipiv = 0; ipiv < 11; ipiv++) {
      kAcol = 11 * ipiv;
      tmp = ipiv + jBcol;
      if (B[tmp] != 0.0) {
        for (b_i = ipiv + 2; b_i < 12; b_i++) {
          Aenea_model_B.i_p = (b_i + jBcol) - 1;
          B[Aenea_model_B.i_p] -= A[(b_i + kAcol) - 1] * B[tmp];
        }
      }
    }
  }

  for (j = 0; j < 18; j++) {
    jBcol = 11 * j;
    for (ipiv = 10; ipiv >= 0; ipiv--) {
      kAcol = 11 * ipiv;
      tmp = ipiv + jBcol;
      Aenea_model_B.temp = B[tmp];
      if (Aenea_model_B.temp != 0.0) {
        B[tmp] = Aenea_model_B.temp / A[ipiv + kAcol];
        for (b_i = 0; b_i < ipiv; b_i++) {
          Aenea_model_B.i_p = b_i + jBcol;
          B[Aenea_model_B.i_p] -= B[tmp] * A[b_i + kAcol];
        }
      }
    }
  }

  return info;
}

// Function for MATLAB Function: '<S552>/DEFINITIVA'
static void Aenea_model_mldivide(const real_T A[121], const real_T B[198],
  real_T Y[198])
{
  std::memcpy(&Y[0], &B[0], 198U * sizeof(real_T));
  std::memcpy(&Aenea_model_B.b_A[0], &A[0], 121U * sizeof(real_T));
  Aenea_model_xgetrfs(Aenea_model_B.b_A, Y);
}

// Function for MATLAB Function: '<S552>/DEFINITIVA'
static void Aenea_model_measure_F1B(const real_T stato[18], const real_T EULERO
  [3], real_T rx, real_T ry, real_T rz, real_T g, real_T Y[11])
{
  real_T Y_tmp;
  real_T Y_tmp_0;
  real_T Y_tmp_1;
  real_T Y_tmp_2;
  real_T Y_tmp_3;
  real_T Y_tmp_4;
  real_T Y_tmp_5;
  Y[0] = stato[0];
  Y[1] = stato[1];
  Y[2] = stato[2];
  Aenea_model_B.Y_tmp = std::cos(EULERO[0]);
  Aenea_model_B.Y_tmp_c = std::sin(EULERO[2]);
  Aenea_model_B.Y_tmp_f = std::cos(EULERO[2]);
  Aenea_model_B.Y_tmp_g = std::sin(EULERO[0]);
  Aenea_model_B.Y_tmp_g1 = std::sin(EULERO[1]);
  Y_tmp = std::cos(EULERO[1]);
  Y_tmp_0 = stato[9] * ry - stato[10] * rx;
  Y_tmp_2 = stato[9] * rz - stato[11] * rx;
  Y_tmp_3 = stato[10] * rz - stato[11] * ry;
  Y[3] = (((Aenea_model_B.Y_tmp * Aenea_model_B.Y_tmp_f * Aenea_model_B.Y_tmp_g1
            + Aenea_model_B.Y_tmp_g * Aenea_model_B.Y_tmp_c) * Y_tmp_0 + stato[3])
          + (Aenea_model_B.Y_tmp * Aenea_model_B.Y_tmp_c - Aenea_model_B.Y_tmp_f
             * Aenea_model_B.Y_tmp_g * Aenea_model_B.Y_tmp_g1) * Y_tmp_2) +
    Y_tmp_3 * (Aenea_model_B.Y_tmp_f * Y_tmp);
  Y_tmp_1 = std::cos(EULERO[0]) * std::sin(EULERO[2]);
  Y_tmp_5 = std::cos(EULERO[2]) * std::sin(EULERO[0]);
  Y[4] = ((stato[4] - (Y_tmp_5 - Y_tmp_1 * Aenea_model_B.Y_tmp_g1) * Y_tmp_0) -
          (std::sin(EULERO[0]) * std::sin(EULERO[2]) * Aenea_model_B.Y_tmp_g1 +
           Y_tmp_1) * Y_tmp_2) + Y_tmp_3 * (Y_tmp * Aenea_model_B.Y_tmp_c);
  Y_tmp_4 = stato[8] - g;
  Y[5] = ((((stato[6] * Y_tmp * Aenea_model_B.Y_tmp_f + stato[12]) + stato[7] *
            Y_tmp * Aenea_model_B.Y_tmp_c) - Y_tmp_4 * Aenea_model_B.Y_tmp_g1) +
          Y_tmp_0 * stato[10]) + Y_tmp_2 * stato[11];
  Y[6] = (((((std::cos(EULERO[2]) * std::sin(EULERO[0]) * std::sin(EULERO[1]) -
              Y_tmp_1) * stato[6] + stato[13]) + (std::sin(EULERO[0]) * std::sin
             (EULERO[2]) * std::sin(EULERO[1]) + std::cos(EULERO[0]) * std::cos
             (EULERO[2])) * stato[7]) + Y_tmp * Aenea_model_B.Y_tmp_g * Y_tmp_4)
          - Y_tmp_0 * stato[9]) + Y_tmp_3 * stato[11];
  Y[7] = (((((std::cos(EULERO[0]) * std::cos(EULERO[2]) * std::sin(EULERO[1]) +
              std::sin(EULERO[0]) * std::sin(EULERO[2])) * stato[6] + stato[14])
            + (std::cos(EULERO[0]) * std::sin(EULERO[2]) * std::sin(EULERO[1]) -
               Y_tmp_5) * stato[7]) + Aenea_model_B.Y_tmp * Y_tmp * Y_tmp_4) -
          Y_tmp_2 * stato[9]) - Y_tmp_3 * stato[10];
  Y[8] = stato[15] + stato[9];
  Y[9] = stato[16] + stato[10];
  Y[10] = stato[17] + stato[11];
}

// Function for MATLAB Function: '<S552>/DEFINITIVA'
static void Aenea_model_f_pred_F1B(const real_T prediction[18], real_T a, real_T
  dt, real_T f[18])
{
  real_T f_tmp;
  f_tmp = a + prediction[2];
  f[0] = dt * prediction[3] / f_tmp + prediction[0];
  f[1] = dt * prediction[4] / (f_tmp * std::cos(prediction[0])) + prediction[1];
  f[2] = prediction[2] - dt * prediction[5];
  f[3] = prediction[6] * dt + prediction[3];
  f[4] = prediction[7] * dt + prediction[4];
  f[5] = prediction[8] * dt + prediction[5];
  std::memcpy(&f[6], &prediction[6], 12U * sizeof(real_T));
}

// Function for Chart: '<S34>/Chart'
static void Aenea_model_Waypoint(const boolean_T *Ap_sel, real_T *Wp_selector,
  real_T *Vec_selector, real_T *Ato_selector, real_T *Al_selector, real_T
  *Go_home_selector)
{
  if ((*Ap_sel) && (Aenea_model_B.modo == 5.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if (!*Ap_sel) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Aenea_model_B.modo == 2.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Aenea_model_B.modo == 4.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else {
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  }
}

// Function for Chart: '<S34>/Chart'
static void Aenea_model_In(const boolean_T *Ap_sel, real_T *Wp_selector, real_T *
  Vec_selector, real_T *Ato_selector, real_T *Al_selector, real_T
  *Go_home_selector)
{
  if ((*Ap_sel) && (Aenea_model_B.modo == 1.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
    *Wp_selector = 1.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Aenea_model_B.modo == 2.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Vettoriale;
    *Wp_selector = 0.0;
    *Vec_selector = 1.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Aenea_model_B.modo == 5.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_GoHome;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 1.0;
  } else if ((*Ap_sel) && (Aenea_model_B.modo == 4.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_AutoLanding;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 1.0;
    *Go_home_selector = 0.0;
  } else if ((*Ap_sel) && (Aenea_model_B.modo == 3.0)) {
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_AutoTakeoff;
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 1.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  } else {
    *Wp_selector = 0.0;
    *Vec_selector = 0.0;
    *Ato_selector = 0.0;
    *Al_selector = 0.0;
    *Go_home_selector = 0.0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = std::fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > std::floor(u1))) {
      q = std::abs(u0 / u1);
      yEq = !(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

// Model step function
void Aenea_model_step(void)
{
  static const real_T h[18] = { 0.0, 0.0, 1.0, 0.0, 0.0, -0.02, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T j_0[18] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.02, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T l[18] = { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.02, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T m[18] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.02,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T b[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T c[18] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T d[18] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T e[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    0, 0 };

  static const int8_T f[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    1, 0 };

  static const int8_T g[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 1 };

  static const int8_T n[18] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T o[18] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T p[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T q[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T r[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T s[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0 };

  static const int8_T t[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0 };

  static const int8_T u[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0 };

  static const int8_T v[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const int8_T w[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0 };

  static const int8_T x[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0 };

  static const int8_T y[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1 };

  uint8_T counter;
  uint8_T j;
  boolean_T Ap_sel;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T rtb_y_b;
  boolean_T rtb_y_e;
  boolean_T rtb_y_p;
  boolean_T tmp;
  boolean_T tmp_0;

  // MATLAB Function: '<S1>/MATLAB Function4' incorporates:
  //   Constant: '<S1>/Constant2'
  //   Constant: '<S1>/Constant3'

  Aenea_model_B.Switch_n = 0;
  Aenea_model_B.caso = 0;
  std::memset(&Aenea_model_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  std::memset(&Aenea_model_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  Aenea_model_find_254(Aenea_model_ConstP.Constant2_Value_l,
                       Aenea_model_B.aterra, &Aenea_model_B.num_254);
  if (Aenea_model_DW.Interr_parz && (Aenea_model_B.num_254 == 1.0)) {
    Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
      (Aenea_model_DW.counter_j + 1U);
    if (Aenea_model_DW.counter_j + 1U > 255U) {
      Aenea_model_B.tolleranza_distWP_fut = 255;
    }

    if (Aenea_model_B.aterra[0] != Aenea_model_B.tolleranza_distWP_fut) {
      Aenea_model_B.num_254 = 0.0;
    }
  }

  Ap_sel = !Aenea_model_DW.Interr_parz;
  if ((Aenea_model_B.num_254 == 1.0) && Ap_sel) {
    Aenea_model_B.caso = 1;
  } else if ((Aenea_model_B.num_254 == 0.0) && Aenea_model_DW.Interr_parz) {
    Aenea_model_B.caso = 2;
  } else if ((Aenea_model_B.num_254 == 1.0) && Aenea_model_DW.Interr_parz) {
    Aenea_model_B.caso = 3;
  } else {
    if ((Aenea_model_B.num_254 == 2.0) && Ap_sel) {
      Aenea_model_B.caso = 4;
    }
  }

  switch (Aenea_model_B.caso) {
   case 1:
    Aenea_model_B.smax = Aenea_model_B.aterra[static_cast<int32_T>
      (Aenea_model_B.num_254) - 1];
    if (Aenea_model_B.smax == 100.0) {
      Aenea_model_DW.message[0] = 0U;
      Aenea_model_DW.Interr_parz = true;
    } else {
      Aenea_model_DW.mess_len = 0.0;
      if (Aenea_model_B.smax > Aenea_model_DW.mess_len) {
        Aenea_model_B.tolleranza_distWP_fut = 0;
        Aenea_model_B.caso = 0;
      } else {
        Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
          (Aenea_model_B.smax) - 1;
        Aenea_model_B.caso = static_cast<int32_T>(Aenea_model_DW.mess_len);
      }

      Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.caso -
        Aenea_model_B.tolleranza_distWP_fut;
      if (0 <= Aenea_model_B.tolleranza_distWP_fut - 1) {
        std::memset(&Aenea_model_DW.message[0], 0,
                    Aenea_model_B.tolleranza_distWP_fut * sizeof(uint8_T));
      }

      Aenea_model_B.smax = rt_roundd_snf(8.0 - Aenea_model_DW.mess_len);
      if (Aenea_model_B.smax < 256.0) {
        if (Aenea_model_B.smax >= 0.0) {
          Aenea_model_DW.counter_j = static_cast<uint8_T>(Aenea_model_B.smax);
        } else {
          Aenea_model_DW.counter_j = 0U;
        }
      } else {
        Aenea_model_DW.counter_j = MAX_uint8_T;
      }

      Aenea_model_DW.Interr_parz = true;
    }
    break;

   case 2:
    std::memset(&Aenea_model_B.x[0], 0, 100U * sizeof(boolean_T));
    if (Aenea_model_ifWhileCond(Aenea_model_B.x)) {
      Aenea_model_B.smax = rt_roundd_snf(Aenea_model_DW.mess_len + 1.0);
      if (Aenea_model_B.smax < 256.0) {
        if (Aenea_model_B.smax >= 0.0) {
          j = static_cast<uint8_T>(Aenea_model_B.smax);
        } else {
          j = 0U;
        }
      } else {
        j = MAX_uint8_T;
      }

      Aenea_model_B.smax = rt_roundd_snf(Aenea_model_DW.mess_len + static_cast<
        real_T>(Aenea_model_DW.counter_j));
      if (Aenea_model_B.smax < 256.0) {
        if (Aenea_model_B.smax >= 0.0) {
          counter = static_cast<uint8_T>(Aenea_model_B.smax);
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (j > counter) {
        Aenea_model_B.Switch_n = 1;
      } else {
        Aenea_model_B.Switch_n = j;
      }

      if (1 > Aenea_model_DW.counter_j) {
        Aenea_model_B.tolleranza_distWP_fut = -1;
      } else {
        Aenea_model_B.tolleranza_distWP_fut = Aenea_model_DW.counter_j - 1;
      }

      if (0 <= Aenea_model_B.tolleranza_distWP_fut) {
        std::memset(&Aenea_model_DW.message[Aenea_model_B.Switch_n + -1], 0,
                    (((Aenea_model_B.tolleranza_distWP_fut +
                       Aenea_model_B.Switch_n) - Aenea_model_B.Switch_n) + 1) *
                    sizeof(uint8_T));
      }

      Aenea_model_DW.Interr_parz = false;
      Aenea_model_B.Switch_n = 1;
      for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
        Aenea_model_B.messaggio[Aenea_model_B.i] =
          Aenea_model_DW.message[Aenea_model_B.i];
        Aenea_model_DW.message[Aenea_model_B.i] = 0U;
      }

      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_DW.counter_j = 0U;
    } else {
      Aenea_model_DW.Interr_parz = false;
      Aenea_model_B.Switch_n = 1;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_DW.counter_j = 0U;
    }
    break;

   case 3:
    Aenea_model_B.smax = rt_roundd_snf(Aenea_model_DW.mess_len + 1.0);
    if (Aenea_model_B.smax < 256.0) {
      if (Aenea_model_B.smax >= 0.0) {
        j = static_cast<uint8_T>(Aenea_model_B.smax);
      } else {
        j = 0U;
      }
    } else {
      j = MAX_uint8_T;
    }

    Aenea_model_B.smax = rt_roundd_snf(Aenea_model_DW.mess_len +
      static_cast<real_T>(Aenea_model_DW.counter_j));
    if (Aenea_model_B.smax < 256.0) {
      if (Aenea_model_B.smax >= 0.0) {
        counter = static_cast<uint8_T>(Aenea_model_B.smax);
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (j > counter) {
      Aenea_model_B.Switch_n = 1;
    } else {
      Aenea_model_B.Switch_n = j;
    }

    if (1 > Aenea_model_DW.counter_j) {
      Aenea_model_B.tolleranza_distWP_fut = -1;
    } else {
      Aenea_model_B.tolleranza_distWP_fut = Aenea_model_DW.counter_j - 1;
    }

    if (0 <= Aenea_model_B.tolleranza_distWP_fut) {
      std::memset(&Aenea_model_DW.message[Aenea_model_B.Switch_n + -1], 0,
                  (((Aenea_model_B.tolleranza_distWP_fut +
                     Aenea_model_B.Switch_n) - Aenea_model_B.Switch_n) + 1) *
                  sizeof(uint8_T));
    }

    Aenea_model_B.Switch_n = 1;
    for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
      Aenea_model_B.messaggio[Aenea_model_B.i] =
        Aenea_model_DW.message[Aenea_model_B.i];
      Aenea_model_DW.message[Aenea_model_B.i] = 0U;
    }

    Aenea_model_DW.mess_len = 0.0;
    if (Aenea_model_B.aterra[static_cast<int32_T>(Aenea_model_B.num_254) - 1] >
        Aenea_model_DW.mess_len) {
      Aenea_model_B.tolleranza_distWP_fut = 0;
      Aenea_model_B.caso = 0;
    } else {
      Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
        (Aenea_model_B.aterra[static_cast<int32_T>(Aenea_model_B.num_254) - 1])
        - 1;
      Aenea_model_B.caso = static_cast<int32_T>(Aenea_model_DW.mess_len);
    }

    Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.caso -
      Aenea_model_B.tolleranza_distWP_fut;
    if (0 <= Aenea_model_B.tolleranza_distWP_fut - 1) {
      std::memset(&Aenea_model_DW.message[0], 0,
                  Aenea_model_B.tolleranza_distWP_fut * sizeof(uint8_T));
    }

    Aenea_model_B.smax = rt_roundd_snf(8.0 - Aenea_model_DW.mess_len);
    if (Aenea_model_B.smax < 256.0) {
      if (Aenea_model_B.smax >= 0.0) {
        Aenea_model_DW.counter_j = static_cast<uint8_T>(Aenea_model_B.smax);
      } else {
        Aenea_model_DW.counter_j = 0U;
      }
    } else {
      Aenea_model_DW.counter_j = MAX_uint8_T;
    }

    Aenea_model_DW.Interr_parz = true;
    break;

   case 4:
    Aenea_model_B.smax = rt_roundd_snf(Aenea_model_B.aterra[0]);
    if (Aenea_model_B.smax < 256.0) {
      if (Aenea_model_B.smax >= 0.0) {
        counter = static_cast<uint8_T>(Aenea_model_B.smax);
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    Aenea_model_B.smax = rt_roundd_snf(Aenea_model_B.aterra[0] + 7.0);
    if (Aenea_model_B.smax < 256.0) {
      if (Aenea_model_B.smax >= 0.0) {
        j = static_cast<uint8_T>(Aenea_model_B.smax);
      } else {
        j = 0U;
      }
    } else {
      j = MAX_uint8_T;
    }

    if (counter > j) {
      Aenea_model_B.Switch_n = 0;
      Aenea_model_B.tolleranza_distWP_fut = 0;
    } else {
      Aenea_model_B.Switch_n = counter - 1;
      Aenea_model_B.tolleranza_distWP_fut = j;
    }

    Aenea_model_B.tolleranza_distWP_fut -= Aenea_model_B.Switch_n;
    if (0 <= Aenea_model_B.tolleranza_distWP_fut - 1) {
      std::memset(&Aenea_model_B.messaggio[0], 0,
                  Aenea_model_B.tolleranza_distWP_fut * sizeof(uint8_T));
    }

    Aenea_model_B.Switch_n = 1;
    if (Aenea_model_B.aterra[1] - Aenea_model_B.aterra[0] > 3.0) {
      Aenea_model_B.smax = rt_roundd_snf(0.0 - Aenea_model_B.aterra[1]);
      if (Aenea_model_B.smax < 2.147483648E+9) {
        if (Aenea_model_B.smax >= -2.147483648E+9) {
          Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
            (Aenea_model_B.smax);
        } else {
          Aenea_model_B.tolleranza_distWP_fut = MIN_int32_T;
        }
      } else {
        Aenea_model_B.tolleranza_distWP_fut = MAX_int32_T;
      }

      if (Aenea_model_B.tolleranza_distWP_fut == 7) {
        Aenea_model_B.smax = rt_roundd_snf(Aenea_model_B.aterra[1]);
        if (Aenea_model_B.smax < 256.0) {
          if (Aenea_model_B.smax >= 0.0) {
            counter = static_cast<uint8_T>(Aenea_model_B.smax);
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        Aenea_model_B.smax = rt_roundd_snf(Aenea_model_B.aterra[1] + 7.0);
        if (Aenea_model_B.smax < 256.0) {
          if (Aenea_model_B.smax >= 0.0) {
            j = static_cast<uint8_T>(Aenea_model_B.smax);
          } else {
            j = 0U;
          }
        } else {
          j = MAX_uint8_T;
        }

        if (counter > j) {
          Aenea_model_B.Switch_n = 0;
          Aenea_model_B.tolleranza_distWP_fut = 0;
        } else {
          Aenea_model_B.Switch_n = counter - 1;
          Aenea_model_B.tolleranza_distWP_fut = j;
        }

        Aenea_model_B.tolleranza_distWP_fut -= Aenea_model_B.Switch_n;
        if (0 <= Aenea_model_B.tolleranza_distWP_fut - 1) {
          std::memset(&Aenea_model_DW.message[0], 0,
                      Aenea_model_B.tolleranza_distWP_fut * sizeof(uint8_T));
        }

        Aenea_model_B.Switch_n = 2;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio_2[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_j = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        Aenea_model_B.smax = rt_roundd_snf(Aenea_model_B.aterra[1]);
        if (Aenea_model_B.smax < 2.147483648E+9) {
          if (Aenea_model_B.smax >= -2.147483648E+9) {
            Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
              (Aenea_model_B.smax);
          } else {
            Aenea_model_B.tolleranza_distWP_fut = MIN_int32_T;
          }
        } else {
          Aenea_model_B.tolleranza_distWP_fut = MAX_int32_T;
        }

        if (Aenea_model_B.tolleranza_distWP_fut > 0) {
          Aenea_model_B.tolleranza_distWP_fut = -1;
        } else {
          Aenea_model_B.tolleranza_distWP_fut -= 2;
        }

        Aenea_model_DW.mess_len = static_cast<int8_T>
          (-Aenea_model_B.tolleranza_distWP_fut - 1);
        if (Aenea_model_B.smax < 2.147483648E+9) {
          if (Aenea_model_B.smax >= -2.147483648E+9) {
            Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
              (Aenea_model_B.smax);
          } else {
            Aenea_model_B.tolleranza_distWP_fut = MIN_int32_T;
          }
        } else {
          Aenea_model_B.tolleranza_distWP_fut = MAX_int32_T;
        }

        if (Aenea_model_B.tolleranza_distWP_fut > 0) {
          Aenea_model_B.tolleranza_distWP_fut = 0;
        } else {
          Aenea_model_B.tolleranza_distWP_fut = 1 -
            Aenea_model_B.tolleranza_distWP_fut;
        }

        if (0 <= Aenea_model_B.tolleranza_distWP_fut - 1) {
          std::memset(&Aenea_model_DW.message[0], 0,
                      Aenea_model_B.tolleranza_distWP_fut * sizeof(uint8_T));
        }

        Aenea_model_B.smax = rt_roundd_snf(8.0 - Aenea_model_DW.mess_len);
        if (Aenea_model_B.smax < 256.0) {
          if (Aenea_model_B.smax >= 0.0) {
            Aenea_model_DW.counter_j = static_cast<uint8_T>(Aenea_model_B.smax);
          } else {
            Aenea_model_DW.counter_j = 0U;
          }
        } else {
          Aenea_model_DW.counter_j = MAX_uint8_T;
        }

        Aenea_model_DW.Interr_parz = true;
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.counter_j = 0U;
      Aenea_model_DW.mess_len = 0.0;
    }
    break;
  }

  // MATLAB Function: '<S1>/MATLAB Function2' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function4'
  //   Memory: '<S1>/Memory4'

  std::memset(&Aenea_model_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (Aenea_model_B.tolleranza_distWP_fut = 0;
       Aenea_model_B.tolleranza_distWP_fut < 100;
       Aenea_model_B.tolleranza_distWP_fut++) {
    Aenea_model_B.buffer[3 * Aenea_model_B.tolleranza_distWP_fut] = 0U;
  }

  for (Aenea_model_B.ix = 0; Aenea_model_B.ix < 2; Aenea_model_B.ix++) {
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 100;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.caso = 3 * Aenea_model_B.tolleranza_distWP_fut +
        Aenea_model_B.ix;
      Aenea_model_B.buffer[Aenea_model_B.caso + 1] =
        Aenea_model_DW.Memory4_PreviousInput_j[Aenea_model_B.caso];
    }
  }

  Aenea_model_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (Aenea_model_B.i >= 1)) {
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 100;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.x[Aenea_model_B.tolleranza_distWP_fut] =
        (Aenea_model_B.buffer[(3 * Aenea_model_B.tolleranza_distWP_fut +
          Aenea_model_B.i) - 1] == 0);
    }

    Ap_sel = true;
    Aenea_model_B.tolleranza_distWP_fut = 0;
    exitg2 = false;
    while ((!exitg2) && (Aenea_model_B.tolleranza_distWP_fut < 100)) {
      if (!Aenea_model_B.x[Aenea_model_B.tolleranza_distWP_fut]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        Aenea_model_B.tolleranza_distWP_fut++;
      }
    }

    if (Ap_sel) {
      counter = static_cast<uint8_T>(Aenea_model_B.i);
      exitg1 = true;
    } else {
      Aenea_model_B.i--;
    }
  }

  if (Aenea_model_B.Switch_n == 1) {
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 100;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.buffer[(counter + 3 * Aenea_model_B.tolleranza_distWP_fut) -
        1] = Aenea_model_B.messaggio[Aenea_model_B.tolleranza_distWP_fut];
    }
  } else if (Aenea_model_B.Switch_n == 2) {
    Aenea_model_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      Aenea_model_B.qY = 0U;
    }

    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 100;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.buffer[(counter + 3 * Aenea_model_B.tolleranza_distWP_fut) -
        1] = Aenea_model_B.messaggio[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.buffer[(static_cast<int32_T>(Aenea_model_B.qY) + 3 *
                            Aenea_model_B.tolleranza_distWP_fut) - 1] =
        Aenea_model_B.messaggio_2[Aenea_model_B.tolleranza_distWP_fut];
    }
  } else {
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 100;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.buffer[(counter + 3 * Aenea_model_B.tolleranza_distWP_fut) -
        1] = 0U;
    }
  }

  for (Aenea_model_B.tolleranza_distWP_fut = 0;
       Aenea_model_B.tolleranza_distWP_fut < 100;
       Aenea_model_B.tolleranza_distWP_fut++) {
    Aenea_model_B.messaggio[Aenea_model_B.tolleranza_distWP_fut] =
      Aenea_model_DW.Memory4_PreviousInput_j[3 *
      Aenea_model_B.tolleranza_distWP_fut + 2];
  }

  // MATLAB Function: '<S1>/MATLAB Function3' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function2'
  //   Memory: '<S1>/Memory4'
  //   Memory: '<S1>/Memory5'

  if (Aenea_model_DW.Memory4_PreviousInput_j[8] !=
      Aenea_model_DW.Memory5_PreviousInput_b[2]) {
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 100;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.x[Aenea_model_B.tolleranza_distWP_fut] =
        (Aenea_model_DW.Memory4_PreviousInput_j[3 *
         Aenea_model_B.tolleranza_distWP_fut + 2] != 0);
    }

    Ap_sel = true;
    Aenea_model_B.tolleranza_distWP_fut = 0;
    exitg1 = false;
    while ((!exitg1) && (Aenea_model_B.tolleranza_distWP_fut < 100)) {
      if (!Aenea_model_B.x[Aenea_model_B.tolleranza_distWP_fut]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        Aenea_model_B.tolleranza_distWP_fut++;
      }
    }

    if (!Ap_sel) {
      if (Aenea_model_DW.counter > 100) {
        Aenea_model_DW.counter = 0U;
      }

      Aenea_model_B.qY = Aenea_model_DW.counter + 1U;
      if (Aenea_model_DW.counter + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      Aenea_model_DW.counter = static_cast<uint16_T>(Aenea_model_B.qY);
    }
  }

  // End of MATLAB Function: '<S1>/MATLAB Function3'

  // MATLAB Function: '<S1>/MATLAB Function1'
  if (!Aenea_model_DW.WP_dbP_not_empty) {
    std::memset(&Aenea_model_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    Aenea_model_DW.WP_dbP_not_empty = true;
    std::memset(&Aenea_model_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if (!Aenea_model_DW.WP_dbP_AL_not_empty) {
    std::memset(&Aenea_model_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    Aenea_model_DW.WP_dbP_AL_not_empty = true;
  }

  Aenea_model_DW.Memory2_PreviousInput_d[0] = 1U;
  Aenea_model_DW.Memory2_PreviousInput_d[1] = 0U;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 7; Aenea_model_B.i++) {
    Aenea_model_B.f = rt_roundf_snf(Aenea_model_DW.riferimenti[Aenea_model_B.i]);
    if (Aenea_model_B.f < 256.0F) {
      if (Aenea_model_B.f >= 0.0F) {
        Aenea_model_DW.Memory2_PreviousInput_d[Aenea_model_B.i + 2] =
          static_cast<uint8_T>(Aenea_model_B.f);
      } else {
        Aenea_model_DW.Memory2_PreviousInput_d[Aenea_model_B.i + 2] = 0U;
      }
    } else {
      Aenea_model_DW.Memory2_PreviousInput_d[Aenea_model_B.i + 2] = MAX_uint8_T;
    }
  }

  // DataTypeConversion: '<S1>/Data Tversion' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  for (Aenea_model_B.i = 0; Aenea_model_B.i < 42; Aenea_model_B.i++) {
    Aenea_model_B.WP_db_param[Aenea_model_B.i] =
      Aenea_model_DW.WP_dbP[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S1>/Data Tversion'

  // UnitDelay: '<S566>/Unit Delay'
  std::memcpy(&Aenea_model_B.UnitDelay[0], &Aenea_model_DW.UnitDelay_DSTATE[0],
              9U * sizeof(real_T));

  // S-Function (Mti_sfun): '<S566>/S-Function Builder1'
  Mti_sfun_Outputs_wrapper(&Aenea_model_B.UnitDelay[0],
    &Aenea_model_B.SFunctionBuilder1[0]);

  // S-Function (byte2any_svd): '<S566>/Byte Unpack'

  // Unpack: <S566>/Byte Unpack
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    // Packed input data type - uint8_T
    // Unpacking the values to output 1
    // Output data type - uint8_T, size - 4
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&Aenea_model_B.ByteUnpack_o1[0], (uint8_T*)
             &Aenea_model_B.SFunctionBuilder1[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }

    // Offset calculations based on alignemnt for packing next input
    MW_remainder2 = MW_outputPortWidth % 1;
    if (MW_remainder2 == 0) {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
    } else {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
        MW_remainder2);
    }

    // Unpacking the values to output 2
    // Output data type - real32_T, size - 9
    {
      MW_outputPortWidth = 9 * sizeof(real32_T);
      memcpy((uint8_T*)&Aenea_model_B.ByteUnpack_o2[0], (uint8_T*)
             &Aenea_model_B.SFunctionBuilder1[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }

    // Offset calculations based on alignemnt for packing next input
    MW_remainder2 = MW_outputPortWidth % 1;
    if (MW_remainder2 == 0) {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
    } else {
      MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
        MW_remainder2);
    }

    // Unpacking the values to output 3
    // Output data type - uint8_T, size - 1
    {
      MW_outputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)&Aenea_model_B.ByteUnpack_o3, (uint8_T*)
             &Aenea_model_B.SFunctionBuilder1[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  // S-Function (reverseendian_svd): '<S566>/Byte Reversal'

  // ReverseEndian: <S566>/Byte Reversal

  // 4 byte-wide input datatypes
  {
    int_T i1;
    const real32_T *u0 = &Aenea_model_B.ByteUnpack_o2[0];
    real32_T *y0 = &Aenea_model_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  // Outputs for Atomic SubSystem: '<S564>/Execution_loop'
  // DataTypeConversion: '<S568>/Data Type Conversion3' incorporates:
  //   UnitDelay: '<S564>/Unit Delay1'

  Aenea_model_B.DataTypeConversion3 = static_cast<real32_T>
    (Aenea_model_DW.UnitDelay1_DSTATE);

  // S-Function (BMP280_sfun): '<S568>/S-Function Builder'
  BMP280_sfun_Outputs_wrapper(&Aenea_model_B.DataTypeConversion3,
    &Aenea_model_B.SFunctionBuilder_o1, &Aenea_model_B.SFunctionBuilder_o2,
    &Aenea_model_B.SFunctionBuilder_o3);

  // End of Outputs for SubSystem: '<S564>/Execution_loop'

  // DataTypeConversion: '<S5>/Data Type Conversion1'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 9; Aenea_model_B.i++) {
    Aenea_model_B.DataTypeConversion1[Aenea_model_B.i] =
      Aenea_model_B.ByteReversal[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S5>/Data Type Conversion1'

  // S-Function (byte2any_svd): '<S564>/Byte Unpack' incorporates:
  //   Constant: '<S564>/registro memoria2 13'


  // Unpack: <S564>/Byte Unpack
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    // Packed input data type - uint8_T
    // Unpacking the values to output 1
    // Output data type - uint16_T, size - 8
    {
      MW_outputPortWidth = 8 * sizeof(uint16_T);
      memcpy((uint8_T*)&Aenea_model_B.ByteUnpack[0], (uint8_T*)
             Aenea_model_ConstP.registromemoria213_Value + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  // S-Function (GPS_sfun): '<S565>/S-Function Builder'
  GPS_sfun_Outputs_wrapper(&Aenea_model_B.Lat, &Aenea_model_B.Long,
    &Aenea_model_B.V, &Aenea_model_B.quota, &Aenea_model_B.heading,
    &Aenea_model_B.SFunctionBuilder_o6);

  // Product: '<S4>/Multiply2' incorporates:
  //   Trigonometry: '<S4>/Cos2'

  Aenea_model_B.num_254 = std::cos(Aenea_model_B.heading) * 0.0;

  // Product: '<S4>/Multiply3' incorporates:
  //   Trigonometry: '<S4>/Sin2'

  Aenea_model_B.V_est = 0.0 * std::sin(Aenea_model_B.heading);

  // Logic: '<S558>/NOT' incorporates:
  //   Memory: '<S558>/Memory'
  //   RelationalOperator: '<S558>/Equal'

  Aenea_model_B.NOT[5] = !(Aenea_model_B.DataTypeConversion1[6] ==
    Aenea_model_DW.Memory_PreviousInput[5]);
  Aenea_model_B.NOT[6] = !(Aenea_model_B.DataTypeConversion1[7] ==
    Aenea_model_DW.Memory_PreviousInput[6]);
  Aenea_model_B.NOT[7] = !(Aenea_model_B.DataTypeConversion1[8] ==
    Aenea_model_DW.Memory_PreviousInput[7]);
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    Aenea_model_B.NOT[Aenea_model_B.i + 8] =
      !(Aenea_model_DW.Memory_PreviousInput[Aenea_model_B.i + 8] ==
        Aenea_model_B.DataTypeConversion1[Aenea_model_B.i]);
  }

  // End of Logic: '<S558>/NOT'

  // MATLAB Function: '<S558>/MATLAB Function'
  rtb_y_p = (Aenea_model_B.NOT[5] || (Aenea_model_B.NOT[6] ||
              (Aenea_model_B.NOT[7] || (Aenea_model_B.NOT[8] ||
    (Aenea_model_B.NOT[9] || (Aenea_model_B.NOT[10] || (Aenea_model_B.NOT[11] ||
    Aenea_model_B.NOT[12])))))));

  // Logic: '<S557>/NOT' incorporates:
  //   Memory: '<S557>/Memory'
  //   RelationalOperator: '<S557>/Equal1'

  Aenea_model_B.NOT[3] = !(Aenea_model_B.num_254 ==
    Aenea_model_DW.Memory_PreviousInput_o[3]);
  Aenea_model_B.NOT[4] = !(Aenea_model_B.V_est ==
    Aenea_model_DW.Memory_PreviousInput_o[4]);

  // MATLAB Function: '<S557>/MATLAB Function1' incorporates:
  //   Logic: '<S557>/NOT'
  //   Memory: '<S557>/Memory'
  //   RelationalOperator: '<S557>/Equal1'

  rtb_y_e = ((!(Aenea_model_B.Lat == Aenea_model_DW.Memory_PreviousInput_o[0])) ||
             (!(Aenea_model_B.Long == Aenea_model_DW.Memory_PreviousInput_o[1])));

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S552>/Enable'

  // SignalConversion generated from: '<S559>/ SFunction ' incorporates:
  //   DataTypeConversion: '<S568>/Data Type Conversion2'
  //   Inport: '<S552>/Misure'
  //   MATLAB Function: '<S553>/MATLAB Function2'

  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[0] = Aenea_model_B.Lat;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[1] = Aenea_model_B.Long;

  // Outputs for Atomic SubSystem: '<S564>/Execution_loop'
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[2] =
    Aenea_model_B.SFunctionBuilder_o3;

  // End of Outputs for SubSystem: '<S564>/Execution_loop'
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[3] = Aenea_model_B.num_254;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[4] = Aenea_model_B.V_est;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5] =
    Aenea_model_B.DataTypeConversion1[6];
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6] =
    Aenea_model_B.DataTypeConversion1[7];
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7] =
    Aenea_model_B.DataTypeConversion1[8];
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // RelationalOperator: '<S557>/Equal1'
    Aenea_model_B.Delta_clock =
      Aenea_model_B.DataTypeConversion1[Aenea_model_B.i];

    // Logic: '<S557>/NOT' incorporates:
    //   Memory: '<S557>/Memory'
    //   RelationalOperator: '<S557>/Equal1'

    Aenea_model_B.NOT[Aenea_model_B.i + 8] =
      !(Aenea_model_DW.Memory_PreviousInput_o[Aenea_model_B.i + 8] ==
        Aenea_model_B.Delta_clock);

    // SignalConversion generated from: '<S559>/ SFunction ' incorporates:
    //   Inport: '<S552>/Misure'
    //   MATLAB Function: '<S553>/MATLAB Function2'

    Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[Aenea_model_B.i + 8] =
      Aenea_model_B.Delta_clock;
  }

  // MATLAB Function: '<S553>/MATLAB Function2' incorporates:
  //   Constant: '<S553>/Constant'
  //   MATLAB Function: '<S552>/DEFINITIVA'
  //   SignalConversion generated from: '<S559>/ SFunction '

  Aenea_model_B.Wp_selector = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Product1 = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
  Aenea_model_B.smax = std::sin(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]);
  Aenea_model_B.Vec_selector = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
  Aenea_model_B.a_c = std::sin(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Sum_fj = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k
    [6]);

  // End of Outputs for SubSystem: '<S4>/Filter2'
  Aenea_model_B.aterra_tmp[0] = Aenea_model_B.Wp_selector * Aenea_model_B.Sum_fj;
  Aenea_model_B.aterra_tmp[3] = Aenea_model_B.Wp_selector *
    Aenea_model_B.Vec_selector * Aenea_model_B.smax - Aenea_model_B.Product1 *
    Aenea_model_B.a_c;
  Aenea_model_B.aterra_tmp[6] = Aenea_model_B.Product1 *
    Aenea_model_B.Wp_selector * Aenea_model_B.smax + Aenea_model_B.Vec_selector *
    Aenea_model_B.a_c;
  Aenea_model_B.aterra_tmp[1] = Aenea_model_B.a_c * Aenea_model_B.Sum_fj;

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S552>/Enable'

  Aenea_model_B.Ato_selector = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);

  // End of Outputs for SubSystem: '<S4>/Filter2'
  Aenea_model_B.aterra_tmp[4] = Aenea_model_B.Ato_selector * Aenea_model_B.smax
    + std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S552>/Enable'

  Aenea_model_B.Al_selector = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.psi_ref_pre = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);

  // End of Outputs for SubSystem: '<S4>/Filter2'
  Aenea_model_B.aterra_tmp[7] = Aenea_model_B.Al_selector * Aenea_model_B.smax -
    Aenea_model_B.psi_ref_pre;
  Aenea_model_B.aterra_tmp[2] = -Aenea_model_B.smax;
  Aenea_model_B.aterra_tmp[5] = Aenea_model_B.Sum_fj *
    Aenea_model_B.Vec_selector;
  Aenea_model_B.aterra_tmp[8] = Aenea_model_B.Product1 * Aenea_model_B.Sum_fj;
  Aenea_model_B.Delta_clock = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[8];
  Aenea_model_B.psi_ref = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[9];
  Aenea_model_B.angoloWP = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[10];
  for (Aenea_model_B.tolleranza_distWP_fut = 0;
       Aenea_model_B.tolleranza_distWP_fut < 3;
       Aenea_model_B.tolleranza_distWP_fut++) {
    Aenea_model_B.aterra[Aenea_model_B.tolleranza_distWP_fut] =
      Aenea_model_B.aterra_tmp[Aenea_model_B.tolleranza_distWP_fut + 6] *
      Aenea_model_B.angoloWP +
      (Aenea_model_B.aterra_tmp[Aenea_model_B.tolleranza_distWP_fut + 3] *
       Aenea_model_B.psi_ref +
       Aenea_model_B.aterra_tmp[Aenea_model_B.tolleranza_distWP_fut] *
       Aenea_model_B.Delta_clock);
  }

  Aenea_model_B.y[0] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[0];
  Aenea_model_B.y[1] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[1];
  Aenea_model_B.y[2] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[2];
  Aenea_model_B.y[3] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[3];
  Aenea_model_B.y[4] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[4];
  Aenea_model_B.y[5] = 0.0;
  Aenea_model_B.y[6] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5];
  Aenea_model_B.y[7] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6];
  Aenea_model_B.y[8] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7];
  Aenea_model_B.y[9] = Aenea_model_B.aterra[0];
  Aenea_model_B.y[10] = Aenea_model_B.aterra[1];
  Aenea_model_B.y[11] = Aenea_model_B.aterra[2];
  Aenea_model_B.y[12] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[11];
  Aenea_model_B.y[13] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[12];
  Aenea_model_B.y[14] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[13];
  Aenea_model_B.y[15] = 0.0392;
  Aenea_model_B.y[16] = -0.0598;
  Aenea_model_B.y[17] = 0.0384;
  Aenea_model_B.y[18] = 1.5184E-6;
  Aenea_model_B.y[19] = 2.9671E-5;
  Aenea_model_B.y[20] = 5.4105E-5;

  // Step: '<S553>/Step' incorporates:
  //   DigitalClock: '<S245>/Digital Clock1'

  Aenea_model_B.Delta_clock = ((Aenea_model_M->Timing.clockTick0) * 0.02);

  // Switch: '<S553>/Switch' incorporates:
  //   Step: '<S553>/Step'

  Aenea_model_B.Switch_n = !(Aenea_model_B.Delta_clock < 0.4);

  // Outputs for Triggered SubSystem: '<S553>/Sample and Hold' incorporates:
  //   TriggerPort: '<S560>/Trigger'

  Aenea_model_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
    &Aenea_model_PrevZCX.SampleandHold_Trig_ZCE,
    (static_cast<real_T>(Aenea_model_B.Switch_n)));
  if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
    // Inport: '<S560>/In'
    std::memcpy(&Aenea_model_B.In[0], &Aenea_model_B.y[0], 21U * sizeof(real_T));
  }

  // End of Outputs for SubSystem: '<S553>/Sample and Hold'

  // MATLAB Function: '<S557>/MATLAB Function'
  rtb_y_b = (Aenea_model_B.NOT[3] || Aenea_model_B.NOT[4]);

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S552>/Enable'

  if (Aenea_model_B.Switch_n > 0) {
    // MATLAB Function: '<S552>/DEFINITIVA' incorporates:
    //   Constant: '<S4>/Constant13'
    //   Constant: '<S4>/Constant16'
    //   Inport: '<S552>/Misure'

    Aenea_model_B.aterra[0] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5];
    Aenea_model_B.aterra[1] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6];
    Aenea_model_B.aterra[2] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7];
    if (!Aenea_model_DW.x_prd_not_empty) {
      std::memset(&Aenea_model_DW.x_prd[0], 0, 18U * sizeof(real_T));
      Aenea_model_DW.x_prd_not_empty = true;
      Aenea_model_DW.x_prd[0] = Aenea_model_B.In[0];
      Aenea_model_DW.x_prd[1] = Aenea_model_B.In[1];
      Aenea_model_DW.x_prd[2] = Aenea_model_B.In[2];
      Aenea_model_DW.x_prd[3] = Aenea_model_B.In[3];
      Aenea_model_DW.x_prd[4] = Aenea_model_B.In[4];
      Aenea_model_DW.x_prd[5] = Aenea_model_B.In[5];
      std::memcpy(&Aenea_model_DW.x_prd[6], &Aenea_model_B.In[9], 12U * sizeof
                  (real_T));
      std::memset(&Aenea_model_DW.p_prd[0], 0, 324U * sizeof(real_T));
      Aenea_model_DW.p_prd[0] = 1.0E+10;
      Aenea_model_DW.p_prd[57] = 1.0E+10;
      Aenea_model_DW.p_prd[76] = 1.0E+10;
    }

    Aenea_model_B.H[3] = 0.0;
    Aenea_model_B.H[14] = 0.0;
    Aenea_model_B.H[25] = 0.0;
    Aenea_model_B.H[36] = 1.0;
    Aenea_model_B.H[47] = 0.0;
    Aenea_model_B.H[58] = 0.0;
    Aenea_model_B.H[69] = 0.0;
    Aenea_model_B.H[80] = 0.0;
    Aenea_model_B.H[91] = 0.0;
    Aenea_model_B.H[102] = (Aenea_model_B.Product1 * Aenea_model_B.Wp_selector *
      Aenea_model_B.smax + Aenea_model_B.Vec_selector * Aenea_model_B.a_c) * 0.0
      + (Aenea_model_B.Product1 * Aenea_model_B.a_c - Aenea_model_B.Wp_selector *
         Aenea_model_B.Vec_selector * Aenea_model_B.smax) * 0.0;
    Aenea_model_B.psi_ref = 0.0 * Aenea_model_B.Wp_selector *
      Aenea_model_B.Sum_fj;
    Aenea_model_B.angoloWP = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) + std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
    Aenea_model_B.H[113] = Aenea_model_B.psi_ref - Aenea_model_B.angoloWP * 0.0;
    Aenea_model_B.H[124] = (Aenea_model_B.Al_selector - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6])) * -0.0 -
      Aenea_model_B.psi_ref;
    Aenea_model_B.H[135] = 0.0;
    Aenea_model_B.H[146] = 0.0;
    Aenea_model_B.H[157] = 0.0;
    Aenea_model_B.H[168] = 0.0;
    Aenea_model_B.H[179] = 0.0;
    Aenea_model_B.H[190] = 0.0;
    Aenea_model_B.H[4] = 0.0;
    Aenea_model_B.H[15] = 0.0;
    Aenea_model_B.H[26] = 0.0;
    Aenea_model_B.H[37] = 0.0;
    Aenea_model_B.H[48] = 1.0;
    Aenea_model_B.H[59] = 0.0;
    Aenea_model_B.H[70] = 0.0;
    Aenea_model_B.H[81] = 0.0;
    Aenea_model_B.H[92] = 0.0;
    Aenea_model_B.H[103] = (Aenea_model_B.psi_ref_pre -
      Aenea_model_B.Al_selector * Aenea_model_B.smax) * -0.0 -
      (Aenea_model_B.Ato_selector * Aenea_model_B.smax +
       Aenea_model_B.Al_selector) * 0.0;
    Aenea_model_B.psi_ref = 0.0 * Aenea_model_B.Sum_fj * Aenea_model_B.a_c;
    Aenea_model_B.H[114] = (Aenea_model_B.psi_ref_pre - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6])) * 0.0 +
      Aenea_model_B.psi_ref;
    Aenea_model_B.H[125] = (std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) +
      Aenea_model_B.Al_selector) * 0.0 - Aenea_model_B.psi_ref;
    Aenea_model_B.H[136] = 0.0;
    Aenea_model_B.H[147] = 0.0;
    Aenea_model_B.H[158] = 0.0;
    Aenea_model_B.H[169] = 0.0;
    Aenea_model_B.H[180] = 0.0;
    Aenea_model_B.H[191] = 0.0;
    Aenea_model_B.H[5] = 0.0;
    Aenea_model_B.H[16] = 0.0;
    Aenea_model_B.H[27] = 0.0;
    Aenea_model_B.H[38] = 0.0;
    Aenea_model_B.H[49] = 0.0;
    Aenea_model_B.H[60] = 0.0;
    Aenea_model_B.H[71] = Aenea_model_B.Wp_selector * Aenea_model_B.Sum_fj;
    Aenea_model_B.H[82] = Aenea_model_B.Sum_fj * Aenea_model_B.a_c;
    Aenea_model_B.H[93] = -Aenea_model_B.smax;
    Aenea_model_B.H[104] = Aenea_model_DW.x_prd[10] * 0.0 +
      Aenea_model_DW.x_prd[11] * 0.0;
    Aenea_model_B.psi_ref = 2.0 * Aenea_model_DW.x_prd[10] * 0.0;
    Aenea_model_B.H[115] = Aenea_model_DW.x_prd[9] * 0.0 - Aenea_model_B.psi_ref;
    Aenea_model_B.Wp_selector = 2.0 * Aenea_model_DW.x_prd[11] * 0.0;
    Aenea_model_B.H[126] = Aenea_model_DW.x_prd[9] * 0.0 -
      Aenea_model_B.Wp_selector;
    Aenea_model_B.H[137] = 1.0;
    Aenea_model_B.H[148] = 0.0;
    Aenea_model_B.H[159] = 0.0;
    Aenea_model_B.H[170] = 0.0;
    Aenea_model_B.H[181] = 0.0;
    Aenea_model_B.H[192] = 0.0;
    Aenea_model_B.H[6] = 0.0;
    Aenea_model_B.H[17] = 0.0;
    Aenea_model_B.H[28] = 0.0;
    Aenea_model_B.H[39] = 0.0;
    Aenea_model_B.H[50] = 0.0;
    Aenea_model_B.H[61] = 0.0;
    Aenea_model_B.H[72] = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
    Aenea_model_B.H[83] = std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) + std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
    Aenea_model_B.H[94] = Aenea_model_B.Sum_fj * Aenea_model_B.Vec_selector;
    Aenea_model_B.Vec_selector = 2.0 * Aenea_model_DW.x_prd[9] * 0.0;
    Aenea_model_B.H[105] = Aenea_model_DW.x_prd[10] * 0.0 -
      Aenea_model_B.Vec_selector;
    Aenea_model_B.H[116] = Aenea_model_DW.x_prd[9] * 0.0 + Aenea_model_DW.x_prd
      [11] * 0.0;
    Aenea_model_B.H[127] = Aenea_model_DW.x_prd[10] * 0.0 -
      Aenea_model_B.Wp_selector;
    Aenea_model_B.H[138] = 0.0;
    Aenea_model_B.H[149] = 1.0;
    Aenea_model_B.H[160] = 0.0;
    Aenea_model_B.H[171] = 0.0;
    Aenea_model_B.H[182] = 0.0;
    Aenea_model_B.H[193] = 0.0;
    Aenea_model_B.H[7] = 0.0;
    Aenea_model_B.H[18] = 0.0;
    Aenea_model_B.H[29] = 0.0;
    Aenea_model_B.H[40] = 0.0;
    Aenea_model_B.H[51] = 0.0;
    Aenea_model_B.H[62] = 0.0;
    Aenea_model_B.H[73] = Aenea_model_B.angoloWP;
    Aenea_model_B.H[84] = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
    Aenea_model_B.H[95] = Aenea_model_B.Product1 * Aenea_model_B.Sum_fj;
    Aenea_model_B.H[106] = Aenea_model_DW.x_prd[11] * 0.0 -
      Aenea_model_B.Vec_selector;
    Aenea_model_B.H[117] = Aenea_model_DW.x_prd[11] * 0.0 -
      Aenea_model_B.psi_ref;
    Aenea_model_B.H[128] = Aenea_model_DW.x_prd[9] * 0.0 + Aenea_model_DW.x_prd
      [10] * 0.0;
    Aenea_model_B.H[139] = 0.0;
    Aenea_model_B.H[150] = 0.0;
    Aenea_model_B.H[161] = 1.0;
    Aenea_model_B.H[172] = 0.0;
    Aenea_model_B.H[183] = 0.0;
    Aenea_model_B.H[194] = 0.0;
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 18;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.H[11 * Aenea_model_B.tolleranza_distWP_fut] =
        b[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.H[11 * Aenea_model_B.tolleranza_distWP_fut + 1] =
        c[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.H[11 * Aenea_model_B.tolleranza_distWP_fut + 2] =
        d[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.H[11 * Aenea_model_B.tolleranza_distWP_fut + 8] =
        e[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.H[11 * Aenea_model_B.tolleranza_distWP_fut + 9] =
        f[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.H[11 * Aenea_model_B.tolleranza_distWP_fut + 10] =
        g[Aenea_model_B.tolleranza_distWP_fut];
    }

    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 11;
         Aenea_model_B.tolleranza_distWP_fut++) {
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_n = Aenea_model_B.tolleranza_distWP_fut + 11 *
          Aenea_model_B.caso;
        Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_n] = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 18; Aenea_model_B.i++) {
          Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_n] += Aenea_model_B.H[11
            * Aenea_model_B.i + Aenea_model_B.tolleranza_distWP_fut] *
            Aenea_model_DW.p_prd[18 * Aenea_model_B.caso + Aenea_model_B.i];
        }
      }

      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_n = Aenea_model_B.tolleranza_distWP_fut + 11 *
          Aenea_model_B.caso;
        Aenea_model_B.S[Aenea_model_B.Switch_n] = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 18; Aenea_model_B.i++) {
          Aenea_model_B.S[Aenea_model_B.Switch_n] += Aenea_model_B.klm_gain_m[11
            * Aenea_model_B.i + Aenea_model_B.tolleranza_distWP_fut] *
            Aenea_model_B.H[11 * Aenea_model_B.i + Aenea_model_B.caso];
        }
      }
    }

    Ap_sel = (rtb_y_e && rtb_y_b);
    if (Ap_sel && rtb_y_p) {
      for (Aenea_model_B.tolleranza_distWP_fut = 0;
           Aenea_model_B.tolleranza_distWP_fut < 11;
           Aenea_model_B.tolleranza_distWP_fut++) {
        Aenea_model_B.Switch_n = 11 * Aenea_model_B.tolleranza_distWP_fut +
          Aenea_model_B.tolleranza_distWP_fut;
        Aenea_model_B.S[Aenea_model_B.Switch_n] +=
          Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
      }
    } else {
      tmp = !rtb_y_e;
      tmp_0 = (tmp && rtb_y_b);
      if (tmp_0 && rtb_y_p) {
        for (Aenea_model_B.tolleranza_distWP_fut = 0;
             Aenea_model_B.tolleranza_distWP_fut < 11;
             Aenea_model_B.tolleranza_distWP_fut++) {
          if ((Aenea_model_B.tolleranza_distWP_fut + 1 == 1) ||
              (Aenea_model_B.tolleranza_distWP_fut + 1 == 2)) {
            Aenea_model_B.Switch_n = 11 * Aenea_model_B.tolleranza_distWP_fut +
              Aenea_model_B.tolleranza_distWP_fut;
            Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
          } else {
            Aenea_model_B.Switch_n = 11 * Aenea_model_B.tolleranza_distWP_fut +
              Aenea_model_B.tolleranza_distWP_fut;
            Aenea_model_B.S[Aenea_model_B.Switch_n] +=
              Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
          }
        }
      } else {
        rtb_y_b = !rtb_y_b;
        rtb_y_e = (rtb_y_e && rtb_y_b);
        if (rtb_y_e && rtb_y_p) {
          for (Aenea_model_B.tolleranza_distWP_fut = 0;
               Aenea_model_B.tolleranza_distWP_fut < 11;
               Aenea_model_B.tolleranza_distWP_fut++) {
            if ((Aenea_model_B.tolleranza_distWP_fut + 1 == 4) ||
                (Aenea_model_B.tolleranza_distWP_fut + 1 == 5)) {
              Aenea_model_B.Switch_n = 11 * Aenea_model_B.tolleranza_distWP_fut
                + Aenea_model_B.tolleranza_distWP_fut;
              Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
            } else {
              Aenea_model_B.Switch_n = 11 * Aenea_model_B.tolleranza_distWP_fut
                + Aenea_model_B.tolleranza_distWP_fut;
              Aenea_model_B.S[Aenea_model_B.Switch_n] +=
                Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
            }
          }
        } else {
          tmp = (tmp && rtb_y_b);
          if (tmp && rtb_y_p) {
            for (Aenea_model_B.tolleranza_distWP_fut = 0;
                 Aenea_model_B.tolleranza_distWP_fut < 11;
                 Aenea_model_B.tolleranza_distWP_fut++) {
              if ((Aenea_model_B.tolleranza_distWP_fut + 1 == 1) ||
                  (Aenea_model_B.tolleranza_distWP_fut + 1 == 2) ||
                  (Aenea_model_B.tolleranza_distWP_fut + 1 == 4) ||
                  (Aenea_model_B.tolleranza_distWP_fut + 1 == 5)) {
                Aenea_model_B.Switch_n = 11 *
                  Aenea_model_B.tolleranza_distWP_fut +
                  Aenea_model_B.tolleranza_distWP_fut;
                Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
              } else {
                Aenea_model_B.Switch_n = 11 *
                  Aenea_model_B.tolleranza_distWP_fut +
                  Aenea_model_B.tolleranza_distWP_fut;
                Aenea_model_B.S[Aenea_model_B.Switch_n] +=
                  Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
              }
            }
          } else {
            rtb_y_b = !rtb_y_p;
            if (Ap_sel && rtb_y_b) {
              for (Aenea_model_B.tolleranza_distWP_fut = 0;
                   Aenea_model_B.tolleranza_distWP_fut < 11;
                   Aenea_model_B.tolleranza_distWP_fut++) {
                if ((Aenea_model_B.tolleranza_distWP_fut + 1 == 1) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 2) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 4) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 5) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 3)) {
                  Aenea_model_B.Switch_n = 11 *
                    Aenea_model_B.tolleranza_distWP_fut +
                    Aenea_model_B.tolleranza_distWP_fut;
                  Aenea_model_B.S[Aenea_model_B.Switch_n] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
                } else {
                  Aenea_model_B.Switch_n = 11 *
                    Aenea_model_B.tolleranza_distWP_fut +
                    Aenea_model_B.tolleranza_distWP_fut;
                  Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
                }
              }
            } else if (tmp_0 && rtb_y_b) {
              for (Aenea_model_B.tolleranza_distWP_fut = 0;
                   Aenea_model_B.tolleranza_distWP_fut < 11;
                   Aenea_model_B.tolleranza_distWP_fut++) {
                if ((Aenea_model_B.tolleranza_distWP_fut + 1 == 4) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 5) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 3)) {
                  Aenea_model_B.Switch_n = 11 *
                    Aenea_model_B.tolleranza_distWP_fut +
                    Aenea_model_B.tolleranza_distWP_fut;
                  Aenea_model_B.S[Aenea_model_B.Switch_n] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
                } else {
                  Aenea_model_B.Switch_n = 11 *
                    Aenea_model_B.tolleranza_distWP_fut +
                    Aenea_model_B.tolleranza_distWP_fut;
                  Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
                }
              }
            } else if (rtb_y_e && rtb_y_b) {
              for (Aenea_model_B.tolleranza_distWP_fut = 0;
                   Aenea_model_B.tolleranza_distWP_fut < 11;
                   Aenea_model_B.tolleranza_distWP_fut++) {
                if ((Aenea_model_B.tolleranza_distWP_fut + 1 == 1) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 2) ||
                    (Aenea_model_B.tolleranza_distWP_fut + 1 == 3)) {
                  Aenea_model_B.Switch_n = 11 *
                    Aenea_model_B.tolleranza_distWP_fut +
                    Aenea_model_B.tolleranza_distWP_fut;
                  Aenea_model_B.S[Aenea_model_B.Switch_n] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
                } else {
                  Aenea_model_B.Switch_n = 11 *
                    Aenea_model_B.tolleranza_distWP_fut +
                    Aenea_model_B.tolleranza_distWP_fut;
                  Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
                }
              }
            } else {
              if (tmp && rtb_y_b) {
                for (Aenea_model_B.tolleranza_distWP_fut = 0;
                     Aenea_model_B.tolleranza_distWP_fut < 11;
                     Aenea_model_B.tolleranza_distWP_fut++) {
                  if (Aenea_model_B.tolleranza_distWP_fut + 1 == 3) {
                    Aenea_model_B.Switch_n = 11 *
                      Aenea_model_B.tolleranza_distWP_fut +
                      Aenea_model_B.tolleranza_distWP_fut;
                    Aenea_model_B.S[Aenea_model_B.Switch_n] +=
                      Aenea_model_ConstP.Constant13_Value[Aenea_model_B.tolleranza_distWP_fut];
                  } else {
                    Aenea_model_B.Switch_n = 11 *
                      Aenea_model_B.tolleranza_distWP_fut +
                      Aenea_model_B.tolleranza_distWP_fut;
                    Aenea_model_B.S[Aenea_model_B.Switch_n] += 1.0E+40;
                  }
                }
              }
            }
          }
        }
      }
    }

    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 11;
         Aenea_model_B.tolleranza_distWP_fut++) {
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_n = Aenea_model_B.tolleranza_distWP_fut + 11 *
          Aenea_model_B.caso;
        Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_n] = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 18; Aenea_model_B.i++) {
          Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_n] += Aenea_model_B.H[11
            * Aenea_model_B.i + Aenea_model_B.tolleranza_distWP_fut] *
            Aenea_model_DW.p_prd[18 * Aenea_model_B.i + Aenea_model_B.caso];
        }
      }
    }

    Aenea_model_mldivide(Aenea_model_B.S, Aenea_model_B.klm_gain_m,
                         Aenea_model_B.ab);
    Aenea_model_B.residui[0] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[0];
    Aenea_model_B.residui[1] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[1];
    Aenea_model_B.residui[2] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[2];
    Aenea_model_B.residui[3] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[3];
    Aenea_model_B.residui[4] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[4];
    Aenea_model_B.residui[5] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[8];
    Aenea_model_B.residui[6] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[9];
    Aenea_model_B.residui[7] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[10];
    Aenea_model_B.residui[8] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[11];
    Aenea_model_B.residui[9] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[12];
    Aenea_model_B.residui[10] = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[13];
    Aenea_model_measure_F1B(Aenea_model_DW.x_prd, Aenea_model_B.aterra, 0.0, 0.0,
      0.0, 9.81, Aenea_model_B.dv1);
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 11;
         Aenea_model_B.tolleranza_distWP_fut++) {
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.klm_gain_m[Aenea_model_B.caso + 18 *
          Aenea_model_B.tolleranza_distWP_fut] = Aenea_model_B.ab[11 *
          Aenea_model_B.caso + Aenea_model_B.tolleranza_distWP_fut];
      }

      Aenea_model_B.residui[Aenea_model_B.tolleranza_distWP_fut] -=
        Aenea_model_B.dv1[Aenea_model_B.tolleranza_distWP_fut];
    }

    Aenea_model_B.F[0] = 1.0;
    Aenea_model_B.F[18] = 0.0;
    Aenea_model_B.F[72] = 0.0;
    Aenea_model_B.F[90] = 0.0;
    Aenea_model_B.F[108] = 0.0;
    Aenea_model_B.F[126] = 0.0;
    Aenea_model_B.F[144] = 0.0;
    Aenea_model_B.F[162] = 0.0;
    Aenea_model_B.F[180] = 0.0;
    Aenea_model_B.F[198] = 0.0;
    Aenea_model_B.F[216] = 0.0;
    Aenea_model_B.F[234] = 0.0;
    Aenea_model_B.F[252] = 0.0;
    Aenea_model_B.F[270] = 0.0;
    Aenea_model_B.F[288] = 0.0;
    Aenea_model_B.F[306] = 0.0;
    Aenea_model_B.F[19] = 1.0;
    Aenea_model_B.F[55] = 0.0;
    Aenea_model_B.F[91] = 0.0;
    Aenea_model_B.F[109] = 0.0;
    Aenea_model_B.F[127] = 0.0;
    Aenea_model_B.F[145] = 0.0;
    Aenea_model_B.F[163] = 0.0;
    Aenea_model_B.F[181] = 0.0;
    Aenea_model_B.F[199] = 0.0;
    Aenea_model_B.F[217] = 0.0;
    Aenea_model_B.F[235] = 0.0;
    Aenea_model_B.F[253] = 0.0;
    Aenea_model_B.F[271] = 0.0;
    Aenea_model_B.F[289] = 0.0;
    Aenea_model_B.F[307] = 0.0;
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 18;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.klm_gain_c[Aenea_model_B.tolleranza_distWP_fut] = 0.0;
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11; Aenea_model_B.caso++)
      {
        Aenea_model_B.klm_gain_c[Aenea_model_B.tolleranza_distWP_fut] +=
          Aenea_model_B.klm_gain_m[18 * Aenea_model_B.caso +
          Aenea_model_B.tolleranza_distWP_fut] *
          Aenea_model_B.residui[Aenea_model_B.caso];
      }

      Aenea_model_B.x_est[Aenea_model_B.tolleranza_distWP_fut] =
        Aenea_model_DW.x_prd[Aenea_model_B.tolleranza_distWP_fut] +
        Aenea_model_B.klm_gain_c[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 2] =
        h[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 3] =
        j_0[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 4] =
        l[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 5] =
        m[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 6] =
        n[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 7] =
        o[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 8] =
        p[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 9] =
        q[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 10] =
        r[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 11] =
        s[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 12] =
        t[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 13] =
        u[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 14] =
        v[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 15] =
        w[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 16] =
        x[Aenea_model_B.tolleranza_distWP_fut];
      Aenea_model_B.F[18 * Aenea_model_B.tolleranza_distWP_fut + 17] =
        y[Aenea_model_B.tolleranza_distWP_fut];
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_n = Aenea_model_B.tolleranza_distWP_fut + 18 *
          Aenea_model_B.caso;
        Aenea_model_B.klm_gain[Aenea_model_B.Switch_n] = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 11; Aenea_model_B.i++) {
          Aenea_model_B.klm_gain[Aenea_model_B.Switch_n] +=
            Aenea_model_B.klm_gain_m[18 * Aenea_model_B.i +
            Aenea_model_B.tolleranza_distWP_fut] * Aenea_model_B.H[11 *
            Aenea_model_B.caso + Aenea_model_B.i];
        }
      }

      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.smax = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 18; Aenea_model_B.i++) {
          Aenea_model_B.smax += Aenea_model_B.klm_gain[18 * Aenea_model_B.i +
            Aenea_model_B.tolleranza_distWP_fut] * Aenea_model_DW.p_prd[18 *
            Aenea_model_B.caso + Aenea_model_B.i];
        }

        Aenea_model_B.i = 18 * Aenea_model_B.caso +
          Aenea_model_B.tolleranza_distWP_fut;
        Aenea_model_B.dv[Aenea_model_B.i] = Aenea_model_DW.p_prd[Aenea_model_B.i]
          - Aenea_model_B.smax;
      }
    }

    Aenea_model_B.angoloWP = std::cos(Aenea_model_B.x_est[0]);
    Aenea_model_B.Product1 = (Aenea_model_B.x_est[2] + 6.378137E+6) *
      (Aenea_model_B.x_est[2] + 6.378137E+6);
    Aenea_model_B.F[36] = -(0.02 * Aenea_model_B.x_est[3]) /
      Aenea_model_B.Product1;
    Aenea_model_B.F[54] = 0.02 / (Aenea_model_B.x_est[2] + 6.378137E+6);
    Aenea_model_B.F[1] = 0.02 * Aenea_model_B.x_est[4] * std::sin
      (Aenea_model_B.x_est[0]) / (Aenea_model_B.angoloWP *
      Aenea_model_B.angoloWP * (Aenea_model_B.x_est[2] + 6.378137E+6));
    Aenea_model_B.F[37] = -(0.02 * Aenea_model_B.x_est[4]) /
      (Aenea_model_B.Product1 * Aenea_model_B.angoloWP);
    Aenea_model_B.F[73] = 0.02 / ((Aenea_model_B.x_est[2] + 6.378137E+6) *
      Aenea_model_B.angoloWP);
    Aenea_model_f_pred_F1B(Aenea_model_B.x_est, 6.378137E+6, 0.02,
      Aenea_model_DW.x_prd);
    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 18;
         Aenea_model_B.tolleranza_distWP_fut++) {
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_n = Aenea_model_B.tolleranza_distWP_fut + 18 *
          Aenea_model_B.caso;
        Aenea_model_B.klm_gain[Aenea_model_B.Switch_n] = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 18; Aenea_model_B.i++) {
          Aenea_model_B.klm_gain[Aenea_model_B.Switch_n] += Aenea_model_B.F[18 *
            Aenea_model_B.i + Aenea_model_B.tolleranza_distWP_fut] *
            Aenea_model_B.dv[18 * Aenea_model_B.caso + Aenea_model_B.i];
        }
      }

      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_n = Aenea_model_B.tolleranza_distWP_fut + 18 *
          Aenea_model_B.caso;
        Aenea_model_DW.p_prd[Aenea_model_B.Switch_n] = 0.0;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 18; Aenea_model_B.i++) {
          Aenea_model_DW.p_prd[Aenea_model_B.Switch_n] +=
            Aenea_model_B.klm_gain[18 * Aenea_model_B.i +
            Aenea_model_B.tolleranza_distWP_fut] * Aenea_model_B.F[18 *
            Aenea_model_B.i + Aenea_model_B.caso];
        }
      }
    }

    for (Aenea_model_B.tolleranza_distWP_fut = 0;
         Aenea_model_B.tolleranza_distWP_fut < 18;
         Aenea_model_B.tolleranza_distWP_fut++) {
      Aenea_model_B.Switch_n = 18 * Aenea_model_B.tolleranza_distWP_fut +
        Aenea_model_B.tolleranza_distWP_fut;
      Aenea_model_DW.p_prd[Aenea_model_B.Switch_n] +=
        Aenea_model_ConstP.Constant16_Value[Aenea_model_B.tolleranza_distWP_fut];
    }

    Aenea_model_B.Lat_K = Aenea_model_B.x_est[0];
    Aenea_model_B.Long_K = Aenea_model_B.x_est[1];
    Aenea_model_B.h_K = Aenea_model_B.x_est[2];
    Aenea_model_B.v_K = std::sqrt(Aenea_model_B.x_est[3] * Aenea_model_B.x_est[3]
      + Aenea_model_B.x_est[4] * Aenea_model_B.x_est[4]);
  }

  // End of Outputs for SubSystem: '<S4>/Filter2'

  // DataTypeConversion: '<S566>/Data Type Conversion1' incorporates:
  //   UnitDelay: '<S566>/Unit Delay'

  for (Aenea_model_B.i = 0; Aenea_model_B.i < 9; Aenea_model_B.i++) {
    Aenea_model_DW.UnitDelay_DSTATE[Aenea_model_B.i] =
      Aenea_model_B.ByteReversal[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S566>/Data Type Conversion1'

  // Outputs for Resettable SubSystem: '<S406>/Resettable Subsystem'
  Aenea_model_ResettableSubsystem(0, &Aenea_model_B.Wp_selector,
    &Aenea_model_DW.ResettableSubsystem_j,
    &Aenea_model_PrevZCX.ResettableSubsystem_j);

  // End of Outputs for SubSystem: '<S406>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S406>/Enabled Subsystem'
  Aenea_model_EnabledSubsystem(0, Aenea_model_B.Wp_selector,
    &Aenea_model_B.Switch_a);

  // End of Outputs for SubSystem: '<S406>/Enabled Subsystem'

  // Product: '<S554>/Product1' incorporates:
  //   Constant: '<S4>/tas'
  //   MATLAB Function: '<S554>/MATLAB Function'
  //   Sum: '<S554>/Sum'
  //   UnitDelay: '<S554>/Unit Delay'

  Aenea_model_B.Product1 = (Aenea_model_DW.UnitDelay_DSTATE_c + 1.0) *
    0.38271604938271603;

  // MATLAB Function: '<S412>/MATLAB Function1'
  guard1 = false;
  if (Aenea_model_DW.Memory2_PreviousInput_d[1] == 1) {
    // Switch: '<S33>/Switch' incorporates:
    //   Constant: '<S33>/Constant'

    if (Aenea_model_B.Switch_a != 0.0) {
      Aenea_model_B.smax = 50.0;
    } else {
      Aenea_model_B.smax = Aenea_model_B.Product1;
    }

    // End of Switch: '<S33>/Switch'
    if (Aenea_model_B.smax > 40.0) {
      Aenea_model_DW.alarm = 1.0;
    } else if (std::abs(0.017453292519943295 *
                        Aenea_model_B.DataTypeConversion1[6] *
                        57.295779513082323) > 55.0) {
      Aenea_model_DW.alarm = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) {
      Aenea_model_DW.alarm = 0.0;
    }
  }

  // Outputs for Resettable SubSystem: '<S429>/Resettable Subsystem' incorporates:
  //   ResetPort: '<S432>/Reset'

  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &Aenea_model_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (Aenea_model_DW.alarm)) != NO_ZCEVENT) {
    // InitializeConditions for Memory: '<S433>/Memory'
    Aenea_model_DW.Memory_PreviousInput_n = 0.0;
  }

  // Sum: '<S433>/Sum' incorporates:
  //   Constant: '<S433>/Constant4'
  //   Memory: '<S433>/Memory'

  Aenea_model_B.Sum_fj = Aenea_model_DW.Memory_PreviousInput_n + 0.02;

  // Update for Memory: '<S433>/Memory' incorporates:
  //   Constant: '<S433>/Constant4'
  //   Sum: '<S433>/Sum'

  Aenea_model_DW.Memory_PreviousInput_n += 0.02;

  // End of Outputs for SubSystem: '<S429>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S429>/Enabled ' incorporates:
  //   EnablePort: '<S431>/Enable'

  // MATLAB Function: '<S412>/MATLAB Function1'
  if (Aenea_model_DW.alarm > 0.0) {
    Aenea_model_DW.Enabled_MODE = true;

    // Switch: '<S431>/Switch'
    Aenea_model_B.Switch = (Aenea_model_B.Sum_fj > 1.0);
  } else {
    if (Aenea_model_DW.Enabled_MODE) {
      // Disable for Switch: '<S431>/Switch' incorporates:
      //   Outport: '<S431>/Alarm Safe'

      Aenea_model_B.Switch = 0.0;
      Aenea_model_DW.Enabled_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S429>/Enabled '

  // Chart: '<S33>/ STATI' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  if (Aenea_model_DW.is_active_c26_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c26_Aenea_model = 1U;
    Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_MANUALE;
  } else {
    switch (Aenea_model_DW.is_c26_Aenea_model) {
     case Aenea_model_IN_AUTOMATICA:
      if (Aenea_model_B.Switch == 1.0) {
        Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_NO_ACTIVE_CHILD;
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_Safe;
      } else if (Aenea_model_ConstB.Go_Home == 1.0) {
        Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_NO_ACTIVE_CHILD;
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_Go_Home;
      } else if (Aenea_model_DW.Memory2_PreviousInput_d[1] == 0) {
        Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_NO_ACTIVE_CHILD;
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_Stand_By;
      } else if (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) {
        Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_NO_ACTIVE_CHILD;
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_MANUALE;
      } else {
        switch (Aenea_model_DW.is_AUTOMATICA) {
         case Aenea_IN_ATTERRAGGIO_AUTOMATICO:
          if ((Aenea_model_DW.Memory2_PreviousInput_d[8] == 0) &&
              (Aenea_model_B.h_K > 20.0) &&
              (Aenea_model_DW.Memory2_PreviousInput_d[6] == 1)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_WAYPOINT;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[8] == 0) &&
                     (Aenea_model_B.h_K > 20.0)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[7] == 1) &&
                     (Aenea_model_DW.Memory2_PreviousInput_d[8] == 0) &&
                     (Aenea_model_B.h_K < 1.0) && (Aenea_model_B.v_K < 1.0)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_mod_IN_DECOLLO_AUTOMATICO;
          } else {
            Aenea_model_B.modo = 4.0;
            Aenea_model_B.switch_manetta = 1.0;
            Aenea_model_B.switch_equilibratore = 1.0;
            Aenea_model_B.switch_alettoni = 1.0;
            Aenea_model_B.switch_timone = 1.0;
          }
          break;

         case Aenea_mod_IN_DECOLLO_AUTOMATICO:
          if ((Aenea_model_DW.Memory2_PreviousInput_d[7] == 0) &&
              (Aenea_model_B.Product1 >= 1.0) &&
              ((Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[2] == 1))) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[6] == 1) &&
                     (Aenea_model_B.h_K > 30.0)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_WAYPOINT;
          } else {
            Aenea_model_B.modo = 3.0;
            Aenea_model_B.switch_manetta = 1.0;
            Aenea_model_B.switch_equilibratore = 1.0;
            Aenea_model_B.switch_alettoni = 1.0;
            Aenea_model_B.switch_timone = 1.0;
          }
          break;

         case Aenea_model_IN_TEST:
          if (Aenea_model_DW.test1 == 0.0) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
          } else {
            Aenea_model_B.switch_manetta = 0.0;
            Aenea_model_B.switch_equilibratore = 0.0;
            Aenea_model_B.switch_alettoni = 0.0;
            Aenea_model_B.switch_timone = 0.0;
          }
          break;

         case Aenea_model_IN_VETTORIALE:
          if (Aenea_model_DW.test1 == 1.0) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_TEST;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[7] == 1) &&
                     (Aenea_model_B.v_K < 1.0)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_mod_IN_DECOLLO_AUTOMATICO;
          } else if (Aenea_model_DW.Memory2_PreviousInput_d[8] == 1) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_IN_ATTERRAGGIO_AUTOMATICO;
          } else if (Aenea_model_DW.Memory2_PreviousInput_d[6] == 1) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_WAYPOINT;
          } else {
            Aenea_model_B.modo = 2.0;
            Aenea_model_B.switch_manetta = 1.0;
            Aenea_model_B.switch_equilibratore = 1.0;
            Aenea_model_B.switch_alettoni = 1.0;
            Aenea_model_B.switch_timone = 1.0;
          }
          break;

         default:
          // case IN_WAYPOINT:
          if ((Aenea_model_DW.Memory2_PreviousInput_d[6] == 0) &&
              ((Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[2] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[7] == 1))) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
          } else if (Aenea_model_DW.Memory2_PreviousInput_d[8] == 1) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_IN_ATTERRAGGIO_AUTOMATICO;
          } else {
            Aenea_model_B.modo = 1.0;
            Aenea_model_B.switch_manetta = 1.0;
            Aenea_model_B.switch_equilibratore = 1.0;
            Aenea_model_B.switch_alettoni = 1.0;
            Aenea_model_B.switch_timone = 1.0;
          }
          break;
        }
      }
      break;

     case Aenea_model_IN_Go_Home:
      if ((Aenea_model_ConstB.Go_Home == 0.0) &&
          ((Aenea_model_DW.Memory2_PreviousInput_d[6] == 1) ||
           (Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) ||
           (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) ||
           (Aenea_model_DW.Memory2_PreviousInput_d[2] == 1) ||
           (Aenea_model_DW.Memory2_PreviousInput_d[8] == 1))) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_AUTOMATICA;
        Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
      } else if (Aenea_model_B.Switch == 1.0) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_Safe;
      } else {
        Aenea_model_B.modo = 5.0;
        Aenea_model_B.switch_manetta = 1.0;
        Aenea_model_B.switch_equilibratore = 1.0;
        Aenea_model_B.switch_alettoni = 1.0;
        Aenea_model_B.switch_timone = 1.0;
      }
      break;

     case Aenea_mode_IN_Intervento_Pilota:
      if (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_MANUALE;
      } else {
        Aenea_model_B.switch_manetta = 0.0;
        Aenea_model_B.switch_equilibratore = 0.0;
        Aenea_model_B.switch_alettoni = 0.0;
        Aenea_model_B.switch_timone = 0.0;
      }
      break;

     case Aenea_model_IN_MANUALE:
      if ((Aenea_model_ConstB.Go_Home == 1.0) && (Aenea_model_B.Switch == 0.0))
      {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_Go_Home;
      } else if (Aenea_model_DW.Memory2_PreviousInput_d[0] == 0) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_Stand_By;
      } else {
        Aenea_model_B.switch_manetta = 0.0;
        Aenea_model_B.switch_equilibratore = 0.0;
        Aenea_model_B.switch_alettoni = 0.0;
        Aenea_model_B.switch_timone = 0.0;
      }
      break;

     case Aenea_model_IN_Safe:
      if (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_MANUALE;
      } else {
        Aenea_model_B.switch_manetta = 1.0;
        Aenea_model_B.switch_equilibratore = 1.0;
        Aenea_model_B.switch_alettoni = 1.0;
        Aenea_model_B.switch_timone = 1.0;
        Aenea_model_B.throttle_safe = 0.1;
      }
      break;

     default:
      // case IN_Stand_By:
      if (Aenea_model_DW.Memory2_PreviousInput_d[1] == 1) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_AUTOMATICA;
        Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
      } else if (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) {
        Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_MANUALE;
      } else {
        Aenea_model_B.switch_manetta = 0.0;
        Aenea_model_B.switch_equilibratore = 0.0;
        Aenea_model_B.switch_alettoni = 0.0;
        Aenea_model_B.switch_timone = 0.0;
      }
      break;
    }
  }

  // End of Chart: '<S33>/ STATI'

  // Logic: '<S34>/AND'
  Ap_sel = ((Aenea_model_B.switch_manetta != 0.0) &&
            (Aenea_model_B.switch_equilibratore != 0.0) &&
            (Aenea_model_B.switch_alettoni != 0.0) &&
            (Aenea_model_B.switch_timone != 0.0));

  // Chart: '<S34>/Chart' incorporates:
  //   Logic: '<S34>/AND'

  if (Aenea_model_DW.is_active_c21_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c21_Aenea_model = 1U;
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
    Aenea_model_B.Wp_selector = 0.0;
    Aenea_model_B.Vec_selector = 0.0;
    Aenea_model_B.Ato_selector = 0.0;
    Aenea_model_B.Al_selector = 0.0;
    Aenea_model_B.Sum_fj = 0.0;
  } else {
    switch (Aenea_model_DW.is_c21_Aenea_model) {
     case Aenea_model_IN_AutoLanding:
      if ((!(Aenea_model_B.switch_manetta != 0.0)) ||
          (!(Aenea_model_B.switch_equilibratore != 0.0)) ||
          (!(Aenea_model_B.switch_alettoni != 0.0)) ||
          (!(Aenea_model_B.switch_timone != 0.0))) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 2.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Vettoriale;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 1.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 1.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
        Aenea_model_B.Wp_selector = 1.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 5.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_GoHome;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 1.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 1.0;
        Aenea_model_B.Sum_fj = 0.0;
      }
      break;

     case Aenea_model_IN_AutoTakeoff:
      if ((!(Aenea_model_B.switch_manetta != 0.0)) ||
          (!(Aenea_model_B.switch_equilibratore != 0.0)) ||
          (!(Aenea_model_B.switch_alettoni != 0.0)) ||
          (!(Aenea_model_B.switch_timone != 0.0))) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 1.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
        Aenea_model_B.Wp_selector = 1.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 2.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Vettoriale;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 1.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 1.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      }
      break;

     case Aenea_model_IN_GoHome:
      if ((!(Aenea_model_B.switch_manetta != 0.0)) ||
          (!(Aenea_model_B.switch_equilibratore != 0.0)) ||
          (!(Aenea_model_B.switch_alettoni != 0.0)) ||
          (!(Aenea_model_B.switch_timone != 0.0))) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 1.0;
      }
      break;

     case Aenea_model_IN_In:
      Aenea_model_In(&Ap_sel, &Aenea_model_B.Wp_selector,
                     &Aenea_model_B.Vec_selector, &Aenea_model_B.Ato_selector,
                     &Aenea_model_B.Al_selector, &Aenea_model_B.Sum_fj);
      break;

     case Aenea_model_IN_Vettoriale:
      if ((!(Aenea_model_B.switch_manetta != 0.0)) ||
          (!(Aenea_model_B.switch_equilibratore != 0.0)) ||
          (!(Aenea_model_B.switch_alettoni != 0.0)) ||
          (!(Aenea_model_B.switch_timone != 0.0))) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 1.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
        Aenea_model_B.Wp_selector = 1.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else if (Aenea_model_B.modo == 5.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_GoHome;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 1.0;
      } else if (Aenea_model_B.modo == 4.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_AutoLanding;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 1.0;
        Aenea_model_B.Sum_fj = 0.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 1.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Sum_fj = 0.0;
      }
      break;

     default:
      // case IN_Waypoint:
      Aenea_model_Waypoint(&Ap_sel, &Aenea_model_B.Wp_selector,
                           &Aenea_model_B.Vec_selector,
                           &Aenea_model_B.Ato_selector,
                           &Aenea_model_B.Al_selector, &Aenea_model_B.Sum_fj);
      break;
    }
  }

  // End of Chart: '<S34>/Chart'

  // Outputs for Enabled SubSystem: '<S34>/Subsystem2' incorporates:
  //   EnablePort: '<S438>/Enable'

  if (Aenea_model_B.Wp_selector > 0.0) {
    // Gain: '<S539>/Gain'
    Aenea_model_B.Gain_m5 = 57.295779513082323 * Aenea_model_B.Lat_K;

    // Gain: '<S540>/Gain'
    Aenea_model_B.Gain_ll = 57.295779513082323 * Aenea_model_B.Long_K;

    // MATLAB Function: '<S438>/WAYPOINTS' incorporates:
    //   DataTypeConversion: '<S1>/Data Tversion'
    //   Memory: '<S438>/Memory4'

    Aenea_model_B.Switch_n = 1;
    if (Aenea_model_DW.Memory4_PreviousInput == 6.0) {
      Aenea_model_B.Switch_n = 0;
    }

    Aenea_model_B.QUOTA = Aenea_model_B.WP_db_param[static_cast<int32_T>
      (Aenea_model_DW.Memory4_PreviousInput) + 35];
    Aenea_model_B.Wp_selector = Aenea_model_B.WP_db_param[static_cast<int32_T>
      (Aenea_model_DW.Memory4_PreviousInput) + 23];
    Aenea_model_B.a_c = std::sin((Aenea_model_B.Wp_selector -
      Aenea_model_B.Gain_m5) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.smax = Aenea_model_B.WP_db_param[static_cast<int32_T>
      (Aenea_model_DW.Memory4_PreviousInput) + 29];
    Aenea_model_B.dist = std::sin((Aenea_model_B.smax - Aenea_model_B.Gain_ll) *
      3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.psi_ref = Aenea_model_B.Wp_selector * 3.1415926535897931 /
      180.0;
    Aenea_model_B.angoloWP = std::cos(Aenea_model_B.psi_ref);
    Aenea_model_B.psi_ref_pre = std::cos(Aenea_model_B.Gain_m5 *
      3.1415926535897931 / 180.0);
    Aenea_model_B.a_c = Aenea_model_B.psi_ref_pre * Aenea_model_B.angoloWP *
      (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_c *
      Aenea_model_B.a_c;
    Aenea_model_B.a_c = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_c), std::sqrt
      (1.0 - Aenea_model_B.a_c)) * 2.0 * 6.378137E+6;
    if (Aenea_model_DW.Memory4_PreviousInput > 1.0) {
      Aenea_model_B.psi_ref_tmp_tmp_tmp = Aenea_model_B.WP_db_param
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23];
      Aenea_model_B.psi_ref = Aenea_model_B.psi_ref_tmp_tmp_tmp *
        3.1415926535897931 / 180.0;
      Aenea_model_B.dist = std::cos(Aenea_model_B.psi_ref);
      Aenea_model_B.psi_ref_tmp_tmp = Aenea_model_B.WP_db_param
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 29];
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.smax -
        Aenea_model_B.psi_ref_tmp_tmp) * 3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref = rt_atan2d_snf(std::sin(Aenea_model_B.psi_ref_tmp) *
        Aenea_model_B.angoloWP, std::sin(Aenea_model_B.WP_db_param
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 23] *
        3.1415926535897931 / 180.0) * Aenea_model_B.dist - std::sin
        (Aenea_model_B.psi_ref) * Aenea_model_B.angoloWP * std::cos
        (Aenea_model_B.psi_ref_tmp)) * 180.0 / 3.1415926535897931;
      Aenea_model_B.psi_ref_tmp = std::sin((Aenea_model_B.Gain_m5 -
        Aenea_model_B.psi_ref_tmp_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.psi_ref_tmp_tmp = std::sin((Aenea_model_B.Gain_ll -
        Aenea_model_B.psi_ref_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.dist = Aenea_model_B.dist * Aenea_model_B.psi_ref_pre *
        (Aenea_model_B.psi_ref_tmp_tmp * Aenea_model_B.psi_ref_tmp_tmp) +
        Aenea_model_B.psi_ref_tmp * Aenea_model_B.psi_ref_tmp;
      Aenea_model_B.dist = rt_atan2d_snf(std::sqrt(Aenea_model_B.dist), std::
        sqrt(1.0 - Aenea_model_B.dist)) * 2.0 * 6.378137E+6;
    } else {
      Aenea_model_B.dist = (Aenea_model_B.smax - Aenea_model_DW.long1) *
        3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_tmp = Aenea_model_DW.lat1 * 3.1415926535897931 /
        180.0;
      Aenea_model_B.psi_ref = rt_atan2d_snf(std::sin(Aenea_model_B.dist) *
        Aenea_model_B.angoloWP, std::sin(Aenea_model_B.psi_ref) * std::cos
        (Aenea_model_B.psi_ref_tmp) - std::cos(Aenea_model_B.dist) * (std::sin
        (Aenea_model_B.psi_ref_tmp) * Aenea_model_B.angoloWP)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.dist = 0.0;
    }

    if (Aenea_model_B.psi_ref < 0.0) {
      Aenea_model_B.psi_ref = 360.0 - std::abs(Aenea_model_B.psi_ref);
    }

    if (Aenea_model_B.Switch_n == 1) {
      Aenea_model_B.psi_ref_tmp_tmp_tmp = Aenea_model_B.WP_db_param[static_cast<
        int32_T>(Aenea_model_DW.Memory4_PreviousInput + 1.0) + 23];
      Aenea_model_B.psi_ref_tmp = std::sin((Aenea_model_B.psi_ref_tmp_tmp_tmp -
        Aenea_model_B.Wp_selector) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.psi_ref_tmp_tmp = (Aenea_model_B.WP_db_param
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput + 1.0) + 29]
        - Aenea_model_B.smax) * 3.1415926535897931 / 180.0;
      Aenea_model_B.Gain_ll = std::sin(Aenea_model_B.psi_ref_tmp_tmp / 2.0);
      Aenea_model_B.psi_ref_tmp_tmp_tmp = Aenea_model_B.psi_ref_tmp_tmp_tmp *
        3.1415926535897931 / 180.0;
      Aenea_model_B.Gain_m5 = std::cos(Aenea_model_B.psi_ref_tmp_tmp_tmp);
      Aenea_model_B.Gain_ll = Aenea_model_B.angoloWP * Aenea_model_B.Gain_m5 *
        (Aenea_model_B.Gain_ll * Aenea_model_B.Gain_ll) +
        Aenea_model_B.psi_ref_tmp * Aenea_model_B.psi_ref_tmp;
      Aenea_model_B.Gain_ll = rt_atan2d_snf(std::sqrt(Aenea_model_B.Gain_ll),
        std::sqrt(1.0 - Aenea_model_B.Gain_ll)) * 2.0 * 6.378137E+6;
      Aenea_model_B.angoloWP = rt_atan2d_snf(std::sin
        (Aenea_model_B.psi_ref_tmp_tmp) * Aenea_model_B.Gain_m5, std::sin
        (Aenea_model_B.psi_ref_tmp_tmp_tmp) * Aenea_model_B.angoloWP - std::cos
        (Aenea_model_B.psi_ref_tmp_tmp) * (std::sin(Aenea_model_B.WP_db_param[
        static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 23] *
        3.1415926535897931 / 180.0) * Aenea_model_B.Gain_m5)) * 180.0 /
        3.1415926535897931;
      if (Aenea_model_B.angoloWP < 0.0) {
        Aenea_model_B.angoloWP = 360.0 - std::abs(Aenea_model_B.angoloWP);
      }

      if (Aenea_model_DW.Memory4_PreviousInput > 1.0) {
        Aenea_model_B.angoloWP = std::abs(Aenea_model_B.angoloWP -
          Aenea_model_B.psi_ref);
      } else {
        Aenea_model_B.angoloWP = std::abs(Aenea_model_B.angoloWP - rt_atan2d_snf
          (std::sin((Aenea_model_B.WP_db_param[static_cast<int32_T>
                     (Aenea_model_DW.Memory4_PreviousInput) + 29] -
                     Aenea_model_DW.long1) * 3.1415926535897931 / 180.0) * std::
           cos(Aenea_model_B.WP_db_param[static_cast<int32_T>
               (Aenea_model_DW.Memory4_PreviousInput) + 23] * 3.1415926535897931
               / 180.0), std::sin(Aenea_model_B.WP_db_param[static_cast<int32_T>
          (Aenea_model_DW.Memory4_PreviousInput) + 23] * 3.1415926535897931 /
          180.0) * std::cos(Aenea_model_DW.lat1 * 3.1415926535897931 / 180.0) -
           std::cos(Aenea_model_B.WP_db_param[static_cast<int32_T>
                    (Aenea_model_DW.Memory4_PreviousInput) + 23] *
                    3.1415926535897931 / 180.0) * std::sin(Aenea_model_DW.lat1 *
          3.1415926535897931 / 180.0) * std::cos((Aenea_model_B.WP_db_param[
          static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 29] -
          Aenea_model_DW.long1) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      Aenea_model_B.Gain_ll = 0.0;
      Aenea_model_B.angoloWP = 0.0;
    }

    if (Aenea_model_DW.Memory4_PreviousInput < 2.0) {
      Aenea_model_B.psi_ref_pre = 0.0;
    } else if (Aenea_model_DW.Memory4_PreviousInput == 2.0) {
      Aenea_model_B.psi_ref_pre = Aenea_model_B.WP_db_param[24] *
        3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_tmp_tmp = std::cos(Aenea_model_B.psi_ref_pre);
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.WP_db_param[30] -
        Aenea_model_DW.long1) * 3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_pre = std::abs(Aenea_model_B.psi_ref - rt_atan2d_snf
        (std::sin(Aenea_model_B.psi_ref_tmp) * Aenea_model_B.psi_ref_tmp_tmp,
         std::cos(Aenea_model_DW.lat1 * 3.1415926535897931 / 180.0) * std::sin
         (Aenea_model_B.psi_ref_pre) - std::sin(Aenea_model_DW.lat1 *
        3.1415926535897931 / 180.0) * Aenea_model_B.psi_ref_tmp_tmp * std::cos
         (Aenea_model_B.psi_ref_tmp)) * 180.0 / 3.1415926535897931);
    } else {
      Aenea_model_B.psi_ref_pre = std::cos(Aenea_model_B.WP_db_param[
        static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23] *
        3.1415926535897931 / 180.0);
      Aenea_model_B.psi_ref_tmp_tmp = Aenea_model_B.WP_db_param
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.WP_db_param[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput - 1.0) + 29] -
        Aenea_model_B.WP_db_param[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput - 2.0) + 29]) * 3.1415926535897931
        / 180.0;
      Aenea_model_B.psi_ref_pre = rt_atan2d_snf(std::sin
        (Aenea_model_B.psi_ref_tmp) * Aenea_model_B.psi_ref_pre, std::cos
        (Aenea_model_B.psi_ref_tmp_tmp) * std::sin(Aenea_model_B.WP_db_param[
        static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23] *
        3.1415926535897931 / 180.0) - std::sin(Aenea_model_B.psi_ref_tmp_tmp) *
        Aenea_model_B.psi_ref_pre * std::cos(Aenea_model_B.psi_ref_tmp)) * 180.0
        / 3.1415926535897931;
      if (Aenea_model_B.psi_ref_pre < 0.0) {
        Aenea_model_B.psi_ref_pre = 360.0 - std::abs(Aenea_model_B.psi_ref_pre);
      }

      Aenea_model_B.psi_ref_pre = std::abs(Aenea_model_B.psi_ref -
        Aenea_model_B.psi_ref_pre);
    }

    if (Aenea_model_B.angoloWP <= 10.0) {
      Aenea_model_B.psi_ref = 40.0;
      Aenea_model_B.tolleranza_distWP_fut = 10;
    } else if ((Aenea_model_B.angoloWP > 10.0) && (Aenea_model_B.angoloWP <=
                50.0)) {
      Aenea_model_B.psi_ref = 60.0;
      Aenea_model_B.tolleranza_distWP_fut = 15;
    } else if ((Aenea_model_B.angoloWP > 50.0) && (Aenea_model_B.angoloWP <=
                90.0)) {
      Aenea_model_B.psi_ref = 80.0;
      Aenea_model_B.tolleranza_distWP_fut = 20;
    } else if ((Aenea_model_B.angoloWP > 90.0) && (Aenea_model_B.angoloWP <=
                120.0)) {
      Aenea_model_B.psi_ref = 120.0;
      Aenea_model_B.tolleranza_distWP_fut = 25;
    } else {
      Aenea_model_B.psi_ref = 150.0;
      Aenea_model_B.tolleranza_distWP_fut = 30;
    }

    if (Aenea_model_B.psi_ref_pre <= 10.0) {
      Aenea_model_B.caso = 50;
    } else if ((Aenea_model_B.psi_ref_pre > 10.0) && (Aenea_model_B.psi_ref_pre <=
                50.0)) {
      Aenea_model_B.caso = 200;
    } else if ((Aenea_model_B.psi_ref_pre > 50.0) && (Aenea_model_B.psi_ref_pre <=
                90.0)) {
      Aenea_model_B.caso = 300;
    } else if ((Aenea_model_B.psi_ref_pre > 90.0) && (Aenea_model_B.psi_ref_pre <=
                120.0)) {
      Aenea_model_B.caso = 350;
    } else {
      Aenea_model_B.caso = 400;
    }

    if (Aenea_model_B.Switch_n == 1) {
      Aenea_model_B.VELOCITA = Aenea_model_B.WP_db_param[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput) + 11];
      if (Aenea_model_B.VELOCITA < 15.0) {
        Aenea_model_B.VELOCITA = 25.0;
      }

      if (!(Aenea_model_B.VELOCITA <= 20.0)) {
        if (Aenea_model_B.VELOCITA <= 25.0) {
          Aenea_model_B.psi_ref *= 1.2;
        } else if (Aenea_model_B.VELOCITA <= 30.0) {
          Aenea_model_B.psi_ref *= 1.3;
        } else {
          Aenea_model_B.psi_ref *= 1.4;
        }
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.caso)) || (!(Aenea_model_B.a_c >
             Aenea_model_B.psi_ref))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.caso)) || (!(Aenea_model_B.a_c >
             Aenea_model_B.psi_ref))) && (Aenea_model_B.a_c <
           Aenea_model_B.psi_ref)) {
        if (Aenea_model_B.Gain_ll > Aenea_model_B.tolleranza_distWP_fut) {
          Aenea_model_DW.Memory4_PreviousInput++;
        } else if (Aenea_model_DW.Memory4_PreviousInput < 5.0) {
          Aenea_model_DW.Memory4_PreviousInput += 2.0;
        } else {
          Aenea_model_B.VELOCITA = 22.0;
          Aenea_model_B.QUOTA = Aenea_model_B.h_K + 0.4;
        }
      }

      Aenea_model_DW.flag_f = 0.0;
    } else {
      Aenea_model_B.VELOCITA = Aenea_model_B.WP_db_param[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput) + 11];
      if (Aenea_model_B.VELOCITA < 15.0) {
        Aenea_model_B.VELOCITA = 25.0;
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.caso)) ||
           (!(Aenea_model_DW.flag_f == 0.0))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.caso)) || (!(Aenea_model_B.a_c > 40.0)) ||
           (!(Aenea_model_DW.flag_f == 0.0)))) {
        Aenea_model_B.VELOCITA = 22.0;
        Aenea_model_B.QUOTA = Aenea_model_B.h_K + 0.4;
        Aenea_model_DW.flag_f = 1.0;
      }
    }

    if ((Aenea_model_B.Wp_selector == 0.0) && (Aenea_model_B.smax == 0.0) &&
        (Aenea_model_B.QUOTA == 0.0)) {
      Aenea_model_B.QUOTA = Aenea_model_B.h_K + 0.3;
      Aenea_model_B.VELOCITA = 22.0;
    }

    // Saturate: '<S438>/saturatore V' incorporates:
    //   MATLAB Function: '<S438>/WAYPOINTS'

    if (Aenea_model_B.VELOCITA > 40.0) {
      // Saturate: '<S438>/saturatore V'
      Aenea_model_B.VELOCITA = 40.0;
    } else {
      if (Aenea_model_B.VELOCITA < 15.0) {
        // Saturate: '<S438>/saturatore V'
        Aenea_model_B.VELOCITA = 15.0;
      }
    }

    // End of Saturate: '<S438>/saturatore V'
  }

  // End of Outputs for SubSystem: '<S34>/Subsystem2'

  // Outputs for Enabled SubSystem: '<S34>/Subsystem' incorporates:
  //   EnablePort: '<S436>/Enable'

  if (Aenea_model_B.Vec_selector > 0.0) {
    // MATLAB Function: '<S436>/VETTORIALE' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'
    //   Memory: '<S436>/Memory1'
    //   Memory: '<S436>/Memory2'
    //   Memory: '<S436>/Memory3'
    //   Memory: '<S436>/Memory6'

    if ((Aenea_model_DW.Memory2_PreviousInput_d[1] !=
         Aenea_model_DW.Memory6_PreviousInput) || (Aenea_model_B.modo !=
         Aenea_model_DW.Memory3_PreviousInput) ||
        (Aenea_model_DW.Memory2_PreviousInput_d[3] !=
         Aenea_model_DW.Memory2_PreviousInput_d2)) {
      Aenea_model_DW.V_ref = Aenea_model_B.Product1;
    }

    if ((Aenea_model_DW.Memory2_PreviousInput_d[1] !=
         Aenea_model_DW.Memory6_PreviousInput) || (Aenea_model_B.modo !=
         Aenea_model_DW.Memory3_PreviousInput) ||
        (Aenea_model_DW.Memory2_PreviousInput_d[4] !=
         Aenea_model_DW.Memory1_PreviousInput_k)) {
      Aenea_model_DW.ALT_ref = Aenea_model_B.h_K;
    }

    if (Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) {
      Aenea_model_B.V_vett = Aenea_model_DW.riferimenti[8];
    } else {
      Aenea_model_B.V_vett = Aenea_model_DW.V_ref;
    }

    if (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) {
      Aenea_model_B.h_vett = Aenea_model_DW.riferimenti[9];
    } else {
      Aenea_model_B.h_vett = Aenea_model_DW.ALT_ref;
    }

    // Update for Memory: '<S436>/Memory1' incorporates:
    //   MATLAB Function: '<S436>/VETTORIALE'

    Aenea_model_DW.Memory1_PreviousInput_k =
      Aenea_model_DW.Memory2_PreviousInput_d[4];

    // Update for Memory: '<S436>/Memory2' incorporates:
    //   MATLAB Function: '<S436>/VETTORIALE'

    Aenea_model_DW.Memory2_PreviousInput_d2 =
      Aenea_model_DW.Memory2_PreviousInput_d[3];

    // Update for Memory: '<S436>/Memory3' incorporates:
    //   MATLAB Function: '<S436>/VETTORIALE'

    Aenea_model_DW.Memory3_PreviousInput = Aenea_model_B.modo;

    // Update for Memory: '<S436>/Memory6' incorporates:
    //   MATLAB Function: '<S436>/VETTORIALE'

    Aenea_model_DW.Memory6_PreviousInput =
      Aenea_model_DW.Memory2_PreviousInput_d[1];
  }

  // End of Outputs for SubSystem: '<S34>/Subsystem'

  // Outputs for Enabled SubSystem: '<S34>/DECOLLO AUTOMATICO' incorporates:
  //   EnablePort: '<S435>/Enable'

  if (Aenea_model_B.Ato_selector > 0.0) {
    // Outputs for Triggered SubSystem: '<S435>/Sample and Hold' incorporates:
    //   TriggerPort: '<S443>/Trigger'

    // Memory: '<S435>/Memory'
    rt_ZCFcn(RISING_ZERO_CROSSING,&Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_a,
             (Aenea_model_DW.Memory_PreviousInput_p));

    // End of Outputs for SubSystem: '<S435>/Sample and Hold'

    // Outputs for Triggered SubSystem: '<S435>/Sample and Hold1' incorporates:
    //   TriggerPort: '<S444>/Trigger'

    // Memory: '<S435>/Memory1'
    rt_ZCFcn(RISING_ZERO_CROSSING,&Aenea_model_PrevZCX.SampleandHold1_Trig_ZCE,
             (Aenea_model_DW.Memory1_PreviousInput_e));

    // End of Outputs for SubSystem: '<S435>/Sample and Hold1'

    // Chart: '<S435>/Chart1'
    if (Aenea_model_DW.temporalCounter_i1 < 255U) {
      Aenea_model_DW.temporalCounter_i1 = static_cast<uint8_T>
        (Aenea_model_DW.temporalCounter_i1 + 1U);
    }

    if (Aenea_model_DW.is_active_c1_Aenea_model == 0U) {
      Aenea_model_DW.is_active_c1_Aenea_model = 1U;
      Aenea_model_DW.is_c1_Aenea_model = Aenea_model_IN_Fase_0_ATO;
    } else {
      switch (Aenea_model_DW.is_c1_Aenea_model) {
       case Aenea_model_IN_Fase_0_ATO:
        if (Aenea_model_B.modo == 3.0) {
          Aenea_model_B.psi_ref_selector = 1.0;
          Aenea_model_DW.is_c1_Aenea_model = Aenea_model_IN_Fase_1_ATO;
          Aenea_model_DW.temporalCounter_i1 = 0U;
        } else {
          Aenea_model_B.Fase_ATO = 0.0;
          Aenea_model_B.psi_ref_selector = 0.0;
          Aenea_model_B.theta_ground_selector = 0.0;
          Aenea_model_B.Tas_ref = 0.0;
          Aenea_model_B.h_ref = 0.0;
        }
        break;

       case Aenea_model_IN_Fase_1_ATO:
        if (Aenea_model_DW.temporalCounter_i1 >= 250) {
          Aenea_model_DW.is_c1_Aenea_model = Aenea_model_IN_Fase_2_ATO;
        } else {
          Aenea_model_B.Fase_ATO = 1.0;
          Aenea_model_B.manetta_ref = 0.1;
          Aenea_model_B.psi_ref_selector = 0.0;
          Aenea_model_B.h_ref = 0.0;
        }
        break;

       case Aenea_model_IN_Fase_2_ATO:
        if ((Aenea_model_B.Product1 >= 18.0) && (Aenea_model_B.v_K >= 10.0)) {
          Aenea_model_B.theta_ground_selector = 1.0;
          Aenea_model_DW.is_c1_Aenea_model = Aenea_model_IN_Fase_3_ATO;
        } else {
          Aenea_model_B.Fase_ATO = 2.0;
          Aenea_model_B.psi_ref_selector = 0.0;
          Aenea_model_B.h_ref = 0.0;
          Aenea_model_B.Tas_ref = 25.0;
        }
        break;

       case Aenea_model_IN_Fase_3_ATO:
        if (Aenea_model_B.h_K >= 2.0) {
          Aenea_model_DW.is_c1_Aenea_model = Aenea_model_IN_Fase_4_ATO;
        } else {
          Aenea_model_B.Fase_ATO = 3.0;
          Aenea_model_B.psi_ref_selector = 0.0;
          Aenea_model_B.theta_ground_selector = 0.0;
          Aenea_model_B.h_ref = 0.0;
          Aenea_model_B.Tas_ref = 25.0;
        }
        break;

       default:
        // case IN_Fase_4_ATO:
        Aenea_model_B.Fase_ATO = 4.0;
        Aenea_model_B.psi_ref_selector = 0.0;
        Aenea_model_B.h_ref = 35.0;
        Aenea_model_B.Tas_ref = 25.0;
        break;
      }
    }

    // End of Chart: '<S435>/Chart1'

    // Update for Memory: '<S435>/Memory'
    Aenea_model_DW.Memory_PreviousInput_p = Aenea_model_B.psi_ref_selector;

    // Update for Memory: '<S435>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput_e = Aenea_model_B.theta_ground_selector;
  }

  // End of Outputs for SubSystem: '<S34>/DECOLLO AUTOMATICO'

  // Outputs for Enabled SubSystem: '<S34>/Subsystem1' incorporates:
  //   EnablePort: '<S437>/Enable'

  if (Aenea_model_B.Al_selector > 0.0) {
    // DataTypeConversion: '<S437>/Data Type Conversion4' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'

    for (Aenea_model_B.i = 0; Aenea_model_B.i < 42; Aenea_model_B.i++) {
      Aenea_model_B.WP_db_param[Aenea_model_B.i] =
        Aenea_model_DW.WP_dbP_AL[Aenea_model_B.i];
    }

    // End of DataTypeConversion: '<S437>/Data Type Conversion4'

    // MATLAB Function: '<S437>/CALIBRATING_HOME_COORDINATES' incorporates:
    //   DataTypeConversion: '<S437>/Data Type Conversion4'
    //   MATLAB Function: '<S450>/MATLAB Function'

    Aenea_model_B.Wp_selector = Aenea_model_B.WP_db_param[30] *
      0.017453292519943295;
    Aenea_model_B.Vec_selector = std::cos(Aenea_model_B.WP_db_param[25] *
      0.017453292519943295);
    Aenea_model_B.a_c = std::sin(Aenea_model_B.WP_db_param[24] *
      0.017453292519943295);
    Aenea_model_B.Ato_selector = std::cos(Aenea_model_B.WP_db_param[24] *
      0.017453292519943295);
    Aenea_model_B.smax = Aenea_model_B.WP_db_param[31] * 0.017453292519943295 -
      Aenea_model_B.WP_db_param[30] * 0.017453292519943295;
    Aenea_model_B.smax = rt_atan2d_snf(std::sin(Aenea_model_B.smax) *
      Aenea_model_B.Vec_selector, std::sin(Aenea_model_B.WP_db_param[25] *
      0.017453292519943295) * Aenea_model_B.Ato_selector - std::cos
      (Aenea_model_B.smax) * (Aenea_model_B.a_c * Aenea_model_B.Vec_selector));
    if (Aenea_model_B.smax < 0.0) {
      Aenea_model_B.smax = 6.2831853071795862 - std::abs(Aenea_model_B.smax);
    }

    // MATLAB Function: '<S450>/MATLAB Function' incorporates:
    //   MATLAB Function: '<S437>/CALIBRATING_HOME_COORDINATES'
    //   Trigonometry: '<S521>/SinCos'

    Aenea_model_B.Vec_selector = std::cos(Aenea_model_B.smax);
    Aenea_model_B.Al_selector = std::asin(Aenea_model_B.Ato_selector *
      -0.00015678559364639647 * Aenea_model_B.Vec_selector + Aenea_model_B.a_c *
      0.99999998770913878);
    Aenea_model_B.smax = std::sin(Aenea_model_B.smax);

    // MATLAB Function: '<S450>/AUTOLANDING_WAYPOINTS' incorporates:
    //   DataTypeConversion: '<S437>/Data Type Conversion4'
    //   Gain: '<S466>/Gain'
    //   Gain: '<S467>/Gain'
    //   MATLAB Function: '<S437>/CALIBRATING_HOME_COORDINATES'
    //   MATLAB Function: '<S450>/MATLAB Function'

    Aenea_model_B.y[12] = 57.295779513082323 * Aenea_model_B.Al_selector;
    Aenea_model_B.y[15] = 57.295779513082323 * (rt_atan2d_snf(Aenea_model_B.smax
      * -0.00015678559364639647 * Aenea_model_B.Ato_selector,
      0.99999998770913878 - Aenea_model_B.a_c * std::sin
      (Aenea_model_B.Al_selector)) + Aenea_model_B.Wp_selector);
    Aenea_model_B.y[3] = 1.0;
    Aenea_model_B.y[6] = 0.0;
    Aenea_model_B.y[9] = 0.0;
    Aenea_model_B.y[18] = Aenea_model_B.WP_db_param[36] + 45.0;

    // MATLAB Function: '<S450>/MATLAB Function'
    Aenea_model_B.Al_selector = std::asin(Aenea_model_B.Ato_selector *
      -0.00012542847510211208 * Aenea_model_B.Vec_selector + Aenea_model_B.a_c *
      0.99999999213384883);

    // MATLAB Function: '<S450>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Constant: '<S450>/Constant1'
    //   DataTypeConversion: '<S437>/Data Type Conversion4'
    //   Gain: '<S466>/Gain'
    //   Gain: '<S467>/Gain'
    //   MATLAB Function: '<S437>/CALIBRATING_HOME_COORDINATES'
    //   MATLAB Function: '<S450>/MATLAB Function'

    Aenea_model_B.y[13] = 57.295779513082323 * Aenea_model_B.Al_selector;
    Aenea_model_B.y[16] = 57.295779513082323 * (rt_atan2d_snf(Aenea_model_B.smax
      * -0.00012542847510211208 * Aenea_model_B.Ato_selector,
      0.99999999213384883 - Aenea_model_B.a_c * std::sin
      (Aenea_model_B.Al_selector)) + Aenea_model_B.Wp_selector);
    Aenea_model_B.y[1] = 20.0;
    Aenea_model_B.y[4] = 1.0;
    Aenea_model_B.y[7] = 0.0;
    Aenea_model_B.y[10] = 0.0;
    Aenea_model_B.y[19] = Aenea_model_B.WP_db_param[36] + 45.0;

    // MATLAB Function: '<S450>/MATLAB Function'
    Aenea_model_B.Al_selector = std::asin(Aenea_model_B.Ato_selector *
      0.00031357118343873296 * Aenea_model_B.Vec_selector + Aenea_model_B.a_c *
      0.99999995083655524);

    // MATLAB Function: '<S450>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Constant: '<S450>/Constant'
    //   Constant: '<S450>/Constant1'
    //   DataTypeConversion: '<S437>/Data Type Conversion4'
    //   Gain: '<S466>/Gain'
    //   Gain: '<S467>/Gain'
    //   MATLAB Function: '<S437>/CALIBRATING_HOME_COORDINATES'
    //   MATLAB Function: '<S450>/MATLAB Function'

    Aenea_model_B.y[14] = 57.295779513082323 * Aenea_model_B.Al_selector;
    Aenea_model_B.y[17] = 57.295779513082323 * (rt_atan2d_snf(Aenea_model_B.smax
      * 0.00031357118343873296 * Aenea_model_B.Ato_selector, 0.99999995083655524
      - Aenea_model_B.a_c * std::sin(Aenea_model_B.Al_selector)) +
      Aenea_model_B.Wp_selector);
    Aenea_model_B.y[2] = 20.0;
    Aenea_model_B.y[8] = 0.0;
    Aenea_model_B.y[11] = 0.0;
    Aenea_model_B.y[20] = Aenea_model_B.WP_db_param[36] + 45.0;
    Aenea_model_B.y[0] = 25.0;
    Aenea_model_B.y[5] = 0.0;

    // Gain: '<S455>/Gain' incorporates:
    //   DataTypeConversion: '<S437>/Data Type Conversion4'
    //   MATLAB Function: '<S437>/CALIBRATING_HOME_COORDINATES'

    Aenea_model_B.Ato_selector = Aenea_model_B.WP_db_param[24] *
      0.017453292519943295 * 57.295779513082323;

    // Switch: '<S531>/Switch' incorporates:
    //   Abs: '<S531>/Abs'
    //   Bias: '<S531>/Bias'
    //   Bias: '<S531>/Bias1'
    //   Constant: '<S531>/Constant2'
    //   Constant: '<S532>/Constant'
    //   Math: '<S531>/Math Function1'
    //   RelationalOperator: '<S532>/Compare'

    if (std::abs(Aenea_model_B.Ato_selector) > 180.0) {
      Aenea_model_B.Ato_selector = rt_modd_snf(Aenea_model_B.Ato_selector +
        180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S531>/Switch'

    // Abs: '<S528>/Abs1'
    Aenea_model_B.a_c = std::abs(Aenea_model_B.Ato_selector);

    // Switch: '<S528>/Switch' incorporates:
    //   Bias: '<S528>/Bias'
    //   Bias: '<S528>/Bias1'
    //   Constant: '<S520>/Constant'
    //   Constant: '<S520>/Constant1'
    //   Constant: '<S530>/Constant'
    //   Gain: '<S528>/Gain'
    //   Product: '<S528>/Divide1'
    //   RelationalOperator: '<S530>/Compare'
    //   Switch: '<S520>/Switch1'

    if (Aenea_model_B.a_c > 90.0) {
      // Signum: '<S528>/Sign1'
      if (Aenea_model_B.Ato_selector < 0.0) {
        Aenea_model_B.Ato_selector = -1.0;
      } else if (Aenea_model_B.Ato_selector > 0.0) {
        Aenea_model_B.Ato_selector = 1.0;
      } else if (Aenea_model_B.Ato_selector == 0.0) {
        Aenea_model_B.Ato_selector = 0.0;
      } else {
        Aenea_model_B.Ato_selector = (rtNaN);
      }

      // End of Signum: '<S528>/Sign1'
      Aenea_model_B.Ato_selector *= -(Aenea_model_B.a_c + -90.0) + 90.0;
      Aenea_model_B.Switch_n = 180;
    } else {
      Aenea_model_B.Switch_n = 0;
    }

    // End of Switch: '<S528>/Switch'

    // Sum: '<S520>/Sum' incorporates:
    //   Gain: '<S456>/Gain'

    Aenea_model_B.a_c = 57.295779513082323 * Aenea_model_B.Wp_selector +
      static_cast<real_T>(Aenea_model_B.Switch_n);

    // Sum: '<S454>/Sum1' incorporates:
    //   Gain: '<S458>/Gain'

    Aenea_model_B.Wp_selector = 57.295779513082323 * Aenea_model_B.Lat_K -
      Aenea_model_B.Ato_selector;

    // Switch: '<S525>/Switch' incorporates:
    //   Abs: '<S525>/Abs'
    //   Bias: '<S525>/Bias'
    //   Bias: '<S525>/Bias1'
    //   Constant: '<S525>/Constant2'
    //   Constant: '<S526>/Constant'
    //   Math: '<S525>/Math Function1'
    //   RelationalOperator: '<S526>/Compare'

    if (std::abs(Aenea_model_B.Wp_selector) > 180.0) {
      Aenea_model_B.Wp_selector = rt_modd_snf(Aenea_model_B.Wp_selector + 180.0,
        360.0) + -180.0;
    }

    // End of Switch: '<S525>/Switch'

    // Abs: '<S522>/Abs1'
    Aenea_model_B.Al_selector = std::abs(Aenea_model_B.Wp_selector);

    // Switch: '<S522>/Switch' incorporates:
    //   Bias: '<S522>/Bias'
    //   Bias: '<S522>/Bias1'
    //   Constant: '<S519>/Constant'
    //   Constant: '<S519>/Constant1'
    //   Constant: '<S524>/Constant'
    //   Gain: '<S522>/Gain'
    //   Product: '<S522>/Divide1'
    //   RelationalOperator: '<S524>/Compare'
    //   Switch: '<S519>/Switch1'

    if (Aenea_model_B.Al_selector > 90.0) {
      // Signum: '<S522>/Sign1'
      if (Aenea_model_B.Wp_selector < 0.0) {
        Aenea_model_B.Wp_selector = -1.0;
      } else if (Aenea_model_B.Wp_selector > 0.0) {
        Aenea_model_B.Wp_selector = 1.0;
      } else if (Aenea_model_B.Wp_selector == 0.0) {
        Aenea_model_B.Wp_selector = 0.0;
      } else {
        Aenea_model_B.Wp_selector = (rtNaN);
      }

      // End of Signum: '<S522>/Sign1'
      Aenea_model_B.Wp_selector *= -(Aenea_model_B.Al_selector + -90.0) + 90.0;
      Aenea_model_B.Switch_n = 180;
    } else {
      Aenea_model_B.Switch_n = 0;
    }

    // End of Switch: '<S522>/Switch'

    // Switch: '<S529>/Switch' incorporates:
    //   Abs: '<S529>/Abs'
    //   Bias: '<S529>/Bias'
    //   Bias: '<S529>/Bias1'
    //   Constant: '<S529>/Constant2'
    //   Constant: '<S533>/Constant'
    //   Math: '<S529>/Math Function1'
    //   RelationalOperator: '<S533>/Compare'

    if (std::abs(Aenea_model_B.a_c) > 180.0) {
      Aenea_model_B.a_c = rt_modd_snf(Aenea_model_B.a_c + 180.0, 360.0) + -180.0;
    }

    // End of Switch: '<S529>/Switch'

    // Sum: '<S519>/Sum' incorporates:
    //   Gain: '<S457>/Gain'
    //   Sum: '<S454>/Sum1'

    Aenea_model_B.psi_ref_pre = (57.295779513082323 * Aenea_model_B.Long_K -
      Aenea_model_B.a_c) + static_cast<real_T>(Aenea_model_B.Switch_n);

    // Gain: '<S535>/Gain1'
    Aenea_model_B.Ato_selector *= 0.017453292519943295;

    // Trigonometry: '<S538>/Trigonometric Function1'
    Aenea_model_B.Al_selector = std::sin(Aenea_model_B.Ato_selector);

    // Sum: '<S538>/Sum1' incorporates:
    //   Constant: '<S538>/Constant'
    //   Product: '<S538>/Product1'

    Aenea_model_B.Al_selector = 1.0 - 0.0066943799901413295 *
      Aenea_model_B.Al_selector * Aenea_model_B.Al_selector;

    // Product: '<S534>/Product1' incorporates:
    //   Constant: '<S534>/Constant1'
    //   Sqrt: '<S534>/sqrt'

    Aenea_model_B.a_c = 6.378137E+6 / std::sqrt(Aenea_model_B.Al_selector);

    // Switch: '<S523>/Switch' incorporates:
    //   Abs: '<S523>/Abs'
    //   Bias: '<S523>/Bias'
    //   Bias: '<S523>/Bias1'
    //   Constant: '<S523>/Constant2'
    //   Constant: '<S527>/Constant'
    //   Math: '<S523>/Math Function1'
    //   RelationalOperator: '<S527>/Compare'

    if (std::abs(Aenea_model_B.psi_ref_pre) > 180.0) {
      Aenea_model_B.psi_ref_pre = rt_modd_snf(Aenea_model_B.psi_ref_pre + 180.0,
        360.0) + -180.0;
    }

    // End of Switch: '<S523>/Switch'

    // Sum: '<S521>/Sum2' incorporates:
    //   Constant: '<S534>/Constant'
    //   Constant: '<S534>/Constant2'
    //   Constant: '<S534>/Constant3'
    //   Gain: '<S518>/Gain1'
    //   Product: '<S521>/dEast'
    //   Product: '<S521>/dNorth'
    //   Product: '<S521>/x*cos'
    //   Product: '<S521>/y*sin'
    //   Product: '<S534>/Product2'
    //   Product: '<S534>/Product3'
    //   Product: '<S534>/Product4'
    //   Sum: '<S534>/Sum1'
    //   Trigonometry: '<S534>/Trigonometric Function'
    //   Trigonometry: '<S534>/Trigonometric Function1'
    //   Trigonometry: '<S534>/Trigonometric Function2'

    Aenea_model_B.Vec_selector = 0.017453292519943295 *
      Aenea_model_B.Wp_selector / rt_atan2d_snf(1.0, Aenea_model_B.a_c *
      0.99330562000985867 / Aenea_model_B.Al_selector) *
      Aenea_model_B.Vec_selector + 1.0 / rt_atan2d_snf(1.0, Aenea_model_B.a_c *
      std::cos(Aenea_model_B.Ato_selector)) * (0.017453292519943295 *
      Aenea_model_B.psi_ref_pre) * Aenea_model_B.smax;

    // Gain: '<S459>/Gain'
    Aenea_model_B.Ato_selector = 57.295779513082323 * Aenea_model_B.Lat_K;

    // Gain: '<S460>/Gain'
    Aenea_model_B.Al_selector = 57.295779513082323 * Aenea_model_B.Long_K;

    // MATLAB Function: '<S437>/ALLINEAMENTO' incorporates:
    //   Memory: '<S437>/Memory7'

    Aenea_model_B.Wp_selector = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 11];
    Aenea_model_B.a_c = std::sin((Aenea_model_B.Wp_selector -
      Aenea_model_B.Ato_selector) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Gain_ll = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 14];
    Aenea_model_B.smax = (Aenea_model_B.Gain_ll - Aenea_model_B.Al_selector) *
      3.1415926535897931 / 180.0;
    Aenea_model_B.dist = std::sin(Aenea_model_B.smax / 2.0);
    Aenea_model_B.psi_ref = Aenea_model_B.Wp_selector * 3.1415926535897931 /
      180.0;
    Aenea_model_B.angoloWP = std::cos(Aenea_model_B.psi_ref);
    Aenea_model_B.psi_ref_tmp_tmp = Aenea_model_B.Ato_selector *
      3.1415926535897931 / 180.0;
    Aenea_model_B.psi_ref_pre = std::cos(Aenea_model_B.psi_ref_tmp_tmp);
    Aenea_model_B.a_c = Aenea_model_B.psi_ref_pre * Aenea_model_B.angoloWP *
      (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_c *
      Aenea_model_B.a_c;
    Aenea_model_B.a_c = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_c), std::sqrt
      (1.0 - Aenea_model_B.a_c)) * 2.0 * 6.378137E+6;
    if (Aenea_model_DW.Memory7_PreviousInput > 1.0) {
      Aenea_model_B.psi_ref_tmp_tmp_tmp = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11];
      Aenea_model_B.psi_ref = Aenea_model_B.psi_ref_tmp_tmp_tmp *
        3.1415926535897931 / 180.0;
      Aenea_model_B.dist = std::cos(Aenea_model_B.psi_ref);
      Aenea_model_B.psi_ref_tmp_tmp = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14];
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.Gain_ll -
        Aenea_model_B.psi_ref_tmp_tmp) * 3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref = rt_atan2d_snf(std::sin(Aenea_model_B.psi_ref_tmp) *
        Aenea_model_B.angoloWP, std::sin(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput) + 11] * 3.1415926535897931 /
        180.0) * Aenea_model_B.dist - std::sin(Aenea_model_B.psi_ref) *
        Aenea_model_B.angoloWP * std::cos(Aenea_model_B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.psi_ref_tmp = std::sin((Aenea_model_B.Ato_selector -
        Aenea_model_B.psi_ref_tmp_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.psi_ref_tmp_tmp = std::sin((Aenea_model_B.Al_selector -
        Aenea_model_B.psi_ref_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.dist = Aenea_model_B.dist * Aenea_model_B.psi_ref_pre *
        (Aenea_model_B.psi_ref_tmp_tmp * Aenea_model_B.psi_ref_tmp_tmp) +
        Aenea_model_B.psi_ref_tmp * Aenea_model_B.psi_ref_tmp;
      Aenea_model_B.dist = rt_atan2d_snf(std::sqrt(Aenea_model_B.dist), std::
        sqrt(1.0 - Aenea_model_B.dist)) * 2.0 * 6.378137E+6;
    } else {
      Aenea_model_B.psi_ref = rt_atan2d_snf(std::sin(Aenea_model_B.smax) *
        Aenea_model_B.angoloWP, std::sin(Aenea_model_B.psi_ref) *
        Aenea_model_B.psi_ref_pre - std::cos(Aenea_model_B.smax) * (std::sin
        (Aenea_model_B.psi_ref_tmp_tmp) * Aenea_model_B.angoloWP)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.dist = 0.0;
    }

    if (Aenea_model_B.psi_ref < 0.0) {
      Aenea_model_B.psi_ref = 360.0 - std::abs(Aenea_model_B.psi_ref);
    }

    Aenea_model_B.smax = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 2];
    if (Aenea_model_B.smax == 1.0) {
      Aenea_model_B.psi_ref_tmp_tmp_tmp = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput + 1.0) + 11];
      Aenea_model_B.psi_ref_tmp = std::sin((Aenea_model_B.psi_ref_tmp_tmp_tmp -
        Aenea_model_B.Wp_selector) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.psi_ref_tmp_tmp = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput + 1.0) + 14] -
        Aenea_model_B.Gain_ll) * 3.1415926535897931 / 180.0;
      Aenea_model_B.Gain_ll = std::sin(Aenea_model_B.psi_ref_tmp_tmp / 2.0);
      Aenea_model_B.psi_ref_tmp_tmp_tmp = Aenea_model_B.psi_ref_tmp_tmp_tmp *
        3.1415926535897931 / 180.0;
      Aenea_model_B.Gain_m5 = std::cos(Aenea_model_B.psi_ref_tmp_tmp_tmp);
      Aenea_model_B.Gain_ll = Aenea_model_B.angoloWP * Aenea_model_B.Gain_m5 *
        (Aenea_model_B.Gain_ll * Aenea_model_B.Gain_ll) +
        Aenea_model_B.psi_ref_tmp * Aenea_model_B.psi_ref_tmp;
      Aenea_model_B.Gain_ll = rt_atan2d_snf(std::sqrt(Aenea_model_B.Gain_ll),
        std::sqrt(1.0 - Aenea_model_B.Gain_ll)) * 2.0 * 6.378137E+6;
      Aenea_model_B.angoloWP = rt_atan2d_snf(std::sin
        (Aenea_model_B.psi_ref_tmp_tmp) * Aenea_model_B.Gain_m5, std::sin
        (Aenea_model_B.psi_ref_tmp_tmp_tmp) * Aenea_model_B.angoloWP - std::cos
        (Aenea_model_B.psi_ref_tmp_tmp) * (std::sin(Aenea_model_B.y[static_cast<
        int32_T>(Aenea_model_DW.Memory7_PreviousInput) + 11] *
        3.1415926535897931 / 180.0) * Aenea_model_B.Gain_m5)) * 180.0 /
        3.1415926535897931;
      if (Aenea_model_B.angoloWP < 0.0) {
        Aenea_model_B.angoloWP = 360.0 - std::abs(Aenea_model_B.angoloWP);
      }

      if (Aenea_model_DW.Memory7_PreviousInput > 1.0) {
        Aenea_model_B.angoloWP = std::abs(Aenea_model_B.angoloWP -
          Aenea_model_B.psi_ref);
      } else {
        Aenea_model_B.angoloWP = std::abs(Aenea_model_B.angoloWP - rt_atan2d_snf
          (std::sin((Aenea_model_B.y[static_cast<int32_T>
                     (Aenea_model_DW.Memory7_PreviousInput) + 14] -
                     Aenea_model_B.Al_selector) * 3.1415926535897931 / 180.0) *
           std::cos(Aenea_model_B.y[static_cast<int32_T>
                    (Aenea_model_DW.Memory7_PreviousInput) + 11] *
                    3.1415926535897931 / 180.0), std::sin(Aenea_model_B.y[
          static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput) + 11] *
          3.1415926535897931 / 180.0) * std::cos(Aenea_model_B.Ato_selector *
          3.1415926535897931 / 180.0) - std::cos(Aenea_model_B.y
          [static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput) + 11] *
          3.1415926535897931 / 180.0) * std::sin(Aenea_model_B.Ato_selector *
          3.1415926535897931 / 180.0) * std::cos((Aenea_model_B.y
          [static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput) + 14] -
          Aenea_model_B.Al_selector) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      Aenea_model_B.Gain_ll = 0.0;
      Aenea_model_B.angoloWP = 0.0;
    }

    if (Aenea_model_DW.Memory7_PreviousInput < 2.0) {
      Aenea_model_B.psi_ref_pre = 0.0;
    } else if (Aenea_model_DW.Memory7_PreviousInput == 2.0) {
      Aenea_model_B.psi_ref_tmp_tmp = std::cos(Aenea_model_B.y
        [static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0);
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14] -
        Aenea_model_B.Al_selector) * 3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_pre = std::abs(Aenea_model_B.psi_ref - rt_atan2d_snf
        (std::sin(Aenea_model_B.psi_ref_tmp) * Aenea_model_B.psi_ref_tmp_tmp,
         std::sin(Aenea_model_B.y[static_cast<int32_T>
                  (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] *
                  3.1415926535897931 / 180.0) * Aenea_model_B.psi_ref_pre - std::
         cos(Aenea_model_B.psi_ref_tmp) * (std::sin(Aenea_model_B.Ato_selector *
        3.1415926535897931 / 180.0) * Aenea_model_B.psi_ref_tmp_tmp)) * 180.0 /
        3.1415926535897931);
    } else {
      Aenea_model_B.psi_ref_pre = std::cos(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931 /
        180.0);
      Aenea_model_B.psi_ref_tmp_tmp = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 2.0) + 11] * 3.1415926535897931 /
        180.0;
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14] - Aenea_model_B.y[
        static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_pre = rt_atan2d_snf(std::sin
        (Aenea_model_B.psi_ref_tmp) * Aenea_model_B.psi_ref_pre, std::cos
        (Aenea_model_B.psi_ref_tmp_tmp) * std::sin(Aenea_model_B.y
        [static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] *
        3.1415926535897931 / 180.0) - std::sin(Aenea_model_B.psi_ref_tmp_tmp) *
        Aenea_model_B.psi_ref_pre * std::cos(Aenea_model_B.psi_ref_tmp)) * 180.0
        / 3.1415926535897931;
      if (Aenea_model_B.psi_ref_pre < 0.0) {
        Aenea_model_B.psi_ref_pre = 360.0 - std::abs(Aenea_model_B.psi_ref_pre);
      }

      Aenea_model_B.psi_ref_pre = std::abs(Aenea_model_B.psi_ref -
        Aenea_model_B.psi_ref_pre);
    }

    if (Aenea_model_B.angoloWP <= 3.0) {
      Aenea_model_B.psi_ref = 1.0;
      Aenea_model_B.tolleranza_distWP_fut = 20;
    } else if (Aenea_model_B.angoloWP <= 10.0) {
      Aenea_model_B.psi_ref = 30.0;
      Aenea_model_B.tolleranza_distWP_fut = 100;
    } else if ((Aenea_model_B.angoloWP > 10.0) && (Aenea_model_B.angoloWP <=
                50.0)) {
      Aenea_model_B.psi_ref = 80.0;
      Aenea_model_B.tolleranza_distWP_fut = 250;
    } else if ((Aenea_model_B.angoloWP > 50.0) && (Aenea_model_B.angoloWP <=
                90.0)) {
      Aenea_model_B.psi_ref = 100.0;
      Aenea_model_B.tolleranza_distWP_fut = 300;
    } else if ((Aenea_model_B.angoloWP > 90.0) && (Aenea_model_B.angoloWP <=
                120.0)) {
      Aenea_model_B.psi_ref = 150.0;
      Aenea_model_B.tolleranza_distWP_fut = 350;
    } else {
      Aenea_model_B.psi_ref = 200.0;
      Aenea_model_B.tolleranza_distWP_fut = 400;
    }

    if (Aenea_model_B.psi_ref_pre <= 10.0) {
      Aenea_model_B.caso = 80;
    } else if ((Aenea_model_B.psi_ref_pre > 10.0) && (Aenea_model_B.psi_ref_pre <=
                50.0)) {
      Aenea_model_B.caso = 200;
    } else if ((Aenea_model_B.psi_ref_pre > 50.0) && (Aenea_model_B.psi_ref_pre <=
                90.0)) {
      Aenea_model_B.caso = 300;
    } else if ((Aenea_model_B.psi_ref_pre > 90.0) && (Aenea_model_B.psi_ref_pre <=
                120.0)) {
      Aenea_model_B.caso = 350;
    } else {
      Aenea_model_B.caso = 400;
    }

    if (Aenea_model_B.smax == 1.0) {
      Aenea_model_B.smax = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput) - 1];
      if (Aenea_model_B.smax <= 20.0) {
        Aenea_model_B.psi_ref *= 1.1;
      } else if ((Aenea_model_B.smax <= 25.0) && (Aenea_model_B.smax > 20.0)) {
        Aenea_model_B.psi_ref *= 1.2;
      } else if (Aenea_model_B.smax <= 30.0) {
        if (Aenea_model_B.smax > 25.0) {
          Aenea_model_B.psi_ref *= 1.3;
        } else {
          Aenea_model_B.psi_ref *= 1.4;
        }
      } else {
        Aenea_model_B.psi_ref *= 1.4;
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.caso)) || (!(Aenea_model_B.a_c >
             Aenea_model_B.psi_ref))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.caso)) || (!(Aenea_model_B.a_c >
             Aenea_model_B.psi_ref))) && (Aenea_model_B.a_c <
           Aenea_model_B.psi_ref)) {
        if (Aenea_model_B.Gain_ll > Aenea_model_B.tolleranza_distWP_fut) {
          Aenea_model_DW.Memory7_PreviousInput++;
        } else if (Aenea_model_DW.Memory7_PreviousInput < 2.0) {
          Aenea_model_DW.Memory7_PreviousInput += 2.0;
        } else {
          Aenea_model_DW.flag_a = 1.0;
        }
      }
    } else {
      if (((!(Aenea_model_B.dist < Aenea_model_B.caso)) ||
           (!(Aenea_model_DW.flag_a == 0.0))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.caso)) || (!(Aenea_model_B.a_c > 40.0)) ||
           (!(Aenea_model_DW.flag_a == 0.0)))) {
        Aenea_model_DW.flag_a = 1.0;
      }
    }

    if (!(Aenea_model_B.modo == 4.0)) {
      Aenea_model_DW.Memory7_PreviousInput = 1.0;
    }

    // End of MATLAB Function: '<S437>/ALLINEAMENTO'

    // Abs: '<S437>/Abs1'
    Aenea_model_B.Wp_selector = std::abs(Aenea_model_B.Vec_selector);

    // Chart: '<S437>/Chart1' incorporates:
    //   Memory: '<S437>/Memory1'
    //   Memory: '<S437>/Memory2'
    //   Memory: '<S437>/Memory5'

    if (Aenea_model_DW.is_active_c10_Aenea_model == 0U) {
      Aenea_model_DW.is_active_c10_Aenea_model = 1U;
      Aenea_model_B.maneuver_selector = 1.0;
      Aenea_model_B.trig_approach = 0.0;
      Aenea_model_B.trig_flare = 0.0;
      Aenea_model_B.approach_selector = 1.0;
      Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Allignment1;
    } else {
      switch (Aenea_model_DW.is_c10_Aenea_model) {
       case Aenea_model_IN_Abort:
        Aenea_model_B.maneuver_selector = 1.0;
        Aenea_model_B.trig_approach = 0.0;
        Aenea_model_B.trig_flare = 0.0;
        Aenea_model_B.approach_selector = 0.0;
        break;

       case Aenea_model_IN_Allignment:
        if ((Aenea_model_B.h_K > 35.0) && (Aenea_model_B.h_K < 60.0) &&
            (Aenea_model_B.Wp_selector <= Aenea_model_B.h_K * 19.081136687728211
             + 100.0) && (Aenea_model_B.Wp_selector >= Aenea_model_B.h_K *
                          14.300666256711928 + 100.0) &&
            (Aenea_model_DW.Memory7_PreviousInput > 1.0)) {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Approach;
        } else if (Aenea_model_B.modo != 4.0) {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Allignment1;
        } else {
          Aenea_model_B.trig_flare = 0.0;
          Aenea_model_B.approach_selector = 0.0;
          Aenea_model_B.maneuver_selector = 1.0;
          Aenea_model_B.trig_approach = 0.0;
        }
        break;

       case Aenea_model_IN_Allignment1:
        if (Aenea_model_B.modo == 4.0) {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Allignment;
        } else {
          Aenea_model_B.maneuver_selector = 1.0;
          Aenea_model_B.trig_approach = 0.0;
          Aenea_model_B.trig_flare = 0.0;
          Aenea_model_B.approach_selector = 0.0;
        }
        break;

       case Aenea_model_IN_Approach:
        if ((Aenea_model_B.Vec_selector >= Aenea_model_DW.Memory5_PreviousInput)
            && ((Aenea_model_B.h_K <= Aenea_model_DW.Memory1_PreviousInput_f +
                 1.5) || (Aenea_model_B.h_K >
                          Aenea_model_DW.Memory1_PreviousInput_f - 1.0))) {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Flare;
        } else if (Aenea_model_B.modo != 4.0) {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Allignment1;
        } else if (Aenea_model_DW.Memory2_PreviousInput_e == 1.0) {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Abort;
        } else {
          Aenea_model_B.trig_flare = 0.0;
          Aenea_model_B.trig_approach = 1.0;
          Aenea_model_B.approach_selector = 1.0;
          Aenea_model_B.maneuver_selector = 2.0;
        }
        break;

       default:
        // case IN_Flare:
        if ((Aenea_model_B.Product1 < 3.0) || (!(Aenea_model_B.modo != 4.0))) {
          Aenea_model_B.trig_approach = 0.0;
          Aenea_model_B.trig_flare = 1.0;
          Aenea_model_B.approach_selector = 0.0;
          Aenea_model_B.maneuver_selector = 3.0;
        } else {
          Aenea_model_DW.is_c10_Aenea_model = Aenea_model_IN_Allignment1;
        }
        break;
      }
    }

    // End of Chart: '<S437>/Chart1'

    // Outputs for Triggered SubSystem: '<S437>/Sample and Hold' incorporates:
    //   TriggerPort: '<S462>/Trigger'

    Aenea_model_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_l,
      (Aenea_model_B.approach_selector));
    if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
      // Inport: '<S462>/In' incorporates:
      //   Abs: '<S437>/Abs2'
      //   Sum: '<S454>/Sum'
      //   UnaryMinus: '<S454>/Ze2height'

      Aenea_model_B.In_c[0] = std::abs(-Aenea_model_B.h_K);
      Aenea_model_B.In_c[1] = Aenea_model_B.Vec_selector;
    }

    // End of Outputs for SubSystem: '<S437>/Sample and Hold'

    // Outputs for Enabled SubSystem: '<S437>/APPROACH' incorporates:
    //   EnablePort: '<S448>/Enable'

    if (Aenea_model_B.trig_approach > 0.0) {
      // Product: '<S448>/Divide' incorporates:
      //   Constant: '<S448>/x_g0'
      //   Sum: '<S448>/Sum'

      Aenea_model_B.Wp_selector = Aenea_model_B.In_c[0] / (Aenea_model_B.In_c[1]
        - -100.0);

      // Abs: '<S448>/Abs' incorporates:
      //   Trigonometry: '<S448>/Atan'

      Aenea_model_B.a_c = std::abs(std::atan(Aenea_model_B.Wp_selector));

      // DiscreteIntegrator: '<S448>/Discrete-Time Integrator'
      if ((Aenea_model_B.trig_approach > 0.0) &&
          (Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o <= 0)) {
        Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j = 0.0;
      }

      if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j >= 1.0) {
        Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j = 1.0;
      } else {
        if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j <= 0.0) {
          Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j = 0.0;
        }
      }

      // Switch: '<S448>/Switch' incorporates:
      //   DiscreteIntegrator: '<S448>/Discrete-Time Integrator'

      Aenea_model_B.tolleranza_distWP_fut =
        (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j > 0.0);

      // MATLAB Function: '<S448>/MATLAB Function'
      Aenea_model_B.Switch_n = 0;
      if ((!Aenea_model_DW.x_not_empty) || (Aenea_model_B.tolleranza_distWP_fut ==
           0)) {
        Aenea_model_DW.x[0] = 1.5;
        Aenea_model_DW.x[1] = -200.0;
        Aenea_model_DW.x[2] = 0.01;
        Aenea_model_DW.x[3] = -2.0;
        Aenea_model_DW.x_not_empty = true;
      }

      Aenea_model_DW.x_new_not_empty = ((!Aenea_model_DW.x_new_not_empty) ||
        (Aenea_model_B.tolleranza_distWP_fut == 0) ||
        Aenea_model_DW.x_new_not_empty);
      if ((!Aenea_model_DW.eps_not_empty) ||
          (Aenea_model_B.tolleranza_distWP_fut == 0)) {
        Aenea_model_DW.eps[0] = 1.0;
        Aenea_model_DW.eps[1] = 1.0;
        Aenea_model_DW.eps[2] = 1.0;
        Aenea_model_DW.eps[3] = 1.0;
        Aenea_model_DW.eps_not_empty = true;
      }

      if ((!Aenea_model_DW.cycle_count_not_empty) ||
          (Aenea_model_B.tolleranza_distWP_fut == 0)) {
        Aenea_model_DW.cycle_count = 0.0;
        Aenea_model_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(Aenea_model_DW.eps[0] < 0.1)) ||
                           ((!(Aenea_model_DW.eps[1] < 0.1)) ||
                            ((!(Aenea_model_DW.eps[2] < 0.1)) ||
                             (!(Aenea_model_DW.eps[3] < 0.1)))))) {
        std::memset(&Aenea_model_B.a[0], 0, sizeof(real_T) << 4U);
        Aenea_model_B.Ato_selector = std::exp((5.0 - Aenea_model_DW.x[1]) *
          -Aenea_model_DW.x[2]);
        Aenea_model_B.psi_ref = std::tan(Aenea_model_B.a_c);
        Aenea_model_B.A[0] = 1.0;
        Aenea_model_B.A[4] = Aenea_model_B.psi_ref;
        Aenea_model_B.A[8] = 0.0;
        Aenea_model_B.A[12] = 0.0;
        Aenea_model_B.A[1] = Aenea_model_DW.x[2];
        Aenea_model_B.A[5] = 0.0;
        Aenea_model_B.psi_ref_pre = Aenea_model_DW.x[0] - Aenea_model_DW.x[3];
        Aenea_model_B.A[9] = Aenea_model_B.psi_ref_pre;
        Aenea_model_B.A[13] = -Aenea_model_DW.x[2];
        Aenea_model_B.A[2] = Aenea_model_B.Ato_selector;
        Aenea_model_B.angoloWP = Aenea_model_B.psi_ref_pre * Aenea_model_DW.x[2];
        Aenea_model_B.A[6] = Aenea_model_B.angoloWP * Aenea_model_B.Ato_selector;
        Aenea_model_B.A[10] = Aenea_model_B.psi_ref_pre * (Aenea_model_DW.x[1] -
          5.0) * Aenea_model_B.Ato_selector;
        Aenea_model_B.A[14] = 1.0;
        Aenea_model_B.A[3] = Aenea_model_DW.x[2] * 18.0 *
          Aenea_model_B.Ato_selector;
        Aenea_model_B.A[7] = Aenea_model_B.psi_ref_pre * (Aenea_model_DW.x[2] *
          Aenea_model_DW.x[2]) * 18.0 * Aenea_model_B.Ato_selector;
        Aenea_model_B.Al_selector = Aenea_model_B.angoloWP * 18.0;
        Aenea_model_B.A[11] = Aenea_model_B.Al_selector * (Aenea_model_DW.x[1] -
          5.0) * Aenea_model_B.Ato_selector + Aenea_model_B.psi_ref_pre * 18.0 *
          Aenea_model_B.Ato_selector;
        Aenea_model_B.A[15] = -Aenea_model_DW.x[2] * 18.0 *
          Aenea_model_B.Ato_selector;
        Aenea_model_B.ipiv_m[0] = 1;
        Aenea_model_B.ipiv_m[1] = 2;
        Aenea_model_B.ipiv_m[2] = 3;
        for (Aenea_model_B.tolleranza_distWP_fut = 0;
             Aenea_model_B.tolleranza_distWP_fut < 3;
             Aenea_model_B.tolleranza_distWP_fut++) {
          Aenea_model_B.caso = Aenea_model_B.tolleranza_distWP_fut * 5;
          Aenea_model_B.i = 0;
          Aenea_model_B.ix = Aenea_model_B.caso;
          Aenea_model_B.smax = std::abs(Aenea_model_B.A[Aenea_model_B.caso]);
          Aenea_model_B.d_k = 2;
          while (Aenea_model_B.d_k <= 4 - Aenea_model_B.tolleranza_distWP_fut) {
            Aenea_model_B.ix++;
            Aenea_model_B.dist = std::abs(Aenea_model_B.A[Aenea_model_B.ix]);
            if (Aenea_model_B.dist > Aenea_model_B.smax) {
              Aenea_model_B.i = Aenea_model_B.d_k - 1;
              Aenea_model_B.smax = Aenea_model_B.dist;
            }

            Aenea_model_B.d_k++;
          }

          if (Aenea_model_B.A[Aenea_model_B.caso + Aenea_model_B.i] != 0.0) {
            if (Aenea_model_B.i != 0) {
              Aenea_model_B.i += Aenea_model_B.tolleranza_distWP_fut;
              Aenea_model_B.ipiv_m[Aenea_model_B.tolleranza_distWP_fut] =
                static_cast<int8_T>(Aenea_model_B.i + 1);
              Aenea_model_B.smax =
                Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut];
              Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut] =
                Aenea_model_B.A[Aenea_model_B.i];
              Aenea_model_B.A[Aenea_model_B.i] = Aenea_model_B.smax;
              Aenea_model_B.smax =
                Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut + 4];
              Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut + 4] =
                Aenea_model_B.A[Aenea_model_B.i + 4];
              Aenea_model_B.A[Aenea_model_B.i + 4] = Aenea_model_B.smax;
              Aenea_model_B.smax =
                Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut + 8];
              Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut + 8] =
                Aenea_model_B.A[Aenea_model_B.i + 8];
              Aenea_model_B.A[Aenea_model_B.i + 8] = Aenea_model_B.smax;
              Aenea_model_B.smax =
                Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut + 12];
              Aenea_model_B.A[Aenea_model_B.tolleranza_distWP_fut + 12] =
                Aenea_model_B.A[Aenea_model_B.i + 12];
              Aenea_model_B.A[Aenea_model_B.i + 12] = Aenea_model_B.smax;
            }

            Aenea_model_B.i = (Aenea_model_B.caso -
                               Aenea_model_B.tolleranza_distWP_fut) + 4;
            Aenea_model_B.ix = Aenea_model_B.caso + 1;
            while (Aenea_model_B.ix + 1 <= Aenea_model_B.i) {
              Aenea_model_B.A[Aenea_model_B.ix] /=
                Aenea_model_B.A[Aenea_model_B.caso];
              Aenea_model_B.ix++;
            }
          }

          Aenea_model_B.i = Aenea_model_B.caso;
          Aenea_model_B.ix = Aenea_model_B.caso + 4;
          Aenea_model_B.d_k = 0;
          while (Aenea_model_B.d_k <= 2 - Aenea_model_B.tolleranza_distWP_fut) {
            if (Aenea_model_B.A[Aenea_model_B.ix] != 0.0) {
              Aenea_model_B.smax = -Aenea_model_B.A[Aenea_model_B.ix];
              Aenea_model_B.c_ix = Aenea_model_B.caso + 1;
              Aenea_model_B.e = (Aenea_model_B.i -
                                 Aenea_model_B.tolleranza_distWP_fut) + 8;
              Aenea_model_B.ijA = Aenea_model_B.i + 5;
              while (Aenea_model_B.ijA + 1 <= Aenea_model_B.e) {
                Aenea_model_B.A[Aenea_model_B.ijA] +=
                  Aenea_model_B.A[Aenea_model_B.c_ix] * Aenea_model_B.smax;
                Aenea_model_B.c_ix++;
                Aenea_model_B.ijA++;
              }
            }

            Aenea_model_B.ix += 4;
            Aenea_model_B.i += 4;
            Aenea_model_B.d_k++;
          }
        }

        Aenea_model_B.p[0] = 1;
        Aenea_model_B.p[1] = 2;
        Aenea_model_B.p[2] = 3;
        Aenea_model_B.p[3] = 4;
        if (Aenea_model_B.ipiv_m[0] > 1) {
          Aenea_model_B.tolleranza_distWP_fut =
            Aenea_model_B.p[Aenea_model_B.ipiv_m[0] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_m[0] - 1] = 1;
          Aenea_model_B.p[0] = static_cast<int8_T>
            (Aenea_model_B.tolleranza_distWP_fut);
        }

        if (Aenea_model_B.ipiv_m[1] > 2) {
          Aenea_model_B.tolleranza_distWP_fut =
            Aenea_model_B.p[Aenea_model_B.ipiv_m[1] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_m[1] - 1] = Aenea_model_B.p[1];
          Aenea_model_B.p[1] = static_cast<int8_T>
            (Aenea_model_B.tolleranza_distWP_fut);
        }

        if (Aenea_model_B.ipiv_m[2] > 3) {
          Aenea_model_B.tolleranza_distWP_fut =
            Aenea_model_B.p[Aenea_model_B.ipiv_m[2] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_m[2] - 1] = Aenea_model_B.p[2];
          Aenea_model_B.p[2] = static_cast<int8_T>
            (Aenea_model_B.tolleranza_distWP_fut);
        }

        Aenea_model_B.c_ix = Aenea_model_B.p[0] - 1;
        Aenea_model_B.a[(Aenea_model_B.p[0] - 1) << 2] = 1.0;
        Aenea_model_B.ix = 0;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.c_ix << 2;
          Aenea_model_B.caso = Aenea_model_B.tolleranza_distWP_fut +
            Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.caso] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.d_k = Aenea_model_B.tolleranza_distWP_fut +
                Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.d_k] -=
                Aenea_model_B.a[Aenea_model_B.caso] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        Aenea_model_B.c_ix = Aenea_model_B.p[1] - 1;
        Aenea_model_B.a[((Aenea_model_B.p[1] - 1) << 2) + 1] = 1.0;
        Aenea_model_B.ix = 1;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.c_ix << 2;
          Aenea_model_B.caso = Aenea_model_B.tolleranza_distWP_fut +
            Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.caso] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.d_k = Aenea_model_B.tolleranza_distWP_fut +
                Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.d_k] -=
                Aenea_model_B.a[Aenea_model_B.caso] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        Aenea_model_B.c_ix = Aenea_model_B.p[2] - 1;
        Aenea_model_B.a[((Aenea_model_B.p[2] - 1) << 2) + 2] = 1.0;
        Aenea_model_B.ix = 2;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.c_ix << 2;
          Aenea_model_B.caso = Aenea_model_B.tolleranza_distWP_fut +
            Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.caso] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.d_k = Aenea_model_B.tolleranza_distWP_fut +
                Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.d_k] -=
                Aenea_model_B.a[Aenea_model_B.caso] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        Aenea_model_B.d_k = (Aenea_model_B.p[3] - 1) << 2;
        Aenea_model_B.a[Aenea_model_B.d_k + 3] = 1.0;
        Aenea_model_B.ix = 3;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.d_k +
            Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.tolleranza_distWP_fut] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.caso = Aenea_model_B.d_k + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.caso] -=
                Aenea_model_B.a[Aenea_model_B.tolleranza_distWP_fut] *
                Aenea_model_B.A[(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        for (Aenea_model_B.tolleranza_distWP_fut = 0;
             Aenea_model_B.tolleranza_distWP_fut < 4;
             Aenea_model_B.tolleranza_distWP_fut++) {
          Aenea_model_B.caso = Aenea_model_B.tolleranza_distWP_fut << 2;
          Aenea_model_B.smax = Aenea_model_B.a[Aenea_model_B.caso + 3];
          if (Aenea_model_B.smax != 0.0) {
            Aenea_model_B.a[Aenea_model_B.caso + 3] = Aenea_model_B.smax /
              Aenea_model_B.A[15];
            Aenea_model_B.i = 0;
            while (Aenea_model_B.i <= 2) {
              Aenea_model_B.d_k = Aenea_model_B.i + Aenea_model_B.caso;
              Aenea_model_B.a[Aenea_model_B.d_k] -=
                Aenea_model_B.a[Aenea_model_B.caso + 3] *
                Aenea_model_B.A[Aenea_model_B.i + 12];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.smax = Aenea_model_B.a[Aenea_model_B.caso + 2];
          if (Aenea_model_B.smax != 0.0) {
            Aenea_model_B.a[Aenea_model_B.caso + 2] = Aenea_model_B.smax /
              Aenea_model_B.A[10];
            Aenea_model_B.i = 0;
            while (Aenea_model_B.i <= 1) {
              Aenea_model_B.d_k = Aenea_model_B.i + Aenea_model_B.caso;
              Aenea_model_B.a[Aenea_model_B.d_k] -=
                Aenea_model_B.a[Aenea_model_B.caso + 2] *
                Aenea_model_B.A[Aenea_model_B.i + 8];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.smax = Aenea_model_B.a[Aenea_model_B.caso + 1];
          if (Aenea_model_B.smax != 0.0) {
            Aenea_model_B.a[Aenea_model_B.caso + 1] = Aenea_model_B.smax /
              Aenea_model_B.A[5];
            Aenea_model_B.a[Aenea_model_B.caso] -=
              Aenea_model_B.a[Aenea_model_B.caso + 1] * Aenea_model_B.A[4];
          }

          if (Aenea_model_B.a[Aenea_model_B.caso] != 0.0) {
            Aenea_model_B.a[Aenea_model_B.caso] /= Aenea_model_B.A[0];
          }
        }

        Aenea_model_B.smax = (Aenea_model_DW.x[1] - -100.0) *
          Aenea_model_B.psi_ref + Aenea_model_DW.x[0];
        Aenea_model_B.psi_ref = Aenea_model_B.angoloWP - Aenea_model_B.psi_ref;
        Aenea_model_B.psi_ref_pre = Aenea_model_B.psi_ref_pre *
          Aenea_model_B.Ato_selector + Aenea_model_DW.x[3];
        Aenea_model_B.Ato_selector = Aenea_model_B.Al_selector *
          Aenea_model_B.Ato_selector + -0.1;
        for (Aenea_model_B.tolleranza_distWP_fut = 0;
             Aenea_model_B.tolleranza_distWP_fut < 4;
             Aenea_model_B.tolleranza_distWP_fut++) {
          Aenea_model_B.x_new[Aenea_model_B.tolleranza_distWP_fut] =
            Aenea_model_DW.x[Aenea_model_B.tolleranza_distWP_fut] -
            (((Aenea_model_B.a[Aenea_model_B.tolleranza_distWP_fut + 4] *
               Aenea_model_B.psi_ref +
               Aenea_model_B.a[Aenea_model_B.tolleranza_distWP_fut] *
               Aenea_model_B.smax) +
              Aenea_model_B.a[Aenea_model_B.tolleranza_distWP_fut + 8] *
              Aenea_model_B.psi_ref_pre) +
             Aenea_model_B.a[Aenea_model_B.tolleranza_distWP_fut + 12] *
             Aenea_model_B.Ato_selector);
        }

        Aenea_model_DW.eps[0] = std::abs(Aenea_model_B.x_new[0] -
          Aenea_model_DW.x[0]);
        Aenea_model_DW.eps[1] = std::abs(Aenea_model_B.x_new[1] -
          Aenea_model_DW.x[1]);
        Aenea_model_DW.eps[2] = std::abs(Aenea_model_B.x_new[2] -
          Aenea_model_DW.x[2]);
        Aenea_model_DW.eps[3] = std::abs(Aenea_model_B.x_new[3] -
          Aenea_model_DW.x[3]);
        Aenea_model_DW.x[0] = Aenea_model_B.x_new[0];
        Aenea_model_DW.x[1] = Aenea_model_B.x_new[1];
        Aenea_model_DW.x[2] = Aenea_model_B.x_new[2];
        Aenea_model_DW.x[3] = Aenea_model_B.x_new[3];
        Aenea_model_DW.cycle_count++;
        if (Aenea_model_DW.cycle_count > 10.0) {
          Aenea_model_B.Switch_n = 1;
          exitg1 = true;
        }
      }

      if ((Aenea_model_DW.eps[0] < 0.1) && (Aenea_model_DW.eps[1] < 0.1) &&
          (Aenea_model_DW.eps[2] < 0.1) && (Aenea_model_DW.eps[3] < 0.1)) {
        Aenea_model_B.h_f_out = Aenea_model_DW.x[0];
        Aenea_model_B.x_f_out = Aenea_model_DW.x[1];
        Aenea_model_B.k_x_out = Aenea_model_DW.x[2];
        Aenea_model_B.h_c_out = Aenea_model_DW.x[3];
      } else {
        Aenea_model_B.h_f_out = 0.0;
        Aenea_model_B.x_f_out = 0.0;
        Aenea_model_B.k_x_out = 0.0;
        Aenea_model_B.h_c_out = 0.0;
      }

      Aenea_model_B.no_solution = Aenea_model_B.Switch_n;

      // End of MATLAB Function: '<S448>/MATLAB Function'

      // Product: '<S448>/Multiply' incorporates:
      //   Constant: '<S448>/x_g0'
      //   Gain: '<S448>/Gain'
      //   Sum: '<S448>/Sum1'

      Aenea_model_B.Multiply = -(Aenea_model_B.Vec_selector - -100.0) *
        Aenea_model_B.Wp_selector;

      // Constant: '<S448>/Constant1'
      Aenea_model_B.Constant1_h = 20.0;

      // Update for DiscreteIntegrator: '<S448>/Discrete-Time Integrator'
      Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j += 0.02;
      if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j >= 1.0) {
        Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j = 1.0;
      } else {
        if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j <= 0.0) {
          Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j = 0.0;
        }
      }

      if (Aenea_model_B.trig_approach > 0.0) {
        Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = 1;
      } else if (Aenea_model_B.trig_approach < 0.0) {
        Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = -1;
      } else if (Aenea_model_B.trig_approach == 0.0) {
        Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = 0;
      } else {
        Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
      }

      // End of Update for DiscreteIntegrator: '<S448>/Discrete-Time Integrator' 
    }

    // End of Outputs for SubSystem: '<S437>/APPROACH'

    // Outputs for Enabled SubSystem: '<S437>/FLARE' incorporates:
    //   EnablePort: '<S452>/Enable'

    if (Aenea_model_B.trig_flare > 0.0) {
      // Constant: '<S452>/Constant1'
      Aenea_model_B.Constant1 = 18.0;

      // Sum: '<S452>/Sum2' incorporates:
      //   Gain: '<S452>/Gain'
      //   Math: '<S452>/Exp'
      //   Product: '<S452>/Multiply'
      //   Product: '<S452>/Multiply1'
      //   Sum: '<S452>/Sum'
      //   Sum: '<S452>/Sum1'
      //
      //  About '<S452>/Exp':
      //   Operator: exp

      Aenea_model_B.Sum2 = std::exp(-((Aenea_model_B.Vec_selector -
        Aenea_model_B.x_f_out) * Aenea_model_B.k_x_out)) *
        (Aenea_model_B.h_f_out - Aenea_model_B.h_c_out) + Aenea_model_B.h_c_out;
    }

    // End of Outputs for SubSystem: '<S437>/FLARE'

    // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation5' 
    switch (static_cast<int32_T>(Aenea_model_B.maneuver_selector)) {
     case 1:
      // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation5' incorporates:
      //   Constant: '<S437>/Constant6'

      Aenea_model_B.velocita = 20.0;
      break;

     case 2:
      // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation5' 
      Aenea_model_B.velocita = Aenea_model_B.Constant1_h;
      break;

     default:
      // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation5' 
      Aenea_model_B.velocita = Aenea_model_B.Constant1;
      break;
    }

    // End of MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation5' 

    // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation4' 
    switch (static_cast<int32_T>(Aenea_model_B.maneuver_selector)) {
     case 1:
      // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Constant: '<S437>/Constant2'

      Aenea_model_B.QUOTA_e = 45.0;
      break;

     case 2:
      // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Abs: '<S437>/Abs3'

      Aenea_model_B.QUOTA_e = std::abs(Aenea_model_B.Multiply);
      break;

     default:
      // MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Abs: '<S437>/Abs4'

      Aenea_model_B.QUOTA_e = std::abs(Aenea_model_B.Sum2);
      break;
    }

    // End of MultiPortSwitch: '<S437>/Switch di selezione  Task - Waypoint navigation4' 

    // Update for Memory: '<S437>/Memory5'
    Aenea_model_DW.Memory5_PreviousInput = Aenea_model_B.x_f_out;

    // Update for Memory: '<S437>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput_f = Aenea_model_B.h_f_out;

    // Update for Memory: '<S437>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput_e = Aenea_model_B.no_solution;
  }

  // End of Outputs for SubSystem: '<S34>/Subsystem1'

  // Outputs for Enabled SubSystem: '<S34>/Subsystem3' incorporates:
  //   EnablePort: '<S439>/Enable'

  if (Aenea_model_B.Sum_fj > 0.0) {
    // Gain: '<S544>/Gain'
    Aenea_model_B.Sum_fj = 57.295779513082323 * Aenea_model_B.Lat_K;

    // MATLAB Function: '<S439>/GO_HOME' incorporates:
    //   Constant: '<S34>/Constant'
    //   Constant: '<S34>/Constant1'
    //   Gain: '<S545>/Gain'

    Aenea_model_B.a_c = std::sin((0.0 - Aenea_model_B.Sum_fj) *
      3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.dist = std::sin((0.0 - 57.295779513082323 *
      Aenea_model_B.Long_K) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.a_c = std::cos(Aenea_model_B.Sum_fj * 3.1415926535897931 /
      180.0) * (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_c *
      Aenea_model_B.a_c;
    Aenea_model_B.h_goHome = 70.0;
    Aenea_model_B.V_goHome = 20.0;
    if ((rt_atan2d_snf(std::sqrt(Aenea_model_B.a_c), std::sqrt(1.0 -
           Aenea_model_B.a_c)) * 2.0 * 6.378137E+6 < 30.0) &&
        (Aenea_model_DW.flag == 0.0)) {
      Aenea_model_DW.flag = 1.0;
      Aenea_model_B.h_goHome = 70.4;
    }

    // End of MATLAB Function: '<S439>/GO_HOME'
  }

  // End of Outputs for SubSystem: '<S34>/Subsystem3'

  // MultiPortSwitch: '<S34>/Switch di selezione  Task - Waypoint navigation1'
  switch (static_cast<int32_T>(Aenea_model_B.modo)) {
   case 1:
    Aenea_model_B.Sum_fj = Aenea_model_B.VELOCITA;
    break;

   case 2:
    Aenea_model_B.Sum_fj = Aenea_model_B.V_vett;
    break;

   case 3:
    Aenea_model_B.Sum_fj = Aenea_model_B.Tas_ref;
    break;

   case 4:
    Aenea_model_B.Sum_fj = Aenea_model_B.velocita;
    break;

   default:
    Aenea_model_B.Sum_fj = Aenea_model_B.V_goHome;
    break;
  }

  // End of MultiPortSwitch: '<S34>/Switch di selezione  Task - Waypoint navigation1' 

  // Sum: '<S37>/Sum3'
  Aenea_model_B.Sum_fj -= Aenea_model_B.Product1;

  // Sum: '<S289>/Sum' incorporates:
  //   DiscreteIntegrator: '<S280>/Integrator'
  //   Product: '<S285>/PProd Out'

  Aenea_model_B.a_c = Aenea_model_B.Sum_fj * 0.033649999648332596 +
    Aenea_model_DW.Integrator_DSTATE;

  // Saturate: '<S287>/Saturation'
  if (Aenea_model_B.a_c > 1.0) {
    Aenea_model_B.Product1 = 1.0;
  } else if (Aenea_model_B.a_c < 0.0) {
    Aenea_model_B.Product1 = 0.0;
  } else {
    Aenea_model_B.Product1 = Aenea_model_B.a_c;
  }

  // End of Saturate: '<S287>/Saturation'

  // Sum: '<S579>/Sum5' incorporates:
  //   DataTypeConversion: '<S7>/Data Type Conversion12'
  //   DataTypeConversion: '<S7>/Data Type Conversion4'
  //   Product: '<S579>/Divide2'
  //   Sum: '<S579>/Sum2'
  //   Sum: '<S579>/Sum3'

  Aenea_model_B.Vec_selector = (Aenea_model_ConstB.DataTypeConversion5 -
    static_cast<real_T>(Aenea_model_B.ByteUnpack[1])) / static_cast<real_T>
    (Aenea_model_B.ByteUnpack[0] - Aenea_model_B.ByteUnpack[1]);

  // MATLAB Function: '<S245>/Smooth Bypass' incorporates:
  //   SignalConversion generated from: '<S245>/Vector Concatenate'

  if (Aenea_model_B.switch_manetta == 0.0) {
    Aenea_model_B.Wp_selector = Aenea_model_B.Product1;
    Aenea_model_DW.Delay_DSTATE = Aenea_model_B.Delta_clock;
  } else {
    if (Aenea_model_B.switch_manetta != Aenea_model_B.switch_manetta) {
      Aenea_model_DW.Delay_DSTATE = Aenea_model_B.Delta_clock;
    }

    Aenea_model_B.Delta_clock -= Aenea_model_DW.Delay_DSTATE;
    if (Aenea_model_B.Delta_clock < 1.3) {
      if (Aenea_model_B.Delta_clock < 0.2) {
        Aenea_model_B.Wp_selector = Aenea_model_B.Vec_selector;
      } else {
        Aenea_model_B.Wp_selector = (Aenea_model_B.Delta_clock - 0.2) / 1.1 *
          (Aenea_model_B.Product1 - Aenea_model_B.Vec_selector) +
          Aenea_model_B.Vec_selector;
      }
    } else {
      Aenea_model_B.Wp_selector = Aenea_model_B.Product1;
    }
  }

  // End of MATLAB Function: '<S245>/Smooth Bypass'

  // MultiPortSwitch: '<S245>/Switch Bumpless 1'
  if (static_cast<int32_T>(Aenea_model_B.switch_manetta) == 0) {
    Aenea_model_B.Wp_selector = Aenea_model_B.Vec_selector;
  }

  // End of MultiPortSwitch: '<S245>/Switch Bumpless 1'

  // MultiPortSwitch: '<S34>/Switch di selezione  Task - Waypoint navigation2'
  switch (static_cast<int32_T>(Aenea_model_B.modo)) {
   case 1:
    Aenea_model_B.Delta_clock = Aenea_model_B.QUOTA;
    break;

   case 2:
    Aenea_model_B.Delta_clock = Aenea_model_B.h_vett;
    break;

   case 3:
    Aenea_model_B.Delta_clock = Aenea_model_B.h_ref;
    break;

   case 4:
    Aenea_model_B.Delta_clock = Aenea_model_B.QUOTA_e;
    break;

   default:
    Aenea_model_B.Delta_clock = Aenea_model_B.h_goHome;
    break;
  }

  // End of MultiPortSwitch: '<S34>/Switch di selezione  Task - Waypoint navigation2' 

  // HitCross: '<S246>/Hit  Crossing'
  Aenea_model_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &Aenea_model_PrevZCX.HitCrossing_Input_ZCE,
    (Aenea_model_B.Delta_clock - 0.3));
  if (Aenea_model_DW.HitCrossing_MODE == 0) {
    if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
      // HitCross: '<S246>/Hit  Crossing'
      Aenea_model_B.HitCrossing = !Aenea_model_B.HitCrossing;
      Aenea_model_DW.HitCrossing_MODE = 1;
    } else {
      if (Aenea_model_B.HitCrossing) {
        // HitCross: '<S246>/Hit  Crossing'
        Aenea_model_B.HitCrossing = ((!(Aenea_model_B.Delta_clock != 0.3)) &&
          Aenea_model_B.HitCrossing);
      }
    }
  } else {
    // HitCross: '<S246>/Hit  Crossing'
    Aenea_model_B.HitCrossing = ((!(Aenea_model_B.Delta_clock != 0.3)) &&
      Aenea_model_B.HitCrossing);
    Aenea_model_DW.HitCrossing_MODE = 0;
  }

  // End of HitCross: '<S246>/Hit  Crossing'

  // Outputs for Triggered SubSystem: '<S246>/Enabled Subsystem' incorporates:
  //   TriggerPort: '<S298>/Trigger'

  if (Aenea_model_B.HitCrossing &&
      (Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE != 1)) {
    // SignalConversion generated from: '<S298>/Out1' incorporates:
    //   Constant: '<S298>/Constant'

    Aenea_model_B.OutportBufferForOut1 = 0.0;
  }

  Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE = Aenea_model_B.HitCrossing;

  // End of Outputs for SubSystem: '<S246>/Enabled Subsystem'

  // MATLAB Function: '<S33>/MATLAB Function'
  if (Aenea_model_B.modo == 3.0) {
    Aenea_model_B.Switch_n = 1;
    Aenea_model_B.tolleranza_distWP_fut = 0;
  } else if (Aenea_model_B.modo == 4.0) {
    Aenea_model_B.tolleranza_distWP_fut = 1;
    Aenea_model_B.Switch_n = 0;
  } else {
    Aenea_model_B.Switch_n = 0;
    Aenea_model_B.tolleranza_distWP_fut = 0;
  }

  // MultiPortSwitch: '<S31>/Switch di selezione riferimeti  per i loop interni 1' 
  if (static_cast<int32_T>(Aenea_model_B.Switch) == 0) {
    // MultiPortSwitch: '<S246>/throttle - landing' incorporates:
    //   MATLAB Function: '<S33>/MATLAB Function'

    if (Aenea_model_B.tolleranza_distWP_fut != 0) {
      // Switch: '<S246>/Switch' incorporates:
      //   Constant: '<S246>/Constant3'

      if (!(Aenea_model_B.OutportBufferForOut1 > 0.0)) {
        Aenea_model_B.Wp_selector = 0.0;
      }

      // End of Switch: '<S246>/Switch'
    }

    // End of MultiPortSwitch: '<S246>/throttle - landing'
  } else {
    Aenea_model_B.Wp_selector = Aenea_model_B.throttle_safe;
  }

  // End of MultiPortSwitch: '<S31>/Switch di selezione riferimeti  per i loop interni 1' 

  // DiscreteIntegrator: '<S302>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S302>/Constant8'
  //   Sum: '<S302>/Sum'

  if ((Aenea_model_B.Fase_ATO - 1.0 > 0.0) &&
      (Aenea_model_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    Aenea_model_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE >= 0.6) {
    Aenea_model_DW.DiscreteTimeIntegrator_DSTATE = 0.6;
  } else {
    if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE <= 0.0) {
      Aenea_model_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
    }
  }

  // MultiPortSwitch: '<S302>/Multiport Switch1' incorporates:
  //   MATLAB Function: '<S33>/MATLAB Function'

  if (Aenea_model_B.Switch_n != 0) {
    // MultiPortSwitch: '<S302>/Switch Bumpless 1' incorporates:
    //   Constant: '<S302>/Constant4'
    //   DiscreteIntegrator: '<S302>/Discrete-Time Integrator'

    switch (static_cast<int32_T>(Aenea_model_B.Fase_ATO)) {
     case 0:
      Aenea_model_B.Wp_selector = 0.0;
      break;

     case 1:
      Aenea_model_B.Wp_selector = Aenea_model_B.manetta_ref;
      break;

     case 2:
      Aenea_model_B.Wp_selector = Aenea_model_DW.DiscreteTimeIntegrator_DSTATE;
      break;

     case 3:
      break;
    }

    // End of MultiPortSwitch: '<S302>/Switch Bumpless 1'
  }

  // End of MultiPortSwitch: '<S302>/Multiport Switch1'

  // Sum: '<S292>/SumI1' incorporates:
  //   Product: '<S277>/IProd Out'
  //   Sum: '<S291>/SumI3'

  Aenea_model_B.Wp_selector = Aenea_model_B.Sum_fj * 0.00800000037997961 +
    (Aenea_model_B.Wp_selector - Aenea_model_B.Product1);

  // DeadZone: '<S273>/DeadZone'
  if (Aenea_model_B.a_c > 1.0) {
    Aenea_model_B.Al_selector = Aenea_model_B.a_c - 1.0;
  } else if (Aenea_model_B.a_c >= 0.0) {
    Aenea_model_B.Al_selector = 0.0;
  } else {
    Aenea_model_B.Al_selector = Aenea_model_B.a_c;
  }

  // End of DeadZone: '<S273>/DeadZone'

  // Signum: '<S271>/SignPreSat'
  if (Aenea_model_B.Al_selector < 0.0) {
    // DataTypeConversion: '<S271>/DataTypeConv1'
    Aenea_model_B.smax = -1.0;
  } else if (Aenea_model_B.Al_selector > 0.0) {
    // DataTypeConversion: '<S271>/DataTypeConv1'
    Aenea_model_B.smax = 1.0;
  } else if (Aenea_model_B.Al_selector == 0.0) {
    // DataTypeConversion: '<S271>/DataTypeConv1'
    Aenea_model_B.smax = 0.0;
  } else {
    // DataTypeConversion: '<S271>/DataTypeConv1'
    Aenea_model_B.smax = (rtNaN);
  }

  // End of Signum: '<S271>/SignPreSat'

  // DataTypeConversion: '<S271>/DataTypeConv1'
  if (rtIsNaN(Aenea_model_B.smax)) {
    Aenea_model_B.smax = 0.0;
  } else {
    Aenea_model_B.smax = std::fmod(Aenea_model_B.smax, 256.0);
  }

  // Signum: '<S271>/SignPreIntegrator'
  if (Aenea_model_B.Wp_selector < 0.0) {
    // DataTypeConversion: '<S271>/DataTypeConv2'
    Aenea_model_B.Product1 = -1.0;
  } else if (Aenea_model_B.Wp_selector > 0.0) {
    // DataTypeConversion: '<S271>/DataTypeConv2'
    Aenea_model_B.Product1 = 1.0;
  } else if (Aenea_model_B.Wp_selector == 0.0) {
    // DataTypeConversion: '<S271>/DataTypeConv2'
    Aenea_model_B.Product1 = 0.0;
  } else {
    // DataTypeConversion: '<S271>/DataTypeConv2'
    Aenea_model_B.Product1 = (rtNaN);
  }

  // End of Signum: '<S271>/SignPreIntegrator'

  // DataTypeConversion: '<S271>/DataTypeConv2'
  if (rtIsNaN(Aenea_model_B.Product1)) {
    Aenea_model_B.Product1 = 0.0;
  } else {
    Aenea_model_B.Product1 = std::fmod(Aenea_model_B.Product1, 256.0);
  }

  // Switch: '<S271>/Switch' incorporates:
  //   Constant: '<S271>/Constant1'
  //   DataTypeConversion: '<S271>/DataTypeConv1'
  //   DataTypeConversion: '<S271>/DataTypeConv2'
  //   Gain: '<S271>/ZeroGain'
  //   Logic: '<S271>/AND3'
  //   RelationalOperator: '<S271>/Equal1'
  //   RelationalOperator: '<S271>/NotEqual'

  if ((0.0 * Aenea_model_B.a_c != Aenea_model_B.Al_selector) &&
      ((Aenea_model_B.smax < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-
          static_cast<int8_T>(static_cast<uint8_T>(-Aenea_model_B.smax)))) :
        static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>
          (Aenea_model_B.smax)))) == (Aenea_model_B.Product1 < 0.0 ?
        static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(
           static_cast<uint8_T>(-Aenea_model_B.Product1)))) :
        static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>
          (Aenea_model_B.Product1)))))) {
    Aenea_model_B.Product1 = 0.0;
  } else {
    Aenea_model_B.Product1 = Aenea_model_B.Wp_selector;
  }

  // End of Switch: '<S271>/Switch'

  // Sum: '<S35>/Sum1'
  Aenea_model_B.Wp_selector = Aenea_model_B.Delta_clock - Aenea_model_B.h_K;

  // Abs: '<S35>/Abs'
  Aenea_model_B.Delta_clock = std::abs(Aenea_model_B.Wp_selector);

  // Chart: '<S35>/SELEZIONE MODALITA'  HOLD//SELECT'
  if (Aenea_model_DW.is_active_c23_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c23_Aenea_model = 1U;
    Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Select;
  } else if (Aenea_model_DW.is_c23_Aenea_model == 1) {
    if (Aenea_model_B.Delta_clock > 10.0) {
      Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Select;
    }
  } else {
    // case IN_Select:
    if (Aenea_model_B.Delta_clock < 10.0) {
      Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Hold;
    }
  }

  // End of Chart: '<S35>/SELEZIONE MODALITA'  HOLD//SELECT'

  // Outputs for Resettable SubSystem: '<S405>/Resettable Subsystem'
  Aenea_model_ResettableSubsystem(0, &Aenea_model_B.Wp_selector,
    &Aenea_model_DW.ResettableSubsystem,
    &Aenea_model_PrevZCX.ResettableSubsystem);

  // End of Outputs for SubSystem: '<S405>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S405>/Enabled Subsystem'
  Aenea_model_EnabledSubsystem(0, Aenea_model_B.Wp_selector,
    &Aenea_model_B.Delta_clock);

  // End of Outputs for SubSystem: '<S405>/Enabled Subsystem'

  // MATLAB Function: '<S407>/MATLAB Function1'
  Aenea_model_DW.Tf_not_empty = ((!Aenea_model_DW.Tf_not_empty) ||
    (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) ||
    (Aenea_model_DW.Memory2_PreviousInput_d[1] == 0) ||
    Aenea_model_DW.Tf_not_empty);

  // Sum: '<S554>/Sum1' incorporates:
  //   Constant: '<S4>/tas'
  //   MATLAB Function: '<S554>/MATLAB Function'
  //   Product: '<S554>/Product4'
  //   Sum: '<S554>/Sum'
  //   UnitDelay: '<S554>/Unit Delay'

  Aenea_model_DW.UnitDelay_DSTATE_c = (Aenea_model_DW.UnitDelay_DSTATE_c + 1.0) *
    0.23456790123456794 + 1.0;

  // Sum: '<S567>/Difference Inputs1' incorporates:
  //   MATLAB Function: '<S564>/MATLAB Function'
  //   UnitDelay: '<S567>/Delay Input2'
  //
  //  Block description for '<S567>/Difference Inputs1':
  //
  //   Add in CPU
  //
  //  Block description for '<S567>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_B.Delta_clock = Aenea_model_DW.P_ref -
    Aenea_model_DW.DelayInput2_DSTATE;

  // Product: '<S567>/delta rise limit' incorporates:
  //   MATLAB Function: '<S564>/MATLAB Function'
  //   SampleTimeMath: '<S567>/sample time'
  //
  //  About '<S567>/sample time':
  //   y = K where K = ( w * Ts )

  Aenea_model_B.Wp_selector = Aenea_model_DW.rl_up * 0.02;

  // Switch: '<S571>/Switch2' incorporates:
  //   RelationalOperator: '<S571>/LowerRelop1'

  if (!(Aenea_model_B.Delta_clock > Aenea_model_B.Wp_selector)) {
    // Product: '<S567>/delta fall limit' incorporates:
    //   MATLAB Function: '<S564>/MATLAB Function'
    //   SampleTimeMath: '<S567>/sample time'
    //
    //  About '<S567>/sample time':
    //   y = K where K = ( w * Ts )

    Aenea_model_B.Wp_selector = Aenea_model_DW.rl_dw * 0.02;

    // Switch: '<S571>/Switch' incorporates:
    //   RelationalOperator: '<S571>/UpperRelop'

    if (!(Aenea_model_B.Delta_clock < Aenea_model_B.Wp_selector)) {
      Aenea_model_B.Wp_selector = Aenea_model_B.Delta_clock;
    }

    // End of Switch: '<S571>/Switch'
  }

  // End of Switch: '<S571>/Switch2'

  // Sum: '<S567>/Difference Inputs2' incorporates:
  //   UnitDelay: '<S567>/Delay Input2'
  //
  //  Block description for '<S567>/Difference Inputs2':
  //
  //   Add in CPU
  //
  //  Block description for '<S567>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_DW.DelayInput2_DSTATE += Aenea_model_B.Wp_selector;
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    // Switch: '<S22>/Switch1' incorporates:
    //   Constant: '<S22>/Constant4'
    //   Constant: '<S22>/Constant5'
    //   Memory: '<S22>/Memory2'
    //   Sum: '<S22>/Add2'

    if (Aenea_model_DW.Memory2_PreviousInput + 1.0 > 9.0) {
      Aenea_model_B.Switch1_g = 0.0;
    } else {
      Aenea_model_B.Switch1_g = Aenea_model_DW.Memory2_PreviousInput + 1.0;
    }

    // End of Switch: '<S22>/Switch1'
  }

  // Update for Memory: '<S1>/Memory4'
  std::memcpy(&Aenea_model_DW.Memory4_PreviousInput_j[0], &Aenea_model_B.buffer
              [0], 300U * sizeof(uint8_T));

  // Update for Memory: '<S1>/Memory5'
  std::memcpy(&Aenea_model_DW.Memory5_PreviousInput_b[0],
              &Aenea_model_B.messaggio[0], 100U * sizeof(uint8_T));

  // Update for UnitDelay: '<S564>/Unit Delay1' incorporates:
  //   UnitDelay: '<S567>/Delay Input2'
  //
  //  Block description for '<S567>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_DW.UnitDelay1_DSTATE = Aenea_model_DW.DelayInput2_DSTATE;

  // Update for Memory: '<S558>/Memory' incorporates:
  //   DataTypeConversion: '<S568>/Data Type Conversion2'

  Aenea_model_DW.Memory_PreviousInput[0] = Aenea_model_B.Lat;
  Aenea_model_DW.Memory_PreviousInput[1] = Aenea_model_B.Long;

  // Outputs for Atomic SubSystem: '<S564>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput[2] = Aenea_model_B.SFunctionBuilder_o3;

  // End of Outputs for SubSystem: '<S564>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput[3] = Aenea_model_B.num_254;
  Aenea_model_DW.Memory_PreviousInput[4] = Aenea_model_B.V_est;
  Aenea_model_DW.Memory_PreviousInput[5] = Aenea_model_B.DataTypeConversion1[6];
  Aenea_model_DW.Memory_PreviousInput[6] = Aenea_model_B.DataTypeConversion1[7];
  Aenea_model_DW.Memory_PreviousInput[7] = Aenea_model_B.DataTypeConversion1[8];

  // Update for Memory: '<S557>/Memory' incorporates:
  //   DataTypeConversion: '<S568>/Data Type Conversion2'

  Aenea_model_DW.Memory_PreviousInput_o[0] = Aenea_model_B.Lat;
  Aenea_model_DW.Memory_PreviousInput_o[1] = Aenea_model_B.Long;

  // Outputs for Atomic SubSystem: '<S564>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_o[2] = Aenea_model_B.SFunctionBuilder_o3;

  // End of Outputs for SubSystem: '<S564>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_o[3] = Aenea_model_B.num_254;
  Aenea_model_DW.Memory_PreviousInput_o[4] = Aenea_model_B.V_est;
  Aenea_model_DW.Memory_PreviousInput_o[5] = Aenea_model_B.DataTypeConversion1[6];
  Aenea_model_DW.Memory_PreviousInput_o[6] = Aenea_model_B.DataTypeConversion1[7];
  Aenea_model_DW.Memory_PreviousInput_o[7] = Aenea_model_B.DataTypeConversion1[8];
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // Update for Memory: '<S558>/Memory'
    Aenea_model_B.Delta_clock =
      Aenea_model_B.DataTypeConversion1[Aenea_model_B.i];
    Aenea_model_DW.Memory_PreviousInput[Aenea_model_B.i + 8] =
      Aenea_model_B.Delta_clock;

    // Update for Memory: '<S557>/Memory'
    Aenea_model_DW.Memory_PreviousInput_o[Aenea_model_B.i + 8] =
      Aenea_model_B.Delta_clock;
  }

  // Update for DiscreteIntegrator: '<S280>/Integrator'
  Aenea_model_DW.Integrator_DSTATE += 0.02 * Aenea_model_B.Product1;

  // Update for DiscreteIntegrator: '<S302>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S302>/Constant7'
  //   Constant: '<S302>/Constant8'
  //   Sum: '<S302>/Sum'

  Aenea_model_DW.DiscreteTimeIntegrator_DSTATE += 0.0029999999999999996;
  if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE >= 0.6) {
    Aenea_model_DW.DiscreteTimeIntegrator_DSTATE = 0.6;
  } else {
    if (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE <= 0.0) {
      Aenea_model_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
    }
  }

  if (Aenea_model_B.Fase_ATO - 1.0 > 0.0) {
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (Aenea_model_B.Fase_ATO - 1.0 < 0.0) {
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (Aenea_model_B.Fase_ATO - 1.0 == 0.0) {
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  // End of Update for DiscreteIntegrator: '<S302>/Discrete-Time Integrator'

  // Switch: '<S22>/Switch' incorporates:
  //   Constant: '<S22>/Constant3'
  //   Memory: '<S22>/Memory1'
  //   Sum: '<S22>/Add1'

  if (Aenea_model_DW.Memory1_PreviousInput + 1.0 > 4.0) {
    // Update for Memory: '<S22>/Memory1' incorporates:
    //   Constant: '<S22>/Constant2'

    Aenea_model_DW.Memory1_PreviousInput = 0.0;
  } else {
    // Update for Memory: '<S22>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput++;
  }

  // End of Switch: '<S22>/Switch'

  // Update for RateTransition: '<S22>/Rate Transition'
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    Aenea_model_DW.RateTransition_Buffer0 = Aenea_model_B.Switch1_g;

    // Update for Memory: '<S22>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput = Aenea_model_B.Switch1_g;
  }

  // End of Update for RateTransition: '<S22>/Rate Transition'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.02, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  Aenea_model_M->Timing.clockTick0++;
  rate_scheduler();
}

// Model initialize function
void Aenea_model_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    // Start for S-Function (Mti_sfun): '<S566>/S-Function Builder1'

    // S-Function Block: <S566>/S-Function Builder1
    Mti_sfun_Start_wrapper();

    // Start for S-Function (GPS_sfun): '<S565>/S-Function Builder'

    // S-Function Block: <S565>/S-Function Builder
    GPS_sfun_Start_wrapper();
    Aenea_model_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
    Aenea_model_PrevZCX.ResettableSubsystem_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.ResettableSubsystem_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.ResettableSubsystem_Reset_ZCE = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_a = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_l = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Aenea_model_PrevZCX.ResettableSubsystem_j.ResettableSubsystem_Reset_ZCE_k =
      POS_ZCSIG;
    Aenea_model_PrevZCX.ResettableSubsystem.ResettableSubsystem_Reset_ZCE_k =
      POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S564>/Unit Delay1'
    Aenea_model_DW.UnitDelay1_DSTATE = 101440.0;

    // InitializeConditions for DiscreteIntegrator: '<S302>/Discrete-Time Integrator' 
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for UnitDelay: '<S567>/Delay Input2'
    //
    //  Block description for '<S567>/Delay Input2':
    //
    //   Store in Global RAM

    Aenea_model_DW.DelayInput2_DSTATE = 101325.0;

    // InitializeConditions for Memory: '<S22>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput = -1.0;

    // InitializeConditions for Memory: '<S22>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput = -1.0;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1'
    std::memcpy(&Aenea_model_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    // SystemInitialize for Atomic SubSystem: '<S564>/Execution_loop'
    // Start for S-Function (BMP280_sfun): '<S568>/S-Function Builder'

    // S-Function Block: <S568>/S-Function Builder
    BMP280_sfun_Start_wrapper();

    // End of SystemInitialize for SubSystem: '<S564>/Execution_loop'

    // SystemInitialize for Chart: '<S33>/ STATI'
    Aenea_model_B.modo = 1.0;

    // SystemInitialize for Enabled SubSystem: '<S34>/Subsystem2'
    // InitializeConditions for Memory: '<S438>/Memory4'
    Aenea_model_DW.Memory4_PreviousInput = 1.0;

    // End of SystemInitialize for SubSystem: '<S34>/Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S34>/Subsystem1'
    // InitializeConditions for Memory: '<S437>/Memory7'
    Aenea_model_DW.Memory7_PreviousInput = 1.0;

    // SystemInitialize for Enabled SubSystem: '<S437>/APPROACH'
    // Start for Constant: '<S448>/Constant1'
    Aenea_model_B.Constant1_h = 20.0;

    // InitializeConditions for DiscreteIntegrator: '<S448>/Discrete-Time Integrator' 
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

    // End of SystemInitialize for SubSystem: '<S437>/APPROACH'

    // SystemInitialize for Enabled SubSystem: '<S437>/FLARE'
    // Start for Constant: '<S452>/Constant1'
    Aenea_model_B.Constant1 = 18.0;

    // End of SystemInitialize for SubSystem: '<S437>/FLARE'
    // End of SystemInitialize for SubSystem: '<S34>/Subsystem1'

    // SystemInitialize for Triggered SubSystem: '<S246>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S298>/Out1' incorporates:
    //   Outport: '<S298>/Out1'

    Aenea_model_B.OutportBufferForOut1 = 1.0;

    // End of SystemInitialize for SubSystem: '<S246>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S564>/MATLAB Function'
    Aenea_model_DW.P_ref = 102600.0;
    Aenea_model_DW.rl_up = 300.0;
    Aenea_model_DW.rl_dw = -300.0;
  }
}

// Model terminate function
void Aenea_model_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S564>/Execution_loop'

  // Terminate for S-Function (BMP280_sfun): '<S568>/S-Function Builder'

  // S-Function Block: <S568>/S-Function Builder
  BMP280_sfun_Terminate_wrapper();

  // End of Terminate for SubSystem: '<S564>/Execution_loop'
}

//
// File trailer for generated code.
//
// [EOF]
//
