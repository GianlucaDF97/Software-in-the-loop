//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.h
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.218
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Mon May 22 17:24:23 2023
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Aenea_model_h_
#define RTW_HEADER_Aenea_model_h_
#include <cfloat>
#include <cmath>
#include <cstring>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Aenea_model_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<S409>/Resettable Subsystem'
typedef struct {
  real_T Memory_PreviousInput;         // '<S421>/Memory'
} DW_ResettableSubsystem_Aenea__T;

// Zero-crossing (trigger) state for system '<S409>/Resettable Subsystem'
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_k;// '<S409>/Resettable Subsystem'
} ZCE_ResettableSubsystem_Aenea_T;

// Block states (default storage) for system '<S434>/Resettable Subsystem'
typedef struct {
  real_T Memory_PreviousInput;         // '<S438>/Memory'
} DW_ResettableSubsystem_Aene_d_T;

// Zero-crossing (trigger) state for system '<S434>/Resettable Subsystem'
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE;// '<S434>/Resettable Subsystem'
} ZCE_ResettableSubsystem_Aen_h_T;

// Block signals (default storage)
typedef struct {
  real_T F[324];
  real_T klm_gain[324];
  real_T dv[324];
  real_T H[198];
  real_T klm_gain_m[198];
  real_T ab[198];
  real_T S[121];
  real_T b_A[121];
  real_T DataTypeConversion4[105];     // '<S451>/Data Type Conversion4'
  uint8_T buffer[300];                 // '<S3>/MATLAB Function2'
  BUS_log_t BusConversion_InsertedFor_SFunc;
  real_T y[21];                        // '<S569>/MATLAB Function2'
  real_T x_est[18];
  real_T klm_gain_c[18];
  real_T a[16];
  real_T A[16];
  real_T rtb_TmpSignalConversionAtSFun_k[14];
  uint8_T messaggio[100];              // '<S3>/MATLAB Function4'
  uint8_T messaggio_2[100];            // '<S3>/MATLAB Function4'
  boolean_T x[100];
  real_T residui[11];                  // '<S568>/DEFINITIVA'
  real_T dv1[11];
  real_T UnitDelay[9];                 // '<S584>/Unit Delay'
  real_T DataTypeConversion1_c[9];     // '<S7>/Data Type Conversion1'
  real_T aterra_tmp[9];
  char_T b_data[64];
  char_T sfull[64];
  int32_T ipiv[11];
  real_T x_new[4];
  real_T aterra[3];
  char_T hex_checksum_data[17];
  boolean_T NOT[14];                   // '<S574>/NOT'
  uint16_T WP_info_in[6];
  real_T Lat;                          // '<S583>/S-Function Builder'
  real_T Long;                         // '<S583>/S-Function Builder'
  real_T V;                            // '<S583>/S-Function Builder'
  real_T quota;                        // '<S583>/S-Function Builder'
  real_T heading;                      // '<S583>/S-Function Builder'
  real_T SFunctionBuilder_o6;          // '<S583>/S-Function Builder'
  real_T SFunctionBuilder_o1;          // '<S585>/S-Function Builder'
  real_T SFunctionBuilder_o2;          // '<S585>/S-Function Builder'
  real_T SFunctionBuilder_o3;          // '<S585>/S-Function Builder'
  real_T Switch;                       // '<S594>/Switch'
  real_T T;                            // '<S591>/T'
  real_T In[21];                       // '<S576>/In'
  real_T Lat_K;                        // '<S568>/DEFINITIVA'
  real_T Long_K;                       // '<S568>/DEFINITIVA'
  real_T h_K;                          // '<S568>/DEFINITIVA'
  real_T vd_K;                         // '<S568>/DEFINITIVA'
  real_T v_K;                          // '<S568>/DEFINITIVA'
  real_T imbardata;                    // '<S568>/DEFINITIVA'
  real_T V_goHome;                     // '<S453>/GO_HOME'
  real_T h_goHome;                     // '<S453>/GO_HOME'
  real_T VELOCITA;                     // '<S452>/saturatore V'
  real_T QUOTA;                        // '<S452>/WAYPOINTS'
  real_T Gain;                         // '<S469>/Gain'
  real_T Gain_o;                       // '<S470>/Gain'
  real_T velocita; // '<S451>/Switch di selezione  Task - Waypoint navigation5'
  real_T QUOTA_e;  // '<S451>/Switch di selezione  Task - Waypoint navigation4'
  real_T In_c[2];                      // '<S476>/In'
  real_T Constant1;                    // '<S466>/Constant1'
  real_T Sum2;                         // '<S466>/Sum2'
  real_T maneuver_selector;            // '<S451>/Chart1'
  real_T trig_approach;                // '<S451>/Chart1'
  real_T trig_flare;                   // '<S451>/Chart1'
  real_T approach_selector;            // '<S451>/Chart1'
  real_T h_Home;                       // '<S451>/CALIBRATING_HOME_COORDINATES'
  real_T Multiply;                     // '<S462>/Multiply'
  real_T Constant1_h;                  // '<S462>/Constant1'
  real_T x_f_out;                      // '<S462>/MATLAB Function'
  real_T h_f_out;                      // '<S462>/MATLAB Function'
  real_T k_x_out;                      // '<S462>/MATLAB Function'
  real_T h_c_out;                      // '<S462>/MATLAB Function'
  real_T no_solution;                  // '<S462>/MATLAB Function'
  real_T V_vett;                       // '<S450>/VETTORIALE'
  real_T h_vett;                       // '<S450>/VETTORIALE'
  real_T Fase_ATO;                     // '<S449>/Chart1'
  real_T manetta_ref;                  // '<S449>/Chart1'
  real_T eq_rot;                       // '<S449>/Chart1'
  real_T h_ref;                        // '<S449>/Chart1'
  real_T Tas_ref;                      // '<S449>/Chart1'
  real_T psi_ref_selector;             // '<S449>/Chart1'
  real_T theta_ground_selector;        // '<S449>/Chart1'
  real_T Switch_n;                     // '<S445>/Switch'
  real_T Switch_l;                     // '<S442>/Switch'
  real_T Switch_e;                     // '<S436>/Switch'
  real_T Switch_a;                     // '<S422>/Switch'
  real_T Switch_k;                     // '<S419>/Switch'
  real_T switch_manetta;               // '<S38>/ STATI'
  real_T switch_equilibratore;         // '<S38>/ STATI'
  real_T switch_alettoni;              // '<S38>/ STATI'
  real_T switch_timone;                // '<S38>/ STATI'
  real_T throttle_safe;                // '<S38>/ STATI'
  real_T modo;                         // '<S38>/ STATI'
  real_T OutportBufferForOut1;         // '<S302>/Constant'
  real_T checksum;
  real_T olddi;
  real_T a_b;
  real_T dist;
  real_T dist_fut;
  real_T Sum_l;                        // '<S570>/Sum'
  real_T e_d;                          // '<S37>/Sum2'
  real_T Gain1_i0;                     // '<S565>/Gain1'
  real_T Gain1_f;                      // '<S562>/Gain1'
  real_T Gain1_o;                      // '<S563>/Gain1'
  real_T Gain_h;                       // '<S33>/Gain'
  real_T Sum5;                         // '<S601>/Sum5'
  real_T Sum_fb;                       // '<S350>/Sum'
  real_T Saturation;                   // '<S348>/Saturation'
  real_T SwitchBumpless2;              // '<S303>/Switch Bumpless 2'
  real_T Sum3;                         // '<S598>/Sum3'
  real_T Equilibratore_n;              // '<S37>/Switch Bumpless 1'
  real_T Sum3_k;                       // '<S602>/Sum3'
  real_T e;                            // '<S37>/Sum5'
  real_T Saturation_a;                 // '<S398>/Saturation'
  real_T Sum3_h;                       // '<S596>/Sum3'
  real_T Alettoni;                     // '<S37>/saturatore A'
  real_T Sum4_b;                       // '<S600>/Sum4'
  real_T Product1;                     // '<S570>/Product1'
  real_T Gain_dt;                      // '<S620>/Gain'
  real_T Alt;                          // '<S6>/Switch'
  real_T V_nord;                       // '<S6>/Multiply2'
  real_T V_est;                        // '<S6>/Multiply3'
  real_T Sum2_k2;                      // '<S304>/Sum2'
  real_T Switch_j;                     // '<S545>/Switch'
  real_T Abs1_l;                       // '<S536>/Abs1'
  real_T Sum_h;                        // '<S533>/Sum'
  real_T Gain_hh;                      // '<S474>/Gain'
  real_T Switch1_g;                    // '<S27>/Switch1'
  real_T Ato_selector;
  real_T Al_selector;
  real_T a_fut_tmp;
  real_T Wp_selector;
  real_T Vec_selector;
  real_T Go_home_selector;
  real_T rtb_TmpSignalConversionAtSFun_p;
  real_T b_a_tmp;
  real_T a_tmp_tmp;
  real_T psi_ref_tmp;
  real_T temp;
  real_T smax;
  real_T y_c;
  real_T Y_tmp;
  real_T Y_tmp_f;
  real_T Y_tmp_g;
  real_T Y_tmp_g1;
  real_T Y_tmp_m;
  real_T Y_tmp_n;
  int8_T p[4];
  int8_T ipiv_p[4];
  real32_T SFunctionBuilder_o3_h;      // '<S587>/S-Function Builder'
  real32_T WP_param[7];                // '<S23>/MATLAB Function'
  real32_T Val_out_MAV[16];            // '<S3>/MATLAB Function1'
  real32_T f;
  int32_T SFunctionBuilder_o2_a;       // '<S3>/S-Function Builder'
  int32_T Add;                         // '<S3>/Add'
  int32_T DataTypeConversion_g[4];     // '<S15>/Data Type Conversion'
  uint16_T Memory[8];                  // '<S3>/Memory'
  uint16_T SFunctionBuilder2_o11[8];   // '<S3>/S-Function Builder2'
  uint16_T LVDE[8];                    // '<S21>/Data Type Conversion2'
  int32_T srem;
  int32_T b_k;
  int32_T npad;
  int32_T d_k;
  int32_T idx;
  int32_T soglia_dist;
  int32_T c;
  int32_T ix;
  int32_T c_ix;
  int32_T ijA;
  int32_T i;
  int32_T i_l;
  int32_T j;
  int32_T jBcol;
  uint32_T SFunctionBuilder2_o2;       // '<S3>/S-Function Builder2'
  uint32_T DataTypeConversion3;        // '<S18>/Data Type Conversion3'
  uint32_T DataTypeConversion;         // '<S16>/Data Type Conversion'
  real32_T ByteUnpack_o2[9];           // '<S584>/Byte Unpack'
  real32_T ByteReversal[9];            // '<S584>/Byte Reversal'
  real32_T SFunctionBuilder2_o8;       // '<S3>/S-Function Builder2'
  real32_T SFunctionBuilder2_o10[7];   // '<S3>/S-Function Builder2'
  real32_T SFunctionBuilder2_o13;      // '<S3>/S-Function Builder2'
  real32_T SFunctionBuilder2_o17;      // '<S3>/S-Function Builder2'
  real32_T DataTypeConversion1[6];     // '<S17>/Data Type Conversion1'
  real32_T AGAC[4];                    // '<S22>/Data Type Conversion'
  real32_T DataTypeConversion2;        // '<S1>/Data Type Conversion2'
  real32_T DataTypeConversion1_m;      // '<S1>/Data Type Conversion1'
  real32_T DataTypeConversion_n;       // '<S4>/Data Type Conversion'
  real32_T DataTypeConversion1_e;      // '<S4>/Data Type Conversion1'
  real32_T DataTypeConversion3_p;      // '<S587>/Data Type Conversion3'
  real32_T SFunctionBuilder_o1_g;      // '<S587>/S-Function Builder'
  real32_T SFunctionBuilder_o2_p;      // '<S587>/S-Function Builder'
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunctionBuilder2_o7[2];    // '<S3>/S-Function Builder2'
  uint16_T SFunctionBuilder2_o9[6];    // '<S3>/S-Function Builder2'
  uint16_T DataTypeConversion2_p;      // '<S15>/Data Type Conversion2'
  uint16_T Heading[9];                 // '<S19>/Data Type Conversion1'
  uint16_T Memory_o;                   // '<S4>/Memory'
  uint16_T SFunctionBuilder1_o3;       // '<S4>/S-Function Builder1'
  uint16_T SFunctionBuilder1_o4;       // '<S4>/S-Function Builder1'
  uint16_T WP_info[6];                 // '<S23>/MATLAB Function'
  uint16_T new_mex;                    // '<S3>/MATLAB Function3'
  uint16_T GC_info[3];                 // '<S3>/MATLAB Function1'
  int16_T DataTypeConversion_j[9];     // '<S17>/Data Type Conversion'
  int16_T DataTypeConversion1_j[3];    // '<S15>/Data Type Conversion1'
  int16_T Heading_f;                   // '<S22>/Data Type Conversion1'
  int16_T manual_throttleCmd_pwm;      // '<S9>/S-Function Builder'
  int16_T manual_elevatorCmd_pwm;      // '<S9>/S-Function Builder3'
  int16_T manual_aileronCmd_pwm;       // '<S9>/S-Function Builder1'
  int16_T manual_rudderCmd_pwm;        // '<S9>/S-Function Builder2'
  int16_T DataTypeConversion2_m;       // '<S4>/Data Type Conversion2'
  int16_T SFunctionBuilder4;           // '<S9>/S-Function Builder4'
  int16_T Sum;                         // '<S604>/Sum'
  int16_T elevatorCmd_pwm;             // '<S10>/Data Type Conversion'
  int16_T aileronCmd_pwm;              // '<S10>/Data Type Conversion1'
  int16_T rudderCmd_pwm;               // '<S10>/Data Type Conversion2'
  uint8_T SFunctionBuilder1[41];       // '<S584>/S-Function Builder1'
  uint8_T ByteUnpack_o1[4];            // '<S584>/Byte Unpack'
  uint8_T ByteUnpack_o3;               // '<S584>/Byte Unpack'
  uint8_T SFunctionBuilder_o1_a[100];  // '<S3>/S-Function Builder'
  uint8_T Memory1[2];                  // '<S3>/Memory1'
  uint8_T Memory_h[4];                 // '<S1>/Memory'
  uint8_T Memory3;                     // '<S3>/Memory3'
  uint8_T SFunctionBuilder2_o1[4];     // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o3;        // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o4[2];     // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o5[3];     // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o6;        // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o12;       // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o14;       // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o15;       // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o16;       // '<S3>/S-Function Builder2'
  uint8_T SFunctionBuilder2_o18;       // '<S3>/S-Function Builder2'
  uint8_T DataTypeConversion1_f[4];    // '<S16>/Data Type Conversion1'
  uint8_T SFunctionBuilder1_o1;        // '<S4>/S-Function Builder1'
  uint8_T SFunctionBuilder1_o2[264];   // '<S4>/S-Function Builder1'
  uint8_T SFunctionBuilder;            // '<S4>/S-Function Builder'
  uint8_T Mex_out[41];                 // '<S584>/MATLAB Function1'
  uint8_T iflogic;                     // '<S18>/iflogic_function'
  uint8_T mess_out[100];               // '<S3>/MATLAB Function2'
  boolean_T SFunctionBuilder_o7;       // '<S583>/S-Function Builder'
  boolean_T Compare;                   // '<S581>/Compare'
  boolean_T HitCrossing;               // '<S250>/Hit  Crossing'
  boolean_T Compare_i;                 // '<S606>/Compare'
} B_Aenea_model_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE[9];          // '<S584>/Unit Delay'
  real_T UnitDelay1_DSTATE;            // '<S580>/Unit Delay1'
  real_T UnitDelay_DSTATE_c;           // '<S570>/Unit Delay'
  real_T UnitDelay_DSTATE_h[5];        // '<S583>/Unit Delay'
  real_T Integrator_DSTATE;            // '<S341>/Integrator'
  real_T Integrator_DSTATE_l;          // '<S391>/Integrator'
  real_T DiscreteWashoutFilter_states; // '<S305>/Discrete Washout Filter'
  real_T DelayInput2_DSTATE;           // '<S586>/Delay Input2'
  real_T Delay_DSTATE;                 // '<S249>/Delay'
  real_T Integrator_DSTATE_lq;         // '<S284>/Integrator'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S306>/Discrete-Time Integrator'
  real_T SFunctionBuilder_DSTATE;      // '<S10>/S-Function Builder'
  real_T SFunctionBuilder1_DSTATE;     // '<S10>/S-Function Builder1'
  real_T SFunctionBuilder2_DSTATE;     // '<S10>/S-Function Builder2'
  real_T SFunctionBuilder3_DSTATE;     // '<S10>/S-Function Builder3'
  real_T UnitDelay_DSTATE_n;           // '<S621>/Unit Delay'
  real_T DiscreteTimeIntegrator_DSTATE_j;// '<S462>/Discrete-Time Integrator'
  volatile real_T RateTransition_Buffer0;// '<S27>/Rate Transition'
  real_T Memory1_PreviousInput;        // '<S27>/Memory1'
  real_T Memory_PreviousInput;         // '<S27>/Memory'
  real_T Memory_PreviousInput_e[14];   // '<S574>/Memory'
  real_T Memory_PreviousInput_o[14];   // '<S573>/Memory'
  real_T PrevY;                        // '<S42>/Rate Limiter'
  real_T Memory2_PreviousInput;        // '<S27>/Memory2'
  real_T P_ref;                        // '<S580>/MATLAB Function'
  real_T rl_up;                        // '<S580>/MATLAB Function'
  real_T rl_dw;                        // '<S580>/MATLAB Function'
  real_T x_prd[18];                    // '<S568>/DEFINITIVA'
  real_T p_prd[324];                   // '<S568>/DEFINITIVA'
  real_T flag;                         // '<S453>/GO_HOME'
  real_T Memory4_PreviousInput;        // '<S452>/Memory4'
  real_T flag_o;                       // '<S452>/WAYPOINTS'
  real_T lat1;                         // '<S452>/WAYPOINTS'
  real_T long1;                        // '<S452>/WAYPOINTS'
  real_T Memory7_PreviousInput;        // '<S451>/Memory7'
  real_T Memory5_PreviousInput;        // '<S451>/Memory5'
  real_T Memory1_PreviousInput_f;      // '<S451>/Memory1'
  real_T Memory2_PreviousInput_e;      // '<S451>/Memory2'
  real_T x[4];                         // '<S462>/MATLAB Function'
  real_T cycle_count;                  // '<S462>/MATLAB Function'
  real_T eps[4];                       // '<S462>/MATLAB Function'
  real_T flag_k;                       // '<S451>/ALLINEAMENTO'
  real_T Memory3_PreviousInput;        // '<S450>/Memory3'
  real_T V_ref;                        // '<S450>/VETTORIALE'
  real_T ALT_ref;                      // '<S450>/VETTORIALE'
  real_T Memory_PreviousInput_p;       // '<S449>/Memory'
  real_T Memory1_PreviousInput_e;      // '<S449>/Memory1'
  real_T alarm;                        // '<S416>/MATLAB Function1'
  real_T mess_len;                     // '<S3>/MATLAB Function4'
  real_T test1;                        // '<S3>/MATLAB Function1'
  real32_T riferimenti[16];            // '<S3>/MATLAB Function1'
  real32_T WP_dbP[105];                // '<S3>/MATLAB Function1'
  real32_T WP_dbP_AL[105];             // '<S3>/MATLAB Function1'
  int_T HitCrossing_MODE;              // '<S250>/Hit  Crossing'
  uint16_T Memory_PreviousInput_i[8];  // '<S3>/Memory'
  uint16_T Memory_PreviousInput_e4;    // '<S4>/Memory'
  uint16_T counter;                    // '<S3>/MATLAB Function3'
  uint16_T WP_dbI[90];                 // '<S3>/MATLAB Function1'
  uint8_T UnitDelay1_DSTATE_b[41];     // '<S584>/Unit Delay1'
  uint8_T Output_DSTATE;               // '<S582>/Output'
  uint8_T Output_DSTATE_k;             // '<S607>/Output'
  int8_T Integrator_PrevResetState;    // '<S391>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S306>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_o;// '<S462>/Discrete-Time Integrator'
  uint8_T Memory4_PreviousInput_j[300];// '<S3>/Memory4'
  uint8_T Memory5_PreviousInput_b[100];// '<S3>/Memory5'
  uint8_T Memory1_PreviousInput_b[2];  // '<S3>/Memory1'
  uint8_T Memory_PreviousInput_a[4];   // '<S1>/Memory'
  uint8_T Memory3_PreviousInput_g;     // '<S3>/Memory3'
  uint8_T Memory2_PreviousInput_d[9];  // '<S3>/Memory2'
  uint8_T is_active_c10_Aenea_model;   // '<S451>/Chart1'
  uint8_T is_c10_Aenea_model;          // '<S451>/Chart1'
  uint8_T Memory1_PreviousInput_k;     // '<S450>/Memory1'
  uint8_T Memory2_PreviousInput_d2;    // '<S450>/Memory2'
  uint8_T Memory6_PreviousInput;       // '<S450>/Memory6'
  uint8_T is_active_c1_Aenea_model;    // '<S449>/Chart1'
  uint8_T is_c1_Aenea_model;           // '<S449>/Chart1'
  uint8_T temporalCounter_i1;          // '<S449>/Chart1'
  uint8_T is_active_c21_Aenea_model;   // '<S39>/Chart'
  uint8_T is_c21_Aenea_model;          // '<S39>/Chart'
  uint8_T is_active_c26_Aenea_model;   // '<S38>/ STATI'
  uint8_T is_c26_Aenea_model;          // '<S38>/ STATI'
  uint8_T is_AUTOMATICA;               // '<S38>/ STATI'
  uint8_T message[100];                // '<S3>/MATLAB Function4'
  uint8_T counter_f;                   // '<S3>/MATLAB Function4'
  boolean_T Memory_PreviousInput_n;    // '<S38>/Memory'
  boolean_T x_prd_not_empty;           // '<S568>/DEFINITIVA'
  boolean_T x_not_empty;               // '<S462>/MATLAB Function'
  boolean_T x_new_not_empty;           // '<S462>/MATLAB Function'
  boolean_T cycle_count_not_empty;     // '<S462>/MATLAB Function'
  boolean_T eps_not_empty;             // '<S462>/MATLAB Function'
  boolean_T Tf_not_empty;              // '<S411>/MATLAB Function1'
  boolean_T Interr_parz;               // '<S3>/MATLAB Function4'
  boolean_T WP_dbP_not_empty;          // '<S3>/MATLAB Function1'
  boolean_T WP_dbP_AL_not_empty;       // '<S3>/MATLAB Function1'
  boolean_T Enabled_MODE;              // '<S440>/Enabled '
  boolean_T Enabled_MODE_j;            // '<S439>/Enabled '
  boolean_T Enabled_MODE_c;            // '<S434>/Enabled '
  boolean_T Enabled_MODE_i;            // '<S426>/Enabled '
  boolean_T Enabled_MODE_b;            // '<S425>/Enabled '
  DW_ResettableSubsystem_Aene_d_T ResettableSubsystem_p0;// '<S440>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aene_d_T ResettableSubsystem_h;// '<S439>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aene_d_T ResettableSubsystem_p;// '<S434>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem_j;// '<S410>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem;// '<S409>/Resettable Subsystem' 
} DW_Aenea_model_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    // '<S250>/Hit  Crossing'
  ZCSigState SampleandHold_Trig_ZCE;   // '<S569>/Sample and Hold'
  ZCSigState SampleandHold_Trig_ZCE_l; // '<S451>/Sample and Hold'
  ZCSigState SampleandHold1_Trig_ZCE;  // '<S449>/Sample and Hold1'
  ZCSigState SampleandHold_Trig_ZCE_a; // '<S449>/Sample and Hold'
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_p0;// '<S440>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_h;// '<S439>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_p;// '<S434>/Resettable Subsystem' 
  ZCSigState ResettableSubsystem_Reset_ZCE_b;// '<S426>/Resettable Subsystem'
  ZCSigState ResettableSubsystem_Reset_ZCE_l;// '<S425>/Resettable Subsystem'
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem_j;// '<S410>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem;// '<S409>/Resettable Subsystem' 
  ZCSigState EnabledSubsystem_Trig_ZCE;// '<S250>/Enabled Subsystem'
} PrevZCX_Aenea_model_T;

