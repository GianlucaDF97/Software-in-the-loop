//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.cpp
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.64
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Nov 24 13:33:36 2022
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Aenea_model.h"
#include "Aenea_model_private.h"

// Named constants for Chart: '<S36>/SELEZIONE MODALITA\'  HOLD//SELECT'
const uint8_T Aenea_model_IN_Hold = 1U;
const uint8_T Aenea_model_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T Aenea_model_IN_Select = 2U;

// Named constants for Chart: '<S34>/ STATI'
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

// Named constants for Chart: '<S35>/Chart'
const uint8_T Aenea_model_IN_AutoLanding = 1U;
const uint8_T Aenea_model_IN_AutoTakeoff = 2U;
const uint8_T Aenea_model_IN_GoHome = 3U;
const uint8_T Aenea_model_IN_In = 4U;
const uint8_T Aenea_model_IN_Vettoriale = 5U;
const uint8_T Aenea_model_IN_Waypoint = 6U;

// Named constants for Chart: '<S436>/Chart1'
const uint8_T Aenea_model_IN_Fase_0_ATO = 1U;
const uint8_T Aenea_model_IN_Fase_1_ATO = 2U;
const uint8_T Aenea_model_IN_Fase_2_ATO = 3U;
const uint8_T Aenea_model_IN_Fase_3_ATO = 4U;
const uint8_T Aenea_model_IN_Fase_4_ATO = 5U;

// Named constants for Chart: '<S438>/Chart1'
const uint8_T Aenea_model_IN_Abort = 1U;
const uint8_T Aenea_model_IN_Allignment = 2U;
const uint8_T Aenea_model_IN_Allignment1 = 3U;
const uint8_T Aenea_model_IN_Approach = 4U;
const uint8_T Aenea_model_IN_Flare = 5U;
const real32_T Aenea_model_R32GND = 0.0F;// real32_T ground
const uint16_T Aenea_model_U16GND = 0U;// uint16_T ground

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
static void Aenea_model_Waypoint(const boolean_T *Ap_sel, real_T *Ato_selector,
  real_T *Al_selector, real_T *Wp_selector, real_T *Vec_selector, real_T
  *Go_home_selector);
static void Aenea_model_In(const boolean_T *Ap_sel, real_T *Ato_selector, real_T
  *Al_selector, real_T *Wp_selector, real_T *Vec_selector, real_T
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
//    '<S406>/Enabled Subsystem'
//    '<S407>/Enabled Subsystem'
//
void Aenea_model_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0)
{
  // Outputs for Enabled SubSystem: '<S406>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S415>/Enable'

  if (rtu_Enable > 0) {
    // Switch: '<S415>/Switch'
    *rty_u0 = !(rtu_Time > 2.0);
  }

  // End of Outputs for SubSystem: '<S406>/Enabled Subsystem'
}

//
// System reset for atomic system:
//    '<S406>/Resettable Subsystem'
//    '<S407>/Resettable Subsystem'
//
void Aenea_ResettableSubsystem_Reset(DW_ResettableSubsystem_Aenea__T *localDW)
{
  // InitializeConditions for Memory: '<S417>/Memory'
  localDW->Memory_PreviousInput = 0.0;
}

