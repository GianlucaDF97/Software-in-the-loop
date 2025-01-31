/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Modello_Arduino_2022.h
 *
 * Code generated for Simulink model 'Modello_Arduino_2022'.
 *
 * Model version                  : 5.39
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 10 14:41:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Modello_Arduino_2022_h_
#define RTW_HEADER_Modello_Arduino_2022_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Modello_Arduino_2022_COMMON_INCLUDES_
#define Modello_Arduino_2022_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#endif                               /* Modello_Arduino_2022_COMMON_INCLUDES_ */

#include "Modello_Arduino_2022_types.h"

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

/* Block states (default storage) for system '<S410>/Resettable Subsystem' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S421>/Memory' */
} DW_ResettableSubsystem_Modell_T;

/* Zero-crossing (trigger) state for system '<S410>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_l;/* '<S410>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_Model_T;

/* Block signals for system '<S569>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S576>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S576>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S576>/I2C Read' */
  int16_T I2CRead9;                    /* '<S576>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S576>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S576>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S576>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S576>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S576>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S576>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S576>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S576>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S576>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S576>/I2C Read12' */
} B_One_time_initialization_Mod_T;

/* Block states (default storage) for system '<S569>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S576>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_i;/* '<S576>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_c;/* '<S576>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_b;/* '<S576>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_k;/* '<S576>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_co;/* '<S576>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_k4;/* '<S576>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_d;/* '<S576>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_ir;/* '<S576>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_l;/* '<S576>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_d0;/* '<S576>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_o;/* '<S576>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_kf;/* '<S576>/I2C Read' */
  codertarget_arduinobase_int_m_T obj_d01;/* '<S576>/I2C Write3' */
  codertarget_arduinobase_int_m_T obj_in;/* '<S576>/I2C Write2' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S576>/I2C Write1' */
} DW_One_time_initialization_Mo_T;

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion4_m[42];    /* '<S442>/Data Type Conversion4' */
  int32_T comma_gga_data[80];
  int32_T star_data[80];
  int32_T fb_data[80];
  int32_T tmp_data[80];
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  real_T WP_param_c[21];               /* '<S455>/AUTOLANDING_WAYPOINTS' */
  real_T a[16];
  real_T A[16];
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio_i[100];            /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  char_T s1_data[81];
  char_T messaggio_k[80];
  uint8_T messaggio_b[80];             /* '<S581>/Create_message' */
  boolean_T messaggio_c[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S583>/Complex to Real-Imag' */
  real_T ManualSwitch1[9];             /* '<S7>/Manual Switch1' */
  real_T ManualSwitch[9];              /* '<S7>/Manual Switch' */
  uint8_T dataIn[63];
  real_T x_new[4];
  uint8_T b_dataOut[32];
  uint8_T b_dataOut_p[31];
  real_T lat_end[3];                   /* '<S455>/MATLAB Function' */
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
  real_T Switch;                       /* '<S580>/Switch' */
  real_T V_goHome;                     /* '<S444>/GO_HOME' */
  real_T h_goHome;                     /* '<S444>/GO_HOME' */
  real_T VELOCITA;                     /* '<S443>/saturatore V' */
  real_T QUOTA;                        /* '<S443>/WAYPOINTS' */
  real_T Gain;                         /* '<S460>/Gain' */
  real_T Gain_h;                       /* '<S461>/Gain' */
  real_T velocita;
                 /* '<S442>/Switch di selezione  Task - Waypoint navigation5' */
  real_T QUOTA_f;/* '<S442>/Switch di selezione  Task - Waypoint navigation4' */
  real_T In[2];                        /* '<S467>/In' */
  real_T Constant1;                    /* '<S457>/Constant1' */
  real_T Sum2;                         /* '<S457>/Sum2' */
  real_T maneuver_selector;            /* '<S442>/Chart1' */
  real_T trig_approach;                /* '<S442>/Chart1' */
  real_T trig_flare;                   /* '<S442>/Chart1' */
  real_T approach_selector;            /* '<S442>/Chart1' */
  real_T h_Home;                     /* '<S442>/CALIBRATING_HOME_COORDINATES' */
  real_T Multiply;                     /* '<S453>/Multiply' */
  real_T Constant1_c;                  /* '<S453>/Constant1' */
  real_T x_f_out;                      /* '<S453>/MATLAB Function' */
  real_T h_f_out;                      /* '<S453>/MATLAB Function' */
  real_T k_x_out;                      /* '<S453>/MATLAB Function' */
  real_T h_c_out;                      /* '<S453>/MATLAB Function' */
  real_T no_solution;                  /* '<S453>/MATLAB Function' */
  real_T V_vett;                       /* '<S441>/VETTORIALE' */
  real_T h_vett;                       /* '<S441>/VETTORIALE' */
  real_T Fase_ATO;                     /* '<S440>/Chart1' */
  real_T manetta_ref;                  /* '<S440>/Chart1' */
  real_T eq_rot;                       /* '<S440>/Chart1' */
  real_T h_ref;                        /* '<S440>/Chart1' */
  real_T Tas_ref;                      /* '<S440>/Chart1' */
  real_T psi_ref_selector;             /* '<S440>/Chart1' */
  real_T theta_ground_selector;        /* '<S440>/Chart1' */
  real_T Switch_j;                     /* '<S436>/Switch' */
  real_T Switch_m;                     /* '<S422>/Switch' */
  real_T switch_manetta;               /* '<S38>/ STATI' */
  real_T switch_equilibratore;         /* '<S38>/ STATI' */
  real_T switch_alettoni;              /* '<S38>/ STATI' */
  real_T switch_timone;                /* '<S38>/ STATI' */
  real_T throttle_safe;                /* '<S38>/ STATI' */
  real_T modo;                         /* '<S38>/ STATI' */
  real_T OutportBufferForOut1;         /* '<S303>/Constant' */
  real_T num_254;
  real_T a_n;
  real_T dist;
  real_T dist_fut;
  real_T Product1;                     /* '<S565>/Product1' */
  real_T Sum_ax;                       /* '<S421>/Sum' */
  real_T Integrator_e;                 /* '<S285>/Integrator' */
  real_T PWM_aileron_p;                /* '<S9>/Data Type Conversion3' */
  real_T SignPreSat;                   /* '<S276>/SignPreSat' */
  real_T Gain1_m;                      /* '<S558>/Gain1' */
  real_T Gain1_nb;                     /* '<S557>/Gain1' */
  real_T Gain1_i;                      /* '<S553>/Gain1' */
  real_T Gain1_l;                      /* '<S552>/Gain1' */
  real_T Sum_ci;                       /* '<S524>/Sum' */
  real_T Sum2_c;                       /* '<S305>/Sum2' */
  real_T Sum_nh;                       /* '<S401>/Sum' */
  real_T Sum3_b;                       /* '<S585>/Sum3' */
  real_T Sum3;                         /* '<S587>/Sum3' */
  real_T Sum5;                         /* '<S590>/Sum5' */
  real_T Switch_i;                     /* '<S536>/Switch' */
  real_T Abs1;                         /* '<S533>/Abs1' */
  real_T deltafalllimit;               /* '<S572>/delta fall limit' */
  real_T Gain_fd;                      /* '<S465>/Gain' */
  real_T Saturation_e;                 /* '<S292>/Saturation' */
  real_T SwitchBumpless2;              /* '<S304>/Switch Bumpless 2' */
  real_T RateTransition;               /* '<S27>/Rate Transition' */
  real_T Gain1_h;                      /* '<S555>/Gain1' */
  real_T Alettoni;                     /* '<S37>/saturatore A' */
  real_T Saturation_a;                 /* '<S399>/Saturation' */
  real_T Go_home_selector;
  real_T Al_selector;
  real_T a_fut_tmp;
  real_T Ato_selector;
  real_T Vec_selector;
  real_T Wp_selector;
  real_T rtb_Gain1_d_idx_0;
  real_T rtb_Gain1_hx_idx_1;
  real_T rtb_Gain1_hx_idx_0;
  real_T b_a_tmp;
  real_T rtb_Sum3_b_tmp;
  real_T a_tmp_tmp;
  real_T psi_ref_tmp;
  real_T scanned1;
  real_T scanned2;
  real_T b_scanned1;
  real_T scanned1_j;
  real_T scanned2_d;
  real_T b_scanned1_g;
  real_T scanned1_l;
  real_T scanned2_dh;
  real_T b_scanned1_d;
  real_T scanned1_lx;
  real_T scanned2_o;
  real_T b_scanned1_b;
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_f[2];
  int32_T messaggio_size_g[2];
  int32_T messaggio_size_g1[2];
  int32_T s1_size[2];
  boolean_T mess_type_n[5];
  char_T mess_type[5];
  char_T s1[5];
  int8_T p[4];
  int8_T ipiv[4];
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion1[6];     /* '<S18>/Data Type Conversion1' */
  real32_T AGAC[4];                    /* '<S22>/Data Type Conversion' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion1_j;      /* '<Root>/Data Type Conversion1' */
  real32_T DataTypeConversion_l;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion4[4];     /* '<S556>/Data Type Conversion4' */
  real32_T T;                          /* '<S579>/T' */
  real32_T SFunctionBuilder_o1;        /* '<S573>/S-Function Builder' */
  real32_T ByteUnpack_o2_h[4];         /* '<S568>/Byte Unpack' */
  real32_T WP_param[7];                /* '<S23>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T Switch1_gg;                 /* '<S577>/Switch1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_a[4];     /* '<S16>/Data Type Conversion' */
  int32_T DataTypeConversion1_i;       /* '<S573>/Data Type  Conversion1' */
  int32_T DataTypeConversion_ay;       /* '<S573>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2_a;       /* '<S573>/S-Function Builder' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  uint16_T DataTypeConversion1_h[10];  /* '<S556>/Data Type Conversion1' */
  int32_T caso;
  int32_T f;
  int32_T ATO;
  int32_T tolleranza_distWP_fut;
  int32_T soglia_dist;
  int32_T eb_data;
  int32_T c;
  int32_T pipk;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
  int32_T i;
  int32_T k;
  int32_T idx;
  int32_T ntoread;
  int32_T k_l;
  int32_T idx_h;
  int32_T ntoread_b;
  int32_T b_k;
  int32_T kexp;
  int32_T k_d;
  int32_T idx_e;
  int32_T ntoread_bj;
  int32_T e_k;
  int32_T kexp_j;
  int32_T idx_f;
  int32_T ntoread_a;
  int32_T d_k;
  int32_T i_j;
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S19>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S17>/Data Type Conversion' */
  uint32_T DataTypeConversion8;        /* '<S556>/Data Type Conversion8' */
  uint32_T SFunctionBuilder1;          /* '<S573>/S-Function Builder1' */
  real32_T ByteUnpack_o2[9];           /* '<S571>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S571>/Byte Reversal' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T ByteUnpack_o4[2];           /* '<S568>/Byte Unpack' */
  uint16_T WP_info[6];                 /* '<S23>/MATLAB Function' */
  char_T s1_b[4];
  uint8_T output[3];
  uint8_T output_raw[3];
  uint16_T DataTypeConversion2_h;      /* '<S16>/Data Type Conversion2' */
  uint16_T Throttle;                   /* '<S22>/Data Type Conversion2' */
  uint16_T Heading[9];                 /* '<S20>/Data Type Conversion1' */
  uint16_T Memory_a;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
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
  int16_T DataTypeConversion_d[9];     /* '<S556>/Data Type Conversion' */
  int16_T DataTypeConversion_p;        /* '<S10>/Data Type Conversion' */
  int16_T DataTypeConversion1_c;       /* '<S10>/Data Type Conversion1' */
  int16_T DataTypeConversion2_j;       /* '<S10>/Data Type Conversion2' */
  int16_T Sum;                         /* '<S593>/Sum' */
  int16_T ByteUnpack_o3[4];            /* '<S568>/Byte Unpack' */
  uint8_T SFunctionBuilder[41];        /* '<S571>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S571>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1_h[100];  /* '<S1>/S-Function Builder' */
  uint16_T z;
  uint8_T ByteUnpack_o3_b;             /* '<S571>/Byte Unpack' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_k[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_m;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_e[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T TmpSignalConversionAtSFunctio_m[4];/* '<S2>/Heartbeat' */
  uint8_T SFunction_o1_g;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_e[264];         /* '<S2>/S-Function' */
  uint8_T TmpSignalConversionAtBytePackIn[2];
  uint8_T BytePack[63];                /* '<S556>/Byte Pack' */
  uint8_T indice_dimario;              /* '<S583>/MATLAB Function' */
  uint8_T ByteUnpack_o1_c[2];          /* '<S568>/Byte Unpack' */
  uint8_T ByteUnpack_o5;               /* '<S568>/Byte Unpack' */
  uint8_T messaggio[31];               /* '<S564>/MATLAB Function' */
  uint8_T iflogic;                     /* '<S19>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S21>/Data Type Conversion3' */
  boolean_T HitCrossing;               /* '<S251>/Hit  Crossing' */
  B_One_time_initialization_Mod_T One_time_initialization;/* '<S569>/One_time_initialization' */
} B_Modello_Arduino_2022_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_bq_T obj; /* '<S556>/Serial Transmit' */
  codertarget_arduinobase_in_bq_T obj_o;/* '<S25>/Serial Transmit' */
  codertarget_arduinobase_int_b_T obj_e;/* '<S570>/Serial Receive1' */
  codertarget_arduinobase_int_b_T obj_c;/* '<S556>/Serial Receive' */
  codertarget_arduinobase_inter_T obj_f;/* '<S573>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S573>/I2C Read1' */
  codertarget_arduinobase_block_T obj_b;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S5>/Digital Output' */
  real_T SFunctionBuilder_DSTATE;      /* '<S571>/S-Function Builder' */
  real_T SFunctionBuilder_DSTATE_l;    /* '<S1>/S-Function Builder' */
  real_T UnitDelay_DSTATE;             /* '<S565>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S342>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S392>/Integrator' */
  real_T DiscreteWashoutFilter_states; /* '<S306>/Discrete Washout Filter' */
  real_T DelayInput2_DSTATE;           /* '<S572>/Delay Input2' */
  real_T Delay_DSTATE;                 /* '<S250>/Delay' */
  real_T Integrator_DSTATE_e;          /* '<S285>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S307>/Discrete-Time Integrator' */
  real_T SFunctionBuilder10_DSTATE;    /* '<S10>/S-Function Builder10' */
  real_T SFunctionBuilder4_DSTATE;     /* '<S10>/S-Function Builder4' */
  real_T SFunctionBuilder5_DSTATE;     /* '<S10>/S-Function Builder5' */
  real_T SFunctionBuilder9_DSTATE;     /* '<S10>/S-Function Builder9' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S4>/S-Function Builder' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S453>/Discrete-Time Integrator' */
  volatile real_T RateTransition_Buffer0;/* '<S27>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S27>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S27>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S27>/Memory2' */
  real_T Memory_PreviousInput_l[9];    /* '<S583>/Memory' */
  real_T P_ref;                        /* '<S569>/MATLAB Function' */
  real_T rl_up;                        /* '<S569>/MATLAB Function' */
  real_T rl_dw;                        /* '<S569>/MATLAB Function' */
  real_T flag;                         /* '<S444>/GO_HOME' */
  real_T Memory4_PreviousInput;        /* '<S443>/Memory4' */
  real_T flag_j;                       /* '<S443>/WAYPOINTS' */
  real_T lat1;                         /* '<S443>/WAYPOINTS' */
  real_T long1;                        /* '<S443>/WAYPOINTS' */
  real_T Memory7_PreviousInput;        /* '<S442>/Memory7' */
  real_T Memory5_PreviousInput;        /* '<S442>/Memory5' */
  real_T Memory1_PreviousInput_b;      /* '<S442>/Memory1' */
  real_T Memory2_PreviousInput_n;      /* '<S442>/Memory2' */
  real_T x[4];                         /* '<S453>/MATLAB Function' */
  real_T cycle_count;                  /* '<S453>/MATLAB Function' */
  real_T eps[4];                       /* '<S453>/MATLAB Function' */
  real_T flag_d;                       /* '<S442>/ALLINEAMENTO' */
  real_T Memory3_PreviousInput;        /* '<S441>/Memory3' */
  real_T V_ref;                        /* '<S441>/VETTORIALE' */
  real_T ALT_ref;                      /* '<S441>/VETTORIALE' */
  real_T Memory_PreviousInput_c;       /* '<S440>/Memory' */
  real_T Memory1_PreviousInput_i;      /* '<S440>/Memory1' */
  real_T alarm;                        /* '<S417>/MATLAB Function1' */
  real_T Memory_PreviousInput_j;       /* '<S438>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S5>/Pulse Generator1' */
  int_T HitCrossing_MODE;              /* '<S251>/Hit  Crossing' */
  uint16_T Memory_PreviousInput_i[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S569>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S392>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S307>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S453>/Discrete-Time Integrator' */
  uint8_T Memory4_PreviousInput_c[300];/* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput_l[100];/* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_d[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_h[4];   /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput_o;     /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S581>/Create_message' */
  uint8_T counter_k;                   /* '<S581>/Create_message' */
  uint8_T message_e[31];               /* '<S564>/MATLAB Function' */
  uint8_T counter_a;                   /* '<S564>/MATLAB Function' */
  uint8_T is_active_c10_Modello_Arduino_2;/* '<S442>/Chart1' */
  uint8_T is_c10_Modello_Arduino_2022; /* '<S442>/Chart1' */
  uint8_T Memory1_PreviousInput_o;     /* '<S441>/Memory1' */
  uint8_T Memory2_PreviousInput_e;     /* '<S441>/Memory2' */
  uint8_T Memory6_PreviousInput;       /* '<S441>/Memory6' */
  uint8_T is_active_c1_Modello_Arduino_20;/* '<S440>/Chart1' */
  uint8_T is_c1_Modello_Arduino_2022;  /* '<S440>/Chart1' */
  uint8_T temporalCounter_i1;          /* '<S440>/Chart1' */
  uint8_T is_active_c21_Modello_Arduino_2;/* '<S39>/Chart' */
  uint8_T is_c21_Modello_Arduino_2022; /* '<S39>/Chart' */
  uint8_T is_active_c26_Modello_Arduino_2;/* '<S38>/ STATI' */
  uint8_T is_c26_Modello_Arduino_2022; /* '<S38>/ STATI' */
  uint8_T is_AUTOMATICA;               /* '<S38>/ STATI' */
  uint8_T is_active_c23_Modello_Arduino_2;
                                 /* '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_c23_Modello_Arduino_2022;
                                 /* '<S40>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_active_c9_Modello_Arduino_20;/* '<S15>/Chart' */
  uint8_T i;                           /* '<S15>/Chart' */
  uint8_T message_i[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_af;                  /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S581>/Create_message' */
  boolean_T end_found;                 /* '<S581>/Create_message' */
  boolean_T start_found_d;             /* '<S564>/MATLAB Function' */
  boolean_T x_not_empty;               /* '<S453>/MATLAB Function' */
  boolean_T x_new_not_empty;           /* '<S453>/MATLAB Function' */
  boolean_T cycle_count_not_empty;     /* '<S453>/MATLAB Function' */
  boolean_T eps_not_empty;             /* '<S453>/MATLAB Function' */
  boolean_T Tf_not_empty;              /* '<S412>/MATLAB Function1' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T Enabled_MODE;              /* '<S434>/Enabled ' */
  boolean_T Enabled_MODE_k;            /* '<S426>/Enabled ' */
  boolean_T Enabled_MODE_b;            /* '<S425>/Enabled ' */
  DW_One_time_initialization_Mo_T One_time_initialization;/* '<S569>/One_time_initialization' */
  DW_ResettableSubsystem_Modell_T ResettableSubsystem_p;/* '<S411>/Resettable Subsystem' */
  DW_ResettableSubsystem_Modell_T ResettableSubsystem;/* '<S410>/Resettable Subsystem' */
} DW_Modello_Arduino_2022_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S251>/Hit  Crossing' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S442>/Sample and Hold' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S440>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE_k; /* '<S440>/Sample and Hold' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S434>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_m;/* '<S426>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_n;/* '<S425>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_Model_T ResettableSubsystem_p;/* '<S411>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_Model_T ResettableSubsystem;/* '<S410>/Resettable Subsystem' */
  ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S251>/Enabled Subsystem' */
} PrevZCX_Modello_Arduino_2022_T;

