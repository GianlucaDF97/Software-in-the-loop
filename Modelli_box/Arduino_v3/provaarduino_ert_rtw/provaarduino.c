/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaarduino.c
 *
 * Code generated for Simulink model 'provaarduino'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 16:03:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaarduino.h"
#include "provaarduino_private.h"

/* Block signals (default storage) */
B_provaarduino_T provaarduino_B;

/* Block states (default storage) */
DW_provaarduino_T provaarduino_DW;

/* Real-time model */
static RT_MODEL_provaarduino_T provaarduino_M_;
RT_MODEL_provaarduino_T *const provaarduino_M = &provaarduino_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void provaarduino_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(provaarduino_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  provaarduino_M->Timing.RateInteraction.TID0_1 =
    (provaarduino_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (provaarduino_M->Timing.TaskCounters.TID[1])++;
  if ((provaarduino_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    provaarduino_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function for TID0 */
void provaarduino_step0(void)          /* Sample time: [0.02s, 0.0s] */
{
  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/RT1' */
  if (provaarduino_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<Root>/RT1' */
    provaarduino_B.RT1 = provaarduino_DW.RT1_Buffer0;
  }

  /* End of RateTransition: '<Root>/RT1' */

  /* S-Function (Servo_microseconds_equilibratore_beta_3): '<Root>/S-Function Builder9' */
  Servo_microseconds_equilibratore_beta_3_Outputs_wrapper(&provaarduino_B.RT1,
    &provaarduino_DW.SFunctionBuilder9_DSTATE);

  /* RateTransition: '<Root>/RT' */
  if (provaarduino_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<Root>/RT' */
    provaarduino_B.RT_g = provaarduino_DW.RT_Buffer0;
  }

  /* End of RateTransition: '<Root>/RT' */

  /* S-Function (Servo_microseconds_manetta_beta_3): '<Root>/S-Function Builder4' */
  Servo_microseconds_manetta_beta_3_Outputs_wrapper(&provaarduino_B.RT_g,
    &provaarduino_DW.SFunctionBuilder4_DSTATE);

  /* Update for S-Function (Servo_microseconds_equilibratore_beta_3): '<Root>/S-Function Builder9' */

  /* S-Function "Servo_microseconds_equilibratore_beta_3_wrapper" Block: <Root>/S-Function Builder9 */
  Servo_microseconds_equilibratore_beta_3_Update_wrapper(&provaarduino_B.RT1,
    &provaarduino_DW.SFunctionBuilder9_DSTATE);

  /* Update for S-Function (Servo_microseconds_manetta_beta_3): '<Root>/S-Function Builder4' */

  /* S-Function "Servo_microseconds_manetta_beta_3_wrapper" Block: <Root>/S-Function Builder4 */
  Servo_microseconds_manetta_beta_3_Update_wrapper(&provaarduino_B.RT_g,
    &provaarduino_DW.SFunctionBuilder4_DSTATE);
}

/* Model step function for TID1 */
void provaarduino_step1(void)          /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp;
  int16_T rtb_DataTypeConversion;

  /* ManualSwitch: '<Root>/Manual Switch2' */
  if (provaarduino_P.ManualSwitch2_CurrentSetting == 1) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    tmp = floor(provaarduino_P.Constant3_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_DataTypeConversion = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Gain: '<S1>/Output'
     *  RandomNumber: '<S1>/White Noise'
     */
    tmp = floor(sqrt(provaarduino_P.BandLimitedWhiteNoise2_Cov) /
                0.31622776601683794 * provaarduino_DW.NextOutput);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_DataTypeConversion = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* RateTransition: '<Root>/RT1' */
  provaarduino_DW.RT1_Buffer0 = rtb_DataTypeConversion;

  /* ManualSwitch: '<Root>/Manual Switch3' */
  if (provaarduino_P.ManualSwitch3_CurrentSetting == 1) {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    rtb_DataTypeConversion = provaarduino_P.Constant4_Value;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Gain: '<S2>/Output'
     *  RandomNumber: '<S2>/White Noise'
     */
    tmp = floor(sqrt(provaarduino_P.BandLimitedWhiteNoise3_Cov) /
                0.31622776601683794 * provaarduino_DW.NextOutput_p);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    rtb_DataTypeConversion = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of ManualSwitch: '<Root>/Manual Switch3' */

  /* RateTransition: '<Root>/RT' */
  provaarduino_DW.RT_Buffer0 = rtb_DataTypeConversion;

  /* Update for RandomNumber: '<S1>/White Noise' */
  provaarduino_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&provaarduino_DW.RandSeed) * provaarduino_P.WhiteNoise_StdDev +
    provaarduino_P.WhiteNoise_Mean;

  /* Update for RandomNumber: '<S2>/White Noise' */
  provaarduino_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
    (&provaarduino_DW.RandSeed_k) * provaarduino_P.WhiteNoise_StdDev_d +
    provaarduino_P.WhiteNoise_Mean_h;
}

/* Model initialize function */
void provaarduino_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* Start for RateTransition: '<Root>/RT1' */
    provaarduino_B.RT1 = provaarduino_P.RT1_InitialCondition;

    /* Start for RateTransition: '<Root>/RT' */
    provaarduino_B.RT_g = provaarduino_P.RT_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/RT1' */
    provaarduino_DW.RT1_Buffer0 = provaarduino_P.RT1_InitialCondition;

    /* InitializeConditions for S-Function (Servo_microseconds_equilibratore_beta_3): '<Root>/S-Function Builder9' */

    /* S-Function Block: <Root>/S-Function Builder9 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provaarduino_DW.SFunctionBuilder9_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for RateTransition: '<Root>/RT' */
    provaarduino_DW.RT_Buffer0 = provaarduino_P.RT_InitialCondition;

    /* InitializeConditions for S-Function (Servo_microseconds_manetta_beta_3): '<Root>/S-Function Builder4' */

    /* S-Function Block: <Root>/S-Function Builder4 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          provaarduino_DW.SFunctionBuilder4_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(provaarduino_P.BandLimitedWhiteNoise2_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    provaarduino_DW.RandSeed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) +
      t) + r;
    if (provaarduino_DW.RandSeed < 1U) {
      provaarduino_DW.RandSeed = 1144108930U;
    } else {
      if (provaarduino_DW.RandSeed > 2147483646U) {
        provaarduino_DW.RandSeed = 2147483646U;
      }
    }

    provaarduino_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&provaarduino_DW.RandSeed) * provaarduino_P.WhiteNoise_StdDev +
      provaarduino_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S2>/White Noise' */
    tmp = floor(provaarduino_P.BandLimitedWhiteNoise3_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    provaarduino_DW.RandSeed_k = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U)
      + t) + r;
    if (provaarduino_DW.RandSeed_k < 1U) {
      provaarduino_DW.RandSeed_k = 1144108930U;
    } else {
      if (provaarduino_DW.RandSeed_k > 2147483646U) {
        provaarduino_DW.RandSeed_k = 2147483646U;
      }
    }

    provaarduino_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&provaarduino_DW.RandSeed_k) * provaarduino_P.WhiteNoise_StdDev_d +
      provaarduino_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S2>/White Noise' */
  }
}

/* Model terminate function */
void provaarduino_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
