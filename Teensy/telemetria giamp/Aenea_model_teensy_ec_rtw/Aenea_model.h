//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model.h
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.66
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu Nov 24 13:43:13 2022
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

// Block states (default storage) for system '<S406>/Resettable Subsystem'
typedef struct {
  real_T Memory_PreviousInput;         // '<S417>/Memory'
} DW_ResettableSubsystem_Aenea__T;

// Zero-crossing (trigger) state for system '<S406>/Resettable Subsystem'
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE_k;// '<S406>/Resettable Subsystem'
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
  real_T DataTypeConversion4[42];      // '<S438>/Data Type Conversion4'
  uint8_T buffer[300];                 // '<S1>/MATLAB Function2'
  real_T y[21];                        // '<S554>/MATLAB Function2'
  real_T x_est[18];
  real_T klm_gain_c[18];
  real_T a[16];
  real_T A[16];
  real_T rtb_TmpSignalConversionAtSFun_k[14];
  uint8_T messaggio[100];              // '<S1>/MATLAB Function4'
  uint8_T messaggio_2[100];            // '<S1>/MATLAB Function4'
  boolean_T x[100];
  real_T residui[11];                  // '<S553>/DEFINITIVA'
  real_T dv1[11];
  real_T UnitDelay[9];                 // '<S567>/Unit Delay'
  real_T DataTypeConversion1_c[9];     // '<S5>/Data Type Conversion1'
  real_T aterra_tmp[9];
  int32_T ipiv[11];
  real32_T ByteUnpack_o2[9];           // '<S567>/Byte Unpack'
  real32_T ByteReversal[9];            // '<S567>/Byte Reversal'
  real_T x_new[4];
  real_T aterra[3];
  real_T In_c[2];                      // '<S463>/In'
  boolean_T NOT[14];                   // '<S559>/NOT'
  uint16_T WP_info_in[6];
  real_T Lat;                          // '<S566>/S-Function Builder'
  real_T Long;                         // '<S566>/S-Function Builder'
  real_T V;                            // '<S566>/S-Function Builder'
  real_T quota;                        // '<S566>/S-Function Builder'
  real_T heading;                      // '<S566>/S-Function Builder'
  real_T SFunctionBuilder_o6;          // '<S566>/S-Function Builder'
  real_T T;                            // '<S573>/T'
  real_T In[21];                       // '<S561>/In'
  real_T Lat_K;                        // '<S553>/DEFINITIVA'
  real_T Long_K;                       // '<S553>/DEFINITIVA'
  real_T h_K;                          // '<S553>/DEFINITIVA'
  real_T vd_K;                         // '<S553>/DEFINITIVA'
  real_T v_K;                          // '<S553>/DEFINITIVA'
  real_T imbardata;                    // '<S553>/DEFINITIVA'
  real_T V_goHome;                     // '<S440>/GO_HOME'
  real_T h_goHome;                     // '<S440>/GO_HOME'
  real_T VELOCITA;                     // '<S439>/saturatore V'
  real_T QUOTA;                        // '<S439>/WAYPOINTS'
  real_T Gain;                         // '<S456>/Gain'
  real_T Gain_o;                       // '<S457>/Gain'
  real_T velocita; // '<S438>/Switch di selezione  Task - Waypoint navigation5'
  real_T QUOTA_e;  // '<S438>/Switch di selezione  Task - Waypoint navigation4'
  real_T Constant1;                    // '<S453>/Constant1'
  real_T Sum2;                         // '<S453>/Sum2'
  real_T maneuver_selector;            // '<S438>/Chart1'
  real_T trig_approach;                // '<S438>/Chart1'
  real_T trig_flare;                   // '<S438>/Chart1'
  real_T approach_selector;            // '<S438>/Chart1'
  real_T h_Home;                       // '<S438>/CALIBRATING_HOME_COORDINATES'
  real_T Multiply;                     // '<S449>/Multiply'
  real_T Constant1_h;                  // '<S449>/Constant1'
  real_T x_f_out;                      // '<S449>/MATLAB Function'
  real_T h_f_out;                      // '<S449>/MATLAB Function'
  real_T k_x_out;                      // '<S449>/MATLAB Function'
  real_T h_c_out;                      // '<S449>/MATLAB Function'
  real_T no_solution;                  // '<S449>/MATLAB Function'
  real_T V_vett;                       // '<S437>/VETTORIALE'
  real_T h_vett;                       // '<S437>/VETTORIALE'
  real_T Fase_ATO;                     // '<S436>/Chart1'
  real_T manetta_ref;                  // '<S436>/Chart1'
  real_T eq_rot;                       // '<S436>/Chart1'
  real_T h_ref;                        // '<S436>/Chart1'
  real_T Tas_ref;                      // '<S436>/Chart1'
  real_T psi_ref_selector;             // '<S436>/Chart1'
  real_T theta_ground_selector;        // '<S436>/Chart1'
  real_T Switch;                       // '<S432>/Switch'
  real_T Switch_a;                     // '<S418>/Switch'
  real_T switch_manetta;               // '<S34>/ STATI'
  real_T switch_equilibratore;         // '<S34>/ STATI'
  real_T switch_alettoni;              // '<S34>/ STATI'
  real_T switch_timone;                // '<S34>/ STATI'
  real_T throttle_safe;                // '<S34>/ STATI'
  real_T modo;                         // '<S34>/ STATI'
  real_T OutportBufferForOut1;         // '<S299>/Constant'
  real_T num_254;
  real_T Delta_clock;
  real_T a_b;
  real_T dist;
  real_T dist_fut;
  real_T Gain1;                        // '<S548>/Gain1'
  real_T Gain1_m;                      // '<S549>/Gain1'
  real_T Gain1_k;                      // '<S551>/Gain1'
  real_T Gain_h;                       // '<S29>/Gain'
  real_T SignPreSat;                   // '<S272>/SignPreSat'
  real_T Sum5;                         // '<S580>/Sum5'
  real_T SwitchBumpless2;              // '<S300>/Switch Bumpless 2'
  real_T Saturation_a;                 // '<S395>/Saturation'
  real_T Sum3_h;                       // '<S575>/Sum3'
  real_T Alettoni;                     // '<S33>/saturatore A'
  real_T Product1;                     // '<S555>/Product1'
  real_T V_est;                        // '<S4>/Multiply3'
  real_T Sum2_k2;                      // '<S301>/Sum2'
  real_T Switch_j;                     // '<S532>/Switch'
  real_T Long_Home;                    // '<S438>/CALIBRATING_HOME_COORDINATES'
  real_T Sum_h;                        // '<S520>/Sum'
  real_T Gain_hh;                      // '<S461>/Gain'
  real_T Switch1_g;                    // '<S23>/Switch1'
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
  real_T y_p;
  real_T Y_tmp;
  real_T Y_tmp_c;
  real_T Y_tmp_f;
  real_T Y_tmp_g;
  real_T Y_tmp_g1;
  real_T Y_tmp_m;
  int8_T p[4];
  int8_T ipiv_n[4];
  real32_T SFunction_o8;               // '<S1>/S-Function'
  real32_T SFunction_o10[7];           // '<S1>/S-Function'
  real32_T SFunction_o13;              // '<S1>/S-Function'
  real32_T SFunction_o17;              // '<S1>/S-Function'
  real32_T DataTypeConversion1[6];     // '<S15>/Data Type Conversion1'
  real32_T AGAC[4];                    // '<S20>/Data Type Conversion'
  real32_T DataTypeConversion1_m;      // '<Root>/Data Type Conversion1'
  real32_T DataTypeConversion;         // '<S2>/Data Type Conversion'
  real32_T DataTypeConversion3_p;      // '<S569>/Data Type Conversion3'
  real32_T SFunctionBuilder_o1;        // '<S569>/S-Function Builder'
  real32_T SFunctionBuilder_o2;        // '<S569>/S-Function Builder'
  real32_T SFunctionBuilder_o3;        // '<S569>/S-Function Builder'
  real32_T WP_param[7];                // '<S21>/MATLAB Function'
  real32_T Val_out_MAV[16];            // '<S1>/MATLAB Function1'
  real32_T f;
  int32_T SFunctionBuilder_o2_a;       // '<S1>/S-Function Builder'
  int32_T Add;                         // '<S1>/Add'
  int32_T DataTypeConversion_g[4];     // '<S13>/Data Type Conversion'
  uint16_T Memory[8];                  // '<S1>/Memory'
  uint16_T SFunction_o9[6];            // '<S1>/S-Function'
  uint16_T SFunction_o11[8];           // '<S1>/S-Function'
  uint16_T LVDE[8];                    // '<S19>/Data Type Conversion2'
  uint16_T ByteUnpack[8];              // '<S565>/Byte Unpack'
  int16_T DataTypeConversion1_j[3];    // '<S13>/Data Type Conversion1'
  int32_T caso;
  int32_T tolleranza_distWP_fut;
  int32_T soglia_dist;
  int32_T c;
  int32_T ix;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
  int32_T Switch_h;                    // '<S554>/Switch'
  int32_T Switch_oz;                   // '<S449>/Switch'
  int32_T i;
  int32_T i_p;
  int32_T j;
  int32_T jBcol;
  uint32_T SFunction_o2;               // '<S1>/S-Function'
  uint32_T DataTypeConversion3;        // '<S16>/Data Type Conversion3'
  uint32_T qY;
  ZCEventType zcEvent;
  uint16_T SFunction_o7[2];            // '<S1>/S-Function'
  uint16_T DataTypeConversion2;        // '<S13>/Data Type Conversion2'
  uint16_T Heading[9];                 // '<S17>/Data Type Conversion1'
  uint16_T Memory_o;                   // '<S2>/Memory'
  uint16_T SFunction_o3;               // '<S2>/S-Function'
  uint16_T SFunction_o4;               // '<S2>/S-Function'
  uint16_T WP_info[6];                 // '<S21>/MATLAB Function'
  uint16_T new_mex;                    // '<S1>/MATLAB Function3'
  uint16_T GC_info[3];                 // '<S1>/MATLAB Function1'
  int16_T DataTypeConversion_j[9];     // '<S15>/Data Type Conversion'
  int16_T Heading_f;                   // '<S20>/Data Type Conversion1'
  int16_T DataTypeConversion2_m;       // '<S2>/Data Type Conversion2'
  uint8_T SFunctionBuilder1[41];       // '<S567>/S-Function Builder1'
  uint8_T ByteUnpack_o1[4];            // '<S567>/Byte Unpack'
  uint8_T ByteUnpack_o3;               // '<S567>/Byte Unpack'
  uint8_T SFunctionBuilder_o1_a[100];  // '<S1>/S-Function Builder'
  uint8_T Memory1[2];                  // '<S1>/Memory1'
  uint8_T Memory_h[4];                 // '<Root>/Memory'
  uint8_T Memory3;                     // '<S1>/Memory3'
  uint8_T SFunction_o1[4];             // '<S1>/S-Function'
  uint8_T SFunction_o3_n;              // '<S1>/S-Function'
  uint8_T SFunction_o4_a[2];           // '<S1>/S-Function'
  uint8_T SFunction_o5[3];             // '<S1>/S-Function'
  uint8_T SFunction_o6;                // '<S1>/S-Function'
  uint8_T SFunction_o12;               // '<S1>/S-Function'
  uint8_T SFunction_o14;               // '<S1>/S-Function'
  uint8_T SFunction_o15;               // '<S1>/S-Function'
  uint8_T SFunction_o16;               // '<S1>/S-Function'
  uint8_T DataTypeConversion1_f[4];    // '<S14>/Data Type Conversion1'
  uint8_T SFunction_o1_i;              // '<S2>/S-Function'
  uint8_T SFunction_o2_h[264];         // '<S2>/S-Function'
  uint8_T SFunctionBuilder;            // '<S2>/S-Function Builder'
  uint8_T iflogic;                     // '<S16>/iflogic_function'
  uint8_T mess_out[100];               // '<S1>/MATLAB Function2'
  boolean_T HitCrossing;               // '<S247>/Hit  Crossing'
} B_Aenea_model_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE[9];          // '<S567>/Unit Delay'
  real_T UnitDelay_DSTATE_c;           // '<S555>/Unit Delay'
  real_T UnitDelay1_DSTATE;            // '<S565>/Unit Delay1'
  real_T Integrator_DSTATE;            // '<S338>/Integrator'
  real_T Integrator_DSTATE_l;          // '<S388>/Integrator'
  real_T DiscreteWashoutFilter_states; // '<S302>/Discrete Washout Filter'
  real_T Delay_DSTATE;                 // '<S246>/Delay'
  real_T Integrator_DSTATE_lq;         // '<S281>/Integrator'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S303>/Discrete-Time Integrator'
  real_T DelayInput2_DSTATE;           // '<S568>/Delay Input2'
  real_T DiscreteTimeIntegrator_DSTATE_j;// '<S449>/Discrete-Time Integrator'
  volatile real_T RateTransition_Buffer0;// '<S23>/Rate Transition'
  real_T Memory1_PreviousInput;        // '<S23>/Memory1'
  real_T Memory_PreviousInput;         // '<S23>/Memory'
  real_T Memory_PreviousInput_e[14];   // '<S559>/Memory'
  real_T Memory_PreviousInput_o[14];   // '<S558>/Memory'
  real_T Memory2_PreviousInput;        // '<S23>/Memory2'
  real_T P_ref;                        // '<S565>/MATLAB Function'
  real_T rl_up;                        // '<S565>/MATLAB Function'
  real_T rl_dw;                        // '<S565>/MATLAB Function'
  real_T x_prd[18];                    // '<S553>/DEFINITIVA'
  real_T p_prd[324];                   // '<S553>/DEFINITIVA'
  real_T flag;                         // '<S440>/GO_HOME'
  real_T Memory4_PreviousInput;        // '<S439>/Memory4'
  real_T flag_f;                       // '<S439>/WAYPOINTS'
  real_T lat1;                         // '<S439>/WAYPOINTS'
  real_T long1;                        // '<S439>/WAYPOINTS'
  real_T Memory7_PreviousInput;        // '<S438>/Memory7'
  real_T Memory5_PreviousInput;        // '<S438>/Memory5'
  real_T Memory1_PreviousInput_f;      // '<S438>/Memory1'
  real_T Memory2_PreviousInput_e;      // '<S438>/Memory2'
  real_T x[4];                         // '<S449>/MATLAB Function'
  real_T cycle_count;                  // '<S449>/MATLAB Function'
  real_T eps[4];                       // '<S449>/MATLAB Function'
  real_T flag_a;                       // '<S438>/ALLINEAMENTO'
  real_T Memory3_PreviousInput;        // '<S437>/Memory3'
  real_T V_ref;                        // '<S437>/VETTORIALE'
  real_T ALT_ref;                      // '<S437>/VETTORIALE'
  real_T Memory_PreviousInput_p;       // '<S436>/Memory'
  real_T Memory1_PreviousInput_e;      // '<S436>/Memory1'
  real_T alarm;                        // '<S413>/MATLAB Function1'
  real_T Memory_PreviousInput_n;       // '<S434>/Memory'
  real_T mess_len;                     // '<S1>/MATLAB Function4'
  real_T test1;                        // '<S1>/MATLAB Function1'
  real32_T riferimenti[16];            // '<S1>/MATLAB Function1'
  real32_T WP_dbP[42];                 // '<S1>/MATLAB Function1'
  real32_T WP_dbP_AL[42];              // '<S1>/MATLAB Function1'
  int_T HitCrossing_MODE;              // '<S247>/Hit  Crossing'
  uint16_T Memory_PreviousInput_i[8];  // '<S1>/Memory'
  uint16_T Memory_PreviousInput_e4;    // '<S2>/Memory'
  uint16_T counter;                    // '<S1>/MATLAB Function3'
  uint16_T WP_dbI[36];                 // '<S1>/MATLAB Function1'
  int8_T Integrator_PrevResetState;    // '<S388>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S303>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_o;// '<S449>/Discrete-Time Integrator'
  uint8_T Memory4_PreviousInput_j[300];// '<S1>/Memory4'
  uint8_T Memory5_PreviousInput_b[100];// '<S1>/Memory5'
  uint8_T Memory1_PreviousInput_b[2];  // '<S1>/Memory1'
  uint8_T Memory3_PreviousInput_g;     // '<S1>/Memory3'
  uint8_T Memory2_PreviousInput_d[9];  // '<S1>/Memory2'
  uint8_T is_active_c10_Aenea_model;   // '<S438>/Chart1'
  uint8_T is_c10_Aenea_model;          // '<S438>/Chart1'
  uint8_T Memory1_PreviousInput_k;     // '<S437>/Memory1'
  uint8_T Memory2_PreviousInput_d2;    // '<S437>/Memory2'
  uint8_T Memory6_PreviousInput;       // '<S437>/Memory6'
  uint8_T is_active_c1_Aenea_model;    // '<S436>/Chart1'
  uint8_T is_c1_Aenea_model;           // '<S436>/Chart1'
  uint8_T temporalCounter_i1;          // '<S436>/Chart1'
  uint8_T is_active_c21_Aenea_model;   // '<S35>/Chart'
  uint8_T is_c21_Aenea_model;          // '<S35>/Chart'
  uint8_T is_active_c26_Aenea_model;   // '<S34>/ STATI'
  uint8_T is_c26_Aenea_model;          // '<S34>/ STATI'
  uint8_T is_AUTOMATICA;               // '<S34>/ STATI'
  uint8_T is_active_c23_Aenea_model;
                                   // '<S36>/SELEZIONE MODALITA'  HOLD//SELECT'
  uint8_T is_c23_Aenea_model;      // '<S36>/SELEZIONE MODALITA'  HOLD//SELECT'
  uint8_T message[100];                // '<S1>/MATLAB Function4'
  uint8_T counter_j;                   // '<S1>/MATLAB Function4'
  boolean_T x_prd_not_empty;           // '<S553>/DEFINITIVA'
  boolean_T x_not_empty;               // '<S449>/MATLAB Function'
  boolean_T x_new_not_empty;           // '<S449>/MATLAB Function'
  boolean_T cycle_count_not_empty;     // '<S449>/MATLAB Function'
  boolean_T eps_not_empty;             // '<S449>/MATLAB Function'
  boolean_T Tf_not_empty;              // '<S408>/MATLAB Function1'
  boolean_T Interr_parz;               // '<S1>/MATLAB Function4'
  boolean_T WP_dbP_not_empty;          // '<S1>/MATLAB Function1'
  boolean_T WP_dbP_AL_not_empty;       // '<S1>/MATLAB Function1'
  boolean_T Enabled_MODE;              // '<S430>/Enabled '
  boolean_T Enabled_MODE_i;            // '<S422>/Enabled '
  boolean_T Enabled_MODE_b;            // '<S421>/Enabled '
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem_j;// '<S407>/Resettable Subsystem' 
  DW_ResettableSubsystem_Aenea__T ResettableSubsystem;// '<S406>/Resettable Subsystem' 
} DW_Aenea_model_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    // '<S247>/Hit  Crossing'
  ZCSigState SampleandHold_Trig_ZCE;   // '<S554>/Sample and Hold'
  ZCSigState SampleandHold_Trig_ZCE_l; // '<S438>/Sample and Hold'
  ZCSigState SampleandHold1_Trig_ZCE;  // '<S436>/Sample and Hold1'
  ZCSigState SampleandHold_Trig_ZCE_a; // '<S436>/Sample and Hold'
  ZCSigState ResettableSubsystem_Reset_ZCE;// '<S430>/Resettable Subsystem'
  ZCSigState ResettableSubsystem_Reset_ZCE_b;// '<S422>/Resettable Subsystem'
  ZCSigState ResettableSubsystem_Reset_ZCE_l;// '<S421>/Resettable Subsystem'
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem_j;// '<S407>/Resettable Subsystem' 
  ZCE_ResettableSubsystem_Aenea_T ResettableSubsystem;// '<S406>/Resettable Subsystem' 
  ZCSigState EnabledSubsystem_Trig_ZCE;// '<S247>/Enabled Subsystem'
} PrevZCX_Aenea_model_T;

