/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prva_09_30.h
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

#ifndef RTW_HEADER_prva_09_30_h_
#define RTW_HEADER_prva_09_30_h_
#include <math.h>
#include <stddef.h>
#ifndef prva_09_30_COMMON_INCLUDES_
#define prva_09_30_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* prva_09_30_COMMON_INCLUDES_ */

#include "prva_09_30_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Transmit' */
} DW_prva_09_30_T;

/* Parameters (default storage) */
struct P_prva_09_30_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T Constant_Value;               /* Expression: 234
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_prva_09_30_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_prva_09_30_T prva_09_30_P;

/* Block states (default storage) */
extern DW_prva_09_30_T prva_09_30_DW;

/* Model entry point functions */
extern void prva_09_30_initialize(void);
extern void prva_09_30_step(void);
extern void prva_09_30_terminate(void);

/* Real-time Model object */
extern RT_MODEL_prva_09_30_T *const prva_09_30_M;
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
 * '<Root>' : 'prva_09_30'
 */
#endif                                 /* RTW_HEADER_prva_09_30_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
