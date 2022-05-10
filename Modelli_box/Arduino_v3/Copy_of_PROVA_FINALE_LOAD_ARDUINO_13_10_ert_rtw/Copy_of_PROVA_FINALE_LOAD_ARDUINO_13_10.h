/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10.h
 *
 * Code generated for Simulink model 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10'.
 *
 * Model version                  : 5.18
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct 29 15:55:33 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_h_
#define RTW_HEADER_Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_COMMON_INCLUDES_
#define Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#endif            /* Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_COMMON_INCLUDES_ */

#include "Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

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

#define Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_M (Copy_of_PROVA_FINALE_LOAD_AR_M)

/* Block states (default storage) for system '<S414>/Resettable Subsystem' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S425>/Memory' */
} DW_ResettableSubsystem_Copy_o_T;

/* Zero-crossing (trigger) state for system '<S414>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_f;/* '<S414>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_Copy__T;

/* Block signals for system '<S557>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S564>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S564>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S564>/I2C Read' */
  int16_T I2CRead9;                    /* '<S564>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S564>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S564>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S564>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S564>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S564>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S564>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S564>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S564>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S564>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S564>/I2C Read12' */
} B_One_time_initialization_Cop_T;

/* Block states (default storage) for system '<S557>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S564>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_i;/* '<S564>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_c;/* '<S564>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_b;/* '<S564>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_k;/* '<S564>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_co;/* '<S564>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_k4;/* '<S564>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_d;/* '<S564>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_ir;/* '<S564>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_l;/* '<S564>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_d0;/* '<S564>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_o;/* '<S564>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_kf;/* '<S564>/I2C Read' */
  codertarget_arduinobase_int_m_T obj_d01;/* '<S564>/I2C Write3' */
  codertarget_arduinobase_int_m_T obj_in;/* '<S564>/I2C Write2' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S564>/I2C Write1' */
} DW_One_time_initialization_Co_T;

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion4[42];      /* '<S446>/Data Type Conversion4' */
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  real_T WP_param_m[21];               /* '<S459>/AUTOLANDING_WAYPOINTS' */
  real_T a[16];
  real_T A[16];
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_i[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio[80];
  uint8_T messaggio_k[80];             /* '<S569>/Create_message' */
  boolean_T messaggio_c[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S571>/Complex to Real-Imag' */
  real_T DataTypeConversion1_cx[9];    /* '<S7>/Data Type Conversion1' */
  real_T x_new[4];
  uint8_T b_dataOut[32];
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real_T lat_end[3];                   /* '<S459>/MATLAB Function' */
  uint128m_T r;
  int32_T DataTypeConversion_a[4];     /* '<S16>/Data Type Conversion' */
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint16_T WP_info_in[6];
  uint64m_T a_g;
  uint64m_T p16;
  uint64m_T sk;
  uint64m_T r3;
  uint32_T i2cname;
  real_T h_goHome;                     /* '<S448>/GO_HOME' */
  real_T QUOTA;                        /* '<S447>/WAYPOINTS' */
  real_T Gain;                         /* '<S464>/Gain' */
  real_T Gain_g;                       /* '<S465>/Gain' */
  real_T QUOTA_m;/* '<S446>/Switch di selezione  Task - Waypoint navigation4' */
  real_T In[2];                        /* '<S471>/In' */
  real_T Sum2;                         /* '<S461>/Sum2' */
  real_T maneuver_selector;            /* '<S446>/Chart1' */
  real_T trig_approach;                /* '<S446>/Chart1' */
  real_T trig_flare;                   /* '<S446>/Chart1' */
  real_T approach_selector;            /* '<S446>/Chart1' */
  real_T h_Home;                     /* '<S446>/CALIBRATING_HOME_COORDINATES' */
  real_T Multiply;                     /* '<S457>/Multiply' */
  real_T x_f_out;                      /* '<S457>/MATLAB Function' */
  real_T h_f_out;                      /* '<S457>/MATLAB Function' */
  real_T k_x_out;                      /* '<S457>/MATLAB Function' */
  real_T h_c_out;                      /* '<S457>/MATLAB Function' */
  real_T no_solution;                  /* '<S457>/MATLAB Function' */
  real_T h_vett;                       /* '<S445>/VETTORIALE' */
  real_T Fase_ATO;                     /* '<S444>/Chart1' */
  real_T eq_rot;                       /* '<S444>/Chart1' */
  real_T h_ref;                        /* '<S444>/Chart1' */
  real_T psi_ref_selector;             /* '<S444>/Chart1' */
  real_T theta_ground_selector;        /* '<S444>/Chart1' */
  real_T Switch;                       /* '<S440>/Switch' */
  real_T Switch_l;                     /* '<S426>/Switch' */
  real_T switch_manetta;               /* '<S44>/ STATI' */
  real_T switch_equilibratore;         /* '<S44>/ STATI' */
  real_T switch_alettoni;              /* '<S44>/ STATI' */
  real_T switch_timone;                /* '<S44>/ STATI' */
  real_T modo;                         /* '<S44>/ STATI' */
  real_T denAccum;
  real_T num_254;
  real_T a_g1;
  real_T dist;
  real_T dist_fut;
  real_T DataTypeConversion1_g_m;      /* '<S557>/Data Type Conversion1' */
  real_T IProdOut;                     /* '<S343>/IProd Out' */
  real_T Multiply_f;                   /* '<S581>/Multiply' */
  real_T Rn;                           /* '<S543>/Product1' */
  real_T Gain2_g;                      /* '<S35>/Gain2' */
  real_T e_d;                          /* '<S43>/Sum2' */
  real_T Sum_ar;                       /* '<S528>/Sum' */
  real_T Sum2_o;                       /* '<S309>/Sum2' */
  real_T Sum_n3;                       /* '<S405>/Sum' */
  real_T Sum_o;                        /* '<S309>/Sum' */
  real_T e;                            /* '<S43>/Sum5' */
  real_T Sum3_b;                       /* '<S573>/Sum3' */
  real_T Sum3_o;                       /* '<S575>/Sum3' */
  real_T Switch_bk;                    /* '<S540>/Switch' */
  real_T Gain_n;                       /* '<S469>/Gain' */
  real_T SwitchBumpless2;              /* '<S308>/Switch Bumpless 2' */
  real_T Alettoni;                     /* '<S43>/saturatore A' */
  real_T Saturation;                   /* '<S353>/Saturation' */
  real_T Saturation_f;                 /* '<S403>/Saturation' */
  real_T Alettoni_c;                   /* '<S43>/Switch Bumpless 5' */
  real_T Go_home_selector;
  real_T Al_selector;
  real_T a_fut_tmp;
  real_T Ato_selector;
  real_T Vec_selector;
  real_T Wp_selector;
  real_T rtb_Long_re;
  real_T rtb_Sum3_b_tmp;
  real_T rtb_Sum5_tmp;
  real_T rtb_Sum3_o_tmp;
  real_T rtb_Sum3_o_tmp_tmp;
  real_T b_a_tmp;
  real_T a_tmp_tmp;
  real_T psi_ref_tmp;
  real_T scanned1;
  real_T scanned2;
  real_T b_scanned1;
  real_T scanned1_n;
  real_T scanned2_p;
  real_T b_scanned1_l;
  real_T scanned1_j;
  real_T scanned2_d;
  real_T b_scanned1_g;
  real_T scanned1_l;
  real_T scanned2_dh;
  real_T b_scanned1_d;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_b[2];
  int32_T messaggio_size_p[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_f[2];
  int32_T s1_size[2];
  boolean_T mess_type_l[5];
  char_T mess_type[5];
  char_T s1[5];
  int8_T p[4];
  int8_T ipiv[4];
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T Switch1;                    /* '<S565>/Switch1' */
  real32_T DataTypeConversion1[6];     /* '<S18>/Data Type Conversion1' */
  real32_T AGAC[4];                    /* '<S22>/Data Type Conversion' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion_l;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S2>/Data Type Conversion1' */
  real32_T T;                          /* '<S567>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S561>/S-Function Builder' */
  real32_T WP_param[7];                /* '<S23>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T h_;                         /* '<S557>/MATLAB Function1' */
  real32_T f;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion1_i;       /* '<S561>/Data Type  Conversion1' */
  int32_T DataTypeConversion_ay;       /* '<S561>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_a;       /* '<S561>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T Heading[9];                 /* '<S20>/Data Type Conversion1' */
  int32_T caso;
  int32_T ATO;
  int32_T AL;
  int32_T c;
  int32_T eb_data;
  int32_T jBcol;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
  int32_T i;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_b;
  int32_T idx_n;
  int32_T ntoread_b;
  int32_T b_k;
  int32_T kexp;
  int32_T k_l;
  int32_T idx_h;
  int32_T ntoread_bn;
  int32_T e_k;
  int32_T kexp_d;
  int32_T idx_e;
  int32_T ntoread_bj;
  int32_T d_k;
  int32_T i_j;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S19>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S17>/Data Type Conversion' */
  uint32_T SFunctionBuilder1;          /* '<S561>/S-Function Builder1' */
  real32_T ByteUnpack_o2[9];           /* '<S559>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S559>/Byte Reversal' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  char_T s1_o[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2_h;      /* '<S16>/Data Type Conversion2' */
  uint16_T Throttle;                   /* '<S22>/Data Type Conversion2' */
  uint16_T Memory_a;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T WP_info[6];                 /* '<S23>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T Gain1;                       /* '<S21>/Gain1' */
  int16_T DataTypeConversion_ld[9];    /* '<S18>/Data Type Conversion' */
  int16_T DataTypeConversion1_p[3];    /* '<S16>/Data Type Conversion1' */
  int16_T Heading_g;                   /* '<S22>/Data Type Conversion1' */
  int16_T PWM_throttle;                /* '<S9>/S-Function Builder6' */
  int16_T SFunctionBuilder2;           /* '<S9>/S-Function Builder2' */
  int16_T PWM_elevator;                /* '<S9>/S-Function Builder1' */
  int16_T PWM_aileron;                 /* '<S9>/S-Function Builder7' */
  int16_T PWM_rudder;                  /* '<S9>/S-Function Builder8' */
  int16_T DataTypeConversion2_m;       /* '<S2>/Data Type Conversion2' */
  int16_T DataTypeConversion1_c;       /* '<S10>/Data Type Conversion1' */
  int16_T Sum;                         /* '<S581>/Sum' */
  int16_T DataTypeConversion2_j;       /* '<S10>/Data Type Conversion2' */
  int16_T DataTypeConversion_p;        /* '<S10>/Data Type Conversion' */
  uint8_T SFunctionBuilder[41];        /* '<S559>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S559>/Byte Unpack' */
  uint16_T z;
  uint8_T ByteUnpack_o3;               /* '<S559>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1_h[100];  /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_k[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_j;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_n[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T TmpSignalConversionAtSFunctio_m[4];/* '<S2>/Heartbeat' */
  uint8_T SFunction_o1_j;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_f[264];         /* '<S2>/S-Function' */
  uint8_T iflogic;                     /* '<S19>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S21>/Data Type Conversion3' */
  boolean_T HitCrossing;               /* '<S256>/Hit  Crossing' */
  B_One_time_initialization_Cop_T One_time_initialization;/* '<S557>/One_time_initialization' */
} B_Copy_of_PROVA_FINALE_LOAD_A_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_f5_T obj; /* '<S25>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_f;/* '<S561>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S561>/I2C Read1' */
  codertarget_arduinobase_int_f_T obj_e;/* '<S558>/Serial Receive1' */
  codertarget_arduinobase_block_T obj_b;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S5>/Digital Output' */
  real_T SFunctionBuilder_DSTATE;      /* '<S559>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_l;    /* '<S1>/S-Function Builder' */
  real_T DelayInput2_DSTATE;           /* '<S560>/Delay Input2' */
  real_T Integrator_DSTATE;            /* '<S346>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S396>/Integrator' */
  real_T DiscreteWashoutFilter_states; /* '<S310>/Discrete Washout Filter' */
  real_T SFunctionBuilder10_DSTATE;    /* '<S10>/S-Function Builder10' */
  real_T SFunctionBuilder4_DSTATE;     /* '<S10>/S-Function Builder4' */
  real_T SFunctionBuilder5_DSTATE;     /* '<S10>/S-Function Builder5' */
  real_T SFunctionBuilder9_DSTATE;     /* '<S10>/S-Function Builder9' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S4>/S-Function Builder' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S457>/Discrete-Time Integrator' */
  volatile real_T RateTransition_Buffer0;/* '<S33>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S33>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S33>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S33>/Memory2' */
  real_T Memory_PreviousInput_l[9];    /* '<S571>/Memory' */
  real_T P_ref;                        /* '<S557>/MATLAB Function' */
  real_T rl_up;                        /* '<S557>/MATLAB Function' */
  real_T rl_dw;                        /* '<S557>/MATLAB Function' */
  real_T flag;                         /* '<S448>/GO_HOME' */
  real_T Memory4_PreviousInput;        /* '<S447>/Memory4' */
  real_T flag_m;                       /* '<S447>/WAYPOINTS' */
  real_T lat1;                         /* '<S447>/WAYPOINTS' */
  real_T long1;                        /* '<S447>/WAYPOINTS' */
  real_T Memory7_PreviousInput;        /* '<S446>/Memory7' */
  real_T Memory5_PreviousInput;        /* '<S446>/Memory5' */
  real_T Memory1_PreviousInput_l;      /* '<S446>/Memory1' */
  real_T Memory2_PreviousInput_f;      /* '<S446>/Memory2' */
  real_T x[4];                         /* '<S457>/MATLAB Function' */
  real_T cycle_count;                  /* '<S457>/MATLAB Function' */
  real_T eps[4];                       /* '<S457>/MATLAB Function' */
  real_T flag_c;                       /* '<S446>/ALLINEAMENTO' */
  real_T Memory3_PreviousInput;        /* '<S445>/Memory3' */
  real_T ALT_ref;                      /* '<S445>/VETTORIALE' */
  real_T Memory_PreviousInput_i;       /* '<S444>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S444>/Memory1' */
  real_T alarm;                        /* '<S421>/MATLAB Function1' */
  real_T Memory_PreviousInput_h;       /* '<S442>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S5>/Pulse Generator1' */
  int_T HitCrossing_MODE;              /* '<S256>/Hit  Crossing' */
  uint16_T Memory_PreviousInput_ic[8]; /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE;          /* '<S557>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S396>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S457>/Discrete-Time Integrator' */
  uint8_T Memory4_PreviousInput_c[300];/* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput_l[100];/* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_d[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_h5[4];  /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput_o;     /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S569>/Create_message' */
  uint8_T counter_k;                   /* '<S569>/Create_message' */
  uint8_T is_active_c10_Copy_of_PROVA_FIN;/* '<S446>/Chart1' */
  uint8_T is_c10_Copy_of_PROVA_FINALE_LOA;/* '<S446>/Chart1' */
  uint8_T Memory1_PreviousInput_h;     /* '<S445>/Memory1' */
  uint8_T Memory6_PreviousInput;       /* '<S445>/Memory6' */
  uint8_T is_active_c1_Copy_of_PROVA_FINA;/* '<S444>/Chart1' */
  uint8_T is_c1_Copy_of_PROVA_FINALE_LOAD;/* '<S444>/Chart1' */
  uint8_T temporalCounter_i1;          /* '<S444>/Chart1' */
  uint8_T is_active_c21_Copy_of_PROVA_FIN;/* '<S45>/Chart' */
  uint8_T is_c21_Copy_of_PROVA_FINALE_LOA;/* '<S45>/Chart' */
  uint8_T is_active_c26_Copy_of_PROVA_FIN;/* '<S44>/ STATI' */
  uint8_T is_c26_Copy_of_PROVA_FINALE_LOA;/* '<S44>/ STATI' */
  uint8_T is_AUTOMATICA;               /* '<S44>/ STATI' */
  uint8_T is_active_c23_Copy_of_PROVA_FIN;
                                 /* '<S46>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_c23_Copy_of_PROVA_FINALE_LOA;
                                 /* '<S46>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_active_c9_Copy_of_PROVA_FINA;/* '<S15>/Chart' */
  uint8_T i;                           /* '<S15>/Chart' */
  uint8_T message_i[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_a;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S569>/Create_message' */
  boolean_T end_found;                 /* '<S569>/Create_message' */
  boolean_T x_not_empty;               /* '<S457>/MATLAB Function' */
  boolean_T x_new_not_empty;           /* '<S457>/MATLAB Function' */
  boolean_T cycle_count_not_empty;     /* '<S457>/MATLAB Function' */
  boolean_T eps_not_empty;             /* '<S457>/MATLAB Function' */
  boolean_T Tf_not_empty;              /* '<S416>/MATLAB Function1' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T Enabled_MODE;              /* '<S438>/Enabled ' */
  boolean_T Enabled_MODE_p;            /* '<S430>/Enabled ' */
  boolean_T Enabled_MODE_m;            /* '<S429>/Enabled ' */
  DW_One_time_initialization_Co_T One_time_initialization;/* '<S557>/One_time_initialization' */
  DW_ResettableSubsystem_Copy_o_T ResettableSubsystem_o;/* '<S415>/Resettable Subsystem' */
  DW_ResettableSubsystem_Copy_o_T ResettableSubsystem;/* '<S414>/Resettable Subsystem' */
} DW_Copy_of_PROVA_FINALE_LOAD__T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S256>/Hit  Crossing' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S446>/Sample and Hold' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S444>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE_h; /* '<S444>/Sample and Hold' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S438>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_h;/* '<S430>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_p;/* '<S429>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_Copy__T ResettableSubsystem_o;/* '<S415>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_Copy__T ResettableSubsystem;/* '<S414>/Resettable Subsystem' */
  ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S256>/Enabled Subsystem' */
} PrevZCX_Copy_of_PROVA_FINALE__T;

/* Parameters for system: '<S414>/Enabled Subsystem' */
struct P_EnabledSubsystem_Copy_of_PR_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S423>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S423>/Constant2'
                                        */
  real_T u0_Y0;                        /* Computed Parameter: u0_Y0
                                        * Referenced by: '<S423>/1//0'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S423>/Switch'
                                        */
};

