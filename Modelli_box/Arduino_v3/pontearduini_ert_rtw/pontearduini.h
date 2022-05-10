/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pontearduini.h
 *
 * Code generated for Simulink model 'pontearduini'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Oct 25 17:17:38 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pontearduini_h_
#define RTW_HEADER_pontearduini_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef pontearduini_COMMON_INCLUDES_
#define pontearduini_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* pontearduini_COMMON_INCLUDES_ */

#include "pontearduini_types.h"

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
  real_T ComplextoRealImag[9];         /* '<S4>/Complex to Real-Imag' */
  real_T dataIn[6];
  uint8_T b_dataOut[32];
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  real_T Switch;                       /* '<S1>/Switch' */
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
} B_pontearduini_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_p_T obj; /* '<Root>/Serial Transmit1' */
  codertarget_arduinobase_inter_T obj_n;/* '<Root>/Serial Receive1' */
  uint8_T message[80];                 /* '<S2>/Create_message' */
  uint8_T counter;                     /* '<S2>/Create_message' */
  boolean_T start_found;               /* '<S2>/Create_message' */
  boolean_T end_found;                 /* '<S2>/Create_message' */
} DW_pontearduini_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Cal_alt;                      /* '<Root>/Cal_alt' */
} ExtU_pontearduini_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T mario;                       /* '<Root>/mario' */
} ExtY_pontearduini_T;

/* Parameters (default storage) */
struct P_pontearduini_T_ {
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S1>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S1>/Constant3'
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
struct tag_RTM_pontearduini_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_pontearduini_T pontearduini_P;

/* Block signals (default storage) */
extern B_pontearduini_T pontearduini_B;

/* Block states (default storage) */
extern DW_pontearduini_T pontearduini_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_pontearduini_T pontearduini_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_pontearduini_T pontearduini_Y;

/* Model entry point functions */
extern void pontearduini_initialize(void);
extern void pontearduini_step(void);
extern void pontearduini_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pontearduini_T *const pontearduini_M;
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
 * '<Root>' : 'pontearduini'
 * '<S1>'   : 'pontearduini/Subsystem1'
 * '<S2>'   : 'pontearduini/Subsystem2'
 * '<S3>'   : 'pontearduini/Subsystem2/Create_message'
 * '<S4>'   : 'pontearduini/Subsystem2/Subsystem'
 * '<S5>'   : 'pontearduini/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_pontearduini_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
