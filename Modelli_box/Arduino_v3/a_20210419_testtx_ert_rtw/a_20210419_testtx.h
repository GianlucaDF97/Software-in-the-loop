/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210419_testtx.h
 *
 * Code generated for Simulink model 'a_20210419_testtx'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May  4 16:38:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a_20210419_testtx_h_
#define RTW_HEADER_a_20210419_testtx_h_
#include <math.h>
#include <stddef.h>
#ifndef a_20210419_testtx_COMMON_INCLUDES_
#define a_20210419_testtx_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* a_20210419_testtx_COMMON_INCLUDES_ */

#include "a_20210419_testtx_types.h"
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

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T DataTypeConversion1;        /* '<S5>/Data Type Conversion1' */
  uint32_T DataTypeConversion;         /* '<S3>/Data Type Conversion' */
  real32_T DataTypeConversion_f[16];   /* '<S10>/Data Type Conversion' */
  real32_T DataTypeConversion2[7];     /* '<S10>/Data Type Conversion2' */
  real32_T DataTypeConversion1_p[6];   /* '<S4>/Data Type Conversion1' */
  real32_T DataTypeConversion3[4];     /* '<S6>/Data Type Conversion3' */
  real32_T DataTypeConversion3_n;      /* '<S1>/Data Type Conversion3' */
  real32_T DataTypeConversion_a;       /* '<S1>/Data Type Conversion' */
  real32_T DataTypeConversion1_b;      /* '<S1>/Data Type Conversion1' */
  int32_T DataTypeConversion_n[4];     /* '<S8>/Data Type Conversion' */
  uint16_T DataTypeConversion5[3];     /* '<S1>/Data Type Conversion5' */
  uint16_T DataTypeConversion1_f[6];   /* '<S10>/Data Type Conversion1' */
  uint16_T TmpSignalConversionAtSFunctionI[8];/* '<S1>/SystemStatus1' */
  uint16_T DataTypeConversion2_d;      /* '<S8>/Data Type Conversion2' */
  uint16_T DataTypeConversion5_o;      /* '<S6>/Data Type Conversion5' */
  uint16_T Heading[9];                 /* '<S7>/Data Type Conversion1' */
  uint16_T Memory;                     /* '<S1>/Memory' */
  uint16_T SFunction_o3;               /* '<S1>/S-Function' */
  uint16_T SFunction_o4;               /* '<S1>/S-Function' */
  int16_T Gain1;                       /* '<S9>/Gain1' */
  int16_T DataTypeConversion_k[9];     /* '<S4>/Data Type Conversion' */
  int16_T DataTypeConversion1_g[3];    /* '<S8>/Data Type Conversion1' */
  int16_T DataTypeConversion4_j;       /* '<S6>/Data Type Conversion4' */
  int16_T DataTypeConversion2_i;       /* '<S1>/Data Type Conversion2' */
  uint8_T DataTypeConversion_ap;       /* '<S5>/Data Type Conversion' */
  uint8_T TmpSignalConversionAtSFunctio_m[4];/* '<S1>/Heartbeat1' */
  uint8_T SFunction_o1;                /* '<S1>/S-Function' */
  uint8_T SFunction_o2[264];           /* '<S1>/S-Function' */
  int8_T B_Remaining;                  /* '<S9>/Data Type Conversion3' */
} B_a_20210419_testtx_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S12>/Serial Transmit' */
  real_T Memory_PreviousInput;         /* '<S5>/Memory' */
  int32_T clockTickCounter;            /* '<S5>/Discrete Pulse Generator' */
  uint16_T Memory_PreviousInput_l;     /* '<S1>/Memory' */
  uint8_T is_active_c9_a_20210419_testtx;/* '<S2>/Chart' */
  uint8_T i;                           /* '<S2>/Chart' */
} DW_a_20210419_testtx_T;

