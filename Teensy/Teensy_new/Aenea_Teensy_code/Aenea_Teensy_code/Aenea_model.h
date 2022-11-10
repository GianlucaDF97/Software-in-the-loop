//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.h
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.35
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Nov 10 14:41:53 2022
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Aenea_model_h_
#define RTW_HEADER_Aenea_model_h_
#include <cmath>
#include <cfloat>
#include <cstring>
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Aenea_model_types.h"

// Shared type includes
#include "multiword_types.h"
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

// Block states (default storage) for system '<S405>/Resettable Subsystem'
typedef struct {
  real_T Memory_PreviousInput;         // '<S416>/Memory'
} DW_ResettableSubsystem_Aenea__T;

// Zero-crossing (trigger) state for system '<S405>/Resettable Subsystem'
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_k;// '<S405>/Resettable Subsystem'
} ZCE_ResettableSubsystem_Aenea_T;

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
  real_T WP_db_param[42];              // '<S1>/Data Tversion'
  uint8_T buffer[300];                 // '<S1>/MATLAB Function2'
  real_T y[21];                        // '<S553>/MATLAB Function2'
  real_T x_est[18];
  real_T klm_gain_c[18];
  real_T a[16];
  real_T A[16];
  real_T TmpSignalConversionAtSFunct[14];// '<S553>/MATLAB Function2'
  uint8_T messaggio_h[100];            // '<S1>/MATLAB Function4'
  uint8_T messaggio_2[100];            // '<S1>/MATLAB Function4'
  boolean_T x[100];
  real_T residui[11];                  // '<S552>/DEFINITIVA'
  real_T dv1[11];
  char_T s1_data[81];
  real_T UnitDelay[9];                 // '<S566>/Unit Delay'
  real_T ComplextoRealImag[9];         // '<S576>/Complex to Real-Imag'
  real_T In[21];                       // '<S560>/In'
  real_T DataTypeConversion1[9];       // '<S5>/Data Type Conversion1'
  real_T aterra_tmp[9];
  int32_T ipiv[11];
  real_T x_new[4];
  real_T aterra[3];
  uint128m_T r;
  boolean_T NOT[14];                   // '<S558>/NOT'
  uint96m_T r1;
  uint96m_T r2;
  real_T Lat_K;                        // '<S552>/DEFINITIVA'
  real_T Long_K;                       // '<S552>/DEFINITIVA'
  real_T h_K;                          // '<S552>/DEFINITIVA'
  real_T v_K;                          // '<S552>/DEFINITIVA'
  real_T V_goHome;                     // '<S439>/GO_HOME'
  real_T h_goHome;                     // '<S439>/GO_HOME'
  real_T VELOCITA;                     // '<S438>/saturatore V'
  real_T QUOTA;                        // '<S438>/WAYPOINTS'
  real_T velocita; // '<S437>/Switch di selezione  Task - Waypoint navigation5'
  real_T QUOTA_e;  // '<S437>/Switch di selezione  Task - Waypoint navigation4'
  real_T In_c[2];                      // '<S462>/In'
  real_T Constant1;                    // '<S452>/Constant1'
  real_T Sum2;                         // '<S452>/Sum2'
  real_T maneuver_selector;            // '<S437>/Chart1'
  real_T trig_approach;                // '<S437>/Chart1'
  real_T trig_flare;                   // '<S437>/Chart1'
  real_T approach_selector;            // '<S437>/Chart1'
  real_T Multiply;                     // '<S448>/Multiply'
  real_T Constant1_h;                  // '<S448>/Constant1'
  real_T x_f_out;                      // '<S448>/MATLAB Function'
  real_T h_f_out;                      // '<S448>/MATLAB Function'
  real_T k_x_out;                      // '<S448>/MATLAB Function'
  real_T h_c_out;                      // '<S448>/MATLAB Function'
  real_T no_solution;                  // '<S448>/MATLAB Function'
  real_T V_vett;                       // '<S436>/VETTORIALE'
  real_T h_vett;                       // '<S436>/VETTORIALE'
  real_T Fase_ATO;                     // '<S435>/Chart1'
  real_T manetta_ref;                  // '<S435>/Chart1'
  real_T h_ref;                        // '<S435>/Chart1'
  real_T Tas_ref;                      // '<S435>/Chart1'
  real_T psi_ref_selector;             // '<S435>/Chart1'
  real_T theta_ground_selector;        // '<S435>/Chart1'
  real_T Switch;                       // '<S431>/Switch'
  real_T Switch_a;                     // '<S417>/Switch'
  real_T switch_manetta;               // '<S33>/ STATI'
  real_T switch_equilibratore;         // '<S33>/ STATI'
  real_T switch_alettoni;              // '<S33>/ STATI'
  real_T switch_timone;                // '<S33>/ STATI'
  real_T throttle_safe;                // '<S33>/ STATI'
  real_T modo;                         // '<S33>/ STATI'
  real_T OutportBufferForOut1;         // '<S298>/Constant'
  real32_T ByteUnpack_o2[9];           // '<S566>/Byte Unpack'
  real32_T ByteReversal[9];            // '<S566>/Byte Reversal'
  uint8_T SFunctionBuilder1[41];       // '<S566>/S-Function Builder1'
  real_T num_254;
  real_T Delta_clock;
  real_T a_k;
  real_T psi_ref;
  real_T dist;
  real_T angoloWP;
  real_T psi_ref_pre;
  real_T smax;
  real_T Product1;                     // '<S554>/Product1'
  real_T V_est;                        // '<S4>/Multiply3'
  real_T Sum_fj;                       // '<S433>/Sum'
  real_T Gain_m5;                      // '<S539>/Gain'
  real_T Gain_ll;                      // '<S540>/Gain'
  real_T Switch1_g;                    // '<S22>/Switch1'
  real_T Wp_selector;
  real_T Vec_selector;
  real_T Ato_selector;
  real_T Al_selector;
  real_T psi_ref_tmp;
  real_T psi_ref_tmp_tmp_tmp;
  real_T psi_ref_tmp_tmp;
  real_T temp;
  real_T smax_c;
  real_T y_b;
  real_T scanned1;
  real_T Y_tmp;
  real_T Y_tmp_p;
  real_T Y_tmp_c;
  real_T Y_tmp_f;
  real_T Y_tmp_g;
  real_T scanned1_g;
  real_T scanned2;
  real_T scanned1_m;
  real_T scanned2_n;
  real_T scanned1_p;
  int8_T p[4];
  int8_T ipiv_l[4];
  real32_T DataTypeConversion3;        // '<S568>/Data Type Conversion3'
  real32_T SFunctionBuilder_o1;        // '<S568>/S-Function Builder'
  real32_T SFunctionBuilder_o2;        // '<S568>/S-Function Builder'
  real32_T SFunctionBuilder_o3;        // '<S568>/S-Function Builder'
  uint16_T ByteUnpack[8];              // '<S564>/Byte Unpack'
  real32_T f;
  int32_T caso;
  int32_T tolleranza_distWP_fut;
  int32_T ix;
  int32_T d_k;
  int32_T c_ix;
  int32_T e;
  int32_T ijA;
  int32_T Switch_j;                    // '<S553>/Switch'
  int32_T i;
  int32_T i_d;
  uint32_T qY;
  ZCEventType zcEvent;
  uint8_T ByteUnpack_o1[4];            // '<S566>/Byte Unpack'
  uint8_T ByteUnpack_o3;               // '<S566>/Byte Unpack'
  boolean_T HitCrossing;               // '<S246>/Hit  Crossing'
} B_Aenea_model_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE[9];          // '<S566>/Unit Delay'
  real_T UnitDelay1_DSTATE;            // '<S564>/Unit Delay1'
  real_T UnitDelay_DSTATE_c;           // '<S554>/Unit Delay'
  real_T Delay_DSTATE;                 // '<S245>/Delay'
  real_T Integrator_DSTATE;            // '<S280>/Integrator'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S302>/Discrete-Time Integrator'
  real_T DelayInput2_DSTATE;           // '<S567>/Delay Input2'
  real_T DiscreteTimeIntegrator_DSTATE_j;// '<S448>/Discrete-Time Integrator'
  real_T Memory_PreviousInput[14];     // '<S558>/Memory'
  real_T Memory_PreviousInput_o[14];   // '<S557>/Memory'
  real_T Memory1_PreviousInput;        // '<S22>/Memory1'
  volatile real_T RateTransition_Buffer0;// '<S22>/Rate Transition'
  real_T Memory2_PreviousInput;        // '<S22>/Memory2'
  real_T P_ref;                        // '<S564>/MATLAB Function'
  real_T rl_up;                        // '<S564>/MATLAB Function'
  real_T rl_dw;                        // '<S564>/MATLAB Function'
  real_T x_prd[18];                    // '<S552>/DEFINITIVA'
  real_T p_prd[324];                   // '<S552>/DEFINITIVA'
  real_T flag;                         // '<S439>/GO_HOME'
  real_T Memory4_PreviousInput;        // '<S438>/Memory4'
  real_T flag_f;                       // '<S438>/WAYPOINTS'
  real_T lat1;                         // '<S438>/WAYPOINTS'
  real_T long1;                        // '<S438>/WAYPOINTS'
  real_T Memory7_PreviousInput;        // '<S437>/Memory7'
  real_T Memory5_PreviousInput;        // '<S437>/Memory5'
  real_T Memory1_PreviousInput_f;      // '<S437>/Memory1'
  real_T Memory2_PreviousInput_e;      // '<S437>/Memory2'
  real_T x[4];                         // '<S448>/MATLAB Function'
  real_T cycle_count;                  // '<S448>/MATLAB Function'
  real_T eps[4];                       // '<S448>/MATLAB Function'
  real_T flag_a;                       // '<S437>/ALLINEAMENTO'
  real_T Memory3_PreviousInput;        // '<S436>/Memory3'
  real_T V_ref;                        // '<S436>/VETTORIALE'
  real_T ALT_ref;                      // '<S436>/VETTORIALE'
  real_T Memory_PreviousInput_p;       // '<S435>/Memory'
  real_T Memory1_PreviousInput_e;      // '<S435>/Memory1'
  real_T alarm;                        // '<S412>/MATLAB Function1'
  real_T Memory_PreviousInput_nq;      // '<S433>/Memory'
  real_T mess_len;                     // '<S1>/MATLAB Function4'
  real_T test1;                        // '<S1>/MATLAB Function1'
  real32_T riferimenti[16];            // '<S1>/MATLAB Function1'
  real32_T WP_dbP[42];                 // '<S1>/MATLAB Function1'
  real32_T WP_dbP_AL[42];              // '<S1>/MATLAB Function1'
  int_T HitCrossing_MODE;              // '<S246>/Hit  Crossing'
  uint16_T counter;                    // '<S1>/MATLAB Function3'
  uint16_T WP_dbI[36];                 // '<S1>/MATLAB Function1'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S302>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_o;// '<S448>/Discrete-Time Integrator'
  uint8_T Memory4_PreviousInput_j[300];// '<S1>/Memory4'
  uint8_T Memory5_PreviousInput_b[100];// '<S1>/Memory5'
  uint8_T Memory2_PreviousInput_d[9];  // '<S1>/Memory2'
  uint8_T is_active_c10_Aenea_model;   // '<S437>/Chart1'
  uint8_T is_c10_Aenea_model;          // '<S437>/Chart1'
  uint8_T Memory1_PreviousInput_k;     // '<S436>/Memory1'
  uint8_T Memory2_PreviousInput_d2;    // '<S436>/Memory2'
  uint8_T Memory6_PreviousInput;       // '<S436>/Memory6'
  uint8_T is_active_c1_Aenea_model;    // '<S435>/Chart1'
  uint8_T is_c1_Aenea_model;           // '<S435>/Chart1'
  uint8_T temporalCounter_i1;          // '<S435>/Chart1'
  uint8_T is_active_c21_Aenea_model;   // '<S34>/Chart'
  uint8_T is_c21_Aenea_model;          // '<S34>/Chart'
  uint8_T is_active_c26_Aenea_model;   // '<S33>/ STATI'
  uint8_T is_c26_Aenea_model;          // '<S33>/ STATI'
  uint8_T is_AUTOMATICA;               // '<S33>/ STATI'
  uint8_T is_active_c23_Aenea_model;
                                   // '<S35>/SELEZIONE MODALITA'  HOLD//SELECT'
  uint8_T is_c23_Aenea_model;      // '<S35>/SELEZIONE MODALITA'  HOLD//SELECT'
  uint8_T message_g[100];              // '<S1>/MATLAB Function4'
  uint8_T counter_j;                   // '<S1>/MATLAB Function4'
  boolean_T x_prd_not_empty;           // '<S552>/DEFINITIVA'
  boolean_T x_not_empty;               // '<S448>/MATLAB Function'
  boolean_T x_new_not_empty;           // '<S448>/MATLAB Function'
  boolean_T cycle_count_not_empty;     // '<S448>/MATLAB Function'
  boolean_T eps_not_empty;             // '<S448>/MATLAB Function'
  boolean_T Tf_not_empty;              // '<S407>/MATLAB Function1'
  boolean_T Interr_parz;               // '<S1>/MATLAB Function4'
  boolean_T WP_dbP_not_empty;          // '<S1>/MATLAB Function1'
  boolean_T WP_dbP_AL_not_empty;       // '<S1>/MATLAB Function1'
  boolean_T Enabled_MODE;              // '<S429>/Enabled '
  boolean_T Enabled_MODE_i;            // '<S421>/Enabled '
  boolean_T Enabled_MODE_b;            // '<S420>/Enabled '
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem_j;// '<S406>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem;// '<S405>/Resettable Subsystem' 
} DW_Aenea_model_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    // '<S246>/Hit  Crossing'
  ZCSigState SampleandHold_Trig_ZCE;   // '<S553>/Sample and Hold'
  ZCSigState SampleandHold_Trig_ZCE_l; // '<S437>/Sample and Hold'
  ZCSigState SampleandHold1_Trig_ZCE;  // '<S435>/Sample and Hold1'
  ZCSigState SampleandHold_Trig_ZCE_a; // '<S435>/Sample and Hold'
  ZCSigState ResettableSubsystem_Reset_ZCE;// '<S429>/Resettable Subsystem'
  ZCSigState ResettableSubsystem_Reset_ZCE_b;// '<S421>/Resettable Subsystem'
  ZCSigState ResettableSubsystem_Reset_ZCE_l;// '<S420>/Resettable Subsystem'
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem_j;// '<S406>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem;// '<S405>/Resettable Subsystem' 
  ZCSigState EnabledSubsystem_Trig_ZCE;// '<S246>/Enabled Subsystem'
} PrevZCX_Aenea_model_T;

