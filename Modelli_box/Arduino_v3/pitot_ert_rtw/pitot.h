/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pitot.h
 *
 * Code generated for Simulink model 'pitot'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 25 11:45:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pitot_h_
#define RTW_HEADER_pitot_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef pitot_COMMON_INCLUDES_
#define pitot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#endif                                 /* pitot_COMMON_INCLUDES_ */

#include "pitot_types.h"
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
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Sum1;                         /* '<S2>/Sum1' */
  real_T V_anem;                       /* '<S1>/deltaP to Velocità' */
  uint16_T AnalogInput;                /* '<S1>/Analog Input' */
} B_pitot_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Analog Input' */
  real_T SFunctionBuilder_DSTATE;      /* '<S3>/S-Function Builder' */
  boolean_T objisempty;                /* '<S1>/Analog Input' */
} DW_pitot_T;

/* Parameters (default storage) */
struct P_pitot_T_ {
  real_T t_AP;                         /* Variable: t_AP
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  real_T Gain3_Gain;                   /* Expression: 6221/9305
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Constant4_Value;              /* Expression: -13897714/9305
                                        * Referenced by: '<S2>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pitot_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_pitot_T pitot_P;

/* Block signals (default storage) */
extern B_pitot_T pitot_B;

/* Block states (default storage) */
extern DW_pitot_T pitot_DW;

/* Model entry point functions */
extern void pitot_initialize(void);
extern void pitot_step(void);
extern void pitot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pitot_T *const pitot_M;
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
 * '<Root>' : 'pitot'
 * '<S1>'   : 'pitot/Velocità indicata'
 * '<S2>'   : 'pitot/Velocità indicata/Bit to deltaP'
 * '<S3>'   : 'pitot/Velocità indicata/Inizializzazioni'
 * '<S4>'   : 'pitot/Velocità indicata/deltaP to Velocità'
 */
#endif                                 /* RTW_HEADER_pitot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
