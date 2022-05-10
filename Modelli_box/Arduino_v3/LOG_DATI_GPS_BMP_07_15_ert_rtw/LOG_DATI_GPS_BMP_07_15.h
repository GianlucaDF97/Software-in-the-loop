/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LOG_DATI_GPS_BMP_07_15.h
 *
 * Code generated for Simulink model 'LOG_DATI_GPS_BMP_07_15'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Jul 19 15:49:29 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LOG_DATI_GPS_BMP_07_15_h_
#define RTW_HEADER_LOG_DATI_GPS_BMP_07_15_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LOG_DATI_GPS_BMP_07_15_COMMON_INCLUDES_
#define LOG_DATI_GPS_BMP_07_15_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_I2C.h"
#endif                             /* LOG_DATI_GPS_BMP_07_15_COMMON_INCLUDES_ */

#include "LOG_DATI_GPS_BMP_07_15_types.h"

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
  uint16_T ByteUnpack[8];              /* '<S36>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S36>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S36>/I2C Read' */
  int16_T I2CRead9;                    /* '<S36>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S36>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S36>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S36>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S36>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S36>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S36>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S36>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S36>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S36>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S36>/I2C Read12' */
} B_One_time_initialization_LOG_T;

/* Block states (default storage) for system '<S3>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S36>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_l;/* '<S36>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_b;/* '<S36>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_m;/* '<S36>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_n;/* '<S36>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_i;/* '<S36>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_o;/* '<S36>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_ba;/* '<S36>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_h;/* '<S36>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S36>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_f;/* '<S36>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_d;/* '<S36>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_n0;/* '<S36>/I2C Read' */
  codertarget_arduinobase_int_k_T obj_ff;/* '<S36>/I2C Write3' */
  codertarget_arduinobase_int_k_T obj_n4;/* '<S36>/I2C Write2' */
  codertarget_arduinobase_int_k_T obj_e;/* '<S36>/I2C Write1' */
} DW_One_time_initialization_LO_T;

