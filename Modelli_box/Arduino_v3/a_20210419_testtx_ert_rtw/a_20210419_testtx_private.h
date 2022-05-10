/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210419_testtx_private.h
 *
 * Code generated for Simulink model 'a_20210419_testtx'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May  4 16:38:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210419_testtx_private_h_
#define RTW_HEADER_a_20210419_testtx_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

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

extern real_T rt_roundd_snf(real_T u);

#endif                             /* RTW_HEADER_a_20210419_testtx_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
