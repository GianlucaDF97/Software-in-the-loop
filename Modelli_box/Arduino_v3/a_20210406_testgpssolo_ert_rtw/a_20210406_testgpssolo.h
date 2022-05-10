/*
 * a_20210406_testgpssolo.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210406_testgpssolo".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Apr  6 17:29:38 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210406_testgpssolo_h_
#define RTW_HEADER_a_20210406_testgpssolo_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef a_20210406_testgpssolo_COMMON_INCLUDES_
#define a_20210406_testgpssolo_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                             /* a_20210406_testgpssolo_COMMON_INCLUDES_ */

#include "a_20210406_testgpssolo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

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
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S1>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S3>/Complex to Real-Imag' */
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  real_T rtb_Lat_re;
  real_T rtb_Long_re;
  real_T scanned1;
  real_T scanned2;
  real_T b_scanned1;
  real_T scanned1_c;
  real_T scanned2_f;
  real_T b_scanned1_g;
  real_T scanned1_g;
  real_T scanned2_m;
  real_T b_scanned1_n;
  real_T scanned1_p;
  real_T scanned2_l;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_k[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_b[2];
  int32_T messaggio_size_p[2];
  int32_T s1_size[2];
  boolean_T mess_type_j[5];
  char_T mess_type[5];
  char_T s1[5];
  int32_T b_i;
  int32_T eb_data;
  uint8_T indice_dimario;              /* '<S3>/MATLAB Function' */
  uint8_T SerialReceive1_o1[32];       /* '<Root>/Serial Receive1' */
} B_a_20210406_testgpssolo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Receive1' */
  real_T Memory_PreviousInput[9];      /* '<S3>/Memory' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Seria;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Subsy;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_S;   /* synthesized block */

  int8_T Subsystem2_SubsysRanBC;       /* '<Root>/Subsystem2' */
  int8_T Subsystem_SubsysRanBC;        /* '<S1>/Subsystem' */
  uint8_T message[80];                 /* '<S1>/Create_message' */
  uint8_T counter;                     /* '<S1>/Create_message' */
  boolean_T start_found;               /* '<S1>/Create_message' */
  boolean_T end_found;                 /* '<S1>/Create_message' */
  boolean_T objisempty;                /* '<Root>/Serial Receive1' */
} DW_a_20210406_testgpssolo_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T mario;                       /* '<Root>/mario' */
} ExtY_a_20210406_testgpssolo_T;

/* Parameters (default storage) */
struct P_a_20210406_testgpssolo_T_ {
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S3>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S3>/mario'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210406_testgpssol_T {
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
extern P_a_20210406_testgpssolo_T a_20210406_testgpssolo_P;

/* Block signals (default storage) */
extern B_a_20210406_testgpssolo_T a_20210406_testgpssolo_B;

/* Block states (default storage) */
extern DW_a_20210406_testgpssolo_T a_20210406_testgpssolo_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_a_20210406_testgpssolo_T a_20210406_testgpssolo_Y;

/* Model entry point functions */
extern void a_20210406_testgpssolo_initialize(void);
extern void a_20210406_testgpssolo_step(void);
extern void a_20210406_testgpssolo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210406_testgpsso_T *const a_20210406_testgpssolo_M;
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
 * '<Root>' : 'a_20210406_testgpssolo'
 * '<S1>'   : 'a_20210406_testgpssolo/Subsystem2'
 * '<S2>'   : 'a_20210406_testgpssolo/Subsystem2/Create_message'
 * '<S3>'   : 'a_20210406_testgpssolo/Subsystem2/Subsystem'
 * '<S4>'   : 'a_20210406_testgpssolo/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                /* RTW_HEADER_a_20210406_testgpssolo_h_ */
