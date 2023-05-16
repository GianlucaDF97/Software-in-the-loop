//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.h
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.214
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Tue May 16 17:26:30 2023
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

// Block states (default storage) for system '<S410>/Resettable Subsystem'
typedef struct {
  real_T Memory_PreviousInput;         // '<S422>/Memory'
} DW_ResettableSubsystem_Aenea__T;

// Zero-crossing (trigger) state for system '<S410>/Resettable Subsystem'
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_k;// '<S410>/Resettable Subsystem'
} ZCE_ResettableSubsystem_Aenea_T;

// Block states (default storage) for system '<S426>/Enabled '
typedef struct {
  boolean_T Enabled_MODE;              // '<S426>/Enabled '
} DW_Enabled_Aenea_model_T;

// Block states (default storage) for system '<S426>/Resettable Subsystem'
typedef struct {
  real_T Memory_PreviousInput;         // '<S431>/Memory'
} DW_ResettableSubsystem_Aene_c_T;

// Zero-crossing (trigger) state for system '<S426>/Resettable Subsystem'
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE;// '<S426>/Resettable Subsystem'
} ZCE_ResettableSubsystem_Aen_h_T;

// Block states (default storage) for system '<S427>/Enabled '
typedef struct {
  boolean_T Enabled_MODE;              // '<S427>/Enabled '
} DW_Enabled_Aenea_model_d_T;

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
  real_T DataTypeConversion4[105];     // '<S452>/Data Type Conversion4'
  uint8_T buffer[300];                 // '<S3>/MATLAB Function2'
  BUS_log_t BusConversion_InsertedFor_SFunc;
  real_T y[21];                        // '<S570>/MATLAB Function2'
  real_T x_est[18];
  real_T klm_gain_c[18];
  real_T a[16];
  real_T A[16];
  real_T rtb_TmpSignalConversionAtSFun_k[14];
  uint8_T messaggio[100];              // '<S3>/MATLAB Function4'
  uint8_T messaggio_2[100];            // '<S3>/MATLAB Function4'
  boolean_T x[100];
  real_T residui[11];                  // '<S569>/DEFINITIVA'
  real_T dv1[11];
  real_T UnitDelay[9];                 // '<S585>/Unit Delay'
  real_T DataTypeConversion1_c[9];     // '<S7>/Data Type Conversion1'
  real_T aterra_tmp[9];
  char_T b_data[64];
  char_T sfull[64];
  int32_T ipiv[11];
  real_T x_new[4];
  real_T aterra[3];
  char_T hex_checksum_data[17];
  boolean_T NOT[14];                   // '<S575>/NOT'
  uint16_T WP_info_in[6];
  real_T Lat;                          // '<S584>/S-Function Builder'
  real_T Long;                         // '<S584>/S-Function Builder'
  real_T V;                            // '<S584>/S-Function Builder'
  real_T quota;                        // '<S584>/S-Function Builder'
  real_T heading;                      // '<S584>/S-Function Builder'
  real_T SFunctionBuilder_o6;          // '<S584>/S-Function Builder'
  real_T SFunctionBuilder_o1;          // '<S586>/S-Function Builder'
  real_T SFunctionBuilder_o2;          // '<S586>/S-Function Builder'
  real_T SFunctionBuilder_o3;          // '<S586>/S-Function Builder'
  real_T Switch;                       // '<S595>/Switch'
  real_T T;                            // '<S592>/T'
  real_T In[21];                       // '<S577>/In'
  real_T Lat_K;                        // '<S569>/DEFINITIVA'
  real_T Long_K;                       // '<S569>/DEFINITIVA'
  real_T h_K;                          // '<S569>/DEFINITIVA'
  real_T vd_K;                         // '<S569>/DEFINITIVA'
  real_T v_K;                          // '<S569>/DEFINITIVA'
  real_T imbardata;                    // '<S569>/DEFINITIVA'
  real_T V_goHome;                     // '<S454>/GO_HOME'
  real_T h_goHome;                     // '<S454>/GO_HOME'
  real_T VELOCITA;                     // '<S453>/saturatore V'
  real_T QUOTA;                        // '<S453>/WAYPOINTS'
  real_T Gain;                         // '<S470>/Gain'
  real_T Gain_o;                       // '<S471>/Gain'
  real_T velocita; // '<S452>/Switch di selezione  Task - Waypoint navigation5'
  real_T QUOTA_e;  // '<S452>/Switch di selezione  Task - Waypoint navigation4'
  real_T In_c[2];                      // '<S477>/In'
  real_T Constant1;                    // '<S467>/Constant1'
  real_T Sum2;                         // '<S467>/Sum2'
  real_T maneuver_selector;            // '<S452>/Chart1'
  real_T trig_approach;                // '<S452>/Chart1'
  real_T trig_flare;                   // '<S452>/Chart1'
  real_T approach_selector;            // '<S452>/Chart1'
  real_T h_Home;                       // '<S452>/CALIBRATING_HOME_COORDINATES'
  real_T Multiply;                     // '<S463>/Multiply'
  real_T Constant1_h;                  // '<S463>/Constant1'
  real_T x_f_out;                      // '<S463>/MATLAB Function'
  real_T h_f_out;                      // '<S463>/MATLAB Function'
  real_T k_x_out;                      // '<S463>/MATLAB Function'
  real_T h_c_out;                      // '<S463>/MATLAB Function'
  real_T no_solution;                  // '<S463>/MATLAB Function'
  real_T V_vett;                       // '<S451>/VETTORIALE'
  real_T h_vett;                       // '<S451>/VETTORIALE'
  real_T Fase_ATO;                     // '<S450>/Chart1'
  real_T manetta_ref;                  // '<S450>/Chart1'
  real_T eq_rot;                       // '<S450>/Chart1'
  real_T h_ref;                        // '<S450>/Chart1'
  real_T Tas_ref;                      // '<S450>/Chart1'
  real_T psi_ref_selector;             // '<S450>/Chart1'
  real_T theta_ground_selector;        // '<S450>/Chart1'
  real_T Switch_n;                     // '<S446>/Switch'
  real_T Switch_l;                     // '<S443>/Switch'
  real_T Switch_e;                     // '<S437>/Switch'
  real_T Switch_d;                     // '<S432>/Switch'
  real_T Switch_m;                     // '<S429>/Switch'
  real_T Switch_a;                     // '<S423>/Switch'
  real_T Switch_k;                     // '<S420>/Switch'
  real_T switch_manetta;               // '<S38>/ STATI'
  real_T switch_equilibratore;         // '<S38>/ STATI'
  real_T switch_alettoni;              // '<S38>/ STATI'
  real_T switch_timone;                // '<S38>/ STATI'
  real_T throttle_safe;                // '<S38>/ STATI'
  real_T modo;                         // '<S38>/ STATI'
  real_T OutportBufferForOut1;         // '<S303>/Constant'
  real_T checksum;
  real_T olddi;
  real_T a_b;
  real_T dist;
  real_T dist_fut;
  real_T Sum_l;                        // '<S571>/Sum'
  real_T e_d;                          // '<S37>/Sum2'
  real_T Sum5;                         // '<S602>/Sum5'
  real_T abs_ManualThrottle;           // '<S418>/Abs3'
  real_T Gain1_i0;                     // '<S566>/Gain1'
  real_T Gain1_f;                      // '<S563>/Gain1'
  real_T Gain1_o;                      // '<S564>/Gain1'
  real_T Sum3_h;                       // '<S597>/Sum3'
  real_T Gain_e;                       // '<S416>/Gain'
  real_T Gain_h;                       // '<S33>/Gain'
  real_T Saturation;                   // '<S349>/Saturation'
  real_T SwitchBumpless2;              // '<S304>/Switch Bumpless 2'
  real_T Sum3;                         // '<S599>/Sum3'
  real_T Equilibratore_n;              // '<S37>/Switch Bumpless 1'
  real_T Sum3_k;                       // '<S603>/Sum3'
  real_T Saturation_a;                 // '<S399>/Saturation'
  real_T Alettoni;                     // '<S37>/saturatore A'
  real_T Sum4_b;                       // '<S601>/Sum4'
  real_T Product1;                     // '<S571>/Product1'
  real_T Gain_dt;                      // '<S621>/Gain'
  real_T Alt;                          // '<S6>/Switch'
  real_T Switch1;                      // '<S38>/Switch1'
  real_T Switch_a_p;                   // '<S412>/Switch'
  real_T V_nord;                       // '<S6>/Multiply2'
  real_T Sum2_k2;                      // '<S305>/Sum2'
  real_T Switch_j;                     // '<S546>/Switch'
  real_T Abs1_l;                       // '<S537>/Abs1'
  real_T Sum_h;                        // '<S534>/Sum'
  real_T Gain_hh;                      // '<S475>/Gain'
  real_T Switch1_g;                    // '<S27>/Switch1'
  real_T Ato_selector;
  real_T Al_selector;
  real_T a_fut_tmp;
  real_T Wp_selector;
  real_T Vec_selector;
  real_T Go_home_selector;
  real_T aterra_tmp_tmp;
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
  real32_T SFunctionBuilder_o3_h;      // '<S588>/S-Function Builder'
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
  real32_T ByteUnpack_o2[9];           // '<S585>/Byte Unpack'
  real32_T ByteReversal[9];            // '<S585>/Byte Reversal'
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
  real32_T DataTypeConversion3_p;      // '<S588>/Data Type Conversion3'
  real32_T SFunctionBuilder_o1_g;      // '<S588>/S-Function Builder'
  real32_T SFunctionBuilder_o2_p;      // '<S588>/S-Function Builder'
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
  int16_T manual_elevatorCmd_pwm;      // '<S9>/S-Function Builder3'
  int16_T manual_throttleCmd_pwm;      // '<S9>/S-Function Builder'
  int16_T manual_aileronCmd_pwm;       // '<S9>/S-Function Builder1'
  int16_T DataTypeConversion_j[9];     // '<S17>/Data Type Conversion'
  int16_T DataTypeConversion1_j[3];    // '<S15>/Data Type Conversion1'
  int16_T Heading_f;                   // '<S22>/Data Type Conversion1'
  int16_T manual_rudderCmd_pwm;        // '<S9>/S-Function Builder2'
  int16_T DataTypeConversion2_m;       // '<S4>/Data Type Conversion2'
  int16_T SFunctionBuilder4;           // '<S9>/S-Function Builder4'
  int16_T Sum;                         // '<S605>/Sum'
  int16_T elevatorCmd_pwm;             // '<S10>/Data Type Conversion'
  int16_T aileronCmd_pwm;              // '<S10>/Data Type Conversion1'
  int16_T rudderCmd_pwm;               // '<S10>/Data Type Conversion2'
  uint8_T SFunctionBuilder1[41];       // '<S585>/S-Function Builder1'
  uint8_T ByteUnpack_o1[4];            // '<S585>/Byte Unpack'
  uint8_T ByteUnpack_o3;               // '<S585>/Byte Unpack'
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
  uint8_T Mex_out[41];                 // '<S585>/MATLAB Function1'
  uint8_T iflogic;                     // '<S18>/iflogic_function'
  uint8_T mess_out[100];               // '<S3>/MATLAB Function2'
  boolean_T SFunctionBuilder_o7;       // '<S584>/S-Function Builder'
  boolean_T Compare;                   // '<S582>/Compare'
  boolean_T HitCrossing;               // '<S251>/Hit  Crossing'
  boolean_T Compare_i;                 // '<S607>/Compare'
} B_Aenea_model_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE[9];          // '<S585>/Unit Delay'
  real_T UnitDelay1_DSTATE;            // '<S581>/Unit Delay1'
  real_T UnitDelay_DSTATE_c;           // '<S571>/Unit Delay'
  real_T UnitDelay_DSTATE_h[5];        // '<S584>/Unit Delay'
  real_T Integrator_DSTATE;            // '<S342>/Integrator'
  real_T Integrator_DSTATE_l;          // '<S392>/Integrator'
  real_T DiscreteWashoutFilter_states; // '<S306>/Discrete Washout Filter'
  real_T DelayInput2_DSTATE;           // '<S587>/Delay Input2'
  real_T Delay_DSTATE;                 // '<S250>/Delay'
  real_T Integrator_DSTATE_lq;         // '<S285>/Integrator'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S307>/Discrete-Time Integrator'
  real_T SFunctionBuilder_DSTATE;      // '<S10>/S-Function Builder'
  real_T SFunctionBuilder1_DSTATE;     // '<S10>/S-Function Builder1'
  real_T SFunctionBuilder2_DSTATE;     // '<S10>/S-Function Builder2'
  real_T SFunctionBuilder3_DSTATE;     // '<S10>/S-Function Builder3'
  real_T UnitDelay_DSTATE_n;           // '<S622>/Unit Delay'
  real_T DiscreteTimeIntegrator_DSTATE_j;// '<S463>/Discrete-Time Integrator'
  volatile real_T RateTransition_Buffer0;// '<S27>/Rate Transition'
  real_T Memory1_PreviousInput;        // '<S27>/Memory1'
  real_T Memory_PreviousInput;         // '<S27>/Memory'
  real_T Memory_PreviousInput_e[14];   // '<S575>/Memory'
  real_T Memory_PreviousInput_o[14];   // '<S574>/Memory'
  real_T Memory2_PreviousInput;        // '<S27>/Memory2'
  real_T P_ref;                        // '<S581>/MATLAB Function'
  real_T rl_up;                        // '<S581>/MATLAB Function'
  real_T rl_dw;                        // '<S581>/MATLAB Function'
  real_T x_prd[18];                    // '<S569>/DEFINITIVA'
  real_T p_prd[324];                   // '<S569>/DEFINITIVA'
  real_T flag;                         // '<S454>/GO_HOME'
  real_T Memory4_PreviousInput;        // '<S453>/Memory4'
  real_T flag_o;                       // '<S453>/WAYPOINTS'
  real_T lat1;                         // '<S453>/WAYPOINTS'
  real_T long1;                        // '<S453>/WAYPOINTS'
  real_T Memory7_PreviousInput;        // '<S452>/Memory7'
  real_T Memory5_PreviousInput;        // '<S452>/Memory5'
  real_T Memory1_PreviousInput_f;      // '<S452>/Memory1'
  real_T Memory2_PreviousInput_e;      // '<S452>/Memory2'
  real_T x[4];                         // '<S463>/MATLAB Function'
  real_T cycle_count;                  // '<S463>/MATLAB Function'
  real_T eps[4];                       // '<S463>/MATLAB Function'
  real_T flag_k;                       // '<S452>/ALLINEAMENTO'
  real_T Memory3_PreviousInput;        // '<S451>/Memory3'
  real_T V_ref;                        // '<S451>/VETTORIALE'
  real_T ALT_ref;                      // '<S451>/VETTORIALE'
  real_T Memory_PreviousInput_p;       // '<S450>/Memory'
  real_T Memory1_PreviousInput_e;      // '<S450>/Memory1'
  real_T alarm;                        // '<S417>/MATLAB Function1'
  real_T Tf;                           // '<S412>/MATLAB Function1'
  real_T mess_len;                     // '<S3>/MATLAB Function4'
  real_T test1;                        // '<S3>/MATLAB Function1'
  real32_T riferimenti[16];            // '<S3>/MATLAB Function1'
  real32_T WP_dbP[105];                // '<S3>/MATLAB Function1'
  real32_T WP_dbP_AL[105];             // '<S3>/MATLAB Function1'
  int_T HitCrossing_MODE;              // '<S251>/Hit  Crossing'
  uint16_T Memory_PreviousInput_i[8];  // '<S3>/Memory'
  uint16_T Memory_PreviousInput_e4;    // '<S4>/Memory'
  uint16_T counter;                    // '<S3>/MATLAB Function3'
  uint16_T WP_dbI[90];                 // '<S3>/MATLAB Function1'
  uint8_T UnitDelay1_DSTATE_b[41];     // '<S585>/Unit Delay1'
  uint8_T Output_DSTATE;               // '<S583>/Output'
  uint8_T Output_DSTATE_k;             // '<S608>/Output'
  int8_T Integrator_PrevResetState;    // '<S392>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S307>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_o;// '<S463>/Discrete-Time Integrator'
  uint8_T Memory4_PreviousInput_j[300];// '<S3>/Memory4'
  uint8_T Memory5_PreviousInput_b[100];// '<S3>/Memory5'
  uint8_T Memory1_PreviousInput_b[2];  // '<S3>/Memory1'
  uint8_T Memory_PreviousInput_a[4];   // '<S1>/Memory'
  uint8_T Memory3_PreviousInput_g;     // '<S3>/Memory3'
  uint8_T Memory2_PreviousInput_d[9];  // '<S3>/Memory2'
  uint8_T is_active_c10_Aenea_model;   // '<S452>/Chart1'
  uint8_T is_c10_Aenea_model;          // '<S452>/Chart1'
  uint8_T Memory1_PreviousInput_k;     // '<S451>/Memory1'
  uint8_T Memory2_PreviousInput_d2;    // '<S451>/Memory2'
  uint8_T Memory6_PreviousInput;       // '<S451>/Memory6'
  uint8_T is_active_c1_Aenea_model;    // '<S450>/Chart1'
  uint8_T is_c1_Aenea_model;           // '<S450>/Chart1'
  uint8_T temporalCounter_i1;          // '<S450>/Chart1'
  uint8_T is_active_c21_Aenea_model;   // '<S39>/Chart'
  uint8_T is_c21_Aenea_model;          // '<S39>/Chart'
  uint8_T is_active_c26_Aenea_model;   // '<S38>/ STATI'
  uint8_T is_c26_Aenea_model;          // '<S38>/ STATI'
  uint8_T is_AUTOMATICA;               // '<S38>/ STATI'
  uint8_T is_active_c23_Aenea_model;
                                   // '<S40>/SELEZIONE MODALITA'  HOLD//SELECT'
  uint8_T is_c23_Aenea_model;      // '<S40>/SELEZIONE MODALITA'  HOLD//SELECT'
  uint8_T message[100];                // '<S3>/MATLAB Function4'
  uint8_T counter_f;                   // '<S3>/MATLAB Function4'
  boolean_T Memory_PreviousInput_n;    // '<S38>/Memory'
  boolean_T x_prd_not_empty;           // '<S569>/DEFINITIVA'
  boolean_T x_not_empty;               // '<S463>/MATLAB Function'
  boolean_T x_new_not_empty;           // '<S463>/MATLAB Function'
  boolean_T cycle_count_not_empty;     // '<S463>/MATLAB Function'
  boolean_T eps_not_empty;             // '<S463>/MATLAB Function'
  boolean_T Tf_not_empty;              // '<S412>/MATLAB Function1'
  boolean_T Interr_parz;               // '<S3>/MATLAB Function4'
  boolean_T WP_dbP_not_empty;          // '<S3>/MATLAB Function1'
  boolean_T WP_dbP_AL_not_empty;       // '<S3>/MATLAB Function1'
  boolean_T Enabled_MODE;              // '<S435>/Enabled '
  DW_ResettableSubsystem_Aene_c_T ResettableSubsystem_p0;// '<S441>/Resettable Subsystem' 
  DW_Enabled_Aenea_model_d_T Enabled_h;// '<S441>/Enabled '
  DW_ResettableSubsystem_Aene_c_T ResettableSubsystem_h;// '<S440>/Resettable Subsystem' 
  DW_Enabled_Aenea_model_T Enabled_n;  // '<S440>/Enabled '
  DW_ResettableSubsystem_Aene_c_T ResettableSubsystem_p;// '<S435>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aene_c_T ResettableSubsystem_o;// '<S427>/Resettable Subsystem' 
  DW_Enabled_Aenea_model_d_T Enabled_o;// '<S427>/Enabled '
  DW_ResettableSubsystem_Aene_c_T ResettableSubsystem_i;// '<S426>/Resettable Subsystem' 
  DW_Enabled_Aenea_model_T Enabled;    // '<S426>/Enabled '
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem_j;// '<S411>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem;// '<S410>/Resettable Subsystem' 
} DW_Aenea_model_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    // '<S251>/Hit  Crossing'
  ZCSigState SampleandHold_Trig_ZCE;   // '<S570>/Sample and Hold'
  ZCSigState SampleandHold_Trig_ZCE_l; // '<S452>/Sample and Hold'
  ZCSigState SampleandHold1_Trig_ZCE;  // '<S450>/Sample and Hold1'
  ZCSigState SampleandHold_Trig_ZCE_a; // '<S450>/Sample and Hold'
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_p0;// '<S441>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_h;// '<S440>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_p;// '<S435>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_o;// '<S427>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aen_h_T ResettableSubsystem_i;// '<S426>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem_j;// '<S411>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem;// '<S410>/Resettable Subsystem' 
  ZCSigState EnabledSubsystem_Trig_ZCE;// '<S251>/Enabled Subsystem'
} PrevZCX_Aenea_model_T;

