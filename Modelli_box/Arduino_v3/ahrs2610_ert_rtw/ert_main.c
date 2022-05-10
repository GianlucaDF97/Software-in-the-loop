/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ahrs2610'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 13:11:55 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ahrs2610.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  ahrs2610_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
}

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
  rtmSetErrorStatus(ahrs2610_M, 0);
  ahrs2610_initialize();
  noInterrupts();
  configureArduinoARMTimer();
  runModel =
    rtmGetErrorStatus(ahrs2610_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(ahrs2610_M) == (NULL));
    MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  ahrs2610_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
