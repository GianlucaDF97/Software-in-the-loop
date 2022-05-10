/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_13.h
 *
 * Code generated for Simulink model 'load_arduino_v_13'.
 *
 * Model version                  : 1.330
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov  5 15:54:12 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_load_arduino_v_13_h_
#define RTW_HEADER_load_arduino_v_13_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef load_arduino_v_13_COMMON_INCLUDES_
# define load_arduino_v_13_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#include "MW_SerialRead.h"
#include "MW_I2C.h"
#endif                                 /* load_arduino_v_13_COMMON_INCLUDES_ */

#include "load_arduino_v_13_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S750>/Resettable Subsystem' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S761>/Memory' */
} DW_ResettableSubsystem_load_a_T;

/* Zero-crossing (trigger) state for system '<S750>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_f;/* '<S750>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_load__T;

/* Block signals for system '<S963>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S971>/Byte Unpack' */
  uint16_T I2CRead;                    /* '<S971>/I2C Read' */
  uint16_T I2CRead3;                   /* '<S971>/I2C Read3' */
  int16_T I2CRead1;                    /* '<S971>/I2C Read1' */
  int16_T I2CRead2;                    /* '<S971>/I2C Read2' */
  int16_T I2CRead4;                    /* '<S971>/I2C Read4' */
  int16_T I2CRead5;                    /* '<S971>/I2C Read5' */
  int16_T I2CRead6;                    /* '<S971>/I2C Read6' */
  int16_T I2CRead7;                    /* '<S971>/I2C Read7' */
  int16_T I2CRead8;                    /* '<S971>/I2C Read8' */
  int16_T I2CRead9;                    /* '<S971>/I2C Read9' */
  int16_T I2CRead10;                   /* '<S971>/I2C Read10' */
  int16_T I2CRead11;                   /* '<S971>/I2C Read11' */
  uint8_T I2CRead12[16];               /* '<S971>/I2C Read12' */
} B_One_time_initialization_loa_T;

/* Block states (default storage) for system '<S963>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_int_b_T obj; /* '<S971>/I2C Read' */
  codertarget_arduinobase_int_b_T obj_o;/* '<S971>/I2C Read1' */
  codertarget_arduinobase_int_b_T obj_d;/* '<S971>/I2C Read2' */
  codertarget_arduinobase_int_b_T obj_k;/* '<S971>/I2C Read3' */
  codertarget_arduinobase_int_b_T obj_c;/* '<S971>/I2C Read4' */
  codertarget_arduinobase_int_b_T obj_kn;/* '<S971>/I2C Read5' */
  codertarget_arduinobase_int_b_T obj_b;/* '<S971>/I2C Read6' */
  codertarget_arduinobase_int_b_T obj_cn;/* '<S971>/I2C Read7' */
  codertarget_arduinobase_int_b_T obj_i;/* '<S971>/I2C Read8' */
  codertarget_arduinobase_int_b_T obj_h;/* '<S971>/I2C Read9' */
  codertarget_arduinobase_int_b_T obj_d0;/* '<S971>/I2C Read10' */
  codertarget_arduinobase_int_b_T obj_l;/* '<S971>/I2C Read11' */
  codertarget_arduinobase_int_b_T obj_ir;/* '<S971>/I2C Read12' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S971>/I2C Write1' */
  codertarget_arduinobase_int_m_T obj_in;/* '<S971>/I2C Write2' */
  codertarget_arduinobase_int_m_T obj_d01;/* '<S971>/I2C Write3' */
} DW_One_time_initialization_lo_T;

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion4_m[42];    /* '<S782>/Data Type Conversion4' */
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  real_T WP_param_c[21];               /* '<S795>/AUTOLANDING_WAYPOINTS' */
  real_T dv0[16];
  real_T dv1[16];
  real_T A[16];
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_b[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio_k[80];
  int8_T comma_gga_data[80];
  int8_T star_data[80];
  boolean_T b_x[80];
  int8_T c_ii_data[80];
  uint8_T messaggio_c[80];             /* '<S976>/Create_message' */
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S978>/Complex to Real-Imag' */
  real_T DataTypeConversion1_b[9];     /* '<S7>/Data Type Conversion1' */
  uint8_T dataIn[63];
  real_T DataTypeConversion5[4];
  uint8_T data[32];
  uint8_T data_p[31];
  real_T lat_end[3];                   /* '<S795>/MATLAB Function' */
  real32_T AGAC[4];                    /* '<S22>/Data Type Conversion' */
  real_T Gain4[2];
  creal_T Lat_1;
  creal_T c_x;
  char_T hex_checksum_data[13];
  char_T hex_checksum_data_c[13];
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  uint16_T WP_info[6];                 /* '<S23>/MATLAB Function' */
  uint16_T WP_info_in[6];
  real_T Switch;                       /* '<S975>/Switch' */
  real_T h_goHome;                     /* '<S784>/GO_HOME' */
  real_T rotta_goHome;                 /* '<S784>/GO_HOME' */
  real_T QUOTA;                        /* '<S783>/WAYPOINTS' */
  real_T ROTTA;                        /* '<S783>/WAYPOINTS' */
  real_T Gain;                         /* '<S800>/Gain' */
  real_T Gain_g;                       /* '<S801>/Gain' */
  real_T QUOTA_m;                      /* '<S782>/Switch di selezione  Task - Waypoint navigation4' */
  real_T Switch1;                      /* '<S782>/Switch1' */
  real_T In[2];                        /* '<S807>/In' */
  real_T Gain_p;                       /* '<S815>/Gain' */
  real_T Sum2;                         /* '<S797>/Sum2' */
  real_T maneuver_selector;            /* '<S782>/Chart1' */
  real_T trig_approach;                /* '<S782>/Chart1' */
  real_T trig_flare;                   /* '<S782>/Chart1' */
  real_T approach_selector;            /* '<S782>/Chart1' */
  real_T h_Home;                       /* '<S782>/CALIBRATING_HOME_COORDINATES' */
  real_T Multiply;                     /* '<S793>/Multiply' */
  real_T x_f_out;                      /* '<S793>/MATLAB Function' */
  real_T h_f_out;                      /* '<S793>/MATLAB Function' */
  real_T k_x_out;                      /* '<S793>/MATLAB Function' */
  real_T h_c_out;                      /* '<S793>/MATLAB Function' */
  real_T no_solution;                  /* '<S793>/MATLAB Function' */
  real_T h_vett;                       /* '<S781>/VETTORIALE' */
  real_T rotta_vett;                   /* '<S781>/VETTORIALE' */
  real_T In_k;                         /* '<S788>/In' */
  real_T Fase_ATO;                     /* '<S780>/Chart1' */
  real_T manetta_ref;                  /* '<S780>/Chart1' */
  real_T psi_ref;                      /* '<S780>/Chart1' */
  real_T eq_rot;                       /* '<S780>/Chart1' */
  real_T h_ref;                        /* '<S780>/Chart1' */
  real_T psi_ref_selector;             /* '<S780>/Chart1' */
  real_T theta_ground_selector;        /* '<S780>/Chart1' */
  real_T Switch_n;                     /* '<S776>/Switch' */
  real_T Switch_l;                     /* '<S762>/Switch' */
  real_T switch_manetta;               /* '<S40>/ STATI' */
  real_T switch_equilibratore;         /* '<S40>/ STATI' */
  real_T switch_alettoni;              /* '<S40>/ STATI' */
  real_T switch_timone;                /* '<S40>/ STATI' */
  real_T modo;                         /* '<S40>/ STATI' */
  real_T n;                            /* '<S15>/Chart' */
  real_T denAccum;
  real_T checksum;
  real_T r;
  real_T a;
  real_T psi_ref_n;
  real_T dist;
  real_T dist_fut;
  real_T angoloWP;
  real_T psi_ref_pre;
  real_T err;
  real_T f_x;
  real_T IProdOut_b;                   /* '<S598>/IProd Out' */
  real_T PWM_rudder_p;                 /* '<S9>/Data Type Conversion' */
  real_T Gain1_c;                      /* '<S945>/Gain1' */
  real_T Gain1_a;                      /* '<S944>/Gain1' */
  real_T Gain1_l;                      /* '<S943>/Gain1' */
  real_T Saturation_f;                 /* '<S728>/Saturation' */
  real_T Sum1_lg;                      /* '<S39>/Sum1' */
  real_T Sum4_n;                       /* '<S985>/Sum4' */
  real_T Sum_n3;                       /* '<S736>/Sum' */
  real_T Sum3_o;                       /* '<S983>/Sum3' */
  real_T Gain1_k;                      /* '<S946>/Gain1' */
  real_T Abs1_b;                       /* '<S916>/Abs1' */
  real_T Switch_bk;                    /* '<S925>/Switch' */
  real_T Abs1;                         /* '<S922>/Abs1' */
  real_T Abs_o;                        /* '<S793>/Abs' */
  real_T Gain_a;                       /* '<S933>/Gain' */
  real_T Gain_pq;                      /* '<S934>/Gain' */
  real_T Gain_k3;                      /* '<S804>/Gain' */
  real_T Gain_n;                       /* '<S805>/Gain' */
  real_T Long_Home;                    /* '<S782>/CALIBRATING_HOME_COORDINATES' */
  real_T Gain_o;                       /* '<S35>/Gain' */
  real_T Gain1_p;                      /* '<S949>/Gain1' */
  real_T Gain1_f;                      /* '<S948>/Gain1' */
  real_T Alettoni;                     /* '<S39>/saturatore A' */
  real_T Product1;
  real_T Al_selector;
  real_T Wp_selector;
  real_T Go_Home;
  real_T rtb_Gain1_kw_idx_1;
  real_T rtb_Gain1_kw_idx_0;
  real_T rtb_long_end_tmp;
  real_T b_x_tmp;
  real_T psi_ref_tmp;
  real_T a_fut_tmp;
  real_T long_comandato_tmp;
  real_T rtb_Sum4_n_tmp;
  real_T rtb_Sum4_n_tmp_j;
  real_T smax;
  real_T s;
  real_T scanned1;
  real_T b_scanned1;
  real_T scanned2;
  real_T scanned1_d;
  real_T b_scanned1_g;
  real_T scanned2_l;
  real_T b_scanned1_d;
  real_T scanned2_d;
  real_T b_scanned1_l;
  real_T scanned2_o;
  int32_T messaggio_size[2];
  int32_T messaggio_size_f[2];
  int32_T messaggio_size_g[2];
  int32_T messaggio_size_g1[2];
  int32_T messaggio_size_m[2];
  boolean_T mess_type_b[5];
  char_T mess_type[5];
  char_T s1[5];
  int8_T p[4];
  int8_T ipiv[4];
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion_l;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion4[4];     /* '<S947>/Data Type Conversion4' */
  real32_T T;                          /* '<S974>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S968>/S-Function Builder' */
  real32_T ByteUnpack_o2_e[4];         /* '<S961>/Byte Unpack' */
  real32_T WP_param[7];                /* '<S23>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T f0;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_a[4];     /* '<S16>/Data Type Conversion' */
  int32_T DataTypeConversion1_i;       /* '<S968>/Data Type  Conversion1' */
  int32_T DataTypeConversion_ay;       /* '<S968>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_a;       /* '<S968>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  int32_T firstcol;
  int32_T caso;
  int32_T AL;
  int32_T tolleranza_distWP_fut;
  int32_T soglia_dist;
  int32_T i;
  int32_T b_j;
  int32_T ix;
  int32_T b_k;
  int32_T b_ix;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T idx;
  int32_T ntoread;
  int32_T loop_ub;
  int32_T b_idx;
  int32_T b_k_b;
  int32_T idx_l;
  int32_T ntoread_h;
  int32_T c_k;
  int32_T h_idx;
  int32_T b_idx_b;
  int32_T b_k_d;
  int32_T idx_e;
  int32_T ntoread_b;
  int32_T c_k_j;
  int32_T b_k_f;
  int32_T idx_a;
  int32_T ntoread_j;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S19>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S17>/Data Type Conversion' */
  uint32_T DataTypeConversion8;        /* '<S947>/Data Type Conversion8' */
  uint32_T SFunctionBuilder1;          /* '<S968>/S-Function Builder1' */
  real32_T ByteUnpack_o2[9];           /* '<S965>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S965>/Byte Reversal' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T Switch1_g;                  /* '<S972>/Switch1' */
  real32_T DataTypeConversion1[6];     /* '<S18>/Data Type Conversion1' */
  uint32_T qY;
  uint32_T qY_tmp;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  char_T s1_n[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2_h;      /* '<S16>/Data Type Conversion2' */
  uint16_T Throttle;                   /* '<S22>/Data Type Conversion2' */
  uint16_T Heading[9];                 /* '<S20>/Data Type Conversion1' */
  uint16_T Memory_a;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion1_h[10];  /* '<S947>/Data Type Conversion1' */
  uint16_T ByteUnpack_o4[2];           /* '<S961>/Byte Unpack' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T Gain1;                       /* '<S21>/Gain1' */
  int16_T DataTypeConversion_ld[9];    /* '<S18>/Data Type Conversion' */
  int16_T DataTypeConversion1_p[3];    /* '<S16>/Data Type Conversion1' */
  int16_T Heading_g;                   /* '<S22>/Data Type Conversion1' */
  int16_T SFunctionBuilder2;           /* '<S9>/S-Function Builder2' */
  int16_T PWM_throttle;                /* '<S9>/S-Function Builder6' */
  int16_T PWM_elevator;                /* '<S9>/S-Function Builder1' */
  int16_T PWM_aileron;                 /* '<S9>/S-Function Builder7' */
  int16_T PWM_rudder;                  /* '<S9>/S-Function Builder8' */
  int16_T DataTypeConversion2_m;       /* '<S2>/Data Type Conversion2' */
  int16_T DataTypeConversion_lx[9];    /* '<S947>/Data Type Conversion' */
  int16_T DataTypeConversion_p;        /* '<S10>/Data Type Conversion' */
  int16_T DataTypeConversion1_c;       /* '<S10>/Data Type Conversion1' */
  int16_T DataTypeConversion2_j;       /* '<S10>/Data Type Conversion2' */
  int16_T Sum;                         /* '<S989>/Sum' */
  int16_T ByteUnpack_o3[4];            /* '<S961>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1_n[41];   /* '<S965>/S-Function Builder' */
  uint8_T SFunctionBuilder_o2_f;       /* '<S965>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S965>/Byte Unpack' */
  uint8_T ByteUnpack_o3_p;             /* '<S965>/Byte Unpack' */
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
  uint8_T BytePack[63];                /* '<S947>/Byte Pack' */
  uint8_T Mex_out[41];                 /* '<S965>/MATLAB Function1' */
  uint8_T indice_dimario;              /* '<S978>/MATLAB Function' */
  uint8_T ByteUnpack_o1_o[2];          /* '<S961>/Byte Unpack' */
  uint8_T ByteUnpack_o5;               /* '<S961>/Byte Unpack' */
  uint8_T messaggio[31];               /* '<S955>/MATLAB Function' */
  uint8_T iflogic;                     /* '<S19>/iflogic_function' */
  uint8_T bt[264];                     /* '<S15>/Chart' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  uint8_T AP_int[9];                   /* '<S1>/MATLAB Function1' */
  int8_T B_Remaining;                  /* '<S21>/Data Type Conversion3' */
  B_One_time_initialization_loa_T One_time_initialization;/* '<S963>/One_time_initialization' */
} B_load_arduino_v_13_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_js_T obj; /* '<S947>/Serial Transmit' */
  codertarget_arduinobase_in_js_T obj_o;/* '<S25>/Serial Transmit' */
  codertarget_arduinobase_int_b_T obj_f;/* '<S968>/I2C Read12' */
  codertarget_arduinobase_int_b_T obj_p;/* '<S968>/I2C Read1' */
  codertarget_arduinobase_block_T obj_l;/* '<S942>/Digital Output' */
  codertarget_arduinobase_block_T obj_c;/* '<S941>/Digital Output' */
  real_T SFunctionBuilder_DSTATE;      /* '<S965>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_l;    /* '<S1>/S-Function Builder' */
  real_T UnitDelay_DSTATE;             /* '<S956>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S544>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S609>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S707>/Integrator' */
  real_T DiscreteWashoutFilter_states; /* '<S543>/Discrete Washout Filter' */
  real_T DelayInput2_DSTATE;           /* '<S967>/Delay Input2' */
  real_T SFunctionBuilder10_DSTATE;    /* '<S10>/S-Function Builder10' */
  real_T SFunctionBuilder4_DSTATE;     /* '<S10>/S-Function Builder4' */
  real_T SFunctionBuilder5_DSTATE;     /* '<S10>/S-Function Builder5' */
  real_T SFunctionBuilder9_DSTATE;     /* '<S10>/S-Function Builder9' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S4>/S-Function Builder' */
  real_T Integrator_DSTATE_h;          /* '<S870>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S793>/Discrete-Time Integrator' */
  volatile real_T RateTransition_Buffer0;/* '<S29>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S29>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S29>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S29>/Memory2' */
  real_T Memory_PreviousInput_l[9];    /* '<S978>/Memory' */
  real_T P_ref;                        /* '<S963>/MATLAB Function' */
  real_T rl_up;                        /* '<S963>/MATLAB Function' */
  real_T rl_dw;                        /* '<S963>/MATLAB Function' */
  real_T flag;                         /* '<S784>/GO_HOME' */
  real_T Memory4_PreviousInput;        /* '<S783>/Memory4' */
  real_T flag_n;                       /* '<S783>/WAYPOINTS' */
  real_T lat1;                         /* '<S783>/WAYPOINTS' */
  real_T long1;                        /* '<S783>/WAYPOINTS' */
  real_T Memory7_PreviousInput;        /* '<S782>/Memory7' */
  real_T Memory5_PreviousInput;        /* '<S782>/Memory5' */
  real_T Memory1_PreviousInput_l;      /* '<S782>/Memory1' */
  real_T Memory2_PreviousInput_f;      /* '<S782>/Memory2' */
  real_T x[4];                         /* '<S793>/MATLAB Function' */
  real_T cycle_count;                  /* '<S793>/MATLAB Function' */
  real_T eps[4];                       /* '<S793>/MATLAB Function' */
  real_T flag_m;                       /* '<S782>/ALLINEAMENTO' */
  real_T Memory3_PreviousInput;        /* '<S781>/Memory3' */
  real_T ALT_ref;                      /* '<S781>/VETTORIALE' */
  real_T HDG_ref;                      /* '<S781>/VETTORIALE' */
  real_T Memory_PreviousInput_i;       /* '<S780>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S780>/Memory1' */
  real_T alarm;                        /* '<S757>/MATLAB Function1' */
  real_T Memory_PreviousInput_h;       /* '<S778>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  codertarget_arduinobase_int_j_T obj_e;/* '<S964>/Serial Receive1' */
  codertarget_arduinobase_int_j_T obj_m;/* '<S947>/Serial Receive' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S5>/Pulse Generator1' */
  uint16_T Memory_PreviousInput_ic[8]; /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  uint8_T Delay_DSTATE[41];            /* '<S965>/Delay' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S963>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S544>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S707>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S793>/Discrete-Time Integrator' */
  uint8_T Memory4_PreviousInput_c[300];/* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput_l[100];/* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_d[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_h5[4];  /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput_o;     /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S976>/Create_message' */
  uint8_T counter_a;                   /* '<S976>/Create_message' */
  uint8_T message_a[31];               /* '<S955>/MATLAB Function' */
  uint8_T counter_i;                   /* '<S955>/MATLAB Function' */
  uint8_T is_active_c10_load_arduino_v_13;/* '<S782>/Chart1' */
  uint8_T is_c10_load_arduino_v_13;    /* '<S782>/Chart1' */
  uint8_T Memory_PreviousInput_b;      /* '<S781>/Memory' */
  uint8_T Memory1_PreviousInput_h;     /* '<S781>/Memory1' */
  uint8_T Memory6_PreviousInput;       /* '<S781>/Memory6' */
  uint8_T is_active_c1_load_arduino_v_13;/* '<S780>/Chart1' */
  uint8_T is_c1_load_arduino_v_13;     /* '<S780>/Chart1' */
  uint8_T temporalCounter_i1;          /* '<S780>/Chart1' */
  uint8_T is_active_c21_load_arduino_v_13;/* '<S41>/Chart' */
  uint8_T is_c21_load_arduino_v_13;    /* '<S41>/Chart' */
  uint8_T is_active_c26_load_arduino_v_13;/* '<S40>/ STATI' */
  uint8_T is_c26_load_arduino_v_13;    /* '<S40>/ STATI' */
  uint8_T is_AUTOMATICA;               /* '<S40>/ STATI' */
  uint8_T is_active_c23_load_arduino_v_13;/* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_c23_load_arduino_v_13;    /* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_active_c9_load_arduino_v_13;/* '<S15>/Chart' */
  uint8_T i;                           /* '<S15>/Chart' */
  uint8_T message_m[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_m;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S976>/Create_message' */
  boolean_T end_found;                 /* '<S976>/Create_message' */
  boolean_T start_found_i;             /* '<S955>/MATLAB Function' */
  boolean_T x_not_empty;               /* '<S793>/MATLAB Function' */
  boolean_T x_new_not_empty;           /* '<S793>/MATLAB Function' */
  boolean_T cycle_count_not_empty;     /* '<S793>/MATLAB Function' */
  boolean_T eps_not_empty;             /* '<S793>/MATLAB Function' */
  boolean_T Tf_not_empty;              /* '<S752>/MATLAB Function1' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T Enabled_MODE;              /* '<S774>/Enabled ' */
  boolean_T Enabled_MODE_p;            /* '<S766>/Enabled ' */
  boolean_T Enabled_MODE_m;            /* '<S765>/Enabled ' */
  DW_One_time_initialization_lo_T One_time_initialization;/* '<S963>/One_time_initialization' */
  DW_ResettableSubsystem_load_a_T ResettableSubsystem_o;/* '<S751>/Resettable Subsystem' */
  DW_ResettableSubsystem_load_a_T ResettableSubsystem;/* '<S750>/Resettable Subsystem' */
} DW_load_arduino_v_13_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S782>/Sample and Hold' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S780>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE_h; /* '<S780>/Sample and Hold' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S774>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_h;/* '<S766>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_p;/* '<S765>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_load__T ResettableSubsystem_o;/* '<S751>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_load__T ResettableSubsystem;/* '<S750>/Resettable Subsystem' */
} PrevZCX_load_arduino_v_13_T;

