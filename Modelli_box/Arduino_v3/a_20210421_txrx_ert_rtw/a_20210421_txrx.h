/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210421_txrx.h
 *
 * Code generated for Simulink model 'a_20210421_txrx'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 17:23:08 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210421_txrx_h_
#define RTW_HEADER_a_20210421_txrx_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef a_20210421_txrx_COMMON_INCLUDES_
#define a_20210421_txrx_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* a_20210421_txrx_COMMON_INCLUDES_ */

#include "a_20210421_txrx_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T buffer[300];                 /* '<S1>/MATLAB Function2' */
  uint8_T messaggio_2[100];            /* '<S1>/MATLAB Function4' */
  uint8_T messaggio[100];              /* '<S1>/MATLAB Function4' */
  boolean_T x[100];
  real_T poss_254[3];
  uint16_T WP_info_in[6];
  real_T num_254;
  real_T PatohPa1;                     /* '<S2>/Pa to hPa1' */
  real_T Sum2;                         /* '<S23>/Sum2' */
  real_T Sum1;                         /* '<S23>/Sum1' */
  uint32_T SFunction_o2;               /* '<S1>/S-Function' */
  uint32_T DataTypeConversion3;        /* '<S11>/Data Type Conversion3' */
  uint32_T DataTypeConversion;         /* '<S9>/Data Type Conversion' */
  real32_T SFunction_o8;               /* '<S1>/S-Function' */
  real32_T SFunction_o10[7];           /* '<S1>/S-Function' */
  real32_T SFunction_o13;              /* '<S1>/S-Function' */
  real32_T SFunction_o17;              /* '<S1>/S-Function' */
  real32_T DataTypeConversion1[6];     /* '<S10>/Data Type Conversion1' */
  real32_T DataTypeConversion3_b[4];   /* '<S14>/Data Type Conversion3' */
  real32_T DataTypeConversion3_d;      /* '<S2>/Data Type Conversion3' */
  real32_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  real32_T DataTypeConversion_m;       /* '<S2>/Data Type Conversion' */
  real32_T DataTypeConversion1_f;      /* '<S2>/Data Type Conversion1' */
  real32_T WP_param[7];                /* '<S15>/MATLAB Function' */
  real32_T Val_out_MAV[16];            /* '<S1>/MATLAB Function1' */
  int32_T SFunctionBuilder_o2;         /* '<S1>/S-Function Builder' */
  int32_T Add;                         /* '<S1>/Add' */
  int32_T DataTypeConversion_c[4];     /* '<S8>/Data Type Conversion' */
  uint16_T Memory[8];                  /* '<S1>/Memory' */
  uint16_T SFunction_o7[2];            /* '<S1>/S-Function' */
  uint16_T SFunction_o9[6];            /* '<S1>/S-Function' */
  uint16_T SFunction_o11[8];           /* '<S1>/S-Function' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S2>/SystemStatus' */
  uint16_T DataTypeConversion2;        /* '<S8>/Data Type Conversion2' */
  uint16_T DataTypeConversion5;        /* '<S14>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S12>/Data Type Conversion1' */
  uint16_T Memory_h;                   /* '<S2>/Memory' */
  uint16_T SFunction_o3;               /* '<S2>/S-Function' */
  uint16_T SFunction_o4;               /* '<S2>/S-Function' */
  uint16_T WP_info[6];                 /* '<S15>/MATLAB Function' */
  uint16_T new_mex;                    /* '<S1>/MATLAB Function3' */
  uint16_T GC_info[3];                 /* '<S1>/MATLAB Function1' */
  int16_T Gain1;                       /* '<S13>/Gain1' */
  int16_T DataTypeConversion_d[9];     /* '<S10>/Data Type Conversion' */
  int16_T DataTypeConversion1_m[3];    /* '<S8>/Data Type Conversion1' */
  int16_T DataTypeConversion4_p;       /* '<S14>/Data Type Conversion4' */
  int16_T DataTypeConversion2_b;       /* '<S2>/Data Type Conversion2' */
  uint8_T SFunctionBuilder_o1[100];    /* '<S1>/S-Function Builder' */
  uint8_T Memory1[2];                  /* '<S1>/Memory1' */
  uint8_T Memory_o[4];                 /* '<Root>/Memory' */
  uint8_T Memory3;                     /* '<S1>/Memory3' */
  uint8_T SFunction_o1[4];             /* '<S1>/S-Function' */
  uint8_T SFunction_o3_d;              /* '<S1>/S-Function' */
  uint8_T SFunction_o4_e[2];           /* '<S1>/S-Function' */
  uint8_T SFunction_o5[3];             /* '<S1>/S-Function' */
  uint8_T SFunction_o6;                /* '<S1>/S-Function' */
  uint8_T SFunction_o12;               /* '<S1>/S-Function' */
  uint8_T SFunction_o14;               /* '<S1>/S-Function' */
  uint8_T SFunction_o15;               /* '<S1>/S-Function' */
  uint8_T SFunction_o16;               /* '<S1>/S-Function' */
  uint8_T TmpSignalConversionAtSFunctio_m[4];/* '<S2>/Heartbeat' */
  uint8_T SFunction_o1_m;              /* '<S2>/S-Function' */
  uint8_T SFunction_o2_a[264];         /* '<S2>/S-Function' */
  uint8_T iflogic;                     /* '<S11>/iflogic_function' */
  uint8_T mess_out[100];               /* '<S1>/MATLAB Function2' */
  int8_T B_Remaining;                  /* '<S13>/Data Type Conversion3' */
} B_a_20210421_txrx_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S17>/Serial Transmit' */
  real_T SFunctionBuilder_DSTATE;      /* '<S1>/S-Function Builder' */
  volatile real_T RateTransition_Buffer0;/* '<S21>/Rate Transition' */
  real_T Memory1_PreviousInput;        /* '<S21>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S21>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S21>/Memory2' */
  real_T mess_len;                     /* '<S1>/MATLAB Function4' */
  real32_T riferimenti[16];            /* '<S1>/MATLAB Function1' */
  real32_T WP_dbP[42];                 /* '<S1>/MATLAB Function1' */
  uint16_T Memory_PreviousInput_o[8];  /* '<S1>/Memory' */
  uint16_T Memory_PreviousInput_p;     /* '<S2>/Memory' */
  uint16_T counter;                    /* '<S1>/MATLAB Function3' */
  uint16_T WP_dbI[36];                 /* '<S1>/MATLAB Function1' */
  uint8_T Memory4_PreviousInput[300];  /* '<S1>/Memory4' */
  uint8_T Memory5_PreviousInput[100];  /* '<S1>/Memory5' */
  uint8_T Memory1_PreviousInput_e[2];  /* '<S1>/Memory1' */
  uint8_T Memory_PreviousInput_oi[4];  /* '<Root>/Memory' */
  uint8_T Memory3_PreviousInput;       /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput_k[9];  /* '<S1>/Memory2' */
  uint8_T is_active_c9_a_20210421_txrx;/* '<S7>/Chart' */
  uint8_T i;                           /* '<S7>/Chart' */
  uint8_T message[100];                /* '<S1>/MATLAB Function4' */
  uint8_T counter_e;                   /* '<S1>/MATLAB Function4' */
  boolean_T Interr_parz;               /* '<S1>/MATLAB Function4' */
  boolean_T WP_dbP_not_empty;          /* '<S1>/MATLAB Function1' */
  boolean_T WP_dbP_AL_not_empty;       /* '<S1>/MATLAB Function1' */
} DW_a_20210421_txrx_T;

