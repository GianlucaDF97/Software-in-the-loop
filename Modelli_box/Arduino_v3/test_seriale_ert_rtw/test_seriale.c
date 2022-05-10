/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_seriale.c
 *
 * Code generated for Simulink model 'test_seriale'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Oct 25 17:13:34 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_seriale.h"
#include "test_seriale_private.h"

/* Block states (default storage) */
DW_test_seriale_T test_seriale_DW;

/* Real-time model */
static RT_MODEL_test_seriale_T test_seriale_M_;
RT_MODEL_test_seriale_T *const test_seriale_M = &test_seriale_M_;
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
void test_seriale_step(void)
{
  uint8_T dataIn;
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (test_seriale_DW.obj_p.Protocol != test_seriale_P.SerialReceive_Protocol) {
    test_seriale_DW.obj_p.Protocol = test_seriale_P.SerialReceive_Protocol;
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  MW_Serial_read(3, test_seriale_DW.obj_p.DataSizeInBytes, &dataIn, &status);
  if (test_seriale_DW.obj.Protocol != test_seriale_P.SerialTransmit_Protocol) {
    test_seriale_DW.obj.Protocol = test_seriale_P.SerialTransmit_Protocol;
  }

  MW_Serial_write(test_seriale_DW.obj.port, &dataIn, 1.0,
                  test_seriale_DW.obj.dataSizeInBytes,
                  test_seriale_DW.obj.sendModeEnum, test_seriale_DW.obj.dataType,
                  test_seriale_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */
}

/* Model initialize function */
void test_seriale_initialize(void)
{
  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    test_seriale_DW.obj_p.matlabCodegenIsDeleted = false;
    test_seriale_DW.obj_p.Protocol = test_seriale_P.SerialReceive_Protocol;
    test_seriale_DW.obj_p.isInitialized = 1;
    test_seriale_DW.obj_p.DataTypeWidth = 1U;
    test_seriale_DW.obj_p.DataSizeInBytes = test_seriale_DW.obj_p.DataTypeWidth;
    MW_SCI_Open(3);
    test_seriale_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    test_seriale_DW.obj.matlabCodegenIsDeleted = false;
    test_seriale_DW.obj.Protocol = test_seriale_P.SerialTransmit_Protocol;
    test_seriale_DW.obj.isInitialized = 1;
    test_seriale_DW.obj.port = 0.0;
    test_seriale_DW.obj.dataSizeInBytes = 1.0;
    test_seriale_DW.obj.dataType = 0.0;
    test_seriale_DW.obj.sendModeEnum = 2.0;
    test_seriale_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(test_seriale_DW.obj.port);
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
    test_seriale_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void test_seriale_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!test_seriale_DW.obj_p.matlabCodegenIsDeleted) {
    test_seriale_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!test_seriale_DW.obj.matlabCodegenIsDeleted) {
    test_seriale_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
