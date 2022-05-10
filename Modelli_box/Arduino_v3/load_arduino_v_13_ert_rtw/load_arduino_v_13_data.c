/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: load_arduino_v_13_data.c
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

#include "load_arduino_v_13.h"
#include "load_arduino_v_13_private.h"

/* Block parameters (default storage) */
P_load_arduino_v_13_T load_arduino_v_13_P = {
  /* Variable: Kp_Rotta_psi
   * Referenced by:
   *   '<S540>/Constant3'
   *   '<S540>/Constant4'
   */
  -0.01,

  /* Variable: attuatore_Amax
   * Referenced by:
   *   '<S39>/saturatore A'
   *   '<S39>/saturatore A1'
   *   '<S981>/Constant8'
   *   '<S987>/Constant'
   *   '<S728>/Saturation'
   */
  0.47123889803846897,

  /* Variable: attuatore_Amin
   * Referenced by:
   *   '<S39>/saturatore A'
   *   '<S39>/saturatore A1'
   *   '<S981>/Constant9'
   *   '<S987>/Constant1'
   *   '<S728>/Saturation'
   */
  -0.4014257279586958,

  /* Variable: attuatore_Emax
   * Referenced by:
   *   '<S983>/Constant8'
   *   '<S990>/Constant'
   *   '<S541>/saturatore E2'
   *   '<S630>/Saturation'
   */
  0.31415926535897931,

  /* Variable: attuatore_Emin
   * Referenced by:
   *   '<S983>/Constant9'
   *   '<S990>/Constant1'
   *   '<S541>/saturatore E2'
   *   '<S630>/Saturation'
   */
  -0.55850536063818546,

  /* Variable: attuatore_Rmax
   * Referenced by:
   *   '<S39>/saturatore R'
   *   '<S985>/Constant8'
   *   '<S988>/Constant'
   */
  0.52359877559829882,

  /* Variable: attuatore_Rmin
   * Referenced by:
   *   '<S39>/saturatore R'
   *   '<S985>/Constant9'
   *   '<S988>/Constant1'
   */
  -0.52359877559829882,

  /* Variable: attuatore_Tmax
   * Referenced by: '<S986>/manetta_massima'
   */
  1.0,

  /* Variable: attuatore_Tmin
   * Referenced by: '<S986>/manetta_minima'
   */
  0.0,

  /* Variable: interventoA_05
   * Referenced by: '<S752>/Constant4'
   */
  6.0,

  /* Variable: interventoA_1
   * Referenced by: '<S752>/Constant3'
   */
  2.0,

  /* Variable: interventoE_05
   * Referenced by: '<S752>/Constant1'
   */
  7.5,

  /* Variable: interventoE_1
   * Referenced by: '<S752>/Constant'
   */
  3.2,

  /* Variable: interventoT
   * Referenced by: '<S752>/Constant2'
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

  /* Variable: phi_max
   * Referenced by: '<S982>/Constant8'
   */
  0.52359877559829882,

  /* Variable: phi_min
   * Referenced by: '<S982>/Constant9'
   */
  -0.52359877559829882,

  /* Variable: safe_V
   * Referenced by: '<S757>/Constant'
   */
  40.0,

  /* Variable: safe_phi
   * Referenced by: '<S757>/Constant1'
   */
  55.0,

  /* Variable: t_AP
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
  0.02,

  /* Variable: theta_max
   * Referenced by: '<S984>/Constant8'
   */
  0.26179938779914941,

  /* Variable: theta_min
   * Referenced by: '<S984>/Constant9'
   */
  -0.26179938779914941,

  /* Variable: time_alarm_SAFE
   * Referenced by: '<S776>/Switch'
   */
  1.0,

  /* Variable: vel_wp1_al
   * Referenced by: '<S795>/Constant'
   */
  25.0,

  /* Variable: vel_wp2_al
   * Referenced by: '<S795>/Constant1'
   */
  20.0,

  /* Variable: Ki_becch
   * Referenced by: '<S8>/Ki controllore  beccheggio1'
   */
  -0.64065F,

  /* Variable: Ki_roll
   * Referenced by: '<S8>/Ki controllore  rollio3'
   */
  0.25F,

  /* Variable: Kp_becch
   * Referenced by: '<S8>/Kp controllore beccheggio1'
   */
  -1.918F,

  /* Variable: Kp_imb
   * Referenced by: '<S8>/Kp controllore imbardata'
   */
  -0.4F,

  /* Variable: Kp_p
   * Referenced by: '<S8>/Kp controllore  velocità rollio3'
   */
  0.125F,

  /* Variable: Kp_q
   * Referenced by: '<S8>/Kp controllore velocità beccheggio1'
   */
  -0.125F,

  /* Variable: Kp_roll
   * Referenced by: '<S8>/Kp controllore  rollio3'
   */
  1.1F,

  /* Variable: K_imb_inv
   * Referenced by: '<S8>/K controllo imbardata inversa'
   */
  -1,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S870>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_g
   * Referenced by: '<S609>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_d
   * Referenced by: '<S707>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S675>/Kb'
   */
  0.5,

  /* Mask Parameter: PIDController_Kb_k
   * Referenced by: '<S577>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt
   * Referenced by: '<S742>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt_m
   * Referenced by: '<S644>/Kt'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S926>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S924>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S927>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S920>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_dp
   * Referenced by: '<S918>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S921>/Constant'
   */
  180.0,

  /* Expression: 360
   * Referenced by: '<S36>/Constant2'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<S544>/Constant4'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S549>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S548>/Constant2'
   */
  360.0,

  /* Expression: 180/pi
   * Referenced by: '<S547>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S549>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S548>/Switch2'
   */
  0.0,

  /* Expression: 0.15
   * Referenced by: '<S540>/Switch3'
   */
  0.15,

  /* Expression: 0.035*10
   * Referenced by: '<S541>/Constant3'
   */
  0.35000000000000003,

  /* Expression: -1
   * Referenced by: '<S541>/Gain'
   */
  -1.0,

  /* Expression: 180/pi
   * Referenced by: '<S546>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S545>/Gain'
   */
  57.295779513082323,

  /* Expression: 360
   * Referenced by: '<S550>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S551>/Constant2'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<S553>/Constant5'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S553>/Switch1'
   */
  16.0,

  /* Expression: 0.6
   * Referenced by: '<S542>/Constant2'
   */
  0.6,

  /* Expression: 180/pi
   * Referenced by: '<S755>/Gain'
   */
  57.295779513082323,

  /* Expression: 20
   * Referenced by: '<S40>/Constant1'
   */
  20.0,

  /* Expression: 50
   * Referenced by: '<S40>/Constant'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S768>/Alarm_Int'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S771>/Alarm_Int'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S776>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S776>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S776>/Alarm Safe'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S778>/Memory'
   */
  0.0,

  /* Expression: initCond
   * Referenced by: '<S788>/ '
   */
  0.0,

  /* Expression: initCond
   * Referenced by: '<S789>/ '
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S787>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S780>/Memory'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S786>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S780>/Memory1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S781>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S781>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S781>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S781>/Out4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S781>/Memory3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S790>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S782>/Constant8'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S782>/Constant3'
   */
  1.0,

  /* Computed Parameter: h_ref_Y0
   * Referenced by: '<S793>/h_ref'
   */
  0.0,

  /* Computed Parameter: flare_data_Y0
   * Referenced by: '<S793>/flare_data'
   */
  0.0,

  /* Computed Parameter: landing_abort_Y0
   * Referenced by: '<S793>/landing_abort'
   */
  0.0,

  /* Computed Parameter: rc_ref_app_Y0
   * Referenced by: '<S793>/rc_ref_app'
   */
  0.0,

  /* Expression: -100
   * Referenced by: '<S793>/x_g0'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S793>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S793>/Constant4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S793>/Discrete-Time Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S793>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S793>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S793>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S793>/Switch'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S793>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S793>/Constant2'
   */
  1.0,

  /* Computed Parameter: h_ref_Y0_n
   * Referenced by: '<S797>/h_ref'
   */
  0.0,

  /* Computed Parameter: RC_ref_Y0
   * Referenced by: '<S797>/RC_ref'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S797>/Gain'
   */
  -1.0,

  /* Computed Parameter: psi_ref_landing_Y0
   * Referenced by: '<S798>/psi_ref_landing'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S798>/Gain1'
   */
  1.0,

  /* Expression: 0.00052
   * Referenced by: '<S798>/psi ref gain1'
   */
  0.00052,

  /* Expression: 0.0052
   * Referenced by: '<S798>/psi ref gain'
   */
  0.0052,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S870>/Integrator'
   */
  0.02,

  /* Expression: 180/pi
   * Referenced by: '<S815>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S913>/Constant1'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S913>/Constant'
   */
  180.0,

  /* Expression: -90
   * Referenced by: '<S916>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S916>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S916>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S919>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S919>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S919>/Bias1'
   */
  -180.0,

  /* Expression: 360
   * Referenced by: '<S917>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S917>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S917>/Bias1'
   */
  -180.0,

  /* Expression: 0
   * Referenced by: '<S914>/Constant1'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S914>/Constant'
   */
  180.0,

  /* Expression: -90
   * Referenced by: '<S922>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S922>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S922>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S925>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S925>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S925>/Bias1'
   */
  -180.0,

  /* Expression: 360
   * Referenced by: '<S923>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S923>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S923>/Bias1'
   */
  -180.0,

  /* Expression: initCond
   * Referenced by: '<S807>/ '
   */
  { 0.0, 0.0 },

  /* Computed Parameter: TAS_AL_Y0
   * Referenced by: '<S782>/TAS_AL'
   */
  0.0,

  /* Computed Parameter: QUOTA_AL_Y0
   * Referenced by: '<S782>/QUOTA_AL'
   */
  0.0,

  /* Computed Parameter: RC_AL_Y0
   * Referenced by: '<S782>/RC_AL'
   */
  0.0,

  /* Computed Parameter: ROTTA_AL_Y0
   * Referenced by: '<S782>/ROTTA_AL'
   */
  0.0,

  /* Computed Parameter: H_LAT_Y0
   * Referenced by: '<S782>/H_LAT'
   */
  0.0,

  /* Computed Parameter: H_LONG_Y0
   * Referenced by: '<S782>/H_LONG'
   */
  0.0,

  /* Computed Parameter: H_ALT_Y0
   * Referenced by: '<S782>/H_ALT'
   */
  0.0,

  /* Expression: [-1000 -800 2000]
   * Referenced by: '<S795>/distance waypoints virtuale'
   */
  { -1000.0, -800.0, 2000.0 },

  /* Expression: 180/pi
   * Referenced by: '<S811>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S812>/Gain'
   */
  57.295779513082323,

  /* Expression: [45 45 45]
   * Referenced by: '<S795>/alt waypoint virtuale'
   */
  { 45.0, 45.0, 45.0 },

  /* Expression: 180/pi
   * Referenced by: '<S803>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S802>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S800>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S801>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S912>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S928>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S931>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S932>/Constant'
   */
  1.0,

  /* Expression: 1/298.257223563
   * Referenced by: '<S930>/Constant'
   */
  0.0033528106647474805,

  /* Expression: 1
   * Referenced by: '<S930>/f'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S929>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 6378137
   * Referenced by: '<S928>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S928>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S928>/Constant3'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S804>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S805>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S806>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S782>/Memory7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S782>/Memory5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S782>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S782>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S782>/Constant4'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S782>/Constant2'
   */
  45.0,

  /* Expression: 1
   * Referenced by: '<S782>/Switch2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S782>/Switch1'
   */
  1.0,

  /* Computed Parameter: RC_Y0
   * Referenced by: '<S783>/RC'
   */
  0.0,

  /* Computed Parameter: VELOCITA_Y0
   * Referenced by: '<S783>/VELOCITA'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_j
   * Referenced by: '<S783>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_m
   * Referenced by: '<S783>/Out4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S783>/Memory4'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S933>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S934>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S935>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Out1_Y0_i
   * Referenced by: '<S784>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0_c
   * Referenced by: '<S784>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_d
   * Referenced by: '<S784>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_c
   * Referenced by: '<S784>/Out4'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S938>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S939>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S940>/Gain'
   */
  57.295779513082323,

  /* Expression: 16
   * Referenced by: '<S968>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S968>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S968>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S968>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S968>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S968>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S975>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S975>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S975>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S975>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S975>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S978>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S978>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: 15
   * Referenced by: '<S972>/Constant'
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
   * Referenced by: '<S947>/Constant'
   */
  62.0,

  /* Expression: tau
   * Referenced by: '<S956>/Constant'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S947>/Gain1'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S956>/Unit Delay'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S943>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S754>/Gain'
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
   * Referenced by: '<S944>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S945>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S948>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S26>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S949>/Gain1'
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
   * Referenced by: '<S947>/Gain4'
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
   * Referenced by: '<S950>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S946>/Gain1'
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

  /* Expression: 0
   * Referenced by: '<S39>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S544>/Constant8'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
   * Referenced by: '<S544>/Discrete-Time Integrator'
   */
  0.0003,

  /* Expression: 0
   * Referenced by: '<S544>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0.6
   * Referenced by: '<S544>/Discrete-Time Integrator'
   */
  0.6,

  /* Expression: 0
   * Referenced by: '<S544>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S31>/Gain2'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S541>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S541>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S984>/Gain'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_b
   * Referenced by: '<S609>/Integrator'
   */
  0.02,

  /* Expression: pi/180
   * Referenced by: '<S651>/Gain1'
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
   * Referenced by: '<S542>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S982>/Gain'
   */
  -1.0,

  /* Expression: 1.8
   * Referenced by: '<S542>/Switch'
   */
  1.8,

  /* Expression: 2
   * Referenced by: '<S542>/Constant3'
   */
  2.0,

  /* Computed Parameter: Integrator_gainval_g
   * Referenced by: '<S707>/Integrator'
   */
  0.02,

  /* Expression: 180/pi
   * Referenced by: '<S33>/Gain'
   */
  57.295779513082323,

  /* Expression: [ 1 -1]
   * Referenced by: '<S543>/Discrete Washout Filter'
   */
  { 1.0, -1.0 },

  /* Expression: [1 -0.995]
   * Referenced by: '<S543>/Discrete Washout Filter'
   */
  { 1.0, -0.995 },

  /* Expression: 0
   * Referenced by: '<S543>/Discrete Washout Filter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/r_rif'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S540>/Switch2'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S550>/Switch2'
   */
  0.0,

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

  /* Expression: 0
   * Referenced by: '<S551>/Switch2'
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
   * Referenced by: '<S967>/Delay Input2'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S967>/sample time'
   */
  0.02,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa'
   */
  0.01,

  /* Expression: 100
   * Referenced by: '<S947>/Gain7'
   */
  100.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa1'
   */
  0.01,

  /* Expression: 180/pi
   * Referenced by: '<S952>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S953>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S954>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S947>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S947>/Gain2'
   */
  100.0,

  /* Expression: 180/pi
   * Referenced by: '<S756>/Gain'
   */
  57.295779513082323,

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

  /* Expression: 10
   * Referenced by: '<S544>/Constant7'
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

  /* Computed Parameter: Constant_Value_gw
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: Gain2_Gain_k4
   * Referenced by: '<S8>/Gain2'
   */
  -1.0F,

  /* Computed Parameter: Out2_Y0_cb
   * Referenced by: '<S961>/Out2'
   */
  0.0F,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S968>/T'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S972>/Switch'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S974>/T_0'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_j5
   * Referenced by: '<S8>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S947>/Gain3'
   */
  100.0F,

  /* Computed Parameter: Gain1_Gain_k2
   * Referenced by: '<S8>/Gain1'
   */
  -1.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S968>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value_h
   * Referenced by: '<S968>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S968>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S968>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_et
   * Referenced by: '<S968>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S968>/Constant9'
   */
  0U,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S965>/Delay'
   */
  1U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S21>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Out3_Y0_a
   * Referenced by: '<S961>/Out3'
   */
  0,

  /* Computed Parameter: Switch_Threshold_mm
   * Referenced by: '<S9>/Switch'
   */
  1500,

  /* Computed Parameter: Gain1_Gain_eu
   * Referenced by: '<S21>/Gain1'
   */
  26214,

  /* Computed Parameter: Out4_Y0_i
   * Referenced by: '<S961>/Out4'
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
   * Referenced by: '<S963>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_ok
   * Referenced by: '<S963>/Constant3'
   */
  1,

  /* Computed Parameter: Gain3_Gain_o
   * Referenced by: '<S8>/Gain3'
   */
  -128,

  /* Computed Parameter: Memory_InitialCondition_j
   * Referenced by: '<S781>/Memory'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_g
   * Referenced by: '<S781>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_n
   * Referenced by: '<S781>/Memory2'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S781>/Memory6'
   */
  0U,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S978>/mario'
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

  /* Computed Parameter: Constant1_Value_g
   * Referenced by: '<S965>/Constant1'
   */
  0U,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S965>/Delay'
   */
  0U,

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
   * Referenced by: '<S947>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<S947>/Fine MSG1'
   */
  60U,

  /* Start of '<S963>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S971>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S971>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S971>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S971>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S971>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S971>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S971>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S971>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S971>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S971>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S971>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S971>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S971>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S971>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S971>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S971>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S971>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S971>/Constant4'
     */
    47U
  }
  ,

  /* End of '<S963>/One_time_initialization' */

  /* Start of '<S751>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S764>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S751>/Resettable Subsystem' */

  /* Start of '<S751>/Enabled Subsystem' */
  {
    /* Expression: 1
     * Referenced by: '<S762>/Constant2'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S762>/Constant1'
     */
    0.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S762>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S762>/Switch'
     */
    2.0
  }
  ,

  /* End of '<S751>/Enabled Subsystem' */

  /* Start of '<S750>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S761>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S750>/Resettable Subsystem' */

  /* Start of '<S750>/Enabled Subsystem' */
  {
    /* Expression: 1
     * Referenced by: '<S759>/Constant2'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S759>/Constant1'
     */
    0.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S759>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S759>/Switch'
     */
    2.0
  }
  /* End of '<S750>/Enabled Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
