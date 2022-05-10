/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.h
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:27:47 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled1_h_
#define RTW_HEADER_untitled1_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef untitled1_COMMON_INCLUDES_
#define untitled1_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_I2C.h"
#endif                                 /* untitled1_COMMON_INCLUDES_ */

#include "untitled1_types.h"

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

/* Block signals for system '<S20>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S27>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S27>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S27>/I2C Read' */
  int16_T I2CRead9;                    /* '<S27>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S27>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S27>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S27>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S27>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S27>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S27>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S27>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S27>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S27>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S27>/I2C Read12' */
} B_One_time_initialization_unt_T;

/* Block states (default storage) for system '<S20>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S27>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_d;/* '<S27>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_o;/* '<S27>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_ds;/* '<S27>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_f;/* '<S27>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_n;/* '<S27>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_e;/* '<S27>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_nf;/* '<S27>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_l;/* '<S27>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_b;/* '<S27>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_m;/* '<S27>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_ni;/* '<S27>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_i;/* '<S27>/I2C Read' */
  codertarget_arduinobase_int_k_T obj_eu;/* '<S27>/I2C Write3' */
  codertarget_arduinobase_int_k_T obj_p;/* '<S27>/I2C Write2' */
  codertarget_arduinobase_int_k_T obj_nb;/* '<S27>/I2C Write1' */
} DW_One_time_initialization_un_T;

/* Block signals (default storage) */
typedef struct {
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  char_T s1_data[81];
  char_T messaggio_m[80];
  uint8_T messaggio_k[80];             /* '<S32>/Create_message' */
  boolean_T messaggio_c[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S34>/Complex to Real-Imag' */
  real_T DataTypeConversion1_c[9];     /* '<S2>/Data Type Conversion1' */
  uint8_T dataIn[63];
  real32_T ByteUnpack_o2[9];           /* '<S22>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S22>/Byte Reversal' */
  uint8_T b_dataOut[32];
  uint8_T b_dataOut_b[31];
  uint8_T dataIn_p[19];
  uint128m_T r;
  real32_T DataTypeConversion4[4];     /* '<S7>/Data Type Conversion4' */
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  uint64m_T r3;
  uint32_T i2cname;
  real_T Switch;                       /* '<S31>/Switch' */
  real_T UkYk1;                        /* '<S23>/Difference Inputs1' */
  real_T deltafalllimit;               /* '<S23>/delta fall limit' */
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
  real_T scanned1_m;
  real_T scanned2_n;
  real_T b_scanned1_p;
  real_T scanned1_l;
  real_T scanned2_j;
  real_T b_scanned1_d;
  real_T scanned1_g;
  real_T scanned2_l;
  real_T b_scanned1_dh;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_f[2];
  int32_T messaggio_size_g[2];
  int32_T messaggio_size_g1[2];
  int32_T s1_size[2];
  boolean_T mess_type_d[5];
  char_T mess_type[5];
  char_T s1[5];
  real32_T T;                          /* '<S30>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S24>/S-Function Builder' */
  real32_T ByteUnpack_o2_e[4];         /* '<S19>/Byte Unpack' */
  real32_T f;
  int32_T DataTypeConversion1;         /* '<S24>/Data Type  Conversion1' */
  int32_T DataTypeConversion;          /* '<S24>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2;         /* '<S24>/S-Function Builder' */
  uint16_T DataTypeConversion1_l[10];  /* '<S7>/Data Type Conversion1' */
  int32_T b_i;
  int32_T g;
  int32_T eb_data;
  int32_T i;
  int32_T loop_ub;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_o;
  int32_T idx_b;
  int32_T ntoread_n;
  int32_T b_k;
  int32_T kexp;
  int32_T k_b;
  int32_T idx_l;
  int32_T ntoread_h;
  int32_T e_k;
  int32_T kexp_b;
  int32_T idx_d;
  int32_T ntoread_e;
  int32_T d_k;
  int32_T i_b;
  uint32_T DataTypeConversion8;        /* '<S7>/Data Type Conversion8' */
  uint32_T SFunctionBuilder1;          /* '<S24>/S-Function Builder1' */
  uint32_T qY;
  uint16_T ByteUnpack_o4[2];           /* '<S19>/Byte Unpack' */
  int16_T DataTypeConversion_g[9];     /* '<S7>/Data Type Conversion' */
  int16_T ByteUnpack_o3[4];            /* '<S19>/Byte Unpack' */
  uint8_T SFunctionBuilder[41];        /* '<S22>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S22>/Byte Unpack' */
  char_T s1_l[4];
  uint8_T output[3];
  uint8_T ByteUnpack_o3_o;             /* '<S22>/Byte Unpack' */
  uint8_T TmpSignalConversionAtBytePackIn[2];
  uint8_T BytePack[63];                /* '<S7>/Byte Pack' */
  uint8_T indice_dimario;              /* '<S34>/MATLAB Function' */
  uint8_T ByteUnpack_o1_j[2];          /* '<S19>/Byte Unpack' */
  uint8_T ByteUnpack_o5;               /* '<S19>/Byte Unpack' */
  uint8_T messaggio[31];               /* '<S15>/MATLAB Function' */
  B_One_time_initialization_unt_T One_time_initialization;/* '<S20>/One_time_initialization' */
} B_untitled1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_lq_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_in_lq_T obj_a;/* '<S7>/Serial Transmit' */
  codertarget_arduinobase_int_l_T obj_b;/* '<S21>/Serial Receive1' */
  codertarget_arduinobase_int_l_T obj_k;/* '<S7>/Serial Receive' */
  codertarget_arduinobase_inter_T obj_d;/* '<S24>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_n;/* '<S24>/I2C Read1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S22>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S23>/Delay Input2' */
  real_T UnitDelay_DSTATE;             /* '<S16>/Unit Delay' */
  real_T P_ref;                        /* '<S20>/MATLAB Function' */
  real_T rl_up;                        /* '<S20>/MATLAB Function' */
  real_T rl_dw;                        /* '<S20>/MATLAB Function' */
  boolean_T UnitDelay_DSTATE_j;        /* '<S20>/Unit Delay' */
  uint8_T message[80];                 /* '<S32>/Create_message' */
  uint8_T counter;                     /* '<S32>/Create_message' */
  uint8_T message_i[31];               /* '<S15>/MATLAB Function' */
  uint8_T counter_b;                   /* '<S15>/MATLAB Function' */
  boolean_T start_found;               /* '<S32>/Create_message' */
  boolean_T end_found;                 /* '<S32>/Create_message' */
  boolean_T start_found_g;             /* '<S15>/MATLAB Function' */
  DW_One_time_initialization_un_T One_time_initialization;/* '<S20>/One_time_initialization' */
} DW_untitled1_T;