// Invariant block signals (default storage)
typedef const struct tag_ConstB_Aenea_model_T {
  real_T Sum1;                         // '<S599>/Sum1'
  real_T Sum3;                         // '<S602>/Sum3'
  real_T Sum1_o;                       // '<S597>/Sum1'
  real_T USCITAPERCENTUALE;            // '<S22>/USCITA PERCENTUALE'
  real_T Sum2;                         // '<S601>/Sum2'
  real_T Sum1_j;                       // '<S605>/Sum1'
  real_T Sum2_d;                       // '<S606>/Sum2'
  real_T Sum2_a;                       // '<S603>/Sum2'
  real_T Sum2_g;                       // '<S604>/Sum2'
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
//  Block '<S74>/DProd Out' : Unused code path elimination
//  Block '<S75>/Filter' : Unused code path elimination
//  Block '<S75>/SumD' : Unused code path elimination
//  Block '<S77>/IProd Out' : Unused code path elimination
//  Block '<S80>/Integrator' : Unused code path elimination
//  Block '<S83>/NProd Out' : Unused code path elimination
//  Block '<S85>/PProd Out' : Unused code path elimination
//  Block '<S89>/Sum' : Unused code path elimination
//  Block '<S91>/Kt' : Unused code path elimination
//  Block '<S91>/SumI3' : Unused code path elimination
//  Block '<S92>/SumI1' : Unused code path elimination
//  Block '<S122>/DProd Out' : Unused code path elimination
//  Block '<S123>/Filter' : Unused code path elimination
//  Block '<S123>/SumD' : Unused code path elimination
//  Block '<S125>/IProd Out' : Unused code path elimination
//  Block '<S128>/Integrator' : Unused code path elimination
//  Block '<S131>/NProd Out' : Unused code path elimination
//  Block '<S133>/PProd Out' : Unused code path elimination
//  Block '<S137>/Sum' : Unused code path elimination
//  Block '<S139>/Kt' : Unused code path elimination
//  Block '<S139>/SumI3' : Unused code path elimination
//  Block '<S140>/SumI1' : Unused code path elimination
//  Block '<S173>/IProd Out' : Unused code path elimination
//  Block '<S176>/Integrator' : Unused code path elimination
//  Block '<S181>/PProd Out' : Unused code path elimination
//  Block '<S185>/Sum' : Unused code path elimination
//  Block '<S187>/Kt' : Unused code path elimination
//  Block '<S187>/SumI3' : Unused code path elimination
//  Block '<S188>/SumI1' : Unused code path elimination
//  Block '<S43>/Saturation' : Unused code path elimination
//  Block '<S43>/Sum1' : Unused code path elimination
//  Block '<S43>/Sum2' : Unused code path elimination
//  Block '<S43>/Sum4' : Unused code path elimination
//  Block '<S43>/Switch auto-manual' : Unused code path elimination
//  Block '<S43>/Switch maneuver' : Unused code path elimination
//  Block '<S43>/Switch rc saturata' : Unused code path elimination
//  Block '<S43>/n-D Lookup Table' : Unused code path elimination
//  Block '<S40>/Kp' : Unused code path elimination
//  Block '<S45>/Constant' : Unused code path elimination
//  Block '<S45>/Lookup Table2' : Unused code path elimination
//  Block '<S193>/Data Type Duplicate' : Unused code path elimination
//  Block '<S193>/Data Type Propagation' : Unused code path elimination
//  Block '<S193>/LowerRelop1' : Unused code path elimination
//  Block '<S193>/Switch' : Unused code path elimination
//  Block '<S193>/Switch2' : Unused code path elimination
//  Block '<S193>/UpperRelop' : Unused code path elimination
//  Block '<S40>/Switch HOLD//SELECT' : Unused code path elimination
//  Block '<S194>/Constant3' : Unused code path elimination
//  Block '<S194>/Constant4' : Unused code path elimination
//  Block '<S194>/Multiport Switch2' : Unused code path elimination
//  Block '<S194>/Multiport Switch3' : Unused code path elimination
//  Block '<S194>/Switch3' : Unused code path elimination
//  Block '<S194>/Switch4' : Unused code path elimination
//  Block '<S41>/Constant' : Unused code path elimination
//  Block '<S41>/Constant2' : Unused code path elimination
//  Block '<S221>/AND3' : Unused code path elimination
//  Block '<S221>/Constant1' : Unused code path elimination
//  Block '<S221>/DataTypeConv1' : Unused code path elimination
//  Block '<S221>/DataTypeConv2' : Unused code path elimination
//  Block '<S223>/DeadZone' : Unused code path elimination
//  Block '<S221>/Equal1' : Unused code path elimination
//  Block '<S221>/NotEqual' : Unused code path elimination
//  Block '<S221>/SignPreIntegrator' : Unused code path elimination
//  Block '<S221>/SignPreSat' : Unused code path elimination
//  Block '<S221>/Switch' : Unused code path elimination
//  Block '<S221>/ZeroGain' : Unused code path elimination
//  Block '<S224>/DProd Out' : Unused code path elimination
//  Block '<S225>/Filter' : Unused code path elimination
//  Block '<S225>/SumD' : Unused code path elimination
//  Block '<S227>/IProd Out' : Unused code path elimination
//  Block '<S230>/Integrator' : Unused code path elimination
//  Block '<S233>/NProd Out' : Unused code path elimination
//  Block '<S235>/PProd Out' : Unused code path elimination
//  Block '<S237>/Saturation' : Unused code path elimination
//  Block '<S239>/Sum' : Unused code path elimination
//  Block '<S241>/Kt' : Unused code path elimination
//  Block '<S241>/SumI3' : Unused code path elimination
//  Block '<S242>/SumI1' : Unused code path elimination
//  Block '<S41>/Switch' : Unused code path elimination
//  Block '<S41>/Switch auto-manual' : Unused code path elimination
//  Block '<S196>/Constant' : Unused code path elimination
//  Block '<S196>/Constant1' : Unused code path elimination
//  Block '<S196>/Constant2' : Unused code path elimination
//  Block '<S247>/Gain1' : Unused code path elimination
//  Block '<S196>/Math Function' : Unused code path elimination
//  Block '<S248>/Gain' : Unused code path elimination
//  Block '<S196>/Sum' : Unused code path elimination
//  Block '<S196>/Sum1' : Unused code path elimination
//  Block '<S196>/Sum2' : Unused code path elimination
//  Block '<S196>/Switch' : Unused code path elimination
//  Block '<S196>/Switch1' : Unused code path elimination
//  Block '<S36>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
//  Block '<S36>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
//  Block '<S37>/Gain3' : Unused code path elimination
//  Block '<S37>/Switch Bumpless 7' : Unused code path elimination
//  Block '<S410>/Display' : Unused code path elimination
//  Block '<S410>/Display1' : Unused code path elimination
//  Block '<S38>/Scope1' : Unused code path elimination
//  Block '<S418>/Abs2' : Unused code path elimination
//  Block '<S463>/Multiply1' : Unused code path elimination
//  Block '<S452>/Constant1' : Unused code path elimination
//  Block '<S452>/Constant7' : Unused code path elimination
//  Block '<S467>/Exp1' : Unused code path elimination
//  Block '<S467>/Gain1' : Unused code path elimination
//  Block '<S467>/Gain2' : Unused code path elimination
//  Block '<S467>/Multiply2' : Unused code path elimination
//  Block '<S467>/Multiply3' : Unused code path elimination
//  Block '<S467>/Multiply4' : Unused code path elimination
//  Block '<S467>/Sum3' : Unused code path elimination
//  Block '<S467>/Sum4' : Unused code path elimination
//  Block '<S468>/Gain1' : Unused code path elimination
//  Block '<S513>/IProd Out' : Unused code path elimination
//  Block '<S516>/Integrator' : Unused code path elimination
//  Block '<S521>/PProd Out' : Unused code path elimination
//  Block '<S525>/Sum' : Unused code path elimination
//  Block '<S484>/Gain' : Unused code path elimination
//  Block '<S468>/Sum3' : Unused code path elimination
//  Block '<S468>/psi ref gain' : Unused code path elimination
//  Block '<S468>/psi ref gain1' : Unused code path elimination
//  Block '<S536>/Sum3' : Unused code path elimination
//  Block '<S536>/x*sin' : Unused code path elimination
//  Block '<S536>/y*cos' : Unused code path elimination
//  Block '<S452>/Relational Operator' : Unused code path elimination
//  Block '<S452>/Switch' : Unused code path elimination
//  Block '<S452>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
//  Block '<S452>/Switch1' : Unused code path elimination
//  Block '<S453>/saturatore V1' : Unused code path elimination
//  Block '<S39>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
//  Block '<S39>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
//  Block '<S6>/Constant2' : Unused code path elimination
//  Block '<S570>/Memory' : Unused code path elimination
//  Block '<S587>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S591>/Data Type Duplicate' : Unused code path elimination
//  Block '<S591>/Data Type Propagation' : Unused code path elimination
//  Block '<S7>/Constant9' : Unused code path elimination
//  Block '<S583>/Data Type Propagation' : Unused code path elimination
//  Block '<S593>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S594>/FixPt Data Type Duplicate1' : Unused code path elimination
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
//  Block '<S598>/Constant8' : Unused code path elimination
//  Block '<S598>/Constant9' : Unused code path elimination
//  Block '<S598>/Divide' : Unused code path elimination
//  Block '<S598>/Gain' : Unused code path elimination
//  Block '<S598>/Multiply' : Unused code path elimination
//  Block '<S598>/Saturation' : Unused code path elimination
//  Block '<S598>/Sum' : Unused code path elimination
//  Block '<S598>/Sum1' : Unused code path elimination
//  Block '<S598>/Sum2' : Unused code path elimination
//  Block '<S598>/Sum3' : Unused code path elimination
//  Block '<S9>/Constant' : Unused code path elimination
//  Block '<S9>/Constant1' : Unused code path elimination
//  Block '<S9>/Data Type Conversion16' : Unused code path elimination
//  Block '<S9>/Data Type Conversion17' : Unused code path elimination
//  Block '<S9>/Data Type Conversion18' : Unused code path elimination
//  Block '<S9>/Data Type Conversion19' : Unused code path elimination
//  Block '<S9>/Data Type Conversion20' : Unused code path elimination
//  Block '<S9>/Data Type Conversion21' : Unused code path elimination
//  Block '<S600>/Constant8' : Unused code path elimination
//  Block '<S600>/Constant9' : Unused code path elimination
//  Block '<S600>/Divide' : Unused code path elimination
//  Block '<S600>/Gain' : Unused code path elimination
//  Block '<S600>/Multiply' : Unused code path elimination
//  Block '<S600>/Saturation' : Unused code path elimination
//  Block '<S600>/Sum' : Unused code path elimination
//  Block '<S600>/Sum1' : Unused code path elimination
//  Block '<S600>/Sum2' : Unused code path elimination
//  Block '<S600>/Sum3' : Unused code path elimination
//  Block '<S9>/Switch' : Unused code path elimination
//  Block '<S608>/Data Type Propagation' : Unused code path elimination
//  Block '<S618>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S619>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S296>/Kt' : Eliminated nontunable gain of 1
//  Block '<S335>/Kb' : Eliminated nontunable gain of 1
//  Block '<S353>/Kt' : Eliminated nontunable gain of 1
//  Block '<S403>/Kt' : Eliminated nontunable gain of 1
//  Block '<S37>/Gain' : Eliminated nontunable gain of 1
//  Block '<S37>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S581>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S581>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S7>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S7>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S7>/Manual Switch3' : Eliminated due to constant selection input
//  Block '<S9>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion12' : Eliminate redundant data type conversion
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
//  Block '<S617>/Data Type Conversion1' : Eliminate redundant data type conversion
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
//  '<S44>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
//  '<S45>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
//  '<S46>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
//  '<S47>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
//  '<S48>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
//  '<S49>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
//  '<S50>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
//  '<S51>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
//  '<S52>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
//  '<S53>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
//  '<S54>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
//  '<S55>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
//  '<S56>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
//  '<S57>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
//  '<S58>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
//  '<S59>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
//  '<S60>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
//  '<S61>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
//  '<S62>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
//  '<S63>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
//  '<S64>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
//  '<S65>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
//  '<S66>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
//  '<S67>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
//  '<S68>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
//  '<S69>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
//  '<S70>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
//  '<S71>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
//  '<S72>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
//  '<S73>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
//  '<S74>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
//  '<S75>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
//  '<S76>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
//  '<S77>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
//  '<S78>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
//  '<S79>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
//  '<S80>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
//  '<S81>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
//  '<S82>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
//  '<S83>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
//  '<S84>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
//  '<S85>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
//  '<S86>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
//  '<S87>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
//  '<S88>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
//  '<S89>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
//  '<S90>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
//  '<S91>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
//  '<S92>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
//  '<S93>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
//  '<S94>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
//  '<S95>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
//  '<S96>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
//  '<S97>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
//  '<S98>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
//  '<S99>'  : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
//  '<S100>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
//  '<S101>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
//  '<S102>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
//  '<S103>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
//  '<S104>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
//  '<S105>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
//  '<S106>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
//  '<S107>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
//  '<S108>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
//  '<S109>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
//  '<S110>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
//  '<S111>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
//  '<S112>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
//  '<S113>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
//  '<S114>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
//  '<S115>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
//  '<S116>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
//  '<S117>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
//  '<S118>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
//  '<S119>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
//  '<S120>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
//  '<S121>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
//  '<S122>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
//  '<S123>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
//  '<S124>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
//  '<S125>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
//  '<S126>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
//  '<S127>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
//  '<S128>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
//  '<S129>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
//  '<S130>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
//  '<S131>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
//  '<S132>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
//  '<S133>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
//  '<S134>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
//  '<S135>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
//  '<S136>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
//  '<S137>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
//  '<S138>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
//  '<S139>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
//  '<S140>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
//  '<S141>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
//  '<S142>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
//  '<S143>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
//  '<S144>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
//  '<S145>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
//  '<S146>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
//  '<S147>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
//  '<S148>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
//  '<S149>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
//  '<S150>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
//  '<S151>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
//  '<S152>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
//  '<S153>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
//  '<S154>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
//  '<S155>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
//  '<S156>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
//  '<S157>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
//  '<S158>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
//  '<S159>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
//  '<S160>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
//  '<S161>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
//  '<S162>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
//  '<S163>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
//  '<S164>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
//  '<S165>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
//  '<S166>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
//  '<S167>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
//  '<S168>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
//  '<S169>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
//  '<S170>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
//  '<S171>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
//  '<S172>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
//  '<S173>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
//  '<S174>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
//  '<S175>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
//  '<S176>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
//  '<S177>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
//  '<S178>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
//  '<S179>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
//  '<S180>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
//  '<S181>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
//  '<S182>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
//  '<S183>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
//  '<S184>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
//  '<S185>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
//  '<S186>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
//  '<S187>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
//  '<S188>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
//  '<S189>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
//  '<S190>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
//  '<S191>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
//  '<S192>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
//  '<S193>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
//  '<S194>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
//  '<S195>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
//  '<S196>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
//  '<S197>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
//  '<S198>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
//  '<S199>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
//  '<S200>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
//  '<S201>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
//  '<S202>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
//  '<S203>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
//  '<S204>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
//  '<S205>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
//  '<S206>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
//  '<S207>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
//  '<S208>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
//  '<S209>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
//  '<S210>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
//  '<S211>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
//  '<S212>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
//  '<S213>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
//  '<S214>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
//  '<S215>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
//  '<S216>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
//  '<S217>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
//  '<S218>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
//  '<S219>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
//  '<S220>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
//  '<S221>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S222>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S223>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S224>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
//  '<S225>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S226>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S227>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
//  '<S228>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
//  '<S229>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S230>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
//  '<S231>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
//  '<S232>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
//  '<S233>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
//  '<S234>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
//  '<S235>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
//  '<S236>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
//  '<S237>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
//  '<S238>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
//  '<S239>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
//  '<S240>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
//  '<S241>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
//  '<S242>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
//  '<S243>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
//  '<S244>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S245>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
//  '<S246>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
//  '<S247>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
//  '<S248>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
//  '<S249>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
//  '<S250>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch'
//  '<S251>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
//  '<S252>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
//  '<S253>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
//  '<S254>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
//  '<S255>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
//  '<S256>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
//  '<S257>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
//  '<S258>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
//  '<S259>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
//  '<S260>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
//  '<S261>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
//  '<S262>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
//  '<S263>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
//  '<S264>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
//  '<S265>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
//  '<S266>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
//  '<S267>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
//  '<S268>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
//  '<S269>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
//  '<S270>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
//  '<S271>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
//  '<S272>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
//  '<S273>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
//  '<S274>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
//  '<S275>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
//  '<S276>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S277>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S278>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S279>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
//  '<S280>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
//  '<S281>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
//  '<S282>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
//  '<S283>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
//  '<S284>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S285>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
//  '<S286>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
//  '<S287>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S288>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
//  '<S289>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
//  '<S290>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
//  '<S291>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
//  '<S292>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
//  '<S293>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
//  '<S294>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
//  '<S295>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
//  '<S296>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
//  '<S297>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S298>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
//  '<S299>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S300>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
//  '<S301>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
//  '<S302>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch/Smooth Bypass'
//  '<S303>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
//  '<S304>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
//  '<S305>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
//  '<S306>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
//  '<S307>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
//  '<S308>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
//  '<S309>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
//  '<S310>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
//  '<S311>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
//  '<S312>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
//  '<S313>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
//  '<S314>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
//  '<S315>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
//  '<S316>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
//  '<S317>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
//  '<S318>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
//  '<S319>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
//  '<S320>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
//  '<S321>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
//  '<S322>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
//  '<S323>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
//  '<S324>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
//  '<S325>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
//  '<S326>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
//  '<S327>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
//  '<S328>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
//  '<S329>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
//  '<S330>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
//  '<S331>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
//  '<S332>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
//  '<S333>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
//  '<S334>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
//  '<S335>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
//  '<S336>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
//  '<S337>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
//  '<S338>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
//  '<S339>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
//  '<S340>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S341>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S342>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
//  '<S343>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
//  '<S344>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S345>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
//  '<S346>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
//  '<S347>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
//  '<S348>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
//  '<S349>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
//  '<S350>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S351>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
//  '<S352>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
//  '<S353>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
//  '<S354>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S355>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
//  '<S356>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S357>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
//  '<S358>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
//  '<S359>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
//  '<S360>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
//  '<S361>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
//  '<S362>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
//  '<S363>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
//  '<S364>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
//  '<S365>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
//  '<S366>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
//  '<S367>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
//  '<S368>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
//  '<S369>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
//  '<S370>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
//  '<S371>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
//  '<S372>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
//  '<S373>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
//  '<S374>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
//  '<S375>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
//  '<S376>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
//  '<S377>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
//  '<S378>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
//  '<S379>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
//  '<S380>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
//  '<S381>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
//  '<S382>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
//  '<S383>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
//  '<S384>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
//  '<S385>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
//  '<S386>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
//  '<S387>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
//  '<S388>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
//  '<S389>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
//  '<S390>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
//  '<S391>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S392>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
//  '<S393>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
//  '<S394>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S395>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
//  '<S396>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
//  '<S397>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
//  '<S398>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
//  '<S399>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
//  '<S400>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
//  '<S401>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
//  '<S402>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
//  '<S403>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
//  '<S404>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S405>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
//  '<S406>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S407>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
//  '<S408>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
//  '<S409>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
//  '<S410>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
//  '<S411>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
//  '<S412>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
//  '<S413>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
//  '<S414>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
//  '<S415>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
//  '<S416>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
//  '<S417>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
//  '<S418>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
//  '<S419>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1'
//  '<S420>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
//  '<S421>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
//  '<S422>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
//  '<S423>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
//  '<S424>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
//  '<S425>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
//  '<S426>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
//  '<S427>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
//  '<S428>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
//  '<S429>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
//  '<S430>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
//  '<S431>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
//  '<S432>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
//  '<S433>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
//  '<S434>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
//  '<S435>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
//  '<S436>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
//  '<S437>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
//  '<S438>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
//  '<S439>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
//  '<S440>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec'
//  '<S441>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec'
//  '<S442>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/MATLAB Function1'
//  '<S443>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec/Enabled '
//  '<S444>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec/Resettable Subsystem'
//  '<S445>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
//  '<S446>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec/Enabled '
//  '<S447>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec/Resettable Subsystem'
//  '<S448>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/GESTIONE AUTOPILOTI1/go home Manager1/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
//  '<S449>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Chart'
//  '<S450>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
//  '<S451>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem'
//  '<S452>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1'
//  '<S453>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2'
//  '<S454>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3'
//  '<S455>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
//  '<S456>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
//  '<S457>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
//  '<S458>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
//  '<S459>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
//  '<S460>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
//  '<S461>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
//  '<S462>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
//  '<S463>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
//  '<S464>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
//  '<S465>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
//  '<S466>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
//  '<S467>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
//  '<S468>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
//  '<S469>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
//  '<S470>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
//  '<S471>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
//  '<S472>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
//  '<S473>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
//  '<S474>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
//  '<S475>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
//  '<S476>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
//  '<S477>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
//  '<S478>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
//  '<S479>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
//  '<S480>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
//  '<S481>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
//  '<S482>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
//  '<S483>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
//  '<S484>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
//  '<S485>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
//  '<S486>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
//  '<S487>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
//  '<S488>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
//  '<S489>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
//  '<S490>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
//  '<S491>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
//  '<S492>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
//  '<S493>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
//  '<S494>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
//  '<S495>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
//  '<S496>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
//  '<S497>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
//  '<S498>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
//  '<S499>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
//  '<S500>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
//  '<S501>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
//  '<S502>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
//  '<S503>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
//  '<S504>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
//  '<S505>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
//  '<S506>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
//  '<S507>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
//  '<S508>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
//  '<S509>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
//  '<S510>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
//  '<S511>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
//  '<S512>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
//  '<S513>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
//  '<S514>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
//  '<S515>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S516>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
//  '<S517>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
//  '<S518>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S519>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
//  '<S520>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
//  '<S521>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
//  '<S522>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
//  '<S523>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
//  '<S524>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
//  '<S525>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
//  '<S526>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
//  '<S527>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
//  '<S528>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S529>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
//  '<S530>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S531>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
//  '<S532>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
//  '<S533>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
//  '<S534>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
//  '<S535>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S536>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
//  '<S537>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S538>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S539>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S540>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S541>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S542>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S543>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S544>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S545>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S546>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S547>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S548>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S549>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
//  '<S550>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
//  '<S551>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
//  '<S552>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
//  '<S553>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
//  '<S554>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
//  '<S555>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
//  '<S556>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
//  '<S557>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
//  '<S558>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
//  '<S559>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
//  '<S560>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
//  '<S561>' : 'Aenea_model/AUTOPILOT_MODEL/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
//  '<S562>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians10'
//  '<S563>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians11'
//  '<S564>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians12'
//  '<S565>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians7'
//  '<S566>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians8'
//  '<S567>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Degrees to Radians9'
//  '<S568>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass'
//  '<S569>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Filter2'
//  '<S570>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2'
//  '<S571>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS'
//  '<S572>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS/MATLAB Function'
//  '<S573>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/Filter2/DEFINITIVA'
//  '<S574>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1'
//  '<S575>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti'
//  '<S576>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/MATLAB Function2'
//  '<S577>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Sample and Hold'
//  '<S578>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function'
//  '<S579>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function1'
//  '<S580>' : 'Aenea_model/AUTOPILOT_MODEL/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti/MATLAB Function'
//  '<S581>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280'
//  '<S582>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Compare To Constant'
//  '<S583>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Counter Limited'
//  '<S584>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/GPS_Venus'
//  '<S585>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/MTi'
//  '<S586>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Pitot_Lidar'
//  '<S587>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Dynamic rate limiter'
//  '<S588>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Execution_loop'
//  '<S589>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/MATLAB Function'
//  '<S590>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Subsystem'
//  '<S591>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
//  '<S592>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/BMP_280/Subsystem/Subsystem1'
//  '<S593>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Counter Limited/Increment Real World'
//  '<S594>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/Counter Limited/Wrap To Zero'
//  '<S595>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/GPS_Venus/Subsystem2'
//  '<S596>' : 'Aenea_model/AUTOPILOT_MODEL/Misure Sensori/MTi/MATLAB Function1'
//  '<S597>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/AILERON'
//  '<S598>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/AILERON1'
//  '<S599>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/ELEVATOR'
//  '<S600>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/ELEVATOR1'
//  '<S601>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/RUDDER'
//  '<S602>' : 'Aenea_model/AUTOPILOT_MODEL/RADIOCOMANDO/THROTTLE'
//  '<S603>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/AILERON1'
//  '<S604>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/RUDDER6'
//  '<S605>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/THROTTLE1'
//  '<S606>' : 'Aenea_model/AUTOPILOT_MODEL/Servi/elevator'
//  '<S607>' : 'Aenea_model/LOG_DATA_MODEL/Compare To Constant'
//  '<S608>' : 'Aenea_model/LOG_DATA_MODEL/Counter Limited'
//  '<S609>' : 'Aenea_model/LOG_DATA_MODEL/LOG_BOOL_SIGNALS'
//  '<S610>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS'
//  '<S611>' : 'Aenea_model/LOG_DATA_MODEL/LOG_INT16_SIGNALS'
//  '<S612>' : 'Aenea_model/LOG_DATA_MODEL/LOG_INT32_SIGNALS'
//  '<S613>' : 'Aenea_model/LOG_DATA_MODEL/LOG_INT8_SIGNALS'
//  '<S614>' : 'Aenea_model/LOG_DATA_MODEL/LOG_SINGLE_SIGNALS'
//  '<S615>' : 'Aenea_model/LOG_DATA_MODEL/LOG_UINT16_SIGNALS'
//  '<S616>' : 'Aenea_model/LOG_DATA_MODEL/LOG_UINT32_SIGNALS'
//  '<S617>' : 'Aenea_model/LOG_DATA_MODEL/LOG_UINT8_SIGNALS'
//  '<S618>' : 'Aenea_model/LOG_DATA_MODEL/Counter Limited/Increment Real World'
//  '<S619>' : 'Aenea_model/LOG_DATA_MODEL/Counter Limited/Wrap To Zero'
//  '<S620>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS/Radians to Degrees'
//  '<S621>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS/Radians to Degrees1'
//  '<S622>' : 'Aenea_model/LOG_DATA_MODEL/LOG_DOUBLE_SIGNALS/Subsystem'

#endif                                 // RTW_HEADER_Aenea_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
