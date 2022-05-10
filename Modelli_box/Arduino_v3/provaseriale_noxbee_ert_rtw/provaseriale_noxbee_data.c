/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaseriale_noxbee_data.c
 *
 * Code generated for Simulink model 'provaseriale_noxbee'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:56:51 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaseriale_noxbee.h"
#include "provaseriale_noxbee_private.h"

/* Block parameters (default storage) */
P_provaseriale_noxbee_T provaseriale_noxbee_P = {
  /* Variable: t_AP
   * Referenced by:
   *   '<S6>/I2C Read1'
   *   '<S6>/I2C Read12'
   *   '<S9>/I2C Read'
   *   '<S9>/I2C Read1'
   *   '<S9>/I2C Read10'
   *   '<S9>/I2C Read11'
   *   '<S9>/I2C Read2'
   *   '<S9>/I2C Read3'
   *   '<S9>/I2C Read4'
   *   '<S9>/I2C Read5'
   *   '<S9>/I2C Read6'
   *   '<S9>/I2C Read7'
   *   '<S9>/I2C Read8'
   *   '<S9>/I2C Read9'
   */
  0.02,

  /* Expression: 16
   * Referenced by: '<S6>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S6>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S6>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S6>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S6>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S6>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S3>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S13>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S13>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S13>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S16>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Serial Transmit'
   */
  0.0,

  /* Expression: 101325
   * Referenced by: '<S5>/Delay Input2'
   */
  101325.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant2'
   */
  1.0,

  /* Expression: 101325
   * Referenced by: '<S1>/Constant3'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S5>/sample time'
   */
  0.02,

  /* Expression: 280
   * Referenced by: '<S1>/Constant1'
   */
  280.0,

  /* Expression: 15
   * Referenced by: '<S10>/Constant'
   */
  15.0,

  /* Expression: zeros(1,3)
   * Referenced by: '<S1>/Constant6'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: zeros(1,4)
   * Referenced by: '<S1>/Constant5'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: T_Y0
   * Referenced by: '<S6>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S12>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S10>/Switch'
   */
  0.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S6>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S6>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S6>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S6>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S6>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S6>/Constant9'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S2>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_o
   * Referenced by: '<S2>/Constant3'
   */
  1,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S16>/mario'
   */
  0U,

  /* Start of '<S2>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S9>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S9>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S9>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S9>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S9>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S9>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S9>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S9>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S9>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S9>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S9>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S9>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S9>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S9>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S9>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S9>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S9>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S9>/Constant4'
     */
    47U
  }
  /* End of '<S2>/One_time_initialization' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
