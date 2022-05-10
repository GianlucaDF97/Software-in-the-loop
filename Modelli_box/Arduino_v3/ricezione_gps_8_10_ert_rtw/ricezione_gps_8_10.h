/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ricezione_gps_8_10.h
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

#ifndef RTW_HEADER_ricezione_gps_8_10_h_
#define RTW_HEADER_ricezione_gps_8_10_h_
#include <math.h>
#include <stddef.h>
#ifndef ricezione_gps_8_10_COMMON_INCLUDES_
#define ricezione_gps_8_10_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* ricezione_gps_8_10_COMMON_INCLUDES_ */

#include "ricezione_gps_8_10_types.h"
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
  codertarget_arduinobase_int_k_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Serial Receive' */
} DW_ricezione_gps_8_10_T;

/* Parameters (default storage) */
struct P_ricezione_gps_8_10_T_ {
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ricezione_gps_8_10_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_ricezione_gps_8_10_T ricezione_gps_8_10_P;

/* Block states (default storage) */
extern DW_ricezione_gps_8_10_T ricezione_gps_8_10_DW;

/* Model entry point functions */
extern void ricezione_gps_8_10_initialize(void);
extern void ricezione_gps_8_10_step(void);
extern void ricezione_gps_8_10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ricezione_gps_8_10_T *const ricezione_gps_8_10_M;
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
 * '<Root>' : 'ricezione_gps_8_10'
 */
#endif                                 /* RTW_HEADER_ricezione_gps_8_10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
