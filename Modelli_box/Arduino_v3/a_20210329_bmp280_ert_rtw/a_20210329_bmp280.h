/*
 * a_20210329_bmp280.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a_20210329_bmp280".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Mar 29 17:19:05 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210329_bmp280_h_
#define RTW_HEADER_a_20210329_bmp280_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef a_20210329_bmp280_COMMON_INCLUDES_
#define a_20210329_bmp280_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_I2C.h"
#endif                                 /* a_20210329_bmp280_COMMON_INCLUDES_ */

#include "a_20210329_bmp280_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

/* Block signals for system '<Root>/One_time_initialization' */
typedef struct {
  uint16_T ByteUnpack[8];              /* '<S2>/Byte Unpack' */
  uint16_T I2CRead3;                   /* '<S2>/I2C Read3' */
  uint16_T I2CRead;                    /* '<S2>/I2C Read' */
  int16_T I2CRead9;                    /* '<S2>/I2C Read9' */
  int16_T I2CRead8;                    /* '<S2>/I2C Read8' */
  int16_T I2CRead7;                    /* '<S2>/I2C Read7' */
  int16_T I2CRead6;                    /* '<S2>/I2C Read6' */
  int16_T I2CRead5;                    /* '<S2>/I2C Read5' */
  int16_T I2CRead4;                    /* '<S2>/I2C Read4' */
  int16_T I2CRead2;                    /* '<S2>/I2C Read2' */
  int16_T I2CRead11;                   /* '<S2>/I2C Read11' */
  int16_T I2CRead10;                   /* '<S2>/I2C Read10' */
  int16_T I2CRead1;                    /* '<S2>/I2C Read1' */
  uint8_T I2CRead12[16];               /* '<S2>/I2C Read12' */
} B_One_time_initialization_a_2_T;

/* Block states (default storage) for system '<Root>/One_time_initialization' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/I2C Read9' */
  codertarget_arduinobase_inter_T obj_n;/* '<S2>/I2C Read8' */
  codertarget_arduinobase_inter_T obj_g;/* '<S2>/I2C Read7' */
  codertarget_arduinobase_inter_T obj_ny;/* '<S2>/I2C Read6' */
  codertarget_arduinobase_inter_T obj_e;/* '<S2>/I2C Read5' */
  codertarget_arduinobase_inter_T obj_f;/* '<S2>/I2C Read4' */
  codertarget_arduinobase_inter_T obj_ng;/* '<S2>/I2C Read3' */
  codertarget_arduinobase_inter_T obj_l;/* '<S2>/I2C Read2' */
  codertarget_arduinobase_inter_T obj_a;/* '<S2>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_o;/* '<S2>/I2C Read11' */
  codertarget_arduinobase_inter_T obj_ej;/* '<S2>/I2C Read10' */
  codertarget_arduinobase_inter_T obj_lm;/* '<S2>/I2C Read1' */
  codertarget_arduinobase_inter_T obj_f1;/* '<S2>/I2C Read' */
  codertarget_arduinobase_int_i_T obj_b;/* '<S2>/I2C Write3' */
  codertarget_arduinobase_int_i_T obj_m;/* '<S2>/I2C Write2' */
  codertarget_arduinobase_int_i_T obj_i;/* '<S2>/I2C Write1' */
  int8_T One_time_initialization_SubsysR;/* '<Root>/One_time_initialization' */
  boolean_T objisempty;                /* '<S2>/I2C Write3' */
  boolean_T objisempty_o;              /* '<S2>/I2C Write2' */
  boolean_T objisempty_oh;             /* '<S2>/I2C Write1' */
  boolean_T objisempty_m;              /* '<S2>/I2C Read9' */
  boolean_T objisempty_l;              /* '<S2>/I2C Read8' */
  boolean_T objisempty_g;              /* '<S2>/I2C Read7' */
  boolean_T objisempty_a;              /* '<S2>/I2C Read6' */
  boolean_T objisempty_h;              /* '<S2>/I2C Read5' */
  boolean_T objisempty_n;              /* '<S2>/I2C Read4' */
  boolean_T objisempty_b;              /* '<S2>/I2C Read3' */
  boolean_T objisempty_bn;             /* '<S2>/I2C Read2' */
  boolean_T objisempty_k;              /* '<S2>/I2C Read12' */
  boolean_T objisempty_hr;             /* '<S2>/I2C Read11' */
  boolean_T objisempty_c;              /* '<S2>/I2C Read10' */
  boolean_T objisempty_kg;             /* '<S2>/I2C Read1' */
  boolean_T objisempty_p;              /* '<S2>/I2C Read' */
} DW_One_time_initialization_a__T;

/* Block signals (default storage) */
typedef struct {
  uint32_T SFunctionBuilder1;          /* '<S1>/S-Function Builder1' */
  real32_T SFunctionBuilder_o1;        /* '<S1>/S-Function Builder' */
  int32_T DataTypeConversion1;         /* '<S1>/Data Type  Conversion1' */
  int32_T DataTypeConversion;          /* '<S1>/Data Type  Conversion' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  B_One_time_initialization_a_2_T One_time_initialization;/* '<Root>/One_time_initialization' */
} B_a_20210329_bmp280_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/I2C Read12' */
  codertarget_arduinobase_inter_T obj_p;/* '<S1>/I2C Read1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_O;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Execu;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Exe_d;   /* synthesized block */

  int8_T Execution_loop_SubsysRanBC;   /* '<Root>/Execution_loop' */
  boolean_T objisempty;                /* '<S1>/I2C Read12' */
  boolean_T objisempty_b;              /* '<S1>/I2C Read1' */
  DW_One_time_initialization_a__T One_time_initialization;/* '<Root>/One_time_initialization' */
} DW_a_20210329_bmp280_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T pwm_max_min[8];             /* '<Root>/pwm_max_min ' */
} ExtY_a_20210329_bmp280_T;