// Invariant block signals (default storage)
typedef const struct tag_ConstB_Aenea_model_T {
  real_T USCITAPERCENTUALE;            // '<S22>/USCITA PERCENTUALE'
  real_T Sum3;                         // '<S601>/Sum3'
  real_T Sum1;                         // '<S598>/Sum1'
  real_T Sum1_i;                       // '<S599>/Sum1'
  real_T Sum1_o;                       // '<S596>/Sum1'
  real_T Sum1_ie;                      // '<S597>/Sum1'
  real_T Sum2;                         // '<S600>/Sum2'
  real_T Sum1_j;                       // '<S604>/Sum1'
  real_T Sum2_d;                       // '<S605>/Sum2'
  real_T Sum2_a;                       // '<S602>/Sum2'
  real_T Sum2_g;                       // '<S603>/Sum2'
  uint16_T Gain;                       // '<S21>/Gain'
  uint16_T Throttle;                   // '<S22>/Data Type Conversion2'
  int16_T K_imb_inv;                   // '<S8>/Gain3'
  int16_T Gain2;                       // '<S21>/Gain2'
  int16_T Gain1;                       // '<S21>/Gain1'
  int8_T B_Remaining;                  // '<S21>/Data Type Conversion3'
} ConstB_Aenea_model_T;

