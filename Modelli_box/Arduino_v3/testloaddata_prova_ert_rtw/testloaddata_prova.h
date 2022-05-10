/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testloaddata_prova.h
 *
 * Code generated for Simulink model 'testloaddata_prova'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jul 16 17:26:32 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testloaddata_prova_h_
#define RTW_HEADER_testloaddata_prova_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#ifndef testloaddata_prova_COMMON_INCLUDES_
#define testloaddata_prova_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rt_logging.h"
#include "MW_gpio.h"
#include "MW_SCI.h"
#endif                                 /* testloaddata_prova_COMMON_INCLUDES_ */

#include "testloaddata_prova_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[10];
  uint8_T RxData[63];
  uint8_T RxDataLocChar[63];
  uint32_T ByteUnpack_o7;              /* '<S16>/Byte Unpack' */
  real32_T ByteUnpack_o2[4];           /* '<S16>/Byte Unpack' */
  uint16_T ByteUnpack_o4[9];           /* '<S16>/Byte Unpack' */
  uint16_T ByteUnpack_o6;              /* '<S16>/Byte Unpack' */
  int16_T ByteUnpack_o3[9];            /* '<S16>/Byte Unpack' */
  uint8_T ByteUnpack_o1[2];            /* '<S16>/Byte Unpack' */
  uint8_T ByteUnpack_o5[2];            /* '<S16>/Byte Unpack' */
  uint8_T ByteUnpack_o8;               /* '<S16>/Byte Unpack' */
  uint8_T messaggio[63];               /* '<S14>/MATLAB Function' */
} B_testloaddata_prova_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S2>/Digital Read' */
  codertarget_raspi_internal_SC_T obj_h;/* '<S4>/Serial Read' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
  uint8_T message[63];                 /* '<S14>/MATLAB Function' */
  uint8_T counter;                     /* '<S14>/MATLAB Function' */
  boolean_T start_found;               /* '<S14>/MATLAB Function' */
} DW_testloaddata_prova_T;

/* Parameters (default storage) */
struct P_testloaddata_prova_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: sampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S4>/Serial Read'
                                        */
  real_T fix_Y0;                       /* Computed Parameter: fix_Y0
                                        * Referenced by: '<S16>/fix '
                                        */
  real_T mario_Y0;                     /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S16>/mario'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<Root>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete-Time Integrator'
                                          */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: pi/180
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.01
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Knot2ms_Gain;                 /* Expression: 0.514444
                                        * Referenced by: '<S4>/Knot2m//s'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S16>/Out2'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S16>/p'
                                        */
  int16_T Out3_Y0;                     /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S16>/Out3'
                                        */
  uint16_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S4>/Gain3'
                                        */
  uint16_T Out4_Y0;                    /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S16>/Out4'
                                        */
  uint16_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S16>/T'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testloaddata_prova_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_testloaddata_prova_T testloaddata_prova_P;

/* Block signals (default storage) */
extern B_testloaddata_prova_T testloaddata_prova_B;

/* Block states (default storage) */
extern DW_testloaddata_prova_T testloaddata_prova_DW;

/* Model entry point functions */
extern void testloaddata_prova_initialize(void);
extern void testloaddata_prova_step(void);
extern void testloaddata_prova_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testloaddata_prova_T *const testloaddata_prova_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type  Conversion' : Unused code path elimination
 * Block '<S8>/Gain1' : Unused code path elimination
 * Block '<S9>/Gain1' : Unused code path elimination
 * Block '<S10>/Gain1' : Unused code path elimination
 * Block '<S11>/Gain1' : Unused code path elimination
 * Block '<S12>/Gain1' : Unused code path elimination
 * Block '<S13>/Gain1' : Unused code path elimination
 * Block '<S4>/Gain2' : Unused code path elimination
 * Block '<S16>/Data Type Conversion' : Unused code path elimination
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
 * '<Root>' : 'testloaddata_prova'
 * '<S1>'   : 'testloaddata_prova/ 2'
 * '<S2>'   : 'testloaddata_prova/GPIO Read1'
 * '<S3>'   : 'testloaddata_prova/MATLAB Function1'
 * '<S4>'   : 'testloaddata_prova/RX Sensori1'
 * '<S5>'   : 'testloaddata_prova/RX Sensori1/Degrees to Radians'
 * '<S6>'   : 'testloaddata_prova/RX Sensori1/Degrees to Radians1'
 * '<S7>'   : 'testloaddata_prova/RX Sensori1/Degrees to Radians2'
 * '<S8>'   : 'testloaddata_prova/RX Sensori1/Degrees to Radians3'
 * '<S9>'   : 'testloaddata_prova/RX Sensori1/Degrees to Radians4'
 * '<S10>'  : 'testloaddata_prova/RX Sensori1/Degrees to Radians5'
 * '<S11>'  : 'testloaddata_prova/RX Sensori1/Degrees to Radians6'
 * '<S12>'  : 'testloaddata_prova/RX Sensori1/Degrees to Radians7'
 * '<S13>'  : 'testloaddata_prova/RX Sensori1/Degrees to Radians8'
 * '<S14>'  : 'testloaddata_prova/RX Sensori1/Subsystem'
 * '<S15>'  : 'testloaddata_prova/RX Sensori1/Subsystem/MATLAB Function'
 * '<S16>'  : 'testloaddata_prova/RX Sensori1/Subsystem/Subsystem'
 */
#endif                                 /* RTW_HEADER_testloaddata_prova_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
