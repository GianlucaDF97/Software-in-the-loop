/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: kalman_prova.c
 *
 * Code generated for Simulink model 'kalman_prova'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 30 17:38:29 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "kalman_prova.h"
#include "kalman_prova_private.h"

/* Block states (default storage) */
DW_kalman_prova_T kalman_prova_DW;

/* Real-time model */
static RT_MODEL_kalman_prova_T kalman_prova_M_;
RT_MODEL_kalman_prova_T *const kalman_prova_M = &kalman_prova_M_;
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
void kalman_prova_step(void)
{
  real_T dataIn;

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (kalman_prova_DW.obj.Protocol != kalman_prova_P.SerialTransmit_Protocol) {
    kalman_prova_DW.obj.Protocol = kalman_prova_P.SerialTransmit_Protocol;
  }

  dataIn = kalman_prova_P.Constant_Value;
  MW_Serial_write(kalman_prova_DW.obj.port, &dataIn, 1.0,
                  kalman_prova_DW.obj.dataSizeInBytes,
                  kalman_prova_DW.obj.sendModeEnum, kalman_prova_DW.obj.dataType,
                  kalman_prova_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */
}

/* Model initialize function */
void kalman_prova_initialize(void)
{
  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    kalman_prova_DW.obj.matlabCodegenIsDeleted = false;
    kalman_prova_DW.obj.Protocol = kalman_prova_P.SerialTransmit_Protocol;
    kalman_prova_DW.obj.isInitialized = 1;
    kalman_prova_DW.obj.port = 1.0;
    kalman_prova_DW.obj.dataSizeInBytes = 8.0;
    kalman_prova_DW.obj.dataType = 6.0;
    kalman_prova_DW.obj.sendModeEnum = 0.0;
    kalman_prova_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(kalman_prova_DW.obj.port);
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
    kalman_prova_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void kalman_prova_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!kalman_prova_DW.obj.matlabCodegenIsDeleted) {
    kalman_prova_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
