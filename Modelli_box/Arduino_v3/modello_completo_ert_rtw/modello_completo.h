/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: modello_completo.h
 *
 * Code generated for Simulink model 'modello_completo'.
 *
 * Model version                  : 5.45
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May  4 15:32:50 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modello_completo_h_
#define RTW_HEADER_modello_completo_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef modello_completo_COMMON_INCLUDES_
#define modello_completo_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#endif                                 /* modello_completo_COMMON_INCLUDES_ */

#include "modello_completo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
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

/* Block states (default storage) for system '<S408>/Resettable Subsystem' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S419>/Memory' */
} DW_ResettableSubsystem_modell_T;

/* Zero-crossing (trigger) state for system '<S408>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_f;/* '<S408>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_model_T;

/* Block signals for system '<S567>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S574>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S574>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S574>/I2C Read' */
  int16_T I2CRead9;                    /* '<S574>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S574>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S574>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S574>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S574>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S574>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S574>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S574>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S574>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S574>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S574>/I2C Read12' */
} B_One_time_initialization_mod_T;

/* Block states (default storage) for system '<S567>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S574>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_i;/* '<S574>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_c;/* '<S574>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_b;/* '<S574>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_k;/* '<S574>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_co;/* '<S574>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_k4;/* '<S574>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_d;/* '<S574>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_ir;/* '<S574>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_l;/* '<S574>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_d0;/* '<S574>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_o;/* '<S574>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_kf;/* '<S574>/I2C Read' */
  codertarget_arduinobase_int_m_T obj_d01;/* '<S574>/I2C Write3' */
  codertarget_arduinobase_int_m_T obj_in;/* '<S574>/I2C Write2' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S574>/I2C Write1' */
} DW_One_time_initialization_mo_T;

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion4_m[42];    /* '<S440>/Data Type Conversion4' */
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  real_T WP_param_c[21];               /* '<S453>/AUTOLANDING_WAYPOINTS' */
  real_T a[16];
  real_T A[16];
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_i[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio_k[80];
  uint8_T messaggio_b[80];             /* '<S579>/Create_message' */
  boolean_T messaggio_c[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S581>/Complex to Real-Imag' */
  real_T DataTypeConversion1_pb[9];    /* '<S7>/Data Type Conversion1' */
  uint8_T dataIn[63];
  real32_T ByteUnpack_o2[9];           /* '<S569>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S569>/Byte Reversal' */
  real_T x_new[4];
  uint8_T b_dataOut[32];
  uint8_T b_dataOut_c[31];
  real_T lat_end[3];                   /* '<S453>/MATLAB Function' */
  uint128m_T r;
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint16_T WP_info[6];                 /* '<S23>/MATLAB Function' */
  uint16_T WP_info_in[6];
  uint64m_T a_n;
  uint64m_T p16;
  uint64m_T sk;
  uint64m_T r3;
  uint32_T i2cname;
  real_T Switch;                       /* '<S578>/Switch' */
  real_T h_goHome;                     /* '<S442>/GO_HOME' */
  real_T QUOTA;                        /* '<S441>/WAYPOINTS' */
  real_T Gain;                         /* '<S458>/Gain' */
  real_T Gain_g;                       /* '<S459>/Gain' */
  real_T QUOTA_m;/* '<S440>/Switch di selezione  Task - Waypoint navigation4' */
  real_T In[2];                        /* '<S465>/In' */
  real_T Sum2;                         /* '<S455>/Sum2' */
  real_T maneuver_selector;            /* '<S440>/Chart1' */
  real_T trig_approach;                /* '<S440>/Chart1' */
  real_T trig_flare;                   /* '<S440>/Chart1' */
  real_T approach_selector;            /* '<S440>/Chart1' */
  real_T h_Home;                     /* '<S440>/CALIBRATING_HOME_COORDINATES' */
  real_T Multiply;                     /* '<S451>/Multiply' */
  real_T x_f_out;                      /* '<S451>/MATLAB Function' */
  real_T h_f_out;                      /* '<S451>/MATLAB Function' */
  real_T k_x_out;                      /* '<S451>/MATLAB Function' */
  real_T h_c_out;                      /* '<S451>/MATLAB Function' */
  real_T no_solution;                  /* '<S451>/MATLAB Function' */
  real_T h_vett;                       /* '<S439>/VETTORIALE' */
  real_T Fase_ATO;                     /* '<S438>/Chart1' */
  real_T eq_rot;                       /* '<S438>/Chart1' */
  real_T h_ref;                        /* '<S438>/Chart1' */
  real_T psi_ref_selector;             /* '<S438>/Chart1' */
  real_T theta_ground_selector;        /* '<S438>/Chart1' */
  real_T Switch_n;                     /* '<S434>/Switch' */
  real_T Switch_l;                     /* '<S420>/Switch' */
  real_T switch_manetta;               /* '<S38>/ STATI' */
  real_T switch_equilibratore;         /* '<S38>/ STATI' */
  real_T switch_alettoni;              /* '<S38>/ STATI' */
  real_T switch_timone;                /* '<S38>/ STATI' */
  real_T modo;                         /* '<S38>/ STATI' */
  real_T denAccum;
  real_T num_254;
  real_T dist;
  real_T dist_fut;
  real_T Product1;                     /* '<S563>/Product1' */
  real_T IProdOut;                     /* '<S337>/IProd Out' */
  real_T Gain3;                        /* '<S554>/Gain3' */
  real_T PWM_rudder_p;                 /* '<S9>/Data Type Conversion' */
  real_T PWM_elevator_l;               /* '<S9>/Data Type Conversion2' */
  real_T Gain1_p;                      /* '<S556>/Gain1' */
  real_T Gain1_f;                      /* '<S555>/Gain1' */
  real_T Gain1_c;                      /* '<S551>/Gain1' */
  real_T Gain1_j;                      /* '<S550>/Gain1' */
  real_T Sum2_o;                       /* '<S303>/Sum2' */
  real_T Sum_n3;                       /* '<S399>/Sum' */
  real_T Sum_o;                        /* '<S303>/Sum' */
  real_T Sum3_b;                       /* '<S583>/Sum3' */
  real_T Sum_nu;                       /* '<S349>/Sum' */
  real_T Sum3_o;                       /* '<S585>/Sum3' */
  real_T Switch_bk;                    /* '<S534>/Switch' */
  real_T deltafalllimit;               /* '<S570>/delta fall limit' */
  real_T Gain_n;                       /* '<S463>/Gain' */
  real_T Gain_o;                       /* '<S33>/Gain' */
  real_T SwitchBumpless2;              /* '<S302>/Switch Bumpless 2' */
  real_T Go_Home;                      /* '<S9>/Switch' */
  real_T RateTransition;               /* '<S27>/Rate Transition' */
  real_T Gain1_kx;                     /* '<S553>/Gain1' */
  real_T Alettoni;                     /* '<S37>/saturatore A' */
  real_T Saturation;                   /* '<S347>/Saturation' */
  real_T Saturation_f;                 /* '<S397>/Saturation' */
  real_T Go_home_selector;
  real_T Al_selector;
  real_T a_fut_tmp;
  real_T Ato_selector;
  real_T Vec_selector;
  real_T Wp_selector;
  real_T rtb_Gain1_i_idx_0;
  real_T rtb_Gain1_kw_idx_1;
  real_T rtb_Gain1_kw_idx_0;
  real_T rtb_Sum3_o_tmp;
  real_T rtb_Sum3_b_tmp;
  real_T b_a_tmp;
  real_T a_tmp_tmp;
  real_T psi_ref_tmp;
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
  int32_T messaggio_size_f[2];
  int32_T messaggio_size_g[2];
  int32_T messaggio_size_g1[2];
  int32_T messaggio_size_m[2];
  int32_T s1_size[2];
  boolean_T mess_type_b[5];
  char_T mess_type[5];
  char_T s1[5];
  int8_T p[4];
  int8_T ipiv[4];
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T Switch1;                    /* '<S575>/Switch1' */
  real32_T DataTypeConversion1[6];     /* '<S18>/Data Type Conversion1' */
  real32_T AGAC[4];                    /* '<S22>/Data Type Conversion' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion_l;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion4[4];     /* '<S554>/Data Type Conversion4' */
  real32_T T;                          /* '<S577>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S571>/S-Function Builder' */
  real32_T ByteUnpack_o2_e[4];         /* '<S566>/Byte Unpack' */
  real32_T WP_param[7];                /* '<S23>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T f;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_a[4];     /* '<S16>/Data Type Conversion' */
  int32_T DataTypeConversion1_i;       /* '<S571>/Data Type  Conversion1' */
  int32_T DataTypeConversion_ay;       /* '<S571>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_a;       /* '<S571>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  int32_T caso;
  int32_T g;
  int32_T ATO;
  int32_T AL;
  int32_T eb_data;
  int32_T c;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
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
  uint32_T DataTypeConversion8;        /* '<S554>/Data Type Conversion8' */
  uint32_T SFunctionBuilder1;          /* '<S571>/S-Function Builder1' */
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  char_T s1_l[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2_h;      /* '<S16>/Data Type Conversion2' */
  uint16_T Throttle;                   /* '<S22>/Data Type Conversion2' */
  uint16_T Heading[9];                 /* '<S20>/Data Type Conversion1' */
  uint16_T Memory_a;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion1_h[10];  /* '<S554>/Data Type Conversion1' */
  uint16_T ByteUnpack_o4[2];           /* '<S566>/Byte Unpack' */
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
  int16_T DataTypeConversion_lx[9];    /* '<S554>/Data Type Conversion' */
  int16_T DataTypeConversion_p;        /* '<S10>/Data Type Conversion' */
  int16_T DataTypeConversion1_c;       /* '<S10>/Data Type Conversion1' */
  int16_T DataTypeConversion2_j;       /* '<S10>/Data Type Conversion2' */
  int16_T Sum;                         /* '<S591>/Sum' */
  int16_T ByteUnpack_o3[4];            /* '<S566>/Byte Unpack' */
  uint8_T SFunctionBuilder[41];        /* '<S569>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S569>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1_h[100];  /* '<S1>/S-Function Builder' */
  uint8_T Memory_k[4];                 /* '<Root>/Memory' */
  uint16_T z;
  uint8_T ByteUnpack_o3_b;             /* '<S569>/Byte Unpack' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
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
  uint8_T BytePack[63];                /* '<S554>/Byte Pack' */
  uint8_T indice_dimario;              /* '<S581>/MATLAB Function' */
  uint8_T ByteUnpack_o1_o[2];          /* '<S566>/Byte Unpack' */
  uint8_T ByteUnpack_o5;               /* '<S566>/Byte Unpack' */
  uint8_T messaggio[31];               /* '<S562>/MATLAB Function' */
  uint8_T iflogic;                     /* '<S19>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S21>/Data Type Conversion3' */
  boolean_T HitCrossing;               /* '<S250>/Hit  Crossing' */
  B_One_time_initialization_mod_T One_time_initialization;/* '<S567>/One_time_initialization' */
} B_modello_completo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_gh_T obj; /* '<S554>/Serial Transmit' */
  codertarget_arduinobase_in_gh_T obj_o;/* '<S25>/Serial Transmit' */
  codertarget_arduinobase_int_g_T obj_e;/* '<S568>/Serial Receive1' */
  codertarget_arduinobase_int_g_T obj_m;/* '<S554>/Serial Receive' */
  codertarget_arduinobase_inter_T obj_f;/* '<S571>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S571>/I2C Read1' */
  codertarget_arduinobase_block_T obj_b;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S5>/Digital Output' */
  real_T SFunctionBuilder_DSTATE;      /* '<S569>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_l;    /* '<S1>/S-Function Builder' */
  real_T UnitDelay_DSTATE;             /* '<S563>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S340>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S390>/Integrator' */
  real_T DiscreteWashoutFilter_states; /* '<S304>/Discrete Washout Filter' */
  real_T DelayInput2_DSTATE;           /* '<S570>/Delay Input2' */
  real_T SFunctionBuilder10_DSTATE;    /* '<S10>/S-Function Builder10' */
  real_T SFunctionBuilder4_DSTATE;     /* '<S10>/S-Function Builder4' */
  real_T SFunctionBuilder5_DSTATE;     /* '<S10>/S-Function Builder5' */
  real_T SFunctionBuilder9_DSTATE;     /* '<S10>/S-Function Builder9' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S4>/S-Function Builder' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S451>/Discrete-Time Integrator' */
  volatile real_T RateTransition_Buffer0;/* '<S27>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S27>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S27>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S27>/Memory2' */
  real_T Memory_PreviousInput_l[9];    /* '<S581>/Memory' */
  real_T P_ref;                        /* '<S567>/MATLAB Function' */
  real_T rl_up;                        /* '<S567>/MATLAB Function' */
  real_T rl_dw;                        /* '<S567>/MATLAB Function' */
  real_T flag;                         /* '<S442>/GO_HOME' */
  real_T Memory4_PreviousInput;        /* '<S441>/Memory4' */
  real_T flag_m;                       /* '<S441>/WAYPOINTS' */
  real_T lat1;                         /* '<S441>/WAYPOINTS' */
  real_T long1;                        /* '<S441>/WAYPOINTS' */
  real_T Memory7_PreviousInput;        /* '<S440>/Memory7' */
  real_T Memory5_PreviousInput;        /* '<S440>/Memory5' */
  real_T Memory1_PreviousInput_l;      /* '<S440>/Memory1' */
  real_T Memory2_PreviousInput_f;      /* '<S440>/Memory2' */
  real_T x[4];                         /* '<S451>/MATLAB Function' */
  real_T cycle_count;                  /* '<S451>/MATLAB Function' */
  real_T eps[4];                       /* '<S451>/MATLAB Function' */
  real_T flag_c;                       /* '<S440>/ALLINEAMENTO' */
  real_T Memory3_PreviousInput;        /* '<S439>/Memory3' */
  real_T ALT_ref;                      /* '<S439>/VETTORIALE' */
  real_T Memory_PreviousInput_i;       /* '<S438>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S438>/Memory1' */
  real_T alarm;                        /* '<S415>/MATLAB Function1' */
  real_T Memory_PreviousInput_h;       /* '<S436>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S5>/Pulse Generator1' */
  int_T HitCrossing_MODE;              /* '<S250>/Hit  Crossing' */
  uint16_T Memory_PreviousInput_ic[8]; /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S567>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S390>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S451>/Discrete-Time Integrator' */
  uint8_T Memory4_PreviousInput_c[300];/* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput_l[100];/* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_d[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_h5[4];  /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput_o;     /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S579>/Create_message' */
  uint8_T counter_k;                   /* '<S579>/Create_message' */
  uint8_T message_k[31];               /* '<S562>/MATLAB Function' */
  uint8_T counter_n;                   /* '<S562>/MATLAB Function' */
  uint8_T is_active_c10_modello_completo;/* '<S440>/Chart1' */
  uint8_T is_c10_modello_completo;     /* '<S440>/Chart1' */
  uint8_T Memory1_PreviousInput_h;     /* '<S439>/Memory1' */
  uint8_T Memory6_PreviousInput;       /* '<S439>/Memory6' */
  uint8_T is_active_c1_modello_completo;/* '<S438>/Chart1' */
  uint8_T is_c1_modello_completo;      /* '<S438>/Chart1' */
  uint8_T temporalCounter_i1;          /* '<S438>/Chart1' */
  uint8_T is_active_c21_modello_completo;/* '<S39>/Chart' */
  uint8_T is_c21_modello_completo;     /* '<S39>/Chart' */
  uint8_T is_active_c26_modello_completo;/* '<S38>/ STATI' */
  uint8_T is_c26_modello_completo;     /* '<S38>/ STATI' */
  uint8_T is_AUTOMATICA;               /* '<S38>/ STATI' */
  uint8_T is_active_c23_modello_completo;
                                 /* '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_c23_modello_completo;
                                 /* '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_active_c9_modello_completo;/* '<S15>/Chart' */
  uint8_T i;                           /* '<S15>/Chart' */
  uint8_T message_i[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_a;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S579>/Create_message' */
  boolean_T end_found;                 /* '<S579>/Create_message' */
  boolean_T start_found_c;             /* '<S562>/MATLAB Function' */
  boolean_T x_not_empty;               /* '<S451>/MATLAB Function' */
  boolean_T x_new_not_empty;           /* '<S451>/MATLAB Function' */
  boolean_T cycle_count_not_empty;     /* '<S451>/MATLAB Function' */
  boolean_T eps_not_empty;             /* '<S451>/MATLAB Function' */
  boolean_T Tf_not_empty;              /* '<S410>/MATLAB Function1' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T Enabled_MODE;              /* '<S432>/Enabled ' */
  boolean_T Enabled_MODE_p;            /* '<S424>/Enabled ' */
  boolean_T Enabled_MODE_m;            /* '<S423>/Enabled ' */
  DW_One_time_initialization_mo_T One_time_initialization;/* '<S567>/One_time_initialization' */
  DW_ResettableSubsystem_modell_T ResettableSubsystem_o;/* '<S409>/Resettable Subsystem' */
  DW_ResettableSubsystem_modell_T ResettableSubsystem;/* '<S408>/Resettable Subsystem' */
} DW_modello_completo_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S250>/Hit  Crossing' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S440>/Sample and Hold' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S438>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE_h; /* '<S438>/Sample and Hold' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S432>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_h;/* '<S424>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_p;/* '<S423>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_model_T ResettableSubsystem_o;/* '<S409>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_model_T ResettableSubsystem;/* '<S408>/Resettable Subsystem' */
  ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S250>/Enabled Subsystem' */
} PrevZCX_modello_completo_T;

/* Parameters for system: '<S408>/Enabled Subsystem' */
struct P_EnabledSubsystem_modello_co_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S417>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S417>/Constant2'
                                        */
  real_T u0_Y0;                        /* Computed Parameter: u0_Y0
                                        * Referenced by: '<S417>/1//0'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S417>/Switch'
                                        */
};

