/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'prova2'.
 *
 * Model version                  : 1.285
 * Simulink Coder version         : 8.2 (R2012a) 29-Dec-2011
 * TLC version                    : 8.2 (Dec 29 2011)
 * C/C++ source code generated on : Sat Jan 19 14:27:22 2013
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova2.h"
#include "Arduino.h"
#include <ext_work.h>                  /* External mode header files */
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
#define STEP_SIZE                      (unsigned long) (10000)

int_T main(void)
{
  unsigned long oldtime = 0;
  init();

  /* initialize external mode */
  ExtParseArgsAndInitUD(0, NULL);
  prova2_initialize();

  /* External mode */
  rtERTExtModeSetTFinal(&rtmGetTFinal(prova2_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = FALSE;
    rtExtModeWaitForStartPkt(prova2_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(prova2_M, TRUE);
    }
  }

  rtERTExtModeStartMsg();

  /* This pin indicates the base rate overrun */
  pinMode(13, OUTPUT);

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 57600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 57600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 57600);

#endif

  /* The main step loop */
  while ((rtmGetErrorStatus(prova2_M) == (NULL)) && !rtmGetStopRequested
         (prova2_M)) {
    if ((unsigned long) (micros() - oldtime) >= STEP_SIZE) {
      oldtime = micros();

      /* External mode */
      {
        boolean_T rtmStopReq = FALSE;
        rtExtModeOneStep(prova2_M->extModeInfo, 1, &rtmStopReq);
        if (rtmStopReq) {
          rtmSetStopRequested(prova2_M, TRUE);
        }
      }

      prova2_output();

      /* Get model outputs here */

      /* External mode */
      rtExtModeUploadCheckTrigger(1);

      {                                /* Sample time: [0.01s, 0.0s] */
        rtExtModeUpload(0, prova2_M->Timing.taskTime0);
      }

      prova2_update();
      rtExtModeCheckEndTrigger();

      /* Check for overrun */
      if ((unsigned long) (micros() - oldtime) > STEP_SIZE) {
        digitalWrite(13, 1);
      }
    }
  }

  rtExtModeShutdown(1);
  delay(1000);
  prova2_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