/* Parameters for system: '<Root>/One_time_initialization' */
struct P_One_time_initialization_a_2_T_ {
  uint16_T BitwiseOperator1_BitMask; /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S2>/Bitwise Operator1'
                                      */
  real_T I2CRead_SampleTime;           /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read'
                                        */
  real_T I2CRead1_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read1'
                                        */
  real_T I2CRead10_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read10'
                                        */
  real_T I2CRead11_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read11'
                                        */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read12'
                                        */
  real_T I2CRead2_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read2'
                                        */
  real_T I2CRead3_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read3'
                                        */
  real_T I2CRead4_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read4'
                                        */
  real_T I2CRead5_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read5'
                                        */
  real_T I2CRead6_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read6'
                                        */
  real_T I2CRead7_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read7'
                                        */
  real_T I2CRead8_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read8'
                                        */
  real_T I2CRead9_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S2>/I2C Read9'
                                        */
  int16_T dig_T2_Y0;                   /* Computed Parameter: dig_T2_Y0
                                        * Referenced by: '<S2>/dig_T2'
                                        */
  int16_T dig_T3_Y0;                   /* Computed Parameter: dig_T3_Y0
                                        * Referenced by: '<S2>/dig_T3'
                                        */
  int16_T dig_p2_Y0;                   /* Computed Parameter: dig_p2_Y0
                                        * Referenced by: '<S2>/dig_p2'
                                        */
  int16_T dig_p3_Y0;                   /* Computed Parameter: dig_p3_Y0
                                        * Referenced by: '<S2>/dig_p3'
                                        */
  int16_T dig_p4_Y0;                   /* Computed Parameter: dig_p4_Y0
                                        * Referenced by: '<S2>/dig_p4'
                                        */
  int16_T dig_p5_Y0;                   /* Computed Parameter: dig_p5_Y0
                                        * Referenced by: '<S2>/dig_p5'
                                        */
  int16_T dig_p6_Y0;                   /* Computed Parameter: dig_p6_Y0
                                        * Referenced by: '<S2>/dig_p6'
                                        */
  int16_T dig_p7_Y0;                   /* Computed Parameter: dig_p7_Y0
                                        * Referenced by: '<S2>/dig_p7'
                                        */
  int16_T dig_p8_Y0;                   /* Computed Parameter: dig_p8_Y0
                                        * Referenced by: '<S2>/dig_p8'
                                        */
  int16_T dig_p9_Y0;                   /* Computed Parameter: dig_p9_Y0
                                        * Referenced by: '<S2>/dig_p9'
                                        */
  uint16_T dig_T1_Y0;                  /* Computed Parameter: dig_T1_Y0
                                        * Referenced by: '<S2>/dig_T1'
                                        */
  uint16_T dig_p1_Y0;                  /* Computed Parameter: dig_p1_Y0
                                        * Referenced by: '<S2>/dig_p1'
                                        */
  uint16_T pwm_max_min_Y0;             /* Computed Parameter: pwm_max_min_Y0
                                        * Referenced by: '<S2>/pwm_max_min'
                                        */
  uint16_T registromemoria2_Value; /* Computed Parameter: registromemoria2_Value
                                    * Referenced by: '<S2>/registro memoria2 '
                                    */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S2>/Constant1'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S2>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_a_20210329_bmp280_T_ {
  real_T I2CRead1_SampleTime;          /* Expression: 0.02
                                        * Referenced by: '<S1>/I2C Read1'
                                        */
  real_T I2CRead12_SampleTime;         /* Expression: 0.02
                                        * Referenced by: '<S1>/I2C Read12'
                                        */
  real_T Constant1_Value;              /* Expression: 16
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 8
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 4
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 16
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 8
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T T_Y0;                       /* Computed Parameter: T_Y0
                                        * Referenced by: '<S1>/T'
                                        */
  uint32_T p_Y0;                       /* Computed Parameter: p_Y0
                                        * Referenced by: '<S1>/p'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S1>/Constant7'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S1>/Constant10'
                                        */
  uint32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S1>/Constant11'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S1>/Constant8'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S1>/Constant9'
                                        */
  P_One_time_initialization_a_2_T One_time_initialization;/* '<Root>/One_time_initialization' */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210329_bmp280_T {
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
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_a_20210329_bmp280_T a_20210329_bmp280_P;

/* Block signals (default storage) */
extern B_a_20210329_bmp280_T a_20210329_bmp280_B;

/* Block states (default storage) */
extern DW_a_20210329_bmp280_T a_20210329_bmp280_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_a_20210329_bmp280_T a_20210329_bmp280_Y;

/* Model entry point functions */
extern void a_20210329_bmp280_initialize(void);
extern void a_20210329_bmp280_step(void);
extern void a_20210329_bmp280_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210329_bmp280_T *const a_20210329_bmp280_M;
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
 * '<Root>' : 'a_20210329_bmp280'
 * '<S1>'   : 'a_20210329_bmp280/Execution_loop'
 * '<S2>'   : 'a_20210329_bmp280/One_time_initialization'
 */
#endif                                 /* RTW_HEADER_a_20210329_bmp280_h_ */
