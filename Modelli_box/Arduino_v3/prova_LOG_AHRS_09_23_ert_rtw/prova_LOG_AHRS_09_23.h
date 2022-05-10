/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_AHRS_09_23.h
 *
 * Code generated for Simulink model 'prova_LOG_AHRS_09_23'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 17:53:09 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prova_LOG_AHRS_09_23_h_
#define RTW_HEADER_prova_LOG_AHRS_09_23_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef prova_LOG_AHRS_09_23_COMMON_INCLUDES_
#define prova_LOG_AHRS_09_23_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                               /* prova_LOG_AHRS_09_23_COMMON_INCLUDES_ */

#include "prova_LOG_AHRS_09_23_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T Memory2[300];                /* '<S1>/Memory2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio[100];              /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  uint8_T dataIn[67];
  real_T poss_254[3];
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S12>/Data Type Conversion3' */
  uint32_T onboard[3];                 /* '<S17>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S10>/Data Type Conversion' */
  uint32_T DataTypeConversion9;        /* '<S2>/Data Type Conversion9' */
  real32_T ByteUnpack_o2[9];           /* '<S3>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S3>/Byte Reversal' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion1[6];     /* '<S11>/Data Type Conversion1' */
  real32_T DataTypeConversion3_m[4];   /* '<S18>/Data Type Conversion3' */
  real32_T DataTypeConversion1_b;      /* '<Root>/Data Type Conversion1' */
  real32_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_k;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_bl;     /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion6[4];     /* '<S2>/Data Type Conversion6' */
  real32_T WP_param[7];                /* '<S19>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_a[4];     /* '<S9>/Data Type Conversion' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T LVDE[8];                    /* '<S17>/Data Type Conversion2' */
  uint16_T DataTypeConversion2;        /* '<S9>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S18>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S16>/Data Type Conversion1' */
  uint16_T Memory_i;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion10;       /* '<S2>/Data Type Conversion10' */
  uint16_T DataTypeConversion11[3];    /* '<S2>/Data Type Conversion11' */
  uint16_T DataTypeConversion12;       /* '<S2>/Data Type Conversion12' */
  int16_T DataTypeConversion_j[9];     /* '<S11>/Data Type Conversion' */
  uint16_T WP_info_in[6];
  real_T num_254;
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Sum2;                         /* '<S25>/Sum2' */
  real_T Sum1;                         /* '<S25>/Sum1' */
  uint16_T DataTypeConversion13;       /* '<S2>/Data Type Conversion13' */
  uint16_T DataTypeConversion14;       /* '<S2>/Data Type Conversion14' */
  uint16_T DataTypeConversion15;       /* '<S2>/Data Type Conversion15' */
  uint16_T DataTypeConversion21;       /* '<S2>/Data Type Conversion21' */
  uint16_T DataTypeConversion20;       /* '<S2>/Data Type Conversion20' */
  uint16_T DataTypeConversion19;       /* '<S2>/Data Type Conversion19' */
  uint16_T DataTypeConversion18;       /* '<S2>/Data Type Conversion18' */
  uint16_T WP_info[6];                 /* '<S19>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T B_Current;                   /* '<S17>/Data Type Conversion1' */
  int16_T DataTypeConversion1_g[3];    /* '<S9>/Data Type Conversion1' */
  int16_T DataTypeConversion4_i;       /* '<S18>/Data Type Conversion4' */
  int16_T DataTypeConversion2_d;       /* '<S2>/Data Type Conversion2' */
  int16_T DataTypeConversion3_k[9];    /* '<S2>/Data Type Conversion3' */
  uint8_T SFunctionBuilder[41];        /* '<S3>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S3>/Byte Unpack' */
  uint8_T ByteUnpack_o3;               /* '<S3>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1[100];    /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_c[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_j;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_b[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T DataTypeConversion1_n[4];    /* '<S10>/Data Type Conversion1' */
  uint8_T SFunction_o1_k;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_i[264];         /* '<S2>/S-Function' */
  uint8_T DataTypeConversion8[2];      /* '<S2>/Data Type Conversion8' */
  uint8_T BytePack[67];                /* '<S2>/Byte Pack' */
  uint8_T iflogic;                     /* '<S12>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S17>/Data Type Conversion3' */
} B_prova_LOG_AHRS_09_23_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/Serial Transmit1' */
  codertarget_arduinobase_inter_T obj_f;/* '<S21>/Serial Transmit' */
  real_T SFunctionBuilder_DSTATE;      /* '<S3>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S1>/S-Function Builder' */
  volatile real_T RateTransition_Buffer0;/* '<S23>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S23>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S23>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S23>/Memory2' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_c[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_c2;    /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_c[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_k[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_i[9];  /* '<S1>/Memory2' */
  uint8_T is_active_c9_prova_LOG_AHRS_09_;/* '<S8>/Chart' */
  uint8_T i;                           /* '<S8>/Chart' */
  uint8_T message[100];                /* '<S1>/MATLAB Function4' */
  uint8_T counter_o;                   /* '<S1>/MATLAB Function4' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
} DW_prova_LOG_AHRS_09_23_T;

/* Parameters (default storage) */
struct P_prova_LOG_AHRS_09_23_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S21>/Serial Transmit'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S2>/Serial Transmit1'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S23>/Rate Transition'
                                          */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S23>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S23>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.02
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S23>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 3
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1000
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant1_Value_l[2];         /* Expression: [0 0]
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Constant3_Value_m;            /* Expression: 23
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S17>/Gain2'
                                        */
  real_T Constant2_Value_a;            /* Expression: 10
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: [0 0]
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant3_Value_a[3];         /* Expression: [0,0,0]
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Constant_Value_ng;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S9>/alt_r'
                                        */
  real_T Gain_Gain_e[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Constant3_Value_d;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S9>/vel y'
                                        */
  real_T RCSimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S9>/RC Simulated'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S9>/Constant4'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 100
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S18>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S18>/v simulated'
                                        */
  real_T Constant_Value_nt;            /* Expression: 30
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S18>/RC simulated'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 50
                                        * Referenced by: '<S18>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S18>/Rpm simulated'
                                        */
  real_T Constant_Value_g;             /* Expression: 4
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S16>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 100
                                        * Referenced by: '<S25>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S16>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Constant2_Value_d;            /* Expression: 90
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S16>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S16>/Timone Simulated'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Constant1_Value_d[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 10000
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 0.01
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Constant1_Value_i;            /* Expression: 101000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 298
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1004
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Constant5_Value;              /* Expression: 32
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant4_Value_g;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_j;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant_Value_or;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant3_Value_mm;           /* Expression: 1500
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant7_Value;              /* Expression: 9
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 8
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 7
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T Constant6_Value_k;            /* Expression: 6
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Constant1_Value_ja;           /* Expression: 1500
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Constant4_Value_j;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant3_Value_j;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value_f;            /* Expression: 0
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T Constant5_Value_e;            /* Expression: 1
                                        * Referenced by: '<S23>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S23>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S23>/Switch1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Gain_Gain_lz;               /* Computed Parameter: Gain_Gain_lz
                                        * Referenced by: '<S13>/Gain'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S14>/Gain'
                                        */
  real32_T Gain_Gain_br;               /* Computed Parameter: Gain_Gain_br
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S2>/Gain'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S17>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S17>/Gain1'
                                        */
  int16_T Gain2_Gain_p;                /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S2>/Gain2'
                                        */
  uint16_T Memory_InitialCondition_l;
                                /* Computed Parameter: Memory_InitialCondition_l
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S17>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S17>/ '
                                        */
  uint16_T Memory_InitialCondition_m;
                                /* Computed Parameter: Memory_InitialCondition_m
                                 * Referenced by: '<S2>/Memory'
                                 */
  uint8_T Memory4_InitialCondition[300];/* Expression: uint8(zeros(3,100))
                                         * Referenced by: '<S1>/Memory4'
                                         */
  uint8_T Constant1_Value_if;          /* Computed Parameter: Constant1_Value_if
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  uint8_T Memory1_InitialCondition_j;
                               /* Computed Parameter: Memory1_InitialCondition_j
                                * Referenced by: '<S1>/Memory1'
                                */
  uint8_T Memory_InitialCondition_i;
                                /* Computed Parameter: Memory_InitialCondition_i
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
                           * Referenced by: '<S10>/Type fixed_wing Autopilot generic'
                           */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S2>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S2>/Fine MSG1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_prova_LOG_AHRS_09_23_T {
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
extern P_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_P;

/* Block signals (default storage) */
extern B_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_B;

/* Block states (default storage) */
extern DW_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_DW;

/* External data declarations for dependent source files */
extern const uint16_T prova_LOG_AHRS_09_23_U16GND;/* uint16_T ground */

/* External function called from main */
extern void prova_LOG_AHRS_09_23_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void prova_LOG_AHRS_09_23_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void prova_LOG_AHRS_09_23_initialize(void);
extern void prova_LOG_AHRS_09_23_step0(void);
extern void prova_LOG_AHRS_09_23_step1(void);
extern void prova_LOG_AHRS_09_23_terminate(void);

/* Real-time Model object */
extern RT_MODEL_prova_LOG_AHRS_09_23_T *const prova_LOG_AHRS_09_23_M;
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
 * '<Root>' : 'prova_LOG_AHRS_09_23'
 * '<S1>'   : 'prova_LOG_AHRS_09_23/AIR RX'
 * '<S2>'   : 'prova_LOG_AHRS_09_23/AIR TX'
 * '<S3>'   : 'prova_LOG_AHRS_09_23/MTi'
 * '<S4>'   : 'prova_LOG_AHRS_09_23/AIR RX/MATLAB Function1'
 * '<S5>'   : 'prova_LOG_AHRS_09_23/AIR RX/MATLAB Function2'
 * '<S6>'   : 'prova_LOG_AHRS_09_23/AIR RX/MATLAB Function3'
 * '<S7>'   : 'prova_LOG_AHRS_09_23/AIR RX/MATLAB Function4'
 * '<S8>'   : 'prova_LOG_AHRS_09_23/AIR TX/Enable '
 * '<S9>'   : 'prova_LOG_AHRS_09_23/AIR TX/GPS'
 * '<S10>'  : 'prova_LOG_AHRS_09_23/AIR TX/Heartbeat'
 * '<S11>'  : 'prova_LOG_AHRS_09_23/AIR TX/IMU & Attidude'
 * '<S12>'  : 'prova_LOG_AHRS_09_23/AIR TX/If_subsystem'
 * '<S13>'  : 'prova_LOG_AHRS_09_23/AIR TX/Radians to Degrees'
 * '<S14>'  : 'prova_LOG_AHRS_09_23/AIR TX/Radians to Degrees1'
 * '<S15>'  : 'prova_LOG_AHRS_09_23/AIR TX/Radians to Degrees2'
 * '<S16>'  : 'prova_LOG_AHRS_09_23/AIR TX/Servo'
 * '<S17>'  : 'prova_LOG_AHRS_09_23/AIR TX/SystemStatus'
 * '<S18>'  : 'prova_LOG_AHRS_09_23/AIR TX/VFR'
 * '<S19>'  : 'prova_LOG_AHRS_09_23/AIR TX/Waypoints'
 * '<S20>'  : 'prova_LOG_AHRS_09_23/AIR TX/Enable /Chart'
 * '<S21>'  : 'prova_LOG_AHRS_09_23/AIR TX/Enable /Chart/sendbyte'
 * '<S22>'  : 'prova_LOG_AHRS_09_23/AIR TX/Heartbeat/Alarm set'
 * '<S23>'  : 'prova_LOG_AHRS_09_23/AIR TX/If_subsystem/Subsystem'
 * '<S24>'  : 'prova_LOG_AHRS_09_23/AIR TX/If_subsystem/iflogic_function'
 * '<S25>'  : 'prova_LOG_AHRS_09_23/AIR TX/Servo/Conversione'
 * '<S26>'  : 'prova_LOG_AHRS_09_23/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S27>'  : 'prova_LOG_AHRS_09_23/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S28>'  : 'prova_LOG_AHRS_09_23/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S29>'  : 'prova_LOG_AHRS_09_23/AIR TX/Waypoints/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_prova_LOG_AHRS_09_23_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
