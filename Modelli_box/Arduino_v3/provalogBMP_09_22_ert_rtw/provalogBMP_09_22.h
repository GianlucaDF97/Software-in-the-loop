/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provalogBMP_09_22.h
 *
 * Code generated for Simulink model 'provalogBMP_09_22'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 17:33:28 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provalogBMP_09_22_h_
#define RTW_HEADER_provalogBMP_09_22_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef provalogBMP_09_22_COMMON_INCLUDES_
#define provalogBMP_09_22_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_I2C.h"
#endif                                 /* provalogBMP_09_22_COMMON_INCLUDES_ */

#include "provalogBMP_09_22_types.h"
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
  uint16_T ByteUnpack[8];              /* '<S35>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S35>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S35>/I2C Read' */
  int16_T I2CRead9;                    /* '<S35>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S35>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S35>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S35>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S35>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S35>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S35>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S35>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S35>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S35>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S35>/I2C Read12' */
} B_One_time_initialization_pro_T;

/* Block states (default storage) for system '<S3>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S35>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_i;/* '<S35>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_l;/* '<S35>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_j;/* '<S35>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_n;/* '<S35>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_e;/* '<S35>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_ef;/* '<S35>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_k;/* '<S35>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_a;/* '<S35>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S35>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_f;/* '<S35>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_f2;/* '<S35>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_m;/* '<S35>/I2C Read' */
  codertarget_arduinobase_int_a_T obj_o;/* '<S35>/I2C Write3' */
  codertarget_arduinobase_int_a_T obj_fo;/* '<S35>/I2C Write2' */
  codertarget_arduinobase_int_a_T obj_d;/* '<S35>/I2C Write1' */
} DW_One_time_initialization_pr_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T Memory2[300];                /* '<S1>/Memory2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio[100];              /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  uint8_T dataIn[67];
  real_T poss_254[3];
  uint16_T WP_info_in[6];
  uint32_T i2cname;
  real_T num_254;
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Sum2;                         /* '<S26>/Sum2' */
  real_T Sum1;                         /* '<S26>/Sum1' */
  real_T RateTransition;               /* '<S24>/Rate Transition' */
  real_T deltafalllimit;               /* '<S31>/delta fall limit' */
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S13>/Data Type Conversion3' */
  uint32_T onboard[3];                 /* '<S18>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S11>/Data Type Conversion' */
  uint32_T DataTypeConversion9;        /* '<S2>/Data Type Conversion9' */
  uint32_T SFunctionBuilder1;          /* '<S32>/S-Function Builder1' */
  real32_T ByteUnpack_o2[9];           /* '<S4>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S4>/Byte Reversal' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion1[6];     /* '<S12>/Data Type Conversion1' */
  real32_T DataTypeConversion3_e;      /* '<S3>/Data Type Conversion3' */
  real32_T DataTypeConversion3_ei[4];  /* '<S19>/Data Type Conversion3' */
  real32_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_n;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_o;      /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion6[4];     /* '<S2>/Data Type Conversion6' */
  real32_T T;                          /* '<S38>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S32>/S-Function Builder' */
  real32_T WP_param[7];                /* '<S20>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_f[4];     /* '<S10>/Data Type Conversion' */
  int32_T DataTypeConversion1_f;       /* '<S32>/Data Type  Conversion1' */
  int32_T DataTypeConversion_d;        /* '<S32>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_f;       /* '<S32>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T LVDE[8];                    /* '<S18>/Data Type Conversion2' */
  uint16_T DataTypeConversion2;        /* '<S10>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S19>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S17>/Data Type Conversion1' */
  uint16_T Memory_i;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion10;       /* '<S2>/Data Type Conversion10' */
  uint16_T DataTypeConversion11[3];    /* '<S2>/Data Type Conversion11' */
  uint16_T DataTypeConversion12;       /* '<S2>/Data Type Conversion12' */
  uint16_T DataTypeConversion13;       /* '<S2>/Data Type Conversion13' */
  uint16_T DataTypeConversion14;       /* '<S2>/Data Type Conversion14' */
  uint16_T DataTypeConversion15;       /* '<S2>/Data Type Conversion15' */
  uint16_T DataTypeConversion21;       /* '<S2>/Data Type Conversion21' */
  uint16_T DataTypeConversion20;       /* '<S2>/Data Type Conversion20' */
  uint16_T DataTypeConversion19;       /* '<S2>/Data Type Conversion19' */
  uint16_T DataTypeConversion18;       /* '<S2>/Data Type Conversion18' */
  uint16_T WP_info[6];                 /* '<S20>/MATLAB Function' */
  real32_T h_;                         /* '<S3>/MATLAB Function1' */
  int32_T status;
  int32_T caso;
  int32_T f;
  int32_T g;
  int32_T x_m;
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T B_Current;                   /* '<S18>/Data Type Conversion1' */
  int16_T DataTypeConversion_n2[9];    /* '<S12>/Data Type Conversion' */
  int16_T DataTypeConversion1_k[3];    /* '<S10>/Data Type Conversion1' */
  int16_T DataTypeConversion4_g;       /* '<S19>/Data Type Conversion4' */
  int16_T DataTypeConversion2_e;       /* '<S2>/Data Type Conversion2' */
  int16_T DataTypeConversion3_h[9];    /* '<S2>/Data Type Conversion3' */
  uint8_T SFunctionBuilder[41];        /* '<S4>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S4>/Byte Unpack' */
  uint8_T ByteUnpack_o3;               /* '<S4>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1_g[100];  /* '<S1>/S-Function Builder' */
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
  uint8_T DataTypeConversion1_c[4];    /* '<S11>/Data Type Conversion1' */
  uint8_T SFunction_o1_h;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_n[264];         /* '<S2>/S-Function' */
  uint8_T DataTypeConversion8[2];      /* '<S2>/Data Type Conversion8' */
  uint8_T BytePack[67];                /* '<S2>/Byte Pack' */
  uint8_T iflogic;                     /* '<S13>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S18>/Data Type Conversion3' */
  B_One_time_initialization_pro_T One_time_initialization;/* '<S3>/One_time_initialization' */
} B_provalogBMP_09_22_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_f_T obj; /* '<S2>/Serial Transmit1' */
  codertarget_arduinobase_int_f_T obj_n;/* '<S22>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_m;/* '<S32>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_k;/* '<S32>/I2C Read1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S4>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S1>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S31>/Delay Input2' */
  volatile real_T RateTransition_Buffer0;/* '<S24>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S24>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S24>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S24>/Memory2' */
  real_T P_ref;                        /* '<S3>/MATLAB Function' */
  real_T rl_up;                        /* '<S3>/MATLAB Function' */
  real_T rl_dw;                        /* '<S3>/MATLAB Function' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_c[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE;          /* '<S3>/Unit Delay' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_c[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_i[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_i[9];  /* '<S1>/Memory2' */
  uint8_T is_active_c9_provalogBMP_09_22;/* '<S9>/Chart' */
  uint8_T i;                           /* '<S9>/Chart' */
  uint8_T message[100];                /* '<S1>/MATLAB Function4' */
  uint8_T counter_o;                   /* '<S1>/MATLAB Function4' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  DW_One_time_initialization_pr_T One_time_initialization;/* '<S3>/One_time_initialization' */
} DW_provalogBMP_09_22_T;

