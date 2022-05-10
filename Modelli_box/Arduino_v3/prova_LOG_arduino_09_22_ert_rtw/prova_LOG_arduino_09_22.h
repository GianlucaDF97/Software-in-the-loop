/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_arduino_09_22.h
 *
 * Code generated for Simulink model 'prova_LOG_arduino_09_22'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 16:59:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prova_LOG_arduino_09_22_h_
#define RTW_HEADER_prova_LOG_arduino_09_22_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef prova_LOG_arduino_09_22_COMMON_INCLUDES_
#define prova_LOG_arduino_09_22_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                            /* prova_LOG_arduino_09_22_COMMON_INCLUDES_ */

#include "prova_LOG_arduino_09_22_types.h"

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

/* Block signals for system '<S1>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S11>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S11>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S11>/I2C Read' */
  int16_T I2CRead9;                    /* '<S11>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S11>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S11>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S11>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S11>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S11>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S11>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S11>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S11>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S11>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S11>/I2C Read12' */
} B_One_time_initialization_pro_T;

/* Block states (default storage) for system '<S1>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S11>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_k;/* '<S11>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_b;/* '<S11>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_l;/* '<S11>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_bu;/* '<S11>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_m;/* '<S11>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_n;/* '<S11>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_c;/* '<S11>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_o;/* '<S11>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_j;/* '<S11>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_cb;/* '<S11>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_jx;/* '<S11>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_ny;/* '<S11>/I2C Read' */
  codertarget_arduinobase_int_l_T obj_js;/* '<S11>/I2C Write3' */
  codertarget_arduinobase_int_l_T obj_a;/* '<S11>/I2C Write2' */
  codertarget_arduinobase_int_l_T obj_bh;/* '<S11>/I2C Write1' */
} DW_One_time_initialization_pr_T;

/* Block signals (default storage) */
typedef struct {
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S16>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S18>/Complex to Real-Imag' */
  uint8_T dataIn[63];
  uint8_T b_dataOut[32];
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint64m_T a;
  uint64m_T p16;
  uint64m_T sk;
  uint64m_T r3;
  uint32_T i2cname;
  real_T Switch;                       /* '<S15>/Switch' */
  real_T rtb_Lat_re;
  real_T rtb_Long_re;
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
  real32_T f;
  int32_T DataTypeConversion1;         /* '<S8>/Data Type  Conversion1' */
  int32_T DataTypeConversion;          /* '<S8>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2;         /* '<S8>/S-Function Builder' */
  uint16_T DataTypeConversion2[10];    /* '<Root>/Data Type Conversion2' */
  int16_T DataTypeConversion1_o[9];    /* '<Root>/Data Type Conversion1' */
  uint8_T SFunctionBuilder[41];        /* '<S3>/S-Function Builder' */
  int32_T b_i;
  int32_T eb_data;
  int32_T i;
  int32_T loop_ub;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_l;
  int32_T idx_d;
  int32_T ntoread_d;
  int32_T b_k;
  int32_T kexp;
  int32_T k_lx;
  int32_T idx_o;
  int32_T ntoread_b;
  int32_T e_k;
  int32_T kexp_n;
  int32_T idx_b;
  int32_T ntoread_l;
  int32_T d_k;
  int32_T i_h;
  uint32_T DataTypeConversion8;        /* '<Root>/Data Type Conversion8' */
  uint32_T SFunctionBuilder1;          /* '<S8>/S-Function Builder1' */
  real32_T ByteUnpack_o2[9];           /* '<S3>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S3>/Byte Reversal' */
  real32_T DataTypeConversion4[4];     /* '<Root>/Data Type Conversion4' */
  real32_T T;                          /* '<S14>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S8>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S3>/Byte Unpack' */
  char_T s1_g[4];
  uint8_T output[3];
  uint8_T ByteUnpack_o3;               /* '<S3>/Byte Unpack' */
  uint8_T DataTypeConversion7[2];      /* '<Root>/Data Type Conversion7' */
  uint8_T BytePack[63];                /* '<Root>/Byte Pack' */
  uint8_T indice_dimario;              /* '<S18>/MATLAB Function' */
  B_One_time_initialization_pro_T One_time_initialization;/* '<S1>/One_time_initialization' */
} B_prova_LOG_arduino_09_22_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_kv_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_g;/* '<S8>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_c;/* '<S8>/I2C Read1' */
  codertarget_arduinobase_int_k_T obj_ga;/* '<S2>/Serial Receive1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S3>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S7>/Delay Input2' */
  real_T P_ref;                        /* '<S1>/MATLAB Function' */
  real_T rl_up;                        /* '<S1>/MATLAB Function' */
  real_T rl_dw;                        /* '<S1>/MATLAB Function' */
  boolean_T UnitDelay_DSTATE;          /* '<S1>/Unit Delay' */
  uint8_T message[80];                 /* '<S16>/Create_message' */
  uint8_T counter;                     /* '<S16>/Create_message' */
  boolean_T start_found;               /* '<S16>/Create_message' */
  boolean_T end_found;                 /* '<S16>/Create_message' */
  DW_One_time_initialization_pr_T One_time_initialization;/* '<S1>/One_time_initialization' */
} DW_prova_LOG_arduino_09_22_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T RPM;                          /* '<Root>/RPM' */
} ExtU_prova_LOG_arduino_09_22_T;

