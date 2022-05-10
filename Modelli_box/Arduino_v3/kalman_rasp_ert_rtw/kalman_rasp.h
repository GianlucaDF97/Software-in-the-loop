/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: kalman_rasp.h
 *
 * Code generated for Simulink model 'kalman_rasp'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 30 15:49:59 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_kalman_rasp_h_
#define RTW_HEADER_kalman_rasp_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#ifndef kalman_rasp_COMMON_INCLUDES_
#define kalman_rasp_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_logging.h"
#include "MW_SCI.h"
#endif                                 /* kalman_rasp_COMMON_INCLUDES_ */

#include "kalman_rasp_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion[10];       /* '<Root>/Data Type Conversion' */
} B_kalman_rasp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_SC_T obj; /* '<Root>/Serial Read' */
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<Root>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<Root>/To File' */
} DW_kalman_rasp_T;

/* Parameters (default storage) */
struct P_kalman_rasp_T_ {
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<Root>/Serial Read'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_kalman_rasp_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_kalman_rasp_T kalman_rasp_P;

/* Block signals (default storage) */
extern B_kalman_rasp_T kalman_rasp_B;

/* Block states (default storage) */
extern DW_kalman_rasp_T kalman_rasp_DW;

/* Model entry point functions */
extern void kalman_rasp_initialize(void);
extern void kalman_rasp_step(void);
extern void kalman_rasp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_kalman_rasp_T *const kalman_rasp_M;

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
 * '<Root>' : 'kalman_rasp'
 */
#endif                                 /* RTW_HEADER_kalman_rasp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
