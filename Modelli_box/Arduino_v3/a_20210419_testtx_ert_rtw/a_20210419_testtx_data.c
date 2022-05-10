/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210419_testtx_data.c
 *
 * Code generated for Simulink model 'a_20210419_testtx'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May  4 16:38:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a_20210419_testtx.h"
#include "a_20210419_testtx_private.h"

/* Block parameters (default storage) */
P_a_20210419_testtx_T a_20210419_testtx_P = {
  /* Expression: 0
   * Referenced by: '<S12>/Serial Transmit'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Discrete Pulse Generator'
   */
  1.0,

  /* Expression: 4
   * Referenced by: '<S5>/Discrete Pulse Generator'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<S5>/Discrete Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Discrete Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S5>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S5>/Memory'
   */
  -0.02,

  /* Expression: 100
   * Referenced by: '<S5>/Gain1'
   */
  100.0,

  /* Expression: [0 0 100]
   * Referenced by: '<S10>/Constant1'
   */
  { 0.0, 0.0, 100.0 },

  /* Expression: [0 0 0 0 0 0 0 0 20 100 0 101325 15 0 0 0]
   * Referenced by: '<S10>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 100.0, 0.0, 101325.0, 15.0,
    0.0, 0.0, 0.0 },

  /* Expression: [0 0 0 0 0 0 ]
   * Referenced by: '<S10>/Constant2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 0 0 0 0 0 0 0]
   * Referenced by: '<S10>/Constant3'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0 0]
   * Referenced by: '<S9>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S9>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Sine Wave'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S9>/Gain2'
   */
  1000.0,

  /* Expression: 10
   * Referenced by: '<S9>/Constant3'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: [0 0]
   * Referenced by: '<S3>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: [0 0]'
   * Referenced by: '<S3>/Constant2'
   */
  { 0.0, 0.0 },

  /* Expression: [0.102 0 0]
   * Referenced by: '<S4>/ACC simulated'
   */
  { 0.102, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S4>/p simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/q simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/r simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: 10^3
   * Referenced by: '<S4>/Gain'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S4>/phi simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/theta simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/psi simulated'
   */
  0.0,

  /* Expression: 41*pi/180
   * Referenced by: '<S8>/Lat Simulated'
   */
  0.715584993317675,

  /* Expression: 180/pi
   * Referenced by: '<S18>/Gain'
   */
  57.295779513082323,

  /* Expression: 12*pi/180
   * Referenced by: '<S8>/Long Simulated'
   */
  0.20943951023931953,

  /* Expression: 180/pi
   * Referenced by: '<S19>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S8>/Alt Simulated'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S8>/alt_r'
   */
  0.0,

  /* Expression: [10^7;10^7;1000 ;1000]
   * Referenced by: '<S8>/Gain'
   */
  { 1.0E+7, 1.0E+7, 1000.0, 1000.0 },

  /* Expression: 20
   * Referenced by: '<S8>/v Simulated'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S8>/vel y'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/RC Simulated'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S8>/Gain1'
   */
  100.0,

  /* Expression: 50
   * Referenced by: '<S8>/Heading simulated'
   */
  50.0,

  /* Expression: 100
   * Referenced by: '<S8>/Gain2'
   */
  100.0,

  /* Expression: 20
   * Referenced by: '<S6>/TAS simulated'
   */
  20.0,

  /* Expression: 20
   * Referenced by: '<S6>/v simulated'
   */
  20.0,

  /* Expression: 100
   * Referenced by: '<S6>/Alt simulated'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S6>/RC simulated'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S6>/ Heading simulated'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S6>/Rpm simulated'
   */
  1000.0,

  /* Expression: 4
   * Referenced by: '<S7>/Constant'
   */
  4.0,

  /* Expression: 0.3
   * Referenced by: '<S7>/Manetta Simulated'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S14>/Gain2'
   */
  100.0,

  /* Expression: 0.12
   * Referenced by: '<S7>/Equilibratore Simulated'
   */
  0.12,

  /* Expression: 180/pi
   * Referenced by: '<S15>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S14>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S7>/Alettoni Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S16>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S7>/Timone Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S17>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S7>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 10000
   * Referenced by: '<S7>/Constant2'
   */
  10000.0,

  /* Expression: 0.01
   * Referenced by: '<S7>/Gain'
   */
  0.01,

  /* Expression: 4000
   * Referenced by: '<S7>/Saturation'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Expression: 1013
   * Referenced by: '<S1>/Constant1'
   */
  1013.0,

  /* Expression: 101325
   * Referenced by: '<S1>/Constant6'
   */
  101325.0,

  /* Expression: 0.01
   * Referenced by: '<S1>/Pa to hPa'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S1>/Constant3'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S1>/Pa to hPa1'
   */
  0.01,

  /* Expression: 298
   * Referenced by: '<S1>/Constant11'
   */
  298.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant10'
   */
  0.0,

  /* Computed Parameter: Constant2_Value_j
   * Referenced by: '<S1>/Constant2'
   */
  15.0F,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S9>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Gain1_Gain_i
   * Referenced by: '<S9>/Gain1'
   */
  26214,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S9>/Gain'
   */
  64000U,

  /* Computed Parameter: loaduint16_Value
   * Referenced by: '<S9>/load uint16'
   */
  10U,

  /* Computed Parameter: Constant2_Value_h
   * Referenced by: '<S9>/Constant2'
   */
  3U,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S9>/Constant'
   */
  { 0U, 0U, 0U },

  /* Computed Parameter: _Value
   * Referenced by: '<S9>/ '
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_j
   * Referenced by: '<S1>/Memory'
   */
  0U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S1>/Constant'
   */
  100U,

  /* Computed Parameter: Typefixed_wingAutopilotgeneric_
   * Referenced by: '<S3>/Type fixed_wing Autopilot generic'
   */
  { 1U, 0U },

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S1>/Constant4'
   */
  0U,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S1>/Constant5'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S1>/Constant7'
   */
  { 0U, 0U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
