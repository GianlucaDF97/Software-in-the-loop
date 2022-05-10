/*
 * a_20210329_gps.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210329_gps".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Mar 29 18:45:08 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210329_gps_h_
#define RTW_HEADER_a_20210329_gps_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef a_20210329_gps_COMMON_INCLUDES_
#define a_20210329_gps_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* a_20210329_gps_COMMON_INCLUDES_ */

#include "a_20210329_gps_types.h"

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
  uint8_T b_dataOut[32];
  uint128m_T r;
  real_T TmpSignalConversionAtsfunxyInpo[2];
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  real_T rtb_Lat_re;
  real_T rtb_Long_re;
  real_T rtb_V_re;
  real_T rtb_heading_re;
  real_T rtb_Magnetic_declination_re;
  real_T rtb_fix_mode_re;
  real_T rtb_n_sat_re;
  real_T rtb_h_mean_sea_re;
  real_T rtb_h_WGS84_re;
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
} B_a_20210329_gps_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Receive2' */
  real_T Memory1_PreviousInput;        /* '<S3>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S3>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S3>/Memory3' */
  real_T Memory4_PreviousInput;        /* '<S3>/Memory4' */
  real_T Memory11_PreviousInput;       /* '<S3>/Memory11' */
  real_T Memory6_PreviousInput;        /* '<S3>/Memory6' */
  real_T Memory8_PreviousInput;        /* '<S3>/Memory8' */
  real_T Memory9_PreviousInput;        /* '<S3>/Memory9' */
  real_T Memory7_PreviousInput;        /* '<S3>/Memory7' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Subsy;   /* synthesized block */

  int8_T Subsystem1_SubsysRanBC;       /* '<Root>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC;        /* '<S1>/Subsystem' */
  uint8_T message[80];                 /* '<S1>/Create_message' */
  uint8_T counter;                     /* '<S1>/Create_message' */
  boolean_T start_found;               /* '<S1>/Create_message' */
  boolean_T end_found;                 /* '<S1>/Create_message' */
  boolean_T objisempty;                /* '<Root>/Serial Receive2' */
} DW_a_20210329_gps_T;

/* Parameters (default storage) */
struct P_a_20210329_gps_T_ {
  real_T SerialReceive2_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive2'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S3>/Outport'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory2'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory3'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory4'
                                        */
  real_T Memory11_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S3>/Memory11'
                                        */
  real_T Memory6_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory6'
                                        */
  real_T Memory8_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory8'
                                        */
  real_T Memory9_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory9'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory7'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S3>/mario'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210329_gps_T {
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
extern P_a_20210329_gps_T a_20210329_gps_P;

/* Block signals (default storage) */
extern B_a_20210329_gps_T a_20210329_gps_B;

/* Block states (default storage) */
extern DW_a_20210329_gps_T a_20210329_gps_DW;

/* Model entry point functions */
extern void a_20210329_gps_initialize(void);
extern void a_20210329_gps_step(void);
extern void a_20210329_gps_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210329_gps_T *const a_20210329_gps_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Memory5' : Unused code path elimination
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
 * '<Root>' : 'a_20210329_gps'
 * '<S1>'   : 'a_20210329_gps/Subsystem1'
 * '<S2>'   : 'a_20210329_gps/Subsystem1/Create_message'
 * '<S3>'   : 'a_20210329_gps/Subsystem1/Subsystem'
 * '<S4>'   : 'a_20210329_gps/Subsystem1/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_a_20210329_gps_h_ */
