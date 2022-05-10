/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 10:59:05 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
void untitled_step(void)
{
  uint8_T dataIn;
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (untitled_DW.obj_p.Protocol != untitled_P.SerialReceive_Protocol) {
    untitled_DW.obj_p.Protocol = untitled_P.SerialReceive_Protocol;
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  MW_Serial_read(1, untitled_DW.obj_p.DataSizeInBytes, &dataIn, &status);
  if (untitled_DW.obj.Protocol != untitled_P.SerialTransmit_Protocol) {
    untitled_DW.obj.Protocol = untitled_P.SerialTransmit_Protocol;
  }

  MW_Serial_write(untitled_DW.obj.port, &dataIn, 1.0,
                  untitled_DW.obj.dataSizeInBytes, untitled_DW.obj.sendModeEnum,
                  untitled_DW.obj.dataType, untitled_DW.obj.sendFormatEnum, 2.0,
                  '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */
}

/* Model initialize function */
void untitled_initialize(void)
{
  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    untitled_DW.obj_p.matlabCodegenIsDeleted = false;
    untitled_DW.obj_p.Protocol = untitled_P.SerialReceive_Protocol;
    untitled_DW.obj_p.isInitialized = 1;
    untitled_DW.obj_p.DataTypeWidth = 1U;
    untitled_DW.obj_p.DataSizeInBytes = untitled_DW.obj_p.DataTypeWidth;
    MW_SCI_Open(1);
    untitled_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.Protocol = untitled_P.SerialTransmit_Protocol;
    untitled_DW.obj.isInitialized = 1;
    untitled_DW.obj.port = 0.0;
    untitled_DW.obj.dataSizeInBytes = 1.0;
    untitled_DW.obj.dataType = 0.0;
    untitled_DW.obj.sendModeEnum = 2.0;
    untitled_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(untitled_DW.obj.port);
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
    untitled_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!untitled_DW.obj_p.matlabCodegenIsDeleted) {
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
