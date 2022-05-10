/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_gps_26_10.h
 *
 * Code generated for Simulink model 'prova_gps_26_10'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 26 17:30:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prova_gps_26_10_h_
#define RTW_HEADER_prova_gps_26_10_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef prova_gps_26_10_COMMON_INCLUDES_
#define prova_gps_26_10_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* prova_gps_26_10_COMMON_INCLUDES_ */

#include "prova_gps_26_10_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

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
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S3>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S5>/Complex to Real-Imag' */
  uint8_T b_dataOut[32];
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  real_T Switch;                       /* '<S2>/Switch' */
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
} B_prova_gps_26_10_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_a_T obj; /* '<Root>/Serial Transmit2' */
  codertarget_arduinobase_inter_T obj_c;/* '<S1>/Serial Receive1' */
  uint8_T message[80];                 /* '<S3>/Create_message' */
  uint8_T counter;                     /* '<S3>/Create_message' */
  boolean_T start_found;               /* '<S3>/Create_message' */
  boolean_T end_found;                 /* '<S3>/Create_message' */
} DW_prova_gps_26_10_T;

/* Parameters (default storage) */
struct P_prova_gps_26_10_T_ {
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S1>/Serial Receive1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S2>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S5>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S5>/Memory'
                                        */
  real_T SerialTransmit2_Protocol;     /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit2'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S5>/mario'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_prova_gps_26_10_T {
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

/* Block parameters (default storage) */
extern P_prova_gps_26_10_T prova_gps_26_10_P;

/* Block signals (default storage) */
extern B_prova_gps_26_10_T prova_gps_26_10_B;

/* Block states (default storage) */
extern DW_prova_gps_26_10_T prova_gps_26_10_DW;

/* External function called from main */
extern void prova_gps_26_10_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void prova_gps_26_10_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void prova_gps_26_10_initialize(void);
extern void prova_gps_26_10_step0(void);
extern void prova_gps_26_10_step1(void);
extern void prova_gps_26_10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_prova_gps_26_10_T *const prova_gps_26_10_M;
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
 * '<Root>' : 'prova_gps_26_10'
 * '<S1>'   : 'prova_gps_26_10/GPS_Venus'
 * '<S2>'   : 'prova_gps_26_10/GPS_Venus/Subsystem1'
 * '<S3>'   : 'prova_gps_26_10/GPS_Venus/Subsystem2'
 * '<S4>'   : 'prova_gps_26_10/GPS_Venus/Subsystem2/Create_message'
 * '<S5>'   : 'prova_gps_26_10/GPS_Venus/Subsystem2/Subsystem'
 * '<S6>'   : 'prova_gps_26_10/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_prova_gps_26_10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