/* Parameters (default storage) */
struct P_a_20210421_txrx_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S17>/Serial Transmit'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S21>/Rate Transition'
                                          */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S21>/Constant3'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S21>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 4
                                        * Referenced by: '<S21>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.02
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S21>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 3
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1000
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Constant1_Value_e[2];         /* Expression: [0 0]
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant3_Value_d;            /* Expression: 23
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Constant2_Value_c;            /* Expression: 10
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_h[2];         /* Expression: [0 0]
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T ACCsimulated_Value[3];        /* Expression: [0.102 0 0]
                                        * Referenced by: '<S10>/ACC simulated'
                                        */
  real_T psimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/p simulated'
                                        */
  real_T qsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/q simulated'
                                        */
  real_T rsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/r simulated'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 10^3
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T phisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S10>/phi simulated'
                                        */
  real_T thetasimulated_Value;         /* Expression: 0
                                        * Referenced by: '<S10>/theta simulated'
                                        */
  real_T psisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S10>/psi simulated'
                                        */
  real_T LatSimulated_Value;           /* Expression: 41*pi/180
                                        * Referenced by: '<S8>/Lat Simulated'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T LongSimulated_Value;          /* Expression: 12*pi/180
                                        * Referenced by: '<S8>/Long Simulated'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T AltSimulated_Value;           /* Expression: 100
                                        * Referenced by: '<S8>/Alt Simulated'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S8>/alt_r'
                                        */
  real_T Gain_Gain_h[4];               /* Expression: [10^7;10^7;1000 ;1000]
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T vSimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S8>/v Simulated'
                                        */
  real_T vely_Value;                   /* Expression: 0
                                        * Referenced by: '<S8>/vel y'
                                        */
  real_T RCSimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S8>/RC Simulated'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 20
                                        * Referenced by: '<S8>/Heading simulated'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 100
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S14>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S14>/v simulated'
                                        */
  real_T Altsimulated_Value;           /* Expression: 100
                                        * Referenced by: '<S14>/Alt simulated'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S14>/RC simulated'
                                        */
  real_T Headingsimulated_Value_g;     /* Expression: 50
                                        * Referenced by: '<S14>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S14>/Rpm simulated'
                                        */
  real_T Constant_Value_l;             /* Expression: 4
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S12>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 100
                                        * Referenced by: '<S23>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S12>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_mr;                 /* Expression: 180/pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Constant2_Value_g;            /* Expression: 90
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S12>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_hs;                 /* Expression: 180/pi
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S12>/Timone Simulated'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Constant1_Value_f[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 10000
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.01
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1013
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: 15
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant6_Value;              /* Expression: 101325
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S2>/Pa to hPa1'
                                        */
  real_T Constant3_Value_f;            /* Expression: 298
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant4_Value_c;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant4'
                                        */
  real_T Constant5_Value_d;            /* Expression: 1
                                        * Referenced by: '<S21>/Constant5'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: -1
                                        * Referenced by: '<S21>/Memory2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 9
                                        * Referenced by: '<S21>/Switch1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S13>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_i;                /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S13>/Gain1'
                                        */
  uint16_T Memory_InitialCondition_b;
                                /* Computed Parameter: Memory_InitialCondition_b
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S13>/load uint16'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S13>/ '
                                        */
  uint16_T Memory_InitialCondition_g;
                                /* Computed Parameter: Memory_InitialCondition_g
                                 * Referenced by: '<S2>/Memory'
                                 */
  uint8_T Memory4_InitialCondition[300];/* Expression: uint8(zeros(3,100))
                                         * Referenced by: '<S1>/Memory4'
                                         */
  uint8_T Constant1_Value_fl;          /* Computed Parameter: Constant1_Value_fl
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T SIUAVuint8_Value;            /* Computed Parameter: SIUAVuint8_Value
                                        * Referenced by: '<Root>/SI UAV uint8'
                                        */
  uint8_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  uint8_T Memory1_InitialCondition_g;
                               /* Computed Parameter: Memory1_InitialCondition_g
                                * Referenced by: '<S1>/Memory1'
                                */
  uint8_T Memory_InitialCondition_i;
                                /* Computed Parameter: Memory_InitialCondition_i
                                 * Referenced by: '<Root>/Memory'
                                 */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory2_InitialCondition_c[9];
                               /* Computed Parameter: Memory2_InitialCondition_c
                                * Referenced by: '<S1>/Memory2'
                                */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S9>/Type fixed_wing Autopilot generic'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210421_txrx_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_a_20210421_txrx_T a_20210421_txrx_P;

