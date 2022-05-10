/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prva_09_30.c
 *
 * Code generated for Simulink model 'prva_09_30'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 30 17:41:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prva_09_30.h"
#include "prva_09_30_private.h"

/* Block states (default storage) */
DW_prva_09_30_T prva_09_30_DW;

/* Real-time model */
static RT_MODEL_prva_09_30_T prva_09_30_M_;
RT_MODEL_prva_09_30_T *const prva_09_30_M = &prva_09_30_M_;
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
void prva_09_30_step(void)
{
  real_T tmp;
  uint8_T dataIn;

  /* MATLABSystem: '<Root>/Serial Transmit' */
  if (prva_09_30_DW.obj.Protocol != prva_09_30_P.SerialTransmit_Protocol) {
    prva_09_30_DW.obj.Protocol = prva_09_30_P.SerialTransmit_Protocol;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(prva_09_30_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  dataIn = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp :
                     (int32_T)(uint8_T)tmp);
  MW_Serial_write(prva_09_30_DW.obj.port, &dataIn, 1.0,
                  prva_09_30_DW.obj.dataSizeInBytes,
                  prva_09_30_DW.obj.sendModeEnum, prva_09_30_DW.obj.dataType,
                  prva_09_30_DW.obj.sendFormatEnum, 1.0, '\x00');
}

/* Model initialize function */
void prva_09_30_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    prva_09_30_DW.obj.matlabCodegenIsDeleted = false;
    prva_09_30_DW.obj.Protocol = prva_09_30_P.SerialTransmit_Protocol;
    prva_09_30_DW.obj.isInitialized = 1;
    prva_09_30_DW.obj.port = 1.0;
    prva_09_30_DW.obj.dataSizeInBytes = 1.0;
    prva_09_30_DW.obj.dataType = 0.0;
    prva_09_30_DW.obj.sendModeEnum = 2.0;
    prva_09_30_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(prva_09_30_DW.obj.port);
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
    prva_09_30_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void prva_09_30_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!prva_09_30_DW.obj.matlabCodegenIsDeleted) {
    prva_09_30_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
