/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Jun  9 15:57:30 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_private.h"

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void untitled1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(untitled1_M, 1));
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
  untitled1_M->Timing.RateInteraction.TID0_1 =
    (untitled1_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled1_M->Timing.TaskCounters.TID[1])++;
  if ((untitled1_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    untitled1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void untitled1_step0(void)             /* Sample time: [0.02s, 0.0s] */
{
  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<Root>/S-Function Builder' */
  if (untitled1_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/S-Function Builder' */
    untitled1_B.TmpRTBAtSFunctionBuilderInport1 =
      untitled1_DW.TmpRTBAtSFunctionBuilderInport1;
  }

  /* End of RateTransition generated from: '<Root>/S-Function Builder' */

  /* S-Function (Mti): '<Root>/S-Function Builder' */
  Mti_Outputs_wrapper(&untitled1_B.TmpRTBAtSFunctionBuilderInport1,
                      &untitled1_B.SFunctionBuilder,
                      &untitled1_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <Root>/S-Function Builder */
  Mti_Update_wrapper(&untitled1_B.TmpRTBAtSFunctionBuilderInport1,
                     &untitled1_B.SFunctionBuilder,
                     &untitled1_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)untitled1_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(untitled1_M)!=-1) &&
        !((rtmGetTFinal(untitled1_M)-untitled1_M->Timing.taskTime0) >
          untitled1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled1_M)) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.taskTime0 =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void untitled1_step1(void)             /* Sample time: [0.1s, 0.0s] */
{
  int32_T rtb_DataTypeConversion;
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (untitled1_DW.obj.Protocol != untitled1_P.SerialReceive_Protocol) {
    untitled1_DW.obj.Protocol = untitled1_P.SerialReceive_Protocol;
  }

  /* MATLABSystem: '<Root>/Serial Receive' */
  MW_Serial_read(1, untitled1_DW.obj.DataSizeInBytes,
                 &untitled1_B.SerialReceive_o1, &status);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_DataTypeConversion = untitled1_B.SerialReceive_o1;

  /* RateTransition generated from: '<Root>/S-Function Builder' */
  untitled1_DW.TmpRTBAtSFunctionBuilderInport1 = rtb_DataTypeConversion;
  rtExtModeUpload(1, (real_T)((untitled1_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled1_M->Timing.clockTick1++;
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled1_M, -1);
  untitled1_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (2286685715U);
  untitled1_M->Sizes.checksums[1] = (2873808520U);
  untitled1_M->Sizes.checksums[2] = (2394226751U);
  untitled1_M->Sizes.checksums[3] = (2919223279U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* Start for RateTransition generated from: '<Root>/S-Function Builder' */
  untitled1_B.TmpRTBAtSFunctionBuilderInport1 =
    untitled1_P.TmpRTBAtSFunctionBuilderInport1;

  /* Start for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  Mti_Start_wrapper(&untitled1_DW.SFunctionBuilder_DSTATE);

  /* InitializeConditions for RateTransition generated from: '<Root>/S-Function Builder' */
  untitled1_DW.TmpRTBAtSFunctionBuilderInport1 =
    untitled1_P.TmpRTBAtSFunctionBuilderInport1;

  /* InitializeConditions for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        untitled1_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }

  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.Protocol = untitled1_P.SerialReceive_Protocol;
  untitled1_DW.obj.isInitialized = 1;
  untitled1_DW.obj.DataTypeWidth = 1U;
  untitled1_DW.obj.DataSizeInBytes = untitled1_DW.obj.DataTypeWidth;
  MW_SCI_Open(1);
  untitled1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