/* Parameters for system: '<S20>/One_time_initialization' */
struct P_One_time_initialization_unt_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S27>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S27>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S27>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S27>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S27>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S27>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S27>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S27>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S27>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S27>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S27>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S27>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S27>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S27>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S27>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S27>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S27>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S27>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_untitled1_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S24>/I2C Read1'
                                        *   '<S24>/I2C Read12'
                                        *   '<S27>/I2C Read'
                                        *   '<S27>/I2C Read1'
                                        *   '<S27>/I2C Read10'
                                        *   '<S27>/I2C Read11'
                                        *   '<S27>/I2C Read2'
                                        *   '<S27>/I2C Read3'
                                        *   '<S27>/I2C Read4'
                                        *   '<S27>/I2C Read5'
                                        *   '<S27>/I2C Read6'
                                        *   '<S27>/I2C Read7'
                                        *   '<S27>/I2C Read8'
                                        *   '<S27>/I2C Read9'
                                        */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<S7>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S7>/Serial Transmit'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S24>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S21>/Serial Receive1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S31>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 2
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Constant3_Value_b;            /* Expression: 3
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S34>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S34>/Memory'
                                        */
  real_T SerialTransmit_Protocol_h;    /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S23>/Delay Input2'
                                        */
  real_T Constant4_Value_d;            /* Expression: 1
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant2_Value_m;            /* Expression: 1
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant3_Value_p;            /* Expression: 101325
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S23>/sample time'
                                        */
  real_T Constant1_Value_p;            /* Expression: 280
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 15
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 100
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T Constant1_Value_pg[3];        /* Expression: zeros(1,3)
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant4_Value_k;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant5_Value_i;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant5'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.01
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Constant_Value_e4;            /* Expression: 62
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: tau
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: pi/180
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S19>/Out2'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S24>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S30>/T_0'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S28>/Switch'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S7>/Gain3'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S24>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S24>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S24>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S24>/Constant11'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S24>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S24>/Constant9'
                                        */
  int16_T Out3_Y0;                     /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S19>/Out3'
                                        */
  uint16_T Out4_Y0;                    /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S19>/Out4'
                                        */
  boolean_T UnitDelay_InitialCondition_o;
                             /* Computed Parameter: UnitDelay_InitialCondition_o
                              * Referenced by: '<S20>/Unit Delay'
                              */
  boolean_T Constant3_Value_o;         /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S20>/Constant3'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S34>/mario'
                                        */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S7>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S7>/Fine MSG1'
                                        */
  P_One_time_initialization_unt_T One_time_initialization;/* '<S20>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled1_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_untitled1_T untitled1_P;

/* Block signals (default storage) */
extern B_untitled1_T untitled1_B;

/* Block states (default storage) */
extern DW_untitled1_T untitled1_DW;

/* Model entry point functions */
extern void untitled1_initialize(void);
extern void untitled1_step(void);
extern void untitled1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled1_T *const untitled1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<S7>/Gain7' : Unused code path elimination
 * Block '<S23>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant5' : Unused code path elimination
 * Block '<S2>/Constant6' : Unused code path elimination
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'untitled1'
 * '<S1>'   : 'untitled1/MISURE DA SENSORI  FILTRATE'
 * '<S2>'   : 'untitled1/Misure Sensori'
 * '<S3>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
 * '<S4>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
 * '<S5>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
 * '<S6>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S7>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry'
 * '<S8>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians'
 * '<S9>'   : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians1'
 * '<S10>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians2'
 * '<S11>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass'
 * '<S12>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees'
 * '<S13>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees1'
 * '<S14>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees2'
 * '<S15>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1'
 * '<S16>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS'
 * '<S17>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS/MATLAB Function'
 * '<S18>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function'
 * '<S19>'  : 'untitled1/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem2'
 * '<S20>'  : 'untitled1/Misure Sensori/BMP_280'
 * '<S21>'  : 'untitled1/Misure Sensori/GPS_Venus'
 * '<S22>'  : 'untitled1/Misure Sensori/MTi'
 * '<S23>'  : 'untitled1/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S24>'  : 'untitled1/Misure Sensori/BMP_280/Execution_loop'
 * '<S25>'  : 'untitled1/Misure Sensori/BMP_280/MATLAB Function'
 * '<S26>'  : 'untitled1/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S27>'  : 'untitled1/Misure Sensori/BMP_280/One_time_initialization'
 * '<S28>'  : 'untitled1/Misure Sensori/BMP_280/Subsystem'
 * '<S29>'  : 'untitled1/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S30>'  : 'untitled1/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S31>'  : 'untitled1/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S32>'  : 'untitled1/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S33>'  : 'untitled1/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S34>'  : 'untitled1/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S35>'  : 'untitled1/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_untitled1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