/* Parameters for system: '<S410>/Enabled Subsystem' */
struct P_EnabledSubsystem_Modello_Ar_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S419>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S419>/Constant2'
                                        */
  real_T u0_Y0;                        /* Computed Parameter: u0_Y0
                                        * Referenced by: '<S419>/1//0'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S419>/Switch'
                                        */
};

/* Parameters for system: '<S410>/Resettable Subsystem' */
struct P_ResettableSubsystem_Modello_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S421>/Memory'
                                        */
};

/* Parameters for system: '<S569>/One_time_initialization' */
struct P_One_time_initialization_Mod_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S576>/Bitwise Operator1'
                                      */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S576>/I2C Read12'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S576>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S576>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S576>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S576>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S576>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S576>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S576>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S576>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S576>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S576>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S576>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S576>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S576>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S576>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S576>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S576>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_Modello_Arduino_2022_T_ {
  real_T Kp_comp_h;                    /* Variable: Kp_comp_h
                                        * Referenced by: '<S304>/Constant3'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S37>/saturatore A'
                                        *   '<S37>/saturatore A1'
                                        *   '<S585>/Constant8'
                                        *   '<S591>/Constant'
                                        *   '<S399>/Saturation'
                                        */
  real_T attuatore_Amin;               /* Variable: attuatore_Amin
                                        * Referenced by:
                                        *   '<S37>/saturatore A'
                                        *   '<S37>/saturatore A1'
                                        *   '<S585>/Constant9'
                                        *   '<S591>/Constant1'
                                        *   '<S399>/Saturation'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S587>/Constant8'
                                        *   '<S594>/Constant'
                                        *   '<S304>/saturatore E2'
                                        *   '<S349>/Saturation'
                                        */
  real_T attuatore_Emin;               /* Variable: attuatore_Emin
                                        * Referenced by:
                                        *   '<S587>/Constant9'
                                        *   '<S594>/Constant1'
                                        *   '<S304>/saturatore E2'
                                        *   '<S349>/Saturation'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S37>/saturatore R'
                                        *   '<S589>/Constant8'
                                        *   '<S592>/Constant'
                                        */
  real_T attuatore_Rmin;               /* Variable: attuatore_Rmin
                                        * Referenced by:
                                        *   '<S37>/saturatore R'
                                        *   '<S589>/Constant9'
                                        *   '<S592>/Constant1'
                                        */
  real_T attuatore_Tmax;               /* Variable: attuatore_Tmax
                                        * Referenced by:
                                        *   '<S590>/manetta_massima'
                                        *   '<S292>/Saturation'
                                        *   '<S278>/DeadZone'
                                        */
  real_T attuatore_Tmin;               /* Variable: attuatore_Tmin
                                        * Referenced by:
                                        *   '<S590>/manetta_minima'
                                        *   '<S292>/Saturation'
                                        *   '<S278>/DeadZone'
                                        */
  real_T interventoA_05;               /* Variable: interventoA_05
                                        * Referenced by: '<S412>/Constant4'
                                        */
  real_T interventoA_1;                /* Variable: interventoA_1
                                        * Referenced by: '<S412>/Constant3'
                                        */
  real_T interventoE_05;               /* Variable: interventoE_05
                                        * Referenced by: '<S412>/Constant1'
                                        */
  real_T interventoE_1;                /* Variable: interventoE_1
                                        * Referenced by: '<S412>/Constant'
                                        */
  real_T interventoT;                  /* Variable: interventoT
                                        * Referenced by: '<S412>/Constant2'
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
                                        * Referenced by: '<S304>/Gain'
                                        */
  real_T phi_max;                      /* Variable: phi_max
                                        * Referenced by:
                                        *   '<S586>/Constant8'
                                        *   '<S586>/Saturation'
                                        */
  real_T phi_min;                      /* Variable: phi_min
                                        * Referenced by:
                                        *   '<S586>/Constant9'
                                        *   '<S586>/Saturation'
                                        */
  real_T safe_V;                       /* Variable: safe_V
                                        * Referenced by: '<S417>/Constant'
                                        */
  real_T safe_phi;                     /* Variable: safe_phi
                                        * Referenced by: '<S417>/Constant1'
                                        */
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S573>/I2C Read1'
                                        *   '<S573>/I2C Read12'
                                        *   '<S576>/I2C Read'
                                        *   '<S576>/I2C Read1'
                                        *   '<S576>/I2C Read10'
                                        *   '<S576>/I2C Read11'
                                        *   '<S576>/I2C Read2'
                                        *   '<S576>/I2C Read3'
                                        *   '<S576>/I2C Read4'
                                        *   '<S576>/I2C Read5'
                                        *   '<S576>/I2C Read6'
                                        *   '<S576>/I2C Read7'
                                        *   '<S576>/I2C Read8'
                                        *   '<S576>/I2C Read9'
                                        *   '<S421>/Constant4'
                                        *   '<S424>/Constant4'
                                        *   '<S438>/Constant4'
                                        */
  real_T theta_max;                    /* Variable: theta_max
                                        * Referenced by:
                                        *   '<S588>/Constant8'
                                        *   '<S588>/Saturation'
                                        */
  real_T theta_min;                    /* Variable: theta_min
                                        * Referenced by:
                                        *   '<S588>/Constant9'
                                        *   '<S588>/Saturation'
                                        */
  real_T time_alarm_SAFE;              /* Variable: time_alarm_SAFE
                                        * Referenced by: '<S436>/Switch'
                                        */
  real_T vel_wp1_al;                   /* Variable: vel_wp1_al
                                        * Referenced by: '<S455>/Constant'
                                        */
  real_T vel_wp2_al;                   /* Variable: vel_wp2_al
                                        * Referenced by: '<S455>/Constant1'
                                        */
  real32_T Ki_AP_vel;                  /* Variable: Ki_AP_vel
                                        * Referenced by: '<S8>/Ki AP velocit�'
                                        */
  real32_T Ki_becch;                   /* Variable: Ki_becch
                                        * Referenced by: '<S8>/Ki controllore  beccheggio1'
                                        */
  real32_T Ki_roll;                    /* Variable: Ki_roll
                                        * Referenced by: '<S8>/Ki controllore  rollio3'
                                        */
  real32_T Kp_AP_vel;                  /* Variable: Kp_AP_vel
                                        * Referenced by: '<S8>/Kp AP velocit�'
                                        */
  real32_T Kp_becch;                   /* Variable: Kp_becch
                                        * Referenced by: '<S8>/Kp controllore beccheggio1'
                                        */
  real32_T Kp_imb;                     /* Variable: Kp_imb
                                        * Referenced by: '<S8>/Kp controllore imbardata'
                                        */
  real32_T Kp_p;                       /* Variable: Kp_p
                                        * Referenced by: '<S8>/Kp controllore  velocit� rollio3'
                                        */
  real32_T Kp_q;                       /* Variable: Kp_q
                                        * Referenced by: '<S8>/Kp controllore velocit� beccheggio1'
                                        */
  real32_T Kp_roll;                    /* Variable: Kp_roll
                                        * Referenced by: '<S8>/Kp controllore  rollio3'
                                        */
  int8_T K_imb_inv;                    /* Variable: K_imb_inv
                                        * Referenced by: '<S8>/K controllo imbardata inversa'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S342>/Integrator'
                               */
  real_T PIDController_InitialConditio_c;
                              /* Mask Parameter: PIDController_InitialConditio_c
                               * Referenced by: '<S392>/Integrator'
                               */
  real_T PIDController_InitialConditio_k;
                              /* Mask Parameter: PIDController_InitialConditio_k
                               * Referenced by: '<S285>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S385>/Kb'
                                        */
  real_T PIDController_Kb_a;           /* Mask Parameter: PIDController_Kb_a
                                        * Referenced by: '<S335>/Kb'
                                        */
  real_T PIDController_Kt;             /* Mask Parameter: PIDController_Kt
                                        * Referenced by: '<S296>/Kt'
                                        */
  real_T PIDController_Kt_o;           /* Mask Parameter: PIDController_Kt_o
                                        * Referenced by: '<S403>/Kt'
                                        */
  real_T PIDController_Kt_b;           /* Mask Parameter: PIDController_Kt_b
                                        * Referenced by: '<S353>/Kt'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S537>/Constant'
                                       */
  real_T CompareToConstant_const_k; /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S535>/Constant'
                                     */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S538>/Constant'
                                     */
  real_T CompareToConstant_const_ky;
                                   /* Mask Parameter: CompareToConstant_const_ky
                                    * Referenced by: '<S531>/Constant'
                                    */
  real_T CompareToConstant_const_j; /* Mask Parameter: CompareToConstant_const_j
                                     * Referenced by: '<S529>/Constant'
                                     */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S532>/Constant'
                                     */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S25>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S34>/Constant2'
                                        */
  real_T Out1_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S303>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S303>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S251>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S251>/Switch'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S309>/Constant5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 16
                                        * Referenced by: '<S309>/Switch1'
                                        */
  real_T r_rif_Value;                  /* Expression: 0
                                        * Referenced by: '<S37>/r_rif'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S307>/Constant4'
                                        */
  real_T Alarm_Int_Y0;                 /* Expression: 0
                                        * Referenced by: '<S428>/Alarm_Int'
                                        */
  real_T Alarm_Int_Y0_g;               /* Expression: 0
                                        * Referenced by: '<S431>/Alarm_Int'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S436>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S436>/Constant1'
                                        */
  real_T AlarmSafe_Y0;                 /* Expression: 0
                                        * Referenced by: '<S436>/Alarm Safe'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S438>/Memory'
                                        */
  real_T Constant1_Value_n;            /* Expression: 20
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S415>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 50
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S448>/ '
                                        */
  real_T _Y0_j;                        /* Expression: initCond
                                        * Referenced by: '<S449>/ '
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S447>/Gain'
                                        */
  real_T Memory_InitialCondition_n;    /* Expression: 0
                                        * Referenced by: '<S440>/Memory'
                                        */
  real_T Gain_Gain_og;                 /* Expression: 180/pi
                                        * Referenced by: '<S446>/Gain'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S440>/Memory1'
                                        */
  real_T Out1_Y0_e;                    /* Computed Parameter: Out1_Y0_e
                                        * Referenced by: '<S441>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S441>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S441>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S441>/Out4'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S441>/Memory3'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S450>/Gain'
                                        */
  real_T h_ref_Y0;                     /* Computed Parameter: h_ref_Y0
                                        * Referenced by: '<S453>/h_ref'
                                        */
  real_T flare_data_Y0;                /* Computed Parameter: flare_data_Y0
                                        * Referenced by: '<S453>/flare_data'
                                        */
  real_T landing_abort_Y0;             /* Computed Parameter: landing_abort_Y0
                                        * Referenced by: '<S453>/landing_abort'
                                        */
  real_T rc_ref_app_Y0;                /* Computed Parameter: rc_ref_app_Y0
                                        * Referenced by: '<S453>/rc_ref_app'
                                        */
  real_T x_g0_Value;                   /* Expression: -100
                                        * Referenced by: '<S453>/x_g0'
                                        */
  real_T Constant3_Value_d;            /* Expression: 1
                                        * Referenced by: '<S453>/Constant3'
                                        */
  real_T Constant4_Value_o;            /* Expression: 0
                                        * Referenced by: '<S453>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S453>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S453>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S453>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S453>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S453>/Switch'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S453>/Gain'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S453>/Constant2'
                                        */
  real_T Constant1_Value_l;            /* Expression: 20
                                        * Referenced by: '<S453>/Constant1'
                                        */
  real_T h_ref_Y0_h;                   /* Computed Parameter: h_ref_Y0_h
                                        * Referenced by: '<S457>/h_ref'
                                        */
  real_T RC_ref_Y0;                    /* Computed Parameter: RC_ref_Y0
                                        * Referenced by: '<S457>/RC_ref'
                                        */
  real_T Constant1_Value_j;            /* Expression: 18
                                        * Referenced by: '<S457>/Constant1'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S457>/Gain'
                                        */
  real_T psi_ref_landing_Y0;           /* Computed Parameter: psi_ref_landing_Y0
                                        * Referenced by: '<S458>/psi_ref_landing'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S527>/Bias'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S527>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S527>/Bias1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 360
                                        * Referenced by: '<S530>/Constant2'
                                        */
  real_T Bias_Bias_o;                  /* Expression: 180
                                        * Referenced by: '<S530>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S530>/Bias1'
                                        */
  real_T Constant_Value_n;             /* Expression: 180
                                        * Referenced by: '<S524>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S524>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 360
                                        * Referenced by: '<S528>/Constant2'
                                        */
  real_T Bias_Bias_a;                  /* Expression: 180
                                        * Referenced by: '<S528>/Bias'
                                        */
  real_T Bias1_Bias_i;                 /* Expression: -180
                                        * Referenced by: '<S528>/Bias1'
                                        */
  real_T Bias_Bias_p;                  /* Expression: -90
                                        * Referenced by: '<S533>/Bias'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S533>/Gain'
                                        */
  real_T Bias1_Bias_ip;                /* Expression: +90
                                        * Referenced by: '<S533>/Bias1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S536>/Constant2'
                                        */
  real_T Bias_Bias_a3;                 /* Expression: 180
                                        * Referenced by: '<S536>/Bias'
                                        */
  real_T Bias1_Bias_a;                 /* Expression: -180
                                        * Referenced by: '<S536>/Bias1'
                                        */
  real_T Constant_Value_m;             /* Expression: 180
                                        * Referenced by: '<S525>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S525>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S534>/Constant2'
                                        */
  real_T Bias_Bias_g;                  /* Expression: 180
                                        * Referenced by: '<S534>/Bias'
                                        */
  real_T Bias1_Bias_b;                 /* Expression: -180
                                        * Referenced by: '<S534>/Bias1'
                                        */
  real_T _Y0_a[2];                     /* Expression: initCond
                                        * Referenced by: '<S467>/ '
                                        */
  real_T Constant3_Value_g;            /* Expression: 1
                                        * Referenced by: '<S442>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S442>/Constant8'
                                        */
  real_T TAS_AL_Y0;                    /* Computed Parameter: TAS_AL_Y0
                                        * Referenced by: '<S442>/TAS_AL'
                                        */
  real_T QUOTA_AL_Y0;                  /* Computed Parameter: QUOTA_AL_Y0
                                        * Referenced by: '<S442>/QUOTA_AL'
                                        */
  real_T RC_AL_Y0;                     /* Computed Parameter: RC_AL_Y0
                                        * Referenced by: '<S442>/RC_AL'
                                        */
  real_T ROTTA_AL_Y0;                  /* Computed Parameter: ROTTA_AL_Y0
                                        * Referenced by: '<S442>/ROTTA_AL'
                                        */
  real_T H_LAT_Y0;                     /* Computed Parameter: H_LAT_Y0
                                        * Referenced by: '<S442>/H_LAT'
                                        */
  real_T H_LONG_Y0;                    /* Computed Parameter: H_LONG_Y0
                                        * Referenced by: '<S442>/H_LONG'
                                        */
  real_T H_ALT_Y0;                     /* Computed Parameter: H_ALT_Y0
                                        * Referenced by: '<S442>/H_ALT'
                                        */
  real_T distancewaypointsvirtuale_Value[3];/* Expression: [-1000 -800 2000]
                                             * Referenced by: '<S455>/distance waypoints virtuale'
                                             */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S471>/Gain'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S472>/Gain'
                                        */
  real_T altwaypointvirtuale_Value[3]; /* Expression: [45 45 45]
                                        * Referenced by: '<S455>/alt waypoint virtuale'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S463>/Gain'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S462>/Gain'
                                        */
  real_T Gain_Gain_fy;                 /* Expression: 180/pi
                                        * Referenced by: '<S460>/Gain'
                                        */
  real_T Gain_Gain_la;                 /* Expression: 180/pi
                                        * Referenced by: '<S461>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S523>/Gain1'
                                        */
  real_T Constant2_Value_k;            /* Expression: 1
                                        * Referenced by: '<S539>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S543>/Constant'
                                        */
  real_T Constant4_Value_n;            /* Expression: 1
                                        * Referenced by: '<S542>/Constant4'
                                        */
  real_T Constant_Value_f;             /* Expression: 1/298.257223563
                                        * Referenced by: '<S541>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S541>/f'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S540>/Gain1'
                                        */
  real_T Constant1_Value_i;            /* Expression: 6378137
                                        * Referenced by: '<S539>/Constant1'
                                        */
  real_T Constant_Value_kr;            /* Expression: 1
                                        * Referenced by: '<S539>/Constant'
                                        */
  real_T Constant3_Value_h;            /* Expression: 1
                                        * Referenced by: '<S539>/Constant3'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S464>/Gain'
                                        */
  real_T Gain_Gain_fp;                 /* Expression: 180/pi
                                        * Referenced by: '<S465>/Gain'
                                        */
  real_T Gain_Gain_ai;                 /* Expression: 180/pi
                                        * Referenced by: '<S466>/Gain'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S442>/Memory7'
                                        */
  real_T Memory5_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S442>/Memory5'
                                        */
  real_T Memory1_InitialCondition_b;   /* Expression: 0
                                        * Referenced by: '<S442>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S442>/Memory2'
                                        */
  real_T Constant4_Value_d;            /* Expression: 0
                                        * Referenced by: '<S442>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 20
                                        * Referenced by: '<S442>/Constant6'
                                        */
  real_T Constant2_Value_j;            /* Expression: 45
                                        * Referenced by: '<S442>/Constant2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 1
                                        * Referenced by: '<S442>/Switch2'
                                        */
  real_T RC_Y0;                        /* Computed Parameter: RC_Y0
                                        * Referenced by: '<S443>/RC'
                                        */
  real_T VELOCITA_Y0;                  /* Computed Parameter: VELOCITA_Y0
                                        * Referenced by: '<S443>/VELOCITA'
                                        */
  real_T Out3_Y0_d;                    /* Computed Parameter: Out3_Y0_d
                                        * Referenced by: '<S443>/Out3'
                                        */
  real_T Out4_Y0_a;                    /* Computed Parameter: Out4_Y0_a
                                        * Referenced by: '<S443>/Out4'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S443>/Memory4'
                                        */
  real_T Gain_Gain_ky;                 /* Expression: 180/pi
                                        * Referenced by: '<S544>/Gain'
                                        */
  real_T Gain_Gain_dg;                 /* Expression: 180/pi
                                        * Referenced by: '<S545>/Gain'
                                        */
  real_T Gain_Gain_fj;                 /* Expression: 180/pi
                                        * Referenced by: '<S546>/Gain'
                                        */
  real_T saturatoreV_UpperSat;         /* Expression: 40
                                        * Referenced by: '<S443>/saturatore V'
                                        */
  real_T saturatoreV_LowerSat;         /* Expression: 15
                                        * Referenced by: '<S443>/saturatore V'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S444>/Out1'
                                        */
  real_T Out2_Y0_l;                    /* Computed Parameter: Out2_Y0_l
                                        * Referenced by: '<S444>/Out2'
                                        */
  real_T Out3_Y0_b;                    /* Computed Parameter: Out3_Y0_b
                                        * Referenced by: '<S444>/Out3'
                                        */
  real_T Out4_Y0_d;                    /* Computed Parameter: Out4_Y0_d
                                        * Referenced by: '<S444>/Out4'
                                        */
  real_T Gain_Gain_jv;                 /* Expression: 180/pi
                                        * Referenced by: '<S549>/Gain'
                                        */
  real_T Gain_Gain_ii;                 /* Expression: 180/pi
                                        * Referenced by: '<S550>/Gain'
                                        */
  real_T Gain_Gain_c2;                 /* Expression: 180/pi
                                        * Referenced by: '<S551>/Gain'
                                        */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<S556>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol_o;    /* Expression: 0
                                        * Referenced by: '<S556>/Serial Transmit'
                                        */
  real_T Constant1_Value_o;            /* Expression: 16
                                        * Referenced by: '<S573>/Constant1'
                                        */
  real_T Constant5_Value_n;            /* Expression: 8
                                        * Referenced by: '<S573>/Constant5'
                                        */
  real_T Constant6_Value_k;            /* Expression: 4
                                        * Referenced by: '<S573>/Constant6'
                                        */
  real_T Constant4_Value_l;            /* Expression: 4
                                        * Referenced by: '<S573>/Constant4'
                                        */
  real_T Constant2_Value_av;           /* Expression: 16
                                        * Referenced by: '<S573>/Constant2'
                                        */
  real_T Constant3_Value_c;            /* Expression: 8
                                        * Referenced by: '<S573>/Constant3'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S570>/Serial Receive1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S580>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S580>/h_to_subtract'
                                        */
  real_T Constant_Value_lv;            /* Expression: 1
                                        * Referenced by: '<S580>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2
                                        * Referenced by: '<S580>/Constant1'
                                        */
  real_T Constant3_Value_ct;           /* Expression: 3
                                        * Referenced by: '<S580>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S583>/Outport'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S583>/Memory'
                                        */
  real_T Constant8_Value_m[6];         /* Expression: [23,24,25,26,27,28]
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 29
                                        * Referenced by: '<S7>/Constant9'
                                        */
  real_T Constant2_Value_o;            /* Expression: 10
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant3_Value_l;            /* Expression: 11
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant4_Value_j;            /* Expression: 12
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant5_Value_p;            /* Expression: 13
                                        * Referenced by: '<S7>/Constant5'
                                        */
  real_T Constant6_Value_l;            /* Expression: 14
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Constant7_Value[8];           /* Expression: [15,16,17,18,19,20,21,22]
                                        * Referenced by: '<S7>/Constant7'
                                        */
  real_T Constant1_Value_ng[9];        /* Expression: [1,2,3,4,5,6,7,8,9]
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_js;           /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S276>/Constant1'
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
  real_T Constant_Value_ml;            /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant1_Value_n0;           /* Expression: 0.02
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Memory_InitialCondition_au;   /* Expression: -0.02
                                        * Referenced by: '<S27>/Memory'
                                        */
  real_T Gain_Gain_cw;                 /* Expression: 100
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_j[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1000
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Constant_Value_oq;            /* Expression: 62
                                        * Referenced by: '<S556>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: tau
                                        * Referenced by: '<S565>/Constant'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.01
                                        * Referenced by: '<S556>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S565>/Unit Delay'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S552>/Gain1'
                                        */
  real_T Gain_Gain_i2;                 /* Expression: 180/pi
                                        * Referenced by: '<S414>/Gain'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant2_Value_eu;           /* Expression: 0
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Gain_Gain_dn;                 /* Expression: 10^3
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain1_Gain_jd;                /* Expression: pi/180
                                        * Referenced by: '<S553>/Gain1'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S554>/Gain1'
                                        */
  real_T Gain1_Gain_hr;                /* Expression: pi/180
                                        * Referenced by: '<S557>/Gain1'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S558>/Gain1'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S16>/alt_r'
                                        */
  real_T Gain_Gain_bx[4];              /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S556>/Gain4'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S16>/vel y'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: pi/180
                                        * Referenced by: '<S559>/Gain1'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S555>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T airspeedgroundspeedaltclimb1_Va;/* Expression: 0
                                          * Referenced by: '<S22>/airspeed groundspeed alt climb1'
                                          */
  real_T Gain_Gain_lb;                 /* Expression: 180/pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Switch2_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S34>/Switch2'
                                        */
  real_T Constant_Value_fg;            /* Expression: 1
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
  real_T Constant2_Value_ar;           /* Expression: 0
                                        * Referenced by: '<S304>/Constant2'
                                        */
  real_T Constant1_Value_nj;           /* Expression: 0
                                        * Referenced by: '<S304>/Constant1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 1
                                        * Referenced by: '<S588>/Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S342>/Integrator'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S359>/Gain1'
                                        */
  real_T Gain_Gain_od;                 /* Expression: 180/pi
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Constant2_Value_m4;           /* Expression: 90
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant1_Value_ig;           /* Expression: 0
                                        * Referenced by: '<S305>/Constant1'
                                        */
  real_T Gain_Gain_av;                 /* Expression: -1
                                        * Referenced by: '<S586>/Gain'
                                        */
  real_T Constant3_Value_m;            /* Expression: 2
                                        * Referenced by: '<S305>/Constant3'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S392>/Integrator'
                                      */
  real_T Gain_Gain_if;                 /* Expression: 180/pi
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T DiscreteWashoutFilter_NumCoef[2];/* Expression: [ 1 -1]
                                           * Referenced by: '<S306>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_DenCoef[2];/* Expression: [1 -0.995]
                                           * Referenced by: '<S306>/Discrete Washout Filter'
                                           */
  real_T DiscreteWashoutFilter_InitialSt;/* Expression: 0
                                          * Referenced by: '<S306>/Discrete Washout Filter'
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
                                        * Referenced by: '<S572>/Delay Input2'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S572>/sample time'
                                        */
  real_T Constant_Value_hx;            /* Expression: 15
                                        * Referenced by: '<S577>/Constant'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Gain7_Gain;                   /* Expression: 100
                                        * Referenced by: '<S556>/Gain7'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T RC_default_Value;             /* Expression: 2
                                        * Referenced by: '<S39>/RC_default'
                                        */
  real_T Constant_Value_p;             /* Expression: 70
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant1_Value_lp;           /* Expression: 20
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Gain_Gain_py;                 /* Expression: 180/pi
                                        * Referenced by: '<S561>/Gain'
                                        */
  real_T Gain_Gain_kq;                 /* Expression: 180/pi
                                        * Referenced by: '<S562>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S563>/Gain'
                                        */
  real_T Gain_Gain_jx;                 /* Expression: 100
                                        * Referenced by: '<S556>/Gain'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 100
                                        * Referenced by: '<S556>/Gain2'
                                        */
  real_T Constant5_Value_i;            /* Expression: 800
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant2_Value_l;            /* Expression: 2200
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant6_Value_a;            /* Expression: 800
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant4_Value_k;            /* Expression: 2200
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant7_Value_h;            /* Expression: 800
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T Constant3_Value_e;            /* Expression: 2200
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S556>/Gain3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S250>/Delay'
                                        */
  real_T Buffer_ic;                    /* Expression: 0
                                        * Referenced by: '<S250>/Buffer'
                                        */
  real_T Integrator_gainval_c;       /* Computed Parameter: Integrator_gainval_c
                                      * Referenced by: '<S285>/Integrator'
                                      */
  real_T HitCrossing_Offset;           /* Expression: 0.3
                                        * Referenced by: '<S251>/Hit  Crossing'
                                        */
  real_T Constant8_Value_j;            /* Expression: 1
                                        * Referenced by: '<S307>/Constant8'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S307>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S307>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_l;/* Expression: 0.6
                                          * Referenced by: '<S307>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_l;/* Expression: 0
                                          * Referenced by: '<S307>/Discrete-Time Integrator'
                                          */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S276>/ZeroGain'
                                        */
  real_T Constant1_Value_m;            /* Expression: 800
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant_Value_nb;            /* Expression: 2200
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain_i0;                 /* Expression: 180/pi
                                        * Referenced by: '<S416>/Gain'
                                        */
  real_T Constant7_Value_j;            /* Expression: 10
                                        * Referenced by: '<S307>/Constant7'
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
  int32_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Out2_Y0_lm;                 /* Computed Parameter: Out2_Y0_lm
                                        * Referenced by: '<S568>/Out2'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S573>/T'
                                        */
  real32_T T_0_Y0;                     /* Computed Parameter: T_0_Y0
                                        * Referenced by: '<S579>/T_0'
                                        */
  real32_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S577>/Switch'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S573>/p'
                                        */
  uint32_T Constant7_Value_hu;         /* Computed Parameter: Constant7_Value_hu
                                        * Referenced by: '<S573>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S573>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S573>/Constant11'
                                        */
  uint32_T Constant8_Value_e;          /* Computed Parameter: Constant8_Value_e
                                        * Referenced by: '<S573>/Constant8'
                                        */
  uint32_T Constant9_Value_o;          /* Computed Parameter: Constant9_Value_o
                                        * Referenced by: '<S573>/Constant9'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S21>/onboard_control_sensor_present uint32'
                           */
  int16_T Out3_Y0_n;                   /* Computed Parameter: Out3_Y0_n
                                        * Referenced by: '<S568>/Out3'
                                        */
  int16_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S9>/Switch'
                                        */
  int16_T Gain1_Gain_eu;               /* Computed Parameter: Gain1_Gain_eu
                                        * Referenced by: '<S21>/Gain1'
                                        */
  uint16_T Out4_Y0_j;                  /* Computed Parameter: Out4_Y0_j
                                        * Referenced by: '<S568>/Out4'
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
                              * Referenced by: '<S569>/Unit Delay'
                              */
  boolean_T Constant3_Value_ok;        /* Computed Parameter: Constant3_Value_ok
                                        * Referenced by: '<S569>/Constant3'
                                        */
  int8_T Gain3_Gain_o;                 /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S8>/Gain3'
                                        */
  uint8_T Memory_InitialCondition_gs;
                               /* Computed Parameter: Memory_InitialCondition_gs
                                * Referenced by: '<S441>/Memory'
                                */
  uint8_T Memory1_InitialCondition_l;
                               /* Computed Parameter: Memory1_InitialCondition_l
                                * Referenced by: '<S441>/Memory1'
                                */
  uint8_T Memory2_InitialCondition_j;
                               /* Computed Parameter: Memory2_InitialCondition_j
                                * Referenced by: '<S441>/Memory2'
                                */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S441>/Memory6'
                                  */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S583>/mario'
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
  uint8_T Memory1_InitialCondition_bc;
                              /* Computed Parameter: Memory1_InitialCondition_bc
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
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S7>/Manual Switch'
                               */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S17>/Type fixed_wing Autopilot generic'
                           */
  uint8_T ManualSwitch8_CurrentSetting;
                             /* Computed Parameter: ManualSwitch8_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch8'
                              */
  uint8_T ManualSwitch4_CurrentSetting;
                             /* Computed Parameter: ManualSwitch4_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch4'
                              */
  uint8_T ManualSwitch7_CurrentSetting;
                             /* Computed Parameter: ManualSwitch7_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch7'
                              */
  uint8_T ManualSwitch5_CurrentSetting;
                             /* Computed Parameter: ManualSwitch5_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch5'
                              */
  uint8_T ManualSwitch6_CurrentSetting;
                             /* Computed Parameter: ManualSwitch6_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch6'
                              */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<S556>/Inizio MSG'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch1'
                              */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch3'
                              */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<S7>/Manual Switch2'
                              */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S556>/Fine MSG1'
                                        */
  P_One_time_initialization_Mod_T One_time_initialization;/* '<S569>/One_time_initialization' */
  P_ResettableSubsystem_Modello_T ResettableSubsystem_p;/* '<S411>/Resettable Subsystem' */
  P_EnabledSubsystem_Modello_Ar_T EnabledSubsystem_h;/* '<S411>/Enabled Subsystem' */
  P_ResettableSubsystem_Modello_T ResettableSubsystem;/* '<S410>/Resettable Subsystem' */
  P_EnabledSubsystem_Modello_Ar_T EnabledSubsystem_c;/* '<S410>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Modello_Arduino_2022_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Modello_Arduino_2022_T Modello_Arduino_2022_P;

/* Block signals (default storage) */
extern B_Modello_Arduino_2022_T Modello_Arduino_2022_B;

