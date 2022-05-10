/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210531_test_GPS.h
 *
 * Code generated for Simulink model 'a_20210531_test_GPS'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jun  1 16:31:17 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210531_test_GPS_h_
#define RTW_HEADER_a_20210531_test_GPS_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef a_20210531_test_GPS_COMMON_INCLUDES_
#define a_20210531_test_GPS_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                /* a_20210531_test_GPS_COMMON_INCLUDES_ */

#include "a_20210531_test_GPS_types.h"

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

/* Block signals (default storage) */
typedef struct {
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S2>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  uint8_T b_dataOut[32];
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
} B_a_20210531_test_GPS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Receive1' */
  real_T Memory_PreviousInput[9];      /* '<S4>/Memory' */
  uint8_T message[80];                 /* '<S2>/Create_message' */
  uint8_T counter;                     /* '<S2>/Create_message' */
  boolean_T start_found;               /* '<S2>/Create_message' */
  boolean_T end_found;                 /* '<S2>/Create_message' */
} DW_a_20210531_test_GPS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Cal_alt;                      /* '<Root>/Cal_alt' */
} ExtU_a_20210531_test_GPS_T;

/* Parameters (default storage) */
struct P_a_20210531_test_GPS_T_ {
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S1>/h_to_subtract'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S4>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S4>/mario'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210531_test_GPS_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_a_20210531_test_GPS_T a_20210531_test_GPS_P;

/* Block signals (default storage) */
extern B_a_20210531_test_GPS_T a_20210531_test_GPS_B;

/* Block states (default storage) */
extern DW_a_20210531_test_GPS_T a_20210531_test_GPS_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_a_20210531_test_GPS_T a_20210531_test_GPS_U;

/* Model entry point functions */
extern void a_20210531_test_GPS_initialize(void);
extern void a_20210531_test_GPS_step(void);
extern void a_20210531_test_GPS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210531_test_GPS_T *const a_20210531_test_GPS_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S1>/Constant2' : Unused code path elimination
 * Block '<S1>/Constant3' : Unused code path elimination
 * Block '<S1>/Equal' : Unused code path elimination
 * Block '<S1>/Equal1' : Unused code path elimination
 * Block '<S1>/Equal2' : Unused code path elimination
 * Block '<S1>/OR' : Unused code path elimination
 * Block '<S1>/Switch' : Unused code path elimination
 * Block '<Root>/Sum' : Unused code path elimination
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
 * '<Root>' : 'a_20210531_test_GPS'
 * '<S1>'   : 'a_20210531_test_GPS/Subsystem1'
 * '<S2>'   : 'a_20210531_test_GPS/Subsystem2'
 * '<S3>'   : 'a_20210531_test_GPS/Subsystem2/Create_message'
 * '<S4>'   : 'a_20210531_test_GPS/Subsystem2/Subsystem'
 * '<S5>'   : 'a_20210531_test_GPS/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_a_20210531_test_GPS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
