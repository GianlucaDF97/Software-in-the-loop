/*
 * modello_HITL_SFT_v4_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modello_HITL_SFT_v4".
 *
 * Model version              : 5.53
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 *
 */

#ifndef RTW_HEADER_modello_HITL_SFT_v4_private_h_
#define RTW_HEADER_modello_HITL_SFT_v4_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "modello_HITL_SFT_v4.h"

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

#ifndef COESA76_DEFINE_DATA

/* 1976 COESA atmosphere model */
#define NUM1976PTS                     8

static real_T altitude76[NUM1976PTS] = {/* in meters (m) */
  0.0, 11000.0, 20000.0, 32000.0, 47000.0, 51000.0, 71000.0, 84852.0 };

static real_T tempGradient76[NUM1976PTS] = {/* in K/m  */
  (-0.0065), 0.0, 0.0010, 0.0028, 0.0, -0.0028, -0.0020, -0.0020 };

#define COESA76_DEFINE_DATA
#endif                                 /* COESA76_DEFINE_DATA */

#ifndef ATMOS_DEFINE
#define PRESSURE0                      101325.0                  /*  N/m^2                  */
#define TEMPERATURE0                   288.15                    /*  K                      */
#define GRAV_CONST                     9.80665                   /*  m/s^2                  */
#define MOL_WT                         28.9644                   /*  kg/kgmol (air)         */
#define R_HAT                          8314.32                   /*  J/kgmol.K (gas const.) */
#define GAMMA                          1.4                       /*  (specific heat ratio) */
#define GMR                            ( GRAV_CONST * MOL_WT / R_HAT )
#define ATMOS_DEFINE
#endif                                 /* ATMOS_DEFINE */

#ifdef __cplusplus

extern "C" {

#endif

  extern void SImulate_messageMTi_nuovo_Start_wrapper(void);
  extern void SImulate_messageMTi_nuovo_Outputs_wrapper(const real32_T *input,
    uint8_T *MTimsg,
    int32_T *Len,
    real32_T *P_num);
  extern void SImulate_messageMTi_nuovo_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void outputStream_v1_Start_wrapper(void);
  extern void outputStream_v1_Outputs_wrapper(const real_T *u0,
    uint8_T *txBuf,
    uint32_T *length);
  extern void outputStream_v1_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void SImulate_messageGPS_nmea_carriage_return_Start_wrapper(void);
  extern void SImulate_messageGPS_nmea_carriage_return_Outputs_wrapper(const
    real_T *Lat,
    const real_T *Long,
    const real_T *V_,
    const real_T *heading,
    const real_T *h,
    uint8_T *GPSmsg);
  extern void SImulate_messageGPS_nmea_carriage_return_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

/* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
extern dsserChannel *rtiDS4201SER_B1_Ser[4];
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(const real_T u0[3], const real_T
  u1[9], real_T y[3]);
void InitCalcAtmosCOESA(real_T *temperature76, real_T *pressureRatio76);
void CalcPAltCOESA(const real_T *pressure, real_T *altitude, real_T
                   *temperature76, real_T *pressureRatio76, int_T numPoints);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
extern void modello_HITL_SFT_v4_MATLABFunction(const real_T rtu_degree[43],
  const real_T rtu_microsec[43], real_T rtu_input, real_T rtu_flag,
  B_MATLABFunction_modello_HITL_SFT_v4_T *localB);
extern void modello_HITL_SFT_v4_FunctionCallSubsystem(void);

/* private model entry point functions */
extern void modello_HITL_SFT_v4_derivatives(void);

#endif                           /* RTW_HEADER_modello_HITL_SFT_v4_private_h_ */