// Constant parameters (default storage)
typedef struct {
  // Expression: R1B
  //  Referenced by: '<S6>/Constant13'

  real_T Constant13_Value[11];

  // Expression: Q1B
  //  Referenced by: '<S6>/Constant16'

  real_T Constant16_Value[18];

  // Computed Parameter: onboard_control_sensor_presentu
  //  Referenced by: '<S21>/onboard_control_sensor_present uint32'

  uint32_T onboard_control_sensor_presentu[3];

  // Computed Parameter: SIUAVuint8_Value
  //  Referenced by: '<S1>/SI UAV uint8'

  uint8_T SIUAVuint8_Value;
} ConstP_Aenea_model_T;

// Real-time Model Data Structure
struct tag_RTM_Aenea_model_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_Aenea_model_T Aenea_model_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_Aenea_model_T Aenea_model_DW;

// Zero-crossing (trigger) state
extern PrevZCX_Aenea_model_T Aenea_model_PrevZCX;

// External data declarations for dependent source files
extern const uint16_T Aenea_model_U16GND;// uint16_T ground
extern const ConstB_Aenea_model_T Aenea_model_ConstB;// constant block i/o

// Constant parameters (default storage)
extern const ConstP_Aenea_model_T Aenea_model_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Aenea_model_initialize(void);
  extern void Aenea_model_step(void);
  extern void Aenea_model_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Aenea_model_T *const Aenea_model_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S40>/Abs' : Unused code path elimination
