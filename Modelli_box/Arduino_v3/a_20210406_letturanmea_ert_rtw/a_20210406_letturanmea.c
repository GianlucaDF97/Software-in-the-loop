/*
 * a_20210406_letturanmea.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210406_letturanmea".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Apr  6 16:49:31 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a_20210406_letturanmea.h"
#include "a_20210406_letturanmea_private.h"

/* Block signals (default storage) */
B_a_20210406_letturanmea_T a_20210406_letturanmea_B;

/* Block states (default storage) */
DW_a_20210406_letturanmea_T a_20210406_letturanmea_DW;

/* Real-time model */
static RT_MODEL_a_20210406_letturanm_T a_20210406_letturanmea_M_;
RT_MODEL_a_20210406_letturanm_T *const a_20210406_letturanmea_M =
  &a_20210406_letturanmea_M_;

/* Model step function */
void a_20210406_letturanmea_step(void)
{
  int32_T b_i;
  int32_T i;
  int32_T loop_ub;
  uint8_T b_dataOut[32];
  uint8_T status;
  boolean_T exitg1;

  /* MATLABSystem: '<Root>/Serial Receive1' */
  if (a_20210406_letturanmea_DW.obj.Protocol !=
      a_20210406_letturanmea_P.SerialReceive1_Protocol) {
    a_20210406_letturanmea_DW.obj.Protocol =
      a_20210406_letturanmea_P.SerialReceive1_Protocol;
  }

  MW_Serial_read(1, a_20210406_letturanmea_DW.obj.DataSizeInBytes, &b_dataOut[0],
                 &status);

  /* MATLAB Function: '<Root>/Create_message' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive1'
   */
  a_20210406_letturanmea_B.status = false;
  memset(&a_20210406_letturanmea_B.messaggio[0], 0, 80U * sizeof(uint8_T));
  status = 0U;
  if (!a_20210406_letturanmea_DW.start_found) {
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i - 1 < 32)) {
      if (b_dataOut[(uint8_T)i - 1] == 36) {
        loop_ub = 32 - (uint8_T)i;
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          a_20210406_letturanmea_DW.message[b_i] = b_dataOut[((uint8_T)i + b_i)
            - 1];
        }

        a_20210406_letturanmea_DW.counter = (uint8_T)(33 - (uint8_T)i);
        a_20210406_letturanmea_DW.start_found = true;
        exitg1 = true;
      } else {
        i++;
      }
    }
  } else {
    b_i = 1;
    exitg1 = false;
    while ((!exitg1) && (b_i - 1 < 32)) {
      if (b_dataOut[(uint8_T)b_i - 1] == 13) {
        a_20210406_letturanmea_DW.end_found = true;
        status = (uint8_T)b_i;
        exitg1 = true;
      } else {
        b_i++;
      }
    }

    if (a_20210406_letturanmea_DW.end_found) {
      if (1 > status) {
        loop_ub = -1;
      } else {
        loop_ub = status - 1;
      }

      for (b_i = 0; b_i <= loop_ub; b_i++) {
        i = (int32_T)(((uint32_T)b_i + a_20210406_letturanmea_DW.counter) + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        a_20210406_letturanmea_DW.message[i - 1] = b_dataOut[b_i];
      }

      a_20210406_letturanmea_B.status = true;
      memcpy(&a_20210406_letturanmea_B.messaggio[0],
             &a_20210406_letturanmea_DW.message[0], 80U * sizeof(uint8_T));
      a_20210406_letturanmea_DW.end_found = false;
      a_20210406_letturanmea_DW.counter = (uint8_T)(32 - status);
      if (status == 32) {
        a_20210406_letturanmea_DW.start_found = false;
        memset(&a_20210406_letturanmea_DW.message[0], 0, 80U * sizeof(uint8_T));
      } else {
        a_20210406_letturanmea_DW.start_found = true;
        loop_ub = -status;
        for (b_i = 0; b_i <= loop_ub + 31; b_i++) {
          a_20210406_letturanmea_DW.message[b_i] = b_dataOut[status + b_i];
        }

        if (0 <= (status + 48) - 1) {
          memset(&a_20210406_letturanmea_DW.message[-status + 32], 0, (((status
                    + 48) - status) + status) * sizeof(uint8_T));
        }
      }
    } else {
      for (i = 0; i < 32; i++) {
        b_i = (int32_T)(((uint32_T)a_20210406_letturanmea_DW.counter + i) + 1U);
        if ((uint32_T)b_i > 255U) {
          b_i = 255;
        }

        a_20210406_letturanmea_DW.message[b_i - 1] = b_dataOut[i];
      }

      b_i = (int32_T)(a_20210406_letturanmea_DW.counter + 32U);
      if (a_20210406_letturanmea_DW.counter + 32U > 255U) {
        b_i = 255;
      }

      a_20210406_letturanmea_DW.counter = (uint8_T)b_i;
    }
  }

  /* End of MATLAB Function: '<Root>/Create_message' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, (real_T)a_20210406_letturanmea_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(a_20210406_letturanmea_M)!=-1) &&
        !((rtmGetTFinal(a_20210406_letturanmea_M)-
           a_20210406_letturanmea_M->Timing.taskTime0) >
          a_20210406_letturanmea_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(a_20210406_letturanmea_M, "Simulation finished");
    }

    if (rtmGetStopRequested(a_20210406_letturanmea_M)) {
      rtmSetErrorStatus(a_20210406_letturanmea_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++a_20210406_letturanmea_M->Timing.clockTick0)) {
    ++a_20210406_letturanmea_M->Timing.clockTickH0;
  }

  a_20210406_letturanmea_M->Timing.taskTime0 =
    a_20210406_letturanmea_M->Timing.clockTick0 *
    a_20210406_letturanmea_M->Timing.stepSize0 +
    a_20210406_letturanmea_M->Timing.clockTickH0 *
    a_20210406_letturanmea_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void a_20210406_letturanmea_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)a_20210406_letturanmea_M, 0,
                sizeof(RT_MODEL_a_20210406_letturanm_T));
  rtmSetTFinal(a_20210406_letturanmea_M, -1);
  a_20210406_letturanmea_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  a_20210406_letturanmea_M->Sizes.checksums[0] = (371197947U);
  a_20210406_letturanmea_M->Sizes.checksums[1] = (771029949U);
  a_20210406_letturanmea_M->Sizes.checksums[2] = (3585446457U);
  a_20210406_letturanmea_M->Sizes.checksums[3] = (1256524967U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    a_20210406_letturanmea_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(a_20210406_letturanmea_M->extModeInfo,
      &a_20210406_letturanmea_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(a_20210406_letturanmea_M->extModeInfo,
                        a_20210406_letturanmea_M->Sizes.checksums);
    rteiSetTPtr(a_20210406_letturanmea_M->extModeInfo, rtmGetTPtr
                (a_20210406_letturanmea_M));
  }

  /* block I/O */
  (void) memset(((void *) &a_20210406_letturanmea_B), 0,
                sizeof(B_a_20210406_letturanmea_T));

  /* states (dwork) */
  (void) memset((void *)&a_20210406_letturanmea_DW, 0,
                sizeof(DW_a_20210406_letturanmea_T));

  /* Start for MATLABSystem: '<Root>/Serial Receive1' */
  a_20210406_letturanmea_DW.obj.matlabCodegenIsDeleted = false;
  a_20210406_letturanmea_DW.objisempty = true;
  a_20210406_letturanmea_DW.obj.Protocol =
    a_20210406_letturanmea_P.SerialReceive1_Protocol;
  a_20210406_letturanmea_DW.obj.isInitialized = 1;
  a_20210406_letturanmea_DW.obj.DataTypeWidth = 1U;
  if (a_20210406_letturanmea_DW.obj.DataTypeWidth > 2047) {
    a_20210406_letturanmea_DW.obj.DataSizeInBytes = MAX_uint16_T;
  } else {
    a_20210406_letturanmea_DW.obj.DataSizeInBytes = (uint16_T)
      (a_20210406_letturanmea_DW.obj.DataTypeWidth << 5);
  }

  MW_SCI_Open(1);
  a_20210406_letturanmea_DW.obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<Root>/Serial Receive1' */

  /* SystemInitialize for MATLAB Function: '<Root>/Create_message' */
  a_20210406_letturanmea_DW.end_found = false;
  a_20210406_letturanmea_DW.start_found = false;
  a_20210406_letturanmea_DW.counter = 0U;
  memset(&a_20210406_letturanmea_DW.message[0], 0, 80U * sizeof(uint8_T));
}

/* Model terminate function */
void a_20210406_letturanmea_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive1' */
  if (!a_20210406_letturanmea_DW.obj.matlabCodegenIsDeleted) {
    a_20210406_letturanmea_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive1' */
}
