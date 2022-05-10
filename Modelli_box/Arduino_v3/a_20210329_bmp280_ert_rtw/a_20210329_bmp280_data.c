/*
 * a_20210329_bmp280_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210329_bmp280".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Mar 29 17:19:05 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a_20210329_bmp280.h"
#include "a_20210329_bmp280_private.h"

/* Block parameters (default storage) */
P_a_20210329_bmp280_T a_20210329_bmp280_P = {
  /* Expression: 0.02
   * Referenced by: '<S1>/I2C Read1'
   */
  0.02,

  /* Expression: 0.02
   * Referenced by: '<S1>/I2C Read12'
   */
  0.02,

  /* Expression: 16
   * Referenced by: '<S1>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S1>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S1>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S1>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S1>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S1>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S1>/T'
   */
  0.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S1>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S1>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S1>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S1>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S1>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S1>/Constant9'
   */
  0U,

  /* Start of '<Root>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S2>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read1'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read10'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read11'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read12'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read2'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read3'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read4'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read5'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read6'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read7'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read8'
     */
    0.02,

    /* Expression: 0.02
     * Referenced by: '<S2>/I2C Read9'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S2>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S2>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S2>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S2>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S2>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S2>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S2>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S2>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S2>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S2>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S2>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S2>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S2>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S2>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S2>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S2>/Constant4'
     */
    47U
  }
  /* End of '<Root>/One_time_initialization' */
};
