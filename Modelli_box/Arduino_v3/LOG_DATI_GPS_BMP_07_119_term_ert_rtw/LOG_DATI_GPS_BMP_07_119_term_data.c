/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LOG_DATI_GPS_BMP_07_119_term_data.c
 *
 * Code generated for Simulink model 'LOG_DATI_GPS_BMP_07_119_term'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Sep 24 12:27:57 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LOG_DATI_GPS_BMP_07_119_term.h"
#include "LOG_DATI_GPS_BMP_07_119_term_private.h"

/* Block parameters (default storage) */
P_LOG_DATI_GPS_BMP_07_119_ter_T LOG_DATI_GPS_BMP_07_119_term_P = {
  /* Variable: t_AP
   * Referenced by:
   *   '<S34>/I2C Read1'
   *   '<S34>/I2C Read12'
   *   '<S37>/I2C Read'
   *   '<S37>/I2C Read1'
   *   '<S37>/I2C Read10'
   *   '<S37>/I2C Read11'
   *   '<S37>/I2C Read2'
   *   '<S37>/I2C Read3'
   *   '<S37>/I2C Read4'
   *   '<S37>/I2C Read5'
   *   '<S37>/I2C Read6'
   *   '<S37>/I2C Read7'
   *   '<S37>/I2C Read8'
   *   '<S37>/I2C Read9'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S23>/Serial Transmit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Serial Transmit1'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S34>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S34>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S34>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S34>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S34>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S34>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S4>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S41>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S41>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S41>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S41>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S41>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S44>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S44>/Memory'
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
   * Referenced by: '<S14>/Gain'
   */
  100.0,

  /* Expression: 3
   * Referenced by: '<S19>/Constant'
   */
  3.0,

  /* Expression: 1000
   * Referenced by: '<S19>/Gain'
   */
  1000.0,

  /* Expression: [0 0]
   * Referenced by: '<S19>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: 23
   * Referenced by: '<S19>/Constant3'
   */
  23.0,

  /* Expression: 1000
   * Referenced by: '<S19>/Gain2'
   */
  1000.0,

  /* Expression: 10
   * Referenced by: '<S19>/Constant2'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant'
   */
  0.0,

  /* Expression: [0 0]
   * Referenced by: '<S12>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0,0]
   * Referenced by: '<S13>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S11>/alt_r'
   */
  0.0,

  /* Expression: [10000;10000;1 ;1]
   * Referenced by: '<S11>/Gain'
   */
  { 10000.0, 10000.0, 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S11>/vel y'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/RC Simulated'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gain1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gain2'
   */
  1.0,

  /* Expression: 101325
   * Referenced by: '<S33>/Delay Input2'
   */
  101325.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 102000
   * Referenced by: '<S3>/Constant1'
   */
  102000.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S33>/sample time'
   */
  0.02,

  /* Expression: 20
   * Referenced by: '<S20>/TAS simulated'
   */
  20.0,

  /* Expression: 20
   * Referenced by: '<S20>/v simulated'
   */
  20.0,

  /* Expression: 273.15+28.3
   * Referenced by: '<S3>/T_0'
   */
  301.45,

  /* Expression: 15
   * Referenced by: '<S38>/Constant'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S20>/RC simulated'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S20>/ Heading simulated'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S20>/Rpm simulated'
   */
  1000.0,

  /* Expression: 4
   * Referenced by: '<S18>/Constant'
   */
  4.0,

  /* Expression: 0.3
   * Referenced by: '<S18>/Manetta Simulated'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S27>/Gain2'
   */
  100.0,

  /* Expression: 0.12
   * Referenced by: '<S18>/Equilibratore Simulated'
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
   * Referenced by: '<S18>/Alettoni Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S29>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S18>/Timone Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S30>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S18>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 10000
   * Referenced by: '<S18>/Constant2'
   */
  10000.0,

  /* Expression: 0.01
   * Referenced by: '<S18>/Gain'
   */
  0.01,

  /* Expression: 4000
   * Referenced by: '<S18>/Saturation'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S18>/Saturation'
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

  /* Expression: 23
   * Referenced by: '<S2>/Constant11'
   */
  23.0,

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

  /* Expression: [0,0,0,0]
   * Referenced by: '<Root>/Comandi'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0,0,0,0]
   * Referenced by: '<Root>/PWM autopilota'
   */
  { 0.0, 0.0, 0.0, 0.0 },

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

  /* Computed Parameter: Constant_Value_jl
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S34>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S40>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_c
   * Referenced by: '<S38>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_cw
   * Referenced by: '<S15>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_mu
   * Referenced by: '<S16>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S17>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_mk
   * Referenced by: '<S2>/Gain'
   */
  100.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S2>/Gain3'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S34>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value_h
   * Referenced by: '<S34>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value_i
   * Referenced by: '<S34>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value_c
   * Referenced by: '<S34>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_k
   * Referenced by: '<S34>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value_d
   * Referenced by: '<S34>/Constant9'
   */
  0U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S19>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<S19>/Gain1'
   */
  26214,

  /* Computed Parameter: Gain2_Gain_l
   * Referenced by: '<S2>/Gain2'
   */
  25600,

  /* Computed Parameter: Memory_InitialCondition_o
   * Referenced by: '<S1>/Memory'
   */
  0U,

  /* Computed Parameter: loaduint16_Value
   * Referenced by: '<S19>/load uint16'
   */
  10U,

  /* Computed Parameter: _Value
   * Referenced by: '<S19>/ '
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_h
   * Referenced by: '<S2>/Memory'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S32>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_g
   * Referenced by: '<S32>/Constant3'
   */
  1,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S44>/mario'
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

  /* Computed Parameter: Constant1_Value_h
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

  /* Computed Parameter: Memory1_InitialCondition_g
   * Referenced by: '<S1>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_gh
   * Referenced by: '<Root>/Memory'
   */
  0U,

  /* Computed Parameter: Memory3_InitialCondition
   * Referenced by: '<S1>/Memory3'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_p
   * Referenced by: '<S1>/Memory2'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Typefixed_wingAutopilotgeneric_
   * Referenced by: '<S12>/Type fixed_wing Autopilot generic'
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

  /* Start of '<S32>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S37>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S37>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S37>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S37>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S37>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S37>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S37>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S37>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S37>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S37>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S37>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S37>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S37>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S37>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S37>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S37>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S37>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S37>/Constant4'
     */
    47U
  }
  /* End of '<S32>/One_time_initialization' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