/* Block signals (default storage) */
typedef struct {
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T Memory2[300];                /* '<S1>/Memory2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_j[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S5>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S41>/Complex to Real-Imag' */
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
  real_T Switch;                       /* '<S4>/Switch' */
  real_T num_254;
  real_T DataTypeConversion13;         /* '<S2>/Data Type Conversion13' */
  real_T DataTypeConversion12;         /* '<S2>/Data Type Conversion12' */
  real_T DataTypeConversion10;         /* '<S2>/Data Type Conversion10' */
  real_T UkYk1;                        /* '<S32>/Difference Inputs1' */
  real_T RateTransition;               /* '<S25>/Rate Transition' */
  real_T deltafalllimit;               /* '<S32>/delta fall limit' */
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
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T ATT[6];                     /* '<S2>/IMU & Attidude' */
  real32_T DataTypeConversion3_m;      /* '<S3>/Data Type Conversion3' */
  real32_T DataTypeConversion3_p[4];   /* '<S20>/Data Type Conversion3' */
  real32_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_g;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion6[4];     /* '<S2>/Data Type Conversion6' */
  real32_T ByteUnpack_o2[9];           /* '<Root>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<Root>/Byte Reversal' */
  real32_T T;                          /* '<S39>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S33>/S-Function Builder' */
  real32_T WP_param[7];                /* '<S21>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T h_;                         /* '<S3>/MATLAB Function1' */
  real32_T f;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_n[4];     /* '<S11>/Data Type Conversion' */
  int32_T DataTypeConversion1_l;       /* '<S33>/Data Type  Conversion1' */
  int32_T DataTypeConversion_p;        /* '<S33>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_i;       /* '<S33>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T LVDE[8];                    /* '<S19>/Data Type Conversion2' */
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
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S14>/Data Type Conversion3' */
  uint32_T onboard[3];                 /* '<S19>/Data Type Conversion' */
  uint32_T DataTypeConversion;         /* '<S12>/Data Type Conversion' */
  uint32_T DataTypeConversion9;        /* '<S2>/Data Type Conversion9' */
  uint32_T SFunctionBuilder1;          /* '<S33>/S-Function Builder1' */
  uint32_T qY;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  char_T s1_g[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2;        /* '<S11>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S20>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S18>/Data Type Conversion1' */
  uint16_T Memory_n;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion5_f[12];  /* '<S2>/Data Type Conversion5' */
  uint16_T WP_info[6];                 /* '<S21>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T B_Current;                   /* '<S19>/Data Type Conversion1' */
  int16_T IMU[9];                      /* '<S2>/IMU & Attidude' */
  int16_T DataTypeConversion1_h[3];    /* '<S11>/Data Type Conversion1' */
  int16_T DataTypeConversion4_h;       /* '<S20>/Data Type Conversion4' */
  int16_T DataTypeConversion2_d;       /* '<S2>/Data Type Conversion2' */
  int16_T TmpRTBAtBytePackInport3[9];
  uint8_T SFunctionBuilder_o1_e[100];  /* '<S1>/S-Function Builder' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint16_T z;
  uint16_T x_e;
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_k[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o3_f;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_j[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T DataTypeConversion1_hk[4];   /* '<S12>/Data Type Conversion1' */
  uint8_T SFunction_o1_g;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_b[264];         /* '<S2>/S-Function' */
  uint8_T DataTypeConversion8[2];      /* '<S2>/Data Type Conversion8' */
  uint8_T BytePack[67];                /* '<S2>/Byte Pack' */
  uint8_T SFunctionBuilder[41];        /* '<Root>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<Root>/Byte Unpack' */
  uint8_T ByteUnpack_o3;               /* '<Root>/Byte Unpack' */
  uint8_T iflogic;                     /* '<S14>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S19>/Data Type Conversion3' */
  B_One_time_initialization_LOG_T One_time_initialization;/* '<S3>/One_time_initialization' */
} B_LOG_DATI_GPS_BMP_07_15_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_oo_T obj; /* '<S2>/Serial Transmit1' */
  codertarget_arduinobase_in_oo_T obj_a;/* '<S23>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_d;/* '<S33>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_i;/* '<S33>/I2C Read1' */
  codertarget_arduinobase_int_o_T obj_l;/* '<Root>/Serial Receive1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S32>/Delay Input2' */
  real_T SFunctionBuilder_DSTATE_h;    /* '<Root>/S-Function Builder' */
  volatile real_T RateTransition_Buffer0;/* '<S25>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S25>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S25>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S25>/Memory2' */
  real_T Memory_PreviousInput_g[9];    /* '<S41>/Memory' */
  real_T P_ref;                        /* '<S3>/MATLAB Function' */
  real_T rl_up;                        /* '<S3>/MATLAB Function' */
  real_T rl_dw;                        /* '<S3>/MATLAB Function' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T ATT_Buffer0[6];             /* synthesized block */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int16_T IMU_Buffer0[9];              /* synthesized block */
  int16_T TmpRTBAtBytePackInport3_Buffer0[9];/* synthesized block */
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
  uint8_T message[80];                 /* '<S5>/Create_message' */
  uint8_T counter_c;                   /* '<S5>/Create_message' */
  uint8_T is_active_c9_LOG_DATI_GPS_BMP_0;/* '<S10>/Chart' */
  uint8_T i;                           /* '<S10>/Chart' */
  uint8_T message_l[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_b;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S5>/Create_message' */
  boolean_T end_found;                 /* '<S5>/Create_message' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  DW_One_time_initialization_LO_T One_time_initialization;/* '<S3>/One_time_initialization' */
} DW_LOG_DATI_GPS_BMP_07_15_T;

/* Parameters for system: '<S3>/One_time_initialization' */
struct P_One_time_initialization_LOG_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S36>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S36>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S36>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S36>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S36>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S36>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S36>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S36>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S36>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S36>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S36>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S36>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S36>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S36>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S36>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S36>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S36>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S36>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_LOG_DATI_GPS_BMP_07_15_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S33>/I2C Read1'
                                        *   '<S33>/I2C Read12'
                                        *   '<S36>/I2C Read'
                                        *   '<S36>/I2C Read1'
                                        *   '<S36>/I2C Read10'
                                        *   '<S36>/I2C Read11'
                                        *   '<S36>/I2C Read2'
                                        *   '<S36>/I2C Read3'
                                        *   '<S36>/I2C Read4'
                                        *   '<S36>/I2C Read5'
                                        *   '<S36>/I2C Read6'
                                        *   '<S36>/I2C Read7'
                                        *   '<S36>/I2C Read8'
                                        *   '<S36>/I2C Read9'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S23>/Serial Transmit'
                                        */
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S2>/Serial Transmit1'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S33>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S33>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S33>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S33>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S4>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 2
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant3_Value_d;            /* Expression: 3
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S41>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S41>/Memory'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S25>/Rate Transition'
                                          */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T Constant3_Value_b;            /* Expression: 1
                                        * Referenced by: '<S25>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S25>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S25>/Switch'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0.02
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T Memory_InitialCondition_g;    /* Expression: -0.02
                                        * Referenced by: '<S25>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 3
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1000
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: [0 0]
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant3_Value_c;            /* Expression: 23
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Constant2_Value_g;            /* Expression: 10
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: [0 0]
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S11>/alt_r'
                                        */
  real_T Gain_Gain_h[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S11>/vel y'
                                        */
  real_T RCSimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S11>/RC Simulated'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S32>/Delay Input2'
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
                                        * Referenced by: '<S32>/sample time'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S20>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S20>/v simulated'
                                        */
  real_T T_0_Value;                    /* Expression: 298
                                        * Referenced by: '<Root>/T_0'
                                        */
  real_T Constant_Value_o;             /* Expression: 15
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S20>/RC simulated'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 50
                                        * Referenced by: '<S20>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S20>/Rpm simulated'
                                        */
  real_T Constant_Value_p;             /* Expression: 4
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S18>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 100
                                        * Referenced by: '<S27>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S18>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180/pi
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Constant2_Value_gt;           /* Expression: 90
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S18>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_h4;                 /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S18>/Timone Simulated'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Constant1_Value_c[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 10000
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0.01
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S18>/Saturation'
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
  real_T Constant4_Value_b;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_a;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant_Value_ja;            /* Expression: 1500
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant3_Value_n;            /* Expression: 1500
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
  real_T Constant6_Value_i;            /* Expression: 6
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Constant1_Value_px;           /* Expression: 1500
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant11_Value;             /* Expression: 46
                                        * Referenced by: '<S2>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 67
                                        * Referenced by: '<S2>/Constant12'
                                        */
  real_T Constant4_Value_n;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant4'
                                        */
  real_T Constant5_Value_d;            /* Expression: 1
                                        * Referenced by: '<S25>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S25>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S25>/Switch1'
                                        */
  real_T Constant3_Value_e[3];         /* Expression: [0,0,0]
                                        * Referenced by: '<S13>/Constant3'
                                        */
  int32_T Constant_Value_jl;           /* Computed Parameter: Constant_Value_jl
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S33>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S39>/T_0'
                                        */
  real32_T Switch_Threshold_c;         /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S37>/Switch'
                                        */
  real32_T ATT_InitialCondition;     /* Computed Parameter: ATT_InitialCondition
                                      * Referenced by: synthesized block
                                      */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real32_T Gain_Gain_cw;               /* Computed Parameter: Gain_Gain_cw
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T Gain_Gain_mu;               /* Computed Parameter: Gain_Gain_mu
                                        * Referenced by: '<S16>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S17>/Gain'
                                        */
  real32_T Gain_Gain_mk;               /* Computed Parameter: Gain_Gain_mk
                                        * Referenced by: '<S2>/Gain'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S33>/p'
                                        */
  uint32_T Constant7_Value_h;          /* Computed Parameter: Constant7_Value_h
                                        * Referenced by: '<S33>/Constant7'
                                        */
  uint32_T Constant10_Value_i;         /* Computed Parameter: Constant10_Value_i
                                        * Referenced by: '<S33>/Constant10'
                                        */
  uint32_T Constant11_Value_c;         /* Computed Parameter: Constant11_Value_c
                                        * Referenced by: '<S33>/Constant11'
                                        */
  uint32_T Constant8_Value_k;          /* Computed Parameter: Constant8_Value_k
                                        * Referenced by: '<S33>/Constant8'
                                        */
  uint32_T Constant9_Value_d;          /* Computed Parameter: Constant9_Value_d
                                        * Referenced by: '<S33>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S19>/onboard_control_sensor_present uint32'
                           */
  int16_T IMU_InitialCondition;      /* Computed Parameter: IMU_InitialCondition
                                      * Referenced by: synthesized block
                                      */
  int16_T TmpRTBAtBytePackInport3_Initial;
                          /* Computed Parameter: TmpRTBAtBytePackInport3_Initial
                           * Referenced by: synthesized block
                           */
  int16_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S19>/Gain1'
                                        */
  int16_T Gain2_Gain_l;                /* Computed Parameter: Gain2_Gain_l
                                        * Referenced by: '<S2>/Gain2'
                                        */
  uint16_T Memory_InitialCondition_o;
                                /* Computed Parameter: Memory_InitialCondition_o
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S19>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S19>/ '
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
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S41>/mario'
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
  uint8_T Memory_InitialCondition_gh;
                               /* Computed Parameter: Memory_InitialCondition_gh
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
                           * Referenced by: '<S12>/Type fixed_wing Autopilot generic'
                           */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S2>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S2>/Fine MSG1'
                                        */
  P_One_time_initialization_LOG_T One_time_initialization;/* '<S3>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_LOG_DATI_GPS_BMP_07_1_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_LOG_DATI_GPS_BMP_07_15_T LOG_DATI_GPS_BMP_07_15_P;

/* Block signals (default storage) */
extern B_LOG_DATI_GPS_BMP_07_15_T LOG_DATI_GPS_BMP_07_15_B;

/* Block states (default storage) */
extern DW_LOG_DATI_GPS_BMP_07_15_T LOG_DATI_GPS_BMP_07_15_DW;

/* External data declarations for dependent source files */
extern const uint16_T LOG_DATI_GPS_BMP_07_15_U16GND;/* uint16_T ground */

/* External function called from main */
extern void LOG_DATI_GPS_BMP_07_15_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void LOG_DATI_GPS_BMP_07_15_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void LOG_DATI_GPS_BMP_07_15_initialize(void);
extern void LOG_DATI_GPS_BMP_07_15_step0(void);
extern void LOG_DATI_GPS_BMP_07_15_step1(void);
extern void LOG_DATI_GPS_BMP_07_15_step2(void);
extern void LOG_DATI_GPS_BMP_07_15_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LOG_DATI_GPS_BMP_07__T *const LOG_DATI_GPS_BMP_07_15_M;
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
 * '<Root>' : 'LOG_DATI_GPS_BMP_07_15'
 * '<S1>'   : 'LOG_DATI_GPS_BMP_07_15/AIR RX'
 * '<S2>'   : 'LOG_DATI_GPS_BMP_07_15/AIR TX'
 * '<S3>'   : 'LOG_DATI_GPS_BMP_07_15/BMP_280'
 * '<S4>'   : 'LOG_DATI_GPS_BMP_07_15/Subsystem1'
 * '<S5>'   : 'LOG_DATI_GPS_BMP_07_15/Subsystem2'
 * '<S6>'   : 'LOG_DATI_GPS_BMP_07_15/AIR RX/MATLAB Function1'
 * '<S7>'   : 'LOG_DATI_GPS_BMP_07_15/AIR RX/MATLAB Function2'
 * '<S8>'   : 'LOG_DATI_GPS_BMP_07_15/AIR RX/MATLAB Function3'
 * '<S9>'   : 'LOG_DATI_GPS_BMP_07_15/AIR RX/MATLAB Function4'
 * '<S10>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Enable '
 * '<S11>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/GPS'
 * '<S12>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Heartbeat'
 * '<S13>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/IMU & Attidude'
 * '<S14>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/If_subsystem'
 * '<S15>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Radians to Degrees'
 * '<S16>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Radians to Degrees1'
 * '<S17>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Radians to Degrees2'
 * '<S18>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Servo'
 * '<S19>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/SystemStatus'
 * '<S20>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/VFR'
 * '<S21>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Waypoints'
 * '<S22>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Enable /Chart'
 * '<S23>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Enable /Chart/sendbyte'
 * '<S24>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Heartbeat/Alarm set'
 * '<S25>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/If_subsystem/Subsystem'
 * '<S26>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/If_subsystem/iflogic_function'
 * '<S27>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Servo/Conversione'
 * '<S28>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S29>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S30>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S31>'  : 'LOG_DATI_GPS_BMP_07_15/AIR TX/Waypoints/MATLAB Function'
 * '<S32>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/Dynamic rate limiter'
 * '<S33>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/Execution_loop'
 * '<S34>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/MATLAB Function'
 * '<S35>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/MATLAB Function1'
 * '<S36>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/One_time_initialization'
 * '<S37>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/Subsystem'
 * '<S38>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S39>'  : 'LOG_DATI_GPS_BMP_07_15/BMP_280/Subsystem/Subsystem1'
 * '<S40>'  : 'LOG_DATI_GPS_BMP_07_15/Subsystem2/Create_message'
 * '<S41>'  : 'LOG_DATI_GPS_BMP_07_15/Subsystem2/Subsystem'
 * '<S42>'  : 'LOG_DATI_GPS_BMP_07_15/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                /* RTW_HEADER_LOG_DATI_GPS_BMP_07_15_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
