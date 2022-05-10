/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ricezione_gps_8_10.c
 *
 * Code generated for Simulink model 'ricezione_gps_8_10'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Oct 11 11:54:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ricezione_gps_8_10.h"
#include "ricezione_gps_8_10_private.h"

/* Block states (default storage) */
DW_ricezione_gps_8_10_T ricezione_gps_8_10_DW;

/* Real-time model */
static RT_MODEL_ricezione_gps_8_10_T ricezione_gps_8_10_M_;
RT_MODEL_ricezione_gps_8_10_T *const ricezione_gps_8_10_M =
  &ricezione_gps_8_10_M_;
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
void ricezione_gps_8_10_step(void)
{
  uint8_T dataIn[32];
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' incorporates:
   *  MATLABSystem: '<Root>/Serial Transmit'
   */
  if (ricezione_gps_8_10_DW.obj_p.Protocol !=
      ricezione_gps_8_10_P.SerialReceive_Protocol) {
    ricezione_gps_8_10_DW.obj_p.Protocol =
      ricezione_gps_8_10_P.SerialReceive_Protocol;
  }

  MW_Serial_read(3, ricezione_gps_8_10_DW.obj_p.DataSizeInBytes, &dataIn[0],
                 &status);

  /* End of MATLABSystem: '<Root>/Serial Receive' */

  /* MATLABSystem: '<Root>/Serial Transmit' */
  if (ricezione_gps_8_10_DW.obj.Protocol !=
      ricezione_gps_8_10_P.SerialTransmit_Protocol) {
    ricezione_gps_8_10_DW.obj.Protocol =
      ricezione_gps_8_10_P.SerialTransmit_Protocol;
  }

  MW_Serial_write(ricezione_gps_8_10_DW.obj.port, &dataIn[0], 32.0,
                  ricezione_gps_8_10_DW.obj.dataSizeInBytes,
                  ricezione_gps_8_10_DW.obj.sendModeEnum,
                  ricezione_gps_8_10_DW.obj.dataType,
                  ricezione_gps_8_10_DW.obj.sendFormatEnum, 2.0, '\x00');
}

/* Model initialize function */
void ricezione_gps_8_10_initialize(void)
{
  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    ricezione_gps_8_10_DW.obj_p.matlabCodegenIsDeleted = false;
    ricezione_gps_8_10_DW.obj_p.Protocol =
      ricezione_gps_8_10_P.SerialReceive_Protocol;
    ricezione_gps_8_10_DW.obj_p.isInitialized = 1;
    ricezione_gps_8_10_DW.obj_p.DataTypeWidth = 1U;
    if (ricezione_gps_8_10_DW.obj_p.DataTypeWidth > 2047) {
      ricezione_gps_8_10_DW.obj_p.DataSizeInBytes = MAX_uint16_T;
    } else {
      ricezione_gps_8_10_DW.obj_p.DataSizeInBytes = (uint16_T)
        (ricezione_gps_8_10_DW.obj_p.DataTypeWidth << 5);
    }

    MW_SCI_Open(3);
    ricezione_gps_8_10_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Receive' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    ricezione_gps_8_10_DW.obj.matlabCodegenIsDeleted = false;
    ricezione_gps_8_10_DW.obj.Protocol =
      ricezione_gps_8_10_P.SerialTransmit_Protocol;
    ricezione_gps_8_10_DW.obj.isInitialized = 1;
    ricezione_gps_8_10_DW.obj.port = 0.0;
    ricezione_gps_8_10_DW.obj.dataSizeInBytes = 1.0;
    ricezione_gps_8_10_DW.obj.dataType = 0.0;
    ricezione_gps_8_10_DW.obj.sendModeEnum = 0.0;
    ricezione_gps_8_10_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(ricezione_gps_8_10_DW.obj.port);
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
    ricezione_gps_8_10_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void ricezione_gps_8_10_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!ricezione_gps_8_10_DW.obj_p.matlabCodegenIsDeleted) {
    ricezione_gps_8_10_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!ricezione_gps_8_10_DW.obj.matlabCodegenIsDeleted) {
    ricezione_gps_8_10_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
