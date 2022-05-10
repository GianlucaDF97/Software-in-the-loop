/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_15_data.c
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

#include "load_arduino_v_15.h"
#include "load_arduino_v_15_private.h"

/* Block parameters (default storage) */
P_load_arduino_v_15_T load_arduino_v_15_P = {
  /* Variable: Kd_h_app
   * Referenced by: '<S45>/Constant14'
   */
  0.085,

  /* Variable: Kd_h_flare
   * Referenced by: '<S45>/Constant9'
   */
  0.01,

  /* Variable: Ki_h_app
   * Referenced by: '<S45>/Constant7'
   */
  0.055,

  /* Variable: Ki_h_cruise
   * Referenced by: '<S45>/Constant10'
   */
  0.008,

  /* Variable: Ki_h_flare
   * Referenced by: '<S45>/Constant12'
   */
  0.07,

  /* Variable: Kp_AP_quota_hold_h
   * Referenced by: '<S8>/Saturation'
   */
  0.5503,

  /* Variable: Kp_AP_quota_hold_l
   * Referenced by: '<S8>/Saturation'
   */
  0.5503,

  /* Variable: Kp_Rotta_ATO
   * Referenced by: '<S196>/Constant3'
   */
  4.0,

  /* Variable: Kp_Rotta_psi
   * Referenced by:
   *   '<S304>/Constant3'
   *   '<S304>/Constant4'
   */
  -0.01,

  /* Variable: Kp_comp_h
   * Referenced by: '<S305>/Constant3'
   */
  0.035,

  /* Variable: Kp_h_cruise
   * Referenced by: '<S45>/Constant5'
   */
  0.04,

  /* Variable: Kp_h_flare
   * Referenced by: '<S45>/Constant11'
   */
  0.1,

  /* Variable: V_max
   * Referenced by: '<S40>/Constant'
   */
  30.0,

  /* Variable: V_stall
   * Referenced by:
   *   '<S452>/Constant1'
   *   '<S455>/Constant6'
   *   '<S320>/Switch1'
   *   '<S466>/Constant1'
   *   '<S470>/Constant1'
   */
  11.0,

  /* Variable: attuatore_Amax
   * Referenced by:
   *   '<S39>/saturatore A'
   *   '<S39>/saturatore A1'
   *   '<S594>/Constant8'
   *   '<S598>/Constant'
   *   '<S410>/Saturation'
   */
  0.47123889803846897,

  /* Variable: attuatore_Amin
   * Referenced by:
   *   '<S39>/saturatore A'
   *   '<S39>/saturatore A1'
   *   '<S594>/Constant9'
   *   '<S598>/Constant1'
   *   '<S410>/Saturation'
   */
  -0.4014257279586958,

  /* Variable: attuatore_Emax
   * Referenced by:
   *   '<S595>/Constant8'
   *   '<S601>/Constant'
   *   '<S305>/saturatore E2'
   *   '<S360>/Saturation'
   */
  0.31415926535897931,

  /* Variable: attuatore_Emin
   * Referenced by:
   *   '<S595>/Constant9'
   *   '<S601>/Constant1'
   *   '<S305>/saturatore E2'
   *   '<S360>/Saturation'
   */
  -0.55850536063818546,

  /* Variable: attuatore_Rmax
   * Referenced by:
   *   '<S39>/saturatore R'
   *   '<S596>/Constant8'
   *   '<S599>/Constant'
   */
  0.52359877559829882,

  /* Variable: attuatore_Rmin
   * Referenced by:
   *   '<S39>/saturatore R'
   *   '<S596>/Constant9'
   *   '<S599>/Constant1'
   */
  -0.52359877559829882,

  /* Variable: attuatore_Tmax
   * Referenced by:
   *   '<S39>/Saturation'
   *   '<S597>/manetta_massima'
   *   '<S310>/Discrete-Time Integrator'
   *   '<S293>/Saturation'
   *   '<S279>/DeadZone'
   */
  1.0,

  /* Variable: attuatore_Tmin
   * Referenced by:
   *   '<S39>/Saturation'
   *   '<S597>/manetta_minima'
   *   '<S293>/Saturation'
   *   '<S279>/DeadZone'
   */
  0.0,

  /* Variable: final_h
   * Referenced by: '<S452>/Constant'
   */
  35.0,

  /* Variable: interventoA_05
   * Referenced by: '<S424>/Constant4'
   */
  6.0,

  /* Variable: interventoA_1
   * Referenced by: '<S424>/Constant3'
   */
  2.0,

  /* Variable: interventoE_05
   * Referenced by: '<S424>/Constant1'
   */
  7.5,

  /* Variable: interventoE_1
   * Referenced by: '<S424>/Constant'
   */
  3.2,

  /* Variable: interventoT
   * Referenced by: '<S424>/Constant2'
   */
  0.1,

  /* Variable: inv_A
   * Referenced by: '<S39>/Gain1'
   */
  -1.0,

  /* Variable: inv_E
   * Referenced by: '<S39>/Gain'
   */
  1.0,

  /* Variable: inv_R
   * Referenced by: '<S39>/Gain2'
   */
  1.0,

  /* Variable: inv_T
   * Referenced by: '<S39>/Gain3'
   */
  1.0,

  /* Variable: inv_comp_h
   * Referenced by: '<S305>/Gain'
   */
  -1.0,

  /* Variable: safe_V
   * Referenced by: '<S429>/Constant'
   */
  40.0,

  /* Variable: safe_phi
   * Referenced by: '<S429>/Constant1'
   */
  55.0,

  /* Variable: t_AP
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
  0.02,

  /* Variable: theta_rot
   * Referenced by: '<S452>/Constant2'
   */
  10.0,

  /* Variable: time_alarm_SAFE
   * Referenced by: '<S448>/Switch'
   */
  1.0,

  /* Variable: vel_wp1_al
   * Referenced by: '<S468>/Constant'
   */
  25.0,

  /* Variable: vel_wp2_al
   * Referenced by: '<S468>/Constant1'
   */
  20.0,

  /* Variable: Ki_AP_vel
   * Referenced by: '<S8>/Ki AP velocità'
   */
  0.025175F,

  /* Variable: Ki_becch
   * Referenced by: '<S8>/Ki controllore  beccheggio1'
   */
  -0.1963F,

  /* Variable: Ki_roll
   * Referenced by: '<S8>/Ki controllore  rollio3'
   */
  0.004528F,

  /* Variable: Kp_AP_rotta
   * Referenced by: '<S8>/Kp AP rotta'
   */
  0.52F,

  /* Variable: Kp_AP_vel
   * Referenced by: '<S8>/Kp AP velocità'
   */
  0.132175F,

  /* Variable: Kp_becch
   * Referenced by: '<S8>/Kp controllore beccheggio1'
   */
  -0.3F,

  /* Variable: Kp_imb
   * Referenced by: '<S8>/Kp controllore imbardata'
   */
  0.0019415F,

  /* Variable: Kp_p
   * Referenced by: '<S8>/Kp controllore  velocità rollio3'
   */
  0.006913F,

  /* Variable: Kp_q
   * Referenced by: '<S8>/Kp controllore velocità beccheggio1'
   */
  -0.025F,

  /* Variable: Kp_roll
   * Referenced by: '<S8>/Kp controllore  rollio3'
   */
  0.0718F,

  /* Variable: K_imb_inv
   * Referenced by: '<S8>/K controllo imbardata inversa'
   */
  0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S514>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S227>/Filter'
   */
  0.0,

  /* Mask Parameter: PIApproach_InitialConditionForF
   * Referenced by: '<S77>/Filter'
   */
  0.0,

  /* Mask Parameter: PIApproach1_InitialConditionFor
   * Referenced by: '<S125>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S519>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_n
   * Referenced by: '<S232>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditi_ld
   * Referenced by: '<S403>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_g
   * Referenced by: '<S286>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIRCsaturato_InitialConditionFo
   * Referenced by: '<S178>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIApproach_InitialConditionForI
   * Referenced by: '<S82>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIApproach1_InitialConditionF_n
   * Referenced by: '<S130>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_a
   * Referenced by: '<S353>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S346>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_Kb_g
   * Referenced by: '<S396>/Kb'
   */
  0.5,

  /* Mask Parameter: PIDController_Kt
   * Referenced by: '<S364>/Kt'
   */
  1.0,

  /* Mask Parameter: PIApproach_Kt
   * Referenced by: '<S93>/Kt'
   */
  1.0,

  /* Mask Parameter: PIApproach1_Kt
   * Referenced by: '<S141>/Kt'
   */
  1.0,

  /* Mask Parameter: PIRCsaturato_Kt
   * Referenced by: '<S189>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt_p
   * Referenced by: '<S297>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt_g
   * Referenced by: '<S414>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController1_Kt
   * Referenced by: '<S243>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by:
   *   '<S239>/Saturation'
   *   '<S225>/DeadZone'
   */
  -0.7854,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by:
   *   '<S239>/Saturation'
   *   '<S225>/DeadZone'
   */
  0.7854,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S550>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S548>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S551>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_k
   * Referenced by: '<S544>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S542>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S545>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S25>/Serial Transmit'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S36>/Constant2'
   */
  360.0,

  /* Expression: [Kp_AP_quota_hold_l Kp_AP_quota_hold_h]
   * Referenced by: '<S8>/n-D Lookup Table'
   */
  { 0.5503, 0.5503 },

  /* Expression: [V_stall*1.2 V_max*0.8]
   * Referenced by: '<S8>/n-D Lookup Table'
   */
  { 13.2, 24.0 },

  /* Expression: [15;20;25;30;35;40]
   * Referenced by: '<S47>/Lookup Table2'
   */
  { 15.0, 20.0, 25.0, 30.0, 35.0, 40.0 },

  /* Expression: [2;2.5;3;3.5;4;4]
   * Referenced by: '<S47>/Lookup Table2'
   */
  { 2.0, 2.5, 3.0, 3.5, 4.0, 4.0 },

  /* Expression: 0
   * Referenced by: '<S196>/Constant4'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S198>/Switch'
   */
  180.0,

  /* Expression: [1]
   * Referenced by: '<S303>/Out1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S303>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S252>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S252>/Switch'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S317>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S318>/Constant2'
   */
  360.0,

  /* Expression: 180/pi
   * Referenced by: '<S312>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S313>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S320>/Constant5'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S315>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S316>/Constant2'
   */
  360.0,

  /* Expression: 180/pi
   * Referenced by: '<S314>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S316>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S315>/Switch2'
   */
  0.0,

  /* Expression: 0.15
   * Referenced by: '<S304>/Switch3'
   */
  0.15,

  /* Expression: 0.15
   * Referenced by: '<S308>/Switch4'
   */
  0.15,

  /* Expression: pi/180
   * Referenced by: '<S420>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S440>/Alarm_Int'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S443>/Alarm_Int'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S448>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S448>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S448>/Alarm Safe'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S450>/Memory'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S40>/Constant1'
   */
  20.0,

  /* Expression: 180/pi
   * Referenced by: '<S427>/Gain'
   */
  57.295779513082323,

  /* Expression: initCond
   * Referenced by: '<S461>/ '
   */
  0.0,

  /* Expression: initCond
   * Referenced by: '<S462>/ '
   */
  0.0,

  /* Computed Parameter: rotta_ATO_Y0
   * Referenced by: '<S452>/rotta_ATO'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S452>/Memory'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S459>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S452>/Memory1'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S460>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Out1_Y0_f
   * Referenced by: '<S454>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S454>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S454>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S454>/Out4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S454>/Memory3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S463>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: h_ref_Y0
   * Referenced by: '<S466>/h_ref'
   */
  0.0,

  /* Computed Parameter: flare_data_Y0
   * Referenced by: '<S466>/flare_data'
   */
  0.0,

  /* Computed Parameter: landing_abort_Y0
   * Referenced by: '<S466>/landing_abort'
   */
  0.0,

  /* Computed Parameter: rc_ref_app_Y0
   * Referenced by: '<S466>/rc_ref_app'
   */
  0.0,

  /* Expression: -100
   * Referenced by: '<S466>/x_g0'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S466>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S466>/Constant4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S466>/Discrete-Time Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S466>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S466>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S466>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S466>/Switch'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S466>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S466>/Constant2'
   */
  1.0,

  /* Computed Parameter: h_ref_Y0_b
   * Referenced by: '<S470>/h_ref'
   */
  0.0,

  /* Computed Parameter: RC_ref_Y0
   * Referenced by: '<S470>/RC_ref'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S470>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S470>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S470>/Gain2'
   */
  -1.0,

  /* Computed Parameter: psi_ref_landing_Y0
   * Referenced by: '<S471>/psi_ref_landing'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S471>/Gain1'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S471>/psi ref gain2'
   */
  0.1,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S514>/Filter'
   */
  0.02,

  /* Expression: 50
   * Referenced by: '<S471>/psi ref gain3'
   */
  50.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S519>/Integrator'
   */
  0.02,

  /* Expression: 0.0042
   * Referenced by: '<S471>/psi ref gain'
   */
  0.0042,

  /* Expression: 180/pi
   * Referenced by: '<S487>/Gain'
   */
  57.295779513082323,

  /* Expression: 0.000072
   * Referenced by: '<S471>/psi ref gain1'
   */
  7.2E-5,

  /* Expression: -90
   * Referenced by: '<S540>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S540>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S540>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S543>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S543>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S543>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S537>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S537>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S541>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S541>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S541>/Bias1'
   */
  -180.0,

  /* Expression: -90
   * Referenced by: '<S546>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S546>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S546>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S549>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S549>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S549>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S538>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S538>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S547>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S547>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S547>/Bias1'
   */
  -180.0,

  /* Expression: initCond
   * Referenced by: '<S480>/ '
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S455>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S455>/Constant8'
   */
  0.0,

  /* Computed Parameter: TAS_AL_Y0
   * Referenced by: '<S455>/TAS_AL'
   */
  0.0,

  /* Computed Parameter: QUOTA_AL_Y0
   * Referenced by: '<S455>/QUOTA_AL'
   */
  0.0,

  /* Computed Parameter: RC_AL_Y0
   * Referenced by: '<S455>/RC_AL'
   */
  0.0,

  /* Computed Parameter: ROTTA_AL_Y0
   * Referenced by: '<S455>/ROTTA_AL'
   */
  0.0,

  /* Expression: [-1000 -800 2000]
   * Referenced by: '<S468>/distance waypoints virtuale'
   */
  { -1000.0, -800.0, 2000.0 },

  /* Expression: 180/pi
   * Referenced by: '<S484>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S485>/Gain'
   */
  57.295779513082323,

  /* Expression: [45 45 45]
   * Referenced by: '<S468>/alt waypoint virtuale'
   */
  { 45.0, 45.0, 45.0 },

  /* Expression: 180/pi
   * Referenced by: '<S476>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S475>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S473>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S474>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S536>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S552>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S556>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S555>/Constant4'
   */
  1.0,

  /* Expression: 1/298.257223563
   * Referenced by: '<S554>/Constant'
   */
  0.0033528106647474805,

  /* Expression: 1
   * Referenced by: '<S554>/f'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S553>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 6378137
   * Referenced by: '<S552>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S552>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S552>/Constant3'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S477>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S478>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S479>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S455>/Memory7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S455>/Memory5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S455>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S455>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S455>/Constant4'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S455>/Constant1'
   */
  2.0,

  /* Expression: -2
   * Referenced by: '<S455>/Constant7'
   */
  -2.0,

  /* Expression: 45
   * Referenced by: '<S455>/Constant2'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S455>/latezza carrello'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S455>/Switch2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S455>/Switch1'
   */
  1.0,

  /* Computed Parameter: RC_Y0
   * Referenced by: '<S456>/RC'
   */
  0.0,

  /* Computed Parameter: VELOCITA_Y0
   * Referenced by: '<S456>/VELOCITA'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_j
   * Referenced by: '<S456>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_e
   * Referenced by: '<S456>/Out4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S456>/Memory4'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S557>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S558>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S559>/Gain'
   */
  57.295779513082323,

  /* Expression: 40
   * Referenced by: '<S456>/saturatore V'
   */
  40.0,

  /* Expression: 15
   * Referenced by: '<S456>/saturatore V'
   */
  15.0,

  /* Expression: 2
   * Referenced by: '<S456>/saturatore V1'
   */
  2.0,

  /* Expression: -2
   * Referenced by: '<S456>/saturatore V1'
   */
  -2.0,

  /* Computed Parameter: Out1_Y0_j
   * Referenced by: '<S457>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0_n
   * Referenced by: '<S457>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_e
   * Referenced by: '<S457>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_n
   * Referenced by: '<S457>/Out4'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S562>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S563>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S564>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S571>/Serial Receive'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S571>/Serial Transmit'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S6>/Switch2'
   */
  2.0,

  /* Expression: 16
   * Referenced by: '<S582>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S582>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S582>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S582>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S582>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S582>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S579>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S589>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S589>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S589>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S589>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S589>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S592>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S592>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S223>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S277>/Constant1'
   */
  0.0,

  /* Expression: 15
   * Referenced by: '<S586>/Constant'
   */
  15.0,

  /* Expression: 0.01
   * Referenced by: '<S571>/Gain1'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S571>/Gain4'
   */
  0.01,

  /* Expression: pi/180
   * Referenced by: '<S565>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S426>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S40>/Constant2'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S569>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S570>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S567>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S566>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 15
   * Referenced by: '<S6>/Switch1'
   */
  15.0,

  /* Computed Parameter: RateLimiter1_RisingLim
   * Referenced by: '<S6>/Rate Limiter1'
   */
  0.12,

  /* Computed Parameter: RateLimiter1_FallingLim
   * Referenced by: '<S6>/Rate Limiter1'
   */
  -0.12,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Limiter1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S306>/Constant1'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S568>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 2
   * Referenced by: '<S41>/RC_default'
   */
  2.0,

  /* Expression: 70
   * Referenced by: '<S41>/Constant'
   */
  70.0,

  /* Expression: 20
   * Referenced by: '<S41>/Constant1'
   */
  20.0,

  /* Expression: 5
   * Referenced by: '<S43>/Switch'
   */
  5.0,

  /* Expression: 180/pi
   * Referenced by: '<S250>/Gain'
   */
  57.295779513082323,

  /* Expression: 360
   * Referenced by: '<S198>/Constant'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S198>/Constant1'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S198>/Constant2'
   */
  360.0,

  /* Expression: -180
   * Referenced by: '<S198>/Switch1'
   */
  -180.0,

  /* Expression: pi/180
   * Referenced by: '<S249>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 2
   * Referenced by: '<S196>/Switch3'
   */
  2.0,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S232>/Integrator'
   */
  0.02,

  /* Expression: 2
   * Referenced by: '<S196>/Switch4'
   */
  2.0,

  /* Computed Parameter: Filter_gainval_d
   * Referenced by: '<S227>/Filter'
   */
  0.02,

  /* Expression: 70
   * Referenced by: '<S43>/Constant'
   */
  70.0,

  /* Expression: 0
   * Referenced by: '<S309>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S308>/Constant5'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S306>/Constant3'
   */
  2.0,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S403>/Integrator'
   */
  0.02,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S286>/Integrator'
   */
  0.02,

  /* Expression: 0.3
   * Referenced by: '<S252>/Hit  Crossing'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S310>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S310>/Constant8'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
   * Referenced by: '<S310>/Discrete-Time Integrator'
   */
  0.0003,

  /* Expression: 0
   * Referenced by: '<S310>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S310>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: RateLimiter_RisingLim
   * Referenced by: '<S39>/Rate Limiter'
   */
  0.006,

  /* Computed Parameter: RateLimiter_FallingLim
   * Referenced by: '<S39>/Rate Limiter'
   */
  -0.006,

  /* Expression: 0
   * Referenced by: '<S39>/Rate Limiter'
   */
  0.0,

  /* Expression: [ 1 -1]
   * Referenced by: '<S307>/Discrete Washout Filter'
   */
  { 1.0, -1.0 },

  /* Expression: [1 -0.995]
   * Referenced by: '<S307>/Discrete Washout Filter'
   */
  { 1.0, -0.995 },

  /* Expression: 0
   * Referenced by: '<S307>/Discrete Washout Filter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/r_rif'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S304>/Switch2'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S317>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S318>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S305>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S305>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S45>/Constant2'
   */
  0.0,

  /* Expression: -5
   * Referenced by: '<S47>/Constant'
   */
  -5.0,

  /* Computed Parameter: Integrator_gainval_hq
   * Referenced by: '<S178>/Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S45>/Constant1'
   */
  0.0,

  /* Expression: [Kp_h_app_max Kp_h_app_min]
   * Referenced by: '<S45>/n-D Lookup Table'
   */
  { 0.086, 0.01 },

  /* Expression: [V_stall*1.2  V_max*0.75]
   * Referenced by: '<S45>/n-D Lookup Table'
   */
  { 13.2, 22.5 },

  /* Expression: 0.046
   * Referenced by: '<S45>/Saturation'
   */
  0.046,

  /* Expression: 0.01
   * Referenced by: '<S45>/Saturation'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_f
   * Referenced by: '<S82>/Integrator'
   */
  0.02,

  /* Computed Parameter: Filter_gainval_a
   * Referenced by: '<S77>/Filter'
   */
  0.02,

  /* Expression: 30
   * Referenced by: '<S45>/Constant15'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S45>/Constant3'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S130>/Integrator'
   */
  0.02,

  /* Computed Parameter: Filter_gainval_d1
   * Referenced by: '<S125>/Filter'
   */
  0.02,

  /* Expression: 40
   * Referenced by: '<S45>/Constant13'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S311>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_e
   * Referenced by: '<S353>/Integrator'
   */
  0.02,

  /* Expression: pi/180
   * Referenced by: '<S370>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S29>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S29>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S29>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S29>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S29>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S29>/Memory'
   */
  -0.02,

  /* Expression: 100
   * Referenced by: '<S19>/Gain'
   */
  100.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S7>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1000
   * Referenced by: '<S21>/Gain'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S21>/Gain2'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant2'
   */
  0.0,

  /* Expression: 10^3
   * Referenced by: '<S18>/Gain'
   */
  1000.0,

  /* Expression: 180/pi
   * Referenced by: '<S26>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S27>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S16>/alt_r'
   */
  0.0,

  /* Expression: [10^7;10^7;1000 ;1000]
   * Referenced by: '<S16>/Gain'
   */
  { 1.0E+7, 1.0E+7, 1000.0, 1000.0 },

  /* Expression: 0
   * Referenced by: '<S16>/vel y'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S16>/Gain1'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S16>/Gain2'
   */
  100.0,

  /* Expression: 180/pi
   * Referenced by: '<S35>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S36>/Switch2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: 100/9000
   * Referenced by: '<S22>/USCITA PERCENTUALE'
   */
  0.011111111111111112,

  /* Expression: 4
   * Referenced by: '<S20>/Constant'
   */
  4.0,

  /* Expression: 100
   * Referenced by: '<S31>/Gain2'
   */
  100.0,

  /* Expression: 180/pi
   * Referenced by: '<S32>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S31>/Constant2'
   */
  90.0,

  /* Expression: 180/pi
   * Referenced by: '<S33>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S34>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S20>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 100
   * Referenced by: '<S20>/Gain'
   */
  100.0,

  /* Expression: 4000
   * Referenced by: '<S20>/Saturation'
   */
  4000.0,

  /* Expression: 0
   * Referenced by: '<S20>/Saturation'
   */
  0.0,

  /* Expression: 101325
   * Referenced by: '<S581>/Delay Input2'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S581>/sample time'
   */
  0.02,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa'
   */
  0.01,

  /* Expression: 100
   * Referenced by: '<S571>/Gain7'
   */
  100.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa1'
   */
  0.01,

  /* Expression: 180/pi
   * Referenced by: '<S572>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S573>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S574>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S571>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S571>/Gain2'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S571>/Gain3'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S6>/Constant1'
   */
  10.0,

  /* Expression: 100
   * Referenced by: '<S571>/Gain6'
   */
  100.0,

  /* Expression: 180/pi
   * Referenced by: '<S428>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S277>/ZeroGain'
   */
  0.0,

  /* Expression: Ki_AP_rotta
   * Referenced by: '<S43>/Constant2'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S223>/ZeroGain'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S310>/Constant7'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator'
   */
  1.0,

  /* Expression: 25
   * Referenced by: '<S5>/Pulse Generator'
   */
  25.0,

  /* Expression: 2
   * Referenced by: '<S5>/Pulse Generator'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator1'
   */
  1.0,

  /* Expression: 25
   * Referenced by: '<S5>/Pulse Generator1'
   */
  25.0,

  /* Expression: 2
   * Referenced by: '<S5>/Pulse Generator1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S29>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S29>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S29>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_gw
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: Out2_Y0_c
   * Referenced by: '<S577>/Out2'
   */
  0.0F,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S582>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S588>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S586>/Switch'
   */
  0.0F,

  /* Expression: Ki_AP_rotta
   * Referenced by: '<S8>/Ki AP rotta1'
   */
  0.002F,

  /* Computed Parameter: Gain5_Gain
   * Referenced by: '<S571>/Gain5'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S582>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value_h
   * Referenced by: '<S582>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S582>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S582>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_e
   * Referenced by: '<S582>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S582>/Constant9'
   */
  0U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S21>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Out3_Y0_a
   * Referenced by: '<S577>/Out3'
   */
  0,

  /* Computed Parameter: Switch_Threshold_m
   * Referenced by: '<S9>/Switch'
   */
  1500,

  /* Computed Parameter: Gain1_Gain_eu
   * Referenced by: '<S21>/Gain1'
   */
  26214,

  /* Computed Parameter: Out4_Y0_i
   * Referenced by: '<S577>/Out4'
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_at
   * Referenced by: '<S1>/Memory'
   */
  0U,

  /* Computed Parameter: loaduint16_Value
   * Referenced by: '<S21>/load uint16'
   */
  10U,

  /* Computed Parameter: _Value
   * Referenced by: '<S21>/ '
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_g
   * Referenced by: '<S2>/Memory'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S578>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_ok
   * Referenced by: '<S578>/Constant3'
   */
  1,

  /* Computed Parameter: Memory_InitialCondition_af
   * Referenced by: '<S454>/Memory'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_k
   * Referenced by: '<S454>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_g
   * Referenced by: '<S454>/Memory2'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S454>/Memory6'
   */
  0U,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S592>/mario'
   */
  0U,

  /* Expression: uint8(zeros(3,100))
   * Referenced by: '<S1>/Memory4'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Constant1_Value_a
   * Referenced by: '<S1>/Constant1'
   */
  1U,

  /* Computed Parameter: SIUAVuint8_Value
   * Referenced by: '<Root>/SI UAV uint8'
   */
  100U,

  /* Computed Parameter: Memory5_InitialCondition_d
   * Referenced by: '<S1>/Memory5'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_b
   * Referenced by: '<S1>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory_InitialCondition_o
   * Referenced by: '<Root>/Memory'
   */
  0U,

  /* Computed Parameter: Memory3_InitialCondition_c
   * Referenced by: '<S1>/Memory3'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_go
   * Referenced by: '<S1>/Memory2'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Typefixed_wingAutopilotgeneric_
   * Referenced by: '<S17>/Type fixed_wing Autopilot generic'
   */
  { 1U, 0U },

  /* Computed Parameter: InizioMSG_Value
   * Referenced by: '<S571>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<S571>/Fine MSG1'
   */
  60U,

  /* Start of '<S578>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S585>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S585>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S585>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S585>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S585>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S585>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S585>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S585>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S585>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S585>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S585>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S585>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S585>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S585>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S585>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S585>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S585>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S585>/Constant4'
     */
    47U
  }
  ,

  /* End of '<S578>/One_time_initialization' */

  /* Start of '<S423>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S436>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S423>/Resettable Subsystem' */

  /* Start of '<S423>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S434>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S434>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S434>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S434>/Switch'
     */
    2.0
  }
  ,

  /* End of '<S423>/Enabled Subsystem' */

  /* Start of '<S422>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S433>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S422>/Resettable Subsystem' */

  /* Start of '<S422>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S431>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S431>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S431>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S431>/Switch'
     */
    2.0
  }
  /* End of '<S422>/Enabled Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