/* Parameters for system: '<S750>/Enabled Subsystem' */
struct P_EnabledSubsystem_load_ardui_T_ {
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S759>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S759>/Constant1'
                                        */
  real_T u0_Y0;                        /* Computed Parameter: u0_Y0
                                        * Referenced by: '<S759>/1//0'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S759>/Switch'
                                        */
};

/* Parameters for system: '<S750>/Resettable Subsystem' */
struct P_ResettableSubsystem_load_ar_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S761>/Memory'
                                        */
};

/* Parameters for system: '<S963>/One_time_initialization' */
struct P_One_time_initialization_loa_T_ {
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S971>/Bitwise Operator1'
                                        */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S971>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S971>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S971>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S971>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S971>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S971>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S971>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S971>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S971>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S971>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S971>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S971>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S971>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S971>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value;     /* Computed Parameter: registromemoria2_Value
                                        * Referenced by: '<S971>/registro memoria2 '
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S971>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S971>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_load_arduino_v_13_T_ {
  real_T Kp_Rotta_psi;                 /* Variable: Kp_Rotta_psi
                                        * Referenced by:
                                        *   '<S540>/Constant3'
                                        *   '<S540>/Constant4'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S39>/saturatore A'
                                        *   '<S39>/saturatore A1'
                                        *   '<S981>/Constant8'
                                        *   '<S987>/Constant'
                                        *   '<S728>/Saturation'
                                        */
  real_T attuatore_Amin;               /* Variable: attuatore_Amin
                                        * Referenced by:
                                        *   '<S39>/saturatore A'
                                        *   '<S39>/saturatore A1'
                                        *   '<S981>/Constant9'
                                        *   '<S987>/Constant1'
                                        *   '<S728>/Saturation'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S983>/Constant8'
                                        *   '<S990>/Constant'
                                        *   '<S541>/saturatore E2'
                                        *   '<S630>/Saturation'
                                        */
  real_T attuatore_Emin;               /* Variable: attuatore_Emin
                                        * Referenced by:
                                        *   '<S983>/Constant9'
                                        *   '<S990>/Constant1'
                                        *   '<S541>/saturatore E2'
                                        *   '<S630>/Saturation'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S39>/saturatore R'
                                        *   '<S985>/Constant8'
                                        *   '<S988>/Constant'
                                        */
  real_T attuatore_Rmin;               /* Variable: attuatore_Rmin
                                        * Referenced by:
                                        *   '<S39>/saturatore R'
                                        *   '<S985>/Constant9'
                                        *   '<S988>/Constant1'
                                        */
  real_T attuatore_Tmax;               /* Variable: attuatore_Tmax
                                        * Referenced by: '<S986>/manetta_massima'
                                        */
  real_T attuatore_Tmin;               /* Variable: attuatore_Tmin
                                        * Referenced by: '<S986>/manetta_minima'
                                        */
  real_T interventoA_05;               /* Variable: interventoA_05
                                        * Referenced by: '<S752>/Constant4'
                                        */
  real_T interventoA_1;                /* Variable: interventoA_1
                                        * Referenced by: '<S752>/Constant3'
                                        */
  real_T interventoE_05;               /* Variable: interventoE_05
                                        * Referenced by: '<S752>/Constant1'
                                        */
  real_T interventoE_1;                /* Variable: interventoE_1
                                        * Referenced by: '<S752>/Constant'
                                        */
  real_T interventoT;                  /* Variable: interventoT
                                        * Referenced by: '<S752>/Constant2'
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
  real_T phi_max;                      /* Variable: phi_max
                                        * Referenced by: '<S982>/Constant8'
                                        */
  real_T phi_min;                      /* Variable: phi_min
                                        * Referenced by: '<S982>/Constant9'
                                        */
  real_T safe_V;                       /* Variable: safe_V
                                        * Referenced by: '<S757>/Constant'
                                        */
  real_T safe_phi;                     /* Variable: safe_phi
                                        * Referenced by: '<S757>/Constant1'
                                        */
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S968>/I2C Read1'
                                        *   '<S968>/I2C Read12'
                                        *   '<S971>/I2C Read'
                                        *   '<S971>/I2C Read1'
                                        *   '<S971>/I2C Read10'
                                        *   '<S971>/I2C Read11'
                                        *   '<S971>/I2C Read2'
                                        *   '<S971>/I2C Read3'
                                        *   '<S971>/I2C Read4'
                                        *   '<S971>/I2C Read5'
                                        *   '<S971>/I2C Read6'
                                        *   '<S971>/I2C Read7'
                                        *   '<S971>/I2C Read8'
                                        *   '<S971>/I2C Read9'
                                        *   '<S761>/Constant4'
                                        *   '<S764>/Constant4'
                                        *   '<S778>/Constant4'
                                        */
  real_T theta_max;                    /* Variable: theta_max
                                        * Referenced by: '<S984>/Constant8'
                                        */
  real_T theta_min;                    /* Variable: theta_min
                                        * Referenced by: '<S984>/Constant9'
                                        */
  real_T time_alarm_SAFE;              /* Variable: time_alarm_SAFE
                                        * Referenced by: '<S776>/Switch'
                                        */
  real_T vel_wp1_al;                   /* Variable: vel_wp1_al
                                        * Referenced by: '<S795>/Constant'
                                        */
  real_T vel_wp2_al;                   /* Variable: vel_wp2_al
                                        * Referenced by: '<S795>/Constant1'
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
  real_T PIDController_InitialConditionF;/* Mask Parameter: PIDController_InitialConditionF
                                          * Referenced by: '<S870>/Integrator'
                                          */
  real_T PIDController_InitialConditio_g;/* Mask Parameter: PIDController_InitialConditio_g
                                          * Referenced by: '<S609>/Integrator'
                                          */
  real_T PIDController_InitialConditio_d;/* Mask Parameter: PIDController_InitialConditio_d
                                          * Referenced by: '<S707>/Integrator'
                                          */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S675>/Kb'
                                        */
  real_T PIDController_Kb_k;           /* Mask Parameter: PIDController_Kb_k
                                        * Referenced by: '<S577>/Kb'
                                        */
  real_T PIDController_Kt;             /* Mask Parameter: PIDController_Kt
                                        * Referenced by: '<S742>/Kt'
                                        */
  real_T PIDController_Kt_m;           /* Mask Parameter: PIDController_Kt_m
                                        * Referenced by: '<S644>/Kt'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S926>/Constant'
                                        */
  real_T CompareToConstant_const_d;    /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S924>/Constant'
                                        */
  real_T CompareToConstant_const_p;    /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S927>/Constant'
                                        */
  real_T CompareToConstant_const_b;    /* Mask Parameter: CompareToConstant_const_b
                                        * Referenced by: '<S920>/Constant'
                                        */
  real_T CompareToConstant_const_dp;   /* Mask Parameter: CompareToConstant_const_dp
                                        * Referenced by: '<S918>/Constant'
                                        */
  real_T CompareToConstant_const_g;    /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S921>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S544>/Constant4'
                                        */
  real_T Constant2_Value_j;            /* Expression: 360
                                        * Referenced by: '<S549>/Constant2'
                                        */
  real_T Constant2_Value_d;            /* Expression: 360
                                        * Referenced by: '<S548>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S547>/Gain'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S549>/Switch2'
                                        */
  real_T Switch2_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<S548>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.15
                                        * Referenced by: '<S540>/Switch3'
                                        */
  real_T Constant3_Value;              /* Expression: 0.035*10
                                        * Referenced by: '<S541>/Constant3'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S541>/Gain'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S546>/Gain'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S545>/Gain'
                                        */
  real_T Constant2_Value_h;            /* Expression: 360
                                        * Referenced by: '<S550>/Constant2'
                                        */
  real_T Constant2_Value_dm;           /* Expression: 360
                                        * Referenced by: '<S551>/Constant2'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S553>/Constant5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 16
                                        * Referenced by: '<S553>/Switch1'
                                        */
  real_T Constant2_Value_hr;           /* Expression: 0.6
                                        * Referenced by: '<S542>/Constant2'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S755>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 20
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 50
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Alarm_Int_Y0;                 /* Expression: 0
                                        * Referenced by: '<S768>/Alarm_Int'
                                        */
  real_T Alarm_Int_Y0_j;               /* Expression: 0
                                        * Referenced by: '<S771>/Alarm_Int'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S776>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S776>/Constant'
                                        */
  real_T AlarmSafe_Y0;                 /* Expression: 0
                                        * Referenced by: '<S776>/Alarm Safe'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S778>/Memory'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S788>/ '
                                        */
  real_T _Y0_a;                        /* Expression: initCond
                                        * Referenced by: '<S789>/ '
                                        */
  real_T Gain_Gain_gm;                 /* Expression: 180/pi
                                        * Referenced by: '<S787>/Gain'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S780>/Memory'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S786>/Gain'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S780>/Memory1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S781>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S781>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S781>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S781>/Out4'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S781>/Memory3'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S790>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S782>/Constant8'
                                        */
  real_T Constant3_Value_c;            /* Expression: 1
                                        * Referenced by: '<S782>/Constant3'
                                        */
  real_T h_ref_Y0;                     /* Computed Parameter: h_ref_Y0
                                        * Referenced by: '<S793>/h_ref'
                                        */
  real_T flare_data_Y0;                /* Computed Parameter: flare_data_Y0
                                        * Referenced by: '<S793>/flare_data'
                                        */
  real_T landing_abort_Y0;             /* Computed Parameter: landing_abort_Y0
                                        * Referenced by: '<S793>/landing_abort'
                                        */
  real_T rc_ref_app_Y0;                /* Computed Parameter: rc_ref_app_Y0
                                        * Referenced by: '<S793>/rc_ref_app'
                                        */
  real_T x_g0_Value;                   /* Expression: -100
                                        * Referenced by: '<S793>/x_g0'
                                        */
  real_T Constant3_Value_n;            /* Expression: 1
                                        * Referenced by: '<S793>/Constant3'
                                        */
  real_T Constant4_Value_g;            /* Expression: 0
                                        * Referenced by: '<S793>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S793>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S793>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S793>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S793>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S793>/Switch'
                                        */
  real_T Gain_Gain_e0;                 /* Expression: -1
                                        * Referenced by: '<S793>/Gain'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S793>/Constant2'
                                        */
  real_T h_ref_Y0_n;                   /* Computed Parameter: h_ref_Y0_n
                                        * Referenced by: '<S797>/h_ref'
                                        */
  real_T RC_ref_Y0;                    /* Computed Parameter: RC_ref_Y0
                                        * Referenced by: '<S797>/RC_ref'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S797>/Gain'
                                        */
  real_T psi_ref_landing_Y0;           /* Computed Parameter: psi_ref_landing_Y0
                                        * Referenced by: '<S798>/psi_ref_landing'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S798>/Gain1'
                                        */
  real_T psirefgain1_Value;            /* Expression: 0.00052
                                        * Referenced by: '<S798>/psi ref gain1'
                                        */
  real_T psirefgain_Value;             /* Expression: 0.0052
                                        * Referenced by: '<S798>/psi ref gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S870>/Integrator'
                                        */
  real_T Gain_Gain_nw;                 /* Expression: 180/pi
                                        * Referenced by: '<S815>/Gain'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S913>/Constant1'
                                        */
  real_T Constant_Value_n;             /* Expression: 180
                                        * Referenced by: '<S913>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S916>/Bias'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S916>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S916>/Bias1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 360
                                        * Referenced by: '<S919>/Constant2'
                                        */
  real_T Bias_Bias_n;                  /* Expression: 180
                                        * Referenced by: '<S919>/Bias'
                                        */
  real_T Bias1_Bias_n;                 /* Expression: -180
                                        * Referenced by: '<S919>/Bias1'
                                        */
  real_T Constant2_Value_gk;           /* Expression: 360
                                        * Referenced by: '<S917>/Constant2'
                                        */
  real_T Bias_Bias_j;                  /* Expression: 180
                                        * Referenced by: '<S917>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S917>/Bias1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S914>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 180
                                        * Referenced by: '<S914>/Constant'
                                        */
  real_T Bias_Bias_f;                  /* Expression: -90
                                        * Referenced by: '<S922>/Bias'
                                        */
  real_T Gain_Gain_mn;                 /* Expression: -1
                                        * Referenced by: '<S922>/Gain'
                                        */
  real_T Bias1_Bias_f;                 /* Expression: +90
                                        * Referenced by: '<S922>/Bias1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 360
                                        * Referenced by: '<S925>/Constant2'
                                        */
  real_T Bias_Bias_e;                  /* Expression: 180
                                        * Referenced by: '<S925>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S925>/Bias1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S923>/Constant2'
                                        */
  real_T Bias_Bias_jc;                 /* Expression: 180
                                        * Referenced by: '<S923>/Bias'
                                        */
  real_T Bias1_Bias_gb;                /* Expression: -180
                                        * Referenced by: '<S923>/Bias1'
                                        */
  real_T _Y0_b[2];                     /* Expression: initCond
                                        * Referenced by: '<S807>/ '
                                        */
  real_T TAS_AL_Y0;                    /* Computed Parameter: TAS_AL_Y0
                                        * Referenced by: '<S782>/TAS_AL'
                                        */
  real_T QUOTA_AL_Y0;                  /* Computed Parameter: QUOTA_AL_Y0
                                        * Referenced by: '<S782>/QUOTA_AL'
                                        */
  real_T RC_AL_Y0;                     /* Computed Parameter: RC_AL_Y0
                                        * Referenced by: '<S782>/RC_AL'
                                        */
  real_T ROTTA_AL_Y0;                  /* Computed Parameter: ROTTA_AL_Y0
                                        * Referenced by: '<S782>/ROTTA_AL'
                                        */
  real_T H_LAT_Y0;                     /* Computed Parameter: H_LAT_Y0
                                        * Referenced by: '<S782>/H_LAT'
                                        */
  real_T H_LONG_Y0;                    /* Computed Parameter: H_LONG_Y0
                                        * Referenced by: '<S782>/H_LONG'
                                        */
  real_T H_ALT_Y0;                     /* Computed Parameter: H_ALT_Y0
                                        * Referenced by: '<S782>/H_ALT'
                                        */
  real_T distancewaypointsvirtuale_Value[3];/* Expression: [-1000 -800 2000]
                                             * Referenced by: '<S795>/distance waypoints virtuale'
                                             */
  real_T Gain_Gain_es;                 /* Expression: 180/pi
                                        * Referenced by: '<S811>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S812>/Gain'
                                        */
  real_T altwaypointvirtuale_Value[3]; /* Expression: [45 45 45]
                                        * Referenced by: '<S795>/alt waypoint virtuale'
                                        */
  real_T Gain_Gain_fi;                 /* Expression: 180/pi
                                        * Referenced by: '<S803>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S802>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S800>/Gain'
                                        */
  real_T Gain_Gain_b2;                 /* Expression: 180/pi
                                        * Referenced by: '<S801>/Gain'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: pi/180
                                        * Referenced by: '<S912>/Gain1'
                                        */
  real_T Constant2_Value_jx;           /* Expression: 1
                                        * Referenced by: '<S928>/Constant2'
                                        */
  real_T Constant_Value_nw;            /* Expression: 1
                                        * Referenced by: '<S931>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S932>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 1/298.257223563
                                        * Referenced by: '<S930>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S930>/f'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S929>/Gain1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 6378137
                                        * Referenced by: '<S928>/Constant1'
                                        */
  real_T Constant_Value_hg;            /* Expression: 1
                                        * Referenced by: '<S928>/Constant'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S928>/Constant3'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S804>/Gain'
                                        */
  real_T Gain_Gain_ov;                 /* Expression: 180/pi
                                        * Referenced by: '<S805>/Gain'
                                        */
  real_T Gain_Gain_jp;                 /* Expression: 180/pi
                                        * Referenced by: '<S806>/Gain'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S782>/Memory7'
                                        */
  real_T Memory5_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S782>/Memory5'
                                        */
  real_T Memory1_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S782>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S782>/Memory2'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S782>/Constant4'
                                        */
  real_T Constant2_Value_n3;           /* Expression: 45
                                        * Referenced by: '<S782>/Constant2'
                                        */
  real_T Switch2_Threshold_f;          /* Expression: 1
                                        * Referenced by: '<S782>/Switch2'
                                        */
  real_T Switch1_Threshold_l;          /* Expression: 1
                                        * Referenced by: '<S782>/Switch1'
                                        */
  real_T RC_Y0;                        /* Computed Parameter: RC_Y0
                                        * Referenced by: '<S783>/RC'
                                        */
  real_T VELOCITA_Y0;                  /* Computed Parameter: VELOCITA_Y0
                                        * Referenced by: '<S783>/VELOCITA'
                                        */
  real_T Out3_Y0_j;                    /* Computed Parameter: Out3_Y0_j
                                        * Referenced by: '<S783>/Out3'
                                        */
  real_T Out4_Y0_m;                    /* Computed Parameter: Out4_Y0_m
                                        * Referenced by: '<S783>/Out4'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S783>/Memory4'
                                        */
  real_T Gain_Gain_bu;                 /* Expression: 180/pi
                                        * Referenced by: '<S933>/Gain'
                                        */
  real_T Gain_Gain_jz;                 /* Expression: 180/pi
                                        * Referenced by: '<S934>/Gain'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 180/pi
                                        * Referenced by: '<S935>/Gain'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S784>/Out1'
                                        */
  real_T Out2_Y0_c;                    /* Computed Parameter: Out2_Y0_c
                                        * Referenced by: '<S784>/Out2'
                                        */
  real_T Out3_Y0_d;                    /* Computed Parameter: Out3_Y0_d
                                        * Referenced by: '<S784>/Out3'
                                        */
  real_T Out4_Y0_c;                    /* Computed Parameter: Out4_Y0_c
                                        * Referenced by: '<S784>/Out4'
                                        */
  real_T Gain_Gain_ji;                 /* Expression: 180/pi
                                        * Referenced by: '<S938>/Gain'
                                        */
  real_T Gain_Gain_gf;                 /* Expression: 180/pi
                                        * Referenced by: '<S939>/Gain'
                                        */
  real_T Gain_Gain_ov4;                /* Expression: 180/pi
                                        * Referenced by: '<S940>/Gain'
                                        */
  real_T Constant1_Value_o;            /* Expression: 16
                                        * Referenced by: '<S968>/Constant1'
                                        */
  real_T Constant5_Value_n;            /* Expression: 8
                                        * Referenced by: '<S968>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S968>/Constant6'
                                        */
  real_T Constant4_Value_l;            /* Expression: 4
                                        * Referenced by: '<S968>/Constant4'
                                        */
  real_T Constant2_Value_a;            /* Expression: 16
                                        * Referenced by: '<S968>/Constant2'
                                        */
  real_T Constant3_Value_c0;           /* Expression: 8
                                        * Referenced by: '<S968>/Constant3'
                                        */
  real_T Constant2_Value_dy;           /* Expression: 0
                                        * Referenced by: '<S975>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S975>/h_to_subtract'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S975>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2
                                        * Referenced by: '<S975>/Constant1'
                                        */
  real_T Constant3_Value_ct;           /* Expression: 3
                                        * Referenced by: '<S975>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S978>/Outport'
                                        */
  real_T Memory_InitialCondition_ab;   /* Expression: 0
                                        * Referenced by: '<S978>/Memory'
                                        */
  real_T Constant1_Value_js;           /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant_Value_bh;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_hx;            /* Expression: 15
                                        * Referenced by: '<S972>/Constant'
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
  real_T Constant1_Value_n;            /* Expression: 0.02
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Memory_InitialCondition_au;   /* Expression: -0.02
                                        * Referenced by: '<S29>/Memory'
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
  real_T Constant_Value_k;             /* Expression: 62
                                        * Referenced by: '<S947>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: tau
                                        * Referenced by: '<S956>/Constant'
                                        */
  real_T Gain1_Gain_px;                /* Expression: 0.01
                                        * Referenced by: '<S947>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S956>/Unit Delay'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: pi/180
                                        * Referenced by: '<S943>/Gain1'
                                        */
  real_T Gain_Gain_mz;                 /* Expression: 180/pi
                                        * Referenced by: '<S754>/Gain'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
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
  real_T Gain1_Gain_kf;                /* Expression: pi/180
                                        * Referenced by: '<S944>/Gain1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S945>/Gain1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S948>/Gain1'
                                        */
  real_T Gain_Gain_f2;                 /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S949>/Gain1'
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
  real_T Gain4_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S947>/Gain4'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S16>/vel y'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S950>/Gain1'
                                        */
  real_T Gain1_Gain_n1;                /* Expression: pi/180
                                        * Referenced by: '<S946>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T airspeedgroundspeedaltclimb1_Va;/* Expression: 0
                                          * Referenced by: '<S22>/airspeed groundspeed alt climb1'
                                          */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
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
  real_T Constant2_Value_jd;           /* Expression: 0
                                        * Referenced by: '<S39>/Constant2'
                                        */
  real_T Constant8_Value_e;            /* Expression: 1
                                        * Referenced by: '<S544>/Constant8'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                          * Referenced by: '<S544>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S544>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_l;/* Expression: 0.6
                                          * Referenced by: '<S544>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_c;/* Expression: 0
                                          * Referenced by: '<S544>/Discrete-Time Integrator'
                                          */
  real_T Gain2_Gain_j;                 /* Expression: 100
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T Constant2_Value_i4;           /* Expression: 0
                                        * Referenced by: '<S541>/Constant2'
                                        */
  real_T Constant1_Value_fj;           /* Expression: 0
                                        * Referenced by: '<S541>/Constant1'
                                        */
  real_T Gain_Gain_h1;                 /* Expression: 1
                                        * Referenced by: '<S984>/Gain'
                                        */
  real_T Integrator_gainval_b;         /* Computed Parameter: Integrator_gainval_b
                                        * Referenced by: '<S609>/Integrator'
                                        */
  real_T Gain1_Gain_jm;                /* Expression: pi/180
                                        * Referenced by: '<S651>/Gain1'
                                        */
  real_T Gain_Gain_od;                 /* Expression: 180/pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant2_Value_m;            /* Expression: 90
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant1_Value_ng;           /* Expression: 0
                                        * Referenced by: '<S542>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S982>/Gain'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 1.8
                                        * Referenced by: '<S542>/Switch'
                                        */
  real_T Constant3_Value_cr;           /* Expression: 2
                                        * Referenced by: '<S542>/Constant3'
                                        */
  real_T Integrator_gainval_g;         /* Computed Parameter: Integrator_gainval_g
                                        * Referenced by: '<S707>/Integrator'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T DiscreteWashoutFilter_NumCoef[2];/* Expression: [ 1 -1]
                                           * Referenced by: '<S543>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_DenCoef[2];/* Expression: [1 -0.995]
                                           * Referenced by: '<S543>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_InitialSt;/* Expression: 0
                                          * Referenced by: '<S543>/Discrete Washout Filter'
                                          */
  real_T r_rif_Value;                  /* Expression: 0
                                        * Referenced by: '<S39>/r_rif'
                                        */
  real_T Switch2_Threshold_c;          /* Expression: 5
                                        * Referenced by: '<S540>/Switch2'
                                        */
  real_T Switch2_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S550>/Switch2'
                                        */
  real_T RC_default_Value;             /* Expression: 2
                                        * Referenced by: '<S41>/RC_default'
                                        */
  real_T Constant_Value_g;             /* Expression: 70
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant1_Value_jf;           /* Expression: 20
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T Switch2_Threshold_ah;         /* Expression: 0
                                        * Referenced by: '<S551>/Switch2'
                                        */
  real_T Gain_Gain_bh;                 /* Expression: 180/pi
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Constant1_Value_pa[3];        /* Expression: zeros(3,1)
                                        * Referenced by: '<S20>/Constant1'
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
  real_T DelayInput2_InitialCondition; /* Expression: 101325
                                        * Referenced by: '<S967>/Delay Input2'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S967>/sample time'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Gain7_Gain;                   /* Expression: 100
                                        * Referenced by: '<S947>/Gain7'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Gain_Gain_nk;                 /* Expression: 180/pi
                                        * Referenced by: '<S952>/Gain'
                                        */
  real_T Gain_Gain_db;                 /* Expression: 180/pi
                                        * Referenced by: '<S953>/Gain'
                                        */
  real_T Gain_Gain_dc;                 /* Expression: 180/pi
                                        * Referenced by: '<S954>/Gain'
                                        */
  real_T Gain_Gain_bk;                 /* Expression: 100
                                        * Referenced by: '<S947>/Gain'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 100
                                        * Referenced by: '<S947>/Gain2'
                                        */
  real_T Gain_Gain_je;                 /* Expression: 180/pi
                                        * Referenced by: '<S756>/Gain'
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
  real_T Switch1_Threshold_c;          /* Expression: 9
                                        * Referenced by: '<S29>/Switch1'
                                        */
  real_T Constant7_Value;              /* Expression: 10
                                        * Referenced by: '<S544>/Constant7'
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
  int32_T Constant_Value_gw;           /* Computed Parameter: Constant_Value_gw
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Gain2_Gain_k4;              /* Computed Parameter: Gain2_Gain_k4
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real32_T Out2_Y0_cb;                 /* Computed Parameter: Out2_Y0_cb
                                        * Referenced by: '<S961>/Out2'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S968>/T'
                                        */
  real32_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S972>/Switch'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S974>/T_0'
                                        */
  real32_T Gain_Gain_j5;               /* Computed Parameter: Gain_Gain_j5
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S947>/Gain3'
                                        */
  real32_T Gain1_Gain_k2;              /* Computed Parameter: Gain1_Gain_k2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S968>/p'
                                        */
  uint32_T Constant7_Value_h;          /* Computed Parameter: Constant7_Value_h
                                        * Referenced by: '<S968>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S968>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S968>/Constant11'
                                        */
  uint32_T Constant8_Value_et;         /* Computed Parameter: Constant8_Value_et
                                        * Referenced by: '<S968>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S968>/Constant9'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S965>/Delay'
                                        */
  uint32_T onboard_control_sensor_presentu[3];/* Computed Parameter: onboard_control_sensor_presentu
                                               * Referenced by: '<S21>/onboard_control_sensor_present uint32'
                                               */
  int16_T Out3_Y0_a;                   /* Computed Parameter: Out3_Y0_a
                                        * Referenced by: '<S961>/Out3'
                                        */
  int16_T Switch_Threshold_mm;         /* Computed Parameter: Switch_Threshold_mm
                                        * Referenced by: '<S9>/Switch'
                                        */
  int16_T Gain1_Gain_eu;               /* Computed Parameter: Gain1_Gain_eu
                                        * Referenced by: '<S21>/Gain1'
                                        */
  uint16_T Out4_Y0_i;                  /* Computed Parameter: Out4_Y0_i
                                        * Referenced by: '<S961>/Out4'
                                        */
  uint16_T Memory_InitialCondition_at; /* Computed Parameter: Memory_InitialCondition_at
                                        * Referenced by: '<S1>/Memory'
                                        */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S21>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S21>/ '
                                        */
  uint16_T Memory_InitialCondition_g;  /* Computed Parameter: Memory_InitialCondition_g
                                        * Referenced by: '<S2>/Memory'
                                        */
  boolean_T UnitDelay_InitialCondition_l;/* Computed Parameter: UnitDelay_InitialCondition_l
                                          * Referenced by: '<S963>/Unit Delay'
                                          */
  boolean_T Constant3_Value_ok;        /* Computed Parameter: Constant3_Value_ok
                                        * Referenced by: '<S963>/Constant3'
                                        */
  int8_T Gain3_Gain_o;                 /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S8>/Gain3'
                                        */
  uint8_T Memory_InitialCondition_j;   /* Computed Parameter: Memory_InitialCondition_j
                                        * Referenced by: '<S781>/Memory'
                                        */
  uint8_T Memory1_InitialCondition_g;  /* Computed Parameter: Memory1_InitialCondition_g
                                        * Referenced by: '<S781>/Memory1'
                                        */
  uint8_T Memory2_InitialCondition_n;  /* Computed Parameter: Memory2_InitialCondition_n
                                        * Referenced by: '<S781>/Memory2'
                                        */
  uint8_T Memory6_InitialCondition;    /* Computed Parameter: Memory6_InitialCondition
                                        * Referenced by: '<S781>/Memory6'
                                        */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S978>/mario'
                                        */
  uint8_T Memory4_InitialCondition_g[300];/* Expression: uint8(zeros(3,100))
                                           * Referenced by: '<S1>/Memory4'
                                           */
  uint8_T Constant1_Value_g;           /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S965>/Constant1'
                                        */
  uint8_T Delay_InitialCondition;      /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S965>/Delay'
                                        */
  uint8_T Constant1_Value_a;           /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory5_InitialCondition_d;  /* Computed Parameter: Memory5_InitialCondition_d
                                        * Referenced by: '<S1>/Memory5'
                                        */
  uint8_T Memory1_InitialCondition_b;  /* Computed Parameter: Memory1_InitialCondition_b
                                        * Referenced by: '<S1>/Memory1'
                                        */
  uint8_T Memory_InitialCondition_o;   /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<Root>/Memory'
                                        */
  uint8_T Memory3_InitialCondition_c;  /* Computed Parameter: Memory3_InitialCondition_c
                                        * Referenced by: '<S1>/Memory3'
                                        */
  uint8_T Memory2_InitialCondition_g[9];/* Computed Parameter: Memory2_InitialCondition_g
                                         * Referenced by: '<S1>/Memory2'
                                         */
  uint8_T Typefixed_wingAutopilotgeneric_[2];/* Computed Parameter: Typefixed_wingAutopilotgeneric_
                                              * Referenced by: '<S17>/Type fixed_wing Autopilot generic'
                                              */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S947>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S947>/Fine MSG1'
                                        */
  P_One_time_initialization_loa_T One_time_initialization;/* '<S963>/One_time_initialization' */
  P_ResettableSubsystem_load_ar_T ResettableSubsystem_o;/* '<S751>/Resettable Subsystem' */
  P_EnabledSubsystem_load_ardui_T EnabledSubsystem_j;/* '<S751>/Enabled Subsystem' */
  P_ResettableSubsystem_load_ar_T ResettableSubsystem;/* '<S750>/Resettable Subsystem' */
  P_EnabledSubsystem_load_ardui_T EnabledSubsystem;/* '<S750>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_load_arduino_v_13_T {
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
extern P_load_arduino_v_13_T load_arduino_v_13_P;

/* Block signals (default storage) */
extern B_load_arduino_v_13_T load_arduino_v_13_B;

/* Block states (default storage) */
extern DW_load_arduino_v_13_T load_arduino_v_13_DW;

/* External data declarations for dependent source files */
extern const uint16_T load_arduino_v_13_U16GND;/* uint16_T ground */

/* External function called from main */
extern void load_arduino_v_13_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void load_arduino_v_13_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void load_arduino_v_13_initialize(void);
extern void load_arduino_v_13_step0(void);
extern void load_arduino_v_13_step1(void);
extern void load_arduino_v_13_step2(void);
extern void load_arduino_v_13_terminate(void);

/* Real-time Model object */
extern RT_MODEL_load_arduino_v_13_T *const load_arduino_v_13_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S45>/Constant1' : Unused code path elimination
 * Block '<S45>/Constant10' : Unused code path elimination
 * Block '<S45>/Constant11' : Unused code path elimination
 * Block '<S45>/Constant12' : Unused code path elimination
 * Block '<S45>/Constant2' : Unused code path elimination
 * Block '<S45>/Constant3' : Unused code path elimination
 * Block '<S45>/Constant5' : Unused code path elimination
 * Block '<S45>/Constant6' : Unused code path elimination
 * Block '<S45>/Constant7' : Unused code path elimination
 * Block '<S45>/D gain' : Unused code path elimination
 * Block '<S45>/D gain1' : Unused code path elimination
 * Block '<S45>/Multiply' : Unused code path elimination
 * Block '<S45>/Multiply1' : Unused code path elimination
 * Block '<S45>/Multiport Switch' : Unused code path elimination
 * Block '<S45>/Multiport Switch1' : Unused code path elimination
 * Block '<S45>/Multiport Switch2' : Unused code path elimination
 * Block '<S94>/IProd Out' : Unused code path elimination
 * Block '<S105>/Integrator' : Unused code path elimination
 * Block '<S121>/PProd Out' : Unused code path elimination
 * Block '<S134>/Sum' : Unused code path elimination
 * Block '<S140>/Kt' : Unused code path elimination
 * Block '<S140>/SumI3' : Unused code path elimination
 * Block '<S142>/SumI1' : Unused code path elimination
 * Block '<S190>/IProd Out' : Unused code path elimination
 * Block '<S201>/Integrator' : Unused code path elimination
 * Block '<S217>/PProd Out' : Unused code path elimination
 * Block '<S230>/Sum' : Unused code path elimination
 * Block '<S236>/Kt' : Unused code path elimination
 * Block '<S236>/SumI3' : Unused code path elimination
 * Block '<S238>/SumI1' : Unused code path elimination
 * Block '<S286>/IProd Out' : Unused code path elimination
 * Block '<S297>/Integrator' : Unused code path elimination
 * Block '<S313>/PProd Out' : Unused code path elimination
 * Block '<S326>/Sum' : Unused code path elimination
 * Block '<S332>/Kt' : Unused code path elimination
 * Block '<S332>/SumI3' : Unused code path elimination
 * Block '<S334>/SumI1' : Unused code path elimination
 * Block '<S45>/Sum' : Unused code path elimination
 * Block '<S45>/Sum1' : Unused code path elimination
 * Block '<S45>/Sum2' : Unused code path elimination
 * Block '<S45>/Sum3' : Unused code path elimination
 * Block '<S45>/Sum4' : Unused code path elimination
 * Block '<S45>/Sum5' : Unused code path elimination
 * Block '<S45>/Sum6' : Unused code path elimination
 * Block '<S45>/Switch auto-manual' : Unused code path elimination
 * Block '<S45>/Switch maneuver' : Unused code path elimination
 * Block '<S45>/Switch rc saturata' : Unused code path elimination
 * Block '<S42>/Kp' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Lookup Table2' : Unused code path elimination
 * Block '<S339>/Data Type Duplicate' : Unused code path elimination
 * Block '<S339>/Data Type Propagation' : Unused code path elimination
 * Block '<S339>/LowerRelop1' : Unused code path elimination
 * Block '<S339>/Switch' : Unused code path elimination
 * Block '<S339>/Switch2' : Unused code path elimination
 * Block '<S339>/UpperRelop' : Unused code path elimination
 * Block '<S42>/Switch HOLD//SELECT' : Unused code path elimination
 * Block '<S340>/Constant3' : Unused code path elimination
 * Block '<S340>/Constant4' : Unused code path elimination
 * Block '<S340>/Multiport Switch2' : Unused code path elimination
 * Block '<S340>/Multiport Switch3' : Unused code path elimination
 * Block '<S340>/Switch1' : Unused code path elimination
 * Block '<S340>/Switch3' : Unused code path elimination
 * Block '<S341>/Constant3' : Unused code path elimination
 * Block '<S341>/Constant4' : Unused code path elimination
 * Block '<S341>/Multiport Switch2' : Unused code path elimination
 * Block '<S341>/Multiport Switch3' : Unused code path elimination
 * Block '<S341>/Switch3' : Unused code path elimination
 * Block '<S341>/Switch4' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S374>/DProd Out' : Unused code path elimination
 * Block '<S380>/Filter' : Unused code path elimination
 * Block '<S380>/SumD' : Unused code path elimination
 * Block '<S407>/NProd Out' : Unused code path elimination
 * Block '<S414>/PProd Out' : Unused code path elimination
 * Block '<S419>/Saturation' : Unused code path elimination
 * Block '<S426>/Sum' : Unused code path elimination
 * Block '<S343>/Constant' : Unused code path elimination
 * Block '<S343>/Constant1' : Unused code path elimination
 * Block '<S343>/Constant2' : Unused code path elimination
 * Block '<S440>/Gain1' : Unused code path elimination
 * Block '<S343>/Math Function' : Unused code path elimination
 * Block '<S441>/Gain' : Unused code path elimination
 * Block '<S343>/Sum' : Unused code path elimination
 * Block '<S343>/Sum1' : Unused code path elimination
 * Block '<S343>/Sum2' : Unused code path elimination
 * Block '<S343>/Switch' : Unused code path elimination
 * Block '<S343>/Switch1' : Unused code path elimination
 * Block '<S471>/AND3' : Unused code path elimination
 * Block '<S471>/Constant1' : Unused code path elimination
 * Block '<S471>/DataTypeConv1' : Unused code path elimination
 * Block '<S471>/DataTypeConv2' : Unused code path elimination
 * Block '<S471>/DeadZone' : Unused code path elimination
 * Block '<S471>/Equal1' : Unused code path elimination
 * Block '<S471>/NotEqual' : Unused code path elimination
 * Block '<S471>/SignPreIntegrator' : Unused code path elimination
 * Block '<S471>/SignPreSat' : Unused code path elimination
 * Block '<S471>/Switch' : Unused code path elimination
 * Block '<S471>/ZeroGain' : Unused code path elimination
 * Block '<S487>/IProd Out' : Unused code path elimination
 * Block '<S498>/Integrator' : Unused code path elimination
 * Block '<S514>/PProd Out' : Unused code path elimination
 * Block '<S519>/Saturation' : Unused code path elimination
 * Block '<S527>/Sum' : Unused code path elimination
 * Block '<S533>/Kt' : Unused code path elimination
 * Block '<S533>/SumI3' : Unused code path elimination
 * Block '<S535>/SumI1' : Unused code path elimination
 * Block '<S44>/Sum3' : Unused code path elimination
 * Block '<S44>/Switch Bumpless 1' : Unused code path elimination
 * Block '<S443>/Constant3' : Unused code path elimination
 * Block '<S443>/Switch' : Unused code path elimination
 * Block '<S443>/throttle - landing' : Unused code path elimination
 * Block '<S38>/Switch di selezione riferimeti  per i loop interni 1' : Unused code path elimination
 * Block '<S38>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
 * Block '<S38>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
 * Block '<S750>/Display' : Unused code path elimination
 * Block '<S750>/Display1' : Unused code path elimination
 * Block '<S768>/Constant' : Unused code path elimination
 * Block '<S768>/Constant1' : Unused code path elimination
 * Block '<S768>/Switch' : Unused code path elimination
 * Block '<S770>/Constant4' : Unused code path elimination
 * Block '<S770>/Memory' : Unused code path elimination
 * Block '<S770>/Sum' : Unused code path elimination
 * Block '<S771>/Constant' : Unused code path elimination
 * Block '<S771>/Constant1' : Unused code path elimination
 * Block '<S771>/Switch' : Unused code path elimination
 * Block '<S773>/Constant4' : Unused code path elimination
 * Block '<S773>/Memory' : Unused code path elimination
 * Block '<S773>/Sum' : Unused code path elimination
 * Block '<S752>/Switch' : Unused code path elimination
 * Block '<S40>/Scope1' : Unused code path elimination
 * Block '<S758>/Abs2' : Unused code path elimination
 * Block '<S793>/Constant1' : Unused code path elimination
 * Block '<S793>/Multiply1' : Unused code path elimination
 * Block '<S782>/Constant1' : Unused code path elimination
 * Block '<S782>/Constant6' : Unused code path elimination
 * Block '<S782>/Constant7' : Unused code path elimination
 * Block '<S797>/Constant1' : Unused code path elimination
 * Block '<S797>/Exp1' : Unused code path elimination
 * Block '<S797>/Gain1' : Unused code path elimination
 * Block '<S797>/Gain2' : Unused code path elimination
 * Block '<S797>/Multiply2' : Unused code path elimination
 * Block '<S797>/Multiply3' : Unused code path elimination
 * Block '<S797>/Multiply4' : Unused code path elimination
 * Block '<S797>/Sum3' : Unused code path elimination
 * Block '<S797>/Sum4' : Unused code path elimination
 * Block '<S782>/Relational Operator' : Unused code path elimination
 * Block '<S782>/Switch' : Unused code path elimination
 * Block '<S782>/Switch di selezione  Task - Waypoint navigation5' : Unused code path elimination
 * Block '<S782>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
 * Block '<S783>/saturatore V' : Unused code path elimination
 * Block '<S783>/saturatore V1' : Unused code path elimination
 * Block '<S41>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
 * Block '<S41>/Switch di selezione  Task - Waypoint navigation1' : Unused code path elimination
 * Block '<S967>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S973>/Data Type Duplicate' : Unused code path elimination
 * Block '<S973>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S947>/Data Type Conversion7' : Eliminate redundant data type conversion
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
 * '<Root>' : 'load_arduino_v_13'
 * '<S1>'   : 'load_arduino_v_13/AIR RX'
 * '<S2>'   : 'load_arduino_v_13/AIR TX'
 * '<S3>'   : 'load_arduino_v_13/AUTOPILOTA'
 * '<S4>'   : 'load_arduino_v_13/Inizializzazioni'
 * '<S5>'   : 'load_arduino_v_13/LED 13-44'
 * '<S6>'   : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE'
 * '<S7>'   : 'load_arduino_v_13/Misure Sensori'
 * '<S8>'   : 'load_arduino_v_13/PARAMETRI SISTEMA DI CONTROLLO'
 * '<S9>'   : 'load_arduino_v_13/RADIOCOMANDO'
 * '<S10>'  : 'load_arduino_v_13/Servi'
 * '<S11>'  : 'load_arduino_v_13/AIR RX/MATLAB Function1'
 * '<S12>'  : 'load_arduino_v_13/AIR RX/MATLAB Function2'
 * '<S13>'  : 'load_arduino_v_13/AIR RX/MATLAB Function3'
 * '<S14>'  : 'load_arduino_v_13/AIR RX/MATLAB Function4'
 * '<S15>'  : 'load_arduino_v_13/AIR TX/Enable '
 * '<S16>'  : 'load_arduino_v_13/AIR TX/GPS'
 * '<S17>'  : 'load_arduino_v_13/AIR TX/Heartbeat'
 * '<S18>'  : 'load_arduino_v_13/AIR TX/IMU & Attidude'
 * '<S19>'  : 'load_arduino_v_13/AIR TX/If_subsystem'
 * '<S20>'  : 'load_arduino_v_13/AIR TX/Servo'
 * '<S21>'  : 'load_arduino_v_13/AIR TX/SystemStatus'
 * '<S22>'  : 'load_arduino_v_13/AIR TX/VFR'
 * '<S23>'  : 'load_arduino_v_13/AIR TX/Waypoints'
 * '<S24>'  : 'load_arduino_v_13/AIR TX/Enable /Chart'
 * '<S25>'  : 'load_arduino_v_13/AIR TX/Enable /Chart/sendbyte'
 * '<S26>'  : 'load_arduino_v_13/AIR TX/GPS/Radians to Degrees'
 * '<S27>'  : 'load_arduino_v_13/AIR TX/GPS/Radians to Degrees1'
 * '<S28>'  : 'load_arduino_v_13/AIR TX/Heartbeat/Alarm set'
 * '<S29>'  : 'load_arduino_v_13/AIR TX/If_subsystem/Subsystem'
 * '<S30>'  : 'load_arduino_v_13/AIR TX/If_subsystem/iflogic_function'
 * '<S31>'  : 'load_arduino_v_13/AIR TX/Servo/Conversione'
 * '<S32>'  : 'load_arduino_v_13/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S33>'  : 'load_arduino_v_13/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S34>'  : 'load_arduino_v_13/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S35>'  : 'load_arduino_v_13/AIR TX/VFR/Radians to Degrees'
 * '<S36>'  : 'load_arduino_v_13/AIR TX/VFR/wrapTo360'
 * '<S37>'  : 'load_arduino_v_13/AIR TX/Waypoints/MATLAB Function'
 * '<S38>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1'
 * '<S39>'  : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
 * '<S40>'  : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1'
 * '<S41>'  : 'load_arduino_v_13/AUTOPILOTA/Subsystem1'
 * '<S42>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
 * '<S43>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
 * '<S44>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
 * '<S45>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota'
 * '<S46>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
 * '<S47>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
 * '<S48>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach'
 * '<S49>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare'
 * '<S50>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato'
 * '<S51>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup'
 * '<S52>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/D Gain'
 * '<S53>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter'
 * '<S54>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter ICs'
 * '<S55>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/I Gain'
 * '<S56>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain'
 * '<S57>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain Fdbk'
 * '<S58>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator'
 * '<S59>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator ICs'
 * '<S60>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Copy'
 * '<S61>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Gain'
 * '<S62>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/P Copy'
 * '<S63>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Parallel P Gain'
 * '<S64>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Reset Signal'
 * '<S65>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation'
 * '<S66>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation Fdbk'
 * '<S67>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum'
 * '<S68>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum Fdbk'
 * '<S69>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Tracking Mode'
 * '<S70>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Tracking Mode Sum'
 * '<S71>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/postSat Signal'
 * '<S72>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/preSat Signal'
 * '<S73>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Back Calculation'
 * '<S74>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Cont. Clamping Ideal'
 * '<S75>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Cont. Clamping Parallel'
 * '<S76>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Disabled'
 * '<S77>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Disc. Clamping Ideal'
 * '<S78>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Disc. Clamping Parallel'
 * '<S79>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Anti-windup/Passthrough'
 * '<S80>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/D Gain/Disabled'
 * '<S81>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/D Gain/External Parameters'
 * '<S82>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/D Gain/Internal Parameters'
 * '<S83>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter/Cont. Filter'
 * '<S84>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter/Differentiator'
 * '<S85>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter/Disabled'
 * '<S86>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter/Disc. Backward Euler Filter'
 * '<S87>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter/Disc. Forward Euler Filter'
 * '<S88>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter/Disc. Trapezoidal Filter'
 * '<S89>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter ICs/Disabled'
 * '<S90>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter ICs/External IC'
 * '<S91>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter ICs/Internal IC - Differentiator'
 * '<S92>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Filter ICs/Internal IC - Filter'
 * '<S93>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/I Gain/Disabled'
 * '<S94>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/I Gain/External Parameters'
 * '<S95>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/I Gain/Internal Parameters'
 * '<S96>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain/External Parameters'
 * '<S97>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain/Internal Parameters'
 * '<S98>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain/Passthrough'
 * '<S99>'  : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain Fdbk/External Parameters'
 * '<S101>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain Fdbk/Internal Parameters'
 * '<S102>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Ideal P Gain Fdbk/Passthrough'
 * '<S103>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator/Continuous'
 * '<S104>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator/Disabled'
 * '<S105>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator/Discrete'
 * '<S106>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator ICs/Disabled'
 * '<S107>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator ICs/External IC'
 * '<S108>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Integrator ICs/Internal IC'
 * '<S109>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Copy/Disabled'
 * '<S110>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Copy/Disabled wSignal Specification'
 * '<S111>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Copy/External Parameters'
 * '<S112>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Copy/Internal Parameters'
 * '<S113>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Gain/Disabled'
 * '<S114>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Gain/External Parameters'
 * '<S115>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Gain/Internal Parameters'
 * '<S116>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/N Gain/Passthrough'
 * '<S117>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/P Copy/Disabled'
 * '<S118>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/P Copy/External Parameters Ideal'
 * '<S119>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/P Copy/Internal Parameters Ideal'
 * '<S120>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Parallel P Gain/Disabled'
 * '<S121>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Parallel P Gain/External Parameters'
 * '<S122>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Parallel P Gain/Internal Parameters'
 * '<S123>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Parallel P Gain/Passthrough'
 * '<S124>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Reset Signal/Disabled'
 * '<S125>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Reset Signal/External Reset'
 * '<S126>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation/Enabled'
 * '<S127>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation/Passthrough'
 * '<S128>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation Fdbk/Disabled'
 * '<S129>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation Fdbk/Enabled'
 * '<S130>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Saturation Fdbk/Passthrough'
 * '<S131>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum/Passthrough_I'
 * '<S132>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum/Passthrough_P'
 * '<S133>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum/Sum_PD'
 * '<S134>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum/Sum_PI'
 * '<S135>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum/Sum_PID'
 * '<S136>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum Fdbk/Disabled'
 * '<S137>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum Fdbk/Enabled'
 * '<S138>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Sum Fdbk/Passthrough'
 * '<S139>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Tracking Mode/Disabled'
 * '<S140>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Tracking Mode/Enabled'
 * '<S141>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Tracking Mode Sum/Passthrough'
 * '<S142>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/Tracking Mode Sum/Tracking Mode'
 * '<S143>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/postSat Signal/Feedback_Path'
 * '<S144>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/postSat Signal/Forward_Path'
 * '<S145>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/preSat Signal/Feedback_Path'
 * '<S146>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Approach/preSat Signal/Forward_Path'
 * '<S147>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup'
 * '<S148>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/D Gain'
 * '<S149>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter'
 * '<S150>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter ICs'
 * '<S151>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/I Gain'
 * '<S152>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain'
 * '<S153>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain Fdbk'
 * '<S154>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator'
 * '<S155>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator ICs'
 * '<S156>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Copy'
 * '<S157>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Gain'
 * '<S158>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/P Copy'
 * '<S159>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Parallel P Gain'
 * '<S160>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Reset Signal'
 * '<S161>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation'
 * '<S162>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation Fdbk'
 * '<S163>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum'
 * '<S164>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum Fdbk'
 * '<S165>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Tracking Mode'
 * '<S166>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Tracking Mode Sum'
 * '<S167>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/postSat Signal'
 * '<S168>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/preSat Signal'
 * '<S169>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Back Calculation'
 * '<S170>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Cont. Clamping Ideal'
 * '<S171>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Cont. Clamping Parallel'
 * '<S172>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Disabled'
 * '<S173>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Disc. Clamping Ideal'
 * '<S174>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Disc. Clamping Parallel'
 * '<S175>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Anti-windup/Passthrough'
 * '<S176>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/D Gain/Disabled'
 * '<S177>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/D Gain/External Parameters'
 * '<S178>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/D Gain/Internal Parameters'
 * '<S179>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter/Cont. Filter'
 * '<S180>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter/Differentiator'
 * '<S181>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter/Disabled'
 * '<S182>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter/Disc. Backward Euler Filter'
 * '<S183>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter/Disc. Forward Euler Filter'
 * '<S184>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter/Disc. Trapezoidal Filter'
 * '<S185>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter ICs/Disabled'
 * '<S186>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter ICs/External IC'
 * '<S187>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter ICs/Internal IC - Differentiator'
 * '<S188>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Filter ICs/Internal IC - Filter'
 * '<S189>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/I Gain/Disabled'
 * '<S190>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/I Gain/External Parameters'
 * '<S191>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/I Gain/Internal Parameters'
 * '<S192>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain/External Parameters'
 * '<S193>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain/Internal Parameters'
 * '<S194>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain/Passthrough'
 * '<S195>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain Fdbk/Disabled'
 * '<S196>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain Fdbk/External Parameters'
 * '<S197>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain Fdbk/Internal Parameters'
 * '<S198>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Ideal P Gain Fdbk/Passthrough'
 * '<S199>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator/Continuous'
 * '<S200>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator/Disabled'
 * '<S201>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator/Discrete'
 * '<S202>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator ICs/Disabled'
 * '<S203>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator ICs/External IC'
 * '<S204>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Integrator ICs/Internal IC'
 * '<S205>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Copy/Disabled'
 * '<S206>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Copy/Disabled wSignal Specification'
 * '<S207>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Copy/External Parameters'
 * '<S208>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Copy/Internal Parameters'
 * '<S209>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Gain/Disabled'
 * '<S210>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Gain/External Parameters'
 * '<S211>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Gain/Internal Parameters'
 * '<S212>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/N Gain/Passthrough'
 * '<S213>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/P Copy/Disabled'
 * '<S214>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/P Copy/External Parameters Ideal'
 * '<S215>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/P Copy/Internal Parameters Ideal'
 * '<S216>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Parallel P Gain/Disabled'
 * '<S217>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Parallel P Gain/External Parameters'
 * '<S218>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Parallel P Gain/Internal Parameters'
 * '<S219>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Parallel P Gain/Passthrough'
 * '<S220>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Reset Signal/Disabled'
 * '<S221>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Reset Signal/External Reset'
 * '<S222>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation/Enabled'
 * '<S223>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation/Passthrough'
 * '<S224>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation Fdbk/Disabled'
 * '<S225>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation Fdbk/Enabled'
 * '<S226>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Saturation Fdbk/Passthrough'
 * '<S227>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum/Passthrough_I'
 * '<S228>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum/Passthrough_P'
 * '<S229>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum/Sum_PD'
 * '<S230>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum/Sum_PI'
 * '<S231>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum/Sum_PID'
 * '<S232>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum Fdbk/Disabled'
 * '<S233>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum Fdbk/Enabled'
 * '<S234>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Sum Fdbk/Passthrough'
 * '<S235>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Tracking Mode/Disabled'
 * '<S236>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Tracking Mode/Enabled'
 * '<S237>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Tracking Mode Sum/Passthrough'
 * '<S238>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/Tracking Mode Sum/Tracking Mode'
 * '<S239>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/postSat Signal/Feedback_Path'
 * '<S240>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/postSat Signal/Forward_Path'
 * '<S241>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/preSat Signal/Feedback_Path'
 * '<S242>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI Flare/preSat Signal/Forward_Path'
 * '<S243>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup'
 * '<S244>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/D Gain'
 * '<S245>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter'
 * '<S246>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter ICs'
 * '<S247>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/I Gain'
 * '<S248>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain'
 * '<S249>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain Fdbk'
 * '<S250>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator'
 * '<S251>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator ICs'
 * '<S252>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Copy'
 * '<S253>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Gain'
 * '<S254>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/P Copy'
 * '<S255>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Parallel P Gain'
 * '<S256>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Reset Signal'
 * '<S257>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation'
 * '<S258>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation Fdbk'
 * '<S259>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum'
 * '<S260>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum Fdbk'
 * '<S261>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Tracking Mode'
 * '<S262>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Tracking Mode Sum'
 * '<S263>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/postSat Signal'
 * '<S264>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/preSat Signal'
 * '<S265>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Back Calculation'
 * '<S266>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Cont. Clamping Ideal'
 * '<S267>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Cont. Clamping Parallel'
 * '<S268>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Disabled'
 * '<S269>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Disc. Clamping Ideal'
 * '<S270>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Disc. Clamping Parallel'
 * '<S271>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Anti-windup/Passthrough'
 * '<S272>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/D Gain/Disabled'
 * '<S273>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/D Gain/External Parameters'
 * '<S274>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/D Gain/Internal Parameters'
 * '<S275>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter/Cont. Filter'
 * '<S276>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter/Differentiator'
 * '<S277>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter/Disabled'
 * '<S278>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter/Disc. Backward Euler Filter'
 * '<S279>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter/Disc. Forward Euler Filter'
 * '<S280>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter/Disc. Trapezoidal Filter'
 * '<S281>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter ICs/Disabled'
 * '<S282>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter ICs/External IC'
 * '<S283>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter ICs/Internal IC - Differentiator'
 * '<S284>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Filter ICs/Internal IC - Filter'
 * '<S285>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/I Gain/Disabled'
 * '<S286>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/I Gain/External Parameters'
 * '<S287>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/I Gain/Internal Parameters'
 * '<S288>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain/External Parameters'
 * '<S289>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain/Internal Parameters'
 * '<S290>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain/Passthrough'
 * '<S291>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain Fdbk/Disabled'
 * '<S292>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain Fdbk/External Parameters'
 * '<S293>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain Fdbk/Internal Parameters'
 * '<S294>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Ideal P Gain Fdbk/Passthrough'
 * '<S295>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator/Continuous'
 * '<S296>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator/Disabled'
 * '<S297>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator/Discrete'
 * '<S298>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator ICs/Disabled'
 * '<S299>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator ICs/External IC'
 * '<S300>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Integrator ICs/Internal IC'
 * '<S301>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Copy/Disabled'
 * '<S302>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Copy/Disabled wSignal Specification'
 * '<S303>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Copy/External Parameters'
 * '<S304>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Copy/Internal Parameters'
 * '<S305>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Gain/Disabled'
 * '<S306>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Gain/External Parameters'
 * '<S307>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Gain/Internal Parameters'
 * '<S308>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/N Gain/Passthrough'
 * '<S309>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/P Copy/Disabled'
 * '<S310>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/P Copy/External Parameters Ideal'
 * '<S311>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/P Copy/Internal Parameters Ideal'
 * '<S312>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Parallel P Gain/Disabled'
 * '<S313>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Parallel P Gain/External Parameters'
 * '<S314>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Parallel P Gain/Internal Parameters'
 * '<S315>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Parallel P Gain/Passthrough'
 * '<S316>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Reset Signal/Disabled'
 * '<S317>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Reset Signal/External Reset'
 * '<S318>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation/Enabled'
 * '<S319>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation/Passthrough'
 * '<S320>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation Fdbk/Disabled'
 * '<S321>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation Fdbk/Enabled'
 * '<S322>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Saturation Fdbk/Passthrough'
 * '<S323>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum/Passthrough_I'
 * '<S324>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum/Passthrough_P'
 * '<S325>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum/Sum_PD'
 * '<S326>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum/Sum_PI'
 * '<S327>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum/Sum_PID'
 * '<S328>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum Fdbk/Disabled'
 * '<S329>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum Fdbk/Enabled'
 * '<S330>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Sum Fdbk/Passthrough'
 * '<S331>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Tracking Mode/Disabled'
 * '<S332>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Tracking Mode/Enabled'
 * '<S333>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Tracking Mode Sum/Passthrough'
 * '<S334>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/Tracking Mode Sum/Tracking Mode'
 * '<S335>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/postSat Signal/Feedback_Path'
 * '<S336>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/postSat Signal/Forward_Path'
 * '<S337>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/preSat Signal/Feedback_Path'
 * '<S338>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Gestione controllori di quota/PI RC saturato/preSat Signal/Forward_Path'
 * '<S339>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
 * '<S340>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/AL'
 * '<S341>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
 * '<S342>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
 * '<S343>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
 * '<S344>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
 * '<S345>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
 * '<S346>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
 * '<S347>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
 * '<S348>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
 * '<S349>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
 * '<S350>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
 * '<S351>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
 * '<S352>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
 * '<S353>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
 * '<S354>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
 * '<S355>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
 * '<S356>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
 * '<S357>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
 * '<S358>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
 * '<S359>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
 * '<S360>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
 * '<S361>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
 * '<S362>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
 * '<S363>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
 * '<S364>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
 * '<S365>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
 * '<S366>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Back Calculation'
 * '<S367>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Cont. Clamping Ideal'
 * '<S368>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Cont. Clamping Parallel'
 * '<S369>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disabled'
 * '<S370>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Ideal'
 * '<S371>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S372>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Passthrough'
 * '<S373>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/Disabled'
 * '<S374>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
 * '<S375>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/Internal Parameters'
 * '<S376>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Cont. Filter'
 * '<S377>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Differentiator'
 * '<S378>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disabled'
 * '<S379>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Backward Euler Filter'
 * '<S380>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S381>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Trapezoidal Filter'
 * '<S382>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Disabled'
 * '<S383>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/External IC'
 * '<S384>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S385>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S386>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/Disabled'
 * '<S387>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
 * '<S388>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/Internal Parameters'
 * '<S389>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/External Parameters'
 * '<S390>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Internal Parameters'
 * '<S391>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
 * '<S392>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S393>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/External Parameters'
 * '<S394>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Internal Parameters'
 * '<S395>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Passthrough'
 * '<S396>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Continuous'
 * '<S397>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Disabled'
 * '<S398>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
 * '<S399>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Disabled'
 * '<S400>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/External IC'
 * '<S401>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
 * '<S402>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
 * '<S403>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S404>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/External Parameters'
 * '<S405>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Internal Parameters'
 * '<S406>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/Disabled'
 * '<S407>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
 * '<S408>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/Internal Parameters'
 * '<S409>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/Passthrough'
 * '<S410>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
 * '<S411>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/External Parameters Ideal'
 * '<S412>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Internal Parameters Ideal'
 * '<S413>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/Disabled'
 * '<S414>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
 * '<S415>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S416>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/Passthrough'
 * '<S417>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
 * '<S418>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/External Reset'
 * '<S419>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
 * '<S420>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Passthrough'
 * '<S421>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
 * '<S422>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Enabled'
 * '<S423>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Passthrough'
 * '<S424>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Passthrough_I'
 * '<S425>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Passthrough_P'
 * '<S426>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PD'
 * '<S427>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PI'
 * '<S428>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
 * '<S429>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
 * '<S430>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Enabled'
 * '<S431>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Passthrough'
 * '<S432>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Disabled'
 * '<S433>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
 * '<S434>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S435>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S436>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Feedback_Path'
 * '<S437>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
 * '<S438>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Feedback_Path'
 * '<S439>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
 * '<S440>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
 * '<S441>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
 * '<S442>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
 * '<S443>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
 * '<S444>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
 * '<S445>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
 * '<S446>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
 * '<S447>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
 * '<S448>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
 * '<S449>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
 * '<S450>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
 * '<S451>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
 * '<S452>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
 * '<S453>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
 * '<S454>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
 * '<S455>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
 * '<S456>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
 * '<S457>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
 * '<S458>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
 * '<S459>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
 * '<S460>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
 * '<S461>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
 * '<S462>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
 * '<S463>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
 * '<S464>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
 * '<S465>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
 * '<S466>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Back Calculation'
 * '<S467>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S468>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S469>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disabled'
 * '<S470>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S471>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S472>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Passthrough'
 * '<S473>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
 * '<S474>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/External Parameters'
 * '<S475>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Internal Parameters'
 * '<S476>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Cont. Filter'
 * '<S477>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Differentiator'
 * '<S478>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
 * '<S479>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S480>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S481>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S482>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
 * '<S483>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/External IC'
 * '<S484>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S485>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S486>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/Disabled'
 * '<S487>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
 * '<S488>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/Internal Parameters'
 * '<S489>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/External Parameters'
 * '<S490>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S491>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
 * '<S492>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S493>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S494>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S495>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S496>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Continuous'
 * '<S497>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Disabled'
 * '<S498>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
 * '<S499>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Disabled'
 * '<S500>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/External IC'
 * '<S501>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
 * '<S502>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled'
 * '<S503>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S504>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/External Parameters'
 * '<S505>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Internal Parameters'
 * '<S506>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
 * '<S507>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/External Parameters'
 * '<S508>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Internal Parameters'
 * '<S509>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Passthrough'
 * '<S510>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
 * '<S511>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/External Parameters Ideal'
 * '<S512>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S513>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/Disabled'
 * '<S514>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
 * '<S515>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S516>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/Passthrough'
 * '<S517>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
 * '<S518>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/External Reset'
 * '<S519>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
 * '<S520>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Passthrough'
 * '<S521>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
 * '<S522>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Enabled'
 * '<S523>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Passthrough'
 * '<S524>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Passthrough_I'
 * '<S525>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Passthrough_P'
 * '<S526>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PD'
 * '<S527>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
 * '<S528>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PID'
 * '<S529>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
 * '<S530>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Enabled'
 * '<S531>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Passthrough'
 * '<S532>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Disabled'
 * '<S533>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
 * '<S534>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S535>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S536>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Feedback_Path'
 * '<S537>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
 * '<S538>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Feedback_Path'
 * '<S539>' : 'load_arduino_v_13/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
 * '<S540>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA'
 * '<S541>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
 * '<S542>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
 * '<S543>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
 * '<S544>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
 * '<S545>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Radians to Degrees'
 * '<S546>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Radians to Degrees1'
 * '<S547>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Radians to Degrees2'
 * '<S548>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem2'
 * '<S549>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem3'
 * '<S550>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem4'
 * '<S551>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/CONTROLLORE DI IMBARDATA/Subsystem5'
 * '<S552>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
 * '<S553>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
 * '<S554>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
 * '<S555>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
 * '<S556>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
 * '<S557>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
 * '<S558>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
 * '<S559>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
 * '<S560>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
 * '<S561>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
 * '<S562>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
 * '<S563>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
 * '<S564>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
 * '<S565>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
 * '<S566>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
 * '<S567>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
 * '<S568>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
 * '<S569>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
 * '<S570>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
 * '<S571>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
 * '<S572>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
 * '<S573>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
 * '<S574>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
 * '<S575>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
 * '<S576>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
 * '<S577>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
 * '<S578>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S579>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S580>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Disabled'
 * '<S581>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S582>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S583>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Passthrough'
 * '<S584>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
 * '<S585>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/External Parameters'
 * '<S586>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Internal Parameters'
 * '<S587>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Cont. Filter'
 * '<S588>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Differentiator'
 * '<S589>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
 * '<S590>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S591>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S592>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S593>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
 * '<S594>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/External IC'
 * '<S595>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S596>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S597>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/Disabled'
 * '<S598>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
 * '<S599>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/Internal Parameters'
 * '<S600>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/External Parameters'
 * '<S601>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S602>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S603>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S604>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S605>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S606>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S607>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Continuous'
 * '<S608>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Disabled'
 * '<S609>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
 * '<S610>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Disabled'
 * '<S611>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/External IC'
 * '<S612>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
 * '<S613>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled'
 * '<S614>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S615>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/External Parameters'
 * '<S616>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Internal Parameters'
 * '<S617>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
 * '<S618>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/External Parameters'
 * '<S619>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Internal Parameters'
 * '<S620>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Passthrough'
 * '<S621>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
 * '<S622>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/External Parameters Ideal'
 * '<S623>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S624>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/Disabled'
 * '<S625>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
 * '<S626>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S627>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/Passthrough'
 * '<S628>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
 * '<S629>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/External Reset'
 * '<S630>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
 * '<S631>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Passthrough'
 * '<S632>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S633>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Enabled'
 * '<S634>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Passthrough'
 * '<S635>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Passthrough_I'
 * '<S636>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Passthrough_P'
 * '<S637>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PD'
 * '<S638>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
 * '<S639>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PID'
 * '<S640>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
 * '<S641>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Enabled'
 * '<S642>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Passthrough'
 * '<S643>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Disabled'
 * '<S644>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
 * '<S645>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S646>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S647>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Feedback_Path'
 * '<S648>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
 * '<S649>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Feedback_Path'
 * '<S650>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
 * '<S651>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
 * '<S652>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
 * '<S653>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
 * '<S654>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
 * '<S655>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
 * '<S656>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
 * '<S657>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
 * '<S658>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
 * '<S659>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
 * '<S660>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
 * '<S661>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
 * '<S662>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
 * '<S663>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
 * '<S664>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
 * '<S665>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
 * '<S666>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
 * '<S667>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
 * '<S668>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
 * '<S669>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
 * '<S670>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
 * '<S671>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
 * '<S672>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
 * '<S673>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
 * '<S674>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
 * '<S675>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
 * '<S676>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S677>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S678>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Disabled'
 * '<S679>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S680>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S681>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Passthrough'
 * '<S682>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
 * '<S683>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/External Parameters'
 * '<S684>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Internal Parameters'
 * '<S685>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Cont. Filter'
 * '<S686>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Differentiator'
 * '<S687>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
 * '<S688>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S689>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S690>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S691>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
 * '<S692>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/External IC'
 * '<S693>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S694>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S695>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/Disabled'
 * '<S696>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
 * '<S697>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/Internal Parameters'
 * '<S698>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/External Parameters'
 * '<S699>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S700>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
 * '<S701>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S702>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S703>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S704>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S705>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Continuous'
 * '<S706>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Disabled'
 * '<S707>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
 * '<S708>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Disabled'
 * '<S709>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/External IC'
 * '<S710>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
 * '<S711>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled'
 * '<S712>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S713>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/External Parameters'
 * '<S714>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Internal Parameters'
 * '<S715>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
 * '<S716>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/External Parameters'
 * '<S717>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Internal Parameters'
 * '<S718>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Passthrough'
 * '<S719>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
 * '<S720>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/External Parameters Ideal'
 * '<S721>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S722>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/Disabled'
 * '<S723>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
 * '<S724>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S725>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/Passthrough'
 * '<S726>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/Disabled'
 * '<S727>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
 * '<S728>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
 * '<S729>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Passthrough'
 * '<S730>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
 * '<S731>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Enabled'
 * '<S732>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Passthrough'
 * '<S733>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Passthrough_I'
 * '<S734>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Passthrough_P'
 * '<S735>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PD'
 * '<S736>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
 * '<S737>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PID'
 * '<S738>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
 * '<S739>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Enabled'
 * '<S740>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Passthrough'
 * '<S741>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Disabled'
 * '<S742>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
 * '<S743>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S744>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S745>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Feedback_Path'
 * '<S746>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
 * '<S747>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Feedback_Path'
 * '<S748>' : 'load_arduino_v_13/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
 * '<S749>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
 * '<S750>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
 * '<S751>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
 * '<S752>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
 * '<S753>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
 * '<S754>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
 * '<S755>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
 * '<S756>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
 * '<S757>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
 * '<S758>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
 * '<S759>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
 * '<S760>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
 * '<S761>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
 * '<S762>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
 * '<S763>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
 * '<S764>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
 * '<S765>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
 * '<S766>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
 * '<S767>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
 * '<S768>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
 * '<S769>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
 * '<S770>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
 * '<S771>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
 * '<S772>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
 * '<S773>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
 * '<S774>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
 * '<S775>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
 * '<S776>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
 * '<S777>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
 * '<S778>' : 'load_arduino_v_13/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
 * '<S779>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Chart'
 * '<S780>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
 * '<S781>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem'
 * '<S782>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1'
 * '<S783>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem2'
 * '<S784>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem3'
 * '<S785>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
 * '<S786>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
 * '<S787>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
 * '<S788>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
 * '<S789>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
 * '<S790>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
 * '<S791>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
 * '<S792>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
 * '<S793>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
 * '<S794>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
 * '<S795>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
 * '<S796>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
 * '<S797>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
 * '<S798>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
 * '<S799>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
 * '<S800>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
 * '<S801>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
 * '<S802>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
 * '<S803>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
 * '<S804>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
 * '<S805>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
 * '<S806>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
 * '<S807>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
 * '<S808>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
 * '<S809>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
 * '<S810>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
 * '<S811>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
 * '<S812>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
 * '<S813>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/FLARE/MATLAB Function'
 * '<S814>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
 * '<S815>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
 * '<S816>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
 * '<S817>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
 * '<S818>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
 * '<S819>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
 * '<S820>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
 * '<S821>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
 * '<S822>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
 * '<S823>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
 * '<S824>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
 * '<S825>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
 * '<S826>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
 * '<S827>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
 * '<S828>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
 * '<S829>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
 * '<S830>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
 * '<S831>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
 * '<S832>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
 * '<S833>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
 * '<S834>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
 * '<S835>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
 * '<S836>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
 * '<S837>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
 * '<S838>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Back Calculation'
 * '<S839>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S840>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S841>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Disabled'
 * '<S842>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S843>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S844>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
 * '<S845>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
 * '<S846>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/External Parameters'
 * '<S847>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Internal Parameters'
 * '<S848>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Cont. Filter'
 * '<S849>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Differentiator'
 * '<S850>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
 * '<S851>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S852>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S853>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S854>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
 * '<S855>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/External IC'
 * '<S856>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S857>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S858>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/Disabled'
 * '<S859>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
 * '<S860>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/Internal Parameters'
 * '<S861>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/External Parameters'
 * '<S862>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S863>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
 * '<S864>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S865>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S866>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S867>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S868>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Continuous'
 * '<S869>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Disabled'
 * '<S870>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
 * '<S871>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Disabled'
 * '<S872>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/External IC'
 * '<S873>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
 * '<S874>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled'
 * '<S875>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S876>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/External Parameters'
 * '<S877>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Internal Parameters'
 * '<S878>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
 * '<S879>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/External Parameters'
 * '<S880>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Internal Parameters'
 * '<S881>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Passthrough'
 * '<S882>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
 * '<S883>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/External Parameters Ideal'
 * '<S884>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S885>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/Disabled'
 * '<S886>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
 * '<S887>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S888>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/Passthrough'
 * '<S889>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
 * '<S890>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/External Reset'
 * '<S891>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Enabled'
 * '<S892>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
 * '<S893>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
 * '<S894>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Enabled'
 * '<S895>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Passthrough'
 * '<S896>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Passthrough_I'
 * '<S897>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Passthrough_P'
 * '<S898>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PD'
 * '<S899>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
 * '<S900>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PID'
 * '<S901>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
 * '<S902>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Enabled'
 * '<S903>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Passthrough'
 * '<S904>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
 * '<S905>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Enabled'
 * '<S906>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S907>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S908>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Feedback_Path'
 * '<S909>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
 * '<S910>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Feedback_Path'
 * '<S911>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
 * '<S912>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
 * '<S913>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
 * '<S914>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
 * '<S915>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
 * '<S916>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
 * '<S917>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
 * '<S918>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S919>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S920>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S921>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S922>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
 * '<S923>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
 * '<S924>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
 * '<S925>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
 * '<S926>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S927>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
 * '<S928>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
 * '<S929>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
 * '<S930>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
 * '<S931>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
 * '<S932>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/e^4'
 * '<S933>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
 * '<S934>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
 * '<S935>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
 * '<S936>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
 * '<S937>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
 * '<S938>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
 * '<S939>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
 * '<S940>' : 'load_arduino_v_13/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
 * '<S941>' : 'load_arduino_v_13/LED 13-44/Digital Output'
 * '<S942>' : 'load_arduino_v_13/LED 13-44/Digital Output1'
 * '<S943>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
 * '<S944>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
 * '<S945>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
 * '<S946>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S947>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry'
 * '<S948>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians'
 * '<S949>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians1'
 * '<S950>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians2'
 * '<S951>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass'
 * '<S952>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees'
 * '<S953>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees1'
 * '<S954>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees2'
 * '<S955>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1'
 * '<S956>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS'
 * '<S957>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS/MATLAB Function'
 * '<S958>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function'
 * '<S959>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function1'
 * '<S960>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem1'
 * '<S961>' : 'load_arduino_v_13/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem2'
 * '<S962>' : 'load_arduino_v_13/Misure Sensori/ATTOPILOT'
 * '<S963>' : 'load_arduino_v_13/Misure Sensori/BMP_280'
 * '<S964>' : 'load_arduino_v_13/Misure Sensori/GPS_Venus'
 * '<S965>' : 'load_arduino_v_13/Misure Sensori/X-Sense MTi'
 * '<S966>' : 'load_arduino_v_13/Misure Sensori/ATTOPILOT/Scalatura_bit_to_percent_Volt'
 * '<S967>' : 'load_arduino_v_13/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S968>' : 'load_arduino_v_13/Misure Sensori/BMP_280/Execution_loop'
 * '<S969>' : 'load_arduino_v_13/Misure Sensori/BMP_280/MATLAB Function'
 * '<S970>' : 'load_arduino_v_13/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S971>' : 'load_arduino_v_13/Misure Sensori/BMP_280/One_time_initialization'
 * '<S972>' : 'load_arduino_v_13/Misure Sensori/BMP_280/Subsystem'
 * '<S973>' : 'load_arduino_v_13/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S974>' : 'load_arduino_v_13/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S975>' : 'load_arduino_v_13/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S976>' : 'load_arduino_v_13/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S977>' : 'load_arduino_v_13/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S978>' : 'load_arduino_v_13/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S979>' : 'load_arduino_v_13/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S980>' : 'load_arduino_v_13/Misure Sensori/X-Sense MTi/MATLAB Function1'
 * '<S981>' : 'load_arduino_v_13/RADIOCOMANDO/AILERON'
 * '<S982>' : 'load_arduino_v_13/RADIOCOMANDO/AILERON1'
 * '<S983>' : 'load_arduino_v_13/RADIOCOMANDO/ELEVATOR'
 * '<S984>' : 'load_arduino_v_13/RADIOCOMANDO/ELEVATOR1'
 * '<S985>' : 'load_arduino_v_13/RADIOCOMANDO/RUDDER'
 * '<S986>' : 'load_arduino_v_13/RADIOCOMANDO/THROTTLE'
 * '<S987>' : 'load_arduino_v_13/Servi/AILERON1'
 * '<S988>' : 'load_arduino_v_13/Servi/RUDDER6'
 * '<S989>' : 'load_arduino_v_13/Servi/THROTTLE1'
 * '<S990>' : 'load_arduino_v_13/Servi/elevator'
 */
#endif                                 /* RTW_HEADER_load_arduino_v_13_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
