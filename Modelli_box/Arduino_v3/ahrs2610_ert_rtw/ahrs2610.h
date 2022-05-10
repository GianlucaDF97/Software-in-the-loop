/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ahrs2610.h
 *
 * Code generated for Simulink model 'ahrs2610'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 13:11:55 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ahrs2610_h_
#define RTW_HEADER_ahrs2610_h_
#include <math.h>
#include <stddef.h>
#ifndef ahrs2610_COMMON_INCLUDES_
#define ahrs2610_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* ahrs2610_COMMON_INCLUDES_ */

#include "ahrs2610_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T ByteUnpack_o2[9];           /* '<S1>/Byte Unpack' */
  real32_T ByteReversal[9];            /* '<S1>/Byte Reversal' */
  uint8_T SFunctionBuilder[41];        /* '<S1>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<S1>/Byte Unpack' */
  uint8_T ByteUnpack_o3;               /* '<S1>/Byte Unpack' */
} B_ahrs2610_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Serial Transmit1' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
} DW_ahrs2610_T;

/* Parameters (default storage) */
struct P_ahrs2610_T_ {
  real_T SerialTransmit1_Protocol;     /* Expression: 0
                                        * Referenced by: '<S1>/Serial Transmit1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ahrs2610_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_ahrs2610_T ahrs2610_P;

/* Block signals (default storage) */
extern B_ahrs2610_T ahrs2610_B;

/* Block states (default storage) */
extern DW_ahrs2610_T ahrs2610_DW;

/* Model entry point functions */
extern void ahrs2610_initialize(void);
extern void ahrs2610_step(void);
extern void ahrs2610_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ahrs2610_T *const ahrs2610_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ahrs2610'
 * '<S1>'   : 'ahrs2610/MTi'
 */
#endif                                 /* RTW_HEADER_ahrs2610_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
