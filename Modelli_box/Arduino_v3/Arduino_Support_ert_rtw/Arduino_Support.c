/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Arduino_Support.c
 *
 * Code generated for Simulink model 'Arduino_Support'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  1 09:35:50 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Arduino_Support.h"
#include "Arduino_Support_private.h"

/* Block states (default storage) */
DW_Arduino_Support_T Arduino_Support_DW;

/* Real-time model */
static RT_MODEL_Arduino_Support_T Arduino_Support_M_;
RT_MODEL_Arduino_Support_T *const Arduino_Support_M = &Arduino_Support_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Arduino_Support_step(void)
{
  uint8_T dataIn;

  /* MATLABSystem: '<Root>/Serial Transmit1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Arduino_Support_DW.obj.Protocol !=
      Arduino_Support_P.SerialTransmit1_Protocol) {
    Arduino_Support_DW.obj.Protocol = Arduino_Support_P.SerialTransmit1_Protocol;
  }

  dataIn = Arduino_Support_P.Constant_Value;
  MW_Serial_write(Arduino_Support_DW.obj.port, &dataIn, 1.0,
                  Arduino_Support_DW.obj.dataSizeInBytes,
                  Arduino_Support_DW.obj.sendModeEnum,
                  Arduino_Support_DW.obj.dataType,
                  Arduino_Support_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit1' */
}

/* Model initialize function */
void Arduino_Support_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Arduino_Support_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Arduino_Support_DW, 0,
                sizeof(DW_Arduino_Support_T));

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Transmit1' */
    Arduino_Support_DW.obj.matlabCodegenIsDeleted = false;
    Arduino_Support_DW.obj.Protocol = Arduino_Support_P.SerialTransmit1_Protocol;
    Arduino_Support_DW.obj.isInitialized = 1;
    Arduino_Support_DW.obj.port = 1.0;
    Arduino_Support_DW.obj.dataSizeInBytes = 1.0;
    Arduino_Support_DW.obj.dataType = 0.0;
    Arduino_Support_DW.obj.sendModeEnum = 0.0;
    Arduino_Support_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(Arduino_Support_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    Arduino_Support_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit1' */
  }
}

/* Model terminate function */
void Arduino_Support_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Transmit1' */
  if (!Arduino_Support_DW.obj.matlabCodegenIsDeleted) {
    Arduino_Support_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
