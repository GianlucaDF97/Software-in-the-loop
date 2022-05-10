/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_3_of_provaLOG_09_28_BUONO.h
 *
 * Code generated for Simulink model 'Copy_3_of_provaLOG_09_28_BUONO'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 25 12:49:50 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_3_of_provaLOG_09_28_BUONO_h_
#define RTW_HEADER_Copy_3_of_provaLOG_09_28_BUONO_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Copy_3_of_provaLOG_09_28_BUONO_COMMON_INCLUDES_
#define Copy_3_of_provaLOG_09_28_BUONO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                     /* Copy_3_of_provaLOG_09_28_BUONO_COMMON_INCLUDES_ */

#include "Copy_3_of_provaLOG_09_28_BUONO_types.h"
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

#define Copy_3_of_provaLOG_09_28_BUONO_M (Copy_3_of_provaLOG_09_28_BUO_M)

/* Block signals (default storage) */
typedef struct {
  uint8_T Memory2[300];                /* '<S1>/Memory2' */
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T messaggio[100];              /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  uint8_T dataIn[67];
  real_T poss_254[3];
  real_T Switch;                       /* '<S19>/Switch' */
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S11>/Data Type Conversion3' */
  uint32_T onboard[3];                 /* '<S13>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S9>/Data Type Conversion' */
  uint32_T DataTypeConversion16;       /* '<S2>/Data Type Conversion16' */
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
  real32_T DataTypeConversion6[4];     /* '<S2>/Data Type Conversion6' */
  real32_T WP_param[7];                /* '<S15>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_j[4];     /* '<S8>/Data Type Conversion' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T LVDE[8];                    /* '<S13>/Data Type Conversion2' */
  uint16_T DataTypeConversion2;        /* '<S8>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S14>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S12>/Data Type Conversion1' */
  uint16_T Memory_e;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion10;       /* '<S2>/Data Type Conversion10' */
  uint16_T DataTypeConversion11[3];    /* '<S2>/Data Type Conversion11' */
  uint16_T DataTypeConversion12;       /* '<S2>/Data Type Conversion12' */
  int16_T DataTypeConversion3_p[9];    /* '<S2>/Data Type Conversion3' */
  uint8_T SFunctionBuilder_o1[100];    /* '<S1>/S-Function Builder' */
  uint16_T WP_info_in[6];
  real_T num_254;
  real_T Sum;                          /* '<S23>/Sum' */
  real_T Gain2;                        /* '<S23>/Gain2' */
  real_T quota;                        /* '<S18>/Sum' */
  real_T PatohPa;                      /* '<S2>/Pa to hPa' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  uint16_T DataTypeConversion13;       /* '<S2>/Data Type Conversion13' */
  uint16_T DataTypeConversion14;       /* '<S2>/Data Type Conversion14' */
  uint16_T DataTypeConversion15;       /* '<S2>/Data Type Conversion15' */
  uint16_T DataTypeConversion21;       /* '<S2>/Data Type Conversion21' */
  uint16_T DataTypeConversion20;       /* '<S2>/Data Type Conversion20' */
  uint16_T DataTypeConversion19;       /* '<S2>/Data Type Conversion19' */
  uint16_T DataTypeConversion18;       /* '<S2>/Data Type Conversion18' */
  uint16_T WP_info[6];                 /* '<S15>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T B_Current;                   /* '<S13>/Data Type Conversion1' */
  int16_T DataTypeConversion3_m[9];    /* '<S10>/Data Type Conversion3' */
  int16_T DataTypeConversion1_k[3];    /* '<S8>/Data Type Conversion1' */
  int16_T DataTypeConversion4_o;       /* '<S14>/Data Type Conversion4' */
  int16_T DataTypeConversion2_c;       /* '<S2>/Data Type Conversion2' */
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
  uint8_T DataTypeConversion8[2];      /* '<S2>/Data Type Conversion8' */
  uint8_T BytePack[67];                /* '<S2>/Byte Pack' */
  uint8_T iflogic;                     /* '<S11>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S13>/Data Type Conversion3' */
} B_Copy_3_of_provaLOG_09_28_BU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/Serial Transmit1' */
  codertarget_arduinobase_inter_T obj_j;/* '<S17>/Serial Transmit' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  volatile real_T RateTransition_Buffer0;/* '<S21>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S21>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S21>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S21>/Memory2' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
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
  uint8_T is_active_c9_Copy_3_of_provaLOG;/* '<S7>/Chart' */
  uint8_T i;                           /* '<S7>/Chart' */
  uint8_T message[100];                /* '<S1>/MATLAB Function4' */
  uint8_T counter_m;                   /* '<S1>/MATLAB Function4' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
} DW_Copy_3_of_provaLOG_09_28_B_T;

/* Parameters (default storage) */
struct P_Copy_3_of_provaLOG_09_28_BU_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S17>/Serial Transmit'
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
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S2>/Serial Transmit1'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S21>/Rate Transition'
                                          */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S21>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S21>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S21>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0.02
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S21>/Memory'
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
  real_T Constant6_Value;              /* Expression: 0.433
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0.345
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0.123
                                        * Referenced by: '<S10>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0.0126
                                        * Referenced by: '<S10>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: 0.0425
                                        * Referenced by: '<S10>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0.0742
                                        * Referenced by: '<S10>/Constant11'
                                        */
  real_T Constant4_Value[3];           /* Expression: [0 0 0]
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant12_Value;             /* Expression: 2
                                        * Referenced by: '<S10>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 4
                                        * Referenced by: '<S10>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 3
                                        * Referenced by: '<S10>/Constant14'
                                        */
  real_T Constant2_Value_e;            /* Expression: 42.12
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Constant1_Value_d;            /* Expression: 12.35
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant3_Value_b;            /* Expression: 34
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S18>/Constant5'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S8>/alt_r'
                                        */
  real_T Gain_Gain_i[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Constant_Value_mi;            /* Expression: 20
                                        * Referenced by: '<S18>/Constant'
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
  real_T Constant4_Value_g;            /* Expression: 50
                                        * Referenced by: '<S18>/Constant4'
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
  real_T Constant6_Value_j;            /* Expression: 28
                                        * Referenced by: '<Root>/Constant6'
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
                                        * Referenced by: '<S23>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S12>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 90
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S12>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S12>/Timone Simulated'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
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
  real_T Constant7_Value_f;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant10_Value_g;           /* Expression: 25
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant8_Value_a;            /* Expression: 101000
                                        * Referenced by: '<Root>/Constant8'
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
  real_T Constant9_Value_k;            /* Expression: 32
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_f;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value_p;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant_Value_ez;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant7_Value_m;            /* Expression: 9
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T Constant8_Value_g;            /* Expression: 8
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Constant9_Value_j;            /* Expression: 7
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T Constant6_Value_l;            /* Expression: 6
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Constant6_Value_g;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant6'
                                        */
  real_T Constant4_Value_d;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant4'
                                        */
  real_T Constant5_Value_k;            /* Expression: 1
                                        * Referenced by: '<S21>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S21>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S21>/Switch1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S13>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S13>/Gain1'
                                        */
  int16_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S2>/Gain'
                                        */
  int16_T Gain2_Gain_n;                /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S2>/Gain2'
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
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S2>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S2>/Fine MSG1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_3_of_provaLOG_09_T {
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
extern P_Copy_3_of_provaLOG_09_28_BU_T Copy_3_of_provaLOG_09_28_BUON_P;

/* Block signals (default storage) */
extern B_Copy_3_of_provaLOG_09_28_BU_T Copy_3_of_provaLOG_09_28_BUON_B;

/* Block states (default storage) */
extern DW_Copy_3_of_provaLOG_09_28_B_T Copy_3_of_provaLOG_09_28_BUO_DW;

/* External data declarations for dependent source files */
extern const uint16_T Copy_3_of_provaLOG_09_28_BUONO_U16GND;/* uint16_T ground */

/* External function called from main */
extern void Copy_3_of_provaLOG_09_28_BUONO_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Copy_3_of_provaLOG_09_28_BUONO_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Copy_3_of_provaLOG_09_28_BUONO_initialize(void);
extern void Copy_3_of_provaLOG_09_28_BUONO_step0(void);
extern void Copy_3_of_provaLOG_09_28_BUONO_step1(void);
extern void Copy_3_of_provaLOG_09_28_BUONO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_3_of_provaLOG_0_T *const Copy_3_of_provaLOG_09_28_BUO_M;
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
 * '<Root>' : 'Copy_3_of_provaLOG_09_28_BUONO'
 * '<S1>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR RX'
 * '<S2>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX'
 * '<S3>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR RX/MATLAB Function1'
 * '<S4>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR RX/MATLAB Function2'
 * '<S5>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR RX/MATLAB Function3'
 * '<S6>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR RX/MATLAB Function4'
 * '<S7>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Enable '
 * '<S8>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/GPS'
 * '<S9>'   : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Heartbeat'
 * '<S10>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/IMU & Attidude'
 * '<S11>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/If_subsystem'
 * '<S12>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Servo'
 * '<S13>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/SystemStatus'
 * '<S14>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/VFR'
 * '<S15>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Waypoints'
 * '<S16>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Enable /Chart'
 * '<S17>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Enable /Chart/sendbyte'
 * '<S18>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus'
 * '<S19>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus/Subsystem1'
 * '<S20>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Heartbeat/Alarm set'
 * '<S21>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/If_subsystem/Subsystem'
 * '<S22>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/If_subsystem/iflogic_function'
 * '<S23>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Servo/Conversione'
 * '<S24>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S25>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S26>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S27>'  : 'Copy_3_of_provaLOG_09_28_BUONO/AIR TX/Waypoints/MATLAB Function'
 */
#endif                        /* RTW_HEADER_Copy_3_of_provaLOG_09_28_BUONO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
