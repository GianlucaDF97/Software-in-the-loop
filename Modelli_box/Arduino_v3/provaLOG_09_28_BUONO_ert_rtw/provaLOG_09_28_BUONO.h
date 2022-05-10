/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaLOG_09_28_BUONO.h
 *
 * Code generated for Simulink model 'provaLOG_09_28_BUONO'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct  8 18:11:05 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provaLOG_09_28_BUONO_h_
#define RTW_HEADER_provaLOG_09_28_BUONO_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef provaLOG_09_28_BUONO_COMMON_INCLUDES_
#define provaLOG_09_28_BUONO_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_I2C.h"
#endif                               /* provaLOG_09_28_BUONO_COMMON_INCLUDES_ */

#include "provaLOG_09_28_BUONO_types.h"

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

/* Block signals for system '<S3>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S38>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S38>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S38>/I2C Read' */
  int16_T I2CRead9;                    /* '<S38>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S38>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S38>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S38>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S38>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S38>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S38>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S38>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S38>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S38>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S38>/I2C Read12' */
} B_One_time_initialization_pro_T;

/* Block states (default storage) for system '<S3>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S38>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_c;/* '<S38>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_j;/* '<S38>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_g;/* '<S38>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_p;/* '<S38>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_b;/* '<S38>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_l;/* '<S38>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_pb;/* '<S38>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_be;/* '<S38>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_m;/* '<S38>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_g3;/* '<S38>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_h;/* '<S38>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_po;/* '<S38>/I2C Read' */
  codertarget_arduinobase_int_j_T obj_i;/* '<S38>/I2C Write3' */
  codertarget_arduinobase_int_j_T obj_pd;/* '<S38>/I2C Write2' */
  codertarget_arduinobase_int_j_T obj_e;/* '<S38>/I2C Write1' */
} DW_One_time_initialization_pr_T;

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
  uint8_T messaggio_c[80];             /* '<S21>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S23>/Complex to Real-Imag' */
  uint8_T dataIn[67];
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
  uint64m_T r3;
  uint32_T i2cname;
  real_T Switch;                       /* '<S20>/Switch' */
  real_T num_254;
  real_T UkYk1;                        /* '<S34>/Difference Inputs1' */
  real_T deltafalllimit;               /* '<S34>/delta fall limit' */
  real_T PatohPa;                      /* '<S2>/Pa to hPa' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T RateTransition;               /* '<S27>/Rate Transition' */
  real_T Sum1;                         /* '<S29>/Sum1' */
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
  real_T b_scanned1_j;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_k[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_b[2];
  int32_T messaggio_size_p[2];
  int32_T s1_size[2];
  boolean_T mess_type_d[5];
  char_T mess_type[5];
  char_T s1[5];
  real32_T h_;                         /* '<S3>/MATLAB Function1' */
  real32_T f;
  int32_T status;
  int32_T caso;
  int32_T f_l;
  int32_T x_d;
  int32_T eb_data;
  int32_T i;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_d;
  int32_T idx_l;
  int32_T ntoread_o;
  int32_T b_k;
  int32_T kexp;
  int32_T k_b;
  int32_T idx_n;
  int32_T ntoread_b;
  int32_T e_k;
  int32_T kexp_l;
  int32_T idx_h;
  int32_T ntoread_bn;
  int32_T d_k;
  int32_T i_d;
  uint32_T DataTypeConversion3;        /* '<S12>/Data Type Conversion3' */
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T onboard[3];                 /* '<S14>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S10>/Data Type Conversion' */
  uint32_T DataTypeConversion16;       /* '<S2>/Data Type Conversion16' */
  uint32_T SFunctionBuilder1;          /* '<S35>/S-Function Builder1' */
  real32_T ByteUnpack_o2[9];           /* '<S26>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S26>/Byte Reversal' */
  real32_T DataTypeConversion4[6];     /* '<S11>/Data Type Conversion4' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion3_j;      /* '<S3>/Data Type Conversion3' */
  real32_T DataTypeConversion3_a[4];   /* '<S15>/Data Type Conversion3' */
  real32_T DataTypeConversion4_g;      /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_a;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion6[4];     /* '<S2>/Data Type Conversion6' */
  real32_T T;                          /* '<S41>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S35>/S-Function Builder' */
  real32_T WP_param[7];                /* '<S16>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_j[4];     /* '<S9>/Data Type Conversion' */
  int32_T DataTypeConversion1_a;       /* '<S35>/Data Type  Conversion1' */
  int32_T DataTypeConversion_h;        /* '<S35>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_a;       /* '<S35>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T LVDE[8];                    /* '<S14>/Data Type Conversion2' */
  uint16_T Heading[9];                 /* '<S13>/Data Type Conversion1' */
  uint32_T qY;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  char_T s1_g[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2;        /* '<S9>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S15>/Data Type Conversion5' */
  uint16_T Memory_e;                   /* '<S2>/Memory' */
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
  uint16_T WP_info[6];                 /* '<S16>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T DataTypeConversion3_m[9];    /* '<S11>/Data Type Conversion3' */
  int16_T B_Current;                   /* '<S14>/Data Type Conversion1' */
  int16_T DataTypeConversion1_k[3];    /* '<S9>/Data Type Conversion1' */
  int16_T DataTypeConversion4_o;       /* '<S15>/Data Type Conversion4' */
  int16_T DataTypeConversion2_c;       /* '<S2>/Data Type Conversion2' */
  int16_T DataTypeConversion3_p[9];    /* '<S2>/Data Type Conversion3' */
  uint8_T SFunctionBuilder[41];        /* '<S26>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S26>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1_j[100];  /* '<S1>/S-Function Builder' */
  uint16_T z;
  uint16_T x_e;
  uint8_T ByteUnpack_o3;               /* '<S26>/Byte Unpack' */
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
  uint8_T DataTypeConversion1_n[4];    /* '<S10>/Data Type Conversion1' */
  uint8_T SFunction_o1_m;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_n[264];         /* '<S2>/S-Function' */
  uint8_T DataTypeConversion8[2];      /* '<S2>/Data Type Conversion8' */
  uint8_T BytePack[67];                /* '<S2>/Byte Pack' */
  uint8_T iflogic;                     /* '<S12>/iflogic_function' */
  uint8_T indice_dimario;              /* '<S23>/MATLAB Function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S14>/Data Type Conversion3' */
  B_One_time_initialization_pro_T One_time_initialization;/* '<S3>/One_time_initialization' */
} B_provaLOG_09_28_BUONO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_hf_T obj; /* '<S2>/Serial Transmit1' */
  codertarget_arduinobase_in_hf_T obj_j;/* '<S18>/Serial Transmit' */
  codertarget_arduinobase_int_h_T obj_m;/* '<S19>/Serial Receive1' */
  codertarget_arduinobase_inter_T obj_f;/* '<S35>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_d;/* '<S35>/I2C Read1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S26>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_c;    /* '<S1>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S34>/Delay Input2' */
  volatile real_T RateTransition_Buffer0;/* '<S27>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S27>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S27>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S27>/Memory2' */
  real_T P_ref;                        /* '<S3>/MATLAB Function' */
  real_T rl_up;                        /* '<S3>/MATLAB Function' */
  real_T rl_dw;                        /* '<S3>/MATLAB Function' */
  real_T Memory_PreviousInput_i[9];    /* '<S23>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_g[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE;          /* '<S3>/Unit Delay' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_j[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_m[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_c[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S21>/Create_message' */
  uint8_T counter_k;                   /* '<S21>/Create_message' */
  uint8_T is_active_c9_provaLOG_09_28_BUO;/* '<S8>/Chart' */
  uint8_T i;                           /* '<S8>/Chart' */
  uint8_T message_e[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_m;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S21>/Create_message' */
  boolean_T end_found;                 /* '<S21>/Create_message' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  DW_One_time_initialization_pr_T One_time_initialization;/* '<S3>/One_time_initialization' */
} DW_provaLOG_09_28_BUONO_T;

/* Parameters for system: '<S3>/One_time_initialization' */
struct P_One_time_initialization_pro_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S38>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S38>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S38>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S38>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S38>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S38>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S38>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S38>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S38>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S38>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S38>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S38>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S38>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S38>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S38>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S38>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S38>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S38>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_provaLOG_09_28_BUONO_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S35>/I2C Read1'
                                        *   '<S35>/I2C Read12'
                                        *   '<S38>/I2C Read'
                                        *   '<S38>/I2C Read1'
                                        *   '<S38>/I2C Read10'
                                        *   '<S38>/I2C Read11'
                                        *   '<S38>/I2C Read2'
                                        *   '<S38>/I2C Read3'
                                        *   '<S38>/I2C Read4'
                                        *   '<S38>/I2C Read5'
                                        *   '<S38>/I2C Read6'
                                        *   '<S38>/I2C Read7'
                                        *   '<S38>/I2C Read8'
                                        *   '<S38>/I2C Read9'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S18>/Serial Transmit'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S19>/Serial Receive1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S20>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S20>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S23>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S23>/Memory'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S2>/Serial Transmit1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 16
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S35>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S35>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S35>/Constant4'
                                        */
  real_T Constant2_Value_c;            /* Expression: 16
                                        * Referenced by: '<S35>/Constant2'
                                        */
  real_T Constant3_Value_p;            /* Expression: 8
                                        * Referenced by: '<S35>/Constant3'
                                        */
  real_T Constant4_Value_l[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S11>/Constant4'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S27>/Rate Transition'
                                          */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S27>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S27>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0.02
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Memory_InitialCondition_k;    /* Expression: -0.02
                                        * Referenced by: '<S27>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 3
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1000
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: [0 0]
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant3_Value_g;            /* Expression: 23
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T Constant2_Value_g;            /* Expression: 10
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_g[2];         /* Expression: [0 0]
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S9>/alt_r'
                                        */
  real_T Gain_Gain_i[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S9>/Gain'
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
  real_T Gain2_Gain_o;                 /* Expression: 100
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S34>/Delay Input2'
                                        */
  real_T Constant2_Value_gi;           /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_k3;           /* Expression: 102000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S34>/sample time'
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
                                        * Referenced by: '<S39>/Constant'
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
  real_T Constant_Value_c;             /* Expression: 4
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S13>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 100
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S13>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 90
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S13>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S13>/Timone Simulated'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant1_Value_gk[3];        /* Expression: zeros(3,1)
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 10000
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 0.01
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
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
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
  real_T Constant_Value_ez;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1500
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
  real_T Constant6_Value_l;            /* Expression: 6
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant4_Value_d;            /* Expression: 0
                                        * Referenced by: '<S27>/Constant4'
                                        */
  real_T Constant5_Value_k;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S27>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S27>/Switch1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S35>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S41>/T_0'
                                        */
  real32_T Switch_Threshold_l;         /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S39>/Switch'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S35>/p'
                                        */
  uint32_T Constant7_Value_e;          /* Computed Parameter: Constant7_Value_e
                                        * Referenced by: '<S35>/Constant7'
                                        */
  uint32_T Constant10_Value_m;         /* Computed Parameter: Constant10_Value_m
                                        * Referenced by: '<S35>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S35>/Constant11'
                                        */
  uint32_T Constant8_Value_p;          /* Computed Parameter: Constant8_Value_p
                                        * Referenced by: '<S35>/Constant8'
                                        */
  uint32_T Constant9_Value_o;          /* Computed Parameter: Constant9_Value_o
                                        * Referenced by: '<S35>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S14>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S14>/Gain1'
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
                                        * Referenced by: '<S14>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S14>/ '
                                        */
  uint16_T Memory_InitialCondition_d;
                                /* Computed Parameter: Memory_InitialCondition_d
                                 * Referenced by: '<S2>/Memory'
                                 */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  boolean_T Constant3_Value_c;         /* Computed Parameter: Constant3_Value_c
                                        * Referenced by: '<S3>/Constant3'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S23>/mario'
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
                           * Referenced by: '<S10>/Type fixed_wing Autopilot generic'
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
struct tag_RTM_provaLOG_09_28_BUONO_T {
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
extern P_provaLOG_09_28_BUONO_T provaLOG_09_28_BUONO_P;

/* Block signals (default storage) */
extern B_provaLOG_09_28_BUONO_T provaLOG_09_28_BUONO_B;

/* Block states (default storage) */
extern DW_provaLOG_09_28_BUONO_T provaLOG_09_28_BUONO_DW;

/* External data declarations for dependent source files */
extern const uint16_T provaLOG_09_28_BUONO_U16GND;/* uint16_T ground */

/* External function called from main */
extern void provaLOG_09_28_BUONO_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void provaLOG_09_28_BUONO_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void provaLOG_09_28_BUONO_initialize(void);
extern void provaLOG_09_28_BUONO_step0(void);
extern void provaLOG_09_28_BUONO_step1(void);
extern void provaLOG_09_28_BUONO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_provaLOG_09_28_BUONO_T *const provaLOG_09_28_BUONO_M;
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
 * '<Root>' : 'provaLOG_09_28_BUONO'
 * '<S1>'   : 'provaLOG_09_28_BUONO/AIR RX'
 * '<S2>'   : 'provaLOG_09_28_BUONO/AIR TX'
 * '<S3>'   : 'provaLOG_09_28_BUONO/BMP_280'
 * '<S4>'   : 'provaLOG_09_28_BUONO/AIR RX/MATLAB Function1'
 * '<S5>'   : 'provaLOG_09_28_BUONO/AIR RX/MATLAB Function2'
 * '<S6>'   : 'provaLOG_09_28_BUONO/AIR RX/MATLAB Function3'
 * '<S7>'   : 'provaLOG_09_28_BUONO/AIR RX/MATLAB Function4'
 * '<S8>'   : 'provaLOG_09_28_BUONO/AIR TX/Enable '
 * '<S9>'   : 'provaLOG_09_28_BUONO/AIR TX/GPS'
 * '<S10>'  : 'provaLOG_09_28_BUONO/AIR TX/Heartbeat'
 * '<S11>'  : 'provaLOG_09_28_BUONO/AIR TX/IMU & Attidude'
 * '<S12>'  : 'provaLOG_09_28_BUONO/AIR TX/If_subsystem'
 * '<S13>'  : 'provaLOG_09_28_BUONO/AIR TX/Servo'
 * '<S14>'  : 'provaLOG_09_28_BUONO/AIR TX/SystemStatus'
 * '<S15>'  : 'provaLOG_09_28_BUONO/AIR TX/VFR'
 * '<S16>'  : 'provaLOG_09_28_BUONO/AIR TX/Waypoints'
 * '<S17>'  : 'provaLOG_09_28_BUONO/AIR TX/Enable /Chart'
 * '<S18>'  : 'provaLOG_09_28_BUONO/AIR TX/Enable /Chart/sendbyte'
 * '<S19>'  : 'provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus'
 * '<S20>'  : 'provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus/Subsystem1'
 * '<S21>'  : 'provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus/Subsystem2'
 * '<S22>'  : 'provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus/Subsystem2/Create_message'
 * '<S23>'  : 'provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus/Subsystem2/Subsystem'
 * '<S24>'  : 'provaLOG_09_28_BUONO/AIR TX/GPS/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S25>'  : 'provaLOG_09_28_BUONO/AIR TX/Heartbeat/Alarm set'
 * '<S26>'  : 'provaLOG_09_28_BUONO/AIR TX/IMU & Attidude/MTi'
 * '<S27>'  : 'provaLOG_09_28_BUONO/AIR TX/If_subsystem/Subsystem'
 * '<S28>'  : 'provaLOG_09_28_BUONO/AIR TX/If_subsystem/iflogic_function'
 * '<S29>'  : 'provaLOG_09_28_BUONO/AIR TX/Servo/Conversione'
 * '<S30>'  : 'provaLOG_09_28_BUONO/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S31>'  : 'provaLOG_09_28_BUONO/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S32>'  : 'provaLOG_09_28_BUONO/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S33>'  : 'provaLOG_09_28_BUONO/AIR TX/Waypoints/MATLAB Function'
 * '<S34>'  : 'provaLOG_09_28_BUONO/BMP_280/Dynamic rate limiter'
 * '<S35>'  : 'provaLOG_09_28_BUONO/BMP_280/Execution_loop'
 * '<S36>'  : 'provaLOG_09_28_BUONO/BMP_280/MATLAB Function'
 * '<S37>'  : 'provaLOG_09_28_BUONO/BMP_280/MATLAB Function1'
 * '<S38>'  : 'provaLOG_09_28_BUONO/BMP_280/One_time_initialization'
 * '<S39>'  : 'provaLOG_09_28_BUONO/BMP_280/Subsystem'
 * '<S40>'  : 'provaLOG_09_28_BUONO/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S41>'  : 'provaLOG_09_28_BUONO/BMP_280/Subsystem/Subsystem1'
 */
#endif                                 /* RTW_HEADER_provaLOG_09_28_BUONO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
