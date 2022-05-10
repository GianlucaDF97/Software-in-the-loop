/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rasp_to_ardu.c
 *
 * Code generated for Simulink model 'rasp_to_ardu'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  1 08:57:16 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rasp_to_ardu.h"
#include "rasp_to_ardu_private.h"

/* Block states (default storage) */
DW_rasp_to_ardu_T rasp_to_ardu_DW;

/* Real-time model */
static RT_MODEL_rasp_to_ardu_T rasp_to_ardu_M_;
RT_MODEL_rasp_to_ardu_T *const rasp_to_ardu_M = &rasp_to_ardu_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void rasp_to_ardu_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rasp_to_ardu_M, 1));
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
  (rasp_to_ardu_M->Timing.TaskCounters.TID[1])++;
  if ((rasp_to_ardu_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.02s, 0.0s] */
    rasp_to_ardu_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void rasp_to_ardu_step0(void)          /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void rasp_to_ardu_step1(void)          /* Sample time: [0.02s, 0.0s] */
{
  /* S-Function (from_raspberry): '<Root>/S-Function Builder' */
  from_raspberry_Outputs_wrapper(&rasp_to_ardu_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (from_raspberry): '<Root>/S-Function Builder' */

  /* S-Function "from_raspberry_wrapper" Block: <Root>/S-Function Builder */
  from_raspberry_Update_wrapper(&rasp_to_ardu_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void rasp_to_ardu_initialize(void)
{
  /* Start for S-Function (from_raspberry): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  from_raspberry_Start_wrapper(&rasp_to_ardu_DW.SFunctionBuilder_DSTATE);

  /* InitializeConditions for S-Function (from_raspberry): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        rasp_to_ardu_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void rasp_to_ardu_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
