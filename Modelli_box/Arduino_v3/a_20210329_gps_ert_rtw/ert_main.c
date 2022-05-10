#include "a_20210329_gps.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_work.h"

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

  a_20210329_gps_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
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
  rtmSetErrorStatus(a_20210329_gps_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  a_20210329_gps_initialize();
  noInterrupts();
  interrupts();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(a_20210329_gps_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(a_20210329_gps_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(a_20210329_gps_M, true);
    }
  }

  rtERTExtModeStartMsg();
  noInterrupts();
  configureArduinoARMTimer();
  runModel =
    (rtmGetErrorStatus(a_20210329_gps_M) == (NULL)) && !rtmGetStopRequested
    (a_20210329_gps_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  XcpStatus lastXcpState = xcpStatusGet();
  interrupts();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(a_20210329_gps_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(a_20210329_gps_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(a_20210329_gps_M) == (NULL)) &&
                      !rtmGetStopRequested(a_20210329_gps_M));
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
  a_20210329_gps_terminate();
  rtExtModeShutdown(1);
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}