//  Block '<S40>/Constant' : Unused code path elimination
//  Block '<S40>/Constant1' : Unused code path elimination
//  Block '<S43>/Constant1' : Unused code path elimination
//  Block '<S43>/Constant10' : Unused code path elimination
//  Block '<S43>/Constant11' : Unused code path elimination
//  Block '<S43>/Constant12' : Unused code path elimination
//  Block '<S43>/Constant13' : Unused code path elimination
//  Block '<S43>/Constant14' : Unused code path elimination
//  Block '<S43>/Constant15' : Unused code path elimination
//  Block '<S43>/Constant2' : Unused code path elimination
//  Block '<S43>/Constant3' : Unused code path elimination
//  Block '<S43>/Constant5' : Unused code path elimination
//  Block '<S43>/Constant7' : Unused code path elimination
//  Block '<S43>/Constant9' : Unused code path elimination
//  Block '<S43>/Multiport Switch' : Unused code path elimination
//  Block '<S43>/Multiport Switch1' : Unused code path elimination
//  Block '<S43>/Multiport Switch2' : Unused code path elimination
//  Block '<S73>/DProd Out' : Unused code path elimination
//  Block '<S74>/Filter' : Unused code path elimination
//  Block '<S74>/SumD' : Unused code path elimination
//  Block '<S76>/IProd Out' : Unused code path elimination
//  Block '<S79>/Integrator' : Unused code path elimination
//  Block '<S82>/NProd Out' : Unused code path elimination
//  Block '<S84>/PProd Out' : Unused code path elimination
//  Block '<S88>/Sum' : Unused code path elimination
//  Block '<S90>/Kt' : Unused code path elimination
//  Block '<S90>/SumI3' : Unused code path elimination
//  Block '<S91>/SumI1' : Unused code path elimination
//  Block '<S121>/DProd Out' : Unused code path elimination
//  Block '<S122>/Filter' : Unused code path elimination
//  Block '<S122>/SumD' : Unused code path elimination
//  Block '<S124>/IProd Out' : Unused code path elimination
//  Block '<S127>/Integrator' : Unused code path elimination
//  Block '<S130>/NProd Out' : Unused code path elimination
//  Block '<S132>/PProd Out' : Unused code path elimination
//  Block '<S136>/Sum' : Unused code path elimination
//  Block '<S138>/Kt' : Unused code path elimination
//  Block '<S138>/SumI3' : Unused code path elimination
//  Block '<S139>/SumI1' : Unused code path elimination
//  Block '<S172>/IProd Out' : Unused code path elimination
//  Block '<S175>/Integrator' : Unused code path elimination
//  Block '<S180>/PProd Out' : Unused code path elimination
//  Block '<S184>/Sum' : Unused code path elimination
//  Block '<S186>/Kt' : Unused code path elimination
//  Block '<S186>/SumI3' : Unused code path elimination
//  Block '<S187>/SumI1' : Unused code path elimination
//  Block '<S43>/Saturation' : Unused code path elimination
//  Block '<S43>/Sum1' : Unused code path elimination
//  Block '<S43>/Sum2' : Unused code path elimination
//  Block '<S43>/Sum4' : Unused code path elimination
//  Block '<S43>/Switch auto-manual' : Unused code path elimination
//  Block '<S43>/Switch maneuver' : Unused code path elimination
//  Block '<S43>/Switch rc saturata' : Unused code path elimination
//  Block '<S43>/n-D Lookup Table' : Unused code path elimination
//  Block '<S40>/Kp' : Unused code path elimination
//  Block '<S44>/Constant' : Unused code path elimination
//  Block '<S44>/Lookup Table2' : Unused code path elimination
//  Block '<S192>/Data Type Duplicate' : Unused code path elimination
//  Block '<S192>/Data Type Propagation' : Unused code path elimination
//  Block '<S192>/LowerRelop1' : Unused code path elimination
//  Block '<S192>/Switch' : Unused code path elimination
//  Block '<S192>/Switch2' : Unused code path elimination
//  Block '<S192>/UpperRelop' : Unused code path elimination
//  Block '<S40>/Sum1' : Unused code path elimination
//  Block '<S40>/Switch' : Unused code path elimination
//  Block '<S40>/Switch HOLD//SELECT' : Unused code path elimination
//  Block '<S193>/Constant3' : Unused code path elimination
//  Block '<S193>/Constant4' : Unused code path elimination
//  Block '<S193>/Multiport Switch2' : Unused code path elimination
//  Block '<S193>/Multiport Switch3' : Unused code path elimination
//  Block '<S193>/Switch3' : Unused code path elimination
//  Block '<S193>/Switch4' : Unused code path elimination
//  Block '<S41>/Constant' : Unused code path elimination
//  Block '<S41>/Constant2' : Unused code path elimination
//  Block '<S220>/AND3' : Unused code path elimination
//  Block '<S220>/Constant1' : Unused code path elimination
//  Block '<S220>/DataTypeConv1' : Unused code path elimination
//  Block '<S220>/DataTypeConv2' : Unused code path elimination
//  Block '<S222>/DeadZone' : Unused code path elimination
//  Block '<S220>/Equal1' : Unused code path elimination
//  Block '<S220>/NotEqual' : Unused code path elimination
//  Block '<S220>/SignPreIntegrator' : Unused code path elimination
//  Block '<S220>/SignPreSat' : Unused code path elimination
//  Block '<S220>/Switch' : Unused code path elimination
//  Block '<S220>/ZeroGain' : Unused code path elimination
//  Block '<S223>/DProd Out' : Unused code path elimination
//  Block '<S224>/Filter' : Unused code path elimination
//  Block '<S224>/SumD' : Unused code path elimination
//  Block '<S226>/IProd Out' : Unused code path elimination
//  Block '<S229>/Integrator' : Unused code path elimination
//  Block '<S232>/NProd Out' : Unused code path elimination
//  Block '<S234>/PProd Out' : Unused code path elimination
//  Block '<S236>/Saturation' : Unused code path elimination
//  Block '<S238>/Sum' : Unused code path elimination
//  Block '<S240>/Kt' : Unused code path elimination
//  Block '<S240>/SumI3' : Unused code path elimination
//  Block '<S241>/SumI1' : Unused code path elimination
//  Block '<S41>/Switch' : Unused code path elimination
//  Block '<S41>/Switch auto-manual' : Unused code path elimination
//  Block '<S195>/Constant' : Unused code path elimination
//  Block '<S195>/Constant1' : Unused code path elimination
//  Block '<S195>/Constant2' : Unused code path elimination
//  Block '<S246>/Gain1' : Unused code path elimination
//  Block '<S195>/Math Function' : Unused code path elimination
//  Block '<S247>/Gain' : Unused code path elimination
//  Block '<S195>/Sum' : Unused code path elimination
//  Block '<S195>/Sum1' : Unused code path elimination
//  Block '<S195>/Sum2' : Unused code path elimination
//  Block '<S195>/Switch' : Unused code path elimination
//  Block '<S195>/Switch1' : Unused code path elimination
//  Block '<S36>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
//  Block '<S36>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
//  Block '<S37>/Gain3' : Unused code path elimination
//  Block '<S37>/Switch Bumpless 7' : Unused code path elimination
//  Block '<S409>/Display' : Unused code path elimination
//  Block '<S409>/Display1' : Unused code path elimination
//  Block '<S428>/Constant' : Unused code path elimination
//  Block '<S428>/Constant1' : Unused code path elimination
//  Block '<S428>/Switch' : Unused code path elimination
//  Block '<S430>/Constant4' : Unused code path elimination
//  Block '<S430>/Memory' : Unused code path elimination
//  Block '<S430>/Sum' : Unused code path elimination
//  Block '<S431>/Constant' : Unused code path elimination
//  Block '<S431>/Constant1' : Unused code path elimination
//  Block '<S431>/Switch' : Unused code path elimination
//  Block '<S433>/Constant4' : Unused code path elimination
//  Block '<S433>/Memory' : Unused code path elimination
//  Block '<S433>/Sum' : Unused code path elimination
//  Block '<S411>/Switch' : Unused code path elimination
//  Block '<S38>/Scope1' : Unused code path elimination
//  Block '<S417>/Abs2' : Unused code path elimination
//  Block '<S462>/Multiply1' : Unused code path elimination
//  Block '<S451>/Constant1' : Unused code path elimination
//  Block '<S451>/Constant7' : Unused code path elimination
//  Block '<S466>/Exp1' : Unused code path elimination
//  Block '<S466>/Gain1' : Unused code path elimination
//  Block '<S466>/Gain2' : Unused code path elimination
//  Block '<S466>/Multiply2' : Unused code path elimination
//  Block '<S466>/Multiply3' : Unused code path elimination
//  Block '<S466>/Multiply4' : Unused code path elimination
//  Block '<S466>/Sum3' : Unused code path elimination
//  Block '<S466>/Sum4' : Unused code path elimination
//  Block '<S467>/Gain1' : Unused code path elimination
//  Block '<S512>/IProd Out' : Unused code path elimination
//  Block '<S515>/Integrator' : Unused code path elimination
//  Block '<S520>/PProd Out' : Unused code path elimination
//  Block '<S524>/Sum' : Unused code path elimination
//  Block '<S483>/Gain' : Unused code path elimination
//  Block '<S467>/Sum3' : Unused code path elimination
//  Block '<S467>/psi ref gain' : Unused code path elimination
//  Block '<S467>/psi ref gain1' : Unused code path elimination
//  Block '<S535>/Sum3' : Unused code path elimination
//  Block '<S535>/x*sin' : Unused code path elimination
//  Block '<S535>/y*cos' : Unused code path elimination
//  Block '<S451>/Relational Operator' : Unused code path elimination
//  Block '<S451>/Switch' : Unused code path elimination
//  Block '<S451>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
//  Block '<S451>/Switch1' : Unused code path elimination
//  Block '<S452>/saturatore V1' : Unused code path elimination
//  Block '<S39>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
//  Block '<S39>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
//  Block '<S6>/Constant2' : Unused code path elimination
//  Block '<S569>/Memory' : Unused code path elimination
//  Block '<S586>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S590>/Data Type Duplicate' : Unused code path elimination
//  Block '<S590>/Data Type Propagation' : Unused code path elimination
//  Block '<S7>/Constant9' : Unused code path elimination
//  Block '<S582>/Data Type Propagation' : Unused code path elimination
//  Block '<S592>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S593>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S8>/K AntiWindup-Bumpless AP quota' : Unused code path elimination
//  Block '<S8>/K AntiWindup-Bumpless controllore beccheggio' : Unused code path elimination
//  Block '<S8>/K AntiWindup-Bumpless controllore imbardata' : Unused code path elimination
//  Block '<S8>/K AntiWindup-Bumpless controllore rollio' : Unused code path elimination
//  Block '<S8>/Ki AP quota Select' : Unused code path elimination
//  Block '<S8>/Ki AP rotta1' : Unused code path elimination
//  Block '<S8>/Kp AP quota Select' : Unused code path elimination
//  Block '<S8>/Kp AP rotta' : Unused code path elimination
//  Block '<S8>/Saturation' : Unused code path elimination
//  Block '<S8>/n-D Lookup Table' : Unused code path elimination
//  Block '<S9>/Constant' : Unused code path elimination
//  Block '<S9>/Constant1' : Unused code path elimination
//  Block '<S9>/Switch' : Unused code path elimination
//  Block '<S607>/Data Type Propagation' : Unused code path elimination
//  Block '<S617>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S618>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S295>/Kt' : Eliminated nontunable gain of 1
//  Block '<S334>/Kb' : Eliminated nontunable gain of 1
//  Block '<S352>/Kt' : Eliminated nontunable gain of 1
//  Block '<S402>/Kt' : Eliminated nontunable gain of 1
//  Block '<S37>/Gain' : Eliminated nontunable gain of 1
//  Block '<S37>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S580>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S580>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S7>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S7>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S7>/Manual Switch3' : Eliminated due to constant selection input
//  Block '<S9>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion18' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion19' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion20' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion21' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S9>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S9>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S9>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S9>/Manual Switch3' : Eliminated due to constant selection input
//  Block '<S10>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S10>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S616>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S7>/Constant1' : Unused code path elimination
//  Block '<S7>/Constant2' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Aenea_model'
//  '<S1>'   : 'Aenea_model/AUTOPILOT_MODEL'
//  '<S2>'   : 'Aenea_model/LOG_DATA_MODEL'
//  '<S3>'   : 'Aenea_model/AUTOPILOT_MODEL/AIR RX'
//  '<S4>'   : 'Aenea_model/AUTOPILOT_MODEL/AIR TX'
//  '<S5>'   : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA'
//  '<S6>'   : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE'
//  '<S7>'   : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori'
//  '<S8>'   : 'Aenea_model/AUTOPILOT_MODEL/PARAMETRI SISTEMA DI CONTROLLO'
//  '<S9>'   : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO'
//  '<S10>'  : 'Aenea_model/AUTOPILOT_MODEL/Servi'
//  '<S11>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR RX/MATLAB Function1'
//  '<S12>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR RX/MATLAB Function2'
//  '<S13>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR RX/MATLAB Function3'
//  '<S14>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR RX/MATLAB Function4'
//  '<S15>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/GPS'
//  '<S16>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Heartbeat'
//  '<S17>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/IMU & Attidude'
//  '<S18>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/If_subsystem'
//  '<S19>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Servo'
//  '<S20>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Subsystem'
//  '<S21>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/SystemStatus'
//  '<S22>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/VFR'
//  '<S23>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Waypoints'
//  '<S24>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/GPS/Radians to Degrees'
//  '<S25>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/GPS/Radians to Degrees2'
//  '<S26>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Heartbeat/Alarm set'
//  '<S27>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/If_subsystem/Subsystem'
//  '<S28>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/If_subsystem/iflogic_function'
//  '<S29>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Servo/Conversione'
//  '<S30>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Servo/Conversione/Radians to Degrees1'
//  '<S31>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Servo/Conversione/Radians to Degrees2'
//  '<S32>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Servo/Conversione/Radians to Degrees3'
//  '<S33>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/VFR/Radians to Degrees'
//  '<S34>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/VFR/wrapTo360'
//  '<S35>'  : 'Aenea_model/AUTOPILOT_MODEL/AIR TX/Waypoints/MATLAB Function'
//  '<S36>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1'
//  '<S37>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
//  '<S38>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1'
//  '<S39>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1'
//  '<S40>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
//  '<S41>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
//  '<S42>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
//  '<S43>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
//  '<S44>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
//  '<S45>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
//  '<S46>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
//  '<S47>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
//  '<S48>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
//  '<S49>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
//  '<S50>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
//  '<S51>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
//  '<S52>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
//  '<S53>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
//  '<S54>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
//  '<S55>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
//  '<S56>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
//  '<S57>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
//  '<S58>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
//  '<S59>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
//  '<S60>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
//  '<S61>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
//  '<S62>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
//  '<S63>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
//  '<S64>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
//  '<S65>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
//  '<S66>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
//  '<S67>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
//  '<S68>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
//  '<S69>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
//  '<S70>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
//  '<S71>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
//  '<S72>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
//  '<S73>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
//  '<S74>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
//  '<S75>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
//  '<S76>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
//  '<S77>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
//  '<S78>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
//  '<S79>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
//  '<S80>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
//  '<S81>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
//  '<S82>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
//  '<S83>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
//  '<S84>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
//  '<S85>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
//  '<S86>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
//  '<S87>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
//  '<S88>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
//  '<S89>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
//  '<S90>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
//  '<S91>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
//  '<S92>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
//  '<S93>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
//  '<S94>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
//  '<S95>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
//  '<S96>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
//  '<S97>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
//  '<S98>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
//  '<S99>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
//  '<S100>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
//  '<S101>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
//  '<S102>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
//  '<S103>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
//  '<S104>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
//  '<S105>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
//  '<S106>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
//  '<S107>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
//  '<S108>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
//  '<S109>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
//  '<S110>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
//  '<S111>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
//  '<S112>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
//  '<S113>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
//  '<S114>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
//  '<S115>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
//  '<S116>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
//  '<S117>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
//  '<S118>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
//  '<S119>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
//  '<S120>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
//  '<S121>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
//  '<S122>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
//  '<S123>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
//  '<S124>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
//  '<S125>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
//  '<S126>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
//  '<S127>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
//  '<S128>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
//  '<S129>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
//  '<S130>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
//  '<S131>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
//  '<S132>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
//  '<S133>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
//  '<S134>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
//  '<S135>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
//  '<S136>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
//  '<S137>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
//  '<S138>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
//  '<S139>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
//  '<S140>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
//  '<S141>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
//  '<S142>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
//  '<S143>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
//  '<S144>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
//  '<S145>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
//  '<S146>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
//  '<S147>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
//  '<S148>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
//  '<S149>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
//  '<S150>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
//  '<S151>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
//  '<S152>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
//  '<S153>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
//  '<S154>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
//  '<S155>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
//  '<S156>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
//  '<S157>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
//  '<S158>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
//  '<S159>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
//  '<S160>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
//  '<S161>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
//  '<S162>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
//  '<S163>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
//  '<S164>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
//  '<S165>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
//  '<S166>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
//  '<S167>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
//  '<S168>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
//  '<S169>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
//  '<S170>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
//  '<S171>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
//  '<S172>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
//  '<S173>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
//  '<S174>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
//  '<S175>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
//  '<S176>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
//  '<S177>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
//  '<S178>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
//  '<S179>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
//  '<S180>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
//  '<S181>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
//  '<S182>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
//  '<S183>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
//  '<S184>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
//  '<S185>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
//  '<S186>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
//  '<S187>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
//  '<S188>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
//  '<S189>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
//  '<S190>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
//  '<S191>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
//  '<S192>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
//  '<S193>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
//  '<S194>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
//  '<S195>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
//  '<S196>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
//  '<S197>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
//  '<S198>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
//  '<S199>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
//  '<S200>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
//  '<S201>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
//  '<S202>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
//  '<S203>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
//  '<S204>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
//  '<S205>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
//  '<S206>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
//  '<S207>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
//  '<S208>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
//  '<S209>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
//  '<S210>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
//  '<S211>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
//  '<S212>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
//  '<S213>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
//  '<S214>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
//  '<S215>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
//  '<S216>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
//  '<S217>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
//  '<S218>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
//  '<S219>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
//  '<S220>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S221>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S222>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S223>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
//  '<S224>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S225>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S226>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
//  '<S227>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
//  '<S228>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S229>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
//  '<S230>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
//  '<S231>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
//  '<S232>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
//  '<S233>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
//  '<S234>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
//  '<S235>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
//  '<S236>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
//  '<S237>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
//  '<S238>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
//  '<S239>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
//  '<S240>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
//  '<S241>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
//  '<S242>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
//  '<S243>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S244>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
//  '<S245>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
//  '<S246>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
//  '<S247>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
//  '<S248>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
//  '<S249>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch'
//  '<S250>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
//  '<S251>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
//  '<S252>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
//  '<S253>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
//  '<S254>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
//  '<S255>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
//  '<S256>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
//  '<S257>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
//  '<S258>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
//  '<S259>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
//  '<S260>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
//  '<S261>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
//  '<S262>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
//  '<S263>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
//  '<S264>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
//  '<S265>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
//  '<S266>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
//  '<S267>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
//  '<S268>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
//  '<S269>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
//  '<S270>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
//  '<S271>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
//  '<S272>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
//  '<S273>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
//  '<S274>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
//  '<S275>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S276>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S277>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S278>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
//  '<S279>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
//  '<S280>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
//  '<S281>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
//  '<S282>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
//  '<S283>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S284>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
//  '<S285>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
//  '<S286>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S287>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
//  '<S288>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
//  '<S289>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
//  '<S290>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
//  '<S291>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
//  '<S292>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
//  '<S293>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
//  '<S294>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
//  '<S295>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
//  '<S296>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S297>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
//  '<S298>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S299>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
//  '<S300>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
//  '<S301>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch/Smooth Bypass'
//  '<S302>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
//  '<S303>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
//  '<S304>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
//  '<S305>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
//  '<S306>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
//  '<S307>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
//  '<S308>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
//  '<S309>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
//  '<S310>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
//  '<S311>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
//  '<S312>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
//  '<S313>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
//  '<S314>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
//  '<S315>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
//  '<S316>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
//  '<S317>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
//  '<S318>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
//  '<S319>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
//  '<S320>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
//  '<S321>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
//  '<S322>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
//  '<S323>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
//  '<S324>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
//  '<S325>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
//  '<S326>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
//  '<S327>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
//  '<S328>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
//  '<S329>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
//  '<S330>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
//  '<S331>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
//  '<S332>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
//  '<S333>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
//  '<S334>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
//  '<S335>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
//  '<S336>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
//  '<S337>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
//  '<S338>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
//  '<S339>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S340>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S341>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
//  '<S342>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
//  '<S343>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S344>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
//  '<S345>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
//  '<S346>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
//  '<S347>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
//  '<S348>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
//  '<S349>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S350>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
//  '<S351>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
//  '<S352>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
//  '<S353>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S354>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
//  '<S355>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S356>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
//  '<S357>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
//  '<S358>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
//  '<S359>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
//  '<S360>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
//  '<S361>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
//  '<S362>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
//  '<S363>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
//  '<S364>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
//  '<S365>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
//  '<S366>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
//  '<S367>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
//  '<S368>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
//  '<S369>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
//  '<S370>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
//  '<S371>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
//  '<S372>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
//  '<S373>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
//  '<S374>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
//  '<S375>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
//  '<S376>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
//  '<S377>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
//  '<S378>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
//  '<S379>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
//  '<S380>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
//  '<S381>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
//  '<S382>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
//  '<S383>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
//  '<S384>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
//  '<S385>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
//  '<S386>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
//  '<S387>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
//  '<S388>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
//  '<S389>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
//  '<S390>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S391>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
//  '<S392>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
//  '<S393>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S394>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
//  '<S395>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
//  '<S396>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
//  '<S397>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
//  '<S398>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
//  '<S399>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
//  '<S400>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
//  '<S401>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
//  '<S402>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
//  '<S403>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S404>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
//  '<S405>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S406>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
//  '<S407>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
//  '<S408>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
//  '<S409>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
//  '<S410>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
//  '<S411>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
//  '<S412>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
//  '<S413>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
//  '<S414>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
//  '<S415>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
//  '<S416>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
//  '<S417>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
//  '<S418>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1'
//  '<S419>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
//  '<S420>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
//  '<S421>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
//  '<S422>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
//  '<S423>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
//  '<S424>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
//  '<S425>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
//  '<S426>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
//  '<S427>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
//  '<S428>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
//  '<S429>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
//  '<S430>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
//  '<S431>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
//  '<S432>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
//  '<S433>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
//  '<S434>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
//  '<S435>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
//  '<S436>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
//  '<S437>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
//  '<S438>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
//  '<S439>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec'
//  '<S440>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec'
//  '<S441>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/MATLAB Function1'
//  '<S442>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec/Enabled '
//  '<S443>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec/Resettable Subsystem'
//  '<S444>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
//  '<S445>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec/Enabled '
//  '<S446>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec/Resettable Subsystem'
//  '<S447>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
//  '<S448>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Chart'
//  '<S449>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
//  '<S450>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem'
//  '<S451>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1'
//  '<S452>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2'
//  '<S453>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3'
//  '<S454>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
//  '<S455>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
//  '<S456>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
//  '<S457>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
//  '<S458>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
//  '<S459>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
//  '<S460>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
//  '<S461>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
//  '<S462>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
//  '<S463>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
//  '<S464>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
//  '<S465>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
//  '<S466>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
//  '<S467>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
//  '<S468>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
//  '<S469>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
//  '<S470>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
//  '<S471>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
//  '<S472>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
//  '<S473>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
//  '<S474>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
//  '<S475>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
//  '<S476>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
//  '<S477>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
//  '<S478>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
//  '<S479>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
//  '<S480>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
//  '<S481>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
//  '<S482>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
//  '<S483>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
//  '<S484>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
//  '<S485>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
//  '<S486>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
//  '<S487>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
//  '<S488>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
//  '<S489>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
//  '<S490>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
//  '<S491>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
//  '<S492>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
//  '<S493>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
//  '<S494>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
//  '<S495>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
//  '<S496>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
//  '<S497>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
//  '<S498>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
//  '<S499>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
//  '<S500>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
//  '<S501>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
//  '<S502>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
//  '<S503>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
//  '<S504>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
//  '<S505>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
//  '<S506>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
//  '<S507>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
//  '<S508>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
//  '<S509>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
//  '<S510>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
//  '<S511>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
//  '<S512>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
//  '<S513>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
//  '<S514>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S515>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
//  '<S516>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
//  '<S517>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S518>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
//  '<S519>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
//  '<S520>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
//  '<S521>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
//  '<S522>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
//  '<S523>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
//  '<S524>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
//  '<S525>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
//  '<S526>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
//  '<S527>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S528>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
//  '<S529>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S530>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
//  '<S531>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
//  '<S532>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
//  '<S533>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
//  '<S534>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S535>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
//  '<S536>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S537>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S538>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S539>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S540>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S541>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S542>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S543>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S544>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S545>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S546>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S547>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S548>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
//  '<S549>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
//  '<S550>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
//  '<S551>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
//  '<S552>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
//  '<S553>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
//  '<S554>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
//  '<S555>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
//  '<S556>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
//  '<S557>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
//  '<S558>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
//  '<S559>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
//  '<S560>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
//  '<S561>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians10'
//  '<S562>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians11'
//  '<S563>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians12'
//  '<S564>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians7'
//  '<S565>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians8'
//  '<S566>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians9'
//  '<S567>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass'
//  '<S568>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Filter2'
//  '<S569>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2'
//  '<S570>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS'
//  '<S571>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS/MATLAB Function'
//  '<S572>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Filter2/DEFINITIVA'
//  '<S573>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1'
//  '<S574>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti'
//  '<S575>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/MATLAB Function2'
//  '<S576>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Sample and Hold'
//  '<S577>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function'
//  '<S578>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function1'
//  '<S579>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti/MATLAB Function'
//  '<S580>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280'
//  '<S581>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Compare To Constant'
//  '<S582>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Counter Limited'
//  '<S583>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/GPS_Venus'
//  '<S584>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/MTi'
//  '<S585>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Pitot_Lidar'
//  '<S586>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Dynamic rate limiter'
//  '<S587>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Execution_loop'
//  '<S588>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/MATLAB Function'
//  '<S589>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Subsystem'
//  '<S590>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
//  '<S591>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Subsystem/Subsystem1'
//  '<S592>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Counter Limited/Increment Real World'
//  '<S593>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Counter Limited/Wrap To Zero'
//  '<S594>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/GPS_Venus/Subsystem2'
//  '<S595>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/MTi/MATLAB Function1'
//  '<S596>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/AILERON'
//  '<S597>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/AILERON1'
//  '<S598>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/ELEVATOR'
//  '<S599>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/ELEVATOR1'
//  '<S600>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/RUDDER'
//  '<S601>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/THROTTLE'
//  '<S602>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/AILERON1'
//  '<S603>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/RUDDER6'
//  '<S604>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/THROTTLE1'
//  '<S605>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/elevator'
//  '<S606>' : 'Aenea_model/LOG_DATA_MODEL/Compare To Constant'
//  '<S607>' : 'Aenea_model/LOG_DATA_MODEL/Counter Limited'
//  '<S608>' : 'Aenea_model/LOG_DATA_MODEL/LOG_BOOL_SIGNALS'
//  '<S609>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS'
//  '<S610>' : 'Aenea_model/LOG_DATA_MODEL/LOG_INT16_SIGNALS'
//  '<S611>' : 'Aenea_model/LOG_DATA_MODEL/LOG_INT32_SIGNALS'
//  '<S612>' : 'Aenea_model/LOG_DATA_MODEL/LOG_INT8_SIGNALS'
//  '<S613>' : 'Aenea_model/LOG_DATA_MODEL/LOG_SINGLE_SIGNALS'
//  '<S614>' : 'Aenea_model/LOG_DATA_MODEL/LOG_UINT16_SIGNALS'
//  '<S615>' : 'Aenea_model/LOG_DATA_MODEL/LOG_UINT32_SIGNALS'
//  '<S616>' : 'Aenea_model/LOG_DATA_MODEL/LOG_UINT8_SIGNALS'
//  '<S617>' : 'Aenea_model/LOG_DATA_MODEL/Counter Limited/Increment Real World'
//  '<S618>' : 'Aenea_model/LOG_DATA_MODEL/Counter Limited/Wrap To Zero'
//  '<S619>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS/Radians to Degrees'
//  '<S620>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS/Radians to Degrees1'
//  '<S621>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS/Subsystem'

#endif                                 // RTW_HEADER_Aenea_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
