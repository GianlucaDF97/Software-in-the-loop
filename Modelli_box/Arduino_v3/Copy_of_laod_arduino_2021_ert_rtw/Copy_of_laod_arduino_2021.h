/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_laod_arduino_2021.h
 *
 * Code generated for Simulink model 'Copy_of_laod_arduino_2021'.
 *
 * Model version                  : 5.11
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 12 13:43:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_of_laod_arduino_2021_h_
#define RTW_HEADER_Copy_of_laod_arduino_2021_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Copy_of_laod_arduino_2021_COMMON_INCLUDES_
#define Copy_of_laod_arduino_2021_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#endif                          /* Copy_of_laod_arduino_2021_COMMON_INCLUDES_ */

#include "Copy_of_laod_arduino_2021_types.h"

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
} DW_ResettableSubsystem_Copy_o_T;

/* Zero-crossing (trigger) state for system '<S410>/Resettable Subsystem' */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_f;/* '<S410>/Resettable Subsystem' */
} ZCE_ResettableSubsystem_Copy__T;

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
  uint8_T messaggio_b[80];             /* '<S571>/Create_message' */
  boolean_T messaggio_c[80];
  uint8_T NMEA_gga_string_data[79];
  char_T messaggio_data[79];
  real_T ComplextoRealImag[9];         /* '<S573>/Complex to Real-Imag' */
  real_T dataIn[6];
  real_T x_new[4];
  uint8_T b_dataOut[32];
  real_T lat_end[3];                   /* '<S455>/MATLAB Function' */
  uint128m_T r;
  creal_T Lat_1;
  creal_T b_x;
  uint96m_T r1;
  uint96m_T r2;
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  uint16_T WP_info_in[6];
  uint64m_T a_g;
  uint64m_T p16;
  uint64m_T sk;
  real_T Switch;                       /* '<S570>/Switch' */
  real_T h_goHome;                     /* '<S444>/GO_HOME' */
  real_T QUOTA;                        /* '<S443>/WAYPOINTS' */
  real_T Gain;                         /* '<S460>/Gain' */
  real_T Gain_g;                       /* '<S461>/Gain' */
  real_T QUOTA_m;/* '<S442>/Switch di selezione  Task - Waypoint navigation4' */
  real_T In[2];                        /* '<S467>/In' */
  real_T Sum2;                         /* '<S457>/Sum2' */
  real_T maneuver_selector;            /* '<S442>/Chart1' */
  real_T trig_approach;                /* '<S442>/Chart1' */
  real_T trig_flare;                   /* '<S442>/Chart1' */
  real_T approach_selector;            /* '<S442>/Chart1' */
  real_T h_Home;                     /* '<S442>/CALIBRATING_HOME_COORDINATES' */
  real_T Multiply;                     /* '<S453>/Multiply' */
  real_T x_f_out;                      /* '<S453>/MATLAB Function' */
  real_T h_f_out;                      /* '<S453>/MATLAB Function' */
  real_T k_x_out;                      /* '<S453>/MATLAB Function' */
  real_T h_c_out;                      /* '<S453>/MATLAB Function' */
  real_T no_solution;                  /* '<S453>/MATLAB Function' */
  real_T h_vett;                       /* '<S441>/VETTORIALE' */
  real_T Fase_ATO;                     /* '<S440>/Chart1' */
  real_T eq_rot;                       /* '<S440>/Chart1' */
  real_T h_ref;                        /* '<S440>/Chart1' */
  real_T psi_ref_selector;             /* '<S440>/Chart1' */
  real_T theta_ground_selector;        /* '<S440>/Chart1' */
  real_T Switch_n;                     /* '<S436>/Switch' */
  real_T Switch_l;                     /* '<S422>/Switch' */
  real_T switch_manetta;               /* '<S40>/ STATI' */
  real_T switch_equilibratore;         /* '<S40>/ STATI' */
  real_T switch_alettoni;              /* '<S40>/ STATI' */
  real_T switch_timone;                /* '<S40>/ STATI' */
  real_T modo;                         /* '<S40>/ STATI' */
  real_T denAccum;
  real_T num_254;
  real_T a_m;
  real_T dist;
  real_T dist_fut;
  real_T Product1;                     /* '<S565>/Product1' */
  real_T IProdOut;                     /* '<S339>/IProd Out' */
  real_T PWM_rudder_n;                 /* '<S9>/Data Type Conversion' */
  real_T PWM_aileron_p;                /* '<S9>/Data Type Conversion3' */
  real_T Gain2_o;                      /* '<S556>/Gain2' */
  real_T Gain2_g;                      /* '<S31>/Gain2' */
  real_T Gain1_c;                      /* '<S553>/Gain1' */
  real_T Gain1_l;                      /* '<S552>/Gain1' */
  real_T Sum2_o;                       /* '<S305>/Sum2' */
  real_T Sum_n3;                       /* '<S401>/Sum' */
  real_T Sum_j;                        /* '<S305>/Sum' */
  real_T Sum_nu;                       /* '<S351>/Sum' */
  real_T Sum3;                         /* '<S577>/Sum3' */
  real_T Switch_bk;                    /* '<S536>/Switch' */
  real_T Gain_n;                       /* '<S465>/Gain' */
  real_T SwitchBumpless2;              /* '<S304>/Switch Bumpless 2' */
  real_T Go_Home;                      /* '<S9>/Switch' */
  real_T RateTransition;               /* '<S29>/Rate Transition' */
  real_T Gain1_p;                      /* '<S558>/Gain1' */
  real_T Gain1_f;                      /* '<S557>/Gain1' */
  real_T Gain1_kx;                     /* '<S555>/Gain1' */
  real_T Alettoni;                     /* '<S39>/saturatore A' */
  real_T Saturation;                   /* '<S349>/Saturation' */
  real_T Saturation_f;                 /* '<S399>/Saturation' */
  real_T Go_home_selector;
  real_T Al_selector;
  real_T a_fut_tmp;
  real_T Ato_selector;
  real_T Vec_selector;
  real_T Wp_selector;
  real_T rtb_Gain1_i_idx_0;
  real_T rtb_Gain1_kw_idx_1;
  real_T rtb_Gain1_kw_idx_0;
  real_T rtb_Sum3_tmp;
  real_T rtb_Sum3_b_tmp;
  real_T rtb_Sum3_b_tmp_tmp;
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
  int32_T star_size[2];
  int32_T eb_size[2];
  int32_T messaggio_size[2];
  int32_T messaggio_size_p[2];
  int32_T messaggio_size_c[2];
  int32_T messaggio_size_f[2];
  int32_T messaggio_size_g[2];
  int32_T s1_size[2];
  boolean_T mess_type_n[5];
  char_T mess_type[5];
  char_T s1[5];
  int8_T p[4];
  int8_T ipiv[4];
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion1[6];     /* '<S18>/Data Type Conversion1' */
  real32_T AGAC[4];                    /* '<S22>/Data Type Conversion' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataTypeConversion1_j;      /* '<Root>/Data Type Conversion1' */
  real32_T DataTypeConversion_l;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_g;      /* '<S2>/Data Type Conversion1' */
  real32_T DataTypeConversion4[4];     /* '<S556>/Data Type Conversion4' */
  real32_T ByteUnpack_o2[4];           /* '<S568>/Byte Unpack' */
  real32_T WP_param[7];                /* '<S23>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  real32_T f;
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_a[4];     /* '<S16>/Data Type Conversion' */
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
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S19>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S17>/Data Type Conversion' */
  uint32_T DataTypeConversion8;        /* '<S556>/Data Type Conversion8' */
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T DataTypeConversion2_h;      /* '<S16>/Data Type Conversion2' */
  uint16_T Throttle;                   /* '<S22>/Data Type Conversion2' */
  uint16_T Heading[9];                 /* '<S20>/Data Type Conversion1' */
  uint16_T Memory_a;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T DataTypeConversion1_h[10];  /* '<S556>/Data Type Conversion1' */
  uint16_T ByteUnpack_o4[2];           /* '<S568>/Byte Unpack' */
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
  int16_T DataTypeConversion_lx[9];    /* '<S556>/Data Type Conversion' */
  int16_T DataTypeConversion_p;        /* '<S10>/Data Type Conversion' */
  int16_T DataTypeConversion1_c;       /* '<S10>/Data Type Conversion1' */
  int16_T DataTypeConversion2_j;       /* '<S10>/Data Type Conversion2' */
  int16_T Sum;                         /* '<S583>/Sum' */
  int16_T ByteUnpack_o3[4];            /* '<S568>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1[100];    /* '<S1>/S-Function Builder' */
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
  uint8_T BytePack[63];                /* '<S556>/Byte Pack' */
  uint8_T indice_dimario;              /* '<S573>/MATLAB Function' */
  uint8_T ByteUnpack_o1[2];            /* '<S568>/Byte Unpack' */
  uint8_T ByteUnpack_o5;               /* '<S568>/Byte Unpack' */
  uint8_T messaggio[31];               /* '<S564>/MATLAB Function' */
  uint8_T iflogic;                     /* '<S19>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S21>/Data Type Conversion3' */
  boolean_T HitCrossing;               /* '<S252>/Hit  Crossing' */
} B_Copy_of_laod_arduino_2021_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_b_T obj; /* '<S7>/Serial Transmit' */
  codertarget_arduinobase_int_b_T obj_o;/* '<S25>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_e;/* '<S569>/Serial Receive1' */
  codertarget_arduinobase_block_T obj_b;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S5>/Digital Output' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  real_T UnitDelay_DSTATE;             /* '<S565>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S342>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S392>/Integrator' */
  real_T DiscreteWashoutFilter_states; /* '<S306>/Discrete Washout Filter' */
  real_T SFunctionBuilder10_DSTATE;    /* '<S10>/S-Function Builder10' */
  real_T SFunctionBuilder4_DSTATE;     /* '<S10>/S-Function Builder4' */
  real_T SFunctionBuilder5_DSTATE;     /* '<S10>/S-Function Builder5' */
  real_T SFunctionBuilder9_DSTATE;     /* '<S10>/S-Function Builder9' */
  real_T SFunctionBuilder_DSTATE_n;    /* '<S4>/S-Function Builder' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S453>/Discrete-Time Integrator' */
  volatile real_T RateTransition_Buffer0;/* '<S29>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S29>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S29>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S29>/Memory2' */
  real_T Memory_PreviousInput_l[9];    /* '<S573>/Memory' */
  real_T flag;                         /* '<S444>/GO_HOME' */
  real_T Memory4_PreviousInput;        /* '<S443>/Memory4' */
  real_T flag_m;                       /* '<S443>/WAYPOINTS' */
  real_T lat1;                         /* '<S443>/WAYPOINTS' */
  real_T long1;                        /* '<S443>/WAYPOINTS' */
  real_T Memory7_PreviousInput;        /* '<S442>/Memory7' */
  real_T Memory5_PreviousInput;        /* '<S442>/Memory5' */
  real_T Memory1_PreviousInput_l;      /* '<S442>/Memory1' */
  real_T Memory2_PreviousInput_f;      /* '<S442>/Memory2' */
  real_T x[4];                         /* '<S453>/MATLAB Function' */
  real_T cycle_count;                  /* '<S453>/MATLAB Function' */
  real_T eps[4];                       /* '<S453>/MATLAB Function' */
  real_T flag_c;                       /* '<S442>/ALLINEAMENTO' */
  real_T Memory3_PreviousInput;        /* '<S441>/Memory3' */
  real_T ALT_ref;                      /* '<S441>/VETTORIALE' */
  real_T Memory_PreviousInput_i;       /* '<S440>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S440>/Memory1' */
  real_T alarm;                        /* '<S417>/MATLAB Function1' */
  real_T Memory_PreviousInput_h;       /* '<S438>/Memory' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real_T test1;                        /* '<S1>/MATLAB Function1' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP_AL[42];              /* '<S1>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S5>/Pulse Generator1' */
  int_T HitCrossing_MODE;              /* '<S252>/Hit  Crossing' */
  uint16_T Memory_PreviousInput_ic[8]; /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_n;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  int8_T Integrator_PrevResetState;    /* '<S392>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S453>/Discrete-Time Integrator' */
  uint8_T Memory4_PreviousInput_c[300];/* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput_l[100];/* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_d[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_h5[4];  /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput_o;     /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_a[9];  /* '<S1>/Memory2' */
  uint8_T message[80];                 /* '<S571>/Create_message' */
  uint8_T counter_k;                   /* '<S571>/Create_message' */
  uint8_T message_k[31];               /* '<S564>/MATLAB Function' */
  uint8_T counter_n;                   /* '<S564>/MATLAB Function' */
  uint8_T is_active_c10_Copy_of_laod_ardu;/* '<S442>/Chart1' */
  uint8_T is_c10_Copy_of_laod_arduino_202;/* '<S442>/Chart1' */
  uint8_T Memory1_PreviousInput_h;     /* '<S441>/Memory1' */
  uint8_T Memory6_PreviousInput;       /* '<S441>/Memory6' */
  uint8_T is_active_c1_Copy_of_laod_ardui;/* '<S440>/Chart1' */
  uint8_T is_c1_Copy_of_laod_arduino_2021;/* '<S440>/Chart1' */
  uint8_T temporalCounter_i1;          /* '<S440>/Chart1' */
  uint8_T is_active_c21_Copy_of_laod_ardu;/* '<S41>/Chart' */
  uint8_T is_c21_Copy_of_laod_arduino_202;/* '<S41>/Chart' */
  uint8_T is_active_c26_Copy_of_laod_ardu;/* '<S40>/ STATI' */
  uint8_T is_c26_Copy_of_laod_arduino_202;/* '<S40>/ STATI' */
  uint8_T is_AUTOMATICA;               /* '<S40>/ STATI' */
  uint8_T is_active_c23_Copy_of_laod_ardu;
                                 /* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_c23_Copy_of_laod_arduino_202;
                                 /* '<S42>/SELEZIONE MODALITA'  HOLD//SELECT' */
  uint8_T is_active_c9_Copy_of_laod_ardui;/* '<S15>/Chart' */
  uint8_T i;                           /* '<S15>/Chart' */
  uint8_T message_i[100];              /* '<S1>/MATLAB Function4' */
  uint8_T counter_a;                   /* '<S1>/MATLAB Function4' */
  boolean_T start_found;               /* '<S571>/Create_message' */
  boolean_T end_found;                 /* '<S571>/Create_message' */
  boolean_T start_found_c;             /* '<S564>/MATLAB Function' */
  boolean_T x_not_empty;               /* '<S453>/MATLAB Function' */
  boolean_T x_new_not_empty;           /* '<S453>/MATLAB Function' */
  boolean_T cycle_count_not_empty;     /* '<S453>/MATLAB Function' */
  boolean_T eps_not_empty;             /* '<S453>/MATLAB Function' */
  boolean_T Tf_not_empty;              /* '<S412>/MATLAB Function1' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
  boolean_T Enabled_MODE;              /* '<S434>/Enabled ' */
  boolean_T Enabled_MODE_p;            /* '<S426>/Enabled ' */
  boolean_T Enabled_MODE_m;            /* '<S425>/Enabled ' */
  DW_ResettableSubsystem_Copy_o_T ResettableSubsystem_o;/* '<S411>/Resettable Subsystem' */
  DW_ResettableSubsystem_Copy_o_T ResettableSubsystem;/* '<S410>/Resettable Subsystem' */
} DW_Copy_of_laod_arduino_2021_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S252>/Hit  Crossing' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S442>/Sample and Hold' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S440>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE_h; /* '<S440>/Sample and Hold' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S434>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_h;/* '<S426>/Resettable Subsystem' */
  ZCSigState ResettableSubsystem_Reset_ZCE_p;/* '<S425>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_Copy__T ResettableSubsystem_o;/* '<S411>/Resettable Subsystem' */
  ZCE_ResettableSubsystem_Copy__T ResettableSubsystem;/* '<S410>/Resettable Subsystem' */
  ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S252>/Enabled Subsystem' */
} PrevZCX_Copy_of_laod_arduino__T;

