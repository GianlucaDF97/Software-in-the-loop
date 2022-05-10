/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_BMP_GPS_09_23_data.c
 *
 * Code generated for Simulink model 'prova_LOG_BMP_GPS_09_23'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Apr  4 13:18:27 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_LOG_BMP_GPS_09_23.h"
#include "prova_LOG_BMP_GPS_09_23_private.h"

/* Block parameters (default storage) */
P_prova_LOG_BMP_GPS_09_23_T prova_LOG_BMP_GPS_09_23_P = {
  /* Variable: t_AP
   * Referenced by:
   *   '<S37>/I2C Read1'
   *   '<S37>/I2C Read12'
   *   '<S40>/I2C Read'
   *   '<S40>/I2C Read1'
   *   '<S40>/I2C Read10'
   *   '<S40>/I2C Read11'
   *   '<S40>/I2C Read2'
   *   '<S40>/I2C Read3'
   *   '<S40>/I2C Read4'
   *   '<S40>/I2C Read5'
   *   '<S40>/I2C Read6'
   *   '<S40>/I2C Read7'
   *   '<S40>/I2C Read8'
   *   '<S40>/I2C Read9'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S21>/Serial Transmit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S23>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S23>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S23>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S26>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Serial Transmit1'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S37>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S37>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S37>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S37>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S37>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S37>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S29>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S29>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S29>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S29>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S29>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S29>/Memory'
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

  /* Expression: 1
   * Referenced by: '<S11>/Constant9'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant10'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant6'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant8'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant7'
   */
  1.0,

  /* Expression: [0,0,0]
   * Referenced by: '<S11>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S11>/Constant12'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant5'
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

  /* Expression: 100
   * Referenced by: '<S9>/Gain2'
   */
  100.0,

  /* Expression: 101325
   * Referenced by: '<S36>/Delay Input2'
   */
  101325.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 102000
   * Referenced by: '<Root>/Constant1'
   */
  102000.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S36>/sample time'
   */
  0.02,

  /* Expression: 20
   * Referenced by: '<S18>/TAS simulated'
   */
  20.0,

  /* Expression: 20
   * Referenced by: '<S18>/v simulated'
   */
  20.0,

  /* Expression: 298
   * Referenced by: '<Root>/T_0'
   */
  298.0,

  /* Expression: 15
   * Referenced by: '<S41>/Constant'
   */
  15.0,

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
   * Referenced by: '<S31>/Gain2'
   */
  100.0,

  /* Expression: 0.12
   * Referenced by: '<S16>/Equilibratore Simulated'
   */
  0.12,

  /* Expression: 180/pi
   * Referenced by: '<S32>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S31>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S16>/Alettoni Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S33>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S16>/Timone Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S34>/Gain'
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

  /* Expression: 180/pi
   * Referenced by: '<S13>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S14>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S15>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S2>/Gain'
   */
  100.0,

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

  /* Expression: 0
   * Referenced by: '<S29>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S29>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S29>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S29>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S37>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S43>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_k
   * Referenced by: '<S41>/Switch'
   */
  0.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S37>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value_m
   * Referenced by: '<S37>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value_i
   * Referenced by: '<S37>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value_f
   * Referenced by: '<S37>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_p
   * Referenced by: '<S37>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value_m
   * Referenced by: '<S37>/Constant9'
   */
  0U,

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

  /* Computed Parameter: Memory_InitialCondition_lq
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

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S3>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_g
   * Referenced by: '<S3>/Constant3'
   */
  1,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S26>/mario'
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
  60U,

  /* Start of '<S3>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S40>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S40>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S40>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S40>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S40>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S40>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S40>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S40>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S40>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S40>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S40>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S40>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S40>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S40>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S40>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S40>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S40>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S40>/Constant4'
     */
    47U
  }
  /* End of '<S3>/One_time_initialization' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
