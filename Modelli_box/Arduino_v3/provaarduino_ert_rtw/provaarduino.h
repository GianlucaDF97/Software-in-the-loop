/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaarduino.h
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

#ifndef RTW_HEADER_provaarduino_h_
#define RTW_HEADER_provaarduino_h_
#include <math.h>
#include <stddef.h>
#ifndef provaarduino_COMMON_INCLUDES_
#define provaarduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* provaarduino_COMMON_INCLUDES_ */

#include "provaarduino_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  int16_T RT1;                         /* '<Root>/RT1' */
  int16_T RT_g;                        /* '<Root>/RT' */
} B_provaarduino_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder9_DSTATE;     /* '<Root>/S-Function Builder9' */
  real_T SFunctionBuilder4_DSTATE;     /* '<Root>/S-Function Builder4' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  real_T NextOutput_p;                 /* '<S2>/White Noise' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  uint32_T RandSeed_k;                 /* '<S2>/White Noise' */
  int16_T RT1_Buffer0;                 /* '<Root>/RT1' */
  int16_T RT_Buffer0;                  /* '<Root>/RT' */
} DW_provaarduino_T;

/* Parameters (default storage) */
struct P_provaarduino_T_ {
  real_T BandLimitedWhiteNoise2_Cov;
                                   /* Mask Parameter: BandLimitedWhiteNoise2_Cov
                                    * Referenced by: '<S1>/Output'
                                    */
  real_T BandLimitedWhiteNoise3_Cov;
                                   /* Mask Parameter: BandLimitedWhiteNoise3_Cov
                                    * Referenced by: '<S2>/Output'
                                    */
  real_T BandLimitedWhiteNoise2_seed;
                                  /* Mask Parameter: BandLimitedWhiteNoise2_seed
                                   * Referenced by: '<S1>/White Noise'
                                   */
  real_T BandLimitedWhiteNoise3_seed;
                                  /* Mask Parameter: BandLimitedWhiteNoise3_seed
                                   * Referenced by: '<S2>/White Noise'
                                   */
  real_T Constant3_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_Mean_h;            /* Expression: 0
                                        * Referenced by: '<S2>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_d;         /* Computed Parameter: WhiteNoise_StdDev_d
                                       * Referenced by: '<S2>/White Noise'
                                       */
  int16_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  int16_T RT1_InitialCondition;      /* Computed Parameter: RT1_InitialCondition
                                      * Referenced by: '<Root>/RT1'
                                      */
  int16_T RT_InitialCondition;        /* Computed Parameter: RT_InitialCondition
                                       * Referenced by: '<Root>/RT'
                                       */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch2'
                              */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_provaarduino_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_provaarduino_T provaarduino_P;

/* Block signals (default storage) */
extern B_provaarduino_T provaarduino_B;

/* Block states (default storage) */
extern DW_provaarduino_T provaarduino_DW;

/* External function called from main */
extern void provaarduino_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void provaarduino_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void provaarduino_initialize(void);
extern void provaarduino_step0(void);
extern void provaarduino_step1(void);
extern void provaarduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_provaarduino_T *const provaarduino_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'provaarduino'
 * '<S1>'   : 'provaarduino/Band-Limited White Noise2'
 * '<S2>'   : 'provaarduino/Band-Limited White Noise3'
 */
#endif                                 /* RTW_HEADER_provaarduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