/* Parameters (default storage) */
struct P_a_20210419_testtx_T_ {
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S12>/Serial Transmit'
                                        */
  real_T DiscretePulseGenerator_Amp;   /* Expression: 1
                                        * Referenced by: '<S5>/Discrete Pulse Generator'
                                        */
  real_T DiscretePulseGenerator_Period;/* Expression: 4
                                        * Referenced by: '<S5>/Discrete Pulse Generator'
                                        */
  real_T DiscretePulseGenerator_Duty;  /* Expression: 1
                                        * Referenced by: '<S5>/Discrete Pulse Generator'
                                        */
  real_T DiscretePulseGenerator_PhaseDel;/* Expression: 0
                                          * Referenced by: '<S5>/Discrete Pulse Generator'
                                          */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.02
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -0.02
                                        * Referenced by: '<S5>/Memory'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Constant1_Value_i[3];         /* Expression: [0 0 100]
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant_Value_d[16];
                       /* Expression: [0 0 0 0 0 0 0 0 20 100 0 101325 15 0 0 0]
                        * Referenced by: '<S10>/Constant'
                        */
  real_T Constant2_Value[6];           /* Expression: [0 0 0 0 0 0 ]
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant3_Value[7];           /* Expression: [ 0 0 0 0 0 0 0]
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: [0 0]
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S9>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S9>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S9>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S9>/Sine Wave'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Constant3_Value_f;            /* Expression: 10
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T Constant_Value_dy;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value_h[2];         /* Expression: [0 0]
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value_l[2];         /* Expression: [0 0]'
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T ACCsimulated_Value[3];        /* Expression: [0.102 0 0]
                                        * Referenced by: '<S4>/ACC simulated'
                                        */
  real_T psimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S4>/p simulated'
                                        */
  real_T qsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S4>/q simulated'
                                        */
  real_T rsimulated_Value;             /* Expression: 0
                                        * Referenced by: '<S4>/r simulated'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 10^3
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T phisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S4>/phi simulated'
                                        */
  real_T thetasimulated_Value;         /* Expression: 0
                                        * Referenced by: '<S4>/theta simulated'
                                        */
  real_T psisimulated_Value;           /* Expression: 0
                                        * Referenced by: '<S4>/psi simulated'
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
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T AltSimulated_Value;           /* Expression: 100
                                        * Referenced by: '<S8>/Alt Simulated'
                                        */
  real_T alt_r_Value;                  /* Expression: 0
                                        * Referenced by: '<S8>/alt_r'
                                        */
  real_T Gain_Gain_n[4];               /* Expression: [10^7;10^7;1000 ;1000]
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
  real_T Gain1_Gain_p;                 /* Expression: 100
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Headingsimulated_Value;       /* Expression: 50
                                        * Referenced by: '<S8>/Heading simulated'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 100
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T TASsimulated_Value;           /* Expression: 20
                                        * Referenced by: '<S6>/TAS simulated'
                                        */
  real_T vsimulated_Value;             /* Expression: 20
                                        * Referenced by: '<S6>/v simulated'
                                        */
  real_T Altsimulated_Value;           /* Expression: 100
                                        * Referenced by: '<S6>/Alt simulated'
                                        */
  real_T RCsimulated_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/RC simulated'
                                        */
  real_T Headingsimulated_Value_j;     /* Expression: 50
                                        * Referenced by: '<S6>/ Heading simulated'
                                        */
  real_T Rpmsimulated_Value;           /* Expression: 1000
                                        * Referenced by: '<S6>/Rpm simulated'
                                        */
  real_T Constant_Value_k;             /* Expression: 4
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T ManettaSimulated_Value;       /* Expression: 0.3
                                        * Referenced by: '<S7>/Manetta Simulated'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 100
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T EquilibratoreSimulated_Value; /* Expression: 0.12
                                        * Referenced by: '<S7>/Equilibratore Simulated'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant2_Value_f;            /* Expression: 90
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T AlettoniSimulated_Value;      /* Expression: 0
                                        * Referenced by: '<S7>/Alettoni Simulated'
                                        */
  real_T Gain_Gain_lr;                 /* Expression: 180/pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T TimoneSimulated_Value;        /* Expression: 0
                                        * Referenced by: '<S7>/Timone Simulated'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant1_Value_n[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 10000
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 0.01
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 4000
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1013
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 101325
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T PatohPa_Gain;                 /* Expression: 0.01
                                        * Referenced by: '<S1>/Pa to hPa'
                                        */
  real_T Constant3_Value_j;            /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T PatohPa1_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S1>/Pa to hPa1'
                                        */
  real_T Constant11_Value;             /* Expression: 298
                                        * Referenced by: '<S1>/Constant11'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant10'
                                        */
  real32_T Constant2_Value_j;          /* Computed Parameter: Constant2_Value_j
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint32_T onboard_control_sensor_presentu[3];
                          /* Computed Parameter: onboard_control_sensor_presentu
                           * Referenced by: '<S9>/onboard_control_sensor_present uint32'
                           */
  int16_T Gain1_Gain_i;                /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S9>/Gain1'
                                        */
  uint16_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S9>/Gain'
                                        */
  uint16_T loaduint16_Value;           /* Computed Parameter: loaduint16_Value
                                        * Referenced by: '<S9>/load uint16'
                                        */
  uint16_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S9>/Constant2'
                                        */
  uint16_T Constant_Value_c[3];        /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S9>/Constant'
                                        */
  uint16_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S9>/ '
                                        */
  uint16_T Memory_InitialCondition_j;
                                /* Computed Parameter: Memory_InitialCondition_j
                                 * Referenced by: '<S1>/Memory'
                                 */
  uint8_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T Typefixed_wingAutopilotgeneric_[2];
                          /* Computed Parameter: Typefixed_wingAutopilotgeneric_
                           * Referenced by: '<S3>/Type fixed_wing Autopilot generic'
                           */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S1>/Constant4'
                                        */
  uint8_T Constant5_Value;             /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S1>/Constant5'
                                        */
  uint8_T Constant7_Value[3];          /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S1>/Constant7'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a_20210419_testtx_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_a_20210419_testtx_T a_20210419_testtx_P;

/* Block signals (default storage) */
extern B_a_20210419_testtx_T a_20210419_testtx_B;

/* Block states (default storage) */
extern DW_a_20210419_testtx_T a_20210419_testtx_DW;

/* External data declarations for dependent source files */
extern const uint16_T a_20210419_testtx_U16GND;/* uint16_T ground */

/* Model entry point functions */
extern void a_20210419_testtx_initialize(void);
extern void a_20210419_testtx_step(void);
extern void a_20210419_testtx_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a_20210419_testtx_T *const a_20210419_testtx_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion2' : Unused code path elimination
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'a_20210419_testtx'
 * '<S1>'   : 'a_20210419_testtx/AIR TX'
 * '<S2>'   : 'a_20210419_testtx/AIR TX/Enable '
 * '<S3>'   : 'a_20210419_testtx/AIR TX/Heartbeat1'
 * '<S4>'   : 'a_20210419_testtx/AIR TX/IMU & Attidude1'
 * '<S5>'   : 'a_20210419_testtx/AIR TX/If_subsystem'
 * '<S6>'   : 'a_20210419_testtx/AIR TX/Subsystem'
 * '<S7>'   : 'a_20210419_testtx/AIR TX/Subsystem1'
 * '<S8>'   : 'a_20210419_testtx/AIR TX/Subsystem2'
 * '<S9>'   : 'a_20210419_testtx/AIR TX/SystemStatus1'
 * '<S10>'  : 'a_20210419_testtx/AIR TX/Waypoints1'
 * '<S11>'  : 'a_20210419_testtx/AIR TX/Enable /Chart'
 * '<S12>'  : 'a_20210419_testtx/AIR TX/Enable /Chart/sendbyte'
 * '<S13>'  : 'a_20210419_testtx/AIR TX/Heartbeat1/Alarm set'
 * '<S14>'  : 'a_20210419_testtx/AIR TX/Subsystem1/Conversione'
 * '<S15>'  : 'a_20210419_testtx/AIR TX/Subsystem1/Conversione/Radians to Degrees1'
 * '<S16>'  : 'a_20210419_testtx/AIR TX/Subsystem1/Conversione/Radians to Degrees2'
 * '<S17>'  : 'a_20210419_testtx/AIR TX/Subsystem1/Conversione/Radians to Degrees3'
 * '<S18>'  : 'a_20210419_testtx/AIR TX/Subsystem2/Radians to Degrees'
 * '<S19>'  : 'a_20210419_testtx/AIR TX/Subsystem2/Radians to Degrees1'
 */
#endif                                 /* RTW_HEADER_a_20210419_testtx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
