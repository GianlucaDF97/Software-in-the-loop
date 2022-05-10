/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_GPS_25_10.h
 *
 * Code generated for Simulink model 'prova_GPS_25_10'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 26 10:31:08 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prova_GPS_25_10_h_
#define RTW_HEADER_prova_GPS_25_10_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef prova_GPS_25_10_COMMON_INCLUDES_
#define prova_GPS_25_10_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* prova_GPS_25_10_COMMON_INCLUDES_ */

#include "prova_GPS_25_10_types.h"

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
  uint8_T Memory2[300];                /* '<S1>/Memory2' */
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T messaggio_l[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S20>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S22>/Complex to Real-Imag' */
  uint8_T b_dataOut[32];
  real_T poss_254[3];
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint16_T WP_info_in[6];
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  real_T Switch;                       /* '<S19>/Switch' */
  real_T num_254;
  real_T PatohPa1;                     /* '<S2>/Pa to hPa1' */
  real_T RateTransition;               /* '<S25>/Rate Transition' */
  real_T Sum;                          /* '<S27>/Sum' */
  real_T Sum1;                         /* '<S27>/Sum1' */
  real_T Sum2;                         /* '<S27>/Sum2' */
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
  real32_T DataTypeConversion4[6];     /* '<S10>/Data Type Conversion4' */
  real32_T DataTypeConversion3_a[4];   /* '<S14>/Data Type Conversion3' */
  real32_T DataTypeConversion17;       /* '<S2>/Data Type Conversion17' */
  real32_T DataTypeConversion4_g;      /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_a;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S2>/Data Type Conversion1' */
  real32_T WP_param[7];                /* '<S15>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T f;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_j[4];     /* '<S8>/Data Type Conversion' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T LVDE[8];                    /* '<S13>/Data Type Conversion2' */
  uint16_T Heading[9];                 /* '<S12>/Data Type Conversion1' */
  int32_T status;
  int32_T caso;
  int32_T f_d;
  int32_T eb_data;
  int32_T i;
  int32_T i_g;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S11>/Data Type Conversion3' */
  uint32_T onboard[3];                 /* '<S13>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S9>/Data Type Conversion' */
  uint32_T qY;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T DataTypeConversion2;        /* '<S8>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S14>/Data Type Conversion5' */
  uint16_T Memory_e;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T WP_info[6];                 /* '<S15>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T B_Current;                   /* '<S13>/Data Type Conversion1' */
  int16_T DataTypeConversion3_m[9];    /* '<S10>/Data Type Conversion3' */
  int16_T DataTypeConversion1_k[3];    /* '<S8>/Data Type Conversion1' */
  int16_T DataTypeConversion4_o;       /* '<S14>/Data Type Conversion4' */
  int16_T DataTypeConversion2_c;       /* '<S2>/Data Type Conversion2' */
  uint8_T SFunctionBuilder_o1[100];    /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_p[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_m;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_n[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T DataTypeConversion1_n[4];    /* '<S9>/Data Type Conversion1' */
  uint8_T SFunction_o1_m;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_n[264];         /* '<S2>/S-Function' */
  uint8_T iflogic;                     /* '<S11>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S13>/Data Type Conversion3' */
} B_prova_GPS_25_10_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_n_T obj; /* '<S17>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_m;/* '<S18>/Serial Receive1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  volatile real_T RateTransition_Buffer0;/* '<S25>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S25>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S25>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S25>/Memory2' */
  real_T Memory_PreviousInput_i[9];    /* '<S22>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_g[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_j[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_m[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_c[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S20>/Create_message' */
  uint8_T counter_k;                   /* '<S20>/Create_message' */
  uint8_T is_active_c9_prova_GPS_25_10;/* '<S7>/Chart' */
  uint8_T i;                           /* '<S7>/Chart' */
  uint8_T message_e[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_m;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S20>/Create_message' */
  boolean_T end_found;                 /* '<S20>/Create_message' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
} DW_prova_GPS_25_10_T;

/* Parameters (default storage) */
struct P_prova_GPS_25_10_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S17>/Serial Transmit'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S18>/Serial Receive1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S19>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S22>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S22>/Memory'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S25>/Rate Transition'
                                          */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S25>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S25>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S25>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0.02
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T Memory_InitialCondition_k;    /* Expression: -0.02
                                        * Referenced by: '<S25>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 3
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1000
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: [0 0]
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant3_Value_g;            /* Expression: 23
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Constant2_Value_g;            /* Expression: 10
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_g[2];         /* Expression: [0 0]
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant5_Value[9];           /* Expression: ones(1,9)
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant4_Value[3];           /* Expression: [0 0 0]
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S8>/alt_r'
                                        */
  real_T Gain_Gain_i[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S8>/vel y'
                                        */
  real_T RCSimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S8>/RC Simulated'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 100
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S14>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S14>/v simulated'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S14>/RC simulated'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 50
                                        * Referenced by: '<S14>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S14>/Rpm simulated'
                                        */
  real_T Constant_Value_c;             /* Expression: 4
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S12>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 100
                                        * Referenced by: '<S27>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S12>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 90
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S12>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S12>/Timone Simulated'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Constant1_Value_gk[3];        /* Expression: zeros(3,1)
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 10000
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 0.01
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant5_Value_o;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant3_Value_k2;           /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Constant4_Value_f;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_f;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant3_Value_b[3];         /* Expression: [0,0,0]
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T ACCsimulated_Value[3];        /* Expression: [0.102 0 0]
                                        * Referenced by: '<S10>/ACC simulated'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T psimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/p simulated'
                                        */
  real_T phisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S10>/phi simulated'
                                        */
  real_T psisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S10>/psi simulated'
                                        */
  real_T qsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/q simulated'
                                        */
  real_T rsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/r simulated'
                                        */
  real_T thetasimulated_Value;         /* Expression: 0
                                        * Referenced by: '<S10>/theta simulated'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 10^3
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Constant4_Value_d;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant4'
                                        */
  real_T Constant5_Value_k;            /* Expression: 1
                                        * Referenced by: '<S25>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S25>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S25>/Switch1'
                                        */
  int32_T Constant_Value_i2;           /* Computed Parameter: Constant_Value_i2
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S13>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S13>/Gain1'
                                        */
  uint16_T Memory_InitialCondition_o;
                                /* Computed Parameter: Memory_InitialCondition_o
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S13>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S13>/ '
                                        */
  uint16_T Memory_InitialCondition_d;
                                /* Computed Parameter: Memory_InitialCondition_d
                                 * Referenced by: '<S2>/Memory'
                                 */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S22>/mario'
                                        */
  uint8_T Memory4_InitialCondition[300];/* Expression: uint8(zeros(3,100))
                                         * Referenced by: '<S1>/Memory4'
                                         */
  uint8_T Constant1_Value_i;           /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  uint8_T Memory1_InitialCondition_l;
                               /* Computed Parameter: Memory1_InitialCondition_l
                                * Referenced by: '<S1>/Memory1'
                                */
  uint8_T Memory_InitialCondition_f;
                                /* Computed Parameter: Memory_InitialCondition_f
                                 * Referenced by: '<Root>/Memory'
                                 */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory2_InitialCondition_j[9];
                               /* Computed Parameter: Memory2_InitialCondition_j
                                * Referenced by: '<S1>/Memory2'
                                */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S9>/Type fixed_wing Autopilot generic'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_prova_GPS_25_10_T {
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
extern P_prova_GPS_25_10_T prova_GPS_25_10_P;

/* Block signals (default storage) */
extern B_prova_GPS_25_10_T prova_GPS_25_10_B;

/* Block states (default storage) */
extern DW_prova_GPS_25_10_T prova_GPS_25_10_DW;

/* External data declarations for dependent source files */
extern const uint16_T prova_GPS_25_10_U16GND;/* uint16_T ground */

/* External function called from main */
extern void prova_GPS_25_10_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void prova_GPS_25_10_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void prova_GPS_25_10_initialize(void);
extern void prova_GPS_25_10_step0(void);
extern void prova_GPS_25_10_step1(void);
extern void prova_GPS_25_10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_prova_GPS_25_10_T *const prova_GPS_25_10_M;
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
 * '<Root>' : 'prova_GPS_25_10'
 * '<S1>'   : 'prova_GPS_25_10/AIR RX'
 * '<S2>'   : 'prova_GPS_25_10/AIR TX'
 * '<S3>'   : 'prova_GPS_25_10/AIR RX/MATLAB Function1'
 * '<S4>'   : 'prova_GPS_25_10/AIR RX/MATLAB Function2'
 * '<S5>'   : 'prova_GPS_25_10/AIR RX/MATLAB Function3'
 * '<S6>'   : 'prova_GPS_25_10/AIR RX/MATLAB Function4'
 * '<S7>'   : 'prova_GPS_25_10/AIR TX/Enable '
 * '<S8>'   : 'prova_GPS_25_10/AIR TX/GPS'
 * '<S9>'   : 'prova_GPS_25_10/AIR TX/Heartbeat'
 * '<S10>'  : 'prova_GPS_25_10/AIR TX/IMU & Attidude'
 * '<S11>'  : 'prova_GPS_25_10/AIR TX/If_subsystem'
 * '<S12>'  : 'prova_GPS_25_10/AIR TX/Servo'
 * '<S13>'  : 'prova_GPS_25_10/AIR TX/SystemStatus'
 * '<S14>'  : 'prova_GPS_25_10/AIR TX/VFR'
 * '<S15>'  : 'prova_GPS_25_10/AIR TX/Waypoints'
 * '<S16>'  : 'prova_GPS_25_10/AIR TX/Enable /Chart'
 * '<S17>'  : 'prova_GPS_25_10/AIR TX/Enable /Chart/sendbyte'
 * '<S18>'  : 'prova_GPS_25_10/AIR TX/GPS/GPS_Venus'
 * '<S19>'  : 'prova_GPS_25_10/AIR TX/GPS/GPS_Venus/Subsystem1'
 * '<S20>'  : 'prova_GPS_25_10/AIR TX/GPS/GPS_Venus/Subsystem2'
 * '<S21>'  : 'prova_GPS_25_10/AIR TX/GPS/GPS_Venus/Subsystem2/Create_message'
 * '<S22>'  : 'prova_GPS_25_10/AIR TX/GPS/GPS_Venus/Subsystem2/Subsystem'
 * '<S23>'  : 'prova_GPS_25_10/AIR TX/GPS/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S24>'  : 'prova_GPS_25_10/AIR TX/Heartbeat/Alarm set'
 * '<S25>'  : 'prova_GPS_25_10/AIR TX/If_subsystem/Subsystem'
 * '<S26>'  : 'prova_GPS_25_10/AIR TX/If_subsystem/iflogic_function'
 * '<S27>'  : 'prova_GPS_25_10/AIR TX/Servo/Conversione'
 * '<S28>'  : 'prova_GPS_25_10/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S29>'  : 'prova_GPS_25_10/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S30>'  : 'prova_GPS_25_10/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S31>'  : 'prova_GPS_25_10/AIR TX/Waypoints/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_prova_GPS_25_10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
