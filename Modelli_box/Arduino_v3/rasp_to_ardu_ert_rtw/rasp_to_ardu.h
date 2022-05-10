/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rasp_to_ardu.h
 *
 * Code generated for Simulink model 'rasp_to_ardu'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  1 08:57:16 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rasp_to_ardu_h_
#define RTW_HEADER_rasp_to_ardu_h_
#include <stddef.h>
#ifndef rasp_to_ardu_COMMON_INCLUDES_
#define rasp_to_ardu_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* rasp_to_ardu_COMMON_INCLUDES_ */

#include "rasp_to_ardu_types.h"
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
} DW_rasp_to_ardu_T;

/* Real-time Model Data Structure */
struct tag_RTM_rasp_to_ardu_T {
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

/* Block states (default storage) */
extern DW_rasp_to_ardu_T rasp_to_ardu_DW;

/* External function called from main */
extern void rasp_to_ardu_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void rasp_to_ardu_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void rasp_to_ardu_initialize(void);
extern void rasp_to_ardu_step0(void);
extern void rasp_to_ardu_step1(void);
extern void rasp_to_ardu_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rasp_to_ardu_T *const rasp_to_ardu_M;
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
 * '<Root>' : 'rasp_to_ardu'
 */
#endif                                 /* RTW_HEADER_rasp_to_ardu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
