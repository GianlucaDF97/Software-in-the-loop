/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_AHRS_09_23_data.c
 *
 * Code generated for Simulink model 'prova_LOG_AHRS_09_23'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 17:53:09 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_LOG_AHRS_09_23.h"
#include "prova_LOG_AHRS_09_23_private.h"

/* Block parameters (default storage) */
P_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_P = {
  /* Expression: 0
   * Referenced by: '<S21>/Serial Transmit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Serial Transmit1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S23>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S23>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S23>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S23>/Memory'
   */
  -0.02,

  /* Expression: 100
   * Referenced by: '<S12>/Gain'
   */
  100.0,

  /* Expression: 3
   * Referenced by: '<S17>/Constant'
   */
  3.0,

  /* Expression: 1000
   * Referenced by: '<S17>/Gain'
   */
  1000.0,

  /* Expression: [0 0]
   * Referenced by: '<S17>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: 23
   * Referenced by: '<S17>/Constant3'
   */
  23.0,

  /* Expression: 1000
   * Referenced by: '<S17>/Gain2'
   */
  1000.0,

  /* Expression: 10
   * Referenced by: '<S17>/Constant2'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: [0 0]
   * Referenced by: '<S10>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0,0]
   * Referenced by: '<S11>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/alt_r'
   */
  0.0,

  /* Expression: [10^7;10^7;1000 ;1000]
   * Referenced by: '<S9>/Gain'
   */
  { 1.0E+7, 1.0E+7, 1000.0, 1000.0 },

  /* Expression: 1
   * Referenced by: '<S9>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/vel y'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/RC Simulated'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S9>/Gain1'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant4'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S9>/Gain2'
   */
  100.0,

  /* Expression: 20
   * Referenced by: '<S18>/TAS simulated'
   */
  20.0,

  /* Expression: 20
   * Referenced by: '<S18>/v simulated'
   */
  20.0,

  /* Expression: 30
   * Referenced by: '<Root>/Constant'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S18>/RC simulated'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S18>/ Heading simulated'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S18>/Rpm simulated'
   */
  1000.0,

  /* Expression: 4
   * Referenced by: '<S16>/Constant'
   */
  4.0,

  /* Expression: 0.3
   * Referenced by: '<S16>/Manetta Simulated'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S25>/Gain2'
   */
  100.0,

  /* Expression: 0.12
   * Referenced by: '<S16>/Equilibratore Simulated'
   */
  0.12,

  /* Expression: 180/pi
   * Referenced by: '<S26>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S25>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S16>/Alettoni Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S27>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S16>/Timone Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S28>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S16>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 10000
   * Referenced by: '<S16>/Constant2'
   */
  10000.0,

  /* Expression: 0.01
   * Referenced by: '<S16>/Gain'
   */
  0.01,

  /* Expression: 4000
   * Referenced by: '<S16>/Saturation'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S16>/Saturation'
   */
  0.0,

  /* Expression: 101000
   * Referenced by: '<Root>/Constant1'
   */
  101000.0,

  /* Expression: 298
   * Referenced by: '<Root>/Constant6'
   */
  298.0,

  /* Expression: 1004
   * Referenced by: '<Root>/Constant2'
   */
  1004.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa1'
   */
  0.01,

  /* Expression: 32
   * Referenced by: '<Root>/Constant5'
   */
  32.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant10'
   */
  0.0,

  /* Expression: 1500
   * Referenced by: '<S2>/Constant'
   */
  1500.0,

  /* Expression: 1500
   * Referenced by: '<S2>/Constant3'
   */
  1500.0,

  /* Expression: 9
   * Referenced by: '<S2>/Constant7'
   */
  9.0,

  /* Expression: 8
   * Referenced by: '<S2>/Constant8'
   */
  8.0,

  /* Expression: 7
   * Referenced by: '<S2>/Constant9'
   */
  7.0,

  /* Expression: 6
   * Referenced by: '<S2>/Constant6'
   */
  6.0,

  /* Expression: 1500
   * Referenced by: '<S2>/Constant1'
   */
  1500.0,

  /* Expression: 100
   * Referenced by: '<S2>/Gain3'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S23>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S23>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: Gain_Gain_lz
   * Referenced by: '<S13>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S14>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_br
   * Referenced by: '<S15>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S2>/Gain'
   */
  100.0F,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S17>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<S17>/Gain1'
   */
  26214,

  /* Computed Parameter: Gain2_Gain_p
   * Referenced by: '<S2>/Gain2'
   */
  25600,

  /* Computed Parameter: Memory_InitialCondition_l
   * Referenced by: '<S1>/Memory'
   */
  0U,

  /* Computed Parameter: loaduint16_Value
   * Referenced by: '<S17>/load uint16'
   */
  10U,

  /* Computed Parameter: _Value
   * Referenced by: '<S17>/ '
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_m
   * Referenced by: '<S2>/Memory'
   */
  0U,

  /* Expression: uint8(zeros(3,100))
   * Referenced by: '<S1>/Memory4'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Constant1_Value_if
   * Referenced by: '<S1>/Constant1'
   */
  1U,

  /* Computed Parameter: SIUAVuint8_Value
   * Referenced by: '<Root>/SI UAV uint8'
   */
  100U,

  /* Computed Parameter: Memory5_InitialCondition
   * Referenced by: '<S1>/Memory5'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_j
   * Referenced by: '<S1>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_i
   * Referenced by: '<Root>/Memory'
   */
  0U,

  /* Computed Parameter: Memory3_InitialCondition
   * Referenced by: '<S1>/Memory3'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_j
   * Referenced by: '<S1>/Memory2'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Typefixed_wingAutopilotgeneric_
   * Referenced by: '<S10>/Type fixed_wing Autopilot generic'
   */
  { 1U, 0U },

  /* Computed Parameter: InizioMSG_Value
   * Referenced by: '<S2>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<S2>/Fine MSG1'
   */
  60U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
