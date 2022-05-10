/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: provaseriale_noxbee.h
 *
 * Code generated for Simulink model 'provaseriale_noxbee'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 16:56:51 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_provaseriale_noxbee_h_
#define RTW_HEADER_provaseriale_noxbee_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef provaseriale_noxbee_COMMON_INCLUDES_
#define provaseriale_noxbee_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                /* provaseriale_noxbee_COMMON_INCLUDES_ */

#include "provaseriale_noxbee_types.h"

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

/* Block signals for system '<S2>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S9>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S9>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S9>/I2C Read' */
  int16_T I2CRead9;                    /* '<S9>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S9>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S9>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S9>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S9>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S9>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S9>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S9>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S9>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S9>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S9>/I2C Read12' */
} B_One_time_initialization_pro_T;

/* Block states (default storage) for system '<S2>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S9>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_d;/* '<S9>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_o;/* '<S9>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_ds;/* '<S9>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_f;/* '<S9>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_n;/* '<S9>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_e;/* '<S9>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_nf;/* '<S9>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_l;/* '<S9>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_b;/* '<S9>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_m;/* '<S9>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_ni;/* '<S9>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_i;/* '<S9>/I2C Read' */
  codertarget_arduinobase_int_k_T obj_eu;/* '<S9>/I2C Write3' */
  codertarget_arduinobase_int_k_T obj_p;/* '<S9>/I2C Write2' */
  codertarget_arduinobase_int_k_T obj_nb;/* '<S9>/I2C Write1' */
} DW_One_time_initialization_pr_T;

/* Block signals (default storage) */
typedef struct {
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_c[80];             /* '<S14>/Create_message' */
  boolean_T messaggio_m[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S16>/Complex to Real-Imag' */
  real_T DataTypeConversion1_k[9];     /* '<S1>/Data Type Conversion1' */
  real32_T ByteUnpack_o2[9];           /* '<S4>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S4>/Byte Reversal' */
  uint8_T b_dataOut[32];
  uint8_T dataIn[26];
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
  real_T Switch;                       /* '<S13>/Switch' */
  real_T UkYk1;                        /* '<S5>/Difference Inputs1' */
  real_T deltafalllimit;               /* '<S5>/delta fall limit' */
  real_T rtb_Long_re;
  real_T rtb_V_re;
  real_T rtb_heading_re;
  real_T rtb_Magnetic_declination_re;
  real_T rtb_fix_mode_re;
  real_T rtb_n_sat_re;
  real_T rtb_h_mean_sea_re;
  real_T rtb_h_WGS84_re;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T scanned1;
  real_T scanned2;
  real_T b_scanned1;
  real_T scanned1_f;
  real_T scanned2_g;
  real_T b_scanned1_g;
  real_T scanned1_m;
  real_T scanned2_n;
  real_T b_scanned1_p;
  real_T scanned1_l;
  real_T scanned2_j;
  real_T b_scanned1_d;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_b[2];
  int32_T messaggio_size_p[2];
  int32_T messaggio_size_cv[2];
  int32_T s1_size[2];
  boolean_T mess_type_g[5];
  char_T mess_type[5];
  char_T s1[5];
  real32_T T;                          /* '<S12>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S6>/S-Function Builder' */
  real32_T f;
  int32_T DataTypeConversion1;         /* '<S6>/Data Type  Conversion1' */
  int32_T DataTypeConversion;          /* '<S6>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2;         /* '<S6>/S-Function Builder' */
  uint8_T SFunctionBuilder[41];        /* '<S4>/S-Function Builder' */
  int32_T b_i;
  int32_T eb_data;
  int32_T i;
  int32_T loop_ub;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_d;
  int32_T idx_d;
  int32_T ntoread_l;
  int32_T b_k;
  int32_T kexp;
  int32_T k_o;
  int32_T idx_b;
  int32_T ntoread_n;
  int32_T e_k;
  int32_T kexp_b;
  int32_T idx_l;
  int32_T ntoread_h;
  int32_T d_k;
  int32_T i_b;
  uint32_T SFunctionBuilder1;          /* '<S6>/S-Function Builder1' */
  uint8_T ByteUnpack_o1[4];            /* '<S4>/Byte Unpack' */
  char_T s1_l[4];
  uint8_T output[3];
  uint8_T ByteUnpack_o3;               /* '<S4>/Byte Unpack' */
  uint8_T indice_dimario;              /* '<S16>/MATLAB Function' */
  B_One_time_initialization_pro_T One_time_initialization;/* '<S2>/One_time_initialization' */
} B_provaseriale_noxbee_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_hp_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_d;/* '<S6>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_n;/* '<S6>/I2C Read1' */
  codertarget_arduinobase_int_h_T obj_b;/* '<S3>/Serial Receive1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S4>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S5>/Delay Input2' */
  real_T P_ref;                        /* '<S2>/MATLAB Function' */
  real_T rl_up;                        /* '<S2>/MATLAB Function' */
  real_T rl_dw;                        /* '<S2>/MATLAB Function' */
  boolean_T UnitDelay_DSTATE;          /* '<S2>/Unit Delay' */
  uint8_T message[80];                 /* '<S14>/Create_message' */
  uint8_T counter;                     /* '<S14>/Create_message' */
  boolean_T start_found;               /* '<S14>/Create_message' */
  boolean_T end_found;                 /* '<S14>/Create_message' */
  DW_One_time_initialization_pr_T One_time_initialization;/* '<S2>/One_time_initialization' */
} DW_provaseriale_noxbee_T;

