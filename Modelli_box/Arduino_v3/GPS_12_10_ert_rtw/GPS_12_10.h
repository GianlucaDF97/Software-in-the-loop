/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GPS_12_10.h
 *
 * Code generated for Simulink model 'GPS_12_10'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 16:53:32 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GPS_12_10_h_
#define RTW_HEADER_GPS_12_10_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef GPS_12_10_COMMON_INCLUDES_
#define GPS_12_10_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* GPS_12_10_COMMON_INCLUDES_ */

#include "GPS_12_10_types.h"

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
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_c[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_cl[80];            /* '<S3>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S9>/Complex to Real-Imag' */
  real_T dataIn[6];
  uint8_T b_dataOut[32];
  real_T poss_254[3];
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  real_T Switch;                       /* '<S2>/Switch' */
  real_T num_254;
  real_T rtb_Lat_re;
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
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  int32_T status;
  int32_T caso;
  int32_T f;
  int32_T eb_data;
  int32_T i;
  int32_T i_d;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T qY;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint8_T SFunctionBuilder_o1[100];    /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_h[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3;                /* '<S1>/S-Function' */
  uint8_T SFunction_o4[2];             /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
} B_GPS_12_10_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_k_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Serial Receive1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_e[8];  /* '<S1>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput[2];    /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_g[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput[9];    /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S3>/Create_message' */
  uint8_T counter_o;                   /* '<S3>/Create_message' */
  uint8_T message_o[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_l;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S3>/Create_message' */
  boolean_T end_found;                 /* '<S3>/Create_message' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
} DW_GPS_12_10_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Cal_alt;                      /* '<Root>/Cal_alt' */
} ExtU_GPS_12_10_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T mario;                       /* '<Root>/mario' */
} ExtY_GPS_12_10_T;

/* Parameters (default storage) */
struct P_GPS_12_10_T_ {
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
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
                                        * Referenced by: '<S9>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  int32_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint16_T Memory_InitialCondition_m;
                                /* Computed Parameter: Memory_InitialCondition_m
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S9>/mario'
                                        */
  uint8_T Memory4_InitialCondition[300];/* Expression: uint8(zeros(3,100))
                                         * Referenced by: '<S1>/Memory4'
                                         */
  uint8_T Constant1_Value_k;           /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S1>/Memory1'
                                  */
  uint8_T Memory_InitialCondition_c;
                                /* Computed Parameter: Memory_InitialCondition_c
                                 * Referenced by: '<Root>/Memory'
                                 */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory2_InitialCondition[9];
                                 /* Computed Parameter: Memory2_InitialCondition
                                  * Referenced by: '<S1>/Memory2'
                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_GPS_12_10_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_GPS_12_10_T GPS_12_10_P;

/* Block signals (default storage) */
extern B_GPS_12_10_T GPS_12_10_B;

/* Block states (default storage) */
extern DW_GPS_12_10_T GPS_12_10_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_GPS_12_10_T GPS_12_10_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_GPS_12_10_T GPS_12_10_Y;

/* Model entry point functions */
extern void GPS_12_10_initialize(void);
extern void GPS_12_10_step(void);
extern void GPS_12_10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_GPS_12_10_T *const GPS_12_10_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Tversion' : Unused code path elimination
 * Block '<S1>/Data Tversion1' : Unused code path elimination
 * Block '<S1>/Data Tversion2' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'GPS_12_10'
 * '<S1>'   : 'GPS_12_10/AIR RX'
 * '<S2>'   : 'GPS_12_10/Subsystem1'
 * '<S3>'   : 'GPS_12_10/Subsystem2'
 * '<S4>'   : 'GPS_12_10/AIR RX/MATLAB Function1'
 * '<S5>'   : 'GPS_12_10/AIR RX/MATLAB Function2'
 * '<S6>'   : 'GPS_12_10/AIR RX/MATLAB Function3'
 * '<S7>'   : 'GPS_12_10/AIR RX/MATLAB Function4'
 * '<S8>'   : 'GPS_12_10/Subsystem2/Create_message'
 * '<S9>'   : 'GPS_12_10/Subsystem2/Subsystem'
 * '<S10>'  : 'GPS_12_10/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_GPS_12_10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
