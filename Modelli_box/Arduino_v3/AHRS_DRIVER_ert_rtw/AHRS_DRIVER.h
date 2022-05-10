/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AHRS_DRIVER.h
 *
 * Code generated for Simulink model 'AHRS_DRIVER'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 08:57:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AHRS_DRIVER_h_
#define RTW_HEADER_AHRS_DRIVER_h_
#include <stddef.h>
#ifndef AHRS_DRIVER_COMMON_INCLUDES_
#define AHRS_DRIVER_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* AHRS_DRIVER_COMMON_INCLUDES_ */

#include "AHRS_DRIVER_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T SFunctionBuilder[41];        /* '<Root>/S-Function Builder' */
} B_AHRS_DRIVER_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
} DW_AHRS_DRIVER_T;

/* Real-time Model Data Structure */
struct tag_RTM_AHRS_DRIVER_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_AHRS_DRIVER_T AHRS_DRIVER_B;

/* Block states (default storage) */
extern DW_AHRS_DRIVER_T AHRS_DRIVER_DW;

/* External function called from main */
extern void AHRS_DRIVER_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void AHRS_DRIVER_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void AHRS_DRIVER_initialize(void);
extern void AHRS_DRIVER_step0(void);
extern void AHRS_DRIVER_step1(void);
extern void AHRS_DRIVER_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AHRS_DRIVER_T *const AHRS_DRIVER_M;
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
 * '<Root>' : 'AHRS_DRIVER'
 */
#endif                                 /* RTW_HEADER_AHRS_DRIVER_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
