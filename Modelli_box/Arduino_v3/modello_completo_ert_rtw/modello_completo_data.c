/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: modello_completo_data.c
 *
 * Code generated for Simulink model 'modello_completo'.
 *
 * Model version                  : 5.45
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May  4 15:32:50 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modello_completo.h"
#include "modello_completo_private.h"

/* Block parameters (default storage) */
P_modello_completo_T modello_completo_P = {
  /* Variable: Kp_comp_h
   * Referenced by: '<S302>/Constant3'
   */
  0.035,

  /* Variable: attuatore_Amax
   * Referenced by:
   *   '<S37>/saturatore A'
   *   '<S37>/saturatore A1'
   *   '<S583>/Constant8'
   *   '<S589>/Constant'
   *   '<S397>/Saturation'
   */
  0.47123889803846897,

  /* Variable: attuatore_Amin
   * Referenced by:
   *   '<S37>/saturatore A'
   *   '<S37>/saturatore A1'
   *   '<S583>/Constant9'
   *   '<S589>/Constant1'
   *   '<S397>/Saturation'
   */
  -0.4014257279586958,

  /* Variable: attuatore_Emax
   * Referenced by:
   *   '<S585>/Constant8'
   *   '<S592>/Constant'
   *   '<S302>/saturatore E2'
   *   '<S347>/Saturation'
   */
  0.31415926535897931,

  /* Variable: attuatore_Emin
   * Referenced by:
   *   '<S585>/Constant9'
   *   '<S592>/Constant1'
   *   '<S302>/saturatore E2'
   *   '<S347>/Saturation'
   */
  -0.55850536063818546,

  /* Variable: attuatore_Rmax
   * Referenced by:
   *   '<S37>/saturatore R'
   *   '<S587>/Constant8'
   *   '<S590>/Constant'
   */
  0.52359877559829882,

  /* Variable: attuatore_Rmin
   * Referenced by:
   *   '<S37>/saturatore R'
   *   '<S587>/Constant9'
   *   '<S590>/Constant1'
   */
  -0.52359877559829882,

  /* Variable: attuatore_Tmax
   * Referenced by: '<S588>/manetta_massima'
   */
  1.0,

  /* Variable: attuatore_Tmin
   * Referenced by: '<S588>/manetta_minima'
   */
  0.0,

  /* Variable: interventoA_05
   * Referenced by: '<S410>/Constant4'
   */
  6.0,

  /* Variable: interventoA_1
   * Referenced by: '<S410>/Constant3'
   */
  2.0,

  /* Variable: interventoE_05
   * Referenced by: '<S410>/Constant1'
   */
  7.5,

  /* Variable: interventoE_1
   * Referenced by: '<S410>/Constant'
   */
  3.2,

  /* Variable: interventoT
   * Referenced by: '<S410>/Constant2'
   */
  0.1,

  /* Variable: inv_A
   * Referenced by: '<S37>/Gain1'
   */
  -1.0,

  /* Variable: inv_E
   * Referenced by: '<S37>/Gain'
   */
  1.0,

  /* Variable: inv_R
   * Referenced by: '<S37>/Gain2'
   */
  1.0,

  /* Variable: inv_comp_h
   * Referenced by: '<S302>/Gain'
   */
  -1.0,

  /* Variable: phi_max
   * Referenced by:
   *   '<S584>/Constant8'
   *   '<S584>/Saturation'
   */
  0.52359877559829882,

  /* Variable: phi_min
   * Referenced by:
   *   '<S584>/Constant9'
   *   '<S584>/Saturation'
   */
  -0.52359877559829882,

  /* Variable: safe_V
   * Referenced by: '<S415>/Constant'
   */
  40.0,

  /* Variable: safe_phi
   * Referenced by: '<S415>/Constant1'
   */
  55.0,

  /* Variable: t_AP
   * Referenced by:
   *   '<S571>/I2C Read1'
   *   '<S571>/I2C Read12'
   *   '<S574>/I2C Read'
   *   '<S574>/I2C Read1'
   *   '<S574>/I2C Read10'
   *   '<S574>/I2C Read11'
   *   '<S574>/I2C Read2'
   *   '<S574>/I2C Read3'
   *   '<S574>/I2C Read4'
   *   '<S574>/I2C Read5'
   *   '<S574>/I2C Read6'
   *   '<S574>/I2C Read7'
   *   '<S574>/I2C Read8'
   *   '<S574>/I2C Read9'
   *   '<S419>/Constant4'
   *   '<S422>/Constant4'
   *   '<S436>/Constant4'
   */
  0.02,

  /* Variable: theta_max
   * Referenced by:
   *   '<S586>/Constant8'
   *   '<S586>/Saturation'
   */
  0.26179938779914941,

  /* Variable: theta_min
   * Referenced by:
   *   '<S586>/Constant9'
   *   '<S586>/Saturation'
   */
  -0.26179938779914941,

  /* Variable: time_alarm_SAFE
   * Referenced by: '<S434>/Switch'
   */
  1.0,

  /* Variable: vel_wp1_al
   * Referenced by: '<S453>/Constant'
   */
  25.0,

  /* Variable: vel_wp2_al
   * Referenced by: '<S453>/Constant1'
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
   * Referenced by: '<S8>/Kp controllore  velocit� rollio3'
   */
  0.006913F,

  /* Variable: Kp_q
   * Referenced by: '<S8>/Kp controllore velocit� beccheggio1'
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
   * Referenced by: '<S340>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_d
   * Referenced by: '<S390>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S383>/Kb'
   */
  0.5,

  /* Mask Parameter: PIDController_Kb_k
   * Referenced by: '<S333>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt
   * Referenced by: '<S401>/Kt'
   */
  1.0,

  /* Mask Parameter: PIDController_Kt_m
   * Referenced by: '<S351>/Kt'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S535>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S533>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S536>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S529>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_dp
   * Referenced by: '<S527>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S530>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S25>/Serial Transmit'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S34>/Constant2'
   */
  360.0,

  /* Expression: [1]
   * Referenced by: '<S301>/Out1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S307>/Constant5'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S307>/Switch1'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<S37>/r_rif'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S426>/Alarm_Int'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S429>/Alarm_Int'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S434>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S434>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S434>/Alarm Safe'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S436>/Memory'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S38>/Constant1'
   */
  20.0,

  /* Expression: 180/pi
   * Referenced by: '<S413>/Gain'
   */
  57.295779513082323,

  /* Expression: 50
   * Referenced by: '<S38>/Constant'
   */
  50.0,

  /* Expression: initCond
   * Referenced by: '<S446>/ '
   */
  0.0,

  /* Expression: initCond
   * Referenced by: '<S447>/ '
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S445>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S438>/Memory'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S444>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S438>/Memory1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_d
   * Referenced by: '<S439>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S439>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S439>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0
   * Referenced by: '<S439>/Out4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S439>/Memory3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S448>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: h_ref_Y0
   * Referenced by: '<S451>/h_ref'
   */
  0.0,

  /* Computed Parameter: flare_data_Y0
   * Referenced by: '<S451>/flare_data'
   */
  0.0,

  /* Computed Parameter: landing_abort_Y0
   * Referenced by: '<S451>/landing_abort'
   */
  0.0,

  /* Computed Parameter: rc_ref_app_Y0
   * Referenced by: '<S451>/rc_ref_app'
   */
  0.0,

  /* Expression: -100
   * Referenced by: '<S451>/x_g0'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S451>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S451>/Constant4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S451>/Discrete-Time Integrator'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S451>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S451>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S451>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S451>/Switch'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S451>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S451>/Constant2'
   */
  1.0,

  /* Computed Parameter: h_ref_Y0_n
   * Referenced by: '<S455>/h_ref'
   */
  0.0,

  /* Computed Parameter: RC_ref_Y0
   * Referenced by: '<S455>/RC_ref'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S455>/Gain'
   */
  -1.0,

  /* Computed Parameter: psi_ref_landing_Y0
   * Referenced by: '<S456>/psi_ref_landing'
   */
  0.0,

  /* Expression: -90
   * Referenced by: '<S525>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S525>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S525>/Bias1'
   */
  90.0,

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

  /* Expression: 180
   * Referenced by: '<S522>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S522>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S526>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S526>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S526>/Bias1'
   */
  -180.0,

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
   * Referenced by: '<S523>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S523>/Constant1'
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

  /* Expression: initCond
   * Referenced by: '<S465>/ '
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S440>/Constant3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S440>/Constant8'
   */
  0.0,

  /* Computed Parameter: TAS_AL_Y0
   * Referenced by: '<S440>/TAS_AL'
   */
  0.0,

  /* Computed Parameter: QUOTA_AL_Y0
   * Referenced by: '<S440>/QUOTA_AL'
   */
  0.0,

  /* Computed Parameter: RC_AL_Y0
   * Referenced by: '<S440>/RC_AL'
   */
  0.0,

  /* Computed Parameter: ROTTA_AL_Y0
   * Referenced by: '<S440>/ROTTA_AL'
   */
  0.0,

  /* Computed Parameter: H_LAT_Y0
   * Referenced by: '<S440>/H_LAT'
   */
  0.0,

  /* Computed Parameter: H_LONG_Y0
   * Referenced by: '<S440>/H_LONG'
   */
  0.0,

  /* Computed Parameter: H_ALT_Y0
   * Referenced by: '<S440>/H_ALT'
   */
  0.0,

  /* Expression: [-1000 -800 2000]
   * Referenced by: '<S453>/distance waypoints virtuale'
   */
  { -1000.0, -800.0, 2000.0 },

  /* Expression: 180/pi
   * Referenced by: '<S469>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S470>/Gain'
   */
  57.295779513082323,

  /* Expression: [45 45 45]
   * Referenced by: '<S453>/alt waypoint virtuale'
   */
  { 45.0, 45.0, 45.0 },

  /* Expression: 180/pi
   * Referenced by: '<S461>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S460>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S458>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S459>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S521>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S537>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S541>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S540>/Constant4'
   */
  1.0,

  /* Expression: 1/298.257223563
   * Referenced by: '<S539>/Constant'
   */
  0.0033528106647474805,

  /* Expression: 1
   * Referenced by: '<S539>/f'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S538>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 6378137
   * Referenced by: '<S537>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S537>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S537>/Constant3'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S462>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S463>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S464>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S440>/Memory7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S440>/Memory5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S440>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S440>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S440>/Constant4'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S440>/Constant2'
   */
  45.0,

  /* Expression: 1
   * Referenced by: '<S440>/Switch2'
   */
  1.0,

  /* Computed Parameter: RC_Y0
   * Referenced by: '<S441>/RC'
   */
  0.0,

  /* Computed Parameter: VELOCITA_Y0
   * Referenced by: '<S441>/VELOCITA'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_j
   * Referenced by: '<S441>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_m
   * Referenced by: '<S441>/Out4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S441>/Memory4'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S542>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S543>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S544>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Out1_Y0_i
   * Referenced by: '<S442>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0_c
   * Referenced by: '<S442>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0_d
   * Referenced by: '<S442>/Out3'
   */
  0.0,

  /* Computed Parameter: Out4_Y0_c
   * Referenced by: '<S442>/Out4'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S547>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S548>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S549>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S554>/Serial Receive'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S554>/Serial Transmit'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<S571>/Constant1'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S571>/Constant5'
   */
  8.0,

  /* Expression: 4
   * Referenced by: '<S571>/Constant6'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S571>/Constant4'
   */
  4.0,

  /* Expression: 16
   * Referenced by: '<S571>/Constant2'
   */
  16.0,

  /* Expression: 8
   * Referenced by: '<S571>/Constant3'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S568>/Serial Receive1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S578>/Constant2'
   */
  0.0,

  /* Computed Parameter: h_to_subtract_Y0
   * Referenced by: '<S578>/h_to_subtract'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S578>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S578>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S578>/Constant3'
   */
  3.0,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S581>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S581>/Memory'
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
   * Referenced by: '<S575>/Constant'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S27>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S27>/Memory1'
   */
  -1.0,

  /* Expression: 4
   * Referenced by: '<S27>/Switch'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S27>/Constant1'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S27>/Memory'
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
   * Referenced by: '<S554>/Constant'
   */
  62.0,

  /* Expression: tau
   * Referenced by: '<S563>/Constant'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S554>/Gain1'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S563>/Unit Delay'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S550>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S412>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S38>/Constant2'
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
   * Referenced by: '<S551>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S552>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S555>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S556>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S16>/alt_r'
   */
  0.0,

  /* Expression: [10^7;10^7;1000 ;1000]
   * Referenced by: '<S16>/Gain'
   */
  { 1.0E+7, 1.0E+7, 1000.0, 1000.0 },

  /* Expression: 0.01
   * Referenced by: '<S554>/Gain4'
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
   * Referenced by: '<S557>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S553>/Gain1'
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
   * Referenced by: '<S33>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S34>/Switch2'
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
   * Referenced by: '<S29>/Gain2'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S302>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S302>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S586>/Gain'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S340>/Integrator'
   */
  0.02,

  /* Expression: pi/180
   * Referenced by: '<S357>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S30>/Gain'
   */
  57.295779513082323,

  /* Expression: 90
   * Referenced by: '<S29>/Constant2'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S303>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S584>/Gain'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S303>/Constant3'
   */
  2.0,

  /* Computed Parameter: Integrator_gainval_g
   * Referenced by: '<S390>/Integrator'
   */
  0.02,

  /* Expression: 180/pi
   * Referenced by: '<S31>/Gain'
   */
  57.295779513082323,

  /* Expression: [ 1 -1]
   * Referenced by: '<S304>/Discrete Washout Filter'
   */
  { 1.0, -1.0 },

  /* Expression: [1 -0.995]
   * Referenced by: '<S304>/Discrete Washout Filter'
   */
  { 1.0, -0.995 },

  /* Expression: 0
   * Referenced by: '<S304>/Discrete Washout Filter'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S32>/Gain'
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
   * Referenced by: '<S570>/Delay Input2'
   */
  101325.0,

  /* Computed Parameter: sampletime_WtEt
   * Referenced by: '<S570>/sample time'
   */
  0.02,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa'
   */
  0.01,

  /* Expression: 100
   * Referenced by: '<S554>/Gain7'
   */
  100.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Pa to hPa1'
   */
  0.01,

  /* Expression: 2
   * Referenced by: '<S39>/RC_default'
   */
  2.0,

  /* Expression: 70
   * Referenced by: '<S39>/Constant'
   */
  70.0,

  /* Expression: 20
   * Referenced by: '<S39>/Constant1'
   */
  20.0,

  /* Expression: 180/pi
   * Referenced by: '<S559>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S560>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S561>/Gain'
   */
  57.295779513082323,

  /* Expression: 100
   * Referenced by: '<S554>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S554>/Gain2'
   */
  100.0,

  /* Expression: 0.3
   * Referenced by: '<S250>/Hit  Crossing'
   */
  0.3,

  /* Expression: 180/pi
   * Referenced by: '<S414>/Gain'
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
   * Referenced by: '<S27>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S27>/Memory2'
   */
  -1.0,

  /* Expression: 9
   * Referenced by: '<S27>/Switch1'
   */
  9.0,

  /* Computed Parameter: Constant_Value_gw
   * Referenced by: '<S1>/Constant'
   */
  8,

  /* Computed Parameter: Out2_Y0_cb
   * Referenced by: '<S566>/Out2'
   */
  0.0F,

  /* Computed Parameter: T_Y0
   * Referenced by: '<S571>/T'
   */
  0.0F,

  /* Computed Parameter: T_0_Y0
   * Referenced by: '<S577>/T_0'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S575>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S554>/Gain3'
   */
  100.0F,

  /* Computed Parameter: p_Y0
   * Referenced by: '<S571>/p'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S571>/Constant7'
   */
  0U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S571>/Constant10'
   */
  0U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S571>/Constant11'
   */
  0U,

  /* Computed Parameter: Constant8_Value_e
   * Referenced by: '<S571>/Constant8'
   */
  0U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S571>/Constant9'
   */
  0U,

  /* Computed Parameter: onboard_control_sensor_presentu
   * Referenced by: '<S21>/onboard_control_sensor_present uint32'
   */
  { 1U, 1U, 1U },

  /* Computed Parameter: Out3_Y0_a
   * Referenced by: '<S566>/Out3'
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
   * Referenced by: '<S566>/Out4'
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
   * Referenced by: '<S567>/Unit Delay'
   */
  0,

  /* Computed Parameter: Constant3_Value_ok
   * Referenced by: '<S567>/Constant3'
   */
  1,

  /* Computed Parameter: Gain3_Gain_o
   * Referenced by: '<S8>/Gain3'
   */
  -128,

  /* Computed Parameter: Memory_InitialCondition_j
   * Referenced by: '<S439>/Memory'
   */
  0U,

  /* Computed Parameter: Memory1_InitialCondition_g
   * Referenced by: '<S439>/Memory1'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition_n
   * Referenced by: '<S439>/Memory2'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S439>/Memory6'
   */
  0U,

  /* Computed Parameter: mario_Y0
   * Referenced by: '<S581>/mario'
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
   * Referenced by: '<S554>/Inizio MSG'
   */
  { 62U, 255U },

  /* Computed Parameter: FineMSG1_Value
   * Referenced by: '<S554>/Fine MSG1'
   */
  60U,

  /* Start of '<S567>/One_time_initialization' */
  {
    /* Mask Parameter: BitwiseOperator1_BitMask
     * Referenced by: '<S574>/Bitwise Operator1'
     */
    255U,

    /* Expression: 0.02
     * Referenced by: '<S574>/I2C Read12'
     */
    0.02,

    /* Computed Parameter: dig_T2_Y0
     * Referenced by: '<S574>/dig_T2'
     */
    0,

    /* Computed Parameter: dig_T3_Y0
     * Referenced by: '<S574>/dig_T3'
     */
    0,

    /* Computed Parameter: dig_p2_Y0
     * Referenced by: '<S574>/dig_p2'
     */
    0,

    /* Computed Parameter: dig_p3_Y0
     * Referenced by: '<S574>/dig_p3'
     */
    0,

    /* Computed Parameter: dig_p4_Y0
     * Referenced by: '<S574>/dig_p4'
     */
    0,

    /* Computed Parameter: dig_p5_Y0
     * Referenced by: '<S574>/dig_p5'
     */
    0,

    /* Computed Parameter: dig_p6_Y0
     * Referenced by: '<S574>/dig_p6'
     */
    0,

    /* Computed Parameter: dig_p7_Y0
     * Referenced by: '<S574>/dig_p7'
     */
    0,

    /* Computed Parameter: dig_p8_Y0
     * Referenced by: '<S574>/dig_p8'
     */
    0,

    /* Computed Parameter: dig_p9_Y0
     * Referenced by: '<S574>/dig_p9'
     */
    0,

    /* Computed Parameter: dig_T1_Y0
     * Referenced by: '<S574>/dig_T1'
     */
    0U,

    /* Computed Parameter: dig_p1_Y0
     * Referenced by: '<S574>/dig_p1'
     */
    0U,

    /* Computed Parameter: pwm_max_min_Y0
     * Referenced by: '<S574>/pwm_max_min'
     */
    0U,

    /* Computed Parameter: registromemoria2_Value
     * Referenced by: '<S574>/registro memoria2 '
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S574>/Constant1'
     */
    0U,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S574>/Constant4'
     */
    47U
  }
  ,

  /* End of '<S567>/One_time_initialization' */

  /* Start of '<S409>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S422>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S409>/Resettable Subsystem' */

  /* Start of '<S409>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S420>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S420>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S420>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S420>/Switch'
     */
    2.0
  }
  ,

  /* End of '<S409>/Enabled Subsystem' */

  /* Start of '<S408>/Resettable Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S419>/Memory'
     */
    0.0
  }
  ,

  /* End of '<S408>/Resettable Subsystem' */

  /* Start of '<S408>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S417>/Constant1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S417>/Constant2'
     */
    1.0,

    /* Computed Parameter: u0_Y0
     * Referenced by: '<S417>/1//0'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S417>/Switch'
     */
    2.0
  }
  /* End of '<S408>/Enabled Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
