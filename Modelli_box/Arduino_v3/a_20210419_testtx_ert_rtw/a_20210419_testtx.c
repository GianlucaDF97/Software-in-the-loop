/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210419_testtx.c
 *
 * Code generated for Simulink model 'a_20210419_testtx'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May  4 16:38:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a_20210419_testtx.h"
#include "a_20210419_testtx_private.h"

const uint16_T a_20210419_testtx_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_a_20210419_testtx_T a_20210419_testtx_B;

/* Block states (default storage) */
DW_a_20210419_testtx_T a_20210419_testtx_DW;

/* Real-time model */
static RT_MODEL_a_20210419_testtx_T a_20210419_testtx_M_;
RT_MODEL_a_20210419_testtx_T *const a_20210419_testtx_M = &a_20210419_testtx_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void a_20210419_testtx_step(void)
{
  /* local block i/o variables */
  real_T rtb_Add;
  real_T rtb_Gain2;
  real_T rtb_PatohPa1;
  real_T rtb_Sum;
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T tmp;
  int32_T exitg1;
  int32_T i;
  uint8_T dataIn;

  /* DiscretePulseGenerator: '<S5>/Discrete Pulse Generator' */
  rtb_Sum = (a_20210419_testtx_DW.clockTickCounter <
             a_20210419_testtx_P.DiscretePulseGenerator_Duty) &&
    (a_20210419_testtx_DW.clockTickCounter >= 0) ?
    a_20210419_testtx_P.DiscretePulseGenerator_Amp : 0.0;
  if (a_20210419_testtx_DW.clockTickCounter >=
      a_20210419_testtx_P.DiscretePulseGenerator_Period - 1.0) {
    a_20210419_testtx_DW.clockTickCounter = 0;
  } else {
    a_20210419_testtx_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Discrete Pulse Generator' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  tmp = floor(rtb_Sum);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_ap = (uint8_T)(tmp < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Memory: '<S5>/Memory'
   */
  rtb_Add = (a_20210419_testtx_P.Constant_Value +
             a_20210419_testtx_P.Constant1_Value) +
    a_20210419_testtx_DW.Memory_PreviousInput;

  /* Gain: '<S5>/Gain1' */
  rtb_Sum = a_20210419_testtx_P.Gain1_Gain * rtb_Add;

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  a_20210419_testtx_B.DataTypeConversion1 = tmp < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-tmp : (uint32_T)tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  tmp = floor(a_20210419_testtx_P.Constant1_Value_i[0]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion5' */
  a_20210419_testtx_B.DataTypeConversion5[0] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  tmp = floor(a_20210419_testtx_P.Constant1_Value_i[1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion5' */
  a_20210419_testtx_B.DataTypeConversion5[1] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  tmp = floor(a_20210419_testtx_P.Constant1_Value_i[2]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion5' */
  a_20210419_testtx_B.DataTypeConversion5[2] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  for (i = 0; i < 16; i++) {
    /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
     *  Constant: '<S10>/Constant'
     */
    a_20210419_testtx_B.DataTypeConversion_f[i] = (real32_T)
      a_20210419_testtx_P.Constant_Value_d[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    tmp = floor(a_20210419_testtx_P.Constant2_Value[i]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    a_20210419_testtx_B.DataTypeConversion1_f[i] = (uint16_T)(tmp < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  }

  for (i = 0; i < 7; i++) {
    /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    a_20210419_testtx_B.DataTypeConversion2[i] = (real32_T)
      a_20210419_testtx_P.Constant3_Value[i];
  }

  /* SignalConversion generated from: '<S1>/S-Function' incorporates:
   *  Constant: '<S9>/ '
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/load uint16'
   *  Gain: '<S9>/Gain'
   */
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[0] =
    a_20210419_testtx_P.loaduint16_Value;
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)(((uint32_T)
    a_20210419_testtx_P.Gain_Gain_o * a_20210419_testtx_P.Constant2_Value_h) >>
    6);
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[2] =
    a_20210419_testtx_P.Constant_Value_c[0];
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[3] =
    a_20210419_testtx_P.Constant_Value_c[1];
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[4] =
    a_20210419_testtx_P.Constant_Value_c[2];
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[5] =
    a_20210419_testtx_P._Value;

  /* Gain: '<S9>/Gain2' incorporates:
   *  Sin: '<S9>/Sine Wave'
   */
  tmp = floor((sin(a_20210419_testtx_P.SineWave_Freq *
                   a_20210419_testtx_M->Timing.t[0] +
                   a_20210419_testtx_P.SineWave_Phase) *
               a_20210419_testtx_P.SineWave_Amp +
               a_20210419_testtx_P.SineWave_Bias) *
              a_20210419_testtx_P.Gain2_Gain);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Gain: '<S9>/Gain1' incorporates:
   *  Gain: '<S9>/Gain2'
   */
  a_20210419_testtx_B.Gain1 = (int16_T)(((tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp) *
    a_20210419_testtx_P.Gain1_Gain_i) >> 18);

  /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  tmp = floor(a_20210419_testtx_P.Constant3_Value_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion3' */
  a_20210419_testtx_B.B_Remaining = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)
    -(int8_T)(uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S3>/Constant'
   */
  tmp = floor(a_20210419_testtx_P.Constant_Value_dy);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion = tmp < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-tmp : (uint32_T)tmp;

  /* DataTypeConversion: '<S9>/Data Type Conversion4' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  tmp = floor(a_20210419_testtx_P.Constant1_Value_p[0]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* SignalConversion generated from: '<S1>/S-Function' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   */
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)(tmp < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* MATLAB Function: '<S3>/Alarm set' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  tmp = rt_roundd_snf(a_20210419_testtx_P.Constant2_Value_l[0]);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      /* SignalConversion generated from: '<S1>/S-Function' */
      a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[2] = (uint8_T)tmp;
    } else {
      /* SignalConversion generated from: '<S1>/S-Function' */
      a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[2] = 0U;
    }
  } else {
    /* SignalConversion generated from: '<S1>/S-Function' */
    a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[2] = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion4' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  tmp = floor(a_20210419_testtx_P.Constant1_Value_p[1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* SignalConversion generated from: '<S1>/S-Function' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion4'
   */
  a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)(tmp < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* MATLAB Function: '<S3>/Alarm set' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  tmp = rt_roundd_snf(a_20210419_testtx_P.Constant2_Value_l[1]);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      /* SignalConversion generated from: '<S1>/S-Function' */
      a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[3] = (uint8_T)tmp;
    } else {
      /* SignalConversion generated from: '<S1>/S-Function' */
      a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[3] = 0U;
    }
  } else {
    /* SignalConversion generated from: '<S1>/S-Function' */
    a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[3] = MAX_uint8_T;
  }

  if (a_20210419_testtx_P.Constant1_Value_h[0] == 1.0) {
    /* SignalConversion generated from: '<S1>/S-Function' */
    a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[2] = 220U;
    a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[3] = 5U;
  }

  if (a_20210419_testtx_P.Constant1_Value_h[1] == 1.0) {
    /* SignalConversion generated from: '<S1>/S-Function' */
    a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[2] = 216U;
    a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[3] = 4U;
  }

  /* SignalConversion generated from: '<S1>/S-Function' incorporates:
   *  Constant: '<S3>/Type fixed_wing Autopilot generic'
   */
  a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[0] =
    a_20210419_testtx_P.Typefixed_wingAutopilotgeneric_[0];
  a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[1] =
    a_20210419_testtx_P.Typefixed_wingAutopilotgeneric_[1];

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/p simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain * a_20210419_testtx_P.psimulated_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[3] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/q simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain * a_20210419_testtx_P.qsimulated_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[4] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/r simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain * a_20210419_testtx_P.rsimulated_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[5] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain * a_20210419_testtx_P.Constant_Value_l;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[6] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain *
    a_20210419_testtx_P.Constant1_Value_e;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[7] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain *
    a_20210419_testtx_P.Constant2_Value_g;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[8] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  Constant: '<S4>/p simulated'
   *  Constant: '<S4>/phi simulated'
   *  Constant: '<S4>/psi simulated'
   *  Constant: '<S4>/q simulated'
   *  Constant: '<S4>/r simulated'
   *  Constant: '<S4>/theta simulated'
   */
  a_20210419_testtx_B.DataTypeConversion1_p[0] = (real32_T)
    a_20210419_testtx_P.phisimulated_Value;
  a_20210419_testtx_B.DataTypeConversion1_p[1] = (real32_T)
    a_20210419_testtx_P.thetasimulated_Value;
  a_20210419_testtx_B.DataTypeConversion1_p[2] = (real32_T)
    a_20210419_testtx_P.psisimulated_Value;
  a_20210419_testtx_B.DataTypeConversion1_p[3] = (real32_T)
    a_20210419_testtx_P.psimulated_Value;
  a_20210419_testtx_B.DataTypeConversion1_p[4] = (real32_T)
    a_20210419_testtx_P.qsimulated_Value;
  a_20210419_testtx_B.DataTypeConversion1_p[5] = (real32_T)
    a_20210419_testtx_P.rsimulated_Value;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Lat Simulated'
   *  Gain: '<S18>/Gain'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain_e *
    a_20210419_testtx_P.LatSimulated_Value * a_20210419_testtx_P.Gain_Gain_n[0];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_n[0] = tmp < 0.0 ? -(int32_T)(uint32_T)
    -tmp : (int32_T)(uint32_T)tmp;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Long Simulated'
   *  Gain: '<S19>/Gain'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain_l *
    a_20210419_testtx_P.LongSimulated_Value * a_20210419_testtx_P.Gain_Gain_n[1];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_n[1] = tmp < 0.0 ? -(int32_T)(uint32_T)
    -tmp : (int32_T)(uint32_T)tmp;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Alt Simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain_n[2] *
    a_20210419_testtx_P.AltSimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_n[2] = tmp < 0.0 ? -(int32_T)(uint32_T)
    -tmp : (int32_T)(uint32_T)tmp;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/alt_r'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain_n[3] * a_20210419_testtx_P.alt_r_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_n[3] = tmp < 0.0 ? -(int32_T)(uint32_T)
    -tmp : (int32_T)(uint32_T)tmp;

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/v Simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain1_Gain_p *
    a_20210419_testtx_P.vSimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  a_20210419_testtx_B.DataTypeConversion1_g[0] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/vel y'
   */
  rtb_Sum = a_20210419_testtx_P.Gain1_Gain_p * a_20210419_testtx_P.vely_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  a_20210419_testtx_B.DataTypeConversion1_g[1] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/RC Simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain1_Gain_p *
    a_20210419_testtx_P.RCSimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  a_20210419_testtx_B.DataTypeConversion1_g[2] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* Gain: '<S8>/Gain2' incorporates:
   *  Constant: '<S8>/Heading simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain2_Gain_l *
    a_20210419_testtx_P.Headingsimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  a_20210419_testtx_B.DataTypeConversion2_d = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
   *  Constant: '<S6>/Alt simulated'
   *  Constant: '<S6>/RC simulated'
   *  Constant: '<S6>/TAS simulated'
   *  Constant: '<S6>/v simulated'
   */
  a_20210419_testtx_B.DataTypeConversion3[0] = (real32_T)
    a_20210419_testtx_P.TASsimulated_Value;
  a_20210419_testtx_B.DataTypeConversion3[1] = (real32_T)
    a_20210419_testtx_P.vsimulated_Value;
  a_20210419_testtx_B.DataTypeConversion3[2] = (real32_T)
    a_20210419_testtx_P.Altsimulated_Value;
  a_20210419_testtx_B.DataTypeConversion3[3] = (real32_T)
    a_20210419_testtx_P.RCsimulated_Value;

  /* DataTypeConversion: '<S6>/Data Type Conversion4' incorporates:
   *  Constant: '<S6>/ Heading simulated'
   */
  tmp = floor(a_20210419_testtx_P.Headingsimulated_Value_j);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion4' */
  a_20210419_testtx_B.DataTypeConversion4_j = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S6>/Data Type Conversion5' incorporates:
   *  Constant: '<S6>/Rpm simulated'
   */
  tmp = floor(a_20210419_testtx_P.Rpmsimulated_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion5' */
  a_20210419_testtx_B.DataTypeConversion5_o = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Gain: '<S14>/Gain2' incorporates:
   *  Constant: '<S7>/Manetta Simulated'
   */
  rtb_Gain2 = a_20210419_testtx_P.Gain2_Gain_g *
    a_20210419_testtx_P.ManettaSimulated_Value;

  /* Sum: '<S14>/Sum' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S7>/Equilibratore Simulated'
   *  Gain: '<S15>/Gain'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain_i *
    a_20210419_testtx_P.EquilibratoreSimulated_Value +
    a_20210419_testtx_P.Constant2_Value_f;

  /* Sum: '<S14>/Sum1' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S7>/Alettoni Simulated'
   *  Gain: '<S16>/Gain'
   */
  rtb_Sum1 = a_20210419_testtx_P.Gain_Gain_lr *
    a_20210419_testtx_P.AlettoniSimulated_Value +
    a_20210419_testtx_P.Constant2_Value_f;

  /* Sum: '<S14>/Sum2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S7>/Timone Simulated'
   *  Gain: '<S17>/Gain'
   */
  rtb_Sum2 = a_20210419_testtx_P.Gain_Gain_m *
    a_20210419_testtx_P.TimoneSimulated_Value +
    a_20210419_testtx_P.Constant2_Value_f;

  /* Gain: '<S7>/Gain' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  rtb_PatohPa1 = a_20210419_testtx_P.Gain_Gain_p *
    a_20210419_testtx_P.Constant2_Value_b;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_PatohPa1 > a_20210419_testtx_P.Saturation_UpperSat) {
    rtb_PatohPa1 = a_20210419_testtx_P.Saturation_UpperSat;
  } else {
    if (rtb_PatohPa1 < a_20210419_testtx_P.Saturation_LowerSat) {
      rtb_PatohPa1 = a_20210419_testtx_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (a_20210419_testtx_P.Constant_Value_k < 0.0) {
    tmp = ceil(a_20210419_testtx_P.Constant_Value_k);
  } else {
    tmp = floor(a_20210419_testtx_P.Constant_Value_k);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[0] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  if (rtb_Gain2 < 0.0) {
    tmp = ceil(rtb_Gain2);
  } else {
    tmp = floor(rtb_Gain2);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[1] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[2] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  if (rtb_Sum1 < 0.0) {
    tmp = ceil(rtb_Sum1);
  } else {
    tmp = floor(rtb_Sum1);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[3] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  if (rtb_Sum2 < 0.0) {
    tmp = ceil(rtb_Sum2);
  } else {
    tmp = floor(rtb_Sum2);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[4] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/ACC simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain *
    a_20210419_testtx_P.ACCsimulated_Value[0];

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[0] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  if (a_20210419_testtx_P.Constant1_Value_n[0] < 0.0) {
    tmp = ceil(a_20210419_testtx_P.Constant1_Value_n[0]);
  } else {
    tmp = floor(a_20210419_testtx_P.Constant1_Value_n[0]);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[5] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/ACC simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain *
    a_20210419_testtx_P.ACCsimulated_Value[1];

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[1] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  if (a_20210419_testtx_P.Constant1_Value_n[1] < 0.0) {
    tmp = ceil(a_20210419_testtx_P.Constant1_Value_n[1]);
  } else {
    tmp = floor(a_20210419_testtx_P.Constant1_Value_n[1]);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[6] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S4>/ACC simulated'
   */
  rtb_Sum = a_20210419_testtx_P.Gain_Gain *
    a_20210419_testtx_P.ACCsimulated_Value[2];

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Sum < 0.0) {
    tmp = ceil(rtb_Sum);
  } else {
    tmp = floor(rtb_Sum);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  a_20210419_testtx_B.DataTypeConversion_k[2] = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  if (a_20210419_testtx_P.Constant1_Value_n[2] < 0.0) {
    tmp = ceil(a_20210419_testtx_P.Constant1_Value_n[2]);
  } else {
    tmp = floor(a_20210419_testtx_P.Constant1_Value_n[2]);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[7] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  if (rtb_PatohPa1 < 0.0) {
    tmp = ceil(rtb_PatohPa1);
  } else {
    tmp = floor(rtb_PatohPa1);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  a_20210419_testtx_B.Heading[8] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Memory: '<S1>/Memory' */
  a_20210419_testtx_B.Memory = a_20210419_testtx_DW.Memory_PreviousInput_l;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  a_20210419_testtx_B.DataTypeConversion3_n = (real32_T)
    a_20210419_testtx_P.Constant1_Value_g;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Gain: '<S1>/Pa to hPa'
   */
  a_20210419_testtx_B.DataTypeConversion_a = (real32_T)
    (a_20210419_testtx_P.PatohPa_Gain * a_20210419_testtx_P.Constant6_Value);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S1>/Pa to hPa1'
   */
  a_20210419_testtx_B.DataTypeConversion1_b = (real32_T)
    (a_20210419_testtx_P.PatohPa1_Gain * a_20210419_testtx_P.Constant3_Value_j);

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Constant: '<S1>/Constant11'
   */
  tmp = floor(a_20210419_testtx_P.Constant11_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  a_20210419_testtx_B.DataTypeConversion2_i = (int16_T)(tmp < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   *  Constant: '<S9>/onboard_control_sensor_present uint32'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&a_20210419_testtx_B.DataTypeConversion_ap,
     &a_20210419_testtx_B.DataTypeConversion1,
     &a_20210419_testtx_P.Constant_Value_i,
     &a_20210419_testtx_B.DataTypeConversion5[0],
     &a_20210419_testtx_B.DataTypeConversion_f[0],
     &a_20210419_testtx_B.DataTypeConversion1_f[0],
     &a_20210419_testtx_B.DataTypeConversion2[0],
     &a_20210419_testtx_P.onboard_control_sensor_presentu[0],
     &a_20210419_testtx_B.TmpSignalConversionAtSFunctionI[0],
     &a_20210419_testtx_B.Gain1, &a_20210419_testtx_B.B_Remaining,
     &a_20210419_testtx_B.DataTypeConversion,
     &a_20210419_testtx_B.TmpSignalConversionAtSFunctio_m[0],
     &a_20210419_testtx_B.DataTypeConversion_k[0],
     &a_20210419_testtx_B.DataTypeConversion1_p[0],
     &a_20210419_testtx_B.DataTypeConversion_n[0],
     &a_20210419_testtx_B.DataTypeConversion1_g[0],
     &a_20210419_testtx_B.DataTypeConversion2_d,
     &a_20210419_testtx_B.DataTypeConversion3[0],
     &a_20210419_testtx_B.DataTypeConversion4_j,
     &a_20210419_testtx_B.DataTypeConversion5_o, &a_20210419_testtx_B.Heading[0],
     &a_20210419_testtx_B.Memory, &a_20210419_testtx_B.DataTypeConversion3_n,
     &a_20210419_testtx_P.Constant4_Value,
     &a_20210419_testtx_P.Constant2_Value_j,
     &a_20210419_testtx_P.Constant5_Value,
     &a_20210419_testtx_B.DataTypeConversion_a,
     &a_20210419_testtx_B.DataTypeConversion1_b,
     &a_20210419_testtx_B.DataTypeConversion2_i,
     &a_20210419_testtx_P.Constant7_Value[0],
     &a_20210419_testtx_P.Constant8_Value, &a_20210419_testtx_P.Constant9_Value,
     &a_20210419_testtx_P.Constant10_Value, ((const uint16_T*)
      &a_20210419_testtx_U16GND), &a_20210419_testtx_B.SFunction_o1,
     &a_20210419_testtx_B.SFunction_o2[0], &a_20210419_testtx_B.SFunction_o3,
     &a_20210419_testtx_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S1>/Enable ' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* SignalConversion generated from: '<S2>/Enable' */
  if (a_20210419_testtx_B.SFunction_o1 > 0) {
    /* Chart: '<S2>/Chart' */
    if (a_20210419_testtx_DW.is_active_c9_a_20210419_testtx == 0U) {
      a_20210419_testtx_DW.is_active_c9_a_20210419_testtx = 1U;
      a_20210419_testtx_DW.i = 1U;
    } else {
      do {
        exitg1 = 0;
        if (a_20210419_testtx_DW.obj.Protocol !=
            a_20210419_testtx_P.SerialTransmit_Protocol) {
          a_20210419_testtx_DW.obj.Protocol =
            a_20210419_testtx_P.SerialTransmit_Protocol;
        }

        dataIn = a_20210419_testtx_B.SFunction_o2[a_20210419_testtx_DW.i - 1];
        MW_Serial_write(a_20210419_testtx_DW.obj.port, &dataIn, 1.0,
                        a_20210419_testtx_DW.obj.dataSizeInBytes,
                        a_20210419_testtx_DW.obj.sendModeEnum,
                        a_20210419_testtx_DW.obj.dataType,
                        a_20210419_testtx_DW.obj.sendFormatEnum, 2.0, '\x00');
        if (a_20210419_testtx_DW.i < a_20210419_testtx_B.SFunction_o3) {
          i = a_20210419_testtx_DW.i + 1;
          if (a_20210419_testtx_DW.i + 1 > 255) {
            i = 255;
          }

          a_20210419_testtx_DW.i = (uint8_T)i;
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      a_20210419_testtx_DW.i = 1U;
    }

    /* End of Chart: '<S2>/Chart' */
  }

  /* End of SignalConversion generated from: '<S2>/Enable' */
  /* End of Outputs for SubSystem: '<S1>/Enable ' */

  /* Update for Memory: '<S5>/Memory' */
  a_20210419_testtx_DW.Memory_PreviousInput = rtb_Add;

  /* Update for Memory: '<S1>/Memory' */
  a_20210419_testtx_DW.Memory_PreviousInput_l = a_20210419_testtx_B.SFunction_o4;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  a_20210419_testtx_M->Timing.t[0] =
    ((time_T)(++a_20210419_testtx_M->Timing.clockTick0)) *
    a_20210419_testtx_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    a_20210419_testtx_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void a_20210419_testtx_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&a_20210419_testtx_M->solverInfo,
                          &a_20210419_testtx_M->Timing.simTimeStep);
    rtsiSetTPtr(&a_20210419_testtx_M->solverInfo, &rtmGetTPtr
                (a_20210419_testtx_M));
    rtsiSetStepSizePtr(&a_20210419_testtx_M->solverInfo,
                       &a_20210419_testtx_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&a_20210419_testtx_M->solverInfo, (&rtmGetErrorStatus
      (a_20210419_testtx_M)));
    rtsiSetRTModelPtr(&a_20210419_testtx_M->solverInfo, a_20210419_testtx_M);
  }

  rtsiSetSimTimeStep(&a_20210419_testtx_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&a_20210419_testtx_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(a_20210419_testtx_M, &a_20210419_testtx_M->Timing.tArray[0]);
  a_20210419_testtx_M->Timing.stepSize0 = 0.02;

  {
    real_T tmp;
    uint8_T tmp_0;

    /* InitializeConditions for Memory: '<S5>/Memory' */
    a_20210419_testtx_DW.Memory_PreviousInput =
      a_20210419_testtx_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    a_20210419_testtx_DW.Memory_PreviousInput_l =
      a_20210419_testtx_P.Memory_InitialCondition_j;

    /* SystemInitialize for Enabled SubSystem: '<S1>/Enable ' */
    /* SystemInitialize for Chart: '<S2>/Chart' incorporates:
     *  SubSystem: '<S11>/sendbyte'
     */
    /* Start for MATLABSystem: '<S12>/Serial Transmit' */
    a_20210419_testtx_DW.obj.matlabCodegenIsDeleted = false;
    a_20210419_testtx_DW.obj.Protocol =
      a_20210419_testtx_P.SerialTransmit_Protocol;
    a_20210419_testtx_DW.obj.isInitialized = 1;
    a_20210419_testtx_DW.obj.port = 2.0;
    a_20210419_testtx_DW.obj.dataSizeInBytes = 1.0;
    a_20210419_testtx_DW.obj.dataType = 0.0;
    a_20210419_testtx_DW.obj.sendModeEnum = 0.0;
    a_20210419_testtx_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(a_20210419_testtx_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    a_20210419_testtx_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S12>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S1>/Enable ' */
  }
}

/* Model terminate function */
void a_20210419_testtx_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S1>/Enable ' */
  /* Terminate for Chart: '<S2>/Chart' incorporates:
   *  SubSystem: '<S11>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S12>/Serial Transmit' */
  if (!a_20210419_testtx_DW.obj.matlabCodegenIsDeleted) {
    a_20210419_testtx_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S12>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S1>/Enable ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