/* Parameters for system: '<S410>/Enabled Subsystem' */
struct P_EnabledSubsystem_Copy_of_la_T_ {
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
struct P_ResettableSubsystem_Copy_of_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S421>/Memory'
                                        */
};

/* Parameters (default storage) */
struct P_Copy_of_laod_arduino_2021_T_ {
  real_T Kp_comp_h;                    /* Variable: Kp_comp_h
                                        * Referenced by: '<S304>/Constant3'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S39>/saturatore A'
                                        *   '<S39>/saturatore A1'
                                        *   '<S575>/Constant8'
                                        *   '<S581>/Constant'
                                        *   '<S399>/Saturation'
                                        */
  real_T attuatore_Amin;               /* Variable: attuatore_Amin
                                        * Referenced by:
                                        *   '<S39>/saturatore A'
                                        *   '<S39>/saturatore A1'
                                        *   '<S575>/Constant9'
                                        *   '<S581>/Constant1'
                                        *   '<S399>/Saturation'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S577>/Constant8'
                                        *   '<S584>/Constant'
                                        *   '<S304>/saturatore E2'
                                        *   '<S349>/Saturation'
                                        */
  real_T attuatore_Emin;               /* Variable: attuatore_Emin
                                        * Referenced by:
                                        *   '<S577>/Constant9'
                                        *   '<S584>/Constant1'
                                        *   '<S304>/saturatore E2'
                                        *   '<S349>/Saturation'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S39>/saturatore R'
                                        *   '<S579>/Constant8'
                                        *   '<S582>/Constant'
                                        */
  real_T attuatore_Rmin;               /* Variable: attuatore_Rmin
                                        * Referenced by:
                                        *   '<S39>/saturatore R'
                                        *   '<S579>/Constant9'
                                        *   '<S582>/Constant1'
                                        */
  real_T attuatore_Tmax;               /* Variable: attuatore_Tmax
                                        * Referenced by: '<S580>/manetta_massima'
                                        */
  real_T attuatore_Tmin;               /* Variable: attuatore_Tmin
                                        * Referenced by: '<S580>/manetta_minima'
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
                                        * Referenced by: '<S39>/Gain1'
                                        */
  real_T inv_E;                        /* Variable: inv_E
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T inv_R;                        /* Variable: inv_R
                                        * Referenced by: '<S39>/Gain2'
                                        */
  real_T inv_comp_h;                   /* Variable: inv_comp_h
                                        * Referenced by: '<S304>/Gain'
                                        */
  real_T phi_max;                      /* Variable: phi_max
                                        * Referenced by:
                                        *   '<S576>/Constant8'
                                        *   '<S576>/Saturation'
                                        */
  real_T phi_min;                      /* Variable: phi_min
                                        * Referenced by:
                                        *   '<S576>/Constant9'
                                        *   '<S576>/Saturation'
                                        */
  real_T safe_V;                       /* Variable: safe_V
                                        * Referenced by: '<S417>/Constant'
                                        */
  real_T safe_phi;                     /* Variable: safe_phi
                                        * Referenced by: '<S417>/Constant1'
                                        */
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by:
                                        *   '<S421>/Constant4'
                                        *   '<S424>/Constant4'
                                        *   '<S438>/Constant4'
                                        */
  real_T theta_max;                    /* Variable: theta_max
                                        * Referenced by:
                                        *   '<S578>/Constant8'
                                        *   '<S578>/Saturation'
                                        */
  real_T theta_min;                    /* Variable: theta_min
                                        * Referenced by:
                                        *   '<S578>/Constant9'
                                        *   '<S578>/Saturation'
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
                               * Referenced by: '<S342>/Integrator'
                               */
  real_T PIDController_InitialConditio_d;
                              /* Mask Parameter: PIDController_InitialConditio_d
                               * Referenced by: '<S392>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S385>/Kb'
                                        */
  real_T PIDController_Kb_k;           /* Mask Parameter: PIDController_Kb_k
                                        * Referenced by: '<S335>/Kb'
                                        */
  real_T PIDController_Kt;             /* Mask Parameter: PIDController_Kt
                                        * Referenced by: '<S403>/Kt'
                                        */
  real_T PIDController_Kt_m;           /* Mask Parameter: PIDController_Kt_m
                                        * Referenced by: '<S353>/Kt'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S537>/Constant'
                                       */
  real_T CompareToConstant_const_d; /* Mask Parameter: CompareToConstant_const_d
                                     * Referenced by: '<S535>/Constant'
                                     */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S538>/Constant'
                                     */
  real_T CompareToConstant_const_b; /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S531>/Constant'
                                     */
  real_T CompareToConstant_const_dp;
                                   /* Mask Parameter: CompareToConstant_const_dp
                                    * Referenced by: '<S529>/Constant'
                                    */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S532>/Constant'
                                     */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S25>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Out1_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S303>/Out1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S309>/Constant5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 16
                                        * Referenced by: '<S309>/Switch1'
                                        */
  real_T r_rif_Value;                  /* Expression: 0
                                        * Referenced by: '<S39>/r_rif'
                                        */
  real_T Alarm_Int_Y0;                 /* Expression: 0
                                        * Referenced by: '<S428>/Alarm_Int'
                                        */
  real_T Alarm_Int_Y0_j;               /* Expression: 0
                                        * Referenced by: '<S431>/Alarm_Int'
                                        */
  real_T Constant_Value;               /* Expression: 1
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
  real_T Constant1_Value_d;            /* Expression: 20
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S415>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 50
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S448>/ '
                                        */
  real_T _Y0_a;                        /* Expression: initCond
                                        * Referenced by: '<S449>/ '
                                        */
  real_T Gain_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S447>/Gain'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S440>/Memory'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S446>/Gain'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S440>/Memory1'
                                        */
  real_T Out1_Y0_d;                    /* Computed Parameter: Out1_Y0_d
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
  real_T Gain_Gain_e;                  /* Expression: 180/pi
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
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S453>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
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
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S453>/Switch'
                                        */
  real_T Gain_Gain_e0;                 /* Expression: -1
                                        * Referenced by: '<S453>/Gain'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S453>/Constant2'
                                        */
  real_T h_ref_Y0_n;                   /* Computed Parameter: h_ref_Y0_n
                                        * Referenced by: '<S457>/h_ref'
                                        */
  real_T RC_ref_Y0;                    /* Computed Parameter: RC_ref_Y0
                                        * Referenced by: '<S457>/RC_ref'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S457>/Gain'
                                        */
  real_T psi_ref_landing_Y0;           /* Computed Parameter: psi_ref_landing_Y0
                                        * Referenced by: '<S458>/psi_ref_landing'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S527>/Bias'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S527>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S527>/Bias1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 360
                                        * Referenced by: '<S530>/Constant2'
                                        */
  real_T Bias_Bias_n;                  /* Expression: 180
                                        * Referenced by: '<S530>/Bias'
                                        */
  real_T Bias1_Bias_n;                 /* Expression: -180
                                        * Referenced by: '<S530>/Bias1'
                                        */
  real_T Constant_Value_n;             /* Expression: 180
                                        * Referenced by: '<S524>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S524>/Constant1'
                                        */
  real_T Constant2_Value_gk;           /* Expression: 360
                                        * Referenced by: '<S528>/Constant2'
                                        */
  real_T Bias_Bias_j;                  /* Expression: 180
                                        * Referenced by: '<S528>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S528>/Bias1'
                                        */
  real_T Bias_Bias_f;                  /* Expression: -90
                                        * Referenced by: '<S533>/Bias'
                                        */
  real_T Gain_Gain_mn;                 /* Expression: -1
                                        * Referenced by: '<S533>/Gain'
                                        */
  real_T Bias1_Bias_f;                 /* Expression: +90
                                        * Referenced by: '<S533>/Bias1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 360
                                        * Referenced by: '<S536>/Constant2'
                                        */
  real_T Bias_Bias_e;                  /* Expression: 180
                                        * Referenced by: '<S536>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S536>/Bias1'
                                        */
  real_T Constant_Value_d;             /* Expression: 180
                                        * Referenced by: '<S525>/Constant'
                                        */
  real_T Constant1_Value_d5;           /* Expression: 0
                                        * Referenced by: '<S525>/Constant1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S534>/Constant2'
                                        */
  real_T Bias_Bias_jc;                 /* Expression: 180
                                        * Referenced by: '<S534>/Bias'
                                        */
  real_T Bias1_Bias_gb;                /* Expression: -180
                                        * Referenced by: '<S534>/Bias1'
                                        */
  real_T _Y0_b[2];                     /* Expression: initCond
                                        * Referenced by: '<S467>/ '
                                        */
  real_T Constant3_Value_c;            /* Expression: 1
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
  real_T Gain_Gain_es;                 /* Expression: 180/pi
                                        * Referenced by: '<S471>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S472>/Gain'
                                        */
  real_T altwaypointvirtuale_Value[3]; /* Expression: [45 45 45]
                                        * Referenced by: '<S455>/alt waypoint virtuale'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S463>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S462>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S460>/Gain'
                                        */
  real_T Gain_Gain_b2;                 /* Expression: 180/pi
                                        * Referenced by: '<S461>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S523>/Gain1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 1
                                        * Referenced by: '<S539>/Constant2'
                                        */
  real_T Constant_Value_nw;            /* Expression: 1
                                        * Referenced by: '<S543>/Constant'
                                        */
  real_T Constant4_Value_o;            /* Expression: 1
                                        * Referenced by: '<S542>/Constant4'
                                        */
  real_T Constant_Value_j;             /* Expression: 1/298.257223563
                                        * Referenced by: '<S541>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S541>/f'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S540>/Gain1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 6378137
                                        * Referenced by: '<S539>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S539>/Constant'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S539>/Constant3'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S464>/Gain'
                                        */
  real_T Gain_Gain_ov;                 /* Expression: 180/pi
                                        * Referenced by: '<S465>/Gain'
                                        */
  real_T Gain_Gain_jp;                 /* Expression: 180/pi
                                        * Referenced by: '<S466>/Gain'
                                        */
  real_T Memory7_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S442>/Memory7'
                                        */
  real_T Memory5_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S442>/Memory5'
                                        */
  real_T Memory1_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S442>/Memory1'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S442>/Memory2'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S442>/Constant4'
                                        */
  real_T Constant2_Value_n3;           /* Expression: 45
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
  real_T Out3_Y0_j;                    /* Computed Parameter: Out3_Y0_j
                                        * Referenced by: '<S443>/Out3'
                                        */
  real_T Out4_Y0_m;                    /* Computed Parameter: Out4_Y0_m
                                        * Referenced by: '<S443>/Out4'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 1
                                        * Referenced by: '<S443>/Memory4'
                                        */
  real_T Gain_Gain_bu;                 /* Expression: 180/pi
                                        * Referenced by: '<S544>/Gain'
                                        */
  real_T Gain_Gain_jz;                 /* Expression: 180/pi
                                        * Referenced by: '<S545>/Gain'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 180/pi
                                        * Referenced by: '<S546>/Gain'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S444>/Out1'
                                        */
  real_T Out2_Y0_c;                    /* Computed Parameter: Out2_Y0_c
                                        * Referenced by: '<S444>/Out2'
                                        */
  real_T Out3_Y0_d;                    /* Computed Parameter: Out3_Y0_d
                                        * Referenced by: '<S444>/Out3'
                                        */
  real_T Out4_Y0_c;                    /* Computed Parameter: Out4_Y0_c
                                        * Referenced by: '<S444>/Out4'
                                        */
  real_T Gain_Gain_ji;                 /* Expression: 180/pi
                                        * Referenced by: '<S549>/Gain'
                                        */
  real_T Gain_Gain_gf;                 /* Expression: 180/pi
                                        * Referenced by: '<S550>/Gain'
                                        */
  real_T Gain_Gain_ov4;                /* Expression: 180/pi
                                        * Referenced by: '<S551>/Gain'
                                        */
  real_T SerialReceive1_Protocol;      /* Expression: 0
                                        * Referenced by: '<S569>/Serial Receive1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S570>/Constant2'
                                        */
  real_T h_to_subtract_Y0;             /* Computed Parameter: h_to_subtract_Y0
                                        * Referenced by: '<S570>/h_to_subtract'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S570>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2
                                        * Referenced by: '<S570>/Constant1'
                                        */
  real_T Constant3_Value_ct;           /* Expression: 3
                                        * Referenced by: '<S570>/Constant3'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S573>/Outport'
                                        */
  real_T Memory_InitialCondition_ab;   /* Expression: 0
                                        * Referenced by: '<S573>/Memory'
                                        */
  real_T SerialTransmit_Protocol_f;    /* Expression: 0
                                        * Referenced by: '<S7>/Serial Transmit'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_js;           /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
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
                                        * Referenced by: '<S556>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: tau
                                        * Referenced by: '<S565>/Constant'
                                        */
  real_T Constant1_Value_j4[31];       /* Expression: zeros(1,31)
                                        * Referenced by: '<S556>/Constant1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 1
                                        * Referenced by: '<S556>/Constant2'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.01
                                        * Referenced by: '<S556>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S565>/Unit Delay'
                                        */
  real_T Constant10_Value;             /* Expression: 0.38
                                        * Referenced by: '<S7>/Constant10'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S552>/Gain1'
                                        */
  real_T Gain_Gain_mz;                 /* Expression: 180/pi
                                        * Referenced by: '<S414>/Gain'
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
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S7>/Constant16'
                                        */
  real_T Constant1_Value_bw;           /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant8_Value_l;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 4
                                        * Referenced by: '<S7>/Constant9'
                                        */
  real_T Constant11_Value;             /* Expression: 3
                                        * Referenced by: '<S7>/Constant11'
                                        */
  real_T Constant14_Value;             /* Expression: 6
                                        * Referenced by: '<S7>/Constant14'
                                        */
  real_T Constant_Value_hx;            /* Expression: 0
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
  real_T Constant12_Value;             /* Expression: 0.86
                                        * Referenced by: '<S7>/Constant12'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S553>/Gain1'
                                        */
  real_T Constant13_Value;             /* Expression: 0.98
                                        * Referenced by: '<S7>/Constant13'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: pi/180
                                        * Referenced by: '<S554>/Gain1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S557>/Gain1'
                                        */
  real_T Gain_Gain_f2;                 /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S558>/Gain1'
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
                                        * Referenced by: '<S556>/Gain4'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S16>/vel y'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 100
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S559>/Gain1'
                                        */
  real_T Gain1_Gain_n1;                /* Expression: pi/180
                                        * Referenced by: '<S555>/Gain1'
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
  real_T Constant_Value_bh;            /* Expression: 4
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant6_Value[8];           /* Expression: [0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 100
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T Constant2_Value_i4;           /* Expression: 0
                                        * Referenced by: '<S304>/Constant2'
                                        */
  real_T Constant1_Value_fj;           /* Expression: 0
                                        * Referenced by: '<S304>/Constant1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 1
                                        * Referenced by: '<S578>/Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S342>/Integrator'
                                        */
  real_T Gain1_Gain_jm;                /* Expression: pi/180
                                        * Referenced by: '<S359>/Gain1'
                                        */
  real_T Gain_Gain_od;                 /* Expression: 180/pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant2_Value_m;            /* Expression: 90
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant1_Value_ng;           /* Expression: 0
                                        * Referenced by: '<S305>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S576>/Gain'
                                        */
  real_T Constant3_Value_cr;           /* Expression: 2
                                        * Referenced by: '<S305>/Constant3'
                                        */
  real_T Integrator_gainval_g;       /* Computed Parameter: Integrator_gainval_g
                                      * Referenced by: '<S392>/Integrator'
                                      */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S33>/Gain'
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
  real_T Constant7_Value;              /* Expression: 101000
                                        * Referenced by: '<S7>/Constant7'
                                        */
  real_T Constant4_Value_jt;           /* Expression: 30
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant5_Value_d;            /* Expression: 40000
                                        * Referenced by: '<S7>/Constant5'
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
  real_T Constant15_Value;             /* Expression: 24
                                        * Referenced by: '<S7>/Constant15'
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
  real_T Constant17_Value;             /* Expression: 30
                                        * Referenced by: '<S7>/Constant17'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S561>/Gain'
                                        */
  real_T Gain_Gain_db;                 /* Expression: 180/pi
                                        * Referenced by: '<S562>/Gain'
                                        */
  real_T Gain_Gain_dc;                 /* Expression: 180/pi
                                        * Referenced by: '<S563>/Gain'
                                        */
  real_T Gain_Gain_bk;                 /* Expression: 100
                                        * Referenced by: '<S556>/Gain'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 100
                                        * Referenced by: '<S556>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S556>/Gain3'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0.3
                                        * Referenced by: '<S252>/Hit  Crossing'
                                        */
  real_T Gain_Gain_je;                 /* Expression: 180/pi
                                        * Referenced by: '<S416>/Gain'
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
  real_T Switch1_Threshold_c;          /* Expression: 9
                                        * Referenced by: '<S29>/Switch1'
                                        */
  int32_T Constant_Value_gw;           /* Computed Parameter: Constant_Value_gw
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Out2_Y0_cb;                 /* Computed Parameter: Out2_Y0_cb
                                        * Referenced by: '<S568>/Out2'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S21>/onboard_control_sensor_present uint32'
                           */
  int16_T Out3_Y0_a;                   /* Computed Parameter: Out3_Y0_a
                                        * Referenced by: '<S568>/Out3'
                                        */
  int16_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S9>/Switch'
                                        */
  int16_T Gain1_Gain_eu;               /* Computed Parameter: Gain1_Gain_eu
                                        * Referenced by: '<S21>/Gain1'
                                        */
  uint16_T Out4_Y0_i;                  /* Computed Parameter: Out4_Y0_i
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
  int8_T Gain3_Gain_o;                 /* Computed Parameter: Gain3_Gain_o
                                        * Referenced by: '<S8>/Gain3'
                                        */
  uint8_T Memory_InitialCondition_j;
                                /* Computed Parameter: Memory_InitialCondition_j
                                 * Referenced by: '<S441>/Memory'
                                 */
  uint8_T Memory1_InitialCondition_g;
                               /* Computed Parameter: Memory1_InitialCondition_g
                                * Referenced by: '<S441>/Memory1'
                                */
  uint8_T Memory2_InitialCondition_n;
                               /* Computed Parameter: Memory2_InitialCondition_n
                                * Referenced by: '<S441>/Memory2'
                                */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S441>/Memory6'
                                  */
  uint8_T mario_Y0;                    /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S573>/mario'
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
                                        * Referenced by: '<S556>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<S556>/Fine MSG1'
                                        */
  P_ResettableSubsystem_Copy_of_T ResettableSubsystem_o;/* '<S411>/Resettable Subsystem' */
  P_EnabledSubsystem_Copy_of_la_T EnabledSubsystem_j;/* '<S411>/Enabled Subsystem' */
  P_ResettableSubsystem_Copy_of_T ResettableSubsystem;/* '<S410>/Resettable Subsystem' */
  P_EnabledSubsystem_Copy_of_la_T EnabledSubsystem_h;/* '<S410>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_laod_arduino__T {
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
extern P_Copy_of_laod_arduino_2021_T Copy_of_laod_arduino_2021_P;

/* Block signals (default storage) */
extern B_Copy_of_laod_arduino_2021_T Copy_of_laod_arduino_2021_B;

/* Block states (default storage) */
extern DW_Copy_of_laod_arduino_2021_T Copy_of_laod_arduino_2021_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Copy_of_laod_arduino__T Copy_of_laod_arduino_20_PrevZCX;

/* External data declarations for dependent source files */
extern const uint16_T Copy_of_laod_arduino_2021_U16GND;/* uint16_T ground */

/* External function called from main */
extern void Copy_of_laod_arduino_2021_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Copy_of_laod_arduino_2021_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Copy_of_laod_arduino_2021_initialize(void);
extern void Copy_of_laod_arduino_2021_step0(void);
extern void Copy_of_laod_arduino_2021_step1(void);
extern void Copy_of_laod_arduino_2021_step2(void);
extern void Copy_of_laod_arduino_2021_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_laod_arduino_T *const Copy_of_laod_arduino_2021_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S45>/Constant1' : Unused code path elimination
 * Block '<S45>/Constant10' : Unused code path elimination
 * Block '<S45>/Constant11' : Unused code path elimination
 * Block '<S45>/Constant12' : Unused code path elimination
 * Block '<S45>/Constant13' : Unused code path elimination
 * Block '<S45>/Constant14' : Unused code path elimination
 * Block '<S45>/Constant15' : Unused code path elimination
 * Block '<S45>/Constant2' : Unused code path elimination
 * Block '<S45>/Constant3' : Unused code path elimination
 * Block '<S45>/Constant5' : Unused code path elimination
 * Block '<S45>/Constant7' : Unused code path elimination
 * Block '<S45>/Constant9' : Unused code path elimination
 * Block '<S45>/Multiport Switch' : Unused code path elimination
 * Block '<S45>/Multiport Switch1' : Unused code path elimination
 * Block '<S45>/Multiport Switch2' : Unused code path elimination
 * Block '<S76>/DProd Out' : Unused code path elimination
 * Block '<S77>/Filter' : Unused code path elimination
 * Block '<S77>/SumD' : Unused code path elimination
 * Block '<S79>/IProd Out' : Unused code path elimination
 * Block '<S82>/Integrator' : Unused code path elimination
 * Block '<S85>/NProd Out' : Unused code path elimination
 * Block '<S87>/PProd Out' : Unused code path elimination
 * Block '<S91>/Sum' : Unused code path elimination
 * Block '<S93>/Kt' : Unused code path elimination
 * Block '<S93>/SumI3' : Unused code path elimination
 * Block '<S94>/SumI1' : Unused code path elimination
 * Block '<S124>/DProd Out' : Unused code path elimination
 * Block '<S125>/Filter' : Unused code path elimination
 * Block '<S125>/SumD' : Unused code path elimination
 * Block '<S127>/IProd Out' : Unused code path elimination
 * Block '<S130>/Integrator' : Unused code path elimination
 * Block '<S133>/NProd Out' : Unused code path elimination
 * Block '<S135>/PProd Out' : Unused code path elimination
 * Block '<S139>/Sum' : Unused code path elimination
 * Block '<S141>/Kt' : Unused code path elimination
 * Block '<S141>/SumI3' : Unused code path elimination
 * Block '<S142>/SumI1' : Unused code path elimination
 * Block '<S175>/IProd Out' : Unused code path elimination
 * Block '<S178>/Integrator' : Unused code path elimination
 * Block '<S183>/PProd Out' : Unused code path elimination
 * Block '<S187>/Sum' : Unused code path elimination
 * Block '<S189>/Kt' : Unused code path elimination
 * Block '<S189>/SumI3' : Unused code path elimination
 * Block '<S190>/SumI1' : Unused code path elimination
 * Block '<S45>/Saturation' : Unused code path elimination
 * Block '<S45>/Sum1' : Unused code path elimination
 * Block '<S45>/Sum2' : Unused code path elimination
 * Block '<S45>/Sum4' : Unused code path elimination
 * Block '<S45>/Switch auto-manual' : Unused code path elimination
 * Block '<S45>/Switch maneuver' : Unused code path elimination
 * Block '<S45>/Switch rc saturata' : Unused code path elimination
 * Block '<S45>/n-D Lookup Table' : Unused code path elimination
 * Block '<S42>/Kp' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Lookup Table2' : Unused code path elimination
 * Block '<S195>/Data Type Duplicate' : Unused code path elimination
 * Block '<S195>/Data Type Propagation' : Unused code path elimination
 * Block '<S195>/LowerRelop1' : Unused code path elimination
 * Block '<S195>/Switch' : Unused code path elimination
 * Block '<S195>/Switch2' : Unused code path elimination
 * Block '<S195>/UpperRelop' : Unused code path elimination
 * Block '<S42>/Switch HOLD//SELECT' : Unused code path elimination
 * Block '<S196>/Constant3' : Unused code path elimination
 * Block '<S196>/Constant4' : Unused code path elimination
 * Block '<S196>/Multiport Switch2' : Unused code path elimination
 * Block '<S196>/Multiport Switch3' : Unused code path elimination
 * Block '<S196>/Switch3' : Unused code path elimination
 * Block '<S196>/Switch4' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S43>/Constant2' : Unused code path elimination
 * Block '<S223>/AND3' : Unused code path elimination
 * Block '<S223>/Constant1' : Unused code path elimination
 * Block '<S223>/DataTypeConv1' : Unused code path elimination
 * Block '<S223>/DataTypeConv2' : Unused code path elimination
 * Block '<S225>/DeadZone' : Unused code path elimination
 * Block '<S223>/Equal1' : Unused code path elimination
 * Block '<S223>/NotEqual' : Unused code path elimination
 * Block '<S223>/SignPreIntegrator' : Unused code path elimination
 * Block '<S223>/SignPreSat' : Unused code path elimination
 * Block '<S223>/Switch' : Unused code path elimination
 * Block '<S223>/ZeroGain' : Unused code path elimination
 * Block '<S226>/DProd Out' : Unused code path elimination
 * Block '<S227>/Filter' : Unused code path elimination
 * Block '<S227>/SumD' : Unused code path elimination
 * Block '<S229>/IProd Out' : Unused code path elimination
 * Block '<S232>/Integrator' : Unused code path elimination
 * Block '<S235>/NProd Out' : Unused code path elimination
 * Block '<S237>/PProd Out' : Unused code path elimination
 * Block '<S239>/Saturation' : Unused code path elimination
 * Block '<S241>/Sum' : Unused code path elimination
 * Block '<S243>/Kt' : Unused code path elimination
 * Block '<S243>/SumI3' : Unused code path elimination
 * Block '<S244>/SumI1' : Unused code path elimination
 * Block '<S43>/Switch' : Unused code path elimination
 * Block '<S43>/Switch auto-manual' : Unused code path elimination
 * Block '<S198>/Constant' : Unused code path elimination
 * Block '<S198>/Constant1' : Unused code path elimination
 * Block '<S198>/Constant2' : Unused code path elimination
 * Block '<S249>/Gain1' : Unused code path elimination
 * Block '<S198>/Math Function' : Unused code path elimination
 * Block '<S250>/Gain' : Unused code path elimination
 * Block '<S198>/Sum' : Unused code path elimination
 * Block '<S198>/Sum1' : Unused code path elimination
 * Block '<S198>/Sum2' : Unused code path elimination
 * Block '<S198>/Switch' : Unused code path elimination
 * Block '<S198>/Switch1' : Unused code path elimination
 * Block '<S277>/AND3' : Unused code path elimination
 * Block '<S277>/Constant1' : Unused code path elimination
 * Block '<S277>/DataTypeConv1' : Unused code path elimination
 * Block '<S277>/DataTypeConv2' : Unused code path elimination
 * Block '<S279>/DeadZone' : Unused code path elimination
 * Block '<S277>/Equal1' : Unused code path elimination
 * Block '<S277>/NotEqual' : Unused code path elimination
 * Block '<S277>/SignPreIntegrator' : Unused code path elimination
 * Block '<S277>/SignPreSat' : Unused code path elimination
 * Block '<S277>/Switch' : Unused code path elimination
 * Block '<S277>/ZeroGain' : Unused code path elimination
 * Block '<S283>/IProd Out' : Unused code path elimination
 * Block '<S286>/Integrator' : Unused code path elimination
 * Block '<S291>/PProd Out' : Unused code path elimination
 * Block '<S293>/Saturation' : Unused code path elimination
 * Block '<S295>/Sum' : Unused code path elimination
 * Block '<S297>/Kt' : Unused code path elimination
 * Block '<S297>/SumI3' : Unused code path elimination
 * Block '<S298>/SumI1' : Unused code path elimination
 * Block '<S44>/Sum3' : Unused code path elimination
 * Block '<S44>/Switch Bumpless 1' : Unused code path elimination
 * Block '<S252>/Constant3' : Unused code path elimination
 * Block '<S303>/Constant' : Unused code path elimination
 * Block '<S252>/Switch' : Unused code path elimination
 * Block '<S252>/throttle - landing' : Unused code path elimination
 * Block '<S38>/Switch di selezione riferimeti  per i loop interni 1' : Unused code path elimination
 * Block '<S38>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
 * Block '<S38>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
 * Block '<S39>/Gain3' : Unused code path elimination
 * Block '<S39>/Switch Bumpless 7' : Unused code path elimination
 * Block '<S307>/Constant4' : Unused code path elimination
 * Block '<S307>/Constant7' : Unused code path elimination
 * Block '<S307>/Constant8' : Unused code path elimination
 * Block '<S307>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S307>/Multiport Switch1' : Unused code path elimination
 * Block '<S307>/Sum' : Unused code path elimination
 * Block '<S307>/Switch Bumpless 1' : Unused code path elimination
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
 * Block '<S40>/Scope1' : Unused code path elimination
 * Block '<S418>/Abs2' : Unused code path elimination
 * Block '<S453>/Constant1' : Unused code path elimination
 * Block '<S453>/Multiply1' : Unused code path elimination
 * Block '<S442>/Constant1' : Unused code path elimination
 * Block '<S442>/Constant6' : Unused code path elimination
 * Block '<S442>/Constant7' : Unused code path elimination
 * Block '<S457>/Constant1' : Unused code path elimination
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
 * Block '<S442>/Switch di selezione  Task - Waypoint navigation5' : Unused code path elimination
 * Block '<S442>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
 * Block '<S442>/Switch1' : Unused code path elimination
 * Block '<S443>/saturatore V' : Unused code path elimination
 * Block '<S443>/saturatore V1' : Unused code path elimination
 * Block '<S41>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
 * Block '<S41>/Switch di selezione  Task - Waypoint navigation1' : Unused code path elimination
 * Block '<S41>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
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
 * '<Root>' : 'Copy_of_laod_arduino_2021'
 * '<S1>'   : 'Copy_of_laod_arduino_2021/AIR RX'
 * '<S2>'   : 'Copy_of_laod_arduino_2021/AIR TX'
 * '<S3>'   : 'Copy_of_laod_arduino_2021/AUTOPILOTA'
 * '<S4>'   : 'Copy_of_laod_arduino_2021/Inizializzazioni'
 * '<S5>'   : 'Copy_of_laod_arduino_2021/LED 13-44'
 * '<S6>'   : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE'
 * '<S7>'   : 'Copy_of_laod_arduino_2021/Misure Sensori'
 * '<S8>'   : 'Copy_of_laod_arduino_2021/PARAMETRI SISTEMA DI CONTROLLO'
 * '<S9>'   : 'Copy_of_laod_arduino_2021/RADIOCOMANDO'
 * '<S10>'  : 'Copy_of_laod_arduino_2021/Servi'
 * '<S11>'  : 'Copy_of_laod_arduino_2021/AIR RX/MATLAB Function1'
 * '<S12>'  : 'Copy_of_laod_arduino_2021/AIR RX/MATLAB Function2'
 * '<S13>'  : 'Copy_of_laod_arduino_2021/AIR RX/MATLAB Function3'
 * '<S14>'  : 'Copy_of_laod_arduino_2021/AIR RX/MATLAB Function4'
 * '<S15>'  : 'Copy_of_laod_arduino_2021/AIR TX/Enable '
 * '<S16>'  : 'Copy_of_laod_arduino_2021/AIR TX/GPS'
 * '<S17>'  : 'Copy_of_laod_arduino_2021/AIR TX/Heartbeat'
 * '<S18>'  : 'Copy_of_laod_arduino_2021/AIR TX/IMU & Attidude'
 * '<S19>'  : 'Copy_of_laod_arduino_2021/AIR TX/If_subsystem'
 * '<S20>'  : 'Copy_of_laod_arduino_2021/AIR TX/Servo'
 * '<S21>'  : 'Copy_of_laod_arduino_2021/AIR TX/SystemStatus'
 * '<S22>'  : 'Copy_of_laod_arduino_2021/AIR TX/VFR'
 * '<S23>'  : 'Copy_of_laod_arduino_2021/AIR TX/Waypoints'
 * '<S24>'  : 'Copy_of_laod_arduino_2021/AIR TX/Enable /Chart'
 * '<S25>'  : 'Copy_of_laod_arduino_2021/AIR TX/Enable /Chart/sendbyte'
 * '<S26>'  : 'Copy_of_laod_arduino_2021/AIR TX/GPS/Radians to Degrees'
 * '<S27>'  : 'Copy_of_laod_arduino_2021/AIR TX/GPS/Radians to Degrees1'
 * '<S28>'  : 'Copy_of_laod_arduino_2021/AIR TX/Heartbeat/Alarm set'
 * '<S29>'  : 'Copy_of_laod_arduino_2021/AIR TX/If_subsystem/Subsystem'
 * '<S30>'  : 'Copy_of_laod_arduino_2021/AIR TX/If_subsystem/iflogic_function'
 * '<S31>'  : 'Copy_of_laod_arduino_2021/AIR TX/Servo/Conversione'
 * '<S32>'  : 'Copy_of_laod_arduino_2021/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S33>'  : 'Copy_of_laod_arduino_2021/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S34>'  : 'Copy_of_laod_arduino_2021/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S35>'  : 'Copy_of_laod_arduino_2021/AIR TX/VFR/Radians to Degrees'
 * '<S36>'  : 'Copy_of_laod_arduino_2021/AIR TX/VFR/wrapTo360'
 * '<S37>'  : 'Copy_of_laod_arduino_2021/AIR TX/Waypoints/MATLAB Function'
 * '<S38>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1'
 * '<S39>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
 * '<S40>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1'
 * '<S41>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1'
 * '<S42>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
 * '<S43>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
 * '<S44>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
 * '<S45>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
 * '<S46>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
 * '<S47>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
 * '<S48>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
 * '<S49>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
 * '<S50>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
 * '<S51>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
 * '<S52>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
 * '<S53>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
 * '<S54>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
 * '<S55>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
 * '<S56>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
 * '<S57>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
 * '<S58>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
 * '<S59>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
 * '<S60>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
 * '<S61>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
 * '<S62>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
 * '<S63>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
 * '<S64>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
 * '<S65>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
 * '<S66>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
 * '<S67>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
 * '<S68>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
 * '<S69>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
 * '<S70>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
 * '<S71>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
 * '<S72>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
 * '<S73>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
 * '<S74>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
 * '<S75>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
 * '<S76>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
 * '<S77>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
 * '<S78>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
 * '<S79>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
 * '<S80>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
 * '<S81>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
 * '<S82>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
 * '<S83>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
 * '<S84>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
 * '<S85>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
 * '<S86>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
 * '<S87>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
 * '<S88>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
 * '<S89>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
 * '<S90>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
 * '<S91>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
 * '<S92>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
 * '<S93>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
 * '<S94>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
 * '<S95>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
 * '<S96>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
 * '<S97>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
 * '<S98>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
 * '<S99>'  : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
 * '<S100>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
 * '<S101>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
 * '<S102>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
 * '<S103>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
 * '<S104>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
 * '<S105>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
 * '<S106>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
 * '<S107>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
 * '<S108>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
 * '<S109>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
 * '<S110>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
 * '<S111>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
 * '<S112>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
 * '<S113>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
 * '<S114>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
 * '<S115>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
 * '<S116>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
 * '<S117>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
 * '<S118>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
 * '<S119>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
 * '<S120>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
 * '<S121>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
 * '<S122>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
 * '<S123>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
 * '<S124>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
 * '<S125>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
 * '<S126>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
 * '<S127>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
 * '<S128>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
 * '<S129>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
 * '<S130>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
 * '<S131>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
 * '<S132>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
 * '<S133>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
 * '<S134>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
 * '<S135>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
 * '<S136>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
 * '<S137>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
 * '<S138>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
 * '<S139>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
 * '<S140>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
 * '<S141>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
 * '<S142>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
 * '<S143>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
 * '<S144>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
 * '<S145>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
 * '<S146>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
 * '<S147>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
 * '<S148>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
 * '<S149>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
 * '<S150>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
 * '<S151>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
 * '<S152>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
 * '<S153>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
 * '<S154>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
 * '<S155>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
 * '<S156>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
 * '<S157>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
 * '<S158>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
 * '<S159>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
 * '<S160>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
 * '<S161>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
 * '<S162>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
 * '<S163>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
 * '<S164>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
 * '<S165>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
 * '<S166>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
 * '<S167>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
 * '<S168>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
 * '<S169>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
 * '<S170>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
 * '<S171>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
 * '<S172>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
 * '<S173>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
 * '<S174>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
 * '<S175>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
 * '<S176>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
 * '<S177>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
 * '<S178>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
 * '<S179>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
 * '<S180>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
 * '<S181>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
 * '<S182>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
 * '<S183>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
 * '<S184>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
 * '<S185>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
 * '<S186>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
 * '<S187>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
 * '<S188>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
 * '<S189>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
 * '<S190>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
 * '<S191>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
 * '<S192>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
 * '<S193>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
 * '<S194>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
 * '<S195>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
 * '<S196>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
 * '<S197>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
 * '<S198>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
 * '<S199>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
 * '<S200>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
 * '<S201>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
 * '<S202>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
 * '<S203>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
 * '<S204>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
 * '<S205>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
 * '<S206>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
 * '<S207>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
 * '<S208>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
 * '<S209>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
 * '<S210>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
 * '<S211>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
 * '<S212>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
 * '<S213>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
 * '<S214>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
 * '<S215>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
 * '<S216>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
 * '<S217>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
 * '<S218>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
 * '<S219>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
 * '<S220>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
 * '<S221>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
 * '<S222>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
 * '<S223>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S224>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S225>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S226>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
 * '<S227>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S228>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S229>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
 * '<S230>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
 * '<S231>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S232>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
 * '<S233>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
 * '<S234>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
 * '<S235>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
 * '<S236>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
 * '<S237>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
 * '<S238>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
 * '<S239>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
 * '<S240>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
 * '<S241>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
 * '<S242>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
 * '<S243>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
 * '<S244>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S245>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S246>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S247>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
 * '<S248>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
 * '<S249>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
 * '<S250>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
 * '<S251>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
 * '<S252>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
 * '<S253>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
 * '<S254>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
 * '<S255>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
 * '<S256>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
 * '<S257>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
 * '<S258>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
 * '<S259>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
 * '<S260>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
 * '<S261>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
 * '<S262>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
 * '<S263>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
 * '<S264>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
 * '<S265>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
 * '<S266>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
 * '<S267>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
 * '<S268>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
 * '<S269>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
 * '<S270>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
 * '<S271>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
 * '<S272>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
 * '<S273>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
 * '<S274>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
 * '<S275>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
 * '<S276>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
 * '<S277>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S278>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S279>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S280>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
 * '<S281>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
 * '<S282>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
 * '<S283>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
 * '<S284>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
 * '<S285>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S286>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
 * '<S287>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
 * '<S288>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S289>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
 * '<S290>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
 * '<S291>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
 * '<S292>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
 * '<S293>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
 * '<S294>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
 * '<S295>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
 * '<S296>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
 * '<S297>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
 * '<S298>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S299>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
 * '<S300>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S301>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
 * '<S302>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
 * '<S303>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
 * '<S304>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
 * '<S305>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
 * '<S306>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
 * '<S307>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
 * '<S308>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
 * '<S309>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
 * '<S310>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
 * '<S311>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
 * '<S312>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
 * '<S313>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
 * '<S314>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
 * '<S315>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
 * '<S316>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
 * '<S317>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
 * '<S318>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
 * '<S319>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
 * '<S320>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
 * '<S321>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
 * '<S322>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
 * '<S323>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
 * '<S324>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
 * '<S325>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
 * '<S326>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
 * '<S327>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
 * '<S328>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
 * '<S329>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
 * '<S330>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
 * '<S331>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
 * '<S332>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
 * '<S333>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
 * '<S334>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
 * '<S335>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
 * '<S336>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
 * '<S337>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
 * '<S338>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
 * '<S339>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
 * '<S340>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
 * '<S341>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S342>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
 * '<S343>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
 * '<S344>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S345>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
 * '<S346>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
 * '<S347>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
 * '<S348>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
 * '<S349>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
 * '<S350>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
 * '<S351>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
 * '<S352>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
 * '<S353>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
 * '<S354>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S355>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
 * '<S356>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S357>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
 * '<S358>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
 * '<S359>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
 * '<S360>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
 * '<S361>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
 * '<S362>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
 * '<S363>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
 * '<S364>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
 * '<S365>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
 * '<S366>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
 * '<S367>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
 * '<S368>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
 * '<S369>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
 * '<S370>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
 * '<S371>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
 * '<S372>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
 * '<S373>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
 * '<S374>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
 * '<S375>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
 * '<S376>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
 * '<S377>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
 * '<S378>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
 * '<S379>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
 * '<S380>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
 * '<S381>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
 * '<S382>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
 * '<S383>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
 * '<S384>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
 * '<S385>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
 * '<S386>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
 * '<S387>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
 * '<S388>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
 * '<S389>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
 * '<S390>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
 * '<S391>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S392>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
 * '<S393>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
 * '<S394>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S395>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
 * '<S396>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
 * '<S397>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
 * '<S398>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
 * '<S399>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
 * '<S400>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
 * '<S401>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
 * '<S402>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
 * '<S403>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
 * '<S404>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S405>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
 * '<S406>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S407>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
 * '<S408>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
 * '<S409>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
 * '<S410>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
 * '<S411>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
 * '<S412>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
 * '<S413>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
 * '<S414>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
 * '<S415>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
 * '<S416>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
 * '<S417>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
 * '<S418>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
 * '<S419>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
 * '<S420>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
 * '<S421>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
 * '<S422>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
 * '<S423>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
 * '<S424>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
 * '<S425>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
 * '<S426>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
 * '<S427>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
 * '<S428>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
 * '<S429>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
 * '<S430>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
 * '<S431>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
 * '<S432>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
 * '<S433>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
 * '<S434>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
 * '<S435>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
 * '<S436>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
 * '<S437>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
 * '<S438>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
 * '<S439>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Chart'
 * '<S440>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
 * '<S441>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem'
 * '<S442>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1'
 * '<S443>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem2'
 * '<S444>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem3'
 * '<S445>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
 * '<S446>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
 * '<S447>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
 * '<S448>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
 * '<S449>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
 * '<S450>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
 * '<S451>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
 * '<S452>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
 * '<S453>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
 * '<S454>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
 * '<S455>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
 * '<S456>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
 * '<S457>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
 * '<S458>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
 * '<S459>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
 * '<S460>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
 * '<S461>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
 * '<S462>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
 * '<S463>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
 * '<S464>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
 * '<S465>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
 * '<S466>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
 * '<S467>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
 * '<S468>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
 * '<S469>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
 * '<S470>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
 * '<S471>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
 * '<S472>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
 * '<S473>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
 * '<S474>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
 * '<S475>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
 * '<S476>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
 * '<S477>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
 * '<S478>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
 * '<S479>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
 * '<S480>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
 * '<S481>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
 * '<S482>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
 * '<S483>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
 * '<S484>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
 * '<S485>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
 * '<S486>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
 * '<S487>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
 * '<S488>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
 * '<S489>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
 * '<S490>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
 * '<S491>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
 * '<S492>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
 * '<S493>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
 * '<S494>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
 * '<S495>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
 * '<S496>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
 * '<S497>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
 * '<S498>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
 * '<S499>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
 * '<S500>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
 * '<S501>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
 * '<S502>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
 * '<S503>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
 * '<S504>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
 * '<S505>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S506>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
 * '<S507>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
 * '<S508>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S509>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
 * '<S510>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
 * '<S511>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
 * '<S512>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
 * '<S513>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
 * '<S514>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
 * '<S515>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
 * '<S516>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
 * '<S517>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
 * '<S518>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S519>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
 * '<S520>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S521>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
 * '<S522>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
 * '<S523>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
 * '<S524>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
 * '<S525>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
 * '<S526>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
 * '<S527>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
 * '<S528>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
 * '<S529>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S530>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S531>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S532>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S533>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
 * '<S534>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
 * '<S535>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
 * '<S536>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
 * '<S537>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S538>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
 * '<S539>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
 * '<S540>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
 * '<S541>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
 * '<S542>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
 * '<S543>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
 * '<S544>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
 * '<S545>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
 * '<S546>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
 * '<S547>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
 * '<S548>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
 * '<S549>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
 * '<S550>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
 * '<S551>' : 'Copy_of_laod_arduino_2021/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
 * '<S552>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
 * '<S553>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
 * '<S554>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
 * '<S555>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
 * '<S556>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry'
 * '<S557>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians'
 * '<S558>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians1'
 * '<S559>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Degrees to Radians2'
 * '<S560>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass'
 * '<S561>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees'
 * '<S562>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees1'
 * '<S563>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Radians to Degrees2'
 * '<S564>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1'
 * '<S565>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS'
 * '<S566>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Discrete Varying Lowpass/FOS/MATLAB Function'
 * '<S567>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/MATLAB Function'
 * '<S568>' : 'Copy_of_laod_arduino_2021/MISURE DA SENSORI  FILTRATE/TX & RX Seriale Arduino Raspberry/Subsystem1/Subsystem2'
 * '<S569>' : 'Copy_of_laod_arduino_2021/Misure Sensori/GPS_Venus'
 * '<S570>' : 'Copy_of_laod_arduino_2021/Misure Sensori/GPS_Venus/Subsystem1'
 * '<S571>' : 'Copy_of_laod_arduino_2021/Misure Sensori/GPS_Venus/Subsystem2'
 * '<S572>' : 'Copy_of_laod_arduino_2021/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
 * '<S573>' : 'Copy_of_laod_arduino_2021/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
 * '<S574>' : 'Copy_of_laod_arduino_2021/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
 * '<S575>' : 'Copy_of_laod_arduino_2021/RADIOCOMANDO/AILERON'
 * '<S576>' : 'Copy_of_laod_arduino_2021/RADIOCOMANDO/AILERON1'
 * '<S577>' : 'Copy_of_laod_arduino_2021/RADIOCOMANDO/ELEVATOR'
 * '<S578>' : 'Copy_of_laod_arduino_2021/RADIOCOMANDO/ELEVATOR1'
 * '<S579>' : 'Copy_of_laod_arduino_2021/RADIOCOMANDO/RUDDER'
 * '<S580>' : 'Copy_of_laod_arduino_2021/RADIOCOMANDO/THROTTLE'
 * '<S581>' : 'Copy_of_laod_arduino_2021/Servi/AILERON1'
 * '<S582>' : 'Copy_of_laod_arduino_2021/Servi/RUDDER6'
 * '<S583>' : 'Copy_of_laod_arduino_2021/Servi/THROTTLE1'
 * '<S584>' : 'Copy_of_laod_arduino_2021/Servi/elevator'
 */
#endif                             /* RTW_HEADER_Copy_of_laod_arduino_2021_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
