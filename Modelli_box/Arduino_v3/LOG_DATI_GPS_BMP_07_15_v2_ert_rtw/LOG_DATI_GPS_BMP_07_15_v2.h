/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LOG_DATI_GPS_BMP_07_15_v2.h
 *
 * Code generated for Simulink model 'LOG_DATI_GPS_BMP_07_15_v2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 18:15:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LOG_DATI_GPS_BMP_07_15_v2_h_
#define RTW_HEADER_LOG_DATI_GPS_BMP_07_15_v2_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LOG_DATI_GPS_BMP_07_15_v2_COMMON_INCLUDES_
#define LOG_DATI_GPS_BMP_07_15_v2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_I2C.h"
#endif                          /* LOG_DATI_GPS_BMP_07_15_v2_COMMON_INCLUDES_ */

#include "LOG_DATI_GPS_BMP_07_15_v2_types.h"
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
  uint16_T ByteUnpack[8];              /* '<S33>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S33>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S33>/I2C Read' */
  int16_T I2CRead9;                    /* '<S33>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S33>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S33>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S33>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S33>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S33>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S33>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S33>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S33>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S33>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S33>/I2C Read12' */
} B_One_time_initialization_LOG_T;

/* Block states (default storage) for system '<S3>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S33>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_p;/* '<S33>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_c;/* '<S33>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_g;/* '<S33>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_i;/* '<S33>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_f;/* '<S33>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_o;/* '<S33>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_h;/* '<S33>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_e;/* '<S33>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_a;/* '<S33>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_m;/* '<S33>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_b;/* '<S33>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_oc;/* '<S33>/I2C Read' */
  codertarget_arduinobase_int_p_T obj_hv;/* '<S33>/I2C Write3' */
  codertarget_arduinobase_int_p_T obj_i2;/* '<S33>/I2C Write2' */
  codertarget_arduinobase_int_p_T obj_es;/* '<S33>/I2C Write1' */
} DW_One_time_initialization_LO_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio[100];              /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  real_T poss_254[3];
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T WP_info_in[6];
  uint32_T i2cname;
  real_T num_254;
  real_T PatohPa1;                     /* '<S2>/Pa to hPa1' */
  real_T Sum2;                         /* '<S24>/Sum2' */
  real_T Sum1;                         /* '<S24>/Sum1' */
  real_T deltafalllimit;               /* '<S29>/delta fall limit' */
  real_T RateTransition;               /* '<S22>/Rate Transition' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T TmpRTBAtSFunctionInport15[6];/* '<S2>/IMU & Attidude' */
  real32_T DataTypeConversion3_l[4];   /* '<S15>/Data Type Conversion3' */
  real32_T DataTypeConversion3_n;      /* '<S2>/Data Type Conversion3' */
  real32_T DataTypeConversion_p;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S2>/Data Type Conversion1' */
  real32_T ByteUnpack_o2[9];           /* '<Root>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<Root>/Byte Reversal' */
  real32_T SFunctionBuilder_o1;        /* '<S30>/S-Function Builder' */
  real32_T WP_param[7];                /* '<S16>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T T_0;                        /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_d[4];     /* '<S9>/Data Type Conversion' */
  int32_T DataTypeConversion1_k;       /* '<S30>/Data Type  Conversion1' */
  int32_T DataTypeConversion_e;        /* '<S30>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_i;       /* '<S30>/S-Function Builder' */
  int32_T status;
  int32_T caso;
  int32_T f;
  int32_T g;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S12>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S10>/Data Type Conversion' */
  uint32_T SFunctionBuilder1;          /* '<S30>/S-Function Builder1' */
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  uint16_T DataTypeConversion2;        /* '<S9>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S15>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S13>/Data Type Conversion1' */
  uint16_T Memory_p;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T WP_info[6];                 /* '<S16>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T Gain1;                       /* '<S14>/Gain1' */
  int16_T TmpRTBAtSFunctionInport14[9];/* '<S2>/IMU & Attidude' */
  int16_T DataTypeConversion1_d[3];    /* '<S9>/Data Type Conversion1' */
  int16_T DataTypeConversion4;         /* '<S15>/Data Type Conversion4' */
  int16_T DataTypeConversion2_h;       /* '<S2>/Data Type Conversion2' */
  uint8_T SFunctionBuilder_o1_e[100];  /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_o[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_d;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_e[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T TmpSignalConversionAtSFunctio_m[4];/* '<S2>/Heartbeat' */
  uint8_T SFunction_o1_e;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_g[264];         /* '<S2>/S-Function' */
  uint8_T SFunctionBuilder[41];        /* '<Root>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<Root>/Byte Unpack' */
  uint8_T ByteUnpack_o3;               /* '<Root>/Byte Unpack' */
  uint8_T iflogic;                     /* '<S12>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S14>/Data Type Conversion3' */
  B_One_time_initialization_LOG_T One_time_initialization;/* '<S3>/One_time_initialization' */
} B_LOG_DATI_GPS_BMP_07_15_v2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_j_T obj; /* '<S18>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_f;/* '<S30>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_k;/* '<S30>/I2C Read1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S29>/Delay Input2' */
  real_T SFunctionBuilder_DSTATE_o;    /* '<Root>/S-Function Builder' */
  volatile real_T RateTransition_Buffer0;/* '<S22>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S22>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S22>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S22>/Memory2' */
  real_T P_ref;                        /* '<S3>/MATLAB Function' */
  real_T rl_up;                        /* '<S3>/MATLAB Function' */
  real_T rl_dw;                        /* '<S3>/MATLAB Function' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real32_T TmpRTBAtSFunctionInport15_Buffe[6];/* synthesized block */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  int16_T TmpRTBAtSFunctionInport14_Buffe[9];/* synthesized block */
  uint16_T Memory_PreviousInput_o[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_m;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE;          /* '<S3>/Unit Delay' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_e[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_i[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_k[9];  /* '<S1>/Memory2' */
  uint8_T is_active_c9_LOG_DATI_GPS_BMP_0;/* '<S8>/Chart' */
  uint8_T i;                           /* '<S8>/Chart' */
  uint8_T message[100];                /* '<S1>/MATLAB Function4' */
  uint8_T counter_e;                   /* '<S1>/MATLAB Function4' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  DW_One_time_initialization_LO_T One_time_initialization;/* '<S3>/One_time_initialization' */
} DW_LOG_DATI_GPS_BMP_07_15_v2_T;

/* Parameters for system: '<S3>/One_time_initialization' */
struct P_One_time_initialization_LOG_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S33>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S33>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S33>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S33>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S33>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S33>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S33>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S33>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S33>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S33>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S33>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S33>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S33>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S33>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S33>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S33>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S33>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S33>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_LOG_DATI_GPS_BMP_07_15_v2_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S30>/I2C Read1'
                                        *   '<S30>/I2C Read12'
                                        *   '<S33>/I2C Read'
                                        *   '<S33>/I2C Read1'
                                        *   '<S33>/I2C Read10'
                                        *   '<S33>/I2C Read11'
                                        *   '<S33>/I2C Read2'
                                        *   '<S33>/I2C Read3'
                                        *   '<S33>/I2C Read4'
                                        *   '<S33>/I2C Read5'
                                        *   '<S33>/I2C Read6'
                                        *   '<S33>/I2C Read7'
                                        *   '<S33>/I2C Read8'
                                        *   '<S33>/I2C Read9'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S18>/Serial Transmit'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S30>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S30>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S22>/Rate Transition'
                                          */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 1
                                        * Referenced by: '<S22>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S22>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S22>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0.02
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S22>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 3
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1000
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant1_Value_m[2];         /* Expression: [0 0]
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant3_Value_b;            /* Expression: 23
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T Constant4_Value_d;            /* Expression: 10
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T Constant_Value_oq;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_id[2];        /* Expression: [0 0]
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T LatSimulated_Value;           /* Expression: 41*pi/180
                                        * Referenced by: '<S9>/Lat Simulated'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T LongSimulated_Value;          /* Expression: 12*pi/180
                                        * Referenced by: '<S9>/Long Simulated'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 180/pi
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T AltSimulated_Value;           /* Expression: 100
                                        * Referenced by: '<S9>/Alt Simulated'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S9>/alt_r'
                                        */
  real_T Gain_Gain_od[4];              /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T vSimulated1_Value;            /* Expression: 20
                                        * Referenced by: '<S9>/v Simulated1'
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
  real_T Headingsimulated_Value;       /* Expression: 20
                                        * Referenced by: '<S9>/Heading simulated'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 100
                                        * Referenced by: '<S9>/Gain2'
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
  real_T Constant_Value_g;             /* Expression: 15
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S29>/Delay Input2'
                                        */
  real_T Constant_Value_l;             /* Expression: 120000
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_ma;           /* Expression: 101000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S29>/sample time'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S15>/RC simulated'
                                        */
  real_T Headingsimulated_Value_f;     /* Expression: 50
                                        * Referenced by: '<S15>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S15>/Rpm simulated'
                                        */
  real_T Constant_Value_a;             /* Expression: 4
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S13>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 100
                                        * Referenced by: '<S24>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S13>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Constant2_Value_g;            /* Expression: 90
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S13>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_j2;                 /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S13>/Timone Simulated'
                                        */
  real_T Gain_Gain_oo;                 /* Expression: 180/pi
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Constant1_Value_k[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 10000
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 0.01
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Constant1_Value_mk;           /* Expression: 1013
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant6_Value_i;            /* Expression: 101325
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Constant3_Value_k;            /* Expression: 298
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant4_Value_e;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_e;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant4_Value_f;            /* Expression: 0
                                        * Referenced by: '<S22>/Constant4'
                                        */
  real_T Constant5_Value_f;            /* Expression: 1
                                        * Referenced by: '<S22>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S22>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S22>/Switch1'
                                        */
  real_T Constant_Value_oo[3];         /* Expression: [0,0,0]
                                        * Referenced by: '<S11>/Constant'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S30>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S36>/T_0'
                                        */
  real32_T Switch_Threshold_d;         /* Computed Parameter: Switch_Threshold_d
                                        * Referenced by: '<S34>/Switch'
                                        */
  real32_T TmpRTBAtSFunctionInport15_Initi;
                          /* Computed Parameter: TmpRTBAtSFunctionInport15_Initi
                           * Referenced by: synthesized block
                           */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S30>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S30>/Constant7'
                                        */
  uint32_T Constant10_Value_b;         /* Computed Parameter: Constant10_Value_b
                                        * Referenced by: '<S30>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S30>/Constant11'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S30>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S30>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S14>/onboard_control_sensor_present uint32'
                           */
  int16_T TmpRTBAtSFunctionInport14_Initi;
                          /* Computed Parameter: TmpRTBAtSFunctionInport14_Initi
                           * Referenced by: synthesized block
                           */
  int16_T Gain1_Gain_p;                /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S14>/Gain1'
                                        */
  uint16_T Memory_InitialCondition_b;
                                /* Computed Parameter: Memory_InitialCondition_b
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S14>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S14>/ '
                                        */
  uint16_T Memory_InitialCondition_k;
                                /* Computed Parameter: Memory_InitialCondition_k
                                 * Referenced by: '<S2>/Memory'
                                 */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  boolean_T Constant3_Value_o;         /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S3>/Constant3'
                                        */
  uint8_T Memory4_InitialCondition[300];/* Expression: uint8(zeros(3,100))
                                         * Referenced by: '<S1>/Memory4'
                                         */
  uint8_T Constant1_Value_f;           /* Computed Parameter: Constant1_Value_f
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
  uint8_T Memory_InitialCondition_bh;
                               /* Computed Parameter: Memory_InitialCondition_bh
                                * Referenced by: '<Root>/Memory'
                                */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory2_InitialCondition_c[9];
                               /* Computed Parameter: Memory2_InitialCondition_c
                                * Referenced by: '<S1>/Memory2'
                                */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S10>/Type fixed_wing Autopilot generic'
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
extern P_LOG_DATI_GPS_BMP_07_15_v2_T LOG_DATI_GPS_BMP_07_15_v2_P;

/* Block signals (default storage) */
extern B_LOG_DATI_GPS_BMP_07_15_v2_T LOG_DATI_GPS_BMP_07_15_v2_B;

/* Block states (default storage) */
extern DW_LOG_DATI_GPS_BMP_07_15_v2_T LOG_DATI_GPS_BMP_07_15_v2_DW;

/* External data declarations for dependent source files */
extern const uint16_T LOG_DATI_GPS_BMP_07_15_v2_U16GND;/* uint16_T ground */

/* External function called from main */
extern void LOG_DATI_GPS_BMP_07_15_v2_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void LOG_DATI_GPS_BMP_07_15_v2_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void LOG_DATI_GPS_BMP_07_15_v2_initialize(void);
extern void LOG_DATI_GPS_BMP_07_15_v2_step0(void);
extern void LOG_DATI_GPS_BMP_07_15_v2_step1(void);
extern void LOG_DATI_GPS_BMP_07_15_v2_step2(void);
extern void LOG_DATI_GPS_BMP_07_15_v2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LOG_DATI_GPS_BMP_07__T *const LOG_DATI_GPS_BMP_07_15_v2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Tversion' : Unused code path elimination
 * Block '<S1>/Data Tversion1' : Unused code path elimination
 * Block '<S1>/Data Tversion2' : Unused code path elimination
 * Block '<S29>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'LOG_DATI_GPS_BMP_07_15_v2'
 * '<S1>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR RX'
 * '<S2>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX'
 * '<S3>'   : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280'
 * '<S4>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR RX/MATLAB Function1'
 * '<S5>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR RX/MATLAB Function2'
 * '<S6>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR RX/MATLAB Function3'
 * '<S7>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR RX/MATLAB Function4'
 * '<S8>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Enable '
 * '<S9>'   : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/GPS'
 * '<S10>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Heartbeat'
 * '<S11>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/IMU & Attidude'
 * '<S12>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/If_subsystem'
 * '<S13>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Servo'
 * '<S14>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/SystemStatus'
 * '<S15>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/VFR'
 * '<S16>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Waypoints'
 * '<S17>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Enable /Chart'
 * '<S18>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Enable /Chart/sendbyte'
 * '<S19>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/GPS/Radians to Degrees'
 * '<S20>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/GPS/Radians to Degrees1'
 * '<S21>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Heartbeat/Alarm set'
 * '<S22>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/If_subsystem/Subsystem'
 * '<S23>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/If_subsystem/iflogic_function'
 * '<S24>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Servo/Conversione'
 * '<S25>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S26>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S27>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S28>'  : 'LOG_DATI_GPS_BMP_07_15_v2/AIR TX/Waypoints/MATLAB Function'
 * '<S29>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/Dynamic rate limiter'
 * '<S30>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/Execution_loop'
 * '<S31>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/MATLAB Function'
 * '<S32>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/MATLAB Function1'
 * '<S33>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/One_time_initialization'
 * '<S34>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/Subsystem'
 * '<S35>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S36>'  : 'LOG_DATI_GPS_BMP_07_15_v2/BMP_280/Subsystem/Subsystem1'
 */
#endif                             /* RTW_HEADER_LOG_DATI_GPS_BMP_07_15_v2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
