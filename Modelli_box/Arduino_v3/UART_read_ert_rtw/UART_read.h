/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UART_read.h
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

#ifndef RTW_HEADER_UART_read_h_
#define RTW_HEADER_UART_read_h_
#include <stddef.h>
#ifndef UART_read_COMMON_INCLUDES_
#define UART_read_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* UART_read_COMMON_INCLUDES_ */

#include "UART_read_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RXPinRead;                   /* '<Root>/RX Pin Read' */
} B_UART_read_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T RXPinRead_DSTATE;             /* '<Root>/RX Pin Read' */
} DW_UART_read_T;

/* Real-time Model Data Structure */
struct tag_RTM_UART_read_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_UART_read_T UART_read_B;

/* Block states (default storage) */
extern DW_UART_read_T UART_read_DW;

/* Model entry point functions */
extern void UART_read_initialize(void);
extern void UART_read_step(void);
extern void UART_read_terminate(void);

/* Real-time Model object */
extern RT_MODEL_UART_read_T *const UART_read_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/To Workspace' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'UART_read'
 */
#endif                                 /* RTW_HEADER_UART_read_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