/* Parameters for system: '<S3>/One_time_initialization' */
struct P_One_time_initialization_pro_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S35>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S35>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S35>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S35>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S35>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S35>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S35>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S35>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S35>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S35>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S35>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S35>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S35>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S35>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S35>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S35>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S35>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S35>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_provalogBMP_09_22_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S32>/I2C Read1'
                                        *   '<S32>/I2C Read12'
                                        *   '<S35>/I2C Read'
                                        *   '<S35>/I2C Read1'
                                        *   '<S35>/I2C Read10'
                                        *   '<S35>/I2C Read11'
                                        *   '<S35>/I2C Read2'
                                        *   '<S35>/I2C Read3'
                                        *   '<S35>/I2C Read4'
                                        *   '<S35>/I2C Read5'
                                        *   '<S35>/I2C Read6'
                                        *   '<S35>/I2C Read7'
                                        *   '<S35>/I2C Read8'
                                        *   '<S35>/I2C Read9'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S22>/Serial Transmit'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S2>/Serial Transmit1'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S32>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S32>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S32>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S32>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S32>/Constant3'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S24>/Rate Transition'
                                          */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: 1
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S24>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S24>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0.02
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S24>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 3
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 1000
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant1_Value_o[2];         /* Expression: [0 0]
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant3_Value_d;            /* Expression: 23
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T Constant2_Value_l;            /* Expression: 10
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: [0 0]
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant3_Value_d1[3];        /* Expression: [0,0,0]
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant1_Value_kl;           /* Expression: 1
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S10>/alt_r'
                                        */
  real_T Gain_Gain_j[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S10>/vel y'
                                        */
  real_T RCSimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S10>/RC Simulated'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Constant4_Value_b;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 100
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S31>/Delay Input2'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 120000
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_kk;           /* Expression: 101000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S31>/sample time'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S19>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S19>/v simulated'
                                        */
  real_T T_0_Value;                    /* Expression: 298
                                        * Referenced by: '<Root>/T_0'
                                        */
  real_T Constant_Value_ot;            /* Expression: 15
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S19>/RC simulated'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 50
                                        * Referenced by: '<S19>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S19>/Rpm simulated'
                                        */
  real_T Constant_Value_n;             /* Expression: 4
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S17>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 100
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S17>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180/pi
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Constant2_Value_lk;           /* Expression: 90
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S17>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S17>/Timone Simulated'
                                        */
  real_T Gain_Gain_bt;                 /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Constant1_Value_o3[3];        /* Expression: zeros(3,1)
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 10000
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 0.01
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_lc;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Constant4_Value_bw;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_h;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant_Value_gd;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant3_Value_m;            /* Expression: 1500
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
  real_T Constant6_Value_d;            /* Expression: 6
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Constant1_Value_j;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant4_Value_j;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant3_Value_g;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value_m;            /* Expression: 0
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T Constant5_Value_d;            /* Expression: 1
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S24>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S24>/Switch1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S32>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S38>/T_0'
                                        */
  real32_T Switch_Threshold_l;         /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S36>/Switch'
                                        */
  real32_T Gain_Gain_g;                /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S14>/Gain'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S16>/Gain'
                                        */
  real32_T Gain_Gain_nw;               /* Computed Parameter: Gain_Gain_nw
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S32>/p'
                                        */
  uint32_T Constant7_Value_f;          /* Computed Parameter: Constant7_Value_f
                                        * Referenced by: '<S32>/Constant7'
                                        */
  uint32_T Constant10_Value_f;         /* Computed Parameter: Constant10_Value_f
                                        * Referenced by: '<S32>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S32>/Constant11'
                                        */
  uint32_T Constant8_Value_e;          /* Computed Parameter: Constant8_Value_e
                                        * Referenced by: '<S32>/Constant8'
                                        */
  uint32_T Constant9_Value_l;          /* Computed Parameter: Constant9_Value_l
                                        * Referenced by: '<S32>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S18>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_l;                /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S18>/Gain1'
                                        */
  int16_T Gain2_Gain_e;                /* Computed Parameter: Gain2_Gain_e
                                        * Referenced by: '<S2>/Gain2'
                                        */
  uint16_T Memory_InitialCondition_l;
                                /* Computed Parameter: Memory_InitialCondition_l
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S18>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S18>/ '
                                        */
  uint16_T Memory_InitialCondition_c;
                                /* Computed Parameter: Memory_InitialCondition_c
                                 * Referenced by: '<S2>/Memory'
                                 */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  boolean_T Constant3_Value_l;         /* Computed Parameter: Constant3_Value_l
                                        * Referenced by: '<S3>/Constant3'
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
  uint8_T Memory1_InitialCondition_j;
                               /* Computed Parameter: Memory1_InitialCondition_j
                                * Referenced by: '<S1>/Memory1'
                                */
  uint8_T Memory_InitialCondition_n;
                                /* Computed Parameter: Memory_InitialCondition_n
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
                           * Referenced by: '<S11>/Type fixed_wing Autopilot generic'
                           */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S2>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S2>/Fine MSG1'
                                        */
  P_One_time_initialization_pro_T One_time_initialization;/* '<S3>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_provalogBMP_09_22_T {
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
extern P_provalogBMP_09_22_T provalogBMP_09_22_P;

/* Block signals (default storage) */
extern B_provalogBMP_09_22_T provalogBMP_09_22_B;

/* Block states (default storage) */
extern DW_provalogBMP_09_22_T provalogBMP_09_22_DW;

/* External data declarations for dependent source files */
extern const uint16_T provalogBMP_09_22_U16GND;/* uint16_T ground */

/* External function called from main */
extern void provalogBMP_09_22_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void provalogBMP_09_22_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void provalogBMP_09_22_initialize(void);
extern void provalogBMP_09_22_step0(void);
extern void provalogBMP_09_22_step1(void);
extern void provalogBMP_09_22_terminate(void);

/* Real-time Model object */
extern RT_MODEL_provalogBMP_09_22_T *const provalogBMP_09_22_M;
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
 * '<Root>' : 'provalogBMP_09_22'
 * '<S1>'   : 'provalogBMP_09_22/AIR RX'
 * '<S2>'   : 'provalogBMP_09_22/AIR TX'
 * '<S3>'   : 'provalogBMP_09_22/BMP_280'
 * '<S4>'   : 'provalogBMP_09_22/MTi'
 * '<S5>'   : 'provalogBMP_09_22/AIR RX/MATLAB Function1'
 * '<S6>'   : 'provalogBMP_09_22/AIR RX/MATLAB Function2'
 * '<S7>'   : 'provalogBMP_09_22/AIR RX/MATLAB Function3'
 * '<S8>'   : 'provalogBMP_09_22/AIR RX/MATLAB Function4'
 * '<S9>'   : 'provalogBMP_09_22/AIR TX/Enable '
 * '<S10>'  : 'provalogBMP_09_22/AIR TX/GPS'
 * '<S11>'  : 'provalogBMP_09_22/AIR TX/Heartbeat'
 * '<S12>'  : 'provalogBMP_09_22/AIR TX/IMU & Attidude'
 * '<S13>'  : 'provalogBMP_09_22/AIR TX/If_subsystem'
 * '<S14>'  : 'provalogBMP_09_22/AIR TX/Radians to Degrees'
 * '<S15>'  : 'provalogBMP_09_22/AIR TX/Radians to Degrees1'
 * '<S16>'  : 'provalogBMP_09_22/AIR TX/Radians to Degrees2'
 * '<S17>'  : 'provalogBMP_09_22/AIR TX/Servo'
 * '<S18>'  : 'provalogBMP_09_22/AIR TX/SystemStatus'
 * '<S19>'  : 'provalogBMP_09_22/AIR TX/VFR'
 * '<S20>'  : 'provalogBMP_09_22/AIR TX/Waypoints'
 * '<S21>'  : 'provalogBMP_09_22/AIR TX/Enable /Chart'
 * '<S22>'  : 'provalogBMP_09_22/AIR TX/Enable /Chart/sendbyte'
 * '<S23>'  : 'provalogBMP_09_22/AIR TX/Heartbeat/Alarm set'
 * '<S24>'  : 'provalogBMP_09_22/AIR TX/If_subsystem/Subsystem'
 * '<S25>'  : 'provalogBMP_09_22/AIR TX/If_subsystem/iflogic_function'
 * '<S26>'  : 'provalogBMP_09_22/AIR TX/Servo/Conversione'
 * '<S27>'  : 'provalogBMP_09_22/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S28>'  : 'provalogBMP_09_22/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S29>'  : 'provalogBMP_09_22/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S30>'  : 'provalogBMP_09_22/AIR TX/Waypoints/MATLAB Function'
 * '<S31>'  : 'provalogBMP_09_22/BMP_280/Dynamic rate limiter'
 * '<S32>'  : 'provalogBMP_09_22/BMP_280/Execution_loop'
 * '<S33>'  : 'provalogBMP_09_22/BMP_280/MATLAB Function'
 * '<S34>'  : 'provalogBMP_09_22/BMP_280/MATLAB Function1'
 * '<S35>'  : 'provalogBMP_09_22/BMP_280/One_time_initialization'
 * '<S36>'  : 'provalogBMP_09_22/BMP_280/Subsystem'
 * '<S37>'  : 'provalogBMP_09_22/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S38>'  : 'provalogBMP_09_22/BMP_280/Subsystem/Subsystem1'
 */
#endif                                 /* RTW_HEADER_provalogBMP_09_22_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
