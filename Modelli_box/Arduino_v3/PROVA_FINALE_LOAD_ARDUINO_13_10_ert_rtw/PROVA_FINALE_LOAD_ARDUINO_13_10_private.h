/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PROVA_FINALE_LOAD_ARDUINO_13_10_private.h
 *
 * Code generated for Simulink model 'PROVA_FINALE_LOAD_ARDUINO_13_10'.
 *
 * Model version                  : 5.19
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 14:08:57 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PROVA_FINALE_LOAD_ARDUINO_13_10_private_h_
#define RTW_HEADER_PROVA_FINALE_LOAD_ARDUINO_13_10_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "PROVA_FINALE_LOAD_ARDUINO_13_10.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Used to reverse endianness */
#define SWAP16(x)                      (((x) >> 8) | (((x) & 0xff) << 8))
#define SWAP32(x)                      (SWAP16((x) >> 16) | (SWAP16((x) & 0xffff) << 16))
#ifdef __cplusplus

extern "C" {

#endif

  extern void calc_T_Start_wrapper(void);
  extern void calc_T_Outputs_wrapper(const uint16_T *dig_T1,
    const int16_T *dig_T2,
    const int16_T *dig_T3,
    const int32_T *adc_T,
    real32_T *T,
    int32_T *t_fine);
  extern void calc_T_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void calc_p_Start_wrapper(void);
  extern void calc_p_Outputs_wrapper(const uint16_T *dig_p1,
    const int16_T *dig_p2,
    const int16_T *dig_p3,
    const int16_T *dig_p4,
    const int16_T *dig_p5,
    const int16_T *dig_p6,
    const int16_T *dig_p7,
    const int16_T *dig_p8,
    const int16_T *dig_p9,
    const int32_T *adc_P,
    const int32_T *t_fine,
    uint32_T *p);
  extern void calc_p_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Mti_Start_wrapper(real_T *xD);
  extern void Mti_Outputs_wrapper(uint8_T *messaggio,
    const real_T *xD);
  extern void Mti_Update_wrapper(uint8_T *messaggio,
    real_T *xD);
  extern void Mti_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Seriale_mav_Start_wrapper(real_T *xD);
  extern void Seriale_mav_Outputs_wrapper(const uint8_T *inutile,
    uint8_T *Messaggio,
    int32_T *serial_available,
    const real_T *xD);
  extern void Seriale_mav_Update_wrapper(const uint8_T *inutile,
    uint8_T *Messaggio,
    int32_T *serial_available,
    real_T *xD);
  extern void Seriale_mav_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void receive_MAVLink_v4_6_beta_AL_HITL_HOME_Start_wrapper(void);
  extern void receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper(const
    uint8_T *bytes_in,
    const int32_T *len_in,
    const uint16_T *count,
    const uint8_T *AP_SI,
    const uint16_T *mem_in,
    const uint8_T *H_mav,
    const uint8_T *H_data_to_AIR_RX,
    const uint8_T *Base_mode_to_SF,
    uint8_T *Heartbeat_data,
    uint32_T *Heartbeat_custom,
    uint8_T *Mav_state,
    uint8_T *int_sw_safe_interv,
    uint8_T *Cal_home,
    uint8_T *Base_mode,
    uint16_T *GC_request,
    real32_T *P_value_change,
    uint16_T *WP_info,
    real32_T *WP_param,
    uint16_T *mem_out,
    uint8_T *T_number,
    real32_T *T_ref,
    uint8_T *Cal_alt,
    uint8_T *T_int,
    uint8_T *P_int,
    real32_T *P_ref,
    const int_T u_width);
  extern void receive_MAVLink_v4_6_beta_AL_HITL_HOME_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_throttle_v4_4_Start_wrapper(void);
  extern void PWMinterrupt_throttle_v4_4_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_throttle_v4_4_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_goHome_Start_wrapper(void);
  extern void PWMinterrupt_goHome_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_goHome_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_elevator_v4_4_Start_wrapper(void);
  extern void PWMinterrupt_elevator_v4_4_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_elevator_v4_4_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_aileron_v4_4_Start_wrapper(void);
  extern void PWMinterrupt_aileron_v4_4_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_aileron_v4_4_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_rudder_v4_4_Start_wrapper(void);
  extern void PWMinterrupt_rudder_v4_4_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_rudder_v4_4_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void send_MAVLink_v4_4_2_beta_3_HOME_Start_wrapper(void);
  extern void send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(const uint8_T
    *iflogic,
    const uint32_T *time_in,
    const uint8_T *AP_SI,
    const uint16_T *GC_req,
    const real32_T *P_val,
    const uint16_T *WP_info,
    const real32_T *WP_param,
    const uint32_T *ss_onboard,
    const uint16_T *ss_LVDE,
    const int16_T *ss_C,
    const int8_T *ss_R,
    const uint32_T *Heartbeat_custom,
    const uint8_T *Heartbeat_data,
    const int16_T *IMU_data,
    const real32_T *attitude,
    const int32_T *lat_long_alt,
    const int16_T *velGPS,
    const uint16_T *hdg,
    const real32_T *VFR_speed,
    const int16_T *VFR_H,
    const uint16_T *VFR_T,
    const uint16_T *Ser_data,
    const uint16_T *prior_in,
    const real32_T *P_refer,
    const uint8_T *Cal_alt,
    const real32_T *T_0,
    const uint8_T *T_int,
    const real32_T *P_RAW,
    const real32_T *deltaP_RAW,
    const int16_T *AB_T,
    const uint8_T *Cal_home,
    const real_T *H_LAT,
    const real_T *H_LONG,
    const real_T *H_ALT,
    const uint16_T *h_lidar,
    uint8_T *enable,
    uint8_T *msg_out,
    uint16_T *Len,
    uint16_T *prior_out);
  extern void send_MAVLink_v4_4_2_beta_3_HOME_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_microseconds_alettoni_beta_3_Start_wrapper(real_T *xD);
  extern void Servo_microseconds_alettoni_beta_3_Outputs_wrapper(const int16_T
    *tau,
    const real_T *xD);
  extern void Servo_microseconds_alettoni_beta_3_Update_wrapper(const int16_T
    *tau,
    real_T *xD);
  extern void Servo_microseconds_alettoni_beta_3_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_microseconds_manetta_beta_3_Start_wrapper(real_T *xD);
  extern void Servo_microseconds_manetta_beta_3_Outputs_wrapper(const int16_T
    *tau,
    const real_T *xD);
  extern void Servo_microseconds_manetta_beta_3_Update_wrapper(const int16_T
    *tau,
    real_T *xD);
  extern void Servo_microseconds_manetta_beta_3_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_microseconds_timone_beta_3_Start_wrapper(real_T *xD);
  extern void Servo_microseconds_timone_beta_3_Outputs_wrapper(const int16_T
    *tau,
    const real_T *xD);
  extern void Servo_microseconds_timone_beta_3_Update_wrapper(const int16_T *tau,
    real_T *xD);
  extern void Servo_microseconds_timone_beta_3_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_microseconds_equilibratore_beta_3_Start_wrapper(real_T *xD);
  extern void Servo_microseconds_equilibratore_beta_3_Outputs_wrapper(const
    int16_T *tau,
    const real_T *xD);
  extern void Servo_microseconds_equilibratore_beta_3_Update_wrapper(const
    int16_T *tau,
    real_T *xD);
  extern void Servo_microseconds_equilibratore_beta_3_Terminate_wrapper(real_T
    *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Risoluzione_12bit_Start_wrapper(real_T *xD);
  extern void Risoluzione_12bit_Outputs_wrapper(const real_T *xD);
  extern void Risoluzione_12bit_Update_wrapper(real_T *xD);
  extern void Risoluzione_12bit_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_roundd_snf(real_T u);
extern real32_T rt_roundf_snf(real32_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
extern void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n);
extern void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void PROVA_EnabledSubsystem_Init(real_T *rty_u0,
  P_EnabledSubsystem_PROVA_FINA_T *localP);
extern void PROVA_FINA_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time,
  real_T *rty_u0, P_EnabledSubsystem_PROVA_FINA_T *localP);
extern void PR_ResettableSubsystem_Init(DW_ResettableSubsystem_PROVA__T *localDW,
  P_ResettableSubsystem_PROVA_F_T *localP);
extern void P_ResettableSubsystem_Reset(DW_ResettableSubsystem_PROVA__T *localDW,
  P_ResettableSubsystem_PROVA_F_T *localP);
extern real_T PROVA_F_ResettableSubsystem(uint8_T rtu_Reset,
  DW_ResettableSubsystem_PROVA__T *localDW, P_ResettableSubsystem_PROVA_F_T
  *localP, ZCE_ResettableSubsystem_PROVA_T *localZCE);
extern void One_time_initializatio_Init(B_One_time_initialization_PRO_T *localB,
  DW_One_time_initialization_PR_T *localDW, P_One_time_initialization_PRO_T
  *localP);
extern void PRO_One_time_initialization(boolean_T rtu_Enable,
  B_One_time_initialization_PRO_T *localB, DW_One_time_initialization_PR_T
  *localDW, P_One_time_initialization_PRO_T *localP);
extern void One_time_initializatio_Term(DW_One_time_initialization_PR_T *localDW);

#endif               /* RTW_HEADER_PROVA_FINALE_LOAD_ARDUINO_13_10_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
