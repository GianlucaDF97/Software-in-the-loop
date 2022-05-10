/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210426_ahrs.h
 *
 * Code generated for Simulink model 'a_20210426_ahrs'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Apr 27 15:03:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210426_ahrs_h_
#define RTW_HEADER_a_20210426_ahrs_h_
#include <math.h>
#include <stddef.h>
#ifndef a_20210426_ahrs_COMMON_INCLUDES_
#define a_20210426_ahrs_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* a_20210426_ahrs_COMMON_INCLUDES_ */

#include "a_20210426_ahrs_types.h"
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
  char_T b_data[64];
  char_T sfull[64];
  real32_T ByteUnpack_o2[9];           /* '<Root>/Byte Unpack' */
  uint8_T SFunctionBuilder_o1[41];     /* '<Root>/S-Function Builder' */
  uint8_T SFunctionBuilder_o2;         /* '<Root>/S-Function Builder' */
  uint8_T ByteUnpack_o1[4];            /* '<Root>/Byte Unpack' */
  uint8_T ByteUnpack_o3;               /* '<Root>/Byte Unpack' */
  uint8_T Mex_out[41];                 /* '<Root>/MATLAB Function1' */
} B_a_20210426_ahrs_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Transmit' */
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  uint8_T Delay_DSTATE[41];            /* '<Root>/Delay' */
} DW_a_20210426_ahrs_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Misure_MTi[9];              /* '<Root>/Misure_MTi' */
} ExtY_a_20210426_ahrs_T;

/* Parameters (default storage) */
struct P_a_20210426_ahrs_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  uint8_T Delay_InitialCondition;  /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  uint8_T Constant_Value[5];           /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210426_ahrs_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_a_20210426_ahrs_T a_20210426_ahrs_P;

/* Block signals (default storage) */
extern B_a_20210426_ahrs_T a_20210426_ahrs_B;

/* Block states (default storage) */
extern DW_a_20210426_ahrs_T a_20210426_ahrs_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_a_20210426_ahrs_T a_20210426_ahrs_Y;

/* Model entry point functions */
extern void a_20210426_ahrs_initialize(void);
extern void a_20210426_ahrs_step(void);
extern void a_20210426_ahrs_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210426_ahrs_T *const a_20210426_ahrs_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 */

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
 * '<Root>' : 'a_20210426_ahrs'
 * '<S1>'   : 'a_20210426_ahrs/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_a_20210426_ahrs_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