// Invariant block signals (default storage)
typedef const struct tag_ConstB_Aenea_model_T {
  real_T USCITAPERCENTUALE;            // '<S20>/USCITA PERCENTUALE'
  real_T DataTypeConversion5;          // '<S7>/Data Type Conversion5'
  real_T Go_Home;                      // '<S7>/Switch'
  real_T DataTypeConversion13;         // '<S7>/Data Type Conversion13'
  real_T DataTypeConversion16;         // '<S7>/Data Type Conversion16'
  real_T DataTypeConversion14;         // '<S7>/Data Type Conversion14'
  real_T DataTypeConversion17;         // '<S7>/Data Type Conversion17'
  real_T DataTypeConversion15;         // '<S7>/Data Type Conversion15'
  real_T Gain;                         // '<S17>/Gain'
  real_T Saturation;                   // '<S17>/Saturation'
  real_T PatohPa1;                     // '<S2>/Pa to hPa1'
  uint32_T DataTypeConversion;         // '<S14>/Data Type Conversion'
  real32_T DataTypeConversion1;        // '<S2>/Data Type Conversion1'
  uint16_T Gain_e;                     // '<S19>/Gain'
  uint16_T Throttle;                   // '<S20>/Data Type Conversion2'
  int16_T K_imb_inv;                   // '<S6>/Gain3'
  int16_T Gain2;                       // '<S19>/Gain2'
  int16_T Gain1;                       // '<S19>/Gain1'
  int8_T B_Remaining;                  // '<S19>/Data Type Conversion3'
} ConstB_Aenea_model_T;