/* Parameters for system: '<S408>/Resettable Subsystem' */
struct P_ResettableSubsystem_modello_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S419>/Memory'
                                        */
};

/* Parameters for system: '<S567>/One_time_initialization' */
struct P_One_time_initialization_mod_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S574>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S574>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S574>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S574>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S574>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S574>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S574>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S574>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S574>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S574>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S574>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S574>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S574>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S574>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S574>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S574>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S574>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S574>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_modello_completo_T_ {
  real_T Kp_comp_h;                    /* Variable: Kp_comp_h
                                        * Referenced by: '<S302>/Constant3'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S37>/saturatore A'
                                        *   '<S37>/saturatore A1'
                                        *   '<S583>/Constant8'
                                        *   '<S589>/Constant'
                                        *   '<S397>/Saturation'
                                        */
  real_T attuatore_Amin;               /* Variable: attuatore_Amin
                                        * Referenced by:
                                        *   '<S37>/saturatore A'
                                        *   '<S37>/saturatore A1'
                                        *   '<S583>/Constant9'
                                        *   '<S589>/Constant1'
                                        *   '<S397>/Saturation'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S585>/Constant8'
                                        *   '<S592>/Constant'
                                        *   '<S302>/saturatore E2'
                                        *   '<S347>/Saturation'
                                        */
  real_T attuatore_Emin;               /* Variable: attuatore_Emin
                                        * Referenced by:
                                        *   '<S585>/Constant9'
                                        *   '<S592>/Constant1'
                                        *   '<S302>/saturatore E2'
                                        *   '<S347>/Saturation'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S37>/saturatore R'
                                        *   '<S587>/Constant8'
                                        *   '<S590>/Constant'
                                        */
  real_T attuatore_Rmin;               /* Variable: attuatore_Rmin
                                        * Referenced by:
                                        *   '<S37>/saturatore R'
                                        *   '<S587>/Constant9'
                                        *   '<S590>/Constant1'
                                        */
  real_T attuatore_Tmax;               /* Variable: attuatore_Tmax
                                        * Referenced by: '<S588>/manetta_massima'
                                        */
  real_T attuatore_Tmin;               /* Variable: attuatore_Tmin
                                        * Referenced by: '<S588>/manetta_minima'
                                        */
  real_T interventoA_05;               /* Variable: interventoA_05
                                        * Referenced by: '<S410>/Constant4'
                                        */
  real_T interventoA_1;                /* Variable: interventoA_1
                                        * Referenced by: '<S410>/Constant3'
                                        */
  real_T interventoE_05;               /* Variable: interventoE_05
                                        * Referenced by: '<S410>/Constant1'
                                        */
  real_T interventoE_1;                /* Variable: interventoE_1
                                        * Referenced by: '<S410>/Constant'
                                        */
  real_T interventoT;                  /* Variable: interventoT
                                        * Referenced by: '<S410>/Constant2'
                                        */
  real_T inv_A;                        /* Variable: inv_A
                                        * Referenced by: '<S37>/Gain1'
                                        */
  real_T inv_E;                        /* Variable: inv_E
                                        * Referenced by: '<S37>/Gain'
                                        */
  real_T inv_R;                        /* Variable: inv_R
                                        * Referenced by: '<S37>/Gain2'
                                        */
  real_T inv_comp_h;                   /* Variable: inv_comp_h
                                        * Referenced by: '<S302>/Gain'
                                        */
  real_T phi_max;                      /* Variable: phi_max
                                        * Referenced by:
                                        *   '<S584>/Constant8'
                                        *   '<S584>/Saturation'
                                        */
  real_T phi_min;                      /* Variable: phi_min
                                        * Referenced by:
                                        *   '<S584>/Constant9'
                                        *   '<S584>/Saturation'
                                        */
  real_T safe_V;                       /* Variable: safe_V
                                        * Referenced by: '<S415>/Constant'
                                        */
  real_T safe_phi;                     /* Variable: safe_phi
                                        * Referenced by: '<S415>/Constant1'
                                        */
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S571>/I2C Read1'
                                        *   '<S571>/I2C Read12'
                                        *   '<S574>/I2C Read'
                                        *   '<S574>/I2C Read1'
                                        *   '<S574>/I2C Read10'
                                        *   '<S574>/I2C Read11'
                                        *   '<S574>/I2C Read2'
                                        *   '<S574>/I2C Read3'
                                        *   '<S574>/I2C Read4'
                                        *   '<S574>/I2C Read5'
                                        *   '<S574>/I2C Read6'
                                        *   '<S574>/I2C Read7'
                                        *   '<S574>/I2C Read8'
                                        *   '<S574>/I2C Read9'
                                        *   '<S419>/Constant4'
                                        *   '<S422>/Constant4'
                                        *   '<S436>/Constant4'
                                        */
  real_T theta_max;                    /* Variable: theta_max
                                        * Referenced by:
                                        *   '<S586>/Constant8'
                                        *   '<S586>/Saturation'
                                        */
  real_T theta_min;                    /* Variable: theta_min
                                        * Referenced by:
                                        *   '<S586>/Constant9'
                                        *   '<S586>/Saturation'
                                        */
  real_T time_alarm_SAFE;              /* Variable: time_alarm_SAFE
                                        * Referenced by: '<S434>/Switch'
                                        */
  real_T vel_wp1_al;                   /* Variable: vel_wp1_al
                                        * Referenced by: '<S453>/Constant'
                                        */
  real_T vel_wp2_al;                   /* Variable: vel_wp2_al
                                        * Referenced by: '<S453>/Constant1'
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
                               * Referenced by: '<S340>/Integrator'
                               */
  real_T PIDController_InitialConditio_d;
                              /* Mask Parameter: PIDController_InitialConditio_d
                               * Referenced by: '<S390>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S383>/Kb'
                                        */
  real_T PIDController_Kb_k;           /* Mask Parameter: PIDController_Kb_k
                                        * Referenced by: '<S333>/Kb'
                                        */
  real_T PIDController_Kt;             /* Mask Parameter: PIDController_Kt
                                        * Referenced by: '<S401>/Kt'
                                        */
  real_T PIDController_Kt_m;           /* Mask Parameter: PIDController_Kt_m
                                        * Referenced by: '<S351>/Kt'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S535>/Constant'
                                       */
  real_T CompareToConstant_const_d; /* Mask Parameter: CompareToConstant_const_d
                                     * Referenced by: '<S533>/Constant'
                                     */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S536>/Constant'
                                     */
  real_T CompareToConstant_const_b; /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S529>/Constant'
                                     */
  real_T CompareToConstant_const_dp;
                                   /* Mask Parameter: CompareToConstant_const_dp
                                    * Referenced by: '<S527>/Constant'
                                    */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S530>/Constant'
                                     */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S25>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S34>/Constant2'
                                        */
  real_T Out1_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S301>/Out1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S307>/Constant5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 16
                                        * Referenced by: '<S307>/Switch1'
                                        */
  real_T r_rif_Value;                  /* Expression: 0
                                        * Referenced by: '<S37>/r_rif'
                                        */
  real_T Alarm_Int_Y0;                 /* Expression: 0
                                        * Referenced by: '<S426>/Alarm_Int'
                                        */
  real_T Alarm_Int_Y0_j;               /* Expression: 0
                                        * Referenced by: '<S429>/Alarm_Int'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S434>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S434>/Constant1'
                                        */
  real_T AlarmSafe_Y0;                 /* Expression: 0
                                        * Referenced by: '<S434>/Alarm Safe'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S436>/Memory'
                                        */
  real_T Constant1_Value_d;            /* Expression: 20
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S413>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 50
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S446>/ '
                                        */
  real_T _Y0_a;                        /* Expression: initCond
                                        * Referenced by: '<S447>/ '
                                        */
  real_T Gain_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S445>/Gain'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S438>/Memory'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S444>/Gain'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S438>/Memory1'
                                        */
  real_T Out1_Y0_d;                    /* Computed Parameter: Out1_Y0_d
                                        * Referenced by: '<S439>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S439>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S439>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S439>/Out4'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S439>/Memory3'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S448>/Gain'
                                        */
  real_T h_ref_Y0;                     /* Computed Parameter: h_ref_Y0
                                        * Referenced by: '<S451>/h_ref'
                                        */
  real_T flare_data_Y0;                /* Computed Parameter: flare_data_Y0
                                        * Referenced by: '<S451>/flare_data'
                                        */
  real_T landing_abort_Y0;             /* Computed Parameter: landing_abort_Y0
                                        * Referenced by: '<S451>/landing_abort'
                                        */
  real_T rc_ref_app_Y0;                /* Computed Parameter: rc_ref_app_Y0
                                        * Referenced by: '<S451>/rc_ref_app'
                                        */
  real_T x_g0_Value;                   /* Expression: -100
                                        * Referenced by: '<S451>/x_g0'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S451>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S451>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S451>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S451>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S451>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S451>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S451>/Switch'
                                        */
  real_T Gain_Gain_e0;                 /* Expression: -1
                                        * Referenced by: '<S451>/Gain'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S451>/Constant2'
                                        */
  real_T h_ref_Y0_n;                   /* Computed Parameter: h_ref_Y0_n
                                        * Referenced by: '<S455>/h_ref'
                                        */
  real_T RC_ref_Y0;                    /* Computed Parameter: RC_ref_Y0
                                        * Referenced by: '<S455>/RC_ref'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S455>/Gain'
                                        */
  real_T psi_ref_landing_Y0;           /* Computed Parameter: psi_ref_landing_Y0
                                        * Referenced by: '<S456>/psi_ref_landing'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S525>/Bias'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S525>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S525>/Bias1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 360
                                        * Referenced by: '<S528>/Constant2'
                                        */
  real_T Bias_Bias_n;                  /* Expression: 180
                                        * Referenced by: '<S528>/Bias'
                                        */
  real_T Bias1_Bias_n;                 /* Expression: -180
                                        * Referenced by: '<S528>/Bias1'
                                        */
  real_T Constant_Value_n;             /* Expression: 180
                                        * Referenced by: '<S522>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S522>/Constant1'
                                        */
  real_T Constant2_Value_gk;           /* Expression: 360
                                        * Referenced by: '<S526>/Constant2'
                                        */
  real_T Bias_Bias_j;                  /* Expression: 180
                                        * Referenced by: '<S526>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S526>/Bias1'
                                        */
  real_T Bias_Bias_f;                  /* Expression: -90
                                        * Referenced by: '<S531>/Bias'
                                        */
  real_T Gain_Gain_mn;                 /* Expression: -1
                                        * Referenced by: '<S531>/Gain'
                                        */
  real_T Bias1_Bias_f;                 /* Expression: +90
                                        * Referenced by: '<S531>/Bias1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 360
                                        * Referenced by: '<S534>/Constant2'
                                        */
  real_T Bias_Bias_e;                  /* Expression: 180
                                        * Referenced by: '<S534>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S534>/Bias1'
                                        */
  real_T Constant_Value_d;             /* Expression: 180
                                        * Referenced by: '<S523>/Constant'
                                        */
  real_T Constant1_Value_d5;           /* Expression: 0
                                        * Referenced by: '<S523>/Constant1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S532>/Constant2'
                                        */
  real_T Bias_Bias_jc;                 /* Expression: 180
                                        * Referenced by: '<S532>/Bias'
                                        */
  real_T Bias1_Bias_gb;                /* Expression: -180
                                        * Referenced by: '<S532>/Bias1'
                                        */
  real_T _Y0_b[2];                     /* Expression: initCond
                                        * Referenced by: '<S465>/ '
                                        */
  real_T Constant3_Value_c;            /* Expression: 1
                                        * Referenced by: '<S440>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S440>/Constant8'
                                        */
  real_T TAS_AL_Y0;                    /* Computed Parameter: TAS_AL_Y0
                                        * Referenced by: '<S440>/TAS_AL'
                                        */
  real_T QUOTA_AL_Y0;                  /* Computed Parameter: QUOTA_AL_Y0
                                        * Referenced by: '<S440>/QUOTA_AL'
                                        */
  real_T RC_AL_Y0;                     /* Computed Parameter: RC_AL_Y0
                                        * Referenced by: '<S440>/RC_AL'
                                        */
  real_T ROTTA_AL_Y0;                  /* Computed Parameter: ROTTA_AL_Y0
                                        * Referenced by: '<S440>/ROTTA_AL'
                                        */
  real_T H_LAT_Y0;                     /* Computed Parameter: H_LAT_Y0
                                        * Referenced by: '<S440>/H_LAT'
                                        */
  real_T H_LONG_Y0;                    /* Computed Parameter: H_LONG_Y0
                                        * Referenced by: '<S440>/H_LONG'
                                        */
  real_T H_ALT_Y0;                     /* Computed Parameter: H_ALT_Y0
                                        * Referenced by: '<S440>/H_ALT'
                                        */
  real_T distancewaypointsvirtuale_Value[3];/* Expression: [-1000 -800 2000]
                                             * Referenced by: '<S453>/distance waypoints virtuale'
                                             */
  real_T Gain_Gain_es;                 /* Expression: 180/pi
                                        * Referenced by: '<S469>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S470>/Gain'
                                        */
  real_T altwaypointvirtuale_Value[3]; /* Expression: [45 45 45]
                                        * Referenced by: '<S453>/alt waypoint virtuale'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S461>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S460>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S458>/Gain'
                                        */
  real_T Gain_Gain_b2;                 /* Expression: 180/pi
                                        * Referenced by: '<S459>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S521>/Gain1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 1
                                        * Referenced by: '<S537>/Constant2'
                                        */
  real_T Constant_Value_nw;            /* Expression: 1
                                        * Referenced by: '<S541>/Constant'
                                        */
  real_T Constant4_Value_o;            /* Expression: 1
                                        * Referenced by: '<S540>/Constant4'
                                        */
  real_T Constant_Value_j;             /* Expression: 1/298.257223563
                                        * Referenced by: '<S539>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S539>/f'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S538>/Gain1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 6378137
                                        * Referenced by: '<S537>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S537>/Constant'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S537>/Constant3'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S462>/Gain'
                                        */
  real_T Gain_Gain_ov;                 /* Expression: 180/pi
                                        * Referenced by: '<S463>/Gain'
                                        */
  real_T Gain_Gain_jp;                 /* Expression: 180/pi
                                        * Referenced by: '<S464>/Gain'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S440>/Memory7'
                                        */
  real_T Memory5_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S440>/Memory5'
                                        */
  real_T Memory1_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S440>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S440>/Memory2'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S440>/Constant4'
                                        */
  real_T Constant2_Value_n3;           /* Expression: 45
                                        * Referenced by: '<S440>/Constant2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 1
                                        * Referenced by: '<S440>/Switch2'
                                        */
  real_T RC_Y0;                        /* Computed Parameter: RC_Y0
                                        * Referenced by: '<S441>/RC'
                                        */
  real_T VELOCITA_Y0;                  /* Computed Parameter: VELOCITA_Y0
                                        * Referenced by: '<S441>/VELOCITA'
                                        */
  real_T Out3_Y0_j;                    /* Computed Parameter: Out3_Y0_j
                                        * Referenced by: '<S441>/Out3'
                                        */
  real_T Out4_Y0_m;                    /* Computed Parameter: Out4_Y0_m
                                        * Referenced by: '<S441>/Out4'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S441>/Memory4'
                                        */
  real_T Gain_Gain_bu;                 /* Expression: 180/pi
                                        * Referenced by: '<S542>/Gain'
                                        */
  real_T Gain_Gain_jz;                 /* Expression: 180/pi
                                        * Referenced by: '<S543>/Gain'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 180/pi
                                        * Referenced by: '<S544>/Gain'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S442>/Out1'
                                        */
  real_T Out2_Y0_c;                    /* Computed Parameter: Out2_Y0_c
                                        * Referenced by: '<S442>/Out2'
                                        */
  real_T Out3_Y0_d;                    /* Computed Parameter: Out3_Y0_d
                                        * Referenced by: '<S442>/Out3'
                                        */
  real_T Out4_Y0_c;                    /* Computed Parameter: Out4_Y0_c
                                        * Referenced by: '<S442>/Out4'
                                        */
  real_T Gain_Gain_ji;                 /* Expression: 180/pi
                                        * Referenced by: '<S547>/Gain'
                                        */
  real_T Gain_Gain_gf;                 /* Expression: 180/pi
                                        * Referenced by: '<S548>/Gain'
                                        */
  real_T Gain_Gain_ov4;                /* Expression: 180/pi
                                        * Referenced by: '<S549>/Gain'
                                        */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<S554>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol_b;    /* Expression: 0
                                        * Referenced by: '<S554>/Serial Transmit'
                                        */
  real_T Constant1_Value_o;            /* Expression: 16
                                        * Referenced by: '<S571>/Constant1'
                                        */
  real_T Constant5_Value_n;            /* Expression: 8
                                        * Referenced by: '<S571>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S571>/Constant6'
                                        */
  real_T Constant4_Value_l;            /* Expression: 4
                                        * Referenced by: '<S571>/Constant4'
                                        */
  real_T Constant2_Value_a;            /* Expression: 16
                                        * Referenced by: '<S571>/Constant2'
                                        */
  real_T Constant3_Value_c0;           /* Expression: 8
                                        * Referenced by: '<S571>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S568>/Serial Receive1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S578>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S578>/h_to_subtract'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S578>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2
                                        * Referenced by: '<S578>/Constant1'
                                        */
  real_T Constant3_Value_ct;           /* Expression: 3
                                        * Referenced by: '<S578>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S581>/Outport'
                                        */
  real_T Memory_InitialCondition_ab;   /* Expression: 0
                                        * Referenced by: '<S581>/Memory'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_js;           /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant_Value_hx;            /* Expression: 15
                                        * Referenced by: '<S575>/Constant'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S27>/Rate Transition'
                                          */
  real_T Constant2_Value_jg;           /* Expression: 0
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant3'
                                        */
  real_T Memory1_InitialCondition_p;   /* Expression: -1
                                        * Referenced by: '<S27>/Memory1'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 4
                                        * Referenced by: '<S27>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0.02
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Memory_InitialCondition_au;   /* Expression: -0.02
                                        * Referenced by: '<S27>/Memory'
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
                                        * Referenced by: '<S554>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: tau
                                        * Referenced by: '<S563>/Constant'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.01
                                        * Referenced by: '<S554>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S563>/Unit Delay'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S550>/Gain1'
                                        */
  real_T Gain_Gain_mz;                 /* Expression: 180/pi
                                        * Referenced by: '<S412>/Gain'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant2'
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
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S551>/Gain1'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: pi/180
                                        * Referenced by: '<S552>/Gain1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S555>/Gain1'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S556>/Gain1'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S16>/alt_r'
                                        */
  real_T Gain_Gain_bx[4];              /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S554>/Gain4'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S16>/vel y'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S557>/Gain1'
                                        */
  real_T Gain1_Gain_n1;                /* Expression: pi/180
                                        * Referenced by: '<S553>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T airspeedgroundspeedaltclimb1_Va;/* Expression: 0
                                          * Referenced by: '<S22>/airspeed groundspeed alt climb1'
                                          */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Switch2_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S34>/Switch2'
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
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real_T Constant2_Value_i4;           /* Expression: 0
                                        * Referenced by: '<S302>/Constant2'
                                        */
  real_T Constant1_Value_fj;           /* Expression: 0
                                        * Referenced by: '<S302>/Constant1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 1
                                        * Referenced by: '<S586>/Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S340>/Integrator'
                                        */
  real_T Gain1_Gain_jm;                /* Expression: pi/180
                                        * Referenced by: '<S357>/Gain1'
                                        */
  real_T Gain_Gain_od;                 /* Expression: 180/pi
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Constant2_Value_m;            /* Expression: 90
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant1_Value_ng;           /* Expression: 0
                                        * Referenced by: '<S303>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S584>/Gain'
                                        */
  real_T Constant3_Value_cr;           /* Expression: 2
                                        * Referenced by: '<S303>/Constant3'
                                        */
  real_T Integrator_gainval_g;       /* Computed Parameter: Integrator_gainval_g
                                      * Referenced by: '<S390>/Integrator'
                                      */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T DiscreteWashoutFilter_NumCoef[2];/* Expression: [ 1 -1]
                                           * Referenced by: '<S304>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_DenCoef[2];/* Expression: [1 -0.995]
                                           * Referenced by: '<S304>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_InitialSt;/* Expression: 0
                                          * Referenced by: '<S304>/Discrete Washout Filter'
                                          */
  real_T Gain_Gain_bh;                 /* Expression: 180/pi
                                        * Referenced by: '<S32>/Gain'
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
                                        * Referenced by: '<S570>/Delay Input2'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S570>/sample time'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Gain7_Gain;                   /* Expression: 100
                                        * Referenced by: '<S554>/Gain7'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T RC_default_Value;             /* Expression: 2
                                        * Referenced by: '<S39>/RC_default'
                                        */
  real_T Constant_Value_g;             /* Expression: 70
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant1_Value_jf;           /* Expression: 20
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S559>/Gain'
                                        */
  real_T Gain_Gain_db;                 /* Expression: 180/pi
                                        * Referenced by: '<S560>/Gain'
                                        */
  real_T Gain_Gain_dc;                 /* Expression: 180/pi
                                        * Referenced by: '<S561>/Gain'
                                        */
  real_T Gain_Gain_bk;                 /* Expression: 100
                                        * Referenced by: '<S554>/Gain'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 100
                                        * Referenced by: '<S554>/Gain2'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0.3
                                        * Referenced by: '<S250>/Hit  Crossing'
                                        */
  real_T Gain_Gain_je;                 /* Expression: 180/pi
                                        * Referenced by: '<S414>/Gain'
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
                                        * Referenced by: '<S27>/Constant4'
                                        */
  real_T Constant5_Value_a;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant5'
                                        */
  real_T Memory2_InitialCondition_o;   /* Expression: -1
                                        * Referenced by: '<S27>/Memory2'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 9
                                        * Referenced by: '<S27>/Switch1'
                                        */
  int32_T Constant_Value_gw;           /* Computed Parameter: Constant_Value_gw
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Out2_Y0_cb;                 /* Computed Parameter: Out2_Y0_cb
                                        * Referenced by: '<S566>/Out2'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S571>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S577>/T_0'
                                        */
  real32_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S575>/Switch'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S554>/Gain3'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S571>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S571>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S571>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S571>/Constant11'
                                        */
  uint32_T Constant8_Value_e;          /* Computed Parameter: Constant8_Value_e
                                        * Referenced by: '<S571>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S571>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S21>/onboard_control_sensor_present uint32'
                           */
  int16_T Out3_Y0_a;                   /* Computed Parameter: Out3_Y0_a
                                        * Referenced by: '<S566>/Out3'
                                        */
  int16_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S9>/Switch'
                                        */
  int16_T Gain1_Gain_eu;               /* Computed Parameter: Gain1_Gain_eu
                                        * Referenced by: '<S21>/Gain1'
                                        */
  uint16_T Out4_Y0_i;                  /* Computed Parameter: Out4_Y0_i
                                        * Referenced by: '<S566>/Out4'
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
  boolean_T UnitDelay_InitialCondition_l;
                             /* Computed Parameter: UnitDelay_InitialCondition_l
                              * Referenced by: '<S567>/Unit Delay'
                              */
  boolean_T Constant3_Value_ok;        /* Computed Parameter: Constant3_Value_ok
                                        * Referenced by: '<S567>/Constant3'
                                        */
  int8_T Gain3_Gain_o;                 /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S8>/Gain3'
                                        */
  uint8_T Memory_InitialCondition_j;
                                /* Computed Parameter: Memory_InitialCondition_j
                                 * Referenced by: '<S439>/Memory'
                                 */
  uint8_T Memory1_InitialCondition_g;
                               /* Computed Parameter: Memory1_InitialCondition_g
                                * Referenced by: '<S439>/Memory1'
                                */
  uint8_T Memory2_InitialCondition_n;
                               /* Computed Parameter: Memory2_InitialCondition_n
                                * Referenced by: '<S439>/Memory2'
                                */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S439>/Memory6'
                                  */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S581>/mario'
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
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S554>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S554>/Fine MSG1'
                                        */
  P_One_time_initialization_mod_T One_time_initialization;/* '<S567>/One_time_initialization' */
  P_ResettableSubsystem_modello_T ResettableSubsystem_o;/* '<S409>/Resettable Subsystem' */
  P_EnabledSubsystem_modello_co_T EnabledSubsystem_j;/* '<S409>/Enabled Subsystem' */
  P_ResettableSubsystem_modello_T ResettableSubsystem;/* '<S408>/Resettable Subsystem' */
  P_EnabledSubsystem_modello_co_T EnabledSubsystem_h;/* '<S408>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_modello_completo_T {
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
extern P_modello_completo_T modello_completo_P;

/* Block signals (default storage) */
extern B_modello_completo_T modello_completo_B;

/* Block states (default storage) */
extern DW_modello_completo_T modello_completo_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_modello_completo_T modello_completo_PrevZCX;

/* External data declarations for dependent source files */
extern const uint16_T modello_completo_U16GND;/* uint16_T ground */

/* External function called from main */
extern void modello_completo_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void modello_completo_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void modello_completo_initialize(void);
extern void modello_completo_step0(void);
extern void modello_completo_step1(void);
extern void modello_completo_step2(void);
extern void modello_completo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_modello_completo_T *const modello_completo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S43>/Constant1' : Unused code path elimination
 * Block '<S43>/Constant10' : Unused code path elimination
 * Block '<S43>/Constant11' : Unused code path elimination
 * Block '<S43>/Constant12' : Unused code path elimination
 * Block '<S43>/Constant13' : Unused code path elimination
 * Block '<S43>/Constant14' : Unused code path elimination
 * Block '<S43>/Constant15' : Unused code path elimination
 * Block '<S43>/Constant2' : Unused code path elimination
 * Block '<S43>/Constant3' : Unused code path elimination
 * Block '<S43>/Constant5' : Unused code path elimination
 * Block '<S43>/Constant7' : Unused code path elimination
 * Block '<S43>/Constant9' : Unused code path elimination
 * Block '<S43>/Multiport Switch' : Unused code path elimination
 * Block '<S43>/Multiport Switch1' : Unused code path elimination
 * Block '<S43>/Multiport Switch2' : Unused code path elimination
 * Block '<S74>/DProd Out' : Unused code path elimination
 * Block '<S75>/Filter' : Unused code path elimination
 * Block '<S75>/SumD' : Unused code path elimination
 * Block '<S77>/IProd Out' : Unused code path elimination
 * Block '<S80>/Integrator' : Unused code path elimination
 * Block '<S83>/NProd Out' : Unused code path elimination
 * Block '<S85>/PProd Out' : Unused code path elimination
 * Block '<S89>/Sum' : Unused code path elimination
 * Block '<S91>/Kt' : Unused code path elimination
 * Block '<S91>/SumI3' : Unused code path elimination
 * Block '<S92>/SumI1' : Unused code path elimination
 * Block '<S122>/DProd Out' : Unused code path elimination
 * Block '<S123>/Filter' : Unused code path elimination
 * Block '<S123>/SumD' : Unused code path elimination
 * Block '<S125>/IProd Out' : Unused code path elimination
 * Block '<S128>/Integrator' : Unused code path elimination
 * Block '<S131>/NProd Out' : Unused code path elimination
 * Block '<S133>/PProd Out' : Unused code path elimination
 * Block '<S137>/Sum' : Unused code path elimination
 * Block '<S139>/Kt' : Unused code path elimination
 * Block '<S139>/SumI3' : Unused code path elimination
 * Block '<S140>/SumI1' : Unused code path elimination
 * Block '<S173>/IProd Out' : Unused code path elimination
 * Block '<S176>/Integrator' : Unused code path elimination
 * Block '<S181>/PProd Out' : Unused code path elimination
 * Block '<S185>/Sum' : Unused code path elimination
 * Block '<S187>/Kt' : Unused code path elimination
 * Block '<S187>/SumI3' : Unused code path elimination
 * Block '<S188>/SumI1' : Unused code path elimination
 * Block '<S43>/Saturation' : Unused code path elimination
 * Block '<S43>/Sum1' : Unused code path elimination
 * Block '<S43>/Sum2' : Unused code path elimination
 * Block '<S43>/Sum4' : Unused code path elimination
 * Block '<S43>/Switch auto-manual' : Unused code path elimination
 * Block '<S43>/Switch maneuver' : Unused code path elimination
 * Block '<S43>/Switch rc saturata' : Unused code path elimination
 * Block '<S43>/n-D Lookup Table' : Unused code path elimination
 * Block '<S40>/Kp' : Unused code path elimination
 * Block '<S45>/Constant' : Unused code path elimination
 * Block '<S45>/Lookup Table2' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Propagation' : Unused code path elimination
 * Block '<S193>/LowerRelop1' : Unused code path elimination
 * Block '<S193>/Switch' : Unused code path elimination
 * Block '<S193>/Switch2' : Unused code path elimination
 * Block '<S193>/UpperRelop' : Unused code path elimination
 * Block '<S40>/Switch HOLD//SELECT' : Unused code path elimination
 * Block '<S194>/Constant3' : Unused code path elimination
 * Block '<S194>/Constant4' : Unused code path elimination
 * Block '<S194>/Multiport Switch2' : Unused code path elimination
 * Block '<S194>/Multiport Switch3' : Unused code path elimination
 * Block '<S194>/Switch3' : Unused code path elimination
 * Block '<S194>/Switch4' : Unused code path elimination
 * Block '<S41>/Constant' : Unused code path elimination
 * Block '<S41>/Constant2' : Unused code path elimination
 * Block '<S221>/AND3' : Unused code path elimination
 * Block '<S221>/Constant1' : Unused code path elimination
 * Block '<S221>/DataTypeConv1' : Unused code path elimination
 * Block '<S221>/DataTypeConv2' : Unused code path elimination
 * Block '<S223>/DeadZone' : Unused code path elimination
 * Block '<S221>/Equal1' : Unused code path elimination
 * Block '<S221>/NotEqual' : Unused code path elimination
 * Block '<S221>/SignPreIntegrator' : Unused code path elimination
 * Block '<S221>/SignPreSat' : Unused code path elimination
 * Block '<S221>/Switch' : Unused code path elimination
 * Block '<S221>/ZeroGain' : Unused code path elimination
 * Block '<S224>/DProd Out' : Unused code path elimination
 * Block '<S225>/Filter' : Unused code path elimination
 * Block '<S225>/SumD' : Unused code path elimination
 * Block '<S227>/IProd Out' : Unused code path elimination
 * Block '<S230>/Integrator' : Unused code path elimination
 * Block '<S233>/NProd Out' : Unused code path elimination
 * Block '<S235>/PProd Out' : Unused code path elimination
 * Block '<S237>/Saturation' : Unused code path elimination
 * Block '<S239>/Sum' : Unused code path elimination
 * Block '<S241>/Kt' : Unused code path elimination
 * Block '<S241>/SumI3' : Unused code path elimination
 * Block '<S242>/SumI1' : Unused code path elimination
 * Block '<S41>/Switch' : Unused code path elimination
 * Block '<S41>/Switch auto-manual' : Unused code path elimination
 * Block '<S196>/Constant' : Unused code path elimination
 * Block '<S196>/Constant1' : Unused code path elimination
 * Block '<S196>/Constant2' : Unused code path elimination
 * Block '<S247>/Gain1' : Unused code path elimination
 * Block '<S196>/Math Function' : Unused code path elimination
 * Block '<S248>/Gain' : Unused code path elimination
 * Block '<S196>/Sum' : Unused code path elimination
 * Block '<S196>/Sum1' : Unused code path elimination
 * Block '<S196>/Sum2' : Unused code path elimination
 * Block '<S196>/Switch' : Unused code path elimination
 * Block '<S196>/Switch1' : Unused code path elimination
 * Block '<S275>/AND3' : Unused code path elimination
 * Block '<S275>/Constant1' : Unused code path elimination
 * Block '<S275>/DataTypeConv1' : Unused code path elimination
 * Block '<S275>/DataTypeConv2' : Unused code path elimination
 * Block '<S277>/DeadZone' : Unused code path elimination
 * Block '<S275>/Equal1' : Unused code path elimination
 * Block '<S275>/NotEqual' : Unused code path elimination
 * Block '<S275>/SignPreIntegrator' : Unused code path elimination
 * Block '<S275>/SignPreSat' : Unused code path elimination
 * Block '<S275>/Switch' : Unused code path elimination
 * Block '<S275>/ZeroGain' : Unused code path elimination
 * Block '<S281>/IProd Out' : Unused code path elimination
 * Block '<S284>/Integrator' : Unused code path elimination
 * Block '<S289>/PProd Out' : Unused code path elimination
 * Block '<S291>/Saturation' : Unused code path elimination
 * Block '<S293>/Sum' : Unused code path elimination
 * Block '<S295>/Kt' : Unused code path elimination
 * Block '<S295>/SumI3' : Unused code path elimination
 * Block '<S296>/SumI1' : Unused code path elimination
 * Block '<S42>/Sum3' : Unused code path elimination
 * Block '<S42>/Switch Bumpless 1' : Unused code path elimination
 * Block '<S250>/Constant3' : Unused code path elimination
 * Block '<S301>/Constant' : Unused code path elimination
 * Block '<S250>/Switch' : Unused code path elimination
 * Block '<S250>/throttle - landing' : Unused code path elimination
 * Block '<S36>/Switch di selezione riferimeti  per i loop interni 1' : Unused code path elimination
 * Block '<S36>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
 * Block '<S36>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
 * Block '<S37>/Gain3' : Unused code path elimination
 * Block '<S37>/Switch Bumpless 7' : Unused code path elimination
 * Block '<S305>/Constant4' : Unused code path elimination
 * Block '<S305>/Constant7' : Unused code path elimination
 * Block '<S305>/Constant8' : Unused code path elimination
 * Block '<S305>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S305>/Multiport Switch1' : Unused code path elimination
 * Block '<S305>/Sum' : Unused code path elimination
 * Block '<S305>/Switch Bumpless 1' : Unused code path elimination
 * Block '<S408>/Display' : Unused code path elimination
 * Block '<S408>/Display1' : Unused code path elimination
 * Block '<S426>/Constant' : Unused code path elimination
 * Block '<S426>/Constant1' : Unused code path elimination
 * Block '<S426>/Switch' : Unused code path elimination
 * Block '<S428>/Constant4' : Unused code path elimination
 * Block '<S428>/Memory' : Unused code path elimination
 * Block '<S428>/Sum' : Unused code path elimination
 * Block '<S429>/Constant' : Unused code path elimination
 * Block '<S429>/Constant1' : Unused code path elimination
 * Block '<S429>/Switch' : Unused code path elimination
 * Block '<S431>/Constant4' : Unused code path elimination
 * Block '<S431>/Memory' : Unused code path elimination
 * Block '<S431>/Sum' : Unused code path elimination
 * Block '<S410>/Switch' : Unused code path elimination
 * Block '<S38>/Scope1' : Unused code path elimination
 * Block '<S416>/Abs2' : Unused code path elimination
 * Block '<S451>/Constant1' : Unused code path elimination
 * Block '<S451>/Multiply1' : Unused code path elimination
 * Block '<S440>/Constant1' : Unused code path elimination
 * Block '<S440>/Constant6' : Unused code path elimination
 * Block '<S440>/Constant7' : Unused code path elimination
 * Block '<S455>/Constant1' : Unused code path elimination
 * Block '<S455>/Exp1' : Unused code path elimination
 * Block '<S455>/Gain1' : Unused code path elimination
 * Block '<S455>/Gain2' : Unused code path elimination
 * Block '<S455>/Multiply2' : Unused code path elimination
 * Block '<S455>/Multiply3' : Unused code path elimination
 * Block '<S455>/Multiply4' : Unused code path elimination
 * Block '<S455>/Sum3' : Unused code path elimination
 * Block '<S455>/Sum4' : Unused code path elimination
 * Block '<S456>/Gain1' : Unused code path elimination
 * Block '<S501>/IProd Out' : Unused code path elimination
 * Block '<S504>/Integrator' : Unused code path elimination
 * Block '<S509>/PProd Out' : Unused code path elimination
 * Block '<S513>/Sum' : Unused code path elimination
 * Block '<S472>/Gain' : Unused code path elimination
 * Block '<S456>/Sum3' : Unused code path elimination
 * Block '<S456>/psi ref gain' : Unused code path elimination
 * Block '<S456>/psi ref gain1' : Unused code path elimination
 * Block '<S524>/Sum3' : Unused code path elimination
 * Block '<S524>/x*sin' : Unused code path elimination
 * Block '<S524>/y*cos' : Unused code path elimination
 * Block '<S440>/Relational Operator' : Unused code path elimination
 * Block '<S440>/Switch' : Unused code path elimination
 * Block '<S440>/Switch di selezione  Task - Waypoint navigation5' : Unused code path elimination
 * Block '<S440>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
 * Block '<S440>/Switch1' : Unused code path elimination
 * Block '<S441>/saturatore V' : Unused code path elimination
 * Block '<S441>/saturatore V1' : Unused code path elimination
 * Block '<S39>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
 * Block '<S39>/Switch di selezione  Task - Waypoint navigation1' : Unused code path elimination
 * Block '<S39>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
 * Block '<S570>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S576>/Data Type Duplicate' : Unused code path elimination
 * Block '<S576>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S554>/Data Type Conversion7' : Eliminate redundant data type conversion
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
 * '<Root>' : 'modello_completo'
 * '<S1>'   : 'modello_completo/AIR RX'
 * '<S2>'   : 'modello_completo/AIR TX'
 * '<S3>'   : 'modello_completo/AUTOPILOTA'
 * '<S4>'   : 'modello_completo/Inizializzazioni'
 * '<S5>'   : 'modello_completo/LED 13-44'
 * '<S6>'   : 'modello_completo/MISURE DA SENSORI  FILTRATE'
 * '<S7>'   : 'modello_completo/Misure Sensori'
 * '<S8>'   : 'modello_completo/PARAMETRI SISTEMA DI CONTROLLO'
 * '<S9>'   : 'modello_completo/RADIOCOMANDO'
 * '<S10>'  : 'modello_completo/Servi'
 * '<S11>'  : 'modello_completo/AIR RX/MATLAB Function1'
 * '<S12>'  : 'modello_completo/AIR RX/MATLAB Function2'
 * '<S13>'  : 'modello_completo/AIR RX/MATLAB Function3'
 * '<S14>'  : 'modello_completo/AIR RX/MATLAB Function4'
 * '<S15>'  : 'modello_completo/AIR TX/Enable '
 * '<S16>'  : 'modello_completo/AIR TX/GPS'
 * '<S17>'  : 'modello_completo/AIR TX/Heartbeat'
 * '<S18>'  : 'modello_completo/AIR TX/IMU & Attidude'
 * '<S19>'  : 'modello_completo/AIR TX/If_subsystem'
 * '<S20>'  : 'modello_completo/AIR TX/Servo'
 * '<S21>'  : 'modello_completo/AIR TX/SystemStatus'
 * '<S22>'  : 'modello_completo/AIR TX/VFR'
 * '<S23>'  : 'modello_completo/AIR TX/Waypoints'
 * '<S24>'  : 'modello_completo/AIR TX/Enable /Chart'
 * '<S25>'  : 'modello_completo/AIR TX/Enable /Chart/sendbyte'
 * '<S26>'  : 'modello_completo/AIR TX/Heartbeat/Alarm set'
 * '<S27>'  : 'modello_completo/AIR TX/If_subsystem/Subsystem'
 * '<S28>'  : 'modello_completo/AIR TX/If_subsystem/iflogic_function'
 * '<S29>'  : 'modello_completo/AIR TX/Servo/Conversione'
 * '<S30>'  : 'modello_completo/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S31>'  : 'modello_completo/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S32>'  : 'modello_completo/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S33>'  : 'modello_completo/AIR TX/VFR/Radians to Degrees'
 * '<S34>'  : 'modello_completo/AIR TX/VFR/wrapTo360'
 * '<S35>'  : 'modello_completo/AIR TX/Waypoints/MATLAB Function'
 * '<S36>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1'
 * '<S37>'  : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
 * '<S38>'  : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1'
 * '<S39>'  : 'modello_completo/AUTOPILOTA/Subsystem1'
 * '<S40>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
 * '<S41>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
 * '<S42>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
 * '<S43>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
 * '<S44>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
 * '<S45>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
 * '<S46>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
 * '<S47>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
 * '<S48>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
 * '<S49>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
 * '<S50>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
 * '<S51>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
 * '<S52>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
 * '<S53>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
 * '<S54>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
 * '<S55>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
 * '<S56>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
 * '<S57>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
 * '<S58>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
 * '<S59>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
 * '<S60>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
 * '<S61>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
 * '<S62>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
 * '<S63>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
 * '<S64>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
 * '<S65>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
 * '<S66>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
 * '<S67>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
 * '<S68>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
 * '<S69>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
 * '<S70>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
 * '<S71>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
 * '<S72>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
 * '<S73>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
 * '<S74>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
 * '<S75>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
 * '<S76>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
 * '<S77>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
 * '<S78>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
 * '<S79>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
 * '<S80>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
 * '<S81>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
 * '<S82>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
 * '<S83>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
 * '<S84>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
 * '<S85>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
 * '<S86>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
 * '<S87>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
 * '<S88>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
 * '<S89>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
 * '<S90>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
 * '<S91>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
 * '<S92>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
 * '<S93>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
 * '<S94>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
 * '<S95>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
 * '<S96>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
 * '<S97>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
 * '<S98>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
 * '<S99>'  : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
 * '<S100>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
 * '<S101>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
 * '<S102>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
 * '<S103>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
 * '<S104>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
 * '<S105>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
 * '<S106>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
 * '<S107>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
 * '<S108>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
 * '<S109>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
 * '<S110>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
 * '<S111>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
 * '<S112>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
 * '<S113>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
 * '<S114>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
 * '<S115>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
 * '<S116>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
 * '<S117>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
 * '<S118>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
 * '<S119>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
 * '<S120>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
 * '<S121>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
 * '<S122>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
 * '<S123>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
 * '<S124>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
 * '<S125>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
 * '<S126>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
 * '<S127>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
 * '<S128>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
 * '<S129>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
 * '<S130>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
 * '<S131>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
 * '<S132>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
 * '<S133>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
 * '<S134>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
 * '<S135>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
 * '<S136>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
 * '<S137>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
 * '<S138>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
 * '<S139>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
 * '<S140>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
 * '<S141>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
 * '<S142>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
 * '<S143>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
 * '<S144>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
 * '<S145>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
 * '<S146>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
 * '<S147>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
 * '<S148>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
 * '<S149>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
 * '<S150>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
 * '<S151>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
 * '<S152>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
 * '<S153>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
 * '<S154>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
 * '<S155>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
 * '<S156>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
 * '<S157>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
 * '<S158>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
 * '<S159>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
 * '<S160>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
 * '<S161>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
 * '<S162>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
 * '<S163>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
 * '<S164>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
 * '<S165>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
 * '<S166>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
 * '<S167>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
 * '<S168>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
 * '<S169>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
 * '<S170>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
 * '<S171>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
 * '<S172>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
 * '<S173>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
 * '<S174>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
 * '<S175>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
 * '<S176>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
 * '<S177>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
 * '<S178>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
 * '<S179>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
 * '<S180>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
 * '<S181>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
 * '<S182>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
 * '<S183>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
 * '<S184>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
 * '<S185>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
 * '<S186>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
 * '<S187>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
 * '<S188>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
 * '<S189>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
 * '<S190>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
 * '<S191>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
 * '<S192>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
 * '<S193>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
 * '<S194>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
 * '<S195>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
 * '<S196>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
 * '<S197>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
 * '<S198>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
 * '<S199>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
 * '<S200>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
 * '<S201>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
 * '<S202>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
 * '<S203>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
 * '<S204>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
 * '<S205>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
 * '<S206>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
 * '<S207>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
 * '<S208>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
 * '<S209>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
 * '<S210>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
 * '<S211>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
 * '<S212>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
 * '<S213>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
 * '<S214>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
 * '<S215>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
 * '<S216>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
 * '<S217>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
 * '<S218>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
 * '<S219>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
 * '<S220>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
 * '<S221>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S222>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S223>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S224>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
 * '<S225>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S226>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S227>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
 * '<S228>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
 * '<S229>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S230>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
 * '<S231>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
 * '<S232>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
 * '<S233>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
 * '<S234>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
 * '<S235>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
 * '<S236>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
 * '<S237>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
 * '<S238>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
 * '<S239>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
 * '<S240>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
 * '<S241>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
 * '<S242>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S243>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S244>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S245>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
 * '<S246>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
 * '<S247>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
 * '<S248>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
 * '<S249>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
 * '<S250>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
 * '<S251>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
 * '<S252>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
 * '<S253>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
 * '<S254>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
 * '<S255>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
 * '<S256>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
 * '<S257>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
 * '<S258>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
 * '<S259>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
 * '<S260>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
 * '<S261>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
 * '<S262>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
 * '<S263>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
 * '<S264>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
 * '<S265>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
 * '<S266>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
 * '<S267>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
 * '<S268>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
 * '<S269>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
 * '<S270>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
 * '<S271>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
 * '<S272>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
 * '<S273>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
 * '<S274>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
 * '<S275>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S276>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S277>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S278>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
 * '<S279>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
 * '<S280>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
 * '<S281>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
 * '<S282>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
 * '<S283>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S284>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
 * '<S285>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
 * '<S286>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S287>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
 * '<S288>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
 * '<S289>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
 * '<S290>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
 * '<S291>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
 * '<S292>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
 * '<S293>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
 * '<S294>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
 * '<S295>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
 * '<S296>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S297>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
 * '<S298>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S299>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
 * '<S300>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
 * '<S301>' : 'modello_completo/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
 * '<S302>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
 * '<S303>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
 * '<S304>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
 * '<S305>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
 * '<S306>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
 * '<S307>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
 * '<S308>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
 * '<S309>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
 * '<S310>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
 * '<S311>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
 * '<S312>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
 * '<S313>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
 * '<S314>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
 * '<S315>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
 * '<S316>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
 * '<S317>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
 * '<S318>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
 * '<S319>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
 * '<S320>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
 * '<S321>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
 * '<S322>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
 * '<S323>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
 * '<S324>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
 * '<S325>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
 * '<S326>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
 * '<S327>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
 * '<S328>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
 * '<S329>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
 * '<S330>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
 * '<S331>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
 * '<S332>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
 * '<S333>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
 * '<S334>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
 * '<S335>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
 * '<S336>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
 * '<S337>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
 * '<S338>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S339>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S340>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
 * '<S341>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
 * '<S342>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S343>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
 * '<S344>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
 * '<S345>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
 * '<S346>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
 * '<S347>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
 * '<S348>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S349>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
 * '<S350>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
 * '<S351>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
 * '<S352>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S353>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S354>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S355>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
 * '<S356>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
 * '<S357>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
 * '<S358>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
 * '<S359>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
 * '<S360>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
 * '<S361>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
 * '<S362>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
 * '<S363>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
 * '<S364>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
 * '<S365>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
 * '<S366>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
 * '<S367>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
 * '<S368>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
 * '<S369>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
 * '<S370>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
 * '<S371>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
 * '<S372>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
 * '<S373>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
 * '<S374>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
 * '<S375>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
 * '<S376>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
 * '<S377>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
 * '<S378>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
 * '<S379>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
 * '<S380>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
 * '<S381>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
 * '<S382>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
 * '<S383>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
 * '<S384>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
 * '<S385>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
 * '<S386>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
 * '<S387>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
 * '<S388>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
 * '<S389>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S390>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
 * '<S391>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
 * '<S392>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S393>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
 * '<S394>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
 * '<S395>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
 * '<S396>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
 * '<S397>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
 * '<S398>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
 * '<S399>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
 * '<S400>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
 * '<S401>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
 * '<S402>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S403>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
 * '<S404>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S405>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
 * '<S406>' : 'modello_completo/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
 * '<S407>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
 * '<S408>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
 * '<S409>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
 * '<S410>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
 * '<S411>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
 * '<S412>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
 * '<S413>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
 * '<S414>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
 * '<S415>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
 * '<S416>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
 * '<S417>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
 * '<S418>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
 * '<S419>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
 * '<S420>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
 * '<S421>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
 * '<S422>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
 * '<S423>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
 * '<S424>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
 * '<S425>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
 * '<S426>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
 * '<S427>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
 * '<S428>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
 * '<S429>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
 * '<S430>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
 * '<S431>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
 * '<S432>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
 * '<S433>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
 * '<S434>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
 * '<S435>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
 * '<S436>' : 'modello_completo/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
 * '<S437>' : 'modello_completo/AUTOPILOTA/Subsystem1/Chart'
 * '<S438>' : 'modello_completo/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
 * '<S439>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem'
 * '<S440>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1'
 * '<S441>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem2'
 * '<S442>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem3'
 * '<S443>' : 'modello_completo/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
 * '<S444>' : 'modello_completo/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
 * '<S445>' : 'modello_completo/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
 * '<S446>' : 'modello_completo/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
 * '<S447>' : 'modello_completo/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
 * '<S448>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
 * '<S449>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
 * '<S450>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
 * '<S451>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
 * '<S452>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
 * '<S453>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
 * '<S454>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
 * '<S455>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
 * '<S456>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
 * '<S457>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
 * '<S458>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
 * '<S459>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
 * '<S460>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
 * '<S461>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
 * '<S462>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
 * '<S463>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
 * '<S464>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
 * '<S465>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
 * '<S466>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
 * '<S467>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
 * '<S468>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
 * '<S469>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
 * '<S470>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
 * '<S471>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
 * '<S472>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
 * '<S473>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
 * '<S474>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
 * '<S475>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
 * '<S476>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
 * '<S477>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
 * '<S478>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
 * '<S479>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
 * '<S480>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
 * '<S481>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
 * '<S482>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
 * '<S483>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
 * '<S484>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
 * '<S485>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
 * '<S486>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
 * '<S487>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
 * '<S488>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
 * '<S489>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
 * '<S490>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
 * '<S491>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
 * '<S492>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
 * '<S493>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
 * '<S494>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
 * '<S495>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
 * '<S496>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
 * '<S497>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
 * '<S498>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
 * '<S499>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
 * '<S500>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
 * '<S501>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
 * '<S502>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
 * '<S503>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S504>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
 * '<S505>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
 * '<S506>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S507>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
 * '<S508>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
 * '<S509>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
 * '<S510>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
 * '<S511>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
 * '<S512>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
 * '<S513>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
 * '<S514>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
 * '<S515>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
 * '<S516>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S517>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
 * '<S518>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S519>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
 * '<S520>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
 * '<S521>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
 * '<S522>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
 * '<S523>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
 * '<S524>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
 * '<S525>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
 * '<S526>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
 * '<S527>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S528>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S529>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S530>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S531>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
 * '<S532>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
 * '<S533>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
 * '<S534>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
 * '<S535>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S536>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
 * '<S537>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
 * '<S538>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
 * '<S539>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
 * '<S540>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
 * '<S541>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
 * '<S542>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
 * '<S543>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
 * '<S544>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
 * '<S545>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
 * '<S546>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
 * '<S547>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
 * '<S548>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
 * '<S549>' : 'modello_completo/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
 * '<S550>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
 * '<S551>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
 * '<S552>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
 * '<S553>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S554>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry'
 * '<S555>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians'
 * '<S556>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians1'
 * '<S557>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians2'
 * '<S558>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass'
 * '<S559>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees'
 * '<S560>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees1'
 * '<S561>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees2'
 * '<S562>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1'
 * '<S563>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS'
 * '<S564>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS/MATLAB Function'
 * '<S565>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function'
 * '<S566>' : 'modello_completo/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem2'
 * '<S567>' : 'modello_completo/Misure Sensori/BMP_280'
 * '<S568>' : 'modello_completo/Misure Sensori/GPS_Venus'
 * '<S569>' : 'modello_completo/Misure Sensori/MTi'
 * '<S570>' : 'modello_completo/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S571>' : 'modello_completo/Misure Sensori/BMP_280/Execution_loop'
 * '<S572>' : 'modello_completo/Misure Sensori/BMP_280/MATLAB Function'
 * '<S573>' : 'modello_completo/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S574>' : 'modello_completo/Misure Sensori/BMP_280/One_time_initialization'
 * '<S575>' : 'modello_completo/Misure Sensori/BMP_280/Subsystem'
 * '<S576>' : 'modello_completo/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S577>' : 'modello_completo/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S578>' : 'modello_completo/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S579>' : 'modello_completo/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S580>' : 'modello_completo/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S581>' : 'modello_completo/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S582>' : 'modello_completo/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S583>' : 'modello_completo/RADIOCOMANDO/AILERON'
 * '<S584>' : 'modello_completo/RADIOCOMANDO/AILERON1'
 * '<S585>' : 'modello_completo/RADIOCOMANDO/ELEVATOR'
 * '<S586>' : 'modello_completo/RADIOCOMANDO/ELEVATOR1'
 * '<S587>' : 'modello_completo/RADIOCOMANDO/RUDDER'
 * '<S588>' : 'modello_completo/RADIOCOMANDO/THROTTLE'
 * '<S589>' : 'modello_completo/Servi/AILERON1'
 * '<S590>' : 'modello_completo/Servi/RUDDER6'
 * '<S591>' : 'modello_completo/Servi/THROTTLE1'
 * '<S592>' : 'modello_completo/Servi/elevator'
 */
#endif                                 /* RTW_HEADER_modello_completo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
