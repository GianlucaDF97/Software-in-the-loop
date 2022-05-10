/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaBMP_10_28_s2b.h
 *
 * Code generated for Simulink model 'provaBMP_10_28_s2b'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 15:05:27 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provaBMP_10_28_s2b_h_
#define RTW_HEADER_provaBMP_10_28_s2b_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef provaBMP_10_28_s2b_COMMON_INCLUDES_
#define provaBMP_10_28_s2b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_I2C.h"
#endif                                 /* provaBMP_10_28_s2b_COMMON_INCLUDES_ */

#include "provaBMP_10_28_s2b_types.h"
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

/* Block signals for system '<S3>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S31>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S31>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S31>/I2C Read' */
  int16_T I2CRead9;                    /* '<S31>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S31>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S31>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S31>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S31>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S31>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S31>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S31>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S31>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S31>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S31>/I2C Read12' */
} B_One_time_initialization_pro_T;

/* Block states (default storage) for system '<S3>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S31>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_l;/* '<S31>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_b;/* '<S31>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_m;/* '<S31>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_n;/* '<S31>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_i;/* '<S31>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_o;/* '<S31>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_ba;/* '<S31>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_h;/* '<S31>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S31>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_f;/* '<S31>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_d;/* '<S31>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_n0;/* '<S31>/I2C Read' */
  codertarget_arduinobase_int_k_T obj_ff;/* '<S31>/I2C Write3' */
  codertarget_arduinobase_int_k_T obj_n4;/* '<S31>/I2C Write2' */
  codertarget_arduinobase_int_k_T obj_e;/* '<S31>/I2C Write1' */
} DW_One_time_initialization_pr_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T Memory2[300];                /* '<S1>/Memory2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio[100];              /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real_T poss_254[3];
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T LVDE[8];                    /* '<S14>/Data Type Conversion2' */
  uint16_T WP_info_in[6];
  uint32_T i2cname;
  real_T num_254;
  real_T PatohPa1;                     /* '<S2>/Pa to hPa1' */
  real_T Sum2;                         /* '<S22>/Sum2' */
  real_T Sum1;                         /* '<S22>/Sum1' */
  real_T RateTransition;               /* '<S20>/Rate Transition' */
  real_T deltafalllimit;               /* '<S27>/delta fall limit' */
  int32_T status;
  int32_T caso;
  int32_T f;
  int32_T g;
  int32_T x_m;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S12>/Data Type Conversion3' */
  uint32_T onboard[3];                 /* '<S14>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S10>/Data Type Conversion' */
  uint32_T SFunctionBuilder1;          /* '<S28>/S-Function Builder1' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion1[6];     /* '<S11>/Data Type Conversion1' */
  real32_T DataTypeConversion3_m;      /* '<S3>/Data Type Conversion3' */
  real32_T DataTypeConversion3_p[4];   /* '<S15>/Data Type Conversion3' */
  real32_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_g;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_n;      /* '<S2>/Data Type Conversion1' */
  real32_T T;                          /* '<S34>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S28>/S-Function Builder' */
  real32_T WP_param[7];                /* '<S16>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_n[4];     /* '<S9>/Data Type Conversion' */
  int32_T DataTypeConversion1_l;       /* '<S28>/Data Type  Conversion1' */
  int32_T DataTypeConversion_p;        /* '<S28>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_i;       /* '<S28>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T DataTypeConversion2;        /* '<S9>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S15>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S13>/Data Type Conversion1' */
  uint16_T Memory_n;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T WP_info[6];                 /* '<S16>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T B_Current;                   /* '<S14>/Data Type Conversion1' */
  int16_T DataTypeConversion_c[9];     /* '<S11>/Data Type Conversion' */
  int16_T DataTypeConversion1_h[3];    /* '<S9>/Data Type Conversion1' */
  int16_T DataTypeConversion4_h;       /* '<S15>/Data Type Conversion4' */
  int16_T DataTypeConversion2_d;       /* '<S2>/Data Type Conversion2' */
  uint8_T SFunctionBuilder_o1_e[100];  /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_k[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_f;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_j[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T DataTypeConversion1_hk[4];   /* '<S10>/Data Type Conversion1' */
  uint8_T SFunction_o1_g;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_b[264];         /* '<S2>/S-Function' */
  uint8_T iflogic;                     /* '<S12>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S14>/Data Type Conversion3' */
  B_One_time_initialization_pro_T One_time_initialization;/* '<S3>/One_time_initialization' */
} B_provaBMP_10_28_s2b_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_d_T obj; /* '<S18>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_d;/* '<S28>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_i;/* '<S28>/I2C Read1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S27>/Delay Input2' */
  volatile real_T RateTransition_Buffer0;/* '<S20>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S20>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S20>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S20>/Memory2' */
  real_T P_ref;                        /* '<S3>/MATLAB Function' */
  real_T rl_up;                        /* '<S3>/MATLAB Function' */
  real_T rl_dw;                        /* '<S3>/MATLAB Function' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_e[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_f;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE;          /* '<S3>/Unit Delay' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_m[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_m[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T is_active_c9_provaBMP_10_28_s2b;/* '<S8>/Chart' */
  uint8_T i;                           /* '<S8>/Chart' */
  uint8_T message[100];                /* '<S1>/MATLAB Function4' */
  uint8_T counter_b;                   /* '<S1>/MATLAB Function4' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  DW_One_time_initialization_pr_T One_time_initialization;/* '<S3>/One_time_initialization' */
} DW_provaBMP_10_28_s2b_T;

