/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_15.h
 *
 * Code generated for Simulink model 'load_arduino_v_15'.
 *
 * Model version                  : 5.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Oct 20 16:54:03 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_load_arduino_v_15_h_
#define RTW_HEADER_load_arduino_v_15_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef load_arduino_v_15_COMMON_INCLUDES_
#define load_arduino_v_15_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#endif                                 /* load_arduino_v_15_COMMON_INCLUDES_ */

#include "load_arduino_v_15_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_look.h"
#include "rt_look1d.h"

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

/* Block states (default storage) for system '<S422>/Resettable Subsystem' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S433>/Memory' */
} DW_ResettableSubsystem_load_a_T;

/* Zero-crossing (trigger) state for system '<S422>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_f;/* '<S422>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_load__T;

/* Block signals for system '<S578>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S585>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S585>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S585>/I2C Read' */
  int16_T I2CRead9;                    /* '<S585>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S585>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S585>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S585>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S585>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S585>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S585>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S585>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S585>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S585>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S585>/I2C Read12' */
} B_One_time_initialization_loa_T;

/* Block states (default storage) for system '<S578>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S585>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_i;/* '<S585>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_c;/* '<S585>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_b;/* '<S585>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_k;/* '<S585>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_co;/* '<S585>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_k4;/* '<S585>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_d;/* '<S585>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_ir;/* '<S585>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_l;/* '<S585>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_d0;/* '<S585>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_o;/* '<S585>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_kf;/* '<S585>/I2C Read' */
  codertarget_arduinobase_int_m_T obj_d01;/* '<S585>/I2C Write3' */
  codertarget_arduinobase_int_m_T obj_in;/* '<S585>/I2C Write2' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S585>/I2C Write1' */
} DW_One_time_initialization_lo_T;