/* Block signals (default storage) */
extern B_a_20210421_txrx_T a_20210421_txrx_B;

/* Block states (default storage) */
extern DW_a_20210421_txrx_T a_20210421_txrx_DW;

/* External data declarations for dependent source files */
extern const uint16_T a_20210421_txrx_U16GND;/* uint16_T ground */

/* External function called from main */
extern void a_20210421_txrx_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void a_20210421_txrx_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void a_20210421_txrx_initialize(void);
extern void a_20210421_txrx_step0(void);
extern void a_20210421_txrx_step1(void);
extern void a_20210421_txrx_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210421_txrx_T *const a_20210421_txrx_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Tversion' : Unused code path elimination
 * Block '<S1>/Data Tversion1' : Unused code path elimination
 * Block '<S1>/Data Tversion2' : Unused code path elimination
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'a_20210421_txrx'
 * '<S1>'   : 'a_20210421_txrx/AIR RX'
 * '<S2>'   : 'a_20210421_txrx/AIR TX'
 * '<S3>'   : 'a_20210421_txrx/AIR RX/MATLAB Function1'
 * '<S4>'   : 'a_20210421_txrx/AIR RX/MATLAB Function2'
 * '<S5>'   : 'a_20210421_txrx/AIR RX/MATLAB Function3'
 * '<S6>'   : 'a_20210421_txrx/AIR RX/MATLAB Function4'
 * '<S7>'   : 'a_20210421_txrx/AIR TX/Enable '
 * '<S8>'   : 'a_20210421_txrx/AIR TX/GPS'
 * '<S9>'   : 'a_20210421_txrx/AIR TX/Heartbeat'
 * '<S10>'  : 'a_20210421_txrx/AIR TX/IMU & Attidude'
 * '<S11>'  : 'a_20210421_txrx/AIR TX/If_subsystem'
 * '<S12>'  : 'a_20210421_txrx/AIR TX/Servo'
 * '<S13>'  : 'a_20210421_txrx/AIR TX/SystemStatus'
 * '<S14>'  : 'a_20210421_txrx/AIR TX/VFR'
 * '<S15>'  : 'a_20210421_txrx/AIR TX/Waypoints'
 * '<S16>'  : 'a_20210421_txrx/AIR TX/Enable /Chart'
 * '<S17>'  : 'a_20210421_txrx/AIR TX/Enable /Chart/sendbyte'
 * '<S18>'  : 'a_20210421_txrx/AIR TX/GPS/Radians to Degrees'
 * '<S19>'  : 'a_20210421_txrx/AIR TX/GPS/Radians to Degrees1'
 * '<S20>'  : 'a_20210421_txrx/AIR TX/Heartbeat/Alarm set'
 * '<S21>'  : 'a_20210421_txrx/AIR TX/If_subsystem/Subsystem'
 * '<S22>'  : 'a_20210421_txrx/AIR TX/If_subsystem/iflogic_function'
 * '<S23>'  : 'a_20210421_txrx/AIR TX/Servo/Conversione'
 * '<S24>'  : 'a_20210421_txrx/AIR TX/Servo/Conversione/Radians to Degrees1'
 * '<S25>'  : 'a_20210421_txrx/AIR TX/Servo/Conversione/Radians to Degrees2'
 * '<S26>'  : 'a_20210421_txrx/AIR TX/Servo/Conversione/Radians to Degrees3'
 * '<S27>'  : 'a_20210421_txrx/AIR TX/Waypoints/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_a_20210421_txrx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