/* Parameters for system: '<S3>/One_time_initialization' */
struct P_One_time_initialization_pro_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S31>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S31>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S31>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S31>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S31>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S31>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S31>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S31>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S31>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S31>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S31>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S31>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S31>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S31>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S31>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S31>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S31>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S31>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_provaBMP_10_28_s2b_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S28>/I2C Read1'
                                        *   '<S28>/I2C Read12'
                                        *   '<S31>/I2C Read'
                                        *   '<S31>/I2C Read1'
                                        *   '<S31>/I2C Read10'
                                        *   '<S31>/I2C Read11'
                                        *   '<S31>/I2C Read2'
                                        *   '<S31>/I2C Read3'
                                        *   '<S31>/I2C Read4'
                                        *   '<S31>/I2C Read5'
                                        *   '<S31>/I2C Read6'
                                        *   '<S31>/I2C Read7'
                                        *   '<S31>/I2C Read8'
                                        *   '<S31>/I2C Read9'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S18>/Serial Transmit'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S28>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S28>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S28>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S28>/Constant3'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S20>/Rate Transition'
                                          */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Constant3_Value_b;            /* Expression: 1
                                        * Referenced by: '<S20>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S20>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S20>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0.02
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S20>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 3
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1000
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: [0 0]
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant3_Value_c;            /* Expression: 23
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T Constant2_Value_g;            /* Expression: 10
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: [0 0]
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T ACCsimulated_Value[3];        /* Expression: [0.102 0 0]
                                        * Referenced by: '<S11>/ACC simulated'
                                        */
  real_T psimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S11>/p simulated'
                                        */
  real_T qsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S11>/q simulated'
                                        */
  real_T rsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S11>/r simulated'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_nf;           /* Expression: 0
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 10^3
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T phisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S11>/phi simulated'
                                        */
  real_T thetasimulated_Value;         /* Expression: 0
                                        * Referenced by: '<S11>/theta simulated'
                                        */
  real_T psisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S11>/psi simulated'
                                        */
  real_T Constant3_Value_j;            /* Expression: 42.15
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant5_Value_j;            /* Expression: 12.36
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant4_Value_b;            /* Expression: 30
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S9>/alt_r'
                                        */
  real_T Gain_Gain_h[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Constant6_Value_l;            /* Expression: 20
                                        * Referenced by: '<Root>/Constant6'
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
  real_T Constant7_Value;              /* Expression: 120
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S27>/Delay Input2'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_a;             /* Expression: 120000
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_kc;           /* Expression: 101000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S27>/sample time'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S15>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S15>/v simulated'
                                        */
  real_T T_0_Value;                    /* Expression: 298
                                        * Referenced by: '<Root>/T_0'
                                        */
  real_T Constant_Value_o;             /* Expression: 15
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S15>/RC simulated'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 50
                                        * Referenced by: '<S15>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S15>/Rpm simulated'
                                        */
  real_T Constant_Value_p;             /* Expression: 4
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S13>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 100
                                        * Referenced by: '<S22>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S13>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180/pi
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Constant2_Value_gt;           /* Expression: 90
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S13>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_h4;                 /* Expression: 180/pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S13>/Timone Simulated'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Constant1_Value_c[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 10000
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0.01
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_eg;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Constant4_Value_b5;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_a;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant4_Value_n;            /* Expression: 0
                                        * Referenced by: '<S20>/Constant4'
                                        */
  real_T Constant5_Value_d;            /* Expression: 1
                                        * Referenced by: '<S20>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S20>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S20>/Switch1'
                                        */
  int32_T Constant_Value_j;            /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S28>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S34>/T_0'
                                        */
  real32_T Switch_Threshold_c;         /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S32>/Switch'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S28>/p'
                                        */
  uint32_T Constant7_Value_h;          /* Computed Parameter: Constant7_Value_h
                                        * Referenced by: '<S28>/Constant7'
                                        */
  uint32_T Constant10_Value_i;         /* Computed Parameter: Constant10_Value_i
                                        * Referenced by: '<S28>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S28>/Constant11'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S28>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S28>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S14>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S14>/Gain1'
                                        */
  uint16_T Memory_InitialCondition_o;
                                /* Computed Parameter: Memory_InitialCondition_o
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S14>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S14>/ '
                                        */
  uint16_T Memory_InitialCondition_h;
                                /* Computed Parameter: Memory_InitialCondition_h
                                 * Referenced by: '<S2>/Memory'
                                 */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  boolean_T Constant3_Value_g;         /* Computed Parameter: Constant3_Value_g
                                        * Referenced by: '<S3>/Constant3'
                                        */
  uint8_T Memory4_InitialCondition[300];/* Expression: uint8(zeros(3,100))
                                         * Referenced by: '<S1>/Memory4'
                                         */
  uint8_T Constant1_Value_h;           /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  uint8_T Memory1_InitialCondition_g;
                               /* Computed Parameter: Memory1_InitialCondition_g
                                * Referenced by: '<S1>/Memory1'
                                */
  uint8_T Memory_InitialCondition_g;
                                /* Computed Parameter: Memory_InitialCondition_g
                                 * Referenced by: '<Root>/Memory'
                                 */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory2_InitialCondition_p[9];
                               /* Computed Parameter: Memory2_InitialCondition_p
                                * Referenced by: '<S1>/Memory2'
                                */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S10>/Type fixed_wing Autopilot generic'
                           */
  P_One_time_initialization_pro_T One_time_initialization;/* '<S3>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_provaBMP_10_28_s2b_T {
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
extern P_provaBMP_10_28_s2b_T provaBMP_10_28_s2b_P;

/* Block signals (default storage) */
extern B_provaBMP_10_28_s2b_T provaBMP_10_28_s2b_B;

/* Block states (default storage) */
extern DW_provaBMP_10_28_s2b_T provaBMP_10_28_s2b_DW;

/* External data declarations for dependent source files */
extern const uint16_T provaBMP_10_28_s2b_U16GND;/* uint16_T ground */

/* External function called from main */
extern void provaBMP_10_28_s2b_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void provaBMP_10_28_s2b_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void provaBMP_10_28_s2b_initialize(void);
extern void provaBMP_10_28_s2b_step0(void);
extern void provaBMP_10_28_s2b_step1(void);
extern void provaBMP_10_28_s2b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_provaBMP_10_28_s2b_T *const provaBMP_10_28_s2b_M;
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
 * '<Root>' : 'provaBMP_10_28_s2b'
 * '<S1>'   : 'provaBMP_10_28_s2b/AIR RX'
 * '<S2>'   : 'provaBMP_10_28_s2b/AIR TX'
 * '<S3>'   : 'provaBMP_10_28_s2b/BMP_280'
 * '<S4>'   : 'provaBMP_10_28_s2b/AIR RX/MATLAB Function1'
 * '<S5>'   : 'provaBMP_10_28_s2b/AIR RX/MATLAB Function2'
 * '<S6>'   : 'provaBMP_10_28_s2b/AIR RX/MATLAB Function3'
 * '<S7>'   : 'provaBMP_10_28_s2b/AIR RX/MATLAB Function4'
 * '<S8>'   : 'provaBMP_10_28_s2b/AIR TX/Enable '
 * '<S9>'   : 'provaBMP_10_28_s2b/AIR TX/GPS'
 * '<S10>'  : 'provaBMP_10_28_s2b/AIR TX/Heartbeat'
 * '<S11>'  : 'provaBMP_10_28_s2b/AIR TX/IMU & Attidude'
 * '<S12>'  : 'provaBMP_10_28_s2b/AIR TX/If_subsystem'
 * '<S13>'  : 'provaBMP_10_28_s2b/AIR TX/Servo'
 * '<S14>'  : 'provaBMP_10_28_s2b/AIR TX/SystemStatus'
 * '<S15>'  : 'provaBMP_10_28_s2b/AIR TX/VFR'
 * '<S16>'  : 'provaBMP_10_28_s2b/AIR TX/Waypoints'
 * '<S17>'  : 'provaBMP_10_28_s2b/AIR TX/Enable /Chart'
 * '<S18>'  : 'provaBMP_10_28_s2b/AIR TX/Enable /Chart/sendbyte'
 * '<S19>'  : 'provaBMP_10_28_s2b/AIR TX/Heartbeat/Alarm set'
 * '<S20>'  : 'provaBMP_10_28_s2b/AIR TX/If_subsystem/Subsystem'
 * '<S21>'  : 'provaBMP_10_28_s2b/AIR TX/If_subsystem/iflogic_function'
 * '<S22>'  : 'provaBMP_10_28_s2b/AIR TX/Servo/Conversione'
 * '<S23>'  : 'provaBMP_10_28_s2b/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S24>'  : 'provaBMP_10_28_s2b/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S25>'  : 'provaBMP_10_28_s2b/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S26>'  : 'provaBMP_10_28_s2b/AIR TX/Waypoints/MATLAB Function'
 * '<S27>'  : 'provaBMP_10_28_s2b/BMP_280/Dynamic rate limiter'
 * '<S28>'  : 'provaBMP_10_28_s2b/BMP_280/Execution_loop'
 * '<S29>'  : 'provaBMP_10_28_s2b/BMP_280/MATLAB Function'
 * '<S30>'  : 'provaBMP_10_28_s2b/BMP_280/MATLAB Function1'
 * '<S31>'  : 'provaBMP_10_28_s2b/BMP_280/One_time_initialization'
 * '<S32>'  : 'provaBMP_10_28_s2b/BMP_280/Subsystem'
 * '<S33>'  : 'provaBMP_10_28_s2b/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S34>'  : 'provaBMP_10_28_s2b/BMP_280/Subsystem/Subsystem1'
 */
#endif                                 /* RTW_HEADER_provaBMP_10_28_s2b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
