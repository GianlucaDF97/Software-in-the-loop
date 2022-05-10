/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaLOG_09_28_data.c
 *
 * Code generated for Simulink model 'provaLOG_09_28'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  1 12:19:19 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaLOG_09_28.h"
#include "provaLOG_09_28_private.h"

/* Block parameters (default storage) */
P_provaLOG_09_28_T provaLOG_09_28_P = {
  /* Variable: t_AP
   * Referenced by:
   *   '<S35>/I2C Read1'
   *   '<S35>/I2C Read12'
   *   '<S38>/I2C Read'
   *   '<S38>/I2C Read1'
   *   '<S38>/I2C Read10'
   *   '<S38>/I2C Read11'
   *   '<S38>/I2C Read2'
   *   '<S38>/I2C Read3'
   *   '<S38>/I2C Read4'
   *   '<S38>/I2C Read5'
   *   '<S38>/I2C Read6'
   *   '<S38>/I2C Read7'
   *   '<S38>/I2C Read8'
   *   '<S38>/I2C Read9'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S18>/Serial Transmit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S20>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S20>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S20>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S20>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S23>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Serial Transmit1'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S35>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S35>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S35>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S35>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S35>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S35>/Constant3'
   */
  8.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S11>/Constant4'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S27>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S27>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S27>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S27>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S27>/Memory'
   */
  -0.02,

  /* Expression: 100
   * Referenced by: '<S12>/Gain'
   */
  100.0,

  /* Expression: 3
   * Referenced by: '<S14>/Constant'
   */
  3.0,

  /* Expression: 1000
   * Referenced by: '<S14>/Gain'
   */
  1000.0,

  /* Expression: [0 0]
   * Referenced by: '<S14>/Constant1'
   */
  { 0.0, 0.0 },

  /* Expression: 23
   * Referenced by: '<S14>/Constant3'
   */
  23.0,

  /* Expression: 1000
   * Referenced by: '<S14>/Gain2'
   */
  1000.0,

  /* Expression: 10
   * Referenced by: '<S14>/Constant2'
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
   * Referenced by: '<S34>/Delay Input2'
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
   * Referenced by: '<S34>/sample time'
   */
  0.02,

  /* Expression: 20
   * Referenced by: '<S15>/TAS simulated'
   */
  20.0,

  /* Expression: 20
   * Referenced by: '<S15>/v simulated'
   */
  20.0,

  /* Expression: 298
   * Referenced by: '<Root>/T_0'
   */
  298.0,

  /* Expression: 15
   * Referenced by: '<S39>/Constant'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S15>/RC simulated'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S15>/ Heading simulated'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S15>/Rpm simulated'
   */
  1000.0,

  /* Expression: 4
   * Referenced by: '<S13>/Constant'
   */
  4.0,

  /* Expression: 0.3
   * Referenced by: '<S13>/Manetta Simulated'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S29>/Gain2'
   */
  100.0,

  /* Expression: 0.12
   * Referenced by: '<S13>/Equilibratore Simulated'
   */
  0.12,

  /* Expression: 180/pi
   * Referenced by: '<S30>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S29>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S13>/Alettoni Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S31>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S13>/Timone Simulated'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S32>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S13>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 10000
   * Referenced by: '<S13>/Constant2'
   */
  10000.0,

  /* Expression: 0.01
   * Referenced by: '<S13>/Gain'
   */
  0.01,

  /* Expression: 4000
   * Referenced by: '<S13>/Saturation'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S13>/Saturation'
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

  /* Expression: 0
   * Referenced by: '<S27>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S27>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S27>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S35>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S41>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_l
   * Referenced by: '<S39>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S2>/Gain3'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S35>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value_e
   * Referenced by: '<S35>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value_m
   * Referenced by: '<S35>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S35>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_p
   * Referenced by: '<S35>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value_o
   * Referenced by: '<S35>/Constant9'
   */
  0U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S14>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<S14>/Gain1'
   */
  26214,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S2>/Gain'
   */
  25600,

  /* Computed Parameter: Gain2_Gain_n
   * Referenced by: '<S2>/Gain2'
   */
  25600,

  /* Computed Parameter: Memory_InitialCondition_o
   * Referenced by: '<S1>/Memory'
   */
  0U,

  /* Computed Parameter: loaduint16_Value
   * Referenced by: '<S14>/load uint16'
   */
  10U,

  /* Computed Parameter: _Value
   * Referenced by: '<S14>/ '
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_d
   * Referenced by: '<S2>/Memory'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S3>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_c
   * Referenced by: '<S3>/Constant3'
   */
  1,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S23>/mario'
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
     * Referenced by: '<S38>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S38>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S38>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S38>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S38>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S38>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S38>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S38>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S38>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S38>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S38>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S38>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S38>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S38>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S38>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S38>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S38>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S38>/Constant4'
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
