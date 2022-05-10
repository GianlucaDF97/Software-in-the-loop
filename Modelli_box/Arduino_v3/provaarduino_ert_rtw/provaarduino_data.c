/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaarduino_data.c
 *
 * Code generated for Simulink model 'provaarduino'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 16:03:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaarduino.h"
#include "provaarduino_private.h"

/* Block parameters (default storage) */
P_provaarduino_T provaarduino_P = {
  /* Mask Parameter: BandLimitedWhiteNoise2_Cov
   * Referenced by: '<S1>/Output'
   */
  0.1,

  /* Mask Parameter: BandLimitedWhiteNoise3_Cov
   * Referenced by: '<S2>/Output'
   */
  0.1,

  /* Mask Parameter: BandLimitedWhiteNoise2_seed
   * Referenced by: '<S1>/White Noise'
   */
  23341.0,

  /* Mask Parameter: BandLimitedWhiteNoise3_seed
   * Referenced by: '<S2>/White Noise'
   */
  23341.0,

  /* Expression: 1500
   * Referenced by: '<Root>/Constant3'
   */
  1500.0,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev_d
   * Referenced by: '<S2>/White Noise'
   */
  1.0,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<Root>/Constant4'
   */
  900,

  /* Computed Parameter: RT1_InitialCondition
   * Referenced by: '<Root>/RT1'
   */
  0,

  /* Computed Parameter: RT_InitialCondition
   * Referenced by: '<Root>/RT'
   */
  0,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
