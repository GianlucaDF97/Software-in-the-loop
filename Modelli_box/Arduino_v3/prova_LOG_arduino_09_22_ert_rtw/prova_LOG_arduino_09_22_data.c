/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_arduino_09_22_data.c
 *
 * Code generated for Simulink model 'prova_LOG_arduino_09_22'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 16:59:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_LOG_arduino_09_22.h"
#include "prova_LOG_arduino_09_22_private.h"

/* Block parameters (default storage) */
P_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_P = {
  /* Variable: t_AP
   * Referenced by:
   *   '<S8>/I2C Read1'
   *   '<S8>/I2C Read12'
   *   '<S11>/I2C Read'
   *   '<S11>/I2C Read1'
   *   '<S11>/I2C Read10'
   *   '<S11>/I2C Read11'
   *   '<S11>/I2C Read2'
   *   '<S11>/I2C Read3'
   *   '<S11>/I2C Read4'
   *   '<S11>/I2C Read5'
   *   '<S11>/I2C Read6'
   *   '<S11>/I2C Read7'
   *   '<S11>/I2C Read8'
   *   '<S11>/I2C Read9'
   */
  0.02,

  /* Expression: 16
   * Referenced by: '<S8>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S8>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S8>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S8>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S8>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S8>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S2>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S15>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S15>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S15>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S18>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Serial Transmit'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 298
   * Referenced by: '<Root>/T_0'
   */
  298.0,

  /* Expression: 15
   * Referenced by: '<S12>/Constant'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 101325
   * Referenced by: '<S7>/Delay Input2'
   */
  101325.0,

  /* Expression: 101000
   * Referenced by: '<Root>/Constant'
   */
  101000.0,

  /* Expression: 101000
   * Referenced by: '<Root>/Constant1'
   */
  101000.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S7>/sample time'
   */
  0.02,

  /* Expression: 100
   * Referenced by: '<Root>/Gain2'
   */
  100.0,

  /* Expression: [1500 1500 1500]
   * Referenced by: '<Root>/PWM_autopilota'
   */
  { 1500.0, 1500.0, 1500.0 },

  /* Expression: 1
   * Referenced by: '<Root>/manetta'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Equilibratore'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Alettoni'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Timone'
   */
  1.0,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S8>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S14>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S12>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S4>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S5>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S6>/Gain'
   */
  57.2957802F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<Root>/Gain'
   */
  100.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S8>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S8>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S8>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S8>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S8>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S8>/Constant9'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S1>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_o
   * Referenced by: '<S1>/Constant3'
   */
  1,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S18>/mario'
   */
  0U,

  /* Computed Parameter: InizioMSG_Value
   * Referenced by: '<Root>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<Root>/Fine MSG1'
   */
  60U,

  /* Start of '<S1>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S11>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S11>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S11>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S11>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S11>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S11>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S11>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S11>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S11>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S11>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S11>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S11>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S11>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S11>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S11>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S11>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S11>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S11>/Constant4'
     */
    47U
  }
  /* End of '<S1>/One_time_initialization' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
