//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model_data.cpp
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.217
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Mon May 22 17:11:12 2023
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Aenea_model.h"
#include "Aenea_model_private.h"

// Invariant block signals (default storage)
const ConstB_Aenea_model_T Aenea_model_ConstB = {
  0.011111111111111112
  ,                                    // '<S22>/USCITA PERCENTUALE'
  780.0
  ,                                    // '<S601>/Sum3'
  798.0
  ,                                    // '<S598>/Sum1'
  798.0
  ,                                    // '<S599>/Sum1'
  672.0
  ,                                    // '<S596>/Sum1'
  672.0
  ,                                    // '<S597>/Sum1'
  630.0
  ,                                    // '<S600>/Sum2'
  780.0
  ,                                    // '<S604>/Sum1'
  798.0
  ,                                    // '<S605>/Sum2'
  672.0
  ,                                    // '<S602>/Sum2'
  630.0
  ,                                    // '<S603>/Sum2'
  0U
  ,                                    // '<S21>/Gain'
  0U
  ,                                    // '<S22>/Data Type Conversion2'
  128
  ,                                    // '<S8>/Gain3'
  0
  ,                                    // '<S21>/Gain2'
  0
  ,                                    // '<S21>/Gain1'
  0
  // '<S21>/Data Type Conversion3'
};

// Constant parameters (default storage)
const ConstP_Aenea_model_T Aenea_model_ConstP = {
  // Expression: R1B
  //  Referenced by: '<S6>/Constant13'

  { 2.0E-14, 2.0E-14, 0.1444, 0.2, 0.2, 0.0001486, 9.403E-5, 0.0001648,
    0.0002934, 2.887E-5, 0.003258 },

  // Expression: Q1B
  //  Referenced by: '<S6>/Constant16'

  { 2.0E-15, 2.0E-15, 0.001, 0.04, 0.04, 5.0E-5, 0.00019943, 7.324E-5, 0.0001065,
    2.6647799999999998E-6, 2.6647799999999998E-6, 3.55304E-5, 6.0E-20, 6.0E-20,
    6.0E-20, 6.0E-15, 6.0E-15, 6.0E-15 },

  // Computed Parameter: onboard_control_sensor_presentu
  //  Referenced by: '<S21>/onboard_control_sensor_present uint32'

  { 1U, 1U, 1U },

  // Computed Parameter: SIUAVuint8_Value
  //  Referenced by: '<S1>/SI UAV uint8'

  100U
};

//
// File trailer for generated code.
//
// [EOF]
//
