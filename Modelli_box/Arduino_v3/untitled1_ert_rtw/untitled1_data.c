/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1_data.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:27:47 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_private.h"

/* Block parameters (default storage) */
P_untitled1_T untitled1_P = {
  /* Variable: t_AP
   * Referenced by:
   *   '<S24>/I2C Read1'
   *   '<S24>/I2C Read12'
   *   '<S27>/I2C Read'
   *   '<S27>/I2C Read1'
   *   '<S27>/I2C Read10'
   *   '<S27>/I2C Read11'
   *   '<S27>/I2C Read2'
   *   '<S27>/I2C Read3'
   *   '<S27>/I2C Read4'
   *   '<S27>/I2C Read5'
   *   '<S27>/I2C Read6'
   *   '<S27>/I2C Read7'
   *   '<S27>/I2C Read8'
   *   '<S27>/I2C Read9'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S7>/Serial Receive'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Serial Transmit'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S24>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S24>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S24>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S24>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S24>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S24>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S21>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S31>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S31>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S31>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S31>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S31>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S34>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S34>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Serial Transmit'
   */
  0.0,

  /* Expression: 101325
   * Referenced by: '<S23>/Delay Input2'
   */
  101325.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant2'
   */
  1.0,

  /* Expression: 101325
   * Referenced by: '<S2>/Constant3'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S23>/sample time'
   */
  0.02,

  /* Expression: 280
   * Referenced by: '<S2>/Constant1'
   */
  280.0,

  /* Expression: 15
   * Referenced by: '<S28>/Constant'
   */
  15.0,

  /* Expression: 180/pi
   * Referenced by: '<S12>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S13>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S14>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S7>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S7>/Gain2'
   */
  100.0,

  /* Expression: zeros(1,3)
   * Referenced by: '<S7>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S7>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant5'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S3>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S4>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S5>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0.01
   * Referenced by: '<S7>/Gain1'
   */
  0.01,

  /* Expression: 62
   * Referenced by: '<S7>/Constant'
   */
  62.0,

  /* Expression: tau
   * Referenced by: '<S16>/Constant'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S16>/Unit Delay'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S8>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S9>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0.01
   * Referenced by: '<S7>/Gain4'
   */
  0.01,

  /* Expression: pi/180
   * Referenced by: '<S10>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S6>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S19>/Out2'
   */
  0.0F,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S24>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S30>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S28>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S7>/Gain3'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S24>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S24>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S24>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S24>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S24>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S24>/Constant9'
   */
  0U,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S19>/Out3'
   */
  0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S19>/Out4'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition_o
   * Referenced by: '<S20>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_o
   * Referenced by: '<S20>/Constant3'
   */
  1,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S34>/mario'
   */
  0U,

  /* Computed Parameter: InizioMSG_Value
   * Referenced by: '<S7>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<S7>/Fine MSG1'
   */
  60U,

  /* Start of '<S20>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S27>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S27>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S27>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S27>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S27>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S27>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S27>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S27>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S27>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S27>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S27>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S27>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S27>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S27>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S27>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S27>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S27>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S27>/Constant4'
     */
    47U
  }
  /* End of '<S20>/One_time_initialization' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
