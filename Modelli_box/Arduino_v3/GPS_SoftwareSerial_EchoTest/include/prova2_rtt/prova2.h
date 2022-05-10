/*
 * File: prova2.h
 *
 * Code generated for Simulink model 'prova2'.
 *
 * Model version                  : 1.285
 * Simulink Coder version         : 8.2 (R2012a) 29-Dec-2011
 * TLC version                    : 8.2 (Dec 29 2011)
 * C/C++ source code generated on : Sat Jan 19 14:27:22 2013
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_prova2_h_
#define RTW_HEADER_prova2_h_
#ifndef prova2_COMMON_INCLUDES_
# define prova2_COMMON_INCLUDES_
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* prova2_COMMON_INCLUDES_ */

#include "prova2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  uint16_T SFunctionBuilder_o2;        /* '<Root>/S-Function Builder' */
  uint8_T SFunctionBuilder_o1[100];    /* '<Root>/S-Function Builder' */
} BlockIO_prova2;

/* Parameters (auto storage) */
struct Parameters_prova2_ {
  uint32_T Customcode_Value;           /* Computed Parameter: Customcode_Value
                                        * Referenced by: '<Root>/Custom code'
                                        */
  uint8_T TypeAutopilotBaseModeSystemStat[5];/* Computed Parameter: TypeAutopilotBaseModeSystemStat
                                              * Referenced by: '<Root>/Type Autopilot Base Mode System Status MAVlink version'
                                              */
};

/* Real-time Model Data Structure */
struct RT_MODEL_prova2 {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

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

/* Block parameters (auto storage) */
extern Parameters_prova2 prova2_P;

/* Block signals (auto storage) */
extern BlockIO_prova2 prova2_B;

/* Model entry point functions */
extern void prova2_initialize(void);
extern void prova2_output(void);
extern void prova2_update(void);
extern void prova2_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_prova2 *const prova2_M;

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
 * '<Root>' : 'prova2'
 */
#endif                                 /* RTW_HEADER_prova2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
