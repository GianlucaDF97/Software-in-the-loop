/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_seriale.h
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

#ifndef RTW_HEADER_test_seriale_h_
#define RTW_HEADER_test_seriale_h_
#include <math.h>
#include <stddef.h>
#ifndef test_seriale_COMMON_INCLUDES_
#define test_seriale_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* test_seriale_COMMON_INCLUDES_ */

#include "test_seriale_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_n_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Serial Receive' */
} DW_test_seriale_T;

/* Parameters (default storage) */
struct P_test_seriale_T_ {
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_seriale_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_test_seriale_T test_seriale_P;

/* Block states (default storage) */
extern DW_test_seriale_T test_seriale_DW;

/* Model entry point functions */
extern void test_seriale_initialize(void);
extern void test_seriale_step(void);
extern void test_seriale_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_seriale_T *const test_seriale_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'test_seriale'
 */
#endif                                 /* RTW_HEADER_test_seriale_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
