//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model_private.h
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
#ifndef RTW_HEADER_Aenea_model_private_h_
#define RTW_HEADER_Aenea_model_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Aenea_model.h"
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

// Used to reverse endianness
#define SWAP16(x)                      (((x) >> 8) | (((x) & 0xff) << 8))
#define SWAP32(x)                      (SWAP16((x) >> 16) | (SWAP16((x) & 0xffff) << 16))
#ifdef __cplusplus

extern "C" {

#endif

  extern void MavLink_Send_sfun_Start_wrapper(void);
  extern void MavLink_Send_sfun_Outputs_wrapper(const uint8_T *mavlink_buf_out,
    const uint16_T *mavlink_buf_len);
  extern void MavLink_Send_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void BMP280_sfun_Start_wrapper(void);
  extern void BMP280_sfun_Outputs_wrapper(const real32_T *h_ref,
    real32_T *OAT,
    real32_T *BaroPressure,
    real32_T *BaroAlt);
  extern void BMP280_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Mti_sfun_Start_wrapper(void);
  extern void Mti_sfun_Outputs_wrapper(const real_T *debug,
    uint8_T *messaggio);
  extern void Mti_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Seriale_mav_sfun_Start_wrapper(void);
  extern void Seriale_mav_sfun_Outputs_wrapper(uint8_T *Messaggio,
    int32_T *serial_available);
  extern void Seriale_mav_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void receive_MAVLink_v4_6_beta_AL_HITL_HOME_sfun_Start_wrapper(void);
  extern void receive_MAVLink_v4_6_beta_AL_HITL_HOME_sfun_Outputs_wrapper(const
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
    uint8_T *go_home,
    const int_T u_width);
  extern void receive_MAVLink_v4_6_beta_AL_HITL_HOME_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GPS_sfun_Start_wrapper(void);
  extern void GPS_sfun_Outputs_wrapper(real_T *lat,
    real_T *lon,
    real_T *V,
    real_T *MSL,
    real_T *heading,
    real_T *fixType,
    boolean_T *gps_data_fresh);
  extern void GPS_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void pitot_lidar_sfun_Start_wrapper(void);
  extern void pitot_lidar_sfun_Outputs_wrapper(real_T *velocity,
    real_T *distance,
    real_T *dp);
  extern void pitot_lidar_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void blink_sfun_Start_wrapper(void);
  extern void blink_sfun_Outputs_wrapper(const boolean_T *clock);
  extern void blink_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_throttle_sfun_Start_wrapper(void);
  extern void PWMinterrupt_throttle_sfun_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_throttle_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_elevator_sfun_Start_wrapper(void);
  extern void PWMinterrupt_elevator_sfun_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_elevator_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_aileron_sfun_Start_wrapper(void);
  extern void PWMinterrupt_aileron_sfun_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_aileron_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_rudder_sfun_Start_wrapper(void);
  extern void PWMinterrupt_rudder_sfun_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_rudder_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void send_MAVLink_v4_4_2_beta_3_HOME_sfun_Start_wrapper(void);
  extern void send_MAVLink_v4_4_2_beta_3_HOME_sfun_Outputs_wrapper(const uint8_T
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
  extern void send_MAVLink_v4_4_2_beta_3_HOME_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void enable_sfun_Start_wrapper(void);
  extern void enable_sfun_Outputs_wrapper(const uint8_T *u0,
    uint8_T *y0);
  extern void enable_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PWMinterrupt_goHome_sfun_Start_wrapper(void);
  extern void PWMinterrupt_goHome_sfun_Outputs_wrapper(int16_T *out);
  extern void PWMinterrupt_goHome_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_manetta_sfun_Start_wrapper(real_T *xD);
  extern void Servo_manetta_sfun_Outputs_wrapper(const int16_T *tau,
    const real_T *xD);
  extern void Servo_manetta_sfun_Update_wrapper(const int16_T *tau,
    real_T *xD);
  extern void Servo_manetta_sfun_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_equilibratore_sfun_Start_wrapper(real_T *xD);
  extern void Servo_equilibratore_sfun_Outputs_wrapper(const int16_T *tau,
    const real_T *xD);
  extern void Servo_equilibratore_sfun_Update_wrapper(const int16_T *tau,
    real_T *xD);
  extern void Servo_equilibratore_sfun_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_alettoni_sfun_Start_wrapper(real_T *xD);
  extern void Servo_alettoni_sfun_Outputs_wrapper(const int16_T *tau,
    const real_T *xD);
  extern void Servo_alettoni_sfun_Update_wrapper(const int16_T *tau,
    real_T *xD);
  extern void Servo_alettoni_sfun_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Servo_timone_sfun_Start_wrapper(real_T *xD);
  extern void Servo_timone_sfun_Outputs_wrapper(const int16_T *tau,
    const real_T *xD);
  extern void Servo_timone_sfun_Update_wrapper(const int16_T *tau,
    real_T *xD);
  extern void Servo_timone_sfun_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Signal_Logger_sfun_Start_wrapper(void);
  extern void Signal_Logger_sfun_Outputs_wrapper(const BUS_log_t *flightData,
    const boolean_T *sec_flag);
  extern void Signal_Logger_sfun_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

extern real_T rt_roundd_snf(real_T u);
extern real32_T rt_roundf_snf(real32_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern void Aenea_model_EnabledSubsystem(uint8_T rtu_Enable, real_T rtu_Time,
  real_T *rty_u0);
extern void Aenea_ResettableSubsystem_Reset(DW_ResettableSubsystem_Aenea__T
  *localDW);
extern void Aenea_model_ResettableSubsystem(uint8_T rtu_Reset, real_T *rty_Time,
  DW_ResettableSubsystem_Aenea__T *localDW, ZCE_ResettableSubsystem_Aenea_T
  *localZCE);
extern void Aen_ResettableSubsystem_j_Reset(DW_ResettableSubsystem_Aene_d_T
  *localDW);
extern void Aenea_mod_ResettableSubsystem_p(real_T rtu_Reset, real_T *rty_Time,
  DW_ResettableSubsystem_Aene_d_T *localDW, ZCE_ResettableSubsystem_Aen_h_T
  *localZCE);

#endif                                 // RTW_HEADER_Aenea_model_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
