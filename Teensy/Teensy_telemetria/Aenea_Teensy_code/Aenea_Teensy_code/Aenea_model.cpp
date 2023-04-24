//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.cpp
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.173
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Mon Apr 24 08:41:43 2023
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Aenea_model.h"
#include "Aenea_model_private.h"

// Named constants for Chart: '<S40>/SELEZIONE MODALITA\'  HOLD//SELECT'
const uint8_T Aenea_model_IN_Hold = 1U;
const uint8_T Aenea_model_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T Aenea_model_IN_Select = 2U;

// Named constants for Chart: '<S38>/ STATI'
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

// Named constants for Chart: '<S39>/Chart'
const uint8_T Aenea_model_IN_AutoLanding = 1U;
const uint8_T Aenea_model_IN_AutoTakeoff = 2U;
const uint8_T Aenea_model_IN_GoHome = 3U;
const uint8_T Aenea_model_IN_In = 4U;
const uint8_T Aenea_model_IN_Vettoriale = 5U;
const uint8_T Aenea_model_IN_Waypoint = 6U;

// Named constants for Chart: '<S440>/Chart1'
const uint8_T Aenea_model_IN_Fase_0_ATO = 1U;
const uint8_T Aenea_model_IN_Fase_1_ATO = 2U;
const uint8_T Aenea_model_IN_Fase_2_ATO = 3U;
const uint8_T Aenea_model_IN_Fase_3_ATO = 4U;
const uint8_T Aenea_model_IN_Fase_4_ATO = 5U;

// Named constants for Chart: '<S442>/Chart1'
const uint8_T Aenea_model_IN_Abort = 1U;
const uint8_T Aenea_model_IN_Allignment = 2U;
const uint8_T Aenea_model_IN_Allignment1 = 3U;
const uint8_T Aenea_model_IN_Approach = 4U;
const uint8_T Aenea_model_IN_Flare = 5U;
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

  (Aenea_model_M->Timing.TaskCounters.TID[2])++;
  if ((Aenea_model_M->Timing.TaskCounters.TID[2]) > 49) {// Sample time: [1.0s, 0.0s] 
    Aenea_model_M->Timing.TaskCounters.TID[2] = 0;
  }
}

//
// Output and update for enable system:
//    '<S410>/Enabled Subsystem'
//    '<S411>/Enabled Subsystem'
//
void Aenea_model_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time, real_T
  *rty_u0)
{
  // Outputs for Enabled SubSystem: '<S410>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S419>/Enable'

  if (rtu_Enable > 0) {
    // Switch: '<S419>/Switch'
    *rty_u0 = !(rtu_Time > 2.0);
  }

  // End of Outputs for SubSystem: '<S410>/Enabled Subsystem'
}

//
// System reset for atomic system:
//    '<S410>/Resettable Subsystem'
//    '<S411>/Resettable Subsystem'
//
void Aenea_ResettableSubsystem_Reset(DW_ResettableSubsystem_Aenea__T *localDW)
{
  // InitializeConditions for Memory: '<S421>/Memory'
  localDW->Memory_PreviousInput = 0.0;
}

//
// Output and update for atomic system:
//    '<S410>/Resettable Subsystem'
//    '<S411>/Resettable Subsystem'
//
void Aenea_model_ResettableSubsystem(uint8_T rtu_Reset, real_T *rty_Time,
  DW_ResettableSubsystem_Aenea__T *localDW, ZCE_ResettableSubsystem_Aenea_T
  *localZCE)
{
  // Outputs for Resettable SubSystem: '<S410>/Resettable Subsystem' incorporates:
  //   ResetPort: '<S420>/Reset'

  if ((rtu_Reset > 0) && (localZCE->ResettableSubsystem_Reset_ZCE_k != POS_ZCSIG))
  {
    Aenea_ResettableSubsystem_Reset(localDW);
  }

  localZCE->ResettableSubsystem_Reset_ZCE_k = (rtu_Reset > 0);

  // Sum: '<S421>/Sum' incorporates:
  //   Constant: '<S421>/Constant4'
  //   Memory: '<S421>/Memory'

  *rty_Time = localDW->Memory_PreviousInput + 0.02;

  // Update for Memory: '<S421>/Memory'
  localDW->Memory_PreviousInput = *rty_Time;

  // End of Outputs for SubSystem: '<S410>/Resettable Subsystem'
}

// Function for MATLAB Function: '<S3>/MATLAB Function4'
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

// Function for MATLAB Function: '<S3>/MATLAB Function4'
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

// Function for MATLAB Function: '<S559>/DEFINITIVA'
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

// Function for MATLAB Function: '<S559>/DEFINITIVA'
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

// Function for MATLAB Function: '<S559>/DEFINITIVA'
static void Aenea_model_mldivide(const real_T A[121], const real_T B[198],
  real_T Y[198])
{
  std::memcpy(&Y[0], &B[0], 198U * sizeof(real_T));
  std::memcpy(&Aenea_model_B.b_A[0], &A[0], 121U * sizeof(real_T));
  Aenea_model_xgetrfs(Aenea_model_B.b_A, Y);
}

// Function for MATLAB Function: '<S559>/DEFINITIVA'
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

// Function for MATLAB Function: '<S559>/DEFINITIVA'
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

// Function for Chart: '<S39>/Chart'
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

