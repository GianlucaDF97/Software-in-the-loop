//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Aenea_model_private.h
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.49
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Tue Dec 20 09:36:06 2022
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

  extern void GPS_sfun_Start_wrapper(void);
  extern void GPS_sfun_Outputs_wrapper(real_T *d_lat,
    real_T *d_long,
    real_T *f_groundspeed,
    real_T *f_msl,
    real_T *f_heading,
    real_T *d_fixType);
  extern void GPS_sfun_Terminate_wrapper(void);

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

#endif                                 // RTW_HEADER_Aenea_model_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
