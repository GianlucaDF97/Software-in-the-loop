/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GPS_12_10_private.h
 *
 * Code generated for Simulink model 'GPS_12_10'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Oct 19 16:53:32 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GPS_12_10_private_h_
#define RTW_HEADER_GPS_12_10_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
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

extern real_T rt_roundd_snf(real_T u);
extern real32_T rt_roundf_snf(real32_T u);
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

#endif                                 /* RTW_HEADER_GPS_12_10_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
