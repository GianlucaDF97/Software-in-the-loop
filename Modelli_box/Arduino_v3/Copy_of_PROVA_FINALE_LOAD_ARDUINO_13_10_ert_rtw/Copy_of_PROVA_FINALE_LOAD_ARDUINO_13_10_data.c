/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_data.c
 *
 * Code generated for Simulink model 'Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10'.
 *
 * Model version                  : 5.18
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct 29 15:55:33 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10.h"
#include "Copy_of_PROVA_FINALE_LOAD_ARDUINO_13_10_private.h"

/* Block parameters (default storage) */
P_Copy_of_PROVA_FINALE_LOAD_A_T Copy_of_PROVA_FINALE_LOAD_ARD_P = {
  /* Variable: Kp_comp_h
   * Referenced by: '<S308>/Constant3'
   */
  0.035,

  /* Variable: attuatore_Amax
   * Referenced by:
   *   '<S43>/saturatore A'
   *   '<S43>/saturatore A1'
   *   '<S573>/Constant8'
   *   '<S579>/Constant'
   *   '<S403>/Saturation'
   */
  0.47123889803846897,

  /* Variable: attuatore_Amin
   * Referenced by:
   *   '<S43>/saturatore A'
   *   '<S43>/saturatore A1'
   *   '<S573>/Constant9'
   *   '<S579>/Constant1'
   *   '<S403>/Saturation'
   */
  -0.4014257279586958,

  /* Variable: attuatore_Emax
   * Referenced by:
   *   '<S575>/Constant8'
   *   '<S582>/Constant'
   *   '<S308>/saturatore E2'
   *   '<S353>/Saturation'
   */
  0.31415926535897931,

  /* Variable: attuatore_Emin
   * Referenced by:
   *   '<S575>/Constant9'
   *   '<S582>/Constant1'
   *   '<S308>/saturatore E2'
   *   '<S353>/Saturation'
   */
  -0.55850536063818546,

  /* Variable: attuatore_Rmax
   * Referenced by:
   *   '<S43>/saturatore R'
   *   '<S577>/Constant8'
   *   '<S580>/Constant'
   */
  0.52359877559829882,

  /* Variable: attuatore_Rmin
   * Referenced by:
   *   '<S43>/saturatore R'
   *   '<S577>/Constant9'
   *   '<S580>/Constant1'
   */
  -0.52359877559829882,

  /* Variable: attuatore_Tmax
   * Referenced by: '<S578>/manetta_massima'
   */
  1.0,

  /* Variable: attuatore_Tmin
   * Referenced by: '<S578>/manetta_minima'
   */
  0.0,

  /* Variable: interventoA_05
   * Referenced by: '<S416>/Constant4'
   */
  6.0,

  /* Variable: interventoA_1
   * Referenced by: '<S416>/Constant3'
   */
  2.0,

  /* Variable: interventoE_05
   * Referenced by: '<S416>/Constant1'
   */
  7.5,

  /* Variable: interventoE_1
   * Referenced by: '<S416>/Constant'
   */
  3.2,

  /* Variable: interventoT
   * Referenced by: '<S416>/Constant2'
   */
  0.1,

  /* Variable: inv_A
   * Referenced by: '<S43>/Gain1'
   */
  -1.0,

  /* Variable: inv_E
   * Referenced by: '<S43>/Gain'
   */
  1.0,

  /* Variable: inv_R
   * Referenced by: '<S43>/Gain2'
   */
  1.0,

  /* Variable: inv_comp_h
   * Referenced by: '<S308>/Gain'
   */
  -1.0,

  /* Variable: phi_max
   * Referenced by:
   *   '<S574>/Constant8'
   *   '<S574>/Saturation'
   */
  0.52359877559829882,

  /* Variable: phi_min
   * Referenced by:
   *   '<S574>/Constant9'
   *   '<S574>/Saturation'
   */
  -0.52359877559829882,

  /* Variable: safe_V
   * Referenced by: '<S421>/Constant'
   */
  40.0,

  /* Variable: safe_phi
   * Referenced by: '<S421>/Constant1'
   */
  55.0,

  /* Variable: t_AP
   * Referenced by:
   *   '<S561>/I2C Read1'
   *   '<S561>/I2C Read12'
   *   '<S564>/I2C Read'
   *   '<S564>/I2C Read1'
   *   '<S564>/I2C Read10'
   *   '<S564>/I2C Read11'
   *   '<S564>/I2C Read2'
   *   '<S564>/I2C Read3'
   *   '<S564>/I2C Read4'
   *   '<S564>/I2C Read5'
   *   '<S564>/I2C Read6'
   *   '<S564>/I2C Read7'
   *   '<S564>/I2C Read8'
   *   '<S564>/I2C Read9'
   *   '<S425>/Constant4'
   *   '<S428>/Constant4'
   *   '<S442>/Constant4'
   */
  0.02,

  /* Variable: theta_max
   * Referenced by:
   *   '<S576>/Constant8'
   *   '<S576>/Saturation'
   */
  0.26179938779914941,

  /* Variable: theta_min
   * Referenced by:
   *   '<S576>/Constant9'
   *   '<S576>/Saturation'
   */
  -0.26179938779914941,

  /* Variable: time_alarm_SAFE
   * Referenced by: '<S440>/Switch'
   */
  1.0,

  /* Variable: vel_wp1_al
   * Referenced by: '<S459>/Constant'
   */
  25.0,

  /* Variable: vel_wp2_al
   * Referenced by: '<S459>/Constant1'
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
   * Referenced by: '<S346>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_d
   * Referenced by: '<S396>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S389>/Kb'
   */
  0.5,

  /* Mask Parameter: PIDController_Kb_k
   * Referenced by: '<S339>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt
   * Referenced by: '<S407>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt_m
   * Referenced by: '<S357>/Kt'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S541>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S539>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S542>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S535>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_dp
   * Referenced by: '<S533>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S536>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S25>/Serial Transmit'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S40>/Constant2'
   */
  360.0,

  /* Expression: [1]
   * Referenced by: '<S307>/Out1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S313>/Constant5'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S313>/Switch1'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<S43>/r_rif'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S432>/Alarm_Int'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S435>/Alarm_Int'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S440>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S440>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S440>/Alarm Safe'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S442>/Memory'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S44>/Constant1'
   */
  20.0,

  /* Expression: 180/pi
   * Referenced by: '<S419>/Gain'
   */
  57.295779513082323,

  /* Expression: 50
   * Referenced by: '<S44>/Constant'
   */
  50.0,

  /* Expression: initCond
   * Referenced by: '<S452>/ '
   */
  0.0,

  /* Expression: initCond
   * Referenced by: '<S453>/ '
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S451>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S444>/Memory'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S450>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S444>/Memory1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_d
   * Referenced by: '<S445>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S445>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S445>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S445>/Out4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S445>/Memory3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S454>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: h_ref_Y0
   * Referenced by: '<S457>/h_ref'
   */
  0.0,

  /* Computed Parameter: flare_data_Y0
   * Referenced by: '<S457>/flare_data'
   */
  0.0,

  /* Computed Parameter: landing_abort_Y0
   * Referenced by: '<S457>/landing_abort'
   */
  0.0,

  /* Computed Parameter: rc_ref_app_Y0
   * Referenced by: '<S457>/rc_ref_app'
   */
  0.0,

  /* Expression: -100
   * Referenced by: '<S457>/x_g0'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S457>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S457>/Constant4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S457>/Discrete-Time Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S457>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S457>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S457>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S457>/Switch'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S457>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S457>/Constant2'
   */
  1.0,

  /* Computed Parameter: h_ref_Y0_n
   * Referenced by: '<S461>/h_ref'
   */
  0.0,

  /* Computed Parameter: RC_ref_Y0
   * Referenced by: '<S461>/RC_ref'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S461>/Gain'
   */
  -1.0,

  /* Computed Parameter: psi_ref_landing_Y0
   * Referenced by: '<S462>/psi_ref_landing'
   */
  0.0,

  /* Expression: -90
   * Referenced by: '<S531>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S531>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S531>/Bias1'
   */
  90.0,

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

  /* Expression: 180
   * Referenced by: '<S528>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S528>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S532>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S532>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S532>/Bias1'
   */
  -180.0,

  /* Expression: -90
   * Referenced by: '<S537>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S537>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S537>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S540>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S540>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S540>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S529>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S529>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S538>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S538>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S538>/Bias1'
   */
  -180.0,

  /* Expression: initCond
   * Referenced by: '<S471>/ '
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S446>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S446>/Constant8'
   */
  0.0,

  /* Computed Parameter: TAS_AL_Y0
   * Referenced by: '<S446>/TAS_AL'
   */
  0.0,

  /* Computed Parameter: QUOTA_AL_Y0
   * Referenced by: '<S446>/QUOTA_AL'
   */
  0.0,

  /* Computed Parameter: RC_AL_Y0
   * Referenced by: '<S446>/RC_AL'
   */
  0.0,

  /* Computed Parameter: ROTTA_AL_Y0
   * Referenced by: '<S446>/ROTTA_AL'
   */
  0.0,

  /* Computed Parameter: H_LAT_Y0
   * Referenced by: '<S446>/H_LAT'
   */
  0.0,

  /* Computed Parameter: H_LONG_Y0
   * Referenced by: '<S446>/H_LONG'
   */
  0.0,

  /* Computed Parameter: H_ALT_Y0
   * Referenced by: '<S446>/H_ALT'
   */
  0.0,

  /* Expression: [-1000 -800 2000]
   * Referenced by: '<S459>/distance waypoints virtuale'
   */
  { -1000.0, -800.0, 2000.0 },

  /* Expression: 180/pi
   * Referenced by: '<S475>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S476>/Gain'
   */
  57.295779513082323,

  /* Expression: [45 45 45]
   * Referenced by: '<S459>/alt waypoint virtuale'
   */
  { 45.0, 45.0, 45.0 },

  /* Expression: 180/pi
   * Referenced by: '<S467>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S466>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S464>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S465>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S527>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S543>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S547>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S546>/Constant4'
   */
  1.0,

  /* Expression: 1/298.257223563
   * Referenced by: '<S545>/Constant'
   */
  0.0033528106647474805,

  /* Expression: 1
   * Referenced by: '<S545>/f'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S544>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 6378137
   * Referenced by: '<S543>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S543>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S543>/Constant3'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S468>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S469>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S470>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S446>/Memory7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S446>/Memory5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S446>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S446>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S446>/Constant4'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S446>/Constant2'
   */
  45.0,

  /* Expression: 1
   * Referenced by: '<S446>/Switch2'
   */
  1.0,

  /* Computed Parameter: RC_Y0
   * Referenced by: '<S447>/RC'
   */
  0.0,

  /* Computed Parameter: VELOCITA_Y0
   * Referenced by: '<S447>/VELOCITA'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_j
   * Referenced by: '<S447>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_m
   * Referenced by: '<S447>/Out4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S447>/Memory4'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S548>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S549>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S550>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Out1_Y0_i
   * Referenced by: '<S448>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0_c
   * Referenced by: '<S448>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_d
   * Referenced by: '<S448>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_c
   * Referenced by: '<S448>/Out4'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S553>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S554>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S555>/Gain'
   */
  57.295779513082323,

  /* Expression: 16
   * Referenced by: '<S561>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S561>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S561>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S561>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S561>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S561>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S558>/Serial Receive1'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S568>/h_to_subtract'
   */
  0.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S571>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S571>/Memory'
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
   * Referenced by: '<S565>/Constant'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S33>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S33>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S33>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S33>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S33>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S33>/Memory'
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

  /* Expression: 180/pi
   * Referenced by: '<S418>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S44>/Constant2'
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

  /* Expression: pi/180
   * Referenced by: '<S29>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S28>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S27>/Gain1'
   */
  0.017453292519943295,

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
   * Referenced by: '<S30>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S31>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S32>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 101325
   * Referenced by: '<S560>/Delay Input2'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S560>/sample time'
   */
  0.02,

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

  /* Expression: pi/180
   * Referenced by: '<S556>/Gain1'
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
   * Referenced by: '<S39>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S40>/Switch2'
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
   * Referenced by: '<S35>/Gain2'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S308>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S308>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S576>/Gain'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S346>/Integrator'
   */
  0.02,

  /* Expression: pi/180
   * Referenced by: '<S363>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S36>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S35>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S309>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S574>/Gain'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S309>/Constant3'
   */
  2.0,

  /* Computed Parameter: Integrator_gainval_g
   * Referenced by: '<S396>/Integrator'
   */
  0.02,

  /* Expression: 180/pi
   * Referenced by: '<S37>/Gain'
   */
  57.295779513082323,

  /* Expression: [ 1 -1]
   * Referenced by: '<S310>/Discrete Washout Filter'
   */
  { 1.0, -1.0 },

  /* Expression: [1 -0.995]
   * Referenced by: '<S310>/Discrete Washout Filter'
   */
  { 1.0, -0.995 },

  /* Expression: 0
   * Referenced by: '<S310>/Discrete Washout Filter'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S38>/Gain'
   */
  57.295779513082323,

  /* Expression: zeros(3,1)
   * Referenced by: '<S20>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 34
   * Referenced by: '<S6>/Constant1'
   */
  34.0,

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

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa'
   */
  0.01,

  /* Expression: 32
   * Referenced by: '<S6>/Constant2'
   */
  32.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa1'
   */
  0.01,

  /* Expression: 2
   * Referenced by: '<S45>/RC_default'
   */
  2.0,

  /* Expression: 70
   * Referenced by: '<S45>/Constant'
   */
  70.0,

  /* Expression: 20
   * Referenced by: '<S45>/Constant1'
   */
  20.0,

  /* Expression: 0.3
   * Referenced by: '<S256>/Hit  Crossing'
   */
  0.3,

  /* Expression: 180/pi
   * Referenced by: '<S420>/Gain'
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
   * Referenced by: '<S33>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S33>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S33>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S33>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_gw
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S561>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S567>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S565>/Switch'
   */
  0.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S561>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S561>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S561>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S561>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_e
   * Referenced by: '<S561>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S561>/Constant9'
   */
  0U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S21>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Switch_Threshold_m
   * Referenced by: '<S9>/Switch'
   */
  1500,

  /* Computed Parameter: Gain1_Gain_eu
   * Referenced by: '<S21>/Gain1'
   */
  26214,

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
   * Referenced by: '<S557>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_ok
   * Referenced by: '<S557>/Constant3'
   */
  1,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S8>/Gain3'
   */
  -128,

  /* Computed Parameter: Memory_InitialCondition_j
   * Referenced by: '<S445>/Memory'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_g
   * Referenced by: '<S445>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_n
   * Referenced by: '<S445>/Memory2'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S445>/Memory6'
   */
  0U,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S571>/mario'
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

  /* Start of '<S557>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S564>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S564>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S564>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S564>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S564>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S564>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S564>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S564>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S564>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S564>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S564>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S564>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S564>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S564>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S564>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S564>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S564>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S564>/Constant4'
     */
    47U
  }
  ,

  /* End of '<S557>/One_time_initialization' */

  /* Start of '<S415>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S428>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S415>/Resettable Subsystem' */

  /* Start of '<S415>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S426>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S426>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S426>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S426>/Switch'
     */
    2.0
  }
  ,

  /* End of '<S415>/Enabled Subsystem' */

  /* Start of '<S414>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S425>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S414>/Resettable Subsystem' */

  /* Start of '<S414>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S423>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S423>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S423>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S423>/Switch'
     */
    2.0
  }
  /* End of '<S414>/Enabled Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
