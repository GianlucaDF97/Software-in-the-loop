/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: laod_arduino_2021_data.c
 *
 * Code generated for Simulink model 'laod_arduino_2021'.
 *
 * Model version                  : 5.36
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct 29 16:05:53 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "laod_arduino_2021.h"
#include "laod_arduino_2021_private.h"

/* Block parameters (default storage) */
P_laod_arduino_2021_T laod_arduino_2021_P = {
  /* Variable: Kp_comp_h
   * Referenced by: '<S304>/Constant3'
   */
  0.035,

  /* Variable: attuatore_Amax
   * Referenced by:
   *   '<S39>/saturatore A'
   *   '<S39>/saturatore A1'
   *   '<S585>/Constant8'
   *   '<S591>/Constant'
   *   '<S399>/Saturation'
   */
  0.47123889803846897,

  /* Variable: attuatore_Amin
   * Referenced by:
   *   '<S39>/saturatore A'
   *   '<S39>/saturatore A1'
   *   '<S585>/Constant9'
   *   '<S591>/Constant1'
   *   '<S399>/Saturation'
   */
  -0.4014257279586958,

  /* Variable: attuatore_Emax
   * Referenced by:
   *   '<S587>/Constant8'
   *   '<S594>/Constant'
   *   '<S304>/saturatore E2'
   *   '<S349>/Saturation'
   */
  0.31415926535897931,

  /* Variable: attuatore_Emin
   * Referenced by:
   *   '<S587>/Constant9'
   *   '<S594>/Constant1'
   *   '<S304>/saturatore E2'
   *   '<S349>/Saturation'
   */
  -0.55850536063818546,

  /* Variable: attuatore_Rmax
   * Referenced by:
   *   '<S39>/saturatore R'
   *   '<S589>/Constant8'
   *   '<S592>/Constant'
   */
  0.52359877559829882,

  /* Variable: attuatore_Rmin
   * Referenced by:
   *   '<S39>/saturatore R'
   *   '<S589>/Constant9'
   *   '<S592>/Constant1'
   */
  -0.52359877559829882,

  /* Variable: attuatore_Tmax
   * Referenced by: '<S590>/manetta_massima'
   */
  1.0,

  /* Variable: attuatore_Tmin
   * Referenced by: '<S590>/manetta_minima'
   */
  0.0,

  /* Variable: interventoA_05
   * Referenced by: '<S412>/Constant4'
   */
  6.0,

  /* Variable: interventoA_1
   * Referenced by: '<S412>/Constant3'
   */
  2.0,

  /* Variable: interventoE_05
   * Referenced by: '<S412>/Constant1'
   */
  7.5,

  /* Variable: interventoE_1
   * Referenced by: '<S412>/Constant'
   */
  3.2,

  /* Variable: interventoT
   * Referenced by: '<S412>/Constant2'
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

  /* Variable: inv_comp_h
   * Referenced by: '<S304>/Gain'
   */
  -1.0,

  /* Variable: phi_max
   * Referenced by:
   *   '<S586>/Constant8'
   *   '<S586>/Saturation'
   */
  0.52359877559829882,

  /* Variable: phi_min
   * Referenced by:
   *   '<S586>/Constant9'
   *   '<S586>/Saturation'
   */
  -0.52359877559829882,

  /* Variable: safe_V
   * Referenced by: '<S417>/Constant'
   */
  40.0,

  /* Variable: safe_phi
   * Referenced by: '<S417>/Constant1'
   */
  55.0,

  /* Variable: t_AP
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
  0.02,

  /* Variable: theta_max
   * Referenced by:
   *   '<S588>/Constant8'
   *   '<S588>/Saturation'
   */
  0.26179938779914941,

  /* Variable: theta_min
   * Referenced by:
   *   '<S588>/Constant9'
   *   '<S588>/Saturation'
   */
  -0.26179938779914941,

  /* Variable: time_alarm_SAFE
   * Referenced by: '<S436>/Switch'
   */
  1.0,

  /* Variable: vel_wp1_al
   * Referenced by: '<S455>/Constant'
   */
  25.0,

  /* Variable: vel_wp2_al
   * Referenced by: '<S455>/Constant1'
   */
  20.0,

  /* Variable: Ki_becch
   * Referenced by: '<S8>/Ki controllore  beccheggio1'
   */
  -0.1963F,

  /* Variable: Ki_roll
   * Referenced by: '<S8>/Ki controllore  rollio3'
   */
  0.004528F,

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
   * Referenced by: '<S342>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_d
   * Referenced by: '<S392>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S385>/Kb'
   */
  0.5,

  /* Mask Parameter: PIDController_Kb_k
   * Referenced by: '<S335>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt
   * Referenced by: '<S403>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt_m
   * Referenced by: '<S353>/Kt'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S537>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S535>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S538>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S531>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_dp
   * Referenced by: '<S529>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S532>/Constant'
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

  /* Expression: [1]
   * Referenced by: '<S303>/Out1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S309>/Constant5'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S309>/Switch1'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<S39>/r_rif'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S428>/Alarm_Int'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S431>/Alarm_Int'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S436>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S436>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S436>/Alarm Safe'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S438>/Memory'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S40>/Constant1'
   */
  20.0,

  /* Expression: 180/pi
   * Referenced by: '<S415>/Gain'
   */
  57.295779513082323,

  /* Expression: 50
   * Referenced by: '<S40>/Constant'
   */
  50.0,

  /* Expression: initCond
   * Referenced by: '<S448>/ '
   */
  0.0,

  /* Expression: initCond
   * Referenced by: '<S449>/ '
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S447>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S440>/Memory'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S446>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S440>/Memory1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_d
   * Referenced by: '<S441>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S441>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S441>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S441>/Out4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S441>/Memory3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S450>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: h_ref_Y0
   * Referenced by: '<S453>/h_ref'
   */
  0.0,

  /* Computed Parameter: flare_data_Y0
   * Referenced by: '<S453>/flare_data'
   */
  0.0,

  /* Computed Parameter: landing_abort_Y0
   * Referenced by: '<S453>/landing_abort'
   */
  0.0,

  /* Computed Parameter: rc_ref_app_Y0
   * Referenced by: '<S453>/rc_ref_app'
   */
  0.0,

  /* Expression: -100
   * Referenced by: '<S453>/x_g0'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S453>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S453>/Constant4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S453>/Discrete-Time Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S453>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S453>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S453>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S453>/Switch'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S453>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S453>/Constant2'
   */
  1.0,

  /* Computed Parameter: h_ref_Y0_n
   * Referenced by: '<S457>/h_ref'
   */
  0.0,

  /* Computed Parameter: RC_ref_Y0
   * Referenced by: '<S457>/RC_ref'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S457>/Gain'
   */
  -1.0,

  /* Computed Parameter: psi_ref_landing_Y0
   * Referenced by: '<S458>/psi_ref_landing'
   */
  0.0,

  /* Expression: -90
   * Referenced by: '<S527>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S527>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S527>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S530>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S530>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S530>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S524>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S524>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S528>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S528>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S528>/Bias1'
   */
  -180.0,

  /* Expression: -90
   * Referenced by: '<S533>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S533>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S533>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S536>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S536>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S536>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S525>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S525>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S534>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S534>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S534>/Bias1'
   */
  -180.0,

  /* Expression: initCond
   * Referenced by: '<S467>/ '
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S442>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S442>/Constant8'
   */
  0.0,

  /* Computed Parameter: TAS_AL_Y0
   * Referenced by: '<S442>/TAS_AL'
   */
  0.0,

  /* Computed Parameter: QUOTA_AL_Y0
   * Referenced by: '<S442>/QUOTA_AL'
   */
  0.0,

  /* Computed Parameter: RC_AL_Y0
   * Referenced by: '<S442>/RC_AL'
   */
  0.0,

  /* Computed Parameter: ROTTA_AL_Y0
   * Referenced by: '<S442>/ROTTA_AL'
   */
  0.0,

  /* Computed Parameter: H_LAT_Y0
   * Referenced by: '<S442>/H_LAT'
   */
  0.0,

  /* Computed Parameter: H_LONG_Y0
   * Referenced by: '<S442>/H_LONG'
   */
  0.0,

  /* Computed Parameter: H_ALT_Y0
   * Referenced by: '<S442>/H_ALT'
   */
  0.0,

  /* Expression: [-1000 -800 2000]
   * Referenced by: '<S455>/distance waypoints virtuale'
   */
  { -1000.0, -800.0, 2000.0 },

  /* Expression: 180/pi
   * Referenced by: '<S471>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S472>/Gain'
   */
  57.295779513082323,

  /* Expression: [45 45 45]
   * Referenced by: '<S455>/alt waypoint virtuale'
   */
  { 45.0, 45.0, 45.0 },

  /* Expression: 180/pi
   * Referenced by: '<S463>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S462>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S460>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S461>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S523>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S539>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S543>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S542>/Constant4'
   */
  1.0,

  /* Expression: 1/298.257223563
   * Referenced by: '<S541>/Constant'
   */
  0.0033528106647474805,

  /* Expression: 1
   * Referenced by: '<S541>/f'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S540>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 6378137
   * Referenced by: '<S539>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S539>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S539>/Constant3'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S464>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S465>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S466>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S442>/Memory7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S442>/Memory5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S442>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S442>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S442>/Constant4'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S442>/Constant2'
   */
  45.0,

  /* Expression: 1
   * Referenced by: '<S442>/Switch2'
   */
  1.0,

  /* Computed Parameter: RC_Y0
   * Referenced by: '<S443>/RC'
   */
  0.0,

  /* Computed Parameter: VELOCITA_Y0
   * Referenced by: '<S443>/VELOCITA'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_j
   * Referenced by: '<S443>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_m
   * Referenced by: '<S443>/Out4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S443>/Memory4'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S544>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S545>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S546>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Out1_Y0_i
   * Referenced by: '<S444>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0_c
   * Referenced by: '<S444>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_d
   * Referenced by: '<S444>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_c
   * Referenced by: '<S444>/Out4'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S549>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S550>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S551>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S556>/Serial Receive'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S556>/Serial Transmit'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S573>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S573>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S573>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S573>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S573>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S573>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S570>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S580>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S580>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S580>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S580>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S580>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S583>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S583>/Memory'
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

  /* Expression: 15
   * Referenced by: '<S577>/Constant'
   */
  15.0,

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

  /* Expression: 62
   * Referenced by: '<S556>/Constant'
   */
  62.0,

  /* Expression: tau
   * Referenced by: '<S565>/Constant'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S556>/Gain1'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S565>/Unit Delay'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S552>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S414>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S40>/Constant2'
   */
  0.0,

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

  /* Expression: pi/180
   * Referenced by: '<S553>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S554>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S557>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S26>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S558>/Gain1'
   */
  0.017453292519943295,

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

  /* Expression: 0.01
   * Referenced by: '<S556>/Gain4'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S16>/vel y'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S16>/Gain1'
   */
  100.0,

  /* Expression: pi/180
   * Referenced by: '<S559>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S555>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 100
   * Referenced by: '<S16>/Gain2'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S22>/airspeed groundspeed alt climb1'
   */
  0.0,

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

  /* Expression: 0
   * Referenced by: '<S304>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S304>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S588>/Gain'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S342>/Integrator'
   */
  0.02,

  /* Expression: pi/180
   * Referenced by: '<S359>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S32>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S31>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S305>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S586>/Gain'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S305>/Constant3'
   */
  2.0,

  /* Computed Parameter: Integrator_gainval_g
   * Referenced by: '<S392>/Integrator'
   */
  0.02,

  /* Expression: 180/pi
   * Referenced by: '<S33>/Gain'
   */
  57.295779513082323,

  /* Expression: [ 1 -1]
   * Referenced by: '<S306>/Discrete Washout Filter'
   */
  { 1.0, -1.0 },

  /* Expression: [1 -0.995]
   * Referenced by: '<S306>/Discrete Washout Filter'
   */
  { 1.0, -0.995 },

  /* Expression: 0
   * Referenced by: '<S306>/Discrete Washout Filter'
   */
  0.0,

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
   * Referenced by: '<S572>/Delay Input2'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S572>/sample time'
   */
  0.02,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa'
   */
  0.01,

  /* Expression: 100
   * Referenced by: '<S556>/Gain7'
   */
  100.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa1'
   */
  0.01,

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

  /* Expression: 180/pi
   * Referenced by: '<S561>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S562>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S563>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S556>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S556>/Gain2'
   */
  100.0,

  /* Expression: 0.3
   * Referenced by: '<S252>/Hit  Crossing'
   */
  0.3,

  /* Expression: 180/pi
   * Referenced by: '<S416>/Gain'
   */
  57.295779513082323,

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

  /* Computed Parameter: Out2_Y0_cb
   * Referenced by: '<S568>/Out2'
   */
  0.0F,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S573>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S579>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S577>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S556>/Gain3'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S573>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S573>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S573>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S573>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_e
   * Referenced by: '<S573>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S573>/Constant9'
   */
  0U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S21>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Out3_Y0_a
   * Referenced by: '<S568>/Out3'
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
   * Referenced by: '<S568>/Out4'
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

  /* Computed Parameter: UnitDelay_InitialCondition_l
   * Referenced by: '<S569>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_ok
   * Referenced by: '<S569>/Constant3'
   */
  1,

  /* Computed Parameter: Gain3_Gain_o
   * Referenced by: '<S8>/Gain3'
   */
  -128,

  /* Computed Parameter: Memory_InitialCondition_j
   * Referenced by: '<S441>/Memory'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_g
   * Referenced by: '<S441>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_n
   * Referenced by: '<S441>/Memory2'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S441>/Memory6'
   */
  0U,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S583>/mario'
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

  /* Computed Parameter: Memory2_InitialCondition_g
   * Referenced by: '<S1>/Memory2'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Typefixed_wingAutopilotgeneric_
   * Referenced by: '<S17>/Type fixed_wing Autopilot generic'
   */
  { 1U, 0U },

  /* Computed Parameter: InizioMSG_Value
   * Referenced by: '<S556>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<S556>/Fine MSG1'
   */
  60U,

  /* Start of '<S569>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S576>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S576>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S576>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S576>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S576>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S576>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S576>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S576>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S576>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S576>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S576>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S576>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S576>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S576>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S576>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S576>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S576>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S576>/Constant4'
     */
    47U
  }
  ,

  /* End of '<S569>/One_time_initialization' */

  /* Start of '<S411>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S424>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S411>/Resettable Subsystem' */

  /* Start of '<S411>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S422>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S422>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S422>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S422>/Switch'
     */
    2.0
  }
  ,

  /* End of '<S411>/Enabled Subsystem' */

  /* Start of '<S410>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S421>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S410>/Resettable Subsystem' */

  /* Start of '<S410>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S419>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S419>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S419>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S419>/Switch'
     */
    2.0
  }
  /* End of '<S410>/Enabled Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