/* Parameters for system: '<S2>/One_time_initialization' */
struct P_One_time_initialization_pro_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S9>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S9>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S9>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S9>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S9>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S9>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S9>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S9>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S9>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S9>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S9>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S9>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S9>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S9>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S9>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S9>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S9>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S9>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_provaseriale_noxbee_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S6>/I2C Read1'
                                        *   '<S6>/I2C Read12'
                                        *   '<S9>/I2C Read'
                                        *   '<S9>/I2C Read1'
                                        *   '<S9>/I2C Read10'
                                        *   '<S9>/I2C Read11'
                                        *   '<S9>/I2C Read2'
                                        *   '<S9>/I2C Read3'
                                        *   '<S9>/I2C Read4'
                                        *   '<S9>/I2C Read5'
                                        *   '<S9>/I2C Read6'
                                        *   '<S9>/I2C Read7'
                                        *   '<S9>/I2C Read8'
                                        *   '<S9>/I2C Read9'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S6>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S6>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S3>/Serial Receive1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S13>/h_to_subtract'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 2
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant3_Value_b;            /* Expression: 3
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S16>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S5>/Delay Input2'
                                        */
  real_T Constant4_Value_d;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant2_Value_m;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value_p;            /* Expression: 101325
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S5>/sample time'
                                        */
  real_T Constant1_Value_p;            /* Expression: 280
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 15
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant6_Value_o[3];         /* Expression: zeros(1,3)
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant5_Value_l[4];         /* Expression: zeros(1,4)
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S6>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S12>/T_0'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S10>/Switch'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S6>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S6>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S6>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S6>/Constant11'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S6>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S6>/Constant9'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S2>/Unit Delay'
                                */
  boolean_T Constant3_Value_o;         /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S2>/Constant3'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S16>/mario'
                                        */
  P_One_time_initialization_pro_T One_time_initialization;/* '<S2>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_provaseriale_noxbee_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_provaseriale_noxbee_T provaseriale_noxbee_P;

/* Block signals (default storage) */
extern B_provaseriale_noxbee_T provaseriale_noxbee_B;

/* Block states (default storage) */
extern DW_provaseriale_noxbee_T provaseriale_noxbee_DW;

/* Model entry point functions */
extern void provaseriale_noxbee_initialize(void);
extern void provaseriale_noxbee_step(void);
extern void provaseriale_noxbee_terminate(void);

/* Real-time Model object */
extern RT_MODEL_provaseriale_noxbee_T *const provaseriale_noxbee_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Unused code path elimination
 * Block '<S1>/Data Type Conversion23' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion21' : Eliminate redundant data type conversion
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
 * '<Root>' : 'provaseriale_noxbee'
 * '<S1>'   : 'provaseriale_noxbee/Misure Sensori'
 * '<S2>'   : 'provaseriale_noxbee/Misure Sensori/BMP_280'
 * '<S3>'   : 'provaseriale_noxbee/Misure Sensori/GPS_Venus'
 * '<S4>'   : 'provaseriale_noxbee/Misure Sensori/MTi'
 * '<S5>'   : 'provaseriale_noxbee/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S6>'   : 'provaseriale_noxbee/Misure Sensori/BMP_280/Execution_loop'
 * '<S7>'   : 'provaseriale_noxbee/Misure Sensori/BMP_280/MATLAB Function'
 * '<S8>'   : 'provaseriale_noxbee/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S9>'   : 'provaseriale_noxbee/Misure Sensori/BMP_280/One_time_initialization'
 * '<S10>'  : 'provaseriale_noxbee/Misure Sensori/BMP_280/Subsystem'
 * '<S11>'  : 'provaseriale_noxbee/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S12>'  : 'provaseriale_noxbee/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S13>'  : 'provaseriale_noxbee/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S14>'  : 'provaseriale_noxbee/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S15>'  : 'provaseriale_noxbee/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S16>'  : 'provaseriale_noxbee/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S17>'  : 'provaseriale_noxbee/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_provaseriale_noxbee_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