/* Parameters for system: '<S414>/Resettable Subsystem' */
struct P_ResettableSubsystem_Copy_of_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S425>/Memory'
                                        */
};

/* Parameters for system: '<S557>/One_time_initialization' */
struct P_One_time_initialization_Cop_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S564>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S564>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S564>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S564>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S564>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S564>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S564>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S564>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S564>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S564>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S564>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S564>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S564>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S564>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S564>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S564>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S564>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S564>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_Copy_of_PROVA_FINALE_LOAD_A_T_ {
  real_T Kp_comp_h;                    /* Variable: Kp_comp_h
                                        * Referenced by: '<S308>/Constant3'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S43>/saturatore A'
                                        *   '<S43>/saturatore A1'
                                        *   '<S573>/Constant8'
                                        *   '<S579>/Constant'
                                        *   '<S403>/Saturation'
                                        */
  real_T attuatore_Amin;               /* Variable: attuatore_Amin
                                        * Referenced by:
                                        *   '<S43>/saturatore A'
                                        *   '<S43>/saturatore A1'
                                        *   '<S573>/Constant9'
                                        *   '<S579>/Constant1'
                                        *   '<S403>/Saturation'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S575>/Constant8'
                                        *   '<S582>/Constant'
                                        *   '<S308>/saturatore E2'
                                        *   '<S353>/Saturation'
                                        */
  real_T attuatore_Emin;               /* Variable: attuatore_Emin
                                        * Referenced by:
                                        *   '<S575>/Constant9'
                                        *   '<S582>/Constant1'
                                        *   '<S308>/saturatore E2'
                                        *   '<S353>/Saturation'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S43>/saturatore R'
                                        *   '<S577>/Constant8'
                                        *   '<S580>/Constant'
                                        */
  real_T attuatore_Rmin;               /* Variable: attuatore_Rmin
                                        * Referenced by:
                                        *   '<S43>/saturatore R'
                                        *   '<S577>/Constant9'
                                        *   '<S580>/Constant1'
                                        */
  real_T attuatore_Tmax;               /* Variable: attuatore_Tmax
                                        * Referenced by: '<S578>/manetta_massima'
                                        */
  real_T attuatore_Tmin;               /* Variable: attuatore_Tmin
                                        * Referenced by: '<S578>/manetta_minima'
                                        */
  real_T interventoA_05;               /* Variable: interventoA_05
                                        * Referenced by: '<S416>/Constant4'
                                        */
  real_T interventoA_1;                /* Variable: interventoA_1
                                        * Referenced by: '<S416>/Constant3'
                                        */
  real_T interventoE_05;               /* Variable: interventoE_05
                                        * Referenced by: '<S416>/Constant1'
                                        */
  real_T interventoE_1;                /* Variable: interventoE_1
                                        * Referenced by: '<S416>/Constant'
                                        */
  real_T interventoT;                  /* Variable: interventoT
                                        * Referenced by: '<S416>/Constant2'
                                        */
  real_T inv_A;                        /* Variable: inv_A
                                        * Referenced by: '<S43>/Gain1'
                                        */
  real_T inv_E;                        /* Variable: inv_E
                                        * Referenced by: '<S43>/Gain'
                                        */
  real_T inv_R;                        /* Variable: inv_R
                                        * Referenced by: '<S43>/Gain2'
                                        */
  real_T inv_comp_h;                   /* Variable: inv_comp_h
                                        * Referenced by: '<S308>/Gain'
                                        */
  real_T phi_max;                      /* Variable: phi_max
                                        * Referenced by:
                                        *   '<S574>/Constant8'
                                        *   '<S574>/Saturation'
                                        */
  real_T phi_min;                      /* Variable: phi_min
                                        * Referenced by:
                                        *   '<S574>/Constant9'
                                        *   '<S574>/Saturation'
                                        */
  real_T safe_V;                       /* Variable: safe_V
                                        * Referenced by: '<S421>/Constant'
                                        */
  real_T safe_phi;                     /* Variable: safe_phi
                                        * Referenced by: '<S421>/Constant1'
                                        */
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S561>/I2C Read1'
                                        *   '<S561>/I2C Read12'
                                        *   '<S564>/I2C Read'
                                        *   '<S564>/I2C Read1'
                                        *   '<S564>/I2C Read10'
                                        *   '<S564>/I2C Read11'
                                        *   '<S564>/I2C Read2'
                                        *   '<S564>/I2C Read3'
                                        *   '<S564>/I2C Read4'
                                        *   '<S564>/I2C Read5'
                                        *   '<S564>/I2C Read6'
                                        *   '<S564>/I2C Read7'
                                        *   '<S564>/I2C Read8'
                                        *   '<S564>/I2C Read9'
                                        *   '<S425>/Constant4'
                                        *   '<S428>/Constant4'
                                        *   '<S442>/Constant4'
                                        */
  real_T theta_max;                    /* Variable: theta_max
                                        * Referenced by:
                                        *   '<S576>/Constant8'
                                        *   '<S576>/Saturation'
                                        */
  real_T theta_min;                    /* Variable: theta_min
                                        * Referenced by:
                                        *   '<S576>/Constant9'
                                        *   '<S576>/Saturation'
                                        */
  real_T time_alarm_SAFE;              /* Variable: time_alarm_SAFE
                                        * Referenced by: '<S440>/Switch'
                                        */
  real_T vel_wp1_al;                   /* Variable: vel_wp1_al
                                        * Referenced by: '<S459>/Constant'
                                        */
  real_T vel_wp2_al;                   /* Variable: vel_wp2_al
                                        * Referenced by: '<S459>/Constant1'
                                        */
  real32_T Ki_becch;                   /* Variable: Ki_becch
                                        * Referenced by: '<S8>/Ki controllore  beccheggio1'
                                        */
  real32_T Ki_roll;                    /* Variable: Ki_roll
                                        * Referenced by: '<S8>/Ki controllore  rollio3'
                                        */
  real32_T Kp_becch;                   /* Variable: Kp_becch
                                        * Referenced by: '<S8>/Kp controllore beccheggio1'
                                        */
  real32_T Kp_imb;                     /* Variable: Kp_imb
                                        * Referenced by: '<S8>/Kp controllore imbardata'
                                        */
  real32_T Kp_p;                       /* Variable: Kp_p
                                        * Referenced by: '<S8>/Kp controllore  velocità rollio3'
                                        */
  real32_T Kp_q;                       /* Variable: Kp_q
                                        * Referenced by: '<S8>/Kp controllore velocità beccheggio1'
                                        */
  real32_T Kp_roll;                    /* Variable: Kp_roll
                                        * Referenced by: '<S8>/Kp controllore  rollio3'
                                        */
  int8_T K_imb_inv;                    /* Variable: K_imb_inv
                                        * Referenced by: '<S8>/K controllo imbardata inversa'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S346>/Integrator'
                               */
  real_T PIDController_InitialConditio_d;
                              /* Mask Parameter: PIDController_InitialConditio_d
                               * Referenced by: '<S396>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S389>/Kb'
                                        */
  real_T PIDController_Kb_k;           /* Mask Parameter: PIDController_Kb_k
                                        * Referenced by: '<S339>/Kb'
                                        */
  real_T PIDController_Kt;             /* Mask Parameter: PIDController_Kt
                                        * Referenced by: '<S407>/Kt'
                                        */
  real_T PIDController_Kt_m;           /* Mask Parameter: PIDController_Kt_m
                                        * Referenced by: '<S357>/Kt'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S541>/Constant'
                                       */
  real_T CompareToConstant_const_d; /* Mask Parameter: CompareToConstant_const_d
                                     * Referenced by: '<S539>/Constant'
                                     */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S542>/Constant'
                                     */
  real_T CompareToConstant_const_b; /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S535>/Constant'
                                     */
  real_T CompareToConstant_const_dp;
                                   /* Mask Parameter: CompareToConstant_const_dp
                                    * Referenced by: '<S533>/Constant'
                                    */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S536>/Constant'
                                     */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S25>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Out1_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S307>/Out1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S313>/Constant5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 16
                                        * Referenced by: '<S313>/Switch1'
                                        */
  real_T r_rif_Value;                  /* Expression: 0
                                        * Referenced by: '<S43>/r_rif'
                                        */
  real_T Alarm_Int_Y0;                 /* Expression: 0
                                        * Referenced by: '<S432>/Alarm_Int'
                                        */
  real_T Alarm_Int_Y0_j;               /* Expression: 0
                                        * Referenced by: '<S435>/Alarm_Int'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S440>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S440>/Constant1'
                                        */
  real_T AlarmSafe_Y0;                 /* Expression: 0
                                        * Referenced by: '<S440>/Alarm Safe'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S442>/Memory'
                                        */
  real_T Constant1_Value_d;            /* Expression: 20
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S419>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 50
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S452>/ '
                                        */
  real_T _Y0_a;                        /* Expression: initCond
                                        * Referenced by: '<S453>/ '
                                        */
  real_T Gain_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S451>/Gain'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S444>/Memory'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S450>/Gain'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S444>/Memory1'
                                        */
  real_T Out1_Y0_d;                    /* Computed Parameter: Out1_Y0_d
                                        * Referenced by: '<S445>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S445>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S445>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S445>/Out4'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S445>/Memory3'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S454>/Gain'
                                        */
  real_T h_ref_Y0;                     /* Computed Parameter: h_ref_Y0
                                        * Referenced by: '<S457>/h_ref'
                                        */
  real_T flare_data_Y0;                /* Computed Parameter: flare_data_Y0
                                        * Referenced by: '<S457>/flare_data'
                                        */
  real_T landing_abort_Y0;             /* Computed Parameter: landing_abort_Y0
                                        * Referenced by: '<S457>/landing_abort'
                                        */
  real_T rc_ref_app_Y0;                /* Computed Parameter: rc_ref_app_Y0
                                        * Referenced by: '<S457>/rc_ref_app'
                                        */
  real_T x_g0_Value;                   /* Expression: -100
                                        * Referenced by: '<S457>/x_g0'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S457>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S457>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S457>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S457>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S457>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S457>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S457>/Switch'
                                        */
  real_T Gain_Gain_e0;                 /* Expression: -1
                                        * Referenced by: '<S457>/Gain'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S457>/Constant2'
                                        */
  real_T h_ref_Y0_n;                   /* Computed Parameter: h_ref_Y0_n
                                        * Referenced by: '<S461>/h_ref'
                                        */
  real_T RC_ref_Y0;                    /* Computed Parameter: RC_ref_Y0
                                        * Referenced by: '<S461>/RC_ref'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S461>/Gain'
                                        */
  real_T psi_ref_landing_Y0;           /* Computed Parameter: psi_ref_landing_Y0
                                        * Referenced by: '<S462>/psi_ref_landing'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S531>/Bias'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S531>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S531>/Bias1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 360
                                        * Referenced by: '<S534>/Constant2'
                                        */
  real_T Bias_Bias_n;                  /* Expression: 180
                                        * Referenced by: '<S534>/Bias'
                                        */
  real_T Bias1_Bias_n;                 /* Expression: -180
                                        * Referenced by: '<S534>/Bias1'
                                        */
  real_T Constant_Value_n;             /* Expression: 180
                                        * Referenced by: '<S528>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S528>/Constant1'
                                        */
  real_T Constant2_Value_gk;           /* Expression: 360
                                        * Referenced by: '<S532>/Constant2'
                                        */
  real_T Bias_Bias_j;                  /* Expression: 180
                                        * Referenced by: '<S532>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S532>/Bias1'
                                        */
  real_T Bias_Bias_f;                  /* Expression: -90
                                        * Referenced by: '<S537>/Bias'
                                        */
  real_T Gain_Gain_mn;                 /* Expression: -1
                                        * Referenced by: '<S537>/Gain'
                                        */
  real_T Bias1_Bias_f;                 /* Expression: +90
                                        * Referenced by: '<S537>/Bias1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 360
                                        * Referenced by: '<S540>/Constant2'
                                        */
  real_T Bias_Bias_e;                  /* Expression: 180
                                        * Referenced by: '<S540>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S540>/Bias1'
                                        */
  real_T Constant_Value_d;             /* Expression: 180
                                        * Referenced by: '<S529>/Constant'
                                        */
  real_T Constant1_Value_d5;           /* Expression: 0
                                        * Referenced by: '<S529>/Constant1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S538>/Constant2'
                                        */
  real_T Bias_Bias_jc;                 /* Expression: 180
                                        * Referenced by: '<S538>/Bias'
                                        */
  real_T Bias1_Bias_gb;                /* Expression: -180
                                        * Referenced by: '<S538>/Bias1'
                                        */
  real_T _Y0_b[2];                     /* Expression: initCond
                                        * Referenced by: '<S471>/ '
                                        */
  real_T Constant3_Value_c;            /* Expression: 1
                                        * Referenced by: '<S446>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S446>/Constant8'
                                        */
  real_T TAS_AL_Y0;                    /* Computed Parameter: TAS_AL_Y0
                                        * Referenced by: '<S446>/TAS_AL'
                                        */
  real_T QUOTA_AL_Y0;                  /* Computed Parameter: QUOTA_AL_Y0
                                        * Referenced by: '<S446>/QUOTA_AL'
                                        */
  real_T RC_AL_Y0;                     /* Computed Parameter: RC_AL_Y0
                                        * Referenced by: '<S446>/RC_AL'
                                        */
  real_T ROTTA_AL_Y0;                  /* Computed Parameter: ROTTA_AL_Y0
                                        * Referenced by: '<S446>/ROTTA_AL'
                                        */
  real_T H_LAT_Y0;                     /* Computed Parameter: H_LAT_Y0
                                        * Referenced by: '<S446>/H_LAT'
                                        */
  real_T H_LONG_Y0;                    /* Computed Parameter: H_LONG_Y0
                                        * Referenced by: '<S446>/H_LONG'
                                        */
  real_T H_ALT_Y0;                     /* Computed Parameter: H_ALT_Y0
                                        * Referenced by: '<S446>/H_ALT'
                                        */
  real_T distancewaypointsvirtuale_Value[3];/* Expression: [-1000 -800 2000]
                                             * Referenced by: '<S459>/distance waypoints virtuale'
                                             */
  real_T Gain_Gain_es;                 /* Expression: 180/pi
                                        * Referenced by: '<S475>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S476>/Gain'
                                        */
  real_T altwaypointvirtuale_Value[3]; /* Expression: [45 45 45]
                                        * Referenced by: '<S459>/alt waypoint virtuale'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S467>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S466>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S464>/Gain'
                                        */
  real_T Gain_Gain_b2;                 /* Expression: 180/pi
                                        * Referenced by: '<S465>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S527>/Gain1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 1
                                        * Referenced by: '<S543>/Constant2'
                                        */
  real_T Constant_Value_nw;            /* Expression: 1
                                        * Referenced by: '<S547>/Constant'
                                        */
  real_T Constant4_Value_o;            /* Expression: 1
                                        * Referenced by: '<S546>/Constant4'
                                        */
  real_T Constant_Value_j;             /* Expression: 1/298.257223563
                                        * Referenced by: '<S545>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S545>/f'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S544>/Gain1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 6378137
                                        * Referenced by: '<S543>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S543>/Constant'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S543>/Constant3'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S468>/Gain'
                                        */
  real_T Gain_Gain_ov;                 /* Expression: 180/pi
                                        * Referenced by: '<S469>/Gain'
                                        */
  real_T Gain_Gain_jp;                 /* Expression: 180/pi
                                        * Referenced by: '<S470>/Gain'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S446>/Memory7'
                                        */
  real_T Memory5_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S446>/Memory5'
                                        */
  real_T Memory1_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S446>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S446>/Memory2'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S446>/Constant4'
                                        */
  real_T Constant2_Value_n3;           /* Expression: 45
                                        * Referenced by: '<S446>/Constant2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 1
                                        * Referenced by: '<S446>/Switch2'
                                        */
  real_T RC_Y0;                        /* Computed Parameter: RC_Y0
                                        * Referenced by: '<S447>/RC'
                                        */
  real_T VELOCITA_Y0;                  /* Computed Parameter: VELOCITA_Y0
                                        * Referenced by: '<S447>/VELOCITA'
                                        */
  real_T Out3_Y0_j;                    /* Computed Parameter: Out3_Y0_j
                                        * Referenced by: '<S447>/Out3'
                                        */
  real_T Out4_Y0_m;                    /* Computed Parameter: Out4_Y0_m
                                        * Referenced by: '<S447>/Out4'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S447>/Memory4'
                                        */
  real_T Gain_Gain_bu;                 /* Expression: 180/pi
                                        * Referenced by: '<S548>/Gain'
                                        */
  real_T Gain_Gain_jz;                 /* Expression: 180/pi
                                        * Referenced by: '<S549>/Gain'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 180/pi
                                        * Referenced by: '<S550>/Gain'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S448>/Out1'
                                        */
  real_T Out2_Y0_c;                    /* Computed Parameter: Out2_Y0_c
                                        * Referenced by: '<S448>/Out2'
                                        */
  real_T Out3_Y0_d;                    /* Computed Parameter: Out3_Y0_d
                                        * Referenced by: '<S448>/Out3'
                                        */
  real_T Out4_Y0_c;                    /* Computed Parameter: Out4_Y0_c
                                        * Referenced by: '<S448>/Out4'
                                        */
  real_T Gain_Gain_ji;                 /* Expression: 180/pi
                                        * Referenced by: '<S553>/Gain'
                                        */
  real_T Gain_Gain_gf;                 /* Expression: 180/pi
                                        * Referenced by: '<S554>/Gain'
                                        */
  real_T Gain_Gain_ov4;                /* Expression: 180/pi
                                        * Referenced by: '<S555>/Gain'
                                        */
  real_T Constant1_Value_o;            /* Expression: 16
                                        * Referenced by: '<S561>/Constant1'
                                        */
  real_T Constant5_Value_n;            /* Expression: 8
                                        * Referenced by: '<S561>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S561>/Constant6'
                                        */
  real_T Constant4_Value_l;            /* Expression: 4
                                        * Referenced by: '<S561>/Constant4'
                                        */
  real_T Constant2_Value_a;            /* Expression: 16
                                        * Referenced by: '<S561>/Constant2'
                                        */
  real_T Constant3_Value_c0;           /* Expression: 8
                                        * Referenced by: '<S561>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S558>/Serial Receive1'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S568>/h_to_subtract'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S571>/Outport'
                                        */
  real_T Memory_InitialCondition_ab;   /* Expression: 0
                                        * Referenced by: '<S571>/Memory'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_js;           /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant_Value_hx;            /* Expression: 15
                                        * Referenced by: '<S565>/Constant'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S33>/Rate Transition'
                                          */
  real_T Constant2_Value_jg;           /* Expression: 0
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant3'
                                        */
  real_T Memory1_InitialCondition_p;   /* Expression: -1
                                        * Referenced by: '<S33>/Memory1'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 4
                                        * Referenced by: '<S33>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0.02
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Memory_InitialCondition_au;   /* Expression: -0.02
                                        * Referenced by: '<S33>/Memory'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 100
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_jp[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain_by;                 /* Expression: 1000
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Gain_Gain_mz;                 /* Expression: 180/pi
                                        * Referenced by: '<S418>/Gain'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S44>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: pi/180
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Constant_Value_hxg;           /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Gain_Gain_dn;                 /* Expression: 10^3
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain1_Gain_ek;                /* Expression: pi/180
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S31>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: pi/180
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S560>/Delay Input2'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S560>/sample time'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S16>/alt_r'
                                        */
  real_T Gain_Gain_bx[4];              /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S16>/vel y'
                                        */
  real_T Gain1_Gain_ej;                /* Expression: 100
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain1_Gain_n1;                /* Expression: pi/180
                                        * Referenced by: '<S556>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T airspeedgroundspeedaltclimb1_Va;/* Expression: 0
                                          * Referenced by: '<S22>/airspeed groundspeed alt climb1'
                                          */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Switch2_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S40>/Switch2'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T USCITAPERCENTUALE_Gain;       /* Expression: 100/9000
                                        * Referenced by: '<S22>/USCITA PERCENTUALE'
                                        */
  real_T Constant_Value_bh;            /* Expression: 4
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 100
                                        * Referenced by: '<S35>/Gain2'
                                        */
  real_T Constant2_Value_i4;           /* Expression: 0
                                        * Referenced by: '<S308>/Constant2'
                                        */
  real_T Constant1_Value_fj;           /* Expression: 0
                                        * Referenced by: '<S308>/Constant1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 1
                                        * Referenced by: '<S576>/Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S346>/Integrator'
                                        */
  real_T Gain1_Gain_jm;                /* Expression: pi/180
                                        * Referenced by: '<S363>/Gain1'
                                        */
  real_T Gain_Gain_od;                 /* Expression: 180/pi
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Constant2_Value_m;            /* Expression: 90
                                        * Referenced by: '<S35>/Constant2'
                                        */
  real_T Constant1_Value_ng;           /* Expression: 0
                                        * Referenced by: '<S309>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S574>/Gain'
                                        */
  real_T Constant3_Value_cr;           /* Expression: 2
                                        * Referenced by: '<S309>/Constant3'
                                        */
  real_T Integrator_gainval_g;       /* Computed Parameter: Integrator_gainval_g
                                      * Referenced by: '<S396>/Integrator'
                                      */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S37>/Gain'
                                        */
  real_T DiscreteWashoutFilter_NumCoef[2];/* Expression: [ 1 -1]
                                           * Referenced by: '<S310>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_DenCoef[2];/* Expression: [1 -0.995]
                                           * Referenced by: '<S310>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_InitialSt;/* Expression: 0
                                          * Referenced by: '<S310>/Discrete Washout Filter'
                                          */
  real_T Gain_Gain_bh;                 /* Expression: 180/pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T Constant1_Value_pa[3];        /* Expression: zeros(3,1)
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 34
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain_Gain_jr;                 /* Expression: 100
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_jt;           /* Expression: 32
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T RC_default_Value;             /* Expression: 2
                                        * Referenced by: '<S45>/RC_default'
                                        */
  real_T Constant_Value_g;             /* Expression: 70
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value_jf;           /* Expression: 20
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0.3
                                        * Referenced by: '<S256>/Hit  Crossing'
                                        */
  real_T Gain_Gain_je;                 /* Expression: 180/pi
                                        * Referenced by: '<S420>/Gain'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 25
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Expression: 25
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Expression: 2
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T Constant4_Value_a;            /* Expression: 0
                                        * Referenced by: '<S33>/Constant4'
                                        */
  real_T Constant5_Value_a;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant5'
                                        */
  real_T Memory2_InitialCondition_o;   /* Expression: -1
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 9
                                        * Referenced by: '<S33>/Switch1'
                                        */
  int32_T Constant_Value_gw;           /* Computed Parameter: Constant_Value_gw
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S561>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S567>/T_0'
                                        */
  real32_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S565>/Switch'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S561>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S561>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S561>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S561>/Constant11'
                                        */
  uint32_T Constant8_Value_e;          /* Computed Parameter: Constant8_Value_e
                                        * Referenced by: '<S561>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S561>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S21>/onboard_control_sensor_present uint32'
                           */
  int16_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S9>/Switch'
                                        */
  int16_T Gain1_Gain_eu;               /* Computed Parameter: Gain1_Gain_eu
                                        * Referenced by: '<S21>/Gain1'
                                        */
  uint16_T Memory_InitialCondition_at;
                               /* Computed Parameter: Memory_InitialCondition_at
                                * Referenced by: '<S1>/Memory'
                                */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S21>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S21>/ '
                                        */
  uint16_T Memory_InitialCondition_g;
                                /* Computed Parameter: Memory_InitialCondition_g
                                 * Referenced by: '<S2>/Memory'
                                 */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S557>/Unit Delay'
                                */
  boolean_T Constant3_Value_ok;        /* Computed Parameter: Constant3_Value_ok
                                        * Referenced by: '<S557>/Constant3'
                                        */
  int8_T Gain3_Gain;                   /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S8>/Gain3'
                                        */
  uint8_T Memory_InitialCondition_j;
                                /* Computed Parameter: Memory_InitialCondition_j
                                 * Referenced by: '<S445>/Memory'
                                 */
  uint8_T Memory1_InitialCondition_g;
                               /* Computed Parameter: Memory1_InitialCondition_g
                                * Referenced by: '<S445>/Memory1'
                                */
  uint8_T Memory2_InitialCondition_n;
                               /* Computed Parameter: Memory2_InitialCondition_n
                                * Referenced by: '<S445>/Memory2'
                                */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S445>/Memory6'
                                  */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S571>/mario'
                                        */
  uint8_T Memory4_InitialCondition_g[300];/* Expression: uint8(zeros(3,100))
                                           * Referenced by: '<S1>/Memory4'
                                           */
  uint8_T Constant1_Value_a;           /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory5_InitialCondition_d;
                               /* Computed Parameter: Memory5_InitialCondition_d
                                * Referenced by: '<S1>/Memory5'
                                */
  uint8_T Memory1_InitialCondition_b;
                               /* Computed Parameter: Memory1_InitialCondition_b
                                * Referenced by: '<S1>/Memory1'
                                */
  uint8_T Memory_InitialCondition_o;
                                /* Computed Parameter: Memory_InitialCondition_o
                                 * Referenced by: '<Root>/Memory'
                                 */
  uint8_T Memory3_InitialCondition_c;
                               /* Computed Parameter: Memory3_InitialCondition_c
                                * Referenced by: '<S1>/Memory3'
                                */
  uint8_T Memory2_InitialCondition_g[9];
                               /* Computed Parameter: Memory2_InitialCondition_g
                                * Referenced by: '<S1>/Memory2'
                                */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S17>/Type fixed_wing Autopilot generic'
                           */
  P_One_time_initialization_Cop_T One_time_initialization;/* '<S557>/One_time_initialization' */
  P_ResettableSubsystem_Copy_of_T ResettableSubsystem_o;/* '<S415>/Resettable Subsystem' */
  P_EnabledSubsystem_Copy_of_PR_T EnabledSubsystem_j;/* '<S415>/Enabled Subsystem' */
  P_ResettableSubsystem_Copy_of_T ResettableSubsystem;/* '<S414>/Resettable Subsystem' */
  P_EnabledSubsystem_Copy_of_PR_T EnabledSubsystem_h;/* '<S414>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_PROVA_FINALE__T {
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
  } Timing;
};

/* Block parameters (default storage) */
extern P_Copy_of_PROVA_FINALE_LOAD_A_T Copy_of_PROVA_FINALE_LOAD_ARD_P;

/* Block signals (default storage) */
extern B_Copy_of_PROVA_FINALE_LOAD_A_T Copy_of_PROVA_FINALE_LOAD_ARD_B;

/* Block states (default storage) */
extern DW_Copy_of_PROVA_FINALE_LOAD__T Copy_of_PROVA_FINALE_LOAD_AR_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Copy_of_PROVA_FINALE__T Copy_of_PROVA_FINALE_LO_PrevZCX;

/* External data declarations for dependent source files */
extern const uint16_T Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_U16GND;/* uint16_T ground */

/* External function called from main */
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_SetEventsForThisBaseStep
  (boolean_T *eventFlags);
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_initialize(void);
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_step0(void);
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_step1(void);
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_step2(void);
extern void Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_PROVA_FINALE_T *const Copy_of_PROVA_FINALE_LOAD_AR_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S49>/Constant1' : Unused code path elimination
 * Block '<S49>/Constant10' : Unused code path elimination
 * Block '<S49>/Constant11' : Unused code path elimination
 * Block '<S49>/Constant12' : Unused code path elimination
 * Block '<S49>/Constant13' : Unused code path elimination
 * Block '<S49>/Constant14' : Unused code path elimination
 * Block '<S49>/Constant15' : Unused code path elimination
 * Block '<S49>/Constant2' : Unused code path elimination
 * Block '<S49>/Constant3' : Unused code path elimination
 * Block '<S49>/Constant5' : Unused code path elimination
 * Block '<S49>/Constant7' : Unused code path elimination
 * Block '<S49>/Constant9' : Unused code path elimination
 * Block '<S49>/Multiport Switch' : Unused code path elimination
 * Block '<S49>/Multiport Switch1' : Unused code path elimination
 * Block '<S49>/Multiport Switch2' : Unused code path elimination
 * Block '<S80>/DProd Out' : Unused code path elimination
 * Block '<S81>/Filter' : Unused code path elimination
 * Block '<S81>/SumD' : Unused code path elimination
 * Block '<S83>/IProd Out' : Unused code path elimination
 * Block '<S86>/Integrator' : Unused code path elimination
 * Block '<S89>/NProd Out' : Unused code path elimination
 * Block '<S91>/PProd Out' : Unused code path elimination
 * Block '<S95>/Sum' : Unused code path elimination
 * Block '<S97>/Kt' : Unused code path elimination
 * Block '<S97>/SumI3' : Unused code path elimination
 * Block '<S98>/SumI1' : Unused code path elimination
 * Block '<S128>/DProd Out' : Unused code path elimination
 * Block '<S129>/Filter' : Unused code path elimination
 * Block '<S129>/SumD' : Unused code path elimination
 * Block '<S131>/IProd Out' : Unused code path elimination
 * Block '<S134>/Integrator' : Unused code path elimination
 * Block '<S137>/NProd Out' : Unused code path elimination
 * Block '<S139>/PProd Out' : Unused code path elimination
 * Block '<S143>/Sum' : Unused code path elimination
 * Block '<S145>/Kt' : Unused code path elimination
 * Block '<S145>/SumI3' : Unused code path elimination
 * Block '<S146>/SumI1' : Unused code path elimination
 * Block '<S179>/IProd Out' : Unused code path elimination
 * Block '<S182>/Integrator' : Unused code path elimination
 * Block '<S187>/PProd Out' : Unused code path elimination
 * Block '<S191>/Sum' : Unused code path elimination
 * Block '<S193>/Kt' : Unused code path elimination
 * Block '<S193>/SumI3' : Unused code path elimination
 * Block '<S194>/SumI1' : Unused code path elimination
 * Block '<S49>/Saturation' : Unused code path elimination
 * Block '<S49>/Sum1' : Unused code path elimination
 * Block '<S49>/Sum2' : Unused code path elimination
 * Block '<S49>/Sum4' : Unused code path elimination
 * Block '<S49>/Switch auto-manual' : Unused code path elimination
 * Block '<S49>/Switch maneuver' : Unused code path elimination
 * Block '<S49>/Switch rc saturata' : Unused code path elimination
 * Block '<S49>/n-D Lookup Table' : Unused code path elimination
 * Block '<S46>/Kp' : Unused code path elimination
 * Block '<S51>/Constant' : Unused code path elimination
 * Block '<S51>/Lookup Table2' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Propagation' : Unused code path elimination
 * Block '<S199>/LowerRelop1' : Unused code path elimination
 * Block '<S199>/Switch' : Unused code path elimination
 * Block '<S199>/Switch2' : Unused code path elimination
 * Block '<S199>/UpperRelop' : Unused code path elimination
 * Block '<S46>/Switch HOLD//SELECT' : Unused code path elimination
 * Block '<S200>/Constant3' : Unused code path elimination
 * Block '<S200>/Constant4' : Unused code path elimination
 * Block '<S200>/Multiport Switch2' : Unused code path elimination
 * Block '<S200>/Multiport Switch3' : Unused code path elimination
 * Block '<S200>/Switch3' : Unused code path elimination
 * Block '<S200>/Switch4' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Constant2' : Unused code path elimination
 * Block '<S227>/AND3' : Unused code path elimination
 * Block '<S227>/Constant1' : Unused code path elimination
 * Block '<S227>/DataTypeConv1' : Unused code path elimination
 * Block '<S227>/DataTypeConv2' : Unused code path elimination
 * Block '<S229>/DeadZone' : Unused code path elimination
 * Block '<S227>/Equal1' : Unused code path elimination
 * Block '<S227>/NotEqual' : Unused code path elimination
 * Block '<S227>/SignPreIntegrator' : Unused code path elimination
 * Block '<S227>/SignPreSat' : Unused code path elimination
 * Block '<S227>/Switch' : Unused code path elimination
 * Block '<S227>/ZeroGain' : Unused code path elimination
 * Block '<S230>/DProd Out' : Unused code path elimination
 * Block '<S231>/Filter' : Unused code path elimination
 * Block '<S231>/SumD' : Unused code path elimination
 * Block '<S233>/IProd Out' : Unused code path elimination
 * Block '<S236>/Integrator' : Unused code path elimination
 * Block '<S239>/NProd Out' : Unused code path elimination
 * Block '<S241>/PProd Out' : Unused code path elimination
 * Block '<S243>/Saturation' : Unused code path elimination
 * Block '<S245>/Sum' : Unused code path elimination
 * Block '<S247>/Kt' : Unused code path elimination
 * Block '<S247>/SumI3' : Unused code path elimination
 * Block '<S248>/SumI1' : Unused code path elimination
 * Block '<S47>/Switch' : Unused code path elimination
 * Block '<S47>/Switch auto-manual' : Unused code path elimination
 * Block '<S202>/Constant' : Unused code path elimination
 * Block '<S202>/Constant1' : Unused code path elimination
 * Block '<S202>/Constant2' : Unused code path elimination
 * Block '<S253>/Gain1' : Unused code path elimination
 * Block '<S202>/Math Function' : Unused code path elimination
 * Block '<S254>/Gain' : Unused code path elimination
 * Block '<S202>/Sum' : Unused code path elimination
 * Block '<S202>/Sum1' : Unused code path elimination
 * Block '<S202>/Sum2' : Unused code path elimination
 * Block '<S202>/Switch' : Unused code path elimination
 * Block '<S202>/Switch1' : Unused code path elimination
 * Block '<S281>/AND3' : Unused code path elimination
 * Block '<S281>/Constant1' : Unused code path elimination
 * Block '<S281>/DataTypeConv1' : Unused code path elimination
 * Block '<S281>/DataTypeConv2' : Unused code path elimination
 * Block '<S283>/DeadZone' : Unused code path elimination
 * Block '<S281>/Equal1' : Unused code path elimination
 * Block '<S281>/NotEqual' : Unused code path elimination
 * Block '<S281>/SignPreIntegrator' : Unused code path elimination
 * Block '<S281>/SignPreSat' : Unused code path elimination
 * Block '<S281>/Switch' : Unused code path elimination
 * Block '<S281>/ZeroGain' : Unused code path elimination
 * Block '<S287>/IProd Out' : Unused code path elimination
 * Block '<S290>/Integrator' : Unused code path elimination
 * Block '<S295>/PProd Out' : Unused code path elimination
 * Block '<S297>/Saturation' : Unused code path elimination
 * Block '<S299>/Sum' : Unused code path elimination
 * Block '<S301>/Kt' : Unused code path elimination
 * Block '<S301>/SumI3' : Unused code path elimination
 * Block '<S302>/SumI1' : Unused code path elimination
 * Block '<S48>/Sum3' : Unused code path elimination
 * Block '<S48>/Switch Bumpless 1' : Unused code path elimination
 * Block '<S256>/Constant3' : Unused code path elimination
 * Block '<S307>/Constant' : Unused code path elimination
 * Block '<S256>/Switch' : Unused code path elimination
 * Block '<S256>/throttle - landing' : Unused code path elimination
 * Block '<S42>/Switch di selezione riferimeti  per i loop interni 1' : Unused code path elimination
 * Block '<S42>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
 * Block '<S42>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
 * Block '<S43>/Gain3' : Unused code path elimination
 * Block '<S43>/Switch Bumpless 7' : Unused code path elimination
 * Block '<S311>/Constant4' : Unused code path elimination
 * Block '<S311>/Constant7' : Unused code path elimination
 * Block '<S311>/Constant8' : Unused code path elimination
 * Block '<S311>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S311>/Multiport Switch1' : Unused code path elimination
 * Block '<S311>/Sum' : Unused code path elimination
 * Block '<S311>/Switch Bumpless 1' : Unused code path elimination
 * Block '<S414>/Display' : Unused code path elimination
 * Block '<S414>/Display1' : Unused code path elimination
 * Block '<S432>/Constant' : Unused code path elimination
 * Block '<S432>/Constant1' : Unused code path elimination
 * Block '<S432>/Switch' : Unused code path elimination
 * Block '<S434>/Constant4' : Unused code path elimination
 * Block '<S434>/Memory' : Unused code path elimination
 * Block '<S434>/Sum' : Unused code path elimination
 * Block '<S435>/Constant' : Unused code path elimination
 * Block '<S435>/Constant1' : Unused code path elimination
 * Block '<S435>/Switch' : Unused code path elimination
 * Block '<S437>/Constant4' : Unused code path elimination
 * Block '<S437>/Memory' : Unused code path elimination
 * Block '<S437>/Sum' : Unused code path elimination
 * Block '<S416>/Switch' : Unused code path elimination
 * Block '<S44>/Scope1' : Unused code path elimination
 * Block '<S422>/Abs2' : Unused code path elimination
 * Block '<S457>/Constant1' : Unused code path elimination
 * Block '<S457>/Multiply1' : Unused code path elimination
 * Block '<S446>/Constant1' : Unused code path elimination
 * Block '<S446>/Constant6' : Unused code path elimination
 * Block '<S446>/Constant7' : Unused code path elimination
 * Block '<S461>/Constant1' : Unused code path elimination
 * Block '<S461>/Exp1' : Unused code path elimination
 * Block '<S461>/Gain1' : Unused code path elimination
 * Block '<S461>/Gain2' : Unused code path elimination
 * Block '<S461>/Multiply2' : Unused code path elimination
 * Block '<S461>/Multiply3' : Unused code path elimination
 * Block '<S461>/Multiply4' : Unused code path elimination
 * Block '<S461>/Sum3' : Unused code path elimination
 * Block '<S461>/Sum4' : Unused code path elimination
 * Block '<S462>/Gain1' : Unused code path elimination
 * Block '<S507>/IProd Out' : Unused code path elimination
 * Block '<S510>/Integrator' : Unused code path elimination
 * Block '<S515>/PProd Out' : Unused code path elimination
 * Block '<S519>/Sum' : Unused code path elimination
 * Block '<S478>/Gain' : Unused code path elimination
 * Block '<S462>/Sum3' : Unused code path elimination
 * Block '<S462>/psi ref gain' : Unused code path elimination
 * Block '<S462>/psi ref gain1' : Unused code path elimination
 * Block '<S530>/Sum3' : Unused code path elimination
 * Block '<S530>/x*sin' : Unused code path elimination
 * Block '<S530>/y*cos' : Unused code path elimination
 * Block '<S446>/Relational Operator' : Unused code path elimination
 * Block '<S446>/Switch' : Unused code path elimination
 * Block '<S446>/Switch di selezione  Task - Waypoint navigation5' : Unused code path elimination
 * Block '<S446>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
 * Block '<S446>/Switch1' : Unused code path elimination
 * Block '<S447>/saturatore V' : Unused code path elimination
 * Block '<S447>/saturatore V1' : Unused code path elimination
 * Block '<S45>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
 * Block '<S45>/Switch di selezione  Task - Waypoint navigation1' : Unused code path elimination
 * Block '<S45>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
 * Block '<S560>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S566>/Data Type Duplicate' : Unused code path elimination
 * Block '<S566>/Data Type Propagation' : Unused code path elimination
 * Block '<S568>/Constant' : Unused code path elimination
 * Block '<S568>/Constant1' : Unused code path elimination
 * Block '<S568>/Constant2' : Unused code path elimination
 * Block '<S568>/Constant3' : Unused code path elimination
 * Block '<S568>/Equal' : Unused code path elimination
 * Block '<S568>/Equal1' : Unused code path elimination
 * Block '<S568>/Equal2' : Unused code path elimination
 * Block '<S568>/OR' : Unused code path elimination
 * Block '<S568>/Switch' : Unused code path elimination
 * Block '<S558>/Sum' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless AP quota' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore beccheggio' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore imbardata' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore rollio' : Unused code path elimination
 * Block '<S8>/Ki AP quota Select' : Unused code path elimination
 * Block '<S8>/Ki AP rotta1' : Unused code path elimination
 * Block '<S8>/Ki AP velocità' : Unused code path elimination
 * Block '<S8>/Kp AP quota Select' : Unused code path elimination
 * Block '<S8>/Kp AP rotta' : Unused code path elimination
 * Block '<S8>/Kp AP velocità' : Unused code path elimination
 * Block '<S8>/Saturation' : Unused code path elimination
 * Block '<S8>/n-D Lookup Table' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/Data Type Conversion1' : Unused code path elimination
 * Block '<S9>/Data Type Conversion2' : Unused code path elimination
 * Block '<S9>/Data Type Conversion3' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10'
 * '<S1>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR RX'
 * '<S2>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX'
 * '<S3>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA'
 * '<S4>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Inizializzazioni'
 * '<S5>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/LED 13-44'
 * '<S6>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/MISURE DA SENSORI  FILTRATE'
 * '<S7>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori'
 * '<S8>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/PARAMETRI SISTEMA DI CONTROLLO'
 * '<S9>'   : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO'
 * '<S10>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Servi'
 * '<S11>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR RX/MATLAB Function1'
 * '<S12>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR RX/MATLAB Function2'
 * '<S13>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR RX/MATLAB Function3'
 * '<S14>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR RX/MATLAB Function4'
 * '<S15>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Enable '
 * '<S16>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/GPS'
 * '<S17>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Heartbeat'
 * '<S18>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude'
 * '<S19>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/If_subsystem'
 * '<S20>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Servo'
 * '<S21>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/SystemStatus'
 * '<S22>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/VFR'
 * '<S23>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Waypoints'
 * '<S24>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Enable /Chart'
 * '<S25>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Enable /Chart/sendbyte'
 * '<S26>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Heartbeat/Alarm set'
 * '<S27>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude/Degrees to Radians'
 * '<S28>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude/Degrees to Radians1'
 * '<S29>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude/Degrees to Radians2'
 * '<S30>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude/Degrees to Radians3'
 * '<S31>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude/Degrees to Radians4'
 * '<S32>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/IMU & Attidude/Degrees to Radians5'
 * '<S33>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/If_subsystem/Subsystem'
 * '<S34>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/If_subsystem/iflogic_function'
 * '<S35>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Servo/Conversione'
 * '<S36>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S37>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S38>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S39>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/VFR/Radians to Degrees'
 * '<S40>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/VFR/wrapTo360'
 * '<S41>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AIR TX/Waypoints/MATLAB Function'
 * '<S42>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1'
 * '<S43>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
 * '<S44>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1'
 * '<S45>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1'
 * '<S46>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
 * '<S47>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
 * '<S48>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
 * '<S49>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
 * '<S50>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
 * '<S51>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
 * '<S52>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
 * '<S53>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
 * '<S54>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
 * '<S55>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
 * '<S56>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
 * '<S57>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
 * '<S58>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
 * '<S59>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
 * '<S60>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
 * '<S61>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
 * '<S62>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
 * '<S63>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
 * '<S64>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
 * '<S65>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
 * '<S66>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
 * '<S67>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
 * '<S68>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
 * '<S69>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
 * '<S70>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
 * '<S71>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
 * '<S72>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
 * '<S73>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
 * '<S74>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
 * '<S75>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
 * '<S76>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
 * '<S77>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
 * '<S78>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
 * '<S79>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
 * '<S80>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
 * '<S81>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
 * '<S82>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
 * '<S83>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
 * '<S84>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
 * '<S85>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
 * '<S86>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
 * '<S87>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
 * '<S88>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
 * '<S89>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
 * '<S90>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
 * '<S91>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
 * '<S92>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
 * '<S93>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
 * '<S94>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
 * '<S95>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
 * '<S96>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
 * '<S97>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
 * '<S98>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
 * '<S99>'  : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
 * '<S100>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
 * '<S101>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
 * '<S102>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
 * '<S103>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
 * '<S104>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
 * '<S105>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
 * '<S106>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
 * '<S107>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
 * '<S108>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
 * '<S109>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
 * '<S110>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
 * '<S111>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
 * '<S112>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
 * '<S113>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
 * '<S114>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
 * '<S115>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
 * '<S116>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
 * '<S117>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
 * '<S118>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
 * '<S119>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
 * '<S120>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
 * '<S121>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
 * '<S122>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
 * '<S123>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
 * '<S124>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
 * '<S125>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
 * '<S126>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
 * '<S127>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
 * '<S128>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
 * '<S129>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
 * '<S130>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
 * '<S131>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
 * '<S132>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
 * '<S133>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
 * '<S134>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
 * '<S135>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
 * '<S136>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
 * '<S137>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
 * '<S138>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
 * '<S139>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
 * '<S140>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
 * '<S141>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
 * '<S142>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
 * '<S143>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
 * '<S144>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
 * '<S145>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
 * '<S146>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
 * '<S147>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
 * '<S148>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
 * '<S149>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
 * '<S150>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
 * '<S151>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
 * '<S152>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
 * '<S153>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
 * '<S154>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
 * '<S155>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
 * '<S156>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
 * '<S157>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
 * '<S158>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
 * '<S159>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
 * '<S160>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
 * '<S161>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
 * '<S162>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
 * '<S163>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
 * '<S164>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
 * '<S165>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
 * '<S166>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
 * '<S167>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
 * '<S168>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
 * '<S169>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
 * '<S170>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
 * '<S171>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
 * '<S172>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
 * '<S173>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
 * '<S174>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
 * '<S175>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
 * '<S176>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
 * '<S177>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
 * '<S178>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
 * '<S179>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
 * '<S180>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
 * '<S181>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
 * '<S182>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
 * '<S183>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
 * '<S184>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
 * '<S185>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
 * '<S186>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
 * '<S187>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
 * '<S188>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
 * '<S189>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
 * '<S190>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
 * '<S191>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
 * '<S192>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
 * '<S193>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
 * '<S194>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
 * '<S195>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
 * '<S196>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
 * '<S197>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
 * '<S198>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
 * '<S199>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
 * '<S200>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
 * '<S201>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
 * '<S202>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
 * '<S203>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
 * '<S204>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
 * '<S205>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
 * '<S206>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
 * '<S207>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
 * '<S208>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
 * '<S209>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
 * '<S210>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
 * '<S211>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
 * '<S212>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
 * '<S213>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
 * '<S214>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
 * '<S215>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
 * '<S216>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
 * '<S217>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
 * '<S218>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
 * '<S219>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
 * '<S220>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
 * '<S221>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
 * '<S222>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
 * '<S223>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
 * '<S224>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
 * '<S225>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
 * '<S226>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
 * '<S227>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S228>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S229>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S230>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
 * '<S231>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S232>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S233>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
 * '<S234>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
 * '<S235>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S236>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
 * '<S237>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
 * '<S238>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
 * '<S239>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
 * '<S240>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
 * '<S241>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
 * '<S242>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
 * '<S243>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
 * '<S244>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
 * '<S245>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
 * '<S246>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
 * '<S247>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
 * '<S248>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S249>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S250>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S251>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
 * '<S252>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
 * '<S253>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
 * '<S254>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
 * '<S255>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
 * '<S256>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
 * '<S257>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
 * '<S258>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
 * '<S259>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
 * '<S260>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
 * '<S261>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
 * '<S262>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
 * '<S263>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
 * '<S264>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
 * '<S265>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
 * '<S266>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
 * '<S267>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
 * '<S268>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
 * '<S269>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
 * '<S270>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
 * '<S271>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
 * '<S272>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
 * '<S273>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
 * '<S274>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
 * '<S275>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
 * '<S276>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
 * '<S277>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
 * '<S278>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
 * '<S279>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
 * '<S280>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
 * '<S281>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S282>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S283>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S284>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
 * '<S285>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
 * '<S286>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
 * '<S287>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
 * '<S288>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
 * '<S289>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S290>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
 * '<S291>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
 * '<S292>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S293>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
 * '<S294>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
 * '<S295>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
 * '<S296>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
 * '<S297>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
 * '<S298>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
 * '<S299>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
 * '<S300>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
 * '<S301>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
 * '<S302>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S303>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
 * '<S304>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S305>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
 * '<S306>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
 * '<S307>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
 * '<S308>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
 * '<S309>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
 * '<S310>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
 * '<S311>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
 * '<S312>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
 * '<S313>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
 * '<S314>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
 * '<S315>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
 * '<S316>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
 * '<S317>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
 * '<S318>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
 * '<S319>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
 * '<S320>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
 * '<S321>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
 * '<S322>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
 * '<S323>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
 * '<S324>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
 * '<S325>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
 * '<S326>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
 * '<S327>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
 * '<S328>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
 * '<S329>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
 * '<S330>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
 * '<S331>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
 * '<S332>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
 * '<S333>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
 * '<S334>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
 * '<S335>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
 * '<S336>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
 * '<S337>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
 * '<S338>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
 * '<S339>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
 * '<S340>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
 * '<S341>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
 * '<S342>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
 * '<S343>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
 * '<S344>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S345>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S346>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
 * '<S347>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
 * '<S348>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S349>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
 * '<S350>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
 * '<S351>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
 * '<S352>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
 * '<S353>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
 * '<S354>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S355>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
 * '<S356>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
 * '<S357>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
 * '<S358>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S359>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S360>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S361>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
 * '<S362>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
 * '<S363>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
 * '<S364>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
 * '<S365>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
 * '<S366>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
 * '<S367>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
 * '<S368>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
 * '<S369>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
 * '<S370>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
 * '<S371>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
 * '<S372>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
 * '<S373>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
 * '<S374>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
 * '<S375>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
 * '<S376>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
 * '<S377>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
 * '<S378>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
 * '<S379>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
 * '<S380>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
 * '<S381>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
 * '<S382>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
 * '<S383>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
 * '<S384>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
 * '<S385>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
 * '<S386>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
 * '<S387>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
 * '<S388>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
 * '<S389>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
 * '<S390>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
 * '<S391>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
 * '<S392>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
 * '<S393>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
 * '<S394>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
 * '<S395>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S396>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
 * '<S397>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
 * '<S398>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S399>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
 * '<S400>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
 * '<S401>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
 * '<S402>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
 * '<S403>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
 * '<S404>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
 * '<S405>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
 * '<S406>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
 * '<S407>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
 * '<S408>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S409>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
 * '<S410>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S411>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
 * '<S412>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
 * '<S413>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
 * '<S414>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
 * '<S415>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
 * '<S416>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
 * '<S417>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
 * '<S418>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
 * '<S419>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
 * '<S420>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
 * '<S421>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
 * '<S422>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
 * '<S423>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
 * '<S424>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
 * '<S425>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
 * '<S426>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
 * '<S427>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
 * '<S428>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
 * '<S429>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
 * '<S430>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
 * '<S431>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
 * '<S432>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
 * '<S433>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
 * '<S434>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
 * '<S435>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
 * '<S436>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
 * '<S437>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
 * '<S438>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
 * '<S439>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
 * '<S440>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
 * '<S441>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
 * '<S442>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
 * '<S443>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Chart'
 * '<S444>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
 * '<S445>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem'
 * '<S446>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1'
 * '<S447>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem2'
 * '<S448>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem3'
 * '<S449>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
 * '<S450>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
 * '<S451>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
 * '<S452>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
 * '<S453>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
 * '<S454>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
 * '<S455>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
 * '<S456>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
 * '<S457>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
 * '<S458>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
 * '<S459>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
 * '<S460>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
 * '<S461>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
 * '<S462>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
 * '<S463>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
 * '<S464>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
 * '<S465>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
 * '<S466>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
 * '<S467>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
 * '<S468>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
 * '<S469>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
 * '<S470>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
 * '<S471>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
 * '<S472>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
 * '<S473>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
 * '<S474>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
 * '<S475>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
 * '<S476>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
 * '<S477>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
 * '<S478>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
 * '<S479>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
 * '<S480>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
 * '<S481>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
 * '<S482>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
 * '<S483>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
 * '<S484>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
 * '<S485>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
 * '<S486>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
 * '<S487>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
 * '<S488>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
 * '<S489>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
 * '<S490>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
 * '<S491>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
 * '<S492>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
 * '<S493>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
 * '<S494>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
 * '<S495>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
 * '<S496>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
 * '<S497>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
 * '<S498>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
 * '<S499>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
 * '<S500>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
 * '<S501>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
 * '<S502>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
 * '<S503>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
 * '<S504>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
 * '<S505>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
 * '<S506>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
 * '<S507>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
 * '<S508>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
 * '<S509>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S510>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
 * '<S511>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
 * '<S512>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S513>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
 * '<S514>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
 * '<S515>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
 * '<S516>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
 * '<S517>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
 * '<S518>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
 * '<S519>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
 * '<S520>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
 * '<S521>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
 * '<S522>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S523>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
 * '<S524>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S525>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
 * '<S526>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
 * '<S527>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
 * '<S528>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
 * '<S529>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
 * '<S530>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
 * '<S531>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
 * '<S532>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
 * '<S533>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S534>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S535>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S536>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S537>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
 * '<S538>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
 * '<S539>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
 * '<S540>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
 * '<S541>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S542>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
 * '<S543>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
 * '<S544>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
 * '<S545>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
 * '<S546>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
 * '<S547>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
 * '<S548>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
 * '<S549>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
 * '<S550>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
 * '<S551>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
 * '<S552>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
 * '<S553>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
 * '<S554>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
 * '<S555>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
 * '<S556>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S557>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280'
 * '<S558>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/GPS_Venus'
 * '<S559>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/MTi'
 * '<S560>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S561>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/Execution_loop'
 * '<S562>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/MATLAB Function'
 * '<S563>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S564>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/One_time_initialization'
 * '<S565>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/Subsystem'
 * '<S566>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S567>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S568>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S569>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S570>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S571>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S572>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S573>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO/AILERON'
 * '<S574>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO/AILERON1'
 * '<S575>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO/ELEVATOR'
 * '<S576>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO/ELEVATOR1'
 * '<S577>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO/RUDDER'
 * '<S578>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/RADIOCOMANDO/THROTTLE'
 * '<S579>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Servi/AILERON1'
 * '<S580>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Servi/RUDDER6'
 * '<S581>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Servi/THROTTLE1'
 * '<S582>' : 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10/Servi/elevator'
 */
#endif               /* RTW_HEADER_Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