/* Block states (default storage) */
extern DW_Modello_Arduino_2022_T Modello_Arduino_2022_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Modello_Arduino_2022_T Modello_Arduino_2022_PrevZCX;

/* External data declarations for dependent source files */
extern const uint16_T Modello_Arduino_2022_U16GND;/* uint16_T ground */

/* External function called from main */
extern void Modello_Arduino_2022_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Modello_Arduino_2022_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Modello_Arduino_2022_initialize(void);
extern void Modello_Arduino_2022_step0(void);
extern void Modello_Arduino_2022_step1(void);
extern void Modello_Arduino_2022_step2(void);
extern void Modello_Arduino_2022_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Modello_Arduino_2022_T *const Modello_Arduino_2022_M;
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
 * Block '<S36>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
 * Block '<S36>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
 * Block '<S37>/Gain3' : Unused code path elimination
 * Block '<S37>/Switch Bumpless 7' : Unused code path elimination
 * Block '<S410>/Display' : Unused code path elimination
 * Block '<S410>/Display1' : Unused code path elimination
 * Block '<S428>/Constant' : Unused code path elimination
 * Block '<S428>/Constant1' : Unused code path elimination
 * Block '<S428>/Switch' : Unused code path elimination
 * Block '<S430>/Constant4' : Unused code path elimination
 * Block '<S430>/Memory' : Unused code path elimination
 * Block '<S430>/Sum' : Unused code path elimination
 * Block '<S431>/Constant' : Unused code path elimination
 * Block '<S431>/Constant1' : Unused code path elimination
 * Block '<S431>/Switch' : Unused code path elimination
 * Block '<S433>/Constant4' : Unused code path elimination
 * Block '<S433>/Memory' : Unused code path elimination
 * Block '<S433>/Sum' : Unused code path elimination
 * Block '<S412>/Switch' : Unused code path elimination
 * Block '<S38>/Scope1' : Unused code path elimination
 * Block '<S418>/Abs2' : Unused code path elimination
 * Block '<S453>/Multiply1' : Unused code path elimination
 * Block '<S442>/Constant1' : Unused code path elimination
 * Block '<S442>/Constant7' : Unused code path elimination
 * Block '<S457>/Exp1' : Unused code path elimination
 * Block '<S457>/Gain1' : Unused code path elimination
 * Block '<S457>/Gain2' : Unused code path elimination
 * Block '<S457>/Multiply2' : Unused code path elimination
 * Block '<S457>/Multiply3' : Unused code path elimination
 * Block '<S457>/Multiply4' : Unused code path elimination
 * Block '<S457>/Sum3' : Unused code path elimination
 * Block '<S457>/Sum4' : Unused code path elimination
 * Block '<S458>/Gain1' : Unused code path elimination
 * Block '<S503>/IProd Out' : Unused code path elimination
 * Block '<S506>/Integrator' : Unused code path elimination
 * Block '<S511>/PProd Out' : Unused code path elimination
 * Block '<S515>/Sum' : Unused code path elimination
 * Block '<S474>/Gain' : Unused code path elimination
 * Block '<S458>/Sum3' : Unused code path elimination
 * Block '<S458>/psi ref gain' : Unused code path elimination
 * Block '<S458>/psi ref gain1' : Unused code path elimination
 * Block '<S526>/Sum3' : Unused code path elimination
 * Block '<S526>/x*sin' : Unused code path elimination
 * Block '<S526>/y*cos' : Unused code path elimination
 * Block '<S442>/Relational Operator' : Unused code path elimination
 * Block '<S442>/Switch' : Unused code path elimination
 * Block '<S442>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
 * Block '<S442>/Switch1' : Unused code path elimination
 * Block '<S443>/saturatore V1' : Unused code path elimination
 * Block '<S39>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
 * Block '<S39>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
 * Block '<S572>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S578>/Data Type Duplicate' : Unused code path elimination
 * Block '<S578>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless AP quota' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore beccheggio' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore imbardata' : Unused code path elimination
 * Block '<S8>/K AntiWindup-Bumpless controllore rollio' : Unused code path elimination
 * Block '<S8>/Ki AP quota Select' : Unused code path elimination
 * Block '<S8>/Ki AP rotta1' : Unused code path elimination
 * Block '<S8>/Kp AP quota Select' : Unused code path elimination
 * Block '<S8>/Kp AP rotta' : Unused code path elimination
 * Block '<S8>/Saturation' : Unused code path elimination
 * Block '<S8>/n-D Lookup Table' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S556>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion18' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion19' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion21' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion9' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Modello_Arduino_2022'
 * '<S1>'   : 'Modello_Arduino_2022/AIR RX'
 * '<S2>'   : 'Modello_Arduino_2022/AIR TX'
 * '<S3>'   : 'Modello_Arduino_2022/AUTOPILOTA'
 * '<S4>'   : 'Modello_Arduino_2022/Inizializzazioni'
 * '<S5>'   : 'Modello_Arduino_2022/LED 13-44'
 * '<S6>'   : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE'
 * '<S7>'   : 'Modello_Arduino_2022/Misure Sensori'
 * '<S8>'   : 'Modello_Arduino_2022/PARAMETRI SISTEMA DI CONTROLLO'
 * '<S9>'   : 'Modello_Arduino_2022/RADIOCOMANDO'
 * '<S10>'  : 'Modello_Arduino_2022/Servi'
 * '<S11>'  : 'Modello_Arduino_2022/AIR RX/MATLAB Function1'
 * '<S12>'  : 'Modello_Arduino_2022/AIR RX/MATLAB Function2'
 * '<S13>'  : 'Modello_Arduino_2022/AIR RX/MATLAB Function3'
 * '<S14>'  : 'Modello_Arduino_2022/AIR RX/MATLAB Function4'
 * '<S15>'  : 'Modello_Arduino_2022/AIR TX/Enable '
 * '<S16>'  : 'Modello_Arduino_2022/AIR TX/GPS'
 * '<S17>'  : 'Modello_Arduino_2022/AIR TX/Heartbeat'
 * '<S18>'  : 'Modello_Arduino_2022/AIR TX/IMU & Attidude'
 * '<S19>'  : 'Modello_Arduino_2022/AIR TX/If_subsystem'
 * '<S20>'  : 'Modello_Arduino_2022/AIR TX/Servo'
 * '<S21>'  : 'Modello_Arduino_2022/AIR TX/SystemStatus'
 * '<S22>'  : 'Modello_Arduino_2022/AIR TX/VFR'
 * '<S23>'  : 'Modello_Arduino_2022/AIR TX/Waypoints'
 * '<S24>'  : 'Modello_Arduino_2022/AIR TX/Enable /Chart'
 * '<S25>'  : 'Modello_Arduino_2022/AIR TX/Enable /Chart/sendbyte'
 * '<S26>'  : 'Modello_Arduino_2022/AIR TX/Heartbeat/Alarm set'
 * '<S27>'  : 'Modello_Arduino_2022/AIR TX/If_subsystem/Subsystem'
 * '<S28>'  : 'Modello_Arduino_2022/AIR TX/If_subsystem/iflogic_function'
 * '<S29>'  : 'Modello_Arduino_2022/AIR TX/Servo/Conversione'
 * '<S30>'  : 'Modello_Arduino_2022/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S31>'  : 'Modello_Arduino_2022/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S32>'  : 'Modello_Arduino_2022/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S33>'  : 'Modello_Arduino_2022/AIR TX/VFR/Radians to Degrees'
 * '<S34>'  : 'Modello_Arduino_2022/AIR TX/VFR/wrapTo360'
 * '<S35>'  : 'Modello_Arduino_2022/AIR TX/Waypoints/MATLAB Function'
 * '<S36>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1'
 * '<S37>'  : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
 * '<S38>'  : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1'
 * '<S39>'  : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1'
 * '<S40>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
 * '<S41>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
 * '<S42>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
 * '<S43>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
 * '<S44>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
 * '<S45>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
 * '<S46>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
 * '<S47>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
 * '<S48>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
 * '<S49>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
 * '<S50>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
 * '<S51>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
 * '<S52>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
 * '<S53>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
 * '<S54>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
 * '<S55>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
 * '<S56>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
 * '<S57>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
 * '<S58>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
 * '<S59>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
 * '<S60>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
 * '<S61>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
 * '<S62>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
 * '<S63>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
 * '<S64>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
 * '<S65>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
 * '<S66>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
 * '<S67>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
 * '<S68>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
 * '<S69>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
 * '<S70>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
 * '<S71>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
 * '<S72>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
 * '<S73>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
 * '<S74>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
 * '<S75>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
 * '<S76>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
 * '<S77>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
 * '<S78>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
 * '<S79>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
 * '<S80>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
 * '<S81>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
 * '<S82>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
 * '<S83>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
 * '<S84>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
 * '<S85>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
 * '<S86>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
 * '<S87>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
 * '<S88>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
 * '<S89>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
 * '<S90>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
 * '<S91>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
 * '<S92>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
 * '<S93>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
 * '<S94>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
 * '<S95>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
 * '<S96>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
 * '<S97>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
 * '<S98>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
 * '<S99>'  : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
 * '<S100>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
 * '<S101>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
 * '<S102>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
 * '<S103>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
 * '<S104>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
 * '<S105>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
 * '<S106>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
 * '<S107>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
 * '<S108>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
 * '<S109>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
 * '<S110>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
 * '<S111>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
 * '<S112>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
 * '<S113>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
 * '<S114>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
 * '<S115>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
 * '<S116>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
 * '<S117>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
 * '<S118>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
 * '<S119>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
 * '<S120>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
 * '<S121>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
 * '<S122>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
 * '<S123>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
 * '<S124>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
 * '<S125>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
 * '<S126>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
 * '<S127>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
 * '<S128>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
 * '<S129>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
 * '<S130>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
 * '<S131>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
 * '<S132>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
 * '<S133>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
 * '<S134>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
 * '<S135>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
 * '<S136>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
 * '<S137>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
 * '<S138>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
 * '<S139>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
 * '<S140>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
 * '<S141>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
 * '<S142>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
 * '<S143>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
 * '<S144>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
 * '<S145>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
 * '<S146>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
 * '<S147>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
 * '<S148>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
 * '<S149>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
 * '<S150>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
 * '<S151>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
 * '<S152>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
 * '<S153>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
 * '<S154>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
 * '<S155>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
 * '<S156>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
 * '<S157>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
 * '<S158>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
 * '<S159>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
 * '<S160>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
 * '<S161>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
 * '<S162>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
 * '<S163>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
 * '<S164>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
 * '<S165>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
 * '<S166>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
 * '<S167>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
 * '<S168>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
 * '<S169>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
 * '<S170>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
 * '<S171>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
 * '<S172>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
 * '<S173>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
 * '<S174>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
 * '<S175>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
 * '<S176>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
 * '<S177>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
 * '<S178>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
 * '<S179>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
 * '<S180>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
 * '<S181>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
 * '<S182>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
 * '<S183>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
 * '<S184>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
 * '<S185>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
 * '<S186>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
 * '<S187>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
 * '<S188>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
 * '<S189>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
 * '<S190>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
 * '<S191>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
 * '<S192>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
 * '<S193>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
 * '<S194>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
 * '<S195>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
 * '<S196>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
 * '<S197>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
 * '<S198>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
 * '<S199>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
 * '<S200>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
 * '<S201>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
 * '<S202>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
 * '<S203>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
 * '<S204>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
 * '<S205>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
 * '<S206>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
 * '<S207>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
 * '<S208>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
 * '<S209>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
 * '<S210>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
 * '<S211>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
 * '<S212>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
 * '<S213>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
 * '<S214>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
 * '<S215>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
 * '<S216>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
 * '<S217>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
 * '<S218>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
 * '<S219>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
 * '<S220>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
 * '<S221>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S222>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S223>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S224>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
 * '<S225>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S226>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S227>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
 * '<S228>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
 * '<S229>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S230>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
 * '<S231>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
 * '<S232>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
 * '<S233>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
 * '<S234>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
 * '<S235>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
 * '<S236>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
 * '<S237>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
 * '<S238>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
 * '<S239>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
 * '<S240>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
 * '<S241>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
 * '<S242>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S243>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S244>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S245>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
 * '<S246>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
 * '<S247>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
 * '<S248>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
 * '<S249>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
 * '<S250>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch'
 * '<S251>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
 * '<S252>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
 * '<S253>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
 * '<S254>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
 * '<S255>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
 * '<S256>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
 * '<S257>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
 * '<S258>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
 * '<S259>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
 * '<S260>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
 * '<S261>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
 * '<S262>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
 * '<S263>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
 * '<S264>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
 * '<S265>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
 * '<S266>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
 * '<S267>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
 * '<S268>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
 * '<S269>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
 * '<S270>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
 * '<S271>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
 * '<S272>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
 * '<S273>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
 * '<S274>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
 * '<S275>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
 * '<S276>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S277>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S278>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S279>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
 * '<S280>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
 * '<S281>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
 * '<S282>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
 * '<S283>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
 * '<S284>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S285>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
 * '<S286>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
 * '<S287>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S288>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
 * '<S289>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
 * '<S290>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
 * '<S291>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
 * '<S292>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
 * '<S293>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
 * '<S294>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
 * '<S295>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
 * '<S296>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
 * '<S297>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S298>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
 * '<S299>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S300>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
 * '<S301>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
 * '<S302>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch/Smooth Bypass'
 * '<S303>' : 'Modello_Arduino_2022/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
 * '<S304>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
 * '<S305>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
 * '<S306>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
 * '<S307>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
 * '<S308>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
 * '<S309>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
 * '<S310>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
 * '<S311>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
 * '<S312>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
 * '<S313>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
 * '<S314>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
 * '<S315>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
 * '<S316>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
 * '<S317>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
 * '<S318>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
 * '<S319>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
 * '<S320>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
 * '<S321>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
 * '<S322>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
 * '<S323>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
 * '<S324>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
 * '<S325>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
 * '<S326>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
 * '<S327>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
 * '<S328>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
 * '<S329>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
 * '<S330>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
 * '<S331>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
 * '<S332>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
 * '<S333>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
 * '<S334>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
 * '<S335>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
 * '<S336>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
 * '<S337>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
 * '<S338>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
 * '<S339>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
 * '<S340>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S341>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S342>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
 * '<S343>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
 * '<S344>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S345>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
 * '<S346>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
 * '<S347>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
 * '<S348>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
 * '<S349>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
 * '<S350>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S351>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
 * '<S352>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
 * '<S353>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
 * '<S354>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S355>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S356>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S357>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
 * '<S358>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
 * '<S359>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
 * '<S360>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
 * '<S361>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
 * '<S362>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
 * '<S363>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
 * '<S364>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
 * '<S365>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
 * '<S366>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
 * '<S367>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
 * '<S368>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
 * '<S369>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
 * '<S370>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
 * '<S371>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
 * '<S372>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
 * '<S373>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
 * '<S374>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
 * '<S375>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
 * '<S376>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
 * '<S377>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
 * '<S378>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
 * '<S379>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
 * '<S380>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
 * '<S381>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
 * '<S382>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
 * '<S383>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
 * '<S384>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
 * '<S385>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
 * '<S386>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
 * '<S387>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
 * '<S388>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
 * '<S389>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
 * '<S390>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
 * '<S391>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S392>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
 * '<S393>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
 * '<S394>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S395>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
 * '<S396>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
 * '<S397>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
 * '<S398>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
 * '<S399>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
 * '<S400>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
 * '<S401>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
 * '<S402>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
 * '<S403>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
 * '<S404>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S405>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
 * '<S406>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S407>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
 * '<S408>' : 'Modello_Arduino_2022/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
 * '<S409>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
 * '<S410>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
 * '<S411>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
 * '<S412>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
 * '<S413>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
 * '<S414>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
 * '<S415>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
 * '<S416>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
 * '<S417>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
 * '<S418>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
 * '<S419>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
 * '<S420>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
 * '<S421>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
 * '<S422>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
 * '<S423>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
 * '<S424>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
 * '<S425>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
 * '<S426>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
 * '<S427>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
 * '<S428>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
 * '<S429>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
 * '<S430>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
 * '<S431>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
 * '<S432>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
 * '<S433>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
 * '<S434>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
 * '<S435>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
 * '<S436>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
 * '<S437>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
 * '<S438>' : 'Modello_Arduino_2022/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
 * '<S439>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Chart'
 * '<S440>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
 * '<S441>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem'
 * '<S442>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1'
 * '<S443>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem2'
 * '<S444>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem3'
 * '<S445>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
 * '<S446>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
 * '<S447>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
 * '<S448>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
 * '<S449>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
 * '<S450>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
 * '<S451>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
 * '<S452>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
 * '<S453>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
 * '<S454>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
 * '<S455>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
 * '<S456>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
 * '<S457>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
 * '<S458>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
 * '<S459>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
 * '<S460>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
 * '<S461>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
 * '<S462>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
 * '<S463>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
 * '<S464>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
 * '<S465>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
 * '<S466>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
 * '<S467>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
 * '<S468>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
 * '<S469>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
 * '<S470>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
 * '<S471>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
 * '<S472>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
 * '<S473>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
 * '<S474>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
 * '<S475>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
 * '<S476>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
 * '<S477>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
 * '<S478>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
 * '<S479>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
 * '<S480>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
 * '<S481>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
 * '<S482>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
 * '<S483>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
 * '<S484>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
 * '<S485>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
 * '<S486>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
 * '<S487>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
 * '<S488>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
 * '<S489>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
 * '<S490>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
 * '<S491>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
 * '<S492>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
 * '<S493>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
 * '<S494>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
 * '<S495>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
 * '<S496>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
 * '<S497>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
 * '<S498>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
 * '<S499>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
 * '<S500>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
 * '<S501>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
 * '<S502>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
 * '<S503>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
 * '<S504>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
 * '<S505>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S506>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
 * '<S507>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
 * '<S508>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S509>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
 * '<S510>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
 * '<S511>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
 * '<S512>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
 * '<S513>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
 * '<S514>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
 * '<S515>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
 * '<S516>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
 * '<S517>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
 * '<S518>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S519>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
 * '<S520>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S521>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
 * '<S522>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
 * '<S523>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
 * '<S524>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
 * '<S525>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
 * '<S526>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
 * '<S527>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
 * '<S528>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
 * '<S529>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S530>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S531>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S532>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S533>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
 * '<S534>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
 * '<S535>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
 * '<S536>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
 * '<S537>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S538>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
 * '<S539>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
 * '<S540>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
 * '<S541>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
 * '<S542>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
 * '<S543>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
 * '<S544>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
 * '<S545>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
 * '<S546>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
 * '<S547>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
 * '<S548>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
 * '<S549>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
 * '<S550>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
 * '<S551>' : 'Modello_Arduino_2022/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
 * '<S552>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
 * '<S553>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
 * '<S554>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
 * '<S555>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S556>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry'
 * '<S557>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians'
 * '<S558>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians1'
 * '<S559>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians2'
 * '<S560>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass'
 * '<S561>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees'
 * '<S562>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees1'
 * '<S563>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees2'
 * '<S564>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1'
 * '<S565>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS'
 * '<S566>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS/MATLAB Function'
 * '<S567>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function'
 * '<S568>' : 'Modello_Arduino_2022/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem2'
 * '<S569>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280'
 * '<S570>' : 'Modello_Arduino_2022/Misure Sensori/GPS_Venus'
 * '<S571>' : 'Modello_Arduino_2022/Misure Sensori/MTi'
 * '<S572>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/Dynamic rate limiter'
 * '<S573>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/Execution_loop'
 * '<S574>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/MATLAB Function'
 * '<S575>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/MATLAB Function1'
 * '<S576>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/One_time_initialization'
 * '<S577>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/Subsystem'
 * '<S578>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
 * '<S579>' : 'Modello_Arduino_2022/Misure Sensori/BMP_280/Subsystem/Subsystem1'
 * '<S580>' : 'Modello_Arduino_2022/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S581>' : 'Modello_Arduino_2022/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S582>' : 'Modello_Arduino_2022/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S583>' : 'Modello_Arduino_2022/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S584>' : 'Modello_Arduino_2022/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S585>' : 'Modello_Arduino_2022/RADIOCOMANDO/AILERON'
 * '<S586>' : 'Modello_Arduino_2022/RADIOCOMANDO/AILERON1'
 * '<S587>' : 'Modello_Arduino_2022/RADIOCOMANDO/ELEVATOR'
 * '<S588>' : 'Modello_Arduino_2022/RADIOCOMANDO/ELEVATOR1'
 * '<S589>' : 'Modello_Arduino_2022/RADIOCOMANDO/RUDDER'
 * '<S590>' : 'Modello_Arduino_2022/RADIOCOMANDO/THROTTLE'
 * '<S591>' : 'Modello_Arduino_2022/Servi/AILERON1'
 * '<S592>' : 'Modello_Arduino_2022/Servi/RUDDER6'
 * '<S593>' : 'Modello_Arduino_2022/Servi/THROTTLE1'
 * '<S594>' : 'Modello_Arduino_2022/Servi/elevator'
 */
#endif                                 /* RTW_HEADER_Modello_Arduino_2022_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
