/*
 * a_20210406_letturanmea.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210406_letturanmea".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Apr  6 16:49:31 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210406_letturanmea_h_
#define RTW_HEADER_a_20210406_letturanmea_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef a_20210406_letturanmea_COMMON_INCLUDES_
#define a_20210406_letturanmea_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                             /* a_20210406_letturanmea_COMMON_INCLUDES_ */

#include "a_20210406_letturanmea_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
  uint8_T messaggio[80];               /* '<Root>/Create_message' */
  boolean_T status;                    /* '<Root>/Create_message' */
} B_a_20210406_letturanmea_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Receive1' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Creat;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Cre_i;   /* synthesized block */

  uint8_T message[80];                 /* '<Root>/Create_message' */
  uint8_T counter;                     /* '<Root>/Create_message' */
  boolean_T objisempty;                /* '<Root>/Serial Receive1' */
  boolean_T start_found;               /* '<Root>/Create_message' */
  boolean_T end_found;                 /* '<Root>/Create_message' */
} DW_a_20210406_letturanmea_T;

/* Parameters (default storage) */
struct P_a_20210406_letturanmea_T_ {
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210406_letturanme_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_a_20210406_letturanmea_T a_20210406_letturanmea_P;

/* Block signals (default storage) */
extern B_a_20210406_letturanmea_T a_20210406_letturanmea_B;

/* Block states (default storage) */
extern DW_a_20210406_letturanmea_T a_20210406_letturanmea_DW;

/* Model entry point functions */
extern void a_20210406_letturanmea_initialize(void);
extern void a_20210406_letturanmea_step(void);
extern void a_20210406_letturanmea_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210406_letturanm_T *const a_20210406_letturanmea_M;
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
 * '<Root>' : 'a_20210406_letturanmea'
 * '<S1>'   : 'a_20210406_letturanmea/Create_message'
 */
#endif                                /* RTW_HEADER_a_20210406_letturanmea_h_ */