//
// Output and update for atomic system:
//    '<S406>/Resettable Subsystem'
//    '<S407>/Resettable Subsystem'
//
void Aenea_model_ResettableSubsystem(uint8_T rtu_Reset, real_T *rty_Time,
  DW_ResettableSubsystem_Aenea__T *localDW, ZCE_ResettableSubsystem_Aenea_T
  *localZCE)
{
  // Outputs for Resettable SubSystem: '<S406>/Resettable Subsystem' incorporates:
  //   ResetPort: '<S416>/Reset'

  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_k != POS_ZCSIG))
  {
    Aenea_ResettableSubsystem_Reset(localDW);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_k = (rtu_Reset > 0);

  // Sum: '<S417>/Sum' incorporates:
  //   Constant: '<S417>/Constant4'
  //   Memory: '<S417>/Memory'

  *rty_Time = localDW->Memory_PreviousInput + 0.02;

  // Update for Memory: '<S417>/Memory'
  localDW->Memory_PreviousInput = *rty_Time;

  // End of Outputs for SubSystem: '<S406>/Resettable Subsystem'
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

// Function for MATLAB Function: '<S553>/DEFINITIVA'
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
    Aenea_model_B.smax = std::abs(A[c]);
    for (iy = 2; iy <= 11 - j; iy++) {
      ix++;
      Aenea_model_B.y_p = std::abs(A[ix]);
      if (Aenea_model_B.y_p > Aenea_model_B.smax) {
        jA = iy - 1;
        Aenea_model_B.smax = Aenea_model_B.y_p;
      }
    }

    if (A[c + jA] != 0.0) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = iy + 1;
        ix = j;
        for (jA = 0; jA < 11; jA++) {
          Aenea_model_B.smax = A[ix];
          A[ix] = A[iy];
          A[iy] = Aenea_model_B.smax;
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
        Aenea_model_B.smax = -A[ix];
        c_ix = c + 1;
        d = (jA - j) + 22;
        for (ijA = jA + 12; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * Aenea_model_B.smax;
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

// Function for MATLAB Function: '<S553>/DEFINITIVA'
static int32_T Aenea_model_xgetrfs(real_T A[121], real_T B[198])
{
  int32_T b_i;
  int32_T info;
  int32_T ipiv;
  int32_T kAcol;
  int32_T tmp;
  Aenea_model_xgetrf(A, Aenea_model_B.ipiv, &info);
  for (Aenea_model_B.i_p = 0; Aenea_model_B.i_p < 10; Aenea_model_B.i_p++) {
    ipiv = Aenea_model_B.ipiv[Aenea_model_B.i_p];
    if (Aenea_model_B.i_p + 1 != ipiv) {
      for (Aenea_model_B.j = 0; Aenea_model_B.j < 18; Aenea_model_B.j++) {
        Aenea_model_B.jBcol = 11 * Aenea_model_B.j + Aenea_model_B.i_p;
        Aenea_model_B.temp = B[Aenea_model_B.jBcol];
        tmp = (ipiv + 11 * Aenea_model_B.j) - 1;
        B[Aenea_model_B.jBcol] = B[tmp];
        B[tmp] = Aenea_model_B.temp;
      }
    }
  }

  for (Aenea_model_B.j = 0; Aenea_model_B.j < 18; Aenea_model_B.j++) {
    Aenea_model_B.jBcol = 11 * Aenea_model_B.j;
    for (ipiv = 0; ipiv < 11; ipiv++) {
      kAcol = 11 * ipiv;
      tmp = ipiv + Aenea_model_B.jBcol;
      if (B[tmp] != 0.0) {
        for (b_i = ipiv + 2; b_i < 12; b_i++) {
          Aenea_model_B.i_p = (b_i + Aenea_model_B.jBcol) - 1;
          B[Aenea_model_B.i_p] -= A[(b_i + kAcol) - 1] * B[tmp];
        }
      }
    }
  }

  for (Aenea_model_B.j = 0; Aenea_model_B.j < 18; Aenea_model_B.j++) {
    Aenea_model_B.jBcol = 11 * Aenea_model_B.j;
    for (ipiv = 10; ipiv >= 0; ipiv--) {
      kAcol = 11 * ipiv;
      tmp = ipiv + Aenea_model_B.jBcol;
      Aenea_model_B.temp = B[tmp];
      if (Aenea_model_B.temp != 0.0) {
        B[tmp] = Aenea_model_B.temp / A[ipiv + kAcol];
        for (b_i = 0; b_i < ipiv; b_i++) {
          Aenea_model_B.i_p = b_i + Aenea_model_B.jBcol;
          B[Aenea_model_B.i_p] -= B[tmp] * A[b_i + kAcol];
        }
      }
    }
  }

  return info;
}

// Function for MATLAB Function: '<S553>/DEFINITIVA'
static void Aenea_model_mldivide(const real_T A[121], const real_T B[198],
  real_T Y[198])
{
  std::memcpy(&Y[0], &B[0], 198U * sizeof(real_T));
  std::memcpy(&Aenea_model_B.b_A[0], &A[0], 121U * sizeof(real_T));
  Aenea_model_xgetrfs(Aenea_model_B.b_A, Y);
}

// Function for MATLAB Function: '<S553>/DEFINITIVA'
static void Aenea_model_measure_F1B(const real_T stato[18], const real_T EULERO
  [3], real_T rx, real_T ry, real_T rz, real_T g, real_T Y[11])
{
  real_T Y_tmp;
  real_T Y_tmp_0;
  real_T Y_tmp_1;
  real_T Y_tmp_2;
  real_T Y_tmp_3;
  real_T Y_tmp_4;
  Y[0] = stato[0];
  Y[1] = stato[1];
  Y[2] = stato[2];
  Aenea_model_B.Y_tmp = std::cos(EULERO[0]);
  Aenea_model_B.Y_tmp_c = std::sin(EULERO[2]);
  Aenea_model_B.Y_tmp_f = std::cos(EULERO[2]);
  Aenea_model_B.Y_tmp_g = std::sin(EULERO[0]);
  Aenea_model_B.Y_tmp_g1 = std::sin(EULERO[1]);
  Aenea_model_B.Y_tmp_m = std::cos(EULERO[1]);
  Y_tmp = stato[9] * ry - stato[10] * rx;
  Y_tmp_1 = stato[9] * rz - stato[11] * rx;
  Y_tmp_2 = stato[10] * rz - stato[11] * ry;
  Y[3] = (((Aenea_model_B.Y_tmp * Aenea_model_B.Y_tmp_f * Aenea_model_B.Y_tmp_g1
            + Aenea_model_B.Y_tmp_g * Aenea_model_B.Y_tmp_c) * Y_tmp + stato[3])
          + (Aenea_model_B.Y_tmp * Aenea_model_B.Y_tmp_c - Aenea_model_B.Y_tmp_f
             * Aenea_model_B.Y_tmp_g * Aenea_model_B.Y_tmp_g1) * Y_tmp_1) +
    Y_tmp_2 * (Aenea_model_B.Y_tmp_f * Aenea_model_B.Y_tmp_m);
  Y_tmp_0 = std::cos(EULERO[0]) * std::sin(EULERO[2]);
  Y_tmp_4 = std::cos(EULERO[2]) * std::sin(EULERO[0]);
  Y[4] = ((stato[4] - (Y_tmp_4 - Y_tmp_0 * Aenea_model_B.Y_tmp_g1) * Y_tmp) -
          (std::sin(EULERO[0]) * std::sin(EULERO[2]) * Aenea_model_B.Y_tmp_g1 +
           Y_tmp_0) * Y_tmp_1) + Y_tmp_2 * (Aenea_model_B.Y_tmp_m *
    Aenea_model_B.Y_tmp_c);
  Y_tmp_3 = stato[8] - g;
  Y[5] = ((((stato[6] * Aenea_model_B.Y_tmp_m * Aenea_model_B.Y_tmp_f + stato[12])
            + stato[7] * Aenea_model_B.Y_tmp_m * Aenea_model_B.Y_tmp_c) -
           Y_tmp_3 * Aenea_model_B.Y_tmp_g1) + Y_tmp * stato[10]) + Y_tmp_1 *
    stato[11];
  Y[6] = (((((std::cos(EULERO[2]) * std::sin(EULERO[0]) * std::sin(EULERO[1]) -
              Y_tmp_0) * stato[6] + stato[13]) + (std::sin(EULERO[0]) * std::sin
             (EULERO[2]) * std::sin(EULERO[1]) + std::cos(EULERO[0]) * std::cos
             (EULERO[2])) * stato[7]) + Aenea_model_B.Y_tmp_m *
           Aenea_model_B.Y_tmp_g * Y_tmp_3) - Y_tmp * stato[9]) + Y_tmp_2 *
    stato[11];
  Y[7] = (((((std::cos(EULERO[0]) * std::cos(EULERO[2]) * std::sin(EULERO[1]) +
              std::sin(EULERO[0]) * std::sin(EULERO[2])) * stato[6] + stato[14])
            + (std::cos(EULERO[0]) * std::sin(EULERO[2]) * std::sin(EULERO[1]) -
               Y_tmp_4) * stato[7]) + Aenea_model_B.Y_tmp *
           Aenea_model_B.Y_tmp_m * Y_tmp_3) - Y_tmp_1 * stato[9]) - Y_tmp_2 *
    stato[10];
  Y[8] = stato[15] + stato[9];
  Y[9] = stato[16] + stato[10];
  Y[10] = stato[17] + stato[11];
}

// Function for MATLAB Function: '<S553>/DEFINITIVA'
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

// Function for Chart: '<S35>/Chart'
static void Aenea_model_Waypoint(const boolean_T *Ap_sel, real_T *Ato_selector,
  real_T *Al_selector, real_T *Wp_selector, real_T *Vec_selector, real_T
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

// Function for Chart: '<S35>/Chart'
static void Aenea_model_In(const boolean_T *Ap_sel, real_T *Ato_selector, real_T
  *Al_selector, real_T *Wp_selector, real_T *Vec_selector, real_T
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

  static const real_T j[18] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.02, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T l[18] = { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.02, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T m[18] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.02,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T b[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T c_0[18] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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

  static const int8_T x_0[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0 };

  static const int8_T y[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1 };

  uint16_T x;
  uint16_T z;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T c;
  uint8_T counter;
  boolean_T Ap_sel;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T rtb_y_b;
  boolean_T rtb_y_e;
  boolean_T rtb_y_p;
  boolean_T tmp;
  boolean_T tmp_0;

  // UnitDelay: '<S567>/Unit Delay'
  std::memcpy(&Aenea_model_B.UnitDelay[0], &Aenea_model_DW.UnitDelay_DSTATE[0],
              9U * sizeof(real_T));

  // S-Function (Mti_sfun): '<S567>/S-Function Builder1'
  Mti_sfun_Outputs_wrapper(&Aenea_model_B.UnitDelay[0],
    &Aenea_model_B.SFunctionBuilder1[0]);

  // S-Function (byte2any_svd): '<S567>/Byte Unpack'

  // Unpack: <S567>/Byte Unpack
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

  // S-Function (reverseendian_svd): '<S567>/Byte Reversal'

  // ReverseEndian: <S567>/Byte Reversal

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

  // S-Function (Seriale_mav_sfun): '<S1>/S-Function Builder'
  Seriale_mav_sfun_Outputs_wrapper(&Aenea_model_B.SFunctionBuilder_o1_a[0],
    &Aenea_model_B.SFunctionBuilder_o2_a);

  // MATLAB Function: '<S1>/MATLAB Function4'
  Aenea_model_B.Switch_h = 0;
  Aenea_model_B.caso = 0;
  std::memset(&Aenea_model_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  std::memset(&Aenea_model_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  Aenea_model_find_254(Aenea_model_B.SFunctionBuilder_o1_a, Aenea_model_B.aterra,
                       &Aenea_model_B.num_254);
  if (Aenea_model_DW.Interr_parz && (Aenea_model_B.num_254 == 1.0)) {
    Aenea_model_B.Switch_oz = static_cast<int32_T>(Aenea_model_DW.counter_j + 1U);
    if (Aenea_model_DW.counter_j + 1U > 255U) {
      Aenea_model_B.Switch_oz = 255;
    }

    if (Aenea_model_B.aterra[0] != Aenea_model_B.Switch_oz) {
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
    Aenea_model_B.a_b = Aenea_model_B.aterra[static_cast<int32_T>
      (Aenea_model_B.num_254) - 1];
    if (Aenea_model_B.a_b == 100.0) {
      Aenea_model_DW.message[0] = Aenea_model_B.SFunctionBuilder_o1_a[99];
      Aenea_model_DW.Interr_parz = true;
    } else if (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
               (Aenea_model_B.a_b + 1.0) - 1] <= 100) {
      Aenea_model_B.Switch_oz = static_cast<int32_T>
        (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[0] + 1.0) - 1] + 8U);
      Aenea_model_B.soglia_dist = Aenea_model_B.Switch_oz;
      if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
        Aenea_model_B.soglia_dist = 255;
      }

      if (Aenea_model_B.soglia_dist == Aenea_model_B.SFunctionBuilder_o2_a) {
        Aenea_model_B.Switch_j = rt_roundd_snf(Aenea_model_B.a_b);
        if (Aenea_model_B.Switch_j < 256.0) {
          if (Aenea_model_B.Switch_j >= 0.0) {
            counter = static_cast<uint8_T>(Aenea_model_B.Switch_j);
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        Aenea_model_B.Switch_oz = static_cast<int32_T>
          (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
           (Aenea_model_B.a_b + 1.0) - 1] + 7U);
        if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
          Aenea_model_B.Switch_oz = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.a_b + static_cast<real_T>
          (Aenea_model_B.Switch_oz));
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            c = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          Aenea_model_B.i = 0;
          Aenea_model_B.ix = 0;
        } else {
          Aenea_model_B.i = counter - 1;
          Aenea_model_B.ix = c;
        }

        Aenea_model_B.caso = Aenea_model_B.ix - Aenea_model_B.i;
        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <
             Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
          Aenea_model_DW.message[Aenea_model_B.Switch_oz] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.i +
            Aenea_model_B.Switch_oz];
        }

        Aenea_model_B.Switch_h = 1;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_j = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
          Aenea_model_B.Switch_oz = 255;
        }

        if (Aenea_model_B.Switch_oz > Aenea_model_B.SFunctionBuilder_o2_a) {
          Aenea_model_DW.mess_len = Aenea_model_B.SFunctionBuilder_o2_a;
          if (Aenea_model_B.a_b > Aenea_model_DW.mess_len) {
            Aenea_model_B.tolleranza_distWP_fut = 0;
            Aenea_model_B.caso = 0;
          } else {
            Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
              (Aenea_model_B.a_b) - 1;
            Aenea_model_B.caso = static_cast<int32_T>(Aenea_model_DW.mess_len);
          }

          Aenea_model_B.caso -= Aenea_model_B.tolleranza_distWP_fut;
          for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <
               Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
            Aenea_model_DW.message[Aenea_model_B.Switch_oz] =
              Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.tolleranza_distWP_fut
              + Aenea_model_B.Switch_oz];
          }

          Aenea_model_B.Switch_oz = static_cast<int32_T>
            (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
             (Aenea_model_B.a_b + 1.0) - 1] + 8U);
          if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
            Aenea_model_B.Switch_oz = 255;
          }

          Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
            (Aenea_model_B.Switch_oz) - Aenea_model_DW.mess_len);
          if (Aenea_model_B.a_b < 256.0) {
            if (Aenea_model_B.a_b >= 0.0) {
              Aenea_model_DW.counter_j = static_cast<uint8_T>(Aenea_model_B.a_b);
            } else {
              Aenea_model_DW.counter_j = 0U;
            }
          } else {
            Aenea_model_DW.counter_j = MAX_uint8_T;
          }

          Aenea_model_DW.Interr_parz = true;
        }
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.counter_j = 0U;
      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_B.Switch_h = 1;
    }
    break;

   case 2:
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.x[Aenea_model_B.Switch_oz] =
        (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_oz] != 0);
    }

    if (Aenea_model_ifWhileCond(Aenea_model_B.x)) {
      Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_DW.mess_len + 1.0);
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          c = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_DW.mess_len +
        static_cast<real_T>(Aenea_model_DW.counter_j));
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          counter = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (c > counter) {
        Aenea_model_B.Switch_h = 1;
      } else {
        Aenea_model_B.Switch_h = c;
      }

      if (1 > Aenea_model_DW.counter_j) {
        Aenea_model_B.caso = -1;
      } else {
        Aenea_model_B.caso = Aenea_model_DW.counter_j - 1;
      }

      for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <=
           Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
        Aenea_model_DW.message[(Aenea_model_B.Switch_h + Aenea_model_B.Switch_oz)
          - 1] = Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_oz];
      }

      Aenea_model_DW.Interr_parz = false;
      Aenea_model_B.Switch_h = 1;
      for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
        Aenea_model_B.messaggio[Aenea_model_B.i] =
          Aenea_model_DW.message[Aenea_model_B.i];
        Aenea_model_DW.message[Aenea_model_B.i] = 0U;
      }

      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_DW.counter_j = 0U;
    } else {
      Aenea_model_DW.Interr_parz = false;
      Aenea_model_B.Switch_h = 1;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_DW.counter_j = 0U;
    }
    break;

   case 3:
    Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_DW.mess_len + 1.0);
    if (Aenea_model_B.a_b < 256.0) {
      if (Aenea_model_B.a_b >= 0.0) {
        c = static_cast<uint8_T>(Aenea_model_B.a_b);
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_DW.mess_len + static_cast<
      real_T>(Aenea_model_DW.counter_j));
    if (Aenea_model_B.a_b < 256.0) {
      if (Aenea_model_B.a_b >= 0.0) {
        counter = static_cast<uint8_T>(Aenea_model_B.a_b);
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (c > counter) {
      Aenea_model_B.Switch_h = 1;
    } else {
      Aenea_model_B.Switch_h = c;
    }

    if (1 > Aenea_model_DW.counter_j) {
      Aenea_model_B.caso = -1;
    } else {
      Aenea_model_B.caso = Aenea_model_DW.counter_j - 1;
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <=
         Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
      Aenea_model_DW.message[(Aenea_model_B.Switch_h + Aenea_model_B.Switch_oz)
        - 1] = Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_oz];
    }

    Aenea_model_DW.Interr_parz = false;
    Aenea_model_B.Switch_h = 1;
    for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
      Aenea_model_B.messaggio[Aenea_model_B.i] =
        Aenea_model_DW.message[Aenea_model_B.i];
      Aenea_model_DW.message[Aenea_model_B.i] = 0U;
    }

    Aenea_model_DW.mess_len = 0.0;
    Aenea_model_DW.counter_j = 0U;
    Aenea_model_B.Switch_oz = static_cast<int32_T>(Aenea_model_B.aterra[
      static_cast<int32_T>(Aenea_model_B.num_254) - 1] + 1.0) - 1;
    if (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_oz] <= 100) {
      Aenea_model_B.soglia_dist = static_cast<int32_T>
        (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[0] + 1.0) - 1] + 8U);
      if (static_cast<uint32_T>(Aenea_model_B.soglia_dist) > 255U) {
        Aenea_model_B.soglia_dist = 255;
      }

      Aenea_model_B.caso = Aenea_model_B.SFunctionBuilder_o2_a;
      if (Aenea_model_B.SFunctionBuilder_o2_a < 0) {
        Aenea_model_B.caso = 0;
      } else {
        if (Aenea_model_B.SFunctionBuilder_o2_a > 255) {
          Aenea_model_B.caso = 255;
        }
      }

      if (Aenea_model_B.soglia_dist == Aenea_model_B.caso) {
        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra
          [static_cast<int32_T>(Aenea_model_B.num_254) - 1]);
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            counter = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        Aenea_model_B.Switch_oz = static_cast<int32_T>
          (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_oz] + 7U);
        if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
          Aenea_model_B.Switch_oz = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra
          [static_cast<int32_T>(Aenea_model_B.num_254) - 1] + static_cast<real_T>
          (Aenea_model_B.Switch_oz));
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            c = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          Aenea_model_B.tolleranza_distWP_fut = 0;
          Aenea_model_B.caso = 0;
        } else {
          Aenea_model_B.tolleranza_distWP_fut = counter - 1;
          Aenea_model_B.caso = c;
        }

        Aenea_model_B.caso -= Aenea_model_B.tolleranza_distWP_fut;
        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <
             Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
          Aenea_model_DW.message[Aenea_model_B.Switch_oz] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.tolleranza_distWP_fut
            + Aenea_model_B.Switch_oz];
        }

        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio_2[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_j = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        Aenea_model_B.soglia_dist = static_cast<int32_T>
          (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
           (Aenea_model_B.aterra[0] + 1.0) - 1] + 8U);
        if (static_cast<uint32_T>(Aenea_model_B.soglia_dist) > 255U) {
          Aenea_model_B.soglia_dist = 255;
        }

        Aenea_model_B.caso = Aenea_model_B.SFunctionBuilder_o2_a;
        if (Aenea_model_B.SFunctionBuilder_o2_a < 0) {
          Aenea_model_B.caso = 0;
        } else {
          if (Aenea_model_B.SFunctionBuilder_o2_a > 255) {
            Aenea_model_B.caso = 255;
          }
        }

        if (Aenea_model_B.soglia_dist > Aenea_model_B.caso) {
          Aenea_model_DW.mess_len = Aenea_model_B.SFunctionBuilder_o2_a;
          if (Aenea_model_B.aterra[static_cast<int32_T>(Aenea_model_B.num_254) -
              1] > Aenea_model_DW.mess_len) {
            Aenea_model_B.tolleranza_distWP_fut = 0;
            Aenea_model_B.caso = 0;
          } else {
            Aenea_model_B.tolleranza_distWP_fut = static_cast<int32_T>
              (Aenea_model_B.aterra[static_cast<int32_T>(Aenea_model_B.num_254)
               - 1]) - 1;
            Aenea_model_B.caso = static_cast<int32_T>(Aenea_model_DW.mess_len);
          }

          Aenea_model_B.caso -= Aenea_model_B.tolleranza_distWP_fut;
          for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist <
               Aenea_model_B.caso; Aenea_model_B.soglia_dist++) {
            Aenea_model_DW.message[Aenea_model_B.soglia_dist] =
              Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.tolleranza_distWP_fut
              + Aenea_model_B.soglia_dist];
          }

          Aenea_model_B.Switch_oz = static_cast<int32_T>
            (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_oz] + 8U);
          if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
            Aenea_model_B.Switch_oz = 255;
          }

          Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
            (Aenea_model_B.Switch_oz) - Aenea_model_DW.mess_len);
          if (Aenea_model_B.a_b < 256.0) {
            if (Aenea_model_B.a_b >= 0.0) {
              Aenea_model_DW.counter_j = static_cast<uint8_T>(Aenea_model_B.a_b);
            } else {
              Aenea_model_DW.counter_j = 0U;
            }
          } else {
            Aenea_model_DW.counter_j = MAX_uint8_T;
          }

          Aenea_model_DW.Interr_parz = true;
        }
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.counter_j = 0U;
      Aenea_model_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
        (Aenea_model_B.aterra[0] + 1.0) - 1] <= 100) {
      Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[0]);
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          counter = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      Aenea_model_B.Switch_oz = static_cast<int32_T>
        (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[0] + 1.0) - 1] + 7U);
      if (static_cast<uint32_T>(Aenea_model_B.Switch_oz) > 255U) {
        Aenea_model_B.Switch_oz = 255;
      }

      Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[0] +
        static_cast<real_T>(Aenea_model_B.Switch_oz));
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          c = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      if (counter > c) {
        Aenea_model_B.Switch_h = 0;
        Aenea_model_B.caso = 0;
      } else {
        Aenea_model_B.Switch_h = counter - 1;
        Aenea_model_B.caso = c;
      }

      Aenea_model_B.caso -= Aenea_model_B.Switch_h;
      for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <
           Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
        Aenea_model_B.messaggio[Aenea_model_B.Switch_oz] =
          Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_h +
          Aenea_model_B.Switch_oz];
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    Aenea_model_B.Switch_h = 1;
    if ((Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[1] + 1.0) - 1] <= 100) && (Aenea_model_B.aterra[1]
         - Aenea_model_B.aterra[0] > 3.0)) {
      Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
        (Aenea_model_B.SFunctionBuilder_o2_a) - Aenea_model_B.aterra[1]);
      Aenea_model_B.qY = Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
        (Aenea_model_B.aterra[1] + 1.0) - 1];
      Aenea_model_B.Switch_oz = static_cast<int32_T>(Aenea_model_B.qY + 7U);
      if (Aenea_model_B.qY + 7U > 255U) {
        Aenea_model_B.Switch_oz = 255;
      }

      if (Aenea_model_B.a_b < 2.147483648E+9) {
        if (Aenea_model_B.a_b >= -2.147483648E+9) {
          Aenea_model_B.soglia_dist = static_cast<int32_T>(Aenea_model_B.a_b);
        } else {
          Aenea_model_B.soglia_dist = MIN_int32_T;
        }
      } else {
        Aenea_model_B.soglia_dist = MAX_int32_T;
      }

      if (Aenea_model_B.soglia_dist == Aenea_model_B.Switch_oz) {
        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[1]);
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            counter = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        Aenea_model_B.Switch_oz = static_cast<int32_T>(Aenea_model_B.qY + 7U);
        if (Aenea_model_B.qY + 7U > 255U) {
          Aenea_model_B.Switch_oz = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[1] + static_cast<
          real_T>(Aenea_model_B.Switch_oz));
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            c = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          Aenea_model_B.Switch_h = 0;
          Aenea_model_B.caso = 0;
        } else {
          Aenea_model_B.Switch_h = counter - 1;
          Aenea_model_B.caso = c;
        }

        Aenea_model_B.caso -= Aenea_model_B.Switch_h;
        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <
             Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
          Aenea_model_DW.message[Aenea_model_B.Switch_oz] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.Switch_h +
            Aenea_model_B.Switch_oz];
        }

        Aenea_model_B.Switch_h = 2;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio_2[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_j = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[1]);
        if (Aenea_model_B.a_b < 2.147483648E+9) {
          if (Aenea_model_B.a_b >= -2.147483648E+9) {
            Aenea_model_B.caso = static_cast<int32_T>(Aenea_model_B.a_b);
          } else {
            Aenea_model_B.caso = MIN_int32_T;
          }
        } else {
          Aenea_model_B.caso = MAX_int32_T;
        }

        if (Aenea_model_B.caso > Aenea_model_B.SFunctionBuilder_o2_a) {
          Aenea_model_B.caso = -1;
          Aenea_model_B.Switch_oz = 0;
        } else {
          Aenea_model_B.caso -= 2;
          Aenea_model_B.Switch_oz = Aenea_model_B.SFunctionBuilder_o2_a;
        }

        Aenea_model_DW.mess_len = static_cast<int8_T>((Aenea_model_B.Switch_oz -
          Aenea_model_B.caso) - 1);
        if (Aenea_model_B.a_b < 2.147483648E+9) {
          if (Aenea_model_B.a_b >= -2.147483648E+9) {
            Aenea_model_B.caso = static_cast<int32_T>(Aenea_model_B.a_b);
          } else {
            Aenea_model_B.caso = MIN_int32_T;
          }
        } else {
          Aenea_model_B.caso = MAX_int32_T;
        }

        if (Aenea_model_B.caso > Aenea_model_B.SFunctionBuilder_o2_a) {
          Aenea_model_B.tolleranza_distWP_fut = 0;
          Aenea_model_B.caso = 0;
        } else {
          Aenea_model_B.tolleranza_distWP_fut = Aenea_model_B.caso - 1;
          Aenea_model_B.caso = Aenea_model_B.SFunctionBuilder_o2_a;
        }

        Aenea_model_B.caso -= Aenea_model_B.tolleranza_distWP_fut;
        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz <
             Aenea_model_B.caso; Aenea_model_B.Switch_oz++) {
          Aenea_model_DW.message[Aenea_model_B.Switch_oz] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.tolleranza_distWP_fut
            + Aenea_model_B.Switch_oz];
        }

        Aenea_model_B.Switch_oz = static_cast<int32_T>(Aenea_model_B.qY + 8U);
        if (Aenea_model_B.qY + 8U > 255U) {
          Aenea_model_B.Switch_oz = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
          (Aenea_model_B.Switch_oz) - Aenea_model_DW.mess_len);
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            Aenea_model_DW.counter_j = static_cast<uint8_T>(Aenea_model_B.a_b);
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
  for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
       Aenea_model_B.Switch_oz++) {
    Aenea_model_B.buffer[3 * Aenea_model_B.Switch_oz] = 0U;
  }

  for (Aenea_model_B.ix = 0; Aenea_model_B.ix < 2; Aenea_model_B.ix++) {
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.caso = 3 * Aenea_model_B.Switch_oz + Aenea_model_B.ix;
      Aenea_model_B.buffer[Aenea_model_B.caso + 1] =
        Aenea_model_DW.Memory4_PreviousInput_j[Aenea_model_B.caso];
    }
  }

  Aenea_model_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (Aenea_model_B.i >= 1)) {
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.x[Aenea_model_B.Switch_oz] = (Aenea_model_B.buffer[(3 *
        Aenea_model_B.Switch_oz + Aenea_model_B.i) - 1] == 0);
    }

    Ap_sel = true;
    Aenea_model_B.caso = 0;
    exitg2 = false;
    while ((!exitg2) && (Aenea_model_B.caso < 100)) {
      if (!Aenea_model_B.x[Aenea_model_B.caso]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        Aenea_model_B.caso++;
      }
    }

    if (Ap_sel) {
      counter = static_cast<uint8_T>(Aenea_model_B.i);
      exitg1 = true;
    } else {
      Aenea_model_B.i--;
    }
  }

  if (Aenea_model_B.Switch_h == 1) {
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.buffer[(counter + 3 * Aenea_model_B.Switch_oz) - 1] =
        Aenea_model_B.messaggio[Aenea_model_B.Switch_oz];
    }
  } else if (Aenea_model_B.Switch_h == 2) {
    Aenea_model_B.qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      Aenea_model_B.qY = 0U;
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.buffer[(counter + 3 * Aenea_model_B.Switch_oz) - 1] =
        Aenea_model_B.messaggio[Aenea_model_B.Switch_oz];
      Aenea_model_B.buffer[(static_cast<int32_T>(Aenea_model_B.qY) + 3 *
                            Aenea_model_B.Switch_oz) - 1] =
        Aenea_model_B.messaggio_2[Aenea_model_B.Switch_oz];
    }
  } else {
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.buffer[(counter + 3 * Aenea_model_B.Switch_oz) - 1] = 0U;
    }
  }

  for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
       Aenea_model_B.Switch_oz++) {
    Aenea_model_B.mess_out[Aenea_model_B.Switch_oz] =
      Aenea_model_DW.Memory4_PreviousInput_j[3 * Aenea_model_B.Switch_oz + 2];
  }

  // Sum: '<S1>/Add' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLAB Function: '<S1>/MATLAB Function2'
  //   Memory: '<S1>/Memory4'

  Aenea_model_B.Add = Aenea_model_DW.Memory4_PreviousInput_j[5] + 8;

  // MATLAB Function: '<S1>/MATLAB Function3' incorporates:
  //   Memory: '<S1>/Memory5'

  if (Aenea_model_B.mess_out[2] != Aenea_model_DW.Memory5_PreviousInput_b[2]) {
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 100;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.x[Aenea_model_B.Switch_oz] =
        (Aenea_model_B.mess_out[Aenea_model_B.Switch_oz] != 0);
    }

    Ap_sel = true;
    Aenea_model_B.caso = 0;
    exitg1 = false;
    while ((!exitg1) && (Aenea_model_B.caso < 100)) {
      if (!Aenea_model_B.x[Aenea_model_B.caso]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        Aenea_model_B.caso++;
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

  Aenea_model_B.new_mex = Aenea_model_DW.counter;

  // End of MATLAB Function: '<S1>/MATLAB Function3'

  // Memory: '<S1>/Memory1'
  Aenea_model_B.Memory1[0] = Aenea_model_DW.Memory1_PreviousInput_b[0];
  Aenea_model_B.Memory1[1] = Aenea_model_DW.Memory1_PreviousInput_b[1];

  // Memory: '<Root>/Memory'
  Aenea_model_B.Memory_h[0] = Aenea_model_B.DataTypeConversion1_f[0];
  Aenea_model_B.Memory_h[1] = Aenea_model_B.DataTypeConversion1_f[1];
  Aenea_model_B.Memory_h[2] = Aenea_model_B.DataTypeConversion1_f[2];
  Aenea_model_B.Memory_h[3] = Aenea_model_B.DataTypeConversion1_f[3];

  // Memory: '<S1>/Memory3'
  Aenea_model_B.Memory3 = Aenea_model_DW.Memory3_PreviousInput_g;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 8; Aenea_model_B.i++) {
    // Memory: '<S1>/Memory'
    Aenea_model_B.Memory[Aenea_model_B.i] =
      Aenea_model_DW.Memory_PreviousInput_i[Aenea_model_B.i];
  }

  // S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
  //   Constant: '<Root>/SI UAV uint8'

  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&Aenea_model_B.mess_out[0], &Aenea_model_B.Add, &Aenea_model_B.new_mex,
     &Aenea_model_ConstP.SIUAVuint8_Value, &Aenea_model_B.Memory[0],
     &Aenea_model_B.Memory1[0], &Aenea_model_B.Memory_h[0],
     &Aenea_model_B.Memory3, &Aenea_model_B.SFunction_o1[0],
     &Aenea_model_B.SFunction_o2, &Aenea_model_B.SFunction_o3_n,
     &Aenea_model_B.SFunction_o4_a[0], &Aenea_model_B.SFunction_o5[0],
     &Aenea_model_B.SFunction_o6, &Aenea_model_B.SFunction_o7[0],
     &Aenea_model_B.SFunction_o8, &Aenea_model_B.SFunction_o9[0],
     &Aenea_model_B.SFunction_o10[0], &Aenea_model_B.SFunction_o11[0],
     &Aenea_model_B.SFunction_o12, &Aenea_model_B.SFunction_o13,
     &Aenea_model_B.SFunction_o14, &Aenea_model_B.SFunction_o15,
     &Aenea_model_B.SFunction_o16, &Aenea_model_B.SFunction_o17, 100);

  // MATLAB Function: '<S1>/MATLAB Function1'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    Aenea_model_B.WP_info_in[Aenea_model_B.i] =
      Aenea_model_B.SFunction_o9[Aenea_model_B.i];
  }

  if ((!Aenea_model_DW.WP_dbP_not_empty) || ((Aenea_model_B.SFunction_o7[0] == 3)
       && (Aenea_model_B.SFunction_o7[1] == 250))) {
    std::memset(&Aenea_model_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    Aenea_model_DW.WP_dbP_not_empty = true;
    std::memset(&Aenea_model_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!Aenea_model_DW.WP_dbP_AL_not_empty) || ((Aenea_model_B.SFunction_o7[0] ==
        3) && (Aenea_model_B.SFunction_o7[1] == 250))) {
    std::memset(&Aenea_model_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    Aenea_model_DW.WP_dbP_AL_not_empty = true;
  }

  Aenea_model_B.GC_info[0] = Aenea_model_B.SFunction_o7[0];
  Aenea_model_B.GC_info[1] = Aenea_model_B.SFunction_o7[1];
  Aenea_model_B.GC_info[2] = Aenea_model_B.SFunction_o11[0];
  if (Aenea_model_B.GC_info[0] == 1) {
    if ((Aenea_model_B.GC_info[1] > 0) && (Aenea_model_B.GC_info[1] <= 7)) {
      if (std::abs(Aenea_model_B.SFunction_o8) > 0.0F) {
        Aenea_model_DW.riferimenti[Aenea_model_B.GC_info[1] - 1] = 1.0F;
      } else {
        if (Aenea_model_B.SFunction_o8 == 0.0F) {
          Aenea_model_DW.riferimenti[Aenea_model_B.GC_info[1] - 1] = 0.0F;
        }
      }
    } else {
      if ((Aenea_model_B.GC_info[1] > 7) && (Aenea_model_B.GC_info[1] < 12)) {
        Aenea_model_DW.riferimenti[Aenea_model_B.GC_info[1] - 1] =
          Aenea_model_B.SFunction_o8;
      }
    }
  }

  if (Aenea_model_B.SFunction_o12 == 13) {
    Aenea_model_DW.riferimenti[Aenea_model_B.SFunction_o12 - 1] =
      Aenea_model_B.SFunction_o13;
  }

  std::memcpy(&Aenea_model_B.Val_out_MAV[0], &Aenea_model_DW.riferimenti[0],
              sizeof(real32_T) << 4U);
  if ((Aenea_model_B.GC_info[0] == 3) && (Aenea_model_B.GC_info[1] == 200)) {
    if (Aenea_model_B.SFunction_o9[0] > 6) {
      Aenea_model_B.WP_info_in[0] = 6U;
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 6;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_DW.WP_dbI[Aenea_model_B.Switch_oz] = Aenea_model_B.WP_info_in
        [0];
    }
  }

  if ((Aenea_model_B.GC_info[0] == 3) && (Aenea_model_B.GC_info[1] < 200)) {
    if (Aenea_model_B.SFunction_o10[1] == 0.0F) {
      Aenea_model_B.qY = Aenea_model_B.SFunction_o9[1] + 1U;
      if (Aenea_model_B.SFunction_o9[1] + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 7;
           Aenea_model_B.Switch_oz++) {
        Aenea_model_DW.WP_dbP[(static_cast<int32_T>(Aenea_model_B.qY) + 6 *
          Aenea_model_B.Switch_oz) - 1] =
          Aenea_model_B.SFunction_o10[Aenea_model_B.Switch_oz];
      }

      Aenea_model_B.qY = Aenea_model_B.SFunction_o9[1] + 1U;
      if (Aenea_model_B.SFunction_o9[1] + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 6;
           Aenea_model_B.Switch_oz++) {
        Aenea_model_DW.WP_dbI[(static_cast<int32_T>(Aenea_model_B.qY) + 6 *
          (Aenea_model_B.Switch_oz + 1)) - 1] =
          Aenea_model_B.WP_info_in[Aenea_model_B.Switch_oz + 1];
      }
    } else {
      Aenea_model_B.Switch_oz = static_cast<int32_T>
        (Aenea_model_B.SFunction_o10[0] + 1.0F);
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 7;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_DW.WP_dbP_AL[(Aenea_model_B.Switch_oz + 6 *
          Aenea_model_B.soglia_dist) - 1] =
          Aenea_model_B.SFunction_o10[Aenea_model_B.soglia_dist];
      }

      Aenea_model_B.qY = Aenea_model_B.SFunction_o9[1] + 1U;
      if (Aenea_model_B.SFunction_o9[1] + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 6;
           Aenea_model_B.Switch_oz++) {
        Aenea_model_DW.WP_dbI[(static_cast<int32_T>(Aenea_model_B.qY) + 6 *
          (Aenea_model_B.Switch_oz + 1)) - 1] =
          Aenea_model_B.WP_info_in[Aenea_model_B.Switch_oz + 1];
      }
    }
  }

  // Update for Memory: '<S1>/Memory3' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  Aenea_model_DW.Memory3_PreviousInput_g = 0U;

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Memory: '<S1>/Memory2'

  if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n == 0))
  {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    // Update for Memory: '<S1>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
  } else if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n ==
              3)) {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    // Update for Memory: '<S1>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
    Aenea_model_DW.test1 = 0.0;
  } else if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n ==
              2)) {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    // Update for Memory: '<S1>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
    Aenea_model_DW.test1 = 0.0;
  } else if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n ==
              1)) {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    // Update for Memory: '<S1>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
    Aenea_model_DW.test1 = 1.0;
  } else {
    switch (Aenea_model_B.SFunction_o6) {
     case 192:
      Aenea_model_DW.Memory1_PreviousInput_b[0] = 192U;
      Aenea_model_DW.Memory1_PreviousInput_b[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      // Update for Memory: '<S1>/Memory3'
      Aenea_model_DW.Memory3_PreviousInput_g = 192U;
      break;

     case 208:
      Aenea_model_DW.Memory1_PreviousInput_b[0] = 208U;
      Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      // Update for Memory: '<S1>/Memory3'
      Aenea_model_DW.Memory3_PreviousInput_g = 208U;
      break;

     default:
      if ((Aenea_model_B.SFunction_o6 == 220) && (Aenea_model_B.SFunction_o3_n
           != 5)) {
        if ((Aenea_model_DW.Memory2_PreviousInput_d[0] == 0) &&
            (Aenea_model_DW.Memory2_PreviousInput_d[1] == 0) &&
            ((Aenea_model_DW.Memory2_PreviousInput_d[2] == 1) ||
             (Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) ||
             (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) ||
             (Aenea_model_DW.Memory2_PreviousInput_d[5] == 1) ||
             (Aenea_model_DW.Memory2_PreviousInput_d[6] == 1) ||
             (Aenea_model_DW.Memory2_PreviousInput_d[7] == 1))) {
          Aenea_model_DW.Memory1_PreviousInput_b[0] = 220U;
          Aenea_model_DW.Memory1_PreviousInput_b[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          // Update for Memory: '<S1>/Memory3'
          Aenea_model_DW.Memory3_PreviousInput_g = 220U;
        } else if ((Aenea_model_DW.Memory2_PreviousInput_d[0] == 0) &&
                   (Aenea_model_DW.Memory2_PreviousInput_d[1] == 1) &&
                   ((Aenea_model_DW.Memory2_PreviousInput_d[2] == 1) ||
                    (Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) ||
                    (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) ||
                    (Aenea_model_DW.Memory2_PreviousInput_d[5] == 1) ||
                    (Aenea_model_DW.Memory2_PreviousInput_d[6] == 1) ||
                    (Aenea_model_DW.Memory2_PreviousInput_d[7] == 1))) {
          Aenea_model_DW.Memory1_PreviousInput_b[0] = 220U;
          Aenea_model_DW.Memory1_PreviousInput_b[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          // Update for Memory: '<S1>/Memory3'
          Aenea_model_DW.Memory3_PreviousInput_g = 220U;
        } else {
          Aenea_model_DW.Memory1_PreviousInput_b[0] = 208U;
          Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          // Update for Memory: '<S1>/Memory3'
          Aenea_model_DW.Memory3_PreviousInput_g = 208U;
        }
      } else if (Aenea_model_B.SFunction_o3_n == 5) {
        Aenea_model_DW.Memory1_PreviousInput_b[0] = 220U;
        Aenea_model_DW.Memory1_PreviousInput_b[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        Aenea_model_DW.Memory1_PreviousInput_b[0] = 192U;
        Aenea_model_DW.Memory1_PreviousInput_b[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  Aenea_model_B.qY = 100U * Aenea_model_B.SFunction_o11[5];
  if (Aenea_model_B.qY > 65535U) {
    Aenea_model_B.qY = 65535U;
  }

  if (Aenea_model_B.SFunction_o11[4] == 0) {
    if (static_cast<uint16_T>(Aenea_model_B.qY) == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = static_cast<uint16_T>(Aenea_model_B.SFunction_o11[4] == 0U ?
      MAX_uint32_T : static_cast<uint32_T>(static_cast<uint16_T>
      (Aenea_model_B.qY)) / Aenea_model_B.SFunction_o11[4]);
    x = static_cast<uint16_T>(static_cast<uint32_T>(static_cast<uint16_T>
      (Aenea_model_B.qY)) - static_cast<uint16_T>(static_cast<uint32_T>(z) *
      Aenea_model_B.SFunction_o11[4]));
    if ((x > 0) && (x >= static_cast<int32_T>(static_cast<uint32_T>
          (Aenea_model_B.SFunction_o11[4]) >> 1) + (Aenea_model_B.SFunction_o11
          [4] & 1))) {
      z = static_cast<uint16_T>(z + 1U);
    }
  }

  Aenea_model_DW.Memory2_PreviousInput_d[0] = static_cast<uint8_T>(AP_mode_idx_0);
  Aenea_model_DW.Memory2_PreviousInput_d[1] = static_cast<uint8_T>(AP_mode_idx_1);
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

  // RateTransition: '<S23>/Rate Transition'
  Aenea_model_B.num_254 = Aenea_model_DW.RateTransition_Buffer0;

  // Switch: '<S23>/Switch' incorporates:
  //   Constant: '<S23>/Constant3'
  //   Memory: '<S23>/Memory1'
  //   Sum: '<S23>/Add1'

  if (Aenea_model_DW.Memory1_PreviousInput + 1.0 > 4.0) {
    // Switch: '<S23>/Switch' incorporates:
    //   Constant: '<S23>/Constant2'

    Aenea_model_DW.Memory1_PreviousInput = 0.0;
  } else {
    // Switch: '<S23>/Switch'
    Aenea_model_DW.Memory1_PreviousInput++;
  }

  // End of Switch: '<S23>/Switch'

  // MATLAB Function: '<S16>/iflogic_function'
  if ((Aenea_model_DW.Memory1_PreviousInput == 1.0) ||
      (Aenea_model_DW.Memory1_PreviousInput == 3.0)) {
    Aenea_model_B.iflogic = 26U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 2.0) ||
             (Aenea_model_DW.Memory1_PreviousInput == 4.0)) {
    Aenea_model_B.iflogic = 30U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.num_254 == 2.0)) {
    Aenea_model_B.iflogic = 33U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.num_254 == 6.0)) {
    Aenea_model_B.iflogic = 34U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.num_254 == 0.0)) {
    Aenea_model_B.iflogic = 0U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             ((Aenea_model_B.num_254 == 1.0) || (Aenea_model_B.num_254 == 5.0) ||
              (Aenea_model_B.num_254 == 9.0))) {
    Aenea_model_B.iflogic = 1U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             ((Aenea_model_B.num_254 == 3.0) || (Aenea_model_B.num_254 == 8.0)))
  {
    Aenea_model_B.iflogic = 74U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.num_254 == 7.0)) {
    Aenea_model_B.iflogic = 36U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.num_254 == 4.0)) {
    Aenea_model_B.iflogic = 29U;
  } else {
    Aenea_model_B.iflogic = MAX_uint8_T;
  }

  // End of MATLAB Function: '<S16>/iflogic_function'

  // Gain: '<S16>/Gain' incorporates:
  //   Constant: '<S23>/Constant1'
  //   Memory: '<S23>/Memory'
  //   Sum: '<S23>/Add'

  Aenea_model_B.Gain_h = (Aenea_model_DW.Memory_PreviousInput + 0.02) * 100.0;

  // DataTypeConversion: '<S16>/Data Type Conversion3'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S16>/Data Type Conversion3'
  Aenea_model_B.DataTypeConversion3 = Aenea_model_B.a_b < 0.0 ?
    static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>
    (-Aenea_model_B.a_b))) : static_cast<uint32_T>(Aenea_model_B.a_b);

  // MATLAB Function: '<S21>/MATLAB Function' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 6;
       Aenea_model_B.Switch_oz++) {
    Aenea_model_B.WP_info[Aenea_model_B.Switch_oz] = Aenea_model_DW.WP_dbI[6 *
      Aenea_model_B.Switch_oz];
  }

  for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 7;
       Aenea_model_B.Switch_oz++) {
    Aenea_model_B.WP_param[Aenea_model_B.Switch_oz] = Aenea_model_DW.WP_dbP[6 *
      Aenea_model_B.Switch_oz];
  }

  if ((Aenea_model_B.GC_info[0] == 2) && (Aenea_model_B.GC_info[1] < 6)) {
    Aenea_model_B.qY = Aenea_model_B.GC_info[1] + 1U;
    if (Aenea_model_B.GC_info[1] + 1U > 65535U) {
      Aenea_model_B.qY = 65535U;
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 6;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.WP_info[Aenea_model_B.Switch_oz] = Aenea_model_DW.WP_dbI[(6 *
        Aenea_model_B.Switch_oz + static_cast<int32_T>(Aenea_model_B.qY)) - 1];
    }

    Aenea_model_B.qY = Aenea_model_B.GC_info[1] + 1U;
    if (Aenea_model_B.GC_info[1] + 1U > 65535U) {
      Aenea_model_B.qY = 65535U;
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 7;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.WP_param[Aenea_model_B.Switch_oz] = Aenea_model_DW.WP_dbP[(6
        * Aenea_model_B.Switch_oz + static_cast<int32_T>(Aenea_model_B.qY)) - 1];
    }
  }

  if ((Aenea_model_B.GC_info[0] == 3) && (Aenea_model_B.GC_info[1] < 200)) {
    Aenea_model_B.qY = Aenea_model_B.GC_info[1] + 1U;
    if (Aenea_model_B.GC_info[1] + 1U > 65535U) {
      Aenea_model_B.qY = 65535U;
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 6;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.WP_info[Aenea_model_B.Switch_oz] = Aenea_model_DW.WP_dbI[(6 *
        Aenea_model_B.Switch_oz + static_cast<int32_T>(Aenea_model_B.qY)) - 1];
    }
  }

  // End of MATLAB Function: '<S21>/MATLAB Function'

  // Outputs for Resettable SubSystem: '<S407>/Resettable Subsystem'
  Aenea_model_ResettableSubsystem(Aenea_model_B.SFunction_o4_a[0],
    &Aenea_model_B.Sum2_k2, &Aenea_model_DW.ResettableSubsystem_j,
    &Aenea_model_PrevZCX.ResettableSubsystem_j);

  // End of Outputs for SubSystem: '<S407>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S407>/Enabled Subsystem'
  Aenea_model_EnabledSubsystem(Aenea_model_B.SFunction_o4_a[0],
    Aenea_model_B.Sum2_k2, &Aenea_model_B.Switch_a);

  // End of Outputs for SubSystem: '<S407>/Enabled Subsystem'

  // Product: '<S555>/Product1' incorporates:
  //   Constant: '<S4>/tas'
  //   MATLAB Function: '<S555>/MATLAB Function'
  //   Sum: '<S555>/Sum'
  //   UnitDelay: '<S555>/Unit Delay'

  Aenea_model_B.num_254 = (Aenea_model_DW.UnitDelay_DSTATE_c + 1.0) *
    0.38271604938271603;

  // DataTypeConversion: '<S5>/Data Type Conversion1'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 9; Aenea_model_B.i++) {
    Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i] =
      Aenea_model_B.ByteReversal[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S5>/Data Type Conversion1'

  // Gain: '<S548>/Gain1'
  Aenea_model_B.Gain1 = 0.017453292519943295 *
    Aenea_model_B.DataTypeConversion1_c[6];

  // MATLAB Function: '<S413>/MATLAB Function1'
  guard1 = false;
  if (Aenea_model_DW.Memory2_PreviousInput_d[1] == 1) {
    // Switch: '<S34>/Switch' incorporates:
    //   Constant: '<S34>/Constant'

    if (Aenea_model_B.Switch_a != 0.0) {
      Aenea_model_B.a_b = 50.0;
    } else {
      Aenea_model_B.a_b = Aenea_model_B.num_254;
    }

    // End of Switch: '<S34>/Switch'
    if (Aenea_model_B.a_b > 40.0) {
      Aenea_model_DW.alarm = 1.0;
    } else if (std::abs(57.295779513082323 * Aenea_model_B.Gain1) > 55.0) {
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

  // Outputs for Resettable SubSystem: '<S430>/Resettable Subsystem' incorporates:
  //   ResetPort: '<S433>/Reset'

  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &Aenea_model_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (Aenea_model_DW.alarm)) != NO_ZCEVENT) {
    // InitializeConditions for Memory: '<S434>/Memory'
    Aenea_model_DW.Memory_PreviousInput_n = 0.0;
  }

  // Sum: '<S434>/Sum' incorporates:
  //   Constant: '<S434>/Constant4'
  //   Memory: '<S434>/Memory'

  Aenea_model_B.Sum_fj = Aenea_model_DW.Memory_PreviousInput_n + 0.02;

  // Update for Memory: '<S434>/Memory' incorporates:
  //   Constant: '<S434>/Constant4'
  //   Sum: '<S434>/Sum'

  Aenea_model_DW.Memory_PreviousInput_n += 0.02;

  // End of Outputs for SubSystem: '<S430>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S430>/Enabled ' incorporates:
  //   EnablePort: '<S432>/Enable'

  // MATLAB Function: '<S413>/MATLAB Function1'
  if (Aenea_model_DW.alarm > 0.0) {
    Aenea_model_DW.Enabled_MODE = true;

    // Switch: '<S432>/Switch'
    Aenea_model_B.Switch = (Aenea_model_B.Sum_fj > 1.0);
  } else {
    if (Aenea_model_DW.Enabled_MODE) {
      // Disable for Switch: '<S432>/Switch' incorporates:
      //   Outport: '<S432>/Alarm Safe'

      Aenea_model_B.Switch = 0.0;
      Aenea_model_DW.Enabled_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S430>/Enabled '

  // DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
  //   Constant: '<S19>/load uint16'

  Aenea_model_B.LVDE[0] = 10U;
  Aenea_model_B.LVDE[1] = Aenea_model_ConstB.Gain_e;

  // MATLAB Function: '<S1>/MATLAB Function1'
  Aenea_model_B.qY = 10U * z;
  if (Aenea_model_B.qY > 65535U) {
    Aenea_model_B.qY = 65535U;
  }

  // DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
  //   Constant: '<S19>/ '
  //   MATLAB Function: '<S1>/MATLAB Function1'

  Aenea_model_B.LVDE[2] = static_cast<uint16_T>(Aenea_model_B.qY);
  Aenea_model_B.LVDE[3] = Aenea_model_B.SFunction_o11[6];
  Aenea_model_B.LVDE[4] = Aenea_model_B.SFunction_o11[2];
  Aenea_model_B.LVDE[5] = 0U;

  // DataTypeConversion: '<S19>/Data Type Conversion4'
  Aenea_model_B.a_b = std::floor(Aenea_model_B.Switch);
  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
  //   Constant: '<S34>/Constant2'
  //   DataTypeConversion: '<S19>/Data Type Conversion4'

  Aenea_model_B.LVDE[6] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));
  Aenea_model_B.LVDE[7] = 0U;

  // DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
  //   MATLAB Function: '<S14>/Alarm set'

  Aenea_model_B.DataTypeConversion1_f[2] =
    Aenea_model_DW.Memory1_PreviousInput_b[0];
  Aenea_model_B.DataTypeConversion1_f[3] =
    Aenea_model_DW.Memory1_PreviousInput_b[1];

  // MATLAB Function: '<S14>/Alarm set' incorporates:
  //   SignalConversion generated from: '<S22>/ SFunction '

  if (Aenea_model_B.Switch == 1.0) {
    // DataTypeConversion: '<S14>/Data Type Conversion1'
    Aenea_model_B.DataTypeConversion1_f[2] = 220U;
    Aenea_model_B.DataTypeConversion1_f[3] = 5U;
  }

  // DataTypeConversion: '<S14>/Data Type Conversion1'
  Aenea_model_B.DataTypeConversion1_f[0] = 1U;
  Aenea_model_B.DataTypeConversion1_f[1] = 0U;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // Gain: '<S15>/Gain'
    Aenea_model_B.Gain_h = 1000.0 *
      Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i];

    // DataTypeConversion: '<S15>/Data Type Conversion'
    if (Aenea_model_B.Gain_h < 0.0) {
      Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
    } else {
      Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
    }

    if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
      Aenea_model_B.a_b = 0.0;
    } else {
      Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
    }

    // DataTypeConversion: '<S15>/Data Type Conversion'
    Aenea_model_B.DataTypeConversion_j[Aenea_model_B.i] = static_cast<int16_T>
      (Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
         static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.a_b)))) :
       static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
         (Aenea_model_B.a_b))));
  }

  // DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
  //   Constant: '<S15>/Constant'
  //   Constant: '<S15>/Constant1'
  //   Constant: '<S15>/Constant2'
  //   Gain: '<S15>/Gain'

  Aenea_model_B.DataTypeConversion_j[6] = 0;
  Aenea_model_B.DataTypeConversion_j[7] = 0;
  Aenea_model_B.DataTypeConversion_j[8] = 0;

  // Gain: '<S549>/Gain1'
  Aenea_model_B.Gain1_m = 0.017453292519943295 *
    Aenea_model_B.DataTypeConversion1_c[7];

  // DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
  //   Gain: '<S550>/Gain1'

  Aenea_model_B.DataTypeConversion1[0] = static_cast<real32_T>
    (Aenea_model_B.Gain1);
  Aenea_model_B.DataTypeConversion1[1] = static_cast<real32_T>
    (Aenea_model_B.Gain1_m);
  Aenea_model_B.DataTypeConversion1[2] = static_cast<real32_T>
    (0.017453292519943295 * Aenea_model_B.DataTypeConversion1_c[8]);
  Aenea_model_B.DataTypeConversion1[3] = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[3]);
  Aenea_model_B.DataTypeConversion1[4] = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[4]);
  Aenea_model_B.DataTypeConversion1[5] = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[5]);

  // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
  // DataTypeConversion: '<S569>/Data Type Conversion3' incorporates:
  //   UnitDelay: '<S565>/Unit Delay1'

  Aenea_model_B.DataTypeConversion3_p = static_cast<real32_T>
    (Aenea_model_DW.UnitDelay1_DSTATE);

  // S-Function (BMP280_sfun): '<S569>/S-Function Builder'
  BMP280_sfun_Outputs_wrapper(&Aenea_model_B.DataTypeConversion3_p,
    &Aenea_model_B.SFunctionBuilder_o1, &Aenea_model_B.SFunctionBuilder_o2,
    &Aenea_model_B.SFunctionBuilder_o3);

  // End of Outputs for SubSystem: '<S565>/Execution_loop'

  // Logic: '<S559>/NOT' incorporates:
  //   Memory: '<S559>/Memory'
  //   RelationalOperator: '<S559>/Equal'

  Aenea_model_B.NOT[5] = !(Aenea_model_B.DataTypeConversion1_c[6] ==
    Aenea_model_DW.Memory_PreviousInput_e[5]);
  Aenea_model_B.NOT[6] = !(Aenea_model_B.DataTypeConversion1_c[7] ==
    Aenea_model_DW.Memory_PreviousInput_e[6]);
  Aenea_model_B.NOT[7] = !(Aenea_model_B.DataTypeConversion1_c[8] ==
    Aenea_model_DW.Memory_PreviousInput_e[7]);
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    Aenea_model_B.NOT[Aenea_model_B.i + 8] =
      !(Aenea_model_DW.Memory_PreviousInput_e[Aenea_model_B.i + 8] ==
        Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i]);
  }

  // End of Logic: '<S559>/NOT'

  // MATLAB Function: '<S559>/MATLAB Function'
  rtb_y_p = (Aenea_model_B.NOT[5] || (Aenea_model_B.NOT[6] ||
              (Aenea_model_B.NOT[7] || (Aenea_model_B.NOT[8] ||
    (Aenea_model_B.NOT[9] || (Aenea_model_B.NOT[10] || (Aenea_model_B.NOT[11] ||
    Aenea_model_B.NOT[12])))))));

  // Logic: '<S558>/NOT' incorporates:
  //   Memory: '<S558>/Memory'
  //   RelationalOperator: '<S558>/Equal1'

  Aenea_model_B.NOT[3] = !(0.0 == Aenea_model_DW.Memory_PreviousInput_o[3]);
  Aenea_model_B.NOT[4] = !(0.0 == Aenea_model_DW.Memory_PreviousInput_o[4]);

  // MATLAB Function: '<S558>/MATLAB Function1' incorporates:
  //   Constant: '<S566>/Constant4'
  //   Constant: '<S566>/Constant5'
  //   Logic: '<S558>/NOT'
  //   Memory: '<S558>/Memory'
  //   RelationalOperator: '<S558>/Equal1'

  rtb_y_e = ((!(1.0 == Aenea_model_DW.Memory_PreviousInput_o[0])) || (!(1.0 ==
    Aenea_model_DW.Memory_PreviousInput_o[1])));

  // Step: '<S554>/Step' incorporates:
  //   DigitalClock: '<S246>/Digital Clock1'

  Aenea_model_B.Sum_fj = ((Aenea_model_M->Timing.clockTick0) * 0.02);

  // Switch: '<S554>/Switch' incorporates:
  //   Step: '<S554>/Step'

  Aenea_model_B.Switch_h = !(Aenea_model_B.Sum_fj < 0.4);

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S553>/Enable'

  // SignalConversion generated from: '<S560>/ SFunction ' incorporates:
  //   Constant: '<S566>/Constant4'
  //   Constant: '<S566>/Constant5'
  //   DataTypeConversion: '<S569>/Data Type Conversion2'
  //   Inport: '<S553>/Misure'
  //   MATLAB Function: '<S554>/MATLAB Function2'

  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[0] = 1.0;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[1] = 1.0;

  // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[2] =
    Aenea_model_B.SFunctionBuilder_o3;

  // End of Outputs for SubSystem: '<S565>/Execution_loop'
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[3] = 0.0;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[4] = 0.0;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5] =
    Aenea_model_B.DataTypeConversion1_c[6];
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6] =
    Aenea_model_B.DataTypeConversion1_c[7];
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7] =
    Aenea_model_B.DataTypeConversion1_c[8];
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // RelationalOperator: '<S558>/Equal1'
    Aenea_model_B.Sum5 = Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i];

    // Logic: '<S558>/NOT' incorporates:
    //   Memory: '<S558>/Memory'
    //   RelationalOperator: '<S558>/Equal1'

    Aenea_model_B.NOT[Aenea_model_B.i + 8] =
      !(Aenea_model_DW.Memory_PreviousInput_o[Aenea_model_B.i + 8] ==
        Aenea_model_B.Sum5);

    // SignalConversion generated from: '<S560>/ SFunction ' incorporates:
    //   Inport: '<S553>/Misure'
    //   MATLAB Function: '<S554>/MATLAB Function2'

    Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[Aenea_model_B.i + 8] =
      Aenea_model_B.Sum5;
  }

  // MATLAB Function: '<S554>/MATLAB Function2' incorporates:
  //   Constant: '<S554>/Constant'
  //   MATLAB Function: '<S553>/DEFINITIVA'
  //   SignalConversion generated from: '<S560>/ SFunction '

  Aenea_model_B.Sum5 = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Gain_h = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k
    [5]);
  Aenea_model_B.Ato_selector = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]);
  Aenea_model_B.SwitchBumpless2 = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
  Aenea_model_B.Saturation_a = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Gain1_k = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]);

  // End of Outputs for SubSystem: '<S4>/Filter2'
  Aenea_model_B.aterra_tmp[0] = Aenea_model_B.Sum5 * Aenea_model_B.Gain1_k;
  Aenea_model_B.aterra_tmp[3] = Aenea_model_B.Sum5 *
    Aenea_model_B.SwitchBumpless2 * Aenea_model_B.Ato_selector -
    Aenea_model_B.Gain_h * Aenea_model_B.Saturation_a;
  Aenea_model_B.aterra_tmp[6] = Aenea_model_B.Gain_h * Aenea_model_B.Sum5 *
    Aenea_model_B.Ato_selector + Aenea_model_B.SwitchBumpless2 *
    Aenea_model_B.Saturation_a;
  Aenea_model_B.aterra_tmp[1] = Aenea_model_B.Saturation_a *
    Aenea_model_B.Gain1_k;

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S553>/Enable'

  Aenea_model_B.Alettoni = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);

  // End of Outputs for SubSystem: '<S4>/Filter2'
  Aenea_model_B.aterra_tmp[4] = Aenea_model_B.Alettoni *
    Aenea_model_B.Ato_selector + std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S553>/Enable'

  Aenea_model_B.aterra_tmp_tmp = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Sum3_h = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k
    [7]) * std::sin(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);

  // End of Outputs for SubSystem: '<S4>/Filter2'
  Aenea_model_B.aterra_tmp[7] = Aenea_model_B.aterra_tmp_tmp *
    Aenea_model_B.Ato_selector - Aenea_model_B.Sum3_h;
  Aenea_model_B.aterra_tmp[2] = -Aenea_model_B.Ato_selector;
  Aenea_model_B.aterra_tmp[5] = Aenea_model_B.Gain1_k *
    Aenea_model_B.SwitchBumpless2;
  Aenea_model_B.aterra_tmp[8] = Aenea_model_B.Gain_h * Aenea_model_B.Gain1_k;
  Aenea_model_B.Vec_selector = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[8];
  Aenea_model_B.Go_home_selector =
    Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[9];
  Aenea_model_B.Wp_selector = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[10];
  for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 3;
       Aenea_model_B.Switch_oz++) {
    Aenea_model_B.aterra[Aenea_model_B.Switch_oz] =
      Aenea_model_B.aterra_tmp[Aenea_model_B.Switch_oz + 6] *
      Aenea_model_B.Wp_selector +
      (Aenea_model_B.aterra_tmp[Aenea_model_B.Switch_oz + 3] *
       Aenea_model_B.Go_home_selector +
       Aenea_model_B.aterra_tmp[Aenea_model_B.Switch_oz] *
       Aenea_model_B.Vec_selector);
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

  // Outputs for Triggered SubSystem: '<S554>/Sample and Hold' incorporates:
  //   TriggerPort: '<S561>/Trigger'

  Aenea_model_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
    &Aenea_model_PrevZCX.SampleandHold_Trig_ZCE,
    (static_cast<real_T>(Aenea_model_B.Switch_h)));
  if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
    // Inport: '<S561>/In'
    std::memcpy(&Aenea_model_B.In[0], &Aenea_model_B.y[0], 21U * sizeof(real_T));
  }

  // End of Outputs for SubSystem: '<S554>/Sample and Hold'

  // MATLAB Function: '<S558>/MATLAB Function'
  rtb_y_b = (Aenea_model_B.NOT[3] || Aenea_model_B.NOT[4]);

  // Outputs for Enabled SubSystem: '<S4>/Filter2' incorporates:
  //   EnablePort: '<S553>/Enable'

  if (Aenea_model_B.Switch_h > 0) {
    // MATLAB Function: '<S553>/DEFINITIVA' incorporates:
    //   Constant: '<S4>/Constant13'
    //   Constant: '<S4>/Constant16'
    //   Inport: '<S553>/Misure'

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
    Aenea_model_B.H[102] = (Aenea_model_B.Gain_h * Aenea_model_B.Sum5 *
      Aenea_model_B.Ato_selector + Aenea_model_B.SwitchBumpless2 *
      Aenea_model_B.Saturation_a) * 0.0 + (Aenea_model_B.Gain_h *
      Aenea_model_B.Saturation_a - Aenea_model_B.Sum5 *
      Aenea_model_B.SwitchBumpless2 * Aenea_model_B.Ato_selector) * 0.0;
    Aenea_model_B.Vec_selector = 0.0 * Aenea_model_B.Sum5 *
      Aenea_model_B.Gain1_k;
    Aenea_model_B.Go_home_selector = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) + std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
    Aenea_model_B.H[113] = Aenea_model_B.Vec_selector -
      Aenea_model_B.Go_home_selector * 0.0;
    Aenea_model_B.H[124] = (Aenea_model_B.aterra_tmp_tmp - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6])) * -0.0 -
      Aenea_model_B.Vec_selector;
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
    Aenea_model_B.H[103] = (Aenea_model_B.Sum3_h - Aenea_model_B.aterra_tmp_tmp *
      Aenea_model_B.Ato_selector) * -0.0 - (Aenea_model_B.Alettoni *
      Aenea_model_B.Ato_selector + Aenea_model_B.aterra_tmp_tmp) * 0.0;
    Aenea_model_B.Vec_selector = 0.0 * Aenea_model_B.Gain1_k *
      Aenea_model_B.Saturation_a;
    Aenea_model_B.H[114] = (Aenea_model_B.Sum3_h - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6])) * 0.0 +
      Aenea_model_B.Vec_selector;
    Aenea_model_B.H[125] = (std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) +
      Aenea_model_B.aterra_tmp_tmp) * 0.0 - Aenea_model_B.Vec_selector;
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
    Aenea_model_B.H[71] = Aenea_model_B.Sum5 * Aenea_model_B.Gain1_k;
    Aenea_model_B.H[82] = Aenea_model_B.Gain1_k * Aenea_model_B.Saturation_a;
    Aenea_model_B.H[93] = -Aenea_model_B.Ato_selector;
    Aenea_model_B.H[104] = Aenea_model_DW.x_prd[10] * 0.0 +
      Aenea_model_DW.x_prd[11] * 0.0;
    Aenea_model_B.Vec_selector = 2.0 * Aenea_model_DW.x_prd[10] * 0.0;
    Aenea_model_B.H[115] = Aenea_model_DW.x_prd[9] * 0.0 -
      Aenea_model_B.Vec_selector;
    Aenea_model_B.Sum5 = 2.0 * Aenea_model_DW.x_prd[11] * 0.0;
    Aenea_model_B.H[126] = Aenea_model_DW.x_prd[9] * 0.0 - Aenea_model_B.Sum5;
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
    Aenea_model_B.H[94] = Aenea_model_B.Gain1_k * Aenea_model_B.SwitchBumpless2;
    Aenea_model_B.SwitchBumpless2 = 2.0 * Aenea_model_DW.x_prd[9] * 0.0;
    Aenea_model_B.H[105] = Aenea_model_DW.x_prd[10] * 0.0 -
      Aenea_model_B.SwitchBumpless2;
    Aenea_model_B.H[116] = Aenea_model_DW.x_prd[9] * 0.0 + Aenea_model_DW.x_prd
      [11] * 0.0;
    Aenea_model_B.H[127] = Aenea_model_DW.x_prd[10] * 0.0 - Aenea_model_B.Sum5;
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
    Aenea_model_B.H[73] = Aenea_model_B.Go_home_selector;
    Aenea_model_B.H[84] = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
    Aenea_model_B.H[95] = Aenea_model_B.Gain_h * Aenea_model_B.Gain1_k;
    Aenea_model_B.H[106] = Aenea_model_DW.x_prd[11] * 0.0 -
      Aenea_model_B.SwitchBumpless2;
    Aenea_model_B.H[117] = Aenea_model_DW.x_prd[11] * 0.0 -
      Aenea_model_B.Vec_selector;
    Aenea_model_B.H[128] = Aenea_model_DW.x_prd[9] * 0.0 + Aenea_model_DW.x_prd
      [10] * 0.0;
    Aenea_model_B.H[139] = 0.0;
    Aenea_model_B.H[150] = 0.0;
    Aenea_model_B.H[161] = 1.0;
    Aenea_model_B.H[172] = 0.0;
    Aenea_model_B.H[183] = 0.0;
    Aenea_model_B.H[194] = 0.0;
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 18;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.H[11 * Aenea_model_B.Switch_oz] = b[Aenea_model_B.Switch_oz];
      Aenea_model_B.H[11 * Aenea_model_B.Switch_oz + 1] =
        c_0[Aenea_model_B.Switch_oz];
      Aenea_model_B.H[11 * Aenea_model_B.Switch_oz + 2] =
        d[Aenea_model_B.Switch_oz];
      Aenea_model_B.H[11 * Aenea_model_B.Switch_oz + 8] =
        e[Aenea_model_B.Switch_oz];
      Aenea_model_B.H[11 * Aenea_model_B.Switch_oz + 9] =
        f[Aenea_model_B.Switch_oz];
      Aenea_model_B.H[11 * Aenea_model_B.Switch_oz + 10] =
        g[Aenea_model_B.Switch_oz];
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 11;
         Aenea_model_B.Switch_oz++) {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.Switch_h = Aenea_model_B.Switch_oz + 11 *
          Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_h] = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso
             ++) {
          Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_h] += Aenea_model_B.H[11
            * Aenea_model_B.caso + Aenea_model_B.Switch_oz] *
            Aenea_model_DW.p_prd[18 * Aenea_model_B.soglia_dist +
            Aenea_model_B.caso];
        }
      }

      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 11;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.Switch_h = Aenea_model_B.Switch_oz + 11 *
          Aenea_model_B.soglia_dist;
        Aenea_model_B.S[Aenea_model_B.Switch_h] = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso
             ++) {
          Aenea_model_B.S[Aenea_model_B.Switch_h] += Aenea_model_B.klm_gain_m[11
            * Aenea_model_B.caso + Aenea_model_B.Switch_oz] * Aenea_model_B.H[11
            * Aenea_model_B.caso + Aenea_model_B.soglia_dist];
        }
      }
    }

    Ap_sel = (rtb_y_e && rtb_y_b);
    if (Ap_sel && rtb_y_p) {
      for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11; Aenea_model_B.caso++)
      {
        Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso + Aenea_model_B.caso;
        Aenea_model_B.S[Aenea_model_B.Switch_h] +=
          Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
      }
    } else {
      tmp = !rtb_y_e;
      tmp_0 = (tmp && rtb_y_b);
      if (tmp_0 && rtb_y_p) {
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11; Aenea_model_B.caso
             ++) {
          if ((Aenea_model_B.caso + 1 == 1) || (Aenea_model_B.caso + 1 == 2)) {
            Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
              Aenea_model_B.caso;
            Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
          } else {
            Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
              Aenea_model_B.caso;
            Aenea_model_B.S[Aenea_model_B.Switch_h] +=
              Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
          }
        }
      } else {
        rtb_y_b = !rtb_y_b;
        rtb_y_e = (rtb_y_e && rtb_y_b);
        if (rtb_y_e && rtb_y_p) {
          for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11;
               Aenea_model_B.caso++) {
            if ((Aenea_model_B.caso + 1 == 4) || (Aenea_model_B.caso + 1 == 5))
            {
              Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                Aenea_model_B.caso;
              Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
            } else {
              Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                Aenea_model_B.caso;
              Aenea_model_B.S[Aenea_model_B.Switch_h] +=
                Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
            }
          }
        } else {
          tmp = (tmp && rtb_y_b);
          if (tmp && rtb_y_p) {
            for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11;
                 Aenea_model_B.caso++) {
              if ((Aenea_model_B.caso + 1 == 1) || (Aenea_model_B.caso + 1 == 2)
                  || (Aenea_model_B.caso + 1 == 4) || (Aenea_model_B.caso + 1 ==
                   5)) {
                Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                  Aenea_model_B.caso;
                Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
              } else {
                Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                  Aenea_model_B.caso;
                Aenea_model_B.S[Aenea_model_B.Switch_h] +=
                  Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
              }
            }
          } else {
            rtb_y_b = !rtb_y_p;
            if (Ap_sel && rtb_y_b) {
              for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11;
                   Aenea_model_B.caso++) {
                if ((Aenea_model_B.caso + 1 == 1) || (Aenea_model_B.caso + 1 ==
                     2) || (Aenea_model_B.caso + 1 == 4) || (Aenea_model_B.caso
                     + 1 == 5) || (Aenea_model_B.caso + 1 == 3)) {
                  Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                    Aenea_model_B.caso;
                  Aenea_model_B.S[Aenea_model_B.Switch_h] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
                } else {
                  Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                    Aenea_model_B.caso;
                  Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
                }
              }
            } else if (tmp_0 && rtb_y_b) {
              for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11;
                   Aenea_model_B.caso++) {
                if ((Aenea_model_B.caso + 1 == 4) || (Aenea_model_B.caso + 1 ==
                     5) || (Aenea_model_B.caso + 1 == 3)) {
                  Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                    Aenea_model_B.caso;
                  Aenea_model_B.S[Aenea_model_B.Switch_h] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
                } else {
                  Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                    Aenea_model_B.caso;
                  Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
                }
              }
            } else if (rtb_y_e && rtb_y_b) {
              for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11;
                   Aenea_model_B.caso++) {
                if ((Aenea_model_B.caso + 1 == 1) || (Aenea_model_B.caso + 1 ==
                     2) || (Aenea_model_B.caso + 1 == 3)) {
                  Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                    Aenea_model_B.caso;
                  Aenea_model_B.S[Aenea_model_B.Switch_h] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
                } else {
                  Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                    Aenea_model_B.caso;
                  Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
                }
              }
            } else {
              if (tmp && rtb_y_b) {
                for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11;
                     Aenea_model_B.caso++) {
                  if (Aenea_model_B.caso + 1 == 3) {
                    Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                      Aenea_model_B.caso;
                    Aenea_model_B.S[Aenea_model_B.Switch_h] +=
                      Aenea_model_ConstP.Constant13_Value[Aenea_model_B.caso];
                  } else {
                    Aenea_model_B.Switch_h = 11 * Aenea_model_B.caso +
                      Aenea_model_B.caso;
                    Aenea_model_B.S[Aenea_model_B.Switch_h] += 1.0E+40;
                  }
                }
              }
            }
          }
        }
      }
    }

    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 11;
         Aenea_model_B.Switch_oz++) {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.Switch_h = Aenea_model_B.Switch_oz + 11 *
          Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_h] = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso
             ++) {
          Aenea_model_B.klm_gain_m[Aenea_model_B.Switch_h] += Aenea_model_B.H[11
            * Aenea_model_B.caso + Aenea_model_B.Switch_oz] *
            Aenea_model_DW.p_prd[18 * Aenea_model_B.caso +
            Aenea_model_B.soglia_dist];
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
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 11;
         Aenea_model_B.Switch_oz++) {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.klm_gain_m[Aenea_model_B.soglia_dist + 18 *
          Aenea_model_B.Switch_oz] = Aenea_model_B.ab[11 *
          Aenea_model_B.soglia_dist + Aenea_model_B.Switch_oz];
      }

      Aenea_model_B.residui[Aenea_model_B.Switch_oz] -=
        Aenea_model_B.dv1[Aenea_model_B.Switch_oz];
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
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 18;
         Aenea_model_B.Switch_oz++) {
      Aenea_model_B.klm_gain_c[Aenea_model_B.Switch_oz] = 0.0;
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 11;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.klm_gain_c[Aenea_model_B.Switch_oz] +=
          Aenea_model_B.klm_gain_m[18 * Aenea_model_B.soglia_dist +
          Aenea_model_B.Switch_oz] *
          Aenea_model_B.residui[Aenea_model_B.soglia_dist];
      }

      Aenea_model_B.x_est[Aenea_model_B.Switch_oz] =
        Aenea_model_DW.x_prd[Aenea_model_B.Switch_oz] +
        Aenea_model_B.klm_gain_c[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 2] =
        h[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 3] =
        j[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 4] =
        l[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 5] =
        m[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 6] =
        n[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 7] =
        o[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 8] =
        p[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 9] =
        q[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 10] =
        r[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 11] =
        s[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 12] =
        t[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 13] =
        u[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 14] =
        v[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 15] =
        w[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 16] =
        x_0[Aenea_model_B.Switch_oz];
      Aenea_model_B.F[18 * Aenea_model_B.Switch_oz + 17] =
        y[Aenea_model_B.Switch_oz];
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.Switch_h = Aenea_model_B.Switch_oz + 18 *
          Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain[Aenea_model_B.Switch_h] = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 11; Aenea_model_B.caso
             ++) {
          Aenea_model_B.klm_gain[Aenea_model_B.Switch_h] +=
            Aenea_model_B.klm_gain_m[18 * Aenea_model_B.caso +
            Aenea_model_B.Switch_oz] * Aenea_model_B.H[11 *
            Aenea_model_B.soglia_dist + Aenea_model_B.caso];
        }
      }

      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.a_b = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso
             ++) {
          Aenea_model_B.a_b += Aenea_model_B.klm_gain[18 * Aenea_model_B.caso +
            Aenea_model_B.Switch_oz] * Aenea_model_DW.p_prd[18 *
            Aenea_model_B.soglia_dist + Aenea_model_B.caso];
        }

        Aenea_model_B.caso = 18 * Aenea_model_B.soglia_dist +
          Aenea_model_B.Switch_oz;
        Aenea_model_B.dv[Aenea_model_B.caso] =
          Aenea_model_DW.p_prd[Aenea_model_B.caso] - Aenea_model_B.a_b;
      }
    }

    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.x_est[0]);
    Aenea_model_B.Gain_h = (Aenea_model_B.x_est[2] + 6.378137E+6) *
      (Aenea_model_B.x_est[2] + 6.378137E+6);
    Aenea_model_B.F[36] = -(0.02 * Aenea_model_B.x_est[3]) /
      Aenea_model_B.Gain_h;
    Aenea_model_B.F[54] = 0.02 / (Aenea_model_B.x_est[2] + 6.378137E+6);
    Aenea_model_B.F[1] = 0.02 * Aenea_model_B.x_est[4] * std::sin
      (Aenea_model_B.x_est[0]) / (Aenea_model_B.Switch_j *
      Aenea_model_B.Switch_j * (Aenea_model_B.x_est[2] + 6.378137E+6));
    Aenea_model_B.F[37] = -(0.02 * Aenea_model_B.x_est[4]) /
      (Aenea_model_B.Gain_h * Aenea_model_B.Switch_j);
    Aenea_model_B.F[73] = 0.02 / ((Aenea_model_B.x_est[2] + 6.378137E+6) *
      Aenea_model_B.Switch_j);
    Aenea_model_f_pred_F1B(Aenea_model_B.x_est, 6.378137E+6, 0.02,
      Aenea_model_DW.x_prd);
    for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 18;
         Aenea_model_B.Switch_oz++) {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.Switch_h = Aenea_model_B.Switch_oz + 18 *
          Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain[Aenea_model_B.Switch_h] = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso
             ++) {
          Aenea_model_B.klm_gain[Aenea_model_B.Switch_h] += Aenea_model_B.F[18 *
            Aenea_model_B.caso + Aenea_model_B.Switch_oz] * Aenea_model_B.dv[18 *
            Aenea_model_B.soglia_dist + Aenea_model_B.caso];
        }
      }

      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.Switch_h = Aenea_model_B.Switch_oz + 18 *
          Aenea_model_B.soglia_dist;
        Aenea_model_DW.p_prd[Aenea_model_B.Switch_h] = 0.0;
        for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso
             ++) {
          Aenea_model_DW.p_prd[Aenea_model_B.Switch_h] +=
            Aenea_model_B.klm_gain[18 * Aenea_model_B.caso +
            Aenea_model_B.Switch_oz] * Aenea_model_B.F[18 * Aenea_model_B.caso +
            Aenea_model_B.soglia_dist];
        }
      }
    }

    for (Aenea_model_B.caso = 0; Aenea_model_B.caso < 18; Aenea_model_B.caso++)
    {
      Aenea_model_B.Switch_h = 18 * Aenea_model_B.caso + Aenea_model_B.caso;
      Aenea_model_DW.p_prd[Aenea_model_B.Switch_h] +=
        Aenea_model_ConstP.Constant16_Value[Aenea_model_B.caso];
    }

    Aenea_model_B.Lat_K = Aenea_model_B.x_est[0];
    Aenea_model_B.Long_K = Aenea_model_B.x_est[1];
    Aenea_model_B.h_K = Aenea_model_B.x_est[2];
    Aenea_model_B.vd_K = Aenea_model_B.x_est[5];
    Aenea_model_B.v_K = std::sqrt(Aenea_model_B.x_est[3] * Aenea_model_B.x_est[3]
      + Aenea_model_B.x_est[4] * Aenea_model_B.x_est[4]);
    Aenea_model_B.imbardata = rt_atan2d_snf(Aenea_model_B.x_est[4],
      Aenea_model_B.x_est[3]);
  }

  // End of Outputs for SubSystem: '<S4>/Filter2'

  // Gain: '<S13>/Gain'
  Aenea_model_B.Gain_h = 1.0E+7 * Aenea_model_B.Lat_K;

  // DataTypeConversion: '<S13>/Data Type Conversion'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S13>/Data Type Conversion'
  Aenea_model_B.DataTypeConversion_g[0] = Aenea_model_B.a_b < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b)) :
    static_cast<int32_T>(static_cast<uint32_T>(Aenea_model_B.a_b));

  // Gain: '<S13>/Gain'
  Aenea_model_B.Gain_h = 1.0E+7 * Aenea_model_B.Long_K;

  // DataTypeConversion: '<S13>/Data Type Conversion'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S13>/Data Type Conversion'
  Aenea_model_B.DataTypeConversion_g[1] = Aenea_model_B.a_b < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b)) :
    static_cast<int32_T>(static_cast<uint32_T>(Aenea_model_B.a_b));

  // Gain: '<S13>/Gain'
  Aenea_model_B.Gain_h = 1000.0 * Aenea_model_B.h_K;

  // DataTypeConversion: '<S13>/Data Type Conversion'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
  //   Constant: '<S13>/alt_r'
  //   Gain: '<S13>/Gain'

  Aenea_model_B.DataTypeConversion_g[2] = Aenea_model_B.a_b < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b)) :
    static_cast<int32_T>(static_cast<uint32_T>(Aenea_model_B.a_b));
  Aenea_model_B.DataTypeConversion_g[3] = 0;

  // Gain: '<S13>/Gain1'
  Aenea_model_B.Gain_h = 100.0 * Aenea_model_B.v_K;

  // DataTypeConversion: '<S13>/Data Type Conversion1'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
  //   Constant: '<S13>/vel y'
  //   Gain: '<S13>/Gain1'

  Aenea_model_B.DataTypeConversion1_j[0] = static_cast<int16_T>
    (Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.a_b)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.a_b))));
  Aenea_model_B.DataTypeConversion1_j[1] = 0;

  // Gain: '<S13>/Gain1'
  Aenea_model_B.Gain_h = 100.0 * Aenea_model_B.vd_K;

  // DataTypeConversion: '<S13>/Data Type Conversion1'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S13>/Data Type Conversion1'
  Aenea_model_B.DataTypeConversion1_j[2] = static_cast<int16_T>
    (Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.a_b)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.a_b))));

  // Gain: '<S551>/Gain1'
  Aenea_model_B.Gain1_k = 0.017453292519943295 * Aenea_model_B.imbardata;

  // Gain: '<S13>/Gain2'
  Aenea_model_B.Gain_h = 100.0 * Aenea_model_B.Gain1_k;

  // DataTypeConversion: '<S13>/Data Type Conversion2'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S13>/Data Type Conversion2'
  Aenea_model_B.DataTypeConversion2 = static_cast<uint16_T>(Aenea_model_B.a_b <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S20>/Data Type Conversion' incorporates:
  //   Constant: '<S20>/airspeed groundspeed alt climb1'

  Aenea_model_B.AGAC[0] = static_cast<real32_T>(Aenea_model_B.num_254);
  Aenea_model_B.AGAC[1] = 0.0F;
  Aenea_model_B.AGAC[2] = static_cast<real32_T>(Aenea_model_B.h_K);
  Aenea_model_B.AGAC[3] = static_cast<real32_T>(Aenea_model_B.vd_K);

  // Gain: '<S29>/Gain'
  Aenea_model_B.Gain_h = 57.295779513082323 * Aenea_model_B.Gain1_k;

  // Switch: '<S30>/Switch2' incorporates:
  //   Abs: '<S30>/Abs'
  //   Constant: '<S30>/Constant2'
  //   Sum: '<S30>/Sum'

  if (!(Aenea_model_B.Gain_h > 0.0)) {
    Aenea_model_B.Gain_h = 360.0 - std::abs(Aenea_model_B.Gain_h);
  }

  // End of Switch: '<S30>/Switch2'

  // DataTypeConversion: '<S20>/Data Type Conversion1'
  if (Aenea_model_B.Gain_h < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_h);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_h);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S20>/Data Type Conversion1'
  Aenea_model_B.Heading_f = static_cast<int16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(static_cast<
    uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(static_cast<int16_T>
    (static_cast<uint16_T>(Aenea_model_B.a_b))));

  // S-Function (byte2any_svd): '<S565>/Byte Unpack' incorporates:
  //   Constant: '<S565>/registro memoria2 13'


  // Unpack: <S565>/Byte Unpack
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

  // Sum: '<S580>/Sum5' incorporates:
  //   DataTypeConversion: '<S7>/Data Type Conversion12'
  //   DataTypeConversion: '<S7>/Data Type Conversion4'
  //   Product: '<S580>/Divide2'
  //   Sum: '<S580>/Sum2'
  //   Sum: '<S580>/Sum3'

  Aenea_model_B.Sum5 = (Aenea_model_ConstB.DataTypeConversion5 -
                        static_cast<real_T>(Aenea_model_B.ByteUnpack[1])) /
    static_cast<real_T>(Aenea_model_B.ByteUnpack[0] - Aenea_model_B.ByteUnpack[1]);

  // Gain: '<S25>/Gain2'
  Aenea_model_B.SignPreSat = 100.0 * Aenea_model_B.Sum5;

  // S-Function (GPS_sfun): '<S566>/S-Function Builder'
  GPS_sfun_Outputs_wrapper(&Aenea_model_B.Lat, &Aenea_model_B.Long,
    &Aenea_model_B.V, &Aenea_model_B.quota, &Aenea_model_B.heading,
    &Aenea_model_B.SFunctionBuilder_o6);

  // Chart: '<S34>/ STATI' incorporates:
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
              (Aenea_model_B.num_254 >= 1.0) &&
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

  // End of Chart: '<S34>/ STATI'

  // Product: '<S577>/Divide' incorporates:
  //   DataTypeConversion: '<S7>/Data Type Conversion6'
  //   DataTypeConversion: '<S7>/Data Type Conversion7'
  //   Product: '<S578>/Divide'
  //   Sum: '<S577>/Sum1'

  Aenea_model_B.Gain_h = Aenea_model_B.ByteUnpack[2] - Aenea_model_B.ByteUnpack
    [3];

  // Sum: '<S577>/Sum3' incorporates:
  //   Constant: '<S577>/Constant8'
  //   Constant: '<S577>/Constant9'
  //   DataTypeConversion: '<S7>/Data Type Conversion7'
  //   Product: '<S577>/Divide'
  //   Product: '<S577>/Multiply'
  //   Sum: '<S577>/Sum'
  //   Sum: '<S577>/Sum2'

  Aenea_model_B.Long_Home = (Aenea_model_ConstB.DataTypeConversion13 -
    static_cast<real_T>(Aenea_model_B.ByteUnpack[3])) / Aenea_model_B.Gain_h *
    0.87266462599716477 + -0.55850536063818546;

  // MATLAB Function: '<S34>/MATLAB Function'
  if (Aenea_model_B.modo == 3.0) {
    Aenea_model_B.Switch_h = 1;
    Aenea_model_B.caso = 0;
  } else if (Aenea_model_B.modo == 4.0) {
    Aenea_model_B.caso = 1;
    Aenea_model_B.Switch_h = 0;
  } else {
    Aenea_model_B.Switch_h = 0;
    Aenea_model_B.caso = 0;
  }

  // Sum: '<S578>/Sum3' incorporates:
  //   Constant: '<S578>/Constant8'
  //   Constant: '<S578>/Constant9'
  //   DataTypeConversion: '<S7>/Data Type Conversion19'
  //   Product: '<S578>/Divide'
  //   Product: '<S578>/Multiply'
  //   Sum: '<S578>/Sum'
  //   Sum: '<S578>/Sum2'

  Aenea_model_B.Ato_selector = (Aenea_model_ConstB.DataTypeConversion16 -
    static_cast<real_T>(Aenea_model_B.ByteUnpack[3])) / Aenea_model_B.Gain_h *
    0.52359877559829882 + -0.26179938779914941;

  // Saturate: '<S578>/Saturation'
  if (Aenea_model_B.Ato_selector > 0.26179938779914941) {
    Aenea_model_B.Ato_selector = 0.26179938779914941;
  } else {
    if (Aenea_model_B.Ato_selector < -0.26179938779914941) {
      Aenea_model_B.Ato_selector = -0.26179938779914941;
    }
  }

  // End of Saturate: '<S578>/Saturation'

  // Sum: '<S33>/Sum2'
  Aenea_model_B.Gain1_m = Aenea_model_B.Ato_selector - Aenea_model_B.Gain1_m;

  // Sum: '<S347>/Sum' incorporates:
  //   DiscreteIntegrator: '<S338>/Integrator'
  //   Product: '<S343>/PProd Out'

  Aenea_model_B.Gain_h = Aenea_model_B.Gain1_m * -1.9179999828338623 +
    Aenea_model_DW.Integrator_DSTATE;

  // Saturate: '<S345>/Saturation'
  if (Aenea_model_B.Gain_h > 0.31415926535897931) {
    Aenea_model_B.Gain1_k = 0.31415926535897931;
  } else if (Aenea_model_B.Gain_h < -0.55850536063818546) {
    Aenea_model_B.Gain1_k = -0.55850536063818546;
  } else {
    Aenea_model_B.Gain1_k = Aenea_model_B.Gain_h;
  }

  // End of Saturate: '<S345>/Saturation'

  // MultiPortSwitch: '<S300>/Switch Bumpless 2'
  if (static_cast<int32_T>(Aenea_model_B.switch_equilibratore) == 0) {
    Aenea_model_B.SwitchBumpless2 = Aenea_model_B.Long_Home;
  } else {
    Aenea_model_B.SwitchBumpless2 = Aenea_model_B.Gain1_k;
  }

  // End of MultiPortSwitch: '<S300>/Switch Bumpless 2'

  // MultiPortSwitch: '<S305>/Multiport Switch2' incorporates:
  //   MATLAB Function: '<S34>/MATLAB Function'

  if (Aenea_model_B.caso != 0) {
    // Switch: '<S305>/Switch1' incorporates:
    //   Constant: '<S305>/Constant5'

    if (!(Aenea_model_B.num_254 >= 16.0)) {
      Aenea_model_B.SwitchBumpless2 = 0.0;
    }

    // End of Switch: '<S305>/Switch1'
  }

  // End of MultiPortSwitch: '<S305>/Multiport Switch2'

  // Logic: '<S35>/AND'
  Ap_sel = ((Aenea_model_B.switch_manetta != 0.0) &&
            (Aenea_model_B.switch_equilibratore != 0.0) &&
            (Aenea_model_B.switch_alettoni != 0.0) &&
            (Aenea_model_B.switch_timone != 0.0));

  // Chart: '<S35>/Chart' incorporates:
  //   Logic: '<S35>/AND'

  if (Aenea_model_DW.is_active_c21_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c21_Aenea_model = 1U;
    Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_In;
    Aenea_model_B.Wp_selector = 0.0;
    Aenea_model_B.Vec_selector = 0.0;
    Aenea_model_B.Ato_selector = 0.0;
    Aenea_model_B.Al_selector = 0.0;
    Aenea_model_B.Go_home_selector = 0.0;
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
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 2.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Vettoriale;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 1.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 1.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
        Aenea_model_B.Wp_selector = 1.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 5.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_GoHome;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 1.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 1.0;
        Aenea_model_B.Go_home_selector = 0.0;
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
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 1.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
        Aenea_model_B.Wp_selector = 1.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 2.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Vettoriale;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 1.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 1.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
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
        Aenea_model_B.Go_home_selector = 0.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 1.0;
      }
      break;

     case Aenea_model_IN_In:
      Aenea_model_In(&Ap_sel, &Aenea_model_B.Ato_selector,
                     &Aenea_model_B.Al_selector, &Aenea_model_B.Wp_selector,
                     &Aenea_model_B.Vec_selector,
                     &Aenea_model_B.Go_home_selector);
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
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 1.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_Waypoint;
        Aenea_model_B.Wp_selector = 1.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
      } else if (Aenea_model_B.modo == 5.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_GoHome;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 1.0;
      } else if (Aenea_model_B.modo == 4.0) {
        Aenea_model_DW.is_c21_Aenea_model = Aenea_model_IN_AutoLanding;
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 0.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 1.0;
        Aenea_model_B.Go_home_selector = 0.0;
      } else {
        Aenea_model_B.Wp_selector = 0.0;
        Aenea_model_B.Vec_selector = 1.0;
        Aenea_model_B.Ato_selector = 0.0;
        Aenea_model_B.Al_selector = 0.0;
        Aenea_model_B.Go_home_selector = 0.0;
      }
      break;

     default:
      // case IN_Waypoint:
      Aenea_model_Waypoint(&Ap_sel, &Aenea_model_B.Ato_selector,
                           &Aenea_model_B.Al_selector,
                           &Aenea_model_B.Wp_selector,
                           &Aenea_model_B.Vec_selector,
                           &Aenea_model_B.Go_home_selector);
      break;
    }
  }

  // End of Chart: '<S35>/Chart'

  // Outputs for Enabled SubSystem: '<S35>/DECOLLO AUTOMATICO' incorporates:
  //   EnablePort: '<S436>/Enable'

  if (Aenea_model_B.Ato_selector > 0.0) {
    // Outputs for Triggered SubSystem: '<S436>/Sample and Hold' incorporates:
    //   TriggerPort: '<S444>/Trigger'

    // Memory: '<S436>/Memory'
    rt_ZCFcn(RISING_ZERO_CROSSING,&Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_a,
             (Aenea_model_DW.Memory_PreviousInput_p));

    // End of Outputs for SubSystem: '<S436>/Sample and Hold'

    // Outputs for Triggered SubSystem: '<S436>/Sample and Hold1' incorporates:
    //   TriggerPort: '<S445>/Trigger'

    // Memory: '<S436>/Memory1'
    rt_ZCFcn(RISING_ZERO_CROSSING,&Aenea_model_PrevZCX.SampleandHold1_Trig_ZCE,
             (Aenea_model_DW.Memory1_PreviousInput_e));

    // End of Outputs for SubSystem: '<S436>/Sample and Hold1'

    // Chart: '<S436>/Chart1'
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
          Aenea_model_B.eq_rot = 0.0;
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
          Aenea_model_B.eq_rot = 2.0;
        }
        break;

       case Aenea_model_IN_Fase_2_ATO:
        if ((Aenea_model_B.num_254 >= 18.0) && (Aenea_model_B.v_K >= 10.0)) {
          Aenea_model_B.theta_ground_selector = 1.0;
          Aenea_model_DW.is_c1_Aenea_model = Aenea_model_IN_Fase_3_ATO;
        } else {
          Aenea_model_B.Fase_ATO = 2.0;
          Aenea_model_B.psi_ref_selector = 0.0;
          Aenea_model_B.h_ref = 0.0;
          Aenea_model_B.eq_rot = 2.0;
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

    // End of Chart: '<S436>/Chart1'

    // Update for Memory: '<S436>/Memory'
    Aenea_model_DW.Memory_PreviousInput_p = Aenea_model_B.psi_ref_selector;

    // Update for Memory: '<S436>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput_e = Aenea_model_B.theta_ground_selector;
  }

  // End of Outputs for SubSystem: '<S35>/DECOLLO AUTOMATICO'

  // MultiPortSwitch: '<S306>/Multiport Switch2' incorporates:
  //   MATLAB Function: '<S34>/MATLAB Function'

  if (Aenea_model_B.Switch_h != 0) {
    // MultiPortSwitch: '<S306>/Multiport Switch1' incorporates:
    //   Gain: '<S355>/Gain1'

    switch (static_cast<int32_T>(Aenea_model_B.Fase_ATO)) {
     case 0:
      Aenea_model_B.SwitchBumpless2 = 0.017453292519943295 *
        Aenea_model_B.eq_rot;
      break;

     case 1:
      Aenea_model_B.SwitchBumpless2 = 0.017453292519943295 *
        Aenea_model_B.eq_rot;
      break;

     case 2:
      Aenea_model_B.SwitchBumpless2 = 0.017453292519943295 *
        Aenea_model_B.eq_rot;
      break;

     case 3:
      break;
    }

    // End of MultiPortSwitch: '<S306>/Multiport Switch1'
  }

  // End of MultiPortSwitch: '<S306>/Multiport Switch2'

  // MultiPortSwitch: '<S33>/Switch Bumpless 1'
  if (static_cast<int32_T>(Aenea_model_B.switch_equilibratore) != 0) {
    // MultiPortSwitch: '<S300>/Switch 1' incorporates:
    //   Abs: '<S300>/Abs1'
    //   Constant: '<S300>/Constant1'
    //   Constant: '<S300>/Constant2'
    //   Constant: '<S300>/Constant3'
    //   Gain: '<S300>/Gain'
    //   MultiPortSwitch: '<S300>/Switch  2'
    //   Product: '<S300>/Product3'
    //   Product: '<S300>/Product4'
    //   Product: '<S300>/Product5'
    //   Sum: '<S300>/Sum3'
    //   Trigonometry: '<S300>/Trigonometric Function'

    if (static_cast<int32_T>(Aenea_model_B.switch_equilibratore) == 0) {
      Aenea_model_B.Switch_j = 0.0;
      Aenea_model_B.a_b = 0.0;
    } else {
      // Abs: '<S300>/Abs1' incorporates:
      //   Abs: '<S300>/Abs'

      Aenea_model_B.a_b = std::abs(Aenea_model_B.Gain1);
      Aenea_model_B.Switch_j = (Aenea_model_B.DataTypeConversion1_c[4] - std::
        sin(Aenea_model_B.a_b) * Aenea_model_B.DataTypeConversion1_c[5]) *
        -0.125;
      Aenea_model_B.a_b *= -0.525;
    }

    // End of MultiPortSwitch: '<S300>/Switch 1'

    // Sum: '<S300>/Sum2' incorporates:
    //   Sum: '<S300>/Sum'

    Aenea_model_B.Long_Home = (Aenea_model_B.SwitchBumpless2 -
      Aenea_model_B.Switch_j) - Aenea_model_B.a_b;

    // Saturate: '<S300>/saturatore E2'
    if (Aenea_model_B.Long_Home > 0.31415926535897931) {
      Aenea_model_B.Long_Home = 0.31415926535897931;
    } else {
      if (Aenea_model_B.Long_Home < -0.55850536063818546) {
        Aenea_model_B.Long_Home = -0.55850536063818546;
      }
    }

    // End of Saturate: '<S300>/saturatore E2'
  }

  // End of MultiPortSwitch: '<S33>/Switch Bumpless 1'

  // Sum: '<S25>/Sum' incorporates:
  //   Constant: '<S25>/Constant2'
  //   Gain: '<S26>/Gain'

  Aenea_model_B.Long_Home = 57.295779513082323 * Aenea_model_B.Long_Home + 90.0;

  // Product: '<S575>/Divide' incorporates:
  //   DataTypeConversion: '<S7>/Data Type Conversion8'
  //   DataTypeConversion: '<S7>/Data Type Conversion9'
  //   Product: '<S576>/Divide'
  //   Sum: '<S575>/Sum1'

  Aenea_model_B.Ato_selector = Aenea_model_B.ByteUnpack[4] -
    Aenea_model_B.ByteUnpack[5];

  // Sum: '<S575>/Sum3' incorporates:
  //   Constant: '<S575>/Constant8'
  //   Constant: '<S575>/Constant9'
  //   DataTypeConversion: '<S7>/Data Type Conversion9'
  //   Product: '<S575>/Divide'
  //   Product: '<S575>/Multiply'
  //   Sum: '<S575>/Sum'
  //   Sum: '<S575>/Sum2'

  Aenea_model_B.Sum3_h = (Aenea_model_ConstB.DataTypeConversion14 -
    static_cast<real_T>(Aenea_model_B.ByteUnpack[5])) /
    Aenea_model_B.Ato_selector * 0.87266462599716477 + -0.4014257279586958;

  // Gain: '<S576>/Gain' incorporates:
  //   Constant: '<S576>/Constant8'
  //   Constant: '<S576>/Constant9'
  //   DataTypeConversion: '<S7>/Data Type Conversion21'
  //   Product: '<S576>/Divide'
  //   Product: '<S576>/Multiply'
  //   Sum: '<S576>/Sum'
  //   Sum: '<S576>/Sum2'
  //   Sum: '<S576>/Sum3'

  Aenea_model_B.Ato_selector = -((Aenea_model_ConstB.DataTypeConversion17 -
    static_cast<real_T>(Aenea_model_B.ByteUnpack[5])) /
    Aenea_model_B.Ato_selector * 1.0471975511965976 + -0.52359877559829882);

  // Saturate: '<S576>/Saturation'
  if (Aenea_model_B.Ato_selector > 0.52359877559829882) {
    Aenea_model_B.Ato_selector = 0.52359877559829882;
  } else {
    if (Aenea_model_B.Ato_selector < -0.52359877559829882) {
      Aenea_model_B.Ato_selector = -0.52359877559829882;
    }
  }

  // End of Saturate: '<S576>/Saturation'

  // Sum: '<S33>/Sum5'
  Aenea_model_B.Gain1 = Aenea_model_B.Ato_selector - Aenea_model_B.Gain1;

  // DiscreteIntegrator: '<S388>/Integrator' incorporates:
  //   Constant: '<S301>/Constant3'
  //   Sum: '<S301>/Sum'

  if ((Aenea_model_B.Fase_ATO - 2.0 > 0.0) &&
      (Aenea_model_DW.Integrator_PrevResetState <= 0)) {
    Aenea_model_DW.Integrator_DSTATE_l = 0.0;
  }

  // Sum: '<S397>/Sum' incorporates:
  //   DiscreteIntegrator: '<S388>/Integrator'
  //   Product: '<S393>/PProd Out'

  Aenea_model_B.Ato_selector = Aenea_model_B.Gain1 * 1.1000000238418579 +
    Aenea_model_DW.Integrator_DSTATE_l;

  // Saturate: '<S395>/Saturation'
  if (Aenea_model_B.Ato_selector > 0.47123889803846897) {
    Aenea_model_B.Saturation_a = 0.47123889803846897;
  } else if (Aenea_model_B.Ato_selector < -0.4014257279586958) {
    Aenea_model_B.Saturation_a = -0.4014257279586958;
  } else {
    Aenea_model_B.Saturation_a = Aenea_model_B.Ato_selector;
  }

  // End of Saturate: '<S395>/Saturation'

  // MultiPortSwitch: '<S301>/Switch Bumpless 1' incorporates:
  //   Constant: '<S301>/Constant1'
  //   Product: '<S301>/Product3'

  if (static_cast<int32_T>(Aenea_model_B.switch_alettoni) == 0) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = Aenea_model_B.DataTypeConversion1_c[3] * 0.125;
  }

  // End of MultiPortSwitch: '<S301>/Switch Bumpless 1'

  // Sum: '<S301>/Sum2'
  Aenea_model_B.Sum2_k2 = Aenea_model_B.Saturation_a - Aenea_model_B.a_b;

  // MultiPortSwitch: '<S33>/Switch Bumpless 3' incorporates:
  //   Saturate: '<S33>/saturatore A1'

  if (static_cast<int32_T>(Aenea_model_B.switch_alettoni) == 0) {
    Aenea_model_B.Switch_j = Aenea_model_B.Sum3_h;
  } else if (Aenea_model_B.Sum2_k2 > 0.47123889803846897) {
    // Saturate: '<S33>/saturatore A1'
    Aenea_model_B.Switch_j = 0.47123889803846897;
  } else if (Aenea_model_B.Sum2_k2 < -0.4014257279586958) {
    // Saturate: '<S33>/saturatore A1'
    Aenea_model_B.Switch_j = -0.4014257279586958;
  } else {
    // Saturate: '<S33>/saturatore A1'
    Aenea_model_B.Switch_j = Aenea_model_B.Sum2_k2;
  }

  // End of MultiPortSwitch: '<S33>/Switch Bumpless 3'

  // Saturate: '<S33>/saturatore A'
  if (Aenea_model_B.Switch_j > 0.47123889803846897) {
    Aenea_model_B.Alettoni = 0.47123889803846897;
  } else if (Aenea_model_B.Switch_j < -0.4014257279586958) {
    Aenea_model_B.Alettoni = -0.4014257279586958;
  } else {
    Aenea_model_B.Alettoni = Aenea_model_B.Switch_j;
  }

  // End of Saturate: '<S33>/saturatore A'

  // MultiPortSwitch: '<S33>/Switch Bumpless 5' incorporates:
  //   Gain: '<S33>/Gain1'

  if (static_cast<int32_T>(Aenea_model_B.switch_alettoni) == 0) {
    Aenea_model_B.a_b = Aenea_model_B.Sum3_h;
  } else {
    Aenea_model_B.a_b = -Aenea_model_B.Alettoni;
  }

  // End of MultiPortSwitch: '<S33>/Switch Bumpless 5'

  // Sum: '<S25>/Sum1' incorporates:
  //   Constant: '<S25>/Constant2'
  //   Gain: '<S27>/Gain'

  Aenea_model_B.Switch_j = 57.295779513082323 * Aenea_model_B.a_b + 90.0;

  // DiscreteTransferFcn: '<S302>/Discrete Washout Filter'
  Aenea_model_B.aterra_tmp_tmp = Aenea_model_B.DataTypeConversion1_c[5] - -0.995
    * Aenea_model_DW.DiscreteWashoutFilter_states;

  // MultiPortSwitch: '<S33>/Switch Bumpless 6' incorporates:
  //   Constant: '<S579>/Constant8'
  //   Constant: '<S579>/Constant9'
  //   DataTypeConversion: '<S7>/Data Type Conversion10'
  //   DataTypeConversion: '<S7>/Data Type Conversion11'
  //   MultiPortSwitch: '<S33>/Switch Bumpless 4'
  //   Product: '<S579>/Divide'
  //   Product: '<S579>/Multiply'
  //   Sum: '<S579>/Sum1'
  //   Sum: '<S579>/Sum2'
  //   Sum: '<S579>/Sum3'
  //   Sum: '<S579>/Sum4'

  if (static_cast<int32_T>(Aenea_model_B.switch_timone) == 0) {
    Aenea_model_B.Sum2_k2 = (Aenea_model_ConstB.DataTypeConversion15 -
      static_cast<real_T>(Aenea_model_B.ByteUnpack[7])) / static_cast<real_T>
      (Aenea_model_B.ByteUnpack[6] - Aenea_model_B.ByteUnpack[7]) *
      1.0471975511965976 + -0.52359877559829882;
  } else {
    if (static_cast<int32_T>(Aenea_model_B.switch_timone) == 0) {
      // MultiPortSwitch: '<S33>/Switch Bumpless 4' incorporates:
      //   Constant: '<S579>/Constant8'
      //   Constant: '<S579>/Constant9'
      //   DataTypeConversion: '<S7>/Data Type Conversion10'
      //   DataTypeConversion: '<S7>/Data Type Conversion11'
      //   Product: '<S579>/Divide'
      //   Product: '<S579>/Multiply'
      //   Sum: '<S579>/Sum1'
      //   Sum: '<S579>/Sum2'
      //   Sum: '<S579>/Sum3'
      //   Sum: '<S579>/Sum4'

      Aenea_model_B.Sum2_k2 = (Aenea_model_ConstB.DataTypeConversion15 -
        static_cast<real_T>(Aenea_model_B.ByteUnpack[7])) / static_cast<real_T>
        (Aenea_model_B.ByteUnpack[6] - Aenea_model_B.ByteUnpack[7]) *
        1.0471975511965976 + -0.52359877559829882;
    } else {
      // MultiPortSwitch: '<S33>/Switch Bumpless 4' incorporates:
      //   Constant: '<S33>/r_rif'
      //   DiscreteTransferFcn: '<S302>/Discrete Washout Filter'
      //   Gain: '<S6>/Gain3'
      //   Product: '<S33>/  CONTROLLO     IMBARDATA      INVERSA'
      //   Product: '<S33>/Product'
      //   Sum: '<S33>/Sum1'
      //   Sum: '<S33>/Sum9'

      Aenea_model_B.Sum2_k2 = (0.0 - (Aenea_model_B.aterra_tmp_tmp +
        -Aenea_model_DW.DiscreteWashoutFilter_states)) * -0.40000000596046448 +
        static_cast<real_T>(Aenea_model_ConstB.K_imb_inv) * 0.0078125 *
        Aenea_model_B.Sum2_k2;
    }

    // Saturate: '<S33>/saturatore R'
    if (Aenea_model_B.Sum2_k2 > 0.52359877559829882) {
      Aenea_model_B.Sum2_k2 = 0.52359877559829882;
    } else {
      if (Aenea_model_B.Sum2_k2 < -0.52359877559829882) {
        Aenea_model_B.Sum2_k2 = -0.52359877559829882;
      }
    }

    // End of Saturate: '<S33>/saturatore R'
  }

  // End of MultiPortSwitch: '<S33>/Switch Bumpless 6'

  // Sum: '<S25>/Sum2' incorporates:
  //   Constant: '<S25>/Constant2'
  //   Gain: '<S28>/Gain'

  Aenea_model_B.Sum2_k2 = 57.295779513082323 * Aenea_model_B.Sum2_k2 + 90.0;

  // DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
  //   Constant: '<S17>/Constant'

  Aenea_model_B.Heading[0] = 4U;

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  if (Aenea_model_B.SignPreSat < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.SignPreSat);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.SignPreSat);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  Aenea_model_B.Heading[1] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  if (Aenea_model_B.Long_Home < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Long_Home);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Long_Home);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  Aenea_model_B.Heading[2] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  if (Aenea_model_B.Switch_j < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Switch_j);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Switch_j);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  Aenea_model_B.Heading[3] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  if (Aenea_model_B.Sum2_k2 < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Sum2_k2);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Sum2_k2);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  Aenea_model_B.Heading[4] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));
  Aenea_model_B.Heading[5] = 0U;
  Aenea_model_B.Heading[6] = 0U;
  Aenea_model_B.Heading[7] = 0U;

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  if (Aenea_model_ConstB.Saturation < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_ConstB.Saturation);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_ConstB.Saturation);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  Aenea_model_B.Heading[8] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // Memory: '<S2>/Memory'
  Aenea_model_B.Memory_o = Aenea_model_DW.Memory_PreviousInput_e4;

  // Outputs for Enabled SubSystem: '<S571>/Subsystem1' incorporates:
  //   EnablePort: '<S573>/Enable'

  if (Aenea_model_B.SFunction_o14 > 0) {
    // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
    // Inport: '<S573>/T' incorporates:
    //   DataTypeConversion: '<S569>/Data Type Conversion'

    Aenea_model_B.T = Aenea_model_B.SFunctionBuilder_o1;

    // End of Outputs for SubSystem: '<S565>/Execution_loop'
  }

  // End of Outputs for SubSystem: '<S571>/Subsystem1'

  // Switch: '<S571>/Switch1' incorporates:
  //   Constant: '<S571>/Constant'
  //   MATLAB Function: '<S1>/MATLAB Function1'
  //   RelationalOperator: '<S571>/NotEqual'
  //   Switch: '<S571>/Switch'

  if (15.0F != Aenea_model_DW.riferimenti[12]) {
    // DataTypeConversion: '<Root>/Data Type Conversion1'
    Aenea_model_B.DataTypeConversion1_m = Aenea_model_DW.riferimenti[12];
  } else if (Aenea_model_B.T > 0.0) {
    // Switch: '<S571>/Switch' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion1'

    Aenea_model_B.DataTypeConversion1_m = static_cast<real32_T>(Aenea_model_B.T);
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion1'
    Aenea_model_B.DataTypeConversion1_m = Aenea_model_DW.riferimenti[12];
  }

  // End of Switch: '<S571>/Switch1'

  // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   DataTypeConversion: '<S569>/Data Type Conversion1'
  //   Gain: '<S2>/Pa to hPa'

  Aenea_model_B.DataTypeConversion = static_cast<real32_T>(0.01 *
    Aenea_model_B.SFunctionBuilder_o2);

  // DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
  //   DataTypeConversion: '<S569>/Data Type Conversion'

  Aenea_model_B.f = std::floor(Aenea_model_B.SFunctionBuilder_o1);

  // End of Outputs for SubSystem: '<S565>/Execution_loop'
  if (rtIsNaNF(Aenea_model_B.f) || rtIsInfF(Aenea_model_B.f)) {
    Aenea_model_B.f = 0.0F;
  } else {
    Aenea_model_B.f = std::fmod(Aenea_model_B.f, 65536.0F);
  }

  // DataTypeConversion: '<S2>/Data Type Conversion2'
  Aenea_model_B.DataTypeConversion2_m = static_cast<int16_T>(Aenea_model_B.f <
    0.0F ? static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.f)))) : static_cast<int32_T>(
    static_cast<int16_T>(static_cast<uint16_T>(Aenea_model_B.f))));

  // Outputs for Enabled SubSystem: '<S35>/Subsystem1' incorporates:
  //   EnablePort: '<S438>/Enable'

  if (Aenea_model_B.Al_selector > 0.0) {
    // DataTypeConversion: '<S438>/Data Type Conversion4' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'

    for (Aenea_model_B.i = 0; Aenea_model_B.i < 42; Aenea_model_B.i++) {
      Aenea_model_B.DataTypeConversion4[Aenea_model_B.i] =
        Aenea_model_DW.WP_dbP_AL[Aenea_model_B.i];
    }

    // End of DataTypeConversion: '<S438>/Data Type Conversion4'

    // MATLAB Function: '<S438>/CALIBRATING_HOME_COORDINATES' incorporates:
    //   DataTypeConversion: '<S438>/Data Type Conversion4'
    //   MATLAB Function: '<S451>/MATLAB Function'

    Aenea_model_B.Long_Home = Aenea_model_B.DataTypeConversion4[30] *
      0.017453292519943295;
    Aenea_model_B.h_Home = Aenea_model_B.DataTypeConversion4[36];
    Aenea_model_B.a_b = std::cos(Aenea_model_B.DataTypeConversion4[25] *
      0.017453292519943295);
    Aenea_model_B.Sum2_k2 = std::sin(Aenea_model_B.DataTypeConversion4[24] *
      0.017453292519943295);
    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.DataTypeConversion4[24] *
      0.017453292519943295);
    Aenea_model_B.SignPreSat = Aenea_model_B.DataTypeConversion4[31] *
      0.017453292519943295 - Aenea_model_B.DataTypeConversion4[30] *
      0.017453292519943295;
    Aenea_model_B.SignPreSat = rt_atan2d_snf(std::sin(Aenea_model_B.SignPreSat) *
      Aenea_model_B.a_b, std::sin(Aenea_model_B.DataTypeConversion4[25] *
      0.017453292519943295) * Aenea_model_B.Switch_j - std::cos
      (Aenea_model_B.SignPreSat) * (Aenea_model_B.Sum2_k2 * Aenea_model_B.a_b));
    if (Aenea_model_B.SignPreSat < 0.0) {
      Aenea_model_B.SignPreSat = 6.2831853071795862 - std::abs
        (Aenea_model_B.SignPreSat);
    }

    // MATLAB Function: '<S451>/MATLAB Function' incorporates:
    //   MATLAB Function: '<S438>/CALIBRATING_HOME_COORDINATES'
    //   Trigonometry: '<S522>/SinCos'

    Aenea_model_B.a_b = std::cos(Aenea_model_B.SignPreSat);
    Aenea_model_B.Al_selector = std::asin(Aenea_model_B.Switch_j *
      -0.00015678559364639647 * Aenea_model_B.a_b + Aenea_model_B.Sum2_k2 *
      0.99999998770913878);
    Aenea_model_B.SignPreSat = std::sin(Aenea_model_B.SignPreSat);

    // MATLAB Function: '<S451>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Gain: '<S467>/Gain'
    //   Gain: '<S468>/Gain'
    //   MATLAB Function: '<S451>/MATLAB Function'

    Aenea_model_B.y[12] = 57.295779513082323 * Aenea_model_B.Al_selector;
    Aenea_model_B.y[15] = 57.295779513082323 * (rt_atan2d_snf
      (Aenea_model_B.SignPreSat * -0.00015678559364639647 *
       Aenea_model_B.Switch_j, 0.99999998770913878 - Aenea_model_B.Sum2_k2 * std::
       sin(Aenea_model_B.Al_selector)) + Aenea_model_B.Long_Home);
    Aenea_model_B.y[3] = 1.0;
    Aenea_model_B.y[6] = 0.0;
    Aenea_model_B.y[9] = 0.0;
    Aenea_model_B.y[18] = Aenea_model_B.h_Home + 45.0;

    // MATLAB Function: '<S451>/MATLAB Function'
    Aenea_model_B.Al_selector = std::asin(Aenea_model_B.Switch_j *
      -0.00012542847510211208 * Aenea_model_B.a_b + Aenea_model_B.Sum2_k2 *
      0.99999999213384883);

    // MATLAB Function: '<S451>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Constant: '<S451>/Constant1'
    //   Gain: '<S467>/Gain'
    //   Gain: '<S468>/Gain'
    //   MATLAB Function: '<S451>/MATLAB Function'

    Aenea_model_B.y[13] = 57.295779513082323 * Aenea_model_B.Al_selector;
    Aenea_model_B.y[16] = 57.295779513082323 * (rt_atan2d_snf
      (Aenea_model_B.SignPreSat * -0.00012542847510211208 *
       Aenea_model_B.Switch_j, 0.99999999213384883 - Aenea_model_B.Sum2_k2 * std::
       sin(Aenea_model_B.Al_selector)) + Aenea_model_B.Long_Home);
    Aenea_model_B.y[1] = 20.0;
    Aenea_model_B.y[4] = 1.0;
    Aenea_model_B.y[7] = 0.0;
    Aenea_model_B.y[10] = 0.0;
    Aenea_model_B.y[19] = Aenea_model_B.h_Home + 45.0;

    // MATLAB Function: '<S451>/MATLAB Function'
    Aenea_model_B.Al_selector = std::asin(Aenea_model_B.Switch_j *
      0.00031357118343873296 * Aenea_model_B.a_b + Aenea_model_B.Sum2_k2 *
      0.99999995083655524);

    // MATLAB Function: '<S451>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Constant: '<S451>/Constant'
    //   Constant: '<S451>/Constant1'
    //   Gain: '<S467>/Gain'
    //   Gain: '<S468>/Gain'
    //   MATLAB Function: '<S451>/MATLAB Function'

    Aenea_model_B.y[14] = 57.295779513082323 * Aenea_model_B.Al_selector;
    Aenea_model_B.y[17] = 57.295779513082323 * (rt_atan2d_snf
      (Aenea_model_B.SignPreSat * 0.00031357118343873296 *
       Aenea_model_B.Switch_j, 0.99999995083655524 - Aenea_model_B.Sum2_k2 * std::
       sin(Aenea_model_B.Al_selector)) + Aenea_model_B.Long_Home);
    Aenea_model_B.y[2] = 20.0;
    Aenea_model_B.y[8] = 0.0;
    Aenea_model_B.y[11] = 0.0;
    Aenea_model_B.y[20] = Aenea_model_B.h_Home + 45.0;
    Aenea_model_B.y[0] = 25.0;
    Aenea_model_B.y[5] = 0.0;

    // Gain: '<S456>/Gain' incorporates:
    //   DataTypeConversion: '<S438>/Data Type Conversion4'
    //   MATLAB Function: '<S438>/CALIBRATING_HOME_COORDINATES'

    Aenea_model_B.Gain = Aenea_model_B.DataTypeConversion4[24] *
      0.017453292519943295 * 57.295779513082323;

    // Switch: '<S532>/Switch' incorporates:
    //   Abs: '<S532>/Abs'
    //   Bias: '<S532>/Bias'
    //   Bias: '<S532>/Bias1'
    //   Constant: '<S532>/Constant2'
    //   Constant: '<S533>/Constant'
    //   Math: '<S532>/Math Function1'
    //   RelationalOperator: '<S533>/Compare'

    if (std::abs(Aenea_model_B.Gain) > 180.0) {
      Aenea_model_B.Switch_j = rt_modd_snf(Aenea_model_B.Gain + 180.0, 360.0) +
        -180.0;
    } else {
      Aenea_model_B.Switch_j = Aenea_model_B.Gain;
    }

    // End of Switch: '<S532>/Switch'

    // Abs: '<S529>/Abs1'
    Aenea_model_B.Sum2_k2 = std::abs(Aenea_model_B.Switch_j);

    // RelationalOperator: '<S531>/Compare' incorporates:
    //   Constant: '<S531>/Constant'

    Ap_sel = (Aenea_model_B.Sum2_k2 > 90.0);

    // Switch: '<S529>/Switch' incorporates:
    //   Bias: '<S529>/Bias'
    //   Bias: '<S529>/Bias1'
    //   Constant: '<S521>/Constant'
    //   Constant: '<S521>/Constant1'
    //   Gain: '<S529>/Gain'
    //   Product: '<S529>/Divide1'
    //   Switch: '<S521>/Switch1'

    if (Ap_sel) {
      // Signum: '<S529>/Sign1'
      if (Aenea_model_B.Switch_j < 0.0) {
        Aenea_model_B.Switch_j = -1.0;
      } else if (Aenea_model_B.Switch_j > 0.0) {
        Aenea_model_B.Switch_j = 1.0;
      } else if (Aenea_model_B.Switch_j == 0.0) {
        Aenea_model_B.Switch_j = 0.0;
      } else {
        Aenea_model_B.Switch_j = (rtNaN);
      }

      // End of Signum: '<S529>/Sign1'
      Aenea_model_B.Switch_j *= -(Aenea_model_B.Sum2_k2 + -90.0) + 90.0;
      Aenea_model_B.Switch_oz = 180;
    } else {
      Aenea_model_B.Switch_oz = 0;
    }

    // End of Switch: '<S529>/Switch'

    // Gain: '<S457>/Gain'
    Aenea_model_B.Gain_o = 57.295779513082323 * Aenea_model_B.Long_Home;

    // Sum: '<S521>/Sum'
    Aenea_model_B.Long_Home = static_cast<real_T>(Aenea_model_B.Switch_oz) +
      Aenea_model_B.Gain_o;

    // Sum: '<S455>/Sum1' incorporates:
    //   Gain: '<S459>/Gain'

    Aenea_model_B.Sum2_k2 = 57.295779513082323 * Aenea_model_B.Lat_K -
      Aenea_model_B.Switch_j;

    // Switch: '<S526>/Switch' incorporates:
    //   Abs: '<S526>/Abs'
    //   Bias: '<S526>/Bias'
    //   Bias: '<S526>/Bias1'
    //   Constant: '<S526>/Constant2'
    //   Constant: '<S527>/Constant'
    //   Math: '<S526>/Math Function1'
    //   RelationalOperator: '<S527>/Compare'

    if (std::abs(Aenea_model_B.Sum2_k2) > 180.0) {
      Aenea_model_B.Sum2_k2 = rt_modd_snf(Aenea_model_B.Sum2_k2 + 180.0, 360.0)
        + -180.0;
    }

    // End of Switch: '<S526>/Switch'

    // Abs: '<S523>/Abs1'
    Aenea_model_B.Al_selector = std::abs(Aenea_model_B.Sum2_k2);

    // Switch: '<S523>/Switch' incorporates:
    //   Bias: '<S523>/Bias'
    //   Bias: '<S523>/Bias1'
    //   Constant: '<S520>/Constant'
    //   Constant: '<S520>/Constant1'
    //   Constant: '<S525>/Constant'
    //   Gain: '<S523>/Gain'
    //   Product: '<S523>/Divide1'
    //   RelationalOperator: '<S525>/Compare'
    //   Switch: '<S520>/Switch1'

    if (Aenea_model_B.Al_selector > 90.0) {
      // Signum: '<S523>/Sign1'
      if (Aenea_model_B.Sum2_k2 < 0.0) {
        Aenea_model_B.Sum2_k2 = -1.0;
      } else if (Aenea_model_B.Sum2_k2 > 0.0) {
        Aenea_model_B.Sum2_k2 = 1.0;
      } else if (Aenea_model_B.Sum2_k2 == 0.0) {
        Aenea_model_B.Sum2_k2 = 0.0;
      } else {
        Aenea_model_B.Sum2_k2 = (rtNaN);
      }

      // End of Signum: '<S523>/Sign1'
      Aenea_model_B.Sum2_k2 *= -(Aenea_model_B.Al_selector + -90.0) + 90.0;
      Aenea_model_B.Switch_oz = 180;
    } else {
      Aenea_model_B.Switch_oz = 0;
    }

    // End of Switch: '<S523>/Switch'

    // Switch: '<S530>/Switch' incorporates:
    //   Abs: '<S530>/Abs'
    //   Bias: '<S530>/Bias'
    //   Bias: '<S530>/Bias1'
    //   Constant: '<S530>/Constant2'
    //   Constant: '<S534>/Constant'
    //   Math: '<S530>/Math Function1'
    //   RelationalOperator: '<S534>/Compare'

    if (std::abs(Aenea_model_B.Long_Home) > 180.0) {
      Aenea_model_B.Long_Home = rt_modd_snf(Aenea_model_B.Long_Home + 180.0,
        360.0) + -180.0;
    }

    // End of Switch: '<S530>/Switch'

    // Sum: '<S520>/Sum' incorporates:
    //   Gain: '<S458>/Gain'
    //   Sum: '<S455>/Sum1'

    Aenea_model_B.Sum_h = (57.295779513082323 * Aenea_model_B.Long_K -
      Aenea_model_B.Long_Home) + static_cast<real_T>(Aenea_model_B.Switch_oz);

    // Gain: '<S536>/Gain1'
    Aenea_model_B.Switch_j *= 0.017453292519943295;

    // Trigonometry: '<S539>/Trigonometric Function1'
    Aenea_model_B.Al_selector = std::sin(Aenea_model_B.Switch_j);

    // Sum: '<S539>/Sum1' incorporates:
    //   Constant: '<S539>/Constant'
    //   Product: '<S539>/Product1'

    Aenea_model_B.Al_selector = 1.0 - 0.0066943799901413295 *
      Aenea_model_B.Al_selector * Aenea_model_B.Al_selector;

    // Product: '<S535>/Product1' incorporates:
    //   Constant: '<S535>/Constant1'
    //   Sqrt: '<S535>/sqrt'

    Aenea_model_B.Long_Home = 6.378137E+6 / std::sqrt(Aenea_model_B.Al_selector);

    // Switch: '<S524>/Switch' incorporates:
    //   Abs: '<S524>/Abs'
    //   Bias: '<S524>/Bias'
    //   Bias: '<S524>/Bias1'
    //   Constant: '<S524>/Constant2'
    //   Constant: '<S528>/Constant'
    //   Math: '<S524>/Math Function1'
    //   RelationalOperator: '<S528>/Compare'

    if (std::abs(Aenea_model_B.Sum_h) > 180.0) {
      Aenea_model_B.Sum_h = rt_modd_snf(Aenea_model_B.Sum_h + 180.0, 360.0) +
        -180.0;
    }

    // End of Switch: '<S524>/Switch'

    // Sum: '<S522>/Sum2' incorporates:
    //   Constant: '<S535>/Constant'
    //   Constant: '<S535>/Constant2'
    //   Constant: '<S535>/Constant3'
    //   Gain: '<S519>/Gain1'
    //   Product: '<S522>/dEast'
    //   Product: '<S522>/dNorth'
    //   Product: '<S522>/x*cos'
    //   Product: '<S522>/y*sin'
    //   Product: '<S535>/Product2'
    //   Product: '<S535>/Product3'
    //   Product: '<S535>/Product4'
    //   Sum: '<S535>/Sum1'
    //   Trigonometry: '<S535>/Trigonometric Function'
    //   Trigonometry: '<S535>/Trigonometric Function1'
    //   Trigonometry: '<S535>/Trigonometric Function2'

    Aenea_model_B.Long_Home = 0.017453292519943295 * Aenea_model_B.Sum2_k2 /
      rt_atan2d_snf(1.0, Aenea_model_B.Long_Home * 0.99330562000985867 /
                    Aenea_model_B.Al_selector) * Aenea_model_B.a_b + 1.0 /
      rt_atan2d_snf(1.0, Aenea_model_B.Long_Home * std::cos
                    (Aenea_model_B.Switch_j)) * (0.017453292519943295 *
      Aenea_model_B.Sum_h) * Aenea_model_B.SignPreSat;

    // Gain: '<S460>/Gain'
    Aenea_model_B.Sum_h = 57.295779513082323 * Aenea_model_B.Lat_K;

    // Gain: '<S461>/Gain'
    Aenea_model_B.Gain_hh = 57.295779513082323 * Aenea_model_B.Long_K;

    // MATLAB Function: '<S438>/ALLINEAMENTO' incorporates:
    //   Memory: '<S438>/Memory7'

    Aenea_model_B.b_a_tmp = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 11];
    Aenea_model_B.a_b = std::sin((Aenea_model_B.b_a_tmp - Aenea_model_B.Sum_h) *
      3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.dist_fut = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 14];
    Aenea_model_B.dist = (Aenea_model_B.dist_fut - Aenea_model_B.Gain_hh) *
      3.1415926535897931 / 180.0;
    Aenea_model_B.Sum2_k2 = std::sin(Aenea_model_B.dist / 2.0);
    Aenea_model_B.Al_selector = Aenea_model_B.b_a_tmp * 3.1415926535897931 /
      180.0;
    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.Al_selector);
    Aenea_model_B.a_tmp_tmp = Aenea_model_B.Sum_h * 3.1415926535897931 / 180.0;
    Aenea_model_B.SignPreSat = std::cos(Aenea_model_B.a_tmp_tmp);
    Aenea_model_B.a_b = Aenea_model_B.SignPreSat * Aenea_model_B.Switch_j *
      (Aenea_model_B.Sum2_k2 * Aenea_model_B.Sum2_k2) + Aenea_model_B.a_b *
      Aenea_model_B.a_b;
    Aenea_model_B.Sum2_k2 = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::
      sqrt(1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    if (Aenea_model_DW.Memory7_PreviousInput > 1.0) {
      Aenea_model_B.a_tmp_tmp = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11];
      Aenea_model_B.Al_selector = Aenea_model_B.a_tmp_tmp * 3.1415926535897931 /
        180.0;
      Aenea_model_B.a_b = std::cos(Aenea_model_B.Al_selector);
      Aenea_model_B.dist = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14];
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.dist_fut - Aenea_model_B.dist) *
        3.1415926535897931 / 180.0;
      Aenea_model_B.Al_selector = rt_atan2d_snf(std::sin
        (Aenea_model_B.psi_ref_tmp) * Aenea_model_B.Switch_j, std::sin
        (Aenea_model_B.y[static_cast<int32_T>
         (Aenea_model_DW.Memory7_PreviousInput) + 11] * 3.1415926535897931 /
         180.0) * Aenea_model_B.a_b - std::sin(Aenea_model_B.Al_selector) *
        Aenea_model_B.Switch_j * std::cos(Aenea_model_B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.a_tmp_tmp = std::sin((Aenea_model_B.Sum_h -
        Aenea_model_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.dist = std::sin((Aenea_model_B.Gain_hh - Aenea_model_B.dist)
        * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.a_b = Aenea_model_B.a_b * Aenea_model_B.SignPreSat *
        (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_tmp_tmp *
        Aenea_model_B.a_tmp_tmp;
      Aenea_model_B.dist = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt
        (1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    } else {
      Aenea_model_B.Al_selector = rt_atan2d_snf(std::sin(Aenea_model_B.dist) *
        Aenea_model_B.Switch_j, std::sin(Aenea_model_B.Al_selector) *
        Aenea_model_B.SignPreSat - std::cos(Aenea_model_B.dist) * (std::sin
        (Aenea_model_B.a_tmp_tmp) * Aenea_model_B.Switch_j)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.dist = 0.0;
    }

    if (Aenea_model_B.Al_selector < 0.0) {
      Aenea_model_B.Al_selector = 360.0 - std::abs(Aenea_model_B.Al_selector);
    }

    Aenea_model_B.a_b = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 2];
    if (Aenea_model_B.a_b == 1.0) {
      Aenea_model_B.psi_ref_tmp = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput + 1.0) + 11];
      Aenea_model_B.a_tmp_tmp = std::sin((Aenea_model_B.psi_ref_tmp -
        Aenea_model_B.b_a_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.b_a_tmp = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput + 1.0) + 14] -
        Aenea_model_B.dist_fut) * 3.1415926535897931 / 180.0;
      Aenea_model_B.dist_fut = std::sin(Aenea_model_B.b_a_tmp / 2.0);
      Aenea_model_B.psi_ref_tmp = Aenea_model_B.psi_ref_tmp * 3.1415926535897931
        / 180.0;
      Aenea_model_B.a_fut_tmp = std::cos(Aenea_model_B.psi_ref_tmp);
      Aenea_model_B.dist_fut = Aenea_model_B.Switch_j * Aenea_model_B.a_fut_tmp *
        (Aenea_model_B.dist_fut * Aenea_model_B.dist_fut) +
        Aenea_model_B.a_tmp_tmp * Aenea_model_B.a_tmp_tmp;
      Aenea_model_B.dist_fut = rt_atan2d_snf(std::sqrt(Aenea_model_B.dist_fut),
        std::sqrt(1.0 - Aenea_model_B.dist_fut)) * 2.0 * 6.378137E+6;
      Aenea_model_B.Switch_j = rt_atan2d_snf(std::sin(Aenea_model_B.b_a_tmp) *
        Aenea_model_B.a_fut_tmp, std::sin(Aenea_model_B.psi_ref_tmp) *
        Aenea_model_B.Switch_j - std::cos(Aenea_model_B.b_a_tmp) * (std::sin
        (Aenea_model_B.y[static_cast<int32_T>
         (Aenea_model_DW.Memory7_PreviousInput) + 11] * 3.1415926535897931 /
         180.0) * Aenea_model_B.a_fut_tmp)) * 180.0 / 3.1415926535897931;
      if (Aenea_model_B.Switch_j < 0.0) {
        Aenea_model_B.Switch_j = 360.0 - std::abs(Aenea_model_B.Switch_j);
      }

      if (Aenea_model_DW.Memory7_PreviousInput > 1.0) {
        Aenea_model_B.Switch_j = std::abs(Aenea_model_B.Switch_j -
          Aenea_model_B.Al_selector);
      } else {
        Aenea_model_B.Switch_j = std::abs(Aenea_model_B.Switch_j - rt_atan2d_snf
          (std::sin((Aenea_model_B.y[static_cast<int32_T>
                     (Aenea_model_DW.Memory7_PreviousInput) + 14] -
                     Aenea_model_B.Gain_hh) * 3.1415926535897931 / 180.0) * std::
           cos(Aenea_model_B.y[static_cast<int32_T>
               (Aenea_model_DW.Memory7_PreviousInput) + 11] * 3.1415926535897931
               / 180.0), std::sin(Aenea_model_B.y[static_cast<int32_T>
          (Aenea_model_DW.Memory7_PreviousInput) + 11] * 3.1415926535897931 /
          180.0) * std::cos(Aenea_model_B.Sum_h * 3.1415926535897931 / 180.0) -
           std::cos(Aenea_model_B.y[static_cast<int32_T>
                    (Aenea_model_DW.Memory7_PreviousInput) + 11] *
                    3.1415926535897931 / 180.0) * std::sin(Aenea_model_B.Sum_h *
          3.1415926535897931 / 180.0) * std::cos((Aenea_model_B.y
          [static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput) + 14] -
          Aenea_model_B.Gain_hh) * 3.1415926535897931 / 180.0)) * 180.0 /
          3.1415926535897931);
      }
    } else {
      Aenea_model_B.dist_fut = 0.0;
      Aenea_model_B.Switch_j = 0.0;
    }

    if (Aenea_model_DW.Memory7_PreviousInput < 2.0) {
      Aenea_model_B.SignPreSat = 0.0;
    } else if (Aenea_model_DW.Memory7_PreviousInput == 2.0) {
      Aenea_model_B.b_a_tmp = std::cos(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931 /
        180.0);
      Aenea_model_B.Gain_hh = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14] -
        Aenea_model_B.Gain_hh) * 3.1415926535897931 / 180.0;
      Aenea_model_B.SignPreSat = std::abs(Aenea_model_B.Al_selector -
        rt_atan2d_snf(std::sin(Aenea_model_B.Gain_hh) * Aenea_model_B.b_a_tmp,
                      std::sin(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931 /
        180.0) * Aenea_model_B.SignPreSat - std::cos(Aenea_model_B.Gain_hh) *
                      (std::sin(Aenea_model_B.Sum_h * 3.1415926535897931 / 180.0)
                       * Aenea_model_B.b_a_tmp)) * 180.0 / 3.1415926535897931);
    } else {
      Aenea_model_B.SignPreSat = std::cos(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931 /
        180.0);
      Aenea_model_B.Sum_h = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 2.0) + 11] * 3.1415926535897931 /
        180.0;
      Aenea_model_B.Gain_hh = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14] - Aenea_model_B.y[
        static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      Aenea_model_B.SignPreSat = rt_atan2d_snf(std::sin(Aenea_model_B.Gain_hh) *
        Aenea_model_B.SignPreSat, std::cos(Aenea_model_B.Sum_h) * std::sin
        (Aenea_model_B.y[static_cast<int32_T>
         (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931
         / 180.0) - std::sin(Aenea_model_B.Sum_h) * Aenea_model_B.SignPreSat *
        std::cos(Aenea_model_B.Gain_hh)) * 180.0 / 3.1415926535897931;
      if (Aenea_model_B.SignPreSat < 0.0) {
        Aenea_model_B.SignPreSat = 360.0 - std::abs(Aenea_model_B.SignPreSat);
      }

      Aenea_model_B.SignPreSat = std::abs(Aenea_model_B.Al_selector -
        Aenea_model_B.SignPreSat);
    }

    if (Aenea_model_B.Switch_j <= 3.0) {
      Aenea_model_B.Switch_j = 1.0;
      Aenea_model_B.tolleranza_distWP_fut = 20;
    } else if (Aenea_model_B.Switch_j <= 10.0) {
      Aenea_model_B.Switch_j = 30.0;
      Aenea_model_B.tolleranza_distWP_fut = 100;
    } else if ((Aenea_model_B.Switch_j > 10.0) && (Aenea_model_B.Switch_j <=
                50.0)) {
      Aenea_model_B.Switch_j = 80.0;
      Aenea_model_B.tolleranza_distWP_fut = 250;
    } else if ((Aenea_model_B.Switch_j > 50.0) && (Aenea_model_B.Switch_j <=
                90.0)) {
      Aenea_model_B.Switch_j = 100.0;
      Aenea_model_B.tolleranza_distWP_fut = 300;
    } else if ((Aenea_model_B.Switch_j > 90.0) && (Aenea_model_B.Switch_j <=
                120.0)) {
      Aenea_model_B.Switch_j = 150.0;
      Aenea_model_B.tolleranza_distWP_fut = 350;
    } else {
      Aenea_model_B.Switch_j = 200.0;
      Aenea_model_B.tolleranza_distWP_fut = 400;
    }

    if (Aenea_model_B.SignPreSat <= 10.0) {
      Aenea_model_B.soglia_dist = 80;
    } else if ((Aenea_model_B.SignPreSat > 10.0) && (Aenea_model_B.SignPreSat <=
                50.0)) {
      Aenea_model_B.soglia_dist = 200;
    } else if ((Aenea_model_B.SignPreSat > 50.0) && (Aenea_model_B.SignPreSat <=
                90.0)) {
      Aenea_model_B.soglia_dist = 300;
    } else if ((Aenea_model_B.SignPreSat > 90.0) && (Aenea_model_B.SignPreSat <=
                120.0)) {
      Aenea_model_B.soglia_dist = 350;
    } else {
      Aenea_model_B.soglia_dist = 400;
    }

    if (Aenea_model_B.a_b == 1.0) {
      Aenea_model_B.a_b = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput) - 1];
      if (Aenea_model_B.a_b <= 20.0) {
        Aenea_model_B.Switch_j *= 1.1;
      } else if ((Aenea_model_B.a_b <= 25.0) && (Aenea_model_B.a_b > 20.0)) {
        Aenea_model_B.Switch_j *= 1.2;
      } else if (Aenea_model_B.a_b <= 30.0) {
        if (Aenea_model_B.a_b > 25.0) {
          Aenea_model_B.Switch_j *= 1.3;
        } else {
          Aenea_model_B.Switch_j *= 1.4;
        }
      } else {
        Aenea_model_B.Switch_j *= 1.4;
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_B.Sum2_k2 > Aenea_model_B.Switch_j))) &&
          ((!(Aenea_model_B.dist > Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_B.Sum2_k2 > Aenea_model_B.Switch_j))) &&
          (Aenea_model_B.Sum2_k2 < Aenea_model_B.Switch_j)) {
        if (Aenea_model_B.dist_fut > Aenea_model_B.tolleranza_distWP_fut) {
          Aenea_model_DW.Memory7_PreviousInput++;
        } else if (Aenea_model_DW.Memory7_PreviousInput < 2.0) {
          Aenea_model_DW.Memory7_PreviousInput += 2.0;
        } else {
          Aenea_model_DW.flag_a = 1.0;
        }
      }
    } else {
      if (((!(Aenea_model_B.dist < Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_DW.flag_a == 0.0))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.soglia_dist)) || (!(Aenea_model_B.Sum2_k2 > 40.0)) ||
           (!(Aenea_model_DW.flag_a == 0.0)))) {
        Aenea_model_DW.flag_a = 1.0;
      }
    }

    if (!(Aenea_model_B.modo == 4.0)) {
      Aenea_model_DW.Memory7_PreviousInput = 1.0;
    }

    // End of MATLAB Function: '<S438>/ALLINEAMENTO'

    // Abs: '<S438>/Abs1'
    Aenea_model_B.a_b = std::abs(Aenea_model_B.Long_Home);

    // Chart: '<S438>/Chart1' incorporates:
    //   Memory: '<S438>/Memory1'
    //   Memory: '<S438>/Memory2'
    //   Memory: '<S438>/Memory5'

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
            (Aenea_model_B.a_b <= Aenea_model_B.h_K * 19.081136687728211 + 100.0)
            && (Aenea_model_B.a_b >= Aenea_model_B.h_K * 14.300666256711928 +
                100.0) && (Aenea_model_DW.Memory7_PreviousInput > 1.0)) {
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
        if ((Aenea_model_B.Long_Home >= Aenea_model_DW.Memory5_PreviousInput) &&
            ((Aenea_model_B.h_K <= Aenea_model_DW.Memory1_PreviousInput_f + 1.5)
             || (Aenea_model_B.h_K > Aenea_model_DW.Memory1_PreviousInput_f -
                 1.0))) {
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
        if ((Aenea_model_B.num_254 < 3.0) || (!(Aenea_model_B.modo != 4.0))) {
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

    // End of Chart: '<S438>/Chart1'

    // Outputs for Triggered SubSystem: '<S438>/Sample and Hold' incorporates:
    //   TriggerPort: '<S463>/Trigger'

    Aenea_model_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_l,
      (Aenea_model_B.approach_selector));
    if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
      // Inport: '<S463>/In' incorporates:
      //   Abs: '<S438>/Abs2'
      //   Sum: '<S455>/Sum'
      //   UnaryMinus: '<S455>/Ze2height'

      Aenea_model_B.In_c[0] = std::abs(-Aenea_model_B.h_K);
      Aenea_model_B.In_c[1] = Aenea_model_B.Long_Home;
    }

    // End of Outputs for SubSystem: '<S438>/Sample and Hold'

    // Outputs for Enabled SubSystem: '<S438>/APPROACH' incorporates:
    //   EnablePort: '<S449>/Enable'

    if (Aenea_model_B.trig_approach > 0.0) {
      // Product: '<S449>/Divide' incorporates:
      //   Constant: '<S449>/x_g0'
      //   Sum: '<S449>/Sum'

      Aenea_model_B.Sum2_k2 = Aenea_model_B.In_c[0] / (Aenea_model_B.In_c[1] -
        -100.0);

      // Abs: '<S449>/Abs' incorporates:
      //   Trigonometry: '<S449>/Atan'

      Aenea_model_B.Switch_j = std::abs(std::atan(Aenea_model_B.Sum2_k2));

      // DiscreteIntegrator: '<S449>/Discrete-Time Integrator'
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

      // Switch: '<S449>/Switch' incorporates:
      //   DiscreteIntegrator: '<S449>/Discrete-Time Integrator'

      Aenea_model_B.Switch_oz = (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j >
        0.0);

      // MATLAB Function: '<S449>/MATLAB Function'
      Aenea_model_B.tolleranza_distWP_fut = 0;
      if ((!Aenea_model_DW.x_not_empty) || (Aenea_model_B.Switch_oz == 0)) {
        Aenea_model_DW.x[0] = 1.5;
        Aenea_model_DW.x[1] = -200.0;
        Aenea_model_DW.x[2] = 0.01;
        Aenea_model_DW.x[3] = -2.0;
        Aenea_model_DW.x_not_empty = true;
      }

      Aenea_model_DW.x_new_not_empty = ((!Aenea_model_DW.x_new_not_empty) ||
        (Aenea_model_B.Switch_oz == 0) || Aenea_model_DW.x_new_not_empty);
      if ((!Aenea_model_DW.eps_not_empty) || (Aenea_model_B.Switch_oz == 0)) {
        Aenea_model_DW.eps[0] = 1.0;
        Aenea_model_DW.eps[1] = 1.0;
        Aenea_model_DW.eps[2] = 1.0;
        Aenea_model_DW.eps[3] = 1.0;
        Aenea_model_DW.eps_not_empty = true;
      }

      if ((!Aenea_model_DW.cycle_count_not_empty) || (Aenea_model_B.Switch_oz ==
           0)) {
        Aenea_model_DW.cycle_count = 0.0;
        Aenea_model_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(Aenea_model_DW.eps[0] < 0.1)) ||
                           ((!(Aenea_model_DW.eps[1] < 0.1)) ||
                            ((!(Aenea_model_DW.eps[2] < 0.1)) ||
                             (!(Aenea_model_DW.eps[3] < 0.1)))))) {
        std::memset(&Aenea_model_B.a[0], 0, sizeof(real_T) << 4U);
        Aenea_model_B.SignPreSat = std::exp((5.0 - Aenea_model_DW.x[1]) *
          -Aenea_model_DW.x[2]);
        Aenea_model_B.Gain_hh = std::tan(Aenea_model_B.Switch_j);
        Aenea_model_B.A[0] = 1.0;
        Aenea_model_B.A[4] = Aenea_model_B.Gain_hh;
        Aenea_model_B.A[8] = 0.0;
        Aenea_model_B.A[12] = 0.0;
        Aenea_model_B.A[1] = Aenea_model_DW.x[2];
        Aenea_model_B.A[5] = 0.0;
        Aenea_model_B.Sum_h = Aenea_model_DW.x[0] - Aenea_model_DW.x[3];
        Aenea_model_B.A[9] = Aenea_model_B.Sum_h;
        Aenea_model_B.A[13] = -Aenea_model_DW.x[2];
        Aenea_model_B.A[2] = Aenea_model_B.SignPreSat;
        Aenea_model_B.dist = Aenea_model_B.Sum_h * Aenea_model_DW.x[2];
        Aenea_model_B.A[6] = Aenea_model_B.dist * Aenea_model_B.SignPreSat;
        Aenea_model_B.A[10] = Aenea_model_B.Sum_h * (Aenea_model_DW.x[1] - 5.0) *
          Aenea_model_B.SignPreSat;
        Aenea_model_B.A[14] = 1.0;
        Aenea_model_B.A[3] = Aenea_model_DW.x[2] * 18.0 *
          Aenea_model_B.SignPreSat;
        Aenea_model_B.A[7] = Aenea_model_B.Sum_h * (Aenea_model_DW.x[2] *
          Aenea_model_DW.x[2]) * 18.0 * Aenea_model_B.SignPreSat;
        Aenea_model_B.Al_selector = Aenea_model_B.dist * 18.0;
        Aenea_model_B.A[11] = Aenea_model_B.Al_selector * (Aenea_model_DW.x[1] -
          5.0) * Aenea_model_B.SignPreSat + Aenea_model_B.Sum_h * 18.0 *
          Aenea_model_B.SignPreSat;
        Aenea_model_B.A[15] = -Aenea_model_DW.x[2] * 18.0 *
          Aenea_model_B.SignPreSat;
        Aenea_model_B.ipiv_n[0] = 1;
        Aenea_model_B.ipiv_n[1] = 2;
        Aenea_model_B.ipiv_n[2] = 3;
        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 3;
             Aenea_model_B.Switch_oz++) {
          Aenea_model_B.soglia_dist = Aenea_model_B.Switch_oz * 5;
          Aenea_model_B.i = 0;
          Aenea_model_B.ix = Aenea_model_B.soglia_dist;
          Aenea_model_B.a_b = std::abs(Aenea_model_B.A[Aenea_model_B.soglia_dist]);
          Aenea_model_B.jy = 2;
          while (Aenea_model_B.jy <= 4 - Aenea_model_B.Switch_oz) {
            Aenea_model_B.ix++;
            Aenea_model_B.dist_fut = std::abs(Aenea_model_B.A[Aenea_model_B.ix]);
            if (Aenea_model_B.dist_fut > Aenea_model_B.a_b) {
              Aenea_model_B.i = Aenea_model_B.jy - 1;
              Aenea_model_B.a_b = Aenea_model_B.dist_fut;
            }

            Aenea_model_B.jy++;
          }

          if (Aenea_model_B.A[Aenea_model_B.soglia_dist + Aenea_model_B.i] !=
              0.0) {
            if (Aenea_model_B.i != 0) {
              Aenea_model_B.i += Aenea_model_B.Switch_oz;
              Aenea_model_B.ipiv_n[Aenea_model_B.Switch_oz] = static_cast<int8_T>
                (Aenea_model_B.i + 1);
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.Switch_oz];
              Aenea_model_B.A[Aenea_model_B.Switch_oz] =
                Aenea_model_B.A[Aenea_model_B.i];
              Aenea_model_B.A[Aenea_model_B.i] = Aenea_model_B.a_b;
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.Switch_oz + 4];
              Aenea_model_B.A[Aenea_model_B.Switch_oz + 4] =
                Aenea_model_B.A[Aenea_model_B.i + 4];
              Aenea_model_B.A[Aenea_model_B.i + 4] = Aenea_model_B.a_b;
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.Switch_oz + 8];
              Aenea_model_B.A[Aenea_model_B.Switch_oz + 8] =
                Aenea_model_B.A[Aenea_model_B.i + 8];
              Aenea_model_B.A[Aenea_model_B.i + 8] = Aenea_model_B.a_b;
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.Switch_oz + 12];
              Aenea_model_B.A[Aenea_model_B.Switch_oz + 12] =
                Aenea_model_B.A[Aenea_model_B.i + 12];
              Aenea_model_B.A[Aenea_model_B.i + 12] = Aenea_model_B.a_b;
            }

            Aenea_model_B.ix = (Aenea_model_B.soglia_dist -
                                Aenea_model_B.Switch_oz) + 4;
            Aenea_model_B.i = Aenea_model_B.soglia_dist + 1;
            while (Aenea_model_B.i + 1 <= Aenea_model_B.ix) {
              Aenea_model_B.A[Aenea_model_B.i] /=
                Aenea_model_B.A[Aenea_model_B.soglia_dist];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix = Aenea_model_B.soglia_dist;
          Aenea_model_B.jy = Aenea_model_B.soglia_dist + 4;
          Aenea_model_B.c = 0;
          while (Aenea_model_B.c <= 2 - Aenea_model_B.Switch_oz) {
            if (Aenea_model_B.A[Aenea_model_B.jy] != 0.0) {
              Aenea_model_B.a_b = -Aenea_model_B.A[Aenea_model_B.jy];
              Aenea_model_B.c_ix = Aenea_model_B.soglia_dist + 1;
              Aenea_model_B.i = (Aenea_model_B.ix - Aenea_model_B.Switch_oz) + 8;
              Aenea_model_B.ijA = Aenea_model_B.ix + 5;
              while (Aenea_model_B.ijA + 1 <= Aenea_model_B.i) {
                Aenea_model_B.A[Aenea_model_B.ijA] +=
                  Aenea_model_B.A[Aenea_model_B.c_ix] * Aenea_model_B.a_b;
                Aenea_model_B.c_ix++;
                Aenea_model_B.ijA++;
              }
            }

            Aenea_model_B.jy += 4;
            Aenea_model_B.ix += 4;
            Aenea_model_B.c++;
          }
        }

        Aenea_model_B.p[0] = 1;
        Aenea_model_B.p[1] = 2;
        Aenea_model_B.p[2] = 3;
        Aenea_model_B.p[3] = 4;
        if (Aenea_model_B.ipiv_n[0] > 1) {
          Aenea_model_B.Switch_oz = Aenea_model_B.p[Aenea_model_B.ipiv_n[0] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_n[0] - 1] = 1;
          Aenea_model_B.p[0] = static_cast<int8_T>(Aenea_model_B.Switch_oz);
        }

        if (Aenea_model_B.ipiv_n[1] > 2) {
          Aenea_model_B.Switch_oz = Aenea_model_B.p[Aenea_model_B.ipiv_n[1] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_n[1] - 1] = Aenea_model_B.p[1];
          Aenea_model_B.p[1] = static_cast<int8_T>(Aenea_model_B.Switch_oz);
        }

        if (Aenea_model_B.ipiv_n[2] > 3) {
          Aenea_model_B.Switch_oz = Aenea_model_B.p[Aenea_model_B.ipiv_n[2] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_n[2] - 1] = Aenea_model_B.p[2];
          Aenea_model_B.p[2] = static_cast<int8_T>(Aenea_model_B.Switch_oz);
        }

        Aenea_model_B.c = Aenea_model_B.p[0] - 1;
        Aenea_model_B.a[(Aenea_model_B.p[0] - 1) << 2] = 1.0;
        Aenea_model_B.ix = 0;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.Switch_oz = Aenea_model_B.c << 2;
          Aenea_model_B.soglia_dist = Aenea_model_B.Switch_oz + Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.jy = Aenea_model_B.Switch_oz + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.jy] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        Aenea_model_B.c = Aenea_model_B.p[1] - 1;
        Aenea_model_B.a[((Aenea_model_B.p[1] - 1) << 2) + 1] = 1.0;
        Aenea_model_B.ix = 1;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.Switch_oz = Aenea_model_B.c << 2;
          Aenea_model_B.soglia_dist = Aenea_model_B.Switch_oz + Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.jy = Aenea_model_B.Switch_oz + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.jy] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        Aenea_model_B.c = Aenea_model_B.p[2] - 1;
        Aenea_model_B.a[((Aenea_model_B.p[2] - 1) << 2) + 2] = 1.0;
        Aenea_model_B.ix = 2;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.Switch_oz = Aenea_model_B.c << 2;
          Aenea_model_B.soglia_dist = Aenea_model_B.Switch_oz + Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.jy = Aenea_model_B.Switch_oz + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.jy] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        Aenea_model_B.jy = (Aenea_model_B.p[3] - 1) << 2;
        Aenea_model_B.a[Aenea_model_B.jy + 3] = 1.0;
        Aenea_model_B.ix = 3;
        while (Aenea_model_B.ix + 1 < 5) {
          Aenea_model_B.Switch_oz = Aenea_model_B.jy + Aenea_model_B.ix;
          if (Aenea_model_B.a[Aenea_model_B.Switch_oz] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.ix + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.soglia_dist = Aenea_model_B.jy + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.soglia_dist] -=
                Aenea_model_B.a[Aenea_model_B.Switch_oz] * Aenea_model_B.A
                [(Aenea_model_B.ix << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.ix++;
        }

        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 4;
             Aenea_model_B.Switch_oz++) {
          Aenea_model_B.soglia_dist = Aenea_model_B.Switch_oz << 2;
          Aenea_model_B.a_b = Aenea_model_B.a[Aenea_model_B.soglia_dist + 3];
          if (Aenea_model_B.a_b != 0.0) {
            Aenea_model_B.a[Aenea_model_B.soglia_dist + 3] = Aenea_model_B.a_b /
              Aenea_model_B.A[15];
            Aenea_model_B.i = 0;
            while (Aenea_model_B.i <= 2) {
              Aenea_model_B.jy = Aenea_model_B.i + Aenea_model_B.soglia_dist;
              Aenea_model_B.a[Aenea_model_B.jy] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist + 3] *
                Aenea_model_B.A[Aenea_model_B.i + 12];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.a_b = Aenea_model_B.a[Aenea_model_B.soglia_dist + 2];
          if (Aenea_model_B.a_b != 0.0) {
            Aenea_model_B.a[Aenea_model_B.soglia_dist + 2] = Aenea_model_B.a_b /
              Aenea_model_B.A[10];
            Aenea_model_B.i = 0;
            while (Aenea_model_B.i <= 1) {
              Aenea_model_B.jy = Aenea_model_B.i + Aenea_model_B.soglia_dist;
              Aenea_model_B.a[Aenea_model_B.jy] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist + 2] *
                Aenea_model_B.A[Aenea_model_B.i + 8];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.a_b = Aenea_model_B.a[Aenea_model_B.soglia_dist + 1];
          if (Aenea_model_B.a_b != 0.0) {
            Aenea_model_B.a[Aenea_model_B.soglia_dist + 1] = Aenea_model_B.a_b /
              Aenea_model_B.A[5];
            Aenea_model_B.a[Aenea_model_B.soglia_dist] -=
              Aenea_model_B.a[Aenea_model_B.soglia_dist + 1] * Aenea_model_B.A[4];
          }

          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.a[Aenea_model_B.soglia_dist] /= Aenea_model_B.A[0];
          }
        }

        Aenea_model_B.a_b = (Aenea_model_DW.x[1] - -100.0) *
          Aenea_model_B.Gain_hh + Aenea_model_DW.x[0];
        Aenea_model_B.Gain_hh = Aenea_model_B.dist - Aenea_model_B.Gain_hh;
        Aenea_model_B.Sum_h = Aenea_model_B.Sum_h * Aenea_model_B.SignPreSat +
          Aenea_model_DW.x[3];
        Aenea_model_B.SignPreSat = Aenea_model_B.Al_selector *
          Aenea_model_B.SignPreSat + -0.1;
        for (Aenea_model_B.Switch_oz = 0; Aenea_model_B.Switch_oz < 4;
             Aenea_model_B.Switch_oz++) {
          Aenea_model_B.x_new[Aenea_model_B.Switch_oz] =
            Aenea_model_DW.x[Aenea_model_B.Switch_oz] -
            (((Aenea_model_B.a[Aenea_model_B.Switch_oz + 4] *
               Aenea_model_B.Gain_hh + Aenea_model_B.a[Aenea_model_B.Switch_oz] *
               Aenea_model_B.a_b) + Aenea_model_B.a[Aenea_model_B.Switch_oz + 8]
              * Aenea_model_B.Sum_h) + Aenea_model_B.a[Aenea_model_B.Switch_oz +
             12] * Aenea_model_B.SignPreSat);
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
          Aenea_model_B.tolleranza_distWP_fut = 1;
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

      Aenea_model_B.no_solution = Aenea_model_B.tolleranza_distWP_fut;

      // End of MATLAB Function: '<S449>/MATLAB Function'

      // Product: '<S449>/Multiply' incorporates:
      //   Constant: '<S449>/x_g0'
      //   Gain: '<S449>/Gain'
      //   Sum: '<S449>/Sum1'

      Aenea_model_B.Multiply = -(Aenea_model_B.Long_Home - -100.0) *
        Aenea_model_B.Sum2_k2;

      // Constant: '<S449>/Constant1'
      Aenea_model_B.Constant1_h = 20.0;

      // Update for DiscreteIntegrator: '<S449>/Discrete-Time Integrator'
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

      // End of Update for DiscreteIntegrator: '<S449>/Discrete-Time Integrator' 
    }

    // End of Outputs for SubSystem: '<S438>/APPROACH'

    // Outputs for Enabled SubSystem: '<S438>/FLARE' incorporates:
    //   EnablePort: '<S453>/Enable'

    if (Aenea_model_B.trig_flare > 0.0) {
      // Constant: '<S453>/Constant1'
      Aenea_model_B.Constant1 = 18.0;

      // Sum: '<S453>/Sum2' incorporates:
      //   Gain: '<S453>/Gain'
      //   Math: '<S453>/Exp'
      //   Product: '<S453>/Multiply'
      //   Product: '<S453>/Multiply1'
      //   Sum: '<S453>/Sum'
      //   Sum: '<S453>/Sum1'
      //
      //  About '<S453>/Exp':
      //   Operator: exp

      Aenea_model_B.Sum2 = std::exp(-((Aenea_model_B.Long_Home -
        Aenea_model_B.x_f_out) * Aenea_model_B.k_x_out)) *
        (Aenea_model_B.h_f_out - Aenea_model_B.h_c_out) + Aenea_model_B.h_c_out;
    }

    // End of Outputs for SubSystem: '<S438>/FLARE'

    // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation5' 
    switch (static_cast<int32_T>(Aenea_model_B.maneuver_selector)) {
     case 1:
      // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation5' incorporates:
      //   Constant: '<S438>/Constant6'

      Aenea_model_B.velocita = 20.0;
      break;

     case 2:
      // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation5' 
      Aenea_model_B.velocita = Aenea_model_B.Constant1_h;
      break;

     default:
      // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation5' 
      Aenea_model_B.velocita = Aenea_model_B.Constant1;
      break;
    }

    // End of MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation5' 

    // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation4' 
    switch (static_cast<int32_T>(Aenea_model_B.maneuver_selector)) {
     case 1:
      // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Constant: '<S438>/Constant2'

      Aenea_model_B.QUOTA_e = 45.0;
      break;

     case 2:
      // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Abs: '<S438>/Abs3'

      Aenea_model_B.QUOTA_e = std::abs(Aenea_model_B.Multiply);
      break;

     default:
      // MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Abs: '<S438>/Abs4'

      Aenea_model_B.QUOTA_e = std::abs(Aenea_model_B.Sum2);
      break;
    }

    // End of MultiPortSwitch: '<S438>/Switch di selezione  Task - Waypoint navigation4' 

    // Update for Memory: '<S438>/Memory5'
    Aenea_model_DW.Memory5_PreviousInput = Aenea_model_B.x_f_out;

    // Update for Memory: '<S438>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput_f = Aenea_model_B.h_f_out;

    // Update for Memory: '<S438>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput_e = Aenea_model_B.no_solution;
  }

  // End of Outputs for SubSystem: '<S35>/Subsystem1'

  // S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
  //   Constant: '<Root>/SI UAV uint8'
  //   Constant: '<S19>/onboard_control_sensor_present uint32'

  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&Aenea_model_B.iflogic,
    &Aenea_model_B.DataTypeConversion3, &Aenea_model_ConstP.SIUAVuint8_Value,
    &Aenea_model_B.GC_info[0], &Aenea_model_B.Val_out_MAV[0],
    &Aenea_model_B.WP_info[0], &Aenea_model_B.WP_param[0],
    Aenea_model_ConstP.onboard_control_sensor_presentu, &Aenea_model_B.LVDE[0],
    &Aenea_model_ConstB.Gain1, &Aenea_model_ConstB.B_Remaining,
    &Aenea_model_ConstB.DataTypeConversion,
    &Aenea_model_B.DataTypeConversion1_f[0],
    &Aenea_model_B.DataTypeConversion_j[0], &Aenea_model_B.DataTypeConversion1[0],
    &Aenea_model_B.DataTypeConversion_g[0],
    &Aenea_model_B.DataTypeConversion1_j[0], &Aenea_model_B.DataTypeConversion2,
    &Aenea_model_B.AGAC[0], &Aenea_model_B.Heading_f,
    &Aenea_model_ConstB.Throttle, &Aenea_model_B.Heading[0],
    &Aenea_model_B.Memory_o, ((const real32_T*) &Aenea_model_R32GND),
    &Aenea_model_B.SFunction_o14, &Aenea_model_B.DataTypeConversion1_m,
    &Aenea_model_B.SFunction_o15, &Aenea_model_B.DataTypeConversion,
    &Aenea_model_ConstB.DataTypeConversion1,
    &Aenea_model_B.DataTypeConversion2_m, &Aenea_model_B.SFunction_o5[0],
    &Aenea_model_B.Gain, &Aenea_model_B.Gain_o, &Aenea_model_B.h_Home, ((const
    uint16_T*) &Aenea_model_U16GND), &Aenea_model_B.SFunction_o1_i,
    &Aenea_model_B.SFunction_o2_h[0], &Aenea_model_B.SFunction_o3,
    &Aenea_model_B.SFunction_o4);

  // S-Function (enable_sfun): '<S2>/S-Function Builder'
  enable_sfun_Outputs_wrapper(&Aenea_model_B.SFunction_o1_i,
    &Aenea_model_B.SFunctionBuilder);

  // Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
  //   EnablePort: '<S18>/Enable'

  if (Aenea_model_B.SFunctionBuilder > 0) {
    // S-Function (MavLink_Send_sfun): '<S18>/S-Function Builder'
    MavLink_Send_sfun_Outputs_wrapper(&Aenea_model_B.SFunction_o2_h[0],
      &Aenea_model_B.SFunction_o3);
  }

  // End of Outputs for SubSystem: '<S2>/Subsystem'

  // DataTypeConversion: '<S1>/Data Tversion' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  for (Aenea_model_B.i = 0; Aenea_model_B.i < 42; Aenea_model_B.i++) {
    Aenea_model_B.DataTypeConversion4[Aenea_model_B.i] =
      Aenea_model_DW.WP_dbP[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S1>/Data Tversion'

  // DataTypeConversion: '<S567>/Data Type Conversion1' incorporates:
  //   UnitDelay: '<S567>/Unit Delay'

  for (Aenea_model_B.i = 0; Aenea_model_B.i < 9; Aenea_model_B.i++) {
    Aenea_model_DW.UnitDelay_DSTATE[Aenea_model_B.i] =
      Aenea_model_B.ByteReversal[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S567>/Data Type Conversion1'

  // Outputs for Enabled SubSystem: '<S35>/Subsystem2' incorporates:
  //   EnablePort: '<S439>/Enable'

  if (Aenea_model_B.Wp_selector > 0.0) {
    // Gain: '<S540>/Gain'
    Aenea_model_B.Gain_hh = 57.295779513082323 * Aenea_model_B.Lat_K;

    // Gain: '<S541>/Gain'
    Aenea_model_B.Sum_h = 57.295779513082323 * Aenea_model_B.Long_K;

    // MATLAB Function: '<S439>/WAYPOINTS' incorporates:
    //   DataTypeConversion: '<S1>/Data Tversion'
    //   DataTypeConversion: '<S1>/Data Tversion1'
    //   DataTypeConversion: '<S1>/Data Tversion2'
    //   Memory: '<S439>/Memory4'

    Aenea_model_B.Switch_oz = 1;
    if (Aenea_model_DW.Memory4_PreviousInput == 6.0) {
      Aenea_model_B.Switch_oz = 0;
    }

    if (static_cast<uint8_T>(Aenea_model_B.GC_info[0]) == 3) {
      Aenea_model_DW.Memory4_PreviousInput = 1.0;
      Aenea_model_DW.lat1 = Aenea_model_B.Gain_hh;
      Aenea_model_DW.long1 = Aenea_model_B.Sum_h;
      for (Aenea_model_B.tolleranza_distWP_fut = 0;
           Aenea_model_B.tolleranza_distWP_fut < 6;
           Aenea_model_B.tolleranza_distWP_fut++) {
        if (Aenea_model_DW.WP_dbI[Aenea_model_B.tolleranza_distWP_fut + 24] == 1)
        {
          Aenea_model_DW.Memory4_PreviousInput = static_cast<real_T>
            (Aenea_model_B.tolleranza_distWP_fut) + 1.0;
        }
      }
    }

    Aenea_model_B.Wp_selector = Aenea_model_B.DataTypeConversion4
      [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 23];
    Aenea_model_B.Long_Home = Aenea_model_B.DataTypeConversion4
      [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 29];
    Aenea_model_B.QUOTA = Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
      (Aenea_model_DW.Memory4_PreviousInput) + 35];
    Aenea_model_B.a_b = std::sin((Aenea_model_B.Wp_selector -
      Aenea_model_B.Gain_hh) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Sum2_k2 = std::sin((Aenea_model_B.Long_Home -
      Aenea_model_B.Sum_h) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Al_selector = Aenea_model_B.Wp_selector * 3.1415926535897931 /
      180.0;
    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.Al_selector);
    Aenea_model_B.SignPreSat = std::cos(Aenea_model_B.Gain_hh *
      3.1415926535897931 / 180.0);
    Aenea_model_B.a_b = Aenea_model_B.SignPreSat * Aenea_model_B.Switch_j *
      (Aenea_model_B.Sum2_k2 * Aenea_model_B.Sum2_k2) + Aenea_model_B.a_b *
      Aenea_model_B.a_b;
    Aenea_model_B.Sum2_k2 = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::
      sqrt(1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    if (Aenea_model_DW.Memory4_PreviousInput > 1.0) {
      Aenea_model_B.a_tmp_tmp = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23];
      Aenea_model_B.Al_selector = Aenea_model_B.a_tmp_tmp * 3.1415926535897931 /
        180.0;
      Aenea_model_B.a_b = std::cos(Aenea_model_B.Al_selector);
      Aenea_model_B.dist = Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput - 1.0) + 29];
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.Long_Home - Aenea_model_B.dist)
        * 3.1415926535897931 / 180.0;
      Aenea_model_B.Al_selector = rt_atan2d_snf(std::sin
        (Aenea_model_B.psi_ref_tmp) * Aenea_model_B.Switch_j, std::sin
        (Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
         (Aenea_model_DW.Memory4_PreviousInput) + 23] * 3.1415926535897931 /
         180.0) * Aenea_model_B.a_b - std::sin(Aenea_model_B.Al_selector) *
        Aenea_model_B.Switch_j * std::cos(Aenea_model_B.psi_ref_tmp)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.a_tmp_tmp = std::sin((Aenea_model_B.Gain_hh -
        Aenea_model_B.a_tmp_tmp) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.dist = std::sin((Aenea_model_B.Sum_h - Aenea_model_B.dist) *
        3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.a_b = Aenea_model_B.a_b * Aenea_model_B.SignPreSat *
        (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_tmp_tmp *
        Aenea_model_B.a_tmp_tmp;
      Aenea_model_B.dist = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt
        (1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    } else {
      Aenea_model_B.a_b = (Aenea_model_B.Long_Home - Aenea_model_DW.long1) *
        3.1415926535897931 / 180.0;
      Aenea_model_B.psi_ref_tmp = Aenea_model_DW.lat1 * 3.1415926535897931 /
        180.0;
      Aenea_model_B.Al_selector = rt_atan2d_snf(std::sin(Aenea_model_B.a_b) *
        Aenea_model_B.Switch_j, std::sin(Aenea_model_B.Al_selector) * std::cos
        (Aenea_model_B.psi_ref_tmp) - std::cos(Aenea_model_B.a_b) * (std::sin
        (Aenea_model_B.psi_ref_tmp) * Aenea_model_B.Switch_j)) * 180.0 /
        3.1415926535897931;
      Aenea_model_B.dist = 0.0;
    }

    if (Aenea_model_B.Al_selector < 0.0) {
      Aenea_model_B.Al_selector = 360.0 - std::abs(Aenea_model_B.Al_selector);
    }

    if (Aenea_model_B.Switch_oz == 1) {
      Aenea_model_B.psi_ref_tmp = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput + 1.0) + 23];
      Aenea_model_B.a_tmp_tmp = std::sin((Aenea_model_B.psi_ref_tmp -
        Aenea_model_B.Wp_selector) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.b_a_tmp = (Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput + 1.0) + 29]
        - Aenea_model_B.Long_Home) * 3.1415926535897931 / 180.0;
      Aenea_model_B.dist_fut = std::sin(Aenea_model_B.b_a_tmp / 2.0);
      Aenea_model_B.psi_ref_tmp = Aenea_model_B.psi_ref_tmp * 3.1415926535897931
        / 180.0;
      Aenea_model_B.a_fut_tmp = std::cos(Aenea_model_B.psi_ref_tmp);
      Aenea_model_B.dist_fut = Aenea_model_B.Switch_j * Aenea_model_B.a_fut_tmp *
        (Aenea_model_B.dist_fut * Aenea_model_B.dist_fut) +
        Aenea_model_B.a_tmp_tmp * Aenea_model_B.a_tmp_tmp;
      Aenea_model_B.dist_fut = rt_atan2d_snf(std::sqrt(Aenea_model_B.dist_fut),
        std::sqrt(1.0 - Aenea_model_B.dist_fut)) * 2.0 * 6.378137E+6;
      Aenea_model_B.Switch_j = rt_atan2d_snf(std::sin(Aenea_model_B.b_a_tmp) *
        Aenea_model_B.a_fut_tmp, std::sin(Aenea_model_B.psi_ref_tmp) *
        Aenea_model_B.Switch_j - std::cos(Aenea_model_B.b_a_tmp) * (std::sin
        (Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
         (Aenea_model_DW.Memory4_PreviousInput) + 23] * 3.1415926535897931 /
         180.0) * Aenea_model_B.a_fut_tmp)) * 180.0 / 3.1415926535897931;
      if (Aenea_model_B.Switch_j < 0.0) {
        Aenea_model_B.Switch_j = 360.0 - std::abs(Aenea_model_B.Switch_j);
      }

      if (Aenea_model_DW.Memory4_PreviousInput > 1.0) {
        Aenea_model_B.Switch_j = std::abs(Aenea_model_B.Switch_j -
          Aenea_model_B.Al_selector);
      } else {
        Aenea_model_B.Switch_j = std::abs(Aenea_model_B.Switch_j - rt_atan2d_snf
          (std::sin((Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
                     (Aenea_model_DW.Memory4_PreviousInput) + 29] -
                     Aenea_model_DW.long1) * 3.1415926535897931 / 180.0) * std::
           cos(Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
               (Aenea_model_DW.Memory4_PreviousInput) + 23] * 3.1415926535897931
               / 180.0), std::sin(Aenea_model_B.DataTypeConversion4
          [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 23] *
          3.1415926535897931 / 180.0) * std::cos(Aenea_model_DW.lat1 *
          3.1415926535897931 / 180.0) - std::cos
           (Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
            (Aenea_model_DW.Memory4_PreviousInput) + 23] * 3.1415926535897931 /
            180.0) * std::sin(Aenea_model_DW.lat1 * 3.1415926535897931 / 180.0) *
           std::cos((Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
                     (Aenea_model_DW.Memory4_PreviousInput) + 29] -
                     Aenea_model_DW.long1) * 3.1415926535897931 / 180.0)) *
          180.0 / 3.1415926535897931);
      }
    } else {
      Aenea_model_B.dist_fut = 0.0;
      Aenea_model_B.Switch_j = 0.0;
    }

    if (Aenea_model_DW.Memory4_PreviousInput < 2.0) {
      Aenea_model_B.SignPreSat = 0.0;
    } else if (Aenea_model_DW.Memory4_PreviousInput == 2.0) {
      Aenea_model_B.a_b = Aenea_model_B.DataTypeConversion4[24] *
        3.1415926535897931 / 180.0;
      Aenea_model_B.b_a_tmp = std::cos(Aenea_model_B.a_b);
      Aenea_model_B.Gain_hh = (Aenea_model_B.DataTypeConversion4[30] -
        Aenea_model_DW.long1) * 3.1415926535897931 / 180.0;
      Aenea_model_B.SignPreSat = std::abs(Aenea_model_B.Al_selector -
        rt_atan2d_snf(std::sin(Aenea_model_B.Gain_hh) * Aenea_model_B.b_a_tmp,
                      std::cos(Aenea_model_DW.lat1 * 3.1415926535897931 / 180.0)
                      * std::sin(Aenea_model_B.a_b) - std::sin
                      (Aenea_model_DW.lat1 * 3.1415926535897931 / 180.0) *
                      Aenea_model_B.b_a_tmp * std::cos(Aenea_model_B.Gain_hh)) *
        180.0 / 3.1415926535897931);
    } else {
      Aenea_model_B.SignPreSat = std::cos(Aenea_model_B.DataTypeConversion4[
        static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23] *
        3.1415926535897931 / 180.0);
      Aenea_model_B.Sum_h = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 2.0) + 23] *
        3.1415926535897931 / 180.0;
      Aenea_model_B.Gain_hh = (Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 29]
        - Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput - 2.0) + 29]) * 3.1415926535897931
        / 180.0;
      Aenea_model_B.SignPreSat = rt_atan2d_snf(std::sin(Aenea_model_B.Gain_hh) *
        Aenea_model_B.SignPreSat, std::cos(Aenea_model_B.Sum_h) * std::sin
        (Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
         (Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23] * 3.1415926535897931
         / 180.0) - std::sin(Aenea_model_B.Sum_h) * Aenea_model_B.SignPreSat *
        std::cos(Aenea_model_B.Gain_hh)) * 180.0 / 3.1415926535897931;
      if (Aenea_model_B.SignPreSat < 0.0) {
        Aenea_model_B.SignPreSat = 360.0 - std::abs(Aenea_model_B.SignPreSat);
      }

      Aenea_model_B.SignPreSat = std::abs(Aenea_model_B.Al_selector -
        Aenea_model_B.SignPreSat);
    }

    if (Aenea_model_B.Switch_j <= 10.0) {
      Aenea_model_B.Switch_j = 40.0;
      Aenea_model_B.tolleranza_distWP_fut = 10;
    } else if ((Aenea_model_B.Switch_j > 10.0) && (Aenea_model_B.Switch_j <=
                50.0)) {
      Aenea_model_B.Switch_j = 60.0;
      Aenea_model_B.tolleranza_distWP_fut = 15;
    } else if ((Aenea_model_B.Switch_j > 50.0) && (Aenea_model_B.Switch_j <=
                90.0)) {
      Aenea_model_B.Switch_j = 80.0;
      Aenea_model_B.tolleranza_distWP_fut = 20;
    } else if ((Aenea_model_B.Switch_j > 90.0) && (Aenea_model_B.Switch_j <=
                120.0)) {
      Aenea_model_B.Switch_j = 120.0;
      Aenea_model_B.tolleranza_distWP_fut = 25;
    } else {
      Aenea_model_B.Switch_j = 150.0;
      Aenea_model_B.tolleranza_distWP_fut = 30;
    }

    if (Aenea_model_B.SignPreSat <= 10.0) {
      Aenea_model_B.soglia_dist = 50;
    } else if ((Aenea_model_B.SignPreSat > 10.0) && (Aenea_model_B.SignPreSat <=
                50.0)) {
      Aenea_model_B.soglia_dist = 200;
    } else if ((Aenea_model_B.SignPreSat > 50.0) && (Aenea_model_B.SignPreSat <=
                90.0)) {
      Aenea_model_B.soglia_dist = 300;
    } else if ((Aenea_model_B.SignPreSat > 90.0) && (Aenea_model_B.SignPreSat <=
                120.0)) {
      Aenea_model_B.soglia_dist = 350;
    } else {
      Aenea_model_B.soglia_dist = 400;
    }

    if (Aenea_model_B.Switch_oz == 1) {
      Aenea_model_B.VELOCITA = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 11];
      if (Aenea_model_B.VELOCITA < 15.0) {
        Aenea_model_B.VELOCITA = 25.0;
      }

      if (!(Aenea_model_B.VELOCITA <= 20.0)) {
        if (Aenea_model_B.VELOCITA <= 25.0) {
          Aenea_model_B.Switch_j *= 1.2;
        } else if (Aenea_model_B.VELOCITA <= 30.0) {
          Aenea_model_B.Switch_j *= 1.3;
        } else {
          Aenea_model_B.Switch_j *= 1.4;
        }
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_B.Sum2_k2 > Aenea_model_B.Switch_j))) &&
          ((!(Aenea_model_B.dist > Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_B.Sum2_k2 > Aenea_model_B.Switch_j))) &&
          (Aenea_model_B.Sum2_k2 < Aenea_model_B.Switch_j)) {
        if (Aenea_model_B.dist_fut > Aenea_model_B.tolleranza_distWP_fut) {
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
      Aenea_model_B.VELOCITA = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 11];
      if (Aenea_model_B.VELOCITA < 15.0) {
        Aenea_model_B.VELOCITA = 25.0;
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_DW.flag_f == 0.0))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.soglia_dist)) || (!(Aenea_model_B.Sum2_k2 > 40.0)) ||
           (!(Aenea_model_DW.flag_f == 0.0)))) {
        Aenea_model_B.VELOCITA = 22.0;
        Aenea_model_B.QUOTA = Aenea_model_B.h_K + 0.4;
        Aenea_model_DW.flag_f = 1.0;
      }
    }

    if ((Aenea_model_B.Wp_selector == 0.0) && (Aenea_model_B.Long_Home == 0.0) &&
        (Aenea_model_B.QUOTA == 0.0)) {
      Aenea_model_B.QUOTA = Aenea_model_B.h_K + 0.3;
      Aenea_model_B.VELOCITA = 22.0;
    }

    // Saturate: '<S439>/saturatore V' incorporates:
    //   MATLAB Function: '<S439>/WAYPOINTS'

    if (Aenea_model_B.VELOCITA > 40.0) {
      // Saturate: '<S439>/saturatore V'
      Aenea_model_B.VELOCITA = 40.0;
    } else {
      if (Aenea_model_B.VELOCITA < 15.0) {
        // Saturate: '<S439>/saturatore V'
        Aenea_model_B.VELOCITA = 15.0;
      }
    }

    // End of Saturate: '<S439>/saturatore V'
  }

  // End of Outputs for SubSystem: '<S35>/Subsystem2'

  // Outputs for Enabled SubSystem: '<S35>/Subsystem' incorporates:
  //   EnablePort: '<S437>/Enable'

  if (Aenea_model_B.Vec_selector > 0.0) {
    // MATLAB Function: '<S437>/VETTORIALE' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'
    //   Memory: '<S437>/Memory1'
    //   Memory: '<S437>/Memory2'
    //   Memory: '<S437>/Memory3'
    //   Memory: '<S437>/Memory6'

    if ((Aenea_model_DW.Memory2_PreviousInput_d[1] !=
         Aenea_model_DW.Memory6_PreviousInput) || (Aenea_model_B.modo !=
         Aenea_model_DW.Memory3_PreviousInput) ||
        (Aenea_model_DW.Memory2_PreviousInput_d[3] !=
         Aenea_model_DW.Memory2_PreviousInput_d2)) {
      Aenea_model_DW.V_ref = Aenea_model_B.num_254;
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

    // Update for Memory: '<S437>/Memory1' incorporates:
    //   MATLAB Function: '<S437>/VETTORIALE'

    Aenea_model_DW.Memory1_PreviousInput_k =
      Aenea_model_DW.Memory2_PreviousInput_d[4];

    // Update for Memory: '<S437>/Memory2' incorporates:
    //   MATLAB Function: '<S437>/VETTORIALE'

    Aenea_model_DW.Memory2_PreviousInput_d2 =
      Aenea_model_DW.Memory2_PreviousInput_d[3];

    // Update for Memory: '<S437>/Memory3' incorporates:
    //   MATLAB Function: '<S437>/VETTORIALE'

    Aenea_model_DW.Memory3_PreviousInput = Aenea_model_B.modo;

    // Update for Memory: '<S437>/Memory6' incorporates:
    //   MATLAB Function: '<S437>/VETTORIALE'

    Aenea_model_DW.Memory6_PreviousInput =
      Aenea_model_DW.Memory2_PreviousInput_d[1];
  }

  // End of Outputs for SubSystem: '<S35>/Subsystem'

  // Outputs for Enabled SubSystem: '<S35>/Subsystem3' incorporates:
  //   EnablePort: '<S440>/Enable'

  if (Aenea_model_B.Go_home_selector > 0.0) {
    // Gain: '<S545>/Gain'
    Aenea_model_B.Vec_selector = 57.295779513082323 * Aenea_model_B.Lat_K;

    // MATLAB Function: '<S440>/GO_HOME' incorporates:
    //   Constant: '<S35>/Constant'
    //   Constant: '<S35>/Constant1'
    //   Gain: '<S546>/Gain'

    Aenea_model_B.a_b = std::sin((0.0 - Aenea_model_B.Vec_selector) *
      3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Sum2_k2 = std::sin((0.0 - 57.295779513082323 *
      Aenea_model_B.Long_K) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.a_b = std::cos(Aenea_model_B.Vec_selector * 3.1415926535897931
      / 180.0) * (Aenea_model_B.Sum2_k2 * Aenea_model_B.Sum2_k2) +
      Aenea_model_B.a_b * Aenea_model_B.a_b;
    Aenea_model_B.h_goHome = 70.0;
    Aenea_model_B.V_goHome = 20.0;
    if ((rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt(1.0 -
           Aenea_model_B.a_b)) * 2.0 * 6.378137E+6 < 30.0) &&
        (Aenea_model_DW.flag == 0.0)) {
      Aenea_model_DW.flag = 1.0;
      Aenea_model_B.h_goHome = 70.4;
    }

    // End of MATLAB Function: '<S440>/GO_HOME'
  }

  // End of Outputs for SubSystem: '<S35>/Subsystem3'

  // MultiPortSwitch: '<S35>/Switch di selezione  Task - Waypoint navigation1'
  switch (static_cast<int32_T>(Aenea_model_B.modo)) {
   case 1:
    Aenea_model_B.Sum2_k2 = Aenea_model_B.VELOCITA;
    break;

   case 2:
    Aenea_model_B.Sum2_k2 = Aenea_model_B.V_vett;
    break;

   case 3:
    Aenea_model_B.Sum2_k2 = Aenea_model_B.Tas_ref;
    break;

   case 4:
    Aenea_model_B.Sum2_k2 = Aenea_model_B.velocita;
    break;

   default:
    Aenea_model_B.Sum2_k2 = Aenea_model_B.V_goHome;
    break;
  }

  // End of MultiPortSwitch: '<S35>/Switch di selezione  Task - Waypoint navigation1' 

  // Sum: '<S38>/Sum3'
  Aenea_model_B.Sum2_k2 -= Aenea_model_B.num_254;

  // Sum: '<S290>/Sum' incorporates:
  //   DiscreteIntegrator: '<S281>/Integrator'
  //   Product: '<S286>/PProd Out'

  Aenea_model_B.Al_selector = Aenea_model_B.Sum2_k2 * 0.033649999648332596 +
    Aenea_model_DW.Integrator_DSTATE_lq;

  // Saturate: '<S288>/Saturation'
  if (Aenea_model_B.Al_selector > 1.0) {
    Aenea_model_B.num_254 = 1.0;
  } else if (Aenea_model_B.Al_selector < 0.0) {
    Aenea_model_B.num_254 = 0.0;
  } else {
    Aenea_model_B.num_254 = Aenea_model_B.Al_selector;
  }

  // End of Saturate: '<S288>/Saturation'

  // MATLAB Function: '<S246>/Smooth Bypass' incorporates:
  //   SignalConversion generated from: '<S246>/Vector Concatenate'

  if (Aenea_model_B.switch_manetta == 0.0) {
    Aenea_model_B.Long_Home = Aenea_model_B.num_254;
    Aenea_model_DW.Delay_DSTATE = Aenea_model_B.Sum_fj;
  } else {
    if (Aenea_model_B.switch_manetta != Aenea_model_B.switch_manetta) {
      Aenea_model_DW.Delay_DSTATE = Aenea_model_B.Sum_fj;
    }

    Aenea_model_B.Sum_fj -= Aenea_model_DW.Delay_DSTATE;
    if (Aenea_model_B.Sum_fj < 1.3) {
      if (Aenea_model_B.Sum_fj < 0.2) {
        Aenea_model_B.Long_Home = Aenea_model_B.Sum5;
      } else {
        Aenea_model_B.Long_Home = (Aenea_model_B.Sum_fj - 0.2) / 1.1 *
          (Aenea_model_B.num_254 - Aenea_model_B.Sum5) + Aenea_model_B.Sum5;
      }
    } else {
      Aenea_model_B.Long_Home = Aenea_model_B.num_254;
    }
  }

  // End of MATLAB Function: '<S246>/Smooth Bypass'

  // MultiPortSwitch: '<S246>/Switch Bumpless 1'
  if (static_cast<int32_T>(Aenea_model_B.switch_manetta) == 0) {
    Aenea_model_B.Long_Home = Aenea_model_B.Sum5;
  }

  // End of MultiPortSwitch: '<S246>/Switch Bumpless 1'

  // MultiPortSwitch: '<S35>/Switch di selezione  Task - Waypoint navigation2'
  switch (static_cast<int32_T>(Aenea_model_B.modo)) {
   case 1:
    Aenea_model_B.Sum_fj = Aenea_model_B.QUOTA;
    break;

   case 2:
    Aenea_model_B.Sum_fj = Aenea_model_B.h_vett;
    break;

   case 3:
    Aenea_model_B.Sum_fj = Aenea_model_B.h_ref;
    break;

   case 4:
    Aenea_model_B.Sum_fj = Aenea_model_B.QUOTA_e;
    break;

   default:
    Aenea_model_B.Sum_fj = Aenea_model_B.h_goHome;
    break;
  }

  // End of MultiPortSwitch: '<S35>/Switch di selezione  Task - Waypoint navigation2' 

  // HitCross: '<S247>/Hit  Crossing'
  Aenea_model_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &Aenea_model_PrevZCX.HitCrossing_Input_ZCE,
    (Aenea_model_B.Sum_fj - 0.3));
  if (Aenea_model_DW.HitCrossing_MODE == 0) {
    if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
      // HitCross: '<S247>/Hit  Crossing'
      Aenea_model_B.HitCrossing = !Aenea_model_B.HitCrossing;
      Aenea_model_DW.HitCrossing_MODE = 1;
    } else {
      if (Aenea_model_B.HitCrossing) {
        // HitCross: '<S247>/Hit  Crossing'
        Aenea_model_B.HitCrossing = ((!(Aenea_model_B.Sum_fj != 0.3)) &&
          Aenea_model_B.HitCrossing);
      }
    }
  } else {
    // HitCross: '<S247>/Hit  Crossing'
    Aenea_model_B.HitCrossing = ((!(Aenea_model_B.Sum_fj != 0.3)) &&
      Aenea_model_B.HitCrossing);
    Aenea_model_DW.HitCrossing_MODE = 0;
  }

  // End of HitCross: '<S247>/Hit  Crossing'

  // Outputs for Triggered SubSystem: '<S247>/Enabled Subsystem' incorporates:
  //   TriggerPort: '<S299>/Trigger'

  if (Aenea_model_B.HitCrossing &&
      (Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE != 1)) {
    // SignalConversion generated from: '<S299>/Out1' incorporates:
    //   Constant: '<S299>/Constant'

    Aenea_model_B.OutportBufferForOut1 = 0.0;
  }

  Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE = Aenea_model_B.HitCrossing;

  // End of Outputs for SubSystem: '<S247>/Enabled Subsystem'

  // MultiPortSwitch: '<S32>/Switch di selezione riferimeti  per i loop interni 1' 
  if (static_cast<int32_T>(Aenea_model_B.Switch) == 0) {
    // MultiPortSwitch: '<S247>/throttle - landing' incorporates:
    //   MATLAB Function: '<S34>/MATLAB Function'

    if (Aenea_model_B.caso != 0) {
      // Switch: '<S247>/Switch' incorporates:
      //   Constant: '<S247>/Constant3'

      if (!(Aenea_model_B.OutportBufferForOut1 > 0.0)) {
        Aenea_model_B.Long_Home = 0.0;
      }

      // End of Switch: '<S247>/Switch'
    }

    // End of MultiPortSwitch: '<S247>/throttle - landing'
  } else {
    Aenea_model_B.Long_Home = Aenea_model_B.throttle_safe;
  }

  // End of MultiPortSwitch: '<S32>/Switch di selezione riferimeti  per i loop interni 1' 

  // DiscreteIntegrator: '<S303>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S303>/Constant8'
  //   Sum: '<S303>/Sum'

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

  // MultiPortSwitch: '<S303>/Multiport Switch1' incorporates:
  //   MATLAB Function: '<S34>/MATLAB Function'

  if (Aenea_model_B.Switch_h != 0) {
    // MultiPortSwitch: '<S303>/Switch Bumpless 1' incorporates:
    //   Constant: '<S303>/Constant4'
    //   DiscreteIntegrator: '<S303>/Discrete-Time Integrator'

    switch (static_cast<int32_T>(Aenea_model_B.Fase_ATO)) {
     case 0:
      Aenea_model_B.Long_Home = 0.0;
      break;

     case 1:
      Aenea_model_B.Long_Home = Aenea_model_B.manetta_ref;
      break;

     case 2:
      Aenea_model_B.Long_Home = Aenea_model_DW.DiscreteTimeIntegrator_DSTATE;
      break;

     case 3:
      break;
    }

    // End of MultiPortSwitch: '<S303>/Switch Bumpless 1'
  }

  // End of MultiPortSwitch: '<S303>/Multiport Switch1'

  // Sum: '<S293>/SumI1' incorporates:
  //   Product: '<S278>/IProd Out'
  //   Sum: '<S292>/SumI3'

  Aenea_model_B.Long_Home = Aenea_model_B.Sum2_k2 * 0.00800000037997961 +
    (Aenea_model_B.Long_Home - Aenea_model_B.num_254);

  // DeadZone: '<S274>/DeadZone'
  if (Aenea_model_B.Al_selector > 1.0) {
    Aenea_model_B.Sum2_k2 = Aenea_model_B.Al_selector - 1.0;
  } else if (Aenea_model_B.Al_selector >= 0.0) {
    Aenea_model_B.Sum2_k2 = 0.0;
  } else {
    Aenea_model_B.Sum2_k2 = Aenea_model_B.Al_selector;
  }

  // End of DeadZone: '<S274>/DeadZone'

  // Signum: '<S272>/SignPreSat'
  if (Aenea_model_B.Sum2_k2 < 0.0) {
    // DataTypeConversion: '<S272>/DataTypeConv1'
    Aenea_model_B.a_b = -1.0;
  } else if (Aenea_model_B.Sum2_k2 > 0.0) {
    // DataTypeConversion: '<S272>/DataTypeConv1'
    Aenea_model_B.a_b = 1.0;
  } else if (Aenea_model_B.Sum2_k2 == 0.0) {
    // DataTypeConversion: '<S272>/DataTypeConv1'
    Aenea_model_B.a_b = 0.0;
  } else {
    // DataTypeConversion: '<S272>/DataTypeConv1'
    Aenea_model_B.a_b = (rtNaN);
  }

  // End of Signum: '<S272>/SignPreSat'

  // DataTypeConversion: '<S272>/DataTypeConv1'
  if (rtIsNaN(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 256.0);
  }

  // Signum: '<S272>/SignPreIntegrator'
  if (Aenea_model_B.Long_Home < 0.0) {
    // DataTypeConversion: '<S272>/DataTypeConv2'
    Aenea_model_B.Switch_j = -1.0;
  } else if (Aenea_model_B.Long_Home > 0.0) {
    // DataTypeConversion: '<S272>/DataTypeConv2'
    Aenea_model_B.Switch_j = 1.0;
  } else if (Aenea_model_B.Long_Home == 0.0) {
    // DataTypeConversion: '<S272>/DataTypeConv2'
    Aenea_model_B.Switch_j = 0.0;
  } else {
    // DataTypeConversion: '<S272>/DataTypeConv2'
    Aenea_model_B.Switch_j = (rtNaN);
  }

  // End of Signum: '<S272>/SignPreIntegrator'

  // DataTypeConversion: '<S272>/DataTypeConv2'
  if (rtIsNaN(Aenea_model_B.Switch_j)) {
    Aenea_model_B.Switch_j = 0.0;
  } else {
    Aenea_model_B.Switch_j = std::fmod(Aenea_model_B.Switch_j, 256.0);
  }

  // Logic: '<S272>/AND3' incorporates:
  //   DataTypeConversion: '<S272>/DataTypeConv1'
  //   DataTypeConversion: '<S272>/DataTypeConv2'
  //   Gain: '<S272>/ZeroGain'
  //   RelationalOperator: '<S272>/Equal1'
  //   RelationalOperator: '<S272>/NotEqual'

  Ap_sel = ((0.0 * Aenea_model_B.Al_selector != Aenea_model_B.Sum2_k2) &&
            ((Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int8_T>
    (-static_cast<int8_T>(static_cast<uint8_T>(-Aenea_model_B.a_b)))) :
              static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>
    (Aenea_model_B.a_b)))) == (Aenea_model_B.Switch_j < 0.0 ?
              static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(
    static_cast<uint8_T>(-Aenea_model_B.Switch_j)))) : static_cast<int32_T>(
    static_cast<int8_T>(static_cast<uint8_T>(Aenea_model_B.Switch_j))))));

  // Abs: '<S36>/Abs' incorporates:
  //   Sum: '<S36>/Sum1'

  Aenea_model_B.num_254 = std::abs(Aenea_model_B.Sum_fj - Aenea_model_B.h_K);

  // Chart: '<S36>/SELEZIONE MODALITA'  HOLD//SELECT'
  if (Aenea_model_DW.is_active_c23_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c23_Aenea_model = 1U;
    Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Select;
  } else if (Aenea_model_DW.is_c23_Aenea_model == 1) {
    if (Aenea_model_B.num_254 > 10.0) {
      Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Select;
    }
  } else {
    // case IN_Select:
    if (Aenea_model_B.num_254 < 10.0) {
      Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Hold;
    }
  }

  // End of Chart: '<S36>/SELEZIONE MODALITA'  HOLD//SELECT'

  // Abs: '<S414>/Abs1'
  Aenea_model_B.Sum2_k2 = std::abs(Aenea_model_B.Sum3_h);

  // Outputs for Resettable SubSystem: '<S406>/Resettable Subsystem'
  Aenea_model_ResettableSubsystem(Aenea_model_B.SFunction_o4_a[1],
    &Aenea_model_B.Sum2_k2, &Aenea_model_DW.ResettableSubsystem,
    &Aenea_model_PrevZCX.ResettableSubsystem);

  // End of Outputs for SubSystem: '<S406>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S406>/Enabled Subsystem'
  Aenea_model_EnabledSubsystem(Aenea_model_B.SFunction_o4_a[1],
    Aenea_model_B.Sum2_k2, &Aenea_model_B.num_254);

  // End of Outputs for SubSystem: '<S406>/Enabled Subsystem'

  // MATLAB Function: '<S408>/MATLAB Function1'
  Aenea_model_DW.Tf_not_empty = ((!Aenea_model_DW.Tf_not_empty) ||
    (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) ||
    (Aenea_model_DW.Memory2_PreviousInput_d[1] == 0) ||
    Aenea_model_DW.Tf_not_empty);

  // MATLAB Function: '<S565>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S565>/Data Type Conversion2'
  //   DataTypeConversion: '<S569>/Data Type Conversion1'

  if (Aenea_model_B.SFunction_o14 == 1) {
    // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
    Aenea_model_DW.P_ref = Aenea_model_B.SFunctionBuilder_o2;

    // End of Outputs for SubSystem: '<S565>/Execution_loop'
  }

  if (Aenea_model_B.SFunction_o16 == 1) {
    Aenea_model_DW.P_ref = Aenea_model_B.SFunction_o17;
    Aenea_model_DW.rl_up = 20.0;
    Aenea_model_DW.rl_dw = -20.0;
  }

  // Sum: '<S568>/Difference Inputs1' incorporates:
  //   MATLAB Function: '<S565>/MATLAB Function'
  //   UnitDelay: '<S568>/Delay Input2'
  //
  //  Block description for '<S568>/Difference Inputs1':
  //
  //   Add in CPU
  //
  //  Block description for '<S568>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_B.num_254 = Aenea_model_DW.P_ref -
    Aenea_model_DW.DelayInput2_DSTATE;

  // Product: '<S568>/delta rise limit' incorporates:
  //   MATLAB Function: '<S565>/MATLAB Function'
  //   SampleTimeMath: '<S568>/sample time'
  //
  //  About '<S568>/sample time':
  //   y = K where K = ( w * Ts )

  Aenea_model_B.Sum2_k2 = Aenea_model_DW.rl_up * 0.02;

  // Switch: '<S572>/Switch2' incorporates:
  //   RelationalOperator: '<S572>/LowerRelop1'

  if (!(Aenea_model_B.num_254 > Aenea_model_B.Sum2_k2)) {
    // Product: '<S568>/delta fall limit' incorporates:
    //   MATLAB Function: '<S565>/MATLAB Function'
    //   SampleTimeMath: '<S568>/sample time'
    //
    //  About '<S568>/sample time':
    //   y = K where K = ( w * Ts )

    Aenea_model_B.Sum2_k2 = Aenea_model_DW.rl_dw * 0.02;

    // Switch: '<S572>/Switch' incorporates:
    //   RelationalOperator: '<S572>/UpperRelop'

    if (!(Aenea_model_B.num_254 < Aenea_model_B.Sum2_k2)) {
      Aenea_model_B.Sum2_k2 = Aenea_model_B.num_254;
    }

    // End of Switch: '<S572>/Switch'
  }

  // End of Switch: '<S572>/Switch2'

  // Sum: '<S568>/Difference Inputs2' incorporates:
  //   UnitDelay: '<S568>/Delay Input2'
  //
  //  Block description for '<S568>/Difference Inputs2':
  //
  //   Add in CPU
  //
  //  Block description for '<S568>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_DW.DelayInput2_DSTATE += Aenea_model_B.Sum2_k2;

  // Sum: '<S555>/Sum1' incorporates:
  //   Constant: '<S4>/tas'
  //   MATLAB Function: '<S555>/MATLAB Function'
  //   Product: '<S555>/Product4'
  //   Sum: '<S555>/Sum'
  //   UnitDelay: '<S555>/Unit Delay'

  Aenea_model_DW.UnitDelay_DSTATE_c = (Aenea_model_DW.UnitDelay_DSTATE_c + 1.0) *
    0.23456790123456794 + 1.0;
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    // Switch: '<S23>/Switch1' incorporates:
    //   Constant: '<S23>/Constant4'
    //   Constant: '<S23>/Constant5'
    //   Memory: '<S23>/Memory2'
    //   Sum: '<S23>/Add2'

    if (Aenea_model_DW.Memory2_PreviousInput + 1.0 > 9.0) {
      Aenea_model_B.Switch1_g = 0.0;
    } else {
      Aenea_model_B.Switch1_g = Aenea_model_DW.Memory2_PreviousInput + 1.0;
    }

    // End of Switch: '<S23>/Switch1'
  }

  // Update for Memory: '<S1>/Memory4'
  std::memcpy(&Aenea_model_DW.Memory4_PreviousInput_j[0], &Aenea_model_B.buffer
              [0], 300U * sizeof(uint8_T));

  // Update for Memory: '<S1>/Memory5'
  std::memcpy(&Aenea_model_DW.Memory5_PreviousInput_b[0],
              &Aenea_model_B.mess_out[0], 100U * sizeof(uint8_T));

  // Update for Memory: '<S1>/Memory'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 8; Aenea_model_B.i++) {
    Aenea_model_DW.Memory_PreviousInput_i[Aenea_model_B.i] =
      Aenea_model_B.SFunction_o11[Aenea_model_B.i];
  }

  // End of Update for Memory: '<S1>/Memory'

  // Update for RateTransition: '<S23>/Rate Transition'
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    Aenea_model_DW.RateTransition_Buffer0 = Aenea_model_B.Switch1_g;
  }

  // End of Update for RateTransition: '<S23>/Rate Transition'

  // Update for Memory: '<S23>/Memory' incorporates:
  //   Constant: '<S23>/Constant1'
  //   Sum: '<S23>/Add'

  Aenea_model_DW.Memory_PreviousInput += 0.02;

  // Update for UnitDelay: '<S565>/Unit Delay1' incorporates:
  //   UnitDelay: '<S568>/Delay Input2'
  //
  //  Block description for '<S568>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_DW.UnitDelay1_DSTATE = Aenea_model_DW.DelayInput2_DSTATE;

  // Update for Memory: '<S559>/Memory' incorporates:
  //   Constant: '<S566>/Constant4'
  //   Constant: '<S566>/Constant5'
  //   DataTypeConversion: '<S569>/Data Type Conversion2'

  Aenea_model_DW.Memory_PreviousInput_e[0] = 1.0;
  Aenea_model_DW.Memory_PreviousInput_e[1] = 1.0;

  // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_e[2] = Aenea_model_B.SFunctionBuilder_o3;

  // End of Outputs for SubSystem: '<S565>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_e[3] = 0.0;
  Aenea_model_DW.Memory_PreviousInput_e[4] = 0.0;
  Aenea_model_DW.Memory_PreviousInput_e[5] =
    Aenea_model_B.DataTypeConversion1_c[6];
  Aenea_model_DW.Memory_PreviousInput_e[6] =
    Aenea_model_B.DataTypeConversion1_c[7];
  Aenea_model_DW.Memory_PreviousInput_e[7] =
    Aenea_model_B.DataTypeConversion1_c[8];

  // Update for Memory: '<S558>/Memory' incorporates:
  //   Constant: '<S566>/Constant4'
  //   Constant: '<S566>/Constant5'
  //   DataTypeConversion: '<S569>/Data Type Conversion2'

  Aenea_model_DW.Memory_PreviousInput_o[0] = 1.0;
  Aenea_model_DW.Memory_PreviousInput_o[1] = 1.0;

  // Outputs for Atomic SubSystem: '<S565>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_o[2] = Aenea_model_B.SFunctionBuilder_o3;

  // End of Outputs for SubSystem: '<S565>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_o[3] = 0.0;
  Aenea_model_DW.Memory_PreviousInput_o[4] = 0.0;
  Aenea_model_DW.Memory_PreviousInput_o[5] =
    Aenea_model_B.DataTypeConversion1_c[6];
  Aenea_model_DW.Memory_PreviousInput_o[6] =
    Aenea_model_B.DataTypeConversion1_c[7];
  Aenea_model_DW.Memory_PreviousInput_o[7] =
    Aenea_model_B.DataTypeConversion1_c[8];
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // Update for Memory: '<S559>/Memory'
    Aenea_model_B.Sum5 = Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i];
    Aenea_model_DW.Memory_PreviousInput_e[Aenea_model_B.i + 8] =
      Aenea_model_B.Sum5;

    // Update for Memory: '<S558>/Memory'
    Aenea_model_DW.Memory_PreviousInput_o[Aenea_model_B.i + 8] =
      Aenea_model_B.Sum5;
  }

  // Update for DiscreteIntegrator: '<S338>/Integrator' incorporates:
  //   Product: '<S335>/IProd Out'
  //   Sum: '<S331>/SumI2'
  //   Sum: '<S331>/SumI4'
  //   Sum: '<S349>/SumI3'
  //   Sum: '<S350>/SumI1'

  Aenea_model_DW.Integrator_DSTATE += ((Aenea_model_B.Gain1_m *
    -0.64064997434616089 + (Aenea_model_B.SwitchBumpless2 -
    Aenea_model_B.Gain1_k)) + (Aenea_model_B.Gain1_k - Aenea_model_B.Gain_h)) *
    0.02;

  // Update for DiscreteIntegrator: '<S388>/Integrator' incorporates:
  //   Constant: '<S301>/Constant3'
  //   Gain: '<S381>/Kb'
  //   Product: '<S385>/IProd Out'
  //   Sum: '<S301>/Sum'
  //   Sum: '<S381>/SumI2'
  //   Sum: '<S381>/SumI4'
  //   Sum: '<S399>/SumI3'
  //   Sum: '<S400>/SumI1'

  Aenea_model_DW.Integrator_DSTATE_l += ((Aenea_model_B.Saturation_a -
    Aenea_model_B.Ato_selector) * 0.5 + (Aenea_model_B.Gain1 * 0.25 +
    (Aenea_model_B.Alettoni - Aenea_model_B.Saturation_a))) * 0.02;
  if (Aenea_model_B.Fase_ATO - 2.0 > 0.0) {
    Aenea_model_DW.Integrator_PrevResetState = 1;
  } else if (Aenea_model_B.Fase_ATO - 2.0 < 0.0) {
    Aenea_model_DW.Integrator_PrevResetState = -1;
  } else if (Aenea_model_B.Fase_ATO - 2.0 == 0.0) {
    Aenea_model_DW.Integrator_PrevResetState = 0;
  } else {
    Aenea_model_DW.Integrator_PrevResetState = 2;
  }

  // End of Update for DiscreteIntegrator: '<S388>/Integrator'

  // Update for DiscreteTransferFcn: '<S302>/Discrete Washout Filter'
  Aenea_model_DW.DiscreteWashoutFilter_states = Aenea_model_B.aterra_tmp_tmp;

  // Update for Memory: '<S2>/Memory'
  Aenea_model_DW.Memory_PreviousInput_e4 = Aenea_model_B.SFunction_o4;

  // Switch: '<S272>/Switch' incorporates:
  //   Constant: '<S272>/Constant1'

  if (Ap_sel) {
    Aenea_model_B.Long_Home = 0.0;
  }

  // End of Switch: '<S272>/Switch'

  // Update for DiscreteIntegrator: '<S281>/Integrator'
  Aenea_model_DW.Integrator_DSTATE_lq += 0.02 * Aenea_model_B.Long_Home;

  // Update for DiscreteIntegrator: '<S303>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S303>/Constant7'
  //   Constant: '<S303>/Constant8'
  //   Sum: '<S303>/Sum'

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

  // End of Update for DiscreteIntegrator: '<S303>/Discrete-Time Integrator'
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    // Update for Memory: '<S23>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput = Aenea_model_B.Switch1_g;
  }

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

    // Start for S-Function (Mti_sfun): '<S567>/S-Function Builder1'

    // S-Function Block: <S567>/S-Function Builder1
    Mti_sfun_Start_wrapper();

    // Start for S-Function (Seriale_mav_sfun): '<S1>/S-Function Builder'

    // S-Function Block: <S1>/S-Function Builder
    Seriale_mav_sfun_Start_wrapper();

    // Start for S-Function (GPS_sfun): '<S566>/S-Function Builder'

    // S-Function Block: <S566>/S-Function Builder
    GPS_sfun_Start_wrapper();

    // Start for S-Function (enable_sfun): '<S2>/S-Function Builder'

    // S-Function Block: <S2>/S-Function Builder
    enable_sfun_Start_wrapper();
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

    // InitializeConditions for Switch: '<S23>/Switch' incorporates:
    //   Memory: '<S23>/Memory1'

    Aenea_model_DW.Memory1_PreviousInput = -1.0;

    // InitializeConditions for Memory: '<S23>/Memory'
    Aenea_model_DW.Memory_PreviousInput = -0.02;

    // InitializeConditions for UnitDelay: '<S565>/Unit Delay1'
    Aenea_model_DW.UnitDelay1_DSTATE = 101440.0;

    // InitializeConditions for DiscreteIntegrator: '<S388>/Integrator'
    Aenea_model_DW.Integrator_PrevResetState = 2;

    // InitializeConditions for DiscreteIntegrator: '<S303>/Discrete-Time Integrator' 
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for UnitDelay: '<S568>/Delay Input2'
    //
    //  Block description for '<S568>/Delay Input2':
    //
    //   Store in Global RAM

    Aenea_model_DW.DelayInput2_DSTATE = 101325.0;

    // InitializeConditions for Memory: '<S23>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput = -1.0;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1'
    std::memcpy(&Aenea_model_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    // SystemInitialize for Atomic SubSystem: '<S565>/Execution_loop'
    // Start for S-Function (BMP280_sfun): '<S569>/S-Function Builder'

    // S-Function Block: <S569>/S-Function Builder
    BMP280_sfun_Start_wrapper();

    // End of SystemInitialize for SubSystem: '<S565>/Execution_loop'

    // SystemInitialize for Chart: '<S34>/ STATI'
    Aenea_model_B.modo = 1.0;

    // SystemInitialize for Enabled SubSystem: '<S35>/Subsystem1'
    // InitializeConditions for Memory: '<S438>/Memory7'
    Aenea_model_DW.Memory7_PreviousInput = 1.0;

    // SystemInitialize for Enabled SubSystem: '<S438>/APPROACH'
    // Start for Constant: '<S449>/Constant1'
    Aenea_model_B.Constant1_h = 20.0;

    // InitializeConditions for DiscreteIntegrator: '<S449>/Discrete-Time Integrator' 
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

    // End of SystemInitialize for SubSystem: '<S438>/APPROACH'

    // SystemInitialize for Enabled SubSystem: '<S438>/FLARE'
    // Start for Constant: '<S453>/Constant1'
    Aenea_model_B.Constant1 = 18.0;

    // End of SystemInitialize for SubSystem: '<S438>/FLARE'
    // End of SystemInitialize for SubSystem: '<S35>/Subsystem1'

    // SystemInitialize for Enabled SubSystem: '<S2>/Subsystem'
    // Start for S-Function (MavLink_Send_sfun): '<S18>/S-Function Builder'

    // S-Function Block: <S18>/S-Function Builder
    MavLink_Send_sfun_Start_wrapper();

    // End of SystemInitialize for SubSystem: '<S2>/Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S35>/Subsystem2'
    // InitializeConditions for Memory: '<S439>/Memory4'
    Aenea_model_DW.Memory4_PreviousInput = 1.0;

    // End of SystemInitialize for SubSystem: '<S35>/Subsystem2'

    // SystemInitialize for Triggered SubSystem: '<S247>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S299>/Out1' incorporates:
    //   Outport: '<S299>/Out1'

    Aenea_model_B.OutportBufferForOut1 = 1.0;

    // End of SystemInitialize for SubSystem: '<S247>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S565>/MATLAB Function'
    Aenea_model_DW.P_ref = 102600.0;
    Aenea_model_DW.rl_up = 300.0;
    Aenea_model_DW.rl_dw = -300.0;
  }
}

// Model terminate function
void Aenea_model_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S565>/Execution_loop'

  // Terminate for S-Function (BMP280_sfun): '<S569>/S-Function Builder'

  // S-Function Block: <S569>/S-Function Builder
  BMP280_sfun_Terminate_wrapper();

  // End of Terminate for SubSystem: '<S565>/Execution_loop'

  // Terminate for Enabled SubSystem: '<S2>/Subsystem'

  // Terminate for S-Function (MavLink_Send_sfun): '<S18>/S-Function Builder'

  // S-Function Block: <S18>/S-Function Builder
  MavLink_Send_sfun_Terminate_wrapper();

  // End of Terminate for SubSystem: '<S2>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//
