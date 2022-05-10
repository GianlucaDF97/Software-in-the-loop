/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_work.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  untitled1_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  untitled1_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;

#ifndef _MW_ARDUINO_LOOP_

    interrupts();

#endif;

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      untitled1_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

#ifndef _MW_ARDUINO_LOOP_

    noInterrupts();

#endif;

    need2runFlags[1]--;
    isRateRunning[1]--;
  }

  rtExtModeCheckEndTrigger();
}

extern void rtIOStreamResync();
volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.02;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(untitled1_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  untitled1_initialize();
  noInterrupts();
  interrupts();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(untitled1_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(untitled1_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(untitled1_M, true);
    }
  }

  rtERTExtModeStartMsg();
  noInterrupts();
  configureArduinoARMTimer();
  runModel =
    (rtmGetErrorStatus(untitled1_M) == (NULL)) && !rtmGetStopRequested
    (untitled1_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  XcpStatus lastXcpState = xcpStatusGet();
  interrupts();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(untitled1_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(untitled1_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(untitled1_M) == (NULL)) &&
                      !rtmGetStopRequested(untitled1_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disable_rt_OneStep();
    if (lastXcpState==XCP_CONNECTED && xcpStatusGet()==XCP_DISCONNECTED)
      rtIOStreamResync();
    lastXcpState = xcpStatusGet();
    MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  untitled1_terminate();
  rtExtModeShutdown(2);
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
