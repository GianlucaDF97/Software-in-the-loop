/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaseriale.c
 *
 * Code generated for Simulink model 'provaseriale'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 11:25:24 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "provaseriale.h"
#include "provaseriale_private.h"

/* Block states (default storage) */
DW_provaseriale_T provaseriale_DW;

/* Real-time model */
static RT_MODEL_provaseriale_T provaseriale_M_;
RT_MODEL_provaseriale_T *const provaseriale_M = &provaseriale_M_;
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
void provaseriale_step(void)
{
  real_T dataIn;

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (provaseriale_DW.obj.Protocol != provaseriale_P.SerialTransmit_Protocol) {
    provaseriale_DW.obj.Protocol = provaseriale_P.SerialTransmit_Protocol;
  }

  dataIn = provaseriale_P.Constant_Value;
  MW_Serial_write(provaseriale_DW.obj.port, &dataIn, 1.0,
                  provaseriale_DW.obj.dataSizeInBytes,
                  provaseriale_DW.obj.sendModeEnum, provaseriale_DW.obj.dataType,
                  provaseriale_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */
}

/* Model initialize function */
void provaseriale_initialize(void)
{
  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    provaseriale_DW.obj.matlabCodegenIsDeleted = false;
    provaseriale_DW.obj.Protocol = provaseriale_P.SerialTransmit_Protocol;
    provaseriale_DW.obj.isInitialized = 1;
    provaseriale_DW.obj.port = 2.0;
    provaseriale_DW.obj.dataSizeInBytes = 8.0;
    provaseriale_DW.obj.dataType = 6.0;
    provaseriale_DW.obj.sendModeEnum = 2.0;
    provaseriale_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(provaseriale_DW.obj.port);
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
    provaseriale_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void provaseriale_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!provaseriale_DW.obj.matlabCodegenIsDeleted) {
    provaseriale_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
