//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model_data.cpp
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.81
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Tue Dec 20 14:13:44 2022
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
  ,                                    // '<S20>/USCITA PERCENTUALE'
  1.0
  ,                                    // '<S7>/Data Type Conversion5'
  0.0
  ,                                    // '<S7>/Switch'
  1.0
  ,                                    // '<S7>/Data Type Conversion13'
  1.0
  ,                                    // '<S7>/Data Type Conversion16'
  1.0
  ,                                    // '<S7>/Data Type Conversion14'
  1.0
  ,                                    // '<S7>/Data Type Conversion17'
  1.0
  ,                                    // '<S7>/Data Type Conversion15'
  100.0
  ,                                    // '<S17>/Gain'
  100.0
  ,                                    // '<S17>/Saturation'
  0.01
  ,                                    // '<S2>/Pa to hPa1'
  0U
  ,                                    // '<S14>/Data Type Conversion'
  0.01F
  ,                                    // '<S2>/Data Type Conversion1'
  0U
  ,                                    // '<S19>/Gain'
  0U
  ,                                    // '<S20>/Data Type Conversion2'
  128
  ,                                    // '<S6>/Gain3'
  0
  ,                                    // '<S19>/Gain2'
  0
  ,                                    // '<S19>/Gain1'
  0
  // '<S19>/Data Type Conversion3'
};

// Constant parameters (default storage)
const ConstP_Aenea_model_T Aenea_model_ConstP = {
  // Expression: R1B
  //  Referenced by: '<S4>/Constant13'

  { 2.0E-14, 2.0E-14, 0.1444, 0.2, 0.2, 0.0001486, 9.403E-5, 0.0001648,
    0.0002934, 2.887E-5, 0.003258 },

  // Expression: Q1B
  //  Referenced by: '<S4>/Constant16'

  { 2.0E-15, 2.0E-15, 0.001, 0.04, 0.04, 5.0E-5, 0.00019943, 7.324E-5, 0.0001065,
    2.6647799999999998E-6, 2.6647799999999998E-6, 3.55304E-5, 6.0E-20, 6.0E-20,
    6.0E-20, 6.0E-15, 6.0E-15, 6.0E-15 },

  // Computed Parameter: onboard_control_sensor_presentu
  //  Referenced by: '<S19>/onboard_control_sensor_present uint32'

  { 1U, 1U, 1U },

  // Computed Parameter: SIUAVuint8_Value
  //  Referenced by: '<Root>/SI UAV uint8'

  100U
};

//
// File trailer for generated code.
//
// [EOF]
//
