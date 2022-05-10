/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testloaddata_prova2_data.c
 *
 * Code generated for Simulink model 'testloaddata_prova2'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jul 16 18:44:43 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testloaddata_prova2.h"
#include "testloaddata_prova2_private.h"

/* Block parameters (default storage) */
P_testloaddata_prova2_T testloaddata_prova2_P = {
  /* Expression: sampleTime
   * Referenced by: '<S2>/Digital Read'
   */
  0.02,

  /* Expression: SampleTime
   * Referenced by: '<S4>/Serial Read'
   */
  0.02,

  /* Computed Parameter: fix_Y0
   * Referenced by: '<S16>/fix '
   */
  0.0,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S16>/mario'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S5>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S6>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S7>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 20
   * Referenced by: '<Root>/Constant'
   */
  20.0,

  /* Expression: 0.01
   * Referenced by: '<S4>/Gain3'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S4>/Gain'
   */
  0.01,

  /* Expression: 0.514444
   * Referenced by: '<S4>/Knot2m//s'
   */
  0.514444,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S16>/Out2'
   */
  0.0F,

  /* Computed Parameter: pressione_Y0
   * Referenced by: '<S16>/pressione'
   */
  0U,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S16>/Out3'
   */
  0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S16>/Out4'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
