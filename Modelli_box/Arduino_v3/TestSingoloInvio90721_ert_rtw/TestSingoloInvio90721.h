/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestSingoloInvio90721.h
 *
 * Code generated for Simulink model 'TestSingoloInvio90721'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jul  9 17:53:27 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestSingoloInvio90721_h_
#define RTW_HEADER_TestSingoloInvio90721_h_
#include <math.h>
#include <stddef.h>
#ifndef TestSingoloInvio90721_COMMON_INCLUDES_
#define TestSingoloInvio90721_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                              /* TestSingoloInvio90721_COMMON_INCLUDES_ */

#include "TestSingoloInvio90721_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T pressione;                  /* '<Root>/Data Type Conversion9' */
  real32_T DataTypeConversion6[4];     /* '<Root>/Data Type Conversion6' */
  uint16_T GPSServo[10];               /* '<Root>/Data Type Conversion5' */
  int16_T DataTypeConversion3[9];      /* '<Root>/Data Type Conversion3' */
  uint8_T DataTypeConversion8[2];      /* '<Root>/Data Type Conversion8' */
  uint8_T BytePack[63];                /* '<Root>/Byte Pack' */
  uint8_T dataIn[63];
} B_TestSingoloInvio90721_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Serial Transmit' */
} DW_TestSingoloInvio90721_T;

/* Parameters (default storage) */
struct P_TestSingoloInvio90721_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T Constant_Value;               /* Expression: 12
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 24
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant24_Value;             /* Expression: 110
                                        * Referenced by: '<Root>/Constant24'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant9_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant5_Value;              /* Expression: 4
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: 6
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: 5
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant8_Value;              /* Expression: 7
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant10_Value;             /* Expression: 8
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 9
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 13
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 14
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 15
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T Constant15_Value;             /* Expression: 16
                                        * Referenced by: '<Root>/Constant15'
                                        */
  real_T Constant16_Value;             /* Expression: 17
                                        * Referenced by: '<Root>/Constant16'
                                        */
  real_T Constant17_Value;             /* Expression: 18
                                        * Referenced by: '<Root>/Constant17'
                                        */
  real_T Constant18_Value;             /* Expression: 19
                                        * Referenced by: '<Root>/Constant18'
                                        */
  real_T Constant19_Value;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant19'
                                        */
  real_T Constant20_Value;             /* Expression: 21
                                        * Referenced by: '<Root>/Constant20'
                                        */
  real_T Constant21_Value;             /* Expression: 22
                                        * Referenced by: '<Root>/Constant21'
                                        */
  real_T Constant25_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant25'
                                        */
  real_T Constant22_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant22'
                                        */
  real_T Constant23_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/Constant23'
                                        */
  uint8_T InizioMSG_Value[2];          /* Computed Parameter: InizioMSG_Value
                                        * Referenced by: '<Root>/Inizio MSG'
                                        */
  uint8_T FineMSG1_Value;              /* Computed Parameter: FineMSG1_Value
                                        * Referenced by: '<Root>/Fine MSG1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestSingoloInvio90721_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_TestSingoloInvio90721_T TestSingoloInvio90721_P;

/* Block signals (default storage) */
extern B_TestSingoloInvio90721_T TestSingoloInvio90721_B;

/* Block states (default storage) */
extern DW_TestSingoloInvio90721_T TestSingoloInvio90721_DW;

/* Model entry point functions */
extern void TestSingoloInvio90721_initialize(void);
extern void TestSingoloInvio90721_step(void);
extern void TestSingoloInvio90721_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestSingoloInvio9072_T *const TestSingoloInvio90721_M;
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
 * '<Root>' : 'TestSingoloInvio90721'
 */
#endif                                 /* RTW_HEADER_TestSingoloInvio90721_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
