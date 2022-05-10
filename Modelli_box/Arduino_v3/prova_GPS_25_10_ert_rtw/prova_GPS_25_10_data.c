/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_GPS_25_10_data.c
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

/* Block parameters (default storage) */
P_prova_GPS_25_10_T prova_GPS_25_10_P = {
  /* Expression: 0
   * Referenced by: '<S17>/Serial Transmit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S19>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S19>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S19>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S22>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S25>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S25>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S25>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S25>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S25>/Memory'
   */
  -0.02,

  /* Expression: 100
   * Referenced by: '<S11>/Gain'
   */
  100.0,

  /* Expression: 3
   * Referenced by: '<S13>/Constant'
   */
  3.0,

  /* Expression: 1000
   * Referenced by: '<S13>/Gain'
   */
  1000.0,

  /* Expression: [0 0]
   * Referenced by: '<S13>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: 23
   * Referenced by: '<S13>/Constant3'
   */
  23.0,

  /* Expression: 1000
   * Referenced by: '<S13>/Gain2'
   */
  1000.0,

  /* Expression: 10
   * Referenced by: '<S13>/Constant2'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: [0 0]
   * Referenced by: '<S9>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: ones(1,9)
   * Referenced by: '<S10>/Constant5'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: [0 0 0]
   * Referenced by: '<S10>/Constant4'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S8>/alt_r'
   */
  0.0,

  /* Expression: [10^7;10^7;1000 ;1000]
   * Referenced by: '<S8>/Gain'
   */
  { 1.0E+7, 1.0E+7, 1000.0, 1000.0 },

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

  /* Expression: 100
   * Referenced by: '<S8>/Gain2'
   */
  100.0,

  /* Expression: 20
   * Referenced by: '<S14>/TAS simulated'
   */
  20.0,

  /* Expression: 20
   * Referenced by: '<S14>/v simulated'
   */
  20.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S14>/RC simulated'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S14>/ Heading simulated'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S14>/Rpm simulated'
   */
  1000.0,

  /* Expression: 4
   * Referenced by: '<S12>/Constant'
   */
  4.0,

  /* Expression: 0.3
   * Referenced by: '<S12>/Manetta Simulated'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S27>/Gain2'
   */
  100.0,

  /* Expression: 0.12
   * Referenced by: '<S12>/Equilibratore Simulated'
   */
  0.12,

  /* Expression: 180/pi
   * Referenced by: '<S28>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S27>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S12>/Alettoni Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S29>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S12>/Timone Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S30>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S12>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 10000
   * Referenced by: '<S12>/Constant2'
   */
  10000.0,

  /* Expression: 0.01
   * Referenced by: '<S12>/Gain'
   */
  0.01,

  /* Expression: 4000
   * Referenced by: '<S12>/Saturation'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant5'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

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

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

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

  /* Expression: [0,0,0]
   * Referenced by: '<S10>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0.102 0 0]
   * Referenced by: '<S10>/ACC simulated'
   */
  { 0.102, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/p simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/phi simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/psi simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/q simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/r simulated'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/theta simulated'
   */
  0.0,

  /* Expression: 10^3
   * Referenced by: '<S10>/Gain1'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S25>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S25>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S25>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_i2
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S13>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<S13>/Gain1'
   */
  26214,

  /* Computed Parameter: Memory_InitialCondition_o
   * Referenced by: '<S1>/Memory'
   */
  0U,

  /* Computed Parameter: loaduint16_Value
   * Referenced by: '<S13>/load uint16'
   */
  10U,

  /* Computed Parameter: _Value
   * Referenced by: '<S13>/ '
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_d
   * Referenced by: '<S2>/Memory'
   */
  0U,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S22>/mario'
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

  /* Computed Parameter: Constant1_Value_i
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

  /* Computed Parameter: Memory1_InitialCondition_l
   * Referenced by: '<S1>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_f
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
   * Referenced by: '<S9>/Type fixed_wing Autopilot generic'
   */
  { 1U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
