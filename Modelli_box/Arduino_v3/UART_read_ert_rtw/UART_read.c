/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UART_read.c
 *
 * Code generated for Simulink model 'UART_read'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  1 10:05:54 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UART_read.h"
#include "UART_read_private.h"

/* Block signals (default storage) */
B_UART_read_T UART_read_B;

/* Block states (default storage) */
DW_UART_read_T UART_read_DW;

/* Real-time model */
static RT_MODEL_UART_read_T UART_read_M_;
RT_MODEL_UART_read_T *const UART_read_M = &UART_read_M_;

/* Model step function */
void UART_read_step(void)
{
  /* S-Function (SerialRead): '<Root>/RX Pin Read' */
  SerialRead_Outputs_wrapper(&UART_read_B.RXPinRead,
    &UART_read_DW.RXPinRead_DSTATE);

  /* Update for S-Function (SerialRead): '<Root>/RX Pin Read' */

  /* S-Function "SerialRead_wrapper" Block: <Root>/RX Pin Read */
  SerialRead_Update_wrapper(&UART_read_B.RXPinRead,
    &UART_read_DW.RXPinRead_DSTATE);
}

/* Model initialize function */
void UART_read_initialize(void)
{
  /* InitializeConditions for S-Function (SerialRead): '<Root>/RX Pin Read' */

  /* S-Function Block: <Root>/RX Pin Read */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        UART_read_DW.RXPinRead_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void UART_read_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