// Function for Chart: '<S39>/Chart'
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
  uint8_T b_v;
  uint8_T c;
  boolean_T Ap_sel;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T rtb_y_c;
  boolean_T rtb_y_e;
  boolean_T rtb_y_n;
  boolean_T tmp;
  boolean_T tmp_0;

  // UnitDelay: '<S575>/Unit Delay'
  std::memcpy(&Aenea_model_B.UnitDelay[0], &Aenea_model_DW.UnitDelay_DSTATE[0],
              9U * sizeof(real_T));

  // S-Function (Mti_sfun): '<S575>/S-Function Builder1'
  Mti_sfun_Outputs_wrapper(&Aenea_model_B.UnitDelay[0],
    &Aenea_model_B.SFunctionBuilder1[0]);

  // MATLAB Function: '<S575>/MATLAB Function1' incorporates:
  //   UnitDelay: '<S575>/Unit Delay1'

  Aenea_model_B.checksum = Aenea_model_B.SFunctionBuilder1[1];
  for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 39; Aenea_model_B.b_k++) {
    Aenea_model_B.checksum += static_cast<real_T>
      (Aenea_model_B.SFunctionBuilder1[Aenea_model_B.b_k + 2]);
  }

  for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 64; Aenea_model_B.npad++) {
    Aenea_model_B.sfull[Aenea_model_B.npad] = '0';
  }

  Aenea_model_B.npad = 64;
  exitg1 = false;
  while ((!exitg1) && (Aenea_model_B.npad > 0)) {
    Aenea_model_B.olddi = Aenea_model_B.checksum;
    Aenea_model_B.checksum = std::floor(Aenea_model_B.checksum / 2.0);
    if (2.0 * Aenea_model_B.checksum < Aenea_model_B.olddi) {
      Aenea_model_B.sfull[Aenea_model_B.npad - 1] = '1';
    }

    if (!(Aenea_model_B.checksum > 0.0)) {
      exitg1 = true;
    } else {
      Aenea_model_B.npad--;
    }
  }

  Aenea_model_B.idx = 0;
  Aenea_model_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (Aenea_model_B.b_k < 64)) {
    if (Aenea_model_B.sfull[Aenea_model_B.b_k] == '1') {
      Aenea_model_B.idx = Aenea_model_B.b_k + 1;
      exitg1 = true;
    } else {
      Aenea_model_B.b_k++;
    }
  }

  if (Aenea_model_B.idx == 0) {
    Aenea_model_B.idx = 64;
  }

  if (4 >= 65 - Aenea_model_B.idx) {
    Aenea_model_B.b_k = 4;
  } else {
    Aenea_model_B.b_k = 65 - Aenea_model_B.idx;
  }

  if (65 - Aenea_model_B.idx < 4) {
    Aenea_model_B.npad = Aenea_model_B.idx;
    Aenea_model_B.srem = 0;
    while (Aenea_model_B.srem <= Aenea_model_B.idx - 62) {
      Aenea_model_B.b_data[Aenea_model_B.srem] = '0';
      Aenea_model_B.srem++;
    }
  } else {
    Aenea_model_B.npad = 61;
  }

  Aenea_model_B.d_k = -1;
  while (Aenea_model_B.d_k + 1 <= 64 - Aenea_model_B.idx) {
    Aenea_model_B.b_data[(Aenea_model_B.npad + Aenea_model_B.d_k) - 60] =
      Aenea_model_B.sfull[Aenea_model_B.idx + Aenea_model_B.d_k];
    Aenea_model_B.d_k++;
  }

  Aenea_model_B.idx = (Aenea_model_B.b_k >> 2) - 1;
  Aenea_model_B.srem = Aenea_model_B.b_k - ((Aenea_model_B.idx + 1) << 2);
  if (Aenea_model_B.srem == 0) {
    Aenea_model_B.d_k = 0;
    while (Aenea_model_B.d_k <= Aenea_model_B.idx) {
      Aenea_model_B.b_k = Aenea_model_B.d_k << 2;
      if (Aenea_model_B.b_data[Aenea_model_B.b_k + 3] == '1') {
        b_v = 1U;
      } else {
        b_v = 0U;
      }

      if (Aenea_model_B.b_data[Aenea_model_B.b_k + 2] == '1') {
        b_v = static_cast<uint8_T>(b_v + 2);
      }

      if (Aenea_model_B.b_data[Aenea_model_B.b_k + 1] == '1') {
        b_v = static_cast<uint8_T>(b_v + 4);
      }

      if (Aenea_model_B.b_data[Aenea_model_B.b_k] == '1') {
        b_v = static_cast<uint8_T>(b_v + 8);
      }

      if (b_v > 9) {
        Aenea_model_B.hex_checksum_data[Aenea_model_B.d_k] = static_cast<int8_T>
          (b_v + 55);
      } else {
        Aenea_model_B.hex_checksum_data[Aenea_model_B.d_k] = static_cast<int8_T>
          (b_v + 48);
      }

      Aenea_model_B.d_k++;
    }
  } else {
    Aenea_model_B.npad = 0;
    while (Aenea_model_B.npad <= Aenea_model_B.idx) {
      Aenea_model_B.b_k = (Aenea_model_B.npad << 2) + Aenea_model_B.srem;
      if (Aenea_model_B.b_data[Aenea_model_B.b_k + 3] == '1') {
        b_v = 1U;
      } else {
        b_v = 0U;
      }

      if (Aenea_model_B.b_data[Aenea_model_B.b_k + 2] == '1') {
        b_v = static_cast<uint8_T>(b_v + 2);
      }

      if (Aenea_model_B.b_data[Aenea_model_B.b_k + 1] == '1') {
        b_v = static_cast<uint8_T>(b_v + 4);
      }

      if (Aenea_model_B.b_data[Aenea_model_B.b_k] == '1') {
        b_v = static_cast<uint8_T>(b_v + 8);
      }

      if (b_v > 9) {
        Aenea_model_B.hex_checksum_data[Aenea_model_B.npad + 1] =
          static_cast<int8_T>(b_v + 55);
      } else {
        Aenea_model_B.hex_checksum_data[Aenea_model_B.npad + 1] =
          static_cast<int8_T>(b_v + 48);
      }

      Aenea_model_B.npad++;
    }
  }

  if ((Aenea_model_B.hex_checksum_data[2] == '0') &&
      (Aenea_model_B.hex_checksum_data[3] == '0')) {
    for (Aenea_model_B.i = 0; Aenea_model_B.i < 41; Aenea_model_B.i++) {
      Aenea_model_B.Mex_out[Aenea_model_B.i] =
        Aenea_model_B.SFunctionBuilder1[Aenea_model_B.i];
    }
  } else {
    for (Aenea_model_B.i = 0; Aenea_model_B.i < 41; Aenea_model_B.i++) {
      Aenea_model_B.Mex_out[Aenea_model_B.i] =
        Aenea_model_DW.UnitDelay1_DSTATE_b[Aenea_model_B.i];
    }
  }

  // End of MATLAB Function: '<S575>/MATLAB Function1'

  // S-Function (byte2any_svd): '<S575>/Byte Unpack'

  // Unpack: <S575>/Byte Unpack
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
             &Aenea_model_B.Mex_out[0] + MW_inputPortOffset, MW_outputPortWidth);
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
             &Aenea_model_B.Mex_out[0] + MW_inputPortOffset, MW_outputPortWidth);
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
             &Aenea_model_B.Mex_out[0] + MW_inputPortOffset, MW_outputPortWidth);
    }
  }

  // S-Function (reverseendian_svd): '<S575>/Byte Reversal'

  // ReverseEndian: <S575>/Byte Reversal

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

  // S-Function (Seriale_mav_sfun): '<S3>/S-Function Builder'
  Seriale_mav_sfun_Outputs_wrapper(&Aenea_model_B.SFunctionBuilder_o1_a[0],
    &Aenea_model_B.SFunctionBuilder_o2_a);

  // MATLAB Function: '<S3>/MATLAB Function4'
  Aenea_model_B.idx = 0;
  Aenea_model_B.b_k = 0;
  std::memset(&Aenea_model_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  std::memset(&Aenea_model_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  Aenea_model_find_254(Aenea_model_B.SFunctionBuilder_o1_a, Aenea_model_B.aterra,
                       &Aenea_model_B.checksum);
  if (Aenea_model_DW.Interr_parz && (Aenea_model_B.checksum == 1.0)) {
    Aenea_model_B.npad = static_cast<int32_T>(Aenea_model_DW.counter_f + 1U);
    if (Aenea_model_DW.counter_f + 1U > 255U) {
      Aenea_model_B.npad = 255;
    }

    if (Aenea_model_B.aterra[0] != Aenea_model_B.npad) {
      Aenea_model_B.checksum = 0.0;
    }
  }

  Ap_sel = !Aenea_model_DW.Interr_parz;
  if ((Aenea_model_B.checksum == 1.0) && Ap_sel) {
    Aenea_model_B.b_k = 1;
  } else if ((Aenea_model_B.checksum == 0.0) && Aenea_model_DW.Interr_parz) {
    Aenea_model_B.b_k = 2;
  } else if ((Aenea_model_B.checksum == 1.0) && Aenea_model_DW.Interr_parz) {
    Aenea_model_B.b_k = 3;
  } else {
    if ((Aenea_model_B.checksum == 2.0) && Ap_sel) {
      Aenea_model_B.b_k = 4;
    }
  }

  switch (Aenea_model_B.b_k) {
   case 1:
    Aenea_model_B.a_b = Aenea_model_B.aterra[static_cast<int32_T>
      (Aenea_model_B.checksum) - 1];
    if (Aenea_model_B.a_b == 100.0) {
      Aenea_model_DW.message[0] = Aenea_model_B.SFunctionBuilder_o1_a[99];
      Aenea_model_DW.Interr_parz = true;
    } else if (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
               (Aenea_model_B.a_b + 1.0) - 1] <= 100) {
      Aenea_model_B.npad = static_cast<int32_T>
        (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[0] + 1.0) - 1] + 8U);
      Aenea_model_B.soglia_dist = Aenea_model_B.npad;
      if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
        Aenea_model_B.soglia_dist = 255;
      }

      if (Aenea_model_B.soglia_dist == Aenea_model_B.SFunctionBuilder_o2_a) {
        Aenea_model_B.e = rt_roundd_snf(Aenea_model_B.a_b);
        if (Aenea_model_B.e < 256.0) {
          if (Aenea_model_B.e >= 0.0) {
            b_v = static_cast<uint8_T>(Aenea_model_B.e);
          } else {
            b_v = 0U;
          }
        } else {
          b_v = MAX_uint8_T;
        }

        Aenea_model_B.npad = static_cast<int32_T>
          (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
           (Aenea_model_B.a_b + 1.0) - 1] + 7U);
        if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
          Aenea_model_B.npad = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.a_b + static_cast<real_T>
          (Aenea_model_B.npad));
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            c = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (b_v > c) {
          Aenea_model_B.d_k = 0;
          Aenea_model_B.i = 0;
        } else {
          Aenea_model_B.d_k = b_v - 1;
          Aenea_model_B.i = c;
        }

        Aenea_model_B.b_k = Aenea_model_B.i - Aenea_model_B.d_k;
        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < Aenea_model_B.b_k;
             Aenea_model_B.npad++) {
          Aenea_model_DW.message[Aenea_model_B.npad] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.d_k +
            Aenea_model_B.npad];
        }

        Aenea_model_B.idx = 1;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_f = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
          Aenea_model_B.npad = 255;
        }

        if (Aenea_model_B.npad > Aenea_model_B.SFunctionBuilder_o2_a) {
          Aenea_model_DW.mess_len = Aenea_model_B.SFunctionBuilder_o2_a;
          if (Aenea_model_B.a_b > Aenea_model_DW.mess_len) {
            Aenea_model_B.srem = 0;
            Aenea_model_B.b_k = 0;
          } else {
            Aenea_model_B.srem = static_cast<int32_T>(Aenea_model_B.a_b) - 1;
            Aenea_model_B.b_k = static_cast<int32_T>(Aenea_model_DW.mess_len);
          }

          Aenea_model_B.b_k -= Aenea_model_B.srem;
          for (Aenea_model_B.npad = 0; Aenea_model_B.npad < Aenea_model_B.b_k;
               Aenea_model_B.npad++) {
            Aenea_model_DW.message[Aenea_model_B.npad] =
              Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.srem +
              Aenea_model_B.npad];
          }

          Aenea_model_B.npad = static_cast<int32_T>
            (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
             (Aenea_model_B.a_b + 1.0) - 1] + 8U);
          if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
            Aenea_model_B.npad = 255;
          }

          Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
            (Aenea_model_B.npad) - Aenea_model_DW.mess_len);
          if (Aenea_model_B.a_b < 256.0) {
            if (Aenea_model_B.a_b >= 0.0) {
              Aenea_model_DW.counter_f = static_cast<uint8_T>(Aenea_model_B.a_b);
            } else {
              Aenea_model_DW.counter_f = 0U;
            }
          } else {
            Aenea_model_DW.counter_f = MAX_uint8_T;
          }

          Aenea_model_DW.Interr_parz = true;
        }
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.counter_f = 0U;
      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_B.idx = 1;
    }
    break;

   case 2:
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.x[Aenea_model_B.npad] =
        (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.npad] != 0);
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
        static_cast<real_T>(Aenea_model_DW.counter_f));
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          b_v = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          b_v = 0U;
        }
      } else {
        b_v = MAX_uint8_T;
      }

      if (c > b_v) {
        Aenea_model_B.idx = 1;
      } else {
        Aenea_model_B.idx = c;
      }

      if (1 > Aenea_model_DW.counter_f) {
        Aenea_model_B.b_k = -1;
      } else {
        Aenea_model_B.b_k = Aenea_model_DW.counter_f - 1;
      }

      for (Aenea_model_B.npad = 0; Aenea_model_B.npad <= Aenea_model_B.b_k;
           Aenea_model_B.npad++) {
        Aenea_model_DW.message[(Aenea_model_B.idx + Aenea_model_B.npad) - 1] =
          Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.npad];
      }

      Aenea_model_DW.Interr_parz = false;
      Aenea_model_B.idx = 1;
      for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
        Aenea_model_B.messaggio[Aenea_model_B.i] =
          Aenea_model_DW.message[Aenea_model_B.i];
        Aenea_model_DW.message[Aenea_model_B.i] = 0U;
      }

      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_DW.counter_f = 0U;
    } else {
      Aenea_model_DW.Interr_parz = false;
      Aenea_model_B.idx = 1;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.mess_len = 0.0;
      Aenea_model_DW.counter_f = 0U;
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
      real_T>(Aenea_model_DW.counter_f));
    if (Aenea_model_B.a_b < 256.0) {
      if (Aenea_model_B.a_b >= 0.0) {
        b_v = static_cast<uint8_T>(Aenea_model_B.a_b);
      } else {
        b_v = 0U;
      }
    } else {
      b_v = MAX_uint8_T;
    }

    if (c > b_v) {
      Aenea_model_B.idx = 1;
    } else {
      Aenea_model_B.idx = c;
    }

    if (1 > Aenea_model_DW.counter_f) {
      Aenea_model_B.b_k = -1;
    } else {
      Aenea_model_B.b_k = Aenea_model_DW.counter_f - 1;
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad <= Aenea_model_B.b_k;
         Aenea_model_B.npad++) {
      Aenea_model_DW.message[(Aenea_model_B.idx + Aenea_model_B.npad) - 1] =
        Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.npad];
    }

    Aenea_model_DW.Interr_parz = false;
    Aenea_model_B.idx = 1;
    for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
      Aenea_model_B.messaggio[Aenea_model_B.i] =
        Aenea_model_DW.message[Aenea_model_B.i];
      Aenea_model_DW.message[Aenea_model_B.i] = 0U;
    }

    Aenea_model_DW.mess_len = 0.0;
    Aenea_model_DW.counter_f = 0U;
    Aenea_model_B.npad = static_cast<int32_T>(Aenea_model_B.aterra
      [static_cast<int32_T>(Aenea_model_B.checksum) - 1] + 1.0) - 1;
    if (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.npad] <= 100) {
      Aenea_model_B.soglia_dist = static_cast<int32_T>
        (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[0] + 1.0) - 1] + 8U);
      if (static_cast<uint32_T>(Aenea_model_B.soglia_dist) > 255U) {
        Aenea_model_B.soglia_dist = 255;
      }

      Aenea_model_B.b_k = Aenea_model_B.SFunctionBuilder_o2_a;
      if (Aenea_model_B.SFunctionBuilder_o2_a < 0) {
        Aenea_model_B.b_k = 0;
      } else {
        if (Aenea_model_B.SFunctionBuilder_o2_a > 255) {
          Aenea_model_B.b_k = 255;
        }
      }

      if (Aenea_model_B.soglia_dist == Aenea_model_B.b_k) {
        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra
          [static_cast<int32_T>(Aenea_model_B.checksum) - 1]);
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            b_v = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            b_v = 0U;
          }
        } else {
          b_v = MAX_uint8_T;
        }

        Aenea_model_B.npad = static_cast<int32_T>
          (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.npad] + 7U);
        if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
          Aenea_model_B.npad = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra
          [static_cast<int32_T>(Aenea_model_B.checksum) - 1] +
          static_cast<real_T>(Aenea_model_B.npad));
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            c = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (b_v > c) {
          Aenea_model_B.srem = 0;
          Aenea_model_B.b_k = 0;
        } else {
          Aenea_model_B.srem = b_v - 1;
          Aenea_model_B.b_k = c;
        }

        Aenea_model_B.b_k -= Aenea_model_B.srem;
        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < Aenea_model_B.b_k;
             Aenea_model_B.npad++) {
          Aenea_model_DW.message[Aenea_model_B.npad] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.srem +
            Aenea_model_B.npad];
        }

        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio_2[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_f = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        Aenea_model_B.soglia_dist = static_cast<int32_T>
          (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
           (Aenea_model_B.aterra[0] + 1.0) - 1] + 8U);
        if (static_cast<uint32_T>(Aenea_model_B.soglia_dist) > 255U) {
          Aenea_model_B.soglia_dist = 255;
        }

        Aenea_model_B.b_k = Aenea_model_B.SFunctionBuilder_o2_a;
        if (Aenea_model_B.SFunctionBuilder_o2_a < 0) {
          Aenea_model_B.b_k = 0;
        } else {
          if (Aenea_model_B.SFunctionBuilder_o2_a > 255) {
            Aenea_model_B.b_k = 255;
          }
        }

        if (Aenea_model_B.soglia_dist > Aenea_model_B.b_k) {
          Aenea_model_DW.mess_len = Aenea_model_B.SFunctionBuilder_o2_a;
          if (Aenea_model_B.aterra[static_cast<int32_T>(Aenea_model_B.checksum)
              - 1] > Aenea_model_DW.mess_len) {
            Aenea_model_B.srem = 0;
            Aenea_model_B.b_k = 0;
          } else {
            Aenea_model_B.srem = static_cast<int32_T>(Aenea_model_B.aterra[
              static_cast<int32_T>(Aenea_model_B.checksum) - 1]) - 1;
            Aenea_model_B.b_k = static_cast<int32_T>(Aenea_model_DW.mess_len);
          }

          Aenea_model_B.b_k -= Aenea_model_B.srem;
          for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist <
               Aenea_model_B.b_k; Aenea_model_B.soglia_dist++) {
            Aenea_model_DW.message[Aenea_model_B.soglia_dist] =
              Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.srem +
              Aenea_model_B.soglia_dist];
          }

          Aenea_model_B.npad = static_cast<int32_T>
            (Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.npad] + 8U);
          if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
            Aenea_model_B.npad = 255;
          }

          Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
            (Aenea_model_B.npad) - Aenea_model_DW.mess_len);
          if (Aenea_model_B.a_b < 256.0) {
            if (Aenea_model_B.a_b >= 0.0) {
              Aenea_model_DW.counter_f = static_cast<uint8_T>(Aenea_model_B.a_b);
            } else {
              Aenea_model_DW.counter_f = 0U;
            }
          } else {
            Aenea_model_DW.counter_f = MAX_uint8_T;
          }

          Aenea_model_DW.Interr_parz = true;
        }
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.counter_f = 0U;
      Aenea_model_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
        (Aenea_model_B.aterra[0] + 1.0) - 1] <= 100) {
      Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[0]);
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          b_v = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          b_v = 0U;
        }
      } else {
        b_v = MAX_uint8_T;
      }

      Aenea_model_B.npad = static_cast<int32_T>
        (Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[0] + 1.0) - 1] + 7U);
      if (static_cast<uint32_T>(Aenea_model_B.npad) > 255U) {
        Aenea_model_B.npad = 255;
      }

      Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[0] +
        static_cast<real_T>(Aenea_model_B.npad));
      if (Aenea_model_B.a_b < 256.0) {
        if (Aenea_model_B.a_b >= 0.0) {
          c = static_cast<uint8_T>(Aenea_model_B.a_b);
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      if (b_v > c) {
        Aenea_model_B.idx = 0;
        Aenea_model_B.b_k = 0;
      } else {
        Aenea_model_B.idx = b_v - 1;
        Aenea_model_B.b_k = c;
      }

      Aenea_model_B.b_k -= Aenea_model_B.idx;
      for (Aenea_model_B.npad = 0; Aenea_model_B.npad < Aenea_model_B.b_k;
           Aenea_model_B.npad++) {
        Aenea_model_B.messaggio[Aenea_model_B.npad] =
          Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.idx +
          Aenea_model_B.npad];
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    Aenea_model_B.idx = 1;
    if ((Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
         (Aenea_model_B.aterra[1] + 1.0) - 1] <= 100) && (Aenea_model_B.aterra[1]
         - Aenea_model_B.aterra[0] > 3.0)) {
      Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>
        (Aenea_model_B.SFunctionBuilder_o2_a) - Aenea_model_B.aterra[1]);
      Aenea_model_B.qY = Aenea_model_B.SFunctionBuilder_o1_a[static_cast<int32_T>
        (Aenea_model_B.aterra[1] + 1.0) - 1];
      Aenea_model_B.npad = static_cast<int32_T>(Aenea_model_B.qY + 7U);
      if (Aenea_model_B.qY + 7U > 255U) {
        Aenea_model_B.npad = 255;
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

      if (Aenea_model_B.soglia_dist == Aenea_model_B.npad) {
        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[1]);
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            b_v = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            b_v = 0U;
          }
        } else {
          b_v = MAX_uint8_T;
        }

        Aenea_model_B.npad = static_cast<int32_T>(Aenea_model_B.qY + 7U);
        if (Aenea_model_B.qY + 7U > 255U) {
          Aenea_model_B.npad = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[1] + static_cast<
          real_T>(Aenea_model_B.npad));
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            c = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (b_v > c) {
          Aenea_model_B.idx = 0;
          Aenea_model_B.b_k = 0;
        } else {
          Aenea_model_B.idx = b_v - 1;
          Aenea_model_B.b_k = c;
        }

        Aenea_model_B.b_k -= Aenea_model_B.idx;
        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < Aenea_model_B.b_k;
             Aenea_model_B.npad++) {
          Aenea_model_DW.message[Aenea_model_B.npad] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.idx +
            Aenea_model_B.npad];
        }

        Aenea_model_B.idx = 2;
        for (Aenea_model_B.i = 0; Aenea_model_B.i < 100; Aenea_model_B.i++) {
          Aenea_model_B.messaggio_2[Aenea_model_B.i] =
            Aenea_model_DW.message[Aenea_model_B.i];
          Aenea_model_DW.message[Aenea_model_B.i] = 0U;
        }

        Aenea_model_DW.counter_f = 0U;
        Aenea_model_DW.mess_len = 0.0;
      } else {
        Aenea_model_B.a_b = rt_roundd_snf(Aenea_model_B.aterra[1]);
        if (Aenea_model_B.a_b < 2.147483648E+9) {
          if (Aenea_model_B.a_b >= -2.147483648E+9) {
            Aenea_model_B.b_k = static_cast<int32_T>(Aenea_model_B.a_b);
          } else {
            Aenea_model_B.b_k = MIN_int32_T;
          }
        } else {
          Aenea_model_B.b_k = MAX_int32_T;
        }

        if (Aenea_model_B.b_k > Aenea_model_B.SFunctionBuilder_o2_a) {
          Aenea_model_B.b_k = -1;
          Aenea_model_B.npad = 0;
        } else {
          Aenea_model_B.b_k -= 2;
          Aenea_model_B.npad = Aenea_model_B.SFunctionBuilder_o2_a;
        }

        Aenea_model_DW.mess_len = static_cast<int8_T>((Aenea_model_B.npad -
          Aenea_model_B.b_k) - 1);
        if (Aenea_model_B.a_b < 2.147483648E+9) {
          if (Aenea_model_B.a_b >= -2.147483648E+9) {
            Aenea_model_B.b_k = static_cast<int32_T>(Aenea_model_B.a_b);
          } else {
            Aenea_model_B.b_k = MIN_int32_T;
          }
        } else {
          Aenea_model_B.b_k = MAX_int32_T;
        }

        if (Aenea_model_B.b_k > Aenea_model_B.SFunctionBuilder_o2_a) {
          Aenea_model_B.srem = 0;
          Aenea_model_B.b_k = 0;
        } else {
          Aenea_model_B.srem = Aenea_model_B.b_k - 1;
          Aenea_model_B.b_k = Aenea_model_B.SFunctionBuilder_o2_a;
        }

        Aenea_model_B.b_k -= Aenea_model_B.srem;
        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < Aenea_model_B.b_k;
             Aenea_model_B.npad++) {
          Aenea_model_DW.message[Aenea_model_B.npad] =
            Aenea_model_B.SFunctionBuilder_o1_a[Aenea_model_B.srem +
            Aenea_model_B.npad];
        }

        Aenea_model_B.npad = static_cast<int32_T>(Aenea_model_B.qY + 8U);
        if (Aenea_model_B.qY + 8U > 255U) {
          Aenea_model_B.npad = 255;
        }

        Aenea_model_B.a_b = rt_roundd_snf(static_cast<real_T>(Aenea_model_B.npad)
          - Aenea_model_DW.mess_len);
        if (Aenea_model_B.a_b < 256.0) {
          if (Aenea_model_B.a_b >= 0.0) {
            Aenea_model_DW.counter_f = static_cast<uint8_T>(Aenea_model_B.a_b);
          } else {
            Aenea_model_DW.counter_f = 0U;
          }
        } else {
          Aenea_model_DW.counter_f = MAX_uint8_T;
        }

        Aenea_model_DW.Interr_parz = true;
      }
    } else {
      Aenea_model_DW.Interr_parz = false;
      std::memset(&Aenea_model_DW.message[0], 0, 100U * sizeof(uint8_T));
      Aenea_model_DW.counter_f = 0U;
      Aenea_model_DW.mess_len = 0.0;
    }
    break;
  }

  // MATLAB Function: '<S3>/MATLAB Function2' incorporates:
  //   MATLAB Function: '<S3>/MATLAB Function4'
  //   Memory: '<S3>/Memory4'

  std::memset(&Aenea_model_B.buffer[0], 0, 300U * sizeof(uint8_T));
  b_v = 0U;
  for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++) {
    Aenea_model_B.buffer[3 * Aenea_model_B.npad] = 0U;
  }

  for (Aenea_model_B.d_k = 0; Aenea_model_B.d_k < 2; Aenea_model_B.d_k++) {
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.b_k = 3 * Aenea_model_B.npad + Aenea_model_B.d_k;
      Aenea_model_B.buffer[Aenea_model_B.b_k + 1] =
        Aenea_model_DW.Memory4_PreviousInput_j[Aenea_model_B.b_k];
    }
  }

  Aenea_model_B.i = 3;
  exitg1 = false;
  while ((!exitg1) && (Aenea_model_B.i >= 1)) {
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.x[Aenea_model_B.npad] = (Aenea_model_B.buffer[(3 *
        Aenea_model_B.npad + Aenea_model_B.i) - 1] == 0);
    }

    Ap_sel = true;
    Aenea_model_B.b_k = 0;
    exitg2 = false;
    while ((!exitg2) && (Aenea_model_B.b_k < 100)) {
      if (!Aenea_model_B.x[Aenea_model_B.b_k]) {
        Ap_sel = false;
        exitg2 = true;
      } else {
        Aenea_model_B.b_k++;
      }
    }

    if (Ap_sel) {
      b_v = static_cast<uint8_T>(Aenea_model_B.i);
      exitg1 = true;
    } else {
      Aenea_model_B.i--;
    }
  }

  if (Aenea_model_B.idx == 1) {
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.buffer[(b_v + 3 * Aenea_model_B.npad) - 1] =
        Aenea_model_B.messaggio[Aenea_model_B.npad];
    }
  } else if (Aenea_model_B.idx == 2) {
    Aenea_model_B.qY = b_v - /*MW:OvSatOk*/ 1U;
    if (b_v - 1U > b_v) {
      Aenea_model_B.qY = 0U;
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.buffer[(b_v + 3 * Aenea_model_B.npad) - 1] =
        Aenea_model_B.messaggio[Aenea_model_B.npad];
      Aenea_model_B.buffer[(static_cast<int32_T>(Aenea_model_B.qY) + 3 *
                            Aenea_model_B.npad) - 1] =
        Aenea_model_B.messaggio_2[Aenea_model_B.npad];
    }
  } else {
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.buffer[(b_v + 3 * Aenea_model_B.npad) - 1] = 0U;
    }
  }

  for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++) {
    Aenea_model_B.mess_out[Aenea_model_B.npad] =
      Aenea_model_DW.Memory4_PreviousInput_j[3 * Aenea_model_B.npad + 2];
  }

  // Sum: '<S3>/Add' incorporates:
  //   Constant: '<S3>/Constant'
  //   MATLAB Function: '<S3>/MATLAB Function2'
  //   Memory: '<S3>/Memory4'

  Aenea_model_B.Add = Aenea_model_DW.Memory4_PreviousInput_j[5] + 8;

  // MATLAB Function: '<S3>/MATLAB Function3' incorporates:
  //   Memory: '<S3>/Memory5'

  if (Aenea_model_B.mess_out[2] != Aenea_model_DW.Memory5_PreviousInput_b[2]) {
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 100; Aenea_model_B.npad++)
    {
      Aenea_model_B.x[Aenea_model_B.npad] =
        (Aenea_model_B.mess_out[Aenea_model_B.npad] != 0);
    }

    Ap_sel = true;
    Aenea_model_B.b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (Aenea_model_B.b_k < 100)) {
      if (!Aenea_model_B.x[Aenea_model_B.b_k]) {
        Ap_sel = false;
        exitg1 = true;
      } else {
        Aenea_model_B.b_k++;
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

  // End of MATLAB Function: '<S3>/MATLAB Function3'

  // Memory: '<S3>/Memory1'
  Aenea_model_B.Memory1[0] = Aenea_model_DW.Memory1_PreviousInput_b[0];
  Aenea_model_B.Memory1[1] = Aenea_model_DW.Memory1_PreviousInput_b[1];

  // Memory: '<S1>/Memory'
  Aenea_model_B.Memory_h[0] = Aenea_model_B.DataTypeConversion1_f[0];
  Aenea_model_B.Memory_h[1] = Aenea_model_B.DataTypeConversion1_f[1];
  Aenea_model_B.Memory_h[2] = Aenea_model_B.DataTypeConversion1_f[2];
  Aenea_model_B.Memory_h[3] = Aenea_model_B.DataTypeConversion1_f[3];

  // Memory: '<S3>/Memory3'
  Aenea_model_B.Memory3 = Aenea_model_DW.Memory3_PreviousInput_g;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 8; Aenea_model_B.i++) {
    // Memory: '<S3>/Memory'
    Aenea_model_B.Memory[Aenea_model_B.i] =
      Aenea_model_DW.Memory_PreviousInput_i[Aenea_model_B.i];
  }

  // S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S3>/S-Function' incorporates:
  //   Constant: '<S1>/SI UAV uint8'

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

  // MATLAB Function: '<S3>/MATLAB Function1'
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

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 6; Aenea_model_B.npad++) {
      Aenea_model_DW.WP_dbI[Aenea_model_B.npad] = Aenea_model_B.WP_info_in[0];
    }
  }

  if ((Aenea_model_B.GC_info[0] == 3) && (Aenea_model_B.GC_info[1] < 200)) {
    if (Aenea_model_B.SFunction_o10[1] == 0.0F) {
      Aenea_model_B.qY = Aenea_model_B.SFunction_o9[1] + 1U;
      if (Aenea_model_B.SFunction_o9[1] + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 7; Aenea_model_B.npad++)
      {
        Aenea_model_DW.WP_dbP[(static_cast<int32_T>(Aenea_model_B.qY) + 6 *
          Aenea_model_B.npad) - 1] =
          Aenea_model_B.SFunction_o10[Aenea_model_B.npad];
      }

      Aenea_model_B.qY = Aenea_model_B.SFunction_o9[1] + 1U;
      if (Aenea_model_B.SFunction_o9[1] + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 6; Aenea_model_B.npad++)
      {
        Aenea_model_DW.WP_dbI[(static_cast<int32_T>(Aenea_model_B.qY) + 6 *
          (Aenea_model_B.npad + 1)) - 1] =
          Aenea_model_B.WP_info_in[Aenea_model_B.npad + 1];
      }
    } else {
      Aenea_model_B.npad = static_cast<int32_T>(Aenea_model_B.SFunction_o10[0] +
        1.0F);
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 7;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_DW.WP_dbP_AL[(Aenea_model_B.npad + 6 *
          Aenea_model_B.soglia_dist) - 1] =
          Aenea_model_B.SFunction_o10[Aenea_model_B.soglia_dist];
      }

      Aenea_model_B.qY = Aenea_model_B.SFunction_o9[1] + 1U;
      if (Aenea_model_B.SFunction_o9[1] + 1U > 65535U) {
        Aenea_model_B.qY = 65535U;
      }

      for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 6; Aenea_model_B.npad++)
      {
        Aenea_model_DW.WP_dbI[(static_cast<int32_T>(Aenea_model_B.qY) + 6 *
          (Aenea_model_B.npad + 1)) - 1] =
          Aenea_model_B.WP_info_in[Aenea_model_B.npad + 1];
      }
    }
  }

  // Update for Memory: '<S3>/Memory3' incorporates:
  //   MATLAB Function: '<S3>/MATLAB Function1'

  Aenea_model_DW.Memory3_PreviousInput_g = 0U;

  // MATLAB Function: '<S3>/MATLAB Function1' incorporates:
  //   Memory: '<S3>/Memory2'

  if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n == 0))
  {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    // Update for Memory: '<S3>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
  } else if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n ==
              3)) {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    // Update for Memory: '<S3>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
    Aenea_model_DW.test1 = 0.0;
  } else if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n ==
              2)) {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    // Update for Memory: '<S3>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
    Aenea_model_DW.test1 = 0.0;
  } else if ((Aenea_model_B.SFunction_o6 == 0) && (Aenea_model_B.SFunction_o3_n ==
              1)) {
    Aenea_model_DW.Memory1_PreviousInput_b[0] = 0U;
    Aenea_model_DW.Memory1_PreviousInput_b[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    // Update for Memory: '<S3>/Memory3'
    Aenea_model_DW.Memory3_PreviousInput_g = 0U;
    Aenea_model_DW.test1 = 1.0;
  } else {
    switch (Aenea_model_B.SFunction_o6) {
     case 192:
      Aenea_model_DW.Memory1_PreviousInput_b[0] = 192U;
      Aenea_model_DW.Memory1_PreviousInput_b[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      // Update for Memory: '<S3>/Memory3'
      Aenea_model_DW.Memory3_PreviousInput_g = 192U;
      break;

     case 208:
      Aenea_model_DW.Memory1_PreviousInput_b[0] = 208U;
      Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      // Update for Memory: '<S3>/Memory3'
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

          // Update for Memory: '<S3>/Memory3'
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

          // Update for Memory: '<S3>/Memory3'
          Aenea_model_DW.Memory3_PreviousInput_g = 220U;
        } else {
          Aenea_model_DW.Memory1_PreviousInput_b[0] = 208U;
          Aenea_model_DW.Memory1_PreviousInput_b[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          // Update for Memory: '<S3>/Memory3'
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

  // RateTransition: '<S27>/Rate Transition'
  Aenea_model_B.checksum = Aenea_model_DW.RateTransition_Buffer0;

  // Switch: '<S27>/Switch' incorporates:
  //   Constant: '<S27>/Constant3'
  //   Memory: '<S27>/Memory1'
  //   Sum: '<S27>/Add1'

  if (Aenea_model_DW.Memory1_PreviousInput + 1.0 > 4.0) {
    // Switch: '<S27>/Switch' incorporates:
    //   Constant: '<S27>/Constant2'

    Aenea_model_DW.Memory1_PreviousInput = 0.0;
  } else {
    // Switch: '<S27>/Switch'
    Aenea_model_DW.Memory1_PreviousInput++;
  }

  // End of Switch: '<S27>/Switch'

  // MATLAB Function: '<S18>/iflogic_function'
  if ((Aenea_model_DW.Memory1_PreviousInput == 1.0) ||
      (Aenea_model_DW.Memory1_PreviousInput == 3.0)) {
    Aenea_model_B.iflogic = 26U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 2.0) ||
             (Aenea_model_DW.Memory1_PreviousInput == 4.0)) {
    Aenea_model_B.iflogic = 30U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.checksum == 2.0)) {
    Aenea_model_B.iflogic = 33U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.checksum == 6.0)) {
    Aenea_model_B.iflogic = 34U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.checksum == 0.0)) {
    Aenea_model_B.iflogic = 0U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             ((Aenea_model_B.checksum == 1.0) || (Aenea_model_B.checksum == 5.0)
              || (Aenea_model_B.checksum == 9.0))) {
    Aenea_model_B.iflogic = 1U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             ((Aenea_model_B.checksum == 3.0) || (Aenea_model_B.checksum == 8.0)))
  {
    Aenea_model_B.iflogic = 74U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.checksum == 7.0)) {
    Aenea_model_B.iflogic = 36U;
  } else if ((Aenea_model_DW.Memory1_PreviousInput == 0.0) &&
             (Aenea_model_B.checksum == 4.0)) {
    Aenea_model_B.iflogic = 29U;
  } else {
    Aenea_model_B.iflogic = MAX_uint8_T;
  }

  // End of MATLAB Function: '<S18>/iflogic_function'

  // Gain: '<S18>/Gain' incorporates:
  //   Constant: '<S27>/Constant1'
  //   Memory: '<S27>/Memory'
  //   Sum: '<S27>/Add'

  Aenea_model_B.e_d = (Aenea_model_DW.Memory_PreviousInput + 0.02) * 100.0;

  // DataTypeConversion: '<S18>/Data Type Conversion3'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S18>/Data Type Conversion3'
  Aenea_model_B.DataTypeConversion3 = Aenea_model_B.a_b < 0.0 ? static_cast<
    uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b))) :
    static_cast<uint32_T>(Aenea_model_B.a_b);

  // MATLAB Function: '<S23>/MATLAB Function' incorporates:
  //   MATLAB Function: '<S3>/MATLAB Function1'

  for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 6; Aenea_model_B.npad++) {
    Aenea_model_B.WP_info[Aenea_model_B.npad] = Aenea_model_DW.WP_dbI[6 *
      Aenea_model_B.npad];
  }

  for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 7; Aenea_model_B.npad++) {
    Aenea_model_B.WP_param[Aenea_model_B.npad] = Aenea_model_DW.WP_dbP[6 *
      Aenea_model_B.npad];
  }

  if ((Aenea_model_B.GC_info[0] == 2) && (Aenea_model_B.GC_info[1] < 6)) {
    Aenea_model_B.qY = Aenea_model_B.GC_info[1] + 1U;
    if (Aenea_model_B.GC_info[1] + 1U > 65535U) {
      Aenea_model_B.qY = 65535U;
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 6; Aenea_model_B.npad++) {
      Aenea_model_B.WP_info[Aenea_model_B.npad] = Aenea_model_DW.WP_dbI[(6 *
        Aenea_model_B.npad + static_cast<int32_T>(Aenea_model_B.qY)) - 1];
    }

    Aenea_model_B.qY = Aenea_model_B.GC_info[1] + 1U;
    if (Aenea_model_B.GC_info[1] + 1U > 65535U) {
      Aenea_model_B.qY = 65535U;
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 7; Aenea_model_B.npad++) {
      Aenea_model_B.WP_param[Aenea_model_B.npad] = Aenea_model_DW.WP_dbP[(6 *
        Aenea_model_B.npad + static_cast<int32_T>(Aenea_model_B.qY)) - 1];
    }
  }

  if ((Aenea_model_B.GC_info[0] == 3) && (Aenea_model_B.GC_info[1] < 200)) {
    Aenea_model_B.qY = Aenea_model_B.GC_info[1] + 1U;
    if (Aenea_model_B.GC_info[1] + 1U > 65535U) {
      Aenea_model_B.qY = 65535U;
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 6; Aenea_model_B.npad++) {
      Aenea_model_B.WP_info[Aenea_model_B.npad] = Aenea_model_DW.WP_dbI[(6 *
        Aenea_model_B.npad + static_cast<int32_T>(Aenea_model_B.qY)) - 1];
    }
  }

  // End of MATLAB Function: '<S23>/MATLAB Function'

  // Outputs for Resettable SubSystem: '<S411>/Resettable Subsystem'
  Aenea_model_ResettableSubsystem(Aenea_model_B.SFunction_o4_a[0],
    &Aenea_model_B.Gain_h, &Aenea_model_DW.ResettableSubsystem_j,
    &Aenea_model_PrevZCX.ResettableSubsystem_j);

  // End of Outputs for SubSystem: '<S411>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S411>/Enabled Subsystem'
  Aenea_model_EnabledSubsystem(Aenea_model_B.SFunction_o4_a[0],
    Aenea_model_B.Gain_h, &Aenea_model_B.Switch_a);

  // End of Outputs for SubSystem: '<S411>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  // DataTypeConversion: '<S578>/Data Type Conversion3' incorporates:
  //   UnitDelay: '<S571>/Unit Delay1'

  Aenea_model_B.DataTypeConversion3_p = static_cast<real32_T>
    (Aenea_model_DW.UnitDelay1_DSTATE);

  // S-Function (BMP280_sfun): '<S578>/S-Function Builder'
  BMP280_sfun_Outputs_wrapper(&Aenea_model_B.DataTypeConversion3_p,
    &Aenea_model_B.SFunctionBuilder_o1_g, &Aenea_model_B.SFunctionBuilder_o2_p,
    &Aenea_model_B.SFunctionBuilder_o3_h);

  // End of Outputs for SubSystem: '<S571>/Execution_loop'

  // S-Function (GPS_sfun): '<S574>/S-Function Builder'
  GPS_sfun_Outputs_wrapper(&Aenea_model_B.Lat, &Aenea_model_B.Long,
    &Aenea_model_B.V, &Aenea_model_B.quota, &Aenea_model_B.heading,
    &Aenea_model_B.SFunctionBuilder_o6, &Aenea_model_B.SFunctionBuilder_o7);

  // S-Function (pitot_lidar_sfun): '<S576>/S-Function Builder'
  pitot_lidar_sfun_Outputs_wrapper(&Aenea_model_B.SFunctionBuilder_o1,
    &Aenea_model_B.SFunctionBuilder_o2, &Aenea_model_B.SFunctionBuilder_o3);

  // Sum: '<S561>/Sum' incorporates:
  //   UnitDelay: '<S561>/Unit Delay'

  Aenea_model_B.Sum_l = Aenea_model_B.SFunctionBuilder_o1 +
    Aenea_model_DW.UnitDelay_DSTATE_c;

  // Product: '<S561>/Product1' incorporates:
  //   MATLAB Function: '<S561>/MATLAB Function'

  Aenea_model_B.olddi = 0.38271604938271603 * Aenea_model_B.Sum_l;

  // DataTypeConversion: '<S7>/Data Type Conversion1'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 9; Aenea_model_B.i++) {
    Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i] =
      Aenea_model_B.ByteReversal[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S7>/Data Type Conversion1'

  // Gain: '<S552>/Gain1'
  Aenea_model_B.checksum = 0.017453292519943295 *
    Aenea_model_B.DataTypeConversion1_c[6];

  // MATLAB Function: '<S417>/MATLAB Function1'
  guard1 = false;
  if (Aenea_model_DW.Memory2_PreviousInput_d[1] == 1) {
    // Switch: '<S38>/Switch' incorporates:
    //   Constant: '<S38>/Constant'

    if (Aenea_model_B.Switch_a != 0.0) {
      Aenea_model_B.a_b = 50.0;
    } else {
      Aenea_model_B.a_b = Aenea_model_B.olddi;
    }

    // End of Switch: '<S38>/Switch'
    if (Aenea_model_B.a_b > 40.0) {
      Aenea_model_DW.alarm = 1.0;
    } else if (std::abs(57.295779513082323 * Aenea_model_B.checksum) > 55.0) {
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

  // Outputs for Resettable SubSystem: '<S434>/Resettable Subsystem' incorporates:
  //   ResetPort: '<S437>/Reset'

  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &Aenea_model_PrevZCX.ResettableSubsystem_Reset_ZCE,
               (Aenea_model_DW.alarm)) != NO_ZCEVENT) {
    // InitializeConditions for Memory: '<S438>/Memory'
    Aenea_model_DW.Memory_PreviousInput_n = 0.0;
  }

  // Sum: '<S438>/Sum' incorporates:
  //   Constant: '<S438>/Constant4'
  //   Memory: '<S438>/Memory'

  Aenea_model_B.Sum_f = Aenea_model_DW.Memory_PreviousInput_n + 0.02;

  // Update for Memory: '<S438>/Memory' incorporates:
  //   Constant: '<S438>/Constant4'
  //   Sum: '<S438>/Sum'

  Aenea_model_DW.Memory_PreviousInput_n += 0.02;

  // End of Outputs for SubSystem: '<S434>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S434>/Enabled ' incorporates:
  //   EnablePort: '<S436>/Enable'

  // MATLAB Function: '<S417>/MATLAB Function1'
  if (Aenea_model_DW.alarm > 0.0) {
    Aenea_model_DW.Enabled_MODE = true;

    // Switch: '<S436>/Switch'
    Aenea_model_B.Switch_e = (Aenea_model_B.Sum_f > 1.0);
  } else {
    if (Aenea_model_DW.Enabled_MODE) {
      // Disable for Switch: '<S436>/Switch' incorporates:
      //   Outport: '<S436>/Alarm Safe'

      Aenea_model_B.Switch_e = 0.0;
      Aenea_model_DW.Enabled_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S434>/Enabled '

  // DataTypeConversion: '<S21>/Data Type Conversion2' incorporates:
  //   Constant: '<S21>/load uint16'

  Aenea_model_B.LVDE[0] = 10U;
  Aenea_model_B.LVDE[1] = Aenea_model_ConstB.Gain;

  // MATLAB Function: '<S3>/MATLAB Function1'
  Aenea_model_B.qY = 10U * z;
  if (Aenea_model_B.qY > 65535U) {
    Aenea_model_B.qY = 65535U;
  }

  // DataTypeConversion: '<S21>/Data Type Conversion2' incorporates:
  //   Constant: '<S21>/ '
  //   MATLAB Function: '<S3>/MATLAB Function1'

  Aenea_model_B.LVDE[2] = static_cast<uint16_T>(Aenea_model_B.qY);
  Aenea_model_B.LVDE[3] = Aenea_model_B.SFunction_o11[6];
  Aenea_model_B.LVDE[4] = Aenea_model_B.SFunction_o11[2];
  Aenea_model_B.LVDE[5] = 0U;

  // DataTypeConversion: '<S21>/Data Type Conversion4'
  Aenea_model_B.a_b = std::floor(Aenea_model_B.Switch_e);
  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S21>/Data Type Conversion2' incorporates:
  //   Constant: '<S38>/Constant2'
  //   DataTypeConversion: '<S21>/Data Type Conversion4'

  Aenea_model_B.LVDE[6] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));
  Aenea_model_B.LVDE[7] = 0U;

  // DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
  //   MATLAB Function: '<S16>/Alarm set'

  Aenea_model_B.DataTypeConversion1_f[2] =
    Aenea_model_DW.Memory1_PreviousInput_b[0];
  Aenea_model_B.DataTypeConversion1_f[3] =
    Aenea_model_DW.Memory1_PreviousInput_b[1];

  // MATLAB Function: '<S16>/Alarm set' incorporates:
  //   SignalConversion generated from: '<S26>/ SFunction '

  if (Aenea_model_B.Switch_e == 1.0) {
    // DataTypeConversion: '<S16>/Data Type Conversion1'
    Aenea_model_B.DataTypeConversion1_f[2] = 220U;
    Aenea_model_B.DataTypeConversion1_f[3] = 5U;
  }

  // DataTypeConversion: '<S16>/Data Type Conversion1'
  Aenea_model_B.DataTypeConversion1_f[0] = 1U;
  Aenea_model_B.DataTypeConversion1_f[1] = 0U;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // Gain: '<S17>/Gain'
    Aenea_model_B.e_d = 1000.0 *
      Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i];

    // DataTypeConversion: '<S17>/Data Type Conversion'
    if (Aenea_model_B.e_d < 0.0) {
      Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
    } else {
      Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
    }

    if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
      Aenea_model_B.a_b = 0.0;
    } else {
      Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
    }

    // DataTypeConversion: '<S17>/Data Type Conversion'
    Aenea_model_B.DataTypeConversion_j[Aenea_model_B.i] = static_cast<int16_T>
      (Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
         static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.a_b)))) :
       static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
         (Aenea_model_B.a_b))));
  }

  // DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
  //   Constant: '<S17>/Constant'
  //   Constant: '<S17>/Constant1'
  //   Constant: '<S17>/Constant2'
  //   Gain: '<S17>/Gain'

  Aenea_model_B.DataTypeConversion_j[6] = 0;
  Aenea_model_B.DataTypeConversion_j[7] = 0;
  Aenea_model_B.DataTypeConversion_j[8] = 0;

  // Gain: '<S553>/Gain1'
  Aenea_model_B.Sum_f = 0.017453292519943295 *
    Aenea_model_B.DataTypeConversion1_c[7];

  // Gain: '<S554>/Gain1'
  Aenea_model_B.Gain1_o = 0.017453292519943295 *
    Aenea_model_B.DataTypeConversion1_c[8];

  // DataTypeConversion: '<S17>/Data Type Conversion1'
  Aenea_model_B.DataTypeConversion1[0] = static_cast<real32_T>
    (Aenea_model_B.checksum);
  Aenea_model_B.DataTypeConversion1[1] = static_cast<real32_T>
    (Aenea_model_B.Sum_f);
  Aenea_model_B.DataTypeConversion1[2] = static_cast<real32_T>
    (Aenea_model_B.Gain1_o);
  Aenea_model_B.DataTypeConversion1[3] = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[3]);
  Aenea_model_B.DataTypeConversion1[4] = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[4]);
  Aenea_model_B.DataTypeConversion1[5] = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[5]);

  // Outputs for Enabled SubSystem: '<S574>/Subsystem2' incorporates:
  //   EnablePort: '<S585>/Enable'

  if (Aenea_model_B.SFunction_o14 > 0) {
    // Switch: '<S585>/Switch' incorporates:
    //   Constant: '<S585>/Constant'
    //   Constant: '<S585>/Constant1'
    //   Constant: '<S585>/Constant3'
    //   Constant: '<S585>/Constant4'
    //   Constant: '<S585>/Constant5'
    //   Constant: '<S585>/Constant6'
    //   Logic: '<S585>/OR'
    //   RelationalOperator: '<S585>/Equal'
    //   RelationalOperator: '<S585>/Equal1'
    //   RelationalOperator: '<S585>/Equal2'
    //   RelationalOperator: '<S585>/Equal3'
    //   RelationalOperator: '<S585>/Equal4'
    //   RelationalOperator: '<S585>/Equal5'

    if ((Aenea_model_B.SFunctionBuilder_o6 == 1.0) ||
        (Aenea_model_B.SFunctionBuilder_o6 == 2.0) ||
        (Aenea_model_B.SFunctionBuilder_o6 == 3.0) ||
        (Aenea_model_B.SFunctionBuilder_o6 == 4.0) ||
        (Aenea_model_B.SFunctionBuilder_o6 == 5.0) ||
        (Aenea_model_B.SFunctionBuilder_o6 == 6.0)) {
      // Switch: '<S585>/Switch'
      Aenea_model_B.Switch = Aenea_model_B.quota;
    } else {
      // Switch: '<S585>/Switch' incorporates:
      //   Constant: '<S585>/Constant2'

      Aenea_model_B.Switch = 0.0;
    }

    // End of Switch: '<S585>/Switch'
  }

  // End of Outputs for SubSystem: '<S574>/Subsystem2'

  // Switch: '<S574>/Switch' incorporates:
  //   Logic: '<S574>/AND'
  //   Sum: '<S574>/Sum1'
  //   Switch: '<S574>/Switch1'
  //   UnitDelay: '<S574>/Unit Delay'

  if (Aenea_model_B.SFunctionBuilder_o7 && (Aenea_model_B.SFunctionBuilder_o6 >
       2.0)) {
    Aenea_model_DW.UnitDelay_DSTATE_h[0] = Aenea_model_B.Lat;
    Aenea_model_DW.UnitDelay_DSTATE_h[1] = Aenea_model_B.Long;
    Aenea_model_DW.UnitDelay_DSTATE_h[2] = Aenea_model_B.V;
    Aenea_model_DW.UnitDelay_DSTATE_h[3] = Aenea_model_B.quota -
      Aenea_model_B.Switch;
    Aenea_model_DW.UnitDelay_DSTATE_h[4] = Aenea_model_B.heading;
  }

  // End of Switch: '<S574>/Switch'

  // Gain: '<S555>/Gain1' incorporates:
  //   UnitDelay: '<S574>/Unit Delay'

  Aenea_model_B.Gain1_i = 0.017453292519943295 *
    Aenea_model_DW.UnitDelay_DSTATE_h[0];

  // Gain: '<S556>/Gain1' incorporates:
  //   UnitDelay: '<S574>/Unit Delay'

  Aenea_model_B.Gain1_i0 = 0.017453292519943295 *
    Aenea_model_DW.UnitDelay_DSTATE_h[1];

  // Gain: '<S557>/Gain1' incorporates:
  //   UnitDelay: '<S574>/Unit Delay'

  Aenea_model_B.e_d = 0.017453292519943295 * Aenea_model_DW.UnitDelay_DSTATE_h[4];

  // Product: '<S6>/Multiply2' incorporates:
  //   Trigonometry: '<S6>/Cos2'
  //   UnitDelay: '<S574>/Unit Delay'

  Aenea_model_B.V_nord = std::cos(Aenea_model_B.e_d) *
    Aenea_model_DW.UnitDelay_DSTATE_h[2];

  // Trigonometry: '<S6>/Sin2'
  Aenea_model_B.e_d = std::sin(Aenea_model_B.e_d);

  // Product: '<S6>/Multiply3' incorporates:
  //   UnitDelay: '<S574>/Unit Delay'

  Aenea_model_B.V_est = Aenea_model_DW.UnitDelay_DSTATE_h[2] * Aenea_model_B.e_d;

  // Logic: '<S565>/NOT' incorporates:
  //   Memory: '<S565>/Memory'
  //   RelationalOperator: '<S565>/Equal'

  Aenea_model_B.NOT[5] = !(Aenea_model_B.checksum ==
    Aenea_model_DW.Memory_PreviousInput_e[5]);
  Aenea_model_B.NOT[6] = !(Aenea_model_B.Sum_f ==
    Aenea_model_DW.Memory_PreviousInput_e[6]);
  Aenea_model_B.NOT[7] = !(Aenea_model_B.Gain1_o ==
    Aenea_model_DW.Memory_PreviousInput_e[7]);
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    Aenea_model_B.NOT[Aenea_model_B.i + 8] =
      !(Aenea_model_DW.Memory_PreviousInput_e[Aenea_model_B.i + 8] ==
        Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i]);
  }

  // End of Logic: '<S565>/NOT'

  // MATLAB Function: '<S565>/MATLAB Function'
  rtb_y_n = (Aenea_model_B.NOT[5] || (Aenea_model_B.NOT[6] ||
              (Aenea_model_B.NOT[7] || (Aenea_model_B.NOT[8] ||
    (Aenea_model_B.NOT[9] || (Aenea_model_B.NOT[10] || (Aenea_model_B.NOT[11] ||
    Aenea_model_B.NOT[12])))))));

  // Logic: '<S564>/NOT' incorporates:
  //   Memory: '<S564>/Memory'
  //   RelationalOperator: '<S564>/Equal1'

  Aenea_model_B.NOT[3] = !(Aenea_model_B.V_nord ==
    Aenea_model_DW.Memory_PreviousInput_o[3]);
  Aenea_model_B.NOT[4] = !(Aenea_model_B.V_est ==
    Aenea_model_DW.Memory_PreviousInput_o[4]);

  // MATLAB Function: '<S564>/MATLAB Function1' incorporates:
  //   Logic: '<S564>/NOT'
  //   Memory: '<S564>/Memory'
  //   RelationalOperator: '<S564>/Equal1'

  rtb_y_c = ((!(Aenea_model_B.Gain1_i == Aenea_model_DW.Memory_PreviousInput_o[0]))
             || (!(Aenea_model_B.Gain1_i0 ==
                   Aenea_model_DW.Memory_PreviousInput_o[1])));

  // Switch: '<S560>/Switch1'
  Aenea_model_B.idx = (Aenea_model_B.SFunctionBuilder_o6 > 2.0);

  // Outputs for Enabled SubSystem: '<S6>/Filter2' incorporates:
  //   EnablePort: '<S559>/Enable'

  // SignalConversion generated from: '<S566>/ SFunction ' incorporates:
  //   DataTypeConversion: '<S578>/Data Type Conversion2'
  //   Inport: '<S559>/Misure'
  //   MATLAB Function: '<S560>/MATLAB Function2'

  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[0] = Aenea_model_B.Gain1_i;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[1] = Aenea_model_B.Gain1_i0;

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[2] =
    Aenea_model_B.SFunctionBuilder_o3_h;

  // End of Outputs for SubSystem: '<S571>/Execution_loop'
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[3] = Aenea_model_B.V_nord;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[4] = Aenea_model_B.V_est;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5] = Aenea_model_B.checksum;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6] = Aenea_model_B.Sum_f;
  Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7] = Aenea_model_B.Gain1_o;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // RelationalOperator: '<S564>/Equal1'
    Aenea_model_B.Alt = Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i];

    // Logic: '<S564>/NOT' incorporates:
    //   Memory: '<S564>/Memory'
    //   RelationalOperator: '<S564>/Equal1'

    Aenea_model_B.NOT[Aenea_model_B.i + 8] =
      !(Aenea_model_DW.Memory_PreviousInput_o[Aenea_model_B.i + 8] ==
        Aenea_model_B.Alt);

    // SignalConversion generated from: '<S566>/ SFunction ' incorporates:
    //   Inport: '<S559>/Misure'
    //   MATLAB Function: '<S560>/MATLAB Function2'

    Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[Aenea_model_B.i + 8] =
      Aenea_model_B.Alt;
  }

  // MATLAB Function: '<S560>/MATLAB Function2' incorporates:
  //   Constant: '<S560>/Constant'
  //   MATLAB Function: '<S559>/DEFINITIVA'
  //   SignalConversion generated from: '<S566>/ SFunction '

  Aenea_model_B.SwitchBumpless2 = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.e_d = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
  Aenea_model_B.Alt = std::sin(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]);
  Aenea_model_B.Saturation_o = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
  Aenea_model_B.Sum3 = std::sin(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Sum_fb = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k
    [6]);

  // End of Outputs for SubSystem: '<S6>/Filter2'
  Aenea_model_B.aterra_tmp[0] = Aenea_model_B.SwitchBumpless2 *
    Aenea_model_B.Sum_fb;
  Aenea_model_B.aterra_tmp[3] = Aenea_model_B.SwitchBumpless2 *
    Aenea_model_B.Saturation_o * Aenea_model_B.Alt - Aenea_model_B.e_d *
    Aenea_model_B.Sum3;
  Aenea_model_B.aterra_tmp[6] = Aenea_model_B.e_d *
    Aenea_model_B.SwitchBumpless2 * Aenea_model_B.Alt +
    Aenea_model_B.Saturation_o * Aenea_model_B.Sum3;
  Aenea_model_B.aterra_tmp[1] = Aenea_model_B.Sum3 * Aenea_model_B.Sum_fb;

  // Outputs for Enabled SubSystem: '<S6>/Filter2' incorporates:
  //   EnablePort: '<S559>/Enable'

  Aenea_model_B.Ato_selector = std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);

  // End of Outputs for SubSystem: '<S6>/Filter2'
  Aenea_model_B.aterra_tmp[4] = Aenea_model_B.Ato_selector * Aenea_model_B.Alt +
    std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);

  // Outputs for Enabled SubSystem: '<S6>/Filter2' incorporates:
  //   EnablePort: '<S559>/Enable'

  Aenea_model_B.Saturation_a = std::cos
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
    (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
  Aenea_model_B.Sum3_h = std::cos(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k
    [7]) * std::sin(Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);

  // End of Outputs for SubSystem: '<S6>/Filter2'
  Aenea_model_B.aterra_tmp[7] = Aenea_model_B.Saturation_a * Aenea_model_B.Alt -
    Aenea_model_B.Sum3_h;
  Aenea_model_B.aterra_tmp[2] = -Aenea_model_B.Alt;
  Aenea_model_B.aterra_tmp[5] = Aenea_model_B.Sum_fb *
    Aenea_model_B.Saturation_o;
  Aenea_model_B.aterra_tmp[8] = Aenea_model_B.e_d * Aenea_model_B.Sum_fb;
  Aenea_model_B.Alettoni_n = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[8];
  Aenea_model_B.Sum2_k2 = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[9];
  Aenea_model_B.e = Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[10];
  for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 3; Aenea_model_B.npad++) {
    Aenea_model_B.aterra[Aenea_model_B.npad] =
      Aenea_model_B.aterra_tmp[Aenea_model_B.npad + 6] * Aenea_model_B.e +
      (Aenea_model_B.aterra_tmp[Aenea_model_B.npad + 3] * Aenea_model_B.Sum2_k2
       + Aenea_model_B.aterra_tmp[Aenea_model_B.npad] * Aenea_model_B.Alettoni_n);
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

  // Outputs for Triggered SubSystem: '<S560>/Sample and Hold' incorporates:
  //   TriggerPort: '<S567>/Trigger'

  Aenea_model_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
    &Aenea_model_PrevZCX.SampleandHold_Trig_ZCE,
    (static_cast<real_T>(Aenea_model_B.idx)));
  if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
    // Inport: '<S567>/In'
    std::memcpy(&Aenea_model_B.In[0], &Aenea_model_B.y[0], 21U * sizeof(real_T));
  }

  // End of Outputs for SubSystem: '<S560>/Sample and Hold'

  // MATLAB Function: '<S564>/MATLAB Function'
  rtb_y_e = (Aenea_model_B.NOT[3] || Aenea_model_B.NOT[4]);

  // Outputs for Enabled SubSystem: '<S6>/Filter2' incorporates:
  //   EnablePort: '<S559>/Enable'

  if (Aenea_model_B.idx > 0) {
    // MATLAB Function: '<S559>/DEFINITIVA' incorporates:
    //   Constant: '<S6>/Constant13'
    //   Constant: '<S6>/Constant16'
    //   Inport: '<S559>/Misure'

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
    Aenea_model_B.H[102] = (Aenea_model_B.e_d * Aenea_model_B.SwitchBumpless2 *
      Aenea_model_B.Alt + Aenea_model_B.Saturation_o * Aenea_model_B.Sum3) * 0.0
      + (Aenea_model_B.e_d * Aenea_model_B.Sum3 - Aenea_model_B.SwitchBumpless2 *
         Aenea_model_B.Saturation_o * Aenea_model_B.Alt) * 0.0;
    Aenea_model_B.Alettoni_n = 0.0 * Aenea_model_B.SwitchBumpless2 *
      Aenea_model_B.Sum_fb;
    Aenea_model_B.Sum2_k2 = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) + std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]);
    Aenea_model_B.H[113] = Aenea_model_B.Alettoni_n - Aenea_model_B.Sum2_k2 *
      0.0;
    Aenea_model_B.H[124] = (Aenea_model_B.Saturation_a - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6])) * -0.0 -
      Aenea_model_B.Alettoni_n;
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
    Aenea_model_B.H[103] = (Aenea_model_B.Sum3_h - Aenea_model_B.Saturation_a *
      Aenea_model_B.Alt) * -0.0 - (Aenea_model_B.Ato_selector *
      Aenea_model_B.Alt + Aenea_model_B.Saturation_a) * 0.0;
    Aenea_model_B.Alettoni_n = 0.0 * Aenea_model_B.Sum_fb * Aenea_model_B.Sum3;
    Aenea_model_B.H[114] = (Aenea_model_B.Sum3_h - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6])) * 0.0 +
      Aenea_model_B.Alettoni_n;
    Aenea_model_B.H[125] = (std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) +
      Aenea_model_B.Saturation_a) * 0.0 - Aenea_model_B.Alettoni_n;
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
    Aenea_model_B.H[71] = Aenea_model_B.SwitchBumpless2 * Aenea_model_B.Sum_fb;
    Aenea_model_B.H[82] = Aenea_model_B.Sum_fb * Aenea_model_B.Sum3;
    Aenea_model_B.H[93] = -Aenea_model_B.Alt;
    Aenea_model_B.H[104] = Aenea_model_DW.x_prd[10] * 0.0 +
      Aenea_model_DW.x_prd[11] * 0.0;
    Aenea_model_B.Alettoni_n = 2.0 * Aenea_model_DW.x_prd[10] * 0.0;
    Aenea_model_B.H[115] = Aenea_model_DW.x_prd[9] * 0.0 -
      Aenea_model_B.Alettoni_n;
    Aenea_model_B.SwitchBumpless2 = 2.0 * Aenea_model_DW.x_prd[11] * 0.0;
    Aenea_model_B.H[126] = Aenea_model_DW.x_prd[9] * 0.0 -
      Aenea_model_B.SwitchBumpless2;
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
    Aenea_model_B.H[94] = Aenea_model_B.Sum_fb * Aenea_model_B.Saturation_o;
    Aenea_model_B.Saturation_o = 2.0 * Aenea_model_DW.x_prd[9] * 0.0;
    Aenea_model_B.H[105] = Aenea_model_DW.x_prd[10] * 0.0 -
      Aenea_model_B.Saturation_o;
    Aenea_model_B.H[116] = Aenea_model_DW.x_prd[9] * 0.0 + Aenea_model_DW.x_prd
      [11] * 0.0;
    Aenea_model_B.H[127] = Aenea_model_DW.x_prd[10] * 0.0 -
      Aenea_model_B.SwitchBumpless2;
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
    Aenea_model_B.H[73] = Aenea_model_B.Sum2_k2;
    Aenea_model_B.H[84] = std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[6]) - std::cos
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[7]) * std::sin
      (Aenea_model_B.rtb_TmpSignalConversionAtSFun_k[5]);
    Aenea_model_B.H[95] = Aenea_model_B.e_d * Aenea_model_B.Sum_fb;
    Aenea_model_B.H[106] = Aenea_model_DW.x_prd[11] * 0.0 -
      Aenea_model_B.Saturation_o;
    Aenea_model_B.H[117] = Aenea_model_DW.x_prd[11] * 0.0 -
      Aenea_model_B.Alettoni_n;
    Aenea_model_B.H[128] = Aenea_model_DW.x_prd[9] * 0.0 + Aenea_model_DW.x_prd
      [10] * 0.0;
    Aenea_model_B.H[139] = 0.0;
    Aenea_model_B.H[150] = 0.0;
    Aenea_model_B.H[161] = 1.0;
    Aenea_model_B.H[172] = 0.0;
    Aenea_model_B.H[183] = 0.0;
    Aenea_model_B.H[194] = 0.0;
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 18; Aenea_model_B.npad++)
    {
      Aenea_model_B.H[11 * Aenea_model_B.npad] = b[Aenea_model_B.npad];
      Aenea_model_B.H[11 * Aenea_model_B.npad + 1] = c_0[Aenea_model_B.npad];
      Aenea_model_B.H[11 * Aenea_model_B.npad + 2] = d[Aenea_model_B.npad];
      Aenea_model_B.H[11 * Aenea_model_B.npad + 8] = e[Aenea_model_B.npad];
      Aenea_model_B.H[11 * Aenea_model_B.npad + 9] = f[Aenea_model_B.npad];
      Aenea_model_B.H[11 * Aenea_model_B.npad + 10] = g[Aenea_model_B.npad];
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 11; Aenea_model_B.npad++)
    {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.idx = Aenea_model_B.npad + 11 * Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain_m[Aenea_model_B.idx] = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++)
        {
          Aenea_model_B.klm_gain_m[Aenea_model_B.idx] += Aenea_model_B.H[11 *
            Aenea_model_B.b_k + Aenea_model_B.npad] * Aenea_model_DW.p_prd[18 *
            Aenea_model_B.soglia_dist + Aenea_model_B.b_k];
        }
      }

      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 11;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.idx = Aenea_model_B.npad + 11 * Aenea_model_B.soglia_dist;
        Aenea_model_B.S[Aenea_model_B.idx] = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++)
        {
          Aenea_model_B.S[Aenea_model_B.idx] += Aenea_model_B.klm_gain_m[11 *
            Aenea_model_B.b_k + Aenea_model_B.npad] * Aenea_model_B.H[11 *
            Aenea_model_B.b_k + Aenea_model_B.soglia_dist];
        }
      }
    }

    Ap_sel = (rtb_y_c && rtb_y_e);
    if (Ap_sel && rtb_y_n) {
      for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11; Aenea_model_B.b_k++) {
        Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
        Aenea_model_B.S[Aenea_model_B.idx] +=
          Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
      }
    } else {
      tmp = !rtb_y_c;
      tmp_0 = (tmp && rtb_y_e);
      if (tmp_0 && rtb_y_n) {
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11; Aenea_model_B.b_k++)
        {
          if ((Aenea_model_B.b_k + 1 == 1) || (Aenea_model_B.b_k + 1 == 2)) {
            Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
            Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
          } else {
            Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
            Aenea_model_B.S[Aenea_model_B.idx] +=
              Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
          }
        }
      } else {
        rtb_y_e = !rtb_y_e;
        rtb_y_c = (rtb_y_c && rtb_y_e);
        if (rtb_y_c && rtb_y_n) {
          for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11; Aenea_model_B.b_k
               ++) {
            if ((Aenea_model_B.b_k + 1 == 4) || (Aenea_model_B.b_k + 1 == 5)) {
              Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
              Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
            } else {
              Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
              Aenea_model_B.S[Aenea_model_B.idx] +=
                Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
            }
          }
        } else {
          tmp = (tmp && rtb_y_e);
          if (tmp && rtb_y_n) {
            for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11;
                 Aenea_model_B.b_k++) {
              if ((Aenea_model_B.b_k + 1 == 1) || (Aenea_model_B.b_k + 1 == 2) ||
                  (Aenea_model_B.b_k + 1 == 4) || (Aenea_model_B.b_k + 1 == 5))
              {
                Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
              } else {
                Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                Aenea_model_B.S[Aenea_model_B.idx] +=
                  Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
              }
            }
          } else {
            rtb_y_e = !rtb_y_n;
            if (Ap_sel && rtb_y_e) {
              for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11;
                   Aenea_model_B.b_k++) {
                if ((Aenea_model_B.b_k + 1 == 1) || (Aenea_model_B.b_k + 1 == 2)
                    || (Aenea_model_B.b_k + 1 == 4) || (Aenea_model_B.b_k + 1 ==
                     5) || (Aenea_model_B.b_k + 1 == 3)) {
                  Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                  Aenea_model_B.S[Aenea_model_B.idx] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
                } else {
                  Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                  Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
                }
              }
            } else if (tmp_0 && rtb_y_e) {
              for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11;
                   Aenea_model_B.b_k++) {
                if ((Aenea_model_B.b_k + 1 == 4) || (Aenea_model_B.b_k + 1 == 5)
                    || (Aenea_model_B.b_k + 1 == 3)) {
                  Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                  Aenea_model_B.S[Aenea_model_B.idx] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
                } else {
                  Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                  Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
                }
              }
            } else if (rtb_y_c && rtb_y_e) {
              for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11;
                   Aenea_model_B.b_k++) {
                if ((Aenea_model_B.b_k + 1 == 1) || (Aenea_model_B.b_k + 1 == 2)
                    || (Aenea_model_B.b_k + 1 == 3)) {
                  Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                  Aenea_model_B.S[Aenea_model_B.idx] +=
                    Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
                } else {
                  Aenea_model_B.idx = 11 * Aenea_model_B.b_k + Aenea_model_B.b_k;
                  Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
                }
              }
            } else {
              if (tmp && rtb_y_e) {
                for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11;
                     Aenea_model_B.b_k++) {
                  if (Aenea_model_B.b_k + 1 == 3) {
                    Aenea_model_B.idx = 11 * Aenea_model_B.b_k +
                      Aenea_model_B.b_k;
                    Aenea_model_B.S[Aenea_model_B.idx] +=
                      Aenea_model_ConstP.Constant13_Value[Aenea_model_B.b_k];
                  } else {
                    Aenea_model_B.idx = 11 * Aenea_model_B.b_k +
                      Aenea_model_B.b_k;
                    Aenea_model_B.S[Aenea_model_B.idx] += 1.0E+40;
                  }
                }
              }
            }
          }
        }
      }
    }

    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 11; Aenea_model_B.npad++)
    {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.idx = Aenea_model_B.npad + 11 * Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain_m[Aenea_model_B.idx] = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++)
        {
          Aenea_model_B.klm_gain_m[Aenea_model_B.idx] += Aenea_model_B.H[11 *
            Aenea_model_B.b_k + Aenea_model_B.npad] * Aenea_model_DW.p_prd[18 *
            Aenea_model_B.b_k + Aenea_model_B.soglia_dist];
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
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 11; Aenea_model_B.npad++)
    {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.klm_gain_m[Aenea_model_B.soglia_dist + 18 *
          Aenea_model_B.npad] = Aenea_model_B.ab[11 * Aenea_model_B.soglia_dist
          + Aenea_model_B.npad];
      }

      Aenea_model_B.residui[Aenea_model_B.npad] -=
        Aenea_model_B.dv1[Aenea_model_B.npad];
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
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 18; Aenea_model_B.npad++)
    {
      Aenea_model_B.klm_gain_c[Aenea_model_B.npad] = 0.0;
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 11;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.klm_gain_c[Aenea_model_B.npad] +=
          Aenea_model_B.klm_gain_m[18 * Aenea_model_B.soglia_dist +
          Aenea_model_B.npad] * Aenea_model_B.residui[Aenea_model_B.soglia_dist];
      }

      Aenea_model_B.x_est[Aenea_model_B.npad] =
        Aenea_model_DW.x_prd[Aenea_model_B.npad] +
        Aenea_model_B.klm_gain_c[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 2] = h[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 3] = j[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 4] = l[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 5] = m[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 6] = n[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 7] = o[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 8] = p[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 9] = q[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 10] = r[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 11] = s[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 12] = t[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 13] = u[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 14] = v[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 15] = w[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 16] = x_0[Aenea_model_B.npad];
      Aenea_model_B.F[18 * Aenea_model_B.npad + 17] = y[Aenea_model_B.npad];
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.idx = Aenea_model_B.npad + 18 * Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain[Aenea_model_B.idx] = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 11; Aenea_model_B.b_k++)
        {
          Aenea_model_B.klm_gain[Aenea_model_B.idx] += Aenea_model_B.klm_gain_m
            [18 * Aenea_model_B.b_k + Aenea_model_B.npad] * Aenea_model_B.H[11 *
            Aenea_model_B.soglia_dist + Aenea_model_B.b_k];
        }
      }

      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.a_b = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++)
        {
          Aenea_model_B.a_b += Aenea_model_B.klm_gain[18 * Aenea_model_B.b_k +
            Aenea_model_B.npad] * Aenea_model_DW.p_prd[18 *
            Aenea_model_B.soglia_dist + Aenea_model_B.b_k];
        }

        Aenea_model_B.b_k = 18 * Aenea_model_B.soglia_dist + Aenea_model_B.npad;
        Aenea_model_B.dv[Aenea_model_B.b_k] =
          Aenea_model_DW.p_prd[Aenea_model_B.b_k] - Aenea_model_B.a_b;
      }
    }

    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.x_est[0]);
    Aenea_model_B.e_d = (Aenea_model_B.x_est[2] + 6.378137E+6) *
      (Aenea_model_B.x_est[2] + 6.378137E+6);
    Aenea_model_B.F[36] = -(0.02 * Aenea_model_B.x_est[3]) / Aenea_model_B.e_d;
    Aenea_model_B.F[54] = 0.02 / (Aenea_model_B.x_est[2] + 6.378137E+6);
    Aenea_model_B.F[1] = 0.02 * Aenea_model_B.x_est[4] * std::sin
      (Aenea_model_B.x_est[0]) / (Aenea_model_B.Switch_j *
      Aenea_model_B.Switch_j * (Aenea_model_B.x_est[2] + 6.378137E+6));
    Aenea_model_B.F[37] = -(0.02 * Aenea_model_B.x_est[4]) / (Aenea_model_B.e_d *
      Aenea_model_B.Switch_j);
    Aenea_model_B.F[73] = 0.02 / ((Aenea_model_B.x_est[2] + 6.378137E+6) *
      Aenea_model_B.Switch_j);
    Aenea_model_f_pred_F1B(Aenea_model_B.x_est, 6.378137E+6, 0.02,
      Aenea_model_DW.x_prd);
    for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 18; Aenea_model_B.npad++)
    {
      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.idx = Aenea_model_B.npad + 18 * Aenea_model_B.soglia_dist;
        Aenea_model_B.klm_gain[Aenea_model_B.idx] = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++)
        {
          Aenea_model_B.klm_gain[Aenea_model_B.idx] += Aenea_model_B.F[18 *
            Aenea_model_B.b_k + Aenea_model_B.npad] * Aenea_model_B.dv[18 *
            Aenea_model_B.soglia_dist + Aenea_model_B.b_k];
        }
      }

      for (Aenea_model_B.soglia_dist = 0; Aenea_model_B.soglia_dist < 18;
           Aenea_model_B.soglia_dist++) {
        Aenea_model_B.idx = Aenea_model_B.npad + 18 * Aenea_model_B.soglia_dist;
        Aenea_model_DW.p_prd[Aenea_model_B.idx] = 0.0;
        for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++)
        {
          Aenea_model_DW.p_prd[Aenea_model_B.idx] += Aenea_model_B.klm_gain[18 *
            Aenea_model_B.b_k + Aenea_model_B.npad] * Aenea_model_B.F[18 *
            Aenea_model_B.b_k + Aenea_model_B.soglia_dist];
        }
      }
    }

    for (Aenea_model_B.b_k = 0; Aenea_model_B.b_k < 18; Aenea_model_B.b_k++) {
      Aenea_model_B.idx = 18 * Aenea_model_B.b_k + Aenea_model_B.b_k;
      Aenea_model_DW.p_prd[Aenea_model_B.idx] +=
        Aenea_model_ConstP.Constant16_Value[Aenea_model_B.b_k];
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

  // End of Outputs for SubSystem: '<S6>/Filter2'

  // Switch: '<S6>/Switch' incorporates:
  //   DataTypeConversion: '<S578>/Data Type Conversion2'

  if (Aenea_model_B.SFunctionBuilder_o6 > 2.0) {
    Aenea_model_B.Alt = Aenea_model_B.h_K;
  } else {
    // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
    Aenea_model_B.Alt = Aenea_model_B.SFunctionBuilder_o3_h;

    // End of Outputs for SubSystem: '<S571>/Execution_loop'
  }

  // End of Switch: '<S6>/Switch'

  // Gain: '<S15>/Gain' incorporates:
  //   Gain: '<S24>/Gain'

  Aenea_model_B.e_d = 57.295779513082323 * Aenea_model_B.Lat_K * 1.0E+7;

  // DataTypeConversion: '<S15>/Data Type Conversion'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S15>/Data Type Conversion'
  Aenea_model_B.DataTypeConversion_g[0] = Aenea_model_B.a_b < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b)) :
    static_cast<int32_T>(static_cast<uint32_T>(Aenea_model_B.a_b));

  // Gain: '<S15>/Gain' incorporates:
  //   Gain: '<S25>/Gain'

  Aenea_model_B.e_d = 57.295779513082323 * Aenea_model_B.Long_K * 1.0E+7;

  // DataTypeConversion: '<S15>/Data Type Conversion'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S15>/Data Type Conversion'
  Aenea_model_B.DataTypeConversion_g[1] = Aenea_model_B.a_b < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b)) :
    static_cast<int32_T>(static_cast<uint32_T>(Aenea_model_B.a_b));

  // Gain: '<S15>/Gain'
  Aenea_model_B.e_d = 1000.0 * Aenea_model_B.Alt;

  // DataTypeConversion: '<S15>/Data Type Conversion'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 4.294967296E+9);
  }

  // DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
  //   Constant: '<S15>/alt_r'
  //   Gain: '<S15>/Gain'

  Aenea_model_B.DataTypeConversion_g[2] = Aenea_model_B.a_b < 0.0 ? -
    static_cast<int32_T>(static_cast<uint32_T>(-Aenea_model_B.a_b)) :
    static_cast<int32_T>(static_cast<uint32_T>(Aenea_model_B.a_b));
  Aenea_model_B.DataTypeConversion_g[3] = 0;

  // Gain: '<S15>/Gain1'
  Aenea_model_B.e_d = 1000.0 * Aenea_model_B.v_K;

  // DataTypeConversion: '<S15>/Data Type Conversion1'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
  //   Constant: '<S15>/vel y'
  //   Gain: '<S15>/Gain1'

  Aenea_model_B.DataTypeConversion1_j[0] = static_cast<int16_T>
    (Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.a_b)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.a_b))));
  Aenea_model_B.DataTypeConversion1_j[1] = 0;

  // Gain: '<S15>/Gain1'
  Aenea_model_B.e_d = 1000.0 * Aenea_model_B.vd_K;

  // DataTypeConversion: '<S15>/Data Type Conversion1'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S15>/Data Type Conversion1'
  Aenea_model_B.DataTypeConversion1_j[2] = static_cast<int16_T>
    (Aenea_model_B.a_b < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.a_b)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.a_b))));

  // Gain: '<S15>/Gain2'
  Aenea_model_B.e_d = 100.0 * Aenea_model_B.imbardata;

  // DataTypeConversion: '<S15>/Data Type Conversion2'
  if (Aenea_model_B.e_d < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.e_d);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.e_d);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S15>/Data Type Conversion2'
  Aenea_model_B.DataTypeConversion2_p = static_cast<uint16_T>(Aenea_model_B.a_b <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
  //   Constant: '<S22>/airspeed groundspeed alt climb1'

  Aenea_model_B.AGAC[0] = static_cast<real32_T>(Aenea_model_B.olddi);
  Aenea_model_B.AGAC[1] = 0.0F;
  Aenea_model_B.AGAC[2] = static_cast<real32_T>(Aenea_model_B.Alt);
  Aenea_model_B.AGAC[3] = static_cast<real32_T>(Aenea_model_B.vd_K);

  // Gain: '<S33>/Gain'
  Aenea_model_B.Gain_h = 57.295779513082323 * Aenea_model_B.imbardata;

  // Switch: '<S34>/Switch2' incorporates:
  //   Abs: '<S34>/Abs'
  //   Constant: '<S34>/Constant2'
  //   Sum: '<S34>/Sum'

  if (!(Aenea_model_B.Gain_h > 0.0)) {
    Aenea_model_B.Gain_h = 360.0 - std::abs(Aenea_model_B.Gain_h);
  }

  // End of Switch: '<S34>/Switch2'

  // DataTypeConversion: '<S22>/Data Type Conversion1'
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

  // DataTypeConversion: '<S22>/Data Type Conversion1'
  Aenea_model_B.Heading_f = static_cast<int16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(static_cast<
    uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(static_cast<int16_T>
    (static_cast<uint16_T>(Aenea_model_B.a_b))));

  // Gain: '<S29>/Gain2' incorporates:
  //   Product: '<S592>/Multiply1'

  Aenea_model_B.Gain_h = 100.0 * Aenea_model_ConstB.Divide2;
  if (Aenea_model_M->Timing.TaskCounters.TID[2] == 0) {
    // RelationalOperator: '<S572>/Compare' incorporates:
    //   Constant: '<S572>/Constant'
    //   UnitDelay: '<S573>/Output'

    Aenea_model_B.Compare = (Aenea_model_DW.Output_DSTATE == 1);

    // S-Function (blink_sfun): '<S7>/S-Function Builder'
    blink_sfun_Outputs_wrapper(&Aenea_model_B.Compare);
  }

  // Chart: '<S38>/ STATI' incorporates:
  //   MATLAB Function: '<S3>/MATLAB Function1'

  if (Aenea_model_DW.is_active_c26_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c26_Aenea_model = 1U;
    Aenea_model_DW.is_c26_Aenea_model = Aenea_model_IN_MANUALE;
  } else {
    switch (Aenea_model_DW.is_c26_Aenea_model) {
     case Aenea_model_IN_AUTOMATICA:
      if (Aenea_model_B.Switch_e == 1.0) {
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
              (Aenea_model_B.Alt > 20.0) &&
              (Aenea_model_DW.Memory2_PreviousInput_d[6] == 1)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_WAYPOINT;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[8] == 0) &&
                     (Aenea_model_B.Alt > 20.0)) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[7] == 1) &&
                     (Aenea_model_DW.Memory2_PreviousInput_d[8] == 0) &&
                     (Aenea_model_B.Alt < 1.0) && (Aenea_model_B.v_K < 1.0)) {
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
              (Aenea_model_B.olddi >= 1.0) &&
              ((Aenea_model_DW.Memory2_PreviousInput_d[3] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[4] == 1) ||
               (Aenea_model_DW.Memory2_PreviousInput_d[2] == 1))) {
            Aenea_model_DW.is_AUTOMATICA = Aenea_model_IN_VETTORIALE;
          } else if ((Aenea_model_DW.Memory2_PreviousInput_d[6] == 1) &&
                     (Aenea_model_B.Alt > 30.0)) {
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
      } else if (Aenea_model_B.Switch_e == 1.0) {
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
      if ((Aenea_model_ConstB.Go_Home == 1.0) && (Aenea_model_B.Switch_e == 0.0))
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

  // End of Chart: '<S38>/ STATI'

  // Sum: '<S589>/Sum3' incorporates:
  //   Constant: '<S589>/Constant8'
  //   Constant: '<S589>/Constant9'
  //   Product: '<S589>/Multiply'
  //   Sum: '<S589>/Sum2'

  Aenea_model_B.Sum3 = Aenea_model_ConstB.Divide * 0.87266462599716477 +
    -0.55850536063818546;

  // MATLAB Function: '<S38>/MATLAB Function'
  if (Aenea_model_B.modo == 3.0) {
    Aenea_model_B.idx = 1;
    Aenea_model_B.b_k = 0;
  } else if (Aenea_model_B.modo == 4.0) {
    Aenea_model_B.b_k = 1;
    Aenea_model_B.idx = 0;
  } else {
    Aenea_model_B.idx = 0;
    Aenea_model_B.b_k = 0;
  }

  // Sum: '<S590>/Sum3' incorporates:
  //   Constant: '<S590>/Constant8'
  //   Constant: '<S590>/Constant9'
  //   Product: '<S590>/Multiply'
  //   Sum: '<S590>/Sum2'

  Aenea_model_B.Ato_selector = Aenea_model_ConstB.Divide_k * 0.52359877559829882
    + -0.26179938779914941;

  // Saturate: '<S590>/Saturation'
  if (Aenea_model_B.Ato_selector > 0.26179938779914941) {
    Aenea_model_B.Ato_selector = 0.26179938779914941;
  } else {
    if (Aenea_model_B.Ato_selector < -0.26179938779914941) {
      Aenea_model_B.Ato_selector = -0.26179938779914941;
    }
  }

  // End of Saturate: '<S590>/Saturation'

  // Sum: '<S37>/Sum2'
  Aenea_model_B.e_d = Aenea_model_B.Ato_selector - Aenea_model_B.Sum_f;

  // Sum: '<S351>/Sum' incorporates:
  //   DiscreteIntegrator: '<S342>/Integrator'
  //   Product: '<S347>/PProd Out'

  Aenea_model_B.Sum_fb = Aenea_model_B.e_d * -1.9179999828338623 +
    Aenea_model_DW.Integrator_DSTATE;

  // Saturate: '<S349>/Saturation'
  if (Aenea_model_B.Sum_fb > 0.31415926535897931) {
    Aenea_model_B.Saturation_o = 0.31415926535897931;
  } else if (Aenea_model_B.Sum_fb < -0.55850536063818546) {
    Aenea_model_B.Saturation_o = -0.55850536063818546;
  } else {
    Aenea_model_B.Saturation_o = Aenea_model_B.Sum_fb;
  }

  // End of Saturate: '<S349>/Saturation'

  // MultiPortSwitch: '<S304>/Switch Bumpless 2'
  if (static_cast<int32_T>(Aenea_model_B.switch_equilibratore) == 0) {
    Aenea_model_B.SwitchBumpless2 = Aenea_model_B.Sum3;
  } else {
    Aenea_model_B.SwitchBumpless2 = Aenea_model_B.Saturation_o;
  }

  // End of MultiPortSwitch: '<S304>/Switch Bumpless 2'

  // MultiPortSwitch: '<S309>/Multiport Switch2' incorporates:
  //   MATLAB Function: '<S38>/MATLAB Function'

  if (Aenea_model_B.b_k != 0) {
    // Switch: '<S309>/Switch1' incorporates:
    //   Constant: '<S309>/Constant5'

    if (!(Aenea_model_B.olddi >= 16.0)) {
      Aenea_model_B.SwitchBumpless2 = 0.0;
    }

    // End of Switch: '<S309>/Switch1'
  }

  // End of MultiPortSwitch: '<S309>/Multiport Switch2'

  // Logic: '<S39>/AND'
  Ap_sel = ((Aenea_model_B.switch_manetta != 0.0) &&
            (Aenea_model_B.switch_equilibratore != 0.0) &&
            (Aenea_model_B.switch_alettoni != 0.0) &&
            (Aenea_model_B.switch_timone != 0.0));

  // Chart: '<S39>/Chart' incorporates:
  //   Logic: '<S39>/AND'

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

  // End of Chart: '<S39>/Chart'

  // Outputs for Enabled SubSystem: '<S39>/DECOLLO AUTOMATICO' incorporates:
  //   EnablePort: '<S440>/Enable'

  if (Aenea_model_B.Ato_selector > 0.0) {
    // Outputs for Triggered SubSystem: '<S440>/Sample and Hold' incorporates:
    //   TriggerPort: '<S448>/Trigger'

    // Memory: '<S440>/Memory'
    rt_ZCFcn(RISING_ZERO_CROSSING,&Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_a,
             (Aenea_model_DW.Memory_PreviousInput_p));

    // End of Outputs for SubSystem: '<S440>/Sample and Hold'

    // Outputs for Triggered SubSystem: '<S440>/Sample and Hold1' incorporates:
    //   TriggerPort: '<S449>/Trigger'

    // Memory: '<S440>/Memory1'
    rt_ZCFcn(RISING_ZERO_CROSSING,&Aenea_model_PrevZCX.SampleandHold1_Trig_ZCE,
             (Aenea_model_DW.Memory1_PreviousInput_e));

    // End of Outputs for SubSystem: '<S440>/Sample and Hold1'

    // Chart: '<S440>/Chart1'
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
        if ((Aenea_model_B.olddi >= 18.0) && (Aenea_model_B.v_K >= 10.0)) {
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
        if (Aenea_model_B.Alt >= 2.0) {
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

    // End of Chart: '<S440>/Chart1'

    // Update for Memory: '<S440>/Memory'
    Aenea_model_DW.Memory_PreviousInput_p = Aenea_model_B.psi_ref_selector;

    // Update for Memory: '<S440>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput_e = Aenea_model_B.theta_ground_selector;
  }

  // End of Outputs for SubSystem: '<S39>/DECOLLO AUTOMATICO'

  // MultiPortSwitch: '<S310>/Multiport Switch2' incorporates:
  //   MATLAB Function: '<S38>/MATLAB Function'

  if (Aenea_model_B.idx != 0) {
    // MultiPortSwitch: '<S310>/Multiport Switch1' incorporates:
    //   Gain: '<S359>/Gain1'

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

    // End of MultiPortSwitch: '<S310>/Multiport Switch1'
  }

  // End of MultiPortSwitch: '<S310>/Multiport Switch2'

  // MultiPortSwitch: '<S37>/Switch Bumpless 1'
  if (static_cast<int32_T>(Aenea_model_B.switch_equilibratore) != 0) {
    // MultiPortSwitch: '<S304>/Switch 1' incorporates:
    //   Abs: '<S304>/Abs1'
    //   Constant: '<S304>/Constant1'
    //   Constant: '<S304>/Constant2'
    //   Constant: '<S304>/Constant3'
    //   Gain: '<S304>/Gain'
    //   MultiPortSwitch: '<S304>/Switch  2'
    //   Product: '<S304>/Product3'
    //   Product: '<S304>/Product4'
    //   Product: '<S304>/Product5'
    //   Sum: '<S304>/Sum3'
    //   Trigonometry: '<S304>/Trigonometric Function'

    if (static_cast<int32_T>(Aenea_model_B.switch_equilibratore) == 0) {
      Aenea_model_B.e = 0.0;
      Aenea_model_B.a_b = 0.0;
    } else {
      // Abs: '<S304>/Abs1' incorporates:
      //   Abs: '<S304>/Abs'

      Aenea_model_B.a_b = std::abs(Aenea_model_B.checksum);
      Aenea_model_B.e = (Aenea_model_B.DataTypeConversion1_c[4] - std::sin
                         (Aenea_model_B.a_b) *
                         Aenea_model_B.DataTypeConversion1_c[5]) * -0.125;
      Aenea_model_B.a_b *= -0.525;
    }

    // End of MultiPortSwitch: '<S304>/Switch 1'

    // Sum: '<S304>/Sum2' incorporates:
    //   Sum: '<S304>/Sum'

    Aenea_model_B.Sum3 = (Aenea_model_B.SwitchBumpless2 - Aenea_model_B.e) -
      Aenea_model_B.a_b;

    // Saturate: '<S304>/saturatore E2'
    if (Aenea_model_B.Sum3 > 0.31415926535897931) {
      Aenea_model_B.Sum3 = 0.31415926535897931;
    } else {
      if (Aenea_model_B.Sum3 < -0.55850536063818546) {
        Aenea_model_B.Sum3 = -0.55850536063818546;
      }
    }

    // End of Saturate: '<S304>/saturatore E2'
  }

  // End of MultiPortSwitch: '<S37>/Switch Bumpless 1'

  // Sum: '<S29>/Sum' incorporates:
  //   Constant: '<S29>/Constant2'
  //   Gain: '<S30>/Gain'

  Aenea_model_B.Abs1_l = 57.295779513082323 * Aenea_model_B.Sum3 + 90.0;

  // Sum: '<S587>/Sum3' incorporates:
  //   Constant: '<S587>/Constant8'
  //   Constant: '<S587>/Constant9'
  //   Product: '<S587>/Multiply'
  //   Sum: '<S587>/Sum2'

  Aenea_model_B.Sum3_h = Aenea_model_ConstB.Divide_d * 0.87266462599716477 +
    -0.4014257279586958;

  // Gain: '<S588>/Gain' incorporates:
  //   Constant: '<S588>/Constant8'
  //   Constant: '<S588>/Constant9'
  //   Product: '<S588>/Multiply'
  //   Sum: '<S588>/Sum2'
  //   Sum: '<S588>/Sum3'

  Aenea_model_B.Ato_selector = -(Aenea_model_ConstB.Divide_g *
    1.0471975511965976 + -0.52359877559829882);

  // Saturate: '<S588>/Saturation'
  if (Aenea_model_B.Ato_selector > 0.52359877559829882) {
    Aenea_model_B.Ato_selector = 0.52359877559829882;
  } else {
    if (Aenea_model_B.Ato_selector < -0.52359877559829882) {
      Aenea_model_B.Ato_selector = -0.52359877559829882;
    }
  }

  // End of Saturate: '<S588>/Saturation'

  // Sum: '<S37>/Sum5'
  Aenea_model_B.e = Aenea_model_B.Ato_selector - Aenea_model_B.checksum;

  // DiscreteIntegrator: '<S392>/Integrator' incorporates:
  //   Constant: '<S305>/Constant3'
  //   Sum: '<S305>/Sum'

  if ((Aenea_model_B.Fase_ATO - 2.0 > 0.0) &&
      (Aenea_model_DW.Integrator_PrevResetState <= 0)) {
    Aenea_model_DW.Integrator_DSTATE_l = 0.0;
  }

  // Sum: '<S401>/Sum' incorporates:
  //   DiscreteIntegrator: '<S392>/Integrator'
  //   Product: '<S397>/PProd Out'

  Aenea_model_B.Ato_selector = Aenea_model_B.e * 1.1000000238418579 +
    Aenea_model_DW.Integrator_DSTATE_l;

  // Saturate: '<S399>/Saturation'
  if (Aenea_model_B.Ato_selector > 0.47123889803846897) {
    Aenea_model_B.Saturation_a = 0.47123889803846897;
  } else if (Aenea_model_B.Ato_selector < -0.4014257279586958) {
    Aenea_model_B.Saturation_a = -0.4014257279586958;
  } else {
    Aenea_model_B.Saturation_a = Aenea_model_B.Ato_selector;
  }

  // End of Saturate: '<S399>/Saturation'

  // MultiPortSwitch: '<S305>/Switch Bumpless 1' incorporates:
  //   Constant: '<S305>/Constant1'
  //   Product: '<S305>/Product3'

  if (static_cast<int32_T>(Aenea_model_B.switch_alettoni) == 0) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = Aenea_model_B.DataTypeConversion1_c[3] * 0.125;
  }

  // End of MultiPortSwitch: '<S305>/Switch Bumpless 1'

  // Sum: '<S305>/Sum2'
  Aenea_model_B.Sum2_k2 = Aenea_model_B.Saturation_a - Aenea_model_B.a_b;

  // MultiPortSwitch: '<S37>/Switch Bumpless 3' incorporates:
  //   Saturate: '<S37>/saturatore A1'

  if (static_cast<int32_T>(Aenea_model_B.switch_alettoni) == 0) {
    Aenea_model_B.Alettoni_n = Aenea_model_B.Sum3_h;
  } else if (Aenea_model_B.Sum2_k2 > 0.47123889803846897) {
    // Saturate: '<S37>/saturatore A1'
    Aenea_model_B.Alettoni_n = 0.47123889803846897;
  } else if (Aenea_model_B.Sum2_k2 < -0.4014257279586958) {
    // Saturate: '<S37>/saturatore A1'
    Aenea_model_B.Alettoni_n = -0.4014257279586958;
  } else {
    // Saturate: '<S37>/saturatore A1'
    Aenea_model_B.Alettoni_n = Aenea_model_B.Sum2_k2;
  }

  // End of MultiPortSwitch: '<S37>/Switch Bumpless 3'

  // Saturate: '<S37>/saturatore A'
  if (Aenea_model_B.Alettoni_n > 0.47123889803846897) {
    Aenea_model_B.Alettoni = 0.47123889803846897;
  } else if (Aenea_model_B.Alettoni_n < -0.4014257279586958) {
    Aenea_model_B.Alettoni = -0.4014257279586958;
  } else {
    Aenea_model_B.Alettoni = Aenea_model_B.Alettoni_n;
  }

  // End of Saturate: '<S37>/saturatore A'

  // MultiPortSwitch: '<S37>/Switch Bumpless 5' incorporates:
  //   Gain: '<S37>/Gain1'

  if (static_cast<int32_T>(Aenea_model_B.switch_alettoni) == 0) {
    Aenea_model_B.Alettoni_n = Aenea_model_B.Sum3_h;
  } else {
    Aenea_model_B.Alettoni_n = -Aenea_model_B.Alettoni;
  }

  // End of MultiPortSwitch: '<S37>/Switch Bumpless 5'

  // Sum: '<S29>/Sum1' incorporates:
  //   Constant: '<S29>/Constant2'
  //   Gain: '<S31>/Gain'

  Aenea_model_B.Switch_j = 57.295779513082323 * Aenea_model_B.Alettoni_n + 90.0;

  // DiscreteTransferFcn: '<S306>/Discrete Washout Filter'
  Aenea_model_B.Sum3_h = Aenea_model_B.DataTypeConversion1_c[5] - -0.995 *
    Aenea_model_DW.DiscreteWashoutFilter_states;

  // MultiPortSwitch: '<S37>/Switch Bumpless 6' incorporates:
  //   Constant: '<S591>/Constant8'
  //   Constant: '<S591>/Constant9'
  //   MultiPortSwitch: '<S37>/Switch Bumpless 4'
  //   Product: '<S591>/Multiply'
  //   Sum: '<S591>/Sum3'
  //   Sum: '<S591>/Sum4'

  if (static_cast<int32_T>(Aenea_model_B.switch_timone) == 0) {
    Aenea_model_B.Sum2_k2 = Aenea_model_ConstB.Divide_p * 1.0471975511965976 +
      -0.52359877559829882;
  } else {
    if (static_cast<int32_T>(Aenea_model_B.switch_timone) == 0) {
      // MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
      //   Constant: '<S591>/Constant8'
      //   Constant: '<S591>/Constant9'
      //   Product: '<S591>/Multiply'
      //   Sum: '<S591>/Sum3'
      //   Sum: '<S591>/Sum4'

      Aenea_model_B.Sum2_k2 = Aenea_model_ConstB.Divide_p * 1.0471975511965976 +
        -0.52359877559829882;
    } else {
      // MultiPortSwitch: '<S37>/Switch Bumpless 4' incorporates:
      //   Constant: '<S37>/r_rif'
      //   DiscreteTransferFcn: '<S306>/Discrete Washout Filter'
      //   Gain: '<S8>/Gain3'
      //   Product: '<S37>/  CONTROLLO     IMBARDATA      INVERSA'
      //   Product: '<S37>/Product'
      //   Sum: '<S37>/Sum1'
      //   Sum: '<S37>/Sum9'

      Aenea_model_B.Sum2_k2 = (0.0 - (Aenea_model_B.Sum3_h +
        -Aenea_model_DW.DiscreteWashoutFilter_states)) * -0.40000000596046448 +
        static_cast<real_T>(Aenea_model_ConstB.K_imb_inv) * 0.0078125 *
        Aenea_model_B.Sum2_k2;
    }

    // Saturate: '<S37>/saturatore R'
    if (Aenea_model_B.Sum2_k2 > 0.52359877559829882) {
      Aenea_model_B.Sum2_k2 = 0.52359877559829882;
    } else {
      if (Aenea_model_B.Sum2_k2 < -0.52359877559829882) {
        Aenea_model_B.Sum2_k2 = -0.52359877559829882;
      }
    }

    // End of Saturate: '<S37>/saturatore R'
  }

  // End of MultiPortSwitch: '<S37>/Switch Bumpless 6'

  // Sum: '<S29>/Sum2' incorporates:
  //   Constant: '<S29>/Constant2'
  //   Gain: '<S32>/Gain'

  Aenea_model_B.Gain_dt = 57.295779513082323 * Aenea_model_B.Sum2_k2 + 90.0;

  // DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
  //   Constant: '<S19>/Constant'

  Aenea_model_B.Heading[0] = 4U;

  // DataTypeConversion: '<S19>/Data Type Conversion1'
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

  // DataTypeConversion: '<S19>/Data Type Conversion1'
  Aenea_model_B.Heading[1] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S19>/Data Type Conversion1'
  if (Aenea_model_B.Abs1_l < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Abs1_l);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Abs1_l);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S19>/Data Type Conversion1'
  Aenea_model_B.Heading[2] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S19>/Data Type Conversion1'
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

  // DataTypeConversion: '<S19>/Data Type Conversion1'
  Aenea_model_B.Heading[3] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));

  // DataTypeConversion: '<S19>/Data Type Conversion1'
  if (Aenea_model_B.Gain_dt < 0.0) {
    Aenea_model_B.a_b = std::ceil(Aenea_model_B.Gain_dt);
  } else {
    Aenea_model_B.a_b = std::floor(Aenea_model_B.Gain_dt);
  }

  if (rtIsNaN(Aenea_model_B.a_b) || rtIsInf(Aenea_model_B.a_b)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.a_b, 65536.0);
  }

  // DataTypeConversion: '<S19>/Data Type Conversion1'
  Aenea_model_B.Heading[4] = static_cast<uint16_T>(Aenea_model_B.a_b < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
    static_cast<uint16_T>(Aenea_model_B.a_b)));
  Aenea_model_B.Heading[5] = 0U;
  Aenea_model_B.Heading[6] = 0U;
  Aenea_model_B.Heading[7] = 0U;
  Aenea_model_B.Heading[8] = 0U;

  // Memory: '<S4>/Memory'
  Aenea_model_B.Memory_o = Aenea_model_DW.Memory_PreviousInput_e4;

  // MATLAB Function: '<S571>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S571>/Data Type Conversion2'
  //   DataTypeConversion: '<S578>/Data Type Conversion1'

  if (Aenea_model_B.SFunction_o14 == 1) {
    // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
    Aenea_model_DW.P_ref = Aenea_model_B.SFunctionBuilder_o2_p;

    // End of Outputs for SubSystem: '<S571>/Execution_loop'
  }

  if (Aenea_model_B.SFunction_o16 == 1) {
    Aenea_model_DW.P_ref = Aenea_model_B.SFunction_o17;
    Aenea_model_DW.rl_up = 20.0;
    Aenea_model_DW.rl_dw = -20.0;
  }

  // Product: '<S577>/delta rise limit' incorporates:
  //   MATLAB Function: '<S571>/MATLAB Function'
  //   SampleTimeMath: '<S577>/sample time'
  //
  //  About '<S577>/sample time':
  //   y = K where K = ( w * Ts )

  Aenea_model_B.Gain_h = Aenea_model_DW.rl_up * 0.02;

  // Sum: '<S577>/Difference Inputs1' incorporates:
  //   MATLAB Function: '<S571>/MATLAB Function'
  //   UnitDelay: '<S577>/Delay Input2'
  //
  //  Block description for '<S577>/Difference Inputs1':
  //
  //   Add in CPU
  //
  //  Block description for '<S577>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_B.Gain_dt = Aenea_model_DW.P_ref -
    Aenea_model_DW.DelayInput2_DSTATE;

  // Switch: '<S581>/Switch2' incorporates:
  //   RelationalOperator: '<S581>/LowerRelop1'

  if (!(Aenea_model_B.Gain_dt > Aenea_model_B.Gain_h)) {
    // Product: '<S577>/delta fall limit' incorporates:
    //   MATLAB Function: '<S571>/MATLAB Function'
    //   SampleTimeMath: '<S577>/sample time'
    //
    //  About '<S577>/sample time':
    //   y = K where K = ( w * Ts )

    Aenea_model_B.Gain_h = Aenea_model_DW.rl_dw * 0.02;

    // Switch: '<S581>/Switch' incorporates:
    //   RelationalOperator: '<S581>/UpperRelop'

    if (!(Aenea_model_B.Gain_dt < Aenea_model_B.Gain_h)) {
      Aenea_model_B.Gain_h = Aenea_model_B.Gain_dt;
    }

    // End of Switch: '<S581>/Switch'
  }

  // End of Switch: '<S581>/Switch2'

  // Sum: '<S577>/Difference Inputs2' incorporates:
  //   UnitDelay: '<S577>/Delay Input2'
  //
  //  Block description for '<S577>/Difference Inputs2':
  //
  //   Add in CPU
  //
  //  Block description for '<S577>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_DW.DelayInput2_DSTATE += Aenea_model_B.Gain_h;

  // DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
  //   UnitDelay: '<S577>/Delay Input2'
  //
  //  Block description for '<S577>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_B.DataTypeConversion2 = static_cast<real32_T>
    (Aenea_model_DW.DelayInput2_DSTATE);

  // Outputs for Enabled SubSystem: '<S580>/Subsystem1' incorporates:
  //   EnablePort: '<S582>/Enable'

  if (Aenea_model_B.SFunction_o14 > 0) {
    // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
    // Inport: '<S582>/T' incorporates:
    //   DataTypeConversion: '<S578>/Data Type Conversion'

    Aenea_model_B.T = Aenea_model_B.SFunctionBuilder_o1_g;

    // End of Outputs for SubSystem: '<S571>/Execution_loop'
  }

  // End of Outputs for SubSystem: '<S580>/Subsystem1'

  // Switch: '<S580>/Switch1' incorporates:
  //   Constant: '<S580>/Constant'
  //   MATLAB Function: '<S3>/MATLAB Function1'
  //   RelationalOperator: '<S580>/NotEqual'
  //   Switch: '<S580>/Switch'

  if (15.0F != Aenea_model_DW.riferimenti[12]) {
    // DataTypeConversion: '<S1>/Data Type Conversion1'
    Aenea_model_B.DataTypeConversion1_m = Aenea_model_DW.riferimenti[12];
  } else if (Aenea_model_B.T > 0.0) {
    // Switch: '<S580>/Switch' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'

    Aenea_model_B.DataTypeConversion1_m = static_cast<real32_T>(Aenea_model_B.T);
  } else {
    // DataTypeConversion: '<S1>/Data Type Conversion1'
    Aenea_model_B.DataTypeConversion1_m = Aenea_model_DW.riferimenti[12];
  }

  // End of Switch: '<S580>/Switch1'

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  // DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
  //   DataTypeConversion: '<S578>/Data Type Conversion1'
  //   Gain: '<S4>/Pa to hPa'

  Aenea_model_B.DataTypeConversion = static_cast<real32_T>(0.01 *
    Aenea_model_B.SFunctionBuilder_o2_p);

  // End of Outputs for SubSystem: '<S571>/Execution_loop'

  // DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
  //   Gain: '<S4>/Pa to hPa1'

  Aenea_model_B.DataTypeConversion1_e = static_cast<real32_T>(0.01 *
    Aenea_model_B.SFunctionBuilder_o3);

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  // DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
  //   DataTypeConversion: '<S578>/Data Type Conversion'

  Aenea_model_B.f = std::floor(Aenea_model_B.SFunctionBuilder_o1_g);

  // End of Outputs for SubSystem: '<S571>/Execution_loop'
  if (rtIsNaNF(Aenea_model_B.f) || rtIsInfF(Aenea_model_B.f)) {
    Aenea_model_B.f = 0.0F;
  } else {
    Aenea_model_B.f = std::fmod(Aenea_model_B.f, 65536.0F);
  }

  // DataTypeConversion: '<S4>/Data Type Conversion2'
  Aenea_model_B.DataTypeConversion2_m = static_cast<int16_T>(Aenea_model_B.f <
    0.0F ? static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Aenea_model_B.f)))) : static_cast<int32_T>(
    static_cast<int16_T>(static_cast<uint16_T>(Aenea_model_B.f))));

  // Outputs for Enabled SubSystem: '<S39>/Subsystem1' incorporates:
  //   EnablePort: '<S442>/Enable'

  if (Aenea_model_B.Al_selector > 0.0) {
    // DataTypeConversion: '<S442>/Data Type Conversion4' incorporates:
    //   MATLAB Function: '<S3>/MATLAB Function1'

    for (Aenea_model_B.i = 0; Aenea_model_B.i < 42; Aenea_model_B.i++) {
      Aenea_model_B.DataTypeConversion4[Aenea_model_B.i] =
        Aenea_model_DW.WP_dbP_AL[Aenea_model_B.i];
    }

    // End of DataTypeConversion: '<S442>/Data Type Conversion4'

    // MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES' incorporates:
    //   DataTypeConversion: '<S442>/Data Type Conversion4'
    //   MATLAB Function: '<S455>/MATLAB Function'

    Aenea_model_B.Gain_dt = Aenea_model_B.DataTypeConversion4[30] *
      0.017453292519943295;
    Aenea_model_B.h_Home = Aenea_model_B.DataTypeConversion4[36];
    Aenea_model_B.a_b = std::cos(Aenea_model_B.DataTypeConversion4[25] *
      0.017453292519943295);
    Aenea_model_B.Gain_h = std::sin(Aenea_model_B.DataTypeConversion4[24] *
      0.017453292519943295);
    Aenea_model_B.Abs1_l = std::cos(Aenea_model_B.DataTypeConversion4[24] *
      0.017453292519943295);
    Aenea_model_B.Switch_j = Aenea_model_B.DataTypeConversion4[31] *
      0.017453292519943295 - Aenea_model_B.DataTypeConversion4[30] *
      0.017453292519943295;
    Aenea_model_B.Al_selector = rt_atan2d_snf(std::sin(Aenea_model_B.Switch_j) *
      Aenea_model_B.a_b, std::sin(Aenea_model_B.DataTypeConversion4[25] *
      0.017453292519943295) * Aenea_model_B.Abs1_l - std::cos
      (Aenea_model_B.Switch_j) * (Aenea_model_B.Gain_h * Aenea_model_B.a_b));
    if (Aenea_model_B.Al_selector < 0.0) {
      Aenea_model_B.Al_selector = 6.2831853071795862 - std::abs
        (Aenea_model_B.Al_selector);
    }

    // MATLAB Function: '<S455>/MATLAB Function' incorporates:
    //   MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES'
    //   Trigonometry: '<S526>/SinCos'

    Aenea_model_B.a_b = std::cos(Aenea_model_B.Al_selector);
    Aenea_model_B.Switch_j = std::asin(Aenea_model_B.Abs1_l *
      -0.00015678559364639647 * Aenea_model_B.a_b + Aenea_model_B.Gain_h *
      0.99999998770913878);
    Aenea_model_B.Al_selector = std::sin(Aenea_model_B.Al_selector);

    // MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Gain: '<S471>/Gain'
    //   Gain: '<S472>/Gain'
    //   MATLAB Function: '<S455>/MATLAB Function'

    Aenea_model_B.y[12] = 57.295779513082323 * Aenea_model_B.Switch_j;
    Aenea_model_B.y[15] = 57.295779513082323 * (rt_atan2d_snf
      (Aenea_model_B.Al_selector * -0.00015678559364639647 *
       Aenea_model_B.Abs1_l, 0.99999998770913878 - Aenea_model_B.Gain_h * std::
       sin(Aenea_model_B.Switch_j)) + Aenea_model_B.Gain_dt);
    Aenea_model_B.y[3] = 1.0;
    Aenea_model_B.y[6] = 0.0;
    Aenea_model_B.y[9] = 0.0;
    Aenea_model_B.y[18] = Aenea_model_B.h_Home + 45.0;

    // MATLAB Function: '<S455>/MATLAB Function'
    Aenea_model_B.Switch_j = std::asin(Aenea_model_B.Abs1_l *
      -0.00012542847510211208 * Aenea_model_B.a_b + Aenea_model_B.Gain_h *
      0.99999999213384883);

    // MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Constant: '<S455>/Constant1'
    //   Gain: '<S471>/Gain'
    //   Gain: '<S472>/Gain'
    //   MATLAB Function: '<S455>/MATLAB Function'

    Aenea_model_B.y[13] = 57.295779513082323 * Aenea_model_B.Switch_j;
    Aenea_model_B.y[16] = 57.295779513082323 * (rt_atan2d_snf
      (Aenea_model_B.Al_selector * -0.00012542847510211208 *
       Aenea_model_B.Abs1_l, 0.99999999213384883 - Aenea_model_B.Gain_h * std::
       sin(Aenea_model_B.Switch_j)) + Aenea_model_B.Gain_dt);
    Aenea_model_B.y[1] = 20.0;
    Aenea_model_B.y[4] = 1.0;
    Aenea_model_B.y[7] = 0.0;
    Aenea_model_B.y[10] = 0.0;
    Aenea_model_B.y[19] = Aenea_model_B.h_Home + 45.0;

    // MATLAB Function: '<S455>/MATLAB Function'
    Aenea_model_B.Switch_j = std::asin(Aenea_model_B.Abs1_l *
      0.00031357118343873296 * Aenea_model_B.a_b + Aenea_model_B.Gain_h *
      0.99999995083655524);

    // MATLAB Function: '<S455>/AUTOLANDING_WAYPOINTS' incorporates:
    //   Constant: '<S455>/Constant'
    //   Constant: '<S455>/Constant1'
    //   Gain: '<S471>/Gain'
    //   Gain: '<S472>/Gain'
    //   MATLAB Function: '<S455>/MATLAB Function'

    Aenea_model_B.y[14] = 57.295779513082323 * Aenea_model_B.Switch_j;
    Aenea_model_B.y[17] = 57.295779513082323 * (rt_atan2d_snf
      (Aenea_model_B.Al_selector * 0.00031357118343873296 * Aenea_model_B.Abs1_l,
       0.99999995083655524 - Aenea_model_B.Gain_h * std::sin
       (Aenea_model_B.Switch_j)) + Aenea_model_B.Gain_dt);
    Aenea_model_B.y[2] = 20.0;
    Aenea_model_B.y[8] = 0.0;
    Aenea_model_B.y[11] = 0.0;
    Aenea_model_B.y[20] = Aenea_model_B.h_Home + 45.0;
    Aenea_model_B.y[0] = 25.0;
    Aenea_model_B.y[5] = 0.0;

    // Gain: '<S460>/Gain' incorporates:
    //   DataTypeConversion: '<S442>/Data Type Conversion4'
    //   MATLAB Function: '<S442>/CALIBRATING_HOME_COORDINATES'

    Aenea_model_B.Gain = Aenea_model_B.DataTypeConversion4[24] *
      0.017453292519943295 * 57.295779513082323;

    // Switch: '<S536>/Switch' incorporates:
    //   Abs: '<S536>/Abs'
    //   Bias: '<S536>/Bias'
    //   Bias: '<S536>/Bias1'
    //   Constant: '<S536>/Constant2'
    //   Constant: '<S537>/Constant'
    //   Math: '<S536>/Math Function1'
    //   RelationalOperator: '<S537>/Compare'

    if (std::abs(Aenea_model_B.Gain) > 180.0) {
      Aenea_model_B.Switch_j = rt_modd_snf(Aenea_model_B.Gain + 180.0, 360.0) +
        -180.0;
    } else {
      Aenea_model_B.Switch_j = Aenea_model_B.Gain;
    }

    // End of Switch: '<S536>/Switch'

    // Abs: '<S533>/Abs1'
    Aenea_model_B.Gain_h = std::abs(Aenea_model_B.Switch_j);

    // RelationalOperator: '<S535>/Compare' incorporates:
    //   Constant: '<S535>/Constant'

    Ap_sel = (Aenea_model_B.Gain_h > 90.0);

    // Switch: '<S533>/Switch' incorporates:
    //   Bias: '<S533>/Bias'
    //   Bias: '<S533>/Bias1'
    //   Constant: '<S525>/Constant'
    //   Constant: '<S525>/Constant1'
    //   Gain: '<S533>/Gain'
    //   Product: '<S533>/Divide1'
    //   Switch: '<S525>/Switch1'

    if (Ap_sel) {
      // Signum: '<S533>/Sign1'
      if (Aenea_model_B.Switch_j < 0.0) {
        Aenea_model_B.Switch_j = -1.0;
      } else if (Aenea_model_B.Switch_j > 0.0) {
        Aenea_model_B.Switch_j = 1.0;
      } else if (Aenea_model_B.Switch_j == 0.0) {
        Aenea_model_B.Switch_j = 0.0;
      } else {
        Aenea_model_B.Switch_j = (rtNaN);
      }

      // End of Signum: '<S533>/Sign1'
      Aenea_model_B.Switch_j *= -(Aenea_model_B.Gain_h + -90.0) + 90.0;
      Aenea_model_B.npad = 180;
    } else {
      Aenea_model_B.npad = 0;
    }

    // End of Switch: '<S533>/Switch'

    // Gain: '<S461>/Gain'
    Aenea_model_B.Gain_o = 57.295779513082323 * Aenea_model_B.Gain_dt;

    // Sum: '<S525>/Sum'
    Aenea_model_B.Gain_dt = static_cast<real_T>(Aenea_model_B.npad) +
      Aenea_model_B.Gain_o;

    // Sum: '<S459>/Sum1' incorporates:
    //   Gain: '<S463>/Gain'

    Aenea_model_B.Gain_h = 57.295779513082323 * Aenea_model_B.Lat_K -
      Aenea_model_B.Switch_j;

    // Switch: '<S530>/Switch' incorporates:
    //   Abs: '<S530>/Abs'
    //   Bias: '<S530>/Bias'
    //   Bias: '<S530>/Bias1'
    //   Constant: '<S530>/Constant2'
    //   Constant: '<S531>/Constant'
    //   Math: '<S530>/Math Function1'
    //   RelationalOperator: '<S531>/Compare'

    if (std::abs(Aenea_model_B.Gain_h) > 180.0) {
      Aenea_model_B.Gain_h = rt_modd_snf(Aenea_model_B.Gain_h + 180.0, 360.0) +
        -180.0;
    }

    // End of Switch: '<S530>/Switch'

    // Abs: '<S527>/Abs1'
    Aenea_model_B.Abs1_l = std::abs(Aenea_model_B.Gain_h);

    // Switch: '<S527>/Switch' incorporates:
    //   Bias: '<S527>/Bias'
    //   Bias: '<S527>/Bias1'
    //   Constant: '<S524>/Constant'
    //   Constant: '<S524>/Constant1'
    //   Constant: '<S529>/Constant'
    //   Gain: '<S527>/Gain'
    //   Product: '<S527>/Divide1'
    //   RelationalOperator: '<S529>/Compare'
    //   Switch: '<S524>/Switch1'

    if (Aenea_model_B.Abs1_l > 90.0) {
      // Signum: '<S527>/Sign1'
      if (Aenea_model_B.Gain_h < 0.0) {
        Aenea_model_B.Gain_h = -1.0;
      } else if (Aenea_model_B.Gain_h > 0.0) {
        Aenea_model_B.Gain_h = 1.0;
      } else if (Aenea_model_B.Gain_h == 0.0) {
        Aenea_model_B.Gain_h = 0.0;
      } else {
        Aenea_model_B.Gain_h = (rtNaN);
      }

      // End of Signum: '<S527>/Sign1'
      Aenea_model_B.Gain_h *= -(Aenea_model_B.Abs1_l + -90.0) + 90.0;
      Aenea_model_B.npad = 180;
    } else {
      Aenea_model_B.npad = 0;
    }

    // End of Switch: '<S527>/Switch'

    // Switch: '<S534>/Switch' incorporates:
    //   Abs: '<S534>/Abs'
    //   Bias: '<S534>/Bias'
    //   Bias: '<S534>/Bias1'
    //   Constant: '<S534>/Constant2'
    //   Constant: '<S538>/Constant'
    //   Math: '<S534>/Math Function1'
    //   RelationalOperator: '<S538>/Compare'

    if (std::abs(Aenea_model_B.Gain_dt) > 180.0) {
      Aenea_model_B.Gain_dt = rt_modd_snf(Aenea_model_B.Gain_dt + 180.0, 360.0)
        + -180.0;
    }

    // End of Switch: '<S534>/Switch'

    // Sum: '<S524>/Sum' incorporates:
    //   Gain: '<S462>/Gain'
    //   Sum: '<S459>/Sum1'

    Aenea_model_B.Sum_h = (57.295779513082323 * Aenea_model_B.Long_K -
      Aenea_model_B.Gain_dt) + static_cast<real_T>(Aenea_model_B.npad);

    // Gain: '<S540>/Gain1'
    Aenea_model_B.Switch_j *= 0.017453292519943295;

    // Trigonometry: '<S543>/Trigonometric Function1'
    Aenea_model_B.Gain_dt = std::sin(Aenea_model_B.Switch_j);

    // Sum: '<S543>/Sum1' incorporates:
    //   Constant: '<S543>/Constant'
    //   Product: '<S543>/Product1'

    Aenea_model_B.Gain_dt = 1.0 - 0.0066943799901413295 * Aenea_model_B.Gain_dt *
      Aenea_model_B.Gain_dt;

    // Product: '<S539>/Product1' incorporates:
    //   Constant: '<S539>/Constant1'
    //   Sqrt: '<S539>/sqrt'

    Aenea_model_B.Abs1_l = 6.378137E+6 / std::sqrt(Aenea_model_B.Gain_dt);

    // Switch: '<S528>/Switch' incorporates:
    //   Abs: '<S528>/Abs'
    //   Bias: '<S528>/Bias'
    //   Bias: '<S528>/Bias1'
    //   Constant: '<S528>/Constant2'
    //   Constant: '<S532>/Constant'
    //   Math: '<S528>/Math Function1'
    //   RelationalOperator: '<S532>/Compare'

    if (std::abs(Aenea_model_B.Sum_h) > 180.0) {
      Aenea_model_B.Sum_h = rt_modd_snf(Aenea_model_B.Sum_h + 180.0, 360.0) +
        -180.0;
    }

    // End of Switch: '<S528>/Switch'

    // Sum: '<S526>/Sum2' incorporates:
    //   Constant: '<S539>/Constant'
    //   Constant: '<S539>/Constant2'
    //   Constant: '<S539>/Constant3'
    //   Gain: '<S523>/Gain1'
    //   Product: '<S526>/dEast'
    //   Product: '<S526>/dNorth'
    //   Product: '<S526>/x*cos'
    //   Product: '<S526>/y*sin'
    //   Product: '<S539>/Product2'
    //   Product: '<S539>/Product3'
    //   Product: '<S539>/Product4'
    //   Sum: '<S539>/Sum1'
    //   Trigonometry: '<S539>/Trigonometric Function'
    //   Trigonometry: '<S539>/Trigonometric Function1'
    //   Trigonometry: '<S539>/Trigonometric Function2'

    Aenea_model_B.Gain_dt = 0.017453292519943295 * Aenea_model_B.Gain_h /
      rt_atan2d_snf(1.0, Aenea_model_B.Abs1_l * 0.99330562000985867 /
                    Aenea_model_B.Gain_dt) * Aenea_model_B.a_b + 1.0 /
      rt_atan2d_snf(1.0, Aenea_model_B.Abs1_l * std::cos(Aenea_model_B.Switch_j))
      * (0.017453292519943295 * Aenea_model_B.Sum_h) * Aenea_model_B.Al_selector;

    // Gain: '<S464>/Gain'
    Aenea_model_B.Sum_h = 57.295779513082323 * Aenea_model_B.Lat_K;

    // Gain: '<S465>/Gain'
    Aenea_model_B.Gain_hh = 57.295779513082323 * Aenea_model_B.Long_K;

    // MATLAB Function: '<S442>/ALLINEAMENTO' incorporates:
    //   Memory: '<S442>/Memory7'

    Aenea_model_B.b_a_tmp = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 11];
    Aenea_model_B.a_b = std::sin((Aenea_model_B.b_a_tmp - Aenea_model_B.Sum_h) *
      3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.dist_fut = Aenea_model_B.y[static_cast<int32_T>
      (Aenea_model_DW.Memory7_PreviousInput) + 14];
    Aenea_model_B.dist = (Aenea_model_B.dist_fut - Aenea_model_B.Gain_hh) *
      3.1415926535897931 / 180.0;
    Aenea_model_B.Gain_h = std::sin(Aenea_model_B.dist / 2.0);
    Aenea_model_B.Al_selector = Aenea_model_B.b_a_tmp * 3.1415926535897931 /
      180.0;
    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.Al_selector);
    Aenea_model_B.a_tmp_tmp = Aenea_model_B.Sum_h * 3.1415926535897931 / 180.0;
    Aenea_model_B.Abs1_l = std::cos(Aenea_model_B.a_tmp_tmp);
    Aenea_model_B.a_b = Aenea_model_B.Abs1_l * Aenea_model_B.Switch_j *
      (Aenea_model_B.Gain_h * Aenea_model_B.Gain_h) + Aenea_model_B.a_b *
      Aenea_model_B.a_b;
    Aenea_model_B.Gain_h = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt
      (1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
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
      Aenea_model_B.a_b = Aenea_model_B.a_b * Aenea_model_B.Abs1_l *
        (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_tmp_tmp *
        Aenea_model_B.a_tmp_tmp;
      Aenea_model_B.dist = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt
        (1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    } else {
      Aenea_model_B.Al_selector = rt_atan2d_snf(std::sin(Aenea_model_B.dist) *
        Aenea_model_B.Switch_j, std::sin(Aenea_model_B.Al_selector) *
        Aenea_model_B.Abs1_l - std::cos(Aenea_model_B.dist) * (std::sin
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
      Aenea_model_B.Abs1_l = 0.0;
    } else if (Aenea_model_DW.Memory7_PreviousInput == 2.0) {
      Aenea_model_B.b_a_tmp = std::cos(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931 /
        180.0);
      Aenea_model_B.Gain_hh = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14] -
        Aenea_model_B.Gain_hh) * 3.1415926535897931 / 180.0;
      Aenea_model_B.Abs1_l = std::abs(Aenea_model_B.Al_selector - rt_atan2d_snf
        (std::sin(Aenea_model_B.Gain_hh) * Aenea_model_B.b_a_tmp, std::sin
         (Aenea_model_B.y[static_cast<int32_T>
          (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] *
          3.1415926535897931 / 180.0) * Aenea_model_B.Abs1_l - std::cos
         (Aenea_model_B.Gain_hh) * (std::sin(Aenea_model_B.Sum_h *
        3.1415926535897931 / 180.0) * Aenea_model_B.b_a_tmp)) * 180.0 /
        3.1415926535897931);
    } else {
      Aenea_model_B.Abs1_l = std::cos(Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931 /
        180.0);
      Aenea_model_B.Sum_h = Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 2.0) + 11] * 3.1415926535897931 /
        180.0;
      Aenea_model_B.Gain_hh = (Aenea_model_B.y[static_cast<int32_T>
        (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 14] - Aenea_model_B.y[
        static_cast<int32_T>(Aenea_model_DW.Memory7_PreviousInput - 2.0) + 14]) *
        3.1415926535897931 / 180.0;
      Aenea_model_B.Abs1_l = rt_atan2d_snf(std::sin(Aenea_model_B.Gain_hh) *
        Aenea_model_B.Abs1_l, std::cos(Aenea_model_B.Sum_h) * std::sin
        (Aenea_model_B.y[static_cast<int32_T>
         (Aenea_model_DW.Memory7_PreviousInput - 1.0) + 11] * 3.1415926535897931
         / 180.0) - std::sin(Aenea_model_B.Sum_h) * Aenea_model_B.Abs1_l * std::
        cos(Aenea_model_B.Gain_hh)) * 180.0 / 3.1415926535897931;
      if (Aenea_model_B.Abs1_l < 0.0) {
        Aenea_model_B.Abs1_l = 360.0 - std::abs(Aenea_model_B.Abs1_l);
      }

      Aenea_model_B.Abs1_l = std::abs(Aenea_model_B.Al_selector -
        Aenea_model_B.Abs1_l);
    }

    if (Aenea_model_B.Switch_j <= 3.0) {
      Aenea_model_B.Switch_j = 1.0;
      Aenea_model_B.srem = 20;
    } else if (Aenea_model_B.Switch_j <= 10.0) {
      Aenea_model_B.Switch_j = 30.0;
      Aenea_model_B.srem = 100;
    } else if ((Aenea_model_B.Switch_j > 10.0) && (Aenea_model_B.Switch_j <=
                50.0)) {
      Aenea_model_B.Switch_j = 80.0;
      Aenea_model_B.srem = 250;
    } else if ((Aenea_model_B.Switch_j > 50.0) && (Aenea_model_B.Switch_j <=
                90.0)) {
      Aenea_model_B.Switch_j = 100.0;
      Aenea_model_B.srem = 300;
    } else if ((Aenea_model_B.Switch_j > 90.0) && (Aenea_model_B.Switch_j <=
                120.0)) {
      Aenea_model_B.Switch_j = 150.0;
      Aenea_model_B.srem = 350;
    } else {
      Aenea_model_B.Switch_j = 200.0;
      Aenea_model_B.srem = 400;
    }

    if (Aenea_model_B.Abs1_l <= 10.0) {
      Aenea_model_B.soglia_dist = 80;
    } else if ((Aenea_model_B.Abs1_l > 10.0) && (Aenea_model_B.Abs1_l <= 50.0))
    {
      Aenea_model_B.soglia_dist = 200;
    } else if ((Aenea_model_B.Abs1_l > 50.0) && (Aenea_model_B.Abs1_l <= 90.0))
    {
      Aenea_model_B.soglia_dist = 300;
    } else if ((Aenea_model_B.Abs1_l > 90.0) && (Aenea_model_B.Abs1_l <= 120.0))
    {
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
           (!(Aenea_model_B.Gain_h > Aenea_model_B.Switch_j))) &&
          ((!(Aenea_model_B.dist > Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_B.Gain_h > Aenea_model_B.Switch_j))) &&
          (Aenea_model_B.Gain_h < Aenea_model_B.Switch_j)) {
        if (Aenea_model_B.dist_fut > Aenea_model_B.srem) {
          Aenea_model_DW.Memory7_PreviousInput++;
        } else if (Aenea_model_DW.Memory7_PreviousInput < 2.0) {
          Aenea_model_DW.Memory7_PreviousInput += 2.0;
        } else {
          Aenea_model_DW.flag_k = 1.0;
        }
      }
    } else {
      if (((!(Aenea_model_B.dist < Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_DW.flag_k == 0.0))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.soglia_dist)) || (!(Aenea_model_B.Gain_h > 40.0)) ||
           (!(Aenea_model_DW.flag_k == 0.0)))) {
        Aenea_model_DW.flag_k = 1.0;
      }
    }

    if (!(Aenea_model_B.modo == 4.0)) {
      Aenea_model_DW.Memory7_PreviousInput = 1.0;
    }

    // End of MATLAB Function: '<S442>/ALLINEAMENTO'

    // Abs: '<S442>/Abs1'
    Aenea_model_B.a_b = std::abs(Aenea_model_B.Gain_dt);

    // Chart: '<S442>/Chart1' incorporates:
    //   Memory: '<S442>/Memory1'
    //   Memory: '<S442>/Memory2'
    //   Memory: '<S442>/Memory5'

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
        if ((Aenea_model_B.Alt > 35.0) && (Aenea_model_B.Alt < 60.0) &&
            (Aenea_model_B.a_b <= Aenea_model_B.Alt * 19.081136687728211 + 100.0)
            && (Aenea_model_B.a_b >= Aenea_model_B.Alt * 14.300666256711928 +
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
        if ((Aenea_model_B.Gain_dt >= Aenea_model_DW.Memory5_PreviousInput) &&
            ((Aenea_model_B.Alt <= Aenea_model_DW.Memory1_PreviousInput_f + 1.5)
             || (Aenea_model_B.Alt > Aenea_model_DW.Memory1_PreviousInput_f -
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
        if ((Aenea_model_B.olddi < 3.0) || (!(Aenea_model_B.modo != 4.0))) {
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

    // End of Chart: '<S442>/Chart1'

    // Outputs for Triggered SubSystem: '<S442>/Sample and Hold' incorporates:
    //   TriggerPort: '<S467>/Trigger'

    Aenea_model_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
      &Aenea_model_PrevZCX.SampleandHold_Trig_ZCE_l,
      (Aenea_model_B.approach_selector));
    if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
      // Inport: '<S467>/In' incorporates:
      //   Abs: '<S442>/Abs2'
      //   Sum: '<S459>/Sum'
      //   UnaryMinus: '<S459>/Ze2height'

      Aenea_model_B.In_c[0] = std::abs(-Aenea_model_B.Alt);
      Aenea_model_B.In_c[1] = Aenea_model_B.Gain_dt;
    }

    // End of Outputs for SubSystem: '<S442>/Sample and Hold'

    // Outputs for Enabled SubSystem: '<S442>/APPROACH' incorporates:
    //   EnablePort: '<S453>/Enable'

    if (Aenea_model_B.trig_approach > 0.0) {
      // Product: '<S453>/Divide' incorporates:
      //   Constant: '<S453>/x_g0'
      //   Sum: '<S453>/Sum'

      Aenea_model_B.Gain_h = Aenea_model_B.In_c[0] / (Aenea_model_B.In_c[1] -
        -100.0);

      // Abs: '<S453>/Abs' incorporates:
      //   Trigonometry: '<S453>/Atan'

      Aenea_model_B.Abs1_l = std::abs(std::atan(Aenea_model_B.Gain_h));

      // DiscreteIntegrator: '<S453>/Discrete-Time Integrator'
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

      // Switch: '<S453>/Switch' incorporates:
      //   DiscreteIntegrator: '<S453>/Discrete-Time Integrator'

      Aenea_model_B.npad = (Aenea_model_DW.DiscreteTimeIntegrator_DSTATE_j > 0.0);

      // MATLAB Function: '<S453>/MATLAB Function'
      Aenea_model_B.srem = 0;
      if ((!Aenea_model_DW.x_not_empty) || (Aenea_model_B.npad == 0)) {
        Aenea_model_DW.x[0] = 1.5;
        Aenea_model_DW.x[1] = -200.0;
        Aenea_model_DW.x[2] = 0.01;
        Aenea_model_DW.x[3] = -2.0;
        Aenea_model_DW.x_not_empty = true;
      }

      Aenea_model_DW.x_new_not_empty = ((!Aenea_model_DW.x_new_not_empty) ||
        (Aenea_model_B.npad == 0) || Aenea_model_DW.x_new_not_empty);
      if ((!Aenea_model_DW.eps_not_empty) || (Aenea_model_B.npad == 0)) {
        Aenea_model_DW.eps[0] = 1.0;
        Aenea_model_DW.eps[1] = 1.0;
        Aenea_model_DW.eps[2] = 1.0;
        Aenea_model_DW.eps[3] = 1.0;
        Aenea_model_DW.eps_not_empty = true;
      }

      if ((!Aenea_model_DW.cycle_count_not_empty) || (Aenea_model_B.npad == 0))
      {
        Aenea_model_DW.cycle_count = 0.0;
        Aenea_model_DW.cycle_count_not_empty = true;
      }

      exitg1 = false;
      while ((!exitg1) && ((!(Aenea_model_DW.eps[0] < 0.1)) ||
                           ((!(Aenea_model_DW.eps[1] < 0.1)) ||
                            ((!(Aenea_model_DW.eps[2] < 0.1)) ||
                             (!(Aenea_model_DW.eps[3] < 0.1)))))) {
        std::memset(&Aenea_model_B.a[0], 0, sizeof(real_T) << 4U);
        Aenea_model_B.Switch_j = std::exp((5.0 - Aenea_model_DW.x[1]) *
          -Aenea_model_DW.x[2]);
        Aenea_model_B.Gain_hh = std::tan(Aenea_model_B.Abs1_l);
        Aenea_model_B.A[0] = 1.0;
        Aenea_model_B.A[4] = Aenea_model_B.Gain_hh;
        Aenea_model_B.A[8] = 0.0;
        Aenea_model_B.A[12] = 0.0;
        Aenea_model_B.A[1] = Aenea_model_DW.x[2];
        Aenea_model_B.A[5] = 0.0;
        Aenea_model_B.Sum_h = Aenea_model_DW.x[0] - Aenea_model_DW.x[3];
        Aenea_model_B.A[9] = Aenea_model_B.Sum_h;
        Aenea_model_B.A[13] = -Aenea_model_DW.x[2];
        Aenea_model_B.A[2] = Aenea_model_B.Switch_j;
        Aenea_model_B.dist = Aenea_model_B.Sum_h * Aenea_model_DW.x[2];
        Aenea_model_B.A[6] = Aenea_model_B.dist * Aenea_model_B.Switch_j;
        Aenea_model_B.A[10] = Aenea_model_B.Sum_h * (Aenea_model_DW.x[1] - 5.0) *
          Aenea_model_B.Switch_j;
        Aenea_model_B.A[14] = 1.0;
        Aenea_model_B.A[3] = Aenea_model_DW.x[2] * 18.0 * Aenea_model_B.Switch_j;
        Aenea_model_B.A[7] = Aenea_model_B.Sum_h * (Aenea_model_DW.x[2] *
          Aenea_model_DW.x[2]) * 18.0 * Aenea_model_B.Switch_j;
        Aenea_model_B.Al_selector = Aenea_model_B.dist * 18.0;
        Aenea_model_B.A[11] = Aenea_model_B.Al_selector * (Aenea_model_DW.x[1] -
          5.0) * Aenea_model_B.Switch_j + Aenea_model_B.Sum_h * 18.0 *
          Aenea_model_B.Switch_j;
        Aenea_model_B.A[15] = -Aenea_model_DW.x[2] * 18.0 *
          Aenea_model_B.Switch_j;
        Aenea_model_B.ipiv_n[0] = 1;
        Aenea_model_B.ipiv_n[1] = 2;
        Aenea_model_B.ipiv_n[2] = 3;
        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 3; Aenea_model_B.npad
             ++) {
          Aenea_model_B.soglia_dist = Aenea_model_B.npad * 5;
          Aenea_model_B.i = 0;
          Aenea_model_B.ix = Aenea_model_B.soglia_dist;
          Aenea_model_B.a_b = std::abs(Aenea_model_B.A[Aenea_model_B.soglia_dist]);
          Aenea_model_B.d_k = 2;
          while (Aenea_model_B.d_k <= 4 - Aenea_model_B.npad) {
            Aenea_model_B.ix++;
            Aenea_model_B.dist_fut = std::abs(Aenea_model_B.A[Aenea_model_B.ix]);
            if (Aenea_model_B.dist_fut > Aenea_model_B.a_b) {
              Aenea_model_B.i = Aenea_model_B.d_k - 1;
              Aenea_model_B.a_b = Aenea_model_B.dist_fut;
            }

            Aenea_model_B.d_k++;
          }

          if (Aenea_model_B.A[Aenea_model_B.soglia_dist + Aenea_model_B.i] !=
              0.0) {
            if (Aenea_model_B.i != 0) {
              Aenea_model_B.d_k = Aenea_model_B.npad + Aenea_model_B.i;
              Aenea_model_B.ipiv_n[Aenea_model_B.npad] = static_cast<int8_T>
                (Aenea_model_B.d_k + 1);
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.npad];
              Aenea_model_B.A[Aenea_model_B.npad] =
                Aenea_model_B.A[Aenea_model_B.d_k];
              Aenea_model_B.A[Aenea_model_B.d_k] = Aenea_model_B.a_b;
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.npad + 4];
              Aenea_model_B.A[Aenea_model_B.npad + 4] =
                Aenea_model_B.A[Aenea_model_B.d_k + 4];
              Aenea_model_B.A[Aenea_model_B.d_k + 4] = Aenea_model_B.a_b;
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.npad + 8];
              Aenea_model_B.A[Aenea_model_B.npad + 8] =
                Aenea_model_B.A[Aenea_model_B.d_k + 8];
              Aenea_model_B.A[Aenea_model_B.d_k + 8] = Aenea_model_B.a_b;
              Aenea_model_B.a_b = Aenea_model_B.A[Aenea_model_B.npad + 12];
              Aenea_model_B.A[Aenea_model_B.npad + 12] =
                Aenea_model_B.A[Aenea_model_B.d_k + 12];
              Aenea_model_B.A[Aenea_model_B.d_k + 12] = Aenea_model_B.a_b;
            }

            Aenea_model_B.i = (Aenea_model_B.soglia_dist - Aenea_model_B.npad) +
              4;
            Aenea_model_B.d_k = Aenea_model_B.soglia_dist + 1;
            while (Aenea_model_B.d_k + 1 <= Aenea_model_B.i) {
              Aenea_model_B.A[Aenea_model_B.d_k] /=
                Aenea_model_B.A[Aenea_model_B.soglia_dist];
              Aenea_model_B.d_k++;
            }
          }

          Aenea_model_B.i = Aenea_model_B.soglia_dist;
          Aenea_model_B.ix = Aenea_model_B.soglia_dist + 4;
          Aenea_model_B.c = 0;
          while (Aenea_model_B.c <= 2 - Aenea_model_B.npad) {
            if (Aenea_model_B.A[Aenea_model_B.ix] != 0.0) {
              Aenea_model_B.a_b = -Aenea_model_B.A[Aenea_model_B.ix];
              Aenea_model_B.c_ix = Aenea_model_B.soglia_dist + 1;
              Aenea_model_B.d_k = (Aenea_model_B.i - Aenea_model_B.npad) + 8;
              Aenea_model_B.ijA = Aenea_model_B.i + 5;
              while (Aenea_model_B.ijA + 1 <= Aenea_model_B.d_k) {
                Aenea_model_B.A[Aenea_model_B.ijA] +=
                  Aenea_model_B.A[Aenea_model_B.c_ix] * Aenea_model_B.a_b;
                Aenea_model_B.c_ix++;
                Aenea_model_B.ijA++;
              }
            }

            Aenea_model_B.ix += 4;
            Aenea_model_B.i += 4;
            Aenea_model_B.c++;
          }
        }

        Aenea_model_B.p[0] = 1;
        Aenea_model_B.p[1] = 2;
        Aenea_model_B.p[2] = 3;
        Aenea_model_B.p[3] = 4;
        if (Aenea_model_B.ipiv_n[0] > 1) {
          Aenea_model_B.npad = Aenea_model_B.p[Aenea_model_B.ipiv_n[0] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_n[0] - 1] = 1;
          Aenea_model_B.p[0] = static_cast<int8_T>(Aenea_model_B.npad);
        }

        if (Aenea_model_B.ipiv_n[1] > 2) {
          Aenea_model_B.npad = Aenea_model_B.p[Aenea_model_B.ipiv_n[1] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_n[1] - 1] = Aenea_model_B.p[1];
          Aenea_model_B.p[1] = static_cast<int8_T>(Aenea_model_B.npad);
        }

        if (Aenea_model_B.ipiv_n[2] > 3) {
          Aenea_model_B.npad = Aenea_model_B.p[Aenea_model_B.ipiv_n[2] - 1];
          Aenea_model_B.p[Aenea_model_B.ipiv_n[2] - 1] = Aenea_model_B.p[2];
          Aenea_model_B.p[2] = static_cast<int8_T>(Aenea_model_B.npad);
        }

        Aenea_model_B.c = Aenea_model_B.p[0] - 1;
        Aenea_model_B.a[(Aenea_model_B.p[0] - 1) << 2] = 1.0;
        Aenea_model_B.d_k = 0;
        while (Aenea_model_B.d_k + 1 < 5) {
          Aenea_model_B.npad = Aenea_model_B.c << 2;
          Aenea_model_B.soglia_dist = Aenea_model_B.npad + Aenea_model_B.d_k;
          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.d_k + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.ix = Aenea_model_B.npad + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.ix] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist] * Aenea_model_B.A
                [(Aenea_model_B.d_k << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.d_k++;
        }

        Aenea_model_B.c = Aenea_model_B.p[1] - 1;
        Aenea_model_B.a[((Aenea_model_B.p[1] - 1) << 2) + 1] = 1.0;
        Aenea_model_B.d_k = 1;
        while (Aenea_model_B.d_k + 1 < 5) {
          Aenea_model_B.npad = Aenea_model_B.c << 2;
          Aenea_model_B.soglia_dist = Aenea_model_B.npad + Aenea_model_B.d_k;
          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.d_k + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.ix = Aenea_model_B.npad + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.ix] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist] * Aenea_model_B.A
                [(Aenea_model_B.d_k << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.d_k++;
        }

        Aenea_model_B.c = Aenea_model_B.p[2] - 1;
        Aenea_model_B.a[((Aenea_model_B.p[2] - 1) << 2) + 2] = 1.0;
        Aenea_model_B.d_k = 2;
        while (Aenea_model_B.d_k + 1 < 5) {
          Aenea_model_B.npad = Aenea_model_B.c << 2;
          Aenea_model_B.soglia_dist = Aenea_model_B.npad + Aenea_model_B.d_k;
          if (Aenea_model_B.a[Aenea_model_B.soglia_dist] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.d_k + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.ix = Aenea_model_B.npad + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.ix] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist] * Aenea_model_B.A
                [(Aenea_model_B.d_k << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.d_k++;
        }

        Aenea_model_B.ix = (Aenea_model_B.p[3] - 1) << 2;
        Aenea_model_B.a[Aenea_model_B.ix + 3] = 1.0;
        Aenea_model_B.d_k = 3;
        while (Aenea_model_B.d_k + 1 < 5) {
          Aenea_model_B.npad = Aenea_model_B.ix + Aenea_model_B.d_k;
          if (Aenea_model_B.a[Aenea_model_B.npad] != 0.0) {
            Aenea_model_B.i = Aenea_model_B.d_k + 1;
            while (Aenea_model_B.i + 1 < 5) {
              Aenea_model_B.soglia_dist = Aenea_model_B.ix + Aenea_model_B.i;
              Aenea_model_B.a[Aenea_model_B.soglia_dist] -=
                Aenea_model_B.a[Aenea_model_B.npad] * Aenea_model_B.A
                [(Aenea_model_B.d_k << 2) + Aenea_model_B.i];
              Aenea_model_B.i++;
            }
          }

          Aenea_model_B.d_k++;
        }

        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 4; Aenea_model_B.npad
             ++) {
          Aenea_model_B.soglia_dist = Aenea_model_B.npad << 2;
          Aenea_model_B.a_b = Aenea_model_B.a[Aenea_model_B.soglia_dist + 3];
          if (Aenea_model_B.a_b != 0.0) {
            Aenea_model_B.a[Aenea_model_B.soglia_dist + 3] = Aenea_model_B.a_b /
              Aenea_model_B.A[15];
            Aenea_model_B.d_k = 0;
            while (Aenea_model_B.d_k <= 2) {
              Aenea_model_B.ix = Aenea_model_B.d_k + Aenea_model_B.soglia_dist;
              Aenea_model_B.a[Aenea_model_B.ix] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist + 3] *
                Aenea_model_B.A[Aenea_model_B.d_k + 12];
              Aenea_model_B.d_k++;
            }
          }

          Aenea_model_B.a_b = Aenea_model_B.a[Aenea_model_B.soglia_dist + 2];
          if (Aenea_model_B.a_b != 0.0) {
            Aenea_model_B.a[Aenea_model_B.soglia_dist + 2] = Aenea_model_B.a_b /
              Aenea_model_B.A[10];
            Aenea_model_B.d_k = 0;
            while (Aenea_model_B.d_k <= 1) {
              Aenea_model_B.ix = Aenea_model_B.d_k + Aenea_model_B.soglia_dist;
              Aenea_model_B.a[Aenea_model_B.ix] -=
                Aenea_model_B.a[Aenea_model_B.soglia_dist + 2] *
                Aenea_model_B.A[Aenea_model_B.d_k + 8];
              Aenea_model_B.d_k++;
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
        Aenea_model_B.Sum_h = Aenea_model_B.Sum_h * Aenea_model_B.Switch_j +
          Aenea_model_DW.x[3];
        Aenea_model_B.Switch_j = Aenea_model_B.Al_selector *
          Aenea_model_B.Switch_j + -0.1;
        for (Aenea_model_B.npad = 0; Aenea_model_B.npad < 4; Aenea_model_B.npad
             ++) {
          Aenea_model_B.x_new[Aenea_model_B.npad] =
            Aenea_model_DW.x[Aenea_model_B.npad] -
            (((Aenea_model_B.a[Aenea_model_B.npad + 4] * Aenea_model_B.Gain_hh +
               Aenea_model_B.a[Aenea_model_B.npad] * Aenea_model_B.a_b) +
              Aenea_model_B.a[Aenea_model_B.npad + 8] * Aenea_model_B.Sum_h) +
             Aenea_model_B.a[Aenea_model_B.npad + 12] * Aenea_model_B.Switch_j);
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
          Aenea_model_B.srem = 1;
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

      Aenea_model_B.no_solution = Aenea_model_B.srem;

      // End of MATLAB Function: '<S453>/MATLAB Function'

      // Product: '<S453>/Multiply' incorporates:
      //   Constant: '<S453>/x_g0'
      //   Gain: '<S453>/Gain'
      //   Sum: '<S453>/Sum1'

      Aenea_model_B.Multiply = -(Aenea_model_B.Gain_dt - -100.0) *
        Aenea_model_B.Gain_h;

      // Constant: '<S453>/Constant1'
      Aenea_model_B.Constant1_h = 20.0;

      // Update for DiscreteIntegrator: '<S453>/Discrete-Time Integrator'
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

      // End of Update for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' 
    }

    // End of Outputs for SubSystem: '<S442>/APPROACH'

    // Outputs for Enabled SubSystem: '<S442>/FLARE' incorporates:
    //   EnablePort: '<S457>/Enable'

    if (Aenea_model_B.trig_flare > 0.0) {
      // Constant: '<S457>/Constant1'
      Aenea_model_B.Constant1 = 18.0;

      // Sum: '<S457>/Sum2' incorporates:
      //   Gain: '<S457>/Gain'
      //   Math: '<S457>/Exp'
      //   Product: '<S457>/Multiply'
      //   Product: '<S457>/Multiply1'
      //   Sum: '<S457>/Sum'
      //   Sum: '<S457>/Sum1'
      //
      //  About '<S457>/Exp':
      //   Operator: exp

      Aenea_model_B.Sum2 = std::exp(-((Aenea_model_B.Gain_dt -
        Aenea_model_B.x_f_out) * Aenea_model_B.k_x_out)) *
        (Aenea_model_B.h_f_out - Aenea_model_B.h_c_out) + Aenea_model_B.h_c_out;
    }

    // End of Outputs for SubSystem: '<S442>/FLARE'

    // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' 
    switch (static_cast<int32_T>(Aenea_model_B.maneuver_selector)) {
     case 1:
      // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' incorporates:
      //   Constant: '<S442>/Constant6'

      Aenea_model_B.velocita = 20.0;
      break;

     case 2:
      // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' 
      Aenea_model_B.velocita = Aenea_model_B.Constant1_h;
      break;

     default:
      // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' 
      Aenea_model_B.velocita = Aenea_model_B.Constant1;
      break;
    }

    // End of MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation5' 

    // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' 
    switch (static_cast<int32_T>(Aenea_model_B.maneuver_selector)) {
     case 1:
      // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Constant: '<S442>/Constant2'

      Aenea_model_B.QUOTA_e = 45.0;
      break;

     case 2:
      // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Abs: '<S442>/Abs3'

      Aenea_model_B.QUOTA_e = std::abs(Aenea_model_B.Multiply);
      break;

     default:
      // MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' incorporates:
      //   Abs: '<S442>/Abs4'

      Aenea_model_B.QUOTA_e = std::abs(Aenea_model_B.Sum2);
      break;
    }

    // End of MultiPortSwitch: '<S442>/Switch di selezione  Task - Waypoint navigation4' 

    // Update for Memory: '<S442>/Memory5'
    Aenea_model_DW.Memory5_PreviousInput = Aenea_model_B.x_f_out;

    // Update for Memory: '<S442>/Memory1'
    Aenea_model_DW.Memory1_PreviousInput_f = Aenea_model_B.h_f_out;

    // Update for Memory: '<S442>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput_e = Aenea_model_B.no_solution;
  }

  // End of Outputs for SubSystem: '<S39>/Subsystem1'

  // S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S4>/S-Function' incorporates:
  //   Constant: '<S1>/SI UAV uint8'
  //   Constant: '<S21>/onboard_control_sensor_present uint32'

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
    &Aenea_model_B.DataTypeConversion1_j[0],
    &Aenea_model_B.DataTypeConversion2_p, &Aenea_model_B.AGAC[0],
    &Aenea_model_B.Heading_f, &Aenea_model_ConstB.Throttle,
    &Aenea_model_B.Heading[0], &Aenea_model_B.Memory_o,
    &Aenea_model_B.DataTypeConversion2, &Aenea_model_B.SFunction_o14,
    &Aenea_model_B.DataTypeConversion1_m, &Aenea_model_B.SFunction_o15,
    &Aenea_model_B.DataTypeConversion, &Aenea_model_B.DataTypeConversion1_e,
    &Aenea_model_B.DataTypeConversion2_m, &Aenea_model_B.SFunction_o5[0],
    &Aenea_model_B.Gain, &Aenea_model_B.Gain_o, &Aenea_model_B.h_Home, ((const
    uint16_T*) &Aenea_model_U16GND), &Aenea_model_B.SFunction_o1_i,
    &Aenea_model_B.SFunction_o2_h[0], &Aenea_model_B.SFunction_o3,
    &Aenea_model_B.SFunction_o4);

  // S-Function (enable_sfun): '<S4>/S-Function Builder'
  enable_sfun_Outputs_wrapper(&Aenea_model_B.SFunction_o1_i,
    &Aenea_model_B.SFunctionBuilder);

  // Outputs for Enabled SubSystem: '<S4>/Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  if (Aenea_model_B.SFunctionBuilder > 0) {
    // S-Function (MavLink_Send_sfun): '<S20>/S-Function Builder'
    MavLink_Send_sfun_Outputs_wrapper(&Aenea_model_B.SFunction_o2_h[0],
      &Aenea_model_B.SFunction_o3);
  }

  // End of Outputs for SubSystem: '<S4>/Subsystem'

  // DataTypeConversion: '<S3>/Data Tversion' incorporates:
  //   MATLAB Function: '<S3>/MATLAB Function1'

  for (Aenea_model_B.i = 0; Aenea_model_B.i < 42; Aenea_model_B.i++) {
    Aenea_model_B.DataTypeConversion4[Aenea_model_B.i] =
      Aenea_model_DW.WP_dbP[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S3>/Data Tversion'

  // DataTypeConversion: '<S575>/Data Type Conversion1' incorporates:
  //   UnitDelay: '<S575>/Unit Delay'

  for (Aenea_model_B.i = 0; Aenea_model_B.i < 9; Aenea_model_B.i++) {
    Aenea_model_DW.UnitDelay_DSTATE[Aenea_model_B.i] =
      Aenea_model_B.ByteReversal[Aenea_model_B.i];
  }

  // End of DataTypeConversion: '<S575>/Data Type Conversion1'

  // Outputs for Enabled SubSystem: '<S39>/Subsystem2' incorporates:
  //   EnablePort: '<S443>/Enable'

  if (Aenea_model_B.Wp_selector > 0.0) {
    // Gain: '<S544>/Gain'
    Aenea_model_B.Gain_hh = 57.295779513082323 * Aenea_model_B.Lat_K;

    // Gain: '<S545>/Gain'
    Aenea_model_B.Sum_h = 57.295779513082323 * Aenea_model_B.Long_K;

    // MATLAB Function: '<S443>/WAYPOINTS' incorporates:
    //   DataTypeConversion: '<S3>/Data Tversion'
    //   DataTypeConversion: '<S3>/Data Tversion1'
    //   DataTypeConversion: '<S3>/Data Tversion2'
    //   Memory: '<S443>/Memory4'

    Aenea_model_B.npad = 1;
    if (Aenea_model_DW.Memory4_PreviousInput == 6.0) {
      Aenea_model_B.npad = 0;
    }

    if (static_cast<uint8_T>(Aenea_model_B.GC_info[0]) == 3) {
      Aenea_model_DW.Memory4_PreviousInput = 1.0;
      Aenea_model_DW.lat1 = Aenea_model_B.Gain_hh;
      Aenea_model_DW.long1 = Aenea_model_B.Sum_h;
      for (Aenea_model_B.srem = 0; Aenea_model_B.srem < 6; Aenea_model_B.srem++)
      {
        if (Aenea_model_DW.WP_dbI[Aenea_model_B.srem + 24] == 1) {
          Aenea_model_DW.Memory4_PreviousInput = static_cast<real_T>
            (Aenea_model_B.srem) + 1.0;
        }
      }
    }

    Aenea_model_B.Wp_selector = Aenea_model_B.DataTypeConversion4
      [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 23];
    Aenea_model_B.Gain_dt = Aenea_model_B.DataTypeConversion4
      [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 29];
    Aenea_model_B.QUOTA = Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
      (Aenea_model_DW.Memory4_PreviousInput) + 35];
    Aenea_model_B.a_b = std::sin((Aenea_model_B.Wp_selector -
      Aenea_model_B.Gain_hh) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Gain_h = std::sin((Aenea_model_B.Gain_dt - Aenea_model_B.Sum_h)
      * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Al_selector = Aenea_model_B.Wp_selector * 3.1415926535897931 /
      180.0;
    Aenea_model_B.Switch_j = std::cos(Aenea_model_B.Al_selector);
    Aenea_model_B.Abs1_l = std::cos(Aenea_model_B.Gain_hh * 3.1415926535897931 /
      180.0);
    Aenea_model_B.a_b = Aenea_model_B.Abs1_l * Aenea_model_B.Switch_j *
      (Aenea_model_B.Gain_h * Aenea_model_B.Gain_h) + Aenea_model_B.a_b *
      Aenea_model_B.a_b;
    Aenea_model_B.Gain_h = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt
      (1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    if (Aenea_model_DW.Memory4_PreviousInput > 1.0) {
      Aenea_model_B.a_tmp_tmp = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23];
      Aenea_model_B.Al_selector = Aenea_model_B.a_tmp_tmp * 3.1415926535897931 /
        180.0;
      Aenea_model_B.a_b = std::cos(Aenea_model_B.Al_selector);
      Aenea_model_B.dist = Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
        (Aenea_model_DW.Memory4_PreviousInput - 1.0) + 29];
      Aenea_model_B.psi_ref_tmp = (Aenea_model_B.Gain_dt - Aenea_model_B.dist) *
        3.1415926535897931 / 180.0;
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
      Aenea_model_B.a_b = Aenea_model_B.a_b * Aenea_model_B.Abs1_l *
        (Aenea_model_B.dist * Aenea_model_B.dist) + Aenea_model_B.a_tmp_tmp *
        Aenea_model_B.a_tmp_tmp;
      Aenea_model_B.dist = rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt
        (1.0 - Aenea_model_B.a_b)) * 2.0 * 6.378137E+6;
    } else {
      Aenea_model_B.a_b = (Aenea_model_B.Gain_dt - Aenea_model_DW.long1) *
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

    if (Aenea_model_B.npad == 1) {
      Aenea_model_B.psi_ref_tmp = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput + 1.0) + 23];
      Aenea_model_B.a_tmp_tmp = std::sin((Aenea_model_B.psi_ref_tmp -
        Aenea_model_B.Wp_selector) * 3.1415926535897931 / 180.0 / 2.0);
      Aenea_model_B.b_a_tmp = (Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput + 1.0) + 29]
        - Aenea_model_B.Gain_dt) * 3.1415926535897931 / 180.0;
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
      Aenea_model_B.Abs1_l = 0.0;
    } else if (Aenea_model_DW.Memory4_PreviousInput == 2.0) {
      Aenea_model_B.a_b = Aenea_model_B.DataTypeConversion4[24] *
        3.1415926535897931 / 180.0;
      Aenea_model_B.b_a_tmp = std::cos(Aenea_model_B.a_b);
      Aenea_model_B.Gain_hh = (Aenea_model_B.DataTypeConversion4[30] -
        Aenea_model_DW.long1) * 3.1415926535897931 / 180.0;
      Aenea_model_B.Abs1_l = std::abs(Aenea_model_B.Al_selector - rt_atan2d_snf
        (std::sin(Aenea_model_B.Gain_hh) * Aenea_model_B.b_a_tmp, std::cos
         (Aenea_model_DW.lat1 * 3.1415926535897931 / 180.0) * std::sin
         (Aenea_model_B.a_b) - std::sin(Aenea_model_DW.lat1 * 3.1415926535897931
        / 180.0) * Aenea_model_B.b_a_tmp * std::cos(Aenea_model_B.Gain_hh)) *
        180.0 / 3.1415926535897931);
    } else {
      Aenea_model_B.Abs1_l = std::cos(Aenea_model_B.DataTypeConversion4[
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
      Aenea_model_B.Abs1_l = rt_atan2d_snf(std::sin(Aenea_model_B.Gain_hh) *
        Aenea_model_B.Abs1_l, std::cos(Aenea_model_B.Sum_h) * std::sin
        (Aenea_model_B.DataTypeConversion4[static_cast<int32_T>
         (Aenea_model_DW.Memory4_PreviousInput - 1.0) + 23] * 3.1415926535897931
         / 180.0) - std::sin(Aenea_model_B.Sum_h) * Aenea_model_B.Abs1_l * std::
        cos(Aenea_model_B.Gain_hh)) * 180.0 / 3.1415926535897931;
      if (Aenea_model_B.Abs1_l < 0.0) {
        Aenea_model_B.Abs1_l = 360.0 - std::abs(Aenea_model_B.Abs1_l);
      }

      Aenea_model_B.Abs1_l = std::abs(Aenea_model_B.Al_selector -
        Aenea_model_B.Abs1_l);
    }

    if (Aenea_model_B.Switch_j <= 10.0) {
      Aenea_model_B.Switch_j = 40.0;
      Aenea_model_B.srem = 10;
    } else if ((Aenea_model_B.Switch_j > 10.0) && (Aenea_model_B.Switch_j <=
                50.0)) {
      Aenea_model_B.Switch_j = 60.0;
      Aenea_model_B.srem = 15;
    } else if ((Aenea_model_B.Switch_j > 50.0) && (Aenea_model_B.Switch_j <=
                90.0)) {
      Aenea_model_B.Switch_j = 80.0;
      Aenea_model_B.srem = 20;
    } else if ((Aenea_model_B.Switch_j > 90.0) && (Aenea_model_B.Switch_j <=
                120.0)) {
      Aenea_model_B.Switch_j = 120.0;
      Aenea_model_B.srem = 25;
    } else {
      Aenea_model_B.Switch_j = 150.0;
      Aenea_model_B.srem = 30;
    }

    if (Aenea_model_B.Abs1_l <= 10.0) {
      Aenea_model_B.soglia_dist = 50;
    } else if ((Aenea_model_B.Abs1_l > 10.0) && (Aenea_model_B.Abs1_l <= 50.0))
    {
      Aenea_model_B.soglia_dist = 200;
    } else if ((Aenea_model_B.Abs1_l > 50.0) && (Aenea_model_B.Abs1_l <= 90.0))
    {
      Aenea_model_B.soglia_dist = 300;
    } else if ((Aenea_model_B.Abs1_l > 90.0) && (Aenea_model_B.Abs1_l <= 120.0))
    {
      Aenea_model_B.soglia_dist = 350;
    } else {
      Aenea_model_B.soglia_dist = 400;
    }

    if (Aenea_model_B.npad == 1) {
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
           (!(Aenea_model_B.Gain_h > Aenea_model_B.Switch_j))) &&
          ((!(Aenea_model_B.dist > Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_B.Gain_h > Aenea_model_B.Switch_j))) &&
          (Aenea_model_B.Gain_h < Aenea_model_B.Switch_j)) {
        if (Aenea_model_B.dist_fut > Aenea_model_B.srem) {
          Aenea_model_DW.Memory4_PreviousInput++;
        } else if (Aenea_model_DW.Memory4_PreviousInput < 5.0) {
          Aenea_model_DW.Memory4_PreviousInput += 2.0;
        } else {
          Aenea_model_B.VELOCITA = 22.0;
          Aenea_model_B.QUOTA = Aenea_model_B.Alt + 0.4;
        }
      }

      Aenea_model_DW.flag_o = 0.0;
    } else {
      Aenea_model_B.VELOCITA = Aenea_model_B.DataTypeConversion4
        [static_cast<int32_T>(Aenea_model_DW.Memory4_PreviousInput) + 11];
      if (Aenea_model_B.VELOCITA < 15.0) {
        Aenea_model_B.VELOCITA = 25.0;
      }

      if (((!(Aenea_model_B.dist < Aenea_model_B.soglia_dist)) ||
           (!(Aenea_model_DW.flag_o == 0.0))) && ((!(Aenea_model_B.dist >
             Aenea_model_B.soglia_dist)) || (!(Aenea_model_B.Gain_h > 40.0)) ||
           (!(Aenea_model_DW.flag_o == 0.0)))) {
        Aenea_model_B.VELOCITA = 22.0;
        Aenea_model_B.QUOTA = Aenea_model_B.Alt + 0.4;
        Aenea_model_DW.flag_o = 1.0;
      }
    }

    if ((Aenea_model_B.Wp_selector == 0.0) && (Aenea_model_B.Gain_dt == 0.0) &&
        (Aenea_model_B.QUOTA == 0.0)) {
      Aenea_model_B.QUOTA = Aenea_model_B.Alt + 0.3;
      Aenea_model_B.VELOCITA = 22.0;
    }

    // Saturate: '<S443>/saturatore V' incorporates:
    //   MATLAB Function: '<S443>/WAYPOINTS'

    if (Aenea_model_B.VELOCITA > 40.0) {
      // Saturate: '<S443>/saturatore V'
      Aenea_model_B.VELOCITA = 40.0;
    } else {
      if (Aenea_model_B.VELOCITA < 15.0) {
        // Saturate: '<S443>/saturatore V'
        Aenea_model_B.VELOCITA = 15.0;
      }
    }

    // End of Saturate: '<S443>/saturatore V'
  }

  // End of Outputs for SubSystem: '<S39>/Subsystem2'

  // Outputs for Enabled SubSystem: '<S39>/Subsystem' incorporates:
  //   EnablePort: '<S441>/Enable'

  if (Aenea_model_B.Vec_selector > 0.0) {
    // MATLAB Function: '<S441>/VETTORIALE' incorporates:
    //   MATLAB Function: '<S3>/MATLAB Function1'
    //   Memory: '<S441>/Memory1'
    //   Memory: '<S441>/Memory2'
    //   Memory: '<S441>/Memory3'
    //   Memory: '<S441>/Memory6'

    if ((Aenea_model_DW.Memory2_PreviousInput_d[1] !=
         Aenea_model_DW.Memory6_PreviousInput) || (Aenea_model_B.modo !=
         Aenea_model_DW.Memory3_PreviousInput) ||
        (Aenea_model_DW.Memory2_PreviousInput_d[3] !=
         Aenea_model_DW.Memory2_PreviousInput_d2)) {
      Aenea_model_DW.V_ref = Aenea_model_B.olddi;
    }

    if ((Aenea_model_DW.Memory2_PreviousInput_d[1] !=
         Aenea_model_DW.Memory6_PreviousInput) || (Aenea_model_B.modo !=
         Aenea_model_DW.Memory3_PreviousInput) ||
        (Aenea_model_DW.Memory2_PreviousInput_d[4] !=
         Aenea_model_DW.Memory1_PreviousInput_k)) {
      Aenea_model_DW.ALT_ref = Aenea_model_B.Alt;
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

    // Update for Memory: '<S441>/Memory1' incorporates:
    //   MATLAB Function: '<S441>/VETTORIALE'

    Aenea_model_DW.Memory1_PreviousInput_k =
      Aenea_model_DW.Memory2_PreviousInput_d[4];

    // Update for Memory: '<S441>/Memory2' incorporates:
    //   MATLAB Function: '<S441>/VETTORIALE'

    Aenea_model_DW.Memory2_PreviousInput_d2 =
      Aenea_model_DW.Memory2_PreviousInput_d[3];

    // Update for Memory: '<S441>/Memory3' incorporates:
    //   MATLAB Function: '<S441>/VETTORIALE'

    Aenea_model_DW.Memory3_PreviousInput = Aenea_model_B.modo;

    // Update for Memory: '<S441>/Memory6' incorporates:
    //   MATLAB Function: '<S441>/VETTORIALE'

    Aenea_model_DW.Memory6_PreviousInput =
      Aenea_model_DW.Memory2_PreviousInput_d[1];
  }

  // End of Outputs for SubSystem: '<S39>/Subsystem'

  // Outputs for Enabled SubSystem: '<S39>/Subsystem3' incorporates:
  //   EnablePort: '<S444>/Enable'

  if (Aenea_model_B.Go_home_selector > 0.0) {
    // Gain: '<S549>/Gain'
    Aenea_model_B.Vec_selector = 57.295779513082323 * Aenea_model_B.Lat_K;

    // MATLAB Function: '<S444>/GO_HOME' incorporates:
    //   Constant: '<S39>/Constant'
    //   Constant: '<S39>/Constant1'
    //   Gain: '<S550>/Gain'

    Aenea_model_B.a_b = std::sin((0.0 - Aenea_model_B.Vec_selector) *
      3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.Gain_h = std::sin((0.0 - 57.295779513082323 *
      Aenea_model_B.Long_K) * 3.1415926535897931 / 180.0 / 2.0);
    Aenea_model_B.a_b = std::cos(Aenea_model_B.Vec_selector * 3.1415926535897931
      / 180.0) * (Aenea_model_B.Gain_h * Aenea_model_B.Gain_h) +
      Aenea_model_B.a_b * Aenea_model_B.a_b;
    Aenea_model_B.h_goHome = 70.0;
    Aenea_model_B.V_goHome = 20.0;
    if ((rt_atan2d_snf(std::sqrt(Aenea_model_B.a_b), std::sqrt(1.0 -
           Aenea_model_B.a_b)) * 2.0 * 6.378137E+6 < 30.0) &&
        (Aenea_model_DW.flag == 0.0)) {
      Aenea_model_DW.flag = 1.0;
      Aenea_model_B.h_goHome = 70.4;
    }

    // End of MATLAB Function: '<S444>/GO_HOME'
  }

  // End of Outputs for SubSystem: '<S39>/Subsystem3'

  // MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation1'
  switch (static_cast<int32_T>(Aenea_model_B.modo)) {
   case 1:
    Aenea_model_B.Gain_h = Aenea_model_B.VELOCITA;
    break;

   case 2:
    Aenea_model_B.Gain_h = Aenea_model_B.V_vett;
    break;

   case 3:
    Aenea_model_B.Gain_h = Aenea_model_B.Tas_ref;
    break;

   case 4:
    Aenea_model_B.Gain_h = Aenea_model_B.velocita;
    break;

   default:
    Aenea_model_B.Gain_h = Aenea_model_B.V_goHome;
    break;
  }

  // End of MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation1' 

  // Sum: '<S42>/Sum3'
  Aenea_model_B.Gain_h -= Aenea_model_B.olddi;

  // Sum: '<S294>/Sum' incorporates:
  //   DiscreteIntegrator: '<S285>/Integrator'
  //   Product: '<S290>/PProd Out'

  Aenea_model_B.Gain_dt = Aenea_model_B.Gain_h * 0.033649999648332596 +
    Aenea_model_DW.Integrator_DSTATE_lq;

  // Saturate: '<S292>/Saturation'
  if (Aenea_model_B.Gain_dt > 1.0) {
    Aenea_model_B.Vec_selector = 1.0;
  } else if (Aenea_model_B.Gain_dt < 0.0) {
    Aenea_model_B.Vec_selector = 0.0;
  } else {
    Aenea_model_B.Vec_selector = Aenea_model_B.Gain_dt;
  }

  // End of Saturate: '<S292>/Saturation'

  // DigitalClock: '<S250>/Digital Clock1'
  Aenea_model_B.Go_home_selector = ((Aenea_model_M->Timing.clockTick0) * 0.02);

  // MATLAB Function: '<S250>/Smooth Bypass' incorporates:
  //   Product: '<S592>/Multiply1'
  //   SignalConversion generated from: '<S250>/Vector Concatenate'

  if (Aenea_model_B.switch_manetta == 0.0) {
    Aenea_model_B.Abs1_l = Aenea_model_B.Vec_selector;
    Aenea_model_DW.Delay_DSTATE = Aenea_model_B.Go_home_selector;
  } else {
    if (Aenea_model_B.switch_manetta != Aenea_model_B.switch_manetta) {
      Aenea_model_DW.Delay_DSTATE = Aenea_model_B.Go_home_selector;
    }

    Aenea_model_B.Go_home_selector -= Aenea_model_DW.Delay_DSTATE;
    if (Aenea_model_B.Go_home_selector < 1.3) {
      if (Aenea_model_B.Go_home_selector < 0.2) {
        Aenea_model_B.Abs1_l = Aenea_model_ConstB.Divide2;
      } else {
        Aenea_model_B.Abs1_l = (Aenea_model_B.Go_home_selector - 0.2) / 1.1 *
          (Aenea_model_B.Vec_selector - Aenea_model_ConstB.Divide2) +
          Aenea_model_ConstB.Divide2;
      }
    } else {
      Aenea_model_B.Abs1_l = Aenea_model_B.Vec_selector;
    }
  }

  // End of MATLAB Function: '<S250>/Smooth Bypass'

  // MultiPortSwitch: '<S250>/Switch Bumpless 1' incorporates:
  //   Product: '<S592>/Multiply1'

  if (static_cast<int32_T>(Aenea_model_B.switch_manetta) == 0) {
    Aenea_model_B.Abs1_l = Aenea_model_ConstB.Divide2;
  }

  // End of MultiPortSwitch: '<S250>/Switch Bumpless 1'

  // MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2'
  switch (static_cast<int32_T>(Aenea_model_B.modo)) {
   case 1:
    Aenea_model_B.Go_home_selector = Aenea_model_B.QUOTA;
    break;

   case 2:
    Aenea_model_B.Go_home_selector = Aenea_model_B.h_vett;
    break;

   case 3:
    Aenea_model_B.Go_home_selector = Aenea_model_B.h_ref;
    break;

   case 4:
    Aenea_model_B.Go_home_selector = Aenea_model_B.QUOTA_e;
    break;

   default:
    Aenea_model_B.Go_home_selector = Aenea_model_B.h_goHome;
    break;
  }

  // End of MultiPortSwitch: '<S39>/Switch di selezione  Task - Waypoint navigation2' 

  // HitCross: '<S251>/Hit  Crossing'
  Aenea_model_B.zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
    &Aenea_model_PrevZCX.HitCrossing_Input_ZCE,
    (Aenea_model_B.Go_home_selector - 0.3));
  if (Aenea_model_DW.HitCrossing_MODE == 0) {
    if (Aenea_model_B.zcEvent != NO_ZCEVENT) {
      // HitCross: '<S251>/Hit  Crossing'
      Aenea_model_B.HitCrossing = !Aenea_model_B.HitCrossing;
      Aenea_model_DW.HitCrossing_MODE = 1;
    } else {
      if (Aenea_model_B.HitCrossing) {
        // HitCross: '<S251>/Hit  Crossing'
        Aenea_model_B.HitCrossing = ((!(Aenea_model_B.Go_home_selector != 0.3)) &&
          Aenea_model_B.HitCrossing);
      }
    }
  } else {
    // HitCross: '<S251>/Hit  Crossing'
    Aenea_model_B.HitCrossing = ((!(Aenea_model_B.Go_home_selector != 0.3)) &&
      Aenea_model_B.HitCrossing);
    Aenea_model_DW.HitCrossing_MODE = 0;
  }

  // End of HitCross: '<S251>/Hit  Crossing'

  // Outputs for Triggered SubSystem: '<S251>/Enabled Subsystem' incorporates:
  //   TriggerPort: '<S303>/Trigger'

  if (Aenea_model_B.HitCrossing &&
      (Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE != 1)) {
    // SignalConversion generated from: '<S303>/Out1' incorporates:
    //   Constant: '<S303>/Constant'

    Aenea_model_B.OutportBufferForOut1 = 0.0;
  }

  Aenea_model_PrevZCX.EnabledSubsystem_Trig_ZCE = Aenea_model_B.HitCrossing;

  // End of Outputs for SubSystem: '<S251>/Enabled Subsystem'

  // MultiPortSwitch: '<S36>/Switch di selezione riferimeti  per i loop interni 1' 
  if (static_cast<int32_T>(Aenea_model_B.Switch_e) == 0) {
    // MultiPortSwitch: '<S251>/throttle - landing' incorporates:
    //   MATLAB Function: '<S38>/MATLAB Function'

    if (Aenea_model_B.b_k != 0) {
      // Switch: '<S251>/Switch' incorporates:
      //   Constant: '<S251>/Constant3'

      if (!(Aenea_model_B.OutportBufferForOut1 > 0.0)) {
        Aenea_model_B.Abs1_l = 0.0;
      }

      // End of Switch: '<S251>/Switch'
    }

    // End of MultiPortSwitch: '<S251>/throttle - landing'
  } else {
    Aenea_model_B.Abs1_l = Aenea_model_B.throttle_safe;
  }

  // End of MultiPortSwitch: '<S36>/Switch di selezione riferimeti  per i loop interni 1' 

  // DiscreteIntegrator: '<S307>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S307>/Constant8'
  //   Sum: '<S307>/Sum'

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

  // MultiPortSwitch: '<S307>/Multiport Switch1' incorporates:
  //   MATLAB Function: '<S38>/MATLAB Function'

  if (Aenea_model_B.idx != 0) {
    // MultiPortSwitch: '<S307>/Switch Bumpless 1' incorporates:
    //   Constant: '<S307>/Constant4'
    //   DiscreteIntegrator: '<S307>/Discrete-Time Integrator'

    switch (static_cast<int32_T>(Aenea_model_B.Fase_ATO)) {
     case 0:
      Aenea_model_B.Abs1_l = 0.0;
      break;

     case 1:
      Aenea_model_B.Abs1_l = Aenea_model_B.manetta_ref;
      break;

     case 2:
      Aenea_model_B.Abs1_l = Aenea_model_DW.DiscreteTimeIntegrator_DSTATE;
      break;

     case 3:
      break;
    }

    // End of MultiPortSwitch: '<S307>/Switch Bumpless 1'
  }

  // End of MultiPortSwitch: '<S307>/Multiport Switch1'
  if (Aenea_model_M->Timing.TaskCounters.TID[2] == 0) {
    // Switch: '<S584>/FixPt Switch' incorporates:
    //   Constant: '<S583>/FixPt Constant'
    //   Constant: '<S584>/Constant'
    //   Sum: '<S583>/FixPt Sum1'
    //   UnitDelay: '<S573>/Output'

    if (static_cast<uint8_T>(Aenea_model_DW.Output_DSTATE + 1U) > 1) {
      Aenea_model_DW.Output_DSTATE = 0U;
    } else {
      Aenea_model_DW.Output_DSTATE = static_cast<uint8_T>
        (Aenea_model_DW.Output_DSTATE + 1U);
    }

    // End of Switch: '<S584>/FixPt Switch'
  }

  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    // Switch: '<S27>/Switch1' incorporates:
    //   Constant: '<S27>/Constant4'
    //   Constant: '<S27>/Constant5'
    //   Memory: '<S27>/Memory2'
    //   Sum: '<S27>/Add2'

    if (Aenea_model_DW.Memory2_PreviousInput + 1.0 > 9.0) {
      Aenea_model_B.Switch1_g = 0.0;
    } else {
      Aenea_model_B.Switch1_g = Aenea_model_DW.Memory2_PreviousInput + 1.0;
    }

    // End of Switch: '<S27>/Switch1'
  }

  // Abs: '<S40>/Abs' incorporates:
  //   Sum: '<S40>/Sum1'

  Aenea_model_B.Go_home_selector = std::abs(Aenea_model_B.Go_home_selector -
    Aenea_model_B.Alt);

  // Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT'
  if (Aenea_model_DW.is_active_c23_Aenea_model == 0U) {
    Aenea_model_DW.is_active_c23_Aenea_model = 1U;
    Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Select;
  } else if (Aenea_model_DW.is_c23_Aenea_model == 1) {
    if (Aenea_model_B.Go_home_selector > 10.0) {
      Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Select;
    }
  } else {
    // case IN_Select:
    if (Aenea_model_B.Go_home_selector < 10.0) {
      Aenea_model_DW.is_c23_Aenea_model = Aenea_model_IN_Hold;
    }
  }

  // End of Chart: '<S40>/SELEZIONE MODALITA'  HOLD//SELECT'

  // Gain: '<S276>/ZeroGain'
  Aenea_model_B.Go_home_selector = 0.0 * Aenea_model_B.Gain_dt;

  // DeadZone: '<S278>/DeadZone'
  if (Aenea_model_B.Gain_dt > 1.0) {
    Aenea_model_B.Gain_dt--;
  } else {
    if (Aenea_model_B.Gain_dt >= 0.0) {
      Aenea_model_B.Gain_dt = 0.0;
    }
  }

  // End of DeadZone: '<S278>/DeadZone'

  // RelationalOperator: '<S276>/NotEqual'
  Ap_sel = (Aenea_model_B.Go_home_selector != Aenea_model_B.Gain_dt);

  // Signum: '<S276>/SignPreSat'
  if (Aenea_model_B.Gain_dt < 0.0) {
    Aenea_model_B.Gain_dt = -1.0;
  } else if (Aenea_model_B.Gain_dt > 0.0) {
    Aenea_model_B.Gain_dt = 1.0;
  } else if (Aenea_model_B.Gain_dt == 0.0) {
    Aenea_model_B.Gain_dt = 0.0;
  } else {
    Aenea_model_B.Gain_dt = (rtNaN);
  }

  // End of Signum: '<S276>/SignPreSat'

  // DataTypeConversion: '<S276>/DataTypeConv1'
  if (rtIsNaN(Aenea_model_B.Gain_dt)) {
    Aenea_model_B.a_b = 0.0;
  } else {
    Aenea_model_B.a_b = std::fmod(Aenea_model_B.Gain_dt, 256.0);
  }

  // Sum: '<S297>/SumI1' incorporates:
  //   Product: '<S282>/IProd Out'
  //   Sum: '<S296>/SumI3'

  Aenea_model_B.Gain_dt = Aenea_model_B.Gain_h * 0.00800000037997961 +
    (Aenea_model_B.Abs1_l - Aenea_model_B.Vec_selector);

  // Product: '<S389>/IProd Out'
  Aenea_model_B.Gain_h = Aenea_model_B.e * 0.25;

  // Sum: '<S404>/SumI1' incorporates:
  //   Sum: '<S403>/SumI3'

  Aenea_model_B.Alettoni = (Aenea_model_B.Alettoni - Aenea_model_B.Saturation_a)
    + Aenea_model_B.Gain_h;

  // Outputs for Resettable SubSystem: '<S410>/Resettable Subsystem'
  Aenea_model_ResettableSubsystem(Aenea_model_B.SFunction_o4_a[1],
    &Aenea_model_B.Gain_h, &Aenea_model_DW.ResettableSubsystem,
    &Aenea_model_PrevZCX.ResettableSubsystem);

  // End of Outputs for SubSystem: '<S410>/Resettable Subsystem'

  // Outputs for Enabled SubSystem: '<S410>/Enabled Subsystem'
  Aenea_model_EnabledSubsystem(Aenea_model_B.SFunction_o4_a[1],
    Aenea_model_B.Gain_h, &Aenea_model_B.e);

  // End of Outputs for SubSystem: '<S410>/Enabled Subsystem'

  // MATLAB Function: '<S412>/MATLAB Function1'
  Aenea_model_DW.Tf_not_empty = ((!Aenea_model_DW.Tf_not_empty) ||
    (Aenea_model_DW.Memory2_PreviousInput_d[0] == 1) ||
    (Aenea_model_DW.Memory2_PreviousInput_d[1] == 0) ||
    Aenea_model_DW.Tf_not_empty);

  // Sum: '<S561>/Sum1' incorporates:
  //   MATLAB Function: '<S561>/MATLAB Function'
  //   Product: '<S561>/Product4'
  //   UnitDelay: '<S561>/Unit Delay'

  Aenea_model_DW.UnitDelay_DSTATE_c = 0.23456790123456794 * Aenea_model_B.Sum_l
    + Aenea_model_B.SFunctionBuilder_o1;

  // Sum: '<S612>/Sum' incorporates:
  //   Constant: '<S612>/Constant8'
  //   UnitDelay: '<S612>/Unit Delay'

  Aenea_model_DW.UnitDelay_DSTATE_n += 0.02;

  // RelationalOperator: '<S597>/Compare' incorporates:
  //   Constant: '<S597>/Constant'
  //   UnitDelay: '<S598>/Output'

  Aenea_model_B.Compare_i = (Aenea_model_DW.Output_DSTATE_k == 50);

  // BusCreator: '<S2>/Bus Creator1' incorporates:
  //   BusCreator: '<S600>/Bus Creator3'
  //   BusCreator: '<S601>/Bus Creator7'
  //   BusCreator: '<S602>/Bus Creator5'
  //   BusCreator: '<S606>/Bus Creator6'
  //   Constant: '<S602>/Constant18'
  //   Constant: '<S602>/Constant9'
  //   Constant: '<S606>/Constant19'
  //   Constant: '<S606>/Constant20'
  //   Constant: '<S7>/Constant3'
  //   Constant: '<S9>/Constant2'
  //   Constant: '<S9>/Constant4'
  //   Constant: '<S9>/Constant6'
  //   Constant: '<S9>/Constant7'
  //   DataTypeConversion: '<S578>/Data Type Conversion'
  //   DataTypeConversion: '<S578>/Data Type Conversion1'
  //   DataTypeConversion: '<S578>/Data Type Conversion2'
  //   DataTypeConversion: '<S604>/Data Type Conversion'
  //   DataTypeConversion: '<S604>/Data Type Conversion1'
  //   DataTypeConversion: '<S604>/Data Type Conversion10'
  //   DataTypeConversion: '<S604>/Data Type Conversion11'
  //   DataTypeConversion: '<S604>/Data Type Conversion12'
  //   DataTypeConversion: '<S604>/Data Type Conversion13'
  //   DataTypeConversion: '<S604>/Data Type Conversion14'
  //   DataTypeConversion: '<S604>/Data Type Conversion15'
  //   DataTypeConversion: '<S604>/Data Type Conversion16'
  //   DataTypeConversion: '<S604>/Data Type Conversion17'
  //   DataTypeConversion: '<S604>/Data Type Conversion18'
  //   DataTypeConversion: '<S604>/Data Type Conversion19'
  //   DataTypeConversion: '<S604>/Data Type Conversion2'
  //   DataTypeConversion: '<S604>/Data Type Conversion23'
  //   DataTypeConversion: '<S604>/Data Type Conversion3'
  //   DataTypeConversion: '<S604>/Data Type Conversion4'
  //   DataTypeConversion: '<S604>/Data Type Conversion5'
  //   DataTypeConversion: '<S604>/Data Type Conversion6'
  //   DataTypeConversion: '<S604>/Data Type Conversion7'
  //   DataTypeConversion: '<S604>/Data Type Conversion8'
  //   DataTypeConversion: '<S604>/Data Type Conversion9'
  //   Gain: '<S610>/Gain'
  //   Gain: '<S611>/Gain'
  //   UnitDelay: '<S574>/Unit Delay'
  //   UnitDelay: '<S612>/Unit Delay'

  Aenea_model_B.BusCreator1.double_data.time_frame =
    Aenea_model_DW.UnitDelay_DSTATE_n;
  Aenea_model_B.BusCreator1.double_data.Lat_raw =
    Aenea_model_DW.UnitDelay_DSTATE_h[0];
  Aenea_model_B.BusCreator1.double_data.Long_raw =
    Aenea_model_DW.UnitDelay_DSTATE_h[1];
  Aenea_model_B.BusCreator1.double_data.Lat = 57.295779513082323 *
    Aenea_model_B.Lat_K;
  Aenea_model_B.BusCreator1.double_data.Long = 57.295779513082323 *
    Aenea_model_B.Long_K;
  Aenea_model_B.BusCreator1.single_data.v_gps_raw = static_cast<real32_T>
    (Aenea_model_DW.UnitDelay_DSTATE_h[2]);
  Aenea_model_B.BusCreator1.single_data.h_gps_raw = static_cast<real32_T>
    (Aenea_model_DW.UnitDelay_DSTATE_h[3]);
  Aenea_model_B.BusCreator1.single_data.heading_raw = static_cast<real32_T>
    (Aenea_model_DW.UnitDelay_DSTATE_h[4]);
  Aenea_model_B.BusCreator1.single_data.acc_x_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[0]);
  Aenea_model_B.BusCreator1.single_data.acc_y_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[1]);
  Aenea_model_B.BusCreator1.single_data.acc_z_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[2]);
  Aenea_model_B.BusCreator1.single_data.p_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[3]);
  Aenea_model_B.BusCreator1.single_data.q_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[4]);
  Aenea_model_B.BusCreator1.single_data.r_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[5]);
  Aenea_model_B.BusCreator1.single_data.phi_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[6]);
  Aenea_model_B.BusCreator1.single_data.theta_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[7]);
  Aenea_model_B.BusCreator1.single_data.psi_raw = static_cast<real32_T>
    (Aenea_model_B.DataTypeConversion1_c[8]);
  Aenea_model_B.BusCreator1.single_data.v_pitot_raw = static_cast<real32_T>
    (Aenea_model_B.SFunctionBuilder_o1);
  Aenea_model_B.BusCreator1.single_data.dist_lidar_raw = 0.0F;

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  Aenea_model_B.BusCreator1.single_data.h_baro_raw =
    Aenea_model_B.SFunctionBuilder_o3_h;
  Aenea_model_B.BusCreator1.single_data.press_raw =
    Aenea_model_B.SFunctionBuilder_o2_p;
  Aenea_model_B.BusCreator1.single_data.temp_raw =
    Aenea_model_B.SFunctionBuilder_o1_g;

  // End of Outputs for SubSystem: '<S571>/Execution_loop'
  Aenea_model_B.BusCreator1.single_data.h_baro_filt = static_cast<real32_T>
    (Aenea_model_B.Alt);
  Aenea_model_B.BusCreator1.single_data.ias_filt = static_cast<real32_T>
    (Aenea_model_B.olddi);
  Aenea_model_B.BusCreator1.single_data.RC_filt = static_cast<real32_T>
    (Aenea_model_B.vd_K);
  Aenea_model_B.BusCreator1.single_data.groundspeed_filt = static_cast<real32_T>
    (Aenea_model_B.v_K);
  Aenea_model_B.BusCreator1.single_data.heading_filt = static_cast<real32_T>
    (Aenea_model_B.imbardata);
  Aenea_model_B.BusCreator1.single_data.dist_lidar_filt = 0.0F;
  Aenea_model_B.BusCreator1.single_data.dp_raw = static_cast<real32_T>
    (Aenea_model_B.SFunctionBuilder_o3);
  Aenea_model_B.BusCreator1.int32_data.dummy3 = 528;
  Aenea_model_B.BusCreator1.int32_data.dummy4 = -15;
  Aenea_model_B.BusCreator1.uint32_data.dummy5 = 15U;
  Aenea_model_B.BusCreator1.uint32_data.dummy6 = 1078U;
  Aenea_model_B.BusCreator1.int16_data.manual_throttleCmd_pwm = 1;
  Aenea_model_B.BusCreator1.int16_data.manual_elevatorCmd_pwm = 1;
  Aenea_model_B.BusCreator1.int16_data.manual_aileronCmd_pwm = 1;
  Aenea_model_B.BusCreator1.int16_data.manual_rudderCmd_pwm = 1;

  // Sum: '<S595>/Sum' incorporates:
  //   Product: '<S592>/Multiply1'
  //   Product: '<S595>/Multiply'

  Aenea_model_B.e = std::floor(Aenea_model_ConstB.Divide2 *
    Aenea_model_ConstB.Sum1_j);
  if (rtIsNaN(Aenea_model_B.e) || rtIsInf(Aenea_model_B.e)) {
    Aenea_model_B.e = 0.0;
  } else {
    Aenea_model_B.e = std::fmod(Aenea_model_B.e, 65536.0);
  }

  // BusCreator: '<S2>/Bus Creator1' incorporates:
  //   Constant: '<S7>/Constant6'
  //   Sum: '<S595>/Sum'

  Aenea_model_B.BusCreator1.int16_data.throttleCmd_pwm = static_cast<int16_T>
    ((Aenea_model_B.e < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
        static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.e)))) :
      static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
        (Aenea_model_B.e)))) + 1099);

  // DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
  //   Constant: '<S596>/Constant'
  //   Constant: '<S596>/Constant1'
  //   Constant: '<S7>/Constant7'
  //   Product: '<S596>/Divide'
  //   Product: '<S596>/Multiply'
  //   Sum: '<S596>/Sum'
  //   Sum: '<S596>/Sum1'
  //   Sum: '<S596>/Sum3'

  Aenea_model_B.e = std::floor((Aenea_model_B.Sum3 - -0.55850536063818546) /
    0.87266462599716477 * Aenea_model_ConstB.Sum2_d + 952.0);
  if (rtIsNaN(Aenea_model_B.e) || rtIsInf(Aenea_model_B.e)) {
    Aenea_model_B.e = 0.0;
  } else {
    Aenea_model_B.e = std::fmod(Aenea_model_B.e, 65536.0);
  }

  // BusCreator: '<S2>/Bus Creator1' incorporates:
  //   DataTypeConversion: '<S10>/Data Type Conversion'

  Aenea_model_B.BusCreator1.int16_data.elevatorCmd_pwm = static_cast<int16_T>
    (Aenea_model_B.e < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.e)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.e))));

  // DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
  //   Constant: '<S593>/Constant'
  //   Constant: '<S593>/Constant1'
  //   Constant: '<S7>/Constant10'
  //   Product: '<S593>/Divide'
  //   Product: '<S593>/Multiply'
  //   Sum: '<S593>/Sum'
  //   Sum: '<S593>/Sum1'
  //   Sum: '<S593>/Sum3'

  Aenea_model_B.e = std::floor((Aenea_model_B.Alettoni_n - -0.4014257279586958) /
    0.87266462599716477 * Aenea_model_ConstB.Sum2_a + 1104.0);
  if (rtIsNaN(Aenea_model_B.e) || rtIsInf(Aenea_model_B.e)) {
    Aenea_model_B.e = 0.0;
  } else {
    Aenea_model_B.e = std::fmod(Aenea_model_B.e, 65536.0);
  }

  // BusCreator: '<S2>/Bus Creator1' incorporates:
  //   DataTypeConversion: '<S10>/Data Type Conversion1'

  Aenea_model_B.BusCreator1.int16_data.aileronCmd_pwm = static_cast<int16_T>
    (Aenea_model_B.e < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.e)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.e))));

  // DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
  //   Constant: '<S594>/Constant'
  //   Constant: '<S594>/Constant1'
  //   Constant: '<S7>/Constant12'
  //   Product: '<S594>/Divide'
  //   Product: '<S594>/Multiply'
  //   Sum: '<S594>/Sum'
  //   Sum: '<S594>/Sum1'
  //   Sum: '<S594>/Sum3'

  Aenea_model_B.e = std::floor((Aenea_model_B.Sum2_k2 - -0.52359877559829882) /
    1.0471975511965976 * Aenea_model_ConstB.Sum2_g + 1233.0);
  if (rtIsNaN(Aenea_model_B.e) || rtIsInf(Aenea_model_B.e)) {
    Aenea_model_B.e = 0.0;
  } else {
    Aenea_model_B.e = std::fmod(Aenea_model_B.e, 65536.0);
  }

  // BusCreator: '<S2>/Bus Creator1' incorporates:
  //   BusCreator: '<S603>/Bus Creator9'
  //   BusCreator: '<S605>/Bus Creator8'
  //   Constant: '<S603>/Constant14'
  //   Constant: '<S603>/Constant23'
  //   Constant: '<S605>/Constant11'
  //   Constant: '<S605>/Constant22'
  //   DataTypeConversion: '<S10>/Data Type Conversion2'

  Aenea_model_B.BusCreator1.int16_data.rudderCmd_pwm = static_cast<int16_T>
    (Aenea_model_B.e < 0.0 ? static_cast<int32_T>(static_cast<int16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-Aenea_model_B.e)))) :
     static_cast<int32_T>(static_cast<int16_T>(static_cast<uint16_T>
       (Aenea_model_B.e))));
  Aenea_model_B.BusCreator1.uint16_data.dummy9 = 20U;
  Aenea_model_B.BusCreator1.uint16_data.dummy10 = 20U;
  Aenea_model_B.BusCreator1.int8_data.dummy11 = -5;
  Aenea_model_B.BusCreator1.int8_data.dummy12 = 120;

  // DataTypeConversion: '<S607>/Data Type Conversion'
  Aenea_model_B.e = std::floor(Aenea_model_B.SFunctionBuilder_o6);
  if (rtIsNaN(Aenea_model_B.e) || rtIsInf(Aenea_model_B.e)) {
    Aenea_model_B.e = 0.0;
  } else {
    Aenea_model_B.e = std::fmod(Aenea_model_B.e, 256.0);
  }

  // BusCreator: '<S2>/Bus Creator1' incorporates:
  //   BusCreator: '<S599>/Bus Creator11'
  //   BusCreator: '<S607>/Bus Creator10'
  //   Constant: '<S599>/Constant24'
  //   Constant: '<S607>/Constant15'
  //   DataTypeConversion: '<S607>/Data Type Conversion'

  Aenea_model_B.BusCreator1.uint8_data.gps_fix = static_cast<uint8_T>
    (Aenea_model_B.e < 0.0 ? static_cast<int32_T>(static_cast<uint8_T>(-
       static_cast<int8_T>(static_cast<uint8_T>(-Aenea_model_B.e)))) :
     static_cast<int32_T>(static_cast<uint8_T>(Aenea_model_B.e)));
  Aenea_model_B.BusCreator1.uint8_data.dummy12 = 111U;
  Aenea_model_B.BusCreator1.bool_data.dummy15 = true;
  Aenea_model_B.BusCreator1.bool_data.dummy16 = Aenea_model_B.Compare_i;

  // S-Function (Signal_Logger_sfun): '<S2>/S-Function Builder'
  Signal_Logger_sfun_Outputs_wrapper(&Aenea_model_B.BusCreator1,
    &Aenea_model_B.Compare_i);

  // Switch: '<S609>/FixPt Switch' incorporates:
  //   Constant: '<S608>/FixPt Constant'
  //   Constant: '<S609>/Constant'
  //   Sum: '<S608>/FixPt Sum1'
  //   UnitDelay: '<S598>/Output'

  if (static_cast<uint8_T>(Aenea_model_DW.Output_DSTATE_k + 1U) > 50) {
    Aenea_model_DW.Output_DSTATE_k = 0U;
  } else {
    Aenea_model_DW.Output_DSTATE_k = static_cast<uint8_T>
      (Aenea_model_DW.Output_DSTATE_k + 1U);
  }

  // End of Switch: '<S609>/FixPt Switch'

  // Update for Memory: '<S3>/Memory4'
  std::memcpy(&Aenea_model_DW.Memory4_PreviousInput_j[0], &Aenea_model_B.buffer
              [0], 300U * sizeof(uint8_T));

  // Update for UnitDelay: '<S575>/Unit Delay1'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 41; Aenea_model_B.i++) {
    Aenea_model_DW.UnitDelay1_DSTATE_b[Aenea_model_B.i] =
      Aenea_model_B.SFunctionBuilder1[Aenea_model_B.i];
  }

  // End of Update for UnitDelay: '<S575>/Unit Delay1'

  // Update for Memory: '<S3>/Memory5'
  std::memcpy(&Aenea_model_DW.Memory5_PreviousInput_b[0],
              &Aenea_model_B.mess_out[0], 100U * sizeof(uint8_T));

  // Update for Memory: '<S3>/Memory'
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 8; Aenea_model_B.i++) {
    Aenea_model_DW.Memory_PreviousInput_i[Aenea_model_B.i] =
      Aenea_model_B.SFunction_o11[Aenea_model_B.i];
  }

  // End of Update for Memory: '<S3>/Memory'

  // Update for RateTransition: '<S27>/Rate Transition'
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    Aenea_model_DW.RateTransition_Buffer0 = Aenea_model_B.Switch1_g;
  }

  // End of Update for RateTransition: '<S27>/Rate Transition'

  // Update for Memory: '<S27>/Memory' incorporates:
  //   Constant: '<S27>/Constant1'
  //   Sum: '<S27>/Add'

  Aenea_model_DW.Memory_PreviousInput += 0.02;

  // Update for UnitDelay: '<S571>/Unit Delay1' incorporates:
  //   UnitDelay: '<S577>/Delay Input2'
  //
  //  Block description for '<S577>/Delay Input2':
  //
  //   Store in Global RAM

  Aenea_model_DW.UnitDelay1_DSTATE = Aenea_model_DW.DelayInput2_DSTATE;

  // Update for Memory: '<S565>/Memory' incorporates:
  //   DataTypeConversion: '<S578>/Data Type Conversion2'

  Aenea_model_DW.Memory_PreviousInput_e[0] = Aenea_model_B.Gain1_i;
  Aenea_model_DW.Memory_PreviousInput_e[1] = Aenea_model_B.Gain1_i0;

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_e[2] = Aenea_model_B.SFunctionBuilder_o3_h;

  // End of Outputs for SubSystem: '<S571>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_e[3] = Aenea_model_B.V_nord;
  Aenea_model_DW.Memory_PreviousInput_e[4] = Aenea_model_B.V_est;
  Aenea_model_DW.Memory_PreviousInput_e[5] = Aenea_model_B.checksum;
  Aenea_model_DW.Memory_PreviousInput_e[6] = Aenea_model_B.Sum_f;
  Aenea_model_DW.Memory_PreviousInput_e[7] = Aenea_model_B.Gain1_o;

  // Update for Memory: '<S564>/Memory' incorporates:
  //   DataTypeConversion: '<S578>/Data Type Conversion2'

  Aenea_model_DW.Memory_PreviousInput_o[0] = Aenea_model_B.Gain1_i;
  Aenea_model_DW.Memory_PreviousInput_o[1] = Aenea_model_B.Gain1_i0;

  // Outputs for Atomic SubSystem: '<S571>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_o[2] = Aenea_model_B.SFunctionBuilder_o3_h;

  // End of Outputs for SubSystem: '<S571>/Execution_loop'
  Aenea_model_DW.Memory_PreviousInput_o[3] = Aenea_model_B.V_nord;
  Aenea_model_DW.Memory_PreviousInput_o[4] = Aenea_model_B.V_est;
  Aenea_model_DW.Memory_PreviousInput_o[5] = Aenea_model_B.checksum;
  Aenea_model_DW.Memory_PreviousInput_o[6] = Aenea_model_B.Sum_f;
  Aenea_model_DW.Memory_PreviousInput_o[7] = Aenea_model_B.Gain1_o;
  for (Aenea_model_B.i = 0; Aenea_model_B.i < 6; Aenea_model_B.i++) {
    // Update for Memory: '<S565>/Memory'
    Aenea_model_B.Alt = Aenea_model_B.DataTypeConversion1_c[Aenea_model_B.i];
    Aenea_model_DW.Memory_PreviousInput_e[Aenea_model_B.i + 8] =
      Aenea_model_B.Alt;

    // Update for Memory: '<S564>/Memory'
    Aenea_model_DW.Memory_PreviousInput_o[Aenea_model_B.i + 8] =
      Aenea_model_B.Alt;
  }

  // Update for DiscreteIntegrator: '<S342>/Integrator' incorporates:
  //   Product: '<S339>/IProd Out'
  //   Sum: '<S335>/SumI2'
  //   Sum: '<S335>/SumI4'
  //   Sum: '<S353>/SumI3'
  //   Sum: '<S354>/SumI1'

  Aenea_model_DW.Integrator_DSTATE += ((Aenea_model_B.e_d * -0.64064997434616089
    + (Aenea_model_B.SwitchBumpless2 - Aenea_model_B.Saturation_o)) +
    (Aenea_model_B.Saturation_o - Aenea_model_B.Sum_fb)) * 0.02;

  // Update for DiscreteIntegrator: '<S392>/Integrator' incorporates:
  //   Constant: '<S305>/Constant3'
  //   Gain: '<S385>/Kb'
  //   Sum: '<S305>/Sum'
  //   Sum: '<S385>/SumI2'
  //   Sum: '<S385>/SumI4'

  Aenea_model_DW.Integrator_DSTATE_l += ((Aenea_model_B.Saturation_a -
    Aenea_model_B.Ato_selector) * 0.5 + Aenea_model_B.Alettoni) * 0.02;
  if (Aenea_model_B.Fase_ATO - 2.0 > 0.0) {
    Aenea_model_DW.Integrator_PrevResetState = 1;
  } else if (Aenea_model_B.Fase_ATO - 2.0 < 0.0) {
    Aenea_model_DW.Integrator_PrevResetState = -1;
  } else if (Aenea_model_B.Fase_ATO - 2.0 == 0.0) {
    Aenea_model_DW.Integrator_PrevResetState = 0;
  } else {
    Aenea_model_DW.Integrator_PrevResetState = 2;
  }

  // End of Update for DiscreteIntegrator: '<S392>/Integrator'

  // Update for DiscreteTransferFcn: '<S306>/Discrete Washout Filter'
  Aenea_model_DW.DiscreteWashoutFilter_states = Aenea_model_B.Sum3_h;

  // Update for Memory: '<S4>/Memory'
  Aenea_model_DW.Memory_PreviousInput_e4 = Aenea_model_B.SFunction_o4;

  // Signum: '<S276>/SignPreIntegrator'
  if (Aenea_model_B.Gain_dt < 0.0) {
    // DataTypeConversion: '<S276>/DataTypeConv2'
    Aenea_model_B.e = -1.0;
  } else if (Aenea_model_B.Gain_dt > 0.0) {
    // DataTypeConversion: '<S276>/DataTypeConv2'
    Aenea_model_B.e = 1.0;
  } else if (Aenea_model_B.Gain_dt == 0.0) {
    // DataTypeConversion: '<S276>/DataTypeConv2'
    Aenea_model_B.e = 0.0;
  } else {
    // DataTypeConversion: '<S276>/DataTypeConv2'
    Aenea_model_B.e = (rtNaN);
  }

  // End of Signum: '<S276>/SignPreIntegrator'

  // DataTypeConversion: '<S276>/DataTypeConv2'
  if (rtIsNaN(Aenea_model_B.e)) {
    Aenea_model_B.e = 0.0;
  } else {
    Aenea_model_B.e = std::fmod(Aenea_model_B.e, 256.0);
  }

  // Switch: '<S276>/Switch' incorporates:
  //   Constant: '<S276>/Constant1'
  //   DataTypeConversion: '<S276>/DataTypeConv1'
  //   DataTypeConversion: '<S276>/DataTypeConv2'
  //   Logic: '<S276>/AND3'
  //   RelationalOperator: '<S276>/Equal1'

  if (Ap_sel && (static_cast<int8_T>(Aenea_model_B.a_b < 0.0 ?
        static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(
           static_cast<uint8_T>(-Aenea_model_B.a_b)))) : static_cast<int32_T>(
         static_cast<int8_T>(static_cast<uint8_T>(Aenea_model_B.a_b)))) ==
                 (Aenea_model_B.e < 0.0 ? static_cast<int32_T>
                  (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
           (-Aenea_model_B.e)))) : static_cast<int32_T>(static_cast<int8_T>(
          static_cast<uint8_T>(Aenea_model_B.e)))))) {
    Aenea_model_B.Gain_dt = 0.0;
  }

  // End of Switch: '<S276>/Switch'

  // Update for DiscreteIntegrator: '<S285>/Integrator'
  Aenea_model_DW.Integrator_DSTATE_lq += 0.02 * Aenea_model_B.Gain_dt;

  // Update for DiscreteIntegrator: '<S307>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S307>/Constant7'
  //   Constant: '<S307>/Constant8'
  //   Sum: '<S307>/Sum'

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

  // End of Update for DiscreteIntegrator: '<S307>/Discrete-Time Integrator'
  if (Aenea_model_M->Timing.TaskCounters.TID[1] == 0) {
    // Update for Memory: '<S27>/Memory2'
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

    // Start for S-Function (Mti_sfun): '<S575>/S-Function Builder1'

    // S-Function Block: <S575>/S-Function Builder1
    Mti_sfun_Start_wrapper();

    // Start for S-Function (Seriale_mav_sfun): '<S3>/S-Function Builder'

    // S-Function Block: <S3>/S-Function Builder
    Seriale_mav_sfun_Start_wrapper();

    // Start for S-Function (GPS_sfun): '<S574>/S-Function Builder'

    // S-Function Block: <S574>/S-Function Builder
    GPS_sfun_Start_wrapper();

    // Start for S-Function (pitot_lidar_sfun): '<S576>/S-Function Builder'

    // S-Function Block: <S576>/S-Function Builder
    pitot_lidar_sfun_Start_wrapper();

    // Start for S-Function (blink_sfun): '<S7>/S-Function Builder'

    // S-Function Block: <S7>/S-Function Builder
    blink_sfun_Start_wrapper();

    // Start for S-Function (enable_sfun): '<S4>/S-Function Builder'

    // S-Function Block: <S4>/S-Function Builder
    enable_sfun_Start_wrapper();

    // Start for S-Function (Signal_Logger_sfun): '<S2>/S-Function Builder'

    // S-Function Block: <S2>/S-Function Builder
    Signal_Logger_sfun_Start_wrapper();
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

    // InitializeConditions for Switch: '<S27>/Switch' incorporates:
    //   Memory: '<S27>/Memory1'

    Aenea_model_DW.Memory1_PreviousInput = -1.0;

    // InitializeConditions for Memory: '<S27>/Memory'
    Aenea_model_DW.Memory_PreviousInput = -0.02;

    // InitializeConditions for UnitDelay: '<S571>/Unit Delay1'
    Aenea_model_DW.UnitDelay1_DSTATE = 101440.0;

    // InitializeConditions for DiscreteIntegrator: '<S392>/Integrator'
    Aenea_model_DW.Integrator_PrevResetState = 2;

    // InitializeConditions for UnitDelay: '<S577>/Delay Input2'
    //
    //  Block description for '<S577>/Delay Input2':
    //
    //   Store in Global RAM

    Aenea_model_DW.DelayInput2_DSTATE = 101325.0;

    // InitializeConditions for DiscreteIntegrator: '<S307>/Discrete-Time Integrator' 
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for Memory: '<S27>/Memory2'
    Aenea_model_DW.Memory2_PreviousInput = -1.0;

    // SystemInitialize for MATLAB Function: '<S3>/MATLAB Function1'
    std::memcpy(&Aenea_model_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    // SystemInitialize for Atomic SubSystem: '<S571>/Execution_loop'
    // Start for S-Function (BMP280_sfun): '<S578>/S-Function Builder'

    // S-Function Block: <S578>/S-Function Builder
    BMP280_sfun_Start_wrapper();

    // End of SystemInitialize for SubSystem: '<S571>/Execution_loop'

    // SystemInitialize for Chart: '<S38>/ STATI'
    Aenea_model_B.modo = 1.0;

    // SystemInitialize for MATLAB Function: '<S571>/MATLAB Function'
    Aenea_model_DW.P_ref = 102600.0;
    Aenea_model_DW.rl_up = 300.0;
    Aenea_model_DW.rl_dw = -300.0;

    // SystemInitialize for Enabled SubSystem: '<S39>/Subsystem1'
    // InitializeConditions for Memory: '<S442>/Memory7'
    Aenea_model_DW.Memory7_PreviousInput = 1.0;

    // SystemInitialize for Enabled SubSystem: '<S442>/APPROACH'
    // Start for Constant: '<S453>/Constant1'
    Aenea_model_B.Constant1_h = 20.0;

    // InitializeConditions for DiscreteIntegrator: '<S453>/Discrete-Time Integrator' 
    Aenea_model_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

    // End of SystemInitialize for SubSystem: '<S442>/APPROACH'

    // SystemInitialize for Enabled SubSystem: '<S442>/FLARE'
    // Start for Constant: '<S457>/Constant1'
    Aenea_model_B.Constant1 = 18.0;

    // End of SystemInitialize for SubSystem: '<S442>/FLARE'
    // End of SystemInitialize for SubSystem: '<S39>/Subsystem1'

    // SystemInitialize for Enabled SubSystem: '<S4>/Subsystem'
    // Start for S-Function (MavLink_Send_sfun): '<S20>/S-Function Builder'

    // S-Function Block: <S20>/S-Function Builder
    MavLink_Send_sfun_Start_wrapper();

    // End of SystemInitialize for SubSystem: '<S4>/Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S39>/Subsystem2'
    // InitializeConditions for Memory: '<S443>/Memory4'
    Aenea_model_DW.Memory4_PreviousInput = 1.0;

    // End of SystemInitialize for SubSystem: '<S39>/Subsystem2'

    // SystemInitialize for Triggered SubSystem: '<S251>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S303>/Out1' incorporates:
    //   Outport: '<S303>/Out1'

    Aenea_model_B.OutportBufferForOut1 = 1.0;

    // End of SystemInitialize for SubSystem: '<S251>/Enabled Subsystem'
  }
}

// Model terminate function
void Aenea_model_terminate(void)
{
  // Terminate for S-Function (Mti_sfun): '<S575>/S-Function Builder1'

  // S-Function Block: <S575>/S-Function Builder1
  Mti_sfun_Terminate_wrapper();

  // Terminate for Atomic SubSystem: '<S571>/Execution_loop'

  // Terminate for S-Function (BMP280_sfun): '<S578>/S-Function Builder'

  // S-Function Block: <S578>/S-Function Builder
  BMP280_sfun_Terminate_wrapper();

  // End of Terminate for SubSystem: '<S571>/Execution_loop'

  // Terminate for S-Function (blink_sfun): '<S7>/S-Function Builder'

  // S-Function Block: <S7>/S-Function Builder
  blink_sfun_Terminate_wrapper();

  // Terminate for Enabled SubSystem: '<S4>/Subsystem'

  // Terminate for S-Function (MavLink_Send_sfun): '<S20>/S-Function Builder'

  // S-Function Block: <S20>/S-Function Builder
  MavLink_Send_sfun_Terminate_wrapper();

  // End of Terminate for SubSystem: '<S4>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//