/* Parameters for system: '<S1>/One_time_initialization' */
struct P_One_time_initialization_pro_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S11>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S11>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S11>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S11>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S11>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S11>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S11>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S11>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S11>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S11>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S11>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S11>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S11>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S11>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S11>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S11>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S11>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S11>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_prova_LOG_arduino_09_22_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S8>/I2C Read1'
                                        *   '<S8>/I2C Read12'
                                        *   '<S11>/I2C Read'
                                        *   '<S11>/I2C Read1'
                                        *   '<S11>/I2C Read10'
                                        *   '<S11>/I2C Read11'
                                        *   '<S11>/I2C Read2'
                                        *   '<S11>/I2C Read3'
                                        *   '<S11>/I2C Read4'
                                        *   '<S11>/I2C Read5'
                                        *   '<S11>/I2C Read6'
                                        *   '<S11>/I2C Read7'
                                        *   '<S11>/I2C Read8'
                                        *   '<S11>/I2C Read9'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S8>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S2>/Serial Receive1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S15>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 2
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Constant3_Value_l;            /* Expression: 3
                                        * Referenced by: '<S15>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S18>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S18>/Memory'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T Constant3_Value_i;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T T_0_Value;                    /* Expression: 298
                                        * Referenced by: '<Root>/T_0'
                                        */
  real_T Constant_Value_a;             /* Expression: 15
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S7>/Delay Input2'
                                        */
  real_T Constant_Value_d;             /* Expression: 101000
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: 101000
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S7>/sample time'
                                        */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T PWM_autopilota_Value[3];      /* Expression: [1500 1500 1500]
                                        * Referenced by: '<Root>/PWM_autopilota'
                                        */
  real_T manetta_Value;                /* Expression: 1
                                        * Referenced by: '<Root>/manetta'
                                        */
  real_T Equilibratore_Value;          /* Expression: 1
                                        * Referenced by: '<Root>/Equilibratore'
                                        */
  real_T Alettoni_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Alettoni'
                                        */
  real_T Timone_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Timone'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S8>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S14>/T_0'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S12>/Switch'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S5>/Gain'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S6>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S8>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S8>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S8>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S8>/Constant11'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S8>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S8>/Constant9'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S1>/Unit Delay'
                                */
  boolean_T Constant3_Value_o;         /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S18>/mario'
                                        */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<Root>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<Root>/Fine MSG1'
                                        */
  P_One_time_initialization_pro_T One_time_initialization;/* '<S1>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_prova_LOG_arduino_09__T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_P;

/* Block signals (default storage) */
extern B_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_B;

/* Block states (default storage) */
extern DW_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_prova_LOG_arduino_09_22_T prova_LOG_arduino_09_22_U;

/* Model entry point functions */
extern void prova_LOG_arduino_09_22_initialize(void);
extern void prova_LOG_arduino_09_22_step(void);
extern void prova_LOG_arduino_09_22_terminate(void);

/* Real-time Model object */
extern RT_MODEL_prova_LOG_arduino_09_T *const prova_LOG_arduino_09_22_M;
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
 * '<Root>' : 'prova_LOG_arduino_09_22'
 * '<S1>'   : 'prova_LOG_arduino_09_22/BMP_280'
 * '<S2>'   : 'prova_LOG_arduino_09_22/GPS_Venus'
 * '<S3>'   : 'prova_LOG_arduino_09_22/MTi'
 * '<S4>'   : 'prova_LOG_arduino_09_22/Radians to Degrees'
 * '<S5>'   : 'prova_LOG_arduino_09_22/Radians to Degrees1'
 * '<S6>'   : 'prova_LOG_arduino_09_22/Radians to Degrees2'
 * '<S7>'   : 'prova_LOG_arduino_09_22/BMP_280/Dynamic rate limiter'
 * '<S8>'   : 'prova_LOG_arduino_09_22/BMP_280/Execution_loop'
 * '<S9>'   : 'prova_LOG_arduino_09_22/BMP_280/MATLAB Function'
 * '<S10>'  : 'prova_LOG_arduino_09_22/BMP_280/MATLAB Function1'
 * '<S11>'  : 'prova_LOG_arduino_09_22/BMP_280/One_time_initialization'
 * '<S12>'  : 'prova_LOG_arduino_09_22/BMP_280/Subsystem'
 * '<S13>'  : 'prova_LOG_arduino_09_22/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S14>'  : 'prova_LOG_arduino_09_22/BMP_280/Subsystem/Subsystem1'
 * '<S15>'  : 'prova_LOG_arduino_09_22/GPS_Venus/Subsystem1'
 * '<S16>'  : 'prova_LOG_arduino_09_22/GPS_Venus/Subsystem2'
 * '<S17>'  : 'prova_LOG_arduino_09_22/GPS_Venus/Subsystem2/Create_message'
 * '<S18>'  : 'prova_LOG_arduino_09_22/GPS_Venus/Subsystem2/Subsystem'
 * '<S19>'  : 'prova_LOG_arduino_09_22/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                               /* RTW_HEADER_prova_LOG_arduino_09_22_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