/* Block signals (default storage) */
typedef struct {
  real_T WP_db_param[42];              /* '<S1>/Data Tversion' */
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  real_T WP_param_m[21];               /* '<S468>/AUTOLANDING_WAYPOINTS' */
  real_T a[16];
  real_T A[16];
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_i[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio_c[80];
  uint8_T messaggio_cx[80];            /* '<S590>/Create_message' */
  boolean_T messaggio_k[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S592>/Complex to Real-Imag' */
  real_T DataTypeConversion1_b[9];     /* '<S7>/Data Type Conversion1' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  uint8_T dataIn[63];
  real_T x_new[4];
  uint8_T b_dataOut[32];
  uint8_T b_dataOut_p[31];
  real_T lat_end[3];                   /* '<S468>/MATLAB Function' */
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint16_T WP_info_in[6];
  uint64m_T a_m;
  uint64m_T p16;
  uint64m_T sk;
  uint64m_T r3;
  uint32_T i2cname;
  real_T Switch;                       /* '<S589>/Switch' */
  real_T V_goHome;                     /* '<S457>/GO_HOME' */
  real_T h_goHome;                     /* '<S457>/GO_HOME' */
  real_T RC_goHome;                    /* '<S457>/GO_HOME' */
  real_T rotta_goHome;                 /* '<S457>/GO_HOME' */
  real_T VELOCITA;                     /* '<S456>/saturatore V' */
  real_T RC;                           /* '<S456>/saturatore V1' */
  real_T QUOTA;                        /* '<S456>/WAYPOINTS' */
  real_T ROTTA;                        /* '<S456>/WAYPOINTS' */
  real_T velocita;
                 /* '<S455>/Switch di selezione  Task - Waypoint navigation5' */
  real_T SwitchdiselezioneTaskWaypointna;
                 /* '<S455>/Switch di selezione  Task - Waypoint navigation6' */
  real_T QUOTA_n;                      /* '<S455>/Sum' */
  real_T Switch1;                      /* '<S455>/Switch1' */
  real_T In[2];                        /* '<S480>/In' */
  real_T Gain;                         /* '<S487>/Gain' */
  real_T Constant1;                    /* '<S470>/Constant1' */
  real_T Sum2;                         /* '<S470>/Sum2' */
  real_T Gain2;                        /* '<S470>/Gain2' */
  real_T maneuver_selector;            /* '<S455>/Chart1' */
  real_T landing_selector;             /* '<S455>/Chart1' */
  real_T trig_approach;                /* '<S455>/Chart1' */
  real_T trig_flare;                   /* '<S455>/Chart1' */
  real_T approach_selector;            /* '<S455>/Chart1' */
  real_T Multiply;                     /* '<S466>/Multiply' */
  real_T Multiply1;                    /* '<S466>/Multiply1' */
  real_T Constant1_l;                  /* '<S466>/Constant1' */
  real_T x_f_out;                      /* '<S466>/MATLAB Function' */
  real_T h_f_out;                      /* '<S466>/MATLAB Function' */
  real_T k_x_out;                      /* '<S466>/MATLAB Function' */
  real_T h_c_out;                      /* '<S466>/MATLAB Function' */
  real_T no_solution;                  /* '<S466>/MATLAB Function' */
  real_T V_vett;                       /* '<S454>/VETTORIALE' */
  real_T h_vett;                       /* '<S454>/VETTORIALE' */
  real_T rotta_vett;                   /* '<S454>/VETTORIALE' */
  real_T RC_vett;                      /* '<S454>/VETTORIALE' */
  real_T Lat_Home;                     /* '<S41>/MATLAB Function' */
  real_T Long_Home;                    /* '<S41>/MATLAB Function' */
  real_T h_Home;                       /* '<S41>/MATLAB Function' */
  real_T Gain_f;                       /* '<S460>/Gain' */
  real_T In_j;                         /* '<S462>/In' */
  real_T In_o;                         /* '<S461>/In' */
  real_T Fase_ATO;                     /* '<S452>/Chart1' */
  real_T manetta_ref;                  /* '<S452>/Chart1' */
  real_T psi_ref;                      /* '<S452>/Chart1' */
  real_T eq_rot;                       /* '<S452>/Chart1' */
  real_T pitch_ref;                    /* '<S452>/Chart1' */
  real_T h_ref;                        /* '<S452>/Chart1' */
  real_T Tas_ref;                      /* '<S452>/Chart1' */
  real_T RC_ref;                       /* '<S452>/Chart1' */
  real_T psi_ref_selector;             /* '<S452>/Chart1' */
  real_T theta_ground_selector;        /* '<S452>/Chart1' */
  real_T Switch_n;                     /* '<S448>/Switch' */
  real_T Switch_l;                     /* '<S434>/Switch' */
  real_T switch_manetta;               /* '<S40>/ STATI' */
  real_T switch_equilibratore;         /* '<S40>/ STATI' */
  real_T switch_alettoni;              /* '<S40>/ STATI' */
  real_T switch_timone;                /* '<S40>/ STATI' */
  real_T phi_safe;                     /* '<S40>/ STATI' */
  real_T theta_safe;                   /* '<S40>/ STATI' */
  real_T throttle_safe;                /* '<S40>/ STATI' */
  real_T modo;                         /* '<S40>/ STATI' */
  real_T OutportBufferForOut1;         /* '<S303>/Constant' */
  real_T mod;                    /* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  real_T num_254;
  real_T h_comandato;
  real_T a_n;
  real_T psi_ref_p;
  real_T dist;
  real_T dist_fut;
  real_T angoloWP;
  real_T psi_ref_pre;
  real_T SumI1_ak;                     /* '<S244>/SumI1' */
  real_T DeadZone;                     /* '<S225>/DeadZone' */
  real_T Gain1_cvb;                    /* '<S567>/Gain1' */
  real_T Gain1_a;                      /* '<S566>/Gain1' */
  real_T Gain1_b;                      /* '<S565>/Gain1' */
  real_T Sum_a1;                       /* '<S362>/Sum' */
  real_T e_b;                          /* '<S39>/Sum2' */
  real_T Sum_l;                        /* '<S139>/Sum' */
  real_T Sum_d;                        /* '<S91>/Sum' */
  real_T Sum_h;                        /* '<S187>/Sum' */
  real_T Sum1_m;                       /* '<S39>/Sum1' */
  real_T e;                            /* '<S39>/Sum5' */
  real_T Sum_gs;                       /* '<S241>/Sum' */
  real_T Sum3;                         /* '<S594>/Sum3' */
  real_T Abs1_a;                       /* '<S540>/Abs1' */
  real_T Abs1;                         /* '<S546>/Abs1' */
  real_T Abs_i;                        /* '<S466>/Abs' */
  real_T Gain_nr;                      /* '<S479>/Gain' */
  real_T Gain_g;                       /* '<S477>/Gain' */
  real_T Gain_dw;                      /* '<S478>/Gain' */
  real_T SwitchBumpless2;              /* '<S305>/Switch Bumpless 2' */
  real_T Go_Home;                      /* '<S9>/Switch' */
  real_T NProdOut_j;                   /* '<S133>/NProd Out' */
  real_T NProdOut_m;                   /* '<S85>/NProd Out' */
  real_T theta_rif;
               /* '<S38>/Switch di selezioneriferimeti  per i loop interni 2' */
  real_T RC_l;     /* '<S41>/Switch di selezione  Task - Waypoint navigation' */
  real_T Gain1_cv;                     /* '<S570>/Gain1' */
  real_T Saturation_h;                 /* '<S293>/Saturation' */
  real_T Saturation_i;                 /* '<S360>/Saturation' */
  real_T Go_home_selector;
  real_T Al_selector;
  real_T Ato_selector;
  real_T Vec_selector;
  real_T Wp_selector;
  real_T rtb_Gain1_idx_1;
  real_T rtb_Gain4_idx_0;
  real_T rtb_Gain4_idx_1;
  real_T rtb_Sum3_o_tmp;
  real_T rtb_Sum3_o_tmp_j;
  real_T scanned1;
  real_T scanned2;
  real_T b_scanned1;
  real_T scanned1_d;
  real_T scanned2_g;
  real_T b_scanned1_l;
  real_T scanned1_dh;
  real_T scanned2_d;
  real_T b_scanned1_lx;
  real_T scanned1_o;
  real_T scanned2_b;
  real_T b_scanned1_n;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_f[2];
  int32_T messaggio_size_g[2];
  int32_T messaggio_size_g1[2];
  int32_T s1_size[2];
  boolean_T mess_type_b[5];
  char_T mess_type[5];
  char_T s1[5];
  int8_T p[4];
  int8_T ipiv[4];
  real32_T f;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_a[4];     /* '<S16>/Data Type Conversion' */
  int32_T DataTypeConversion1_i;       /* '<S582>/Data Type  Conversion1' */
  int32_T DataTypeConversion_ay;       /* '<S582>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_a;       /* '<S582>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  uint16_T Heading[9];                 /* '<S20>/Data Type Conversion1' */
  int16_T DataTypeConversion_ld[9];    /* '<S18>/Data Type Conversion' */
  int16_T DataTypeConversion1_p[3];    /* '<S16>/Data Type Conversion1' */
  int32_T caso;
  int32_T ATO;
  int32_T soglia_dist;
  int32_T c;
  int32_T pipk;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
  int32_T eb_data;
  int32_T i;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_h;
  int32_T idx_b;
  int32_T ntoread_d;
  int32_T b_k;
  int32_T kexp;
  int32_T k_e;
  int32_T idx_bj;
  int32_T ntoread_j;
  int32_T e_k;
  int32_T kexp_f;
  int32_T idx_a;
  int32_T ntoread_ju;
  int32_T d_k;
  int32_T i_j;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S19>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S17>/Data Type Conversion' */
  uint32_T DataTypeConversion8;        /* '<S571>/Data Type Conversion8' */
  uint32_T SFunctionBuilder1;          /* '<S582>/S-Function Builder1' */
  real32_T ByteUnpack1_o2[9];          /* '<S580>/Byte Unpack1' */
  real32_T ByteReversal1[9];           /* '<S580>/Byte Reversal1' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T Switch1_g;                  /* '<S586>/Switch1' */
  real32_T DataTypeConversion1[6];     /* '<S18>/Data Type Conversion1' */
  real32_T AGAC[4];                    /* '<S22>/Data Type Conversion' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion_l;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion4[4];     /* '<S571>/Data Type Conversion4' */
  real32_T T;                          /* '<S588>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S582>/S-Function Builder' */
  real32_T ByteUnpack_o2[4];           /* '<S577>/Byte Unpack' */
  real32_T WP_param[7];                /* '<S23>/MATLAB Function' */
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  char_T s1_l[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2_h;      /* '<S16>/Data Type Conversion2' */
  uint16_T Throttle;                   /* '<S22>/Data Type Conversion2' */
  uint16_T Memory_a;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion1_h[10];  /* '<S571>/Data Type Conversion1' */
  uint16_T ByteUnpack_o4[2];           /* '<S577>/Byte Unpack' */
  uint16_T WP_info[6];                 /* '<S23>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T SFunctionBuilder2;           /* '<S9>/S-Function Builder2' */
  int16_T PWM_aileron;                 /* '<S9>/S-Function Builder7' */
  int16_T DataTypeConversion1_c;       /* '<S10>/Data Type Conversion1' */
  int16_T PWM_throttle;                /* '<S9>/S-Function Builder6' */
  int16_T Sum;                         /* '<S600>/Sum' */
  int16_T PWM_rudder;                  /* '<S9>/S-Function Builder8' */
  int16_T DataTypeConversion2_j;       /* '<S10>/Data Type Conversion2' */
  int16_T PWM_elevator;                /* '<S9>/S-Function Builder1' */
  int16_T DataTypeConversion_p;        /* '<S10>/Data Type Conversion' */
  int16_T Gain1;                       /* '<S21>/Gain1' */
  int16_T Heading_g;                   /* '<S22>/Data Type Conversion1' */
  int16_T DataTypeConversion2_m;       /* '<S2>/Data Type Conversion2' */
  int16_T DataTypeConversion_lx[9];    /* '<S571>/Data Type Conversion' */
  int16_T ByteUnpack_o3[4];            /* '<S577>/Byte Unpack' */
  uint8_T SFunctionBuilder1_b[41];     /* '<S580>/S-Function Builder1' */
  uint8_T ByteUnpack1_o1[4];           /* '<S580>/Byte Unpack1' */
  uint16_T z;
  uint8_T ByteUnpack1_o3;              /* '<S580>/Byte Unpack1' */
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
  uint8_T TmpSignalConversionAtBytePackIn[2];
  uint8_T BytePack[63];                /* '<S571>/Byte Pack' */
  uint8_T indice_dimario;              /* '<S592>/MATLAB Function' */
  uint8_T ByteUnpack_o1[2];            /* '<S577>/Byte Unpack' */
  uint8_T ByteUnpack_o5;               /* '<S577>/Byte Unpack' */
  uint8_T messaggio[31];               /* '<S575>/MATLAB Function' */
  uint8_T iflogic;                     /* '<S19>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S21>/Data Type Conversion3' */
  boolean_T HitCrossing;               /* '<S252>/Hit  Crossing' */
  B_One_time_initialization_loa_T One_time_initialization;/* '<S578>/One_time_initialization' */
} B_load_arduino_v_15_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_hb_T obj; /* '<S571>/Serial Transmit' */
  codertarget_arduinobase_in_hb_T obj_o;/* '<S25>/Serial Transmit' */
  codertarget_arduinobase_int_h_T obj_e;/* '<S579>/Serial Receive1' */
  codertarget_arduinobase_int_h_T obj_m;/* '<S571>/Serial Receive' */
  codertarget_arduinobase_inter_T obj_f;/* '<S582>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S582>/I2C Read1' */
  codertarget_arduinobase_block_T obj_b;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S5>/Digital Output' */
  real_T SFunctionBuilder1_DSTATE;     /* '<S580>/S-Function Builder1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  real_T Integrator_DSTATE;            /* '<S232>/Integrator' */
  real_T Filter_DSTATE;                /* '<S227>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S403>/Integrator' */
  real_T SFunctionBuilder10_DSTATE;    /* '<S10>/S-Function Builder10' */
  real_T Integrator_DSTATE_n;          /* '<S286>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S310>/Discrete-Time Integrator' */
  real_T SFunctionBuilder4_DSTATE;     /* '<S10>/S-Function Builder4' */
  real_T DiscreteWashoutFilter_states; /* '<S307>/Discrete Washout Filter' */
  real_T SFunctionBuilder5_DSTATE;     /* '<S10>/S-Function Builder5' */
  real_T Integrator_DSTATE_h;          /* '<S178>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S82>/Integrator' */
  real_T Filter_DSTATE_l;              /* '<S77>/Filter' */
  real_T Integrator_DSTATE_d5;         /* '<S130>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S125>/Filter' */
  real_T Integrator_DSTATE_l;          /* '<S353>/Integrator' */
  real_T SFunctionBuilder9_DSTATE;     /* '<S10>/S-Function Builder9' */
  real_T DelayInput2_DSTATE;           /* '<S581>/Delay Input2' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S4>/S-Function Builder' */
  real_T Filter_DSTATE_g;              /* '<S514>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S519>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S466>/Discrete-Time Integrator' */
  real_T PrevY;                        /* '<S6>/Rate Limiter1' */
  real_T PrevY_o;                      /* '<S39>/Rate Limiter' */
  volatile real_T RateTransition_Buffer0;/* '<S29>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S29>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S29>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S29>/Memory2' */
  real_T Memory_PreviousInput_l[9];    /* '<S592>/Memory' */
  real_T P_ref;                        /* '<S578>/MATLAB Function' */
  real_T rl_up;                        /* '<S578>/MATLAB Function' */
  real_T rl_dw;                        /* '<S578>/MATLAB Function' */
  real_T flag;                         /* '<S457>/GO_HOME' */
  real_T Memory4_PreviousInput;        /* '<S456>/Memory4' */
  real_T flag_l;                       /* '<S456>/WAYPOINTS' */
  real_T lat1;                         /* '<S456>/WAYPOINTS' */
  real_T long1;                        /* '<S456>/WAYPOINTS' */
  real_T Memory7_PreviousInput;        /* '<S455>/Memory7' */
  real_T Memory5_PreviousInput;        /* '<S455>/Memory5' */
  real_T Memory1_PreviousInput_i;      /* '<S455>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S455>/Memory2' */
  real_T x[4];                         /* '<S466>/MATLAB Function' */
  real_T cycle_count;                  /* '<S466>/MATLAB Function' */
  real_T eps[4];                       /* '<S466>/MATLAB Function' */
  real_T flag_m;                       /* '<S455>/ALLINEAMENTO' */
  real_T Memory3_PreviousInput;        /* '<S454>/Memory3' */
  real_T V_ref;                        /* '<S454>/VETTORIALE' */
  real_T ALT_ref;                      /* '<S454>/VETTORIALE' */
  real_T HDG_ref;                      /* '<S454>/VETTORIALE' */
  real_T Memory_PreviousInput_a;       /* '<S452>/Memory' */
  real_T Memory1_PreviousInput_m;      /* '<S452>/Memory1' */
  real_T alarm;                        /* '<S429>/MATLAB Function1' */
  real_T Memory_PreviousInput_h;       /* '<S450>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S5>/Pulse Generator1' */
  int_T HitCrossing_MODE;              /* '<S252>/Hit  Crossing' */
  uint16_T Memory_PreviousInput_i[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE;          /* '<S578>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S403>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S310>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_c;  /* '<S178>/Integrator' */
  int8_T Integrator_PrevResetState_a;  /* '<S82>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S77>/Filter' */
  int8_T Integrator_PrevResetState_f;  /* '<S130>/Integrator' */
  int8_T Filter_PrevResetState_f;      /* '<S125>/Filter' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S466>/Discrete-Time Integrator' */
  uint8_T Memory4_PreviousInput_c[300];/* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput_l[100];/* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_d[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_h5[4];  /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput_o;     /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S590>/Create_message' */
  uint8_T counter_k;                   /* '<S590>/Create_message' */
  uint8_T message_k[31];               /* '<S575>/MATLAB Function' */
  uint8_T counter_n;                   /* '<S575>/MATLAB Function' */
  uint8_T is_active_c17_load_arduino_v_15;/* '<S455>/Chart1' */
  uint8_T is_c17_load_arduino_v_15;    /* '<S455>/Chart1' */
  uint8_T Memory_PreviousInput_b;      /* '<S454>/Memory' */
  uint8_T Memory1_PreviousInput_a;     /* '<S454>/Memory1' */
  uint8_T Memory2_PreviousInput_d;     /* '<S454>/Memory2' */
  uint8_T Memory6_PreviousInput;       /* '<S454>/Memory6' */
  uint8_T is_active_c2_load_arduino_v_15;/* '<S452>/Chart1' */
  uint8_T is_c2_load_arduino_v_15;     /* '<S452>/Chart1' */
  uint8_T temporalCounter_i1;          /* '<S452>/Chart1' */
  uint8_T is_active_c1_load_arduino_v_15;/* '<S41>/Chart' */
  uint8_T is_c1_load_arduino_v_15;     /* '<S41>/Chart' */
  uint8_T is_active_c26_load_arduino_v_15;/* '<S40>/ STATI' */
  uint8_T is_c26_load_arduino_v_15;    /* '<S40>/ STATI' */
  uint8_T is_AUTOMATICA;               /* '<S40>/ STATI' */
  uint8_T is_active_c23_load_arduino_v_15;
                                 /* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_c23_load_arduino_v_15;
                                 /* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_active_c9_load_arduino_v_15;/* '<S15>/Chart' */
  uint8_T i;                           /* '<S15>/Chart' */
  uint8_T message_i[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_a;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S590>/Create_message' */
  boolean_T end_found;                 /* '<S590>/Create_message' */
  boolean_T start_found_c;             /* '<S575>/MATLAB Function' */
  boolean_T x_not_empty;               /* '<S466>/MATLAB Function' */
  boolean_T x_new_not_empty;           /* '<S466>/MATLAB Function' */
  boolean_T cycle_count_not_empty;     /* '<S466>/MATLAB Function' */
  boolean_T eps_not_empty;             /* '<S466>/MATLAB Function' */
  boolean_T Tf_not_empty;              /* '<S424>/MATLAB Function1' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T Enabled_MODE;              /* '<S446>/Enabled ' */
  boolean_T Enabled_MODE_p;            /* '<S438>/Enabled ' */
  boolean_T Enabled_MODE_m;            /* '<S437>/Enabled ' */
  DW_One_time_initialization_lo_T One_time_initialization;/* '<S578>/One_time_initialization' */
  DW_ResettableSubsystem_load_a_T ResettableSubsystem_o;/* '<S423>/Resettable Subsystem' */
  DW_ResettableSubsystem_load_a_T ResettableSubsystem;/* '<S422>/Resettable Subsystem' */
} DW_load_arduino_v_15_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S252>/Hit  Crossing' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S455>/Sample and Hold' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S452>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE_e; /* '<S452>/Sample and Hold' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S446>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_h;/* '<S438>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_p;/* '<S437>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_load__T ResettableSubsystem_o;/* '<S423>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_load__T ResettableSubsystem;/* '<S422>/Resettable Subsystem' */
  ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S252>/Enabled Subsystem' */
} PrevZCX_load_arduino_v_15_T;

/* Parameters for system: '<S422>/Enabled Subsystem' */
struct P_EnabledSubsystem_load_ardui_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S431>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S431>/Constant2'
                                        */
  real_T u0_Y0;                        /* Computed Parameter: u0_Y0
                                        * Referenced by: '<S431>/1//0'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S431>/Switch'
                                        */
};

/* Parameters for system: '<S422>/Resettable Subsystem' */
struct P_ResettableSubsystem_load_ar_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S433>/Memory'
                                        */
};

/* Parameters for system: '<S578>/One_time_initialization' */
struct P_One_time_initialization_loa_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S585>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S585>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S585>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S585>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S585>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S585>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S585>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S585>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S585>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S585>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S585>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S585>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S585>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S585>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S585>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S585>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S585>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S585>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_load_arduino_v_15_T_ {
  real_T Kd_h_app;                     /* Variable: Kd_h_app
                                        * Referenced by: '<S45>/Constant14'
                                        */
  real_T Kd_h_flare;                   /* Variable: Kd_h_flare
                                        * Referenced by: '<S45>/Constant9'
                                        */
  real_T Ki_h_app;                     /* Variable: Ki_h_app
                                        * Referenced by: '<S45>/Constant7'
                                        */
  real_T Ki_h_cruise;                  /* Variable: Ki_h_cruise
                                        * Referenced by: '<S45>/Constant10'
                                        */
  real_T Ki_h_flare;                   /* Variable: Ki_h_flare
                                        * Referenced by: '<S45>/Constant12'
                                        */
  real_T Kp_AP_quota_hold_h;           /* Variable: Kp_AP_quota_hold_h
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Kp_AP_quota_hold_l;           /* Variable: Kp_AP_quota_hold_l
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Kp_Rotta_ATO;                 /* Variable: Kp_Rotta_ATO
                                        * Referenced by: '<S196>/Constant3'
                                        */
  real_T Kp_Rotta_psi;                 /* Variable: Kp_Rotta_psi
                                        * Referenced by:
                                        *   '<S304>/Constant3'
                                        *   '<S304>/Constant4'
                                        */
  real_T Kp_comp_h;                    /* Variable: Kp_comp_h
                                        * Referenced by: '<S305>/Constant3'
                                        */
  real_T Kp_h_cruise;                  /* Variable: Kp_h_cruise
                                        * Referenced by: '<S45>/Constant5'
                                        */
  real_T Kp_h_flare;                   /* Variable: Kp_h_flare
                                        * Referenced by: '<S45>/Constant11'
                                        */
  real_T V_max;                        /* Variable: V_max
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T V_stall;                      /* Variable: V_stall
                                        * Referenced by:
                                        *   '<S452>/Constant1'
                                        *   '<S455>/Constant6'
                                        *   '<S320>/Switch1'
                                        *   '<S466>/Constant1'
                                        *   '<S470>/Constant1'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S39>/saturatore A'
                                        *   '<S39>/saturatore A1'
                                        *   '<S594>/Constant8'
                                        *   '<S598>/Constant'
                                        *   '<S410>/Saturation'
                                        */
  real_T attuatore_Amin;               /* Variable: attuatore_Amin
                                        * Referenced by:
                                        *   '<S39>/saturatore A'
                                        *   '<S39>/saturatore A1'
                                        *   '<S594>/Constant9'
                                        *   '<S598>/Constant1'
                                        *   '<S410>/Saturation'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S595>/Constant8'
                                        *   '<S601>/Constant'
                                        *   '<S305>/saturatore E2'
                                        *   '<S360>/Saturation'
                                        */
  real_T attuatore_Emin;               /* Variable: attuatore_Emin
                                        * Referenced by:
                                        *   '<S595>/Constant9'
                                        *   '<S601>/Constant1'
                                        *   '<S305>/saturatore E2'
                                        *   '<S360>/Saturation'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S39>/saturatore R'
                                        *   '<S596>/Constant8'
                                        *   '<S599>/Constant'
                                        */
  real_T attuatore_Rmin;               /* Variable: attuatore_Rmin
                                        * Referenced by:
                                        *   '<S39>/saturatore R'
                                        *   '<S596>/Constant9'
                                        *   '<S599>/Constant1'
                                        */
  real_T attuatore_Tmax;               /* Variable: attuatore_Tmax
                                        * Referenced by:
                                        *   '<S39>/Saturation'
                                        *   '<S597>/manetta_massima'
                                        *   '<S310>/Discrete-Time Integrator'
                                        *   '<S293>/Saturation'
                                        *   '<S279>/DeadZone'
                                        */
  real_T attuatore_Tmin;               /* Variable: attuatore_Tmin
                                        * Referenced by:
                                        *   '<S39>/Saturation'
                                        *   '<S597>/manetta_minima'
                                        *   '<S293>/Saturation'
                                        *   '<S279>/DeadZone'
                                        */
  real_T final_h;                      /* Variable: final_h
                                        * Referenced by: '<S452>/Constant'
                                        */
  real_T interventoA_05;               /* Variable: interventoA_05
                                        * Referenced by: '<S424>/Constant4'
                                        */
  real_T interventoA_1;                /* Variable: interventoA_1
                                        * Referenced by: '<S424>/Constant3'
                                        */
  real_T interventoE_05;               /* Variable: interventoE_05
                                        * Referenced by: '<S424>/Constant1'
                                        */
  real_T interventoE_1;                /* Variable: interventoE_1
                                        * Referenced by: '<S424>/Constant'
                                        */
  real_T interventoT;                  /* Variable: interventoT
                                        * Referenced by: '<S424>/Constant2'
                                        */
  real_T inv_A;                        /* Variable: inv_A
                                        * Referenced by: '<S39>/Gain1'
                                        */
  real_T inv_E;                        /* Variable: inv_E
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T inv_R;                        /* Variable: inv_R
                                        * Referenced by: '<S39>/Gain2'
                                        */
  real_T inv_T;                        /* Variable: inv_T
                                        * Referenced by: '<S39>/Gain3'
                                        */
  real_T inv_comp_h;                   /* Variable: inv_comp_h
                                        * Referenced by: '<S305>/Gain'
                                        */
  real_T safe_V;                       /* Variable: safe_V
                                        * Referenced by: '<S429>/Constant'
                                        */
  real_T safe_phi;                     /* Variable: safe_phi
                                        * Referenced by: '<S429>/Constant1'
                                        */
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S582>/I2C Read1'
                                        *   '<S582>/I2C Read12'
                                        *   '<S585>/I2C Read'
                                        *   '<S585>/I2C Read1'
                                        *   '<S585>/I2C Read10'
                                        *   '<S585>/I2C Read11'
                                        *   '<S585>/I2C Read2'
                                        *   '<S585>/I2C Read3'
                                        *   '<S585>/I2C Read4'
                                        *   '<S585>/I2C Read5'
                                        *   '<S585>/I2C Read6'
                                        *   '<S585>/I2C Read7'
                                        *   '<S585>/I2C Read8'
                                        *   '<S585>/I2C Read9'
                                        *   '<S433>/Constant4'
                                        *   '<S436>/Constant4'
                                        *   '<S450>/Constant4'
                                        */
  real_T theta_rot;                    /* Variable: theta_rot
                                        * Referenced by: '<S452>/Constant2'
                                        */
  real_T time_alarm_SAFE;              /* Variable: time_alarm_SAFE
                                        * Referenced by: '<S448>/Switch'
                                        */
  real_T vel_wp1_al;                   /* Variable: vel_wp1_al
                                        * Referenced by: '<S468>/Constant'
                                        */
  real_T vel_wp2_al;                   /* Variable: vel_wp2_al
                                        * Referenced by: '<S468>/Constant1'
                                        */
  real32_T Ki_AP_vel;                  /* Variable: Ki_AP_vel
                                        * Referenced by: '<S8>/Ki AP velocità'
                                        */
  real32_T Ki_becch;                   /* Variable: Ki_becch
                                        * Referenced by: '<S8>/Ki controllore  beccheggio1'
                                        */
  real32_T Ki_roll;                    /* Variable: Ki_roll
                                        * Referenced by: '<S8>/Ki controllore  rollio3'
                                        */
  real32_T Kp_AP_rotta;                /* Variable: Kp_AP_rotta
                                        * Referenced by: '<S8>/Kp AP rotta'
                                        */
  real32_T Kp_AP_vel;                  /* Variable: Kp_AP_vel
                                        * Referenced by: '<S8>/Kp AP velocità'
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
                               * Referenced by: '<S514>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S227>/Filter'
                               */
  real_T PIApproach_InitialConditionForF;
                              /* Mask Parameter: PIApproach_InitialConditionForF
                               * Referenced by: '<S77>/Filter'
                               */
  real_T PIApproach1_InitialConditionFor;
                              /* Mask Parameter: PIApproach1_InitialConditionFor
                               * Referenced by: '<S125>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S519>/Integrator'
                               */
  real_T PIDController1_InitialConditi_n;
                              /* Mask Parameter: PIDController1_InitialConditi_n
                               * Referenced by: '<S232>/Integrator'
                               */
  real_T PIDController_InitialConditi_ld;
                              /* Mask Parameter: PIDController_InitialConditi_ld
                               * Referenced by: '<S403>/Integrator'
                               */
  real_T PIDController_InitialConditio_g;
                              /* Mask Parameter: PIDController_InitialConditio_g
                               * Referenced by: '<S286>/Integrator'
                               */
  real_T PIRCsaturato_InitialConditionFo;
                              /* Mask Parameter: PIRCsaturato_InitialConditionFo
                               * Referenced by: '<S178>/Integrator'
                               */
  real_T PIApproach_InitialConditionForI;
                              /* Mask Parameter: PIApproach_InitialConditionForI
                               * Referenced by: '<S82>/Integrator'
                               */
  real_T PIApproach1_InitialConditionF_n;
                              /* Mask Parameter: PIApproach1_InitialConditionF_n
                               * Referenced by: '<S130>/Integrator'
                               */
  real_T PIDController_InitialConditio_a;
                              /* Mask Parameter: PIDController_InitialConditio_a
                               * Referenced by: '<S353>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S346>/Kb'
                                        */
  real_T PIDController_Kb_g;           /* Mask Parameter: PIDController_Kb_g
                                        * Referenced by: '<S396>/Kb'
                                        */
  real_T PIDController_Kt;             /* Mask Parameter: PIDController_Kt
                                        * Referenced by: '<S364>/Kt'
                                        */
  real_T PIApproach_Kt;                /* Mask Parameter: PIApproach_Kt
                                        * Referenced by: '<S93>/Kt'
                                        */
  real_T PIApproach1_Kt;               /* Mask Parameter: PIApproach1_Kt
                                        * Referenced by: '<S141>/Kt'
                                        */
  real_T PIRCsaturato_Kt;              /* Mask Parameter: PIRCsaturato_Kt
                                        * Referenced by: '<S189>/Kt'
                                        */
  real_T PIDController_Kt_p;           /* Mask Parameter: PIDController_Kt_p
                                        * Referenced by: '<S297>/Kt'
                                        */
  real_T PIDController_Kt_g;           /* Mask Parameter: PIDController_Kt_g
                                        * Referenced by: '<S414>/Kt'
                                        */
  real_T PIDController1_Kt;            /* Mask Parameter: PIDController1_Kt
                                        * Referenced by: '<S243>/Kt'
                                        */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by:
                               *   '<S239>/Saturation'
                               *   '<S225>/DeadZone'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by:
                               *   '<S239>/Saturation'
                               *   '<S225>/DeadZone'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S550>/Constant'
                                       */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S548>/Constant'
                                     */
  real_T CompareToConstant_const_f; /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S551>/Constant'
                                     */
  real_T CompareToConstant_const_k; /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S544>/Constant'
                                     */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S542>/Constant'
                                     */
  real_T CompareToConstant_const_o; /* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S545>/Constant'
                                     */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S25>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T nDLookupTable_tableData[2];
                          /* Expression: [Kp_AP_quota_hold_l Kp_AP_quota_hold_h]
                           * Referenced by: '<S8>/n-D Lookup Table'
                           */
  real_T nDLookupTable_bp01Data[2];    /* Expression: [V_stall*1.2 V_max*0.8]
                                        * Referenced by: '<S8>/n-D Lookup Table'
                                        */
  real_T LookupTable2_XData[6];        /* Expression: [15;20;25;30;35;40]
                                        * Referenced by: '<S47>/Lookup Table2'
                                        */
  real_T LookupTable2_YData[6];        /* Expression: [2;2.5;3;3.5;4;4]
                                        * Referenced by: '<S47>/Lookup Table2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S196>/Constant4'
                                        */
  real_T Switch_Threshold;             /* Expression: 180
                                        * Referenced by: '<S198>/Switch'
                                        */
  real_T Out1_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S303>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S303>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S252>/Constant3'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S252>/Switch'
                                        */
  real_T Constant2_Value_f;            /* Expression: 360
                                        * Referenced by: '<S317>/Constant2'
                                        */
  real_T Constant2_Value_c;            /* Expression: 360
                                        * Referenced by: '<S318>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S312>/Gain'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S313>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S320>/Constant5'
                                        */
  real_T Constant2_Value_o;            /* Expression: 360
                                        * Referenced by: '<S315>/Constant2'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S316>/Constant2'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S314>/Gain'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S316>/Switch2'
                                        */
  real_T Switch2_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<S315>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.15
                                        * Referenced by: '<S304>/Switch3'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.15
                                        * Referenced by: '<S308>/Switch4'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S420>/Gain1'
                                        */
  real_T Alarm_Int_Y0;                 /* Expression: 0
                                        * Referenced by: '<S440>/Alarm_Int'
                                        */
  real_T Alarm_Int_Y0_j;               /* Expression: 0
                                        * Referenced by: '<S443>/Alarm_Int'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S448>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S448>/Constant1'
                                        */
  real_T AlarmSafe_Y0;                 /* Expression: 0
                                        * Referenced by: '<S448>/Alarm Safe'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S450>/Memory'
                                        */
  real_T Constant1_Value_d;            /* Expression: 20
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S427>/Gain'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S461>/ '
                                        */
  real_T _Y0_a;                        /* Expression: initCond
                                        * Referenced by: '<S462>/ '
                                        */
  real_T rotta_ATO_Y0;                 /* Computed Parameter: rotta_ATO_Y0
                                        * Referenced by: '<S452>/rotta_ATO'
                                        */
  real_T Memory_InitialCondition_k;    /* Expression: 0
                                        * Referenced by: '<S452>/Memory'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S459>/Gain'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S452>/Memory1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S460>/Gain'
                                        */
  real_T Out1_Y0_f;                    /* Computed Parameter: Out1_Y0_f
                                        * Referenced by: '<S454>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S454>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S454>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S454>/Out4'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S454>/Memory3'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180/pi
                                        * Referenced by: '<S463>/Gain'
                                        */
  real_T h_ref_Y0;                     /* Computed Parameter: h_ref_Y0
                                        * Referenced by: '<S466>/h_ref'
                                        */
  real_T flare_data_Y0;                /* Computed Parameter: flare_data_Y0
                                        * Referenced by: '<S466>/flare_data'
                                        */
  real_T landing_abort_Y0;             /* Computed Parameter: landing_abort_Y0
                                        * Referenced by: '<S466>/landing_abort'
                                        */
  real_T rc_ref_app_Y0;                /* Computed Parameter: rc_ref_app_Y0
                                        * Referenced by: '<S466>/rc_ref_app'
                                        */
  real_T x_g0_Value;                   /* Expression: -100
                                        * Referenced by: '<S466>/x_g0'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S466>/Constant3'
                                        */
  real_T Constant4_Value_e;            /* Expression: 0
                                        * Referenced by: '<S466>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S466>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S466>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S466>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S466>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S466>/Switch'
                                        */
  real_T Gain_Gain_oz;                 /* Expression: -1
                                        * Referenced by: '<S466>/Gain'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S466>/Constant2'
                                        */
  real_T h_ref_Y0_b;                   /* Computed Parameter: h_ref_Y0_b
                                        * Referenced by: '<S470>/h_ref'
                                        */
  real_T RC_ref_Y0;                    /* Computed Parameter: RC_ref_Y0
                                        * Referenced by: '<S470>/RC_ref'
                                        */
  real_T Gain_Gain_hs;                 /* Expression: -1
                                        * Referenced by: '<S470>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S470>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S470>/Gain2'
                                        */
  real_T psi_ref_landing_Y0;           /* Computed Parameter: psi_ref_landing_Y0
                                        * Referenced by: '<S471>/psi_ref_landing'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S471>/Gain1'
                                        */
  real_T psirefgain2_Value;            /* Expression: 0.1
                                        * Referenced by: '<S471>/psi ref gain2'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S514>/Filter'
                                        */
  real_T psirefgain3_Value;            /* Expression: 50
                                        * Referenced by: '<S471>/psi ref gain3'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S519>/Integrator'
                                        */
  real_T psirefgain_Value;             /* Expression: 0.0042
                                        * Referenced by: '<S471>/psi ref gain'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S487>/Gain'
                                        */
  real_T psirefgain1_Value;            /* Expression: 0.000072
                                        * Referenced by: '<S471>/psi ref gain1'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S540>/Bias'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S540>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S540>/Bias1'
                                        */
  real_T Constant2_Value_o2;           /* Expression: 360
                                        * Referenced by: '<S543>/Constant2'
                                        */
  real_T Bias_Bias_d;                  /* Expression: 180
                                        * Referenced by: '<S543>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S543>/Bias1'
                                        */
  real_T Constant_Value_e;             /* Expression: 180
                                        * Referenced by: '<S537>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S537>/Constant1'
                                        */
  real_T Constant2_Value_on;           /* Expression: 360
                                        * Referenced by: '<S541>/Constant2'
                                        */
  real_T Bias_Bias_g;                  /* Expression: 180
                                        * Referenced by: '<S541>/Bias'
                                        */
  real_T Bias1_Bias_c;                 /* Expression: -180
                                        * Referenced by: '<S541>/Bias1'
                                        */
  real_T Bias_Bias_m;                  /* Expression: -90
                                        * Referenced by: '<S546>/Bias'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S546>/Gain'
                                        */
  real_T Bias1_Bias_f;                 /* Expression: +90
                                        * Referenced by: '<S546>/Bias1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S549>/Constant2'
                                        */
  real_T Bias_Bias_b;                  /* Expression: 180
                                        * Referenced by: '<S549>/Bias'
                                        */
  real_T Bias1_Bias_jg;                /* Expression: -180
                                        * Referenced by: '<S549>/Bias1'
                                        */
  real_T Constant_Value_a;             /* Expression: 180
                                        * Referenced by: '<S538>/Constant'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S538>/Constant1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 360
                                        * Referenced by: '<S547>/Constant2'
                                        */
  real_T Bias_Bias_c;                  /* Expression: 180
                                        * Referenced by: '<S547>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S547>/Bias1'
                                        */
  real_T _Y0_f[2];                     /* Expression: initCond
                                        * Referenced by: '<S480>/ '
                                        */
  real_T Constant3_Value_m;            /* Expression: 1
                                        * Referenced by: '<S455>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S455>/Constant8'
                                        */
  real_T TAS_AL_Y0;                    /* Computed Parameter: TAS_AL_Y0
                                        * Referenced by: '<S455>/TAS_AL'
                                        */
  real_T QUOTA_AL_Y0;                  /* Computed Parameter: QUOTA_AL_Y0
                                        * Referenced by: '<S455>/QUOTA_AL'
                                        */
  real_T RC_AL_Y0;                     /* Computed Parameter: RC_AL_Y0
                                        * Referenced by: '<S455>/RC_AL'
                                        */
  real_T ROTTA_AL_Y0;                  /* Computed Parameter: ROTTA_AL_Y0
                                        * Referenced by: '<S455>/ROTTA_AL'
                                        */
  real_T distancewaypointsvirtuale_Value[3];/* Expression: [-1000 -800 2000]
                                             * Referenced by: '<S468>/distance waypoints virtuale'
                                             */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S484>/Gain'
                                        */
  real_T Gain_Gain_pc;                 /* Expression: 180/pi
                                        * Referenced by: '<S485>/Gain'
                                        */
  real_T altwaypointvirtuale_Value[3]; /* Expression: [45 45 45]
                                        * Referenced by: '<S468>/alt waypoint virtuale'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 180/pi
                                        * Referenced by: '<S476>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S475>/Gain'
                                        */
  real_T Gain_Gain_n2;                 /* Expression: 180/pi
                                        * Referenced by: '<S473>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S474>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S536>/Gain1'
                                        */
  real_T Constant2_Value_oc;           /* Expression: 1
                                        * Referenced by: '<S552>/Constant2'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S556>/Constant'
                                        */
  real_T Constant4_Value_ee;           /* Expression: 1
                                        * Referenced by: '<S555>/Constant4'
                                        */
  real_T Constant_Value_i;             /* Expression: 1/298.257223563
                                        * Referenced by: '<S554>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S554>/f'
                                        */
  real_T Gain1_Gain_m4;                /* Expression: pi/180
                                        * Referenced by: '<S553>/Gain1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 6378137
                                        * Referenced by: '<S552>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S552>/Constant'
                                        */
  real_T Constant3_Value_h;            /* Expression: 1
                                        * Referenced by: '<S552>/Constant3'
                                        */
  real_T Gain_Gain_lp;                 /* Expression: 180/pi
                                        * Referenced by: '<S477>/Gain'
                                        */
  real_T Gain_Gain_iz;                 /* Expression: 180/pi
                                        * Referenced by: '<S478>/Gain'
                                        */
  real_T Gain_Gain_dl;                 /* Expression: 180/pi
                                        * Referenced by: '<S479>/Gain'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S455>/Memory7'
                                        */
  real_T Memory5_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S455>/Memory5'
                                        */
  real_T Memory1_InitialCondition_g;   /* Expression: 0
                                        * Referenced by: '<S455>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S455>/Memory2'
                                        */
  real_T Constant4_Value_n;            /* Expression: 0
                                        * Referenced by: '<S455>/Constant4'
                                        */
  real_T Constant1_Value_c;            /* Expression: 2
                                        * Referenced by: '<S455>/Constant1'
                                        */
  real_T Constant7_Value;              /* Expression: -2
                                        * Referenced by: '<S455>/Constant7'
                                        */
  real_T Constant2_Value_jb;           /* Expression: 45
                                        * Referenced by: '<S455>/Constant2'
                                        */
  real_T latezzacarrello_Value;        /* Expression: 0
                                        * Referenced by: '<S455>/latezza carrello'
                                        */
  real_T Switch2_Threshold_p;          /* Expression: 1
                                        * Referenced by: '<S455>/Switch2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S455>/Switch1'
                                        */
  real_T RC_Y0;                        /* Computed Parameter: RC_Y0
                                        * Referenced by: '<S456>/RC'
                                        */
  real_T VELOCITA_Y0;                  /* Computed Parameter: VELOCITA_Y0
                                        * Referenced by: '<S456>/VELOCITA'
                                        */
  real_T Out3_Y0_j;                    /* Computed Parameter: Out3_Y0_j
                                        * Referenced by: '<S456>/Out3'
                                        */
  real_T Out4_Y0_e;                    /* Computed Parameter: Out4_Y0_e
                                        * Referenced by: '<S456>/Out4'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S456>/Memory4'
                                        */
  real_T Gain_Gain_hq;                 /* Expression: 180/pi
                                        * Referenced by: '<S557>/Gain'
                                        */
  real_T Gain_Gain_jr;                 /* Expression: 180/pi
                                        * Referenced by: '<S558>/Gain'
                                        */
  real_T Gain_Gain_l2;                 /* Expression: 180/pi
                                        * Referenced by: '<S559>/Gain'
                                        */
  real_T saturatoreV_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S456>/saturatore V'
                                        */
  real_T saturatoreV_LowerSat;         /* Expression: 15
                                        * Referenced by: '<S456>/saturatore V'
                                        */
  real_T saturatoreV1_UpperSat;        /* Expression: 2
                                        * Referenced by: '<S456>/saturatore V1'
                                        */
  real_T saturatoreV1_LowerSat;        /* Expression: -2
                                        * Referenced by: '<S456>/saturatore V1'
                                        */
  real_T Out1_Y0_j;                    /* Computed Parameter: Out1_Y0_j
                                        * Referenced by: '<S457>/Out1'
                                        */
  real_T Out2_Y0_n;                    /* Computed Parameter: Out2_Y0_n
                                        * Referenced by: '<S457>/Out2'
                                        */
  real_T Out3_Y0_e;                    /* Computed Parameter: Out3_Y0_e
                                        * Referenced by: '<S457>/Out3'
                                        */
  real_T Out4_Y0_n;                    /* Computed Parameter: Out4_Y0_n
                                        * Referenced by: '<S457>/Out4'
                                        */
  real_T Gain_Gain_jv;                 /* Expression: 180/pi
                                        * Referenced by: '<S562>/Gain'
                                        */
  real_T Gain_Gain_hc;                 /* Expression: 180/pi
                                        * Referenced by: '<S563>/Gain'
                                        */
  real_T Gain_Gain_pr;                 /* Expression: 180/pi
                                        * Referenced by: '<S564>/Gain'
                                        */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<S571>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol_b;    /* Expression: 0
                                        * Referenced by: '<S571>/Serial Transmit'
                                        */
  real_T Switch2_Threshold_k;          /* Expression: 2
                                        * Referenced by: '<S6>/Switch2'
                                        */
  real_T Constant1_Value_ol;           /* Expression: 16
                                        * Referenced by: '<S582>/Constant1'
                                        */
  real_T Constant5_Value_n;            /* Expression: 8
                                        * Referenced by: '<S582>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S582>/Constant6'
                                        */
  real_T Constant4_Value_l;            /* Expression: 4
                                        * Referenced by: '<S582>/Constant4'
                                        */
  real_T Constant2_Value_av;           /* Expression: 16
                                        * Referenced by: '<S582>/Constant2'
                                        */
  real_T Constant3_Value_c;            /* Expression: 8
                                        * Referenced by: '<S582>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S579>/Serial Receive1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S589>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S589>/h_to_subtract'
                                        */
  real_T Constant_Value_lv;            /* Expression: 1
                                        * Referenced by: '<S589>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2
                                        * Referenced by: '<S589>/Constant1'
                                        */
  real_T Constant3_Value_ct;           /* Expression: 3
                                        * Referenced by: '<S589>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S592>/Outport'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S592>/Memory'
                                        */
  real_T Constant_Value_bh;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant1_Value_op;           /* Expression: 0
                                        * Referenced by: '<S223>/Constant1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S277>/Constant1'
                                        */
  real_T Constant_Value_hx;            /* Expression: 15
                                        * Referenced by: '<S586>/Constant'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.01
                                        * Referenced by: '<S571>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S571>/Gain4'
                                        */
  real_T Gain1_Gain_kg;                /* Expression: pi/180
                                        * Referenced by: '<S565>/Gain1'
                                        */
  real_T Gain_Gain_mz;                 /* Expression: 180/pi
                                        * Referenced by: '<S426>/Gain'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S569>/Gain1'
                                        */
  real_T Gain1_Gain_kd;                /* Expression: pi/180
                                        * Referenced by: '<S570>/Gain1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S567>/Gain1'
                                        */
  real_T Gain1_Gain_kf;                /* Expression: pi/180
                                        * Referenced by: '<S566>/Gain1'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 15
                                        * Referenced by: '<S6>/Switch1'
                                        */
  real_T RateLimiter1_RisingLim;   /* Computed Parameter: RateLimiter1_RisingLim
                                    * Referenced by: '<S6>/Rate Limiter1'
                                    */
  real_T RateLimiter1_FallingLim; /* Computed Parameter: RateLimiter1_FallingLim
                                   * Referenced by: '<S6>/Rate Limiter1'
                                   */
  real_T RateLimiter1_IC;              /* Expression: 0
                                        * Referenced by: '<S6>/Rate Limiter1'
                                        */
  real_T Constant1_Value_fs;           /* Expression: 0
                                        * Referenced by: '<S306>/Constant1'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: pi/180
                                        * Referenced by: '<S568>/Gain1'
                                        */
  real_T RC_default_Value;             /* Expression: 2
                                        * Referenced by: '<S41>/RC_default'
                                        */
  real_T Constant_Value_g;             /* Expression: 70
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant1_Value_cc;           /* Expression: 20
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 5
                                        * Referenced by: '<S43>/Switch'
                                        */
  real_T Gain_Gain_pa;                 /* Expression: 180/pi
                                        * Referenced by: '<S250>/Gain'
                                        */
  real_T Constant_Value_ig;            /* Expression: 360
                                        * Referenced by: '<S198>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 360
                                        * Referenced by: '<S198>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 360
                                        * Referenced by: '<S198>/Constant2'
                                        */
  real_T Switch1_Threshold_b;          /* Expression: -180
                                        * Referenced by: '<S198>/Switch1'
                                        */
  real_T Gain1_Gain_ef;                /* Expression: pi/180
                                        * Referenced by: '<S249>/Gain1'
                                        */
  real_T Switch3_Threshold_d;          /* Expression: 2
                                        * Referenced by: '<S196>/Switch3'
                                        */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S232>/Integrator'
                                      */
  real_T Switch4_Threshold_d;          /* Expression: 2
                                        * Referenced by: '<S196>/Switch4'
                                        */
  real_T Filter_gainval_d;             /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S227>/Filter'
                                        */
  real_T Constant_Value_j;             /* Expression: 70
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Constant_Value_a3;            /* Expression: 0
                                        * Referenced by: '<S309>/Constant'
                                        */
  real_T Constant5_Value_g;            /* Expression: 0
                                        * Referenced by: '<S308>/Constant5'
                                        */
  real_T Constant3_Value_j;            /* Expression: 2
                                        * Referenced by: '<S306>/Constant3'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S403>/Integrator'
                                      */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S286>/Integrator'
                                      */
  real_T HitCrossing_Offset;           /* Expression: 0.3
                                        * Referenced by: '<S252>/Hit  Crossing'
                                        */
  real_T Constant4_Value_d;            /* Expression: 0
                                        * Referenced by: '<S310>/Constant4'
                                        */
  real_T Constant8_Value_p;            /* Expression: 1
                                        * Referenced by: '<S310>/Constant8'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<S310>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S310>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_LowerS_o;/* Expression: 0
                                          * Referenced by: '<S310>/Discrete-Time Integrator'
                                          */
  real_T RateLimiter_RisingLim;     /* Computed Parameter: RateLimiter_RisingLim
                                     * Referenced by: '<S39>/Rate Limiter'
                                     */
  real_T RateLimiter_FallingLim;   /* Computed Parameter: RateLimiter_FallingLim
                                    * Referenced by: '<S39>/Rate Limiter'
                                    */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S39>/Rate Limiter'
                                        */
  real_T DiscreteWashoutFilter_NumCoef[2];/* Expression: [ 1 -1]
                                           * Referenced by: '<S307>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_DenCoef[2];/* Expression: [1 -0.995]
                                           * Referenced by: '<S307>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_InitialSt;/* Expression: 0
                                          * Referenced by: '<S307>/Discrete Washout Filter'
                                          */
  real_T r_rif_Value;                  /* Expression: 0
                                        * Referenced by: '<S39>/r_rif'
                                        */
  real_T Switch2_Threshold_n;          /* Expression: 5
                                        * Referenced by: '<S304>/Switch2'
                                        */
  real_T Switch2_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S317>/Switch2'
                                        */
  real_T Switch2_Threshold_h;          /* Expression: 0
                                        * Referenced by: '<S318>/Switch2'
                                        */
  real_T Constant2_Value_em;           /* Expression: 0
                                        * Referenced by: '<S305>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S305>/Constant1'
                                        */
  real_T Constant2_Value_by;           /* Expression: 0
                                        * Referenced by: '<S45>/Constant2'
                                        */
  real_T Constant_Value_d;             /* Expression: -5
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Integrator_gainval_hq;     /* Computed Parameter: Integrator_gainval_hq
                                     * Referenced by: '<S178>/Integrator'
                                     */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T nDLookupTable_tableData_c[2];/* Expression: [Kp_h_app_max Kp_h_app_min]
                                       * Referenced by: '<S45>/n-D Lookup Table'
                                       */
  real_T nDLookupTable_bp01Data_l[2];  /* Expression: [V_stall*1.2  V_max*0.75]
                                        * Referenced by: '<S45>/n-D Lookup Table'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.046
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.01
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Integrator_gainval_f;       /* Computed Parameter: Integrator_gainval_f
                                      * Referenced by: '<S82>/Integrator'
                                      */
  real_T Filter_gainval_a;             /* Computed Parameter: Filter_gainval_a
                                        * Referenced by: '<S77>/Filter'
                                        */
  real_T Constant15_Value;             /* Expression: 30
                                        * Referenced by: '<S45>/Constant15'
                                        */
  real_T Constant3_Value_f;            /* Expression: 0
                                        * Referenced by: '<S45>/Constant3'
                                        */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S130>/Integrator'
                                      */
  real_T Filter_gainval_d1;            /* Computed Parameter: Filter_gainval_d1
                                        * Referenced by: '<S125>/Filter'
                                        */
  real_T Constant13_Value;             /* Expression: 40
                                        * Referenced by: '<S45>/Constant13'
                                        */
  real_T Constant_Value_at;            /* Expression: 0
                                        * Referenced by: '<S311>/Constant'
                                        */
  real_T Integrator_gainval_e;       /* Computed Parameter: Integrator_gainval_e
                                      * Referenced by: '<S353>/Integrator'
                                      */
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S370>/Gain1'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S29>/Rate Transition'
                                          */
  real_T Constant2_Value_jg;           /* Expression: 0
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T Memory1_InitialCondition_p;   /* Expression: -1
                                        * Referenced by: '<S29>/Memory1'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 4
                                        * Referenced by: '<S29>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Constant1_Value_n0;           /* Expression: 0.02
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Memory_InitialCondition_au;   /* Expression: -0.02
                                        * Referenced by: '<S29>/Memory'
                                        */
  real_T Gain_Gain_cw;                 /* Expression: 100
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_jp[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain_by;                 /* Expression: 1000
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 1000
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T Constant_Value_ex;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant_Value_hxg;           /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant1_Value_fi;           /* Expression: 0
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant2_Value_eu;           /* Expression: 0
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Gain_Gain_dn;                 /* Expression: 10^3
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain_Gain_ds;                 /* Expression: 180/pi
                                        * Referenced by: '<S27>/Gain'
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
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T Gain_Gain_lb;                 /* Expression: 180/pi
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Switch2_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S36>/Switch2'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T USCITAPERCENTUALE_Gain;       /* Expression: 100/9000
                                        * Referenced by: '<S22>/USCITA PERCENTUALE'
                                        */
  real_T Constant_Value_bh2;           /* Expression: 4
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 100
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T Gain_Gain_od;                 /* Expression: 180/pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant2_Value_m;            /* Expression: 90
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Gain_Gain_if;                 /* Expression: 180/pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Gain_Gain_bh;                 /* Expression: 180/pi
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Constant1_Value_p[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Gain_Gain_jrt;                /* Expression: 100
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 4000
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S581>/Delay Input2'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S581>/sample time'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Gain7_Gain;                   /* Expression: 100
                                        * Referenced by: '<S571>/Gain7'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Gain_Gain_nk;                 /* Expression: 180/pi
                                        * Referenced by: '<S572>/Gain'
                                        */
  real_T Gain_Gain_db;                 /* Expression: 180/pi
                                        * Referenced by: '<S573>/Gain'
                                        */
  real_T Gain_Gain_dc;                 /* Expression: 180/pi
                                        * Referenced by: '<S574>/Gain'
                                        */
  real_T Gain_Gain_bk;                 /* Expression: 100
                                        * Referenced by: '<S571>/Gain'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 100
                                        * Referenced by: '<S571>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S571>/Gain3'
                                        */
  real_T Constant1_Value_fu;           /* Expression: 10
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain6_Gain;                   /* Expression: 100
                                        * Referenced by: '<S571>/Gain6'
                                        */
  real_T Gain_Gain_je;                 /* Expression: 180/pi
                                        * Referenced by: '<S428>/Gain'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S277>/ZeroGain'
                                        */
  real_T Constant2_Value_kv;           /* Expression: Ki_AP_rotta
                                        * Referenced by: '<S43>/Constant2'
                                        */
  real_T ZeroGain_Gain_f;              /* Expression: 0
                                        * Referenced by: '<S223>/ZeroGain'
                                        */
  real_T Constant7_Value_i;            /* Expression: 10
                                        * Referenced by: '<S310>/Constant7'
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
                                        * Referenced by: '<S29>/Constant4'
                                        */
  real_T Constant5_Value_a;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant5'
                                        */
  real_T Memory2_InitialCondition_o;   /* Expression: -1
                                        * Referenced by: '<S29>/Memory2'
                                        */
  real_T Switch1_Threshold_ca;         /* Expression: 9
                                        * Referenced by: '<S29>/Switch1'
                                        */
  int32_T Constant_Value_gw;           /* Computed Parameter: Constant_Value_gw
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Out2_Y0_c;                  /* Computed Parameter: Out2_Y0_c
                                        * Referenced by: '<S577>/Out2'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S582>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S588>/T_0'
                                        */
  real32_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S586>/Switch'
                                        */
  real32_T KiAProtta1_Value;           /* Expression: Ki_AP_rotta
                                        * Referenced by: '<S8>/Ki AP rotta1'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S571>/Gain5'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S582>/p'
                                        */
  uint32_T Constant7_Value_h;          /* Computed Parameter: Constant7_Value_h
                                        * Referenced by: '<S582>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S582>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S582>/Constant11'
                                        */
  uint32_T Constant8_Value_e;          /* Computed Parameter: Constant8_Value_e
                                        * Referenced by: '<S582>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S582>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S21>/onboard_control_sensor_present uint32'
                           */
  int16_T Out3_Y0_a;                   /* Computed Parameter: Out3_Y0_a
                                        * Referenced by: '<S577>/Out3'
                                        */
  int16_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S9>/Switch'
                                        */
  int16_T Gain1_Gain_eu;               /* Computed Parameter: Gain1_Gain_eu
                                        * Referenced by: '<S21>/Gain1'
                                        */
  uint16_T Out4_Y0_i;                  /* Computed Parameter: Out4_Y0_i
                                        * Referenced by: '<S577>/Out4'
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
                                * Referenced by: '<S578>/Unit Delay'
                                */
  boolean_T Constant3_Value_ok;        /* Computed Parameter: Constant3_Value_ok
                                        * Referenced by: '<S578>/Constant3'
                                        */
  uint8_T Memory_InitialCondition_af;
                               /* Computed Parameter: Memory_InitialCondition_af
                                * Referenced by: '<S454>/Memory'
                                */
  uint8_T Memory1_InitialCondition_k;
                               /* Computed Parameter: Memory1_InitialCondition_k
                                * Referenced by: '<S454>/Memory1'
                                */
  uint8_T Memory2_InitialCondition_g;
                               /* Computed Parameter: Memory2_InitialCondition_g
                                * Referenced by: '<S454>/Memory2'
                                */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S454>/Memory6'
                                  */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S592>/mario'
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
  uint8_T Memory2_InitialCondition_go[9];
                              /* Computed Parameter: Memory2_InitialCondition_go
                               * Referenced by: '<S1>/Memory2'
                               */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S17>/Type fixed_wing Autopilot generic'
                           */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S571>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S571>/Fine MSG1'
                                        */
  P_One_time_initialization_loa_T One_time_initialization;/* '<S578>/One_time_initialization' */
  P_ResettableSubsystem_load_ar_T ResettableSubsystem_o;/* '<S423>/Resettable Subsystem' */
  P_EnabledSubsystem_load_ardui_T EnabledSubsystem_j;/* '<S423>/Enabled Subsystem' */
  P_ResettableSubsystem_load_ar_T ResettableSubsystem;/* '<S422>/Resettable Subsystem' */
  P_EnabledSubsystem_load_ardui_T EnabledSubsystem_h;/* '<S422>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_load_arduino_v_15_T {
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
extern P_load_arduino_v_15_T load_arduino_v_15_P;

/* Block signals (default storage) */
extern B_load_arduino_v_15_T load_arduino_v_15_B;

/* Block states (default storage) */
extern DW_load_arduino_v_15_T load_arduino_v_15_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_load_arduino_v_15_T load_arduino_v_15_PrevZCX;

/* External data declarations for dependent source files */
extern const uint16_T load_arduino_v_15_U16GND;/* uint16_T ground */

/* External function called from main */
extern void load_arduino_v_15_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void load_arduino_v_15_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void load_arduino_v_15_initialize(void);
extern void load_arduino_v_15_step0(void);
extern void load_arduino_v_15_step1(void);
extern void load_arduino_v_15_step2(void);
extern void load_arduino_v_15_terminate(void);

/* Real-time Model object */
extern RT_MODEL_load_arduino_v_15_T *const load_arduino_v_15_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S195>/Data Type Duplicate' : Unused code path elimination
 * Block '<S195>/Data Type Propagation' : Unused code path elimination
 * Block '<S422>/Display' : Unused code path elimination
 * Block '<S422>/Display1' : Unused code path elimination
 * Block '<S440>/Constant' : Unused code path elimination
 * Block '<S440>/Constant1' : Unused code path elimination
 * Block '<S440>/Switch' : Unused code path elimination
 * Block '<S442>/Constant4' : Unused code path elimination
 * Block '<S442>/Memory' : Unused code path elimination
 * Block '<S442>/Sum' : Unused code path elimination
 * Block '<S443>/Constant' : Unused code path elimination
 * Block '<S443>/Constant1' : Unused code path elimination
 * Block '<S443>/Switch' : Unused code path elimination
 * Block '<S445>/Constant4' : Unused code path elimination
 * Block '<S445>/Memory' : Unused code path elimination
 * Block '<S445>/Sum' : Unused code path elimination
 * Block '<S424>/Switch' : Unused code path elimination
 * Block '<S430>/Abs2' : Unused code path elimination
 * Block '<S581>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S587>/Data Type Duplicate' : Unused code path elimination
 * Block '<S587>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless AP quota' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore beccheggio' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore imbardata' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore rollio' : Unused code path elimination
 * Block '<S8>/Ki AP quota Select' : Unused code path elimination
 * Block '<S8>/Kp AP quota Select' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S571>/Data Type Conversion7' : Eliminate redundant data type conversion
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
 * '<Root>' : 'load_arduino_v_15'
 * '<S1>'   : 'load_arduino_v_15/AIR RX'
 * '<S2>'   : 'load_arduino_v_15/AIR TX'
 * '<S3>'   : 'load_arduino_v_15/AUTOPILOTA'
 * '<S4>'   : 'load_arduino_v_15/Inizializzazioni'
 * '<S5>'   : 'load_arduino_v_15/LED 13-44'
 * '<S6>'   : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE'
 * '<S7>'   : 'load_arduino_v_15/Misure Sensori'
 * '<S8>'   : 'load_arduino_v_15/PARAMETRI SISTEMA DI CONTROLLO'
 * '<S9>'   : 'load_arduino_v_15/RADIOCOMANDO'
 * '<S10>'  : 'load_arduino_v_15/Servi'
 * '<S11>'  : 'load_arduino_v_15/AIR RX/MATLAB Function1'
 * '<S12>'  : 'load_arduino_v_15/AIR RX/MATLAB Function2'
 * '<S13>'  : 'load_arduino_v_15/AIR RX/MATLAB Function3'
 * '<S14>'  : 'load_arduino_v_15/AIR RX/MATLAB Function4'
 * '<S15>'  : 'load_arduino_v_15/AIR TX/Enable '
 * '<S16>'  : 'load_arduino_v_15/AIR TX/GPS'
 * '<S17>'  : 'load_arduino_v_15/AIR TX/Heartbeat'
 * '<S18>'  : 'load_arduino_v_15/AIR TX/IMU & Attidude'
 * '<S19>'  : 'load_arduino_v_15/AIR TX/If_subsystem'
 * '<S20>'  : 'load_arduino_v_15/AIR TX/Servo'
 * '<S21>'  : 'load_arduino_v_15/AIR TX/SystemStatus'
 * '<S22>'  : 'load_arduino_v_15/AIR TX/VFR'
 * '<S23>'  : 'load_arduino_v_15/AIR TX/Waypoints'
 * '<S24>'  : 'load_arduino_v_15/AIR TX/Enable /Chart'
 * '<S25>'  : 'load_arduino_v_15/AIR TX/Enable /Chart/sendbyte'
 * '<S26>'  : 'load_arduino_v_15/AIR TX/GPS/Radians to Degrees'
 * '<S27>'  : 'load_arduino_v_15/AIR TX/GPS/Radians to Degrees1'
 * '<S28>'  : 'load_arduino_v_15/AIR TX/Heartbeat/Alarm set'
 * '<S29>'  : 'load_arduino_v_15/AIR TX/If_subsystem/Subsystem'
 * '<S30>'  : 'load_arduino_v_15/AIR TX/If_subsystem/iflogic_function'
 * '<S31>'  : 'load_arduino_v_15/AIR TX/Servo/Conversione'
 * '<S32>'  : 'load_arduino_v_15/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S33>'  : 'load_arduino_v_15/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S34>'  : 'load_arduino_v_15/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S35>'  : 'load_arduino_v_15/AIR TX/VFR/Radians to Degrees'
 * '<S36>'  : 'load_arduino_v_15/AIR TX/VFR/wrapTo360'
 * '<S37>'  : 'load_arduino_v_15/AIR TX/Waypoints/MATLAB Function'
 * '<S38>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1'
 * '<S39>'  : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
 * '<S40>'  : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1'
 * '<S41>'  : 'load_arduino_v_15/AUTOPILOTA/Subsystem1'
 * '<S42>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
 * '<S43>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
 * '<S44>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
 * '<S45>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
 * '<S46>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
 * '<S47>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
 * '<S48>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
 * '<S49>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
 * '<S50>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
 * '<S51>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
 * '<S52>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
 * '<S53>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
 * '<S54>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
 * '<S55>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
 * '<S56>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
 * '<S57>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
 * '<S58>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
 * '<S59>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
 * '<S60>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
 * '<S61>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
 * '<S62>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
 * '<S63>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
 * '<S64>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
 * '<S65>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
 * '<S66>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
 * '<S67>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
 * '<S68>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
 * '<S69>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
 * '<S70>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
 * '<S71>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
 * '<S72>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
 * '<S73>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
 * '<S74>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
 * '<S75>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
 * '<S76>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
 * '<S77>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
 * '<S78>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
 * '<S79>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
 * '<S80>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
 * '<S81>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
 * '<S82>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
 * '<S83>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
 * '<S84>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
 * '<S85>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
 * '<S86>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
 * '<S87>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
 * '<S88>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
 * '<S89>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
 * '<S90>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
 * '<S91>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
 * '<S92>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
 * '<S93>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
 * '<S94>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
 * '<S95>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
 * '<S96>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
 * '<S97>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
 * '<S98>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
 * '<S99>'  : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
 * '<S100>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
 * '<S101>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
 * '<S102>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
 * '<S103>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
 * '<S104>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
 * '<S105>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
 * '<S106>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
 * '<S107>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
 * '<S108>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
 * '<S109>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
 * '<S110>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
 * '<S111>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
 * '<S112>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
 * '<S113>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
 * '<S114>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
 * '<S115>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
 * '<S116>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
 * '<S117>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
 * '<S118>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
 * '<S119>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
 * '<S120>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
 * '<S121>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
 * '<S122>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
 * '<S123>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
 * '<S124>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
 * '<S125>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
 * '<S126>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
 * '<S127>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
 * '<S128>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
 * '<S129>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
 * '<S130>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
 * '<S131>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
 * '<S132>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
 * '<S133>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
 * '<S134>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
 * '<S135>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
 * '<S136>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
 * '<S137>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
 * '<S138>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
 * '<S139>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
 * '<S140>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
 * '<S141>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
 * '<S142>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
 * '<S143>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
 * '<S144>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
 * '<S145>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
 * '<S146>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
 * '<S147>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
 * '<S148>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
 * '<S149>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
 * '<S150>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
 * '<S151>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
 * '<S152>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
 * '<S153>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
 * '<S154>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
 * '<S155>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
 * '<S156>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
 * '<S157>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
 * '<S158>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
 * '<S159>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
 * '<S160>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
 * '<S161>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
 * '<S162>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
 * '<S163>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
 * '<S164>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
 * '<S165>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
 * '<S166>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
 * '<S167>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
 * '<S168>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
 * '<S169>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
 * '<S170>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
 * '<S171>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
 * '<S172>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
 * '<S173>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
 * '<S174>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
 * '<S175>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
 * '<S176>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
 * '<S177>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
 * '<S178>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
 * '<S179>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
 * '<S180>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
 * '<S181>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
 * '<S182>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
 * '<S183>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
 * '<S184>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
 * '<S185>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
 * '<S186>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
 * '<S187>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
 * '<S188>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
 * '<S189>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
 * '<S190>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
 * '<S191>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
 * '<S192>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
 * '<S193>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
 * '<S194>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
 * '<S195>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
 * '<S196>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
 * '<S197>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
 * '<S198>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
 * '<S199>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
 * '<S200>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
 * '<S201>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
 * '<S202>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
 * '<S203>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
 * '<S204>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
 * '<S205>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
 * '<S206>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
 * '<S207>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
 * '<S208>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
 * '<S209>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
 * '<S210>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
 * '<S211>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
 * '<S212>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
 * '<S213>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
 * '<S214>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
 * '<S215>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
 * '<S216>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
 * '<S217>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
 * '<S218>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
 * '<S219>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
 * '<S220>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
 * '<S221>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
 * '<S222>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
 * '<S223>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S224>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S225>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S226>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
 * '<S227>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S228>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S229>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
 * '<S230>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
 * '<S231>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S232>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
 * '<S233>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
 * '<S234>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
 * '<S235>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
 * '<S236>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
 * '<S237>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
 * '<S238>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
 * '<S239>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
 * '<S240>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
 * '<S241>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
 * '<S242>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
 * '<S243>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
 * '<S244>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S245>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S246>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S247>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
 * '<S248>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
 * '<S249>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
 * '<S250>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
 * '<S251>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
 * '<S252>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
 * '<S253>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
 * '<S254>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
 * '<S255>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
 * '<S256>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
 * '<S257>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
 * '<S258>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
 * '<S259>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
 * '<S260>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
 * '<S261>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
 * '<S262>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
 * '<S263>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
 * '<S264>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
 * '<S265>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
 * '<S266>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
 * '<S267>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
 * '<S268>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
 * '<S269>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
 * '<S270>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
 * '<S271>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
 * '<S272>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
 * '<S273>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
 * '<S274>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
 * '<S275>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
 * '<S276>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
 * '<S277>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S278>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S279>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S280>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
 * '<S281>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
 * '<S282>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
 * '<S283>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
 * '<S284>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
 * '<S285>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S286>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
 * '<S287>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
 * '<S288>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S289>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
 * '<S290>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
 * '<S291>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
 * '<S292>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
 * '<S293>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
 * '<S294>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
 * '<S295>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
 * '<S296>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
 * '<S297>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
 * '<S298>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S299>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
 * '<S300>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S301>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
 * '<S302>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
 * '<S303>' : 'load_arduino_v_15/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
 * '<S304>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA'
 * '<S305>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
 * '<S306>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
 * '<S307>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
 * '<S308>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/alettoni - landing1'
 * '<S309>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/alettoni - takeoff'
 * '<S310>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
 * '<S311>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/theta - takeoff'
 * '<S312>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Radians to Degrees'
 * '<S313>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Radians to Degrees1'
 * '<S314>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Radians to Degrees2'
 * '<S315>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem2'
 * '<S316>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem3'
 * '<S317>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem4'
 * '<S318>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem5'
 * '<S319>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
 * '<S320>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
 * '<S321>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
 * '<S322>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
 * '<S323>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
 * '<S324>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
 * '<S325>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
 * '<S326>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
 * '<S327>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
 * '<S328>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
 * '<S329>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
 * '<S330>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
 * '<S331>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
 * '<S332>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
 * '<S333>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
 * '<S334>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
 * '<S335>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
 * '<S336>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
 * '<S337>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
 * '<S338>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
 * '<S339>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
 * '<S340>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
 * '<S341>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
 * '<S342>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
 * '<S343>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
 * '<S344>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
 * '<S345>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
 * '<S346>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
 * '<S347>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
 * '<S348>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
 * '<S349>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
 * '<S350>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
 * '<S351>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S352>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S353>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
 * '<S354>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
 * '<S355>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S356>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
 * '<S357>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
 * '<S358>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
 * '<S359>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
 * '<S360>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
 * '<S361>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S362>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
 * '<S363>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
 * '<S364>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
 * '<S365>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S366>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S367>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S368>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
 * '<S369>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
 * '<S370>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
 * '<S371>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
 * '<S372>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
 * '<S373>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
 * '<S374>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
 * '<S375>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
 * '<S376>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
 * '<S377>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
 * '<S378>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
 * '<S379>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
 * '<S380>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
 * '<S381>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
 * '<S382>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
 * '<S383>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
 * '<S384>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
 * '<S385>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
 * '<S386>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
 * '<S387>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
 * '<S388>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
 * '<S389>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
 * '<S390>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
 * '<S391>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
 * '<S392>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
 * '<S393>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
 * '<S394>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
 * '<S395>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
 * '<S396>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
 * '<S397>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
 * '<S398>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
 * '<S399>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
 * '<S400>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
 * '<S401>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
 * '<S402>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S403>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
 * '<S404>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
 * '<S405>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S406>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
 * '<S407>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
 * '<S408>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
 * '<S409>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
 * '<S410>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
 * '<S411>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
 * '<S412>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
 * '<S413>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
 * '<S414>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
 * '<S415>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S416>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
 * '<S417>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S418>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
 * '<S419>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
 * '<S420>' : 'load_arduino_v_15/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/theta - takeoff/Degrees to Radians'
 * '<S421>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
 * '<S422>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
 * '<S423>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
 * '<S424>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
 * '<S425>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
 * '<S426>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
 * '<S427>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
 * '<S428>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
 * '<S429>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
 * '<S430>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
 * '<S431>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
 * '<S432>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
 * '<S433>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
 * '<S434>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
 * '<S435>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
 * '<S436>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
 * '<S437>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
 * '<S438>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
 * '<S439>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
 * '<S440>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
 * '<S441>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
 * '<S442>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
 * '<S443>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
 * '<S444>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
 * '<S445>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
 * '<S446>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
 * '<S447>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
 * '<S448>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
 * '<S449>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
 * '<S450>' : 'load_arduino_v_15/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
 * '<S451>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Chart'
 * '<S452>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
 * '<S453>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/MATLAB Function'
 * '<S454>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem'
 * '<S455>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1'
 * '<S456>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem2'
 * '<S457>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem3'
 * '<S458>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
 * '<S459>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
 * '<S460>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees2'
 * '<S461>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
 * '<S462>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
 * '<S463>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
 * '<S464>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
 * '<S465>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
 * '<S466>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
 * '<S467>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
 * '<S468>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
 * '<S469>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
 * '<S470>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
 * '<S471>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
 * '<S472>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
 * '<S473>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
 * '<S474>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
 * '<S475>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
 * '<S476>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
 * '<S477>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
 * '<S478>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
 * '<S479>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
 * '<S480>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
 * '<S481>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
 * '<S482>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
 * '<S483>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
 * '<S484>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
 * '<S485>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
 * '<S486>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
 * '<S487>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
 * '<S488>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
 * '<S489>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
 * '<S490>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
 * '<S491>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
 * '<S492>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
 * '<S493>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
 * '<S494>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
 * '<S495>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
 * '<S496>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
 * '<S497>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
 * '<S498>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
 * '<S499>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
 * '<S500>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
 * '<S501>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
 * '<S502>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
 * '<S503>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
 * '<S504>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
 * '<S505>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
 * '<S506>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
 * '<S507>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
 * '<S508>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
 * '<S509>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
 * '<S510>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
 * '<S511>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
 * '<S512>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
 * '<S513>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/External Parameters'
 * '<S514>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S515>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S516>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
 * '<S517>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
 * '<S518>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S519>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
 * '<S520>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
 * '<S521>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled'
 * '<S522>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/External Parameters'
 * '<S523>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
 * '<S524>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
 * '<S525>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
 * '<S526>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
 * '<S527>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
 * '<S528>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PID'
 * '<S529>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
 * '<S530>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
 * '<S531>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S532>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
 * '<S533>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S534>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
 * '<S535>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
 * '<S536>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
 * '<S537>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
 * '<S538>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
 * '<S539>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
 * '<S540>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
 * '<S541>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
 * '<S542>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S543>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S544>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S545>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S546>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
 * '<S547>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
 * '<S548>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
 * '<S549>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
 * '<S550>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S551>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
 * '<S552>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
 * '<S553>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
 * '<S554>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
 * '<S555>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
 * '<S556>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
 * '<S557>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
 * '<S558>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
 * '<S559>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
 * '<S560>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
 * '<S561>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
 * '<S562>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
 * '<S563>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
 * '<S564>' : 'load_arduino_v_15/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
 * '<S565>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
 * '<S566>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
 * '<S567>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
 * '<S568>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S569>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/Degrees to Radians4'
 * '<S570>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/Degrees to Radians5'
 * '<S571>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry'
 * '<S572>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees'
 * '<S573>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees1'
 * '<S574>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees2'
 * '<S575>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1'
 * '<S576>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function'
 * '<S577>' : 'load_arduino_v_15/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem2'
 * '<S578>' : 'load_arduino_v_15/Misure Sensori/BMP_280'
 * '<S579>' : 'load_arduino_v_15/Misure Sensori/GPS_Venus'
 * '<S580>' : 'load_arduino_v_15/Misure Sensori/X-Sense MTi'
 * '<S581>' : 'load_arduino_v_15/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S582>' : 'load_arduino_v_15/Misure Sensori/BMP_280/Execution_loop'
 * '<S583>' : 'load_arduino_v_15/Misure Sensori/BMP_280/MATLAB Function'
 * '<S584>' : 'load_arduino_v_15/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S585>' : 'load_arduino_v_15/Misure Sensori/BMP_280/One_time_initialization'
 * '<S586>' : 'load_arduino_v_15/Misure Sensori/BMP_280/Subsystem'
 * '<S587>' : 'load_arduino_v_15/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S588>' : 'load_arduino_v_15/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S589>' : 'load_arduino_v_15/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S590>' : 'load_arduino_v_15/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S591>' : 'load_arduino_v_15/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S592>' : 'load_arduino_v_15/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S593>' : 'load_arduino_v_15/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S594>' : 'load_arduino_v_15/RADIOCOMANDO/AILERON'
 * '<S595>' : 'load_arduino_v_15/RADIOCOMANDO/ELEVATOR'
 * '<S596>' : 'load_arduino_v_15/RADIOCOMANDO/RUDDER'
 * '<S597>' : 'load_arduino_v_15/RADIOCOMANDO/THROTTLE'
 * '<S598>' : 'load_arduino_v_15/Servi/AILERON1'
 * '<S599>' : 'load_arduino_v_15/Servi/RUDDER6'
 * '<S600>' : 'load_arduino_v_15/Servi/THROTTLE1'
 * '<S601>' : 'load_arduino_v_15/Servi/elevator'
 */
#endif                                 /* RTW_HEADER_load_arduino_v_15_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
