/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testloaddata1.h
 *
 * Code generated for Simulink model 'testloaddata1'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul  6 18:41:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testloaddata1_h_
#define RTW_HEADER_testloaddata1_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#ifndef testloaddata1_COMMON_INCLUDES_
#define testloaddata1_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rt_logging.h"
#include "MW_gpio.h"
#include "MW_SCI.h"
#endif                                 /* testloaddata1_COMMON_INCLUDES_ */

#include "testloaddata1_types.h"

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
  uint32_T ByteUnpack_o6;              /* '<S18>/Byte Unpack' */
  real32_T ByteUnpack_o2[4];           /* '<S18>/Byte Unpack' */
  uint16_T ByteUnpack_o4[10];          /* '<S18>/Byte Unpack' */
  int16_T ByteUnpack_o3[9];            /* '<S18>/Byte Unpack' */
  uint8_T ByteUnpack_o1[2];            /* '<S18>/Byte Unpack' */
  uint8_T ByteUnpack_o5[2];            /* '<S18>/Byte Unpack' */
  uint8_T ByteUnpack_o7;               /* '<S18>/Byte Unpack' */
  uint8_T messaggio[63];               /* '<S16>/MATLAB Function' */
} B_testloaddata1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S3>/Digital Read' */
  codertarget_linux_blocks_Digi_T obj_k;/* '<S2>/Digital Read' */
  codertarget_raspi_internal_SC_T obj_h;/* '<S6>/Serial Read' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T status;                       /* '<Root>/MATLAB Function2' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
  uint8_T message[63];                 /* '<S16>/MATLAB Function' */
  uint8_T counter;                     /* '<S16>/MATLAB Function' */
  boolean_T Memory1_PreviousInput;     /* '<Root>/Memory1' */
  boolean_T start_found;               /* '<S16>/MATLAB Function' */
  boolean_T spento;                    /* '<Root>/MATLAB Function2' */
} DW_testloaddata1_T;

/* Parameters (default storage) */
struct P_testloaddata1_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: sampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T DigitalRead_SampleTime_p;     /* Expression: sampleTime
                                        * Referenced by: '<S3>/Digital Read'
                                        */
  real_T SerialRead_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S6>/Serial Read'
                                        */
  real_T fix_Y0;                       /* Computed Parameter: fix_Y0
                                        * Referenced by: '<S18>/fix '
                                        */
  real_T mario_Y0;                     /* Computed Parameter: mario_Y0
                                        * Referenced by: '<S18>/mario'
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
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: pi/180
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.01
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Knot2ms_Gain;                 /* Expression: 0.514444
                                        * Referenced by: '<S6>/Knot2m//s'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S18>/Out2'
                                        */
  uint32_T pressione_Y0;               /* Computed Parameter: pressione_Y0
                                        * Referenced by: '<S18>/pressione'
                                        */
  int16_T Out3_Y0;                     /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S18>/Out3'
                                        */
  uint16_T Out4_Y0;                    /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S18>/Out4'
                                        */
  boolean_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<Root>/Memory1'
                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_testloaddata1_T {
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
extern P_testloaddata1_T testloaddata1_P;

/* Block signals (default storage) */
extern B_testloaddata1_T testloaddata1_B;

/* Block states (default storage) */
extern DW_testloaddata1_T testloaddata1_DW;

/* Model entry point functions */
extern void testloaddata1_initialize(void);
extern void testloaddata1_step(void);
extern void testloaddata1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testloaddata1_T *const testloaddata1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type  Conversion' : Unused code path elimination
 * Block '<S10>/Gain1' : Unused code path elimination
 * Block '<S11>/Gain1' : Unused code path elimination
 * Block '<S12>/Gain1' : Unused code path elimination
 * Block '<S13>/Gain1' : Unused code path elimination
 * Block '<S14>/Gain1' : Unused code path elimination
 * Block '<S15>/Gain1' : Unused code path elimination
 * Block '<S6>/Gain2' : Unused code path elimination
 * Block '<S18>/Data Type Conversion' : Unused code path elimination
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
 * '<Root>' : 'testloaddata1'
 * '<S1>'   : 'testloaddata1/ 2'
 * '<S2>'   : 'testloaddata1/GPIO Read1'
 * '<S3>'   : 'testloaddata1/GPIO Read2'
 * '<S4>'   : 'testloaddata1/MATLAB Function1'
 * '<S5>'   : 'testloaddata1/MATLAB Function2'
 * '<S6>'   : 'testloaddata1/RX Sensori1'
 * '<S7>'   : 'testloaddata1/RX Sensori1/Degrees to Radians'
 * '<S8>'   : 'testloaddata1/RX Sensori1/Degrees to Radians1'
 * '<S9>'   : 'testloaddata1/RX Sensori1/Degrees to Radians2'
 * '<S10>'  : 'testloaddata1/RX Sensori1/Degrees to Radians3'
 * '<S11>'  : 'testloaddata1/RX Sensori1/Degrees to Radians4'
 * '<S12>'  : 'testloaddata1/RX Sensori1/Degrees to Radians5'
 * '<S13>'  : 'testloaddata1/RX Sensori1/Degrees to Radians6'
 * '<S14>'  : 'testloaddata1/RX Sensori1/Degrees to Radians7'
 * '<S15>'  : 'testloaddata1/RX Sensori1/Degrees to Radians8'
 * '<S16>'  : 'testloaddata1/RX Sensori1/Subsystem'
 * '<S17>'  : 'testloaddata1/RX Sensori1/Subsystem/MATLAB Function'
 * '<S18>'  : 'testloaddata1/RX Sensori1/Subsystem/Subsystem'
 */
#endif                                 /* RTW_HEADER_testloaddata1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
