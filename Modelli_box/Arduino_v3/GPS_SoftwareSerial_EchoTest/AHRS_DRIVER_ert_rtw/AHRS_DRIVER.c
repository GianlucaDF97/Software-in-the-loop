/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AHRS_DRIVER.c
 *
 * Code generated for Simulink model 'AHRS_DRIVER'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 08:57:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AHRS_DRIVER.h"
#include "AHRS_DRIVER_private.h"

/* Block signals (default storage) */
B_AHRS_DRIVER_T AHRS_DRIVER_B;

/* Block states (default storage) */
DW_AHRS_DRIVER_T AHRS_DRIVER_DW;

/* Real-time model */
static RT_MODEL_AHRS_DRIVER_T AHRS_DRIVER_M_;
RT_MODEL_AHRS_DRIVER_T *const AHRS_DRIVER_M = &AHRS_DRIVER_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void AHRS_DRIVER_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(AHRS_DRIVER_M, 1));
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AHRS_DRIVER_M->Timing.TaskCounters.TID[1])++;
  if ((AHRS_DRIVER_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [1.0s, 0.0s] */
    AHRS_DRIVER_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void AHRS_DRIVER_step0(void)           /* Sample time: [0.02s, 0.0s] */
{
  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void AHRS_DRIVER_step1(void)           /* Sample time: [1.0s, 0.0s] */
{
  /* S-Function (Mti): '<Root>/S-Function Builder' */
  Mti_Outputs_wrapper(&AHRS_DRIVER_B.SFunctionBuilder[0],
                      &AHRS_DRIVER_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <Root>/S-Function Builder */
  Mti_Update_wrapper(&AHRS_DRIVER_B.SFunctionBuilder[0],
                     &AHRS_DRIVER_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void AHRS_DRIVER_initialize(void)
{
  /* Start for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  Mti_Start_wrapper(&AHRS_DRIVER_DW.SFunctionBuilder_DSTATE);

  /* InitializeConditions for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        AHRS_DRIVER_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void AHRS_DRIVER_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
