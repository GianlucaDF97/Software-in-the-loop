/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UART_read_private.h
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

#ifndef RTW_HEADER_UART_read_private_h_
#define RTW_HEADER_UART_read_private_h_
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void SerialRead_Start_wrapper(real_T *xD);
  extern void SerialRead_Outputs_wrapper(uint8_T *RX,
    const real_T *xD);
  extern void SerialRead_Update_wrapper(uint8_T *RX,
    real_T *xD);
  extern void SerialRead_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_UART_read_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