// Invariant block signals (default storage)
typedef const struct tag_ConstB_Aenea_model_T {
  real_T Go_Home;                      // '<S7>/Switch'
  real_T DataTypeConversion5;          // '<S7>/Data Type Conversion5'
  real_T DataTypeConversion13;         // '<S7>/Data Type Conversion13'
  real_T DataTypeConversion14;         // '<S7>/Data Type Conversion14'
} ConstB_Aenea_model_T;

// Constant parameters (default storage)
typedef struct {
  // Expression: R1B
  //  Referenced by: '<S4>/Constant13'

  real_T Constant13_Value[11];

  // Expression: Q1B
  //  Referenced by: '<S4>/Constant16'

  real_T Constant16_Value[18];

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S1>/Constant2'

  uint8_T Constant2_Value_l[100];

  // Computed Parameter: registromemoria213_Value
  //  Referenced by: '<S564>/registro memoria2 13'

  uint8_T registromemoria213_Value[16];
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
      uint8_T TID[2];
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
//  Block '<S1>/Add' : Unused code path elimination
//  Block '<S1>/Constant' : Unused code path elimination
//  Block '<S1>/Constant7' : Unused code path elimination
//  Block '<S1>/Memory' : Unused code path elimination
//  Block '<S1>/Memory1' : Unused code path elimination
//  Block '<S1>/Memory3' : Unused code path elimination
//  Block '<S2>/Data Type Conversion' : Unused code path elimination
//  Block '<S2>/Data Type Conversion1' : Unused code path elimination
//  Block '<S2>/Data Type Conversion2' : Unused code path elimination
//  Block '<S13>/Data Type Conversion' : Unused code path elimination
//  Block '<S13>/Data Type Conversion1' : Unused code path elimination
//  Block '<S13>/Data Type Conversion2' : Unused code path elimination
//  Block '<S13>/Gain' : Unused code path elimination
//  Block '<S13>/Gain1' : Unused code path elimination
//  Block '<S13>/Gain2' : Unused code path elimination
//  Block '<S13>/alt_r' : Unused code path elimination
//  Block '<S13>/vel y' : Unused code path elimination
//  Block '<S14>/Constant' : Unused code path elimination
//  Block '<S14>/Data Type Conversion' : Unused code path elimination
//  Block '<S14>/Data Type Conversion1' : Unused code path elimination
//  Block '<S14>/Type fixed_wing Autopilot generic' : Unused code path elimination
//  Block '<S15>/Constant' : Unused code path elimination
//  Block '<S15>/Constant1' : Unused code path elimination
//  Block '<S15>/Constant2' : Unused code path elimination
//  Block '<S15>/Data Type Conversion' : Unused code path elimination
//  Block '<S15>/Data Type Conversion1' : Unused code path elimination
//  Block '<S15>/Gain' : Unused code path elimination
//  Block '<S16>/Data Type Conversion3' : Unused code path elimination
//  Block '<S16>/Gain' : Unused code path elimination
//  Block '<S22>/Add' : Unused code path elimination
//  Block '<S22>/Constant' : Unused code path elimination
//  Block '<S22>/Constant1' : Unused code path elimination
//  Block '<S22>/Memory' : Unused code path elimination
//  Block '<S2>/Pa to hPa' : Unused code path elimination
//  Block '<S2>/Pa to hPa1' : Unused code path elimination
//  Block '<S17>/Constant' : Unused code path elimination
//  Block '<S17>/Constant1' : Unused code path elimination
//  Block '<S24>/Constant2' : Unused code path elimination
//  Block '<S24>/Gain2' : Unused code path elimination
//  Block '<S25>/Gain' : Unused code path elimination
//  Block '<S26>/Gain' : Unused code path elimination
//  Block '<S27>/Gain' : Unused code path elimination
//  Block '<S24>/Sum' : Unused code path elimination
//  Block '<S24>/Sum1' : Unused code path elimination
//  Block '<S24>/Sum2' : Unused code path elimination
//  Block '<S17>/Data Type Conversion1' : Unused code path elimination
//  Block '<S17>/Gain' : Unused code path elimination
//  Block '<S17>/Saturation' : Unused code path elimination
//  Block '<S18>/ ' : Unused code path elimination
//  Block '<S18>/Data Type Conversion' : Unused code path elimination
//  Block '<S18>/Data Type Conversion1' : Unused code path elimination
//  Block '<S18>/Data Type Conversion2' : Unused code path elimination
//  Block '<S18>/Data Type Conversion3' : Unused code path elimination
//  Block '<S18>/Data Type Conversion4' : Unused code path elimination
//  Block '<S18>/Gain' : Unused code path elimination
//  Block '<S18>/Gain1' : Unused code path elimination
//  Block '<S18>/Gain2' : Unused code path elimination
//  Block '<S18>/load uint16' : Unused code path elimination
//  Block '<S18>/onboard_control_sensor_present uint32' : Unused code path elimination
//  Block '<S19>/Data Type Conversion' : Unused code path elimination
//  Block '<S19>/Data Type Conversion1' : Unused code path elimination
//  Block '<S19>/Data Type Conversion2' : Unused code path elimination
//  Block '<S28>/Gain' : Unused code path elimination
//  Block '<S19>/USCITA PERCENTUALE' : Unused code path elimination
//  Block '<S19>/airspeed groundspeed alt climb1' : Unused code path elimination
//  Block '<S29>/Abs' : Unused code path elimination
//  Block '<S29>/Constant2' : Unused code path elimination
//  Block '<S29>/Sum' : Unused code path elimination
//  Block '<S29>/Switch2' : Unused code path elimination
//  Block '<S38>/Constant1' : Unused code path elimination
//  Block '<S38>/Constant10' : Unused code path elimination
//  Block '<S38>/Constant11' : Unused code path elimination
//  Block '<S38>/Constant12' : Unused code path elimination
//  Block '<S38>/Constant13' : Unused code path elimination
//  Block '<S38>/Constant14' : Unused code path elimination
//  Block '<S38>/Constant15' : Unused code path elimination
//  Block '<S38>/Constant2' : Unused code path elimination
//  Block '<S38>/Constant3' : Unused code path elimination
//  Block '<S38>/Constant5' : Unused code path elimination
//  Block '<S38>/Constant7' : Unused code path elimination
//  Block '<S38>/Constant9' : Unused code path elimination
//  Block '<S38>/Multiport Switch' : Unused code path elimination
//  Block '<S38>/Multiport Switch1' : Unused code path elimination
//  Block '<S38>/Multiport Switch2' : Unused code path elimination
//  Block '<S69>/DProd Out' : Unused code path elimination
//  Block '<S70>/Filter' : Unused code path elimination
//  Block '<S70>/SumD' : Unused code path elimination
//  Block '<S72>/IProd Out' : Unused code path elimination
//  Block '<S75>/Integrator' : Unused code path elimination
//  Block '<S78>/NProd Out' : Unused code path elimination
//  Block '<S80>/PProd Out' : Unused code path elimination
//  Block '<S84>/Sum' : Unused code path elimination
//  Block '<S86>/Kt' : Unused code path elimination
//  Block '<S86>/SumI3' : Unused code path elimination
//  Block '<S87>/SumI1' : Unused code path elimination
//  Block '<S117>/DProd Out' : Unused code path elimination
//  Block '<S118>/Filter' : Unused code path elimination
//  Block '<S118>/SumD' : Unused code path elimination
//  Block '<S120>/IProd Out' : Unused code path elimination
//  Block '<S123>/Integrator' : Unused code path elimination
//  Block '<S126>/NProd Out' : Unused code path elimination
//  Block '<S128>/PProd Out' : Unused code path elimination
//  Block '<S132>/Sum' : Unused code path elimination
//  Block '<S134>/Kt' : Unused code path elimination
//  Block '<S134>/SumI3' : Unused code path elimination
//  Block '<S135>/SumI1' : Unused code path elimination
//  Block '<S168>/IProd Out' : Unused code path elimination
//  Block '<S171>/Integrator' : Unused code path elimination
//  Block '<S176>/PProd Out' : Unused code path elimination
//  Block '<S180>/Sum' : Unused code path elimination
//  Block '<S182>/Kt' : Unused code path elimination
//  Block '<S182>/SumI3' : Unused code path elimination
//  Block '<S183>/SumI1' : Unused code path elimination
//  Block '<S38>/Saturation' : Unused code path elimination
//  Block '<S38>/Sum1' : Unused code path elimination
//  Block '<S38>/Sum2' : Unused code path elimination
//  Block '<S38>/Sum4' : Unused code path elimination
//  Block '<S38>/Switch auto-manual' : Unused code path elimination
//  Block '<S38>/Switch maneuver' : Unused code path elimination
//  Block '<S38>/Switch rc saturata' : Unused code path elimination
//  Block '<S38>/n-D Lookup Table' : Unused code path elimination
//  Block '<S35>/Kp' : Unused code path elimination
//  Block '<S40>/Constant' : Unused code path elimination
//  Block '<S40>/Lookup Table2' : Unused code path elimination
//  Block '<S188>/Data Type Duplicate' : Unused code path elimination
//  Block '<S188>/Data Type Propagation' : Unused code path elimination
//  Block '<S188>/LowerRelop1' : Unused code path elimination
//  Block '<S188>/Switch' : Unused code path elimination
//  Block '<S188>/Switch2' : Unused code path elimination
//  Block '<S188>/UpperRelop' : Unused code path elimination
//  Block '<S35>/Switch HOLD//SELECT' : Unused code path elimination
//  Block '<S189>/Constant3' : Unused code path elimination
//  Block '<S189>/Constant4' : Unused code path elimination
//  Block '<S189>/Multiport Switch2' : Unused code path elimination
//  Block '<S189>/Multiport Switch3' : Unused code path elimination
//  Block '<S189>/Switch3' : Unused code path elimination
//  Block '<S189>/Switch4' : Unused code path elimination
//  Block '<S36>/Constant' : Unused code path elimination
//  Block '<S36>/Constant2' : Unused code path elimination
//  Block '<S216>/AND3' : Unused code path elimination
//  Block '<S216>/Constant1' : Unused code path elimination
//  Block '<S216>/DataTypeConv1' : Unused code path elimination
//  Block '<S216>/DataTypeConv2' : Unused code path elimination
//  Block '<S218>/DeadZone' : Unused code path elimination
//  Block '<S216>/Equal1' : Unused code path elimination
//  Block '<S216>/NotEqual' : Unused code path elimination
//  Block '<S216>/SignPreIntegrator' : Unused code path elimination
//  Block '<S216>/SignPreSat' : Unused code path elimination
//  Block '<S216>/Switch' : Unused code path elimination
//  Block '<S216>/ZeroGain' : Unused code path elimination
//  Block '<S219>/DProd Out' : Unused code path elimination
//  Block '<S220>/Filter' : Unused code path elimination
//  Block '<S220>/SumD' : Unused code path elimination
//  Block '<S222>/IProd Out' : Unused code path elimination
//  Block '<S225>/Integrator' : Unused code path elimination
//  Block '<S228>/NProd Out' : Unused code path elimination
//  Block '<S230>/PProd Out' : Unused code path elimination
//  Block '<S232>/Saturation' : Unused code path elimination
//  Block '<S234>/Sum' : Unused code path elimination
//  Block '<S236>/Kt' : Unused code path elimination
//  Block '<S236>/SumI3' : Unused code path elimination
//  Block '<S237>/SumI1' : Unused code path elimination
//  Block '<S36>/Switch' : Unused code path elimination
//  Block '<S36>/Switch auto-manual' : Unused code path elimination
//  Block '<S191>/Constant' : Unused code path elimination
//  Block '<S191>/Constant1' : Unused code path elimination
//  Block '<S191>/Constant2' : Unused code path elimination
//  Block '<S242>/Gain1' : Unused code path elimination
//  Block '<S191>/Math Function' : Unused code path elimination
//  Block '<S243>/Gain' : Unused code path elimination
//  Block '<S191>/Sum' : Unused code path elimination
//  Block '<S191>/Sum1' : Unused code path elimination
//  Block '<S191>/Sum2' : Unused code path elimination
//  Block '<S191>/Switch' : Unused code path elimination
//  Block '<S191>/Switch1' : Unused code path elimination
//  Block '<S31>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
//  Block '<S31>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
//  Block '<S32>/  CONTROLLO     IMBARDATA      INVERSA' : Unused code path elimination
//  Block '<S299>/Abs' : Unused code path elimination
//  Block '<S299>/Abs1' : Unused code path elimination
//  Block '<S299>/Constant1' : Unused code path elimination
//  Block '<S299>/Constant2' : Unused code path elimination
//  Block '<S299>/Constant3' : Unused code path elimination
//  Block '<S299>/Gain' : Unused code path elimination
//  Block '<S330>/Kb' : Unused code path elimination
//  Block '<S330>/SumI2' : Unused code path elimination
//  Block '<S330>/SumI4' : Unused code path elimination
//  Block '<S334>/IProd Out' : Unused code path elimination
//  Block '<S337>/Integrator' : Unused code path elimination
//  Block '<S342>/PProd Out' : Unused code path elimination
//  Block '<S344>/Saturation' : Unused code path elimination
//  Block '<S346>/Sum' : Unused code path elimination
//  Block '<S348>/Kt' : Unused code path elimination
//  Block '<S348>/SumI3' : Unused code path elimination
//  Block '<S349>/SumI1' : Unused code path elimination
//  Block '<S299>/Product3' : Unused code path elimination
//  Block '<S299>/Product4' : Unused code path elimination
//  Block '<S299>/Product5' : Unused code path elimination
//  Block '<S299>/Sum' : Unused code path elimination
//  Block '<S299>/Sum2' : Unused code path elimination
//  Block '<S299>/Sum3' : Unused code path elimination
//  Block '<S299>/Switch  2' : Unused code path elimination
//  Block '<S299>/Switch 1' : Unused code path elimination
//  Block '<S299>/Switch Bumpless 2' : Unused code path elimination
//  Block '<S299>/Trigonometric Function' : Unused code path elimination
//  Block '<S304>/Constant5' : Unused code path elimination
//  Block '<S304>/Multiport Switch2' : Unused code path elimination
//  Block '<S304>/Switch1' : Unused code path elimination
//  Block '<S354>/Gain1' : Unused code path elimination
//  Block '<S305>/Multiport Switch1' : Unused code path elimination
//  Block '<S305>/Multiport Switch2' : Unused code path elimination
//  Block '<S299>/saturatore E2' : Unused code path elimination
//  Block '<S300>/Constant1' : Unused code path elimination
//  Block '<S300>/Constant3' : Unused code path elimination
//  Block '<S380>/Kb' : Unused code path elimination
//  Block '<S380>/SumI2' : Unused code path elimination
//  Block '<S380>/SumI4' : Unused code path elimination
//  Block '<S384>/IProd Out' : Unused code path elimination
//  Block '<S387>/Integrator' : Unused code path elimination
//  Block '<S392>/PProd Out' : Unused code path elimination
//  Block '<S394>/Saturation' : Unused code path elimination
//  Block '<S396>/Sum' : Unused code path elimination
//  Block '<S398>/Kt' : Unused code path elimination
//  Block '<S398>/SumI3' : Unused code path elimination
//  Block '<S399>/SumI1' : Unused code path elimination
//  Block '<S300>/Product3' : Unused code path elimination
//  Block '<S300>/Sum' : Unused code path elimination
//  Block '<S300>/Sum2' : Unused code path elimination
//  Block '<S300>/Switch Bumpless 1' : Unused code path elimination
//  Block '<S301>/Discrete Washout Filter' : Unused code path elimination
//  Block '<S32>/Gain' : Unused code path elimination
//  Block '<S32>/Gain1' : Unused code path elimination
//  Block '<S32>/Gain2' : Unused code path elimination
//  Block '<S32>/Gain3' : Unused code path elimination
//  Block '<S32>/Product' : Unused code path elimination
//  Block '<S32>/Sum1' : Unused code path elimination
//  Block '<S32>/Sum2' : Unused code path elimination
//  Block '<S32>/Sum5' : Unused code path elimination
//  Block '<S32>/Sum9' : Unused code path elimination
//  Block '<S32>/Switch Bumpless 1' : Unused code path elimination
//  Block '<S32>/Switch Bumpless 3' : Unused code path elimination
//  Block '<S32>/Switch Bumpless 4' : Unused code path elimination
//  Block '<S32>/Switch Bumpless 5' : Unused code path elimination
//  Block '<S32>/Switch Bumpless 6' : Unused code path elimination
//  Block '<S32>/Switch Bumpless 7' : Unused code path elimination
//  Block '<S32>/r_rif' : Unused code path elimination
//  Block '<S32>/saturatore A' : Unused code path elimination
//  Block '<S32>/saturatore A1' : Unused code path elimination
//  Block '<S32>/saturatore R' : Unused code path elimination
//  Block '<S405>/Display' : Unused code path elimination
//  Block '<S405>/Display1' : Unused code path elimination
//  Block '<S423>/Constant' : Unused code path elimination
//  Block '<S423>/Constant1' : Unused code path elimination
//  Block '<S423>/Switch' : Unused code path elimination
//  Block '<S425>/Constant4' : Unused code path elimination
//  Block '<S425>/Memory' : Unused code path elimination
//  Block '<S425>/Sum' : Unused code path elimination
//  Block '<S426>/Constant' : Unused code path elimination
//  Block '<S426>/Constant1' : Unused code path elimination
//  Block '<S426>/Switch' : Unused code path elimination
//  Block '<S428>/Constant4' : Unused code path elimination
//  Block '<S428>/Memory' : Unused code path elimination
//  Block '<S428>/Sum' : Unused code path elimination
//  Block '<S407>/Switch' : Unused code path elimination
//  Block '<S33>/Scope1' : Unused code path elimination
//  Block '<S413>/Abs2' : Unused code path elimination
//  Block '<S448>/Multiply1' : Unused code path elimination
//  Block '<S437>/Constant1' : Unused code path elimination
//  Block '<S437>/Constant7' : Unused code path elimination
//  Block '<S452>/Exp1' : Unused code path elimination
//  Block '<S452>/Gain1' : Unused code path elimination
//  Block '<S452>/Gain2' : Unused code path elimination
//  Block '<S452>/Multiply2' : Unused code path elimination
//  Block '<S452>/Multiply3' : Unused code path elimination
//  Block '<S452>/Multiply4' : Unused code path elimination
//  Block '<S452>/Sum3' : Unused code path elimination
//  Block '<S452>/Sum4' : Unused code path elimination
//  Block '<S453>/Gain1' : Unused code path elimination
//  Block '<S498>/IProd Out' : Unused code path elimination
//  Block '<S501>/Integrator' : Unused code path elimination
//  Block '<S506>/PProd Out' : Unused code path elimination
//  Block '<S510>/Sum' : Unused code path elimination
//  Block '<S469>/Gain' : Unused code path elimination
//  Block '<S453>/Sum3' : Unused code path elimination
//  Block '<S453>/psi ref gain' : Unused code path elimination
//  Block '<S453>/psi ref gain1' : Unused code path elimination
//  Block '<S521>/Sum3' : Unused code path elimination
//  Block '<S521>/x*sin' : Unused code path elimination
//  Block '<S521>/y*cos' : Unused code path elimination
//  Block '<S437>/Relational Operator' : Unused code path elimination
//  Block '<S437>/Switch' : Unused code path elimination
//  Block '<S437>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
//  Block '<S437>/Switch1' : Unused code path elimination
//  Block '<S438>/saturatore V1' : Unused code path elimination
//  Block '<S34>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
//  Block '<S34>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
//  Block '<Root>/Data Type Conversion1' : Unused code path elimination
//  Block '<Root>/Data Type Conversion2' : Unused code path elimination
//  Block '<S4>/Constant2' : Unused code path elimination
//  Block '<S4>/Constant6' : Unused code path elimination
//  Block '<S4>/Constant7' : Unused code path elimination
//  Block '<S4>/Data Type Conversion1' : Unused code path elimination
//  Block '<S4>/dp diff raw' : Unused code path elimination
//  Block '<Root>/Memory' : Unused code path elimination
//  Block '<S567>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S571>/Data Type Duplicate' : Unused code path elimination
//  Block '<S571>/Data Type Propagation' : Unused code path elimination
//  Block '<S570>/Constant' : Unused code path elimination
//  Block '<S570>/NotEqual' : Unused code path elimination
//  Block '<S570>/Switch' : Unused code path elimination
//  Block '<S570>/Switch1' : Unused code path elimination
//  Block '<S5>/Constant' : Unused code path elimination
//  Block '<S573>/Constant' : Unused code path elimination
//  Block '<S573>/Constant1' : Unused code path elimination
//  Block '<S573>/Constant2' : Unused code path elimination
//  Block '<S573>/Constant3' : Unused code path elimination
//  Block '<S573>/Equal' : Unused code path elimination
//  Block '<S573>/Equal1' : Unused code path elimination
//  Block '<S573>/Equal2' : Unused code path elimination
//  Block '<S573>/OR' : Unused code path elimination
//  Block '<S573>/Switch' : Unused code path elimination
//  Block '<S565>/Sum' : Unused code path elimination
//  Block '<S6>/Gain3' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless AP quota' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless controllore beccheggio' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless controllore imbardata' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless controllore rollio' : Unused code path elimination
//  Block '<S6>/K controllo imbardata inversa' : Unused code path elimination
//  Block '<S6>/Ki AP quota Select' : Unused code path elimination
//  Block '<S6>/Ki AP rotta1' : Unused code path elimination
//  Block '<S6>/Ki controllore  beccheggio1' : Unused code path elimination
//  Block '<S6>/Ki controllore  rollio3' : Unused code path elimination
//  Block '<S6>/Kp AP quota Select' : Unused code path elimination
//  Block '<S6>/Kp AP rotta' : Unused code path elimination
//  Block '<S6>/Kp controllore  rollio3' : Unused code path elimination
//  Block '<S6>/Kp controllore  velocità rollio3' : Unused code path elimination
//  Block '<S6>/Kp controllore beccheggio1' : Unused code path elimination
//  Block '<S6>/Kp controllore imbardata' : Unused code path elimination
//  Block '<S6>/Kp controllore velocità beccheggio1' : Unused code path elimination
//  Block '<S6>/Saturation' : Unused code path elimination
//  Block '<S6>/n-D Lookup Table' : Unused code path elimination
//  Block '<S579>/Constant8' : Unused code path elimination
//  Block '<S579>/Constant9' : Unused code path elimination
//  Block '<S579>/Divide' : Unused code path elimination
//  Block '<S579>/Gain' : Unused code path elimination
//  Block '<S579>/Multiply' : Unused code path elimination
//  Block '<S579>/Saturation' : Unused code path elimination
//  Block '<S579>/Sum' : Unused code path elimination
//  Block '<S579>/Sum1' : Unused code path elimination
//  Block '<S579>/Sum2' : Unused code path elimination
//  Block '<S579>/Sum3' : Unused code path elimination
//  Block '<S7>/Constant4' : Unused code path elimination
//  Block '<S7>/Data Type Conversion' : Unused code path elimination
//  Block '<S7>/Data Type Conversion1' : Unused code path elimination
//  Block '<S7>/Data Type Conversion10' : Unused code path elimination
//  Block '<S7>/Data Type Conversion11' : Unused code path elimination
//  Block '<S7>/Data Type Conversion15' : Unused code path elimination
//  Block '<S7>/Data Type Conversion16' : Unused code path elimination
//  Block '<S7>/Data Type Conversion17' : Unused code path elimination
//  Block '<S7>/Data Type Conversion18' : Unused code path elimination
//  Block '<S7>/Data Type Conversion19' : Unused code path elimination
//  Block '<S7>/Data Type Conversion2' : Unused code path elimination
//  Block '<S7>/Data Type Conversion20' : Unused code path elimination
//  Block '<S7>/Data Type Conversion21' : Unused code path elimination
//  Block '<S7>/Data Type Conversion3' : Unused code path elimination
//  Block '<S581>/Constant8' : Unused code path elimination
//  Block '<S581>/Constant9' : Unused code path elimination
//  Block '<S581>/Divide' : Unused code path elimination
//  Block '<S581>/Gain' : Unused code path elimination
//  Block '<S581>/Multiply' : Unused code path elimination
//  Block '<S581>/Saturation' : Unused code path elimination
//  Block '<S581>/Sum' : Unused code path elimination
//  Block '<S581>/Sum1' : Unused code path elimination
//  Block '<S581>/Sum2' : Unused code path elimination
//  Block '<S581>/Sum3' : Unused code path elimination
//  Block '<S582>/Constant8' : Unused code path elimination
//  Block '<S582>/Constant9' : Unused code path elimination
//  Block '<S582>/Divide' : Unused code path elimination
//  Block '<S582>/Multiply' : Unused code path elimination
//  Block '<S582>/Sum1' : Unused code path elimination
//  Block '<S582>/Sum2' : Unused code path elimination
//  Block '<S582>/Sum3' : Unused code path elimination
//  Block '<S582>/Sum4' : Unused code path elimination
//  Block '<Root>/SI UAV uint8' : Unused code path elimination
//  Block '<S584>/Constant' : Unused code path elimination
//  Block '<S584>/Constant1' : Unused code path elimination
//  Block '<S584>/Divide' : Unused code path elimination
//  Block '<S584>/Multiply' : Unused code path elimination
//  Block '<S584>/Sum' : Unused code path elimination
//  Block '<S584>/Sum1' : Unused code path elimination
//  Block '<S584>/Sum2' : Unused code path elimination
//  Block '<S584>/Sum3' : Unused code path elimination
//  Block '<S8>/Constant' : Unused code path elimination
//  Block '<S8>/Constant1' : Unused code path elimination
//  Block '<S8>/Constant2' : Unused code path elimination
//  Block '<S8>/Constant3' : Unused code path elimination
//  Block '<S8>/Constant4' : Unused code path elimination
//  Block '<S8>/Constant5' : Unused code path elimination
//  Block '<S8>/Constant6' : Unused code path elimination
//  Block '<S8>/Constant7' : Unused code path elimination
//  Block '<S8>/Data Type Conversion' : Unused code path elimination
//  Block '<S8>/Data Type Conversion1' : Unused code path elimination
//  Block '<S8>/Data Type Conversion10' : Unused code path elimination
//  Block '<S8>/Data Type Conversion11' : Unused code path elimination
//  Block '<S8>/Data Type Conversion2' : Unused code path elimination
//  Block '<S8>/Data Type Conversion3' : Unused code path elimination
//  Block '<S8>/Data Type Conversion4' : Unused code path elimination
//  Block '<S8>/Data Type Conversion5' : Unused code path elimination
//  Block '<S8>/Data Type Conversion6' : Unused code path elimination
//  Block '<S8>/Data Type Conversion7' : Unused code path elimination
//  Block '<S8>/Data Type Conversion8' : Unused code path elimination
//  Block '<S8>/Data Type Conversion9' : Unused code path elimination
//  Block '<S585>/Constant' : Unused code path elimination
//  Block '<S585>/Constant1' : Unused code path elimination
//  Block '<S585>/Divide' : Unused code path elimination
//  Block '<S585>/Multiply' : Unused code path elimination
//  Block '<S585>/Sum' : Unused code path elimination
//  Block '<S585>/Sum1' : Unused code path elimination
//  Block '<S585>/Sum2' : Unused code path elimination
//  Block '<S585>/Sum3' : Unused code path elimination
//  Block '<S586>/Multiply' : Unused code path elimination
//  Block '<S586>/Sum' : Unused code path elimination
//  Block '<S586>/Sum1' : Unused code path elimination
//  Block '<S587>/Constant' : Unused code path elimination
//  Block '<S587>/Constant1' : Unused code path elimination
//  Block '<S587>/Divide' : Unused code path elimination
//  Block '<S587>/Multiply' : Unused code path elimination
//  Block '<S587>/Sum' : Unused code path elimination
//  Block '<S587>/Sum1' : Unused code path elimination
//  Block '<S587>/Sum2' : Unused code path elimination
//  Block '<S587>/Sum3' : Unused code path elimination
//  Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S291>/Kt' : Eliminated nontunable gain of 1
//  Block '<S564>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S564>/Data Type Conversion1' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'Aenea_model/AIR RX'
//  '<S2>'   : 'Aenea_model/AIR TX'
//  '<S3>'   : 'Aenea_model/AUTOPILOTA'
//  '<S4>'   : 'Aenea_model/MISURE DA SENSORI  FILTRATE'
//  '<S5>'   : 'Aenea_model/Misure Sensori'
//  '<S6>'   : 'Aenea_model/PARAMETRI SISTEMA DI CONTROLLO'
//  '<S7>'   : 'Aenea_model/RADIOCOMANDO'
//  '<S8>'   : 'Aenea_model/Servi'
//  '<S9>'   : 'Aenea_model/AIR RX/MATLAB Function1'
//  '<S10>'  : 'Aenea_model/AIR RX/MATLAB Function2'
//  '<S11>'  : 'Aenea_model/AIR RX/MATLAB Function3'
//  '<S12>'  : 'Aenea_model/AIR RX/MATLAB Function4'
//  '<S13>'  : 'Aenea_model/AIR TX/GPS'
//  '<S14>'  : 'Aenea_model/AIR TX/Heartbeat'
//  '<S15>'  : 'Aenea_model/AIR TX/IMU & Attidude'
//  '<S16>'  : 'Aenea_model/AIR TX/If_subsystem'
//  '<S17>'  : 'Aenea_model/AIR TX/Servo'
//  '<S18>'  : 'Aenea_model/AIR TX/SystemStatus'
//  '<S19>'  : 'Aenea_model/AIR TX/VFR'
//  '<S20>'  : 'Aenea_model/AIR TX/Waypoints'
//  '<S21>'  : 'Aenea_model/AIR TX/Heartbeat/Alarm set'
//  '<S22>'  : 'Aenea_model/AIR TX/If_subsystem/Subsystem'
//  '<S23>'  : 'Aenea_model/AIR TX/If_subsystem/iflogic_function'
//  '<S24>'  : 'Aenea_model/AIR TX/Servo/Conversione'
//  '<S25>'  : 'Aenea_model/AIR TX/Servo/Conversione/Radians to Degrees1'
//  '<S26>'  : 'Aenea_model/AIR TX/Servo/Conversione/Radians to Degrees2'
//  '<S27>'  : 'Aenea_model/AIR TX/Servo/Conversione/Radians to Degrees3'
//  '<S28>'  : 'Aenea_model/AIR TX/VFR/Radians to Degrees'
//  '<S29>'  : 'Aenea_model/AIR TX/VFR/wrapTo360'
//  '<S30>'  : 'Aenea_model/AIR TX/Waypoints/MATLAB Function'
//  '<S31>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1'
//  '<S32>'  : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
//  '<S33>'  : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1'
//  '<S34>'  : 'Aenea_model/AUTOPILOTA/Subsystem1'
//  '<S35>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
//  '<S36>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
//  '<S37>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
//  '<S38>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
//  '<S39>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
//  '<S40>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
//  '<S41>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
//  '<S42>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
//  '<S43>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
//  '<S44>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
//  '<S45>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
//  '<S46>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
//  '<S47>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
//  '<S48>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
//  '<S49>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
//  '<S50>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
//  '<S51>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
//  '<S52>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
//  '<S53>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
//  '<S54>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
//  '<S55>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
//  '<S56>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
//  '<S57>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
//  '<S58>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
//  '<S59>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
//  '<S60>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
//  '<S61>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
//  '<S62>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
//  '<S63>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
//  '<S64>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
//  '<S65>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
//  '<S66>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
//  '<S67>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
//  '<S68>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
//  '<S69>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
//  '<S70>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
//  '<S71>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
//  '<S72>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
//  '<S73>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
//  '<S74>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
//  '<S75>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
//  '<S76>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
//  '<S77>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
//  '<S78>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
//  '<S79>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
//  '<S80>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
//  '<S81>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
//  '<S82>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
//  '<S83>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
//  '<S84>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
//  '<S85>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
//  '<S86>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
//  '<S87>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
//  '<S88>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
//  '<S89>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
//  '<S90>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
//  '<S91>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
//  '<S92>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
//  '<S93>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
//  '<S94>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
//  '<S95>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
//  '<S96>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
//  '<S97>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
//  '<S98>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
//  '<S99>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
//  '<S100>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
//  '<S101>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
//  '<S102>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
//  '<S103>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
//  '<S104>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
//  '<S105>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
//  '<S106>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
//  '<S107>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
//  '<S108>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
//  '<S109>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
//  '<S110>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
//  '<S111>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
//  '<S112>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
//  '<S113>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
//  '<S114>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
//  '<S115>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
//  '<S116>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
//  '<S117>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
//  '<S118>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
//  '<S119>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
//  '<S120>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
//  '<S121>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
//  '<S122>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
//  '<S123>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
//  '<S124>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
//  '<S125>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
//  '<S126>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
//  '<S127>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
//  '<S128>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
//  '<S129>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
//  '<S130>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
//  '<S131>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
//  '<S132>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
//  '<S133>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
//  '<S134>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
//  '<S135>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
//  '<S136>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
//  '<S137>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
//  '<S138>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
//  '<S139>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
//  '<S140>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
//  '<S141>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
//  '<S142>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
//  '<S143>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
//  '<S144>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
//  '<S145>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
//  '<S146>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
//  '<S147>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
//  '<S148>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
//  '<S149>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
//  '<S150>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
//  '<S151>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
//  '<S152>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
//  '<S153>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
//  '<S154>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
//  '<S155>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
//  '<S156>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
//  '<S157>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
//  '<S158>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
//  '<S159>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
//  '<S160>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
//  '<S161>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
//  '<S162>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
//  '<S163>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
//  '<S164>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
//  '<S165>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
//  '<S166>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
//  '<S167>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
//  '<S168>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
//  '<S169>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
//  '<S170>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
//  '<S171>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
//  '<S172>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
//  '<S173>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
//  '<S174>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
//  '<S175>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
//  '<S176>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
//  '<S177>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
//  '<S178>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
//  '<S179>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
//  '<S180>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
//  '<S181>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
//  '<S182>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
//  '<S183>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
//  '<S184>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
//  '<S185>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
//  '<S186>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
//  '<S187>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
//  '<S188>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
//  '<S189>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
//  '<S190>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
//  '<S191>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
//  '<S192>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
//  '<S193>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
//  '<S194>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
//  '<S195>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
//  '<S196>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
//  '<S197>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
//  '<S198>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
//  '<S199>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
//  '<S200>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
//  '<S201>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
//  '<S202>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
//  '<S203>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
//  '<S204>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
//  '<S205>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
//  '<S206>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
//  '<S207>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
//  '<S208>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
//  '<S209>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
//  '<S210>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
//  '<S211>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
//  '<S212>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
//  '<S213>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
//  '<S214>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
//  '<S215>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
//  '<S216>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S217>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S218>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S219>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
//  '<S220>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S221>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S222>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
//  '<S223>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
//  '<S224>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S225>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
//  '<S226>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
//  '<S227>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
//  '<S228>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
//  '<S229>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
//  '<S230>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
//  '<S231>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
//  '<S232>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
//  '<S233>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
//  '<S234>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
//  '<S235>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
//  '<S236>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
//  '<S237>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
//  '<S238>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
//  '<S239>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S240>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
//  '<S241>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
//  '<S242>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
//  '<S243>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
//  '<S244>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
//  '<S245>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch'
//  '<S246>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
//  '<S247>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
//  '<S248>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
//  '<S249>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
//  '<S250>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
//  '<S251>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
//  '<S252>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
//  '<S253>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
//  '<S254>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
//  '<S255>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
//  '<S256>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
//  '<S257>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
//  '<S258>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
//  '<S259>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
//  '<S260>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
//  '<S261>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
//  '<S262>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
//  '<S263>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
//  '<S264>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
//  '<S265>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
//  '<S266>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
//  '<S267>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
//  '<S268>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
//  '<S269>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
//  '<S270>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
//  '<S271>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S272>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S273>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S274>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
//  '<S275>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
//  '<S276>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
//  '<S277>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
//  '<S278>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
//  '<S279>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S280>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
//  '<S281>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
//  '<S282>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S283>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
//  '<S284>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
//  '<S285>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
//  '<S286>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
//  '<S287>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
//  '<S288>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
//  '<S289>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
//  '<S290>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
//  '<S291>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
//  '<S292>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S293>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
//  '<S294>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S295>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
//  '<S296>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
//  '<S297>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch/Smooth Bypass'
//  '<S298>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
//  '<S299>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
//  '<S300>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
//  '<S301>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
//  '<S302>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
//  '<S303>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
//  '<S304>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
//  '<S305>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
//  '<S306>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
//  '<S307>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
//  '<S308>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
//  '<S309>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
//  '<S310>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
//  '<S311>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
//  '<S312>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
//  '<S313>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
//  '<S314>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
//  '<S315>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
//  '<S316>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
//  '<S317>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
//  '<S318>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
//  '<S319>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
//  '<S320>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
//  '<S321>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
//  '<S322>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
//  '<S323>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
//  '<S324>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
//  '<S325>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
//  '<S326>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
//  '<S327>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
//  '<S328>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
//  '<S329>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
//  '<S330>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
//  '<S331>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
//  '<S332>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
//  '<S333>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
//  '<S334>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
//  '<S335>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S336>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S337>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
//  '<S338>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
//  '<S339>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S340>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
//  '<S341>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
//  '<S342>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
//  '<S343>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
//  '<S344>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
//  '<S345>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S346>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
//  '<S347>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
//  '<S348>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
//  '<S349>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S350>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
//  '<S351>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S352>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
//  '<S353>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
//  '<S354>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
//  '<S355>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
//  '<S356>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
//  '<S357>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
//  '<S358>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
//  '<S359>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
//  '<S360>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
//  '<S361>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
//  '<S362>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
//  '<S363>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
//  '<S364>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
//  '<S365>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
//  '<S366>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
//  '<S367>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
//  '<S368>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
//  '<S369>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
//  '<S370>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
//  '<S371>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
//  '<S372>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
//  '<S373>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
//  '<S374>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
//  '<S375>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
//  '<S376>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
//  '<S377>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
//  '<S378>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
//  '<S379>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
//  '<S380>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
//  '<S381>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
//  '<S382>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
//  '<S383>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
//  '<S384>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
//  '<S385>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
//  '<S386>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S387>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
//  '<S388>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
//  '<S389>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S390>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
//  '<S391>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
//  '<S392>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
//  '<S393>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
//  '<S394>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
//  '<S395>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
//  '<S396>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
//  '<S397>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
//  '<S398>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
//  '<S399>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S400>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
//  '<S401>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S402>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
//  '<S403>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
//  '<S404>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
//  '<S405>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
//  '<S406>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
//  '<S407>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
//  '<S408>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
//  '<S409>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
//  '<S410>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
//  '<S411>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
//  '<S412>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
//  '<S413>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
//  '<S414>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
//  '<S415>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
//  '<S416>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
//  '<S417>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
//  '<S418>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
//  '<S419>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
//  '<S420>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
//  '<S421>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
//  '<S422>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
//  '<S423>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
//  '<S424>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
//  '<S425>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
//  '<S426>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
//  '<S427>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
//  '<S428>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
//  '<S429>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
//  '<S430>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
//  '<S431>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
//  '<S432>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
//  '<S433>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
//  '<S434>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Chart'
//  '<S435>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
//  '<S436>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem'
//  '<S437>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1'
//  '<S438>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2'
//  '<S439>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3'
//  '<S440>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
//  '<S441>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
//  '<S442>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
//  '<S443>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
//  '<S444>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
//  '<S445>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
//  '<S446>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
//  '<S447>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
//  '<S448>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
//  '<S449>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
//  '<S450>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
//  '<S451>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
//  '<S452>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
//  '<S453>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
//  '<S454>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
//  '<S455>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
//  '<S456>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
//  '<S457>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
//  '<S458>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
//  '<S459>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
//  '<S460>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
//  '<S461>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
//  '<S462>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
//  '<S463>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
//  '<S464>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
//  '<S465>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
//  '<S466>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
//  '<S467>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
//  '<S468>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
//  '<S469>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
//  '<S470>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
//  '<S471>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
//  '<S472>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
//  '<S473>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
//  '<S474>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
//  '<S475>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
//  '<S476>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
//  '<S477>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
//  '<S478>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
//  '<S479>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
//  '<S480>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
//  '<S481>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
//  '<S482>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
//  '<S483>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
//  '<S484>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
//  '<S485>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
//  '<S486>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
//  '<S487>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
//  '<S488>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
//  '<S489>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
//  '<S490>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
//  '<S491>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
//  '<S492>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
//  '<S493>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
//  '<S494>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
//  '<S495>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
//  '<S496>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
//  '<S497>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
//  '<S498>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
//  '<S499>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
//  '<S500>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S501>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
//  '<S502>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
//  '<S503>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S504>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
//  '<S505>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
//  '<S506>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
//  '<S507>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
//  '<S508>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
//  '<S509>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
//  '<S510>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
//  '<S511>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
//  '<S512>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
//  '<S513>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S514>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
//  '<S515>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S516>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
//  '<S517>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
//  '<S518>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
//  '<S519>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
//  '<S520>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S521>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
//  '<S522>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S523>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S524>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S525>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S526>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S527>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S528>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S529>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S530>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S531>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S532>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S533>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S534>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
//  '<S535>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
//  '<S536>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
//  '<S537>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
//  '<S538>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
//  '<S539>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
//  '<S540>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
//  '<S541>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
//  '<S542>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
//  '<S543>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
//  '<S544>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
//  '<S545>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
//  '<S546>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
//  '<S547>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
//  '<S548>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
//  '<S549>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
//  '<S550>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
//  '<S551>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass'
//  '<S552>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Filter2'
//  '<S553>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2'
//  '<S554>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS'
//  '<S555>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS/MATLAB Function'
//  '<S556>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Filter2/DEFINITIVA'
//  '<S557>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1'
//  '<S558>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti'
//  '<S559>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/MATLAB Function2'
//  '<S560>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Sample and Hold'
//  '<S561>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function'
//  '<S562>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function1'
//  '<S563>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti/MATLAB Function'
//  '<S564>' : 'Aenea_model/Misure Sensori/BMP_280'
//  '<S565>' : 'Aenea_model/Misure Sensori/GPS_Venus'
//  '<S566>' : 'Aenea_model/Misure Sensori/MTi'
//  '<S567>' : 'Aenea_model/Misure Sensori/BMP_280/Dynamic rate limiter'
//  '<S568>' : 'Aenea_model/Misure Sensori/BMP_280/Execution_loop'
//  '<S569>' : 'Aenea_model/Misure Sensori/BMP_280/MATLAB Function'
//  '<S570>' : 'Aenea_model/Misure Sensori/BMP_280/Subsystem'
//  '<S571>' : 'Aenea_model/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
//  '<S572>' : 'Aenea_model/Misure Sensori/BMP_280/Subsystem/Subsystem1'
//  '<S573>' : 'Aenea_model/Misure Sensori/GPS_Venus/Subsystem1'
//  '<S574>' : 'Aenea_model/Misure Sensori/GPS_Venus/Subsystem2'
//  '<S575>' : 'Aenea_model/Misure Sensori/GPS_Venus/Subsystem2/Create_message'
//  '<S576>' : 'Aenea_model/Misure Sensori/GPS_Venus/Subsystem2/Subsystem'
//  '<S577>' : 'Aenea_model/Misure Sensori/GPS_Venus/Subsystem2/Subsystem/MATLAB Function'
//  '<S578>' : 'Aenea_model/RADIOCOMANDO/AILERON'
//  '<S579>' : 'Aenea_model/RADIOCOMANDO/AILERON1'
//  '<S580>' : 'Aenea_model/RADIOCOMANDO/ELEVATOR'
//  '<S581>' : 'Aenea_model/RADIOCOMANDO/ELEVATOR1'
//  '<S582>' : 'Aenea_model/RADIOCOMANDO/RUDDER'
//  '<S583>' : 'Aenea_model/RADIOCOMANDO/THROTTLE'
//  '<S584>' : 'Aenea_model/Servi/AILERON1'
//  '<S585>' : 'Aenea_model/Servi/RUDDER6'
//  '<S586>' : 'Aenea_model/Servi/THROTTLE1'
//  '<S587>' : 'Aenea_model/Servi/elevator'

#endif                                 // RTW_HEADER_Aenea_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