// Constant parameters (default storage)
typedef struct {
  // Expression: R1B
  //  Referenced by: '<S4>/Constant13'

  real_T Constant13_Value[11];

  // Expression: Q1B
  //  Referenced by: '<S4>/Constant16'

  real_T Constant16_Value[18];

  // Computed Parameter: onboard_control_sensor_presentu
  //  Referenced by: '<S19>/onboard_control_sensor_present uint32'

  uint32_T onboard_control_sensor_presentu[3];

  // Computed Parameter: SIUAVuint8_Value
  //  Referenced by: '<Root>/SI UAV uint8'

  uint8_T SIUAVuint8_Value;

  // Computed Parameter: registromemoria213_Value
  //  Referenced by: '<S565>/registro memoria2 13'

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

// External data declarations for dependent source files
extern const real32_T Aenea_model_R32GND;// real32_T ground
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
//  Block '<S39>/Constant1' : Unused code path elimination
//  Block '<S39>/Constant10' : Unused code path elimination
//  Block '<S39>/Constant11' : Unused code path elimination
//  Block '<S39>/Constant12' : Unused code path elimination
//  Block '<S39>/Constant13' : Unused code path elimination
//  Block '<S39>/Constant14' : Unused code path elimination
//  Block '<S39>/Constant15' : Unused code path elimination
//  Block '<S39>/Constant2' : Unused code path elimination
//  Block '<S39>/Constant3' : Unused code path elimination
//  Block '<S39>/Constant5' : Unused code path elimination
//  Block '<S39>/Constant7' : Unused code path elimination
//  Block '<S39>/Constant9' : Unused code path elimination
//  Block '<S39>/Multiport Switch' : Unused code path elimination
//  Block '<S39>/Multiport Switch1' : Unused code path elimination
//  Block '<S39>/Multiport Switch2' : Unused code path elimination
//  Block '<S70>/DProd Out' : Unused code path elimination
//  Block '<S71>/Filter' : Unused code path elimination
//  Block '<S71>/SumD' : Unused code path elimination
//  Block '<S73>/IProd Out' : Unused code path elimination
//  Block '<S76>/Integrator' : Unused code path elimination
//  Block '<S79>/NProd Out' : Unused code path elimination
//  Block '<S81>/PProd Out' : Unused code path elimination
//  Block '<S85>/Sum' : Unused code path elimination
//  Block '<S87>/Kt' : Unused code path elimination
//  Block '<S87>/SumI3' : Unused code path elimination
//  Block '<S88>/SumI1' : Unused code path elimination
//  Block '<S118>/DProd Out' : Unused code path elimination
//  Block '<S119>/Filter' : Unused code path elimination
//  Block '<S119>/SumD' : Unused code path elimination
//  Block '<S121>/IProd Out' : Unused code path elimination
//  Block '<S124>/Integrator' : Unused code path elimination
//  Block '<S127>/NProd Out' : Unused code path elimination
//  Block '<S129>/PProd Out' : Unused code path elimination
//  Block '<S133>/Sum' : Unused code path elimination
//  Block '<S135>/Kt' : Unused code path elimination
//  Block '<S135>/SumI3' : Unused code path elimination
//  Block '<S136>/SumI1' : Unused code path elimination
//  Block '<S169>/IProd Out' : Unused code path elimination
//  Block '<S172>/Integrator' : Unused code path elimination
//  Block '<S177>/PProd Out' : Unused code path elimination
//  Block '<S181>/Sum' : Unused code path elimination
//  Block '<S183>/Kt' : Unused code path elimination
//  Block '<S183>/SumI3' : Unused code path elimination
//  Block '<S184>/SumI1' : Unused code path elimination
//  Block '<S39>/Saturation' : Unused code path elimination
//  Block '<S39>/Sum1' : Unused code path elimination
//  Block '<S39>/Sum2' : Unused code path elimination
//  Block '<S39>/Sum4' : Unused code path elimination
//  Block '<S39>/Switch auto-manual' : Unused code path elimination
//  Block '<S39>/Switch maneuver' : Unused code path elimination
//  Block '<S39>/Switch rc saturata' : Unused code path elimination
//  Block '<S39>/n-D Lookup Table' : Unused code path elimination
//  Block '<S36>/Kp' : Unused code path elimination
//  Block '<S41>/Constant' : Unused code path elimination
//  Block '<S41>/Lookup Table2' : Unused code path elimination
//  Block '<S189>/Data Type Duplicate' : Unused code path elimination
//  Block '<S189>/Data Type Propagation' : Unused code path elimination
//  Block '<S189>/LowerRelop1' : Unused code path elimination
//  Block '<S189>/Switch' : Unused code path elimination
//  Block '<S189>/Switch2' : Unused code path elimination
//  Block '<S189>/UpperRelop' : Unused code path elimination
//  Block '<S36>/Switch HOLD//SELECT' : Unused code path elimination
//  Block '<S190>/Constant3' : Unused code path elimination
//  Block '<S190>/Constant4' : Unused code path elimination
//  Block '<S190>/Multiport Switch2' : Unused code path elimination
//  Block '<S190>/Multiport Switch3' : Unused code path elimination
//  Block '<S190>/Switch3' : Unused code path elimination
//  Block '<S190>/Switch4' : Unused code path elimination
//  Block '<S37>/Constant' : Unused code path elimination
//  Block '<S37>/Constant2' : Unused code path elimination
//  Block '<S217>/AND3' : Unused code path elimination
//  Block '<S217>/Constant1' : Unused code path elimination
//  Block '<S217>/DataTypeConv1' : Unused code path elimination
//  Block '<S217>/DataTypeConv2' : Unused code path elimination
//  Block '<S219>/DeadZone' : Unused code path elimination
//  Block '<S217>/Equal1' : Unused code path elimination
//  Block '<S217>/NotEqual' : Unused code path elimination
//  Block '<S217>/SignPreIntegrator' : Unused code path elimination
//  Block '<S217>/SignPreSat' : Unused code path elimination
//  Block '<S217>/Switch' : Unused code path elimination
//  Block '<S217>/ZeroGain' : Unused code path elimination
//  Block '<S220>/DProd Out' : Unused code path elimination
//  Block '<S221>/Filter' : Unused code path elimination
//  Block '<S221>/SumD' : Unused code path elimination
//  Block '<S223>/IProd Out' : Unused code path elimination
//  Block '<S226>/Integrator' : Unused code path elimination
//  Block '<S229>/NProd Out' : Unused code path elimination
//  Block '<S231>/PProd Out' : Unused code path elimination
//  Block '<S233>/Saturation' : Unused code path elimination
//  Block '<S235>/Sum' : Unused code path elimination
//  Block '<S237>/Kt' : Unused code path elimination
//  Block '<S237>/SumI3' : Unused code path elimination
//  Block '<S238>/SumI1' : Unused code path elimination
//  Block '<S37>/Switch' : Unused code path elimination
//  Block '<S37>/Switch auto-manual' : Unused code path elimination
//  Block '<S192>/Constant' : Unused code path elimination
//  Block '<S192>/Constant1' : Unused code path elimination
//  Block '<S192>/Constant2' : Unused code path elimination
//  Block '<S243>/Gain1' : Unused code path elimination
//  Block '<S192>/Math Function' : Unused code path elimination
//  Block '<S244>/Gain' : Unused code path elimination
//  Block '<S192>/Sum' : Unused code path elimination
//  Block '<S192>/Sum1' : Unused code path elimination
//  Block '<S192>/Sum2' : Unused code path elimination
//  Block '<S192>/Switch' : Unused code path elimination
//  Block '<S192>/Switch1' : Unused code path elimination
//  Block '<S32>/Switch di selezioneriferimeti  per i loop interni 2' : Unused code path elimination
//  Block '<S32>/Switch di selezioneriferimeti  per i loop interni 3' : Unused code path elimination
//  Block '<S33>/Gain3' : Unused code path elimination
//  Block '<S33>/Switch Bumpless 7' : Unused code path elimination
//  Block '<S406>/Display' : Unused code path elimination
//  Block '<S406>/Display1' : Unused code path elimination
//  Block '<S424>/Constant' : Unused code path elimination
//  Block '<S424>/Constant1' : Unused code path elimination
//  Block '<S424>/Switch' : Unused code path elimination
//  Block '<S426>/Constant4' : Unused code path elimination
//  Block '<S426>/Memory' : Unused code path elimination
//  Block '<S426>/Sum' : Unused code path elimination
//  Block '<S427>/Constant' : Unused code path elimination
//  Block '<S427>/Constant1' : Unused code path elimination
//  Block '<S427>/Switch' : Unused code path elimination
//  Block '<S429>/Constant4' : Unused code path elimination
//  Block '<S429>/Memory' : Unused code path elimination
//  Block '<S429>/Sum' : Unused code path elimination
//  Block '<S408>/Switch' : Unused code path elimination
//  Block '<S34>/Scope1' : Unused code path elimination
//  Block '<S414>/Abs2' : Unused code path elimination
//  Block '<S449>/Multiply1' : Unused code path elimination
//  Block '<S438>/Constant1' : Unused code path elimination
//  Block '<S438>/Constant7' : Unused code path elimination
//  Block '<S453>/Exp1' : Unused code path elimination
//  Block '<S453>/Gain1' : Unused code path elimination
//  Block '<S453>/Gain2' : Unused code path elimination
//  Block '<S453>/Multiply2' : Unused code path elimination
//  Block '<S453>/Multiply3' : Unused code path elimination
//  Block '<S453>/Multiply4' : Unused code path elimination
//  Block '<S453>/Sum3' : Unused code path elimination
//  Block '<S453>/Sum4' : Unused code path elimination
//  Block '<S454>/Gain1' : Unused code path elimination
//  Block '<S499>/IProd Out' : Unused code path elimination
//  Block '<S502>/Integrator' : Unused code path elimination
//  Block '<S507>/PProd Out' : Unused code path elimination
//  Block '<S511>/Sum' : Unused code path elimination
//  Block '<S470>/Gain' : Unused code path elimination
//  Block '<S454>/Sum3' : Unused code path elimination
//  Block '<S454>/psi ref gain' : Unused code path elimination
//  Block '<S454>/psi ref gain1' : Unused code path elimination
//  Block '<S522>/Sum3' : Unused code path elimination
//  Block '<S522>/x*sin' : Unused code path elimination
//  Block '<S522>/y*cos' : Unused code path elimination
//  Block '<S438>/Relational Operator' : Unused code path elimination
//  Block '<S438>/Switch' : Unused code path elimination
//  Block '<S438>/Switch di selezione  Task - Waypoint navigation6' : Unused code path elimination
//  Block '<S438>/Switch1' : Unused code path elimination
//  Block '<S439>/saturatore V1' : Unused code path elimination
//  Block '<S35>/Switch di selezione  Task - Waypoint navigation' : Unused code path elimination
//  Block '<S35>/Switch di selezione  Task - Waypoint navigation3' : Unused code path elimination
//  Block '<S4>/Constant2' : Unused code path elimination
//  Block '<S568>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S572>/Data Type Duplicate' : Unused code path elimination
//  Block '<S572>/Data Type Propagation' : Unused code path elimination
//  Block '<S566>/Constant' : Unused code path elimination
//  Block '<S566>/Constant2' : Unused code path elimination
//  Block '<S566>/Constant3' : Unused code path elimination
//  Block '<S566>/Manual Switch1' : Unused code path elimination
//  Block '<S566>/Manual Switch3' : Unused code path elimination
//  Block '<S566>/Manual Switch4' : Unused code path elimination
//  Block '<S574>/Constant' : Unused code path elimination
//  Block '<S574>/Constant1' : Unused code path elimination
//  Block '<S574>/Constant2' : Unused code path elimination
//  Block '<S574>/Constant3' : Unused code path elimination
//  Block '<S574>/Constant4' : Unused code path elimination
//  Block '<S574>/Constant5' : Unused code path elimination
//  Block '<S574>/Constant6' : Unused code path elimination
//  Block '<S574>/Equal' : Unused code path elimination
//  Block '<S574>/Equal1' : Unused code path elimination
//  Block '<S574>/Equal2' : Unused code path elimination
//  Block '<S574>/Equal3' : Unused code path elimination
//  Block '<S574>/Equal4' : Unused code path elimination
//  Block '<S574>/Equal5' : Unused code path elimination
//  Block '<S574>/OR' : Unused code path elimination
//  Block '<S574>/Switch' : Unused code path elimination
//  Block '<S566>/Sum1' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless AP quota' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless controllore beccheggio' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless controllore imbardata' : Unused code path elimination
//  Block '<S6>/K AntiWindup-Bumpless controllore rollio' : Unused code path elimination
//  Block '<S6>/Ki AP quota Select' : Unused code path elimination
//  Block '<S6>/Ki AP rotta1' : Unused code path elimination
//  Block '<S6>/Kp AP quota Select' : Unused code path elimination
//  Block '<S6>/Kp AP rotta' : Unused code path elimination
//  Block '<S6>/Saturation' : Unused code path elimination
//  Block '<S6>/n-D Lookup Table' : Unused code path elimination
//  Block '<S7>/Data Type Conversion' : Unused code path elimination
//  Block '<S7>/Data Type Conversion1' : Unused code path elimination
//  Block '<S7>/Data Type Conversion2' : Unused code path elimination
//  Block '<S7>/Data Type Conversion3' : Unused code path elimination
//  Block '<S581>/Constant' : Unused code path elimination
//  Block '<S581>/Constant1' : Unused code path elimination
//  Block '<S581>/Divide' : Unused code path elimination
//  Block '<S581>/Multiply' : Unused code path elimination
//  Block '<S581>/Sum' : Unused code path elimination
//  Block '<S581>/Sum1' : Unused code path elimination
//  Block '<S581>/Sum2' : Unused code path elimination
//  Block '<S581>/Sum3' : Unused code path elimination
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
//  Block '<S582>/Constant' : Unused code path elimination
//  Block '<S582>/Constant1' : Unused code path elimination
//  Block '<S582>/Divide' : Unused code path elimination
//  Block '<S582>/Multiply' : Unused code path elimination
//  Block '<S582>/Sum' : Unused code path elimination
//  Block '<S582>/Sum1' : Unused code path elimination
//  Block '<S582>/Sum2' : Unused code path elimination
//  Block '<S582>/Sum3' : Unused code path elimination
//  Block '<S583>/Multiply' : Unused code path elimination
//  Block '<S583>/Sum' : Unused code path elimination
//  Block '<S583>/Sum1' : Unused code path elimination
//  Block '<S584>/Constant' : Unused code path elimination
//  Block '<S584>/Constant1' : Unused code path elimination
//  Block '<S584>/Divide' : Unused code path elimination
//  Block '<S584>/Multiply' : Unused code path elimination
//  Block '<S584>/Sum' : Unused code path elimination
//  Block '<S584>/Sum1' : Unused code path elimination
//  Block '<S584>/Sum2' : Unused code path elimination
//  Block '<S584>/Sum3' : Unused code path elimination
//  Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S15>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S15>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S15>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S15>/Manual Switch3' : Eliminated due to constant selection input
//  Block '<S15>/Manual Switch4' : Eliminated due to constant selection input
//  Block '<S15>/Manual Switch5' : Eliminated due to constant selection input
//  Block '<S15>/Manual Switch6' : Eliminated due to constant selection input
//  Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S292>/Kt' : Eliminated nontunable gain of 1
//  Block '<S331>/Kb' : Eliminated nontunable gain of 1
//  Block '<S349>/Kt' : Eliminated nontunable gain of 1
//  Block '<S399>/Kt' : Eliminated nontunable gain of 1
//  Block '<S33>/Gain' : Eliminated nontunable gain of 1
//  Block '<S33>/Gain2' : Eliminated nontunable gain of 1
//  Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S565>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S565>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S566>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S566>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S566>/Manual Switch5' : Eliminated due to constant selection input
//  Block '<S578>/Gain' : Eliminated nontunable gain of 1
//  Block '<S15>/Constant3' : Unused code path elimination
//  Block '<S15>/Constant4' : Unused code path elimination
//  Block '<S15>/Constant5' : Unused code path elimination
//  Block '<S15>/Constant6' : Unused code path elimination
//  Block '<S15>/Constant7' : Unused code path elimination
//  Block '<S15>/Constant8' : Unused code path elimination
//  Block '<S15>/Constant9' : Unused code path elimination
//  Block '<S566>/Constant1' : Unused code path elimination
//  Block '<S566>/Constant4' : Unused code path elimination
//  Block '<S566>/Constant5' : Unused code path elimination


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
//  '<S18>'  : 'Aenea_model/AIR TX/Subsystem'
//  '<S19>'  : 'Aenea_model/AIR TX/SystemStatus'
//  '<S20>'  : 'Aenea_model/AIR TX/VFR'
//  '<S21>'  : 'Aenea_model/AIR TX/Waypoints'
//  '<S22>'  : 'Aenea_model/AIR TX/Heartbeat/Alarm set'
//  '<S23>'  : 'Aenea_model/AIR TX/If_subsystem/Subsystem'
//  '<S24>'  : 'Aenea_model/AIR TX/If_subsystem/iflogic_function'
//  '<S25>'  : 'Aenea_model/AIR TX/Servo/Conversione'
//  '<S26>'  : 'Aenea_model/AIR TX/Servo/Conversione/Radians to Degrees1'
//  '<S27>'  : 'Aenea_model/AIR TX/Servo/Conversione/Radians to Degrees2'
//  '<S28>'  : 'Aenea_model/AIR TX/Servo/Conversione/Radians to Degrees3'
//  '<S29>'  : 'Aenea_model/AIR TX/VFR/Radians to Degrees'
//  '<S30>'  : 'Aenea_model/AIR TX/VFR/wrapTo360'
//  '<S31>'  : 'Aenea_model/AIR TX/Waypoints/MATLAB Function'
//  '<S32>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1'
//  '<S33>'  : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1'
//  '<S34>'  : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1'
//  '<S35>'  : 'Aenea_model/AUTOPILOTA/Subsystem1'
//  '<S36>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA'
//  '<S37>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA'
//  '<S38>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA''
//  '<S39>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1'
//  '<S40>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/SELEZIONE MODALITA'  HOLD//SELECT'
//  '<S41>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC '
//  '<S42>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach'
//  '<S43>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1'
//  '<S44>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato'
//  '<S45>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup'
//  '<S46>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain'
//  '<S47>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter'
//  '<S48>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs'
//  '<S49>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain'
//  '<S50>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain'
//  '<S51>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk'
//  '<S52>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator'
//  '<S53>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs'
//  '<S54>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy'
//  '<S55>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain'
//  '<S56>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy'
//  '<S57>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain'
//  '<S58>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal'
//  '<S59>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation'
//  '<S60>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk'
//  '<S61>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum'
//  '<S62>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk'
//  '<S63>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode'
//  '<S64>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum'
//  '<S65>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral'
//  '<S66>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain'
//  '<S67>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal'
//  '<S68>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal'
//  '<S69>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Anti-windup/Passthrough'
//  '<S70>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/D Gain/External Parameters'
//  '<S71>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter'
//  '<S72>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter ICs/Internal IC - Filter'
//  '<S73>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/I Gain/External Parameters'
//  '<S74>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain/Passthrough'
//  '<S75>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Ideal P Gain Fdbk/Disabled'
//  '<S76>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete'
//  '<S77>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator ICs/Internal IC'
//  '<S78>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Copy/Disabled'
//  '<S79>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/N Gain/External Parameters'
//  '<S80>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/P Copy/Disabled'
//  '<S81>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Parallel P Gain/External Parameters'
//  '<S82>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Reset Signal/External Reset'
//  '<S83>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation/Passthrough'
//  '<S84>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Saturation Fdbk/Disabled'
//  '<S85>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum/Sum_PID'
//  '<S86>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Sum Fdbk/Disabled'
//  '<S87>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode/Enabled'
//  '<S88>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tracking Mode Sum/Tracking Mode'
//  '<S89>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Integral/Passthrough'
//  '<S90>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Tsamp - Ngain/Passthrough'
//  '<S91>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/postSat Signal/Forward_Path'
//  '<S92>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/preSat Signal/Forward_Path'
//  '<S93>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup'
//  '<S94>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain'
//  '<S95>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter'
//  '<S96>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs'
//  '<S97>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain'
//  '<S98>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain'
//  '<S99>'  : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk'
//  '<S100>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator'
//  '<S101>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs'
//  '<S102>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy'
//  '<S103>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain'
//  '<S104>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy'
//  '<S105>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain'
//  '<S106>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal'
//  '<S107>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation'
//  '<S108>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk'
//  '<S109>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum'
//  '<S110>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk'
//  '<S111>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode'
//  '<S112>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum'
//  '<S113>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral'
//  '<S114>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain'
//  '<S115>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal'
//  '<S116>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal'
//  '<S117>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Anti-windup/Passthrough'
//  '<S118>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/D Gain/External Parameters'
//  '<S119>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter'
//  '<S120>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter ICs/Internal IC - Filter'
//  '<S121>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/I Gain/External Parameters'
//  '<S122>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain/Passthrough'
//  '<S123>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Ideal P Gain Fdbk/Disabled'
//  '<S124>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete'
//  '<S125>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator ICs/Internal IC'
//  '<S126>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Copy/Disabled'
//  '<S127>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/N Gain/External Parameters'
//  '<S128>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/P Copy/Disabled'
//  '<S129>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Parallel P Gain/External Parameters'
//  '<S130>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Reset Signal/External Reset'
//  '<S131>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation/Passthrough'
//  '<S132>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Saturation Fdbk/Disabled'
//  '<S133>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum/Sum_PID'
//  '<S134>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Sum Fdbk/Disabled'
//  '<S135>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode/Enabled'
//  '<S136>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tracking Mode Sum/Tracking Mode'
//  '<S137>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Integral/Passthrough'
//  '<S138>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Tsamp - Ngain/Passthrough'
//  '<S139>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/postSat Signal/Forward_Path'
//  '<S140>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/preSat Signal/Forward_Path'
//  '<S141>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup'
//  '<S142>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain'
//  '<S143>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter'
//  '<S144>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs'
//  '<S145>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain'
//  '<S146>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain'
//  '<S147>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk'
//  '<S148>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator'
//  '<S149>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs'
//  '<S150>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy'
//  '<S151>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain'
//  '<S152>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy'
//  '<S153>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain'
//  '<S154>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal'
//  '<S155>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation'
//  '<S156>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk'
//  '<S157>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum'
//  '<S158>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk'
//  '<S159>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode'
//  '<S160>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum'
//  '<S161>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral'
//  '<S162>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain'
//  '<S163>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal'
//  '<S164>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal'
//  '<S165>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Anti-windup/Passthrough'
//  '<S166>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/D Gain/Disabled'
//  '<S167>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter/Disabled'
//  '<S168>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Filter ICs/Disabled'
//  '<S169>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/I Gain/External Parameters'
//  '<S170>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain/Passthrough'
//  '<S171>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Ideal P Gain Fdbk/Disabled'
//  '<S172>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete'
//  '<S173>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator ICs/Internal IC'
//  '<S174>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Copy/Disabled wSignal Specification'
//  '<S175>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/N Gain/Disabled'
//  '<S176>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/P Copy/Disabled'
//  '<S177>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Parallel P Gain/External Parameters'
//  '<S178>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Reset Signal/External Reset'
//  '<S179>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation/Passthrough'
//  '<S180>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Saturation Fdbk/Disabled'
//  '<S181>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum/Sum_PI'
//  '<S182>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Sum Fdbk/Disabled'
//  '<S183>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode/Enabled'
//  '<S184>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tracking Mode Sum/Tracking Mode'
//  '<S185>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Integral/Passthrough'
//  '<S186>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Tsamp - Ngain/Passthrough'
//  '<S187>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/postSat Signal/Forward_Path'
//  '<S188>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/preSat Signal/Forward_Path'
//  '<S189>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI QUOTA/Saturazione RC /Saturation Dynamic1'
//  '<S190>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/ATO'
//  '<S191>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1'
//  '<S192>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi '
//  '<S193>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup'
//  '<S194>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain'
//  '<S195>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter'
//  '<S196>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs'
//  '<S197>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain'
//  '<S198>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain'
//  '<S199>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk'
//  '<S200>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator'
//  '<S201>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs'
//  '<S202>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy'
//  '<S203>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain'
//  '<S204>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy'
//  '<S205>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain'
//  '<S206>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal'
//  '<S207>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation'
//  '<S208>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk'
//  '<S209>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum'
//  '<S210>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk'
//  '<S211>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode'
//  '<S212>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum'
//  '<S213>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral'
//  '<S214>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain'
//  '<S215>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal'
//  '<S216>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal'
//  '<S217>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S218>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S219>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S220>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/D Gain/External Parameters'
//  '<S221>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S222>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S223>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/I Gain/External Parameters'
//  '<S224>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain/Passthrough'
//  '<S225>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S226>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete'
//  '<S227>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator ICs/Internal IC'
//  '<S228>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Copy/Disabled'
//  '<S229>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/N Gain/External Parameters'
//  '<S230>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/P Copy/Disabled'
//  '<S231>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Parallel P Gain/External Parameters'
//  '<S232>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Reset Signal/Disabled'
//  '<S233>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation/Enabled'
//  '<S234>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Saturation Fdbk/Disabled'
//  '<S235>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum/Sum_PID'
//  '<S236>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Sum Fdbk/Disabled'
//  '<S237>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode/Enabled'
//  '<S238>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tracking Mode Sum/Tracking Mode'
//  '<S239>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Integral/Passthrough'
//  '<S240>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S241>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/postSat Signal/Forward_Path'
//  '<S242>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/preSat Signal/Forward_Path'
//  '<S243>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Degrees to Radians'
//  '<S244>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI ROTTA/calcolo errore Psi /Radians to Degrees'
//  '<S245>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller'
//  '<S246>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch'
//  '<S247>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing'
//  '<S248>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup'
//  '<S249>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain'
//  '<S250>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter'
//  '<S251>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs'
//  '<S252>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain'
//  '<S253>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain'
//  '<S254>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk'
//  '<S255>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator'
//  '<S256>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs'
//  '<S257>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy'
//  '<S258>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain'
//  '<S259>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy'
//  '<S260>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain'
//  '<S261>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal'
//  '<S262>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation'
//  '<S263>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk'
//  '<S264>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum'
//  '<S265>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk'
//  '<S266>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode'
//  '<S267>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum'
//  '<S268>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral'
//  '<S269>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain'
//  '<S270>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal'
//  '<S271>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal'
//  '<S272>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S273>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S274>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S275>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/D Gain/Disabled'
//  '<S276>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter/Disabled'
//  '<S277>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Filter ICs/Disabled'
//  '<S278>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/I Gain/External Parameters'
//  '<S279>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain/Passthrough'
//  '<S280>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S281>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete'
//  '<S282>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator ICs/Internal IC'
//  '<S283>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S284>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/N Gain/Disabled'
//  '<S285>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/P Copy/Disabled'
//  '<S286>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Parallel P Gain/External Parameters'
//  '<S287>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Reset Signal/Disabled'
//  '<S288>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation/Enabled'
//  '<S289>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Saturation Fdbk/Disabled'
//  '<S290>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum/Sum_PI'
//  '<S291>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Sum Fdbk/Disabled'
//  '<S292>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode/Enabled'
//  '<S293>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S294>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Integral/Passthrough'
//  '<S295>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S296>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/postSat Signal/Forward_Path'
//  '<S297>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/preSat Signal/Forward_Path'
//  '<S298>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/Smooth Switch/Smooth Bypass'
//  '<S299>' : 'Aenea_model/AUTOPILOTA/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/throttle - landing/Enabled Subsystem'
//  '<S300>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID'
//  '<S301>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1'
//  '<S302>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Filtro Washout1'
//  '<S303>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/manetta - takeoff'
//  '<S304>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller'
//  '<S305>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - landing'
//  '<S306>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff'
//  '<S307>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup'
//  '<S308>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain'
//  '<S309>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter'
//  '<S310>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs'
//  '<S311>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain'
//  '<S312>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain'
//  '<S313>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk'
//  '<S314>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator'
//  '<S315>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs'
//  '<S316>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy'
//  '<S317>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain'
//  '<S318>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy'
//  '<S319>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain'
//  '<S320>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal'
//  '<S321>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation'
//  '<S322>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk'
//  '<S323>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum'
//  '<S324>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk'
//  '<S325>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode'
//  '<S326>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum'
//  '<S327>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral'
//  '<S328>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain'
//  '<S329>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal'
//  '<S330>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal'
//  '<S331>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Anti-windup/Back Calculation'
//  '<S332>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/D Gain/Disabled'
//  '<S333>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter/Disabled'
//  '<S334>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Filter ICs/Disabled'
//  '<S335>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/I Gain/External Parameters'
//  '<S336>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S337>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S338>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete'
//  '<S339>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator ICs/Internal IC'
//  '<S340>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S341>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/N Gain/Disabled'
//  '<S342>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/P Copy/Disabled'
//  '<S343>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Parallel P Gain/External Parameters'
//  '<S344>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Reset Signal/Disabled'
//  '<S345>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation/Enabled'
//  '<S346>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S347>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum/Sum_PI'
//  '<S348>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Sum Fdbk/Disabled'
//  '<S349>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode/Enabled'
//  '<S350>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S351>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Integral/Passthrough'
//  '<S352>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S353>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/postSat Signal/Forward_Path'
//  '<S354>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/preSat Signal/Forward_Path'
//  '<S355>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID/elevator - takeoff/Degrees to Radians'
//  '<S356>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller'
//  '<S357>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup'
//  '<S358>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain'
//  '<S359>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter'
//  '<S360>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs'
//  '<S361>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain'
//  '<S362>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain'
//  '<S363>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk'
//  '<S364>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator'
//  '<S365>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs'
//  '<S366>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy'
//  '<S367>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain'
//  '<S368>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy'
//  '<S369>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain'
//  '<S370>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal'
//  '<S371>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation'
//  '<S372>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk'
//  '<S373>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum'
//  '<S374>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk'
//  '<S375>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode'
//  '<S376>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum'
//  '<S377>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral'
//  '<S378>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain'
//  '<S379>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal'
//  '<S380>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal'
//  '<S381>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Anti-windup/Back Calculation'
//  '<S382>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/D Gain/Disabled'
//  '<S383>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter/Disabled'
//  '<S384>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Filter ICs/Disabled'
//  '<S385>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/I Gain/External Parameters'
//  '<S386>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain/Passthrough'
//  '<S387>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S388>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete'
//  '<S389>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator ICs/Internal IC'
//  '<S390>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S391>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/N Gain/Disabled'
//  '<S392>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/P Copy/Disabled'
//  '<S393>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Parallel P Gain/External Parameters'
//  '<S394>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Reset Signal/External Reset'
//  '<S395>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation/Enabled'
//  '<S396>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Saturation Fdbk/Disabled'
//  '<S397>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum/Sum_PI'
//  '<S398>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Sum Fdbk/Disabled'
//  '<S399>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode/Enabled'
//  '<S400>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tracking Mode Sum/Tracking Mode'
//  '<S401>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Integral/Passthrough'
//  '<S402>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S403>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/postSat Signal/Forward_Path'
//  '<S404>' : 'Aenea_model/AUTOPILOTA/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/preSat Signal/Forward_Path'
//  '<S405>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/ STATI'
//  '<S406>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento'
//  '<S407>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe'
//  '<S408>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager'
//  '<S409>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/MATLAB Function'
//  '<S410>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees'
//  '<S411>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees1'
//  '<S412>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Radians to Degrees2'
//  '<S413>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager'
//  '<S414>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/abs comandi manuali'
//  '<S415>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Enabled Subsystem'
//  '<S416>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem'
//  '<S417>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Intervento/Resettable Subsystem/CLOCK'
//  '<S418>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Enabled Subsystem'
//  '<S419>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem'
//  '<S420>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Interruttore_Safe/Resettable Subsystem/CLOCK'
//  '<S421>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec'
//  '<S422>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec'
//  '<S423>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/MATLAB Function1'
//  '<S424>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Enabled '
//  '<S425>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem'
//  '<S426>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_0.5sec/Resettable Subsystem/CLOCK'
//  '<S427>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Enabled '
//  '<S428>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem'
//  '<S429>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Intervento Manager/Alarm_Timing_1sec/Resettable Subsystem/CLOCK'
//  '<S430>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing'
//  '<S431>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/MATLAB Function1'
//  '<S432>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Enabled '
//  '<S433>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem'
//  '<S434>' : 'Aenea_model/AUTOPILOTA/GESTIONE AUTOPILOTI1/Safe Manager/Alarm_Timing/Resettable Subsystem/CLOCK'
//  '<S435>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Chart'
//  '<S436>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO'
//  '<S437>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem'
//  '<S438>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1'
//  '<S439>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2'
//  '<S440>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3'
//  '<S441>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Chart1'
//  '<S442>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees'
//  '<S443>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Radians to Degrees1'
//  '<S444>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold'
//  '<S445>' : 'Aenea_model/AUTOPILOTA/Subsystem1/DECOLLO AUTOMATICO/Sample and Hold1'
//  '<S446>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem/Radians to Degrees3'
//  '<S447>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem/VETTORIALE'
//  '<S448>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/ALLINEAMENTO'
//  '<S449>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH'
//  '<S450>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CALIBRATING_HOME_COORDINATES'
//  '<S451>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT '
//  '<S452>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Chart1'
//  '<S453>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/FLARE'
//  '<S454>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA'
//  '<S455>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth'
//  '<S456>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees10'
//  '<S457>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees11'
//  '<S458>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees16'
//  '<S459>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees17'
//  '<S460>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees4'
//  '<S461>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees5'
//  '<S462>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Radians to Degrees6'
//  '<S463>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/Sample and Hold'
//  '<S464>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/APPROACH/MATLAB Function'
//  '<S465>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /AUTOLANDING_WAYPOINTS'
//  '<S466>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /MATLAB Function'
//  '<S467>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees'
//  '<S468>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/CREAZIONE_WAYPOINT /Radians to Degrees1'
//  '<S469>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller'
//  '<S470>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/Radians to Degrees2'
//  '<S471>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup'
//  '<S472>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain'
//  '<S473>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter'
//  '<S474>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs'
//  '<S475>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain'
//  '<S476>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain'
//  '<S477>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk'
//  '<S478>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator'
//  '<S479>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs'
//  '<S480>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy'
//  '<S481>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain'
//  '<S482>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy'
//  '<S483>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain'
//  '<S484>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal'
//  '<S485>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation'
//  '<S486>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk'
//  '<S487>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum'
//  '<S488>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk'
//  '<S489>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode'
//  '<S490>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum'
//  '<S491>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral'
//  '<S492>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain'
//  '<S493>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal'
//  '<S494>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal'
//  '<S495>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Anti-windup/Passthrough'
//  '<S496>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/D Gain/Disabled'
//  '<S497>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disabled'
//  '<S498>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter ICs/Disabled'
//  '<S499>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/I Gain/External Parameters'
//  '<S500>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain/Passthrough'
//  '<S501>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S502>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete'
//  '<S503>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator ICs/Internal IC'
//  '<S504>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S505>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/N Gain/Disabled'
//  '<S506>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/P Copy/Disabled'
//  '<S507>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Parallel P Gain/External Parameters'
//  '<S508>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Reset Signal/Disabled'
//  '<S509>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation/Passthrough'
//  '<S510>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Saturation Fdbk/Disabled'
//  '<S511>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum/Sum_PI'
//  '<S512>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Sum Fdbk/Disabled'
//  '<S513>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode/Disabled'
//  '<S514>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S515>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Integral/Passthrough'
//  '<S516>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S517>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/postSat Signal/Forward_Path'
//  '<S518>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/preSat Signal/Forward_Path'
//  '<S519>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Degrees to Radians'
//  '<S520>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap'
//  '<S521>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0'
//  '<S522>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1'
//  '<S523>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90'
//  '<S524>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude'
//  '<S525>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S526>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S527>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S528>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S529>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90'
//  '<S530>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude'
//  '<S531>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Compare To Constant'
//  '<S532>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180'
//  '<S533>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S534>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/LatLong wrap LL0/Wrap Longitude/Compare To Constant'
//  '<S535>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem'
//  '<S536>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Degrees to Radians'
//  '<S537>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem'
//  '<S538>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/Subsystem1'
//  '<S539>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem1/LLA to Flat Earth/Subsystem1/Subsystem/denom'
//  '<S540>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees'
//  '<S541>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees1'
//  '<S542>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/Radians to Degrees2'
//  '<S543>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem2/WAYPOINTS'
//  '<S544>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/GO_HOME'
//  '<S545>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees12'
//  '<S546>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees13'
//  '<S547>' : 'Aenea_model/AUTOPILOTA/Subsystem1/Subsystem3/Radians to Degrees9'
//  '<S548>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians'
//  '<S549>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians1'
//  '<S550>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians2'
//  '<S551>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Degrees to Radians3'
//  '<S552>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass'
//  '<S553>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Filter2'
//  '<S554>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2'
//  '<S555>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS'
//  '<S556>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Discrete Varying Lowpass/FOS/MATLAB Function'
//  '<S557>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/Filter2/DEFINITIVA'
//  '<S558>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1'
//  '<S559>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti'
//  '<S560>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/MATLAB Function2'
//  '<S561>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Sample and Hold'
//  '<S562>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function'
//  '<S563>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock GPS1/MATLAB Function1'
//  '<S564>' : 'Aenea_model/MISURE DA SENSORI  FILTRATE/initializer//Clk_generator 2/Clock Mti/MATLAB Function'
//  '<S565>' : 'Aenea_model/Misure Sensori/BMP_280'
//  '<S566>' : 'Aenea_model/Misure Sensori/GPS_Venus'
//  '<S567>' : 'Aenea_model/Misure Sensori/MTi'
//  '<S568>' : 'Aenea_model/Misure Sensori/BMP_280/Dynamic rate limiter'
//  '<S569>' : 'Aenea_model/Misure Sensori/BMP_280/Execution_loop'
//  '<S570>' : 'Aenea_model/Misure Sensori/BMP_280/MATLAB Function'
//  '<S571>' : 'Aenea_model/Misure Sensori/BMP_280/Subsystem'
//  '<S572>' : 'Aenea_model/Misure Sensori/BMP_280/Dynamic rate limiter/Saturation Dynamic'
//  '<S573>' : 'Aenea_model/Misure Sensori/BMP_280/Subsystem/Subsystem1'
//  '<S574>' : 'Aenea_model/Misure Sensori/GPS_Venus/Subsystem2'
//  '<S575>' : 'Aenea_model/RADIOCOMANDO/AILERON'
//  '<S576>' : 'Aenea_model/RADIOCOMANDO/AILERON1'
//  '<S577>' : 'Aenea_model/RADIOCOMANDO/ELEVATOR'
//  '<S578>' : 'Aenea_model/RADIOCOMANDO/ELEVATOR1'
//  '<S579>' : 'Aenea_model/RADIOCOMANDO/RUDDER'
//  '<S580>' : 'Aenea_model/RADIOCOMANDO/THROTTLE'
//  '<S581>' : 'Aenea_model/Servi/AILERON1'
//  '<S582>' : 'Aenea_model/Servi/RUDDER6'
//  '<S583>' : 'Aenea_model/Servi/THROTTLE1'
//  '<S584>' : 'Aenea_model/Servi/elevator'

#endif                                 // RTW_HEADER_Aenea_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
